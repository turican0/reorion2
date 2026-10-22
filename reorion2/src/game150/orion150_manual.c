/* Wave 185: hand written parts of the 1.50 patch block - functions Hex-Rays could not decompile and the
   ones rewritten on the official Lua API. A function here (with its //----- (ADDR) marker) is skipped by
   tools/compare/gen150.py.
   Goal: the hook stubs and the code constants patched through ccode are temporary - they will be
   rewritten as normal C functions and variables (see the GOAL note in tools/compare/gen150.py). */
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

//----- (00077433) --------------------------------------------------------
/* 1.50 entry in front of sub_7743A: 77433 mov byte_19BF08, 1, then the 1.31 body */
int sub_77433(int a1)
{
  byte_19BF08 = 1;
  return sub_7743A(a1);
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
