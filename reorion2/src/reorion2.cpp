// reorion2.cpp - vstupni bod portu hry Orion (puvodne DOS/real-mode binarka).
//
// Puvodni main() jen volal dekompilovanou funkci main__0 (dnes prejmenovanou
// na GameMain_10057, viz PROGRESS.md - vlna 01). Ted uz sem navic patri
// inicializace portovaci vrstvy (SDL3 okno/terminal/zvuk/mys) v poradi, ktere
// odpovida tomu, jak si to drivejsi DOS program cekal od BIOSu/DOSu: video a
// "textovy" rezim musi byt pripraveny driv, nez GameMain_10057 zacne cokoliv
// vypisovat nebo kreslit.

#include <cstdint>
#include <cstdio>
#include <windows.h>

// DEBUG (temporary, wave-23 x64 bisection): print the faulting instruction/address
// when an unhandled SEH exception occurs, since the default CRT abort() path gives
// no diagnostic info at all. Defined before including orion_common.h so the
// project's decomp_compat.h macros (fflush/fprintf -> PortFile_*, __stdcall -> "")
// don't clobber this plain Win32 code.
static LONG __stdcall DebugVectoredHandler(EXCEPTION_POINTERS* ep)
{
    DWORD code = ep->ExceptionRecord->ExceptionCode;
    if (code == EXCEPTION_ACCESS_VIOLATION || code == EXCEPTION_STACK_OVERFLOW ||
        code == EXCEPTION_ILLEGAL_INSTRUCTION || code == EXCEPTION_INT_DIVIDE_BY_ZERO)
    {
        std::fprintf(stderr, "SEH code=0x%08lX addr=%p", code, ep->ExceptionRecord->ExceptionAddress);
        if (code == EXCEPTION_ACCESS_VIOLATION && ep->ExceptionRecord->NumberParameters >= 2)
        {
            std::fprintf(stderr, " av_%s=0x%p",
                ep->ExceptionRecord->ExceptionInformation[0] ? "write" : "read",
                (void*)ep->ExceptionRecord->ExceptionInformation[1]);
        }
        HMODULE mod = nullptr;
        if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                                (LPCSTR)ep->ExceptionRecord->ExceptionAddress, &mod))
        {
            char path[MAX_PATH] = {0};
            GetModuleFileNameA(mod, path, MAX_PATH);
            std::fprintf(stderr, " module=%s base=%p rva=0x%zx", path, (void*)mod,
                (size_t)((char*)ep->ExceptionRecord->ExceptionAddress - (char*)mod));
        }
        std::fprintf(stderr, "\n");
        std::fflush(stderr);
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

#include "game/orion_common.h"
#include "port/port_dos.h"
#include "port/port_vga.h"
#include "port/port_sound.h"
#include "port/port_mouse.h"
#include "port/port_memory.h"

int main(int argc, char* argv[])
{
    AddVectoredExceptionHandler(1, DebugVectoredHandler);
    // Evidence alokaci zapnout uplne prvni, aby zachytila i pripadne
    // alokace, ktere si udelaji Init() funkce port vrstvy nize.
    Port::Memory::Init();

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
    Port::Memory::Shutdown();
    return 0;
}
