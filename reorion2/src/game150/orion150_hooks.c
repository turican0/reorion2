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

//----- (001E2CEE) --------------------------------------------------------
/* replaces sub_ED8BF: sub_100828, sub_14A27 */
void sub_ED8BF(int a1)
{
  if ( !g_orion150 )
  {
    sub_ED8BF_131(a1);
    return;
  }
  sub_100828();
  sub_14A27();
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
