#include "port_memory.h"

#include <cstdlib>
#include <cstdio>
extern "C" void PortDebug_CrashLog(const char* fmt, ...);
#include <cstring>
#include <unordered_map>
#include <mutex>

namespace Port::Memory {

namespace {

struct AllocInfo {
    std::size_t size;
    const char* debugTag;
};

// Jednoducha evidence zivych alokaci. Mutex je tu kvuli budouci moznosti
// vicevlaknoveho pristupu (napr. asynchronni nacitani zdroju) - dnes to
// puvodni DOS kod resit nemusel, protoze byl vzdy jednovlaknovy.
std::mutex g_mutex;
std::unordered_map<void*, AllocInfo> g_liveAllocations;
std::size_t g_liveBytes = 0;
bool g_trackingEnabled = false;

// Emulovany rozpocet pameti - viz komentar v port_memory.h (vlna 11).
// 32 MiB odpovida referencnimu dosbox-x behu (memsize=32), na kterem byly
// zmerene hodnoty originalu (DPMI+memavl ~26.3 MB volnych po startu DOSu).
constexpr std::size_t kDefaultBudgetBytes = 32u * 1024u * 1024u;
std::size_t g_budgetBytes = kDefaultBudgetBytes;

// Vejde se dalsich "size" bajtu do rozpoctu? Volat pod zamkem g_mutex.
// Enforcement jen pri zapnute evidenci (bez ni nezname g_liveBytes) -
// Port::Memory::Init() se vola jako prvni vec v main(), takze herni beh
// je pokryty vzdy; bez Init() (izolovane testy) se chova jako driv.
bool FitsBudgetLocked(std::size_t size)
{
    if (!g_trackingEnabled)
        return true;
    return size <= g_budgetBytes && g_liveBytes <= g_budgetBytes - size;
}

} // namespace

// PORT (vlna 99): STRAZNI BAJTY kolem hernich alokaci.
// Herni pamet jde pres std::malloc, tedy pres SKUTECNOU haldu procesu - kdyz
// dekompilovany kod prestreli buffer, poskodi metadata haldy a Windows to
// nahlasi az pri nejakem pozdejsim free() UPLNE JINDE (typicky
// ntdll!RtlpFreeHeap na cizim vlakne - presne tak to vypadalo u FLEETS).
// S REORION2_MEM_GUARD=1 se kolem kazdeho bloku alokuje 32 B vzoru 0xAB a
// pri uvolneni (nebo na vyzadani) se rekne, KTERY blok prestrelil - i s tagem.
static std::size_t g_guard = 0;   // 0 = vypnuto
static const unsigned char kGuardByte = 0xAB;

static void FillGuards(unsigned char* raw, std::size_t size)
{
    if (!g_guard) return;
    std::memset(raw, kGuardByte, g_guard);
    std::memset(raw + g_guard + size, kGuardByte, g_guard);
}

// 0 = v poradku, -1 = poskozena predni straz, +1 = zadni
static int TestGuards(const unsigned char* raw, std::size_t size)
{
    if (!g_guard) return 0;
    for (std::size_t i = 0; i < g_guard; ++i)
        if (raw[i] != kGuardByte) return -1;
    for (std::size_t i = 0; i < g_guard; ++i)
        if (raw[g_guard + size + i] != kGuardByte) return 1;
    return 0;
}

void Init()
{
    std::lock_guard<std::mutex> lock(g_mutex);
    g_liveAllocations.clear();
    g_liveBytes = 0;
    g_trackingEnabled = true;

    // Volitelny prepis rozpoctu (v bajtech) - pro ladeni shody s DOSBox
    // referenci nebo simulaci mensiho stroje.
    if (std::getenv("REORION2_MEM_GUARD"))
        g_guard = 32;   // vlna 99: strazni bajty kolem kazde alokace

    if (const char* env = std::getenv("REORION2_MEM_BUDGET")) {
        const unsigned long long v = std::strtoull(env, nullptr, 0);
        if (v > 0)
            g_budgetBytes = (std::size_t)v;
    }
}

void Shutdown()
{
    std::lock_guard<std::mutex> lock(g_mutex);
    if (g_trackingEnabled && !g_liveAllocations.empty()) {
        std::fprintf(stderr, "Port::Memory::Shutdown - nalezeno %zu neuvolnenych bloku (%zu bajtu):\n",
                      g_liveAllocations.size(), g_liveBytes);
        for (const auto& [ptr, info] : g_liveAllocations) {
            std::fprintf(stderr, "  %p  %zu bajtu  tag=%s\n", ptr, info.size,
                          info.debugTag ? info.debugTag : "(bez popisku)");
        }
        // OVERENO proti originalu (vlna 14): pri ukonceni hry je tento vypis
        // OCEKAVANY - puvodni DOS kod trvale zive bloky (resource buffer
        // 0x64000, VGA stranky, fonty...) NIKDY neuvolnoval a spolehal na
        // zanik procesu (v celem dumpu neexistuje jedine nfree na tyto
        // globaly, exit retez sub_113DBD jen resetuje mys/video/AIL).
        // Vyznam ma tento report pro bloky, ktere by rostly BEHEM hrani.
        std::fprintf(stderr, "  (pozn.: trvale bloky hry se pri exitu neuvolnuji ani v originale - viz PROGRESS.md vlna 14)\n");
    }
    g_trackingEnabled = false;
}

void* Alloc(std::size_t size, const char* debugTag)
{
    {
        // Rozpocet kontrolovat PRED malloc - emuluje DOS "dosla pamet",
        // vcetne pripadu, kdy dekompilovany kod dorazi se zapornym intem
        // pretypovanym na obri size_t (ten rozpocet prekroci vzdy).
        std::lock_guard<std::mutex> lock(g_mutex);
        if (!FitsBudgetLocked(size))
            return nullptr;
    }

    unsigned char* raw = static_cast<unsigned char*>(std::malloc(size + 2 * g_guard));
    if (!raw)
        return nullptr;
    FillGuards(raw, size);
    void* ptr = raw + g_guard;

    std::lock_guard<std::mutex> lock(g_mutex);
    if (g_trackingEnabled) {
        g_liveAllocations[ptr] = AllocInfo{size, debugTag};
        g_liveBytes += size;
    }
    return ptr;
}

void Free(void* ptr)
{
    if (!ptr)
        return;

    std::lock_guard<std::mutex> lock(g_mutex);
    if (g_trackingEnabled) {
        auto it = g_liveAllocations.find(ptr);
        if (it != g_liveAllocations.end()) {
            if (g_guard) {
                unsigned char* raw = static_cast<unsigned char*>(ptr) - g_guard;
                int bad = TestGuards(raw, it->second.size);
                if (bad)
                    std::fprintf(stderr, "Port::Memory: PRESTRELENY BLOK %p (%zu B, tag=%s) - %s straz\n",
                                 ptr, it->second.size,
                                 it->second.debugTag ? it->second.debugTag : "?",
                                 bad < 0 ? "predni" : "zadni");
            }
            g_liveBytes -= it->second.size;
            g_liveAllocations.erase(it);
        }
    }
    std::free(g_guard ? static_cast<unsigned char*>(ptr) - g_guard : ptr);
}

void* Realloc(void* ptr, std::size_t newSize, const char* debugTag)
{
    if (!ptr)
        return Alloc(newSize, debugTag);
    if (newSize == 0) {
        Free(ptr);
        return nullptr;
    }

    std::size_t oldSize = 0;
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        auto it = g_liveAllocations.find(ptr);
        if (it != g_liveAllocations.end())
            oldSize = it->second.size;
        // Rozpocet: pocita se jen NARUST oproti stavajici velikosti bloku.
        if (newSize > oldSize && !FitsBudgetLocked(newSize - oldSize))
            return nullptr;
    }

    if (g_guard) {
        // pod strazemi nejde volat realloc primo - blok ma jiny zacatek
        void* fresh = Alloc(newSize, debugTag);
        if (!fresh)
            return nullptr;
        std::memcpy(fresh, ptr, oldSize < newSize ? oldSize : newSize);
        Free(ptr);
        return fresh;
    }
    void* newPtr = std::realloc(ptr, newSize);
    if (!newPtr)
        return nullptr; // puvodni ptr dle realloc kontraktu zustava platny

    std::lock_guard<std::mutex> lock(g_mutex);
    if (g_trackingEnabled) {
        if (oldSize) {
            g_liveAllocations.erase(ptr);
            g_liveBytes -= oldSize;
        }
        g_liveAllocations[newPtr] = AllocInfo{newSize, debugTag};
        g_liveBytes += newSize;
    }
    return newPtr;
}

// PORT (vlna 99): projde VSECHNY zive bloky a nahlasi prvni, ktery ma
// poskozenou straz. Volat po podezrelem useku (napr. po vykresleni
// obrazovky) - rekne jmeno a velikost bloku, ktery se prestrelil, misto aby
// se chyba projevila az za dlouho v ntdll pri cizim free().
// Bez REORION2_MEM_GUARD=1 nedela nic a vraci 0.
int CheckGuards(const char* where)
{
    if (!g_guard)
        return 0;
    std::lock_guard<std::mutex> lock(g_mutex);
    int damaged = 0;
    for (const auto& [ptr, info] : g_liveAllocations) {
        const unsigned char* raw = static_cast<const unsigned char*>(ptr) - g_guard;
        int bad = TestGuards(raw, info.size);
        if (!bad)
            continue;
        ++damaged;
        if (damaged == 1) {
            std::fprintf(stderr, "Port::Memory[%s]: PRESTRELENY BLOK %p (%zu B, tag=%s) - %s straz\n",
                         where ? where : "?", ptr, info.size,
                         info.debugTag ? info.debugTag : "?", bad < 0 ? "predni" : "zadni");
            std::fflush(stderr);
            PortDebug_CrashLog("MEM[%s]: prestreleny blok %p (%zu B, tag=%s) - %s straz",
                               where ? where : "?", ptr, info.size,
                               info.debugTag ? info.debugTag : "?", bad < 0 ? "predni" : "zadni");
        }
    }
    return damaged;
}

std::size_t GetLiveBytes()
{
    std::lock_guard<std::mutex> lock(g_mutex);
    return g_liveBytes;
}

std::size_t GetLiveAllocationCount()
{
    std::lock_guard<std::mutex> lock(g_mutex);
    return g_liveAllocations.size();
}

std::size_t GetBudgetBytes()
{
    std::lock_guard<std::mutex> lock(g_mutex);
    return g_budgetBytes;
}

std::size_t GetAvailableBytes()
{
    std::lock_guard<std::mutex> lock(g_mutex);
    return g_liveBytes < g_budgetBytes ? g_budgetBytes - g_liveBytes : 0;
}

} // namespace Port::Memory

// ---------------------------------------------------------------------
// C-linkage most - viz DECOMP_TODO v port_memory.h. Vsechny 4 funkce jsou
// jen tenke obalky nad Port::Memory:: API vyse.
extern "C" {

void* PortMemory_Alloc(size_t size)
{
    return Port::Memory::Alloc(size, "malloc");
}

void* PortMemory_Calloc(size_t count, size_t size)
{
    // std::malloc negarantuje vynulovani pameti - calloc na rozdil od
    // malloc musi vratit vynulovany blok, proto rucni memset.
    std::size_t total = count * size;
    void* ptr = Port::Memory::Alloc(total, "calloc");
    if (ptr)
        std::memset(ptr, 0, total);
    return ptr;
}

void* PortMemory_Realloc(void* ptr, size_t size)
{
    return Port::Memory::Realloc(ptr, size, "realloc");
}

int PortMemory_Free(void* ptr)
{
    if (!ptr)
        return 0;
    Port::Memory::Free(ptr);
    return 1;
}

int memavl(void)
{
    // Watcom _memavl: kolik bajtu je jeste k dispozici pro alokaci.
    // V portu = zbytek emulovaneho rozpoctu. Clamp na INT_MAX kvuli
    // navratovemu typu int (dekompilovany kod pocita v intech).
    const std::size_t avail = Port::Memory::GetAvailableBytes();
    return avail > 0x7FFFFFFFu ? 0x7FFFFFFF : (int)avail;
}

} // extern "C"