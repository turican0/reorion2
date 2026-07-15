// reorion2.cpp - vstupni bod portu hry Orion (puvodne DOS/real-mode binarka).
//
// Puvodni main() jen volal dekompilovanou funkci main__0 (dnes prejmenovanou
// na GameMain_10057, viz PROGRESS.md - vlna 01). Ted uz sem navic patri
// inicializace portovaci vrstvy (SDL3 okno/terminal/zvuk/mys) v poradi, ktere
// odpovida tomu, jak si to drivejsi DOS program cekal od BIOSu/DOSu: video a
// "textovy" rezim musi byt pripraveny driv, nez GameMain_10057 zacne cokoliv
// vypisovat nebo kreslit.

#include <cstdint>

#include "game/orion_common.h"
#include "port/port_dos.h"
#include "port/port_vga.h"
#include "port/port_sound.h"
#include "port/port_mouse.h"

int main(int argc, char* argv[])
{
    // Terminal/video emulace se musi zapnout uplne prvni - stejne jako driv
    // BIOS pripravil textovy/VGA rezim jeste pred spustenim programu.
    Port::Dos::InitTerminalEmulation();
    Port::Vga::Init();
    Port::Sound::Init();
    Port::Mouse::Init();

    // Predavame puvodni parametry programu i tehdy, kdyz uzivatel nezadal
    // zadny argument (argc je v takovem pripade 1 a argv obsahuje cestu EXE).
    // Treti parametr dekompilovaneho vstupu (a3) neni ve standardnim main
    // dostupny, puvodni volajici (DOS startup kod) do nej pravdepodobne
    // predaval PSP/env blok - zatim nullptr, viz DECOMP_TODO v port_dos.h.
    GameMain_10057(argc, reinterpret_cast<intptr_t>(argv), nullptr);

    // GameMain_10057 je __noreturn (interne kdyz nekonci hru, zavola exit()
    // pres RunGameAndExit_113D47 -> atexit(...)), takze se sem beh nikdy
    // nevrati. Return tu je jen kvuli tvaru signatury main().
    Port::Sound::Shutdown();
    Port::Vga::Shutdown();
    return 0;
}
