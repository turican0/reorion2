/*
 * Link-time placeholders for dependencies missing from the Hex-Rays dump.
 * They make the project linkable; they do not implement the original DOS/Watcom runtime.
 */
#include <stddef.h> /* size_t - potreba pro PortMemory_* deklarace nize (vlna 06) */
#include <string.h> /* memcpy - realny qmemcpy, wave 20 */
#include <SDL3/SDL.h> /* SDL_GetTicks - realny AIL_ms_count nahrada, viz sub_149B10/149B30 nize (vlna 25) */

int __CS__;
int __DS__;
int __ES__;
int __FS__;
int __GS__;
/* PORT (vlna 58): __PAIR32__/__PAIR64__ presunuty do decomp_compat.h jako
   skutecna makra. __PAIR64__ tu byl DATOVY symbol, takze 15 jeho "volani"
   skakalo do .bss - viz komentar u maker a PROGRESS.md vlna 58. */
/* PORT (wave 25q): these were `return 0;` no-op stubs - and the decompiled
   code calls __ROR4__ 219 times and __ROL4__ once, so EVERY 32-bit rotate in
   the whole dump silently evaluated to zero. Same class as the memset32 no-op
   stub found in wave 22k ("the root of the garbage graphics"). defs.h only
   ever defines __ROL4__/__ROR4__ for a C++ build; the game translation units
   are compiled as C (/TC), where the calls fell back to an implicit
   `int __ROL4__()` declaration and linked against these stubs - so nothing
   warned about it. Real implementations below (x86 `rol`/`ror` semantics:
   the shift count is taken modulo 32). */
unsigned int __ROL4__(unsigned int value, int count)
{
    unsigned int n = (unsigned int)count & 31u;
    return n ? ((value << n) | (value >> (32 - n))) : value;
}

unsigned int __ROR4__(unsigned int value, int count)
{
    unsigned int n = (unsigned int)count & 31u;
    return n ? ((value >> n) | (value << (32 - n))) : value;
}
int __SET_PAIR__(void) { return 0; }
int __SS__;
int _CF;
int _DOS4G_hook_fini(void) { return 0; }
int _DOS4G_hook_init(void) { return 0; }
int _EBP;
int _Ergo_hook_fini(void) { return 0; }
int _Ergo_hook_init(void) { return 0; }
int _FDFS(void) { return 0; }
int _Intel_hook_fini(void) { return 0; }
int _Intel_hook_init(void) { return 0; }
int _no_support_loaded;
int _Phar_hook_fini(void) { return 0; }
int _Phar_hook_init(void) { return 0; }
int _SF;
int _terminate;
int _wcpp_1_unwind_leave(void) { return 0; }
int _ZF;
/* PORT (vlna 58): abs16/abs32 jsou ted skutecne funkce v decomp_compat.h.
   Jako pahyly vracely 0, takze 81 porovnani vzdalenosti/rozdilu v cele hre
   pocitalo s nulou (napr. reset rolovani titulku v sub_81147). */
int byte_190488;
int byte_192E80;
int byte_192ECC;
int byte_199A66;
int byte_199A67;
int byte_199A6C;
int byte_199A6D;
int byte_199BA2;
int byte_199EC2;
int byte_19A0D8;
int byte_19ABA4;
int byte_19ABA5;
int byte_19ABA6;
int byte_19ACF7;
int byte_19B11B;
int byte_19B544;
/* vlna 73: byte_19B688 je ted 8bajtove pole v orion_data.c */
int byte_19C120;
int byte_19C148;
/* vlna 119: duplicitni skalar odstranen - pole je v orion_data.c */
/* vlna 58: byte_19C6EE je ted makro do bloku hofBlock_19C5FC - tenhle
   pahyl uz nic nealiasoval a jen mrtve zabiral symbol. */
int byte_19C714;
int byte_19DECA;
int byte_19DECD;
int byte_19E57C;
int byte_19E57D;
int byte_19E57E;
int byte_19E57F;
int byte_19EB99;
int byte_19EB9A;
int byte_19EB9B;
int byte_19EB9C;
int byte_19EBA0;
int byte_19EF81;
int byte_19EF82;
int byte_19EF84;
int byte_1A0C6E;
int byte_1A125C;
int byte_1A7234;
int byte_1A7235;
int byte_1A7274;
int byte_1A7284;
int byte_1AAF60;
int byte_1AAF7E;
int byte_1AAF88;
int byte_1AAF8A;
int byte_1AAF8B;
int byte_1AAF8C;
int byte_1AAF94;
int byte_1AAF95;
int byte_1AB14C;
int byte_1AB14F;
int byte_1ACF60;
int byte_1ACF97;
int byte_1B3E88;
int byte_1B3E90;
int byte_1B3E98;
int byte_1B61D8;
int byte_1BA318;
/* byte_1BA319/byte_1BA31A odstraneny (vlna 89) - jsou soucasti prekryvoveho
   bloku byte_1BA318[64] v orion_data.c/orion_common.h a od vlny 89 jsou to
   makra. Tady to byly DUPLICITNI skalary (link_stubs.c nezahrnuje
   orion_common.h, takze se makro neuplatnilo) - tataz past jako ve vlne 73. */
int byte_1BB354;
int byte_1BB355;
int byte_1BB356;
int byte_1BB357;
int byte_1BB499;
int byte_1BB49A;
int byte_1BB599;
int byte_1BB59A;
int byte_1BB619;
int byte_1BB61A;
int byte_1BB658;
int byte_1BB659;
int byte_1BB65A;
int byte_1BB758;
int byte_1BC89B;
int byte_1BC89C;
int byte_1BD0A0;
int byte_1BD35A;
int byte_1BD35B;
int byte_1BD35C;
int byte_1BD35D;
int byte_1BD35E;
int byte_1BE355;
int byte_1BE356;
/* dos_getdiskfree/dos_getvect/dos_setvect (Watcom _dos_* runtime, INT 21h
   AH=36h/35h/25h) UZ NEJSOU stubovane - skutecna implementace (realne volne
   misto na disku pres std::filesystem + emulovana tabulka interrupt vektoru)
   je v src/port/port_dos.cpp, deklarace v port_dos.h a zrcadlene v
   decomp_compat.h. Viz PROGRESS.md vlna 09. */
/* PORT (wave 25r-6): NEPOUZIVAT primo pro radkovy stride obrazovky.
   IDA pojmenovala VNITREK souvisleho qword_184530 (LODWORD=0, HIDWORD=640 =
   stride) jako samostatny symbol, a 54 mist v dekompilatu cetlo stride
   vyrazem `*(int *)((char *)&dword_184532 + 2)`. V originalu je to
   `mov edx, dword ptr qword_184530+4` (viz sub_1475BB), tedy proste HIDWORD
   toho qwordu - jenze tady je dword_184532 samostatny symbol (v hlavicce
   dokonce `_UNKNOWN`, 1 bajt), takze se cetly 4 bajty CIZI pameti.
   Dusledek: `sub_1475BB` (celoobrazovkova vypln) vyplnila jen PRVNI RADEK a
   pak ukazatel odskocil mimo buffer -> vymazani obrazovky pri prechodu sceny
   se nikdy neprojevilo. Vsechna pouziti nahrazena za HIDWORD(qword_184530). */
int dword_184532;
int dword_184536;
int dword_18F4B0;
int dword_18F4C0;
/* vlna 85: duplicitni skalar - skutecne pole je v orion_data.c */
int dword_190498;
int dword_1904C8;
int dword_1906B0;
/* vlna 73: dword_192210 a dword_192228 jsou ted souvisla pole v orion_data.c
   (a puvodni skalary jsou makra do nich), duplicitni definice tu byly navic. */
/* vlna 58: dword_192630/192644 jsou ted souvisly blok v orion_data.c
   (a dword_192644 makro do nej), duplicitni skalary tu byly navic. */
int dword_19291C;
int dword_1933F8;
int dword_19A058;
int dword_19A060;
int dword_19A080;
int dword_19A0E8;
int dword_19A1A0;
int dword_19A1BC;
int dword_19A1E8;
int dword_19A200;
int dword_19A21C;
int dword_19A22C;
int dword_19A248;
int dword_19A26C;
int dword_19BEDC;
int dword_19DD98;
int dword_19EAF4;
int dword_19EAF8;
int dword_19EAFC;
int dword_19EB00;
int dword_19EB04;
int dword_19FA2C;
int dword_1A0C40;
int dword_1A0C6A;
/* PORT (vlna 58): dword_1A1260/12D4/12FC/1300/1310/132C tady byly jako
   SKALARY, zatimco orion_data.c je definuje jako pole - dve tentativni
   definice se v C slily na spolecny symbol o velikosti 4 B. Ted jsou to
   souvisle bloky v orion_data.c (a cast z nich makra v orion_common.h). */
int dword_1A7254;
int dword_1A7294;
int dword_1A72B8;
int dword_1A72C0;
int dword_1A72C4;
int dword_1A7454;
int dword_1A7458;
int dword_1AA3F4;
int dword_1AA404;
int dword_1AAB48;
int dword_1AAB5C;
int dword_1AAB70;
int dword_1ACEBC;
int dword_1ACFC0;
int dword_1AD6C4;
/* dword_1BB910 odstraneno (vlna 89) - je soucasti prekryvoveho bloku
   screenPtrs_1BB910 v orion_data.c/orion_common.h. Tady to byl DUPLICITNI
   skalar (link_stubs.c nezahrnuje orion_common.h, takze makro se neuplatnilo);
   tataz past, kterou popisuje vlna 73. Nikdo ho nereferencoval. */
/* dword_1BBA74 odstraneno (vlna 12) - je soucasti prekryvoveho bloku
   lbxHeader_1BBA6A, viz orion_data.c/orion_common.h. */
int dword_1BD352;
int dword_1C9400;
int dword_1C9540;
/* fprintf/fscanf/printf/sprintf ZAMERNE NEJSOU stubovane - jsou to realne
   standardni CRT funkce (viz <stdio.h> pribaleny v decomp_compat.h) a
   dekompilovany kod je opravdu pouziva se skutecnymi argumenty (napr. AIL
   debug log v orion_part_21.c, nacitani hodnot v orion_part_07.c) - stub
   vracejici vzdy 0 by jejich chovani rozbil. Puvodne tu byly definovane
   jako no-op nahrady (viz git historie), coz zpusobovalo LNK2005/LNK1169
   "multiply defined symbol" ve chvili, kdy se do projektu pridala realna
   CRT knihovna (SDL3 zavislosti, port_memory.cpp pouzivajici <cstdio>). */
int DECOMP_MEMORY_STUB;
int DECOMP_STACK_STUB;
/* int386 UZ NENI no-op stub - emulace je v src/port/port_dos.cpp
   (INT 33h/mys -> Port::Mouse, ostatni preruseni deterministicky vraci
   vstupni registry). Stub, ktery do vystupniho REGS bufferu nic nezapsal,
   zpusoboval cteni neinicializovane pameti - viz PROGRESS.md vlna 13. */
int PortDos_Int386(int intNum, const void* inRegs, void* outRegs);
int int386(int inum, void* inregs, void* outregs) {
    return PortDos_Int386(inum, inregs, outregs);
}
/* int386x UZ NENI no-op stub (vlna 26 pokr. 41). Prave pres nej si hra
   registruje OBSLUZNOU RUTINU MYSHI (INT 33h fn 0x0C v sub_1237F3 a fn 0x14
   v sub_12386C/sub_123926) - dokud to byl stub vracejici 0, port se o rutine
   nikdy nedozvedel, nikdy ji nezavolal, a tim padem se herni pozice kurzoru
   (dword_1BBA38/1BBA34) ani stav tlacitek (word_1B921A) nikdy nezmenily:
   kurzor zustaval na 0,0 a kliknuti nemela ucinek. Emulace je v
   src/port/port_dos.cpp. */
int PortDos_Int386x(int intNum, const void* inRegs);
int int386x(int inum, void* inregs) {
    return PortDos_Int386x(inum, inregs);
}
int j___clock(void) { return 0; }
int j___delay(void) { return 0; }
int j__nfree(void) { return 0; }
int j_unlink(void) { return 0; }
int loc_110177;
int loc_168636;
int loc_90139;
int loc_93D66;
int loc_A0020;
int loc_E0000;
int loc_E40C7;
/* memavl UZ NENI stub - skutecna implementace (zbytek emulovaneho 32MiB
   rozpoctu pameti) je v src/port/port_memory.cpp. Stub vracejici 0 posilal
   hru do "Insufficient Memory!" vetve a nasledneho zaseknuti v nekonecne
   sondovaci smycce sub_110FE7. Viz PROGRESS.md vlna 11. */
/* Hex-Rays intrinsic memset32(dst, val, count): fill `count` DWORDs at dst with
   the 32-bit value `val`. This was a no-op stub (returned 0, ignored its args),
   so every buffer the game clears via sub_127678 (the backbuffers dword_1BB90C/
   1BB8FC, the dirty-span tables dword_1BB908/1BB8C0, palette fills, ...) stayed
   at the debug-heap fill 0xCDCDCDCD instead of 0. That surfaced as garbage top
   rows (the "extra line") and wrong dirty spans (jumping top). Fixed in wave 22k;
   verified against dosbox (original backbuffer top = 0x00000000, dirty entry =
   0x009F0000; the port had 0xCDCDCDCD / 0x009FCF0D before this). */
void *memset32(void *dst, unsigned int val, unsigned int count)
{
    unsigned int *p = (unsigned int *)dst;
    while ( count-- )
        *p++ = val;
    return dst;
}
/* DULEZITA OPRAVA (vlna 06): tady drive bylo "int nfree;" - OBYCEJNA
   DATOVA promenna se stejnym jmenem, jako ma FUNKCE "nfree" deklarovana
   v orion_common.h ("extern int nfree(unsigned int);"). Zadna SKUTECNA
   funkce nfree nikde v projektu neexistovala! Vsech 39 volani nfree(ptr)
   v herním kodu by se tak za behu linkovalo na adresu ctyr nulovych bajtu
   (tato promenna) - zavolani teto "funkce" by skocilo doprostred dat a
   spadlo/poskodilo pamet. Ted uz je nfree skutecna funkce, viz nize -
   napojena (spolu s nmalloc) na Port::Memory:: pres PortMemory_Alloc/Free. */
#ifdef __cplusplus
extern "C" {
#endif
void* PortMemory_Alloc(size_t size);
int   PortMemory_Free(void* ptr);
#ifdef __cplusplus
}
#endif

void* nmalloc(unsigned int a) {
    return PortMemory_Alloc(a);
};
int nfree(unsigned int a) {
    return PortMemory_Free((void*)(size_t)a);
};
int nosound(void) { return 0; }
int nullsub_1(void) { return 0; }
int nullsub_10(void) { return 0; }
int nullsub_11(void) { return 0; }
int nullsub_12(void) { return 0; }
int nullsub_13(void) { return 0; }
int nullsub_14(void) { return 0; }
int nullsub_15(void) { return 0; }
int nullsub_16(void) { return 0; }
int nullsub_17(void) { return 0; }
int nullsub_18(void) { return 0; }
int nullsub_19(void) { return 0; }
int nullsub_2(void) { return 0; }
int nullsub_21(void) { return 0; }
int nullsub_22(void) { return 0; }
int nullsub_3(void) { return 0; }
int nullsub_4(void) { return 0; }
int nullsub_5(void) { return 0; }
int nullsub_6(void) { return 0; }
int nullsub_7(void) { return 0; }
int nullsub_8(void) { return 0; }
int nullsub_9(void) { return 0; }
/* printf viz poznamka u fprintf vyse - nestubovat, je to realna CRT funkce. */
/* qmemcpy is Hex-Rays' name for a plain memcpy (rep movsd/movsb). It was a
   no-op stub returning 0, which SILENTLY dropped every graphics blit that
   used it (100+ call sites, e.g. the RLE blitter sub_14852C) - the screen
   would stay empty even with everything else fixed. Wave 20. */
void* qmemcpy(void* dst, const void* src, size_t n) {
    return memcpy(dst, src, n);
}
/* PORT (vlna 58): SBYTE4/SDWORD1/SDWORD2 -> makra v decomp_compat.h. */
int segread(void) { return 0; }
int sound(void) { return 0; }
/* sprintf viz poznamka u fprintf vyse - nestubovat, je to realna CRT funkce. */
// PORT (wave 23b): real constant, not a stub - see orion_common.h comment.
const int sub_10000 = 0x10000;
int sub_1279A(void) { return 0; }
int sub_13F949(void) { return 0; }
int sub_13F94E(void) { return 0; }
int sub_13FBB5(void) { return 0; }
int sub_13FD4B(void) { return 0; }
int sub_149950(void) { return 0; }
int sub_1499C0(void) { return 0; }
// PORT (wave 25): dword_18A5AC ("int (*)(_DWORD)") is the Miles Sound System
// AIL_ms_count()-equivalent timer-tick query, installed by sub_149890/
// sub_149A20 and used throughout the Smacker reader (orion_part_22.c) for
// real-time pacing - both as a plain "read current tick" query and as a
// busy-wait throttle (`do v = dword_18A5AC(v); while (v < target);`). Both
// candidate implementations were `return 0;` stubs, meaning every timing/
// pacing calculation derived from them saw a permanently-stopped clock: no
// per-frame throttling ever engaged, so the whole cinematic (including any
// palette-encoded fade-in/out, which only reads as a fade when spread across
// real elapsed time) decoded and presented as fast as the CPU allowed, i.e.
// all in an eyeblink instead of over its authored duration. The single int
// argument is ignored by the real AIL_ms_count() too (Miles callers just
// re-feed the previous return value into the throttle loop above) - a real
// monotonic millisecond clock is all that is needed here.
int sub_149B10(int a1) { (void)a1; return (int)SDL_GetTicks(); }
int sub_149B30(int a1) { (void)a1; return (int)SDL_GetTicks(); }
int sub_149BB0(void) { return 0; }
int sub_149C40(void) { return 0; }
int sub_15C7F0(void) { return 0; }
int sub_164DA0(void) { return 0; }
int sub_1655B0(void) { return 0; }
/* PORT (wave 25q): real implementation now lives in orion_part_26.c */
/* PORT (wave 25q): real implementation now lives in orion_part_26.c */
/* PORT (wave 25q): real implementation now lives in orion_part_26.c */
int sub_702E5(void) { return 0; }
int sub_772BF(void) { return 0; }
int sub_77433(void) { return 0; }
int sub_8139F(void) { return 0; }
/* vlna 81: sub_8CF09 uz neni pahyl - rekonstruovano v orion_part_08.c */
int sub_A162D(void) { return 0; }
int sub_A5EBC(void) { return 0; }
int sub_B3E75(void) { return 0; }
int sub_C5B5F(void) { return 0; }
/* PORT (vlna 58): SWORD1..SWORD6 -> makra v decomp_compat.h. SWORD2 tu byl
   DATOVY symbol -> 144 jeho "volani" skakalo do .bss (pad NEW GAME). */
int unk_178A04;
int unk_183938;
int unk_183CEB;
int unk_199A12;
int unk_19C048;
/* vlna 58: unk_19C6F8 a unk_19C7C6 jsou druha jmena IDA pro byte_19C6F8
   resp. byte_19C7C6 - ted makra v orion_common.h; pahyly by z nich zase
   udelaly samostatne objekty a cetlo by se prazdno. */
int unk_19DA6C;
int unk_1A74B4;
int unk_1AA414;
int unk_1AAED5;
int unk_1AD404;
int unk_1AD418;
int unk_1AD454;
int unk_1AD494;
int unk_1AE054;
/* unk_1AE5D4 zrusen (vlna 26 pokr. 54) - je to tentyz symbol jako
   word_1AE5D4[2086] v orion_data.c; viz prekryvove makro v orion_common.h. */
int unk_1B000D;
int unk_1B0020;
int unk_1B002B;
int unk_1B0041;
int unk_1B0043;
int unk_1B004F;
int unk_1B0057;
// PORT (wave 24): sized array, not a plain int placeholder - see
// orion_common.h declaration comment (off_184480/off_184484 both point at
// this same "window slot table": 250 slots * 55 bytes, per the loop bounds
// in sub_11E718/sub_1198F9 and the sibling constant word_18447E=250).
char unk_1B0848[13750];
int unk_1BB8C4;
int unk_1C95D8;
/* unknown_libname_1/2 (puvodni Watcom v9.x DOS runtime FINDFIRST/FINDNEXT,
   INT 21h AH=1Ah+4Eh/4Fh) UZ NEJSOU stubovane - skutecna implementace
   (case-insensitive, s * a ? wildcards) je v src/port/port_file.cpp,
   deklarace v src/port/port_file.h. Viz PROGRESS.md vlna 08. */
/* vsprintf viz poznamka u fprintf v horni casti souboru - nestubovat, je
   to realna CRT funkce a dekompilovany kod ji genuinne pouziva (napr.
   orion_part_12.c, orion_part_21.c, orion_part_24.c). */
int word_18F500;
/* vlna 85: `word_1906C8` NENI funkce, ale POLE pozic hvezd na mape -
   zaslepka se stejnym jmenem kolidovala s definici v orion_data.c a odkaz
   mohl skoncit v kodu (zmereno: zapis na 0x2149DF uvnitr modulu). */
int word_19296C;
int word_192B10;
int word_192C80;
int word_192C82;
int word_192C84;
int word_192C86;
int word_192C88;
/* vlna 88: duplicitni skalar - skutecne pole je v orion_data.c */
/* vlna 85: DUPLICITNI skalarni definice - skutecne pole je v orion_data.c word_192FDE */
int word_192FE0;
int word_192FE2;
/* vlna 85: DUPLICITNI skalarni definice - skutecne pole je v orion_data.c word_192FE4 */
/* vlna 85: DUPLICITNI skalarni definice - skutecne pole je v orion_data.c word_192FE6 */
int word_192FE8;
int word_192FEA;
int word_192FEC;
int word_192FEE;
int word_192FF0;
int word_192FF2;
int word_192FF4;
int word_192FF6;
/* vlna 116: duplicitni skalar odstranen - pole je v orion_data.c */
int word_1931BC;
int word_1931BE;
int word_1931C0;
int word_1931C2;
int word_19918A;
int word_1991B6;
/* vlna 85: DUPLICITNI skalarni definice - skutecne pole je v orion_data.c word_1992C0 */
int word_19A020;
int word_19A022;
int word_19A0C8;
int word_19A5B4;
int word_19A5B6;
int word_19A5B8;
int word_19A5BA;
int word_19A5BC;
/* vlna 73: word_19B694 a word_19B6C8 jsou ted souvisla pole v orion_data.c
   (word_19B6DC je makro do word_19B6C8), duplicitni skalary tu prekazely. */
int word_19C0A0;
int word_19C0A2;
int word_19C0E0;
int word_19C0E2;
int word_19C0E4;
int word_19C6C6;
int word_19C6DA;
int word_19E040;
int word_19E044;
int word_19E046;
int word_19EB94;
int word_19EB96;
int word_19F99C;
int word_19F9BA;
int word_19F9E0;
int word_1A08E4;
int word_1A0904;
int word_1A0906;
int word_1A0908;
int word_1A0C64;
int word_1A0C66;
int word_1A0C68;
int word_1AA38A;
int word_1AAF8D;
int word_1AAF8F;
int word_1AAF91;
int word_1ACE78;
int word_1ACE7A;
int word_1ACFEC;
int word_1ACFEE;
int word_1ACFF0;
int word_1ACFF2;
int word_1ACFF4;
int word_1B43B8;
int word_1BD356;
int word_1BD358;
int word_1BDF52;
int word_1BDF54;
