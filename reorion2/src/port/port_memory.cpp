#include "port_memory.h"

#include <cstdlib>
#include <cstdio>
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

} // namespace

void Init()
{
    std::lock_guard<std::mutex> lock(g_mutex);
    g_liveAllocations.clear();
    g_liveBytes = 0;
    g_trackingEnabled = true;
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
    }
    g_trackingEnabled = false;
}

void* Alloc(std::size_t size, const char* debugTag)
{
    void* ptr = std::malloc(size);
    if (!ptr)
        return nullptr;

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
            g_liveBytes -= it->second.size;
            g_liveAllocations.erase(it);
        }
    }
    std::free(ptr);
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

} // extern "C"