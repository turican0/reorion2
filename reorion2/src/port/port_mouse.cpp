#include "port_mouse.h"

#include <SDL3/SDL.h>
#include <cstdlib> /* getenv - REORION2_SENDKEY, vlna 58 */
#include <cstdio>  /* sscanf - dtto */

namespace Port::Mouse {

namespace {
State g_state;
bool g_initialized = false;
bool g_keyPending = false;
int  g_keyCode = 0;
bool g_quitRequested = false;
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

    // POZOR (vlna 26 pokr. 31): frontu udalosti je nutne SKUTECNE VYBIRAT.
    // Drive tu bylo jen SDL_PumpEvents(), coz zpravy z fronty neodebira -
    // okno se pak z pohledu Windows stane "neodpovidajicim", prestane
    // dostavat vstup a prekreslovat se. Odtud pravdepodobne i cerna
    // obrazovka po zobrazeni menu a to, ze SDL_GetMouseState vracelo porad
    // 0,0 (namereno: 200+ dotazu hry, vzdy x=0 y=0).
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_EVENT_MOUSE_MOTION:
            g_state.x = (int)e.motion.x;
            g_state.y = (int)e.motion.y;
            break;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
        case SDL_EVENT_MOUSE_BUTTON_UP: {
            const bool down = (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN);
            if (e.button.button == SDL_BUTTON_LEFT)  g_state.leftButton  = down;
            if (e.button.button == SDL_BUTTON_RIGHT) g_state.rightButton = down;
            g_state.x = (int)e.button.x;
            g_state.y = (int)e.button.y;
            break;
        }
        case SDL_EVENT_KEY_DOWN: {
            // Jen SKUTECNA klavesnice. Multimedialni a systemove klavesy
            // (hlasitost, jas, prehravani...) v DOSu pres INT 9 nechodily -
            // uzivatel zmeril, ze pouhe stazeni hlasitosti preskocilo menu.
            // Opakovani (auto-repeat) taky ignorujeme, preruseni by ho
            // hlasilo jako novy stisk az po uvolneni.
            if (e.key.repeat)
                break;
            const SDL_Scancode sc0 = e.key.scancode;
            const bool realKey =
                (sc0 >= SDL_SCANCODE_A && sc0 <= SDL_SCANCODE_0) ||
                sc0 == SDL_SCANCODE_RETURN || sc0 == SDL_SCANCODE_ESCAPE ||
                sc0 == SDL_SCANCODE_BACKSPACE || sc0 == SDL_SCANCODE_TAB ||
                sc0 == SDL_SCANCODE_SPACE ||
                (sc0 >= SDL_SCANCODE_MINUS && sc0 <= SDL_SCANCODE_SLASH) ||
                (sc0 >= SDL_SCANCODE_F1 && sc0 <= SDL_SCANCODE_F12) ||
                (sc0 >= SDL_SCANCODE_HOME && sc0 <= SDL_SCANCODE_UP) ||
                (sc0 >= SDL_SCANCODE_KP_DIVIDE && sc0 <= SDL_SCANCODE_KP_PERIOD);
            if (!realKey)
                break;
            // Kod ve tvaru, v jakem ho ceka herni kruhovy buffer (BIOS styl:
            // horni bajt = scancode, dolni = ASCII). Pro preskoceni intra
            // staci nenulovy, ale v menu uz na konkretni klavese zalezi.
            const int sc = (int)e.key.scancode;
            int ascii = 0;
            const SDL_Keycode kc = e.key.key;
            if (kc >= 32 && kc < 127) ascii = (int)kc;
            else if (kc == SDLK_RETURN) ascii = 13;
            else if (kc == SDLK_ESCAPE) ascii = 27;
            else if (kc == SDLK_BACKSPACE) ascii = 8;
            else if (kc == SDLK_TAB) ascii = 9;
            g_keyCode = ((sc & 0xFF) << 8) | (ascii & 0xFF);
            g_keyPending = true;
            break;
        }
        case SDL_EVENT_QUIT:
            g_quitRequested = true;
            break;
        default:
            break;
        }
    }

    // Doplnkove i primy dotaz - kdyby udalost o pohybu unikla (napr. kurzor
    // vstoupil do okna mimo nas pump), stav se tim srovna.
    float x = 0.0f, y = 0.0f;
    const SDL_MouseButtonFlags buttons = SDL_GetMouseState(&x, &y);
    if (x != 0.0f || y != 0.0f) {
        g_state.x = (int)x;
        g_state.y = (int)y;
    }
    g_state.leftButton  = (buttons & SDL_BUTTON_LMASK) != 0;
    g_state.rightButton = (buttons & SDL_BUTTON_RMASK) != 0;
}

// Presun kurzoru tam, kam si ho hra nastavi pres INT 33h funkci 4.
void WarpTo(int x, int y)
{
    if (!g_initialized)
        return;
    SDL_WarpMouseInWindow(nullptr, (float)x, (float)y);
    g_state.x = x;
    g_state.y = y;
}

// Odebere priznak "prisla nova klavesa" (nastavuje ho Poll z fronty udalosti).
bool ConsumeKeyPress()
{
    const bool had = g_keyPending;
    g_keyPending = false;
    return had;
}

int LastKeyCode()
{
    return g_keyCode;
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
    // PORT (ladeni, vlna 58): REORION2_SENDKEY=<scancode>[:<ms>] vlozi po
    // <ms> od startu (vychozi 6000) JEDNOU umely stisk klavesy, jako by ho
    // ohlasilo preruseni. Obdoba prikazu SENDKEY v dosbox-x z vlny 53 -
    // synteticky vstup pres SetCursorPos/mouse_event se do SDL okna
    // nedostane, takze bez tohohle nejde projit menu automatizovane.
    // Zkratky hlavniho menu (sub_816F2, porovnava ASCII v `v7`):
    //   'C' 67 continue, 'N' 78 new game, 'L' 76 load, 'M' 77 multiplayer,
    //   'H' 72 hall of fame, 'Q' 81 quit.
    {
        static int s_code = -1;
        static unsigned s_atMs = 6000;
        static bool s_done = false;
        if (s_code == -1) {
            s_code = 0;
            if (const char* e = std::getenv("REORION2_SENDKEY")) {
                int c = 0, ms = 6000;
                // %i => prijme i hex ("0x2348"). Kod klavesy ma stejny tvar
                // jako z realneho stisku: (scancode << 8) | ascii, tedy napr.
                // 'H' = 0x2348, 'N' = 0x314E, 'Q' = 0x1051.
                if (std::sscanf(e, "%i:%d", &c, &ms) >= 1 && c > 0) {
                    s_code = c;
                    s_atMs = (unsigned)ms;
                }
            }
        }
        if (s_code) {
            static int s_seen = 0;
            if (s_seen < 3) { ++s_seen; SDL_Log("Port: PollKeyPress volano, t=%llu ms",
                                                (unsigned long long)SDL_GetTicks()); }
        }
        if (s_code && !s_done && SDL_GetTicks() >= (Uint64)s_atMs) {
            s_done = true;
            SDL_Log("Port: REORION2_SENDKEY vklada kod %d", s_code);
            return s_code;
        }
    }
    // Bere se ze stejne fronty udalosti jako my� (viz Poll vyse) - hranou,
    // tedy jen pri NOVEM stisku, stejne jako by prislo preruseni INT 9.
    Port::Mouse::Poll();
    if (!Port::Mouse::ConsumeKeyPress())
        return 0;
    const int code = Port::Mouse::LastKeyCode();
    return code ? code : 0x3900; // kdyz se kod nepodarilo urcit, mezernik
}

