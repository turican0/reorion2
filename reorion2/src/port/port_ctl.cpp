// port_ctl.cpp - nativni strana srovnavaciho harnessu z genCompare/
// (viz genCompare/DOSBOX_CTL_PROTOCOL.md).  Vlna 112.
//
// Umoznuje spustit dosbox-x i tenhle port se STEJNYM konfiguracnim souborem
// a porovnat vysledne trace soubory. Aktivuje se VYHRADNE pres promennou
// prostredi REORION2_CTL / DOSBOX_CTL_FILE - bez ni se neudela vubec nic,
// aby normalni beh (a regresni brana) zustaly nedotcene.
//
// POZOR NA PORADI INCLUDU (jinak se to prelozi, ale nebude fungovat):
// `orion_common.h` pres `decomp_compat.h` predefinovava fopen/fclose/fread/
// fwrite/fflush/fprintf na PortFile_*. Harness ale potrebuje SKUTECNE CRT -
// zapisuje si vlastni trace soubor a hlasky na stderr, coz herni souborova
// vrstva neumi. Poradi nize je proto zamerne:
//   1. ctl_common.h        - prelozi se driv, nez makra vubec vzniknou
//   2. gen tabulka         - tahne orion_common.h (= makra vzniknou tady)
//   3. #undef tech maker
//   4. native_ctl.h        - zase nad skutecnym CRT

#include <cstdio>
#include <cstdlib>

#include "ctl_common.h"

// Tabulka sledovanych globalu; generuje ji genCompare/gen_watchtable.cpp
// z `orion_common.h`. PREGENEROVAT po kazde zmene hlavicky:
//   gen_watchtable.exe src/game/orion_common.h src/game/
#include "../game/trace_native_symbols.gen.cpp"

// decomp_compat.h makra zpet na skutecne CRT (viz komentar nahore)
#undef fopen
#undef fclose
#undef fread
#undef fwrite
#undef fflush
#undef fprintf

#include "native_ctl.h"

static bool g_ctl_active = false;

extern "C" void PortCtl_Init()
{
    const char* path = std::getenv("REORION2_CTL");
    if (!path)
        path = std::getenv("DOSBOX_CTL_FILE");
    if (!path || !*path)
        return;   // harness vypnuty - normalni beh

    native_ctl_init(path);
    std::atexit(native_ctl_shutdown);   // GameMain_10057 se nikdy nevraci,
                                        // konci pres exit() - proto atexit
    g_ctl_active = true;
    std::fprintf(stderr, "PortCtl: harness zapnut, config = %s (%d sledovanych symbolu)\n",
                 path, g_watch_symbols_count);
}

// Jeden "krok" nativni strany = jeden snimek (Present). Tim se vyhodnocuji
// podminky cycle/every/changed/eq/neq.
// NASTROJ (vlna 114): REORION2_BLOCKWATCH=1 hlida obsah bloku nactenych ze
// savu a hlasi KAZDOU zmenu kontrolniho souctu i s poradim snimku. Odpovida
// na otazku "nacetlo se to spravne a pak to nekdo prepsal?" vs "nacetlo se to
// spravne a spatne se to kresli". Bez te promenne nedela nic - proto to tu
// muze zustat natrvalo.
extern "C" void PortDebug_CrashLog(const char* fmt, ...);

static void PortCtl_BlockWatch()
{
    static int enabled = -1;
    if (enabled < 0) enabled = std::getenv("REORION2_BLOCKWATCH") ? 1 : 0;
    if (!enabled) return;

    struct Blk { const char* name; const void* base; int len; unsigned long last; };
    static Blk blks[] = {
        { "dword_19306C (hvezdy)",   nullptr, 8136,  0 },
        { "dword_192B18 (kolonie)",  nullptr, 90250, 0 },
        { "dword_197F98 (hraci)",    nullptr, 30024, 0 },
        { "dword_1930DC",            nullptr, 3953,  0 },
    };
    static long frame = 0;
    ++frame;
    const void* bases[4] = { (const void *)(intptr_t)dword_19306C,
                             (const void *)(uint8_t*)dword_192B18,
                             (const void *)(uint8_t*)dword_197F98,
                             (const void *)(intptr_t)dword_1930DC };
    for (int i = 0; i < 4; ++i) {
        const unsigned char* p = (const unsigned char *)bases[i];
        if (!p) continue;
        unsigned long s = 0;
        for (int k = 0; k < blks[i].len; ++k) s += p[k];
        if (s != blks[i].last) {
            PortDebug_CrashLog("BLOCKWATCH snimek=%ld  %s  soucet %lu -> %lu",
                               frame, blks[i].name, blks[i].last, s);
            blks[i].last = s;
        }
    }
}

extern "C" void PortCtl_Tick()
{
    PortCtl_BlockWatch();
    if (g_ctl_active)
        native_ctl_tick();
}

// Vstup instrumentovane funkce - pro podminky `call:0xADDR`.
extern "C" void PortCtl_OnCall(unsigned int addr)
{
    if (g_ctl_active)
        native_ctl_on_call(addr);
}
