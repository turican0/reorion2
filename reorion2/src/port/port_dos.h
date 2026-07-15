// port_dos.h - nahrada za veci, ktere puvodne resil DOS/BIOS (int 21h, PSP,
// souborovy system, prostredi procesu...). Inspirovano tim, jak podobne
// vrstvy delaji dosbox-x a remc2 - cilem NENI plna emulace DOSu, ale jen
// poskytnout dekompilovanemu kodu prostredi, ktere ocekava.
//
// DECOMP_TODO: az budeme prochazet dalsi vlny funkci (sub_xxx), veci jako
// primy pristup na segment:offset pameti, int 21h volani pres emulovane
// registry apod. sem prijdou postupne - ted je tu jen kostra a terminal
// emulace, protoze ta musi bezet uplne prvni (viz reorion2.cpp).
#ifndef PORT_DOS_H
#define PORT_DOS_H

namespace Port::Dos {

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

#endif // PORT_DOS_H
