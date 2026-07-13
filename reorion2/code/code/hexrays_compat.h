/*
 * hexrays_compat.h
 * Kompatibilni vrstva pro preklad Hex-Rays dekompilovaneho vystupu
 * (Orion2.exe, Watcom C++, DOS4GW protected mode)
 */

#ifndef HEXRAYS_COMPAT_H
#define HEXRAYS_COMPAT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

 /* ============================================= */
 /*  Pøevzato a upraveno z oficiálního defs.h    */
 /* ============================================= */

#if defined(__GNUC__)
typedef          long long ll;
typedef unsigned long long ull;
#define __int64 long long
#define __int32 int
#define __int16 short
#define __int8  char
#define MAKELL(num) num ## LL
#define FMT_64 "ll"
#elif defined(_MSC_VER)
typedef          __int64 ll;
typedef unsigned __int64 ull;
#define MAKELL(num) num ## i64
#define FMT_64 "I64"
#elif defined(__BORLANDC__)
typedef          __int64 ll;
typedef unsigned __int64 ull;
#define MAKELL(num) num ## i64
#define FMT_64 "L"
#else
#error "unknown compiler"
#endif

typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long ulong;

typedef char   int8;
typedef signed char   sint8;
typedef unsigned char   uint8;
typedef short  int16;
typedef signed short  sint16;
typedef unsigned short  uint16;
typedef int    int32;
typedef signed int    sint32;
typedef unsigned int    uint32;
typedef ll     int64;
typedef ll     sint64;
typedef ull    uint64;

/* Hex-Rays základní typy */
#define _BYTE  uint8
#define _WORD  uint16
#define _DWORD uint32
#define _QWORD uint64
#if defined(_MSC_VER)
    /* MSVC nemá __int128, použijeme vlastní typ */
typedef struct {
    uint64_t low;
    int64_t  high;
} __int128;

#define _LONGLONG __int128
#else
    /* GCC, Clang, ICC atd. */
#define _LONGLONG __int128
#endif

typedef int _BOOL1;
typedef int _BOOL2;
typedef int _BOOL4;

typedef char _UNKNOWN;

/* ============================================= */
/*  Calling conventions + další makra            */
/* ============================================= */

#define __fastcall
#define __cdecl
#define __stdcall
#define __thiscall
#define __usercall
#define __userpurge
#define __noreturn
#define __spoils(x)

/* ============================================= */
/*  Bezpeènìjší byte/word pøístupy (z defs.h)    */
/* ============================================= */

#define LAST_IND(x,part_type)    (sizeof(x)/sizeof(part_type) - 1)

#define BYTEn(x, n)   (*((_BYTE*)&(x)+n))
#define WORDn(x, n)   (*((_WORD*)&(x)+n))
#define DWORDn(x, n)  (*((_DWORD*)&(x)+n))

#define LOBYTE(x)  BYTEn(x,0)
#define LOWORD(x)  WORDn(x,0)
#define LODWORD(x) DWORDn(x,0)

#define HIBYTE(x)  BYTEn(x,1)
#define HIWORD(x)  WORDn(x,1)
#define HIDWORD(x) DWORDn(x,1)

#define BYTE1(x)   BYTEn(x,1)
#define BYTE2(x)   BYTEn(x,2)
#define BYTE3(x)   BYTEn(x,3)
#define BYTE4(x)   BYTEn(x,4)
#define BYTE5(x)   BYTEn(x,5)
#define BYTE6(x)   BYTEn(x,6)
#define BYTE7(x)   BYTEn(x,7)
#define BYTE14(x)  BYTEn(x,14)

#define SBYTEn(x, n)   (*((int8*)&(x)+n))
#define SWORDn(x, n)   (*((int16*)&(x)+n))

#define SLOBYTE(x)  SBYTEn(x,0)
#define SLOWORD(x)  SWORDn(x,0)
#define SLODWORD(x) (*((int32*)&(x)))

#define SHIBYTE(x)  SBYTEn(x,1)
#define SHIWORD(x)  SWORDn(x,1)
#define SHIDWORD(x) (*((int*)&(x)+1))

#define WORD1(x)   WORDn(x,1)
#define WORD2(x)   WORDn(x,2)
#define WORD3(x)   WORDn(x,3)
#define WORD4(x)   WORDn(x,4)
#define WORD5(x)   WORDn(x,5)
#define WORD6(x)   WORDn(x,6)

/* DOS4GW specific */
//#define MK_FP(seg, off) ((void*)((unsigned long)(off)))   // lepší pro protected mode
#define MK_FP(seg, off) ((WORD*)(uintptr_t)(off))

/* Flag pseudo-makra */
#define __CFSHL__(x,y) 0
#define __CFADD__(x,y) 0
#define __OFSUB__(x,y) 0
#define __CFSHR__(x,y) 0

/* ============================================= */
/*  Stub pro STACK a MEMORY                      */
/* ============================================= */

extern char HEXRAYS_STACK_STUB[];
#define STACK ((int*)HEXRAYS_STACK_STUB)

extern char HEXRAYS_MEMORY_STUB[];
#define MEMORY ((int*)HEXRAYS_MEMORY_STUB)

/* CPU flags + EBP */
extern int _CF, _ZF, _SF, _OF, _PF;
extern void* _EBP;

typedef struct { unsigned char b[16]; } _OWORD;

/* Watcom CRT */
extern int close(int);
extern void _terminate(void);

/* JUMPOUT */
static inline void HEXRAYS_JUMPOUT_STUB(unsigned int addr) { (void)addr; }
#define JUMPOUT(addr) HEXRAYS_JUMPOUT_STUB(addr)

/* Segment registers + intrinsics */
extern int __DS__, __ES__, __CS__, __SS__, __FS__, __GS__;
extern void* _EBP_STUB;

static inline void _enable(void) {}
static inline void _disable(void) {}
static inline void* _GETDS_STUB(void) { return (void*)0; }
#define _GETDS _GETDS_STUB

/* Specifické pro Orion2 */
typedef struct { unsigned char arr[4]; } arg8_ED48B;

/* MSVC/Watcom intrinsics */
static inline void __outbyte(int port, unsigned char data) { (void)port; (void)data; }
static inline unsigned char __inbyte(int port) { (void)port; return 0; }
static inline unsigned int __readeflags(void) { return 0; }
static inline void __writeeflags(unsigned int v) { (void)v; }
static inline unsigned int __getcallerseflags(void) { return 0; }
static inline void __debugbreak(void) {}

/* TODO makro */
#define DECOMP_TODO(msg)   /* #pragma message("DECOMP_TODO: " msg) */

#endif /* HEXRAYS_COMPAT_H */