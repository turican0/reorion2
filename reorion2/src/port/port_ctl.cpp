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
extern "C" void PortCtl_Tick()
{
    if (g_ctl_active)
        native_ctl_tick();
}

// Vstup instrumentovane funkce - pro podminky `call:0xADDR`.
extern "C" void PortCtl_OnCall(unsigned int addr)
{
    if (g_ctl_active)
        native_ctl_on_call(addr);
}
