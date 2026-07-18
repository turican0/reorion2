#include "port_file.h"

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <filesystem>
#include <optional>

#ifdef _WIN32
#include <io.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h> // GetModuleFileNameA - fallback datovy adresar (vlna 12)
#else
#include <dirent.h>
#include <unistd.h>
#include <strings.h> // strcasecmp
#endif

namespace fs = std::filesystem;

namespace Port::File {

// Tabulka otevrenych souboru - PortFile_Open vraci INDEX+1 do tohoto pole
// (0 = neplatny handle) misto skutecneho FILE*, viz DECOMP_TODO v
// port_file.h (herni kod uklada handle do 32bit int/_DWORD promennych,
// realny ukazatel na x64 by se orizl). Soubor-scope (ne anonymous
// namespace), aby byly dostupne i z extern "C" bloku nize v tomto souboru.
std::mutex g_handleMutex;
std::vector<FILE*> g_openFiles; // index 0 nepouzity (aby handle 0 == neplatny)

namespace {

std::mutex g_cacheMutex;
std::unordered_map<std::string, std::string> g_resolveCache;

// ---------------------------------------------------------------------
// Fallback datove adresare (vlna 12). Hra hleda VSECHNY soubory
// (fonts.lbx, sound.lbx, mox.set, savy...) v aktualnim pracovnim
// adresari - kdyz se exe spusti odjinud (F5 z Visual Studia, dvojklik
// na exe v x64/Debug, cmd z jineho adresare), skoncila hned na
// "fonts.lbx [entry 0] could not be found.". Kdyz soubor v cwd neni
// (cwd ma VZDY prednost - napr. cerstve zapsane savy), zkusi se poporade:
//   1. REORION2_DATA_DIR (env promenna, explicitni prepis),
//   2. adresar, kde lezi samotne exe (pokryva "nakopiroval jsem LBX
//      k exe do vystupni slozky"),
//   3. C:/prenos/mastori2 - znama instalace hry na tomto stroji
//      (posledni zachrana; pro jine stroje slouzi env promenna vyse).
// Pro F5 z VS je navic nastaveny LocalDebuggerWorkingDirectory v
// reorion2.vcxproj.user, takze fallback vetsinou ani neni potreba.
std::vector<std::string> BuildDataDirPrefixes()
{
    std::vector<std::string> dirs;
    auto add = [&dirs](std::string p) {
        if (p.empty())
            return;
        if (p.back() != '/' && p.back() != '\\')
            p += '/';
        dirs.push_back(std::move(p));
    };

    if (const char* env = std::getenv("REORION2_DATA_DIR"))
        add(env);

#ifdef _WIN32
    char exePath[MAX_PATH];
    DWORD n = GetModuleFileNameA(nullptr, exePath, MAX_PATH);
    if (n > 0 && n < MAX_PATH) {
        std::string p(exePath);
        size_t slash = p.find_last_of("/\\");
        if (slash != std::string::npos)
            add(p.substr(0, slash));
    }
#endif

    add("C:/prenos/mastori2");
    return dirs;
}

const std::vector<std::string>& DataDirPrefixes()
{
    static const std::vector<std::string> dirs = BuildDataDirPrefixes();
    return dirs;
}

// Fallback ma smysl jen pro relativni cesty (bez uvodniho lomitka a bez
// "X:" prefixu) - absolutni cestu uz nekdo slozil vedome.
bool IsRelativePath(const char* path)
{
    if (!path || !*path)
        return false;
    if (path[0] == '/' || path[0] == '\\')
        return false;
    if (path[1] == ':')
        return false;
    return true;
}

#ifndef _WIN32
// Rozdeli "path" na segmenty podle '/' NEBO '\\' (puvodni DOS kod ma
// oddelovace jako literalni zpetna lomitka primo v retezcovych
// konstantach, napr. "DATA\\SOUND.LBX") a kazdy segment dohleda
// case-insensitive v realnem adresari. Vysledek pouziva '/' (funguje na
// vsech POSIX systemech), puvodni velikost pismen v "path" je irelevantni.
std::string ResolveCaseInsensitiveImpl(const std::string& path)
{
    if (path.empty())
        return path;

    bool isAbsolute = path[0] == '/' || path[0] == '\\';
    std::string current = isAbsolute ? "/" : ".";
    size_t pos = isAbsolute ? 1 : 0;

    while (pos < path.size()) {
        size_t next = path.find_first_of("/\\", pos);
        std::string segment = (next == std::string::npos)
            ? path.substr(pos)
            : path.substr(pos, next - pos);

        if (!segment.empty() && segment != ".") {
            std::string matched = segment;
            DIR* dir = opendir(current.c_str());
            if (dir) {
                struct dirent* entry;
                while ((entry = readdir(dir)) != nullptr) {
                    if (strcasecmp(entry->d_name, segment.c_str()) == 0) {
                        matched = entry->d_name;
                        break;
                    }
                }
                closedir(dir);
            }
            // Pokud se presna case-insensitive shoda nenajde (napr. soubor
            // jeste neexistuje - zapis noveho souboru), pouzije se puvodni
            // segment beze zmeny - dalsi krok (fopen) pak selze/uspeje
            // standardnim zpusobem.
            current = (current == "/") ? ("/" + matched) : (current + "/" + matched);
        }

        if (next == std::string::npos)
            break;
        pos = next + 1;
    }

    return current;
}
#endif // !_WIN32

} // namespace

const char* ResolveCaseInsensitivePath(const char* path)
{
    if (!path)
        return path;

#ifdef _WIN32
    // NTFS/FAT jsou uz case-insensitive (case-preserving) samy o sobe -
    // zadne dohledavani neni potreba.
    return path;
#else
    std::lock_guard<std::mutex> lock(g_cacheMutex);
    auto it = g_resolveCache.find(path);
    if (it != g_resolveCache.end())
        return it->second.c_str();

    auto result = g_resolveCache.emplace(path, ResolveCaseInsensitiveImpl(path));
    return result.first->second.c_str();
#endif
}

void ClearResolveCache()
{
    std::lock_guard<std::mutex> lock(g_cacheMutex);
    g_resolveCache.clear();
}

namespace {

// Jednoduchy case-insensitive wildcard matcher pro DOS 8.3 vzory (* a ?).
// '*' = libovolny (i prazdny) retezec, '?' = presne jeden znak.
bool WildcardMatch(const char* pattern, const char* name)
{
    const char* p = pattern;
    const char* n = name;
    const char* starP = nullptr;
    const char* starN = nullptr;

    while (*n) {
        if (*p == '?' || (std::tolower((unsigned char)*p) == std::tolower((unsigned char)*n))) {
            ++p;
            ++n;
        } else if (*p == '*') {
            starP = p++;
            starN = n;
        } else if (starP) {
            p = starP + 1;
            n = ++starN;
        } else {
            return false;
        }
    }
    while (*p == '*')
        ++p;
    return *p == '\0';
}

// Prevod std::filesystem::file_time_type na DOS-kodovane datum/cas
// (stejny format, jaky by vratil skutecny INT 21h AH=4Eh/4Fh).
void EncodeDosDateTime(const fs::file_time_type& ftime, uint16_t& outDate, uint16_t& outTime)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(ftime - fs::file_time_type::clock::now() + system_clock::now());
    std::time_t tt = system_clock::to_time_t(sctp);
    std::tm tmv{};
#ifdef _WIN32
    localtime_s(&tmv, &tt);
#else
    localtime_r(&tt, &tmv);
#endif
    int year = tmv.tm_year + 1900;
    if (year < 1980) year = 1980; // DOS datum nezna roky pred 1980
    outDate = static_cast<uint16_t>(((year - 1980) << 9) | ((tmv.tm_mon + 1) << 5) | tmv.tm_mday);
    outTime = static_cast<uint16_t>((tmv.tm_hour << 11) | (tmv.tm_min << 5) | (tmv.tm_sec / 2));
}

// Stav jednoho probihajiciho hledani (mezi FindFirst a nasledujicimi
// FindNext) - handle na tento stav se uklada do DosDta::reserved, presne
// jako u puvodniho DOS DTA (tam je to opaque, tady je to jen index).
struct FindState {
    std::string directory;   // rozresena (case-insensitive) cesta k adresari
    std::string wildcard;    // jen jmenna cast vzoru (bez adresare)
    std::vector<fs::directory_entry> entries; // predem nactene, aby FindNext nemusel znovu prochazet adresar
    size_t nextIndex = 0;
};

std::mutex g_findMutex;
std::vector<std::optional<FindState>> g_findStates; // index 0 nepouzity (0 = neplatny handle)

// Naplni jednu polozku DosDta z nalezeneho directory_entry.
void FillDta(DosDta* dta, const fs::directory_entry& entry)
{
    std::string name = entry.path().filename().string();
    std::strncpy(dta->name, name.c_str(), sizeof(dta->name) - 1);
    dta->name[sizeof(dta->name) - 1] = '\0';

    std::error_code ec;
    auto size = entry.file_size(ec);
    dta->size = ec ? 0 : static_cast<uint32_t>(size);

    auto ftime = entry.last_write_time(ec);
    if (!ec)
        EncodeDosDateTime(ftime, dta->date, dta->time);
    else
        dta->date = dta->time = 0;

    // DOS atributy: bit0=read-only, bit4=adresar. Ostatni (hidden/system/
    // archive) nemame odkud spolehlive zjistit napric platformami - 0 je
    // bezpecny vychozi stav (bezny soubor).
    dta->attr = 0;
    if (entry.is_directory(ec))
        dta->attr |= 0x10;
}

// Najde dalsi zaznam v "state" odpovidajici wildcard vzoru a attrMask,
// vyplni "dta". Vraci false, kdyz uz zadny dalsi zaznam neni.
bool AdvanceFind(FindState& state, int attrMask, DosDta* dta)
{
    while (state.nextIndex < state.entries.size()) {
        const auto& entry = state.entries[state.nextIndex++];
        std::string name = entry.path().filename().string();

        std::error_code ec;
        bool isDir = entry.is_directory(ec);
        // attrMask==0 (typicky pouziti v teto hre) znamena "jen bezne
        // soubory" - adresare se v takovem hledani DOS konvenci preskakuji,
        // pokud volajici vyslovne nepozadal o bit 0x10 v masce.
        if (isDir && !(attrMask & 0x10))
            continue;

        if (!WildcardMatch(state.wildcard.c_str(), name.c_str()))
            continue;

        FillDta(dta, entry);
        return true;
    }
    return false;
}

} // namespace

bool FindFirst(const char* pattern, int attrMask, DosDta* dta)
{
    if (!pattern || !dta)
        return false;

    std::string patternStr(pattern);
    size_t slashPos = patternStr.find_last_of("/\\");
    std::string dirPart = (slashPos == std::string::npos) ? "." : patternStr.substr(0, slashPos);
    std::string wildcardPart = (slashPos == std::string::npos) ? patternStr : patternStr.substr(slashPos + 1);

    // Kandidatni adresare: nejdriv ten ze vzoru (cwd-relativni), pak
    // fallback datove adresare (vlna 12, viz BuildDataDirPrefixes) -
    // jinak by FindMoxSetPath ("mox.set") a vypis savu (*.GAM) nenasly
    // nic, kdyz exe nebezi primo z adresare hry, zatimco fopen by diky
    // svemu fallbacku stejny soubor otevrel.
    std::vector<std::string> candidateDirs;
    candidateDirs.push_back(dirPart);
    if (IsRelativePath(patternStr.c_str())) {
        for (const std::string& prefix : DataDirPrefixes())
            candidateDirs.push_back(prefix + ((dirPart == ".") ? std::string() : dirPart));
    }

    FindState state;
    state.wildcard = wildcardPart;
    bool found = false;
    for (const std::string& cand : candidateDirs) {
        state.directory = ResolveCaseInsensitivePath(cand.empty() ? "." : cand.c_str());
        state.entries.clear();
        state.nextIndex = 0;

        std::error_code ec;
        fs::directory_iterator it(state.directory, ec);
        if (ec)
            continue;
        for (const auto& entry : it)
            state.entries.push_back(entry);

        if (AdvanceFind(state, attrMask, dta)) {
            found = true;
            break;
        }
    }
    if (!found)
        return false;

    // Ulozit stav pro nasledne FindNext - handle (index do g_findStates)
    // se uklada primo do DosDta::reserved bajtu, presne jako skutecny DOS
    // DTA nese svuj vlastni (u nej opaque) hledaci stav mezi volanimi.
    std::lock_guard<std::mutex> lock(g_findMutex);
    if (g_findStates.empty())
        g_findStates.emplace_back(std::nullopt); // index 0 = "neplatny handle" strazce
    g_findStates.push_back(std::move(state));
    uint32_t handle = static_cast<uint32_t>(g_findStates.size() - 1);
    std::memcpy(dta->reserved, &handle, sizeof(handle));
    return true;
}

bool FindNext(DosDta* dta)
{
    if (!dta)
        return false;

    uint32_t handle = 0;
    std::memcpy(&handle, dta->reserved, sizeof(handle));

    std::lock_guard<std::mutex> lock(g_findMutex);
    if (handle == 0 || handle >= g_findStates.size() || !g_findStates[handle])
        return false;

    return AdvanceFind(*g_findStates[handle], /*attrMask=*/0, dta);
}

} // namespace Port::File

// ---------------------------------------------------------------------
// C-linkage most - viz DECOMP_TODO v port_file.h. Handle 0 = neplatny
// (falsy, stejne jako puvodne NULL z fopen).
extern "C" {

int unknown_libname_1(const char* pattern, int attrMask, struct DosDta* dta)
{
    // OPRAVENO: puvodni verze mela obracenou konvenci. Overeno krizovou
    // kontrolou VSECH 4 volajicich mist v orion_part_18.c - zejmena
    // "return unknown_libname_1(a1, 0, v2) == 0;" (sub_11181C, pouzivano
    // jako "soubor existuje" kontrola) je jednoznacny dukaz. Skutecna
    // DOS/Watcom konvence (jako errno): 0 = USPECH (nalezeno), nenulova
    // hodnota = CHYBA/nenalezeno - presne obracene nez typicky C bool.
    return Port::File::FindFirst(pattern, attrMask, dta) ? 0 : 1;
}

int unknown_libname_2(struct DosDta* dta)
{
    return Port::File::FindNext(dta) ? 0 : 1;
}

int PortFile_Open(const char* path, const char* mode)
{
    const char* resolved = Port::File::ResolveCaseInsensitivePath(path);
    FILE* f = std::fopen(resolved, mode);
    if (!f && Port::File::IsRelativePath(path)) {
        // Soubor v cwd neni - zkus fallback datove adresare (viz komentar
        // u BuildDataDirPrefixes vyse: env -> adresar exe -> mastori2).
        for (const std::string& prefix : Port::File::DataDirPrefixes()) {
            const std::string prefixed = prefix + path;
            f = std::fopen(Port::File::ResolveCaseInsensitivePath(prefixed.c_str()), mode);
            if (f)
                break;
        }
    }
    if (!f)
        return 0;

    // Zapis noveho souboru meni obsah adresare - zahodime cache, aby
    // pripadne dalsi otevreni stejneho jmena (jinou velikosti pismen) uz
    // naslo cerstve vytvoreny soubor pres presnou shodu.
    if (mode && (mode[0] == 'w' || mode[0] == 'a'))
        Port::File::ClearResolveCache();

    std::lock_guard<std::mutex> lock(Port::File::g_handleMutex);
    if (Port::File::g_openFiles.empty())
        Port::File::g_openFiles.push_back(nullptr); // index 0 = "neplatny handle" strazce

    Port::File::g_openFiles.push_back(f);
    return static_cast<int>(Port::File::g_openFiles.size() - 1);
}

int PortFile_Close(int handle)
{
    std::lock_guard<std::mutex> lock(Port::File::g_handleMutex);
    if (handle <= 0 || static_cast<size_t>(handle) >= Port::File::g_openFiles.size())
        return -1; // EOF-like chyba, stejne jako skutecne fclose na spatny handle
    FILE* f = Port::File::g_openFiles[handle];
    Port::File::g_openFiles[handle] = nullptr;
    return f ? std::fclose(f) : -1;
}

static FILE* PortFile_Resolve(int handle)
{
    std::lock_guard<std::mutex> lock(Port::File::g_handleMutex);
    if (handle <= 0 || static_cast<size_t>(handle) >= Port::File::g_openFiles.size())
        return nullptr;
    return Port::File::g_openFiles[handle];
}

size_t PortFile_Read(void* buffer, size_t size, size_t count, int handle)
{
    FILE* f = PortFile_Resolve(handle);
    return f ? std::fread(buffer, size, count, f) : 0;
}

size_t PortFile_Write(const void* buffer, size_t size, size_t count, int handle)
{
    FILE* f = PortFile_Resolve(handle);
    return f ? std::fwrite(buffer, size, count, f) : 0;
}

int PortFile_Seek(int handle, long offset, int origin)
{
    FILE* f = PortFile_Resolve(handle);
    return f ? std::fseek(f, offset, origin) : -1;
}

long PortFile_Tell(int handle)
{
    FILE* f = PortFile_Resolve(handle);
    return f ? std::ftell(f) : -1L;
}

int PortFile_Flush(int handle)
{
    FILE* f = PortFile_Resolve(handle);
    return f ? std::fflush(f) : -1;
}

int PortFile_Access(const char* path, int mode)
{
    const char* resolved = Port::File::ResolveCaseInsensitivePath(path);
#ifdef _WIN32
    int rc = _access(resolved, mode);
#else
    int rc = access(resolved, mode);
#endif
    if (rc != 0 && Port::File::IsRelativePath(path)) {
        // Stejny fallback jako v PortFile_Open - jinak by "existuje soubor?"
        // kontroly nesouhlasily s tim, co pak fopen skutecne otevre.
        for (const std::string& prefix : Port::File::DataDirPrefixes()) {
            const std::string prefixed = prefix + path;
            const char* r2 = Port::File::ResolveCaseInsensitivePath(prefixed.c_str());
#ifdef _WIN32
            rc = _access(r2, mode);
#else
            rc = access(r2, mode);
#endif
            if (rc == 0)
                break;
        }
    }
    return rc;
}

} // extern "C"
