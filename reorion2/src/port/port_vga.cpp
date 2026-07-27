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

void DumpFrameIfRequested(const uint8_t* framebuffer, const std::array<uint32_t, 256>& palette,
                           int width, int height)
{
    static int s_presentCount = 0;
    ++s_presentCount;

    const char* dir = std::getenv("REORION2_DUMP_DIR");
    std::string base = dir ? dir : ".";

    // Batch range mode.
    static int s_rangeStart = -2, s_rangeCount = 0; // -2 = not yet read
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
    if (s_rangeStart > 0 && s_presentCount >= s_rangeStart &&
        s_presentCount < s_rangeStart + s_rangeCount) {
        char name[64];
        std::snprintf(name, sizeof(name), "/frame_%05d.raw", s_presentCount - s_rangeStart);
        DumpRawFrame(base + name, framebuffer, palette, width, height);
        SDL_Log("Port::Vga: batch frame #%d (Present #%d) dumped to %s%s",
                s_presentCount - s_rangeStart, s_presentCount, base.c_str(), name);
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

    if (FILE* f = std::fopen(rawPath.c_str(), "wb")) {
        for (int i = 0; i < 256; ++i) {
            uint32_t argb = palette[static_cast<size_t>(i)];
            uint8_t rgb[3] = { static_cast<uint8_t>((argb >> 16) & 0xFF),
                                static_cast<uint8_t>((argb >> 8) & 0xFF),
                                static_cast<uint8_t>(argb & 0xFF) };
            std::fwrite(rgb, 1, 3, f);
        }
        std::fwrite(framebuffer, 1, static_cast<size_t>(width) * height, f);
        std::fclose(f);
        SDL_Log("Port::Vga: frame #%d dumped to %s (palette+%dx%d indices)",
                s_presentCount, rawPath.c_str(), width, height);
    }

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

// Replaces the VGA DAC palette write (game sub_132AF8 wrote a 6-bit index/R/G/B
// stream to ports 0x3C6/0x3C8/0x3C9, which are no-ops in the port). r/g/b are
// already scaled to 8 bits by the caller.
void PortVga_SetPaletteEntry(int index, int r, int g, int b)
{
    Port::Vga::SetPaletteEntry((uint8_t)index, (uint8_t)r, (uint8_t)g, (uint8_t)b);
}

} // extern "C"
