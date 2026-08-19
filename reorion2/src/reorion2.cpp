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
#include <cstdlib>
#include <windows.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")

// DEBUG (temporary, wave-23 x64 bisection): print the faulting instruction/address
// when an unhandled SEH exception occurs, since the default CRT abort() path gives
// no diagnostic info at all. Defined before including orion_common.h so the
// project's decomp_compat.h macros (fflush/fprintf -> PortFile_*, __stdcall -> "")
// don't clobber this plain Win32 code.
/* vlna 92: dopredna deklarace - definice je az na konci souboru. */
extern "C" void PortDebug_Symbolize(const char* tag, void* addr);
extern "C" void PortDebug_CrashLog(const char* fmt, ...);
extern "C" void PortDebug_Backtrace(const char* tag, int frames);
extern "C" void PortCtl_Init();   /* vlna 112: srovnavaci harness (port_ctl.cpp) */

static LONG __stdcall DebugVectoredHandler(EXCEPTION_POINTERS* ep)
{
    // PORT (vlna 92): POJISTKA PROTI ZACYKLENI. Vectored handler bezi na
    // KAZDOU vyjimku vcetne te, kterou zpusobi sam (StackWalk64 nad
    // rozbitym zasobnikem cte mimo). Bez tehle zavory se do stderr valily
    // tisice radku `av_read=0xFFFFFFFFFFFFFFFF` a PRVNI - jediny zajimavy -
    // vypis se v nich ztratil (zmereno pri padu na obrazovce kolonie).
    static volatile LONG s_inHandler = 0;
    if (InterlockedCompareExchange(&s_inHandler, 1, 0) != 0)
        return EXCEPTION_CONTINUE_SEARCH;
    struct HandlerGuard { volatile LONG* f; ~HandlerGuard() { InterlockedExchange((LONG*)f, 0); } } guard{ &s_inHandler };

    DWORD code = ep->ExceptionRecord->ExceptionCode;
    if (code == EXCEPTION_ACCESS_VIOLATION || code == EXCEPTION_STACK_OVERFLOW ||
        code == EXCEPTION_ILLEGAL_INSTRUCTION || code == EXCEPTION_INT_DIVIDE_BY_ZERO)
    {
        std::fprintf(stderr, "SEH code=0x%08lX addr=%p", code, ep->ExceptionRecord->ExceptionAddress);
        if (code == EXCEPTION_ACCESS_VIOLATION && ep->ExceptionRecord->NumberParameters >= 2)
        {
            // ExceptionInformation[0]: 0 = cteni, 1 = zapis, 8 = DEP/spusteni.
            // Puvodne se tu vsechno nenulove tisklo jako "write", takze skok
            // pres rozbity funkcni ukazatel vypadal jako zapis - matouci.
            ULONG_PTR kind = ep->ExceptionRecord->ExceptionInformation[0];
            const char* kindName = kind == 0 ? "read" : (kind == 1 ? "write" : "execute");
            std::fprintf(stderr, " av_%s(info0=%zu)=0x%p", kindName, (size_t)kind,
                (void*)ep->ExceptionRecord->ExceptionInformation[1]);
        }
        // PORT (vlna 92): modul + RVA se tisknou HNED. Drive se vypisovaly
        // az za rozvinutim zasobniku, takze kdyz to rozvinuti spadlo,
        // zbyla jen absolutni adresa - a ta je pri ASLR k nicemu.
        {
            HMODULE m0 = nullptr;
            if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                                   (LPCSTR)ep->ExceptionRecord->ExceptionAddress, &m0) && m0)
            {
                char p0[MAX_PATH] = {0};
                GetModuleFileNameA(m0, p0, MAX_PATH);
                std::fprintf(stderr, " module=%s base=%p rva=0x%zx\n", p0, (void*)m0,
                    (size_t)((char*)ep->ExceptionRecord->ExceptionAddress - (char*)m0));
                std::fflush(stderr);
                PortDebug_CrashLog("SEH code=0x%08lX addr=%p rva=0x%zx modul=%s", code,
                    ep->ExceptionRecord->ExceptionAddress,
                    (size_t)((char*)ep->ExceptionRecord->ExceptionAddress - (char*)m0), p0);
            }
            // a rovnou i jmeno funkce + radek (PortDebug_Symbolize umi obe).
            PortDebug_Symbolize("SEH.rip", (void*)ep->ExceptionRecord->ExceptionAddress);
        }
#if !defined(_M_IX86)
        // Kdyz RIP neni v zadnem modulu, StackWalk64 nema podle ceho rozvinout
        // ramec a vypis konci hned. Skok pres rozbity ukazatel ale nechava
        // navratovou adresu na vrcholu zasobniku - vypiseme prvnich par
        // qwordu, ktere lezi v nejakem modulu, at je videt volajici.
        HMODULE faultMod = nullptr;
        if (!GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                                (LPCSTR)ep->ExceptionRecord->ExceptionAddress, &faultMod))
        {
            const ULONG_PTR* sp = (const ULONG_PTR*)ep->ContextRecord->Rsp;
            for (int i = 0, shown = 0; i < 24 && shown < 6; ++i)
            {
                HMODULE m = nullptr;
                if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                                       (LPCSTR)sp[i], &m) && m)
                {
                    char p[MAX_PATH] = {0};
                    GetModuleFileNameA(m, p, MAX_PATH);
                    std::fprintf(stderr, "  stack[%d] = %p  %s+0x%zx\n", i, (void*)sp[i], p,
                                 (size_t)((char*)sp[i] - (char*)m));
                    ++shown;
                }
            }
        }
#endif
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

        // PORT (wave 24e): print the call stack so an AV inside a CRT/system
        // DLL (e.g. memcpy called with a garbage pointer/size) can still be
        // traced back to the game-code call site that triggered it - without
        // this, "module=vcruntime140d.dll" alone gives no way to find the bug.
        SymSetOptions(SYMOPT_LOAD_LINES | SYMOPT_UNDNAME);
        HANDLE process = GetCurrentProcess();
        // PORT (vlna 101): SymInitialize VRACI FALSE, kdyz uz je pro proces
        // inicializovano - a to od vlny 92 je, protoze PortDebug_Symbolize se
        // vola o par radku vys. Podminka tim cely vypis zasobniku umlcela,
        // takze u padu v CRT (memcpy) nebylo videt, kdo ho zavolal.
        SymInitialize(process, nullptr, TRUE);
        {
            STACKFRAME64 frame = {};
            DWORD machine = IMAGE_FILE_MACHINE_AMD64;
#if defined(_M_IX86)
            machine = IMAGE_FILE_MACHINE_I386;
            frame.AddrPC.Offset = ep->ContextRecord->Eip;
            frame.AddrFrame.Offset = ep->ContextRecord->Ebp;
            frame.AddrStack.Offset = ep->ContextRecord->Esp;
#else
            frame.AddrPC.Offset = ep->ContextRecord->Rip;
            frame.AddrFrame.Offset = ep->ContextRecord->Rbp;
            frame.AddrStack.Offset = ep->ContextRecord->Rsp;
#endif
            frame.AddrPC.Mode = AddrModeFlat;
            frame.AddrFrame.Mode = AddrModeFlat;
            frame.AddrStack.Mode = AddrModeFlat;

            CONTEXT ctx = *ep->ContextRecord;
            for (int i = 0; i < 32; ++i)
            {
                if (!StackWalk64(machine, process, GetCurrentThread(), &frame, &ctx,
                                  nullptr, SymFunctionTableAccess64, SymGetModuleBase64, nullptr))
                    break;
                if (frame.AddrPC.Offset == 0)
                    break;

                char symBuf[sizeof(SYMBOL_INFO) + 256] = {0};
                SYMBOL_INFO* sym = (SYMBOL_INFO*)symBuf;
                sym->SizeOfStruct = sizeof(SYMBOL_INFO);
                sym->MaxNameLen = 256;
                DWORD64 displacement = 0;
                // PORT (vlna 89): doplneno CISLO RADKU. SYMOPT_LOAD_LINES uz je
                // nastaveno vys, ale vypis ho nepouzival, takze se z padu dal
                // vycist jen offset typu "sub_11B05A+0xb11" a radek se musel
                // dohledavat rucne (nebo cekat, az uzivatel posle screenshot
                // z debuggeru). Hlidac (REORION2_WATCHDOG) to umi uz od vlny 84,
                // tady to chybelo.
                IMAGEHLP_LINE64 line = {};
                line.SizeOfStruct = sizeof(line);
                DWORD lineDisp = 0;
                if (SymFromAddr(process, frame.AddrPC.Offset, &displacement, sym))
                {
                    if (SymGetLineFromAddr64(process, frame.AddrPC.Offset, &lineDisp, &line))
                        std::fprintf(stderr, "  #%d %p %s+0x%llx  (%s:%lu)\n", i,
                                     (void*)frame.AddrPC.Offset, sym->Name,
                                     (unsigned long long)displacement,
                                     line.FileName, (unsigned long)line.LineNumber);
                    else
                        std::fprintf(stderr, "  #%d %p %s+0x%llx\n", i, (void*)frame.AddrPC.Offset,
                                     sym->Name, (unsigned long long)displacement);
                }
                else
                    std::fprintf(stderr, "  #%d %p ?\n", i, (void*)frame.AddrPC.Offset);
            }
            SymCleanup(process);
        }
        std::fflush(stderr);
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

// ---------------------------------------------------------------------
// HLIDAC ZAMRZNUTI (vlna 26 pokr. 35)
// Kdyz se delsi dobu nezavola Present(), hra uvizla ve smycce a okno
// prestane odpovidat - z logu se pak nepozna KDE. Na stroji neni cdb ani
// windbg, ale dbghelp uz linkujeme kvuli SEH vypisu, takze si zasobnik
// hlavniho vlakna rozvineme sami: pozastavime ho, precteme kontext a
// vypiseme ramce. Presne to, co by ukazal debugger.
// Zapina REORION2_WATCHDOG=<sekundy>.
static HANDLE g_mainThread = nullptr;
static volatile LONG64 g_lastPresentTick = 0;

extern "C" void PortWatchdog_Ping(void)
{
    InterlockedExchange64(&g_lastPresentTick, (LONG64)GetTickCount64());
}

static DWORD WINAPI WatchdogProc(LPVOID param)
{
    const DWORD timeoutMs = (DWORD)(uintptr_t)param;
    bool reported = false;
    for (;;) {
        Sleep(500);
        const LONG64 last = InterlockedCompareExchange64(&g_lastPresentTick, 0, 0);
        if (last == 0)
            continue;
        const ULONGLONG now = GetTickCount64();
        if ((ULONGLONG)(now - (ULONGLONG)last) < timeoutMs) { reported = false; continue; }
        if (reported)
            continue;
        reported = true;

        std::fprintf(stderr, "\n=== HLIDAC: zadny Present uz %llu ms - zasobnik hlavniho vlakna ===\n",
                     (unsigned long long)(now - (ULONGLONG)last));
        if (SuspendThread(g_mainThread) == (DWORD)-1) {
            std::fprintf(stderr, "HLIDAC: nelze pozastavit hlavni vlakno\n");
            continue;
        }
        CONTEXT ctx = {};
        ctx.ContextFlags = CONTEXT_FULL;
        if (GetThreadContext(g_mainThread, &ctx)) {
            SymSetOptions(SYMOPT_LOAD_LINES | SYMOPT_UNDNAME);
            HANDLE proc = GetCurrentProcess();
            SymInitialize(proc, nullptr, TRUE);
            STACKFRAME64 f = {};
            f.AddrPC.Offset = ctx.Rip;    f.AddrPC.Mode = AddrModeFlat;
            f.AddrFrame.Offset = ctx.Rbp; f.AddrFrame.Mode = AddrModeFlat;
            f.AddrStack.Offset = ctx.Rsp; f.AddrStack.Mode = AddrModeFlat;
            for (int i = 0; i < 20; ++i) {
                if (!StackWalk64(IMAGE_FILE_MACHINE_AMD64, proc, g_mainThread, &f, &ctx,
                                 nullptr, SymFunctionTableAccess64, SymGetModuleBase64, nullptr))
                    break;
                if (!f.AddrPC.Offset)
                    break;
                unsigned char buf[sizeof(SYMBOL_INFO) + 256] = {0};
                auto* sym = reinterpret_cast<SYMBOL_INFO*>(buf);
                sym->SizeOfStruct = sizeof(SYMBOL_INFO);
                sym->MaxNameLen = 255;
                DWORD64 disp = 0;
                IMAGEHLP_LINE64 line = {}; line.SizeOfStruct = sizeof(line);
                DWORD lineDisp = 0;
                if (SymFromAddr(proc, f.AddrPC.Offset, &disp, sym)) {
                    if (SymGetLineFromAddr64(proc, f.AddrPC.Offset, &lineDisp, &line))
                        std::fprintf(stderr, "  #%d %s+0x%llx  (%s:%lu)\n", i, sym->Name,
                                     (unsigned long long)disp, line.FileName, line.LineNumber);
                    else
                        std::fprintf(stderr, "  #%d %s+0x%llx\n", i, sym->Name,
                                     (unsigned long long)disp);
                } else {
                    std::fprintf(stderr, "  #%d %p\n", i, (void*)f.AddrPC.Offset);
                }
            }
        }
        ResumeThread(g_mainThread);
        std::fflush(stderr);
    }
    return 0;
}

static void StartWatchdog()
{
    const char* env = getenv("REORION2_WATCHDOG");
    if (!env)
        return;
    int seconds = atoi(env);
    if (seconds <= 0)
        seconds = 5;
    DuplicateHandle(GetCurrentProcess(), GetCurrentThread(),
                    GetCurrentProcess(), &g_mainThread, 0, FALSE, DUPLICATE_SAME_ACCESS);
    PortWatchdog_Ping();
    CreateThread(nullptr, 0, WatchdogProc, (LPVOID)(uintptr_t)(seconds * 1000), 0, nullptr);
    std::fprintf(stderr, "HLIDAC zapnut, prah %d s\n", seconds);
}


// Prelozi adresu na jmeno funkce + radek (vlna 26 pokr. 37). Pouziva se z
// dekompilovaneho kodu k identifikaci volajiciho pres _ReturnAddress().
// PORT (vlna 103): vypis N ramcu zasobniku z MISTA VOLANI v hernim kodu.
// `PortDebug_Symbolize(_ReturnAddress())` rekne jen primeho volajiciho; kdyz je
// chyba o dva-tri ramce vys (typicky u obecnych kreslicich funkci jako
// sub_12A478, kterou vola pul hry), je potreba videt cely retez.
extern "C" void PortDebug_Backtrace(const char* tag, int frames)
{
    static bool btInited = false;
    HANDLE proc = GetCurrentProcess();
    if (!btInited) { SymSetOptions(SYMOPT_LOAD_LINES | SYMOPT_UNDNAME); SymInitialize(proc, nullptr, TRUE); btInited = true; }
    if (frames <= 0 || frames > 24) frames = 8;
    void* stack[24] = {0};
    USHORT got = CaptureStackBackTrace(1, (ULONG)frames, stack, nullptr);
    unsigned char btbuf[sizeof(SYMBOL_INFO) + 256] = {0};
    SYMBOL_INFO* sym = reinterpret_cast<SYMBOL_INFO*>(btbuf);
    sym->SizeOfStruct = sizeof(SYMBOL_INFO);
    sym->MaxNameLen = 255;
    for (USHORT i = 0; i < got; ++i) {
        DWORD64 disp = 0;
        IMAGEHLP_LINE64 line = {}; line.SizeOfStruct = sizeof(line);
        DWORD ld = 0;
        if (SymFromAddr(proc, (DWORD64)stack[i], &disp, sym)) {
            if (SymGetLineFromAddr64(proc, (DWORD64)stack[i], &ld, &line))
                std::fprintf(stderr, "BT %s #%u %s+0x%llx  (%s:%lu)\n", tag, i, sym->Name,
                             (unsigned long long)disp, line.FileName, line.LineNumber);
            else
                std::fprintf(stderr, "BT %s #%u %s+0x%llx\n", tag, i, sym->Name,
                             (unsigned long long)disp);
        } else {
            std::fprintf(stderr, "BT %s #%u %p\n", tag, i, stack[i]);
        }
    }
    std::fflush(stderr);
}

extern "C" void PortDebug_Symbolize(const char* tag, void* addr)
{
    static bool inited = false;
    HANDLE proc = GetCurrentProcess();
    if (!inited) { SymSetOptions(SYMOPT_LOAD_LINES | SYMOPT_UNDNAME); SymInitialize(proc, nullptr, TRUE); inited = true; }
    unsigned char buf[sizeof(SYMBOL_INFO) + 256] = {0};
    auto* sym = reinterpret_cast<SYMBOL_INFO*>(buf);
    sym->SizeOfStruct = sizeof(SYMBOL_INFO);
    sym->MaxNameLen = 255;
    DWORD64 disp = 0;
    IMAGEHLP_LINE64 line = {}; line.SizeOfStruct = sizeof(line);
    DWORD ld = 0;
    if (SymFromAddr(proc, (DWORD64)addr, &disp, sym)) {
        if (SymGetLineFromAddr64(proc, (DWORD64)addr, &ld, &line))
            std::fprintf(stderr, "SYMBOL %s = %s+0x%llx  (%s:%lu)\n", tag, sym->Name,
                         (unsigned long long)disp, line.FileName, line.LineNumber);
        else
            std::fprintf(stderr, "SYMBOL %s = %s+0x%llx\n", tag, sym->Name, (unsigned long long)disp);
    } else {
        std::fprintf(stderr, "SYMBOL %s = %p (nezname)\n", tag, addr);
    }
    std::fflush(stderr);
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
    // PORT (vlna 95): ZMERENO jednorazovou sondou (uz odstranena):
    //   zasobnik = 0x00000000004FFBF0, kod = 0x0000000000753014
    // Obe adresy jsou hluboko pod 2 GB (ImageBase 0x400000 + ASLR jen v ramci
    // nizkych 4 GB, HIGH_ENTROPY_VA je vypnute), takze `(int)&lokalka` ani
    // `(int)funkce` v dekompilatu nic neorezavaji. To je duvod, proc port
    // vubec bezi - a zaroven proc chyby typu "int misto ukazatele" boli az
    // ve VARARGS (viz vlna 93), kde jde o sirku slotu, ne o velikost adresy.
    // Evidence alokaci zapnout uplne prvni, aby zachytila i pripadne
    // alokace, ktere si udelaji Init() funkce port vrstvy nize.
    Port::Memory::Init();

    // Terminal/video emulace se musi zapnout uplne prvni - stejne jako driv
    // BIOS pripravil textovy/VGA rezim jeste pred spustenim programu.
    Port::Dos::InitTerminalEmulation();
    Port::Vga::Init();
    Port::Sound::Init();
    Port::Mouse::Init();
    StartWatchdog();

    // vlna 112: nativni strana srovnavaciho harnessu (genCompare/).
    // Aktivuje se jen kdyz je nastaveno REORION2_CTL / DOSBOX_CTL_FILE.
    PortCtl_Init();

    // Predavame puvodni parametry programu i tehdy, kdyz uzivatel nezadal
    // zadny argument (argc je v takovem pripade 1 a argv obsahuje cestu EXE).
    // Treti parametr dekompilovaneho vstupu (a3) neni ve standardnim main
    // dostupny, puvodni volajici (DOS startup kod) do nej pravdepodobne
    // predaval PSP/env blok - zatim nullptr, viz DECOMP_TODO v port_dos.h.
    GameMain_10057(argc, argv, nullptr);

    // GameMain_10057 je (interne kdyz nekonci hru, zavola exit()
    // pres RunGameAndExit_113D47 -> atexit(...)), takze se sem beh nikdy
    // nevrati. Return tu je jen kvuli tvaru signatury main().
    Port::Sound::Shutdown();
    Port::Vga::Shutdown();
    Port::Memory::Shutdown();
    return 0;
}
