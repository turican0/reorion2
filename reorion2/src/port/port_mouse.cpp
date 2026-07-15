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
