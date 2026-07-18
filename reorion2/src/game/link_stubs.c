/*
 * Link-time placeholders for dependencies missing from the Hex-Rays dump.
 * They make the project linkable; they do not implement the original DOS/Watcom runtime.
 */
#include <stddef.h> /* size_t - potreba pro PortMemory_* deklarace nize (vlna 06) */

int __CS__;
int __DS__;
int __ES__;
int __FS__;
int __GS__;
int __PAIR32__(void) { return 0; }
int __PAIR64__;
int __ROL4__(void) { return 0; }
int __ROR4__(void) { return 0; }
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
int abs16(void) { return 0; }
int abs32(void) { return 0; }
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
int byte_19B688;
int byte_19C120;
int byte_19C148;
int byte_19C31C;
int byte_19C6EE;
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
int byte_1B071B;
int byte_1B071C;
int byte_1B071D;
int byte_1B3E88;
int byte_1B3E90;
int byte_1B3E98;
int byte_1B61D8;
int byte_1BA318;
int byte_1BA319;
int byte_1BA31A;
int byte_1BB354;
int byte_1BB355;
int byte_1BB356;
int byte_1BB357;
int byte_1BB358;
int byte_1BB359;
int byte_1BB35A;
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
int byte_1BC79C;
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
   hexrays_compat.h. Viz PROGRESS.md vlna 09. */
int dword_184532;
int dword_184536;
int dword_18F4B0;
int dword_18F4C0;
int dword_18F990;
int dword_18F9B8;
int dword_190298;
int dword_190430;
int dword_190448;
int dword_190498;
int dword_1904C8;
int dword_1906B0;
int dword_192210;
int dword_192228;
int dword_192630;
int dword_192644;
int dword_19291C;
int dword_192BE0;
int dword_192BF4;
int dword_192C08;
int dword_192C74;
int dword_1933F8;
int dword_197FA0;
int dword_199150;
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
int dword_1A1260;
int dword_1A12D4;
int dword_1A12FC;
int dword_1A1300;
int dword_1A1310;
int dword_1A132C;
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
int dword_1BB910;
/* dword_1BBA74 odstraneno (vlna 12) - je soucasti prekryvoveho bloku
   lbxHeader_1BBA6A, viz orion_data.c/orion_common.h. */
int dword_1BD352;
int dword_1C9400;
int dword_1C9540;
/* fprintf/fscanf/printf/sprintf ZAMERNE NEJSOU stubovane - jsou to realne
   standardni CRT funkce (viz <stdio.h> pribaleny v hexrays_compat.h) a
   dekompilovany kod je opravdu pouziva se skutecnymi argumenty (napr. AIL
   debug log v orion_part_21.c, nacitani hodnot v orion_part_07.c) - stub
   vracejici vzdy 0 by jejich chovani rozbil. Puvodne tu byly definovane
   jako no-op nahrady (viz git historie), coz zpusobovalo LNK2005/LNK1169
   "multiply defined symbol" ve chvili, kdy se do projektu pridala realna
   CRT knihovna (SDL3 zavislosti, port_memory.cpp pouzivajici <cstdio>). */
int HEXRAYS_MEMORY_STUB;
int HEXRAYS_STACK_STUB;
int int386(void) { return 0; }
int int386x(void) { return 0; }
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
int memset32(void) { return 0; }
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
int qmemcpy(void) { return 0; }
int SBYTE4(void) { return 0; }
int SDWORD1(void) { return 0; }
int SDWORD2(void) { return 0; }
int segread(void) { return 0; }
int sound(void) { return 0; }
/* sprintf viz poznamka u fprintf vyse - nestubovat, je to realna CRT funkce. */
int sub_10000;
int sub_1279A(void) { return 0; }
int sub_13F949(void) { return 0; }
int sub_13F94E(void) { return 0; }
int sub_13FBB5(void) { return 0; }
int sub_13FD4B(void) { return 0; }
int sub_149950(void) { return 0; }
int sub_1499C0(void) { return 0; }
int sub_149B10(void) { return 0; }
int sub_149B30(void) { return 0; }
int sub_149BB0(void) { return 0; }
int sub_149C40(void) { return 0; }
int sub_15C7F0(void) { return 0; }
int sub_164DA0(void) { return 0; }
int sub_1655B0(void) { return 0; }
int sub_166830(void) { return 0; }
int sub_167040(void) { return 0; }
int sub_167190(void) { return 0; }
int sub_702E5(void) { return 0; }
int sub_772BF(void) { return 0; }
int sub_77433(void) { return 0; }
int sub_8139F(void) { return 0; }
int sub_8CF09(void) { return 0; }
int sub_A162D(void) { return 0; }
int sub_A5EBC(void) { return 0; }
int sub_B3E75(void) { return 0; }
int sub_C5B5F(void) { return 0; }
int SWORD1(void) { return 0; }
int SWORD2;
int SWORD3(void) { return 0; }
int SWORD4(void) { return 0; }
int SWORD5(void) { return 0; }
int SWORD6(void) { return 0; }
int unk_178A04;
int unk_183938;
int unk_183B46;
int unk_183B93;
int unk_183CEB;
int unk_18A610;
int unk_199A12;
int unk_19B772;
int unk_19C048;
int unk_19C348;
int unk_19C6F8;
int unk_19C7C6;
int unk_19DA6C;
int unk_1A74B4;
int unk_1AA414;
int unk_1AAED5;
int unk_1AD404;
int unk_1AD418;
int unk_1AD454;
int unk_1AD494;
int unk_1AE054;
int unk_1AE5D4;
int unk_1B000D;
int unk_1B0020;
int unk_1B002B;
int unk_1B0041;
int unk_1B0043;
int unk_1B004F;
int unk_1B0057;
int unk_1B0848;
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
int word_1906C0;
int word_1906C2;
int word_1906C4;
int word_1906C6;
int word_1906C8(void) { return 0; }
int word_19296C;
int word_192B10;
int word_192C80;
int word_192C82;
int word_192C84;
int word_192C86;
int word_192C88;
int word_192FDC;
int word_192FDE;
int word_192FE0;
int word_192FE2;
int word_192FE4;
int word_192FE6;
int word_192FE8;
int word_192FEA;
int word_192FEC;
int word_192FEE;
int word_192FF0;
int word_192FF2;
int word_192FF4;
int word_192FF6;
int word_1931AC;
int word_1931BC;
int word_1931BE;
int word_1931C0;
int word_1931C2;
int word_19918A;
int word_1991B6;
int word_1992C0;
int word_19A020;
int word_19A022;
int word_19A0C8;
int word_19A5B4;
int word_19A5B6;
int word_19A5B8;
int word_19A5BA;
int word_19A5BC;
int word_19B694;
int word_19B6C8;
int word_19B6DC;
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
