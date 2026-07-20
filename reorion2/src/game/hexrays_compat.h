/*
 * hexrays_compat.h
 * Kompatibilni vrstva pro preklad Hex-Rays dekompilovaneho vystupu
 * (Orion2.exe, Watcom C++, DOS4GW protected mode) beznym C kompilatorem.
 *
 * Ucel: umoznit SYNTAKTICKY preklad puvodniho pseudokodu, ne nutne
 * bit-presnou funkcni ekvivalenci. __asm bloky a "decompilation failure"
 * funkce jsou nahrazeny stuby s TODO komentarem - viz DECOMP_TODO.
 */
#ifndef HEXRAYS_COMPAT_H
#define HEXRAYS_COMPAT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
/* POZOR: zamerne NEpridavame <stdio.h> sem. Dekompilovany kod vola
   fopen/fseek/fgets/fgetc/ftell s jinym poctem argumentu, nez maji
   skutecne CRT prototypy (typicky Hex-Rays "guessed type" artefakt) -
   bez prototypu se to preklada jako implicitni K&R deklarace (funguje
   na cdecl ABI), se skutecnym prototypem z <stdio.h> uz ne. fprintf a
   spol. proto zustavaji take bez explicitniho prototypu zde - viz
   poznamka v link_stubs.c u jejich odstranenych stubu. */

/* ---- presmerovani alokacnich funkci na port_memory (vlna 06) ----
   VSECHNY malloc/calloc/realloc/free v dekompilovanem kodu jdou od ted
   pres Port::Memory:: evidenci zivych alokaci (leak-report pri shutdownu
   - viz src/port/port_memory.h/.cpp) misto primo na CRT alokator. Stejne
   jako u fprintf/sprintf drive NEpridavame <stdlib.h> - staci proste C
   deklarace primo tady, aby makra nekolidovala se skutecnymi prototypy.
   nmalloc/nfree (Watcom "near heap" varianty) NEJSOU makra, protoze uz
   maji vlastni extern deklaraci v orion_common.h ("unsigned int" misto
   "size_t") - kdyby se tu prejmenovaly makrem, ta deklarace by se
   makro-expandovala taky a vytvorila neshodujici se redeklaraci. Misto
   toho jsou nmalloc/nfree REALNE funkce definovane v link_stubs.c, ktere
   uvnitr volaji tyhle same PortMemory_* funkce - viz tam. */
#ifdef __cplusplus
extern "C" {
#endif
void* PortMemory_Alloc(size_t size);
void* PortMemory_Calloc(size_t count, size_t size);
void* PortMemory_Realloc(void* ptr, size_t size);
int   PortMemory_Free(void* ptr);
#ifdef __cplusplus
}
#endif

#define malloc(sz)      PortMemory_Alloc(sz)
#define calloc(cnt, sz) PortMemory_Calloc((cnt), (sz))
#define realloc(p, sz)  PortMemory_Realloc((p), (sz))
#define free(p)         ((void)PortMemory_Free(p))

/* ---- presmerovani souborovych funkci na port_file (vlna 06) ----
   fopen/fclose/fread/fwrite/fflush/access presmerovane na case-insensitive
   wrappery (viz src/port/port_file.h/.cpp) - overeno, ze VSECHNA jejich
   volani v dekompilovanem kodu maji spravny pocet argumentu (na rozdil od
   fseek/ftell nize, ktera VETSINOU nemaji - viz DECOMP_TODO tam).
   Handle je "int" (ne FILE*) - dekompilovany kod vzdy uklada vysledek
   fopen() do "int"/"_DWORD" promennych; skutecny 8bajtovy FILE* na x64
   by se pri takovem ulozeni oriznul. Viz DECOMP_TODO v port_file.h. */
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
/* Znakove/textove stdio - vlna 15 (viz port_file.cpp). Stream = int handle. */
char*  PortFile_Gets(char* buffer, int n, int handle);
int    PortFile_Getc(int handle);
int    PortFile_Putc(int c, int handle);
int    PortFile_Puts(const char* s, int handle);
int    PortFile_Setbuf(int handle, char* buf);
int    PortFile_Printf(int handle, const char* fmt, ...);
int    PortFile_Scanf(int handle, const char* fmt, ...);
#ifdef __cplusplus
}
#endif

/* SEEK_SET/SEEK_CUR/SEEK_END normalne prijdou z <stdio.h>, ktere sem
   zamerne nevkladame (viz vyse) - hodnoty jsou soucasti C standardu a
   nemeni se mezi platformami/kompilatory, takze je bezpecne je definovat
   primo tady. */
#ifndef SEEK_SET
#define SEEK_SET 0
#endif
#ifndef SEEK_CUR
#define SEEK_CUR 1
#endif
#ifndef SEEK_END
#define SEEK_END 2
#endif

#define fopen(path, mode)          PortFile_Open((path), (mode))
#define fclose(stream)             PortFile_Close(stream)
#define fread(buf, sz, cnt, str)   PortFile_Read((buf), (sz), (cnt), (str))
#define fwrite(buf, sz, cnt, str)  PortFile_Write((buf), (sz), (cnt), (str))
#define fseek(str, off, orig)      PortFile_Seek((str), (off), (orig))
#define ftell(str)                 PortFile_Tell(str)
#define fflush(str)                PortFile_Flush(str)
#define access(path, mode)         PortFile_Access((path), (mode))

/* Znakove/textove stdio (vlna 15) - stream je int handle z PortFile_Open,
   ne FILE*. fgets/fscanf/fprintf maji v dekompilaci casto navic zdvojeny
   posledni argument (Hex-Rays artefakt) - variadicka makra ho zahodi.
   fprintf smeruje vyhradne na herni handle (AIL debug log dword_1C0E50 /
   dword_1849E6), nikdy na stdout/stderr - viz analyza vlny 15. */
#define fgets(buf, n, str, ...)    PortFile_Gets((buf), (n), (str))
#define fgetc(str)                 PortFile_Getc(str)
#define fputc(c, str)              PortFile_Putc((c), (str))
#define fputs(s, str)              PortFile_Puts((s), (str))
#define setbuf(str, buf)           PortFile_Setbuf((str), (buf))
#define fscanf(str, ...)           PortFile_Scanf((str), __VA_ARGS__)
#define fprintf(str, ...)          PortFile_Printf((str), __VA_ARGS__)

/* ---- DOS FINDFIRST/FINDNEXT (vlna 08) ----
   "unknown_libname_1"/"unknown_libname_2" jsou puvodni Watcom v9.x DOS
   runtime knihovni funkce (nemely rozpoznatelnou vlastni adresu v IDA),
   ktere spojuji INT 21h AH=1Ah (SET DTA) + AH=4Eh/4Fh (FIND FIRST/NEXT
   ASCIZ) do jednoho volani. Skutecna implementace (case-insensitive
   hledani se * a ? wildcards, vyuziva stejny resolver jako fopen() vyse)
   je v src/port/port_file.cpp - logicky tam patri vic nez do port_dos.cpp,
   protoze jde primo o adresarove hledani souboru.
   DosDta layout je OVEREN primo z volajicich mist v orion_part_18.c
   (pevne bytove offsety na `unk_1AD828` odpovidaji presne standardnimu
   DOS DTA formatu - viz komentar u struktury nize a v port_file.h). */
#pragma pack(push, 1)
struct DosDta {
    uint8_t  reserved[21]; /* interne pouzivano Port::File pro handle hledani */
    uint8_t  attr;         /* +0x15 */
    uint16_t time;         /* +0x16 */
    uint16_t date;         /* +0x18 */
    uint32_t size;         /* +0x1A */
    char     name[13];     /* +0x1E - 8.3 jmeno, null-terminated */
};
#pragma pack(pop)

#ifdef __cplusplus
extern "C" {
#endif
int unknown_libname_1(const char* pattern, int attrMask, struct DosDta* dta); /* FINDFIRST */
int unknown_libname_2(struct DosDta* dta); /* FINDNEXT */
#ifdef __cplusplus
}
#endif

/* ---- diagnosticke checkpointy (vlna 11) ----
   Zapina se env promennou REORION2_TRACE=1 - pak kazdy checkpoint vypise
   radek "DIAG <jmeno> <hodnota>" na stderr (unbuffered, prezije i pad).
   Bez promenne no-op. Implementace v port_dos.cpp. Pouziti: docasne i
   trvale znacky v miste dulezitych prechodu init sekvence - pomaha najit,
   KAM az se beh dostal, kdyz stdout buffer pri padu zmizi. */
#ifdef __cplusplus
extern "C" {
#endif
void PortDebug_Checkpoint(const char* name, int value);
/* Vsync cekani (port 0x3DA) -> vykresleni snimku + ~70Hz takt, vlna 13. */
void PortVga_WaitVsync(void);
unsigned char *PortVga_Framebuffer(void);
/* BIOS tick counter (0x46C, ~18.2 Hz) z realneho casu, vlna 15. */
unsigned int PortDos_BiosTick(void);
#ifdef __cplusplus
}
#endif

/* ---- DOS diskfree + interrupt vektory (vlna 09) ----
   dos_getdiskfree/dos_getvect/dos_setvect jsou Watcom runtime funkce
   (_dos_getdiskfree = INT 21h AH=36h, _dos_getvect/AH=35h,
   _dos_setvect/AH=25h). Skutecna implementace je v src/port/port_dos.cpp
   (emulovana tabulka vektoru + realne volne misto na disku pres
   std::filesystem) - struktury a deklarace jsou zrcadlene z port_dos.h,
   viz komentare tam (layout DosDiskFree OVEREN z GetFreeDiskSpace_111763,
   navratova konvence 0=uspech je klasicky DOS "errno" styl - stejne
   ponauceni jako FINDFIRST ve vlne 08). Sdileny guard s port_dos.h -
   reorion2.cpp includuje obe hlavicky najednou. */
#ifndef REORION2_DOS_STRUCTS_DEFINED
#define REORION2_DOS_STRUCTS_DEFINED
#pragma pack(push, 1)
struct DosDiskFree {
    uint16_t total_clusters;      /* +0 - DX */
    uint16_t avail_clusters;      /* +2 - BX */
    uint16_t sectors_per_cluster; /* +4 - AX */
    uint16_t bytes_per_sector;    /* +6 - CX */
};
struct DosFarPointer {
    uint32_t offset;  /* +0 */
    uint16_t segment; /* +4 - selektor/segment puvodniho 48bit far ptr */
};
#pragma pack(pop)
#endif /* REORION2_DOS_STRUCTS_DEFINED */

#ifdef __cplusplus
extern "C" {
#endif
int dos_getdiskfree(unsigned int drive, struct DosDiskFree* out); /* 0 = uspech */
unsigned int dos_getvect(unsigned int vectorNumber); /* vraci offset handleru */
int dos_setvect(unsigned int vectorNumber, unsigned int vectorNumberDup,
                unsigned int handlerOffset, unsigned int handlerSegment);
#ifdef __cplusplus
}
#endif

/* DECOMP_TODO - DLUH (vlna 07, castecne vyreseno): z 20 fseek + 1 mylne
   pojmenovaneho ftell (celkem 21 mist) je ted 19 opraveno na spravny
   3parametrovy tvar (handle, offset, origin) na zaklade rozpoznaneho LBX
   archivniho vzoru (offset tabulka nactena spolu s 2048bajtovym headerem,
   viz orion_part_19/20.c) nebo klasickeho "zjisti velikost souboru" idiomu
   (orion_part_22.c). 2 mista (orion_part_19.c ~radek 5907, orion_part_20.c
   ~radek 7230 - "Play_Sound") maji jen NIZKOU jistotu rekonstrukce (viz
   DECOMP_TODO primo u nich) - oznaceny explicitne v komentari, aby bylo
   jasne, ze potrebuji dalsi overeni, i kdyz uz technicky pouzivaji makro.
   VSECHNY fseek/ftell/fopen/fclose/fread/fwrite ted konzistentne pouzivaji
   stejny int-handle system (viz port_file.h) - fseek/ftell NEMOHOU zustat
   na skutecnem CRT FILE*, protoze fopen uz vraci jen maly int handle. */

/* ---- zakladni typy ----
   __int8/16/32/64 a jejich unsigned/signed kombinace jsou v preprocesnim
   kroku (split.py) nahrazeny primo za stdint typy, protoze "unsigned __intN"
   neni v C platna kombinace typedef + unsigned. */

typedef uint8_t  _BYTE;
typedef uint16_t _WORD;
typedef uint32_t _DWORD;
typedef uint64_t _QWORD;

/* Hex-Rays _BOOLn nejsou 'bool' - jde o vysledek flagoveho vyrazu ulozeny
   do n-bytoveho registru/promenne, chova se jako int. */
typedef int _BOOL1;
typedef int _BOOL2;
typedef int _BOOL4;

/* nezname/nerozpoznane typy - typicky jednobytove placeholdery */
typedef char _UNKNOWN;

/* __int8/16/32/64 jsou MSVC vestavene typy - split.py je typicky prevadi
   primo na stdint typy, ale par vyskytu (napr. sub_1AFA0 v orion_part_01.c)
   proslo beze zmeny. GCC/Clang je neznaji, proto tu pro ne (a jen pro ne -
   pod MSVC uz tyto typy existuji nativne) pridavame ekvivalentni typedef,
   aby slo sanity-checkovat preklad i mimo Visual Studio. */
#ifndef _MSC_VER
typedef int8_t   __int8;
typedef int16_t  __int16;
typedef int32_t  __int32;
typedef int64_t  __int64;
#endif

/* ---- kalingove konvence (na urovni zdrojoveho textu nevyznamove) ---- */
#define __fastcall
#define __cdecl
#define __stdcall
#define __thiscall
#define __usercall
#define __userpurge
#define __noreturn
#define __spoils(x)

/* ---- extrakce bajtu/slov z promennych (Hex-Rays makra) ---- */
#define LOBYTE(x)   (*((unsigned char*)&(x)))
#define LOWORD(x)   (*((unsigned short*)&(x)))
#define LODWORD(x)  (*((unsigned int*)&(x)))
#define HIBYTE(x)   (*((unsigned char*)&(x)+1))
#define HIWORD(x)   (*((unsigned short*)&(x)+1))
#define HIDWORD(x)  (*((unsigned int*)&(x)+1))
#define SHIDWORD(x) (*((int*)&(x)+1))
#define SLODWORD(x) (*((int*)&(x)))
#define SLOWORD(x)  (*((short*)&(x)))
#define SHIWORD(x)  (*((short*)&(x)+1))
#define SLOBYTE(x)  (*((signed char*)&(x)))
#define SHIBYTE(x)  (*((signed char*)&(x)+1))

#define BYTE1(x) (*((unsigned char*)&(x)+1))
#define BYTE2(x) (*((unsigned char*)&(x)+2))
#define BYTE3(x) (*((unsigned char*)&(x)+3))
#define BYTE4(x) (*((unsigned char*)&(x)+4))
#define BYTE5(x) (*((unsigned char*)&(x)+5))
#define BYTE6(x) (*((unsigned char*)&(x)+6))
#define BYTE7(x) (*((unsigned char*)&(x)+7))
#define BYTE14(x) (*((unsigned char*)&(x)+14))
#define SBYTE1(x) (*((signed char*)&(x)+1))
#define SBYTE2(x) (*((signed char*)&(x)+2))
#define SBYTE3(x) (*((signed char*)&(x)+3))
#define WORD1(x) (*((unsigned short*)&(x)+1))
#define WORD2(x) (*((unsigned short*)&(x)+2))
#define WORD3(x) (*((unsigned short*)&(x)+3))
#define WORD4(x) (*((unsigned short*)&(x)+4))
#define WORD5(x) (*((unsigned short*)&(x)+5))
#define WORD6(x) (*((unsigned short*)&(x)+6))
/* MK_FP(seg,off): DOS "vytvor far pointer ze seg:off". V protected-mode
   dumpu jde uz jen o pozustatek/pseudo-adresaci - pro preklad staci vratit
   ukazatel na fiktivni linearni adresu. */
#define MK_FP(seg, off) ((int*)(long)(((unsigned int)(seg) << 4) + (unsigned int)(off)))

#define DWORD1(x) (*((unsigned int*)&(x)+1))
#define DWORD2(x) (*((unsigned int*)&(x)+2))

/* ---- flagova pseudo-makra (presna hodnota neni pro preklad podstatna) ---- */
#define __CFSHL__(x,y) 0
#define __CFADD__(x,y) 0
#define __OFSUB__(x,y) 0
#define __CFSHR__(x,y) 0

/* pseudo-pole reprezentujici obsah zasobniku pri primem/absolutnim
   pristupu (STACK[n]) - jen pro syntakticky preklad. */
extern int HEXRAYS_STACK_STUB[0x8000];
#define STACK HEXRAYS_STACK_STUB

/* CPU flagy a _EBP jako pseudo-registr - vysledek vyrazu s vedlejsimi
   ucinky na priznaky/ukazatel zasobnikoveho ramce, zde jen stub. */
extern int _CF, _ZF, _SF, _OF, _PF;
extern void *_EBP;

typedef struct { unsigned char b[16]; } _OWORD;

#if defined(_MSC_VER)
/* MSVC nema nativni 128bitovy typ A NAVIC bere "__int128" jako rezervovane
   (byt nepodporovane) klicove slovo - nejde ho ani pouzit jako jmeno
   typedefu. split.py proto v generovanem kodu VSECHNY vyskyty "__int128"
   prejmenuje na "hr_int128_t" - tenhle typedef je pak jeho realna definice.
   Protoze struct se neprevede implicitne na int, split.py zaroven obaluje
   kazde HOLE predani takove promenne jako argumentu volani do LODWORD(...).
   Pokud i presto narazis na chybu "argument nekompatibilni s int" u
   nejakeho hr_int128_t, oznac mi presny soubor+radek. */
/* Syntakticka nahrada: dekompilovany kod pouziva tyto hodnoty pouze jako
   docasne registry. 64 bitu zachova nizsi cast a na rozdil od structu se
   chova jako cislo v aritmetickych vyrazech i pri navratove hodnote. */
typedef uint64_t hr_int128_t;
#else
/* GCC/Clang maji __int128 jako vestavany typ - hr_int128_t je na nej jen alias. */
typedef __int128 hr_int128_t;
#endif

/* close(handle): Watcom CRT - deklarace chybela v puvodnim vystupu. */
extern int close(int);
extern void _terminate(void);

/* ---- primy pristup do pameti (MEMORY[adresa]) ----
   V originale jde o cely 32bit adresni prostor DOS4GW; pro ucely prekladu
   (ne behu) je nahrazen fiktivnim polem. Skutecna semantika (BIOS tick
   pri 0x46C apod.) se dorezi az pri realne portaci. */
extern int HEXRAYS_MEMORY_STUB[0x40000];
#define MEMORY HEXRAYS_MEMORY_STUB

/* ---- nedekodovane/nerekonstruovane skoky ----
   JUMPOUT(adr) = dekompilator nedokazal prevest control-flow na strukturu.
   Stub jen zaznamena adresu, funkce s JUMPOUT je nutne rucne dohledat v IDA. */
static inline void HEXRAYS_JUMPOUT_STUB(unsigned int addr) { (void)addr; }
#define JUMPOUT(addr) HEXRAYS_JUMPOUT_STUB(addr)

/* ---- pseudo-registry / DOS4GW segmentove intrinsics ----
   Pouzity jen ojedinele (FPU inicializace apod.) - stub hodnoty. */
extern int __DS__, __ES__, __CS__, __SS__, __FS__, __GS__;
extern void *_EBP_STUB;
static inline void _enable(void) {}
static inline void _disable(void) {}
static inline void *_GETDS_STUB(void) { return (void*)0; }
#define _GETDS _GETDS_STUB

/* sub_ED48B: Hex-Rays u teto (jiz tak podezrele - "local variable
   allocation has failed") funkce nedokazal urcit typ 8. argumentu.
   DECOMP_TODO: overit v IDA, jak je a8 skutecne pouzivan. */
typedef struct { unsigned char arr[4]; } arg8_ED48B;

/* ---- MSVC/Watcom intrinsics (port I/O, GS-segmentovy pristup, flagy) ----
   DECOMP_TODO: skutecna semantika (I/O porty, alternativni linear segment
   pres GS) se dorezi az pri realne portaci/emulaci - zde jen stuby pro
   syntakticky preklad. */
/* MSVC bere tyto nazvy jako sve vlastni vestavene intrinsiky (nejdou
   predefinovat) - split.py proto v generovanem kodu VSECHNY vyskyty
   __readgsbyte/__outbyte/... prejmenuje na hr_readgsbyte/hr_outbyte/...
   nize je jejich realna (stub) definice. */
static inline void hr_outbyte(int port, unsigned char data) { (void)port; (void)data; }
static inline unsigned char hr_inbyte(int port) { (void)port; return 0; }
static inline unsigned int hr_readeflags(void) { return 0; }
static inline void hr_writeeflags(unsigned int v) { (void)v; }
static inline unsigned int hr_getcallerseflags(void) { return 0; }
static inline void hr_debugbreak(void) {}
static inline unsigned char hr_readgsbyte(unsigned int off) { (void)off; return 0; }
static inline unsigned short hr_readgsword(unsigned int off) { (void)off; return 0; }
static inline void hr_writegsbyte(unsigned int off, unsigned char v) { (void)off; (void)v; }
static inline void hr_writegsword(unsigned int off, unsigned short v) { (void)off; (void)v; }
static inline void hr_writegsdword(unsigned int off, unsigned int v) { (void)off; (void)v; }
static inline void hr_addgsword(unsigned int off, unsigned short v) { (void)off; (void)v; }

/* Oznaceni mist, kde je potreba rucni dopracovani (asm bloky, funkce s
   selhanou dekompilaci). Vyhledatelne pres grep DECOMP_TODO. */
#define DECOMP_TODO(msg)

#endif /* HEXRAYS_COMPAT_H */
