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
  _BYTE v7[3]; // [esp+0h] [ebp-4Ch] BYREF
  int16_t v8; // [esp+3h] [ebp-49h]
  char v9; // [esp+5h] [ebp-47h]
  int16_t v10; // [esp+6h] [ebp-46h]

  memset(v7, 0, 73);
  v7[0] = -1;
  v7[2] = 1;
  v7[1] = a1;
  v2 = 0;
  for ( i = 0; i < 49; ++i )
  {
    if ( *(_BYTE *)(i + 361 * a1 + dword_192B18 + 310) )
      ++v2;
  }
  v4 = *(uint8_t *)(dword_192B18 + 361 * a1 + 10) + v2;
  v5 = sub_1247A0(3u);
  v6 = (int)(v4 * (v5 + sub_1247A0(3u))) / 10;
  if ( !(_WORD)v6 )
    LOWORD(v6) = 1;
  v9 = 0;
  v10 = 0;
  v8 = v6;
  sub_DD2F2((int)v7);
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;


//----- (00023833) --------------------------------------------------------
void sub_23833( int a1)
{
  int v2; // ebx
  unsigned int v3; // edx
  _BYTE v4[3]; // [esp+0h] [ebp-4Ch] BYREF
  int16_t v5; // [esp+3h] [ebp-49h]
  char v6; // [esp+5h] [ebp-47h]
  int16_t v7; // [esp+6h] [ebp-46h]

  memset(v4, 0, 73);
  v4[0] = -1;
  v4[2] = 1;
  v5 = 1;
  v6 = 1;
  v4[1] = a1;
  v2 = *(uint8_t *)(dword_192B18 + 361 * a1 + 10);
  v3 = sub_1247A0(3u);
  v7 = (int)(v2 * (v3 + sub_1247A0(3u))) / 10;
  sub_DD2F2((int)v4);
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;


//----- (000238A8) --------------------------------------------------------
int sub_238A8( int a1, _WORD *a2, _WORD *a3)
{
  int16_t v4; // dx
  int16_t i; // ax
  int16_t v6; // dx
  unsigned int v7; // edi
  int v8; // edx
  int result; // eax
  _BYTE v11[3]; // [esp+4h] [ebp-50h] BYREF
  int16_t v12; // [esp+7h] [ebp-4Dh]
  char v13; // [esp+9h] [ebp-4Bh]
  int16_t v14; // [esp+Ah] [ebp-4Ah]
  int16_t v15; // [esp+10h] [ebp-44h]
  _BYTE v16[62]; // [esp+12h] [ebp-42h]
  int v17; // [esp+50h] [ebp-4h]

  memset(v11, 0, 73);
  v11[0] = -1;
  v11[2] = 1;
  v4 = 0;
  v11[1] = a1;
  for ( i = 0; i < 49; ++i )
  {
    v17 = 361 * a1;
    if ( *(_BYTE *)(dword_192B18 + v17 + i + 310) )
      ++v4;
  }
  v6 = *(uint8_t *)(361 * a1 + dword_192B18 + 10) + v4;
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
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;


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
    if ( *(char *)(361 * (int16_t)v3 + dword_192B18) == a1 )
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
// 192B18: using guessed type int dword_192B18;
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

  v2 = 113 * *(uint8_t *)(17 * *(int16_t *)(dword_192B18 + 361 * a1 + 2) + dword_1930D4 + 2) + dword_19306C;
  v3 = *(_WORD *)(v2 + 15);
  v4 = *(_WORD *)(v2 + 17);
  v5 = dword_197F9C + 129 * a2;
  v6 = *(_WORD *)(v5 + 105);
  v7 = v3 - *(int16_t *)(v5 + 103);
  v8 = ((HIDWORD(v7) ^ v7) - HIDWORD(v7)) * ((HIDWORD(v7) ^ v7) - HIDWORD(v7));
  LODWORD(v7) = abs32(v4 - v6);
  return v8 + v7 * v7;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;


//----- (00023A5F) --------------------------------------------------------
void sub_23A5F()
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
          v5 = *(int16_t *)(dword_1930D4 + 17 * v4);
          if ( v5 != -1 )
          {
            v6 = dword_192B18 + 361 * v5;
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
  JUMPOUT(0x231AD);
}
// 23B23: control flows out of bounds to 231AD
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999A: using guessed type int16_t word_19999A;


//----- (00023B28) --------------------------------------------------------
void sub_23B28( int a1)
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
      JUMPOUT(0x2227B);
  }
}
// 23B5F: control flows out of bounds to 2227B
// 197F9C: using guessed type int dword_197F9C;


//----- (00023B64) --------------------------------------------------------
int16_t sub_23B64( int a1)
{
  return *(_WORD *)(361 * a1 + dword_192B18 + 235);
}
// 192B18: using guessed type int dword_192B18;


//----- (00023B7D) --------------------------------------------------------
void sub_23B7D( int a1)
{
  int v1; // esi
  int16_t i; // bx

  v1 = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    if ( !*(_BYTE *)(dword_197F98 + 3753 * i + 36)
      && (uint16_t)sub_1276F0(dword_197F98 + 3753 * a1 + 1412, i)
      && i != a1 )
    {
      sub_1247A0((int16_t)++v1);
    }
  }
  JUMPOUT(0x23D99);
}
// 23BE7: control flows out of bounds to 23D99
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00023BEC) --------------------------------------------------------
void sub_23BEC( int a1)
{
  int16_t v1; // si
  int16_t i; // dx
  int16_t j; // bx
  int v4; // eax
  int v5; // eax
  char *v6; // eax

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
          v5 = *(int16_t *)(dword_1930D4 + 17 * v4);
          if ( v5 != -1 )
          {
            v6 = (char *)(dword_192B18 + 361 * v5);
            if ( !v6[6] && *v6 == a1 )
            {
              if ( ++v1 )
                sub_1247A0(v1);
            }
          }
        }
      }
    }
  }
  JUMPOUT(0x23D99);
}
// 23C9C: control flows out of bounds to 23D99
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999A: using guessed type int16_t word_19999A;


//----- (00023CA1) --------------------------------------------------------
void sub_23CA1( int a1)
{
  int v2; // esi
  int16_t v3; // dx
  int v4; // eax

  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = dword_1930DC + 59 * v3;
    if ( a1 == *(char *)(v4 + 58) && *(char *)(v4 + 57) >= 0 )
      sub_1247A0((int16_t)++v2);
    if ( ++v3 >= 67 )
      JUMPOUT(0x23D9A);
  }
}
// 23CE8: control flows out of bounds to 23D9A
// 1930DC: using guessed type int dword_1930DC;


//----- (00023CED) --------------------------------------------------------
void sub_23CED( int a1)
{
  int v2; // ebx
  int16_t i; // dx
  int v4; // eax

  v2 = 0;
  for ( i = 0; i < word_199994; ++i )
  {
    v4 = dword_197F9C + 129 * i;
    if ( a1 == *(char *)(v4 + 99) && *(_BYTE *)(v4 + 100) <= 1u )
      sub_1247A0((int16_t)++v2);
  }
  JUMPOUT(0x23D9A);
}
// 23D42: control flows out of bounds to 23D9A
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
    if ( a1 == *(char *)(v6 + dword_192B18) && !*(_BYTE *)(v6 + dword_192B18 + 6) && sub_1247A0((int16_t)++v3) == 1 )
      v2 = i;
  }
  return v2;
}
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (00023DA0) --------------------------------------------------------
void sub_23DA0( int a1)
{
  int v2; // ebx
  int16_t i; // dx
  char *v4; // eax

  v2 = 0;
  for ( i = 0; i < word_199996; ++i )
  {
    v4 = (char *)(361 * i + dword_192B18);
    if ( a1 == *v4 && !v4[319] && !v4[6] )
      sub_1247A0((int16_t)++v2);
  }
  JUMPOUT(0x23D97);
}
// 23DFC: control flows out of bounds to 23D97
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (00023DFE) --------------------------------------------------------
bool sub_23DFE( int a1)
{
  return (byte_19AC35 == 2 || byte_19AC35 == 6) && a1 == word_19AC37
      || (byte_19AC7D == 2 || byte_19AC7D == 6)
      && *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(361 * a1 + dword_192B18 + 2) + 2) == word_19AC7F;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
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
    && *(uint8_t *)(17 * *(int16_t *)(dword_192B18 + 361 * a1 + 2) + dword_1930D4 + 2) == word_19AC88 )
  {
    return 25;
  }
  if ( (byte_19AC23 == 2 || byte_19AC23 == 4 || byte_19AC23 == 6)
    && *(uint8_t *)(17 * *(int16_t *)(361 * a1 + dword_192B18 + 2) + dword_1930D4 + 2) == word_19AC25 )
  {
    return 14;
  }
  if ( (byte_19AC7D == 2 || byte_19AC7D == 4 || byte_19AC7D == 6)
    && *(uint8_t *)(17 * *(int16_t *)(361 * a1 + dword_192B18 + 2) + dword_1930D4 + 2) == word_19AC7F )
  {
    return 24;
  }
  return -1;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
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
    && *(uint8_t *)(17 * *(int16_t *)(361 * a1 + dword_192B18 + 2) + dword_1930D4 + 2) == word_19AC88 )
  {
    v5 = 0;
    for ( i = 0; i < word_199998; ++i )
    {
      if ( (((int)*(uint8_t *)(dword_19306C
                                     + 113
                                     * *(uint8_t *)(17 * *(int16_t *)(361 * a1 + dword_192B18 + 2)
                                                          + dword_1930D4
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
    && *(uint8_t *)(17 * *(int16_t *)(dword_192B18 + 361 * a1 + 2) + dword_1930D4 + 2) == word_19AC25 )
  {
    v7 = 0;
    for ( j = 0; j < word_199998; ++j )
    {
      if ( (((int)*(uint8_t *)(dword_19306C
                                     + 113
                                     * *(uint8_t *)(17 * *(int16_t *)(dword_192B18 + 361 * a1 + 2)
                                                          + dword_1930D4
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
    v9 = *(uint8_t *)(17 * *(int16_t *)(361 * a1 + dword_192B18 + 2) + dword_1930D4 + 2);
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
  JUMPOUT(0x23D9A);
}
// 242CA: control flows out of bounds to 23D9A
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
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
    && *(uint8_t *)(17 * *(int16_t *)(361 * word_19ABB9 + dword_192B18 + 2) + dword_1930D4 + 2) == a1 )
  {
    return 2;
  }
  if ( (byte_19AC35 == 2 || byte_19AC35 == 4 || byte_19AC35 == 6)
    && *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * word_19AC37 + 2) + 2) == a1 )
  {
    return 16;
  }
  if ( (byte_19AC3E == 2 || byte_19AC3E == 4 || byte_19AC3E == 6)
    && *(uint8_t *)(17 * *(int16_t *)(dword_192B18 + 361 * word_19AC40 + 2) + dword_1930D4 + 2) == a1 )
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
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
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
      LOWORD(v2) = *(_WORD *)(dword_197F98 + 3753 * i + 60) + v2;
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
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (00024511) --------------------------------------------------------
void sub_24511()
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
    v4 = v3 + dword_197F98;
    if ( !*(_BYTE *)(v3 + dword_197F98 + 36) && *(_BYTE *)(v4 + 2233) == 1 )
    {
      v5 = *(int16_t *)(v4 + 3699) / v0;
      if ( (int)sub_1247A0(0x3E8u) <= v5 )
      {
        v1 = i;
        *(_WORD *)(v3 + dword_197F98 + 3699) = 0;
      }
    }
  }
  JUMPOUT(0x23D97);
}
// 245BF: control flows out of bounds to 23D97
// 197F98: using guessed type int dword_197F98;
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
    v1 = 3753 * i + dword_197F98;
    if ( !*(_BYTE *)(v1 + 36) && *(_BYTE *)(v1 + 2233) == 1 )
      ++*(_WORD *)(v1 + 3699);
  }
}
// 197F98: using guessed type int dword_197F98;
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
      if ( *(_BYTE *)(dword_197F98 + 3753 * i + 40) == 100 )
      {
        for ( j = 0; j < word_199998; ++j )
        {
          v4 = j;
          *(_BYTE *)(v4 + 3753 * i + dword_197F98 + 1412) = 1;
        }
      }
    }
    return sub_2490D(a1);
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
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

  if ( byte_199BEF == 1 )
  {
    word_180EB8 = -1;
    if ( word_180EB4 != 1 && word_180EB4 != 2 && word_180EB4 != 3 )
    {
      sub_113C28(1);
      v0 = sub_113B56();
      while ( v0 > 0 )
      {
        v1 = sub_113B56();
        v0 = v1;
        sub_FE8BE(v1);
      }
      v2 = sub_113A4E();
      word_180EB4 = j___clock(v2, 0, 3) % 3uLL + 1;
      sub_1136EC(aStreamLbx);
      sub_113A20(word_180EB4);
      sub_113BAC(-1);
      word_180EB8 = -1;
      sub_113AF2(0);
      return sub_113CBD(30);
    }
  }
  return result;
}
// FE8BE: using guessed type int sub_FE8BE(_DWORD);
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
        sub_FE8BE((int16_t)v1 / 18, 0, v1, a1);
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
      sub_FE8BE(v1);
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
// FE8BE: using guessed type int sub_FE8BE(_DWORD);
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
  ((void (*)(void))sub_FE8BE)();
  v7 = sub_126C91((int)a1, v6, (int)v11, 0, 1u, 100);
  sub_FE8BE(v7);
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
// FE8BE: using guessed type int sub_FE8BE(_DWORD);
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 199CAE: using guessed type char byte_199CAE;


//----- (00024ACA) --------------------------------------------------------
char sub_24ACA(
        unsigned int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int64_t a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37)
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
  char result; // al
  int16_t v50; // [esp+72h] [ebp-82h]
  int16_t v51; // [esp+76h] [ebp-7Eh]
  int16_t v52; // [esp+7Ah] [ebp-7Ah]
  char *v53; // [esp+7Eh] [ebp-76h] BYREF
  char v54[114]; // [esp+82h] [ebp-72h] BYREF

  v37 = 0;
  for ( *(_DWORD *)((char *)&a29 + 2) = 0; SWORD1(a29) < 200; ++*(_DWORD *)((char *)&a29 + 2) )
  {
    v46 = &v53[SWORD1(a29)];
    if ( !*v46 )
      break;
    switch ( *v46 )
    {
      case -128:
        v54[v37] = 0;
        v38 = (char *)(dword_197F98 + 3753 * v52 + 1);
        goto LABEL_12;
      case -127:
        v54[v37] = 0;
        v38 = (char *)(113 * v51 + dword_19306C);
        goto LABEL_12;
      case -126:
        v38 = (char *)&a19 + 2;
        v54[v37] = 0;
        itoa(SHIWORD(a33), (char *)&a19 + 2, 10, a1);
        goto LABEL_12;
      case -125:
        v40 = v52;
        v54[v37] = 0;
        v41 = v50;
        goto LABEL_9;
      case -124:
        v54[v37] = 0;
        v38 = (char *)(3753 * SHIWORD(a34) + dword_197F98 + 1);
        goto LABEL_12;
      case -123:
        v40 = HIWORD(a34);
        v54[v37] = 0;
        v41 = HIWORD(a35);
LABEL_9:
        v42 = sub_10F7A1(v41, v40);
        goto LABEL_10;
      case -122:
        v54[v37] = 0;
        v39 = v52;
        goto LABEL_5;
      case -121:
        v54[v37] = 0;
        v39 = SHIWORD(a34);
LABEL_5:
        v38 = (char *)(dword_197F98 + 3753 * v39 + 21);
        goto LABEL_12;
      case -120:
        v54[v37] = 0;
        if ( byte_199CAE )
          sprintf((char *)&a19 + 2, "%d,%d", dword_192FD8 / 10, dword_192FD8 % 10);
        else
          sprintf((char *)&a19 + 2, "%d.%d", dword_192FD8 / 10, dword_192FD8 % 10);
        goto LABEL_11;
      case -119:
        v54[v37] = 0;
        v42 = sub_10F772(SHIWORD(a36));
        goto LABEL_10;
      case -118:
        v54[v37] = 0;
        v42 = (char *)sub_77B28(v51);
LABEL_10:
        strcpy((char *)&a19 + 2, v42);
LABEL_11:
        v38 = (char *)&a19 + 2;
LABEL_12:
        v43 = (char *)&v53 + 3;
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
        v54[v45] = v53[SWORD1(a29)];
        break;
    }
  }
  v47 = SHIWORD(a37);
  v54[v37] = 0;
  if ( strlen(v54) >= v47 - 1 )
  {
    v48 = sprintf(v54, "Decode message too long (%d).\n%s", v47, v53);
    sub_126487(v54, SHIDWORD(v48));
  }
  strcpy(v53, v54);
  return result;
}
// 24B03: variable 'v52' is possibly undefined
// 24B4A: variable 'v51' is possibly undefined
// 24B8E: variable 'v50' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 192FD8: using guessed type int dword_192FD8;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199CAE: using guessed type char byte_199CAE;


//----- (00024D30) --------------------------------------------------------
void sub_24D30()
{
  JUMPOUT(0x24E20);
}
// 24D47: control flows out of bounds to 24E20


//----- (00024D4C) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=12)) - nutno dohledat rucne v IDA @ 0x24D64 */
int sub_24D4C(_DWORD _p0, _DWORD _p1, _DWORD _p2, _DWORD _p3)
{
  DECOMP_TODO("call analysis failed (funcsize=12)");
}


//----- (00024D6A) --------------------------------------------------------
void sub_24D6A()
{
  JUMPOUT(0x24D64);
}
// 24D81: control flows out of bounds to 24D64


//----- (00024D83) --------------------------------------------------------
void sub_24D83()
{
  JUMPOUT(0x24D64);
}
// 24D9A: control flows out of bounds to 24D64


//----- (00024D9C) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=18)) - nutno dohledat rucne v IDA @ 0x24DBB */
_DWORD sub_24D9C( int _p0)
{
  DECOMP_TODO("call analysis failed (funcsize=18)");
}


//----- (00024DC5) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=18)) - nutno dohledat rucne v IDA @ 0x24DE6 */
_DWORD sub_24DC5( int _p0, int _p1)
{
  DECOMP_TODO("call analysis failed (funcsize=18)");
}


//----- (00024DF0) --------------------------------------------------------
void sub_24DF0()
{
  JUMPOUT(0x24D5F);
}
// 24E03: control flows out of bounds to 24D5F


//----- (00024E08) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=14)) - nutno dohledat rucne v IDA @ 0x24E20 */
int sub_24E08(_DWORD _p0, _DWORD _p1, _DWORD _p2)
{
  DECOMP_TODO("call analysis failed (funcsize=14)");
}


//----- (00024E27) --------------------------------------------------------
void sub_24E27()
{
  JUMPOUT(0x24E1E);
}
// 24E3C: control flows out of bounds to 24E1E


//----- (00024E3E) --------------------------------------------------------
void sub_24E3E()
{
  JUMPOUT(0x24E1C);
}
// 24E52: control flows out of bounds to 24E1C


//----- (00024E54) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=15)) - nutno dohledat rucne v IDA @ 0x24E6B */
int sub_24E54(_DWORD _p0, _DWORD _p1)
{
  DECOMP_TODO("call analysis failed (funcsize=15)");
}


//----- (00024E73) --------------------------------------------------------
void sub_24E73( int a1)
{
  JUMPOUT(0x24DBB);
}
// 24E91: control flows out of bounds to 24DBB


//----- (00024E96) --------------------------------------------------------
int16_t sub_24E96(int a1)
{
  sub_12F578(dword_19F7C4, a1);
  sub_12E332(0);
  sub_12E1E0(0, 0, (int16_t *)dword_19F7C4, 0);
  return sub_123E6C((int)&unk_17CF00, 1);
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
  sub_123E6C((int)&unk_180EBC, 1);
  word_19ACF4 = 0;
  sub_11C2F0();
  sub_124C08();
  sub_124D41();
  sub_128C32(0, 0, 639, 479, 0);
  sub_1112EC(dword_192EF4, 0);
  v2 = sub_111499(dword_192EF4);
  v3 = sub_110D3C(dword_192EF4, v2 - 100);
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
    sub_123E6C((int)&unk_180EBC, 1);
    sub_131922(0, 255);
    v4 = sub_124ECB();
    v5 = sub_81547(v4, 255);
    sub_12C7CC();
    v6 = sub_124DEC();
    sub_FE8BE((int)v6, 1, 639, a1);
    sub_124ECB();
    word_19ACF4 = 0;
    v1 = sub_251EF(a1);
    v7 = 15;
    sub_123E6C((int)&unk_180EBC, 1);
    v8 = 0;
    PortDebug_Checkpoint("24ED3.loop1.enter", v5);
    while ( !(_WORD)v8 && !v1 )
    {
      static int loop1_iters = 0;
      if ((++loop1_iters % 200) == 0)
        PortDebug_Checkpoint("24ED3.loop1.tick", (sub_12D70B() << 16) | (uint16_t)v5);
      sub_12C2A0();
      LOBYTE(v9) = sub_12C392();
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
        sub_FE8BE(v10, v8, v7, a1);
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
    sub_FE8BE((int)v13, 1, 639, a1);
    sub_124ECB();
    sub_C5C44();
    v14 = 5;
    sub_123E6C((int)&unk_180EBC, 1);
    v8 = 0;
    PortDebug_Checkpoint("24ED3.loop2.enter", v12);
    while ( !(_WORD)v8 )
    {
      static int loop2_iters = 0;
      if ((++loop2_iters % 200) == 0)
        PortDebug_Checkpoint("24ED3.loop2.tick", (sub_12D70B() << 16) | (uint16_t)v12);
      sub_12C2A0();
      LOBYTE(v15) = sub_12C392();
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
        sub_FE8BE(v16, v8, v14, a1);
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
  sub_FE8BE(v17, v8, 639, a1);
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
// 24FE5: variable 'v9' is possibly undefined
// 250E0: variable 'v15' is possibly undefined
// 2515A: variable 'v17' is possibly undefined
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
    sub_FE8BE(v3, a1, a2, a3);
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
    LOBYTE(v4) = sub_12C392();
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
    sub_FE8BE(v5, v2, v1--, a1);
  }
  sub_124C08();
  if ( (_WORD)v2 == 1 )
    word_19ACF4 = v1;
  return v2;
}
// 2520A: variable 'v4' is possibly undefined
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
    v2 = 3753 * i + dword_197F98;
    if ( *(_BYTE *)(v2 + 40) != 100 && !*(_BYTE *)(v2 + 2226) && dword_192FD8 % word_199998 == i )
    {
      for ( j = 0; j < word_199998; ++j )
      {
        if ( j != i )
        {
          v4 = dword_197F98 + 3753 * j;
          if ( *(_BYTE *)(v4 + 40) != 100 && !*(_BYTE *)(v4 + 2226) )
          {
            v5 = j + dword_197F98 + 3753 * i;
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
                    if ( *(_BYTE *)((int16_t)v8 + dword_197F98 + 3753 * i + 279) == 3 )
                    {
                      v9 = 3753 * j + dword_197F98;
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
                    if ( *(_BYTE *)((int16_t)v8 + dword_197F98 + 3753 * j + 279) == 3 )
                    {
                      v11 = 3753 * i + dword_197F98;
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
                      sub_E4204(dword_197F98 + 3753 * i, v14, v13);
                      sub_E4204(3753 * j + dword_197F98, v13, v13);
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
  JUMPOUT(0x25526);
}
// 26BB8: control flows out of bounds to 25526
// 17D916: using guessed type int dword_17D916;
// 17E07F: using guessed type int16_t word_17E07F;
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
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
      v2 = dword_197F98 + 3753 * i;
      if ( *(_BYTE *)(v2 + 40) != 100 && *(_BYTE *)(3753 * j + dword_197F98 + 40) != 100 )
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
                || (v5 = dword_197F98 + 3753 * i, v6 = v5 + j, *(_BYTE *)(v6 + 1583))
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
              v7 = v14 + dword_197F98;
              v8 = v14 + dword_197F98 + 2 * j;
              if ( *(int16_t *)(v8 + 1631) <= 0 )
              {
                if ( *(_BYTE *)(v7 + 39) == 4 && *(_BYTE *)(j + v7 + 1831) == 1 )
                  v11 = -2 * *(_WORD *)(v8 + 1631) + word_180CE8;
                else
                  v11 = word_180CDC[*(uint8_t *)(dword_197F98 + 3753 * i + 39)]
                      - 2 * *(_WORD *)(dword_197F98 + 3753 * i + 2 * j + 1631);
                if ( (int)sub_1247A0(0x64u) < v11 || v15 == 2 )
                {
                  v12 = j + dword_197F98 + 3753 * i;
                  v13 = dword_197F98;
                  *(_BYTE *)(v12 + 1823) += v15;
                  *(_BYTE *)(v13 + 3753 * j + i + 1823) = *(_BYTE *)(v12 + 1823);
                }
                else
                {
                  *(_BYTE *)(dword_197F98 + 3753 * i + j + 1615) = 0;
                }
              }
              else
              {
                v9 = (int16_t)(2 * *(_WORD *)(v8 + 1631));
                if ( (int)sub_1247A0(0x64u) >= v9 )
                {
                  *(_BYTE *)(j + v14 + dword_197F98 + 1615) = 0;
                }
                else
                {
                  v10 = j + v14 + dword_197F98;
                  if ( (char)--*(_BYTE *)(v10 + 1823) < 0 )
                    *(_BYTE *)(v10 + 1823) = 0;
                  *(_BYTE *)(3753 * j + dword_197F98 + i + 1823) = *(_BYTE *)(j + dword_197F98 + 3753 * i + 1823);
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
// 197F98: using guessed type int dword_197F98;
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
    JUMPOUT(0x25526);
  }
  for ( i = 0; ; ++i )
  {
    if ( i >= word_199998 )
    {
      ++v0;
      goto LABEL_72;
    }
    v28 = 3753 * v0;
    if ( *(_BYTE *)(dword_197F98 + v28 + 40) != 100 )
    {
      v2 = 3753 * i + dword_197F98;
      if ( *(_BYTE *)(v2 + 40) != 100
        && !*(_BYTE *)(dword_197F98 + v28 + 2226)
        && !*(_BYTE *)(v2 + 2226)
        && v0 != i
        && sub_1247A0(250 - 40 * (uint8_t)byte_199CB0) == 1 )
      {
        v3 = (_BYTE *)(v28 + dword_197F98 + i);
        if ( v3[1412] == 1 )
          break;
      }
    }
LABEL_69:
    ;
  }
  if ( (char)v3[1575] >= 4 || *(int16_t *)(v28 + dword_197F98 + 2 * i + 1679) < -30 )
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
  if ( *(_BYTE *)(i + dword_197F98 + 3753 * v0 + 1575) == 2 )
    v5 += 40;
  if ( *(_BYTE *)(3753 * v0 + dword_197F98 + i + 1583) )
    v5 += 20;
  for ( j = 0; j < word_199998; ++j )
  {
    if ( j != v0 && j != i )
    {
      if ( *(char *)(dword_197F98 + 3753 * v0 + j + 1575) >= 4 )
        v5 += 10;
      if ( *(char *)(dword_197F98 + 3753 * i + j + 1575) >= 4 )
        v5 += 20;
      if ( *(char *)(dword_197F98 + 3753 * i + j + 1823) > 0 )
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
      if ( *(char *)(dword_197F98 + 3753 * i + v7 + 1575) >= 4 )
      {
        if ( *(_BYTE *)(v31 + dword_197F98 + 40) == 100 )
          ++v33;
        else
          ++v32;
      }
      if ( *(char *)(dword_197F98 + 3753 * v0 + v7 + 1575) >= 4 )
      {
        if ( *(_BYTE *)(v31 + dword_197F98 + 40) == 100 )
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
  v25 = *(int16_t *)(dword_197F98 + v24 + 2 * i + 1679);
  v30 = word_180CCC[*(uint8_t *)(v24 + dword_197F98 + 39)]
      + word_180CCC[*(uint8_t *)(dword_197F98 + 3753 * i + 39)]
      + 50 * v33
      + v5
      + sub_1247A0(0x64u)
      + v25;
  if ( v30 < 200 || *(_BYTE *)(i + v24 + dword_197F98 + 1575) != 1 || v32 )
  {
    if ( v30 < 100 )
      goto LABEL_51;
    v8 = i;
    v11 = i + 3753 * v0 + dword_197F98;
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
  v12 = *(int16_t *)(v27 + dword_197F98 + 2 * i + 1695);
  v26 = v12 + v5 + sub_1247A0(0x64u);
  v13 = dword_197F98 + 3753 * i;
  v29 = word_180CCC[*(uint8_t *)(v13 + 39)] + v26;
  if ( v29 <= 110 || (v14 = i + v27 + dword_197F98, *(_BYTE *)(v14 + 1591)) )
  {
    if ( v29 > 80 )
    {
      v15 = dword_197F98;
      v16 = i + dword_197F98 + 3753 * v0;
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
  v17 = *(int16_t *)(dword_197F98 + 3753 * v0 + 2 * i + 1679);
  v18 = word_180CCC[*(uint8_t *)(dword_197F98 + 3753 * i + 39)] + v5 + sub_1247A0(0x64u) + v17;
  v19 = 0;
  v20 = 0;
  while ( v19 < word_199998 )
  {
    if ( *(int16_t *)(3753 * v0 + dword_197F98 + 2 * i + 1599) < 0 )
      v20 = 1;
    ++v19;
  }
  if ( (int)(word_180CCC[*(uint8_t *)(dword_197F98 + 3753 * v0 + 39)] + v18) > 150 && !v20 )
  {
    sub_500CF(v0, i);
    if ( v21 < 100 && *(_WORD *)(3753 * v0 + dword_197F98 + 174) < *(_WORD *)(3753 * i + dword_197F98 + 174) )
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
// 25ACD: control flows out of bounds to 25526
// 25A03: variable 'v21' is possibly undefined
// 180CCC: using guessed type int16_t word_180CCC[6];
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (00025AD2) --------------------------------------------------------
int sub_25AD2( int a1, int a2)
{
  int v4; // edx
  int result; // eax
  _BYTE *v6; // eax
  int v7; // [esp+4h] [ebp-4h]

  v4 = 3753 * a1 + dword_197F98;
  result = a2;
  if ( *(_BYTE *)(v4 + a2 + 1575) == 2 )
  {
    for ( LOWORD(v7) = 0; ; LOWORD(v7) = v7 + 1 )
    {
      result = v7;
      if ( (int16_t)v7 >= word_199998 )
        break;
      if ( a1 != (_WORD)v7 && *(char *)((int16_t)v7 + dword_197F98 + 3753 * a2 + 1575) >= 4 )
      {
        v6 = (_BYTE *)((int16_t)v7 + dword_197F98 + 3753 * a1);
        if ( (char)v6[1575] < 4 && v6[1412] == 1 && v6[1429] == 1 )
        {
          if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v7 + 40) == 100 )
            sub_4E3B5(-10000, v7, a1, 19, 0, 0);
          *(_BYTE *)(a2 + 3753 * a1 + dword_197F98 + 1927) = v7;
          sub_51078(a1, v7);
        }
      }
    }
  }
  return result;
}
// 25BB0: variable 'v7' is possibly undefined
// 197F98: using guessed type int dword_197F98;
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
        v2 = dword_197F98 + 3753 * (int16_t)i;
        if ( *(_BYTE *)(v2 + 40) != 100 )
        {
          v3 = 3753 * (int16_t)j + dword_197F98;
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
  JUMPOUT(0x25526);
}
// 25C77: control flows out of bounds to 25526
// 197F98: using guessed type int dword_197F98;
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
          if ( *(_BYTE *)(dword_197F98 + v2 + 40) != 100 )
          {
            v3 = 3753 * j + dword_197F98;
            if ( *(_BYTE *)(v3 + 40) != 100 && *(int16_t *)(v3 + 1548) > 0 )
            {
              v4 = i + v3;
              if ( *(_BYTE *)(v4 + 1575) != 2
                && *(_BYTE *)(v4 + 1575) != 3
                && *(int16_t *)(dword_197F98 + v2 + 1548) > 3 * ((uint8_t)byte_199CB2 + 1)
                && sub_1247A0(4u) == 1 )
              {
                v5 = (3 * ((uint8_t)byte_199CB2 + 1) - *(int16_t *)(v2 + dword_197F98 + 1548))
                   / ((uint8_t)byte_199CB2 + 6 - (uint8_t)byte_199CB0);
                v6 = 4 * ((int)(v5 * sub_1247A0(4u)) / 3);
                if ( *(_BYTE *)(dword_197F98 + v2 + 40) != 100 )
                  v6 /= 2;
                sub_4E3B5(v6, i, j, 8, 0, 0);
              }
            }
          }
        }
      }
    }
  }
  JUMPOUT(0x25526);
}
// 25DEC: control flows out of bounds to 25526
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
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
    if ( *(_BYTE *)(v1 + dword_197F98 + 40) != 100
      && !*(_BYTE *)(v1 + dword_197F98 + 36)
      && (!sub_233FA() || sub_233FA() && *(_BYTE *)(v1 + dword_197F98 + 2236) == 1) )
    {
      for ( j = 0; j < word_199998; ++j )
      {
        v3 = j + 3753 * i + dword_197F98;
        if ( *(char *)(v3 + 1575) < 4 || *(_BYTE *)(v3 + 1412) != 1 || i == j )
          v54[j] = 0;
        else
          v54[j] = 3;
        v4 = j;
        v54[v4 + 8] = 0;
      }
      if ( *(_BYTE *)(dword_197F98 + 3753 * i + 39) == 3 )
      {
        for ( k = 0; k < word_199998; ++k )
        {
          v59 = dword_197F98;
          v6 = k + dword_197F98 + 3753 * i;
          if ( *(_BYTE *)(v6 + 1429) == 1 && *(char *)(v6 + 1839) < 1 )
          {
            v60 = 3753 * k;
            if ( !*(_BYTE *)(v60 + v59 + 36) && !v54[k] && i != k )
            {
              sub_500CF(i, k);
              if ( v7 >= 100
                && *(_BYTE *)(v60 + dword_197F98 + 40) != 100
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
        v9 = dword_197F98 + 3753 * m;
        if ( *(_BYTE *)(v9 + 40) != 100 && !*(_BYTE *)(v9 + 36) && i != m )
        {
          v61 = 3753 * i;
          v10 = (_BYTE *)(v61 + dword_197F98 + m);
          if ( v10[1412] == 1 && v10[1429] == 1 && (char)v10[1839] < 1 )
          {
            sub_500CF(i, m);
            if ( v11 >= 100 && !v54[m] )
            {
              v66 = word_199998;
              if ( dword_192FD8 % word_199998 == m )
              {
                v12 = -*(char *)(m + v61 + dword_197F98 + 1559);
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
      if ( *(_BYTE *)(3753 * i + dword_197F98 + 1550) == 1 )
      {
        for ( n = 0; n < word_199998; ++n )
        {
          v15 = dword_197F98 + 3753 * n;
          if ( *(_BYTE *)(v15 + 40) != 100 && !*(_BYTE *)(v15 + 36) && i != n )
          {
            v62 = 3753 * i;
            v16 = n + v62 + dword_197F98;
            if ( *(_BYTE *)(v16 + 1412) == 1 && *(_BYTE *)(v16 + 1429) == 1 )
            {
              sub_500CF(i, n);
              if ( v17 >= 100 && *(char *)(n + v62 + dword_197F98 + 1839) < 1 && !v54[n] )
              {
                v54[n] = 1;
                v54[n + 8] = 113;
              }
            }
          }
        }
      }
      v18 = *(int16_t *)(dword_197F98 + 3753 * i + 2028);
      if ( (int)sub_1247A0(0x64u) < v18 )
      {
        for ( ii = 0; ii < word_199998; ++ii )
        {
          v20 = dword_197F98 + 3753 * ii;
          if ( *(_BYTE *)(v20 + 40) != 100 && !*(_BYTE *)(v20 + 36) && i != ii )
          {
            v63 = 3753 * i;
            v21 = ii + v63 + dword_197F98;
            if ( *(_BYTE *)(v21 + 1412) == 1 && *(_BYTE *)(v21 + 1429) == 1 )
            {
              sub_500CF(i, ii);
              if ( v22 >= 100 && *(char *)(ii + v63 + dword_197F98 + 1839) < 1 && !v54[ii] )
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
        v24 = dword_197F98 + 3753 * jj;
        if ( *(_BYTE *)(v24 + 40) != 100 && !*(_BYTE *)(v24 + 36) && i != jj )
        {
          v25 = 3753 * i + dword_197F98;
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
        v28 = 3753 * kk + dword_197F98;
        if ( *(_BYTE *)(v28 + 40) != 100 && kk != i && !*(_BYTE *)(v28 + 36) )
        {
          for ( mm = 0; mm < word_199998; ++mm )
          {
            v30 = 3753 * mm + dword_197F98;
            if ( *(_BYTE *)(v30 + 40) == 100 && mm != i && !*(_BYTE *)(v30 + 36) && *(char *)(kk + v30 + 1575) >= 4 )
              v54[kk] = 0;
          }
        }
      }
      for ( nn = 0; nn < word_199998; ++nn )
      {
        v32 = dword_197F98 + 3753 * nn;
        if ( *(_BYTE *)(v32 + 40) != 100 && !*(_BYTE *)(v32 + 36) && i != nn )
        {
          v64 = i;
          v33 = 3753 * i + dword_197F98 + nn;
          v65 = 3753 * i;
          if ( *(_BYTE *)(v33 + 1429) == 1 && !v54[nn] )
          {
            v66 = word_199998;
            v34 = dword_192FD8 % word_199998;
            if ( v34 == nn && *(char *)(v33 + 1839) < 1 )
            {
              v35 = 3 * word_180CCC[sub_53E96(v64, v34)];
              v36 = 25 * (uint8_t)byte_199CB0 + sub_1247A0(0xC8u) + 125 + v35;
              if ( *(_BYTE *)(nn + v65 + dword_197F98 + 1575) == 1 )
                v36 += 50;
              if ( *(_BYTE *)(3753 * i + dword_197F98 + nn + 1575) == 2 )
                v36 += 100;
              if ( *(_BYTE *)(dword_197F98 + 3753 * i + nn + 1575) == 3 )
                v36 += 200;
              if ( *(_BYTE *)(3753 * i + dword_197F98 + nn + 1583) )
                v36 += 50;
              if ( *(_BYTE *)(3753 * i + dword_197F98 + nn + 1591) )
                v36 += 50;
              if ( *(_WORD *)(3753 * i + dword_197F98 + 2 * nn + 1599) == 1 )
                v36 += 50;
              if ( *(_WORD *)(3753 * i + dword_197F98 + 2 * nn + 1599) == 2 )
                v36 += 100;
              for ( i1 = 0; i1 < word_199998; ++i1 )
              {
                v55 = i1;
                v56 = 3753 * i1;
                v38 = v56 + dword_197F98;
                if ( *(_BYTE *)(v56 + dword_197F98 + 40) == 100
                  && !*(_BYTE *)(v38 + 36)
                  && i1 != nn
                  && i1 != i
                  && *(_BYTE *)(nn + v38 + 1429) == 1 )
                {
                  v67 = i;
                  sub_500CF(v55, i);
                  if ( v39 > 100 )
                  {
                    sub_500CF(v55, v67);
                    v36 -= v40;
                  }
                }
              }
              sub_500CF(i, nn);
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
          v43 = 3753 * i2 + dword_197F98;
          if ( *(_BYTE *)(v43 + 40) != 100 && i2 != i && !*(_BYTE *)(v43 + 36) )
          {
            for ( i3 = 0; i3 < word_199998; ++i3 )
            {
              v45 = 3753 * i3 + dword_197F98;
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
          if ( *(char *)(i4 + dword_197F98 + 3753 * i + 1839) < 1 && i4 != i )
          {
            if ( *(_BYTE *)(dword_197F98 + 3753 * i4 + 40) == 100 )
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
        v50 = i5 + v58 + dword_197F98;
        if ( *(char *)(v50 + 1839) < 1 && i != i5 )
        {
          if ( *(char *)(v50 + 1575) >= 4 )
            ++v47;
          v66 = 3753 * i;
          if ( *(int16_t *)(v66 + dword_197F98 + 1991) != -1 )
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
            if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v68 + 40) == 100 )
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
  JUMPOUT(0x25526);
}
// 26705: control flows out of bounds to 25526
// 25F30: variable 'v7' is possibly undefined
// 25FED: variable 'v11' is possibly undefined
// 260DF: variable 'v17' is possibly undefined
// 261A1: variable 'v22' is possibly undefined
// 264BE: variable 'v39' is possibly undefined
// 264CB: variable 'v40' is possibly undefined
// 264E9: variable 'v41' is possibly undefined
// 266E5: variable 'v53' is possibly undefined
// 180CCC: using guessed type int16_t word_180CCC[6];
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
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
    v1 = 3753 * i + dword_197F98;
    if ( *(_BYTE *)(v1 + 40) != 100 && !*(_BYTE *)(v1 + 36) )
    {
      for ( j = 0; j < word_199998; ++j )
      {
        if ( i != j )
        {
          v3 = dword_197F98 + 3753 * j;
          if ( *(_BYTE *)(v3 + 40) != 100 && !*(_BYTE *)(v3 + 36) )
          {
            v4 = j + dword_197F98 + 3753 * i;
            if ( (*(_BYTE *)(v4 + 1575) == 4 || *(_BYTE *)(v4 + 1575) == 5)
              && *(_BYTE *)(j + dword_197F98 + 3753 * i + 1412) == 1 )
            {
              v5 = 0;
              for ( k = 0; k < word_199998; ++k )
              {
                v7 = dword_197F98 + 3753 * k;
                if ( *(_BYTE *)(v7 + 40) == 100
                  && !*(_BYTE *)(v7 + 36)
                  && k != i
                  && k != j
                  && *(char *)(k + dword_197F98 + 3753 * i + 1575) >= 4 )
                {
                  ++v5;
                }
              }
              if ( 90 - 15 * (uint8_t)byte_199CB0 - 20 * v5 < *(uint8_t *)(j
                                                                                         + 3753 * i
                                                                                         + dword_197F98
                                                                                         + 1815) )
              {
                sub_27A3D(i);
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
  JUMPOUT(0x25526);
}
// 26898: control flows out of bounds to 25526
// 26856: variable 'v8' is possibly undefined
// 197F98: using guessed type int dword_197F98;
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

  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1575) == 2 && sub_1247A0(0xAu) == 1 )
  {
    v8 = -1;
    for ( i = 0; i < word_199998; ++i )
    {
      if ( i != a1 && i != a2 )
      {
        v5 = a2 + 3753 * i + dword_197F98;
        if ( *(_BYTE *)(v5 + 1575) == 4 || *(_BYTE *)(v5 + 1575) == 5 )
        {
          v6 = (_BYTE *)(i + 3753 * a1 + dword_197F98);
          if ( v6[1412] == 1 && v6[1429] == 1 && (char)v6[1575] < 4 )
            v8 = i;
        }
      }
    }
    if ( v8 != -1 )
    {
      v7 = 3753 * a1 + dword_197F98;
      *(_BYTE *)(a2 + v7 + 1623) = 70;
      *(_BYTE *)(a2 + v7 + 1927) = v8;
      sub_51078(a1, v8);
    }
  }
}
// 197F98: using guessed type int dword_197F98;
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
  v5 = *(char *)(a2 + v12 + dword_197F98 + 1751) + *(char *)(a2 + v12 + dword_197F98 + 1559);
  sub_E5E09(a1);
  v7 = v5 + v6 - 50 * (uint8_t)byte_199CB0 + 150 + 20 * *(int16_t *)(v12 + dword_197F98 + 2 * a2 + 2087);
  if ( *(_BYTE *)(v12 + dword_197F98 + 2227) )
    v7 += 50;
  if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 479) == 3 )
    v7 += 50;
  v14 = 3753 * a2;
  if ( *(_BYTE *)(v14 + dword_197F98 + 39) == 4 && *(_BYTE *)(a1 + v14 + dword_197F98 + 1831) == 1 )
    v8 = word_180CD8;
  else
    v8 = word_180CCC[*(uint8_t *)(3753 * a2 + dword_197F98 + 39)];
  v9 = v8 + v7;
  if ( a3 == 1 )
    v10 = v9 + 150;
  else
    v10 = v13 - 1 + *(int16_t *)(3753 * a1 + dword_197F98 + 2 * a2 + 1711) + v9;
  if ( v10 < 0 )
    return 10000 / (100 - v10);
  else
    return v10 + 100;
}
// 26C08: variable 'v6' is possibly undefined
// 180CCC: using guessed type int16_t word_180CCC[6];
// 180CD8: using guessed type int16_t word_180CD8;
// 197F98: using guessed type int dword_197F98;
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
    if ( *(_BYTE *)(v25 + dword_197F98 + 3753 * a1 + 279) == 3 && sub_E412B(dword_197F98 + 3753 * a2, v25) == 1 )
    {
      sub_FC845(a2, v25);
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
    if ( *(_BYTE *)(v27 + dword_197F98 + 3753 * a2 + 279) == 3 && sub_E412B(dword_197F98 + 3753 * a1, v27) == 1 )
    {
      sub_FC845(a1, v27);
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
    qsort(&dword_19ACF8, v8, 5);
    qsort(&dword_19B11C, v24, 5);
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
// 26DA4: variable 'v10' is possibly undefined
// 26E73: variable 'v14' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 19ACF8: using guessed type int dword_19ACF8;
// 19B117: using guessed type int dword_19B117;
// 19B11C: using guessed type int dword_19B11C;


//----- (00026FBA) --------------------------------------------------------
void sub_26FBA()
{
  sub_1247A0(0x96u);
  JUMPOUT(0x25BC0);
}
// 2707B: control flows out of bounds to 25BC0
// 197F98: using guessed type int dword_197F98;
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
    if ( *(_BYTE *)(i + 3753 * a2 + dword_197F98 + 279) == 3 )
    {
      sub_FC845(a1, i);
      v11 = v10;
      if ( i == 42 && *(_BYTE *)(dword_197F98 + 3753 * a1 + 2207) )
        v11 = 0;
      if ( i == 92 && *(_BYTE *)(dword_197F98 + 3753 * a1 + 2207) != 2 )
        v11 = 0;
      if ( i == 65 && *(_BYTE *)(dword_197F98 + 3753 * a1 + 2207) != 4 )
        v11 = 0;
      if ( i == 77 && *(_BYTE *)(dword_197F98 + 3753 * a1 + 2207) != 6 )
        v11 = 0;
      if ( !sub_E412B(dword_197F98 + 3753 * a1, i) )
        v11 = 0;
      if ( v11 && v11 >= a3 && v11 <= a4 )
      {
        byte_19ACFC[5 * *a7] = i;
        *(int *)((char *)&dword_19ACF8 + 5 * (*a7)++) = v11;
      }
    }
  }
  if ( a8 == 1 && *a7 )
    qsort(&dword_19ACF8, *a7, 5);
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
// 270E2: variable 'v10' is possibly undefined
// 197F98: using guessed type int dword_197F98;
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
  result = (char *)((int16_t)a2 + dword_197F98 + 3753 * a1);
  if ( !result[1623] && result[1575] < 4 )
  {
    sub_26FBA();
    v21 = v4;
    if ( v4 < 10 )
      v21 = 10;
    sub_FD219(a1);
    v5 = 0;
    v6 = 0;
    v7 = 0;
    do
    {
      v19 = 3753 * (int16_t)v24;
      result = (char *)(v19 + dword_197F98);
      if ( *(_BYTE *)(v6 + v19 + dword_197F98 + 279) == 3 )
      {
        sub_FC845(a1, v6);
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
      qsort(&dword_19ACF8, v5, 5);
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
        v16 = dword_197F98 + 3753 * v22;
        result = (char *)(v16 + v15);
        result[1623] = 101;
        *(_DWORD *)(v16 + 4 * v15 + 1935) = v12;
        result[1967] = v20;
      }
    }
  }
  return result;
}
// 2725A: variable 'v4' is possibly undefined
// 272A1: variable 'v8' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 19ACF8: using guessed type int dword_19ACF8;


//----- (0002736E) --------------------------------------------------------
void sub_2736E( int a1, int a2)
{
  if ( *(char *)(3753 * a1 + dword_197F98 + a2 + 1575) < 4 )
  {
    sub_E5E09(a2);
    sub_1247A0(0x64u);
  }
  JUMPOUT(0x25BC0);
}
// 274FB: control flows out of bounds to 25BC0
// 197F98: using guessed type int dword_197F98;
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
  v5 = dword_197F98;
  v6 = dword_197F98 + 3753 * a1;
  v7 = 3753 * a2;
  *(_WORD *)(v6 + 2 * a2 + 2071) = 0;
  result = v4;
  *(_WORD *)(v7 + v5 + 2 * v4 + 2071) = 0;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0002755F) --------------------------------------------------------
int16_t sub_2755F( int a1, int a2, _WORD *a3)
{
  unsigned int v4; // eax
  int v5; // esi
  unsigned int v6; // eax
  int v7; // edi

  LOWORD(v4) = *(_WORD *)(3753 * a1 + dword_197F98 + 2 * a2 + 2087);
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
    v5 = 3753 * a1 + dword_197F98;
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
        v7 = dword_197F98;
        *(_WORD *)(2 * a2 + dword_197F98 + 3753 * a1 + 2087) = v4;
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
// 197F98: using guessed type int dword_197F98;


//----- (000276E6) --------------------------------------------------------
int sub_276E6( int a1, int a2, int a3)
{
  int v5; // edi
  int v6; // edx
  int result; // eax
  int v8; // ebx
  int v9; // ebx

  v5 = a2;
  v6 = 3753 * a1 + dword_197F98;
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
  v9 = dword_197F98 + 3753 * a2;
  *(_WORD *)(2 * a2 + dword_197F98 + 3753 * a1 + 2087) = result;
  *(_WORD *)(v9 + 2 * a1 + 2087) = result;
  return result;
}
// 197F98: using guessed type int dword_197F98;


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
      if ( *(_BYTE *)(dword_197F98 + 3753 * i + 40) == 100 )
      {
        v1 = 0;
        for ( j = 0; j < word_199998; ++j )
        {
          v3 = 3753 * i + dword_197F98 + j;
          if ( *(_BYTE *)(v3 + 1412) && j != i )
          {
            if ( *(_BYTE *)(v3 + 1575) == 1 )
              v1 += 100;
            if ( *(_BYTE *)(dword_197F98 + 3753 * i + j + 1575) == 2 )
              v1 += 200;
            if ( *(_BYTE *)(3753 * i + dword_197F98 + j + 1583) )
              v1 += 50;
            if ( *(_BYTE *)(dword_197F98 + 3753 * i + j + 1591) )
              v1 += 50;
          }
        }
        if ( *(_BYTE *)(dword_197F98 + 3753 * i + 479) == 3 )
          v1 = 2 * (int16_t)v1 / 3;
        if ( byte_199CB0 == 3 )
          LOWORD(v1) = (int16_t)v1 / 2;
        if ( (int16_t)v1 > 0 )
        {
          for ( k = 0; k < word_199998; ++k )
          {
            v5 = dword_197F98 + 3753 * k;
            if ( *(_BYTE *)(v5 + 40) != 100 )
            {
              v6 = (_BYTE *)(k + 3753 * i + dword_197F98);
              if ( v6[1412] )
              {
                if ( !v6[1575] && !v6[1591] && !v6[1583] && *(_BYTE *)(v5 + 39) != 5 )
                {
                  v6[1559] -= (int16_t)v1 / 100;
                  if ( (int)sub_1247A0(0x64u) <= (int16_t)v1 % 100 )
                    --*(_BYTE *)(k + 3753 * i + dword_197F98 + 1559);
                  v7 = 3753 * i + dword_197F98 + k;
                  if ( *(char *)(v7 + 1559) <= -100 )
                    *(_BYTE *)(v7 + 1559) = -100;
                  *(_BYTE *)(i + 3753 * k + dword_197F98 + 1559) = *(_BYTE *)(dword_197F98 + 3753 * i + k + 1559);
                }
              }
            }
          }
        }
      }
    }
  }
  JUMPOUT(0x25526);
}
// 27A38: control flows out of bounds to 25526
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (00027A3D) --------------------------------------------------------
void sub_27A3D( int a1)
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
  int16_t v17; // cx
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

  if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 40) != 100 && dword_192FD8 - 35000 >= 150 )
  {
    v31 = 1;
    v26 = 1;
    for ( i = 0; i < word_199998; ++i )
    {
      if ( i != a1 )
      {
        v3 = 3753 * i;
        if ( !*(_BYTE *)(v3 + dword_197F98 + 36) && *(int16_t *)(v3 + dword_197F98 + 166) > v31 )
          v31 = *(int16_t *)(v3 + dword_197F98 + 166);
      }
    }
    for ( j = 0; j < word_199998; ++j )
    {
      for ( k = 0; k < word_199998; ++k )
      {
        if ( j != a1 && k != a1 && j != k )
        {
          v6 = 3753 * j;
          if ( !*(_BYTE *)(dword_197F98 + v6 + 36) && !*(_BYTE *)(3753 * k + dword_197F98 + 36) )
          {
            v7 = 4 * k + dword_197F98 + v6;
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
        v30 = 3753 * a1 + dword_197F98;
        if ( *(_BYTE *)(m + v30 + 1412) == 1 && !*(_BYTE *)(dword_197F98 + 3753 * m + 36) )
        {
          ++v9;
          v8 += *(_DWORD *)(v30 + 4 * m + 1516);
        }
      }
    }
    if ( v9 > 0 )
      v8 /= v9;
    v11 = 100 * *(int16_t *)(dword_197F98 + 3753 * a1 + 166) / v31;
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
    v14 = *(_WORD *)(3753 * a1 + dword_197F98 + 166);
    if ( v14 < 1 )
      v14 = 1;
    v15 = 0;
    for ( n = 0; n < word_199998; ++n )
    {
      if ( a1 != n )
        v15 += *(_WORD *)(2 * n + 3753 * a1 + dword_197F98 + 1791);
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
        if ( *(_BYTE *)(ii + v27 + dword_197F98 + 1412) == 1 && ii != a1 )
        {
          v24 = 3753 * ii;
          if ( !*(_BYTE *)(v24 + dword_197F98 + 36)
            && sub_E4CD2(a1, ii)
            && *(_BYTE *)(v24 + dword_197F98 + 40) != 100
            && *(char *)(v27 + dword_197F98 + ii + 1575) < 4
            && *(int16_t *)(v24 + dword_197F98 + 166) >= v35 )
          {
            v17 = ii;
            v35 = *(_WORD *)(v24 + dword_197F98 + 166);
          }
        }
      }
      if ( v17 == -1 )
      {
        v33 = 0;
        for ( jj = 0; jj < word_199998; ++jj )
        {
          if ( *(_BYTE *)(jj + dword_197F98 + 3753 * a1 + 1412) == 1 && jj != a1 )
          {
            v20 = 3753 * jj + dword_197F98;
            if ( !*(_BYTE *)(v20 + 36) && *(_BYTE *)(v20 + 40) != 100 && sub_E4CD2(a1, jj) )
            {
              v28 = 3753 * jj;
              if ( *(int16_t *)(v28 + dword_197F98 + 166) < v33 )
              {
                v17 = jj;
                v33 = *(_WORD *)(v28 + dword_197F98 + 166);
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
          if ( *(_BYTE *)(kk + v23 + dword_197F98 + 1412) == 1
            && kk != a1
            && !*(_BYTE *)(3753 * kk + dword_197F98 + 36)
            && sub_E4CD2(a1, kk)
            && *(char *)(dword_197F98 + v23 + kk + 1575) < 4 )
          {
            v25 = 3753 * kk;
            if ( *(int16_t *)(v25 + dword_197F98 + 166) < v34 )
            {
              v17 = kk;
              v34 = *(_WORD *)(v25 + dword_197F98 + 166);
            }
          }
        }
      }
      if ( v17 == -1 && (uint8_t)byte_199CB0 < 3u )
      {
        v32 = 0;
        for ( mm = 0; mm < word_199998; ++mm )
        {
          if ( *(_BYTE *)(mm + dword_197F98 + 3753 * a1 + 1412) == 1
            && mm != a1
            && !*(_BYTE *)(3753 * mm + dword_197F98 + 36)
            && sub_E4CD2(a1, mm) )
          {
            v29 = 3753 * mm;
            if ( *(int16_t *)(v29 + dword_197F98 + 166) > v32 )
              v32 = *(_WORD *)(v29 + dword_197F98 + 166);
          }
        }
      }
    }
  }
  JUMPOUT(0x25526);
}
// 27F21: control flows out of bounds to 25526
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (00027F26) --------------------------------------------------------
void sub_27F26()
{
  int v0; // ebx
  int i; // esi
  int v2; // eax
  int16_t v3; // [esp+0h] [ebp-8h]

  v0 = 0;
  for ( i = 0; ; i += 26 )
  {
    v2 = i + dword_192B14;
    if ( *(_WORD *)(i + dword_192B14 + 6) == v3 && *(int16_t *)v2 > 0 && !*(_BYTE *)(v2 + 8) && sub_2AED2(v3, v0) )
      sub_3BB3D(v0);
    if ( ++v0 >= 300 )
      JUMPOUT(0x2BAFF);
  }
}
// 27F9A: control flows out of bounds to 2BAFF
// 27F47: variable 'v3' is possibly undefined
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (00027F9F) --------------------------------------------------------
void sub_27F9F()
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
  int16_t v9; // [esp+0h] [ebp-30h]
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
      sub_2885A(v9, v0);
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
      && (int16_t)sub_286E8(v9, *(int16_t *)((char *)v5 + 9), *(int16_t *)((char *)v5 + 11)) < 3 )
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
      JUMPOUT(0x27F97);
  }
}
// 28163: control flows out of bounds to 27F97
// 27FE9: variable 'v9' is possibly undefined
// 28036: variable 'v3' is possibly undefined
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00028168) --------------------------------------------------------
void sub_28168( int a1)
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
  if ( *(_BYTE *)(v2 + 32) > 8u || !a1 || !*(_BYTE *)(v2 + 49) )
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
    sub_35FDA(v2);
    v40 = v5;
    sub_35FDA(*(uint8_t *)(v4 + dword_192864 + 32));
    v7 = v6;
    sub_360AA(*(uint8_t *)(v4 + dword_192864 + 32));
    v41 = v7 + v8;
    v9 = 20 * sub_4B0D3(a1, 29) + v7 + v8;
    LOWORD(v10) = sub_35CAD(a1);
    v43 = v10 + v9;
    sub_EC767(v35, 5, v40, *(uint8_t *)(v4 + dword_192864 + 32), 5, v10 + v9, &v31, (int)v29);
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
          if ( (int16_t)sub_286E8(a1, v20, v19) < 3 )
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
          if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v45 + 2232) )
            v28 = 10 * v27;
          else
            v28 = 5 * v27;
          v24 += v28;
        }
      }
      if ( v24 > 0 && (int)sub_1247A0(0x64u) < v24 && !*(_WORD *)(313 * a1 + dword_192864 + 59) )
        v52 = 1;
LABEL_74:
      JUMPOUT(0x2BB00);
    }
    v39 = 313 * i;
    if ( *(_BYTE *)(v39 + dword_192864 + 36) || i == a1 || sub_3E563(i) )
      continue;
    v34 = a1;
    sub_2885A(a1, i);
    v12 = 313 * v34;
    v46 = v13;
    LOWORD(v14) = sub_35CAD(i);
    v44 += v14;
    v35 = dword_192864;
    v33 = v12;
    if ( *(_BYTE *)(v39 + dword_192864 + 32) == *(_BYTE *)(v12 + dword_192864 + 32) )
    {
      if ( (int16_t)v46 > 1 )
      {
        if ( (_WORD)v46 == 2 )
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
    if ( (_WORD)v46 == 2 )
    {
      ++v50;
      goto LABEL_20;
    }
    if ( (int16_t)v46 < 7 && v15 )
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
// 285C1: control flows out of bounds to 2BB00
// 28223: variable 'v5' is possibly undefined
// 28235: variable 'v6' is possibly undefined
// 2824D: variable 'v8' is possibly undefined
// 28277: variable 'v10' is possibly undefined
// 282F4: variable 'v13' is possibly undefined
// 282FE: variable 'v14' is possibly undefined
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 197F98: using guessed type int dword_197F98;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;
// 199998: using guessed type int16_t word_199998;


//----- (000285C6) --------------------------------------------------------
int sub_285C6()
{
  int16_t v0; // si
  int16_t i; // dx
  int v2; // edi
  int v3; // eax
  int result; // eax
  int16_t v5; // [esp+0h] [ebp-8h]
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
// 2860A: variable 'v5' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0002864A) --------------------------------------------------------
void sub_2864A( int a1, int a2, int a3, int a4)
{
  int16_t v5; // si
  int16_t v6; // dx
  int16_t i; // bx
  uint8_t *v8; // eax

  v5 = 0;
  v6 = 0;
  for ( i = (int16_t)sub_3A142(a4, 0) <= 0; i < word_1998C0; ++i )
  {
    v8 = (uint8_t *)(dword_192864 + 313 * i);
    if ( !v8[36] && !v8[176] && v8[32] != a1 )
    {
      ++v6;
      if ( sub_3E563(i) )
        ++v5;
    }
  }
  if ( v6 - v5 < 1 )
    sub_285C6();
  JUMPOUT(0x2BAFF);
}
// 286E3: control flows out of bounds to 2BAFF
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
  return sub_286E8(a1, *(_WORD *)(26 * a2 + dword_192B14 + 9), *(_WORD *)(26 * a2 + dword_192B14 + 11));
}
// 192B14: using guessed type int dword_192B14;


//----- (0002885A) --------------------------------------------------------
void sub_2885A( int a1, int a2)
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
  sub_134637(v12, v13, v21, v16);
  JUMPOUT(0x2B098);
}
// 289BF: control flows out of bounds to 2B098
// 192864: using guessed type int dword_192864;


//----- (000289C4) --------------------------------------------------------
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
    sub_28EAE(a3, v7, 0, *(uint8_t *)(dword_192864 + 313 * a1 + 32));
    v12 = (int16_t)v12;
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
                         *(uint8_t *)(313 * *(int16_t *)(dword_192B14 + 26 * a3 + 4) + dword_192864 + 32),
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
    v13 = ((word_17F819[14 * v6] + word_17F817[14 * v6]) / 2
         - *(int16_t *)((char *)&word_17F6C1 + 59 * *(uint8_t *)(v16 + 38)))
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
       * ((word_17F819[14 * v6] + word_17F817[14 * v6]) / 2
        - *(int16_t *)((char *)&word_17F6C1 + 59 * *(uint8_t *)(dword_192864 + 313 * a3 + 38)))
       * v23;
    goto LABEL_56;
  }
  if ( v6 == 45 )
  {
LABEL_50:
    v12 = 4
        * ((word_17F819[14 * v6] + word_17F817[14 * v6]) / 2
         - *(int16_t *)((char *)&word_17F6C1 + 59 * *(uint8_t *)(dword_192864 + 313 * a3 + 38)))
        * v23;
    goto LABEL_48;
  }
LABEL_56:
  if ( sub_4B0D3(a3, 7) )
    v8 >>= 2;
  if ( !byte_17F80F[28 * v6] || byte_17F80F[28 * v6] == 3 )
    return (v8 + 99) / 0x64;
  return v8;
}
// 28BB6: variable 'v12' is possibly undefined
// 17F6C1: using guessed type int16_t word_17F6C1;
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (00028EAE) --------------------------------------------------------
void sub_28EAE( int a1, int a2, int a3, int a4)
{
  int16_t v4; // [esp+0h] [ebp-14h]

  if ( a1 )
    sub_4B0D3(v4, 13);
  else
    sub_3A142(a2, a3);
  JUMPOUT(0x28EA8);
}
// 290CE: control flows out of bounds to 28EA8
// 28EF1: variable 'v4' is possibly undefined
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int dword_197F98;


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
  if ( a6 || !sub_4B0D3(a3, 13) && (v11 & 0x40) != 0 )
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
  sub_EC0DE(v18, v19, v25, v16, v26);
  return a4 * v23;
}
// 291B4: conditional instruction was optimized away because %arg_4.2==0
// 293CF: variable 'v23' is possibly undefined
// 17F6C1: using guessed type int16_t word_17F6C1;
// 17F815: using guessed type int16_t word_17F815[];
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 199224: using guessed type int16_t word_199224[15];
// 19988E: using guessed type int16_t word_19988E;


//----- (000293D8) --------------------------------------------------------
void sub_293D8(int a1)
{
  int16_t v2; // di
  int16_t *v3; // eax
  int16_t v4; // ax
  int16_t v5; // [esp+0h] [ebp-8h]

  v2 = 0;
  v5 = 0;
  while ( 1 )
  {
    v3 = (int16_t *)(26 * v5 + dword_192B14);
    if ( (_WORD)a1 == v3[3] && (_WORD)a1 != v3[2] && *v3 > 0 )
    {
      sub_28EAE(a1, *(int16_t *)((char *)v3 + 17), a1, *(uint8_t *)(313 * v3[2] + dword_192864 + 32));
      v2 += v4;
    }
    if ( ++v5 >= 300 )
    {
      if ( (_WORD)a1 )
        sub_2BB06(a1, a1);
      else
        sub_2BB06(0, a1);
      JUMPOUT(0x2BAFF);
    }
  }
}
// 2947B: control flows out of bounds to 2BAFF
// 29438: variable 'v4' is possibly undefined
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

  v2 = 1;
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
void sub_295D0( int a1)
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
  JUMPOUT(0x294C0);
}
// 29611: control flows out of bounds to 294C0
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
      v2 = *(int16_t *)(dword_197F98 + 3753 * word_19988E + 43);
      v3 = &v7;
      return sub_F6816(v2, 1002, (int)v3, 2u);
    }
    word_192B12 = 0;
    word_1998E0 = 0;
    if ( !word_1998CE )
      return result;
    v4 = 3753 * *(uint8_t *)(result + 32);
    v5 = dword_197F98;
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
    v4 = dword_197F98;
LABEL_8:
    v2 = *(int16_t *)(v5 + v4 + 43);
    v3 = &v6;
    return sub_F6816(v2, 1002, (int)v3, 2u);
  }
  word_192B10[0] = 0;
  word_1998E0 = 0;
  if ( !word_1998CE )
    return result;
  v2 = *(int16_t *)(3753 * *(uint8_t *)(result + 32) + dword_197F98 + 43);
  v3 = &v7;
  return sub_F6816(v2, 1002, (int)v3, 2u);
}
// 192864: using guessed type int dword_192864;
// 192B10: using guessed type int16_t word_192B10[];
// 192B12: using guessed type int16_t word_192B12;
// 197F98: using guessed type int dword_197F98;
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
      v7 = v8;
      v5 = (char *)&v7 + 3;
      do
        ++v5;
      while ( *v5 );
      strcpy(v5, v4);
      sub_131F7B();
      LOWORD(v6) = sub_77423((int)v8);
      sub_2C601(v6, (int)v8);
    }
  }
  JUMPOUT(0x2BAFF);
}
// 29832: control flows out of bounds to 2BAFF
// 2982D: variable 'v6' is possibly undefined
// 192864: using guessed type int dword_192864;


//----- (00029837) --------------------------------------------------------
void sub_29837(int a1, int a2, int a3, int i)
{
  int16_t v4; // ax
  _BYTE *v5; // eax
  int v6; // edx
  int v7; // edx
  int v8; // eax
  int16_t v9; // di
  char v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int16_t v14; // si
  int v15; // ebx
  char v16; // al
  int16_t v17; // di
  int v18; // eax
  char v19; // al
  int v20; // edx
  int16_t v21; // ax
  int16_t v22; // ax
  int v23; // eax
  int16_t v24; // ax
  int16_t v25; // ax
  int v26; // eax
  int16_t v27; // ax
  int16_t v28; // ax
  int16_t v29; // dx
  int v30; // ebx
  int v31; // eax
  int v32; // edx
  int v33; // eax
  uint8_t *v34; // eax
  int v35; // ecx
  int v36; // ecx
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // edx
  int v42; // edx
  int v43; // eax
  char v44; // al
  int16_t v45; // cx
  int v46; // eax
  int16_t v47; // dx
  int16_t v48; // dx
  int16_t v49; // ax
  int16_t v50; // [esp-Ch] [ebp-2Ch]
  int16_t v51; // [esp-Ch] [ebp-2Ch]
  int16_t v52; // [esp-8h] [ebp-28h]
  int16_t v53; // [esp-8h] [ebp-28h]
  int v54; // [esp+8h] [ebp-18h] BYREF
  int v55; // [esp+Ch] [ebp-14h]
  int v56; // [esp+10h] [ebp-10h] BYREF
  int v57; // [esp+14h] [ebp-Ch]
  int16_t v58; // [esp+18h] [ebp-8h]
  char v59; // [esp+1Ch] [ebp-4h]

  v59 = 0;
  if ( !sub_3E563(word_1998F8) )
  {
    if ( !(uint16_t)sub_339A7(word_1998F8, a2, a3) )
      sub_49D09(
        *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 33),
        *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 34));
    if ( (uint16_t)sub_294DF(word_1998F8)
      || byte_199B4B[*(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32)] == -1 )
    {
      if ( *(_BYTE *)(313 * word_1998F8 + dword_192864 + 49) )
      {
        sub_42A61();
        if ( !v4 )
        {
          v5 = (_BYTE *)(313 * word_1998F8 + dword_192864);
          if ( v5[32] < 8u && word_1998C8 == 1 )
          {
            v5[75] = 1;
            v5[71] = -1;
          }
        }
      }
    }
    v6 = dword_192864;
    sub_2864A(*(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32), dword_192864, a3, i);
    sub_46CC8(word_1998F8, v6);
    do
    {
      v57 = 0;
      v7 = sub_2A4E8(word_1998F8);
      v8 = sub_1171AB(v7, v7, a3, i);
      if ( (_WORD)v8 == word_199898 )
        v8 = sub_29616();
      i = (int16_t)v7;
      if ( (int16_t)v7 == -1
        || (sub_2A545(word_1998F8, v7),
            v9 = word_1998F8,
            a3 = dword_192864,
            *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 177) = v10,
            v7 = (int16_t)v7,
            sub_2A9A5(v7, v9),
            v57 = v8,
            (_WORD)v8) )
      {
        v59 = 0;
      }
      else
      {
        LOBYTE(v8) = 1 - v59;
        word_1998DA = 2;
        v59 = 1 - v59;
      }
      if ( (uint16_t)sub_1171AB(v8, v7, a3, (int16_t)v7) == word_199898 )
        sub_29616();
      v11 = dword_192864 + 313 * word_1998F8;
      if ( !*(_BYTE *)(v11 + 36) && !*(_BYTE *)(v11 + 176) )
      {
        v12 = 0;
        do
        {
          v13 = 11 * (int16_t)v12++;
          *(_BYTE *)(v13 + dword_192864 + 313 * word_1998F8 + 90) = -1;
        }
        while ( (int16_t)v12 < 8 );
        v55 = -1;
        v14 = 0;
        do
        {
          v15 = 313 * word_1998F8 + dword_192864;
          if ( *(_WORD *)(v15 + 11 * v14 + 82) == 13 && (sub_27F26(), v16)
            || ((v18 = 11 * v14 + dword_192864 + 313 * word_1998F8, *(_WORD *)(v18 + 82) == 36)
             || *(_WORD *)(v18 + 82) == 13)
            && (sub_27F9F(), !v19)
            || (v20 = 313 * word_1998F8, i = 11 * v14, *(_WORD *)(i + v20 + dword_192864 + 82) == 32)
            && (sub_2864A(*(uint8_t *)(v20 + dword_192864 + 32), v20, v15, i), v21 < 2) )
          {
            v17 = -1;
          }
          else
          {
            v22 = word_1998F8;
            *(_BYTE *)(11 * v14 + 313 * word_1998F8 + dword_192864 + 90) = 1;
            sub_2B09E(v22, v55);
            v15 = dword_192864;
            v17 = v23;
            if ( !*(_BYTE *)(313 * word_1998F8 + dword_192864 + 63) )
            {
              if ( (int16_t)v23 != -1 )
                v55 = v23;
              i = (int16_t)v23;
              v24 = sub_2C129(word_1998F8, v23);
              if ( v24 )
              {
                v15 = v24;
                sub_2BF73(word_1998F8, v17, v24);
                sub_2B09E(word_1998F8, v17);
                v17 = v25;
              }
            }
            if ( v17 != -1 )
            {
              v15 = dword_192864 + 313 * word_1998F8;
              v26 = v15 + 11 * v14;
              i = 28 * *(int16_t *)(v26 + 82);
              if ( !byte_17F80F[i] && (*(_BYTE *)(v26 + 86) & 2) == 0 )
              {
                if ( (*(_BYTE *)(v26 + 86) & 4) == 0 || (sub_295D0(word_1998F8), !v27) )
                {
                  v56 = 0;
                  v54 = 0;
                  if ( *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 63) )
                    v28 = sub_286E8(
                            word_1998F8,
                            *(_WORD *)(26 * v17 + dword_192B14 + 9),
                            *(_WORD *)(26 * v17 + dword_192B14 + 11));
                  else
                    sub_2885A(word_1998F8, v17);
                  v29 = v28;
                  v30 = 313 * word_1998F8 + dword_192864;
                  v31 = 11 * v14;
                  i = *(int16_t *)(v30 + v31 + 82);
                  v15 = *(int16_t *)(v30 + v31 + 86);
                  sub_39434(word_1998F8, v29, v15, i, &v56, &v54);
                  v32 = 313 * word_1998F8;
                  if ( *(_BYTE *)(v32 + dword_192864 + 32) < 8u )
                  {
                    HIWORD(v33) = HIWORD(dword_197F98);
                    LOWORD(v33) = *(char *)(3753 * *(uint8_t *)(v32 + dword_192864 + 32) + dword_197F98 + 2214);
                    v56 += v33;
                  }
                }
              }
            }
          }
          if ( v17 == -1 )
          {
            v37 = 11 * v14++;
            *(_BYTE *)(dword_192864 + 313 * word_1998F8 + v37 + 90) = -1;
          }
          else
          {
            v34 = (uint8_t *)(dword_192864 + 313 * word_1998F8);
            if ( v34[63] == 1 )
            {
              v35 = dword_192B14 + 26 * v17;
              v52 = *(_WORD *)(v35 + 11);
              v50 = *(_WORD *)(v35 + 9);
              i = v17;
              v15 = (int16_t)(20 * v34[34]);
              v57 = sub_38B5E(word_1998F8, (int16_t)(20 * v34[33]), v15, v17, v50, v52, 1);
            }
            else
            {
              v36 = 313 * v17 + dword_192864;
              v53 = 20 * *(uint8_t *)(v36 + 34);
              v51 = 20 * *(uint8_t *)(v36 + 33);
              i = v17;
              v15 = (int16_t)(20 * v34[34]);
              v57 = sub_38B5E(word_1998F8, (int16_t)(20 * v34[33]), v15, v17, v51, v53, 0);
              if ( *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 32) == 11 )
                sub_29790(v17);
            }
          }
          v38 = sub_124D41();
          v39 = sub_2F4EE(v38);
          sub_1077D(v39);
          sub_2864A(*(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32), dword_192864, v15, i);
        }
        while ( v14 < 8 && !(uint16_t)sub_3897A(word_1998F8) );
        v40 = 0;
        do
        {
          a3 = dword_192864 + 313 * word_1998F8;
          v41 = 11 * (int16_t)v40++;
          *(_BYTE *)(v41 + a3 + 90) = 1;
        }
        while ( (int16_t)v40 < 8 );
      }
      v42 = dword_192864;
    }
    while ( *(int16_t *)(dword_192864 + 313 * word_1998F8 + 61) > 0 && ((_WORD)v57 || v59) );
    v43 = sub_42A27(word_1998F8);
    if ( (_WORD)v43 )
    {
      for ( i = 0; (int16_t)i < word_1998C0; ++i )
      {
        v42 = (int16_t)i;
        v43 = sub_2C129(word_1998F8, i);
        if ( (_WORD)v43 )
        {
          a3 = (int16_t)v43;
          v42 = (int16_t)i;
          v43 = sub_2BF73(word_1998F8, (int16_t)i, (int16_t)v43);
        }
      }
    }
    if ( (uint16_t)sub_1171AB(v43, v42, a3, i) == word_199898 )
      sub_29616();
    sub_28168(word_1998F8);
    if ( v44 )
    {
      v45 = word_1998F8;
      v46 = 313 * word_1998F8 + dword_192864;
      v47 = *(uint8_t *)(v46 + 49);
      *(_WORD *)(v46 + 256) = 0;
      v58 = v47;
      v48 = *(uint8_t *)(v46 + 49);
      *(_BYTE *)(v46 + 49) = 1;
      v49 = sub_3897A(v45);
      v58 = v48;
      sub_39E15(
        word_1998F8,
        20 * *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 33),
        20 * *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 34),
        v49);
      *(_BYTE *)(313 * word_1998F8 + dword_192864 + 49) = v58;
      word_19296C[word_1998D8] = -1;
    }
  }
  JUMPOUT(0x2BAFF);
}
// 29F16: control flows out of bounds to 2BAFF
// 298E3: variable 'v4' is possibly undefined
// 2998D: variable 'v10' is possibly undefined
// 2999D: variable 'v8' is possibly undefined
// 29A59: variable 'v16' is possibly undefined
// 29A9E: variable 'v19' is possibly undefined
// 29ACF: variable 'v21' is possibly undefined
// 29B0D: variable 'v23' is possibly undefined
// 29B56: variable 'v25' is possibly undefined
// 29BAE: variable 'v27' is possibly undefined
// 29C0C: variable 'v28' is possibly undefined
// 29E76: variable 'v44' is possibly undefined
// 1077D: using guessed type int sub_1077D(_DWORD);
// 2BF73: using guessed type int sub_2BF73(_DWORD, _DWORD, _DWORD);
// 2F4EE: using guessed type int sub_2F4EE(_DWORD);
// 192864: using guessed type int dword_192864;
// 19296C: using guessed type int16_t word_19296C[];
// 192B14: using guessed type int dword_192B14;
// 197F98: using guessed type int dword_197F98;
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

  v4 = 0;
  if ( a3 <= 0 )
  {
    v16 = 0;
  }
  else
  {
    v16 = sub_286E8(a1, *(_WORD *)(26 * a2 + dword_192B14 + 9), *(_WORD *)(26 * a2 + dword_192B14 + 11));
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
                  *(uint8_t *)(313 * *(int16_t *)(26 * a2 + dword_192B14 + 4) + dword_192864 + 32),
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
    LOWORD(v6) = (int16_t)(v6 - (__CFSHL__((int16_t)v6 >> 15, 2) + 4 * ((int16_t)v6 >> 15))) >> 2;
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
void sub_2A145()
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

  v7 = -5000;
  v8 = 0;
  while ( 1 )
  {
    v0 = v8;
    v1 = 26 * (int16_t)v8;
    v2 = sub_286E8(v5, *(_WORD *)(v1 + dword_192B14 + 9), *(_WORD *)(v1 + dword_192B14 + 11));
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
      JUMPOUT(0x2BAFF);
  }
}
// 2A234: control flows out of bounds to 2BAFF
// 2A180: variable 'v5' is possibly undefined
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
  sub_2BB06(a1, a3);
  v21 = v4;
  if ( sub_3E563(a1) )
    return -20000;
  if ( a2 <= 0 )
  {
    v20 = 0;
  }
  else
  {
    sub_2885A(v16, a1);
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
  sub_293D8(a1);
  if ( v13 == 1 )
    v8 -= 1000;
  if ( !(_WORD)v22 )
    v8 -= 2000;
  sub_388CE();
  if ( v14 )
    v8 -= 5000;
  return v8;
}
// 2A25E: variable 'v4' is possibly undefined
// 2A27B: variable 'v16' is possibly undefined
// 2A280: variable 'v5' is possibly undefined
// 2A434: variable 'v13' is possibly undefined
// 2A454: variable 'v14' is possibly undefined
// 192864: using guessed type int dword_192864;


//----- (0002A46A) --------------------------------------------------------
void sub_2A46A()
{
  int16_t i; // cx
  _BYTE *v1; // eax
  int v2; // eax
  int16_t v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  v4 = -5000;
  for ( i = 1; i < word_1998C0; ++i )
  {
    v1 = (_BYTE *)(dword_192864 + 313 * i);
    if ( !v1[36] && v1[32] != *(_BYTE *)(313 * v3 + dword_192864 + 32) && v1[64] != 4 && !sub_3E563(i) )
    {
      v2 = sub_2A239(i, 0, v3);
      if ( v2 > v4 )
        v4 = v2;
    }
  }
  JUMPOUT(0x29478);
}
// 2A4E3: control flows out of bounds to 29478
// 2A487: variable 'v3' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0002A4E8) --------------------------------------------------------
int sub_2A4E8( int a1)
{
  int v1; // ebx
  int v2; // eax
  int v3; // edx

  v1 = 313 * a1;
  *(_BYTE *)(v1 + dword_192864 + 63) = 0;
  sub_2A46A();
  v3 = v2;
  if ( (int16_t)v2 == -1
    && !*(_BYTE *)(dword_192864 + 36)
    && *(uint8_t *)(v1 + dword_192864 + 32) == word_1998AC )
  {
    return 0;
  }
  return v3;
}
// 2A504: variable 'v2' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998AC: using guessed type int16_t word_1998AC;


//----- (0002A545) --------------------------------------------------------
void sub_2A545( int a1, int a2)
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
      JUMPOUT(0x2B098);
  }
}
// 2A75F: control flows out of bounds to 2B098
// 192864: using guessed type int dword_192864;
// 199890: using guessed type int16_t word_199890;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (0002A77D) --------------------------------------------------------
int sub_2A77D(
        int a1, int a2, unsigned int a3, int a4,
        int a5,
        int16_t *a6,
        int a7,
        int a8,
        int a9)
{
  int16_t v9; // si

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
      *(_WORD *)(a7 + 2 * *a6) = a2;
      *(_WORD *)(a8 + 2 * *a6) = a4;
      a9 = a1 - a5;
LABEL_14:
      ++*a6;
      return a9;
    }
    if ( v9 == (_WORD)a9 && *a6 < 20 )
    {
      *(_WORD *)(a7 + 2 * *a6) = a2;
      *(_WORD *)(a8 + 2 * *a6) = a4;
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
void sub_2A9A5( int a1, int a2)
{
  int v3; // edx
  _BOOL2 v4; // cx
  int v5; // ebx
  int v6; // edx
  int v7; // eax
  uint8_t *v8; // ebx
  int v9; // ecx
  int16_t v10; // ax
  int16_t v11; // cx
  int16_t v12; // dx
  int16_t v13; // bx
  int16_t v14; // ax
  int v15; // edx
  int16_t v16; // bx
  uint8_t v17; // al
  int v18; // ebx
  int16_t v19; // cx
  int16_t v20; // dx
  int16_t v21; // bx
  int v22; // eax
  int v23; // ecx
  int16_t v24; // bx
  int v25; // eax
  int16_t v26; // bx
  int16_t v27; // dx
  int v28; // ebx
  int16_t v29; // [esp+0h] [ebp-74h]
  _WORD v30[20]; // [esp+4h] [ebp-70h] BYREF
  _WORD v31[20]; // [esp+2Ch] [ebp-48h] BYREF
  int v32; // [esp+54h] [ebp-20h]
  int v33; // [esp+58h] [ebp-1Ch]
  int v34; // [esp+5Ch] [ebp-18h]
  int v35; // [esp+60h] [ebp-14h]
  int v36; // [esp+64h] [ebp-10h] BYREF
  int v37; // [esp+68h] [ebp-Ch]
  int v38; // [esp+6Ch] [ebp-8h]
  int v39; // [esp+70h] [ebp-4h]

  v3 = 313 * word_1998F8;
  v4 = 0;
  v36 = 0;
  v5 = *(uint8_t *)(v3 + dword_192864 + 32);
  v35 = 0;
  if ( byte_199B4B[v5] == -1 )
    *(_BYTE *)(v3 + dword_192864 + 177) = 2;
  v6 = 313 * word_1998F8;
  if ( !*(_BYTE *)(v6 + dword_192864 + 63) )
  {
    v7 = *(uint8_t *)(v6 + dword_192864 + 32);
    if ( byte_199B4B[v7] == 3 || byte_199B4B[v7] == 2 )
      v4 = word_199890 != 1 || byte_17F80F[28 * *(int16_t *)(dword_192864 + 313 * word_1998F8 + 82)] != 1;
  }
  word_1998C2 = 0;
  if ( !v4 )
  {
    v8 = (uint8_t *)(dword_192864 + 313 * word_1998F8);
    if ( v8[63] == 1 )
    {
      v9 = 26 * a1 + dword_192B14;
      v32 = *(int16_t *)(v9 + 11) / 20;
      v10 = *(int16_t *)(v9 + 9) / 20;
      v11 = v32;
      v12 = v8[34];
      v32 = v8[33];
      v13 = v10;
      v14 = v32;
    }
    else
    {
      v15 = 313 * a1;
      v11 = *(uint8_t *)(v15 + dword_192864 + 34);
      v32 = *(uint8_t *)(v15 + dword_192864 + 33);
      v12 = v8[34];
      v14 = v8[33];
      v13 = v32;
    }
    v16 = sub_134637(v14, v12, v13, v11);
    v17 = *(_BYTE *)(313 * word_1998F8 + dword_192864 + 177);
    if ( v17 )
    {
      if ( v17 <= 1u )
      {
        a2 = v16 - 15;
      }
      else if ( v17 == 2 )
      {
        a2 = v16 - 50;
      }
    }
    else
    {
      a2 = v16 - 3;
    }
    if ( a2 > 0 )
    {
      v38 = 0;
      do
      {
        v39 = 0;
        do
        {
          v33 = (int16_t)v38;
          v34 = (int16_t)v39;
          if ( word_18C9A8[68 * (int16_t)v38 + (int16_t)v39] == 2000 )
          {
            if ( *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 63) == 1 )
            {
              v18 = 26 * a1 + dword_192B14;
              v19 = *(int16_t *)(v18 + 11) / 20;
              v20 = v34;
              v21 = *(int16_t *)(v18 + 9) / 20;
            }
            else
            {
              v22 = 313 * a1;
              v19 = *(uint8_t *)(dword_192864 + v22 + 34);
              v21 = *(uint8_t *)(dword_192864 + v22 + 33);
              v20 = v34;
            }
            v37 = sub_134637(v33, v20, v21, v19);
            a2 = sub_2A77D(
                   (int16_t)v37,
                   v38,
                   *(uint8_t *)(dword_192864 + 313 * v29 + 177),
                   v39,
                   a2,
                   (int16_t *)&v36,
                   (int)v30,
                   (int)v31,
                   a2);
          }
          ++v39;
        }
        while ( (int16_t)v39 < 68 );
        ++v38;
      }
      while ( (int16_t)v38 < 81 );
    }
    if ( (int16_t)v36 > 0 )
    {
      v23 = (int16_t)(sub_1247A0((int16_t)v36) - 1);
      sub_3F95F(word_1998F8, v30[v23], (int16_t)v31[v23]);
      v24 = sub_3EE0F(word_1998F8, (int16_t)v30[v23], (int16_t)v31[v23]);
      if ( v24 > 0 )
      {
        v35 = 1;
        *(_WORD *)(313 * word_1998F8 + dword_192864 + 61) -= v24;
      }
    }
  }
  if ( *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 63) )
  {
    v28 = 26 * a1 + dword_192B14;
    v27 = *(int16_t *)(v28 + 9) / 20;
    v26 = *(int16_t *)(v28 + 11) / 20;
  }
  else
  {
    v25 = 313 * a1;
    v26 = *(uint8_t *)(dword_192864 + v25 + 34);
    v27 = *(uint8_t *)(dword_192864 + v25 + 33);
  }
  sub_3FA61(word_1998F8, v27, v26);
  word_1998C2 = 0;
  JUMPOUT(0x2B098);
}
// 2ACF4: control flows out of bounds to 2B098
// 2ABD5: variable 'v29' is possibly undefined
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
_BOOL2 sub_2AED2( int a1, int a2)
{
  uint16_t *v3; // eax
  uint16_t v4; // cx
  int16_t v5; // bx
  int v6; // ebx
  int v7; // eax
  int16_t v8; // ax

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
      && *(_BYTE *)(dword_192864 + 313 * *(int16_t *)(v4 + 4) + 32) != *(_BYTE *)(313 * v7 + dword_192864 + 32)
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
// 2B013: variable 'v7' is possibly undefined
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (0002B09E) --------------------------------------------------------
void sub_2B09E( int a1, int a2)
{
  int v3; // ecx
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  int v7; // [esp+0h] [ebp-8h] BYREF
  int v8; // [esp+4h] [ebp-4h] BYREF

  v3 = a1;
  v4 = 313 * a1;
  v5 = *(uint8_t *)(v4 + dword_192864 + 32);
  if ( byte_199B4B[v5] == 1 || byte_199B4B[v5] == 3 )
  {
    sub_2ACF9(a1, a2, a1, &v8, v4);
    sub_2AFA9(a1, &v7);
    v6 = 313 * a1;
    *(_BYTE *)(v6 + dword_192864 + 63) = v7 / 2 > v8;
  }
  else
  {
    sub_2AFA9(v3, &v7);
    sub_2ACF9(v3, -1, v3, &v8, v4);
    if ( v8 / 2 <= v7 )
    {
      *(_BYTE *)(v4 + dword_192864 + 63) = 1;
      JUMPOUT(0x2B096);
    }
    *(_BYTE *)(v4 + dword_192864 + 63) = 0;
  }
  JUMPOUT(0x2B098);
}
// 2B10B: control flows out of bounds to 2B098
// 2B164: control flows out of bounds to 2B096
// 192864: using guessed type int dword_192864;


//----- (0002B191) --------------------------------------------------------
int sub_2B191( int a1, int a2)
{
  int result; // eax

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
void sub_2B1FD(int a1, _WORD *a2)
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
        sub_FE8BE(v12);
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
                        sub_2B7CC(v38, k, *(&v28 + j), v39, (int16_t *)&v46, -1);
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
              sub_FE8BE(v14);
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
              JUMPOUT(0x2B098);
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
    sub_FE8BE(v6);
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
// 2B7C7: control flows out of bounds to 2B098
// 2B6A3: variable 'v19' is possibly undefined
// FE8BE: using guessed type int sub_FE8BE(_DWORD);
// 17F6C1: using guessed type int16_t word_17F6C1;
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0002B7CC) --------------------------------------------------------
void sub_2B7CC( int a1, int a2, int a3, int a4, int16_t *a5, int a6)
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

  v8 = dword_192864 + 313 * a1 + 11 * a2;
  v22 = *(_WORD *)(v8 + 86);
  v20 = *(_WORD *)(v8 + 82);
  if ( a6 <= -1 )
    v25 = 2;
  else
    v25 = sub_286E8(a1, *(_WORD *)(dword_192B14 + 26 * a6 + 9), *(_WORD *)(dword_192B14 + 26 * a6 + 11));
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
      *a5 = 0;
    else
      *a5 = v23 - a3 * v16;
  }
  JUMPOUT(0x293D2);
}
// 2B9DE: control flows out of bounds to 293D2
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
    sub_FE8BE(v4);
  }
  return v2;
}
// 2BAE1: variable 'v4' is possibly undefined
// FE8BE: using guessed type int sub_FE8BE(_DWORD);
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0002BB06) --------------------------------------------------------
void sub_2BB06( int a1, int a2)
{
  int v2; // ebx
  int16_t v4; // ax
  int v5; // edi
  int16_t v6; // si
  int16_t i; // ax

  v2 = 0;
  if ( a1 )
  {
    sub_36B64(a1);
    sub_494A8(a1, a2);
  }
  else
  {
    sub_5685F(*(uint8_t *)(dword_192864 + 32));
    v5 = 100 * (*(int16_t *)((char *)&word_17F642 + 15 * v4) + 100) / 100;
    v6 = sub_3A142(100, a2);
    for ( i = 0; i < 4; ++i )
    {
      if ( ((1 << i) & v6) != 0 )
        v2 += v5;
    }
  }
  JUMPOUT(0x2BB00);
}
// 2BB9C: control flows out of bounds to 2BB00
// 2BB5A: variable 'v4' is possibly undefined
// 17F642: using guessed type int16_t word_17F642;
// 192864: using guessed type int dword_192864;


//----- (0002BBA1) --------------------------------------------------------
void sub_2BBA1( int a1, int a2, int a3, int a4)
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

  v27 = 0;
  v23 = 0;
  v21 = 0;
  v22 = 0;
  v20 = 0;
  if ( a1 < 8 && *(_BYTE *)(3753 * a1 + dword_197F98 + 40) != 100 && word_1998C8 == 1 )
  {
    sub_42A61();
    if ( !v4 )
    {
      for ( i = 0; (int16_t)i < word_1998C0; ++i )
      {
        if ( (_WORD)i || (uint16_t)sub_3A142(a4, i) )
        {
          v6 = dword_192864 + 313 * (int16_t)i;
          if ( !*(_BYTE *)(v6 + 36) && !*(_BYTE *)(v6 + 176) )
          {
            sub_2BB06(i, i);
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
      if ( v16 > 5 * v15 )
        v27 = 1;
    }
  }
  JUMPOUT(0x2BAFF);
}
// 2BE20: control flows out of bounds to 2BAFF
// 2BC09: variable 'v4' is possibly undefined
// 2BC4C: variable 'v7' is possibly undefined
// 2BC79: variable 'v17' is possibly undefined
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int dword_197F98;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998C8: using guessed type int16_t word_1998C8;


//----- (0002BE25) --------------------------------------------------------
void sub_2BE25( int a1)
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
    sub_FE8BE(v3);
  }
  JUMPOUT(0x2BAFD);
}
// 2BF6E: control flows out of bounds to 2BAFD
// 2BF4E: variable 'v3' is possibly undefined
// FE8BE: using guessed type int sub_FE8BE(_DWORD);
// 17F815: using guessed type int16_t word_17F815[];
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0002BF73) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=121)) - nutno dohledat rucne v IDA @ 0x2C102 */
int sub_2BF73(_DWORD _p0, _DWORD _p1, _DWORD _p2)
{
  DECOMP_TODO("call analysis failed (funcsize=121)");
}


//----- (0002C129) --------------------------------------------------------
int sub_2C129( int a1, int a2)
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
    sub_2885A(v36, v5);
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
    sub_388A2();
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
      sub_4528F(a2);
      if ( v11 > 0 )
        goto LABEL_21;
    }
    if ( !*(_BYTE *)(dword_192864 + 313 * word_1998F8 + 175)
      || (_WORD)v40 == 4
      && ((_WORD)v38 != 1 || *(int16_t *)(dword_192864 + 313 * a2 + 59) > 0)
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
      sub_388A2();
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
        sub_35FDA(v28);
        v16 = v15;
        LOWORD(v17) = sub_35CAD(v35);
        v39 = v16 + v17 + v24;
        sub_35FDA(v31);
        v19 = v18;
        sub_360AA(v31);
        v21 = 20 * sub_4B0D3(a2, 29) + v20 + v19;
        v34 = (int16_t)(v26 + v21 + sub_35CAD(a2));
        if ( (int16_t)v39 > v34 - 20 )
        {
          if ( *(_BYTE *)(3753 * v28 + dword_197F98 + 2232) )
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
// 2C176: variable 'v9' is possibly undefined
// 2C203: variable 'v10' is possibly undefined
// 2C269: variable 'v11' is possibly undefined
// 2C33A: variable 'v14' is possibly undefined
// 2C384: variable 'v15' is possibly undefined
// 2C38E: variable 'v17' is possibly undefined
// 2C3A0: variable 'v18' is possibly undefined
// 2C3B4: variable 'v20' is possibly undefined
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int dword_197F98;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (0002C43A) --------------------------------------------------------
void sub_2C43A( int a1, int a2)
{
  int16_t v3; // cx
  int16_t v4; // ax
  int v5; // eax
  int16_t v6; // [esp+10h] [ebp-10h] BYREF
  int v7; // [esp+14h] [ebp-Ch]
  int v8; // [esp+18h] [ebp-8h]
  int16_t v9; // [esp+1Ch] [ebp-4h] BYREF

  if ( a1 == word_1998AC )
    v3 = word_19988E;
  else
    v3 = word_1998AC;
  sub_2BBA1(a1, a2, a1, v3);
  if ( !v4 )
  {
    sub_2B1FD(a1, &v9);
    sub_2BE25(a1);
    v7 = v5;
    sub_2B1FD(v3, &v6);
    sub_2BA5E(a1);
    v8 = sub_2BA5E(v3);
    sub_2BE25(v3);
  }
  JUMPOUT(0x2BAFF);
}
// 2C472: control flows out of bounds to 2BAFF
// 2C46B: variable 'v4' is possibly undefined
// 2C491: variable 'v5' is possibly undefined
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
    sub_2E2CD();
  sub_128EDE(401, 362, 489, 374, 0, 199);
  sub_128EDE(401, 379, 488, 467, 0, 199);
  sub_3459E(401, 379);
  word_1998F4 = 666;
  sub_2F4EE();
  sub_11E718();
  v1 = sub_124DEC();
  result = sub_1077D(v1);
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
      sub_2E2CD();
    sub_128EDE(401, 362, 489, 374, 0, 199);
    sub_128EDE(401, 379, 488, 467, 0, 199);
    sub_3459E(401, 379);
    word_1998F4 = 666;
    sub_124E36();
    v3 = sub_124D41();
    v4 = sub_2F4EE(v3);
    sub_1077D(v4);
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
  sub_FE8BE(a1);
  sub_128EDE(15, 362, 102, 374, 0, 199);
  sub_128EDE(401, 362, 489, 374, 0, 199);
  LOBYTE(v1) = sub_128EDE(401, 379, 488, 467, 0, 199);
  sub_FE8BE(v1);
  v2 = word_1998F8;
  if ( word_1998F8 > -1 )
    sub_3459E(401, 379);
  sub_FE8BE(v2);
  dword_192880 = sub_127C27((int)aCombatLbx_0, 0, dword_193174);
  sub_FE8BE(dword_192880);
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
  sub_FE8BE(v3);
  sub_128AB6(0, 0, 639, 350);
  sub_12B634();
  if ( word_1998CA == 1 )
    v4 = 35;
  else
    v4 = 46;
  dword_192858 = sub_127C27((int)aCombatLbx_0, v4, dword_193174);
  sub_FE8BE(dword_192858);
  sub_12A478(word_199880, word_199882, dword_192858);
  v5 = sub_12A478(word_199880 - 640, word_199882, dword_192858);
  sub_FE8BE(v5);
  sub_12A478(word_199880 - 640, word_199882 - 480, dword_192858);
  v6 = sub_12A478(word_199880, word_199882 - 480, dword_192858);
  v7 = sub_FE8BE(v6);
  if ( word_1998EE == 1 )
  {
    v7 = word_1998F8;
    if ( word_1998F8 > -1 )
    {
      v7 = 313 * word_1998F8 + dword_192864;
      if ( *(_BYTE *)(v7 + 32) < 8u )
      {
        v8 = 3753 * *(uint8_t *)(v7 + 32);
        v7 = dword_197F98;
        if ( *(_BYTE *)(v8 + dword_197F98 + 40) == 100 )
          sub_34AB6();
      }
    }
  }
  sub_FE8BE(v7);
  dword_192878 = sub_127C27((int)aCombatLbx_0, 47, dword_193174);
  sub_FE8BE(dword_192878);
  sub_12A478(word_199886, word_199884, dword_192878);
  v9 = sub_12A478(word_199886 - 640, word_199884, dword_192878);
  sub_FE8BE(v9);
  sub_12A478(word_199886 - 640, word_199884 - 480, dword_192878);
  v10 = sub_12A478(word_199886, word_199884 - 480, dword_192878);
  sub_FE8BE(v10);
  dword_192888 = sub_127C27((int)aCombatLbx_0, 48, dword_193174);
  sub_FE8BE(dword_192888);
  sub_12A478(word_19988C, word_19988A, dword_192888);
  v11 = sub_12A478(word_19988C - 640, word_19988A, dword_192888);
  sub_FE8BE(v11);
  sub_12A478(word_19988C - 640, word_19988A - 480, dword_192888);
  v12 = sub_12A478(word_19988C, word_19988A - 480, dword_192888);
  sub_FE8BE(v12);
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
  v16 = sub_FE8BE(v15);
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
  sub_FE8BE(v16);
  sub_2F172();
  word_1998F4 = -2;
LABEL_36:
  JUMPOUT(0x33AFE);
}
// 2CBC7: control flows out of bounds to 33AFE
// 2C6FE: variable 'a1' is possibly undefined
// 2C763: variable 'v1' is possibly undefined
// 2C783: variable 'v2' is possibly undefined
// 2C91A: variable 'v7' is possibly undefined
// FE8BE: using guessed type int sub_FE8BE(_DWORD);
// 192858: using guessed type int dword_192858;
// 192864: using guessed type int dword_192864;
// 19286C: using guessed type int dword_19286C;
// 192878: using guessed type int dword_192878;
// 192880: using guessed type int dword_192880;
// 192888: using guessed type int dword_192888;
// 192B10: using guessed type int16_t word_192B10[];
// 192B12: using guessed type int16_t word_192B12;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
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
    sub_5685F(*(uint8_t *)(dword_192864 + 32));
    v39 = (int16_t)(88 * v8 / (100 * (*(int16_t *)((char *)&word_17F642 + 15 * v10) + 100) / 0x64u)) / 2;
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
    if ( *(_BYTE *)(v18 + 49) )
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
// 2CCDB: variable 'v10' is possibly undefined
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
        v8 = *(uint8_t *)(dword_192B18 + 361 * word_199878 + 10);
      itoa(v8, v43, 10, a4);
      v9 = &v40;
      do
        ++v9;
      while ( *v9 );
      strcpy(v9, v43);
      v10 = &v40;
      do
        ++v10;
      while ( *v10 );
      strcpy(v10, asc_178C4F);
      if ( word_199878 != -1 )
      {
        if ( *(int16_t *)(361 * word_199878 + dword_192B18 + 306) > 0 )
        {
          sub_58F1E(1, v42, 80);
          v11 = &v40;
          do
            ++v11;
          while ( *v11 );
          strcpy(v11, v42);
          itoa(*(int16_t *)(dword_192B18 + 361 * word_199878 + 306), v43, 10, a4);
          v12 = &v40;
          do
            ++v12;
          while ( *v12 );
          strcpy(v12, v43);
          v13 = &v40;
          do
            ++v13;
          while ( *v13 );
          strcpy(v13, asc_178C4F);
        }
        if ( *(int16_t *)(361 * word_199878 + dword_192B18 + 304) > 0 )
        {
          sub_58F1E(2, v42, 80);
          v14 = &v40;
          do
            ++v14;
          while ( *v14 );
          strcpy(v14, v42);
          itoa(*(int16_t *)(dword_192B18 + 361 * word_199878 + 304), v43, 10, a4);
          v15 = &v40;
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
        if ( *(_BYTE *)(dword_192B18 + 361 * word_199878 + 336) )
        {
          sub_1212B3(v39 + 2, v16, (int)off_17ED2B);
          v16 = v38 + 11;
        }
        if ( *(_BYTE *)(361 * word_199878 + dword_192B18 + 337) )
        {
          v17 = v16;
          v16 += 7;
          sub_1212B3(v39 + 2, v17, (int)off_17ED3E);
        }
        if ( *(_BYTE *)(dword_192B18 + 361 * word_199878 + 357) )
        {
          v18 = v16;
          v16 += 7;
          sub_1212B3(v39 + 2, v18, (int)off_17EEBA);
        }
        result = 361 * word_199878;
        if ( *(_BYTE *)(dword_192B18 + result + 352) )
          return sub_1212B3(v39 + 2, v16, (int)off_17EE5B);
      }
    }
  }
  return result;
}
// 2D295: variable 'v38' is possibly undefined
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
// 192B18: using guessed type int dword_192B18;
// 193174: using guessed type int dword_193174;
// 199878: using guessed type int16_t word_199878;


//----- (0002E2CD) --------------------------------------------------------
int sub_2E2CD()
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
  int16_t v40; // [esp+0h] [ebp-4Eh]
  int16_t v41; // [esp+4h] [ebp-4Ah]
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
      v6 = 3;
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
      v23 = &v43;
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
      v25 = (char *)*(&off_17F803 + 7 * *(int16_t *)(v24 + 82));
    else
      v25 = (char *)*(&off_17F807 + 7 * *(int16_t *)(v24 + 82));
    v26 = &v43;
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
      v30 = &v43;
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
      v34 = &v43;
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
            v37 = &v43;
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
      v38 = &v43;
      do
        ++v38;
      while ( *v38 );
      strcpy(v38, v31);
      goto LABEL_102;
    }
    if ( *(int16_t *)(v29 + 88) > 0 )
    {
      v32 = &v43;
      do
        ++v32;
      while ( *v32 );
      strcpy(v32, asc_178C52);
      itoa(*(int16_t *)(v28 + dword_192864 + 313 * word_1998F8 + 88), v45, 10, v6);
      v33 = &v43;
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
// 2E3D5: variable 'v40' is possibly undefined
// 2E46C: variable 'v41' is possibly undefined
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
      JUMPOUT(0x33AFE);
    }
  }
}
// 2EB0A: control flows out of bounds to 33AFE
// 17EEE0: using guessed type _UNKNOWN *off_17EEE0;
// 192864: using guessed type int dword_192864;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (0002EB0F) --------------------------------------------------------
char sub_2EB0F( int a1, int a2, int a3, int a4)
{
  char v5; // bl

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

  sub_12972D(a1, a2, a4 + a3 + 9);
  sub_12972D(a1 + 1, a2, a4 + a3 + 6);
  v5 = a4 + a3 + 4;
  sub_12972D(a1 + 2, a2, a4 + a3 + 4);
  sub_12972D(a1, a2 + 1, a4 + a3 + 6);
  sub_12972D(a1 + 1, a2 + 1, a4 + a3 + 6);
  sub_12972D(a1 + 2, a2 + 1, v5);
  sub_12972D(a1, a2 + 2, v5);
  sub_12972D(a1 + 1, a2 + 2, v5);
  JUMPOUT(0x2EB79);
}
// 2EC50: control flows out of bounds to 2EB79


//----- (0002EC55) --------------------------------------------------------
void sub_2EC55( int a1, int a2, int a3, int a4)
{
  char v5; // cl
  char v8; // [esp+18h] [ebp-Ch]

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
  JUMPOUT(0x2EB79);
}
// 2ED83: control flows out of bounds to 2EB79


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
  JUMPOUT(0x2EB79);
}
// 2EF4C: control flows out of bounds to 2EB79


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
    v2 = *(_BYTE *)(17 * *(int16_t *)(dword_192B18 + 361 * word_199878 + 2) + dword_1930D4 + 5);
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
      JUMPOUT(0x33AFE);
  }
}
// 2F37D: control flows out of bounds to 33AFE
// 192864: using guessed type int dword_192864;
// 1928A4: using guessed type int dword_1928A4;
// 192B14: using guessed type int dword_192B14;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
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
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=702)) - nutno dohledat rucne v IDA @ 0x2F856 */
int sub_2F4EE(_DWORD _p0)
{
  DECOMP_TODO("call analysis failed (funcsize=702)");
}


//----- (00030062) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void sub_30062( int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        hr_int128_t a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int64_t a21,
        int64_t a22,
        int64_t a23)
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
        v35 = *(int16_t *)(v33 + 196) + 45 * *(uint8_t *)(dword_197F98 + 3753 * SWORD1(a21) + 38);
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
  JUMPOUT(0x2E2B2);
}
// 30163: control flows out of bounds to 2E2B2
// 300D4: inconsistent variable size for '^F0.8'
// 300FB: inconsistent variable size for '^F0.8'
// 30174: inconsistent variable size for '^F8.8'
// 30088: inconsistent variable size for '^100.8'
// 19283C: using guessed type int dword_19283C;
// 192840: using guessed type int dword_192840;
// 19285C: using guessed type int dword_19285C;
// 192864: using guessed type int dword_192864;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
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
      v14 = (int16_t *)sub_110D3C(dword_192ED4, 10000);
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
      v104 = v105;
      v17 = (char *)&v104 + 3;
      do
        ++v17;
      while ( *v17 );
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
      v104 = v105;
      v18 = (char *)&v104 + 3;
      do
        ++v18;
      while ( *v18 );
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
      v104 = v105;
      v21 = (char *)&v104 + 3;
      do
        ++v21;
      while ( *v21 );
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
      if ( byte_199AC1 != -1 )
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
      if ( !v150 && byte_199A43 )
      {
        sub_120CCB(1, (int)&v118);
        strcpy(v105, "(");
        itoa(word_199B12, v109, 10, 65);
        v104 = v105;
        v27 = (char *)&v104 + 3;
        do
          ++v27;
        while ( *v27 );
        strcpy(v27, v109);
        v104 = v105;
        v28 = (char *)&v104 + 3;
        do
          ++v28;
        while ( *v28 );
        strcpy(v28, "/");
        itoa(word_199ADC, v109, 10, 65);
        v104 = v105;
        v29 = (char *)&v104 + 3;
        do
          ++v29;
        while ( *v29 );
        strcpy(v29, v109);
        v104 = v105;
        v30 = (char *)&v104 + 3;
        do
          ++v30;
        while ( *v30 );
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
        v32 = *(char **)((char *)&off_17F638 + 15 * (uint8_t)byte_199A45);
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
        itoa(word_17FE9C[23 * (uint8_t)byte_199A43], v109, 10, v36);
        strcpy(v105, "^ ");
        v104 = v105;
        v37 = (char *)&v104 + 3;
        do
          ++v37;
        while ( *v37 );
        strcpy(v37, v109);
        sub_58F1E(15, v106, 80);
        v104 = v105;
        v38 = (char *)&v104 + 3;
        do
          ++v38;
        while ( *v38 );
        strcpy(v38, v106);
        sub_1212B3(v155 + 3, v139, (int)v105);
      }
      v39 = v152 + 3;
      if ( v150 )
      {
        sub_5685F(*(uint8_t *)(dword_192864 + 32));
        itoa((int16_t)(100 * (*(int16_t *)((char *)&word_17F642 + 15 * v41) + 100) / 100), v109, 10, v39);
        strcpy(v105, "^ ");
        v104 = v105;
        v42 = (char *)&v104 + 3;
        do
          ++v42;
        while ( *v42 );
        strcpy(v42, v109);
        v104 = v105;
        v43 = (char *)&v104 + 3;
        do
          ++v43;
        while ( *v43 );
        strcpy(v43, asc_178C52);
        sub_58F1E(16, v106, 80);
        v104 = v105;
        v44 = (char *)&v104 + 3;
        do
          ++v44;
        while ( *v44 );
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
      v104 = v105;
      v46 = (char *)&v104 + 3;
      do
        ++v46;
      while ( *v46 );
      strcpy(v46, v109);
      sub_58F1E(17, v106, 80);
      v104 = v105;
      v47 = (char *)&v104 + 3;
      do
        ++v47;
      while ( *v47 );
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
            v48 = sub_4A884(word_199878);
          }
          v49 = word_180024[18 * v48]
              + *(int16_t *)((char *)&word_17F642 + 15 * (uint8_t)byte_199A45) * word_180024[18 * v48] / 100;
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
        v104 = v105;
        v54 = (char *)&v104 + 3;
        do
          ++v54;
        while ( *v54 );
        strcpy(v54, v109);
        v104 = v105;
        v55 = (char *)&v104 + 3;
        do
          ++v55;
        while ( *v55 );
        strcpy(v55, "/");
        itoa(word_199ADE, v109, 10, v53);
        v104 = v105;
        v56 = (char *)&v104 + 3;
        do
          ++v56;
        while ( *v56 );
        strcpy(v56, v109);
        v104 = v105;
        v57 = (char *)&v104 + 3;
        do
          ++v57;
        while ( *v57 );
        strcpy(v57, asc_178C5E);
        v127 = (int16_t)(v139 + 3);
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
            v104 = v105;
            v58 = (char *)&v104 + 3;
            do
              ++v58;
            while ( *v58 );
            strcpy(v58, v109);
            v104 = v105;
            v59 = (char *)&v104 + 3;
            do
              ++v59;
            while ( *v59 );
            strcpy(v59, "/");
            itoa(word_199B10, v109, 10, v53);
            v104 = v105;
            v60 = (char *)&v104 + 3;
            do
              ++v60;
            while ( *v60 );
            strcpy(v60, v109);
            v104 = v105;
            v61 = (char *)&v104 + 3;
            do
              ++v61;
            while ( *v61 );
            strcpy(v61, asc_178C5E);
            sub_1210B7(v152 + 155, v127, (int)v105);
          }
        }
        else
        {
          sub_1212B3(v152, v53, *(int *)((char *)&off_17EB3D + 19 * (uint8_t)byte_199A38));
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
            v104 = (char *)(*(int16_t *)((char *)&word_17F6C1 + 59 * (int16_t)sub_5679E((uint8_t)byte_199A32))
                          + word_199A39);
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
        v104 = v105;
        v76 = (char *)&v104 + 3;
        do
          ++v76;
        while ( *v76 );
        strcpy(v76, asc_178C52);
        if ( byte_199A66[v75] == 1 )
          v77 = (char *)*(&off_17F803 + 7 * *(int16_t *)((char *)&word_199A64 + v75));
        else
          v77 = (char *)*(&off_17F807 + 7 * *(int16_t *)((char *)&word_199A64 + v75));
        v104 = v105;
        v78 = (char *)&v104 + 3;
        do
          ++v78;
        while ( *v78 );
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
        v81 = &v108;
        do
          ++v81;
        while ( *v81 );
        strcpy(v81, v80);
LABEL_169:
        v104 = v109;
        v82 = &v108;
        do
          ++v82;
        while ( *v82 );
        strcpy(v82, asc_178C5E);
        if ( (int16_t)v151 != 1 )
        {
          v104 = v105;
          v83 = (char *)&v104 + 3;
          do
            ++v83;
          while ( *v83 );
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
                v104 = v105;
                v93 = (char *)&v104 + 3;
                do
                  ++v93;
                while ( *v93 );
                strcpy(v93, ", ");
              }
              v94 = *(char **)((char *)&off_17FD0F + 15 * i);
              v104 = v105;
              v95 = (char *)&v104 + 3;
              do
                ++v95;
              while ( *v95 );
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
              JUMPOUT(0x33AFF);
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
// 31F20: control flows out of bounds to 33AFF
// 311CC: variable 'v41' is possibly undefined
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

  v14 = a1;
  v1 = a1 == -1;
  sub_6FCAB();
  sub_107AF(&dword_19B568);
  sub_124D7A();
  --word_19987A;
  sub_107C2(&dword_19B568);
  sub_1174CB();
  v2 = sub_124E36();
  sub_1077D(v2);
  sub_1191CA((int)sub_30631, 1);
  v15 = v1;
  sub_1112EC(dword_192ED4, 1);
  if ( !v1 )
  {
    word_1998D2 = -1;
    sub_4CB1E(v14, (int)&word_199A48, (int)&word_199A4A, (int16_t)&word_199A46);
    strcpy(v13, byte_199A12);
    sub_54E5B(v14, &word_199A48, &word_199A4A, &word_199A46);
    v3 = sub_12DAA4(98, 98);
    dword_19283C = (int)sub_110D3C(dword_192ED4, v3);
    v4 = sub_12DAA4(98, 98);
    dword_192824 = (int)sub_110D3C(dword_192ED4, v4);
    v5 = sub_127C27((int)aCombatLbx, 11, dword_193174);
    sub_133C9C(v5, 11);
    byte_1A125C[0] = sub_133DE1(0x84u);
    byte_1A125D = sub_133DE1(0x8Cu);
    byte_1A125E = sub_133DE1(0x8Au);
    byte_1A125F = sub_133DE1(0x8Cu);
    LOBYTE(dword_1A1260) = sub_133DE1(0x8Cu);
    BYTE1(dword_1A1260) = sub_133DE1(0x8Cu);
    BYTE2(dword_1A1260) = sub_133DE1(0x8Cu);
    HIBYTE(dword_1A1260) = sub_133DE1(0x8Cu);
  }
  if ( word_199ABF == -1 )
  {
    v6 = (uint8_t)byte_199A32;
    if ( (uint8_t)byte_199A32 >= 8u )
      v6 = 0;
    v7 = sub_126B42((int)aFlticonsLbx, *(uint8_t *)(3753 * v6 + dword_197F98 + 37), dword_192ED4);
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
    sub_120BB5(4, (int)&byte_1A125C);
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
    v9 = sub_1077D(v11);
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
  JUMPOUT(0x33AFE);
}
// 321FE: control flows out of bounds to 33AFE
// 321A7: variable 'v11' is possibly undefined
// 321C2: variable 'v12' is possibly undefined
// 1077D: using guessed type int sub_1077D(_DWORD);
// 192814: using guessed type int dword_192814;
// 192824: using guessed type int dword_192824;
// 19283C: using guessed type int dword_19283C;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
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
  JUMPOUT(0x33AFE);
}
// 32488: control flows out of bounds to 33AFE
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
  JUMPOUT(0x33AFE);
}
// 3299F: control flows out of bounds to 33AFE
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
      v12 = 45 * *(uint8_t *)(3753 * v4 + dword_197F98 + 38) + *(int16_t *)(v10 + dword_192864 + 196);
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
// 32B50: variable 'v22' is possibly undefined
// 32D7C: variable 'v21' is possibly undefined
// 19283C: using guessed type int dword_19283C;
// 192840: using guessed type int dword_192840;
// 192864: using guessed type int dword_192864;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
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
  if ( !(uint16_t)sub_3897A(a1) )
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
      sub_2F4EE(v22);
      sub_12B634();
      sub_128AB6(0, 0, 639, 350);
      v23 = sub_127C27((int)aCmbtsfxLbx_2, 42, dword_193174);
      sub_12B753(v23, v20);
      v24 = SWORD2((int)LODWORD(v39));
      sub_12A478(v44, SWORD2(v45), v23);
      sub_128AB6(SWORD2(v46), v46, v35, v24);
      sub_30062(
        a1,
        v24,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        (int)v36,
        v37,
        v38,(int)LODWORD(v39),
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46);
      sub_1077D(v25);
      sub_12C2C6(1);
      if ( (_WORD)v45 == word_1998AC )
        HIDWORD(v44) -= HIDWORD(v39);
      else
        HIDWORD(v44) += HIDWORD(v39);
      v20 += v43;
    }
    sub_8FD56(v30);
  }
  JUMPOUT(0x33AFE);
}
// 33151: control flows out of bounds to 33AFE
// 33085: variable 'v22' is possibly undefined
// 3310D: variable 'v26' is possibly undefined
// 33112: variable 'v25' is possibly undefined
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
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=254)) - nutno dohledat rucne v IDA @ 0x3384D */
int sub_33543(_DWORD _p0)
{
  DECOMP_TODO("call analysis failed (funcsize=254)");
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
        v14 = *(uint8_t *)(17 * *(int16_t *)(361 * word_199878 + dword_192B18 + 2) + dword_1930D4 + 5);
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
// 33A5F: variable 'v10' is possibly undefined
// 33AE5: variable 'v12' is possibly undefined
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;


//----- (00033B19) --------------------------------------------------------
void sub_33B19( int a1)
{
  int16_t v2; // cx
  int16_t v3; // si
  int16_t v4; // ax
  int16_t v5; // si
  int16_t v6; // cx
  uint8_t v7; // al
  int v8; // [esp+0h] [ebp-4h]

  v8 = 313 * a1;
  v2 = *(uint8_t *)(v8 + dword_192864 + 33);
  v3 = *(uint8_t *)(v8 + dword_192864 + 34);
  sub_3D259(v2, v3);
  if ( !a1 )
  {
    if ( word_19988E == 8 )
      v4 = 2;
    else
      v4 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * word_199878 + 2) + 5);
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
    sub_3D259(v6, v5);
  }
LABEL_17:
  JUMPOUT(0x33AFC);
}
// 33B9F: control flows out of bounds to 33AFC
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
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
    v3 = sub_2E2CD();
  sub_2F4EE(v3);
  v4 = sub_124DEC();
  sub_1077D(v4);
  sub_123E6C((int)&unk_17CF00, 1);
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
  sub_2C601(v8, 1);
  return sub_1191CA((int)sub_2F4EE, 1);
}
// 33C6D: variable 'v3' is possibly undefined
// 33CD3: variable 'v8' is possibly undefined
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
    sub_2F4EE(v13);
    sub_128AB6(0, 0, 639, 350);
    sub_12B634();
    sub_1344B0((int16_t *)&v24, (int16_t *)&v26, v25, v34, v29, v33, v32);
    v14 = sub_127C27((int)aCmbtmislLbx_0, v11, dword_193174);
    v15 = sub_12A478(v24 - 17, v26 - 17, v14);
    sub_1077D(v15);
    sub_12C2C6(1);
  }
  if ( v35 )
    sub_A943A();
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
    sub_2F4EE(v19);
    sub_128AB6(0, 0, 639, 350);
    sub_12B634();
    v20 = sub_127C27((int)aCmbtsfxLbx_2, 7, dword_193174);
    sub_12B753(v20, v18);
    sub_12A478(v29 - 12, v33 - 12, v20);
    sub_A9223();
    sub_1077D(v21);
    ++v18;
    sub_12C2C6(1);
  }
  sub_A94A1();
  return sub_112C96(v16, 10);
}
// 3425B: variable 'v21' is possibly undefined
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
                              JUMPOUT(0x33AFE);
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
// 3443F: control flows out of bounds to 33AFE


//----- (00034454) --------------------------------------------------------
char sub_34454( int a1, _WORD *a2, _WORD *a3)
{
  int v3; // eax
  int v4; // eax
  int16_t v5; // si
  unsigned int v6; // eax

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
      LOBYTE(v3) = *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * word_199878 + 2) + 5);
      if ( (_BYTE)v3 != 2 )
        return v3;
      *a2 = 9;
    }
    *a3 = 7;
  }
  return v3;
}
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199878: using guessed type int16_t word_199878;


//----- (00034543) --------------------------------------------------------
int sub_34543( int a1, _WORD *a2, _WORD *a3)
{
  int v3; // edi
  int v4; // eax
  int result; // eax
  int v6; // [esp+0h] [ebp-8h] BYREF
  int v7; // [esp+4h] [ebp-4h] BYREF

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
  JUMPOUT(0x2E981);
}
// 3491C: control flows out of bounds to 2E981
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
      || (sub_4B0D3(word_1998F8, 33) || sub_4B0D3(word_1998F8, 22)) && (sub_38876(), !v0) )
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
  JUMPOUT(0x33AFE);
}
// 34C3D: control flows out of bounds to 33AFE
// 34B21: variable 'v0' is possibly undefined
// 34BCB: variable 'v7' is possibly undefined
// 34BCD: variable 'v8' is possibly undefined
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
    sub_2F4EE(v8);
    sub_34921();
    sub_124E36();
    sub_124D41();
    v2 = 298;
    v3 = 445;
    a2 = 298;
    dword_19284C = sub_127C27((int)aCombatLbx_0, 9, dword_193174);
    v12 = 7;
    v9 = sub_12A478(248, 298, dword_19284C);
    sub_1077D(v9);
  }
  else
  {
    v2 = 445;
    v3 = 298;
    v12 = -7;
    word_199876 = 1;
    v4 = sub_124D7A();
    sub_2C6BA(v4);
    sub_2F4EE(v5);
    sub_34921();
    v6 = sub_124E36();
    sub_1077D(v6);
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
    sub_1077D(v10);
  }
  sub_465D0();
  sub_46CC8(word_1998F8, a2);
  sub_1172FC();
  sub_2C601(v11, a2);
  JUMPOUT(0x33AFE);
}
// 34EC3: control flows out of bounds to 33AFE
// 34C79: variable 'v5' is possibly undefined
// 34CA2: variable 'v8' is possibly undefined
// 34E9E: variable 'v10' is possibly undefined
// 34EBE: variable 'v11' is possibly undefined
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
  sub_103915(2);
  sub_121199(182, 231, word_19B570, v1);
  sub_121199(296, 231, word_19B56E, v1);
  sub_121199(408, 231, word_19B56C, v1);
  sub_128C32(186, 253, (int16_t)(216 * (word_19B56E - word_19B570) / (word_19B56C - word_19B570) + 185), 263, 193);
  JUMPOUT(0x2F166);
}
// 34FBE: control flows out of bounds to 2F166
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
  sub_2F4EE(v6);
  sub_1174CB();
  v7 = sub_124E36();
  sub_1077D(v7);
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
  sub_1077D(v12);
  LOWORD(v13) = sub_123E6C((int)&unk_17CF00, 1);
  while ( 1 )
  {
    v9 = (void *)sub_1171AB(v13, v11, (int)v9, (int)v10);
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
    v13 = sub_1077D(v14);
  }
  sub_1113CC(dword_192ED4, 1);
  sub_11C2F0();
  v15 = sub_1191CA((int)sub_2F4EE, 1);
  sub_2C601(v15, 1);
  sub_46CC8(word_1998F8, 1);
  *a4 = word_19B56E;
  return v23;
}
// 3506A: variable 'v6' is possibly undefined
// 350C7: variable 'v17' is possibly undefined
// 35177: variable 'v12' is possibly undefined
// 35186: variable 'v13' is possibly undefined
// 35201: variable 'v14' is possibly undefined
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
LABEL_72:
        *a2 = 0;
        break;
      case 3:
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
        sub_4528F(a1);
        v34 = v33;
        v35 = (_WORD *)(dword_192864 + 313 * a1);
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
        if ( v41 >= 0 )
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
              sub_127712(v51 + dword_192864 + 178, v43);
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
// 35578: variable 'v33' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998CA: using guessed type int16_t word_1998CA;
// 1998FE: using guessed type int16_t word_1998FE;


//----- (00035821) --------------------------------------------------------
int sub_35821( int a1, int a2, int a3, int a4)
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
          *(_WORD *)(v31 + 292) = *(_WORD *)(v31 + 238);
        }
      }
      return result;
    }
    if ( *(_BYTE *)(v10 + 49) )
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
int sub_35C3A(int result)
{
  qmemcpy((void *)(result + 256), (void *)(result + 202), 0x36u);
  return result;
}


//----- (00035C56) --------------------------------------------------------
void sub_35C56( int a1, int a2, int a3, _WORD *a4, _WORD *a5)
{
  int16_t v5; // ax
  int16_t v6; // ax

  sub_366DD(a1);
  *a4 = v5;
  sub_35D0D(a2, a3);
  *a5 = v6;
}
// 35C69: variable 'v5' is possibly undefined
// 35C77: variable 'v6' is possibly undefined


//----- (00035C7F) --------------------------------------------------------
int16_t sub_35C7F( int a1)
{
  int v1; // eax

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
  return word_17D174[4 * *(uint8_t *)(dword_192864 + 313 * a1 + 172)];
}
// 17D174: using guessed type int16_t word_17D174[];
// 192864: using guessed type int dword_192864;


//----- (00035D0D) --------------------------------------------------------
void sub_35D0D( int a1, int a2)
{
  int v3; // [esp+10h] [ebp-Ch] BYREF
  _DWORD v4[2]; // [esp+14h] [ebp-8h] BYREF

  v4[0] = 0;
  v3 = 0;
  v4[1] = sub_36A63(a1, a2, v4);
  sub_36139(*(uint8_t *)(dword_192864 + 313 * a1 + 32), a2, (int16_t *)&v3);
  JUMPOUT(0x35C34);
}
// 35E07: control flows out of bounds to 35C34
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int dword_197F98;


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
        sub_3607A(v5);
        if ( (int16_t)v6 > (int16_t)v2 )
          v2 = v6;
      }
    }
  }
  return v2;
}
// 35E55: variable 'v6' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00035E6A) --------------------------------------------------------
int sub_35E6A( int a1)
{
  int v1; // edx
  int v2; // eax
  int v3; // ebx

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
void sub_35EAE( int a1)
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
  JUMPOUT(0x35E63);
}
// 35F05: control flows out of bounds to 35E63
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00035F0A) --------------------------------------------------------
int sub_35F0A()
{
  int16_t v0; // ax
  int16_t v1; // ax
  int16_t v2; // dx
  int result; // eax

  sub_35F7E(word_1998AC);
  word_199224[word_1998AC] = v0 + 100;
  sub_35F7E(word_19988E);
  v2 = v1;
  result = word_19988E;
  word_199224[word_19988E] = v2 + 100;
  return result;
}
// 35F20: variable 'v0' is possibly undefined
// 35F37: variable 'v1' is possibly undefined
// 199224: using guessed type int16_t word_199224[15];
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;


//----- (00035F4D) --------------------------------------------------------
void sub_35F4D( int a1)
{
  if ( (*(_BYTE *)(59 * a1 + dword_1930DC + 43) & 4) != 0 )
  {
    sub_94951(a1);
    JUMPOUT(0x35EA8);
  }
  JUMPOUT(0x35E93);
}
// 35F70: control flows out of bounds to 35EA8
// 35F79: control flows out of bounds to 35E93
// 1930DC: using guessed type int dword_1930DC;


//----- (00035F7E) --------------------------------------------------------
void sub_35F7E( int a1)
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
        sub_35F4D(v5);
        if ( v6 > v2 )
          v2 = v6;
      }
    }
  }
  JUMPOUT(0x35E63);
}
// 35FD5: control flows out of bounds to 35E63
// 35FC7: variable 'v6' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00035FDA) --------------------------------------------------------
void sub_35FDA( int a1)
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
        sub_36036(v5);
        if ( v6 > v2 )
          v2 = v6;
      }
    }
  }
  JUMPOUT(0x35E63);
}
// 36031: control flows out of bounds to 35E63
// 36023: variable 'v6' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00036036) --------------------------------------------------------
void sub_36036( int a1)
{
  int v1; // edx
  int v2; // eax

  v1 = a1;
  v2 = dword_1930DC + 59 * a1;
  if ( (*(_BYTE *)(v2 + 38) & 4) != 0 || (*(_BYTE *)(v2 + 38) & 8) != 0 )
    sub_94951(v1);
  JUMPOUT(0x35EA8);
}
// 3605B: control flows out of bounds to 35EA8
// 1930DC: using guessed type int dword_1930DC;


//----- (0003607A) --------------------------------------------------------
void sub_3607A( int a1)
{
  if ( (*(_BYTE *)(dword_1930DC + 59 * a1 + 42) & 1) != 0 )
  {
    sub_94951(a1);
    JUMPOUT(0x35EA8);
  }
  JUMPOUT(0x36064);
}
// 3609F: control flows out of bounds to 35EA8
// 360A8: control flows out of bounds to 36064
// 1930DC: using guessed type int dword_1930DC;


//----- (000360AA) --------------------------------------------------------
void sub_360AA( int a1)
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
        sub_36106(v5);
        if ( v6 > v2 )
          v2 = v6;
      }
    }
  }
  JUMPOUT(0x35E63);
}
// 36101: control flows out of bounds to 35E63
// 360F3: variable 'v6' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00036106) --------------------------------------------------------
void sub_36106( int a1)
{
  if ( (*(_BYTE *)(dword_1930DC + 59 * a1 + 43) & 0x10) != 0 )
  {
    sub_94951(a1);
    JUMPOUT(0x35EA8);
  }
  JUMPOUT(0x36064);
}
// 3612B: control flows out of bounds to 35EA8
// 36134: control flows out of bounds to 36064
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

  v3 = 0;
  if ( a2 == 1 )
  {
    for ( i = 0; i < word_1998C0; ++i )
    {
      v10 = (uint8_t *)(313 * i + dword_192864);
      if ( v10[32] == a1 && !v10[176] && !v10[36] )
      {
        if ( sub_4B0D3(i, 38) )
          *a3 = 70;
        v11 = *(int16_t *)(dword_192864 + 313 * i + 173);
        if ( v11 > -1 )
        {
          sub_3677D(v11);
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
          sub_3677D(v6);
          if ( (int16_t)v7 > (int16_t)v3 )
            v3 = v7;
        }
      }
    }
    return v3;
  }
}
// 36194: variable 'v7' is possibly undefined
// 36246: variable 'v12' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00036266) --------------------------------------------------------
int sub_36266()
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
  int16_t v11; // [esp+0h] [ebp-14h]
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
        sub_367AE(v7);
        if ( (int16_t)v8 > (int16_t)v0 )
          v0 = v8;
        if ( v14 )
        {
          sub_367DF(v7);
          if ( (int16_t)v9 > (int16_t)v2 )
            v2 = v9;
        }
      }
      if ( v14 && sub_4B0D3(i, 28) )
        v13 = 20;
    }
  }
  return v13 + v2 + v0 + v1;
}
// 362C1: variable 'v11' is possibly undefined
// 36339: variable 'v8' is possibly undefined
// 3634F: variable 'v9' is possibly undefined
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
        v9 = *(int16_t *)((char *)&word_17EEE8 + 47 * v8 + 2 * v10) / 10;
        if ( v9 <= 1 )
          LOWORD(v9) = 1;
        *(_WORD *)(a1 + 2 * v7 + 238) = v9;
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
  JUMPOUT(0x3638A);
}
// 366AA: control flows out of bounds to 3638A
// 17EEE8: using guessed type int16_t word_17EEE8;
// 180028: using guessed type int16_t word_180028[];
// 18002A: using guessed type int16_t word_18002A[];
// 18002C: using guessed type int16_t word_18002C[];


//----- (000366AF) --------------------------------------------------------
int sub_366AF( int a1, int a2)
{
  int result; // eax

  result = dword_192864 + 313 * a1;
  if ( *(uint8_t *)(result + 175) < a2 )
    *(_BYTE *)(result + 175) = 0;
  else
    *(_BYTE *)(result + 175) -= a2;
  return result;
}
// 192864: using guessed type int dword_192864;


//----- (000366DD) --------------------------------------------------------
void sub_366DD( int a1)
{
  sub_35C7F(a1);
  sub_4B0D3(a1, 5);
  sub_36266();
  JUMPOUT(0x35C34);
}
// 36778: control flows out of bounds to 35C34
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int dword_197F98;


//----- (0003677D) --------------------------------------------------------
void sub_3677D( int a1)
{
  if ( (*(_BYTE *)(59 * a1 + dword_1930DC + 42) & 0x40) != 0 )
  {
    sub_94951(a1);
    JUMPOUT(0x35EA8);
  }
  JUMPOUT(0x35E93);
}
// 367A0: control flows out of bounds to 35EA8
// 367A9: control flows out of bounds to 35E93
// 1930DC: using guessed type int dword_1930DC;


//----- (000367AE) --------------------------------------------------------
void sub_367AE( int a1)
{
  if ( (*(_BYTE *)(59 * a1 + dword_1930DC + 43) & 0x40) != 0 )
  {
    sub_94951(a1);
    JUMPOUT(0x35EA8);
  }
  JUMPOUT(0x35E93);
}
// 367D1: control flows out of bounds to 35EA8
// 367DA: control flows out of bounds to 35E93
// 1930DC: using guessed type int dword_1930DC;


//----- (000367DF) --------------------------------------------------------
void sub_367DF( int a1)
{
  if ( (*(_BYTE *)(59 * a1 + dword_1930DC + 42) & 0x10) != 0 )
  {
    sub_94951(a1);
    JUMPOUT(0x35EA8);
  }
  JUMPOUT(0x35E93);
}
// 36802: control flows out of bounds to 35EA8
// 3680B: control flows out of bounds to 35E93
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
      result = sub_FE92D((int)v22, 19);
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

  v4 = 0;
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
        sub_27F9F();
        v14 = v12 != -1;
        v15 = v11 == 13 && v14 && v13;
        v16 = v15;
        v26 = 313 * a1;
        v17 = dword_192864 + v26 + 11 * i;
        *(_BYTE *)(v17 + 90) = 1;
        if ( !byte_17F80F[28 * v11] && (*(_BYTE *)(v17 + 86) & 4) != 0 || v16 || v11 == 33 )
        {
          v29 = v32 - v30;
          v28 = v34 - v33;
          if ( v11 != 13
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
// 36D75: variable 'v13' is possibly undefined
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

  if ( *(_BYTE *)(dword_192864 + 313 * a1 + 64) != 4 )
  {
    for ( i = 0; i < word_1998C0 && !(uint16_t)sub_3897A(a1); ++i )
    {
      v20 = 313 * i;
      if ( *(_BYTE *)(dword_192864 + v20 + 32) != *(_BYTE *)(313 * a1 + dword_192864 + 32) && sub_42A27(i) )
      {
        v6 = v20 + dword_192864;
        if ( *(_BYTE *)(v20 + dword_192864 + 64) != 1 && *(_BYTE *)(v6 + 64) != 4 && *(_BYTE *)(v6 + 177) )
        {
          sub_49ED1(a1, &v27, &v25);
          v7 = sub_286E8(i, v27 + a2, v25 + a3);
          v8 = sub_286E8(i, v27 + a4, v25 + a5);
          if ( v7 < 1 )
            v7 = 1;
          if ( v7 <= 8 && v7 <= v8 )
          {
            v9 = (int16_t)(100 * (9 - v7) / (9 - (*(uint8_t *)(dword_192864 + 313 * i + 177) + 2) / 3));
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
              sub_37173(i);
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
  JUMPOUT(0x3581B);
}
// 3716E: control flows out of bounds to 3581B
// 3712B: variable 'v12' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00037173) --------------------------------------------------------
void sub_37173( int a1)
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
            sub_4528F(i);
            v10 = v8 - v9;
            if ( v10 <= 0 )
              v10 = 1;
            if ( v10 < v1 )
              v1 = v10;
          }
        }
      }
      JUMPOUT(0x3638A);
    }
  }
}
// 3724F: control flows out of bounds to 3638A
// 37230: variable 'v9' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00037254) --------------------------------------------------------
void sub_37254( int a1, int a2)
{
  int16_t v2; // di
  int16_t v3; // si
  int16_t i; // bx

  v2 = 0;
  v3 = 0;
  for ( i = 0; i < 39 && !v3; ++i )
  {
    if ( (uint16_t)sub_1276F0(313 * a1 + dword_192864 + 76, i) )
    {
      if ( v2 == a2 )
        v3 = 1;
      else
        ++v2;
    }
  }
  JUMPOUT(0x35C34);
}
// 372B8: control flows out of bounds to 35C34
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
// local variable allocation has failed, the output may be wrong!
void sub_37308( int a1,
        int a2, int a3,
        int a4,
        int a5,
        int a6, int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        hr_int128_t a14,
        int a15,
        hr_int128_t a16,
        int64_t a17,
        int64_t a18,
        int a19,
        int64_t a20)
{
  char v20; // dl
  int v21; // eax
  int v22; // edx
  int v23; // ebx
  int v24; // edi
  int v25; // eax
  int v26; // eax
  int v27; // esi
  int v28; // eax
  int v29; // esi
  int v30; // eax
  int v31; // esi
  int v32; // eax
  int v33; // esi
  int v34; // eax
  int v35; // esi
  int v36; // esi
  int16_t v37; // si
  int v38; // edi
  int v39; // eax
  int v40; // edx
  int v41; // ecx
  char *v42; // edi
  char *v43; // edi
  char *v44; // edi
  char *v45; // edi
  char *v46; // edi
  int16_t v47; // ax
  char *v48; // edi
  char *v49; // edi
  int v50; // eax
  char *v51; // edi
  char *v52; // edi
  char *v53; // edi
  int v54; // eax
  char *v55; // edi
  int v56; // ecx
  char *v57; // edi
  char *v58; // edi
  int v59; // esi
  char *v60; // esi
  char *v61; // edi
  char *v62; // edi
  char *v63; // edi
  char *v64; // edi
  int16_t v65; // dx
  char *v66; // edi
  int16_t v67; // ax
  char *v68; // edi
  char *v69; // edi
  char *v70; // edi
  char *v71; // edi
  int v72; // ecx
  char *v73; // edi
  char *v74; // edi
  char *v75; // edi
  int v76; // eax
  char *v77; // edi
  int v78; // ecx
  int v79; // eax
  int v80; // ecx
  char *v81; // edi
  char *v82; // edi
  char *v83; // edi
  int v84; // eax
  char *v85; // edi
  int v86; // esi
  int16_t v87; // ax
  int v88; // ecx
  int v89; // ecx
  int v91; // eax
  int16_t *v92; // [esp+76h] [ebp-2FEh]
  int16_t v93; // [esp+7Ah] [ebp-2FAh]
  int16_t v94; // [esp+7Eh] [ebp-2F6h]
  char v95; // [esp+81h] [ebp-2F3h] BYREF
  char v96[500]; // [esp+82h] [ebp-2F2h] BYREF
  char v97[79]; // [esp+276h] [ebp-FEh] BYREF
  _BYTE v98[81]; // [esp+2C5h] [ebp-AFh] BYREF
  int16_t v99[2]; // [esp+316h] [ebp-5Eh] BYREF
  int v100; // [esp+31Ah] [ebp-5Ah]
  _BYTE v101[4]; // [esp+34Eh] [ebp-26h] BYREF
  int v102; // [esp+352h] [ebp-22h]
  _UNKNOWN *retaddr; // [esp+384h] [ebp+10h]

  v20 = *(_BYTE *)(313 * a1 + dword_192864 + 32);
  *(_DWORD *)((char *)&a16 + 6) = 0;
  if ( v20 != *(_BYTE *)(313 * v93 + dword_192864 + 32) )
  {
    v21 = 0;
    do
    {
      v22 = (int16_t)v21++;
      *((_WORD *)&retaddr + v22 + 1) = 0;
    }
    while ( (int16_t)v21 < 19 );
    v23 = 313 * v93;
    v24 = 313 * v94;
    HIWORD(a19) = *(uint8_t *)(dword_192864 + v23 + 175);
    HIWORD(v25) = HIWORD(v92);
    LOWORD(v25) = *v92;
    *(_DWORD *)((char *)&a18 + 6) = v25;
    sub_35FDA(*(uint8_t *)(v24 + dword_192864 + 32));
    v27 = v26;
    LOWORD(v28) = sub_35CAD(v94);
    v29 = v28 + v27;
    sub_35FDA(*(uint8_t *)(dword_192864 + v23 + 32));
    *(_DWORD *)((char *)&a17 + 2) = v29;
    v31 = v30;
    sub_360AA(*(uint8_t *)(dword_192864 + v23 + 32));
    v33 = 20 * sub_4B0D3(v93, 29) + v32 + v31;
    LOWORD(v34) = sub_35CAD(v93);
    *(_DWORD *)((char *)&a20 + 2) = v34 + v33;
    sub_EC767(
      *(uint8_t *)(dword_192864 + v24 + 32),
      *v92,
      SWORD1(a17),
      *(uint8_t *)(dword_192864 + v23 + 32),
      SHIWORD(a19),
      v34 + v33,
      v99,
      (int)v101);
    *(_DWORD *)((char *)&a17 + 2) = v100;
    *(_DWORD *)((char *)&a16 + 14) = 0;
    *(_DWORD *)((char *)&a20 + 2) = v102;
    while ( SHIWORD(a16) < *v92 )
    {
      *(_DWORD *)((char *)&a16 + 2) = 50;
      v35 = *(_DWORD *)((char *)&a17 + 2);
      v36 = sub_1247A0(0x64u) + v35;
      v37 = v36 - (WORD1(a20) + sub_1247A0(0x64u));
      if ( v37 > 20 )
      {
        v38 = 0;
        do
        {
          sub_384A8(v93, (_WORD *)&a16 + 5, (_WORD *)&a15 + 1);
          if ( SWORD5(a16) != -1 )
          {
            if ( WORD5(a16) < 5u )
            {
              if ( WORD5(a16) >= 2u )
              {
                if ( WORD5(a16) <= 2u )
                {
                  LOWORD(a2) = a2 + 1;
                }
                else if ( WORD5(a16) == 3 )
                {
                  ++*(&a3 + SHIWORD(a15));
                }
              }
            }
            else if ( WORD5(a16) <= 5u )
            {
              ++HIWORD(retaddr);
            }
            else if ( WORD5(a16) >= 8u )
            {
              if ( WORD5(a16) <= 8u )
              {
                ++HIWORD(a2);
              }
              else if ( WORD5(a16) == 9 )
              {
                ++*(&a7 + SHIWORD(a15));
              }
            }
            sub_35251(v93, (int16_t *)&a16 + 1, SWORD5(a16), SHIWORD(a15), 0);
          }
          ++v38;
        }
        while ( (int16_t)v38 < 2 );
      }
      if ( v37 > 50 && SHIWORD(a19) > 0 )
        --HIWORD(a19);
      if ( v37 < -50 )
        --*(_DWORD *)((char *)&a18 + 6);
      ++*(_DWORD *)((char *)&a16 + 14);
    }
    v39 = 0;
    do
    {
      v40 = (int16_t)v39;
      LOWORD(v40) = *((_WORD *)&retaddr + (int16_t)v39++ + 1);
      *(_DWORD *)((char *)&a16 + 6) += v40;
    }
    while ( (int16_t)v39 < 19 );
    sub_58F1E(42, v97, 80);
    strcpy(&v98[1], v97);
    *(_DWORD *)((char *)&a14 + 6) = v93;
    v41 = 313 * v93;
    v42 = v98;
    do
      ++v42;
    while ( *v42 );
    strcpy(v42, (char *)(v41 + dword_192864));
    sub_58F1E(92, v97, 80);
    strcpy(v96, v97);
    itoa(SWORD1(a17), (char *)&a11 + 2, 10, v41);
    v43 = &v95;
    do
      ++v43;
    while ( *v43 );
    strcpy(v43, (char *)&a11 + 2);
    v44 = &v95;
    do
      ++v44;
    while ( *v44 );
    strcpy(v44, asc_178CD8);
    sub_58F1E(93, v97, 80);
    strcpy(v96, v97);
    itoa(SWORD1(a20), (char *)&a11 + 2, 10, v41);
    v45 = &v95;
    do
      ++v45;
    while ( *v45 );
    strcpy(v45, (char *)&a11 + 2);
    v46 = &v95;
    do
      ++v46;
    while ( *v46 );
    strcpy(v46, asc_178CE3);
    if ( SWORD3(a16) <= 0 )
    {
      sub_58F1E(47, v97, 80);
      v71 = &v95;
      do
        ++v71;
      while ( *v71 );
      strcpy(v71, v97);
    }
    else
    {
      v47 = sub_3897A(SWORD3(a14));
      if ( v47 > 0 )
        sub_39E15(
          SWORD3(a14),
          20 * *(uint8_t *)(dword_192864 + v41 + 33),
          20 * *(uint8_t *)(dword_192864 + v41 + 34),
          v47);
      if ( SHIWORD(retaddr) > 0 )
      {
        sub_58F1E(43, v97, 80);
        v48 = &v95;
        do
          ++v48;
        while ( *v48 );
        strcpy(v48, v97);
      }
      if ( (int16_t)a2 > 0 )
      {
        sub_58F1E(44, v97, 80);
        v49 = &v95;
        do
          ++v49;
        while ( *v49 );
        strcpy(v49, v97);
        if ( *(int16_t *)(dword_192864 + 313 * v93 + 308) <= 0 )
          v50 = 46;
        else
          v50 = 45;
        sub_58F1E(v50, v97, 80);
        v51 = &v95;
        do
          ++v51;
        while ( *v51 );
        strcpy(v51, v97);
      }
      if ( SHIWORD(a2) > 0 )
      {
        sub_58F1E(21, v97, 80);
        v52 = &v95;
        do
          ++v52;
        while ( *v52 );
        strcpy(v52, v97);
        v53 = &v95;
        do
          ++v53;
        while ( *v53 );
        strcpy(v53, (char *)&off_178CE6);
        if ( *(int16_t *)(dword_192864 + 313 * v93 + 258) <= 0 )
          v54 = 46;
        else
          v54 = 45;
        sub_58F1E(v54, v97, 80);
        v55 = &v95;
        do
          ++v55;
        while ( *v55 );
        strcpy(v55, v97);
      }
      *(_DWORD *)((char *)&a18 + 2) = 0;
      do
      {
        *(_DWORD *)((char *)&a14 + 14) = SWORD1(a18);
        v56 = 2 * SWORD1(a18);
        if ( *(int16_t *)((char *)&a3 + v56) > 0 )
        {
          itoa(*(&a3 + SWORD1(a18)), (char *)&a11 + 2, 10, 2 * SWORD1(a18));
          v57 = &v95;
          do
            ++v57;
          while ( *v57 );
          strcpy(v57, (char *)&a11 + 2);
          v58 = &v95;
          do
            ++v58;
          while ( *v58 );
          strcpy(v58, (char *)&off_178CE6);
          v59 = 11 * *(_DWORD *)((char *)&a14 + 14);
          if ( *(int16_t *)((char *)&a3 + v56) <= 1 )
            v60 = (char *)*(&off_17F803 + 7 * *(int16_t *)(v59 + 313 * v93 + dword_192864 + 82));
          else
            v60 = (char *)*(&off_17F807 + 7 * *(int16_t *)(v59 + dword_192864 + 313 * v93 + 82));
          v61 = &v95;
          do
            ++v61;
          while ( *v61 );
          strcpy(v61, v60);
          v62 = &v95;
          do
            ++v62;
          while ( *v62 );
          strcpy(v62, (char *)&off_178CE6);
          sub_58F1E(46, v97, 80);
          v63 = &v95;
          do
            ++v63;
          while ( *v63 );
          strcpy(v63, v97);
        }
        ++*(_DWORD *)((char *)&a18 + 2);
      }
      while ( SWORD1(a18) < 8 );
      *(_DWORD *)((char *)&a17 + 6) = 0;
      do
      {
        *(_DWORD *)((char *)&a14 + 10) = SHIWORD(a17);
        if ( *(&a7 + SHIWORD(a17)) > 0 )
        {
          itoa(*(&a7 + SHIWORD(a17)), (char *)&a11 + 2, 10, 2 * SHIWORD(a17));
          v64 = &v95;
          do
            ++v64;
          while ( *v64 );
          strcpy(v64, (char *)&a11 + 2);
          v65 = WORD5(a14);
          v66 = &v95;
          do
            ++v66;
          while ( *v66 );
          strcpy(v66, (char *)&off_178CE6);
          sub_37254(v93, v65);
          v68 = &v95;
          do
            ++v68;
          while ( *v68 );
          strcpy(v68, *(char **)((char *)&off_17EEE0 + 47 * v67));
          v69 = &v95;
          do
            ++v69;
          while ( *v69 );
          strcpy(v69, (char *)&off_178CE6);
          sub_58F1E(46, v97, 80);
          v70 = &v95;
          do
            ++v70;
          while ( *v70 );
          strcpy(v70, v97);
        }
        ++*(_DWORD *)((char *)&a17 + 6);
      }
      while ( SHIWORD(a17) < 8 );
    }
    if ( SHIWORD(a18) < *v92 )
    {
      v72 = SHIWORD(a18);
      itoa(*v92 - SHIWORD(a18), (char *)&a11 + 2, 10, SHIWORD(a18));
      v73 = &v95;
      do
        ++v73;
      while ( *v73 );
      strcpy(v73, (char *)&off_178CE6 + 2);
      v74 = &v95;
      do
        ++v74;
      while ( *v74 );
      strcpy(v74, (char *)&a11 + 2);
      v75 = &v95;
      do
        ++v75;
      while ( *v75 );
      strcpy(v75, (char *)&off_178CE6);
      if ( *v92 - v72 <= 1 )
        v76 = 94;
      else
        v76 = 95;
      sub_58F1E(v76, v97, 80);
      v77 = &v95;
      do
        ++v77;
      while ( *v77 );
      strcpy(v77, v97);
    }
    v78 = 313 * v93 + dword_192864;
    *(_DWORD *)((char *)&a14 + 2) = 313 * v93;
    if ( *(uint8_t *)(v78 + 175) > SHIWORD(a19) )
    {
      v79 = *(uint8_t *)(v78 + 175);
      v80 = SHIWORD(a19);
      itoa(v79 - SHIWORD(a19), (char *)&a11 + 2, 10, SHIWORD(a19));
      v81 = &v95;
      do
        ++v81;
      while ( *v81 );
      strcpy(v81, (char *)&off_178CE6 + 2);
      v82 = &v95;
      do
        ++v82;
      while ( *v82 );
      strcpy(v82, (char *)&a11 + 2);
      v83 = &v95;
      do
        ++v83;
      while ( *v83 );
      strcpy(v83, (char *)&off_178CE6);
      if ( *(uint8_t *)(*(_DWORD *)((char *)&a14 + 2) + dword_192864 + 175) - v80 <= 1 )
        v84 = 96;
      else
        v84 = 97;
      sub_58F1E(v84, v97, 80);
      v85 = &v95;
      do
        ++v85;
      while ( *v85 );
      strcpy(v85, v97);
    }
    v86 = sub_147D7(67);
    if ( *(uint8_t *)(dword_192864 + 313 * v94 + 32) == word_1998AC )
      v87 = word_192B12;
    else
      v87 = word_192B10[0];
    if ( (v87
       || (v88 = 313 * v93 + dword_192864, *(_BYTE *)(v88 + 32) >= 8u)
       || *(_BYTE *)(3753 * *(uint8_t *)(v88 + 32) + dword_197F98 + 40) != 100)
      && (word_199900
       || (v89 = 313 * v94 + dword_192864, *(_BYTE *)(v89 + 32) >= 8u)
       || *(_BYTE *)(3753 * *(uint8_t *)(v89 + 32) + dword_197F98 + 40) != 100) )
    {
      sub_A5EBC(&v98[1], v96, 54);
    }
    else
    {
      sub_A5EB2((int)&v98[1], (int)v96);
    }
    sub_112C96(v86, 10);
    *(_BYTE *)(313 * v93 + dword_192864 + 175) = BYTE2(a19);
    v91 = *(_DWORD *)((char *)&a18 + 6);
    *v92 = HIWORD(a18);
    sub_2C601(v91, (int)v92);
  }
}
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
// 197F98: using guessed type int dword_197F98;
// 1998AC: using guessed type int16_t word_1998AC;
// 199900: using guessed type int16_t word_199900;


//----- (00037DA8) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void sub_37DA8( int a1,
        int a2,
        int a3,
        int a4, int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18, int a19,
        hr_int128_t a20,
        int64_t a21,
        int64_t a22,
        int64_t a23,
        int a24,
        int a25,
        int a26,
        int a27)
{
  int v27; // ebx
  int16_t v28; // ax
  int16_t v29; // di
  int v30; // eax
  int v31; // edx
  int v32; // eax
  _BOOL2 v33; // ax
  char *v34; // edi
  int v35; // eax
  int v36; // eax
  char *v37; // edi
  char *v38; // edi
  char *v39; // edi
  char *v40; // edi
  char *v41; // edi
  char *v42; // edi
  char *v43; // edi
  char *v44; // edi
  int16_t v45; // ax
  int v46; // eax
  int v47; // eax
  _BOOL2 v48; // cx
  int v49; // esi
  int v50; // eax
  char *v51; // edi
  int v52; // esi
  int v53; // eax
  int16_t v54; // [esp+6Eh] [ebp-2BAh]
  int v55; // [esp+72h] [ebp-2B6h]
  int16_t v56; // [esp+76h] [ebp-2B2h]
  int16_t v57; // [esp+7Ah] [ebp-2AEh]
  char v58; // [esp+7Dh] [ebp-2ABh] BYREF
  int16_t v59; // [esp+7Eh] [ebp-2AAh] BYREF
  char v60; // [esp+80h] [ebp-2A8h]
  char v61[79]; // [esp+272h] [ebp-B6h] BYREF
  _BYTE v62[81]; // [esp+2C1h] [ebp-67h] BYREF
  int16_t v63[2]; // [esp+312h] [ebp-16h] BYREF
  _WORD v64[9]; // [esp+316h] [ebp-12h] BYREF
  char vars3; // [esp+32Bh] [ebp+3h]

  v27 = 313 * v56;
  *(_DWORD *)((char *)&a20 + 2) = 313 * a1;
  if ( *(_BYTE *)(dword_192864 + *(_DWORD *)((char *)&a20 + 2) + 32) != *(_BYTE *)(v27 + dword_192864 + 32) )
  {
    HIWORD(a20) = *(uint8_t *)(v27 + dword_192864 + 175);
    *(_DWORD *)((char *)&a22 + 2) = v55;
    *(_DWORD *)((char *)&a20 + 6) = *(_DWORD *)((char *)&a20 + 14);
    sub_35FDA(*(uint8_t *)(dword_192864 + *(_DWORD *)((char *)&a20 + 2) + 32));
    v29 = v28;
    sub_35FDA(*(uint8_t *)(v27 + dword_192864 + 32));
    v31 = v30;
    sub_360AA(*(uint8_t *)(v27 + dword_192864 + 32));
    *(_DWORD *)((char *)&a20 + 10) = v32 + v31;
    v33 = sub_4B0D3(v56, 29);
    sub_EC767(
      *(uint8_t *)(*(_DWORD *)((char *)&a20 + 2) + dword_192864 + 32),
      v55,
      v29,
      *(uint8_t *)(v27 + dword_192864 + 32),
      SHIWORD(a20),
      20 * v33 + WORD5(a20),
      v63,
      (int)&a6 + 2);
    while ( SHIWORD(a20) > 0 && (int16_t)v55 > 0 )
    {
      sub_EC4FE((uint8_t *)v63, (uint8_t *)&a6 + 2);
      if ( vars3 > -1 )
        LOWORD(v55) = v55 - 1;
      if ( SHIBYTE(a12) > -1 )
        --HIWORD(a20);
    }
    *(_DWORD *)((char *)&a21 + 2) = v55;
    *(_DWORD *)((char *)&a22 + 6) = *(_DWORD *)((char *)&a20 + 14);
    *(_DWORD *)((char *)&a23 + 2) = *(_DWORD *)((char *)&a20 + 6) - *(_DWORD *)((char *)&a20 + 14);
    *(_DWORD *)((char *)&a21 + 6) = *(_DWORD *)((char *)&a22 + 2) - v55;
    sub_58F1E(48, v61, 80);
    strcpy(&v62[1], v61);
    v34 = v62;
    do
      ++v34;
    while ( *v34 );
    strcpy(v34, (char *)(313 * v56 + dword_192864));
    v35 = 313 * v57 + dword_192864;
    if ( *(_BYTE *)(v35 + 32) >= 8u || *(_BYTE *)(dword_197F98 + 3753 * *(uint8_t *)(v35 + 32) + 40) != 100 )
      v64[0] -= SHIBYTE(a5);
    v36 = dword_192864 + 313 * v56;
    if ( *(_BYTE *)(v36 + 32) >= 8u || *(_BYTE *)(dword_197F98 + 3753 * *(uint8_t *)(v36 + 32) + 40) != 100 )
      HIWORD(a7) -= SHIBYTE(a19);
    sub_103C5B(0, (int)&a22 + 2);
    sub_103C5B(1, (int)&a21 + 6);
    sub_103C5B(2, (int)&a21 + 2);
    sub_103C5B(3, (int)&a20 + 6);
    sub_103C5B(4, (int)&a23 + 2);
    sub_103C5B(5, (int)&a22 + 6);
    sub_103C5B(6, (int)v64);
    sub_103C5B(7, (int)&a7 + 2);
    v59 = unk_178CEA;
    v60 = unk_178CEC;
    sub_58F1E(92, v61, 80);
    v37 = &v58;
    do
      ++v37;
    while ( *v37 );
    strcpy(v37, v61);
    v38 = &v58;
    do
      ++v38;
    while ( *v38 );
    strcpy(v38, byte_178CED);
    sub_58F1E(93, v61, 80);
    v39 = &v58;
    do
      ++v39;
    while ( *v39 );
    strcpy(v39, v61);
    sub_58F1E(100, v61, 80);
    v40 = &v58;
    do
      ++v40;
    while ( *v40 );
    strcpy(v40, byte_178CF7);
    v41 = &v58;
    do
      ++v41;
    while ( *v41 );
    strcpy(v41, v61);
    v42 = &v58;
    do
      ++v42;
    while ( *v42 );
    strcpy(v42, byte_178D26);
    v43 = &v58;
    do
      ++v43;
    while ( *v43 );
    strcpy(v43, v61);
    v44 = &v58;
    do
      ++v44;
    while ( *v44 );
    strcpy(v44, aX48X223);
    if ( *(uint8_t *)(313 * v56 + dword_192864 + 32) == word_1998AC )
      v45 = word_192B10[0];
    else
      v45 = word_192B12;
    v48 = 0;
    if ( v45
      || (v46 = dword_192864 + 313 * v56, *(_BYTE *)(v46 + 32) >= 8u)
      || *(_BYTE *)(dword_197F98 + 3753 * *(uint8_t *)(v46 + 32) + 40) != 100 )
    {
      if ( word_199900
        || (v47 = dword_192864 + 313 * v57, *(_BYTE *)(v47 + 32) >= 8u)
        || *(_BYTE *)(dword_197F98 + 3753 * *(uint8_t *)(v47 + 32) + 40) != 100 )
      {
        v48 = 1;
      }
    }
    if ( (int16_t)v55 <= 0 )
    {
      *(_BYTE *)(313 * v56 + dword_192864 + 175) = BYTE14(a20);
      v50 = 51;
    }
    else
    {
      v49 = 313 * v56;
      *(_BYTE *)(dword_192864 + v49 + 175) = v55 - BYTE14(a20);
      sub_38312(v56, v54, SHIWORD(a27));
      if ( *(_BYTE *)(v49 + dword_192864 + 36) )
        v50 = 49;
      else
        v50 = 50;
    }
    sub_58F1E(v50, v61, 80);
    v51 = &v58;
    do
      ++v51;
    while ( *v51 );
    strcpy(v51, v61);
    v52 = sub_147D7(67);
    if ( v48 )
      sub_A5EBC(&v62[1], &v59, 54);
    else
      sub_A5EB2((int)&v62[1], (int)&v59);
    v53 = sub_112C96(v52, 10);
    sub_2C601(v53, 10);
  }
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
// 197F98: using guessed type int dword_197F98;
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
  sub_4588C(a1);
  if ( v9 >= 8 || !*(_BYTE *)(3753 * v9 + dword_197F98 + 2232) )
    *(_BYTE *)(dword_192864 + 313 * a1 + 176) = 1;
  v10 = 313 * a1;
  v11 = dword_192864;
  *(_BYTE *)(dword_192864 + v10 + 75) = 0;
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
// 197F98: using guessed type int dword_197F98;
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
      v17[v12] = 100 - 100 * (uint16_t)v17[v12] / v18;
    ++v12;
  }
  while ( v12 < 19 );
  result = sub_FE92D((int)v17, 19);
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

  v1 = 313 * a1;
  v2 = sub_4B0D3(a1, 24);
  result = 5 * word_18002A[18 * *(uint8_t *)(v1 + dword_192864 + 37)];
  if ( v2 )
    return 15 * word_18002A[18 * *(uint8_t *)(v1 + dword_192864 + 37)];
  return result;
}
// 18002A: using guessed type int16_t word_18002A[];
// 192864: using guessed type int dword_192864;


//----- (0003868F) --------------------------------------------------------
void sub_3868F( int a1)
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

  v17 = a1;
  v16 = 1;
  for ( i = 1; ; ++i )
  {
    if ( (int16_t)i >= word_1998C0 )
      JUMPOUT(0x3638A);
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
// 38835: control flows out of bounds to 3638A
// 180EC8: using guessed type int16_t word_180EC8[6];
// 192844: using guessed type int dword_192844;
// 192864: using guessed type int dword_192864;
// 1998A2: using guessed type int16_t word_1998A2;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0003883A) --------------------------------------------------------
int sub_3883A( int a1)
{
  return sub_1276F0(313 * a1 + dword_192864 + 72, 2u);
}
// 192864: using guessed type int dword_192864;


//----- (00038858) --------------------------------------------------------
int sub_38858( int a1)
{
  return sub_127712(313 * a1 + dword_192864 + 72, 2u);
}
// 192864: using guessed type int dword_192864;


