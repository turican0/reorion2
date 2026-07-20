// port_vga.h - nahrada za VGA/BIOS video sluzby (int 10h, primy pristup na
// A000:0000 framebuffer) postavena na SDL3. Az najdeme dekompilovane funkce,
// ktere primo zapisuji do VGA pameti nebo volaji int 10h (v puvodnim kodu
// typicky viditelne jako zapisy na pevne adresy segmentu A000 nebo volani
// nejasnych "unknown_libname_*"/"sub_*" wrapperu okolo BIOS sluzeb), jejich
// citelna verze bude volat funkce odsud.
#ifndef PORT_VGA_H
#define PORT_VGA_H

#include <cstdint>

namespace Port::Vga {

// Vytvori SDL3 okno + renderer. Vlna 21: rozliseni 640x480 - hra bezi ve
// vynucenem VESA modu 5 (640x480x8bpp, viz sub_1248AB vlna 16); mode-5
// prezentacni funkce (sub_1255DF a spol.) kopiruji cely 307200B obraz.
bool Init();

// Linearni 8bpp framebuffer 640x480 (nahrada VESA okna na A000:0000).
// Zaloha ma velikost 5 celych 64KiB bank (327680 B) - bankovane kopie
// originalu smely adresovat i zbytek posledniho okna za koncem obrazu.
uint8_t* Framebuffer();

void Shutdown();

// Nahrazuje primy zapis do VGA framebufferu (segment 0xA000) v rezimu 13h -
// jeden byte = jeden pixel = index do 256barevne palety.
void SetPixel8(int x, int y, uint8_t colorIndex);

// Nahrazuje BIOS int 10h/AH=10h (nastaveni polozky palety).
void SetPaletteEntry(uint8_t index, uint8_t r, uint8_t g, uint8_t b);

// Prekresli okno - volat jednou za herni snimek (nahrazuje puvodni cekani
// na vertikalni zpetny beh pres port 3DAh).
void Present();

} // namespace Port::Vga

#endif // PORT_VGA_H
