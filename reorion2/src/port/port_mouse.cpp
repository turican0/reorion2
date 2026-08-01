#include "port_mouse.h"

#include <SDL3/SDL.h>

namespace Port::Mouse {

namespace {
State g_state;
bool g_initialized = false;
} // namespace

bool Init()
{
    // SDL_INIT_VIDEO uz je typicky spusteno pres Port::Vga::Init(), ktere se
    // vola pred nami - SDL_Init je idempotentni, takze staci pripojit se.
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Port::Mouse::Init - SDL_Init selhalo: %s", SDL_GetError());
        return false;
    }
    g_initialized = true;
    return true;
}

void Shutdown()
{
    g_initialized = false;
}

void Poll()
{
    if (!g_initialized)
        return;

    // POZOR (vlna 26 pokr. 28): bez SDL_PumpEvents() se vnitrni stav SDL
    // nikdy neaktualizuje, takze SDL_GetMouseState vraci porad totez a
    // klavesnice se necte vubec. Byl to spolecny duvod, proc slo intro
    // preskocit ani mysi, ani klavesou.
    SDL_PumpEvents();

    float x = 0.0f, y = 0.0f;
    SDL_MouseButtonFlags buttons = SDL_GetMouseState(&x, &y);
    g_state.x = static_cast<int>(x);
    g_state.y = static_cast<int>(y);
    g_state.leftButton = (buttons & SDL_BUTTON_LMASK) != 0;
    g_state.rightButton = (buttons & SDL_BUTTON_RMASK) != 0;
}

const State& GetState()
{
    return g_state;
}

} // namespace Port::Mouse

// ---------------------------------------------------------------------
// Nahrada za INT 9 (klavesnicova obsluha). Hra si ji zavesuje v
// InstallKeyboardIsr_12C420 a v portu je to prazdna zaslepka
// (KeyboardIsr_12C4D8), takze `byte_1BC2E4` nikdy nezmenilo hodnotu a
// `sub_12C392` ("je pripravena klavesa?") vracelo vzdy 0 - proto se
// intro nedalo preskocit. Tady se ta informace ziskava ze SDL a hlasi se
// HRANOU (jen pri novem stisku), stejne jako by to udelalo preruseni.
extern "C" int PortInput_PollKeyPress(void)
{
    SDL_PumpEvents();
    int numKeys = 0;
    const bool* keys = SDL_GetKeyboardState(&numKeys);
    if (!keys)
        return 0;

    bool anyDown = false;
    for (int i = 0; i < numKeys; ++i) {
        if (keys[i]) { anyDown = true; break; }
    }

    static bool s_wasDown = false;
    const bool pressed = anyDown && !s_wasDown;
    s_wasDown = anyDown;
    return pressed ? 1 : 0;
}
