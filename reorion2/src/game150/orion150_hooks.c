/* Wave 185: hooks of the 1.50 patch the 1.31 game functions call (orion150_hooks.h). */
#include "orion150.h"
#include "orion150_hooks.h"

#define ESEG150(a) (eseg + (a) - 0x22A600)
#define EINT150(a) ((int)(intptr_t)ESEG150(a))
#define ECODE150(a) (ecode + (a) - 0x1E0000)
#define CCODE150(a) (ccode + (a) - 0x10000)

void Dos150_GetTime(uint16_t *cx, uint16_t *dx);
void PortDebug_Message(const char *msg);

int g_orion150;

uint8_t *Hook150_Eseg(uint32_t addr)
{
  return ESEG150(addr);
}

//----- (001E0824) --------------------------------------------------------
/* mov al, byte 23DDD5 / mov byte_19A006, al before call sub_107E6 */
char Hook150_MonstersSetting(void)
{
  return *ESEG150(0x23DDD5);
}

//----- (001E2BDA) --------------------------------------------------------
/* call sub_1205E6 / mov byte 23F9E3, 1 (read by sub_1EB84B) */
void Hook150_VideoReady(void)
{
  *ESEG150(0x23F9E3) = 1;
}

//----- (001E2BA8) --------------------------------------------------------
/* 1E2BA8: edx = 1 for the return addresses 86BAE, 103DF, 108C9, 109FE, then 1FEA6F: an internal error
   (dl = 0) ends through sub_1ECCDF; a normal end logs "exiting normally, bye!", releases the config,
   closes ORION2.LOG and exits with the message (sub_1EB84B) */
void Hook150_Exit(char *msg, int normal)
{
  uint16_t cx, dx;

  PortDebug_Message(msg);
  if ( !normal )
    sub_1ECCDF(0, 1, EINT150(0x246DB8), (int)(intptr_t)msg, 0);   /* "MOO2 internal error:\n%s" */
  Dos150_GetTime(&cx, &dx);
  sub_1EC907(0, EINT150(0x251F8D), cx >> 8, cx & 0xFF, dx >> 8, dx & 0xFF);
  sub_1FB983(0, 0, 0, 0, 0);
  if ( !*ESEG150(0x2407BE) )
    sub_1E5643();
  sub_1EB84B((int64_t)(uint32_t)(uintptr_t)msg << 32, (int64_t)0, 0, 0, 0, (char *)0);
}

/* ===== wrappers of the game functions 1.50 hooks at every call (the body is X_131) ===== */

//----- (001E3E8A) --------------------------------------------------------
/* sub eax, dword 23FA4E / jmp 12C2C6 */
int sub_12C2C6(int result)
{
  if ( g_orion150 )
    result -= *(int32_t *)ESEG150(0x23FA4E);
  return sub_12C2C6_131(result);
}

//----- (001E1F16) --------------------------------------------------------
/* replaces sub_6F11C: movsx eax, ax / movzx ax, byte [eax+23CE20h] */
char sub_6F11C(int a1)
{
  if ( !g_orion150 )
    return sub_6F11C_131(a1);
  return (char)*ESEG150(0x23CE20 + (int16_t)a1);
}

//----- (001E04B4) --------------------------------------------------------
/* call sub_E0B4F / at most 42 */
int sub_E0B4F(int16_t *a1, int a2)
{
  int r = sub_E0B4F_131(a1, a2);

  return g_orion150 && r > 42 ? 42 : r;
}

//----- (001E04A4) --------------------------------------------------------
/* call sub_E0C1D / at most 42 */
int sub_E0C1D(char *a1, int a2)
{
  int r = sub_E0C1D_131(a1, a2);

  return g_orion150 && r > 42 ? 42 : r;
}

//----- (001E32F2) --------------------------------------------------------
/* replaces sub_93D4B: std / scasw over the 5 words 925A4..925AC of the game code from the top while
   ax < word; then 5 -> 4 + dl, else + dl only with byte 23F0D0 == 1 */
int sub_93D4B(int a1, int a2)
{
  int c = 5;
  uint32_t p = 0x925AC;

  if ( !g_orion150 )
    return sub_93D4B_131(a1, a2);
  for ( ;; )
  {
    int16_t w = *(int16_t *)CCODE150(p);

    p -= 2;
    if ( (int16_t)a1 >= w || --c == 0 )
      break;
  }
  if ( c >= 5 )
    c = 4;
  else if ( *ESEG150(0x23F0D0) != 1 )
    return c;
  if ( (char)a2 )
    ++c;
  return c;
}

//----- (001E4AE8) --------------------------------------------------------
/* byte 1E1932 = 0; a second entry while byte 1E4AE7 is set is fatal (1EE073); nullsub_42; call E938C */
int16_t sub_E938C(int a1, int a2, int a3, int a4, uint8_t *a5, int a6)
{
  int16_t r;

  if ( !g_orion150 )
    return sub_E938C_131(a1, a2, a3, a4, a5, a6);
  *ECODE150(0x1E1932) = 0;
  if ( *ECODE150(0x1E4AE7) )
    sub_1ECCDF(0, 1, EINT150(0x2467C1));
  *ECODE150(0x1E4AE7) = 1;
  nullsub_42();
  r = sub_E938C_131(a1, a2, a3, a4, a5, a6);
  *ECODE150(0x1E4AE7) = 0;
  return r;
}

//----- (001E190C) --------------------------------------------------------
/* replaces sub_6E1A0: push ecx / call sub_1E88EF (eax, edx) */
int sub_6E1A0(int a1, int *a2)
{
  if ( !g_orion150 )
    return sub_6E1A0_131(a1, a2);
  return sub_1E88EF(a1, (_DWORD *)a2);
}

//----- (001E1513) --------------------------------------------------------
/* test ax, ax / jnz sub_34454; else sub_1ED94F(eax = ebx, edx) */
char sub_34454(int a1, uint16_t *a2, uint16_t *a3)
{
  if ( !g_orion150 || (int16_t)a1 )
    return sub_34454_131(a1, a2, a3);
  return (char)sub_1ED94F(a3, a2, 0, 0, 0, 0, 0);
}

//----- (001E253A) --------------------------------------------------------
/* pusha / call sub_1ECAC7 (eax, edx) / popa / jmp sub_B1E19 */
int16_t sub_B1E19(int a1, int a2)
{
  if ( g_orion150 )
    sub_1ECAC7(a1, a2);
  return sub_B1E19_131(a1, a2);
}

//----- (001E4F03) --------------------------------------------------------
/* xor ecx, ecx / call sub_3E095 / 0 -> 1 */
int sub_3E095(unsigned int a1, int a2, int a3, int a4)
{
  int r;

  if ( !g_orion150 )
    return sub_3E095_131(a1, a2, a3, a4);
  r = sub_3E095_131(a1, a2, a3, 0);
  return r ? r : 1;
}

//----- (001E1164) --------------------------------------------------------
/* replaces sub_11BE4 (5 of 6 calls; F4D82 lies in code 1.50 overwrote): pusha / call sub_1E80A3 / popa
   = sub_1E8053, sub_11BE4, sub_1E7FFF; eax keeps the caller's value */
char sub_11BE4(void)
{
  if ( !g_orion150 )
    return sub_11BE4_131();
  sub_1E80A3(0, 0);
  return 0;
}

//----- (001E0638) --------------------------------------------------------
/* cmp byte 1E0621, 1 / jz sub_5DF0A / retn: the caller runs sub_5DF0A only when this returns 1 */
int Hook150_1E0638(void)
{
  return ecode[0x1E0621 - 0x1E0000] == 1;
}
