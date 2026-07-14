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
typedef struct { uint64_t low; int64_t high; } hr_int128_t;
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
