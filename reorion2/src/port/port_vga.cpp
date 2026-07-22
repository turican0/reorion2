#include "port_vga.h"

#include <SDL3/SDL.h>
#include <array>
#include <cstdlib>
#include <cstring>

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
