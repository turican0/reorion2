/* Wave 185: hand written parts of the 1.50 patch block - functions Hex-Rays could not decompile and the
   ones rewritten on the official Lua API. A function here (with its //----- (ADDR) marker) is skipped by
   tools/compare/gen150.py.
   Goal: the hook stubs and the code constants patched through ccode are temporary - they will be
   rewritten as normal C functions and variables (see the GOAL note in tools/compare/gen150.py). */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "orion150.h"

void PortDebug_Message(const char *msg);
int sprintf(char *buf, const char *fmt, ...);

/* stub of a function that still works on the Lua internals of ORION150.EXE (orion150_lua_pending.c) */
void Lua150_Pending(uint32_t addr)
{
  static uint32_t seen[64];
  static int n;
  char buf[96];
  int i;

  for ( i = 0; i < n; ++i )
    if ( seen[i] == addr )
      return;
  if ( n < 64 )
    seen[n++] = addr;
  sprintf(buf, "1.50: Lua function 0x%X is not ported yet", (unsigned)addr);
  PortDebug_Message(buf);
}

/* inline DOS call (int 21h) of the block whose registers are not wired yet (asm_pending.txt) */
void Dos150_AsmPending(uint32_t addr)
{
  static uint32_t seen[16];
  static int n;
  char buf[96];
  int i;

  for ( i = 0; i < n; ++i )
    if ( seen[i] == addr )
      return;
  if ( n < 16 )
    seen[n++] = addr;
  sprintf(buf, "1.50: int 21h in 0x%X is not wired yet", (unsigned)addr);
  PortDebug_Message(buf);
}

#define ESTR150(a) ((char *)(eseg + (a) - 0x22A600))
#define EINT150(a) ((int)(intptr_t)(eseg + (a) - 0x22A600))

void Dos150_GetTime(uint16_t *cx, uint16_t *dx);

/* the milliseconds since midnight the block computes from CX:DX (202B74..202BA6) */
static int Ms150(uint16_t cx, uint16_t dx)
{
  return 10 * ((dx & 0xFF) + 100 * ((dx >> 8) + 60 * ((cx & 0xFF) + 60 * (cx >> 8))));
}

//----- (001E5BC7) --------------------------------------------------------
/* Lua C function: pushes the time of day in ms (integer, tag 13h) on the Lua stack of a3 (L->top at +0Ch);
   it works on the 32-bit Lua internals of ORION150.EXE - rewritten with the Lua API later */
int sub_1E5BC7(int a1, int a2, int a3)
{
  uint16_t cx, dx;
  uint32_t *top;

  Dos150_GetTime(&cx, &dx);
  top = (uint32_t *)(intptr_t)*(uint32_t *)(intptr_t)(a3 + 12);
  top[0] = Ms150(cx, dx);
  top[1] = 19;
  *(uint32_t *)(intptr_t)(a3 + 12) = (uint32_t)(uintptr_t)(top + 2);
  return 1;
}

//----- (001EB8E3) --------------------------------------------------------
/* time of day in 1/100 s (1EB929 mul 51EB851Fh / shr 5 = ms / 10), stored to *a3 when *a3 != 0 */
unsigned int sub_1EB8E3(int a1, int a2, unsigned int *a3)
{
  uint16_t cx, dx;
  unsigned int r;

  Dos150_GetTime(&cx, &dx);
  r = (unsigned int)Ms150(cx, dx) / 100;
  if ( *a3 )
    *a3 = r;
  return r;
}

//----- (001EB947) --------------------------------------------------------
/* [arg_0] = CX and [arg_0+2] = DX, both with the bytes swapped (rol 8) */
int64_t sub_1EB947(int64_t result, int a2, _WORD *a3)
{
  uint16_t cx, dx;

  Dos150_GetTime(&cx, &dx);
  a3[0] = (uint16_t)((cx << 8) | (cx >> 8));
  a3[1] = (uint16_t)((dx << 8) | (dx >> 8));
  return result;
}

//----- (002029AB) --------------------------------------------------------
/* entry of the 1.50 block, called by the loader (169716) before main__0. cdecl arguments: argc, argv,
   block base, block size, data object base, code object base. Reads the command line (/c=<config>,
   /extract=<file>), loads the configs (ORION2.CFG by default) and applies them. */
int sub_2029AB(char *a1, char *a2, int argc, uint32_t *argv, int base, int size, int data, int code)
{
  uint16_t cx, dx;
  int16_t n;
  int i, r, t0;
  int *res = 0;   /* var_28 */
  int *msg = 0;

  *(uint32_t *)ESTR150(0x240782) = base;
  *(uint32_t *)ESTR150(0x240786) = size;
  *(uint32_t *)ESTR150(0x24078A) = 0;
  *(uint32_t *)ESTR150(0x24076A) = data;
  *(uint32_t *)ESTR150(0x24076E) = 0x130FE;
  *(uint32_t *)ESTR150(0x240772) = 0x1F6694;
  *(uint32_t *)ESTR150(0x240776) = code;
  *(uint32_t *)ESTR150(0x24077A) = 0x161000;
  *(uint32_t *)ESTR150(0x24077E) = 0x95694;
  sub_1EBC6B();
  for ( i = 0x24071E; i != 0x240768; i += 2 )
    *(uint16_t *)ESTR150(i) = 0xFFFF;
  r = sub_1FA13F();   /* 202A26: eax = end of the loop above */
  Dos150_GetTime(&cx, &dx);
  sub_1EC907(0, EINT150(0x2528B5), cx >> 8, cx & 0xFF, dx >> 8, dx & 0xFF, argv[0],
             (int)(intptr_t)(ccode + 0x169549 - 0x10000), r);   /* "starting %s, version %s" */
  sub_1EC907(0, EINT150(0x2528E5), base, data, code);
  if ( !*ESTR150(0x2407BE) )   /* close ORION2.LOG */
  {
    *ESTR150(0x2407BE) = 1;
    if ( *(uint32_t *)ESTR150(0x23F992) )
    {
      fclose(*(uint32_t *)ESTR150(0x23F992));
      *(uint32_t *)ESTR150(0x23F992) = 0;
    }
    *ESTR150(0x2407BE) = 0;
  }
  sub_1E8BCF();
  sub_1FB173((int *)ESTR150(0x23E6A8));
  n = *(int16_t *)ESTR150(0x24068E);
  for ( i = 0; i < argc; ++i )
  {
    char *s = (char *)(intptr_t)argv[i];
    size_t len = strlen(s);

    if ( !*s )
      continue;
    if ( len > 2 && !strncmp(s, ESTR150(0x247030), 3) )   /* "/c=" */
    {
      if ( n == 25 )
        sub_1ECCDF(0, (const char *)(intptr_t)EINT150(0x252909), 25);   /* "at most %d configs" */
      *(int16_t *)ESTR150(0x24068E) = n + 1;
      *(uint32_t *)ESTR150(0x24069E + 4 * n) = (uint32_t)(uintptr_t)(s + 3);
      n = n + 1;
    }
    else if ( len > 8 && !strncmp(s, ESTR150(0x247034), 9) )   /* "/extract=" */
    {
      *(uint32_t *)ESTR150(0x23E6B8) = (uint32_t)(uintptr_t)(s + 9);
    }
  }
  if ( !n )
  {
    *(int16_t *)ESTR150(0x24068E) = 1;
    *(uint32_t *)ESTR150(0x24069E) = EINT150(0x24703E);   /* "ORION2.CFG" */
    n = 1;
  }
  Dos150_GetTime(&cx, &dx);
  t0 = Ms150(cx, dx);
  if ( !sub_20228B(0, (uint32_t *)&res, 0, 0, (int *)ESTR150(0x23E6A8), (int *)ESTR150(0x24069E), n) )
  {
    /* 202BD3: "failed to load config:\n%.*s" */
    if ( res )
      sub_1ECCDF(0, (const char *)(intptr_t)EINT150(0x247060), *res, (int)(intptr_t)(res + 2));
    sub_1ECCDF(0, (const char *)(intptr_t)EINT150(0x247060), 0, 0);
  }
  sub_1F8F2B();
  sub_1FB173((int *)ESTR150(0x23E698));
  Dos150_GetTime(&cx, &dx);
  sub_1EC907(0, EINT150(0x247049), Ms150(cx, dx) - t0);   /* "config loaded in %ums" */
  sub_1FF103(0, 0);
  if ( !sub_1FD03B((uint32_t *)&res) )
  {
    /* 202D2C..202E2D: the original lists the languages the config works with ($AVAIL$ in 25292D);
       here only the "configuration is broken" message (252A05) - not ported yet */
    sub_1FC7BB(&msg, ESTR150(0x252A05), ESTR150(0x246E2C), res);
    sub_1ECCDF(0, (const char *)(intptr_t)EINT150(0x246E50), msg ? *msg : 0, (int)(intptr_t)(msg ? msg + 2 : 0));
  }
  if ( !*ESTR150(0x2407BE) )
  {
    *ESTR150(0x2407BE) = 1;
    if ( *(uint32_t *)ESTR150(0x23F992) )
    {
      fclose(*(uint32_t *)ESTR150(0x23F992));
      *(uint32_t *)ESTR150(0x23F992) = 0;
    }
    *ESTR150(0x2407BE) = 0;
  }
  return 0;
}

/* vsnprintf for the block's variadic calls: the arguments are the 32-bit stack slots of the original
   (va32 of the variadic functions, pointers for %s too, a double takes two slots); each conversion is
   handed to snprintf on its own */
static int Vsnprintf150(char *buf, int size, const char *fmt, uint32_t *va)
{
  char spec[32], one[512];
  int n = 0;

  while ( *fmt )
  {
    const char *p = fmt;
    int k = 0, star[2], ns = 0, len;

    if ( *fmt != '%' || fmt[1] == '%' )
    {
      char c = *fmt;

      fmt += (*fmt == '%') ? 2 : 1;
      if ( n < size - 1 )
        buf[n] = c;
      ++n;
      continue;
    }
    spec[k++] = *fmt++;
    while ( *fmt && strchr("-+ #0", *fmt) && k < 20 )
      spec[k++] = *fmt++;
    while ( (*fmt == '*' || (*fmt >= '0' && *fmt <= '9') || *fmt == '.') && k < 24 )
    {
      if ( *fmt == '*' )
        star[ns++ & 1] = (int)*va++;
      spec[k++] = *fmt++;
    }
    while ( *fmt == 'h' || *fmt == 'l' || *fmt == 'L' )
      ++fmt;   /* every slot is 32-bit */
    spec[k++] = *fmt;
    spec[k] = 0;
    if ( !*fmt )
      break;
    switch ( *fmt++ )
    {
      case 's':
      {
        char *s = (char *)(uintptr_t)*va++;

        if ( !s )
          s = "(null)";
        if ( ns == 2 )
          len = snprintf(one, sizeof(one), spec, star[0], star[1], s);
        else if ( ns == 1 )
          len = snprintf(one, sizeof(one), spec, star[0], s);
        else
          len = snprintf(one, sizeof(one), spec, s);
        break;
      }
      case 'p':
        len = snprintf(one, sizeof(one), "%08X", (unsigned)*va++);
        break;
      case 'f': case 'e': case 'g': case 'E': case 'G':
      {
        double d;

        memcpy(&d, va, 8);
        va += 2;
        len = snprintf(one, sizeof(one), spec, d);
        break;
      }
      default:
        if ( ns == 2 )
          len = snprintf(one, sizeof(one), spec, star[0], star[1], (int)*va);
        else if ( ns == 1 )
          len = snprintf(one, sizeof(one), spec, star[0], (int)*va);
        else
          len = snprintf(one, sizeof(one), spec, (int)*va);
        ++va;
        break;
    }
    (void)p;
    if ( len > (int)sizeof(one) - 1 )
      len = (int)sizeof(one) - 1;
    for ( k = 0; k < len; ++k, ++n )
      if ( n < size - 1 )
        buf[n] = one[k];
  }
  if ( size > 0 )
    buf[n < size - 1 ? n : size - 1] = 0;
  return n;
}

//----- (001E0076) --------------------------------------------------------
/* 1E0083 call __fprtf_(arg_0 file, arg_4 format, &arg_8): vfprintf on a port file handle */
int Vsprintf150(char *buf, const char *fmt, uint32_t *va)
{
  return Vsnprintf150(buf, 0x7FFFFFFF, fmt, va);
}

int sub_1E0076(int a1, char *a2, uint32_t *a3)
{
  char buf[4096];
  int n = Vsnprintf150(buf, sizeof(buf), a2, a3);

  if ( n > 0 )
    fwrite(buf, 1, n < (int)sizeof(buf) ? n : (int)sizeof(buf) - 1, a1);
  return n;
}

//----- (001E009E) --------------------------------------------------------
/* 1E00B0 call __prtf_(&{arg_0 buffer, arg_4 room}, arg_8 format, &arg_C, putc 1E00B7): the putc stores
   only while there is room and counts every character; no terminating NUL */
int sub_1E009E(char *a1, int a2, char *a3, uint32_t *a4)
{
  char buf[4096];
  int n = Vsnprintf150(buf, sizeof(buf), a3, a4);

  if ( n > 0 && a2 > 0 )
    memcpy(a1, buf, n < a2 ? n : a2);
  return n;
}

//----- (001E090B) --------------------------------------------------------
/* hook stub inside sub_3D2DF: 1E090B tests [ebp-27h] bit 0, byte_23F0F4 and word [ebp-18h] of the game
   function's frame and jumps to 3D751 or 3D79D - wired into the game function at the hook site */
int sub_1E090B()
{
  return 0;
}

//----- (001E136E) --------------------------------------------------------
/* cdecl -> register wrapper: eax..ecx = arg_0..arg_C, call sub_F6816 */
int sub_1E136E(int a1, int a2, int a3, int a4)
{
  return sub_F6816(a1, a2, a3, a4);
}

//----- (001E3727) --------------------------------------------------------
/* cdecl -> register wrapper: eax..ecx = arg_0..arg_C, call sub_77048 */
int sub_1E3727(int a1, int a2, int a3, int a4)
{
  return sub_77048(a1, a2, a3, a4);
}

//----- (001E4BBB) --------------------------------------------------------
/* 1E4BBB eax = dword 1E4BA3 (kept in the block code), call sub_1FA583, call ServiceAudioTick (eax kept) */
int sub_1E4BBB()
{
  int r = (uint8_t)sub_1FA583(*(uint32_t *)(ecode + 0x4BA3));

  return ServiceAudioTick_FE8BE(r, 0, 0, 0);
}

//----- (001F8F2B) --------------------------------------------------------
/* applies the parsed config to the game data (asm 1F8F2B-1F90A0) */
int sub_1F8F2B()
{
  int src, dst, k;

  sub_1EEBFB();   /* 1F8F2F: its register arguments are scratch */
  dseg[0x485] = eseg[0x137D6];
  dseg[0x3D3] = (uint8_t)-eseg[0x137DC];   /* the switch flag bytes after "/nowh" ... */
  dseg[0x3DA] = (uint8_t)-eseg[0x137DB];
  dseg[0x44A] = (uint8_t)-eseg[0x137D7];
  dseg[0x456] = (uint8_t)-eseg[0x137DA];
  dseg[0x461] = (uint8_t)-eseg[0x137DE];
  dseg[0x46E] = (uint8_t)-eseg[0x137D8];
  dseg[0x47A] = (uint8_t)-eseg[0x137D9];
  dseg[0x4DD] = (uint8_t)-eseg[0x137DF];
  dseg[0x749] = (uint8_t)-eseg[0x137DD];
  dseg[0x7AD] = (uint8_t)-eseg[0x14B8E];
  byte_19A006 = eseg[0x137D5];
  dseg[0x7C1] = (uint8_t)-eseg[0x14B90];
  dseg[0x755] = (uint8_t)-eseg[0x14B8F];
  /* 1F8FD8: 130 records of 17 bytes 0x23D180 (stride 22) -> 0x180184 */
  for ( src = 0x23D180, dst = 0x180184; dst != 0x180A26; src += 22, dst += 17 )
    memcpy(dseg + dst - 0x178000, eseg + src - 0x22A600, 17);
  /* 1F900C: 130 records of 5 bytes 0x23D191 (stride 22) -> 0x180A26 */
  for ( src = 0x23D191, dst = 0x180A26; dst != 0x180CB0; src += 22, dst += 5 )
    memcpy(dseg + dst - 0x178000, eseg + src - 0x22A600, 5);
  /* 1F9040: every second byte of 0x23D121 -> 0x17D1FD..0x17D218 */
  for ( k = 0; k < 0x17D218 - 0x17D1FD; ++k )
    dseg[0x17D1FD - 0x178000 + k] = eseg[0x23D121 - 0x22A600 + 2 * k];
  sub_1E6CD3(0, 0, 0, 0);   /* register pass-through to sub_5E1E3, no effect */
  if ( *(uint32_t *)(eseg + 0x13DE8) )   /* dword 23E3E8 */
  {
    sub_1F8EB3((int)(intptr_t)(eseg + 0x13DE8));
    nfree(*(uint32_t *)(eseg + 0x13DE8));
    *(uint32_t *)(eseg + 0x13DE8) = 0;
  }
  *(uint32_t *)(eseg + 0x13DEC) = 0;   /* dword 23E3EC */
  return 0;
}

/* refcounted string slot: release the old string, store the new one (1FB8DE..1FB8F5 / 1FD9BF..1FD9D6) */
static void SetRefString150(uint32_t *slot, int *s)
{
  int *old;

  if ( !slot )
  {
    sub_1ECCDF(1, (const char *)(intptr_t)(int)(intptr_t)ESTR150(0x250759), (int)(intptr_t)ESTR150(0x2467E7));   /* 1FB902 call sub_1EE113 (fatal) */
    return;
  }
  old = (int *)(uintptr_t)*slot;
  if ( old == s )
    return;
  if ( old )
  {
    if ( !old[1] )
      sub_1ECCDF(1, (const char *)(intptr_t)(int)(intptr_t)ESTR150(0x25071D), (int)(intptr_t)ESTR150(0x2467D9), old[1]);
    if ( !--old[1] )
      nfree((int)(intptr_t)old);
  }
  *slot = (uint32_t)(uintptr_t)s;
}

//----- (001FB8CF) --------------------------------------------------------
int sub_1FB8CF(uint32_t *a1, int *a2)
{
  SetRefString150(a1, a2);
  return (int)(intptr_t)a2;
}

//----- (001FD8FF) --------------------------------------------------------
/* message with its context: without a message yet (*a1 == 0) every context of the chain a2 gets
   "<prefix> <file>:<line>: <text>" in its slot [ctx+0Ch] (1FD967..1FD9DC); then sub_1FC66B(a1, text,
   strlen(text), a4) (1FD956 tail jump) */
int *sub_1FD8FF(uint32_t *a1, int a2, char *a3, unsigned int *a4)
{
  if ( !*a1 && a2 )
  {
    char *s = a3;
    int ctx = a2;

    do
    {
      int *f = 0;   /* var_20 */
      int name = *(int *)(uintptr_t)*(uint32_t *)(a2 + 12);
      int line = *(int *)(*(int *)(ctx + 8) + 4) + 1;
      int file = *(int *)(ctx + 4);

      sub_1FC7BB(&f, ESTR150(0x246CAA), ESTR150(0x246CA8), ESTR150(a2 == ctx ? 0x246C8C : 0x246C8F),
                 ESTR150(0x246C82), file, ESTR150(0x246CA4), line, ESTR150(0x246C9D), name, 0, s);
      s = (char *)f;
      SetRefString150((uint32_t *)(uintptr_t)*(uint32_t *)(a2 + 12), f);   /* 1FD9B5 edi = [ebp+0Ch] */
      ctx = *(int *)ctx;
    }
    while ( ctx );
  }
  return sub_1FC66B(a1, a3, (int)strlen(a3), a4);
}

/* empty functions of the block (retn only) */
void nullsub_41()
{
}

void nullsub_42()
{
}

//----- (00169569) --------------------------------------------------------
/* LE code of 1.50 (cdecl wrapper): eax = arg_0, edx = arg_4, ebx = arg_8, call fseek_ */
int sub_169569(int a1, int a2, int a3)
{
  return fseek(a1, a2, a3);
}

//----- (001E1307) --------------------------------------------------------
/* 1E1307 pusha / call sub_1E80C7 / popa / jmp fopen_ (eax = name, edx = mode) */
int sub_1E1307(int a1, int a2)
{
  sub_1E80C7();
  return fopen((char *)(intptr_t)a1, (char *)(intptr_t)a2);
}

//----- (001E1313) --------------------------------------------------------
/* hook stub: 1E1313 call sub_1FC7FB, then jmp loc_5C187 back into sub_5BD97 with ecx = eax,
   eax = 2, edx = ebp+66h - the game function continues there (wired at the hook site) */
int sub_1E1313(int a1, int a2)
{
  (void)a1;
}

//----- (001E21D7) --------------------------------------------------------
/* hook stub: 1E21D7 pusha / mov eax, ecx / call sub_1E915F / popa / jmp loc_4CA8A back into the game */
int sub_1E21D7(int a1, int a2, int a3, int a4)
{
  sub_1E915F(a4, a2);
  return a1;
}

//----- (001E2BE7) --------------------------------------------------------
/* 1E2BE7 mov ah, 8 / int 21h: wait for a key before the fatal exit - the port prints the message to
   stderr and does not wait */
int64_t sub_1E2BE7()
{
  return 0;
}

//----- (001EB84B) --------------------------------------------------------
/* fatal exit: arg_0 = exit code, arg_4 = message (1EB84F ebx); "Press any key" text when the code is
   not 0 (1EB86B push 250059h), else "%s" (1EB889 push 246631h) */
void sub_1EB84B(int64_t a1, int64_t a2, int a3, int a4, int a5, char *a6)
{
  int code = (int)a1;
  char *msg = (char *)(intptr_t)(int)(a1 >> 32);

  if ( BYTE1(dword_23F992[20]) )
    sub_113DBD();
  if ( msg )
  {
    if ( code )
    {
      printf((char *)(eseg + 0x250059 - 0x22A600), msg);
      sub_1E2BE7();
    }
    else
    {
      printf((char *)(eseg + 0x246631 - 0x22A600), msg);
    }
  }
  exit(code);
}

//----- (001EC8EC) --------------------------------------------------------
/* 1EC8F6 call sub_1EC897(arg_0), 1EC8FB edx = arg_4, jmp fopen_ */
int sub_1EC8EC(char *a1, char *a2)
{
  return fopen((char *)sub_1EC897(a1), a2);
}

//----- (001EC97B) --------------------------------------------------------
/* Hex-Rays lost the result of sub_E0DD6 (1EC990 movzx edx, ax). Refund of the bought production
   (+12Ch) to the owner's treasury (+32h) - first half at 2 BC, then up to a tenth at 5, the rest at 10 */
int sub_1EC97B(char *a1)
{
  unsigned int v3, w12C, w125, total;
  int half, cnt, rest, refund;
  uint8_t *result;

  v3 = (uint16_t)sub_E0DD6(a1, *(int16_t *)(a1 + 277));
  w12C = *(uint16_t *)(a1 + 300);
  w125 = *(uint16_t *)(a1 + 293);
  if ( v3 != w12C + w125 )
  {
    sub_1EC907(0, EINT150(0x2500A9), (int)((uint8_t *)a1 - (uint8_t *)dword_192B18) / 361, w125, w12C, v3);
    if ( !byte_2407BE[0] )
    {
      byte_2407BE[0] = 1;
      if ( dword_23F992[0] )
      {
        fclose(dword_23F992[0]);
        dword_23F992[0] = 0;
      }
      byte_2407BE[0] = 0;
    }
    w12C = *(uint16_t *)(a1 + 300);
    w125 = *(uint16_t *)(a1 + 293);
  }
  total = w12C + w125;
  refund = 0;
  if ( (int)w125 < (int)total )
  {
    half = (int)total >> 1;
    cnt = half > (int)w12C ? (int)w12C : half;
    refund = 2 * cnt;
    rest = (int)w12C - cnt;
    if ( rest )
    {
      cnt = half - (int)(total / 10);
      if ( cnt > rest )
        cnt = rest;
      refund += 5 * cnt;
      rest -= cnt;
      if ( rest )
        refund += 10 * rest;
    }
  }
  *(_WORD *)(a1 + 300) = 0;
  result = (uint8_t *)dword_197F98 + 3753 * *a1;
  *(_DWORD *)(result + 50) += refund;
  return (int)(intptr_t)result;
}

//----- (001EE5AF) --------------------------------------------------------
/* Hex-Rays lost the result of sub_E0DD6 (1EE5DF movzx edi, ax). Two texts (23DD14, 23DD1E) with the
   keys 24683A = a1, 24682C = +125h, 24681E = +12Ch, 246811 = sum, 246802 = sub_E0DD6 */
int *sub_1EE5AF(unsigned int a1)
{
  uint8_t *v2;
  unsigned int v3, w125, w12C;
  unsigned int v6[32];

  a1 = (uint16_t)a1;
  v2 = (uint8_t *)dword_192B18 + 361 * dword_19F7A8;
  v3 = (uint16_t)sub_E0DD6((char *)v2, *(int16_t *)(v2 + 277));
  w125 = *(uint16_t *)(v2 + 293);
  w12C = *(uint16_t *)(v2 + 300);
  sub_1EE50F((_BYTE *)v6, (_BYTE *)0x64, (uint32_t *)dword_23DD14,
             (int)(intptr_t)(eseg + 0x1C23A), a1, (int)(intptr_t)(eseg + 0x1C22C), w125,
             (int)(intptr_t)(eseg + 0x1C21E), w12C, (int)(intptr_t)(eseg + 0x1C211), w125 + w12C,
             (int)(intptr_t)(eseg + 0x1C202), v3, 0);
  return sub_1EE50F((_BYTE *)v6, (_BYTE *)0x64, (uint32_t *)dword_23DD1E,
                    (int)(intptr_t)(eseg + 0x1C23A), a1, (int)(intptr_t)(eseg + 0x1C22C), w125,
                    (int)(intptr_t)(eseg + 0x1C21E), w12C, (int)(intptr_t)(eseg + 0x1C211), w125 + w12C,
                    (int)(intptr_t)(eseg + 0x1C202), v3, 0);
}

//----- (001ECCDF) --------------------------------------------------------
/* the block's fatal error (arg_0 kind, arg_4 format, the arguments): Hex-Rays lost most of it. The original
   writes the message to the log and either raises it as a Lua error or ends the game - the port reports it
   and ends the game */
void Hook150_Exit(char *msg, int normal);
_WORD *sub_1ECCDF(int a1, const char *a2, ...)
{
  char buf[4000];
  uint32_t va32[32];
  va_list va;
  int i;

  (void)a1;
  va_start(va, a2);
  for ( i = 0; i < 32; ++i )
    va32[i] = (uint32_t)va_arg(va, uintptr_t);
  va_end(va);
  Vsnprintf150(buf, sizeof(buf), a2, va32);
  PortDebug_Backtrace("sub_1ECCDF", 10);   /* who reached the block's fatal check */
  PortDebug_Message(buf);
  exit(1);
  return 0;
}

/* GCC nested functions: the block builds a trampoline on the stack (mov ecx, frame / jmp) and hands it over as a
   callback. In the port the frame of the parent goes through a static pointer. */
static uint8_t *g_frame1FAB6F;
static _DWORD *g_frame1F920F;

/* 1E515B: marks which side of the battle a ship of this fleet is on */
static uint8_t Nested150_1E515B(int a1, int a2)
{
  g_frame1FAB6F[2 + (*(char *)(intptr_t)(a2 + 32) == (int16_t)dword_19988E)] = 1;
  return 0;
}

/* 1E517B */
static uint8_t Nested150_1E517B(int a1, int a2)
{
  return g_frame1FAB6F[*(char *)(intptr_t)(a2 + 32) == (int16_t)dword_19988E] ^ 1;
}

//----- (001FAB6F) --------------------------------------------------------
int sub_1FAB6F(int a1)
{
  uint8_t f[4];
  int v1, v4;
  int16_t v2;

  g_frame1FAB6F = f;
  if ( sub_1FA9B3(0, 0) )
    return 1;
  if ( a1 == 1 )
  {
    v4 = SHIWORD(dword_1998D6);
    if ( (_WORD)v4 != 0xFFFF && *(int16_t *)(2 * v4 + (dseg + 0x1A96C)) >= 0 )
      *(_WORD *)(2 * v4 + (dseg + 0x1A96C)) = -1;
  }
  f[0] = *(_BYTE *)(SLOWORD(dword_1998AC) + (eseg + 0x157AE)) != 0;
  f[1] = *(_BYTE *)(SLOWORD(dword_19988E) + (eseg + 0x157AE)) != 0;
  f[2] = f[3] = 0;
  sub_1E8813(0, Nested150_1E515B);
  if ( f[0] && f[1] && f[2] )
    f[0] = 0;
  else
  {
    if ( !f[2] )
      f[1] = 0;
    if ( !f[3] )
      f[0] = 0;
  }
  v1 = sub_1E8813((a1 != 3) + SHIWORD(dword_1998D6), Nested150_1E517B);
  if ( v1 != -1 )
  {
    v2 = *(_WORD *)(2 * v1 + (dseg + 0x1A96C));
    if ( v2 >= 0 )
    {
      HIWORD(dword_1998D6) = v1;
      LOWORD(dword_1998F8) = v2;
      return 0;
    }
  }
  return 1;
}

//----- (001FCC27) --------------------------------------------------------
int sub_1FCC27(_DWORD *a1)
{
  _DWORD *v1 = g_frame1F920F;
  int *v3;
  unsigned int *v4;
  unsigned int v5;
  _BYTE *v6, *v7, *v8;
  int *v9;
  int *v10 = 0;

  if ( a1[2] == (int)(intptr_t)(eseg + 0x11EC0) && (*(_BYTE *)(intptr_t)(*(_DWORD *)(intptr_t)(4 * a1[3] + (int)(intptr_t)(eseg + 0x184C6)) + 32) & 2) == 0 )
  {
    v3 = (int *)(intptr_t)a1[1];
    v4 = (unsigned int *)(intptr_t)*v3;
    if ( *v3 )
    {
      v5 = v1[2];
      if ( *v4 >= v5 )
      {
        v6 = (_BYTE *)(v4 + 2);
        v7 = (_BYTE *)(intptr_t)v1[1];
        if ( v5 )
        {
          v8 = &v7[v5];
          while ( *v6 == *v7 )
          {
            ++v6;
            if ( ++v7 == v8 )
              goto LABEL_10;
          }
        }
        else
        {
LABEL_10:
          v10 = 0;
          sub_1FC7BB(&v10, &byte_246B07[287], (int)(intptr_t)(eseg + 0x1C622), *v1, (int)(intptr_t)(eseg + 0x1C61B), *(_DWORD *)(intptr_t)*v3 - v5, *v3 + v5 + 8, v6);
          v9 = v10;
          if ( v10 != (int *)(intptr_t)*v3 )
          {
            sub_1EE0DB(*v3);
            *v3 = (int)(intptr_t)v9;
          }
        }
      }
    }
  }
  return 0;
}

//----- (001F920F) --------------------------------------------------------
uint8_t sub_1F920F(_BYTE *a1, int a2)
{
  _DWORD chain[3];

  chain[0] = a2;
  chain[1] = (int)(intptr_t)a1;
  chain[2] = (int)strlen((char *)a1);
  g_frame1F920F = chain;
  return sub_1F8D47(0, 16, (uint8_t (*)(_DWORD *))sub_1FCC27, 0);
}

//----- (001EB207) --------------------------------------------------------
/* dword_190298 holds port pointers (8 bytes each): the table is not in dseg */
char * sub_1EB207(unsigned int a1, unsigned int a2, int a3, unsigned int a4)
{
  extern void *dword_190298[48];
  uint16_t *v6; // ecx
  uint16_t *v9; // edi
  int v10; // ebp
  int v11; // esi
  int v13; // [esp+0h] [ebp-14h]

  a1 = (uint16_t)a1;
  a2 = (uint16_t)a2;
  a4 = (uint16_t)a4;
  v6 = (uint16_t *)(((int)(intptr_t)dword_193068) + 5 * a4);
  if ( v6[0] > a1 )
    return 0;
  if ( v6[1] > a2 )
    return 0;
  v9 = (uint16_t *)dword_190298[4 * a4 + 3];
  v10 = v9[0];
  v13 = (int)(a1 - v6[0]) / 3;
  if ( v10 <= v13 )
    return 0;
  v11 = (int)(a2 - v6[1]) / 3;
  if ( v9[1] <= v11 )
    return 0;
  return (char *)(intptr_t)(*((_BYTE *)v9 + v13 + v11 * v10 + *((_DWORD *)v9 + 3)) > 5u);
}
