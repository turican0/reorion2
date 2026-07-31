#include "port_vga.h"

#include <SDL3/SDL.h>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

namespace Port::Vga {

namespace {
// Vlna 21: 640x480 - hra bezi ve vynucenem VESA modu 5 (viz sub_1248AB).
constexpr int kModeWidth = 640;
constexpr int kModeHeight = 480;
// Zaloha = 5 celych VESA bank po 64 KiB (327680 B > 640*480 = 307200 B):
// bankovane kopie originalu (sub_1255DF, sub_125814...) smely sahat az na
// konec posledniho 64KiB okna, ne jen na konec viditelneho obrazu.
constexpr size_t kFramebufferBytes = 5 * 0x10000;

SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
SDL_Texture* g_texture = nullptr;

// Framebuffer NENI staticke pole. Dekompilovany kod ho uklada do 32bit intu
// (dword_1BB910[0] = (int)PortVga_Framebuffer()); staticke pole zije v datovem
// segmentu modulu, ktery na x64 lezi vysoko (image base ~0x140000000) - cast
// na int ho orezal na 0/garbage (odtud hlaseny "result=0" v sub_138CE0).
// Proto ho bereme z HALDY pres malloc: pod /LARGEADDRESSAWARE:NO lezi heap v
// dolnich 2 GB a ukazatel round-tripuje pres int - stejne jako vsechny ostatni
// buffery portu (dword_1BB90C z PoolAlloc funguje presne z tohoto duvodu).
uint8_t* g_framebuffer = nullptr;
std::array<uint32_t, 256> g_palette{}; // ulozeno uz jako ARGB8888 pro SDL

bool g_initialized = false;

// PORT (wave 25p): debug-only frame dump, requested by user to compare the
// port's actual rendered framebuffer+palette against dosbox-x DUMPFRAME
// captures of the original, byte-for-byte, instead of relying on
// register-trace inference alone. Two modes, both read once from env on
// first call:
//   REORION2_DUMP_FRAME=N          - legacy single dump at Present() #N,
//                                     writes port_frame.raw + port_frame.bmp.
//   REORION2_DUMP_FRAME_RANGE=S:C  - batch dump of C consecutive frames
//                                     starting at Present() #S, writes
//                                     frame_00000.raw .. frame_(C-1).raw -
//                                     SAME layout as dosbox-x's DUMPFRAME
//                                     (768B RGB8 palette + WxH index bytes)
//                                     so genCompare/compare_frames can diff
//                                     them directly, index-for-index.
// Both write to REORION2_DUMP_DIR (default: cwd).
void DumpRawFrame(const std::string& path, const uint8_t* framebuffer,
                   const std::array<uint32_t, 256>& palette, int width, int height)
{
    FILE* f = std::fopen(path.c_str(), "wb");
    if (!f)
        return;
    for (int i = 0; i < 256; ++i) {
        uint32_t argb = palette[static_cast<size_t>(i)];
        uint8_t rgb[3] = { static_cast<uint8_t>((argb >> 16) & 0xFF),
                            static_cast<uint8_t>((argb >> 8) & 0xFF),
                            static_cast<uint8_t>(argb & 0xFF) };
        std::fwrite(rgb, 1, 3, f);
    }
    std::fwrite(framebuffer, 1, static_cast<size_t>(width) * height, f);
    std::fclose(f);
}

unsigned char expand6to8(unsigned char v)
{
    return static_cast<unsigned char>((v << 2) | (v >> 4));
}

// PORT (wave 25p, per user request): instead of dumping port frames to
// files and comparing them with an external tool afterward, compare
// in-process against a directory of dosbox-x DUMPFRAME captures
// (frame_NNNNN.raw, same 768B-palette+WxH-index layout) and abort with a
// precise diagnostic the INSTANT a distinct-content frame diverges - no
// alignment guesswork, no post-hoc tooling, exact frame number up front.
// Enabled by REORION2_COMPARE_DIR=<dir with frame_NNNNN.raw from dosbox>.
// Driven by the SAME "content actually changed" gate as the batch dump
// (see DumpFrameIfRequested) so it compares the same kind of event dosbox
// captures (a real draw), not every vsync/busy-wait Present() call.
// Returns true if `fb`(index bytes)+`pal` match a loaded reference frame's
// palette (6-bit, expanded)+framebuffer within `tolerance` differing bytes.
static bool FramesRoughlyMatch(const std::vector<uint8_t>& ref, const uint8_t* fb,
                                const std::array<uint32_t, 256>& pal, size_t fbBytes,
                                int* outPaletteMismatches, long* outPixelMismatches,
                                long* outFirstPixelMismatch)
{
    int paletteMismatches = 0;
    for (int c = 0; c < 256 * 3; ++c) {
        uint8_t refVal = expand6to8(ref[static_cast<size_t>(c)]);
        int ch = c % 3;
        uint32_t argb = pal[static_cast<size_t>(c / 3)];
        uint8_t portVal = (ch == 0) ? static_cast<uint8_t>((argb >> 16) & 0xFF)
                        : (ch == 1) ? static_cast<uint8_t>((argb >> 8) & 0xFF)
                                    : static_cast<uint8_t>(argb & 0xFF);
        if (refVal != portVal)
            ++paletteMismatches;
    }
    long firstPixelMismatch = -1;
    long pixelMismatches = 0;
    for (size_t px = 0; px < fbBytes; ++px) {
        if (ref[768 + px] != fb[px]) {
            if (firstPixelMismatch < 0)
                firstPixelMismatch = static_cast<long>(px);
            ++pixelMismatches;
        }
    }
    if (outPaletteMismatches) *outPaletteMismatches = paletteMismatches;
    if (outPixelMismatches) *outPixelMismatches = pixelMismatches;
    if (outFirstPixelMismatch) *outFirstPixelMismatch = firstPixelMismatch;
    return paletteMismatches == 0 && pixelMismatches == 0;
}

// PORT (wave 25p, per user request): compare in-process against a directory
// of dosbox-x DUMPFRAME captures (frame_NNNNN.raw) and abort with a precise
// diagnostic once it's clear the port has genuinely diverged from the
// original - no external tooling, no post-hoc alignment.
//
// The port is known (this session) to sometimes emit a few EXTRA
// content-changed frames that the original doesn't (the still-open "block/
// row advance" bug) before catching up to the same real content, so a
// strict 1:1 index comparison false-positives on the very first such extra
// frame. Instead this keeps a single reference cursor (s_refIndex) that
// only advances when the CURRENT port frame matches it: an unmatched port
// frame is logged as a tolerated "extra" frame and does not by itself fail
// anything. Only genuine failure to ever reach the next reference frame
// (more than kMaxExtraFrames tolerated extras in a row) aborts - that is
// the actual bug signature, not "port took a couple more steps".
void CompareAgainstReferenceIfChanged(const uint8_t* framebuffer,
                                       const std::array<uint32_t, 256>& palette,
                                       int width, int height)
{
    constexpr int kMaxExtraFrames = 300;

    static bool s_enabled = false;
    static bool s_checked = false;
    static std::string s_dir;
    static int s_refIndex = 0;
    static int s_skipCount = 0;
    static int s_extraFramesSinceLastMatch = 0;
    static int s_totalPortFrames = 0;
    static std::vector<uint8_t> s_lastFb;
    static std::array<uint32_t, 256> s_lastPal{};
    static bool s_havePrev = false;

    if (!s_checked) {
        s_checked = true;
        if (const char* env = std::getenv("REORION2_COMPARE_DIR")) {
            s_dir = env;
            s_enabled = true;
            if (const char* skipEnv = std::getenv("REORION2_COMPARE_SKIP"))
                s_skipCount = std::atoi(skipEnv);
            s_refIndex = s_skipCount; // start matching from the first non-skipped reference
            SDL_Log("Port::Vga: comparing against dosbox reference frames in %s (starting at ref #%d)",
                    s_dir.c_str(), s_refIndex);
        }
    }
    if (!s_enabled)
        return;

    // PORT (wave 25p, per user correction): trigger ONLY on framebuffer
    // (pixel) changes, NOT palette changes, by default. dosbox-x's
    // sub_125814 is specifically the dirty-rect PIXEL blit - it does not
    // fire for a palette-only DAC ramp step (that goes through a completely
    // different VGA-port path in the original with no matching "blit"
    // event). Treating a palette-only change as "a new frame" here was
    // comparing two different kinds of events and made the SIMTEX fade-in
    // (many palette steps, ZERO pixel changes) look like ~116 spurious
    // extra frames that don't exist on a sub_125814-triggered dosbox
    // reference at all.
    //
    // PORT (wave 25r): that reasoning only holds when the dosbox reference
    // was captured via sub_125814. dosbox-x's OWN `DUMPFRAME` ctl command
    // (engine.cpp FrameWatch) has its own independent dedup that fires on
    // EITHER a pixel OR a palette change - so a reference captured that way
    // (e.g. breakpointing sub_132B41 to study a pure palette fade, as in
    // the wave 25p-continuation fade-ramp test) writes one file per genuine
    // palette step even with a static framebuffer. Comparing that against a
    // pixel-only port dedup silently drops nearly all of the port's fade
    // steps (only the very first Present() differs from "no previous
    // frame"), which looks exactly like a slowly growing palette
    // "drift" when diffed index-by-index - a tooling misalignment, not
    // necessarily a bug in sub_132C80 itself. REORION2_DUMP_INCLUDE_PALETTE=1
    // switches this dedup to pixel-OR-palette to match a DUMPFRAME-captured
    // reference; leave it unset when comparing against a sub_125814-style
    // (blit-triggered) reference.
    static bool s_paletteGate = std::getenv("REORION2_DUMP_INCLUDE_PALETTE") != nullptr;
    size_t fbBytes = static_cast<size_t>(width) * height;
    bool pixelChanged = !s_havePrev || s_lastFb.size() != fbBytes ||
                         std::memcmp(s_lastFb.data(), framebuffer, fbBytes) != 0;
    bool paletteChanged = s_paletteGate && (!s_havePrev || s_lastPal != palette);
    bool changed = pixelChanged || paletteChanged;
    if (!changed) {
        s_lastPal = palette; // still track latest palette for the next real blit's comparison
        return;
    }
    s_lastFb.assign(framebuffer, framebuffer + fbBytes);
    s_lastPal = palette;
    s_havePrev = true;
    ++s_totalPortFrames;

    char path[1024];
    std::snprintf(path, sizeof(path), "%s/frame_%05d.raw", s_dir.c_str(), s_refIndex);
    FILE* f = std::fopen(path, "rb");
    if (!f) {
        SDL_Log("Port::Vga: no more reference frames at %s - comparison finished (reached ref #%d, %d port frames total)",
                path, s_refIndex, s_totalPortFrames);
        s_enabled = false;
        return;
    }
    std::vector<uint8_t> ref(768 + fbBytes);
    size_t got = std::fread(ref.data(), 1, ref.size(), f);
    std::fclose(f);
    if (got != ref.size()) {
        SDL_Log("Port::Vga: reference frame %s has wrong size (%zu, expected %zu) - stopping comparison",
                path, got, ref.size());
        s_enabled = false;
        return;
    }

    int paletteMismatches = 0;
    long pixelMismatches = 0, firstPixelMismatch = -1;
    bool matches = FramesRoughlyMatch(ref, framebuffer, palette, fbBytes,
                                       &paletteMismatches, &pixelMismatches, &firstPixelMismatch);
    if (matches) {
        SDL_Log("Port::Vga: port frame #%d MATCHES reference #%d (%d extra port frame(s) before this match).",
                s_totalPortFrames, s_refIndex, s_extraFramesSinceLastMatch);
        ++s_refIndex;
        s_extraFramesSinceLastMatch = 0;
        return;
    }

    ++s_extraFramesSinceLastMatch;
    if (s_extraFramesSinceLastMatch <= kMaxExtraFrames) {
        SDL_Log("Port::Vga: port frame #%d does not match reference #%d yet (%d/%d tolerated extra frame(s)) -"
                " palette_mismatches=%d pixel_mismatches=%ld",
                s_totalPortFrames, s_refIndex, s_extraFramesSinceLastMatch, kMaxExtraFrames,
                paletteMismatches, pixelMismatches);
        return;
    }

    SDL_Log("=== GENUINE DIVERGENCE: port frame #%d never reached reference #%d after %d extra frame(s) ===",
            s_totalPortFrames, s_refIndex, s_extraFramesSinceLastMatch);
    SDL_Log("  reference file: %s", path);
    SDL_Log("  palette channel mismatches: %d/768", paletteMismatches);
    SDL_Log("  pixel mismatches: %ld/%zu (first at x=%ld y=%ld)",
            pixelMismatches, fbBytes,
            firstPixelMismatch < 0 ? -1 : firstPixelMismatch % width,
            firstPixelMismatch < 0 ? -1 : firstPixelMismatch / width);
    SDL_Log("Port::Vga: aborting - see log above.");
    std::fflush(nullptr);
    std::exit(3);
}

void DumpFrameIfRequested(const uint8_t* framebuffer, const std::array<uint32_t, 256>& palette,
                           int width, int height)
{
    static int s_presentCount = 0;
    ++s_presentCount;

    const char* dir = std::getenv("REORION2_DUMP_DIR");
    std::string base = dir ? dir : ".";

    // Batch range mode. PORT (wave 25p, per user feedback): dosbox-x's side
    // of this comparison triggers on sub_125814 - the original's actual
    // "blit changed content to the screen" function, called once per real
    // draw, NOT once per vsync tick. Present() here is called far more
    // often (every vsync/busy-wait iteration), so a raw Present()-call
    // count is NOT the same event and produces a skewed/misaligned
    // comparison. To measure the same thing on both sides, only emit a
    // file when the framebuffer or palette actually CHANGED since the last
    // dump - that is the port's equivalent of "a new frame was drawn".
    static int s_rangeStart = -2, s_rangeCount = 0; // -2 = not yet read
    static std::vector<uint8_t> s_lastFb;
    static std::array<uint32_t, 256> s_lastPal{};
    static bool s_havePrev = false;
    static int s_distinctWritten = 0;
    if (s_rangeStart == -2) {
        s_rangeStart = -1;
        if (const char* env = std::getenv("REORION2_DUMP_FRAME_RANGE")) {
            int start = -1, count = 0;
            if (std::sscanf(env, "%d:%d", &start, &count) == 2 && start > 0 && count > 0) {
                s_rangeStart = start;
                s_rangeCount = count;
            }
        }
    }
    if (s_rangeStart > 0 && s_presentCount >= s_rangeStart && s_distinctWritten < s_rangeCount) {
        // PORT (wave 25p, per user correction; wave 25r: made opt-in via
        // REORION2_DUMP_INCLUDE_PALETTE): pixel-only trigger by default, see
        // the matching comment in CompareAgainstReferenceIfChanged - a
        // palette-only DAC ramp step is not "a new frame" on a sub_125814
        // (blit-triggered) dosbox reference. But dosbox-x's DUMPFRAME ctl
        // command dedups on pixel-OR-palette, so a reference captured that
        // way (e.g. breakpointing sub_132B41 to isolate a fade ramp) needs
        // the same gate here, or the port silently drops ~all fade steps
        // after the first Present() and the resulting index-by-index diff
        // looks like a growing palette drift that isn't really there.
        static bool s_paletteGate = std::getenv("REORION2_DUMP_INCLUDE_PALETTE") != nullptr;
        size_t fbBytes = static_cast<size_t>(width) * height;
        bool pixelChanged = !s_havePrev || s_lastFb.size() != fbBytes ||
                             std::memcmp(s_lastFb.data(), framebuffer, fbBytes) != 0;
        bool paletteChanged = s_paletteGate && (!s_havePrev || s_lastPal != palette);
        bool changed = pixelChanged || paletteChanged;
        if (changed) {
            char name[64];
            std::snprintf(name, sizeof(name), "/frame_%05d.raw", s_distinctWritten);
            DumpRawFrame(base + name, framebuffer, palette, width, height);
            SDL_Log("Port::Vga: batch frame #%d (Present #%d, distinct draw) dumped to %s%s",
                    s_distinctWritten, s_presentCount, base.c_str(), name);
            s_lastFb.assign(framebuffer, framebuffer + fbBytes);
            s_lastPal = palette;
            s_havePrev = true;
            ++s_distinctWritten;
        }
    }

    // Legacy single-shot mode.
    static int s_target = -2; // -2 = not yet read from env
    if (s_target == -2) {
        const char* env = std::getenv("REORION2_DUMP_FRAME");
        s_target = env ? std::atoi(env) : -1;
    }
    if (s_target <= 0 || s_presentCount != s_target)
        return;

    std::string rawPath = base + "/port_frame.raw";
    std::string bmpPath = base + "/port_frame.bmp";

    DumpRawFrame(rawPath, framebuffer, palette, width, height);
    SDL_Log("Port::Vga: frame #%d dumped to %s (palette+%dx%d indices)",
            s_presentCount, rawPath.c_str(), width, height);

    if (FILE* f = std::fopen(bmpPath.c_str(), "wb")) {
        int rowSize = ((width * 3 + 3) / 4) * 4;
        uint32_t pixelDataSize = static_cast<uint32_t>(rowSize) * static_cast<uint32_t>(height);
        uint32_t fileSize = 54 + pixelDataSize;
        uint8_t header[54] = {0};
        header[0] = 'B'; header[1] = 'M';
        std::memcpy(&header[2], &fileSize, 4);
        uint32_t dataOffset = 54;
        std::memcpy(&header[10], &dataOffset, 4);
        uint32_t dibSize = 40;
        std::memcpy(&header[14], &dibSize, 4);
        int32_t w32 = width, h32 = height;
        std::memcpy(&header[18], &w32, 4);
        std::memcpy(&header[22], &h32, 4);
        uint16_t planes = 1, bpp = 24;
        std::memcpy(&header[26], &planes, 2);
        std::memcpy(&header[28], &bpp, 2);
        std::memcpy(&header[34], &pixelDataSize, 4);
        std::fwrite(header, 1, 54, f);

        std::vector<uint8_t> row(static_cast<size_t>(rowSize), 0);
        for (int y = height - 1; y >= 0; --y) { // BMP rows are bottom-up
            for (int x = 0; x < width; ++x) {
                uint32_t argb = palette[framebuffer[static_cast<size_t>(y) * width + x]];
                row[static_cast<size_t>(x) * 3 + 0] = static_cast<uint8_t>(argb & 0xFF);
                row[static_cast<size_t>(x) * 3 + 1] = static_cast<uint8_t>((argb >> 8) & 0xFF);
                row[static_cast<size_t>(x) * 3 + 2] = static_cast<uint8_t>((argb >> 16) & 0xFF);
            }
            std::fwrite(row.data(), 1, static_cast<size_t>(rowSize), f);
        }
        std::fclose(f);
        SDL_Log("Port::Vga: frame #%d dumped to %s", s_presentCount, bmpPath.c_str());
    }
}

uint8_t* EnsureFramebuffer()
{
    if (g_framebuffer)
        return g_framebuffer;
    g_framebuffer = static_cast<uint8_t*>(std::calloc(kFramebufferBytes, 1));
    if (!g_framebuffer) {
        SDL_Log("Port::Vga: calloc framebufferu (%zu B) selhal", kFramebufferBytes);
        return nullptr;
    }
    // Kontrola, ze ukazatel opravdu padne do 32bit (round-trip pres int, ktery
    // dela dekompilovany kod). Pod LAA:NO ma platit vzdy; kdyby ne, hlasime.
    auto asInt = static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(g_framebuffer));
    if (asInt > 0x7FFFFFFFu)
        SDL_Log("Port::Vga: VAROVANI - framebuffer na %p NEsedi do 32bit intu!",
                static_cast<void*>(g_framebuffer));
    return g_framebuffer;
}
} // namespace

uint8_t* Framebuffer()
{
    return EnsureFramebuffer();
}

bool Init()
{
    if (g_initialized)
        return true;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Port::Vga::Init - SDL_Init selhalo: %s", SDL_GetError());
        return false;
    }

    g_window = SDL_CreateWindow("Orion", kModeWidth * 2, kModeHeight * 2, 0);
    if (!g_window) {
        SDL_Log("Port::Vga::Init - SDL_CreateWindow selhalo: %s", SDL_GetError());
        return false;
    }

    g_renderer = SDL_CreateRenderer(g_window, nullptr);
    if (!g_renderer) {
        SDL_Log("Port::Vga::Init - SDL_CreateRenderer selhalo: %s", SDL_GetError());
        return false;
    }

    g_texture = SDL_CreateTexture(g_renderer, SDL_PIXELFORMAT_ARGB8888,
                                   SDL_TEXTUREACCESS_STREAMING, kModeWidth, kModeHeight);
    if (!g_texture) {
        SDL_Log("Port::Vga::Init - SDL_CreateTexture selhalo: %s", SDL_GetError());
        return false;
    }

    EnsureFramebuffer(); // uz mohl byt alokovan drive (sub_1248AB volal Framebuffer())
    g_palette.fill(0xFF000000u); // vychozi cerna, dokud SetPaletteEntry nedorazi

    g_initialized = true;
    return true;
}

void Shutdown()
{
    if (g_texture) {
        SDL_DestroyTexture(g_texture);
        g_texture = nullptr;
    }
    if (g_renderer) {
        SDL_DestroyRenderer(g_renderer);
        g_renderer = nullptr;
    }
    if (g_window) {
        SDL_DestroyWindow(g_window);
        g_window = nullptr;
    }
    if (g_framebuffer) {
        std::free(g_framebuffer);
        g_framebuffer = nullptr;
    }
    g_initialized = false;
}

void SetPixel8(int x, int y, uint8_t colorIndex)
{
    if (x < 0 || x >= kModeWidth || y < 0 || y >= kModeHeight)
        return;
    if (!EnsureFramebuffer())
        return;
    g_framebuffer[static_cast<size_t>(y) * kModeWidth + x] = colorIndex;
}

void SetPaletteEntry(uint8_t index, uint8_t r, uint8_t g, uint8_t b)
{
    g_palette[index] = 0xFF000000u | (static_cast<uint32_t>(r) << 16) |
                        (static_cast<uint32_t>(g) << 8) | b;
}

void Present()
{
    if (!g_initialized || !g_framebuffer)
        return;

    void* pixels = nullptr;
    int pitch = 0;
    if (SDL_LockTexture(g_texture, nullptr, &pixels, &pitch)) {
        for (int y = 0; y < kModeHeight; ++y) {
            auto* row = reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(pixels) + y * pitch);
            for (int x = 0; x < kModeWidth; ++x) {
                row[x] = g_palette[g_framebuffer[static_cast<size_t>(y) * kModeWidth + x]];
            }
        }
        SDL_UnlockTexture(g_texture);
    }

    DumpFrameIfRequested(g_framebuffer, g_palette, kModeWidth, kModeHeight);
    CompareAgainstReferenceIfChanged(g_framebuffer, g_palette, kModeWidth, kModeHeight);

    SDL_RenderClear(g_renderer);
    SDL_RenderTexture(g_renderer, g_texture, nullptr, nullptr);
    SDL_RenderPresent(g_renderer);
}

} // namespace Port::Vga

// ---------------------------------------------------------------------
// C-linkage most pro dekompilovany herni kod (vlna 13).
extern "C" {

// Linearni framebuffer pro dekompilovany kod (mode-5 prezentacni funkce
// kopiruji backbuffer dword_1BB90C -> tento buffer; Present() ho pak
// prevede pres paletu do SDL textury).
unsigned char* PortVga_Framebuffer(void)
{
    return Port::Vga::Framebuffer();
}

// Nahrada za VGA "cekani na vertical retrace" (busy-wait na portu 0x3DA,
// bit 8 - sub_132B27/sub_132B41 v orion_part_20.c). V portu zadny VGA
// port neni (hr_inbyte stub vracel 0 -> druha smycka cekala DONEKONECNA).
// Misto toho se snimek VYKRESLI (Present - vsync je prirozeny okamzik,
// kdy ma byt framebuffer na obrazovce) a kratce se pocka, cimz se herni
// smycka taktuje zhruba na puvodnich ~70 Hz VGA a netoci 100 % CPU.
void PortVga_WaitVsync(void)
{
    Port::Vga::Present();
    SDL_Delay(14); // ~70 Hz VGA refresh
}

// PORT (wave 25r-4): capture the framebuffer AT THE BLIT (game sub_125814),
// which is exactly where dosbox-x's `DUMPFRAME cond=eip:0x349814` samples the
// original. Sampling the port at Present() instead was a measurement
// asymmetry: the port blits ~1400 video frames per intro run (verified 1:1:1
// decode:copy:blit on both sides - original 784/784/784, port 1406/1401/1401)
// but Present() runs on its own cadence, so a Present()-triggered dump only
// ever saw ~113 distinct states and made a correctly-playing cinematic look
// like it was skipping ~98% of its frames. Enabled by REORION2_BLIT_DUMP_DIR;
// same file layout (768B palette + WxH indices) and same content dedup as
// DumpFrameIfRequested, so genCompare/compare_frames can diff the two
// directories directly.
// PORT (wave 25r-6): `backBuffer` must be the game's dword_1BB90C surface, NOT
// the final SDL framebuffer. dosbox-x's `DUMPFRAME ... framebuf=0x452044`
// samples that address, and DUMPMEM on the original proves 0x452044 IS
// dword_1BB904/dword_1BB90C (the back buffer) - the real screen there is
// dword_1BB910[0] = 0xA0000, the VGA window. Sampling g_framebuffer here
// instead compared the fully-composed back buffer against a surface that only
// ever receives the blit's dirty spans, which made undamaged areas keep the
// previous scene's background (255) and looked like a 75-80% pixel mismatch.
void PortVga_CaptureBlit(const void* backBuffer)
{
    static bool s_checked = false;
    static std::string s_dir;
    static int s_written = 0;
    static int s_max = 0;
    static std::vector<uint8_t> s_lastFb;
    static std::array<uint32_t, 256> s_lastPal{};
    static bool s_havePrev = false;

    if (!s_checked) {
        s_checked = true;
        if (const char* env = std::getenv("REORION2_BLIT_DUMP_DIR")) {
            s_dir = env;
            s_max = 600;
            if (const char* cnt = std::getenv("REORION2_BLIT_DUMP_COUNT"))
                s_max = std::atoi(cnt);
            SDL_Log("Port::Vga: blit-triggered dump to %s (max %d frames)", s_dir.c_str(), s_max);
        }
    }
    if (s_dir.empty() || s_written >= s_max)
        return;

    const uint8_t* fb = static_cast<const uint8_t*>(backBuffer);
    if (!fb)
        return;
    const int w = Port::Vga::kModeWidth, h = Port::Vga::kModeHeight;
    size_t fbBytes = static_cast<size_t>(w) * h;
    const std::array<uint32_t, 256>& pal = Port::Vga::g_palette;

    bool changed = !s_havePrev || s_lastFb.size() != fbBytes ||
                   std::memcmp(s_lastFb.data(), fb, fbBytes) != 0 || s_lastPal != pal;
    if (!changed)
        return;

    char name[64];
    std::snprintf(name, sizeof(name), "/frame_%05d.raw", s_written);
    Port::Vga::DumpRawFrame(s_dir + name, fb, pal, w, h);
    s_lastFb.assign(fb, fb + fbBytes);
    s_lastPal = pal;
    s_havePrev = true;
    ++s_written;
}

// PORT (wave 25p): sub_12C2C6 ("wait N BIOS ticks", orion_part_20.c) busy-
// waits by calling PortVga_WaitVsync() every loop iteration to stay
// responsive and keep the window updating while it waits. A BIOS tick is
// ~54.9ms but PortVga_WaitVsync only advances ~14ms per call, so every
// real tick of waiting calls Present()+Delay ~4x more often than needed -
// confirmed via dosbox-x/port frame-dump comparison (genCompare/
// compare_frames.exe): the port produced ~60% frame-to-frame duplicates
// vs the original's ~39%, and took ~3x as many Present() calls to reach
// the same point in the SIMTEX/MICROPROSE intro. Same idea as
// PortVga_WaitVsync (present the current frame, stay responsive) but at a
// coarser ~1-BIOS-tick cadence so a "wait N ticks" call doesn't redraw the
// same still frame 4 times per tick while accumulating real delay.
void PortVga_WaitVsyncSlow(void)
{
    Port::Vga::Present();
    SDL_Delay(50); // ~1 BIOS tick (~54.9ms) - see comment above
}

// Replaces the VGA DAC palette write (game sub_132AF8 wrote a 6-bit index/R/G/B
// stream to ports 0x3C6/0x3C8/0x3C9, which are no-ops in the port). r/g/b are
// already scaled to 8 bits by the caller.
void PortVga_SetPaletteEntry(int index, int r, int g, int b)
{
    Port::Vga::SetPaletteEntry((uint8_t)index, (uint8_t)r, (uint8_t)g, (uint8_t)b);
}

} // extern "C"
