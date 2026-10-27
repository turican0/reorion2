/* Wave 185: hooks of the 1.50 patch the 1.31 game functions call (orion150_hooks.h). */
#include "orion150.h"
#include "orion150_hooks.h"

#define ESEG150(a) (eseg + (a) - 0x22A600)
#define EINT150(a) ((int)(intptr_t)ESEG150(a))
#define ECODE150(a) (ecode + (a) - 0x1E0000)
#define DSEG150(a) (dseg + (a) - 0x178000)
#define CCODE150(a) (ccode + (a) - 0x10000)

void Dos150_GetTime(uint16_t *cx, uint16_t *dx);
void PortDebug_Message(const char *msg);

int g_orion150;

uint8_t *Hook150_Eseg(uint32_t addr)
{
  return ESEG150(addr);
}

int Hook150_CodeByte(uint32_t addr, int value131)
{
  return g_orion150 ? (int8_t)*CCODE150(addr) : value131;
}

void Hook150_1E33D1(void)
{
  word_19990E = (int16_t)sub_74F51(word_192248[word_1999D8]);
  word_199960 = -1;
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

//----- (001E03DB) --------------------------------------------------------
/* test byte 23F18D, 1 / jz sub_56BFA / jmp sub_56B26 */
int16_t sub_56BFA(int a1)
{
  if ( g_orion150 && (*ESEG150(0x23F18D) & 1) )
    return sub_56B26(a1);
  return sub_56BFA_131(a1);
}

//----- (001E4833) --------------------------------------------------------
/* cmp edx, 0 / jnz sub_E401D / retn (eax unchanged) */
int sub_E401D(int a1, int a2, int a3)
{
  if ( g_orion150 && !a2 )
    return a1;
  return sub_E401D_131(a1, a2, a3);
}

//----- (001E07CB) --------------------------------------------------------
/* replaces sub_E0C9B: sub_1F9B77(eax, edx, 0) */
int8_t sub_E0C9B(int a1, int a2)
{
  if ( !g_orion150 )
    return sub_E0C9B_131(a1, a2);
  return sub_1F9B77((char *)(intptr_t)a1, a2, 0);
}

//----- (001E07DA) --------------------------------------------------------
/* replaces sub_FED77: sub_1F9B77(eax, edx, ebx) */
_BOOL1 sub_FED77(char *a1, int a2, int a3)
{
  if ( !g_orion150 )
    return sub_FED77_131(a1, a2, a3);
  return sub_1F9B77(a1, a2, a3);
}

//----- (001E3CEB) --------------------------------------------------------
/* replaces sub_56A78 (not at 61034): sub_1EDE6F(eax) */
int16_t sub_56A78(int a1)
{
  if ( !g_orion150 )
    return sub_56A78_131(a1);
  return (int16_t)sub_1EDE6F(a1);
}

//----- (001E2E96) --------------------------------------------------------
/* call 13FD9 / sub_E1CED(dword_192B18 + 361 * eax) */
void sub_13FD9(int a1, unsigned int a2)
{
  sub_13FD9_131(a1, a2);
  if ( g_orion150 )
    sub_E1CED((char *)(dword_192B18 + 361 * a1));
}

//----- (001E43D8) --------------------------------------------------------
/* pusha / call sub_A20CD / popa / jmp sub_E7CDB */
void sub_E7CDB(int16_t *a1, int a2, uint16_t *a3, uint16_t *a4)
{
  if ( g_orion150 )
    sub_A20CD();
  sub_E7CDB_131(a1, a2, a3, a4);
}

//----- (001E2589) --------------------------------------------------------
/* replaces sub_B230D: sub_1EB48B(eax, edx) */
void sub_B230D(int a1, int a2)
{
  if ( !g_orion150 )
  {
    sub_B230D_131(a1, a2);
    return;
  }
  sub_1EB48B(a1, a2);
}

//----- (001E3448) --------------------------------------------------------
/* cmp word_199A02, 0 / jnz sub_74502 / retn */
void sub_74502(void)
{
  if ( !g_orion150 || word_199A02 )
    sub_74502_131();
}

//----- (001E13A3) --------------------------------------------------------
/* replaces sub_63E4C: word 23E040 / 23E042 / 23E044 by byte_199CB5 (< 1, 1, > 1) */
int sub_63E4C(void)
{
  if ( !g_orion150 )
    return sub_63E4C_131();
  if ( (int8_t)byte_199CB5 == 1 )
    return *(uint16_t *)ESEG150(0x23E042);
  if ( (int8_t)byte_199CB5 > 1 )
    return *(uint16_t *)ESEG150(0x23E044);
  return *(uint16_t *)ESEG150(0x23E040);
}

//----- (001E3D5B) --------------------------------------------------------
/* cmp word_1998E0, 0 / jnz ret; cmp eax, 44h / ja ret; call sub_112399 (eax unchanged when skipped) */
int sub_112399(int a1)
{
  if ( g_orion150 && (word_1998E0 || (unsigned int)a1 > 0x44) )
    return a1;
  return sub_112399_131(a1);
}

//----- (001E2CD5) --------------------------------------------------------
/* replaces sub_DFDC6: push ecx / mov ecx, ebx / call sub_1E9727 */
int sub_DFDC6(int a1, int a2, int a3)
{
  if ( !g_orion150 )
    return sub_DFDC6_131(a1, a2, a3);
  return sub_1E9727(a1, a2, a3, (_WORD *)(intptr_t)a3);
}

//----- (001E2D9B) --------------------------------------------------------
/* replaces sub_DEC95: push ecx / mov ecx, ebx / call sub_1E99A7 */
int sub_DEC95(int a1, int a2, int a3)
{
  if ( !g_orion150 )
    return sub_DEC95_131(a1, a2, a3);
  return sub_1E99A7(a1, a2, a3, (_WORD *)(intptr_t)a3);
}

//----- (001E0415) --------------------------------------------------------
/* sub_1E7B2B(eax, edx, -, ecx = 1) bit 0 clear -> 0, else call sub_2C129 */
int sub_2C129(int a1, int a2)
{
  if ( g_orion150 && !(sub_1E7B2B(a1, a2, 0, 1) & 1) )
    return 0;
  return sub_2C129_131(a1, a2);
}

//----- (001E16C4) --------------------------------------------------------
/* call sub_CD435 / byte 23FF6F = 0; byte_199CB1 9 -> 8 with byte 23FF6F = 1 */
int sub_CD435(int16_t *a1)
{
  int r = sub_CD435_131(a1);

  if ( g_orion150 )
  {
    *ESEG150(0x23FF6F) = 0;
    if ( byte_199CB1 == 9 )
    {
      byte_199CB1 = 8;
      *ESEG150(0x23FF6F) = 1;
    }
  }
  return r;
}

//----- (001E3A3A) --------------------------------------------------------
/* edx = buffer 1E39FE unless byte_199CB4 == 1 and byte_199F3A > 1 */
void sub_98282(int a1, int a2, int a3)
{
  if ( g_orion150 && !(byte_199CB4 == 1 && (int8_t)byte_199F3A > 1) )
    a2 = (int)(intptr_t)ECODE150(0x1E39FE);
  sub_98282_131(a1, a2, a3);
}

//----- (001E3A0A) --------------------------------------------------------
/* the 3 words at 1E39F8 = 0, then as 1E3A3A */
int sub_980DB(int a1, int a2, uint16_t *a3)
{
  if ( g_orion150 )
  {
    memset(ECODE150(0x1E39F8), 0, 6);
    if ( !(byte_199CB4 == 1 && (int8_t)byte_199F3A > 1) )
      a2 = (int)(intptr_t)ECODE150(0x1E39FE);
  }
  return sub_980DB_131(a1, a2, a3);
}

//----- (001E3426) --------------------------------------------------------
/* call sub_82DFF / jmp sub_1E33D1 (not at 82607) */
int16_t sub_82DFF(int16_t *a1, int16_t *a2, int a3)
{
  int16_t r = sub_82DFF_131(a1, a2, a3);

  if ( g_orion150 )
    Hook150_1E33D1();
  return r;
}

//----- (001E4EF2) --------------------------------------------------------
/* dword 1E4EEE = dword_1B9E34 / jmp sub_FC470 */
void sub_FC470(int a1, int a2, int a3, int a4)
{
  if ( g_orion150 )
    *(int32_t *)ECODE150(0x1E4EEE) = dword_1B9E34;
  sub_FC470_131(a1, a2, a3, a4);
}

//----- (001E1B05) --------------------------------------------------------
/* byte 1E1B04 = 0; byte 1E1B40 = byte_199BE9 / 0 / 1 for byte 23CF00 < 0 / 0 / > 0 */
int sub_47939(int a1, int a2, int a3, int a4, int a29, int a30, int a31)
{
  if ( g_orion150 )
  {
    int8_t c = (int8_t)*ESEG150(0x23CF00);

    *ECODE150(0x1E1B04) = 0;
    *ECODE150(0x1E1B40) = c < 0 ? byte_199BE9 : c == 0 ? 0 : 1;
  }
  return sub_47939_131(a1, a2, a3, a4, a29, a30, a31);
}

//----- (001E0A4A) --------------------------------------------------------
/* edx = byte_199BED unless byte_199BEF */
_BOOL1 sub_132646(int a1, int a2, int a3)
{
  if ( g_orion150 && !byte_199BEF )
    a2 = (uint8_t)byte_199BED;
  return sub_132646_131(a1, a2, a3);
}

//----- (001E419C) --------------------------------------------------------
/* replaces sub_8E280 (not at 8E0E6): sub_8E280 as many times as sub_8C527 says; eax unchanged */
int16_t sub_8E280(int a1)
{
  int8_t n, i;

  if ( !g_orion150 )
    return sub_8E280_131(a1);
  n = (int8_t)sub_8C527(a1);
  for ( i = 0; i < n; ++i )
    sub_8E280_131(a1);
  return (int16_t)a1;
}

//----- (001E0265) --------------------------------------------------------
/* sub_2004B7(eax) != 0 -> return (eax unchanged), else call sub_C4343 */
char sub_C4343(int16_t *a1, int16_t *a2, int a3)
{
  if ( g_orion150 && sub_2004B7(a1, 0) )
    return (char)(uintptr_t)a1;
  return sub_C4343_131(a1, a2, a3);
}

//----- (001E1992) --------------------------------------------------------
/* call sub_ECBF7; byte 1E1932 == 2 -> 13FD9(dword 1E1933, dword 1E1937) */
void sub_ECBF7(int a1, int a2)
{
  sub_ECBF7_131(a1, a2);
  if ( g_orion150 && *ECODE150(0x1E1932) == 2 )
    sub_13FD9_131(*(int32_t *)ECODE150(0x1E1933), *(uint32_t *)ECODE150(0x1E1937));
}

//----- (001E4B27) --------------------------------------------------------
/* only while byte 1E4AE7 == 0 */
void sub_EAAA1(int a1, int a2, int a3)
{
  if ( !g_orion150 || !*ECODE150(0x1E4AE7) )
    sub_EAAA1_131(a1, a2, a3);
}

//----- (001E2A07) --------------------------------------------------------
/* dword 1E2A1C = eax during sub_E9927, -1 after */
void sub_E9927(uint8_t *a1)
{
  if ( g_orion150 )
    *(uint32_t *)ECODE150(0x1E2A1C) = (uint32_t)(uintptr_t)a1;
  sub_E9927_131(a1);
  if ( g_orion150 )
    *(uint32_t *)ECODE150(0x1E2A1C) = 0xFFFFFFFF;
}

//----- (001E2FE7) --------------------------------------------------------
/* 0136BD in sub_136B3, byte_199F3A <= 1: al == 1 -> word [dword 1E2FE3 + 19ABA7h] = -1 once */
void Hook150_1E2FE7(int al)
{
  int32_t *p = (int32_t *)ECODE150(0x1E2FE3);

  if ( g_orion150 && al == 1 && *p != -1 )
  {
    *(int16_t *)DSEG150(0x19ABA7 + *p) = -1;
    *p = -1;
  }
}

//----- (001E3193) --------------------------------------------------------
/* 014605 in sub_145EA: sub_1E9D23(the record, a2) */
void Hook150_1E3193(void *rec, int a2)
{
  if ( g_orion150 )
    sub_1E9D23((int)(uintptr_t)rec, a2);
}

//----- (001E053C) --------------------------------------------------------
/* 01513D in sub_150FB: the random number (1.31 sub_1247A0(3)) by byte 23F18A */
int Hook150_1E053C(void)
{
  uint8_t b;

  if ( !g_orion150 )
    return sub_1247A0(3);
  b = *ESEG150(0x23F18A);
  if ( b < 1 )
    return sub_1247A0(3);
  if ( (int8_t)b > 1 )
    return sub_1247A0(5);
  return sub_1247A0(2) + 3;
}

//----- (001E0E28) --------------------------------------------------------
/* 035373 in sub_35251, damage type 3: sub_1F9F2B(ax = di, dx = cx, ebx = 3, ecx = esi) */
void Hook150_1E0E28(int a1, int a4, int16_t *a2)
{
  sub_1F9F2B((int16_t)a1, (int16_t)a4, 3, a2);
}

//----- (001E4282) --------------------------------------------------------
/* 042808 in sub_42781: word_1998AC = ax; for a player also word_199254 / word_199242 of it (sub_5699C, sub_56CA2) */
void Hook150_1E4282(int ax)
{
  word_1998AC = (int16_t)ax;
  if ( (int16_t)ax > 8 )
    return;
  word_199254[(int16_t)ax] = (int16_t)sub_5699C((int16_t)ax);
  word_199242[word_1998AC] = (int16_t)sub_56CA2(word_1998AC);
}

//----- (001E2D82) --------------------------------------------------------
/* 040436 in sub_40148: with byte 23F088 == 1 sub_1EA783 (pusha / popa) */
void Hook150_1EA783(void)
{
  if ( g_orion150 && *ESEG150(0x23F088) == 1 )
    sub_1EA783(0);
}

//----- (001E2150) --------------------------------------------------------
/* 03FAF5 in sub_3FA61: the direction sub_1E20C4 left in dword 1E20BF (-1000 = none); with byte 1E20C3 == 1
   no turn at all; both are reset */
void Hook150_1E2150(int b35, int16_t *dir, int16_t *diff)
{
  int32_t *d;

  if ( !g_orion150 )
    return;
  d = (int32_t *)ECODE150(0x1E20BF);
  if ( *d != -1000 )
  {
    *dir = (int16_t)*d;
    *diff = (int16_t)(b35 - *d);
    if ( *ECODE150(0x1E20C3) == 1 )
    {
      *dir = (int16_t)b35;
      *diff = 0;
    }
  }
  *ECODE150(0x1E20C3) = 0;
  *d = -1000;
}

//----- (001E8587) --------------------------------------------------------
/* 03D402 in sub_3D2DF: the losses of the missiles (ax = the record) by byte 23CF06 */
void Hook150_1E8587(int a1)
{
  sub_1E8587((uint16_t)a1);
}

//----- (001E0372) --------------------------------------------------------
/* 03CB98 in sub_3C892: sub_1EAE8B(ax = the missile) */
void Hook150_1EAE8B(int a1)
{
  sub_1EAE8B((uint16_t)a1);
}

//----- (001E1A44) --------------------------------------------------------
/* 03C3AA in sub_3C2DC: the ship behind a chain of missiles (sub_1E89BF) */
int Hook150_1E89BF(int rec)
{
  return sub_1E89BF(rec);
}

//----- (001E2672) --------------------------------------------------------
/* 03ACA1 in sub_3AC20: sub_1E9377(the damage, the word +2 of the missile) */
int Hook150_1E9377(int a1, int a2)
{
  return sub_1E9377(a1, a2);
}

//----- (001E42BC) --------------------------------------------------------
/* sub_3A3C3: the points of one damage step of the planet - word 23E2B4[sub_5685F(the owner of record 0)] */
int Hook150_1E42BC(void)
{
  int r = (uint8_t)sub_5685F(*(uint8_t *)(dword_192864 + 32));

  return *(uint16_t *)ESEG150(0x23E2B4 + 2 * r);
}

//----- (001E26B1) --------------------------------------------------------
/* 039F56 in sub_39F1D: sub_1E9557 / sub_1E966B(ship, target, ecx = the weapon); -1 = the 1.31 range check */
int Hook150_1E9557(int ship, int target, int weapon)
{
  return sub_1E9557((int16_t)ship, (int16_t)target, 0, (int16_t)weapon);
}

int Hook150_1E966B(int ship, int target, int weapon)
{
  return sub_1E966B((int16_t)ship, (int16_t)target, 0, (int16_t)weapon);
}

//----- (001E14CC) --------------------------------------------------------
/* 039FF1 in sub_39F1D: sub_1E8397(ship, target, ecx = the range) */
int Hook150_1E8397(int ship, int target, int range)
{
  return (uint8_t)sub_1E8397((int16_t)ship, (int16_t)target, 0, range);
}

//----- (001E1923) --------------------------------------------------------
/* 038DAC in sub_38B5E: after state 2 pusha / sub_1F9EC7(the record) / popa */
void Hook150_1F9EC7(int rec)
{
  if ( g_orion150 )
    sub_1F9EC7(rec, 0);
}

//----- (001E236F) --------------------------------------------------------
/* 038684 in sub_38656: pusha / sub_1E91DB(eax = the result, edx = sub_4B0D3 result) / popa */
void Hook150_1E91DB(int a1)
{
  sub_1E91DB(a1, 0);
}

//----- (001E2DE7) --------------------------------------------------------
/* sub_37308: pusha / sub_1FC9A3(esi) / popa - the text part goes to the combat log */
void Hook150_1E2DE7(const char *s)
{
  sub_1FC9A3((int *)(uintptr_t)s);
}

//----- (001E8F5F) --------------------------------------------------------
/* 036A87 in sub_36A63: the bonus of 1.50 instead of 80 for the state 1 */
int Hook150_1E8F5F(int a1, int a2)
{
  return (int)sub_1E8F5F((int16_t)a1, (int16_t)a2);
}

//----- (001E034A) --------------------------------------------------------
/* 035B58 in sub_35821: sub_1E7D97(the record + 2 * i, i, the repair) - cdecl, pushed edx, ecx, esi */
void Hook150_1E034A(int rec2, int i, int add)
{
  sub_1E7D97(rec2, i, add);
}

//----- (001E0DC1) --------------------------------------------------------
/* 0357A2 in sub_35251: sub_1F9EFF(di) */
void Hook150_1E0DC1(int a1)
{
  if ( g_orion150 )
    sub_1F9EFF((int16_t)a1, 0);
}

//----- (001EA36F) --------------------------------------------------------
/* 1.50 02AED2, 02AED3, 02AEE3: sub_2AED2 is push ecx / call sub_1EA36F / movzx eax, al - the 1.31 body (with the hook
   02AEE3) is dead code */
_BOOL2 sub_2AED2(int a1, int a2)
{
  if ( !g_orion150 )
    return sub_2AED2_131(a1, a2);
  return (uint8_t)sub_1EA36F(a1, a2, 0);
}

//----- (001E2F08) --------------------------------------------------------
/* 021785 in sub_21371 (eax = 9 * event): byte 1E30E9 = 1, the colony word_19ABA7 is returned and cleared -
   with byte_199F3A == 1 only later (dword 1E2FE3, sub_1E2FE7) */
int Hook150_1E2F08(int off)
{
  int16_t *w = (int16_t *)DSEG150(0x19ABA7 + off);
  int16_t v = *w;

  *ECODE150(0x1E30E9) = 1;
  if ( *DSEG150(0x199F3A) == 1 )
    *(int32_t *)ECODE150(0x1E2FE3) = off;
  else
    *w = -1;
  return v;
}

//----- (001E300F) --------------------------------------------------------
/* 02181F in sub_21371: as sub_1E2F08, returns var_2C = byte_19ABA6 - 10 (- 20 more above 7) */
int Hook150_1E300F(int off)
{
  int v = *(int8_t *)DSEG150(0x19ABA6 + off) - 10;

  if ( v > 7 )
    v -= 20;
  *ECODE150(0x1E30E9) = 1;
  if ( *DSEG150(0x199F3A) == 1 )
    *(int32_t *)ECODE150(0x1E2FE3) = off;
  else
    *(int16_t *)DSEG150(0x19ABA7 + off) = -1;
  return v;
}

/* a byte at a flat address of the game; 1.50 sometimes reads the DOS low memory (IVT, 04A581)
   - not emulated yet, 0 and a note on stderr (TODO: the bytes from DOSBox) */
uint8_t Hook150_Byte(uint32_t addr)
{
  if ( addr >= 0x10000 )
    return *(uint8_t *)(uintptr_t)addr;
  Dbg150("Hook150_Byte: low memory %05X read as 0\n", addr);
  return 0;
}

//----- (001E1345) --------------------------------------------------------
/* 108B8B in sub_1089C6: the font of sub_120BB5 (2 in 1.31) = sub_1E819B(bx) */
int Hook150_1E1345(int player)
{
  return g_orion150 ? sub_1E819B(player) : 2;
}

//----- (001E2A62) --------------------------------------------------------
/* FE3B0 in sub_FE359, message type 3: sub_10D167(word_19999C, byte +5) with dword 1E2A5E = word +4 */
void Hook150_1E2A62(int value, int tech)
{
  *(int32_t *)ECODE150(0x1E2A5E) = value;
  sub_10D167((int16_t)word_19999C, tech);
  *(int32_t *)ECODE150(0x1E2A5E) = -1;
}

//----- (001E2A20) --------------------------------------------------------
/* E9CA2 in sub_E9927 after sub_E4204: sub_1E96EB(word [ebp-8], byte [esi+ebp-39h],
   the monster of the planet dword 1E2A1C (sub_E9871 with sub_1E2A48)) */
void Hook150_1E2A20(int player, int b)
{
  if ( g_orion150 )
    sub_1E96EB(player, b, 0, (uint16_t)sub_E9871(dword_1E2A1C, (uint8_t (*)(int))sub_1E2A48, 0, 0));
}

//----- (001E43B0) --------------------------------------------------------
/* pusha / call sub_1EAE2F(eax, edx) / popa / jmp sub_E4B5F */
void sub_E4B5F(int a1, int a2)
{
  if ( g_orion150 )
    sub_1EAE2F(a1, a2);
  sub_E4B5F_131(a1, a2);
}

//----- (001E025A) --------------------------------------------------------
/* call sub_C2E4D / call sub_1E9203 */
void sub_C2E4D(void)
{
  sub_C2E4D_131();
  if ( g_orion150 )
    sub_1E9203();
}

//----- (001E1266) --------------------------------------------------------
/* byte 1E1265 = 1 during sub_BA5DA (not at BA416) */
char sub_BA5DA(int a1, int a2, int a3)
{
  char r;

  if ( !g_orion150 )
    return sub_BA5DA_131(a1, a2, a3);
  *ECODE150(0x1E1265) = 1;
  r = sub_BA5DA_131(a1, a2, a3);
  *ECODE150(0x1E1265) = 0;
  return r;
}

//----- (001E020F) --------------------------------------------------------
/* call sub_B094C / sub_1E6EA3 */
int sub_B094C(void)
{
  int r = sub_B094C_131();

  if ( g_orion150 )
    sub_1E6EA3();
  return r;
}

//----- (001E4194) --------------------------------------------------------
/* replaces sub_8BC39: sub_1EABAF */
void sub_8BC39(int a1)
{
  if ( !g_orion150 )
  {
    sub_8BC39_131(a1);
    return;
  }
  sub_1EABAF();
}

//----- (001E2945) --------------------------------------------------------
/* call sub_85FF2 / bytes +30h and +321h of the current player's record = 0 */
void sub_85FF2(int a1)
{
  sub_85FF2_131(a1);
  if ( g_orion150 )
  {
    uint8_t *p = dword_197F98 + 3753 * word_19999C;

    p[0x30] = 0;
    p[0x321] = 0;
  }
}

//----- (001E0399) --------------------------------------------------------
/* call sub_7B631 / sub_1EAD6B */
void sub_7B631(void)
{
  sub_7B631_131();
  if ( g_orion150 )
    sub_1EAD6B();
}

//----- (001E038F) --------------------------------------------------------
/* replaces sub_79AE8: sub_1EAD07(eax) */
char sub_79AE8(int a1)
{
  if ( !g_orion150 )
    return sub_79AE8_131(a1);
  return (char)sub_1EAD07(a1);
}

//----- (001E34B8) --------------------------------------------------------
/* call sub_7585D / 0 with byte_19BED1 == 1 (not at 75D72) */
int sub_7585D(int a1)
{
  int r = sub_7585D_131(a1);

  return g_orion150 && byte_19BED1 == 1 ? 0 : r;
}

//----- (001E3119) --------------------------------------------------------
/* call sub_755D2 / sub_1E9B67 with byte 23F0D6 (not at 72940) */
void sub_755D2(void)
{
  sub_755D2_131();
  if ( g_orion150 && *ESEG150(0x23F0D6) )
    sub_1E9B67();
}

//----- (001E3457) --------------------------------------------------------
/* only with word_199A02 */
void sub_745A5(int a1, int a2)
{
  if ( !g_orion150 || word_199A02 )
    sub_745A5_131(a1, a2);
}

//----- (001E38A3) --------------------------------------------------------
/* not with byte 23FF6E == 1 */
void sub_5D953(void)
{
  if ( !g_orion150 || *ESEG150(0x23FF6E) != 1 )
    sub_5D953_131();
}

//----- (001E03FB) --------------------------------------------------------
/* only when bit 0 of sub_1E7B2B(eax, edx, -, ecx = 0) */
void sub_459E7(int a1, int a2)
{
  if ( !g_orion150 || (sub_1E7B2B(a1, a2, 0, 0) & 1) )
    sub_459E7_131(a1, a2);
}

//----- (001E296A) --------------------------------------------------------
/* byte 1E1C32 = 0; byte 1E2969 = 1 during sub_44EA4 */
void sub_44EA4(int a1)
{
  if ( !g_orion150 )
  {
    sub_44EA4_131(a1);
    return;
  }
  *ECODE150(0x1E1C32) = 0;
  *ECODE150(0x1E2969) = 1;
  sub_44EA4_131(a1);
  *ECODE150(0x1E2969) = 0;
}

//----- (001E22C4) --------------------------------------------------------
/* sub_4B0D3(eax, 17) -> 0, else call sub_3E7A9 */
int sub_3E7A9(int a1, uint16_t *a2)
{
  if ( g_orion150 && sub_4B0D3(a1, 17) )
    return 0;
  return sub_3E7A9_131(a1, a2);
}

//----- (001E0358) --------------------------------------------------------
/* call sub_35C3A / sub_1E7DDB(eax) / eax unchanged */
int sub_35C3A(int result)
{
  int r = sub_35C3A_131(result);

  if ( !g_orion150 )
    return r;
  sub_1E7DDB(result);
  return result;
}

//----- (001E1914) --------------------------------------------------------
/* call sub_35821 / sub_1E893F(eax) / eax unchanged */
int sub_35821(int a1, int a2, int a3, int a4)
{
  int r = sub_35821_131(a1, a2, a3, a4);

  if ( !g_orion150 )
    return r;
  sub_1E893F(a1);
  return a1;
}

//----- (001E2906) --------------------------------------------------------
/* eax = 1 for sub_10DC12; a changed byte +321h of the current player's record clears byte +30h
   (not at 10DB96) */
void sub_10DC12(int a1, int a2, int a3, int16_t *a4)
{
  uint8_t *p;
  uint8_t c;

  if ( !g_orion150 )
  {
    sub_10DC12_131(a1, a2, a3, a4);
    return;
  }
  p = dword_197F98 + 3753 * word_19999C;
  c = p[0x321];
  sub_10DC12_131(1, a2, a3, a4);
  if ( p[0x321] != c )
    p[0x30] = 0;
}

//----- (001E1356) --------------------------------------------------------
/* the row step of sub_1088A0 (immediates 1089A6, 1089AA) = sub_1E81EB(bl) */
char sub_1088A0(int a1, int a2, unsigned int a3)
{
  if ( g_orion150 )
  {
    uint8_t v = (uint8_t)sub_1E81EB((uint8_t)a3);

    *CCODE150(0x1089A6) = v;
    *CCODE150(0x1089AA) = v;
  }
  return sub_1088A0_131(a1, a2, a3);
}

//----- (001E0433) --------------------------------------------------------
/* replaces sub_3CD21: sub_1ED4E7(eax, dx, cx = ebx) */
int sub_3CD21(unsigned int a1, int a2, int a3)
{
  if ( !g_orion150 )
    return sub_3CD21_131(a1, a2, a3);
  return sub_1ED4E7(a1, a2, a3, 0, 0, 0);
}

//----- (001E34EF) --------------------------------------------------------
/* replaces sub_A432F (not at A4EB9): sub_1EA223(dx, ecx, -, the 4 stack arguments) / retn 10h */
void sub_A432F(int a1, int a2, int a3, uint16_t *a4, uint16_t *a5, uint16_t *a6, uint16_t *a7, int a8)
{
  if ( !g_orion150 )
  {
    sub_A432F_131(a1, a2, a3, a4, a5, a6, a7, a8);
    return;
  }
  sub_1EA223(a2, a4, 0, a5, a6, a7, (_BYTE *)(intptr_t)a8);
}

//----- (001E4BE0) --------------------------------------------------------
/* pusha / call sub_22A3A7 / popa / jmp sub_5C510 (not at FAAF6) */
int sub_5C510(int base, int16_t *a1)
{
  if ( g_orion150 )
    sub_22A3A7(0);
  return sub_5C510_131(base, a1);
}

//----- (001E113C) --------------------------------------------------------
/* replaces sub_12479 (not at 1030F): call sub_22A267 / retn 8 */
void sub_12479(int a1, int a2, int a3, int a4, int a5, int a6)
{
  if ( !g_orion150 )
  {
    sub_12479_131(a1, a2, a3, a4, a5, a6);
    return;
  }
  sub_22A267(0, 0, 0);
}

//----- (001E0571) --------------------------------------------------------
/* replaces sub_D108B */
int sub_D108B(int a1, int a2, int a3)
{
  if ( !g_orion150 )
    return sub_D108B_131(a1, a2, a3);
  return sub_1E0571(a1, a2, a3);
}

//----- (001E9BB7) --------------------------------------------------------
/* replaces sub_92E72 */
int16_t sub_92E72(void)
{
  if ( !g_orion150 )
    return sub_92E72_131();
  return (int16_t)sub_1E9BB7();
}

//----- (001E0EF9) --------------------------------------------------------
/* call sub_5AEF4 / pusha / sub_1FBD3B / popa */
int sub_5AEF4(void)
{
  int r = sub_5AEF4_131();

  if ( g_orion150 )
    sub_1FBD3B(0, 0, 0, 0, 0, 0, 0);
  return r;
}

//----- (001E01E1) --------------------------------------------------------
/* sub_2027EB(eax), call sub_B2542, sub_AFF9E; a changed word_1828A8 -> sub_11C2F0, sub_B3E7A */
void sub_B2542(int16_t *a1, int16_t *a2, int a3)
{
  int16_t w;

  if ( !g_orion150 )
  {
    sub_B2542_131(a1, a2, a3);
    return;
  }
  sub_2027EB((int64_t)(uint32_t)(uintptr_t)a1, 0, 0, 0);
  sub_B2542_131(a1, a2, a3);
  w = word_1828A8;
  sub_AFF9E();
  if ( w != word_1828A8 )
  {
    sub_11C2F0();
    sub_B3E7A();
  }
}

//----- (001E43D0) --------------------------------------------------------
/* replaces sub_97A66: pusha / sub_1EDF9F(eax) / popa */
void sub_97A66(int a1)
{
  if ( !g_orion150 )
  {
    sub_97A66_131(a1);
    return;
  }
  sub_1EDF9F(a1, 0, 0, 0, 0, 0, 0);
}

//----- (00229EC7) --------------------------------------------------------
/* replaces sub_82809; edx comes back only in its tail jump to sub_82809 (229F50), which Hex-Rays
   reads from a4 */
int16_t sub_82809(int a1, char *a2)
{
  if ( !g_orion150 )
    return sub_82809_131(a1, a2);
  sub_229EC7(a1, 0, 0, (int)(intptr_t)a2);
  return 0;
}

//----- (001EADBB) --------------------------------------------------------
/* replaces sub_E36DF */
void sub_E36DF(char *a1, int a2)
{
  if ( !g_orion150 )
  {
    sub_E36DF_131(a1, a2);
    return;
  }
  sub_1EADBB((int)(intptr_t)a1);
}

//----- (001E21FA) --------------------------------------------------------
/* replaces sub_E3616 */
char *sub_E3616(char *result)
{
  if ( !g_orion150 )
    return sub_E3616_131(result);
  return (char *)(intptr_t)sub_1E21FA((int)(intptr_t)result);
}

//----- (001E4C10) --------------------------------------------------------
/* replaces sub_EB9C8: push ecx / mov ecx, ebx / call sub_1EB207 (a record pointer or 0) */
_BOOL1 sub_EB9C8(int a1, int a2, int a3)
{
  if ( !g_orion150 )
    return sub_EB9C8_131(a1, a2, a3);
  return sub_1EB207(a1, a2, a3, a3) != 0;
}

/* ===== call->call hooks at single call sites ===== */

//----- (001E1ED8) --------------------------------------------------------
/* 115ED: pusha / sub_1FEADB / fclose(dword 23FC5A) / popa / jmp sub_7A7CF */
int16_t Hook150_1E1ED8(void)
{
  if ( g_orion150 )
  {
    sub_1FEADB(0, 0, 0, 0);
    fclose(*(int32_t *)ESEG150(0x23FC5A));
  }
  return sub_7A7CF();
}

//----- (001E1ECB) --------------------------------------------------------
/* 11BCB: pusha / sub_1FBA8F(eax = the file) / popa / call fclose */
int Hook150_1E1ECB(int handle)
{
  if ( g_orion150 )
    sub_1FBA8F(handle, 0, 0, 0, 0, 0, 0, 0);
  return fclose(handle);
}

//----- (001E0793) --------------------------------------------------------
/* 209E7: xchg ebx, edx / jmp sub_4E3B5 */
char Hook150_1E0793(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return g_orion150 ? sub_4E3B5(a1, a3, a2, a4, a5, a6) : sub_4E3B5(a1, a2, a3, a4, a5, a6);
}

//----- (001E25C8) --------------------------------------------------------
/* replaces sub_286E8: sub_1E9413(eax, edx, ebx) */
int Hook150_1E25C8(int a1, int a2, int a3)
{
  return g_orion150 ? (int)sub_1E9413(a1, a2, a3) : sub_286E8(a1, a2, a3);
}

//----- (001E25B8) --------------------------------------------------------
/* replaces sub_286E8: sub_1E9397(eax, edx, ebx) */
int Hook150_1E25B8(int a1, int a2, int a3)
{
  return g_orion150 ? (int)sub_1E9397(a1, a2, a3) : sub_286E8(a1, a2, a3);
}

//----- (001E0C0C) --------------------------------------------------------
/* byte 1E0C0B = 1 with byte 23F0F2 == 1 during sub_1E25B8 */
int Hook150_1E0C0C(int a1, int a2, int a3)
{
  int r;

  if ( !g_orion150 )
    return sub_286E8(a1, a2, a3);
  if ( *ESEG150(0x23F0F2) == 1 )
    *ECODE150(0x1E0C0B) = 1;
  r = sub_1E9397(a1, a2, a3);
  *ECODE150(0x1E0C0B) = 0;
  return r;
}

//----- (001E0C69) --------------------------------------------------------
/* byte 1E0C0B = 1 during sub_2885A */
int Hook150_1E0C69(int a1, int a2)
{
  int r;

  if ( !g_orion150 )
    return sub_2885A(a1, a2);
  *ECODE150(0x1E0C0B) = 1;
  r = sub_2885A(a1, a2);
  *ECODE150(0x1E0C0B) = 0;
  return r;
}

//----- (001E3E95) --------------------------------------------------------
/* call sub_34921 / call sub_1EE80F (its eax is the result) */
int Hook150_1E3E95(void)
{
  int r = sub_34921();

  return g_orion150 ? (int)sub_1EE80F() : r;
}

//----- (001E19E2) --------------------------------------------------------
/* sub_3897A; 0 and sub_4528F > 0 and byte +4Bh of record eax (dword_192864, 139h) == 1 -> 0; else
   (byte +3Dh = 0 unless the 0 case reached +4Bh) word +4Bh = 0 -> 1 */
int Hook150_1E19E2(int a1)
{
  uint8_t *p;
  int r;

  if ( !g_orion150 )
    return sub_3897A(a1);
  p = (uint8_t *)(dword_192864 + 0x139 * a1);
  r = sub_3897A(a1);
  if ( !(int16_t)r && sub_4528F(a1) > 0 )
  {
    if ( p[0x4B] == 1 )
      return 0;
  }
  else
    p[0x3D] = 0;
  *(uint16_t *)(p + 0x4B) = 0;
  return 1;
}

//----- (001E22FC) --------------------------------------------------------
/* sub_3E563(eax) -> 0, else sub_4B0D3 */
_BOOL1 Hook150_1E22FC(int a1, int a2)
{
  if ( g_orion150 && sub_3E563(a1) )
    return 0;
  return sub_4B0D3(a1, a2);
}

//----- (001E17BD) --------------------------------------------------------
/* replaces sub_455A4: sub_1FB0DB (no register arguments) */
int Hook150_1E17BD(int a1, int a2)
{
  return g_orion150 ? sub_1FB0DB(0, 0, 0, 0) : sub_455A4(a1, a2);
}

//----- (001E17C7) --------------------------------------------------------
/* replaces sub_455A4: sub_1FB0EB */
int Hook150_1E17C7(int a1, int a2)
{
  return g_orion150 ? sub_1FB0EB(0, 0, 0, 0) : sub_455A4(a1, a2);
}

//----- (001E0249) --------------------------------------------------------
/* sub_1171AB again while sub_229DBF(its result) */
int Hook150_1E0249(int a1, int a2, int a3, int a4)
{
  int r;

  do
    r = sub_1171AB(a1, a2, a3, a4);
  while ( g_orion150 && sub_229DBF((int64_t)(uint32_t)r, 0, 0, 0) );
  return r;
}

//----- (001E1A7F) --------------------------------------------------------
/* sub_3E563 0 and byte 1E1B04 -> sub_4B0D3(eax, 34) == 0 */
_BOOL1 Hook150_1E1A7F(int a1)
{
  _BOOL1 r = sub_3E563(a1);

  if ( g_orion150 && !r && *ECODE150(0x1E1B04) )
    r = !sub_4B0D3(a1, 34);
  return r;
}

//----- (001E16F3) --------------------------------------------------------
/* 043552, 044615 in sub_42F7F: after the owner byte pusha / sub_1E8663(owner) / popa */
void Hook150_1E16F3(int owner)
{
  if ( g_orion150 )
    sub_1E8663(owner);
}

//----- (001E1C4F) --------------------------------------------------------
/* 044EBB in sub_44EA4: once the loop has settled, one more pass with byte 1E1C32 = 1; 1 = leave the loop */
int Hook150_1E1C4F(int done)
{
  if ( !done )
    return 0;
  if ( !g_orion150 )
    return 1;
  if ( !*ECODE150(0x1E1C32) )
  {
    *ECODE150(0x1E1C32) = 1;
    return 0;
  }
  *ECODE150(0x1E1C32) = 0;
  return 1;
}

//----- (001E1C33) --------------------------------------------------------
/* 044F03 in sub_44EA4: byte +8 of the missile is not checked in the extra pass (byte 1E1C32 = 1) */
int Hook150_1E1C33(int rec)
{
  return !*(_BYTE *)(rec + 8) || g_orion150 && *ECODE150(0x1E1C32) == 1;
}

//----- (001E1C76) --------------------------------------------------------
/* 044F13 in sub_44EA4 (word_17D853 set): byte +17h != FFh, with byte 1E1B04 = 1 also weapon type 4 or the
   code byte 3C9F1 (the FFh of mov [+17h], 0FFh in sub_3C892) = 0 */
int Hook150_1E1C76(int rec)
{
  if ( *(_BYTE *)(rec + 23) == 0xFF )
    return 0;
  if ( !g_orion150 || *ECODE150(0x1E1B04) != 1 )
    return 1;
  if ( byte_17F80F[28 * *(int16_t *)rec] == 4 )
    return 1;
  return !(uint8_t)Hook150_CodeByte(0x3C9F1, 0xFF);
}

//----- (001E1CB2) --------------------------------------------------------
/* 04520A in sub_44EA4 (word_17D853 set): byte +17h is not counted up with byte 1E1B04 = 1 */
int Hook150_1E1CB2(void)
{
  return !g_orion150 || *ECODE150(0x1E1B04) != 1;
}

//----- (001E17F0) --------------------------------------------------------
/* 4315F in sub_42F7F: the qsort comparator sub_42E9C becomes sub_1E87C3 */
int Hook150_1E17F0(int16_t *a1, int16_t *a2)
{
  return sub_1E87C3(a1, a2);
}

//----- (001E079A) --------------------------------------------------------
/* replaces sub_4545B: sub_1FA9B3 */
int Hook150_1E079A(int a1, int a2)
{
  return g_orion150 ? sub_1FA9B3(0, 0, 0, 0) : sub_4545B(a1, a2);
}

//----- (001E0238) --------------------------------------------------------
/* call sub_114C72 / sub_1E6F3F */
unsigned int Hook150_1E0238(uint8_t *a1, int a2)
{
  unsigned int r = sub_114C72(a1, a2);

  if ( g_orion150 )
    sub_1E6F3F();
  return r;
}

//----- (001E3D80) --------------------------------------------------------
/* byte 1E3D7F = 1 during sub_568EB */
int16_t Hook150_1E3D80(int a1)
{
  int16_t r;

  if ( !g_orion150 )
    return sub_568EB(a1);
  *ECODE150(0x1E3D7F) = 1;
  r = sub_568EB(a1);
  *ECODE150(0x1E3D7F) = 0;
  return r;
}

//----- (001E1971) --------------------------------------------------------
/* byte 1E1932 1 -> 2 with eax, edx kept in 1E1933, 1E1937 */
void Hook150_1E1971(int a1, unsigned int a2, int a3)
{
  if ( g_orion150 && *ECODE150(0x1E1932) == 1 )
  {
    *ECODE150(0x1E1932) = 2;
    *(int32_t *)ECODE150(0x1E1933) = a1;
    *(uint32_t *)ECODE150(0x1E1937) = a2;
  }
  sub_145EA(a1, a2, a3);
}

//----- (001E1526) --------------------------------------------------------
/* byte_199CB4 -> sub_5F2F6 instead of sub_58387 */
int Hook150_1E1526(int a1, int a2, int a3, int a4)
{
  if ( g_orion150 && byte_199CB4 )
    return sub_5F2F6(a1, a2, a3, a4);
  return sub_58387(a1, a2, a3, a4);
}

//----- (001E10F7) --------------------------------------------------------
/* byte_199CB4 -> sub_57871(eax, 5, edx) (eax unchanged), else sub_616A5 */
int16_t Hook150_1E10F7(int a1, int a2, int a3)
{
  if ( g_orion150 && byte_199CB4 )
  {
    sub_57871(a1, 5, a2);
    return (int16_t)a1;
  }
  return sub_616A5(a1, a2, a3);
}

//----- (001E10BF) --------------------------------------------------------
/* byte 1E0F83 = 1, sub_12779E(1E0F1F, eax, edx), then sub_127776 */
unsigned int Hook150_1E10BF(uint8_t *a1, unsigned int a2)
{
  if ( g_orion150 )
  {
    *ECODE150(0x1E0F83) = 1;
    sub_12779E(ECODE150(0x1E0F1F), a1, a2);
  }
  return sub_127776(a1, a2);
}

//----- (001E01B0) --------------------------------------------------------
/* word_19999C = ax during sub_6B577 */
int Hook150_1E01B0(int a1, int a2)
{
  int16_t w = word_19999C;
  int r;

  if ( !g_orion150 )
    return sub_6B577(a1, a2);
  word_19999C = (int16_t)a1;
  r = sub_6B577(a1, a2);
  word_19999C = w;
  return r;
}

//----- (001E3488) --------------------------------------------------------
/* only with word_199A08 == 4 (eax unchanged otherwise) */
int Hook150_1E3488(int a1, int a2, int a3)
{
  if ( g_orion150 && word_199A08 != 4 )
    return a1;
  return sub_12A478(a1, a2, a3);
}

//----- (001E395F) --------------------------------------------------------
/* call sub_7A25F; al -> sub_1FD613(word 1E3951, -1) */
int Hook150_1E395F(uint8_t *a1, int a2, int a3)
{
  int r = sub_7A25F(a1, a2, a3);

  if ( g_orion150 && (uint8_t)r )
    sub_1FD613(*(uint16_t *)ECODE150(0x1E3951), -1);
  return r;
}

//----- (001E373F) --------------------------------------------------------
/* replaces sub_A0305: eax = dword_192B6C, sub_1FD44F(eax) */
int Hook150_1E373F(void)
{
  int v;

  if ( !g_orion150 )
    return sub_A0305();
  v = dword_192B6C;
  sub_1FD44F((int16_t *)(intptr_t)v);
  return v;
}

//----- (001E41B8) --------------------------------------------------------
/* replaces sub_1247A0: sub_8C807(byte_199CB3) until below 6, then al + 1 */
unsigned int Hook150_1E41B8(unsigned int a1)
{
  int r;

  if ( !g_orion150 )
    return sub_1247A0(a1);
  do
    r = sub_8C807((uint8_t)byte_199CB3);
  while ( (int8_t)r >= 6 );
  return (r & ~0xFF) | (uint8_t)(r + 1);
}

//----- (001EE553) --------------------------------------------------------
/* replaces sub_1210FD */
int Hook150_1EE553(int a1, int a2, int a3)
{
  return g_orion150 ? (int)(intptr_t)sub_1EE553(0) : sub_1210FD(a1, a2, a3);
}

//----- (001E6F7F) --------------------------------------------------------
/* replaces sub_11ADB4 */
int Hook150_1E6F7F(int a1, int a2)
{
  return g_orion150 ? sub_1E6F7F() : sub_11ADB4(a1, a2);
}

//----- (001E04DF) --------------------------------------------------------
/* sub_1E04C4 / call sub_119281 */
void Hook150_1E04DF(void)
{
  if ( g_orion150 )
    sub_1E04C4();
  sub_119281();
}

//----- (001E38B2) --------------------------------------------------------
/* call sub_94B3A; ax -> sub_1FD613(byte_199F15, -1) */
int Hook150_1E38B2(int a1, unsigned int a2, int a3, int16_t *a4, int a5)
{
  int r = sub_94B3A(a1, a2, a3, a4, a5);

  if ( g_orion150 && (int16_t)r )
    sub_1FD613((int8_t)byte_199F15, -1);
  return r;
}

//----- (001E31F3) --------------------------------------------------------
/* byte [eax+23FF7E] = 1 / call sub_933F2 */
int Hook150_1E31F3(int a1)
{
  if ( g_orion150 )
    *ESEG150(0x23FF7E + a1) = 1;
  return sub_933F2(a1);
}

//----- (001E30F6) --------------------------------------------------------
/* byte 23FC56 = 0 / call sub_A20CD */
int Hook150_1E30F6(void)
{
  if ( g_orion150 )
    *ESEG150(0x23FC56) = 0;
  return sub_A20CD();
}

//----- (001E3103) --------------------------------------------------------
/* call sub_1171AB; byte 23F0D6 -> sub_1E9C6F(its result) */
int Hook150_1E3103(int a1, int a2, int a3, int a4)
{
  int r = sub_1171AB(a1, a2, a3, a4);

  if ( g_orion150 && *ESEG150(0x23F0D6) )
    sub_1E9C6F(r, 0);
  return r;
}

uint8_t *Hook150_Ecode(uint32_t addr)
{
  return ECODE150(addr);
}

//----- (001E0380) --------------------------------------------------------
/* 1278A mov eax, offset dword_199CB6 / 1278F: call sub_1691E7 (LE code of 1.50, ends in sub_124820(value)),
   then sub_1E711F */
void Hook150_1E0380(void)
{
  sub_1691E7((int *)&dword_199CB6, 0);
  sub_1E711F();
}

//----- (001E12FB) --------------------------------------------------------
/* pusha / sub_1E80C7 / popa / jmp FE8BE */
int Hook150_1E12FB(int a1, int a2, int a3, int16_t *a4)
{
  if ( g_orion150 )
    sub_1E80C7();
  return ServiceAudioTick_FE8BE(a1, a2, a3, a4);
}

//----- (001E19B1) --------------------------------------------------------
/* 13F1F: byte 23F0E3 == 1 -> sub_56586(eax, edx), sub_AF7B4(ecx = eax, 5, ebx) before sub_564CD */
char Hook150_1E19B1(int a1, int a2, int ebx)
{
  if ( g_orion150 && *ESEG150(0x23F0E3) == 1 )
  {
    sub_56586(a1, a2);
    sub_AF7B4(a1, 5, ebx);
  }
  return sub_564CD(a1, a2);
}

//----- (001E0A60) --------------------------------------------------------
/* 310F9: the number itoa gets is sub_575D6(byte_199A32, byte_199A43) when byte_199A32 < 8, word [ebp+5Ah]
   != 1 and word_199A30 != -1 */
int Hook150_1E0A60(int value, int var5A)
{
  if ( g_orion150 && (int8_t)byte_199A32 < 8 && (int16_t)var5A != 1 && word_199A30 != -1 )
    return sub_575D6((uint8_t)byte_199A32, (uint8_t)byte_199A43);
  return value;
}

//----- (001E0ADF) --------------------------------------------------------
/* 31348: word_199A30 != -1 -> the byte_199A43 branch (3134F: byte_199A37), else sub_4A884 */
int Hook150_1E0ADF(int a1)
{
  if ( g_orion150 && word_199A30 != -1 )
    return (uint8_t)byte_199A37;
  return sub_4A884(a1);
}

//----- (001E0B25) --------------------------------------------------------
/* 31567, 3168A: sub_1210B7 only without byte_199CB4 == 1, word_199A3B == 1, word [ebp+5Ah] == 1 */
int Hook150_1E0B25(int var5A)
{
  return !g_orion150 || !(byte_199CB4 == 1 || word_199A3B[0] == 1 || (int16_t)var5A == 1);
}

//----- (001E50BF) --------------------------------------------------------
/* bx == 20: m = sub_494A8(di, edx) into [ebp-1Ch]; the 4 words +29h of record di at most m, word +27h = m */
static void Hook150_1E50BF(int di, int bx, int16_t *var1C)
{
  uint8_t *rec;
  int16_t m;
  int b;

  if ( (int16_t)bx != 20 )
    return;
  m = (int16_t)sub_494A8((int16_t)di, bx);
  *var1C = m;
  rec = (uint8_t *)(dword_192864 + 0x139 * (int16_t)di);
  for ( b = 0; b < 4; ++b )
    if ( *(int16_t *)(rec + 2 * b + 0x29) > m )
      *(int16_t *)(rec + 2 * b + 0x29) = m;
  *(int16_t *)(rec + 0x27) = m;
}

//----- (001E1DF9) --------------------------------------------------------
/* 356DA: call sub_127712 / sub_1E8EB3(di, bx) / sub_1E50BF (bx = edx = the second argument) */
int Hook150_1E1DF9(int a1, unsigned int a2, int di, int16_t *var1C)
{
  int r = sub_127712(a1, a2);

  if ( g_orion150 )
  {
    sub_1E8EB3((int16_t)di, (int16_t)a2);
    Hook150_1E50BF(di, (int)a2, var1C);
  }
  return r;
}

//----- (001E1B8A) --------------------------------------------------------
/* 36F38: sub_42A27; ax and byte 1E1B04 == 1 -> sub_4B0D3(ecx = eax, 34) */
_BOOL1 Hook150_1E1B8A(int a1)
{
  int r = sub_42A27(a1);

  if ( g_orion150 && (int16_t)r && *ECODE150(0x1E1B04) == 1 )
    r = sub_4B0D3(a1, 34);
  return (_BOOL1)r;
}

//----- (001E2DF1) --------------------------------------------------------
/* 37D4A replaces sub_A5EBC: mov edx, ebx / call sub_1FB857 */
int Hook150_1E2DF1(int a1, int a3)
{
  return sub_1FB857(a1, a3, 0, 0, 0);
}

//----- (001FB7E3) --------------------------------------------------------
/* 37D5D replaces sub_A5EB2 (its pushed ecx only pads the cdecl call of sub_1E2DF9) */
int16_t Hook150_1FB7E3(int a1, int a2)
{
  return g_orion150 ? (int16_t)sub_1FB7E3(a1, 0, 0, 0) : sub_A5EB2(a1, a2);
}

//----- (001E21E5) --------------------------------------------------------
/* 3A97B: call sub_3891E(si) / sub_4588C(si) / sub_2C601(its result, edx = a4) */
void Hook150_1E21E5(int a4)
{
  sub_3891E(a4);
  if ( g_orion150 )
    sub_2C601(sub_4588C((int16_t)a4), a4);
}

//----- (001E1A24) --------------------------------------------------------
/* 43078: pusha / sub_1E7F27(di) / popa / call FE8BE */
int Hook150_1E1A24(int a1, int a2, int a3, int16_t *a4, int di)
{
  if ( g_orion150 )
    sub_1E7F27((int16_t)di);
  return ServiceAudioTick_FE8BE(a1, a2, a3, a4);
}

//----- (001E1788) --------------------------------------------------------
/* 4319C: dword 23FDAA = lea [ebp+4Ah] (a local of sub_42F7F), sub_1E8717, jmp FE8BE */
int Hook150_1E1788(int a1, int a2, int a3, int16_t *a4, uint8_t *var4A)
{
  if ( g_orion150 )
  {
    *(uint32_t *)ESEG150(0x23FDAA) = (uint32_t)(uintptr_t)var4A;
    sub_1E8717();
  }
  return ServiceAudioTick_FE8BE(a1, a2, a3, a4);
}

//----- (001E1AAF) --------------------------------------------------------
/* 4321A: sub_3E563; 0 -> (byte 1E1B04 and sub_4B0D3(a1, 34) == 0) or (!word_17D853 and byte +20h of
   record a1 != di) */
_BOOL1 Hook150_1E1AAF(int a1, int di)
{
  _BOOL1 r = sub_3E563(a1);

  if ( !g_orion150 || r )
    return r;
  if ( *ECODE150(0x1E1B04) && !(int16_t)sub_4B0D3(a1, 34) )
    return 1;
  if ( word_17D853 )
    return 0;
  return *(uint8_t *)(dword_192864 + 0x139 * a1 + 0x20) != (uint16_t)di;
}

//----- (001E512C) --------------------------------------------------------
/* 4350C after sub_127776: ebx = sub_1EB393(bx): 2721h -> 2719h with byte 23FDA6 = 1 */
int Hook150_1E512C(int ebx)
{
  *ESEG150(0x23FDA6) = (int16_t)ebx == 0x2721;
  return (int16_t)ebx == 0x2721 ? 0x2719 : (int16_t)ebx;
}

//----- (001E1FF4) --------------------------------------------------------
/* 438BC, 4459A: a local of sub_42F7F ([ebp+46h] / [ebp+7Ah]) = movzx ax, byte +20h of record eax (the upper
   half stays from the multiplication), then sub_3FA61 */
void Hook150_1E1FF4(int a1, int a2, int a3, int *var)
{
  if ( g_orion150 )
  {
    int v = 0x139 * (int16_t)a1;

    *var = (v & 0xFFFF0000) | *(uint8_t *)(dword_192864 + v + 0x20);
  }
  sub_3FA61(a1, a2, a3);
}

//----- (001E20C4) --------------------------------------------------------
/* 3FADF in sub_3FA61 before sub_3F5F1: [ebp-4] = a2 * 20 (v16), [ebp-10h] = a3 * 20, [ebp-14h] = byte +23h of
   record a1; sub_3EAA5(a1, &[ebp-4], &[ebp-10h], &[ebp-14h]) == 1 -> word_1998DA = 1 and dword 1E20BF =
   word [ebp-14h]; [ebp-14h] is set back to 313 * a1 afterwards (v14) */
void Hook150_1E20C4(int a1, int a2, int a3, int16_t *v16)
{
  int32_t var10, var14;

  if ( !g_orion150 )
    return;
  if ( word_1998DA == 1 )
    *ECODE150(0x1E20C3) = 1;
  if ( word_1998C4 != 1 || word_1998C2 || word_1998DA == 2 )
    return;
  *v16 = (int16_t)(20 * (int16_t)a2);
  var10 = 20 * (int16_t)a3;
  var14 = (int32_t)(((uint32_t)(uintptr_t)dword_192864 & 0xFFFF0000) |
                    *(uint8_t *)(dword_192864 + 313 * (int16_t)a1 + 0x23));
  if ( (int16_t)sub_3EAA5((int16_t)a1, (_WORD *)v16, (_WORD *)&var10, (_WORD *)&var14) == 1 )
  {
    word_1998DA = 1;
    *(int32_t *)ECODE150(0x1E20BF) = (int16_t)var14;
  }
}

//----- (001E1B65) --------------------------------------------------------
/* 4A623, 4A7BE, 4D093 (si = eax there): sub_3E563 0 and byte 1E1B04 == 1 -> sub_4B0D3(si, 34) ^ 1 */
_BOOL1 Hook150_1E1B65(int a1)
{
  _BOOL1 r = sub_3E563(a1);

  if ( g_orion150 && !r && *ECODE150(0x1E1B04) == 1 )
    r = (sub_4B0D3((int16_t)a1, 34) ^ 1) & 1;
  return r;
}

//----- (001E4941) --------------------------------------------------------
/* 558BB: call sub_127712 / sub_127712(the same record, byte 23DFAE) */
int Hook150_1E4941(int a1, unsigned int a2)
{
  int r = sub_127712(a1, a2);

  return g_orion150 ? sub_127712(a1, *ESEG150(0x23DFAE)) : r;
}

//----- (001E495D) --------------------------------------------------------
/* 55AA9: call sub_127712 / sub_127712(ecx = the same record, byte 23DF64) */
int Hook150_1E495D(int a1, unsigned int a2)
{
  int r = sub_127712(a1, a2);

  return g_orion150 ? sub_127712(a1, *ESEG150(0x23DF64)) : r;
}

//----- (001E1B41) --------------------------------------------------------
/* 48BF9 in sub_47939 (jmp 1E1B41, back at 48C1A): sub_42F7F(0, byte 1E1B04), sub_1E8A58, sub_4A5CE (eax as
   sub_42F7F left it - sub_4A5CE compares it only without word_17D853 == 1, 4A612 sub_1E1BAC), byte 1E1B04 ^= 1;
   instead of 1.31's sub_42F7F(0, 0), sub_4A5CE(si), sub_4A5CE(di), sub_42F7F(0, 1) */
void Hook150_1E1B41(int si, int ebx)
{
  sub_42F7F(0, *ECODE150(0x1E1B04), ebx);
  sub_1E8A58();
  sub_4A5CE(si);
  *ECODE150(0x1E1B04) ^= 1;
}

//----- (001E07A4) --------------------------------------------------------
/* 49AB3 in sub_49A41: with word 23DCE0 and sub_1E7E1F() == 0 back to the loop head (49CE0 jmp 49A51) */
int Hook150_1E07A4(void)
{
  return g_orion150 && *(int16_t *)ESEG150(0x23DCE0) && !sub_1E7E1F();
}

//----- (001E0C29) --------------------------------------------------------
/* 4785C in sub_4752F: byte 23F0F2 == 1 -> word_18C9A8 at [ebp-3Ch] (v20) = -1, byte 1E0C0B = 1 during
   sub_1E9397 (replaces sub_286E8) */
int Hook150_1E0C29(int a1, int a2, int a3, int v20)
{
  int r;

  if ( !g_orion150 )
    return sub_286E8(a1, a2, a3);
  if ( *ESEG150(0x23F0F2) == 1 )
  {
    *(int16_t *)((char *)word_18C9A8 + v20) = -1;
    *ECODE150(0x1E0C0B) = 1;
  }
  r = sub_1E9397(a1, a2, a3);
  *ECODE150(0x1E0C0B) = 0;
  return r;
}

//----- (001E4971) --------------------------------------------------------
/* 56170 replaces sub_127776(record + 9Fh, 11): sub_127712(dword_192864 + ebx + 4Ch, byte 23DEA6) */
void Hook150_1E4971(int ebx)
{
  sub_127712(ebx + dword_192864 + 0x4C, *ESEG150(0x23DEA6));
}

//----- (001E4988) --------------------------------------------------------
/* 563F8: call sub_127712 / sub_127712(ecx = the same record, byte 23DE56) */
int Hook150_1E4988(int a1, unsigned int a2)
{
  int r = sub_127712(a1, a2);

  return g_orion150 ? sub_127712(a1, *ESEG150(0x23DE56)) : r;
}

//----- (001E0E59) --------------------------------------------------------
/* 56541 / 565FA (1E0E43): call sub_127712, then sub_1E0E8B(ecx = the player) with byte 23F0ED / 23F0EE == 1 */
int Hook150_1E0E59(int a1, unsigned int a2, int player, uint32_t flag)
{
  int r = sub_127712(a1, a2);

  if ( g_orion150 && *ESEG150(flag) == 1 )
    sub_1E0E8B(0, 0, 0, player);
  return r;
}

//----- (001E1307) --------------------------------------------------------
/* 5BCC4: pusha / sub_1E80C7 / popa / jmp fopen */
int Hook150_1E1307(char *name, char *mode)
{
  if ( g_orion150 )
    sub_1E80C7();
  return fopen(name, mode);
}

//----- (001E0A09) --------------------------------------------------------
/* 618E8: eax = word 17F0ED[byte +10h of [ebp-28h] (a2 of sub_616A5)] instead of word_17F0ED */
int Hook150_1E0A09(int a2)
{
  if ( !g_orion150 )
    return word_17F0ED;
  return *(int16_t *)((char *)&word_17F0ED + 2 * *(uint8_t *)(intptr_t)(a2 + 16));
}

//----- (001E415C) --------------------------------------------------------
/* 6A890: byte 23F0B3 -> movzx sub_77C78(eax, word [ebp-18h] = a2 of sub_6A7C8) instead of sub_5680D */
int Hook150_1E415C(int a1, int a2)
{
  if ( g_orion150 && *ESEG150(0x23F0B3) )
    return (uint8_t)sub_77C78(a1, (int16_t)a2);
  return sub_5680D(a1);
}

//----- (001E4178) --------------------------------------------------------
/* 6A8E6: byte 23F0B2 -> movzx sub_77CF4(eax, word [ebp-18h]) instead of sub_5679E */
int Hook150_1E4178(int a1, int a2)
{
  if ( g_orion150 && *ESEG150(0x23F0B2) )
    return (uint8_t)sub_77CF4(a1, (int16_t)a2);
  return sub_5679E(a1);
}

//----- (001E17D1) --------------------------------------------------------
/* 46936: byte 23CF00 == 2 and byte 2400A6 -> ax = -1 instead of sub_1151B0 */
char *Hook150_1E17D1(int a1, int a2, int a3, _WORD *a4, _BYTE *a5, int a6)
{
  if ( g_orion150 && *ESEG150(0x23CF00) == 2 && *ESEG150(0x2400A6) )
    return (char *)(intptr_t)((a1 & 0xFFFF0000) | 0xFFFF);
  return sub_1151B0(a1, a2, a3, a4, a5, a6);
}

//----- (001E096A) --------------------------------------------------------
/* 6B72E: pusha / sub_6E8DA(word [ebp+7Ah] = v23 of sub_6B577) / popa / call sub_6B86A */
void Hook150_1E096A(int v23)
{
  if ( g_orion150 )
    sub_6E8DA((int16_t)v23);
}

//----- (001E3719) --------------------------------------------------------
/* 868E0 replaces sub_A0305: sub_1FD44F(lea [ebp-64Ah] = the ship list v65 of sub_86188) */
void Hook150_1E3719(int16_t *v65)
{
  sub_1FD44F(v65);
}

//----- (001E4D9E) --------------------------------------------------------
/* 87CEC before sub_233FA: with sub_234E5 a frame for the text 0C6h (sub_8F6F8 colours, sub_134D2D lines);
   [ebp-16h] (2 colour bytes) and [ebp-36h] (the text) are scratch space of the caller */
_BOOL1 Hook150_1E4D9E(void)
{
  char col[24], text[32];
  int16_t x;

  if ( g_orion150 && (int16_t)sub_234E5() )
  {
    sub_8F6F8(3, 0x49, 0x4C, col);
    sub_120BB5(3, (int)(intptr_t)col);
    sub_8F7DF((int16_t)((uint8_t)byte_199F07 * 5 / 9));
    strcpy(text, (char *)(intptr_t)sub_CDF5C(0xC6));
    x = (int16_t)(sub_12066F((int)(intptr_t)text) + 25);
    sub_134D2D(x, 0x15, 0x19, 0x15, (uint8_t)col[0]);
    sub_134D2D(x, 0x16, 0x19, 0x16, (uint8_t)col[1]);
    sub_1212B3(0x19, 0x18, (int)(intptr_t)text);
    {
      int16_t c = (int16_t)(sub_122259() + 25);

      sub_134D2D(x, (int16_t)(sub_122259() + 25), 0x19, c, (uint8_t)col[1]);
      c = (int16_t)(sub_122259() + 26);
      sub_134D2D(x, (int16_t)(sub_122259() + 26), 0x19, c, (uint8_t)col[0]);
    }
  }
  return sub_233FA();
}

//----- (001E4B3B) --------------------------------------------------------
/* 95E3E: dword 1E4B35 = edx, word 1E4B39 = word [ebp+5Ah] (v78 of sub_95BAA), call sub_1212B3, sub_1EE677 */
int Hook150_1E4B3B(int a1, int a2, int a3, int v78)
{
  int r;

  if ( !g_orion150 )
    return sub_1212B3(a1, a2, a3);
  *(int32_t *)ECODE150(0x1E4B35) = a2;
  *(int16_t *)ECODE150(0x1E4B39) = (int16_t)v78;
  r = sub_1212B3(a1, a2, a3);
  sub_1EE677(0);
  return r;
}

//----- (001E3A6B) --------------------------------------------------------
/* 981C7 in sub_980DB: unless byte_199CB4 == 1 and byte_199F3A > 1, the positive words 1E39F8[0..2] are
   appended to the list esi (a2) with the count [ecx] (a3); then sub_8A4C4 ([ebp-4] is the loop byte) */
int Hook150_1E3A6B(int a2, uint16_t *a3)
{
  int b;

  if ( g_orion150 && !(byte_199CB4 == 1 && (int8_t)byte_199F3A > 1) )
    for ( b = 0; b <= 2; ++b )
    {
      int16_t w = *(int16_t *)ECODE150(0x1E39F8 + 2 * b);

      if ( w > 0 )
        *(int16_t *)(intptr_t)(a2 + 2 * (int16_t)(*a3)++) = w;
    }
  return sub_8A4C4();
}

//----- (001E3906) --------------------------------------------------------
/* 9893F, 989F7 (1E3923): call sub_94B3A; ax -> sub_1FD613(ecx, word [ebp+14Eh] / -1) */
int Hook150_1E3906(int a1, unsigned int a2, int a3, int16_t *a4, int a5, int ecx, int arg)
{
  int r = sub_94B3A(a1, a2, a3, a4, a5);

  if ( g_orion150 && (int16_t)r )
    sub_1FD613(ecx, arg);
  return r;
}

//----- (001E41EE) --------------------------------------------------------
/* 9BB72 replaces sub_A44FC(byte, player): sub_1E4204(player) (byte +8BAh of the player) or sub_79E32 */
_BOOL1 Hook150_1E41EE(int a1, int a2)
{
  if ( !g_orion150 )
    return sub_A44FC(a1, a2);
  if ( sub_1E4204(a2) )
    return 1;
  return sub_79E32(a2, a1);
}

//----- (001E4544) --------------------------------------------------------
/* A08AA: byte_199BDF == 1 -> 1 without sub_A1341 */
char Hook150_1E4544(int a1)
{
  if ( g_orion150 && byte_199BDF == 1 )
    return 1;
  return sub_A1341(a1);
}

//----- (001E507C) --------------------------------------------------------
/* A217E replaces sub_79E06(player): byte +8BAh of the player != 0 */
_BOOL1 Hook150_1E507C(int a1)
{
  return g_orion150 ? sub_1E4204(a1) : sub_79E06(a1);
}

//----- (001E3DB6) --------------------------------------------------------
/* A5F53: call sub_103CAF / at most 176h */
int Hook150_1E3DB6(int a1, int a2)
{
  int r = sub_103CAF(a1, a2);

  return g_orion150 && (int16_t)r > 0x176 ? 0x176 : r;
}

//----- (001E4CFD) --------------------------------------------------------
/* ADF1F replaces sub_1247A0(10): byte +0ADh of record [ebp-2F8h] (v89 of sub_ADE18): > -1 -> 1, else it */
unsigned int Hook150_1E4CFD(unsigned int a1, int v89)
{
  int8_t b;

  if ( !g_orion150 )
    return sub_1247A0(a1);
  b = *(int8_t *)(dword_192864 + 0x139 * (int8_t)v89 + 0xAD);
  return b > -1 ? 1 : b;
}

//----- (001E4D69) --------------------------------------------------------
/* AEC50: call sub_147D7; byte 23F077 == 1 and byte +0ADh of record di > -1 -> sub_147D7(21h) */
int Hook150_1E4D69(int a1, int di)
{
  int r = sub_147D7(a1);

  if ( g_orion150 && *ESEG150(0x23F077) == 1 && *(int8_t *)(dword_192864 + 0x139 * (int16_t)di + 0xAD) > -1 )
    r = sub_147D7(0x21);
  return r;
}

//----- (001E0F84) --------------------------------------------------------
/* AF895: call sub_12779E; byte 1E0F83 == 1 -> sub_12779E(player record + 515h ([ebp-8] = v20), 1E0F1F, 63h) */
_BYTE *Hook150_1E0F84(_BYTE *a1, _BYTE *a2, unsigned int a3, int v20)
{
  _BYTE *r = sub_12779E(a1, a2, a3);

  if ( g_orion150 && *ECODE150(0x1E0F83) == 1 )
  {
    sub_12779E((_BYTE *)dword_197F98 + v20 + 0x515, ECODE150(0x1E0F1F), 0x63);
    *ECODE150(0x1E0F83) = 0;
  }
  return r;
}

//----- (001E4AB0) --------------------------------------------------------
/* B0614 replaces sub_120CCB: sub_1EAF5B(eax, edx, ebx, ecx = word_1827CE[si]) */
int Hook150_1E4AB0(int a1, int a2, int si)
{
  if ( !g_orion150 )
    return sub_120CCB(a1, a2);
  sub_1EAF5B(a1, a2, 0, word_1827CE[(int16_t)si]);
  return a1;
}

//----- (001E25A0) --------------------------------------------------------
/* B183E: call sub_77658; not 1 -> byte_1827BF = 0, sub_C0AF4 */
int Hook150_1E25A0(int a1)
{
  int r = sub_77658(a1);

  if ( g_orion150 && (uint8_t)r != 1 )
  {
    byte_1827BF = 0;
    sub_C0AF4();
  }
  return r;
}

//----- (001E05D8) --------------------------------------------------------
/* B2296 in sub_B2190: the new reserve of the ship (word +5Eh): m = a (the maximum) less sub_1E88EF's share;
   byte 23F186 < 1 -> max(2 * (x - v8), m), else max(x - v8, 0) + m */
int Hook150_1E05D8(int a, int x, int v8)
{
  int m = a, r;

  if ( (int8_t)*ESEG150(0x23F186) < 1 )
  {
    r = 2 * (x - v8);
    sub_1E88EF(word_19999C, (_DWORD *)&m);
    if ( r < m )
      r = m;
  }
  else
  {
    r = x - v8;
    if ( r < 0 )
      r = 0;
    sub_1E88EF(word_19999C, (_DWORD *)&m);
    r += m;
  }
  return r;
}

//----- (001E1019) --------------------------------------------------------
/* B2303 before sub_8A4C4: byte 1E0F83 == 1 -> sub_12779E(dword 1E0FF6, 1E0F1F, 63h), dword 1E0FF6 = 0;
   byte 1E0F83 = 0 */
void Hook150_1E1019(void)
{
  if ( !g_orion150 )
    return;
  if ( *ECODE150(0x1E0F83) == 1 )
  {
    sub_12779E((_BYTE *)(uintptr_t)*(uint32_t *)ECODE150(0x1E0FF6), ECODE150(0x1E0F1F), 0x63);
    *(uint32_t *)ECODE150(0x1E0FF6) = 0;
  }
  *ECODE150(0x1E0F83) = 0;
}

//----- (001E1EFC) --------------------------------------------------------
/* B25E9: sub_B09CE only with byte_199BE6 == 1 or byte 23CEF4, else 0 */
char Hook150_1E1EFC(void)
{
  if ( g_orion150 && byte_199BE6 != 1 && !*ESEG150(0x23CEF4) )
    return 0;
  return sub_B09CE();
}

//----- (001E10DC) --------------------------------------------------------
/* B2998, C1F25: byte 1E0F83 = 1, sub_12779E(1E0F1F, eax, ebx), then the call */
_BYTE *Hook150_1E10DC(_BYTE *a1, _BYTE *a2, unsigned int a3)
{
  if ( g_orion150 )
  {
    *ECODE150(0x1E0F83) = 1;
    sub_12779E(ECODE150(0x1E0F1F), a1, a3);
  }
  return sub_12779E(a1, a2, a3);
}

//----- (001E4561) --------------------------------------------------------
/* B3731: call sub_1212B3 / sub_120CCB(3, 1827ADh) */
int Hook150_1E4561(int a1, int a2, int a3)
{
  int r = sub_1212B3(a1, a2, a3);

  return g_orion150 ? sub_120CCB(3, (int)(intptr_t)unk_1827AD) : r;
}

//----- (001E23CA) --------------------------------------------------------
/* B4B46 replaces sub_A5EB2(eax, edx): sub_A5EBF(eax, edx, word 23CDFE) */
int16_t Hook150_1E23CA(int a1, int a2)
{
  return g_orion150 ? sub_A5EBF(a1, a2, *(int16_t *)ESEG150(0x23CDFE)) : sub_A5EB2(a1, a2);
}

//----- (001E23B5) --------------------------------------------------------
/* E8609, E8696, E94BA replace sub_77423(eax): sub_A5EBF(0, eax, word 23CDFE) */
int16_t Hook150_1E23B5(int a1)
{
  return g_orion150 ? sub_A5EBF(0, a1, *(int16_t *)ESEG150(0x23CDFE)) : sub_77423(a1);
}

//----- (001E4346) --------------------------------------------------------
/* C782B: byte_1831C5 == 1 -> sub_7A990(125h); word_1A1238 == 2 -> sub_CDF5C(5) */
int Hook150_1E4346(int a1)
{
  if ( !g_orion150 )
    return sub_CDF5C(a1);
  if ( byte_1831C5 == 1 )
    return (int)(intptr_t)sub_7A990(0x125);
  return sub_CDF5C(word_1A1238 == 2 ? 5 : a1);
}

//----- (001E490B) --------------------------------------------------------
/* EC2CF: call sub_94951; byte 23F08B == 1 -> (r + 1) * 15 / 2 (sar), else (r + 1) * 3 */
int Hook150_1E490B(int a1)
{
  int r = sub_94951(a1);

  if ( !g_orion150 )
    return r;
  return *ESEG150(0x23F08B) == 1 ? (((int16_t)r + 1) * 15) >> 1 : (r + 1) * 3;
}

//----- (001E48F4) --------------------------------------------------------
/* EC2E0: call sub_94951; byte 23F08B == 1 -> (r + 1) * 5, else (r + 1) * 2 */
int Hook150_1E48F4(int a1)
{
  int r = sub_94951(a1);

  if ( !g_orion150 )
    return r;
  return *ESEG150(0x23F08B) == 1 ? (r + 1) * 5 : (r + 1) * 2;
}

//----- (001E0819) --------------------------------------------------------
/* F74F7: call sub_110D3C / dword 240296 = the result */
PoolMemType *Hook150_1E0819(PoolMemType *a1, int a2)
{
  PoolMemType *r = sub_110D3C(a1, a2);

  if ( g_orion150 )
    *(uint32_t *)ESEG150(0x240296) = (uint32_t)(uintptr_t)r;
  return r;
}

//----- (001E1386) --------------------------------------------------------
/* FBC37 replaces sub_F6816: sub_1FB4A3(eax, edx, ebx, ecx pushed); eax unchanged */
int Hook150_1E1386(int a1, int a2, int a3, unsigned int a4)
{
  if ( !g_orion150 )
    return sub_F6816(a1, a2, a3, a4);
  sub_1FB4A3(0, (uint32_t *)(intptr_t)a1, a2, (_BYTE *)(intptr_t)a3, (int)a4);
  return a1;
}

//----- (001E04EA) --------------------------------------------------------
/* FDE7B, FDF60: sub_1E04C4 / call sub_8A4C4 */
int Hook150_1E04EA(void)
{
  if ( g_orion150 )
    sub_1E04C4();
  return sub_8A4C4();
}

//----- (001E1F26) --------------------------------------------------------
/* 10AC36: dword 1E1F22 = dword_184378 / jmp sub_11127C */
uint32_t *Hook150_1E1F26(int a1)
{
  if ( g_orion150 )
    *(int32_t *)ECODE150(0x1E1F22) = dword_184378;
  return (uint32_t *)sub_11127C(a1);
}

//----- (001E1F37) --------------------------------------------------------
/* 10AC5B: dword_184378 = dword 1E1F22 / jmp sub_1112B4 */
uint32_t *Hook150_1E1F37(int a1)
{
  if ( g_orion150 )
    dword_184378 = *(int32_t *)ECODE150(0x1E1F22);
  return (uint32_t *)sub_1112B4(a1);
}

//----- (001E4C28) --------------------------------------------------------
/* 10C5CD: byte 23F191 == 1 -> 0 instead of sub_11523B */
int Hook150_1E4C28(int a1, int a2, int a3, _WORD *a4, int a5, _BYTE *a6, int a7)
{
  if ( g_orion150 && *ESEG150(0x23F191) == 1 )
    return 0;
  return sub_11523B(a1, a2, a3, a4, a5, a6, a7);
}

//----- (001E700F) --------------------------------------------------------
/* 11C347: the words 24071E..240766 = -1, then sub_123C48 */
int16_t Hook150_1E700F(void)
{
  if ( g_orion150 )
  {
    uint32_t a;

    for ( a = 0x24071E; a != 0x240768; a += 2 )
      *(uint16_t *)ESEG150(a) = 0xFFFF;
  }
  return sub_123C48();
}

//----- (001E1893) --------------------------------------------------------
/* E2266, E2279 (1E1893: ebx), E22B2 (1E18A8: eax >> 1), E22E4 (1E18BF: the second value): the first value of
   the sprintf becomes mult * the signed byte at addr */
int Hook150_Mul8(int value, int mult, uint32_t addr)
{
  return g_orion150 ? mult * (int8_t)*ESEG150(addr) : value;
}

//----- (001E18EF) --------------------------------------------------------
/* E24BD, E24D4: the first value = byte 23CDF0[byte 23F0DB] * [ebp-10h] */
int Hook150_1E18EF(int value, int var10)
{
  return g_orion150 ? *ESEG150(0x23CDF0 + *ESEG150(0x23F0DB)) * var10 : value;
}

//----- (001E07E8) --------------------------------------------------------
/* F786D in sub_F74CD (save): sub_1FB25F(&[ebp-0Ch]) appends the data of 1.50 at the write pointer (v29) */
void Hook150_1E07E8(uint32_t *ptr)
{
  sub_1FB25F(0, 0, 0, ptr, 0, 0, 0);
}

//----- (001E0802) --------------------------------------------------------
/* F7E89 in sub_F79F6 (load): sub_1FA623(&[ebp-8]) reads the data of 1.50 at the read pointer (v22) */
void Hook150_1E0802(uint32_t *ptr)
{
  sub_1FA623(0, 0, 0, ptr);
}

//----- (001E4BBB) --------------------------------------------------------
/* F88CD in sub_F83D8: sub_1FA583(dword 1E4BA3 - the read pointer F8894 kept) before FE8BE */
void Hook150_1E4BBB(void)
{
  if ( g_orion150 )
    sub_1FA583(*(uint32_t *)ECODE150(0x1E4BA3), 0, 0, 0, 0);
}

/* ===== hooks that read the caller's frame or registers (one call site each) ===== */

//----- (001E37E4) --------------------------------------------------------
/* FFAA1 in sub_FF799: after sub_EB7FD, sub_1E9EAF([ebp-58h] = a1, word [ebp-5Ch] = a2) != 0 -> 0 and
   byte [esi+0Bh] = 1 (esi = a3) */
char Hook150_1E37E4(char r, int16_t *a1, int a2, uint8_t *a3)
{
  if ( !g_orion150 || !sub_1E9EAF(a1, (int16_t)a2) )
    return r;
  a3[0xB] = 1;
  return 0;
}

//----- (001E40BC) --------------------------------------------------------
/* FD5DE in sub_FD335: sub_FC734 again while sub_1EA743(result, [ebp-14h]) */
int Hook150_1E40BC(int var14)
{
  int r;

  do
    r = sub_FC734();
  while ( g_orion150 && sub_1EA743(r, var14) );
  return r;
}

//----- (001E3F2E) --------------------------------------------------------
/* 293C6 in sub_290DA: with word [ebp-2Ch] (w) and sub_4B0D3(w, 10) both coordinates lose sub_1E1295 */
int Hook150_1E3F2E(int a1, int a2, int a3, int a4, int a5, int w)
{
  if ( g_orion150 && (uint16_t)w && sub_4B0D3((uint16_t)w, 10) )
  {
    a1 -= sub_1E1295(a1);
    a2 -= sub_1E1295(a2);
  }
  return sub_EC0DE(a1, a2, a3, a4, a5);
}

//----- (001E24A8) --------------------------------------------------------
/* 29998 in sub_29837 after sub_2A9A5: byte +0B1h of record word_1998F8 = byte 1E248C */
void Hook150_1E24A8(void)
{
  if ( g_orion150 )
    *(uint8_t *)(dword_192864 + 0x139 * word_1998F8 + 0xB1) = *ECODE150(0x1E248C);
}

//----- (001E0DF8) --------------------------------------------------------
/* 3AB4D in sub_3A82F after sub_AD3CA: bl (byte [ebx+42h]) != FFh -> sub_1F9EFF(bl) */
void Hook150_1E0DF8(uint8_t b)
{
  if ( g_orion150 && b != 0xFF )
    sub_1F9EFF(b, 0);
}

//----- (001E3259) --------------------------------------------------------
/* 3E010 in sub_3DFE0 after sub_35EAE: + sub_36139(esi, 0) */
int Hook150_1E3259(int r, int esi)
{
  if ( !g_orion150 )
    return r;
  return r + sub_36139(esi, 0, 0);
}

//----- (001E011D) --------------------------------------------------------
/* 40378 in sub_40148: sub_3868F with word_1998A2 kept; its change goes to [ebp+56h] */
int Hook150_1E011D(int *var56)
{
  int16_t w = word_1998A2;
  int r = sub_3868F(1);

  if ( g_orion150 )
  {
    *var56 = (int16_t)(word_1998A2 - w);
    word_1998A2 = w;
  }
  return r;
}

//----- (001E0CD0) --------------------------------------------------------
/* 43065 in sub_42F7F after sub_42B70: sub_1F9B9B(cx) */
void Hook150_1E0CD0(int cx)
{
  if ( g_orion150 )
    sub_1F9B9B((int16_t)cx, 0, 0, 0);
}

//----- (001E4308) --------------------------------------------------------
/* 9C0F8 in sub_9BF70: si = 10 when byte +0Fh of record word [ebp+6Eh] (dword_1930D4, 17 bytes) is 10 */
int Hook150_1E4308(int16_t v66, int si)
{
  if ( g_orion150 && *(uint8_t *)((uint8_t *)dword_1930D4 + 17 * v66 + 0xF) == 10 )
    return 10;
  return si;
}

//----- (001E2AE8) --------------------------------------------------------
/* DDB8A in sub_DDB25: 0 with byte 23F0D9 == 1 and byte [ecx+89Fh] == 5, else sub_DDAD4 */
int Hook150_1E2AE8(int a1, char *ecx)
{
  if ( g_orion150 && *ESEG150(0x23F0D9) == 1 && ecx[0x89F] == 5 )
    return 0;
  return sub_DDAD4(a1);
}

/* LBX file opens: the name goes through sub_1EC7CF (the config's replacement, e.g. \150\lbx\NEWGAME.LBX) */
//----- (001E0646) --------------------------------------------------------
uint32_t *sub_126F3B(int a1, int a2, int a3, int a4, unsigned int a5, unsigned int a6, int a7)
{
  if ( g_orion150 )
    a1 = sub_1EC7CF(a1);
  return sub_126F3B_131(a1, a2, a3, a4, a5, a6, a7);
}

//----- (001E0670) --------------------------------------------------------
uint32_t *sub_12816C(int a1, int a2, int a3, int *a4)
{
  if ( g_orion150 )
    a1 = sub_1EC7CF(a1);
  return sub_12816C_131(a1, a2, a3, a4);
}

//----- (001E0654) --------------------------------------------------------
uint32_t *sub_126CEB(int a1, int a2, int a3, int a4)
{
  if ( g_orion150 )
    a1 = sub_1EC7CF(a1);
  return sub_126CEB_131(a1, a2, a3, a4);
}

//----- (001E0662) --------------------------------------------------------
int sub_127233(int a1, int a2, int a3, int a4)
{
  if ( g_orion150 )
    a1 = sub_1EC7CF(a1);
  return sub_127233_131(a1, a2, a3, a4);
}

//----- (001E067E) --------------------------------------------------------
/* xchg eax, edx: the name is the second argument */
int sub_13AD33(int16_t *a1, int a2)
{
  if ( g_orion150 )
    a2 = sub_1EC7CF(a2);
  return sub_13AD33_131(a1, a2);
}

//----- (001E0638) --------------------------------------------------------
/* cmp byte 1E0621, 1 / jz sub_5DF0A / retn: the caller runs sub_5DF0A only when this returns 1 */
int Hook150_1E0638(void)
{
  return ecode[0x1E0621 - 0x1E0000] == 1;
}
