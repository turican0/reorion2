#include "orion_common.h"

/* Adresni rozsah: 0x93BB0 - 0x9F505  (200 funkci) */

//----- (00093BB0) --------------------------------------------------------
void __usercall sub_93BB0(int16_t *a1, int a2)
{
  int16_t v2; // ax
  int v3; // eax

  sub_1172D4();
  byte_199F05 = 2;
  sub_124C08();
  byte_199F11 = 1;
  sub_123E6C((int)&unk_17CF4A, 1);
  sub_C5BB9();
  sub_1205E6(8, 0, 255);
  sub_1318D4(0, 255);
  if ( !byte_199F1F && word_1999D8 > -1 )
  {
    v2 = sub_77FE9(word_192248[word_1999D8]);
    sub_585E0(v2, 255);
  }
  sub_132C80(100);
  sub_124D41();
  sub_93550(a2);
  v3 = sub_131922(0, 255);
  sub_1077D(v3, 255, 255, a1);
  sub_123E6C((int)&unk_17CF00, 1);
  sub_C5C44();
  sub_1172FC();
}
// 192248: using guessed type int16_t word_192248[500];
// 1999D8: using guessed type int16_t word_1999D8;
// 199F05: using guessed type char byte_199F05;
// 199F11: using guessed type char byte_199F11;
// 199F1F: using guessed type char byte_199F1F;


//----- (00093C69) --------------------------------------------------------
void __fastcall sub_93C69( int a1)
{
  _BOOL2 v2; // cx
  int16_t i; // ax

  v2 = 0;
  for ( i = 0; i < word_19992E && !v2; ++i )
    v2 = a1 == *(_WORD *)(13 * i + dword_192B24 + 11);
  JUMPOUT(0x92F4B);
}
// 93CAE: control flows out of bounds to 92F4B
// 192B24: using guessed type int dword_192B24;
// 19992E: using guessed type int16_t word_19992E;


//----- (00093D0A) --------------------------------------------------------
int16_t __fastcall sub_93D0A( int a1)
{
  char v1; // bl

  v1 = 0;
  switch ( *(char *)(3753 * a1 + dword_197F98 + 2207) / 2 )
  {
    case 0:
      v1 = 1;
      break;
    case 1:
      v1 = 3;
      break;
    case 2:
      v1 = 5;
      break;
    case 3:
      v1 = 7;
      break;
    default:
      return v1;
  }
  return v1;
}
// 197F98: using guessed type int dword_197F98;


//----- (00093D4B) --------------------------------------------------------
int __fastcall sub_93D4B( int a1, int a2)
{
  if ( a1 < 60 )
    return 0;
  if ( a1 < 150 )
    return 1;
  if ( a1 < 300 )
    return 2;
  if ( a1 < 500 )
    return 3;
  if ( a1 >= 1000 && a2 )
    return 5;
  return 4;
}


//----- (00093D8E) --------------------------------------------------------
char __fastcall sub_93D8E( int a1, _WORD *a2, _WORD *a3)
{
  int v5; // ebx
  int16_t v6; // ax
  char result; // al

  v5 = a1;
  sub_97A2D(word_19999C, a1);
  *a2 = v6;
  *a3 = sub_94A9D(word_19999C, v5);
  result = (*(_DWORD *)(dword_1930DC + 59 * v5 + 38) & dword_17D411) != 0;
  if ( (*(_DWORD *)(dword_1930DC + 59 * v5 + 38) & dword_17D411) != 0 || (result = sub_9467D(word_19999C, a1, 29)) != 0 )
    *a3 = 0;
  return result;
}
// 93DAA: variable 'v6' is possibly undefined
// 17D411: using guessed type int dword_17D411;
// 1930DC: using guessed type int dword_1930DC;
// 19999C: using guessed type int16_t word_19999C;


//----- (00093DF7) --------------------------------------------------------
void sub_93DF7()
{
  int16_t i; // di
  int16_t v1; // ax
  int16_t v2; // si
  _DWORD *v3; // edx
  int v4; // eax
  int v5; // ebx
  _DWORD *v6; // edx
  int v7; // eax
  int v8; // ebx
  int v9; // [esp+0h] [ebp-8h]

  for ( i = 0; i < word_1999A6; ++i )
  {
    v9 = 2 * i;
    v1 = *(_WORD *)(v9 + dword_193188);
    v2 = v1;
    if ( v1 > -1 )
    {
      v3 = sub_925AE(word_19999C, v1, dword_193118, i == 0, 0);
      v4 = 6 * i;
      v5 = dword_19C458;
      *(_DWORD *)(dword_19C458 + v4) = v3;
      *(_WORD *)(v5 + v4 + 4) = *(_WORD *)(v9 + dword_193188);
      v6 = sub_92619(word_19999C, v2, dword_193118, 0);
      v7 = 6 * (i + 4);
      v8 = dword_19C458;
      *(_DWORD *)(dword_19C458 + v7) = v6;
      *(_WORD *)(v8 + v7 + 4) = *(_WORD *)(v9 + dword_193188);
    }
  }
  JUMPOUT(0x94800);
}
// 93EAD: control flows out of bounds to 94800
// 193118: using guessed type int dword_193118;
// 193188: using guessed type int dword_193188;
// 19999C: using guessed type int16_t word_19999C;
// 1999A6: using guessed type int16_t word_1999A6;
// 19C458: using guessed type int dword_19C458;


//----- (00093EB2) --------------------------------------------------------
void __fastcall sub_93EB2(_DWORD *a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v6; // ecx
  int16_t i; // bx
  int16_t v9; // [esp+10h] [ebp-10h]
  int16_t v10; // [esp+14h] [ebp-Ch]
  int16_t v12; // [esp+1Ch] [ebp-4h]

  *a1 = 0;
  v10 = 0;
  *a2 = 0;
  while ( 1 )
  {
    if ( v10 >= a4 )
      JUMPOUT(0x92C1F);
    v12 = 0;
    v6 = 0;
    v9 = a3;
    if ( a5 && (int)sub_1247A0(7u) < 3 )
      v9 = 0;
    for ( i = 0; i < 27; ++i )
    {
      if ( v9 || byte_17D21D[9 * i] )
      {
        if ( v9 )
        {
          if ( (uint8_t)byte_17D21D[9 * i] == a3
            && (*a1 & dword_17D219[9 * i / 4u]) == 0
            && (*a1 & *(int *)((char *)&dword_17D219[9 * i / 4u + 4] + 2)) == 0
            && sub_1247A0((int16_t)++v6) == 1 )
          {
            if ( sub_1247A0(2u) == 1 )
            {
LABEL_12:
              v12 = i * 2;
              continue;
            }
            goto LABEL_19;
          }
        }
      }
      else if ( (*a2 & dword_17D219[9 * i / 4u]) == 0
             && (*a2 & *(int *)((char *)&dword_17D219[9 * i / 4u + 4] + 2)) == 0
             && sub_1247A0((int16_t)++v6) == 1 )
      {
        if ( sub_1247A0(2u) == 1 )
          goto LABEL_12;
LABEL_19:
        v12 = i * 2 + 1;
        continue;
      }
    }
    if ( v9 )
      *a1 += *(int *)((char *)dword_17D219 + 18 * v12);
    else
      *a2 += *(int *)((char *)dword_17D219 + 18 * v12);
    ++v10;
  }
}
// 94006: control flows out of bounds to 92C1F
// 17D219: using guessed type int dword_17D219[];


//----- (0009402B) --------------------------------------------------------
void __fastcall sub_9402B( int a1)
{
  int v1; // eax
  int16_t v2; // si
  int16_t v3; // di
  int16_t v4; // ax
  int16_t v5; // ax
  int16_t v6; // ax
  int16_t v7; // [esp+0h] [ebp-60h]
  _BYTE v8[80]; // [esp+4h] [ebp-5Ch] BYREF
  int v9; // [esp+54h] [ebp-Ch]
  int v10; // [esp+58h] [ebp-8h]
  int v11; // [esp+5Ch] [ebp-4h]

  HIWORD(v1) = HIWORD(dword_1930DC);
  v2 = 0;
  LOWORD(v1) = *(char *)(59 * a1 + dword_1930DC + 58);
  v3 = 0;
  v11 = v1;
  while ( 1 )
  {
    if ( byte_17D21D[18 * v3] )
    {
      if ( (uint8_t)byte_17D21D[18 * v3] <= 2u )
      {
        v9 = v7;
        if ( (*(_DWORD *)(dword_1930DC + 59 * v7 + 42) & *(int *)((char *)dword_17D219 + 18 * v3)) != 0 )
        {
          v6 = sub_94BB2((int16_t)v11, v9, v3);
          sprintf(v8, *(char **)((char *)&off_17D226 + 18 * v3), v6);
          v5 = sub_12066F((int)v8);
          if ( v5 > v2 )
            goto LABEL_10;
        }
      }
    }
    else
    {
      v10 = v7;
      if ( (*(_DWORD *)(dword_1930DC + 59 * v7 + 38) & *(int *)((char *)dword_17D219 + 18 * v3)) != 0 )
      {
        v4 = sub_94BB2((int16_t)v11, v10, v3);
        sprintf(v8, *(char **)((char *)&off_17D226 + 18 * v3), v4);
        v5 = sub_12066F((int)v8);
        if ( v5 > v2 )
LABEL_10:
          v2 = v5;
      }
    }
    if ( ++v3 >= 54 )
      JUMPOUT(0x94800);
  }
}
// 94126: control flows out of bounds to 94800
// 9406D: variable 'v7' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17D219: using guessed type int dword_17D219[];
// 17D226: using guessed type char *off_17D226;
// 1930DC: using guessed type int dword_1930DC;


//----- (0009412B) --------------------------------------------------------
void __fastcall sub_9412B(int a1, int a2)
{
  char v3; // al
  char v4; // al
  int16_t v5; // [esp+0h] [ebp-8h] BYREF
  int16_t v6; // [esp+4h] [ebp-4h] BYREF

  sub_93D8E(a2, &v5, &v6);
  *(_DWORD *)(dword_197F98 + 3753 * (int16_t)a1 + 50) -= v5;
  sub_9718F(a2, a1, 1, a1);
  if ( !*(_BYTE *)(dword_1930DC + 59 * a2 + 35) )
  {
    sub_9469E();
    if ( v3 || (sub_9469E(), v4) )
      *(_BYTE *)(3753 * (int16_t)a1 + dword_197F98 + 3701) = 1;
  }
}
// 9418B: variable 'v3' is possibly undefined
// 9419D: variable 'v4' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (000941BB) --------------------------------------------------------
_BOOL1 sub_941BB()
{
  return byte_199F1F == 0;
}
// 199F1F: using guessed type char byte_199F1F;


//----- (000941C6) --------------------------------------------------------
int __usercall sub_941C6( int a1, int a2)
{
  int v3; // eax
  int v4; // ebx
  int result; // eax

  v3 = dword_1930DC + 59 * a1;
  v4 = *(int16_t *)(v3 + 53);
  if ( v4 > -1 )
  {
    if ( *(_BYTE *)(v3 + 35) == 1 )
    {
      if ( *(char *)(v3 + 58) > -1 && *(char *)(v3 + 58) < 8 )
        *(_BYTE *)(*(char *)(v3 + 58) + dword_19306C + 113 * v4 + 66) = -1;
    }
    else
    {
      *(_WORD *)(dword_197F9C + 129 * v4 + 116) = -1;
    }
  }
  result = dword_1930DC + 59 * a1;
  *(_BYTE *)(result + 57) = -2;
  *(_BYTE *)(result + 55) = 0;
  *(_WORD *)(result + 53) = -1;
  if ( *(_BYTE *)(result + 35) == 1 )
    return sub_E2D72(*(char *)(result + 58), a2);
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;


//----- (00094254) --------------------------------------------------------
_BOOL1 __fastcall sub_94254( int a1)
{
  return *(_BYTE *)(dword_1930DC + 59 * a1 + 57) <= 2u;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (0009427B) --------------------------------------------------------
char sub_9427B()
{
  char v0; // bl
  int16_t i; // dx
  _BOOL1 v2; // cl
  int v3; // eax

  v0 = 0;
  for ( i = 0; i < 67 && !v0; ++i )
  {
    v2 = !byte_199F1F && !*(_BYTE *)(dword_1930DC + 59 * i + 35)
      || byte_199F1F && *(_BYTE *)(dword_1930DC + 59 * i + 35) == 1;
    v3 = dword_1930DC + 59 * i;
    if ( *(_BYTE *)(v3 + 57) == 4 && *(char *)(v3 + 58) == word_19999C && v2 )
      v0 = 1;
  }
  return v0;
}
// 1930DC: using guessed type int dword_1930DC;
// 19999C: using guessed type int16_t word_19999C;
// 199F1F: using guessed type char byte_199F1F;


//----- (000942FD) --------------------------------------------------------
void sub_942FD()
{
  int16_t i; // si
  int v1; // ebx
  int16_t *v2; // edi
  _DWORD *v3; // eax
  int16_t j; // si
  int v5; // edi
  _DWORD *v6; // eax
  _DWORD v7[5]; // [esp+0h] [ebp-18h] BYREF
  int v8; // [esp+14h] [ebp-4h]

  v8 = 1;
  sub_99403(v7);
  for ( i = 0; i < 27; ++i )
  {
    v1 = dword_192ED4;
    v2 = (int16_t *)i;
    v3 = sub_126C37((int)v7, 0, dword_192ED4, i, 1u, 38);
    dword_19C4CC[(_DWORD)v2] = (int)v3;
  }
  sub_FE8BE((int)v3, 0, v1, v2);
  for ( j = 0; j < 27; ++j )
  {
    v5 = j;
    v6 = sub_126C37((int)v7, (int16_t)v8, dword_192ED4, j, 1u, 255);
    dword_19C45C[v5] = (int)v6;
  }
  JUMPOUT(0x94800);
}
// 94371: control flows out of bounds to 94800
// 192ED4: using guessed type int dword_192ED4;
// 19C45C: using guessed type int dword_19C45C[27];
// 19C4CC: using guessed type int dword_19C4CC[27];


//----- (00094376) --------------------------------------------------------
int sub_94376()
{
  int16_t i; // dx
  int result; // eax

  for ( i = 0; i < 67; ++i )
  {
    result = dword_1930DC + 59 * i;
    if ( *(_BYTE *)(result + 57) == 2 )
    {
      *(_BYTE *)(result + 57) = 0;
      *(_BYTE *)(result + 55) = 0;
    }
  }
  return result;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (000943A0) --------------------------------------------------------
void __fastcall sub_943A0( int a1)
{
  int v2; // ebx
  int v3; // eax
  int16_t *v4; // edi
  char *v5; // esi
  char v6; // al
  int16_t *v7; // eax
  int16_t v8; // bx
  int16_t v9; // cx
  int v10; // eax
  int v11; // ebx
  int16_t v12[100]; // [esp+0h] [ebp-190h] BYREF
  _BYTE v13[200]; // [esp+C8h] [ebp-C8h] BYREF

  v2 = a1;
  v3 = 59 * a1 + dword_1930DC;
  if ( *(_BYTE *)(v3 + 57) == 4 )
  {
    v4 = v12;
    v5 = sub_7A990(0x12Bu);
    do
    {
      v6 = *v5++;
      *(_BYTE *)v4 = v6;
      v4 = (int16_t *)((char *)v4 + 1);
    }
    while ( v6 );
    v7 = sub_97588(v2, 0);
    sprintf(v13, (char *)v12, v7);
    sub_94B3A((int)v13, 3u, v2, v12, (int16_t)v5);
  }
  else
  {
    v8 = *(_WORD *)(v3 + 53);
    v9 = *(char *)(v3 + 58);
    sub_123E6C((int)&unk_17CF00, 1);
    if ( byte_199F1F )
    {
      if ( v8 > -1 )
        *(_BYTE *)(113 * v8 + dword_19306C + v9 + 66) = -1;
    }
    else if ( v8 > -1 && v8 < word_199994 )
    {
      *(_WORD *)(dword_197F9C + 129 * v8 + 116) = -1;
    }
    v10 = 59 * a1;
    v11 = dword_1930DC;
    byte_19C544 = -1;
    *(_BYTE *)(dword_1930DC + v10 + 57) = 2;
    byte_199F15 = -1;
    *(_WORD *)(v11 + v10 + 53) = -1;
  }
  JUMPOUT(0x94800);
}
// 9440A: control flows out of bounds to 94800
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199F15: using guessed type char byte_199F15;
// 199F1F: using guessed type char byte_199F1F;
// 19C544: using guessed type char byte_19C544;


//----- (000944A3) --------------------------------------------------------
int __usercall sub_944A3( int a1, int a2)
{
  int v3; // eax
  int16_t v4; // cx
  int16_t v5; // bx
  char v6; // al
  int v7; // eax
  int result; // eax

  v3 = 59 * a1 + dword_1930DC;
  v4 = *(char *)(v3 + 58);
  if ( *(int16_t *)(v3 + 53) != -1 && *(_BYTE *)(v3 + 57) != 5 )
  {
    v5 = *(_WORD *)(v3 + 53);
    v6 = *(_BYTE *)(v3 + 35);
    if ( v6 )
    {
      if ( v6 == 1 )
        *(_BYTE *)(113 * v5 + dword_19306C + v4 + 66) = -1;
    }
    else
    {
      v7 = dword_197F9C + 129 * v5;
      if ( a1 == *(_WORD *)(v7 + 116) )
        *(_WORD *)(v7 + 116) = -1;
    }
  }
  result = dword_1930DC + 59 * a1;
  *(_BYTE *)(result + 57) = 0;
  *(_BYTE *)(result + 55) = 0;
  *(_WORD *)(result + 53) = -1;
  if ( *(_BYTE *)(result + 35) == 1 )
    return sub_E2D72(*(char *)(result + 58), a2);
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;


//----- (0009453C) --------------------------------------------------------
void __usercall sub_9453C(_BYTE *a1, int16_t *a2, int a3)
{
  int16_t v4; // ax
  int v5; // edx
  int v6; // eax

  word_1999D8 = -1;
  word_1999C0 = -1;
  word_19991C = -1;
  word_19990E = -1;
  word_1999C6 = -1;
  sub_A20CD();
  if ( byte_199F1F == 1 )
  {
    if ( word_19C53E == -1 && byte_199F19 == 1 )
    {
      v4 = word_199838;
    }
    else
    {
      if ( word_19C53E != -1 )
      {
LABEL_8:
        sub_A3FE6(word_19C53E);
        byte_199F11 = 1;
        word_19C540 = word_19C53E;
        sub_968D1((int)a1, a2);
        goto LABEL_13;
      }
      sub_85BDD();
    }
    byte_199F15 = -1;
    word_19C53E = v4;
    goto LABEL_8;
  }
  sub_772C4(0);
  if ( word_1999D8 != -1 && (uint16_t)sub_77FE9(word_192248[word_1999D8]) != word_19999C )
    word_1999D8 = -1;
  v5 = *(int16_t *)(dword_1975C4 + 12);
  sub_7563F(word_1999D8);
  sub_968D1((int)a1, a2);
  byte_199F11 = 1;
  byte_19C545 = 1;
  sub_93550(a3);
  sub_1077D(v6, v5, (int)a1, a2);
  sub_585E0(word_19999C, v5);
  byte_199F15 = -1;
  word_1999BE = -1;
LABEL_13:
  *a1 = 1;
  byte_199F11 = 1;
}
// 945B0: variable 'v4' is possibly undefined
// 9463E: variable 'v6' is possibly undefined
// 192248: using guessed type int16_t word_192248[500];
// 1975C4: using guessed type int dword_1975C4;
// 199838: using guessed type int16_t word_199838;
// 19990E: using guessed type int16_t word_19990E;
// 19991C: using guessed type int16_t word_19991C;
// 19999C: using guessed type int16_t word_19999C;
// 1999BE: using guessed type int16_t word_1999BE;
// 1999C0: using guessed type int16_t word_1999C0;
// 1999C6: using guessed type int16_t word_1999C6;
// 1999D8: using guessed type int16_t word_1999D8;
// 199F11: using guessed type char byte_199F11;
// 199F15: using guessed type char byte_199F15;
// 199F19: using guessed type char byte_199F19;
// 199F1F: using guessed type char byte_199F1F;
// 19C53E: using guessed type int16_t word_19C53E;
// 19C540: using guessed type int16_t word_19C540;
// 19C545: using guessed type char byte_19C545;


//----- (0009467D) --------------------------------------------------------
_BOOL1 __fastcall sub_9467D(int a1, int a2, int a3)
{
  return (*(_DWORD *)(dword_1930DC + 59 * a2 + 38) & *(int *)((char *)&dword_17D219 + 18 * a3)) != 0;
}
// 17D219: using guessed type int dword_17D219;
// 1930DC: using guessed type int dword_1930DC;


//----- (0009469E) --------------------------------------------------------
void sub_9469E()
{
  JUMPOUT(0x94694);
}
// 946B5: control flows out of bounds to 94694
// 1930DC: using guessed type int dword_1930DC;


//----- (000946B7) --------------------------------------------------------
int __fastcall sub_946B7( int a1)
{
  int v1; // ecx
  int16_t i; // si
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int16_t j; // dx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax

  v1 = 0;
  for ( i = 0; i < 54; ++i )
  {
    if ( !byte_17D21D[18 * i] && sub_9467D(word_19999C, a1, i) )
    {
      LOWORD(v3) = (uint8_t)byte_17D221[18 * i];
      if ( i == 2 || i == 3 )
      {
        v3 = *(_BYTE *)(dword_1930DC + 59 * a1 + 35) ? 1 : 3;
        if ( i == 3 )
          v3 *= 2;
      }
      v1 += v3;
    }
    v4 = dword_1930DC + 59 * a1;
    if ( *(_BYTE *)(v4 + 35) )
    {
      if ( *(_BYTE *)(v4 + 35) == 1 )
      {
        v5 = 18 * i;
        if ( byte_17D21D[v5] == 2 )
        {
          sub_9469E();
          if ( (_BYTE)v6 )
          {
LABEL_19:
            LOWORD(v6) = (uint8_t)byte_17D221[v5];
            v1 += v6;
            continue;
          }
        }
      }
    }
    else
    {
      v5 = 18 * i;
      if ( byte_17D21D[v5] == 1 )
      {
        sub_9469E();
        if ( (_BYTE)v6 )
          goto LABEL_19;
      }
    }
  }
  for ( j = 0; j < 3; ++j )
  {
    v8 = dword_1930DC + 59 * a1 + j;
    if ( *(_BYTE *)(v8 + 46) )
    {
      v9 = *(int16_t *)((char *)&word_17E07F + 13 * *(uint8_t *)(v8 + 46));
      if ( v9 <= -1 )
      {
        v1 = 1;
      }
      else
      {
        v10 = *(int *)((char *)&dword_17D916 + 23 * v9);
        if ( v10 >= 1000 )
        {
          if ( v10 >= 5000 )
            v11 = 4;
          else
            v11 = 3;
        }
        else
        {
          v11 = 1;
        }
        v1 += v11;
      }
    }
  }
  return v1;
}
// 94723: variable 'v3' is possibly undefined
// 94757: variable 'v6' is possibly undefined
// 17D916: using guessed type int dword_17D916;
// 17E07F: using guessed type int16_t word_17E07F;
// 1930DC: using guessed type int dword_1930DC;
// 19999C: using guessed type int16_t word_19999C;


//----- (00094877) --------------------------------------------------------
char __fastcall sub_94877( int a1)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 3701);
}
// 197F98: using guessed type int dword_197F98;


//----- (0009488F) --------------------------------------------------------
void __fastcall sub_9488F( int a1)
{
  int16_t v2; // di
  int16_t v3; // cx
  int v4; // eax
  int v5; // eax
  int16_t v6; // bx
  int16_t v7; // [esp+0h] [ebp-8h]

  v7 = 0;
  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = dword_1930DC + 59 * v3;
    if ( *(char *)(v4 + 58) != a1 || *(_BYTE *)(v4 + 57) > 1u )
      goto LABEL_11;
    v5 = dword_1930DC + 59 * v3;
    if ( (*(_DWORD *)(v5 + 38) & dword_17D2CD) != 0 )
    {
      v6 = 10;
    }
    else
    {
      if ( (*(_DWORD *)(v5 + 38) & dword_17D2DF) == 0 )
        goto LABEL_9;
      v6 = 11;
    }
    v7 = sub_94BB2(a1, v3, v6);
LABEL_9:
    if ( v2 < v7 )
      v2 = v7;
LABEL_11:
    if ( ++v3 >= 67 )
      JUMPOUT(0x94800);
  }
}
// 94924: control flows out of bounds to 94800
// 17D2CD: using guessed type int dword_17D2CD;
// 17D2DF: using guessed type int dword_17D2DF;
// 1930DC: using guessed type int dword_1930DC;


//----- (00094951) --------------------------------------------------------
int __fastcall sub_94951(int a1)
{
  int16_t v1; // ax
  char v2; // dl
  int result; // eax

  if ( a1 == 66 )
  {
    v1 = *(_WORD *)(dword_1930DC + 3930);
    v2 = 0;
  }
  else
  {
    v2 = *(_BYTE *)(3753 * *(char *)(59 * a1 + dword_1930DC + 58) + dword_197F98 + 2237);
    v1 = *(_WORD *)(59 * a1 + dword_1930DC + 36);
  }
  LOWORD(result) = sub_93D4B(v1, v2);
  if ( (int16_t)result <= 5 )
    return (int16_t)result;
  else
    return 5;
}
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (000949A7) --------------------------------------------------------
char __fastcall sub_949A7( int a1, int a2)
{
  char v3; // dl
  int16_t i; // bx
  int v5; // ecx
  int v7; // eax
  int16_t v8; // dx
  int16_t v9; // dx

  v3 = 0;
  for ( i = 0; i < 67 && !v3; ++i )
  {
    v5 = 59 * i;
    if ( *(_BYTE *)(v5 + dword_1930DC + 57) == 1 && *(int16_t *)(v5 + dword_1930DC + 53) != -1
      || !*(_BYTE *)(dword_1930DC + 59 * i + 57) )
    {
      v7 = 59 * i + dword_1930DC;
      if ( *(char *)(v7 + 58) == a1 )
      {
        if ( *(_BYTE *)(v7 + 56) )
        {
          if ( a2 )
          {
            v8 = *(_WORD *)(v7 + 53);
            if ( !*(_BYTE *)(v7 + 35) && v8 > -1 )
            {
              v9 = *(_WORD *)(dword_197F9C + 129 * v8 + 101);
              if ( v9 < 500 || v9 >= 1000 )
                v8 = sub_78E07(v9);
              else
                v8 = -1;
            }
            sub_C8209(v8, i);
            *(_BYTE *)(dword_1930DC + 59 * i + 56) = 0;
          }
          v3 = 1;
        }
      }
    }
  }
  return v3;
}
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;


//----- (00094A9D) --------------------------------------------------------
int __fastcall sub_94A9D( int a1, int a2)
{
  int16_t v3; // ax
  int v4; // edi
  _BOOL1 v5; // al

  sub_97A2D(a1, a2);
  v4 = (v3 + 99) / 100;
  if ( (*(_DWORD *)(59 * a2 + dword_1930DC + 38) & dword_17D411) != 0 || (v5 = sub_9467D(a1, a2, 29)) )
    v5 = 1;
  if ( a2 == 65 || v5 )
    return 0;
  if ( (int16_t)v4 <= 1 )
    return 1;
  return (int16_t)v4;
}
// 94AB0: variable 'v3' is possibly undefined
// 17D411: using guessed type int dword_17D411;
// 1930DC: using guessed type int dword_1930DC;


//----- (00094B3A) --------------------------------------------------------
int __usercall sub_94B3A(
        int a1, unsigned int a2,
        int a3,
        int16_t *a4, int a5)
{
  int v5; // ecx
  int v6; // eax
  int v7; // eax

  v5 = -1;
  if ( !a2 )
    goto LABEL_12;
  if ( a2 <= 1u )
  {
    sub_77658(a1);
    v5 = v6;
  }
  else
  {
    if ( a2 < 3u )
    {
LABEL_12:
      sub_77423(a1);
      goto LABEL_13;
    }
    if ( a2 <= 3u )
    {
      sub_77433(a1);
    }
    else
    {
      if ( a2 != 5 )
        goto LABEL_12;
      if ( byte_199F09 < 0 )
        byte_199F09 = 126;
      a3 = byte_199F09;
      a2 = a1;
      sub_A5EBC(0, a1, byte_199F09);
      byte_199F09 = 0;
    }
  }
LABEL_13:
  sub_124D41();
  byte_199F11 = 1;
  sub_93550(a5);
  sub_1077D(v7, a2, a3, a4);
  return v5;
}
// 94B65: variable 'v6' is possibly undefined
// 94BA8: variable 'v7' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// A5EBC: using guessed type int __fastcall sub_A5EBC(_DWORD, _DWORD, _DWORD);
// 199F09: using guessed type char byte_199F09;
// 199F11: using guessed type char byte_199F11;


//----- (00094BB2) --------------------------------------------------------
int __fastcall sub_94BB2(int a1, int a2, int a3)
{
  int v3; // eax
  int16_t v4; // ax

  v3 = dword_1930DC + 59 * a2;
  if ( *(char *)(v3 + 58) == -1 )
  {
    v4 = sub_93D4B(*(_WORD *)(v3 + 36), 0);
    if ( v4 > 5 )
      v4 = 5;
  }
  else
  {
    v4 = sub_94951(a2);
  }
  return word_17D21E[9 * a3]
       * (int16_t)(((int16_t)(v4 + 1) + (uint8_t)byte_17D220[18 * a3] - 1)
                 / (uint8_t)byte_17D220[18 * a3])
       / 10;
}
// 17D21E: using guessed type int16_t word_17D21E[];
// 1930DC: using guessed type int dword_1930DC;


//----- (00094C1D) --------------------------------------------------------
void __usercall sub_94C1D(int a1, int a2, int16_t *a3, int a4)
{
  int v4; // eax
  int v5; // ebx
  int16_t v6; // ax
  int16_t v7; // dx
  int v8; // eax
  int v9; // ebx
  int16_t v10; // dx
  int64_t v11; // rax
  int v12; // ebx
  uint16_t *v13; // ecx
  int v14; // eax
  int16_t v15; // dx
  int v16; // esi
  int16_t v17; // ax
  int v18; // eax
  int v19; // edx
  char *v20; // eax
  int v21; // edx
  int16_t *v22; // edi
  char v23; // al
  int16_t *v24; // eax
  int16_t v25; // dx
  int16_t v26; // dx
  int16_t v27; // dx
  int16_t v28; // ax
  char *v29; // eax
  void *v30; // eax
  void *v31; // eax
  int16_t v32; // dx
  int v33[25]; // [esp+0h] [ebp-20Ch] BYREF
  int64_t v34; // [esp+64h] [ebp-1A8h]
  int v35; // [esp+6Ch] [ebp-1A0h]
  int16_t v36[100]; // [esp+C8h] [ebp-144h] BYREF
  _BYTE v37[8]; // [esp+190h] [ebp-7Ch] BYREF
  _BYTE v38[8]; // [esp+198h] [ebp-74h] BYREF
  int v39; // [esp+1A0h] [ebp-6Ch] BYREF
  int v40; // [esp+1A4h] [ebp-68h] BYREF
  char *v41; // [esp+1A8h] [ebp-64h]
  int v42; // [esp+1ACh] [ebp-60h] BYREF
  int v43; // [esp+1B0h] [ebp-5Ch] BYREF
  uint16_t v44; // [esp+1B4h] [ebp-58h] BYREF
  int16_t v45; // [esp+1B8h] [ebp-54h] BYREF
  int16_t v46; // [esp+1BCh] [ebp-50h] BYREF
  int16_t v47; // [esp+1C0h] [ebp-4Ch] BYREF
  int v48; // [esp+1C4h] [ebp-48h] BYREF
  int16_t v49; // [esp+1C8h] [ebp-44h] BYREF
  int16_t v50; // [esp+1CCh] [ebp-40h] BYREF
  uint16_t v51; // [esp+1D0h] [ebp-3Ch] BYREF
  int16_t v52; // [esp+1D4h] [ebp-38h] BYREF
  int16_t v53; // [esp+1D8h] [ebp-34h] BYREF
  int16_t v54; // [esp+1DCh] [ebp-30h] BYREF
  int v55; // [esp+1E0h] [ebp-2Ch]
  uint16_t v56; // [esp+1E4h] [ebp-28h] BYREF
  int16_t v57; // [esp+1E8h] [ebp-24h] BYREF
  uint16_t v58; // [esp+1ECh] [ebp-20h] BYREF
  int16_t v59; // [esp+1F0h] [ebp-1Ch] BYREF
  int v60; // [esp+1F4h] [ebp-18h]
  int v61; // [esp+1F8h] [ebp-14h]
  int v62; // [esp+1FCh] [ebp-10h] BYREF
  int16_t v63; // [esp+200h] [ebp-Ch] BYREF
  char v64[4]; // [esp+204h] [ebp-8h] BYREF
  _BOOL1 v65; // [esp+208h] [ebp-4h]

  v64[0] = 0;
  LOWORD(a1) = word_199992;
  v60 = a1;
  sub_128BE7();
  sub_12B65C();
  sub_11C2F0();
  byte_182ACE = 0;
  byte_19C548 = 2;
  byte_19C546 = 0;
  byte_19C547 = 1;
  byte_19C545 = 0;
  byte_19C543 = 0;
  word_19C53C = -1;
  byte_19C542 = 0;
  byte_19C544 = -1;
  word_19992C = 0;
  word_19992E = 0;
  byte_199EFC = 0;
  word_199912 = 0;
  word_1999D8 = -1;
  word_1999BE = -1;
  word_19992A = -1;
  word_199960 = -1;
  word_1999C0 = -1;
  word_19991C = -1;
  word_19990E = -1;
  byte_199F29 = 0;
  word_199910 = -1;
  sub_A20CD();
  sub_131922(0, 255);
  sub_C5BB9();
  if ( byte_199F19 == 1 )
  {
    byte_199F1F = 1;
    if ( word_199838 > -1 )
      word_1999D8 = word_199838;
  }
  if ( byte_199F1F == -1 )
    byte_199F1F = 0;
  sub_968D1(a2, a3);
  sub_A0305();
  v4 = sub_77048(
         v33[0],
         v33[1],
         v33[2],
         v33[3],
         v33[4],
         v33[5],
         v33[6],
         v33[7],
         v33[8],
         v33[9],
         v33[10],
         v33[11],
         v33[12],
         v33[13],
         v33[14],
         v33[15],
         v33[16],
         v33[17],
         v33[18],
         v33[19],
         v33[20],
         v33[21],
         v33[22],
         v33[23],
         v33[24],
         v34,
         v35);
  if ( byte_199F1F )
  {
    word_19C53E = word_199838;
    word_19C540 = word_199838;
    if ( word_199838 == -1 )
      word_19C540 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_197F98 + 3753 * word_19999C + 41) + 2);
    sub_A3FE6(word_19C53E);
  }
  else if ( word_1999D8 < 0 )
  {
    LOBYTE(v4) = byte_199F1F == 0;
    sub_772BF(v4, 235, 318, 169);
  }
  byte_199F11 = 1;
  if ( word_1999D8 != -1 && (uint16_t)sub_77FE9(word_192248[word_1999D8]) != word_19999C )
    word_1999D8 = -1;
  sub_1191CA((int)sub_93550, 1);
  word_1999A4 = 302;
  word_1999A8 = 19;
  byte_199F14 = 5;
  byte_199F10 = 3;
  byte_199F0E = 15;
  sub_9264E(&v53, &v57, &v59, &v58, &v63, (int)v37, (int)v38, &v56, &v44, &v51, &v50, &v52);
  v5 = dword_1975C4;
  *(_WORD *)(dword_1975C4 + 10) = 3;
  *(_WORD *)(v5 + 14) = 121;
  v6 = sub_A00F1((_WORD *)v5);
  *(_WORD *)(v5 + 6) = v6;
  byte_199F13 = 1;
  byte_199F15 = -1;
  *(_WORD *)(v5 + 2) = -1;
  byte_199F0F = -1;
  *(_BYTE *)(v5 + 24) = 2;
  word_19991A = -1;
  v7 = *(_WORD *)(v5 + 14);
  *(_BYTE *)(v5 + 26) = 1;
  word_1999C6 = -1;
  *(_WORD *)v5 = v7 - v6 / 2;
  sub_A20CD();
  v8 = 0;
  do
  {
    v9 = (int16_t)v8;
    v10 = *(_WORD *)(dword_1930DC + 59 * (int16_t)v8++ + 53);
    *(_WORD *)(dword_1930EC + 2 * v9) = v10;
  }
  while ( (int16_t)v8 < 67 );
  LODWORD(v11) = 0;
  do
  {
    v12 = (int16_t)v11;
    HIDWORD(v11) = dword_1930DC + 59 * (int16_t)v11;
    v13 = (uint16_t *)dword_193114;
    WORD2(v11) = *(_WORD *)(HIDWORD(v11) + 53);
    LODWORD(v11) = v11 + 1;
    *(_WORD *)(dword_193114 + 2 * v12) = WORD2(v11);
  }
  while ( (int16_t)v11 < 67 );
  byte_199F11 = 1;
  byte_199F09 = 1;
  v61 = 0;
  word_199A10 = (uint8_t)byte_199F19;
  sub_93BB0(a3, a4);
  byte_199F09 = 0;
  sub_9872C();
  while ( 1 )
  {
    if ( (_WORD)v61 )
    {
      sub_11C2F0();
      sub_119281();
      sub_123E6C((int)&unk_17CF00, 1);
      sub_94376();
      sub_92F8A((int)a3);
      sub_E2D72(word_19999C, (int)a3);
      byte_199F38 = 0;
      dword_19C4C8 = 0;
      dword_1975C4 = 0;
      word_199992 = v60;
      JUMPOUT(0x94800);
    }
    v65 = byte_199F1F == 0;
    sub_12C2A0();
    v14 = sub_1171AB(v11, SHIDWORD(v11), v12, (int)v13);
    v15 = v14;
    v55 = v14;
    v41 = sub_114177();
    if ( v15 == v57 )
    {
      sub_123E6C((int)&unk_17CF00, 1);
      byte_19C544 = -1;
      word_19991A = -1;
      byte_199F15 = -1;
      byte_199F11 = 1;
    }
    if ( (_WORD)v55 == v53 )
    {
      if ( byte_199F15 <= -1 )
      {
        if ( byte_19C544 )
        {
          sub_123E6C((int)&unk_18228C, 1);
          byte_19C544 = 0;
          word_19991A = -1;
          byte_199F15 = -1;
        }
        else
        {
          sub_123E6C((int)&unk_17CF00, 1);
          byte_19C544 = -1;
          word_19991A = -1;
          byte_199F11 = 1;
        }
      }
      else
      {
        sub_98062(byte_199F15);
      }
    }
    v16 = (int16_t)v41;
    a3 = (int16_t *)(int16_t)v55;
    sub_9301E((int16_t *)(int16_t)v55, (char *)(int16_t)v41, (int)v37, (int)v38);
    if ( byte_19C544 == -1 )
    {
      if ( (uint16_t)sub_749F0(v16, (int16_t)a3, &v62, &v48) || !sub_941BB() )
      {
        if ( (int16_t)v62 > -1 )
        {
          word_19990E = v62;
          word_199960 = -1;
          word_19991C = -1;
        }
      }
      else
      {
        byte_199F11 = 1;
        sub_968D1((int)&v62, a3);
      }
    }
    if ( byte_19C544 == -1 && v65 )
    {
      v17 = sub_97041((int16_t)v41, v55, (int16_t *)&v62, (int16_t *)&v48);
      word_19991C = v62;
      if ( (int16_t)v62 > -1 )
      {
        word_199960 = -1;
        word_19990E = -1;
      }
      if ( v17 )
      {
        if ( v17 == 1 )
        {
          v25 = *(_WORD *)(dword_192B24 + 13 * (int16_t)v48 + 11);
          sub_1196F7();
          sub_31F25(v25);
          sub_9872C();
          byte_199F11 = 1;
        }
      }
      else
      {
        byte_199F11 = 1;
        if ( (_WORD)v48 == word_19991A )
        {
          v18 = 13 * (int16_t)v48;
          v19 = dword_192B24;
          word_19991A = -1;
LABEL_42:
          *(_BYTE *)(v19 + v18 + 4) = 0;
          goto LABEL_57;
        }
        if ( (int16_t)v48 > -1 )
        {
          if ( sub_78182(*(_WORD *)(13 * (int16_t)v48 + dword_192B24 + 11)) )
          {
            word_19991A = v48;
            sub_77393();
            *(_BYTE *)(13 * word_19991A + dword_192B24 + 4) = 1;
            if ( byte_199F15 > -1 && byte_199F15 < 67 )
            {
              if ( sub_94254(byte_199F15) )
              {
                sub_987FB(byte_199F15, *(int16_t *)(dword_192B24 + 13 * (int16_t)v48 + 11), (int)&v62);
                v21 = 13 * word_19991A;
                byte_199F11 = 1;
                byte_199F15 = -1;
                word_19991A = -1;
                *(_BYTE *)(v21 + dword_192B24 + 4) = 0;
              }
              else
              {
                v22 = v36;
                v16 = (int)sub_7A990(0x12Du);
                do
                {
                  v23 = *(_BYTE *)v16++;
                  *(_BYTE *)v22 = v23;
                  v22 = (int16_t *)((char *)v22 + 1);
                }
                while ( v23 );
                a3 = v36;
                v24 = sub_97588(byte_199F15, 0);
                sprintf(v33, (char *)v36, v24);
                sub_94B3A((int)v33, 0, (int)&v62, v36, v16);
              }
              if ( word_19991A > -1 )
              {
                v18 = 13 * word_19991A;
                v19 = dword_192B24;
                goto LABEL_42;
              }
            }
          }
          else
          {
            v20 = sub_7A990(0x12Cu);
            sub_94B3A((int)v20, 3u, (int)&v62, a3, v16);
          }
        }
      }
    }
LABEL_57:
    if ( byte_19C544 == -1 )
    {
      v26 = sub_890EF((int16_t)v41, v55, (int16_t *)&v39, (int16_t *)&v43);
      if ( (int16_t)v39 > -1 )
      {
        word_19990E = -1;
        word_19991C = -1;
        word_199960 = v39;
      }
      if ( !v26 && !v65 && (int16_t)v43 > -1 && sub_78D71(word_19999C, v43) )
      {
        if ( (_WORD)v43 == word_19C540 )
        {
          word_19C540 = -1;
        }
        else
        {
          byte_199F15 = -1;
          byte_199F11 = 1;
          word_19C540 = v43;
        }
        word_19C53E = v43;
      }
    }
    if ( byte_19C544 == -1 && !v65 )
    {
      v27 = sub_899AB((int16_t)v41, v55, (int)word_1992D4, &v54, &v46, (int16_t *)&v42, &v45, (int16_t *)&v40);
      word_1999DC = v42;
      if ( (int16_t)v40 > -1 )
        word_1999C0 = v40;
      if ( !v27 && v46 > -1 )
      {
        v28 = *(_WORD *)(dword_1930D4 + 17 * sub_79C54(word_19C53E, v46));
        if ( v28 > -1 && v28 < word_199996 && byte_19C19D == 39 )
        {
          v29 = sub_7A990(0x12Eu);
          sub_94B3A((int)v29, 0, (int)word_1992D4, a3, v16);
        }
      }
    }
    if ( byte_19C544 == -1 && (_WORD)v55 == v51 )
    {
      if ( byte_199F1F )
      {
        sub_8302C(&word_19C53E, word_19999C, 0);
        word_19C540 = word_19C53E;
      }
      else
      {
        sub_82DFF(&word_1999D8, &v47, 0);
        v64[0] = 1;
        word_19991C = -1;
      }
    }
    if ( byte_19C544 == -1 && (_WORD)v55 == v50 )
    {
      if ( byte_199F1F )
      {
        sub_8302C(&word_19C53E, word_19999C, 1);
        word_19C540 = word_19C53E;
      }
      else
      {
        sub_82DFF(&word_1999D8, &v49, 1);
        v64[0] = 1;
        word_19991C = -1;
      }
    }
    if ( (_WORD)v55 == word_19C538 )
    {
      if ( byte_19C544 == 2 )
      {
        v30 = &unk_17CF00;
        byte_19C544 = -1;
      }
      else
      {
        v30 = &unk_18228C;
        byte_19C544 = 2;
      }
      sub_123E6C((int)v30, 1);
    }
    if ( (_WORD)v55 == word_19C53A )
    {
      if ( byte_19C544 == 1 )
      {
        v31 = &unk_17CF00;
        byte_19C544 = -1;
LABEL_99:
        sub_123E6C((int)v31, 1);
        goto LABEL_100;
      }
      if ( byte_199F15 <= -1 )
      {
        v31 = &unk_18228C;
        byte_19C544 = 1;
        goto LABEL_99;
      }
      sub_943A0(byte_199F15);
    }
LABEL_100:
    if ( byte_19C544 == -1 && (_WORD)v55 == v44 )
    {
      sub_A015D((int16_t *)dword_1975C4);
    }
    else if ( byte_19C544 == -1 && (_WORD)v55 == v56 )
    {
      sub_A01C6((int16_t *)dword_1975C4);
    }
    if ( byte_19C544 == -1 && ((_WORD)v55 == v58 || (_WORD)v55 == v59) )
    {
      v32 = byte_199F1F;
      byte_199F1F = (_WORD)v55 == v58;
      if ( ((_WORD)v55 == v58) != v32 )
      {
        sub_9453C(v64, a3, v16);
        v42 = -1;
      }
    }
    if ( (_WORD)v55 == v63 )
    {
      v61 = 1;
      word_199A08 = word_199A10;
    }
    sub_11C2F0();
    v13 = &v58;
    v12 = (int)&v59;
    v11 = sub_9264E(&v53, &v57, &v59, &v58, &v63, (int)v37, (int)v38, &v56, &v44, &v51, &v50, &v52);
    if ( v64[0] )
    {
      v64[0] = 0;
      sub_9872C();
      if ( !byte_199F1F )
      {
        v12 = dword_1975C4;
        *(_WORD *)(dword_1975C4 + 10) = 3;
        *(_WORD *)(v12 + 14) = 121;
        LOWORD(v11) = sub_A00F1((_WORD *)v12);
        *(_WORD *)(v12 + 6) = v11;
        *(_WORD *)(v12 + 2) = -1;
        *(_BYTE *)(v12 + 24) = 2;
        HIDWORD(v11) = *(int16_t *)(v12 + 14);
        *(_BYTE *)(v12 + 26) = 1;
        HIDWORD(v11) -= (int16_t)v11 / 2;
        *(_WORD *)v12 = WORD2(v11);
      }
    }
    if ( !(_WORD)v61 )
    {
      sub_124D41();
      sub_93550(v16);
      sub_1077D(v11, SHIDWORD(v11), v12, a3);
    }
    sub_12C2C6(1);
  }
}
// 956DD: control flows out of bounds to 94800
// 94F73: variable 'v11' is possibly undefined
// 772BF: using guessed type int __fastcall sub_772BF(_DWORD, _DWORD, _DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACE: using guessed type char byte_182ACE;
// 192248: using guessed type int16_t word_192248[500];
// 192B24: using guessed type int dword_192B24;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 1930EC: using guessed type int dword_1930EC;
// 193114: using guessed type int dword_193114;
// 1975C4: using guessed type int dword_1975C4;
// 197F98: using guessed type int dword_197F98;
// 1992D4: using guessed type int16_t word_1992D4[10];
// 199838: using guessed type int16_t word_199838;
// 19990E: using guessed type int16_t word_19990E;
// 199910: using guessed type int16_t word_199910;
// 199912: using guessed type int16_t word_199912;
// 19991A: using guessed type int16_t word_19991A;
// 19991C: using guessed type int16_t word_19991C;
// 19992A: using guessed type int16_t word_19992A;
// 19992C: using guessed type int16_t word_19992C;
// 19992E: using guessed type int16_t word_19992E;
// 199960: using guessed type int16_t word_199960;
// 199992: using guessed type int16_t word_199992;
// 199996: using guessed type int16_t word_199996;
// 19999C: using guessed type int16_t word_19999C;
// 1999A4: using guessed type int16_t word_1999A4;
// 1999A8: using guessed type int16_t word_1999A8;
// 1999BE: using guessed type int16_t word_1999BE;
// 1999C0: using guessed type int16_t word_1999C0;
// 1999C6: using guessed type int16_t word_1999C6;
// 1999D8: using guessed type int16_t word_1999D8;
// 1999DC: using guessed type int16_t word_1999DC;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199EFC: using guessed type char byte_199EFC;
// 199F09: using guessed type char byte_199F09;
// 199F0E: using guessed type char byte_199F0E;
// 199F0F: using guessed type char byte_199F0F;
// 199F10: using guessed type char byte_199F10;
// 199F11: using guessed type char byte_199F11;
// 199F13: using guessed type char byte_199F13;
// 199F14: using guessed type char byte_199F14;
// 199F15: using guessed type char byte_199F15;
// 199F19: using guessed type char byte_199F19;
// 199F1F: using guessed type char byte_199F1F;
// 199F29: using guessed type char byte_199F29;
// 199F38: using guessed type char byte_199F38;
// 19C19D: using guessed type char byte_19C19D;
// 19C4C8: using guessed type int dword_19C4C8;
// 19C538: using guessed type int16_t word_19C538;
// 19C53A: using guessed type int16_t word_19C53A;
// 19C53C: using guessed type int16_t word_19C53C;
// 19C53E: using guessed type int16_t word_19C53E;
// 19C540: using guessed type int16_t word_19C540;
// 19C542: using guessed type char byte_19C542;
// 19C543: using guessed type char byte_19C543;
// 19C544: using guessed type char byte_19C544;
// 19C545: using guessed type char byte_19C545;
// 19C546: using guessed type char byte_19C546;
// 19C547: using guessed type char byte_19C547;
// 19C548: using guessed type char byte_19C548;


//----- (000956E2) --------------------------------------------------------
int __fastcall sub_956E2( int a1, int a2, int a3, int a4)
{
  int16_t v5; // di
  int v6; // eax
  char *v7; // eax
  int64_t v8; // rax
  int16_t v9; // di
  int v10; // ecx
  int v11; // edi
  _BYTE v13[20]; // [esp+0h] [ebp-20h] BYREF
  int v14; // [esp+14h] [ebp-Ch]
  int v15; // [esp+18h] [ebp-8h]
  int v16; // [esp+1Ch] [ebp-4h]

  v5 = *(char *)(59 * a1 + dword_1930DC + 55);
  sub_120DB3(2, (int)&unk_18227C);
  sub_120DED(0, 0);
  LOWORD(v6) = sub_122259();
  v15 = v6;
  v7 = sub_7A990(0x12Fu);
  v8 = sprintf(v13, v7, v5);
  v9 = sub_12066F((int)v13);
  v16 = HIDWORD(v8);
  v10 = a4 / 2 + a2 - v9 / 2;
  sub_1212B3(v10, SWORD2(v8), (int)v13);
  v11 = (int16_t)(v9 + v10);
  sub_134D2D((int16_t)v10, (int16_t)(v16 - 4), v11, (int16_t)(v16 - 4), 129);
  sub_134D2D((int16_t)v10, (int16_t)(v16 - 3), v11, (int16_t)(v16 - 3), 75);
  v14 = v15 + v16;
  sub_134D2D((int16_t)v10, (int16_t)(v15 + v16), v11, (int16_t)(v15 + v16), 75);
  return sub_134D2D((int16_t)v10, (int16_t)(v14 + 1), v11, (int16_t)(v14 + 1), 129);
}
// 95718: variable 'v6' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1930DC: using guessed type int dword_1930DC;


//----- (000957E3) --------------------------------------------------------
void __fastcall sub_957E3( int a1)
{
  int16_t v1; // bx
  int v2; // edx
  int v3; // eax
  int16_t v4; // cx
  int16_t v5; // si
  int16_t v6; // ax
  int16_t v7; // ax
  int v8; // edx
  int v9; // eax
  char v10; // bl
  char *v11; // eax
  uint16_t v12; // ax
  char *v13; // eax
  char *v14; // edi
  uint16_t v15; // ax
  char *v16; // eax
  char *v17; // edi
  uint16_t v18; // ax
  char *v19; // eax
  char *v20; // edi
  int16_t i; // bx
  char *v22; // eax
  char *v23; // edi
  unsigned int v24; // kr04_4
  int16_t v25; // ax
  int v26; // [esp-4h] [ebp-20Eh] BYREF
  char v27[500]; // [esp+0h] [ebp-20Ah] BYREF
  char v28[40]; // [esp+1F4h] [ebp-16h] BYREF
  char v29[40]; // [esp+21Ch] [ebp+12h] BYREF
  _WORD v30[6]; // [esp+244h] [ebp+3Ah] BYREF
  _BYTE v31[8]; // [esp+250h] [ebp+46h] BYREF
  char v32[8]; // [esp+258h] [ebp+4Eh] BYREF
  int16_t v33; // [esp+260h] [ebp+56h] BYREF
  int v34; // [esp+264h] [ebp+5Ah]
  int v35; // [esp+268h] [ebp+5Eh]
  int16_t v36; // [esp+26Ch] [ebp+62h] BYREF
  int16_t v37; // [esp+270h] [ebp+66h] BYREF
  int16_t v38; // [esp+274h] [ebp+6Ah] BYREF
  int v39; // [esp+278h] [ebp+6Eh]
  int v40; // [esp+27Ch] [ebp+72h]
  int v41; // [esp+280h] [ebp+76h]
  int v42; // [esp+284h] [ebp+7Ah]
  int v43; // [esp+288h] [ebp+7Eh]

  v1 = word_1906C2[6 * a1];
  v2 = 129 * *(int16_t *)((char *)&word_1975D4 + 5 * v1);
  v3 = v2 + dword_197F9C;
  v40 = 1;
  v4 = *(_WORD *)(v2 + dword_197F9C + 103);
  LOWORD(v2) = *(_WORD *)(v2 + dword_197F9C + 105);
  v5 = *(char *)(v3 + 99);
  v35 = v2;
  v34 = 1;
  sub_120DED(0, 0);
  if ( word_199A08 == 29 )
  {
    v43 = 364;
    v41 = 412;
    v42 = 203;
  }
  else
  {
    v43 = 67;
    v41 = 248;
    v42 = 199;
  }
  v39 = 21;
  v29[0] = 0;
  if ( v1 < 5000 )
  {
    if ( v5 <= 8 )
      goto LABEL_8;
  }
  else
  {
    v1 -= 4991;
  }
  v6 = sub_77FE9(v1);
  sub_784A0(v6, v29);
LABEL_8:
  if ( v29[0] )
  {
    sub_132F5C((int)v29);
    strcpy(v28, v29);
    v26 = (int)v32;
    qmemcpy(v32, sub_8E5C5(4u, 76, 79), sizeof(v32));
    sub_120D79(4, (int)v32);
    sub_1210FD(v43 + 102, v41 + 5, (int)v28);
  }
  else
  {
    sub_A432F(v4, v35, v5, &v38, &v37, &v33, &v36, (int)v30);
    if ( v5 >= 8 )
      v7 = 73;
    else
      v7 = (uint8_t)byte_10010[*(uint8_t *)(3753 * v5 + dword_197F98 + 38)];
    sub_8F6F8(v40, v7, v7 + 5, v32);
    v8 = 1;
    do
    {
      v9 = (int16_t)v8;
      v10 = v32[(int16_t)v8++];
      v32[v9] += 2;
      v31[v9] = v10 + 4;
    }
    while ( (int16_t)v8 < 8 );
    sub_120F07((int)v31);
    sub_120D79(v40, (int)v32);
    sub_120E8C(v34);
    sub_784A0(v5, v29);
    v11 = sub_7A990(0x131u);
    sprintf(v27, v11, v29);
    sub_132F5C((int)v27);
    if ( v33 > 0 )
    {
      if ( v33 == 1 )
      {
        v26 = 1;
        v12 = 258;
      }
      else
      {
        v26 = v33;
        v12 = 259;
      }
      v13 = sub_7A990(v12);
      sprintf(v29, v13, v26);
      v26 = (int)v27;
      v14 = (char *)&v26 + 3;
      do
        ++v14;
      while ( *v14 );
      strcpy(v14, v29);
    }
    if ( v36 > 0 )
    {
      if ( v36 == 1 )
      {
        v26 = 1;
        v15 = 260;
      }
      else
      {
        v26 = v36;
        v15 = 261;
      }
      v16 = sub_7A990(v15);
      sprintf(v29, v16, v26);
      v26 = (int)v27;
      v17 = (char *)&v26 + 3;
      do
        ++v17;
      while ( *v17 );
      strcpy(v17, v29);
    }
    if ( v37 > 0 )
    {
      if ( v37 == 1 )
      {
        v26 = 1;
        v18 = 262;
      }
      else
      {
        v26 = v37;
        v18 = 263;
      }
      v19 = sub_7A990(v18);
      sprintf(v29, v19, v26);
      v26 = (int)v27;
      v20 = (char *)&v26 + 3;
      do
        ++v20;
      while ( *v20 );
      strcpy(v20, v29);
    }
    for ( i = 0; i < 6; ++i )
    {
      if ( (int16_t)v30[i] > 0 )
      {
        if ( v30[i] == 1 )
          v22 = (char *)*(&off_18003A + 9 * i);
        else
          v22 = (char *)*(&off_18003E + 9 * i);
        sprintf(v29, "%d %s, ", (int16_t)v30[i], v22);
        v26 = (int)v27;
        v23 = (char *)&v26 + 3;
        do
          ++v23;
        while ( *v23 );
        strcpy(v23, v29);
      }
    }
    v24 = strlen(v27) + 1;
    if ( (int16_t)(v24 - 1) > 2 )
      v27[(int16_t)(v24 - 1) - 2] = 0;
    v25 = sub_103CAF(v42, (int)v27);
    if ( v25 > (int16_t)v39 )
    {
      sub_120F07((int)v31);
      sub_120D79(v40 - 1, (int)v32);
    }
    sub_C5F14((int16_t)v43, (int16_t)v41, v42, (uint16_t)(v39 + 1), (int)v27);
  }
  JUMPOUT(0x92E66);
}
// 95911: control flows out of bounds to 92E66
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 18003A: using guessed type _UNKNOWN *off_18003A;
// 18003E: using guessed type _UNKNOWN *off_18003E;
// 1906C2: using guessed type int16_t word_1906C2[];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199A08: using guessed type int16_t word_199A08;


//----- (00095BAA) --------------------------------------------------------
_BOOL1 __fastcall sub_95BAA( int a1,
        int a2,
        int a3,
        int a4, int a5, int a6, int a7, int a8,
        int a9,
        int a10)
{
  int16_t v11; // cx
  int v12; // eax
  void *v13; // esi
  int16_t *v14; // eax
  int16_t v15; // ax
  char *v16; // eax
  int16_t v17; // cx
  int16_t v18; // si
  int64_t v19; // rax
  char *v20; // ebx
  int16_t v21; // dx
  int16_t v22; // ax
  char *v23; // eax
  int16_t v24; // bx
  int16_t v25; // cx
  uint16_t v26; // ax
  char *v27; // esi
  int v28; // esi
  char *v29; // eax
  int16_t v30; // ax
  int v31; // eax
  int v32; // edx
  int16_t v33; // si
  char v34; // al
  _BOOL1 v35; // al
  char v36; // al
  int16_t v37; // cx
  int64_t v38; // rax
  int16_t v39; // bx
  int16_t v40; // ax
  _BOOL1 result; // al
  int16_t v42; // si
  int v43; // ecx
  int16_t v44; // di
  int64_t v45; // rax
  int16_t v46; // ax
  int v47; // [esp-4h] [ebp-CAh]
  char *v48; // [esp-4h] [ebp-CAh]
  char *v49; // [esp-4h] [ebp-CAh]
  char v50[80]; // [esp+0h] [ebp-C6h] BYREF
  char v51[80]; // [esp+50h] [ebp-76h] BYREF
  char v52[12]; // [esp+A0h] [ebp-26h] BYREF
  char v53[12]; // [esp+ACh] [ebp-1Ah] BYREF
  _BYTE v54[8]; // [esp+B8h] [ebp-Eh] BYREF
  _BYTE v55[8]; // [esp+C0h] [ebp-6h] BYREF
  char v56[4]; // [esp+C8h] [ebp+2h] BYREF
  int v57; // [esp+CCh] [ebp+6h]
  int v58; // [esp+D0h] [ebp+Ah]
  int16_t v59; // [esp+D4h] [ebp+Eh] BYREF
  int16_t v60; // [esp+D8h] [ebp+12h] BYREF
  int v61; // [esp+DCh] [ebp+16h]
  int v62; // [esp+E0h] [ebp+1Ah]
  int v63; // [esp+E4h] [ebp+1Eh]
  int v64; // [esp+E8h] [ebp+22h]
  int v65; // [esp+ECh] [ebp+26h]
  int v66; // [esp+F0h] [ebp+2Ah]
  int v67; // [esp+F4h] [ebp+2Eh]
  int v68; // [esp+F8h] [ebp+32h]
  int16_t v69; // [esp+FCh] [ebp+36h] BYREF
  int16_t v70; // [esp+100h] [ebp+3Ah] BYREF
  int v71; // [esp+104h] [ebp+3Eh]
  int v72; // [esp+108h] [ebp+42h]
  int v73; // [esp+10Ch] [ebp+46h]
  int v74; // [esp+110h] [ebp+4Ah]
  int v75; // [esp+114h] [ebp+4Eh]
  int v76; // [esp+118h] [ebp+52h]
  int v77; // [esp+11Ch] [ebp+56h]
  int v78; // [esp+120h] [ebp+5Ah]
  int v79; // [esp+124h] [ebp+5Eh]
  int v80; // [esp+128h] [ebp+62h]
  _BOOL1 v81; // [esp+12Ch] [ebp+66h]
  char v82; // [esp+130h] [ebp+6Ah]

  v78 = a2;
  v72 = a3;
  v79 = a4;
  v11 = a2;
  HIWORD(a2) = HIWORD(dword_1930DC);
  v12 = dword_1930DC + 59 * (int16_t)a2;
  LOWORD(a2) = *(char *)(v12 + 57);
  v58 = a2;
  LOWORD(a2) = *(uint8_t *)(v12 + 35);
  v75 = a2;
  LOWORD(a2) = *(_WORD *)(v12 + 53);
  v80 = a2;
  LOWORD(v12) = *(char *)(v12 + 55);
  v64 = v12;
  v82 = 1;
  sub_93D8E(v11, &v59, &v60);
  v68 = 17;
  sub_120DED(0, 0);
  if ( word_199A08 == 29 )
  {
    if ( a1 > -1 && byte_199F0F == *(_WORD *)(dword_193188 + 2 * a1)
      || a1 > -1 && byte_199F15 == *(_WORD *)(dword_193188 + 2 * a1) )
    {
      v13 = &unk_182298;
    }
    else
    {
      v13 = &unk_182284;
    }
  }
  else
  {
    v13 = &unk_182284;
  }
  qmemcpy(v54, v13, sizeof(v54));
  v62 = 3;
  v74 = 1;
  if ( word_199A08 == 29 && !byte_19C542 )
  {
    v14 = sub_97588(v78, 0);
    sprintf(v50, "%s", (char *)v14);
    sub_120D79(3, (int)v54);
    sub_120E8C(1);
    v15 = sub_12066F((int)v50);
    sub_1212B3(v72 + (160 - v15) / 2 + 22, v79, (int)v50);
  }
  if ( word_199A08 == 29 && !byte_19C542 )
  {
    v54[0] = 59;
    sub_120BB5(0, (int)v54);
    if ( (_WORD)v58 == 4 )
    {
      v16 = sub_7A990(0x108u);
      v17 = sub_12066F((int)v16);
      sub_7ABA6((int)v52);
      v18 = a9 + v72 - 2;
      v19 = sprintf(v50, "%d %s", v59, v52);
      sub_1210B7(v18, SWORD2(v19), (int)v50);
      v20 = sub_7A990(0x108u);
      v21 = v79 + sub_122259();
      v22 = v18 - v17;
    }
    else
    {
      v23 = sub_7A990(0x109u);
      v24 = sub_12066F((int)v23);
      if ( v60 )
      {
        sub_7ABA6((int)v53);
        sprintf(v50, "%d %s", v60, v53);
      }
      else
      {
        strcpy(v50, sub_7A990(0x10Au));
      }
      v25 = a9 + v72 - 2 - v24;
      sub_1212B3(v25, v79, (int)v50);
      v20 = sub_7A990(0x109u);
      v21 = v79 + sub_122259();
      v22 = v25;
    }
    sub_1212B3(v22, v21, (int)v20);
    v54[0] = 61;
  }
  v51[0] = 0;
  switch ( (_WORD)v58 )
  {
    case 0:
      sub_120BB5(2, (int)v54);
      v26 = 267;
LABEL_23:
      v27 = sub_7A990(v26);
LABEL_24:
      strcpy(v51, v27);
      break;
    case 2:
      sub_120BB5(2, (int)v54);
      v26 = 268;
      goto LABEL_23;
    case 1:
      sub_120BB5(2, (int)v54);
      if ( !(_WORD)v75 && (int16_t)v80 > -1 )
      {
        v27 = (char *)(129 * (int16_t)v80 + dword_197F9C);
        goto LABEL_24;
      }
      if ( (_WORD)v75 == 1 && (int16_t)v80 > -1 )
      {
        v27 = (char *)(113 * (int16_t)v80 + dword_19306C);
        goto LABEL_24;
      }
      break;
    case 4:
      v28 = (int16_t)v78;
      sub_93D8E(v78, &v70, &v69);
      if ( word_199A08 == 29 )
      {
        v47 = 30 - *(char *)(dword_1930DC + 59 * v28 + 55);
        v29 = sub_7A990(0x10Du);
        sprintf(v51, v29, v47);
      }
      else
      {
        strcpy(v51, sub_7A990(0x10Eu));
      }
      sub_120BB5(2, (int)&unk_18227C);
      break;
  }
  if ( word_199A08 != 29 || byte_19C542 )
    goto LABEL_48;
  if ( v82 )
  {
    sub_8F625((int)v55);
    v30 = sub_8F645();
    sub_8FDA1((int)v51, (int)v55, SHIWORD(dword_1B61E4), v30, 4, 74, 1);
    if ( 12 - (sub_122259() + 12) / 2 >= 0 )
    {
      LOWORD(v31) = 0;
      goto LABEL_47;
    }
  }
  else if ( 12 - (sub_122259() + 12) / 2 >= 0 )
  {
    LOWORD(v31) = 0;
    goto LABEL_47;
  }
  v31 = 12 - (sub_122259() + 12) / 2;
LABEL_47:
  sub_1210FD(a5 + a7 / 2, v31 + a8 + a6 + 1, (int)v51);
LABEL_48:
  v51[0] = 0;
  if ( (int16_t)v64 > 0 && (_WORD)v58 == 1 )
    sub_956E2(v78, a5, a6, a7);
  sub_120D79(v62, (int)v54);
  sub_120E8C(v74);
  if ( word_199A08 == 29 && !byte_19C542 )
    v79 += 16;
  v81 = 0;
  strcpy(v56, " .");
  sub_12066F((int)v56);
  v32 = v72;
  sub_9402B(v78);
  v65 = v32 + 2;
  v33 = 0;
  v73 = a9 + v72 - 3;
  v61 = a9 + v72 + 3;
  do
  {
    v71 = v65;
    if ( (_WORD)v75 )
    {
      if ( (_WORD)v75 != 1 )
        goto LABEL_66;
      v35 = 0;
      if ( byte_17D21D[18 * v33] == 2 )
      {
        sub_9469E();
        if ( v36 )
          v35 = 1;
      }
    }
    else
    {
      v35 = 0;
      if ( byte_17D21D[18 * v33] == 1 )
      {
        sub_9469E();
        if ( v34 )
          v35 = 1;
      }
    }
    v81 = v35;
LABEL_66:
    if ( v81 )
    {
      v57 = v33;
      sub_12A478(v71, v79 - 4, dword_190358[v33 / 2]);
      v48 = *(char **)((char *)&dword_17D222 + 18 * v33);
      v37 = v79;
      v71 += 22;
      v38 = sprintf(v50, "%s ", v48);
      sub_1212B3(v71, SWORD2(v38), (int)v50);
      WORD2(v38) = v78;
      v39 = v57;
      sub_12066F((int)v50);
      LOWORD(v38) = sub_94BB2(word_19999C, SWORD2(v38), v39);
      sprintf(v50, *(char **)((char *)&off_17D226 + 18 * v33), (int16_t)v38);
      if ( word_199A08 == 29 )
        v40 = v73;
      else
        v40 = v61;
      sub_1210B7(v40, v37, (int)v50);
      sub_120E8C(v74);
      v79 += v68;
    }
    ++v33;
  }
  while ( v33 < 54 );
  v63 = v72 + 2;
  v77 = 0;
  v67 = a9 + v72 - 3;
  v66 = a9 + v72 + 3;
  do
  {
    v76 = v63;
    result = !byte_17D21D[18 * (int16_t)v77] && sub_9467D(word_19999C, v78, v77);
    if ( result )
    {
      v42 = v77;
      v43 = 18 * (int16_t)v77;
      sub_12A478(v76, v79 - 4, dword_190358[(int16_t)v77 / 2]);
      v49 = *(char **)((char *)&dword_17D222 + v43);
      v44 = v79;
      v76 += 22;
      v45 = sprintf(v50, "%s ", v49);
      sub_1212B3(v76, SWORD2(v45), (int)v50);
      WORD2(v45) = v78;
      sub_12066F((int)v50);
      LOWORD(v45) = sub_94BB2(word_19999C, SWORD2(v45), v42);
      sprintf(v50, *(char **)((char *)&off_17D226 + v43), (int16_t)v45);
      if ( word_199A08 == 29 )
        v46 = v67;
      else
        v46 = v66;
      sub_1210B7(v46, v44, (int)v50);
      sub_120E8C(v74);
      result = v68;
      v79 += v68;
    }
    ++v77;
  }
  while ( (int16_t)v77 < 54 );
  return result;
}
// 96124: variable 'v34' is possibly undefined
// 96156: variable 'v36' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17D222: using guessed type int dword_17D222;
// 17D226: using guessed type char *off_17D226;
// 190358: using guessed type int dword_190358[54];
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 193188: using guessed type int dword_193188;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199F0F: using guessed type char byte_199F0F;
// 199F15: using guessed type char byte_199F15;
// 19C542: using guessed type char byte_19C542;
// 1B61E4: using guessed type int dword_1B61E4;


//----- (0009636D) --------------------------------------------------------
int16_t __fastcall sub_9636D( int a1, int a2, int a3)
{
  int16_t *v4; // eax
  char *v5; // edi
  int64_t v6; // rax
  int16_t *v7; // edi
  char *v8; // esi
  char v9; // al
  int16_t result; // ax
  int v11; // eax
  char v12[256]; // [esp+0h] [ebp-222h] BYREF
  _BYTE v13[255]; // [esp+100h] [ebp-122h] BYREF
  char v14; // [esp+1FFh] [ebp-23h] BYREF
  _BYTE v15[80]; // [esp+200h] [ebp-22h] BYREF
  int16_t v16[40]; // [esp+250h] [ebp+2Eh] BYREF
  int v17; // [esp+2A0h] [ebp+7Eh]

  v17 = a2;
  v4 = sub_97588(a3, 1);
  sprintf(v15, "%s", (char *)v4);
  if ( byte_199CAE != 4 && *(_BYTE *)(dword_1930DC + 59 * a3 + 15) )
  {
    v5 = &v14;
    do
      ++v5;
    while ( *v5 );
    strcpy(v5, ",");
  }
  if ( a1 == 28 )
  {
    v17 = 10;
  }
  else if ( a1 == 29 )
  {
    v17 = 15;
  }
  v6 = sprintf(v13, (char *)dword_19C45C[a1 / 2], v15, (int16_t)v17);
  if ( word_199A08 == 29 )
  {
    v7 = v16;
    v8 = *(char **)((char *)dword_19C4CC + HIDWORD(v6));
    do
    {
      v9 = *v8++;
      *(_BYTE *)v7 = v9;
      v7 = (int16_t *)((char *)v7 + 1);
    }
    while ( v9 );
    sub_8FD21(v12, 95, 32);
    result = sub_A5EB2((int)v16, (int)v13);
    if ( !byte_19C543 )
    {
      sub_124D41();
      byte_199F11 = 1;
      sub_93550((int16_t)v8);
      return sub_1077D(v11, (int)v13, 32, v16);
    }
  }
  else
  {
    strcpy((char *)v16, *(char **)((char *)dword_19C4CC + HIDWORD(v6)));
    sub_8FD21(v12, 95, 32);
    return sub_A5EB2((int)v16, (int)v13);
  }
  return result;
}
// 96473: variable 'v11' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1930DC: using guessed type int dword_1930DC;
// 199A08: using guessed type int16_t word_199A08;
// 199CAE: using guessed type char byte_199CAE;
// 199F11: using guessed type char byte_199F11;
// 19C45C: using guessed type int dword_19C45C[27];
// 19C4CC: using guessed type int dword_19C4CC[27];
// 19C543: using guessed type char byte_19C543;


//----- (000964BB) --------------------------------------------------------
void sub_964BB()
{
  int16_t v0; // ax
  int v1; // esi
  int16_t v2; // bx
  int v3; // eax
  uint16_t v4; // ax
  char *v5; // eax
  int v6; // [esp-Ch] [ebp-64h]
  int v7; // [esp-8h] [ebp-60h]
  int v8; // [esp-4h] [ebp-5Ch]
  char v9[80]; // [esp+0h] [ebp-58h] BYREF
  int v10; // [esp+50h] [ebp-8h]
  int v11; // [esp+54h] [ebp-4h]

  v0 = *(_WORD *)(dword_192B24 + 13 * word_19991C + 11);
  v1 = 129 * v0;
  v10 = 466;
  sub_77FF5(v0);
  v11 = 211;
  v2 = *(_WORD *)(v1 + dword_197F9C + 116);
  sub_120DED(0, 0);
  if ( v2 <= -1 )
  {
    strcpy(v9, (char *)(dword_197F9C + v1));
  }
  else
  {
    v3 = dword_1930DC + 59 * v2;
    if ( *(char *)(v3 + 55) <= 0 )
    {
      sprintf(v9, "%s (%s)", (char *)(dword_197F9C + v1), (char *)(dword_1930DC + 59 * v2));
    }
    else
    {
      v8 = *(char *)(v3 + 55);
      v7 = dword_1930DC + 59 * v2;
      v6 = dword_197F9C + v1;
      if ( *(_BYTE *)(v3 + 55) == 1 )
        v4 = 146;
      else
        v4 = 147;
      v5 = sub_7A990(v4);
      sprintf(v9, v5, v6, v7, v8);
    }
  }
  sub_8FDA1((int)v9, (int)&unk_182284, 3, 2, 4, 204, 1);
  sub_1210FD(v10, v11, (int)v9);
  JUMPOUT(0x94800);
}
// 965C9: control flows out of bounds to 94800
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192B24: using guessed type int dword_192B24;
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;
// 19991C: using guessed type int16_t word_19991C;


//----- (000965CE) --------------------------------------------------------
unsigned int __fastcall sub_965CE(uint16_t *a1, unsigned int *a2, int a3)
{
  uint16_t v4; // cx
  int16_t v5; // bx
  int v6; // eax
  int16_t i; // di
  unsigned int result; // eax
  int16_t j; // di
  char v10; // cl
  int16_t v11; // si
  int16_t k; // di
  unsigned int v13; // eax
  char v14; // al
  int v15; // ecx
  int v16; // [esp+0h] [ebp-1Ch]
  int v17; // [esp+4h] [ebp-18h]
  unsigned int v18; // [esp+Ch] [ebp-10h]
  int16_t v19; // [esp+10h] [ebp-Ch]

  v4 = *a1;
  v5 = 0;
  v18 = *a2;
  v6 = 0;
  do
  {
    if ( (*(_BYTE *)a1 & 3) != 0 )
      ++v5;
    ++v6;
    *(_DWORD *)a1 >>= 2;
  }
  while ( (int16_t)v6 < 10 );
  for ( i = 0; i < (int16_t)((a3 != 0) + 8); ++i )
  {
    if ( (*(_BYTE *)a2 & 3) != 0 )
      ++v5;
    *a2 >>= 2;
  }
  *(_DWORD *)a1 = v4;
  *a2 = v18;
  result = sub_1247A0(4u);
  if ( result == 1 )
  {
    v19 = 1;
    for ( j = 0; v19 && j < 100; ++j )
    {
      v10 = 2 * (sub_1247A0(0xAu) - 1);
      v17 = 1 << v10;
      result = 1 << (v10 + 1);
      if ( (*(_DWORD *)a1 & (1 << v10)) != 0 )
      {
        *(_DWORD *)a1 ^= v17;
        v19 = 0;
        *(_DWORD *)a1 |= result;
      }
      else if ( (*(_DWORD *)a1 & result) == 0 && v5 < 5 )
      {
        if ( v5 )
        {
          result = 1 << v10;
          *(_DWORD *)a1 |= v17;
        }
        else
        {
          result = dword_17D2A9;
          *(_DWORD *)a1 += dword_17D2A9;
        }
        v19 = 0;
        ++v5;
      }
    }
  }
  else
  {
    v11 = 1;
    for ( k = 0; v11 && k < 100; ++k )
    {
      if ( a3 )
        v13 = 9;
      else
        v13 = 8;
      v14 = sub_1247A0(v13);
      v16 = 1 << (2 * (v14 - 1));
      v15 = 1 << (2 * (v14 - 1) + 1);
      result = *a2;
      if ( (*a2 & v16) != 0 )
      {
        result = v16;
        *a2 ^= v16;
        v11 = 0;
        *a2 |= v15;
      }
      else if ( (result & v15) == 0 && v5 < 5 )
      {
        result = v16;
        ++v5;
        v11 = 0;
        *a2 |= v16;
      }
    }
  }
  return result;
}
// 17D2A9: using guessed type int dword_17D2A9;


//----- (00096737) --------------------------------------------------------
void __fastcall sub_96737(uint16_t *a1, int *a2, int a3, _WORD *a4, _WORD *a5)
{
  int16_t v6; // bx
  int v7; // edi
  int16_t v8; // di
  int16_t v9; // ax
  char v10; // cl
  int v11; // eax
  unsigned int v12; // eax
  int16_t v13; // ax
  int v14; // eax
  int v15; // esi
  char v16; // [esp+0h] [ebp-28h]
  int v17; // [esp+4h] [ebp-24h]
  int v18; // [esp+8h] [ebp-20h]
  int16_t v20; // [esp+10h] [ebp-18h]
  int16_t v21; // [esp+14h] [ebp-14h]
  int16_t v22; // [esp+18h] [ebp-10h]
  int16_t v23; // [esp+1Ch] [ebp-Ch]
  int16_t v24; // [esp+20h] [ebp-8h]
  uint16_t v25; // [esp+24h] [ebp-4h]

  v6 = 0;
  v25 = *a1;
  v7 = 0;
  v17 = *a2;
  while ( 1 )
  {
    if ( (*(_BYTE *)a1 & 3) != 0 )
      ++v6;
    ++v7;
    *(_DWORD *)a1 >>= 2;
    if ( (int16_t)v7 >= 10 )
    {
      v22 = 0;
      v8 = (a3 != 0) + 8;
      while ( v8 > v22 )
      {
        if ( (*(_BYTE *)a2 & 3) != 0 )
          ++v6;
        ++v22;
        *a2 = (unsigned int)*a2 >> 2;
      }
      *(_DWORD *)a1 = v25;
      *a2 = v17;
      if ( sub_1247A0(4u) == 1 )
      {
        v20 = 1;
        v23 = 0;
        *a4 = 0;
        while ( v20 && v23 < 100 )
        {
          v9 = sub_1247A0(0xAu);
          v8 = v9 - 1;
          v10 = 2 * (v9 - 1);
          v18 = 1 << v10;
          v11 = 1 << (v10 + 1);
          if ( (*(_DWORD *)a1 & (1 << v10)) != 0 )
          {
            *(_DWORD *)a1 ^= v18;
            v20 = 0;
            *(_DWORD *)a1 |= v11;
          }
          else if ( (*(_DWORD *)a1 & v11) == 0 && v6 < 5 )
          {
            if ( v6 )
              *(_DWORD *)a1 |= v18;
            else
              *(_DWORD *)a1 += dword_17D2A9;
            v20 = 0;
            ++v6;
          }
          ++v23;
        }
      }
      else
      {
        v21 = 1;
        v24 = 0;
        *a4 = 1;
        while ( v21 && v24 < 100 )
        {
          if ( a3 )
            v12 = 9;
          else
            v12 = 8;
          v13 = sub_1247A0(v12);
          v8 = v13 - 1;
          v16 = 2 * (v13 - 1);
          v14 = 1 << v16;
          v15 = 1 << (v16 + 1);
          if ( ((1 << v16) & *a2) != 0 )
          {
            *a2 ^= v14;
            v21 = 0;
            *a2 |= v15;
          }
          else if ( (v15 & *a2) == 0 && v6 < 5 )
          {
            v21 = 0;
            ++v6;
            *a2 |= v14;
          }
          ++v24;
        }
      }
      *a5 = v8;
      JUMPOUT(0x92C1F);
    }
  }
}
// 968CC: control flows out of bounds to 92C1F
// 17D2A9: using guessed type int dword_17D2A9;


//----- (000968D1) --------------------------------------------------------
void __usercall sub_968D1(int a1, int16_t *a2)
{
  int v2; // eax
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // ebx
  int v9; // ebx
  int v10; // ebx
  _DWORD *v11; // eax
  int v12; // ebx
  int16_t v13; // di
  int v14; // esi
  _DWORD *v15; // eax
  int v16; // edx
  int v17; // eax
  int16_t v18; // si
  int v19; // ecx
  _DWORD *v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // [esp+0h] [ebp-8h]
  int16_t v24; // [esp+4h] [ebp-4h]

  sub_12DAA4(100, 100);
  v2 = 17 * *(int16_t *)(3753 * word_19999C + dword_197F98 + 41);
  LOWORD(v2) = *(uint8_t *)(dword_1930D4 + v2 + 2);
  v24 = v2;
  sub_FE8BE(v2, dword_1930D4, a1, a2);
  sub_82348();
  sub_72A65();
  dword_193118 = (int)sub_110D3C(dword_192ED4, (int)&loc_14C05 + 3);
  dword_19C458 = (int)sub_110D3C(dword_192ED4, 48);
  memset(dword_19C458, 0, 48);
  v3 = 0;
  dword_19C4C8 = (int)sub_110D3C(dword_192ED4, 3953);
  while ( 1 )
  {
    v4 = dword_1930DC + 59 * (int16_t)v3;
    v5 = dword_19C4C8 + 5 * (int16_t)v3;
    *(_BYTE *)v5 = *(_BYTE *)(v4 + 57);
    *(_WORD *)(v5 + 1) = *(_WORD *)(v4 + 53);
    *(_WORD *)(v5 + 3) = *(char *)(v4 + 55);
    if ( *(_BYTE *)(v4 + 35) == 1 && (!*(_BYTE *)v5 || *(_BYTE *)v5 == 4) )
      *(_WORD *)(5 * (int16_t)v3 + dword_19C4C8 + 1) = v24;
    if ( (int16_t)++v3 >= 67 )
    {
      dword_193114 = (int)sub_110D3C(dword_192ED4, 268);
      dword_1930EC = (int)sub_110D3C(dword_192ED4, 268);
      LOWORD(v6) = sub_92E72();
      sub_FE8BE(v6, 268, v3, a2);
      dword_193168 = (int)sub_126B42((int)off_182278, 0, dword_192ED4);
      dword_193124 = (int)sub_126B42((int)off_182278, 1, dword_192ED4);
      dword_193154 = (int)sub_126B42((int)off_182278, 2, dword_192ED4);
      dword_19316C = (int)sub_126B42((int)off_182278, 3, dword_192ED4);
      v7 = sub_126B42((int)off_182278, 4, dword_192ED4);
      v8 = dword_192ED4;
      dword_193164 = (int)v7;
      dword_193160 = (int)sub_126B42((int)off_182278, 5, dword_192ED4);
      sub_FE8BE(dword_193160, 5, v8, a2);
      dword_193120 = (int)sub_126B42((int)off_182278, 6, dword_192ED4);
      dword_193158 = (int)sub_126B42((int)off_182278, 7, dword_192ED4);
      dword_193128 = (int)sub_126B42((int)off_182278, 8, dword_192ED4);
      dword_19312C = (int)sub_126B42((int)off_182278, 9, dword_192ED4);
      dword_193110 = (int)sub_126B42((int)off_182278, 10, dword_192ED4);
      dword_1930FC = (int)sub_126B42((int)off_182278, 11, dword_192ED4);
      dword_1930F8 = (int)sub_126B42((int)off_182278, 12, dword_192ED4);
      v9 = dword_192ED4;
      dword_1930E0 = (int)sub_126B42((int)off_182278, 13, dword_192ED4);
      sub_FE8BE(dword_1930E0, 14, v9, a2);
      dword_192B28 = (int)sub_126B42((int)off_182278, 14, dword_192ED4);
      dword_192B44 = (int)sub_126B42((int)off_182278, 15, dword_192ED4);
      dword_192B60 = (int)sub_126B42((int)off_182278, 16, dword_192ED4);
      dword_19310C = (int)sub_126B42((int)off_182278, 17, dword_192ED4);
      dword_193100 = (int)sub_126B42((int)off_182278, 18, dword_192ED4);
      dword_193104 = (int)sub_126B42((int)off_182278, 19, dword_192ED4);
      v10 = dword_192ED4;
      dword_1930E8 = (int)sub_126B42((int)off_182278, 20, dword_192ED4);
      sub_FE8BE(dword_1930E8, 141, v10, a2);
      v11 = sub_126B42((int)off_182278, 141, dword_192ED4);
      v12 = dword_192ED4;
      dword_19315C = (int)v11;
      dword_19311C = (int)sub_126B42((int)off_182278, 142, dword_192ED4);
      sub_FE8BE(dword_19311C, 142, v12, a2);
      v13 = 88;
      dword_193108 = (int)sub_110D3C(dword_192ED4, 48);
      sub_93DF7();
      sub_942FD();
      v14 = 0;
      v23 = dword_192ED4;
      do
      {
        v15 = sub_126B42((int)off_182278, v13++, v23);
        v16 = (int)v15;
        v17 = (int16_t)v14++;
        dword_190358[v17] = v16;
      }
      while ( (int16_t)v14 < 27 );
      sub_96D52();
      v18 = 130;
      v19 = 0;
      do
      {
        v20 = sub_126B42((int)off_182278, v18++, dword_192ED4);
        v21 = (int)v20;
        v22 = (int16_t)v19++;
        dword_1932E0[v22] = v21;
      }
      while ( (int16_t)v19 < 11 );
      JUMPOUT(0x94800);
    }
  }
}
// 96CE0: control flows out of bounds to 94800
// 969F3: variable 'v6' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 182278: using guessed type char *off_182278;
// 190358: using guessed type int dword_190358[54];
// 192B28: using guessed type int dword_192B28;
// 192B44: using guessed type int dword_192B44;
// 192B60: using guessed type int dword_192B60;
// 192ED4: using guessed type int dword_192ED4;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 1930E0: using guessed type int dword_1930E0;
// 1930E8: using guessed type int dword_1930E8;
// 1930EC: using guessed type int dword_1930EC;
// 1930F8: using guessed type int dword_1930F8;
// 1930FC: using guessed type int dword_1930FC;
// 193100: using guessed type int dword_193100;
// 193104: using guessed type int dword_193104;
// 193108: using guessed type int dword_193108;
// 19310C: using guessed type int dword_19310C;
// 193110: using guessed type int dword_193110;
// 193114: using guessed type int dword_193114;
// 193118: using guessed type int dword_193118;
// 19311C: using guessed type int dword_19311C;
// 193120: using guessed type int dword_193120;
// 193124: using guessed type int dword_193124;
// 193128: using guessed type int dword_193128;
// 19312C: using guessed type int dword_19312C;
// 193154: using guessed type int dword_193154;
// 193158: using guessed type int dword_193158;
// 19315C: using guessed type int dword_19315C;
// 193160: using guessed type int dword_193160;
// 193164: using guessed type int dword_193164;
// 193168: using guessed type int dword_193168;
// 19316C: using guessed type int dword_19316C;
// 1932E0: using guessed type int dword_1932E0[11];
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19C458: using guessed type int dword_19C458;
// 19C4C8: using guessed type int dword_19C4C8;


//----- (00096CE5) --------------------------------------------------------
void __fastcall sub_96CE5(int a1)
{
  int16_t v2; // si
  int v3; // ecx
  _DWORD *v4; // eax
  int v5; // edx
  int v6; // eax

  v2 = 88;
  v3 = 0;
  do
  {
    v4 = sub_126B42((int)off_182278, v2++, a1);
    v5 = (int)v4;
    v6 = (int16_t)v3++;
    dword_190358[v6] = v5;
  }
  while ( (int16_t)v3 < 27 );
  JUMPOUT(0x94801);
}
// 96D16: control flows out of bounds to 94801
// 182278: using guessed type char *off_182278;
// 190358: using guessed type int dword_190358[54];


//----- (00096D1B) --------------------------------------------------------
int sub_96D1B()
{
  int16_t v0; // si
  int v1; // ecx
  _DWORD *v2; // eax
  int v3; // edx
  int result; // eax

  v0 = 130;
  v1 = 0;
  do
  {
    v2 = sub_126B42((int)off_182278, v0++, dword_192ED4);
    v3 = (int)v2;
    result = (int16_t)v1++;
    dword_1932E0[result] = v3;
  }
  while ( (int16_t)v1 < 11 );
  return result;
}
// 182278: using guessed type char *off_182278;
// 192ED4: using guessed type int dword_192ED4;
// 1932E0: using guessed type int dword_1932E0[11];


//----- (00096D52) --------------------------------------------------------
void sub_96D52()
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

  v0 = 115;
  v11 = 0;
  sub_111499(dword_192ED4);
  do
  {
    v1 = (int16_t)v11++;
    v2 = sub_126B42((int)off_182278, (int16_t)v0, dword_192ED4);
    v3 = dword_192ED4;
    v4 = (int16_t)v0;
    dword_18F928[v1] = (int)v2;
    ++v0;
    dword_18F948[v1] = (int)sub_126B42((int)off_182278, v4, v3);
  }
  while ( (int16_t)v11 < 8 );
  for ( i = 0; i < 7; ++i )
  {
    v10 = (int16_t)v0;
    v6 = i;
    v7 = (int16_t)v0++;
    v8 = sub_126B42((int)off_182278, v7, dword_192ED4);
    v9 = dword_192ED4;
    dword_192B8C[i] = (int)v8;
    dword_192B70[v6] = (int)sub_126B42((int)off_182278, v10, v9);
  }
  sub_111499(dword_192ED4);
  JUMPOUT(0x94800);
}
// 96E06: control flows out of bounds to 94800
// 182278: using guessed type char *off_182278;
// 18F928: using guessed type int dword_18F928[8];
// 18F948: using guessed type int dword_18F948[8];
// 192B70: using guessed type int dword_192B70[7];
// 192B8C: using guessed type int dword_192B8C[15];
// 192ED4: using guessed type int dword_192ED4;


//----- (00096E0B) --------------------------------------------------------
void sub_96E0B()
{
  qmemcpy((void *)dword_1930DC, (void *)dword_1930D8, 0xF71u);
}
// 1930D8: using guessed type int dword_1930D8;
// 1930DC: using guessed type int dword_1930DC;


//----- (00096E27) --------------------------------------------------------
void sub_96E27()
{
  JUMPOUT(0x96E1F);
}
// 96E3B: control flows out of bounds to 96E1F
// 1930D8: using guessed type int dword_1930D8;
// 1930DC: using guessed type int dword_1930DC;


//----- (00096E3D) --------------------------------------------------------
int sub_96E3D()
{
  int result; // eax
  int v1; // ebx
  int16_t v2; // dx

  result = 0;
  do
  {
    v1 = (int16_t)result;
    v2 = *(_WORD *)(59 * (int16_t)result++ + dword_1930DC + 53);
    *(_WORD *)(dword_1930EC + 2 * v1) = v2;
  }
  while ( (int16_t)result < 67 );
  return result;
}
// 1930DC: using guessed type int dword_1930DC;
// 1930EC: using guessed type int dword_1930EC;


//----- (00096E69) --------------------------------------------------------
int sub_96E69()
{
  int result; // eax
  int v1; // ebx
  int16_t v2; // dx

  result = 0;
  do
  {
    v1 = (int16_t)result;
    v2 = *(_WORD *)(59 * (int16_t)result++ + dword_1930DC + 53);
    *(_WORD *)(dword_193114 + 2 * v1) = v2;
  }
  while ( (int16_t)result < 67 );
  return result;
}
// 1930DC: using guessed type int dword_1930DC;
// 193114: using guessed type int dword_193114;


//----- (00096E95) --------------------------------------------------------
int __fastcall sub_96E95(int a1, int a2, int a3, int a4, _BYTE *a5, _WORD *a6, _WORD *a7)
{
  int result; // eax
  int v8; // ebx
  int16_t j; // si
  int16_t v10; // bx
  int16_t k; // dx
  int v12; // esi
  int16_t m; // bx
  int v17; // [esp+Ch] [ebp-10h]
  int16_t v18; // [esp+14h] [ebp-8h]
  int16_t i; // [esp+18h] [ebp-4h]

  result = -1;
  *a5 = -1;
  *a6 = -1;
  v18 = 0;
  *a7 = -1;
  while ( v18 < 4 && (int16_t)result == -1 )
  {
    for ( i = 0; i < 5 && (int16_t)result == -1; ++i )
    {
      v8 = 2 * i + 20 * v18;
      if ( a4 == *(int16_t *)((char *)word_19C408 + v8) )
      {
        result = 0;
        *a6 = *(_WORD *)(2 * v18 + dword_193188);
      }
      else if ( a4 == -*(int16_t *)((char *)word_19C408 + v8) )
      {
        result = 1;
        *a6 = *(_WORD *)(dword_193188 + 2 * v18);
        *a7 = *(int16_t *)((char *)&word_19C412 + v8);
      }
    }
    ++v18;
  }
  for ( j = 0; j < 4 && (int16_t)result == -1; ++j )
  {
    v17 = 2 * j;
    if ( a4 == *(_WORD *)(v17 + a1) || a4 == *(_WORD *)(v17 + a2) )
    {
      result = 0;
      v10 = *(_WORD *)(dword_193188 + 2 * j);
    }
    else
    {
      if ( -*(int16_t *)(v17 + a2) != a4 )
        continue;
      v10 = *(_WORD *)(v17 + dword_193188);
      result = 1;
    }
    *a6 = v10;
  }
  if ( (int16_t)result == -1 )
  {
    for ( k = 0; k < 4; ++k )
    {
      v12 = 2 * k;
      if ( a3 == *(_WORD *)(v12 + a1) || a3 == *(_WORD *)(v12 + a2) )
      {
        result = 4;
        *a5 = *(_BYTE *)(dword_193188 + 2 * k);
      }
      for ( m = 0; m < 5 && (int16_t)result == -1; ++m )
      {
        if ( a3 == word_19C408[10 * k + m] )
        {
          result = 4;
          *a5 = *(_BYTE *)(dword_193188 + 2 * k);
        }
      }
    }
  }
  return result;
}
// 193188: using guessed type int dword_193188;
// 19C408: using guessed type int16_t word_19C408[];
// 19C412: using guessed type int16_t word_19C412;


//----- (00097041) --------------------------------------------------------
int __fastcall sub_97041( int a1, int a2, int16_t *a3, int16_t *a4)
{
  int16_t v4; // dx
  int v5; // esi
  int16_t i; // ax
  int v7; // edx
  int v8; // edx
  int16_t j; // ax
  int v10; // edx
  int16_t v14; // [esp+10h] [ebp-Ch]
  int16_t v15; // [esp+14h] [ebp-8h]
  char v16; // [esp+18h] [ebp-4h]

  v14 = (uint8_t)byte_199F14 * *(_WORD *)(dword_1975C4 + 12);
  v4 = word_19992E;
  if ( v14 + 20 <= word_19992E )
    v4 = v14 + 20;
  v5 = -1;
  v16 = 0;
  *a3 = -1;
  v15 = v4;
  *a4 = -1;
  if ( v14 < 0 || v4 < 0 )
    v16 = 1;
  for ( i = v14; i < v15 && !v16; ++i )
  {
    v7 = dword_192B24 + 13 * i;
    if ( a2 == *(_WORD *)(v7 + 9) && *(int16_t *)(v7 + 11) > -1 )
    {
      v16 = 1;
      v5 = 0;
LABEL_13:
      *a4 = i;
      continue;
    }
    v8 = 13 * i + dword_192B24;
    if ( a2 == -*(int16_t *)(v8 + 9) && *(int16_t *)(v8 + 11) > -1 )
    {
      v5 = 1;
      v16 = 1;
      goto LABEL_13;
    }
  }
  if ( (int16_t)v5 == -1 )
  {
    for ( j = v14; j < v15 && !v16; ++j )
    {
      v10 = 13 * j + dword_192B24;
      if ( a1 == *(_WORD *)(v10 + 9) && *(int16_t *)(v10 + 11) > -1 )
      {
        v5 = 4;
        v16 = 1;
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


//----- (00097156) --------------------------------------------------------
int __fastcall sub_97156(int a1)
{
  int16_t v2; // ax
  int result; // eax
  int16_t v4; // dx

  *(_WORD *)(a1 + 10) = 3;
  *(_WORD *)(a1 + 14) = 121;
  v2 = sub_A00F1((_WORD *)a1);
  *(_WORD *)(a1 + 6) = v2;
  result = v2 / 2;
  *(_WORD *)(a1 + 2) = -1;
  *(_BYTE *)(a1 + 24) = 2;
  v4 = *(_WORD *)(a1 + 14);
  *(_BYTE *)(a1 + 26) = 1;
  *(_WORD *)a1 = v4 - result;
  return result;
}


//----- (0009718F) --------------------------------------------------------
int __usercall sub_9718F( int a1, int a2, int a3, int a4)
{
  int16_t v5; // si
  int16_t v6; // dx
  _BYTE *v7; // eax
  int16_t v8; // ax
  int result; // eax
  int v10; // eax
  char v11; // al
  int16_t v12; // [esp+8h] [ebp-Ch]
  int16_t v14; // [esp+10h] [ebp-4h]

  v14 = -1;
  v5 = 0;
  v6 = 0;
  v12 = 0;
  do
  {
    if ( v6 != a1 )
    {
      HIWORD(a4) = HIWORD(dword_1930DC);
      v7 = (_BYTE *)(dword_1930DC + 59 * v6);
      LOWORD(a4) = (char)v7[58];
      if ( (_WORD)a4 == a2 )
      {
        a4 = (char)v7[57];
        if ( a4 != -2 && a4 != -1 )
        {
          a4 = 59 * a1 + dword_1930DC;
          if ( v7[35] == *(_BYTE *)(a4 + 35) )
          {
            if ( v7[57] == 4 )
            {
              v8 = (char)v7[55];
              if ( v8 > v12 )
              {
                v12 = v8;
                v14 = v6;
              }
            }
            ++v5;
          }
        }
      }
    }
    ++v6;
  }
  while ( v6 < 67 );
  if ( v5 == 4 )
  {
    result = v14;
    if ( v14 == -1 )
      return result;
    sub_933F2(v14);
  }
  v10 = dword_1930DC + 59 * a1;
  *(_BYTE *)(v10 + 55) = 0;
  *(_BYTE *)(v10 + 58) = a2;
  if ( a3 )
    v11 = 0;
  else
    v11 = 4;
  *(_BYTE *)(dword_1930DC + 59 * a1 + 57) = v11;
  if ( a3 )
    sub_99223(a1, a2);
  result = dword_1930DC;
  if ( *(_BYTE *)(59 * a1 + dword_1930DC + 35) == 1 )
    return sub_E2D72(a2, a4);
  return result;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (00097287) --------------------------------------------------------
bool __fastcall sub_97287( int a1, int a2)
{
  int v2; // ebx
  int v3; // edx

  v2 = 129 * a2;
  v3 = dword_197F9C + 129 * a1;
  return *(_WORD *)(v3 + 103) == *(_WORD *)(v2 + dword_197F9C + 103)
      && *(_WORD *)(v3 + 105) == *(_WORD *)(v2 + dword_197F9C + 105);
}
// 197F9C: using guessed type int dword_197F9C;


//----- (000972C4) --------------------------------------------------------
int __fastcall sub_972C4( int a1, int a2)
{
  return word_17D21E[9 * a2] * (int16_t)(a1 / (uint8_t)byte_17D220[18 * a2] + 1) / 10;
}
// 17D21E: using guessed type int16_t word_17D21E[];


//----- (000972EE) --------------------------------------------------------
_BOOL1 __fastcall sub_972EE( int a1, int a2, int a3)
{
  _BOOL1 result; // al

  byte_19C542 = 1;
  result = sub_95BAA(-1, a3, (int16_t)(a1 + 95), (int16_t)(a2 + 5), a1 + 10, a2 + 2, 80, 90, 195, 14);
  byte_19C542 = 0;
  return result;
}
// 19C542: using guessed type char byte_19C542;


//----- (0009733E) --------------------------------------------------------
void __fastcall sub_9733E( int a1, int a2)
{
  int16_t v3; // bx
  int i; // edx
  int v5; // edx

  v3 = -1;
  for ( i = 0; (int16_t)i < 5 && v3 == -1; ++i )
  {
    if ( a1 == -word_19C408[(int16_t)i] )
      v3 = word_19C412[(int16_t)i];
  }
  if ( v3 != -1 )
  {
    sub_1112EC(dword_192ED4, i);
    sub_942FD();
    v5 = (int16_t)sub_94BB2(word_19999C, a2, v3);
    sub_9636D(v3, v5, a2);
    sub_1113CC(dword_192ED4, v5);
  }
  JUMPOUT(0x941B5);
}
// 973C7: control flows out of bounds to 941B5
// 192ED4: using guessed type int dword_192ED4;
// 19999C: using guessed type int16_t word_19999C;
// 19C408: using guessed type int16_t word_19C408[5];
// 19C412: using guessed type int16_t word_19C412[35];


//----- (000973CC) --------------------------------------------------------
_BOOL1 __fastcall sub_973CC( int a1, int a2)
{
  return sub_95BAA(a1, a2, 92, (int16_t)(109 * a1 + 38), 8, 109 * a1 + 34, 83, 96, 204, 3);
}


//----- (00097400) --------------------------------------------------------
void sub_97400()
{
  int16_t v0; // di
  int16_t v1; // si
  int v2; // ecx
  int v3; // edx
  int v4; // ebx
  int v5; // eax

  v0 = 50;
  v1 = 0;
  while ( 1 )
  {
    v2 = *(int16_t *)(dword_193188 + 2 * v1);
    if ( v2 <= -1 )
    {
      v3 = 0;
      do
      {
        v4 = 10 * v1;
        v5 = (int16_t)v3;
        word_19C408[(int16_t)v3++ + v4] = -1000;
        word_19C412[v5 + v4] = 0;
      }
      while ( (int16_t)v3 < 5 );
    }
    else
    {
      sub_92A92(94, v0, word_19999C, v2, (int)&word_19C408[10 * v1]);
    }
    ++v1;
    v0 += 109;
    if ( v1 >= 4 )
      JUMPOUT(0x94801);
  }
}
// 97473: control flows out of bounds to 94801
// 193188: using guessed type int dword_193188;
// 19999C: using guessed type int16_t word_19999C;
// 19C408: using guessed type int16_t word_19C408[5];
// 19C412: using guessed type int16_t word_19C412[35];


//----- (00097478) --------------------------------------------------------
unsigned int __fastcall sub_97478( int a1)
{
  int16_t v2; // [esp+0h] [ebp-8h] BYREF
  int16_t v3; // [esp+4h] [ebp-4h] BYREF

  return sub_A1C74(a1, 306, 17, 0, 0, 0, 0, &v3, 0, &v2);
}


//----- (000974A6) --------------------------------------------------------
void __fastcall sub_974A6( int a1)
{
  if ( a1 > -1 && sub_A44FC(a1, word_19999C) )
    sub_A3FE6(a1);
  sub_A31DA(a1, 0, (int)&unk_179AEA, 306, 17, 0, 0, 3, 3);
  JUMPOUT(0x94800);
}
// 97524: control flows out of bounds to 94800
// 19999C: using guessed type int16_t word_19999C;


//----- (00097529) --------------------------------------------------------
char __fastcall sub_97529( int a1, int a2, int a3)
{
  memset(word_19C408, 0, 80);
  return sub_92A92(a1 + 97, (int16_t)(a2 + 1), word_19999C, a3, (int)word_19C408);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19999C: using guessed type int16_t word_19999C;
// 19C408: using guessed type int16_t word_19C408[5];


//----- (00097565) --------------------------------------------------------
char *__fastcall sub_97565(char *a1, int a2, int a3)
{
  strcpy(a1, (char *)sub_97588(a3, 0));
  return a1;
}


//----- (00097588) --------------------------------------------------------
int16_t *__fastcall sub_97588( int a1, int a2)
{
  int v3; // ecx
  int v4; // eax
  int16_t v5; // ax
  char *v6; // esi
  char *v7; // edi
  int v8; // edx
  char *v9; // edi
  char *v10; // edi
  uint16_t v11; // ax
  char *v13; // edi
  char *v14; // edi
  char v16[200]; // [esp+0h] [ebp-4Ah] BYREF
  char v17; // [esp+C8h] [ebp+7Eh]

  v17 = a2;
  v3 = a1;
  v4 = dword_1930DC + 59 * a1;
  if ( *(char *)(v4 + 58) == -1 )
  {
    v5 = sub_93D4B(*(_WORD *)(v4 + 36), 0);
    if ( v5 > 5 )
      v5 = 5;
  }
  else
  {
    v5 = sub_94951(v3);
  }
  LOBYTE(word_18FF78) = 0;
  if ( *(_BYTE *)(59 * a1 + dword_1930DC + 35) )
    v6 = (char *)dword_190448[v5];
  else
    v6 = (char *)dword_190430[v5];
  v7 = (char *)&word_18FF78 - 1;
  do
    ++v7;
  while ( *v7 );
  strcpy(v7, v6);
  v8 = 59 * a1;
  v9 = (char *)&word_18FF78 - 1;
  do
    ++v9;
  while ( *v9 );
  strcpy(v9, asc_179B1B);
  v10 = (char *)&word_18FF78 - 1;
  do
    ++v10;
  while ( *v10 );
  strcpy(v10, (char *)(v8 + dword_1930DC));
  if ( v17 && *(_BYTE *)(v8 + dword_1930DC + 15) )
  {
    if ( byte_199CAE == 4 )
    {
      sub_9946D(a1, v16);
    }
    else
    {
      if ( byte_199CAE == 2 && sub_8F8DC(*(_BYTE *)(v8 + dword_1930DC + 15)) )
      {
        v11 = 390;
      }
      else if ( a1 == 10 || a1 == 22 || a1 == 34 || a1 == 37 || a1 == 39 || a1 == 60 )
      {
        v11 = 386;
      }
      else
      {
        v11 = 272;
      }
      sub_8F6DF(v11, v16);
    }
    v13 = (char *)&word_18FF78 - 1;
    do
      ++v13;
    while ( *v13 );
    strcpy(v13, v16);
    v14 = (char *)&word_18FF78 - 1;
    do
      ++v14;
    while ( *v14 );
    strcpy(v14, (char *)(dword_1930DC + 59 * a1 + 15));
  }
  return &word_18FF78;
}
// 18FF78: using guessed type int16_t word_18FF78;
// 190430: using guessed type int dword_190430[];
// 190448: using guessed type int dword_190448[];
// 1930DC: using guessed type int dword_1930DC;
// 199CAE: using guessed type char byte_199CAE;


//----- (0009773F) --------------------------------------------------------
_BOOL1 __fastcall sub_9773F( int a1)
{
  int v1; // eax

  v1 = dword_1930DC + 59 * a1;
  return *(_BYTE *)(v1 + 57) < 2u || *(_BYTE *)(v1 + 57) == 4 || *(_BYTE *)(v1 + 57) == 3;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (0009776C) --------------------------------------------------------
void __fastcall sub_9776C( int a1)
{
  int v2; // ebx
  int16_t v3; // dx
  int v4; // eax

  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = dword_1930DC + 59 * v3;
    if ( a1 == *(char *)(v4 + 58) && !*(_BYTE *)(v4 + 35) && sub_9773F(v3) )
      ++v2;
    if ( ++v3 >= 67 )
      JUMPOUT(0x94801);
  }
}
// 977AA: control flows out of bounds to 94801
// 1930DC: using guessed type int dword_1930DC;


//----- (000977AF) --------------------------------------------------------
void __fastcall sub_977AF( int a1)
{
  int v2; // edx
  int16_t v3; // bx
  int v4; // eax

  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = 59 * v3 + dword_1930DC;
    if ( a1 == *(char *)(v4 + 58) && *(_BYTE *)(v4 + 35) == 1 && sub_9773F(v3) )
      ++v2;
    if ( ++v3 >= 67 )
      JUMPOUT(0x94800);
  }
}
// 977F4: control flows out of bounds to 94800
// 1930DC: using guessed type int dword_1930DC;


//----- (000977F9) --------------------------------------------------------
_BOOL1 __fastcall sub_977F9( int a1)
{
  int16_t v2; // ax
  int16_t v3; // bx
  int16_t v4; // ax

  sub_9776C(a1);
  v3 = v2;
  sub_977AF(a1);
  return v4 + v3 < 8;
}
// 97805: variable 'v2' is possibly undefined
// 9780E: variable 'v4' is possibly undefined


//----- (0009781D) --------------------------------------------------------
void __fastcall sub_9781D( int a1)
{
  int v3; // eax
  int16_t v4; // bx
  int v5; // ebx
  int16_t i; // si
  int16_t v7; // ax
  int16_t v8; // di
  int v9; // eax
  int v10; // eax
  int v11; // [esp+4h] [ebp-10h]

  sub_9776C(a1);
  sub_977AF(a1);
  if ( sub_64395() >= 5 )
  {
    v3 = dword_197F98 + 3753 * a1;
    if ( *(_WORD *)(v3 + 3690) )
      v4 = dword_192FD8 - *(_WORD *)(v3 + 3690);
    else
      v4 = sub_64395();
    LOWORD(v5) = v4 + 1;
    if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 2227) )
      LOWORD(v5) = v5 + 5;
    if ( *(_BYTE *)(3753 * a1 + dword_197F98 + 2226) )
      LOWORD(v5) = v5 - 10;
    for ( i = 0; i < 67; ++i )
    {
      v11 = 59 * i;
      if ( *(char *)(v11 + dword_1930DC + 58) == -1 )
      {
        v7 = sub_93D4B(*(_WORD *)(v11 + dword_1930DC + 36), 0);
        if ( v7 > 5 )
          v7 = 5;
      }
      else
      {
        v7 = sub_94951(i);
      }
      v8 = v7 + 1;
      v9 = 59 * i + dword_1930DC;
      if ( a1 == *(char *)(v9 + 58) && *(_BYTE *)(v9 + 57) <= 1u )
      {
        v10 = dword_1930DC + 59 * i;
        if ( (*(_DWORD *)(v10 + 38) & dword_17D2CD) != 0 )
        {
          LOWORD(v5) = v8 + v5;
        }
        else if ( (*(_DWORD *)(v10 + 38) & dword_17D2DF) != 0 )
        {
          v5 = (int16_t)v5 + 15 * v8 / 10;
        }
      }
    }
  }
  JUMPOUT(0x94800);
}
// 97852: control flows out of bounds to 94800
// 17D2CD: using guessed type int dword_17D2CD;
// 17D2DF: using guessed type int dword_17D2DF;
// 192FD8: using guessed type int dword_192FD8;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (000979A0) --------------------------------------------------------
void __fastcall sub_979A0( int a1)
{
  int v2; // eax
  _BOOL1 v3; // bl
  char v4; // cl
  int v5; // ebx
  int16_t v6; // ax
  int16_t v7; // [esp+2h] [ebp-Ah]
  int v8; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h]

  v2 = dword_1930DC + 59 * a1;
  v7 = 60;
  v8 = loc_925A6;
  v9 = loc_925AA;
  v3 = 0;
  if ( *(char *)(v2 + 58) != -1 )
    v3 = *(_BYTE *)(dword_197F98 + 3753 * *(char *)(v2 + 58) + 2237) != 0;
  v4 = v3;
  v5 = 59 * a1;
  v6 = sub_93D4B(*(_WORD *)(v5 + dword_1930DC + 36), v4);
  if ( v6 + 1 < 6 )
    *(_WORD *)(dword_1930DC + v5 + 36) = *(&v7 + v6);
  JUMPOUT(0x94800);
}
// 97A24: control flows out of bounds to 94800
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (00097A29) --------------------------------------------------------
int __fastcall sub_97A29( int a1, int a2)
{
  return sub_97A2D(a1, a2);
}
// 97A2D: using guessed type int __fastcall sub_97A2D(_DWORD, _DWORD);


//----- (00097A2D) --------------------------------------------------------
int __fastcall sub_97A2D( int a1, int a2)
{
  sub_93D4B(*(_WORD *)(dword_1930DC + 59 * a2 + 36), 0);
  sub_9488F(a1);
  if ( (*(_DWORD *)(59 * a2 + dword_1930DC + 38) & dword_17D411) == 0 )
    sub_9467D(a1, a2, 29);
  JUMPOUT(0x941B5);
}
// 94872: control flows out of bounds to 941B5
// 17D411: using guessed type int dword_17D411;
// 1930DC: using guessed type int dword_1930DC;


//----- (00097A66) --------------------------------------------------------
void __fastcall sub_97A66( int a1)
{
  int16_t v3; // ax
  int16_t v4; // si
  int16_t v5; // ax
  int16_t v6; // cx
  int16_t v7; // ax
  _BOOL1 v8; // [esp+0h] [ebp-4h]

  sub_9781D(a1);
  v4 = v3;
  sub_9776C(a1);
  v6 = v5;
  sub_977AF(a1);
  v8 = 0;
  if ( v6 + v7 < 8 )
  {
    if ( v4 > 0 )
      v8 = (int16_t)(sub_1247A0(0x64u) - 1) < v4;
    if ( v8 )
      sub_97AD4(a1);
  }
  JUMPOUT(0x92F4B);
}
// 97ACF: control flows out of bounds to 92F4B
// 97A7A: variable 'v3' is possibly undefined
// 97A83: variable 'v5' is possibly undefined
// 97A8C: variable 'v7' is possibly undefined


//----- (00097AD4) --------------------------------------------------------
int __fastcall sub_97AD4( int a1)
{
  int v1; // edx
  int v2; // eax
  int16_t v3; // cx
  int v4; // ebx
  int v5; // eax
  char v7; // [esp+0h] [ebp-4h]

  v7 = a1;
  v1 = a1;
  sub_97B2D(a1);
  v3 = v2;
  v4 = v2;
  v5 = dword_197F98 + 3753 * v1;
  *(_BYTE *)(v5 + 1441) = v3;
  if ( (char)v3 > -1 )
  {
    *(_WORD *)(v5 + 3690) = dword_192FD8;
    *(_BYTE *)(59 * v3 + dword_1930DC + 58) = v7;
  }
  return v4;
}
// 97AE5: variable 'v2' is possibly undefined
// 192FD8: using guessed type int dword_192FD8;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (00097B2D) --------------------------------------------------------
void __fastcall sub_97B2D( int a1)
{
  int v1; // ebx
  int16_t v2; // ax
  int16_t v3; // ax
  int v4; // eax
  int v5; // edi
  int v6; // edx
  int16_t v7; // si
  int16_t v8; // dx
  int16_t v9; // dx
  char v10; // bl
  int16_t v11; // [esp+4h] [ebp-Ch]
  int16_t v12; // [esp+8h] [ebp-8h]
  int16_t v13; // [esp+Ch] [ebp-4h]

  v1 = a1;
  sub_9776C(a1);
  v13 = v2;
  sub_977AF(v1);
  v12 = v3;
  v4 = word_199998 + sub_64395() / 5 + 10;
  v5 = 0;
  v6 = 3753 * v1 + dword_197F98;
  v7 = 0;
  if ( *(_BYTE *)(v6 + 2227) )
  {
    LOWORD(v4) = v4 + 10;
  }
  else if ( *(_BYTE *)(v6 + 2226) )
  {
    LOWORD(v4) = (int16_t)v4 / 2;
  }
  if ( (int16_t)v4 >= 67 )
    v8 = 67;
  else
    v8 = v4;
  v11 = v8;
  while ( 1 )
  {
    v9 = sub_1247A0(v11) - 1;
    v10 = 0;
    if ( !*(_BYTE *)(59 * v9 + dword_1930DC + 35) && v13 < 4 || *(_BYTE *)(59 * v9 + dword_1930DC + 35) == 1 && v12 < 4 )
      v10 = 1;
    if ( v10 && sub_97C2D(v9) )
      v7 = 1;
    if ( (int16_t)++v5 > 100 )
      v7 = 1;
    if ( v7 )
      JUMPOUT(0x947FE);
  }
}
// 97C28: control flows out of bounds to 947FE
// 97B40: variable 'v2' is possibly undefined
// 97B51: variable 'v3' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00097C2D) --------------------------------------------------------
_BOOL1 __fastcall sub_97C2D( int a1)
{
  int v2; // eax

  v2 = dword_1930DC + 59 * a1;
  return *(char *)(v2 + 58) == -1 && a1 != 65 && a1 != 66 && *(char *)(v2 + 57) == -1;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (00097C64) --------------------------------------------------------
int __fastcall sub_97C64( int a1, int a2, int a3)
{
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int16_t v8; // ax
  int v9; // eax
  int result; // eax
  int v11; // eax
  int v12; // eax
  int16_t v13; // [esp+8h] [ebp-4h]

  v4 = dword_1930DC + 59 * a2;
  if ( *(char *)(v4 + 58) == -1 )
  {
    LOWORD(v5) = sub_93D4B(*(_WORD *)(v4 + 36), 0);
    if ( (int16_t)v5 <= 5 )
      v5 = (int16_t)v5;
    else
      v5 = 5;
  }
  else
  {
    v5 = sub_94951(a2);
  }
  v6 = v5;
  v7 = 59 * a2 + dword_1930DC;
  *(_WORD *)(v7 + 36) += a3;
  if ( *(int16_t *)(v7 + 36) <= 30000 )
    v8 = *(_WORD *)(v7 + 36);
  else
    v8 = 30000;
  v13 = v8;
  v9 = 59 * a2 + dword_1930DC;
  *(_WORD *)(v9 + 36) = v13;
  if ( *(char *)(v9 + 58) == -1 )
  {
    LOWORD(result) = sub_93D4B(*(_WORD *)(v9 + 36), 0);
    if ( (int16_t)result <= 5 )
      result = (int16_t)result;
    else
      result = 5;
  }
  else
  {
    result = sub_94951(a2);
  }
  if ( (_WORD)result != (_WORD)v6 )
  {
    v11 = dword_1930DC + 59 * a2;
    if ( *(_BYTE *)(v11 + 35) == 1 )
    {
      v12 = *(int16_t *)(v11 + 53);
      if ( v12 != -1 )
        sub_E2AB1(v12, a1, v6);
    }
    result = dword_1930DC;
    *(_BYTE *)(59 * a2 + dword_1930DC + 56) = 1;
  }
  return result;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (00097D59) --------------------------------------------------------
void __usercall sub_97D59( int a1, int16_t *a2, char *a3)
{
  int v4; // edx
  int v5; // eax
  int16_t v6; // bx
  uint16_t v7; // ax
  char *v8; // edi
  char v9; // al
  int16_t *v10; // eax
  int v11; // edx
  char *v12; // edi
  char v13; // al
  int16_t *v14; // eax
  int16_t *v15; // eax
  char *v16; // edi
  char v17; // al
  _BOOL1 v18; // cl
  _BOOL1 v19; // cl
  uint16_t v20; // dx
  _BYTE *v21; // eax
  int v22; // [esp-8h] [ebp-56h]
  char *v23; // [esp-8h] [ebp-56h]
  char *v24; // [esp-8h] [ebp-56h]
  int v25; // [esp-4h] [ebp-52h]
  int16_t *v26; // [esp-4h] [ebp-52h]
  int v27; // [esp-4h] [ebp-52h]
  int v28; // [esp-4h] [ebp-52h]
  int16_t v29; // [esp+0h] [ebp-4Eh]
  char v30[200]; // [esp+4h] [ebp-4Ah] BYREF
  _BYTE v31[200]; // [esp+CCh] [ebp+7Eh] BYREF
  _BYTE v32[200]; // [esp+194h] [ebp+146h] BYREF
  int v33; // [esp+25Ch] [ebp+20Eh]

  HIWORD(v4) = HIWORD(dword_1930DC);
  v5 = dword_1930DC + 59 * a1;
  LOWORD(v4) = *(uint8_t *)(v5 + 35);
  v6 = *(_WORD *)(v5 + 53);
  v32[0] = 0;
  v33 = v4;
  v31[0] = 0;
  if ( v6 == -1 )
  {
    if ( *(_BYTE *)(v5 + 57) )
      v7 = 274;
    else
      v7 = 273;
    v8 = v30;
    a3 = sub_7A990(v7);
    do
    {
      v9 = *a3++;
      *v8++ = v9;
    }
    while ( v9 );
    a2 = (int16_t *)v30;
    v10 = sub_97588(a1, 0);
    sprintf(v32, v30, v10);
  }
  if ( !v32[0] )
  {
    if ( (_WORD)v33 )
    {
      word_19C540 = sub_78E07(v6);
      v19 = word_19C540 != word_19C53E;
      word_19C53E = word_19C540;
      if ( v19 )
      {
        v28 = dword_19306C + 113 * word_19C540;
        v24 = sub_7A990(0x116u);
        sprintf(v31, v24, v28);
      }
    }
    else
    {
      v11 = 129 * v6;
      if ( *(_BYTE *)(v11 + dword_197F9C + 100) == 4 )
      {
        v6 = sub_78E07(*(int16_t *)(v11 + dword_197F9C + 101));
        v12 = v30;
        a3 = sub_7A990(0x113u);
        do
        {
          v13 = *a3++;
          *v12++ = v13;
        }
        while ( v13 );
        a2 = (int16_t *)v30;
        v25 = 113 * v6 + dword_19306C;
        v22 = dword_197F9C + v11;
        v14 = sub_97588(v29, 0);
        sprintf(v32, v30, v14, v22, v25);
      }
      else
      {
        sub_78B0E(v6);
        a2 = v15;
        if ( (int16_t)v15 == -1 )
        {
          v16 = v30;
          a3 = sub_7A990(0x114u);
          do
          {
            v17 = *a3++;
            *v16++ = v17;
          }
          while ( v17 );
          a2 = (int16_t *)v30;
          v26 = sub_97588(v29, 0);
          sprintf(v32, v30, v26);
        }
        else
        {
          v18 = (_WORD)v15 != (uint16_t)word_1999D8;
          word_1999D8 = (int16_t)v15;
          word_19C53C = v6;
          if ( v18 )
          {
            v27 = dword_197F9C + 129 * v6;
            v23 = sub_7A990(0x115u);
            sprintf(v31, v23, v27);
          }
        }
      }
    }
  }
  if ( v32[0] )
  {
    v20 = 3;
    v21 = v32;
  }
  else
  {
    if ( !v31[0] )
      goto LABEL_30;
    if ( byte_199CB0 )
      byte_199F09 = 15;
    else
      byte_199F09 = 0;
    v20 = 5;
    v21 = v31;
  }
  sub_94B3A((int)v21, v20, v6, a2, (int16_t)a3);
LABEL_30:
  JUMPOUT(0x92E6C);
}
// 97F88: control flows out of bounds to 92E6C
// 97E4D: variable 'v29' is possibly undefined
// 97E75: variable 'v15' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;
// 1999D8: using guessed type int16_t word_1999D8;
// 199CB0: using guessed type char byte_199CB0;
// 199F09: using guessed type char byte_199F09;
// 19C53C: using guessed type int16_t word_19C53C;
// 19C53E: using guessed type int16_t word_19C53E;
// 19C540: using guessed type int16_t word_19C540;


//----- (00097F8D) --------------------------------------------------------
char __usercall sub_97F8D(int16_t *a1, int a2, int a3)
{
  int16_t v4; // si
  char v5; // bl
  int16_t i; // dx
  int v7; // eax
  int16_t v8; // ax
  int v9; // eax
  int v10; // edx
  int16_t v12; // [esp+0h] [ebp-10h]
  char v14; // [esp+Ch] [ebp-4h]

  v4 = -1;
  v14 = 0;
  v5 = 0;
  *a1 = -1;
  for ( i = 0; i < 67 && !v5; ++i )
  {
    v7 = 59 * i + dword_1930DC;
    if ( *(_BYTE *)(v7 + 57) == 5 )
    {
      LOWORD(a3) = *(_WORD *)(v7 + 53);
      if ( (_WORD)a3 == v12 )
      {
        if ( *(_BYTE *)(v7 + 35) )
          sub_977AF(a2);
        else
          sub_9776C(a2);
        v5 = 1;
        *a1 = i;
        if ( v8 >= 4 )
        {
          v14 = 0;
          v4 = i;
        }
        else
        {
          v14 = 1;
        }
      }
    }
  }
  if ( v4 == -1 )
  {
    v9 = *a1;
    if ( v9 != -1 )
    {
      v10 = dword_1930DC;
      *(_BYTE *)(dword_1930DC + 59 * v9 + 58) = a2;
      *(_WORD *)(v10 + 59 * *a1 + 53) = -1;
      sub_9718F(*a1, a2, 1, a3);
      sub_944A3(*a1, a3);
    }
  }
  else
  {
    sub_933F2(v4);
  }
  return v14;
}
// 97FCC: variable 'v12' is possibly undefined
// 97FF5: variable 'v8' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;


//----- (00098062) --------------------------------------------------------
int16_t __fastcall sub_98062( int a1)
{
  int v1; // ebx
  int16_t v2; // ax
  int16_t v3; // si
  uint8_t v4; // cl
  uint8_t v5; // al

  v1 = a1;
  sub_97A2D(word_19999C, a1);
  v3 = v2;
  sub_123E6C((int)&unk_17CF00, 1);
  v4 = 0;
  if ( *(_BYTE *)(dword_1930DC + 59 * v1 + 57) == 4 )
  {
    if ( v3 <= *(_DWORD *)(dword_197F98 + 3753 * word_19999C + 50) )
    {
      sub_92D72(v1);
      return v5;
    }
    else
    {
      sub_92CF8(v1, v3);
    }
  }
  else
  {
    sub_92C25(v1, dword_1930DC, v1);
  }
  return v4;
}
// 9807C: variable 'v2' is possibly undefined
// 980C7: variable 'v5' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (000980DB) --------------------------------------------------------
int __fastcall sub_980DB( int a1, int a2, _WORD *a3)
{
  int16_t v5; // ax
  int16_t v6; // dx
  int16_t v7; // ax
  int v8; // eax
  int v9; // eax
  int v10; // edi
  int v11; // eax
  _BOOL1 v13; // [esp+0h] [ebp-4h]

  sub_983B8();
  v6 = v5;
  v13 = v5 == -1;
  sub_9776C(a1);
  if ( v7 >= 4 )
    v13 = 1;
  if ( v13 )
  {
    v8 = dword_1930DC;
    *(_WORD *)(dword_1930DC + 3888) = -1;
    *(_BYTE *)(v8 + 3893) = -1;
    *(_BYTE *)(v8 + 3892) = 6;
    *(_WORD *)(dword_197F9C + 129 * v6 + 116) = -1;
  }
  else if ( v6 != -1 )
  {
    v9 = dword_1930DC;
    *(_BYTE *)(dword_1930DC + 3892) = 1;
    *(_WORD *)(v9 + 3888) = v6;
    *(_BYTE *)(v9 + 3893) = a1;
    sub_99223(65, a1);
  }
  v10 = 3753 * a1;
  v11 = v10 + dword_197F98;
  *a3 = 0;
  if ( sub_E412B(v11, 0x2Fu) )
  {
    sub_E4204(v10 + dword_197F98, 0x2Fu, v10);
    *(_WORD *)(a2 + 2 * (int16_t)(*a3)++) = 47;
  }
  sub_982B6(a1, 3, a2, a3);
  return sub_8A4C4();
}
// 980EC: variable 'v5' is possibly undefined
// 98108: variable 'v7' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;


//----- (000981D1) --------------------------------------------------------
char __fastcall sub_981D1(char *a1, int a2, int a3)
{
  uint16_t v4; // ax
  char result; // al
  char *v6; // edi
  int16_t v7; // dx
  char *v8; // edi
  char *v9; // edi
  char *v10; // edi
  char *v11; // edi
  char *v12; // [esp-4h] [ebp-8h]

  if ( *(_BYTE *)(dword_1930DC + 3892) == 6 )
    v4 = 37;
  else
    v4 = 38;
  strcpy(a1, sub_7A990(v4));
  v6 = a1;
  v7 = 0;
  while ( v7 < a3 )
  {
    v12 = v6;
    v8 = v6 - 1;
    do
      ++v8;
    while ( *v8 );
    strcpy(v8, byte_179B1D);
    v9 = v12 - 1;
    do
      ++v9;
    while ( *v9 );
    strcpy(v9, "^ ");
    v10 = v12 - 1;
    do
      ++v10;
    while ( *v10 );
    strcpy(v10, *(char **)((char *)&off_17E079 + 13 * *(int16_t *)(a2 + 2 * v7++)));
    v11 = v12 - 1;
    do
      ++v11;
    while ( *v11 );
    strcpy(v11, "\n");
    v6 = v12;
  }
  return result;
}
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 1930DC: using guessed type int dword_1930DC;


//----- (00098282) --------------------------------------------------------
void __fastcall sub_98282(int a1, int a2, int a3)
{
  char v3[500]; // [esp+0h] [ebp-1F4h] BYREF

  if ( a3 > 0 )
  {
    sub_981D1(v3, a2, a3);
    sub_7A25F(&byte_199F28, (int)v3, 0);
    word_19994C = 1;
  }
}
// 19994C: using guessed type int16_t word_19994C;
// 199F28: using guessed type char byte_199F28;


//----- (000982B6) --------------------------------------------------------
void __fastcall sub_982B6(int a1, int a2, int a3, _WORD *a4)
{
  int16_t v5; // si
  unsigned int v6; // ebx
  _WORD v7[212]; // [esp+0h] [ebp-1B8h] BYREF
  int v8; // [esp+1A8h] [ebp-10h]
  int v9; // [esp+1ACh] [ebp-Ch]
  int v10; // [esp+1B0h] [ebp-8h]
  int v11; // [esp+1B4h] [ebp-4h] BYREF

  v5 = a2;
  v11 = 0;
  memset(v7, -1, sizeof(v7));
  sub_98363(a1, (int)v7, (int16_t *)&v11);
  if ( a2 > (int16_t)v11 )
    v5 = v11;
  while ( v5 )
  {
    v6 = sub_1247A0((int16_t)v11) - 1;
    v8 = (int16_t)v7[v6];
    v9 = 3753 * (int16_t)a1;
    sub_E4204(v9 + dword_197F98, v8, a1);
    *(_WORD *)(v10 + 2 * (int16_t)(*a4)++) = v8;
    --v11;
    --v5;
    v7[v6] = v7[(int16_t)v11];
  }
  JUMPOUT(0x97152);
}
// 982FC: control flows out of bounds to 97152
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;


//----- (00098363) --------------------------------------------------------
char __fastcall sub_98363( int a1, int a2, int16_t *a3)
{
  int16_t i; // cx
  int v4; // eax

  *a3 = 0;
  for ( i = 0; i < 212; ++i )
  {
    LOWORD(v4) = *(int16_t *)((char *)&word_17E07F + 13 * i);
    if ( (_WORD)v4 == 74 )
    {
      LOBYTE(v4) = sub_E412B(dword_197F98 + 3753 * a1, i);
      if ( (_BYTE)v4 )
      {
        v4 = *a3;
        *(_WORD *)(a2 + 2 * v4) = i;
        ++*a3;
      }
    }
  }
  return v4;
}
// 17E07F: using guessed type int16_t word_17E07F;
// 197F98: using guessed type int dword_197F98;


//----- (000983B8) --------------------------------------------------------
void sub_983B8()
{
  int i; // ecx
  char v1; // [esp+0h] [ebp-72h]
  _WORD v2[66]; // [esp+4h] [ebp-6Eh] BYREF
  _BYTE v3[100]; // [esp+88h] [ebp+16h] BYREF
  int v4; // [esp+ECh] [ebp+7Ah]
  int v5; // [esp+F0h] [ebp+7Eh]

  v5 = -1;
  for ( i = 0; (int16_t)i < word_199994 && (int16_t)v5 == -1; ++i )
  {
    if ( sub_77FF5(i) == 9 )
      v5 = i;
  }
  v4 = (int16_t)v5;
  if ( (int16_t)v5 > -1 && (int16_t)v5 < word_199994 )
  {
    sub_58487((int)v3);
    memset(v2, 0, 129);
    qmemcpy(v2, v3, 0x63u);
    *(_WORD *)((char *)&v2[50] + 1) = 0;
    HIBYTE(v2[49]) = v1;
    HIBYTE(v2[46]) = v1;
    *(_WORD *)((char *)&v2[51] + 1) = *(_WORD *)(dword_19306C + 15);
    *(_WORD *)((char *)&v2[52] + 1) = *(_WORD *)(dword_19306C + 17);
    v2[58] = 65;
    LOBYTE(v2[50]) = 0;
    qmemcpy((void *)(129 * v4 + dword_197F9C), v2, 0x81u);
  }
  JUMPOUT(0x92E66);
}
// 98484: control flows out of bounds to 92E66
// 98448: variable 'v1' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (00098489) --------------------------------------------------------
void sub_98489()
{
  int v0; // eax
  int16_t i; // bx
  int16_t v2; // si
  int16_t v3; // dx
  int16_t v4; // di
  int v5; // esi
  int16_t j; // ax
  int16_t v7; // dx
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  int16_t k; // bx
  int16_t v12; // si
  int16_t v13; // ax
  int16_t v14; // di
  int16_t m; // ax
  int v16; // esi
  char v17; // cl
  int16_t v18; // bx
  int16_t v19; // di
  int v20; // ecx
  int v21; // edx
  _WORD v22[68]; // [esp+0h] [ebp-CCh]
  _BYTE v23[68]; // [esp+88h] [ebp-44h] BYREF

  memset(v23, 0, 67);
  v0 = 0;
  do
  {
    v22[(int16_t)v0] = v0;
    ++v0;
  }
  while ( (int16_t)v0 < 67 );
  for ( i = 0; i < 10; ++i )
  {
    v2 = sub_1247A0(0xAu) - 1;
    v3 = sub_1247A0(0xAu) - 1;
    if ( v2 != v3 )
    {
      v4 = v22[v2];
      v22[v2] = v22[v3];
      v22[v3] = v4;
    }
  }
  v5 = 0;
  for ( j = 0; j < word_199998; ++j )
  {
    if ( *(_BYTE *)(3753 * j + dword_197F98 + 2226) )
    {
      v7 = v22[(int16_t)v5];
      v8 = v7;
      ++v5;
      if ( v7 > -1 )
      {
        v9 = dword_1930DC + 59 * v7;
        *(_BYTE *)(v9 + 57) = 4;
        *(_BYTE *)(v9 + 58) = j;
        v23[v8] = 1;
      }
    }
  }
  v10 = 0;
  do
  {
    v22[(int16_t)v10] = v10;
    ++v10;
  }
  while ( (int16_t)v10 < 67 );
  for ( k = 0; k < 25; ++k )
  {
    v12 = sub_1247A0(0x19u) - 1;
    v13 = sub_1247A0(0x19u) - 1;
    if ( v12 != v13 )
    {
      v14 = v22[v12];
      v22[v12] = v22[v13];
      v22[v13] = v14;
    }
  }
  for ( m = 0; m < word_199998; ++m )
  {
    if ( !*(_BYTE *)(dword_197F98 + 3753 * m + 2226) )
    {
      v16 = 0;
      do
      {
        v17 = 0;
        v18 = 0;
        do
        {
          v19 = v22[v18];
          if ( v23[v19] )
            ++v18;
          else
            v17 = 1;
        }
        while ( !v17 );
        if ( v19 > -1 )
        {
          v20 = 59 * v19;
          v21 = dword_1930DC;
          *(_BYTE *)(v20 + dword_1930DC + 57) = 4;
          *(_BYTE *)(v20 + v21 + 58) = m;
          v23[v19] = 1;
        }
        ++v16;
      }
      while ( (int16_t)v16 < 2 );
    }
  }
  JUMPOUT(0x94800);
}
// 9862E: control flows out of bounds to 94800
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00098633) --------------------------------------------------------
void __fastcall sub_98633(int a1)
{
  int16_t v1; // cx
  int16_t v2; // di
  int v3; // eax
  int16_t v4; // dx
  int16_t j; // si
  char v6; // al
  int16_t i; // si
  char v8; // al

  v1 = 0;
  while ( 1 )
  {
    v2 = *(_WORD *)(dword_193188 + 2 * v1);
    if ( v2 > -1 )
    {
      v3 = 59 * v2 + dword_1930DC;
      v4 = *(char *)(v3 + 58);
      if ( *(_BYTE *)(v3 + 35) )
      {
        if ( *(_BYTE *)(v3 + 35) == 1 )
        {
          for ( i = 0; i < 54; ++i )
          {
            if ( byte_17D21D[18 * i] || !sub_9467D(v4, v2, i) )
            {
              if ( byte_17D21D[18 * i] != 2 )
                continue;
              sub_9469E();
              if ( !v8 )
                continue;
            }
            ++*(_WORD *)(a1 + 2 * v1);
          }
        }
      }
      else
      {
        for ( j = 0; j < 54; ++j )
        {
          if ( byte_17D21D[18 * j] || !sub_9467D(v4, v2, j) )
          {
            if ( byte_17D21D[18 * j] != 1 )
              continue;
            sub_9469E();
            if ( !v6 )
              continue;
          }
          ++*(_WORD *)(a1 + 2 * v1);
        }
      }
    }
    if ( ++v1 >= 4 )
      JUMPOUT(0x94800);
  }
}
// 98727: control flows out of bounds to 94800
// 986AE: variable 'v6' is possibly undefined
// 98708: variable 'v8' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;
// 193188: using guessed type int dword_193188;


//----- (0009872C) --------------------------------------------------------
void sub_9872C()
{
  _BYTE v0[8]; // [esp+0h] [ebp-8h] BYREF

  memset(v0, 0, sizeof(v0));
  sub_98633((int)v0);
  if ( byte_199F1F == 1 )
    sub_6F95F((int)v0);
  else
    sub_6F9BD((int)v0, word_19992C);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19992C: using guessed type int16_t word_19992C;
// 199F1F: using guessed type char byte_199F1F;


//----- (00098771) --------------------------------------------------------
void __fastcall sub_98771( int a1)
{
  int v2; // eax
  int16_t v3; // dx

  v2 = dword_1930DC + 59 * a1;
  v3 = *(_WORD *)(v2 + 53);
  if ( *(_BYTE *)(v2 + 35) )
  {
    if ( v3 > -1 && v3 < word_19999A )
      *(_BYTE *)(*(char *)(v2 + 58) + 113 * v3 + dword_19306C + 66) = -1;
  }
  else if ( v3 > -1 && v3 < word_199994 )
  {
    *(_WORD *)(129 * v3 + dword_197F9C + 116) = -1;
  }
  sub_933F2(a1);
  sub_92E72();
  sub_93DF7();
  sub_9872C();
  byte_19C544 = -1;
}
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999A: using guessed type int16_t word_19999A;
// 19C544: using guessed type char byte_19C544;


//----- (000987FB) --------------------------------------------------------
void __fastcall sub_987FB(int a1, int a2, int a3)
{
  int16_t v3; // ax
  int16_t *v4; // edi
  char *v5; // esi
  char v6; // al
  int16_t *v7; // eax
  uint8_t v8; // al
  int v9; // edx
  int v10; // ebx
  int16_t *v11; // edi
  char *v12; // esi
  char v13; // al
  int16_t *v14; // eax
  int16_t *v15; // edi
  char v16; // al
  int16_t *v17; // eax
  char v18; // ah
  int v19; // edx
  int v20; // ecx
  int16_t *v21; // edi
  char *v22; // esi
  char v23; // al
  int16_t v24; // ax
  int16_t *v25; // edi
  char v26; // al
  int16_t *v27; // eax
  uint8_t v28; // al
  int v29; // edx
  int v30; // ebx
  int16_t *v31; // edi
  char *v32; // esi
  char v33; // al
  int16_t *v34; // eax
  int16_t *v35; // edi
  char v36; // al
  int16_t *v37; // eax
  int v38; // edx
  int v39; // eax
  int v40; // ecx
  int v41; // eax
  uint16_t v42; // ax
  int16_t *v43; // edi
  char *v44; // esi
  char v45; // al
  int16_t *v46; // eax
  int16_t *v47; // [esp-8h] [ebp-56h]
  int16_t *v48; // [esp-8h] [ebp-56h]
  int v49; // [esp-4h] [ebp-52h]
  int v50; // [esp-4h] [ebp-52h]
  int v51; // [esp-4h] [ebp-52h]
  int v52; // [esp-4h] [ebp-52h]
  int v53; // [esp-4h] [ebp-52h]
  int v54; // [esp-4h] [ebp-52h]
  int v55; // [esp-4h] [ebp-52h]
  int v56; // [esp-4h] [ebp-52h]
  int16_t v57; // [esp+0h] [ebp-4Eh]
  int16_t v58[100]; // [esp+4h] [ebp-4Ah] BYREF
  _BYTE v59[200]; // [esp+CCh] [ebp+7Eh] BYREF
  int v60; // [esp+194h] [ebp+146h]
  int v61; // [esp+198h] [ebp+14Ah]
  int v62; // [esp+19Ch] [ebp+14Eh]
  char v63; // [esp+1A0h] [ebp+152h]

  if ( byte_199F1F )
  {
    v60 = a2;
    v30 = (int16_t)a2;
    v28 = sub_98F42(word_19999C, v57, a2);
    v29 = 113 * (int16_t)a2;
    LOWORD(v30) = v28;
    if ( v28 )
    {
      v31 = v58;
      v32 = sub_7A990(0x118u);
      do
      {
        v33 = *v32++;
        *(_BYTE *)v31 = v33;
        v31 = (int16_t *)((char *)v31 + 1);
      }
      while ( v33 );
      if ( byte_199CAE == 4 )
      {
        v53 = v29 + dword_19306C;
        v34 = sub_97588(v57, 0);
        sprintf(v59, (char *)v58, v34, (int16_t)v30, v53);
      }
      else
      {
        v54 = v29 + dword_19306C;
        v48 = sub_97588(v57, 0);
        sprintf(v59, (char *)v58, (int16_t)v30, v48, v54);
      }
    }
    else
    {
      v35 = v58;
      v32 = sub_7A990(0x119u);
      do
      {
        v36 = *v32++;
        *(_BYTE *)v35 = v36;
        v35 = (int16_t *)((char *)v35 + 1);
      }
      while ( v36 );
      v55 = v29 + dword_19306C;
      v37 = sub_97588(v57, 0);
      sprintf(v59, (char *)v58, v37, v55);
    }
    v63 = sub_94B3A((int)v59, 1u, v30, v58, (int16_t)v32);
    if ( v63 )
    {
      v38 = 113 * (int16_t)v60;
      v39 = word_19999C;
      v40 = word_19999C + v38 + dword_19306C;
      LOWORD(v39) = *(char *)(v40 + 66);
      v61 = v39;
      if ( (_WORD)v39 != v57 )
      {
        v41 = *(char *)(v40 + 66);
        if ( v41 != -1 )
        {
          if ( *(char *)(dword_1930DC + 59 * v41 + 55) <= 0 )
            v42 = 283;
          else
            v42 = 282;
          v43 = v58;
          v44 = sub_7A990(v42);
          do
          {
            v45 = *v44++;
            *(_BYTE *)v43 = v45;
            v43 = (int16_t *)((char *)v43 + 1);
          }
          while ( v45 );
          v56 = v38 + dword_19306C;
          v46 = sub_97588(v61, 1);
          sprintf(v59, (char *)v58, v46, v56);
          v63 = sub_94B3A((int)v59, 1u, v30, v58, (int16_t)v44);
        }
      }
    }
    if ( v63 )
      sub_98CEB(dword_197F98 + 3753 * word_19999C, 59 * v57 + dword_1930DC, 113 * (int16_t)v60 + dword_19306C, v30);
  }
  else
  {
    v62 = a2;
    v3 = sub_77FF5(a2);
    if ( v3 == word_19999C )
    {
      HIWORD(v10) = (int16_t)a2 >> 15;
      v8 = sub_98E4B(v3, v57, a2);
      v9 = 129 * (int16_t)a2;
      LOWORD(v10) = v8;
      if ( v8 )
      {
        v11 = v58;
        v12 = sub_7A990(0x118u);
        do
        {
          v13 = *v12++;
          *(_BYTE *)v11 = v13;
          v11 = (int16_t *)((char *)v11 + 1);
        }
        while ( v13 );
        if ( byte_199CAE == 4 )
        {
          v49 = v9 + dword_197F9C;
          v14 = sub_97588(v57, 0);
          sprintf(v59, (char *)v58, v14, (int16_t)v10, v49);
        }
        else
        {
          v50 = dword_197F9C + v9;
          v47 = sub_97588(v57, 0);
          sprintf(v59, (char *)v58, (int16_t)v10, v47, v50);
        }
      }
      else
      {
        v15 = v58;
        v12 = sub_7A990(0x119u);
        do
        {
          v16 = *v12++;
          *(_BYTE *)v15 = v16;
          v15 = (int16_t *)((char *)v15 + 1);
        }
        while ( v16 );
        v51 = v9 + dword_197F9C;
        v17 = sub_97588(v57, 0);
        sprintf(v59, (char *)v58, v17, v51);
      }
      v18 = sub_94B3A((int)v59, 1u, v10, v58, (int16_t)v12);
      if ( v18 )
      {
        v19 = 129 * (int16_t)v62;
        if ( *(int16_t *)(v19 + dword_197F9C + 116) != -1 )
        {
          v20 = *(int16_t *)(v19 + dword_197F9C + 116);
          if ( *(char *)(dword_1930DC + 59 * v20 + 55) <= 0 )
          {
            v25 = v58;
            v22 = sub_7A990(0x11Bu);
            do
            {
              v26 = *v22++;
              *(_BYTE *)v25 = v26;
              v25 = (int16_t *)((char *)v25 + 1);
            }
            while ( v26 );
            v52 = v19 + dword_197F9C;
            v24 = v20;
          }
          else
          {
            v21 = v58;
            v22 = sub_7A990(0x11Au);
            do
            {
              v23 = *v22++;
              *(_BYTE *)v21 = v23;
              v21 = (int16_t *)((char *)v21 + 1);
            }
            while ( v23 );
            v52 = dword_197F9C + v19;
            v24 = v20;
          }
          v27 = sub_97588(v24, 1);
          sprintf(v59, (char *)v58, v27, v52);
          v18 = sub_94B3A((int)v59, 1u, v10, v58, (int16_t)v22);
        }
      }
      if ( v18 )
        sub_98DAD(dword_197F98 + 3753 * word_19999C, dword_1930DC + 59 * v57, 129 * (int16_t)v62 + dword_197F9C, v10);
    }
    else
    {
      v4 = v58;
      v5 = sub_7A990(0x117u);
      do
      {
        v6 = *v5++;
        *(_BYTE *)v4 = v6;
        v4 = (int16_t *)((char *)v4 + 1);
      }
      while ( v6 );
      v7 = sub_97588(v57, 0);
      sprintf(v59, (char *)v58, v7);
      sub_94B3A((int)v59, 3u, a3, v58, (int16_t)v5);
    }
  }
  JUMPOUT(0x97739);
}
// 98C1E: control flows out of bounds to 97739
// 98856: variable 'v57' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 199CAE: using guessed type char byte_199CAE;
// 199F1F: using guessed type char byte_199F1F;


//----- (00098C23) --------------------------------------------------------
int __fastcall sub_98C23(int a1, int a2, int a3)
{
  char v4; // al

  v4 = sub_98E4B((a1 - dword_197F98) / 3753, (a2 - dword_1930DC) / 59, (a3 - dword_197F9C) / 129);
  return sub_98DAD(a1, a2, a3, v4);
}
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;


//----- (00098C87) --------------------------------------------------------
char __fastcall sub_98C87(int a1, int a2, int a3)
{
  char v4; // al

  v4 = sub_98F42((a1 - dword_197F98) / 3753, (a2 - dword_1930DC) / 59, (a3 - dword_19306C) / 113);
  return sub_98CEB(a1, a2, a3, v4);
}
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (00098CEB) --------------------------------------------------------
char __fastcall sub_98CEB(int a1, int a2, int a3, int a4)
{
  int v5; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  char result; // al
  int16_t v12; // [esp+0h] [ebp-10h]
  int v13; // [esp+4h] [ebp-Ch]
  int16_t v15; // [esp+Ch] [ebp-4h]

  v12 = (a2 - dword_1930DC) / 59;
  v13 = (a3 - dword_19306C) / 113;
  v5 = (a1 - dword_197F98) / 3753;
  v6 = a3 + (int16_t)v5;
  v7 = *(char *)(v6 + 66);
  if ( v7 > -1 && *(char *)(v6 + 66) < 67 )
  {
    v15 = *(char *)(v6 + 66);
    v8 = 59 * v7;
    v9 = dword_1930DC;
    *(_BYTE *)(dword_1930DC + v8 + 55) = 0;
    v10 = 59 * v15;
    *(_BYTE *)(v9 + v10 + 57) = 0;
    *(_WORD *)(v9 + v10 + 53) = -1;
  }
  if ( *(int16_t *)(a2 + 53) > -1 )
    *(_BYTE *)((int16_t)v5 + 113 * *(int16_t *)(a2 + 53) + dword_19306C + 66) = -1;
  *(_WORD *)(a2 + 53) = v13;
  *(_BYTE *)(a2 + 55) = a4;
  *(_BYTE *)(a2 + 57) = 1;
  result = v12;
  *(_BYTE *)((int16_t)v5 + a3 + 66) = v12;
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (00098DAD) --------------------------------------------------------
int __fastcall sub_98DAD(int a1, int a2, int a3, int a4)
{
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int result; // eax
  int v9; // [esp+0h] [ebp-8h]
  int v10; // [esp+4h] [ebp-4h]

  v9 = (a2 - dword_1930DC) / 59;
  v10 = (a3 - dword_197F9C) / 129;
  v5 = *(int16_t *)(a3 + 116);
  if ( v5 > -1 && *(int16_t *)(a3 + 116) < 67 )
  {
    v6 = 59 * v5;
    v7 = dword_1930DC;
    *(_BYTE *)(v6 + dword_1930DC + 57) = 0;
    *(_WORD *)(59 * *(int16_t *)(a3 + 116) + v7 + 53) = -1;
    *(_BYTE *)(59 * *(int16_t *)(a3 + 116) + v7 + 55) = 0;
  }
  if ( *(int16_t *)(a2 + 53) > -1 )
    *(_WORD *)(129 * *(int16_t *)(a2 + 53) + dword_197F9C + 116) = -1;
  *(_BYTE *)(a2 + 57) = 1;
  *(_BYTE *)(a2 + 55) = a4;
  *(_WORD *)(a2 + 53) = v10;
  result = v9;
  *(_WORD *)(a3 + 116) = v9;
  return result;
}
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;


//----- (00098E4B) --------------------------------------------------------
char __fastcall sub_98E4B( int a1, int a2, int a3)
{
  int16_t v4; // si
  _BOOL1 v5; // dl
  int16_t v6; // ax
  int v7; // eax
  int v8; // eax
  int16_t v11; // [esp+8h] [ebp-8h]

  v4 = a3;
  LOBYTE(a3) = 5;
  v5 = 0;
  if ( dword_19C4C8 )
    v6 = *(_WORD *)(dword_19C4C8 + 5 * a2 + 1);
  else
    v6 = sub_78E07(*(int16_t *)(59 * a2 + dword_1930DC + 53));
  v11 = *(uint8_t *)(17 * *(int16_t *)(3753 * a1 + dword_197F98 + 41) + dword_1930D4 + 2);
  if ( v6 != -1 )
    v5 = sub_97287(v6, v4);
  if ( dword_19C4C8 )
  {
    v7 = dword_19C4C8 + 5 * a2;
    if ( *(_BYTE *)v7 && *(_BYTE *)v7 != 4 )
    {
      if ( v5 )
        return *(_WORD *)(v7 + 3);
    }
    else
    {
      v8 = dword_197F9C + 129 * v4;
      if ( *(_WORD *)(v8 + 101) == v11 || (uint16_t)sub_7A3E3(*(_WORD *)(v8 + 103), *(_WORD *)(v8 + 105)) == v11 )
        goto LABEL_15;
    }
  }
  else if ( v5 )
  {
LABEL_15:
    LOBYTE(a3) = 0;
  }
  return a3;
}
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 19C4C8: using guessed type int dword_19C4C8;


//----- (00098F42) --------------------------------------------------------
char __fastcall sub_98F42( int a1, int a2, int a3)
{
  int16_t v3; // cx
  int16_t v4; // si
  int16_t v5; // di
  int v6; // eax

  v3 = a3;
  LOBYTE(a3) = 5;
  v4 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_197F98 + 3753 * a1 + 41) + 2);
  if ( dword_19C4C8 )
    v5 = *(_WORD *)(dword_19C4C8 + 5 * a2 + 1);
  else
    v5 = *(_WORD *)(dword_1930DC + 59 * a2 + 53);
  if ( dword_19C4C8 )
  {
    v6 = 5 * a2 + dword_19C4C8;
    if ( *(_BYTE *)v6 && *(_BYTE *)v6 != 4 )
    {
      if ( v5 == v3 )
        return *(_WORD *)(v6 + 3);
    }
    else if ( v3 == v4 )
    {
LABEL_13:
      LOBYTE(a3) = 0;
    }
  }
  else if ( v3 == v4 && !*(_BYTE *)(dword_1930DC + 59 * a2 + 57) )
  {
    goto LABEL_13;
  }
  return a3;
}
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 19C4C8: using guessed type int dword_19C4C8;


//----- (00098FEE) --------------------------------------------------------
void __usercall sub_98FEE(int16_t *a1)
{
  char *v1; // eax
  int16_t v2; // ax
  int16_t v3; // cx
  int16_t v4; // bx
  int v5; // eax
  uint16_t v6; // ax
  int16_t *v7; // eax
  int16_t v8; // ax
  int16_t v9; // ax
  int16_t i; // ax
  int v11; // edx
  int16_t *v12; // eax
  int16_t *v13; // eax
  int v14; // [esp-4h] [ebp-4Eh]
  int v15; // [esp-4h] [ebp-4Eh]
  int v16; // [esp-4h] [ebp-4Eh]
  char v17[200]; // [esp+0h] [ebp-4Ah] BYREF
  _BYTE v18[200]; // [esp+C8h] [ebp+7Eh] BYREF
  char v19; // [esp+190h] [ebp+146h]

  v19 = 0;
  while ( 1 )
  {
    sub_124D41();
    sub_84E9D();
    sub_124E36();
    sub_124C08();
    v14 = dword_197F98 + 3753 * word_19999C + 1;
    v1 = sub_7A990(0x11Cu);
    sprintf(v18, v1, v14);
    v2 = sub_C9EB0(0, 66, (int)v18, 0, a1, 0);
    v3 = v2;
    if ( v2 <= 0 )
    {
      v19 = 1;
    }
    else
    {
      v4 = v2;
      v5 = dword_1930DC + 59 * v2;
      if ( *(char *)(v5 + 57) != -1 )
      {
        v6 = 279;
LABEL_5:
        strcpy(v17, sub_7A990(v6));
        v7 = sub_97588(v4, 0);
        sprintf(v18, v17, v7);
        goto LABEL_6;
      }
      if ( *(_BYTE *)(v5 + 35) == 1 )
      {
        sub_977AF(word_19999C);
        if ( v8 == 4 )
        {
          v6 = 286;
          goto LABEL_5;
        }
      }
      else
      {
        sub_9776C(word_19999C);
        if ( v9 == 4 )
        {
          v6 = 287;
          goto LABEL_5;
        }
      }
      for ( i = 0; i < word_199998; ++i )
      {
        v11 = 3753 * i;
        if ( *(char *)(v11 + dword_197F98 + 1441) == v3 )
        {
          strcpy(v17, sub_7A990(0x120u));
          v15 = v11 + dword_197F98 + 1;
          v12 = sub_97588(v3, 0);
          sprintf(v18, v17, v12, v15);
LABEL_6:
          sub_7A25F(&byte_199F28, (int)v18, 3);
LABEL_22:
          JUMPOUT(0x92E6C);
        }
      }
      strcpy(v17, sub_7A990(0x132u));
      a1 = (int16_t *)v17;
      v16 = dword_197F98 + 3753 * word_19999C + 1;
      v13 = sub_97588(v3, 1);
      sprintf(v18, v17, v13, v16);
      if ( (uint16_t)sub_7A25F(&byte_199F28, (int)v18, 1) )
      {
        v19 = 1;
        *(_BYTE *)(3753 * word_19999C + dword_197F98 + 1441) = v3;
      }
    }
    if ( v19 )
    {
      word_19994C = 1;
      goto LABEL_22;
    }
  }
}
// 9921E: control flows out of bounds to 92E6C
// 990E0: variable 'v8' is possibly undefined
// 990F9: variable 'v9' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 199F28: using guessed type char byte_199F28;


//----- (00099223) --------------------------------------------------------
void __fastcall sub_99223( int a1, int a2)
{
  int16_t v3; // ax
  int16_t v4; // si
  int v5; // edi
  int16_t i; // si
  unsigned int v7; // edi
  char v8; // al
  char v9; // al
  int v10; // [esp+0h] [ebp-4h]

  if ( a1 == 47 )
  {
    v3 = sub_93D0A(a2);
    v4 = 0;
    if ( (uint16_t)v3 < 3u )
    {
      if ( v3 == 1 )
        v4 = 42;
    }
    else if ( (uint16_t)v3 <= 3u )
    {
      v4 = 92;
    }
    else if ( (uint16_t)v3 >= 5u )
    {
      if ( (uint16_t)v3 <= 5u )
      {
        v4 = 65;
      }
      else if ( v3 == 7 )
      {
        v4 = 77;
      }
    }
    v5 = 3753 * a2;
    if ( sub_E412B(v5 + dword_197F98, v4) )
      sub_E4204(v5 + dword_197F98, v4, v5);
  }
  else
  {
    for ( i = 0; i < 3; ++i )
    {
      if ( *(_BYTE *)(i + 59 * a1 + dword_1930DC + 46) )
      {
        v7 = *(uint8_t *)(i + 59 * a1 + dword_1930DC + 46);
        v10 = 3753 * a2;
        if ( sub_E412B(v10 + dword_197F98, v7) )
          sub_E4204(v10 + dword_197F98, v7, v7);
      }
    }
  }
  if ( !*(_BYTE *)(59 * a1 + dword_1930DC + 35) )
  {
    sub_9469E();
    if ( v8 || (sub_9469E(), v9) )
      *(_BYTE *)(dword_197F98 + 3753 * a2 + 3701) = 1;
  }
  JUMPOUT(0x941B5);
}
// 99356: control flows out of bounds to 941B5
// 99327: variable 'v8' is possibly undefined
// 99339: variable 'v9' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (0009935B) --------------------------------------------------------
void __fastcall sub_9935B( int a1)
{
  int16_t v2; // cx
  int16_t v3; // di
  int16_t v4; // bx
  int v5; // [esp+0h] [ebp-Ch]
  int16_t v6; // [esp+4h] [ebp-8h]

  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v5 = 59 * v3;
    if ( *(char *)(v5 + dword_1930DC + 58) != a1 || !sub_9773F(v3) )
      goto LABEL_11;
    v6 = 0;
    if ( (*(_DWORD *)(v5 + dword_1930DC + 38) & dword_17D261) != 0 )
    {
      v4 = 4;
    }
    else
    {
      if ( (*(_DWORD *)(v5 + dword_1930DC + 38) & dword_17D273) == 0 )
        goto LABEL_9;
      v4 = 5;
    }
    v6 = sub_94BB2(a1, v3, v4);
LABEL_9:
    if ( v2 < v6 )
      v2 = v6;
LABEL_11:
    if ( ++v3 >= 67 )
      JUMPOUT(0x947FE);
  }
}
// 993EA: control flows out of bounds to 947FE
// 17D261: using guessed type int dword_17D261;
// 17D273: using guessed type int dword_17D273;
// 1930DC: using guessed type int dword_1930DC;


//----- (00099403) --------------------------------------------------------
int __fastcall sub_99403(_DWORD *a1)
{
  _DWORD *v1; // edi
  int result; // eax
  _DWORD *v3; // kr00_4
  char *v4; // esi
  _DWORD *v5; // edi
  char *v6; // esi

  v1 = a1;
  LOBYTE(a1) = byte_199CAE;
  v3 = a1;
  result = (uint8_t)byte_199CAE;
  switch ( byte_199CAE )
  {
    case 1:
      v4 = aGerskllsLbx;
      break;
    case 2:
      v4 = aFreskllsLbx;
      break;
    case 3:
      v4 = aSpaskllsLbx;
      break;
    case 4:
      v4 = aItaskllsLbx;
      break;
    default:
      result = (int)v3;
      v4 = aSkildescLbx;
      break;
  }
  *v1 = *(_DWORD *)v4;
  v6 = v4 + 4;
  v5 = v1 + 1;
  *v5 = *(_DWORD *)v6;
  v6 += 4;
  *++v5 = *(_DWORD *)v6;
  *((_BYTE *)v5 + 4) = v6[4];
  return result;
}
// 199CAE: using guessed type char byte_199CAE;


//----- (0009946D) --------------------------------------------------------
char __fastcall sub_9946D( int a1, char *a2)
{
  char result; // al
  uint16_t v4; // ax

  *a2 = 0;
  result = sub_8F8DC(*(_BYTE *)(59 * a1 + dword_1930DC + 15));
  if ( result )
  {
    v4 = 390;
  }
  else
  {
    if ( a1 == 26 || a1 == 43 || a1 == 52 )
    {
      strcpy(a2, ", lo ");
      return result;
    }
    if ( a1 == 10 || a1 == 22 || a1 == 34 || a1 == 37 || a1 == 39 || a1 == 60 )
      result = 1;
    if ( result )
      v4 = 386;
    else
      v4 = 272;
  }
  strcpy(a2, sub_7A990(v4));
  return result;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (00099522) --------------------------------------------------------
int __fastcall sub_99522(int result, int a2)
{
  *(_WORD *)(result + 36) = 1;
  *(_WORD *)(result + 28) = a2;
  return result;
}


//----- (0009952D) --------------------------------------------------------
int16_t __fastcall sub_9952D(int a1)
{
  if ( *(_WORD *)(a1 + 36) == 1 )
    return *(_WORD *)(a1 + 28);
  else
    return -1;
}


//----- (0009953F) --------------------------------------------------------
unsigned int __fastcall sub_9953F(_WORD *a1, int a2)
{
  unsigned int result; // eax

  result = sub_11438B(
             102 - **(_WORD **)(dword_19C598 + 52) - 2,
             55 * a2 + 84 - *(_WORD *)(*(_DWORD *)(dword_19C598 + 52) + 2) - 2,
             100,
             55 * a2 + 82,
             &unk_179B78,
             0);
  *a1 = result;
  return result;
}
// 19C598: using guessed type int dword_19C598;


//----- (0009958B) --------------------------------------------------------
unsigned int __fastcall sub_9958B(_WORD *a1, int a2)
{
  unsigned int result; // eax

  result = sub_11438B(
             102,
             55 * a2 + 84 - *(_WORD *)(*(_DWORD *)(dword_19C598 + 52) + 2),
             **(_WORD **)(dword_19C598 + 52) + 102,
             55 * a2 + 84,
             &unk_179B78,
             0);
  *a1 = result;
  return result;
}
// 19C598: using guessed type int dword_19C598;


//----- (000995D1) --------------------------------------------------------
void sub_995D1()
{
  int16_t v0; // ax
  _WORD *v1; // ecx
  int16_t v2; // ax
  _WORD *v3; // ecx
  int16_t v4; // ax
  _WORD *v5; // ecx
  int16_t v6; // dx
  int v7; // eax
  int16_t v8; // ax
  _WORD *v9; // ecx
  int16_t v10; // ax
  _WORD *v11; // ecx
  int16_t v12; // ax
  _WORD *v13; // ecx
  int16_t v14; // dx
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int v18; // edx
  int16_t v19; // si
  int16_t v20; // di
  int v21; // ecx
  int16_t i; // di
  int v23; // esi
  int16_t v24; // dx
  int v25; // eax
  uint16_t v26; // ax
  _WORD *v27; // ecx
  uint16_t v28; // dx
  int v29; // eax
  uint16_t v30; // dx
  int v31; // eax
  int v32; // esi

  v0 = sub_115383(441, 200, (int)&unk_179B78, *(_WORD **)(dword_19C598 + 4), (int)&word_182306, 0, &unk_179B78, 41);
  v1 = *(_WORD **)(dword_19C598 + 8);
  *(_WORD *)(dword_19C598 + 56) = v0;
  v2 = sub_115383(501, 200, (int)&unk_179B78, v1, (int)&word_182306, 1, &unk_179B78, 41);
  v3 = *(_WORD **)(dword_19C598 + 12);
  *(_WORD *)(dword_19C598 + 58) = v2;
  v4 = sub_115383(567, 200, (int)&unk_179B78, v3, (int)&word_182306, 2, &unk_179B78, 41);
  v5 = *(_WORD **)(dword_19C598 + 16);
  *(_WORD *)(dword_19C598 + 60) = v4;
  v6 = sub_11523B(441, 266, (int)&unk_179B78, v5, (int)&off_18230E, a1_2, 41);
  v7 = dword_19C598;
  *(_WORD *)(dword_19C598 + 62) = v6;
  v8 = sub_11523B(441, 289, (int)&unk_179B78, *(_WORD **)(v7 + 20), (int)&word_182308, a2_2, 41);
  v9 = *(_WORD **)(dword_19C598 + 24);
  *(_WORD *)(dword_19C598 + 64) = v8;
  v10 = sub_11523B(441, 312, (int)&unk_179B78, v9, (int)&word_18230A, a3, 41);
  v11 = *(_WORD **)(dword_19C598 + 28);
  *(_WORD *)(dword_19C598 + 66) = v10;
  v12 = sub_11523B(441, 335, (int)&unk_179B78, v11, (int)&word_18230C, a4, 41);
  v13 = *(_WORD **)(dword_19C598 + 32);
  *(_WORD *)(dword_19C598 + 68) = v12;
  v14 = sub_11523B(441, 358, (int)&unk_179B78, v13, (int)&off_18230E + 2, a5, 41);
  v15 = dword_19C598;
  *(_WORD *)(dword_19C598 + 70) = v14;
  if ( byte_19C5EA )
    *(_WORD *)(dword_19C598 + 72) = sub_11438B(454, 386, 609, 408, aC_4, 41);
  else
    *(_WORD *)(v15 + 72) = -1000;
  if ( byte_19C5E9 )
    *(_WORD *)(dword_19C598 + 74) = sub_11438B(454, 413, 610, 437, aO_0, 41);
  else
    *(_WORD *)(dword_19C598 + 74) = -1000;
  v16 = 0;
  do
  {
    v17 = dword_19C598;
    v18 = 2 * (int16_t)v16;
    *(_WORD *)(v18 + dword_19C598 + 92) = -1000;
    ++v16;
    *(_WORD *)(v18 + v17 + 108) = -1000;
  }
  while ( (int16_t)v16 < 8 );
  v19 = 0;
  while ( 1 )
  {
    v20 = v19 + *(_WORD *)(dword_1975C4 + 12);
    if ( *(char *)(28 * v20 + dword_19C5A0 + 26) >= 0 )
    {
      v21 = 2 * v19;
      sub_9953F((_WORD *)(v21 + dword_19C598 + 92), v19);
      byte_199F09 = *(_BYTE *)(v21 + dword_19C598 + 92);
    }
    if ( *(char *)(dword_19C5A0 + 28 * v20 + 27) >= 0 )
      sub_9958B((_WORD *)(dword_19C598 + 108 + 2 * v19), v19);
    if ( ++v19 >= 8 )
    {
      for ( i = 0; i < 8; ++i )
      {
        v23 = i;
        v24 = sub_11438B(18, word_1822B8[i] + 36, 414, word_1822B8[i] + 86, &unk_179B78, 41);
        v25 = dword_19C598;
        *(_WORD *)(dword_19C598 + 2 * v23 + 76) = v24;
      }
      v26 = (uint16_t)sub_1151B0(422, 16, (int)&unk_179B78, *(_WORD **)(v25 + 36), asc_179B87, 40);
      v27 = *(_WORD **)(dword_19C598 + 40);
      *(_WORD *)(dword_19C598 + 124) = v26;
      v28 = (uint16_t)sub_1151B0(421, 448, (int)&unk_179B78, v27, &off_179B89, 40);
      v29 = dword_19C598 + 130;
      *(_WORD *)(dword_19C598 + 126) = v28;
      sub_999BF(v29);
      sub_99981();
      v30 = (uint16_t)sub_1151B0(
                                454,
                                440,
                                (int)&unk_179B78,
                                *(_WORD **)(dword_19C598 + 44),
                                (_BYTE *)&off_179B89 + 2,
                                40);
      v31 = dword_19C598;
      *(_WORD *)(dword_19C598 + 128) = v30;
      v32 = dword_1975C4;
      *(_WORD *)(dword_1975C4 + 16) = *(_WORD *)(v31 + 124);
      *(_WORD *)(v32 + 18) = *(_WORD *)(v31 + 126);
      JUMPOUT(0x99A69);
    }
  }
}
// 99956: control flows out of bounds to 99A69
// 179B89: using guessed type _UNKNOWN *off_179B89;
// 1822B8: using guessed type int16_t word_1822B8[];
// 182306: using guessed type int16_t word_182306;
// 182308: using guessed type int16_t word_182308;
// 18230A: using guessed type int16_t word_18230A;
// 18230C: using guessed type int16_t word_18230C;
// 18230E: using guessed type void (__noreturn *off_18230E)();
// 1975C4: using guessed type int dword_1975C4;
// 199F09: using guessed type char byte_199F09;
// 19C598: using guessed type int dword_19C598;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5E9: using guessed type char byte_19C5E9;
// 19C5EA: using guessed type char byte_19C5EA;


//----- (00099981) --------------------------------------------------------
unsigned int sub_99981()
{
  unsigned int result; // eax

  result = sub_115478(418, 37, 0, 407, 0, 407, 15, 407, dword_1975C4, &unk_179B78, 0);
  word_19C5AE = result;
  return result;
}
// 1975C4: using guessed type int dword_1975C4;
// 19C5AE: using guessed type int16_t word_19C5AE;


//----- (000999BF) --------------------------------------------------------
int __fastcall sub_999BF(int a1)
{
  int v2; // esi
  int result; // eax
  int16_t i; // si
  int16_t v5; // dx
  int v6; // [esp+4h] [ebp-18h] BYREF
  int v7; // [esp+8h] [ebp-14h] BYREF
  int v8; // [esp+Ch] [ebp-10h]
  int v9; // [esp+10h] [ebp-Ch]
  int v10; // [esp+14h] [ebp-8h]
  int v11; // [esp+18h] [ebp-4h]

  v9 = 0;
  v10 = 0;
  v8 = 0;
  v11 = 5;
  v2 = 0;
  do
  {
    result = (int16_t)v2++;
    *(_WORD *)(a1 + 2 * result) = -1000;
  }
  while ( (int16_t)v2 < 72 );
  for ( i = 0; i < word_19999A; ++i )
  {
    sub_911D5(i, 443, 17, 180, 116, v9, v10, v8, &v6, &v7);
    v5 = sub_11438B(v6, v7, v11 + v6, v11 + v7, &unk_179B78, 41);
    result = i;
    *(_WORD *)(a1 + 2 * result) = v5;
  }
  return result;
}
// 19999A: using guessed type int16_t word_19999A;


//----- (00099A6F) --------------------------------------------------------
int sub_99A6F()
{
  dword_19C5A0 = (int)sub_110D3C(dword_192ED4, 10080);
  memset(dword_19C5A0, -1, 10080);
  dword_19C598 = (int)sub_110D3C(dword_192ED4, 277);
  memset(dword_19C598, 0, 277);
  dword_19C5A4 = (int)sub_110D3C(dword_192ED4, 4000);
  memset(dword_19C5A4, -1, 4000);
  dword_1975C4 = (int)sub_110D3C(dword_192ED4, 29);
  return memset(dword_1975C4, 0, 29);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 1975C4: using guessed type int dword_1975C4;
// 19C598: using guessed type int dword_19C598;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5A4: using guessed type int dword_19C5A4;


//----- (00099AFA) --------------------------------------------------------
void sub_99AFA()
{
  int16_t v0; // si
  int16_t v1; // cx
  int16_t v2; // ax
  int16_t v3; // bx
  int16_t v4; // di
  int v5; // eax
  int v6; // edx
  _BOOL1 v7; // al
  int16_t v8; // ax
  int v10; // eax
  int v11; // edx
  _BOOL1 v12; // al
  int16_t v13; // ax
  int16_t v15; // [esp+4h] [ebp-1Ch]
  _BOOL1 v16; // [esp+Ch] [ebp-14h]
  _BOOL1 v17; // [esp+10h] [ebp-10h]
  _BOOL1 v18; // [esp+14h] [ebp-Ch]
  _BOOL1 v19; // [esp+18h] [ebp-8h]
  _BOOL1 v20; // [esp+1Ch] [ebp-4h]

  word_19C5B0 = 0;
  memset(dword_19C5A4, -1, 4000);
  v0 = 0;
  memset(byte_19C54C, 0, sizeof(byte_19C54C));
  byte_19C5EA = 0;
  byte_19C5E9 = 0;
  while ( v0 < word_199A02 )
  {
    v1 = word_192248[v0];
    if ( sub_7843D(word_19999C, dword_197F9C + 129 * *(int16_t *)((char *)&word_1975D4 + 5 * v1)) && v1 != -1 )
    {
      v20 = 0;
      while ( !v20 )
      {
        sub_78800(v1);
        *(_WORD *)(dword_19C5A4 + 8 * word_19C5B0 + 4) = v2;
        v3 = *(int16_t *)((char *)&word_1975D4 + 5 * v1);
        v4 = sub_77FF5(v3);
        v5 = 129 * v3 + dword_197F9C;
        v15 = *(char *)(v5 + 100);
        if ( *(_BYTE *)(v5 + 17) == 1 && v4 == word_19999C && *(char *)(v5 + 100) < 3 )
        {
          *(_WORD *)(dword_19C5A4 + 8 * word_19C5B0) = v3;
          v6 = v5;
          v7 = *(int16_t *)(v5 + 101) > -1 && *(int16_t *)(v5 + 101) < 500;
          v18 = v7;
          v16 = *(int16_t *)(v6 + 101) >= 1000 && *(int16_t *)(v6 + 101) < 1500;
          v8 = sub_9952D(v6);
          if ( v18 || v16 && v8 == -1 )
          {
            byte_19C5EA = 1;
            sub_9B7F1(word_19C5B0, v3);
            *(_BYTE *)(8 * word_19C5B0 + dword_19C5A4 + 6) = 1;
          }
          else
          {
            *(_BYTE *)(dword_19C5A4 + 8 * word_19C5B0 + 6) = 0;
          }
        }
        else
        {
          v10 = 129 * v3 + dword_197F9C;
          if ( *(_BYTE *)(v10 + 17) == 4 && v4 == word_19999C && v15 < 3 )
          {
            *(_WORD *)(dword_19C5A4 + 8 * word_19C5B0 + 2) = v3;
            v11 = v10;
            v12 = *(int16_t *)(v10 + 101) > -1 && *(int16_t *)(v10 + 101) < 500;
            v19 = v12;
            v17 = *(int16_t *)(v11 + 101) >= 1000 && *(int16_t *)(v11 + 101) < 1500;
            v13 = sub_9952D(v11);
            if ( v19 || v17 && v13 == -1 )
            {
              byte_19C5E9 = 1;
              sub_9B998(word_19C5B0, v3);
              *(_BYTE *)(8 * word_19C5B0 + dword_19C5A4 + 7) = 1;
            }
            else
            {
              *(_BYTE *)(8 * word_19C5B0 + dword_19C5A4 + 7) = 0;
            }
          }
        }
        ++word_19C5B0;
        if ( byte_19C5EA && byte_19C5E9 )
          v20 = 1;
        if ( !v20 )
        {
          v1 = *(int16_t *)((char *)&word_1975D6 + 5 * v1);
          v20 = v1 == -1;
        }
      }
    }
    ++v0;
  }
  sub_9CFA8();
  JUMPOUT(0x99A68);
}
// 99E02: control flows out of bounds to 99A68
// 99BBE: variable 'v2' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 199A02: using guessed type int16_t word_199A02;
// 19C5A4: using guessed type int dword_19C5A4;
// 19C5B0: using guessed type int16_t word_19C5B0;
// 19C5E9: using guessed type char byte_19C5E9;
// 19C5EA: using guessed type char byte_19C5EA;


//----- (00099E07) --------------------------------------------------------
void sub_99E07()
{
  char v0; // ch
  int16_t i; // bx
  _BOOL1 v2; // cl
  int16_t v3; // si
  int v4; // edi
  char v5; // dl
  int v6; // eax
  int v7; // eax
  int16_t v8; // [esp+0h] [ebp-8h]

  v0 = 0;
  for ( i = 0; i < word_199A02 && !v0; ++i )
  {
    v2 = 0;
    v3 = word_192248[i];
    while ( !v2 )
    {
      v4 = 129 * *(int16_t *)((char *)&word_1975D4 + 5 * v3);
      v8 = *(int16_t *)((char *)&word_1975D4 + 5 * v3);
      v5 = sub_7843D(word_19999C, v4 + dword_197F9C);
      v6 = v4 + dword_197F9C;
      if ( *(_BYTE *)(v4 + dword_197F9C + 17) == 1 && v5 && *(_BYTE *)(v6 + 100) != 1 && sub_9BB95((_WORD *)v6) )
      {
        byte_19C5E0 = 1;
        byte_19C5EA = 1;
      }
      v7 = dword_197F9C + 129 * v8;
      if ( *(_BYTE *)(v7 + 17) == 4 && v5 && *(_BYTE *)(v7 + 100) != 1 && sub_9BB95((_WORD *)v7) )
      {
        byte_19C5E2 = 1;
        byte_19C5EA = 1;
      }
      if ( byte_19C5EA && byte_19C5E9 )
      {
        v2 = 1;
        v0 = 1;
      }
      if ( !v2 )
      {
        v3 = *(int16_t *)((char *)&word_1975D6 + 5 * v3);
        v2 = v3 == -1;
      }
    }
  }
  JUMPOUT(0x99A68);
}
// 99F1D: control flows out of bounds to 99A68
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 199A02: using guessed type int16_t word_199A02;
// 19C5E0: using guessed type char byte_19C5E0;
// 19C5E2: using guessed type char byte_19C5E2;
// 19C5E9: using guessed type char byte_19C5E9;
// 19C5EA: using guessed type char byte_19C5EA;


//----- (00099F38) --------------------------------------------------------
char __fastcall sub_99F38(char *a1, _BYTE *a2, unsigned int a3, _BYTE *a4)
{
  char *v4; // edi
  int16_t v5; // dx
  char v6; // bl
  int16_t v7; // ax
  int16_t v8; // bx
  int16_t v9; // dx

  if ( (int16_t)a1 == -1 )
  {
    if ( a3 )
    {
      if ( a3 <= 1u )
      {
        byte_199F34 = 66;
        v8 = 255;
        goto LABEL_15;
      }
      if ( a3 == 2 )
      {
        byte_199F34 = 64;
        v8 = 138;
        v9 = 0;
        goto LABEL_18;
      }
    }
    byte_199F34 = 67;
    v8 = 65;
LABEL_15:
    v9 = 64;
LABEL_18:
    qmemcpy(a2, sub_8E5C5(4u, v9, v8), 8u);
    LOBYTE(a1) = a2[1];
    *a4 = (_BYTE)a1;
    return (char)a1;
  }
  LOBYTE(a1) = 6 * *(_BYTE *)(dword_197F98 + 3753 * (int16_t)a1 + 38) - 49;
  *a4 = (_BYTE)a1;
  if ( a3 )
  {
    if ( a3 <= 1u )
    {
      byte_199F34 = (_BYTE)a1 + 3;
      v4 = a2;
      v7 = (uint8_t)*a4 + 5;
    }
    else
    {
      if ( a3 != 2 )
        return (char)a1;
      byte_199F34 = (_BYTE)a1 + 1;
      v4 = a2;
      v7 = (uint8_t)*a4 + 3;
    }
    v5 = (uint8_t)*a4;
  }
  else
  {
    v4 = a2;
    v5 = (uint8_t)*a4;
    v6 = (_BYTE)a1 + 2;
    v7 = (uint8_t)a1 + 4;
    byte_199F34 = v6;
  }
  a1 = sub_8E5C5(4u, v5, v7);
  qmemcpy(v4, a1, 8u);
  return (char)a1;
}
// 197F98: using guessed type int dword_197F98;
// 199F34: using guessed type char byte_199F34;


//----- (0009A04B) --------------------------------------------------------
char __fastcall sub_9A04B(char *a1, _BYTE *a2, unsigned int a3)
{
  _BYTE v4[4]; // [esp+0h] [ebp-4h] BYREF

  a1 = (char *)(int16_t)a1;
  if ( (int16_t)a1 != -1 )
    a1 = (char *)*(char *)(361 * (int16_t)a1 + dword_192B18);
  return sub_99F38(a1, a2, a3, v4);
}
// 192B18: using guessed type int dword_192B18;


//----- (0009A07B) --------------------------------------------------------
char sub_9A07B()
{
  int16_t v0; // ax

  sub_99AFA();
  LOBYTE(v0) = dword_1975C4;
  byte_19C5E0 = 0;
  byte_19C5E2 = 0;
  if ( *(int16_t *)(dword_1975C4 + 8) > 0 )
  {
    v0 = sub_233FA();
    if ( !v0 )
    {
      if ( byte_19C5E9 && sub_9B281() )
      {
        word_19C5AC = 0;
        LOBYTE(v0) = byte_19C5E9;
        byte_19C5E0 = 2;
        if ( byte_19C5E9 )
          byte_19C5E2 = 1;
      }
      else if ( !byte_19C5EA || (LOBYTE(v0) = sub_9B7EB(), (_BYTE)v0) )
      {
        LOBYTE(v0) = byte_19C5EA;
        if ( !byte_19C5EA )
        {
          LOBYTE(v0) = sub_9B7EB();
          if ( (_BYTE)v0 )
          {
            word_19C5AC = 1;
            byte_19C5E2 = 2;
          }
        }
      }
      else
      {
        word_19C5AC = 0;
        byte_19C5E0 = 2;
      }
    }
  }
  return v0;
}
// 1975C4: using guessed type int dword_1975C4;
// 19C5AC: using guessed type int16_t word_19C5AC;
// 19C5E0: using guessed type char byte_19C5E0;
// 19C5E2: using guessed type char byte_19C5E2;
// 19C5E9: using guessed type char byte_19C5E9;
// 19C5EA: using guessed type char byte_19C5EA;


//----- (0009A125) --------------------------------------------------------
void sub_9A125()
{
  int v0; // ebx
  int16_t v1; // ax
  int16_t i; // si
  int v3; // eax
  int16_t *v4; // ebx
  int v5; // eax
  int16_t v6; // [esp+4h] [ebp-4h]

  v0 = *(int16_t *)(dword_1975C4 + 12);
  v1 = v0 + 8;
  if ( v0 + 8 > v0 + *(int16_t *)(dword_1975C4 + 8) )
    v1 = v0 + *(_WORD *)(dword_1975C4 + 8);
  v6 = v1;
  for ( i = 0; ; ++i )
  {
    v5 = *(int16_t *)(dword_1975C4 + 12);
    if ( i >= v6 - v5 )
      break;
    v3 = *(int16_t *)(dword_19C5A0 + 28 * (i + v5) + 10);
    if ( v3 != -1 )
    {
      v4 = *(int16_t **)(dword_19C594
                       + 4
                       * (int16_t)(*(uint8_t *)(17 * v3 + dword_1930D4 + 5)
                                 + 5 * *(uint8_t *)(17 * v3 + dword_1930D4 + 8)));
      sub_12A478((86 - *v4) / 2 + 18, word_1822B8[i] + 45 + (25 - v4[1]) / 2, (int)v4);
    }
  }
  JUMPOUT(0x99A68);
}
// 9A1EB: control flows out of bounds to 99A68
// 1822B8: using guessed type int16_t word_1822B8[];
// 1930D4: using guessed type int dword_1930D4;
// 1975C4: using guessed type int dword_1975C4;
// 19C594: using guessed type int dword_19C594;
// 19C5A0: using guessed type int dword_19C5A0;


//----- (0009A1F0) --------------------------------------------------------
void sub_9A1F0()
{
  int16_t v0; // di
  int16_t v1; // si
  int v2; // [esp+4h] [ebp-8h]
  int16_t v3; // [esp+8h] [ebp-4h]

  sub_128AB6(421, 37, 431, 444);
  sub_12B634();
  v0 = 150;
  v3 = 423;
  v2 = *(int16_t *)(dword_1975C4 + 14) - (*(int16_t *)(dword_1975C4 + 6) / 2 + *(int16_t *)dword_1975C4);
  v1 = 0;
  while ( 1 )
  {
    sub_134D2D(v3, (int16_t)(v2 + 38), v3, (int16_t)(*(_WORD *)(dword_1975C4 + 6) + 37 + v2), v0);
    if ( !(v1 % 2) )
      --v0;
    ++v1;
    ++v3;
    if ( v1 >= 10 )
    {
      sub_12B65C();
      sub_128BE7();
      sub_12A478(421, 37, *(_DWORD *)(dword_19C598 + 48));
      byte_19C5E7 = 0;
      JUMPOUT(0x99A68);
    }
  }
}
// 9A2B5: control flows out of bounds to 99A68
// 1975C4: using guessed type int dword_1975C4;
// 19C598: using guessed type int dword_19C598;
// 19C5E7: using guessed type char byte_19C5E7;


//----- (0009A2BA) --------------------------------------------------------
void __fastcall sub_9A2BA(int16_t *a1)
{
  int v2; // ebx
  int16_t v3; // si
  int v4; // edx
  int16_t *v5; // edi
  int v6; // eax
  int v7; // ebx
  int16_t v8; // ax
  int v9; // eax
  int v10; // edx
  int v11; // [esp+4h] [ebp-8h]
  int16_t v12; // [esp+8h] [ebp-4h]

  v12 = *a1;
  v2 = 10080;
  sub_1112EC(dword_192ED4, 10080);
  v3 = 0;
  v4 = -1;
  v5 = (int16_t *)sub_110D3C(dword_192ED4, 10080);
  v6 = memset(v5, -1, 10080);
  *a1 = 0;
  while ( v3 < word_1999A2 )
  {
    sub_FE8BE(v6, v4, v2, v5);
    v4 = dword_1930D4;
    v6 = dword_1930D4 + 17 * v3;
    LOBYTE(v2) = *(_BYTE *)(v6 + 4) == 3;
    if ( *(_BYTE *)(v6 + 4) == 3 )
    {
      LOBYTE(v6) = sub_9A9F8(v3);
      if ( (_BYTE)v6 )
        LOBYTE(v2) = 0;
    }
    if ( (_BYTE)v2 )
    {
      LOBYTE(v6) = sub_9AC0D(v3);
      if ( (_BYTE)v6 )
        LOBYTE(v2) = 0;
    }
    if ( (_BYTE)v2 )
    {
      LOBYTE(v6) = sub_9A9AC(v3);
      if ( !(_BYTE)v6 )
        LOBYTE(v2) = 0;
    }
    if ( !(_BYTE)v2 )
      goto LABEL_31;
    v4 = v3;
    v6 = sub_1276F0((int)&byte_19C5B2, v3);
    if ( !(_WORD)v6 )
      goto LABEL_31;
    if ( HIWORD(off_18230E) )
    {
      LOBYTE(v6) = sub_9AAC1(v3);
      if ( !(_BYTE)v6 )
        LOBYTE(v2) = 0;
    }
    if ( (_BYTE)v2 )
    {
      if ( word_182308 )
      {
        v4 = word_19999C;
        LOBYTE(v6) = sub_9A98A(v3, word_19999C);
        if ( (_BYTE)v6 )
          LOBYTE(v2) = 0;
      }
    }
    if ( (_BYTE)v2 )
    {
      if ( (_WORD)off_18230E )
      {
        v4 = word_19999C;
        LOBYTE(v6) = sub_9AAED(v3);
        if ( (_BYTE)v6 )
          LOBYTE(v2) = 0;
      }
    }
    if ( (_BYTE)v2 )
    {
      if ( word_18230A )
      {
        LOBYTE(v6) = sub_9A9E2(v3);
        if ( (_BYTE)v6 )
          LOBYTE(v2) = 0;
      }
    }
    if ( (_BYTE)v2 )
    {
      if ( word_18230C )
      {
        v6 = v3;
        LOBYTE(v6) = sub_9ABEC(v3);
        if ( (_BYTE)v6 )
LABEL_31:
          LOBYTE(v2) = 0;
      }
    }
    if ( (_BYTE)v2 )
    {
      v7 = 17 * v3;
      sub_E0B4F((int16_t *)(v7 + dword_1930D4), word_19999C);
      v5[14 * *a1] = v8;
      v9 = v7 + dword_1930D4;
      v5[14 * *a1 + 1] = *(uint8_t *)(v7 + dword_1930D4 + 11);
      v10 = 28 * *a1;
      *(int16_t *)((char *)v5 + v10 + 4) = (uint8_t)byte_DD4B5[*(uint8_t *)(v9 + 10)];
      LOWORD(v10) = *(uint8_t *)(v9 + 8);
      v11 = v10;
      v4 = 28 * *a1;
      v2 = v11;
      *(int16_t *)((char *)v5 + v4 + 8) = v11;
      LOWORD(v4) = *(uint8_t *)(v9 + 10);
      v5[14 * *a1 + 3] = v4;
      v6 = 28 * *a1;
      *(int16_t *)((char *)v5 + v6 + 10) = v3;
      ++*a1;
    }
    ++v3;
  }
  if ( v12 != *a1 )
  {
    qmemcpy((void *)dword_19C5A0, v5, 0x2760u);
    sub_9BBED();
    word_1999BC = -1;
  }
  sub_1113CC(dword_192ED4, v4);
  JUMPOUT(0x99A68);
}
// 9A4EC: control flows out of bounds to 99A68
// 9A379: conditional instruction was optimized away because bl.1==1
// 9A301: variable 'v6' is possibly undefined
// 9A43A: variable 'v8' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 182308: using guessed type int16_t word_182308;
// 18230A: using guessed type int16_t word_18230A;
// 18230C: using guessed type int16_t word_18230C;
// 18230E: using guessed type void (__noreturn *off_18230E)();
// 192ED4: using guessed type int dword_192ED4;
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;
// 1999A2: using guessed type int16_t word_1999A2;
// 1999BC: using guessed type int16_t word_1999BC;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5B2: using guessed type char byte_19C5B2;


//----- (0009A4F1) --------------------------------------------------------
_WORD *__fastcall sub_9A4F1( int a1, _WORD *a2, _WORD *a3)
{
  int16_t *v5; // eax
  int16_t v6; // ax
  int16_t v7; // ax
  _BOOL1 v8; // dl
  _BOOL1 v9; // dh
  _WORD *result; // eax
  int16_t v12; // [esp+4h] [ebp-8h]

  v5 = (int16_t *)(8 * a1 + dword_19C5A4);
  if ( *v5 >= v5[1] )
    v6 = *v5;
  else
    v6 = v5[1];
  v12 = v6;
  v7 = *(_WORD *)(129 * v6 + dword_197F9C + 101);
  v8 = v7 >= 1000 && v7 < 1500;
  v9 = v8;
  if ( v7 >= 500 && v7 < 1000 )
  {
    result = sub_91151(*(_WORD *)(dword_19C5A4 + 8 * a1 + 4), 443, 17, 180, 116, a2, a3);
  }
  else
  {
    if ( v9 )
      v7 = sub_7A3E3(*(_WORD *)(dword_197F9C + 129 * v12 + 103), *(_WORD *)(dword_197F9C + 129 * v12 + 105));
    result = (_WORD *)sub_911D5(v7, 443, 17, 180, 116, 0, 0, 2, a2, a3);
  }
  *a2 += 2;
  return result;
}
// 197F9C: using guessed type int dword_197F9C;
// 19C5A4: using guessed type int dword_19C5A4;


//----- (0009A5E8) --------------------------------------------------------
int __fastcall sub_9A5E8( int a1)
{
  int16_t v1; // si
  int v2; // ecx
  int16_t i; // dx
  int16_t *v4; // eax

  v1 = -1;
  v2 = 0;
  for ( i = 0; i < *(int16_t *)(dword_1975C4 + 8) && v1 == -1; ++i )
  {
    v4 = (int16_t *)(28 * i + dword_19C5A0);
    if ( *(uint8_t *)(17 * v4[5] + dword_1930D4 + 2) == a1 )
    {
      if ( v4[8] >= v4[9] )
        v1 = v4[8];
      else
        v1 = v4[9];
    }
  }
  if ( v1 != -1 )
    return sub_79BEB(v1, a1);
  return v2;
}
// 1930D4: using guessed type int dword_1930D4;
// 1975C4: using guessed type int dword_1975C4;
// 19C5A0: using guessed type int dword_19C5A0;


//----- (0009A66B) --------------------------------------------------------
_DWORD *__fastcall sub_9A66B( int a1)
{
  int16_t v1; // dx
  _DWORD *v2; // edx

  v1 = a1 + 26;
  sub_111499(dword_192ED4);
  v2 = sub_126B42((int)off_1822FA, v1, dword_192ED4);
  sub_111499(dword_192ED4);
  return v2;
}
// 1822FA: using guessed type char *off_1822FA;
// 192ED4: using guessed type int dword_192ED4;


//----- (0009A6A0) --------------------------------------------------------
void __usercall sub_9A6A0(int16_t *a1)
{
  int v1; // edx
  int v2; // ebx
  _DWORD *v3; // ecx
  int v4; // eax

  v1 = 0;
  do
  {
    v2 = (int16_t)v1;
    v3 = sub_9A66B(v1);
    v4 = dword_19C594;
    ++v1;
    *(_DWORD *)(dword_19C594 + 4 * v2) = v3;
    sub_FE8BE(v4, v1, v2, a1);
  }
  while ( (int16_t)v1 < 50 );
}
// 19C594: using guessed type int dword_19C594;


//----- (0009A6C9) --------------------------------------------------------
int sub_9A6C9()
{
  _DWORD *v0; // edx
  int result; // eax

  v0 = sub_126B42(
         (int)off_1822FA,
         (int16_t)(*(uint8_t *)(dword_197F98 + 3753 * word_19999C + 38) + 76),
         dword_192ED4);
  result = dword_19C598;
  *(_DWORD *)(dword_19C598 + 52) = v0;
  return result;
}
// 1822FA: using guessed type char *off_1822FA;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19C598: using guessed type int dword_19C598;


//----- (0009A709) --------------------------------------------------------
int __usercall sub_9A709(int16_t *a1)
{
  _DWORD *v1; // eax
  int v2; // ebx
  _DWORD *v3; // eax
  int v4; // ebx
  _DWORD *v5; // eax
  int v6; // ebx
  _DWORD *v7; // edx
  int v8; // eax
  _DWORD *v9; // eax
  int v10; // ebx
  _DWORD *v11; // eax
  int v12; // ebx
  _DWORD *v13; // edx
  int v14; // eax
  _DWORD *v15; // eax
  int v16; // ebx
  _DWORD *v17; // eax
  int v18; // ebx
  int v19; // ebx
  _DWORD *v20; // edx
  int v21; // eax
  int16_t v22; // si
  int16_t v23; // cx
  int v24; // edx
  _DWORD *v25; // eax
  int v26; // ebx
  int v27; // eax

  sub_111499(dword_192ED4);
  v1 = sub_126B42((int)off_1822FA, 0, dword_192ED4);
  v2 = dword_192ED4;
  *(_DWORD *)dword_19C598 = v1;
  v3 = sub_126B42((int)off_1822FA, 1, v2);
  v4 = dword_192ED4;
  *(_DWORD *)(dword_19C598 + 4) = v3;
  v5 = sub_126B42((int)off_1822FA, 2, v4);
  v6 = dword_192ED4;
  *(_DWORD *)(dword_19C598 + 8) = v5;
  v7 = sub_126B42((int)off_1822FA, 3, v6);
  v8 = dword_19C598;
  *(_DWORD *)(dword_19C598 + 12) = v7;
  sub_FE8BE(v8, (int)v7, v6, a1);
  v9 = sub_126B42((int)off_1822FA, 4, dword_192ED4);
  v10 = dword_192ED4;
  *(_DWORD *)(dword_19C598 + 16) = v9;
  *(_DWORD *)(dword_19C598 + 20) = sub_126B42((int)off_1822FA, 5, v10);
  v11 = sub_126B42((int)off_1822FA, 6, dword_192ED4);
  v12 = dword_192ED4;
  *(_DWORD *)(dword_19C598 + 24) = v11;
  v13 = sub_126B42((int)off_1822FA, 7, v12);
  v14 = dword_19C598;
  *(_DWORD *)(dword_19C598 + 28) = v13;
  sub_FE8BE(v14, (int)v13, v12, a1);
  v15 = sub_126B42((int)off_1822FA, 8, dword_192ED4);
  v16 = dword_192ED4;
  *(_DWORD *)(dword_19C598 + 32) = v15;
  dword_1822FE = (int)sub_126B42((int)off_1822FA, 9, v16);
  dword_182302 = (int)sub_126B42((int)off_1822FA, 10, dword_192ED4);
  v17 = sub_126B42((int)off_1822FA, 11, dword_192ED4);
  v18 = dword_192ED4;
  *(_DWORD *)(dword_19C598 + 36) = v17;
  *(_DWORD *)(dword_19C598 + 40) = sub_126B42((int)off_1822FA, 12, v18);
  v19 = dword_192ED4;
  v20 = sub_126B42((int)off_1822FA, 13, dword_192ED4);
  v21 = dword_19C598;
  *(_DWORD *)(dword_19C598 + 48) = v20;
  sub_FE8BE(v21, (int)v20, v19, a1);
  v22 = 15;
  *(_DWORD *)(dword_19C598 + 44) = sub_126B42((int)off_1822FA, 14, dword_192ED4);
  v23 = 0;
  sub_111499(dword_192ED4);
  do
  {
    v24 = v22;
    v25 = sub_126B42((int)off_1822FA, v22++, dword_192ED4);
    v26 = (int)v25;
    v27 = v23++;
    dword_197588[v27] = v26;
    sub_FE8BE(v27, v24, v26, a1);
  }
  while ( v23 < 11 );
  sub_111499(dword_192ED4);
  *(_DWORD *)(dword_19C598 + 52) = sub_126B42(
                                     (int)off_1822FA,
                                     (int16_t)(*(uint8_t *)(3753 * word_19999C + dword_197F98 + 38) + 76),
                                     dword_192ED4);
  sub_1318D4(0, 255);
  sub_13AAC1();
  return sub_111499(dword_192ED4);
}
// 1822FA: using guessed type char *off_1822FA;
// 1822FE: using guessed type int dword_1822FE;
// 182302: using guessed type int dword_182302;
// 192ED4: using guessed type int dword_192ED4;
// 197588: using guessed type int dword_197588[11];
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19C598: using guessed type int dword_19C598;


//----- (0009A98A) --------------------------------------------------------
_BOOL1 __fastcall sub_9A98A( int a1, int a2)
{
  return (int16_t)sub_9AF07(a2, *(uint8_t *)(dword_1930D4 + 17 * a1 + 6)) > 0;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (0009A9AC) --------------------------------------------------------
_BOOL1 __fastcall sub_9A9AC( int a1)
{
  char v1; // dl
  _BOOL1 result; // al

  v1 = sub_79E32(word_19999C, *(uint8_t *)(dword_1930D4 + 17 * a1 + 2));
  result = sub_79E06(word_19999C);
  if ( result || v1 )
    return 1;
  return result;
}
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;


//----- (0009A9E2) --------------------------------------------------------
_BOOL1 __fastcall sub_9A9E2( int a1)
{
  return *(_BYTE *)(17 * a1 + dword_1930D4 + 11) == 0;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (0009A9F8) --------------------------------------------------------
_BOOL1 __fastcall sub_9A9F8( int a1)
{
  int v1; // eax
  int16_t v2; // dx

  v1 = *(int16_t *)(dword_1930D4 + 17 * a1);
  v2 = -1;
  if ( v1 != -1 )
    v2 = *(char *)(361 * v1 + dword_192B18);
  return v2 == word_19999C;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;


//----- (0009AA2E) --------------------------------------------------------
int __fastcall sub_9AA2E( int a1)
{
  int v2; // edx
  int i; // eax

  v2 = -1;
  for ( i = 0; (int16_t)i < *(int16_t *)(dword_1975C4 + 8) && (int16_t)v2 == -1; ++i )
  {
    if ( *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_19C5A0 + 28 * (int16_t)i + 10) + 2) == a1 )
      v2 = i;
  }
  return v2;
}
// 1930D4: using guessed type int dword_1930D4;
// 1975C4: using guessed type int dword_1975C4;
// 19C5A0: using guessed type int dword_19C5A0;


//----- (0009AA83) --------------------------------------------------------
void __fastcall sub_9AA83( int a1)
{
  int16_t v2; // dx
  int16_t i; // ax

  v2 = -1;
  for ( i = 0; i < *(int16_t *)(dword_1975C4 + 8) && v2 == -1; ++i )
  {
    if ( *(_WORD *)(dword_19C5A0 + 28 * i + 10) == a1 )
      v2 = i;
  }
  JUMPOUT(0x9AA7C);
}
// 9AABF: control flows out of bounds to 9AA7C
// 1975C4: using guessed type int dword_1975C4;
// 19C5A0: using guessed type int dword_19C5A0;


//----- (0009AAC1) --------------------------------------------------------
char __fastcall sub_9AAC1( int a1)
{
  return sub_FF68A(dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * a1 + 2), word_19999C);
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;


//----- (0009AAED) --------------------------------------------------------
_BOOL1 __fastcall sub_9AAED( int a1)
{
  _BOOL1 v1; // dl
  int16_t i; // ax
  int v3; // ebx
  int v4; // ebx
  int16_t j; // bx
  char v6; // dh
  int16_t v7; // si
  int v8; // ecx
  int16_t v10; // [esp+0h] [ebp-4h]

  v1 = 0;
  v10 = *(uint8_t *)(dword_1930D4 + 17 * a1 + 2);
  for ( i = 0; i < 5 && !v1; ++i )
  {
    v3 = *(int16_t *)(dword_19306C + 113 * v10 + 2 * i + 74);
    if ( v3 > -1 )
    {
      v4 = *(int16_t *)(17 * v3 + dword_1930D4);
      if ( v4 > -1 )
        v1 = *(char *)(361 * v4 + dword_192B18) != word_19999C;
    }
  }
  if ( !v1 )
  {
    for ( j = 0; j < word_199A02; ++j )
    {
      v6 = 0;
      v7 = word_192248[j];
      while ( !v6 )
      {
        if ( v7 == -1 )
        {
          v6 = 1;
        }
        else
        {
          v8 = *(int16_t *)((char *)&word_1975D4 + 5 * v7);
          if ( *(_WORD *)(dword_197F9C + 129 * v8 + 101) == v10 && sub_77FF5(v8) != word_19999C )
          {
            v6 = 1;
            v1 = 1;
          }
          v7 = *(int16_t *)((char *)&word_1975D6 + 5 * v7);
        }
      }
    }
  }
  return v1;
}
// 192248: using guessed type int16_t word_192248[500];
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 199A02: using guessed type int16_t word_199A02;


//----- (0009ABEC) --------------------------------------------------------
_BOOL1 __fastcall sub_9ABEC( int a1)
{
  return *(_BYTE *)(dword_1930D4 + 17 * a1 + 10) <= 1u;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (0009AC0D) --------------------------------------------------------
char __fastcall sub_9AC0D( int a1)
{
  int v1; // eax

  v1 = *(int16_t *)(dword_1930D4 + 17 * a1);
  if ( v1 <= -1 )
    return 0;
  else
    return *(_BYTE *)(361 * v1 + dword_192B18 + 6);
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;


//----- (0009AC37) --------------------------------------------------------
void __fastcall sub_9AC37( int a1)
{
  int16_t v2; // dx
  int16_t i; // ax

  v2 = -1;
  for ( i = 0; i < *(int16_t *)(dword_1975C4 + 8) && v2 == -1; ++i )
  {
    if ( a1 == *(_WORD *)(28 * i + dword_19C5A0 + 10) )
      v2 = i;
  }
  JUMPOUT(0x9AA7C);
}
// 9AC74: control flows out of bounds to 9AA7C
// 1975C4: using guessed type int dword_1975C4;
// 19C5A0: using guessed type int dword_19C5A0;


//----- (0009AC79) --------------------------------------------------------
char __fastcall sub_9AC79(int a1, int a2, int a3, int a4, int a5)
{
  int16_t v5; // dx
  int16_t v6; // ax
  int v7; // esi
  char result; // al
  int16_t v9; // si
  int v10; // ecx
  int16_t v11; // ax
  int *v12; // edx
  void *v13; // ebx
  int16_t v14; // dx
  int16_t v15; // ax
  int v16; // ecx
  int16_t v17; // ax
  int16_t v18; // bx
  int16_t v19; // cx
  int v20; // edx
  int16_t v21; // ax
  int v22; // edx
  int16_t v23; // ax
  int16_t v25; // [esp+0h] [ebp-2Ch]
  int16_t v27; // [esp+4h] [ebp-28h]
  int v28; // [esp+8h] [ebp-24h] BYREF
  char v29[12]; // [esp+Ch] [ebp-20h] BYREF
  int v30; // [esp+18h] [ebp-14h]
  int v31; // [esp+1Ch] [ebp-10h]
  int v32; // [esp+20h] [ebp-Ch]
  int v33; // [esp+24h] [ebp-8h]
  char v34; // [esp+28h] [ebp-4h]

  v34 = a4;
  v5 = 1;
  v28 = 1127889408;
  strcpy(v29, "BA??");
  do
  {
    v6 = v5 + *(_WORD *)(dword_19C5A0 + 23);
    if ( v6 < 1 )
      v6 = 1;
    if ( v6 > 7 )
      v6 = 7;
    v7 = v5;
    result = v29[v6 - 4];
    ++v5;
    v29[v7 + 4] = result;
  }
  while ( v5 < 8 );
  if ( a5 && v34 )
  {
    v27 = a1 + 3;
    result = word_1999BC;
    v25 = a2 - 1;
    if ( word_1999BC <= -1 || word_1999BC >= 1000 || (uint16_t)word_19C5AC > 1u )
    {
      v13 = &unk_179B8D;
      sub_120BB5(0, (int)&v28);
      v14 = v25;
      v15 = v27;
    }
    else
    {
      if ( word_19C5AC == 1 )
      {
        sub_120BB5(0, (int)&v29[4]);
        v9 = v25;
        v10 = (int16_t)(v25 + sub_122259());
        v11 = sub_12066F((int)&unk_179B8D);
        sub_128C32(v27, v25, (int16_t)(v27 + v11), v10, 1);
        sub_1212B3(v27, v25, (int)&unk_179B90);
        v12 = &v28;
      }
      else
      {
        if ( word_19C5AC )
          return result;
        sub_120BB5(0, (int)&v28);
        v9 = v25;
        v16 = (int16_t)(v25 + sub_122259());
        v17 = sub_12066F((int)&unk_179B8D);
        sub_128C32(v27, v25, (int16_t)(v27 + v17), v16, 1);
        sub_1212B3(v27, v25, (int)&unk_179B90);
        v12 = (int *)&v29[4];
      }
      sub_120BB5(0, (int)v12);
      v13 = &unk_179B92;
      v14 = v9;
      v15 = v27 + sub_12066F((int)&unk_179B90);
    }
  }
  else
  {
    v18 = a2 - 1;
    v19 = a1 + 6;
    if ( a5 )
    {
      v30 = a1 + 6;
      v31 = a2 - 1;
      if ( word_1999BC <= -1 || word_1999BC >= 1000 )
      {
        sub_120BB5(0, (int)&v28);
      }
      else
      {
        sub_120BB5(0, (int)&v29[4]);
        v20 = (int16_t)(v18 + sub_122259());
        v21 = sub_12066F((int)&unk_179B90);
        sub_128C32(v19, v18, (int16_t)(v19 + v21), v20, 1);
      }
      v14 = v31;
      v15 = v30;
      v13 = &unk_179B90;
    }
    else
    {
      if ( !v34 )
        return result;
      v33 = a1 + 6;
      v32 = a2 - 1;
      if ( word_1999BC <= -1 || word_1999BC >= 1000 )
      {
        sub_120BB5(0, (int)&v28);
      }
      else
      {
        sub_120BB5(0, (int)&v29[4]);
        v22 = (int16_t)(v18 + sub_122259());
        v23 = sub_12066F((int)&unk_179B92);
        sub_128C32(v19, v18, (int16_t)(v19 + v23), v22, 1);
      }
      v14 = v32;
      v15 = v33;
      v13 = &unk_179B92;
    }
  }
  return sub_1212B3(v15, v14, (int)v13);
}
// 1999BC: using guessed type int16_t word_1999BC;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5AC: using guessed type int16_t word_19C5AC;


//----- (0009AF07) --------------------------------------------------------
int __fastcall sub_9AF07( int a1, int a2)
{
  int v2; // eax
  char v3; // bl
  char v4; // ah
  _BOOL1 v5; // al

  v2 = 3753 * a1 + dword_197F98;
  v3 = *(_BYTE *)(v2 + 2217);
  v4 = *(_BYTE *)(v2 + 2218);
  v5 = !v3 && !v4;
  if ( v3 && a2 == 2 || v5 && a2 == 2 || v4 && !a2 )
    return 50;
  if ( v3 && a2 == 1 || v5 && !a2 )
    return 25;
  return 0;
}
// 197F98: using guessed type int dword_197F98;


//----- (0009AF72) --------------------------------------------------------
void sub_9AF72()
{
  int16_t v0; // cx
  int16_t i; // ax
  int16_t j; // bx
  int16_t *v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // edx

  if ( word_19C5AC )
    v0 = 4;
  else
    v0 = 1;
  for ( i = 0; i < *(int16_t *)(dword_1975C4 + 8); ++i )
  {
    if ( v0 == 1 )
      *(_WORD *)(28 * i + dword_19C5A0 + 12) = 9999;
    else
      *(_WORD *)(dword_19C5A0 + 28 * i + 14) = 9999;
  }
  for ( j = 0; j < word_19C5B0; ++j )
  {
    if ( v0 == 1 && (v3 = (int16_t *)(dword_19C5A4 + 8 * j), v4 = *v3, v4 > -1) && *v3 < word_199994 )
    {
      sub_9B7F1(j, v4);
    }
    else if ( v0 == 4 )
    {
      v5 = dword_19C5A4 + 8 * j;
      v6 = *(int16_t *)(v5 + 2);
      if ( v6 > -1 && *(int16_t *)(v5 + 2) < word_199994 )
        sub_9B998(j, v6);
    }
  }
}
// 9AFAF: conditional instruction was optimized away because cx.2==4
// 1975C4: using guessed type int dword_1975C4;
// 199994: using guessed type int16_t word_199994;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5A4: using guessed type int dword_19C5A4;
// 19C5AC: using guessed type int16_t word_19C5AC;
// 19C5B0: using guessed type int16_t word_19C5B0;


//----- (0009B04D) --------------------------------------------------------
int __fastcall sub_9B04D( int a1, int a2, _WORD *a3)
{
  int v4; // edx
  int v5; // eax
  int v6; // edx
  int16_t i; // cx
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  _WORD *v11; // eax
  int v12; // edx
  int16_t v13; // ax
  int16_t v14; // ax
  int v15; // eax
  int16_t v16; // dx
  int16_t v17; // ax
  int v18; // eax
  int v19; // eax
  int result; // eax
  int16_t v23[2]; // [esp+Ch] [ebp-18h] BYREF
  int v24; // [esp+10h] [ebp-14h]
  int v25; // [esp+14h] [ebp-10h]
  int v26; // [esp+18h] [ebp-Ch]
  int v27; // [esp+1Ch] [ebp-8h]
  int v28; // [esp+20h] [ebp-4h]

  v4 = *(int16_t *)(dword_1975C4 + 12);
  v5 = v4 + *(int16_t *)(dword_1975C4 + 8);
  v6 = v4 + 8;
  if ( v6 <= v5 )
    v5 = v6;
  byte_19C5E4 = 0;
  byte_19C5E8 = -1;
  v26 = v5;
  for ( i = 0; ; ++i )
  {
    result = *(int16_t *)(dword_1975C4 + 12);
    if ( (int16_t)v26 - result <= i )
      break;
    v25 = i + result;
    HIWORD(v8) = HIWORD(dword_19C5A0);
    LOWORD(v8) = *(_WORD *)(28 * v25 + dword_19C5A0 + 10);
    v9 = (int16_t)v8;
    v27 = v8;
    if ( (int16_t)v8 == -1 )
      continue;
    v10 = 17 * (int16_t)v8 + dword_1930D4;
    LOWORD(v10) = *(uint8_t *)(v10 + 2);
    v28 = v10;
    v24 = 2 * i;
    v11 = (_WORD *)(v24 + dword_19C598);
    if ( a2 == *(_WORD *)(v24 + dword_19C598 + 76) )
    {
      if ( (uint16_t)word_19C5AC <= 1u )
      {
        v12 = (int16_t)v27;
        sub_9AC37(v27);
        if ( sub_9B287(v13) > -1 )
        {
          sub_9B2C7(v12);
LABEL_11:
          sub_9A07B();
          sub_9AF72();
          continue;
        }
      }
    }
    else
    {
      if ( a2 == v11[46] || a2 == v11[54] )
      {
        sub_9CD24();
        goto LABEL_11;
      }
      if ( a1 == v11[38] && *(int16_t *)(dword_1975C4 + 8) > v25 )
      {
        byte_19C5E8 = i;
        if ( v9 > -1 )
        {
          sub_9AC37(v9);
          if ( sub_9B287(v14) != -1 && (uint16_t)word_19C5AC <= 1u )
            byte_19C5E4 = 1;
        }
        if ( a1 != *a3 )
        {
          word_1999BC = v28 + 1000;
          if ( word_19C5AC )
          {
            if ( word_19C5AC == 1 )
            {
              v18 = 28 * (*(int16_t *)(dword_1975C4 + 12) + i) + dword_19C5A0;
              if ( *(int16_t *)(v18 + 18) != -1 )
              {
                v16 = v28;
                v17 = *(_WORD *)(v18 + 18);
LABEL_26:
                v23[0] = v17;
                v23[1] = -1;
                sub_FF799(v23, v16, &byte_1992A8);
                word_1999BC = v28;
              }
            }
          }
          else
          {
            v15 = 28 * (*(int16_t *)(dword_1975C4 + 12) + i) + dword_19C5A0;
            if ( *(int16_t *)(v15 + 16) != -1 )
            {
              v16 = v28;
              v17 = *(_WORD *)(v15 + 16);
              goto LABEL_26;
            }
          }
          *a3 = a1;
          continue;
        }
      }
      else
      {
        v19 = 2 * i + dword_19C598;
        if ( a1 == *(_WORD *)(v19 + 92) || a1 == *(_WORD *)(v19 + 108) )
          byte_19C5E4 = 1;
      }
    }
  }
  return result;
}
// 9B0FB: variable 'v13' is possibly undefined
// 9B16E: variable 'v14' is possibly undefined
// 1930D4: using guessed type int dword_1930D4;
// 1975C4: using guessed type int dword_1975C4;
// 1992A8: using guessed type char byte_1992A8;
// 1999BC: using guessed type int16_t word_1999BC;
// 19C598: using guessed type int dword_19C598;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5AC: using guessed type int16_t word_19C5AC;
// 19C5E4: using guessed type char byte_19C5E4;
// 19C5E8: using guessed type char byte_19C5E8;


//----- (0009B281) --------------------------------------------------------
char sub_9B281()
{
  return byte_19C5EA;
}
// 19C5EA: using guessed type char byte_19C5EA;


//----- (0009B287) --------------------------------------------------------
int16_t __fastcall sub_9B287( int a1)
{
  int16_t result; // ax

  result = -1;
  if ( !word_19C5AC )
    return *(_WORD *)(28 * a1 + dword_19C5A0 + 16);
  if ( word_19C5AC == 1 )
    return *(_WORD *)(28 * a1 + dword_19C5A0 + 18);
  return result;
}
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5AC: using guessed type int16_t word_19C5AC;


//----- (0009B2C7) --------------------------------------------------------
void __fastcall sub_9B2C7(int a1)
{
  int v2; // eax
  int v3; // ebx
  int v4; // ecx
  int16_t v5; // ax
  int16_t v6; // bx
  int v7; // edx
  int v8; // eax
  int16_t v9; // ax
  int16_t v10; // cx
  int16_t v11; // di
  char *v12; // eax
  char v13; // al
  char v14; // al
  char *v15; // eax
  char *v16; // eax
  uint16_t v17; // ax
  char *v18; // eax
  char *v19; // eax
  char v20; // al
  int16_t v21; // cx
  int v22; // edi
  char v23; // bl
  char v24; // al
  uint16_t v25; // ax
  char *v26; // eax
  char v27; // al
  int v28; // edi
  int v29; // eax
  uint16_t v30; // ax
  char *v31; // eax
  int v32; // edx
  int v33; // eax
  char *v34; // eax
  int v35; // [esp-Ch] [ebp-56h]
  int v36; // [esp-Ch] [ebp-56h]
  int v37; // [esp-8h] [ebp-52h]
  int v38; // [esp-8h] [ebp-52h]
  int v39; // [esp-8h] [ebp-52h]
  int v40; // [esp-8h] [ebp-52h]
  int v41; // [esp-8h] [ebp-52h]
  int v42; // [esp-4h] [ebp-4Eh]
  int v43; // [esp-4h] [ebp-4Eh]
  int v44; // [esp-4h] [ebp-4Eh]
  int v45; // [esp-4h] [ebp-4Eh]
  int v46; // [esp-4h] [ebp-4Eh]
  int v47; // [esp-4h] [ebp-4Eh]
  _BYTE v48[120]; // [esp+0h] [ebp-4Ah] BYREF
  char v49[20]; // [esp+78h] [ebp+2Eh] BYREF
  _BYTE v50[4]; // [esp+8Ch] [ebp+42h] BYREF
  uint8_t v51; // [esp+90h] [ebp+46h]
  char v52; // [esp+91h] [ebp+47h]
  char v53; // [esp+99h] [ebp+4Fh]
  int v54; // [esp+9Ch] [ebp+52h] BYREF
  int v55; // [esp+A0h] [ebp+56h]
  int v56; // [esp+A4h] [ebp+5Ah]
  int v57; // [esp+A8h] [ebp+5Eh]
  int v58; // [esp+ACh] [ebp+62h]
  int v59; // [esp+B0h] [ebp+66h]
  int16_t v60; // [esp+B4h] [ebp+6Ah] BYREF
  int v61; // [esp+B8h] [ebp+6Eh]
  char v62; // [esp+BCh] [ebp+72h]
  _BOOL1 v63; // [esp+C0h] [ebp+76h]
  char v64; // [esp+C4h] [ebp+7Ah]
  char v65; // [esp+C8h] [ebp+7Eh]

  v54 = -1;
  v2 = 17 * (int16_t)a1;
  v64 = 1;
  v3 = -1;
  LOWORD(v2) = *(uint8_t *)(dword_1930D4 + v2 + 2);
  v58 = a1;
  v61 = v2;
  v4 = 0;
  v63 = sub_79E06(word_19999C);
  while ( (int16_t)v4 < *(int16_t *)(dword_1975C4 + 8) && (int16_t)v3 == -1 )
  {
    if ( *(_WORD *)(dword_19C5A0 + 28 * (int16_t)v4 + 10) == (_WORD)v58 )
      v3 = v4;
    ++v4;
  }
  v5 = -1;
  v59 = v3;
  if ( word_19C5AC )
  {
    if ( word_19C5AC == 1 )
      v5 = *(_WORD *)(dword_19C5A0 + 28 * (int16_t)v3 + 18);
  }
  else
  {
    v5 = *(_WORD *)(dword_19C5A0 + 28 * (int16_t)v3 + 16);
  }
  v6 = v5;
  HIWORD(v7) = HIWORD(dword_197F9C);
  v8 = dword_197F9C + 129 * v5;
  LOWORD(v7) = *(uint8_t *)(v8 + 17);
  v57 = v7;
  v9 = sub_78E07(*(int16_t *)(v8 + 101));
  v10 = *(uint8_t *)(dword_1930D4 + 17 * (int16_t)a1 + 2);
  v11 = v9;
  if ( v9 != v10 && (_WORD)v57 == 1 && *(char *)(dword_19C5A0 + 28 * (int16_t)v59 + 26) > 0
    || (_WORD)v57 == 4 && *(char *)(dword_19C5A0 + 28 * (int16_t)v59 + 27) > 0 )
  {
    v42 = dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * (int16_t)a1 + 2);
    v12 = sub_7A990(0x134u);
    sprintf(v48, v12, v42);
    sub_123E6C((int)&unk_17CF00, 1);
    sub_77658((int)v48);
    v64 = v13;
    *(_BYTE *)(dword_19C598 + 274) = 1;
    if ( !v13 )
      goto LABEL_56;
  }
  if ( v6 <= -1 || (v55 = 129 * v6, *(int16_t *)(v55 + dword_197F9C + 101) < 500) )
  {
    if ( v6 == -1 )
      v64 = 0;
    goto LABEL_38;
  }
  v65 = sub_79E32(word_19999C, v11);
  v62 = v65;
  v56 = v10;
  v14 = sub_79E32(word_19999C, v10);
  if ( v11 == v10 )
  {
    v43 = dword_19306C + 113 * v56;
    v37 = v55 + dword_197F9C;
    v15 = sub_7A990(0x138u);
    sprintf(v48, v15, v37, v43);
    sub_77423((int)v48);
LABEL_55:
    *(_BYTE *)(dword_19C598 + 274) = 1;
    goto LABEL_56;
  }
  if ( v63 || v14 && v65 )
  {
    v44 = dword_19306C + 113 * v10;
    v38 = 113 * v11 + dword_19306C;
    v35 = dword_197F9C + 129 * v6;
    v16 = sub_7A990(0x139u);
    sprintf(v48, v16, v35, v38, v44);
  }
  else
  {
    if ( !v14 || v62 )
    {
      if ( v14 || !v62 )
      {
        if ( !v14 && !v62 )
        {
          v46 = dword_197F9C + 129 * v6;
          v19 = sub_7A990(0x13Au);
          sprintf(v48, v19, v46);
        }
        goto LABEL_35;
      }
      v45 = dword_19306C + 113 * v11;
      v39 = dword_197F9C + 129 * v6;
      v17 = 313;
    }
    else
    {
      v45 = dword_19306C + 113 * v10;
      v39 = dword_197F9C + 129 * v6;
      v17 = 314;
    }
    v18 = sub_7A990(v17);
    sprintf(v48, v18, v39, v45);
  }
LABEL_35:
  sub_123E6C((int)&unk_17CF00, 1);
  sub_77658((int)v48);
  v64 = v20;
  *(_BYTE *)(dword_19C598 + 274) = 1;
LABEL_38:
  if ( !v64 )
    goto LABEL_56;
  if ( word_19C5AC == 1 )
    v21 = *(_WORD *)(dword_19C5A0 + 28 * (int16_t)v59 + 18);
  else
    v21 = *(_WORD *)(dword_19C5A0 + 28 * (int16_t)v59 + 16);
  HIWORD(v54) = -1;
  v22 = (int16_t)v61;
  LOWORD(v54) = v21;
  sub_FF799((int16_t *)&v54, v61, v50);
  if ( !v52 )
  {
    if ( !v53 )
      goto LABEL_56;
    v34 = sub_7A990(0x13Fu);
    sub_77433(v34);
    goto LABEL_55;
  }
  v23 = 1;
  sub_7A47A(v22, &v60);
  if ( v24 )
  {
    sub_784A0(v60, v49);
    sub_123E6C((int)&unk_17CF00, 1);
    v40 = dword_19306C + 113 * v22;
    if ( word_19C5AC )
      v25 = 315;
    else
      v25 = 316;
    v26 = sub_7A990(v25);
    sprintf(v48, v26, v40, v49);
    sub_77658((int)v48);
    v23 = v27;
  }
  if ( v23 )
  {
    v28 = (int16_t)v61;
    sub_FFD08((int16_t *)&v54, v61, v50);
    v29 = 113 * v28;
    if ( v51 == 1 )
    {
      v47 = 1;
      v41 = dword_19306C + v29;
      v36 = dword_197F9C + 129 * v21;
      v30 = 317;
    }
    else
    {
      v47 = v51;
      v41 = dword_19306C + v29;
      v36 = 129 * v21 + dword_197F9C;
      v30 = 318;
    }
    v31 = sub_7A990(v30);
    sprintf(v48, v31, v36, v41, v47);
    v32 = 129 * v21;
    sub_77423((int)v48);
    word_19C5AA = v21;
    *(_BYTE *)(dword_19C598 + 274) = 1;
    sub_9CFA8();
    v33 = dword_197F9C;
    *(_WORD *)(v32 + dword_197F9C + 36) = 1;
    *(_WORD *)(v32 + v33 + 28) = a1;
  }
LABEL_56:
  JUMPOUT(0x99A69);
}
// 9B7E6: control flows out of bounds to 99A69
// 9B447: variable 'v13' is possibly undefined
// 9B60D: variable 'v20' is possibly undefined
// 9B697: variable 'v24' is possibly undefined
// 9B701: variable 'v27' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1975C4: using guessed type int dword_1975C4;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 19C598: using guessed type int dword_19C598;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5AA: using guessed type int16_t word_19C5AA;
// 19C5AC: using guessed type int16_t word_19C5AC;


//----- (0009B7EB) --------------------------------------------------------
char sub_9B7EB()
{
  return byte_19C5E9;
}
// 19C5E9: using guessed type char byte_19C5E9;


//----- (0009B7F1) --------------------------------------------------------
void __fastcall sub_9B7F1( int a1, int a2)
{
  int16_t v2; // ax
  _BOOL1 v3; // dl
  _BOOL1 v4; // al
  int16_t v5; // si
  int16_t v6; // ax
  int v7; // eax
  int v8; // edi
  int16_t v9; // dx
  int v10; // eax
  int16_t i; // cx
  int v12; // eax
  int j; // eax
  int v14; // eax
  int v15; // eax
  _BYTE v18[16]; // [esp+8h] [ebp-2Ch] BYREF
  int16_t v19[2]; // [esp+18h] [ebp-1Ch] BYREF
  int v20; // [esp+1Ch] [ebp-18h]
  int v21; // [esp+20h] [ebp-14h]
  int v22; // [esp+24h] [ebp-10h]
  int v23; // [esp+28h] [ebp-Ch]
  _BOOL1 v24; // [esp+2Ch] [ebp-8h]
  _BOOL1 v25; // [esp+30h] [ebp-4h]

  v2 = *(_WORD *)(dword_197F9C + 129 * a2 + 101);
  v3 = v2 >= 1000 && v2 < 1500;
  v24 = v3;
  v4 = v2 >= 500 && v2 < 1000;
  v25 = v4;
  v5 = 0;
  v6 = *(_WORD *)(dword_19C5A4 + 8 * a1);
  v19[1] = -1;
  v19[0] = v6;
  while ( 1 )
  {
    sub_9BF1C(v5);
    v8 = (int16_t)v7;
    v23 = v7;
    if ( (int16_t)v7 != -1 )
    {
      sub_FF799(v19, v5, v18);
      if ( v18[5] )
      {
        v9 = v18[4];
        byte_19C54C[v5] = 1;
        if ( v24 )
        {
          v9 += 1000;
        }
        else if ( v25 )
        {
          v9 += 2000;
        }
        v10 = dword_19C5A0 + 28 * (int16_t)v23;
        if ( *(int16_t *)(v10 + 12) == -1 || v9 < *(int16_t *)(v10 + 12) )
        {
          for ( i = 0; i < 5; ++i )
          {
            v12 = 2 * i + 113 * v5 + dword_19306C;
            if ( *(int16_t *)(v12 + 74) > -1 )
            {
              LOWORD(v12) = *(_WORD *)(v12 + 74);
              v22 = -1;
              v21 = v12;
              for ( j = 0; (int16_t)j < *(int16_t *)(dword_1975C4 + 8) && (int16_t)v22 == -1; ++j )
              {
                v20 = 28 * (int16_t)j;
                if ( *(_WORD *)(v20 + dword_19C5A0 + 10) == (_WORD)v21 )
                  v22 = j;
              }
              if ( (int16_t)v22 > -1 )
              {
                v14 = 28 * (int16_t)v22 + dword_19C5A0;
                *(_BYTE *)(v14 + 20) = 0;
                *(_WORD *)(v14 + 12) = v9;
                *(_WORD *)(v14 + 16) = a2;
                *(_WORD *)(v14 + 21) = a1;
              }
            }
          }
        }
      }
      else if ( v18[0] )
      {
        v15 = dword_19C5A0 + 28 * v8;
        if ( *(int16_t *)(v15 + 12) == -1 )
          *(_BYTE *)(v15 + 20) = 1;
      }
    }
    if ( ++v5 >= 72 )
      JUMPOUT(0x9ABE6);
  }
}
// 9B993: control flows out of bounds to 9ABE6
// 9B85D: variable 'v7' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 1975C4: using guessed type int dword_1975C4;
// 197F9C: using guessed type int dword_197F9C;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5A4: using guessed type int dword_19C5A4;


//----- (0009B998) --------------------------------------------------------
void __fastcall sub_9B998( int a1, int a2)
{
  int16_t v2; // ax
  _BOOL1 v3; // dl
  _BOOL1 v4; // al
  int16_t v5; // si
  int16_t v6; // ax
  int v7; // eax
  int v8; // edi
  int16_t v9; // dx
  int v10; // eax
  int16_t i; // cx
  int v12; // eax
  int j; // eax
  int v14; // eax
  int v15; // eax
  _BYTE v18[16]; // [esp+8h] [ebp-2Ch] BYREF
  int16_t v19[2]; // [esp+18h] [ebp-1Ch] BYREF
  int v20; // [esp+1Ch] [ebp-18h]
  int v21; // [esp+20h] [ebp-14h]
  int v22; // [esp+24h] [ebp-10h]
  int v23; // [esp+28h] [ebp-Ch]
  _BOOL1 v24; // [esp+2Ch] [ebp-8h]
  _BOOL1 v25; // [esp+30h] [ebp-4h]

  v2 = *(_WORD *)(dword_197F9C + 129 * a2 + 101);
  v3 = v2 >= 1000 && v2 < 1500;
  v24 = v3;
  v4 = v2 >= 500 && v2 < 1000;
  v25 = v4;
  v5 = 0;
  v6 = *(_WORD *)(dword_19C5A4 + 8 * a1 + 2);
  v19[1] = -1;
  v19[0] = v6;
  while ( 1 )
  {
    sub_9BF1C(v5);
    v8 = (int16_t)v7;
    v23 = v7;
    if ( (int16_t)v7 != -1 )
    {
      sub_FF799(v19, v5, v18);
      if ( v18[5] )
      {
        v9 = v18[4];
        byte_19C54C[v5] = 1;
        if ( v24 )
        {
          v9 += 1000;
        }
        else if ( v25 )
        {
          v9 += 2000;
        }
        v10 = dword_19C5A0 + 28 * (int16_t)v23;
        if ( *(int16_t *)(v10 + 14) == -1 || v9 < *(int16_t *)(v10 + 14) )
        {
          for ( i = 0; i < 5; ++i )
          {
            v12 = 2 * i + 113 * v5 + dword_19306C;
            if ( *(int16_t *)(v12 + 74) > -1 )
            {
              LOWORD(v12) = *(_WORD *)(v12 + 74);
              v22 = -1;
              v21 = v12;
              for ( j = 0; (int16_t)j < *(int16_t *)(dword_1975C4 + 8) && (int16_t)v22 == -1; ++j )
              {
                v20 = 28 * (int16_t)j;
                if ( *(_WORD *)(v20 + dword_19C5A0 + 10) == (_WORD)v21 )
                  v22 = j;
              }
              if ( (int16_t)v22 > -1 )
              {
                v14 = 28 * (int16_t)v22 + dword_19C5A0;
                *(_BYTE *)(v14 + 20) = 0;
                *(_WORD *)(v14 + 14) = v9;
                *(_WORD *)(v14 + 18) = a2;
                *(_WORD *)(v14 + 21) = a1;
              }
            }
          }
        }
      }
      else if ( v18[0] )
      {
        v15 = dword_19C5A0 + 28 * v8;
        if ( *(int16_t *)(v15 + 14) == -1 )
          *(_BYTE *)(v15 + 20) = 1;
      }
    }
    if ( ++v5 >= 72 )
      JUMPOUT(0x9ABE6);
  }
}
// 9BB3B: control flows out of bounds to 9ABE6
// 9BA05: variable 'v7' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 1975C4: using guessed type int dword_1975C4;
// 197F9C: using guessed type int dword_197F9C;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5A4: using guessed type int dword_19C5A4;


//----- (0009BB40) --------------------------------------------------------
char sub_9BB40()
{
  int v0; // ebx
  int v1; // eax
  int16_t i; // bx

  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    byte_19C5B2[v1] = 0;
  }
  while ( (int16_t)v0 < 45 );
  for ( i = 0; i < word_1999A2; ++i )
  {
    LOBYTE(v1) = sub_A44FC(*(uint8_t *)(17 * i + dword_1930D4 + 2), word_19999C);
    if ( (_BYTE)v1 )
      LOBYTE(v1) = sub_127712((int)byte_19C5B2, i);
  }
  return v1;
}
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;
// 1999A2: using guessed type int16_t word_1999A2;


//----- (0009BB95) --------------------------------------------------------
_BOOL1 __fastcall sub_9BB95(_WORD *a1)
{
  _BOOL1 v1; // dl
  _BOOL1 v2; // dh
  _BOOL1 v3; // dl
  int16_t v4; // ax

  v1 = *(int16_t *)((char *)a1 + 101) > -1 && *(int16_t *)((char *)a1 + 101) < 500;
  v2 = v1;
  v3 = *(int16_t *)((char *)a1 + 101) >= 1000 && *(int16_t *)((char *)a1 + 101) < 1500;
  if ( a1[18] == 1 )
    v4 = a1[14];
  else
    v4 = -1;
  return v2 || v3 && v4 == -1;
}


//----- (0009BBED) --------------------------------------------------------
int16_t sub_9BBED()
{
  int16_t result; // ax
  int v1; // eax

  result = word_182306;
  if ( !word_182306 )
  {
    v1 = dword_1975C4;
    return qsort(dword_19C5A0, *(int16_t *)(v1 + 8), 28);
  }
  if ( (uint16_t)word_182306 <= 1u )
  {
    v1 = dword_1975C4;
    return qsort(dword_19C5A0, *(int16_t *)(v1 + 8), 28);
  }
  if ( word_182306 == 2 )
  {
    v1 = dword_1975C4;
    return qsort(dword_19C5A0, *(int16_t *)(v1 + 8), 28);
  }
  return result;
}
// 182306: using guessed type int16_t word_182306;
// 1975C4: using guessed type int dword_1975C4;
// 19C5A0: using guessed type int dword_19C5A0;


//----- (0009BC46) --------------------------------------------------------
void __fastcall sub_9BC46( int a1)
{
  int16_t v1; // ax
  char v2; // cl
  int16_t v3; // si
  int16_t v4; // bx
  int16_t v5; // [esp+0h] [ebp-34h]
  _DWORD v6[2]; // [esp+4h] [ebp-30h] BYREF
  int v7; // [esp+Ch] [ebp-28h] BYREF
  int v8; // [esp+10h] [ebp-24h] BYREF
  int v9; // [esp+14h] [ebp-20h] BYREF
  int v10; // [esp+18h] [ebp-1Ch] BYREF
  int v11; // [esp+1Ch] [ebp-18h]
  int v12; // [esp+20h] [ebp-14h]
  int v13; // [esp+24h] [ebp-10h]
  char v14; // [esp+28h] [ebp-Ch]
  char v15; // [esp+2Ch] [ebp-8h]
  _BOOL1 v16; // [esp+30h] [ebp-4h]

  v12 = 0;
  v13 = 0;
  v11 = 0;
  sub_9BF1C(a1);
  v2 = 0;
  v14 = 0;
  v15 = byte_19C5EA;
  v6[0] = -437984286;
  v6[1] = -488381468;
  if ( v1 != -1 && (byte_19C5EA || byte_19C5E9) )
  {
    if ( byte_19C5E0 != 1 && (byte_19C5E2 == 1 || !v15 && byte_19C5E9) )
      v14 = 1;
    else
      v2 = 1;
    v3 = v2 ? *(_WORD *)(28 * v1 + dword_19C5A0 + 16) : *(_WORD *)(28 * v1 + dword_19C5A0 + 18);
    v4 = *(_WORD *)(dword_19C5A0 + 28 * v1 + 21);
    if ( v3 != -1 )
    {
      v16 = *(_BYTE *)(129 * v3 + dword_197F9C + 100) == 1;
      sub_9A4F1(v4, &v10, &v8);
      if ( v2 )
      {
        if ( v3 > -1 )
        {
          if ( byte_19C54C[v5] )
          {
            if ( !v16 )
            {
              sub_911D5(v5, 443, 17, 180, 116, v12, v13, v11, &v7, &v9);
              if ( (int16_t)sub_134637(v10, v8, v7 + 4, v9 + 3) > 10 )
              {
                sub_A11C0(v10 + 7, v8 + 2, v7 + 2, v9 + 2, (int)v6, word_19995E);
                word_19995E = (word_19995E + 1) % 8;
              }
            }
          }
        }
      }
      if ( v14 && v3 > -1 && byte_19C54C[v5] && !v16 )
      {
        sub_911D5(v5, 443, 17, 180, 116, v12, v13, v11, &v7, &v9);
        if ( (int16_t)sub_134637(v10, v8, v7 + 4, v9 + 3) > 10 )
        {
          sub_A11C0(v10 + 8, v8 + 2, v7 + 2, v9 + 2, (int)v6, word_19995E);
          word_19995E = (word_19995E + 1) % 8;
        }
      }
    }
  }
  JUMPOUT(0x99A68);
}
// 9BED0: control flows out of bounds to 99A68
// 9BC7E: variable 'v1' is possibly undefined
// 9BD42: variable 'v5' is possibly undefined
// 99510: using guessed type int[3];
// 197F9C: using guessed type int dword_197F9C;
// 19995E: using guessed type int16_t word_19995E;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5E0: using guessed type char byte_19C5E0;
// 19C5E2: using guessed type char byte_19C5E2;
// 19C5E9: using guessed type char byte_19C5E9;
// 19C5EA: using guessed type char byte_19C5EA;


//----- (0009BF1C) --------------------------------------------------------
void __fastcall sub_9BF1C( int a1)
{
  int16_t v2; // dx
  int16_t i; // ax

  v2 = -1;
  for ( i = 0; i < *(int16_t *)(dword_1975C4 + 8) && v2 == -1; ++i )
  {
    if ( *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(28 * i + dword_19C5A0 + 10) + 2) == a1 )
      v2 = i;
  }
  JUMPOUT(0x9AA7C);
}
// 9BF6B: control flows out of bounds to 9AA7C
// 1930D4: using guessed type int dword_1930D4;
// 1975C4: using guessed type int dword_1975C4;
// 19C5A0: using guessed type int dword_19C5A0;


//----- (0009BF70) --------------------------------------------------------
void sub_9BF70()
{
  int v0; // ebx
  int v1; // eax
  int v2; // eax
  _WORD *v3; // eax
  int v4; // edx
  int16_t v5; // si
  int v6; // edx
  int v7; // ebx
  uint8_t v8; // al
  int v9; // ecx
  int v10; // eax
  _BOOL1 v11; // al
  _BOOL1 v12; // cl
  int v13; // eax
  int16_t v14; // ax
  char *v15; // esi
  char *v16; // eax
  int16_t v17; // cx
  int16_t v18; // ax
  int16_t v19; // cx
  int16_t v20; // si
  char *v21; // eax
  char v22; // al
  int16_t v23; // ax
  int v24; // esi
  int16_t v25; // cx
  char *v26; // eax
  int64_t v27; // rax
  int16_t v28; // bx
  char *v29; // esi
  int16_t v30; // di
  int16_t v31; // si
  int16_t v32; // dx
  int16_t v33; // ax
  int16_t v34; // cx
  char *v35; // eax
  int v36; // edi
  int v37; // esi
  int v38; // esi
  int v39; // eax
  int16_t v40; // cx
  char *v41; // eax
  int v42; // eax
  int16_t v43; // cx
  char *v44; // eax
  int v45; // eax
  int v46; // [esp-4h] [ebp-B6h]
  int v47; // [esp-4h] [ebp-B6h]
  int v48; // [esp-4h] [ebp-B6h]
  char v49[100]; // [esp+0h] [ebp-B2h] BYREF
  char v50[80]; // [esp+64h] [ebp-4Eh] BYREF
  char v51[32]; // [esp+B4h] [ebp+2h] BYREF
  char v52[20]; // [esp+D4h] [ebp+22h] BYREF
  _BYTE v53[8]; // [esp+E8h] [ebp+36h] BYREF
  int v54; // [esp+F0h] [ebp+3Eh]
  int v55; // [esp+F4h] [ebp+42h] BYREF
  int v56; // [esp+F8h] [ebp+46h]
  int v57; // [esp+FCh] [ebp+4Ah]
  _WORD *v58; // [esp+100h] [ebp+4Eh]
  _WORD *v59; // [esp+104h] [ebp+52h]
  int v60; // [esp+108h] [ebp+56h]
  int v61; // [esp+10Ch] [ebp+5Ah]
  int v62; // [esp+110h] [ebp+5Eh]
  int v63; // [esp+114h] [ebp+62h]
  int v64; // [esp+118h] [ebp+66h]
  int v65; // [esp+11Ch] [ebp+6Ah]
  int v66; // [esp+120h] [ebp+6Eh]
  int v67; // [esp+124h] [ebp+72h]
  int v68; // [esp+128h] [ebp+76h]
  int v69; // [esp+12Ch] [ebp+7Ah]
  _BOOL1 v70; // [esp+130h] [ebp+7Eh]

  v55 = -1;
  v0 = *(int16_t *)(dword_1975C4 + 12);
  v1 = v0 + 8;
  if ( v0 + 8 > v0 + *(int16_t *)(dword_1975C4 + 8) )
    v1 = v0 + *(int16_t *)(dword_1975C4 + 8);
  v69 = 0;
  v60 = v1;
  while ( 1 )
  {
    HIWORD(v45) = HIWORD(dword_1975C4);
    if ( (int16_t)v69 >= (int16_t)v60 - *(int16_t *)(dword_1975C4 + 12) )
      JUMPOUT(0x9B7DF);
    LOWORD(v45) = *(_WORD *)(dword_1975C4 + 12);
    v2 = v69 + v45;
    v65 = v2;
    LOWORD(v2) = word_1822B8[(int16_t)v69];
    v57 = v2 + 39;
    HIWORD(v4) = HIWORD(dword_19C5A0);
    v3 = (_WORD *)(dword_19C5A0 + 28 * (int16_t)v65);
    LOWORD(v4) = v3[5];
    v5 = 0;
    v66 = v4;
    v68 = 0;
    if ( (int16_t)v4 != -1 )
      break;
LABEL_40:
    ++v69;
  }
  v6 = 17 * (int16_t)v4;
  v7 = v6 + dword_1930D4;
  LOWORD(v6) = *(uint8_t *)(v6 + dword_1930D4 + 2);
  v64 = v6;
  LOWORD(v6) = v3[3];
  LOWORD(v3) = v3[4];
  v59 = v3;
  LOWORD(v3) = *(uint8_t *)(v7 + 6);
  v61 = v6;
  v58 = v3;
  v8 = 0;
  if ( (uint16_t)word_19C5AC > 1u )
  {
    if ( byte_19C5E8 != (_WORD)v69 )
      goto LABEL_12;
  }
  else if ( byte_19C5E8 != (_WORD)v69 || !byte_19C5E4 )
  {
    if ( byte_19C5E8 == (_WORD)v69 )
      v8 = 2;
LABEL_12:
    v9 = 17 * (int16_t)v66;
    sub_9A04B((char *)*(int16_t *)(v9 + dword_1930D4), v53, v8);
    v70 = *(int16_t *)(v9 + dword_1930D4) != -1;
    sub_128AB6(v68 + 18, v57, v68 + 104, (int16_t)(word_1822BA[(int16_t)v69] + v57));
    sub_12B634();
    sub_120BB5(1, (int)v53);
    v10 = 113 * (int16_t)v64 + dword_19306C;
    if ( *(char *)(v10 + 40) > 0 && *(_BYTE *)(v10 + 40) != 11 )
      v5 = *(char *)(v10 + 40);
    v11 = sub_78C5B(v5);
    v12 = v11;
    if ( v5 > 0 && v11 )
    {
      v13 = dword_19306C + 113 * (int16_t)v64;
      if ( *(_BYTE *)(v13 + 40) == 9 )
      {
        v14 = sub_7A352(v13);
        if ( v14 == -1 )
        {
          if ( v5 == 10 )
            v15 = sub_7A990(0x140u);
          else
            v15 = (char *)dword_18F9B8[v5];
        }
        else
        {
          v15 = (char *)(129 * v14 + dword_197F9C);
        }
        strcpy(v50, v15);
        goto LABEL_27;
      }
      if ( v12 && *(char *)(dword_1930D4 + 17 * (int16_t)v66 + 15) == v5 )
      {
        strcpy(v50, (char *)dword_18F9B8[v5]);
LABEL_27:
        sub_1210FD(v68 + 61, v57, (int)v50);
      }
    }
    sub_120BB5(2, (int)v53);
    v62 = (50 - 2 * sub_122259()) / 2 - 4;
    v54 = (int16_t)v66;
    sub_77B42();
    strcpy(v51, v16);
    sub_8FDA1((int)v51, (int)v53, 2, 2, 0, 86, 1);
    v17 = v57;
    v18 = sub_122259();
    v19 = v17 + 50;
    v20 = v68 + 61;
    sub_1210FD(v68 + 61, v19 - 2 * v18, (int)v51);
    if ( v70 )
    {
      v21 = (char *)(3753 * *(char *)(361 * *(int16_t *)(17 * v54 + dword_1930D4) + dword_192B18)
                         + dword_197F98
                         + 21);
    }
    else
    {
      sub_7A47A(v64, &v55);
      if ( !v22 )
      {
LABEL_33:
        sub_12B65C();
        sub_128BE7();
        v24 = (int16_t)v59;
        v56 = v68 + 140;
        v67 = v62 + v57;
        sub_8FDA1(dword_18F990[(int16_t)v59], (int)v53, 2, 2, -1, 65, 1);
        sub_122259();
        v25 = v56;
        sub_1210FD(v56, v67, dword_18F990[v24]);
        sub_120BB5(1, (int)v53);
        v46 = *(int16_t *)(28 * (int16_t)v65 + dword_19C5A0 + 2);
        v26 = sub_7A990(0x141u);
        v27 = sprintf(v49, v26, v46);
        sub_1210FD(v25, SWORD2(v27), (int)v49);
        v28 = (int16_t)v58;
        v29 = (char *)dword_192C74[(int16_t)v58];
        v56 = v68 + 217;
        strcpy(v49, v29);
        sub_120BB5(2, (int)v53);
        v30 = v67 + sub_122259() + 4;
        v31 = sub_9AF07(word_19999C, v28);
        if ( v31 )
        {
          v34 = v56;
          sub_1210FD(v56, v67, (int)v49);
          sub_120BB5(1, (int)v53);
          v35 = sub_7A990(0x142u);
          sprintf(v49, v35, v31);
          v32 = v30;
          v33 = v34;
        }
        else
        {
          v32 = v67 + sub_122259() / 2;
          v33 = v56;
        }
        sub_1210FD(v33, v32, (int)v49);
        v36 = 28 * (int16_t)v65;
        v37 = v57;
        sub_120BB5(2, (int)v53);
        v38 = v62 + v37;
        LOWORD(v39) = sub_122259();
        v63 = v38 + v39 + 4;
        v40 = v68 + 311;
        sub_1210FD(v68 + 311, v38, dword_192BF4[(int16_t)v61]);
        sub_120BB5(1, (int)v53);
        v47 = *(int16_t *)(v36 + dword_19C5A0 + 4);
        v41 = sub_7A990(0x152u);
        sprintf(v49, v41, v47);
        sub_1210FD(v40, v63, (int)v49);
        sub_120BB5(2, (int)v53);
        LOWORD(v42) = sub_122259();
        v63 = v38 + v42 + 4;
        v43 = v68 + 386;
        sub_1210FD(v68 + 386, v38, dword_192BE0[*(uint8_t *)(17 * (int16_t)v66 + dword_1930D4 + 5)]);
        sub_120BB5(1, (int)v53);
        v48 = *(int16_t *)(v36 + dword_19C5A0);
        v44 = sub_7A990(0x143u);
        sprintf(v49, v44, v48);
        sub_1210FD(v43, v63, (int)v49);
        if ( *(char *)(v36 + dword_19C5A0 + 26) >= 0 )
          sub_12A478(
            102 - **(_WORD **)(dword_19C598 + 52),
            word_1822B8[(int16_t)v69] + 84 - *(_WORD *)(*(_DWORD *)(dword_19C598 + 52) + 2),
            *(_DWORD *)(dword_19C598 + 52));
        if ( *(char *)(dword_19C5A0 + 28 * (int16_t)v65 + 27) >= 0 )
          sub_12A478(
            18,
            word_1822B8[(int16_t)v69] + 84 - *(_WORD *)(*(_DWORD *)(dword_19C598 + 52) + 2),
            *(_DWORD *)(dword_19C598 + 52));
        goto LABEL_40;
      }
      sub_784A0(v55, v52);
      v21 = v52;
    }
    sprintf(v49, "(%s)", v21);
    sub_120BB5(1, (int)v53);
    v23 = sub_122259();
    sub_1210FD(v20, v19 - v23 - 2, (int)v49);
    goto LABEL_33;
  }
  v8 = 1;
  goto LABEL_12;
}
// 9C5FB: control flows out of bounds to 9B7DF
// 9C175: conditional instruction was optimized away because si.2 is in (1..7F)
// 9C1FC: variable 'v16' is possibly undefined
// 9C283: variable 'v22' is possibly undefined
// 9C45D: variable 'v39' is possibly undefined
// 9C4DF: variable 'v42' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1822B8: using guessed type int16_t word_1822B8[];
// 1822BA: using guessed type int16_t word_1822BA[32];
// 18F990: using guessed type int dword_18F990[];
// 18F9B8: using guessed type int dword_18F9B8[];
// 192B18: using guessed type int dword_192B18;
// 192BE0: using guessed type int dword_192BE0[];
// 192BF4: using guessed type int dword_192BF4[];
// 192C74: using guessed type int dword_192C74[];
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1975C4: using guessed type int dword_1975C4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 19C598: using guessed type int dword_19C598;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5AC: using guessed type int16_t word_19C5AC;
// 19C5E4: using guessed type char byte_19C5E4;
// 19C5E8: using guessed type char byte_19C5E8;


//----- (0009C600) --------------------------------------------------------
void sub_9C600()
{
  int16_t v0; // bx
  int v1; // edx
  int16_t v2; // ax
  char v3; // cl
  char *v4; // eax
  int16_t v5; // dx
  int16_t v6; // ax
  _BOOL1 v7; // dl
  uint16_t v8; // ax
  char *v9; // esi
  int16_t v10; // ax
  uint16_t v11; // ax
  char *v12; // eax
  int16_t v13; // ax
  uint16_t v14; // ax
  char *v15; // eax
  void *v16; // edx
  _BOOL1 v17; // al
  char v18; // cl
  uint16_t v19; // ax
  char *v20; // eax
  char *v21; // eax
  int v22; // [esp-8h] [ebp-52h]
  int v23; // [esp-4h] [ebp-4Eh]
  int v24; // [esp-4h] [ebp-4Eh]
  int v25; // [esp-4h] [ebp-4Eh]
  int v26; // [esp-4h] [ebp-4Eh]
  int v27; // [esp-4h] [ebp-4Eh]
  char v28[200]; // [esp+0h] [ebp-4Ah] BYREF
  char v29[100]; // [esp+C8h] [ebp+7Eh] BYREF
  char v30[100]; // [esp+12Ch] [ebp+E2h] BYREF
  int v31; // [esp+190h] [ebp+146h]
  int v32; // [esp+194h] [ebp+14Ah]

  v0 = word_1999BC;
  v1 = word_1999BC;
  sub_9BF1C(word_1999BC);
  v31 = 533;
  v32 = 143;
  v3 = 0;
  if ( *(_BYTE *)(28 * v2 + dword_19C5A0 + 20) == 1 )
  {
    v23 = 113 * v1 + dword_19306C;
    v4 = sub_7A990(0x144u);
    sprintf(v28, v4, v23);
    sub_120BB5(1, (int)&unk_1822A8);
    v5 = sub_122259() / 2 + 143;
    v6 = 533;
LABEL_55:
    sub_1210FD(v6, v5, (int)v28);
LABEL_56:
    JUMPOUT(0x9B7E5);
  }
  if ( v0 < 1000 || v1 >= word_19999A + 1000 )
  {
    if ( (uint16_t)word_19C5AC > 1u )
      goto LABEL_56;
    if ( sub_79E32(word_19999C, v0) || (v17 = sub_79E06(word_19999C)) )
      v17 = 1;
    if ( byte_1992AD )
    {
      v18 = 2;
      if ( v17 )
      {
        v26 = dword_19306C + 113 * v0;
        if ( byte_1992AC == 1 )
        {
          v22 = 1;
          v19 = 105;
        }
        else
        {
          v22 = (uint8_t)byte_1992AC;
          v19 = 106;
        }
        v20 = sub_7A990(v19);
        sprintf(v28, v20, v22, v26);
      }
      else
      {
        v27 = (uint8_t)byte_1992AC;
        v21 = sub_7A990(0x14Cu);
        sprintf(v28, v21, v27);
      }
    }
    else
    {
      v18 = 1;
      strcpy(v28, sub_7A990(0x148u));
    }
    if ( (uint8_t)v18 <= 1u )
      v16 = &unk_1822A8;
    else
      v16 = &unk_1822B0;
    goto LABEL_54;
  }
  v7 = sub_79E32(word_19999C, v0 - 1000) || sub_79E06(word_19999C);
  if ( *(_BYTE *)(dword_19306C + 113 * (v0 - 1000) + 22) == 6 )
  {
    v8 = 325;
  }
  else
  {
    if ( v7 )
    {
      strcpy(v29, (char *)(dword_19306C + 113 * (v0 - 1000)));
      v30[0] = 0;
      if ( (uint16_t)word_19C5AC <= 1u )
      {
        if ( *((_BYTE *)&word_19C164 + v0) )
        {
          v10 = sub_9A5E8(v0 - 1000);
          if ( v10 > 0 )
          {
            if ( v10 == 1 )
            {
              v24 = 1;
              v11 = 336;
            }
            else
            {
              v24 = v10;
              v11 = 337;
            }
            v12 = sub_7A990(v11);
            sprintf(v30, v12, v24);
          }
          v3 = 2;
        }
        else
        {
          v3 = 1;
          strcpy(v30, sub_7A990(0x146u));
        }
      }
      sprintf(v28, "%s%s", v30, v29);
      goto LABEL_34;
    }
    if ( (uint16_t)word_19C5AC > 1u )
    {
      v9 = sub_7A990(0x94u);
      goto LABEL_33;
    }
    if ( *((_BYTE *)&word_19C164 + v0) )
    {
      v13 = sub_9A5E8(v0 - 1000);
      if ( v13 > 0 )
      {
        if ( v13 == 1 )
        {
          v25 = 1;
          v14 = 331;
        }
        else
        {
          v25 = v13;
          v14 = 332;
        }
        v15 = sub_7A990(v14);
        sprintf(v28, v15, v25);
      }
      v3 = 2;
      goto LABEL_34;
    }
    v8 = 327;
  }
  v9 = sub_7A990(v8);
  v3 = 1;
LABEL_33:
  strcpy(v28, v9);
LABEL_34:
  if ( v3 )
  {
    if ( (uint8_t)v3 <= 1u )
      v16 = &unk_1822A8;
    else
      v16 = &unk_1822B0;
  }
  else
  {
    v16 = &unk_1822A0;
  }
LABEL_54:
  sub_120BB5(2, (int)v16);
  v5 = v32 + (sub_122259() + 2) / 2;
  v6 = v31;
  goto LABEL_55;
}
// 9C9ED: control flows out of bounds to 9B7E5
// 9C865: conditional instruction was optimized away because cl.1==2
// 9C999: conditional instruction was optimized away because cl.1 is in (1..2)
// 9C9A0: conditional instruction was optimized away because cl.1==2
// 9C620: variable 'v2' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 1992AC: using guessed type char byte_1992AC;
// 1992AD: using guessed type char byte_1992AD;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1999BC: using guessed type int16_t word_1999BC;
// 19C164: using guessed type int16_t word_19C164;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5AC: using guessed type int16_t word_19C5AC;


//----- (0009C9F2) --------------------------------------------------------
int __fastcall sub_9C9F2( int a1)
{
  int v2; // ebx
  int i; // edx
  _WORD *v4; // eax

  v2 = -1;
  for ( i = 0; (int16_t)i < word_19C5B0 && (int16_t)v2 == -1; ++i )
  {
    v4 = (_WORD *)(8 * (int16_t)i + dword_19C5A4);
    if ( a1 == *v4 || a1 == v4[1] )
      v2 = i;
  }
  return v2;
}
// 19C5A4: using guessed type int dword_19C5A4;
// 19C5B0: using guessed type int16_t word_19C5B0;


//----- (0009CA34) --------------------------------------------------------
int __fastcall sub_9CA34(int a1, int a2)
{
  return sub_12A478(
           102 - **(_WORD **)(dword_19C598 + 52),
           word_1822B8[a2] + 84 - *(_WORD *)(*(_DWORD *)(dword_19C598 + 52) + 2),
           *(_DWORD *)(dword_19C598 + 52));
}
// 1822B8: using guessed type int16_t word_1822B8[];
// 19C598: using guessed type int dword_19C598;


//----- (0009CA6F) --------------------------------------------------------
int __fastcall sub_9CA6F(int a1, int a2)
{
  return sub_12A478(
           18,
           word_1822B8[a2] + 84 - *(_WORD *)(*(_DWORD *)(dword_19C598 + 52) + 2),
           *(_DWORD *)(dword_19C598 + 52));
}
// 1822B8: using guessed type int16_t word_1822B8[];
// 19C598: using guessed type int dword_19C598;


//----- (0009CAA0) --------------------------------------------------------
void sub_9CAA0()
{
  int16_t v0; // si
  int16_t v1; // dx
  int16_t v2; // ax
  int v3; // eax
  int16_t i; // si
  int16_t *v5; // eax
  _BOOL1 v6; // al
  char v7; // cl
  int v8; // eax
  _BOOL1 v9; // al
  char v10; // ch
  int v11; // eax
  int v12; // [esp+8h] [ebp-20h] BYREF
  int v13; // [esp+Ch] [ebp-1Ch]
  int v14; // [esp+10h] [ebp-18h] BYREF
  int v15; // [esp+14h] [ebp-14h]
  int v16; // [esp+18h] [ebp-10h]
  int v17; // [esp+1Ch] [ebp-Ch]
  int v18; // [esp+20h] [ebp-8h]
  int v19; // [esp+24h] [ebp-4h]

  v18 = 0;
  v19 = 0;
  v16 = 0;
  v13 = 0;
  v15 = 2;
  v17 = -1;
  sub_128AB6(443, 17, 623, 133);
  sub_12B634();
  v0 = 226;
  if ( word_1999BC == -1 )
    goto LABEL_13;
  v1 = word_1999BC;
  if ( word_1999BC >= 1000 )
  {
    if ( word_1999BC >= word_19999A + 1000 )
      goto LABEL_7;
    v2 = word_1999BC - 1000;
  }
  else
  {
    v2 = word_1999BC;
  }
  sub_9BC46(v2);
LABEL_7:
  if ( v1 >= 1000 && v1 < word_19999A + 1000 )
    v1 -= 1000;
  sub_911D5(v1, 443, 17, 180, 116, v18, v19, v15, &v14, &v12);
  v3 = *(char *)(113 * v1 + dword_19306C + 20);
  if ( v3 > -1 )
    v0 = 6 * *(uint8_t *)(dword_197F98 + 3753 * v3 + 38) + 212;
  sub_1297C3(v14 - 1, v12 - 1, 9, 9, 1, v0);
LABEL_13:
  for ( i = 0; i < word_19C5B0; ++i )
  {
    v5 = (int16_t *)(8 * i + dword_19C5A4);
    v6 = *v5 != -1 && *((_BYTE *)v5 + 6);
    v7 = v6;
    v8 = dword_19C5A4 + 8 * i;
    v9 = *(int16_t *)(v8 + 2) != -1 && *(_BYTE *)(v8 + 7);
    v10 = v9;
    if ( v7 || v9 )
    {
      sub_9A4F1(i, &v14, &v12);
      sub_9AC79((int16_t)v14, (int16_t)v12, i, v7, v10);
    }
  }
  sub_12B65C();
  sub_128BE7();
  sub_90C4F(17, 443, i, 180, 116, v18, v19, v16, (int16_t)v13, v15, v17);
  v11 = dword_19C5A0;
  *(_WORD *)(dword_19C5A0 + 23) += 2 * *(char *)(dword_19C5A0 + 25);
  if ( *(char *)(v11 + 25) > 0 && *(int16_t *)(v11 + 23) >= 3
    || *(char *)(dword_19C5A0 + 25) < 0 && *(int16_t *)(dword_19C5A0 + 23) <= 0 )
  {
    *(_BYTE *)(dword_19C5A0 + 25) = -*(_BYTE *)(dword_19C5A0 + 25);
  }
  JUMPOUT(0x99A68);
}
// 9CCFA: control flows out of bounds to 99A68
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;
// 1999BC: using guessed type int16_t word_1999BC;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5A4: using guessed type int dword_19C5A4;
// 19C5B0: using guessed type int16_t word_19C5B0;


//----- (0009CCFF) --------------------------------------------------------
int __fastcall sub_9CCFF(int a1, int a2)
{
  return *(int16_t *)(a2 + 8) - *(int16_t *)(a1 + 8);
}


//----- (0009CD0C) --------------------------------------------------------
int __fastcall sub_9CD0C(int16_t *a1, int16_t *a2)
{
  return *a2 - *a1;
}


//----- (0009CD24) --------------------------------------------------------
int16_t sub_9CD24()
{
  int16_t v0; // cx
  char v1; // bl
  int64_t v2; // rax
  _WORD *v3; // eax
  uint16_t v4; // ax
  int v5; // eax
  int v6; // eax
  uint16_t v7; // ax
  char *v8; // eax
  _BYTE *v9; // eax
  int v10; // edx
  int v11; // eax
  _BYTE *v12; // eax
  int v13; // eax
  char v14; // al
  int v16; // [esp-8h] [ebp-14Eh]
  int v17; // [esp-4h] [ebp-14Ah]
  _BYTE *v18; // [esp-4h] [ebp-14Ah]
  int16_t v19; // [esp+0h] [ebp-146h]
  int16_t v20; // [esp+4h] [ebp-142h]
  _BYTE v21[200]; // [esp+8h] [ebp-13Eh] BYREF
  char v22[200]; // [esp+D0h] [ebp-76h] BYREF
  _BYTE v23[40]; // [esp+198h] [ebp+52h] BYREF
  int v24; // [esp+1C0h] [ebp+7Ah] BYREF
  int v25; // [esp+1C4h] [ebp+7Eh]

  v0 = -1;
  v1 = 0;
  WORD2(v2) = 0;
  v24 = -1;
  while ( SWORD2(v2) < *(int16_t *)(dword_1975C4 + 8) && !v1 )
  {
    v3 = (_WORD *)(dword_19C5A0 + 28 * SWORD2(v2));
    if ( v3[5] == v20 )
    {
      if ( v19 == 1 )
        v0 = v3[8];
      else
        v0 = v3[9];
      if ( !sub_8A16A(v0) )
      {
        if ( v19 == 1 )
          v4 = 329;
        else
          v4 = 330;
        strcpy(v22, sub_7A990(v4));
        sub_77B42();
        v2 = sprintf(v21, v22, v5);
        sub_77433(v21);
      }
      v1 = 1;
    }
    ++WORD2(v2);
  }
  LOWORD(v6) = v0;
  if ( v0 != -1 )
  {
    v6 = sub_7A3E3(*(_WORD *)(129 * v0 + dword_197F9C + 103), *(_WORD *)(129 * v0 + dword_197F9C + 105));
    if ( (int16_t)v6 == -1 )
    {
      LOWORD(v24) = v0;
      sub_78D86();
      v25 = v6;
      if ( (int16_t)v6 != -1 )
        goto LABEL_20;
      v6 = 17 * *(int16_t *)(3753 * word_19999C + dword_197F98 + 41);
      LOWORD(v6) = *(uint8_t *)(dword_1930D4 + v6 + 2);
    }
    v25 = v6;
LABEL_20:
    if ( (int16_t)v25 != -1 )
    {
      LOWORD(v24) = v0;
      sub_FF799((int16_t *)&v24, v25, &byte_1992A8);
      if ( byte_1992AC == 1 )
      {
        v17 = 1;
        v7 = 331;
      }
      else
      {
        v17 = (uint8_t)byte_1992AC;
        v7 = 332;
      }
      v8 = sub_7A990(v7);
      sprintf(v23, v8, v17);
      if ( v19 == 1 )
      {
        strcpy(v22, sub_7A990(0x14Du));
        if ( byte_1992AC )
          v9 = v23;
        else
          v9 = &unk_179B78;
        v18 = v9;
        v10 = 113 * (int16_t)v25;
        v11 = dword_19306C;
      }
      else
      {
        strcpy(v22, sub_7A990(0x14Eu));
        if ( byte_1992AC )
          v12 = v23;
        else
          v12 = &unk_179B78;
        v18 = v12;
        v11 = 113 * (int16_t)v25;
        v10 = dword_19306C;
      }
      v16 = v10 + v11;
      sub_77B42();
      sprintf(v21, v22, v13, v16, v18);
      sub_77658((int)v21);
      if ( v14 )
      {
        sub_FFD08((int16_t *)&v24, v25, &byte_1992A8);
        sub_9CFA8();
        sub_A1BF4(129 * v0 + dword_197F9C);
      }
      LOWORD(v6) = dword_19C598;
      *(_BYTE *)(dword_19C598 + 274) = 1;
    }
  }
  return v6;
}
// 9CD63: variable 'v20' is possibly undefined
// 9CD71: variable 'v19' is possibly undefined
// 9CDCB: variable 'v5' is possibly undefined
// 9CE2E: variable 'v6' is possibly undefined
// 9CF4E: variable 'v13' is possibly undefined
// 9CF63: variable 'v14' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1975C4: using guessed type int dword_1975C4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 1992A8: using guessed type char byte_1992A8;
// 1992AC: using guessed type char byte_1992AC;
// 19999C: using guessed type int16_t word_19999C;
// 19C598: using guessed type int dword_19C598;
// 19C5A0: using guessed type int dword_19C5A0;


//----- (0009CFA8) --------------------------------------------------------
void sub_9CFA8()
{
  int16_t i; // bx
  int v1; // eax
  int v2; // edx
  int16_t j; // bx
  int v4; // esi
  int16_t v5; // cx
  int16_t v6; // di
  int v7; // eax
  int16_t v8; // ax
  int16_t v9; // ax
  int v10; // eax
  char v11; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *(int16_t *)(dword_1975C4 + 8); ++i )
  {
    v1 = 28 * i;
    v2 = dword_19C5A0;
    *(_BYTE *)(dword_19C5A0 + v1 + 26) = -1;
    *(_BYTE *)(v2 + v1 + 27) = -1;
  }
  for ( j = 0; j < word_199994; ++j )
  {
    v4 = 129 * j;
    v5 = sub_78E07(*(int16_t *)(v4 + dword_197F9C + 101));
    v6 = -1;
    if ( sub_77FF5(j) == word_19999C
      && v5 > -1
      && (*(_BYTE *)(v4 + dword_197F9C + 17) == 1 || *(_BYTE *)(v4 + dword_197F9C + 17) == 4) )
    {
      v11 = sub_79BEB(j, v5);
      v7 = dword_197F9C + 129 * j;
      if ( *(_WORD *)(v7 + 36) == 1 )
        v8 = *(_WORD *)(v7 + 28);
      else
        v8 = -1;
      if ( v8 > -1 )
      {
        sub_9AA83(v8);
        v6 = v9;
      }
      if ( v6 > -1 )
      {
        v10 = 28 * v6 + dword_19C5A0;
        if ( *(_BYTE *)(dword_197F9C + 129 * j + 17) == 1 )
          *(_BYTE *)(v10 + 26) = v11;
        else
          *(_BYTE *)(v10 + 27) = v11;
      }
    }
  }
  JUMPOUT(0x99A68);
}
// 9D0C1: control flows out of bounds to 99A68
// 9D074: variable 'v9' is possibly undefined
// 1975C4: using guessed type int dword_1975C4;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999C: using guessed type int16_t word_19999C;
// 19C5A0: using guessed type int dword_19C5A0;


//----- (0009D0C6) --------------------------------------------------------
int sub_9D0C6()
{
  int16_t i; // dx
  int16_t v1; // bx
  int v2; // eax
  int result; // eax

  if ( word_19994C )
  {
    sub_124D7A();
    sub_128C32(0, 0, 639, 479, 0);
    sub_12A478(0, 0, *(_DWORD *)dword_19C598);
    sub_124E36();
    word_19994C = 0;
    sub_124D41();
  }
  sub_128C32(0, 0, 639, 479, 0);
  sub_12A478(0, 0, *(_DWORD *)dword_19C598);
  sub_128BE7();
  sub_12B65C();
  if ( sub_113F8C() == word_19C5AE )
    byte_19C5E7 = 1;
  sub_9A125();
  sub_9CAA0();
  sub_A0226((int16_t *)dword_1975C4, (void (__cdecl *)(_DWORD))sub_9A1F0);
  sub_9BF70();
  if ( word_1999BC > -1 )
    sub_9C600();
  for ( i = 0; i < word_19C5B0 && !byte_19C5E5; ++i )
  {
    v1 = *(int16_t *)((char *)&word_1975D4 + 5 * word_1906C2[6 * *(int16_t *)(dword_19C5A4 + 8 * i + 4)]);
    v2 = 129 * v1 + dword_197F9C;
    if ( *(int16_t *)(v2 + 101) >= 500 && (*(_BYTE *)(v2 + 17) == 1 || *(_BYTE *)(v2 + 17) == 4) )
      sub_9BC46(*(_WORD *)(dword_197F9C + 129 * v1 + 101));
  }
  sub_12B753(dword_1822FE, (uint8_t)byte_19C5E0);
  sub_12A478(454, 386, dword_1822FE);
  sub_12B753(dword_182302, (uint8_t)byte_19C5E2);
  result = sub_12A478(454, 413, dword_182302);
  byte_19C5E3 = 0;
  return result;
}
// 1822FE: using guessed type int dword_1822FE;
// 182302: using guessed type int dword_182302;
// 1906C2: using guessed type int16_t word_1906C2[];
// 1975C4: using guessed type int dword_1975C4;
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 19994C: using guessed type int16_t word_19994C;
// 1999BC: using guessed type int16_t word_1999BC;
// 19C598: using guessed type int dword_19C598;
// 19C5A4: using guessed type int dword_19C5A4;
// 19C5AE: using guessed type int16_t word_19C5AE;
// 19C5B0: using guessed type int16_t word_19C5B0;
// 19C5E0: using guessed type char byte_19C5E0;
// 19C5E2: using guessed type char byte_19C5E2;
// 19C5E3: using guessed type char byte_19C5E3;
// 19C5E5: using guessed type char byte_19C5E5;
// 19C5E7: using guessed type char byte_19C5E7;


//----- (0009D252) --------------------------------------------------------
void sub_9D252()
{
  int v0; // edi
  int v1; // eax
  _WORD *v2; // eax
  int16_t v3; // ax
  int v4; // ebx
  int16_t v5; // dx
  int16_t v6; // dx
  int v7; // eax
  int *v8; // ebx
  int v9; // edx
  _DWORD *v10; // ecx
  int v11; // eax
  int v12; // eax
  int16_t v13; // si
  int v14; // eax
  int16_t v15; // dx
  char *v16; // ebx
  int v17; // eax
  _WORD *v18; // ebx
  int16_t v19; // ax
  int16_t i; // si
  int16_t v21; // ax
  _WORD *v22; // ebx
  char *v23; // eax
  char *v24; // eax
  char *v25; // eax
  int v26; // eax
  int v27; // [esp-4h] [ebp-78h]
  _BYTE v28[100]; // [esp+0h] [ebp-74h] BYREF
  int v29; // [esp+64h] [ebp-10h]
  char *v30; // [esp+68h] [ebp-Ch]
  int v31; // [esp+6Ch] [ebp-8h] BYREF
  char v32; // [esp+70h] [ebp-4h]

  sub_82348();
  v0 = 0;
  byte_19C5E5 = 1;
  sub_11946A(215);
  sub_6F52D();
  byte_182ACE = 0;
  byte_19C5E1 = 0;
  byte_19C5E7 = 0;
  word_19C5AC = -1;
  word_1999BC = -1;
  v31 = -1;
  byte_199F29 = 0;
  word_19C5AA = -1;
  dword_19C59C = 0;
  byte_19B995 = 1;
  byte_19C5DF = 0;
  byte_19C5E3 = 0;
  byte_19C5E4 = 0;
  byte_19C5E0 = 0;
  byte_19C5E2 = 0;
  word_19C5B0 = 0;
  word_19995E = 0;
  sub_124B65();
  sub_99E07();
  if ( byte_19C5EA )
    byte_19C5E0 = 1;
  if ( byte_19C5E9 )
    byte_19C5E2 = 1;
  sub_1191CA((int)sub_9D0C6, 1);
  sub_11C2F0();
  sub_8F26E(0);
  sub_1205E6(6, 0, 254);
  sub_99A6F();
  sub_9A709(0);
  sub_995D1();
  v1 = dword_19C5A0;
  *(_WORD *)(dword_19C5A0 + 23) = 0;
  *(_BYTE *)(v1 + 25) = 1;
  sub_9BB40();
  sub_9A2BA((int16_t *)(dword_1975C4 + 8));
  v2 = (_WORD *)dword_1975C4;
  *(_WORD *)dword_1975C4 = 407;
  v2[5] = 8;
  v2[7] = 407;
  v3 = sub_A00F1(v2);
  v4 = dword_1975C4;
  *(_WORD *)(dword_1975C4 + 6) = v3;
  *(_WORD *)(v4 + 2) = -1;
  v5 = *(_WORD *)(v4 + 14);
  *(_BYTE *)(v4 + 24) = 2;
  v6 = v5 - v3 / 2;
  v7 = dword_192ED4;
  *(_WORD *)v4 = v6;
  *(_BYTE *)(v4 + 26) = 1;
  v8 = 0;
  dword_19C594 = (int)sub_110D3C(v7, 200);
  do
  {
    v9 = (int16_t)v8;
    v10 = sub_9A66B((int16_t)v8);
    v11 = dword_19C594;
    v8 = (int *)((char *)v8 + 1);
    *(_DWORD *)(dword_19C594 + 4 * v9) = v10;
    sub_FE8BE(v11, v9, (int)v8, 0);
  }
  while ( (int16_t)v8 < 50 );
  LOBYTE(v12) = sub_9A07B();
  while ( 1 )
  {
    if ( (_WORD)v0 )
    {
      sub_11C2F0();
      sub_1172D4();
      sub_124C08();
      sub_123E6C((int)&unk_17CF00, 1);
      sub_8F26E((int16_t *)v0);
      sub_1172FC();
      dword_1975C4 = 0;
      if ( sub_918D5(2) && word_19C5AA != -1 )
        word_199A06 = -1;
      sub_84E9D();
      sub_11946A(10);
      JUMPOUT(0x99A68);
    }
    v13 = word_182306;
    v14 = sub_1171AB(v12, v9, (int)v8, (int)v10);
    v15 = v14;
    v10 = (_DWORD *)v14;
    v16 = sub_114177();
    v17 = dword_19C598;
    *(_WORD *)(dword_19C598 + 275) = (_WORD)v16;
    v30 = v16;
    if ( v15 == *(_WORD *)(v17 + 128) )
    {
      word_199A08 = 0;
      v0 = 1;
    }
    if ( v13 != word_182306
      && ((_WORD)v10 == *(_WORD *)(dword_19C598 + 56)
       || (_WORD)v10 == *(_WORD *)(dword_19C598 + 58)
       || (_WORD)v10 == *(_WORD *)(dword_19C598 + 60)) )
    {
      sub_9BBED();
      word_1999BC = -1;
    }
    if ( (_WORD)v10 == *(_WORD *)(dword_19C598 + 62)
      || (_WORD)v10 == *(_WORD *)(dword_19C598 + 64)
      || (_WORD)v10 == *(_WORD *)(dword_19C598 + 66)
      || (_WORD)v10 == *(_WORD *)(dword_19C598 + 68)
      || (_WORD)v10 == *(_WORD *)(dword_19C598 + 70) )
    {
      sub_9A2BA((int16_t *)(dword_1975C4 + 8));
      v18 = (_WORD *)dword_1975C4;
      v31 = -1;
      if ( *(int16_t *)(dword_1975C4 + 8) >= 8 )
      {
        if ( *(int16_t *)(dword_1975C4 + 12) + 8 > *(int16_t *)(dword_1975C4 + 8) )
        {
          v19 = *(_WORD *)(dword_1975C4 + 8) - 8;
          *(_WORD *)(dword_1975C4 + 12) = v19;
          *v18 = 407 - 407 * (1000 * v19 / (int16_t)v18[4]) / 1000;
        }
      }
      else
      {
        *(_WORD *)(dword_1975C4 + 12) = 0;
      }
      if ( byte_19C5EA || sub_9B7EB() )
        sub_99AFA();
    }
    if ( (_WORD)v10 == *(_WORD *)(dword_19C598 + 124) && *(int16_t *)(dword_1975C4 + 8) > 8 )
    {
      sub_A01C6((int16_t *)dword_1975C4);
      v31 = -1;
    }
    if ( (_WORD)v10 == *(_WORD *)(dword_19C598 + 126) && *(int16_t *)(dword_1975C4 + 8) > 8 )
    {
      sub_A015D((int16_t *)dword_1975C4);
      v31 = -1;
    }
    if ( (_WORD)v10 == word_19C5AE )
    {
      byte_19C5E7 = 1;
      v31 = -1;
    }
    v32 = 0;
    for ( i = 0; i < word_19999A && !v32; ++i )
    {
      if ( (_WORD)v10 == *(_WORD *)(dword_19C598 + 2 * i + 130) && *(int16_t *)(dword_1975C4 + 8) > 8 )
      {
        v21 = sub_9AA2E(i);
        if ( v21 <= -1 )
        {
          v27 = dword_19306C + 113 * i;
          v23 = sub_7A990(0x14Fu);
          sprintf(v28, v23, v27);
          sub_77433(v28);
        }
        else
        {
          v22 = (_WORD *)dword_1975C4;
          *(_WORD *)(dword_1975C4 + 12) = v21;
          v29 = (int16_t)v22[4];
          *v22 = 407 - v22[6] * (407 / v29 + 1);
        }
        v32 = 1;
      }
      if ( (_WORD)v30 == *(_WORD *)(2 * i + dword_19C598 + 130) )
      {
        v32 = 1;
        word_1999BC = i + 1000;
      }
    }
    v8 = &v31;
    v9 = (int16_t)v10;
    sub_9B04D((int16_t)v30, (int16_t)v10, &v31);
    if ( (_WORD)v10 == *(_WORD *)(dword_19C598 + 72) && byte_19C5E0 )
    {
      if ( sub_233FA() )
      {
        v24 = sub_7A990(0x13Fu);
        sub_77433(v24);
      }
      else if ( byte_19C5E0 != 2 )
      {
        byte_19C5E0 = 2;
        byte_19C5E2 = 1;
        word_19C5AC = 0;
        goto LABEL_55;
      }
      byte_19C5E0 = 1;
      word_19C5AC = -1;
    }
LABEL_55:
    if ( (_WORD)v10 == *(_WORD *)(dword_19C598 + 74) && byte_19C5E2 )
    {
      if ( sub_233FA() )
      {
        v25 = sub_7A990(0x13Fu);
        sub_77433(v25);
LABEL_59:
        byte_19C5E2 = 1;
        word_19C5AC = -1;
        goto LABEL_62;
      }
      if ( byte_19C5E2 == 2 )
        goto LABEL_59;
      byte_19C5E2 = 2;
      byte_19C5E0 = 1;
      word_19C5AC = 1;
    }
LABEL_62:
    v12 = dword_19C598;
    if ( *(_BYTE *)(dword_19C598 + 274) )
    {
      sub_11C2F0();
      sub_995D1();
      v12 = dword_19C598;
      *(_BYTE *)(dword_19C598 + 274) = 0;
    }
    if ( !(_WORD)v0 )
    {
      if ( byte_19C5E5 )
      {
        sub_124D41();
        sub_9D0C6();
        sub_124DEC();
        sub_C5C44();
        byte_19C5E5 = 0;
      }
      else
      {
        sub_124D41();
        v26 = sub_9D0C6();
        v12 = sub_1077D(v26, (int16_t)v10, (int)&v31, (int16_t *)v0);
      }
    }
  }
}
// 9D7E5: control flows out of bounds to 99A68
// 9D40E: variable 'v12' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182306: using guessed type int16_t word_182306;
// 182ACE: using guessed type char byte_182ACE;
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 1975C4: using guessed type int dword_1975C4;
// 19995E: using guessed type int16_t word_19995E;
// 19999A: using guessed type int16_t word_19999A;
// 1999BC: using guessed type int16_t word_1999BC;
// 199A06: using guessed type int16_t word_199A06;
// 199A08: using guessed type int16_t word_199A08;
// 199F29: using guessed type char byte_199F29;
// 19B995: using guessed type char byte_19B995;
// 19C594: using guessed type int dword_19C594;
// 19C598: using guessed type int dword_19C598;
// 19C59C: using guessed type int dword_19C59C;
// 19C5A0: using guessed type int dword_19C5A0;
// 19C5AA: using guessed type int16_t word_19C5AA;
// 19C5AC: using guessed type int16_t word_19C5AC;
// 19C5AE: using guessed type int16_t word_19C5AE;
// 19C5B0: using guessed type int16_t word_19C5B0;
// 19C5DF: using guessed type char byte_19C5DF;
// 19C5E0: using guessed type char byte_19C5E0;
// 19C5E1: using guessed type char byte_19C5E1;
// 19C5E2: using guessed type char byte_19C5E2;
// 19C5E3: using guessed type char byte_19C5E3;
// 19C5E4: using guessed type char byte_19C5E4;
// 19C5E5: using guessed type char byte_19C5E5;
// 19C5E7: using guessed type char byte_19C5E7;
// 19C5E9: using guessed type char byte_19C5E9;
// 19C5EA: using guessed type char byte_19C5EA;


//----- (0009D7EA) --------------------------------------------------------
int sub_9D7EA()
{
  int16_t v0; // dx
  int result; // eax

  v0 = sub_11438B(0, 0, 639, 479, asc_179BAA, 41);
  result = dword_19C7C0;
  *(_WORD *)(dword_19C7C0 + 76) = v0;
  return result;
}
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009D816) --------------------------------------------------------
int __fastcall sub_9D816( int a1)
{
  int16_t v2; // di
  int16_t i; // ax
  int16_t v4; // ax
  int16_t v5; // bx
  int16_t v6; // ax
  _WORD v8[8]; // [esp+0h] [ebp-14h] BYREF
  int v9; // [esp+10h] [ebp-4h]

  v9 = sub_12484C();
  v2 = 0;
  memset(v8, 0, sizeof(v8));
  for ( i = 0; i < 8; ++i )
  {
    if ( i != a1 && *(_BYTE *)(3753 * a1 + dword_197F98 + i + 1551) == 1 )
      v8[i] = 2;
    if ( *(_WORD *)(2 * i + dword_197F98 + 3753 * a1 + 498) )
      v8[i] = 5;
  }
  if ( *(int16_t *)(dword_19C7C0 + 140) >= 16 )
    v4 = 16;
  else
    v4 = *(_WORD *)(dword_19C7C0 + 140);
  v5 = 0;
  *(_WORD *)(dword_19C7C0 + 138) = v4;
  while ( v5 < *(int16_t *)(dword_19C7C0 + 138) )
  {
    v6 = sub_FE92D((int)v8, 8);
    if ( v6 > -1 && v6 < word_199998 && v6 != a1 )
    {
      ++v2;
      *(_BYTE *)(v5 + dword_19C7C0 + 142) = *(_BYTE *)(3753 * v6 + dword_197F98 + 37);
    }
    ++v5;
  }
  qsort(dword_19C7C0 + 142, 16, 1);
  *(_WORD *)(dword_19C7C0 + 138) = v2;
  return sub_124820(v9);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009D94C) --------------------------------------------------------
int __fastcall sub_9D94C( int a1)
{
  int16_t i; // ax
  int v3; // edx

  for ( i = 0; i < word_199996; ++i )
    ;
  v3 = sub_12484C();
  sub_9FCF0(a1);
  return sub_124820(v3);
}
// 199996: using guessed type int16_t word_199996;


//----- (0009D977) --------------------------------------------------------
int __fastcall sub_9D977( int a1)
{
  int16_t v3; // dx
  int16_t v4; // dx
  int16_t v6; // ax
  int16_t v7; // cx
  int v8; // ebx
  uint16_t v9; // dx
  int v10; // esi
  int16_t v11; // dx
  int v12; // eax
  int16_t v13; // dx
  int v14; // eax
  int16_t v15; // ax
  int16_t *v16; // ebx
  int result; // eax
  int v18; // [esp+0h] [ebp-8h] BYREF
  int v19; // [esp+4h] [ebp-4h] BYREF

  *(_WORD *)(dword_19C7C0 + 118) = sub_9E84C(a1);
  sub_9E90B(a1, &v18, &v19);
  *(_WORD *)(dword_19C7C0 + 168) = 5 * v19 + 3 * v18;
  if ( sub_9DB21(a1) )
    v3 = 250;
  else
    v3 = 0;
  *(_WORD *)(dword_19C7C0 + 105) = v3;
  if ( sub_9DB39(a1) )
    v4 = 100;
  else
    v4 = 0;
  *(_WORD *)(dword_19C7C0 + 162) = v4;
  if ( sub_9EC32(a1) )
    v6 = 100;
  else
    v6 = 0;
  v7 = a1;
  v8 = dword_19C7C0;
  *(_WORD *)(dword_19C7C0 + 176) = v6;
  v9 = *(_WORD *)(3753 * a1 + dword_197F98 + 514);
  v10 = (uint8_t)byte_199CB2 + 1;
  *(_WORD *)(v8 + 140) = v9;
  *(_WORD *)(v8 + 108) = 2 * v9 / v10;
  v11 = sub_9E9DA(v7);
  v12 = dword_19C7C0;
  *(_WORD *)(dword_19C7C0 + 160) = v11;
  *(_WORD *)(v12 + 164) = v11;
  v13 = word_199998 * (20 * ((uint8_t)byte_199CB2 + 1) + 80) - (dword_192FD8 + 30536);
  if ( !*(_WORD *)(v12 + 160) )
    v13 = 0;
  v14 = dword_19C7C0;
  *(_WORD *)(dword_19C7C0 + 172) = v13;
  *(_WORD *)(v14 + 170) = *(_WORD *)(v14 + 164)
                        + *(_WORD *)(v14 + 108)
                        + *(_WORD *)(v14 + 176)
                        + *(_WORD *)(v14 + 105)
                        + *(_WORD *)(v14 + 168)
                        + *(_WORD *)(v14 + 118)
                        + v13
                        + *(_WORD *)(v14 + 162);
  v15 = sub_58F4A(*(uint8_t *)(v14 + 104));
  v16 = (int16_t *)dword_19C7C0;
  *(_WORD *)(dword_19C7C0 + 182) = v15;
  result = (v16[91] * v16[85] + 50) / 100;
  v16[87] = result;
  return result;
}
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB2: using guessed type char byte_199CB2;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009DB21) --------------------------------------------------------
char __fastcall sub_9DB21( int a1)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 496);
}
// 197F98: using guessed type int dword_197F98;


//----- (0009DB39) --------------------------------------------------------
char __fastcall sub_9DB39( int a1)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 495);
}
// 197F98: using guessed type int dword_197F98;


//----- (0009DB51) --------------------------------------------------------
int __fastcall sub_9DB51( int a1)
{
  uint16_t v2; // dx

  sub_1112EC(dword_192EE8, 293);
  dword_19C7C0 = (int)sub_110CEE(dword_192EE8, 293);
  sub_9D977(a1);
  v2 = *(_WORD *)(dword_19C7C0 + 174);
  sub_1113CC(dword_192EE8, v2);
  return v2;
}
// 192EE8: using guessed type int dword_192EE8;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009DB96) --------------------------------------------------------
int sub_9DB96()
{
  char *v0; // eax

  v0 = sub_7A990(0x153u);
  return sub_9E207(*(int16_t *)(dword_19C7C0 + 105), v0, 0, 0);
}
// 9E207: using guessed type int __fastcall sub_9E207(_DWORD, _DWORD, _DWORD, _DWORD);
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009DBBB) --------------------------------------------------------
int sub_9DBBB()
{
  return sub_9E3D1(1, 2, *(_WORD *)(dword_19C7C0 + 138));
}
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009DBDB) --------------------------------------------------------
int sub_9DBDB()
{
  uint16_t v0; // ax
  char *v1; // eax
  int v3; // [esp-4h] [ebp-54h]
  _BYTE v4[80]; // [esp+0h] [ebp-50h] BYREF

  v3 = *(int16_t *)(dword_19C7C0 + 140);
  if ( *(_WORD *)(dword_19C7C0 + 140) == 1 )
    v0 = 340;
  else
    v0 = 341;
  v1 = sub_7A990(v0);
  sprintf(v4, v1, v3);
  return sub_9E207(*(int16_t *)(dword_19C7C0 + 108), v4, sub_9DBBB, 360);
}
// 9E207: using guessed type int __fastcall sub_9E207(_DWORD, _DWORD, _DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009DC3F) --------------------------------------------------------
int sub_9DC3F()
{
  int result; // eax
  char *v1; // edx

  result = dword_19C7C0;
  if ( *(int16_t *)(dword_19C7C0 + 176) > 0 )
  {
    v1 = sub_7A990(0x156u);
    return sub_9E207(*(int16_t *)(dword_19C7C0 + 176), v1, 0, 0);
  }
  return result;
}
// 9E207: using guessed type int __fastcall sub_9E207(_DWORD, _DWORD, _DWORD, _DWORD);
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009DC76) --------------------------------------------------------
void sub_9DC76()
{
  int v0; // edx
  int16_t v1; // dx
  int v2; // ecx
  int v3; // eax
  int v4; // edi
  int16_t v5; // si
  char *v6; // eax
  int v7; // esi
  int v8; // ecx
  int16_t v9; // di
  int v10; // ecx
  int16_t v11; // si
  char v12[80]; // [esp+0h] [ebp-56h] BYREF
  _BYTE v13[80]; // [esp+50h] [ebp-6h] BYREF
  char v14[12]; // [esp+A0h] [ebp+4Ah] BYREF
  _BYTE v15[8]; // [esp+ACh] [ebp+56h] BYREF
  int v16; // [esp+B4h] [ebp+5Eh]
  int v17; // [esp+B8h] [ebp+62h]
  int v18; // [esp+BCh] [ebp+66h]
  int v19; // [esp+C0h] [ebp+6Ah]
  char *v20; // [esp+C4h] [ebp+6Eh] BYREF
  int v21; // [esp+C8h] [ebp+72h]
  int v22; // [esp+CCh] [ebp+76h]
  int v23; // [esp+D0h] [ebp+7Ah]
  int i; // [esp+D4h] [ebp+7Eh]

  v0 = *(int16_t *)(dword_19C7C0 + 178) + 6;
  v16 = v0;
  v18 = v0;
  LOWORD(v0) = *(_WORD *)(dword_19C7C0 + 178);
  v19 = v0 + 6;
  sub_120BB5(4, dword_19C7C0 + 110);
  sub_120E8C(1);
  strcpy(v12, sub_7A990(0x157u));
  v23 = sub_12066F((int)v12);
  v17 = 498;
  v1 = *(_WORD *)(dword_19C7C0 + 174);
  i = 140;
  if ( v1 == *(_WORD *)(dword_19C7C0 + 170) )
  {
    sprintf(v13, "%d", v1);
  }
  else
  {
    if ( *(int16_t *)(dword_19C7C0 + 182) >= 100 )
      sprintf(v14, "%d.%d", *(int16_t *)(dword_19C7C0 + 182) / 100, *(int16_t *)(dword_19C7C0 + 182) % 100);
    else
      sprintf(v14, ".%d", *(int16_t *)(dword_19C7C0 + 182));
    sprintf(v13, "(%d x %s) %d", *(int16_t *)(dword_19C7C0 + 170), v14, *(int16_t *)(dword_19C7C0 + 174));
  }
  v2 = (int16_t)v18;
  v3 = sub_12066F((int)v13);
  v4 = (int16_t)v17;
  v22 = v3 + 2;
  v5 = 500 - (v3 + 2);
  sub_134D2D(v5, (int16_t)v16, (int16_t)v17, v2, 209);
  sub_134D2D(v5, (int16_t)(v16 + 1), v4, (int16_t)(v18 + 1), 210);
  sub_134D2D(v5, (int16_t)(v16 + 2), v4, (int16_t)(v18 + 2), 209);
  sub_122259();
  v6 = sub_8E5C5(4u, 208, 209);
  qmemcpy(v15, v6, sizeof(v15));
  LOWORD(v6) = word_179BCB;
  v20 = v6;
  v7 = sub_12066F((int)&v20);
  v21 = v7;
  sub_120BB5(4, dword_19C7C0 + 110);
  LOWORD(v4) = v19;
  v8 = i;
  sub_120E8C(1);
  v9 = v4 + 4;
  v8 += 4;
  sub_1212B3(v8, v9, (int)v12);
  sub_120BB5(4, (int)v15);
  v10 = v7 + v23 + v8;
  sub_120E8C(1);
  for ( i = v10; ; i += v21 )
  {
    v11 = i;
    if ( (int16_t)i >= 500 - (int16_t)v22 )
      break;
    sub_1212B3(i, v9, (int)&v20);
  }
  sub_120BB5(4, dword_19C7C0 + 110);
  sub_120E8C(1);
  sub_1212B3(v11, v9, (int)v13);
  JUMPOUT(0x9D946);
}
// 9DEF2: control flows out of bounds to 9D946
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 179BCB: using guessed type int16_t word_179BCB;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009DEF7) --------------------------------------------------------
void __fastcall sub_9DEF7(int a1, int a2)
{
  int v2; // eax
  int16_t v3; // si
  int v4; // edx
  int v5; // eax
  int16_t *v6; // ebx
  int16_t v7; // di
  int16_t v8; // cx
  int16_t v9; // dx
  int v10; // ebx
  int16_t v11; // ax
  int v12; // ebx
  int16_t v13; // dx
  int16_t v14; // ax
  int v15; // ebx
  _BYTE v16[40]; // [esp+0h] [ebp-64h] BYREF
  int v17; // [esp+28h] [ebp-3Ch]
  int v18; // [esp+2Ch] [ebp-38h]
  int v19; // [esp+30h] [ebp-34h]
  int v20; // [esp+34h] [ebp-30h]
  int v21; // [esp+38h] [ebp-2Ch]
  int v22; // [esp+3Ch] [ebp-28h]
  int v23; // [esp+40h] [ebp-24h]
  int v24; // [esp+44h] [ebp-20h]
  int v25; // [esp+48h] [ebp-1Ch]
  int v26; // [esp+4Ch] [ebp-18h]
  int v27; // [esp+50h] [ebp-14h]
  int v28; // [esp+54h] [ebp-10h]
  int v29; // [esp+58h] [ebp-Ch]
  int v30; // [esp+5Ch] [ebp-8h]
  char v31; // [esp+60h] [ebp-4h]

  HIWORD(v2) = HIWORD(dword_19C7C0);
  LOWORD(a2) = *(uint8_t *)(dword_19C7C0 + 104);
  v3 = 142;
  v28 = a2;
  LOWORD(a2) = *(_WORD *)(dword_19C7C0 + 178);
  v31 = 0;
  v4 = a2 + 2;
  v27 = 0;
  v29 = v4;
  LOWORD(v4) = *(_WORD *)(dword_19C7C0 + 178);
  LOWORD(v2) = v4;
  v30 = v2;
  v24 = v4 + 1;
  v23 = v2 + 3;
  while ( (int16_t)v27 < word_199998 )
  {
    v21 = 3753 * (int16_t)v28;
    v20 = 2 * (int16_t)v27;
    if ( *(_WORD *)(v20 + dword_197F98 + v21 + 498) )
    {
      HIWORD(v5) = HIWORD(dword_19C7C0);
      v6 = *(int16_t **)(dword_19C7C0 + 4 * *(uint8_t *)(dword_197F98 + 3753 * (int16_t)v27 + 37) + 12);
      LOWORD(v5) = v6[1];
      v19 = 3753 * (int16_t)v27;
      v26 = v5;
      v7 = *v6;
      v17 = (int16_t)v29;
      v22 = v3;
      sub_12A478(v3, v29, (int)v6);
      v25 = v26 + v29;
      sub_128AB6(v22, v17, v7 + v3, (int16_t)(v26 + v29));
      sub_12B634();
      sub_120D79(1, dword_19C7C0 + 110);
      sub_120DED(2, 1);
      sub_120E8C(1);
      sprintf(
        v16,
        "%d.%d",
        *(uint16_t *)(v20 + v21 + dword_197F98 + 498) / 10,
        *(uint16_t *)(v20 + v21 + dword_197F98 + 498) % 10);
      v17 = (int16_t)v23;
      v8 = v22 + v7 / 2;
      sub_1210FD(v8, v23, (int)v16);
      sub_120D79(1, dword_19C7C0 + 110);
      sub_120DED(2, 1);
      v31 = 1;
      if ( (int16_t)sub_12066F(v19 + dword_197F98 + 1) <= v7 )
      {
        v12 = v19 + dword_197F98 + 1;
        v13 = v25;
        v14 = sub_122259();
        sub_1210FD(v8, v13 - v14 - 1, v12);
      }
      else
      {
        v9 = v25;
        v10 = dword_197F98;
        v11 = sub_122259();
        sub_1212B3(v3 + 1, v9 - v11 - 1, v19 + v10 + 1);
      }
      sub_128BE7();
      sub_12B65C();
      v15 = *(_DWORD *)(dword_19C7C0 + 68);
      v17 = (int16_t)v24;
      v18 = (int16_t)(v3 - 1);
      sub_12A478(v3 - 1, v24, v15);
      sub_1297C3(v3 - 2, v30, v7 + 3, v26 + 3, 1, 75);
      v3 += v7 + 4;
      sub_1297C3(v18, v17, v7 + 1, v26 + 1, 1, 15);
    }
    ++v27;
  }
  if ( v31 )
    *(_WORD *)(dword_19C7C0 + 178) += v26 + 4;
  JUMPOUT(0x9D945);
}
// 9E177: control flows out of bounds to 9D945
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E17C) --------------------------------------------------------
void sub_9E17C()
{
  uint16_t v0; // ax
  char *v1; // eax
  int v2; // [esp-4h] [ebp-54h]
  char v3[80]; // [esp+0h] [ebp-50h] BYREF

  if ( *(_WORD *)(dword_19C7C0 + 136) )
  {
    v2 = *(int16_t *)(dword_19C7C0 + 136);
    if ( *(_WORD *)(dword_19C7C0 + 136) == 1 )
      v0 = 345;
    else
      v0 = 346;
    v1 = sub_7A990(v0);
    sprintf(v3, v1, v2);
  }
  else
  {
    strcpy(v3, sub_7A990(0x158u));
  }
  sub_9E207(*(int16_t *)(dword_19C7C0 + 118), v3, sub_9DEF7, 360);
  JUMPOUT(0x9D945);
}
// 9E202: control flows out of bounds to 9D945
// 9E207: using guessed type int __fastcall sub_9E207(_DWORD, _DWORD, _DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E207) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=37)) - nutno dohledat rucne v IDA @ 0x9E257 */
int __fastcall sub_9E207(_DWORD, _DWORD, _DWORD, _DWORD)
{
  DECOMP_TODO("call analysis failed (funcsize=37)");
}


//----- (0009E27A) --------------------------------------------------------
void sub_9E27A()
{
  int v0; // eax
  char *v1; // eax
  char *v2; // eax
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  int v6; // [esp-4h] [ebp-54h]
  _BYTE v7[80]; // [esp+0h] [ebp-50h] BYREF

  if ( *(_BYTE *)(dword_19C7C0 + 107) )
  {
    sub_128C32(0, 0, 639, 479, 0);
    *(_BYTE *)(dword_19C7C0 + 107) = 0;
  }
  v0 = sub_12A478(0, 0, *(_DWORD *)(dword_19C7C0 + 4));
  sub_9E68B(v0);
  v6 = *(int16_t *)(dword_19C7C0 + 160);
  v1 = sub_7A990(0x15Cu);
  sprintf(v7, v1, v6);
  sub_9E207(*(int16_t *)(dword_19C7C0 + 164), v7, sub_9E64A, 360);
  sub_9E17C();
  sub_9DBDB();
  v2 = sub_7A990(0x15Du);
  sub_9E207(*(int16_t *)(dword_19C7C0 + 168), v2, 0, 360);
  v3 = sub_7A990(0x15Bu);
  sub_9E207(*(int16_t *)(dword_19C7C0 + 162), v3, 0, 0);
  v4 = sub_7A990(0x153u);
  sub_9E207(*(int16_t *)(dword_19C7C0 + 105), v4, 0, 0);
  if ( *(int16_t *)(dword_19C7C0 + 176) > 0 )
  {
    v5 = sub_7A990(0x156u);
    sub_9E207(*(int16_t *)(dword_19C7C0 + 176), v5, 0, 0);
  }
  sub_9DC76();
  JUMPOUT(0x9DB1B);
}
// 9E3A8: control flows out of bounds to 9DB1B
// 9E207: using guessed type int __fastcall sub_9E207(_DWORD, _DWORD, _DWORD, _DWORD);
// 9E68B: using guessed type int __fastcall sub_9E68B(_DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E3AD) --------------------------------------------------------
void sub_9E3AD()
{
  sub_7A990(0x15Bu);
  JUMPOUT(0x9DC6D);
}
// 9E3CC: control flows out of bounds to 9DC6D
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E3D1) --------------------------------------------------------
int __fastcall sub_9E3D1( int a1, int a2, int a3)
{
  int16_t v3; // si
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  _WORD *v7; // eax
  int v8; // eax
  int result; // eax
  int16_t v10; // [esp+0h] [ebp-34h]
  int16_t i; // [esp+8h] [ebp-2Ch]
  int v12; // [esp+Ch] [ebp-28h]
  int v13; // [esp+24h] [ebp-10h]
  int v14; // [esp+28h] [ebp-Ch]
  int16_t v15; // [esp+2Ch] [ebp-8h]

  v3 = *(_WORD *)(dword_19C7C0 + 178);
  v4 = sub_BBA8E(13);
  sub_133C9C(v4, a2);
  v12 = 0;
  v5 = 0;
  LOWORD(v6) = 0;
  v10 = 0;
  if ( a3 >= 48 * a2 )
  {
    if ( a3 >= 58 * a2 )
    {
      if ( a3 >= 72 * a2 )
      {
        if ( a3 >= 97 * a2 )
        {
          v14 = 4;
          v15 = 4;
          v13 = 4;
        }
        else
        {
          v14 = 6;
          v15 = 6;
          v13 = 6;
        }
      }
      else
      {
        v14 = 8;
        v15 = 8;
        v13 = 8;
      }
    }
    else
    {
      v14 = 10;
      v15 = 10;
      v13 = 10;
    }
  }
  else
  {
    v14 = 12;
    v15 = 12;
    v13 = 12;
  }
  for ( i = 0; i < a3; ++i )
  {
    if ( i < 97 * a2 )
    {
      if ( a1 )
        sub_BB53E();
      else
        v7 = (_WORD *)sub_BB4A9(*(_WORD *)(dword_19C7C0 + 4 * i + 189), *(_WORD *)(dword_19C7C0 + 4 * i + 191));
      if ( a3 > 27 * a2 )
      {
        if ( v10 % 2 )
        {
          LOWORD(v6) = v15;
          sub_12B7E1((int16_t)(v5 + 140), (int16_t)(v3 + v15), v7);
          v8 = v12 + 1;
          v5 += v14;
        }
        else
        {
          sub_12B7E1((int16_t)(v5 + 140), v3, v7);
          v5 += v13;
          v8 = v12 + 1;
          LOWORD(v6) = 0;
        }
        v12 = v8;
        if ( (int16_t)v5 + 24 > 360 )
        {
          v10 = 0;
          v3 += 30;
          v5 = 0;
          LOWORD(v6) = 0;
        }
      }
      else
      {
        v5 = 22 * ((int16_t)v12 % 25);
        v6 = 22 * ((int16_t)v12 / 25);
        sub_12B7E1((int16_t)(v5 + 140), (int16_t)(v6 + v3), v7);
        ++v12;
      }
      ++v10;
    }
  }
  result = dword_19C7C0;
  if ( a3 <= 0 )
    *(_WORD *)(dword_19C7C0 + 178) += 3;
  else
    *(_WORD *)(dword_19C7C0 + 178) = v6 + v3 + 28;
  return result;
}
// 9E54E: variable 'v7' is possibly undefined
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E601) --------------------------------------------------------
void sub_9E601()
{
  char *v0; // eax
  int v1; // [esp-4h] [ebp-54h]
  _BYTE v2[80]; // [esp+0h] [ebp-50h] BYREF

  v1 = *(int16_t *)(dword_19C7C0 + 160);
  v0 = sub_7A990(0x15Cu);
  sprintf(v2, v0, v1);
  JUMPOUT(0x9DC35);
}
// 9E645: control flows out of bounds to 9DC35
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E64A) --------------------------------------------------------
void sub_9E64A()
{
  JUMPOUT(0x9DBD3);
}
// 9E65F: control flows out of bounds to 9DBD3


//----- (0009E664) --------------------------------------------------------
void sub_9E664()
{
  sub_7A990(0x15Du);
  JUMPOUT(0x9DC6D);
}
// 9E686: control flows out of bounds to 9DC6D
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E68B) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=34)) - nutno dohledat rucne v IDA @ 0x9E6F5 */
int __fastcall sub_9E68B(_DWORD)
{
  DECOMP_TODO("call analysis failed (funcsize=34)");
}


//----- (0009E735) --------------------------------------------------------
int __fastcall sub_9E735( int a1)
{
  uint16_t v1; // bx

  v1 = *(_WORD *)(dword_197F98 + 3753 * a1 + 514);
  *(_WORD *)(dword_19C7C0 + 140) = v1;
  return 2 * v1 / ((uint8_t)byte_199CB2 + 1);
}
// 197F98: using guessed type int dword_197F98;
// 199CB2: using guessed type char byte_199CB2;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E76D) --------------------------------------------------------
void sub_9E76D()
{
  int v0; // eax

  byte_199F34 = -16;
  qmemcpy((void *)(dword_19C7C0 + 110), sub_8E5C5(4u, 239, 244), 8u);
  v0 = dword_19C7C0;
  *(_BYTE *)(dword_19C7C0 + 184) = 3;
  *(_BYTE *)(v0 + 185) = 1;
  *(_BYTE *)(v0 + 186) = 0;
  JUMPOUT(0x9D946);
}
// 9E7BB: control flows out of bounds to 9D946
// 199F34: using guessed type char byte_199F34;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E7C0) --------------------------------------------------------
void sub_9E7C0()
{
  qmemcpy((void *)(dword_19C7C0 + 110), sub_8E5C5(4u, 208, 210), 8u);
  qmemcpy((void *)(dword_19C7C0 + 128), sub_8E5C5(4u, 208, 210), 8u);
  byte_199F34 = -13;
  qmemcpy((void *)(dword_19C7C0 + 120), sub_8E5C5(4u, 208, 210), 8u);
  JUMPOUT(0x9D946);
}
// 9E847: control flows out of bounds to 9D946
// 199F34: using guessed type char byte_199F34;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E84C) --------------------------------------------------------
int __fastcall sub_9E84C( int a1)
{
  int v1; // ebx
  int16_t v2; // dx

  v1 = 0;
  v2 = 0;
  *(_WORD *)(dword_19C7C0 + 136) = 0;
  while ( v2 < word_199998 )
  {
    if ( *(_WORD *)(3753 * a1 + dword_197F98 + 2 * v2 + 498) )
    {
      v1 += 50;
      ++*(_WORD *)(dword_19C7C0 + 136);
    }
    ++v2;
  }
  return v1;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E8C7) --------------------------------------------------------
void __fastcall sub_9E8C7( int a1)
{
  int16_t v2; // bx
  int16_t i; // dx
  char *v4; // eax

  v2 = 0;
  for ( i = 0; i < word_199996; ++i )
  {
    v4 = (char *)(361 * i + dword_192B18);
    if ( *v4 == a1 )
      v2 += (uint8_t)v4[10];
  }
  *(_WORD *)(dword_19C7C0 + 160) = v2;
  JUMPOUT(0x9E89C);
}
// 9E909: control flows out of bounds to 9E89C
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E90B) --------------------------------------------------------
int __fastcall sub_9E90B( int a1, _WORD *a2, _WORD *a3)
{
  int16_t v4; // ax
  int result; // eax

  *a2 = 0;
  v4 = 0;
  *a3 = 0;
  do
  {
    if ( *(_BYTE *)(3753 * a1 + dword_197F98 + v4 + 196) == 3 )
      ++*a2;
    ++v4;
  }
  while ( v4 < 83 );
  result = 0;
  do
  {
    if ( *(_BYTE *)((int16_t)result + 3753 * a1 + dword_197F98 + 540) )
      ++*a3;
    ++result;
  }
  while ( (int16_t)result < 8 );
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0009E973) --------------------------------------------------------
int __fastcall sub_9E973( int a1)
{
  int v2; // [esp+0h] [ebp-8h] BYREF
  int v3; // [esp+4h] [ebp-4h] BYREF

  sub_9E90B(a1, &v3, &v2);
  return 5 * v2 + 3 * v3;
}


//----- (0009E993) --------------------------------------------------------
int sub_9E993()
{
  if ( *(_WORD *)(dword_19C7C0 + 160) )
    return (20 * (int16_t)((uint8_t)byte_199CB2 + 1) + 80) * word_199998 - (int16_t)(dword_192FD8 + 30536);
  else
    return 0;
}
// 192FD8: using guessed type int dword_192FD8;
// 199998: using guessed type int16_t word_199998;
// 199CB2: using guessed type char byte_199CB2;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009E9DA) --------------------------------------------------------
int __fastcall sub_9E9DA( int a1)
{
  int v2; // edx
  int16_t i; // bx
  int v4; // eax

  v2 = 0;
  for ( i = 0; i < word_199996; ++i )
  {
    v4 = 361 * i + dword_192B18;
    if ( *(char *)v4 == a1 )
    {
      LOWORD(v4) = *(uint8_t *)(v4 + 10);
      v2 += v4;
    }
  }
  return v2;
}
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (0009EA3B) --------------------------------------------------------
int16_t __usercall sub_9EA3B( int a1, int16_t *a2)
{
  int v3; // ecx
  char v4; // al
  int16_t v5; // dx
  int v6; // ebx
  int v7; // edx
  int v8; // eax
  int16_t v9; // ax
  int v10; // eax

  sub_1196F7();
  sub_9F4AD();
  v3 = 0;
  if ( !v4 )
    sub_9F540();
  sub_1191CA((int)sub_9E27A, 1);
  sub_11C2F0();
  sub_9EB42();
  *(_BYTE *)(dword_19C7C0 + 104) = a1;
  v5 = a1;
  sub_9D977(a1);
  *(_BYTE *)(dword_19C7C0 + 187) = -1;
  sub_9E7C0();
  sub_9D7EA();
  sub_9E9DA(a1);
  v6 = sub_12484C();
  sub_9FCF0(v5);
  sub_124820(v6);
  sub_9D816(v5);
  v7 = dword_19C7C0 + 107;
  sub_8F1C4((void (__fastcall *)(int, int))sub_9E27A, (_BYTE *)(dword_19C7C0 + 107), 12);
  LOBYTE(v8) = sub_133237();
  while ( 1 )
  {
    v9 = sub_1171AB(v8, v7, 12, v3);
    v7 = dword_19C7C0;
    if ( v9 == *(_WORD *)(dword_19C7C0 + 76) )
      v3 = 1;
    if ( (_WORD)v3 )
      break;
    sub_124D41();
    sub_9E27A();
    v8 = sub_1077D(v10, v7, 12, a2);
  }
  sub_124D41();
  sub_9E27A();
  sub_124DEC();
  sub_124C08();
  word_199A08 = word_199A10;
  sub_11C2F0();
  sub_119281();
  return *(_WORD *)(dword_19C7C0 + 174);
}
// 9EA4E: variable 'v4' is possibly undefined
// 9EAD8: variable 'v8' is possibly undefined
// 9EAFD: variable 'v10' is possibly undefined
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009EB42) --------------------------------------------------------
int sub_9EB42()
{
  int v0; // eax
  _DWORD *v1; // eax
  int v2; // eax
  _DWORD *v3; // eax
  int v4; // ebx
  int16_t v5; // si
  int v6; // ecx
  _DWORD *v7; // eax
  _DWORD *v8; // edx
  int result; // eax
  int v10; // ebx

  dword_19C7C0 = (int)sub_110CEE(dword_192ED4, 293);
  memset(dword_19C7C0, 0, 293);
  v0 = sub_12DAA4(600, 300);
  v1 = sub_110D3C(dword_192ED4, v0);
  *(_DWORD *)(dword_19C7C0 + 8) = v1;
  sub_12D8F5(600, 300, (int)v1);
  v2 = sub_12DAA4(50, 50);
  dword_19C150 = (int)sub_110D3C(dword_192ED4, v2);
  v3 = sub_126B42((int)off_182314, 0, dword_192ED4);
  v4 = dword_192ED4;
  *(_DWORD *)(dword_19C7C0 + 4) = v3;
  v5 = 2;
  v6 = 0;
  *(_DWORD *)(dword_19C7C0 + 68) = sub_126B42((int)off_182314, 1, v4);
  do
  {
    v7 = sub_126B42((int)off_182314, v5++, dword_192ED4);
    v8 = v7;
    result = dword_19C7C0;
    v10 = 4 * (int16_t)v6++;
    *(_DWORD *)(v10 + dword_19C7C0 + 12) = v8;
  }
  while ( (int16_t)v6 < 13 );
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 182314: using guessed type char *off_182314;
// 192ED4: using guessed type int dword_192ED4;
// 19C150: using guessed type int dword_19C150;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009EC32) --------------------------------------------------------
char __fastcall sub_9EC32( int a1)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + 497);
}
// 197F98: using guessed type int dword_197F98;


//----- (0009EC4A) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __cdecl sub_9EC4A(
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
        __int128 a25)
{
  char *v25; // eax
  int v26; // ecx
  int16_t v27; // di
  int16_t v28; // si
  char *v30; // [esp+72h] [ebp-46h]
  int16_t v31; // [esp+76h] [ebp-42h]
  int16_t v32; // [esp+7Ah] [ebp-3Eh]
  int16_t v33; // [esp+7Eh] [ebp-3Ah]
  int16_t i; // [esp+7Eh] [ebp-3Ah]
  char v35[54]; // [esp+82h] [ebp-36h] BYREF

  v25 = sub_8E5C5(4u, 208, 209);
  qmemcpy((char *)&a23 + 2, v25, 8u);
  LOWORD(v25) = word_179BCB;
  *(_DWORD *)((char *)&a25 + 6) = v25;
  v26 = sub_12066F((int)&a25 + 6);
  *(_DWORD *)((char *)&a25 + 10) = v26;
  strcpy(v35, v30);
  *(_DWORD *)((char *)&a25 + 2) = sub_12066F((int)v35);
  sprintf((char *)&a3 + 2, "%d", v31);
  *(_DWORD *)((char *)&a25 + 14) = sub_12066F((int)&a3 + 2) + 3;
  v27 = v32 + 4;
  sub_120BB5(4, dword_19C7C0 + 110);
  sub_120E8C(1);
  sub_1212B3(v33 + 4, v32 + 4, (int)v35);
  sub_120BB5(4, (int)&a23 + 2);
  v28 = v26 + WORD1(a25) + v33 + 4;
  sub_120E8C(1);
  for ( i = v28; i < 499 - SHIWORD(a25); i += WORD5(a25) )
    sub_1212B3(i, v27, (int)&a25 + 6);
  sub_120BB5(4, dword_19C7C0 + 110);
  sub_120E8C(1);
  return sub_1210B7(499, v27, (int)&a3 + 2);
}
// 9ECDF: inconsistent variable size for '^144.16'
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 179BCB: using guessed type int16_t word_179BCB;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009ED88) --------------------------------------------------------
int16_t __fastcall sub_9ED88( int a1)
{
  sub_1112EC(dword_192ED4, 293);
  dword_19C7C0 = (int)sub_110D3C(dword_192ED4, 293);
  memset(dword_19C7C0, 0, 293);
  *(_BYTE *)(dword_19C7C0 + 104) = a1;
  sub_9D977(a1);
  sub_1113CC(dword_192ED4, 0);
  return *(_WORD *)(dword_19C7C0 + 174);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009EDE1) --------------------------------------------------------
int sub_9EDE1()
{
  _DWORD *v0; // eax
  int v1; // ebx
  _DWORD *v2; // edx
  int result; // eax

  dword_19C7C0 = (int)sub_110CEE(dword_192ED4, 293);
  memset(dword_19C7C0, 0, 293);
  v0 = sub_126B42((int)aScoreLbx, 15, dword_192ED4);
  v1 = dword_192ED4;
  *(_DWORD *)(dword_19C7C0 + 72) = v0;
  v2 = sub_126B42((int)aScoreLbx, 16, v1);
  result = dword_19C7C0;
  *(_DWORD *)dword_19C7C0 = v2;
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009EE43) --------------------------------------------------------
void sub_9EE43()
{
  int16_t v0; // di
  int16_t i; // si
  int16_t v2; // si
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  char v6; // cl
  int16_t v7; // ax
  char *v8; // ebx
  int16_t v9; // ax
  int v10; // ecx
  int16_t v11; // cx
  int16_t v12; // ax
  int16_t v13; // si
  _BYTE *v14; // ebx
  int16_t v15; // [esp+Ch] [ebp-24h]
  char v16; // [esp+10h] [ebp-20h]
  int16_t v17; // [esp+14h] [ebp-1Ch]
  int16_t v18; // [esp+18h] [ebp-18h]
  int16_t v19; // [esp+1Ch] [ebp-14h]
  int16_t v20; // [esp+20h] [ebp-10h]
  int16_t v21; // [esp+2Ch] [ebp-4h]

  v0 = 4;
  v17 = 2;
  v18 = 2;
  for ( i = 0; i < 10; ++i )
  {
    v15 = *(_WORD *)(dword_19C7C0 + 4 * i + 255);
    sub_8FDA1((int)&byte_19C6F8[20 * v15], dword_19C7C0 + 110, 4, 2, -1, 67, 1);
    if ( sub_8F64C() < v0 )
      v0 = sub_8F64C();
    if ( sub_8F645() < v17 )
      v17 = sub_8F645();
    sub_8FDA1((int)&unk_19C7C6 + 15 * (uint8_t)byte_19C6EE[v15], dword_19C7C0 + 110, 4, 2, -1, 86, 1);
    if ( sub_8F64C() < v0 )
      v0 = sub_8F64C();
    if ( sub_8F645() < v18 )
      v18 = sub_8F645();
  }
  if ( *(_BYTE *)(dword_19C7C0 + 107) || *(char *)(dword_19C7C0 + 187) < -2 )
  {
    *(_BYTE *)(dword_19C7C0 + 187) = -1;
    sub_128C32(0, 0, 639, 479, 0);
    sub_12A478(0, 0, *(_DWORD *)(dword_19C7C0 + 72));
    word_19994C = 0;
  }
  v20 = 0;
  v19 = 135;
  do
  {
    v2 = v19;
    v21 = *(_WORD *)(dword_19C7C0 + 4 * v20 + 255);
    if ( v21 == word_19C7C4 )
      v16 = *(_BYTE *)(dword_19C7C0 + 184);
    else
      v16 = 0;
    v3 = 1;
    *(_BYTE *)(dword_19C7C0 + 120) = *(_BYTE *)(dword_19C7C0 + 110);
    do
    {
      v4 = dword_19C7C0;
      v5 = (int16_t)v3;
      v6 = v16 + *(_BYTE *)(dword_19C7C0 + (int16_t)v3++ + 110);
      *(_BYTE *)(dword_19C7C0 + v5 + 120) = v6;
    }
    while ( (int16_t)v3 < 8 );
    sub_120BB5(4, v4 + 120);
    sub_120E8C(1);
    sub_128AB6(164, v19, 281, (int16_t)(v19 + 20));
    sub_12B634();
    sub_1212B3(164, v19, (int)&byte_19C5FE[20 * v21]);
    if ( byte_199CAE )
    {
      sub_120BB5(v0, dword_19C7C0 + 120);
      sub_120E8C(v17);
    }
    sub_128AB6(292, v19, 354, (int16_t)(v19 + 20));
    sub_12B634();
    v7 = sub_122259();
    sub_1212B3(292, v19 + 16 - v7, (int)&byte_19C6F8[20 * v21]);
    if ( byte_199CAE )
    {
      sub_120BB5(v0, dword_19C7C0 + 120);
      sub_120E8C(v18);
    }
    sub_128AB6(364, v19, 449, (int16_t)(v19 + 20));
    sub_12B634();
    v8 = (char *)&unk_19C7C6 + 15 * (uint8_t)byte_19C6EE[v21];
    v9 = sub_122259();
    sub_1212B3(364, v19 + 16 - v9, (int)v8);
    if ( byte_199CAE )
    {
      sub_120BB5(4, dword_19C7C0 + 120);
      sub_120E8C(1);
    }
    v10 = (int16_t)(v19 + 20);
    v19 += 29;
    sub_128AB6(458, v2, 500, v10);
    sub_12B634();
    ++v20;
    sub_121153(500, v2, word_19C6C6[v21], v10);
  }
  while ( v20 < 10 );
  sub_128BE7();
  sub_12B65C();
  if ( !*(_BYTE *)(dword_19C7C0 + 107) )
  {
    sub_128AB6(0, 0, 640, 480);
    sub_12B634();
    v11 = sub_123ABA();
    v12 = sub_123AE7();
    v13 = v12;
    if ( v11 > 636 )
      v11 = 636;
    if ( v12 > 476 )
      v13 = 476;
    sub_12A478(v11, v13, *(_DWORD *)dword_19C7C0);
    sub_128BE7();
    sub_12B65C();
  }
  if ( word_19C7C4 > -1 && word_19C7C4 < 10 )
  {
    v14 = (_BYTE *)dword_19C7C0;
    ++*(_BYTE *)(dword_19C7C0 + 186);
    if ( !((uint8_t)v14[186] % 6) )
    {
      v14[184] += v14[185];
      if ( (char)v14[184] == -1 )
      {
        v14[185] = 1;
LABEL_40:
        v14[186] = 0;
        goto LABEL_41;
      }
      if ( v14[184] == 6 )
      {
        v14[185] = -1;
        goto LABEL_40;
      }
    }
  }
LABEL_41:
  *(_BYTE *)(dword_19C7C0 + 107) = 0;
  JUMPOUT(0x9D945);
}
// 9F281: control flows out of bounds to 9D945
// 19994C: using guessed type int16_t word_19994C;
// 199CAE: using guessed type char byte_199CAE;
// 19C6C6: using guessed type int16_t word_19C6C6[];
// 19C7C0: using guessed type int dword_19C7C0;
// 19C7C4: using guessed type int16_t word_19C7C4;


//----- (0009F286) --------------------------------------------------------
void __fastcall sub_9F286( int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  char v5; // al
  int16_t v6; // ax
  int v7; // edx
  int v8; // eax
  int16_t v9; // cx
  uint16_t v10; // dx
  int v11; // eax
  int16_t v12; // si
  int v13; // eax

  word_19C7C4 = a1;
  strcpy(byte_19C7C6, (char *)sub_CDF5C(545));
  strcpy(byte_19C7D5, (char *)sub_CDF5C(280));
  strcpy(byte_19C7E4, (char *)sub_CDF5C(190));
  strcpy(byte_19C7F3, (char *)sub_CDF5C(318));
  v4 = 0;
  strcpy((char *)word_19C802, (char *)sub_CDF5C(328));
  sub_9F4AD();
  if ( v5 )
    v6 = word_19C5FC;
  else
    v6 = 0;
  if ( v6 != 130 )
    sub_9F540();
  sub_113E92();
  sub_1196F7();
  sub_9F4AD();
  HIWORD(v7) = 0;
  sub_1191CA((int)sub_9EE43, 1);
  sub_9EDE1();
  sub_9F981();
  *(_WORD *)(dword_19C7C0 + 78) = -1000;
  while ( 1 )
  {
    v8 = dword_19C7C0;
    LOWORD(v7) = *(_WORD *)(dword_19C7C0 + 78);
    *(_WORD *)(dword_19C7C0 + 82) = v7;
    v9 = sub_1171AB(v8, v7, v4, a4);
    v10 = (uint16_t)sub_114177();
    v11 = dword_19C7C0;
    *(_WORD *)(dword_19C7C0 + 78) = v10;
    if ( v10 != *(_WORD *)(v11 + 82) )
      *(_BYTE *)(v11 + 187) = -1;
    if ( v9 == *(_WORD *)(dword_19C7C0 + 76) )
    {
      v4 = 1;
    }
    else if ( v9 == *(_WORD *)(dword_19C7C0 + 80) )
    {
      sub_9F540();
      word_19C7C4 = -1;
      *(_WORD *)(dword_19C7C0 + 180) = 0;
      sub_9F981();
    }
    v7 = 0;
    do
    {
      a4 = 2 * (int16_t)v7;
      v12 = *(_WORD *)(dword_19C7C0 + 78);
      if ( v12 == *(_WORD *)(a4 + dword_19C7C0 + 84)
        && v12 == *(_WORD *)(dword_19C7C0 + 82)
        && *(int16_t *)(dword_19C7C0 + 180) > 1000 )
      {
        *(_BYTE *)(dword_19C7C0 + 187) = v7;
      }
      ++v7;
    }
    while ( (int16_t)v7 < 10 );
    if ( (_WORD)v4 )
    {
      sub_C5BB9();
      word_199A08 = word_199A10;
      sub_11C2F0();
      sub_119281();
      JUMPOUT(0x9D946);
    }
    sub_124D41();
    sub_9EE43();
    sub_1077D(v13, v7, v4, word_19C802);
  }
}
// 9F442: control flows out of bounds to 9D946
// 9F321: variable 'v5' is possibly undefined
// 9F419: variable 'v13' is possibly undefined
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 19C5FC: using guessed type int16_t word_19C5FC;
// 19C7C0: using guessed type int dword_19C7C0;
// 19C7C4: using guessed type int16_t word_19C7C4;
// 19C802: using guessed type int16_t word_19C802[8];


//----- (0009F447) --------------------------------------------------------
int __fastcall sub_9F447(int16_t *a1, int16_t *a2)
{
  int v2; // ebx
  int v3; // ecx
  int v4; // esi
  int v5; // edx
  int result; // eax

  v2 = *a1;
  v3 = *a2;
  v4 = a1[1];
  v5 = a2[1];
  result = 0;
  if ( v2 > v3 )
    return -1;
  if ( v2 < v3 )
    return 1;
  if ( v2 == v3 )
  {
    if ( v4 > v5 )
      return -1;
    if ( v4 < v5 )
      return 1;
  }
  return result;
}


//----- (0009F47A) --------------------------------------------------------
int __fastcall sub_9F47A(int16_t *a1, int16_t *a2)
{
  int v2; // ebx
  int v3; // ecx
  int v4; // esi
  int v5; // edx
  int result; // eax

  v2 = *a1;
  v3 = *a2;
  v4 = a1[1];
  v5 = a2[1];
  result = 0;
  if ( v2 > v3 )
    return 1;
  if ( v2 < v3 )
    return -1;
  if ( v2 == v3 )
  {
    if ( v4 > v5 )
      return 1;
    if ( v4 < v5 )
      return -1;
  }
  return result;
}


//----- (0009F4AD) --------------------------------------------------------
void sub_9F4AD()
{
  int v0; // eax
  int v1; // esi
  _BYTE v2[40]; // [esp+0h] [ebp-28h] BYREF

  v0 = fopen(aHofM2, &unk_179BCD);
  v1 = v0;
  if ( v0 )
  {
    fread(&word_19C5FC, 452, 1, v0);
    fclose(v1);
    sub_9FBE9((int)v2);
    sub_9FC27();
  }
  JUMPOUT(0x9DB1B);
}
// 9F4CC: control flows out of bounds to 9DB1B
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 19C5FC: using guessed type int16_t word_19C5FC;


//----- (0009F505) --------------------------------------------------------
int sub_9F505()
{
  int result; // eax
  int v1; // esi

  result = fopen(aHofM2, aWb_2);
  v1 = result;
  if ( result )
  {
    fwrite(&word_19C5FC, 452, 1, result);
    return fclose(v1);
  }
  return result;
}
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);
// 19C5FC: using guessed type int16_t word_19C5FC;


