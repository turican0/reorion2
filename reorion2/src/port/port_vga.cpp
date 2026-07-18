#include "port_vga.h"

#include <SDL3/SDL.h>
#include <array>
#include <cstring>

namespace Port::Vga {

namespace {
constexpr int kModeWidth = 320;
constexpr int kModeHeight = 200;

SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
SDL_Texture* g_texture = nullptr;

// Vlastni 8bpp framebuffer + 256barevna paleta - stejny model dat, jaky mel
// puvodni VGA rezim 13h (segment A000, 1 byte na pixel + samostatny DAC).
std::array<uint8_t, kModeWidth * kModeHeight> g_framebuffer{};
std::array<uint32_t, 256> g_palette{}; // ulozeno uz jako ARGB8888 pro SDL

bool g_initialized = false;
} // namespace

bool Init()
{
    if (g_initialized)
        return true;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Port::Vga::Init - SDL_Init selhalo: %s", SDL_GetError());
        return false;
    }

    g_window = SDL_CreateWindow("Orion", kModeWidth * 3, kModeHeight * 3, 0);
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

    g_framebuffer.fill(0);
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
    g_initialized = false;
}

void SetPixel8(int x, int y, uint8_t colorIndex)
{
    if (x < 0 || x >= kModeWidth || y < 0 || y >= kModeHeight)
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
    if (!g_initialized)
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

} // extern "C"
