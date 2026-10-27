#include "orion_common.h"

/* Adresni rozsah: 0x23780 - 0x38858  (200 funkci) */

//----- (00023780) --------------------------------------------------------
void sub_23780( int a1)
{
  int16_t v2; // dx
  int16_t i; // ax
  int16_t v4; // dx
  unsigned int v5; // esi
  int v6; // edx
  /* wave 182: v7..v10 are one 73-byte record in the frame (ebp-4Ch) */
  _BYTE blk23780_v7[73];
#define v7 ((_BYTE *)(blk23780_v7 + 0))
#define v8 (*(int16_t *)(blk23780_v7 + 3))
#define v9 (*(char *)(blk23780_v7 + 5))
#define v10 (*(int16_t *)(blk23780_v7 + 6))

  memset(v7, 0, 73);
  v7[0] = -1;
  v7[2] = 1;
  v7[1] = a1;
  v2 = 0;
  for ( i = 0; i < 49; ++i )
  {
    if ( *(_BYTE *)(i + 361 * a1 + (uint8_t*)dword_192B18 + 310) )
      ++v2;
  }
  v4 = *(uint8_t *)((uint8_t*)dword_192B18 + 361 * a1 + 10) + v2;
  v5 = sub_1247A0(3u);
  v6 = (int)(v4 * (v5 + sub_1247A0(3u))) / 10;
  if ( !(_WORD)v6 )
    LOWORD(v6) = 1;
  v9 = 0;
  v10 = 0;
  v8 = v6;
  sub_DD2F2((int)v7);
#undef v7
#undef v8
#undef v9
#undef v10
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int (uint8_t*)dword_192B18;


//----- (00023833) --------------------------------------------------------
void sub_23833( int a1)
{
  int v2; // ebx
  unsigned int v3; // edx
  /* wave 182: v4..v7 are one 73-byte record in the frame (ebp-4Ch) */
  _BYTE blk23833_v4[73];
#define v4 ((_BYTE *)(blk23833_v4 + 0))
#define v5 (*(int16_t *)(blk23833_v4 + 3))
#define v6 (*(char *)(blk23833_v4 + 5))
#define v7 (*(int16_t *)(blk23833_v4 + 6))

  memset(v4, 0, 73);
  v4[0] = -1;
  v4[2] = 1;
  v5 = 1;
  v6 = 1;
  v4[1] = a1;
  v2 = *(uint8_t *)((uint8_t*)dword_192B18 + 361 * a1 + 10);
  v3 = sub_1247A0(3u);
  v7 = (int)(v2 * (v3 + sub_1247A0(3u))) / 10;
  sub_DD2F2((int)v4);
#undef v4
#undef v5
#undef v6
#undef v7
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int (uint8_t*)dword_192B18;


//----- (000238A8) --------------------------------------------------------
int sub_238A8( int a1, _WORD *a2, _WORD *a3)
{
  int16_t v4; // dx
  int16_t i; // ax
  int16_t v6; // dx
  unsigned int v7; // edi
  int v8; // edx
  int result; // eax
  /* wave 182: v11..v16 are one 73-byte record in the frame (ebp-50h) */
  _BYTE blk238A8_v11[73];
#define v11 ((_BYTE *)(blk238A8_v11 + 0))
#define v12 (*(int16_t *)(blk238A8_v11 + 3))
#define v13 (*(char *)(blk238A8_v11 + 5))
#define v14 (*(int16_t *)(blk238A8_v11 + 6))
#define v15 (*(int16_t *)(blk238A8_v11 + 12))
#define v16 ((_BYTE *)(blk238A8_v11 + 14))
  int v17; // [esp+50h] [ebp-4h]

  memset(v11, 0, 73);
  v11[0] = -1;
  v11[2] = 1;
  v4 = 0;
  v11[1] = a1;
  for ( i = 0; i < 49; ++i )
  {
    v17 = 361 * a1;
    if ( *(_BYTE *)((uint8_t*)dword_192B18 + v17 + i + 310) )
      ++v4;
  }
  v6 = *(uint8_t *)(361 * a1 + (uint8_t*)dword_192B18 + 10) + v4;
  v7 = sub_1247A0(3u);
  v8 = (int)(v6 * (v7 + sub_1247A0(2u))) / 10;
  if ( !(_WORD)v8 )
    LOWORD(v8) = 1;
  v13 = 0;
  v14 = 0;
  v12 = v8;
  sub_DD2F2((int)v11);
  *a2 = v15;
  *a3 = 0;
  result = 0;
  do
  {
    if ( v16[(int16_t)result] == 1 )
      ++*a3;
    ++result;
  }
  while ( (int16_t)result < 49 );
  return result;
#undef v11
#undef v12
#undef v13
#undef v14
#undef v15
#undef v16
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int (uint8_t*)dword_192B18;


//----- (00023988) --------------------------------------------------------
int sub_23988( int a1, int a2)
{
  int16_t v2; // si
  int v3; // ebx
  int v4; // ecx
  int16_t v5; // dx

  v2 = -1;
  v3 = 0;
  v4 = -1;
  while ( (int16_t)v3 < word_199996 )
  {
    if ( *(char *)(361 * (int16_t)v3 + (uint8_t*)dword_192B18) == a1 )
    {
      v5 = sub_239E8(v3, a2);
      if ( v5 < v2 || v2 == -1 )
      {
        v2 = v5;
        v4 = v3;
      }
    }
    ++v3;
  }
  return v4;
}
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (000239E8) --------------------------------------------------------
int sub_239E8( int a1, int a2)
{
  int v2; // eax
  int16_t v3; // bx
  int16_t v4; // cx
  int v5; // eax
  int16_t v6; // si
  int64_t v7; // rax
  int v8; // ebx

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  v2 = 113 * *(uint8_t *)(17 * *(int16_t *)((uint8_t*)dword_192B18 + 361 * a1 + 2) + (uint8_t*)dword_1930D4 + 2) + dword_19306C;
  v3 = *(_WORD *)(v2 + 15);
  v4 = *(_WORD *)(v2 + 17);
  v5 = dword_197F9C + 129 * a2;
  v6 = *(_WORD *)(v5 + 105);
  v7 = v3 - *(int16_t *)(v5 + 103);
  v8 = ((HIDWORD(v7) ^ v7) - HIDWORD(v7)) * ((HIDWORD(v7) ^ v7) - HIDWORD(v7));
  LODWORD(v7) = abs32(v4 - v6);
  return v8 + v7 * v7;
}
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int (uint8_t*)dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;


//----- (00023A5F) --------------------------------------------------------
int sub_23A5F()
{
  int16_t v0; // di
  int16_t v1; // si
  int16_t v2; // dx
  int16_t i; // bx
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v0 = 0;
  v1 = 0;
  v2 = sub_1247A0(word_19999A) - 1;
  while ( !v0 && v1 < 1000 )
  {
    if ( *(_BYTE *)(dword_19306C + 113 * v2 + 56) )
    {
      for ( i = 0; i < 5; ++i )
      {
        v4 = *(int16_t *)(113 * v2 + dword_19306C + 2 * i + 74);
        if ( v4 != -1 )
        {
          v5 = *(int16_t *)((uint8_t*)dword_1930D4 + 17 * v4);
          if ( v5 != -1 )
          {
            v6 = (uint8_t*)dword_192B18 + 361 * v5;
            if ( !*(_BYTE *)(v6 + 6) && !*(_BYTE *)(v6 + 319) )
              v0 = 1;
          }
        }
      }
    }
    else
    {
      v2 = sub_1247A0(word_19999A) - 1;
    }
    ++v1;
  }
  if ( v1 > 990 )   /* wave 184: 23B13 cmp si, 3DEh; jle 231AD */
    v2 = -1;
  return v2;
}
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int (uint8_t*)dword_1930D4;
// 19999A: using guessed type int16_t word_19999A;


//----- (00023B28) --------------------------------------------------------
int sub_23B28( int a1)
{
  int v2; // edx
  int16_t v3; // bx
  int v4; // eax

  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = dword_197F9C + 129 * v3;
    if ( a1 == *(_WORD *)(v4 + 101) && !*(_BYTE *)(v4 + 100) )
    {
      LOWORD(v4) = *(uint8_t *)(v4 + 16);
      v2 += v4 + 1;
    }
    if ( ++v3 >= 500 )
      return v2;   /* wave 181: tail loc_2227B `mov     eax, edx` */
  }
}
// 197F9C: using guessed type int dword_197F9C;


//----- (00023B64) --------------------------------------------------------
int16_t sub_23B64( int a1)
{
  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  return *(_WORD *)(361 * a1 + (uint8_t*)dword_192B18 + 235);
}
// 192B18: using guessed type int (uint8_t*)dword_192B18;


//----- (00023B7D) --------------------------------------------------------
int sub_23B7D( int a1)
{
  int v1; // esi
  int16_t i; // bx
  int v2; // ecx - the picked player

  v1 = 0;
  v2 = -1;
  for ( i = 0; i < word_199998; ++i )
  {
    if ( !*(_BYTE *)((uint8_t*)dword_197F98 + 3753 * i + 36)
      && (uint16_t)sub_1276F0((uint8_t*)dword_197F98 + 3753 * a1 + 1412, i)
      && i != a1
      && sub_1247A0((int16_t)++v1) == 1 )
    {
      v2 = i;   /* wave 184: 23BD9 mov ecx, ebx */
    }
  }
  return v2;   /* wave 184: 23BE5 mov eax, ecx */
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00023BEC) --------------------------------------------------------
int sub_23BEC( int a1)
{
  int16_t v1; // si
  int16_t i; // dx
  int16_t j; // bx
  int v4; // eax
  int v5; // eax
  char *v6; // eax
  int v7; // edi - the picked star

  v7 = -1;
  v1 = 0;
  for ( i = 0; i < word_19999A; ++i )
  {
    if ( *(char *)(dword_19306C + 113 * i + 20) == a1 )
    {
      for ( j = 0; j < 5; ++j )
      {
        v4 = *(int16_t *)(113 * i + dword_19306C + 2 * j + 74);
        if ( v4 != -1 )
        {
          v5 = *(int16_t *)((uint8_t*)dword_1930D4 + 17 * v4);
          if ( v5 != -1 )
          {
            v6 = (char *)((uint8_t*)dword_192B18 + 361 * v5);
            if ( !v6[6] && *v6 == a1 )
            {
              if ( !++v1 || sub_1247A0(v1) == 1 )   /* wave 184: 23C72 inc si; jz */
                v7 = i;
            }
          }
        }
      }
    }
  }
  return v7;   /* wave 184: 23C9A mov eax, edi */
}
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int (uint8_t*)dword_1930D4;
// 19999A: using guessed type int16_t word_19999A;


//----- (00023CA1) --------------------------------------------------------
int sub_23CA1( int a1)
{
  int v2; // esi
  int16_t v3; // dx
  int v4; // eax
  int v5; // ebx - the picked index (no caller in the original)

  v2 = 0;
  v5 = -1;
  for ( v3 = 0; v3 < 67; ++v3 )
  {
    v4 = dword_1930DC + 59 * v3;
    if ( (int16_t)a1 == *(char *)(v4 + 58) && *(char *)(v4 + 57) >= 0 && sub_1247A0((int16_t)++v2) == 1 )
      v5 = v3;   /* wave 184: 23CDD mov ebx, edx */
  }
  return v5;   /* wave 184: 23CE6 mov eax, ebx */
}
// 1930DC: using guessed type int dword_1930DC;


//----- (00023CED) --------------------------------------------------------
int sub_23CED( int a1)
{
  int v2; // ebx
  int16_t i; // dx
  int v4; // eax
  int v5; // esi - the picked ship

  v2 = 0;
  v5 = -1;
  for ( i = 0; i < word_199994; ++i )
  {
    v4 = dword_197F9C + 129 * i;
    if ( (int16_t)a1 == *(char *)(v4 + 99) && *(_BYTE *)(v4 + 100) <= 1u && sub_1247A0((int16_t)++v2) == 1 )
      v5 = i;   /* wave 184: 23D34 mov esi, edx */
  }
  return v5;   /* wave 184: 23D40 mov eax, esi */
}
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (00023D44) --------------------------------------------------------
int sub_23D44( int a1)
{
  int v2; // esi
  int v3; // ebx
  int i; // edx
  int v6; // [esp+0h] [ebp-4h]

  v2 = -1;
  v3 = 0;
  for ( i = 0; (int16_t)i < word_199996; ++i )
  {
    v6 = 361 * (int16_t)i;
    if ( a1 == *(char *)(v6 + (uint8_t*)dword_192B18) && !*(_BYTE *)(v6 + (uint8_t*)dword_192B18 + 6) && sub_1247A0((int16_t)++v3) == 1 )
      v2 = i;
  }
  return v2;
}
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (00023DA0) --------------------------------------------------------
int sub_23DA0( int a1)
{
  int v2; // ebx
  int16_t i; // dx
  char *v4; // eax
  int v5; // esi - the picked colony

  v2 = 0;
  v5 = -1;
  for ( i = 0; i < word_199996; ++i )
  {
    v4 = (char *)(361 * i + (uint8_t*)dword_192B18);
    if ( (int16_t)a1 == *v4 && !v4[319] && !v4[6] && sub_1247A0((int16_t)++v2) == 1 )
      v5 = i;   /* 23DF0 mov esi, edx */
  }
  return v5;   /* wave 184: 23DFC jmp 23D97 (mov eax, esi) */
}
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (00023DFE) --------------------------------------------------------
bool sub_23DFE( int a1)
{
  return (byte_19AC35 == 2 || byte_19AC35 == 6) && a1 == word_19AC37
      || (byte_19AC7D == 2 || byte_19AC7D == 6)
      && *(uint8_t *)((uint8_t*)dword_1930D4 + 17 * *(int16_t *)(361 * a1 + (uint8_t*)dword_192B18 + 2) + 2) == word_19AC7F;
}
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 1930D4: using guessed type int (uint8_t*)dword_1930D4;
// 19AC35: using guessed type char byte_19AC35;
// 19AC37: using guessed type int16_t word_19AC37;
// 19AC7D: using guessed type char byte_19AC7D;
// 19AC7F: using guessed type int16_t word_19AC7F;


//----- (00023E60) --------------------------------------------------------
int sub_23E60( int a1)
{
  if ( (byte_19ABB7 == 2 || byte_19ABB7 == 4 || byte_19ABB7 == 6) && a1 == word_19ABB9 )
    return 2;
  if ( (byte_19AC35 == 2 || byte_19AC35 == 4 || byte_19AC35 == 6) && a1 == word_19AC37 )
    return 16;
  if ( (byte_19AC3E == 2 || byte_19AC3E == 4 || byte_19AC3E == 6) && a1 == word_19AC40 )
    return 17;
  if ( (byte_19AC86 == 2 || byte_19AC86 == 4 || byte_19AC86 == 6)
    && *(uint8_t *)(17 * *(int16_t *)((uint8_t*)dword_192B18 + 361 * a1 + 2) + (uint8_t*)dword_1930D4 + 2) == word_19AC88 )
  {
    return 25;
  }
  if ( (byte_19AC23 == 2 || byte_19AC23 == 4 || byte_19AC23 == 6)
    && *(uint8_t *)(17 * *(int16_t *)(361 * a1 + (uint8_t*)dword_192B18 + 2) + (uint8_t*)dword_1930D4 + 2) == word_19AC25 )
  {
    return 14;
  }
  if ( (byte_19AC7D == 2 || byte_19AC7D == 4 || byte_19AC7D == 6)
    && *(uint8_t *)(17 * *(int16_t *)(361 * a1 + (uint8_t*)dword_192B18 + 2) + (uint8_t*)dword_1930D4 + 2) == word_19AC7F )
  {
    return 24;
  }
  return -1;
}
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 1930D4: using guessed type int (uint8_t*)dword_1930D4;
// 19ABB7: using guessed type char byte_19ABB7;
// 19ABB9: using guessed type int16_t word_19ABB9;
// 19AC23: using guessed type char byte_19AC23;
// 19AC25: using guessed type int16_t word_19AC25;
// 19AC35: using guessed type char byte_19AC35;
// 19AC37: using guessed type int16_t word_19AC37;
// 19AC3E: using guessed type char byte_19AC3E;
// 19AC40: using guessed type int16_t word_19AC40;
// 19AC7D: using guessed type char byte_19AC7D;
// 19AC7F: using guessed type int16_t word_19AC7F;
// 19AC86: using guessed type char byte_19AC86;
// 19AC88: using guessed type int16_t word_19AC88;


//----- (0002401F) --------------------------------------------------------
void sub_2401F( int a1)
{
  int16_t v5; // bx
  int16_t i; // dx
  int16_t v7; // si
  int16_t j; // dx
  int16_t v9; // si
  int16_t v10; // bx
  int16_t k; // ax

  if ( (byte_19ABB7 == 2 || byte_19ABB7 == 4 || byte_19ABB7 == 6) && a1 == word_19ABB9 )
  {
    byte_19ABB7 = 3;
    byte_19ABB6 = -1;
  }
  if ( (byte_19AC35 == 2 || byte_19AC35 == 4 || byte_19AC35 == 6) && a1 == word_19AC37 )
  {
    byte_19AC35 = 3;
    byte_19AC34 = -1;
  }
  if ( (byte_19AC3E == 2 || byte_19AC3E == 4 || byte_19AC3E == 6) && a1 == word_19AC40 )
  {
    byte_19AC3E = 3;
    byte_19AC3D = -1;
  }
  if ( (byte_19AC86 == 2 || byte_19AC86 == 4 || byte_19AC86 == 6)
    && *(uint8_t *)(17 * *(int16_t *)(361 * a1 + (uint8_t*)dword_192B18 + 2) + (uint8_t*)dword_1930D4 + 2) == word_19AC88 )
  {
    v5 = 0;
    for ( i = 0; i < word_199998; ++i )
    {
      if ( (((int)*(uint8_t *)(dword_19306C
                                     + 113
                                     * *(uint8_t *)(17 * *(int16_t *)(361 * a1 + (uint8_t*)dword_192B18 + 2)
                                                          + (uint8_t*)dword_1930D4
                                                          + 2)
                                     + 56) >> i)
          & 1) != 0 )
        ++v5;
    }
    if ( v5 < 2 )
    {
      byte_19AC86 = 3;
      byte_19AC85 = -1;
    }
  }
  if ( (byte_19AC23 == 2 || byte_19AC23 == 4 || byte_19AC23 == 6)
    && *(uint8_t *)(17 * *(int16_t *)((uint8_t*)dword_192B18 + 361 * a1 + 2) + (uint8_t*)dword_1930D4 + 2) == word_19AC25 )
  {
    v7 = 0;
    for ( j = 0; j < word_199998; ++j )
    {
      if ( (((int)*(uint8_t *)(dword_19306C
                                     + 113
                                     * *(uint8_t *)(17 * *(int16_t *)((uint8_t*)dword_192B18 + 361 * a1 + 2)
                                                          + (uint8_t*)dword_1930D4
                                                          + 2)
                                     + 56) >> j)
          & 1) != 0 )
        ++v7;
    }
    if ( v7 < 2 )
    {
      byte_19AC23 = 3;
      byte_19AC22 = -1;
    }
  }
  if ( byte_19AC7D == 2 || byte_19AC7D == 4 || byte_19AC7D == 6 )
  {
    v9 = *(uint8_t *)(17 * *(int16_t *)(361 * a1 + (uint8_t*)dword_192B18 + 2) + (uint8_t*)dword_1930D4 + 2);
    if ( v9 == word_19AC7F )
    {
      v10 = 0;
      for ( k = 0; k < word_199998; ++k )
      {
        if ( (((int)*(uint8_t *)(113 * v9 + dword_19306C + 56) >> k) & 1) != 0 )
          ++v10;
      }
      if ( v10 < 2 )
      {
        byte_19AC7D = 3;
        byte_19AC7C = -1;
      }
    }
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x23D9A je epilog funkce */
}
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int (uint8_t*)dword_1930D4;
// 199998: using guessed type int16_t word_199998;
// 19ABB6: using guessed type char byte_19ABB6;
// 19ABB7: using guessed type char byte_19ABB7;
// 19ABB9: using guessed type int16_t word_19ABB9;
// 19AC22: using guessed type char byte_19AC22;
// 19AC23: using guessed type char byte_19AC23;
// 19AC25: using guessed type int16_t word_19AC25;
// 19AC34: using guessed type char byte_19AC34;
// 19AC35: using guessed type char byte_19AC35;
// 19AC37: using guessed type int16_t word_19AC37;
// 19AC3D: using guessed type char byte_19AC3D;
// 19AC3E: using guessed type char byte_19AC3E;
// 19AC40: using guessed type int16_t word_19AC40;
// 19AC7C: using guessed type char byte_19AC7C;
// 19AC7D: using guessed type char byte_19AC7D;
// 19AC7F: using guessed type int16_t word_19AC7F;
// 19AC85: using guessed type char byte_19AC85;
// 19AC86: using guessed type char byte_19AC86;
// 19AC88: using guessed type int16_t word_19AC88;


//----- (000242CF) --------------------------------------------------------
bool sub_242CF( int a1)
{
  return (byte_19AC86 == 2 || byte_19AC86 == 4 || byte_19AC86 == 6) && a1 == word_19AC88;
}
// 19AC86: using guessed type char byte_19AC86;
// 19AC88: using guessed type int16_t word_19AC88;


//----- (000242FC) --------------------------------------------------------
int sub_242FC( int a1)
{
  if ( (byte_19ABB7 == 2 || byte_19ABB7 == 4 || byte_19ABB7 == 6)
    && *(uint8_t *)(17 * *(int16_t *)(361 * word_19ABB9 + (uint8_t*)dword_192B18 + 2) + (uint8_t*)dword_1930D4 + 2) == a1 )
  {
    return 2;
  }
  if ( (byte_19AC35 == 2 || byte_19AC35 == 4 || byte_19AC35 == 6)
    && *(uint8_t *)((uint8_t*)dword_1930D4 + 17 * *(int16_t *)((uint8_t*)dword_192B18 + 361 * word_19AC37 + 2) + 2) == a1 )
  {
    return 16;
  }
  if ( (byte_19AC3E == 2 || byte_19AC3E == 4 || byte_19AC3E == 6)
    && *(uint8_t *)(17 * *(int16_t *)((uint8_t*)dword_192B18 + 361 * word_19AC40 + 2) + (uint8_t*)dword_1930D4 + 2) == a1 )
  {
    return 17;
  }
  if ( (byte_19AC86 == 2 || byte_19AC86 == 4 || byte_19AC86 == 6) && a1 == word_19AC88 )
    return 25;
  if ( (byte_19AC23 == 2 || byte_19AC23 == 4 || byte_19AC23 == 6) && a1 == word_19AC25 )
    return 14;
  if ( (byte_19AC7D == 2 || byte_19AC7D == 4 || byte_19AC7D == 6) && a1 == word_19AC7F )
    return 24;
  return -1;
}
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 1930D4: using guessed type int (uint8_t*)dword_1930D4;
// 19ABB7: using guessed type char byte_19ABB7;
// 19ABB9: using guessed type int16_t word_19ABB9;
// 19AC23: using guessed type char byte_19AC23;
// 19AC25: using guessed type int16_t word_19AC25;
// 19AC35: using guessed type char byte_19AC35;
// 19AC37: using guessed type int16_t word_19AC37;
// 19AC3E: using guessed type char byte_19AC3E;
// 19AC40: using guessed type int16_t word_19AC40;
// 19AC7D: using guessed type char byte_19AC7D;
// 19AC7F: using guessed type int16_t word_19AC7F;
// 19AC86: using guessed type char byte_19AC86;
// 19AC88: using guessed type int16_t word_19AC88;


//----- (0002448F) --------------------------------------------------------
int16_t sub_2448F( int a1)
{
  int v2; // eax
  int16_t i; // dx

  LOWORD(v2) = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    if ( (((int)*(uint8_t *)(113 * a1 + dword_19306C + 56) >> i) & 1) != 0 )
      LOWORD(v2) = *(_WORD *)((uint8_t*)dword_197F98 + 3753 * i + 60) + v2;
  }
  switch ( byte_199CB0 )
  {
    case 0:
      v2 = (int16_t)v2;
      goto LABEL_8;
    case 1:
      v2 = 2 * (int16_t)v2;
      goto LABEL_8;
    case 2:
      v2 = 3 * (int16_t)v2;
      goto LABEL_8;
    case 4:
      v2 = 4 * (int16_t)v2;
LABEL_8:
      v2 /= 5;
      break;
    default:
      break;
  }
  if ( (int16_t)v2 < 5 )
    LOWORD(v2) = 0;
  return v2;
}
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (00024511) --------------------------------------------------------
int sub_24511()
{
  int16_t v0; // cx
  int16_t v1; // si
  int16_t i; // bx
  int v3; // edi
  int v4; // eax
  int v5; // edx

  if ( byte_199BDE )
  {
    if ( byte_199CAF )
      v0 = 8;
    else
      v0 = 6;
  }
  else if ( byte_199CAF )
  {
    v0 = 12;
  }
  else
  {
    v0 = 10;
  }
  v1 = -1;
  for ( i = 0; i < word_199998 && v1 == -1; ++i )
  {
    v3 = 3753 * i;
    v4 = v3 + (uint8_t*)dword_197F98;
    if ( !*(_BYTE *)(v3 + (uint8_t*)dword_197F98 + 36) && *(_BYTE *)(v4 + 2233) == 1 )
    {
      v5 = *(int16_t *)(v4 + 3699) / v0;
      if ( (int)sub_1247A0(0x3E8u) <= v5 )
      {
        v1 = i;
        *(_WORD *)(v3 + (uint8_t*)dword_197F98 + 3699) = 0;
      }
    }
  }
  return v1;   /* wave 181: tail loc_23D97 `mov     eax, esi` */
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199BDE: using guessed type char byte_199BDE;
// 199CAF: using guessed type char byte_199CAF;


//----- (000245C4) --------------------------------------------------------
void sub_245C4()
{
  int16_t i; // dx
  int v1; // eax

  for ( i = 0; i < word_199998; ++i )
  {
    v1 = 3753 * i + (uint8_t*)dword_197F98;
    if ( !*(_BYTE *)(v1 + 36) && *(_BYTE *)(v1 + 2233) == 1 )
      ++*(_WORD *)(v1 + 3699);
  }
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000245FD) --------------------------------------------------------
int16_t sub_245FD(int16_t *a1)
{
  int16_t result; // ax
  int16_t i; // ax
  int16_t j; // dx
  int v4; // ecx

  result = IsMemPoolReady_110B5C();
  if ( result != 1 )
  {
    sub_121C24(0, 0, (uint8_t)byte_199CAE, (int)&unk_178BB0);
    for ( i = 0; i < word_199998; ++i )
    {
      if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * i + 40) == 100 )
      {
        for ( j = 0; j < word_199998; ++j )
        {
          v4 = j;
          *(_BYTE *)(v4 + 3753 * i + (uint8_t*)dword_197F98 + 1412) = 1;
        }
      }
    }
    return sub_2490D(a1);
  }
  return result;
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CAE: using guessed type char byte_199CAE;


//----- (00024677) --------------------------------------------------------
int sub_24677(int result, int a2, int a3)
{
  int v3; // eax
  int v4; // eax

  if ( byte_199BEF == 1 )
  {
    if ( (_WORD)result != word_180EB8 )
    {
      word_180EB6 = 1;
      word_180EB8 = result;
      word_180EBA = a2;
    }
    switch ( word_180EB6 )
    {
      case 1:
        result = sub_113C28(30);
        word_180EB6 = 2;
        return result;
      case 2:
        result = sub_113B56();
        if ( (_WORD)result )
          return result;
        sub_113A4E();
        if ( word_180EB8 <= 100 )
        {
          sub_1136EC(aStreamLbx);
          v3 = word_180EB8;
        }
        else
        {
          sub_1136EC(aStreamhdLbx);
          v3 = word_180EB8 - 100;
        }
        sub_113A20(v3);
        word_180EB4 = word_180EB8;
        if ( word_180EBA == -1 && a3 == 1 )
          sub_113BAC(-1);
        sub_113AF2(0);
        sub_113CBD(30);
        result = word_180EBA;
        if ( word_180EBA != -1 )
        {
          word_180EB6 = 3;
          return result;
        }
        goto LABEL_27;
      case 3:
        result = sub_113BCE();
        if ( !result )
        {
          sub_113A4E();
          if ( word_180EBA == -2 )
          {
            word_180EB4 = j___clock(-2, 0, a3) % 3uLL + 1;
            sub_1136EC(aStreamLbx);
            sub_113A20(word_180EB4);
          }
          else
          {
            if ( word_180EBA <= 100 )
            {
              sub_1136EC(aStreamLbx);
              v4 = word_180EBA;
            }
            else
            {
              sub_1136EC(aStreamhdLbx);
              v4 = word_180EBA - 100;
            }
            sub_113A20(v4);
            word_180EB4 = word_180EBA;
          }
          if ( a3 == 1 )
            sub_113BAC(-1);
          sub_113AF2(0);
          result = sub_113CBD(30);
LABEL_27:
          word_180EB6 = 4;
        }
        break;
    }
  }
  return result;
}
// 129FE4: using guessed type int64_t j___clock(_DWORD, _DWORD, _DWORD);
// 180EB4: using guessed type int16_t word_180EB4;
// 180EB6: using guessed type int16_t word_180EB6;
// 180EB8: using guessed type int16_t word_180EB8;
// 180EBA: using guessed type int16_t word_180EBA;
// 199BEF: using guessed type char byte_199BEF;


//----- (00024831) --------------------------------------------------------
int sub_24831()
{
  word_180EB8 = -1;
  word_180EB4 = -1;
  sub_113AF2(0);
  return sub_113A4E();
}
// 180EB4: using guessed type int16_t word_180EB4;
// 180EB8: using guessed type int16_t word_180EB8;


//----- (0002484F) --------------------------------------------------------
int sub_2484F()
{
  int16_t v0; // dx
  int v1; // eax
  int v2; // eax
  int result = 0; // eax  // vlna 15: Hex-Rays artefakt neinicializovaneho navratu
                          // (byte_199BEF != 1 -> return result). Debug RTC jinak pada.

  PortDebug_Checkpoint("hudba.2484F_vstup", (int)word_180EB4);
  if ( byte_199BEF == 1 )
  {
    word_180EB8 = -1;
    if ( word_180EB4 != 1 && word_180EB4 != 2 && word_180EB4 != 3 )
    {
      PortDebug_Checkpoint("hudba.2484F_spousti", 1);
      sub_113C28(1);
      v0 = sub_113B56();
      while ( v0 > 0 )
      {
        v1 = sub_113B56();
        v0 = v1;
        ServiceAudioTick_FE8BE(v1, 0, 0, 0);
      }
      v2 = sub_113A4E();
      word_180EB4 = j___clock(v2, 0, 3) % 3uLL + 1;
      sub_1136EC(aStreamLbx);
      sub_113A20(word_180EB4);
      sub_113BAC(-1);
      word_180EB8 = -1;
      sub_113AF2(0);
      PortDebug_Checkpoint("hudba.2484F_pred_113CBD", (int)word_180EB4);
      return sub_113CBD(30);
    }
  }
  return result;
}
// FE8BE: using guessed type int ServiceAudioTick_FE8BE(_DWORD);
// 129FE4: using guessed type int64_t j___clock(_DWORD, _DWORD, _DWORD);
// 180EB4: using guessed type int16_t word_180EB4;
// 180EB8: using guessed type int16_t word_180EB8;
// 199BEF: using guessed type char byte_199BEF;


//----- (0002490D) --------------------------------------------------------
int sub_2490D(int16_t *a1)
{
  int v1; // ebx
  int16_t v2; // cx
  int result; // eax

  if ( byte_199BEF == 1 )
  {
    word_180EB8 = -1;
    sub_113C28(1);
    v1 = 0;
    v2 = sub_113B56();
    while ( v2 > 0 )
    {
      v2 = sub_113B56();
      if ( !((int16_t)v1 % 18) )
        ServiceAudioTick_FE8BE((int16_t)v1 / 18, 0, v1, a1);
      ++v1;
    }
    result = sub_113A4E();
    word_180EB4 = -1;
  }
  return result;
}
// 180EB4: using guessed type int16_t word_180EB4;
// 180EB8: using guessed type int16_t word_180EB8;
// 199BEF: using guessed type char byte_199BEF;


//----- (0002496C) --------------------------------------------------------
int sub_2496C()
{
  int16_t v0; // dx
  int v1; // eax
  int v2; // eax
  int result; // eax

  if ( byte_199BEF == 1 )
  {
    word_180EB8 = -1;
    sub_113C28(1);
    v0 = sub_113B56();
    while ( v0 > 0 )
    {
      v1 = sub_113B56();
      v0 = v1;
      ServiceAudioTick_FE8BE(v1, 0, 0, 0);
    }
    v2 = sub_113A4E();
    word_180EB4 = j___clock(v2, 0, 3) % 3uLL + 4;
    sub_1136EC(aStreamLbx);
    sub_113A20(word_180EB4);
    sub_113BAC(-1);
    sub_113AF2(0);
    return sub_113CBD(30);
  }
  return result;
}
// FE8BE: using guessed type int ServiceAudioTick_FE8BE(_DWORD);
// 129FE4: using guessed type int64_t j___clock(_DWORD, _DWORD, _DWORD);
// 180EB4: using guessed type int16_t word_180EB4;
// 180EB8: using guessed type int16_t word_180EB8;
// 199BEF: using guessed type char byte_199BEF;


//----- (000249F9) --------------------------------------------------------
char sub_249F9(char *a1, int a2, char *a3, int a4)
{
  int16_t v5; // di
  int16_t v6; // di
  _DWORD *v7; // eax
  unsigned int v8; // kr04_4
  int16_t v9; // cx
  char result; // al
  char v11[100]; // [esp+0h] [ebp-70h] BYREF
  char *v12; // [esp+64h] [ebp-Ch]
  int v13; // [esp+68h] [ebp-8h]
  int v14; // [esp+6Ch] [ebp-4h]

  v14 = a2;
  v12 = a3;
  v13 = a4;
  v5 = (uint8_t)byte_199CAE;
  if ( (uint8_t)byte_199CAE > 5u )
    v5 = 0;
  v6 = 6 * v14 + v5;
  ((void (*)(void))ServiceAudioTick_FE8BE)();
  v7 = sub_126C91((int)a1, v6, (int)v11, 0, 1u, 100);
  ServiceAudioTick_FE8BE(v7, 0, 0, 0);
  v8 = strlen(v11) + 1;
  v9 = v8 - 1;
  if ( (int16_t)(v8 - 1) >= (int16_t)v13 - 1 || v9 >= 99 )
  {
    sprintf(v11, "Message #%d in %s too long (%d).", (int16_t)v14, a1, v9);
    sub_126487(v11, (int16_t)(v8 - 1));
  }
  strcpy(v12, v11);
  return result;
}
// FE8BE: using guessed type int ServiceAudioTick_FE8BE(_DWORD);
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 199CAE: using guessed type char byte_199CAE;


//----- (00024ACA) --------------------------------------------------------
/* vlna 139: SKUTECNA signatura podle asm (Orion2.exe.lst, cseg01:00024ACA).
   Prolog `enter 0F4h,0` + `push eax/edx/ebx/ecx` + `sub ebp, 82h` uklada
   ctyri registrove argumenty do ramce; IDA z nich udelala neinicializovane
   lokalky v50..v53 (sama to hlasi: "variable 'v51'/'v52' is possibly
   undefined"). `v53` je pritom BUFFER, ktery se cte i prepisuje - proto se
   v portu nedosazovalo do textu nic (na INFO chybelo cislo v "Net Income").
   Skutecne zasobnikove argumenty zacinaji na [ebp_orig+10h] = [ebp'+92h];
   IDA je pojmenovala s posunem 0x10 (arg_82 = offset 92h = argument 1).
   Prirazeni s1..s5 k puvodnim a33..a37 je overene misto po miste proti asm. */
char sub_24ACA(
        char *bufEax,      /* eax -> [ebp-0F8h] (IDA var_76) - buffer se sablonou */
        int16_t regEdx,    /* edx -> [ebp-0FCh] (var_7A) */
        int16_t regEbx,    /* ebx -> [ebp-100h] (var_7E) */
        int16_t regEcx,    /* ecx -> [ebp-104h] (var_82) */
        int16_t s1,        /* zasobnikovy argument 1 (arg_82) - cislo pro itoa */
        int16_t s2,        /* 2 (arg_86) */
        int16_t s3,        /* 3 (arg_8A) */
        int16_t s4,        /* 4 (arg_8E) */
        int16_t s5)        /* 5 (arg_92) - velikost ciloveho bufferu */
{
  int16_t v37; // di
  char *v38; // esi
  int v39; // eax
  int16_t v40; // dx
  int16_t v41; // ax
  char *v42; // eax
  char *v43; // edi
  unsigned int v44; // kr08_4
  int v45; // edx
  char *v46; // eax
  int v47; // esi
  int64_t v48; // rax
  char result = 0; // al
  /* vlna 139: ctyri registrove argumenty, ktere ulozil prolog */
  int16_t v50 = regEcx;   /* [ebp-104h] */
  int16_t v51 = regEbx;   /* [ebp-100h] */
  int16_t v52 = regEdx;   /* [ebp-0FCh] */
  char *v53 = bufEax;     /* [ebp-0F8h] - buffer se sablonou */
  char v54[114]; // [esp+82h] [ebp-72h] BYREF
  /* vlna 139: `arg_46` (56h) a `arg_6E` (7Eh) jsou po `sub ebp,82h` UVNITR
     ramce, tedy lokalky - v dekompilatu vystupovaly jako `scratch`
     a `*(_DWORD *)((char *)&a29 + 2)`. Buffer saha do 7Dh, tedy 40 B. */
  char scratch[40];       /* arg_46: sem itoa/sprintf/strcpy sklada vysledek */
  int16_t i;              /* arg_6E: citac smycky (asm `cmp word ptr ..., 0C8h`) */
  unsigned int a1 = 0;    /* ecx pro itoa; asm ho nenastavuje, itoa ho ignoruje */

  v37 = 0;
  for ( i = 0; i < 200; ++i )
  {
    v46 = &v53[i];
    if ( !*v46 )
      break;
    switch ( *v46 )
    {
      case -128:
        v54[v37] = 0;
        v38 = (char *)((uint8_t*)dword_197F98 + 3753 * v52 + 1);
        goto LABEL_12;
      case -127:
        v54[v37] = 0;
        v38 = (char *)(113 * v51 + dword_19306C);
        goto LABEL_12;
      case -126:
        v38 = scratch;
        v54[v37] = 0;
        itoa(s1, scratch, 10, a1);
        goto LABEL_12;
      case -125:
        v40 = v52;
        v54[v37] = 0;
        v41 = v50;
        goto LABEL_9;
      case -124:
        v54[v37] = 0;
        v38 = (char *)(3753 * s2 + (uint8_t*)dword_197F98 + 1);
        goto LABEL_12;
      case -123:
        v40 = s2;
        v54[v37] = 0;
        v41 = s3;
LABEL_9:
        v42 = sub_10F7A1(v41, v40);
        goto LABEL_10;
      case -122:
        v54[v37] = 0;
        v39 = v52;
        goto LABEL_5;
      case -121:
        v54[v37] = 0;
        v39 = s2;
LABEL_5:
        v38 = (char *)((uint8_t*)dword_197F98 + 3753 * v39 + 21);
        goto LABEL_12;
      case -120:
        v54[v37] = 0;
        if ( byte_199CAE )
          sprintf(scratch, "%d,%d", dword_192FD8 / 10, dword_192FD8 % 10);
        else
          sprintf(scratch, "%d.%d", dword_192FD8 / 10, dword_192FD8 % 10);
        goto LABEL_11;
      case -119:
        v54[v37] = 0;
        v42 = sub_10F772(s4);
        goto LABEL_10;
      case -118:
        v54[v37] = 0;
        v42 = (char *)sub_77B28(v51);
LABEL_10:
        strcpy(scratch, v42);
LABEL_11:
        v38 = scratch;
LABEL_12:
        v43 = (char *)v54 - 1;   /* vlna 124: cil je sousedni buffer v54, ne &v53 */
        do
          ++v43;
        while ( *v43 );
        strcpy(v43, v38);
        v44 = strlen(v54) + 1;
        a1 = v44 - 1;
        v37 = v44 - 1;
        break;
      default:
        v45 = v37++;
        v54[v45] = v53[i];
        break;
    }
  }
  v47 = s5;
  v54[v37] = 0;
  if ( strlen(v54) >= v47 - 1 )
  {
    v48 = sprintf(v54, "Decode message too long (%d).\n%s", v47, v53);
    sub_126487(v54, SHIDWORD(v48));
  }
  strcpy(v53, v54);
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 192FD8: using guessed type int dword_192FD8;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199CAE: using guessed type char byte_199CAE;


//----- (00024D30) --------------------------------------------------------
int sub_24D30(char *a1, int a2, int a3)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24D30) */
  return sub_24ACA(a1, a2, -1, -1, -1, -1, -1, -1, a3);
}



//----- (00024D4C) --------------------------------------------------------
int sub_24D4C(char *a1, int a2, int a3, int a4)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24D4C) */
  return sub_24ACA(a1, a2, -1, -1, a3, -1, -1, -1, a4);
}



//----- (00024D6A) --------------------------------------------------------
int sub_24D6A(char *a1, int a2, int a3, int a4)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24D6A) */
  return sub_24ACA(a1, a2, a3, -1, -1, -1, -1, -1, a4);
}



//----- (00024D83) --------------------------------------------------------
int sub_24D83(char *a1, int a2, int a3, int a4)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24D83) */
  return sub_24ACA(a1, a2, -1, a3, -1, -1, -1, -1, a4);
}



//----- (00024D9C) --------------------------------------------------------
int sub_24D9C(char *a1, int a2, int a3, int a4, int a5)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24D9C) */
  return sub_24ACA(a1, a2, -1, -1, -1, a3, a4, -1, a5);
}



//----- (00024DC5) --------------------------------------------------------
int sub_24DC5(char *a1, int a2, int a3, int a4, int a5, int a6)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24DC5) */
  return sub_24ACA(a1, a2, -1, a4, -1, a3, a5, -1, a6);
}



//----- (00024DF0) --------------------------------------------------------
int sub_24DF0(char *a1, int a2, int a3, int a4)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24DF0) */
  return sub_24ACA(a1, a2, -1, -1, -1, a3, -1, -1, a4);
}



//----- (00024E08) --------------------------------------------------------
/* vlna 139: thunk do sub_24ACA - dosadi CISLO do sablony textu.
   asm (cseg01:00024E08):
       push ecx / movsx ebx,bx / push ebx    ; zasobnikovy argument 5 = velikost
       push -1 / push -1 / push -1           ; argumenty 4, 3, 2
       movsx edx,dx / mov ecx,-1 / push edx  ; argument 1 = cislo
     loc_24E1C: mov ebx, ecx                 ; ebx = -1
     loc_24E1E: mov edx, ecx                 ; edx = -1
     loc_24E20: call sub_24ACA / pop ecx / retn
   Posledni `push` lezi nejnize, je to tedy argument 1; sedi to i vyznamove -
   argument 1 jde do `itoa` a argument 5 do kontroly delky bufferu.
   Registrove argumenty: eax = buffer (nemeni se), edx = ebx = ecx = -1. */
int sub_24E08(char *a1, int a2, int a3)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24E08) */
  return sub_24ACA(a1, -1, -1, -1, a2, -1, -1, -1, a3);
}



//----- (00024E27) --------------------------------------------------------
int sub_24E27(char *a1, int a2, int a3)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24E27) */
  return sub_24ACA(a1, -1, a2, -1, -1, -1, -1, -1, a3);
}



//----- (00024E3E) --------------------------------------------------------
int sub_24E3E(char *a1, int a2, int a3)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24E3E) */
  return sub_24ACA(a1, -1, -1, -1, -1, -1, -1, a2, a3);
}



//----- (00024E54) --------------------------------------------------------
int sub_24E54(char *a1, int a2)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24E54) */
  return sub_24ACA(a1, -1, -1, -1, -1, -1, -1, -1, a2);
}



//----- (00024E73) --------------------------------------------------------
int sub_24E73(char *a1, int a2, int a3, int a4, int a5)
{
  /* wave 182: thunk into sub_24ACA (asm 0x24E73) */
  return sub_24ACA(a1, a2, -1, a3, -1, a4, -1, -1, a5);
}



//----- (00024E96) --------------------------------------------------------
int16_t sub_24E96(int a1)
{
  sub_12F578(dword_19F7C4, a1);
  sub_12E332(0);
  sub_12E1E0(0, 0, (int16_t *)dword_19F7C4, 0);
  return sub_123E6C((int)unk_17CF00, 1);
}
// 19F7C4: using guessed type int dword_19F7C4;


//----- (00024ED3) --------------------------------------------------------
void sub_24ED3(int16_t *a1)
{
  int16_t v1; // si
  int v2; // eax
  _DWORD *v3; // eax
  int v4; // eax
  int16_t v5; // cx
  void *v6; // eax
  int v7; // ebx
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int16_t v12; // cx
  void *v13; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // eax
  int v17 = 0; // eax

  sub_119281();
  v1 = 0;
  sub_123E6C((int)unk_180EBC, 1);
  word_19ACF4 = 0;
  sub_11C2F0();
  sub_124C08();
  sub_124D41();
  sub_128C32(0, 0, 639, 479, 0);
  sub_1112EC(dword_192EF4, 0);
  v2 = sub_111499(dword_192EF4);
  v3 = (_DWORD*)sub_110D3C(dword_192EF4, v2 - 100);
  sub_12D7B7((int)v3);
  if ( sub_25259() )
  {
    v7 = 0;
    v8 = 0;
    sub_14DF7((int)aSimtexLbx, 0, 0);
    sub_113A4E();
    word_180EB4 = -1;
  }
  else
  {
    sub_12C607((int)aLogoLbx, 0, 639, 479);
    sub_124D41();
    sub_132C80(100);
    sub_123E6C((int)unk_180EBC, 1);
    sub_131922(0, 255);
    v4 = sub_124ECB();
    v5 = sub_81547(v4, 255);
    sub_12C7CC();
    v6 = sub_124DEC();
    ServiceAudioTick_FE8BE((int)v6, 1, 639, a1);
    sub_124ECB();
    word_19ACF4 = 0;
    v1 = sub_251EF(a1);
    v7 = 15;
    sub_123E6C((int)unk_180EBC, 1);
    v8 = 0;
    PortDebug_Checkpoint("24ED3.loop1.enter", v5);
    while ( !(_WORD)v8 && !v1 )
    {
      static int loop1_iters = 0;
      if ((++loop1_iters % 200) == 0)
        PortDebug_Checkpoint("24ED3.loop1.tick", (sub_12D70B() << 16) | (uint16_t)v5);
      sub_12C2A0();
      v9 = (uint8_t)sub_12C392();
      if ( v9 == 1 )
      {
        v8 = 1;
        sub_12C2E1();
        v1 = 1;
      }
      if ( sub_124075() )
      {
        v1 = 1;
        v8 = 1;
      }
      if ( !(_WORD)v8 )
      {
        sub_124D41();
        if ( sub_12D70B() == v5 )
        {
          if ( (int16_t)--v7 < 1 )
            v8 = 1;
        }
        else
        {
          sub_12C7CC();
        }
        v10 = sub_124ECB();
        ServiceAudioTick_FE8BE(v10, v8, v7, a1);
        sub_12C2C6(1);
      }
    }
  }
  PortDebug_Checkpoint("24ED3.loop1.exit", (v1 << 16) | (uint16_t)v8);
  if ( !v1 )
  {
    sub_2518F(v8, v7, a1);
    sub_124D41();
    sub_128C32(0, 0, 639, 479, 0);
    v11 = sub_12C607((int)aLogoLbx, 1, 639, 479);
    v12 = sub_81547(v11, 1);
    sub_12C7CC();
    v13 = sub_124DEC();
    ServiceAudioTick_FE8BE((int)v13, 1, 639, a1);
    sub_124ECB();
    sub_C5C44();
    v14 = 5;
    sub_123E6C((int)unk_180EBC, 1);
    v8 = 0;
    PortDebug_Checkpoint("24ED3.loop2.enter", v12);
    while ( !(_WORD)v8 )
    {
      static int loop2_iters = 0;
      if ((++loop2_iters % 200) == 0)
        PortDebug_Checkpoint("24ED3.loop2.tick", (sub_12D70B() << 16) | (uint16_t)v12);
      sub_12C2A0();
      v15 = (uint8_t)sub_12C392();
      if ( v15 == 1 )
      {
        v8 = 1;
        sub_12C2E1();
        v1 = 1;
      }
      if ( sub_124075() )
      {
        v8 = 1;
        v1 = 1;
      }
      if ( !(_WORD)v8 )
      {
        sub_124D41();
        if ( sub_12D70B() == v12 )
        {
          if ( (int16_t)--v14 < 1 )
            v8 = 1;
        }
        else
        {
          sub_12CD2D();
        }
        v16 = sub_124ECB();
        ServiceAudioTick_FE8BE(v16, v8, v14, a1);
        sub_12C2C6(1);
      }
    }
    PortDebug_Checkpoint("24ED3.loop2.exit", (v1 << 16) | (uint16_t)v8);
  }
  PortDebug_Checkpoint("24ED3.after_loops", 0);
  sub_1113CC(dword_192EF4, v8);
  PortDebug_Checkpoint("24ED3.after_1113CC", 0);
  sub_12D78E();
  PortDebug_Checkpoint("24ED3.after_12D78E", 0);
  sub_2518F(v8, 639, a1);
  PortDebug_Checkpoint("24ED3.after_2518F", 0);
  ServiceAudioTick_FE8BE(0, v8, 639, a1);
  PortDebug_Checkpoint("24ED3.after_FE8BE", 0);
  sub_124D41();
  PortDebug_Checkpoint("24ED3.after_124D41", 0);
  sub_128C32(0, 0, 639, 479, 0);
  PortDebug_Checkpoint("24ED3.after_128C32", 0);
  sub_124DEC();
  PortDebug_Checkpoint("24ED3.after_124DEC", v1);
  if ( !v1 )
  {
    sub_14DF7((int)aIntroLbx, 0, 1);
    PortDebug_Checkpoint("24ED3.after_14DF7", 0);
  }
}
// 180EB4: using guessed type int16_t word_180EB4;
// 192EF4: using guessed type int dword_192EF4;
// 19ACF4: using guessed type int16_t word_19ACF4;


//----- (0002518F) --------------------------------------------------------
void sub_2518F(int a1, int a2, int16_t *a3)
{
  int v3; // eax
  int v4; // eax

  sub_124B65();
  LOWORD(a1) = word_19ACF4;
  while ( (int16_t)a1 <= 100 )
  {
    v3 = sub_132C80((int16_t)a1);
    ServiceAudioTick_FE8BE(v3, a1, a2, a3);
    a1 += 10;
  }
  sub_124D7A();
  sub_128C32(0, 0, 639, 479, 0);
  sub_124E36();
  v4 = sub_131922(0, 255);
  sub_1077D(v4, 255, 639, a3);
  sub_124C08();
}
// 19ACF4: using guessed type int16_t word_19ACF4;


//----- (000251EF) --------------------------------------------------------
int sub_251EF(int16_t *a1)
{
  int v1; // ebx
  int v2; // edx
  int16_t v3; // cx
  int v4; // eax
  int v5; // eax

  sub_124B65();
  v1 = 100;
  v2 = 0;
  v3 = 0;
  while ( (v1 & 0x8000u) == 0 && !v3 )
  {
    v4 = (uint8_t)sub_12C392();
    if ( v4 == 1 )
    {
      v3 = 1;
      sub_12C2E1();
      v2 = 1;
    }
    if ( sub_124075() )
    {
      v3 = 1;
      v2 = 1;
    }
    v5 = sub_132C80((int16_t)v1);
    ServiceAudioTick_FE8BE(v5, v2, v1--, a1);
  }
  sub_124C08();
  if ( (_WORD)v2 == 1 )
    word_19ACF4 = v1;
  return v2;
}
// 19ACF4: using guessed type int16_t word_19ACF4;


//----- (00025259) --------------------------------------------------------
bool sub_25259()
{
  _BYTE v1[80]; // [esp+0h] [ebp-A0h] BYREF
  _BYTE v2[80]; // [esp+50h] [ebp-50h] BYREF

  sprintf(v1, "%ssimtex.lbx", byte_184544);
  return FindMoxSetPath_1114D7(aSimtexLbx, v2) || FindMoxSetPath_1114D7(v1, v2);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);


//----- (000252A7) --------------------------------------------------------
void sub_252A7(int a1)
{
  int16_t i; // bx
  int v2; // eax
  int16_t j; // cx
  int v4; // eax
  int v5; // eax
  int v6; // edx
  signed int v7; // edx
  int v8; // esi
  int v9; // eax
  unsigned int v10; // edi
  int v11; // eax
  unsigned int v12; // edi
  int v13; // edi
  int v14; // edx

  sub_53EDB();
  sub_25C7C();
  sub_252D5();
  sub_2552D();
  sub_25DF1();
  sub_2670A();
  for ( i = 0; i < word_199998; ++i )
  {
    v2 = 3753 * i + (uint8_t*)dword_197F98;
    if ( *(_BYTE *)(v2 + 40) != 100 && !*(_BYTE *)(v2 + 2226) && dword_192FD8 % word_199998 == i )
    {
      for ( j = 0; j < word_199998; ++j )
      {
        if ( j != i )
        {
          v4 = (uint8_t*)dword_197F98 + 3753 * j;
          if ( *(_BYTE *)(v4 + 40) != 100 && !*(_BYTE *)(v4 + 2226) )
          {
            v5 = j + (uint8_t*)dword_197F98 + 3753 * i;
            if ( *(_BYTE *)(v5 + 1412) )
            {
              v6 = *(char *)(v5 + 1559) + 50;
              if ( (int)sub_1247A0(0x64u) < v6 )
              {
                v7 = (uint8_t)byte_199CB0;
                if ( (int)sub_1247A0(4u) <= v7 )
                {
                  *(_DWORD *)(a1 - 12) = 0;
                  *(_DWORD *)(a1 - 16) = 0;
                  *(_DWORD *)(a1 - 4) = -1;
                  *(_DWORD *)(a1 - 8) = -1;
                  v8 = 1;
                  do
                  {
                    if ( *(_BYTE *)((int16_t)v8 + (uint8_t*)dword_197F98 + 3753 * i + 279) == 3 )
                    {
                      v9 = 3753 * j + (uint8_t*)dword_197F98;
                      if ( *(_BYTE *)((int16_t)v8 + v9 + 279) != 3 )
                      {
                        if ( sub_E412B(v9, (int16_t)v8) )
                        {
                          v10 = *(int *)((char *)&dword_17D916
                                       + 23 * *(int16_t *)((char *)&word_17E07F + 13 * (int16_t)v8));
                          if ( byte_17E082[13 * (int16_t)v8] == 39 )
                            v10 *= 1000;
                          if ( v10 > *(_DWORD *)(a1 - 12) )
                          {
                            *(_DWORD *)(a1 - 12) = v10;
                            *(_DWORD *)(a1 - 4) = v8;
                          }
                        }
                      }
                    }
                    if ( *(_BYTE *)((int16_t)v8 + (uint8_t*)dword_197F98 + 3753 * j + 279) == 3 )
                    {
                      v11 = 3753 * i + (uint8_t*)dword_197F98;
                      if ( *(_BYTE *)((int16_t)v8 + v11 + 279) != 3 )
                      {
                        if ( sub_E412B(v11, (int16_t)v8) )
                        {
                          v12 = *(int *)((char *)&dword_17D916
                                       + 23 * *(int16_t *)((char *)&word_17E07F + 13 * (int16_t)v8));
                          if ( byte_17E082[13 * (int16_t)v8] == 39 )
                            v12 *= 1000;
                          if ( v12 > *(_DWORD *)(a1 - 16) )
                          {
                            *(_DWORD *)(a1 - 16) = v12;
                            *(_DWORD *)(a1 - 8) = v8;
                          }
                        }
                      }
                    }
                    ++v8;
                  }
                  while ( (int16_t)v8 < 204 );
                  v13 = *(int16_t *)(a1 - 4);
                  if ( v13 != -1 )
                  {
                    v14 = *(int16_t *)(a1 - 8);
                    if ( v14 != -1 )
                    {
                      sub_E4204((uint8_t*)dword_197F98 + 3753 * i, v14, v13);
                      sub_E4204(3753 * j + (uint8_t*)dword_197F98, v13, v13);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x25526 je epilog funkce */
}
// 17D916: using guessed type int dword_17D916;
// 17E07F: using guessed type int16_t word_17E07F;
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (000252D5) --------------------------------------------------------
void sub_252D5()
{
  int16_t i; // bx
  int16_t j; // dx
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  signed int v9; // esi
  int v10; // eax
  int16_t v11; // si
  int v12; // eax
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+4h] [ebp-8h]
  int16_t v15; // [esp+8h] [ebp-4h]

  for ( i = 0; i < word_199998; ++i )
  {
    for ( j = 0; j < word_199998; ++j )
    {
      v2 = (uint8_t*)dword_197F98 + 3753 * i;
      if ( *(_BYTE *)(v2 + 40) != 100 && *(_BYTE *)(3753 * j + (uint8_t*)dword_197F98 + 40) != 100 )
      {
        v3 = v2 + 2 * j;
        if ( *(_WORD *)(v3 + 1631) )
        {
          v4 = j + v2;
          if ( *(_BYTE *)(v4 + 1615) )
          {
            if ( *(_WORD *)(v3 + 1631) != 10000 )
            {
              if ( *(char *)(v4 + 1575) >= 1 && *(char *)(v4 + 1575) <= 3
                || (v5 = (uint8_t*)dword_197F98 + 3753 * i, v6 = v5 + j, *(_BYTE *)(v6 + 1583))
                || *(_BYTE *)(v6 + 1591)
                || *(int16_t *)(v5 + 2 * j + 1599) < 0 )
              {
                v15 = 2;
              }
              else
              {
                v15 = 1;
              }
              v14 = 3753 * i;
              v7 = v14 + (uint8_t*)dword_197F98;
              v8 = v14 + (uint8_t*)dword_197F98 + 2 * j;
              if ( *(int16_t *)(v8 + 1631) <= 0 )
              {
                if ( *(_BYTE *)(v7 + 39) == 4 && *(_BYTE *)(j + v7 + 1831) == 1 )
                  v11 = -2 * *(_WORD *)(v8 + 1631) + word_180CE8;
                else
                  v11 = word_180CDC[*(uint8_t *)((uint8_t*)dword_197F98 + 3753 * i + 39)]
                      - 2 * *(_WORD *)((uint8_t*)dword_197F98 + 3753 * i + 2 * j + 1631);
                if ( (int)sub_1247A0(0x64u) < v11 || v15 == 2 )
                {
                  v12 = j + (uint8_t*)dword_197F98 + 3753 * i;
                  v13 = (uint8_t*)dword_197F98;
                  *(_BYTE *)(v12 + 1823) += v15;
                  *(_BYTE *)(v13 + 3753 * j + i + 1823) = *(_BYTE *)(v12 + 1823);
                }
                else
                {
                  *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * i + j + 1615) = 0;
                }
              }
              else
              {
                v9 = (int16_t)(2 * *(_WORD *)(v8 + 1631));
                if ( (int)sub_1247A0(0x64u) >= v9 )
                {
                  *(_BYTE *)(j + v14 + (uint8_t*)dword_197F98 + 1615) = 0;
                }
                else
                {
                  v10 = j + v14 + (uint8_t*)dword_197F98;
                  if ( (char)--*(_BYTE *)(v10 + 1823) < 0 )
                    *(_BYTE *)(v10 + 1823) = 0;
                  *(_BYTE *)(3753 * j + (uint8_t*)dword_197F98 + i + 1823) = *(_BYTE *)(j + (uint8_t*)dword_197F98 + 3753 * i + 1823);
                }
              }
            }
          }
        }
      }
    }
  }
}
// 180CDC: using guessed type int16_t word_180CDC[];
// 180CE8: using guessed type int16_t word_180CE8;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0002552D) --------------------------------------------------------
void sub_2552D()
{
  int16_t v0; // di
  int16_t i; // si
  int v2; // ebx
  _BYTE *v3; // eax
  int v4; // ebx
  int v5; // ecx
  int j; // eax
  int v7; // eax
  int16_t v8; // dx
  int16_t v9; // bx
  int16_t v10; // ax
  int v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // ebx
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  int v22; // edx
  int16_t v23; // ax
  int v24; // [esp+4h] [ebp-50h]
  int v25; // [esp+8h] [ebp-4Ch]
  int v26; // [esp+8h] [ebp-4Ch]
  int v27; // [esp+18h] [ebp-3Ch]
  int v28; // [esp+20h] [ebp-34h]
  int v29; // [esp+2Ch] [ebp-28h]
  signed int v30; // [esp+38h] [ebp-1Ch]
  int v31; // [esp+44h] [ebp-10h]
  int v32; // [esp+4Ch] [ebp-8h]
  int v33; // [esp+50h] [ebp-4h]

  v0 = 0;
LABEL_72:
  if ( v0 >= word_199998 )
  {
    sub_25BC6();
    return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x25526 je epilog funkce */
  }
  for ( i = 0; ; ++i )
  {
    if ( i >= word_199998 )
    {
      ++v0;
      goto LABEL_72;
    }
    v28 = 3753 * v0;
    if ( *(_BYTE *)((uint8_t*)dword_197F98 + v28 + 40) != 100 )
    {
      v2 = 3753 * i + (uint8_t*)dword_197F98;
      if ( *(_BYTE *)(v2 + 40) != 100
        && !*(_BYTE *)((uint8_t*)dword_197F98 + v28 + 2226)
        && !*(_BYTE *)(v2 + 2226)
        && v0 != i
        && sub_1247A0(250 - 40 * (uint8_t)byte_199CB0) == 1 )
      {
        v3 = (_BYTE *)(v28 + (uint8_t*)dword_197F98 + i);
        if ( v3[1412] == 1 )
          break;
      }
    }
LABEL_69:
    ;
  }
  if ( (char)v3[1575] >= 4 || *(int16_t *)(v28 + (uint8_t*)dword_197F98 + 2 * i + 1679) < -30 )
  {
LABEL_68:
    sub_25AD2(v0, i);
    sub_524C3(v0, i);
    sub_524C3(v0, i);
    sub_524C3(v0, i);
    goto LABEL_69;
  }
  v4 = (char)v3[1751];
  v5 = v4 + (char)v3[1559];
  if ( v3[1575] == 1 )
    v5 = v4 + (char)v3[1559] + 20;
  if ( *(_BYTE *)(i + (uint8_t*)dword_197F98 + 3753 * v0 + 1575) == 2 )
    v5 += 40;
  if ( *(_BYTE *)(3753 * v0 + (uint8_t*)dword_197F98 + i + 1583) )
    v5 += 20;
  for ( j = 0; j < word_199998; ++j )
  {
    if ( j != v0 && j != i )
    {
      if ( *(char *)((uint8_t*)dword_197F98 + 3753 * v0 + j + 1575) >= 4 )
        v5 += 10;
      if ( *(char *)((uint8_t*)dword_197F98 + 3753 * i + j + 1575) >= 4 )
        v5 += 20;
      if ( *(char *)((uint8_t*)dword_197F98 + 3753 * i + j + 1823) > 0 )
        v5 += 5;
    }
  }
  v33 = 0;
  v7 = 0;
  v32 = 0;
  v31 = 0;
  while ( v7 < word_199998 )
  {
    if ( v7 != v0 && v7 != i )
    {
      if ( *(char *)((uint8_t*)dword_197F98 + 3753 * i + v7 + 1575) >= 4 )
      {
        if ( *(_BYTE *)(v31 + (uint8_t*)dword_197F98 + 40) == 100 )
          ++v33;
        else
          ++v32;
      }
      if ( *(char *)((uint8_t*)dword_197F98 + 3753 * v0 + v7 + 1575) >= 4 )
      {
        if ( *(_BYTE *)(v31 + (uint8_t*)dword_197F98 + 40) == 100 )
          ++v33;
        else
          ++v32;
      }
    }
    v31 += 3753;
    ++v7;
  }
  v24 = 3753 * v0;
  v8 = i;
  v25 = *(int16_t *)((uint8_t*)dword_197F98 + v24 + 2 * i + 1679);
  v30 = word_180CCC[*(uint8_t *)(v24 + (uint8_t*)dword_197F98 + 39)]
      + word_180CCC[*(uint8_t *)((uint8_t*)dword_197F98 + 3753 * i + 39)]
      + 50 * v33
      + v5
      + sub_1247A0(0x64u)
      + v25;
  if ( v30 < 200 || *(_BYTE *)(i + v24 + (uint8_t*)dword_197F98 + 1575) != 1 || v32 )
  {
    if ( v30 < 100 )
      goto LABEL_51;
    v8 = i;
    v11 = i + 3753 * v0 + (uint8_t*)dword_197F98;
    if ( *(_BYTE *)(v11 + 1575) == 1 || *(_BYTE *)(v11 + 1575) == 2 )
      goto LABEL_51;
    v9 = 1;
    v10 = v0;
  }
  else
  {
    v9 = 2;
    v10 = v0;
  }
  sub_5232E(v10, v8, v9);
LABEL_51:
  v27 = 3753 * v0;
  v12 = *(int16_t *)(v27 + (uint8_t*)dword_197F98 + 2 * i + 1695);
  v26 = v12 + v5 + sub_1247A0(0x64u);
  v13 = (uint8_t*)dword_197F98 + 3753 * i;
  v29 = word_180CCC[*(uint8_t *)(v13 + 39)] + v26;
  if ( v29 <= 110 || (v14 = i + v27 + (uint8_t*)dword_197F98, *(_BYTE *)(v14 + 1591)) )
  {
    if ( v29 > 80 )
    {
      v15 = (uint8_t*)dword_197F98;
      v16 = i + (uint8_t*)dword_197F98 + 3753 * v0;
      if ( !*(_BYTE *)(v16 + 1583) )
      {
        *(_BYTE *)(v16 + 1583) = 1;
        *(_BYTE *)(v0 + v15 + 3753 * i + 1583) = 1;
      }
    }
  }
  else
  {
    *(_BYTE *)(v14 + 1591) = 1;
    *(_BYTE *)(v0 + v13 + 1591) = 1;
  }
  v17 = *(int16_t *)((uint8_t*)dword_197F98 + 3753 * v0 + 2 * i + 1679);
  v18 = word_180CCC[*(uint8_t *)((uint8_t*)dword_197F98 + 3753 * i + 39)] + v5 + sub_1247A0(0x64u) + v17;
  v19 = 0;
  v20 = 0;
  while ( v19 < word_199998 )
  {
    if ( *(int16_t *)(3753 * v0 + (uint8_t*)dword_197F98 + 2 * i + 1599) < 0 )
      v20 = 1;
    ++v19;
  }
  if ( (int)(word_180CCC[*(uint8_t *)((uint8_t*)dword_197F98 + 3753 * v0 + 39)] + v18) > 150 && !v20 )
  {
    v21 = sub_500CF(v0, i);   /* wave 184: the result was dropped */
    if ( v21 < 100 && *(_WORD *)(3753 * v0 + (uint8_t*)dword_197F98 + 174) < *(_WORD *)(3753 * i + (uint8_t*)dword_197F98 + 174) )
    {
      v22 = (uint8_t)byte_199CB0 + 1;
      if ( (int)sub_1247A0(0x14u) <= v22 )
      {
        sub_1247A0(4u);
        sub_52049(v0, i, 2);
        v23 = sub_1247A0(3u);
        sub_4E3B5((int16_t)(v23 + 3), v0, i, 14, 0, 0);
      }
    }
  }
  goto LABEL_68;
}
// 180CCC: using guessed type int16_t word_180CCC[6];
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (00025AD2) --------------------------------------------------------
int sub_25AD2( int a1, int a2)
{
  int v4; // edx
  int result; // eax
  _BYTE *v6; // eax
  int v7; // [esp+4h] [ebp-4h]

  v4 = 3753 * a1 + (uint8_t*)dword_197F98;
  result = a2;
  if ( *(_BYTE *)(v4 + a2 + 1575) == 2 )
  {
    for ( LOWORD(v7) = 0; ; LOWORD(v7) = v7 + 1 )
    {
      result = v7;
      if ( (int16_t)v7 >= word_199998 )
        break;
      if ( a1 != (_WORD)v7 && *(char *)((int16_t)v7 + (uint8_t*)dword_197F98 + 3753 * a2 + 1575) >= 4 )
      {
        v6 = (_BYTE *)((int16_t)v7 + (uint8_t*)dword_197F98 + 3753 * a1);
        if ( (char)v6[1575] < 4 && v6[1412] == 1 && v6[1429] == 1 )
        {
          if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * (int16_t)v7 + 40) == 100 )
            sub_4E3B5(-10000, v7, a1, 19, 0, 0);
          *(_BYTE *)(a2 + 3753 * a1 + (uint8_t*)dword_197F98 + 1927) = v7;
          sub_51078(a1, v7);
        }
      }
    }
  }
  return result;
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00025BC6) --------------------------------------------------------
void sub_25BC6()
{
  int i; // esi
  int j; // ebx
  int v2; // eax
  int v3; // edi
  int16_t v4; // [esp+8h] [ebp-8h]

  for ( i = 0; (int16_t)i < word_199998; ++i )
  {
    for ( j = i + 1; (int16_t)j < word_199998; ++j )
    {
      v4 = i + 1;
      while ( (int16_t)j < word_199998 )
      {
        v2 = (uint8_t*)dword_197F98 + 3753 * (int16_t)i;
        if ( *(_BYTE *)(v2 + 40) != 100 )
        {
          v3 = 3753 * (int16_t)j + (uint8_t*)dword_197F98;
          if ( *(_BYTE *)(v3 + 40) != 100
            && *(char *)(v4 + v3 + 1575) >= 4
            && *(_BYTE *)((int16_t)j + v2 + 1575) == 2
            && *(_BYTE *)(v4 + v2 + 1575) == 2 )
          {
            sub_5138E(i, j);
            sub_5138E(i, v4);
          }
        }
        ++j;
      }
    }
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x25526 je epilog funkce */
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00025C7C) --------------------------------------------------------
void sub_25C7C()
{
  int16_t i; // di
  int16_t j; // si
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  int v5; // edx
  int16_t v6; // ax

  if ( !((dword_192FD8 - 35000) % 2) )
  {
    for ( i = 0; i < word_199998; ++i )
    {
      for ( j = 0; j < word_199998; ++j )
      {
        if ( i != j )
        {
          v2 = 3753 * i;
          if ( *(_BYTE *)((uint8_t*)dword_197F98 + v2 + 40) != 100 )
          {
            v3 = 3753 * j + (uint8_t*)dword_197F98;
            if ( *(_BYTE *)(v3 + 40) != 100 && *(int16_t *)(v3 + 1548) > 0 )
            {
              v4 = i + v3;
              if ( *(_BYTE *)(v4 + 1575) != 2
                && *(_BYTE *)(v4 + 1575) != 3
                && *(int16_t *)((uint8_t*)dword_197F98 + v2 + 1548) > 3 * ((uint8_t)byte_199CB2 + 1)
                && sub_1247A0(4u) == 1 )
              {
                v5 = (3 * ((uint8_t)byte_199CB2 + 1) - *(int16_t *)(v2 + (uint8_t*)dword_197F98 + 1548))
                   / ((uint8_t)byte_199CB2 + 6 - (uint8_t)byte_199CB0);
                v6 = 4 * ((int)(v5 * sub_1247A0(4u)) / 3);
                if ( *(_BYTE *)((uint8_t*)dword_197F98 + v2 + 40) != 100 )
                  v6 /= 2;
                sub_4E3B5(v6, i, j, 8, 0, 0);
              }
            }
          }
        }
      }
    }
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x25526 je epilog funkce */
}
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;
// 199CB2: using guessed type char byte_199CB2;


//----- (00025DF1) --------------------------------------------------------
void sub_25DF1()
{
  int16_t i; // si
  int v1; // edx
  int16_t j; // ax
  int v3; // ebx
  int v4; // edx
  int16_t k; // cx
  int v6; // eax
  int v7; // eax
  int16_t m; // di
  int v9; // eax
  _BYTE *v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // edx
  int16_t n; // cx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  signed int v18; // edx
  int16_t ii; // cx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int16_t jj; // cx
  int v24; // eax
  int v25; // edi
  _BYTE *v26; // eax
  int16_t kk; // cx
  int v28; // eax
  int16_t mm; // bx
  int v30; // eax
  int16_t nn; // cx
  int v32; // eax
  int v33; // ebx
  int v34; // edx
  int16_t v35; // dx
  int16_t v36; // bx
  int16_t i1; // di
  int v38; // eax
  int v39; // eax
  int16_t v40; // ax
  int v41; // eax
  int16_t i2; // ax
  int v43; // ebx
  int16_t i3; // cx
  int v45; // ebx
  int16_t i4; // di
  int v47; // edx
  int16_t v48; // di
  int16_t i5; // ax
  int v50; // ebx
  int16_t v51; // ax
  int16_t v52; // di
  int v53; // eax
  _WORD v54[16]; // [esp+0h] [ebp-58h]
  int v55; // [esp+20h] [ebp-38h]
  int v56; // [esp+24h] [ebp-34h]
  int v57; // [esp+28h] [ebp-30h]
  int v58; // [esp+2Ch] [ebp-2Ch]
  int v59; // [esp+30h] [ebp-28h]
  int v60; // [esp+34h] [ebp-24h]
  int v61; // [esp+38h] [ebp-20h]
  int v62; // [esp+3Ch] [ebp-1Ch]
  int v63; // [esp+40h] [ebp-18h]
  int v64; // [esp+44h] [ebp-14h]
  int v65; // [esp+48h] [ebp-10h]
  int v66; // [esp+4Ch] [ebp-Ch]
  int v67; // [esp+50h] [ebp-8h]
  int v68; // [esp+54h] [ebp-4h]

  for ( i = 0; i < word_199998; ++i )
  {
    v1 = 3753 * i;
    if ( *(_BYTE *)(v1 + (uint8_t*)dword_197F98 + 40) != 100
      && !*(_BYTE *)(v1 + (uint8_t*)dword_197F98 + 36)
      && (!sub_233FA() || sub_233FA() && *(_BYTE *)(v1 + (uint8_t*)dword_197F98 + 2236) == 1) )
    {
      for ( j = 0; j < word_199998; ++j )
      {
        v3 = j + 3753 * i + (uint8_t*)dword_197F98;
        if ( *(char *)(v3 + 1575) < 4 || *(_BYTE *)(v3 + 1412) != 1 || i == j )
          v54[j] = 0;
        else
          v54[j] = 3;
        v4 = j;
        v54[v4 + 8] = 0;
      }
      if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * i + 39) == 3 )
      {
        for ( k = 0; k < word_199998; ++k )
        {
          v59 = (uint8_t*)dword_197F98;
          v6 = k + (uint8_t*)dword_197F98 + 3753 * i;
          if ( *(_BYTE *)(v6 + 1429) == 1 && *(char *)(v6 + 1839) < 1 )
          {
            v60 = 3753 * k;
            if ( !*(_BYTE *)(v60 + v59 + 36) && !v54[k] && i != k )
            {
              v7 = sub_500CF(i, k);   /* wave 184: the result was dropped */
              if ( v7 >= 100
                && *(_BYTE *)(v60 + (uint8_t*)dword_197F98 + 40) != 100
                && sub_1247A0(30 * ((uint8_t)byte_199CB0 * (uint8_t)byte_199CB0 + 1)) == 1 )
              {
                v54[k] = 1;
                v54[k + 8] = 20;
              }
            }
          }
        }
      }
      for ( m = 0; m < word_199998; ++m )
      {
        v9 = (uint8_t*)dword_197F98 + 3753 * m;
        if ( *(_BYTE *)(v9 + 40) != 100 && !*(_BYTE *)(v9 + 36) && i != m )
        {
          v61 = 3753 * i;
          v10 = (_BYTE *)(v61 + (uint8_t*)dword_197F98 + m);
          if ( v10[1412] == 1 && v10[1429] == 1 && (char)v10[1839] < 1 )
          {
            v11 = sub_500CF(i, m);   /* wave 184: the result was dropped */
            if ( v11 >= 100 && !v54[m] )
            {
              v66 = word_199998;
              if ( dword_192FD8 % word_199998 == m )
              {
                v12 = -*(char *)(m + v61 + (uint8_t*)dword_197F98 + 1559);
                v66 = 2 * (uint8_t)byte_199CB0 + 1;
                v13 = (v12 - 5) / v66;
                if ( (int)sub_1247A0(0x64u) <= v13 )
                {
                  v54[m] = 1;
                  v54[m + 8] = 68;
                }
              }
            }
          }
        }
      }
      if ( *(_BYTE *)(3753 * i + (uint8_t*)dword_197F98 + 1550) == 1 )
      {
        for ( n = 0; n < word_199998; ++n )
        {
          v15 = (uint8_t*)dword_197F98 + 3753 * n;
          if ( *(_BYTE *)(v15 + 40) != 100 && !*(_BYTE *)(v15 + 36) && i != n )
          {
            v62 = 3753 * i;
            v16 = n + v62 + (uint8_t*)dword_197F98;
            if ( *(_BYTE *)(v16 + 1412) == 1 && *(_BYTE *)(v16 + 1429) == 1 )
            {
              v17 = sub_500CF(i, n);   /* wave 184: the result was dropped */
              if ( v17 >= 100 && *(char *)(n + v62 + (uint8_t*)dword_197F98 + 1839) < 1 && !v54[n] )
              {
                v54[n] = 1;
                v54[n + 8] = 113;
              }
            }
          }
        }
      }
      v18 = *(int16_t *)((uint8_t*)dword_197F98 + 3753 * i + 2028);
      if ( (int)sub_1247A0(0x64u) < v18 )
      {
        for ( ii = 0; ii < word_199998; ++ii )
        {
          v20 = (uint8_t*)dword_197F98 + 3753 * ii;
          if ( *(_BYTE *)(v20 + 40) != 100 && !*(_BYTE *)(v20 + 36) && i != ii )
          {
            v63 = 3753 * i;
            v21 = ii + v63 + (uint8_t*)dword_197F98;
            if ( *(_BYTE *)(v21 + 1412) == 1 && *(_BYTE *)(v21 + 1429) == 1 )
            {
              v22 = sub_500CF(i, ii);   /* wave 184: the result was dropped */
              if ( v22 >= 100 && *(char *)(ii + v63 + (uint8_t*)dword_197F98 + 1839) < 1 && !v54[ii] )
              {
                v54[ii] = 1;
                v54[ii + 8] = 113;
              }
            }
          }
        }
      }
      for ( jj = 0; jj < word_199998; ++jj )
      {
        v24 = (uint8_t*)dword_197F98 + 3753 * jj;
        if ( *(_BYTE *)(v24 + 40) != 100 && !*(_BYTE *)(v24 + 36) && i != jj )
        {
          v25 = 3753 * i + (uint8_t*)dword_197F98;
          v26 = (_BYTE *)(v25 + jj);
          if ( v26[1412] == 1
            && v26[1429] == 1
            && (char)v26[1839] < 1
            && !v54[jj]
            && *(int16_t *)(v25 + 2 * jj + 1791) > 0 )
          {
            v54[jj] = 2;
            v54[jj + 8] = 22;
          }
        }
      }
      for ( kk = 0; kk < word_199998; ++kk )
      {
        v28 = 3753 * kk + (uint8_t*)dword_197F98;
        if ( *(_BYTE *)(v28 + 40) != 100 && kk != i && !*(_BYTE *)(v28 + 36) )
        {
          for ( mm = 0; mm < word_199998; ++mm )
          {
            v30 = 3753 * mm + (uint8_t*)dword_197F98;
            if ( *(_BYTE *)(v30 + 40) == 100 && mm != i && !*(_BYTE *)(v30 + 36) && *(char *)(kk + v30 + 1575) >= 4 )
              v54[kk] = 0;
          }
        }
      }
      for ( nn = 0; nn < word_199998; ++nn )
      {
        v32 = (uint8_t*)dword_197F98 + 3753 * nn;
        if ( *(_BYTE *)(v32 + 40) != 100 && !*(_BYTE *)(v32 + 36) && i != nn )
        {
          v64 = i;
          v33 = 3753 * i + (uint8_t*)dword_197F98 + nn;
          v65 = 3753 * i;
          if ( *(_BYTE *)(v33 + 1429) == 1 && !v54[nn] )
          {
            v66 = word_199998;
            v34 = dword_192FD8 % word_199998;
            if ( v34 == nn && *(char *)(v33 + 1839) < 1 )
            {
              v35 = 3 * word_180CCC[sub_53E96(v64, v34)];
              v36 = 25 * (uint8_t)byte_199CB0 + sub_1247A0(0xC8u) + 125 + v35;
              if ( *(_BYTE *)(nn + v65 + (uint8_t*)dword_197F98 + 1575) == 1 )
                v36 += 50;
              if ( *(_BYTE *)(3753 * i + (uint8_t*)dword_197F98 + nn + 1575) == 2 )
                v36 += 100;
              if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * i + nn + 1575) == 3 )
                v36 += 200;
              if ( *(_BYTE *)(3753 * i + (uint8_t*)dword_197F98 + nn + 1583) )
                v36 += 50;
              if ( *(_BYTE *)(3753 * i + (uint8_t*)dword_197F98 + nn + 1591) )
                v36 += 50;
              if ( *(_WORD *)(3753 * i + (uint8_t*)dword_197F98 + 2 * nn + 1599) == 1 )
                v36 += 50;
              if ( *(_WORD *)(3753 * i + (uint8_t*)dword_197F98 + 2 * nn + 1599) == 2 )
                v36 += 100;
              for ( i1 = 0; i1 < word_199998; ++i1 )
              {
                v55 = i1;
                v56 = 3753 * i1;
                v38 = v56 + (uint8_t*)dword_197F98;
                if ( *(_BYTE *)(v56 + (uint8_t*)dword_197F98 + 40) == 100
                  && !*(_BYTE *)(v38 + 36)
                  && i1 != nn
                  && i1 != i
                  && *(_BYTE *)(nn + v38 + 1429) == 1 )
                {
                  v67 = i;
                  v39 = sub_500CF(v55, i);   /* wave 184: the result was dropped */
                  if ( v39 > 100 )
                  {
                    v40 = sub_500CF(v55, v67);   /* wave 184: the result was dropped */
                    v36 -= v40;
                  }
                }
              }
              v41 = sub_500CF(i, nn);   /* wave 184: the result was dropped */
              if ( v41 >= v36 )
              {
                v54[nn] = 1;
                v54[nn + 8] = 23;
              }
            }
          }
        }
      }
      if ( (uint8_t)byte_199CB0 >= 3u )
      {
        for ( i2 = 0; i2 < word_199998; ++i2 )
        {
          v43 = 3753 * i2 + (uint8_t*)dword_197F98;
          if ( *(_BYTE *)(v43 + 40) != 100 && i2 != i && !*(_BYTE *)(v43 + 36) )
          {
            for ( i3 = 0; i3 < word_199998; ++i3 )
            {
              v45 = 3753 * i3 + (uint8_t*)dword_197F98;
              if ( *(_BYTE *)(v45 + 40) != 100
                && i3 != i
                && i3 != i2
                && !*(_BYTE *)(v45 + 36)
                && *(char *)(i2 + v45 + 1575) >= 4 )
              {
                v54[i2] = 0;
              }
            }
          }
        }
      }
      for ( i4 = 0; i4 < word_199998; ++i4 )
      {
        if ( v54[i4] == 2 )
        {
          v57 = i;
          if ( *(char *)(i4 + (uint8_t*)dword_197F98 + 3753 * i + 1839) < 1 && i4 != i )
          {
            if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * i4 + 40) == 100 )
              sub_4E3B5(-10000, i4, v57, v54[i4 + 8], 0, 0);
            sub_51078(i, i4);
          }
        }
      }
      v47 = 0;
      v48 = 0;
      for ( i5 = 0; i5 < word_199998; ++i5 )
      {
        v58 = 3753 * i;
        v50 = i5 + v58 + (uint8_t*)dword_197F98;
        if ( *(char *)(v50 + 1839) < 1 && i != i5 )
        {
          if ( *(char *)(v50 + 1575) >= 4 )
            ++v47;
          v66 = 3753 * i;
          if ( *(int16_t *)(v66 + (uint8_t*)dword_197F98 + 1991) != -1 )
            ++v47;
          if ( v54[i5] == 1 )
            ++v48;
        }
      }
      if ( !(_WORD)v47 && v48 > 0 )
      {
        v51 = sub_1247A0(v48);
        v68 = v47;
        v52 = v51;
        while ( (int16_t)v68 < word_199998 )
        {
          if ( v54[(int16_t)v68] == 1 && i != (_WORD)v68 && !--v52 )
          {
            if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * (int16_t)v68 + 40) == 100 )
              sub_4E3B5(-10000, v68, i, v54[(int16_t)v68 + 8], 0, 0);
            sub_51078(i, v68);
            LOWORD(v53) = word_199998;
            v68 = v53;
          }
          ++v68;
        }
      }
    }
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x25526 je epilog funkce */
}
// 180CCC: using guessed type int16_t word_180CCC[6];
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (0002670A) --------------------------------------------------------
void sub_2670A()
{
  int16_t i; // bx
  int v1; // ecx
  int16_t j; // si
  int v3; // ecx
  int v4; // ecx
  int16_t v5; // di
  int16_t k; // ax
  int v7; // ecx
  int16_t v8; // ax
  int16_t v9; // di

  for ( i = 0; i < word_199998; ++i )
  {
    v1 = 3753 * i + (uint8_t*)dword_197F98;
    if ( *(_BYTE *)(v1 + 40) != 100 && !*(_BYTE *)(v1 + 36) )
    {
      for ( j = 0; j < word_199998; ++j )
      {
        if ( i != j )
        {
          v3 = (uint8_t*)dword_197F98 + 3753 * j;
          if ( *(_BYTE *)(v3 + 40) != 100 && !*(_BYTE *)(v3 + 36) )
          {
            v4 = j + (uint8_t*)dword_197F98 + 3753 * i;
            if ( (*(_BYTE *)(v4 + 1575) == 4 || *(_BYTE *)(v4 + 1575) == 5)
              && *(_BYTE *)(j + (uint8_t*)dword_197F98 + 3753 * i + 1412) == 1 )
            {
              v5 = 0;
              for ( k = 0; k < word_199998; ++k )
              {
                v7 = (uint8_t*)dword_197F98 + 3753 * k;
                if ( *(_BYTE *)(v7 + 40) == 100
                  && !*(_BYTE *)(v7 + 36)
                  && k != i
                  && k != j
                  && *(char *)(k + (uint8_t*)dword_197F98 + 3753 * i + 1575) >= 4 )
                {
                  ++v5;
                }
              }
              if ( 90 - 15 * (uint8_t)byte_199CB0 - 20 * v5 < *(uint8_t *)(j
                                                                                         + 3753 * i
                                                                                         + (uint8_t*)dword_197F98
                                                                                         + 1815) )
              {
                v8 = sub_27A3D(i);   /* wave 184: 26851 result */
                v9 = v8;
                if ( v8 == -1 )
                {
                  sub_524FB(j, i);
                }
                else
                {
                  sub_E4D06(i, v8);
                  sub_233D2(i, v9);
                }
              }
            }
          }
        }
      }
    }
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x25526 je epilog funkce */
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (0002689D) --------------------------------------------------------
void sub_2689D( int a1, int a2)
{
  int16_t i; // dx
  int v5; // eax
  _BYTE *v6; // eax
  int v7; // eax
  int16_t v8; // [esp+0h] [ebp-4h]

  if ( *(_BYTE *)(3753 * a1 + (uint8_t*)dword_197F98 + a2 + 1575) == 2 && sub_1247A0(0xAu) == 1 )
  {
    v8 = -1;
    for ( i = 0; i < word_199998; ++i )
    {
      if ( i != a1 && i != a2 )
      {
        v5 = a2 + 3753 * i + (uint8_t*)dword_197F98;
        if ( *(_BYTE *)(v5 + 1575) == 4 || *(_BYTE *)(v5 + 1575) == 5 )
        {
          v6 = (_BYTE *)(i + 3753 * a1 + (uint8_t*)dword_197F98);
          if ( v6[1412] == 1 && v6[1429] == 1 && (char)v6[1575] < 4 )
            v8 = i;
        }
      }
    }
    if ( v8 != -1 )
    {
      v7 = 3753 * a1 + (uint8_t*)dword_197F98;
      *(_BYTE *)(a2 + v7 + 1623) = 70;
      *(_BYTE *)(a2 + v7 + 1927) = v8;
      sub_51078(a1, v8);
    }
  }
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00026BBD) --------------------------------------------------------
int sub_26BBD( int a1, int a2, int a3)
{
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  int v12; // [esp+0h] [ebp-14h]
  unsigned int v13; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h]

  v13 = sub_1247A0(0x96u);
  v12 = 3753 * a1;
  v5 = *(char *)(a2 + v12 + (uint8_t*)dword_197F98 + 1751) + *(char *)(a2 + v12 + (uint8_t*)dword_197F98 + 1559);
  v6 = sub_E5E09(a1);
  v7 = v5 + v6 - 50 * (uint8_t)byte_199CB0 + 150 + 20 * *(int16_t *)(v12 + (uint8_t*)dword_197F98 + 2 * a2 + 2087);
  if ( *(_BYTE *)(v12 + (uint8_t*)dword_197F98 + 2227) )
    v7 += 50;
  if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * a1 + 479) == 3 )
    v7 += 50;
  v14 = 3753 * a2;
  if ( *(_BYTE *)(v14 + (uint8_t*)dword_197F98 + 39) == 4 && *(_BYTE *)(a1 + v14 + (uint8_t*)dword_197F98 + 1831) == 1 )
    v8 = word_180CD8;
  else
    v8 = word_180CCC[*(uint8_t *)(3753 * a2 + (uint8_t*)dword_197F98 + 39)];
  v9 = v8 + v7;
  if ( a3 == 1 )
    v10 = v9 + 150;
  else
    v10 = v13 - 1 + *(int16_t *)(3753 * a1 + (uint8_t*)dword_197F98 + 2 * a2 + 1711) + v9;
  if ( v10 < 0 )
    return 10000 / (100 - v10);
  else
    return v10 + 100;
}
// 180CCC: using guessed type int16_t word_180CCC[6];
// 180CD8: using guessed type int16_t word_180CD8;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (00026D0D) --------------------------------------------------------
int sub_26D0D(_DWORD *a1, _DWORD *a2)
{
  return *a1 - *a2;
}


//----- (00026D12) --------------------------------------------------------
int sub_26D12(_DWORD *a1, _DWORD *a2)
{
  return *a2 - *a1;
}


//----- (00026D19) --------------------------------------------------------
void sub_26D19( int a1, int a2, int16_t *a3, int a4, int a5)
{
  int16_t v6; // ax
  int v7; // ecx
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  int i; // ebx
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int j; // eax
  int v16; // edx
  int v17; // ebx
  int k; // edx
  int v21; // [esp+14h] [ebp-34h]
  int v22; // [esp+20h] [ebp-28h]
  int v23; // [esp+38h] [ebp-10h]
  int v24; // [esp+3Ch] [ebp-Ch]
  int v25; // [esp+40h] [ebp-8h]
  int v26; // [esp+40h] [ebp-8h]
  int v27; // [esp+40h] [ebp-8h]
  int v28; // [esp+40h] [ebp-8h]

  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  v6 = sub_26BBD(a1, a2, 0);
  v7 = v6;
  v8 = 0;
  if ( v6 <= 0 )
    goto LABEL_2;
  sub_FD219(a2);
  v25 = 0;
  v9 = 0;
  do
  {
    if ( *(_BYTE *)(v25 + (uint8_t*)dword_197F98 + 3753 * a1 + 279) == 3 && sub_E412B((uint8_t*)dword_197F98 + 3753 * a2, v25) == 1 )
    {
      v10 = sub_FC845(a2, v25);   /* wave 182: 0x26D9D */
      if ( v10 )
      {
        v9 += 5;
        *(_DWORD *)((char *)&unk_19ACF3 + v9) = v10;
        ++v8;
        byte_19ACF7[v9] = v25;
      }
    }
    ++v25;
  }
  while ( v25 < 204 );
  v23 = 0;
  v26 = 0;
  for ( i = 0; i < 5 * v8; *(_DWORD *)((char *)&unk_19ACF3 + i) = v12 )
  {
    v12 = v7 * *(int *)((char *)&dword_19ACF8 + i) / 100;
    if ( v12 > v23 )
      v23 = v7 * *(int *)((char *)&dword_19ACF8 + i) / 100;
    i += 5;
    ++v26;
  }
  v24 = 0;
  v27 = 0;
  v13 = 0;
  sub_FD219(a1);
  do
  {
    if ( *(_BYTE *)(v27 + (uint8_t*)dword_197F98 + 3753 * a2 + 279) == 3 && sub_E412B((uint8_t*)dword_197F98 + 3753 * a1, v27) == 1 )
    {
      v14 = sub_FC845(a1, v27);   /* wave 182: 0x26E6C */
      if ( v14 )
      {
        if ( v14 <= v7 * v23 / v7 )
        {
          v13 += 5;
          *(int *)((char *)&dword_19B117 + v13) = v14;
          ++v24;
          byte_19B11B[v13] = v27;
        }
      }
    }
    ++v27;
  }
  while ( v27 < 212 );
  if ( v8 && v24 )
  {
    qsort(&dword_19ACF8, v8, 5, sub_26D0D);   /* vlna 84: komparator z asm */
    qsort(&dword_19B11C, v24, 5, sub_26D12);   /* vlna 84: komparator z asm */
    v28 = 0;
    v22 = *(int *)((char *)&dword_19ACF8 + 5 * (v8 / 2));
    *a3 = 0;
    for ( j = 0; j < 5 * v24; j += 5 )
    {
      v16 = *(int *)((char *)&dword_19B11C + j);
      v21 = v16;
      if ( v16 > v23 )
      {
        *(_BYTE *)(a4 + *a3) = byte_19B120[j];
        *(_BYTE *)(a5 + *a3) = 0;
      }
      else
      {
        if ( v16 < v22 )
          v17 = 0;
        else
          v17 = v8 / 2;
        for ( k = 5 * v17; k < 5 * v8 && *(int *)((char *)&dword_19ACF8 + k) < v21; k += 5 )
          ++v17;
        *(_BYTE *)(a4 + *a3) = byte_19B120[j];
        if ( v17 >= v8 )
          *(_BYTE *)(a5 + *a3) = 1;
        else
          *(_BYTE *)(a5 + *a3) = byte_19ACFC[5 * v17];
      }
      ++*a3;
      ++v28;
    }
  }
  else
  {
LABEL_2:
    *a3 = 0;
  }
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 19ACF8: using guessed type int dword_19ACF8;
// 19B117: using guessed type int dword_19B117;
// 19B11C: using guessed type int dword_19B11C;


//----- (00026FBA) --------------------------------------------------------
/* wave 184: written from asm 26FBA-2708F (the C had only the rng call): the attitude of
   player a1 (eax) towards a2 (edx), 150 random points included */
int sub_26FBA(int a1, int a2)
{
  int v_rng; // esi
  int v_eax;
  uint8_t *v_rec; // ecx
  uint8_t *v_rec2;

  v_rng = sub_1247A0(150);
  v_rec = (uint8_t *)(intptr_t)(dword_197F98 + 3753 * (int16_t)a1);
  v_eax = (int8_t)v_rec[(int16_t)a2 + 1751] - 25 * (uint8_t)byte_199CB0 + v_rng;   /* 26FE4 */
  if ( v_rec[2227] )
    v_eax += 50;
  if ( v_rec[479] == 3 )
    v_eax += 50;
  v_rec2 = (uint8_t *)(intptr_t)(dword_197F98 + 3753 * (int16_t)a2);
  if ( v_rec2[39] == 4 && v_rec2[(int16_t)a1 + 1831] == 1 )   /* 2703A */
    v_eax += word_180CD8;
  else
    v_eax += word_180CCC[v_rec2[39]];
  if ( v_eax >= 0 )
    return v_eax + 100;
  return 10000 / (100 - v_eax);   /* 27080 */
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (00027094) --------------------------------------------------------
_DWORD *sub_27094( int a1, int a2,
        unsigned int a3,
        unsigned int a4,
        char *a5,
        _DWORD *a6,
        int16_t *a7, int a8)
{
  int i; // ebx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  _DWORD *result; // eax
  int v14; // ebx
  int v15; // ecx
  char v16; // dl

  *a7 = 0;
  sub_FD219(a1);
  for ( i = 0; i < 204; ++i )
  {
    if ( *(_BYTE *)(i + 3753 * a2 + (uint8_t*)dword_197F98 + 279) == 3 )
    {
      v10 = sub_FC845(a1, i);   /* wave 182: 0x270DD */
      v11 = v10;
      if ( i == 42 && *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * a1 + 2207) )
        v11 = 0;
      if ( i == 92 && *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * a1 + 2207) != 2 )
        v11 = 0;
      if ( i == 65 && *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * a1 + 2207) != 4 )
        v11 = 0;
      if ( i == 77 && *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * a1 + 2207) != 6 )
        v11 = 0;
      if ( !sub_E412B((uint8_t*)dword_197F98 + 3753 * a1, i) )
        v11 = 0;
      if ( v11 && v11 >= a3 && v11 <= a4 )
      {
        byte_19ACFC[5 * *a7] = i;
        *(int *)((char *)&dword_19ACF8 + 5 * (*a7)++) = v11;
      }
    }
  }
  if ( a8 == 1 && *a7 )
    qsort(&dword_19ACF8, *a7, 5, sub_26D12);   /* vlna 84: komparator z asm */
  result = a6;
  v14 = 0;
  v15 = 0;
  while ( v14 < *a7 )
  {
    v16 = byte_19ACFC[v15];
    v15 += 5;
    *a5 = v16;
    ++v14;
    ++a5;
    *result++ = *(_DWORD *)((char *)&unk_19ACF3 + v15);
  }
  return result;
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 19ACF8: using guessed type int dword_19ACF8;


//----- (0002720F) --------------------------------------------------------
char *sub_2720F( int a1, int a2)
{
  char *result; // eax
  int v4; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // ebx
  int v8; // eax
  unsigned int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // esi
  unsigned int v13; // ecx
  int v14; // eax
  int v15; // edi
  int v16; // edx
  _DWORD v17[212]; // [esp+0h] [ebp-3BAh] BYREF
  char v18[212]; // [esp+350h] [ebp-6Ah] BYREF
  int v19; // [esp+424h] [ebp+6Ah]
  int v20; // [esp+428h] [ebp+6Eh]
  int v21; // [esp+42Ch] [ebp+72h]
  int v22; // [esp+430h] [ebp+76h]
  int16_t v23; // [esp+434h] [ebp+7Ah] BYREF
  int v24; // [esp+438h] [ebp+7Eh]

  v24 = a2;
  result = (char *)((int16_t)a2 + (uint8_t*)dword_197F98 + 3753 * a1);
  if ( !result[1623] && result[1575] < 4 )
  {
    v21 = sub_26FBA((int16_t)a2, a1);   /* wave 184: 27255 eax = a2, edx = a1 */
    if ( v21 < 10 )   /* 2725D cmp eax, 0Ah */
      v21 = 10;
    sub_FD219(a1);
    v5 = 0;
    v6 = 0;
    v7 = 0;
    do
    {
      v19 = 3753 * (int16_t)v24;
      result = (char *)(v19 + (uint8_t*)dword_197F98);
      if ( *(_BYTE *)(v6 + v19 + (uint8_t*)dword_197F98 + 279) == 3 )
      {
        v8 = sub_FC845(a1, v6);   /* wave 182: 0x2729C add eax, eax */
        result = (char *)(2 * v8);
        if ( result )
        {
          v7 += 5;
          byte_19ACF7[v7] = v6;
          ++v5;
          *(_DWORD *)((char *)&unk_19ACF3 + v7) = result;
        }
      }
      ++v6;
    }
    while ( v6 < 204 );
    if ( v5 > 0 )
    {
      qsort(&dword_19ACF8, v5, 5, sub_26D12);   /* vlna 84: komparator z asm */
      v9 = 5 * (sub_1247A0((v5 + 1) / 2) - 1);
      v10 = (uint8_t)byte_19ACFC[v9];
      v11 = v21 * *(int *)((char *)&dword_19ACF8 + v9);
      v20 = v10;
      v12 = v11 / 100;
      v13 = v11 / 100;
      v14 = a1;
      v15 = (int16_t)v24;
      v22 = v14;
      result = (char *)sub_27094(v24, v14, 0, v13, v18, v17, &v23, 0);
      if ( v23 > 0 )
      {
        v16 = (uint8_t*)dword_197F98 + 3753 * v22;
        result = (char *)(v16 + v15);
        result[1623] = 101;
        *(_DWORD *)(v16 + 4 * v15 + 1935) = v12;
        result[1967] = v20;
      }
    }
  }
  return result;
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 19ACF8: using guessed type int dword_19ACF8;


//----- (0002736E) --------------------------------------------------------
/* wave 184: rewritten from the asm (2736E..27502) - IDA kept only the calls; the
   computation and the result (AX, tested by sub_501CA) were lost behind the
   shared epilog 25BC0 */
int sub_2736E( int a1, int a2)
{
  uint8_t *base = (uint8_t *)dword_197F98;
  uint8_t *p;
  int v, w, d;

  a1 = (int16_t)a1;   /* 2737A cwde */
  a2 = (int16_t)a2;   /* 2738C movsx esi, dx */
  p = base + 3753 * a1;
  if ( *(char *)(p + a2 + 1575) >= 4 )
    return 0;
  v = 10 - *(int16_t *)(p + 2 * a2 + 1679) / 20;
  v -= *(char *)(p + a2 + 1751) / 20;
  v += *(char *)(p + a2 + 1559) / 20;
  v -= sub_E5E09(a2) / 15;
  v += 3 * *(int16_t *)(p + 2 * a2 + 2087);
  v += 4 * (uint8_t)byte_199CB0;
  v -= word_180CCC[*(uint8_t *)(p + 39)] / 5;
  if ( *(char *)(base + 3753 * a2 + a1 + 1575) == 1 )
    v -= 4;
  if ( *(char *)(base + 3753 * a2 + a1 + 1575) == 2 )
    v -= 8;
  if ( *(char *)(base + 3753 * a2 + 479) == 3 )
    v -= 5;
  if ( v < 0 )
    v = 0;
  if ( v > 40 )
    v = 40;
  w = *(int16_t *)(p + 2 * a2 + 2071);
  d = v * v / 50 + 1;
  return (int)sub_1247A0(0x64u) > w / d ? 0 : 1;   /* 274F2 cmp eax, ebx / jg */
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (00027507) --------------------------------------------------------
int sub_27507( int a1, int a2)
{
  int v4; // edx
  int v5; // ecx
  int v6; // esi
  int v7; // ebx
  int result; // eax

  v4 = a1;
  v5 = (uint8_t*)dword_197F98;
  v6 = (uint8_t*)dword_197F98 + 3753 * a1;
  v7 = 3753 * a2;
  *(_WORD *)(v6 + 2 * a2 + 2071) = 0;
  result = v4;
  *(_WORD *)(v7 + v5 + 2 * v4 + 2071) = 0;
  return result;
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;


//----- (0002755F) --------------------------------------------------------
int16_t sub_2755F( int a1, int a2, _WORD *a3)
{
  unsigned int v4; // eax
  int v5; // esi
  unsigned int v6; // eax
  int v7; // edi

  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  LOWORD(v4) = *(_WORD *)(3753 * a1 + (uint8_t*)dword_197F98 + 2 * a2 + 2087);
  if ( (int16_t)v4 <= -4
    && (*a3 == 138
     || *a3 == 139
     || *a3 == 140
     || *a3 == 141
     || *a3 == 142
     || *a3 == 143
     || *a3 == 144
     || *a3 == 145
     || *a3 == 146
     || *a3 == 147
     || *a3 == 148
     || *a3 == 149
     || *a3 == 150
     || *a3 == 151
     || *a3 == 152
     || *a3 == 174) )
  {
    *a3 = 175;
    v5 = 3753 * a1 + (uint8_t*)dword_197F98;
    switch ( *(_BYTE *)(v5 + 39) )
    {
      case 0:
        goto LABEL_19;
      case 1:
      case 2:
        v4 = -1 - sub_1247A0(3u);
        goto LABEL_26;
      case 3:
        v6 = 4;
        goto LABEL_25;
      case 4:
        if ( *(_BYTE *)(v5 + a2 + 1831) == 1 )
        {
LABEL_19:
          v4 = sub_1247A0(4u) - 6;
        }
        else
        {
          v6 = 3;
LABEL_25:
          v4 = -sub_1247A0(v6);
        }
LABEL_26:
        v7 = (uint8_t*)dword_197F98;
        *(_WORD *)(2 * a2 + (uint8_t*)dword_197F98 + 3753 * a1 + 2087) = v4;
        *(_WORD *)(v7 + 3753 * a2 + 2 * a1 + 2087) = v4;
        break;
      case 5:
        v6 = 3;
        goto LABEL_25;
      default:
        goto LABEL_26;
    }
  }
  return v4;
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;


//----- (000276E6) --------------------------------------------------------
int sub_276E6( int a1, int a2, int a3)
{
  int v5; // edi
  int v6; // edx
  int result; // eax
  int v8; // ebx
  int v9; // ebx

  v5 = a2;
  v6 = 3753 * a1 + (uint8_t*)dword_197F98;
  result = 2 * v5;
  LOWORD(result) = *(_WORD *)(v6 + 2 * v5 + 2087);
  if ( a3 == 1 )
  {
    v8 = result + 1;
    if ( (result & 0x8000u) == 0 )
    {
LABEL_3:
      result = v8;
      goto LABEL_12;
    }
    switch ( *(_BYTE *)(v6 + 39) )
    {
      case 0:
        goto LABEL_3;
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
        result = 1;
        break;
      default:
        break;
    }
  }
  else
  {
    v8 = result - 1;
    if ( (int16_t)result <= 0 )
      goto LABEL_3;
    switch ( *(_BYTE *)(v6 + 39) )
    {
      case 0:
        goto LABEL_10;
      case 1:
      case 2:
      case 3:
        LOWORD(result) = (int16_t)result / 2;
        break;
      case 4:
        if ( *(_BYTE *)(v6 + v5 + 1831) == 1 )
LABEL_10:
          result = -1;
        break;
      case 5:
        --result;
        break;
      default:
        break;
    }
  }
LABEL_12:
  v9 = (uint8_t*)dword_197F98 + 3753 * a2;
  *(_WORD *)(2 * a2 + (uint8_t*)dword_197F98 + 3753 * a1 + 2087) = result;
  *(_WORD *)(v9 + 2 * a1 + 2087) = result;
  return result;
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;


//----- (000277CF) --------------------------------------------------------
void sub_277CF()
{
  int16_t i; // si
  int v1; // ecx
  int16_t j; // ax
  int v3; // ebx
  int16_t k; // di
  int v5; // eax
  _BYTE *v6; // ebx
  int v7; // eax

  if ( (uint8_t)byte_199CB0 >= 3u )
  {
    for ( i = 0; i < word_199998; ++i )
    {
      if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * i + 40) == 100 )
      {
        v1 = 0;
        for ( j = 0; j < word_199998; ++j )
        {
          v3 = 3753 * i + (uint8_t*)dword_197F98 + j;
          if ( *(_BYTE *)(v3 + 1412) && j != i )
          {
            if ( *(_BYTE *)(v3 + 1575) == 1 )
              v1 += 100;
            if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * i + j + 1575) == 2 )
              v1 += 200;
            if ( *(_BYTE *)(3753 * i + (uint8_t*)dword_197F98 + j + 1583) )
              v1 += 50;
            if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * i + j + 1591) )
              v1 += 50;
          }
        }
        if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * i + 479) == 3 )
          v1 = 2 * (int16_t)v1 / 3;
        if ( byte_199CB0 == 3 )
          LOWORD(v1) = (int16_t)v1 / 2;
        if ( (int16_t)v1 > 0 )
        {
          for ( k = 0; k < word_199998; ++k )
          {
            v5 = (uint8_t*)dword_197F98 + 3753 * k;
            if ( *(_BYTE *)(v5 + 40) != 100 )
            {
              v6 = (_BYTE *)(k + 3753 * i + (uint8_t*)dword_197F98);
              if ( v6[1412] )
              {
                if ( !v6[1575] && !v6[1591] && !v6[1583] && *(_BYTE *)(v5 + 39) != 5 )
                {
                  v6[1559] -= (int16_t)v1 / 100;
                  if ( (int)sub_1247A0(0x64u) <= (int16_t)v1 % 100 )
                    --*(_BYTE *)(k + 3753 * i + (uint8_t*)dword_197F98 + 1559);
                  v7 = 3753 * i + (uint8_t*)dword_197F98 + k;
                  if ( *(char *)(v7 + 1559) <= -100 )
                    *(_BYTE *)(v7 + 1559) = -100;
                  *(_BYTE *)(i + 3753 * k + (uint8_t*)dword_197F98 + 1559) = *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * i + k + 1559);
                }
              }
            }
          }
        }
      }
    }
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x25526 je epilog funkce */
}
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (00027A3D) --------------------------------------------------------
int sub_27A3D( int a1)
{
  int16_t i; // si
  int v3; // edx
  int16_t j; // ax
  int16_t k; // si
  int v6; // edx
  int v7; // ecx
  int v8; // ecx
  int v9; // esi
  int16_t m; // ax
  int v11; // esi
  int v12; // eax
  signed int v13; // ecx
  int16_t v14; // di
  int16_t v15; // si
  int16_t n; // ax
  int16_t v17 = -1; // cx - wave 184: the result (esi = ecx at 27F1D)
  int16_t ii; // si
  int16_t jj; // si
  int v20; // eax
  int16_t kk; // si
  int16_t mm; // si
  int v23; // [esp+8h] [ebp-60h]
  int v24; // [esp+10h] [ebp-58h]
  int v25; // [esp+18h] [ebp-50h]
  unsigned int v26; // [esp+20h] [ebp-48h]
  int v27; // [esp+28h] [ebp-40h]
  int v28; // [esp+30h] [ebp-38h]
  int v29; // [esp+34h] [ebp-34h]
  int v30; // [esp+40h] [ebp-28h]
  int v31; // [esp+50h] [ebp-18h]
  int16_t v32; // [esp+54h] [ebp-14h]
  int16_t v33; // [esp+58h] [ebp-10h]
  int16_t v34; // [esp+5Ch] [ebp-Ch]
  int16_t v35; // [esp+60h] [ebp-8h]

  if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * a1 + 40) != 100 && dword_192FD8 - 35000 >= 150 )
  {
    v31 = 1;
    v26 = 1;
    for ( i = 0; i < word_199998; ++i )
    {
      if ( i != a1 )
      {
        v3 = 3753 * i;
        if ( !*(_BYTE *)(v3 + (uint8_t*)dword_197F98 + 36) && *(int16_t *)(v3 + (uint8_t*)dword_197F98 + 166) > v31 )
          v31 = *(int16_t *)(v3 + (uint8_t*)dword_197F98 + 166);
      }
    }
    for ( j = 0; j < word_199998; ++j )
    {
      for ( k = 0; k < word_199998; ++k )
      {
        if ( j != a1 && k != a1 && j != k )
        {
          v6 = 3753 * j;
          if ( !*(_BYTE *)((uint8_t*)dword_197F98 + v6 + 36) && !*(_BYTE *)(3753 * k + (uint8_t*)dword_197F98 + 36) )
          {
            v7 = 4 * k + (uint8_t*)dword_197F98 + v6;
            if ( *(_DWORD *)(v7 + 1516) > v26 )
              v26 = *(_DWORD *)(v7 + 1516);
          }
        }
      }
    }
    v8 = 0;
    v9 = 0;
    for ( m = 0; m < word_199998; ++m )
    {
      if ( m != a1 )
      {
        v30 = 3753 * a1 + (uint8_t*)dword_197F98;
        if ( *(_BYTE *)(m + v30 + 1412) == 1 && !*(_BYTE *)((uint8_t*)dword_197F98 + 3753 * m + 36) )
        {
          ++v9;
          v8 += *(_DWORD *)(v30 + 4 * m + 1516);
        }
      }
    }
    if ( v9 > 0 )
      v8 /= v9;
    v11 = 100 * *(int16_t *)((uint8_t*)dword_197F98 + 3753 * a1 + 166) / v31;
    v12 = 100 * v8 / v31;
    v13 = 0;
    if ( v11 < 26 || v12 < 26 )
    {
      v13 = 5;
      if ( v11 < 26 )
        v13 = 5 * (26 - v11) / 12;
      if ( v12 < 26 )
        v13 = v13 * (26 - v12) / 12;
    }
    v14 = *(_WORD *)(3753 * a1 + (uint8_t*)dword_197F98 + 166);
    if ( v14 < 1 )
      v14 = 1;
    v15 = 0;
    for ( n = 0; n < word_199998; ++n )
    {
      if ( a1 != n )
        v15 += *(_WORD *)(2 * n + 3753 * a1 + (uint8_t*)dword_197F98 + 1791);
    }
    if ( 100 * v15 * v15 / (v14 + v15) / (v14 + v15) > v13 )
      v13 = 100 * v15 * v15 / (v14 + v15) / (v14 + v15);
    if ( v13 >= (int)sub_1247A0(0x64u) )
    {
      v17 = -1;
      v35 = 0;
      for ( ii = 0; ii < word_199998; ++ii )
      {
        v27 = 3753 * a1;
        if ( *(_BYTE *)(ii + v27 + (uint8_t*)dword_197F98 + 1412) == 1 && ii != a1 )
        {
          v24 = 3753 * ii;
          if ( !*(_BYTE *)(v24 + (uint8_t*)dword_197F98 + 36)
            && sub_E4CD2(a1, ii)
            && *(_BYTE *)(v24 + (uint8_t*)dword_197F98 + 40) != 100
            && *(char *)(v27 + (uint8_t*)dword_197F98 + ii + 1575) < 4
            && *(int16_t *)(v24 + (uint8_t*)dword_197F98 + 166) >= v35 )
          {
            v17 = ii;
            v35 = *(_WORD *)(v24 + (uint8_t*)dword_197F98 + 166);
          }
        }
      }
      if ( v17 == -1 )
      {
        v33 = 0;
        for ( jj = 0; jj < word_199998; ++jj )
        {
          if ( *(_BYTE *)(jj + (uint8_t*)dword_197F98 + 3753 * a1 + 1412) == 1 && jj != a1 )
          {
            v20 = 3753 * jj + (uint8_t*)dword_197F98;
            if ( !*(_BYTE *)(v20 + 36) && *(_BYTE *)(v20 + 40) != 100 && sub_E4CD2(a1, jj) )
            {
              v28 = 3753 * jj;
              if ( *(int16_t *)(v28 + (uint8_t*)dword_197F98 + 166) < v33 )
              {
                v17 = jj;
                v33 = *(_WORD *)(v28 + (uint8_t*)dword_197F98 + 166);
              }
            }
          }
        }
      }
      if ( v17 == -1 && (uint8_t)byte_199CB0 < 3u )
      {
        v34 = 0;
        for ( kk = 0; kk < word_199998; ++kk )
        {
          v23 = 3753 * a1;
          if ( *(_BYTE *)(kk + v23 + (uint8_t*)dword_197F98 + 1412) == 1
            && kk != a1
            && !*(_BYTE *)(3753 * kk + (uint8_t*)dword_197F98 + 36)
            && sub_E4CD2(a1, kk)
            && *(char *)((uint8_t*)dword_197F98 + v23 + kk + 1575) < 4 )
          {
            v25 = 3753 * kk;
            if ( *(int16_t *)(v25 + (uint8_t*)dword_197F98 + 166) < v34 )
            {
              v17 = kk;
              v34 = *(_WORD *)(v25 + (uint8_t*)dword_197F98 + 166);
            }
          }
        }
      }
      if ( v17 == -1 && (uint8_t)byte_199CB0 < 3u )
      {
        v32 = 0;
        for ( mm = 0; mm < word_199998; ++mm )
        {
          if ( *(_BYTE *)(mm + (uint8_t*)dword_197F98 + 3753 * a1 + 1412) == 1
            && mm != a1
            && !*(_BYTE *)(3753 * mm + (uint8_t*)dword_197F98 + 36)
            && sub_E4CD2(a1, mm) )
          {
            v29 = 3753 * mm;
            if ( *(int16_t *)(v29 + (uint8_t*)dword_197F98 + 166) > v32 )
            {
              v17 = mm;   /* wave 184: 27F0E mov ecx, esi */
              v32 = *(_WORD *)(v29 + (uint8_t*)dword_197F98 + 166);
            }
          }
        }
      }
    }
  }
  return v17;   /* wave 184: 27F1F mov eax, esi */
}
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (00027F26) --------------------------------------------------------
char sub_27F26(int a1)
{
  int v0; // ebx
  int i; // esi
  int v2; // eax
  int16_t v3 = (int16_t)a1;   /* wave 184: 27F2F push eax (ship) */
  char v4; // [ebp-4]

  v4 = 0;
  v0 = 0;
  for ( i = 0; v0 < 300; i += 26, ++v0 )
  {
    v2 = i + dword_192B14;
    if ( *(_WORD *)(i + dword_192B14 + 6) == (uint16_t)v3
      && *(int16_t *)v2 > 0
      && !*(_BYTE *)(v2 + 8)
      && (uint16_t)sub_2AED2(v3, (int16_t)v0)
      && (uint16_t)sub_3BB3D((int16_t)v0) != *(uint8_t *)(dword_192864 + 313 * v3 + 32) )   /* wave 184: 27F82 */
      v4 = 1;
  }
  return v4;   /* wave 184: 27F97 mov al, [var_4] */
}
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (00027F9F) --------------------------------------------------------
char sub_27F9F(int a1)
{
  int16_t v0; // bx
  int v1; // esi
  int v2; // ecx
  int16_t v3; // ax
  int v4; // edi
  int16_t *v5; // eax
  int16_t v6; // dx
  int16_t v7; // ax
  int16_t v8; // ax
  int16_t v9 = (int16_t)a1;   /* wave 184: 27FA8 push eax (ship) */
  int16_t v10; // [esp+18h] [ebp-18h]
  int16_t v11; // [esp+1Ch] [ebp-14h]
  int16_t v12; // [esp+20h] [ebp-10h]
  int16_t v13; // [esp+24h] [ebp-Ch]
  int16_t v14; // [esp+28h] [ebp-8h]

  v0 = 1;
  v1 = 0;
  v2 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  while ( v0 < word_1998C0 )
  {
    if ( !*(_BYTE *)(313 * v0 + dword_192864 + 36) && v0 != v9 && !sub_3E563(v0) )
    {
      v3 = sub_2885A(v9, v0);
      if ( *(_BYTE *)(313 * v0 + dword_192864 + 32) == *(_BYTE *)(313 * v9 + dword_192864 + 32) )
      {
        if ( v3 > 1 )
        {
          if ( v3 == 2 )
            ++v1;
        }
        else
        {
          v1 += 2;
        }
      }
      else if ( v3 > 1 )
      {
        if ( v3 == 2 )
          ++v2;
      }
      else
      {
        v2 += 2;
      }
    }
    ++v0;
  }
  v14 = 0;
  while ( 1 )
  {
    v4 = 26 * v14;
    v5 = (int16_t *)(v4 + dword_192B14);
    if ( *(int16_t *)(v4 + dword_192B14) > 0
      && byte_17F80F[28 * *v5] != 2
      && (int16_t)Hook150_1E25C8(v9, *(int16_t *)((char *)v5 + 9), *(int16_t *)((char *)v5 + 11)) < 3 )   /* 1.50 0280AD */
    {
      v6 = *(uint8_t *)(313 * v9 + dword_192864 + 32);
      if ( sub_3BB3D(v14) == v6 )
      {
        v7 = *(_WORD *)(v4 + dword_192B14 + 15);
        if ( byte_17F80F[28 * *(int16_t *)(v4 + dword_192B14)] == 4 )
          v11 += v7;
        else
          v13 += v7;
      }
      else
      {
        v8 = *(_WORD *)(v4 + dword_192B14 + 15);
        if ( byte_17F80F[28 * *(int16_t *)(v4 + dword_192B14)] == 4 )
          v10 += v8;
        else
          v12 += v8;
      }
    }
    if ( ++v14 >= 300 )
      break;
  }
  /* wave 184: 28138 - only cx is tested, so 16-bit sums are enough */
  if ( (int16_t)(5 * v10 + v12 - 8 * v11 - v13 + 15 * v2 - 10 * v1) < 0 )
    return 0;
  return 1;   /* wave 184: 27F97 mov al, [var_4] */
}
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00028168) --------------------------------------------------------
char sub_28168( int a1)
{
  int v2; // eax
  int v3; // esi
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int16_t i; // cx
  int v12; // edx
  int v13; // eax
  int v14; // eax
  _BOOL1 v15; // al
  int v16; // eax
  int16_t j; // cx
  int16_t *v18; // eax
  int16_t v19; // bx
  int16_t v20; // ax
  int16_t v21; // dx
  int v22; // eax
  int v23; // eax
  int16_t v24; // cx
  int16_t v25; // bx
  int16_t v26; // ax
  int16_t v27; // si
  int16_t v28; // si
  _BYTE v29[4]; // [esp+0h] [ebp-3Eh] BYREF
  int v30; // [esp+4h] [ebp-3Ah]
  int16_t v31; // [esp+38h] [ebp-6h] BYREF
  int v32; // [esp+3Ch] [ebp-2h]
  int v33; // [esp+70h] [ebp+32h]
  int v34; // [esp+74h] [ebp+36h]
  int v35; // [esp+78h] [ebp+3Ah]
  int v36; // [esp+7Ch] [ebp+3Eh]
  int v37; // [esp+80h] [ebp+42h]
  int v38; // [esp+84h] [ebp+46h]
  int v39; // [esp+88h] [ebp+4Ah]
  int v40; // [esp+8Ch] [ebp+4Eh]
  int v41; // [esp+90h] [ebp+52h]
  int v42; // [esp+94h] [ebp+56h]
  int v43; // [esp+98h] [ebp+5Ah]
  int v44; // [esp+9Ch] [ebp+5Eh]
  int v45; // [esp+A0h] [ebp+62h]
  int v46; // [esp+A4h] [ebp+66h]
  int v47; // [esp+A8h] [ebp+6Ah]
  int v48; // [esp+ACh] [ebp+6Eh]
  int v49; // [esp+B0h] [ebp+72h]
  int v50; // [esp+B4h] [ebp+76h]
  int v51; // [esp+B8h] [ebp+7Ah]
  char v52; // [esp+BCh] [ebp+7Eh]

  v52 = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v42 = 0;
  v48 = 0;
  v47 = 0;
  v44 = 0;
  v2 = 313 * a1 + dword_192864;
  v43 = 0;
  v3 = 0;
  if ( *(_BYTE *)(v2 + 32) > 8u
    || g_orion150 && sub_3E57C(a1) && *Hook150_Eseg(0x23DD80) != 1   /* 1.50 0281C3, 0281C8: sub_1E397E */
    || !a1 || !*(_BYTE *)(v2 + 49) )
    goto LABEL_74;
  if ( *(uint8_t *)(v2 + 32) == word_1998AC )
    LOWORD(v2) = word_19988E;
  else
    LOWORD(v2) = word_1998AC;
  v45 = v2;
  if ( (int16_t)v2 < word_199998 )
  {
    v4 = 313 * a1;
    v35 = (int16_t)v2;
    v5 = sub_35FDA(v2);
    v40 = v5;
    v6 = sub_35FDA(*(uint8_t *)(v4 + dword_192864 + 32));
    v7 = v6;
    v8 = sub_360AA(*(uint8_t *)(v4 + dword_192864 + 32));
    v41 = v7 + v8;
    v9 = 20 * sub_4B0D3(a1, 29) + v7 + v8;
    v10 = sub_35CAD(a1);   /* wave 184: 28266 add edx, eax (full eax) */
    v43 = v10 + v9;
    sub_EC767(v35, 5, (int16_t)v40, *(uint8_t *)(v4 + dword_192864 + 32), 5, (int16_t)(v10 + v9), &v31, (int)v29);
    v44 = v32;
    v43 = v30;
  }
  for ( i = 1; ; ++i )
  {
    if ( i >= word_1998C0 )
    {
      for ( j = 0; j < 300; ++j )
      {
        v37 = j;
        v36 = 26 * j;
        v18 = (int16_t *)(v36 + dword_192B14);
        if ( *(int16_t *)(v36 + dword_192B14) > 0 && byte_17F80F[28 * *v18] != 2 )
        {
          v19 = *(int16_t *)((char *)v18 + 11);
          v20 = *(int16_t *)((char *)v18 + 9);
          v38 = a1;
          if ( (int16_t)Hook150_1E25C8(a1, v20, v19) < 3 )   /* 1.50 028404 */
          {
            v21 = *(uint8_t *)(dword_192864 + 313 * v38 + 32);
            if ( sub_3BB3D(v37) == v21 )
            {
              v22 = v36 + dword_192B14;
              LOWORD(v22) = *(_WORD *)(v36 + dword_192B14 + 15);
              if ( byte_17F80F[28 * *(int16_t *)(v36 + dword_192B14)] == 4 )
                v47 += v22;
              else
                v42 += v22;
            }
            else
            {
              v23 = v36 + dword_192B14;
              LOWORD(v23) = *(_WORD *)(v36 + dword_192B14 + 15);
              if ( byte_17F80F[28 * *(int16_t *)(v36 + dword_192B14)] == 4 )
                v48 += v23;
              else
                v51 += v23;
            }
          }
        }
      }
      v24 = 20 * v50 + 5 * v48 + v51 - 5 * v47 - v42 - 10 * v49;
      if ( v3 > 0 && (int16_t)v45 < word_199998 )
      {
        v35 = 313 * a1;
        v25 = v44 - v43;
        v26 = *(uint8_t *)(v35 + dword_192864 + 175);
        if ( (int16_t)(v44 - v43) <= 50 )
        {
          if ( v25 < 40 )
          {
            if ( v25 < 30 )
            {
              if ( v25 < 20 )
              {
                if ( v25 < 10 )
                {
                  if ( v25 >= -50 )
                  {
                    if ( v25 > -40 )
                    {
                      if ( v25 > -30 )
                      {
                        if ( v25 > -20 )
                        {
                          if ( v25 <= -10 )
                            v26 *= 2;
                        }
                        else
                        {
                          v26 *= 3;
                        }
                      }
                      else
                      {
                        v26 *= 4;
                      }
                    }
                    else
                    {
                      v26 *= 7;
                    }
                  }
                  else
                  {
                    v26 *= 10;
                  }
                }
                else
                {
                  v3 *= 2;
                }
              }
              else
              {
                v3 *= 3;
              }
            }
            else
            {
              v3 *= 4;
            }
          }
          else
          {
            v3 *= 7;
          }
        }
        else
        {
          v3 *= 10;
        }
        if ( v3 > v26 )
        {
          v27 = v3 - v26;
          if ( *(_BYTE *)((uint8_t*)dword_197F98 + 3753 * (int16_t)v45 + 2232) )
            v28 = 10 * v27;
          else
            v28 = 5 * v27;
          v24 += v28;
        }
      }
      if ( v24 > 0 && (int)sub_1247A0(0x64u) < v24 && !*(_WORD *)(313 * a1 + dword_192864 + 59) )
        v52 = 1;
LABEL_74:
      return v52;   /* wave 184: 285B7 mov al, [var_4] */
    }
    v39 = 313 * i;
    if ( *(_BYTE *)(v39 + dword_192864 + 36) || i == a1 || sub_3E563(i) )
      continue;
    v34 = a1;
    v13 = Hook150_1E0C69(a1, i);   /* 1.50 0282E8; wave 184: 282E8 result */
    v12 = 313 * v34;
    v46 = v13;
    v14 = sub_35CAD(i);   /* wave 184: 282FE add [var_24], eax */
    v44 += v14;
    v35 = dword_192864;
    v33 = v12;
    if ( *(_BYTE *)(v39 + dword_192864 + 32) == *(_BYTE *)(v12 + dword_192864 + 32) )
    {
      if ( (int16_t)v46 > 1 )
      {
        if ( (_WORD)v46 == (g_orion150 ? (uint16_t)(2 * *(int8_t *)Hook150_Eseg(0x23DCDE)) : 2) )   /* 1.50 02832D: sub_1E0C7D */
          ++v49;
      }
      else
      {
        v49 += 2;
      }
      continue;
    }
    v15 = sub_4B0D3(i, 35);
    if ( (int16_t)v46 <= 1 )
      break;
    if ( (_WORD)v46 == (g_orion150 ? (uint16_t)(2 * *(int8_t *)Hook150_Eseg(0x23DCDE)) : 2) )   /* 1.50 028383: sub_1E0C7D */
    {
      ++v50;
      goto LABEL_20;
    }
    if ( (int16_t)v46 < (g_orion150 ? (int16_t)(7 * *(int8_t *)Hook150_Eseg(0x23DCDE)) : 7) && v15 )   /* 1.50 02838F: sub_1E0C8D */
    {
      v16 = *(uint8_t *)(v39 + dword_192864 + 175);
      goto LABEL_28;
    }
LABEL_29:
    ;
  }
  v50 += 2;
LABEL_20:
  if ( v15 || !*(_WORD *)(v33 + dword_192864 + 59) )
  {
    v16 = *(uint8_t *)(dword_192864 + 313 * i + 175);
LABEL_28:
    v3 += v16 / 2;
    goto LABEL_29;
  }
  goto LABEL_29;
}
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;
// 199998: using guessed type int16_t word_199998;


//----- (000285C6) --------------------------------------------------------
int sub_285C6(int a1)
{
  int16_t v0; // si
  int16_t i; // dx
  int v2; // edi
  int v3; // eax
  int result; // eax
  int16_t v5 = (int16_t)a1;   /* wave 184: 285CE push eax (owner) */
  int16_t v6; // [esp+4h] [ebp-4h]

  v0 = -1;
  v6 = 100;
  for ( i = 1; i < word_1998C0; ++i )
  {
    v2 = 313 * i;
    v3 = v2 + dword_192864;
    if ( !*(_BYTE *)(v2 + dword_192864 + 36)
      && !*(_BYTE *)(v3 + 176)
      && *(uint8_t *)(v3 + 32) == v5
      && sub_3E563(i)
      && *(uint8_t *)(v2 + dword_192864 + 37) < v6 )
    {
      v6 = *(uint8_t *)(v2 + dword_192864 + 37);
      v0 = i;
    }
  }
  result = v0;
  if ( v0 != -1 )
    return sub_3AFB3(v0);
  return result;
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0002864A) --------------------------------------------------------
int sub_2864A( int a1)
{
  int16_t v5; // si
  int16_t v6; // dx
  int16_t i; // bx
  uint8_t *v8; // eax
  int16_t v9; // [ebp-4] the other side

  v5 = 0;
  v6 = 0;
  v9 = (int16_t)a1 == word_1998AC ? word_19988E : word_1998AC;   /* wave 184: 28659 */
  for ( i = (int16_t)sub_3A142(v9, 0) <= 0; i < word_1998C0; ++i )
  {
    v8 = (uint8_t *)(dword_192864 + 313 * i);
    if ( !v8[36] && !v8[176] && (uint16_t)v8[32] != (uint16_t)a1 )
    {
      ++v6;
      if ( sub_3E563(i) )
        ++v5;
    }
  }
  if ( v6 - v5 < 1 )
    sub_285C6(v9);   /* wave 184: 286D6 movsx eax, [var_4] */
  return v6 - v5;   /* wave 184: 286DF mov eax, edx; sub eax, esi */
}
// 192864: using guessed type int dword_192864;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (000286E8) --------------------------------------------------------
int sub_286E8( int a1, int a2, int a3)
{
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int16_t v6; // cx
  int16_t v7; // si
  int16_t v8; // bx
  int16_t v9; // ax
  int v10; // ecx
  int v11; // edx
  int16_t v12; // cx
  int v13; // edx
  int v14; // esi
  int v15; // esi
  int v16; // ebx
  int v17; // esi
  int v20; // [esp+18h] [ebp-Ch] BYREF
  int v21; // [esp+1Ch] [ebp-8h] BYREF
  int v22; // [esp+20h] [ebp-4h]

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v3 = a1;
  sub_49ED1(a1, &v20, &v21);
  HIWORD(v4) = HIWORD(v20);
  LOWORD(v4) = (int16_t)v20 / 20;
  v20 = v4;
  HIWORD(v4) = HIWORD(v21);
  LOWORD(v4) = (int16_t)v21 / 20;
  v21 = v4;
  v5 = 313 * v3 + dword_192864;
  v6 = *(uint8_t *)(v5 + 33);
  v7 = *(uint8_t *)(v5 + 34);
  v8 = a2 / 20;
  v9 = a3 / 20;
  v22 = 0;
  if ( v6 <= a2 / 20 )
  {
    v11 = v6 + (int16_t)v20;
    if ( v11 > v8 )
      LOWORD(v11) = v8;
  }
  else
  {
    v10 = v6 - (int16_t)v20;
    LOWORD(v11) = a2 / 20;
    if ( v10 >= v8 )
      LOWORD(v11) = v10;
  }
  v12 = v11;
  if ( v7 <= v9 )
  {
    v14 = (int16_t)v21 + v7;
    LOWORD(v13) = a3 / 20;
    if ( v14 <= v9 )
      LOWORD(v13) = v14;
  }
  else
  {
    v13 = v7 - (int16_t)v21;
    if ( v13 < v9 )
      LOWORD(v13) = a3 / 20;
  }
  if ( v8 <= v12 )
  {
    v16 = v8 + (int16_t)v22;
    if ( v16 > v12 )
      LOWORD(v16) = v12;
  }
  else
  {
    v15 = v8 - (int16_t)v22;
    LOWORD(v16) = v12;
    if ( v15 >= v12 )
      LOWORD(v16) = v15;
  }
  if ( v9 <= (int16_t)v13 )
  {
    v17 = v9;
    v9 = v13;
    if ( v17 <= (int16_t)v13 )
      v9 = v17;
  }
  else if ( v9 < (int16_t)v13 )
  {
    v9 = v13;
  }
  return ((int16_t)sub_134637(v12, v13, v16, v9) + 2) / 3;
}
// 192864: using guessed type int dword_192864;


//----- (00028836) --------------------------------------------------------
int sub_28836( int a1, int a2)
{
  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  return Hook150_1E25C8(a1, *(_WORD *)(26 * a2 + dword_192B14 + 9), *(_WORD *)(26 * a2 + dword_192B14 + 11));   /* 1.50 028852 */
}
// 192B14: using guessed type int dword_192B14;


//----- (0002885A) --------------------------------------------------------
int sub_2885A( int a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // edi
  int16_t v5; // cx
  int16_t v6; // si
  int v7; // edx
  int16_t v8; // ax
  int16_t v9; // dx
  int v10; // ebx
  int v11; // ecx
  int16_t v12; // cx
  int v13; // ebx
  int v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // edx
  bool v18; // [esp+8h] [ebp-18h]
  int v19; // [esp+Ch] [ebp-14h]
  int v20; // [esp+10h] [ebp-10h]
  int16_t v21; // [esp+14h] [ebp-Ch]
  int16_t v22; // [esp+18h] [ebp-8h] BYREF
  int16_t v23; // [esp+1Ch] [ebp-4h] BYREF

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v2 = 313 * a1;
  sub_49ED1(a1, &v22, &v23);
  v19 = 0;
  v3 = v2 + dword_192864;
  v20 = 0;
  v4 = 0;
  v5 = *(uint8_t *)(v2 + dword_192864 + 33);
  v6 = *(uint8_t *)(v3 + 34);
  v18 = v22 > 10;
  if ( v22 > 20 )
  {
    v19 = 1;
    ++v5;
    ++v6;
  }
  sub_49ED1(a2, &v22, &v23);
  v7 = dword_192864 + 313 * a2;
  v8 = *(uint8_t *)(v7 + 33);
  v9 = *(uint8_t *)(v7 + 34);
  if ( v22 > 10 )
    v20 = 1;
  if ( v22 > 20 )
  {
    v4 = 1;
    ++v8;
    ++v9;
  }
  if ( v5 <= v8 )
  {
    LOWORD(v10) = v8;
    v11 = v18 + v5;
    if ( v11 <= v8 )
      LOWORD(v10) = v11;
  }
  else
  {
    v10 = v5 - v19;
    if ( v10 < v8 )
      LOWORD(v10) = v8;
  }
  v12 = v10;
  if ( v6 <= v9 )
  {
    LOWORD(v13) = v9;
    v14 = v18 + v6;
    if ( v14 <= v9 )
      LOWORD(v13) = v14;
  }
  else
  {
    v13 = v6 - v19;
    if ( v13 < v9 )
      LOWORD(v13) = v9;
  }
  if ( v8 <= v12 )
  {
    v15 = v20 + v8;
    if ( v15 > v12 )
      LOWORD(v15) = v12;
  }
  else
  {
    v15 = v8 - v4;
    if ( v15 < v12 )
      LOWORD(v15) = v12;
  }
  v21 = v15;
  if ( v9 <= (int16_t)v13 )
  {
    v16 = v20 + v9;
    if ( v16 > (int16_t)v13 )
      LOWORD(v16) = v13;
  }
  else
  {
    LOWORD(v16) = v13;
    v17 = v9 - v4;
    if ( v17 >= (int16_t)v13 )
      LOWORD(v16) = v17;
  }
  /* wave 184: 289AF - the distance in hexes, (d + 2) / 3 */
  v17 = sub_134637(v12, (int16_t)v13, v21, (int16_t)v16);
  if ( g_orion150 && *(int8_t *)Hook150_Ecode(0x1E0C0B) >= 1 )   /* 1.50 0289B4, 0289B9: sub_1E0C54 - the distance itself */
    return v17;
  return ((int16_t)v17 + 2) / 3;
}
// 192864: using guessed type int dword_192864;


//----- (000289C4) --------------------------------------------------------
//----- (001E4028) --------------------------------------------------------
/* 1.50: avg - def with the modifiers of 1.50 - avg less byte 23D0F3 % (sub_1E1295) when a3 has special 10,
   def + byte 23E2B2 when a3 has special 13, else def 0 when word_1998CA */
static int sub_1E4028(int a3, int avg, int def)
{
  if ( !g_orion150 )
    return avg - def;
  if ( (int16_t)sub_4B0D3((int16_t)a3, 10) )
    avg -= avg * *Hook150_Eseg(0x23D0F3) / 100;
  if ( (int16_t)sub_4B0D3((int16_t)a3, 13) )
    def += *Hook150_Eseg(0x23E2B2);
  else if ( word_1998CA )
    def = 0;
  return avg - def;
}

unsigned int sub_289C4( int a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int16_t v6; // di
  int16_t v7; // dx
  unsigned int v8; // esi
  int16_t v9; // ax
  int16_t v10; // ax
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  char v21; // [esp+28h] [ebp-14h]
  int16_t v22; // [esp+2Ch] [ebp-10h]
  int16_t v23; // [esp+30h] [ebp-Ch]
  int16_t v24; // [esp+38h] [ebp-4h]

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v5 = 313 * a1 + dword_192864 + 11 * a2;
  v6 = *(_WORD *)(v5 + 82);
  v7 = *(_WORD *)(v5 + 86);
  v23 = *(uint8_t *)(v5 + 84);
  v8 = 0;
  v22 = (uint8_t)byte_17F80F[28 * v6];
  if ( v6 <= 0 || !(uint16_t)sub_389E8(v6, v7, a3, a4) )
    goto LABEL_56;
  if ( a5 )
  {
    if ( a4 )
    {
      v24 = a5;
      v9 = sub_329A4(a1, *(_WORD *)(dword_192B14 + 26 * a3 + 9), *(_WORD *)(dword_192B14 + 26 * a3 + 11));
      v21 = sub_32AD1(v9);
    }
    else
    {
      v10 = sub_32A20(a1, a3);
      v21 = sub_32AD1(v10);
      v24 = a5;
    }
    v23 = 0;
    if ( sub_4584C(a1, a2) )
    {
      v11 = dword_192864 + 313 * a1 + 11 * a2;
      if ( (v21 & *(uint8_t *)(v11 + 85)) != 0
        && (v22 != 2 && *(_WORD *)(v11 + 88) || v22 == 2 && !*(_WORD *)(313 * a1 + dword_192864 + 11 * a2 + 88)) )
      {
        if ( (uint16_t)sub_39F1D(a2, a1, a3, a4, v24) )
          v23 = *(uint8_t *)(313 * a1 + dword_192864 + 11 * a2 + 91);
      }
    }
  }
  else
  {
    v24 = 1;
  }
  if ( v23 <= 0 )
    goto LABEL_56;
  if ( byte_17F80F[28 * v6] == 1 || byte_17F80F[28 * v6] == 4 || byte_17F80F[28 * v6] == 2 )
  {
    /* wave 184: 28BB1 eax = a3, edx = di, ebx = var_C, ecx = var_18, esi = 0 (28A02) */
    v12 = (int16_t)sub_28EAE(a3, v6, v23, v7, *(uint8_t *)(dword_192864 + 313 * a1 + 32), 0);
LABEL_48:
    v8 = v12;
    goto LABEL_56;
  }
  if ( !byte_17F80F[28 * v6] || byte_17F80F[28 * v6] == 3 )
  {
    v12 = sub_290DA(a1, a2, a3, v23, v24, a4);
    goto LABEL_48;
  }
  if ( byte_17F80F[28 * v6] != 5 )
    goto LABEL_56;
  if ( (uint16_t)v6 < 0x24u )
  {
    if ( (uint16_t)v6 >= 0x21u )
    {
      if ( (uint16_t)v6 <= 0x21u )
      {
        if ( !a4 )
          goto LABEL_56;
        v13 = (int16_t)sub_3E095(
                         *(_WORD *)(dword_192B14 + 26 * a3),
                         g_orion150 ? *(uint16_t *)(dword_192B14 + 26 * a3 + 2)   /* 1.50 028CD0: the word +2 */
                                    : *(uint8_t *)(313 * *(int16_t *)(dword_192B14 + 26 * a3 + 4) + dword_192864 + 32),
                         *(int16_t *)(dword_192B14 + 26 * a3 + 17),
                         HIBYTE(*(_WORD *)(dword_192B14 + 26 * a3 + 17)));
        v14 = (int16_t)((v23 * (70 - 10 * (v24 - 1)) + 50) / 100);
      }
      else
      {
        if ( (uint16_t)v6 > 0x22u )
          goto LABEL_50;
        v13 = (*(uint8_t *)(dword_192864 + 313 * a3 + 37) + 1)
            * ((word_17F819[14 * v6] + word_17F817[14 * v6])
             / 2);
        v14 = v23;
      }
LABEL_47:
      v12 = v13 * v14;
      goto LABEL_48;
    }
    if ( (uint16_t)v6 < 0xDu )
      goto LABEL_56;
    if ( (uint16_t)v6 > 0xDu )
    {
      if ( v6 != 32 )
        goto LABEL_56;
      goto LABEL_53;
    }
    v13 = (word_17F819[14 * v6] + word_17F817[14 * v6]) / 2 * v23;
    v15 = *(uint8_t *)(313 * a3 + dword_192864 + 37);
LABEL_46:
    v14 = v15 + 1;
    goto LABEL_47;
  }
  if ( (uint16_t)v6 <= 0x24u )
  {
    v16 = dword_192864 + 313 * a3;
    v13 = sub_1E4028(a3, (word_17F819[14 * v6] + word_17F817[14 * v6]) / 2,   /* 1.50 028E35, 028E3A: sub_1E400A */
                     *(int16_t *)((char *)&word_17F6C1 + 59 * *(uint8_t *)(v16 + 38)))
        * v23;
    v15 = *(uint8_t *)(v16 + 37);
    goto LABEL_46;
  }
  if ( (uint16_t)v6 < 0x27u )
  {
    if ( (uint16_t)v6 > 0x25u )
      goto LABEL_50;
LABEL_53:
    v8 = 1000;
    goto LABEL_56;
  }
  if ( (uint16_t)v6 <= 0x27u )
  {
    if ( *(int16_t *)(dword_192864 + 313 * a3 + 59) > 0 )
      v8 = 50;
    goto LABEL_56;
  }
  if ( (uint16_t)v6 < 0x2Cu )
    goto LABEL_56;
  if ( (uint16_t)v6 <= 0x2Cu )
  {
    v8 = 4
       * (*(uint8_t *)(dword_192864 + 313 * a3 + 37) + 1)
       * sub_1E4028(a3, (word_17F819[14 * v6] + word_17F817[14 * v6]) / 2,   /* 1.50 028DE4, 028DE9: sub_1E400A */
                    *(int16_t *)((char *)&word_17F6C1 + 59 * *(uint8_t *)(dword_192864 + 313 * a3 + 38)))
       * v23;
    goto LABEL_56;
  }
  if ( v6 == 45 )
  {
LABEL_50:
    v12 = 4
        * sub_1E4028(a3, (word_17F819[14 * v6] + word_17F817[14 * v6]) / 2,   /* 1.50 028D9A, 028D9F: sub_1E401A */
                     *(int16_t *)((char *)&word_17F6C1 + 59 * *(uint8_t *)(dword_192864 + 313 * a3 + 38)))
        * v23;
    goto LABEL_48;
  }
LABEL_56:
  if ( sub_4B0D3(a3, 7) )
  {
    if ( g_orion150 )   /* 1.50 028E7B: sub_1E12C6 */
      v8 = (int)v8 * *Hook150_Eseg(0x23D0F2) / 100;
    else
    v8 >>= 2;
  }
  if ( !byte_17F80F[28 * v6] || byte_17F80F[28 * v6] == 3 )
    return (v8 + 99) / 0x64;
  return v8;
}
// 17F6C1: using guessed type int16_t word_17F6C1;
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (00028EAE) --------------------------------------------------------
/* wave 184: written from asm 28EAE-290D5 (Hex-Rays lost everything after 28EF1).
   a1 = eax target ship, a2 = edx weapon, a3 = ebx count, a4 = ecx weapon flags,
   a5 = stack owner (retn 4), a6 = the caller's esi (read for a type 4 weapon outside 28..31).
   Only the low words matter (the result is test si, si / movsx eax, si). */
int sub_28EAE( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int16_t v14 = (int16_t)a1;   // [ebp-14h] push eax
  int16_t v_di = (int16_t)a2;  // edi
  int v4 = a3;                 // [ebp-4] ebx
  int v_cx = a4;               // ecx
  int16_t v_arg = (int16_t)a5; // arg_0
  int16_t v_bx = 0;            // ebx
  int16_t v_si = (int16_t)a6;  // esi
  int16_t v8;                  // [ebp-8]
  int16_t v_dx;                // edx
  uint8_t *v_s;
  uint8_t *v_r;

  if ( v14 )
  {
    v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * v14);
    /* 1.50 028ED0, 028ED5: sub_1E3EF3 ends with xor ebx, ebx - the jle after it always jumps, no armour */
    if ( !g_orion150 && *(int16_t *)(v_s + 308) > 0 )   /* 28ED0 */
      v_bx = *(int16_t *)((char *)&word_17F6C1 + 59 * v_s[38]);
    if ( (uint16_t)sub_4B0D3(v14, 13) )
      v_bx += 3;
  }
  else if ( (int16_t)sub_3A142(0, 0) )   /* 28F00 */
  {
    v_bx = *(int16_t *)(intptr_t)(dword_192864 + 41);
  }
  else
  {
    v_bx = *(int16_t *)(intptr_t)(dword_192864 + 43);
  }
  v8 = v_bx;   /* 28F26 */
  if ( byte_17F80F[28 * v_di] == 4 )
  {
    if ( (uint16_t)v_di == 28 )
      v_si = 100;   /* 28F78 */
    else if ( (uint16_t)v_di == 29 || (uint16_t)v_di == 30 )
      v_si = word_17F819[14 * word_199242[v_arg]];   /* 28F6A */
    else if ( (uint16_t)v_di == 31 )
      v_si = word_17F819[14 * word_199254[v_arg]];   /* 28F52 */
    v_si = (int16_t)(v_si * word_199224[v_arg] / 100);   /* 28F7D */
    v_si = (int16_t)(2 * (v_si - v8) * v4);
  }
  else
  {
    v_si = word_17F819[14 * v_di];   /* 28FA7 */
    if ( (v_cx & 0x4000) != 0 )
      v_si = (int16_t)(3 * v_si / 2);
    if ( (v_cx & 0x200) != 0 && !g_orion150 )   /* 1.50 028FC3: in sub_1E3F6B */
      v_si = (int16_t)(v_si << 2);
    v_si = (int16_t)(v_si * word_199224[v_arg] / 100);   /* 28FC8 */
    v_bx = *(int16_t *)(intptr_t)(dword_192864 + 313 * v14 + 56);
    v_dx = v_bx - 40;
    if ( v_arg < 8 )
    {
      v_r = (uint8_t *)(intptr_t)(dword_197F98 + 3753 * v_arg);
      if ( v_r[439] == 3 )   /* 2901A */
        v_bx -= 70;
      else if ( v_r[395] == 3 )
        v_bx = v_dx;
      else if ( v_r[460] == 3 )
        v_bx -= 20;
    }
    else
    {
      v_bx = v_dx;
    }
    if ( v_di == 40 )   /* 29041 */
      v_bx = 0;
    if ( v_bx < 0 )
      v_bx = 0;
    else if ( (v_cx & 0x400) != 0 )
      v_bx /= 2;
    if ( (v_di == 20 || v_di == 40) && (v_cx & 0x20) == 0 )   /* 29063 */
      v_si /= 2;
    if ( g_orion150 )   /* 1.50 029080, 029085: sub_1E3F6B; 0290A7, 0290AC: sub_1E3FE1 */
    {
      int s = v_si;
      int m = v4;
      int half;

      if ( !v14 && byte_17F80F[28 * v_di] == 2 )
        s >>= 1;
      if ( (int16_t)sub_4B0D3(v14, 10) )
        s -= s * *Hook150_Eseg(0x23D0F3) / 100;
      half = *(_BYTE *)(dword_192864 + 313 * v14 + 64) == 1;
      if ( *Hook150_Eseg(0x23E1EE) && half )
      {
        v_bx = (int16_t)(v_bx + *(int32_t *)Hook150_Eseg(0x23E1EE));   /* add ebx, dword 23E1EE */
        half = 0;
      }
      s -= v8;
      if ( (v_cx & 0x200) != 0 )
        m <<= 2;
      s = (100 - v_bx) * (int16_t)(s * m) / 100;
      if ( (v_cx & 0x100) != 0 )
        s <<= 2;
      if ( half )
        s = s * *(int8_t *)Hook150_Eseg(0x23E1EF) / 100;
      v_si = (int16_t)s;
    }
    else
    {
    v_si = (int16_t)((100 - v_bx) * (int16_t)((v_si - v8) * v4) / 100);   /* 29080 */
    if ( *(_BYTE *)(dword_192864 + 313 * v14 + 64) == 1 )
      v_si /= 2;
    }
  }
  return v_si > 0 ? v_si : 0;   /* 290C6 */
}
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int (uint8_t*)dword_197F98;


//----- (000290DA) --------------------------------------------------------
int sub_290DA( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v8; // edx
  int v9; // eax
  int16_t v10; // cx
  int16_t v11; // bx
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // ebx
  int v18; // esi
  int v19; // edi
  int v20; // esi
  int v21; // edi
  int v22; // eax
  int v23; // eax
  int v25; // [esp+8h] [ebp-24h]
  int v26; // [esp+Ch] [ebp-20h]
  int16_t v27; // [esp+10h] [ebp-1Ch]
  int16_t v30; // [esp+1Ch] [ebp-10h]
  int v31; // [esp+20h] [ebp-Ch] BYREF
  int v32; // [esp+24h] [ebp-8h]
  int v33; // [esp+28h] [ebp-4h] BYREF

  v8 = 313 * a1 + dword_192864;
  v9 = 11 * a2;
  v10 = 0;
  v33 = 0;
  v11 = *(_WORD *)(v8 + v9 + 86);
  LOWORD(v9) = *(_WORD *)(v8 + v9 + 82);
  v32 = 0;
  v30 = v9;
  v31 = 0;
  if ( a6 || !sub_4B0D3(a3, 13) && (v11 & 0x40) != 0 && !g_orion150 )   /* 1.50 029133 */
  {
    v26 = 0;
  }
  else
  {
    if ( a3 )
    {
      v12 = 313 * a3 + dword_192864;
      if ( *(int16_t *)(v12 + 308) > 0 )
        v10 = *(int16_t *)((char *)&word_17F6C1 + 59 * *(uint8_t *)(v12 + 38));
      if ( sub_4B0D3(a3, 13) )
        v10 += 3;
      if ( g_orion150 )   /* 1.50 0291A8: sub_1E3EC4 */
      {
        if ( ((word_17F815[14 * v30] & 0x100) != 0 || (v11 & 0x40) != 0 || word_1998CA) && !sub_4B0D3(a3, 13) )
          v10 = 0;
      }
      else
      if ( (word_17F815[14 * v30] & 0x100) != 0 || (v11 & 0x40) != 0 && !sub_4B0D3(a3, 13) )
        v10 = 0;
    }
    else
    {
      v32 = 1;
      v10 = *(_WORD *)(dword_192864 + 39);
    }
    v26 = v10;
  }
  if ( byte_17F80F[28 * v30] )
  {
    v31 = 0;
    v16 = 0;
    v33 = 100;
    v25 = 0;
  }
  else
  {
    sub_39434(
      a1,
      a5,
      *(_WORD *)(11 * a2 + dword_192864 + 313 * a1 + 86),
      *(_WORD *)(11 * a2 + dword_192864 + 313 * a1 + 82),
      &v31,
      &v33);
    v13 = 40 - (int16_t)v31;
    if ( v13 >= 95 )
      v13 = 95;
    v25 = v13;
    v14 = *(int16_t *)(dword_192864 + 313 * a1 + 52);
    if ( a6 )
      v15 = (int16_t)sub_3DFE0(
                       *(_WORD *)(dword_192B14 + 26 * a3),
                       *(uint8_t *)(313 * *(int16_t *)(dword_192B14 + 26 * a3 + 4) + dword_192864 + 32));
    else
      v15 = *(int16_t *)(dword_192864 + 313 * a3 + 54);
    v16 = v14 - v15;
  }
  v17 = (((int16_t)v33 + word_199224[*(uint8_t *)(dword_192864 + 313 * a1 + 32)] - 100) * word_17F817[14 * v30]
       + 50)
      / 100;
  if ( v17 <= 1 )
    v17 = 1;
  v18 = v17;
  if ( ((word_199224[*(uint8_t *)(313 * a1 + dword_192864 + 32)] - 100 + (int16_t)v33) * word_17F819[14 * v30]
      + 50)
     / 100 >= v17 )
    v17 = ((word_199224[*(uint8_t *)(313 * a1 + dword_192864 + 32)] - 100 + (int16_t)v33)
         * word_17F819[14 * v30]
         + 50)
        / 100;
  v19 = v17;
  if ( g_orion150 )   /* 1.50 029359, 029366, 029380: sub_1E407B */
  {
    if ( (_WORD)v32 )
    {
      v27 = sub_5679E(word_19988E);
      if ( !byte_17F80F[28 * v30] )
      {
        if ( (word_17F815[14 * v30] & 8) != 0 )
        {
          v18 = 0;
          v17 = 0;
        }
        v18 /= 2;
        v17 /= 2;
      }
      v22 = *(int16_t *)((char *)&word_17F6C1 + 59 * v27);
      v18 -= v22;
      v19 = v17 - v22;
      if ( v18 < 0 )
        v18 = 0;
      if ( v19 < 0 )
        v19 = 0;
    }
  }
  else
  if ( (_WORD)v32 && !byte_17F80F[28 * v30] )
  {
    v27 = sub_5679E(word_19988E);
    v20 = v18 / 2;
    v21 = v17 / 2;
    if ( v27 == 7 )
    {
      v18 = (v20 - (__CFSHL__(v20 >> 31, 2) + 4 * (v20 >> 31))) >> 2;
      v19 = (v21 - (__CFSHL__(v21 >> 31, 2) + 4 * (v21 >> 31))) >> 2;
    }
    else
    {
      v22 = *(int16_t *)((char *)&word_17F6C1 + 59 * v27);
      v18 = v20 - v22;
      v19 = v21 - v22;
    }
    if ( v18 < 0 )
      v18 = 0;
    if ( v19 < 0 )
      v19 = 0;
  }
  /* 1.50 293C6: call sub_1E3F2E with word [ebp-2Ch] - 1.50 0292AB (sub_1E3F24) sets it to esi = a3 on both paths */
    v23 = Hook150_1E3F2E(v18, v19, v25, v16, v26, (int16_t)a3);   /* 293CF imul eax, edx */
  return a4 * v23;
}
// 291B4: conditional instruction was optimized away because %arg_4.2==0
// 17F6C1: using guessed type int16_t word_17F6C1;
// 17F815: using guessed type int16_t word_17F815[];
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 199224: using guessed type int16_t word_199224[15];
// 19988E: using guessed type int16_t word_19988E;


//----- (000293D8) --------------------------------------------------------
int sub_293D8(int a1)
{
  int16_t v2; // di
  int16_t *v3; // eax
  int16_t v4; // ax
  int16_t v5; // [esp+0h] [ebp-8h]

  v2 = 0;
  for ( v5 = 0; v5 < 300; ++v5 )
  {
    v3 = (int16_t *)(intptr_t)(26 * v5 + dword_192B14);
    if ( (_WORD)a1 == v3[3] && (_WORD)a1 != v3[2] && *v3 > 0 )
      /* wave 184: 29433 edx = type, ebx = +0Fh, ecx = +11h, push owner, esi = a1 */
      v2 += (int16_t)sub_28EAE(
                       (int16_t)a1,
                       v3[0],
                       *(int16_t *)((char *)v3 + 15),
                       *(int16_t *)((char *)v3 + 17),
                       *(uint8_t *)(313 * v3[2] + dword_192864 + 32),
                       a1);
  }
  if ( (_WORD)a1 )
  {
    v4 = sub_2BB06((int16_t)a1, a1);
    return v2 > v4;   /* wave 184: 29452 cmp di, ax */
  }
  v4 = sub_2BB06(0, a1);
  return v2 > 3 * v4 / 2;   /* wave 184: 29461 */
}
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (00029480) --------------------------------------------------------
int sub_29480( int a1)
{
  int v1; // edx
  int16_t i; // bx
  int v3; // ecx

  v1 = 0;
  for ( i = 0; i < 300 && !(_WORD)v1; ++i )
  {
    v3 = 26 * i;
    if ( a1 == *(_WORD *)(v3 + dword_192B14 + 4) && byte_17F80F[28 * *(int16_t *)(v3 + dword_192B14)] == 4 )
      v1 = 1;
  }
  return v1;
}
// 192B14: using guessed type int dword_192B14;


//----- (000294DF) --------------------------------------------------------
int sub_294DF( int a1)
{
  int v2; // ebx
  int16_t i; // dx
  int v4; // esi
  int v5; // eax
  int16_t v6; // cx

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v2 = 1;
  if ( g_orion150 && *(int16_t *)(dword_192864 + 313 * a1 + 173) > -1 )   /* 1.50 0294EB: sub_1E4F16 */
    return 0;
  if ( sub_4B0D3(a1, 37) || sub_4B0D3(a1, 38) )
    return 0;
  for ( i = 0; i < 8 && (_WORD)v2 == 1; ++i )
  {
    v4 = dword_192864 + 313 * a1;
    v5 = v4 + 11 * i;
    v6 = *(_WORD *)(v5 + 82);
    if ( v6 && *(_BYTE *)(v5 + 84) )
    {
      switch ( byte_17F80F[28 * v6] )
      {
        case 0:
        case 2:
          goto LABEL_13;
        case 1:
          goto LABEL_9;
        case 3:
          if ( *(int16_t *)(v5 + 88) > 0 && *(uint8_t *)(v4 + 32) == word_1998AC )
            goto LABEL_13;
          continue;
        case 4:
          if ( *(int16_t *)(v5 + 88) > 0 )
            goto LABEL_13;
          LOWORD(v2) = (uint16_t)sub_29480(a1) == 0;
          continue;
        case 5:
          if ( v6 != 33 )
            goto LABEL_13;
LABEL_9:
          if ( *(int16_t *)(v5 + 88) > 0 )
LABEL_13:
            v2 = 0;
          break;
        default:
          continue;
      }
    }
  }
  return v2;
}
// 192864: using guessed type int dword_192864;
// 1998AC: using guessed type int16_t word_1998AC;


//----- (000295D0) --------------------------------------------------------
int sub_295D0( int a1)
{
  _BOOL2 v2; // dx
  int16_t i; // bx
  int v4; // eax

  v2 = 0;
  for ( i = 0; i < 300 && !v2; ++i )
  {
    v4 = 26 * i + dword_192B14;
    if ( a1 == *(_WORD *)(v4 + 6) && !*(_BYTE *)(v4 + 8) )
      v2 = a1 != *(_WORD *)(v4 + 4);
  }
  return v2;   /* wave 181: tail loc_294C0 `mov     eax, edx` */
}
// 192B14: using guessed type int dword_192B14;


//----- (00029616) --------------------------------------------------------
int sub_29616()
{
  int result; // eax
  int16_t v1; // dx
  int v2; // eax
  int *v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // [esp+0h] [ebp-8h] BYREF
  int v7; // [esp+4h] [ebp-4h] BYREF

  result = dword_192864 + 313 * word_1998F8;
  v7 = 0;
  v6 = 1;
  v1 = *(uint8_t *)(result + 32);
  if ( v1 == word_1998AC )
  {
    if ( v1 == word_19999C || byte_199F3A == 1 )
    {
      word_192B10[0] = 0;
      word_199900 = 0;
      word_1998E0 = 0;
      if ( !word_1998CE )
        return result;
      v2 = *(int16_t *)((uint8_t*)dword_197F98 + 3753 * word_19988E + 43);
      v3 = &v7;
      return sub_F6816(v2, 1002, (int)v3, 2u);
    }
    word_192B12 = 0;
    word_1998E0 = 0;
    if ( !word_1998CE )
      return result;
    v4 = 3753 * *(uint8_t *)(result + 32);
    v5 = (uint8_t*)dword_197F98;
    goto LABEL_8;
  }
  if ( v1 == word_19999C || byte_199F3A == 1 )
  {
    word_192B12 = 0;
    word_199900 = 0;
    word_1998E0 = 0;
    if ( !word_1998CE )
      return result;
    v5 = 3753 * word_1998AC;
    v4 = (uint8_t*)dword_197F98;
LABEL_8:
    v2 = *(int16_t *)(v5 + v4 + 43);
    v3 = &v6;
    return sub_F6816(v2, 1002, (int)v3, 2u);
  }
  word_192B10[0] = 0;
  word_1998E0 = 0;
  if ( !word_1998CE )
    return result;
  v2 = *(int16_t *)(3753 * *(uint8_t *)(result + 32) + (uint8_t*)dword_197F98 + 43);
  v3 = &v7;
  return sub_F6816(v2, 1002, (int)v3, 2u);
}
// 192864: using guessed type int dword_192864;
// 192B10: using guessed type int16_t word_192B10[];
// 192B12: using guessed type int16_t word_192B12;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F8: using guessed type int16_t word_1998F8;
// 199900: using guessed type int16_t word_199900;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;


//----- (00029790) --------------------------------------------------------
void sub_29790( int a1)
{
  int v2; // esi
  uint8_t *v3; // eax
  char *v4; // esi
  char *v5; // edi
  int v6; // eax
  char *v7; // [esp-4h] [ebp-54h] BYREF
  char v8[80]; // [esp+0h] [ebp-50h] BYREF

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  if ( a1 )
  {
    v2 = 313 * a1;
    v3 = (uint8_t *)(v2 + dword_192864);
    if ( !*(_BYTE *)(v2 + dword_192864 + 36) && !v3[175] )
    {
      sub_38312(a1, (int16_t)(20 * v3[33]), 20 * v3[34]);
      *(_BYTE *)(v2 + dword_192864 + 176) = 0;
      sub_58F1E(76, v8, 80);
      v4 = (char *)(dword_192864 + v2);
      /* vlna 73: puvodne `v7 = v8; v5 = (char *)&v7 + 3;` -
         v asm lezi v7 tesne pred bufferem v8, takze &v7+4 je
         v8[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
         8 B, takze &v7+3 miri DOVNITR ukazatele. */
      v5 = (char *)v8;
      while ( *v5 )
        ++v5;
      strcpy(v5, v4);
      sub_131F7B();
      LOWORD(v6) = sub_77423((int)v8);
      sub_2C601(0, (int)v8);
    }
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x2BAFF je epilog funkce */
}
// 192864: using guessed type int dword_192864;


//----- (00029837) --------------------------------------------------------
/* wave 184: rewritten from asm 29837-29F16 - the AI turn of ship word_1998F8 in tactical combat
   (no register arguments; the old version lost the results of most callees) */
#define SHIP_29837(n) ((uint8_t *)(intptr_t)(dword_192864 + 313 * (n)))
void sub_29837(void)
{
  char v4;        // [ebp-4]
  int16_t vC;     // [ebp-0Ch]
  int16_t v14;    // [ebp-14h] last target
  _WORD v10;      // [ebp-10h]
  _WORD v18;      // [ebp-18h]
  int16_t v8;     // [ebp-8]
  int16_t v_si;   // esi - weapon slot
  int16_t v_di;   // edi - target
  int16_t v_cx;   // ecx
  int v_t, v_r, i;
  uint8_t *v_s;
  uint8_t *v_w;   // weapon slot record

  v4 = 0;
  if ( sub_3E563(word_1998F8) )
    return;
  if ( !(int16_t)sub_339A7(word_1998F8, 0, 0) )
    sub_49D09(SHIP_29837(word_1998F8)[33], SHIP_29837(word_1998F8)[34]);
  if ( (int16_t)sub_294DF(word_1998F8) || byte_199B4B[SHIP_29837(word_1998F8)[32]] == -1 )   /* 2988B */
  {
    v_s = SHIP_29837(word_1998F8);
    if ( v_s[49] && !(int16_t)sub_42A61(v_s[32]) && v_s[32] < 8u && word_1998C8 == 1 )
    {
      v_s[75] = 1;
      v_s[71] = -1;
    }
  }
  sub_2864A(SHIP_29837(word_1998F8)[32]);   /* 29929 */
  sub_46CC8(word_1998F8, 0);
  do
  {
    vC = 0;   /* 2993A */
    v_t = sub_2A4E8(word_1998F8);
    if ( (int16_t)sub_1171AB(0, 0, 0, 0) == word_199898 )
      sub_29616();
    if ( (int16_t)v_t != -1 )
    {
      {
        uint8_t v177 = (uint8_t)sub_2A545(word_1998F8, (int16_t)v_t);

        if ( g_orion150 )   /* 1.50 02998D, 029992: sub_1E2490 - the old byte into byte 1E248C for sub_1E24A8 */
          *Hook150_Ecode(0x1E248C) = SHIP_29837(word_1998F8)[177];
        SHIP_29837(word_1998F8)[177] = v177;   /* 2998D */
      }
      vC = (int16_t)sub_2A9A5(word_1998F8, (int16_t)v_t);
          Hook150_1E24A8();   /* 1.50 29998: call sub_1E24A8 */
      if ( vC )
        v4 = 0;
      else
      {
        v4 = 1 - v4;   /* 299A5 */
        word_1998DA = 2;
      }
    }
    else
    {
      v4 = 0;
    }
    if ( (int16_t)sub_1171AB(0, 0, 0, 0) == word_199898 )   /* 299BC */
      sub_29616();
    v_s = SHIP_29837(word_1998F8);
    if ( !v_s[36] && !v_s[176] )
    {
      for ( i = 0; i < 8; ++i )
        SHIP_29837(word_1998F8)[11 * i + 90] = -1;
      v14 = -1;
      v_si = 0;
      do
      {
        v_w = SHIP_29837(word_1998F8) + 11 * v_si;   /* 29A2D */
        if ( *(int16_t *)(v_w + 82) == 13 && sub_27F26(word_1998F8)
          || (*(int16_t *)(v_w + 82) == 36 || *(int16_t *)(v_w + 82) == 13) && !sub_27F9F(word_1998F8)
          || *(int16_t *)(v_w + 82) == 32 && (int16_t)sub_2864A(SHIP_29837(word_1998F8)[32]) < 2 )
        {
          v_di = -1;   /* 29A5B */
        }
        else
        {
          SHIP_29837(word_1998F8)[11 * v_si + 90] = 1;   /* 29AEC */
          v_di = (int16_t)sub_2B09E(word_1998F8, v14);
          if ( !SHIP_29837(word_1998F8)[63] )
          {
            if ( v_di != -1 )
              v14 = v_di;
            v_r = (int16_t)sub_2C129(word_1998F8, v_di);   /* 29B2D */
            if ( v_r )
            {
              sub_2BF73(word_1998F8, v_di, v_r);
              v_di = (int16_t)sub_2B09E(word_1998F8, v_di);
            }
          }
          if ( v_di != -1 )   /* 29B58 */
          {
            v_w = SHIP_29837(word_1998F8) + 11 * v_si;
            if ( !byte_17F80F[28 * *(int16_t *)(v_w + 82)]
              && (v_w[86] & 2) == 0
              && ((v_w[86] & 4) == 0 || !(int16_t)sub_295D0(word_1998F8)) )
            {
              v10 = 0;
              v18 = 0;
              if ( SHIP_29837(word_1998F8)[63] )   /* 29BD5 */
                v_r = Hook150_1E25C8(   /* 1.50 029BFB */
                        word_1998F8,
                        *(int16_t *)(intptr_t)(dword_192B14 + 26 * v_di + 9),
                        *(int16_t *)(intptr_t)(dword_192B14 + 26 * v_di + 11));
              else
                v_r = sub_2885A(word_1998F8, v_di);
              v_w = SHIP_29837(word_1998F8) + 11 * v_si;
              sub_39434(word_1998F8, (int16_t)v_r, *(int16_t *)(v_w + 86), *(int16_t *)(v_w + 82), &v10, &v18);
              /* 29C5D: var_10 += a race bonus - var_10 is not read again */
            }
          }
        }
        if ( v_di != -1 )   /* 29C7E */
        {
          v_s = SHIP_29837(word_1998F8);
          if ( v_s[63] == 1 )
          {
            vC = (int16_t)sub_38B5E(
                            word_1998F8,
                            (int16_t)(20 * v_s[33]),
                            (int16_t)(20 * v_s[34]),
                            v_di,
                            *(int16_t *)(intptr_t)(dword_192B14 + 26 * v_di + 9),
                            *(int16_t *)(intptr_t)(dword_192B14 + 26 * v_di + 11),
                            1);
          }
          else
          {
            vC = (int16_t)sub_38B5E(
                            word_1998F8,
                            (int16_t)(20 * v_s[33]),
                            (int16_t)(20 * v_s[34]),
                            v_di,
                            (int16_t)(20 * SHIP_29837(v_di)[33]),
                            (int16_t)(20 * SHIP_29837(v_di)[34]),
                            0);
            if ( SHIP_29837(word_1998F8)[32] == 11 )
              sub_29790(v_di);
          }
        }
        else
        {
          SHIP_29837(word_1998F8)[11 * v_si + 90] = -1;   /* 29D4F */
          ++v_si;
        }
        sub_124D41();   /* 29D6F */
        sub_2F4EE();
        sub_1077D(0, 0, 0, 0);
        sub_2864A(SHIP_29837(word_1998F8)[32]);
      }
      while ( v_si < 8 && !(int16_t)sub_3897A(word_1998F8) );
      for ( i = 0; i < 8; ++i )   /* 29DB6 */
        SHIP_29837(word_1998F8)[11 * i + 90] = 1;
    }
  }
  while ( *(int16_t *)(SHIP_29837(word_1998F8) + 61) > 0 && (vC || v4) );   /* 29DDF */
  if ( (int16_t)sub_42A27(word_1998F8) )   /* 29E0F */
  {
    for ( v_cx = 0; v_cx < word_1998C0; ++v_cx )
    {
      v_r = (int16_t)sub_2C129(word_1998F8, v_cx);
      if ( v_r )
        sub_2BF73(word_1998F8, v_cx, v_r);
    }
  }
  if ( (int16_t)sub_1171AB(0, 0, 0, 0) == word_199898 )
    sub_29616();
  if ( !sub_28168(word_1998F8) )   /* 29E68 */
    return;
  v_s = SHIP_29837(word_1998F8);
  *(int16_t *)(v_s + 256) = 0;
  v8 = v_s[49];
  v_s[49] = 1;
  v_r = (int16_t)sub_3897A(word_1998F8);
  v_s = SHIP_29837(word_1998F8);
  if ( g_orion150 )   /* 1.50 029ECE: sub_1E0D69 - byte +31h back before sub_39E15 */
    v_s[49] = (uint8_t)v8;
  sub_39E15(word_1998F8, (int16_t)(20 * v_s[33]), (int16_t)(20 * v_s[34]), v_r);   /* 29EE6 */
  SHIP_29837(word_1998F8)[49] = (uint8_t)v8;
  word_19296C[word_1998D8] = -1;
}
#undef SHIP_29837
// 1077D: using guessed type int sub_1077D(_DWORD);
// 2BF73: using guessed type int sub_2BF73(_DWORD, _DWORD, _DWORD);
// 2F4EE: using guessed type int sub_2F4EE(_DWORD);
// 192864: using guessed type int dword_192864;
// 19296C: using guessed type int16_t word_19296C[];
// 192B14: using guessed type int dword_192B14;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199898: using guessed type int16_t word_199898;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998C8: using guessed type int16_t word_1998C8;
// 1998D8: using guessed type int16_t word_1998D8;
// 1998DA: using guessed type int16_t word_1998DA;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (00029F1B) --------------------------------------------------------
int sub_29F1B( int a1, int a2, int a3)
{
  int16_t v4; // si
  int16_t v5; // dx
  int v6; // esi
  uint16_t *v7; // ebx
  uint16_t v8; // bx
  int v9; // ebx
  int16_t v10; // bx
  int16_t v11; // bx
  int16_t v12; // si
  int v14; // [esp+4h] [ebp-14h]
  int16_t v16; // [esp+10h] [ebp-8h]
  int v17; // [esp+14h] [ebp-4h]

  a3 = (int16_t)a3;   /* wave 181: the original reads only the low word (movsx) */
  v4 = 0;
  if ( a3 <= 0 )
  {
    v16 = 0;
  }
  else
  {
    v16 = Hook150_1E25C8(a1, *(_WORD *)(26 * a2 + dword_192B14 + 9), *(_WORD *)(26 * a2 + dword_192B14 + 11));   /* 1.50 029F4D */
    if ( v16 < 1 )
      v16 = 1;
  }
  v17 = 0;
  do
  {
    v5 = v17++;
    v4 += sub_289C4(a1, v5, a2, 1, v16);
  }
  while ( (int16_t)v17 < 8 );
  v6 = v4
     / (int16_t)sub_3E095(
                  *(_WORD *)(26 * a2 + dword_192B14),
                  g_orion150 ? *(uint16_t *)(26 * a2 + dword_192B14 + 2)   /* 1.50 029FBC: the word +2 */
                             : *(uint8_t *)(313 * *(int16_t *)(26 * a2 + dword_192B14 + 4) + dword_192864 + 32),
                  26 * a2,
                  HIBYTE(*(_WORD *)(26 * a2 + dword_192B14 + 17)));
  if ( (int16_t)v6 > *(int16_t *)(26 * a2 + dword_192B14 + 15) )
    LOWORD(v6) = *(_WORD *)(26 * a2 + dword_192B14 + 15);
  v7 = (uint16_t *)(26 * a2 + dword_192B14);
  if ( byte_17F80F[28 * (int16_t)*v7] == 4 )
  {
    v8 = *v7;
    if ( v8 >= 0x1Du )
    {
      if ( v8 <= 0x1Eu )
      {
        v9 = word_199242[*(uint8_t *)(313 * a1 + dword_192864 + 32)];
      }
      else
      {
        if ( v8 != 31 )
        {
LABEL_20:
          v10 = 0;
          goto LABEL_22;
        }
        v9 = word_199254[*(uint8_t *)(313 * a1 + dword_192864 + 32)];
      }
      v10 = word_17F819[14 * v9];
      goto LABEL_22;
    }
    if ( v8 == 28 )
    {
      v10 = 100;
      goto LABEL_22;
    }
    goto LABEL_20;
  }
  v10 = word_17F819[14 * (int16_t)*v7];
LABEL_22:
  if ( a1 )
    v11 = v10 - *(int16_t *)((char *)&word_17F6C1 + 59 * *(uint8_t *)(dword_192864 + 313 * a1 + 38));
  else
    v11 = v10 - *(_WORD *)(dword_192864 + 41);
  if ( sub_4B0D3(a1, 7) )
  {
    if ( g_orion150 )   /* 1.50 02A0CC, 02A0D1: sub_1E12AC */
      v6 = (uint16_t)v6 * *Hook150_Eseg(0x23D0F2) / 100;
    else
    LOWORD(v6) = (int16_t)(v6 - (__CFSHL__((int16_t)v6 >> 15, 2) + 4 * ((int16_t)v6 >> 15))) >> 2;
  }
  v12 = v11 * v6;
  if ( byte_17F80F[28 * *(int16_t *)(dword_192B14 + 26 * a2)] != 4 )
    v12 /= 2;
  v14 = v12;
  if ( v12 <= 0 )
    v14 = -10000;
  if ( !sub_2AED2(*(_WORD *)(dword_192B14 + 26 * a2 + 6), a2) )
    return -10000;
  return v14;
}
// 17F6C1: using guessed type int16_t word_17F6C1;
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 199242: using guessed type int16_t word_199242[9];
// 199254: using guessed type int16_t word_199254[42];


//----- (0002A145) --------------------------------------------------------
void sub_2A145(int a1)
{
  int16_t v0; // di
  int v1; // ecx
  int16_t v2; // bx
  int16_t *v3; // eax
  int v4; // ebx
  int16_t v5; // [esp+0h] [ebp-14h]
  int16_t v6; // [esp+8h] [ebp-Ch] BYREF
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  v5 = a1;   /* wave 184: spilled by `push eax` after enter */
  v7 = -5000;
  v8 = 0;
  while ( 1 )
  {
    v0 = v8;
    v1 = 26 * (int16_t)v8;
    v2 = Hook150_1E25C8(v5, *(_WORD *)(v1 + dword_192B14 + 9), *(_WORD *)(v1 + dword_192B14 + 11));   /* 1.50 02A180 */
    v3 = (int16_t *)(v1 + dword_192B14);
    if ( *(int16_t *)(v1 + dword_192B14) > 0
      && byte_17F80F[28 * *v3] != 2
      && *(int16_t *)((char *)v3 + 15) > 0
      && v2 < 30
      && *(_BYTE *)(dword_192864 + 313 * v3[2] + 32) != *(_BYTE *)(313 * v5 + dword_192864 + 32)
      && sub_2AED2(v3[3], v0) )
    {
      if ( (uint16_t)sub_2A810(v5, v0, 1, &v6) )
      {
        v4 = sub_29F1B(v5, v0, 0);
        if ( v4 > (int16_t)v7 )
          v7 = v4;
      }
    }
    if ( (int16_t)++v8 >= 300 )
      return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x2BAFF je epilog funkce */
  }
}
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (0002A239) --------------------------------------------------------
int sub_2A239( int a1, int a2, int a3)
{
  int16_t v4; // ax
  int16_t v5; // ax
  int16_t v6; // dx
  int16_t v7; // bx
  signed int v8; // esi
  int v9; // ebx
  int16_t v10; // ax
  int v11; // ebx
  int v12; // eax
  int16_t v13; // ax
  int16_t v14; // ax
  int16_t v16; // [esp+0h] [ebp-28h]
  int16_t v17; // [esp+10h] [ebp-18h]
  int16_t i; // [esp+14h] [ebp-14h]
  int16_t v20; // [esp+1Ch] [ebp-Ch]
  int16_t v21; // [esp+20h] [ebp-8h]
  int v22; // [esp+24h] [ebp-4h]

  v17 = 0;
  v22 = 0;
  v16 = (int16_t)a3;   /* wave 182: eax (push eax at 0x2A240) */
  v21 = sub_2BB06((int16_t)a1, (int16_t)a1);   /* wave 182: 0x2A246 eax = edx = (int16)dx; 2A25E result */
  if ( sub_3E563(a1) )
    return -20000;
  if ( a2 <= 0 )
  {
    v20 = 0;
  }
  else
  {
    v5 = sub_2885A(v16, a1);   /* wave 184: 2A27B result */
    v20 = v5;
    if ( v5 < 1 )
      v20 = 1;
  }
  for ( i = 0; i < 8; ++i )
  {
    v6 = sub_289C4(v16, i, a1, 0, v20);
    v7 = v6;
    if ( a1 && byte_17F80F[28 * *(int16_t *)(11 * i + dword_192864 + 313 * v16 + 82)] == 4 )
      v7 = 2 * v6;
    v17 += v7;
    if ( !*(_BYTE *)(dword_192864 + 313 * a1 + 176) )
      v22 += sub_289C4(a1, i, v16, 0, 0);
  }
  if ( !v17 )
    return -10000;
  v8 = 3 * (int16_t)v22 * v17 / (unsigned int)v21;
  if ( a2 )
  {
    if ( a1 )
    {
      v9 = 313 * a1;
      if ( *(int16_t *)(dword_192864 + v9 + 308) > 0 )
      {
        v10 = sub_32A20(a1, v16);
        v11 = 2 * (int16_t)sub_39DE0(v10) + dword_192864 + v9;
        if ( v17 >= (int)(*(int16_t *)(v11 + 41)
                        - (__CFSHL__((uint64_t)*(int16_t *)(v11 + 41) >> 32, 2)
                         + 4 * ((uint64_t)*(int16_t *)(v11 + 41) >> 32))) >> 2 )
        {
          if ( v17 < *(int16_t *)(v11 + 41) )
          {
            v8 /= 2;
            if ( v8 < 2 )
              v8 = 2;
          }
        }
        else
        {
          v8 = 1;
        }
      }
    }
  }
  if ( a1 )
  {
    if ( v17 > v21 / 3 )
    {
      v12 = 5 * (int16_t)v22;
      goto LABEL_28;
    }
  }
  else if ( v17 > v21 )
  {
    v12 = 3 * (int16_t)v22;
LABEL_28:
    v8 += v12;
  }
  if ( sub_3E57C(a1) )
    v8 /= 2;
  v13 = sub_293D8(a1);   /* wave 184: 2A430 cmp ax, 1 */
  if ( v13 == 1 )
    v8 -= 1000;
  if ( !(_WORD)v22 )
    v8 -= 2000;
  v14 = sub_388CE((int16_t)a1);   /* 2A454 */
  if ( v14 )
    v8 -= 5000;
  return v8;
}
// 192864: using guessed type int dword_192864;


//----- (0002A46A) --------------------------------------------------------
int sub_2A46A(int a1)
{
  int16_t i; // cx
  _BYTE *v1; // eax
  int v2; // eax
  int16_t v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  int v5; // [ebp-4h] - the best target

  v3 = a1;   /* 2A473 push eax - var_C */
  v5 = -1;
  v4 = -5000;
  for ( i = 1; i < word_1998C0; ++i )
  {
    v1 = (_BYTE *)(dword_192864 + 313 * i);
    if ( !v1[36] && v1[32] != *(_BYTE *)(313 * v3 + dword_192864 + 32) && v1[64] != 4 && !sub_3E563(i) )
    {
      v2 = sub_2A239(v3, i, 0);   /* wave 184: 2A4C5 eax = a1, edx = i, ebx = 0 */
      if ( v2 > v4 )
      {
        v5 = i;
        v4 = v2;
      }
    }
  }
  return v5;   /* wave 184: 2A4E3 jmp 29478 (mov eax, [var_4]) */
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0002A4E8) --------------------------------------------------------
int sub_2A4E8( int a1)
{
  int v1; // ebx
  int v2; // eax
  int v3; // edx

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v1 = 313 * a1;
  *(_BYTE *)(v1 + dword_192864 + 63) = 0;
  v2 = sub_2A46A(a1);   /* 2A4FF */
  v3 = v2;
  if ( (int16_t)v2 == -1
    && !*(_BYTE *)(dword_192864 + 36)
    && *(uint8_t *)(v1 + dword_192864 + 32) == word_1998AC )
  {
    return 0;
  }
  return v3;
}
// 192864: using guessed type int dword_192864;
// 1998AC: using guessed type int16_t word_1998AC;


//----- (0002A545) --------------------------------------------------------
int sub_2A545( int a1, int a2)
{
  int v2; // edi
  int16_t v3; // ax
  int16_t v4; // ax
  int v5; // ebx
  unsigned int v6; // eax
  int v8; // [esp+8h] [ebp-1Ch]
  int v9; // [esp+10h] [ebp-14h]
  int v10; // [esp+14h] [ebp-10h]
  int v11; // [esp+18h] [ebp-Ch]
  int16_t v12; // [esp+1Ch] [ebp-8h]
  int16_t v13; // [esp+20h] [ebp-4h]

  v12 = 0;
  v11 = 0;
  v10 = 0;
  v13 = 0;
  v2 = a1;
  while ( 1 )
  {
    v3 = *(_WORD *)(313 * v2 + dword_192864 + 11 * v13 + 82);
    if ( v3 )
    {
      switch ( byte_17F80F[28 * v3] )
      {
        case 0:
          v8 = (int16_t)sub_289C4(v2, v13, a2, 0, 1);
          v9 = (int16_t)sub_289C4(v2, v13, a2, 0, 5);
          v5 = (int16_t)sub_289C4(v2, v13, a2, 0, 12);
          if ( v5 <= v9 / 2 )
          {
            if ( v8 / 2 >= v9 )
            {
              v4 = v8;
LABEL_21:
              v12 += v4;
              break;
            }
            v6 = v9;
            goto LABEL_13;
          }
          v10 += v5;
          break;
        case 1:
          if ( word_199890 == 1 )
            goto LABEL_12;
          goto LABEL_14;
        case 2:
          if ( v3 == 20 || v3 == 40 )
            goto LABEL_17;
          if ( v3 != 19 )
            goto LABEL_14;
LABEL_12:
          v6 = sub_289C4(v2, v13, a2, 0, 5);
          goto LABEL_13;
        case 3:
          if ( a2 )
            break;
          v4 = sub_289C4(v2, v13, 0, 0, 0);
          goto LABEL_21;
        case 4:
          goto LABEL_20;
        case 5:
          if ( v3 == 36 || v3 == 44 || v3 == 32 || v3 == 13 )
          {
LABEL_17:
            v4 = sub_289C4(a1, v13, a2, 0, 1);
            goto LABEL_21;
          }
          if ( v3 == 34 || v3 == 45 || v3 == 37 || v3 == 35 )
          {
            v6 = sub_289C4(a1, v13, a2, 0, 1);
LABEL_13:
            v11 += v6;
            break;
          }
          if ( v3 != 38 )
          {
            if ( v3 != 39 )
              break;
LABEL_20:
            v4 = sub_289C4(v2, v13, a2, 0, 1);
            goto LABEL_21;
          }
LABEL_14:
          v10 += sub_289C4(v2, v13, a2, 0, 12);
          break;
        default:
          break;
      }
    }
    if ( ++v13 >= 8 )
      break;
  }
  /* wave 184: 2A70A - the tail Hex-Rays lost; the sums are compared as words */
  v3 = *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32);
  if ( !byte_199B4B[v3] || byte_199B4B[v3] == 1 )
    v12 <<= 1;
  v5 = 3 * v12 / 2;
  if ( (int16_t)v10 >= v5 )
    return (int16_t)v10 >= 3 * (int16_t)v11 / 2 ? 2 : 1;
  return (int16_t)v11 >= v5 ? 1 : 0;
}
// 192864: using guessed type int dword_192864;
// 199890: using guessed type int16_t word_199890;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (0002A77D) --------------------------------------------------------
int sub_2A77D(
        int a1, int a2, unsigned int a3, int a4,
        int a5,
        int16_t *a6,
        _WORD *a7,
        _WORD *a8,
        int a9)
{
  int16_t v9; // si

  a3 = (int16_t)a3;   /* wave 181: the original reads only the low word (movsx) */
  if ( a3 )
  {
    if ( a3 <= 1u )
    {
      a5 = 15;
    }
    else if ( a3 == 2 )
    {
      a5 = 50;
    }
  }
  else
  {
    a5 = 3;
  }
  v9 = a1 - a5;
  if ( (int16_t)(a1 - a5) >= 0 )
  {
    if ( v9 < (int16_t)a9 )
    {
      *a6 = 0;
      a7[*a6] = a2;
      a8[*a6] = a4;
      a9 = a1 - a5;
LABEL_14:
      ++*a6;
      return a9;
    }
    if ( v9 == (_WORD)a9 && *a6 < 20 )
    {
      a7[*a6] = a2;
      a8[*a6] = a4;
      goto LABEL_14;
    }
  }
  return a9;
}


//----- (0002A810) --------------------------------------------------------
int sub_2A810( int a1, int a2, int a3, int16_t *a4)
{
  int v5; // eax
  int16_t v6; // dx
  int16_t v7; // ax
  int16_t v8; // dx
  int16_t v9; // ax
  int v10; // eax
  int16_t v11; // bx
  int16_t v12; // dx
  int16_t v13; // ax
  int v14; // ecx
  int v16; // [esp+4h] [ebp-14h]
  int16_t v17; // [esp+8h] [ebp-10h]
  int16_t v18; // [esp+Ch] [ebp-Ch]

  v16 = 1;
  v17 = -1;
  *a4 = *(uint8_t *)(dword_192864 + 313 * a1 + 35);
  do
  {
    v5 = 313 * a1 + dword_192864 + 11 * ++v17;
    v6 = *(uint8_t *)(v5 + 85);
    v18 = v6;
  }
  while ( (uint16_t)sub_389E8(*(_WORD *)(v5 + 82), *(_WORD *)(v5 + 86), a2, a3) && v17 < 8 );
  if ( v6 != 15 )
  {
    v7 = a3
       ? sub_329A4(a1, *(_WORD *)(dword_192B14 + 26 * a2 + 9), *(_WORD *)(dword_192B14 + 26 * a2 + 11))
       : sub_32A20(a1, a2);
    v8 = v7;
    if ( ((char)v18 & (uint8_t)sub_32AD1(v7)) == 0 )
    {
      if ( v18 == 2 )
        v9 = 60;
      else
        v9 = 0;
      if ( v8 >= 180 )
      {
        v10 = (2 * (300 - v9 - v8) + 44) / 45;
        v11 = -1;
      }
      else
      {
        v10 = (2 * (v8 - (v9 + 60)) + 44) / 45;
        v11 = 1;
      }
      v12 = v10;
      v13 = v10 * v11 + *(uint8_t *)(dword_192864 + 313 * a1 + 35);
      *a4 = v13;
      if ( v13 < 0 )
        *a4 += 16;
      if ( *a4 > 15 )
        *a4 -= 16;
      v14 = *(int16_t *)(313 * a1 + dword_192864 + 61);
      if ( (int16_t)sub_3F923(a1) * v12 > v14 )
        return 0;
    }
  }
  return v16;
}
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (0002A9A5) --------------------------------------------------------
/* wave 184: rewritten from asm 2A9A5-2ACF4 - a1 = eax ship, a2 = edx target (ship or missile);
   returns var_14 (1 = the ship moved) */
int sub_2A9A5( int a1, int a2)
{
  int16_t v29 = (int16_t)a1;   // [ebp-74h] push eax
  int16_t v_t = (int16_t)a2;   // esi
  int16_t v_di = (int16_t)a1;  // edi - the caller's edi is the ship too (29978)
  int v4; // cx
  int16_t v36; // [ebp-10h] count of the best hexes
  int v35; // [ebp-14h]
  _WORD v30[20]; // [ebp-70h] rows
  _WORD v31[20]; // [ebp-48h] columns
  uint8_t *v8;
  int16_t v_x, v_y, v38, v39;
  int v16, v37, v23;
  int16_t v24;

  v8 = (uint8_t *)(intptr_t)(dword_192864 + 313 * word_1998F8);
  v4 = 0;
  v36 = 0;
  v35 = 0;
  if ( byte_199B4B[v8[32]] == -1 )
    v8[177] = 2;
  if ( !v8[63] && (byte_199B4B[v8[32]] == 3 || byte_199B4B[v8[32]] == 2) )   /* 2A9F4 */
    v4 = word_199890 != 1 || byte_17F80F[28 * *(int16_t *)(v8 + 82)] != 1;
  word_1998C2 = 0;
  if ( !v4 )
  {
    if ( v8[63] == 1 )   /* 2AA6D: the target is a missile */
    {
      v_x = (int16_t)(*(int16_t *)(intptr_t)(dword_192B14 + 26 * v_t + 9) / 20);
      v_y = (int16_t)(*(int16_t *)(intptr_t)(dword_192B14 + 26 * v_t + 11) / 20);
    }
    else
    {
      v_x = *(uint8_t *)(dword_192864 + 313 * v_t + 33);
      v_y = *(uint8_t *)(dword_192864 + 313 * v_t + 34);
    }
    v16 = sub_134637(v8[33], v8[34], v_x, v_y);
    switch ( v8[177] )   /* 2AAF0 */
    {
      case 0:
        v_di = (int16_t)(v16 - 3);
        break;
      case 1:
        v_di = (int16_t)(v16 - 15);
        break;
      case 2:
        v_di = (int16_t)(v16 - 50);
        break;
    }
    if ( v_di > 0 )
    {
      for ( v38 = 0; v38 < 81; ++v38 )
      {
        for ( v39 = 0; v39 < 68; ++v39 )
        {
          if ( word_18C9A8[68 * v38 + v39] != 2000 )
            continue;
          v37 = sub_134637(v38, v39, v_x, v_y);   /* 2ABB9 */
          v_di = (int16_t)sub_2A77D(
                            (int16_t)v37,
                            v38,
                            *(uint8_t *)(dword_192864 + 313 * v29 + 177),
                            v39,
                            v_di,
                            &v36,
                            v30,
                            v31,
                            v_di);
        }
      }
    }
    if ( v36 > 0 )   /* 2AC18 */
    {
      v23 = (int16_t)(sub_1247A0(v36) - 1);
      sub_3F95F(word_1998F8, (int16_t)v30[v23], (int16_t)v31[v23]);   /* 2AC3D (cx for 3EE0F, which overwrites cl) */
      v24 = (int16_t)sub_3EE0F(word_1998F8, (int16_t)v30[v23], (int16_t)v31[v23]);
      if ( v24 > 0 )
      {
        v35 = 1;
        *(_WORD *)(313 * word_1998F8 + dword_192864 + 61) -= v24;
        if ( g_orion150 && *(int16_t *)(313 * word_1998F8 + dword_192864 + 61) < 0 )   /* 1.50 02AC7F: sub_1E3B28 */
          *(_WORD *)(313 * word_1998F8 + dword_192864 + 61) = 0;
      }
    }
  }
  if ( *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 63) )   /* 2AC84 */
  {
    v_x = (int16_t)(*(int16_t *)(intptr_t)(dword_192B14 + 26 * v_t + 9) / 20);
    v_y = (int16_t)(*(int16_t *)(intptr_t)(dword_192B14 + 26 * v_t + 11) / 20);
  }
  else
  {
    v_x = *(uint8_t *)(dword_192864 + 313 * v_t + 33);
    v_y = *(uint8_t *)(dword_192864 + 313 * v_t + 34);
  }
  sub_3FA61(word_1998F8, v_x, v_y);
  word_1998C2 = 0;
  return v35;   /* wave 184: 2ACF1 mov eax, [var_14] */
}
// 18C9A8: using guessed type int16_t word_18C9A8[4979];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 199890: using guessed type int16_t word_199890;
// 1998C2: using guessed type int16_t word_1998C2;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (0002ACF9) --------------------------------------------------------
int sub_2ACF9( int a1, int a2, int a3, int *a4, int a5)
{
  _BYTE *v6; // ebx
  int16_t *v7; // ebx
  int16_t v8; // ax
  int v9; // eax
  int v10; // ebx
  int v13; // [esp+Ch] [ebp-18h]
  char v14; // [esp+10h] [ebp-14h]
  int16_t v15; // [esp+14h] [ebp-10h]
  int16_t v16; // [esp+18h] [ebp-Ch]
  int v17; // [esp+1Ch] [ebp-8h]
  int16_t i; // [esp+20h] [ebp-4h]

  v17 = -1;
  v13 = -5000;
  LOWORD(a5) = (uint16_t)sub_3A142(a3, a5) == 0;
  while ( (int16_t)a5 < word_1998C0 )
  {
    v6 = (_BYTE *)(dword_192864 + 313 * (int16_t)a5);
    if ( !v6[36] && v6[32] != *(_BYTE *)(313 * a1 + dword_192864 + 32) && v6[64] != 4 && !sub_3E563(a5) )
    {
      v16 = 0;
      for ( i = 0; i < 8 && !v16; ++i )
      {
        v7 = (int16_t *)(11 * i + 313 * a1 + dword_192864 + 82);
        if ( *v7 )
        {
          v8 = sub_32A20(a1, a5);
          v14 = sub_32AD1(v8);
          v15 = (uint8_t)byte_17F80F[28 * *v7];
          if ( sub_4584C(a1, i)
            && *((_BYTE *)v7 + 9)
            && (v14 & *((uint8_t *)v7 + 3)) != 0
            && (v15 != 2 && v7[3] || v15 == 2 && !v7[3]) )
          {
            if ( (uint16_t)sub_39F1D(i, a1, a5, 0, 0) )
              v16 = 1;
          }
        }
      }
      if ( v16 == 1 )
      {
        v9 = sub_2A239(a5, 1, a5);
        v10 = v9;
        if ( (_WORD)a5 == a2 && v9 > 0 )
        {
          if ( v9 <= 6000 )
            v10 = 10 * v9;
          else
            v10 = 60000;
        }
        if ( (_WORD)a5 == word_19B540 && v10 > 0 )
        {
          if ( v10 <= 12000 )
            v10 *= 5;
          else
            v10 = 60000;
        }
        if ( v10 > v13 )
        {
          v13 = v10;
          v17 = a5;
        }
      }
    }
    ++a5;
  }
  if ( (int16_t)v17 == -1 )
    *a4 = -20000;
  else
    *a4 = v13;
  return v17;
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;
// 19B540: using guessed type int16_t word_19B540;


//----- (0002AED2) --------------------------------------------------------
_BOOL2 sub_2AED2_131( int a1, int a2)
{
  uint16_t *v3; // eax
  uint16_t v4; // cx
  int16_t v5; // bx
  int v6; // ebx
  int v7; // eax
  int16_t v8; // ax

  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  v3 = (uint16_t *)(dword_192B14 + 26 * a2);
  v4 = *v3;
  v5 = 0;
  if ( byte_17F80F[28 * (int16_t)*v3] != 4 )
  {
    v5 = word_17F819[14 * (int16_t)*v3];
    goto LABEL_13;
  }
  if ( v4 >= 0x1Du )
  {
    if ( v4 <= 0x1Eu )
    {
      v6 = word_199242[*(uint8_t *)(dword_192864 + 313 * (int16_t)v3[2] + 32)];
    }
    else
    {
      if ( v4 != 31 )
        goto LABEL_13;
      v6 = word_199254[*(uint8_t *)(dword_192864 + 313 * (int16_t)v3[2] + 32)];
    }
    v5 = word_17F819[14 * v6];
    goto LABEL_13;
  }
  if ( v4 == 28 )
    v5 = 100;
LABEL_13:
  v7 = dword_192864 + 313 * a1;
  if ( *(int16_t *)(v7 + 308) <= 0 )
    v8 = 0;
  else
    v8 = *(int16_t *)((char *)&word_17F6C1 + 59 * *(uint8_t *)(v7 + 38));
  return v5 > v8;
}
// 17F6C1: using guessed type int16_t word_17F6C1;
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 199242: using guessed type int16_t word_199242[9];
// 199254: using guessed type int16_t word_199254[42];


//----- (0002AFA9) --------------------------------------------------------
int sub_2AFA9( int a1, int *a2)
{
  int v2; // edi
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int16_t v7; // [esp+0h] [ebp-18h]
  int v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  v7 = a1;   /* wave 181: v7 saved by the prologue (push eax) */
  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v9 = -5000;
  v2 = -1;
  v3 = 0;
  *(_BYTE *)(dword_192864 + 313 * a1 + 63) = 0;
  do
  {
    v8 = 26 * (int16_t)v3;
    v4 = v8 + dword_192B14;
    if ( *(int16_t *)(v8 + dword_192B14) > 0
      && *(int16_t *)(v4 + 15) > 0
      && (g_orion150 ? (uint8_t)sub_3BB3D(v3)   /* 1.50 02B022, 02B027: sub_1E1116 */
                     : *(_BYTE *)(dword_192864 + 313 * *(int16_t *)(v4 + 4) + 32)) != *(_BYTE *)(313 * v7 + dword_192864 + 32)
      && sub_2AED2(v7, v3)
      && (byte_17F80F[28 * *(int16_t *)(v8 + dword_192B14)] == 1
       || byte_17F80F[28 * *(int16_t *)(v8 + dword_192B14)] == 4) )
    {
      v5 = sub_29F1B(v7, v3, 1);
      if ( v5 > v9 )
      {
        v2 = v3;
        v9 = v5;
      }
    }
    ++v3;
  }
  while ( (int16_t)v3 < 300 );
  if ( (int16_t)v2 == -1 )
    *a2 = -20000;
  else
    *a2 = v9;
  return v2;
}
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (0002B09E) --------------------------------------------------------
int sub_2B09E( int a1, int a2)
{
  int v3; // ecx
  int v4; // esi
  int v5; // eax
  int v6; // ebx - sub_2ACF9 target
  int v9; // esi/edi - sub_2AFA9 target
  int v7; // [esp+0h] [ebp-8h] BYREF
  int v8; // [esp+4h] [ebp-4h] BYREF

  v3 = (int16_t)a1;
  v4 = 313 * v3;
  v5 = *(uint8_t *)(v4 + dword_192864 + 32);
  if ( byte_199B4B[v5] == 1 || byte_199B4B[v5] == 3 )
  {
    v6 = sub_2ACF9(v3, (int16_t)a2, v3, &v8, v4);
    v9 = sub_2AFA9(v3, &v7);
    if ( v7 / 2 > v8 )
    {
      *(_BYTE *)(v4 + dword_192864 + 63) = 1;
      return v9;   /* wave 184: 2B104 mov eax, esi */
    }
    *(_BYTE *)(v4 + dword_192864 + 63) = 0;
    return v6;   /* wave 184: 2B113 mov eax, ebx */
  }
  v9 = sub_2AFA9(v3, &v7);
  v6 = sub_2ACF9(v3, -1, v3, &v8, v4);
  if ( v8 / 2 > v7 )
  {
    *(_BYTE *)(v4 + dword_192864 + 63) = 0;
    return v6;   /* wave 184: 2B153 mov eax, ebx */
  }
  *(_BYTE *)(v4 + dword_192864 + 63) = 1;
  return v9;   /* wave 184: 2B096 mov eax, edi */
}
// 192864: using guessed type int dword_192864;


//----- (0002B191) --------------------------------------------------------
int sub_2B191( int a1, int a2)
{
  int result; // eax

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  switch ( a1 )
  {
    case 0:
      result = 14;
      break;
    case 1:
      result = 15;
      break;
    case 2:
      result = 16;
      break;
    case 3:
      result = 17;
      break;
    case 4:
      result = 29;
      break;
    case 5:
      result = 30;
      break;
    case 6:
      result = 31;
      break;
    case 7:
      result = 18;
      break;
    case 8:
      a2 = 20;
      goto LABEL_12;
    case 9:
      result = 38;
      break;
    default:
LABEL_12:
      result = a2;
      break;
  }
  return result;
}


//----- (0002B1FD) --------------------------------------------------------
int sub_2B1FD(int a1, _WORD *a2)
{
  int16_t v2; // ax
  int v3; // eax
  int16_t v4; // bx
  int16_t i; // dx
  uint8_t *v6; // eax
  int16_t v7; // si
  int v8; // ecx
  int v9; // edi
  int16_t v10; // si
  int v11; // edx
  int v12; // eax
  int16_t j; // si
  int v14; // eax
  int v15; // ebx
  int v16; // ecx
  int v17; // edi
  int v18; // eax
  int16_t v19; // ax
  uint8_t *v20; // edx
  int v21; // ecx
  int16_t v22; // bx
  int64_t v23; // rax
  int v24; // eax
  int v25; // edx
  int16_t v27; // [esp+4h] [ebp-44h]
  int16_t v28; // [esp+8h] [ebp-40h] BYREF
  int16_t v29; // [esp+Ah] [ebp-3Eh]
  int16_t v30; // [esp+Ch] [ebp-3Ch]
  int16_t v31; // [esp+Eh] [ebp-3Ah]
  int16_t v32; // [esp+10h] [ebp-38h]
  int16_t v33; // [esp+12h] [ebp-36h]
  int16_t v34; // [esp+14h] [ebp-34h]
  int16_t v35; // [esp+16h] [ebp-32h]
  int16_t v36; // [esp+18h] [ebp-30h]
  int v37; // [esp+20h] [ebp-28h]
  int v38; // [esp+24h] [ebp-24h]
  int v39; // [esp+28h] [ebp-20h]
  int v40; // [esp+2Ch] [ebp-1Ch]
  int v41; // [esp+30h] [ebp-18h]
  int v42; // [esp+34h] [ebp-14h]
  int v43; // [esp+38h] [ebp-10h]
  int k; // [esp+3Ch] [ebp-Ch]
  int v45; // [esp+40h] [ebp-8h]
  int v46; // [esp+44h] [ebp-4h] BYREF

  v27 = a1;
  if ( (_WORD)a1 == word_1998AC )
    LOWORD(a1) = word_19988E;
  else
    LOWORD(a1) = word_1998AC;
  v41 = a1;
  v2 = sub_5679E(a1);
  if ( v2 == 7 )
  {
    v42 = 100;
  }
  else
  {
    v3 = 59 * v2;
    LOWORD(v3) = *(int16_t *)((char *)&word_17F6C1 + v3);
    v42 = v3;
  }
  v4 = 0;
  *a2 = 0;
  v43 = 0;
  sub_127776(&v28, 0x16u);
  for ( i = 0; ; ++i )
  {
    if ( i >= word_1998C0 )
    {
      v10 = 0;
      while ( 1 )
      {
        HIWORD(v12) = HIWORD(dword_192B14);
        v11 = dword_192B14 + 26 * v10;
        LOWORD(v12) = *(_WORD *)v11;
        if ( *(int16_t *)v11 <= 0
          || byte_17F80F[28 * (int16_t)v12] != 4
          || *(uint8_t *)(313 * *(int16_t *)(v11 + 4) + dword_192864 + 32) != v27 )
        {
          goto LABEL_60;
        }
        if ( (uint16_t)v12 >= 0x1Eu )
          break;
        if ( (_WORD)v12 == 29 )
        {
          LOWORD(v12) = *(_WORD *)(v11 + 15);
          v32 += v12;
LABEL_59:
          v4 += *(_WORD *)(v11 + 15);
        }
LABEL_60:
        ++v10;
        ServiceAudioTick_FE8BE(v12, 0, 0, 0);
        if ( v10 >= 300 )
        {
          if ( v4 <= 0 )
          {
            v11 = (int)a2;
            *a2 = sub_2BA5E(v41);
          }
          else
          {
            for ( j = 0; !*(&v28 + j) && j <= 6; ++j )
              ;
            v38 = 0;
            v39 = sub_2B191(j, v11);
            while ( (int16_t)v38 < word_1998C0 && j <= 6 )
            {
              v11 = dword_192864;
              v14 = dword_192864 + 313 * (int16_t)v38;
              if ( !*(_BYTE *)(v14 + 36) && !*(_BYTE *)(v14 + 176) )
              {
                LOWORD(v14) = *(uint8_t *)(v14 + 32);
                if ( (_WORD)v14 != v27 )
                {
                  for ( k = 0; (int16_t)k < 8 && j <= 6; ++k )
                  {
                    v15 = 313 * (int16_t)v38;
                    v16 = 11 * (int16_t)k;
                    LOWORD(v11) = *(_WORD *)(v16 + v15 + dword_192864 + 82);
                    v40 = v11;
                    v46 = 0;
                    v17 = (int16_t)v11;
                    v11 = *(int16_t *)(v16 + v15 + dword_192864 + 86);
                    if ( (uint16_t)sub_3A7AA(v17, v11) && !byte_17F80F[28 * v17] )
                    {
                      v18 = v15 + dword_192864;
                      LOWORD(v18) = *(uint8_t *)(v16 + v15 + dword_192864 + 84);
                      v46 = v18;
                      do
                      {
                        v19 = sub_2B7CC(v38, k, *(&v28 + j), v39, (int16_t *)&v46, -1);   /* wave 184: 2B69E result */
                        *(&v28 + j) -= v19;
                        while ( !*(&v28 + j) && j <= 6 )
                          ++j;
                        v11 = j;
                        v39 = sub_2B191(j, j);
                      }
                      while ( *(&v28 + j) && j <= 6 && (int16_t)v46 > 0 );
                    }
                    v14 = 28 * (int16_t)v40;
                    if ( !byte_17F80F[v14] )
                    {
                      HIWORD(v20) = HIWORD(v46);
                      LOWORD(v20) = word_17F819[14 * (int16_t)v40] * v46;
                      v14 = (int)v20;
                      v11 = (int)a2;
                      *a2 += v14;
                    }
                  }
                }
              }
              ServiceAudioTick_FE8BE(v14, 0, 0, 0);
              ++v38;
            }
          }
          v21 = (int16_t)v42;
          v22 = 0;
          while ( 1 )
          {
            if ( (_WORD)v42 == 100 )
            {
              v23 = word_17F819[14 * (int16_t)sub_2B191(v22, v11)];
              v24 = (int)(v23 - (__CFSHL__(HIDWORD(v23), 2) + 4 * HIDWORD(v23))) >> 2;
              v25 = *(&v28 + v22);
            }
            else
            {
              if ( word_17F819[14 * (int16_t)sub_2B191(v22, v22)] - v21 <= 0 )
                v25 = 0;
              else
                v25 = word_17F819[14 * (int16_t)sub_2B191(v22, v22)] - v21;
              v24 = *(&v28 + v22);
            }
            v11 = v24 * v25;
            v43 = v11 + (int16_t)v43;
            if ( ++v22 > 9 )
              return v43;   /* wave 184: 2B7C4 mov eax, [var_10] */
          }
        }
      }
      if ( (uint16_t)v12 <= 0x1Eu )
      {
        LOWORD(v12) = *(_WORD *)(v11 + 15);
        v33 += v12;
      }
      else
      {
        if ( (_WORD)v12 != 31 )
          goto LABEL_60;
        LOWORD(v12) = *(_WORD *)(v11 + 15);
        v34 += v12;
      }
      goto LABEL_59;
    }
    v6 = (uint8_t *)(dword_192864 + 313 * i);
    if ( !v6[36] && !v6[176] )
    {
      LOWORD(v6) = v6[32];
      if ( (_WORD)v6 == v27 )
        break;
    }
LABEL_45:
    ServiceAudioTick_FE8BE(v6, 0, 0, 0);
  }
  v6 = 0;
  while ( 1 )
  {
    v8 = 11 * (int16_t)v6;
    v7 = *(_WORD *)(v8 + 313 * i + dword_192864 + 82);
    v37 = v8 + 313 * i + dword_192864;
    LOWORD(v8) = (uint8_t)byte_17F80F[28 * v7];
    v45 = v8;
    if ( v7 <= 0
      || !*(_BYTE *)(v37 + 84)
      || (_WORD)v8 != 1 && (_WORD)v8 != 2 && (_WORD)v8 != 4
      || ((_WORD)v45 != 1 && (_WORD)v45 != 4 || *(int16_t *)(11 * (int16_t)v6 + 313 * i + dword_192864 + 88) <= 0)
      && (_WORD)v45 != 2 )
    {
      goto LABEL_44;
    }
    if ( (uint16_t)v7 < 0x12u )
    {
      if ( (uint16_t)v7 >= 0xFu )
      {
        if ( (uint16_t)v7 <= 0xFu )
        {
          v9 = 11 * (int16_t)v6 + 313 * i + dword_192864;
          v29 += *(uint8_t *)(v9 + 84);
        }
        else
        {
          v9 = 11 * (int16_t)v6 + dword_192864 + 313 * i;
          if ( (uint16_t)v7 <= 0x10u )
            v30 += *(uint8_t *)(v9 + 84);
          else
            v31 += *(uint8_t *)(v9 + 84);
        }
        goto LABEL_43;
      }
      if ( v7 == 14 )
      {
        v9 = 11 * (int16_t)v6 + dword_192864 + 313 * i;
        v28 += *(uint8_t *)(v9 + 84);
LABEL_43:
        v4 += *(uint8_t *)(v9 + 84);
      }
    }
    else
    {
      if ( (uint16_t)v7 > 0x12u )
      {
        if ( (uint16_t)v7 < 0x1Du )
        {
          if ( v7 == 20 )
            v36 += *(uint8_t *)(11 * (int16_t)v6 + dword_192864 + 313 * i + 84);
          goto LABEL_44;
        }
        if ( (uint16_t)v7 <= 0x1Du )
        {
          v9 = 11 * (int16_t)v6 + 313 * i + dword_192864;
          v32 += 4 * *(uint8_t *)(v9 + 84);
        }
        else if ( (uint16_t)v7 <= 0x1Eu )
        {
          v9 = 11 * (int16_t)v6 + 313 * i + dword_192864;
          v33 += 4 * *(uint8_t *)(v9 + 84);
        }
        else
        {
          if ( v7 != 31 )
            goto LABEL_44;
          v9 = 11 * (int16_t)v6 + 313 * i + dword_192864;
          v34 += 4 * *(uint8_t *)(v9 + 84);
        }
        goto LABEL_43;
      }
      v35 += *(uint8_t *)(11 * (int16_t)v6 + dword_192864 + 313 * i + 84);
    }
LABEL_44:
    if ( (int16_t)++v6 >= 8 )
      goto LABEL_45;
  }
}
// FE8BE: using guessed type int ServiceAudioTick_FE8BE(_DWORD);
// 17F6C1: using guessed type int16_t word_17F6C1;
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0002B7CC) --------------------------------------------------------
int sub_2B7CC( int a1, int a2, int a3, int a4, int16_t *a5, int a6)
{
  int v8; // eax
  int16_t v9; // dx
  int v10; // ebx
  int v11; // ebx
  int v12; // ecx
  int64_t v13; // rax
  int16_t v14; // bx
  int v15; // eax
  int v16; // ebx
  int v17; // [esp+0h] [ebp-24h]
  int16_t v18; // [esp+4h] [ebp-20h]
  int v19; // [esp+8h] [ebp-1Ch]
  int16_t v20; // [esp+Ch] [ebp-18h]
  int16_t v22; // [esp+14h] [ebp-10h]
  int16_t v23; // [esp+18h] [ebp-Ch]
  int16_t v25; // [esp+20h] [ebp-4h]

  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  v8 = dword_192864 + 313 * a1 + 11 * a2;
  v22 = *(_WORD *)(v8 + 86);
  v20 = *(_WORD *)(v8 + 82);
  if ( a6 <= -1 )
    v25 = 2;
  else
    v25 = Hook150_1E25C8(a1, *(_WORD *)(dword_192B14 + 26 * a6 + 9), *(_WORD *)(dword_192B14 + 26 * a6 + 11));   /* 1.50 02B827 */
  if ( *(uint8_t *)(dword_192864 + 313 * a1 + 32) == word_1998AC )
    v9 = word_19988E;
  else
    v9 = word_1998AC;
  v23 = *a5;
  if ( byte_17F80F[28 * a4] != 2 )
  {
    v10 = 2 * v25;
    v17 = 40 - *(int16_t *)((char *)word_17D855 + v10);
    v19 = 313 * a1;
    if ( (int16_t)sub_3DFE0(a4, v9) + v17 - *(int16_t *)(v19 + dword_192864 + 52) >= 95 )
    {
      v18 = 95;
    }
    else
    {
      v11 = 40 - word_17D855[v25];
      v10 = (int16_t)sub_3DFE0(a4, v9) + v11 - *(int16_t *)(v19 + dword_192864 + 52);
      v18 = v10;
    }
    LOWORD(v10) = word_17F819[14 * v20] + word_17F817[14 * v20];
    v12 = 5 * v10;
    if ( (v22 & 0x20) == 0 && (word_17F815[14 * v20] & 4) == 0 && !sub_4B0D3(a1, 15) )
    {
      v13 = word_17D867[v25];
      v12 = (int16_t)v12 - (int)((int16_t)v12 * ((HIDWORD(v13) ^ v13) - HIDWORD(v13))) / 100;
    }
    v14 = 10 * sub_3E095(a4, 0, v12, 0);
    v15 = (100 - v18) * (int16_t)v12 / 100;
    if ( (int16_t)v15 <= v14 )
    {
      if ( (_WORD)v15 )
        v16 = ((int16_t)v15 + v14 - 1) / (int16_t)v15;
      else
        LOWORD(v16) = 1000;
    }
    else
    {
      LOWORD(v16) = 1;
    }
    if ( (int16_t)(v23 / (int16_t)v16) <= a3 )
    {
      *a5 = 0;
      return v23 / (int16_t)v16;   /* wave 184: 2B9B8 mov edi, eax */
    }
    *a5 = v23 - a3 * v16;
    return a3;   /* wave 184: 2B9CC mov edi, [var_8] */
  }
  return 0;   /* wave 184: 2B7F8 xor edi, edi */
}
// 17D855: using guessed type int16_t word_17D855[9];
// 17D867: using guessed type int16_t word_17D867[9];
// 17F815: using guessed type int16_t word_17F815[];
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;


//----- (0002B9E3) --------------------------------------------------------
int16_t sub_2B9E3( int a1, int a2)
{
  return *(uint8_t *)(11 * a2 + dword_192864 + 313 * a1 + 84);
}
// 192864: using guessed type int dword_192864;


//----- (0002BA5E) --------------------------------------------------------
int sub_2BA5E( int a1)
{
  int v2; // esi
  int16_t i; // bx
  int v4; // eax
  int16_t j; // cx
  int16_t v7; // [esp+4h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < word_1998C0; ++i )
  {
    v4 = 313 * i + dword_192864;
    if ( !*(_BYTE *)(v4 + 36) && !*(_BYTE *)(v4 + 176) )
    {
      LOWORD(v4) = *(uint8_t *)(v4 + 32);
      if ( (_WORD)v4 == a1 )
      {
        for ( j = 0; j < 8; ++j )
        {
          v7 = *(_WORD *)(dword_192864 + 313 * i + 11 * j + 82);
          v4 = 28 * v7;
          if ( !byte_17F80F[v4] || v7 == 19 )
          {
            LOWORD(v4) = sub_2B9E3(i, j);
            v2 += v4;
          }
        }
      }
    }
    ServiceAudioTick_FE8BE(v4, 0, 0, 0);
  }
  return v2;
}
// FE8BE: using guessed type int ServiceAudioTick_FE8BE(_DWORD);
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0002BB06) --------------------------------------------------------
int sub_2BB06( int a1, int a2)
{
  int v2; // ebx
  int16_t v4; // ax
  int v5; // edi
  int16_t v6; // si
  int16_t i; // ax
  int v7; // ecx

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v2 = 0;
  if ( a1 )
  {
    v7 = 313 * a1 + dword_192864;   /* wave 184: 2BB1D, the 16-bit sums on bx */
    v2 = (int16_t)((int16_t)sub_36B64(a1) + *(int16_t *)(v7 + 194) + *(int16_t *)(v7 + 170)
                 - *(int16_t *)(v7 + 192));
    v2 += sub_494A8(a1, a2);   /* wave 184: 2BB48 add ebx, eax */
  }
  else
  {
    v4 = sub_5685F(*(uint8_t *)(dword_192864 + 32));
    v5 = (g_orion150 ? *(int16_t *)Hook150_Eseg(0x23CD3E) : 100)   /* 1.50 02BB65, 02BB6A: sub_1E4ACB */
       * (*(int16_t *)((char *)&word_17F642 + 15 * v4) + 100) / 100;
    v6 = sub_3A142(100, a2);
    for ( i = 0; i < 4; ++i )
    {
      if ( ((1 << i) & v6) != 0 )
        v2 += v5;
    }
  }
  return v2;   /* wave 184: 2BB9A mov eax, ebx */
}
// 17F642: using guessed type int16_t word_17F642;
// 192864: using guessed type int dword_192864;


//----- (0002BBA1) --------------------------------------------------------
int sub_2BBA1( int a1, int a2, int a3, int a4)
{
  int16_t v4; // ax
  int i; // esi
  int v6; // eax
  int16_t v7; // ax
  int16_t v8; // bx
  int16_t j; // di
  int v10; // eax
  int k; // esi
  _BYTE *v12; // eax
  int16_t v13; // dx
  int v14; // eax
  int v15; // ebx
  unsigned int v16; // eax
  int16_t v17; // [esp+0h] [ebp-1D0h]
  _WORD v18[210]; // [esp+4h] [ebp-1CCh]
  int v19; // [esp+1A8h] [ebp-28h]
  int v20; // [esp+1ACh] [ebp-24h]
  int v21; // [esp+1B0h] [ebp-20h]
  int v22; // [esp+1B4h] [ebp-1Ch]
  int v23; // [esp+1B8h] [ebp-18h]
  int v24; // [esp+1BCh] [ebp-14h]
  int v25; // [esp+1C0h] [ebp-10h]
  int v26; // [esp+1C4h] [ebp-Ch]
  int v27; // [esp+1C8h] [ebp-8h]
  int v28; // [esp+1CCh] [ebp-4h]

  v17 = a1;   /* wave 181: v17 saved by the prologue (push eax) */
  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v27 = 0;
  v23 = 0;
  v21 = 0;
  v22 = 0;
  v20 = 0;
  if ( a1 < 8 && *(_BYTE *)(3753 * a1 + (uint8_t*)dword_197F98 + 40) != 100 && word_1998C8 == 1 )
  {
    v4 = sub_42A61(a1);   /* wave 184: 2BC06 test ax, ax */
    if ( !v4 )
    {
      for ( i = 0; (int16_t)i < word_1998C0; ++i )
      {
        if ( (_WORD)i || (uint16_t)sub_3A142(a4, i) )
        {
          v6 = dword_192864 + 313 * (int16_t)i;
          if ( !*(_BYTE *)(v6 + 36) && !*(_BYTE *)(v6 + 176) )
          {
            v7 = sub_2BB06(i, i);   /* wave 184: 2BC4C result */
            v8 = v7;
            v18[(int16_t)i] = v7;
            if ( !(_WORD)i )
              v8 = 3 * v7;
            if ( *(uint8_t *)(313 * (int16_t)i + dword_192864 + 32) == v17 )
              v20 += v8;
            else
              v21 += v8;
          }
        }
      }
      for ( j = 0; j < word_1998C0; ++j )
      {
        v10 = dword_192864 + 313 * j;
        if ( !*(_BYTE *)(v10 + 36) && !*(_BYTE *)(v10 + 176) )
        {
          v24 = 0;
          v26 = -1;
          for ( k = 0; (int16_t)k < word_1998C0; ++k )
          {
            if ( (_WORD)k || (uint16_t)sub_3A142(a4, k) )
            {
              v12 = (_BYTE *)(dword_192864 + 313 * (int16_t)k);
              if ( !v12[36] && !v12[176] && v12[32] != *(_BYTE *)(dword_192864 + 313 * j + 32) )
              {
                v25 = 0;
                v28 = 0;
                do
                {
                  v13 = v28;
                  v19 = (int16_t)k;
                  a4 = 0;
                  ++v28;
                  v25 += sub_289C4(j, v13, k, 0, 0);
                }
                while ( (int16_t)v28 < 8 );
                v14 = 2 * v19;
                if ( (int16_t)v25 > (int16_t)v18[v19] )
                {
                  LOWORD(v14) = v18[v19];
                  v25 = v14;
                }
                if ( (int16_t)v25 > (int16_t)v24 )
                {
                  v24 = v25;
                  v26 = k;
                }
              }
            }
          }
          if ( (int16_t)v24 > 0 )
          {
            v18[(int16_t)v26] -= v24;
            if ( *(uint8_t *)(313 * j + dword_192864 + 32) == v17 )
              v22 += (int16_t)v24;
            else
              v23 += (int16_t)v24;
          }
        }
      }
      if ( v21 )
        v15 = 100 * v22 / v21;
      else
        v15 = -1294967296;
      if ( v20 )
        v16 = 100 * v23 / v20;
      else
        v16 = -1294967296;
      if ( (unsigned int)v16 > (unsigned int)(5 * v15) )   /* wave 184: 2BE14 jbe */
        v27 = 1;
    }
  }
  return v27;   /* wave 184: 2BE1D mov eax, [var_8] */
}
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998C8: using guessed type int16_t word_1998C8;


//----- (0002BE25) --------------------------------------------------------
int sub_2BE25( int a1)
{
  int v1; // esi
  int16_t i; // bx
  int v3; // eax
  int16_t j; // cx
  int16_t v6; // [esp+Ch] [ebp-8h]
  int16_t v7; // [esp+10h] [ebp-4h]

  v1 = 0;
  for ( i = 0; i < word_1998C0; ++i )
  {
    v3 = dword_192864 + 313 * i;
    if ( !*(_BYTE *)(v3 + 36) && !*(_BYTE *)(v3 + 176) )
    {
      LOWORD(v3) = *(uint8_t *)(v3 + 32);
      if ( (_WORD)v3 == a1 )
      {
        for ( j = 0; j < 8; ++j )
        {
          v6 = *(_WORD *)(11 * j + 313 * i + dword_192864 + 82);
          v3 = 28 * v6;
          if ( !byte_17F80F[v3] || v6 == 19 )
          {
            v7 = 0;
            if ( (word_17F815[14 * *(int16_t *)(11 * j + 313 * i + dword_192864 + 82)] & 4) != 0
              || sub_4B0D3(i, 15)
              || (*(_BYTE *)(11 * j + 313 * i + dword_192864 + 86) & 0x20) != 0 )
            {
              v7 = 1;
            }
            if ( v7 && sub_4B0D3(i, 25)
              || (v3 = 11 * j, (*(_BYTE *)(dword_192864 + 313 * i + v3 + 86) & 2) != 0)
              || v6 == 19 )
            {
              LOWORD(v3) = sub_2B9E3(i, j);
              v1 += v3;
            }
          }
        }
      }
    }
    ServiceAudioTick_FE8BE(v3, 0, 0, 0);
  }
  return v1;   /* wave 181: tail loc_2BAFD `mov     eax, esi` */
}
// FE8BE: using guessed type int ServiceAudioTick_FE8BE(_DWORD);
// 17F815: using guessed type int16_t word_17F815[];
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0002BF73) --------------------------------------------------------
/* wave 184: written from asm 2BF73-2C128 (Hex-Rays failed) - a1 = eax ship, a2 = edx target,
   a3 = ebx action (1 = sub_37308, 2 = sub_37DA8) */
int sub_2BF73(int a1, int a2, int a3)
{
  int16_t vC = (int16_t)a1;   // [ebp-0Ch] push eax
  int16_t v_di = (int16_t)a2; // edi
  int16_t v_si = (int16_t)a3; // esi
  int v4;                     // [ebp-4]
  int v8;                     // [ebp-8] (sub_37308 gets its address)
  int16_t v_cx;               // cx
  uint8_t *v_s;

  if ( !v_si )
    return a1;   /* 2BF82 jz locret_2C124 (eax = a1) */
  v4 = Hook150_1E0C69(vC, v_di);   /* 1.50 02BF90 */
  v_cx = sub_4B0D3(vC, 35) ? 4 : 1;   /* 2BF9F */
  v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * vC);
  v8 = (int16_t)(v_s[175] / 2);
  if ( !(int16_t)v8 )
    v8 = 1;
  v_s[175] -= (uint8_t)v8;   /* 2BFF7 */
  if ( v_cx == 4
    && ((g_orion150 ? (int16_t)v4 > 1 : (int16_t)v4 != 1) || *(int16_t *)(intptr_t)(dword_192864 + 313 * v_di + 59) > 0)   /* 1.50 02C008 */
    && (uint16_t)sub_4B0D3(v_di, 7) )
  {
    v8 = (int16_t)((int16_t)v8 / 3);   /* 2C035 cwd; idiv bx */
    if ( (int16_t)v8 <= 0 )
      v_si = 0;
  }
  if ( word_1998CE && (v_si == 1 || v_si == 2) && word_199908 != word_19999C )   /* 2C045 */
    sub_42B0F(word_199908, 10015, v_di, (int16_t)v8, v_si);
  if ( v_si == 1 )
  {
    sub_388B8(vC);
    sub_37308(vC, v_di, (int)(intptr_t)&v8, 0);   /* 2C0A5 ebx = &var_8 */
    *(uint8_t *)(intptr_t)(dword_192864 + 313 * vC + 175) += (uint8_t)v8;
  }
  else if ( v_si == 2 )
  {
    sub_388B8(vC);
    sub_388E7(v_di);   /* 2C0D2 eax = edx = di */
    v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * v_di);
    sub_37DA8(vC, v_di, (int16_t)v8, (int16_t)(20 * v_s[33]), (int16_t)(20 * v_s[34]));
  }
  word_1998E8 = 0;
  if ( word_1998CE )
    return sub_3FBFE(1);
  return 0;
}


//----- (0002C129) --------------------------------------------------------
int sub_2C129_131( int a1, int a2)
{
  int v4; // ebx
  int v5; // eax
  int v6; // edx
  int v7; // esi
  char v8; // bl
  int v9; // eax
  int16_t v10; // ax
  int16_t v11; // ax
  int16_t v12; // ax
  int16_t v13; // dx
  int16_t v14; // ax
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // edx
  int16_t v23; // [esp+0h] [ebp-2Ah] BYREF
  int v24; // [esp+4h] [ebp-26h]
  char v25[4]; // [esp+38h] [ebp+Eh] BYREF
  int v26; // [esp+3Ch] [ebp+12h]
  int v27; // [esp+70h] [ebp+46h]
  int v28; // [esp+74h] [ebp+4Ah]
  int v29; // [esp+78h] [ebp+4Eh]
  int v30; // [esp+7Ch] [ebp+52h]
  int v31; // [esp+80h] [ebp+56h]
  int v32; // [esp+84h] [ebp+5Ah]
  int v33; // [esp+88h] [ebp+5Eh]
  int v34; // [esp+8Ch] [ebp+62h]
  int v35; // [esp+90h] [ebp+66h]
  int v36; // [esp+94h] [ebp+6Ah]
  int v37; // [esp+98h] [ebp+6Eh]
  int v38; // [esp+9Ch] [ebp+72h]
  int v39; // [esp+A0h] [ebp+76h]
  int v40; // [esp+A4h] [ebp+7Ah]
  int v41; // [esp+A8h] [ebp+7Eh]

  v36 = a1;
  v4 = 313 * a1;
  v5 = a2;
  v6 = v4 + dword_192864;
  v7 = 0;
  LOWORD(v6) = *(uint8_t *)(v4 + dword_192864 + 32);
  v8 = 1;
  v41 = v6;
  if ( v5 != -1 )
  {
    v9 = Hook150_1E0C69(v36, v5);   /* 1.50 02C16C; wave 184: 2C16C result */
    v38 = v9;
    if ( sub_4B0D3(v36, 35) )
      v40 = 4;
    else
      v40 = 1;
    v37 = 313 * a2;
    v27 = dword_192864;
    if ( *(_BYTE *)(v37 + dword_192864 + 32) > 8u )
      goto LABEL_21;
    v33 = a1;
    v29 = 313 * a1;
    if ( *(_BYTE *)(v29 + v27 + 32) > 8u )
      goto LABEL_21;
    if ( !sub_42A27(a2) )
      goto LABEL_21;
    if ( *(_BYTE *)(v37 + dword_192864 + 64) == 4 )
      goto LABEL_21;
    v10 = sub_388A2(v33);   /* 2C203 */
    if ( v10 )
      goto LABEL_21;
    if ( !a2 )
      goto LABEL_21;
    v29 = dword_192864;
    v30 = v37 + dword_192864;
    v31 = 313 * word_1998F8 + dword_192864;
    if ( *(_BYTE *)(v37 + dword_192864 + 32) == *(_BYTE *)(v31 + 32) )
      goto LABEL_21;
    if ( (int16_t)v38 > (int16_t)v40 )
      goto LABEL_21;
    if ( (_WORD)v40 != 4 )
    {
      v11 = sub_4528F(a2);   /* wave 184: 2C261 result */
      if ( v11 > 0 )
        goto LABEL_21;
    }
    if ( !*(_BYTE *)(dword_192864 + 313 * word_1998F8 + 175)
      || (_WORD)v40 == 4
      && ((g_orion150 ? (int16_t)v38 > 1 : (_WORD)v38 != 1) || *(int16_t *)(dword_192864 + 313 * a2 + 59) > 0)   /* 1.50 02C298 */
      && ((v32 = a2,
           v31 = 313 * a2 + dword_192864,
           v12 = sub_32A20(a2, a1),
           *(int16_t *)(v31 + 2 * (int16_t)sub_39DE0(v12) + 41) > 0)
       || sub_4B0D3(v32, 13)) )
    {
LABEL_21:
      v8 = 0;
    }
    if ( v8 )
    {
      if ( (_WORD)v41 == word_1998AC )
        v13 = word_19988E;
      else
        v13 = word_1998AC;
      if ( word_1998AC > 8 )
        return 0;
      if ( word_19988E > 8 )
        return 0;
      v35 = a1;
      v14 = sub_388A2(v35);   /* 2C33A */
      if ( v14 )
      {
        return 0;
      }
      else if ( (_WORD)v41 == 8 )
      {
        return 1;
      }
      else
      {
        v31 = v13;
        v28 = (int16_t)v41;
        sub_EC767(v41, 1, 0, v13, 1, 0, &v23, (int)v25);
        v15 = sub_35FDA(v28);
        v16 = v15;
        LOWORD(v17) = sub_35CAD(v35);
        v39 = v16 + v17 + v24;
        v18 = sub_35FDA(v31);
        v19 = v18;
        v20 = sub_360AA(v31);
        v21 = 20 * sub_4B0D3(a2, 29) + v20 + v19;
        v34 = (int16_t)(v26 + v21 + sub_35CAD(a2));
        if ( (int16_t)v39 > v34 - 20 )
        {
          if ( *(_BYTE *)(3753 * v28 + (uint8_t*)dword_197F98 + 2232) )
            return 2;
          v7 = 1;
          if ( *(_BYTE *)(313 * v35 + dword_192864 + 175) >= *(_BYTE *)(dword_192864 + 313 * a2 + 175)
            && (int16_t)v39 > v34 - 10 )
          {
            return 2;
          }
        }
      }
    }
  }
  return v7;
}
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (0002C43A) --------------------------------------------------------
/* wave 184: rewritten from asm 2C43A-2C548 - the combat decision of side a1 (eax):
   0FFh, 0 .. 3 (Hex-Rays lost everything after the calls) */
int sub_2C43A( int a1, int a2)
{
  int16_t v3; // cx - the other side
  int16_t v6; // [ebp-10h]
  int v7; // [ebp-0Ch]
  int v8; // [ebp-8]
  int16_t v9; // [ebp-4]
  int v18, v14, v_di, v_r, v_t;

  if ( (int16_t)a1 == word_1998AC )
    v3 = word_19988E;
  else
    v3 = word_1998AC;
  if ( (int16_t)sub_2BBA1((int16_t)a1, a2, (int16_t)a1, v3) )   /* 2C463 */
    return 255;
  v18 = sub_2B1FD((int16_t)a1, (_WORD *)&v9);
  v7 = sub_2BE25((int16_t)a1);
  v_di = sub_2B1FD(v3, (_WORD *)&v6);
  v14 = sub_2BA5E((int16_t)a1);
  v8 = sub_2BA5E(v3);
  v_r = (int16_t)sub_2BE25(v3);   /* 2C4C3 */
  if ( v_r + (int16_t)v_di < (int16_t)v18 + (int16_t)v7
    && byte_199B4B[(int16_t)a1] != 1
    && byte_199B4B[(int16_t)a1] != 0 )
  {
    v_t = 3 * (int16_t)v8 / 4;   /* 2C4EA */
    if ( v6 > v_t )
    {
      if ( (int16_t)a1 == word_1998AC && v6 > 50 )
        return 0;
      return 2;
    }
    return 3;
  }
  if ( (int16_t)v14 > 3 * (int16_t)v8 / 2 )   /* 2C52F */
    return 0;
  return 1;
}
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;


//----- (0002C555) --------------------------------------------------------
int sub_2C555()
{
  int v0; // eax
  void *v1; // eax
  int result; // eax

  word_1998E0 = 0;
  v0 = sub_124D41();
  sub_2C6BA(v0);
  if ( word_1998D6 )
    sub_2E98D();
  else
    sub_2E2CD(-1, -1);
  sub_128EDE(401, 362, 489, 374, 0, 199);
  sub_128EDE(401, 379, 488, 467, 0, 199);
  sub_3459E(401, 379);
  word_1998F4 = 666;
  sub_2F4EE();
  sub_11E718();
  v1 = sub_124DEC();
  result = sub_1077D(v1, 0, 0, 0);
  word_1998E0 = 1;
  return result;
}
// 1077D: using guessed type int sub_1077D(_DWORD);
// 2F4EE: using guessed type int sub_2F4EE(void);
// 1998D6: using guessed type int16_t word_1998D6;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F4: using guessed type int16_t word_1998F4;


//----- (0002C601) --------------------------------------------------------
void sub_2C601(int a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  sub_465D0();
  sub_46CC8(word_1998F8, a2);
  if ( !word_1998E0 )
  {
    v2 = sub_124D7A();
    sub_2C6BA(v2);
    if ( word_1998D6 )
      sub_2E98D();
    else
      sub_2E2CD(-1, -1);
    sub_128EDE(401, 362, 489, 374, 0, 199);
    sub_128EDE(401, 379, 488, 467, 0, 199);
    sub_3459E(401, 379);
    word_1998F4 = 666;
    sub_124E36();
    v3 = sub_124D41();
    v4 = sub_2F4EE();
    sub_1077D(v4, 0, 0, 0);
  }
}
// 1077D: using guessed type int sub_1077D(_DWORD);
// 2F4EE: using guessed type int sub_2F4EE(_DWORD);
// 1998D6: using guessed type int16_t word_1998D6;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F4: using guessed type int16_t word_1998F4;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (0002C6BA) --------------------------------------------------------
void sub_2C6BA(int a1)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int16_t i; // dx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int16_t j; // si
  int v18; // eax
  int v19; // ebx
  int16_t k; // si
  int v21; // edx
  int v22; // ecx
  char v23[32]; // [esp+0h] [ebp-20h] BYREF

  if ( !word_1998F6 || word_1998E0 )
    goto LABEL_36;
  if ( !word_1998CA )
    LOBYTE(a1) = sub_128C32(0, 0, 639, 479, 0);
  ServiceAudioTick_FE8BE(0, 0, 0, 0);
  sub_128EDE(15, 362, 102, 374, 0, 199);
  sub_128EDE(401, 362, 489, 374, 0, 199);
  LOBYTE(v1) = sub_128EDE(401, 379, 488, 467, 0, 199);
  ServiceAudioTick_FE8BE(0, 0, 0, 0);
  v2 = word_1998F8;
  if ( word_1998F8 > -1 )
    sub_3459E(401, 379);
  ServiceAudioTick_FE8BE(0, 0, 0, 0);
  dword_192880 = sub_127C27((int)aCombatLbx_0, 0, dword_193174);
  ServiceAudioTick_FE8BE(dword_192880, 0, 0, 0);
  v3 = sub_12A478(0, 351, dword_192880);
  LOWORD(v3) = word_19999C;
  if ( word_19999C == word_1998AC )
  {
    if ( word_192B10[0] )
      goto LABEL_11;
  }
  else if ( word_192B12 )
  {
LABEL_11:
    sub_12B753(dword_19286C, 1);
    v3 = sub_12A478(273, 364, dword_19286C);
  }
  ServiceAudioTick_FE8BE(v3, 0, 0, 0);
  sub_128AB6(0, 0, 639, 350);
  sub_12B634();
  if ( word_1998CA == 1 )
    v4 = 35;
  else
    v4 = 46;
  dword_192858 = sub_127C27((int)aCombatLbx_0, v4, dword_193174);
  ServiceAudioTick_FE8BE(dword_192858, 0, 0, 0);
  sub_12A478(word_199880, word_199882, dword_192858);
  v5 = sub_12A478(word_199880 - 640, word_199882, dword_192858);
  ServiceAudioTick_FE8BE(v5, 0, 0, 0);
  sub_12A478(word_199880 - 640, word_199882 - 480, dword_192858);
  v6 = sub_12A478(word_199880, word_199882 - 480, dword_192858);
  v7 = ServiceAudioTick_FE8BE(v6, 0, 0, 0);
  if ( word_1998EE == 1 )
  {
    v7 = word_1998F8;
    if ( word_1998F8 > -1 )
    {
      v7 = 313 * word_1998F8 + dword_192864;
      if ( *(_BYTE *)(v7 + 32) < 8u )
      {
        v8 = 3753 * *(uint8_t *)(v7 + 32);
        v7 = (uint8_t*)dword_197F98;
        if ( *(_BYTE *)(v8 + (uint8_t*)dword_197F98 + 40) == 100 )
          sub_34AB6();
      }
    }
  }
  ServiceAudioTick_FE8BE(v7, 0, 0, 0);
  dword_192878 = sub_127C27((int)aCombatLbx_0, 47, dword_193174);
  ServiceAudioTick_FE8BE(dword_192878, 0, 0, 0);
  sub_12A478(word_199886, word_199884, dword_192878);
  v9 = sub_12A478(word_199886 - 640, word_199884, dword_192878);
  ServiceAudioTick_FE8BE(v9, 0, 0, 0);
  sub_12A478(word_199886 - 640, word_199884 - 480, dword_192878);
  v10 = sub_12A478(word_199886, word_199884 - 480, dword_192878);
  ServiceAudioTick_FE8BE(v10, 0, 0, 0);
  dword_192888 = sub_127C27((int)aCombatLbx_0, 48, dword_193174);
  ServiceAudioTick_FE8BE(dword_192888, 0, 0, 0);
  sub_12A478(word_19988C, word_19988A, dword_192888);
  v11 = sub_12A478(word_19988C - 640, word_19988A, dword_192888);
  ServiceAudioTick_FE8BE(v11, 0, 0, 0);
  sub_12A478(word_19988C - 640, word_19988A - 480, dword_192888);
  v12 = sub_12A478(word_19988C, word_19988A - 480, dword_192888);
  ServiceAudioTick_FE8BE(v12, 0, 0, 0);
  sub_12B65C();
  sub_128BE7();
  for ( i = 0; i < word_1998C0; ++i )
  {
    v14 = dword_192864 + 313 * i;
    if ( !*(_BYTE *)(v14 + 36)
      && i != word_1998FC
      && *(_BYTE *)(v14 + 66) != 0xFF
      && *(uint8_t *)(v14 + 66) != word_1998FC )
    {
      sub_ACCDB(i);
    }
  }
  v15 = word_1998F8;
  if ( word_1998F8 != -1 )
  {
    sub_120CCB(2, (int)&unk_17D879);
    sub_120DED(0, 0);
    strcpy(v23, (char *)(313 * word_1998F8 + dword_192864));
    sub_102F4F(59, 362, (int)v23, 88);
    sub_2D1ED(14, 376, word_1998F8, 88);
    sub_2CBCC(14, 376, word_1998F8);
    v15 = sub_2F445(word_1998F8, 15, 379);
  }
  v16 = ServiceAudioTick_FE8BE(v15, 0, 0, 0);
  if ( word_1998E4 == 1 )
  {
    for ( j = 0; j < 640; j += 20 )
    {
      v18 = j;
      v19 = j;
      sub_134D2D(v18, 0, v19, 350, 4);
    }
    for ( k = 0; k < 360; k += 20 )
    {
      v21 = k;
      v22 = k;
      v16 = sub_134D2D(0, v21, 640, v22, 4);
    }
  }
  ServiceAudioTick_FE8BE(v16, 0, 0, 0);
  sub_2F172();
  word_1998F4 = -2;
LABEL_36:
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x33AFE je epilog funkce */
}
// FE8BE: using guessed type int ServiceAudioTick_FE8BE(_DWORD);
// 192858: using guessed type int dword_192858;
// 192864: using guessed type int dword_192864;
// 19286C: using guessed type int dword_19286C;
// 192878: using guessed type int dword_192878;
// 192880: using guessed type int dword_192880;
// 192888: using guessed type int dword_192888;
// 192B10: using guessed type int16_t word_192B10[];
// 192B12: using guessed type int16_t word_192B12;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 199880: using guessed type int16_t word_199880;
// 199882: using guessed type int16_t word_199882;
// 199884: using guessed type int16_t word_199884;
// 199886: using guessed type int16_t word_199886;
// 19988A: using guessed type int16_t word_19988A;
// 19988C: using guessed type int16_t word_19988C;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998CA: using guessed type int16_t word_1998CA;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998E4: using guessed type int16_t word_1998E4;
// 1998EE: using guessed type int16_t word_1998EE;
// 1998F4: using guessed type int16_t word_1998F4;
// 1998F6: using guessed type int16_t word_1998F6;
// 1998F8: using guessed type int16_t word_1998F8;
// 1998FC: using guessed type int16_t word_1998FC;
// 19999C: using guessed type int16_t word_19999C;


//----- (0002CBCC) --------------------------------------------------------
int16_t sub_2CBCC( int a1, int a2, int a3)
{
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int16_t v10; // ax
  int v11; // eax
  int v12; // ebx
  int16_t v13; // dx
  int16_t v14; // ax
  int v15; // ebx
  int16_t result; // ax
  int v17; // ecx
  int v18; // eax
  int16_t v19; // ax
  int v20; // ebx
  unsigned int v21; // ebx
  unsigned int v22; // edx
  int v23; // eax
  int v24; // eax
  int v25; // eax
  unsigned int v26; // eax
  int v27; // eax
  unsigned int v28; // ebx
  unsigned int v29; // edx
  unsigned int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  unsigned int v35; // ebx
  unsigned int v36; // edx
  int16_t v37; // si
  int v38; // eax
  int16_t v39; // [esp+Ch] [ebp-24h]
  int16_t v40; // [esp+Ch] [ebp-24h]
  int16_t v41; // [esp+Ch] [ebp-24h]
  int16_t v42; // [esp+18h] [ebp-18h]
  int16_t v43; // [esp+1Ch] [ebp-14h]
  int16_t v44; // [esp+20h] [ebp-10h]
  int16_t v46; // [esp+28h] [ebp-8h]
  int16_t v47; // [esp+2Ch] [ebp-4h]

  v5 = sub_127C27((int)aCombatLbx_0, 43, dword_193174);
  sub_12A478(a1 - 1, a2 - 1, v5);
  v6 = sub_127C27((int)aCombatLbx_0, 44, dword_193174);
  sub_12A478(a1, a2 + 78, v6);
  v44 = a2 + 85;
  v46 = a1 + 1;
  v47 = a2 + 79;
  v43 = a1 + 88;
  v42 = a1 + 1;
  if ( !a3 )
  {
    v7 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
    sub_12A478(v46, v47, v7);
    if ( !(uint16_t)sub_3A142(a1 + 1, v46) )
    {
      v15 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
      return sub_12A478(v46, v44, v15);
    }
    v8 = *(int16_t *)(dword_192864 + 192);
    v9 = sub_127C27((int)aCombatLbx_0, 88, dword_193174);
    sub_12A478(v46, v44, v9);
    v10 = sub_5685F(*(uint8_t *)(dword_192864 + 32));
    v39 = (int16_t)(88 * v8 / ((g_orion150 ? *(int16_t *)Hook150_Eseg(0x23CD3E) : 100)   /* 1.50 02CCE6, 02CCEB: sub_1E4AD9 */
                               * (*(int16_t *)((char *)&word_17F642 + 15 * v10) + 100) / 0x64u)) / 2;
    sub_128AB6(0, 0, v39 + v42, 479);
    sub_12B634();
    v11 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
    sub_12A478(v46, v44, v11);
    sub_128AB6(v43 - v39, 0, 639, 479);
    v12 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
    v13 = a2 + 85;
    v14 = a1 + 1;
    goto LABEL_27;
  }
  v17 = 313 * a3;
  v18 = v17 + dword_192864;
  if ( *(_BYTE *)(v17 + dword_192864 + 312) > 9u )
  {
    v31 = sub_127C27((int)aCombatLbx_0, 89, dword_193174);
    sub_12A478(v46, v47, v31);
    v32 = sub_127C27((int)aCombatLbx_0, 88, dword_193174);
    sub_12A478(v46, v44, v32);
    if ( *(int16_t *)(v17 + dword_192864 + 192) > 0 )
    {
      v40 = (int16_t)(88 * *(int16_t *)(v17 + dword_192864 + 192) / (unsigned int)*(int16_t *)(v17 + dword_192864 + 170))
          / 2;
      sub_128AB6(0, 0, v40 + v42, 479);
      sub_12B634();
      v33 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
      sub_12A478(v46, v44, v33);
      sub_128AB6(v43 - v40, 0, 639, 479);
      v34 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
      sub_12A478(v46, v44, v34);
      sub_12B65C();
      sub_128BE7();
    }
    v35 = sub_36BE2(a3);
    v36 = v35 - sub_36B64(a3);
    result = v36;
    if ( v36 )
    {
      v41 = a1;
      sub_128AB6(0, 0, (int16_t)(88 * v36 / v35) / 2 + a1 + 1, 479);
      sub_12B634();
      v37 = a1 + 1;
      v38 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
      sub_12A478(v37, a2 + 79, v38);
      sub_128AB6(v41 + 88 - (int16_t)(88 * v36 / v35) / 2, 0, 639, 479);
      v12 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
      v13 = a2 + 79;
      v14 = v37;
LABEL_27:
      sub_12A478(v14, v13, v12);
      sub_12B65C();
      return sub_128BE7();
    }
  }
  else
  {
    if ( g_orion150 ? *(_BYTE *)(v18 + 31) != 0xFF : *(_BYTE *)(v18 + 49) )   /* 1.50 02CDC1: byte +1Fh == -1 */
    {
      v19 = *(uint8_t *)(v18 + 37);
    }
    else if ( word_19988E == 8 )
    {
      v19 = 8;
    }
    else
    {
      v19 = sub_4A884(word_199878);
    }
    v20 = word_180024[18 * v19];
    v21 = v20 * *(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(dword_192864 + 313 * a3 + 51)) / 100 + v20;
    if ( sub_4B0D3(a3, 14) )
      v21 *= 3;
    v22 = v21 - *(int16_t *)(dword_192864 + 313 * a3 + 194);
    if ( v21 != *(int16_t *)(dword_192864 + 313 * a3 + 194) )
    {
      sub_128AB6(0, 0, (int16_t)(88 * v22 / v21) / 2 + a1 + 1, 479);
      sub_12B634();
      v23 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
      sub_12A478(a1 + 1, a2 + 79, v23);
      sub_128AB6(a1 + 88 - (int16_t)(88 * v22 / v21) / 2, 0, 639, 479);
      v24 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
      sub_12A478(a1 + 1, a2 + 79, v24);
      sub_12B65C();
      sub_128BE7();
    }
    v25 = dword_192864 + 313 * a3;
    if ( *(int16_t *)(v25 + 192) > 0 )
    {
      v26 = 44 * *(int16_t *)(v25 + 192) / (unsigned int)*(int16_t *)(v25 + 170);
      if ( (int16_t)v26 < 2 )
        LOWORD(v26) = 2;
      sub_128AB6(a1 + 1, 0, a1 + 1 + v26, 479);
      sub_12B634();
      v27 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
      sub_12A478(a1 + 1, a2 + 85, v27);
      sub_12B65C();
      sub_128BE7();
    }
    v28 = sub_36BE2(a3);
    v29 = v28 - sub_36B64(a3);
    result = v29;
    if ( v29 )
    {
      v30 = 44 * v29 / v28;
      if ( (int16_t)v30 < 2 )
        LOWORD(v30) = 2;
      sub_128AB6(a1 + 88 - v30, 0, a1 + 88, 479);
      sub_12B634();
      v12 = sub_127C27((int)aCombatLbx_0, 87, dword_193174);
      v14 = a1 + 1;
      v13 = a2 + 85;
      goto LABEL_27;
    }
  }
  return result;
}
// 17F642: using guessed type int16_t word_17F642;
// 180024: using guessed type int16_t word_180024[];
// 192864: using guessed type int dword_192864;
// 193174: using guessed type int dword_193174;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;


//----- (0002D1ED) --------------------------------------------------------
int sub_2D1ED( int a1, int a2, int a3, int a4)
{
  int v5; // ebx
  int16_t v6; // ax
  int result; // eax
  int v8; // eax
  char *v9; // edi
  char *v10; // edi
  char *v11; // edi
  char *v12; // edi
  char *v13; // edi
  char *v14; // edi
  char *v15; // edi
  int16_t v16; // si
  int16_t v17; // dx
  int16_t v18; // dx
  int64_t v19; // rax
  int v20; // eax
  int64_t v21; // rax
  int v22; // eax
  int v23; // eax
  int v24; // edi
  unsigned int v25; // eax
  int16_t v26; // di
  int16_t v27; // di
  int16_t v28; // di
  int16_t v29; // di
  int16_t v30; // di
  int64_t v31; // rax
  int v32; // eax
  int64_t v33; // rax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // ebx
  int16_t v38; // [esp+0h] [ebp-6Ah]
  int16_t v39; // [esp+4h] [ebp-66h]
  char v40; // [esp+7h] [ebp-63h] BYREF
  char v41[80]; // [esp+8h] [ebp-62h] BYREF
  char v42[80]; // [esp+58h] [ebp-12h] BYREF
  char v43[12]; // [esp+A8h] [ebp+3Eh] BYREF
  _BYTE v44[8]; // [esp+B4h] [ebp+4Ah] BYREF
  int v45; // [esp+BCh] [ebp+52h]
  int v46; // [esp+C0h] [ebp+56h]
  int v47; // [esp+C4h] [ebp+5Ah]
  int v48; // [esp+C8h] [ebp+5Eh]
  int v49; // [esp+CCh] [ebp+62h]
  int v50; // [esp+D0h] [ebp+66h]
  int v51; // [esp+D4h] [ebp+6Ah]
  int v52; // [esp+D8h] [ebp+6Eh]
  int v53; // [esp+DCh] [ebp+72h]
  int v54; // [esp+E0h] [ebp+76h]
  int v55; // [esp+E4h] [ebp+7Ah]
  int v56; // [esp+E8h] [ebp+7Eh]

  v38 = a2;   /* wave 181: v38 saved by the prologue (push edx) */
  v39 = a1;   /* wave 181: v39 saved by the prologue (push eax) */
  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  if ( a1 >= 20 )
  {
    if ( a1 <= 380 )
      goto LABEL_6;
    a4 = 467;
    sub_128C32(401, 379, 488, 467, 0);
    v5 = sub_127C27((int)aCombatLbx_0, 45, dword_193174);
    v6 = 401;
  }
  else
  {
    a4 = 453;
    sub_128C32(15, 379, 102, 453, 0);
    v5 = sub_127C27((int)aCombatLbx_0, 45, dword_193174);
    v6 = 15;
  }
  sub_12A478(v6, 379, v5);
LABEL_6:
  if ( a3 )
  {
    sub_32B26(a3, 0, 0, 0);
    sub_12D8F5(98, 98, dword_192824);
    v19 = *(uint8_t *)(dword_192864 + 313 * a3 + 35) - 1;
    v20 = (int)(v19 - (__CFSHL__(HIDWORD(v19), 2) + 4 * HIDWORD(v19))) >> 2;
    if ( v20 <= 0 )
      v20 = 0;
    if ( v20 == 1 )
      goto LABEL_45;
    v21 = *(uint8_t *)(dword_192864 + 313 * a3 + 35) - 1;
    v22 = (int)(v21 - (__CFSHL__(HIDWORD(v21), 2) + 4 * HIDWORD(v21))) >> 2;
    if ( v22 <= 0 )
      v22 = 0;
    if ( v22 == 2 )
LABEL_45:
      v23 = 14;
    else
      v23 = 16;
    sub_12F7E6(v23, 11, (int16_t *)dword_19283C, (int16_t *)dword_192824);
    v24 = 313 * a3;
    v56 = *(uint8_t *)(v24 + dword_192864 + 35);
    if ( *(_BYTE *)(v24 + dword_192864 + 38) && *(int16_t *)(v24 + dword_192864 + 308) > 0 )
    {
      sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 1, 0);
      sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 2, 0);
      v25 = (*(int16_t *)(v24 + dword_192864 + 39) + 19) / 10;
      if ( (int)v25 > 10 )
        v25 = 10;
      if ( v25 < 5 )
      {
        if ( v25 )
        {
          if ( v25 > 2 )
          {
            sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 1, 0);
            sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 2, 0);
            sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 80, 0);
            sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 82, 0);
            sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 84, 0);
            v27 = 0;
            sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 86, 0);
            do
            {
              v46 = 313 * a3;
              v51 = 2 * v27;
              if ( *(int16_t *)(v51 + v46 + dword_192864 + 41) < 31 )
              {
                sub_12E0B2(dword_19283C, (int16_t *)dword_192824);
                sub_12EFBD(
                  0,
                  0,
                  (_WORD *)dword_19283C,
                  (int *)dword_18F4C0[4 * ((int16_t)v56 % 4)
                                    + (4
                                     - ((int)((int16_t)v56
                                            - (__CFSHL__((uint64_t)(int16_t)v56 >> 32, 2)
                                             + 4 * ((uint64_t)(int16_t)v56 >> 32))) >> 2)
                                     + v27)
                                    % 4],
                  1);
                sub_13719F(dword_19283C, 86, 1);
                if ( *(int16_t *)(v51 + v46 + dword_192864 + 41) <= 21 )
                  sub_13719F(dword_19283C, 84, 1);
                if ( *(int16_t *)(dword_192864 + 313 * a3 + 2 * v27 + 41) <= 11 )
                  sub_13719F(dword_19283C, 82, 1);
                if ( *(int16_t *)(dword_192864 + 313 * a3 + 2 * v27 + 41) <= 0 )
                  sub_13719F(dword_19283C, 80, 1);
                sub_12F7E6(0, 0, (int16_t *)dword_19283C, (int16_t *)dword_192824);
              }
              ++v27;
            }
            while ( v27 < 4 );
          }
          else
          {
            sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 1, 0);
            sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 2, 0);
            sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 81, 0);
            v26 = 0;
            sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 82, 0);
            do
            {
              v53 = 313 * a3;
              v47 = 2 * v26;
              if ( *(int16_t *)(v47 + v53 + dword_192864 + 41) < 11 )
              {
                sub_12E0B2(dword_19283C, (int16_t *)dword_192824);
                sub_12EFBD(
                  0,
                  0,
                  (_WORD *)dword_19283C,
                  (int *)dword_18F4C0[4 * ((int16_t)v56 % 4)
                                    + (4
                                     - ((int)((int16_t)v56
                                            - (__CFSHL__((uint64_t)(int16_t)v56 >> 32, 2)
                                             + 4 * ((uint64_t)(int16_t)v56 >> 32))) >> 2)
                                     + v26)
                                    % 4],
                  1);
                sub_13719F(dword_19283C, 82, 1);
                if ( *(int16_t *)(v47 + v53 + dword_192864 + 41) <= 0 )
                  sub_13719F(dword_19283C, 81, 1);
                sub_12F7E6(0, 0, (int16_t *)dword_19283C, (int16_t *)dword_192824);
              }
              ++v26;
            }
            while ( v26 < 4 );
          }
        }
      }
      else if ( v25 <= 6 )
      {
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 1, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 2, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 80, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 81, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 83, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 84, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 85, 0);
        v28 = 0;
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 86, 0);
        do
        {
          v52 = 313 * a3;
          v55 = 2 * v28;
          if ( *(int16_t *)(v55 + v52 + dword_192864 + 41) < 51 )
          {
            sub_12E0B2(dword_19283C, (int16_t *)dword_192824);
            sub_12EFBD(
              0,
              0,
              (_WORD *)dword_19283C,
              (int *)dword_18F4C0[4 * ((int16_t)v56 % 4)
                                + (4
                                 - ((int)((int16_t)v56
                                        - (__CFSHL__((uint64_t)(int16_t)v56 >> 32, 2)
                                         + 4 * ((uint64_t)(int16_t)v56 >> 32))) >> 2)
                                 + v28)
                                % 4],
              1);
            sub_13719F(dword_19283C, 86, 1);
            if ( *(int16_t *)(v55 + v52 + dword_192864 + 41) <= 41 )
              sub_13719F(dword_19283C, 85, 1);
            if ( *(int16_t *)(313 * a3 + dword_192864 + 2 * v28 + 41) <= 31 )
              sub_13719F(dword_19283C, 84, 1);
            if ( *(int16_t *)(313 * a3 + dword_192864 + 2 * v28 + 41) <= 21 )
              sub_13719F(dword_19283C, 83, 1);
            if ( *(int16_t *)(313 * a3 + dword_192864 + 2 * v28 + 41) <= 11 )
              sub_13719F(dword_19283C, 81, 1);
            if ( *(int16_t *)(313 * a3 + dword_192864 + 2 * v28 + 41) <= 0 )
              sub_13719F(dword_19283C, 80, 1);
            sub_12F7E6(0, 0, (int16_t *)dword_19283C, (int16_t *)dword_192824);
          }
          ++v28;
        }
        while ( v28 < 4 );
      }
      else if ( v25 <= 8 )
      {
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 80, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 81, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 82, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 83, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 84, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 85, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 86, 0);
        v29 = 0;
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 87, 0);
        do
        {
          v54 = 313 * a3;
          v50 = 2 * v29;
          if ( *(int16_t *)(v50 + v54 + dword_192864 + 41) < 71 )
          {
            sub_12E0B2(dword_19283C, (int16_t *)dword_192824);
            sub_12EFBD(
              0,
              0,
              (_WORD *)dword_19283C,
              (int *)dword_18F4C0[4 * ((int16_t)v56 % 4)
                                + (4
                                 - ((int)((int16_t)v56
                                        - (__CFSHL__((uint64_t)(int16_t)v56 >> 32, 2)
                                         + 4 * ((uint64_t)(int16_t)v56 >> 32))) >> 2)
                                 + v29)
                                % 4],
              1);
            sub_13719F(dword_19283C, 87, 1);
            if ( *(int16_t *)(v50 + v54 + dword_192864 + 41) <= 61 )
              sub_13719F(dword_19283C, 86, 1);
            if ( *(int16_t *)(dword_192864 + 313 * a3 + 2 * v29 + 41) <= 51 )
              sub_13719F(dword_19283C, 85, 1);
            if ( *(int16_t *)(dword_192864 + 313 * a3 + 2 * v29 + 41) <= 41 )
              sub_13719F(dword_19283C, 84, 1);
            if ( *(int16_t *)(dword_192864 + 313 * a3 + 2 * v29 + 41) <= 31 )
              sub_13719F(dword_19283C, 83, 1);
            if ( *(int16_t *)(dword_192864 + 313 * a3 + 2 * v29 + 41) <= 21 )
              sub_13719F(dword_19283C, 82, 1);
            if ( *(int16_t *)(313 * a3 + dword_192864 + 2 * v29 + 41) <= 11 )
              sub_13719F(dword_19283C, 81, 1);
            if ( *(int16_t *)(dword_192864 + 313 * a3 + 2 * v29 + 41) <= 0 )
              sub_13719F(dword_19283C, 80, 1);
            sub_12F7E6(0, 0, (int16_t *)dword_19283C, (int16_t *)dword_192824);
          }
          ++v29;
        }
        while ( v29 < 4 );
      }
      else if ( v25 <= 0xA )
      {
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 80, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 81, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 82, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 83, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 83, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 84, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 84, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 85, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 86, 0);
        v30 = 0;
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 87, 0);
        do
        {
          v48 = 313 * a3;
          v45 = 2 * v30;
          if ( *(int16_t *)(v45 + v48 + dword_192864 + 41) < 91 )
          {
            sub_12E0B2(dword_19283C, (int16_t *)dword_192824);
            sub_12EFBD(
              0,
              0,
              (_WORD *)dword_19283C,
              (int *)dword_18F4C0[4 * ((int16_t)v56 % 4)
                                + (4
                                 - ((int)((int16_t)v56
                                        - (__CFSHL__((uint64_t)(int16_t)v56 >> 32, 2)
                                         + 4 * ((uint64_t)(int16_t)v56 >> 32))) >> 2)
                                 + v30)
                                % 4],
              1);
            sub_13719F(dword_19283C, 87, 1);
            if ( *(int16_t *)(v45 + v48 + dword_192864 + 41) <= 81 )
              sub_13719F(dword_19283C, 86, 1);
            if ( *(int16_t *)(dword_192864 + 313 * a3 + 2 * v30 + 41) <= 71 )
              sub_13719F(dword_19283C, 85, 1);
            if ( *(int16_t *)(313 * a3 + dword_192864 + 2 * v30 + 41) <= 61 )
              sub_13719F(dword_19283C, 84, 1);
            if ( *(int16_t *)(313 * a3 + dword_192864 + 2 * v30 + 41) <= 41 )
              sub_13719F(dword_19283C, 83, 1);
            if ( *(int16_t *)(313 * a3 + dword_192864 + 2 * v30 + 41) <= 21 )
              sub_13719F(dword_19283C, 82, 1);
            if ( *(int16_t *)(313 * a3 + dword_192864 + 2 * v30 + 41) <= 11 )
              sub_13719F(dword_19283C, 81, 1);
            if ( *(int16_t *)(313 * a3 + dword_192864 + 2 * v30 + 41) <= 0 )
              sub_13719F(dword_19283C, 80, 1);
            sub_12F7E6(0, 0, (int16_t *)dword_19283C, (int16_t *)dword_192824);
          }
          ++v30;
        }
        while ( v30 < 4 );
      }
      v49 = 313 * a3;
      sub_12EFBD(0, 0, (_WORD *)dword_192824, (int *)dword_18F4B0[*(uint8_t *)(v49 + dword_192864 + 35) % 4], 0);
      sub_32B26(a3, 1, 0, 0);
      v31 = *(uint8_t *)(v49 + dword_192864 + 35) - 1;
      v32 = (int)(v31 - (__CFSHL__(HIDWORD(v31), 2) + 4 * HIDWORD(v31))) >> 2;
      if ( v32 <= 0 )
        v32 = 0;
      if ( v32 == 1 )
        goto LABEL_134;
      v33 = *(uint8_t *)(dword_192864 + 313 * a3 + 35) - 1;
      v34 = (int)(v33 - (__CFSHL__(HIDWORD(v33), 2) + 4 * HIDWORD(v33))) >> 2;
      if ( v34 <= 0 )
        v34 = 0;
      if ( v34 == 2 )
LABEL_134:
        v35 = 14;
      else
        v35 = 16;
      sub_12F7E6(v35, 11, (int16_t *)dword_19283C, (int16_t *)dword_192824);
    }
    sub_13719F(dword_192824, 1, 0);
    sub_13719F(dword_192824, 2, 0);
    sub_12A478(v39, v38, dword_192824);
    result = 313 * a3;
    if ( *(int16_t *)(dword_192864 + result + 59) <= 0 )
    {
      v44[0] = 72;
      v36 = 1;
      do
      {
        v37 = (int16_t)v36++;
        v44[v37] = 74;
      }
      while ( (int16_t)v36 < 8 );
      sub_120CCB(1, (int)v44);
      sub_58F1E(71, v42, 80);
      return sub_1210FD(v39 + 45, v38 + 70, (int)v42);
    }
  }
  else
  {
    sub_12A478(v39 + 16, v38 + 15, dword_19288C);
    result = dword_192864;
    if ( *(_BYTE *)(dword_192864 + 32) != 8 )
    {
      sub_120BB5(0, (int)&unk_17D879);
      sub_58F1E(0, v42, 80);
      strcpy(v41, v42);
      if ( word_199878 == -1 )
        v8 = 35;
      else
        v8 = *(uint8_t *)((uint8_t*)dword_192B18 + 361 * word_199878 + 10);
      itoa(v8, v43, 10, a4);
      v9 = (char *)v41 - 1;   /* vlna 124: cil je sousedni buffer v41, ne &v40 */
      do
        ++v9;
      while ( *v9 );
      strcpy(v9, v43);
      v10 = (char *)v41 - 1;   /* vlna 124: cil je sousedni buffer v41, ne &v40 */
      do
        ++v10;
      while ( *v10 );
      strcpy(v10, asc_178C4F);
      if ( word_199878 != -1 )
      {
        if ( *(int16_t *)(361 * word_199878 + (uint8_t*)dword_192B18 + 306) > 0 )
        {
          sub_58F1E(1, v42, 80);
          v11 = (char *)v41 - 1;   /* vlna 124: cil je sousedni buffer v41, ne &v40 */
          do
            ++v11;
          while ( *v11 );
          strcpy(v11, v42);
          itoa(*(int16_t *)((uint8_t*)dword_192B18 + 361 * word_199878 + 306), v43, 10, a4);
          v12 = (char *)v41 - 1;   /* vlna 124: cil je sousedni buffer v41, ne &v40 */
          do
            ++v12;
          while ( *v12 );
          strcpy(v12, v43);
          v13 = (char *)v41 - 1;   /* vlna 124: cil je sousedni buffer v41, ne &v40 */
          do
            ++v13;
          while ( *v13 );
          strcpy(v13, asc_178C4F);
        }
        if ( *(int16_t *)(361 * word_199878 + (uint8_t*)dword_192B18 + 304) > 0 )
        {
          sub_58F1E(2, v42, 80);
          v14 = (char *)v41 - 1;   /* vlna 124: cil je sousedni buffer v41, ne &v40 */
          do
            ++v14;
          while ( *v14 );
          strcpy(v14, v42);
          itoa(*(int16_t *)((uint8_t*)dword_192B18 + 361 * word_199878 + 304), v43, 10, a4);
          v15 = (char *)v41 - 1;   /* vlna 124: cil je sousedni buffer v41, ne &v40 */
          do
            ++v15;
          while ( *v15 );
          strcpy(v15, v43);
        }
      }
      v16 = v38 + 4;
      sub_1212B3(v39 + 2, v38 + 72, (int)v41);
      result = word_199878;
      v41[0] = 0;
      if ( word_199878 != -1 )
      {
        if ( *(_BYTE *)((uint8_t*)dword_192B18 + 361 * word_199878 + 336) )
        {
          sub_1212B3(v39 + 2, v16, (int)off_17ED2B);
          v16 = v38 + 11;
        }
        if ( *(_BYTE *)(361 * word_199878 + (uint8_t*)dword_192B18 + 337) )
        {
          v17 = v16;
          v16 += 7;
          sub_1212B3(v39 + 2, v17, (int)off_17ED3E);
        }
        if ( *(_BYTE *)((uint8_t*)dword_192B18 + 361 * word_199878 + 357) )
        {
          v18 = v16;
          v16 += 7;
          sub_1212B3(v39 + 2, v18, (int)off_17EEBA);
        }
        result = 361 * word_199878;
        if ( *(_BYTE *)((uint8_t*)dword_192B18 + result + 352) )
          return sub_1212B3(v39 + 2, v16, (int)off_17EE5B);
      }
    }
  }
  return result;
}
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 17ED2B: using guessed type _UNKNOWN *off_17ED2B;
// 17ED3E: using guessed type _UNKNOWN *off_17ED3E;
// 17EE5B: using guessed type _UNKNOWN *off_17EE5B;
// 17EEBA: using guessed type _UNKNOWN *off_17EEBA;
// 18F4B0: using guessed type int dword_18F4B0[];
// 18F4C0: using guessed type int dword_18F4C0[];
// 192824: using guessed type int dword_192824;
// 19283C: using guessed type int dword_19283C;
// 192864: using guessed type int dword_192864;
// 19288C: using guessed type int dword_19288C;
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 193174: using guessed type int dword_193174;
// 199878: using guessed type int16_t word_199878;


//----- (0002E2CD) --------------------------------------------------------
int sub_2E2CD(int a1, int a2)
{
  int v0; // eax
  int v1; // esi
  int v2; // eax
  int v3; // esi
  int16_t v4; // di
  int result; // eax
  int v6; // ecx
  int16_t v7; // ax
  uint8_t v8; // dl
  int v9; // eax
  int16_t v10; // cx
  int16_t v11; // bx
  int16_t v12; // ax
  uint8_t v13; // dl
  int v14; // edx
  int v15; // eax
  int v16; // eax
  _BYTE *v17; // edx
  uint8_t *v18; // eax
  int v19; // edx
  int v20; // ebx
  int v21; // eax
  char *v22; // esi
  char *v23; // edi
  int v24; // esi
  char *v25; // esi
  char *v26; // edi
  _BYTE *v27; // edx
  int v28; // edx
  int v29; // esi
  char *v30; // edi
  char *v31; // esi
  char *v32; // edi
  char *v33; // edi
  char *v34; // edi
  int v35; // eax
  char *v36; // esi
  char *v37; // edi
  char *v38; // edi
  int16_t v39; // dx
  int16_t v40 = a2;   /* wave 184: 2E2D6 push edx (missile index) */
  int16_t v41 = a1;   /* wave 184: 2E2D5 push eax (ship index) */
  char v42[79]; // [esp+8h] [ebp-46h] BYREF
  char v43; // [esp+57h] [ebp+9h] BYREF
  char v44[52]; // [esp+58h] [ebp+Ah] BYREF
  char v45[20]; // [esp+8Ch] [ebp+3Eh] BYREF
  _BYTE v46[8]; // [esp+A0h] [ebp+52h] BYREF
  _BYTE v47[8]; // [esp+A8h] [ebp+5Ah] BYREF
  _BYTE v48[16]; // [esp+B0h] [ebp+62h] BYREF
  int v49; // [esp+C0h] [ebp+72h]
  int v50; // [esp+C4h] [ebp+76h]
  int v51; // [esp+C8h] [ebp+7Ah]
  uint8_t v52; // [esp+CCh] [ebp+7Eh]

  qmemcpy(v48, "SVVVVVVVPSSSSSSS", sizeof(v48));
  v46[0] = -33;
  v0 = 1;
  do
  {
    v1 = (int16_t)v0++;
    v46[v1] = -36;
  }
  while ( (int16_t)v0 < 8 );
  v47[0] = 72;
  v2 = 1;
  do
  {
    v3 = (int16_t)v2++;
    v47[v3] = 74;
  }
  while ( (int16_t)v2 < 8 );
  v51 = 0;
  v50 = 380;
  sub_128EDE(114, 378, 263, 466, 0, 199);
  do
  {
    v4 = v51;
    result = 11 * (int16_t)v51 + 313 * word_1998F8 + dword_192864;
    v49 = 11 * (int16_t)v51;
    if ( !*(_WORD *)(result + 82) )
      goto LABEL_103;
    v52 = *(_BYTE *)(result + 85);
    if ( (uint16_t)sub_42ABF(word_1998F8) )
      goto LABEL_8;
    if ( sub_4584C(word_1998F8, v4) )
    {
      if ( v40 <= -1 )
      {
        if ( v41 != -1 )
        {
          v12 = sub_32A20(word_1998F8, v41);
          v13 = v52;
          if ( ((uint8_t)sub_32AD1(v12) & v13) != 0 )
          {
            if ( (uint16_t)sub_39F1D(v4, word_1998F8, v41, 0, 0) )
            {
              v9 = v49 + dword_192864 + 313 * word_1998F8;
              v11 = v41;
              v10 = 0;
LABEL_14:
              if ( (uint16_t)sub_389E8(*(_WORD *)(v9 + 82), *(_WORD *)(v9 + 86), v11, v10) )
              {
                v6 = 1;
                goto LABEL_23;
              }
            }
          }
        }
      }
      else
      {
        v7 = sub_329A4(word_1998F8, *(_WORD *)(dword_192B14 + 26 * v40 + 9), *(_WORD *)(dword_192B14 + 26 * v40 + 11));
        v8 = v52;
        if ( ((uint8_t)sub_32AD1(v7) & v8) != 0 && (uint16_t)sub_39F1D(v4, word_1998F8, v40, 1, 0) )
        {
          v9 = v49 + 313 * word_1998F8 + dword_192864;
          v10 = 1;
          v11 = v40;
          goto LABEL_14;
        }
      }
LABEL_8:
      v6 = 0;
      goto LABEL_23;
    }
    if ( *(_BYTE *)(v49 + dword_192864 + 313 * word_1998F8 + 90) )
    {
      v6 = 3;
      if ( g_orion150 )   /* 1.50 02E4FF: sub_1E260F - straight to loc_2E5D2 */
        goto LABEL_2E5D2;
    }
    else
      v6 = 2;
LABEL_23:
    v14 = dword_192864 + 313 * word_1998F8;
    if ( (byte_17F80F[28 * *(int16_t *)(v14 + 11 * (int16_t)v51 + 82)] == 1
       || byte_17F80F[28 * *(int16_t *)(v14 + 11 * (int16_t)v51 + 82)] == 3
       || byte_17F80F[28 * *(int16_t *)(v14 + 11 * (int16_t)v51 + 82)] == 4)
      && !*(_WORD *)(11 * (int16_t)v51 + dword_192864 + 313 * word_1998F8 + 88)
      || (v15 = dword_192864 + 313 * word_1998F8 + 11 * (int16_t)v51, byte_17F80F[28 * *(int16_t *)(v15 + 82)] == 2)
      && *(int16_t *)(v15 + 88) > 0
      || (v16 = dword_192864 + 313 * word_1998F8 + 11 * (int16_t)v51, !*(_BYTE *)(v16 + 91))
      && *(_BYTE *)(v16 + 92) != 1 )
    {
LABEL_31:
      v17 = v46;
LABEL_32:
      sub_120CCB(1, (int)v17);
    }
    else
    {
LABEL_2E5D2:
      switch ( (int16_t)v6 )
      {
        case 0:
          v17 = &v48[8];
          goto LABEL_32;
        case 1:
          v17 = v48;
          goto LABEL_32;
        case 2:
          goto LABEL_31;
        case 3:
          v17 = v47;
          goto LABEL_32;
        default:
          break;
      }
    }
    sub_120DED(0, 0);
    sub_120E8C(1);
    v18 = (uint8_t *)(dword_192864 + 313 * word_1998F8 + 11 * (int16_t)v51);
    if ( v18[91] || v18[92] != 1 )
    {
      v20 = *(uint8_t *)(11 * (int16_t)v51 + dword_192864 + 313 * word_1998F8 + 91);
      v19 = (int16_t)v50;
    }
    else
    {
      v19 = (int16_t)v50;
      v20 = v18[84];
    }
    sub_121153(127, v19, v20, v6);
    v21 = dword_192864 + 313 * word_1998F8 + 11 * (int16_t)v51;
    if ( (*(_BYTE *)(v21 + 86) & 2) != 0 )
    {
      v22 = (char *)off_17FD1E;
      goto LABEL_43;
    }
    if ( (*(_BYTE *)(v21 + 86) & 4) != 0 )
    {
      v22 = (char *)off_17FD2D;
LABEL_43:
      strcpy(v44, v22);
      v23 = (char *)v44 - 1;   /* vlna 124: cil je sousedni buffer v44, ne &v43 */
      do
        ++v23;
      while ( *v23 );
      strcpy(v23, asc_178C52);
      goto LABEL_49;
    }
    v44[0] = 0;
LABEL_49:
    v24 = 11 * (int16_t)v51 + 313 * word_1998F8 + dword_192864;
    if ( *(_BYTE *)(v24 + 91) == 1 )
      v25 = (char *)WEAPON_NAME(0x7803, *(int16_t *)(v24 + 82));
    else
      v25 = (char *)WEAPON_NAME(0x7807, *(int16_t *)(v24 + 82));
    v26 = (char *)v44 - 1;   /* vlna 124: cil je sousedni buffer v44, ne &v43 */
    do
      ++v26;
    while ( *v26 );
    strcpy(v26, v25);
    if ( (_WORD)v6 )
    {
      if ( (uint16_t)v6 <= 1u )
      {
        v27 = v48;
      }
      else
      {
        if ( (_WORD)v6 != 2 )
          goto LABEL_62;
        v27 = v46;
      }
    }
    else
    {
      v27 = &v48[8];
    }
    sub_120CCB(1, (int)v27);
LABEL_62:
    v28 = 11 * (int16_t)v51;
    v29 = v28 + 313 * word_1998F8 + dword_192864;
    if ( byte_17F80F[28 * *(int16_t *)(v29 + 82)] == 1
      || byte_17F80F[28 * *(int16_t *)(v29 + 82)] == 3
      || byte_17F80F[28 * *(int16_t *)(v29 + 82)] == 4
      || *(_WORD *)(v29 + 82) == 33 )
    {
      v30 = (char *)v44 - 1;   /* vlna 124: cil je sousedni buffer v44, ne &v43 */
      do
        ++v30;
      while ( *v30 );
      strcpy(v30, asc_178C54);
      v31 = v45;
      itoa(*(int16_t *)(11 * (int16_t)v51 + dword_192864 + 313 * word_1998F8 + 88), v45, 10, v6);
      goto LABEL_99;
    }
    if ( byte_17F80F[28 * *(int16_t *)(v29 + 82)] != 2 )
    {
      if ( byte_17F80F[28 * *(int16_t *)(v29 + 82)] )
        goto LABEL_102;
      v34 = (char *)v44 - 1;   /* vlna 124: cil je sousedni buffer v44, ne &v43 */
      do
        ++v34;
      while ( *v34 );
      strcpy(v34, asc_178C57);
      if ( v52 < 4u )
      {
        if ( v52 )
        {
          if ( v52 <= 1u )
          {
            v35 = 3;
          }
          else
          {
            if ( v52 != 2 )
              goto LABEL_98;
            v35 = 4;
          }
          goto LABEL_90;
        }
      }
      else
      {
        if ( v52 <= 4u )
        {
          v35 = 6;
          goto LABEL_90;
        }
        if ( v52 >= 8u )
        {
          if ( v52 > 8u )
          {
            if ( v52 != 15 )
              goto LABEL_98;
            v36 = a360;
LABEL_95:
            v37 = (char *)v44 - 1;   /* vlna 124: cil je sousedni buffer v44, ne &v43 */
            do
              ++v37;
            while ( *v37 );
            strcpy(v37, v36);
            goto LABEL_98;
          }
          v35 = 5;
LABEL_90:
          v36 = v42;
          sub_58F1E(v35, v42, 80);
          goto LABEL_95;
        }
      }
LABEL_98:
      v31 = asc_178C5E;
LABEL_99:
      v38 = (char *)v44 - 1;   /* vlna 124: cil je sousedni buffer v44, ne &v43 */
      do
        ++v38;
      while ( *v38 );
      strcpy(v38, v31);
      goto LABEL_102;
    }
    if ( *(int16_t *)(v29 + 88) > 0 )
    {
      v32 = (char *)v44 - 1;   /* vlna 124: cil je sousedni buffer v44, ne &v43 */
      do
        ++v32;
      while ( *v32 );
      strcpy(v32, asc_178C52);
      itoa(*(int16_t *)(v28 + dword_192864 + 313 * word_1998F8 + 88), v45, 10, v6);
      v33 = (char *)v44 - 1;   /* vlna 124: cil je sousedni buffer v44, ne &v43 */
      do
        ++v33;
      while ( *v33 );
      strcpy(v33, v45);
      v31 = v42;
      sub_58F1E(85, v42, 80);
      goto LABEL_99;
    }
LABEL_102:
    sub_120DED(0, 0);
    v39 = v50;
    sub_120E8C(1);
    result = sub_1212B3(131, v39, (int)v44);
LABEL_103:
    ++v51;
    v50 += 11;
  }
  while ( (int16_t)v51 < 8 );
  return result;
}
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 17F803: using guessed type _UNKNOWN *off_17F803;
// 17F807: using guessed type _UNKNOWN *off_17F807;
// 17FD1E: using guessed type _UNKNOWN *off_17FD1E;
// 17FD2D: using guessed type _UNKNOWN *off_17FD2D;
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (0002E98D) --------------------------------------------------------
void sub_2E98D()
{
  int v0; // ecx
  int v1; // ebx
  int v2; // ecx
  int v3; // ebx
  int v4; // edi
  int16_t v5; // si
  int16_t v6; // cx
  _BYTE *v7; // edx
  int16_t v8; // dx
  char v9[80]; // [esp+0h] [ebp-68h] BYREF
  _BYTE v10[8]; // [esp+50h] [ebp-18h] BYREF
  _BYTE v11[8]; // [esp+58h] [ebp-10h] BYREF
  _BYTE v12[8]; // [esp+60h] [ebp-8h] BYREF

  qmemcpy(v12, "PSSSSSSS", sizeof(v12));
  v10[0] = 72;
  v0 = 1;
  do
  {
    v1 = (int16_t)v0++;
    v10[v1] = 74;
  }
  while ( (int16_t)v0 < 8 );
  v11[0] = -33;
  v2 = 1;
  do
  {
    v3 = (int16_t)v2++;
    v11[v3] = -36;
  }
  while ( (int16_t)v2 < 7 );
  v4 = 380;
  v5 = 0;
  sub_128EDE(114, 378, 263, 466, 0, 199);
  v6 = 0;
  while ( 1 )
  {
    if ( (uint16_t)sub_1276F0(dword_192864 + 313 * word_1998F8 + 76, v6) )
    {
      if ( (uint16_t)sub_1276F0(dword_192864 + 313 * word_1998F8 + 178, v6) )
      {
        v7 = v10;
      }
      else if ( sub_3AFE5(word_1998F8, v5) )
      {
        v7 = v12;
      }
      else
      {
        v7 = v11;
      }
      sub_120CCB(1, (int)v7);
      sub_120DED(0, 0);
      ++v5;
      sub_120E8C(1);
      v8 = v4;
      v4 += 11;
      sub_1212B3(123, v8, *(int *)((char *)&off_17EEE0 + 47 * v6));
    }
    if ( ++v6 >= 39 )
    {
      if ( !v5 )
      {
        sub_120CCB(2, (int)&unk_17D879);
        sub_120DED(0, 0);
        sub_58F1E(7, v9, 80);
        sub_1210FD(187, 418, (int)v9);
      }
      return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x33AFE je epilog funkce */
    }
  }
}
// 17EEE0: using guessed type _UNKNOWN *off_17EEE0;
// 192864: using guessed type int dword_192864;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (0002EB0F) --------------------------------------------------------
char sub_2EB0F( int a1, int a2, int a3, int a4)
{
  char v5; // bl

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  v5 = a4 + a3 + 9;
  sub_12972D(a1, a2, v5);
  sub_12972D(a1 + 1, a2, a4 + a3 + 6);
  sub_12972D(a1, a2 + 1, a4 + a3 + 6);
  return sub_12972D(a1 + 1, a2 + 1, a3 + 4 + a4);
}


//----- (0002EB82) --------------------------------------------------------
void sub_2EB82( int a1, int a2, int a3, int a4)
{
  char v5; // cl

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  sub_12972D(a1, a2, a4 + a3 + 9);
  sub_12972D(a1 + 1, a2, a4 + a3 + 6);
  v5 = a4 + a3 + 4;
  sub_12972D(a1 + 2, a2, a4 + a3 + 4);
  sub_12972D(a1, a2 + 1, a4 + a3 + 6);
  sub_12972D(a1 + 1, a2 + 1, a4 + a3 + 6);
  sub_12972D(a1 + 2, a2 + 1, v5);
  sub_12972D(a1, a2 + 2, v5);
  sub_12972D(a1 + 1, a2 + 2, v5);
  sub_12972D(a1 + 2, a2 + 2, a4 + a3 + 1);   /* wave 184: 2EC50 jmp 2EB79 - the shared last call */
}


//----- (0002EC55) --------------------------------------------------------
void sub_2EC55( int a1, int a2, int a3, int a4)
{
  char v5; // cl
  char v8; // [esp+18h] [ebp-Ch]

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  v8 = a4 + a3 + 1;
  sub_12972D(a1, a2, v8);
  v5 = a4 + a3 + 4;
  sub_12972D(a1 + 1, a2, v5);
  sub_12972D(a1 + 2, a2, v5);
  sub_12972D(a1 + 3, a2, v8);
  sub_12972D(a1, a2 + 1, v5);
  sub_12972D(a1 + 1, a2 + 1, a4 + a3 + 9);
  sub_12972D(a1 + 2, a2 + 1, a4 + a3 + 6);
  sub_12972D(a1 + 3, a2 + 1, v5);
  sub_12972D(a1, a2 + 2, v5);
  sub_12972D(a1 + 1, a2 + 2, a4 + a3 + 6);
  sub_12972D(a1 + 2, a2 + 2, a4 + a3 + 6);
  sub_12972D(a1 + 3, a2 + 2, v5);
  sub_12972D(a1, a2 + 3, v8);
  sub_12972D(a1 + 1, a2 + 3, v5);
  sub_12972D(a1 + 2, a2 + 3, v5);
  sub_12972D(a1 + 3, a2 + 3, v8);   /* wave 184: 2ED83 jmp 2EB79 */
}


//----- (0002ED88) --------------------------------------------------------
void sub_2ED88( int a1, int a2, int a3, int a4)
{
  int16_t v4; // di
  char v5; // bl
  int16_t v6; // cx
  char v7; // si
  int16_t v8; // [esp+0h] [ebp-28h]
  int16_t v9; // [esp+4h] [ebp-24h]
  int16_t v10; // [esp+8h] [ebp-20h]
  int16_t v11; // [esp+10h] [ebp-18h]

  v4 = a1;
  v5 = a4 + a3 + 2;
  v6 = a1;
  sub_12972D(a1, a2, v5);
  v10 = v6;
  LOBYTE(v6) = a4 + a3 + 4;
  v9 = v4 + 1;
  sub_12972D(v4 + 1, a2, v6);
  v8 = v4 + 2;
  sub_12972D(v4 + 2, a2, v6);
  v11 = v4 + 3;
  sub_12972D(v4 + 3, a2, v6);
  v4 += 4;
  sub_12972D(v4, a2, a4 + a3 + 1);
  sub_12972D(v10, a2 + 1, v6);
  sub_12972D(v9, a2 + 1, a4 + a3 + 9);
  sub_12972D(v8, a2 + 1, a4 + a3 + 9);
  v7 = a4 + a3 + 6;
  sub_12972D(v11, a2 + 1, v7);
  sub_12972D(v4, a2 + 1, v6);
  sub_12972D(v10, a2 + 2, v6);
  sub_12972D(v9, a2 + 2, a4 + a3 + 9);
  sub_12972D(v8, a2 + 2, v7);
  sub_12972D(v11, a2 + 2, v7);
  sub_12972D(v4, a2 + 2, v6);
  sub_12972D(v10, a2 + 3, v6);
  sub_12972D(v9, a2 + 3, v7);
  sub_12972D(v8, a2 + 3, v7);
  sub_12972D(v11, a2 + 3, v7);
  sub_12972D(v4, a2 + 3, v6);
  sub_12972D(v10, a2 + 4, a4 + a3 + 1);
  sub_12972D(v9, a2 + 4, v6);
  sub_12972D(v8, a2 + 4, v6);
  sub_12972D(v11, a2 + 4, v6);
  sub_12972D(v4, a2 + 4, a4 + a3 + 1);   /* wave 184: 2EF4C jmp 2EB79 */
}


//----- (0002EF51) --------------------------------------------------------
int sub_2EF51()
{
  int v0; // esi
  int v1; // esi
  int v2; // esi
  int v3; // esi
  int v4; // eax

  v0 = (int16_t)(3 * word_1998F2 / 2 + 363);
  sub_134D2D((int16_t)(3 * word_1998F0 / 2 + 499), v0, (int16_t)(3 * word_1998F0 / 2 + 506), v0, 138);
  sub_134D2D(
    (int16_t)(3 * word_1998F0 / 2 + 499),
    (int16_t)(3 * word_1998F2 / 2 + 363),
    (int16_t)(3 * word_1998F0 / 2 + 499),
    (int16_t)(3 * word_1998F2 / 2 + 370),
    138);
  v1 = (int16_t)(3 * word_1998F2 / 2 + 392);
  sub_134D2D((int16_t)(3 * word_1998F0 / 2 + 499), v1, (int16_t)(3 * word_1998F0 / 2 + 506), v1, 138);
  sub_134D2D(
    (int16_t)(3 * word_1998F0 / 2 + 499),
    (int16_t)(3 * word_1998F2 / 2 + 392),
    (int16_t)(3 * word_1998F0 / 2 + 499),
    (int16_t)(3 * word_1998F2 / 2 + 385),
    138);
  v2 = (int16_t)(3 * word_1998F2 / 2 + 363);
  sub_134D2D((int16_t)(3 * word_1998F0 / 2 + 549), v2, (int16_t)(3 * word_1998F0 / 2 + 542), v2, 138);
  sub_134D2D(
    (int16_t)(3 * word_1998F0 / 2 + 549),
    (int16_t)(3 * word_1998F2 / 2 + 363),
    (int16_t)(3 * word_1998F0 / 2 + 549),
    (int16_t)(3 * word_1998F2 / 2 + 370),
    138);
  v3 = (int16_t)(3 * word_1998F2 / 2 + 392);
  sub_134D2D((int16_t)(3 * word_1998F0 / 2 + 549), v3, (int16_t)(3 * word_1998F0 / 2 + 542), v3, 138);
  v4 = (int16_t)(3 * word_1998F0 / 2 + 549);
  return sub_134D2D(v4, (int16_t)(3 * word_1998F2 / 2 + 392), v4, (int16_t)(3 * word_1998F2 / 2 + 385), 138);
}
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;


//----- (0002F172) --------------------------------------------------------
void sub_2F172()
{
  int v0; // ecx
  int v1; // edx
  uint8_t v2; // al
  int16_t i; // si
  int v4; // ebx
  char v5; // cl
  uint8_t *v6; // ebx
  int v7; // edi
  int v8; // edx
  uint8_t v9; // al
  int16_t v10; // cx
  int16_t *v11; // ebx

  if ( word_199878 != -1 )
  {
    v0 = 3 * *(uint8_t *)(dword_192864 + 34) / 2 + 364;
    v1 = 3 * *(uint8_t *)(dword_192864 + 33) / 2 + 500;
    v2 = *(_BYTE *)(17 * *(int16_t *)((uint8_t*)dword_192B18 + 361 * word_199878 + 2) + (uint8_t*)dword_1930D4 + 5);
    if ( v2 )
    {
      if ( v2 <= 4u )
        sub_12A478(v1 - (7 - v2), v0 - (7 - v2), dword_1928A4);
    }
    else
    {
      sub_2EC55(v1, v0, 96, 0);
    }
  }
  for ( i = 1; i < word_1998C0; ++i )
  {
    v4 = 313 * i;
    if ( !*(_BYTE *)(v4 + dword_192864 + 36) )
    {
      if ( *(uint8_t *)(v4 + dword_192864 + 32) == word_1998AC )
        v5 = 32;
      else
        v5 = 96;
      v6 = (uint8_t *)(dword_192864 + 313 * i);
      v7 = 3 * v6[34] / 2 + 364;
      v8 = 3 * v6[33] / 2 + 500;
      v9 = v6[37];
      if ( v9 )
      {
        if ( v9 <= 2u )
        {
          sub_2EB82(v8, v7, v5, 0);
        }
        else if ( v9 <= 3u )
        {
          sub_2EC55(v8, v7, v5, 0);
        }
        else if ( v9 <= 5u )
        {
          sub_2ED88(v8, v7, v5, 0);
        }
      }
      else
      {
        sub_2EB0F(v8, v7, v5, 0);
      }
    }
  }
  v10 = 0;
  while ( 1 )
  {
    v11 = (int16_t *)(26 * v10 + dword_192B14);
    if ( *v11 > 0 )
      sub_12972D(
        3 * (*(int16_t *)((char *)v11 + 9) / 20) / 2 + 500,
        3 * (*(int16_t *)((char *)v11 + 11) / 20) / 2 + 364,
        28);
    if ( ++v10 >= 300 )
      return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x33AFE je epilog funkce */
  }
}
// 192864: using guessed type int dword_192864;
// 1928A4: using guessed type int dword_1928A4;
// 192B14: using guessed type int dword_192B14;
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 1930D4: using guessed type int (uint8_t*)dword_1930D4;
// 199878: using guessed type int16_t word_199878;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0002F382) --------------------------------------------------------
int sub_2F382()
{
  sub_12B753(dword_19282C, word_1998C4);
  sub_12A478(267, 386, dword_19282C);
  sub_12B753(dword_19282C, word_19987E);
  sub_12A478(267, 402, dword_19282C);
  sub_12B753(dword_19282C, word_1998EE);
  sub_12A478(267, 418, dword_19282C);
  sub_12B753(dword_19282C, word_1998CC);
  sub_12A478(267, 434, dword_19282C);
  sub_12B753(dword_19282C, word_1998E4);
  return sub_12A478(267, 450, dword_19282C);
}
// 19282C: using guessed type int dword_19282C;
// 19987E: using guessed type int16_t word_19987E;
// 1998C4: using guessed type int16_t word_1998C4;
// 1998CC: using guessed type int16_t word_1998CC;
// 1998E4: using guessed type int16_t word_1998E4;
// 1998EE: using guessed type int16_t word_1998EE;


//----- (0002F445) --------------------------------------------------------
int sub_2F445( int a1, int a2, int a3)
{
  int result; // eax
  char v5[80]; // [esp+0h] [ebp-58h] BYREF
  int v6; // [esp+50h] [ebp-8h]
  int v7; // [esp+54h] [ebp-4h]

  v7 = a2;
  if ( a1 )
  {
    v6 = 0;
    while ( *(uint8_t *)(313 * a1 + dword_192864 + 172) > (int16_t)v6 )
    {
      ++v6;
      sub_12A478(v7, a3, dword_1928A8);
      v7 += 11;
    }
  }
  sub_120BB5(2, (int)&unk_17D879);
  result = *(int16_t *)(dword_192864 + 313 * a1 + 173);
  if ( result > -1 )
  {
    sub_58F1E(86, v5, 80);
    return sub_1210B7(a2 + 87, a3 + 2, (int)v5);
  }
  return result;
}
// 192864: using guessed type int dword_192864;
// 1928A8: using guessed type int dword_1928A8;


//----- (0002F4EE) --------------------------------------------------------
/* wave 184: written from asm 2F4EE-3004D (Hex-Rays failed) - combat screen redraw */
int sub_2F4EE(void)
{
  static const int16_t v_tbl[4] = { 0, 2, 5, 2 };   /* 2C54D off_2C54D */
  char v4;           // [ebp-4]
  int16_t v8;        // [ebp-8] mouse x
  int16_t v14;       // [ebp-14h] mouse y
  int v18;           // [ebp-18h]
  int16_t vC;        // [ebp-0Ch]
  int v24;           // [ebp-24h]
  int16_t v10;       // [ebp-10h]
  int v20;           // [ebp-20h]
  char v4C[32];      // [ebp-4Ch]
  int16_t v_di;      // di
  int16_t v_si;      // si
  int16_t v_cx;      // cx
  int16_t v_bx;      // bx
  int16_t v_x;       // di
  int16_t v_y;       // si
  int v_off, v_w, v_k, v_n, i, result;
  uint8_t v_b;
  uint8_t *v_s;
  char *v_from, *v_to;

  if ( ++word_19987C > 18 )   /* 2F4F7 */
    word_19987C = 15;
  v4 = sub_124AA2();
  word_199902 = word_199900;
  if ( !word_1998F6 || word_1998E0 )
    return (uint16_t)word_199900;   /* 2F52D jz locret_33AFE */
  v8 = sub_123ABA();
  v14 = sub_123AE7();
  v18 = sub_124039();
  v_di = (int16_t)(intptr_t)sub_114177();
  if ( v_di > 0 && v_di <= word_1998FA )
  {
    v_si = 0;
    for ( v_cx = 0; v_cx < 300 && v_si < word_1998FA; ++v_cx )   /* 2F57C */
    {
      v_s = (uint8_t *)(intptr_t)(dword_192B14 + 26 * v_cx);
      if ( *(int16_t *)v_s > 0
        && sub_3D259((int16_t)((*(int16_t *)(v_s + 9) - 8) / 20), (int16_t)((*(int16_t *)(v_s + 11) - 8) / 20)) )
      {
        if ( ++v_si == v_di )
        {
          v_di = v_cx;   /* 2F5C7 mov edi, ecx */
          break;
        }
      }
    }
  }
  else
  {
    v_di = -1000;   /* 2F5DE */
  }
  if ( word_1998F8 < 0 )
    goto LABEL_2FAD8;
  if ( v8 / 20 >= 32 || v14 / 20 >= 18 )
    goto LABEL_2FA13;
  sub_128AB6(0, 0, 639, 350);
  sub_12B634();
  v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * word_1998F8);
  v_off = !v_s[37] ? 0 : (v_s[37] > 2 ? 20 : 10);   /* 2F642 */
  v_cx = (int16_t)((v8 + 12 - v_off) / 20);
  v_bx = (int16_t)((v14 + 12 - v_off) / 20);
  if ( word_18C9A8[68 * (word_1998F0 + v_cx) + word_1998F2 + v_bx] == 2000
    && !word_1998D4
    && (byte_199F3A == 1 || (int16_t)v_s[32] == word_19999C)
    && word_199876 == 1 )
  {
    v_b = v_s[37];   /* 2F71F */
    v_w = !v_b ? 20 : (v_b <= 2 ? 40 : (v_b <= 5 ? 60 : 0));
    if ( v_w )
      sub_1297C3((int16_t)(20 * v_cx), (int16_t)(20 * v_bx), v_w, v_w, 1, 177);
  }
  sub_12B65C();   /* 2F770 */
  sub_128BE7();
  v_x = v8 + (int16_t)sub_123FFB();
  v_y = v14 + (int16_t)sub_123FFB();
  vC = word_18C9A8[68 * (v_x / 20 + word_1998F0) + v_y / 20 + word_1998F2];
  if ( word_1998D6 )
  {
    sub_2E98D();   /* 2FA09 */
    goto LABEL_2FAA7;
  }
  if ( v_di > -1 )
  {
    sub_2E2CD(-1, v_di);
    sub_128EDE(401, 362, 489, 374, 0, 199);
    sub_120CCB(1, (int)&unk_17D879);
    sub_120DED(0, 0);
    sub_102F4F(445, 365, (int)(intptr_t)WEAPON_NAME(0x7803, *(int16_t *)(intptr_t)(dword_192B14 + 26 * v_di)), 89);
    sub_3C539(401, 379, v_di, 89);
    word_1998F4 = -1;
    goto LABEL_2FAA7;
  }
  if ( (int16_t)v18 == 12 || (int16_t)v18 == 1 )   /* 2F869 */
  {
    v24 = vC;
    if ( v24 != -1 && vC < word_1998C0 )
      goto LABEL_2F916;
  }
  if ( word_1998F4 == 666 )   /* 2F893 */
    goto LABEL_2FAA7;
  sub_124D7A();
  sub_2E2CD(-1, -1);
LABEL_2F8B3:
  sub_128EDE(401, 362, 489, 374, 0, 199);
  sub_128EDE(401, 379, 488, 467, 0, 199);
  sub_3459E(401, 379);
  if ( v4 == 1 )
    sub_124D41();
  goto LABEL_2FA9E;
LABEL_2F916:
  sub_2E2CD(v24, v_di);
  if ( word_1998F4 == vC )
    goto LABEL_2FAA7;
  v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * v24);
  sub_124D7A();
  if ( v_s[36] )
    goto LABEL_2F8B3;   /* 2F9FF */
  sub_120CCB(2, (int)&unk_17D879);
  sub_120DED(0, 0);
  sub_128EDE(401, 362, 489, 374, 0, 199);
  v_from = (char *)v_s;   /* 2F99D lodsb / stosb - ship name */
  v_to = v4C;
  while ( (*v_to++ = *v_from++) != 0 )
    ;
  sub_102F4F(445, 362, (int)(intptr_t)v4C, 89);
  sub_2D1ED(400, 376, v24, 89);
  sub_2CBCC(400, 376, v24);
  sub_2F445(v24, 401, 379);
  if ( v4 == 1 )
    sub_124D41();
  word_1998F4 = vC;
  goto LABEL_2FAA7;
LABEL_2FA13:
  if ( word_1998F4 == 666 )
    goto LABEL_2FAA7;
  sub_124D7A();
  if ( word_1998D6 )
    sub_2E98D();
  else
    sub_2E2CD(-1, -1);
  sub_128EDE(401, 362, 489, 374, 0, 199);
  sub_128EDE(401, 379, 488, 467, 0, 199);
  sub_3459E(401, 379);
  if ( v4 == 1 )
    sub_124D41();
LABEL_2FA9E:
  word_1998F4 = 666;
LABEL_2FAA7:
  if ( word_1998CC == 1 )
  {
    sub_128AB6(0, 0, 639, 350);
    sub_12B634();
    sub_32243();
    sub_12B65C();
    sub_128BE7();
  }
LABEL_2FAD8:
  sub_128AB6(0, 0, 639, 350);
  sub_12B634();
  for ( i = 0; (int16_t)i < word_1998C0; ++i )   /* 2FAF4 */
  {
    v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * (int16_t)i);
    if ( !v_s[36] && (int16_t)i != word_1998FC && (int16_t)sub_33B19((int16_t)i) )
      sub_30062(
        (int16_t)i,
        (int16_t)(20 * (int16_t)(v_s[33] - word_1998F0)),
        (int16_t)(20 * (int16_t)(v_s[34] - word_1998F2)),
        i);
  }
  if ( word_1998F8 != word_1998FC && word_1998F8 )   /* 2FB5A */
  {
    v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * word_1998F8);
    if ( !v_s[36]
      && !(int16_t)sub_42ABF(word_1998F8)
      && ((int16_t)v_s[32] == word_19999C || byte_199F3A == 1) )
    {
      v_n = (int16_t)((word_19987A / 2) % 4);   /* 2FBCB */
      v_b = v_s[37];
      v_x = (int16_t)(20 * (int16_t)(v_s[33] - word_1998F0));
      v_y = (int16_t)(20 * (int16_t)(v_s[34] - word_1998F2));
      v_k = -1;
      if ( !v_b )
      {
        v_k = 0;
        v_x -= 3;
        v_y -= 3;
      }
      else if ( v_b <= 2 )
      {
        v_k = 1;
        v_x -= 5;
        v_y -= 4;
      }
      else if ( v_b <= 5 )
      {
        v_k = 2;
        v_x -= 8;
        v_y -= 8;
      }
      if ( v_k >= 0 )
      {
        /* 18A91C / 18A920 / 18A924: three dwords in a row */
        sub_12B753(dword_19291C[v_k], v_n);
        sub_12A478(v_x, v_y, dword_19291C[v_k]);
      }
    }
  }
  sub_3C834();   /* 2FD07 */
  sub_12B65C();
  sub_128BE7();
  sub_120CCB(2, (int)&unk_17D879);
  sub_120DED(0, 0);
  v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * word_1998F8);
  if ( word_1998DA > 0
    && v_s[32] < 8u
    && *(uint8_t *)(intptr_t)(dword_197F98 + 3753 * v_s[32] + 40) == 100 )
  {
    if ( word_1998DA != 1 )
    {
      sub_2F172();   /* 2FDD8 */
      goto LABEL_2FFDB;
    }
    v_n = *(int16_t *)(intptr_t)(dword_192884 + 4);
    sub_12B726(dword_192884);
    for ( v_cx = 0; v_cx < v_n; ++v_cx )
      sub_12A478(500, 363, dword_192884);
    sub_12A478(500, 363, dword_192884);
    result = sub_12A478(529, 407, dword_192850);
    goto LABEL_2FFE0;
  }
  v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * word_1998F8);   /* 2FDE2 */
  v_y = (int16_t)(3 * v_s[34] / 2 + 364);
  v_x = (int16_t)(3 * v_s[33] / 2 + 500);
  v_cx = v_tbl[(word_19987A / 2) % 4];
  if ( word_1998F8 )
  {
    v_w = (int16_t)v_s[32] == word_1998AC ? 32 : 96;
    v_b = v_s[37];
    if ( !v_b )
      sub_2EB0F(v_x, v_y, v_w, v_cx);
    else if ( v_b <= 2 )
      sub_2EB82(v_x, v_y, v_w, v_cx);
    else if ( v_b <= 3 )
      sub_2EC55(v_x, v_y, v_w, v_cx);
    else if ( v_b <= 5 )
      sub_2ED88(v_x, v_y, v_w, v_cx);
  }
  else
  {
    v_b = *(uint8_t *)(intptr_t)(dword_1930D4 + 17 * *(int16_t *)(intptr_t)(dword_192B18 + 361 * word_199878 + 2) + 5);
    if ( !v_b )
    {
      sub_2EC55(v_x, v_y, 96, v_cx);   /* 2FF2B */
    }
    else if ( v_b <= 4 )
    {
      sub_1112EC(dword_192ED4, 400);   /* 2FF35 */
      v10 = 96;
      v20 = (int)(intptr_t)sub_110D3C((PoolMemType *)(intptr_t)dword_192ED4, 400);
      sub_12F578(v20, dword_1928A4);
      while ( v10 < 112 )   /* 2FF86 */
      {
        v_w = v10 - v_cx;
        if ( v_w <= 96 )
          v_w = 96;
        sub_13719F(v20, v10++, (int16_t)v_w);
      }
      v_b = *(uint8_t *)(intptr_t)(dword_1930D4 + 17 * *(int16_t *)(intptr_t)(dword_192B18 + 361 * word_199878 + 2) + 5);
      v_y -= 7 - v_b;
      v_x -= 7 - v_b;
      sub_12A478(v_x, v_y, v20);
      sub_1113CC(dword_192ED4, v_y);
    }
  }
LABEL_2FFDB:
  result = sub_2EF51();
LABEL_2FFE0:
  if ( ++word_19987A == 32000 )
    word_19987A = 0;
  if ( !word_199876 )
  {
    sub_34921();
    dword_19284C = sub_127C27((int)aCombatLbx_0, 9, dword_193174);
    sub_12A478(248, 298, dword_19284C);
    result = sub_2F382();
  }
  if ( word_199900 == 1 )
    result = Hook150_1E3E95();   /* 1.50 030048 */
  return result;
}


//----- (00030062) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
/* wave 184: the frame above the moved ebp (Hex-Rays made it arguments a5..a23) */
#pragma pack(push, 1)
typedef struct {
  int a5;
  int a6;
  int a7;
  int a8;
  int a9;
  int a10;
  int a11;
  int a12;
  int a13;
  int a14;
  int a15;
  hr_int128_t a16;
  int a17;
  int a18;
  int a19;
  int a20;
  int64_t a21;
  int64_t a22;
  int64_t a23;
} frame30062_t;
#pragma pack(pop)
void sub_30062(int a1, int a2, int a3, int a4)
{
  int v23; // ebx
  int v24; // eax
  int v25; // eax
  int v26; // et2
  int v27; // esi
  int v28; // eax
  int v29; // esi
  int v30; // edx
  char v31; // cl
  char v32; // ch
  int v33; // eax
  int v34; // ebx
  int v35; // edx
  int v36; // eax
  int v37; // esi
  int16_t v38; // bx
  char *v39; // edx
  int v40; // eax
  int v41; // eax
  int v42; // edx
  int v43; // eax
  int v44; // edx
  int16_t v45; // bx
  int v46; // edx
  int v47; // edx
  int v48; // edx
  int var2; // [esp+76h] [ebp-2h] BYREF
  int vars2; // [esp+7Ah] [ebp+2h] BYREF
  int16_t vars6; // [esp+7Eh] [ebp+6h]
  _BYTE varsA[6]; // [esp+82h] [ebp+Ah] BYREF

  frame30062_t frm30062;
  memset(&frm30062, 0, sizeof(frm30062));
#define a5 (frm30062.a5)
#define a6 (frm30062.a6)
#define a7 (frm30062.a7)
#define a8 (frm30062.a8)
#define a9 (frm30062.a9)
#define a10 (frm30062.a10)
#define a11 (frm30062.a11)
#define a12 (frm30062.a12)
#define a13 (frm30062.a13)
#define a14 (frm30062.a14)
#define a15 (frm30062.a15)
#define a16 (frm30062.a16)
#define a17 (frm30062.a17)
#define a18 (frm30062.a18)
#define a19 (frm30062.a19)
#define a20 (frm30062.a20)
#define a21 (frm30062.a21)
#define a22 (frm30062.a22)
#define a23 (frm30062.a23)
  vars6 = a1;   /* wave 184: push eax in the prologue */
  vars2 = a2;   /* wave 184: push edx in the prologue */
  var2 = a3;   /* wave 184: push ebx in the prologue */
  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v23 = a1;
  v24 = 313 * a1;
  *(_DWORD *)((char *)&a23 + 2) = 0;
  *(_DWORD *)((char *)&a23 + 6) = 0;
  LOWORD(v24) = *(uint8_t *)(dword_192864 + v24 + 312);
  HIWORD(a17) = 1;
  a18 = 196610;
  LOWORD(a19) = 2;
  *(_DWORD *)((char *)&a21 + 2) = v24;
  if ( (int16_t)v24 <= 9 )
  {
    v25 = v23 + word_19987A / 2;
    v26 = v25 % 4;
    HIWORD(v25) = (unsigned int)(v25 / 4) >> 16;
    LOWORD(v25) = *((_WORD *)&a17 + v26 + 1);
    *(_DWORD *)((char *)&a22 + 2) = 4;
    *(_DWORD *)((char *)&a21 + 6) = v25;
  }
  else
  {
    *(_DWORD *)((char *)&a22 + 2) = 4;
    *(_DWORD *)((char *)&a21 + 6) = word_19987A / 2 % 4;
  }
  v27 = 313 * vars6;
  sub_34454(vars6, (_WORD *)&a20 + 1, (_WORD *)&a19 + 1);
  if ( vars6 )
  {
    HIWORD(v28) = HIWORD(dword_192864);
    v29 = dword_192864 + v27;
    LOWORD(v28) = *(uint8_t *)(v29 + 35);
    *(_DWORD *)((char *)&a22 + 6) = v28;
    if ( *(_DWORD *)(v29 + 198) && *(_BYTE *)(v29 + 32) == *(_BYTE *)(v29 + 312) )
    {
      v37 = *(_DWORD *)(v29 + 198);
    }
    else
    {
      v30 = 0;
      v31 = 96;
      v32 = 32;
      do
      {
        varsA[(int16_t)v30] = v32;
        *((_BYTE *)&a8 + (int16_t)v30++ + 2) = v31++;
        ++v32;
      }
      while ( (int16_t)v30 < 32 );
      if ( SWORD1(a21) >= 8 || (v33 = 313 * vars6 + dword_192864, *(_WORD *)(v33 + 196) == 44) )
      {
        v36 = dword_192864 + 313 * vars6;
        strcpy((char *)&a16 + 2, "monster.lbx");
        if ( *(_WORD *)(v36 + 196) == 44 )
        {
          v35 = 25;
          v34 = dword_193174;
        }
        else
        {
          v34 = dword_193174;
          v35 = *(int16_t *)(v36 + 196);
        }
      }
      else
      {
        strcpy((char *)&a16 + 2, "cmbtshp.lbx");
        v34 = dword_193174;
        v35 = *(int16_t *)(v33 + 196) + 45 * *(uint8_t *)((uint8_t*)dword_197F98 + 3753 * SWORD1(a21) + 38);
      }
      v37 = sub_127C27((int)&a16 + 2, v35, v34);
      a2 = 32;
      if ( *(uint8_t *)(dword_192864 + 313 * vars6 + 32) == word_1998AC )
      {
        v38 = 96;
        v39 = varsA;
        v40 = v37;
      }
      else
      {
        v39 = (char *)&a8 + 2;
        v40 = v37;
        v38 = 32;
      }
      sub_137D86(v40, (int)v39, v38, 32);
    }
    v41 = (SHIWORD(a22) - 1 - (__CFSHL__((SHIWORD(a22) - 1) >> 31, 2) + 4 * ((SHIWORD(a22) - 1) >> 31))) >> 2;
    if ( v41 <= 0 )
      v41 = 0;
    switch ( v41 )
    {
      case 0:
        if ( (uint16_t)sub_3883A(vars6) || *(_BYTE *)(dword_192864 + 313 * vars6 + 176) )
          v42 = SHIWORD(a22) * SWORD1(a22);
        else
          v42 = SHIWORD(a21) + SWORD1(a22) * SHIWORD(a22);
        sub_12B753(v37, v42);
        sub_12F578(dword_19283C, v37);
        break;
      case 1:
        if ( (uint16_t)sub_3883A(vars6) || *(_BYTE *)(313 * vars6 + dword_192864 + 176) )
          v44 = SWORD1(a22) * (8 - SHIWORD(a22));
        else
          v44 = SWORD1(a22) * (8 - SHIWORD(a22)) + SHIWORD(a21);
        sub_12B753(v37, v44);
        sub_12F578(dword_192840, v37);
        v45 = 0;
        goto LABEL_38;
      case 2:
        if ( (uint16_t)sub_3883A(vars6) || *(_BYTE *)(dword_192864 + 313 * vars6 + 176) )
          v46 = (SHIWORD(a22) - 8) * SWORD1(a22);
        else
          v46 = SWORD1(a22) * (SHIWORD(a22) - 8) + SHIWORD(a21);
        sub_12B753(v37, v46);
        sub_12F578(dword_19283C, v37);
        sub_12DFB2(dword_192840, (int16_t *)dword_19283C, 0);
        v45 = 3;
        goto LABEL_38;
      case 3:
        if ( (uint16_t)sub_3883A(vars6) || *(_BYTE *)(dword_192864 + 313 * vars6 + 176) )
          v47 = (16 - SHIWORD(a22)) * SWORD1(a22);
        else
          v47 = (16 - SHIWORD(a22)) * SWORD1(a22) + SHIWORD(a21);
        sub_12B753(v37, v47);
        v45 = 3;
        sub_12F578(dword_192840, v37);
LABEL_38:
        sub_12DFB2(dword_19283C, (int16_t *)dword_192840, v45);
        break;
      default:
        break;
    }
    v43 = dword_192864 + 313 * vars6;
    if ( *(_BYTE *)(v43 + 64) == 4 )
    {
      if ( *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32) == word_19999C || byte_199F3A == 1 )
      {
        sub_12E64F((int16_t *)dword_192840, (int16_t *)dword_19283C, 5, 0);
        sub_12EFBD(0, 0, (_WORD *)dword_192840, (int *)dword_19283C, 0);
        sub_12A478(WORD1(a23) + HIWORD(a20) + vars2, HIWORD(a23) + HIWORD(a19) + var2, dword_192840);
      }
    }
    else
    {
      if ( *(_BYTE *)(v43 + 64) == 1 || *(_BYTE *)(v43 + 64) == 5 )
        sub_33DC3((int16_t *)dword_19283C, (2 * vars6 + word_19987A) % 16, 3, a2);
      v48 = 313 * vars6;
      if ( *(int16_t *)(v48 + dword_192864 + 69) > 0
        && !sub_3E563(vars6)
        && !sub_3E57C(vars6)
        && !*(_WORD *)(v48 + dword_192864 + 67) )
      {
        sub_3B3ED(vars6, vars2, (int16_t)var2);
      }
      sub_12A478(HIWORD(a20) + vars2, HIWORD(a19) + var2, dword_19283C);
      if ( sub_3E563(vars6) )
      {
        sub_AC619(vars6, 100, 0, 0);
      }
      else if ( *(int16_t *)(dword_192864 + 313 * vars6 + 67) <= 0 )
      {
        if ( sub_3E57C(vars6) )
          sub_3B4C0(vars6, 0, 0);
      }
      else
      {
        sub_AD580(vars6, (int16_t)vars2);
      }
    }
  }
  else
  {
    sub_12A478(
      HIWORD(a20) + 20 * (*(uint8_t *)(v27 + dword_192864 + 33) - word_1998F0),
      HIWORD(a19) + 20 * (*(uint8_t *)(v27 + dword_192864 + 34) - word_1998F2),
      dword_19285C);
    sub_49ED1(0, &vars2, &var2);
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x2E2B2 je epilog funkce */
#undef a5
#undef a6
#undef a7
#undef a8
#undef a9
#undef a10
#undef a11
#undef a12
#undef a13
#undef a14
#undef a15
#undef a16
#undef a17
#undef a18
#undef a19
#undef a20
#undef a21
#undef a22
#undef a23
}
// 300D4: inconsistent variable size for '^F0.8'
// 300FB: inconsistent variable size for '^F0.8'
// 30174: inconsistent variable size for '^F8.8'
// 30088: inconsistent variable size for '^100.8'
// 19283C: using guessed type int dword_19283C;
// 192840: using guessed type int dword_192840;
// 19285C: using guessed type int dword_19285C;
// 192864: using guessed type int dword_192864;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 19987A: using guessed type int16_t word_19987A;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F8: using guessed type int16_t word_1998F8;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;


//----- (00030631) --------------------------------------------------------
void sub_30631()
{
  uint8_t v0; // dl
  char v1; // dl
  int v2; // eax
  int16_t v3; // si
  int16_t v4; // di
  int16_t v5; // dx
  int16_t v6; // ax
  char v7; // al
  int v8; // eax
  int v9; // esi
  int16_t v10; // di
  int v11; // ecx
  int v12; // eax
  char v13; // dl
  int16_t *v14; // esi
  int v15; // edx
  int v16; // ecx
  char *v17; // edi
  char *v18; // edi
  int16_t v19; // dx
  int v20; // ecx
  char *v21; // edi
  int16_t *v22; // esi
  int16_t v23; // dx
  int v24; // ecx
  int16_t v25; // cx
  int v26; // eax
  char *v27; // edi
  char *v28; // edi
  char *v29; // edi
  char *v30; // edi
  int16_t v31; // dx
  char *v32; // ebx
  int16_t v33; // ax
  int16_t v34; // ax
  int16_t v35; // si
  int16_t v36; // bx
  char *v37; // edi
  char *v38; // edi
  int v39; // ecx
  int16_t v40; // dx
  int16_t v41; // ax
  char *v42; // edi
  char *v43; // edi
  char *v44; // edi
  int16_t v45; // cx
  char *v46; // edi
  char *v47; // edi
  int16_t v48; // ax
  int v49; // ecx
  int16_t v50; // dx
  int16_t v51; // ax
  int16_t v52; // dx
  int v53; // ecx
  char *v54; // edi
  char *v55; // edi
  char *v56; // edi
  char *v57; // edi
  char *v58; // edi
  char *v59; // edi
  char *v60; // edi
  char *v61; // edi
  int16_t v62; // di
  int16_t v63; // ax
  int16_t v64; // si
  int16_t v65; // cx
  int16_t v66; // cx
  int16_t v67; // cx
  int16_t v68; // dx
  char *v69; // ebx
  int16_t v70; // dx
  int16_t v71; // ax
  int16_t v72; // cx
  int16_t v73; // si
  int v74; // eax
  int v75; // ecx
  char *v76; // edi
  char *v77; // esi
  char *v78; // edi
  int v79; // eax
  char *v80; // esi
  char *v81; // edi
  char *v82; // edi
  char *v83; // edi
  int16_t v84; // si
  char v85; // al
  int16_t v86; // di
  int16_t v87; // si
  int v88; // edx
  int16_t v89; // dx
  int16_t v90; // ax
  char *v91; // ebx
  int16_t i; // bx
  char *v93; // edi
  char *v94; // esi
  char *v95; // edi
  int16_t v96; // di
  int16_t v97; // si
  int16_t v98; // cx
  int16_t v99; // dx
  int16_t v100; // di
  unsigned int v101; // ecx
  char *v102; // edx
  int16_t v103; // ax
  char *v104; // [esp-4h] [ebp-FEh] BYREF
  char v105[100]; // [esp+0h] [ebp-FAh] BYREF
  char v106[80]; // [esp+64h] [ebp-96h] BYREF
  _BYTE v107[31]; // [esp+B4h] [ebp-46h] BYREF
  char v108; // [esp+D3h] [ebp-27h] BYREF
  char v109[12]; // [esp+D4h] [ebp-26h] BYREF
  char v110; // [esp+E0h] [ebp-1Ah] BYREF
  char v111; // [esp+E1h] [ebp-19h]
  char v112; // [esp+E2h] [ebp-18h]
  char v113; // [esp+E3h] [ebp-17h]
  char v114; // [esp+E4h] [ebp-16h]
  char v115; // [esp+E5h] [ebp-15h]
  char v116; // [esp+E6h] [ebp-14h]
  char v117; // [esp+E7h] [ebp-13h]
  char v118; // [esp+E8h] [ebp-12h] BYREF
  char v119; // [esp+E9h] [ebp-11h]
  char v120; // [esp+EAh] [ebp-10h]
  char v121; // [esp+EBh] [ebp-Fh]
  char v122; // [esp+ECh] [ebp-Eh]
  char v123; // [esp+EDh] [ebp-Dh]
  char v124; // [esp+EEh] [ebp-Ch]
  char v125; // [esp+EFh] [ebp-Bh]
  _BYTE v126[8]; // [esp+F0h] [ebp-Ah] BYREF
  int v127; // [esp+F8h] [ebp-2h]
  int v128; // [esp+FCh] [ebp+2h]
  int v129; // [esp+100h] [ebp+6h]
  int v130; // [esp+104h] [ebp+Ah]
  int v131; // [esp+108h] [ebp+Eh]
  int v132; // [esp+10Ch] [ebp+12h]
  int v133; // [esp+110h] [ebp+16h]
  int v134; // [esp+114h] [ebp+1Ah]
  int v135; // [esp+118h] [ebp+1Eh]
  int v136; // [esp+11Ch] [ebp+22h]
  int v137; // [esp+120h] [ebp+26h]
  int v138; // [esp+124h] [ebp+2Ah]
  int v139; // [esp+128h] [ebp+2Eh]
  int v140; // [esp+12Ch] [ebp+32h]
  int v141; // [esp+130h] [ebp+36h]
  int v142; // [esp+134h] [ebp+3Ah]
  int v143; // [esp+138h] [ebp+3Eh]
  int v144; // [esp+13Ch] [ebp+42h]
  int v145; // [esp+140h] [ebp+46h]
  int v146; // [esp+144h] [ebp+4Ah]
  int v147; // [esp+148h] [ebp+4Eh]
  int v148; // [esp+14Ch] [ebp+52h]
  int v149; // [esp+150h] [ebp+56h]
  bool v150; // [esp+154h] [ebp+5Ah]
  int v151; // [esp+158h] [ebp+5Eh]
  int v152; // [esp+15Ch] [ebp+62h]
  int v153; // [esp+160h] [ebp+66h]
  int v154; // [esp+164h] [ebp+6Ah]
  int v155; // [esp+168h] [ebp+6Eh]
  int16_t v156; // [esp+16Ch] [ebp+72h]
  int v157; // [esp+170h] [ebp+76h]
  int v158; // [esp+174h] [ebp+7Ah]
  uint8_t v159; // [esp+178h] [ebp+7Eh]

  dword_19292C = sub_127C27((int)aCombatLbx_0, 5, dword_193174);
  v144 = 320 - *(int16_t *)dword_19292C / 2 + 9;
  if ( g_orion150 && byte_199A32 > 8 )   /* 1.50 03067A: sub_1E0A95 */
    byte_199A32 = byte_199B4A;
  v153 = 240 - *(int16_t *)(dword_19292C + 2) / 2 + 9;
  v150 = word_199B12 == -666;
  if ( !word_199A08 || word_199A08 == 4 || word_199A08 == 29 )
  {
    v156 = 0;
    v0 = 0x80;
    do
    {
      byte_19B544[v156++] = sub_133DE1(v0);
      v0 += 2;
    }
    while ( v156 < 8 );
    v159 = sub_133DE1(0xC7u);
    v156 = 1;
    v126[0] = sub_133DE1(0x48u);
    do
    {
      v1 = sub_133DE1(0x4Au);
      v2 = v156++;
      v126[v2] = v1;
    }
    while ( v156 < 8 );
    sub_129130(
      (int16_t)v144,
      (int16_t)v153,
      (int16_t)(v144 + 325),
      (int16_t)(v153 + 387),
      (uint8_t)byte_19B546,
      (uint8_t)byte_19B546,
      0);
    v130 = v159;
    v3 = v153 + 105;
    v4 = v153 + 26;
    sub_128EDE(v144 + 10, v153 + 26, v144 + 95, v153 + 105, 0, v159);
    if ( (uint8_t)byte_199A32 < 8u )
      sub_128EDE(v144 + 236, v4, v144 + 308, v3, 0, v130);
    v110 = byte_19B546;
    v111 = byte_19B54A;
    v112 = byte_19B549;
    v113 = byte_19B54A;
    v114 = byte_19B54A;
    v115 = byte_19B54A;
    v116 = byte_19B54A;
    v117 = byte_19B54A;
    v118 = byte_19B544[0];
    v119 = byte_19B548;
    v120 = byte_19B546;
    v121 = byte_19B548;
    v122 = byte_19B548;
    v123 = byte_19B548;
    v124 = byte_19B548;
    v125 = byte_19B548;
    sub_33199(v144 + 10, v153 + 24);
    if ( (uint8_t)byte_199A32 >= 8u )
      goto LABEL_28;
    if ( word_199ABF == -1 )
    {
      sub_12B7E1((int16_t)(v144 + 246), (int16_t)(v153 + 39), (_WORD *)dword_192814);
      goto LABEL_28;
    }
    v5 = v153 + 22;
    v6 = v144 + 236;
  }
  else
  {
    v156 = 0;
    v159 = -57;
    v7 = 0x80;
    do
    {
      byte_19B544[v156++] = v7;
      v7 += 2;
    }
    while ( v156 < 8 );
    v126[0] = 72;
    v156 = 1;
    do
    {
      v8 = v156++;
      v126[v8] = 74;
    }
    while ( v156 < 8 );
    sub_129130(
      (int16_t)v144,
      (int16_t)v153,
      (int16_t)(v144 + 325),
      (int16_t)(v153 + 387),
      (uint8_t)byte_19B545,
      (uint8_t)byte_19B545,
      0);
    v129 = v159;
    v9 = (int16_t)(v153 + 105);
    v10 = v153 + 26;
    v11 = v9;
    sub_128EDE(v144 + 10, v153 + 26, v144 + 95, v9, 0, v159);
    if ( (uint8_t)byte_199A32 < 8u )
    {
      v11 = v9;
      sub_128EDE(v144 + 236, v10, v144 + 308, v9, 0, v129);
    }
    v110 = byte_19B546;
    v111 = byte_19B54A;
    v112 = byte_19B549;
    v113 = byte_19B54A;
    v114 = byte_19B54A;
    v115 = byte_19B54A;
    v116 = byte_19B54A;
    v117 = byte_19B54A;
    v118 = byte_19B544[0];
    v119 = byte_19B548;
    v120 = byte_19B546;
    v121 = byte_19B548;
    v122 = byte_19B548;
    v123 = byte_19B548;
    v124 = byte_19B548;
    v125 = byte_19B548;
    sub_2D1ED(v144 + 10, (int16_t)(v153 + 24), word_1998D2, v11);
    if ( (uint8_t)byte_199A32 > 8u )
      goto LABEL_28;
    if ( word_199ABF != -1 )
    {
      v156 = 0;
      do
      {
        v12 = v156;
        v13 = v156++;
        v107[v12] = v13;
      }
      while ( v156 < 32 );
      sub_1112EC(dword_192ED4, 10000);
      v14 = (int16_t *)(_DWORD*)sub_110D3C((PoolMemType*)dword_192ED4, 10000);
      sub_12F578((int)v14, dword_192814);
      sub_12F498(v14, 0, 32, (int)v107, 0);
      v15 = (int16_t)(v153 + 25);
      sub_12A478(v144 + 235, v15, (int)v14);
      sub_1113CC(dword_192ED4, v15);
LABEL_28:
      v154 = v153 + 26;
      sub_120CCB(2, (int)&v110);
      sub_58F1E(8, v106, 80);
      sub_1210FD(v144 + 167, v154, (int)v106);
      v16 = (int16_t)(v154 + 48);
      sub_128EDE(v144 + 106, v154 + 12, v144 + 219, v16, 0, v159);
      sub_120CCB(1, (int)&v118);
      v154 += 15;
      sub_58F1E(9, v106, 80);
      sub_1212B3(v144 + 111, v154, (int)v106);
      itoa(word_199A46, v109, 10, v16);
      if ( word_199A46 <= 0 )
        v105[0] = 0;
      else
        strcpy(v105, "+");
      /* vlna 73: puvodne `v104 = v105; v17 = (char *)&v104 + 3;` -
         v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
         v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
         8 B, takze &v104+3 miri DOVNITR ukazatele. */
      v17 = (char *)v105;
      while ( *v17 )
        ++v17;
      strcpy(v17, v109);
      sub_1210B7(v144 + 214, v154, (int)v105);
      v154 += 12;
      sub_58F1E(10, v106, 80);
      sub_1212B3(v144 + 111, v154, (int)v106);
      itoa(word_199A48, v109, 10, v16);
      if ( word_199A48 <= 0 )
        v105[0] = 0;
      else
        strcpy(v105, "+");
      /* vlna 73: puvodne `v104 = v105; v18 = (char *)&v104 + 3;` -
         v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
         v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
         8 B, takze &v104+3 miri DOVNITR ukazatele. */
      v18 = (char *)v105;
      while ( *v18 )
        ++v18;
      strcpy(v18, v109);
      v19 = v154;
      v154 += 12;
      v128 = (int16_t)(v144 + 214);
      sub_1210B7(v144 + 214, v19, (int)v105);
      v20 = (int16_t)v154;
      sub_58F1E(11, v106, 80);
      sub_1212B3(v144 + 111, v20, (int)v106);
      itoa(word_199A4A, v109, 10, v20);
      strcpy(v105, v109);
      /* vlna 73: puvodne `v104 = v105; v21 = (char *)&v104 + 3;` -
         v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
         v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
         8 B, takze &v104+3 miri DOVNITR ukazatele. */
      v21 = (char *)v105;
      while ( *v21 )
        ++v21;
      strcpy(v21, "%");
      v154 += 18;
      sub_1210B7(v128, v20, (int)v105);
      if ( (uint8_t)byte_199A32 < 9u )
      {
        sub_120CCB(2, (int)&v110);
        v22 = sub_33CFA((uint8_t)byte_199ABE);
        v23 = 0;
        v104 = v105;
        strcpy(v105, (char *)v22);
        while ( v23 < strlen(v105) )
        {
          if ( v105[v23] == 40 )
            v105[v23] = 0;
          ++v23;
        }
        sub_1210FD(v144 + 166, v154, (int)v105);
      }
      v154 += 14;
      if ( byte_199AC1 != -1 && !(g_orion150 && (int16_t)v150 == 1) )   /* 1.50 030D76: sub_1E0B7D */
      {
        v24 = (int16_t)v154;
        sub_58F1E(12, v106, 80);
        sub_1212B3(v144 + 111, v24, (int)v106);
        sub_121153((int16_t)(v144 + 214), v24, (uint8_t)byte_199AC1, v24);
      }
      v139 = v153 + 118;
      v155 = v144 + 5;
      v152 = v144 + 165;
      if ( byte_199AC2 == 1 )
      {
        sub_120CCB(4, (int)v126);
        sub_120DED(0, 1);
        sub_58F1E(13, v106, 80);
        v25 = v153 + 3;
        sub_1212B3(v155, v153 + 3, (int)v106);
        sub_1210B7(v144 + 323, v25, (int)v106);
      }
      sub_120CCB(4, (int)&v110);
      sub_120DED(0, 1);
      sub_128EDE(268, 49, 383, 65, 0, v159);
      if ( word_199A08 && word_199A08 != 4 && word_199A08 != 29 )
        sub_1210FD(325, 50, (int)&unk_199A12);
      sub_120CCB(2, (int)&v110);
      if ( (uint8_t)byte_199A32 > 9u )
        v26 = 87;
      else
        v26 = 14;
      sub_58F1E(v26, v106, 80);
      sub_1212B3(v155, v139, (int)v106);
      if ( !v150 && (g_orion150 ? byte_199CB4 != 1 && word_199A3B[0] != 1 && word_199A30 != -1   /* 1.50 030F13: sub_1E0AF7 */
                                : byte_199A43 != 0) )
      {
        sub_120CCB(1, (int)&v118);
        strcpy(v105, "(");
        itoa(word_199B12, v109, 10, 65);
        /* vlna 73: puvodne `v104 = v105; v27 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v27 = (char *)v105;
        while ( *v27 )
          ++v27;
        strcpy(v27, v109);
        /* vlna 73: puvodne `v104 = v105; v28 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v28 = (char *)v105;
        while ( *v28 )
          ++v28;
        strcpy(v28, "/");
        itoa(word_199ADC, v109, 10, 65);
        /* vlna 73: puvodne `v104 = v105; v29 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v29 = (char *)v105;
        while ( *v29 )
          ++v29;
        strcpy(v29, v109);
        /* vlna 73: puvodne `v104 = v105; v30 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v30 = (char *)v105;
        while ( *v30 )
          ++v30;
        strcpy(v30, asc_178C5E);
        sub_1210B7(v155 + 155, v139 + 3, (int)v105);
      }
      sub_120CCB(2, (int)&v110);
      if ( (uint8_t)byte_199A32 > 9u )
      {
        sub_58F1E(88, v106, 80);
        v31 = v139;
        v33 = v152;
        v32 = v106;
      }
      else
      {
        v31 = v139;
        v32 = ((char *)(intptr_t)*(int *)((char *)&off_17F638 + 15 * (uint8_t)byte_199A45));
        v33 = v152;
      }
      sub_1212B3(v33, v31, (int)v32);
      v34 = v139;
      v139 += 14;
      v142 = v152 + 155;
      v35 = v34 + 12;
      v128 = v159;
      v104 = (char *)v159;
      if ( (uint8_t)byte_199A32 > 9u )
        v36 = v139 + 8;
      else
        v36 = v139 + 21;
      sub_128EDE(v155, v35, v155 + 155, v36, 0, (int16_t)v104);
      sub_128EDE(v152, v35, v142, v36, 0, v128);
      sub_120CCB(1, (int)&v118);
      if ( (uint8_t)byte_199A32 <= 9u )
      {
        itoa(Hook150_1E0A60(word_17FE9C[23 * (uint8_t)byte_199A43], v150), v109, 10, v36);   /* 1.50 310F9 */
        strcpy(v105, "^ ");
        /* vlna 73: puvodne `v104 = v105; v37 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v37 = (char *)v105;
        while ( *v37 )
          ++v37;
        strcpy(v37, v109);
        sub_58F1E(15, v106, 80);
        /* vlna 73: puvodne `v104 = v105; v38 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v38 = (char *)v105;
        while ( *v38 )
          ++v38;
        strcpy(v38, v106);
        sub_1212B3(v155 + 3, v139, (int)v105);
      }
      v39 = v152 + 3;
      if ( v150 )
      {
        v41 = sub_5685F(*(uint8_t *)(dword_192864 + 32));
        itoa((int16_t)((g_orion150 ? *(int16_t *)Hook150_Eseg(0x23CD3E) : 100)   /* 1.50 0311D7, 0311DC: sub_1E4AD9 */
                       * (*(int16_t *)((char *)&word_17F642 + 15 * v41) + 100) / 100), v109, 10, v39);
        strcpy(v105, "^ ");
        /* vlna 73: puvodne `v104 = v105; v42 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v42 = (char *)v105;
        while ( *v42 )
          ++v42;
        strcpy(v42, v109);
        /* vlna 73: puvodne `v104 = v105; v43 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v43 = (char *)v105;
        while ( *v43 )
          ++v43;
        strcpy(v43, asc_178C52);
        sub_58F1E(16, v106, 80);
        /* vlna 73: puvodne `v104 = v105; v44 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v44 = (char *)v105;
        while ( *v44 )
          ++v44;
        strcpy(v44, v106);
        v40 = v139;
      }
      else
      {
        sub_58F1E(89, v106, 80);
        v40 = v139;
        sprintf(v105, v106, word_199ABC - word_199AD2, word_199ABC);
      }
      sub_1212B3(v39, v40, (int)v105);
      if ( (uint8_t)byte_199A32 <= 9u )
        v139 += 12;
      v45 = v139;
      itoa(word_199A4D, v109, 10, (int16_t)v139);
      strcpy(v105, "^ ");
      /* vlna 73: puvodne `v104 = v105; v46 = (char *)&v104 + 3;` -
         v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
         v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
         8 B, takze &v104+3 miri DOVNITR ukazatele. */
      v46 = (char *)v105;
      while ( *v46 )
        ++v46;
      strcpy(v46, v109);
      sub_58F1E(17, v106, 80);
      /* vlna 73: puvodne `v104 = v105; v47 = (char *)&v104 + 3;` -
         v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
         v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
         8 B, takze &v104+3 miri DOVNITR ukazatele. */
      v47 = (char *)v105;
      while ( *v47 )
        ++v47;
      strcpy(v47, v106);
      sub_1212B3(v155 + 3, v45, (int)v105);
      if ( (uint8_t)byte_199A32 <= 9u )
      {
        if ( v150 )
        {
          sub_58F1E(20, v106, 80);
          v104 = v105;
          strcpy(v105, v106);
          v52 = v152 + 3;
          v51 = v52 + sub_12066F((int)&unk_178C80);
          v50 = v45;
        }
        else
        {
          if ( byte_199A43 )
          {
            v48 = (uint8_t)byte_199A37;
          }
          else if ( byte_199A32 == 8 )
          {
            v48 = 8;
          }
          else
          {
            v48 = Hook150_1E0ADF(word_199878);   /* 1.50 31348 */
          }
          v49 = word_180024[18 * v48]
              + *(int16_t *)((char *)&word_17F642 + 15 * (uint8_t)byte_199A45) * word_180024[18 * v48] / 100;
          if ( g_orion150 && byte_199CB4 )   /* 1.50 031382: sub_1E1556 */
            v49 = 0;
          if ( (uint16_t)sub_1276F0((int)&byte_199A5E, 0xEu) )
            v49 *= 3;
          itoa(word_199AD4, v109, 10, v49);
          sub_58F1E(91, v106, 80);
          v50 = v139;
          sprintf(v105, v106, word_199AD4, (int16_t)v49);
          v51 = v152 + 3;
        }
        sub_1212B3(v51, v50, (int)v105);
      }
      if ( (uint8_t)byte_199A32 > 9u )
        v139 += 12;
      v139 += 16;
      if ( (uint8_t)byte_199A32 <= 9u )
      {
        sub_120CCB(2, (int)&v110);
        v53 = (int16_t)v139;
        sub_58F1E(21, v106, 80);
        sub_1212B3(v155, v53, (int)v106);
        sub_120CCB(1, (int)&v118);
        strcpy(v105, "(");
        itoa(word_199B14, v109, 10, v53);
        /* vlna 73: puvodne `v104 = v105; v54 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v54 = (char *)v105;
        while ( *v54 )
          ++v54;
        strcpy(v54, v109);
        /* vlna 73: puvodne `v104 = v105; v55 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v55 = (char *)v105;
        while ( *v55 )
          ++v55;
        strcpy(v55, "/");
        itoa(word_199ADE, v109, 10, v53);
        /* vlna 73: puvodne `v104 = v105; v56 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v56 = (char *)v105;
        while ( *v56 )
          ++v56;
        strcpy(v56, v109);
        /* vlna 73: puvodne `v104 = v105; v57 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v57 = (char *)v105;
        while ( *v57 )
          ++v57;
        strcpy(v57, asc_178C5E);
        v127 = (int16_t)(v139 + 3);
        if ( Hook150_1E0B25(v150) )   /* 1.50 31567 */
          sub_1210B7(v155 + 155, v139 + 3, (int)v105);
        sub_120CCB(2, (int)&v110);
        if ( (uint8_t)byte_199A38 <= 6u )
        {
          sub_1212B3(v152, v53, *(int *)((char *)&off_17F6A1 + 59 * (uint8_t)byte_199A38));
          if ( byte_199A38 )
          {
            sub_120CCB(1, (int)&v118);
            strcpy(v105, "(");
            itoa(word_199B46, v109, 10, v53);
            /* vlna 73: puvodne `v104 = v105; v58 = (char *)&v104 + 3;` -
               v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
               v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
               8 B, takze &v104+3 miri DOVNITR ukazatele. */
            v58 = (char *)v105;
            while ( *v58 )
              ++v58;
            strcpy(v58, v109);
            /* vlna 73: puvodne `v104 = v105; v59 = (char *)&v104 + 3;` -
               v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
               v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
               8 B, takze &v104+3 miri DOVNITR ukazatele. */
            v59 = (char *)v105;
            while ( *v59 )
              ++v59;
            strcpy(v59, "/");
            itoa(word_199B10, v109, 10, v53);
            /* vlna 73: puvodne `v104 = v105; v60 = (char *)&v104 + 3;` -
               v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
               v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
               8 B, takze &v104+3 miri DOVNITR ukazatele. */
            v60 = (char *)v105;
            while ( *v60 )
              ++v60;
            strcpy(v60, v109);
            /* vlna 73: puvodne `v104 = v105; v61 = (char *)&v104 + 3;` -
               v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
               v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
               8 B, takze &v104+3 miri DOVNITR ukazatele. */
            v61 = (char *)v105;
            while ( *v61 )
              ++v61;
            strcpy(v61, asc_178C5E);
            if ( Hook150_1E0B25(v150) )   /* 1.50 3168A */
              sub_1210B7(v152 + 155, v127, (int)v105);
          }
        }
        else
        {
          sub_1212B3(v152, v53, TECHNAME_AT(19 * (uint8_t)byte_199A38));
        }
        v62 = v159;
        v63 = v139;
        v139 += 12;
        v64 = v139;
        sub_128EDE(v155, v139, v155 + 155, v63 + 25, 0, v159);
        v65 = v139 + 13;
        v139 += 3;
        sub_128EDE(v152, v64, v152 + 155, v65, 0, v62);
        v66 = v155;
        sub_120CCB(1, (int)&v118);
        v67 = v66 + 3;
        if ( word_199B14 <= 0 )
        {
          sub_58F1E(23, v106, 80);
          v68 = v139;
          v69 = v106;
        }
        else
        {
          sub_58F1E(22, v106, 80);
          v104 = (char *)word_17FE00[11 * (uint8_t)byte_199A44];
          v68 = v139;
          v69 = v105;
          sprintf(v105, v106, v104);
        }
        sub_1212B3(v67, v68, (int)v69);
        if ( v150 )
        {
          sub_58F1E(24, v106, 80);
          if ( byte_199A32 == 8 )
            v104 = 0;
          else
          {
            int def = *(int16_t *)((char *)&word_17F6C1 + 59 * (int16_t)sub_5679E((uint8_t)byte_199A32));

            if ( g_orion150 && !((int16_t)sub_3A142(0, 0) && !(int16_t)sub_4B0D3(0, 7)) )   /* 1.50 0317F3: sub_1E0B45 */
              v104 = (char *)(intptr_t)(byte_199A38 > 0 ? word_199A39 : 0);
            else
            v104 = (char *)(intptr_t)(def + word_199A39);
          }
          sprintf(v105, v106, v104);
          v71 = v152;
          v70 = v139;
        }
        else
        {
          sub_58F1E(24, v106, 80);
          v70 = v139;
          sprintf(v105, v106, word_199A39);
          v71 = v152;
        }
        sub_1212B3(v71 + 3, v70, (int)v105);
        v139 += 18;
      }
      v72 = v139;
      sub_120CCB(2, (int)&v110);
      v73 = v155;
      sub_58F1E(25, v106, 80);
      sub_1212B3(v73, v72, (int)v106);
      sub_58F1E(26, v106, 80);
      sub_1212B3(v155 + 150, v72, (int)v106);
      sub_58F1E(27, v106, 80);
      sub_1212B3(v155 + 200, v72, (int)v106);
      sub_128EDE(v73, v139 + 13, v155 + 315, v139 + 102, 0, v159);
      v148 = v155 + 203;
      v133 = v155 + 153;
      v138 = v155 + 161;
      v139 += 16;
      v134 = v155 + 3;
      v156 = 0;
      v145 = v139 + 1;
      v146 = v139 + 2;
      v131 = v139 + 3;
      v158 = v155 + 153;
      v135 = v155 + 154;
      v74 = v155 + 155;
      v137 = v155 + 156;
      v136 = v155 + 155;
      while ( 1 )
      {
        v75 = 11 * v156;
        if ( !*(int16_t *)((char *)&word_199A64 + v75) )
          goto LABEL_204;
        LOWORD(v74) = (uint8_t)byte_199A67[11 * v156];
        v151 = v74;
        sub_120CCB(1, (int)&v118);
        sub_120E8C(1);
        itoa((uint8_t)byte_199A66[v75], v109, 10, v75);
        strcpy(v105, v109);
        /* vlna 73: puvodne `v104 = v105; v76 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v76 = (char *)v105;
        while ( *v76 )
          ++v76;
        strcpy(v76, asc_178C52);
        if ( byte_199A66[v75] == 1 )
          v77 = (char *)WEAPON_NAME(0x7803, *(int16_t *)((char *)&word_199A64 + v75));
        else
          v77 = (char *)WEAPON_NAME(0x7807, *(int16_t *)((char *)&word_199A64 + v75));
        /* vlna 73: puvodne `v104 = v105; v78 = (char *)&v104 + 3;` -
           v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
           v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
           8 B, takze &v104+3 miri DOVNITR ukazatele. */
        v78 = (char *)v105;
        while ( *v78 )
          ++v78;
        strcpy(v78, v77);
        strcpy(v109, " (");
        if ( (uint16_t)v151 < 4u )
        {
          if ( !(_WORD)v151 )
            goto LABEL_169;
          if ( (uint16_t)v151 <= 1u )
          {
            v79 = 3;
          }
          else
          {
            if ( (_WORD)v151 != 2 )
              goto LABEL_169;
            v79 = 4;
          }
        }
        else if ( (uint16_t)v151 <= 4u )
        {
          v79 = 6;
        }
        else
        {
          if ( (uint16_t)v151 < 8u )
            goto LABEL_169;
          if ( (uint16_t)v151 > 8u )
          {
            if ( (_WORD)v151 != 15 )
              goto LABEL_169;
            v80 = a360;
            goto LABEL_166;
          }
          v79 = 5;
        }
        v80 = v106;
        sub_58F1E(v79, v106, 80);
LABEL_166:
        v104 = v109;
        v81 = (char *)v109 - 1;   /* vlna 124: cil je sousedni buffer v109, ne &v108 */
        do
          ++v81;
        while ( *v81 );
        strcpy(v81, v80);
LABEL_169:
        v104 = v109;
        v82 = (char *)v109 - 1;   /* vlna 124: cil je sousedni buffer v109, ne &v108 */
        do
          ++v82;
        while ( *v82 );
        strcpy(v82, asc_178C5E);
        if ( (int16_t)v151 != 1 )
        {
          /* vlna 73: puvodne `v104 = v105; v83 = (char *)&v104 + 3;` -
             v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
             v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
             8 B, takze &v104+3 miri DOVNITR ukazatele. */
          v83 = (char *)v105;
          while ( *v83 )
            ++v83;
          strcpy(v83, v109);
        }
        v84 = v139;
        sub_1212B3(v134, v139, (int)v105);
        v85 = byte_17F80F[28 * *(int16_t *)((char *)&word_199A64 + 11 * v156)];
        if ( v85 )
        {
          if ( (uint8_t)v85 <= 1u )
            goto LABEL_181;
          if ( (uint8_t)v85 <= 2u )
          {
            v141 = v131;
            v140 = v146;
            v149 = 0;
            v143 = v145;
            v86 = v136;
            v132 = v158;
            v87 = v137;
            v147 = v135;
            while ( (uint8_t)byte_17F810[28 * *(int16_t *)((char *)&word_199A64 + 11 * v156)] > (int16_t)v149 )
            {
              if ( *(int16_t *)((char *)&word_199A6A + 11 * v156) )
              {
                if ( (int16_t)v149 >= *(int16_t *)((char *)&word_199A6A + 11 * v156) )
                {
                  sub_1297C3(v132, v139, 7, 7, 1, 81);
                  sub_1297C3(v147, v143, 5, 5, 1, 84);
                  sub_1297C3(v86, v140, 3, 3, 1, 84);
                  sub_1297C3(v87, v141, 1, 1, 1, 84);
                }
                else
                {
                  sub_1297C3(v132, v139, 7, 7, 1, 73);
                  sub_1297C3(v147, v143, 5, 5, 1, 75);
                  sub_1297C3(v86, v140, 3, 3, 1, 75);
                  sub_1297C3(v87, v141, 1, 1, 1, 75);
                }
              }
              else
              {
                sub_58F1E(28, v106, 80);
                sub_1212B3(v133, v139, (int)v106);
              }
              v132 += 9;
              v147 += 9;
              ++v149;
              v86 += 9;
              v87 += 9;
            }
            goto LABEL_190;
          }
          if ( (uint8_t)v85 <= 4u )
LABEL_181:
            sub_121153((int16_t)v138, (int16_t)v139, *(int16_t *)((char *)&word_199A6A + 11 * v156), v75);
        }
        else
        {
          sub_1212B3(v133, v84, (int)&unk_178C83);
        }
LABEL_190:
        LOWORD(v88) = *(int16_t *)((char *)&word_199A68 + 11 * v156);
        if ( (_WORD)v88 )
        {
          v105[0] = 0;
          for ( i = 0; i < 15; ++i )
          {
            if ( (v88 & 1) != 0 )
            {
              if ( strlen(v105) )
              {
                /* vlna 73: puvodne `v104 = v105; v93 = (char *)&v104 + 3;` -
                   v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
                   v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
                   8 B, takze &v104+3 miri DOVNITR ukazatele. */
                v93 = (char *)v105;
                while ( *v93 )
                  ++v93;
                strcpy(v93, ", ");
              }
              v94 = ((char *)(intptr_t)*(int *)((char *)&off_17FD0F + 15 * i));
              /* vlna 73: puvodne `v104 = v105; v95 = (char *)&v104 + 3;` -
                 v asm lezi v104 tesne pred bufferem v105, takze &v104+4 je
                 v105[0] a smycka hleda konec retezce (strcat). Na x64 ma ukazatel
                 8 B, takze &v104+3 miri DOVNITR ukazatele. */
              v95 = (char *)v105;
              while ( *v95 )
                ++v95;
              strcpy(v95, v94);
            }
            v88 = (int16_t)v88 >> 1;
          }
          v89 = v139;
          v90 = v148;
          v91 = v105;
        }
        else
        {
          sub_58F1E(29, v106, 80);
          v89 = v139;
          v90 = v148;
          v91 = v106;
        }
        v74 = sub_1212B3(v90, v89, (int)v91);
LABEL_204:
        v145 += 11;
        v146 += 11;
        v131 += 11;
        ++v156;
        v139 += 11;
        if ( v156 >= 8 )
        {
          v139 += 7;
          sub_120CCB(2, (int)&v110);
          v96 = v155;
          sub_58F1E(30, v106, 80);
          v97 = 0;
          sub_1212B3(v96, v139, (int)v106);
          v156 = 0;
          v98 = v139 + 59;
          v99 = v139 + 13;
          v139 += 16;
          sub_128EDE(v96, v99, v155 + 315, v98, 0, v159);
          v100 = v152 + 3;
          v157 = v155 + 3;
          while ( 1 )
          {
            v101 = v156;
            if ( (uint16_t)sub_1276F0((int)&byte_199A5E, v156) )
            {
              if ( (uint16_t)sub_1276F0((int)&byte_199AC4, v101) )
                v102 = v126;
              else
                v102 = &v118;
              sub_120CCB(1, (int)v102);
              sub_120E8C(1);
              if ( (v97 & 1) == 0 && v97 )
                v139 += 11;
              if ( (v97 & 1) != 0 )
                v103 = v100;
              else
                v103 = v157;
              sub_1212B3(v103, v139, *(int *)((char *)&off_17EEE0 + 47 * v156));
              ++v97;
            }
            if ( ++v156 >= 39 )
            {
              dword_19292C = sub_127C27((int)aCombatLbx_0, 5, dword_193174);
              sub_12A478(v144 - 9, v153 - 9, dword_19292C);
              return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x33AFF je epilog funkce */
            }
          }
        }
      }
    }
    if ( (uint8_t)byte_199A32 >= 8u )
      goto LABEL_28;
    v5 = v153 + 39;
    v6 = v144 + 246;
  }
  sub_12A478(v6, v5, dword_192814);
  goto LABEL_28;
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 17EEE0: using guessed type _UNKNOWN *off_17EEE0;
// 17F638: using guessed type _UNKNOWN *off_17F638;
// 17F642: using guessed type int16_t word_17F642;
// 17F6A1: using guessed type _UNKNOWN *off_17F6A1;
// 17F6C1: using guessed type int16_t word_17F6C1;
// 17F803: using guessed type _UNKNOWN *off_17F803;
// 17F807: using guessed type _UNKNOWN *off_17F807;
// 17FD0F: using guessed type _UNKNOWN *off_17FD0F;
// 17FE00: using guessed type int16_t word_17FE00[];
// 17FE9C: using guessed type int16_t word_17FE9C[];
// 180024: using guessed type int16_t word_180024[];
// 192814: using guessed type int dword_192814;
// 192864: using guessed type int dword_192864;
// 19292C: using guessed type int dword_19292C;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 199878: using guessed type int16_t word_199878;
// 1998D2: using guessed type int16_t word_1998D2;
// 199A08: using guessed type int16_t word_199A08;
// 199A32: using guessed type char byte_199A32;
// 199A37: using guessed type char byte_199A37;
// 199A38: using guessed type char byte_199A38;
// 199A39: using guessed type int16_t word_199A39;
// 199A43: using guessed type char byte_199A43;
// 199A44: using guessed type char byte_199A44;
// 199A45: using guessed type char byte_199A45;
// 199A46: using guessed type int16_t word_199A46;
// 199A48: using guessed type int16_t word_199A48;
// 199A4A: using guessed type int16_t word_199A4A;
// 199A4D: using guessed type int16_t word_199A4D;
// 199A5E: using guessed type char byte_199A5E;
// 199A64: using guessed type int16_t word_199A64;
// 199A68: using guessed type int16_t word_199A68;
// 199A6A: using guessed type int16_t word_199A6A;
// 199ABC: using guessed type int16_t word_199ABC;
// 199ABE: using guessed type char byte_199ABE;
// 199ABF: using guessed type int16_t word_199ABF;
// 199AC1: using guessed type char byte_199AC1;
// 199AC2: using guessed type char byte_199AC2;
// 199AC4: using guessed type char byte_199AC4;
// 199AD2: using guessed type int16_t word_199AD2;
// 199AD4: using guessed type int16_t word_199AD4;
// 199ADC: using guessed type int16_t word_199ADC;
// 199ADE: using guessed type int16_t word_199ADE;
// 199B10: using guessed type int16_t word_199B10;
// 199B12: using guessed type int16_t word_199B12;
// 199B14: using guessed type int16_t word_199B14;
// 199B46: using guessed type int16_t word_199B46;
// 19B545: using guessed type char byte_19B545;
// 19B546: using guessed type char byte_19B546;
// 19B548: using guessed type char byte_19B548;
// 19B549: using guessed type char byte_19B549;
// 19B54A: using guessed type char byte_19B54A;


//----- (00031F25) --------------------------------------------------------
void sub_31F25( int a1)
{
  _BOOL1 v1; // bl
  void *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int16_t v6; // ax
  _DWORD *v7; // eax
  _BOOL2 v8; // si
  unsigned int v9; // eax
  uint16_t v10; // di
  int v11; // eax
  int16_t v12; // [esp+0h] [ebp-1Ch]
  char v13[16]; // [esp+4h] [ebp-18h] BYREF
  int v14; // [esp+14h] [ebp-8h]
  _BOOL1 v15; // [esp+18h] [ebp-4h]

  v12 = a1;   /* wave 181: v12 saved by the prologue (push eax) */
  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v14 = a1;
  v1 = a1 == -1;
  sub_6FCAB();
  sub_107AF(&dword_19B568);
  sub_124D7A();
  --word_19987A;
  sub_107C2(&dword_19B568);
  sub_1174CB();
  v2 = sub_124E36();
  sub_1077D(v2, 0, 0, 0);
  sub_1191CA((int)sub_30631, 1);
  v15 = v1;
  sub_1112EC(dword_192ED4, 1);
  if ( !v1 )
  {
    word_1998D2 = -1;
    if ( g_orion150 )   /* 1.50 031F9D: sub_1E29EF - byte_199A12 cleared (313 bytes) first */
      sub_127776((_BYTE *)byte_199A12, 0x139);
    sub_4CB1E(v14, (int)&word_199A48, (int)&word_199A4A, (int16_t)&word_199A46);
    strcpy(v13, byte_199A12);
    sub_54E5B(v14, &word_199A48, &word_199A4A, &word_199A46);
    v3 = sub_12DAA4(98, 98);
    dword_19283C = (int)(_DWORD*)sub_110D3C((PoolMemType*)dword_192ED4, v3);
    v4 = sub_12DAA4(98, 98);
    dword_192824 = (int)(_DWORD*)sub_110D3C((PoolMemType*)dword_192ED4, v4);
    v5 = sub_127C27((int)aCombatLbx, 11, dword_193174);
    sub_133C9C(v5, 11);
    byte_1A125C[0] = sub_133DE1(0x84u);
    byte_1A125D = sub_133DE1(0x8Cu);
    byte_1A125E = sub_133DE1(0x8Au);
    byte_1A125F = sub_133DE1(0x8Cu);
    // vlna 58: dword_1A1260 je ted pole (souvisly blok) - bajty prvniho prvku.
    LOBYTE(dword_1A1260[0]) = sub_133DE1(0x8Cu);
    BYTE1(dword_1A1260[0]) = sub_133DE1(0x8Cu);
    BYTE2(dword_1A1260[0]) = sub_133DE1(0x8Cu);
    HIBYTE(dword_1A1260[0]) = sub_133DE1(0x8Cu);
  }
  if ( word_199ABF == -1 )
  {
    v6 = (uint8_t)byte_199A32;
    if ( (uint8_t)byte_199A32 >= 8u )
      v6 = 0;
    v7 = sub_126B42((int)aFlticonsLbx, *(uint8_t *)(3753 * v6 + (uint8_t*)dword_197F98 + 37), dword_192ED4);
  }
  else if ( v15 )
  {
    v7 = sub_925AE(0, word_199ABF, dword_192ED4, 0, 2u);
  }
  else
  {
    v7 = sub_925AE(0, word_199ABF, dword_192ED4, 0, 0);
  }
  dword_192814 = (int)v7;
  sub_119861();
  if ( !v15 )
  {
    sub_120BB5(4, (int)byte_1A125C);
    sub_115BEA(262, 50, 103, 12, (int)v13, 15, 0, 0, 0, 0);
    sub_11438B(268, 50, 383, 64, &unk_178CA0, 0);
  }
  v8 = 0;
  v9 = sub_11438B(0, 0, 639, 479, &unk_178CA0, 0);
  v10 = v9;
  while ( !v8 )
  {
    v8 = (uint16_t)sub_1171AB(v9, 0, 639, 479) == v10;
    sub_124D41();
    sub_30631();
    v9 = sub_1077D(0, 0, 0, 0);
  }
  if ( !v15 )
  {
    sub_13303E((int)v13);
    if ( v13[0] )
      strcpy((char *)(dword_197F9C + 129 * v12), v13);
  }
  sub_1198F9();
  sub_6FCCE();
  sub_107BA((int *)&dword_19B568);
  sub_1113CC(dword_192ED4, 0);
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x33AFE je epilog funkce */
}
// 1077D: using guessed type int sub_1077D(_DWORD);
// 192814: using guessed type int dword_192814;
// 192824: using guessed type int dword_192824;
// 19283C: using guessed type int dword_19283C;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 19987A: using guessed type int16_t word_19987A;
// 1998D2: using guessed type int16_t word_1998D2;
// 199A32: using guessed type char byte_199A32;
// 199A46: using guessed type int16_t word_199A46;
// 199A48: using guessed type int16_t word_199A48;
// 199A4A: using guessed type int16_t word_199A4A;
// 199ABF: using guessed type int16_t word_199ABF;
// 19B568: using guessed type int (*dword_19B568)(void);
// 1A125C: using guessed type char byte_1A125C;
// 1A125D: using guessed type char byte_1A125D;
// 1A125E: using guessed type char byte_1A125E;
// 1A125F: using guessed type char byte_1A125F;
// 1A1260: using guessed type int dword_1A1260;


//----- (00032243) --------------------------------------------------------
void sub_32243()
{
  int16_t v0; // ax
  int16_t v1; // cx
  int v2; // edx
  uint8_t *v3; // eax
  int16_t v4; // bx
  int v5; // ebx
  int v6; // eax
  int16_t v7; // dx
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int16_t i; // di
  int16_t v15; // ax
  int v16; // ecx
  int16_t v17; // bx
  int16_t v18; // dx
  int16_t v19; // bx
  _WORD *v20; // ebx
  int16_t v21; // dx
  int16_t v22; // ax
  int v23; // ecx
  int v24; // edi
  int v25; // ebx
  int v26; // esi
  int v27; // eax
  int v28; // esi
  int v29; // edx
  int v30; // eax
  int16_t v31; // dx
  int v32; // esi
  int v33; // ebx
  int v34; // edx
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // edi
  int v40; // esi
  int v41; // ebx
  int v42; // eax
  int v43; // ebx
  int v44; // edx
  _WORD v45[2]; // [esp+0h] [ebp-54h] BYREF
  int16_t v46; // [esp+4h] [ebp-50h]
  int16_t v47; // [esp+8h] [ebp-4Ch]
  int16_t v48; // [esp+Ch] [ebp-48h]
  _WORD v49[6]; // [esp+10h] [ebp-44h]
  int16_t v50; // [esp+1Ch] [ebp-38h]
  int16_t v51; // [esp+1Eh] [ebp-36h]
  int16_t v52; // [esp+20h] [ebp-34h]
  int16_t v53; // [esp+22h] [ebp-32h]
  int16_t v54; // [esp+24h] [ebp-30h]
  int16_t v55; // [esp+26h] [ebp-2Eh]
  int16_t v56; // [esp+28h] [ebp-2Ch]
  int16_t v57; // [esp+2Ah] [ebp-2Ah]
  _WORD v58[8]; // [esp+2Ch] [ebp-28h]
  int v59; // [esp+3Ch] [ebp-18h]
  int v60; // [esp+40h] [ebp-14h]
  int v61; // [esp+44h] [ebp-10h] BYREF
  int v62; // [esp+48h] [ebp-Ch]
  int v63; // [esp+4Ch] [ebp-8h] BYREF
  int v64; // [esp+50h] [ebp-4h]

  if ( word_1998F8 )
  {
    if ( byte_199CAE == 4 )
    {
      v45[0] = word_178CA1;
      v46 = word_178CA3;
      v47 = word_178CA5;
      v0 = word_178CA7;
    }
    else
    {
      v45[0] = word_178CA9;
      v46 = word_178CAB;
      v47 = word_178CAD;
      v0 = word_178CAF;
    }
    v48 = v0;
    v1 = *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 37);
    v49[0] = 15;
    v49[1] = 22;
    v49[2] = 25;
    v49[3] = 30;
    v49[4] = 33;
    v49[5] = 33;
    sub_49ED1(word_1998F8, &v61, &v63);
    HIWORD(v2) = HIWORD(dword_192864);
    v3 = (uint8_t *)(dword_192864 + 313 * word_1998F8);
    LOWORD(v2) = v3[33];
    v2 *= 20;
    v61 += v2;
    LOWORD(v2) = v3[34];
    v63 += 20 * v2;
    v4 = v3[35];
    switch ( v3[35] )
    {
      case 0u:
      case 4u:
      case 8u:
      case 0xCu:
        v5 = (int)v3[35] >> 2;
        v6 = v5 % 4;
        v7 = v49[v1];
        v58[v6] = 0;
        v58[v6 + 4] = v7;
        v8 = (v5 + 1) % 4;
        v9 = v8;
        v58[v8 + 4] = 0;
        LOWORD(v8) = v49[v1];
        v58[v9] = v8;
        v10 = v8;
        v11 = (v5 + 2) % 4;
        v12 = -v10;
        v58[v11] = 0;
        v58[v11 + 4] = v12;
        v13 = (v5 + 3) % 4;
        v54 = 2000;
        v50 = 2000;
        v55 = -2000;
        v51 = -2000;
        v56 = 2000;
        v52 = -2000;
        v57 = -2000;
        v53 = 2000;
        v58[v13 + 4] = 0;
        goto LABEL_7;
      case 1u:
      case 5u:
      case 9u:
      case 0xDu:
        v23 = (int16_t)v49[v1];
        v24 = 23 * v23;
        v64 = 23 * v23 / 25;
        v25 = (int)(v4 - (__CFSHL__((uint64_t)v4 >> 32, 2) + 4 * ((uint64_t)v4 >> 32))) >> 2;
        v23 *= 19;
        v26 = v25 % 4;
        v58[v26 + 4] = v64;
        v59 = 50;
        v62 = -v23 / 50;
        v58[v26] = v62;
        v23 /= 50;
        v27 = (v25 + 1) % 4;
        v58[v27 + 4] = v23;
        v58[v27] = v64;
        v28 = -v24 / 25;
        v29 = (v25 + 2) % 4;
        v58[v29 + 4] = v28;
        v58[v29] = v23;
        v54 = 3827;
        v50 = -9239;
        v55 = -9239;
        v51 = -3827;
        v56 = -3827;
        v52 = 9239;
        v57 = 9239;
        v30 = (v25 + 3) % 4;
        v53 = 3827;
        v31 = v62;
        v58[v30] = v28;
        goto LABEL_12;
      case 2u:
      case 6u:
      case 0xAu:
      case 0xEu:
        v32 = v1;
        v33 = (int)v3[35] >> 2;
        v34 = v33 % 4;
        v35 = v33 % 4;
        LOWORD(v34) = v49[v1];
        v12 = -v34;
        v58[v35 + 4] = v34;
        v58[v35] = -(int16_t)v34;
        v36 = (v33 + 1) % 4;
        LOWORD(v34) = v49[v32];
        v58[v36 + 4] = v34;
        v58[v36] = v34;
        v37 = (v33 + 2) % 4;
        v58[v37 + 4] = v12;
        v58[v37] = v49[v32];
        v13 = (v33 + 3) % 4;
        v54 = 0;
        v50 = 2000;
        v55 = -2000;
        v51 = 0;
        v56 = 0;
        v52 = -2000;
        v57 = 2000;
        v53 = 0;
        v58[v13 + 4] = v12;
LABEL_7:
        v58[v13] = v12;
        break;
      case 3u:
      case 7u:
      case 0xBu:
      case 0xFu:
        v38 = (int16_t)v49[v1];
        v39 = 19 * v38;
        v64 = 19 * v38 / 50;
        v40 = (int)(v4 - (__CFSHL__((uint64_t)v4 >> 32, 2) + 4 * ((uint64_t)v4 >> 32))) >> 2;
        v38 *= 23;
        v41 = v40 % 4;
        v58[v41 + 4] = v64;
        v59 = 25;
        v60 = -v38 / 25;
        v58[v41] = v60;
        v38 /= 25;
        v42 = (v40 + 1) % 4;
        v58[v42 + 4] = v38;
        v58[v42] = v64;
        v43 = -v39 / 50;
        v44 = (v40 + 2) % 4;
        v58[v44 + 4] = v43;
        v58[v44] = v38;
        v54 = 9239;
        v50 = -3827;
        v55 = -3827;
        v51 = -9239;
        v56 = -9239;
        v52 = 3827;
        v57 = 3827;
        v30 = (v40 + 3) % 4;
        v53 = 9239;
        v31 = v60;
        v58[v30] = v43;
LABEL_12:
        v58[v30 + 4] = v31;
        break;
      default:
        break;
    }
    sub_120BB5(0, (int)&unk_17D879);
    for ( i = 0; i < 4; ++i )
    {
      v15 = v63 - 20 * word_1998F2;
      v16 = (int16_t)(v15 + *(&v50 + i));
      v17 = v61 - 20 * word_1998F0;
      v58[i + 4] -= 2;
      v18 = v17;
      v19 = *(&v54 + i);
      v58[i] -= 3;
      v59 = v18;
      sub_134D2D(v18, v15, (int16_t)(v18 + v19), v16, 84);
      v20 = &v45[2 * i];
      v21 = v63 + v58[i] - 20 * word_1998F2;
      v22 = v61 + v58[i + 4] - 20 * word_1998F0;
      sub_1212B3(v22, v21, (int)v20);
    }
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x33AFE je epilog funkce */
}
// 178CA1: using guessed type int16_t word_178CA1;
// 178CA3: using guessed type int16_t word_178CA3;
// 178CA5: using guessed type int16_t word_178CA5;
// 178CA7: using guessed type int16_t word_178CA7;
// 178CA9: using guessed type int16_t word_178CA9;
// 178CAB: using guessed type int16_t word_178CAB;
// 178CAD: using guessed type int16_t word_178CAD;
// 178CAF: using guessed type int16_t word_178CAF;
// 192864: using guessed type int dword_192864;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F8: using guessed type int16_t word_1998F8;
// 199CAE: using guessed type char byte_199CAE;


//----- (00032735) --------------------------------------------------------
void sub_32735()
{
  int v0; // edx
  uint8_t *v1; // eax
  int16_t i; // si
  int16_t v3; // dx
  int v4; // ecx
  int v5; // ebx
  int16_t v6; // [esp-4h] [ebp-34h]
  int16_t v7; // [esp+0h] [ebp-30h]
  int16_t v8; // [esp+2h] [ebp-2Eh]
  int16_t v9; // [esp+4h] [ebp-2Ch]
  int16_t v10; // [esp+6h] [ebp-2Ah]
  int16_t v11; // [esp+8h] [ebp-28h]
  int16_t v12; // [esp+Ah] [ebp-26h]
  int16_t v13; // [esp+Ch] [ebp-24h]
  int16_t v14; // [esp+Eh] [ebp-22h]
  int16_t v15; // [esp+10h] [ebp-20h]
  int16_t v16; // [esp+12h] [ebp-1Eh]
  int16_t v17; // [esp+14h] [ebp-1Ch]
  int16_t v18; // [esp+16h] [ebp-1Ah]
  int16_t v19; // [esp+18h] [ebp-18h]
  int16_t v20; // [esp+1Ah] [ebp-16h]
  int16_t v21; // [esp+1Ch] [ebp-14h]
  int16_t v22; // [esp+1Eh] [ebp-12h]
  _WORD v23[4]; // [esp+20h] [ebp-10h]
  int v24; // [esp+28h] [ebp-8h] BYREF
  int v25; // [esp+2Ch] [ebp-4h] BYREF

  v23[0] = 84;
  v23[1] = 135;
  v23[2] = 84;
  v23[3] = 135;
  sub_49ED1(word_1998F8, &v24, &v25);
  HIWORD(v0) = HIWORD(dword_192864);
  v1 = (uint8_t *)(dword_192864 + 313 * word_1998F8);
  LOWORD(v0) = v1[33] - word_1998F0;
  v0 *= 20;
  v24 += v0;
  LOWORD(v0) = v1[34] - word_1998F2;
  v25 += 20 * v0;
  switch ( v1[35] )
  {
    case 0u:
    case 4u:
    case 8u:
    case 0xCu:
      v15 = 2000;
      v7 = -3464;
      v16 = 2000;
      v8 = 3464;
      v17 = 3464;
      v9 = 2000;
      v18 = -3464;
      v10 = 2000;
      v19 = -2000;
      v11 = 3464;
      v20 = -2000;
      v12 = -3464;
      v21 = -3464;
      v13 = -2000;
      v22 = 3464;
      v14 = -2000;
      break;
    case 1u:
    case 5u:
    case 9u:
    case 0xDu:
      v15 = 522;
      v7 = -3966;
      v16 = 2435;
      v8 = 3173;
      v17 = 3966;
      v9 = 522;
      v18 = -3173;
      v10 = 2435;
      v19 = -522;
      v11 = 3966;
      v20 = -2435;
      v12 = -3173;
      v21 = -3966;
      v13 = -522;
      v22 = 3173;
      v14 = -2435;
      break;
    case 2u:
    case 6u:
    case 0xAu:
    case 0xEu:
      v15 = -1035;
      v7 = -3864;
      v16 = 3864;
      v8 = 1035;
      v17 = 3864;
      v9 = -1035;
      v18 = -1035;
      v10 = 3864;
      v19 = 1035;
      v11 = 3864;
      v20 = -3864;
      v12 = -1035;
      v21 = -3864;
      v13 = 1035;
      v22 = 1035;
      v14 = -3864;
      break;
    case 3u:
    case 7u:
    case 0xBu:
    case 0xFu:
      v15 = -2435;
      v7 = -3173;
      v16 = 3966;
      v8 = 522;
      v17 = 3173;
      v9 = -2435;
      v18 = 522;
      v10 = 3966;
      v19 = 2435;
      v11 = 3173;
      v20 = -3966;
      v12 = -522;
      v21 = -3173;
      v13 = 2435;
      v22 = -522;
      v14 = -3966;
      break;
    default:
      break;
  }
  for ( i = 0; i < 8; ++i )
  {
    v6 = v23[i / 2];
    v3 = v25 - 20 * word_1998F2;
    v4 = (int16_t)(v3 + *(&v7 + i));
    v5 = (int16_t)(v24 - 20 * word_1998F0 + *(&v15 + i));
    sub_134D2D((int16_t)(v24 - 20 * word_1998F0), v3, v5, v4, v6);
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x33AFE je epilog funkce */
}
// 192864: using guessed type int dword_192864;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (000329A4) --------------------------------------------------------
int sub_329A4( int a1, int a2, int a3)
{
  int v4; // ecx
  int *v5; // edx
  int v6; // eax
  int result; // eax
  int v8; // [esp+0h] [ebp-8h] BYREF
  int v9; // [esp+4h] [ebp-4h] BYREF

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v4 = a1;
  v5 = &v9;
  sub_49ED1(a1, &v9, &v8);
  HIWORD(v6) = HIWORD(dword_192864);
  LOWORD(v5) = *(uint8_t *)(313 * v4 + dword_192864 + 33);
  v9 += 20 * (_DWORD)v5;
  LOWORD(v6) = *(uint8_t *)(313 * v4 + dword_192864 + 34);
  v8 += 20 * v6;
  result = (int16_t)sub_1384B9((int16_t)(a2 - v9), (int16_t)(v8 - a3))
         - (22 * *(uint8_t *)(313 * v4 + dword_192864 + 35)
          + *(uint8_t *)(313 * v4 + dword_192864 + 35) / 2);
  if ( (result & 0x8000u) != 0 )
    result += 360;
  return result;
}
// 192864: using guessed type int dword_192864;


//----- (00032A20) --------------------------------------------------------
int sub_32A20( int a1, int a2)
{
  int v3; // esi
  int *v4; // edx
  int v5; // eax
  int v6; // eax
  int result; // eax
  int v8; // [esp+0h] [ebp-10h] BYREF
  int v9; // [esp+4h] [ebp-Ch] BYREF
  int v10; // [esp+8h] [ebp-8h] BYREF
  int v11; // [esp+Ch] [ebp-4h] BYREF

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v3 = 313 * a1;
  v4 = &v11;
  sub_49ED1(a1, &v11, &v10);
  HIWORD(v5) = HIWORD(dword_192864);
  LOWORD(v4) = *(uint8_t *)(v3 + dword_192864 + 33);
  v11 += 20 * (_DWORD)v4;
  LOWORD(v5) = *(uint8_t *)(v3 + dword_192864 + 34);
  v10 += 20 * v5;
  sub_49ED1(a2, &v9, &v8);
  HIWORD(v4) = HIWORD(dword_192864);
  v6 = dword_192864 + 313 * a2;
  LOWORD(v4) = *(uint8_t *)(v6 + 33);
  v9 += 20 * (_DWORD)v4;
  LOWORD(v6) = *(uint8_t *)(v6 + 34);
  v8 += 20 * v6;
  result = (int16_t)sub_1384B9((int16_t)(v9 - v11), (int16_t)(v10 - v8))
         - (*(uint8_t *)(v3 + dword_192864 + 35) / 2
          + 22 * *(uint8_t *)(v3 + dword_192864 + 35));
  if ( (result & 0x8000u) != 0 )
    result += 360;
  return result;
}
// 192864: using guessed type int dword_192864;


//----- (00032AD1) --------------------------------------------------------
char sub_32AD1( int a1)
{
  char result; // al

  result = 0;
  if ( a1 <= 60 || a1 >= 300 )
    result = 1;
  if ( a1 <= 120 || a1 >= 240 )
    result += 2;
  if ( a1 >= 60 && a1 <= 300 )
    result += 4;
  if ( a1 >= 120 && a1 <= 240 )
    result += 8;
  return result;
}


//----- (00032B26) --------------------------------------------------------
int sub_32B26( int a1, int a2, int a3, int a4)
{
  int16_t v4; // cx
  int v5; // eax
  int v6; // esi
  int v7; // edx
  char v8; // bh
  char v9; // bl
  int v10; // edx
  int v11; // ebx
  int v12; // edx
  int v13; // eax
  int v14; // esi
  int16_t v15; // bx
  _BYTE *v16; // edx
  int v17; // eax
  int result; // eax
  int16_t v19; // bx
  int16_t v21; // [esp+4h] [ebp-60h]
  int16_t v22; // [esp+8h] [ebp-5Ch]
  _BYTE v23[32]; // [esp+Ch] [ebp-58h] BYREF
  _BYTE v24[32]; // [esp+2Ch] [ebp-38h] BYREF
  char v25[16]; // [esp+4Ch] [ebp-18h] BYREF
  int v26; // [esp+5Ch] [ebp-8h]
  int v27; // [esp+60h] [ebp-4h]

  v21 = a3;   /* wave 181: v21 saved by the prologue (push ebx) */
  v22 = a1;   /* wave 181: v22 saved by the prologue (push eax) */
  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v4 = *(uint8_t *)(dword_192864 + 313 * a1 + 312);
  v27 = 4;
  HIWORD(v5) = HIWORD(dword_192864);
  v6 = dword_192864 + 313 * v22;
  LOWORD(v5) = *(uint8_t *)(v6 + 35);
  v26 = v5;
  if ( *(_DWORD *)(v6 + 198) && *(_BYTE *)(v6 + 32) == *(_BYTE *)(v6 + 312) )
  {
    v14 = *(_DWORD *)(v6 + 198);
  }
  else
  {
    v7 = 0;
    v8 = 96;
    v9 = 32;
    do
    {
      v23[(int16_t)v7] = v9;
      v24[(int16_t)v7++] = v8++;
      ++v9;
    }
    while ( (int16_t)v7 < 32 );
    if ( v4 >= 8 || (v10 = 313 * v22, *(_WORD *)(v10 + dword_192864 + 196) == 44) )
    {
      v13 = dword_192864 + 313 * v22;
      strcpy(v25, "monster.lbx");
      if ( *(_WORD *)(v13 + 196) == 44 )
      {
        v12 = 25;
        v11 = dword_193174;
      }
      else
      {
        v11 = dword_193174;
        v12 = *(int16_t *)(v13 + 196);
      }
    }
    else
    {
      strcpy(v25, "cmbtshp.lbx");
      v11 = dword_193174;
      v12 = 45 * *(uint8_t *)(3753 * v4 + (uint8_t*)dword_197F98 + 38) + *(int16_t *)(v10 + dword_192864 + 196);
    }
    v14 = sub_127C27((int)v25, v12, v11);
    v4 = 32;
    if ( *(uint8_t *)(313 * v22 + dword_192864 + 32) == word_1998AC )
    {
      v15 = 96;
      v16 = v23;
      v17 = v14;
    }
    else
    {
      v16 = v24;
      v17 = v14;
      v15 = 32;
    }
    sub_137D86(v17, (int)v16, v15, 32);
  }
  result = ((int16_t)v26 - 1 - (__CFSHL__(((int16_t)v26 - 1) >> 31, 2) + 4 * (((int16_t)v26 - 1) >> 31))) >> 2;
  if ( result <= 0 )
    result = 0;
  switch ( result )
  {
    case 0:
      sub_12B753(v14, (int16_t)v27 * (int16_t)v26);
      result = sub_12F578(dword_19283C, v14);
      break;
    case 1:
      sub_12B753(v14, (int16_t)v27 * (8 - (int16_t)v26));
      v19 = 0;
      sub_12F578(dword_192840, v14);
      goto LABEL_23;
    case 2:
      sub_12B753(v14, ((int16_t)v26 - 8) * (int16_t)v27);
      sub_12F578(dword_19283C, v14);
      sub_12DFB2(dword_192840, (int16_t *)dword_19283C, 0);
      v19 = 3;
      goto LABEL_23;
    case 3:
      sub_12B753(v14, (16 - (int16_t)v26) * (int16_t)v27);
      v19 = 3;
      sub_12F578(dword_192840, v14);
LABEL_23:
      result = (int)sub_12DFB2(dword_19283C, (int16_t *)dword_192840, v19);
      break;
    default:
      break;
  }
  if ( v21 )
    return sub_33DC3((int16_t *)dword_19283C, a4, v21, v4);
  return result;
}
// 19283C: using guessed type int dword_19283C;
// 192840: using guessed type int dword_192840;
// 192864: using guessed type int dword_192864;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 1998AC: using guessed type int16_t word_1998AC;


//----- (00032D94) --------------------------------------------------------
void sub_32D94( int a1)
{
  int v2; // eax
  int16_t v3; // cx
  int v4; // eax
  int *v5; // edx
  int v6; // edx
  int16_t v7; // ax
  uint16_t *v8; // eax
  uint16_t v9; // dx
  int16_t v10; // bx
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // edx
  int16_t v15; // bx
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int16_t v20; // di
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int v24; // ecx
  int v25; // eax
  int v26; // [esp+0h] [ebp-78h]
  int v27; // [esp+4h] [ebp-74h] BYREF
  int v28; // [esp+8h] [ebp-70h] BYREF
  int v29; // [esp+Ch] [ebp-6Ch]
  int v30; // [esp+10h] [ebp-68h] BYREF
  int v31; // [esp+14h] [ebp-64h]
  int v32; // [esp+18h] [ebp-60h] BYREF
  int v33; // [esp+1Ch] [ebp-5Ch]
  int v34; // [esp+20h] [ebp-58h]
  int v35; // [esp+24h] [ebp-54h]
  int *v36; // [esp+28h] [ebp-50h]
  int v37; // [esp+2Ch] [ebp-4Ch] BYREF
  int v38; // [esp+30h] [ebp-48h] BYREF
  hr_int128_t v39; // [esp+34h] [ebp-44h]
  int v40; // [esp+44h] [ebp-34h]
  int v41; // [esp+48h] [ebp-30h]
  int v42; // [esp+4Ch] [ebp-2Ch]
  int v43; // [esp+50h] [ebp-28h]
  int64_t v44; // [esp+54h] [ebp-24h]
  int64_t v45; // [esp+5Ch] [ebp-1Ch]
  int64_t v46; // [esp+64h] [ebp-14h]
  int v47; // [esp+6Ch] [ebp-Ch] BYREF
  int v48; // [esp+70h] [ebp-8h]
  int v49; // [esp+74h] [ebp-4h]

  v2 = 313 * a1;
  v29 = 33;
  LOWORD(v2) = *(uint8_t *)(dword_192864 + v2 + 32);
  v33 = 53;
  LODWORD(v45) = v2;
  if ( (_WORD)v2 == word_1998AC )
    v3 = 8;
  else
    v3 = 0;
  if ( (_WORD)v45 == word_1998AC )
    v4 = 28;
  else
    v4 = 31;
  v40 = v4;
  v49 = (int16_t)v4 / 3;
  v41 = ((int)((int16_t)v4
             - (__CFSHL__((uint64_t)(int16_t)v4 >> 32, 2)
              + 4 * ((uint64_t)(int16_t)v4 >> 32))) >> 2)
      + 1;
  v26 = 313 * a1;
  sub_49D09(*(uint8_t *)(v26 + dword_192864 + 33), *(uint8_t *)(v26 + dword_192864 + 34));
  v5 = &v27;
  sub_34543(a1, &v27, &v38);
  LOWORD(v5) = *(uint8_t *)(v26 + dword_192864 + 33);
  v5 = (int *)(20 * (_DWORD)v5);
  v36 = v5;
  LOWORD(v5) = *(uint8_t *)(v26 + dword_192864 + 34);
  v6 = 20 * (_DWORD)v5;
  HIDWORD(v44) = 0;
  v43 = 1;
  v7 = *(uint8_t *)(v26 + dword_192864 + 35);
  v34 = v6;
  if ( v3 != v7 )
    sub_3F628(a1, v3, (int16_t)((_WORD)v36 - 20 * word_1998F0), (int16_t)(v6 - 20 * word_1998F2));
  if ( !(uint16_t)Hook150_1E19E2(a1) )   /* 1.50 032EA1 */
  {
    v8 = (uint16_t *)sub_127C27((int)aCmbtsfxLbx_2, 42, dword_193174);
    v42 = *v8;
    v9 = v8[1];
    LOWORD(v8) = v8[3];
    DWORD2(v39) = v9;
    LODWORD(v39) = v8;
    sub_32B26(a1, 0, 0, 0);
    sub_131528((_WORD *)dword_19283C, (int16_t *)&v32, (int16_t *)&v28, &v37, &v47);
    word_1998FC = a1;
    sub_34543(a1, &v27, &v38);
    sub_124D41();
    if ( word_1998AC == (_WORD)v45 )
      v10 = v27 - ((int16_t)v37 / 2 + v40 + v42);
    else
      v10 = v27 + v40 + (int16_t)v37 / 2;
    v11 = (int16_t)v38 - SWORD4((int)LODWORD(v39)) / 2;
    if ( v10 >= 4 )
      v12 = v10;
    else
      v12 = 4;
    LODWORD(v44) = v12;
    if ( (int16_t)v12 + (int16_t)v42 > 639 )
      LODWORD(v44) = 630 - v42;
    if ( (int16_t)v11 >= 4 )
      v13 = (int16_t)v11;
    else
      v13 = 4;
    HIDWORD(v45) = v13;
    if ( (int16_t)v13 > 350 )
      HIDWORD(v45) = 346 - DWORD2(v39);
    v14 = HIDWORD(v45);
    v15 = v45;
    sub_8FD71(&v30);
    v16 = v33 + v14;
    if ( v15 == word_1998AC )
    {
      HIDWORD(v46) = v29 + v44;
      v35 = v37 + v27;
      v17 = v47 + v38;
      LODWORD(v46) = v16;
    }
    else
    {
      LODWORD(v46) = v16;
      v35 = v29 + v44 - 3;
      v17 = DWORD2(v39) + HIDWORD(v45);
      HIDWORD(v46) = v27 - v37;
    }
    DWORD1(v39) = v17;
    v18 = -2500 * (*(uint8_t *)(dword_192864 + 313 * a1 + 37) - 2);
    v19 = sub_147D7(52);
    sub_112CD9(v19, v18);
    if ( word_19987E == 1 || word_1998CE )
      v43 = 3;
    v31 = v43 * v49;
    v20 = 0;
    v48 = v43 * v41;
    while ( v20 < (int16_t)v39 )
    {
      if ( v20 >= 5 )
        v21 = v48;
      else
        v21 = v31;
      HIDWORD(v39) = v21;
      sub_12C2A0();
      sub_2F4EE();
      sub_12B634();
      sub_128AB6(0, 0, 639, 350);
      v23 = sub_127C27((int)aCmbtsfxLbx_2, 42, dword_193174);
      sub_12B753(v23, v20);
      v24 = SWORD2((int)LODWORD(v39));
      sub_12A478(v44, SWORD2(v45), v23);
      sub_128AB6(SWORD2(v46), v46, v35, v24);
      sub_30062(a1, v24, v26, v27);
      sub_1077D(0, 0, 0, 0);
      sub_12C2C6(1);
      if ( (_WORD)v45 == word_1998AC )
        HIDWORD(v44) -= HIDWORD(v39);
      else
        HIDWORD(v44) += HIDWORD(v39);
      v20 += v43;
    }
    sub_8FD56(v30);
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x33AFE je epilog funkce */
}
// 1077D: using guessed type int sub_1077D(_DWORD);
// 2F4EE: using guessed type int sub_2F4EE(_DWORD);
// 19283C: using guessed type int dword_19283C;
// 192864: using guessed type int dword_192864;
// 193174: using guessed type int dword_193174;
// 19987E: using guessed type int16_t word_19987E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (00033156) --------------------------------------------------------
_WORD *sub_33156( int a1, _WORD *a2, _WORD *a3)
{
  int16_t v4; // [esp+0h] [ebp-8h] BYREF
  int16_t v5; // [esp+4h] [ebp-4h] BYREF

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  sub_32B26(a1, 0, 0, 0);
  return sub_131528((_WORD *)dword_19283C, &v4, &v5, a2, a3);
}
// 19283C: using guessed type int dword_19283C;


//----- (00033199) --------------------------------------------------------
int sub_33199( int a1, int a2)
{
  int v3; // eax
  int16_t v4; // bx

  v3 = sub_58678(word_199A30);
  sub_12F578(dword_19283C, v3);
  sub_12D8F5(98, 98, dword_192824);
  sub_12F7E6(16, 11, (int16_t *)dword_19283C, (int16_t *)dword_192824);
  if ( byte_199A38 )
  {
    sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 1, 0);
    sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 2, 0);
    switch ( byte_199A38 )
    {
      case 1:
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 1, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 2, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B546, 0);
        v4 = (uint8_t)byte_19B548;
        goto LABEL_8;
      case 2:
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 1, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 2, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B545, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B546, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B547, 0);
        v4 = (uint8_t)byte_19B549;
        goto LABEL_8;
      case 3:
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 1, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 2, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B544, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B545, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B547, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B548, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B549, 0);
        v4 = (uint8_t)byte_19B54A;
        goto LABEL_8;
      case 4:
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, 1, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B544, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B545, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B546, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B547, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B548, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B549, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B54A, 0);
        v4 = (uint8_t)byte_19B54B;
        goto LABEL_8;
      case 5:
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B544, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B545, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B546, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B546, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B547, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B548, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B548, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B549, 0);
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, (uint8_t)byte_19B54A, 0);
        v4 = (uint8_t)byte_19B54B;
LABEL_8:
        sub_12E64F((int16_t *)dword_192824, (int16_t *)dword_192824, v4, 0);
        break;
      default:
        break;
    }
    sub_13719F(dword_192824, 1, 0);
    sub_13719F(dword_192824, 2, 0);
  }
  return sub_12A478(a1, a2, dword_192824);
}
// 192824: using guessed type int dword_192824;
// 19283C: using guessed type int dword_19283C;
// 199A30: using guessed type int16_t word_199A30;
// 199A38: using guessed type char byte_199A38;
// 19B544: using guessed type char byte_19B544;
// 19B545: using guessed type char byte_19B545;
// 19B546: using guessed type char byte_19B546;
// 19B547: using guessed type char byte_19B547;
// 19B548: using guessed type char byte_19B548;
// 19B549: using guessed type char byte_19B549;
// 19B54A: using guessed type char byte_19B54A;
// 19B54B: using guessed type char byte_19B54B;


//----- (00033543) --------------------------------------------------------
/* wave 184: written from asm 33543-33992 (Hex-Rays failed) - redraw of the combat map after scrolling */
void sub_33543(void)
{
  int16_t v_si; // esi
  int16_t v_bx; // ebx
  int16_t v_cx; // ecx
  int16_t v_n;  // si
  uint8_t *v_s;

  sub_128AB6(0, 0, 639, 350);
  sub_12B634();
  if ( !word_1998CA )
    sub_128C32(0, 0, 639, 350, 0);
  /* 3357E: the three background layers, each drawn four times for the wrap */
  dword_192858 = sub_127C27((int)aCombatLbx_0, word_1998CA == 1 ? 35 : 46, dword_193174);
  sub_12A478(word_199880, word_199882, dword_192858);
  sub_12A478((int16_t)(word_199880 - 640), word_199882, dword_192858);
  sub_12A478((int16_t)(word_199880 - 640), (int16_t)(word_199882 - 480), dword_192858);
  sub_12A478(word_199880, (int16_t)(word_199882 - 480), dword_192858);
  dword_192878 = sub_127C27((int)aCombatLbx_0, 47, dword_193174);   /* 33629 */
  sub_12A478(word_199886, word_199884, dword_192878);
  sub_12A478((int16_t)(word_199886 - 640), word_199884, dword_192878);
  sub_12A478((int16_t)(word_199886 - 640), (int16_t)(word_199884 - 480), dword_192878);
  sub_12A478(word_199886, (int16_t)(word_199884 - 480), dword_192878);
  dword_192888 = sub_127C27((int)aCombatLbx_0, 48, dword_193174);   /* 336C1 */
  sub_12A478(word_19988C, word_19988A, dword_192888);
  sub_12A478((int16_t)(word_19988C - 640), word_19988A, dword_192888);
  sub_12A478((int16_t)(word_19988C - 640), (int16_t)(word_19988A - 480), dword_192888);
  sub_12A478(word_19988C, (int16_t)(word_19988A - 480), dword_192888);
  sub_12B65C();
  sub_128BE7();
  if ( word_1998E4 == 1 )   /* 33763: the grid */
  {
    for ( v_si = 0; v_si < 640; v_si += 20 )
      sub_134D2D(v_si, 0, v_si, 350, 4);
    for ( v_si = 0; v_si < 360; v_si += 20 )
      sub_134D2D(0, v_si, 640, v_si, 4);
  }
  for ( v_bx = 0; v_bx < word_1998C0; ++v_bx )   /* 337AF */
  {
    v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * v_bx);
    if ( !v_s[36] && v_bx != word_1998FC && v_s[66] != 0xFF && (int16_t)v_s[66] != word_1998FC )
      sub_ACCDB(v_bx);
  }
  sub_128AB6(0, 0, 639, 350);   /* 337F4 */
  sub_12B634();
  for ( v_cx = 0; v_cx < word_1998C0; ++v_cx )
  {
    v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * v_cx);
    if ( !v_s[36] )
      sub_30062(
        v_cx,
        (int16_t)(20 * (int16_t)(v_s[33] - word_1998F0)),
        (int16_t)(20 * (int16_t)(v_s[34] - word_1998F2)),
        v_cx);
  }
  sub_3C834();   /* 3385C */
  sub_12B65C();
  sub_128BE7();
  if ( word_1998DA == 1 )
  {
    v_n = *(int16_t *)(intptr_t)(dword_192884 + 4);
    sub_12B726(dword_192884);
    for ( v_cx = 0; v_cx < v_n; ++v_cx )
      sub_12A478(500, 363, dword_192884);
    sub_12A478(500, 363, dword_192884);
    sub_12A478(529, 407, dword_192850);
  }
  else
  {
    sub_2F172();   /* 338CE */
    sub_2EF51();
  }
  if ( word_1998F4 != 666 )   /* 338D8 */
  {
    if ( word_1998D6 )
      sub_2E98D();
    else
      sub_2E2CD(-1, -1);
    sub_128EDE(401, 362, 489, 374, 0, 199);
    sub_128EDE(401, 379, 488, 467, 0, 199);
    sub_3459E(401, 379);
  }
  if ( !word_199876 )   /* 3394F */
  {
    sub_34921();
    dword_19284C = sub_127C27((int)aCombatLbx_0, 9, dword_193174);
    sub_12A478(248, 298, dword_19284C);
    sub_2F382();
  }
}


//----- (000339A7) --------------------------------------------------------
int sub_339A7( int a1, int a2, int a3)
{
  int v4; // eax
  int16_t v5; // cx
  int16_t v6; // si
  _BOOL1 v7; // al
  int16_t v8; // dx
  int16_t v9; // ax
  int v10; // eax
  uint8_t v11; // al
  int v12; // eax
  int16_t v14; // [esp+4h] [ebp-4h]

  v4 = dword_192864 + 313 * a1;
  v5 = *(uint8_t *)(v4 + 33);
  v6 = *(uint8_t *)(v4 + 34);
  v7 = sub_3D259(v5, v6);
  LOWORD(a3) = v7;
  if ( v7 )
  {
    if ( !a1 )
    {
      if ( word_19988E == 8 )
        v14 = 2;
      else
        v14 = *(uint8_t *)(17 * *(int16_t *)(361 * word_199878 + (uint8_t*)dword_192B18 + 2) + (uint8_t*)dword_1930D4 + 5);
      switch ( v14 )
      {
        case 0:
          v8 = v6 + 2;
          v9 = v5 + 2;
          goto LABEL_8;
        case 1:
          v8 = v6 + 3;
          v9 = v5 + 3;
          goto LABEL_8;
        case 2:
          v8 = v6 + 5;
          v9 = v5 + 5;
          goto LABEL_8;
        case 3:
          v8 = v6 + 6;
          v9 = v5 + 6;
          goto LABEL_8;
        case 4:
          v8 = v6 + 7;
          v9 = v5 + 7;
LABEL_8:
          LOWORD(v10) = sub_3D259(v9, v8);
          a3 &= v10;
          break;
        default:
          break;
      }
    }
    v11 = *(_BYTE *)(313 * a1 + dword_192864 + 37);
    if ( v11 )
    {
      if ( v11 <= 2u )
      {
        LOWORD(v12) = sub_3D259(v5 + 1, v6 + 1);
        return v12 & a3;
      }
      else if ( v11 <= 5u )
      {
        LOWORD(a3) = sub_3D259(v5 + 2, v6 + 2);
      }
    }
  }
  return a3;
}
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 1930D4: using guessed type int (uint8_t*)dword_1930D4;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;


//----- (00033B19) --------------------------------------------------------
int sub_33B19( int a1)
{
  int16_t v2; // cx
  int16_t v3; // si
  int16_t v4; // ax
  int16_t v5; // si
  int16_t v6; // cx
  uint8_t v7; // al
  int v8; // [esp+0h] [ebp-4h]
  int v9; // ebx

  v8 = 313 * (int16_t)a1;
  v2 = *(uint8_t *)(v8 + dword_192864 + 33);
  v3 = *(uint8_t *)(v8 + dword_192864 + 34);
  v9 = (uint8_t)sub_3D259(v2, v3);   /* wave 184: 33B4D movzx bx, al */
  if ( !(int16_t)a1 )
  {
    if ( word_19988E == 8 )
      v4 = 2;
    else
      v4 = *(uint8_t *)((uint8_t*)dword_1930D4 + 17 * *(int16_t *)((uint8_t*)dword_192B18 + 361 * word_199878 + 2) + 5);
    switch ( v4 )
    {
      case 0:
        goto LABEL_6;
      case 1:
        v5 = v3 + 3;
        v6 = v2 + 3;
        goto LABEL_7;
      case 2:
        v5 = v3 + 5;
        v6 = v2 + 5;
        goto LABEL_7;
      case 3:
        v5 = v3 + 6;
        v6 = v2 + 6;
        goto LABEL_7;
      case 4:
        v5 = v3 + 7;
        v6 = v2 + 7;
        goto LABEL_7;
      default:
        goto LABEL_17;
    }
  }
  v7 = *(_BYTE *)(v8 + dword_192864 + 37);
  if ( v7 )
  {
    if ( v7 <= 2u )
    {
      v5 = v3 + 1;
      v6 = v2 + 1;
    }
    else
    {
      if ( v7 > 5u )
        goto LABEL_17;
LABEL_6:
      v5 = v3 + 2;
      v6 = v2 + 2;
    }
LABEL_7:
    v9 |= (uint8_t)sub_3D259(v6, v5);   /* wave 184: 33BBA or ebx, eax */
  }
LABEL_17:
  return v9;   /* wave 184: 33AFC mov eax, ebx */
}
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 1930D4: using guessed type int (uint8_t*)dword_1930D4;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;


//----- (00033C05) --------------------------------------------------------
int sub_33C05( int a1)
{
  int v2; // eax
  int v3; // eax
  void *v4; // eax
  int16_t i; // ax
  int v6; // edx
  int v7; // ebx
  int v8; // eax

  sub_12779E(byte_199A12, (_BYTE *)(313 * a1 + dword_192864), 0x139u);
  word_1998D2 = a1;
  if ( !a1 )
    word_199B12 = -666;
  v2 = sub_124D41();
  word_1998F4 = 1;
  sub_2C6BA(v2);
  if ( word_1998D6 )
    sub_2E98D();
  else
    v3 = sub_2E2CD(-1, -1);
  sub_2F4EE();
  v4 = sub_124DEC();
  sub_1077D(v4, 0, 0, 0);
  sub_123E6C((int)unk_17CF00, 1);
  for ( i = 0; i < 81; ++i )
  {
    v6 = 0;
    do
    {
      v7 = (int16_t)v6++;
      word_18C9A8[68 * i + v7] = -1;
    }
    while ( (int16_t)v6 < 68 );
  }
  sub_31F25(-1);
  sub_465D0();
  sub_46CC8(word_1998F8, 1);
  sub_2C601(0, 1);
  return sub_1191CA((int)sub_2F4EE, 1);
}
// 1077D: using guessed type int sub_1077D(_DWORD);
// 2F4EE: using guessed type int sub_2F4EE(_DWORD);
// 18C9A8: using guessed type int16_t word_18C9A8[4979];
// 192864: using guessed type int dword_192864;
// 1998D2: using guessed type int16_t word_1998D2;
// 1998D6: using guessed type int16_t word_1998D6;
// 1998F4: using guessed type int16_t word_1998F4;
// 1998F8: using guessed type int16_t word_1998F8;
// 199B12: using guessed type int16_t word_199B12;


//----- (00033CFA) --------------------------------------------------------
int16_t *sub_33CFA( int a1)
{
  char v2[80]; // [esp+0h] [ebp-50h] BYREF

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  LOBYTE(word_18FF78) = 0;
  switch ( a1 )
  {
    case 0:
      sub_58F1E(31, v2, 80);
      sprintf(&word_18FF78, v2, 0);
      break;
    case 1:
      sub_58F1E(32, v2, 80);
      sprintf(&word_18FF78, v2, 100);
      break;
    case 2:
      sub_58F1E(33, v2, 80);
      sprintf(&word_18FF78, v2, 200);
      break;
    case 3:
      sub_58F1E(34, v2, 80);
      sprintf(&word_18FF78, v2, 300);
      break;
    case 4:
      sub_58F1E(35, v2, 80);
      sprintf(&word_18FF78, v2, 300);
      break;
    default:
      return &word_18FF78;
  }
  return &word_18FF78;
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 18FF78: using guessed type int16_t word_18FF78;


//----- (00033DC3) --------------------------------------------------------
int sub_33DC3(int16_t *a1, int a2, int a3, int a4)
{
  int v5; // ebx
  int result; // eax
  int v7; // edx
  int16_t v8; // bx
  int16_t v9; // di
  unsigned int v10; // esi
  int v11; // [esp+0h] [ebp-40h]
  char *v12; // [esp+8h] [ebp-38h]
  int v13; // [esp+Ch] [ebp-34h]
  int16_t v14; // [esp+18h] [ebp-28h]
  int16_t v15; // [esp+1Ch] [ebp-24h]
  int16_t v16; // [esp+20h] [ebp-20h]
  int16_t v18; // [esp+28h] [ebp-18h]
  int16_t v19; // [esp+2Ch] [ebp-14h]
  int16_t v20; // [esp+30h] [ebp-10h]
  int16_t v21; // [esp+34h] [ebp-Ch]
  int16_t v22; // [esp+3Ch] [ebp-4h]

  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  v5 = a2;
  sub_12B753(dword_192820, a2 % 16);
  v11 = dword_192820 + *(_DWORD *)(dword_192820 + 12 + 4 * *(int16_t *)(dword_192820 + 4));
  v12 = (char *)a1 + *(_DWORD *)&a1[2 * a1[2] + 6];
  v13 = (int)(a2 - (__CFSHL__((uint64_t)a2 >> 32, 2) + 4 * ((uint64_t)a2 >> 32))) >> 2;
  result = a2 / 3;
  v7 = a2 % 3;
  switch ( a3 )
  {
    case 0:
      return result;
    case 1:
      LOWORD(a4) = v13;
      if ( (int16_t)v13 <= 6 )
        break;
      goto LABEL_3;
    case 2:
      LOWORD(a4) = 6 - v13;
      goto LABEL_7;
    case 3:
LABEL_3:
      LOWORD(a4) = 6;
      break;
    case 4:
      a4 = v5 / 3;
      if ( (int16_t)result > 20 )
        LOWORD(a4) = 20;
      break;
    case 5:
      LOWORD(a4) = 12 - result;
LABEL_7:
      if ( (a4 & 0x8000u) != 0 )
        LOWORD(a4) = 0;
      break;
    default:
      result = (int)a1 + *(_DWORD *)&a1[2 * a1[2] + 6];
      v7 = dword_192820 + *(_DWORD *)(dword_192820 + 12 + 4 * *(int16_t *)(dword_192820 + 4));
      break;
  }
  if ( (_WORD)a4 )
  {
    LOWORD(v7) = *(_WORD *)dword_192820;
    v22 = *(_WORD *)(dword_192820 + 2);
    v16 = *a1;
    v21 = a1[1];
    v8 = 0;
    v15 = *(_WORD *)dword_192820;
    v20 = 0;
    result = 0;
    v19 = 0;
    while ( v8 < v21 )
    {
      if ( v8 < v22 )
      {
        v14 = 0;
        v9 = v19;
        v18 = v20;
        while ( v14 < v16 )
        {
          if ( v14 < v15 )
          {
            if ( (int16_t)a4 >= 5 )
              v10 = (int16_t)a4 + *(uint8_t *)(v11 + v9) - 4;
            else
              v10 = (*(uint8_t *)(v11 + v9) * (int16_t)a4) >> 2;
            if ( v10 > 0xF )
              v10 = 15;
            v12[v18] = byte_18C1A8[16 * (uint8_t)v12[v18] + v10];
          }
          ++v18;
          ++v14;
          ++v9;
        }
      }
      v20 += v16;
      result = v7;
      ++v8;
      v19 += v7;
    }
  }
  return result;
}
// 192820: using guessed type int dword_192820;


//----- (00033F60) --------------------------------------------------------
int sub_33F60( int a1, int a2, int a3, int a4)
{
  _BOOL1 v6; // cl
  int16_t v7; // ax
  int i; // edx
  int16_t v9; // ax
  int16_t v10; // ax
  int16_t v11; // si
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // eax
  int16_t v18; // si
  int v19; // eax
  int v20; // ebx
  int v21; // eax
  int v23; // [esp+0h] [ebp-38h]
  int v24; // [esp+8h] [ebp-30h] BYREF
  int v25; // [esp+Ch] [ebp-2Ch] BYREF
  int v26; // [esp+10h] [ebp-28h] BYREF
  int v27; // [esp+14h] [ebp-24h]
  int v28; // [esp+18h] [ebp-20h]
  int v29; // [esp+1Ch] [ebp-1Ch] BYREF
  int v30; // [esp+20h] [ebp-18h]
  int v31; // [esp+24h] [ebp-14h]
  int v32; // [esp+28h] [ebp-10h]
  int v33; // [esp+2Ch] [ebp-Ch] BYREF
  int v34; // [esp+30h] [ebp-8h] BYREF
  char v35; // [esp+34h] [ebp-4h]

  a3 = (int16_t)a3;   /* wave 181: the original reads only the low word (movsx) */
  v27 = a2;
  v35 = word_17F815[14 * a3] & 0x80;
  v6 = sub_4B0D3(a1, 35);
  if ( word_19987E || word_1998CE )
    v32 = 12;
  else
    v32 = 6;
  if ( !(uint16_t)sub_339A7(a1, 35, a1) )
    sub_49D09(*(uint8_t *)(dword_192864 + 313 * a1 + 33), *(uint8_t *)(dword_192864 + 313 * a1 + 34));
  sub_34543(v27, &v29, &v33);
  if ( v6 )
  {
    v23 = *(int16_t *)(dword_19285C + 2) / 2 * (*(int16_t *)(dword_19285C + 2) / 2)
        + *(int16_t *)dword_19285C / 2 * (*(int16_t *)dword_19285C / 2);
    sub_34543(a1, &v25, &v34);
    v7 = sub_134637(v25, v34, v29, v33);
    v28 = v25;
    v31 = v34;
    for ( i = v7 * v7; i > v23 + 3600; i = v9 * v9 )
    {
      sub_1344B0((int16_t *)&v25, (int16_t *)&v34, v28, v31, v29, v33, 20);
      v9 = sub_134637(v25, v34, v29, v33);
    }
    sub_AD7F5(a1, (int16_t)v25, (int16_t)v34);
  }
  else
  {
    sub_34543(a1, &v25, &v34);
  }
  v10 = sub_3F5F1(v25, v34, v29, v33);
  if ( v35 )
    v11 = v10 + 160;
  else
    v11 = v10 + 144;
  v12 = sub_124D7A();
  sub_2C6BA(v12);
  v24 = v25;
  v26 = v34;
  while ( (_WORD)v24 != (_WORD)v29 || (_WORD)v26 != (_WORD)v33 )
  {
    sub_12C2A0();
    v13 = sub_124D41();
    sub_2F4EE();
    sub_128AB6(0, 0, 639, 350);
    sub_12B634();
    sub_1344B0((int16_t *)&v24, (int16_t *)&v26, v25, v34, v29, v33, v32);
    v14 = sub_127C27((int)aCmbtmislLbx_0, v11, dword_193174);
    v15 = sub_12A478(v24 - 17, v26 - 17, v14);
    sub_1077D(v15, 0, 0, 0);
    sub_12C2C6(1);
  }
  if ( v35 )
    sub_A943A(v29, v26, 1, a4);   /* 341B4: same registers as the sub_A9412 call */
  else
    sub_A9412(v29, v26, 1, a4);
  v16 = sub_147D7(24);
  v17 = sub_127C27((int)aCmbtsfxLbx_2, 7, dword_193174);
  LOWORD(v17) = *(_WORD *)(v17 + 6);
  v18 = 0;
  v30 = v17;
  while ( v18 < (int16_t)v30 )
  {
    sub_12C2A0();
    v19 = sub_124D41();
    sub_2F4EE();
    sub_128AB6(0, 0, 639, 350);
    sub_12B634();
    v20 = sub_127C27((int)aCmbtsfxLbx_2, 7, dword_193174);
    sub_12B753(v20, v18);
    sub_12A478(v29 - 12, v33 - 12, v20);
    sub_A9223();
    sub_1077D(0, 0, 0, 0);
    ++v18;
    sub_12C2C6(1);
  }
  sub_A94A1();
  return sub_112C96(v16, 10);
}
// 1077D: using guessed type int sub_1077D(_DWORD);
// 2F4EE: using guessed type int sub_2F4EE(_DWORD);
// AD7F5: using guessed type int sub_AD7F5(_DWORD, _DWORD, _DWORD);
// 17F815: using guessed type int16_t word_17F815[];
// 19285C: using guessed type int dword_19285C;
// 192864: using guessed type int dword_192864;
// 193174: using guessed type int dword_193174;
// 19987E: using guessed type int16_t word_19987E;
// 1998CE: using guessed type int16_t word_1998CE;


//----- (00034286) --------------------------------------------------------
void sub_34286()
{
  int16_t v0; // cx
  int16_t v1; // bx
  char v2; // dl
  int v3; // eax
  int16_t v4; // cx
  int16_t v5; // bx
  char v6; // dl
  int v7; // eax
  int16_t v8; // cx
  int16_t v9; // bx
  char v10; // dl
  int v11; // eax
  int16_t v12; // cx
  int16_t i; // bx
  int v14; // eax
  int v15; // edx
  int16_t v16; // cx
  int16_t j; // bx
  int v18; // eax
  char v19; // dl
  int16_t v20; // cx
  int16_t v21; // bx
  char v22; // dl
  int v23; // eax
  int16_t v24; // cx
  int16_t v25; // bx
  char v26; // dl
  int v27; // eax

  v0 = 0;
  while ( 1 )
  {
    v1 = 0;
    v2 = v0;
    do
    {
      v3 = 16 * v0 + v1;
      byte_18C1A8[v3] = v2;
      if ( (uint8_t)v2 > 0x20u )
        byte_18C1A8[v3] = 0;
      ++v1;
      v2 -= 2;
    }
    while ( v1 < 16 );
    if ( ++v0 >= 32 )
    {
      v4 = 32;
      while ( 1 )
      {
        v5 = 0;
        v6 = v4;
        do
        {
          v7 = 16 * v4 + v5;
          byte_18C1A8[v7] = v6;
          if ( (uint8_t)v6 < 0x20u )
            byte_18C1A8[v7] = 0;
          ++v5;
          --v6;
        }
        while ( v5 < 16 );
        if ( ++v4 >= 48 )
        {
          v8 = 48;
          while ( 1 )
          {
            v9 = 0;
            v10 = v8;
            do
            {
              v11 = v9 + 16 * v8;
              byte_18C1A8[v11] = v10;
              if ( (uint8_t)v10 < 0x30u )
                byte_18C1A8[v11] = 0;
              ++v9;
              --v10;
            }
            while ( v9 < 16 );
            if ( ++v8 >= 64 )
            {
              v12 = 64;
              while ( 1 )
              {
                for ( i = 0; i < 16; ++i )
                {
                  v14 = i + 16 * v12;
                  v15 = v12 - i / 2;
                  byte_18C1A8[v14] = v15;
                  if ( (uint8_t)v15 < 0x40u )
                    byte_18C1A8[v14] = 0;
                }
                if ( ++v12 >= 72 )
                {
                  v16 = 72;
                  while ( 1 )
                  {
                    for ( j = 0; j < 16; ++j )
                    {
                      v18 = j + 16 * v16;
                      v19 = v16 - j / 2;
                      byte_18C1A8[v18] = v19;
                      if ( (uint8_t)v19 < 0x48u )
                        byte_18C1A8[v18] = 0;
                    }
                    if ( ++v16 >= 80 )
                    {
                      v20 = 96;
                      while ( 1 )
                      {
                        v21 = 0;
                        v22 = v20;
                        do
                        {
                          v23 = v21 + 16 * v20;
                          byte_18C1A8[v23] = v22;
                          if ( (uint8_t)v22 < 0x60u )
                            byte_18C1A8[v23] = 0;
                          ++v21;
                          --v22;
                        }
                        while ( v21 < 16 );
                        if ( ++v20 >= 112 )
                        {
                          v24 = 112;
                          while ( 1 )
                          {
                            v25 = 0;
                            v26 = v24;
                            do
                            {
                              v27 = v25 + 16 * v24;
                              byte_18C1A8[v27] = v26;
                              if ( (uint8_t)v26 < 0x70u )
                                byte_18C1A8[v27] = 0;
                              ++v25;
                              --v26;
                            }
                            while ( v25 < 16 );
                            if ( ++v24 >= 128 )
                              return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x33AFE je epilog funkce */
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}


//----- (00034454) --------------------------------------------------------
char sub_34454_131( int a1, _WORD *a2, _WORD *a3)
{
  int v3; // eax
  int v4; // eax
  int16_t v5; // si
  unsigned int v6; // eax

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  *a2 = 0;
  *a3 = 0;
  if ( a1 )
  {
    v4 = 313 * a1;
    v5 = *(uint8_t *)(dword_192864 + v4 + 35);
    v6 = (*(uint8_t *)(dword_192864 + v4 + 37) + 1) / 2;
    if ( v6 )
    {
      if ( v6 <= 1 )
      {
        *a2 = -6;
        *a3 = -6;
      }
      else if ( v6 <= 3 )
      {
        *a2 = 4;
        *a3 = 4;
      }
    }
    else
    {
      *a2 = -16;
      *a3 = -16;
    }
    v3 = (v5 - 1 - (__CFSHL__((v5 - 1) >> 31, 2) + 4 * ((v5 - 1) >> 31))) >> 2;
    if ( v3 <= 0 )
      v3 = 0;
    switch ( v3 )
    {
      case 1:
        *a2 -= 2;
        break;
      case 2:
        *a2 -= 2;
        goto LABEL_19;
      case 3:
LABEL_19:
        --*a3;
        break;
      default:
        break;
    }
    *a2 -= 2;
    *a3 -= 3;
  }
  else
  {
    *a2 = 0;
    *a3 = 0;
    LOBYTE(v3) = word_199878;
    if ( word_199878 == -1 )
    {
      *a2 = 9;
    }
    else
    {
      LOBYTE(v3) = *(_BYTE *)((uint8_t*)dword_1930D4 + 17 * *(int16_t *)((uint8_t*)dword_192B18 + 361 * word_199878 + 2) + 5);
      if ( (_BYTE)v3 != 2 )
        return v3;
      *a2 = 9;
    }
    *a3 = 7;
  }
  return v3;
}
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int (uint8_t*)dword_192B18;
// 1930D4: using guessed type int (uint8_t*)dword_1930D4;
// 199878: using guessed type int16_t word_199878;


//----- (00034543) --------------------------------------------------------
int sub_34543( int a1, _WORD *a2, _WORD *a3)
{
  int v3; // edi
  int v4; // eax
  int result; // eax
  int v6; // [esp+0h] [ebp-8h] BYREF
  int v7; // [esp+4h] [ebp-4h] BYREF

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v3 = 313 * a1;
  sub_49ED1(a1, &v6, &v7);
  v4 = dword_192864;
  *a2 = 20 * (*(uint8_t *)(v3 + dword_192864 + 33) - word_1998F0) + v6;
  LOWORD(v4) = *(uint8_t *)(v3 + v4 + 34) - word_1998F2;
  result = 20 * v4;
  *a3 = result + v7;
  return result;
}
// 192864: using guessed type int dword_192864;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;


//----- (0003459E) --------------------------------------------------------
void sub_3459E(int a1, int a2)
{
  int v3; // ecx
  int v4; // ecx
  int16_t v5; // si
  int v6; // edi
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  char v10[80]; // [esp+0h] [ebp-2Eh] BYREF
  _BYTE v11[80]; // [esp+50h] [ebp+22h] BYREF
  int v12; // [esp+A0h] [ebp+72h]
  int v13; // [esp+A4h] [ebp+76h]
  int v14; // [esp+A8h] [ebp+7Ah]
  int v15; // [esp+ACh] [ebp+7Eh]

  v14 = a2;
  if ( word_1998F8 )
  {
    sub_120CCB(2, (int)&unk_17D879);
    sub_120DED(0, 0);
    sub_58F1E(36, v10, 80);
    sub_1210FD(445, 362, (int)v10);
    sub_120CCB(1, (int)&unk_17D879);
    sub_120DED(0, 0);
    v3 = a2 + 4;
    v13 = a1 + 4;
    if ( *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 49) )
    {
      sub_58F1E(14, v10, 80);
      sub_1212B3(v13, v3, (int)v10);
      itoa(*(int16_t *)(dword_192864 + 313 * word_1998F8 + 256), v11, 10, v3);
      sub_1210B7(a1 + 85, v3, (int)v11);
    }
    else
    {
      sub_58F1E(37, v10, 80);
      sub_1212B3(v13, v3, (int)v10);
    }
    v4 = a2 + 14;
    v15 = a1 + 4;
    if ( *(_BYTE *)(313 * word_1998F8 + dword_192864 + 38) )
    {
      sub_58F1E(39, v10, 80);
      sub_1212B3(v15, v4, (int)v10);
      itoa(*(int16_t *)(313 * word_1998F8 + dword_192864 + 308), v11, 10, v4);
      sub_1210B7(a1 + 85, v4, (int)v11);
    }
    else
    {
      sub_58F1E(38, v10, 80);
      sub_1212B3(v15, v4, (int)v10);
    }
    sub_58F1E(21, v10, 80);
    v12 = (int16_t)(a2 + 24);
    v5 = a1 + 4;
    sub_1212B3(a1 + 4, a2 + 24, (int)v10);
    v6 = (int16_t)(a1 + 85);
    itoa(*(int16_t *)(313 * word_1998F8 + dword_192864 + 258), v11, 10, a2 + 24);
    sub_1210B7(v6, v12, (int)v11);
    sub_58F1E(16, v10, 80);
    v12 = (int16_t)(a2 + 34);
    sub_1212B3(v5, a2 + 34, (int)v10);
    itoa(
      *(int16_t *)(313 * word_1998F8 + dword_192864 + 170) - *(int16_t *)(313 * word_1998F8 + dword_192864 + 192),
      v11,
      10,
      a2 + 34);
    sub_1210B7(v6, v12, (int)v11);
    sub_58F1E(18, v10, 80);
    v7 = (int16_t)(a2 + 44);
    sub_1212B3(v5, v7, (int)v10);
    itoa(*(int16_t *)(dword_192864 + 313 * word_1998F8 + 194), v11, 10, v7);
    sub_1210B7(v6, v7, (int)v11);
    sub_58F1E(40, v10, 80);
    v8 = (int16_t)(v14 + 64);
    sub_1212B3(v5, v14 + 64, (int)v10);
    sub_121153(v6, v8, *(int16_t *)(313 * word_1998F8 + dword_192864 + 59), v8);
    sub_58F1E(90, v10, 80);
    v9 = (int16_t)(v14 + 75);
    sub_1212B3(v5, v14 + 75, (int)v10);
    sub_121153(v6, v9, *(int16_t *)(313 * word_1998F8 + dword_192864 + 61), v9);
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x2E981 je epilog funkce */
}
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 192864: using guessed type int dword_192864;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (00034921) --------------------------------------------------------
int sub_34921()
{
  int16_t v0; // dx
  int16_t v1; // ax
  int v2; // ebx

  sub_12B753(dword_192818, 1 - word_1998D6);
  sub_12A478(114, 361, dword_192818);
  sub_12B753(dword_192848, word_1998D6);
  sub_12A478(187, 361, dword_192848);
  if ( word_199876 == 1 )
  {
    sub_12B753(dword_19286C, word_199900);
    sub_12A478(273, 364, dword_19286C);
    sub_12B753(dword_192874, word_1998D4);
    sub_12A478(337, 364, dword_192874);
    sub_12B726(dword_192860);
    sub_12A478(273, 392, dword_192860);
    sub_12B726(dword_192870);
    sub_12A478(337, 392, dword_192870);
    sub_12B726(dword_192838);
    sub_12A478(273, 420, dword_192838);
    sub_12B726(dword_192830);
    sub_12A478(337, 420, dword_192830);
    sub_12B753(dword_192828, 0);
    v0 = 448;
    v1 = 298;
    v2 = dword_192828;
  }
  else
  {
    sub_2F382();
    sub_12B753(dword_192828, 0);
    sub_12A478(298, 301, dword_192828);
    sub_12B753(dword_19281C, 0);
    v0 = 348;
    v1 = 284;
    v2 = dword_19281C;
  }
  return sub_12A478(v1, v0, v2);
}
// 192818: using guessed type int dword_192818;
// 19281C: using guessed type int dword_19281C;
// 192828: using guessed type int dword_192828;
// 192830: using guessed type int dword_192830;
// 192838: using guessed type int dword_192838;
// 192848: using guessed type int dword_192848;
// 192860: using guessed type int dword_192860;
// 19286C: using guessed type int dword_19286C;
// 192870: using guessed type int dword_192870;
// 192874: using guessed type int dword_192874;
// 199876: using guessed type int16_t word_199876;
// 1998D4: using guessed type int16_t word_1998D4;
// 1998D6: using guessed type int16_t word_1998D6;
// 199900: using guessed type int16_t word_199900;


//----- (00034AB6) --------------------------------------------------------
void sub_34AB6()
{
  int16_t v0; // ax
  uint8_t v1; // al
  int16_t i; // si
  int16_t j; // di
  int16_t v4; // dx
  int16_t v5; // ax
  int16_t v6; // cx
  int16_t v7; // [esp+Ch] [ebp-8h]
  int16_t v8; // [esp+10h] [ebp-4h]

  if ( word_1998F8 )
  {
    if ( *(int16_t *)(313 * word_1998F8 + dword_192864 + 61) > 0
      || (sub_4B0D3(word_1998F8, 33) || sub_4B0D3(word_1998F8, 22)) && !(int16_t)sub_38876((int16_t)word_1998F8) )   /* 34B1E test ax, ax */
    {
      v1 = *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 37);
      if ( v1 )
      {
        if ( v1 <= 2u )
        {
          v8 = 40;
          v7 = 40;
        }
        else if ( v1 <= 5u )
        {
          v8 = 60;
          v7 = 60;
        }
      }
      else
      {
        v8 = 20;
        v7 = 20;
      }
      for ( i = word_1998F0; i < word_1998F0 + 32; ++i )
      {
        for ( j = word_1998F2; j < word_1998F2 + 18; ++j )
        {
          if ( word_18C9A8[68 * i + j] == 2000 )
          {
            v4 = 20 * (i - word_1998F0);
            v5 = 20 * (j - word_1998F2);
            v6 = v5 + v7;
            if ( word_1998CA == 1 )
              sub_128C32(v4, v5, (int16_t)(v4 + v8), v6, 0);
            else
              sub_128C32(v4, v5, (int16_t)(v4 + v8), v6, 129);
          }
        }
      }
    }
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x33AFE je epilog funkce */
}
// 34BCB: v7 (stack slot) is unset on one path - the original reads the same uninitialized slot there
// 34BCD: v8 (stack slot) is unset on one path - the original reads the same uninitialized slot there
// 18C9A8: using guessed type int16_t word_18C9A8[4979];
// 192864: using guessed type int dword_192864;
// 1998CA: using guessed type int16_t word_1998CA;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (00034C42) --------------------------------------------------------
void sub_34C42(int a1, int a2)
{
  int16_t v2; // si
  int16_t v3; // di
  int v4; // eax
  int v5; // eax
  void *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int16_t v12; // [esp+0h] [ebp-4h]

  if ( word_199876 )
  {
    v7 = sub_124D7A();
    sub_2C6BA(v7);
    sub_2F4EE();
    sub_34921();
    sub_124E36();
    sub_124D41();
    v2 = 298;
    v3 = 445;
    a2 = 298;
    dword_19284C = sub_127C27((int)aCombatLbx_0, 9, dword_193174);
    v12 = 7;
    v9 = sub_12A478(248, 298, dword_19284C);
    sub_1077D(v9, 0, 0, 0);
  }
  else
  {
    v2 = 445;
    v3 = 298;
    v12 = -7;
    word_199876 = 1;
    v4 = sub_124D7A();
    sub_2C6BA(v4);
    sub_2F4EE();
    sub_34921();
    v6 = sub_124E36();
    sub_1077D(v6, 0, 0, 0);
    word_199876 = 0;
  }
  sub_1172D4();
  while ( v2 != v3 )
  {
    v2 += v12;
    if ( v12 < 0 && v2 < v3 || v12 > 0 && v2 > v3 )
      v2 = v3;
    sub_124D41();
    sub_12B753(dword_192818, 1 - word_1998D6);
    sub_12A478(114, 361, dword_192818);
    sub_12B753(dword_192848, word_1998D6);
    sub_12A478(187, 361, dword_192848);
    sub_128AB6(0, 0, 639, 479);
    sub_12B634();
    dword_19284C = sub_127C27((int)aCombatLbx_0, 9, dword_193174);
    sub_12A478(248, v2, dword_19284C);
    sub_12B753(dword_19282C, word_1998C4);
    sub_12A478(267, v2 + 88, dword_19282C);
    sub_12B753(dword_19282C, word_19987E);
    sub_12A478(267, v2 + 104, dword_19282C);
    sub_12B753(dword_19282C, word_1998EE);
    sub_12A478(267, v2 + 120, dword_19282C);
    sub_12B753(dword_19282C, word_1998CC);
    sub_12A478(267, v2 + 136, dword_19282C);
    sub_12B753(dword_19282C, word_1998E4);
    a2 = (int16_t)(v2 + 152);
    sub_12A478(267, a2, dword_19282C);
    sub_12B65C();
    LOWORD(v10) = sub_128BE7();
    sub_1077D(0, 0, 0, 0);
  }
  sub_465D0();
  sub_46CC8(word_1998F8, a2);
  sub_1172FC();
  sub_2C601(0, a2);
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x33AFE je epilog funkce */
}
// 1077D: using guessed type int sub_1077D(_DWORD);
// 2F4EE: using guessed type int sub_2F4EE(_DWORD);
// 192818: using guessed type int dword_192818;
// 19282C: using guessed type int dword_19282C;
// 192848: using guessed type int dword_192848;
// 19284C: using guessed type int dword_19284C;
// 193174: using guessed type int dword_193174;
// 199876: using guessed type int16_t word_199876;
// 19987E: using guessed type int16_t word_19987E;
// 1998C4: using guessed type int16_t word_1998C4;
// 1998CC: using guessed type int16_t word_1998CC;
// 1998D6: using guessed type int16_t word_1998D6;
// 1998E4: using guessed type int16_t word_1998E4;
// 1998EE: using guessed type int16_t word_1998EE;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (00034EC8) --------------------------------------------------------
void sub_34EC8()
{
  int v0; // eax
  int v1; // ecx

  sub_120BB5(2, (int)&unk_17D879);
  v0 = sub_127C27((int)aCombatLbx_3, 36, dword_193174);
  sub_12A478(150, 100, v0);
  v1 = dword_19B554;
  sub_103915(2, 165, 153, dword_19B554, 261);   /* wave 182: 0x34F18 */
  sub_121199(182, 231, word_19B570, v1);
  sub_121199(296, 231, word_19B56E, v1);
  sub_121199(408, 231, word_19B56C, v1);
  sub_128C32(186, 253, (int16_t)(216 * (word_19B56E - word_19B570) / (word_19B56C - word_19B570) + 185), 263, 193);
  sub_134D2D((int16_t)(216 * (word_19B56E - word_19B570) / (word_19B56C - word_19B570) + 186), 253,
             (int16_t)(216 * (word_19B56E - word_19B570) / (word_19B56C - word_19B570) + 186), 263, 0);   /* wave 184: 34FBE jmp 2F166 */
}
// 103915: using guessed type _DWORD sub_103915(int16_t);
// 193174: using guessed type int dword_193174;
// 19B554: using guessed type int dword_19B554;
// 19B56C: using guessed type int16_t word_19B56C;
// 19B56E: using guessed type int16_t word_19B56E;
// 19B570: using guessed type int16_t word_19B570;


//----- (00034FC3) --------------------------------------------------------
int sub_34FC3( int a1, int a2, int a3, _WORD *a4)
{
  int v5; // eax
  int v6; // eax
  void *v7; // eax
  int16_t v8; // di
  void *v9; // ebx
  char *v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int16_t v17; // [esp+0h] [ebp-1Ch]
  int16_t v19; // [esp+8h] [ebp-14h]
  uint16_t v20; // [esp+Ch] [ebp-10h]
  uint16_t v21; // [esp+10h] [ebp-Ch]
  uint16_t v22; // [esp+14h] [ebp-8h]
  int v23; // [esp+18h] [ebp-4h]

  v17 = a1;   /* wave 181: v17 saved by the prologue (push eax) */
  word_19B570 = a1;
  word_19B56C = a2;
  word_19B56E = a2;
  dword_19B554 = a3;
  sub_1112EC(dword_192ED4, 6);
  dword_19B558 = (int)sub_126B42((int)aCombatLbx_3, 6, dword_192ED4);
  dword_19B560 = (int)sub_126B42((int)aCombatLbx_3, 40, dword_192ED4);
  dword_19B564 = (int)sub_126B42((int)aCombatLbx_3, 39, dword_192ED4);
  dword_19B55C = (int)sub_126B42((int)aCombatLbx_3, 41, dword_192ED4);
  v5 = sub_124D7A();
  sub_2C6BA(v5);
  sub_2F4EE();
  sub_1174CB();
  v7 = sub_124E36();
  sub_1077D(v7, 0, 0, 0);
  sub_119281();
  sub_1191CA((int)sub_34EC8, 1);
  sub_11C2F0();
  v23 = 1;
  v8 = 0;
  sub_115478(187, 249, v17, a2 + 1, v17, a2, 207, 13, (int)&word_19B56E, &unk_178CA0, 0);
  v20 = (uint16_t)sub_1151B0(164, 253, (int)&unk_178CA0, (_WORD *)dword_19B558, &unk_178CA0, 0);
  v21 = (uint16_t)sub_1151B0(406, 253, (int)&unk_178CA0, (_WORD *)dword_19B560, &unk_178CA0, 0);
  v9 = &unk_178CA0;
  v22 = (uint16_t)sub_1151B0(163, 273, (int)&unk_178CA0, (_WORD *)dword_19B564, &unk_178CA0, 0);
  v10 = sub_1151B0(345, 273, (int)&unk_178CA0, (_WORD *)dword_19B55C, &unk_178CA0, 0);
  v11 = 1;
  v19 = sub_114C72(asc_178CD5, 1);
  sub_124D41();
  sub_34EC8();
  sub_1077D(0, 0, 0, 0);
  LOWORD(v13) = sub_123E6C((int)unk_17CF00, 1);
  while ( 1 )
  {
    v9 = (void *)sub_1171AB(0, v11, (int)v9, (int)v10);
    v11 = (int)v9;
    sub_114177();
    if ( (_WORD)v9 == (_WORD)v10 )
    {
      v8 = 1;
      v23 = 2;
    }
    if ( (_WORD)v9 == v22 )
    {
      v8 = 1;
      v23 = 1;
    }
    if ( (_WORD)v9 == v21 && a2 > word_19B56E )
      ++word_19B56E;
    if ( (_WORD)v9 == v20 && word_19B56E > 0 )
      --word_19B56E;
    if ( (_WORD)v9 == v19 )
    {
      v23 = 0;
      v8 = 1;
    }
    if ( v8 )
      break;
    sub_124D41();
    sub_34EC8();
    v13 = sub_1077D(0, 0, 0, 0);
  }
  sub_1113CC(dword_192ED4, 1);
  sub_11C2F0();
  v15 = sub_1191CA((int)sub_2F4EE, 1);
  sub_2C601(v15, 1);
  sub_46CC8(word_1998F8, 1);
  *a4 = word_19B56E;
  return v23;
}
// 1077D: using guessed type int sub_1077D(_DWORD);
// 2F4EE: using guessed type int sub_2F4EE(_DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 1998F8: using guessed type int16_t word_1998F8;
// 19B554: using guessed type int dword_19B554;
// 19B558: using guessed type int dword_19B558;
// 19B55C: using guessed type int dword_19B55C;
// 19B560: using guessed type int dword_19B560;
// 19B564: using guessed type int dword_19B564;
// 19B56C: using guessed type int16_t word_19B56C;
// 19B56E: using guessed type int16_t word_19B56E;
// 19B570: using guessed type int16_t word_19B570;


//----- (00035251) --------------------------------------------------------
int16_t sub_35251( int a1, int16_t *a2, int a3, int a4, int a5)
{
  int v7; // eax
  int16_t v8; // dx
  int16_t v9; // ax
  int v10; // ebx
  int16_t v11; // cx
  int v12; // ebx
  int v13; // eax
  int v14; // edx
  int16_t v15; // bx
  int v16; // eax
  int v17; // eax
  int16_t v18; // dx
  int16_t v19; // ax
  int16_t v20; // bx
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int16_t v24; // dx
  int v25; // eax
  int16_t v26; // bx
  int v27; // eax
  int16_t v28; // dx
  int16_t i; // bx
  int v30; // eax
  int v31; // ebx
  int16_t v32; // dx
  int16_t v33; // ax
  int16_t v34; // bx
  _WORD *v35; // eax
  int16_t v36; // dx
  int v37; // ebx
  int16_t v38; // dx
  int v39; // ebx
  int v40; // eax
  int16_t v41; // dx
  int v42; // eax
  int16_t v43; // bx
  int v44; // edx
  int v45; // eax
  int v46; // eax
  int16_t v47; // dx
  signed int v48; // eax
  int16_t j; // bx
  int v51; // [esp+Ch] [ebp-30h]
  int v52; // [esp+18h] [ebp-24h]
  int16_t v53; // [esp+20h] [ebp-1Ch]
  int16_t v54; // [esp+24h] [ebp-18h]
  int v55; // [esp+28h] [ebp-14h]
  int16_t v56; // [esp+2Ch] [ebp-10h]
  int16_t v57; // [esp+2Ch] [ebp-10h]
  int16_t v58; // [esp+30h] [ebp-Ch]
  int16_t v59; // [esp+34h] [ebp-8h]
  int16_t v60; // [esp+38h] [ebp-4h]

  a3 = (int16_t)a3;   /* wave 181: the original reads only the low word (movsx) */
  if ( a3 == 7 )
  {
    v7 = dword_192864 + 313 * a1;
    v8 = *(_WORD *)(v7 + 194);
    if ( v8 < *a2 )
    {
      *a2 -= v8;
      a3 = -1;
      *(_WORD *)(v7 + 194) = 0;
    }
    else
    {
      *(_WORD *)(v7 + 194) -= *a2;
      *a2 = 0;
    }
  }
  v9 = *a2;
  v56 = *a2;
  if ( *a2 > 0 )
  {
    switch ( a3 )
    {
      case 2:
        v10 = 313 * a1;
        v11 = *(_WORD *)(v10 + dword_192864 + 308) - v9;
        *(_WORD *)(v10 + dword_192864 + 308) = v11;
        if ( v11 <= 0 )
        {
          *a2 = abs16(v11);
          *(_WORD *)(v10 + dword_192864 + 308) = 0;
          v12 = 0;
          do
          {
            v13 = 313 * a1 + dword_192864;
            v14 = (int16_t)v12++;
            *(_WORD *)(v13 + 2 * v14 + 41) = 0;
          }
          while ( (int16_t)v12 < 4 );
          *(_WORD *)(v13 + 39) = 0;
          break;
        }
        v15 = 0;
        v53 = sub_494A8(a1, (int)a2);
        do
        {
          v16 = 2 * v15 + dword_192864 + 313 * a1;
          if ( *(int16_t *)(v16 + 41) > v53 )
            *(_WORD *)(v16 + 41) = v53;
          ++v15;
        }
        while ( v15 < 4 );
        if ( g_orion150 )   /* 1.50 03535A: sub_1E5097 */
          *(_WORD *)(dword_192864 + 313 * a1 + 39) = v53;
LABEL_72:
        *a2 = 0;
        break;
      case 3:
        if ( g_orion150 )   /* 1.50 035373, 035378: sub_1E0E28 - sub_1F9F2B, then loc_3579C */
        {
          Hook150_1E0E28(a1, a4, a2);
          break;
        }
        v17 = 313 * a1 + dword_192864 + 2 * a4;
        v18 = *(_WORD *)(v17 + 260);
        v19 = *(_WORD *)(v17 + 276);
        v20 = v18 % v19;
        if ( !(v18 % v19) )
          v20 = v19;
        v21 = dword_192864 + 313 * a1 + 2 * a4;
        if ( v20 >= *a2 )
        {
          *(_WORD *)(v21 + 260) -= *a2;
          *a2 = 0;
        }
        else
        {
          *(_WORD *)(v21 + 260) -= v20;
          *a2 -= v20;
        }
        v22 = dword_192864 + 313 * a1;
        v23 = v22 + 11 * a4;
        v24 = *(uint8_t *)(v23 + 84);
        v58 = v24;
        v25 = (*(int16_t *)(2 * a4 + v22 + 276) + *(int16_t *)(2 * a4 + v22 + 260) - 1)
            / *(int16_t *)(2 * a4 + v22 + 276);
        *(_BYTE *)(v23 + 84) = v25;
        if ( *(_WORD *)(v23 + 82) == 32 && (uint8_t)v25 != v24 )
        {
          v26 = 1;
          v60 = (uint8_t)v25;
          while ( v26 < word_1998C0 )
          {
            if ( *(uint8_t *)(dword_192864 + 313 * v26 + 74) == a1 )
            {
              if ( v60 )
                --v60;
              else
                sub_3AFB3(v26);
            }
            ++v26;
          }
        }
        v27 = dword_192864 + 313 * a1 + 11 * a4;
        if ( *(_WORD *)(v27 + 82) == 37 )
        {
          v28 = *(uint8_t *)(v27 + 84);
          if ( v28 != v58 )
          {
            for ( i = 1; i < word_1998C0; ++i )
            {
              v30 = dword_192864 + 313 * i;
              if ( a1 == *(uint8_t *)(v30 + 311) )
              {
                if ( v28 )
                {
                  --v28;
                }
                else
                {
                  *(_BYTE *)(v30 + 310) = 0;
                  *(_BYTE *)(v30 + 311) = -1;
                }
              }
            }
          }
        }
        break;
      case 5:
        v31 = 313 * a1;
        v32 = *(_WORD *)(v31 + dword_192864 + 256) - v9;
        *(_WORD *)(v31 + dword_192864 + 256) = v32;
        if ( v32 >= 0 )
        {
          *a2 = 0;
        }
        else
        {
          *a2 = abs16(v32);
          *(_WORD *)(v31 + dword_192864 + 256) = 0;
        }
        v33 = sub_4528F(a1);   /* wave 184: 35573 result */
        v34 = v33;
        v35 = (_WORD *)(dword_192864 + 313 * a1);
        if ( !g_orion150 )   /* 1.50 035588 */
          *(_WORD *)((char *)v35 + 59) = v34;
        if ( *a2 > 0 )
        {
          v35[96] += *a2;
          v36 = v35[85];
          if ( v36 > (int16_t)v35[96] )
            v36 = v35[96];
          *(_WORD *)(dword_192864 + 313 * a1 + 192) = v36;
          goto LABEL_72;
        }
        break;
      case 8:
        v37 = 313 * a1;
        v38 = *(_WORD *)(v37 + dword_192864 + 258) - v56;
        *(_WORD *)(v37 + dword_192864 + 258) = v38;
        if ( v38 < 0 )
        {
          *a2 = abs16(v38);
          *(_WORD *)(v37 + dword_192864 + 258) = 0;
          break;
        }
        goto LABEL_72;
      case 9:
        v39 = 313 * a1;
        v52 = 2 * a4;
        v40 = v52 + v39 + dword_192864;
        v41 = *(_WORD *)(v40 + 292) - v56;
        *(_WORD *)(v40 + 292) = v41;
        if ( g_orion150 ? v41 > 0 : v41 >= 0 )   /* 1.50 035662 */
          goto LABEL_72;
        *a2 = abs16(v41);
        v59 = 0;
        v42 = v52 + v39 + dword_192864;
        v54 = 0;
        v43 = 0;
        *(_WORD *)(v42 + 292) = 0;
        while ( v43 < 39 && !v54 )
        {
          v51 = 313 * a1;
          if ( (uint16_t)sub_1276F0(v51 + dword_192864 + 76, v43) )
          {
            if ( a4 == v59 )
            {
              Hook150_1E1DF9(v51 + dword_192864 + 178, v43, a1, &v53);   /* 1.50 356DA */
              if ( v43 == 13 && word_1998CA == 1 )
              {
                v55 = 0;
                do
                {
                  v44 = 313 * a1 + dword_192864;
                  v45 = v44 + 2 * (int16_t)v55++;
                  *(_WORD *)(v45 + 41) = 0;
                }
                while ( (int16_t)v55 < 4 );
                *(_WORD *)(v44 + 39) = 0;
              }
              v54 = 1;
            }
            ++v59;
          }
          ++v43;
        }
        break;
      case 7:
      case 0:
        v46 = dword_192864 + 313 * a1;
        *(_WORD *)(v46 + 192) += *a2;
        v47 = *(_WORD *)(v46 + 170);
        if ( v47 > *(int16_t *)(v46 + 192) )
          v47 = *(_WORD *)(v46 + 192);
        *(_WORD *)(dword_192864 + 313 * a1 + 192) = v47;
        goto LABEL_72;
    }
  }
  LOWORD(v48) = *a2;
  v57 = v56 - *a2;
  Hook150_1E0DC1(a1);   /* 1.50 0357A2 */
  if ( a5 == 1 )
  {
    v48 = 313 * a1;
    if ( *(_BYTE *)(dword_192864 + v48 + 175) != 0xFF )
    {
      for ( j = 0; j < v57; ++j )
      {
        v48 = sub_1247A0(0x64u);
        if ( v48 <= 1 )
        {
          v48 = dword_192864 + 313 * a1;
          if ( *(_BYTE *)(v48 + 175) )
            --*(_BYTE *)(v48 + 175);
          else
            *(_BYTE *)(v48 + 175) = 0;
        }
        word_1998FE = 0;
      }
    }
  }
  return v48;
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998CA: using guessed type int16_t word_1998CA;
// 1998FE: using guessed type int16_t word_1998FE;


//----- (00035821) --------------------------------------------------------
int sub_35821_131( int a1, int a2, int a3, int a4)
{
  int result; // eax
  int v7; // eax
  int16_t *v8; // ebx
  int v9; // edx
  int v10; // eax
  int16_t v11; // si
  int16_t v12; // si
  uint8_t v13; // dl
  int v14; // eax
  int16_t v15; // dx
  int v16; // edx
  int v17; // edx
  int v18; // eax
  int16_t v19; // dx
  int v20; // ecx
  int v21; // ecx
  int16_t i; // cx
  int v23; // esi
  int v24; // edx
  int v25; // edx
  int v26; // ecx
  int v27; // edx
  int16_t j; // cx
  int v29; // esi
  int v30; // edx
  int v31; // edx

  if ( a1 )
  {
    v10 = dword_192864 + 313 * a1;
    v11 = *(_WORD *)(v10 + 170);
    if ( *(int16_t *)(v10 + 30) > -1 )
    {
      LOWORD(a4) = sub_58425(*(_WORD *)(v10 + 30));
      v12 = a4 + v11;
LABEL_27:
      v17 = v12 * a2 / 100;
      if ( (int16_t)v17 < 1 )
        LOWORD(v17) = 1;
      v18 = dword_192864 + 313 * a1;
      *(_WORD *)(v18 + 192) -= v17;
      if ( *(int16_t *)(v18 + 192) < 0 )
      {
        v19 = *(_WORD *)(v18 + 192);
        *(_WORD *)(v18 + 192) = 0;
        *(_WORD *)(v18 + 194) -= v19;
        if ( (int16_t)a4 < *(int16_t *)(v18 + 194) )
          *(_WORD *)(v18 + 194) = a4;
      }
      if ( g_orion150 )   /* 1.50 035A43, 035A48: sub_1E207F - word 23CE04 / 10000 instead of / 200 */
        result = sub_36BE2(a1) * a2 * *(uint16_t *)Hook150_Eseg(0x23CE04) / 10000;
      else
      result = sub_36BE2(a1) * a2 / 200;
      if ( result <= 1 )
        result = 1;
      v20 = 313 * a1;
      if ( *(_WORD *)(v20 + dword_192864 + 256) < *(_WORD *)(v20 + dword_192864 + 202) && (int16_t)result > 0 )
      {
        LOWORD(v20) = *(_WORD *)(v20 + dword_192864 + 202) - *(_WORD *)(v20 + dword_192864 + 256);
        if ( (int16_t)v20 > (int16_t)result )
          v20 = result;
        result -= v20;
        *(_WORD *)(313 * a1 + dword_192864 + 256) += v20;
      }
      v21 = 313 * a1;
      if ( *(_WORD *)(v21 + dword_192864 + 258) < *(_WORD *)(v21 + dword_192864 + 204) && (int16_t)result > 0 )
      {
        LOWORD(v21) = *(_WORD *)(v21 + dword_192864 + 204) - *(_WORD *)(v21 + dword_192864 + 258);
        if ( (int16_t)v21 > (int16_t)result )
          v21 = result;
        result -= v21;
        *(_WORD *)(313 * a1 + dword_192864 + 258) += v21;
      }
      for ( i = 0; i < 8 && (int16_t)result > 0; ++i )
      {
        v23 = 313 * a1 + dword_192864;
        v24 = v23 + 2 * i;
        if ( *(_WORD *)(v24 + 260) < *(_WORD *)(v24 + 206) )
        {
          LOWORD(v23) = *(_WORD *)(v24 + 206) - *(_WORD *)(v24 + 260);
          if ( (int16_t)v23 > (int16_t)result )
            v23 = result;
          v25 = 2 * i + dword_192864 + 313 * a1;
          result -= v23;
          if ( g_orion150 )   /* 1.50 035B58, 035B5D: sub_1E034A - sub_1E7D97 adds and recounts the weapons */
            Hook150_1E034A(v25, i, v23);
          else
          *(_WORD *)(v25 + 260) += v23;
        }
      }
      HIWORD(v26) = HIWORD(dword_192864);
      v27 = dword_192864 + 313 * a1;
      if ( *(_WORD *)(v27 + 308) < *(_WORD *)(v27 + 254) && (int16_t)result > 0 )
      {
        LOWORD(v26) = *(_WORD *)(v27 + 254) - *(_WORD *)(v27 + 308);
        if ( (int16_t)v26 > (int16_t)result )
          v26 = result;
        result -= v26;
        *(_WORD *)(dword_192864 + 313 * a1 + 308) += v26;
        if ( g_orion150 )   /* 1.50 035BB7, 035BBC: sub_1E032E */
          *(_WORD *)(dword_192864 + 313 * a1 + 39) = sub_494A8(a1, 0);
      }
      for ( j = 0; j < 8 && (int16_t)result > 0; ++j )
      {
        v29 = 2 * j;
        v30 = v29 + dword_192864 + 313 * a1;
        if ( *(_WORD *)(v30 + 292) < *(_WORD *)(v30 + 238) )
        {
          LOWORD(v29) = *(_WORD *)(v30 + 238) - *(_WORD *)(v30 + 292);
          if ( (int16_t)v29 > (int16_t)result )
            v29 = result;
          v31 = 313 * a1 + dword_192864 + 2 * j;
          result -= v29;
          if ( g_orion150 )   /* 1.50 035C22 */
            *(_WORD *)(v31 + 292) += v29;
          else
          *(_WORD *)(v31 + 292) = *(_WORD *)(v31 + 238);
        }
      }
      return result;
    }
    if ( g_orion150 ? *(uint8_t *)(v10 + 31) != 0xFF : *(_BYTE *)(v10 + 49) != 0 )   /* 1.50 0358E2: byte +1Fh == -1 */
    {
      v16 = word_180024[18 * *(uint8_t *)(v10 + 37)];
      v14 = v16 + v16 * *(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v10 + 51)) / 100;
    }
    else
    {
      v13 = *(_BYTE *)(v10 + 37);
      if ( v13 < 3u )
      {
        if ( v13 == 2 )
          a4 = word_1800FC * *(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v10 + 51)) / 100
             + word_1800FC;
        goto LABEL_24;
      }
      if ( v13 <= 3u )
      {
        v14 = *(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v10 + 51)) * word_1800FC / 100;
        v15 = word_180120;
      }
      else
      {
        if ( v13 != 4 )
          goto LABEL_24;
        v14 = word_1800FC * *(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v10 + 51)) / 100;
        v15 = word_180144;
      }
      LOWORD(v14) = v15 + v14;
    }
    LOWORD(a4) = v14;
LABEL_24:
    if ( sub_4B0D3(a1, 14) )
      LOWORD(a4) = 3 * a4;
    v12 = a4 + v11;
    goto LABEL_27;
  }
  result = dword_192864;
  if ( *(int16_t *)(dword_192864 + 192) <= 0 )
  {
    if ( *(int16_t *)(dword_192864 + 170) <= 0 )
      return result;
    v7 = *(int16_t *)(dword_192864 + 170) * a2 / 100;
    v8 = (int16_t *)(dword_192864 + 170);
  }
  else
  {
    v7 = *(int16_t *)(dword_192864 + 192) * a2 / 100;
    v8 = (int16_t *)(dword_192864 + 192);
  }
  if ( v7 <= 1 )
    v9 = 1;
  else
    v9 = v7;
  result = *v8 - v9;
  *v8 = result;
  return result;
}
// 17F642: using guessed type int16_t word_17F642;
// 180024: using guessed type int16_t word_180024[];
// 1800FC: using guessed type int16_t word_1800FC;
// 180120: using guessed type int16_t word_180120;
// 180144: using guessed type int16_t word_180144;
// 192864: using guessed type int dword_192864;


//----- (00035C3A) --------------------------------------------------------
int sub_35C3A_131(int result)
{
  qmemcpy((void *)(result + 256), (void *)(result + 202), 0x36u);
  return result;
}


//----- (00035C56) --------------------------------------------------------
void sub_35C56( int a1, int a2, int a3, _WORD *a4, _WORD *a5)
{
  int16_t v5; // ax
  int16_t v6; // ax

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  a3 = (int16_t)a3;   /* wave 181: the original reads only the low word (movsx) */
  v5 = sub_366DD(a1);   /* wave 184: 35C62 result */
  *a4 = v5;
  v6 = sub_35D0D(a2, a3);   /* wave 184: 35C72 result */
  *a5 = v6;
}


//----- (00035C7F) --------------------------------------------------------
int16_t sub_35C7F( int a1)
{
  int v1; // eax

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v1 = dword_192864 + 313 * a1;
  if ( *(int16_t *)(v1 + 258) > 0 )
    return word_17FE00[11 * *(uint8_t *)(v1 + 50)];
  else
    return 0;
}
// 17FE00: using guessed type int16_t word_17FE00[];
// 192864: using guessed type int dword_192864;


//----- (00035CAD) --------------------------------------------------------
int16_t sub_35CAD( int a1)
{
  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  return word_17D174[4 * *(uint8_t *)(dword_192864 + 313 * a1 + 172)];
}
// 17D174: using guessed type int16_t word_17D174[];
// 192864: using guessed type int dword_192864;


//----- (00035D0D) --------------------------------------------------------
/* wave 184: rewritten from asm 35D0D-35E07 (the C lost the sum): defence of ship a1,
   a2 = 0 / 1 (the two defence values at +54 / +56) */
int sub_35D0D( int a1, int a2)
{
  int16_t v8; // [ebp-8]
  int16_t vC; // [ebp-0Ch]
  int v10, v14, v18, v_di, v_bx, v4;
  uint8_t *v_s;

  v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * (int16_t)a1);
  v8 = 0;
  vC = 0;
  v18 = 0;
  v10 = word_17D172[4 * v_s[172]];   /* 35D3C */
  if ( !(int16_t)a2 )
  {
    v_di = (int16_t)(5 * *(int16_t *)(v_s + 59));
    if ( !*(int16_t *)(v_s + 59) )
      v_di -= 20;
  }
  else
  {
    v10 = (int16_t)v10 / 2;   /* 35D64 */
    v_di = 0;
  }
  v4 = sub_36A63((int16_t)a1, (int16_t)a2, (_WORD *)&v8);
  v14 = v4;
  v_bx = sub_36139(v_s[32], (int16_t)a2, &vC);   /* 35DA3 */
  if ( vC > v8 )
    v14 = v4 - v8;
  else
    v_bx -= vC;
  if ( (g_orion150 ? v_s[31] != 0xFF : v_s[49] != 0) && v_s[32] < 8u )   /* 35DD2; 1.50 035DD4: byte +1Fh == -1 */
    v18 = *(int8_t *)(intptr_t)(dword_197F98 + 3753 * v_s[32] + 2213);
  return v_di + v10 + v14 + v_bx + v18;   /* 35DFA */
}
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int (uint8_t*)dword_197F98;


//----- (00035E0C) --------------------------------------------------------
int sub_35E0C( int a1)
{
  int v2; // ebx
  int16_t i; // dx
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = 0;
  for ( i = 0; i < word_1998C0; ++i )
  {
    v4 = 313 * i + dword_192864;
    if ( *(uint8_t *)(v4 + 32) == a1 && !*(_BYTE *)(v4 + 176) && !*(_BYTE *)(v4 + 36) )
    {
      v5 = *(int16_t *)(v4 + 173);
      if ( v5 > -1 )
      {
        v6 = sub_3607A(v5);   /* wave 182 */
        if ( (int16_t)v6 > (int16_t)v2 )
          v2 = v6;
      }
    }
  }
  return v2;
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00035E6A) --------------------------------------------------------
int sub_35E6A( int a1)
{
  int v1; // edx
  int v2; // eax
  int v3; // ebx

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v1 = a1;
  v2 = 59 * a1 + dword_1930DC;
  v3 = 0;
  if ( (*(_BYTE *)(v2 + 42) & 4) != 0 )
    return 5 * (sub_94951(v1) + 1);
  if ( (*(_BYTE *)(v2 + 42) & 8) != 0 )
    return 15 * ((int16_t)sub_94951(v1) + 1) / 2;
  return v3;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (00035EAE) --------------------------------------------------------
int sub_35EAE( int a1)
{
  int16_t v2; // bx
  int16_t i; // dx
  int v4; // eax
  int v5; // eax
  int16_t v6; // ax

  v2 = 0;
  for ( i = 0; i < word_1998C0; ++i )
  {
    v4 = 313 * i + dword_192864;
    if ( *(uint8_t *)(v4 + 32) == a1 && !*(_BYTE *)(v4 + 176) && !*(_BYTE *)(v4 + 36) )
    {
      v5 = *(int16_t *)(v4 + 173);
      if ( v5 > -1 )
      {
        v6 = sub_35E6A(v5);
        if ( v6 > v2 )
          v2 = v6;
      }
    }
  }
  return v2;   /* wave 181: tail loc_35E63 `mov     eax, ebx` */
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00035F0A) --------------------------------------------------------
int sub_35F0A()
{
  int16_t v0; // ax
  int16_t v1; // ax
  int16_t v2; // dx
  int result; // eax

  v0 = sub_35F7E(word_1998AC);
  word_199224[word_1998AC] = v0 + 100;
  v1 = sub_35F7E(word_19988E);
  v2 = v1;
  result = word_19988E;
  word_199224[word_19988E] = v2 + 100;
  return result;
}
// 199224: using guessed type int16_t word_199224[15];
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;


//----- (00035F4D) --------------------------------------------------------
/* wave 182: rewritten from the asm (0x35F5F) - it jumps into the tail of
   sub_35E6A; bits of the design record at +43 */
int sub_35F4D( int a1)
{
  uint8_t v1; // flags

  a1 = (int16_t)a1;
  v1 = *(uint8_t *)(59 * a1 + dword_1930DC + 43);
  if ( (v1 & 0x4) != 0 )
    return 5 * (sub_94951(a1) + 1);
  if ( (v1 & 0x8) != 0 )
    return 15 * ((int16_t)sub_94951(a1) + 1) / 2;
  return 0;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (00035F7E) --------------------------------------------------------
int sub_35F7E( int a1)
{
  int16_t v2; // bx
  int16_t i; // dx
  int v4; // eax
  int v5; // eax
  int16_t v6; // ax

  v2 = 0;
  for ( i = 0; i < word_1998C0; ++i )
  {
    v4 = 313 * i + dword_192864;
    if ( *(uint8_t *)(v4 + 32) == a1 && !*(_BYTE *)(v4 + 176) && !*(_BYTE *)(v4 + 36) )
    {
      v5 = *(int16_t *)(v4 + 173);
      if ( v5 > -1 )
      {
        v6 = sub_35F4D(v5);   /* wave 182 */
        if ( v6 > v2 )
          v2 = v6;
      }
    }
  }
  return v2;   /* wave 181: tail loc_35E63 `mov     eax, ebx` */
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00035FDA) --------------------------------------------------------
int sub_35FDA( int a1)
{
  int16_t v2; // bx
  int16_t i; // dx
  int v4; // eax
  int v5; // eax
  int16_t v6; // ax

  v2 = 0;
  for ( i = 0; i < word_1998C0; ++i )
  {
    v4 = 313 * i + dword_192864;
    if ( *(uint8_t *)(v4 + 32) == a1 && !*(_BYTE *)(v4 + 176) && !*(_BYTE *)(v4 + 36) )
    {
      v5 = *(int16_t *)(v4 + 173);
      if ( v5 > -1 )
      {
        v6 = sub_36036(v5);   /* 3601B */
        if ( v6 > v2 )
          v2 = v6;
      }
    }
  }
  return v2;   /* wave 181: tail loc_35E63 `mov     eax, ebx` */
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00036036) --------------------------------------------------------
int sub_36036( int a1)
{
  int v2; // eax

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v2 = dword_1930DC + 59 * a1;
  /* wave 184: 3605B / 36075 jmp 35EA8 (mov eax, ebx) */
  if ( (*(_BYTE *)(v2 + 38) & 4) != 0 )
    return 2 * (sub_94951(a1) + 1);
  if ( (*(_BYTE *)(v2 + 38) & 8) != 0 )
    return 3 * (sub_94951(a1) + 1);
  return 0;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (0003607A) --------------------------------------------------------
/* wave 182: rewritten from the asm (0x3608D) - it jumps into the tail of
   sub_36036; bits of the design record at +42 */
int sub_3607A( int a1)
{
  uint8_t v1; // flags

  a1 = (int16_t)a1;
  v1 = *(uint8_t *)(59 * a1 + dword_1930DC + 42);
  if ( (v1 & 0x1) != 0 )
    return 2 * (sub_94951(a1) + 1);
  if ( (v1 & 0x2) != 0 )
    return 3 * (sub_94951(a1) + 1);
  return 0;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (000360AA) --------------------------------------------------------
int sub_360AA( int a1)
{
  int16_t v2; // bx
  int16_t i; // dx
  int v4; // eax
  int v5; // eax
  int16_t v6; // ax

  v2 = 0;
  for ( i = 0; i < word_1998C0; ++i )
  {
    v4 = 313 * i + dword_192864;
    if ( *(uint8_t *)(v4 + 32) == a1 && !*(_BYTE *)(v4 + 176) && !*(_BYTE *)(v4 + 36) )
    {
      v5 = *(int16_t *)(v4 + 173);
      if ( v5 > -1 )
      {
        v6 = sub_36106(v5);   /* wave 182 */
        if ( v6 > v2 )
          v2 = v6;
      }
    }
  }
  return v2;   /* wave 181: tail loc_35E63 `mov     eax, ebx` */
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00036106) --------------------------------------------------------
/* wave 182: rewritten from the asm (0x36119) - it jumps into the tail of
   sub_36036; bits of the design record at +43 */
int sub_36106( int a1)
{
  uint8_t v1; // flags

  a1 = (int16_t)a1;
  v1 = *(uint8_t *)(59 * a1 + dword_1930DC + 43);
  if ( (v1 & 0x10) != 0 )
    return 2 * (sub_94951(a1) + 1);
  if ( (v1 & 0x20) != 0 )
    return 3 * (sub_94951(a1) + 1);
  return 0;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (00036139) --------------------------------------------------------
int sub_36139( int a1, int a2, int16_t *a3)
{
  int v3; // ecx
  int16_t j; // si
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int16_t i; // si
  uint8_t *v10; // eax
  int v11; // eax
  int16_t v12; // ax

  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  v3 = 0;
  if ( a2 == 1 )
  {
    for ( i = 0; i < word_1998C0; ++i )
    {
      v10 = (uint8_t *)(313 * i + dword_192864);
      if ( v10[32] == a1 && !v10[176] && !v10[36] )
      {
        if ( Hook150_1E22FC(i, 38) )   /* 1.50 036213 */
          *a3 = 70;
        v11 = *(int16_t *)(dword_192864 + 313 * i + 173);
        if ( v11 > -1 )
        {
          v12 = sub_3677D(v11);   /* wave 182 */
          if ( v12 > (int16_t)v3 )
            LOWORD(v3) = v12;
        }
      }
    }
    return *a3 + (int16_t)v3 / 2;
  }
  else
  {
    for ( j = 0; j < word_1998C0; ++j )
    {
      v5 = 313 * j + dword_192864;
      if ( *(uint8_t *)(v5 + 32) == a1 && !*(_BYTE *)(v5 + 176) && !*(_BYTE *)(v5 + 36) )
      {
        v6 = *(int16_t *)(v5 + 173);
        if ( v6 > -1 )
        {
          v7 = sub_3677D(v6);   /* wave 182 */
          if ( (int16_t)v7 > (int16_t)v3 )
            v3 = v7;
        }
      }
    }
    return v3;
  }
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00036266) --------------------------------------------------------
int sub_36266(int a1)
{
  int v0; // esi
  int v1; // ecx
  int v2; // edi
  _BOOL2 v3; // ax
  int16_t i; // bx
  uint8_t *v5; // eax
  uint8_t v6; // al
  int16_t v7; // dx
  int v8; // eax
  int v9; // eax
  int16_t v11 = (int16_t)a1;   /* wave 184: 3626F push eax (owner) */
  int v12; // [esp+4h] [ebp-10h]
  int v13; // [esp+Ch] [ebp-8h]
  _BOOL2 v14; // [esp+10h] [ebp-4h]

  v13 = 0;
  v0 = 0;
  v1 = 0;
  v2 = 0;
  v3 = word_1998AC > 8 || word_19988E > 8;
  v14 = v3;
  for ( i = 0; i < word_1998C0; ++i )
  {
    v5 = (uint8_t *)(313 * i + dword_192864);
    if ( v5[32] == v11 && !v5[176] && !v5[36] )
    {
      if ( g_orion150 )   /* 1.50 0362E0, 0362E4: sub_1E2318; 0362F3, 0362F8: sub_1E43BC */
      {
        if ( v5[31] == 0xFF && !sub_3E563(i) )
        {
          v6 = v5[37];
          if ( *Hook150_Eseg(0x23F09F) == 1 )
            --v6;
          if ( v6 < 3u )
          {
            if ( v6 == 2 )
              v1 = *Hook150_Eseg(0x23E20E);
          }
          else if ( v6 <= 3u )
            v1 = 10;
          else if ( v6 == 4 )
            v1 = 20;
        }
      }
      else
      if ( !v5[49] )
      {
        v6 = v5[37];
        if ( v6 < 3u )
        {
          if ( v6 == 2 )
            v1 = 0;
        }
        else if ( v6 <= 3u )
        {
          v1 = 10;
        }
        else if ( v6 == 4 )
        {
          v1 = 20;
        }
      }
      v12 = 313 * i;
      if ( *(int16_t *)(v12 + dword_192864 + 173) > -1 )
      {
        v7 = *(_WORD *)(v12 + dword_192864 + 173);
        v8 = sub_367AE(v7);   /* wave 182 */
        if ( (int16_t)v8 > (int16_t)v0 )
          v0 = v8;
        if ( v14 )
        {
          v9 = sub_367DF(v7);   /* wave 182 */
          if ( (int16_t)v9 > (int16_t)v2 )
            v2 = v9;
        }
      }
      if ( v14 && Hook150_1E22FC(i, 28) )   /* 1.50 036362 */
        v13 = 20;
    }
  }
  return v13 + v2 + v0 + v1;
}
// 192864: using guessed type int dword_192864;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00036470) --------------------------------------------------------
void sub_36470(int a1)
{
  int16_t v2; // ax
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int16_t v7; // bx
  int16_t v8; // di
  int v9; // eax
  int16_t v10; // [esp+8h] [ebp-Ch]
  int16_t v11; // [esp+Ch] [ebp-8h]
  int16_t v12; // [esp+10h] [ebp-4h]

  v2 = *(uint8_t *)(a1 + 37);
  v10 = v2;
  if ( *(_BYTE *)(a1 + 49) )
    *(_WORD *)(a1 + 202) = word_18002A[18 * v2];
  else
    *(_WORD *)(a1 + 202) = 0;
  if ( (uint16_t)sub_1276F0(a1 + 76, 0x1Bu) && !(uint16_t)sub_1276F0(a1 + 178, 0x1Bu) )
    *(_WORD *)(a1 + 202) *= 3;
  v11 = 0;
  *(_WORD *)(a1 + 204) = word_180028[18 * v10];
  if ( g_orion150 && *(int8_t *)(a1 + 50) <= 0 )   /* 1.50 0364F1, 0364F6: sub_1E317C */
    *(_WORD *)(a1 + 204) = 0;
  do
  {
    v3 = a1 + 11 * v11;
    if ( *(int16_t *)(v3 + 82) <= 0 )
    {
      *(_WORD *)(a1 + 2 * v11 + 222) = 0;
      *(_WORD *)(a1 + 2 * v11 + 206) = 0;
    }
    else
    {
      if ( (int16_t)sub_6D1B4(
                      *(_WORD *)(v3 + 82),
                      *(uint8_t *)(v3 + 85),
                      *(_WORD *)(v3 + 88),
                      *(_WORD *)(v3 + 86))
         / 10 <= 1 )
        LOWORD(v4) = 1;
      else
        v4 = (int16_t)sub_6D1B4(
                        *(_WORD *)(v3 + 82),
                        *(uint8_t *)(v3 + 85),
                        *(_WORD *)(v3 + 88),
                        *(_WORD *)(v3 + 86))
           / 10;
      *(_WORD *)(a1 + 2 * v11 + 222) = v4;
      *(_WORD *)(a1 + 2 * v11 + 206) = v4 * *(uint8_t *)(11 * v11 + a1 + 84);
    }
    ++v11;
  }
  while ( v11 < 8 );
  v5 = 0;
  do
  {
    v6 = (int16_t)v5++;
    *(_WORD *)(a1 + 2 * v6 + 238) = 0;
  }
  while ( (int16_t)v5 < 8 );
  v7 = 0;
  v8 = 0;
  v12 = 0;
  while ( v8 < 39 && !v12 )
  {
    if ( (uint16_t)sub_1276F0(a1 + 76, v8) && !(uint16_t)sub_1276F0(a1 + 178, v8) )
    {
      if ( v8 == 27 || v8 == 11 || v8 == 4 || v8 == 14 || v8 == 24 )
      {
        *(_WORD *)(a1 + 2 * v7 + 238) = 0;
      }
      else
      {
        if ( g_orion150 )   /* 1.50 03661F, 036624: sub_1E1411; 036640: sub_1E0E3C */
        {
          int c = (int16_t)v10;

          if ( c >= 6 )
            c = c - 4 + (*Hook150_Eseg(0x23F09F) != 0);
          v9 = *(int16_t *)((char *)&word_17EEE8 + 47 * v8 + 2 * c) / 10;
          if ( v9 <= 1 )
            v9 = 1;
          *(_WORD *)(a1 + 2 * v7 + 238) = v9 + 1;
        }
        else
        {
        v9 = *(int16_t *)((char *)&word_17EEE8 + 47 * v8 + 2 * v10) / 10;
        if ( v9 <= 1 )
          LOWORD(v9) = 1;
        *(_WORD *)(a1 + 2 * v7 + 238) = v9;
        }
      }
      if ( ++v7 >= 8 )
        v12 = 1;
    }
    ++v8;
  }
  if ( *(_BYTE *)(a1 + 38) )
    *(_WORD *)(a1 + 254) = word_18002C[18 * v10];
  else
    *(_WORD *)(a1 + 254) = 0;
  qmemcpy((void *)(a1 + 256), (void *)(a1 + 202), 0x36u);
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x3638A je epilog funkce */
}
// 17EEE8: using guessed type int16_t word_17EEE8;
// 180028: using guessed type int16_t word_180028[];
// 18002A: using guessed type int16_t word_18002A[];
// 18002C: using guessed type int16_t word_18002C[];


//----- (000366AF) --------------------------------------------------------
int sub_366AF( int a1, int a2)
{
  int result; // eax

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  result = dword_192864 + 313 * a1;
  if ( *(uint8_t *)(result + 175) < a2 )
    *(_BYTE *)(result + 175) = 0;
  else
    *(_BYTE *)(result + 175) -= a2;
  return result;
}
// 192864: using guessed type int dword_192864;


//----- (000366DD) --------------------------------------------------------
/* wave 184: rewritten from asm 366DD-36778 (the C lost the sum): attack value of ship a1 (+52) */
int sub_366DD( int a1)
{
  int v_di, v4, v_si, v_dx, v_ax;
  uint8_t *v_s;

  v_di = (int16_t)sub_35C7F((int16_t)a1);
  v_s = (uint8_t *)(intptr_t)(dword_192864 + 313 * (int16_t)a1);
  v4 = word_17D170[4 * v_s[172]];   /* 36707 */
  v_si = (uint16_t)sub_4B0D3((int16_t)a1, 5) ? 50 : 0;
  v_dx = sub_36266(v_s[32]);
  v_ax = v_s[32] < 8u ? *(int8_t *)(intptr_t)(dword_197F98 + 3753 * v_s[32] + 2214) : 0;
  return v4 + v_di + v_si + v_dx + v_ax;   /* 3676D */
}
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int (uint8_t*)dword_197F98;


//----- (0003677D) --------------------------------------------------------
/* wave 182: rewritten from the asm (0x3678F) - it jumps into the tail of
   sub_35E6A; bits of the design record at +42 */
int sub_3677D( int a1)
{
  uint8_t v1; // flags

  a1 = (int16_t)a1;
  v1 = *(uint8_t *)(59 * a1 + dword_1930DC + 42);
  if ( (v1 & 0x40) != 0 )
    return 5 * (sub_94951(a1) + 1);
  if ( (v1 & 0x80) != 0 )
    return 15 * ((int16_t)sub_94951(a1) + 1) / 2;
  return 0;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (000367AE) --------------------------------------------------------
/* wave 182: rewritten from the asm (0x367C0) - it jumps into the tail of
   sub_35E6A; bits of the design record at +43 */
int sub_367AE( int a1)
{
  uint8_t v1; // flags

  a1 = (int16_t)a1;
  v1 = *(uint8_t *)(59 * a1 + dword_1930DC + 43);
  if ( (v1 & 0x40) != 0 )
    return 5 * (sub_94951(a1) + 1);
  if ( (v1 & 0x80) != 0 )
    return 15 * ((int16_t)sub_94951(a1) + 1) / 2;
  return 0;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (000367DF) --------------------------------------------------------
/* wave 182: rewritten from the asm (0x367F1) - it jumps into the tail of
   sub_35E6A; bits of the design record at +42 */
int sub_367DF( int a1)
{
  uint8_t v1; // flags

  a1 = (int16_t)a1;
  v1 = *(uint8_t *)(59 * a1 + dword_1930DC + 42);
  if ( (v1 & 0x10) != 0 )
    return 5 * (sub_94951(a1) + 1);
  if ( (v1 & 0x20) != 0 )
    return 15 * ((int16_t)sub_94951(a1) + 1) / 2;
  return 0;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (00036810) --------------------------------------------------------
int sub_36810( int a1, _WORD *a2, _WORD *a3, int a4, int a5, int a6, int a7)
{
  int result; // eax
  int v10; // ebx
  int v11; // edx
  int16_t i; // ax
  int16_t v13; // bx
  int v14; // eax
  int v15; // edx
  int16_t v16; // bx
  int16_t v17; // ax
  int16_t v18; // di
  int16_t v19; // dx
  _WORD *v20; // edx
  _WORD *v21; // edx
  _WORD v22[20]; // [esp+0h] [ebp-3Ch] BYREF
  int v23; // [esp+28h] [ebp-14h]
  _WORD *v24; // [esp+2Ch] [ebp-10h]
  int v25; // [esp+30h] [ebp-Ch]
  int v26; // [esp+34h] [ebp-8h]
  int v27; // [esp+38h] [ebp-4h]

  v24 = a3;
  v27 = a4;
  result = sub_1247A0(0x64u);
  v25 = result;
  *a2 = -1;
  if ( a7 )
  {
    *a2 = 5;
  }
  else if ( a6 || (result = 313 * a1, *(int16_t *)(dword_192864 + result + 194) <= 0) || a5 )
  {
    v10 = sub_36B64(a1);
    if ( a5 )
      result = 100;
    else
      result = 100
             * v10
             / ((int16_t)(*(_WORD *)(313 * a1 + dword_192864 + 170) - *(_WORD *)(313 * a1 + dword_192864 + 192)) + v10);
    if ( *(_BYTE *)(313 * a1 + dword_192864 + 32) > 9u && (int16_t)result > 25 )
      result = 25;
    if ( (int16_t)result < (int16_t)v25 )
    {
      *a2 = 0;
    }
    else
    {
      memset(v22, 0, 38);
      v11 = dword_192864 + 313 * a1;
      v22[0] = *(_WORD *)(v11 + 256);
      v22[1] = *(_WORD *)(v11 + 258);
      for ( i = 0; i < 8; ++i )
      {
        if ( (_WORD)v27 )
          v13 = 3 * *(_WORD *)(313 * a1 + dword_192864 + 2 * i + 260);
        else
          v13 = *(_WORD *)(dword_192864 + 313 * a1 + 2 * i + 260);
        v22[i + 2] = v13;
      }
      v26 = 0;
      do
      {
        v14 = dword_192864 + 313 * a1;
        v15 = (int16_t)v26;
        v16 = *(_WORD *)(v14 + 2 * (int16_t)v26++ + 292);
        v22[v15 + 10] = v16;
      }
      while ( (int16_t)v26 < 8 );
      if ( (_WORD)v27 )
        v17 = 3 * *(_WORD *)(v14 + 308);
      else
        v17 = *(_WORD *)(v14 + 308);
      v22[18] = v17;
      result = sub_FE92D((const uint16_t *)v22, 19);
      v18 = result;
      if ( (_WORD)result )
      {
        if ( (_WORD)result == 1 )
        {
          *a2 = 8;
        }
        else
        {
          v19 = 0;
          for ( result = 0; (int16_t)result < 8 && !v19; ++result )
          {
            v23 = (int16_t)result;
            if ( v18 == (int16_t)result + 2 )
            {
              v20 = v24;
              *a2 = 3;
              *v20 = result;
              v19 = 1;
            }
          }
          if ( !v19 )
          {
            for ( result = 0; (int16_t)result < 8 && !v19; ++result )
            {
              if ( (int16_t)result + 10 == v18 )
              {
                v21 = v24;
                *a2 = 9;
                *v21 = result;
                v19 = 1;
              }
            }
          }
          if ( v18 == 18 )
            *a2 = 2;
        }
      }
      else
      {
        *a2 = 5;
      }
    }
  }
  else
  {
    *a2 = 7;
  }
  return result;
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192864: using guessed type int dword_192864;


//----- (00036A63) --------------------------------------------------------
int sub_36A63( int a1, int a2, _WORD *a3)
{
  int v4; // ebx

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v4 = 0;
  if ( g_orion150 )   /* 1.50 036A83, 036A87, 036A8C: sub_1E8F5F */
    v4 = Hook150_1E8F5F(a1, a2);
  else
  if ( *(_BYTE *)(313 * a1 + dword_192864 + 64) == 1 && !a2 )
    v4 = 80;
  if ( sub_4B0D3(a1, 38) )
  {
    if ( a2 == 1 )
    {
      v4 += 130;
      *a3 = 130;
    }
  }
  else if ( sub_4B0D3(a1, 21) )
  {
    if ( a2 == 1 )
    {
      v4 += 100;
      *a3 = 100;
    }
  }
  else if ( sub_4B0D3(a1, 9) && a2 == 1 )
  {
    v4 += 70;
    *a3 = 70;
  }
  if ( sub_4B0D3(a1, 17) )
  {
    if ( !a2 )
      v4 += 100;
    if ( a2 == 1 )
      v4 += 50;
  }
  if ( sub_4B0D3(a1, 18) )
  {
    if ( !a2 )
      v4 += 50;
    if ( a2 == 1 )
      v4 += 25;
  }
  return v4;
}
// 192864: using guessed type int dword_192864;


//----- (00036B46) --------------------------------------------------------
int sub_36B46( int a1)
{
  int v1; // ebx

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v1 = 0;
  if ( sub_4B0D3(a1, 5) )
    return 50;
  return v1;
}


//----- (00036B64) --------------------------------------------------------
int16_t sub_36B64( int a1)
{
  int v2; // edx
  int16_t v3; // ax
  int v4; // ebx
  int v5; // ebx
  int v6; // edx
  int v7; // esi

  v2 = 0;
  if ( g_orion150 )   /* 1.50 036B80: sub_1E0369 - 1 counts as 2, then shr 1 */
  {
    int x = *(int16_t *)(313 * a1 + dword_192864 + 256);

    v3 = *(_WORD *)(313 * a1 + dword_192864 + 258) + (uint16_t)((uint32_t)(x == 1 ? 2 : x) >> 1);
  }
  else
  v3 = *(_WORD *)(313 * a1 + dword_192864 + 258) + *(int16_t *)(313 * a1 + dword_192864 + 256) / 2;
  do
  {
    v4 = (int16_t)v2++;
    v3 += *(_WORD *)(313 * a1 + dword_192864 + 2 * v4 + 260);
  }
  while ( (int16_t)v2 < 8 );
  v5 = 0;
  do
  {
    v6 = 313 * a1 + dword_192864;
    v7 = (int16_t)v5++;
    v3 += *(_WORD *)(v6 + 2 * v7 + 292);
  }
  while ( (int16_t)v5 < 8 );
  return *(_WORD *)(v6 + 308) + v3;
}
// 192864: using guessed type int dword_192864;


//----- (00036BE2) --------------------------------------------------------
int16_t sub_36BE2( int a1)
{
  int v2; // edx
  int16_t v3; // ax
  int v4; // ebx
  int v5; // ebx
  int v6; // edx
  int v7; // esi

  v2 = 0;
  v3 = *(_WORD *)(313 * a1 + dword_192864 + 204) + *(int16_t *)(313 * a1 + dword_192864 + 202) / 2;
  do
  {
    v4 = (int16_t)v2++;
    v3 += *(_WORD *)(313 * a1 + dword_192864 + 2 * v4 + 206);
  }
  while ( (int16_t)v2 < 8 );
  v5 = 0;
  do
  {
    v6 = 313 * a1 + dword_192864;
    v7 = (int16_t)v5++;
    v3 += *(_WORD *)(v6 + 2 * v7 + 238);
  }
  while ( (int16_t)v5 < 8 );
  return *(_WORD *)(v6 + 254) + v3;
}
// 192864: using guessed type int dword_192864;


//----- (00036C60) --------------------------------------------------------
int sub_36C60(int a1, int a2)
{
  int v2; // ebx
  int v3; // ecx

  a2 = (int16_t)a2;   /* wave 181: the original reads only the low word (movsx) */
  v2 = a1 + 2 * a2;
  v3 = *(int16_t *)(v2 + 260) / *(int16_t *)(v2 + 276);
  if ( *(int16_t *)(v2 + 260) % *(int16_t *)(v2 + 276) && *(int16_t *)(v2 + 260) > 0 )
    ++v3;
  return v3;
}


//----- (00036C9C) --------------------------------------------------------
int16_t sub_36C9C( int a1, int a2, int a3, int a4)
{
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int16_t i; // di
  int16_t v11; // bx
  int v12; // ecx
  char v13; // al
  _BOOL1 v14; // cl
  _BOOL1 v15; // al
  _BOOL1 v16; // dl
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // ecx
  char v21; // dl
  _WORD v23[8]; // [esp+0h] [ebp-40h]
  int v24; // [esp+10h] [ebp-30h]
  int v25; // [esp+14h] [ebp-2Ch]
  int v26; // [esp+18h] [ebp-28h]
  int v27; // [esp+1Ch] [ebp-24h]
  int v28; // [esp+20h] [ebp-20h]
  int v29; // [esp+24h] [ebp-1Ch]
  int v30; // [esp+28h] [ebp-18h] BYREF
  int v31; // [esp+2Ch] [ebp-14h]
  int v32; // [esp+30h] [ebp-10h]
  int v33; // [esp+34h] [ebp-Ch] BYREF
  int v34; // [esp+38h] [ebp-8h]
  _BOOL1 v35; // [esp+3Ch] [ebp-4h]

  v32 = a2;
  v34 = a3;
  v31 = a4;
  sub_49ED1(a1, &v30, &v33);
  v6 = (int16_t)v31;
  LOWORD(v7) = sub_2AED2(a1, v31);
  if ( (_WORD)v7 )
  {
    v7 = dword_192B14 + 26 * v6;
    if ( byte_17F80F[28 * *(int16_t *)v7] != 2 && *(int16_t *)(v7 + 15) > 0 )
    {
      v8 = 0;
      do
      {
        v9 = 313 * a1 + dword_192864 + 11 * (int16_t)v8;
        v23[(int16_t)v8++] = *(char *)(v9 + 90);
        *(_BYTE *)(v9 + 90) = -1;
      }
      while ( (int16_t)v8 < 8 );
      for ( i = 0; i < 8 && *(int16_t *)(dword_192B14 + 26 * (int16_t)v31) > 0; ++i )
      {
        v11 = *(_WORD *)(11 * i + dword_192864 + 313 * a1 + 82);
        v35 = v11 == 13;
        v12 = (int16_t)v23[i];
        if ( g_orion150 )   /* 1.50 36D60: call sub_1E2502 - sub_27F9F is not called, eax stays a1; v12 == -1 jumps to the
          end of the step (36E67) unless !dl and byte 1E2969 == 1 */
        {
          if ( v12 == -1 && (v35 || *Hook150_Ecode(0x1E2969) != 1) )
            goto LABEL_150_36E67;
          v13 = (uint8_t)a1;
        }
        else
          v13 = sub_27F9F(a1);   /* wave 184: 36D60 result (eax = movsx si = a1) */
        v14 = v12 != -1;
        v15 = v11 == 13 && v14 && (v13 || g_orion150);   /* 1.50 036D76: al not tested */
        v16 = v15;
        v26 = 313 * a1;
        v17 = dword_192864 + v26 + 11 * i;
        *(_BYTE *)(v17 + 90) = 1;
        if ( !byte_17F80F[28 * v11] && (*(_BYTE *)(v17 + 86) & 4) != 0 || v16 || v11 == 33 )
        {
          v29 = v32 - v30;
          v28 = v34 - v33;
          if ( g_orion150 || v11 != 13   /* 1.50 036DDA: always loc_36E3D */
            || (v25 = (int16_t)v29, !((int16_t)v29 % 20))
            && !((int16_t)v28 % 20)
            && (v18 = 313 * a1 + dword_192864, v24 = *(uint8_t *)(v18 + 33), v27 = 20, v25 / 20 == v24)
            && (int16_t)v28 / 20 == *(uint8_t *)(v18 + 34) )
          {
            sub_38B5E(
              *(int16_t *)(26 * (int16_t)v31 + dword_192B14 + 9),
              *(int16_t *)(26 * (int16_t)v31 + dword_192B14 + 11),
              1);
          }
        }
LABEL_150_36E67:
        v19 = 11 * i;
        *(_BYTE *)(313 * a1 + dword_192864 + v19 + 90) = -1;
      }
      LOWORD(v7) = 0;
      do
      {
        v20 = 11 * (int16_t)v7 + dword_192864 + 313 * a1;
        v21 = v23[(int16_t)v7];
        LOWORD(v7) = v7 + 1;
        *(_BYTE *)(v20 + 90) = v21;
      }
      while ( (int16_t)v7 < 8 );
    }
  }
  return v7;
}
// 38B5E: using guessed type _DWORD sub_38B5E(_DWORD, _DWORD, int16_t);
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (00036ED1) --------------------------------------------------------
void sub_36ED1( int a1, int a2, int a3, int a4, int a5)
{
  int16_t i; // si
  int v6; // eax
  int16_t v7; // di
  int16_t v8; // ax
  signed int v9; // edx
  int16_t v10; // dx
  int v11; // eax
  char v12; // al
  int v13; // eax
  int v14; // edx
  char v15; // bl
  _WORD v19[8]; // [esp+10h] [ebp-30h]
  int v20; // [esp+20h] [ebp-20h]
  int v21; // [esp+24h] [ebp-1Ch]
  int v22; // [esp+28h] [ebp-18h]
  int v23; // [esp+2Ch] [ebp-14h]
  int v24; // [esp+30h] [ebp-10h]
  int v25; // [esp+34h] [ebp-Ch] BYREF
  int v26; // [esp+38h] [ebp-8h]
  int v27; // [esp+3Ch] [ebp-4h] BYREF

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  if ( g_orion150 && word_17D853 && *Hook150_Eseg(0x23F0DE) != 1 )   /* 1.50 036EE8: sub_1E24DF */
    return;
  if ( *(_BYTE *)(dword_192864 + 313 * a1 + 64) != 4 )
  {
    for ( i = 0; i < word_1998C0 && !(uint16_t)sub_3897A(a1); ++i )
    {
      v20 = 313 * i;
      if ( *(_BYTE *)(dword_192864 + v20 + 32) != *(_BYTE *)(313 * a1 + dword_192864 + 32) && Hook150_1E1B8A(i) )   /* 1.50 036F38 */
      {
        v6 = v20 + dword_192864;
        if ( *(_BYTE *)(v20 + dword_192864 + 64) != 1 && *(_BYTE *)(v6 + 64) != 4
          && (g_orion150 ? *(int8_t *)(v6 + 177) > 0 : *(_BYTE *)(v6 + 177) != 0) )   /* 1.50 036F6A */
        {
          sub_49ED1(a1, &v27, &v25);
          v7 = Hook150_1E25B8(i, v27 + a2, v25 + a3);   /* 1.50 036F90 */
          v8 = Hook150_1E25B8(i, v27 + a4, v25 + a5);   /* 1.50 036FAB */
          if ( v7 < 1 )
            v7 = 1;
          if ( v7 <= 8 && (g_orion150 || v7 <= v8) )   /* 1.50 036FC8: sub_1E24C5 drops v7 <= v8 */
          {
            if ( g_orion150 && *Hook150_Eseg(0x23F0D7) == 1 )   /* 1.50 036FC8: sub_1E24C5 - the chance from byte 23CDBF[v7] */
              v9 = *Hook150_Eseg(0x23CDBF + v7);
            else
            {
              int b = *(uint8_t *)(dword_192864 + 313 * i + 177);

              if ( g_orion150 && !word_199890 )   /* 1.50 036FDD, 036FE2: sub_1E2463 */
              {
                b /= 3;
                if ( b <= 0 )
                  b = 1;
              }
              v9 = (int16_t)(100 * (9 - v7) / (9 - (b + 2) / 3));
            }
            if ( (int)sub_1247A0(0x64u) <= v9 )
            {
              v26 = 0;
              do
              {
                v10 = v26;
                v21 = i;
                v23 = 313 * i;
                v11 = 11 * (int16_t)v26 + v23 + dword_192864;
                v24 = 11 * (int16_t)v26;
                v19[(int16_t)v26] = *(char *)(v11 + 90);
                if ( byte_17F80F[28 * *(int16_t *)(v11 + 82)]
                  || *(char *)(v11 + 90) == -1
                  || (*(_BYTE *)(v11 + 86) & 2) != 0
                  || (*(_BYTE *)(v11 + 86) & 4) != 0 )
                {
                  *(_BYTE *)(dword_192864 + 313 * i + 11 * (int16_t)v26 + 90) = -1;
                }
                else if ( (int16_t)sub_289C4(v21, v10, a1, 0, v7) <= 0 )
                {
                  *(_BYTE *)(v24 + v23 + dword_192864 + 90) = -1;
                }
                else
                {
                  *(_BYTE *)(v24 + v23 + dword_192864 + 90) = 1;
                }
                ++v26;
              }
              while ( (int16_t)v26 < 8 );
              v22 = 313 * i;
              sub_38B5E(
                i,
                (int16_t)(20 * *(uint8_t *)(v22 + dword_192864 + 33)),
                (int16_t)(20 * *(uint8_t *)(v22 + dword_192864 + 34)),
                a1,
                a2,
                a3,
                0);
              v12 = sub_37173(i);   /* wave 184: 3711C result */
              *(_BYTE *)(v22 + dword_192864 + 177) = v12;
              v13 = 0;
              do
              {
                v22 = 313 * i;
                v14 = v22 + dword_192864 + 11 * (int16_t)v13;
                v15 = v19[(int16_t)v13++];
                *(_BYTE *)(v14 + 90) = v15;
              }
              while ( (int16_t)v13 < 8 );
            }
          }
        }
      }
    }
  }
  return;   /* vlna 79: JUMPOUT byl NO-OP, cil 0x3581B je epilog funkce */
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00037173) --------------------------------------------------------
int sub_37173( int a1)
{
  int16_t v1; // cx
  int16_t v2; // dx
  int v3; // eax
  int16_t v4; // si
  int16_t i; // di
  _BYTE *v6; // edx
  _BYTE *v7; // eax
  int16_t v8; // dx
  int16_t v9; // ax
  int16_t v10; // ax

  v1 = -1;
  v2 = 0;
  while ( 1 )
  {
    v3 = 11 * v2 + dword_192864 + 313 * a1;
    v4 = *(_WORD *)(v3 + 82);
    if ( v4 > 0
      && !byte_17F80F[28 * v4]
      && (*(_BYTE *)(v3 + 86) & 2) == 0
      && (*(_BYTE *)(v3 + 86) & 4) == 0
      && *(_BYTE *)(v3 + 91) )
    {
      v1 = 24;
    }
    if ( ++v2 >= 8 )
    {
      if ( v1 > 0 )
      {
        for ( i = 1; i < word_1998C0; ++i )
        {
          v6 = (_BYTE *)(dword_192864 + 313 * a1);
          v7 = (_BYTE *)(313 * i + dword_192864);
          if ( v6[32] != v7[32] && !v7[176] && !v7[36] )
          {
            v8 = sub_3F95F(i, (uint8_t)v6[33], (uint8_t)v6[34]);
            v9 = sub_4528F(i);   /* wave 184: 37229 result */
            v10 = v8 - v9;
            if ( v10 <= 0 )
              v10 = 1;
            if ( v10 < v1 )
              v1 = v10;
          }
        }
      }
      return v1;   /* wave 184: 3724D mov eax, ecx */
    }
  }
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00037254) --------------------------------------------------------
int sub_37254( int a1, int a2)
{
  int16_t v2; // di
  int16_t v3; // si
  int16_t i; // bx
  int v4; // ecx

  v2 = 0;
  v3 = 0;
  v4 = -1;
  for ( i = 0; i < 39 && !v3; ++i )
  {
    if ( (uint16_t)sub_1276F0(313 * (int16_t)a1 + dword_192864 + 76, i) )
    {
      if ( v2 == (int16_t)a2 )
      {
        v3 = 1;
        v4 = i;   /* wave 184: 3729B mov ecx, ebx */
      }
      else
      {
        ++v2;
      }
    }
  }
  return v3 ? v4 : -1;   /* wave 184: 372B6 mov eax, ecx */
}
// 192864: using guessed type int dword_192864;


//----- (000372BD) --------------------------------------------------------
int sub_372BD( int a1, _WORD *a2)
{
  char v4[80]; // [esp+0h] [ebp-50h] BYREF

  sub_58F1E(41, v4, 80);
  return sub_34FC3(0, (*(uint8_t *)(313 * a1 + dword_192864 + 175) + 1) / 2, (int)v4, a2);
}
// 192864: using guessed type int dword_192864;


//----- (00037308) --------------------------------------------------------
/* wave 184: rewritten from asm 37308-37DA7 (moved-ebp frame: enter 374h; push eax/edx/ebx;
   sub ebp, 82h). Hit-and-run raid of marines: a1 = eax attacker ship, a2 = edx target ship,
   a3 = ebx -> troops (word, written back). Each trooper rolls rng(100) against the defence;
   over 20 hits two systems (sub_384A8), over 50 kills a defender, under -50 is lost. */
/* 1.50 sub_37308 (31 hooks, sub_1E2DE7): every strcpy/strcat into the text goes to the combat log
   (sub_1FC9A3) instead, the text stays empty; the display hooks of 1.50 do not read it
   1.50 0375C2, 0375ED, 037614, 037634, 03765F, 03767B, 0376F5, 037732
   1.50 037794, 0377D1, 0377ED, 03784F, 037898, 0378B4, 037924, 03794B
   1.50 037972, 0379C9, 0379E8, 037A1D, 037A3E, 037A65, 037AA6, 037AEA
   1.50 037B04, 037B20, 037B74, 037BD4, 037BEE, 037C0A, 037C65 */
#define CAT_37308(s) ( g_orion150 ? Hook150_1E2DE7(s) : (void)strcat(v2F2, (s)) )
#define CPY_37308(s) ( g_orion150 ? Hook150_1E2DE7(s) : (void)strcpy(v2F2, (s)) )
void sub_37308(int a1, int a2, int a3, int a4)
{
  int16_t v2F6 = (int16_t)a1;   // [ebp-2F6h]
  int16_t v2FA = (int16_t)a2;   // [ebp-2FAh]
  int16_t *v2FE = (int16_t *)(intptr_t)a3;   // [ebp-2FEh]
  int16_t v_cnt[19];            // [ebp+12h]: 0 = drive (5), 1 = computer (2), 2 = shields (8),
                                //            3..10 weapon slots (3), 11..18 specials (9)
  int v4A;                      // [ebp+4Ah] systems hit
  int16_t v66;                  // [ebp+66h] defenders left
  int16_t v62;                  // [ebp+62h] attackers left
  int v56, v6A;                 // attack / defence strength
  int16_t v42, v4E;             // [ebp+42h] slot, [ebp+4Eh] system
  int16_t v46;                  // [ebp+46h]
  uint8_t v_A[56], v_B[56];     // [ebp-5Eh] [ebp-26h] sub_EC767 records (+4 = strength)
  char vFE[80];                 // [ebp-0FEh]
  char vAE[80];                 // [ebp-0AEh] title
  char v2F2[500];               // [ebp-2F2h] text
  char v26[16];                 // [ebp+3Ah] number
  uint8_t *v_s1, *v_s2;
  int16_t v_si, v_di, v52, i;
  int v_snd, v_flag, v_n;
  int16_t v_side;

  (void)a4;
  v_s1 = (uint8_t *)(intptr_t)(dword_192864 + 313 * v2F6);
  v_s2 = (uint8_t *)(intptr_t)(dword_192864 + 313 * v2FA);
  v4A = 0;
  if ( v_s1[32] == v_s2[32] )
    return;   /* 37342 */
  for ( i = 0; i < 19; ++i )
    v_cnt[i] = 0;
  v66 = v_s2[175];
  v62 = *v2FE;
  v56 = sub_35FDA(v_s1[32]) + (int16_t)sub_35CAD(v2F6);   /* 3739E */
  v6A = sub_35FDA(v_s2[32]) + sub_360AA(v_s2[32]) + 20 * sub_4B0D3(v2FA, 29) + (int16_t)sub_35CAD(v2FA);
  sub_EC767(v_s1[32], *v2FE, (int16_t)v56, v_s2[32], v66, (int16_t)v6A, (int16_t *)v_A, (int)(intptr_t)v_B);
  v56 = *(int *)&v_A[4];   /* 37422 */
  v6A = *(int *)&v_B[4];
  for ( v52 = 0; v52 < *v2FE; ++v52 )   /* 3743A: one roll per trooper */
  {
    v46 = 50;
    v_si = (int16_t)(v56 + sub_1247A0(100));
    v_si = (int16_t)(v_si - (sub_1247A0(100) + v6A));
    if ( v_si > 20 )
    {
      for ( v_di = 0; v_di < 2; ++v_di )   /* 3746B */
      {
        sub_384A8(v2FA, (_WORD *)&v4E, (_WORD *)&v42);
        if ( v4E == -1 )
          continue;
        switch ( (uint16_t)v4E )
        {
          case 5:
            ++v_cnt[0];
            break;
          case 2:
            ++v_cnt[1];
            break;
          case 8:
            ++v_cnt[2];
            break;
          case 3:
            ++v_cnt[3 + v42];
            break;
          case 9:
            ++v_cnt[11 + v42];
            break;
        }
        sub_35251(v2FA, &v46, v4E, v42, 0);   /* 374F1 */
      }
    }
    if ( v_si > 50 && v66 > 0 )
      --v66;
    if ( v_si < -50 )
      --v62;
  }
  for ( i = 0; i < 19; ++i )   /* 37534 */
    v4A += v_cnt[i];
  sub_58F1E(42, vFE, 80);
  strcpy(vAE, vFE);
  strcat(vAE, (char *)v_s2);   /* + the target ship name */
  sub_58F1E(92, vFE, 80);
  CPY_37308(vFE);
  sprintf(v26, "%d", (int16_t)v56);   /* 1.50 0375E6: the text cut to "" - it is not used */
  CAT_37308(v26);
  CAT_37308((char *)&asc_178CD8);
  sub_58F1E(93, vFE, 80);
  CPY_37308(vFE);   /* 37633: the original copies over the line built above */
  sprintf(v26, "%d", (int16_t)v6A);
  CAT_37308(v26);
  CAT_37308((char *)&asc_178CE3);
  if ( (int16_t)v4A > 0 )   /* 37684 */
  {
    v_n = (int16_t)sub_3897A(v2FA);
    if ( v_n > 0 )
      sub_39E15(v2FA, (int16_t)(20 * v_s2[33]), (int16_t)(20 * v_s2[34]), v_n);
    if ( v_cnt[0] > 0 )
    {
      sub_58F1E(43, vFE, 80);
      CAT_37308(vFE);
    }
    if ( v_cnt[1] > 0 )   /* 376FE */
    {
      sub_58F1E(44, vFE, 80);
      CAT_37308(vFE);
      sub_58F1E(*(int16_t *)(v_s2 + 308) > 0 ? 45 : 46, vFE, 80);
      CAT_37308(vFE);
    }
    if ( v_cnt[2] > 0 )   /* 3779D */
    {
      sub_58F1E(21, vFE, 80);
      CAT_37308(vFE);
      CAT_37308((char *)&off_178CE6);
      sub_58F1E(*(int16_t *)(v_s2 + 258) > 0 ? 45 : 46, vFE, 80);
      CAT_37308(vFE);
    }
    for ( i = 0; i < 8; ++i )   /* 3785F: weapon slots */
    {
      if ( v_cnt[3 + i] <= 0 )
        continue;
      sprintf(v26, "%d", v_cnt[3 + i]);
      CAT_37308(v26);
      CAT_37308((char *)&off_178CE6);
      CAT_37308(WEAPON_NAME(v_cnt[3 + i] > 1 ? 0x7807 : 0x7803, *(int16_t *)(v_s2 + 11 * i + 82)));
      CAT_37308((char *)&off_178CE6);
      sub_58F1E(46, vFE, 80);
      CAT_37308(vFE);
    }
    for ( i = 0; i < 8; ++i )   /* 37990: specials */
    {
      if ( v_cnt[11 + i] <= 0 )
        continue;
      sprintf(v26, "%d", g_orion150 ? 1 : v_cnt[11 + i]);   /* 1.50 0379B1: mov eax, 1 */
      CAT_37308(v26);
      CAT_37308((char *)&off_178CE6);
      CAT_37308((char *)(intptr_t)*(int *)((char *)&off_17EEE0 + 47 * (int16_t)sub_37254(v2FA, i)));
      CAT_37308((char *)&off_178CE6);
      /* 1.50 037A47: sub_1E2DC2 - 45 while the special still works */
      sub_58F1E(g_orion150 && *(int16_t *)(v_s2 + 292 + 2 * i) > 0 ? 45 : 46, vFE, 80);
      CAT_37308(vFE);
    }
  }
  else
  {
    sub_58F1E(47, vFE, 80);   /* 37A7D */
    CAT_37308(vFE);
  }
  if ( v62 < *v2FE )   /* 37AAF: attackers lost */
  {
    sprintf(v26, "%d", *v2FE - v62);
    CAT_37308((char *)&off_178CE6 + 2);
    CAT_37308(v26);
    CAT_37308((char *)&off_178CE6);
    sub_58F1E(*v2FE - v62 > 1 ? 95 : 94, vFE, 80);
    CAT_37308(vFE);
  }
  if ( v_s2[175] > v66 )   /* 37B7D: defenders lost */
  {
    sprintf(v26, "%d", v_s2[175] - v66);
    CAT_37308((char *)&off_178CE6 + 2);
    CAT_37308(v26);
    CAT_37308((char *)&off_178CE6);
    sub_58F1E(v_s2[175] - v66 > 1 ? 97 : 96, vFE, 80);
    CAT_37308(vFE);
  }
  v_snd = sub_147D7(67);   /* 37C6E */
  v_side = (int16_t)v_s1[32] == word_1998AC ? word_192B12 : word_192B10;
  if ( !v_side && v_s2[32] < 8u && *(uint8_t *)(intptr_t)(dword_197F98 + 3753 * v_s2[32] + 40) == 100 )
    v_flag = 0;
  else if ( word_199900
         || v_s1[32] >= 8u
         || *(uint8_t *)(intptr_t)(dword_197F98 + 3753 * v_s1[32] + 40) != 100 )
    v_flag = 1;
  else
    v_flag = 0;
  if ( v_flag )
    if ( g_orion150 )   /* 1.50 37D4A */
      Hook150_1E2DF1((int)(intptr_t)vAE, 54);
    else
      sub_A5EBC((int)(intptr_t)vAE, (int)(intptr_t)v2F2, 54);
  else
    Hook150_1FB7E3((int)(intptr_t)vAE, (int)(intptr_t)v2F2);   /* 1.50 37D5D */
  sub_112C96(v_snd, 10);
  v_s2[175] = (uint8_t)v66;   /* 37D6E */
  *v2FE = v62;
  sub_2C601(0, 0);
}
#undef CAT_37308
#undef CPY_37308
// 37863: inconsistent variable size for '^3D4.16'
// 378BD: inconsistent variable size for '^3D4.16'
// 3742B: inconsistent variable size for '^3E8.16'
// 3751D: inconsistent variable size for '^3E8.16'
// 37989: inconsistent variable size for '^3F8.8'
// 37A6E: inconsistent variable size for '^3F8.8'
// 37391: inconsistent variable size for '^400.8'
// 3751A: inconsistent variable size for '^400.8'
// 37D92: inconsistent variable size for '^400.8'
// A5EBC: using guessed type int sub_A5EBC(_DWORD, _DWORD, _DWORD);
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 178CE6: using guessed type _UNKNOWN *off_178CE6;
// 17EEE0: using guessed type _UNKNOWN *off_17EEE0;
// 17F803: using guessed type _UNKNOWN *off_17F803;
// 17F807: using guessed type _UNKNOWN *off_17F807;
// 192864: using guessed type int dword_192864;
// 192B10: using guessed type int16_t word_192B10[];
// 192B12: using guessed type int16_t word_192B12;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 1998AC: using guessed type int16_t word_1998AC;
// 199900: using guessed type int16_t word_199900;


//----- (00037DA8) --------------------------------------------------------
/* wave 184: rewritten from asm 37DA8-3830F (moved-ebp frame: enter 328h; push eax/edx/ebx/ecx;
   sub ebp, 7Eh; retn 4). Boarding combat: a1 = eax attacker ship, a2 = edx target ship,
   a3 = ebx attacking troops, a4 = ecx x, a5 = stack y (for sub_38312). */
void sub_37DA8(int a1, int a2, int a3, int a4, int a5)
{
  int16_t v2AE = (int16_t)a1; // [ebp-2AEh]
  int16_t v2B2 = (int16_t)a2; // [ebp-2B2h]
  int16_t v2B6 = (int16_t)a3; // [ebp-2B6h] attackers left
  int16_t v56;                // [ebp+56h] defenders left
  int v4E, v5A, v5E, v62, v66, v6A;   // values for the report text (sub_103C5B)
  uint8_t v_A[56];            // [ebp-16h] attacker record (+4 word, +19h, +33h)
  uint8_t v_B[56];            // [ebp+22h] defender record
  char v2AA[500];             // [ebp-2AAh] report text
  char vB6[80];               // [ebp-0B6h]
  char v66s[80];              // [ebp-66h] title
  uint8_t *v_s1, *v_s2;
  int v_edi, v_dx, v_cx, v_snd;
  int16_t v_side;

  v_s1 = (uint8_t *)(intptr_t)(dword_192864 + 313 * v2AE);
  v_s2 = (uint8_t *)(intptr_t)(dword_192864 + 313 * v2B2);
  if ( v_s1[32] == v_s2[32] )
    return;   /* 37DDC */
  v56 = v_s2[175];
  v62 = v2B6;
  v4E = v56;
  v_edi = sub_35FDA(v_s1[32]);
  v_dx = sub_35FDA(v_s2[32]) + sub_360AA(v_s2[32]);   /* 37E28 */
  if ( g_orion150 )   /* 1.50 037DFD, 037E02, 037E0D, 037E10, 037E15: sub_1E7D47 adds sub_35CAD of the ship */
  {
    v_edi += (int16_t)sub_35CAD(v2AE);
    v_dx += (int16_t)sub_35CAD(v2B2);
  }
  v_dx += 20 * sub_4B0D3(v2B2, 29);
  sub_EC767(v_s1[32], v2B6, (int16_t)v_edi, v_s2[32], v56, (int16_t)v_dx, (int16_t *)v_A, (int)(intptr_t)v_B);
  while ( v56 > 0 && v2B6 > 0 )   /* 37E72: one round per call */
  {
    sub_EC4FE(v_A, v_B);
    if ( (int8_t)v_A[25] > -1 )
      --v2B6;
    if ( (int8_t)v_B[25] > -1 )
      --v56;
  }
  v5A = v2B6;   /* 37EAD */
  v66 = v56;
  v6A = v4E - v56;
  v5E = v62 - v2B6;
  sub_58F1E(48, vB6, 80);
  strcpy(v66s, vB6);
  strcat(v66s, (char *)v_s2);   /* 37F11: + the target ship name */
  if ( !g_orion150 )   /* 1.50 037F29: jmp loc_37FA7 */
  {
  if ( v_s1[32] >= 8u || *(uint8_t *)(intptr_t)(dword_197F98 + 3753 * v_s1[32] + 40) != 100 )
    *(int16_t *)&v_A[4] -= (int8_t)v_A[51];   /* 37F5B */
  if ( v_s2[32] >= 8u || *(uint8_t *)(intptr_t)(dword_197F98 + 3753 * v_s2[32] + 40) != 100 )
    *(int16_t *)&v_B[4] -= (int8_t)v_B[51];
  }
  sub_103C5B(0, (int)(intptr_t)&v62);   /* 37FA7 */
  sub_103C5B(1, (int)(intptr_t)&v5E);
  sub_103C5B(2, (int)(intptr_t)&v5A);
  sub_103C5B(3, (int)(intptr_t)&v4E);
  sub_103C5B(4, (int)(intptr_t)&v6A);
  sub_103C5B(5, (int)(intptr_t)&v66);
  sub_103C5B(6, (int)(intptr_t)&v_A[4]);
  sub_103C5B(7, (int)(intptr_t)&v_B[4]);
  memcpy(v2AA, &unk_178CEA, 3);   /* 38027 movsw; movsb */
  sub_58F1E(92, vB6, 80);
  strcat(v2AA, vB6);
  strcat(v2AA, (char *)&byte_178CED);
  sub_58F1E(93, vB6, 80);
  strcat(v2AA, vB6);
  sub_58F1E(100, vB6, 80);   /* 380B5 */
  strcat(v2AA, (char *)&byte_178CF7);
  strcat(v2AA, vB6);
  strcat(v2AA, (char *)&byte_178D26);
  strcat(v2AA, vB6);   /* 38104: the same text again */
  strcat(v2AA, aX48X223);
  v_side = (int16_t)v_s2[32] == word_1998AC ? word_192B10 : word_192B12;   /* 3813D */
  if ( !v_side && v_s2[32] < 8u && *(uint8_t *)(intptr_t)(dword_197F98 + 3753 * v_s2[32] + 40) == 100 )
    v_cx = 0;
  else if ( word_199900
         || v_s1[32] >= 8u
         || *(uint8_t *)(intptr_t)(dword_197F98 + 3753 * v_s1[32] + 40) != 100 )   /* 381AB */
    v_cx = 1;
  else
    v_cx = 0;
  if ( v2B6 > 0 )   /* 381F8: the ship is taken */
  {
    v2B6 -= v56;
    v_s2[175] = (uint8_t)v2B6;
    if ( g_orion150 && *Hook150_Eseg(0x23F09C) == 1 )   /* 1.50 038225, 03822A: sub_1E2032 - the crew capped by the hull */
    {
      int8_t cap = (int8_t)dseg[0x180022 - 0x178000 + 36 * (v_s2[37] + (*(int16_t *)(v_s2 + 30) == -1 ? 4 : 0))];

      if ( (int16_t)sub_4B0D3(v2B2, 36) )
        cap = (int8_t)(cap * 2);
      if ( cap < (int8_t)v_s2[175] )
        v_s2[175] = (uint8_t)cap;
    }
    sub_38312(v2B2, (int16_t)a4, (int16_t)a5);
    sub_58F1E(v_s2[36] ? 49 : 50, vB6, 80);
  }
  else
  {
    v_s2[175] = (uint8_t)v56;   /* 38275 */
    sub_58F1E(51, vB6, 80);
  }
  strcat(v2AA, vB6);   /* 382A8 */
  v_snd = sub_147D7(67);
  if ( g_orion150 && word_1998E0 )   /* 1.50 0382CE: sub_1E21BF - no report (esi keeps an old value there, v_snd here) */
    ;
  else
  if ( v_cx )
    sub_A5EBC((int)(intptr_t)v66s, (int)(intptr_t)v2AA, 54);
  else
    sub_A5EB2((int)(intptr_t)v66s, (int)(intptr_t)v2AA);
  sub_112C96(v_snd, 10);
  sub_2C601(0, 0);
}
// 37DFA: inconsistent variable size for '^3A0.16'
// 37EB9: inconsistent variable size for '^3A0.16'
// 37EC7: inconsistent variable size for '^3A0.16'
// 37EDF: inconsistent variable size for '^3B0.8'
// 37EB9: inconsistent variable size for '^3B8.8'
// A5EBC: using guessed type int sub_A5EBC(_DWORD, _DWORD, _DWORD);
// 192864: using guessed type int dword_192864;
// 192B10: using guessed type int16_t word_192B10[];
// 192B12: using guessed type int16_t word_192B12;
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 1998AC: using guessed type int16_t word_1998AC;
// 199900: using guessed type int16_t word_199900;


//----- (00038312) --------------------------------------------------------
int sub_38312( int a1, int a2, int a3)
{
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int result; // eax
  int16_t v9; // bx
  int v10; // eax
  int v11; // edx
  int16_t i; // dx
  int16_t v13; // bx

  v5 = 313 * a1;
  if ( g_orion150 )   /* 1.50 038334: jle loc_38342; 038367, 03836C: sub_1E27F2 */
  {
    if ( *(int16_t *)(v5 + dword_192864 + 173) > -1 )
      sub_941C6(*(_WORD *)(v5 + dword_192864 + 173), a2);
    *(_WORD *)(v5 + dword_192864 + 173) = -1;
    v7 = *(int16_t *)(v5 + dword_192864 + 30);
    if ( v7 != -1 && *(int16_t *)(dword_197F9C + 129 * v7 + 116) != -1 )
      sub_944A3(*(int16_t *)(dword_197F9C + 129 * v7 + 116), 0);
  }
  else
  if ( *(int16_t *)(v5 + dword_192864 + 173) > -1 )
  {
    sub_941C6(*(_WORD *)(v5 + dword_192864 + 173), a2);
    v6 = dword_192864;
    *(_WORD *)(v5 + dword_192864 + 173) = -1;
    v7 = *(int16_t *)(v5 + v6 + 30);
    if ( v7 != -1 )
      *(_WORD *)(dword_197F9C + 129 * v7 + 116) = -1;
  }
  sub_12772A(dword_192864 + 313 * a1 + 72, 4u);
  if ( sub_4B0D3(a1, 24) && (int)sub_1247A0(0xAu) < 6 )
    return sub_39E15(a1, a2, a3, 4);
  if ( *(uint8_t *)(dword_192864 + 313 * a1 + 32) == word_1998AC )
    v9 = word_19988E;
  else
    v9 = word_1998AC;
  *(_BYTE *)(dword_192864 + 313 * a1 + 32) = v9;
  sub_3891E(a1);
  if ( !g_orion150 )   /* 1.50 03840C: nop - sub_4588C comes in sub_1E0E0D below */
    sub_4588C(a1);
  if ( v9 >= 8 || !*(_BYTE *)(3753 * v9 + (uint8_t*)dword_197F98 + 2232) )
    *(_BYTE *)(dword_192864 + 313 * a1 + 176) = 1;
  else if ( g_orion150 && *Hook150_Eseg(0x23F07F) == 1 )   /* 1.50 038425, 03842A: sub_1E4C95 */
    *(_BYTE *)(dword_192864 + 313 * a1 + 176) = 0;
  v10 = 313 * a1;
  v11 = dword_192864;
  *(_BYTE *)(dword_192864 + v10 + 75) = 0;
  if ( g_orion150 )   /* 1.50 03845A: sub_1E1F48 - sub_1E0E0D (sub_4588C with word 23E564 = a1), then the end */
  {
    *(int16_t *)Hook150_Eseg(0x23E564) = (int16_t)a1;
    sub_4588C(a1);
    *(int16_t *)Hook150_Eseg(0x23E564) = -1;
    return v10;
  }
  *(_BYTE *)(v11 + v10 + 66) = -1;
  for ( i = 0; ; ++i )
  {
    result = word_19296C[i];
    if ( result == -10 )
      break;
  }
  while ( i >= 0 )
  {
    result = i;
    v13 = word_19296C[i--];
    word_19296E[result] = v13;
  }
  word_19296C[0] = -1;
  ++word_1998D8;
  ++word_1998EA;
  return result;
}
// 192864: using guessed type int dword_192864;
// 19296C: using guessed type int16_t word_19296C[];
// 19296E: using guessed type int16_t word_19296E[209];
// 197F98: using guessed type int (uint8_t*)dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998D8: using guessed type int16_t word_1998D8;
// 1998EA: using guessed type int16_t word_1998EA;


//----- (000384A8) --------------------------------------------------------
int sub_384A8( int a1, _WORD *a2, _WORD *a3)
{
  int v4; // edi
  int v5; // ebx
  int v6; // eax
  int v7; // ebx
  int16_t v8; // di
  int v9; // eax
  int v10; // ebx
  int16_t v11; // di
  int16_t v12; // di
  int result; // eax
  int16_t v14; // bx
  int16_t v15; // di
  _WORD v17[20]; // [esp+4h] [ebp-38h] BYREF
  int v18; // [esp+2Ch] [ebp-10h]
  int v19; // [esp+30h] [ebp-Ch]
  int v20; // [esp+34h] [ebp-8h]
  int v21; // [esp+38h] [ebp-4h]

  v4 = a1;
  sub_1247A0(0x64u);
  *a2 = -1;
  v18 = sub_36B64(v4);
  memset(v17, 0, 38);
  v5 = dword_192864 + 313 * v4;
  if ( g_orion150 )   /* 1.50 0384F5: sub_1E0369 - 1 counts as 2, then shr 1 */
  {
    int x = *(int16_t *)(v5 + 256);

    v17[0] = (int16_t)((uint32_t)(x == 1 ? 2 : x) >> 1);
  }
  else
  v17[0] = *(int16_t *)(v5 + 256) / 2;
  v17[1] = *(_WORD *)(v5 + 258);
  v6 = 0;
  do
  {
    v7 = (int16_t)v6;
    v8 = *(_WORD *)(313 * a1 + dword_192864 + 2 * (int16_t)v6++ + 260);
    v17[v7 + 2] = v8;
  }
  while ( (int16_t)v6 < 8 );
  v9 = 0;
  do
  {
    v10 = (int16_t)v9;
    v19 = 313 * a1 + dword_192864;
    v11 = *(_WORD *)(v19 + 2 * (int16_t)v9++ + 292);
    v17[v10 + 10] = v11;
  }
  while ( (int16_t)v9 < 8 );
  v12 = 0;
  v17[18] = *(_WORD *)(v19 + 308);
  do
  {
    if ( v17[v12] )
      v17[v12] = (g_orion150 ? 101 : 100) - 100 * (uint16_t)v17[v12] / v18;   /* 1.50 03858C */
    ++v12;
  }
  while ( v12 < 19 );
  result = sub_FE92D((const uint16_t *)v17, 19);
  v14 = result;
  if ( (_WORD)result )
  {
    if ( (_WORD)result == 1 )
    {
      *a2 = 8;
    }
    else
    {
      v15 = 0;
      for ( result = 0; (int16_t)result < 8 && !v15; ++result )
      {
        v20 = v14;
        v21 = (int16_t)result + 2;
        if ( v14 == v21 )
        {
          *a2 = 3;
          v15 = 1;
          *a3 = result;
        }
      }
      if ( !v15 )
      {
        for ( result = 0; (int16_t)result < 8 && !v15; ++result )
        {
          v21 = v14;
          v20 = (int16_t)result + 10;
          if ( v14 == v20 )
          {
            *a2 = 9;
            v15 = 1;
            *a3 = result;
          }
        }
      }
      if ( v14 == 18 )
        *a2 = 2;
    }
  }
  else
  {
    *a2 = 5;
  }
  return result;
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192864: using guessed type int dword_192864;


//----- (00038656) --------------------------------------------------------
int16_t sub_38656( int a1)
{
  int v1; // ebx
  _BOOL2 v2; // dx
  int16_t result; // ax

  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  v1 = 313 * a1;
  v2 = sub_4B0D3(a1, 24);
  result = 5 * word_18002A[18 * *(uint8_t *)(v1 + dword_192864 + 37)];
  if ( g_orion150 && *(uint16_t *)(v1 + dword_192864 + 69) == 0x7FFF )   /* 1.50 038674, 038684: sub_1E2359, sub_1E236F */
  {
    result = (int16_t)(result * 77);
    Hook150_1E91DB(result);
    return result;
  }
  if ( v2 )
    return 15 * word_18002A[18 * *(uint8_t *)(v1 + dword_192864 + 37)];
  return result;
}
// 18002A: using guessed type int16_t word_18002A[];
// 192864: using guessed type int dword_192864;


//----- (0003868F) --------------------------------------------------------
/* wave 184: returns al = [var_8] (38832) - 1 when every ship passed its check */
char sub_3868F( int a1)
{
  int i; // esi
  int16_t v2; // ax
  signed int v3; // edx
  int v4; // ebx
  int16_t v5; // cx
  unsigned int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  int v12; // ebx
  _DWORD v13[2]; // [esp+0h] [ebp-18h] BYREF
  unsigned int v14; // [esp+8h] [ebp-10h]
  int v15; // [esp+Ch] [ebp-Ch] BYREF
  char v16; // [esp+10h] [ebp-8h]
  char v17; // [esp+14h] [ebp-4h]

  if ( g_orion150 )   /* 1.50 038698, 03869D: sub_1E4EDA - the RNG back to its value at sub_FC470 (dword 1E4EEE) */
    dword_1B9E34 = *(int32_t *)Hook150_Ecode(0x1E4EEE);
  v17 = a1;
  v16 = 1;
  for ( i = 1; ; ++i )
  {
    if ( (int16_t)i >= word_1998C0 )
      return v16;   /* wave 184: 38832 mov al, [var_8] */
    v2 = v17
       ? *(uint8_t *)(33 * (int16_t)i + dword_192844 + 1)
       : *(uint8_t *)(dword_192864 + 313 * (int16_t)i + 37);
    v3 = word_180EC8[v2];
    if ( (int)sub_1247A0(0x64u) > v3 )
      break;
    if ( v17 )
    {
      v4 = 33 * (int16_t)i;
      v5 = *(_WORD *)(v4 + dword_192844 + 9);
      v6 = sub_1247A0(0xC9u);
      v13[1] = v6 + 74;
      *(_WORD *)(v4 + dword_192844 + 9) = 0;
      sub_40C2A(i, v6 + 74);
      v7 = v4 + dword_192844;
      *(_WORD *)(v7 + 9) = v5;
      if ( *(_BYTE *)(v7 + 6) != 1 )
        break;
      --word_1998A2;
      *(_BYTE *)(v7 + 6) = 2;
    }
    else
    {
      v8 = 0;
      do
      {
        v9 = (int16_t)v8++;
        *(_WORD *)(dword_192864 + 313 * (int16_t)i + 2 * v9 + 41) = 0;
      }
      while ( (int16_t)v8 < 4 );
      v14 = sub_1247A0(0x191u) + 149;
      while ( (int16_t)v14 > 0 )
      {
        v10 = sub_3897A(i);
        if ( (_WORD)v10 )
          break;
        v15 = 20;
        v13[0] = v10;
        v14 -= 20;
        sub_39985(i, (int16_t *)&v15, (int16_t *)v13, 0, 0, 0, 0, 0, 0);
      }
      if ( (uint16_t)sub_3897A(i) )
      {
        *(_BYTE *)(dword_192864 + 313 * (int16_t)i + 36) = 5;
      }
      else
      {
        v16 = 0;
        v15 = sub_494A8(i, i);
        v11 = 0;
        do
        {
          v12 = 2 * (int16_t)v11++ + 313 * (int16_t)i + dword_192864;
          *(_WORD *)(v12 + 41) = v15;
        }
        while ( (int16_t)v11 < 4 );
      }
    }
LABEL_21:
    ;
  }
  v16 = 0;
  goto LABEL_21;
}
// 180EC8: using guessed type int16_t word_180EC8[6];
// 192844: using guessed type int dword_192844;
// 192864: using guessed type int dword_192864;
// 1998A2: using guessed type int16_t word_1998A2;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0003883A) --------------------------------------------------------
int sub_3883A( int a1)
{
  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  return sub_1276F0(313 * a1 + dword_192864 + 72, 2u);
}
// 192864: using guessed type int dword_192864;


//----- (00038858) --------------------------------------------------------
int sub_38858( int a1)
{
  a1 = (int16_t)a1;   /* wave 181: the original reads only the low word (movsx) */
  return sub_127712(313 * a1 + dword_192864 + 72, 2u);
}
// 192864: using guessed type int dword_192864;


