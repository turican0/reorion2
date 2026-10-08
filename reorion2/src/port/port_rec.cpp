// port_rec.cpp - deterministic game record / replay (wave 183).
//
// REORION2_RECORD=<file.r2rec | auto>   records a whole session into ONE file
// REORION2_REPLAY=<file.r2rec>          replays it bit-exact, then goes live
//   REORION2_REPLAY_EXTRACT=1           first writes the start files to cwd
//   REORION2_REPLAY_FAST=1              no real-time waits while replaying
//
// Idea: the game code is deterministic, only the values it reads from the
// outside world are not. Every such read goes through PortRec_Value(src,
// live): the recorder stores the value (only when it changes) indexed by the
// GLOBAL call counter G; the replayer returns the stored value at the same G.
// The game then executes the same code, the RNG (LCG dword_1B9E34) follows
// the same sequence and the saves come out byte-identical. Sources:
//   mouse (ComputeVirtualMouse), key (PortInput_PollKeyPress), BIOS tick,
//   AIL ms counter, frame-wait clock (PortVga_WaitSliced), audio queue depth
//   (drives the game mixer and the video waits), file date/time.
//
// File: "R2REC\x01\0\0" + chunks { char tag[4]; u32 len; payload }
//   META  text "key=value\n" (build, env REORION2_* at record start)
//   FILE  u16 name_len, name, data         start files (MOX.SET, SAVE*.GAM)
//   EVTS  record stream (continues across chunks):
//           u8 type, varint dG, payload
//           type < 0x40  value of source `type`, payload zigzag(v - last)
//           0x40 CHECK   payload varint RNG seed (taken inside the call)
//           0x41 MARK    no payload ("the recorder reached G")
//           0x42 PRESS   varint ms, varint mouse, varint CRC32 x regions, varint RNG,
//                        varint waiting game function, varint its caller (IDA)
//           0x43 RELEASE varint ms, varint mouse
//           0x44 SYNC    varint ms (first entry of the main menu sub_816F2)
//           0x45 KEYMS   varint ms, varint key code
//         (0x42..0x45 carry real time + structure state for the DOSBox
//          comparison, tools/compare/r2rec.py)
//   SAVE  u64 G, u16 name_len, name, data  every save the game wrote
// A replay compares the RNG at each CHECK and every save it writes with the
// recorded one; results go to reorion2_replay.log.
#include <SDL3/SDL.h>

#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")
#endif

extern "C" uint8_t dseg[];
extern "C" void PortRec_GameRegions(const uint8_t* ptr[10], uint32_t size[10]);
extern "C" void PortDebug_Backtrace(const char* tag, int frames);

namespace {

enum { kSrcCount = 16 };
int g_pressNow = 0;   // wave 183: presses replayed so far (REORION2_REPLAY_FRAMES)
const char* const kSrcName[kSrcCount] = { "mouse", "key", "tick", "ms", "wait", "audioq", "ftime", "time" };

int      g_mode = 0;          // 0 off, 1 record, 2 replay
FILE*    g_out = nullptr;     // record
std::vector<uint8_t> g_buf;   // record: pending EVTS payload
uint64_t g_G = 0;             // global call counter
uint64_t g_lastEvG = 0;       // G of the last written/read record
uint32_t g_last[kSrcCount];   // last value per source (delta base)
uint64_t g_lastFlushMs = 0;
unsigned long g_thread = 0;

// replay
std::vector<uint8_t> g_ev;    // all EVTS payloads concatenated
size_t   g_pos = 0;
uint64_t g_nextG = UINT64_MAX; // G of the next record (UINT64_MAX = none)
int      g_nextType = -1;
uint64_t g_endG = 0;           // last G mentioned in the record
bool     g_fast = false;
struct SaveRec { uint64_t G; std::string name; std::vector<uint8_t> data; };
std::vector<SaveRec> g_saves;  // replay: recorded saves, in order
size_t   g_saveIdx = 0;        // record + replay: saves seen so far
int      g_checks = 0, g_checkFails = 0;
std::vector<std::string> g_metaEnv;   // replay: REORION2_* names set in the record

uint32_t Rng() { return *reinterpret_cast<uint32_t*>(dseg + 0x41E34); }   // dword_1B9E34

// Main game structures (= what the save holds, sub_1049B writer). C address,
// pointer or not, size. The same table is in my DOSBox (engine.cpp STATE),
// DOSBox address = C + 0x216000, dseg offset = C - 0x178000.
struct Region { const char* name; uint32_t c; bool ptr; uint32_t size; };
const Region kRegions[] = {
    { "colonies", 0x192B18, true,  361 * 250 },
    { "planets",  0x1930D4, true,  17 * 360 },
    { "stars",    0x19306C, true,  113 * 72 },
    { "leaders",  0x1930DC, true,  59 * 67 },
    { "players",  0x197F98, true,  3753 * 8 },
    { "ships",    0x197F9C, true,  129 * 500 },
    { "events",   0x1AB14C, false, 950 },
    { "1AA414",   0x1AA414, false, 18 * 100 },
    { "19ABA4",   0x19ABA4, false, 9 * 36 },
    { "counts",   0x199994, false, 0x10 },   // 199994..1999A3: ship/player/star/colony/planet counts
};
enum { kRegionCount = sizeof(kRegions) / sizeof(kRegions[0]) };

uint32_t Crc32(const uint8_t* p, uint32_t n)
{
    static uint32_t t[256];
    if (!t[1])
        for (uint32_t i = 0; i < 256; ++i) {
            uint32_t c = i;
            for (int k = 0; k < 8; ++k) c = (c & 1) ? 0xEDB88320u ^ (c >> 1) : c >> 1;
            t[i] = c;
        }
    uint32_t c = 0xFFFFFFFFu;
    while (n--) c = t[(c ^ *p++) & 0xFF] ^ (c >> 8);
    return ~c;
}

// Where the game waits for this input: the innermost two game functions on the
// stack (IDA start addresses from the symbol names sub_XXXXX / Name_XXXXX).
// My DOSBox presses a step only when it sees the same function called from the
// same caller - the game is back in the same input loop (not in an animation).
void GameFrames(uint32_t& inner, uint32_t& outer)
{
    inner = outer = 0;
#ifdef _WIN32
    static bool inited = false;
    HANDLE proc = GetCurrentProcess();
    if (!inited) { SymSetOptions(SYMOPT_UNDNAME); SymInitialize(proc, nullptr, TRUE); inited = true; }
    void* st[48] = {0};
    const USHORT got = CaptureStackBackTrace(1, 48, st, nullptr);
    unsigned char buf[sizeof(SYMBOL_INFO) + 256] = {0};
    SYMBOL_INFO* sym = reinterpret_cast<SYMBOL_INFO*>(buf);
    for (USHORT i = 0; i < got && !outer; ++i) {
        std::memset(buf, 0, sizeof buf);
        sym->SizeOfStruct = sizeof(SYMBOL_INFO);
        sym->MaxNameLen = 255;
        DWORD64 disp = 0;
        if (!SymFromAddr(proc, (DWORD64)st[i], &disp, sym)) continue;
        const char* us = std::strrchr(sym->Name, '_');
        if (!us || std::strlen(us + 1) < 4) continue;
        char* end = nullptr;
        const unsigned long a = std::strtoul(us + 1, &end, 16);
        if (!end || *end || a < 0x10000 || a >= 0x200000) continue;
        if (!inner) inner = (uint32_t)a;
        else if ((uint32_t)a != inner) outer = (uint32_t)a;
    }
#endif
}

void StateHashes(uint32_t out[kRegionCount])
{
    // the pointers are separate C globals in the port (orion_data.c), so the
    // table lives in the game code (orion_part_19.c)
    const uint8_t* p[kRegionCount];
    uint32_t n[kRegionCount];
    PortRec_GameRegions(p, n);
    for (int i = 0; i < kRegionCount; ++i)
        out[i] = p[i] ? Crc32(p[i], n[i]) : 0;
}

void Log(const char* fmt, ...)
{
    static FILE* f = nullptr;
    if (!f) f = std::fopen("reorion2_replay.log", g_mode == 2 ? "w" : "a");
    char line[1024];
    va_list ap;
    va_start(ap, fmt);
    std::vsnprintf(line, sizeof line, fmt, ap);
    va_end(ap);
    SDL_Log("PortRec: %s", line);
    if (f) { std::fprintf(f, "%s\n", line); std::fflush(f); }
}

unsigned long ThreadId()
{
#ifdef _WIN32
    return (unsigned long)GetCurrentThreadId();
#else
    return 0;
#endif
}

void PutVar(std::vector<uint8_t>& b, uint64_t v)
{
    while (v >= 0x80) { b.push_back((uint8_t)(v | 0x80)); v >>= 7; }
    b.push_back((uint8_t)v);
}

bool GetVar(uint64_t& v)
{
    v = 0;
    for (int sh = 0; g_pos < g_ev.size() && sh < 64; sh += 7) {
        const uint8_t c = g_ev[g_pos++];
        v |= (uint64_t)(c & 0x7F) << sh;
        if (!(c & 0x80)) return true;
    }
    return false;
}

void WriteChunk(const char tag[4], const void* p, uint32_t n)
{
    if (!g_out) return;
    std::fwrite(tag, 1, 4, g_out);
    std::fwrite(&n, 4, 1, g_out);
    if (n) std::fwrite(p, 1, n, g_out);
    std::fflush(g_out);
}

void FlushEvents()
{
    if (g_mode != 1 || !g_out) return;
    g_buf.push_back(0x41);                 // MARK: reached G
    PutVar(g_buf, g_G - g_lastEvG);
    g_lastEvG = g_G;
    WriteChunk("EVTS", g_buf.data(), (uint32_t)g_buf.size());
    g_buf.clear();
    g_lastFlushMs = SDL_GetTicks();
}

void Emit(int type, uint64_t payload, bool hasPayload)
{
    g_buf.push_back((uint8_t)type);
    PutVar(g_buf, g_G - g_lastEvG);
    g_lastEvG = g_G;
    if (hasPayload) PutVar(g_buf, payload);
    if (g_buf.size() > 65536) FlushEvents();
}

std::vector<uint8_t> ReadFile(const std::string& path)
{
    std::vector<uint8_t> d;
    FILE* f = std::fopen(path.c_str(), "rb");
    if (!f) return d;
    std::fseek(f, 0, SEEK_END);
    long n = std::ftell(f);
    std::fseek(f, 0, SEEK_SET);
    if (n > 0) { d.resize((size_t)n); d.resize(std::fread(d.data(), 1, (size_t)n, f)); }
    std::fclose(f);
    return d;
}

std::string Upper(std::string s) { for (auto& c : s) c = (char)toupper((unsigned char)c); return s; }

bool IsGameFile(const std::string& name)
{
    const std::string u = Upper(name);
    return u == "MOX.SET" || (u.rfind("SAVE", 0) == 0 && u.size() > 8 && u.substr(u.size() - 4) == ".GAM");
}

// replay: read the next record header (type + G)
void NextRecord()
{
    g_nextG = UINT64_MAX;
    g_nextType = -1;
    if (g_pos >= g_ev.size()) return;
    const int type = g_ev[g_pos++];
    uint64_t dg = 0;
    if (!GetVar(dg)) return;
    g_nextType = type;
    g_nextG = g_lastEvG + dg;
    g_lastEvG = g_nextG;
}

int PayloadVars(int type)
{
    if (type < kSrcCount || type == 0x40 || type == 0x44) return 1;
    if (type == 0x42) return 2 + kRegionCount + 1 + 2;
    if (type == 0x43 || type == 0x45) return 2;
    return 0;
}

void EndReplay(const char* why)
{
    Log("REPLAY END (%s) at G=%llu, record end G=%llu, checks %d ok / %d failed - input is live now",
        why, (unsigned long long)g_G, (unsigned long long)g_endG, g_checks - g_checkFails, g_checkFails);
    g_mode = 0;
}

bool LoadReplay(const char* path)
{
    std::vector<uint8_t> d = ReadFile(path);
    if (d.size() < 8 || std::memcmp(d.data(), "R2REC\x01", 6) != 0) {
        Log("REPLAY: %s is not a record", path);
        return false;
    }
    const bool extract = SDL_getenv("REORION2_REPLAY_EXTRACT") && *SDL_getenv("REORION2_REPLAY_EXTRACT") == '1';
    size_t p = 8;
    int files = 0;
    while (p + 8 <= d.size()) {
        char tag[5] = {0};
        std::memcpy(tag, &d[p], 4);
        uint32_t n = 0;
        std::memcpy(&n, &d[p + 4], 4);
        p += 8;
        if (p + n > d.size()) { Log("REPLAY: truncated chunk %s (crash while recording?)", tag); break; }
        const uint8_t* c = &d[p];
        if (!std::strcmp(tag, "EVTS")) {
            g_ev.insert(g_ev.end(), c, c + n);
        } else if (!std::strcmp(tag, "META")) {
            // env of the recording (SKIPINTRO etc.) - the game must take the same paths
            std::string meta((const char*)c, n);
            size_t a = 0;
            while (a < meta.size()) {
                size_t e = meta.find('\n', a);
                if (e == std::string::npos) e = meta.size();
                const std::string ln = meta.substr(a, e - a);
                a = e + 1;
                const size_t eq = ln.find('=');
                if (ln.rfind("env.", 0) != 0 || eq == std::string::npos) continue;
                const std::string k = ln.substr(4, eq - 4), v = ln.substr(eq + 1);
                // scripted input is in the record already
                if (k.rfind("REORION2_CLICK", 0) == 0 || k.rfind("REORION2_SENDKEY", 0) == 0 ||
                    k.rfind("REORION2_FAKE_", 0) == 0) continue;
                g_metaEnv.push_back(k);
                // wave 183: the recorded env WINS - a different REORION2_VIDEO_AUDIO
                // took the intro through other clocks (desync at G=4520)
                const char* cur = SDL_getenv(k.c_str());
                if (cur && v == cur) continue;
#ifdef _WIN32
                _putenv_s(k.c_str(), v.c_str());
#else
                setenv(k.c_str(), v.c_str(), 1);
#endif
                SDL_setenv_unsafe(k.c_str(), v.c_str(), 1);
                Log("REPLAY: env %s=%s (from the record)", k.c_str(), v.c_str());
            }
        } else if (!std::strcmp(tag, "FILE") && n >= 2) {
            uint16_t nl = 0;
            std::memcpy(&nl, c, 2);
            const std::string name((const char*)c + 2, nl);
            if (extract) {
                FILE* f = std::fopen(name.c_str(), "wb");
                if (f) { std::fwrite(c + 2 + nl, 1, n - 2 - nl, f); std::fclose(f); ++files; }
            }
        } else if (!std::strcmp(tag, "SAVE") && n >= 10) {
            SaveRec s;
            std::memcpy(&s.G, c, 8);
            uint16_t nl = 0;
            std::memcpy(&nl, c + 8, 2);
            s.name.assign((const char*)c + 10, nl);
            s.data.assign(c + 10 + nl, c + n);
            g_saves.push_back(std::move(s));
        }
        p += n;
    }
    // game switches that were NOT set while recording must not be set now
    // (tool / debug variables stay: they do not change what the game does)
    {
        static const char* const tools[] = { "REORION2_REPLAY", "REORION2_RECORD", "REORION2_DUMP",
            "REORION2_BLIT_DUMP", "REORION2_RNG_LOG", "REORION2_INPUT_LOG", "REORION2_PROBE",
            "REORION2_TRACE", "REORION2_MOUSE_TRACE", "REORION2_PRESENT_TRACE", "REORION2_AUDIO_TRACE",
            "REORION2_AUDIO_STATS", "REORION2_CTL", "REORION2_CLICK", "REORION2_SENDKEY", "REORION2_FAKE_",
            "REORION2_IGNORE_REAL_INPUT" };
        std::vector<std::string> drop;
#ifdef _WIN32
        for (char** e = _environ; e && *e; ++e) {
#else
        extern char** environ;
        for (char** e = environ; e && *e; ++e) {
#endif
            const std::string s = *e;
            const size_t eq = s.find('=');
            if (s.rfind("REORION2_", 0) != 0 || eq == std::string::npos) continue;
            const std::string k = s.substr(0, eq);
            bool keep = false;
            for (const char* t : tools) if (k.rfind(t, 0) == 0) keep = true;
            for (const std::string& m : g_metaEnv) if (m == k) keep = true;
            if (!keep) drop.push_back(k);
        }
        for (const std::string& k : drop) {
#ifdef _WIN32
            _putenv_s(k.c_str(), "");
#else
            unsetenv(k.c_str());
#endif
            SDL_unsetenv_unsafe(k.c_str());
            Log("REPLAY: env %s removed (not set in the record)", k.c_str());
        }
    }
    // last G mentioned = end of the recording
    {
        size_t save = g_pos; uint64_t lg = g_lastEvG;
        while (true) {
            NextRecord();
            if (g_nextType < 0) break;
            g_endG = g_nextG;
            for (int k = PayloadVars(g_nextType); k > 0; --k) { uint64_t v; GetVar(v); }
        }
        g_pos = save; g_lastEvG = lg;
    }
    NextRecord();
    Log("REPLAY %s: %zu B of events, end G=%llu, %zu saves%s", path, g_ev.size(),
        (unsigned long long)g_endG, g_saves.size(), extract ? "" : " (start files NOT extracted)");
    if (extract) Log("REPLAY: %d start files written to the current directory", files);
    return true;
}

bool StartRecord(const char* spec)
{
    std::string path = spec;
    if (path == "auto" || path == "1") {
        char nm[64];
        std::time_t t = std::time(nullptr);
        std::tm tmv{};
#ifdef _WIN32
        localtime_s(&tmv, &t);
#else
        localtime_r(&t, &tmv);
#endif
        std::strftime(nm, sizeof nm, "record_%Y%m%d_%H%M%S.r2rec", &tmv);
        path = nm;
    }
    g_out = std::fopen(path.c_str(), "wb");
    if (!g_out) { Log("RECORD: cannot create %s", path.c_str()); return false; }
    std::fwrite("R2REC\x01\0\0", 1, 8, g_out);
    std::string meta = "build=" __DATE__ " " __TIME__ "\n";
    {
        std::time_t t = std::time(nullptr);
        meta += "started=" + std::to_string((long long)t) + "\n";
    }
#ifdef _WIN32
    for (char** e = _environ; e && *e; ++e) {
#else
    extern char** environ;
    for (char** e = environ; e && *e; ++e) {
#endif
        const std::string s = *e;
        if (s.rfind("REORION2_", 0) != 0) continue;
        static const char* const skip[] = { "REORION2_RECORD", "REORION2_REPLAY", "REORION2_DUMP",
            "REORION2_BLIT_DUMP", "REORION2_RNG_LOG", "REORION2_INPUT_LOG", "REORION2_PROBE" };
        bool bad = false;
        for (const char* k : skip) if (s.rfind(k, 0) == 0) bad = true;
        if (!bad) meta += "env." + s + "\n";
    }
    WriteChunk("META", meta.data(), (uint32_t)meta.size());
    int files = 0;
    std::error_code ec;
    for (const auto& de : std::filesystem::directory_iterator(".", ec)) {
        const std::string name = de.path().filename().string();
        if (!de.is_regular_file() || !IsGameFile(name)) continue;
        const std::vector<uint8_t> d = ReadFile(name);
        std::vector<uint8_t> c(2 + name.size());
        const uint16_t nl = (uint16_t)name.size();
        std::memcpy(c.data(), &nl, 2);
        std::memcpy(c.data() + 2, name.data(), name.size());
        c.insert(c.end(), d.begin(), d.end());
        WriteChunk("FILE", c.data(), (uint32_t)c.size());
        ++files;
    }
    Log("RECORD %s: %d start files", path.c_str(), files);
    return true;
}

} // namespace

extern "C" {

void PortRec_Init(void)
{
    g_thread = ThreadId();
    std::memset(g_last, 0, sizeof g_last);
    if (const char* r = SDL_getenv("REORION2_REPLAY"); r && *r) {
        if (LoadReplay(r)) {
            g_mode = 2;
            g_fast = SDL_getenv("REORION2_REPLAY_FAST") && *SDL_getenv("REORION2_REPLAY_FAST") == '1';
        }
        return;
    }
    if (const char* r = SDL_getenv("REORION2_RECORD"); r && *r) {
        if (StartRecord(r)) {
            g_mode = 1;
            std::atexit([] { FlushEvents(); });
        }
    }
}

int PortRec_Replaying(void) { return g_mode == 2; }
unsigned long long PortRec_G(void) { return g_G; }   // for probes
int PortRec_PressIndex(void) { return g_pressNow; }   // wave 183: presses replayed so far
int PortRec_FastReplay(void) { return g_mode == 2 && g_fast; }

uint32_t PortRec_Value(int src, uint32_t live)
{
    if (!g_mode) return live;
    if (ThreadId() != g_thread) {
        static bool warned = false;
        if (!warned) { warned = true; Log("WARNING: source %s read from another thread - not recorded", kSrcName[src]); }
        return live;
    }
    if (g_mode == 1) {
        const bool check = src <= 1 || (g_G & 8191) == 0;
        if (live != g_last[src]) {
            const uint32_t prev = g_last[src];
            const int32_t d = (int32_t)(live - prev);
            Emit(src, ((uint32_t)d << 1) ^ (uint32_t)(d >> 31), true);
            g_last[src] = live;
            if (check) Emit(0x40, Rng(), true);
            const uint64_t ms = SDL_GetTicks();
            if (src == 0 && !(prev >> 24) && (live >> 24)) {          // button pressed
                uint32_t h[kRegionCount];
                StateHashes(h);
                Emit(0x42, ms, true);
                PutVar(g_buf, live);
                for (int i = 0; i < kRegionCount; ++i) PutVar(g_buf, h[i]);
                PutVar(g_buf, Rng());
                uint32_t fin = 0, fout = 0;
                GameFrames(fin, fout);
                PutVar(g_buf, fin);
                PutVar(g_buf, fout);
            } else if (src == 0 && (prev >> 24) && !(live >> 24)) {   // all released
                Emit(0x43, ms, true);
                PutVar(g_buf, live);
            } else if (src == 1 && live) {
                Emit(0x45, ms, true);
                PutVar(g_buf, live);
            }
        } else if ((g_G & 8191) == 0) {
            Emit(0x40, Rng(), true);
        }
        ++g_G;
        return live;
    }
    // replay
    while (g_nextG == g_G) {
        const int t = g_nextType;
        if (t == 0x41) { NextRecord(); continue; }
        uint64_t pl = 0;
        GetVar(pl);
        if (t == 0x42) {                                   // state at a press
            static int s_press = 0;
            uint64_t mouse = 0, v = 0;
            GetVar(mouse);
            uint32_t h[kRegionCount];
            StateHashes(h);
            std::string bad;
            for (int i = 0; i < kRegionCount; ++i) {
                GetVar(v);
                if ((uint32_t)v != h[i]) { bad += ' '; bad += kRegions[i].name; }
            }
            GetVar(v);                                     // RNG
            GetVar(v);                                     // waiting function
            GetVar(v);                                     // its caller
            ++s_press;
            g_pressNow = s_press;
            // REORION2_REPLAY_TRACE_PRESS=N: call stack at press N (which game loop reads it)
            static int s_trace = -2;
            if (s_trace == -2) {
                const char* e = SDL_getenv("REORION2_REPLAY_TRACE_PRESS");
                s_trace = e ? std::atoi(e) : -1;
            }
            // REORION2_REPLAY_DUMP_PRESS=5,6,7: dseg (0x5DCD0 B, C 0x178000..) before press N
            if (const char* e = SDL_getenv("REORION2_REPLAY_DUMP_PRESS")) {
                const std::string list = std::string(",") + e + ",";
                if (list.find("," + std::to_string(s_press) + ",") != std::string::npos) {
                    char nm[64];
                    std::snprintf(nm, sizeof nm, "dseg_p%d.bin", s_press);
                    if (FILE* f = std::fopen(nm, "wb")) { std::fwrite(dseg, 1, 0x5DCD0, f); std::fclose(f); }
                    // + the 10 main structures back to back (same order as kRegions)
                    std::snprintf(nm, sizeof nm, "regions_p%d.bin", s_press);
                    if (FILE* f = std::fopen(nm, "wb")) {
                        const uint8_t* rp[kRegionCount];
                        uint32_t rn[kRegionCount];
                        PortRec_GameRegions(rp, rn);
                        for (int i = 0; i < kRegionCount; ++i)
                            if (rp[i]) std::fwrite(rp[i], 1, rn[i], f);
                        std::fclose(f);
                    }
                }
            }
            if (s_press == s_trace) {
                Log("PRESS #%d at G=%llu: call stack -> reorion2_crash.log", s_press, (unsigned long long)g_G);
                PortDebug_Backtrace("replay press", 24);
            }
            if (!bad.empty() && ++g_checkFails <= 20)
                Log("PRESS #%d at G=%llu (%d,%d): state DIFFERS in%s", s_press, (unsigned long long)g_G,
                    (int)(mouse & 0xFFF), (int)((mouse >> 12) & 0xFFF), bad.c_str());
            ++g_checks;
            NextRecord();
            continue;
        }
        if (t >= 0x43) {                                   // DOSBox-side info only
            for (int k = PayloadVars(t) - 1; k > 0; --k) { uint64_t v; GetVar(v); }
            NextRecord();
            continue;
        }
        if (t == 0x40) {
            ++g_checks;
            if ((uint32_t)pl != Rng()) {
                if (++g_checkFails <= 20)
                    Log("CHECK FAILED at G=%llu (%s): RNG record %08X, replay %08X",
                        (unsigned long long)g_G, kSrcName[src], (unsigned)pl, (unsigned)Rng());
            }
        } else if (t < kSrcCount) {
            if (t != src) {
                Log("DESYNC at G=%llu: record reads %s, replay reads %s", (unsigned long long)g_G,
                    kSrcName[t], kSrcName[src]);
                EndReplay("desync");
                return live;
            }
            const uint32_t z = (uint32_t)pl;
            const int32_t d = (int32_t)((z >> 1) ^ (0u - (z & 1)));
            g_last[src] += (uint32_t)d;
        }
        NextRecord();
    }
    const uint32_t v = g_last[src];
    ++g_G;
    if (g_G > g_endG) EndReplay("end of the record");
    return v;
}

// Called from Present: periodic flush so a crash loses at most ~200 ms.
void PortRec_Tick(void)
{
    if (g_mode == 1 && SDL_GetTicks() - g_lastFlushMs >= 200) FlushEvents();
}

void PortRec_Flush(void) { FlushEvents(); }

// time() of the game code (decomp_compat.h macro) - Watcom time_t is 32 bits.
int PortRec_Time(void* p)
{
    const uint32_t v = PortRec_Value(7, (uint32_t)std::time(nullptr));
    if (p) std::memcpy(p, &v, 4);
    return (int)v;
}

// First entry of the main menu (sub_816F2) = DOSBox after=0x002A56F2 anchor.
void PortRec_Sync(void)
{
    if (g_mode == 1) Emit(0x44, SDL_GetTicks(), true);
}

// The game closed a file it wrote (port_file.cpp).
void PortRec_OnFileWritten(const char* path)
{
    if (!g_mode || !path) return;
    const std::string name = std::filesystem::path(path).filename().string();
    if (!IsGameFile(name) || Upper(name) == "MOX.SET") return;
    const std::vector<uint8_t> d = ReadFile(path);
    if (g_mode == 1) {
        FlushEvents();
        std::vector<uint8_t> c(10 + name.size());
        const uint16_t nl = (uint16_t)name.size();
        std::memcpy(c.data(), &g_G, 8);
        std::memcpy(c.data() + 8, &nl, 2);
        std::memcpy(c.data() + 10, name.data(), name.size());
        c.insert(c.end(), d.begin(), d.end());
        WriteChunk("SAVE", c.data(), (uint32_t)c.size());
        Log("RECORD: save #%zu %s at G=%llu (RNG %08X)", ++g_saveIdx, name.c_str(),
            (unsigned long long)g_G, (unsigned)Rng());
        return;
    }
    if (g_saveIdx >= g_saves.size()) {
        Log("REPLAY: save %s at G=%llu has no recorded counterpart", name.c_str(), (unsigned long long)g_G);
        return;
    }
    const SaveRec& s = g_saves[g_saveIdx++];
    int diffs = 0;
    std::string first;
    const size_t n = s.data.size() > d.size() ? s.data.size() : d.size();
    for (size_t i = 0; i < n; ++i) {
        const int a = i < s.data.size() ? s.data[i] : -1, b = i < d.size() ? d[i] : -1;
        if (a == b) continue;
        if (++diffs <= 8) {
            char t[48];
            std::snprintf(t, sizeof t, " %zX:%02X/%02X", i, a & 0xFF, b & 0xFF);
            first += t;
        }
    }
    Log("SAVE #%zu %s (record %s, G %llu/%llu): %s%s", g_saveIdx, name.c_str(), s.name.c_str(),
        (unsigned long long)s.G, (unsigned long long)g_G,
        diffs ? "DIFFERS" : "identical", diffs ? (" in " + std::to_string(diffs) + " bytes:" + first).c_str() : "");
}

} // extern "C"
