#include "port_file.h"

#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <mutex>

#ifdef _WIN32
#include <io.h>
#else
#include <dirent.h>
#include <unistd.h>
#include <strings.h> // strcasecmp
#endif

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

} // namespace Port::File

// ---------------------------------------------------------------------
// C-linkage most - viz DECOMP_TODO v port_file.h. Handle 0 = neplatny
// (falsy, stejne jako puvodne NULL z fopen).
extern "C" {

int PortFile_Open(const char* path, const char* mode)
{
    const char* resolved = Port::File::ResolveCaseInsensitivePath(path);
    FILE* f = std::fopen(resolved, mode);
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
    return _access(resolved, mode);
#else
    return access(resolved, mode);
#endif
}

} // extern "C"
