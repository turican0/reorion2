#include "orion_common.h"

/* Adresni rozsah: 0x71CE7 - 0x79E06  (200 funkci) */

//----- (00071CE7) --------------------------------------------------------
void sub_71CE7()
{
  _BOOL1 v0; // cl
  int16_t i; // bx
  int v2; // esi
  int v3; // edi
  int16_t v4; // [esp+0h] [ebp-8h]
  int16_t v5; // [esp+4h] [ebp-4h]

  if ( word_1999B8 != -1 )
  {
    v5 = *(int16_t *)((char *)&word_1975D4 + 5 * word_192248[word_1999B8]);
    v4 = sub_7A3E3(*(_WORD *)(dword_197F9C + 129 * v5 + 103), *(_WORD *)(dword_197F9C + 129 * v5 + 105));
    if ( v4 != -1 )
    {
      v0 = 0;
      for ( i = 0; i < word_199994 && !v0; ++i )
      {
        v2 = 129 * i;
        if ( *(char *)(v2 + dword_197F9C + 100) < 3 && sub_78182(v5) )
        {
          v3 = 129 * v5;
          if ( (uint16_t)sub_78E07(*(int16_t *)(v3 + dword_197F9C + 101)) != word_19999A
            && *(_WORD *)(dword_197F9C + v2 + 103) == *(_WORD *)(v3 + dword_197F9C + 103) )
          {
            v0 = *(_WORD *)(dword_197F9C + v2 + 105) == *(_WORD *)(v3 + dword_197F9C + 105);
          }
        }
      }
      if ( v0 )
        sub_79D40(113 * v4 + dword_19306C);
    }
  }
  JUMPOUT(0x7086E);
}
// 71DD3: control flows out of bounds to 7086E
// 192248: using guessed type int16_t word_192248[500];
// 19306C: using guessed type int dword_19306C;
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999A: using guessed type int16_t word_19999A;
// 1999B8: using guessed type int16_t word_1999B8;


//----- (00071DD8) --------------------------------------------------------
void sub_71DD8( int a1)
{
  int16_t v1; // bx
  int v2; // edx
  int16_t v3; // cx
  int16_t v4; // dx
  _BOOL1 v5; // al
  _BOOL1 v6; // al
  int16_t i; // si
  int16_t j; // cx
  _BOOL1 v10; // [esp+8h] [ebp-Ch]
  char v11; // [esp+Ch] [ebp-8h]
  char v12; // [esp+10h] [ebp-4h]

  if ( word_1999B8 != -1 )
  {
    v1 = word_192248[word_1999B8];
    v2 = *(int16_t *)((char *)&word_1975D4 + 5 * v1);
    v3 = sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * v1));
    v4 = *(_WORD *)(dword_197F9C + 129 * v2 + 101);
    v12 = 0;
    v5 = v4 > -1 && v4 < 500;
    v10 = v5;
    v6 = v4 > 1000 && v4 < 1072;
    if ( v6 )
      v4 -= 1000;
    if ( v3 == word_19999C && (v10 || v6) && *(char *)(dword_19306C + 113 * v4 + 55) == word_19999C )
    {
      for ( i = 0; i < a1 && !v12 && v1 > -1; ++i )
      {
        if ( *(_BYTE *)(dword_197F9C + 129 * *(int16_t *)((char *)&word_1975D4 + 5 * v1) + 17) == 4 )
        {
          v11 = 0;
          for ( j = 0; j < 5 && !v11; ++j )
          {
            if ( sub_7022D(*(_WORD *)(dword_19306C + 113 * v4 + 2 * j + 74)) )
            {
              v11 = 1;
              v12 = 1;
            }
          }
        }
        v1 = *(int16_t *)((char *)&word_1975D6 + 5 * v1);
      }
    }
  }
  JUMPOUT(0x7086E);
}
// 71DF0: control flows out of bounds to 7086E
// 192248: using guessed type int16_t word_192248[500];
// 19306C: using guessed type int dword_19306C;
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;


//----- (00071F35) --------------------------------------------------------
void sub_71F35( int a1)
{
  int16_t v1; // bx
  int v2; // edx
  int16_t v3; // cx
  int16_t v4; // dx
  _BOOL1 v5; // al
  _BOOL1 v6; // ah
  _BOOL1 v7; // al
  int16_t i; // si
  int v9; // ecx
  int16_t j; // cx
  char v12; // [esp+8h] [ebp-Ch]
  char v13; // [esp+Ch] [ebp-8h]

  if ( word_1999B8 != -1 )
  {
    v1 = word_192248[word_1999B8];
    v2 = *(int16_t *)((char *)&word_1975D4 + 5 * v1);
    v3 = sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * v1));
    v4 = *(_WORD *)(dword_197F9C + 129 * v2 + 101);
    v13 = 0;
    v5 = v4 > -1 && v4 < 500;
    v6 = v5;
    v7 = v4 > 1000 && v4 < 1072;
    if ( v7 )
      v4 -= 1000;
    if ( v3 == word_19999C && (v6 || v7) && *(char *)(dword_19306C + 113 * v4 + 55) == word_19999C )
    {
      for ( i = 0; i < a1 && !v13 && v1 > -1; ++i )
      {
        v9 = *(int16_t *)((char *)&word_1975D4 + 5 * v1);
        sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * v1));
        if ( *(_BYTE *)(dword_197F9C + 129 * v9 + 17) == 1 )
        {
          v12 = 0;
          for ( j = 0; j < 5 && !v12; ++j )
          {
            if ( sub_714A1(*(_WORD *)(dword_19306C + 113 * v4 + 2 * j + 74)) )
            {
              v12 = 1;
              v13 = 1;
            }
          }
        }
        v1 = *(int16_t *)((char *)&word_1975D6 + 5 * v1);
      }
    }
  }
  JUMPOUT(0x7086E);
}
// 72098: control flows out of bounds to 7086E
// 192248: using guessed type int16_t word_192248[500];
// 19306C: using guessed type int dword_19306C;
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;


//----- (0007209D) --------------------------------------------------------
void sub_7209D( int a1)
{
  _BOOL1 v1; // bl
  int16_t v2; // cx
  int16_t v3; // si
  int16_t v4; // di
  int16_t v5; // dx
  _BOOL1 v6; // al
  _BOOL1 v7; // bh
  _BOOL1 v8; // al
  int16_t i; // di
  int v10; // esi
  int v11; // eax
  _BOOL1 v13; // [esp+Ch] [ebp-4h]

  v1 = 0;
  if ( word_1999B8 != -1 )
  {
    v2 = word_192248[word_1999B8];
    v3 = *(int16_t *)((char *)&word_1975D4 + 5 * v2);
    v4 = sub_77FF5(v3);
    v5 = *(_WORD *)(dword_197F9C + 129 * v3 + 101);
    v6 = v5 > -1 && v5 < 500;
    v7 = v6;
    v8 = v5 > 1000 && v5 < 1072;
    v13 = v8;
    if ( v8 )
      sub_7A3E3(*(_WORD *)(129 * v3 + dword_197F9C + 103), *(_WORD *)(129 * v3 + dword_197F9C + 105));
    if ( v4 == word_19999C && (v7 || v13) )
    {
      for ( i = 0; i < a1 && !v1 && v2 > -1; ++i )
      {
        v10 = *(int16_t *)((char *)&word_1975D4 + 5 * v2);
        v11 = 129 * v10 + dword_197F9C;
        if ( !*(_BYTE *)(v11 + 17) && *(char *)(v11 + 100) < 3 )
          v1 = sub_77FF5(v10) == word_19999C;
        v2 = *(int16_t *)((char *)&word_1975D6 + 5 * v2);
      }
    }
  }
  JUMPOUT(0x7086E);
}
// 720B7: control flows out of bounds to 7086E
// 192248: using guessed type int16_t word_192248[500];
// 19306C: using guessed type int dword_19306C;
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;


//----- (000721EB) --------------------------------------------------------
int16_t sub_721EB()
{
  int v0; // eax

  word_19301A = word_199BB2;
  word_193018 = word_199BB0;
  if ( word_199BAC + word_199BB2 > 527 )
  {
    word_199BAC = 527 - word_199BB2;
    word_19301C = 527 - word_199BB2;
  }
  v0 = word_199BAE + word_199BB0;
  if ( v0 > 421 )
  {
    LOWORD(v0) = word_199BB0;
    word_199BAE = 421 - word_199BB0;
    word_19301E = 421 - word_199BB0;
  }
  return v0;
}
// 193018: using guessed type int16_t word_193018;
// 19301A: using guessed type int16_t word_19301A;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 199BAC: using guessed type int16_t word_199BAC;
// 199BAE: using guessed type int16_t word_199BAE;
// 199BB0: using guessed type int16_t word_199BB0;
// 199BB2: using guessed type int16_t word_199BB2;


//----- (0007226A) --------------------------------------------------------
void sub_7226A( int a1)
{
  int v2; // eax
  int16_t v3; // ax

  v2 = (a1 - 1) / 3 + 1;
  if ( v2 > 3 )
    LOWORD(v2) = 3;
  word_199962 = sub_71198(v2);
  sub_711E6(a1);
  word_193018 = v3;
}
// 72294: variable 'v3' is possibly undefined
// 193018: using guessed type int16_t word_193018;
// 199962: using guessed type int16_t word_199962;


//----- (0007229E) --------------------------------------------------------
void sub_7229E( int a1, int a2)
{
  int16_t i; // cx
  int v4; // edx
  int16_t v5; // di
  int16_t v6; // [esp+0h] [ebp-8h]

  for ( i = 0; ; ++i )
  {
    if ( i >= word_199BB8 )
    {
      byte_199F08 = a1;
      JUMPOUT(0x6FF02);
    }
    v4 = 5 * *(int16_t *)((char *)&word_197FC3 + 9 * i);
    v5 = *(int16_t *)((char *)&word_1975D4 + v4);
    v6 = *(int16_t *)((char *)&word_197FC3 + 9 * i);
    if ( sub_77FF5(v5) == word_19999C )
    {
      if ( !a1 )
      {
        byte_1975D8[v4] = 0;
        continue;
      }
      if ( a1 == 1 && a2 && sub_724CF(v5) )
        goto LABEL_12;
      if ( a1 == 1 && !a2 && sub_8A16A(v5) )
        break;
    }
LABEL_13:
    ;
  }
  v4 = 5 * v6;
LABEL_12:
  byte_1975D8[v4] = 1;
  goto LABEL_13;
}
// 72341: control flows out of bounds to 6FF02
// 1975D4: using guessed type int16_t word_1975D4;
// 197FC3: using guessed type int16_t word_197FC3;
// 19999C: using guessed type int16_t word_19999C;
// 199BB8: using guessed type int16_t word_199BB8;
// 199F08: using guessed type char byte_199F08;


//----- (00072346) --------------------------------------------------------
void sub_72346( int a1)
{
  int16_t v1; // cx
  int16_t v2; // bx
  int16_t v3; // si
  int16_t v4; // dx
  _BOOL1 v5; // al
  int16_t i; // si
  int v8; // ebx
  int16_t j; // bx
  int v10; // eax
  int16_t *v11; // eax
  char v13; // [esp+8h] [ebp-Ch]
  _BOOL1 v14; // [esp+Ch] [ebp-8h]
  char v15; // [esp+10h] [ebp-4h]

  if ( word_1999B8 != -1 )
  {
    v1 = word_192248[word_1999B8];
    v2 = *(int16_t *)((char *)&word_1975D4 + 5 * v1);
    v3 = sub_77FF5(v2);
    v4 = *(_WORD *)(129 * v2 + dword_197F9C + 101);
    v13 = 0;
    v5 = v4 > -1 && v4 < 500;
    v14 = v5;
    if ( v4 > 1000 && v4 < 1072 )
      v4 = sub_7A3E3(*(_WORD *)(129 * v2 + dword_197F9C + 103), *(_WORD *)(129 * v2 + dword_197F9C + 105));
    if ( v3 == word_19999C && v14 )
    {
      for ( i = 0; i < a1 && !v13 && v1 > -1; ++i )
      {
        v8 = *(int16_t *)((char *)&word_1975D4 + 5 * v1);
        sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * v1));
        if ( *(_BYTE *)(dword_197F9C + 129 * v8 + 17) == 2 )
        {
          v15 = 0;
          for ( j = 0; j < 5 && !v15; ++j )
          {
            v10 = *(int16_t *)(113 * v4 + dword_19306C + 2 * j + 74);
            if ( v10 != -1 )
            {
              v11 = (int16_t *)(17 * v10 + dword_1930D4);
              if ( *v11 != -1 && *(char *)(dword_192B18 + 361 * *v11) == word_19999C )
              {
                v15 = 1;
                v13 = 1;
              }
            }
          }
        }
        v1 = *(int16_t *)((char *)&word_1975D6 + 5 * v1);
      }
    }
  }
  JUMPOUT(0x7086E);
}
// 7235E: control flows out of bounds to 7086E
// 192248: using guessed type int16_t word_192248[500];
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;


//----- (000724CF) --------------------------------------------------------
_BOOL1 sub_724CF( int a1)
{
  return sub_8A16A(a1) && !byte_199F33;
}
// 199F33: using guessed type char byte_199F33;


//----- (000724E8) --------------------------------------------------------
int sub_724E8(int a1, int a2)
{
  int16_t v3; // ax
  int result; // eax
  int16_t v5; // dx

  *(_WORD *)(a1 + 10) = 3;
  *(_WORD *)(a1 + 14) = 102;
  *(_WORD *)(a1 + 12) = 0;
  *(_WORD *)(a1 + 8) = a2;
  v3 = sub_A00F1((_WORD *)a1);
  *(_WORD *)(a1 + 6) = v3;
  result = v3 / 2;
  *(_WORD *)(a1 + 2) = -1;
  *(_BYTE *)(a1 + 24) = 2;
  v5 = *(_WORD *)(a1 + 14);
  *(_BYTE *)(a1 + 26) = 1;
  dword_1975C4 = a1;
  *(_WORD *)a1 = v5 - result;
  return result;
}
// 1975C4: using guessed type int dword_1975C4;


//----- (0007252F) --------------------------------------------------------
char sub_7252F( int a1)
{
  int v2; // eax
  char v3; // bl
  int16_t i; // dx

  v2 = word_1999FE + word_1999FC;
  v3 = 0;
  if ( word_199BB8 <= v2 )
    LOWORD(v2) = word_199BB8;
  for ( i = word_1999FC; i < (int16_t)v2; ++i )
  {
    if ( a1 == *(int16_t *)((char *)&word_197FC1 + 9 * i) )
      return byte_1975D8[5 * *(int16_t *)((char *)&word_197FC3 + 9 * i)];
  }
  return v3;
}
// 197FC1: using guessed type int16_t word_197FC1;
// 197FC3: using guessed type int16_t word_197FC3;
// 1999FC: using guessed type int16_t word_1999FC;
// 1999FE: using guessed type int16_t word_1999FE;
// 199BB8: using guessed type int16_t word_199BB8;


//----- (00072590) --------------------------------------------------------
int sub_72590()
{
  int result; // eax

  if ( byte_199BC6 )
  {
    dword_1932AC = sub_127C27((int)aBuffer0Lbx_0, 56, dword_193174);
    dword_199BC2 = dword_1932AC;
    result = sub_127C27((int)aBuffer0Lbx_0, 52, dword_193174);
    dword_1932B0 = result;
  }
  else
  {
    dword_1932CC = sub_127C27((int)aBuffer0Lbx_0, 55, dword_193174);
    dword_199BC2 = dword_1932CC;
    result = sub_127C27((int)aBuffer0Lbx_0, 51, dword_193174);
    dword_193298 = result;
  }
  dword_199BBE = result;
  return result;
}
// 193174: using guessed type int dword_193174;
// 193298: using guessed type int dword_193298;
// 1932AC: using guessed type int dword_1932AC;
// 1932B0: using guessed type int dword_1932B0;
// 1932CC: using guessed type int dword_1932CC;
// 199BBE: using guessed type int dword_199BBE;
// 199BC2: using guessed type int dword_199BC2;
// 199BC6: using guessed type char byte_199BC6;


//----- (00072617) --------------------------------------------------------
_BOOL1 sub_72617()
{
  _BYTE v1[1000]; // [esp+0h] [ebp-3E8h] BYREF

  return sub_918D5(2) && (int16_t)sub_7802A((int)v1, 500) > 0;
}


//----- (00072651) --------------------------------------------------------
_BOOL1 sub_72651( int a1)
{
  return (uint16_t)sub_77FE9(*(int16_t *)((char *)&word_197FC3 + 9 * a1)) == (uint16_t)word_19999C;
}
// 197FC3: using guessed type int16_t word_197FC3;
// 19999C: using guessed type int16_t word_19999C;


//----- (0007267D) --------------------------------------------------------
int64_t sub_7267D(
        _WORD *a1,
        _WORD *a2,
        _WORD *a3,
        uint16_t *a4,
        _WORD *a5,
        _WORD *a6,
        uint16_t *a7,
        uint16_t *a8,
        _WORD *a9,
        int16_t *a10)
{
  uint16_t v12; // ax
  _WORD *v13; // ecx
  uint16_t v14; // ax
  _WORD *v15; // ecx
  int v16; // eax
  uint16_t v17; // ax
  uint16_t *v18; // edx
  int16_t v20; // [esp+8h] [ebp-14h] BYREF
  int v21; // [esp+Ch] [ebp-10h]
  int v22; // [esp+10h] [ebp-Ch]
  int v23; // [esp+14h] [ebp-8h]
  int v24; // [esp+18h] [ebp-4h]

  v24 = 605;
  v23 = 86;
  v21 = 14;
  v22 = 234;
  if ( word_199912 <= 0 || word_199932 != word_19999C || byte_19BED1 == 1 )
  {
    byte_199EF9 = 0;
    *a2 = -1000;
  }
  else
  {
    byte_199EF9 = 1;
    *a2 = (uint16_t)sub_1151B0(549, 380, (int)&unk_1792C8, (_WORD *)dword_192B20, aS_32, 40);
  }
  if ( word_19992E <= 0 || word_199932 != word_19999C || byte_19BED1 == 1 )
  {
    byte_199EFB = 0;
    *a9 = -1000;
  }
  else
  {
    byte_199EFB = 1;
    *a9 = (uint16_t)sub_1151B0(348, 380, (int)&unk_1792C8, (_WORD *)dword_192B48, &off_1792C9, 40);
  }
  *a3 = (uint16_t)sub_1151B0(556, 430, (int)&unk_1792C8, (_WORD *)dword_192B4C, (_BYTE *)&off_1792C9 + 2, 40);
  *a4 = -1000;
  *a5 = -1000;
  *a7 = -1000;
  *a6 = -1000;
  if ( word_19BECE > 0 )
  {
    if ( word_19992E > 20 )
    {
      v12 = (uint16_t)sub_1151B0(606, 59, (int)&unk_1792C8, (_WORD *)dword_192B5C, byte_1792CD, 40);
      v13 = (_WORD *)dword_192B34;
      *a4 = v12;
      *a5 = (uint16_t)sub_1151B0(605, 325, (int)&unk_1792C8, v13, byte_1792CF, 40);
    }
    v14 = (uint16_t)sub_1151B0(19, 249, (int)&unk_1792C8, (_WORD *)dword_192B64, byte_1792D1, 40);
    v15 = (_WORD *)dword_192B3C;
    *a7 = v14;
    *a6 = (uint16_t)sub_1151B0(283, 249, (int)&unk_1792C8, v15, byte_1792D3, 40);
  }
  v16 = dword_1975C4;
  *(_WORD *)(dword_1975C4 + 18) = *a5;
  *(_WORD *)(v16 + 16) = *a4;
  if ( byte_19BED1 == 2 )
  {
    byte_19BED1 = 2;
    *a1 = 0;
  }
  else
  {
    *a1 = sub_11438B(441, 380, *(_WORD *)dword_192B2C + 441, *(_WORD *)(dword_192B2C + 2) + 380, byte_1792D5, 41);
  }
  if ( sub_74F14() )
  {
    v17 = (uint16_t)sub_1151B0(342, 430, (int)&unk_1792C8, (_WORD *)dword_192B58, byte_1792D7, 40);
    v18 = a8;
    byte_199EF7 = 1;
  }
  else
  {
    v17 = sub_11438B(342, 430, *(_WORD *)dword_192B58 + 342, *(_WORD *)(dword_192B58 + 2) + 430, &unk_1792C8, 41);
    v18 = a8;
    byte_199EF7 = 0;
  }
  *v18 = v17;
  sub_755D2();
  if ( word_1999D8 > -1 )
  {
    sub_75B80(a10, v24, v23, v21, v22);
    *(_WORD *)(dword_1975C4 + 8) = (uint8_t)byte_199EFC;
  }
  sub_9023B(15, 52, 305, 182, 0, 0, 0, 0, 1, &v20, (int)word_190178, &word_19997A);
  word_19C18C = sub_11438B(0, 470, 10, 479, &unk_1792C8, 41);
  if ( word_19BECE <= 0 )
  {
    word_19BEC8 = -1000;
    word_19BECA = -1000;
  }
  else
  {
    word_19BEC8 = sub_11523B(425, 435, (int)&unk_1792C8, (_WORD *)dword_19BEC4, (int)&word_19990C, byte_1792D9, 41);
    word_19BECA = sub_11523B(487, 435, (int)&unk_1792C8, (_WORD *)dword_19BEC0, (int)&word_19990A, byte_1792DB, 41);
  }
  return sub_11438B(0, 0, 639, 479, &unk_1792C8, 0);
}
// 1792C9: using guessed type _UNKNOWN *off_1792C9;
// 1792CD: using guessed type _BYTE byte_1792CD[2];
// 1792CF: using guessed type _BYTE byte_1792CF[2];
// 1792D1: using guessed type _BYTE byte_1792D1[2];
// 1792D3: using guessed type _BYTE byte_1792D3[2];
// 1792D5: using guessed type _BYTE byte_1792D5[2];
// 1792D7: using guessed type _BYTE byte_1792D7[2];
// 1792D9: using guessed type _BYTE byte_1792D9[2];
// 1792DB: using guessed type _BYTE byte_1792DB[2];
// 190178: using guessed type int16_t word_190178[72];
// 192B20: using guessed type int dword_192B20;
// 192B2C: using guessed type int dword_192B2C;
// 192B34: using guessed type int dword_192B34;
// 192B3C: using guessed type int dword_192B3C;
// 192B48: using guessed type int dword_192B48;
// 192B4C: using guessed type int dword_192B4C;
// 192B58: using guessed type int dword_192B58;
// 192B5C: using guessed type int dword_192B5C;
// 192B64: using guessed type int dword_192B64;
// 1975C4: using guessed type int dword_1975C4;
// 19990A: using guessed type int16_t word_19990A;
// 19990C: using guessed type int16_t word_19990C;
// 199912: using guessed type int16_t word_199912;
// 19992E: using guessed type int16_t word_19992E;
// 199932: using guessed type int16_t word_199932;
// 19997A: using guessed type int16_t word_19997A;
// 19999C: using guessed type int16_t word_19999C;
// 1999D8: using guessed type int16_t word_1999D8;
// 199EF7: using guessed type char byte_199EF7;
// 199EF9: using guessed type char byte_199EF9;
// 199EFB: using guessed type char byte_199EFB;
// 199EFC: using guessed type char byte_199EFC;
// 19BEC0: using guessed type int dword_19BEC0;
// 19BEC4: using guessed type int dword_19BEC4;
// 19BEC8: using guessed type int16_t word_19BEC8;
// 19BECA: using guessed type int16_t word_19BECA;
// 19BECE: using guessed type int16_t word_19BECE;
// 19BED1: using guessed type char byte_19BED1;
// 19C18C: using guessed type int16_t word_19C18C;


//----- (00072A65) --------------------------------------------------------
int sub_72A65()
{
  dword_192B24 = (int)sub_110D3C(dword_192ED4, 3250);
  dword_192B68 = (int)sub_110D3C(dword_192ED4, 250);
  dword_192B6C = (int)sub_110D3C(dword_192ED4, 500);
  dword_193188 = (int)sub_110D3C(dword_192ED4, 134);
  dword_1975C4 = (int)sub_110D3C(dword_192ED4, 29);
  memset(dword_1975C4, 0, 29);
  return sub_111499(dword_192ED4);
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192B24: using guessed type int dword_192B24;
// 192B68: using guessed type int dword_192B68;
// 192B6C: using guessed type int dword_192B6C;
// 192ED4: using guessed type int dword_192ED4;
// 193188: using guessed type int dword_193188;
// 1975C4: using guessed type int dword_1975C4;


//----- (00072AE4) --------------------------------------------------------
int16_t sub_72AE4(int a1, _WORD *a2)
{
  int v2; // esi
  int16_t i; // bx

  v2 = a1;
  *a2 = 0;
  for ( i = 0; i < word_19992E; ++i )
  {
    a1 = dword_192B24 + 13 * i;
    if ( *(int16_t *)(a1 + 11) > -1 && *(int16_t *)(a1 + 11) < 500 && *(_BYTE *)(a1 + 4) )
    {
      LOWORD(a1) = *(_WORD *)(a1 + 11);
      *(_WORD *)(v2 + 2 * (int16_t)(*a2)++) = a1;
    }
  }
  return a1;
}
// 192B24: using guessed type int dword_192B24;
// 19992E: using guessed type int16_t word_19992E;


//----- (00072B33) --------------------------------------------------------
char sub_72B33(int a1, int a2, int a3)
{
  int16_t v4; // ax
  int16_t v5; // ax
  int16_t v6; // si
  int16_t v7; // bx
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  int16_t i; // di
  int v12; // ebx
  int v13; // eax
  int16_t v14; // di
  int v15; // eax
  unsigned int v16; // eax
  int v17; // ebx
  int v18; // eax
  int16_t v19; // dx
  int16_t j; // dx
  int v21; // ebx
  int v22; // edi
  int16_t v23; // ax
  int v24; // ebx
  char *v25; // edi
  char *v26; // edi
  char *v27; // esi
  char *v28; // edi
  char *v29; // edi
  int16_t *v31; // [esp-4h] [ebp-2BEh] BYREF
  _BYTE v32[500]; // [esp+0h] [ebp-2BAh] BYREF
  char v33[200]; // [esp+1F4h] [ebp-C6h] BYREF
  _WORD v34[26]; // [esp+2BCh] [ebp+2h] BYREF
  _WORD v35[26]; // [esp+2F0h] [ebp+36h] BYREF
  int v36; // [esp+324h] [ebp+6Ah]
  int v37; // [esp+328h] [ebp+6Eh]
  int v38; // [esp+32Ch] [ebp+72h]
  unsigned int v39; // [esp+330h] [ebp+76h]
  int k; // [esp+334h] [ebp+7Ah]
  char v41; // [esp+338h] [ebp+7Eh]

  v38 = a2;
  v41 = a3;
  memset(v34, -1, 50);
  memset(v35, 0, 50);
  v4 = *(char *)(a1 + 99);
  v37 = 0;
  sub_5709F(v4);
  v6 = 0;
  if ( v5 > -1 && v5 < 6 )
  {
    v7 = word_17FFE8[5 * v5];
    if ( !sub_78457(v7, v38) )
    {
      v6 = 1;
      v34[0] = v7;
    }
  }
  if ( !sub_78457(word_17FE76[23 * *(uint8_t *)(a1 + 19)], v38) )
  {
    v8 = v6++;
    v34[v8] = word_17FE76[23 * *(uint8_t *)(a1 + 19)];
  }
  if ( !sub_78457(word_17FDF2[11 * *(uint8_t *)(a1 + 21)], v38) )
  {
    v9 = v6++;
    v34[v9] = word_17FDF2[11 * *(uint8_t *)(a1 + 21)];
  }
  if ( !sub_78457(*(int16_t *)((char *)&word_17F63E + 15 * *(uint8_t *)(a1 + 22)), v38) )
  {
    v10 = v6++;
    v34[v10] = *(int16_t *)((char *)&word_17F63E + 15 * *(uint8_t *)(a1 + 22));
  }
  for ( i = 0; i < 8; ++i )
  {
    v12 = a1 + 8 * i;
    if ( *(int16_t *)(v12 + 28) > 0 && !sub_78457(word_17F80D[14 * *(int16_t *)(v12 + 28)], v38) )
    {
      v13 = v6++;
      v34[v13] = word_17F80D[14 * *(int16_t *)(v12 + 28)];
    }
  }
  v14 = 1;
  v36 = a1 + 23;
  do
  {
    LOWORD(v15) = sub_1276F0(v36, v14);
    if ( (_WORD)v15 )
    {
      LOBYTE(v15) = sub_78457(*(int16_t *)((char *)&word_17EEE6 + 47 * v14), v38);
      if ( !(_BYTE)v15 )
      {
        v15 = v6++;
        v34[v15] = *(int16_t *)((char *)&word_17EEE6 + 47 * v14);
      }
    }
    ++v14;
  }
  while ( v14 < 39 );
  if ( v6 > 0 )
  {
    sub_8F6DF(0x74u, v33);
    sprintf(v32, v33, a1);
    v16 = sub_1247A0(v6);
    v39 = v16 - 1;
    v17 = (int16_t)(v16 - 1);
    v18 = (int16_t)v37;
    v19 = v34[v17];
    ++v37;
    v35[v18] = v19;
    for ( j = 0; j < v6; ++j )
    {
      if ( j != (_WORD)v39 )
      {
        v21 = (int16_t)v37;
        v22 = 25 - 5 * ((int16_t)v37 - 1);
        if ( (int)(sub_1247A0(0x64u) - 1) < v22 )
        {
          v23 = v34[j];
          ++v37;
          v35[v21] = v23;
        }
      }
    }
    for ( k = 0; (int16_t)k < (int16_t)v37; ++k )
    {
      if ( v35[(int16_t)k] )
      {
        v24 = 13 * (int16_t)v35[(int16_t)k];
        sub_E4204(dword_197F98 + 3753 * (int16_t)v38, v35[(int16_t)k], (int)v32);
        v31 = (int16_t *)v32;
        v25 = (char *)&v31 + 3;
        do
          ++v25;
        while ( *v25 );
        strcpy(v25, byte_1792DD);
        v31 = (int16_t *)v32;
        v26 = (char *)&v31 + 3;
        do
          ++v26;
        while ( *v26 );
        strcpy(v26, "^ ");
        v27 = *(char **)((char *)&off_17E079 + v24);
        v31 = (int16_t *)v32;
        v28 = (char *)&v31 + 3;
        do
          ++v28;
        while ( *v28 );
        strcpy(v28, v27);
        v31 = (int16_t *)v32;
        v29 = (char *)&v31 + 3;
        do
          ++v29;
        while ( *v29 );
        strcpy(v29, "\n");
      }
    }
    v31 = &word_18FF78;
    strcpy((char *)&word_18FF78, (char *)a1);
    if ( v41 )
      LOBYTE(v15) = sub_7A25F(&byte_199EFE, (int)v32, 2);
  }
  return v15;
}
// 72B79: variable 'v5' is possibly undefined
// 72E56: variable 'v15' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17F63E: using guessed type int16_t word_17F63E;
// 17F80D: using guessed type int16_t word_17F80D[];
// 17FDF2: using guessed type int16_t word_17FDF2[];
// 17FE76: using guessed type int16_t word_17FE76[];
// 17FFE8: using guessed type int16_t word_17FFE8[];
// 18FF78: using guessed type int16_t word_18FF78;
// 197F98: using guessed type int dword_197F98;
// 199EFE: using guessed type char byte_199EFE;


//----- (00072E61) --------------------------------------------------------
int sub_72E61()
{
  int v0; // ebx
  int16_t i; // dx
  int v2; // ecx

  v0 = 0;
  for ( i = 0; i < word_19992E; ++i )
  {
    v2 = 13 * i;
    if ( *(_BYTE *)(v2 + dword_192B24 + 4) )
      v0 += sub_EDDD8(dword_197F9C + 129 * *(int16_t *)(v2 + dword_192B24 + 11));
  }
  return v0;
}
// 192B24: using guessed type int dword_192B24;
// 197F9C: using guessed type int dword_197F9C;
// 19992E: using guessed type int16_t word_19992E;


//----- (00072EA6) --------------------------------------------------------
int sub_72EA6(int a1)
{
  int16_t v2; // ax
  int result; // eax
  int16_t v4; // dx

  *(_WORD *)(a1 + 10) = 5;
  *(_WORD *)(a1 + 14) = 234;
  v2 = sub_A00F1((_WORD *)a1);
  *(_WORD *)(a1 + 6) = v2;
  result = v2 / 2;
  *(_WORD *)(a1 + 2) = -1;
  *(_BYTE *)(a1 + 24) = 0;
  v4 = *(_WORD *)(a1 + 14);
  *(_BYTE *)(a1 + 26) = 1;
  *(_WORD *)a1 = v4 - result;
  return result;
}


//----- (00072EDF) --------------------------------------------------------
int sub_72EDF(int a1)
{
  char *v1; // eax
  int64_t v2; // rax
  int result; // eax
  _BYTE v5[80]; // [esp+0h] [ebp-50h] BYREF

  v1 = sub_7A990(0x75u);
  v2 = sprintf(v5, v1, a1);
  result = sub_7A25F(&byte_199EFE, SHIDWORD(v2), 0);
  word_19BECC = -1;
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 199EFE: using guessed type char byte_199EFE;
// 19BECC: using guessed type int16_t word_19BECC;


//----- (00072F19) --------------------------------------------------------
int sub_72F19()
{
  int16_t v0; // dx
  int16_t v1; // ax
  int v2; // ebx
  int result; // eax

  v0 = word_192248[word_1999D8];
  v1 = sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * v0));
  if ( v1 >= 8 )
    v2 = dword_192B70[(int16_t)(v1 - 8)];
  else
    v2 = dword_18F948[*(uint8_t *)(3753 * v1 + dword_197F98 + 38)];
  result = (int16_t)sub_74F51(v0);
  if ( (int16_t)result != -1 )
    return sub_12A478(word_1906C8[6 * (int16_t)result], word_1906CA[6 * (int16_t)result], v2);
  return result;
}
// 18F948: using guessed type int dword_18F948[8];
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 192248: using guessed type int16_t word_192248[500];
// 192B70: using guessed type int dword_192B70[7];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F98: using guessed type int dword_197F98;
// 1999D8: using guessed type int16_t word_1999D8;


//----- (00072F92) --------------------------------------------------------
int sub_72F92( int a1)
{
  void (*v1)(); // edx
  int v2; // ebx
  int16_t v3; // cx
  int v4; // eax
  char v5; // cl
  int v6; // ebx
  int result; // eax
  char v8; // [esp+4h] [ebp-4h]

  if ( byte_199EFE || word_19994C )
  {
    sub_128BE7();
    sub_128C32(0, 0, 639, 479, 0);
    sub_12A478(0, 0, dword_192B1C);
    sub_737A2();
    sub_124DEC();
    if ( byte_199EFE )
      byte_199EFE = 0;
    if ( word_19994C )
      word_19994C = 0;
  }
  if ( word_199960 > -1 )
    sub_761A5();
  if ( word_19991C > -1 && word_19991C < 250 && word_199A08 == 4 )
  {
    sub_128AB6(15, 282, 320, 465);
    sub_12B634();
    sub_7670E(*(_WORD *)(dword_192B24 + 13 * word_19991C + 11));
    sub_12B65C();
    sub_128BE7();
  }
  sub_7527A(4);
  sub_734F1(4);
  v1 = 0;
  sub_90C4F(52, 15, a1, 305, 182, 0, 0, 0, 0, 1, -1);
  if ( byte_19BED1 != 1 && sub_124075() == 1 )
  {
    v8 = 0;
    v2 = 0;
    LOWORD(v1) = *(_WORD *)(dword_1975C4 + 12) * (uint8_t)byte_199F14;
    while ( (int16_t)v1 < word_19992E && !v8 )
    {
      v3 = sub_113F8C();
      v4 = 13 * (int16_t)v1 + dword_192B24;
      a1 = (int16_t)v1;
      if ( v3 == *(_WORD *)(v4 + 9) )
      {
        if ( byte_19C195 == -1 )
          byte_19C195 = *(_BYTE *)(v4 + 4) == 0;
        v5 = byte_19C195;
        *(_BYTE *)(13 * (int16_t)v1 + dword_192B24 + 4) = byte_19C195;
        if ( !v5 )
          byte_199F28 = 1;
        sub_734A9((int16_t)v1);
      }
      if ( (int16_t)++v2 >= (uint8_t)byte_199F14 * (uint8_t)byte_199F10 )
        v8 = 1;
      v1 = (void (*)())((char *)v1 + 1);
    }
  }
  if ( word_19990E > -1 )
    sub_957E3(word_19990E);
  if ( word_1999D8 > -1 )
    sub_72F19();
  if ( word_19992E > 0 )
  {
    v1 = sub_73873;
    if ( sub_A0226((int16_t *)dword_1975C4, (void (*)(_DWORD))sub_73873) )
      word_19991C = -1;
  }
  if ( word_199932 <= -1 || byte_199EFA || word_1999D8 <= -1 )
    byte_199EFA = 0;
  else
    sub_732D6(4, (int)v1, a1);
  if ( byte_19BED1 == 2 )
  {
    v6 = dword_192B30;
  }
  else
  {
    if ( byte_19BED1 )
      sub_12B753(dword_192B2C, 1);
    else
      sub_12B726(dword_192B2C);
    v6 = dword_192B2C;
  }
  sub_12A478(441, 380, v6);
  if ( !byte_199EF9 )
    sub_12A478(549, 380, dword_192B40);
  if ( !byte_199EFB )
    sub_12A478(348, 380, dword_192B50);
  if ( !byte_199EF7 )
    sub_12A478(342, 430, dword_192B38);
  result = (word_19995E + 1) / 8;
  word_19995E = (word_19995E + 1) % 8;
  return result;
}
// 192B1C: using guessed type int dword_192B1C;
// 192B24: using guessed type int dword_192B24;
// 192B2C: using guessed type int dword_192B2C;
// 192B30: using guessed type int dword_192B30;
// 192B38: using guessed type int dword_192B38;
// 192B40: using guessed type int dword_192B40;
// 192B50: using guessed type int dword_192B50;
// 1975C4: using guessed type int dword_1975C4;
// 19990E: using guessed type int16_t word_19990E;
// 19991C: using guessed type int16_t word_19991C;
// 19992E: using guessed type int16_t word_19992E;
// 199932: using guessed type int16_t word_199932;
// 19994C: using guessed type int16_t word_19994C;
// 19995E: using guessed type int16_t word_19995E;
// 199960: using guessed type int16_t word_199960;
// 1999D8: using guessed type int16_t word_1999D8;
// 199A08: using guessed type int16_t word_199A08;
// 199EF7: using guessed type char byte_199EF7;
// 199EF9: using guessed type char byte_199EF9;
// 199EFA: using guessed type char byte_199EFA;
// 199EFB: using guessed type char byte_199EFB;
// 199EFE: using guessed type char byte_199EFE;
// 199F10: using guessed type char byte_199F10;
// 199F14: using guessed type char byte_199F14;
// 199F28: using guessed type char byte_199F28;
// 19BED1: using guessed type char byte_19BED1;
// 19C195: using guessed type char byte_19C195;


//----- (000732D6) --------------------------------------------------------
int sub_732D6( int a1, int a2, int a3)
{
  int16_t v3; // di
  int result; // eax
  int i; // esi
  _WORD *v6; // eax
  int16_t v7; // dx
  int16_t v8; // ax
  int16_t v9; // dx
  int16_t v10; // ax
  int v11; // ecx
  int v12; // eax
  int v13; // [esp+0h] [ebp-30h]
  int v14; // [esp+8h] [ebp-28h] BYREF
  _WORD *v15; // [esp+Ch] [ebp-24h]
  int v16; // [esp+10h] [ebp-20h]
  int v17; // [esp+14h] [ebp-1Ch]
  int v18; // [esp+18h] [ebp-18h]
  int v19; // [esp+1Ch] [ebp-14h]
  int v20; // [esp+20h] [ebp-10h]
  int v21; // [esp+24h] [ebp-Ch]
  int v22; // [esp+28h] [ebp-8h] BYREF
  char v23; // [esp+2Ch] [ebp-4h]

  v23 = 0;
  v3 = 0;
  if ( a1 == 29 )
  {
    v18 = 57;
    v17 = 57;
    v20 = 3;
  }
  else
  {
    v18 = 56;
    v17 = 57;
    v20 = 1;
  }
  result = dword_1975C4;
  LOWORD(a2) = (uint8_t)byte_199F14;
  LOWORD(a3) = *(_WORD *)(dword_1975C4 + 12);
  for ( i = a2 * a3; (int16_t)i < word_19992E && !v23; ++i )
  {
    v13 = 13 * (int16_t)i;
    v6 = (_WORD *)sub_58678(*(_WORD *)(v13 + dword_192B24 + 11));
    v7 = *v6;
    LOWORD(v6) = v6[1];
    v15 = v6;
    sub_76028(v3, &v14, &v22);
    v21 = (57 - v7) / 2;
    v16 = (57 - (int16_t)v15) / 2;
    v8 = *(_WORD *)(v13 + dword_192B24 + 11);
    v19 = i;
    sub_77FF5(v8);
    if ( (_WORD)i == word_19991C && word_199A08 == 4 )
      sub_734A9(i);
    if ( *(_BYTE *)(dword_192B24 + 13 * (int16_t)v19 + 4) )
    {
      if ( word_199A08 == 4 )
      {
        v9 = v22 + 1;
        v10 = v14 - 2;
      }
      else
      {
        v9 = v22 - 1;
        v10 = v14 - 1;
      }
      sub_12A478(v10, v9, dword_192B28);
    }
    v11 = 13 * (int16_t)v19;
    v12 = sub_58678(*(_WORD *)(v11 + dword_192B24 + 11));
    sub_12A478(v21 + v14 + 1, v16 + v22 + 2, v12);
    if ( sub_78182(*(_WORD *)(v11 + dword_192B24 + 11)) )
      sub_702EA(v14, (int16_t)v22, (int16_t)v18, (int16_t)v17, v20, *(_WORD *)(v11 + dword_192B24 + 11));
    result = (uint8_t)byte_199F10 * (uint8_t)byte_199F14;
    if ( ++v3 >= result )
      v23 = 1;
  }
  return result;
}
// 192B24: using guessed type int dword_192B24;
// 192B28: using guessed type int dword_192B28;
// 1975C4: using guessed type int dword_1975C4;
// 19991C: using guessed type int16_t word_19991C;
// 19992E: using guessed type int16_t word_19992E;
// 199A08: using guessed type int16_t word_199A08;
// 199F10: using guessed type char byte_199F10;
// 199F14: using guessed type char byte_199F14;


//----- (000734A9) --------------------------------------------------------
int sub_734A9( int a1)
{
  int v1; // eax
  int16_t v2; // dx
  int16_t v3; // ax
  int16_t v4; // ax
  int16_t v5; // dx

  v1 = 13 * a1;
  v2 = *(_WORD *)(dword_192B24 + v1 + 5);
  v3 = *(_WORD *)(dword_192B24 + v1 + 7);
  if ( word_199A08 == 4 )
  {
    v4 = v3 - 1;
    v5 = v2 - 3;
  }
  else
  {
    v4 = v3 - 2;
    v5 = v2 - 2;
  }
  return sub_12A478(v5, v4, dword_192B44);
}
// 192B24: using guessed type int dword_192B24;
// 192B44: using guessed type int dword_192B44;
// 199A08: using guessed type int16_t word_199A08;


//----- (000734F1) --------------------------------------------------------
void sub_734F1( int a1)
{
  _BOOL1 v1; // dl
  _BYTE *v2; // esi
  int v3; // eax
  int v4; // edx
  char v5; // bl
  int16_t v6; // cx
  int v7; // edx
  _BYTE *v8; // esi
  _BYTE v9[8]; // [esp+0h] [ebp-44h] BYREF
  _BYTE v10[8]; // [esp+8h] [ebp-3Ch] BYREF
  _BYTE v11[8]; // [esp+10h] [ebp-34h] BYREF
  int v12; // [esp+18h] [ebp-2Ch]
  int v13; // [esp+1Ch] [ebp-28h] BYREF
  int v14; // [esp+20h] [ebp-24h] BYREF
  int v15; // [esp+24h] [ebp-20h]
  int i; // [esp+28h] [ebp-1Ch]
  int v17; // [esp+2Ch] [ebp-18h]
  int16_t v18; // [esp+30h] [ebp-14h] BYREF
  int v19; // [esp+34h] [ebp-10h]
  int v20; // [esp+38h] [ebp-Ch]
  int v21; // [esp+3Ch] [ebp-8h]
  int v22; // [esp+40h] [ebp-4h]

  v17 = 0;
  v12 = -1;
  qmemcpy(v9, &unk_182135, sizeof(v9));
  v1 = 0;
  qmemcpy(v11, &unk_18213D, sizeof(v11));
  if ( a1 == 4 )
  {
    if ( word_1999D8 > -1 && (int16_t)sub_74ED8() != -1 && word_199960 > -1 && word_199960 < word_19999A )
    {
      v12 = sub_74F51(word_192248[word_1999D8]);
      v1 = (int16_t)v12 > -1;
    }
    v20 = 15;
    v21 = 52;
    v19 = 305;
    v22 = 182;
  }
  else
  {
    v20 = 306;
    v21 = 235;
    v19 = 318;
    v22 = 169;
  }
  if ( v1 )
  {
    if ( !byte_1992AD || *(_BYTE *)(dword_19306C + 113 * word_199960 + 22) == 6 )
      v2 = v11;
    else
      v2 = v9;
    qmemcpy(v10, v2, sizeof(v10));
    sub_911D5(word_199960, v20, v21, v19, v22, 0, 0, 1, &v14, &v13);
    sub_A1299(v14 + 3, v13 + 3, word_1906C8[6 * (int16_t)v12], v17 + word_1906CA[6 * (int16_t)v12], (int)v10);
  }
  for ( i = 0; ; ++i )
  {
    if ( (int16_t)i >= word_1999F8 )
      JUMPOUT(0x734A2);
    LOWORD(v3) = sub_78889(i);
    v4 = (int16_t)v3;
    v15 = v3;
    v5 = 0;
    v6 = sub_77FF5(v3);
    if ( v6 != word_19999C
      || (v7 = 129 * v4, (uint16_t)sub_78E07(*(int16_t *)(v7 + dword_197F9C + 101)) == word_19999A)
      || *(int16_t *)(v7 + dword_197F9C + 101) < 500
      || *(int16_t *)(v7 + dword_197F9C + 101) >= 1500 )
    {
      if ( v6 == word_19999C || !sub_A1341(word_1906C2[6 * (int16_t)i]) )
        goto LABEL_25;
      v8 = v11;
    }
    else
    {
      v8 = v9;
    }
    v5 = 1;
    qmemcpy(v10, v8, sizeof(v10));
LABEL_25:
    if ( v5 )
    {
      sub_78E2D(*(_WORD *)(dword_197F9C + 129 * (int16_t)v15 + 101), &v18);
      sub_911D5(v18, v20, v21, v19, v22, 0, 0, 1, &v14, &v13);
      sub_A1299(v14 + 3, v17 + v13 + 3, word_1906C8[6 * (int16_t)i], v17 + word_1906CA[6 * (int16_t)i], (int)v10);
    }
  }
}
// 7379D: control flows out of bounds to 734A2
// 7367B: variable 'v3' is possibly undefined
// 1906C2: using guessed type int16_t word_1906C2[];
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 192248: using guessed type int16_t word_192248[500];
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 1992AD: using guessed type char byte_1992AD;
// 199960: using guessed type int16_t word_199960;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1999D8: using guessed type int16_t word_1999D8;
// 1999F8: using guessed type int16_t word_1999F8;


//----- (000737A2) --------------------------------------------------------
void sub_737A2()
{
  int16_t v0; // cx
  int16_t v1; // ax
  int v2; // eax
  int16_t v3; // si
  int v4; // ebx
  int16_t v5; // ax
  int16_t v6; // dx
  int v7; // ebx

  v0 = word_1999F8;
  while ( --v0 > -1 )
  {
    v1 = sub_77FE9(word_1906C2[6 * v0]);
    if ( v1 >= 8 )
    {
      v7 = *(char *)(dword_197F9C + 129 * *(int16_t *)((char *)&word_1975D4 + 5 * word_1906C2[6 * v0]) + 99) - 8;
      sub_12B726(dword_192B8C[v7]);
      v4 = dword_192B8C[v7];
      v6 = word_1906CA[6 * v0];
      v5 = word_1906C8[6 * v0];
    }
    else
    {
      v2 = 3753 * v1;
      v3 = *(uint8_t *)(dword_197F98 + v2 + 38);
      sub_12B726(dword_18F928[*(uint8_t *)(dword_197F98 + v2 + 38)]);
      v4 = dword_18F928[v3];
      v5 = word_1906C8[6 * v0];
      v6 = word_1906CA[6 * v0];
    }
    sub_12A478(v5, v6, v4);
  }
}
// 18F928: using guessed type int dword_18F928[8];
// 1906C2: using guessed type int16_t word_1906C2[];
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 192B8C: using guessed type int dword_192B8C[15];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 1999F8: using guessed type int16_t word_1999F8;


//----- (00073873) --------------------------------------------------------
void sub_73873()
{
  int16_t v0; // si
  int v1; // edi
  int v2; // ecx
  int16_t v3; // dx
  int v4; // edi
  int16_t v5; // ax
  int16_t v6; // di
  int16_t v7; // [esp+0h] [ebp-20h]
  int16_t v8; // [esp+4h] [ebp-1Ch]
  int16_t v9; // [esp+8h] [ebp-18h]
  int16_t v10; // [esp+Ch] [ebp-14h]
  int16_t v11; // [esp+14h] [ebp-Ch]
  int16_t v12; // [esp+18h] [ebp-8h]
  int16_t v13; // [esp+1Ch] [ebp-4h]

  v10 = *(_WORD *)(dword_1975C4 + 6);
  if ( word_199A08 == 4 )
  {
    v0 = 606;
    v1 = 86;
    v13 = 12;
    v12 = 166;
    v8 = 605;
  }
  else
  {
    v0 = 613;
    v1 = 45;
    v13 = 10;
    v12 = 175;
    v8 = 612;
  }
  v9 = v1;
  v2 = (int16_t)(v1 + *(_WORD *)(dword_1975C4 + 14));
  v3 = v1;
  v4 = *(int16_t *)(dword_1975C4 + 14) - (*(int16_t *)dword_1975C4 + *(int16_t *)(dword_1975C4 + 6) / 2) + v1;
  sub_128AB6(v0, v3, v0 + v13, v2);
  sub_12B634();
  v11 = 0;
  v5 = v4 + 1;
  v6 = v10 + v4;
  v7 = v5;
  while ( v11 < v13 )
  {
    sub_134D2D(v0, v7, v0, v6, v12);
    if ( !(v11 % 2) )
      --v12;
    ++v11;
    ++v0;
  }
  sub_12B65C();
  sub_128BE7();
  sub_12A478(v8, v9, dword_192B60);
  JUMPOUT(0x734A2);
}
// 7397B: control flows out of bounds to 734A2
// 192B60: using guessed type int dword_192B60;
// 1975C4: using guessed type int dword_1975C4;
// 199A08: using guessed type int16_t word_199A08;


//----- (00073980) --------------------------------------------------------
void sub_73980(int a1, int16_t *a2, char *a3)
{
  int v3; // eax
  int v4; // ebx
  int16_t v5; // ax
  int v6; // edx
  int v7; // edx
  int16_t v8; // ax
  int v9; // ebx
  int v10; // eax
  int64_t v11; // rax
  int16_t v12; // bx
  int16_t v13; // dx
  void *v14; // eax
  _BYTE *v15; // edi
  char v16; // al
  int16_t v17; // ax
  int16_t v18; // ax
  char *v19; // eax
  char *v20; // eax
  int16_t v21; // ax
  int16_t v22; // bx
  char *v23; // eax
  int v24; // edx
  int v25; // ebx
  int16_t v26; // ax
  int16_t v27; // ax
  _BYTE *v28; // edi
  char v29; // al
  _BOOL1 v30; // zf
  int v31; // eax
  _BOOL1 v32; // zf
  int16_t v33; // ax
  int v34; // eax
  int16_t v35; // ax
  int v36; // edx
  int16_t v37; // ax
  int v38; // eax
  int v39; // [esp-4h] [ebp-646h]
  int v40; // [esp-4h] [ebp-646h]
  int v41; // [esp+0h] [ebp-642h] BYREF
  int v42; // [esp+4h] [ebp-63Eh]
  int v43; // [esp+8h] [ebp-63Ah]
  int v44; // [esp+Ch] [ebp-636h]
  int v45; // [esp+10h] [ebp-632h]
  int v46; // [esp+14h] [ebp-62Eh]
  int v47; // [esp+18h] [ebp-62Ah]
  int v48; // [esp+1Ch] [ebp-626h]
  int v49; // [esp+20h] [ebp-622h]
  int v50; // [esp+24h] [ebp-61Eh]
  int v51; // [esp+28h] [ebp-61Ah]
  int v52; // [esp+2Ch] [ebp-616h]
  int v53; // [esp+30h] [ebp-612h]
  int v54; // [esp+34h] [ebp-60Eh]
  int v55; // [esp+38h] [ebp-60Ah]
  int v56; // [esp+3Ch] [ebp-606h]
  int v57; // [esp+40h] [ebp-602h]
  int v58; // [esp+44h] [ebp-5FEh]
  int v59; // [esp+48h] [ebp-5FAh]
  int v60; // [esp+4Ch] [ebp-5F6h]
  int v61; // [esp+50h] [ebp-5F2h]
  int v62; // [esp+54h] [ebp-5EEh]
  int v63; // [esp+58h] [ebp-5EAh]
  int v64; // [esp+5Ch] [ebp-5E6h]
  int v65; // [esp+60h] [ebp-5E2h]
  int64_t v66; // [esp+64h] [ebp-5DEh]
  int v67; // [esp+6Ch] [ebp-5D6h]
  _BYTE v68[200]; // [esp+3E8h] [ebp-25Ah] BYREF
  _BYTE v69[200]; // [esp+4B0h] [ebp-192h] BYREF
  _BYTE v70[80]; // [esp+578h] [ebp-CAh] BYREF
  _BYTE v71[80]; // [esp+5C8h] [ebp-7Ah] BYREF
  _BYTE v72[80]; // [esp+618h] [ebp-2Ah] BYREF
  int16_t v73; // [esp+668h] [ebp+26h] BYREF
  int v74; // [esp+66Ch] [ebp+2Ah] BYREF
  uint16_t v75; // [esp+670h] [ebp+2Eh] BYREF
  int v76; // [esp+674h] [ebp+32h] BYREF
  int v77; // [esp+678h] [ebp+36h] BYREF
  int16_t v78; // [esp+67Ch] [ebp+3Ah] BYREF
  int v79; // [esp+680h] [ebp+3Eh] BYREF
  int16_t v80; // [esp+684h] [ebp+42h] BYREF
  int16_t v81; // [esp+688h] [ebp+46h] BYREF
  int16_t v82; // [esp+68Ch] [ebp+4Ah] BYREF
  int v83; // [esp+690h] [ebp+4Eh]
  int16_t v84; // [esp+694h] [ebp+52h] BYREF
  int16_t v85; // [esp+698h] [ebp+56h] BYREF
  int16_t v86; // [esp+69Ch] [ebp+5Ah] BYREF
  uint16_t v87; // [esp+6A0h] [ebp+5Eh] BYREF
  int16_t v88; // [esp+6A4h] [ebp+62h] BYREF
  int v89; // [esp+6A8h] [ebp+66h]
  char *v90; // [esp+6ACh] [ebp+6Ah]
  int v91; // [esp+6B0h] [ebp+6Eh]
  int16_t v92; // [esp+6B4h] [ebp+72h] BYREF
  uint16_t v93; // [esp+6B8h] [ebp+76h] BYREF
  char v94; // [esp+6BCh] [ebp+7Ah]
  char v95; // [esp+6C0h] [ebp+7Eh]

  v77 = -1;
  v74 = -1;
  LOWORD(a1) = word_199992;
  v89 = a1;
  sub_A20CD();
  dword_1975C4 = 0;
  word_1999A4 = 347;
  word_1999A8 = 53;
  byte_199F14 = 4;
  byte_199F10 = 5;
  byte_199F0E = 20;
  byte_19BED1 = 0;
  sub_7464A();
  sub_1191CA((int)sub_72F92, 1);
  byte_199F13 = 0;
  word_1999F2 = -1;
  word_1999F4 = -1;
  byte_182ACE = 0;
  word_19992C = 0;
  word_19992E = 0;
  byte_199EFC = 0;
  word_199912 = 0;
  word_19990E = -1;
  word_19991C = -1;
  byte_199F29 = 0;
  word_19BECE = sub_79B73(word_19999C);
  v3 = sub_77048(
         v41,
         v42,
         v43,
         v44,
         v45,
         v46,
         v47,
         v48,
         v49,
         v50,
         v51,
         v52,
         v53,
         v54,
         v55,
         v56,
         v57,
         v58,
         v59,
         v60,
         v61,
         v62,
         v63,
         v64,
         v65,
         v66,
         v67);
  sub_772BF(v3, 52, 305, 182);
  word_1999BE = -1;
  byte_199F09 = 0;
  byte_199EFA = 1;
  word_19BECC = -1;
  sub_11C2F0();
  v94 = 0;
  v83 = 0;
  v95 = 0;
  sub_7267D(&v86, &v92, &v82, &v93, &v81, &v80, &v75, &v87, &v88, &v85);
  v4 = dword_1975C4;
  *(_WORD *)(dword_1975C4 + 10) = 5;
  *(_WORD *)(v4 + 14) = 234;
  v5 = sub_A00F1((_WORD *)v4);
  *(_WORD *)(v4 + 6) = v5;
  *(_WORD *)(v4 + 2) = -1;
  *(_BYTE *)(v4 + 24) = 0;
  v6 = *(int16_t *)(v4 + 14);
  *(_BYTE *)(v4 + 26) = 1;
  v7 = v6 - v5 / 2;
  v8 = word_19992C;
  *(_WORD *)v4 = v7;
  sub_6F88F(v8);
  sub_1172D4();
  byte_199F05 = 2;
  v9 = 255;
  sub_124C08();
  byte_199EFE = 1;
  sub_123E6C((int)&unk_17CF4A, 1);
  sub_C5BB9();
  sub_1205E6(8, 0, 255);
  sub_1318D4(0, 255);
  if ( word_19BECE > 0 )
    sub_585E0(
      *(char *)(129 * *(int16_t *)(dword_192B24 + 11) + dword_197F9C + 99),
      129 * *(int16_t *)(dword_192B24 + 11));
  sub_132C80(100);
  sub_124D41();
  sub_72F92((int16_t)a3);
  if ( word_19BECE > 0 )
  {
    sub_12B753(dword_19BEC4, 1);
    sub_12A478(425, 435, dword_19BEC4);
    sub_12B753(dword_19BEC0, 1);
    v9 = dword_19BEC0;
    sub_12A478(487, 435, dword_19BEC0);
  }
  v10 = sub_131922(0, 255);
  sub_1077D(v10, 255, v9, a2);
  sub_123E6C((int)&unk_17CF00, 1);
  sub_C5C44();
  sub_1172FC();
  while ( 1 )
  {
    if ( (_WORD)v83 )
    {
      if ( sub_918D5(2) )
      {
        word_1999B8 = word_1999D8;
        if ( word_1999D8 == -1 )
        {
          sub_77BF1();
          sub_91A40();
        }
      }
      sub_123E6C((int)&unk_17CF00, 1);
      byte_199F38 = 0;
      word_199992 = v89;
      JUMPOUT(0x734A3);
    }
    byte_19C195 = -1;
    sub_11C2F0();
    v11 = sub_7267D(&v86, &v92, &v82, &v93, &v81, &v80, &v75, &v87, &v88, &v85);
    sub_12C2A0();
    byte_199F1E = 0;
    LODWORD(v11) = sub_1171AB(v11, SHIDWORD(v11), (int)&v82, (int)&v93);
    v12 = v11;
    v91 = v11;
    v90 = sub_114177();
    if ( v12 < 0 && byte_19BED1 == 1 )
      break;
    if ( (int16_t)v91 != -1105 )
    {
      if ( (int16_t)v91 != -1005 )
        goto LABEL_19;
      if ( byte_19BED0 )
      {
        byte_19BED1 = 0;
        v13 = 1;
        v14 = &unk_17CF00;
        byte_19BED0 = 0;
      }
      else
      {
        byte_19BED1 = 2;
        v13 = 4;
        v14 = &unk_182048;
        byte_19BED0 = 1;
      }
      goto LABEL_18;
    }
    v15 = v68;
    sub_77BB1(word_19999C);
    a3 = sub_7A990(0x76u);
    do
    {
      v16 = *a3++;
      *v15++ = v16;
    }
    while ( v16 );
    a2 = (int16_t *)v68;
    sub_7A25F(&byte_199EFE, (int)v68, 0);
LABEL_19:
    if ( word_199932 == word_19999C )
    {
      v17 = sub_76F22((int16_t)v90, v91, (int16_t *)&v76, &v78);
      if ( (int16_t)v76 > -1 )
      {
        word_199960 = -1;
        word_19990E = -1;
        word_19991C = v76;
      }
      if ( v17 == 1 )
      {
        sub_1196F7();
        sub_31F25(*(_WORD *)(dword_192B24 + 13 * v78 + 11));
        sub_6F88F(word_19992C);
        byte_199EFE = 1;
      }
    }
    v18 = sub_890EF((int16_t)v90, v91, (int16_t *)&v79, &v73);
    if ( (int16_t)v79 > -1 )
    {
      word_19990E = -1;
      word_199960 = v79;
    }
    if ( v18 == 1 && byte_19BED1 == 1 )
    {
      sub_7522B(v73);
    }
    else if ( !v18 )
    {
      if ( byte_19BED0 )
      {
        byte_19BED0 = 0;
        sub_123E6C((int)&unk_17CF00, 1);
        byte_19BED1 = 0;
        sub_785EC(v73, word_19999C);
        v39 = 113 * v73 + dword_19306C;
        v19 = sub_7A990(0x77u);
        sprintf(v70, v19, v39);
        sub_7A25F(&byte_199EFE, (int)v70, 0);
        v77 = -1;
        v74 = -1;
      }
      else if ( byte_19BED1 == 1 )
      {
        sub_75180((int16_t *)&v77, (int16_t *)&v74, v73);
      }
      else if ( *(_BYTE *)(dword_19306C + 113 * v73 + 22) == 6 )
      {
        v20 = sub_7A990(0x78u);
        sprintf(v72, v20);
        sub_7A25F(&byte_199EFE, (int)v72, 3);
      }
      else
      {
        v21 = sub_74ED8();
        v22 = v21;
        if ( v21 > -1 && sub_7843D(word_19999C, 129 * v21 + dword_197F9C) )
        {
          sub_75D48(v73);
        }
        else if ( v22 > -1 )
        {
          v40 = 129 * v22 + dword_197F9C;
          v23 = sub_7A990(0x75u);
          sprintf(v71, v23, v40);
          sub_7A25F(&byte_199EFE, (int)v71, 0);
          word_19BECC = -1;
        }
      }
    }
    v24 = (int16_t)v91;
    v25 = (int)&v76;
    v26 = sub_749F0((int16_t)v90, v91, &v76, &v78);
    if ( v26 )
    {
      if ( v26 == 4 && (int16_t)v76 > -1 )
      {
        word_199960 = -1;
        word_19990E = v76;
      }
    }
    else
    {
      LOWORD(v24) = *(_WORD *)(dword_1975C4 + 14);
      byte_199EFE = 1;
      *(_WORD *)dword_1975C4 = v24;
      if ( word_1999D8 != word_1999BE )
      {
        if ( word_1999BE != -1 )
        {
          v24 = word_1999D8;
          if ( word_1999D8 != -1 )
          {
            v24 = sub_77FE9(word_192248[word_1999BE]);
            if ( (uint16_t)sub_77FE9(word_192248[word_1999D8]) != (_WORD)v24 )
LABEL_48:
              byte_199EFA = 1;
            word_19991C = -1;
            goto LABEL_53;
          }
        }
        byte_199EFE = 1;
        goto LABEL_48;
      }
    }
LABEL_53:
    if ( (_WORD)v91 == v88 && word_19992E > 0 && sub_77FF5(*(_WORD *)(dword_192B24 + 11)) == word_19999C )
      sub_74E04(word_199912 != word_19992E);
    if ( (_WORD)v91 == v82 )
    {
      word_199A08 = 0;
      v83 = 1;
      sub_11C2F0();
      sub_119281();
      word_199960 = -1;
      sub_94376();
    }
    if ( (_WORD)v91 == v92 )
    {
      sub_72AE4((int)&v41, &v84);
      v25 = v84;
      v24 = (int)&v41;
      LOBYTE(v24) = sub_74AFE(
                      (int16_t *)&v41,
                      1,
                      v41,
                      v42,
                      v43,
                      v44,
                      v45,
                      v46,
                      v47,
                      v48,
                      v49,
                      v50,
                      v51,
                      v52,
                      v53,
                      v54,
                      v55,
                      v56,
                      v57,
                      v58,
                      v59,
                      v60,
                      v61,
                      v62,
                      v63,
                      v64,
                      v65,
                      v66,
                      v67);
      sub_75398();
      word_1999BE = -1;
      byte_199EFE = 1;
      if ( v27 == word_19992E && (_BYTE)v24 )
      {
        word_19992E = 0;
        word_199960 = -1;
        v25 = 305;
        v24 = 52;
        sub_A0305();
        sub_77048(
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67);
        sub_772C4(0);
      }
      word_19991C = -1;
      word_19BECE = sub_79B73(word_19999C);
    }
    if ( (_WORD)v91 == v87 )
    {
      if ( byte_199EF7 )
      {
        word_199A08 = 29;
        word_199A10 = 4;
        v83 = 1;
        word_199838 = word_1999C6;
      }
      else
      {
        v28 = v69;
        v24 = (int)v69;
        a3 = sub_7A990(0x79u);
        v25 = 0;
        do
        {
          v29 = *a3++;
          *v28++ = v29;
        }
        while ( v29 );
        a2 = (int16_t *)v69;
        sub_7A25F(&byte_199EFE, (int)v69, 0);
      }
    }
    if ( (_WORD)v91 == v81 )
    {
      sub_A015D((int16_t *)dword_1975C4);
    }
    else if ( (_WORD)v91 == v93 )
    {
      sub_A01C6((int16_t *)dword_1975C4);
    }
    if ( (_WORD)v91 == v86 && byte_19BED1 != 2 )
    {
      if ( byte_19BED1 )
      {
        if ( byte_19BED1 == 1 )
        {
          v24 = 1;
          sub_123E6C((int)&unk_17CF00, 1);
          byte_19BED1 = 0;
          v77 = -1;
          v74 = -1;
        }
      }
      else
      {
        v24 = 4;
        sub_123E6C((int)&unk_181FE8, 4);
        byte_19BED1 = 1;
      }
    }
    if ( (_WORD)v91 == v80 || (int16_t)v91 == -1002 )
    {
      LOWORD(v24) = word_1999D8;
      sub_74502();
      v30 = (_WORD)v24 == (uint16_t)word_1999D8;
      if ( (_WORD)v24 != word_1999D8 )
      {
        byte_199EFA = 1;
        *(_WORD *)dword_1975C4 = -1;
        word_19991C = -1;
        byte_199EFE = 1;
        if ( !v30 )
          word_19991C = -1;
        v94 = 1;
      }
    }
    v31 = v91;
    if ( (_WORD)v91 == v75 || (v31 = (int16_t)v91, (int16_t)v91 == -1001) )
    {
      LOWORD(v24) = word_1999D8;
      sub_745A5(v31, v24);
      v32 = (_WORD)v24 == (uint16_t)word_1999D8;
      if ( (_WORD)v24 != word_1999D8 )
      {
        word_19991C = -1;
        *(_WORD *)dword_1975C4 = -1;
        byte_199EFA = 1;
        byte_199EFE = 1;
        if ( !v32 )
          word_19991C = -1;
        v94 = 1;
      }
    }
    if ( (_WORD)v91 == word_19BEC8 || (_WORD)v91 == word_19BECA )
    {
      if ( (_WORD)v91 == word_19BEC8 && !word_19990C && !word_19990A )
        word_19990A = 1;
      if ( (_WORD)v91 == word_19BECA && !word_19990C )
        word_19990C = word_19990A == 0;
      if ( word_1999D8 > -1 && word_1999D8 < word_199A02 )
      {
        sub_75EE8(word_192248[word_1999D8]);
        if ( !v33 )
          sub_74502();
      }
      v34 = dword_1975C4;
      LOWORD(v24) = *(_WORD *)(dword_1975C4 + 14);
      v95 = 1;
      *(_WORD *)dword_1975C4 = v24;
      byte_199EFA = 1;
      byte_199EFE = 1;
      *(_WORD *)(v34 + 12) = -1;
    }
    if ( v94 )
    {
      v25 = dword_1975C4;
      *(_WORD *)(dword_1975C4 + 10) = 5;
      *(_WORD *)(v25 + 14) = 234;
      v35 = sub_A00F1((_WORD *)v25);
      *(_WORD *)(v25 + 6) = v35;
      *(_WORD *)(v25 + 2) = -1;
      *(_BYTE *)(v25 + 24) = 0;
      v36 = *(int16_t *)(v25 + 14);
      *(_BYTE *)(v25 + 26) = 1;
      v24 = v36 - v35 / 2;
      v94 = 0;
      *(_WORD *)v25 = v24;
    }
    sub_6F88F(word_19992C);
    if ( byte_199F1E )
    {
      v37 = sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * word_192248[word_1999D8]));
      sub_75B5F(v37, v24, v25, a2, (int16_t)a3);
    }
    if ( !(_WORD)v83 )
    {
      if ( word_1999D8 > -1 )
        word_199912 = sub_74E4A();
      if ( v95 )
      {
        v95 = 0;
      }
      else
      {
        sub_124D41();
        v38 = sub_72F92((int16_t)a3);
        sub_1077D(v38, v24, v25, a2);
      }
    }
    sub_12C2C6(1);
  }
  v77 = -1;
  v74 = -1;
  v13 = 1;
  v14 = &unk_17CF00;
  byte_19BED1 = 0;
LABEL_18:
  sub_123E6C((int)v14, v13);
  goto LABEL_19;
}
// 744C8: control flows out of bounds to 734A3
// 73C72: variable 'v11' is possibly undefined
// 740FE: variable 'v27' is possibly undefined
// 74385: variable 'v33' is possibly undefined
// 772BF: using guessed type int sub_772BF(_DWORD, _DWORD, _DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACE: using guessed type char byte_182ACE;
// 192248: using guessed type int16_t word_192248[500];
// 192B24: using guessed type int dword_192B24;
// 19306C: using guessed type int dword_19306C;
// 1975C4: using guessed type int dword_1975C4;
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 199838: using guessed type int16_t word_199838;
// 19990A: using guessed type int16_t word_19990A;
// 19990C: using guessed type int16_t word_19990C;
// 19990E: using guessed type int16_t word_19990E;
// 199912: using guessed type int16_t word_199912;
// 19991C: using guessed type int16_t word_19991C;
// 19992C: using guessed type int16_t word_19992C;
// 19992E: using guessed type int16_t word_19992E;
// 199932: using guessed type int16_t word_199932;
// 199960: using guessed type int16_t word_199960;
// 199992: using guessed type int16_t word_199992;
// 19999C: using guessed type int16_t word_19999C;
// 1999A4: using guessed type int16_t word_1999A4;
// 1999A8: using guessed type int16_t word_1999A8;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999BE: using guessed type int16_t word_1999BE;
// 1999C6: using guessed type int16_t word_1999C6;
// 1999D8: using guessed type int16_t word_1999D8;
// 1999F2: using guessed type int16_t word_1999F2;
// 1999F4: using guessed type int16_t word_1999F4;
// 199A02: using guessed type int16_t word_199A02;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199EF7: using guessed type char byte_199EF7;
// 199EFA: using guessed type char byte_199EFA;
// 199EFC: using guessed type char byte_199EFC;
// 199EFE: using guessed type char byte_199EFE;
// 199F05: using guessed type char byte_199F05;
// 199F09: using guessed type char byte_199F09;
// 199F0E: using guessed type char byte_199F0E;
// 199F10: using guessed type char byte_199F10;
// 199F13: using guessed type char byte_199F13;
// 199F14: using guessed type char byte_199F14;
// 199F1E: using guessed type char byte_199F1E;
// 199F29: using guessed type char byte_199F29;
// 199F38: using guessed type char byte_199F38;
// 19BEC0: using guessed type int dword_19BEC0;
// 19BEC4: using guessed type int dword_19BEC4;
// 19BEC8: using guessed type int16_t word_19BEC8;
// 19BECA: using guessed type int16_t word_19BECA;
// 19BECC: using guessed type int16_t word_19BECC;
// 19BECE: using guessed type int16_t word_19BECE;
// 19BED0: using guessed type char byte_19BED0;
// 19BED1: using guessed type char byte_19BED1;
// 19C195: using guessed type char byte_19C195;


//----- (000744CD) --------------------------------------------------------
_DWORD *sub_744CD(int a1, int a2, int a3, int a4)
{
  int16_t v4; // ax

  v4 = *(uint8_t *)(dword_1930DC + 59 * a2 + 49) + 45;
  if ( a4 )
    return sub_126AFD((int)off_181FE4, v4, a3);
  else
    return sub_126B42((int)off_181FE4, v4, a3);
}
// 181FE4: using guessed type char *off_181FE4;
// 1930DC: using guessed type int dword_1930DC;


//----- (00074502) --------------------------------------------------------
void sub_74502()
{
  int16_t v0; // cx
  char v1; // bl
  int16_t v2; // si
  int16_t v3; // dx
  int16_t v4; // ax
  int16_t v5; // ax

  v0 = word_1999D8;
  v1 = 0;
  v2 = sub_77FE9(word_192248[word_1999D8]);
  v3 = word_1999D8 + 1;
  do
  {
    if ( v3 >= word_199A02 )
      v3 = 0;
    v4 = sub_77FE9(word_192248[v3]);
    if ( v4 == word_19999C && v2 == v4
      || (uint16_t)sub_77FE9(word_192248[v3]) != word_19999C && v2 != word_19999C )
    {
      sub_75EE8(word_192248[v3]);
      if ( v5 > 0 )
      {
        v1 = 1;
        word_1999D8 = v3;
      }
    }
    if ( v3 == v0 )
      v1 = 1;
    ++v3;
  }
  while ( !v1 );
}
// 74589: variable 'v5' is possibly undefined
// 192248: using guessed type int16_t word_192248[500];
// 19999C: using guessed type int16_t word_19999C;
// 1999D8: using guessed type int16_t word_1999D8;
// 199A02: using guessed type int16_t word_199A02;


//----- (000745A5) --------------------------------------------------------
void sub_745A5(int a1, int a2)
{
  int16_t v2; // cx
  char v3; // bl
  int16_t v4; // ax
  int16_t v5; // si
  int v6; // edx
  int16_t v7; // ax
  int16_t v8; // ax

  v2 = word_1999D8;
  v3 = 0;
  v4 = sub_77FE9(word_192248[word_1999D8]);
  LOWORD(a2) = word_1999D8;
  v5 = v4;
  v6 = a2 - 1;
  do
  {
    if ( (v6 & 0x8000u) != 0 )
    {
      LOWORD(v6) = word_199A02;
      --v6;
    }
    v7 = sub_77FE9(word_192248[(int16_t)v6]);
    if ( v7 == word_19999C && v5 == v7
      || (uint16_t)sub_77FE9(word_192248[(int16_t)v6]) != word_19999C && v5 != word_19999C )
    {
      sub_75EE8(word_192248[(int16_t)v6]);
      if ( v8 > 0 )
      {
        v3 = 1;
        word_1999D8 = v6;
      }
    }
    if ( (_WORD)v6 == v2 )
      v3 = 1;
    --v6;
  }
  while ( !v3 );
}
// 7462E: variable 'v8' is possibly undefined
// 192248: using guessed type int16_t word_192248[500];
// 19999C: using guessed type int16_t word_19999C;
// 1999D8: using guessed type int16_t word_1999D8;
// 199A02: using guessed type int16_t word_199A02;


//----- (0007464A) --------------------------------------------------------
void sub_7464A()
{
  int v0; // edi
  int16_t v1; // si
  _BYTE *v2; // eax
  int v3; // ebx
  int16_t v4; // si
  int v5; // ecx
  _DWORD *v6; // eax
  int v7; // edx
  int v8; // eax

  sub_82348();
  dword_192B1C = (int)sub_126B42((int)off_181FE4, 0, dword_192ED4);
  dword_192B60 = (int)sub_126B42((int)off_181FE4, 1, dword_192ED4);
  dword_192B5C = (int)sub_126B42((int)off_181FE4, 2, dword_192ED4);
  dword_192B64 = (int)sub_126B42((int)off_181FE4, 3, dword_192ED4);
  dword_192B3C = (int)sub_126B42((int)off_181FE4, 4, dword_192ED4);
  dword_192B34 = (int)sub_126B42((int)off_181FE4, 5, dword_192ED4);
  v0 = 0;
  dword_192B48 = (int)sub_126B42((int)off_181FE4, 6, dword_192ED4);
  dword_192B2C = (int)sub_126B42((int)off_181FE4, 7, dword_192ED4);
  dword_192B20 = (int)sub_126B42((int)off_181FE4, 8, dword_192ED4);
  dword_19BEC4 = (int)sub_126B42((int)off_181FE4, 9, dword_192ED4);
  dword_19BEC0 = (int)sub_126B42((int)off_181FE4, 10, dword_192ED4);
  dword_192B58 = (int)sub_126B42((int)off_181FE4, 11, dword_192ED4);
  dword_192B4C = (int)sub_126B42((int)off_181FE4, 12, dword_192ED4);
  dword_192B50 = (int)sub_126B42((int)off_181FE4, 13, dword_192ED4);
  dword_192B30 = (int)sub_126B42((int)off_181FE4, 14, dword_192ED4);
  dword_192B40 = (int)sub_126B42((int)off_181FE4, 15, dword_192ED4);
  dword_192B38 = (int)sub_126B42((int)off_181FE4, 16, dword_192ED4);
  dword_192B28 = (int)sub_126B42((int)off_181FE4, 17, dword_192ED4);
  dword_192B44 = (int)sub_126B42((int)off_181FE4, 18, dword_192ED4);
  v1 = 0;
  dword_193108 = (int)sub_110D3C(dword_192ED4, 67);
  sub_72A65();
  while ( 1 )
  {
    v2 = (_BYTE *)(59 * v1 + dword_1930DC);
    if ( (char)v2[58] == word_19999C && v2[57] == 1 && !v2[35] )
    {
      v3 = (int16_t)v0;
      *(_DWORD *)(4 * (int16_t)v0++ + dword_193108) = sub_744CD(word_19999C, v1, dword_192ED4, 0);
      *(_WORD *)(dword_193188 + 2 * v3) = v1;
    }
    if ( ++v1 >= 67 )
    {
      sub_74937();
      v4 = 34;
      v5 = 0;
      do
      {
        v6 = sub_126B42((int)off_181FE4, v4++, dword_192ED4);
        v7 = (int)v6;
        v8 = (int16_t)v5++;
        dword_1932E0[v8] = v7;
      }
      while ( (int16_t)v5 < 11 );
      JUMPOUT(0x734A2);
    }
  }
}
// 748FB: control flows out of bounds to 734A2
// 181FE4: using guessed type char *off_181FE4;
// 192B1C: using guessed type int dword_192B1C;
// 192B20: using guessed type int dword_192B20;
// 192B28: using guessed type int dword_192B28;
// 192B2C: using guessed type int dword_192B2C;
// 192B30: using guessed type int dword_192B30;
// 192B34: using guessed type int dword_192B34;
// 192B38: using guessed type int dword_192B38;
// 192B3C: using guessed type int dword_192B3C;
// 192B40: using guessed type int dword_192B40;
// 192B44: using guessed type int dword_192B44;
// 192B48: using guessed type int dword_192B48;
// 192B4C: using guessed type int dword_192B4C;
// 192B50: using guessed type int dword_192B50;
// 192B58: using guessed type int dword_192B58;
// 192B5C: using guessed type int dword_192B5C;
// 192B60: using guessed type int dword_192B60;
// 192B64: using guessed type int dword_192B64;
// 192ED4: using guessed type int dword_192ED4;
// 1930DC: using guessed type int dword_1930DC;
// 193108: using guessed type int dword_193108;
// 193188: using guessed type int dword_193188;
// 1932E0: using guessed type int dword_1932E0[11];
// 19999C: using guessed type int16_t word_19999C;
// 19BEC0: using guessed type int dword_19BEC0;
// 19BEC4: using guessed type int dword_19BEC4;


//----- (00074900) --------------------------------------------------------
int sub_74900()
{
  int16_t v0; // si
  int v1; // ecx
  _DWORD *v2; // eax
  int v3; // edx
  int result; // eax

  v0 = 34;
  v1 = 0;
  do
  {
    v2 = sub_126B42((int)off_181FE4, v0++, dword_192ED4);
    v3 = (int)v2;
    result = (int16_t)v1++;
    dword_1932E0[result] = v3;
  }
  while ( (int16_t)v1 < 11 );
  return result;
}
// 181FE4: using guessed type char *off_181FE4;
// 192ED4: using guessed type int dword_192ED4;
// 1932E0: using guessed type int dword_1932E0[11];


//----- (00074937) --------------------------------------------------------
void sub_74937()
{
  int v0; // esi
  int v1; // ecx
  _DWORD *v2; // eax
  int v3; // ebx
  int v4; // edx
  int16_t i; // di
  int v6; // ecx
  int v7; // edx
  _DWORD *v8; // eax
  int v9; // ebx
  int v10; // [esp+0h] [ebp-8h]
  int v11; // [esp+4h] [ebp-4h]

  v0 = 19;
  v11 = 0;
  sub_111499(dword_192ED4);
  do
  {
    v1 = (int16_t)v11++;
    v2 = sub_126B42((int)off_181FE4, (int16_t)v0, dword_192ED4);
    v3 = dword_192ED4;
    v4 = (int16_t)v0;
    dword_18F928[v1] = (int)v2;
    ++v0;
    dword_18F948[v1] = (int)sub_126B42((int)off_181FE4, v4, v3);
  }
  while ( (int16_t)v11 < 8 );
  for ( i = 0; i < 7; ++i )
  {
    v10 = (int16_t)v0;
    v6 = i;
    v7 = (int16_t)v0++;
    v8 = sub_126B42((int)off_181FE4, v7, dword_192ED4);
    v9 = dword_192ED4;
    dword_192B8C[i] = (int)v8;
    dword_192B70[v6] = (int)sub_126B42((int)off_181FE4, v10, v9);
  }
  sub_111499(dword_192ED4);
  JUMPOUT(0x734A2);
}
// 749EB: control flows out of bounds to 734A2
// 181FE4: using guessed type char *off_181FE4;
// 18F928: using guessed type int dword_18F928[8];
// 18F948: using guessed type int dword_18F948[8];
// 192B70: using guessed type int dword_192B70[7];
// 192B8C: using guessed type int dword_192B8C[15];
// 192ED4: using guessed type int dword_192ED4;


//----- (000749F0) --------------------------------------------------------
int sub_749F0(int a1, int a2, _WORD *a3, _WORD *a4)
{
  int v6; // edx
  char v7; // bl
  int16_t v8; // ax
  char v9; // cl
  int16_t v11; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h] BYREF

  v6 = -1;
  *a3 = -1;
  *a4 = -1;
  v7 = 0;
  for ( i = 0; (int16_t)i < word_1999F8 && !v7; ++i )
  {
    if ( a2 == word_1906C0[6 * (int16_t)i] )
    {
      sub_A0FA8((int16_t *)&i, 7, 4);
      v8 = i;
      *a4 = i;
      v6 = 0;
      word_1999D8 = sub_78ABA(v8);
      if ( word_1999D8 != word_1999BE )
        word_1999BE = -1;
      v7 = 1;
    }
  }
  if ( (int16_t)v6 == -1 )
  {
    i = 0;
    v9 = 0;
    while ( (int16_t)i < word_1999F8 && !v9 )
    {
      if ( v11 == word_1906C0[6 * (int16_t)i] )
      {
        v6 = 4;
        v9 = 1;
        *a3 = i;
      }
      ++i;
    }
  }
  return v6;
}
// 74A8C: variable 'v11' is possibly undefined
// 1906C0: using guessed type int16_t word_1906C0[];
// 1999BE: using guessed type int16_t word_1999BE;
// 1999D8: using guessed type int16_t word_1999D8;
// 1999F8: using guessed type int16_t word_1999F8;


//----- (00074AB4) --------------------------------------------------------
char sub_74AB4(int a1, int a2, int a3)
{
  int v3; // esi
  int16_t i; // cx

  v3 = a1;
  for ( i = 0; i < a2; ++i )
  {
    a1 = 129 * *(int16_t *)(v3 + 2 * i) + dword_197F9C;
    if ( *(_BYTE *)(a1 + 93) != *(_BYTE *)(a1 + 99) )
      LOBYTE(a1) = sub_72B33(a1, word_19999C, a3);
  }
  return a1;
}
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;


//----- (00074AFE) --------------------------------------------------------
char sub_74AFE(
        int16_t *a1, int a2,
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
        int64_t a28,
        int a29)
{
  int v29; // eax
  int16_t v30; // dx
  int v31; // edx
  char v32; // ch
  int v33; // edx
  uint16_t v34; // ax
  int v35; // edx
  char *v36; // eax
  int v38; // ebx
  char *v39; // eax
  int64_t v40; // rax
  int v41; // eax
  int v42; // edi
  uint16_t v43; // ax
  char *v44; // eax
  int16_t i; // bx
  int v46; // edx
  int v47; // eax
  int16_t j; // dx
  int16_t v49; // ax
  int v50; // [esp-14h] [ebp-2D8h]
  int v51; // [esp-10h] [ebp-2D4h]
  int v52; // [esp-10h] [ebp-2D4h]

  v29 = 129 * *a1 + dword_197F9C;
  v30 = *(_WORD *)(v29 + 105);
  LOWORD(v29) = *(_WORD *)(v29 + 103);
  LOBYTE(STACK[0x602]) = 1;
  v31 = (int16_t)sub_7A3E3(v29, v30);
  v32 = 0;
  if ( v31 == -1 || !sub_79D1C(SHIWORD(a28), v31) )
  {
    LOBYTE(STACK[0x602]) = 0;
    if ( a2 )
    {
      if ( HIWORD(a27) == 1 )
      {
        v33 = 3753 * SHIWORD(a28);
        if ( sub_8F8DC(*(_BYTE *)(v33 + dword_197F98 + 21)) )
        {
          v51 = v33 + dword_197F98 + 21;
          v34 = 123;
        }
        else
        {
          v51 = v33 + dword_197F98 + 21;
          v34 = 122;
        }
      }
      else
      {
        v35 = 3753 * SHIWORD(a28);
        if ( sub_8F8DC(*(_BYTE *)(v35 + dword_197F98 + 21)) )
        {
          v51 = v35 + dword_197F98 + 21;
          v34 = 125;
        }
        else
        {
          v51 = dword_197F98 + v35 + 21;
          v34 = 124;
        }
      }
      v36 = sub_7A990(v34);
      sprintf((char *)&a29 + 2, v36, v51);
      if ( !(uint8_t)sub_7A25F(&byte_199EFE, (int)&a29 + 2, 1) )
        goto LABEL_12;
    }
  }
  for ( STACK[0x5FE] = 0; (int16_t)STACK[0x5FE] < SHIWORD(a27); ++STACK[0x5FE] )
  {
    v38 = 129 * *(int16_t *)(*(_DWORD *)((char *)&a28 + 2) + 2 * (int16_t)STACK[0x5FE]);
    if ( *(int16_t *)(v38 + dword_197F9C + 116) > -1 )
    {
      if ( a2 )
      {
        strcpy((char *)&STACK[0x536], (char *)sub_97588(*(_WORD *)(v38 + dword_197F9C + 116), 1));
        v50 = v38 + dword_197F9C;
        v39 = sub_7A990(0x7Eu);
        v40 = sprintf((char *)&a29 + 2, v39, v50, &STACK[0x536]);
        if ( !(uint8_t)sub_7A25F(&byte_199EFE, SHIDWORD(v40), 1) )
          goto LABEL_12;
      }
      v32 = 1;
    }
  }
  v41 = sub_72E61();
  v42 = v41;
  if ( a2 && (int16_t)v41 > 0 )
  {
    v52 = (int16_t)v41;
    if ( HIWORD(a27) == 1 )
      v43 = 128;
    else
      v43 = 129;
    v44 = sub_7A990(v43);
    sprintf((char *)&a29 + 2, v44, v52);
    if ( !(uint8_t)sub_7A25F(&byte_199EFE, (int)&a29 + 2, 1) )
    {
LABEL_12:
      strcpy((char *)&STACK[0x46E], sub_7A990(0x7Fu));
      sub_7A25F(&byte_199EFE, (int)&STACK[0x46E], 3);
      return 0;
    }
    if ( LOBYTE(STACK[0x602]) )
    {
      *(_DWORD *)(dword_197F98 + 3753 * SHIWORD(a28) + 50) += (int16_t)v42;
      sub_74AB4(*(int *)((char *)&a28 + 2), SHIWORD(a27), a2);
    }
  }
  if ( v32 )
  {
    for ( i = 0; i < SHIWORD(a27); ++i )
    {
      v46 = dword_197F9C + 129 * *(int16_t *)(*(_DWORD *)((char *)&a28 + 2) + 2 * i);
      if ( *(int16_t *)(v46 + 116) > -1 )
      {
        v47 = 59 * *(int16_t *)(v46 + 116);
        v42 = dword_1930DC;
        *(_BYTE *)(dword_1930DC + v47 + 57) = 0;
        *(_WORD *)(v42 + v47 + 53) = -1;
        *(_BYTE *)(v42 + v47 + 55) = 0;
        *(_WORD *)(v46 + 116) = -1;
      }
    }
  }
  for ( j = 0; j < SHIWORD(a27); ++j )
  {
    v49 = *(_WORD *)(*(_DWORD *)((char *)&a28 + 2) + 2 * j);
    sub_A163A(v49, v42);
  }
  sub_E2D72(SHIWORD(a28), v42);
  return 1;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199EFE: using guessed type char byte_199EFE;


//----- (00074E04) --------------------------------------------------------
int sub_74E04(int result)
{
  int v1; // ebx
  int v2; // edx

  if ( (_WORD)result )
  {
    for ( result = 0; (int16_t)result < word_19992E; ++result )
    {
      v1 = 13 * (int16_t)result;
      *(_BYTE *)(dword_192B24 + v1 + 4) = 1;
    }
  }
  else
  {
    while ( (int16_t)result < word_19992E )
    {
      v2 = 13 * (int16_t)result++;
      *(_BYTE *)(v2 + dword_192B24 + 4) = 0;
    }
  }
  return result;
}
// 192B24: using guessed type int dword_192B24;
// 19992E: using guessed type int16_t word_19992E;


//----- (00074E4A) --------------------------------------------------------
int sub_74E4A()
{
  int v0; // edx
  int16_t i; // bx
  int v2; // eax
  char v3; // cl

  v0 = 0;
  if ( sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * word_192248[word_1999D8])) == word_19999C )
  {
    for ( i = 0; i < word_19992E; ++i )
    {
      v2 = dword_192B24 + 13 * i;
      v3 = *(_BYTE *)(v2 + 4);
      *(_BYTE *)(dword_192B68 + i) = v3;
      if ( v3 )
      {
        if ( !(_WORD)v0 )
          word_199836 = *(_WORD *)(v2 + 11);
        if ( (_WORD)v0 == 1 )
          word_199838 = *(_WORD *)(13 * i + dword_192B24 + 11);
        ++v0;
      }
    }
  }
  return v0;
}
// 192248: using guessed type int16_t word_192248[500];
// 192B24: using guessed type int dword_192B24;
// 192B68: using guessed type int dword_192B68;
// 1975D4: using guessed type int16_t word_1975D4;
// 199836: using guessed type int16_t word_199836;
// 199838: using guessed type int16_t word_199838;
// 19992E: using guessed type int16_t word_19992E;
// 19999C: using guessed type int16_t word_19999C;
// 1999D8: using guessed type int16_t word_1999D8;


//----- (00074ED8) --------------------------------------------------------
int sub_74ED8()
{
  int v0; // edx
  int16_t i; // bx
  int v2; // eax

  v0 = -1;
  for ( i = 0; i < word_19992E && (int16_t)v0 == -1; ++i )
  {
    v2 = dword_192B24 + 13 * i;
    if ( *(_BYTE *)(v2 + 4) )
      LOWORD(v0) = *(_WORD *)(v2 + 11);
  }
  return v0;
}
// 192B24: using guessed type int dword_192B24;
// 19992E: using guessed type int16_t word_19992E;


//----- (00074F14) --------------------------------------------------------
_BOOL1 sub_74F14()
{
  _BOOL1 v0; // dl
  int16_t i; // bx
  int v2; // eax

  v0 = 0;
  for ( i = 0; i < 67 && !v0; ++i )
  {
    v2 = 59 * i + dword_1930DC;
    if ( *(char *)(v2 + 58) == word_19999C )
      v0 = *(_BYTE *)(v2 + 57) >= 0;
  }
  return v0;
}
// 1930DC: using guessed type int dword_1930DC;
// 19999C: using guessed type int16_t word_19999C;


//----- (00074F51) --------------------------------------------------------
int sub_74F51( int a1)
{
  int v2; // ebx
  char v3; // cl
  int i; // eax

  v2 = -1;
  v3 = 0;
  for ( i = 0; (int16_t)i < word_1999F8 && !v3; ++i )
  {
    if ( a1 == word_1906C2[6 * (int16_t)i] )
    {
      v3 = 1;
      v2 = i;
    }
  }
  return v2;
}
// 1906C2: using guessed type int16_t word_1906C2[];
// 1999F8: using guessed type int16_t word_1999F8;


//----- (00074F8A) --------------------------------------------------------
char sub_74F8A( int a1)
{
  char v1; // bl

  v1 = sub_75035(a1, 0);
  sub_123E6C((int)&unk_181FE8, 4);
  return v1;
}


//----- (00074FAA) --------------------------------------------------------
char sub_74FAA( int a1, int a2)
{
  char v3; // cl
  int v4; // esi
  char *v5; // eax
  int64_t v6; // rax
  int v8; // [esp-8h] [ebp-6Ch]
  int v9; // [esp-4h] [ebp-68h]
  _BYTE v10[100]; // [esp+0h] [ebp-64h] BYREF

  v3 = sub_75035(a2, 1);
  sub_123E6C((int)&unk_182018, 4);
  if ( v3 )
  {
    v4 = 113 * a1;
    if ( (uint16_t)sub_1276F0(v4 + dword_19306C + 31, a2) )
    {
      v9 = dword_19306C + 113 * a2;
      v8 = v4 + dword_19306C;
      v5 = sub_7A990(0x82u);
      v6 = sprintf(v10, v5, v8, v9);
      v3 = 0;
      sub_7A25F(&byte_199EFE, SHIDWORD(v6), 3);
    }
  }
  return v3;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 199EFE: using guessed type char byte_199EFE;


//----- (00075035) --------------------------------------------------------
char sub_75035( int a1, int a2)
{
  int v3; // esi
  char v4; // cl
  uint16_t v5; // ax
  char v6; // al
  char *v7; // eax
  char *v8; // eax
  int v10; // [esp-8h] [ebp-66h]
  int v11; // [esp-4h] [ebp-62h]
  _BYTE v12[120]; // [esp+0h] [ebp-5Eh] BYREF
  char v13[80]; // [esp+78h] [ebp+1Ah] BYREF
  char v14[20]; // [esp+C8h] [ebp+6Ah] BYREF
  int v15; // [esp+DCh] [ebp+7Eh] BYREF

  v3 = 113 * a1;
  v15 = 0;
  v13[0] = 0;
  v4 = 1;
  if ( *(_BYTE *)(v3 + dword_19306C + 22) == 6 )
  {
    v4 = 0;
    if ( a2 )
      v5 = 131;
    else
      v5 = 132;
LABEL_4:
    strcpy(v13, sub_7A990(v5));
    goto LABEL_17;
  }
  if ( !sub_79E32(word_19999C, a1) )
  {
    v4 = 0;
    if ( a2 )
      v5 = 133;
    else
      v5 = 134;
    goto LABEL_4;
  }
  sub_7A47A(a1, &v15);
  if ( v6 )
  {
    sub_784A0(v15, v14);
    sub_123E6C((int)&unk_17CF00, 1);
    if ( a2 )
    {
      v10 = v3 + dword_19306C;
      v7 = sub_7A990(0x87u);
      sprintf(v12, v7, v10, v14);
      v4 = sub_7A25F(&byte_199EFE, (int)v12, 1);
    }
    else
    {
      v4 = 0;
    }
  }
  else if ( !a2 && !sub_78D71(word_19999C, a1) )
  {
    v11 = dword_19306C + v3;
    v8 = sub_7A990(0x88u);
    v4 = 0;
    sprintf(v13, v8, v11);
  }
LABEL_17:
  if ( !v4 && v13[0] )
    sub_7A25F(&byte_199EFE, (int)v13, 3);
  return v4;
}
// 750C1: variable 'v6' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 19999C: using guessed type int16_t word_19999C;
// 199EFE: using guessed type char byte_199EFE;


//----- (00075180) --------------------------------------------------------
char sub_75180(int16_t *a1, int16_t *a2, int a3)
{
  int v4; // eax
  char result; // al
  char v6; // [esp+0h] [ebp-4h]

  v4 = *a1;
  if ( v4 == -1 )
  {
    v6 = sub_75035(a3, 0);
    result = sub_123E6C((int)&unk_181FE8, 4);
    if ( v6 )
    {
      *a1 = a3;
      return sub_123E6C((int)&unk_182018, 4);
    }
  }
  else
  {
    result = sub_74FAA(v4, a3);
    if ( result )
    {
      *a2 = a3;
      sub_123E6C((int)&unk_17CF00, 1);
      if ( *a2 == *a1 )
        sub_7522B(*a2);
      else
        sub_787EA(*a1, word_19999C, a3);
      result = sub_123E6C((int)&unk_181FE8, 4);
      *a1 = -1;
      *a2 = -1;
    }
  }
  return result;
}
// 19999C: using guessed type int16_t word_19999C;


//----- (0007522B) --------------------------------------------------------
int sub_7522B( int a1)
{
  char *v2; // eax
  int v4; // [esp-4h] [ebp-68h]
  _BYTE v5[100]; // [esp+0h] [ebp-64h] BYREF

  v4 = 113 * a1 + dword_19306C;
  v2 = sub_7A990(0x89u);
  sprintf(v5, v2, v4);
  sub_77C07(a1, word_19999C);
  return sub_7A25F(&byte_199EFE, (int)v5, 3);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 19999C: using guessed type int16_t word_19999C;
// 199EFE: using guessed type char byte_199EFE;


//----- (0007527A) --------------------------------------------------------
void sub_7527A( int a1)
{
  int16_t v1; // di
  int16_t v2; // si
  int v3; // eax
  _DWORD v4[2]; // [esp+0h] [ebp-3Ch] BYREF
  int v5; // [esp+8h] [ebp-34h]
  int v6; // [esp+Ch] [ebp-30h]
  int v7; // [esp+10h] [ebp-2Ch]
  int v8; // [esp+14h] [ebp-28h]
  int v9; // [esp+18h] [ebp-24h]
  int16_t v10; // [esp+1Ch] [ebp-20h] BYREF
  int v11; // [esp+20h] [ebp-1Ch]
  int v12; // [esp+24h] [ebp-18h]
  int v13; // [esp+28h] [ebp-14h]
  int v14; // [esp+2Ch] [ebp-10h]
  int v15; // [esp+30h] [ebp-Ch] BYREF
  int v16; // [esp+34h] [ebp-8h] BYREF
  int16_t v17; // [esp+38h] [ebp-4h] BYREF

  v4[0] = 134678278;
  v4[1] = 168364296;
  if ( a1 == 4 )
  {
    v8 = 15;
    v11 = 52;
    v12 = 305;
    v13 = 182;
  }
  else
  {
    v8 = 306;
    v11 = 235;
    v12 = 318;
    v13 = 169;
  }
  v14 = 0;
  v1 = v8;
  while ( (int16_t)v14 < word_19999A )
  {
    v2 = v14;
    if ( sub_78C94(v14, word_19999C) )
    {
      LOWORD(v3) = sub_784F0(v2, word_19999C);
      v9 = v3;
      v5 = (int16_t)v13;
      v6 = (int16_t)v12;
      v7 = (int16_t)v11;
      sub_911D5(v2, v1, v11, v12, v13, 0, 0, 1, &v10, &v17);
      sub_911D5(v9, v1, v7, v6, v5, 0, 0, 1, &v16, &v15);
      sub_A1299(v16 + 3, v15 + 3, v10, v17, (int)v4);
    }
    ++v14;
  }
  JUMPOUT(0x734A2);
}
// 75393: control flows out of bounds to 734A2
// 75304: variable 'v3' is possibly undefined
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;


//----- (00075398) --------------------------------------------------------
void sub_75398()
{
  int v0; // edx
  int16_t i; // ax

  v0 = 0;
  for ( i = (uint8_t)byte_199F14 * *(_WORD *)(dword_1975C4 + 12); i < word_19992E; ++i )
  {
    if ( *(_BYTE *)(dword_192B24 + 13 * i + 4) )
      ++v0;
  }
  JUMPOUT(0x74F0E);
}
// 753D1: control flows out of bounds to 74F0E
// 192B24: using guessed type int dword_192B24;
// 1975C4: using guessed type int dword_1975C4;
// 19992E: using guessed type int16_t word_19992E;
// 199F14: using guessed type char byte_199F14;


//----- (000753F2) --------------------------------------------------------
int16_t *sub_753F2( int a1)
{
  char v1; // al
  uint16_t v2; // ax

  v1 = *(_BYTE *)(dword_197F9C + 129 * a1 + 113);
  LOBYTE(word_18FF78) = 0;
  switch ( v1 )
  {
    case 0:
      v2 = 138;
      goto LABEL_7;
    case 1:
      v2 = 139;
      goto LABEL_7;
    case 2:
      v2 = 140;
      goto LABEL_7;
    case 3:
      v2 = 141;
      goto LABEL_7;
    case 4:
      v2 = 142;
LABEL_7:
      strcpy((char *)&word_18FF78, sub_7A990(v2));
      break;
    default:
      return &word_18FF78;
  }
  return &word_18FF78;
}
// 18FF78: using guessed type int16_t word_18FF78;
// 197F9C: using guessed type int dword_197F9C;


//----- (0007545C) --------------------------------------------------------
void sub_7545C( int a1)
{
  int v2; // edx
  int v3; // eax
  int16_t v4; // ax
  int v5; // edi
  int v6; // edx
  int16_t v7; // [esp+4h] [ebp-20h]
  int16_t v8; // [esp+Ch] [ebp-18h]
  int16_t v9; // [esp+1Ch] [ebp-8h]
  int16_t v10; // [esp+20h] [ebp-4h]

  if ( word_199A08 == 4 )
    v8 = 58;
  else
    v8 = 57;
  v2 = 0;
  do
    v3 = *(int16_t *)(dword_192B24 + 13 * (a1 + (int16_t)v2++) + 11);
  while ( v3 == -1 );
  v4 = sub_77FF5(v3);
  word_19992C = 0;
  v10 = v4;
  while ( (uint8_t)byte_199F0E > word_19992C && word_19992C < word_19992E && a1 + word_19992C < word_19992E )
  {
    v7 = word_1999A4 + 62 * (word_19992C % (uint8_t)byte_199F14);
    v5 = 13 * (int16_t)(a1 + word_19992C);
    v9 = word_1999A8 + 60 * (word_19992C / (uint8_t)byte_199F14);
    v6 = v5 + dword_192B24;
    *(_WORD *)(v6 + 5) = v7;
    *(_WORD *)(v6 + 7) = v9;
    if ( v10 == word_19999C )
      *(_WORD *)(v5 + dword_192B24 + 9) = sub_11438B(v7, v9, v8 + v7, v9 + 57, &unk_1792E8, 41);
    else
      *(_WORD *)(v6 + 9) = -1000;
    ++word_19992C;
  }
  JUMPOUT(0x75B59);
}
// 7593E: control flows out of bounds to 75B59
// 192B24: using guessed type int dword_192B24;
// 19992C: using guessed type int16_t word_19992C;
// 19992E: using guessed type int16_t word_19992E;
// 19999C: using guessed type int16_t word_19999C;
// 1999A4: using guessed type int16_t word_1999A4;
// 1999A8: using guessed type int16_t word_1999A8;
// 199A08: using guessed type int16_t word_199A08;
// 199F0E: using guessed type char byte_199F0E;
// 199F14: using guessed type char byte_199F14;


//----- (000755D2) --------------------------------------------------------
void sub_755D2()
{
  int16_t i; // di
  int v1; // esi
  int v2; // [esp+0h] [ebp-8h] BYREF
  int v3; // [esp+4h] [ebp-4h] BYREF

  for ( i = 0; i < word_1999F8; ++i )
  {
    v1 = 6 * i;
    sub_773B7(i, &v3, &v2);
    word_1906C0[v1] = sub_11438B(
                        word_1906C8[v1],
                        word_1906CA[v1],
                        v3 + word_1906C8[v1],
                        v2 + word_1906CA[v1],
                        &unk_1792E8,
                        41);
  }
  JUMPOUT(0x75B59);
}
// 7593E: control flows out of bounds to 75B59
// 1906C0: using guessed type int16_t word_1906C0[];
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 1999F8: using guessed type int16_t word_1999F8;


//----- (0007563F) --------------------------------------------------------
int16_t sub_7563F( int a1)
{
  int16_t v1; // si
  int16_t v2; // cx
  int16_t v3; // di
  int16_t i; // bx
  int v5; // edx
  int v6; // eax
  int v7; // edx
  int16_t v8; // bx
  int v9; // eax
  int16_t j; // cx
  int v11; // edi
  int16_t result; // ax
  _WORD v13[250]; // [esp+0h] [ebp-1FCh] BYREF
  int v14; // [esp+1F4h] [ebp-8h]
  int v15; // [esp+1F8h] [ebp-4h]

  v15 = -1;
  v1 = 0;
  word_19992C = 0;
  v2 = word_192248[a1];
  memset(v13, -1, sizeof(v13));
  v3 = word_19992E;
  for ( i = 0; i < v3; ++i )
  {
    v14 = 13 * i;
    if ( *(_BYTE *)(v14 + dword_192B24 + 4) )
    {
      v5 = v1++;
      v13[v5] = *(_WORD *)(v14 + dword_192B24 + 11);
    }
  }
  memset(dword_192B24, 0, 3250);
  v6 = 0;
  do
  {
    v7 = 13 * (int16_t)v6++;
    *(_WORD *)(v7 + dword_192B24 + 9) = -1000;
  }
  while ( (int16_t)v6 < 250 );
  word_19992E = 0;
  while ( v2 > -1 && word_19992E < 250 )
  {
    v8 = *(int16_t *)((char *)&word_1975D4 + 5 * v2);
    if ( sub_76127(v8) && *(char *)(dword_197F9C + 129 * v8 + 100) < 3 )
    {
      *(_WORD *)(dword_192B24 + 13 * word_19992E + 11) = v8;
      v9 = word_19C53C;
      if ( word_19C53C != -1 && v8 == word_19C53C )
      {
        LOWORD(v9) = word_19992E;
        v15 = v9;
      }
      ++word_19992E;
    }
    v2 = *(int16_t *)((char *)&word_1975D6 + 5 * v2);
  }
  for ( j = 0; j < word_19992E; ++j )
  {
    v11 = 13 * j;
    if ( sub_C5A84(*(_WORD *)(v11 + dword_192B24 + 11), (int)v13, v1) )
      *(_BYTE *)(v11 + dword_192B24 + 4) = 1;
  }
  if ( (int16_t)v15 != -1 && word_19992E > 1 )
    sub_75802((int16_t)v15);
  result = word_1999D8;
  word_199932 = -1;
  if ( word_1999D8 > -1 )
  {
    result = sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * word_192248[word_1999D8]));
    word_199932 = result;
  }
  return result;
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192248: using guessed type int16_t word_192248[500];
// 192B24: using guessed type int dword_192B24;
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;
// 19992C: using guessed type int16_t word_19992C;
// 19992E: using guessed type int16_t word_19992E;
// 199932: using guessed type int16_t word_199932;
// 1999D8: using guessed type int16_t word_1999D8;
// 19C53C: using guessed type int16_t word_19C53C;


//----- (00075802) --------------------------------------------------------
int sub_75802(int result)
{
  _BYTE v1[13]; // [esp+0h] [ebp-10h] BYREF

  if ( word_19992E > 1 )
  {
    result = 13 * (int16_t)result;
    qmemcpy(v1, (void *)dword_192B24, sizeof(v1));
    qmemcpy((void *)dword_192B24, (void *)(dword_192B24 + result), 0xDu);
    qmemcpy((void *)(result + dword_192B24), v1, 0xDu);
  }
  word_19C53C = -1;
  return result;
}
// 192B24: using guessed type int dword_192B24;
// 19992E: using guessed type int16_t word_19992E;
// 19C53C: using guessed type int16_t word_19C53C;


//----- (0007585D) --------------------------------------------------------
int sub_7585D()
{
  int v0; // edx
  int16_t v1; // cx
  int16_t v2; // si
  int v3; // eax
  _WORD *v4; // ebx
  int v6; // [esp+0h] [ebp-8h]
  int16_t v7; // [esp+4h] [ebp-4h]

  v0 = 1;
  v1 = 0;
  v2 = 0;
  v7 = 0;
  while ( v2 < word_19992E && !v7 )
  {
    v3 = dword_192B24 + 13 * v2;
    if ( *(_BYTE *)(v3 + 4) )
    {
      v4 = (_WORD *)(v6 + 2 * v1++);
      *v4 = *(_WORD *)(v3 + 11);
      if ( v1 >= 250 )
      {
        v7 = 1;
        sub_7A25F(&byte_199EFE, (int)aTooManyShipsIn, 0);
        v0 = 0;
      }
    }
    ++v2;
  }
  if ( !v1 )
    return 0;
  return v0;
}
// 7588D: variable 'v6' is possibly undefined
// 192B24: using guessed type int dword_192B24;
// 19992E: using guessed type int16_t word_19992E;
// 199EFE: using guessed type char byte_199EFE;


//----- (000758D9) --------------------------------------------------------
void sub_758D9( int a1)
{
  int16_t i; // bx
  _BOOL2 v2; // [esp+0h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < word_1999F8 && !v2; ++i )
  {
    if ( i != a1 && word_1906C8[6 * i] == word_1906C8[6 * a1] )
      v2 = word_1906CA[6 * i] == word_1906CA[6 * a1];
  }
  JUMPOUT(0x7593D);
}
// 7593B: control flows out of bounds to 7593D
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 1999F8: using guessed type int16_t word_1999F8;


//----- (00075943) --------------------------------------------------------
int sub_75943( int a1)
{
  int v1; // ecx
  int result; // eax

  v1 = 13 * a1;
  memset(v1 + dword_192B24, -1, 13);
  result = dword_192B24;
  *(_BYTE *)(v1 + dword_192B24 + 4) = 0;
  return result;
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192B24: using guessed type int dword_192B24;


//----- (00075970) --------------------------------------------------------
int sub_75970( int a1, int a2)
{
  return 100 * a2 / word_17CF38[*(uint8_t *)(dword_197F9C + 129 * a1 + 16)];
}
// 17CF38: using guessed type int16_t word_17CF38[];
// 197F9C: using guessed type int dword_197F9C;


//----- (00075999) --------------------------------------------------------
int sub_75999( int a1, int a2)
{
  if ( a1 < 20 )
    return 0;
  if ( a1 < 60 )
    return 1;
  if ( a1 < 120 )
    return 2;
  if ( a1 < 500 )
    return 3;
  return a2;
}


//----- (000759D3) --------------------------------------------------------
int sub_759D3()
{
  return 30;
}


//----- (000759D9) --------------------------------------------------------
char sub_759D9( int a1)
{
  int16_t v2; // bx
  int16_t v3; // si
  int v4; // edx
  int v5; // eax
  _WORD *v6; // eax
  int16_t *v7; // eax
  int16_t v8; // di
  uint8_t *v9; // eax
  int16_t v10; // cx
  int16_t v11; // bx
  _BYTE v13[80]; // [esp+0h] [ebp-2h] BYREF
  _DWORD v14[2]; // [esp+50h] [ebp+4Eh] BYREF
  int v15; // [esp+58h] [ebp+56h]
  int v16; // [esp+5Ch] [ebp+5Ah]
  int v17; // [esp+60h] [ebp+5Eh]
  int v18; // [esp+64h] [ebp+62h]
  int v19; // [esp+68h] [ebp+66h]
  _WORD *v20; // [esp+6Ch] [ebp+6Ah]
  int v21; // [esp+70h] [ebp+6Eh]
  int v22; // [esp+74h] [ebp+72h]
  _WORD *v23; // [esp+78h] [ebp+76h]
  int v24; // [esp+7Ch] [ebp+7Ah]
  char v25; // [esp+80h] [ebp+7Eh]

  v19 = 242;
  v21 = 284;
  v24 = 240;
  v22 = 282;
  v25 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  qmemcpy(v14, "LMNO?@AB", sizeof(v14));
  while ( (int16_t)v4 < 67 && !v25 )
  {
    v5 = dword_1930DC + 59 * (int16_t)v4;
    if ( *(char *)(v5 + 58) == word_19999C && *(_BYTE *)(v5 + 57) == 1 && !*(_BYTE *)(v5 + 35) )
    {
      if ( a1 == *(_WORD *)(v5 + 53) )
      {
        v25 = 1;
        v3 = v4;
      }
      else
      {
        ++v2;
      }
    }
    ++v4;
  }
  if ( v25 )
  {
    v15 = 4 * v2;
    v6 = *(_WORD **)(v15 + dword_193108);
    LOWORD(v4) = *v6;
    v18 = v4;
    LOWORD(v6) = v6[1];
    v23 = v6;
    v7 = sub_97588(v3, 1);
    sprintf(v13, "%s", (char *)v7);
    sub_120BB5(0, (int)&byte_182078);
    v8 = v19;
    v16 = (int16_t)v21;
    sub_C5ED3((int16_t)v19 - 69, (int16_t)v21 + 3, 66, (uint16_t)v23, (int)v13, 2);
    sub_12A478(v8, v16, *(_DWORD *)(v15 + dword_193108));
    v17 = v18 + 2;
    v20 = v23 + 1;
    if ( *(char *)(dword_1930DC + 59 * v3 + 55) <= 0 )
    {
      v9 = (uint8_t *)&v14[1];
      v11 = v17;
      v10 = (_WORD)v23 + 2;
    }
    else
    {
      sub_956E2(v3, v8, v16, v18);
      v9 = (uint8_t *)v14;
      v10 = (int16_t)v20;
      v11 = v17;
    }
    sub_8F0BD(v24, v22, v11, v10, v9);
  }
  return v25;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182078: using guessed type char byte_182078;
// 1930DC: using guessed type int dword_1930DC;
// 193108: using guessed type int dword_193108;
// 19999C: using guessed type int16_t word_19999C;


//----- (00075B5F) --------------------------------------------------------
int sub_75B5F( int a1, int a2, int a3, int16_t *a4, int a5)
{
  int v5; // eax

  sub_585E0(a1, a2);
  byte_199EFA = 1;
  sub_124D41();
  v5 = sub_72F92(a5);
  sub_1077D(v5, a2, a3, a4);
  return sub_131F7B();
}
// 199EFA: using guessed type char byte_199EFA;


//----- (00075B80) --------------------------------------------------------
int16_t sub_75B80(int16_t *a1, int a2, int a3, int a4, int a5)
{
  int v6; // edx
  int16_t v7; // ax
  int16_t i; // dx
  int16_t result; // ax
  char v11; // [esp+Ch] [ebp-4h]

  if ( word_1999D8 <= -1
    || word_1999BE == word_1999D8 && word_19992A == *(_WORD *)(dword_1975C4 + 12) && word_19992A != -1 )
  {
    if ( word_19C53C > -1 && word_19992E > 1 )
    {
      v11 = 0;
      for ( i = 0; i < word_19992E && !v11; ++i )
      {
        if ( *(_WORD *)(13 * i + dword_192B24 + 11) == word_19C53C )
        {
          sub_75802(i);
          v11 = 1;
        }
      }
    }
  }
  else
  {
    word_1999BE = word_1999D8;
    word_19992A = *(_WORD *)(dword_1975C4 + 12);
    v6 = word_19992A;
    sub_7563F(word_1999D8);
    v7 = sub_77FE9(word_192248[word_1999D8]);
    sub_585E0(v7, v6);
  }
  if ( word_19992E > 0 )
  {
    byte_199EFC = word_19992E / (uint8_t)byte_199F14;
    if ( word_19992E % (int)(uint8_t)byte_199F14 > 0 )
      ++byte_199EFC;
  }
  if ( word_19992E <= 0 )
  {
    *(_WORD *)(dword_1975C4 + 12) = 0;
  }
  else
  {
    if ( *(_WORD *)(dword_1975C4 + 12) >= 0x1F4u )
      *(_WORD *)(dword_1975C4 + 12) = 0;
    sub_7545C(*(_WORD *)(dword_1975C4 + 12) * (uint8_t)byte_199F14);
  }
  if ( (uint8_t)byte_199EFC <= *(int16_t *)(dword_1975C4 + 12) )
    *(_WORD *)(dword_1975C4 + 12) = 0;
  result = (uint8_t)byte_199F14;
  *a1 = -1000;
  if ( result < word_19992E )
  {
    result = sub_115478(a2, a3, 0, a5, 0, a5, a4, a5, dword_1975C4, &unk_1792E8, 0);
    *a1 = result;
  }
  return result;
}
// 192248: using guessed type int16_t word_192248[500];
// 192B24: using guessed type int dword_192B24;
// 1975C4: using guessed type int dword_1975C4;
// 19992A: using guessed type int16_t word_19992A;
// 19992E: using guessed type int16_t word_19992E;
// 1999BE: using guessed type int16_t word_1999BE;
// 1999D8: using guessed type int16_t word_1999D8;
// 199EFC: using guessed type char byte_199EFC;
// 199F14: using guessed type char byte_199F14;
// 19C53C: using guessed type int16_t word_19C53C;


//----- (00075D48) --------------------------------------------------------
void sub_75D48( int a1)
{
  int v2; // ecx
  char *v3; // eax
  int v4; // [esp-4h] [ebp-4Eh]
  int v5[25]; // [esp+0h] [ebp-4Ah] BYREF
  int64_t v6; // [esp+64h] [ebp+1Ah]
  int v7; // [esp+6Ch] [ebp+22h]
  char v8[100]; // [esp+C8h] [ebp+7Eh] BYREF

  memset(dword_192B6C, -1, 500);
  if ( (uint16_t)sub_7585D() )
  {
    sub_FF799((int16_t *)dword_192B6C, a1, &byte_1992A8);
    if ( byte_1992AD )
    {
      sub_FFD08((int16_t *)dword_192B6C, a1, &byte_1992A8);
      sub_A0305();
      sub_77048(
        v5[0],
        v5[1],
        v5[2],
        v5[3],
        v5[4],
        v5[5],
        v5[6],
        v5[7],
        v5[8],
        v5[9],
        v5[10],
        v5[11],
        v5[12],
        v5[13],
        v5[14],
        v5[15],
        v5[16],
        v5[17],
        v5[18],
        v5[19],
        v5[20],
        v5[21],
        v5[22],
        v5[23],
        v5[24],
        v6,
        v7);
      word_1999BE = -1;
      byte_199EFE = 1;
      sub_74E04(0);
      goto LABEL_14;
    }
    if ( byte_1992A8 )
    {
      v2 = 113 * a1;
      strcpy(v8, sub_7A990(0x21u));
      sprintf(v5, "%s to %s", v8, (char *)(v2 + dword_19306C));
    }
    else if ( byte_1992AE )
    {
      if ( sub_79E32(word_19999C, a1) || sub_79E06(word_19999C) )
      {
        v4 = 113 * a1 + dword_19306C;
        v3 = sub_7A990(0x90u);
        sprintf(v5, v3, v4);
      }
      else
      {
        strcpy((char *)v5, sub_7A990(0x91u));
      }
    }
    else
    {
      if ( !byte_1992B5 )
        goto LABEL_14;
      strcpy((char *)v5, sub_7A990(0x24u));
    }
    sub_7A25F(&byte_199EFE, (int)v5, 3);
  }
LABEL_14:
  JUMPOUT(0x75B58);
}
// 75EE3: control flows out of bounds to 75B58
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192B6C: using guessed type int dword_192B6C;
// 19306C: using guessed type int dword_19306C;
// 1992A8: using guessed type char byte_1992A8;
// 1992AD: using guessed type char byte_1992AD;
// 1992AE: using guessed type char byte_1992AE;
// 1992B5: using guessed type char byte_1992B5;
// 19999C: using guessed type int16_t word_19999C;
// 1999BE: using guessed type int16_t word_1999BE;
// 199EFE: using guessed type char byte_199EFE;


//----- (00075EE8) --------------------------------------------------------
void sub_75EE8( int a1)
{
  int16_t v2; // cx
  int16_t v3; // bx
  int16_t v4; // ax
  _BYTE v5[12]; // [esp+0h] [ebp-1Ch] BYREF
  int v6; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-Ch] BYREF
  int v8; // [esp+14h] [ebp-8h] BYREF
  int v9; // [esp+18h] [ebp-4h] BYREF

  v2 = sub_78BB2(a1);
  v3 = sub_78BCF(a1);
  v4 = sub_77FE9(a1);
  sub_A432F(v2, v3, v4, &v9, &v6, &v8, &v7, (int)v5);
  sub_75FE2();
  JUMPOUT(0x7593D);
}
// 7593B: control flows out of bounds to 7593D


//----- (00075F79) --------------------------------------------------------
char sub_75F79(_WORD *a1, _WORD *a2)
{
  int16_t v3; // di
  int16_t v4; // si
  int v5; // eax
  int16_t v7; // [esp+4h] [ebp-4h]

  v3 = 0;
  v4 = 0;
  *a1 = 0;
  v7 = 0;
  *a2 = 0;
  while ( v4 < word_19992E && !v7 )
  {
    v5 = 13 * v4 + dword_192B24;
    if ( *(_BYTE *)(v5 + 4) )
    {
      if ( v3 )
      {
        if ( v3 == 1 )
        {
          v7 = 1;
          *a2 = *(_WORD *)(v5 + 11);
        }
      }
      else
      {
        *a1 = *(_WORD *)(v5 + 11);
      }
      ++v3;
    }
    ++v4;
  }
  return v7;
}
// 192B24: using guessed type int dword_192B24;
// 19992E: using guessed type int16_t word_19992E;


//----- (00075FE2) --------------------------------------------------------
int sub_75FE2()
{
  int result; // eax

  result = -1;
  if ( word_199A08 == 29 || word_19990A == 1 && word_19990C == 1 )
    return 0;
  if ( word_19990A == 1 )
    return 2;
  if ( word_19990C == 1 )
    return 1;
  return result;
}
// 19990A: using guessed type int16_t word_19990A;
// 19990C: using guessed type int16_t word_19990C;
// 199A08: using guessed type int16_t word_199A08;


//----- (00076028) --------------------------------------------------------
int sub_76028( int a1, _WORD *a2, _WORD *a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-8h]

  v4 = (uint8_t)byte_199F14;
  *a2 = 62 * (a1 % (uint8_t)byte_199F14) + word_1999A4;
  result = 60 * (a1 / v4) + word_1999A8;
  *a3 = result;
  return result;
}
// 1999A4: using guessed type int16_t word_1999A4;
// 1999A8: using guessed type int16_t word_1999A8;
// 199A08: using guessed type int16_t word_199A08;
// 199F14: using guessed type char byte_199F14;


//----- (000760D1) --------------------------------------------------------
int sub_760D1( int a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // ebx

  v4 = 129 * a1;
  LOWORD(a4) = word_17CF38[*(uint8_t *)(v4 + dword_197F9C + 16)];
  v5 = a4;
  if ( (uint16_t)sub_1276F0(v4 + dword_197F9C + 23, 0x24u)
    && !(uint16_t)sub_1276F0(v4 + dword_197F9C + 118, 0x24u) )
  {
    return 2 * a4;
  }
  return v5;
}
// 17CF38: using guessed type int16_t word_17CF38[];
// 197F9C: using guessed type int dword_197F9C;


//----- (00076127) --------------------------------------------------------
char sub_76127( int a1)
{
  int16_t v1; // dx
  uint16_t v2; // ax

  v1 = *(uint8_t *)(dword_197F9C + 129 * a1 + 17);
  v2 = sub_75FE2();
  if ( !v2 )
    return 1;
  if ( v2 <= 1u )
    return v1 == 2 || v1 == 1 || v1 == 4;
  return v2 == 2 && v1 == 0;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (000761A5) --------------------------------------------------------
void sub_761A5()
{
  int v0; // eax
  char *v1; // eax
  uint16_t v2; // ax
  char *v3; // eax
  char *v4; // esi
  uint16_t v5; // ax
  char *v6; // eax
  uint16_t v7; // ax
  int16_t v8; // ax
  int v9; // edx
  int16_t v10; // ax
  uint16_t v11; // ax
  char *v12; // eax
  char *v13; // eax
  int v14; // eax
  int v15; // esi
  int16_t v16; // di
  int v17; // eax
  uint16_t v18; // ax
  char *v19; // eax
  int v20; // [esp-Ch] [ebp-88h]
  int v21; // [esp-8h] [ebp-84h]
  int v22; // [esp-8h] [ebp-84h]
  int v23; // [esp-8h] [ebp-84h]
  int v24; // [esp-4h] [ebp-80h]
  int v25; // [esp-4h] [ebp-80h]
  int v26; // [esp-4h] [ebp-80h]
  int v27; // [esp-4h] [ebp-80h]
  int v28; // [esp-4h] [ebp-80h]
  int v29; // [esp-4h] [ebp-80h]
  char v30[80]; // [esp+0h] [ebp-7Ch] BYREF
  _BYTE v31[8]; // [esp+50h] [ebp-2Ch] BYREF
  int v32; // [esp+58h] [ebp-24h]
  int v33; // [esp+5Ch] [ebp-20h]
  int v34; // [esp+60h] [ebp-1Ch]
  int v35; // [esp+64h] [ebp-18h]
  int v36; // [esp+68h] [ebp-14h]
  int v37; // [esp+6Ch] [ebp-10h]
  char v38; // [esp+70h] [ebp-Ch]
  char v39; // [esp+74h] [ebp-8h]
  char v40; // [esp+78h] [ebp-4h]

  v34 = -1;
  v36 = -1;
  v37 = 0;
  v35 = 0;
  v32 = 3;
  v33 = 2;
  v40 = sub_79E32(word_19999C, word_199960);
  v39 = v40;
  memset(dword_192B6C, -1, 500);
  qmemcpy(v31, &byte_182078, sizeof(v31));
  v38 = 0;
  if ( (uint16_t)sub_7585D() )
  {
    v38 = 1;
    sub_FF799((int16_t *)dword_192B6C, word_199960, &byte_1992A8);
  }
  else
  {
    v0 = memset(&byte_1992A8, 0, 14);
    if ( v40
      || (v0 = word_19999C, *(_BYTE *)(3753 * word_19999C + dword_197F98 + 2234))
      || sub_94877(word_19999C)
      || sub_78F4B(word_199960) )
    {
      LOWORD(v0) = word_199960;
      v36 = 7;
      v37 = v0;
    }
    else
    {
      v36 = 8;
    }
  }
  if ( byte_1992A8 )
    goto LABEL_10;
  if ( byte_1992AA )
  {
    v36 = 4;
    goto LABEL_28;
  }
  if ( byte_1992AE )
  {
    if ( !v39 )
    {
      LOWORD(v0) = (uint8_t)byte_1992B1;
      v36 = 6;
LABEL_27:
      v37 = v0;
      goto LABEL_28;
    }
    LOWORD(v0) = (uint8_t)byte_1992B1;
    v37 = v0;
    LOWORD(v0) = word_199960;
    v36 = 5;
  }
  else
  {
    if ( byte_1992B5 )
    {
      v36 = 9;
      goto LABEL_28;
    }
    if ( !byte_1992AD )
    {
LABEL_28:
      switch ( (int16_t)v36 )
      {
        case 0:
          v24 = dword_19306C + 113 * (int16_t)v37;
          v1 = sub_7A990(0x67u);
          sprintf(v30, v1, v24);
          goto LABEL_34;
        case 1:
          v25 = 113 * (int16_t)v35 + dword_19306C;
          if ( (_WORD)v37 == 1 )
          {
            v21 = 1;
            v2 = 105;
          }
          else
          {
            v21 = (int16_t)v37;
            v2 = 106;
          }
          v3 = sub_7A990(v2);
          sprintf(v30, v3, v21, v25);
          goto LABEL_34;
        case 2:
          if ( (_WORD)v37 == 1 )
          {
            v26 = 1;
            v5 = 107;
          }
          else
          {
            v26 = (int16_t)v37;
            v5 = 108;
          }
          v6 = sub_7A990(v5);
          sprintf(v30, v6, v26);
LABEL_34:
          v4 = &byte_182078;
          goto LABEL_42;
        case 3:
          v7 = 33;
          goto LABEL_40;
        case 4:
          v7 = 110;
          goto LABEL_40;
        case 5:
          v27 = dword_19306C + 113 * (int16_t)v35;
          if ( (_WORD)v37 == 1 )
          {
            v22 = 1;
            v11 = 111;
          }
          else
          {
            v22 = (int16_t)v37;
            v11 = 112;
          }
          v12 = sub_7A990(v11);
          sprintf(v30, v12, v22, v27);
          goto LABEL_41;
        case 6:
          v28 = (int16_t)v37;
          v13 = sub_7A990(0xEBu);
          sprintf(v30, v13, v28);
          goto LABEL_41;
        case 7:
          v14 = 113 * word_199960;
          LOWORD(v14) = *(char *)(dword_19306C + v14 + 20);
          v34 = v14;
          if ( (uint16_t)v14 >= 8u )
          {
            v34 = -1;
            qmemcpy(v31, &unk_182088, sizeof(v31));
          }
          v15 = 113 * (int16_t)v37;
          v16 = *(char *)(word_19999C + v15 + dword_19306C + 66);
          if ( *(char *)(word_19999C + v15 + dword_19306C + 66) == -1 || !sub_79D1C(word_19999C, v37) )
          {
            strcpy(v30, (char *)(113 * (int16_t)v37 + dword_19306C));
          }
          else
          {
            v17 = dword_1930DC + 59 * v16;
            if ( *(char *)(v17 + 55) <= 0 )
            {
              sprintf(v30, "%s (%s)", (char *)(v15 + dword_19306C), (char *)(dword_1930DC + 59 * v16));
            }
            else
            {
              v29 = *(char *)(v17 + 55);
              v23 = dword_1930DC + 59 * v16;
              v20 = dword_19306C + v15;
              if ( *(_BYTE *)(v17 + 55) == 1 )
                v18 = 146;
              else
                v18 = 147;
              v19 = sub_7A990(v18);
              sprintf(v30, v19, v20, v23, v29);
            }
          }
          break;
        case 8:
          v7 = 148;
          goto LABEL_40;
        case 9:
          v7 = 115;
LABEL_40:
          strcpy(v30, sub_7A990(v7));
LABEL_41:
          v4 = (char *)&unk_182088;
LABEL_42:
          qmemcpy(v31, v4, sizeof(v31));
          break;
        default:
          break;
      }
      sub_8FDA1((int)v30, (int)v31, v32, v33, 0, 189, 1);
      if ( (int16_t)v34 != -1 && !v38 )
      {
        v8 = (uint8_t)byte_10010[*(uint8_t *)(dword_197F98 + 3753 * (int16_t)v34 + 38)];
        if ( v8 == 32 )
          v8 = 15;
        qmemcpy(v31, sub_8E5C5(HIWORD(dword_1B61E4), v8, v8 + 6), sizeof(v31));
        sub_8FE0A((int)v31);
      }
      v9 = 166 - (int16_t)sub_12066F((int)v30) / 2;
      v10 = sub_122259();
      sub_1212B3(v9 + 3, (21 - v10 + 2) / 2 + 248, (int)v30);
      JUMPOUT(0x75B59);
    }
    v0 = dword_19306C + 113 * word_199960;
    if ( *(_BYTE *)(v0 + 22) == 6 )
    {
LABEL_10:
      v36 = 3;
      goto LABEL_28;
    }
    LOWORD(v0) = *(char *)(v0 + 20);
    v34 = v0;
    if ( !byte_1992AC )
    {
      LOWORD(v0) = word_199960;
      v36 = 0;
      goto LABEL_27;
    }
    if ( !v39 )
    {
      LOWORD(v0) = (uint8_t)byte_1992AC;
      v36 = 2;
      goto LABEL_27;
    }
    LOWORD(v0) = (uint8_t)byte_1992AC;
    v37 = v0;
    LOWORD(v0) = word_199960;
    v36 = 1;
  }
  v35 = v0;
  goto LABEL_28;
}
// 7593E: control flows out of bounds to 75B59
// 7629F: variable 'v0' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 182078: using guessed type char byte_182078;
// 192B6C: using guessed type int dword_192B6C;
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 1992A8: using guessed type char byte_1992A8;
// 1992AA: using guessed type char byte_1992AA;
// 1992AC: using guessed type char byte_1992AC;
// 1992AD: using guessed type char byte_1992AD;
// 1992AE: using guessed type char byte_1992AE;
// 1992B1: using guessed type char byte_1992B1;
// 1992B5: using guessed type char byte_1992B5;
// 199960: using guessed type int16_t word_199960;
// 19999C: using guessed type int16_t word_19999C;
// 1B61E4: using guessed type int dword_1B61E4;


//----- (0007670E) --------------------------------------------------------
void sub_7670E( int a1)
{
  uint8_t v1; // bl
  _DWORD *v2; // esi
  int16_t v3; // cx
  _DWORD *v4; // esi
  int v5; // edx
  int16_t v6; // cx
  int16_t *v7; // eax
  int16_t v8; // ax
  int16_t v9; // cx
  int16_t v10; // cx
  char *v11; // ebx
  char *v12; // eax
  int16_t v13; // si
  char *v14; // eax
  int16_t v15; // dx
  int16_t v16; // ax
  int16_t v17; // si
  char *v18; // eax
  int16_t v19; // cx
  int v20; // eax
  int v21; // eax
  int16_t v22; // si
  char v23; // bh
  int v24; // edx
  int v25; // eax
  char v26; // bl
  _BOOL1 v27; // al
  int64_t v28; // rax
  int16_t v29; // si
  char *v30; // ebx
  char *v31; // eax
  int16_t v32; // si
  int16_t v33; // ax
  int16_t v34; // di
  int16_t v35; // cx
  int16_t v36; // dx
  char *v37; // eax
  int16_t v38; // si
  int16_t v39; // dx
  char *v40; // eax
  int16_t v41; // cx
  int16_t v42; // si
  int16_t v43; // di
  int v44; // ebx
  int v45; // eax
  int v46; // eax
  char *v47; // eax
  int16_t v48; // ax
  int16_t v49; // bx
  char *v50; // eax
  int16_t v51; // si
  int16_t v52; // di
  int16_t v53; // cx
  char *v54; // edx
  int16_t v55; // bx
  char *v56; // eax
  int v57; // [esp-4h] [ebp-C6h]
  int v58; // [esp-4h] [ebp-C6h]
  int16_t v59; // [esp+0h] [ebp-C2h]
  char v60[120]; // [esp+4h] [ebp-BEh] BYREF
  char v61[20]; // [esp+7Ch] [ebp-46h] BYREF
  char v62[20]; // [esp+90h] [ebp-32h] BYREF
  char v63[20]; // [esp+A4h] [ebp-1Eh] BYREF
  char v64[20]; // [esp+B8h] [ebp-Ah] BYREF
  char v65[20]; // [esp+CCh] [ebp+Ah] BYREF
  _BYTE v66[8]; // [esp+E0h] [ebp+1Eh] BYREF
  char v67[8]; // [esp+E8h] [ebp+26h] BYREF
  char v68[8]; // [esp+F0h] [ebp+2Eh] BYREF
  int v69; // [esp+F8h] [ebp+36h]
  int v70; // [esp+FCh] [ebp+3Ah]
  int v71; // [esp+100h] [ebp+3Eh]
  int v72; // [esp+104h] [ebp+42h]
  int16_t v73; // [esp+108h] [ebp+46h] BYREF
  int v74; // [esp+10Ch] [ebp+4Ah]
  int v75; // [esp+110h] [ebp+4Eh]
  int v76; // [esp+114h] [ebp+52h]
  int16_t v77; // [esp+118h] [ebp+56h] BYREF
  int16_t v78; // [esp+11Ch] [ebp+5Ah] BYREF
  int v79; // [esp+120h] [ebp+5Eh]
  int v80; // [esp+124h] [ebp+62h]
  int v81; // [esp+128h] [ebp+66h]
  int v82; // [esp+12Ch] [ebp+6Ah]
  int v83; // [esp+130h] [ebp+6Eh]
  _BOOL1 v84; // [esp+134h] [ebp+72h]
  _BOOL1 v85; // [esp+138h] [ebp+76h]
  _BOOL1 v86; // [esp+13Ch] [ebp+7Ah]
  char v87; // [esp+140h] [ebp+7Eh]

  v71 = a1;
  v72 = 129 * a1;
  v84 = *(_BYTE *)(v72 + dword_197F9C + 17) == 2;
  v86 = *(_BYTE *)(v72 + dword_197F9C + 17) == 1;
  v85 = *(_BYTE *)(v72 + dword_197F9C + 17) == 4;
  strcpy(v61, sub_7A990(0x95u));
  strcpy(v62, sub_7A990(0x96u));
  strcpy(v63, sub_7A990(0x97u));
  strcpy(v64, sub_7A990(0x98u));
  sub_54E5B(v71, &v78, &v77, &v73);
  if ( v84 || v86 || v85 )
  {
    v1 = *(_BYTE *)(dword_197F9C + 129 * v59 + 17);
    sub_1112EC(dword_192ED4, 10000);
    v76 = 282;
    v2 = sub_110D3C(dword_192ED4, 10000);
    v3 = 0;
    sub_110D3C(dword_192ED4, 1403);
    if ( v1 < 2u )
    {
      if ( v1 == 1 )
        v3 = 41;
    }
    else if ( v1 <= 2u )
    {
      v3 = 189;
    }
    else if ( v1 == 4 )
    {
      v3 = 109;
    }
    sub_A6547(v65);
    v4 = sub_126C37((int)v65, 0, (int)v2, v3, 1u, 1403);
    byte_199F34 = 114;
    sub_8F6F8(3u, 111, 116, v67);
    sub_120BB5(3, (int)v67);
    v5 = (int16_t)v76;
    sub_C5ED3(18, (int16_t)v76, 299, 183, (int)v4 + 103, 0);
    sub_1113CC(dword_192ED4, v5);
  }
  else
  {
    v87 = sub_759D9(v71);
    sub_120BB5(3, (int)byte_182078);
    sub_1212B3(18, 287, v72 + dword_197F9C);
    sub_120BB5(2, (int)byte_182078);
    v6 = sub_122259();
    sub_120BB5(2, (int)byte_182078);
    sub_120E8C(1);
    v57 = *(int16_t *)(v72 + dword_197F9C + 114);
    v7 = sub_753F2(v71);
    sprintf(v60, "%s (%d EP)", (char *)v7, v57);
    v6 += 2;
    sub_12066F((int)v60);
    v80 = 1;
    v83 = 18;
    sub_1212B3(18, v6 + 287, (int)v60);
    v8 = sub_122259();
    v82 = 287;
    v9 = v8 + 2 + v6;
    sub_1212B3(18, v9 + 287, *(int *)((char *)&off_17F6A1 + 59 * *(uint8_t *)(v72 + dword_197F9C + 18)));
    v10 = sub_122259() + 2 + v9;
    v11 = sub_7A990(0x99u);
    sub_1212B3(18, v10 + 287, (int)v11);
    if ( v73 < 0 )
      v12 = (char *)&unk_1792E8;
    else
      v12 = asc_17931F;
    sprintf(v60, "%s%d", v12, v73);
    sub_1210B7(v83 + 115, v10 + v82, (int)v60);
    strcpy(v60, sub_7A990(0x9Au));
    if ( v87 )
    {
      v13 = sub_12066F((int)v60);
      v10 += sub_122259() + 2;
      sub_1212B3(v83, v10 + v82, (int)v60);
      if ( v78 < 0 )
        v14 = (char *)&unk_1792E8;
      else
        v14 = asc_17931F;
      sprintf(v60, "%s%d", v14, v78);
      if ( v13 < 115 )
        v13 = 115;
      v15 = v10 + v82;
      v16 = v83 + v13;
    }
    else
    {
      v17 = sub_12066F((int)v60);
      if ( v17 + 155 < 270 )
        v17 = 115;
      sub_1212B3(v83 + 155, v10 + v82, (int)v60);
      if ( v78 < 0 )
        v18 = (char *)&unk_1792E8;
      else
        v18 = asc_17931F;
      sprintf(v60, "%s%d", v18, v78);
      v15 = v10 + v82;
      v16 = v17 + v83 + 155;
    }
    sub_1212B3(v16, v15, (int)v60);
    v19 = sub_122259() + 2 + v10;
    v20 = 129 * v59 + dword_197F9C;
    if ( *(int16_t *)(v20 + 101) >= 500 )
    {
      v21 = *(int16_t *)(v20 + 101);
      if ( v21 <= word_19999A + 1000 )
      {
        v22 = sub_78E07(v21);
        v23 = sub_79E32(word_19999C, v22);
        v24 = 0;
        do
        {
          v25 = (int16_t)v24;
          v26 = byte_182078[(int16_t)v24++] + 3;
          v66[v25] = v26;
        }
        while ( (int16_t)v24 < 8 );
        sub_120BB5(2, (int)v66);
        if ( v23
          || *(_BYTE *)(3753 * word_19999C + dword_197F98 + 2234)
          || sub_94877(word_19999C)
          || (v27 = sub_78F4B(v22)) )
        {
          v27 = 1;
        }
        WORD2(v28) = v19 + v82;
        if ( v22 == word_19999A )
        {
          v29 = v83;
          v30 = sub_7A990(0x68u);
          LOWORD(v28) = v29;
        }
        else if ( v27 )
        {
          v58 = dword_19306C + 113 * v22;
          v31 = sub_7A990(0x9Bu);
          v28 = sprintf(v60, v31, v58);
          v30 = v60;
          sub_12066F((int)v60);
          LOWORD(v28) = v83;
        }
        else
        {
          v32 = v83;
          v30 = sub_7A990(0x9Cu);
          LOWORD(v28) = v32;
        }
        sub_1212B3(v28, SWORD2(v28), (int)v30);
        sub_120BB5(2, (int)byte_182078);
      }
    }
    v33 = sub_122259();
    v34 = v83;
    v35 = v33 + 2 + v19;
    v36 = v35 + v82;
    v37 = sub_7A990(0x9Du);
    v38 = v36;
    sub_1212B3(v34, v36, (int)v37);
    v39 = v83;
    v40 = sub_7A990(0x9Eu);
    sub_1212B3(v39 + 155, v38, (int)v40);
    v41 = sub_122259() + 1 + v35;
    v79 = 0;
    sub_120BB5(1, (int)byte_182078);
    v81 = 0;
    sub_120E8C(1);
    v42 = 0;
    v43 = v41;
    v75 = v83 + 5;
    while ( v42 < 8 && !(_WORD)v79 )
    {
      v70 = 129 * v59;
      v44 = 8 * v42;
      v45 = v44 + v70 + dword_197F9C;
      if ( *(int16_t *)(v45 + 28) > -1 && *(_BYTE *)(v45 + 30) )
      {
        sub_6EFF8(*(_BYTE *)(v45 + 32), v68);
        v46 = v44 + v70 + dword_197F9C;
        if ( *(_BYTE *)(v46 + 30) == 1 )
          v47 = (char *)*(&off_17F803 + 7 * *(int16_t *)(v46 + 28));
        else
          v47 = (char *)*(&off_17F807 + 7 * *(int16_t *)(v46 + 28));
        sprintf(v60, "%d %s (%s)", *(uint8_t *)(dword_197F9C + 129 * v59 + 8 * v42 + 30), v47, v68);
        sub_1212B3(v75, v43 + v82, (int)v60);
        v48 = sub_122259();
        ++v81;
        v43 += v80 + v48;
      }
      else
      {
        v79 = 1;
      }
      ++v42;
    }
    if ( !(_WORD)v81 )
    {
      v49 = v83;
      v50 = sub_7A990(0x9Fu);
      sub_1212B3(v49 + 5, v82 + v43, (int)v50);
    }
    v51 = v41;
    v52 = 0;
    v53 = 0;
    v74 = v83 + 170;
    do
    {
      v69 = 129 * v59;
      if ( (uint16_t)sub_1276F0(v69 + dword_197F9C + 23, v53) )
      {
        if ( (uint16_t)sub_1276F0(v69 + dword_197F9C + 118, v53) )
          v54 = (char *)&unk_182080;
        else
          v54 = byte_182078;
        sub_120BB5(1, (int)v54);
        sub_120E8C(1);
        sub_1212B3(v74, v51 + v82, *(int *)((char *)&off_17EEE0 + 47 * v53));
        ++v52;
        v51 += v80 + sub_122259();
      }
      ++v53;
    }
    while ( v53 < 39 );
    if ( !v52 )
    {
      v55 = v83;
      v56 = sub_7A990(0x9Fu);
      sub_1212B3(v55 + 170, v82 + v51, (int)v56);
    }
  }
  JUMPOUT(0x75B52);
}
// 768C5: control flows out of bounds to 75B52
// 767E3: variable 'v59' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17EEE0: using guessed type _UNKNOWN *off_17EEE0;
// 17F6A1: using guessed type _UNKNOWN *off_17F6A1;
// 17F803: using guessed type _UNKNOWN *off_17F803;
// 17F807: using guessed type _UNKNOWN *off_17F807;
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 199F34: using guessed type char byte_199F34;


//----- (00076F22) --------------------------------------------------------
int sub_76F22( int a1, int a2, int16_t *a3, int16_t *a4)
{
  int16_t v4; // dx
  int v5; // esi
  int16_t i; // ax
  int v7; // edx
  int16_t j; // ax
  int16_t v12; // [esp+8h] [ebp-Ch]
  int16_t v13; // [esp+Ch] [ebp-8h]
  int16_t v14; // [esp+10h] [ebp-4h]

  v12 = (uint8_t)byte_199F14 * *(_WORD *)(dword_1975C4 + 12);
  v4 = word_19992E;
  if ( v12 + 20 <= word_19992E )
    v4 = v12 + 20;
  v5 = -1;
  v13 = 0;
  *a4 = -1;
  v14 = v4;
  *a3 = -1;
  if ( v12 < 0 || v4 < 0 )
    v13 = 1;
  for ( i = v12; i < v14 && !v13; ++i )
  {
    v7 = dword_192B24 + 13 * i;
    if ( a2 == *(_WORD *)(v7 + 9) )
    {
      v13 = 1;
      *a4 = i;
      v5 = 0;
    }
    else
    {
      if ( -*(int16_t *)(v7 + 9) != a2 )
        continue;
      v5 = 1;
      *a4 = i;
      v13 = 1;
    }
    *a3 = i;
  }
  if ( (int16_t)v5 == -1 )
  {
    for ( j = v12; j < v14 && !v13; ++j )
    {
      if ( a1 == *(_WORD *)(dword_192B24 + 13 * j + 9) )
      {
        v5 = 4;
        *a3 = j;
      }
    }
  }
  return v5;
}
// 192B24: using guessed type int dword_192B24;
// 1975C4: using guessed type int dword_1975C4;
// 19992E: using guessed type int16_t word_19992E;
// 199F14: using guessed type char byte_199F14;


//----- (00077048) --------------------------------------------------------
int sub_77048(
        int a1,
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
        int64_t a26,
        int a27)
{
  int16_t v27; // si
  int16_t v28; // ax
  int v29; // edx
  int result; // eax
  int16_t i; // si
  int16_t v32; // ax
  int v33; // edx
  int v34; // ebx
  int16_t v35; // dx
  int16_t v36; // ax
  int16_t v37; // dx
  int v38; // ecx
  int v39; // ecx
  int16_t v40; // [esp+72h] [ebp-DAh]
  int16_t v41; // [esp+76h] [ebp-D6h]
  int16_t v42; // [esp+7Ah] [ebp-D2h]
  int16_t v43; // [esp+7Eh] [ebp-CEh]
  _WORD v44[101]; // [esp+82h] [ebp-CAh] BYREF
  int v45; // [esp+1A6h] [ebp+5Ah]
  int16_t v46; // [esp+1BEh] [ebp+72h]

  v46 = sub_79917();
  v27 = 0;
  word_199992 = word_1999A0;
  while ( v27 < word_19999A )
  {
    v28 = v27;
    v29 = v27++;
    sub_911D5(v28, v43, v42, v41, v40, 0, 0, 1, &v44[v29 + 72], &v44[v29]);
  }
  result = 200000;
  for ( i = 0; i < word_1999F8; ++i )
  {
    sub_78E2D(word_1906C4[6 * i], (int16_t *)&a26 + 1);
    sub_773B7(i, (_WORD *)&a27 + 1, (_WORD *)&a26 + 3);
    if ( word_1906C6[6 * i] )
    {
      if ( word_1906C6[6 * i] == 1 )
      {
        v35 = sub_78BB2(word_1906C2[6 * i]);
        v36 = sub_78BCF(word_1906C2[6 * i]);
        *(_DWORD *)((char *)&a26 + 2) = sub_7A3E3(v35, v36);
        v34 = (int16_t)v44[SWORD1(a26) + 72] - SHIWORD(a27) / 2;
        v32 = SHIWORD(a26) / 2;
        LOWORD(v33) = v44[SWORD1(a26)] - 3;
      }
      else
      {
        if ( word_1906C6[6 * i] == 2 )
        {
          LOWORD(v34) = v44[SWORD1(a26) + 72] - HIWORD(a27);
          v37 = v44[SWORD1(a26)] - 5;
          goto LABEL_15;
        }
        if ( word_1906C6[6 * i] < 5 )
        {
          LOWORD(v34) = v44[SWORD1(a26) + 72] - HIWORD(a27);
          v37 = HIWORD(a26) + v44[SWORD1(a26)] - 5;
          goto LABEL_15;
        }
        v38 = 129 * *(int16_t *)((char *)&word_1975D4 + 5 * word_1906C2[6 * i]);
        v45 = (int16_t)sub_7926C(*(_WORD *)(v38 + dword_197F9C + 103));
        v39 = (int16_t)sub_7926C(*(_WORD *)(v38 + dword_197F9C + 105));
        sub_A1BC9(v46, &byte_192E80[v46], &byte_192ECC[v46]);
        v34 = 1000 * v45 / (506000 / v41) + v43 - SHIWORD(a27) / 2;
        v32 = SHIWORD(a26) / 2;
        v33 = 1000 * v39 / (400000 / v40) + v42;
      }
    }
    else
    {
      v32 = SHIWORD(a26) / 2;
      LOWORD(v33) = v44[SWORD1(a26)] - 3;
      LOWORD(v34) = v44[SWORD1(a26) + 72] + 4;
    }
    v37 = v33 - v32;
LABEL_15:
    result = 6 * i;
    word_1906C8[result] = v34;
    word_1906CA[result] = v37;
  }
  return result * 2;
}
// 770AE: variable 'v43' is possibly undefined
// 770AE: variable 'v42' is possibly undefined
// 770AE: variable 'v41' is possibly undefined
// 770AE: variable 'v40' is possibly undefined
// 1906C2: using guessed type int16_t word_1906C2[];
// 1906C4: using guessed type int16_t word_1906C4[];
// 1906C6: using guessed type int16_t word_1906C6[];
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 199992: using guessed type int16_t word_199992;
// 19999A: using guessed type int16_t word_19999A;
// 1999A0: using guessed type int16_t word_1999A0;
// 1999F8: using guessed type int16_t word_1999F8;


//----- (000772C4) --------------------------------------------------------
int16_t sub_772C4( int a1)
{
  _BOOL2 v2; // cx
  int16_t i; // dx
  int16_t result; // ax

  word_1999D8 = -1;
  word_199932 = -1;
  if ( sub_918D5(2) && a1 )
  {
    word_1999D8 = word_1999B8;
  }
  else if ( word_1999F8 > 0 )
  {
    v2 = 0;
    for ( i = 0; i < word_1999F8 && !v2; ++i )
    {
      if ( (uint16_t)sub_77FE9(word_1906C2[6 * i]) == word_19999C )
      {
        word_1999D8 = sub_78ABA(i);
        v2 = word_1999D8 > -1;
      }
    }
  }
  result = word_1999D8;
  if ( word_1999D8 > -1 )
  {
    word_199932 = -1;
    word_199932 = sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * word_192248[word_1999D8]));
    result = word_199932;
    word_199930 = word_199932;
  }
  return result;
}
// 1906C2: using guessed type int16_t word_1906C2[];
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 199930: using guessed type int16_t word_199930;
// 199932: using guessed type int16_t word_199932;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999D8: using guessed type int16_t word_1999D8;
// 1999F8: using guessed type int16_t word_1999F8;


//----- (00077393) --------------------------------------------------------
int sub_77393()
{
  int result; // eax
  int v1; // ebx

  for ( result = 0; (int16_t)result < word_19992E; ++result )
  {
    v1 = 13 * (int16_t)result;
    *(_BYTE *)(dword_192B24 + v1 + 4) = 0;
  }
  return result;
}
// 192B24: using guessed type int dword_192B24;
// 19992E: using guessed type int16_t word_19992E;


//----- (000773B7) --------------------------------------------------------
int16_t sub_773B7( int a1, _WORD *a2, _WORD *a3)
{
  int v3; // eax
  int v4; // ecx
  int16_t v5; // ax
  int16_t v6; // cx
  _WORD *v7; // eax
  int16_t result; // ax

  v3 = word_1906C2[6 * a1];
  v4 = 5 * v3;
  v5 = sub_77FE9(v3);
  v6 = *(int16_t *)((char *)&word_1975D4 + v4);
  if ( v5 >= 8 )
    v7 = (_WORD *)dword_192B8C[*(char *)(129 * v6 + dword_197F9C + 99) - 8];
  else
    v7 = (_WORD *)dword_18F928[*(uint8_t *)(3753 * v5 + dword_197F98 + 38)];
  *a2 = *v7;
  result = v7[1];
  *a3 = result;
  return result;
}
// 18F928: using guessed type int dword_18F928[8];
// 1906C2: using guessed type int16_t word_1906C2[];
// 192B8C: using guessed type int dword_192B8C[15];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;


//----- (00077423) --------------------------------------------------------
int16_t sub_77423(int a1)
{
  return sub_A5EBF(0, a1, 0);
}


//----- (0007743A) --------------------------------------------------------
int16_t sub_7743A(int a1)
{
  int v1; // eax
  int16_t v2; // cx
  int v3; // eax
  int v4; // ebx
  int v5; // ecx
  int v6; // edx
  int i; // eax
  int v8; // eax
  int v9; // eax
  _BYTE v12[8]; // [esp+4h] [ebp-14h] BYREF
  int v13; // [esp+Ch] [ebp-Ch]
  _BYTE v14[4]; // [esp+10h] [ebp-8h] BYREF
  _BYTE v15[4]; // [esp+14h] [ebp-4h] BYREF

  sub_77961();
  sub_120BB5(4, (int)&unk_182098);
  sub_120E24(18);
  dword_19BEDC[0] = sub_127C27((int)aWarningLbx, 0, dword_193174);
  sub_133C9C(dword_19BEDC[0], 191);
  v1 = sub_12DAA4(331, 191);
  dword_19BED4 = (int)sub_110D3C(dword_192ED4, v1);
  sub_12D8F5(331, 191, dword_19BED4);
  word_19BF06 = 144;
  word_19BF02 = sub_11438B(0, 0, 639, 479, asc_179340, 41);
  sub_120940(4, (int)v12);
  sub_120E24(18);
  v2 = 4;
  if ( (int16_t)sub_103CAF(226, a1) > 120 )
  {
    sub_120940(3, (int)v12);
    v2 = 3;
    sub_120E24(18);
  }
  sub_A64AB(1u, v15, v14);
  v13 = v2;
  qmemcpy(v12, sub_8E5C5(v2, v15[0], v14[0]), sizeof(v12));
  sub_120940(v13, (int)v12);
  sub_120E24(18);
  dword_19BEDC[0] = sub_127C27((int)aWarningLbx, 0, dword_193174);
  sub_12B7E1(154, word_19BF06, (_WORD *)dword_19BEDC[0]);
  sub_77A74(0xD0u, 232, 226, a1, 0);
  sub_124DEC();
  v3 = sub_138CEE(0, 0, 639, 479);
  sub_1077D(v3);
  v4 = 434;
  v5 = (int16_t)(word_19BF06 + 157);
  sub_12E148(208, (int16_t)(word_19BF06 + 37), 434, v5, dword_19BED4);
  v6 = 2;
  for ( i = sub_1191CA((int)sub_77860, 2); ; i = sub_12C2C6(2) )
  {
    v8 = sub_1171AB(i, v6, v4, v5);
    if ( (_WORD)v8 )
      break;
    sub_12C2A0();
    sub_77860();
    v5 = 459;
    v4 = 589;
    v6 = 20;
    v9 = sub_138CEE(5, 20, 589, 459);
    sub_1077D(v9);
  }
  return sub_779FC(v8, v6);
}
// 1077D: using guessed type int sub_1077D(_DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 19BED4: using guessed type int dword_19BED4;
// 19BEDC: using guessed type int dword_19BEDC[];
// 19BF02: using guessed type int16_t word_19BF02;
// 19BF06: using guessed type int16_t word_19BF06;


//----- (00077658) --------------------------------------------------------
void sub_77658(int a1)
{
  int16_t v1; // cx
  int16_t i; // cx
  int v3; // esi
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  _BYTE v11[8]; // [esp+4h] [ebp-1Ch] BYREF
  int v12; // [esp+Ch] [ebp-14h]
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  _BYTE v15[4]; // [esp+18h] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+1Ch] [ebp-4h] BYREF

  sub_A64AB(2u, v15, v16);
  qmemcpy(v11, sub_8E5C5(4u, v15[0], v16[0]), sizeof(v11));
  sub_120940(4, (int)v11);
  sub_77961();
  v1 = 0;
  while ( 1 )
  {
    dword_19BEDC[v1] = sub_127C27((int)aConfirmLbx, v1, dword_193174);
    if ( !v1 )
      sub_133C9C(dword_19BEDC[0], 0);
    if ( ++v1 >= 3 )
    {
      word_19BF02 = sub_11438B(235, 302, 286, 323, aY, 41);
      v13 = sub_11438B(345, 302, 396, 323, aN, 41);
      for ( i = 0; i < 3; ++i )
      {
        v3 = i;
        v4 = sub_127C27((int)aConfirmLbx, i, dword_193174);
        dword_19BEDC[v3] = v4;
      }
      v14 = 4;
      sub_12B7E1(161, 117, (_WORD *)dword_19BEDC[0]);
      do
      {
        sub_A64AB(2u, v15, v16);
        v12 = (int16_t)v14;
        qmemcpy(v11, sub_8E5C5(v14, v15[0], v16[0]), sizeof(v11));
        sub_120940(v12, (int)v11);
        sub_120E24(18);
        --v14;
      }
      while ( (int16_t)sub_103CAF(224, a1) > 126 && (int16_t)v14 > 1 );
      sub_77A74(0xCCu, 208, 224, a1, 0);
      sub_778E4();
      sub_124DEC();
      v5 = 479;
      v6 = sub_138CEE(0, 0, 639, 479);
      sub_1077D(v6);
      sub_1191CA((int)sub_778E4, 2);
      while ( 1 )
      {
        sub_12C2A0();
        v8 = sub_1171AB(v7, 2, 639, v5);
        v5 = v8;
        if ( !(_WORD)v8 )
          sub_1077D(v8);
        v9 = sub_12C2C6(2);
        if ( (_WORD)v5 == word_19BF02 || (_WORD)v5 == (_WORD)v13 )
        {
          sub_779FC(v9, 2);
          word_19994C = 1;
          JUMPOUT(0x77651);
        }
      }
    }
  }
}
// 7785B: control flows out of bounds to 77651
// 77815: variable 'v7' is possibly undefined
// 1077D: using guessed type int sub_1077D(_DWORD);
// 193174: using guessed type int dword_193174;
// 19994C: using guessed type int16_t word_19994C;
// 19BEDC: using guessed type int dword_19BEDC[];
// 19BF02: using guessed type int16_t word_19BF02;


//----- (00077860) --------------------------------------------------------
int sub_77860()
{
  int16_t v0; // si
  int16_t v1; // si

  v0 = word_19BF06;
  sub_12B753(dword_19BEDC[0], word_19BEFE);
  v1 = v0 + 37;
  if ( !word_19BEFE )
    word_19BF04 = 1;
  if ( word_19BEFE == 6 )
    word_19BF04 = -1;
  word_19BEFE += word_19BF04;
  sub_12B7E1(154, word_19BF06, (_WORD *)dword_19BEDC[0]);
  return sub_12A478(208, v1, dword_19BED4);
}
// 19BED4: using guessed type int dword_19BED4;
// 19BEDC: using guessed type int dword_19BEDC[];
// 19BEFE: using guessed type int16_t word_19BEFE;
// 19BF04: using guessed type int16_t word_19BF04;
// 19BF06: using guessed type int16_t word_19BF06;


//----- (000778E4) --------------------------------------------------------
int sub_778E4()
{
  int16_t v0; // ax
  int v1; // eax

  sub_12B753(dword_19BEE0, 0);
  sub_12B753(dword_19BEE4, 0);
  v0 = sub_113F8C();
  if ( v0 == word_19BF02 )
  {
    v1 = dword_19BEE0;
LABEL_5:
    sub_12B753(v1, 1);
    goto LABEL_6;
  }
  if ( v0 == word_19BF02 + 1 )
  {
    v1 = dword_19BEE4;
    goto LABEL_5;
  }
LABEL_6:
  sub_12B7E1(235, 302, (_WORD *)dword_19BEE0);
  return sub_12B7E1(345, 302, (_WORD *)dword_19BEE4);
}
// 19BEE0: using guessed type int dword_19BEE0;
// 19BEE4: using guessed type int dword_19BEE4;
// 19BF02: using guessed type int16_t word_19BF02;


//----- (00077961) --------------------------------------------------------
void sub_77961()
{
  sub_7A795();
  sub_123E6C((int)&unk_17CF00, 1);
  sub_C5C44();
  sub_1112EC(dword_192ED4, 1);
  sub_107AF(&dword_19BED8);
  word_19BEFA = word_1844D8;
  word_1844D8 = 0;
  sub_107C2(&dword_19BED8);
  word_19BEFC = dword_1844E6;
  sub_1172FC();
  sub_11E718();
  sub_1172D4();
  sub_10FE41((int)&unk_19BEE8);
  sub_124D41();
  word_19BF00 = sub_124C3B();
  sub_124C08();
  word_19BEFE = 0;
  word_19BF04 = 1;
}
// 1844D8: using guessed type int16_t word_1844D8;
// 1844E6: using guessed type int dword_1844E6;
// 192ED4: using guessed type int dword_192ED4;
// 19BED8: using guessed type int (*dword_19BED8)(void);
// 19BEFA: using guessed type int16_t word_19BEFA;
// 19BEFC: using guessed type int16_t word_19BEFC;
// 19BEFE: using guessed type int16_t word_19BEFE;
// 19BF00: using guessed type int16_t word_19BF00;
// 19BF04: using guessed type int16_t word_19BF04;


//----- (000779FC) --------------------------------------------------------
int16_t sub_779FC(int a1, int a2)
{
  sub_10FEC1((int)&unk_19BEE8);
  sub_107BA((int *)&dword_19BED8);
  sub_1113CC(dword_192ED4, a2);
  if ( (uint16_t)word_19BF00 < 2u )
  {
    if ( !word_19BF00 )
      sub_124B65();
  }
  else if ( (uint16_t)word_19BF00 <= 2u )
  {
    sub_124C9B();
  }
  else if ( word_19BF00 == 3 )
  {
    sub_124C08();
  }
  LOWORD(dword_1844E6) = word_19BEFC;
  word_1844D8 = word_19BEFA;
  sub_119441();
  sub_117174(3);
  return sub_7A7CF();
}
// 1844D8: using guessed type int16_t word_1844D8;
// 1844E6: using guessed type int dword_1844E6;
// 192ED4: using guessed type int dword_192ED4;
// 19BED8: using guessed type int (*dword_19BED8)(void);
// 19BEFA: using guessed type int16_t word_19BEFA;
// 19BEFC: using guessed type int16_t word_19BEFC;
// 19BF00: using guessed type int16_t word_19BF00;


//----- (00077A74) --------------------------------------------------------
int sub_77A74( unsigned int a1, int a2, int a3, int a4, int a5)
{
  int16_t v6; // ax
  int v7; // esi

  v6 = word_1B3EA0;
  v7 = a2 - ((int16_t)sub_103CAF(a3, a4) - v6) / 2;
  if ( a5 )
    return sub_103BE2(a1, v7, a3, a4, 2, a5);
  else
    return sub_103BC4(a1, v7, a3, a4, 2);
}
// 1B3EA0: using guessed type int16_t word_1B3EA0;


//----- (00077AE6) --------------------------------------------------------
int16_t *sub_77AE6( int a1, int a2)
{
  word_18FF78 = word_179354;
  strcpy((char *)&word_18FF78, (char *)(dword_197F98 + 3753 * a1 + 806 + 99 * a2));
  return &word_18FF78;
}
// 179354: using guessed type int16_t word_179354;
// 18FF78: using guessed type int16_t word_18FF78;
// 197F98: using guessed type int dword_197F98;


//----- (00077B28) --------------------------------------------------------
int16_t *sub_77B28( int a1)
{
  sub_77E1F(a1, (char *)&word_18FF78, 1);
  return &word_18FF78;
}
// 18FF78: using guessed type int16_t word_18FF78;


//----- (00077B42) --------------------------------------------------------
void sub_77B42()
{
  JUMPOUT(0x77B35);
}
// 77B4C: control flows out of bounds to 77B35


//----- (00077B4E) --------------------------------------------------------
int sub_77B4E()
{
  int result; // eax
  int v1; // edx
  int16_t i; // bx
  unsigned int v3; // edx

  result = 0;
  do
  {
    v1 = (int16_t)result++;
    byte_199E44[v1] = 0;
  }
  while ( (int16_t)result < 63 );
  if ( word_199A02 > 0 )
  {
    for ( i = 0; i < word_199BB8; ++i )
    {
      v3 = *(int16_t *)((char *)&word_1975D4 + 5 * *(int16_t *)((char *)&word_197FC3 + 9 * i));
      result = sub_127712((int)byte_199E44, v3);
    }
  }
  return result;
}
// 1975D4: using guessed type int16_t word_1975D4;
// 197FC3: using guessed type int16_t word_197FC3;
// 199A02: using guessed type int16_t word_199A02;
// 199BB8: using guessed type int16_t word_199BB8;


//----- (00077BB1) --------------------------------------------------------
int sub_77BB1(int result)
{
  int16_t v1; // bx
  int16_t i; // dx

  v1 = result;
  for ( i = 0; i < word_19999A; ++i )
  {
    result = 2 * v1 + dword_19306C + 113 * i;
    if ( *(int16_t *)(result + 84) != -1 )
      *(_WORD *)(result + 84) = -1;
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (00077BF1) --------------------------------------------------------
int sub_77BF1()
{
  int result; // eax
  int v1; // edx

  result = 0;
  do
  {
    v1 = (int16_t)result++;
    byte_199E05[v1] = 0;
  }
  while ( (int16_t)result < 63 );
  return result;
}


//----- (00077C07) --------------------------------------------------------
int sub_77C07( int a1, int a2)
{
  int result; // eax

  result = 113 * a1 + dword_19306C;
  *(_WORD *)(result + 2 * a2 + 84) = -1;
  return result;
}
// 19306C: using guessed type int dword_19306C;


//----- (00077C59) --------------------------------------------------------
char sub_77C59( int a1, int a2)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 99 * a2 + 828);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077C78) --------------------------------------------------------
char sub_77C78( int a1, int a2)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 99 * a2 + 827);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077C97) --------------------------------------------------------
char sub_77C97( int a1, int a2)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 99 * a2 + 900);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077CB6) --------------------------------------------------------
char sub_77CB6( int a1, int a2)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 99 * a2 + 825);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077CD5) --------------------------------------------------------
char sub_77CD5( int a1, int a2)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 99 * a2 + 898);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077CF4) --------------------------------------------------------
char sub_77CF4( int a1, int a2)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 99 * a2 + 824);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077D13) --------------------------------------------------------
char sub_77D13( int a1, int a2)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 99 * a2 + 822);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077D32) --------------------------------------------------------
int16_t sub_77D32( int a1, int a2)
{
  _BYTE v3[100]; // [esp-64h] [ebp-70h] BYREF

  qmemcpy(v3, (void *)(99 * a2 + 3753 * a1 + dword_197F98 + 806), 0x63u);
  return sub_582BF(
           *(int *)v3,
           *(int *)&v3[4],
           *(int *)&v3[8],
           *(int *)&v3[12],
           v3[16],
           *(int *)&v3[20],
           *(int *)&v3[24],
           *(int *)&v3[28],
           *(int *)&v3[32],
           *(int *)&v3[36],
           *(int *)&v3[40],
           *(int *)&v3[44],
           *(int *)&v3[48],
           *(int *)&v3[52],
           *(int *)&v3[56],
           *(int *)&v3[60],
           *(int *)&v3[64],
           *(int *)&v3[68],
           *(int *)&v3[72],
           *(int *)&v3[76],
           *(int *)&v3[80],
           *(int *)&v3[84],
           *(int *)&v3[88],
           *(int *)&v3[92],
           *(int *)&v3[96]);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077D69) --------------------------------------------------------
int16_t sub_77D69( int a1, int a2, int a3)
{
  return *(_WORD *)(3753 * a1 + dword_197F98 + 99 * a2 + 8 * a3 + 834);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077D8E) --------------------------------------------------------
char sub_77D8E( int a1, int a2, int a3)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 99 * a2 + 8 * a3 + 841);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077DB2) --------------------------------------------------------
char sub_77DB2( int a1, int a2, int a3)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 99 * a2 + 8 * a3 + 836);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077DD6) --------------------------------------------------------
char sub_77DD6( int a1, int a2, int a3)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 99 * a2 + 8 * a3 + 838);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077DFA) --------------------------------------------------------
int16_t sub_77DFA( int a1, int a2, int a3)
{
  return *(_WORD *)(3753 * a1 + dword_197F98 + 99 * a2 + 8 * a3 + 839);
}
// 197F98: using guessed type int dword_197F98;


//----- (00077E1F) --------------------------------------------------------
char sub_77E1F( int a1, char *a2, int a3)
{
  int16_t v3; // si
  uint8_t v4; // al
  int v5; // ebx
  char *v6; // eax
  char result; // al
  char v8[30]; // [esp+0h] [ebp-4Ah] BYREF
  char v9; // [esp+1Eh] [ebp-2Ch]
  char *v10; // [esp+C8h] [ebp+7Eh]

  v10 = a2;
  *(_WORD *)v8 = word_179354;
  v3 = *(uint8_t *)(dword_1930D4 + 17 * a1 + 2);
  sub_79C6B(a1);
  if ( a3 )
  {
    v5 = v4;
    if ( !strcmp(off_17D5E4[v5], &unk_179356) )
      v6 = sub_7A990(0xA0u);
    else
      v6 = off_17D5E4[v5];
    sprintf(v8, "%s %s", (char *)(dword_19306C + 113 * v3), v6);
  }
  else
  {
    sprintf(v8, "%s %s", (char *)(113 * v3 + dword_19306C), off_17D5E4[v4]);
  }
  if ( strlen(v8) > 0x1E )
    v9 = 0;
  strcpy(v10, v8);
  return result;
}
// 77E58: variable 'v4' is possibly undefined
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 138B90: using guessed type int strcmp(_DWORD, _DWORD);
// 179354: using guessed type int16_t word_179354;
// 17D5E4: using guessed type char *off_17D5E4[20];
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (00077EED) --------------------------------------------------------
_BOOL1 sub_77EED()
{
  _BOOL1 v0; // cl
  int16_t i; // bx
  int v2; // edx
  int16_t v3; // ax

  v0 = 0;
  for ( i = 0; i < word_199A02 && !v0; ++i )
  {
    v2 = *(int16_t *)((char *)&word_1975D4 + 5 * word_192248[i]);
    if ( sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * word_192248[i])) != word_19999C )
    {
      v3 = sub_78E07(*(int16_t *)(129 * v2 + dword_197F9C + 101));
      v0 = sub_79D1C(word_19999C, v3);
    }
  }
  return v0;
}
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 199A02: using guessed type int16_t word_199A02;


//----- (00077F5D) --------------------------------------------------------
char sub_77F5D( int a1)
{
  return byte_1975D8[5 * *(int16_t *)((char *)&word_197FC3 + 9 * a1)];
}
// 197FC3: using guessed type int16_t word_197FC3;


//----- (00077F73) --------------------------------------------------------
int sub_77F73( int a1)
{
  int v1; // ecx
  char v2; // dl
  int i; // eax
  int16_t v4; // bx
  int16_t v6; // [esp+0h] [ebp-4h]

  v1 = 0;
  v2 = 0;
  v6 = *(int16_t *)((char *)&word_197FC3 + 9 * a1);
  for ( i = 0; (int16_t)i < word_199A02 && !v2; ++i )
  {
    v4 = word_192248[(int16_t)i];
    do
    {
      if ( v4 == v6 )
      {
        v2 = 1;
        v1 = i;
      }
      else if ( v4 != -1 )
      {
        v4 = *(int16_t *)((char *)&word_1975D6 + 5 * v4);
      }
    }
    while ( v4 > -1 && !v2 );
  }
  return v1;
}
// 192248: using guessed type int16_t word_192248[500];
// 1975D6: using guessed type int16_t word_1975D6;
// 197FC3: using guessed type int16_t word_197FC3;
// 199A02: using guessed type int16_t word_199A02;


//----- (00077FE9) --------------------------------------------------------
int sub_77FE9( int a1)
{
  return sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * a1));
}
// 77FF5: using guessed type int sub_77FF5(_DWORD);
// 1975D4: using guessed type int16_t word_1975D4;


//----- (00077FF5) --------------------------------------------------------
int16_t sub_77FF5( int a1)
{
  int16_t v2; // ax
  int v3; // edx
  int v5; // edx
  char v6[200]; // [esp+0h] [ebp-C8h] BYREF

  v2 = 0;
  if ( a1 >= 0 )
  {
    if ( a1 < 500 )
    {
      v3 = dword_197F9C + 129 * a1;
      if ( *(char *)(v3 + 99) >= 0 )
      {
        if ( *(char *)(v3 + 99) > 15 )
          v2 = 4;
      }
      else
      {
        v2 = 3;
      }
    }
    else
    {
      v2 = 2;
    }
  }
  else
  {
    v2 = 1;
  }
  if ( v2 )
  {
    v5 = *(char *)(129 * a1 + dword_197F9C + 99);
    sprintf(v6, "Memory Corruption! val == %d, ship_id == %d, owner == %d stardate = %ld\n", v2, a1, v5, dword_192FD8);
    sub_126487(v6, v5);
  }
  return *(char *)(dword_197F9C + 129 * a1 + 99);
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 192FD8: using guessed type int dword_192FD8;
// 197F9C: using guessed type int dword_197F9C;


//----- (00078013) --------------------------------------------------------
int16_t sub_78013( int a1)
{
  return *(int16_t *)((char *)&word_1975D4 + 5 * *(int16_t *)((char *)&word_197FC3 + 9 * a1));
}
// 1975D4: using guessed type int16_t word_1975D4;
// 197FC3: using guessed type int16_t word_197FC3;


//----- (0007802A) --------------------------------------------------------
int sub_7802A(int a1, int a2)
{
  int v3; // ecx
  int16_t i; // dx
  char v5; // zf
  int v6; // eax
  int16_t v8; // [esp+0h] [ebp-8h]
  _BOOL1 v9; // [esp+4h] [ebp-4h]

  v9 = 0;
  v3 = 0;
  memset(a1, -1, 2 * a2);
  for ( i = 0; i < 500 && !v9; ++i )
  {
    v8 = *(int16_t *)((char *)&word_1975D4 + 5 * i);
    sub_169169((int)byte_1975D8, i);
    if ( !v5 )
    {
      v6 = (int16_t)v3++;
      *(_WORD *)(a1 + 2 * v6) = v8;
      v9 = (int16_t)v3 > 500;
    }
  }
  return v3;
}
// 780A6: variable 'v5' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;


//----- (000780D3) --------------------------------------------------------
_BOOL1 sub_780D3()
{
  int16_t v0; // bx
  int16_t v1; // cx
  char v3; // [esp+0h] [ebp-8h]
  char v4; // [esp+4h] [ebp-4h]

  v4 = 0;
  v3 = 0;
  word_1999B8 = -1;
  v0 = 0;
  while ( !v3 && !v4 )
  {
    v1 = word_192248[v0];
    do
    {
      if ( (uint16_t)sub_1276F0((int)byte_199E44, *(int16_t *)((char *)&word_1975D4 + 5 * v1)) )
      {
        v3 = 1;
        word_1999B8 = v0;
      }
      v1 = *(int16_t *)((char *)&word_1975D6 + 5 * v1);
    }
    while ( v1 != -1 && !v3 );
    if ( ++v0 >= word_199A02 )
      v4 = 1;
  }
  return word_1999B8 > -1 && word_1999B8 < word_199A02;
}
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 1999B8: using guessed type int16_t word_1999B8;
// 199A02: using guessed type int16_t word_199A02;


//----- (00078182) --------------------------------------------------------
_BOOL1 sub_78182( int a1)
{
  return (uint16_t)*(uint8_t *)(dword_197F9C + 129 * a1 + 17) == 0;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (0007819E) --------------------------------------------------------
int sub_7819E( int a1, int a2)
{
  int v4; // esi
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v9; // [esp+4h] [ebp-4h] BYREF

  v4 = 113 * a1 + dword_19306C;
  v5 = v4 + a2;
  v9 = -1;
  v6 = -1;
  if ( *(char *)(v5 + 23) > -1 && *(char *)(v5 + 23) < 5 )
  {
    v7 = v4 + 2 * *(char *)(v5 + 23);
    LOWORD(v7) = *(_WORD *)(v7 + 74);
    v9 = v7;
  }
  if ( (int16_t)v9 > -1 && (int16_t)v9 < word_1999A2 )
  {
    HIWORD(v6) = HIWORD(dword_1930D4);
    LOWORD(v6) = *(_WORD *)(dword_1930D4 + 17 * (int16_t)v9);
  }
  if ( (int16_t)v6 == -1 || *(char *)(dword_192B18 + 361 * (int16_t)v6) != a2 )
  {
    sub_7862B(a1, a2, &v9);
    if ( (int16_t)v9 <= -1 || (int16_t)v9 >= word_1999A2 )
    {
      return -1;
    }
    else
    {
      HIWORD(v6) = HIWORD(dword_1930D4);
      LOWORD(v6) = *(_WORD *)(dword_1930D4 + 17 * (int16_t)v9);
    }
  }
  return v6;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1999A2: using guessed type int16_t word_1999A2;


//----- (0007826A) --------------------------------------------------------
char sub_7826A( int a1, int a2)
{
  char v4; // bl
  int16_t i; // dx
  int v6; // eax
  int v7; // eax
  char *v8; // eax

  v4 = 0;
  for ( i = 0; i < 5; ++i )
  {
    v6 = *(int16_t *)(dword_19306C + 113 * a1 + 2 * i + 74);
    if ( v6 > -1 )
    {
      v7 = *(int16_t *)(17 * v6 + dword_1930D4);
      if ( v7 != -1 )
      {
        v8 = (char *)(361 * v7 + dword_192B18);
        if ( !v8[6] && (*v8 == a2 || a2 == -1) )
          ++v4;
      }
    }
  }
  return v4;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000782ED) --------------------------------------------------------
char sub_782ED( int a1)
{
  char v2; // dl
  int16_t i; // ax

  v2 = 0;
  for ( i = 0; i < word_19999A; ++i )
  {
    if ( *(int16_t *)(dword_19306C + 113 * i + 2 * a1 + 84) != -1 )
      ++v2;
  }
  return v2;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (0007832B) --------------------------------------------------------
int sub_7832B( int a1, int a2)
{
  char v3; // dl
  int i; // eax

  v3 = 0;
  for ( i = 0; (int16_t)i < 500 && !v3; ++i )
  {
    if ( a1 == *(int16_t *)((char *)&word_1975D4 + 5 * (int16_t)i) )
    {
      v3 = 1;
      a2 = i;
    }
  }
  if ( v3 )
    return a2;
  else
    return -1;
}
// 1975D4: using guessed type int16_t word_1975D4;


//----- (0007836A) --------------------------------------------------------
void sub_7836A( int a1)
{
  if ( word_199A02 )
  {
    if ( a1 <= word_199A02 )
    {
      if ( a1 == word_199A02 )
        sub_789D4();
    }
    else
    {
      sub_91A40();
    }
  }
}
// 199A02: using guessed type int16_t word_199A02;


//----- (00078398) --------------------------------------------------------
char sub_78398()
{
  char v0; // bl
  int16_t i; // dx
  int v2; // eax
  int16_t *v3; // eax
  int v4; // eax

  v0 = -1;
  for ( i = 0; i < 5; ++i )
  {
    v2 = *(int16_t *)(dword_19306C + 2 * i + 74);
    if ( v2 != -1 )
    {
      v3 = (int16_t *)(dword_1930D4 + 17 * v2);
      if ( *((_BYTE *)v3 + 4) == 3 )
      {
        v4 = *v3;
        if ( v4 != -1 )
          return *(_BYTE *)(dword_192B18 + 361 * v4);
      }
    }
  }
  return v0;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000783ED) --------------------------------------------------------
int16_t sub_783ED( int a1)
{
  return *(uint8_t *)(17 * a1 + dword_1930D4 + 3);
}
// 1930D4: using guessed type int dword_1930D4;


//----- (0007843D) --------------------------------------------------------
char sub_7843D( int a1, int a2)
{
  if ( *(char *)(a2 + 99) == a1 )
    return sub_FF6BE(a2);
  else
    return 0;
}


//----- (00078457) --------------------------------------------------------
_BOOL1 sub_78457( int a1, int a2)
{
  return *(_BYTE *)(3753 * a2 + dword_197F98 + a1 + 279) == 3;
}
// 197F98: using guessed type int dword_197F98;


//----- (00078477) --------------------------------------------------------
int16_t *sub_78477( int a1)
{
  char v2[20]; // [esp+0h] [ebp-14h] BYREF

  sub_784A0(a1, v2);
  strcpy((char *)&word_18FF78, v2);
  return &word_18FF78;
}
// 18FF78: using guessed type int16_t word_18FF78;


//----- (000784A0) --------------------------------------------------------
char sub_784A0( int a1, char *a2)
{
  char *v2; // edi
  char *v3; // esi
  char result; // al

  strcpy(a2, "Human");
  if ( a1 >= 8 )
  {
    if ( a1 == 8 )
    {
      v3 = (char *)dword_192664;
      v2 = a2;
    }
    else
    {
      v2 = a2;
      v3 = (char *)dword_192630[(int16_t)(a1 + 5)];
    }
  }
  else
  {
    v2 = a2;
    v3 = (char *)(3753 * a1 + dword_197F98 + 21);
  }
  strcpy(v2, v3);
  return result;
}
// 192630: using guessed type int dword_192630[];
// 192664: using guessed type int dword_192664;
// 197F98: using guessed type int dword_197F98;


//----- (000784F0) --------------------------------------------------------
int16_t sub_784F0( int a1, int a2)
{
  return *(_WORD *)(113 * a1 + dword_19306C + 2 * a2 + 84);
}
// 19306C: using guessed type int dword_19306C;


//----- (00078507) --------------------------------------------------------
void sub_78507()
{
  int16_t i; // dx
  int v1; // eax
  _BOOL1 v2; // cl
  int16_t j; // bx
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int16_t *v7; // eax
  char *v8; // eax
  int16_t v9; // ax

  for ( i = 0; i < word_19999A; ++i )
  {
    v1 = *(char *)(word_19999C + dword_19306C + 113 * i + 23);
    v2 = 0;
    if ( v1 != -1 )
      v2 = *(_WORD *)(dword_1930D4 + 17 * v1) == (uint16_t)word_19999C;
    for ( j = 0; j < 5 && !v2; ++j )
    {
      v4 = dword_19306C + 113 * i;
      v5 = v4 + 2 * j;
      if ( *(int16_t *)(v5 + 74) > -1 )
      {
        v6 = *(int16_t *)(v5 + 74);
        if ( v6 > -1 )
        {
          v7 = (int16_t *)(17 * v6 + dword_1930D4);
          if ( *v7 > -1 )
          {
            v8 = (char *)(dword_192B18 + 361 * *v7);
            if ( !v8[6] )
            {
              v9 = *v8;
              if ( v9 == word_19999C )
                *(_BYTE *)(v4 + v9 + 23) = j;
              else
                *(_BYTE *)(v4 + word_19999C + 23) = -1;
            }
          }
        }
      }
    }
  }
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;


//----- (000785EC) --------------------------------------------------------
int sub_785EC(int result, int a2)
{
  int16_t v2; // bx
  int16_t i; // dx

  v2 = result;
  for ( i = 0; i < word_19999A; ++i )
  {
    result = dword_19306C + 113 * i + 2 * a2;
    if ( *(int16_t *)(result + 84) != -1 )
      *(_WORD *)(result + 84) = v2;
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (0007862B) --------------------------------------------------------
int sub_7862B(int a1, int a2, _WORD *a3)
{
  int16_t v4; // si
  int16_t v5; // dx
  int v6; // eax
  int16_t v7; // ax
  int16_t *v8; // eax
  char *v9; // eax
  int result; // eax
  int16_t v11; // [esp+0h] [ebp-10h]
  int v12; // [esp+4h] [ebp-Ch]
  char v13; // [esp+Ch] [ebp-4h]

  v13 = 0;
  v4 = -1;
  v5 = 0;
  *a3 = -1;
  while ( v5 < 5 && !v13 )
  {
    v6 = dword_19306C + 113 * v11 + 2 * v5;
    v12 = dword_19306C + 113 * v11;
    if ( *(int16_t *)(v6 + 74) > -1 )
    {
      v7 = *(_WORD *)(v6 + 74);
      *a3 = v7;
      if ( v7 > -1 )
      {
        v8 = (int16_t *)(dword_1930D4 + 17 * v7);
        if ( *v8 > -1 )
        {
          v4 = *v8;
          v9 = (char *)(dword_192B18 + 361 * *v8);
          if ( v9[6] || *v9 != a2 )
          {
            v4 = -1;
          }
          else
          {
            v13 = 1;
            *(_BYTE *)(v12 + a2 + 23) = v5;
          }
        }
      }
    }
    ++v5;
  }
  result = v4;
  if ( v4 == -1 )
    *a3 = -1;
  return result;
}
// 78648: variable 'v11' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000786E9) --------------------------------------------------------
int sub_786E9( int a1, int a2)
{
  int result; // eax
  int v3; // ebx

  result = 361 * a1 + dword_192B18;
  if ( !*(_BYTE *)(result + 6) )
  {
    v3 = 17 * *(int16_t *)(result + 2);
    result = 113 * *(uint8_t *)(v3 + dword_1930D4 + 2) + dword_19306C;
    *(_BYTE *)(a2 + result + 23) = *(_BYTE *)(v3 + dword_1930D4 + 3);
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0007872E) --------------------------------------------------------
int sub_7872E( int a1)
{
  int result; // eax

  if ( sub_918D5(2) )
  {
    result = a1;
    word_19C0E6[4 * a1] = *(int16_t *)((char *)&word_1975D4 + 5 * word_197FC3);
  }
  else
  {
    result = a1;
    word_19C0E6[4 * a1] = -1;
  }
  return result;
}
// 1975D4: using guessed type int16_t word_1975D4;
// 197FC3: using guessed type int16_t word_197FC3;
// 19C0E6: using guessed type int16_t word_19C0E6[29];


//----- (00078770) --------------------------------------------------------
int16_t sub_78770( int a1)
{
  int v2; // edx
  int16_t v3; // ax
  int16_t result; // ax

  v2 = word_19C0E6[4 * a1];
  sub_8A4C4();
  if ( v2 > -1 && sub_77FF5(v2) == a1 && *(char *)(dword_197F9C + 129 * v2 + 100) < 3 )
  {
    sub_78B0E(v2);
    word_1999B8 = v3;
  }
  else
  {
    word_1999B8 = -1;
  }
  result = word_1999B8;
  if ( word_1999B8 == -1 )
  {
    sub_91A40();
    result = word_1992C4;
    byte_199BD5 = 0;
    word_199BD3 = word_1992C4;
  }
  return result;
}
// 787B2: variable 'v3' is possibly undefined
// 197F9C: using guessed type int dword_197F9C;
// 1992C4: using guessed type int16_t word_1992C4;
// 1999B8: using guessed type int16_t word_1999B8;
// 199BD3: using guessed type int16_t word_199BD3;
// 199BD5: using guessed type char byte_199BD5;
// 19C0E6: using guessed type int16_t word_19C0E6[29];


//----- (000787EA) --------------------------------------------------------
int sub_787EA( int a1, int a2, int a3)
{
  int result; // eax

  result = 113 * a1 + dword_19306C;
  *(_WORD *)(result + 2 * a2 + 84) = a3;
  return result;
}
// 19306C: using guessed type int dword_19306C;


//----- (00078800) --------------------------------------------------------
void sub_78800( int a1)
{
  int16_t v2; // cx
  int16_t i; // ax
  int16_t v4; // dx

  v2 = 0;
  for ( i = 0; i < word_1999F8 && !v2; ++i )
  {
    v4 = word_1906C2[6 * i];
    if ( v4 == a1 )
    {
      v2 = 1;
    }
    else
    {
      while ( !v2 && v4 != -1 )
      {
        v4 = *(int16_t *)((char *)&word_1975D6 + 5 * v4);
        if ( v4 == a1 )
        {
          v2 = 1;
        }
        else if ( v4 != -1 )
        {
          v4 = *(int16_t *)((char *)&word_1975D6 + 5 * v4);
        }
      }
    }
  }
  JUMPOUT(0x785E6);
}
// 78874: control flows out of bounds to 785E6
// 1906C2: using guessed type int16_t word_1906C2[];
// 1975D6: using guessed type int16_t word_1975D6;
// 1999F8: using guessed type int16_t word_1999F8;


//----- (00078879) --------------------------------------------------------
int sub_78879( int a1)
{
  return sub_77FE9(word_1906C2[6 * a1]);
}
// 1906C2: using guessed type int16_t word_1906C2[];


//----- (00078889) --------------------------------------------------------
int16_t sub_78889( int a1)
{
  int16_t v1; // ax

  v1 = word_1906C2[6 * a1];
  if ( (uint16_t)v1 < 0x1F4u )
    return sub_788A2(v1);
  else
    return 0;
}
// 1906C2: using guessed type int16_t word_1906C2[];


//----- (000788A2) --------------------------------------------------------
int16_t sub_788A2( int a1)
{
  return *(int16_t *)((char *)&word_1975D4 + 5 * a1);
}
// 1975D4: using guessed type int16_t word_1975D4;


//----- (000788AE) --------------------------------------------------------
void sub_788AE()
{
  JUMPOUT(0x78BAB);
}
// 788D2: control flows out of bounds to 78BAB
// 197F9C: using guessed type int dword_197F9C;


//----- (000789D4) --------------------------------------------------------
void sub_789D4()
{
  int16_t v0; // si
  int16_t v1; // bx
  int16_t v2; // dx
  int16_t v3; // cx
  int16_t v4; // [esp+4h] [ebp-Ch]
  _BOOL1 v5; // [esp+8h] [ebp-8h]
  char v6; // [esp+Ch] [ebp-4h]

  v0 = -1;
  v6 = 0;
  v1 = 0;
  v5 = word_199A02 < 1;
  while ( !v6 && !v5 && v1 < 500 )
  {
    if ( *(char *)(129 * v1 + dword_197F9C + 100) < 3 && (uint16_t)sub_1276F0((int)&byte_199E44, v1) )
    {
      v2 = 0;
      v4 = sub_77FF5(v1);
      while ( v2 < word_199A02 && !v6 )
      {
        v3 = *(int16_t *)((char *)&word_1975D4 + 5 * word_192248[v2]);
        if ( v0 == -1 && sub_77FF5(v3) == v4 )
          v0 = v2;
        if ( v3 == v1 )
          v6 = 1;
        ++v2;
      }
    }
    ++v1;
  }
  JUMPOUT(0x785E5);
}
// 78AB5: control flows out of bounds to 785E5
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 199A02: using guessed type int16_t word_199A02;
// 199E44: using guessed type char byte_199E44;


//----- (00078ABA) --------------------------------------------------------
int sub_78ABA( int a1)
{
  int v1; // edx
  char v2; // bl
  int result; // eax
  char v4; // bh

  v1 = 6 * a1;
  v2 = 0;
  result = 0;
  v4 = 0;
  if ( word_199A02 )
  {
    while ( !v2 )
    {
      if ( word_1906C2[v1] == word_192248[(int16_t)result] )
      {
        v4 = 1;
        v2 = 1;
      }
      else
      {
        ++result;
      }
      if ( (int16_t)result >= word_199A02 )
        v2 = 1;
    }
    if ( !v4 )
      return -1;
  }
  return result;
}
// 1906C2: using guessed type int16_t word_1906C2[];
// 192248: using guessed type int16_t word_192248[500];
// 199A02: using guessed type int16_t word_199A02;


//----- (00078B0E) --------------------------------------------------------
void sub_78B0E( int a1)
{
  char v1; // cl
  int16_t i; // dx
  char v3; // ch
  int16_t v4; // [esp+0h] [ebp-4h]

  v1 = 0;
  for ( i = 0; i < word_199A02 && !v1; ++i )
  {
    v3 = 0;
    v4 = word_192248[i];
    while ( !v3 )
    {
      if ( *(int16_t *)((char *)&word_1975D4 + 5 * v4) == a1 )
      {
        v3 = 1;
        v1 = 1;
      }
      else
      {
        v4 = *(int16_t *)((char *)&word_1975D6 + 5 * v4);
      }
      if ( v4 == -1 )
        v3 = 1;
    }
  }
  JUMPOUT(0x785E5);
}
// 78B8E: control flows out of bounds to 785E5
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 199994: using guessed type int16_t word_199994;
// 199A02: using guessed type int16_t word_199A02;


//----- (00078B93) --------------------------------------------------------
int16_t sub_78B93( int a1)
{
  return *(_WORD *)(129 * *(int16_t *)((char *)&word_1975D4 + 5 * a1) + dword_197F9C + 101);
}
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;


//----- (00078BB2) --------------------------------------------------------
int16_t sub_78BB2( int a1)
{
  return *(_WORD *)(129 * *(int16_t *)((char *)&word_1975D4 + 5 * a1) + dword_197F9C + 103);
}
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;


//----- (00078BCF) --------------------------------------------------------
int16_t sub_78BCF( int a1)
{
  return *(_WORD *)(129 * *(int16_t *)((char *)&word_1975D4 + 5 * a1) + dword_197F9C + 105);
}
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;


//----- (00078BEC) --------------------------------------------------------
int sub_78BEC( int a1)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax

  v2 = 129 * a1 + dword_197F9C;
  v3 = 0;
  if ( *(int16_t *)(v2 + 101) >= 500 && *(int16_t *)(v2 + 101) < 1000 )
    return 1;
  v4 = 129 * a1 + dword_197F9C;
  if ( *(int16_t *)(v4 + 101) < 500 )
    return 0;
  if ( *(int16_t *)(v4 + 101) >= 1000 && *(int16_t *)(v4 + 101) < word_19999A + 1000 )
    return 2;
  return v3;
}
// 197F9C: using guessed type int dword_197F9C;
// 19999A: using guessed type int16_t word_19999A;


//----- (00078C5B) --------------------------------------------------------
_BOOL1 sub_78C5B( int a1)
{
  return a1 == 4 || a1 == 5 || a1 == 6 || a1 == 7 || a1 == 10;
}


//----- (00078C94) --------------------------------------------------------
_BOOL1 sub_78C94( int a1, int a2)
{
  return *(int16_t *)(dword_19306C + 113 * a1 + 2 * a2 + 84) != -1;
}
// 19306C: using guessed type int dword_19306C;


//----- (00078CDB) --------------------------------------------------------
int16_t sub_78CDB( int a1, int a2)
{
  return *(_WORD *)(113 * a1 + dword_19306C + 2 * a2 + 74);
}
// 19306C: using guessed type int dword_19306C;


//----- (00078CF2) --------------------------------------------------------
void sub_78CF2( int a1)
{
  int16_t i; // ax
  _BOOL1 v3; // [esp+0h] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < 500 && !v3; ++i )
    v3 = word_1906C2[6 * i] == word_1931C2[6 * a1];
  JUMPOUT(0x77FD6);
}
// 78D39: control flows out of bounds to 77FD6
// 1906C2: using guessed type int16_t word_1906C2[];
// 1931C2: using guessed type int16_t word_1931C2[];


//----- (00078D3E) --------------------------------------------------------
int sub_78D3E( int a1)
{
  int v2; // ebx
  char v3; // cl
  int i; // eax

  v2 = 0;
  v3 = 0;
  for ( i = 0; (int16_t)i < 40 && !v3; ++i )
  {
    if ( a1 == word_17F80D[14 * (int16_t)i] )
    {
      v3 = 1;
      v2 = i;
    }
  }
  return v2;
}
// 17F80D: using guessed type int16_t word_17F80D[];


//----- (00078D71) --------------------------------------------------------
_BOOL1 sub_78D71( int a1, int a2)
{
  return sub_79D1C(a1, a2);
}


//----- (00078D86) --------------------------------------------------------
void sub_78D86()
{
  int i; // esi
  int v1; // eax
  int16_t *v2; // [esp+0h] [ebp-1Ch]
  _BYTE v3[4]; // [esp+4h] [ebp-18h] BYREF
  uint8_t v4; // [esp+8h] [ebp-14h]
  char v5; // [esp+9h] [ebp-13h]
  int v6; // [esp+14h] [ebp-8h]
  int v7; // [esp+18h] [ebp-4h]

  v6 = 255;
  v7 = -1;
  for ( i = 0; (int16_t)i < word_19999A; ++i )
  {
    if ( sub_79D1C(i, word_19999C)
      && (((int)*(uint8_t *)(113 * (int16_t)i + dword_19306C + 42) >> word_19999C) & 1) == 0 )
    {
      sub_FF799(v2, i, v3);
      if ( v5 )
      {
        LOWORD(v1) = v4;
        if ( v4 < (int16_t)v6 )
        {
          v7 = i;
          v6 = v1;
        }
      }
    }
  }
  JUMPOUT(0x785E5);
}
// 78E02: control flows out of bounds to 785E5
// 78DD9: variable 'v2' is possibly undefined
// 78DF2: variable 'v1' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;


//----- (00078E07) --------------------------------------------------------
int sub_78E07(int result)
{
  if ( (int16_t)result < 500 || (int16_t)result >= 1000 )
  {
    if ( (int16_t)result >= 1000 && (int16_t)result < 1072 )
      result -= 1000;
  }
  else
  {
    result -= 500;
  }
  return result;
}


//----- (00078E2D) --------------------------------------------------------
int sub_78E2D( int a1, int16_t *a2)
{
  int v2; // ebx

  v2 = 0;
  if ( a1 < 500 || a1 >= 1000 )
  {
    if ( a1 >= 1000 && a1 < 1500 )
    {
      v2 = 2;
      a1 -= 1000;
    }
  }
  else
  {
    v2 = 1;
    a1 -= 500;
  }
  *a2 = a1;
  return v2;
}


//----- (00078E67) --------------------------------------------------------
void sub_78E67()
{
  int16_t i; // cx
  int16_t j; // cx
  int16_t k; // dx
  int v3; // eax
  int v4; // eax
  _WORD v5[6]; // [esp+0h] [ebp-10h] BYREF
  int v6; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < word_1999A2; ++i )
    sub_79C6B(i);
  for ( j = 0; j < word_19999A; ++j )
  {
    memset(v5, 0, 10);
    for ( k = 0; k < 5; ++k )
    {
      v6 = 113 * j + dword_19306C;
      v3 = *(int16_t *)(v6 + 2 * k + 74);
      if ( v3 != -1 )
      {
        v4 = dword_1930D4 + 17 * v3;
        if ( v5[*(uint8_t *)(v4 + 3)] )
        {
          _wcpp_1_unwind_leave(
            0,
            1,
            "orbit %d of star %d has more than 1 planet in it",
            *(uint8_t *)(v4 + 3),
            j);
          _wcpp_1_unwind_leave(0, 2, aRelateGameCond);
          _wcpp_1_unwind_leave(0, 3, "(%s)", (char *)(dword_19306C + 113 * j));
          sub_6497C();
        }
        v5[k] = 1;
      }
    }
  }
}
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999A: using guessed type int16_t word_19999A;
// 1999A2: using guessed type int16_t word_1999A2;


//----- (00078F4B) --------------------------------------------------------
_BOOL1 sub_78F4B( int a1)
{
  _BOOL1 v2; // cl
  int16_t i; // bx
  int v4; // eax
  int v5; // eax

  v2 = 0;
  for ( i = 0; i < 5 && !v2; ++i )
  {
    v4 = *(int16_t *)(dword_19306C + 113 * a1 + 2 * i + 74);
    if ( v4 > -1 )
    {
      v5 = *(int16_t *)(dword_1930D4 + 17 * v4);
      if ( v5 > -1 )
        v2 = sub_78FB8(word_19999C, *(char *)(361 * v5 + dword_192B18)) != 0;
    }
  }
  return v2;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;


//----- (00078FB8) --------------------------------------------------------
char sub_78FB8( int a1, int a2)
{
  if ( a2 >= 0 && a2 < word_199998 )
    return *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1412);
  else
    return 0;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00078FE6) --------------------------------------------------------
void sub_78FE6()
{
  if ( --word_19999E <= 0 )
    word_19999E = 0;
}
// 19999E: using guessed type int16_t word_19999E;


//----- (00079001) --------------------------------------------------------
_BOOL1 sub_79001( int a1)
{
  char v2; // dl
  int16_t i; // ax

  v2 = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( *(_WORD *)(113 * a1 + dword_19306C + 2 * i + 74) != 0xFFFF )
      ++v2;
  }
  return v2 == 0;
}
// 19306C: using guessed type int dword_19306C;


//----- (00079037) --------------------------------------------------------
_BOOL1 sub_79037( int a1)
{
  _BOOL1 v2; // dl
  int16_t i; // ax
  int v4; // ebx
  int v5; // ebx

  v2 = 0;
  for ( i = 0; i < 5 && !v2; ++i )
  {
    v4 = *(int16_t *)(dword_19306C + 113 * a1 + 2 * i + 74);
    if ( v4 > -1 )
    {
      v5 = *(int16_t *)(dword_1930D4 + 17 * v4);
      if ( v5 > -1 )
        v2 = *(char *)(361 * v5 + dword_192B18) != word_19999C;
    }
  }
  return v2;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;


//----- (000790A4) --------------------------------------------------------
int sub_790A4( int a1)
{
  int result; // eax

  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( word_1999A0 < 15 )
        goto LABEL_3;
      result = 15;
    }
    else if ( a1 == 2 )
    {
      if ( word_1999A0 < 20 )
        goto LABEL_3;
      result = 20;
    }
    else
    {
      if ( word_1999A0 < 30 )
        goto LABEL_3;
      result = 30;
    }
  }
  else
  {
    if ( word_1999A0 < 10 )
    {
LABEL_3:
      result = word_1999A0;
      goto LABEL_13;
    }
    result = 10;
  }
LABEL_13:
  if ( (_WORD)result == word_1999A0 )
  {
    word_199980 = 0;
    word_19997E = 0;
    word_19998A = 0;
    word_19998E = 0;
    word_199984 = 0;
    word_199986 = 0;
  }
  return result;
}
// 19997E: using guessed type int16_t word_19997E;
// 199980: using guessed type int16_t word_199980;
// 199984: using guessed type int16_t word_199984;
// 199986: using guessed type int16_t word_199986;
// 19998A: using guessed type int16_t word_19998A;
// 19998E: using guessed type int16_t word_19998E;
// 1999A0: using guessed type int16_t word_1999A0;


//----- (00079138) --------------------------------------------------------
int sub_79138( int a1, unsigned int a2, char *a3, int a4)
{
  int16_t v6; // ax
  int16_t v7; // bx
  int16_t v8; // bx
  int v9; // eax
  int16_t v10; // cx
  int16_t i; // bx
  int v12; // eax
  int v13; // eax
  char v14; // dl
  int result; // eax
  int16_t v16; // [esp+0h] [ebp-14h]
  int16_t v17; // [esp+Ch] [ebp-8h]
  char v18; // [esp+10h] [ebp-4h]

  v6 = 11;
  v17 = 14;
  v7 = 1;
  v18 = 0;
  if ( a4 )
    v16 = byte_199F31;
  else
    v16 = 0;
  if ( a1 >= 8 && a1 < 15 )
  {
    v8 = 4;
    v18 = 1;
LABEL_7:
    v17 = v6;
    sub_8F6F8(a2, v8, v6, a3);
    goto LABEL_14;
  }
  v9 = dword_197F98 + 3753 * a1;
  if ( *(_BYTE *)(v9 + 38) == 3 )
  {
    v8 = 12;
    v6 = 22;
    v18 = 2;
    goto LABEL_7;
  }
  if ( a1 < 8 )
  {
    v10 = (uint8_t)byte_10010[*(uint8_t *)(v9 + 38)];
    v7 = v10 + 1;
    v17 = v10 + 6;
    if ( *(_BYTE *)(v9 + 38) == 4 )
      v17 = v10 + 5;
  }
  sub_8F6F8(a2, v7, v17, a3);
LABEL_14:
  for ( i = 1; i < 8; ++i )
  {
    if ( v18 == 1 )
    {
      a3[i] += v16;
    }
    else
    {
      if ( v18 == 2 )
        v12 = (7 * v16 - (__CFSHL__((7 * v16) >> 31, 2) + 4 * ((7 * v16) >> 31))) >> 2;
      else
        v12 = 3 * v16 / 2;
      a3[i] += v12;
    }
    v13 = v17 + 8;
    if ( (uint8_t)a3[i] <= v13 )
      LOBYTE(v13) = a3[i];
    v14 = v13;
    result = i;
    a3[result] = v14;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199F31: using guessed type char byte_199F31;


//----- (0007926C) --------------------------------------------------------
int sub_7926C( int a1)
{
  return 10 * a1 / word_199992;
}
// 199992: using guessed type int16_t word_199992;


//----- (0007927F) --------------------------------------------------------
void sub_7927F()
{
  JUMPOUT(0x79279);
}
// 79291: control flows out of bounds to 79279
// 199992: using guessed type int16_t word_199992;


//----- (00079293) --------------------------------------------------------
void sub_79293()
{
  JUMPOUT(0x79279);
}
// 792A7: control flows out of bounds to 79279
// 199992: using guessed type int16_t word_199992;
// 1999A0: using guessed type int16_t word_1999A0;


//----- (000792A9) --------------------------------------------------------
_BOOL2 sub_792A9( int a1)
{
  return *(_BYTE *)(113 * a1 + dword_19306C + 22) < 6u;
}
// 19306C: using guessed type int dword_19306C;


//----- (000792C3) --------------------------------------------------------
int sub_792C3()
{
  int16_t v0; // bx
  int v1; // eax
  int v2; // edx
  int v3; // eax
  int v4; // edx
  int v5; // ebx
  int v6; // eax
  char v7; // bl

  byte_1823E0[0] = 0;
  byte_1823E1 = 4;
  byte_1823E2 = 9;
  byte_1823E3 = 15;
  byte_1823E4 = 22;
  byte_1823E5 = 30;
  byte_1823E6 = 39;
  byte_1823E7 = 48;
  byte_1823E8 = 56;
  byte_1823E9 = 64;
  word_19995E = 0;
  word_199972 = 0;
  word_199980 = 0;
  word_19997E = 0;
  word_19998A = 0;
  word_19998E = 0;
  word_199984 = 0;
  word_199986 = 0;
  word_1992C0[0] = -1;
  word_1992C2 = 0;
  word_1992C4 = 0;
  word_1992C6 = 0;
  word_1992C8 = 0;
  if ( byte_199F3A == 1 )
  {
    memset(&word_19C0E0, 0, 64);
    memset(&word_19C0A0, 0, 64);
    memset(&byte_19C120, 0, 8);
  }
  byte_199F31 = 0;
  byte_199F30 = 1;
  v0 = word_1992C0[0];
  v1 = 0;
  do
  {
    v2 = (int16_t)v1++;
    word_19C0A4[4 * v2] = v0;
  }
  while ( (int16_t)v1 < 8 );
  v3 = 0;
  do
  {
    v4 = 3 * (int16_t)v3;
    *(int16_t *)((char *)&word_199BCD + v4) = -1000;
    byte_199BCF[v4] = 0;
    v5 = 14 * (int16_t)v3;
    LOWORD(v4) = word_1992C0[(int16_t)v3++];
    word_192FDE[v5] = v4;
  }
  while ( (int16_t)v3 < 5 );
  word_199960 = -1;
  word_19C53E = -1;
  byte_199F17 = 0;
  byte_19C18E = 0;
  word_199830 = 0;
  word_199988 = -1;
  word_199974 = 0;
  byte_199F0A = 2;
  word_1999FC = 0;
  word_199A06 = -1;
  word_19995C = -1;
  word_199964 = -1;
  word_199956 = 0;
  word_199A04 = 102;
  word_1999CA = -1;
  word_1999C0 = -1;
  byte_199F09 = 0;
  byte_199F1D = -1;
  byte_199F23 = 0;
  byte_199F33 = 0;
  byte_199F21 = 0;
  dword_1975B8 = 0;
  byte_199F26 = 0;
  byte_19C198 = 0;
  word_19990C = 1;
  word_19990A = 1;
  byte_199F1F = 1;
  byte_19C1A0 = 0;
  byte_19BFC4 = 1;
  byte_19C191 = 1;
  word_19C180 = -1;
  byte_199F1B = -1;
  word_1999BA = 0;
  word_1931AC[0] = 33;
  word_1931AE = 29;
  word_1931B0 = 25;
  word_1931B2 = 23;
  word_1931B4 = 21;
  word_1931B6 = 17;
  word_1992B6 = 21;
  word_1992B8 = 33;
  word_1992BA = 45;
  word_1992BC = 57;
  word_1992BE = 69;
  byte_199EC2[0] = 19;
  byte_199EC3 = 20;
  byte_199EC4 = 22;
  byte_199EC5 = 22;
  byte_199EC6 = 24;
  word_19995A = 160;
  word_199970 = 117;
  byte_199F04 = 59;
  byte_199F03 = 61;
  byte_199F02 = 73;
  byte_199F01 = 76;
  word_199992 = word_1999A0;
  v6 = 0;
  byte_199F07 = 0;
  byte_199F06 = 1;
  v7 = 0;
  do
  {
    byte_1992F2[(int16_t)v6++] = v7;
    v7 += 2;
  }
  while ( (int16_t)v6 < 10 );
  byte_199F1C = 0;
  sub_82D9B();
  return memset(byte_199E05, 0, sizeof(byte_199E05));
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 1823E1: using guessed type char byte_1823E1;
// 1823E2: using guessed type char byte_1823E2;
// 1823E3: using guessed type char byte_1823E3;
// 1823E4: using guessed type char byte_1823E4;
// 1823E5: using guessed type char byte_1823E5;
// 1823E6: using guessed type char byte_1823E6;
// 1823E7: using guessed type char byte_1823E7;
// 1823E8: using guessed type char byte_1823E8;
// 1823E9: using guessed type char byte_1823E9;
// 192FDE: using guessed type int16_t word_192FDE[];
// 1931AC: using guessed type int16_t word_1931AC[];
// 1931AE: using guessed type int16_t word_1931AE;
// 1931B0: using guessed type int16_t word_1931B0;
// 1931B2: using guessed type int16_t word_1931B2;
// 1931B4: using guessed type int16_t word_1931B4;
// 1931B6: using guessed type int16_t word_1931B6;
// 1975B8: using guessed type int dword_1975B8;
// 1992B6: using guessed type int16_t word_1992B6;
// 1992B8: using guessed type int16_t word_1992B8;
// 1992BA: using guessed type int16_t word_1992BA;
// 1992BC: using guessed type int16_t word_1992BC;
// 1992BE: using guessed type int16_t word_1992BE;
// 1992C0: using guessed type int16_t word_1992C0[];
// 1992C2: using guessed type int16_t word_1992C2;
// 1992C4: using guessed type int16_t word_1992C4;
// 1992C6: using guessed type int16_t word_1992C6;
// 1992C8: using guessed type int16_t word_1992C8;
// 199830: using guessed type int16_t word_199830;
// 19990A: using guessed type int16_t word_19990A;
// 19990C: using guessed type int16_t word_19990C;
// 199956: using guessed type int16_t word_199956;
// 19995A: using guessed type int16_t word_19995A;
// 19995C: using guessed type int16_t word_19995C;
// 19995E: using guessed type int16_t word_19995E;
// 199960: using guessed type int16_t word_199960;
// 199964: using guessed type int16_t word_199964;
// 199970: using guessed type int16_t word_199970;
// 199972: using guessed type int16_t word_199972;
// 199974: using guessed type int16_t word_199974;
// 19997E: using guessed type int16_t word_19997E;
// 199980: using guessed type int16_t word_199980;
// 199984: using guessed type int16_t word_199984;
// 199986: using guessed type int16_t word_199986;
// 199988: using guessed type int16_t word_199988;
// 19998A: using guessed type int16_t word_19998A;
// 19998E: using guessed type int16_t word_19998E;
// 199992: using guessed type int16_t word_199992;
// 1999A0: using guessed type int16_t word_1999A0;
// 1999BA: using guessed type int16_t word_1999BA;
// 1999C0: using guessed type int16_t word_1999C0;
// 1999CA: using guessed type int16_t word_1999CA;
// 1999FC: using guessed type int16_t word_1999FC;
// 199A04: using guessed type int16_t word_199A04;
// 199A06: using guessed type int16_t word_199A06;
// 199BCD: using guessed type int16_t word_199BCD;
// 199EC3: using guessed type char byte_199EC3;
// 199EC4: using guessed type char byte_199EC4;
// 199EC5: using guessed type char byte_199EC5;
// 199EC6: using guessed type char byte_199EC6;
// 199F01: using guessed type char byte_199F01;
// 199F02: using guessed type char byte_199F02;
// 199F03: using guessed type char byte_199F03;
// 199F04: using guessed type char byte_199F04;
// 199F06: using guessed type char byte_199F06;
// 199F07: using guessed type char byte_199F07;
// 199F09: using guessed type char byte_199F09;
// 199F0A: using guessed type char byte_199F0A;
// 199F17: using guessed type char byte_199F17;
// 199F1B: using guessed type char byte_199F1B;
// 199F1C: using guessed type char byte_199F1C;
// 199F1D: using guessed type char byte_199F1D;
// 199F1F: using guessed type char byte_199F1F;
// 199F21: using guessed type char byte_199F21;
// 199F23: using guessed type char byte_199F23;
// 199F26: using guessed type char byte_199F26;
// 199F30: using guessed type char byte_199F30;
// 199F31: using guessed type char byte_199F31;
// 199F33: using guessed type char byte_199F33;
// 199F3A: using guessed type char byte_199F3A;
// 19BFC4: using guessed type char byte_19BFC4;
// 19C0A0: using guessed type int16_t word_19C0A0;
// 19C0A4: using guessed type int16_t word_19C0A4[30];
// 19C0E0: using guessed type int16_t word_19C0E0;
// 19C120: using guessed type char byte_19C120;
// 19C180: using guessed type int16_t word_19C180;
// 19C18E: using guessed type char byte_19C18E;
// 19C191: using guessed type char byte_19C191;
// 19C198: using guessed type char byte_19C198;
// 19C1A0: using guessed type char byte_19C1A0;
// 19C53E: using guessed type int16_t word_19C53E;


//----- (0007962C) --------------------------------------------------------
void sub_7962C()
{
  word_1992C0[0] = -1;
  word_1992C2 = 0;
  word_1992C4 = -1;
  word_1992C6 = 0;
  word_1992C8 = 0;
  sub_79756();
  JUMPOUT(0x79624);
}
// 7966C: control flows out of bounds to 79624
// 1992C0: using guessed type int16_t word_1992C0[];
// 1992C2: using guessed type int16_t word_1992C2;
// 1992C4: using guessed type int16_t word_1992C4;
// 1992C6: using guessed type int16_t word_1992C6;
// 1992C8: using guessed type int16_t word_1992C8;


//----- (0007966E) --------------------------------------------------------
int sub_7966E( int a1)
{
  int v2; // edx
  int16_t i; // ax
  int v4; // ebx

  v2 = 0;
  for ( i = 0; i < 5 && !(_WORD)v2; ++i )
  {
    v4 = *(int16_t *)(113 * a1 + dword_19306C + 2 * i + 74);
    if ( v4 > -1 && *(int16_t *)(17 * v4 + dword_1930D4) > -1 )
      v2 = 1;
  }
  return v2;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000796BF) --------------------------------------------------------
int16_t sub_796BF()
{
  int16_t result; // ax

  result = ++word_19999E;
  if ( word_19999E >= word_19997C )
  {
    result = word_19997C;
    word_19999E = word_19997C;
  }
  return result;
}
// 19997C: using guessed type int16_t word_19997C;
// 19999E: using guessed type int16_t word_19999E;


//----- (000796E2) --------------------------------------------------------
int sub_796E2()
{
  int v0; // eax
  char v1; // al

  v0 = word_19999E + 1;
  if ( word_19997C <= v0 )
    LOWORD(v0) = word_19997C;
  word_19999E = v0;
  v1 = sub_79917();
  if ( v1 > word_19999E )
    return 1;
  word_19999E = v1;
  return 0;
}
// 19997C: using guessed type int16_t word_19997C;
// 19999E: using guessed type int16_t word_19999E;


//----- (0007971F) --------------------------------------------------------
void sub_7971F()
{
  word_19301A = 200;
  word_193018 = 272;
  word_19301C = 22;
  word_19301E = 22;
  word_193028 = 200;
  word_19302A = 39;
}
// 193018: using guessed type int16_t word_193018;
// 19301A: using guessed type int16_t word_19301A;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 193028: using guessed type int16_t word_193028;
// 19302A: using guessed type int16_t word_19302A;


//----- (00079756) --------------------------------------------------------
int sub_79756()
{
  int v0; // ebx
  int v1; // eax
  int16_t v2; // dx

  memset(word_192FDC, 0, 140);
  word_192FDC[0] = 0;
  word_192FF8 = 1;
  word_193014 = 2;
  word_193030 = 3;
  word_19304C = 4;
  v0 = 0;
  do
  {
    word_1992E8[(int16_t)v0] = v0;
    v1 = 14 * (int16_t)v0;
    word_192FE4[v1] = -1;
    v2 = word_1992C0[(int16_t)v0];
    word_192FE6[v1] = -1;
    ++v0;
    word_192FDE[v1] = v2;
  }
  while ( (int16_t)v0 < 5 );
  sub_7971F();
  return sub_797DD();
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192FDC: using guessed type int16_t word_192FDC[];
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 192FF8: using guessed type int16_t word_192FF8;
// 193014: using guessed type int16_t word_193014;
// 193030: using guessed type int16_t word_193030;
// 19304C: using guessed type int16_t word_19304C;
// 1992C0: using guessed type int16_t word_1992C0[];
// 1992E8: using guessed type int16_t word_1992E8[5];


//----- (000797DD) --------------------------------------------------------
int sub_797DD()
{
  int16_t v0; // ax
  int result; // eax

  dword_193070 = sub_127C27((int)aBuffer0Lbx_1, 0, dword_193174);
  v0 = *(_WORD *)(dword_193070 + 2);
  word_192FE2[0] = *(_WORD *)dword_193070;
  word_192FE0[0] = v0;
  if ( word_192FE4[0] < 0 )
    word_192FE4[0] = 22;
  result = 0;
  if ( word_192FE6[0] < 0 )
    word_192FE6[0] = 22;
  return result;
}
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 193070: using guessed type int dword_193070;
// 193174: using guessed type int dword_193174;


//----- (0007987A) --------------------------------------------------------
char sub_7987A( int a1)
{
  char v2; // bl
  int16_t i; // ax
  int v4; // edx

  v2 = 0;
  for ( i = 0; i < 5; ++i )
  {
    v4 = *(int16_t *)(dword_19306C + 113 * a1 + 2 * i + 74);
    if ( v4 > -1 && *(int16_t *)(dword_1930D4 + 17 * v4) != -1 )
      v2 = 1;
  }
  return v2;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000798C4) --------------------------------------------------------
_BOOL1 sub_798C4( int a1)
{
  return (int16_t)sub_79E8D(a1) != -1;
}


//----- (000798D2) --------------------------------------------------------
int16_t sub_798D2()
{
  int16_t result; // ax

  result = (uint8_t)byte_199CB2;
  if ( word_19999A <= 20 )
    return 0;
  if ( word_19999A <= 36 )
    return 1;
  if ( word_19999A <= 54 )
    return 2;
  if ( word_19999A <= 72 )
    return 3;
  return result;
}
// 19999A: using guessed type int16_t word_19999A;
// 199CB2: using guessed type char byte_199CB2;


//----- (00079917) --------------------------------------------------------
int sub_79917()
{
  switch ( word_199992 )
  {
    case 10:
      if ( word_19997C < 0 )
        return word_19997C;
      return 0;
    case 15:
      if ( word_19997C < 1 )
        return word_19997C;
      return 1;
    case 20:
      if ( word_19997C < 2 )
        return word_19997C;
      return 2;
    default:
      if ( word_19997C < 3 )
        return word_19997C;
      return 3;
  }
}
// 19997C: using guessed type int16_t word_19997C;
// 199992: using guessed type int16_t word_199992;


//----- (00079979) --------------------------------------------------------
void sub_79979( int a1)
{
  int v2; // ecx
  int16_t v3; // dx
  int v4; // eax
  int v5; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-8h] BYREF

  memset(v6, 0, sizeof(v6));
  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = *(int16_t *)(dword_19306C + 113 * a1 + 2 * v3 + 74);
    if ( v4 > -1 )
    {
      v5 = *(int16_t *)(dword_1930D4 + 17 * v4);
      if ( v5 > -1 && !v6[*(char *)(361 * v5 + dword_192B18)] )
      {
        ++v2;
        v6[*(char *)(361 * v5 + dword_192B18)] = 1;
      }
    }
    if ( ++v3 >= 5 )
      JUMPOUT(0x78F44);
  }
}
// 799F2: control flows out of bounds to 78F44
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000799F7) --------------------------------------------------------
int sub_799F7(int a1, int a2, _WORD *a3, int a4)
{
  int v5; // eax
  int v6; // edx
  int16_t i; // dx
  int result; // eax
  char v9; // cl
  int16_t v10; // [esp+0h] [ebp-Ch]

  *a3 = 0;
  v5 = 0;
  do
  {
    v6 = (int16_t)v5++;
    *(_WORD *)(a2 + 2 * v6) = 0;
  }
  while ( (int16_t)v5 < 8 );
  for ( i = 0; i < 5; ++i )
  {
    result = *(int16_t *)(113 * v10 + dword_19306C + 2 * i + 74);
    if ( result > -1 )
    {
      result = *(int16_t *)(dword_1930D4 + 17 * result);
      if ( result > -1 )
      {
        result = 361 * result + dword_192B18;
        if ( *(char *)result > -1 )
        {
          LOWORD(result) = *(char *)result;
          if ( a4 && (_WORD)result != word_19999C )
          {
            if ( (result & 0x8000u) == 0 && (int16_t)result < word_199998 )
              v9 = *(_BYTE *)(dword_197F98 + 3753 * word_19999C + (int16_t)result + 1412);
            else
              v9 = 0;
          }
          else
          {
            v9 = 1;
          }
          if ( v9 )
          {
            if ( !*(_WORD *)(a2 + 2 * (int16_t)result) )
              ++*a3;
            result = (int16_t)result;
            ++*(_WORD *)(a2 + 2 * (int16_t)result);
          }
        }
      }
    }
  }
  return result;
}
// 79A1C: variable 'v10' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;


//----- (00079AE8) --------------------------------------------------------
char sub_79AE8( int a1)
{
  char v3; // dl
  int16_t i; // ax
  int v5; // ebx

  v3 = 0;
  for ( i = 0; i < 5; ++i )
  {
    v5 = *(int16_t *)(113 * a1 + dword_19306C + 2 * i + 74);
    if ( v5 > -1 && *(_BYTE *)(dword_1930D4 + 17 * v5 + 11) )
      ++v3;
  }
  return v3;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (00079B2D) --------------------------------------------------------
char sub_79B2D( int a1)
{
  char v3; // dl
  int16_t i; // ax
  int v5; // ebx

  v3 = 0;
  for ( i = 0; i < 5; ++i )
  {
    v5 = *(int16_t *)(113 * a1 + dword_19306C + 2 * i + 74);
    if ( v5 != -1 && *(_BYTE *)(dword_1930D4 + 17 * v5 + 4) == 3 )
      ++v3;
  }
  return v3;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (00079B73) --------------------------------------------------------
int sub_79B73( int a1)
{
  int v2; // ebx
  int16_t i; // dx

  v2 = 0;
  for ( i = 0; i < 500; ++i )
  {
    if ( sub_77FF5(i) == a1 && *(char *)(129 * i + dword_197F9C + 100) < 3 )
      ++v2;
  }
  return v2;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (00079BAE) --------------------------------------------------------
char sub_79BAE( int a1)
{
  char v3; // dl
  int16_t i; // ax

  v3 = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( *(_WORD *)(113 * a1 + dword_19306C + 2 * i + 74) != 0xFFFF )
      ++v3;
  }
  return v3;
}
// 19306C: using guessed type int dword_19306C;


//----- (00079BEB) --------------------------------------------------------
int sub_79BEB( int a1, int a2)
{
  int v2; // ecx
  _BYTE v4[16]; // [esp+0h] [ebp-14h] BYREF
  int16_t v5[2]; // [esp+10h] [ebp-4h] BYREF

  v2 = -1;
  v5[0] = a1;
  v5[1] = -1;
  sub_FF799(v5, a2, v4);
  if ( v4[5] )
    LOWORD(v2) = v4[4];
  return nullsub_4(v2);
}
// 79C1C: using guessed type int nullsub_4(_DWORD);


//----- (00079C1D) --------------------------------------------------------
_BOOL1 sub_79C1D( int a1)
{
  char v1; // dl
  int v2; // eax

  v1 = 0;
  if ( a1 != -1 )
  {
    v2 = *(int16_t *)(dword_1930D4 + 17 * a1);
    if ( v2 != -1 )
      return *(_BYTE *)(dword_192B18 + 361 * v2 + 6) != 0;
  }
  return v1;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;


//----- (00079C54) --------------------------------------------------------
int16_t sub_79C54( int a1, int a2)
{
  return *(_WORD *)(113 * a1 + dword_19306C + 2 * a2 + 74);
}
// 19306C: using guessed type int dword_19306C;


//----- (00079C6B) --------------------------------------------------------
void sub_79C6B( int a1)
{
  int16_t v2; // si
  int16_t v3; // bx
  char v4; // dl
  int v5; // eax
  int16_t v6; // [esp+0h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  v6 = *(uint8_t *)(dword_1930D4 + 17 * a1 + 2);
  v4 = 0;
  while ( v3 < 5 && !v2 )
  {
    v5 = 113 * v6 + dword_19306C + 2 * v3;
    if ( a1 == *(_WORD *)(v5 + 74) )
    {
      v2 = 1;
    }
    else if ( *(int16_t *)(v5 + 74) > -1 )
    {
      ++v4;
    }
    ++v3;
  }
  JUMPOUT(0x78F44);
}
// 79CCD: control flows out of bounds to 78F44
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (00079CD2) --------------------------------------------------------
int16_t sub_79CD2( int a1, int a2)
{
  return *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_19306C + 113 * a1 + 2 * a2 + 74) + 4);
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (00079CF9) --------------------------------------------------------
int sub_79CF9(int a1, int a2)
{
  return ((int)*(uint8_t *)(a2 + 63) >> ((a1 - dword_197F98) / 3753)) & 1;
}
// 197F98: using guessed type int dword_197F98;


//----- (00079D1C) --------------------------------------------------------
_BOOL1 sub_79D1C( int a1, int a2)
{
  return (uint16_t)sub_1276F0(dword_19306C + 113 * a2 + 56, a1) != 0;
}
// 19306C: using guessed type int dword_19306C;


//----- (00079D40) --------------------------------------------------------
_BOOL1 sub_79D40(int a1)
{
  return *(_BYTE *)(a1 + 64) != 0;
}


//----- (00079D48) --------------------------------------------------------
_BOOL1 sub_79D48(int a1)
{
  return *(_BYTE *)(a1 + 63) != 0;
}


//----- (00079D50) --------------------------------------------------------
void sub_79D50()
{
  JUMPOUT(0x79D0F);
}
// 79D66: control flows out of bounds to 79D0F
// 197F98: using guessed type int dword_197F98;


//----- (00079D68) --------------------------------------------------------
int sub_79D68( int a1, int a2)
{
  return ((int)*(uint8_t *)(dword_19306C + 113 * a2 + 62) >> a1) & 1;
}
// 19306C: using guessed type int dword_19306C;


//----- (00079D86) --------------------------------------------------------
_BOOL1 sub_79D86(int a1, int a2)
{
  _BOOL1 v3; // dl
  int16_t i; // ax
  int v5; // ebx
  int v6; // ebx

  v3 = 0;
  for ( i = 0; i < 5 && !v3; ++i )
  {
    v5 = *(int16_t *)(113 * a2 + dword_19306C + 2 * i + 74);
    if ( v5 > -1 )
    {
      v6 = *(int16_t *)(dword_1930D4 + 17 * v5);
      if ( v6 > -1 )
        v3 = *(_BYTE *)(361 * v6 + dword_192B18 + 6) != 0;
    }
  }
  return v3;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (00079DEA) --------------------------------------------------------
void sub_79DEA()
{
  JUMPOUT(0x79D7F);
}
// 79E01: control flows out of bounds to 79D7F
// 19306C: using guessed type int dword_19306C;


//----- (00079E06) --------------------------------------------------------
_BOOL1 sub_79E06( int a1)
{
  int v1; // edx

  v1 = a1;
  return sub_94877(a1) || *(_BYTE *)(3753 * v1 + dword_197F98 + 2234);
}
// 197F98: using guessed type int dword_197F98;


