// port_dos.h - nahrada za veci, ktere puvodne resil DOS/BIOS (int 21h, PSP,
// souborovy system, prostredi procesu...). Inspirovano tim, jak podobne
// vrstvy delaji dosbox-x a remc2 - cilem NENI plna emulace DOSu, ale jen
// poskytnout dekompilovanemu kodu prostredi, ktere ocekava.
//
// DECOMP_TODO: az budeme prochazet dalsi vlny funkci (sub_xxx), veci jako
// primy pristup na segment:offset pameti, int 21h volani pres emulovane
// registry apod. sem prijdou postupne - ted je tu jen kostra a terminal
// emulace, protoze ta musi bezet uplne prvni (viz reorion2.cpp). Souborove
// DOS sluzby (FINDFIRST/FINDNEXT, INT 21h AH=1Ah/4Eh/4Fh) jsou vyjimka -
// ty jsou v src/port/port_file.cpp spolu se zbytkem souboroveho I/O,
// protoze znovupouzivaji stejnou case-insensitive resolver logiku (viz
// PORT_LAYER_ARCHITECTURE.md, "Poznamka k realne implementaci").
#ifndef PORT_DOS_H
#define PORT_DOS_H

#include <cstdint>

// ---------------------------------------------------------------------
// Sdileny guard s hexrays_compat.h: obe hlavicky definuji stejne struktury
// (kazda pro svou stranu - port vs. cisty C herni kod), ale reorion2.cpp
// includuje obe najednou - bez guardu by slo o redefinici.
#ifndef REORION2_DOS_STRUCTS_DEFINED
#define REORION2_DOS_STRUCTS_DEFINED

// Vysledek INT 21h AH=36h (GET DISK FREE SPACE) - Watcom "_dos_getdiskfree"
// a jeho "struct diskfree_t". Layout OVEREN z volajiciho mista
// GetFreeDiskSpace_111763 (orion_part_18.c): buffer 4x uint16 na ofsetech
// 0/2/4/6, volajici pocita volne bajty jako soucin poli +2 * +4 * +6 -
// presne odpovida Watcom poradi total/avail/sectors_per_cluster/
// bytes_per_sector (avail*spc*bps = volne bajty). Pole jsou 16bitova
// (obsah registru DX/BX/AX/CX z INT 21h), proto pack(1) + uint16_t.
#pragma pack(push, 1)
struct DosDiskFree {
    uint16_t total_clusters;      // +0 - DX
    uint16_t avail_clusters;      // +2 - BX
    uint16_t sectors_per_cluster; // +4 - AX
    uint16_t bytes_per_sector;    // +6 - CX
};
#pragma pack(pop)

// 48bitovy DOS4GW "far pointer" na interrupt handler (32bit offset +
// 16bit selektor/segment) - tvar, ve kterem si hra uklada puvodni INT 9
// vektor (savedKeyboardVector_1BC2DC, puvodne 6 bajtu na adrese 1BC2DC).
#pragma pack(push, 1)
struct DosFarPointer {
    uint32_t offset;  // +0
    uint16_t segment; // +4
};
#pragma pack(pop)

#endif // REORION2_DOS_STRUCTS_DEFINED

// ---------------------------------------------------------------------
// C-linkage most pro dekompilovany herni kod (jmena odpovidaji puvodnim
// IDA nazvum Watcom runtime funkci, stejny princip jako unknown_libname_1/2
// v port_file.h). Deklarace pro cisty C kod jsou zrcadlene v
// hexrays_compat.h (ten nemuze includovat tento header kvuli namespace).
#ifdef __cplusplus
extern "C" {
#endif

// _dos_getdiskfree (INT 21h AH=36h). drive: 0 = aktualni disk (jedina
// hodnota, kterou hra pouziva), 1 = A: atd. Vraci 0 pri uspechu
// (klasicka DOS "errno" konvence - viz ponauceni z vlny 08), nenulovou
// pri chybe - volajici pak povazuje volne misto za 0.
int dos_getdiskfree(unsigned int drive, struct DosDiskFree* out);

// _dos_getvect (INT 21h AH=35h) - vrati OFFSET handleru ulozeneho v
// emulovane tabulce vektoru. POZOR na artefakt dekompilace: v originale
// vracel 48bit far pointer v DX:EAX - segmentovou cast (DX) dekompiler
// ve volajicim InstallKeyboardIsr_12C420 mylne ztotoznil s parametrem a2.
unsigned int dos_getvect(unsigned int vectorNumber);

// _dos_setvect (INT 21h AH=25h) - ulozi handler do emulovane tabulky
// vektoru. Druhy parametr je artefakt registroveho volani (duplikat cisla
// vektoru v dalsim registru) - zachovan, aby sedel na dekompilovana
// volajici mista. Handler se v portu NIKDY nevykonava (klavesnici resi
// SDL3 v port_mouse/port_vga vrstve) - tabulka jen verne uchovava
// hodnoty, aby parove uloz/instaluj/obnov sekvence fungovaly identicky.
int dos_setvect(unsigned int vectorNumber, unsigned int vectorNumberDup,
                unsigned int handlerOffset, unsigned int handlerSegment);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace Port::Dos {

// Volne misto na disku (adresar, ve kterem hra bezi) zakodovane do
// 16bitovych DOS poli - viz komentar u DosDiskFree. Kvuli 16bitovym
// polim je vysledek zamerne zastropovan tesne pod 2 GiB (soucin poli
// se musi vejit do "int" nasobeni ve volajicim kodu bez preteceni).
// Vraci true pri uspechu.
bool GetDiskFree(DosDiskFree& out);

// Emulovana tabulka interrupt vektoru (256 polozek, jen uloziste -
// handlery se nevykonavaji, viz dos_setvect vyse).
DosFarPointer GetInterruptVector(unsigned int vectorNumber);
void SetInterruptVector(unsigned int vectorNumber, DosFarPointer value);

// Inicializuje jednoduchy terminalovy emulator (80x25 textovy bufer), ktery
// SDL3 vrstva (port_vga) pozdeji vykresli jako grafiku, ale zaroven se vzdy
// zrcadli na standardni vystup (stdout) - presne jak je pozadovano: "bude se
// to posilat i na standardni vystup, pokud bude."
void InitTerminalEmulation();

// Zapise text do terminalu na aktualni pozici kurzoru (textovy rezim).
// Vzdy se propise i na stdout.
void TerminalWrite(const char* text);

// Nastavi pozici kurzoru v textovem rezimu (0-based, radek/sloupec).
void TerminalSetCursor(int row, int col);

// Vrati true, pokud uz je terminal/graficke okno inicializovane a pripravene
// prijimat vystup - GameMain_10057 a jeho volani na to budou postupne
// napojovana misto puvodnich primych volani DOS/BIOS interruptu.
bool IsTerminalReady();

} // namespace Port::Dos
#endif // __cplusplus

#endif // PORT_DOS_H
