// port_file.h - nahrada za souborove sluzby DOS/BIOS (int 21h subset:
// otevirani/cteni/zapis/seek souboru). Puvodni DOS FAT filesystem byl VZDY
// case-insensitive (SOUND.LBX == sound.lbx == Sound.Lbx) - dekompilovany
// kod s tim pocita a retezcove literaly pro nazvy souboru maji nepredvidatelnou
// velikost pismen. Na Windows (NTFS/FAT) to CRT vyresi samo, ale na
// Linuxu/macOS (case-sensitive filesystemy) by presne to same volani
// fopen() bez uprav SELHALO, kdyby se velikost pismen na disku neshodovala
// presne - proto tahle vrstva na non-Windows systemech dohledava spravny
// nazev rucnim prochazenim adresare (viz PORT_LAYER_ARCHITECTURE.md,
// sekce 5.6 a 8).
//
// DULEZITY DESIGN DETAIL: dekompilovany kod NIKDE nepouziva typ "FILE*" -
// vysledek fopen() vzdy uklada do "int"/"_DWORD" promennych (napr.
// "dword_1BC338 = fopen(...)"). Kdyby PortFile_Open vracel skutecny
// FILE* (8 bajtu na x64), ulozeni do 32bit promenne by ukazatel oriznul
// a nasledne PortFile_Read/Close by dostaly nesmyslnou adresu - jisty pad.
// Proto PortFile_Open vraci maly CELOCISELNY HANDLE (index do interni
// tabulky, 0 = neplatny/selhani - stejna "falsy" semantika jako NULL),
// ktery se bezpecne vejde do "int" na kterekoliv platforme.
//
// VSECHNY souborove funkce v dekompilovanem kodu (fopen/fclose/fread/
// fwrite/fseek/ftell/fflush/access) jsou presmerovane sem pres makra v
// decomp_compat.h - viz komentar tam.
//
// Sem patri i FINDFIRST/FINDNEXT (INT 21h AH=1Ah+4Eh/4Fh, puvodne
// "unknown_libname_1/2" - Watcom v9.x DOS runtime, viz PROGRESS.md vlna
// 08) - je to sice DOS interrupt sluzba, ale je to PRIMO adresarove
// hledani souboru, ktere potrebuje presne tu samou case-insensitive
// resolver logiku jako fopen() nize - dava vic smysl tady nez v
// port_dos.cpp (ktery resi jen terminal/obecne DOS sluzby).
#ifndef PORT_FILE_H
#define PORT_FILE_H

#include <cstddef>
#include <cstdint>

// ---------------------------------------------------------------------
// C-linkage most pro dekompilovany herni kod (cisty C, src/game/*.c).
// Vsechny funkce pracuji s "int" handle misto FILE* - viz vyse.
#ifdef __cplusplus
extern "C" {
#endif

int    PortFile_Open(const char* path, const char* mode);
int    PortFile_Close(int handle);
size_t PortFile_Read(void* buffer, size_t size, size_t count, int handle);
size_t PortFile_Write(const void* buffer, size_t size, size_t count, int handle);
int    PortFile_Seek(int handle, long offset, int origin);
long   PortFile_Tell(int handle);
int    PortFile_Flush(int handle);
int    PortFile_Access(const char* path, int mode);

#ifdef __cplusplus
}
#endif

// ---------------------------------------------------------------------
// DOS DTA (Disk Transfer Area) - vysledek INT 21h AH=4Eh/4Fh (FINDFIRST/
// FINDNEXT ASCIZ). Layout OVEREN primo z volajicich mist v dekompilaci
// (orion_part_18.c) - hra cte jednotlive polozky primo na pevnych
// bytovych offsetech od zacatku DTA bufferu `unk_1AD828`:
//   dword_1AD842 (+0x1A) = velikost, word_1AD840 (+0x18) = datum,
//   word_1AD83E (+0x16) = cas, unk_1AD846 (+0x1E) = jmeno (13 bajtu).
// Presne odpovida standardnimu DOS DTA formatu (reserved 21B, attr 1B,
// time 2B, date 2B, size 4B, name 13B) - zadne hadani, jen overeny fakt
// z toho, jak hra na tyhle offsety pristupuje. `#pragma pack` je nutny,
// aby kompilator nezarovnaval pole jinak, nez presne na tyhle offsety.
#pragma pack(push, 1)
struct DosDta {
    uint8_t  reserved[21]; // interne: Port::File si sem uklada handle aktivniho hledani
    uint8_t  attr;         // +0x15
    uint16_t time;         // +0x16 - DOS-kodovany cas
    uint16_t date;         // +0x18 - DOS-kodovane datum
    uint32_t size;         // +0x1A
    char     name[13];     // +0x1E - 8.3 jmeno, null-terminated
};
#pragma pack(pop)
#ifdef __cplusplus
static_assert(sizeof(DosDta) == 0x1E + 13, "DosDta layout musi presne odpovidat overenym offsetum z dekompilace");
#endif

// C-linkage bridge - jmena odpovidaji puvodnim IDA nazvum ("unknown_libname_N"),
// protoze tyhle Watcom runtime funkce nemely rozpoznatelnou vlastni adresu
// (viz PROGRESS.md vlna 08).
#ifdef __cplusplus
extern "C" {
#endif
int unknown_libname_1(const char* pattern, int attrMask, struct DosDta* dta); // FINDFIRST
int unknown_libname_2(struct DosDta* dta); // FINDNEXT
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace Port::File {

// Vrati skutecnou cestu k souboru na disku, ktera case-insensitive
// odpovida "path" (na Windows vraci "path" beze zmeny - NTFS/FAT uz je
// case-insensitive samy o sobe). Na non-Windows prochazi adresarovou
// strukturu segment po segmentu a hleda case-insensitive shodu; vysledky
// se cachuji, aby se opakovane otevirani stejneho souboru neplatilo
// opakovanym prochazenim adresare.
const char* ResolveCaseInsensitivePath(const char* path);

// Zahodí cache vyresenych cest - uzitecne po vytvoreni/smazani souboru,
// aby dalsi ResolveCaseInsensitivePath videl aktualni stav disku.
void ClearResolveCache();

// Nahrada za INT 21h AH=1Ah (SET DTA) + AH=4Eh (FIND FIRST ASCIZ),
// spojene do jednoho volani presne tak, jak to delal puvodni Watcom
// runtime wrapper (viz unknown_libname_1 vyse). "pattern" muze
// obsahovat DOS wildcardy (* a ?) a je case-insensitive (pouziva stejny
// resolver jako fopen() vyse pro adresarovou cast cesty). Vraci true a
// vyplni "dta", pokud se nasel odpovidajici soubor.
bool FindFirst(const char* pattern, int attrMask, DosDta* dta);

// Nahrada za INT 21h AH=4Fh (FIND NEXT ASCIZ) - pokracuje v hledani
// zapocatem pres FindFirst se stejnym "dta" bufferem (hledaci stav je
// ulozen v jeho "reserved" bajtech, presne jako u puvodniho DOS DTA).
bool FindNext(DosDta* dta);

} // namespace Port::File
#endif // __cplusplus

#endif // PORT_FILE_H
