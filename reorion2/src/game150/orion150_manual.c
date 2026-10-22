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

//----- (001E0076) --------------------------------------------------------
/* 1E0083 call __fprtf_(arg_0 file, arg_4 format, &arg_8): vfprintf on a port file handle */
int sub_1E0076(int a1, char *a2, va_list a3)
{
  char buf[4096];
  int n = vsnprintf(buf, sizeof(buf), a2, a3);

  if ( n > 0 )
    fwrite(buf, 1, n < (int)sizeof(buf) ? n : (int)sizeof(buf) - 1, a1);
  return n;
}

//----- (001E009E) --------------------------------------------------------
/* 1E00B0 call __prtf_(&{arg_0 buffer, arg_4 room}, arg_8 format, &arg_C, putc 1E00B7): the putc stores
   only while there is room and counts every character; no terminating NUL */
int sub_1E009E(char *a1, int a2, char *a3, va_list a4)
{
  char buf[4096];
  int n = vsnprintf(buf, sizeof(buf), a3, a4);

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
  int r = (uint8_t)sub_1FA583(*(uint32_t *)(ecode + 0x4BA3), 0, 0, 0, 0);

  return ServiceAudioTick_FE8BE(r, 0, 0, 0);
}

//----- (001F8F2B) --------------------------------------------------------
/* applies the parsed config to the game data (asm 1F8F2B-1F90A0) */
int sub_1F8F2B()
{
  int src, dst, k;

  sub_1EEBFB(0, 0, 0, 0, 0, 0, 0, 0);   /* 1F8F2F: its register arguments are scratch */
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
  sub_1E6CD3();
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
static void SetRefString150(int **slot, int *s)
{
  int *old;

  if ( !slot )
  {
    sub_1EE113();
    return;
  }
  old = *slot;
  if ( old == s )
    return;
  if ( old )
  {
    if ( !old[1] )
      sub_1ECCDF(0, 1, (int)(intptr_t)ESTR150(0x25071D), (int)(intptr_t)ESTR150(0x2467D9), old[1]);
    if ( !--old[1] )
      nfree((int)(intptr_t)old);
  }
  *slot = s;
}

//----- (001FB8CF) --------------------------------------------------------
int sub_1FB8CF(int **a1, int *a2)
{
  SetRefString150(a1, a2);
  return (int)(intptr_t)a2;
}

//----- (001FD8FF) --------------------------------------------------------
/* message with its context: without a message yet (*a1 == 0) every context of the chain a2 gets
   "<prefix> <file>:<line>: <text>" in its slot [ctx+0Ch] (1FD967..1FD9DC); then sub_1FC66B(a1, text,
   strlen(text), a4) (1FD956 tail jump) */
int *sub_1FD8FF(int **a1, int a2, char *a3, unsigned int *a4)
{
  if ( !*a1 && a2 )
  {
    char *s = a3;
    int ctx = a2;

    do
    {
      int *f = 0;   /* var_20 */
      int name = **(int **)(a2 + 12);
      int line = *(int *)(*(int *)(ctx + 8) + 4) + 1;
      int file = *(int *)(ctx + 4);

      sub_1FC7BB(&f, ESTR150(0x246CAA), ESTR150(0x246CA8), ESTR150(a2 == ctx ? 0x246C8C : 0x246C8F),
                 ESTR150(0x246C82), file, ESTR150(0x246CA4), line, ESTR150(0x246C9D), name, 0, s);
      s = (char *)f;
      SetRefString150((int **)(intptr_t)*(int *)(a2 + 12), f);   /* 1FD9B5 edi = [ebp+0Ch] */
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
  return sub_1FC7FB(a1, a2);
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
