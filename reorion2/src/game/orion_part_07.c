#include "orion_common.h"

/* Adresni rozsah: 0x79E32 - 0x88B0A  (200 funkci) */

//----- (00079E32) --------------------------------------------------------
char __fastcall sub_79E32( int a1, int a2)
{
  return (1 << a1) & *(_BYTE *)(113 * a2 + dword_19306C + 51);
}
// 19306C: using guessed type int dword_19306C;


//----- (00079E4D) --------------------------------------------------------
_BOOL1 __fastcall sub_79E4D( int a1, int a2)
{
  char v2; // al

  v2 = (1 << a1) & *(_BYTE *)(113 * a2 + dword_19306C + 51);
  return *(_BYTE *)(dword_19306C + 113 * a2 + 40) == 9 && v2;
}
// 19306C: using guessed type int dword_19306C;


//----- (00079E8D) --------------------------------------------------------
int __fastcall sub_79E8D( int a1)
{
  int v2; // ebx
  int16_t i; // dx
  int j; // eax
  int16_t v6; // [esp+4h] [ebp-4h]

  v2 = -1;
  for ( i = 0; i < 5 && (int16_t)v2 == -1; ++i )
  {
    v6 = *(_WORD *)(dword_19306C + 113 * a1 + 2 * i + 74);
    if ( v6 > -1 )
    {
      for ( j = 0; (int16_t)j < word_199998; ++j )
      {
        if ( *(_WORD *)(3753 * (int16_t)j + dword_197F98 + 41) == v6 )
          v2 = j;
      }
    }
  }
  return v2;
}
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00079F05) --------------------------------------------------------
int __fastcall sub_79F05(unsigned int a1)
{
  int v2; // edx

  v2 = sub_12484C();
  LOWORD(a1) = sub_1247A0(a1);
  sub_124820(v2);
  return (int16_t)a1;
}


//----- (00079F26) --------------------------------------------------------
int __fastcall sub_79F26(int a1, int a2, int a3)
{
  int16_t i; // cx
  uint64_t v6; // rax
  int v7; // eax
  int16_t v8; // bx
  int result; // eax
  unsigned int v10; // [esp+0h] [ebp-Ch]

  for ( i = 0; ; ++i )
  {
    result = 3 * a2 / 2;
    if ( result <= i )
      break;
    if ( a3 )
    {
      v6 = j___clock(result, 0, a2);
      v10 = v6 % (unsigned int)a2;
      v7 = j___clock(v6 / (unsigned int)a2, 0, a2) % (uint64_t)(unsigned int)a2;
    }
    else
    {
      v10 = sub_1247A0(a2) - 1;
      LOWORD(v7) = sub_1247A0(a2) - 1;
    }
    if ( (_WORD)v7 != (_WORD)v10 )
    {
      v8 = *(_WORD *)(a1 + 2 * (int16_t)v10);
      *(_WORD *)(a1 + 2 * (int16_t)v10) = *(_WORD *)(a1 + 2 * (int16_t)v7);
      *(_WORD *)(a1 + 2 * (int16_t)v7) = v8;
    }
  }
  return result;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);


//----- (00079FA6) --------------------------------------------------------
int sub_79FA6()
{
  int v0; // edx
  int v2; // [esp+0h] [ebp-4h] BYREF

  v0 = fopen(aSeed_0, aRt_0);
  fscanf(v0, "%ld", &v2);
  fclose(v0);
  return v2;
}
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 138E95: using guessed type _DWORD fscanf(_DWORD, char *, ...);


//----- (00079FDB) --------------------------------------------------------
int sub_79FDB()
{
  int16_t i; // dx
  int result; // eax

  for ( i = 0; i < word_19999A; ++i )
  {
    result = 113 * i + dword_19306C;
    *(_BYTE *)(result + 51) |= 1 << word_19999C;
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;


//----- (0007A00A) --------------------------------------------------------
int __fastcall sub_7A00A( int a1, int a2, unsigned int a3)
{
  char v4[8]; // [esp+0h] [ebp-8h] BYREF

  switch ( word_199992 )
  {
    case 10:
      a3 = 3;
      break;
    case 15:
    case 20:
      a3 = 2;
      break;
    case 30:
      a3 = 1;
      break;
  }
  sub_79138(a1, a3, v4, a2);
  return sub_120BB5(a3, (int)v4);
}
// 199992: using guessed type int16_t word_199992;


//----- (0007A06C) --------------------------------------------------------
char sub_7A06C()
{
  int16_t v0; // ax
  int16_t v1; // dx

  if ( (uint8_t)byte_199BF0 >= 0x64u )
    v0 = 100;
  else
    v0 = (uint8_t)byte_199BF0;
  v1 = v0;
  if ( byte_199BEF )
    sub_113CFB();
  else
    sub_113D23();
  sub_113C6B(v1);
  sub_113AF2(v1);
  if ( byte_199BED )
  {
    sub_112269();
    sub_112857(-1);
  }
  else
  {
    sub_112816();
  }
  return sub_112686((uint8_t)byte_199BEE);
}
// 199BED: using guessed type char byte_199BED;
// 199BEE: using guessed type char byte_199BEE;
// 199BEF: using guessed type char byte_199BEF;
// 199BF0: using guessed type char byte_199BF0;


//----- (0007A0D9) --------------------------------------------------------
int16_t __fastcall sub_7A0D9( int a1)
{
  int v1; // edx
  int16_t result; // ax
  int v3; // edx

  v1 = a1;
  result = -1;
  if ( v1 > -1 )
  {
    v3 = *(int16_t *)(361 * v1 + dword_192B18 + 2);
    if ( v3 > -1 )
      return *(uint8_t *)(dword_1930D4 + 17 * v3 + 2);
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;


//----- (0007A115) --------------------------------------------------------
_BOOL1 __fastcall sub_7A115( int a1)
{
  return strcmp(dword_19306C + 113 * a1, aOrion) == 0;
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;


//----- (0007A133) --------------------------------------------------------
_BOOL1 __fastcall sub_7A133( int a1)
{
  char v2; // bl
  int16_t v3; // ax
  char v4; // bh
  int v5; // edx
  int v6; // edx

  v2 = 0;
  v3 = 0;
  v4 = 0;
  do
  {
    v5 = *(int16_t *)(113 * a1 + dword_19306C + 2 * v3 + 74);
    if ( v5 != -1 )
    {
      v6 = *(int16_t *)(17 * v5 + dword_1930D4);
      if ( v6 != -1 )
      {
        if ( *(_BYTE *)(dword_192B18 + 361 * v6 + 6) )
          ++v2;
        else
          ++v4;
      }
    }
    ++v3;
  }
  while ( v3 < 5 );
  return v2 && !v4;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0007A1A8) --------------------------------------------------------
int __fastcall sub_7A1A8( int a1, int a2)
{
  int v3; // esi
  _BOOL1 v4; // al
  int v5; // ebx
  int16_t v6; // cx
  int i; // edx
  _WORD v9[8]; // [esp+0h] [ebp-14h] BYREF
  int16_t v10; // [esp+10h] [ebp-4h] BYREF

  v3 = -1;
  v4 = sub_94877(a2) || *(_BYTE *)(dword_197F98 + 3753 * a2 + 2234);
  sub_799F7(a1, (int)v9, &v10, !v4);
  if ( (int16_t)v9[word_19999C] <= 0 )
  {
    v5 = -1;
    v6 = 0;
    for ( i = 0; (int16_t)i < word_199998; ++i )
    {
      if ( v6 < (int16_t)v9[(int16_t)i] )
      {
        v5 = i;
        v6 = v9[(int16_t)i];
      }
    }
    if ( (int16_t)v5 > -1 )
      return v5;
  }
  else
  {
    LOWORD(v3) = word_19999C;
  }
  return v3;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;


//----- (0007A25F) --------------------------------------------------------
int __fastcall sub_7A25F(_BYTE *a1, int a2, int a3)
{
  int v4; // eax
  int v5; // ebx
  int v6; // ebx
  char v8[100]; // [esp+0h] [ebp-68h] BYREF
  int v9; // [esp+64h] [ebp-4h]

  v9 = -1;
  switch ( a3 )
  {
    case 1:
      sub_124B65();
      *a1 = 1;
      sub_77658(a2);
      v9 = v4;
      goto LABEL_12;
    case 2:
      strcpy(v8, (char *)&word_18FF78);
      sub_124B65();
      *a1 = 1;
      sub_A5EB2((int)v8, a2);
      goto LABEL_12;
    case 3:
      sub_124B65();
      *a1 = 1;
      sub_77433(a2);
      goto LABEL_12;
    case 4:
      if ( byte_199F09 < 0 )
        byte_199F09 = 126;
      sub_124B65();
      v5 = byte_199F09;
      *a1 = 1;
      sub_A5EBC(v8, a2, v5);
      goto LABEL_12;
    case 5:
      if ( byte_199F09 < 0 )
        byte_199F09 = 126;
      sub_124B65();
      v6 = byte_199F09;
      *a1 = 1;
      sub_A5EBC(0, a2, v6);
      *a1 = 1;
      sub_124C08();
      byte_199F09 = 0;
      return v9;
    default:
      sub_124B65();
      *a1 = 1;
      sub_77423(a2);
LABEL_12:
      *a1 = 1;
      sub_124C08();
      return v9;
  }
}
// 7A293: variable 'v4' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// A5EBC: using guessed type int __fastcall sub_A5EBC(_DWORD, _DWORD, _DWORD);
// 18FF78: using guessed type int16_t word_18FF78;
// 199F09: using guessed type char byte_199F09;


//----- (0007A352) --------------------------------------------------------
int __fastcall sub_7A352(int a1)
{
  int v2; // [esp+0h] [ebp-8h] BYREF
  int v3; // [esp+4h] [ebp-4h] BYREF

  v3 = 2;
  sub_7A371(a1, (int)&v2, (int16_t *)&v3);
  return v2;
}


//----- (0007A371) --------------------------------------------------------
int __fastcall sub_7A371(int result, int a2, int16_t *a3)
{
  int16_t v3; // si
  int16_t i; // cx
  int v5; // edx

  v3 = *a3;
  if ( *a3 < 1 || v3 > word_199994 )
    v3 = word_199994;
  *a3 = 0;
  for ( i = 0; i < word_199994 && v3 >= *a3; ++i )
  {
    v5 = 113 * i + dword_19306C;
    if ( *(_WORD *)(v5 + 15) == *(_WORD *)(result + 15) && *(_WORD *)(v5 + 17) == *(_WORD *)(result + 17) )
      *(_WORD *)(a2 + 2 * (*a3)++) = i;
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 199994: using guessed type int16_t word_199994;


//----- (0007A3E3) --------------------------------------------------------
int __fastcall sub_7A3E3( int a1, int a2)
{
  int v3; // ebx
  int16_t v4; // si
  int i; // edx
  int v6; // eax

  v3 = -1;
  v4 = 0;
  for ( i = 0; (int16_t)i < word_19999A + 1 && !v4; ++i )
  {
    v6 = dword_19306C + 113 * (int16_t)i;
    if ( a1 == *(_WORD *)(v6 + 15) && *(_WORD *)(v6 + 17) == a2 )
    {
      v4 = 1;
      v3 = i;
    }
  }
  return v3;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (0007A440) --------------------------------------------------------
int sub_7A440()
{
  int result; // eax

  switch ( word_199992 )
  {
    case 10:
      return 3;
    case 15:
    case 20:
      return 2;
    case 30:
      return 1;
  }
  return result;
}
// 199992: using guessed type int16_t word_199992;


//----- (0007A47A) --------------------------------------------------------
void __fastcall sub_7A47A( int a1, _WORD *a2)
{
  char v2; // cl
  int16_t i; // si
  int16_t v4; // bx
  int v5; // eax
  int16_t j; // [esp+4h] [ebp-4h]

  *a2 = 0;
  v2 = 0;
  for ( i = 0; ; ++i )
  {
    if ( i >= word_199A02 || v2 )
      JUMPOUT(0x7A43A);
    v4 = word_192248[i];
    for ( j = *(int16_t *)((char *)&word_1975D4 + 5 * v4); ; j = *(int16_t *)((char *)&word_1975D4 + 5 * v4) )
    {
      v5 = dword_197F9C + 129 * j;
      if ( !*(_BYTE *)(v5 + 100) && *(char *)(v5 + 99) >= 8 && *(_WORD *)(v5 + 101) == a1 )
        break;
      v4 = *(int16_t *)((char *)&word_1975D6 + 5 * v4);
      if ( v4 == -1 )
        goto LABEL_9;
    }
    v2 = 1;
    *a2 = *(char *)(v5 + 99);
LABEL_9:
    ;
  }
}
// 7A51E: control flows out of bounds to 7A43A
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;
// 199A02: using guessed type int16_t word_199A02;


//----- (0007A523) --------------------------------------------------------
char __fastcall sub_7A523( int a1)
{
  char v2; // bl
  int16_t i; // ax

  v2 = 0;
  for ( i = 0; i < word_1999F8; ++i )
  {
    if ( a1 == word_1906C4[6 * i] )
      v2 = 1;
  }
  return v2;
}
// 1906C4: using guessed type int16_t word_1906C4[];
// 1999F8: using guessed type int16_t word_1999F8;


//----- (0007A54F) --------------------------------------------------------
int sub_7A54F()
{
  int v0; // edx
  int16_t i; // bx
  int v2; // eax

  v0 = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    v2 = dword_197F98 + 3753 * i;
    if ( *(_BYTE *)(v2 + 40) == 100 && !*(_BYTE *)(v2 + 36) )
      ++v0;
  }
  return v0;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0007A586) --------------------------------------------------------
_DWORD *__fastcall sub_7A586(int a1, int a2, int a3, _WORD *a4, _WORD *a5)
{
  int v5; // eax
  int16_t v8; // [esp+4h] [ebp-8h] BYREF
  int16_t v9; // [esp+8h] [ebp-4h] BYREF

  sub_1112EC(dword_192ED4, a2);
  v5 = sub_12DAA4(a2, a3);
  dword_1932D0 = (int)sub_110D3C(dword_192ED4, v5 + 100);
  sub_12D8F5(a2, a3, dword_1932D0);
  sub_12F578(dword_1932D0, a1);
  sub_131528((_WORD *)dword_1932D0, &v9, &v8, a4, a5);
  return sub_1113CC(dword_192ED4, (int)&v9);
}
// 192ED4: using guessed type int dword_192ED4;
// 1932D0: using guessed type int dword_1932D0;


//----- (0007A5F7) --------------------------------------------------------
int __fastcall sub_7A5F7( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // eax
  int v8; // ebx
  int v9; // esi
  int v10; // edx
  char v11; // al
  int v12; // edi
  _BYTE v16[8]; // [esp+8h] [ebp-40h] BYREF
  int v17; // [esp+10h] [ebp-38h]
  int v18; // [esp+14h] [ebp-34h]
  int v19; // [esp+18h] [ebp-30h]
  int v20; // [esp+1Ch] [ebp-2Ch]
  int v21; // [esp+20h] [ebp-28h]
  int v22; // [esp+24h] [ebp-24h]
  int v23; // [esp+28h] [ebp-20h]
  int v24; // [esp+2Ch] [ebp-1Ch]
  int v25; // [esp+30h] [ebp-18h]
  int v26; // [esp+34h] [ebp-14h]
  int v27; // [esp+38h] [ebp-10h]
  int v28; // [esp+3Ch] [ebp-Ch]
  int v29; // [esp+40h] [ebp-8h]
  int v30; // [esp+44h] [ebp-4h]

  v29 = a4;
  v7 = 7 - a6;
  if ( v7 <= 0 )
    v7 = 0;
  v8 = 7;
  v30 = v7;
  v9 = 0;
  do
  {
    v10 = (int16_t)v8--;
    v11 = *(_BYTE *)(a5 + (int16_t)v9++);
    v16[v10] = v11;
  }
  while ( (int16_t)v9 < 8 );
  v18 = a2;
  v25 = a3;
  v19 = a1;
  sub_135870(a1, a2, a3, a2, a5, a6);
  v21 = (int16_t)v30;
  v26 = (int16_t)(a2 + 1);
  v23 = (int16_t)(a3 - 1);
  v22 = (int16_t)(a1 + 1);
  sub_135870(v22, v26, v23, v26, a5, (int16_t)v30);
  v24 = (int16_t)(a2 + 2);
  v27 = (int16_t)(a3 - 2);
  v20 = (int16_t)(a1 + 2);
  sub_135870(v20, v24, v27, v24, a5, a6);
  v17 = (int16_t)v29;
  sub_135870(v25, v18, v25, (int16_t)v29, a5, a6);
  v12 = (int16_t)(v29 - 1);
  sub_135870(v23, v26, v23, v12, a5, v21);
  v28 = (int16_t)(v29 - 2);
  sub_135870(v27, v24, v27, v28, a5, a6);
  sub_135870(v19, v17, v25, v17, (int)v16, a6);
  sub_135870(v22, v12, v23, v12, (int)v16, v21);
  sub_135870(v20, v28, v27, v28, (int)v16, a6);
  sub_135870(v19, v18, v19, v17, (int)v16, a6);
  sub_135870(v22, v26, v22, v12, (int)v16, v21);
  return sub_135870(v20, v24, v20, v28, (int)v16, a6);
}


//----- (0007A795) --------------------------------------------------------
int sub_7A795()
{
  int result; // eax

  if ( SHIWORD(dword_1B9222) <= 10 )
    result = SHIWORD(dword_1B9222);
  else
    result = 10;
  word_19BFC0 = result;
  qmemcpy(&unk_19BF0C, (void *)dword_1B9204, 12 * (int16_t)result);
  return result;
}
// 19BFC0: using guessed type int16_t word_19BFC0;
// 1B9204: using guessed type int dword_1B9204;
// 1B9222: using guessed type int dword_1B9222;


//----- (0007A7CF) --------------------------------------------------------
int16_t sub_7A7CF()
{
  int16_t result; // ax

  result = sub_123E6C((int)&unk_19BF0C, word_19BFC0);
  word_19BFC0 = 0;
  return result;
}
// 19BFC0: using guessed type int16_t word_19BFC0;


//----- (0007A7EC) --------------------------------------------------------
void sub_7A7EC()
{
  word_19BFC0 = 0;
}
// 19BFC0: using guessed type int16_t word_19BFC0;


//----- (0007A7F6) --------------------------------------------------------
_BOOL1 sub_7A7F6()
{
  return word_19BFC0 != 0;
}
// 19BFC0: using guessed type int16_t word_19BFC0;


//----- (0007A816) --------------------------------------------------------
void sub_7A816()
{
  char v0; // al
  int16_t v1; // di
  int v2; // esi
  char v3; // dl
  int v4; // eax
  int64_t v5; // rax
  char v6[200]; // [esp+0h] [ebp-66h] BYREF
  char v7[20]; // [esp+C8h] [ebp+62h] BYREF
  int v8; // [esp+DCh] [ebp+76h]
  int v9; // [esp+E0h] [ebp+7Ah]
  int v10; // [esp+E4h] [ebp+7Eh]

  v10 = 0;
  v9 = 0;
  v0 = byte_199CAE;
  v8 = 0;
  if ( (uint8_t)byte_199CAE >= 6u )
  {
    byte_199CAE = 0;
    v0 = 0;
  }
  switch ( v0 )
  {
    case 1:
      strcpy(v7, "HGSTRNGS.LBX");
      v1 = 15617;
      v2 = 416;
      break;
    case 2:
      strcpy(v7, "HFSTRNGS.LBX");
      v1 = 16525;
      v2 = 280;
      break;
    case 3:
      strcpy(v7, "HSSTRNGS.LBX");
      v1 = 15592;
      v2 = 417;
      break;
    case 4:
      strcpy(v7, "HISTRNGS.LBX");
      v1 = 14031;
      v2 = 370;
      break;
    default:
      strcpy(v7, "HESTRNGS.LBX");
      v1 = 13521;
      v2 = 385;
      break;
  }
  memset(byte_19341C, 0, sizeof(byte_19341C));
  v3 = 0;
  sub_126C91((int)v7, 0, (int)byte_19341C, 0, 1u, v1);
  while ( !v3 )
  {
    v4 = 0;
    while ( byte_19341C[(int16_t)v10] && (unsigned int)(int16_t)v10 < 0x4074 )
    {
      ++v10;
      ++v4;
    }
    if ( (int16_t)v10 + 1 > 16500 )
      break;
    if ( v4 > v2 )
    {
      v5 = sprintf(v6, "(%s) String #%d Too Long, check terminator (strlen: %i)", v7, (int16_t)v9, v4);
      sub_126487(v6, SHIDWORD(v5));
    }
    ++v10;
    word_1992FC[(int16_t)v9++] = v8;
    v8 = (int16_t)v10;
    if ( (_WORD)v9 == 397 )
      v3 = 1;
  }
  JUMPOUT(0x78F45);
}
// 7A98B: control flows out of bounds to 78F45
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1992FC: using guessed type int16_t word_1992FC[462];
// 199CAE: using guessed type char byte_199CAE;


//----- (0007A990) --------------------------------------------------------
char *__fastcall sub_7A990( unsigned int a1)
{
  uint16_t v1; // dx

  v1 = 0;
  if ( a1 <= 0x18Cu )
    v1 = word_1992FC[(int16_t)a1];
  return &byte_19341C[v1];
}
// 1992FC: using guessed type int16_t word_1992FC[462];


//----- (0007A9B1) --------------------------------------------------------
void __usercall sub_7A9B1(int a1, char *a2, int16_t *a3)
{
  unsigned int v3; // eax
  int v4; // eax
  char v5[20]; // [esp+0h] [ebp-14h] BYREF

  if ( byte_199CAE == 1 )
    byte_199CAE = 0;
  byte_199CAE = 0;
  sub_7A816();
  v3 = sub_FECDA();
  sub_CDF65(v3, a1, a2);
  v5[0] = 0;
  GetFontsLbxName_7AA33(v5);
  v4 = sub_120526((int)v5);
  sub_7AB13(v4, a1);
  sub_7ABD7();
  sub_5DF0A(a1, (int)a2, a3);
  sub_56484();
}
// 199CAE: using guessed type char byte_199CAE;


//----- (0007AA05) --------------------------------------------------------
int sub_7AA05()
{
  char v1[20]; // [esp+0h] [ebp-14h] BYREF

  v1[0] = 0;
  GetFontsLbxName_7AA33(v1);
  return sub_120526((int)v1);
}


//----- (0007AA33) --------------------------------------------------------
char *__fastcall GetFontsLbxName_7AA33(char *a1)
{
  char *v1; // edi
  char *result; // eax
  char *v3; // kr00_4
  char *v4; // esi
  char *v5; // edi
  char *v6; // esi

  v1 = a1;
  LOBYTE(a1) = byte_199CAE;
  v3 = a1;
  result = (char *)(uint8_t)byte_199CAE;
  switch ( byte_199CAE )
  {
    case 1:
      v4 = aFontsgLbx;
      goto LABEL_6;
    case 2:
      v4 = aFontsfLbx;
      goto LABEL_6;
    case 3:
      v4 = aFontssLbx;
      goto LABEL_6;
    case 4:
      v4 = aFontsiLbx;
LABEL_6:
      *(_DWORD *)v1 = *(_DWORD *)v4;
      v6 = v4 + 4;
      v5 = v1 + 4;
      *(_DWORD *)v5 = *(_DWORD *)v6;
      v6 += 4;
      v5 += 4;
      *(_WORD *)v5 = *(_WORD *)v6;
      v5[2] = v6[2];
      break;
    default:
      result = v3;
      strcpy(v1, "fonts.lbx");
      break;
  }
  return result;
}
// 199CAE: using guessed type char byte_199CAE;


//----- (0007AA79) --------------------------------------------------------
int sub_7AA79()
{
  int result; // eax
  int v1; // ecx
  _BYTE v2[80]; // [esp+0h] [ebp-50h] BYREF

  result = fopen(aLanguageIni, aWt);
  v1 = result;
  if ( result )
  {
    itoa((uint8_t)byte_199CAE, v2, 10, result);
    fputs(v2, v1);
    return fclose(v1);
  }
  return result;
}
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 138EB6: using guessed type int __fastcall fputs(_DWORD, _DWORD);
// 199CAE: using guessed type char byte_199CAE;


//----- (0007AAD3) --------------------------------------------------------
int __fastcall sub_7AAD3(_DWORD *a1)
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
      v4 = aHerodatgLbx;
      break;
    case 2:
      v4 = aHerodatfLbx;
      break;
    case 3:
      v4 = aHerodatsLbx;
      break;
    case 4:
      v4 = aHerodatiLbx;
      break;
    default:
      result = (int)v3;
      v4 = aHerodataLbx;
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


//----- (0007AB13) --------------------------------------------------------
void __fastcall sub_7AB13(int a1, int a2)
{
  unsigned int v2; // ecx
  int v3; // esi
  _DWORD v4[5]; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  if ( dword_192ED4 )
  {
    v5 = 0;
    sub_7AAD3(v4);
    do
    {
      v2 = (int16_t)v5;
      v3 = 59 * (int16_t)v5;
      sub_1112EC(dword_192ED4, a2);
      a2 = 0;
      strcpy((char *)(v3 + dword_1930DC + 15), (char *)sub_126C37((int)v4, 0, dword_192ED4, v2, 1u, 59) + 15);
      ++v5;
      sub_1113CC(dword_192ED4, 0);
    }
    while ( (int16_t)v5 < 67 );
  }
  JUMPOUT(0x78F44);
}
// 7AB8D: control flows out of bounds to 78F44
// 192ED4: using guessed type int dword_192ED4;
// 1930DC: using guessed type int dword_1930DC;


//----- (0007ABA6) --------------------------------------------------------
int __fastcall sub_7ABA6(int a1)
{
  int v1; // edi
  int result; // eax
  int v3; // kr00_4
  char *v4; // esi

  v1 = a1;
  LOBYTE(a1) = byte_199CAE;
  v3 = a1;
  result = (uint8_t)byte_199CAE;
  switch ( byte_199CAE )
  {
    case 1:
      v4 = aMc;
      break;
    case 4:
      v4 = aBc;
      break;
    default:
      result = v3;
      v4 = aBc;
      break;
  }
  *(_WORD *)v1 = *(_WORD *)v4;
  *(_BYTE *)(v1 + 2) = v4[2];
  return result;
}
// 199CAE: using guessed type char byte_199CAE;


//----- (0007ABD7) --------------------------------------------------------
void sub_7ABD7()
{
  int16_t i; // dx
  _BYTE *v1; // eax

  for ( i = 0; i < word_199998; ++i )
  {
    v1 = (_BYTE *)(dword_197F98 + 3753 * i);
    if ( v1[40] != 100 && (uint8_t)v1[37] < 0x14u )
      strcpy(v1 + 21, (char *)dword_192630[(uint8_t)v1[37]]);
  }
}
// 192630: using guessed type int dword_192630[];
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0007AC30) --------------------------------------------------------
int __fastcall sub_7AC30( int a1, int a2, _WORD *a3)
{
  int result; // eax
  int16_t v5; // di

  result = 0;
  do
  {
    v5 = *(_WORD *)(113 * a1 + dword_19306C + 2 * (int16_t)result + 74);
    if ( v5 > -1 )
      *(_WORD *)(a2 + 2 * (int16_t)(*a3)++) = v5;
    ++result;
  }
  while ( (int16_t)result < 5 );
  return result;
}
// 19306C: using guessed type int dword_19306C;


//----- (0007AC71) --------------------------------------------------------
void sub_7AC71()
{
  int16_t i; // bx
  int v1; // eax
  int16_t v2; // dx
  _BYTE v3[16]; // [esp+0h] [ebp-14h] BYREF
  char *v4; // [esp+10h] [ebp-4h]

  memset(v3, 0, 14);
  v4 = (char *)sub_126BDD((int)aStarnameLbx, 0, dword_192ED4, 0, 0xDu, 15);
  for ( i = 0; i < word_199998; ++i )
  {
    v1 = 3753 * i + dword_197F98;
    v2 = *(uint8_t *)(v1 + 37);
    if ( !v3[*(uint8_t *)(v1 + 37)] )
    {
      strcpy(
        (char *)(113 * *(uint8_t *)(17 * *(int16_t *)(v1 + 41) + dword_1930D4 + 2) + dword_19306C),
        &v4[15 * *(uint8_t *)(v1 + 37)]);
      v3[v2] = 1;
    }
  }
  JUMPOUT(0x7BF57);
}
// 7AD0E: control flows out of bounds to 7BF57
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0007AD13) --------------------------------------------------------
char __fastcall sub_7AD13(int a1, int a2)
{
  int i; // ebx
  int16_t *j; // edi
  int v4; // edx
  int16_t v5; // si
  int v6; // eax
  int v7; // eax
  int16_t v8; // ax
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int16_t v15; // cx
  int v16; // ebx
  int v17; // edx
  int v18; // ebx
  int v19; // edx
  int16_t v20; // si
  int v21; // eax
  int v22; // edx
  int16_t v23; // di
  int16_t k; // ax
  int v25; // ebx
  int16_t *v27; // [esp-8h] [ebp-C08h]
  _WORD v30[1512]; // [esp+8h] [ebp-BF8h] BYREF
  _BYTE v31[8]; // [esp+BD8h] [ebp-28h] BYREF
  int16_t v32[4]; // [esp+BE0h] [ebp-20h] BYREF
  int v33; // [esp+BE8h] [ebp-18h]
  int v34; // [esp+BECh] [ebp-14h]
  int v35; // [esp+BF0h] [ebp-10h]
  int v36; // [esp+BF4h] [ebp-Ch]
  unsigned int v37; // [esp+BF8h] [ebp-8h]
  char v38; // [esp+BFCh] [ebp-4h]

  qmemcpy(v32, sub_8E5C5(4u, 119, 121), sizeof(v32));
  i = 3024;
  qmemcpy(v31, sub_8E5C5(4u, 119, 124), sizeof(v31));
  j = (int16_t *)v31;
  v4 = 0;
  v5 = 1;
  v6 = memset(v30, 0, sizeof(v30));
  while ( v5 < word_19999A )
  {
    sub_FE8BE(v6, v4, i, j);
    v7 = 21 * v5;
    v30[v7 + 20] = 1;
    v30[v7] = v5;
    if ( word_19C2F0 >= dword_19BFD8 )
    {
      sub_7C78E();
    }
    else
    {
      sub_120BB5(4, (int)v32);
      v27 = (int16_t *)dword_19C2E4;
      v8 = sub_12066F((int)byte_19C2F4);
      v9 = (int16_t)dword_19BFD8;
      v4 = (int)&word_19C2F0;
      v10 = sub_8EFE1(4u, &word_19C2F0, dword_19BFD8, v32, (int)v31, (640 - v8) / 2, 215, byte_19C2F4, v27, 0);
      v6 = sub_1077D(v10, (int)&word_19C2F0, v9, j);
    }
    for ( i = 1; (int16_t)i < word_19999A; ++i )
    {
      v4 = v5;
      v11 = 42 * v5;
      LOWORD(v11) = *(_WORD *)((char *)&v30[20] + v11);
      v36 = v11;
      sub_FE8BE(v11, v5, i, j);
      if ( v5 != (_WORD)i )
      {
        v4 = (int16_t)i;
        v6 = sub_1276F0(dword_19BFE0 + 299 * v5, (int16_t)i);
        if ( (_WORD)v6 )
        {
          v38 = 1;
          for ( j = 0; (int16_t)j < (int16_t)v36 && v38; j = (int16_t *)((char *)j + 1) )
          {
            v12 = 42 * v5 + 2 * (int16_t)j;
            LOWORD(v12) = *(_WORD *)((char *)v30 + v12);
            v35 = v12;
            v33 = (int16_t)v12;
            v34 = sub_7B0B4(v12, i);
            v4 = sub_1276F0(dword_19BFE0 + 299 * v33, (int16_t)i);
            sub_FE8BE(v4, v4, i, j);
            if ( (_WORD)i != (_WORD)v35 )
            {
              if ( !(_BYTE)v4 || (v6 = v34, v34 < a2) )
                v38 = 0;
            }
          }
          if ( v38 )
          {
            v13 = 21 * v5;
            v30[(int16_t)v30[v13 + 20] + v13] = i;
            v14 = (int16_t)v30[v13 + 20] + 1;
            if ( v14 >= 20 )
              v14 = 20;
            v4 = v14;
            v6 = 42 * v5;
            *(_WORD *)((char *)&v30[20] + v6) = v4;
          }
        }
      }
    }
    ++v5;
  }
  v15 = -1;
  v16 = 1;
  v17 = 0;
  do
  {
    sub_FE8BE(v6, v17, v16, j);
    v6 = 42 * (int16_t)v17;
    LOWORD(v6) = *(_WORD *)((char *)&v30[20] + v6);
    if ( (int16_t)v6 >= word_199998 )
    {
      v6 = sub_1247A0((int16_t)v16);
      if ( v6 == 1 )
      {
        v15 = v17;
        ++v16;
      }
    }
    ++v17;
  }
  while ( (int16_t)v17 < 72 );
  if ( v15 <= -1 )
    return 1;
  v18 = 0;
  do
  {
    v19 = 21 * v15;
    v20 = sub_1247A0((int16_t)v30[v19 + 20]);
    v37 = sub_1247A0((int16_t)v30[v19 + 20]) - 1;
    v21 = v19 * 2 + 2 * (int16_t)(v20 - 1);
    v22 = 2 * (int16_t)v37 + v19 * 2;
    v23 = *(_WORD *)((char *)v30 + v21);
    *(_WORD *)((char *)v30 + v21) = *(_WORD *)((char *)v30 + v22);
    ++v18;
    *(_WORD *)((char *)v30 + v22) = v23;
  }
  while ( (int16_t)v18 < 4 );
  memset(a1, -1, 16);
  for ( k = 0; k < word_199998; ++k )
  {
    v25 = k;
    *(_WORD *)(a1 + v25 * 2) = v30[21 * v15 + v25];
  }
  return 0;
}
// 7AD7D: variable 'v6' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19BFD8: using guessed type int dword_19BFD8;
// 19BFE0: using guessed type int dword_19BFE0;
// 19C2E4: using guessed type int dword_19C2E4;
// 19C2F0: using guessed type int16_t word_19C2F0;


//----- (0007B020) --------------------------------------------------------
void __usercall sub_7B020(int a1, int a2, int a3, int16_t *a4)
{
  int16_t i; // cx
  int16_t v5; // si
  int v6; // [esp+0h] [ebp-Ch]

  v6 = a1;
  for ( i = 0; i < word_19999A; ++i )
  {
    sub_FE8BE(a1, a2, a3, a4);
    a1 = 299 * i;
    a3 = dword_19BFE0;
    v5 = 0;
    *(_WORD *)(dword_19BFE0 + a1 + 297) = 0;
    while ( v5 < word_19999A )
    {
      sub_FE8BE(a1, a2, a3, a4);
      a3 = v5;
      a2 = v5;
      a1 = sub_7B0B4(i, v5);
      a4 = (int16_t *)a1;
      if ( a1 >= v6 )
      {
        a2 = v5;
        sub_127712(299 * i + dword_19BFE0, v5);
        a1 = 299 * i + dword_19BFE0;
        *(_DWORD *)(a1 + 4 * v5 + 9) = a4;
        ++*(_WORD *)(a1 + 297);
      }
      ++v5;
    }
  }
  JUMPOUT(0x7BF57);
}
// 7B0AF: control flows out of bounds to 7BF57
// 19999A: using guessed type int16_t word_19999A;
// 19BFE0: using guessed type int dword_19BFE0;


//----- (0007B0B4) --------------------------------------------------------
int __fastcall sub_7B0B4( int a1, int a2)
{
  int v2; // eax
  int16_t v3; // cx
  int16_t v4; // si
  int v5; // eax
  int v6; // ecx
  int v7; // ebx

  v2 = 113 * a1;
  v3 = *(_WORD *)(dword_19306C + v2 + 15);
  v4 = *(_WORD *)(dword_19306C + v2 + 17);
  v5 = dword_19306C + 113 * a2;
  v6 = v3 - *(int16_t *)(v5 + 15);
  v7 = v4 - *(int16_t *)(v5 + 17);
  return v6 * v6 + v7 * v7;
}
// 19306C: using guessed type int dword_19306C;


//----- (0007B0FB) --------------------------------------------------------
int __fastcall sub_7B0FB( int a1, int a2, int a3, int a4)
{
  return (a1 - a3) * (a1 - a3) + (a2 - a4) * (a2 - a4);
}


//----- (0007B11A) --------------------------------------------------------
void __fastcall sub_7B11A( int a1)
{
  char v2; // sf
  char v3; // of
  int16_t v4; // ax
  int16_t v5; // bx
  char v6; // dl
  int v7; // eax
  int16_t v8; // cx
  int v9; // eax
  int i; // [esp+8h] [ebp-4h]

  sub_79B2D(a1);
  sub_F4D0E();
  if ( v2 != v3 )
  {
    while ( !sub_792A9(a1) )
      *(_BYTE *)(dword_19306C + 113 * a1 + 22) = sub_8C807((uint8_t)byte_199CB3);
    for ( i = 0; ; ++i )
    {
      sub_79B2D(a1);
      sub_F4D0E();
      if ( v2 == v3 )
        break;
      sub_7CCB5(a1);
      v5 = v4;
      v6 = v4;
      v7 = dword_19306C + 113 * a1 + 2 * v4;
      if ( *(int16_t *)(v7 + 74) == -1 )
      {
        sub_7C3C4(a1, word_1999A2, v5, 0);
        ++word_1999A2;
      }
      else
      {
        v8 = word_1999A2;
        word_1999A2 = *(_WORD *)(v7 + 74);
        v9 = dword_1930D4 + 17 * word_1999A2;
        *(_BYTE *)(v9 + 4) = 3;
        *(_BYTE *)(v9 + 3) = v6;
        sub_8C5D7(a1);
        word_1999A2 = v8;
      }
    }
  }
  JUMPOUT(0x7BF57);
}
// 7B20D: control flows out of bounds to 7BF57
// 7B134: variable 'v2' is possibly undefined
// 7B134: variable 'v3' is possibly undefined
// 7B18D: variable 'v4' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1999A2: using guessed type int16_t word_1999A2;
// 199CB3: using guessed type char byte_199CB3;


//----- (0007B22B) --------------------------------------------------------
int16_t __usercall sub_7B22B( int a1, int a2, int16_t *a3, int a4)
{
  int16_t i; // dx
  int v7; // eax
  int v8; // eax
  int16_t v9; // bx
  int64_t v10; // rax
  int16_t j; // ax
  int v12; // edx
  int16_t k; // ax
  int v14; // edx
  int16_t v15; // ax
  char v16; // dl
  int v17; // eax
  char v19[100]; // [esp+0h] [ebp-16h] BYREF
  _WORD v20[4]; // [esp+64h] [ebp+4Eh] BYREF
  int v21; // [esp+6Ch] [ebp+56h]
  int v22; // [esp+70h] [ebp+5Ah]
  int v23; // [esp+74h] [ebp+5Eh]
  int v24; // [esp+78h] [ebp+62h]
  int v25; // [esp+7Ch] [ebp+66h]
  int v26; // [esp+80h] [ebp+6Ah]
  int16_t v27; // [esp+84h] [ebp+6Eh]
  int v28; // [esp+88h] [ebp+72h]
  int v29; // [esp+8Ch] [ebp+76h]
  int m; // [esp+90h] [ebp+7Ah]
  char v31; // [esp+94h] [ebp+7Eh]

  v27 = a2;
  v26 = 0;
  v23 = 0;
  *a3 = -1;
  for ( i = 0; i < 5 && !(_WORD)v26; ++i )
  {
    v22 = 113 * a1;
    v7 = dword_19306C + v22 + 2 * i;
    LOWORD(v7) = *(_WORD *)(v7 + 74);
    v25 = v7;
    v7 = (int16_t)v7;
    v21 = v7;
    if ( (int16_t)v7 > -1 )
    {
      v8 = (int16_t)v23;
      v9 = v25;
      *(_WORD *)&v19[4 * (int16_t)v23 + 80] = v25;
      *(_WORD *)&v19[4 * v8 + 82] = i;
      v22 = 17 * v21;
      LOWORD(v8) = *(uint8_t *)(17 * v21 + dword_1930D4 + 8);
      ++v23;
      if ( (_WORD)v8 == v27 )
      {
        v26 = 1;
        *a3 = v9;
      }
    }
  }
  if ( (int16_t)v23 <= 0 )
  {
    v10 = sprintf(v19, "Found no satellites after 3_MIN enforcement: Star: %d", a1);
    sub_126487(v19, SHIDWORD(v10));
  }
  if ( !(_WORD)v26 )
  {
    v24 = 0;
    memset(v20, -1, sizeof(v20));
    while ( !(_WORD)v24 )
    {
      a4 = 0;
      v31 = *(_BYTE *)(dword_19306C + 113 * a1 + 22);
      for ( j = 0; j < 4; ++j )
      {
        v22 = 4 * v27;
        if ( byte_17D77F[v22 + j] )
        {
          v12 = a4++;
          v20[v12] = j;
        }
      }
      v28 = 0;
      for ( k = 0; k < 5; ++k )
      {
        for ( m = 0; a4 > (int16_t)m && !(_WORD)v28; ++m )
        {
          v14 = k + 5 * v31;
          LOWORD(v14) = (uint8_t)byte_17D761[v14];
          v29 = v14;
          if ( (_WORD)v14 == v20[(int16_t)m] )
            v28 = 1;
        }
      }
      if ( (_WORD)v28 )
        v24 = 1;
      else
        *(_BYTE *)(dword_19306C + 113 * a1 + 22) = sub_8C807((uint8_t)byte_199CB3);
    }
    v15 = *(_WORD *)&v19[4 * (int16_t)(sub_1247A0((int16_t)v23) - 1) + 80];
    *a3 = v15;
    *(_BYTE *)(dword_1930D4 + 17 * v15 + 8) = v27;
    *(_BYTE *)(17 * *a3 + dword_1930D4 + 7) = v20[(int16_t)(sub_1247A0(a4) - 1)];
  }
  v16 = sub_8BFA3(a1, *a3);
  v17 = 17 * *a3;
  *(_BYTE *)(dword_1930D4 + v17 + 11) = v16;
  return v17;
}
// 7B2FB: conditional instruction was optimized away because %var_18.2==0
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 199CB3: using guessed type char byte_199CB3;


//----- (0007B45C) --------------------------------------------------------
int __fastcall sub_7B45C( int a1, unsigned int a2, int a3)
{
  int result; // eax
  char v4; // dl

  result = 17 * a1 + dword_1930D4;
  *(_BYTE *)(result + 6) = a2;
  if ( *(_BYTE *)(result + 10) == 4 && !*(_BYTE *)(3753 * a3 + dword_197F98 + 2218) )
  {
    v4 = sub_8C05B(*(uint8_t *)(result + 2));
    result = 17 * a3;
    *(_BYTE *)(dword_1930D4 + result + 10) = v4;
  }
  return result;
}
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (0007B4B4) --------------------------------------------------------
int __fastcall sub_7B4B4( int a1)
{
  int result; // eax

  result = dword_1930D4 + 17 * a1;
  if ( *(_BYTE *)(result + 5) != 2 )
  {
    *(_BYTE *)(result + 5) = 2;
    *(_BYTE *)(result + 13) = byte_17D7FC[*(uint8_t *)(result + 5)];
  }
  return result;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (0007B4DA) --------------------------------------------------------
uint8_t *__fastcall sub_7B4DA( int a1, int a2)
{
  int v4; // eax
  int v5; // edx
  _BOOL2 v6; // cx
  int16_t i; // ax
  uint8_t *result; // eax
  int16_t v9; // [esp+4h] [ebp-Ch]
  int16_t v10; // [esp+8h] [ebp-8h]
  char v11; // [esp+Ch] [ebp-4h]

  v4 = 17 * a1;
  v5 = dword_1930D4;
  *(_BYTE *)(dword_1930D4 + v4 + 10) = a2;
  v9 = 0;
  v10 = *(uint8_t *)(v5 + v4 + 2);
  while ( !v9 )
  {
    v6 = 0;
    v11 = *(_BYTE *)(113 * v10 + dword_19306C + 22);
    if ( v11 < 5 )
    {
      for ( i = 0; i < 10 && !v6; ++i )
        v6 = (uint8_t)byte_17D6EE[6 * i + v11] == a2;
    }
    if ( v6 )
      v9 = 1;
    else
      *(_BYTE *)(113 * v10 + dword_19306C + 22) = sub_8C807((uint8_t)byte_199CB3);
  }
  result = (uint8_t *)(dword_1930D4 + 17 * a1);
  result[6] = byte_17D72A[5 * result[10] + result[5]];
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 199CB3: using guessed type char byte_199CB3;


//----- (0007B5B2) --------------------------------------------------------
int __fastcall sub_7B5B2( int a1, int a2)
{
  int result; // eax

  *(_BYTE *)(17 * a1 + dword_1930D4 + 15) = 10;
  result = dword_19306C;
  *(_BYTE *)(113 * a2 + dword_19306C + 40) = 10;
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0007B5D3) --------------------------------------------------------
int __fastcall sub_7B5D3( int a1, int a2)
{
  int result; // eax

  result = 17 * a1;
  *(_BYTE *)(dword_1930D4 + result + 5) = a2;
  return result;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (0007B5E4) --------------------------------------------------------
int __fastcall sub_7B5E4( int a1, int a2)
{
  _BOOL2 v3; // cx
  int16_t i; // ax
  int result; // eax

  v3 = 0;
  for ( i = 0; i < 5 && !v3; ++i )
    v3 = a2 == *(_WORD *)(113 * a1 + dword_19306C + 2 * i + 74);
  result = dword_1930D4;
  *(_BYTE *)(17 * a2 + dword_1930D4 + 4) = 3;
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0007B631) --------------------------------------------------------
void sub_7B631()
{
  int16_t v0; // si
  int16_t v1; // dx
  char *v2; // eax
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int16_t v6; // di
  int16_t v7; // ax
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int16_t v11; // dx
  int16_t v12; // di
  int v13; // eax
  int16_t v14; // ax
  int v15; // edx
  _WORD v16[360]; // [esp+0h] [ebp-2FCh] BYREF
  int v17; // [esp+2D0h] [ebp-2Ch]
  int v18; // [esp+2D4h] [ebp-28h] BYREF
  int v19; // [esp+2D8h] [ebp-24h]
  int v20; // [esp+2DCh] [ebp-20h]
  int v21; // [esp+2E0h] [ebp-1Ch]
  char *v22; // [esp+2E4h] [ebp-18h]
  int v23; // [esp+2E8h] [ebp-14h]
  int16_t v24; // [esp+2ECh] [ebp-10h]
  int v25; // [esp+2F0h] [ebp-Ch]
  char v26; // [esp+2F4h] [ebp-8h]
  char v27; // [esp+2F8h] [ebp-4h]

  v18 = 0;
  v26 = 1;
  v23 = 0;
  memset(v16, -1, sizeof(v16));
  while ( (int16_t)v23 < word_199996 )
  {
    v2 = (char *)(dword_192B18 + 361 * (int16_t)v23);
    v0 = -1;
    v1 = *((_WORD *)v2 + 1);
    LOWORD(v2) = *v2;
    v22 = v2;
    if ( v1 > -1 && !*(_BYTE *)(3753 * (int16_t)v2 + dword_197F98 + 2225) )
    {
      v3 = 17 * v1;
      v27 = 0;
      v17 = 999;
      v4 = 1;
      v25 = -1;
      LOWORD(v3) = *(uint8_t *)(dword_1930D4 + v3 + 2);
      v19 = -1;
      v21 = v3;
      while ( (int16_t)v4 < word_19999A && !v27 )
      {
        if ( (_WORD)v4 != (_WORD)v21 )
        {
          sub_EBEB7(v21, v4);
          if ( (int16_t)v5 < (int16_t)v17 )
          {
            v17 = v5;
            if ( (int16_t)v5 <= 6 )
              v19 = v4;
          }
          if ( (int16_t)v5 <= 6 )
          {
            if ( sub_79B2D(v4) )
            {
              v27 = sub_79AE8(v4);
              if ( v27 )
              {
                if ( v0 == -1 )
                  v0 = v4;
              }
              else
              {
                sub_7AC30(v4, (int)v16, &v18);
              }
            }
            else if ( *(_BYTE *)(dword_19306C + 113 * (int16_t)v4 + 22) != 6 )
            {
              v25 = v4;
            }
          }
        }
        ++v4;
      }
      if ( v27 )
      {
        if ( (int16_t)v18 > 0 && v0 == -1 )
          v0 = *(uint8_t *)(17 * v16[0] + dword_1930D4 + 2);
      }
      else
      {
        v6 = v25;
        if ( (int16_t)v25 <= -1 )
        {
          v8 = (int16_t)v19;
          if ( (int16_t)v19 > -1 )
          {
            LOWORD(v8) = word_1999A2;
            v20 = v8;
            v9 = (int16_t)(sub_1247A0((int16_t)v18) - 1);
            v10 = dword_1930D4 + 17 * (int16_t)v16[v9];
            v11 = *(char *)(v10 + 15);
            v12 = *(uint8_t *)(v10 + 2);
            v13 = 113 * *(uint8_t *)(v10 + 2);
            v24 = v11;
            word_1999A2 = v16[v9];
            v14 = sub_C5AA7(word_1999A2, v13 + dword_19306C + 74, 5u);
            sub_7C3C4(v12, word_1999A2, v14, 1);
            *(_BYTE *)(17 * (int16_t)v16[v9] + dword_1930D4 + 15) = v24;
            v0 = v12;
            word_1999A2 = v20;
          }
        }
        else
        {
          sub_7CCB5(v25);
          v0 = v25;
          sub_7C3C4(v6, word_1999A2, v7, 1);
          ++word_1999A2;
        }
      }
      v15 = (int16_t)v22;
      word_19BFC8[(int16_t)v22] = v0;
      if ( v0 == -1 && !*(_BYTE *)(dword_197F98 + 3753 * v15 + 2225) )
        v26 = 0;
    }
    ++v23;
  }
  JUMPOUT(0x7BF57);
}
// 7B8C8: control flows out of bounds to 7BF57
// 7B6F4: variable 'v5' is possibly undefined
// 7B797: variable 'v7' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 19999A: using guessed type int16_t word_19999A;
// 1999A2: using guessed type int16_t word_1999A2;
// 19BFC8: using guessed type int16_t word_19BFC8[8];


//----- (0007B8CD) --------------------------------------------------------
void sub_7B8CD()
{
  char *v0; // eax
  int v1; // edi
  int v2; // ebx
  int v3; // edx
  int v4; // eax
  int v5; // eax
  char *v6; // esi
  int v7; // eax
  int16_t i; // dx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  int16_t v13; // ax
  int v14; // eax
  int16_t v15; // ax
  int v16; // eax
  int v17; // eax
  int16_t j; // dx
  int16_t k; // dx
  int16_t v20; // ax
  int v21; // ebx
  int v22; // eax
  int16_t *v23; // [esp-8h] [ebp-30h]
  int16_t *v24; // [esp-8h] [ebp-30h]
  int16_t *v25; // [esp-8h] [ebp-30h]
  _WORD v26[8]; // [esp+0h] [ebp-28h] BYREF
  int16_t v27[4]; // [esp+10h] [ebp-18h] BYREF
  int16_t v28[4]; // [esp+18h] [ebp-10h] BYREF
  int v29; // [esp+20h] [ebp-8h]
  char *v30; // [esp+24h] [ebp-4h]

  qmemcpy(v27, sub_8E5C5(4u, 119, 121), sizeof(v27));
  v0 = sub_8E5C5(4u, 119, 124);
  qmemcpy(v28, v0, sizeof(v28));
  v6 = v0 + 8;
  v1 = (int)v28;
  dword_19BFE0 = (int)sub_110CEE(dword_192ED4, 21528);
  memset(dword_19BFE0, 0, 288);
  v2 = 16;
  v3 = -1;
  v4 = memset(word_19BFC8, -1, sizeof(word_19BFC8));
  sub_FE8BE(v4, -1, 16, v28);
  sub_124B65();
  LOWORD(v6) = word_199998;
  v29 = 0;
  if ( word_199998 > 6 )
  {
    LOWORD(v5) = (uint8_t)byte_199F2B;
    v6 += v5;
  }
  v30 = v6 + 4;
  sub_FE8BE((int)(v6 + 4), -1, 16, v28);
  sub_7C78E();
  while ( !(_WORD)v29 )
  {
    sub_FE8BE(v7, v3, v2, (int16_t *)v1);
    for ( i = 0; i < word_19999A; ++i )
    {
      v9 = 113 * i;
      *(_BYTE *)(dword_19306C + v9 + 20) = -1;
    }
    v10 = 10 * (int16_t)v6;
    v2 = word_1999A0;
    v11 = word_1999A0 * word_199A0A % v10;
    v1 = word_1999A0 * word_199A0A / v10 * (word_1999A0 * word_199A0A / v10)
       + word_1999A0 * word_199A0C / v10 * (word_1999A0 * word_199A0C / v10);
    if ( v1 <= 15000 )
      v1 = 15000;
    v12 = word_19C2F0;
    if ( word_19C2F0 < dword_19BFD8 )
    {
      sub_120BB5(4, (int)v27);
      v23 = (int16_t *)dword_19C2E4;
      v13 = sub_12066F((int)byte_19C2F4);
      v2 = (int16_t)dword_19BFD8;
      v11 = (int)&word_19C2F0;
      v14 = sub_8EFE1(4u, &word_19C2F0, dword_19BFD8, v27, (int)v28, (640 - v13) / 2, 215, byte_19C2F4, v23, 0);
      v12 = sub_1077D(v14, (int)&word_19C2F0, v2, (int16_t *)v1);
    }
    sub_FE8BE(v12, v11, v2, (int16_t *)v1);
    sub_7B020(v1, v11, v2, (int16_t *)v1);
    if ( word_19C2F0 < dword_19BFD8 )
    {
      sub_120BB5(4, (int)v27);
      v24 = (int16_t *)dword_19C2E4;
      v15 = sub_12066F((int)byte_19C2F4);
      v2 = (int16_t)dword_19BFD8;
      v16 = sub_8EFE1(4u, &word_19C2F0, dword_19BFD8, v27, (int)v28, (640 - v15) / 2, 215, byte_19C2F4, v24, 0);
      sub_1077D(v16, (int)&word_19C2F0, v2, (int16_t *)v1);
    }
    v3 = v1;
    LOBYTE(v17) = sub_7AD13((int)v26, v1);
    LOBYTE(v3) = v17;
    sub_FE8BE(v17, v3, v2, (int16_t *)v1);
    if ( (_BYTE)v3 )
    {
      LOWORD(v6) = (_WORD)v6 + 1;
      if ( (int16_t)v6 > (int16_t)v30 )
        goto LABEL_25;
    }
    else
    {
      v29 = 1;
    }
  }
  for ( j = 0; j < word_199998; ++j )
    ;
  sub_7C6EF((int)v26);
  for ( k = 0; k < word_199998; ++k )
    *(_BYTE *)(dword_19306C + 113 * (int16_t)v26[k] + 20) = k;
  sub_7C4AF();
  sub_120BB5(4, (int)v27);
  v25 = (int16_t *)dword_19C2E4;
  v20 = sub_12066F((int)byte_19C2F4);
  v21 = (int16_t)dword_19BFD8;
  v22 = sub_8EFE1(4u, &word_19C2F0, dword_19BFD8, v27, (int)v28, (640 - v20) / 2, 215, byte_19C2F4, v25, 1);
  sub_1077D(v22, (int)&word_19C2F0, v21, (int16_t *)v1);
  sub_169245();
LABEL_25:
  JUMPOUT(0x7BF57);
}
// 7BAFB: control flows out of bounds to 7BF57
// 7B974: variable 'v5' is possibly undefined
// 7B995: variable 'v7' is possibly undefined
// 7BAE5: variable 'v17' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 1999A0: using guessed type int16_t word_1999A0;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;
// 199F2B: using guessed type char byte_199F2B;
// 19BFC8: using guessed type int16_t word_19BFC8[8];
// 19BFD8: using guessed type int dword_19BFD8;
// 19BFE0: using guessed type int dword_19BFE0;
// 19C2E4: using guessed type int dword_19C2E4;
// 19C2F0: using guessed type int16_t word_19C2F0;


//----- (0007BBB6) --------------------------------------------------------
int sub_7BBB6()
{
  return 1;
}


//----- (0007BBBC) --------------------------------------------------------
int sub_7BBBC()
{
  int v0; // eax
  int16_t i; // dx
  int16_t v2; // bx
  int v3; // eax
  int16_t v4; // bx
  int16_t j; // dx
  int v6; // eax
  int v7; // eax
  char *v8; // edi
  int v9; // edx
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // edx
  _BYTE v15[128]; // [esp+0h] [ebp-6h] BYREF
  int v16; // [esp+80h] [ebp+7Ah]
  int16_t v17; // [esp+84h] [ebp+7Eh]

  sub_7BD87();
  v17 = -1;
  v16 = v0;
  for ( i = 0; i < 5; ++i )
  {
    v2 = *(_WORD *)(dword_19306C + 2 * i + 74);
    *(_WORD *)&v15[2 * i + 116] = v2;
    if ( v2 > -1 && i > 2 && sub_1247A0(i - 1) == 1 )
      v17 = i;
  }
  if ( v17 < 2 )
    v17 = sub_1247A0(3u) + 1;
  v3 = dword_19306C + 2 * v17;
  v4 = *(_WORD *)(v3 + 74);
  if ( v4 == -1 )
  {
    v4 = word_1999A2;
    *(_WORD *)(v3 + 74) = word_1999A2;
    word_1999A2 = v4 + 1;
  }
  for ( j = 0; j < 5; ++j )
  {
    if ( j != v17 )
    {
      v6 = dword_19306C + 2 * j;
      if ( *(int16_t *)(v6 + 74) != -1 )
        *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(v6 + 74) + 4) = 1;
    }
  }
  v7 = dword_19306C;
  v8 = (char *)dword_19306C;
  *(_BYTE *)(dword_19306C + 40) = 11;
  strcpy(v8, "Orion");
  if ( *(_BYTE *)(v7 + 22) == 6 )
    *(_BYTE *)(dword_19306C + 22) = sub_1247A0(6u) - 1;
  v9 = dword_19306C;
  v10 = dword_19306C + 113 * (int16_t)v16;
  qmemcpy(v15, (void *)v10, 0x71u);
  *(_WORD *)(v10 + 15) = *(_WORD *)(dword_19306C + 15);
  *(_WORD *)(v10 + 17) = *(_WORD *)(v9 + 17);
  v11 = 17 * v4;
  *(_DWORD *)(v9 + 15) = *(_DWORD *)&v15[15];
  memset(v11 + dword_1930D4, 0, 17);
  v12 = dword_1930D4;
  *(_WORD *)(v11 + dword_1930D4) = -1;
  *(_BYTE *)(v11 + v12 + 4) = 3;
  *(_BYTE *)(v11 + v12 + 5) = 4;
  *(_BYTE *)(v11 + v12 + 6) = 1;
  *(_BYTE *)(v11 + v12 + 7) = 2;
  *(_BYTE *)(v11 + v12 + 8) = 9;
  *(_BYTE *)(v11 + v12 + 10) = 4;
  LOBYTE(v9) = v17;
  *(_BYTE *)(v11 + v12 + 15) = 11;
  *(_BYTE *)(v11 + v12 + 3) = v9;
  *(_BYTE *)(v11 + dword_1930D4 + 11) = sub_8BFA3(0, v4);
  *(_BYTE *)(dword_1930D4 + v11 + 13) = sub_8C01E(0, v4);
  v13 = 0;
  do
    ++v13;
  while ( (int16_t)v13 < 5 );
  return v16;
}
// 7BBD6: variable 'v0' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1999A2: using guessed type int16_t word_1999A2;


//----- (0007BD87) --------------------------------------------------------
void sub_7BD87()
{
  int16_t i; // ax
  int16_t j; // di
  int16_t v2; // ax
  int v3; // edx
  int v4; // eax
  int16_t v5; // di
  int16_t v6; // dx
  int v7; // esi
  int16_t v8; // si
  _BYTE v10[432]; // [esp+0h] [ebp-214h] BYREF
  _BYTE v11[72]; // [esp+1B0h] [ebp-64h] BYREF
  int v12; // [esp+1F8h] [ebp-1Ch]
  int v13; // [esp+1FCh] [ebp-18h]
  int v14; // [esp+200h] [ebp-14h]
  int16_t v15; // [esp+204h] [ebp-10h] BYREF
  int v16; // [esp+208h] [ebp-Ch]
  int16_t v17; // [esp+20Ch] [ebp-8h] BYREF
  int v18; // [esp+210h] [ebp-4h]

  v18 = 253 * word_199992 / 10 + 21;
  v16 = 200 * word_199992 / 10 + 21;
  memset(v11, 0, sizeof(v11));
  v13 = 4;
  sub_85ABF(v18, v16, &v15, &v17);
  for ( i = 0; i < word_199998; ++i )
    ;
  v14 = 0;
  memset(v10, -1, sizeof(v10));
  while ( (int16_t)v14 < 4 && (int16_t)v13 < 8 )
  {
    for ( j = 0; j < word_19999A; ++j )
    {
      if ( !v11[j] && !sub_798C4(j) && !sub_7C396(j) )
      {
        v12 = 113 * j;
        sub_EBE79(*(_WORD *)(v12 + dword_19306C + 15), *(_WORD *)(v12 + dword_19306C + 17), v18, v16);
        if ( v2 < (int16_t)v13 )
        {
          v3 = v2;
          v4 = 6 * (int16_t)v14;
          v11[j] = 1;
          *(_DWORD *)&v10[v4] = v3;
          ++v14;
          *(_WORD *)&v10[v4 + 4] = j;
        }
      }
    }
    ++v13;
  }
  qsort(v10, word_19999A, 6);
  v5 = 0;
  v6 = 0;
  while ( v5 < word_19999A )
  {
    if ( *(int *)&v10[6 * v5] > 0 )
    {
      v7 = 6 * v6;
      *(_WORD *)&v10[v7 + 4] = *(_WORD *)&v10[6 * v5 + 4];
      ++v6;
      *(_DWORD *)&v10[v7] = *(_DWORD *)&v10[6 * v5];
    }
    ++v5;
  }
  if ( v6 <= 1 )
  {
    do
      v8 = sub_1247A0(word_19999A) - 1;
    while ( sub_798C4(v8) || sub_7C396(v8) );
  }
  else
  {
    sub_1247A0(v6);
  }
  JUMPOUT(0x7BD81);
}
// 7BF58: control flows out of bounds to 7BD81
// 7BE6E: variable 'v2' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 199992: using guessed type int16_t word_199992;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (0007BF5D) --------------------------------------------------------
int __fastcall sub_7BF5D(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int16_t i; // cx
  int16_t *v7; // ebx
  int16_t v8; // ax
  int v9; // eax
  int16_t v10; // dx
  int16_t v11; // bx
  int16_t *v12; // ecx
  int v13; // eax
  int16_t v14; // ax
  int16_t v15; // dx
  int v16; // [esp+0h] [ebp-38h]
  int16_t v19; // [esp+20h] [ebp-18h]
  int16_t v20; // [esp+24h] [ebp-14h]
  int v21; // [esp+28h] [ebp-10h]
  int16_t v22; // [esp+2Ch] [ebp-Ch]
  int16_t v23; // [esp+30h] [ebp-8h]
  int16_t v24; // [esp+34h] [ebp-4h]

  if ( word_199998 % 2 )
  {
    v21 = (word_199998 - 1) / 2;
    v23 = word_199A0C / (int16_t)v21;
    result = word_199A0A / 2;
    v11 = 0;
    v20 = word_199A0A / 2;
    while ( v11 < word_199998 )
    {
      v12 = (int16_t *)(2 * v11 + v16);
      *v12 = v23 * (v11 % (int16_t)v21);
      *(_WORD *)(a2 + 2 * v11) = v20 * (v11 / (int16_t)v21);
      v13 = v23 + *v12;
      if ( word_199A0C <= v13 )
        LOWORD(v13) = word_199A0C;
      *(_WORD *)(a3 + 2 * v11) = v13;
      v14 = word_199A0A;
      if ( word_199A0A > v20 + *(int16_t *)(a2 + 2 * v11) )
        v14 = v20 + *(_WORD *)(a2 + 2 * v11);
      v15 = v14;
      result = a4 + 2 * v11++;
      *(_WORD *)result = v15;
    }
  }
  else
  {
    v19 = word_199998 / 2;
    v24 = word_199A0C / (word_199998 / 2);
    result = word_199A0A / 2;
    v22 = word_199A0A / 2;
    for ( i = 0; i < word_199998; ++i )
    {
      v7 = (int16_t *)(2 * i + v16);
      *v7 = i % v19 * v24;
      *(_WORD *)(a2 + 2 * i) = v22 * (i / v19);
      v8 = word_199A0C;
      if ( word_199A0C > v24 + *v7 )
        v8 = v24 + *v7;
      *(_WORD *)(a3 + 2 * i) = v8;
      v9 = v22 + *(int16_t *)(a2 + 2 * i);
      if ( word_199A0A <= v9 )
        LOWORD(v9) = word_199A0A;
      v10 = v9;
      result = a4 + 2 * i;
      *(_WORD *)result = v10;
    }
  }
  return result;
}
// 7BFD2: variable 'v16' is possibly undefined
// 199998: using guessed type int16_t word_199998;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;


//----- (0007C107) --------------------------------------------------------
void __fastcall sub_7C107( int a1, int a2, int a3)
{
  int16_t v3; // bx
  int v4; // edx
  int v5; // eax
  int16_t i; // bx
  int v7; // esi
  int16_t v8; // ax
  int16_t v9; // di
  char v10; // dl
  char v11; // dh
  int16_t v12; // si
  int16_t j; // ax
  int v14; // edx
  int16_t v15; // bx
  int v16; // eax
  int v17; // ebx
  char v18; // al
  char v19; // bl
  int v20; // edx
  int16_t v21; // ax
  int v22; // edx
  int v23; // edx
  int16_t v24; // ax
  int v28; // [esp+18h] [ebp-10h]
  int v29; // [esp+1Ch] [ebp-Ch] BYREF
  int v30; // [esp+20h] [ebp-8h] BYREF
  char v31; // [esp+24h] [ebp-4h]

  v3 = 0;
  dword_19BFE4 = (int)sub_110CEE(dword_192EE8, 288);
  while ( v3 < word_19999A )
  {
    v4 = dword_19BFE4;
    v5 = v3;
    *(_WORD *)(dword_19BFE4 + 4 * v3++) = 999;
    *(_WORD *)(v4 + 4 * v5 + 2) = 999;
  }
  v31 = 0;
  for ( i = 1; i < word_19999A && !v31; ++i )
  {
    if ( i != a1 )
    {
      v7 = 4 * i;
      *(_WORD *)(dword_19BFE4 + v7 + 2) = i;
      sub_EBEB7(a1, i);
      *(_WORD *)(dword_19BFE4 + v7) = v8;
      if ( sub_7C8E6(i) && *(int16_t *)(v7 + dword_19BFE4) <= a2 )
        v31 = 1;
    }
  }
  if ( !v31 )
  {
    qsort(dword_19BFE4, word_19999A, 4);
    v9 = 0;
    v10 = 0;
    do
    {
      v11 = 1;
      v12 = *(_WORD *)(dword_19BFE4 + 4 * v9 + 2);
      for ( j = 0; j < word_199998; ++j )
      {
        if ( v12 == *(_WORD *)(a3 + 2 * j) )
        {
          v11 = 0;
          break;
        }
      }
      if ( v11 )
      {
        v10 = 1;
      }
      else if ( ++v9 >= word_19999A )
      {
        v10 = 1;
      }
    }
    while ( !v10 );
    if ( !sub_7C8E6(v12) )
    {
      v14 = 113 * v12;
      *(_BYTE *)(dword_19306C + v14 + 22) = 4;
      v15 = sub_1247A0(0xAu) - 1;
      if ( v15 >= 3 )
      {
        if ( v15 >= 7 )
          *(_BYTE *)(v14 + dword_19306C + 19) = 2;
        else
          *(_BYTE *)(v14 + dword_19306C + 19) = 1;
      }
      else
      {
        *(_BYTE *)(v14 + dword_19306C + 19) = 0;
      }
      *(_BYTE *)(dword_19306C + 113 * v12 + 21) = sub_1247A0(3u) - 1;
      v16 = 0;
      do
      {
        v17 = (int16_t)v16++;
        *(_WORD *)(113 * v12 + dword_19306C + 2 * v17 + 74) = -1;
      }
      while ( (int16_t)v16 < 5 );
      v28 = 0;
      do
      {
        sub_8C567(v12);
        v19 = v18;
        v20 = 2 * v18 + 113 * v12 + dword_19306C;
        v21 = word_1999A2;
        *(_WORD *)(v20 + 74) = word_1999A2;
        v22 = dword_1930D4 + 17 * v21;
        *(_BYTE *)(v22 + 4) = 3;
        *(_BYTE *)(v22 + 3) = v19;
        ++v28;
        sub_8C5D7(v12);
        ++word_1999A2;
      }
      while ( (int16_t)v28 < 2 );
    }
    if ( v9 < word_19999A )
    {
      do
      {
        sub_3BBF6(
          *(_WORD *)(dword_19306C + 113 * v12 + 15),
          *(_WORD *)(dword_19306C + 113 * v12 + 17),
          *(_WORD *)(113 * a1 + dword_19306C + 15),
          *(_WORD *)(113 * a1 + dword_19306C + 17),
          0xAu,
          &v29,
          &v30);
        v23 = 113 * v12 + dword_19306C;
        *(_WORD *)(v23 + 15) += v29;
        *(_WORD *)(v23 + 17) += v30;
        sub_EBEB7(a1, v12);
      }
      while ( v24 > a2 );
    }
  }
}
// 7C17E: variable 'v8' is possibly undefined
// 7C2CB: variable 'v18' is possibly undefined
// 7C38F: variable 'v24' is possibly undefined
// 192EE8: using guessed type int dword_192EE8;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 1999A2: using guessed type int16_t word_1999A2;
// 19BFE4: using guessed type int dword_19BFE4;


//----- (0007C396) --------------------------------------------------------
_BOOL1 __fastcall sub_7C396( int a1)
{
  _BOOL1 v2; // dl
  int16_t i; // ax

  v2 = 0;
  for ( i = 0; i < word_199998 && !v2; ++i )
    v2 = a1 == word_19BFC8[i];
  return v2;
}
// 199998: using guessed type int16_t word_199998;
// 19BFC8: using guessed type int16_t word_19BFC8[8];


//----- (0007C3C4) --------------------------------------------------------
int __fastcall sub_7C3C4( int a1, int a2, int a3, int a4)
{
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int result; // eax
  int v11; // esi
  int v12; // edi

  v6 = 113 * a1;
  if ( a4 && *(uint8_t *)(v6 + dword_19306C + 22) >= 5u )
    *(_BYTE *)(v6 + dword_19306C + 22) = sub_1247A0(5u) - 1;
  byte_19C31A = a4;
  v7 = 17 * a2;
  memset(v7 + dword_1930D4, 0, 17);
  v8 = dword_1930D4;
  *(_BYTE *)(v7 + dword_1930D4 + 4) = 3;
  *(_BYTE *)(v7 + v8 + 3) = a3;
  sub_8C5D7(a1);
  byte_19C31A = 0;
  if ( a2 == word_1999A2 && (v9 = dword_19306C + 113 * a1 + 2 * a3, *(int16_t *)(v9 + 74) >= 0) )
  {
    result = 17 * *(int16_t *)(v9 + 74);
    v11 = dword_1930D4 + v7;
    v12 = result + dword_1930D4;
    --word_1999A2;
    *(_DWORD *)v12 = *(_DWORD *)(dword_1930D4 + v7);
    v11 += 4;
    v12 += 4;
    *(_DWORD *)v12 = *(_DWORD *)v11;
    v11 += 4;
    v12 += 4;
    *(_DWORD *)v12 = *(_DWORD *)v11;
    v11 += 4;
    v12 += 4;
    *(_DWORD *)v12 = *(_DWORD *)v11;
    *(_BYTE *)(v12 + 4) = *(_BYTE *)(v11 + 4);
  }
  else
  {
    result = a3;
    *(_WORD *)(113 * a1 + dword_19306C + 2 * a3 + 74) = a2;
  }
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1999A2: using guessed type int16_t word_1999A2;
// 19C31A: using guessed type char byte_19C31A;


//----- (0007C4AF) --------------------------------------------------------
void sub_7C4AF()
{
  int v0; // esi
  int16_t v1; // cx
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int i; // ecx
  int v6; // edx
  int16_t v7; // si
  int16_t v8; // dx
  int v9; // edx
  int16_t v10; // ax
  int v11; // eax
  int v12; // eax
  int16_t v13; // ax
  int16_t v14; // dx
  int v15; // edx
  uint8_t v16; // al
  int v17; // esi
  int v18; // esi
  int v19; // edx
  int j; // ebx
  int v21; // eax
  _BYTE *v22; // ecx
  int v23; // [esp-Ch] [ebp-20h]
  int16_t v24; // [esp-4h] [ebp-18h]
  _WORD v25[8]; // [esp+0h] [ebp-14h] BYREF
  int v26; // [esp+10h] [ebp-4h] BYREF

  v26 = 0;
  memset(v25, -1, sizeof(v25));
  v0 = 0;
  v1 = 0;
  v2 = dword_19306C;
  while ( v1 < word_19999A )
  {
    v3 = 113 * v1;
    if ( *(char *)(v2 + v3 + 20) > -1 && *(char *)(v2 + v3 + 20) < 8 )
    {
      v4 = (int16_t)v0++;
      v25[v4] = v1;
    }
    ++v1;
  }
  for ( i = 0; ; ++i )
  {
    if ( (int16_t)i >= word_19999A )
    {
      word_199996 = word_199998;
      sub_7AC71();
      sub_7B631();
      JUMPOUT(0x7BF57);
    }
    v6 = 113 * (int16_t)i;
    v7 = *(char *)(v6 + dword_19306C + 20);
    if ( *(char *)(v6 + dword_19306C + 20) > -1 && v7 < 8 )
      break;
LABEL_32:
    ;
  }
  sub_7B11A(i);
  v8 = 8;
  if ( *(_BYTE *)(dword_197F98 + 3753 * v7 + 2219) )
    v8 = 5;
  sub_7B22B(i, v8, (int16_t *)&v26, i);
  sub_7C73D(i);
  v24 = v7;
  v23 = i;
  v18 = v26;
  v19 = 113 * i + dword_19306C;
  for ( j = 0; ; ++j )
  {
    v21 = *(int16_t *)(v19 + 2 * j + 74);
    if ( (_WORD)v21 != 0xFFFF && v21 != v26 )
    {
      v22 = (_BYTE *)(17 * v21 + dword_1930D4);
      if ( v22[4] == 3 )
        break;
    }
  }
  if ( byte_17846E == -1 )
  {
    v22[5] = 4;
    v22[13] = 10;
    v22[6] = sub_F4C45(v18);
  }
  if ( byte_17844A == -1 )
  {
    if ( (char)v22[5] < 2 )
    {
      v22[5] = 2;
      v22[13] = 5;
    }
    v22[10] = (v22[10] & 1) + 1;
    v22[6] = sub_F4C45(v18);
  }
  if ( byte_178456 == -1 )
  {
    v22[10] = 4;
  }
  else
  {
    if ( byte_17847A != -1 )
    {
LABEL_50:
      i = v23;
      v9 = 3753 * v24 + dword_197F98;
      v10 = v26;
      *(_WORD *)(v9 + 41) = v26;
      if ( *(_BYTE *)(v9 + 2221) )
        *(_BYTE *)(17 * v10 + dword_1930D4 + 5) = 3;
      else
        sub_7B4B4(v10);
      sub_7B5E4(v23, v26);
      v11 = 17 * (int16_t)v26;
      if ( *(_BYTE *)(v11 + dword_1930D4 + 10) != 2 )
        *(_BYTE *)(v11 + dword_1930D4 + 10) = 2;
      v12 = 3753 * v24;
      if ( *(char *)(v12 + dword_197F98 + 2222) <= 0 )
      {
        if ( *(char *)(v12 + dword_197F98 + 2222) >= 0 )
        {
LABEL_23:
          if ( *(_BYTE *)(3753 * v24 + dword_197F98 + 2223) )
          {
            *(_BYTE *)(17 * (int16_t)v26 + dword_1930D4 + 15) = 10;
            *(_BYTE *)(113 * (int16_t)v23 + dword_19306C + 40) = 10;
          }
          v15 = dword_197F98 + 3753 * v24;
          if ( *(_BYTE *)(v15 + 2217) )
          {
            v16 = 0;
          }
          else if ( *(_BYTE *)(v15 + 2218) )
          {
            v16 = 2;
          }
          else
          {
            v16 = 1;
          }
          v17 = 113 * (int16_t)v23;
          sub_7B45C(v26, v16, v24);
          sub_13FA7(v26, *(char *)(dword_19306C + v17 + 20));
          sub_7C107(v23, 4, (int)v25);
          if ( *(_BYTE *)(v17 + dword_19306C + 40) == 9 )
            *(_BYTE *)(v17 + dword_19306C + 40) = 0;
          goto LABEL_32;
        }
        v13 = v26;
        v14 = 1;
      }
      else
      {
        v13 = v26;
        v14 = 3;
      }
      sub_7B4DA(v13, v14);
      goto LABEL_23;
    }
    v22[10] = 3;
  }
  v22[6] = sub_F4C45(v18);
  goto LABEL_50;
}
// 7C6EA: control flows out of bounds to 7BF57
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17844A: using guessed type char byte_17844A;
// 178456: using guessed type char byte_178456;
// 17846E: using guessed type char byte_17846E;
// 17847A: using guessed type char byte_17847A;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (0007C6EF) --------------------------------------------------------
void __fastcall sub_7C6EF(int a1)
{
  int v2; // ecx
  int16_t v3; // dx
  int16_t v4; // si
  int16_t v5; // di

  v2 = 0;
  while ( 1 )
  {
    v3 = sub_1247A0(word_199998) - 1;
    v4 = sub_1247A0(word_199998) - 1;
    if ( v3 != v4 )
    {
      v5 = *(_WORD *)(a1 + 2 * v3);
      *(_WORD *)(a1 + 2 * v3) = *(_WORD *)(a1 + 2 * v4);
      *(_WORD *)(a1 + 2 * v4) = v5;
    }
    if ( (int16_t)++v2 >= 100 )
      JUMPOUT(0x7BD81);
  }
}
// 7C738: control flows out of bounds to 7BD81
// 199998: using guessed type int16_t word_199998;


//----- (0007C73D) --------------------------------------------------------
int __fastcall sub_7C73D( int a1)
{
  int v2; // edx
  int v3; // eax
  int result; // eax
  int v5; // edx

  v2 = 113 * a1;
  v3 = dword_19306C;
  *(_BYTE *)(v2 + dword_19306C + 40) = 0;
  *(_BYTE *)(v2 + v3 + 41) = -1;
  result = 0;
  do
  {
    v5 = *(int16_t *)(dword_19306C + 113 * a1 + 2 * (int16_t)result + 74);
    if ( v5 > -1 )
      *(_BYTE *)(17 * v5 + dword_1930D4 + 15) = 0;
    ++result;
  }
  while ( (int16_t)result < 5 );
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0007C78E) --------------------------------------------------------
void sub_7C78E()
{
  char *v0; // edi
  int v1; // eax
  int v2; // eax
  _BYTE v3[8]; // [esp+0h] [ebp-10h] BYREF
  _BYTE v4[8]; // [esp+8h] [ebp-8h] BYREF

  qmemcpy(v4, sub_8E5C5(4u, 119, 121), sizeof(v4));
  qmemcpy(v3, sub_8E5C5(4u, 119, 124), sizeof(v3));
  dword_19BFD8 = 25 * word_19999A / 20;
  if ( word_19999A > 54 )
    dword_19BFD8 = 372;
  if ( strlen(byte_19C2F4) < 0x23 )
  {
    v0 = &byte_19C2F4[-1];
    do
      ++v0;
    while ( *v0 );
    strcpy(v0, asc_17957D);
  }
  sub_124D7A();
  v1 = sub_127C27((int)aRaceoptLbx_1, 0, dword_193174);
  sub_12A478(0, 0, v1);
  sub_124E36();
  v2 = sub_12DAA4(325, 30);
  dword_19C2E4 = (int)sub_110D3C(dword_192ED4, v2);
  sub_12D8F5(325, 30, dword_19C2E4);
  word_19C2F0 = 0;
  strcpy(byte_19C2F4, sub_7A990(0xA1u));
  sub_120DB3(4, (int)v4);
  sub_120DED(2, 1);
  sub_122A6E(0, 0, (int)byte_19C2F4, dword_19C2E4);
  JUMPOUT(0x7BF57);
}
// 7C8E1: control flows out of bounds to 7BF57
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 19999A: using guessed type int16_t word_19999A;
// 19BFD8: using guessed type int dword_19BFD8;
// 19C2E4: using guessed type int dword_19C2E4;
// 19C2F0: using guessed type int16_t word_19C2F0;


//----- (0007C8E6) --------------------------------------------------------
_BOOL1 __fastcall sub_7C8E6( int a1)
{
  _BOOL1 v3; // cl
  int16_t i; // ax
  int v5; // edx

  if ( *(_BYTE *)(113 * a1 + dword_19306C + 22) == 6 )
    return 0;
  v3 = 0;
  for ( i = 0; i < 5 && !v3; ++i )
  {
    v5 = *(int16_t *)(113 * a1 + dword_19306C + 2 * i + 74);
    if ( v5 > -1 )
      v3 = *(_BYTE *)(dword_1930D4 + 17 * v5 + 4) == 3;
  }
  return v3;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0007C94E) --------------------------------------------------------
int16_t __fastcall sub_7C94E( int a1)
{
  int16_t i; // ax
  int v3; // ebx
  _WORD v5[6]; // [esp+0h] [ebp-Ch] BYREF

  memset(v5, 0, 10);
  for ( i = 0; i < 5; ++i )
  {
    v3 = *(int16_t *)(2 * i + 113 * a1 + dword_19306C + 74);
    if ( v3 != -1 && *(_BYTE *)(17 * v3 + dword_1930D4 + 4) && *(uint8_t *)(17 * v3 + dword_1930D4 + 4) < 4u )
      v5[i] = 1;
  }
  return *(_WORD *)(113 * a1 + dword_19306C + 2 * (uint16_t)sub_FE92D((int)v5, 5) + 74);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0007C9EE) --------------------------------------------------------
char __fastcall sub_7C9EE(uint8_t *a1, int a2)
{
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edx
  uint16_t v8; // ax
  uint16_t v9; // ax
  uint16_t v10; // ax
  _WORD v12[10]; // [esp+0h] [ebp-30h] BYREF
  _BYTE v13[4]; // [esp+14h] [ebp-1Ch] BYREF
  int16_t v14; // [esp+18h] [ebp-18h]
  int16_t v15; // [esp+1Ah] [ebp-16h]
  int16_t v16; // [esp+1Ch] [ebp-14h]
  _BYTE v17[6]; // [esp+20h] [ebp-10h] BYREF
  int16_t v18; // [esp+26h] [ebp-Ah]
  int16_t v19; // [esp+28h] [ebp-8h]
  char v20; // [esp+2Ch] [ebp-4h]

  memset(v13, 0, 10);
  memset(v17, 0, 10);
  memset(v12, 0, sizeof(v12));
  v20 = 1;
  switch ( a2 )
  {
    case 10:
      v14 = 1;
      v15 = 1;
      v16 = 1;
      v18 = 1;
      v19 = 1;
      if ( a1[4] == 3 )
        goto LABEL_3;
      v4 = 0;
      do
      {
        v5 = (int16_t)v4++;
        v12[v5] = 1;
      }
      while ( (int16_t)v4 < 10 );
      break;
    case 11:
    case 14:
      goto LABEL_8;
    case 12:
      v14 = 1;
LABEL_8:
      v15 = 1;
      v16 = 1;
      v18 = 1;
      v19 = 1;
      v12[8] = 1;
      v12[9] = 1;
      break;
    case 13:
      v15 = 1;
      v16 = 1;
      v18 = 1;
      v19 = 1;
      if ( a1[4] == 3 )
      {
LABEL_3:
        v20 = 0;
      }
      else
      {
        v6 = 0;
        do
        {
          v7 = (int16_t)v6++;
          v12[v7] = 1;
        }
        while ( (int16_t)v6 < 10 );
      }
      break;
    default:
      break;
  }
  a1[4] = 3;
  v8 = sub_FE92D((int)v13, 5);
  if ( v8 > (int)a1[5] )
    a1[5] = v8;
  v9 = sub_FE92D((int)v17, 5);
  if ( v9 > (int)a1[10] )
    a1[10] = v9;
  if ( v20 )
  {
    v10 = sub_FE92D((int)v12, 10);
    if ( v10 > (int)a1[8] )
      a1[8] = v10;
  }
  sub_8C6C0(a1[2], (int)&a1[-dword_1930D4] / 17);
  return sub_7CB7C(dword_19306C + 113 * a1[2], a2);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0007CB7C) --------------------------------------------------------
char __fastcall sub_7CB7C(int a1, int a2)
{
  _BOOL1 v3; // ch
  int v4; // edi
  int v5; // eax
  int v6; // edx
  int16_t i; // cx
  char *v8; // esi
  char v10[200]; // [esp+0h] [ebp-5Ah] BYREF
  int v11; // [esp+C8h] [ebp+6Eh]
  int v12; // [esp+CCh] [ebp+72h]
  int v13; // [esp+D0h] [ebp+76h]
  int16_t v14; // [esp+D4h] [ebp+7Ah] BYREF
  char v15; // [esp+D8h] [ebp+7Eh]

  v3 = 0;
  v12 = -1;
  v4 = 2;
  v13 = (a1 - dword_19306C) / 113;
  v15 = 0;
  sub_784A0(a2, v10);
  if ( a2 == 12 )
  {
    v4 = 2710;
  }
  else if ( a2 == 13 )
  {
    v4 = 3918;
  }
  LOWORD(v5) = 0;
  while ( (int16_t)v5 < 5 && !v3 )
  {
    v11 = 113 * (int16_t)v13;
    v6 = *(int16_t *)(dword_19306C + v11 + 2 * (int16_t)v5 + 74);
    if ( v6 > -1 )
      v3 = *(_BYTE *)(17 * v6 + dword_1930D4 + 15) > 0;
    LOWORD(v5) = v5 + 1;
  }
  if ( v3 && (v5 = v4 >> *(_BYTE *)(a1 + 40), (v5 & 1) != 0) )
  {
    v15 = 1;
    if ( (int16_t)v12 == -1 )
    {
      for ( i = 0; i < 5; ++i )
      {
        v5 = *(int16_t *)(dword_19306C + 113 * (int16_t)v13 + 2 * i + 74);
        if ( v5 > -1 )
        {
          v5 *= 17;
          *(_BYTE *)(dword_1930D4 + v5 + 15) = 0;
        }
      }
    }
    else
    {
      LOBYTE(v5) = 17 * v12;
      *(_BYTE *)(dword_1930D4 + 17 * (int16_t)v12 + 15) = 0;
    }
  }
  else if ( !v3 )
  {
    v15 = 1;
  }
  if ( v15 )
  {
    v8 = (char *)(a1 + 40);
    do
      LOBYTE(v5) = sub_F4D46(v13, &v14, v8, 1, v4);
    while ( *v8 <= 0 );
  }
  return v5;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0007CCB5) --------------------------------------------------------
void __fastcall sub_7CCB5( int a1)
{
  int16_t v1; // dx
  int v2; // esi
  int16_t v3; // bx
  int16_t v4; // cx
  int16_t v5; // ax
  int16_t i; // ax
  int16_t v7; // cx

  v1 = -1;
  v2 = 0;
  v3 = 0;
  while ( !v3 )
  {
    v4 = sub_1247A0(5u) - 1;
    if ( v4 > -1 && v4 < 5 )
    {
      v5 = *(_WORD *)(113 * a1 + dword_19306C + 2 * v4 + 74);
      if ( v5 == -1 || v5 > -1 && v5 < word_1999A2 && *(_BYTE *)(dword_1930D4 + 17 * word_1999A2 + 4) != 3 )
      {
        v3 = 1;
        v1 = v4;
      }
      if ( (int16_t)++v2 > 100 )
        break;
    }
  }
  for ( i = 0; i < 5 && !v3; ++i )
  {
    v7 = *(_WORD *)(dword_19306C + 113 * a1 + 2 * i + 74);
    if ( v7 == -1 || *(_BYTE *)(dword_1930D4 + 17 * v7 + 4) != 3 )
    {
      v3 = 1;
      v1 = i;
    }
  }
  if ( v1 == -1 )
    sub_1247A0(5u);
  JUMPOUT(0x7BF55);
}
// 7CD9E: control flows out of bounds to 7BF55
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1999A2: using guessed type int16_t word_1999A2;


//----- (0007CDA3) --------------------------------------------------------
int __fastcall sub_7CDA3(_WORD *a1, _WORD *a2)
{
  if ( *a2 == *a1 )
    return 0;
  if ( *a2 <= *a1 )
    return 1;
  return -1;
}


//----- (0007CDC0) --------------------------------------------------------
int __fastcall sub_7CDC0(_DWORD *a1, _DWORD *a2)
{
  return *a1 - *a2;
}


//----- (0007CDC5) --------------------------------------------------------
void sub_7CDC5()
{
  int16_t v0; // ax
  int v1; // edx
  int16_t v2; // ax
  int16_t v3; // cx
  int16_t v4; // si
  int16_t i; // bx
  int v6; // eax
  int16_t j; // bx
  char v8; // bl
  unsigned int v9; // esi
  int16_t v10; // di
  char v11; // bh
  int16_t v12; // si
  int16_t v13; // ax
  int v14; // edx
  int v15; // esi
  char v16; // bl
  int v17; // eax
  _WORD v18[72]; // [esp+0h] [ebp-FEh] BYREF
  _WORD v19[72]; // [esp+90h] [ebp-6Eh] BYREF
  _BYTE v20[72]; // [esp+120h] [ebp+22h] BYREF
  int v21; // [esp+168h] [ebp+6Ah]
  unsigned int v22; // [esp+16Ch] [ebp+6Eh]
  unsigned int v23; // [esp+170h] [ebp+72h]
  int v24; // [esp+174h] [ebp+76h]
  int v25; // [esp+178h] [ebp+7Ah]
  int v26; // [esp+17Ch] [ebp+7Eh]

  v0 = sub_7926C(word_199A0C);
  v1 = v0 * v0;
  v2 = sub_7926C(word_199A0A);
  v3 = 0;
  v23 = v2 * v2 + v1;
  if ( byte_19A006 == -1 )
  {
    if ( (uint8_t)byte_19C319 <= 0x14u )
      LOBYTE(v6) = byte_19C319;
    else
      LOBYTE(v6) = 20;
  }
  else
  {
    v4 = 0;
    for ( i = 0; i < word_19999A; ++i )
    {
      if ( sub_7A115(i)
        || sub_798C4(i)
        || sub_7987A(i)
        || sub_7C396(i)
        || sub_79001(i)
        || *(_BYTE *)(dword_19306C + 113 * i + 22) == 6 )
      {
        ++v4;
      }
    }
    v6 = word_19999A - v4;
    if ( byte_19A006 <= v6 )
      LOBYTE(v6) = byte_19A006;
    v23 = 0;
    byte_19A006 = v6;
  }
  byte_19C319 = v6;
  if ( !(_BYTE)v6 )
    goto LABEL_48;
  memset(v19, 0, sizeof(v19));
  memset(v20, 0, sizeof(v20));
  memset(v18, -1, sizeof(v18));
  for ( j = 0; j < word_19999A; ++j )
  {
    if ( !sub_7A115(j)
      && !sub_7C396(j)
      && !sub_798C4(j)
      && !sub_7987A(j)
      && !sub_79001(j)
      && *(_BYTE *)(dword_19306C + 113 * j + 22) != 6 )
    {
      v19[j] = 1;
    }
  }
  v24 = 0;
LABEL_47:
  if ( (uint8_t)byte_19C319 <= (int16_t)v24 )
LABEL_48:
    JUMPOUT(0x7BD7A);
  v25 = 0;
  v8 = 0;
  if ( 2 * v3 <= 1 )
    v9 = 1;
  else
    v9 = 2 * v3;
  v10 = -1;
  v22 = v23 / v9;
  while ( 1 )
  {
    v11 = 1;
    v12 = 0;
    v26 = sub_FE92D((int)v19, word_19999A);
    while ( v12 < v3 && v11 )
    {
      v13 = v18[v12];
      v21 = (int16_t)v26;
      if ( sub_7B0B4(v26, v13) < v22 )
        v11 = 0;
      ++v12;
    }
    if ( v11 )
      break;
    if ( (int16_t)++v25 > 250 )
      goto LABEL_43;
LABEL_44:
    if ( v8 )
    {
      if ( v10 != -1 )
      {
        v14 = 113 * v10;
        v15 = dword_19306C;
        v16 = *(_BYTE *)(v14 + dword_19306C + 40);
        *(_BYTE *)(v14 + dword_19306C + 40) = 9;
        *(_BYTE *)(v14 + v15 + 100) = v16;
        ++v24;
        v20[v10] = 1;
        v19[v10] = 0;
        v17 = v3++;
        v18[v17] = v10;
        goto LABEL_47;
      }
      goto LABEL_48;
    }
  }
  v10 = v26;
LABEL_43:
  v8 = 1;
  goto LABEL_44;
}
// 7D031: control flows out of bounds to 7BD7A
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;
// 19A006: using guessed type char byte_19A006;
// 19C319: using guessed type char byte_19C319;


//----- (0007D036) --------------------------------------------------------
_BOOL1 sub_7D036()
{
  char v0; // dl

  v0 = 1;
  if ( (uint16_t)byte_199BF1 <= 9u )
    return *(_DWORD *)(dword_19C038 + 4 * byte_199BF1) <= 0;
  return v0;
}
// 199BF1: using guessed type char byte_199BF1;
// 19C038: using guessed type int dword_19C038;


//----- (0007D061) --------------------------------------------------------
int __fastcall sub_7D061(_WORD *a1, _WORD *a2)
{
  int *v2; // eax
  int v3; // eax
  int v4; // eax
  uint16_t v5; // dx
  int v6; // eax
  int v7; // eax
  int16_t v8; // dx
  int16_t v9; // si
  int v10; // eax
  int v11; // eax
  int v12; // edx
  _WORD *v13; // eax
  int16_t v14; // ax
  int16_t *v15; // ebx
  int v16; // eax
  int v17; // eax
  int16_t v18; // cx
  int v19; // eax
  int16_t v20; // dx
  int v21; // esi
  char v22; // al
  int16_t v23; // dx
  int16_t v24; // bx
  int v25; // esi
  int v26; // esi
  char v27; // al
  int16_t v28; // ax
  uint16_t v29; // dx
  int v30; // esi
  int v31; // edi
  int16_t v32; // dx
  int16_t v33; // bx
  int16_t v34; // ax
  int16_t v35; // dx
  int v36; // eax
  int v37; // ebx
  int16_t v38; // dx
  int result; // eax
  char v42[8]; // [esp+8h] [ebp-40h] BYREF
  char v43[8]; // [esp+10h] [ebp-38h] BYREF
  int v44; // [esp+18h] [ebp-30h]
  int v45; // [esp+1Ch] [ebp-2Ch]
  int v46; // [esp+20h] [ebp-28h]
  int v47; // [esp+24h] [ebp-24h]
  int v48; // [esp+28h] [ebp-20h]
  int v49; // [esp+2Ch] [ebp-1Ch]
  int v50; // [esp+30h] [ebp-18h]
  int v51; // [esp+34h] [ebp-14h]
  int v52; // [esp+38h] [ebp-10h]
  int v53; // [esp+3Ch] [ebp-Ch]
  int v54; // [esp+40h] [ebp-8h]
  int v55; // [esp+44h] [ebp-4h]

  v55 = 2;
  word_19C05C = -1000;
  word_19C060 = -1000;
  if ( word_199830 )
  {
    if ( (uint16_t)word_199830 <= 1u )
    {
      v7 = dword_19C044;
      v8 = **(_WORD **)(dword_19C044 + 32);
      word_19983C = 144;
      *a1 = v8;
      word_19983A = 25;
      v10 = *(_DWORD *)(v7 + 32);
      v9 = 0;
      LOWORD(v10) = *(_WORD *)(v10 + 2);
      v52 = 0;
      *a2 = v10;
      do
      {
        LOWORD(v10) = word_19983C;
        v11 = v10 + 26;
        v47 = v11;
        LOWORD(v11) = word_19983A;
        v12 = v11 + 41 + v52;
        v13 = *(_WORD **)(dword_19C044 + 36);
        v46 = v12;
        v14 = sub_11438B(v47, v12, *v13 + v47, v13[1] + v12, &unk_179597, 40);
        v44 = 2 * v9;
        *(_WORD *)(v44 + dword_19C038 + 82) = v14;
        LOWORD(v12) = sub_11438B(
                        v47 + 23,
                        v12,
                        v47 + 217,
                        *(_WORD *)(*(_DWORD *)(dword_19C044 + 36) + 2) + v46,
                        &unk_179597,
                        41);
        v10 = v44 + dword_19C038;
        v52 += 17;
        ++v9;
        *(_WORD *)(v44 + dword_19C038 + 580) = v12;
      }
      while ( v9 < 13 );
      *(_WORD *)(dword_19C038 + 108) = (uint16_t)sub_1151B0(
                                                           word_19983C + 97,
                                                           word_19983A + 338,
                                                           (int)&unk_179597,
                                                           *(_WORD **)(dword_19C044 + 40),
                                                           &aNsqoA[5],
                                                           40);
    }
    else if ( (uint16_t)word_199830 <= 3u )
    {
      if ( word_199A08 == 10 )
      {
        v15 = *(int16_t **)(dword_19C044 + 44);
        word_19983C = (640 - *v15) / 2;
        word_19983A = (480 - v15[1]) / 2;
      }
      else
      {
        word_19983C = 144;
        word_19983A = 25;
      }
      v16 = dword_19C044;
      if ( word_199830 == 2 )
      {
        *a1 = **(_WORD **)(dword_19C044 + 44);
        v17 = *(_DWORD *)(v16 + 44);
      }
      else
      {
        *a1 = **(_WORD **)(dword_19C044 + 56);
        v17 = *(_DWORD *)(v16 + 56);
      }
      *a2 = *(_WORD *)(v17 + 2);
      sub_7D954();
      sub_7E6C1(v55, v42, v43);
      v18 = 0;
      sub_120F07((int)v43);
      do
      {
        if ( v18 == byte_199BF1 )
        {
          v19 = sub_806A2(&byte_1996BE[37 * byte_199BF1], 37);
        }
        else
        {
          v19 = 37 * v18;
          if ( byte_1996BE[v19] == 3 )
            sub_80658(&byte_1996BE[v19]);
        }
        ++v18;
      }
      while ( v18 < 10 );
      if ( word_199830 == 2 )
      {
        v54 = 0;
        v51 = 0;
        do
        {
          LOWORD(v19) = word_19983C;
          v49 = v19 + 29;
          v20 = v51 + word_19983A + 24;
          if ( *(_BYTE *)((int16_t)v54 + dword_19C038 + 170) == 2 )
            strcpy(&byte_1996BE[37 * (int16_t)v54], "* INVALID *");
          v21 = (int16_t)v54;
          sub_11FCC(v54);
          *(_BYTE *)(v21 + dword_19C038 + 550) = v22;
          v23 = sub_11438B(v49, v20, v49 + 197, v20 + 24, &unk_179597, 41);
          HIWORD(v19) = HIWORD(v21);
          v51 += 31;
          ++v54;
          *(_WORD *)(dword_19C038 + 2 * v21 + 56) = v23;
        }
        while ( (int16_t)v54 < 10 );
        *(_WORD *)(dword_19C038 + 76) = sub_11438B(629, 469, 639, 479, aD_0, 51);
        *(_WORD *)(dword_19C038 + 560) = (uint16_t)sub_1151B0(
                                                             word_19983C + 37,
                                                             word_19983A + 337,
                                                             (int)&unk_179597,
                                                             *(_WORD **)(dword_19C044 + 48),
                                                             asc_179595,
                                                             40);
      }
      else
      {
        v53 = 0;
        v50 = 0;
        do
        {
          LOWORD(v19) = word_19983C;
          v48 = v19 + 29;
          v24 = word_19983A + 24 + v50;
          v25 = (int16_t)v53;
          sub_120BB5((int16_t)v55, (int)v42);
          if ( *(_BYTE *)(v25 + dword_19C038 + 170) == 2 )
            strcpy(&byte_1996BE[37 * v25], "* INVALID *");
          v26 = (int16_t)v53;
          sub_11FCC(v53);
          *(_BYTE *)(v26 + dword_19C038 + 550) = v27;
          v28 = sub_122259();
          v29 = (uint16_t)sub_115BEA(v48 - 3, v24, 200, v28, (int)&byte_1996BE[37 * v26], 30, 0, 0, 41, 0);
          HIWORD(v19) = HIWORD(v26);
          v50 += 31;
          ++v53;
          *(_WORD *)(dword_19C038 + 2 * v26 + 56) = v29;
        }
        while ( (int16_t)v53 < 10 );
        v30 = 0;
        v31 = 0;
        do
        {
          v32 = v31 + word_19983A + 24;
          v33 = word_19983C + 29;
          v45 = (int16_t)(v32 + 2 * sub_122259());
          v44 = (int16_t)(v33 + 215);
          v34 = sub_122259();
          v31 += 31;
          v35 = sub_11438B(v33, v32 + v34 + 1, v44, v45, &unk_179597, 41);
          v36 = dword_19C038;
          v37 = (int16_t)v30++;
          *(_WORD *)(dword_19C038 + 2 * v37 + 124) = v35;
        }
        while ( (int16_t)v30 < 10 );
        *(_WORD *)(v36 + 76) = -1000;
        *(_WORD *)(dword_19C038 + 562) = (uint16_t)sub_1151B0(
                                                             word_19983C + 37,
                                                             word_19983A + 338,
                                                             (int)&unk_179597,
                                                             *(_WORD **)(dword_19C044 + 60),
                                                             &aNsqoA[1],
                                                             40);
      }
      *(_WORD *)(dword_19C038 + 110) = (uint16_t)sub_1151B0(
                                                           word_19983C + 171,
                                                           word_19983A + 338,
                                                           (int)&unk_179597,
                                                           *(_WORD **)(dword_19C044 + 52),
                                                           aC_0,
                                                           40);
    }
  }
  else
  {
    v2 = (int *)dword_19C044;
    *a1 = **(_WORD **)dword_19C044;
    v3 = *v2;
    word_19983C = 144;
    LOWORD(v3) = *(_WORD *)(v3 + 2);
    word_19983A = 25;
    *a2 = v3;
    if ( (uint8_t)byte_199F3A > 1u )
    {
      v4 = dword_19C038;
      *(_WORD *)(dword_19C038 + 40) = -1000;
      *(_WORD *)(v4 + 46) = -1000;
    }
    else
    {
      *(_WORD *)(dword_19C038 + 40) = (uint16_t)sub_1151B0(
                                                          word_19983C + 147,
                                                          word_19983A + 43,
                                                          (int)&unk_179597,
                                                          *(_WORD **)(dword_19C044 + 8),
                                                          asc_179595,
                                                          40);
      *(_WORD *)(dword_19C038 + 46) = (uint16_t)sub_1151B0(
                                                          word_19983C + 40,
                                                          word_19983A + 88,
                                                          (int)&unk_179597,
                                                          *(_WORD **)(dword_19C044 + 12),
                                                          aNsqoA,
                                                          40);
    }
    *(_WORD *)(dword_19C038 + 42) = (uint16_t)sub_1151B0(
                                                        word_19983C + 40,
                                                        word_19983A + 43,
                                                        (int)&unk_179597,
                                                        *(_WORD **)(dword_19C044 + 4),
                                                        &aNsqoA[1],
                                                        40);
    *(_WORD *)(dword_19C038 + 44) = (uint16_t)sub_1151B0(
                                                        word_19983C + 147,
                                                        word_19983A + 88,
                                                        (int)&unk_179597,
                                                        *(_WORD **)(dword_19C044 + 16),
                                                        &aNsqoA[2],
                                                        40);
    *(_WORD *)(dword_19C038 + 48) = (uint16_t)sub_1151B0(
                                                        word_19983C + 40,
                                                        word_19983A + 307,
                                                        (int)&unk_179597,
                                                        *(_WORD **)(dword_19C044 + 20),
                                                        &aNsqoA[3],
                                                        40);
    v5 = (uint16_t)sub_1151B0(
                             word_19983C + 151,
                             word_19983A + 307,
                             (int)&unk_179597,
                             *(_WORD **)(dword_19C044 + 24),
                             &aNsqoA[4],
                             40);
    v6 = dword_19C038;
    *(_WORD *)(dword_19C038 + 50) = v5;
    word_19C05C = sub_115478(word_19983C + 62, word_19983A + 194, 0, 156, 0, 156, 155, 12, v6 + 116, &unk_179597, 0);
    word_19C060 = sub_115478(
                    word_19983C + 62,
                    word_19983A + 216,
                    0,
                    156,
                    0,
                    156,
                    155,
                    12,
                    dword_19C038 + 118,
                    &unk_179597,
                    0);
  }
  *(_WORD *)(dword_19C038 + 114) = sub_11438B(
                                     word_19983C,
                                     word_19983A,
                                     *a1 + word_19983C,
                                     *a2 + word_19983A,
                                     &unk_179597,
                                     0);
  v38 = sub_11438B(0, 0, 639, 479, &aNsqoA[4], 41);
  result = dword_19C038;
  *(_WORD *)(dword_19C038 + 112) = v38;
  return result;
}
// 7D572: variable 'v19' is possibly undefined
// 7D5AE: variable 'v22' is possibly undefined
// 7D6DD: variable 'v27' is possibly undefined
// 179598: using guessed type wchar_t aNsqoA[6];
// 199830: using guessed type int16_t word_199830;
// 19983A: using guessed type int16_t word_19983A;
// 19983C: using guessed type int16_t word_19983C;
// 199A08: using guessed type int16_t word_199A08;
// 199BF1: using guessed type char byte_199BF1;
// 199F3A: using guessed type char byte_199F3A;
// 19C038: using guessed type int dword_19C038;
// 19C044: using guessed type int dword_19C044;
// 19C05C: using guessed type int16_t word_19C05C;
// 19C060: using guessed type int16_t word_19C060;


//----- (0007D892) --------------------------------------------------------
_DWORD *sub_7D892()
{
  _DWORD *result; // eax

  dword_19C044 = (int)sub_110CEE(dword_192ED4, 101);
  memset(dword_19C044, 0, 101);
  dword_19268C = (int)sub_110D3C(dword_192ED4, 1000);
  dword_192688 = (int)sub_110D3C(dword_192ED4, 1000);
  result = sub_110D3C(dword_192ED4, 632);
  dword_19C038 = (int)result;
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192688: using guessed type int dword_192688;
// 19268C: using guessed type int dword_19268C;
// 192ED4: using guessed type int dword_192ED4;
// 19C038: using guessed type int dword_19C038;
// 19C044: using guessed type int dword_19C044;


//----- (0007D8F3) --------------------------------------------------------
int __usercall sub_7D8F3( unsigned int a1, int a2, int16_t *a3)
{
  int16_t v4; // ax
  uint16_t v5; // ax
  char *v6; // eax
  int v8; // [esp-4h] [ebp-104h]
  _BYTE v9[256]; // [esp+0h] [ebp-100h] BYREF

  v4 = a2 + 1;
  if ( a1 >= 2u )
  {
    if ( a1 <= 2u )
    {
      v8 = v4;
      v5 = 179;
    }
    else
    {
      if ( a1 != 3 )
        return sub_7E59A((int)v9, 3u, a3);
      v8 = v4;
      v5 = 180;
    }
    goto LABEL_9;
  }
  if ( a1 == 1 )
  {
    v8 = v4;
    v5 = 178;
LABEL_9:
    v6 = sub_7A990(v5);
    sprintf(v9, v6, v8);
  }
  return sub_7E59A((int)v9, 3u, a3);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);


//----- (0007D954) --------------------------------------------------------
void sub_7D954()
{
  int v0; // ecx
  int v1; // ebx
  char *v2; // edi
  _BYTE *v3; // ebx
  char *v4; // edi
  int v5; // eax
  char v6; // al
  int v7; // [esp+0h] [ebp-30h] BYREF
  char v8[20]; // [esp+4h] [ebp-2Ch] BYREF
  char v9[20]; // [esp+18h] [ebp-18h] BYREF
  int v10; // [esp+2Ch] [ebp-4h]

  v0 = 0;
  do
  {
    v10 = (int16_t)v0;
    itoa((int16_t)v0 + 1, v9, 10, v0);
    strcpy(v8, "SAVE");
    v1 = v7;
    v2 = (char *)&v7 + 3;
    do
      ++v2;
    while ( *v2 );
    strcpy(v2, v9);
    v3 = (_BYTE *)(v10 + v1);
    v4 = (char *)&v7 + 3;
    do
      ++v4;
    while ( *v4 );
    strcpy(v4, aGam_0);
    *v3 = 0;
    if ( FindMoxSetPath_1114D7(v8, v8) )
    {
      sub_11E56((int)v8);
      if ( v5 > 0 && sub_11E04((int)v8) )
      {
        sub_11FCC(v10);
        if ( v6 == 3 || v6 == 2 )
          *(_BYTE *)(v7 + (int16_t)v0) = 3;
      }
      else
      {
        *v3 = 2;
      }
    }
    else
    {
      *v3 = 1;
    }
    ++v0;
  }
  while ( (int16_t)v0 < 10 );
}
// 7D9D0: variable 'v5' is possibly undefined
// 7D9ED: variable 'v6' is possibly undefined
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (0007DA13) --------------------------------------------------------
void sub_7DA13()
{
  sub_1318D4(0, 255);
  sub_133237();
  sub_124B65();
  sub_124D41();
  sub_84E9D();
  sub_12E148(22, 22, 527, 421, dword_19C150);
  sub_90006(22, 22, 527, 421);
  sub_124DEC();
  sub_124C08();
}
// 19C150: using guessed type int dword_19C150;


//----- (0007DA76) --------------------------------------------------------
void __fastcall sub_7DA76(_WORD *a1, int a2, int a3, int a4)
{
  int v4; // edx
  _WORD *v5; // eax
  int16_t v6; // ax
  int16_t v7; // si
  int16_t j; // ax
  uint16_t v9; // ax
  char *v10; // eax
  int v11; // eax
  int16_t i; // bx
  char *v13; // eax
  _BYTE v15[80]; // [esp+4h] [ebp-68h] BYREF
  int v16; // [esp+54h] [ebp-18h]
  int16_t v17; // [esp+58h] [ebp-14h] BYREF
  int16_t v18; // [esp+5Ch] [ebp-10h] BYREF
  int16_t v19; // [esp+60h] [ebp-Ch]
  char v20; // [esp+64h] [ebp-8h]
  char v21; // [esp+68h] [ebp-4h]

  sub_7E913();
  v21 = 0;
  v16 = 0;
  v20 = 1;
  strcpy((char *)word_19C048, sub_7A990(0x184u));
  byte_19C068 = 0;
  if ( word_199A08 == 10 )
  {
    v20 = 0;
  }
  else
  {
    sub_6F850();
    sub_11C2F0();
    a4 = 479;
    a3 = 639;
    byte_199F09 = sub_11438B(0, 0, 639, 479, &aNsqoA[4], 41);
  }
  sub_1191CA((int)sub_7F206, 1);
  sub_11C2F0();
  v4 = (int)&v17;
  v5 = (_WORD *)sub_7D061(&v18, &v17);
  byte_199F09 = 0;
  while ( 1 )
  {
    if ( (_WORD)v16 )
    {
      for ( i = 0; i < 10; ++i )
      {
        v13 = &byte_1996BE[37 * i];
        sub_80658(v13);
      }
      JUMPOUT(0x7DA0C);
    }
    v6 = sub_1171AB((int)v5, v4, a3, a4);
    v19 = -1;
    a3 = dword_19C038;
    v7 = v6;
    for ( j = 0; ; ++j )
    {
      if ( j >= 10 )
        goto LABEL_11;
      if ( v7 == *(_WORD *)(dword_19C038 + 2 * j + 56) )
        break;
    }
    v19 = j;
LABEL_11:
    if ( v7 == *(_WORD *)(dword_19C038 + 560) && v19 == -1 && byte_199BF1 > -1 && byte_199BF1 < 10 )
    {
      byte_1820B8 = 1;
      v19 = byte_199BF1;
    }
    v4 = v19;
    if ( v19 > -1 && v19 < 10 )
    {
      if ( *(_BYTE *)(v19 + dword_19C038 + 170) )
      {
        v9 = *(uint8_t *)(v19 + dword_19C038 + 170);
        v16 = 2;
        sub_7D8F3(v9, v19, word_19C048);
      }
      else
      {
        if ( byte_199BE2 && !byte_199F19 )
        {
          sub_11C2F0();
          *(_BYTE *)(dword_19C044 + 100) = 1;
          sub_124D41();
          a4 = 1;
          a3 = -1;
          sub_7EDF2(*(int16_t **)(dword_19C044 + 44), *(int16_t *)(*(_DWORD *)(dword_19C044 + 44) + 2), -1, 1u);
        }
        v4 = v19;
        LOBYTE(a3) = sub_10E2F(v19, v19, a3, a4);
        v21 = a3;
        byte_199BF1 = v19;
        sub_12030();
        if ( (_BYTE)a3 )
        {
          byte_19C066 = 1;
          if ( byte_199F3A == 1 )
            word_199A10 = 17;
          else
            word_199A10 = 39;
        }
        else
        {
          v10 = sub_7A990(0xB8u);
          sprintf(v15, v10, v4);
          v4 = 3;
          sub_7E59A((int)v15, 3u, word_19C048);
          word_199A10 = (uint8_t)byte_199F19;
        }
        if ( v20 && dword_1975B8 )
        {
          v4 = (int)&byte_199F28;
          a3 = 0;
          sub_8F1C4((void (__fastcall *)(int, int))sub_84E9D, &byte_199F28, 0);
        }
        v16 = 1;
        *a1 = 1;
      }
    }
    v5 = (_WORD *)dword_19C038;
    if ( v7 == *(_WORD *)(dword_19C038 + 110) )
    {
      word_199830 = 0;
      v16 = 1;
      if ( word_199A08 == 10 )
      {
        v5 = a1;
LABEL_37:
        *v5 = 1;
      }
    }
    else if ( v7 == *(_WORD *)(dword_19C038 + 112) )
    {
      v5 = a1;
      v21 = 0;
      v16 = 1;
      goto LABEL_37;
    }
    if ( !(_WORD)v16 )
    {
      sub_124D41();
      v11 = sub_1192D1();
      v5 = (_WORD *)sub_1077D(v11, v4, a3, word_19C048);
    }
  }
}
// 7DD3C: control flows out of bounds to 7DA0C
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 179598: using guessed type wchar_t aNsqoA[6];
// 1820B8: using guessed type char byte_1820B8;
// 1975B8: using guessed type int dword_1975B8;
// 199830: using guessed type int16_t word_199830;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199BE2: using guessed type char byte_199BE2;
// 199BF1: using guessed type char byte_199BF1;
// 199F09: using guessed type char byte_199F09;
// 199F19: using guessed type char byte_199F19;
// 199F28: using guessed type char byte_199F28;
// 199F3A: using guessed type char byte_199F3A;
// 19C038: using guessed type int dword_19C038;
// 19C044: using guessed type int dword_19C044;
// 19C048: using guessed type int16_t word_19C048[10];
// 19C066: using guessed type char byte_19C066;
// 19C068: using guessed type char byte_19C068;


//----- (0007DD41) --------------------------------------------------------
void __usercall sub_7DD41(int a1, int16_t *a2, char *a3)
{
  int v3; // edx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  _WORD *v7; // eax
  int16_t *v8; // edi
  char v9; // al
  int16_t *v10; // edi
  char v11; // al
  int16_t *v12; // edi
  char v13; // al
  int v14; // eax
  _WORD *v15; // [esp+0h] [ebp-4Eh]
  int16_t v16[100]; // [esp+4h] [ebp-4Ah] BYREF
  int16_t v17[100]; // [esp+CCh] [ebp+7Eh] BYREF
  int16_t v18[100]; // [esp+194h] [ebp+146h] BYREF
  int v19; // [esp+25Ch] [ebp+20Eh]
  char v20; // [esp+260h] [ebp+212h]

  v3 = 1;
  v20 = 0;
  sub_1191CA((int)sub_7F701, 1);
  sub_6F826();
  v5 = 0;
  while ( 1 )
  {
    if ( (_WORD)v5 )
    {
      if ( v20 && byte_199BE2 )
      {
        sub_11C2F0();
        sub_7EDF2(*(int16_t **)dword_19C044, *(int16_t *)(*(_DWORD *)dword_19C044 + 2), -1, 0);
        *(_BYTE *)(dword_19C044 + 100) = 1;
      }
      JUMPOUT(0x7E50B);
    }
    v6 = sub_1171AB(v4, v3, v5, a1);
    v19 = v6;
    if ( (_WORD)v6 == *(_WORD *)(dword_19C038 + 50) )
    {
      byte_19C06A = 1;
      v5 = 1;
      if ( word_199830 )
        goto LABEL_36;
      v7 = v15;
      goto LABEL_6;
    }
    if ( (_WORD)v6 == *(_WORD *)(dword_19C038 + 46) )
      break;
    if ( (_WORD)v6 == *(_WORD *)(dword_19C038 + 44) )
    {
      v10 = v16;
      a3 = sub_7A990(0xBBu);
      do
      {
        v11 = *a3++;
        *(_BYTE *)v10 = v11;
        v10 = (int16_t *)((char *)v10 + 1);
      }
      while ( v11 );
      a2 = v16;
      if ( (uint16_t)sub_7E59A((int)v16, 1u, v16) )
      {
        sub_1160B(9, 1, v5, a1);
        byte_199BF1 = 10;
        sub_12030();
        if ( byte_199F3A == 2 || byte_199F3A == 3 )
        {
          sub_FA97C(word_19999C, (int)v16);
          sub_139062();
        }
        v7 = v15;
        v5 = 1;
        word_199A10 = 7;
        goto LABEL_6;
      }
LABEL_12:
      sub_124D7A();
      a1 = 479;
      sub_128C32(0, 0, 639, 479, 0);
      sub_84E9D();
      sub_8440E();
      sub_124E36();
LABEL_13:
      v5 = 1;
      goto LABEL_36;
    }
    if ( (_WORD)v6 == *(_WORD *)(dword_19C038 + 48) )
    {
      byte_19C06A = 1;
      word_199830 = 1;
      goto LABEL_13;
    }
    if ( (_WORD)v6 == *(_WORD *)(dword_19C038 + 40) )
    {
      v5 = 1;
      sub_1191CA((int)sub_7F206, 1);
      byte_19C06A = 1;
      word_199830 = 2;
    }
    else
    {
      if ( (_WORD)v6 == *(_WORD *)(dword_19C038 + 42) )
      {
        if ( word_1999E4 )
        {
          v12 = v17;
          a3 = sub_7A990(0xB9u);
          do
          {
            v13 = *a3++;
            *(_BYTE *)v12 = v13;
            v12 = (int16_t *)((char *)v12 + 1);
          }
          while ( v13 );
          a2 = v17;
          sub_7E59A((int)v17, 0, v17);
          v7 = v15;
          v5 = 1;
LABEL_6:
          *v7 = 1;
          goto LABEL_36;
        }
        byte_19C06A = 1;
        word_199830 = 3;
        goto LABEL_13;
      }
      if ( (_WORD)v6 == word_19C05C )
      {
        sub_80892();
      }
      else if ( (_WORD)v6 == word_19C060 )
      {
        sub_80918(1);
      }
    }
LABEL_36:
    v4 = dword_19C038;
    v3 = v19;
    if ( (_WORD)v19 == *(_WORD *)(dword_19C038 + 112) )
    {
      v4 = (int)v15;
      v5 = 1;
      v20 = 1;
      *v15 = 1;
    }
    if ( !(_WORD)v5 )
    {
      sub_124D41();
      sub_7F701(v3, (int)a3);
      v4 = sub_1077D(v14, v3, v5, a2);
    }
  }
  v8 = v18;
  a3 = sub_7A990(0xBAu);
  do
  {
    v9 = *a3++;
    *(_BYTE *)v8 = v9;
    v8 = (int16_t *)((char *)v8 + 1);
  }
  while ( v9 );
  a2 = v18;
  if ( (uint16_t)sub_7E59A((int)v18, 1u, v18) )
  {
    byte_199F3A = 0;
    word_199A10 = 13;
    v5 = 1;
    *v15 = 1;
    goto LABEL_36;
  }
  goto LABEL_12;
}
// 7E00A: control flows out of bounds to 7E50B
// 7DD77: variable 'v4' is possibly undefined
// 7DDA9: variable 'v15' is possibly undefined
// 7DFC0: variable 'v14' is possibly undefined
// 199830: using guessed type int16_t word_199830;
// 19999C: using guessed type int16_t word_19999C;
// 1999E4: using guessed type int16_t word_1999E4;
// 199A10: using guessed type int16_t word_199A10;
// 199BE2: using guessed type char byte_199BE2;
// 199BF1: using guessed type char byte_199BF1;
// 199F3A: using guessed type char byte_199F3A;
// 19C038: using guessed type int dword_19C038;
// 19C044: using guessed type int dword_19C044;
// 19C05C: using guessed type int16_t word_19C05C;
// 19C060: using guessed type int16_t word_19C060;
// 19C06A: using guessed type char byte_19C06A;


//----- (0007E00F) --------------------------------------------------------
void __fastcall sub_7E00F(_WORD *a1)
{
  int v2; // ebx
  int16_t *i; // edx
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int16_t v9; // [esp+4h] [ebp-Ch] BYREF
  int16_t v10; // [esp+8h] [ebp-8h] BYREF
  uint8_t v11; // [esp+Ch] [ebp-4h]

  v11 = byte_199CAE;
  sub_6F87A();
  sub_11C2F0();
  v2 = 639;
  byte_199F09 = sub_11438B(0, 0, 639, 479, &aNsqoA[4], 41);
  sub_11C2F0();
  sub_1191CA((int)sub_7FA28, 1);
  i = &v9;
  v4 = 0;
  v5 = sub_7D061(&v10, &v9);
  byte_199F09 = 0;
  while ( 1 )
  {
    if ( (_WORD)v4 )
    {
      LOWORD(i) = v11;
      if ( v11 != *(_WORD *)(dword_19C038 + 606) )
      {
        byte_199CAE = *(_BYTE *)(dword_19C038 + 606);
        if ( (uint8_t)byte_199CAE >= 5u )
          byte_199CAE = 0;
        sub_7A9B1((int)i, (char *)v2, (int16_t *)v4);
        sub_7AA79();
      }
      JUMPOUT(0x7DA0C);
    }
    v2 = sub_1171AB(v5, (int)i, v2, 479);
    for ( i = 0; ; i = (int16_t *)((char *)i + 1) )
    {
      if ( (int16_t)i >= 13 )
        goto LABEL_9;
      v6 = 2 * (int16_t)i + dword_19C038;
      if ( (_WORD)v2 == *(_WORD *)(v6 + 82) || (_WORD)v2 == *(_WORD *)(v6 + 580) )
        break;
    }
    HIWORD(i) = HIWORD(dword_19C038);
    v7 = dword_19C038 + 2 * (int16_t)i;
    LOWORD(i) = *(_WORD *)(v7 + 144) == 0;
    *(_WORD *)(v7 + 144) = (_WORD)i;
LABEL_9:
    v5 = dword_19C038;
    if ( (_WORD)v2 == *(_WORD *)(dword_19C038 + 112) )
    {
      v4 = 1;
      *a1 = 1;
    }
    else if ( (_WORD)v2 == *(_WORD *)(dword_19C038 + 108) )
    {
      word_199830 = 0;
      v4 = 1;
    }
    if ( !(_WORD)v4 )
    {
      sub_124D41();
      sub_7FA28();
      v5 = sub_1077D(v8, (int)i, v2, (int16_t *)v4);
    }
  }
}
// 7E14F: control flows out of bounds to 7DA0C
// 7E10E: variable 'v8' is possibly undefined
// 179598: using guessed type wchar_t aNsqoA[6];
// 199830: using guessed type int16_t word_199830;
// 199CAE: using guessed type char byte_199CAE;
// 199F09: using guessed type char byte_199F09;
// 19C038: using guessed type int dword_19C038;


//----- (0007E154) --------------------------------------------------------
void sub_7E154()
{
  int v0; // ecx
  char *v1; // edi
  int v2; // ebx
  uint64_t v3; // rax
  int v4; // eax
  int64_t v5; // rax
  int16_t v6; // dx
  char *v7; // esi
  int16_t i; // bx
  char *v9; // eax
  char *v10; // [esp-4h] [ebp-6h]
  char *v11; // [esp-4h] [ebp-6h]
  char *v12; // [esp-4h] [ebp-6h]
  char *v13; // [esp-4h] [ebp-6h]
  _WORD *v14; // [esp+0h] [ebp-2h]
  char v15[100]; // [esp+4h] [ebp+2h] BYREF
  int16_t v16; // [esp+68h] [ebp+66h] BYREF
  int16_t v17; // [esp+6Ch] [ebp+6Ah]
  int16_t v18; // [esp+70h] [ebp+6Eh] BYREF
  int v19; // [esp+74h] [ebp+72h]
  char v20; // [esp+78h] [ebp+76h]
  char v21; // [esp+7Ch] [ebp+7Ah]
  char v22; // [esp+80h] [ebp+7Eh]

  v22 = 0;
  v19 = 0;
  v20 = 0;
  v0 = 479;
  strcpy((char *)word_19C048, sub_7A990(0x184u));
  v1 = (char *)word_19C048;
  sub_7E913();
  sub_6F865();
  sub_11C2F0();
  v2 = 639;
  v17 = -1;
  byte_199F09 = sub_11438B(0, 0, 639, 479, &aNsqoA[4], 41);
  sub_11C2F0();
  v21 = 0;
  sub_1191CA((int)sub_7F206, 1);
  v17 = -1;
  v3 = __PAIR64__(&v18, sub_7D061(&v16, &v18));
  byte_199F09 = 0;
  while ( 1 )
  {
    if ( (_WORD)v19 )
    {
      for ( i = 0; i < 10; ++i )
      {
        v9 = &byte_1996BE[37 * i];
        sub_80658(v9);
      }
      if ( v22 && byte_199BE2 )
      {
        sub_11C2F0();
        sub_7EDF2(*(int16_t **)(dword_19C044 + 56), *(int16_t *)(*(_DWORD *)(dword_19C044 + 56) + 2), -1, 1u);
        *(_BYTE *)(dword_19C044 + 100) = 1;
      }
      JUMPOUT(0x7DA0D);
    }
    v2 = sub_1171AB(v3, SHIDWORD(v3), v2, v0);
    if ( (_WORD)v2 )
    {
      v1 = byte_1B071C;
      for ( HIDWORD(v3) = 0; ; ++HIDWORD(v3) )
      {
        if ( SWORD2(v3) >= 10 )
          goto LABEL_15;
        v0 = 2 * SWORD2(v3);
        LODWORD(v3) = v0 + dword_19C038;
        if ( (_WORD)v2 == *(_WORD *)(v0 + dword_19C038 + 56) )
          break;
        if ( (_WORD)v2 == *(_WORD *)(v3 + 124) )
        {
          if ( WORD2(v3) == v17 )
          {
            v21 = 1;
            byte_1820B8 = 2;
            goto LABEL_15;
          }
          word_1844CA = 1;
          dword_1844C6 = 0;
          v17 = WORD2(v3);
          HIWORD(dword_1844CE) = *(_WORD *)(v3 + 56);
          v10 = v1;
          strcpy(v1, &byte_1996BE[37 * SWORD2(v3)]);
          v1 = v10;
          byte_1B3E18 = 1;
        }
      }
      if ( WORD2(v3) == v17 )
      {
        v20 = 1;
        v21 = 1;
      }
      v17 = WORD2(v3);
    }
LABEL_15:
    if ( (_WORD)v2 == *(_WORD *)(dword_19C038 + 562) )
    {
      if ( v17 <= -1 || v17 >= 10 )
      {
        if ( byte_199BF1 > -1 && byte_199BF1 < 10 )
        {
          v21 = 1;
          v17 = byte_199BF1;
        }
      }
      else
      {
        v21 = 1;
      }
    }
    if ( v21 && v17 > -1 && v17 < 10 )
      break;
LABEL_37:
    LODWORD(v3) = dword_19C038;
    if ( (_WORD)v2 == *(_WORD *)(dword_19C038 + 110)
      || (v2 & 0x8000u) != 0
      && (v1 = (char *)(int16_t)v2, v0 = *(int16_t *)(dword_19C038 + 56), v3 = (int16_t)v2, abs16(v2) >= v0)
      && (v0 = *(int16_t *)(dword_19C038 + 74), v3 = (int16_t)v2, LODWORD(v3) = abs16(v2), (int)v3 <= v0) )
    {
      word_199830 = 0;
      v19 = 1;
    }
    else
    {
      LODWORD(v3) = dword_19C038;
      if ( (_WORD)v2 == *(_WORD *)(dword_19C038 + 112) )
      {
        LODWORD(v3) = v14;
        v19 = 1;
        *v14 = 1;
      }
    }
    if ( !(_WORD)v19 )
    {
      sub_124D41();
      sub_7F206();
      LODWORD(v3) = sub_1077D(v3, SHIDWORD(v3), v2, (int16_t *)v1);
    }
  }
  v4 = 37 * v17;
  v21 = 0;
  byte_199BF1 = v17;
  if ( byte_1996BE[v4] && (v1 = &byte_1996BE[v4], HIDWORD(v5) = word_19C048, strcmp(&byte_1996BE[v4], word_19C048)) )
  {
    if ( !v20 )
    {
LABEL_36:
      sub_1160B(v17, SHIDWORD(v5), v2, v0);
      sub_12030();
      sub_7E752(dword_19268C);
      HIDWORD(v3) = dword_192688;
      sub_7E7FF(dword_19C038, dword_192688, v2, v0);
      v22 = 1;
      v19 = 1;
      *v14 = 1;
      goto LABEL_37;
    }
    v7 = byte_1B071C;
  }
  else
  {
    v6 = sub_C5560(word_19999C);
    if ( v6 == 1 )
    {
      v11 = sub_7A990(0xBCu);
      v5 = sprintf(
             v15,
             "%s, %s, %d %s",
             (char *)(3753 * word_19999C + dword_197F98 + 1),
             (char *)(3753 * word_19999C + dword_197F98 + 21),
             1,
             v11);
    }
    else
    {
      v12 = sub_7A990(0xBDu);
      v5 = sprintf(
             v15,
             "%s, %s, %d %s",
             (char *)(3753 * word_19999C + dword_197F98 + 1),
             (char *)(3753 * word_19999C + dword_197F98 + 21),
             v6,
             v12);
    }
    v0 = strlen(v15);
    if ( (unsigned int)v0 >= 0x25 )
      v15[36] = 0;
    v7 = v15;
    v1 = &byte_1996BE[37 * v17];
  }
  v13 = v1;
  strcpy(v1, v7);
  v1 = v13;
  goto LABEL_36;
}
// 7E50C: control flows out of bounds to 7DA0D
// 7E426: variable 'v14' is possibly undefined
// 7E4A2: variable 'v3' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 179598: using guessed type wchar_t aNsqoA[6];
// 1820B8: using guessed type char byte_1820B8;
// 1844C6: using guessed type int dword_1844C6;
// 1844CA: using guessed type int16_t word_1844CA;
// 1844CE: using guessed type int dword_1844CE;
// 192688: using guessed type int dword_192688;
// 19268C: using guessed type int dword_19268C;
// 197F98: using guessed type int dword_197F98;
// 199830: using guessed type int16_t word_199830;
// 19999C: using guessed type int16_t word_19999C;
// 199BE2: using guessed type char byte_199BE2;
// 199BF1: using guessed type char byte_199BF1;
// 199F09: using guessed type char byte_199F09;
// 19C038: using guessed type int dword_19C038;
// 19C044: using guessed type int dword_19C044;
// 19C048: using guessed type int16_t word_19C048[10];
// 1B3E18: using guessed type char byte_1B3E18;


//----- (0007E514) --------------------------------------------------------
int __usercall sub_7E514(int a1, int a2, int16_t *a3)
{
  int v3; // eax

  if ( word_199A08 == 10 )
  {
    sub_124D7A();
    sub_128C32(0, 0, 639, 479, 0);
    a2 = dword_19C088;
    a1 = 0;
    sub_12A478(0, 0, dword_19C088);
  }
  else
  {
    sub_124D41();
    sub_84E9D();
    sub_124DEC();
    sub_124C08();
    word_19994C = 0;
  }
  sub_124D41();
  v3 = sub_1192D1();
  return sub_1077D(v3, a1, a2, a3);
}
// 19994C: using guessed type int16_t word_19994C;
// 199A08: using guessed type int16_t word_199A08;
// 19C088: using guessed type int dword_19C088;


//----- (0007E59A) --------------------------------------------------------
int __usercall sub_7E59A(int a1, unsigned int a2, int16_t *a3)
{
  int v5; // edx
  int v7; // eax

  v5 = 0;
  if ( a2 )
  {
    if ( a2 <= 1u )
    {
      sub_124B65();
      byte_19C06A = 1;
      sub_77658(a1);
      v5 = v7;
    }
    else
    {
      if ( a2 != 3 )
        return 0;
      sub_124B65();
      byte_19C06A = 1;
      sub_77433(a1);
    }
  }
  else
  {
    sub_124B65();
    byte_19C06A = 1;
    sub_77423(a1);
  }
  sub_11C2F0();
  sub_7E514(v5, a1, a3);
  return v5;
}
// 7E5F9: variable 'v7' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// 19C06A: using guessed type char byte_19C06A;


//----- (0007E609) --------------------------------------------------------
void __fastcall sub_7E609(int a1, _BYTE *a2)
{
  int v4; // eax
  int16_t v5; // [esp+0h] [ebp-18h] BYREF
  int16_t v6; // [esp+4h] [ebp-14h] BYREF
  int16_t v7; // [esp+8h] [ebp-10h] BYREF
  int16_t v8; // [esp+Ch] [ebp-Ch] BYREF
  int16_t v9; // [esp+10h] [ebp-8h] BYREF
  int16_t v10; // [esp+14h] [ebp-4h] BYREF

  v4 = fopen(a1);
  if ( v4 )
  {
    fclose(v4);
    sub_8F72D(a1, &v9, &v10, &v5, &v8, &v7, &v6);
    if ( v9 || v10 || v5 || v8 || v6 )
    {
      sprintf(a2, "%3s %2d, %-4d  %2d:%2d", &byte_19BFE8[6 * v9], v10, v5, v8, v7);
      if ( a2[14] == 32 )
        a2[14] = 48;
      if ( a2[17] == 32 )
        a2[17] = 48;
    }
    else
    {
      *a2 = 0;
    }
  }
  JUMPOUT(0x7D88C);
}
// 7E670: control flows out of bounds to 7D88C
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 12697A: using guessed type int __fastcall fclose(_DWORD);


//----- (0007E6C1) --------------------------------------------------------
char *__fastcall sub_7E6C1( unsigned int a1, char *a2, char *a3)
{
  int16_t v4; // bx
  int16_t v5; // dx
  char *result; // eax
  uint16_t v7; // [esp+0h] [ebp-8h]

  if ( word_199A08 == 10 )
  {
    v7 = a1;
    v4 = 252;
    v5 = 251;
    qmemcpy(a2, sub_8E5C5(a1, 254, 255), 8u);
  }
  else
  {
    byte_199F34 = 89;
    v7 = a1;
    v4 = 126;
    v5 = 89;
    qmemcpy(a2, sub_8E5C5(a1, 86, 91), 8u);
    byte_199F34 = 91;
  }
  result = sub_8E5C5(v7, v5, v4);
  qmemcpy(a3, result, 8u);
  return result;
}
// 199A08: using guessed type int16_t word_199A08;
// 199F34: using guessed type char byte_199F34;


//----- (0007E752) --------------------------------------------------------
void __fastcall sub_7E752(int a1)
{
  int v1; // ecx
  char *v2; // edi
  char *v3; // edi
  int v4; // edx
  _BYTE *v5; // esi
  char v6; // al
  _BYTE v8[27]; // [esp+4h] [ebp-38h] BYREF
  char v9; // [esp+1Fh] [ebp-1Dh] BYREF
  char v10[16]; // [esp+20h] [ebp-1Ch] BYREF
  char v11[12]; // [esp+30h] [ebp-Ch] BYREF

  v1 = 0;
  while ( 1 )
  {
    itoa((int16_t)v1 + 1, v11, 10, v1);
    strcpy(v10, "SAVE");
    v2 = &v9;
    do
      ++v2;
    while ( *v2 );
    strcpy(v2, v11);
    v3 = &v9;
    do
      ++v3;
    while ( *v3 );
    strcpy(v3, aGam_0);
    memset(v8, 0, 25);
    if ( !(uint16_t)access(v10, 0) )
      sub_7E609((int)v10, v8);
    v4 = 0;
    do
    {
      v5 = (_BYTE *)(a1 + (int16_t)v4 + 25 * (int16_t)v1);
      v6 = v8[(int16_t)v4++];
      *v5 = v6;
    }
    while ( (int16_t)v4 < 25 );
    if ( (int16_t)++v1 >= 10 )
      JUMPOUT(0x7DA0C);
  }
}
// 7E7FA: control flows out of bounds to 7DA0C
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 129E6B: using guessed type int __fastcall access(_DWORD, _DWORD);


//----- (0007E7FF) --------------------------------------------------------
void __fastcall sub_7E7FF(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // edx
  unsigned int v5; // ebx
  int16_t v6; // di
  int16_t v7; // ax
  char v8; // cl
  char v11[28]; // [esp+8h] [ebp-34h] BYREF
  char v12[8]; // [esp+24h] [ebp-18h] BYREF
  int v13; // [esp+2Ch] [ebp-10h]
  int v14; // [esp+30h] [ebp-Ch]
  int v15; // [esp+34h] [ebp-8h]
  int v16; // [esp+38h] [ebp-4h]

  v14 = 0;
  v16 = 0;
  while ( 1 )
  {
    v15 = v16;
    memset(v11, 0, 25);
    v4 = (_DWORD *)(a1 + 4 * (int16_t)v14);
    if ( (int)*v4 <= 0 )
    {
      if ( (int)*v4 < 0 )
        strcpy(v11, "* INVALID *");
    }
    else
    {
      strcpy(v11, sub_7A990(0xCAu));
      itoa(*v4, v12, 10, a4);
      v5 = strlen(v11);
      v6 = strlen(v12);
      v7 = 0;
      v8 = 0;
      do
      {
        v13 = v6 - 1;
        if ( v7 == v13 )
        {
          v11[(int16_t)v5] = 46;
          v11[(int16_t)(v5 + 1)] = v12[v7];
          v5 += 2;
        }
        else
        {
          v11[(int16_t)v5++] = v12[v7];
        }
        if ( ++v7 == v6 )
          v8 = 1;
      }
      while ( !v8 );
      v11[(int16_t)v5] = 0;
    }
    v16 += 25;
    ++v14;
    qmemcpy((void *)(a2 + (int16_t)v15), v11, 0x19u);
    a4 = 0;
    if ( (int16_t)v14 >= 10 )
      JUMPOUT(0x7D88C);
  }
}
// 7E90E: control flows out of bounds to 7D88C
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (0007E913) --------------------------------------------------------
char sub_7E913()
{
  char result; // al

  strcpy(byte_19BFE8, sub_7A990(0xBEu));
  strcpy(byte_19BFEE, sub_7A990(0xBFu));
  strcpy(byte_19BFF4, sub_7A990(0xC0u));
  strcpy(byte_19BFFA, sub_7A990(0xC1u));
  strcpy(byte_19C000, sub_7A990(0xC2u));
  strcpy(byte_19C006, sub_7A990(0xC3u));
  strcpy(byte_19C00C, sub_7A990(0xC4u));
  strcpy(byte_19C012, sub_7A990(0xC5u));
  strcpy(byte_19C018, sub_7A990(0xC6u));
  strcpy(byte_19C01E, sub_7A990(0xC7u));
  strcpy(byte_19C024, sub_7A990(0xC8u));
  strcpy(byte_19C02A, sub_7A990(0xC9u));
  return result;
}


//----- (0007EA5C) --------------------------------------------------------
_DWORD *__usercall sub_7EA5C(int a1, int a2, int a3, int16_t *a4)
{
  _DWORD *v4; // eax
  int v5; // ebx
  _DWORD *v6; // eax
  int v7; // ebx
  _DWORD *v8; // eax
  int v9; // ebx
  _DWORD *v10; // eax
  int v11; // ebx
  _DWORD *v12; // eax
  int v13; // ebx
  _DWORD *v14; // edx
  int v15; // eax
  _DWORD *v16; // eax
  int v17; // ebx
  _DWORD *v18; // eax
  int v19; // ebx
  _DWORD *v20; // eax
  int v21; // ebx
  _DWORD *v22; // eax
  int v23; // ebx
  _DWORD *v24; // edx
  int v25; // eax
  _DWORD *v26; // eax
  int v27; // ebx
  _DWORD *v28; // eax
  int v29; // ebx
  _DWORD *v30; // eax
  int v31; // ebx
  _DWORD *v32; // eax
  int v33; // ebx
  _DWORD *v34; // edx
  int v35; // eax
  _DWORD *v36; // eax
  int v37; // ebx
  _DWORD *v38; // eax
  int v39; // ebx
  _DWORD *v40; // eax
  int v41; // ebx
  _DWORD *v42; // edx
  int v43; // eax
  int v44; // eax
  _DWORD *result; // eax

  sub_FE8BE(a1, a2, a3, a4);
  v4 = sub_126B42((int)off_1820B4, 0, dword_192ED4);
  v5 = dword_192ED4;
  *(_DWORD *)dword_19C044 = v4;
  v6 = sub_126B42((int)off_1820B4, 1, v5);
  v7 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 4) = v6;
  v8 = sub_126B42((int)off_1820B4, 2, v7);
  v9 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 8) = v8;
  v10 = sub_126B42((int)off_1820B4, 3, v9);
  v11 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 12) = v10;
  v12 = sub_126B42((int)off_1820B4, 4, v11);
  v13 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 16) = v12;
  v14 = sub_126B42((int)off_1820B4, 5, v13);
  v15 = dword_19C044;
  *(_DWORD *)(dword_19C044 + 20) = v14;
  sub_FE8BE(v15, (int)v14, v13, a4);
  v16 = sub_126B42((int)off_1820B4, 6, dword_192ED4);
  v17 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 24) = v16;
  v18 = sub_126B42((int)off_1820B4, 7, v17);
  v19 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 28) = v18;
  v20 = sub_126B42((int)off_1820B4, 29, v19);
  v21 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 32) = v20;
  v22 = sub_126B42((int)off_1820B4, 9, v21);
  v23 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 36) = v22;
  v24 = sub_126B42((int)off_1820B4, 10, v23);
  v25 = dword_19C044;
  *(_DWORD *)(dword_19C044 + 40) = v24;
  sub_FE8BE(v25, (int)v24, v23, a4);
  *(_DWORD *)(dword_19C044 + 44) = sub_126B42((int)off_1820B4, 11, dword_192ED4);
  v26 = sub_126B42((int)off_1820B4, 12, dword_192ED4);
  v27 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 48) = v26;
  v28 = sub_126B42((int)off_1820B4, 13, v27);
  v29 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 52) = v28;
  v30 = sub_126B42((int)off_1820B4, 14, v29);
  v31 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 56) = v30;
  v32 = sub_126B42((int)off_1820B4, 15, v31);
  v33 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 60) = v32;
  v34 = sub_126B42((int)off_1820B4, 16, v33);
  v35 = dword_19C044;
  *(_DWORD *)(dword_19C044 + 64) = v34;
  sub_FE8BE(v35, (int)v34, v33, a4);
  *(_DWORD *)(dword_19C044 + 68) = sub_126B42((int)off_1820B4, 17, dword_192ED4);
  v36 = sub_126B42((int)off_1820B4, 18, dword_192ED4);
  v37 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 72) = v36;
  v38 = sub_126B42((int)off_1820B4, 19, v37);
  v39 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 76) = v38;
  v40 = sub_126B42((int)off_1820B4, 27, v39);
  v41 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 92) = v40;
  v42 = sub_126B42((int)off_1820B4, 28, v41);
  v43 = dword_19C044;
  *(_DWORD *)(dword_19C044 + 96) = v42;
  sub_FE8BE(v43, (int)v42, v41, a4);
  v44 = sub_12DAA4(**(_WORD **)dword_19C044 + 1, *(_WORD *)(*(_DWORD *)dword_19C044 + 2) + 1);
  result = sub_110D3C(dword_192ED4, v44);
  dword_19C150 = (int)result;
  return result;
}
// 1820B4: using guessed type char *off_1820B4;
// 192ED4: using guessed type int dword_192ED4;
// 19C044: using guessed type int dword_19C044;
// 19C150: using guessed type int dword_19C150;


//----- (0007ED66) --------------------------------------------------------
int __usercall sub_7ED66(int a1, int a2)
{
  int16_t v2; // bx
  int16_t v3; // dx
  int result; // eax

  byte_19C062 = 1;
  v2 = word_19983C;
  v3 = word_19983A;
  dword_19C034 = a1;
  word_19983C = 0;
  word_19983A = 0;
  sub_7F701(v3, a2);
  byte_19C062 = 0;
  word_19983C = v2;
  word_19983A = v3;
  return result;
}
// 19983A: using guessed type int16_t word_19983A;
// 19983C: using guessed type int16_t word_19983C;
// 19C034: using guessed type int dword_19C034;
// 19C062: using guessed type char byte_19C062;


//----- (0007EDC4) --------------------------------------------------------
_DWORD *__fastcall sub_7EDC4(int16_t *a1)
{
  return sub_7EDF2(a1, 0, 1, 0);
}


//----- (0007EDD9) --------------------------------------------------------
_DWORD *__fastcall sub_7EDD9(int16_t *a1, unsigned int a2)
{
  return sub_7EDF2(a1, a1[1], -1, a2);
}


//----- (0007EDF2) --------------------------------------------------------
_DWORD *__fastcall sub_7EDF2(int16_t *a1, int a2, int a3, unsigned int a4)
{
  int v4; // esi
  int16_t *v5; // edi
  int v6; // eax
  _DWORD *v7; // ecx
  int16_t v8; // bx
  int16_t v9; // si
  int v10; // ebx
  int16_t v11; // dx
  int v12; // edx
  int v13; // eax
  int16_t v16; // [esp+18h] [ebp-14h]
  int16_t *v18; // [esp+20h] [ebp-Ch]
  int16_t v19; // [esp+28h] [ebp-4h]

  v4 = (int)a1;
  v5 = (int16_t *)a2;
  v19 = *a1;
  LOWORD(a1) = a1[1];
  v18 = a1;
  sub_1112EC(dword_192ED4, a2);
  v6 = sub_12DAA4(v19, (int16_t)v18);
  v7 = sub_110D3C(dword_192ED4, v6 + 100);
  sub_12D8F5(v19, (int16_t)v18, (int)v7);
  HIWORD(a2) = HIWORD(v4);
  v16 = 1;
  sub_12F578((int)v7, v4);
  if ( a4 )
  {
    if ( a4 <= 2u )
    {
      byte_19C062 = 1;
      dword_19C034 = (int)v7;
      sub_7F206();
    }
    else
    {
      if ( a4 != 3 )
        goto LABEL_9;
      byte_19C062 = 1;
      dword_19C034 = (int)v7;
      sub_7FA28();
    }
    byte_19C062 = 0;
  }
  else
  {
    byte_19C062 = 1;
    LOWORD(a2) = word_19983C;
    v8 = word_19983A;
    dword_19C034 = (int)v7;
    word_19983C = 0;
    word_19983A = 0;
    sub_7F701(a2, v4);
    byte_19C062 = 0;
    word_19983C = a2;
    word_19983A = v8;
  }
LABEL_9:
  sub_8440E();
  sub_124DEC();
  sub_124C08();
  do
  {
    v5 = (int16_t *)((char *)v5 + a3 * (v16 * (int16_t)v18 / 100));
    if ( (int16_t)v5 > (int16_t)v18 && (int16_t)a3 > 0 )
      v5 = v18;
    sub_124D41();
    v9 = (_WORD)v5 + 26;
    sub_128AB6(144, 25, v19 + 144, (int16_t)((_WORD)v5 + 26));
    sub_12B634();
    if ( v16 == 14 && (int16_t)a3 > 0 )
    {
      v10 = (int)v7;
      v11 = 25;
    }
    else
    {
      v10 = (int)v7;
      v11 = (_WORD)v5 + 21 - (_WORD)v18;
    }
    sub_12A478(144, v11, v10);
    sub_12B65C();
    if ( (int16_t)a3 <= 0 )
    {
      v13 = 25;
      v12 = v9 - 25;
      LOBYTE(v13) = v12 <= 25;
    }
    else
    {
      v12 = v9 - 25;
      v13 = (int16_t)v18;
      LOBYTE(v13) = v12 > (int16_t)v18;
    }
    LOBYTE(v12) = v13;
    sub_1077D(v13, v12, v10, v5);
    ++v16;
  }
  while ( !(_BYTE)v12 );
  sub_124DEC();
  return sub_1113CC(dword_192ED4, v12);
}
// 7EDF2: could not find valid save-restore pair for ebx
// 192ED4: using guessed type int dword_192ED4;
// 19983A: using guessed type int16_t word_19983A;
// 19983C: using guessed type int16_t word_19983C;
// 19C034: using guessed type int dword_19C034;
// 19C062: using guessed type char byte_19C062;


//----- (0007EFEF) --------------------------------------------------------
_WORD *sub_7EFEF()
{
  _WORD *v0; // ebx
  _WORD *result; // eax
  int16_t v2; // bx

  v0 = (_WORD *)dword_19C038;
  *(_WORD *)(dword_19C038 + 116) = 155 * (100 * (uint8_t)byte_199BF0 / 100) / 100;
  v0[59] = 155 * (100 * (uint8_t)byte_199BEE / 100) / 100;
  v0[60] = (uint8_t)byte_199BEF;
  v0[61] = (uint8_t)byte_199BED;
  v0[72] = (uint8_t)byte_199BDC;
  if ( byte_199F3A )
    v0[73] = 0;
  else
    v0[73] = (uint8_t)byte_199BDD;
  result = (_WORD *)dword_19C038;
  *(_WORD *)(dword_19C038 + 148) = (uint8_t)byte_199BDF;
  result[75] = (uint8_t)byte_199BE0;
  result[76] = (uint8_t)byte_199BE1;
  result[77] = (uint8_t)byte_199BE2;
  result[78] = (uint8_t)byte_199BE3;
  result[79] = (uint8_t)byte_199BE4;
  result[80] = (uint8_t)byte_199BE5;
  result[81] = (uint8_t)byte_199BE6;
  result[82] = (uint8_t)byte_199BE7;
  result[83] = (uint8_t)byte_199BE8;
  result[84] = (uint8_t)byte_199BE9;
  v2 = (uint8_t)byte_199CAE;
  result[303] = (uint8_t)byte_199CAE;
  if ( v2 >= 5 )
    result[303] = 0;
  return result;
}
// 199BDC: using guessed type char byte_199BDC;
// 199BDD: using guessed type char byte_199BDD;
// 199BDF: using guessed type char byte_199BDF;
// 199BE0: using guessed type char byte_199BE0;
// 199BE1: using guessed type char byte_199BE1;
// 199BE2: using guessed type char byte_199BE2;
// 199BE3: using guessed type char byte_199BE3;
// 199BE4: using guessed type char byte_199BE4;
// 199BE5: using guessed type char byte_199BE5;
// 199BE6: using guessed type char byte_199BE6;
// 199BE7: using guessed type char byte_199BE7;
// 199BE8: using guessed type char byte_199BE8;
// 199BE9: using guessed type char byte_199BE9;
// 199BED: using guessed type char byte_199BED;
// 199BEE: using guessed type char byte_199BEE;
// 199BEF: using guessed type char byte_199BEF;
// 199BF0: using guessed type char byte_199BF0;
// 199CAE: using guessed type char byte_199CAE;
// 199F3A: using guessed type char byte_199F3A;
// 19C038: using guessed type int dword_19C038;


//----- (0007F14C) --------------------------------------------------------
char sub_7F14C()
{
  char result; // al

  byte_199BDC = *(_BYTE *)(dword_19C038 + 144);
  byte_199BDD = *(_BYTE *)(dword_19C038 + 146);
  byte_199BDF = *(_BYTE *)(dword_19C038 + 148);
  byte_199BE0 = *(_BYTE *)(dword_19C038 + 150);
  byte_199BE1 = *(_BYTE *)(dword_19C038 + 152);
  byte_199BE2 = *(_BYTE *)(dword_19C038 + 154);
  byte_199BE3 = *(_BYTE *)(dword_19C038 + 156);
  byte_199BE4 = *(_BYTE *)(dword_19C038 + 158);
  byte_199BE5 = *(_BYTE *)(dword_19C038 + 160);
  byte_199BE6 = *(_BYTE *)(dword_19C038 + 162);
  byte_199BE7 = *(_BYTE *)(dword_19C038 + 164);
  byte_199BE8 = *(_BYTE *)(dword_19C038 + 166);
  result = *(_BYTE *)(dword_19C038 + 606);
  byte_199BE9 = *(_BYTE *)(dword_19C038 + 168);
  byte_199CAE = result;
  if ( (uint8_t)result >= 5u )
    byte_199CAE = 0;
  return result;
}
// 199BDC: using guessed type char byte_199BDC;
// 199BDD: using guessed type char byte_199BDD;
// 199BDF: using guessed type char byte_199BDF;
// 199BE0: using guessed type char byte_199BE0;
// 199BE1: using guessed type char byte_199BE1;
// 199BE2: using guessed type char byte_199BE2;
// 199BE3: using guessed type char byte_199BE3;
// 199BE4: using guessed type char byte_199BE4;
// 199BE5: using guessed type char byte_199BE5;
// 199BE6: using guessed type char byte_199BE6;
// 199BE7: using guessed type char byte_199BE7;
// 199BE8: using guessed type char byte_199BE8;
// 199BE9: using guessed type char byte_199BE9;
// 199CAE: using guessed type char byte_199CAE;
// 19C038: using guessed type int dword_19C038;


//----- (0007F206) --------------------------------------------------------
void sub_7F206()
{
  int v0; // ecx
  int v1; // ebx
  int16_t v2; // dx
  int16_t v3; // ax
  int v4; // eax
  int v5; // eax
  int v6; // edx
  uint8_t v7; // cl
  int v8; // ebx
  int16_t *v9; // esi
  int16_t *v10; // ecx
  int16_t *v11; // ebx
  int v12; // ebx
  int v13; // ecx
  int v14; // edx
  int16_t v15; // dx
  char *v16; // ebx
  int v17; // ecx
  int16_t v18; // ax
  int v19; // ecx
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // edx
  int16_t v24; // ax
  char *v25; // ebx
  int v26; // edx
  int16_t v27; // bx
  int16_t v28; // dx
  int16_t v29; // ax
  _BYTE v30[28]; // [esp+0h] [ebp-3Ch] BYREF
  int v31; // [esp+1Ch] [ebp-20h]
  int v32; // [esp+20h] [ebp-1Ch]
  int v33; // [esp+24h] [ebp-18h]
  int v34; // [esp+28h] [ebp-14h]
  int v35; // [esp+2Ch] [ebp-10h]
  int v36; // [esp+30h] [ebp-Ch]
  int v37; // [esp+34h] [ebp-8h]
  _BOOL1 v38; // [esp+38h] [ebp-4h]

  v37 = 2;
  if ( word_199830 == 2 )
    v0 = *(_DWORD *)(dword_19C044 + 44);
  else
    v0 = *(_DWORD *)(dword_19C044 + 56);
  v1 = v0;
  if ( word_199A08 == 10 )
  {
    sub_12A478(0, 0, dword_19C088);
    v2 = word_19983A;
    v3 = word_19983C;
    v1 = v0;
  }
  else
  {
    if ( byte_19C062 || !word_19994C )
    {
      if ( !byte_19C062 )
        sub_12A478(word_19983C, word_19983A, v0);
      goto LABEL_12;
    }
    sub_124D41();
    sub_84E9D();
    sub_124DEC();
    sub_124C08();
    v2 = word_19983A;
    v3 = word_19983C;
    word_19994C = 0;
  }
  sub_12A478(v3, v2, v1);
  word_19994C = 0;
LABEL_12:
  v36 = 0;
  v33 = 0;
  v31 = 0;
  while ( 1 )
  {
    v32 = v33;
    qmemcpy(v30, (void *)(dword_192688 + (int16_t)v33), 0x19u);
    HIWORD(v4) = HIWORD(dword_19C038);
    v38 = *(_BYTE *)((int16_t)v36 + dword_19C038 + 170) == 2;
    if ( byte_19C062 )
    {
      v5 = 228;
      LOWORD(v6) = v31 + 36;
    }
    else
    {
      LOWORD(v4) = word_19983C;
      v5 = v4 + 228;
      LOWORD(v6) = v31 + word_19983A + 24 + 12;
    }
    v7 = *(_BYTE *)((int16_t)v36 + dword_19C038 + 550);
    if ( !v7 )
    {
      if ( byte_19C062 )
      {
        v8 = dword_19C034;
        v6 = (int16_t)v6;
        v5 = (int16_t)v5;
        v9 = *(int16_t **)(dword_19C044 + 64);
LABEL_22:
        v10 = (int16_t *)v8;
        v11 = v9;
LABEL_23:
        v5 = sub_12F7E6(v5, v6, v11, v10);
        goto LABEL_32;
      }
      v12 = *(_DWORD *)(dword_19C044 + 64);
      goto LABEL_31;
    }
    if ( v7 <= 1u )
      break;
    if ( v7 <= 3u )
    {
      if ( byte_19C062 )
      {
        v6 = (int16_t)v6;
        v5 = (int16_t)v5;
        v11 = *(int16_t **)(dword_19C044 + 72);
        v10 = (int16_t *)dword_19C034;
        goto LABEL_23;
      }
      v12 = *(_DWORD *)(dword_19C044 + 72);
LABEL_31:
      v5 = sub_12A478(v5, v6, v12);
    }
LABEL_32:
    if ( byte_19C062 )
    {
      v34 = v31 + 24;
      v13 = (int16_t)v37;
      sub_7E6C1(v37, (char *)(dword_19C038 + 564), (char *)(dword_19C038 + 572));
      v35 = 32;
      if ( byte_199BF1 == (_WORD)v36 )
        v14 = dword_19C038 + 572;
      else
        v14 = dword_19C038 + 564;
      sub_120BB5(v13, v14);
      if ( word_199830 == 3 )
      {
        if ( v38 )
        {
          v15 = v34;
          v16 = aInvalid;
          v17 = dword_19C034;
          v18 = v35 + 4;
LABEL_39:
          sub_122A6E(v18, v15, (int)v16, v17);
          goto LABEL_54;
        }
        v19 = 37 * (int16_t)v36;
        if ( byte_1996BE[v19] )
        {
          v15 = v34;
          v16 = &byte_1996BE[v19];
          v17 = dword_19C034;
          v18 = v35 + 4;
          goto LABEL_39;
        }
      }
      else
      {
        v20 = 37 * (int16_t)v36;
        if ( byte_1996BE[v20] )
        {
          v15 = v34;
          if ( v38 )
          {
            v18 = v35;
            v16 = aInvalid;
            v17 = dword_19C034;
          }
          else
          {
            v16 = &byte_1996BE[v20];
            v17 = dword_19C034;
            v18 = v35;
          }
          goto LABEL_39;
        }
      }
    }
    else
    {
      LOWORD(v5) = word_19983C;
      v21 = v5 + 32;
      v35 = v21;
      LOWORD(v21) = word_19983A;
      v34 = v21 + 24 + v31;
      if ( word_199830 == 2 )
      {
        v22 = (int16_t)v37;
        sub_7E6C1(v37, (char *)(dword_19C038 + 564), (char *)(dword_19C038 + 572));
        if ( byte_199BF1 == (_WORD)v36 )
          v23 = dword_19C038 + 572;
        else
          v23 = dword_19C038 + 564;
        sub_120BB5(v22, v23);
        if ( v38 )
        {
          v24 = v35;
          v25 = aInvalid;
        }
        else
        {
          v25 = &byte_1996BE[37 * (int16_t)v36];
          v24 = v35;
        }
        sub_1212B3(v24, v34, (int)v25);
      }
    }
LABEL_54:
    qmemcpy(v30, (void *)((int16_t)v32 + dword_192688), 0x19u);
    sub_7E6C1(1u, (char *)(dword_19C038 + 564), (char *)(dword_19C038 + 572));
    if ( byte_199BF1 == (_WORD)v36 )
      v26 = dword_19C038 + 572;
    else
      v26 = dword_19C038 + 564;
    sub_120BB5(1, v26);
    if ( word_199830 == 3 )
      v35 += 2;
    v27 = v34 + 14;
    if ( byte_19C062 )
    {
      sub_122A6E(v35, v27, (int)v30, dword_19C034);
    }
    else if ( strcmp(&unk_19C048, &byte_1996BE[37 * (int16_t)v36]) )
    {
      sub_1212B3(v35, v27, (int)v30);
    }
    qmemcpy(v30, (void *)(dword_19268C + (int16_t)v32), 0x19u);
    v28 = v34 + 14;
    v29 = v35 + 100;
    if ( byte_19C062 )
      sub_122A6E(v29, v28, (int)v30, dword_19C034);
    else
      sub_1212B3(v29, v28, (int)v30);
    v33 += 25;
    ++v36;
    v31 += 31;
    if ( (int16_t)v36 >= 10 )
      JUMPOUT(0x7DA0C);
  }
  if ( byte_19C062 )
  {
    v8 = dword_19C034;
    v6 = (int16_t)v6;
    v5 = (int16_t)v5;
    v9 = *(int16_t **)(dword_19C044 + 68);
    goto LABEL_22;
  }
  v12 = *(_DWORD *)(dword_19C044 + 68);
  goto LABEL_31;
}
// 7F6FC: control flows out of bounds to 7DA0C
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 192688: using guessed type int dword_192688;
// 19268C: using guessed type int dword_19268C;
// 199830: using guessed type int16_t word_199830;
// 19983A: using guessed type int16_t word_19983A;
// 19983C: using guessed type int16_t word_19983C;
// 19994C: using guessed type int16_t word_19994C;
// 199A08: using guessed type int16_t word_199A08;
// 199BF1: using guessed type char byte_199BF1;
// 19C034: using guessed type int dword_19C034;
// 19C038: using guessed type int dword_19C038;
// 19C044: using guessed type int dword_19C044;
// 19C062: using guessed type char byte_19C062;
// 19C088: using guessed type int dword_19C088;


//----- (0007F701) --------------------------------------------------------
void __usercall sub_7F701(int a1, int a2)
{
  int v2; // eax
  int v3; // esi
  int v4; // edi
  int v5; // edx
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int16_t v9; // di
  int16_t v10; // si
  int16_t v11; // di
  _BYTE v12[8]; // [esp+0h] [ebp-28h]
  int v13; // [esp+8h] [ebp-20h]
  int v14; // [esp+Ch] [ebp-1Ch]
  int v15; // [esp+10h] [ebp-18h]
  int v16; // [esp+14h] [ebp-14h]
  int v17; // [esp+18h] [ebp-10h]
  int v18; // [esp+1Ch] [ebp-Ch]
  int v19; // [esp+20h] [ebp-8h]
  int v20; // [esp+24h] [ebp-4h]

  LOWORD(v2) = sub_113F8C();
  LOWORD(a2) = word_19983C;
  v15 = v2;
  HIWORD(v2) = HIWORD(dword_19C038);
  v3 = a2 + 62;
  v4 = 1;
  v18 = v3;
  LOWORD(a1) = *(_WORD *)(dword_19C038 + 116);
  LOWORD(v2) = *(_WORD *)(dword_19C038 + 118);
  v5 = v3 + a1;
  v12[0] = -115;
  v13 = v5;
  v6 = v3 + v2;
  LOWORD(v5) = word_19983A;
  v14 = v6;
  v5 += 194;
  LOWORD(v6) = word_19983A;
  v19 = v5;
  v6 += 216;
  LOWORD(v5) = word_19983A;
  v20 = v6;
  LOWORD(v6) = word_19983A;
  v16 = v5 + 207;
  v17 = v6 + 229;
  do
  {
    v7 = (int16_t)v4;
    v8 = (int16_t)v4++ / 2 + 153;
    v12[v7] = v8;
  }
  while ( (int16_t)v4 < 8 );
  if ( !byte_19C062 )
  {
    sub_84E9D();
    sub_12A478(word_19983C, word_19983A, *(_DWORD *)dword_19C044);
    if ( !byte_19C064 )
    {
      sub_12A478(word_19983C + 147, word_19983A + 43, *(_DWORD *)(dword_19C044 + 92));
      sub_12A478(word_19983C + 40, word_19983A + 88, *(_DWORD *)(dword_19C044 + 96));
      byte_19C064 = 0;
    }
    word_19994C = 0;
  }
  if ( byte_199F3A && byte_19C062 )
  {
    sub_12D8F5(**(_WORD **)(dword_19C044 + 92), *(_WORD *)(*(_DWORD *)(dword_19C044 + 92) + 2), dword_19C150);
    sub_12F7E6(0, 0, *(int16_t **)(dword_19C044 + 92), (int16_t *)dword_19C150);
    sub_12F7E6(147, 43, (int16_t *)dword_19C150, (int16_t *)dword_19C034);
    sub_12D8F5(**(_WORD **)(dword_19C044 + 96), *(_WORD *)(*(_DWORD *)(dword_19C044 + 96) + 2), dword_19C150);
    sub_12F7E6(0, 0, *(int16_t **)(dword_19C044 + 96), (int16_t *)dword_19C150);
    sub_12F7E6(40, 88, (int16_t *)dword_19C150, (int16_t *)dword_19C034);
  }
  if ( byte_19C062 )
  {
    sub_12D8F5(v13 - v3 + 1, v16 - v19 + 1, dword_19C150);
    sub_12F7E6(0, 0, *(int16_t **)(dword_19C044 + 28), (int16_t *)dword_19C150);
    sub_12F7E6((int16_t)v3, (int16_t)v19, (int16_t *)dword_19C150, (int16_t *)dword_19C034);
  }
  else
  {
    v9 = v19;
    sub_128AB6(v3, v19, v13, (int16_t)v16);
    sub_12B634();
    sub_12A478(v3, v9, *(_DWORD *)(dword_19C044 + 28));
    sub_128BE7();
    sub_12B65C();
  }
  if ( byte_19C062 )
  {
    sub_12D8F5(v14 - v18 + 1, v17 - v20 + 1, dword_19C150);
    sub_12F7E6(0, 0, *(int16_t **)(dword_19C044 + 28), (int16_t *)dword_19C150);
    sub_12F7E6((int16_t)v18, (int16_t)v20, (int16_t *)dword_19C150, (int16_t *)dword_19C034);
  }
  else
  {
    v10 = v20;
    v11 = v18;
    sub_128AB6(v18, v20, v14, (int16_t)v17);
    sub_12B634();
    sub_12A478(v11, v10, *(_DWORD *)(dword_19C044 + 28));
    sub_128BE7();
    sub_12B65C();
  }
  if ( (_WORD)v15 == word_19C05C )
  {
    sub_80892();
  }
  else if ( (_WORD)v15 == word_19C060 )
  {
    sub_80918(0);
  }
  JUMPOUT(0x7DA0C);
}
// 7FA0A: control flows out of bounds to 7DA0C
// 7F716: variable 'v2' is possibly undefined
// 19983A: using guessed type int16_t word_19983A;
// 19983C: using guessed type int16_t word_19983C;
// 19994C: using guessed type int16_t word_19994C;
// 199F3A: using guessed type char byte_199F3A;
// 19C034: using guessed type int dword_19C034;
// 19C038: using guessed type int dword_19C038;
// 19C044: using guessed type int dword_19C044;
// 19C05C: using guessed type int16_t word_19C05C;
// 19C060: using guessed type int16_t word_19C060;
// 19C062: using guessed type char byte_19C062;
// 19C064: using guessed type char byte_19C064;
// 19C150: using guessed type int dword_19C150;


//----- (0007FA28) --------------------------------------------------------
void sub_7FA28()
{
  int v0; // edx
  int16_t v1; // si
  int v2; // edi
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int16_t v6; // bx
  int v7; // ecx
  int16_t v8; // bx
  int16_t v9; // dx
  int v10; // ecx
  int16_t v11; // di
  char *v12; // eax
  int16_t v13; // si
  int v14; // edx
  int v15; // ecx
  char *v16; // eax
  int v17; // edx
  int v18; // ecx
  char *v19; // eax
  int v20; // ecx
  char *v21; // eax
  int v22; // edx
  int v23; // ecx
  char *v24; // eax
  int v25; // edx
  int v26; // ecx
  char *v27; // eax
  int v28; // edx
  int v29; // ecx
  char *v30; // eax
  int v31; // edx
  int v32; // ecx
  char *v33; // eax
  int v34; // ecx
  char *v35; // eax
  int v36; // ecx
  char *v37; // eax
  int v38; // ecx
  char *v39; // eax
  int v40; // ecx
  char *v41; // eax
  int v42; // ecx
  char *v43; // eax
  int v44; // edi
  int16_t v45; // si
  int v46; // edx
  int v47; // edx
  int16_t v48; // cx
  char *v49; // eax
  int16_t v50; // si
  int16_t v51; // di
  char *v52; // eax
  int16_t v53; // di
  char *v54; // eax
  int16_t v55; // dx
  char *v56; // eax
  int16_t v57; // di
  char *v58; // eax
  int16_t v59; // di
  char *v60; // eax
  int16_t v61; // di
  char *v62; // eax
  int16_t v63; // di
  char *v64; // eax
  int16_t v65; // di
  char *v66; // eax
  int16_t v67; // dx
  char *v68; // eax
  int16_t v69; // dx
  char *v70; // eax
  int16_t v71; // dx
  char *v72; // eax
  int16_t v73; // dx
  char *v74; // eax
  _BYTE v75[8]; // [esp+0h] [ebp+2h] BYREF
  int v76; // [esp+8h] [ebp+Ah]
  int v77; // [esp+Ch] [ebp+Eh]
  int v78; // [esp+10h] [ebp+12h]
  int v79; // [esp+14h] [ebp+16h]
  int v80; // [esp+18h] [ebp+1Ah]
  int v81; // [esp+1Ch] [ebp+1Eh]
  int v82; // [esp+20h] [ebp+22h]
  int v83; // [esp+24h] [ebp+26h]
  int v84; // [esp+28h] [ebp+2Ah]
  int v85; // [esp+2Ch] [ebp+2Eh]
  int v86; // [esp+30h] [ebp+32h]
  int v87; // [esp+34h] [ebp+36h]
  int v88; // [esp+38h] [ebp+3Ah]
  int v89; // [esp+3Ch] [ebp+3Eh]
  int v90; // [esp+40h] [ebp+42h]
  int v91; // [esp+44h] [ebp+46h]
  int v92; // [esp+48h] [ebp+4Ah]
  int v93; // [esp+4Ch] [ebp+4Eh]
  int v94; // [esp+50h] [ebp+52h]
  int v95; // [esp+54h] [ebp+56h]
  int v96; // [esp+58h] [ebp+5Ah]
  int v97; // [esp+5Ch] [ebp+5Eh]
  int v98; // [esp+60h] [ebp+62h]
  int v99; // [esp+64h] [ebp+66h]
  int v100; // [esp+68h] [ebp+6Ah]
  int v101; // [esp+6Ch] [ebp+6Eh]
  int v102; // [esp+70h] [ebp+72h]
  int v103; // [esp+74h] [ebp+76h]
  int v104; // [esp+78h] [ebp+7Ah]
  int v105; // [esp+7Ch] [ebp+7Eh]

  byte_199F34 = 85;
  v101 = 0;
  qmemcpy(v75, sub_8E5C5(2u, 85, 126), sizeof(v75));
  if ( !byte_19C062 && word_19994C )
  {
    sub_124D41();
    sub_84E9D();
    sub_124DEC();
    sub_124C08();
    word_19994C = 0;
  }
  if ( !byte_19C062 )
    sub_12A478(word_19983C, word_19983A, *(_DWORD *)(dword_19C044 + 32));
  sub_120D79(2, (int)v75);
  v0 = v75[0];
  v1 = 0;
  sub_120DED(0, v75[0]);
  v2 = 0;
  sub_120E8C(1);
  while ( 1 )
  {
    LOWORD(v0) = word_19983C;
    LOWORD(v3) = word_19983A;
    v4 = v0 + 26;
    v5 = v3 + 41;
    v79 = v4;
    if ( v1 >= 13 )
      break;
    v92 = v2 + v5;
    sub_12B753(*(_DWORD *)(dword_19C044 + 36), *(int16_t *)(2 * v1 + dword_19C038 + 144));
    if ( byte_19C062 )
    {
      sub_12F7E6(0, 0, *(int16_t **)(dword_19C044 + 36), (int16_t *)dword_19C150);
      v0 = (int16_t)(v92 - word_19983A);
      v3 = sub_12F7E6((int16_t)(v79 - word_19983C), v0, (int16_t *)dword_19C150, (int16_t *)dword_19C034);
    }
    else
    {
      v0 = (int16_t)v92;
      v3 = sub_12A478(v79, v92, *(_DWORD *)(dword_19C044 + 36));
    }
    v2 += 17;
    ++v1;
  }
  if ( byte_19C062 )
  {
    v6 = 26;
    v7 = 41;
  }
  else
  {
    v6 = v4;
    v7 = v5;
  }
  v98 = v7 + 17 * (v101 + 2) + 2;
  v87 = v101 + 3;
  v82 = v101 + 4;
  v91 = 17 * (v101 + 1) + v7 + 2;
  v85 = v101 + 5;
  v81 = 17 * (v101 + 3) + v7;
  v94 = v81 + 2;
  v89 = 17 * (v101 + 4) + v7;
  v84 = v101 + 7;
  v96 = v89 + 2;
  v88 = v101 + 8;
  v99 = v7 + 17 * (v101 + 5) + 2;
  v86 = v101 + 9;
  v97 = 17 * (v101 + 6) + v7 + 2;
  v102 = v7 + 17 * (v101 + 7) + 2;
  v83 = v101 + 10;
  v105 = v7 + 17 * (v101 + 8) + 2;
  v80 = 17 * (v101 + 9);
  v100 = v7 + v80;
  v90 = v101 + 12;
  v95 = v7 + 17 * (v101 + 10) + 2;
  v8 = v6 + 4;
  v9 = 17 * v101 + v7 + 2;
  v103 = v7 + v80 + 2;
  v104 = v7 + 17 * (v101 + 11) + 2;
  v93 = 17 * (v101 + 12) + v7 + 2;
  if ( byte_19C062 )
  {
    v10 = dword_19C034;
    v11 = v8 + **(_WORD **)(dword_19C044 + 36);
    v12 = sub_7A990(0xA6u);
    v13 = v11;
    v76 = v9;
    sub_122A6E(v11, v9, (int)v12, v10);
    v11 += 150;
    sub_122A6E(v11, v76, (int)aAltF1, dword_19C034);
    v14 = (int16_t)v91;
    v15 = dword_19C034;
    v16 = sub_7A990(0xA7u);
    v76 = v14;
    sub_122A6E(v13, v14, (int)v16, v15);
    sub_122A6E(v11, v76, (int)aAltF2, dword_19C034);
    v17 = (int16_t)v98;
    v18 = dword_19C034;
    v19 = sub_7A990(0xA8u);
    v77 = v17;
    sub_122A6E(v13, v17, (int)v19, v18);
    sub_122A6E(v11, v77, (int)aAltF3, dword_19C034);
    LOWORD(v17) = v94;
    v20 = dword_19C034;
    v21 = sub_7A990(0xA9u);
    sub_122A6E(v13, v17, (int)v21, v20);
    v22 = (int16_t)v96;
    v23 = dword_19C034;
    v24 = sub_7A990(0xAAu);
    v76 = v22;
    sub_122A6E(v13, v22, (int)v24, v23);
    sub_122A6E(v11, v76, (int)aAltF5, dword_19C034);
    v25 = (int16_t)v99;
    v26 = dword_19C034;
    v27 = sub_7A990(0xABu);
    v78 = v25;
    sub_122A6E(v13, v25, (int)v27, v26);
    sub_122A6E(v11, v78, (int)aAltF6, dword_19C034);
    v28 = (int16_t)v97;
    v29 = dword_19C034;
    v30 = sub_7A990(0xACu);
    v76 = v28;
    sub_122A6E(v13, v28, (int)v30, v29);
    sub_122A6E(v11, v76, (int)aAltF7, dword_19C034);
    v31 = (int16_t)v102;
    v32 = dword_19C034;
    v33 = sub_7A990(0xADu);
    v76 = v31;
    sub_122A6E(v13, v31, (int)v33, v32);
    sub_122A6E(v11, v76, (int)aAltF8, dword_19C034);
    LOWORD(v31) = v105;
    v34 = dword_19C034;
    v35 = sub_7A990(0xAEu);
    sub_122A6E(v13, v31, (int)v35, v34);
    LOWORD(v31) = v103;
    v36 = dword_19C034;
    v37 = sub_7A990(0xAFu);
    sub_122A6E(v13, v31, (int)v37, v36);
    LOWORD(v31) = v95;
    v38 = dword_19C034;
    v39 = sub_7A990(0xB0u);
    sub_122A6E(v13, v31, (int)v39, v38);
    LOWORD(v31) = v104;
    v40 = dword_19C034;
    v41 = sub_7A990(0xB1u);
    sub_122A6E(v13, v31, (int)v41, v40);
    LOWORD(v31) = v93;
    v42 = dword_19C034;
    v43 = sub_7A990(0x187u);
    v44 = 41;
    sub_122A6E(v13, v31, (int)v43, v42);
    v45 = 0;
    do
    {
      v46 = *(int16_t *)(2 * v45++ + dword_19C038 + 144);
      sub_12B753(*(_DWORD *)(dword_19C044 + 36), v46);
      v47 = (int16_t)v44;
      v44 += 17;
      sub_12F7E6(26, v47, *(int16_t **)(dword_19C044 + 36), (int16_t *)dword_19C034);
    }
    while ( v45 < 13 );
  }
  else
  {
    v48 = v8 + **(_WORD **)(dword_19C044 + 36);
    v49 = sub_7A990(0xA6u);
    v50 = v48;
    sub_1212B3(v48, v9, (int)v49);
    v48 += 150;
    sub_1212B3(v48, v9, (int)aAltF1_0);
    v51 = v91;
    v52 = sub_7A990(0xA7u);
    sub_1212B3(v50, v51, (int)v52);
    sub_1212B3(v48, v51, (int)aAltF2_0);
    v53 = v98;
    v54 = sub_7A990(0xA8u);
    sub_1212B3(v50, v53, (int)v54);
    sub_1212B3(v48, v53, (int)aAltF3_0);
    v55 = v94;
    v56 = sub_7A990(0xA9u);
    sub_1212B3(v50, v55, (int)v56);
    v57 = v96;
    v58 = sub_7A990(0xAAu);
    sub_1212B3(v50, v57, (int)v58);
    sub_1212B3(v48, v57, (int)aAltF4);
    v59 = v99;
    v60 = sub_7A990(0xABu);
    sub_1212B3(v50, v59, (int)v60);
    sub_1212B3(v48, v59, (int)aAltF5_0);
    v61 = v97;
    v62 = sub_7A990(0xACu);
    sub_1212B3(v50, v61, (int)v62);
    sub_1212B3(v48, v61, (int)aAltF6_0);
    v63 = v102;
    v64 = sub_7A990(0xADu);
    sub_1212B3(v50, v63, (int)v64);
    sub_1212B3(v48, v63, (int)aAltF7_0);
    v65 = v105;
    v66 = sub_7A990(0xAEu);
    sub_1212B3(v50, v65, (int)v66);
    sub_1212B3(v48, v65, (int)aAltF8_0);
    v67 = v103;
    v68 = sub_7A990(0xAFu);
    sub_1212B3(v50, v67, (int)v68);
    v69 = v95;
    v70 = sub_7A990(0xB0u);
    sub_1212B3(v50, v69, (int)v70);
    v71 = v104;
    v72 = sub_7A990(0xB1u);
    sub_1212B3(v50, v71, (int)v72);
    v73 = v93;
    v74 = sub_7A990(0x187u);
    sub_1212B3(v50, v73, (int)v74);
  }
  JUMPOUT(0x7E505);
}
// 8011A: control flows out of bounds to 7E505
// 7FB7E: variable 'v3' is possibly undefined
// 19983A: using guessed type int16_t word_19983A;
// 19983C: using guessed type int16_t word_19983C;
// 19994C: using guessed type int16_t word_19994C;
// 199F34: using guessed type char byte_199F34;
// 19C034: using guessed type int dword_19C034;
// 19C038: using guessed type int dword_19C038;
// 19C044: using guessed type int dword_19C044;
// 19C062: using guessed type char byte_19C062;
// 19C150: using guessed type int dword_19C150;


//----- (0008012F) --------------------------------------------------------
void __fastcall sub_8012F(int a1, int a2)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edx
  _DWORD *v5; // eax
  int v6; // eax
  int v7; // eax
  int16_t v8[278]; // [esp+0h] [ebp-240h] BYREF
  int16_t v9; // [esp+22Ch] [ebp-14h] BYREF
  int v10; // [esp+230h] [ebp-10h]
  int v11; // [esp+234h] [ebp-Ch] BYREF
  int16_t v12; // [esp+238h] [ebp-8h] BYREF
  char v13; // [esp+23Ch] [ebp-4h]

  v13 = 1;
  v11 = 0;
  byte_199F1A = 1;
  byte_19C066 = 0;
  LOWORD(a1) = word_199830;
  v10 = a1;
  sub_11C2F0();
  byte_199F09 = 0;
  qmemcpy(v8, &byte_199BDC, 0x229u);
  if ( (uint16_t)word_199830 >= 4u )
    word_199830 = 0;
  sub_7D892();
  sub_124D41();
  sub_84E9D();
  sub_124DEC();
  sub_124C08();
  word_19994C = 0;
  v2 = 632;
  sub_7EA5C(v3, a2, 632, v8);
  v4 = -1;
  sub_111499(dword_192ED4);
  memset(dword_19C038, -1, 632);
  sub_7EFEF();
  while ( 1 )
  {
    sub_119281();
    byte_19C06A = 1;
    if ( v13 )
    {
      if ( byte_199BE2 )
      {
        sub_124D41();
        v2 = 1;
        v4 = 0;
        v5 = sub_7EDF2(*(int16_t **)dword_19C044, 0, 1, 0);
      }
      else
      {
        sub_124D41();
        sub_84E9D();
        sub_124DEC();
        sub_124C08();
        word_19994C = 0;
      }
      v13 = 0;
    }
    else
    {
      sub_124D41();
      sub_84E9D();
      sub_124DEC();
      sub_124C08();
      word_19994C = 0;
    }
    if ( word_199830 == 2 || word_199830 == 3 )
    {
      sub_1131F0((int)v5, v4);
      sub_80556();
      word_199A10 = (uint8_t)byte_199F19;
    }
    sub_11C2F0();
    v4 = (int)&v9;
    sub_7D061(&v12, &v9);
    switch ( word_199830 )
    {
      case 0:
        sub_7DD41(0, v8, byte_199E05);
        break;
      case 1:
        sub_7E00F(&v11);
        break;
      case 2:
        sub_7DA76(&v11, (int)&v9, v2, 0);
        break;
      case 3:
        sub_7E154();
        break;
      default:
        break;
    }
    if ( (_WORD)v11 )
    {
      if ( !byte_19C068 )
      {
        sub_7F14C();
        sub_12030();
      }
      word_199A08 = word_199A10;
      sub_119281();
      sub_11C2F0();
      if ( byte_199BE2 && !*(_BYTE *)(dword_19C044 + 100) && !byte_19C068 )
      {
        byte_19C064 = 1;
        sub_124D41();
        sub_7F701((int)&v9, (int)byte_199E05);
        sub_1077D(v6, (int)&v9, v2, v8);
        sub_12C2A0();
        sub_12C2C6(7);
        sub_124D41();
        v2 = -1;
        v4 = *(int16_t *)(*(_DWORD *)dword_19C044 + 2);
        sub_7EDF2(*(int16_t **)dword_19C044, v4, -1, 0);
      }
      if ( word_199A08 == 13 )
      {
        sub_C5BB9();
      }
      else if ( !byte_19C066 )
      {
        sub_11C2F0();
        sub_1172D4();
        byte_199F28 = 1;
        sub_82348();
        sub_124D41();
        LOWORD(v7) = sub_84E9D();
        sub_1077D(v7, v4, v2, v8);
        sub_1172FC();
      }
      JUMPOUT(0x7DA0C);
    }
  }
}
// 8038A: control flows out of bounds to 7DA0C
// 801BE: variable 'v3' is possibly undefined
// 8026C: variable 'v5' is possibly undefined
// 80348: variable 'v6' is possibly undefined
// 803C1: variable 'v7' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 199830: using guessed type int16_t word_199830;
// 19994C: using guessed type int16_t word_19994C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199BDC: using guessed type char byte_199BDC;
// 199BE2: using guessed type char byte_199BE2;
// 199F09: using guessed type char byte_199F09;
// 199F19: using guessed type char byte_199F19;
// 199F1A: using guessed type char byte_199F1A;
// 199F28: using guessed type char byte_199F28;
// 19C038: using guessed type int dword_19C038;
// 19C044: using guessed type int dword_19C044;
// 19C064: using guessed type char byte_19C064;
// 19C066: using guessed type char byte_19C066;
// 19C068: using guessed type char byte_19C068;
// 19C06A: using guessed type char byte_19C06A;


//----- (000803D9) --------------------------------------------------------
int sub_803D9()
{
  _DWORD *v0; // eax
  int v1; // ebx
  _DWORD *v2; // eax
  int v3; // ebx
  _DWORD *v4; // eax
  int v5; // ebx
  _DWORD *v6; // eax
  int v7; // ebx
  _DWORD *v8; // eax
  int v9; // ebx
  _DWORD *v10; // eax
  int v11; // ebx
  _DWORD *v12; // edx
  int result; // eax

  v0 = sub_126B42((int)off_1820B4, 20, dword_192ED4);
  v1 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 44) = v0;
  v2 = sub_126B42((int)off_1820B4, 21, v1);
  v3 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 48) = v2;
  v4 = sub_126B42((int)off_1820B4, 22, v3);
  v5 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 52) = v4;
  v6 = sub_126B42((int)off_1820B4, 23, v5);
  v7 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 64) = v6;
  v8 = sub_126B42((int)off_1820B4, 24, v7);
  v9 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 68) = v8;
  v10 = sub_126B42((int)off_1820B4, 25, v9);
  v11 = dword_192ED4;
  *(_DWORD *)(dword_19C044 + 72) = v10;
  v12 = sub_126B42((int)off_1820B4, 26, v11);
  result = dword_19C044;
  *(_DWORD *)(dword_19C044 + 76) = v12;
  return result;
}
// 1820B4: using guessed type char *off_1820B4;
// 192ED4: using guessed type int dword_192ED4;
// 19C044: using guessed type int dword_19C044;


//----- (000804B7) --------------------------------------------------------
char __fastcall sub_804B7(_WORD *a1)
{
  char v2; // al

  word_199830 = 2;
  byte_19C06A = 1;
  dword_19C088 = (int)sub_126AFD((int)aMainmenuLbx_0, 21, dword_192ED4);
  dword_19C044 = (int)sub_110D3C(dword_192ED4, 101);
  dword_19C038 = (int)sub_110D3C(dword_192ED4, 632);
  memset(dword_19C044, 0, 101);
  memset(dword_19C038, -1, 632);
  sub_7E913();
  sub_803D9();
  sub_80556();
  sub_7DA76(a1, -1, 632, (int)a1);
  LOBYTE(a1) = v2;
  sub_11C2F0();
  return (char)a1;
}
// 80549: variable 'v2' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 199830: using guessed type int16_t word_199830;
// 19C038: using guessed type int dword_19C038;
// 19C044: using guessed type int dword_19C044;
// 19C06A: using guessed type char byte_19C06A;
// 19C088: using guessed type int dword_19C088;


//----- (00080556) --------------------------------------------------------
void sub_80556()
{
  int v0; // edx
  int v1; // ecx
  int i; // eax
  int v3; // ebx
  int v4; // eax
  int16_t v5; // bx
  char *v6; // eax
  _BOOL1 v7; // bl
  _BYTE v8[25]; // [esp+0h] [ebp-20h] BYREF
  int v9; // [esp+1Ch] [ebp-4h]

  sub_11C83();
  v0 = 0;
  do
  {
    v1 = strlen(&byte_1996BE[37 * (int16_t)v0]);
    for ( i = v1; (int16_t)i < 37; ++i )
    {
      v1 = 37 * (int16_t)v0;
      v3 = (int16_t)i;
      byte_1996BE[v1 + v3] = 0;
    }
    ++v0;
  }
  while ( (int16_t)v0 < 10 );
  sub_1131F0(i, v0);
  sub_7E752(dword_19268C);
  sub_1131F0(v4, v0);
  v5 = 0;
  sub_7E7FF(dword_19C038, dword_192688, 0, v1);
  v9 = 0;
  while ( 1 )
  {
    qmemcpy(v8, (void *)(dword_192688 + (int16_t)v9), sizeof(v8));
    if ( !byte_1996BE[37 * v5] && v8[0] )
    {
      v6 = sub_7A990(0xCBu);
      sprintf(&byte_1996BE[37 * v5], v6, v5);
    }
    ++v5;
    v9 += 25;
    if ( v5 >= 10 )
    {
      v7 = 1;
      if ( (uint16_t)byte_199BF1 <= 9u )
        v7 = *(_DWORD *)(dword_19C038 + 4 * byte_199BF1) <= 0;
      if ( v7 )
        byte_199BF1 = -1;
      JUMPOUT(0x7DA0C);
    }
  }
}
// 80653: control flows out of bounds to 7DA0C
// 805B4: variable 'v4' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192688: using guessed type int dword_192688;
// 19268C: using guessed type int dword_19268C;
// 199BF1: using guessed type char byte_199BF1;
// 19C038: using guessed type int dword_19C038;


//----- (00080658) --------------------------------------------------------
void __fastcall sub_80658(char *a1)
{
  if ( *a1 == 3 )
  {
    memmove(a1, a1 + 1, (int16_t)strlen(a1));
    a1[(int16_t)sub_8FE65(a1)] = 0;
  }
  JUMPOUT(0x7D88C);
}
// 8069D: control flows out of bounds to 7D88C
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);


//----- (000806A2) --------------------------------------------------------
int __fastcall sub_806A2(char *a1, int a2)
{
  int16_t v2; // cx
  int result; // eax
  _BYTE *v4; // [esp+0h] [ebp+7Ah]
  char v5; // [esp+4h] [ebp+7Eh] BYREF
  _BYTE v6[203]; // [esp+5h] [ebp+7Fh] BYREF

  v2 = strlen(a1);
  result = memset(&v5, 0, 201);
  if ( v2 <= 200 )
  {
    result = v2;
    if ( v2 < a2 - 2 && *v4 != 3 )
    {
      v5 = 3;
      qmemcpy(v6, v4, v2);
      v6[v2] = 1;
      qmemcpy(v4, &v5, v2 + 2);
    }
  }
  return result;
}
// 806E4: variable 'v4' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (00080715) --------------------------------------------------------
int16_t __fastcall sub_80715(_WORD *a1)
{
  char *v2; // eax
  int16_t result; // ax
  int v4; // [esp-8h] [ebp-F8h]
  char *v5; // [esp-4h] [ebp-F4h]
  _BYTE v6[200]; // [esp+0h] [ebp-F0h] BYREF

  sub_11C83();
  v5 = &byte_1996BE[37 * byte_199BF1];
  v4 = byte_199BF1;
  v2 = sub_7A990(0xCCu);
  sprintf(v6, v2, v4, v5);
  result = sub_7A25F(&byte_199F28, (int)v6, 1);
  if ( result )
  {
    sub_1160B(byte_199BF1, (int)v6, 1, (int)a1);
    byte_19C1A2 = 1;
    result = word_199A08;
    *a1 = 1;
    word_199A10 = result;
  }
  else
  {
    word_19994C = 1;
    *a1 = 0;
  }
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19994C: using guessed type int16_t word_19994C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199BF1: using guessed type char byte_199BF1;
// 199F28: using guessed type char byte_199F28;
// 19C1A2: using guessed type char byte_19C1A2;


//----- (000807A6) --------------------------------------------------------
char __fastcall sub_807A6(_WORD *a1)
{
  char *v2; // eax
  int16_t v3; // ax
  int v5; // [esp-8h] [ebp-F8h]
  char *v6; // [esp-4h] [ebp-F4h]
  _BYTE v7[200]; // [esp+0h] [ebp-F0h] BYREF

  sub_11C83();
  v6 = &byte_1996BE[37 * byte_199BF1];
  v5 = byte_199BF1;
  v2 = sub_7A990(0xCDu);
  sprintf(v7, v2, v5, v6);
  v3 = sub_7A25F(&byte_199F28, (int)v7, 1);
  if ( v3 )
  {
    LOBYTE(v3) = sub_10E2F(byte_199BF1, (int)v7, 1, (int)a1);
    if ( byte_199F3A == 1 )
      word_199A10 = 17;
    else
      word_199A10 = 39;
    *a1 = 1;
  }
  else
  {
    word_19994C = 1;
    *a1 = 0;
  }
  return v3;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19994C: using guessed type int16_t word_19994C;
// 199A10: using guessed type int16_t word_199A10;
// 199BF1: using guessed type char byte_199BF1;
// 199F28: using guessed type char byte_199F28;
// 199F3A: using guessed type char byte_199F3A;


//----- (00080841) --------------------------------------------------------
int sub_80841()
{
  return sub_12A478(word_19983C + 147, word_19983A + 43, *(_DWORD *)(dword_19C044 + 92));
}
// 19983A: using guessed type int16_t word_19983A;
// 19983C: using guessed type int16_t word_19983C;
// 19C044: using guessed type int dword_19C044;


//----- (0008086D) --------------------------------------------------------
void sub_8086D()
{
  JUMPOUT(0x80864);
}
// 80890: control flows out of bounds to 80864
// 19C044: using guessed type int dword_19C044;


//----- (00080892) --------------------------------------------------------
void sub_80892()
{
  int v0; // edx

  v0 = 100 * (100 * *(int16_t *)(dword_19C038 + 116) / 155) / 100;
  if ( (int16_t)v0 <= 5 )
  {
    sub_113D23();
    sub_24831();
    byte_199BEF = 0;
    LOWORD(v0) = 0;
    *(_WORD *)(dword_19C038 + 120) = 0;
  }
  else
  {
    *(_WORD *)(dword_19C038 + 120) = 1;
    if ( !byte_199BEF )
    {
      sub_113CFB();
      byte_199BEF = 1;
      sub_2484F();
    }
  }
  byte_199BF0 = v0;
  sub_113C6B((int16_t)v0);
  sub_113AF2((int16_t)v0);
}
// 199BEF: using guessed type char byte_199BEF;
// 199BF0: using guessed type char byte_199BF0;
// 19C038: using guessed type int dword_19C038;


//----- (00080918) --------------------------------------------------------
int __fastcall sub_80918( int a1)
{
  int v2; // eax
  int result; // eax

  v2 = 100 * (100 * *(int16_t *)(dword_19C038 + 118) / 155) / 100;
  byte_199F09 = 0;
  byte_199BEE = v2;
  if ( (uint8_t)v2 <= 5u )
  {
    byte_199BEE = 0;
    sub_112686(0);
    result = dword_19C038;
    byte_199BED = 0;
    *(_WORD *)(dword_19C038 + 122) = 0;
  }
  else
  {
    if ( !byte_199BED )
      sub_112269();
    byte_199BED = 1;
    sub_112686((uint8_t)byte_199BEE);
    if ( a1 )
      sub_112399(33);
    result = dword_19C038;
    *(_WORD *)(dword_19C038 + 122) = 1;
  }
  return result;
}
// 199BED: using guessed type char byte_199BED;
// 199BEE: using guessed type char byte_199BEE;
// 199F09: using guessed type char byte_199F09;
// 19C038: using guessed type int dword_19C038;


//----- (000809AE) --------------------------------------------------------
void __fastcall sub_809AE( int a1)
{
  int16_t v1; // si
  int16_t v2; // dx
  int16_t v3; // ax
  int v4; // ebx
  int v5; // edx
  int16_t v6; // [esp+0h] [ebp-14h]
  int v7; // [esp+4h] [ebp-10h]
  int v8; // [esp+8h] [ebp-Ch]
  int v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  v10 = 0;
  v1 = 0;
  v9 = 17 - (a1 + 1) / 2;
  while ( 1 )
  {
    if ( v1 >= v6 )
    {
      v5 = dword_19C038;
      *(_WORD *)(dword_19C038 + 2 * v1 + 620) = -1000;
      *(_WORD *)(v5 + 2 * v1 + 608) = -1000;
    }
    else
    {
      v8 = 124 * ((int16_t)v10 % 2) + word_19983C + 26;
      v2 = 17 * (v9 + (int16_t)v10 / 2) + word_19983A + 41;
      v3 = sub_11438B(
             124 * ((int16_t)v10 % 2) + word_19983C + 26 + 23,
             v2,
             124 * ((int16_t)v10 % 2) + word_19983C + 26 + 106,
             v2 + *(_WORD *)(*(_DWORD *)(dword_19C044 + 36) + 2),
             &unk_179597,
             41);
      v4 = dword_19C038 + 606;
      v7 = 2 * v1;
      *(_WORD *)(v4 + v7 + 14) = v3;
      ++v10;
      *(_WORD *)(v7 + dword_19C038 + 608) = sub_115383(
                                              v8,
                                              v2,
                                              (int)&unk_179597,
                                              *(_WORD **)(dword_19C044 + 36),
                                              v4,
                                              v1,
                                              &unk_179597,
                                              41);
    }
    if ( ++v1 >= 5 )
      JUMPOUT(0x7DA0C);
  }
}
// 80AC7: control flows out of bounds to 7DA0C
// 809D6: variable 'v6' is possibly undefined
// 19983A: using guessed type int16_t word_19983A;
// 19983C: using guessed type int16_t word_19983C;
// 19C038: using guessed type int dword_19C038;
// 19C044: using guessed type int dword_19C044;


//----- (00080AE4) --------------------------------------------------------
int sub_80AE4()
{
  int64_t v0; // rax
  int16_t v2; // dx
  int result; // eax
  _BYTE v4[16]; // [esp+0h] [ebp-20h] BYREF
  _BYTE v5[16]; // [esp+10h] [ebp-10h] BYREF

  sub_11FCC(9);
  v0 = sprintf(v4, "save%d.gam", 10);
  sub_11C2F0();
  if ( BYTE4(v0) <= 1u && FindMoxSetPath_1114D7(v4, v5) == 1 )
    *(_WORD *)(dword_19C090 + 12) = sub_11438B(415, 172, 567, 193, aC_1, 41);
  else
    *(_WORD *)(dword_19C090 + 12) = -1000;
  if ( word_1999E4 || FindMoxSetPath_1114D7(aSaveGam, v5) != 1 )
    *(_WORD *)(dword_19C090 + 26) = -1000;
  else
    *(_WORD *)(dword_19C090 + 26) = sub_11438B(415, 195, 567, 215, aLnmhq, 41);
  *(_WORD *)(dword_19C090 + 40) = sub_11438B(415, 217, 567, 238, &aLnmhq[1], 41);
  *(_WORD *)(dword_19C090 + 54) = sub_11438B(415, 240, 567, 260, &aLnmhq[2], 41);
  *(_WORD *)(dword_19C090 + 68) = sub_11438B(415, 262, 567, 283, &aLnmhq[3], 41);
  v2 = sub_11438B(415, 285, 567, 306, &aLnmhq[4], 41);
  result = dword_19C090;
  *(_WORD *)(dword_19C090 + 82) = v2;
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17969C: using guessed type wchar_t aLnmhq[6];
// 1999E4: using guessed type int16_t word_1999E4;
// 19C090: using guessed type int dword_19C090;


//----- (00080C6F) --------------------------------------------------------
int __fastcall sub_80C6F( int a1, int a2)
{
  int v4; // edx
  int result; // eax

  v4 = 1;
  do
  {
    result = (int16_t)v4++;
    *(_BYTE *)(a2 + result) += a1;
  }
  while ( (int16_t)v4 < 8 );
  return result;
}


//----- (00080C8A) --------------------------------------------------------
char __fastcall sub_80C8A( int a1, int a2)
{
  _BYTE *v2; // eax
  int v3; // eax
  _BYTE *v4; // eax
  int v5; // eax
  int16_t v6; // bx
  char v9[100]; // [esp+8h] [ebp-6Ch] BYREF
  int v10; // [esp+6Ch] [ebp-8h]
  char v11; // [esp+70h] [ebp-4h]

  v2 = (_BYTE *)(dword_19C06C + 254 * a1);
  v10 = 0;
  if ( *v2 || v2[127] )
  {
    strcpy(v9, (char *)(dword_19C06C + 254 * a1));
    sub_122A6E(v10, 0, (int)v9, a2);
    if ( v9[0] )
      v3 = sub_12066F((int)v9) + 4;
    else
      v3 = 0;
    v10 += v3;
    v4 = (_BYTE *)(254 * a1 + dword_19C06C);
    if ( *v4 && v4[127] )
    {
      v11 = 0;
      do
      {
        sub_122A6E(v10, 0, (int)&aLnmhq[5], a2);
        v5 = sub_12066F((int)&aLnmhq[5]);
        v10 += v5;
        if ( (uint8_t)byte_19C09A <= (int16_t)v10 )
          v11 = 1;
      }
      while ( !v11 );
    }
    v6 = (uint8_t)byte_19C09A + 4;
    strcpy(v9, (char *)(dword_19C06C + 254 * a1 + 127));
    LOBYTE(v2) = sub_122A6E(v6, 0, (int)v9, a2);
  }
  return (char)v2;
}
// 17969C: using guessed type wchar_t aLnmhq[6];
// 19C06C: using guessed type int dword_19C06C;
// 19C09A: using guessed type char byte_19C09A;


//----- (00080DB4) --------------------------------------------------------
int __fastcall sub_80DB4(int a1, int a2, int a3, int a4)
{
  int v4; // edx
  char *v5; // eax
  int v6; // eax
  _DWORD *v7; // eax
  int16_t *v8; // edi
  int v9; // edx
  unsigned int v10; // ebx
  int v11; // eax
  int16_t v12; // si
  int v13; // eax
  int v14; // eax
  int16_t i; // ax
  int v16; // eax
  _WORD v18[8]; // [esp+0h] [ebp-24h]
  int v19; // [esp+10h] [ebp-14h]
  int v20; // [esp+14h] [ebp-10h]
  int v21; // [esp+18h] [ebp-Ch]
  int v22; // [esp+1Ch] [ebp-8h]
  char v23; // [esp+20h] [ebp-4h]

  v21 = 0;
  v22 = -1;
  v23 = 0;
  sub_12C607((int)aMainmenuLbx, 0, a3, a4);
  v4 = sub_8152B();
  if ( !(_WORD)dword_1845E0 )
  {
    v5 = sub_7A990(0xCEu);
    sub_126487(v5, v4);
  }
  HIWORD(v6) = HIWORD(dword_1B06FC);
  LOWORD(v6) = *(_WORD *)(dword_1B06FC + 6);
  v20 = v6 - 1;
  v7 = sub_110D3C(dword_192ED4, v4);
  sub_12D7B7((int)v7);
  sub_1318D4(0, 255);
  sub_12B79D(dword_19C08C);
  sub_11C2F0();
  v18[0] = sub_11438B(10, 20, 25, 35, aC_1, 41);
  v18[1] = sub_11438B(20, 30, 35, 45, aS_4, 41);
  v18[2] = sub_11438B(30, 40, 45, 55, aLnmhq, 41);
  v18[3] = sub_11438B(40, 50, 55, 65, &aLnmhq[2], 41);
  v18[4] = sub_11438B(50, 60, 65, 75, &aLnmhq[3], 41);
  v18[5] = sub_11438B(60, 70, 75, 85, &aLnmhq[4], 41);
  v8 = (int16_t *)sub_114C72(&off_1796B7, 70);
  v9 = 1;
  v10 = sub_11438B(0, 0, 639, 479, (_BYTE *)&off_1796B7 + 2, 41);
  sub_1191CA((int)sub_8139F, 1);
  while ( !(_WORD)v21 )
  {
    sub_12C2A0();
    v12 = sub_1171AB(v11, v9, v10, 479);
    LOWORD(v13) = sub_12D70B();
    v9 = v13;
    if ( (_WORD)v13 == 5 )
    {
      v14 = 53;
LABEL_9:
      v19 = sub_147D7(v14);
      goto LABEL_10;
    }
    if ( (_WORD)v13 == 46 )
    {
      sub_1127A3(v19);
      v14 = 54;
      goto LABEL_9;
    }
LABEL_10:
    if ( v12 == (_WORD)v10 || v12 == (_WORD)v8 )
    {
      v23 = 1;
LABEL_14:
      v21 = 1;
      goto LABEL_15;
    }
    if ( (_WORD)v9 == (_WORD)v20 )
      goto LABEL_14;
LABEL_15:
    for ( i = 0; i < 6 && !(_WORD)v21; ++i )
    {
      v9 = i;
      if ( v12 == v18[i] )
      {
        v9 = (uint16_t)i;
        switch ( i )
        {
          case 0:
            v22 = 67;
            break;
          case 1:
            v22 = 83;
            break;
          case 2:
            v22 = 76;
            break;
          case 3:
            v22 = 77;
            break;
          case 4:
            v22 = 72;
            break;
          case 5:
            v22 = 81;
            break;
          default:
            v9 = i;
            v22 = -1;
            break;
        }
        v23 = 1;
        v21 = 1;
      }
    }
    if ( !(_WORD)v21 )
    {
      sub_124D41();
      v16 = sub_12C7CC();
      sub_1077D(v16, v9, v10, v8);
    }
    sub_12C2C6(1);
  }
  if ( v23 )
  {
    sub_1127A3(v19);
    sub_147D7(54);
  }
  return v22;
}
// 80FB5: variable 'v11' is possibly undefined
// 80FC1: variable 'v13' is possibly undefined
// 17969C: using guessed type wchar_t aLnmhq[6];
// 1796B7: using guessed type _UNKNOWN *off_1796B7;
// 1845E0: using guessed type int dword_1845E0;
// 192ED4: using guessed type int dword_192ED4;
// 19C08C: using guessed type int dword_19C08C;
// 1B06FC: using guessed type int dword_1B06FC;


//----- (000810C7) --------------------------------------------------------
char __usercall sub_810C7(int16_t *a1)
{
  int v1; // ebx
  void *v2; // eax
  char result; // al
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = 0;
  dword_19C080 = (int)sub_126AFD((int)aMainmenuLbx, 21, dword_192ED4);
  sub_124C08();
  sub_124D7A();
  sub_128C32(0, 0, 649, 479, 0);
  v1 = dword_19C080;
  sub_12A478(0, 0, dword_19C080);
  v2 = sub_124E36();
  sub_1077D((int)v2, 0, v1, a1);
  sub_1196F7();
  byte_199F19 = 10;
  do
    result = sub_804B7(&v4);
  while ( (_WORD)v4 != 1 );
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 199F19: using guessed type char byte_199F19;
// 19C080: using guessed type int dword_19C080;


//----- (00081147) --------------------------------------------------------
void sub_81147()
{
  int v0; // eax
  int v1; // edx
  char v2; // bl
  int v3; // eax
  int v4; // edx
  char v5; // cl
  int v6; // eax
  _DWORD v7[2]; // [esp+0h] [ebp-34h] BYREF
  _DWORD v8[2]; // [esp+8h] [ebp-2Ch] BYREF
  _DWORD v9[2]; // [esp+10h] [ebp-24h] BYREF
  _BYTE v10[8]; // [esp+18h] [ebp-1Ch] BYREF
  int v11; // [esp+20h] [ebp-14h]
  int v12; // [esp+24h] [ebp-10h]
  int v13; // [esp+28h] [ebp-Ch]
  int v14; // [esp+2Ch] [ebp-8h]
  int v15; // [esp+30h] [ebp-4h]

  v9[0] = -707471917;
  v9[1] = dword_80ACC[1];
  v8[0] = -589636395;
  v8[1] = dword_80AD4[1];
  v11 = 66;
  v7[0] = -640165420;
  v7[1] = dword_80ADC[1];
  if ( word_19C096 > 0 )
  {
    --word_19C096;
  }
  else
  {
    dword_19C078 -= 2;
    dword_19C074 = 422 - dword_19C078;
    if ( dword_19C078 > 179 )
      v14 = -1;
    else
      v14 = (179 - dword_19C078) / 14;
    v0 = (422 - dword_19C078) / 14;
    v12 = v0;
    LOWORD(v0) = dword_19C078;
    v15 = 0;
    v13 = v0;
    while ( (int16_t)v15 < word_19C098 )
    {
      if ( (_WORD)v15 == (_WORD)v14 )
      {
        qmemcpy(v10, v7, sizeof(v10));
        v4 = 1;
        v5 = 2 * ((int16_t)(dword_19C078 - 179) % 14 / 3);
        do
        {
          v6 = (int16_t)v4++;
          v10[v6] += v5;
        }
        while ( (int16_t)v4 < 8 );
      }
      else if ( (_WORD)v15 == (_WORD)v12 )
      {
        qmemcpy(v10, v9, sizeof(v10));
        v1 = 1;
        v2 = 2
           * ((int)((422 - dword_19C078) % 14
                  - (__CFSHL__((uint64_t)((422 - dword_19C078) % 14) >> 32, 2)
                   + 4 * ((uint64_t)((422 - dword_19C078) % 14) >> 32))) >> 2);
        do
        {
          v3 = (int16_t)v1++;
          v10[v3] += v2;
        }
        while ( (int16_t)v1 < 8 );
      }
      else
      {
        qmemcpy(v10, v8, sizeof(v10));
      }
      sub_120DED(253, 253);
      sub_120D79(word_19C094, (int)v10);
      sub_120E8C((uint8_t)byte_19C09E);
      sub_12D8F5(289, 14, dword_19C070);
      sub_80C8A(v15, dword_19C070);
      sub_128AB6(66, 179, 354, 422);
      sub_12B634();
      ++v15;
      sub_12A478(v11, v13, dword_19C070);
      sub_12B65C();
      v13 += 14;
    }
  }
  if ( (int)abs32(dword_19C078 - 179) > 14 * word_19C098 )
  {
    word_19C096 = 10;
    dword_19C07C = 66;
    dword_19C078 = 422;
  }
  JUMPOUT(0x810C0);
}
// 8137C: control flows out of bounds to 810C0
// 80ACC: using guessed type int dword_80ACC[2];
// 80AD4: using guessed type int dword_80AD4[2];
// 80ADC: using guessed type int dword_80ADC[2];
// 19C070: using guessed type int dword_19C070;
// 19C074: using guessed type int dword_19C074;
// 19C078: using guessed type int dword_19C078;
// 19C07C: using guessed type int dword_19C07C;
// 19C094: using guessed type int16_t word_19C094;
// 19C096: using guessed type int16_t word_19C096;
// 19C098: using guessed type int16_t word_19C098;
// 19C09E: using guessed type char byte_19C09E;


//----- (00081381) --------------------------------------------------------
int sub_81381()
{
  return sub_12A478(0, 0, dword_19C08C);
}
// 19C08C: using guessed type int dword_19C08C;


//----- (00081395) --------------------------------------------------------
void sub_81395()
{
  JUMPOUT(0x81389);
}
// 8139D: control flows out of bounds to 81389


//----- (000813A4) --------------------------------------------------------
void __usercall sub_813A4(int16_t *a1)
{
  int v1; // ebx
  void *v2; // eax
  int16_t v3; // dx
  int v4; // ebx
  int16_t v5; // ax
  _BYTE v6[8]; // [esp+0h] [ebp-8h] BYREF

  if ( word_19994C )
  {
    sub_124D41();
    sub_128C32(0, 0, 639, 479, 0);
    v1 = dword_19C08C;
    sub_12A478(0, 0, dword_19C08C);
    v2 = sub_124DEC();
    sub_1077D((int)v2, 0, v1, a1);
    word_19C096 = 10;
    dword_19C07C = 66;
    dword_19C078 = 422;
    word_19994C = 0;
  }
  if ( word_1999BC == *(_WORD *)(dword_19C090 + 12) )
  {
    v3 = 172;
    v4 = *(_DWORD *)(dword_19C090 + 4);
  }
  else if ( word_1999BC == *(_WORD *)(dword_19C090 + 26) )
  {
    v3 = 195;
    v4 = *(_DWORD *)(dword_19C090 + 18);
  }
  else if ( word_1999BC == *(_WORD *)(dword_19C090 + 40) )
  {
    v3 = 217;
    v4 = *(_DWORD *)(dword_19C090 + 32);
  }
  else if ( word_1999BC == *(_WORD *)(dword_19C090 + 54) )
  {
    v3 = 240;
    v4 = *(_DWORD *)(dword_19C090 + 46);
  }
  else if ( word_1999BC == *(_WORD *)(dword_19C090 + 68) )
  {
    v3 = 262;
    v4 = *(_DWORD *)(dword_19C090 + 60);
  }
  else
  {
    if ( word_1999BC != *(_WORD *)(dword_19C090 + 82) )
      goto LABEL_16;
    v3 = 285;
    v4 = *(_DWORD *)(dword_19C090 + 74);
  }
  sub_12A478(415, v3, v4);
LABEL_16:
  if ( *(int16_t *)(dword_19C090 + 12) == -1000 )
    sub_12A478(415, 172, *(_DWORD *)(dword_19C090 + 8));
  if ( *(int16_t *)(dword_19C090 + 26) == -1000 )
    sub_12A478(415, 195, *(_DWORD *)(dword_19C090 + 22));
  if ( byte_19C09D )
    sub_81147();
  qmemcpy(v6, sub_8E5C5(1u, 210, 215), sizeof(v6));
  sub_120BB5(1, (int)v6);
  v5 = sub_122259();
  sub_1210FD(517, 443 - (v5 + 1), (int)aVer140b23);
  JUMPOUT(0x810C0);
}
// 81526: control flows out of bounds to 810C0
// 19994C: using guessed type int16_t word_19994C;
// 1999BC: using guessed type int16_t word_1999BC;
// 19C078: using guessed type int dword_19C078;
// 19C07C: using guessed type int dword_19C07C;
// 19C08C: using guessed type int dword_19C08C;
// 19C090: using guessed type int dword_19C090;
// 19C096: using guessed type int16_t word_19C096;
// 19C09D: using guessed type char byte_19C09D;


//----- (0008152B) --------------------------------------------------------
int sub_8152B()
{
  _DWORD *v0; // eax

  v0 = (_DWORD *)(dword_1B06FC + 12 + 4 * *(int16_t *)(dword_1B06FC + 4));
  return v0[1] - *v0 + 1;
}
// 1B06FC: using guessed type int dword_1B06FC;


//----- (00081547) --------------------------------------------------------
int __fastcall sub_81547(int a1, int a2)
{
  char *v2; // eax
  int v3; // eax

  if ( !(_WORD)dword_1845E0 )
  {
    v2 = sub_7A990(0xCEu);
    sub_126487(v2, a2);
  }
  HIWORD(v3) = HIWORD(dword_1B06FC);
  LOWORD(v3) = *(_WORD *)(dword_1B06FC + 6);
  return v3 - 1;
}
// 1845E0: using guessed type int dword_1845E0;
// 1B06FC: using guessed type int dword_1B06FC;


//----- (0008156B) --------------------------------------------------------
void __usercall sub_8156B(int a1, int a2, int16_t *a3)
{
  char *v3; // eax
  int v4; // ebx
  char *v5; // edx
  int16_t v6; // ax
  int v7; // edx
  char *v8; // esi
  char *v9; // esi
  int v10; // edx
  char *v11; // [esp-4h] [ebp-24h]
  char v12[20]; // [esp+0h] [ebp-20h] BYREF
  int v13; // [esp+14h] [ebp-Ch]
  int v14; // [esp+18h] [ebp-8h]
  int v15; // [esp+1Ch] [ebp-4h]

  v3 = sub_81B7C(v12);
  sub_FE8BE((int)v3, a1, a2, a3);
  v4 = dword_192ED4;
  v5 = (char *)sub_126C37((int)v12, 0, dword_192ED4, 0, 1u, 127);
  sub_FE8BE((int)v5, (int)v5, v4, a3);
  v6 = sub_12760B(v5);
  v7 = 254 * v6;
  v15 = 1;
  word_19C098 = v6;
  v14 = 0;
  dword_19C06C = (int)sub_110D3C(dword_192ED4, v7);
  while ( (int16_t)v14 < word_19C098 )
  {
    sub_FE8BE(v14, v7, v4, a3);
    sub_1112EC(dword_192ED4, v7);
    v8 = (char *)sub_126C37((int)v12, 0, dword_192ED4, (int16_t)v15, 1u, 127);
    sub_1113CC(dword_192ED4, 0);
    v13 = 254 * (int16_t)v14;
    strcpy((char *)(v13 + dword_19C06C), v8);
    ++v15;
    sub_1112EC(dword_192ED4, 0);
    v7 = 0;
    v4 = dword_192ED4;
    v9 = (char *)sub_126C37((int)v12, 0, dword_192ED4, (int16_t)v15, 1u, 127);
    sub_1113CC(dword_192ED4, 0);
    ++v15;
    ++v14;
    v11 = (char *)(v13 + dword_19C06C + 127);
    strcpy(v11, v9);
    a3 = (int16_t *)v11;
  }
  byte_19C09D = 1;
  word_19C096 = 0;
  word_1820C0 = 0;
  word_1820C2 = 0;
  dword_19C074 = 0;
  dword_19C07C = 66;
  dword_19C078 = 422;
  v10 = sub_12DAA4(289, 14);
  dword_19C070 = (int)sub_110D3C(dword_192ED4, v10);
  sub_FE8BE(dword_19C070, v10, v4, a3);
  JUMPOUT(0x810C0);
}
// 816ED: control flows out of bounds to 810C0
// 1820C0: using guessed type int16_t word_1820C0;
// 1820C2: using guessed type int16_t word_1820C2;
// 192ED4: using guessed type int dword_192ED4;
// 19C06C: using guessed type int dword_19C06C;
// 19C070: using guessed type int dword_19C070;
// 19C074: using guessed type int dword_19C074;
// 19C078: using guessed type int dword_19C078;
// 19C07C: using guessed type int dword_19C07C;
// 19C096: using guessed type int16_t word_19C096;
// 19C098: using guessed type int16_t word_19C098;
// 19C09D: using guessed type char byte_19C09D;


//----- (000816F2) --------------------------------------------------------
void __usercall sub_816F2(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int16_t v7; // si
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  int v13; // ebx
  void *v14; // eax
  int16_t *v15; // edi
  int v16; // eax
  int v17; // edx
  uint16_t v18; // ax
  char *v19; // eax
  int v20; // eax
  _BYTE v21[4]; // [esp+0h] [ebp-4h] BYREF

  sub_124B65();
  LOWORD(v4) = sub_11C2F0();
  sub_FE8BE(v4, a1, a3, a4);
  v5 = dword_192ED4;
  dword_19C088 = (int)sub_126AFD((int)aMainmenuLbx, 1, dword_192ED4);
  sub_FE8BE(dword_19C088, 210, v5, a4);
  sub_8156B(210, v5, a4);
  sub_FE8BE(v6, 210, v5, a4);
  byte_199F3A = 0;
  dword_19C090 = (int)sub_110CEE(dword_192EE8, 210);
  dword_19C084 = (int)sub_110D3C(dword_192EE8, 40);
  sub_FE8BE(dword_19C084, -1, 210, a4);
  memset(dword_19C090, -1, 210);
  dword_19C038 = (int)sub_110D3C(dword_192EE8, 632);
  dword_19268C = (int)sub_110D3C(dword_192EE8, 1000);
  v7 = -1;
  dword_192688 = (int)sub_110D3C(dword_192EE8, 1000);
  sub_FE8BE(dword_192688, 1000, 210, a4);
  if ( byte_19A005 )
  {
    sub_81ABE(v8, 1000, 210, a4);
    byte_19A005 = 0;
    sub_8F1C4((void (__fastcall *)(int, int))sub_81395, v21, 5);
    sub_124B65();
    v7 = sub_80DB4(v9, (int)v21, 5, a2);
  }
  else if ( byte_199F19 == 8
         || byte_199F19 == 14
         || byte_199F19 == 15
         || byte_199F19 == 12
         || byte_199F19 == 13
         || word_19994C )
  {
    word_19994C = 0;
    sub_81ABE(v8, (int)v21, 5, a4);
    sub_8F1C4((void (__fastcall *)(int, int))sub_81381, v21, 5);
  }
  else
  {
    if ( byte_199F19 != 10 )
    {
LABEL_13:
      sub_124C08();
      sub_124D7A();
      v12 = 479;
      sub_128C32(0, 0, 639, 479, 0);
      v13 = dword_19C08C;
      sub_12A478(0, 0, dword_19C08C);
      v14 = sub_124E36();
      sub_1077D((int)v14, 0, v13, a4);
      v15 = (int16_t *)sub_114C72(&aLnmhq[1], 2);
      sub_1191CA((int)sub_813A4, 2);
      sub_6FAC0();
      word_19C096 = 10;
      dword_19C07C = 66;
      dword_19C078 = 422;
      v17 = 0;
      while ( 1 )
      {
        if ( (_WORD)v17 )
        {
          word_19994C = 0;
          byte_19C1A0 = 1;
          sub_119281();
          JUMPOUT(0x810C0);
        }
        v12 = sub_1171AB(v16, v17, v13, v12);
        v13 = v12;
        word_1999BC = (uint16_t)sub_114177();
        sub_12C2A0();
        if ( (_WORD)v12 == *(_WORD *)(dword_19C090 + 12) || v7 == 67 && *(int16_t *)(dword_19C090 + 12) != -1000 )
          break;
        if ( (_WORD)v12 == *(_WORD *)(dword_19C090 + 40) || (_WORD)v12 == (_WORD)v15 || v7 == 78 )
        {
          word_199A08 = 13;
          word_199A10 = 0;
          goto LABEL_50;
        }
        if ( (_WORD)v12 == *(_WORD *)(dword_19C090 + 26) || v7 == 76 )
        {
          if ( sub_810C7(v15) )
          {
            if ( byte_199F3A != 2 && byte_199F3A != 3 )
            {
LABEL_24:
              if ( byte_199F3A == 1 )
                word_199A08 = 17;
              else
                word_199A08 = 39;
              goto LABEL_50;
            }
            v18 = 208;
LABEL_22:
            v19 = sub_7A990(v18);
            sub_77433(v19);
LABEL_23:
            word_199A08 = 10;
            goto LABEL_50;
          }
          if ( byte_199F19 )
          {
            v17 = 1;
            word_199A08 = 10;
            goto LABEL_51;
          }
          word_199A08 = 0;
        }
        else
        {
          if ( (_WORD)v12 == *(_WORD *)(dword_19C090 + 54) || v7 == 77 )
          {
            word_199A08 = 15;
          }
          else
          {
            if ( (_WORD)v12 != *(_WORD *)(dword_19C090 + 68) && v7 != 72 )
            {
              if ( (_WORD)v12 != *(_WORD *)(dword_19C090 + 82) && v7 != 81 )
                goto LABEL_51;
              word_199A08 = 7;
              goto LABEL_50;
            }
            word_199A08 = 14;
          }
          word_199A10 = 10;
        }
LABEL_50:
        v17 = 1;
LABEL_51:
        if ( !(_WORD)v17 )
        {
          sub_124D41();
          sub_813A4(v15);
          sub_1077D(v20, v17, v12, v15);
        }
        v16 = sub_12C2C6(3);
      }
      if ( sub_10E2F(9, v17, v12, v12) )
      {
        if ( byte_199F3A != 2 && byte_199F3A != 3 )
          goto LABEL_24;
        v18 = 207;
        goto LABEL_22;
      }
      goto LABEL_23;
    }
    sub_81ABE(v8, 1000, 210, a4);
    sub_124D41();
    sub_128C32(0, 0, 639, 479, 0);
    v10 = dword_19C08C;
    v11 = sub_12A478(0, 0, dword_19C08C);
    sub_1077D(v11, 0, v10, a4);
  }
  sub_80AE4();
  goto LABEL_13;
}
// 81AB9: control flows out of bounds to 810C0
// 81705: variable 'v4' is possibly undefined
// 81733: variable 'v6' is possibly undefined
// 817CA: variable 'v8' is possibly undefined
// 817ED: variable 'v9' is possibly undefined
// 81913: variable 'v16' is possibly undefined
// 81A90: variable 'v20' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17969C: using guessed type wchar_t aLnmhq[6];
// 192688: using guessed type int dword_192688;
// 19268C: using guessed type int dword_19268C;
// 192ED4: using guessed type int dword_192ED4;
// 192EE8: using guessed type int dword_192EE8;
// 19994C: using guessed type int16_t word_19994C;
// 1999BC: using guessed type int16_t word_1999BC;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199F19: using guessed type char byte_199F19;
// 199F3A: using guessed type char byte_199F3A;
// 19A005: using guessed type char byte_19A005;
// 19C038: using guessed type int dword_19C038;
// 19C078: using guessed type int dword_19C078;
// 19C07C: using guessed type int dword_19C07C;
// 19C084: using guessed type int dword_19C084;
// 19C088: using guessed type int dword_19C088;
// 19C08C: using guessed type int dword_19C08C;
// 19C090: using guessed type int dword_19C090;
// 19C096: using guessed type int16_t word_19C096;
// 19C1A0: using guessed type char byte_19C1A0;


//----- (00081ABE) --------------------------------------------------------
void __usercall sub_81ABE(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // ebx
  int v5; // ecx
  int16_t v6; // si
  int16_t *v7; // edi
  _DWORD *v8; // eax
  int v9; // ebx
  int v10; // ecx
  _DWORD *v11; // eax
  int v12; // ebx
  _DWORD *v13; // edx
  int v14; // eax

  sub_FE8BE(a1, a2, a3, a4);
  v4 = dword_192ED4;
  v5 = 3;
  v6 = 0;
  dword_19C08C = (int)sub_126B42((int)aMainmenuLbx, 2, dword_192ED4);
  sub_FE8BE(dword_19C08C, 2, v4, a4);
  do
  {
    v7 = (int16_t *)(14 * v6);
    v8 = sub_126B42((int)aMainmenuLbx, (int16_t)v5, dword_192ED4);
    v9 = dword_192ED4;
    v10 = v5 + 1;
    *(_DWORD *)((char *)v7 + dword_19C090) = v8;
    v11 = sub_126B42((int)aMainmenuLbx, (int16_t)v10, v9);
    v12 = dword_192ED4;
    ++v10;
    *(_DWORD *)((char *)v7 + dword_19C090 + 4) = v11;
    v13 = sub_126B42((int)aMainmenuLbx, (int16_t)v10, v12);
    v14 = dword_19C090;
    ++v6;
    *(int16_t *)((char *)v7 + dword_19C090 + 12) = -1000;
    v5 = v10 + 1;
    *(_DWORD *)((char *)v7 + v14 + 8) = v13;
    sub_FE8BE(v14, (int)v13, v12, v7);
  }
  while ( v6 < 6 );
  JUMPOUT(0x810C1);
}
// 81B63: control flows out of bounds to 810C1
// 192ED4: using guessed type int dword_192ED4;
// 19C08C: using guessed type int dword_19C08C;
// 19C090: using guessed type int dword_19C090;


//----- (00081B7C) --------------------------------------------------------
char *__fastcall sub_81B7C(char *a1)
{
  char *v1; // edi
  char *result; // eax
  char *v3; // kr00_4
  char v4; // dh
  char *v5; // esi
  int16_t v6; // bx
  char v7; // dl
  char *v8; // edi
  char *v9; // esi

  v1 = a1;
  LOBYTE(a1) = byte_199CAE;
  v3 = a1;
  result = (char *)(uint8_t)byte_199CAE;
  switch ( byte_199CAE )
  {
    case 1:
      v4 = -102;
      v5 = aGercrdtsLbx;
      v6 = 2;
      v7 = 2;
      goto LABEL_7;
    case 2:
      v4 = -92;
      v5 = aFrecrdtsLbx;
      goto LABEL_4;
    case 3:
      v4 = -110;
      v5 = aSpacrdtsLbx;
LABEL_4:
      v6 = 2;
      v7 = 1;
      goto LABEL_7;
    case 4:
      v4 = -110;
      v5 = aItacrdtsLbx;
      v6 = 2;
      v7 = 1;
LABEL_7:
      *(_DWORD *)v1 = *(_DWORD *)v5;
      v9 = v5 + 4;
      v8 = v1 + 4;
      *(_DWORD *)v8 = *(_DWORD *)v9;
      v9 += 4;
      v8 += 4;
      *(_DWORD *)v8 = *(_DWORD *)v9;
      v8[4] = v9[4];
      break;
    default:
      result = v3;
      v4 = 124;
      v6 = 3;
      v7 = 1;
      strcpy(v1, "CREDITS.LBX");
      break;
  }
  byte_19C09A = v4;
  word_19C094 = v6;
  byte_19C09E = v7;
  return result;
}
// 199CAE: using guessed type char byte_199CAE;
// 19C094: using guessed type int16_t word_19C094;
// 19C09A: using guessed type char byte_19C09A;
// 19C09E: using guessed type char byte_19C09E;


//----- (00081CD3) --------------------------------------------------------
int __fastcall sub_81CD3( unsigned int a1, int a2, unsigned int a3)
{
  int16_t v3; // dx
  int16_t v4; // ax
  int v5; // ecx
  int result; // eax

  v3 = 6 * a1;
  if ( a1 == 6 )
    v4 = sub_79917();
  else
    v4 = a3 + (uint16_t)sub_79917();
  v5 = (int16_t)(v3 + v4);
  result = sub_127C27((int)aBuffer0Lbx_2, v5 + 148, dword_193174);
  dword_19330C[v5] = result;
  return result;
}
// 193174: using guessed type int dword_193174;
// 19330C: using guessed type int dword_19330C[57];


//----- (00081D15) --------------------------------------------------------
int __fastcall sub_81D15(int a1, int a2)
{
  int v2; // eax
  int result; // eax

  word_182155 = sub_11ADB4((int)aEinstein, a2);
  word_182159 = sub_11ADB4((int)aMoola, a2);
  word_18215B = sub_11ADB4((int)aMenlo, a2);
  word_18215D = sub_11ADB4((int)aIseeall, a2);
  v2 = sub_11ADB4((int)aScore, a2);
  word_182163 = v2;
  LOWORD(v2) = word_1B3E0E;
  result = v2 - 1;
  word_19C154 = result;
  return result;
}
// 182155: using guessed type int16_t word_182155;
// 182159: using guessed type int16_t word_182159;
// 18215B: using guessed type int16_t word_18215B;
// 18215D: using guessed type int16_t word_18215D;
// 182163: using guessed type int16_t word_182163;
// 19C154: using guessed type int16_t word_19C154;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (00081D73) --------------------------------------------------------
unsigned int sub_81D73()
{
  int v0; // edx
  int v1; // eax
  unsigned int result; // eax
  int v3; // edx
  int64_t v4; // [esp-Ch] [ebp-10h]
  int16_t v5; // [esp+0h] [ebp-4h] BYREF

  if ( byte_199F0C == 1 )
  {
    sub_89F8A();
    v0 = 0;
    do
    {
      v1 = 14 * (int16_t)v0;
      word_192FEA[v1] = -1000;
      ++v0;
      word_192FEC[v1] = -1000;
    }
    while ( (int16_t)v0 < 5 );
    word_19C176 = (uint16_t)sub_1151B0(244, 428, (int)&unk_179716, (_WORD *)dword_192EF8, asc_179714, 40);
    word_19C178 = (uint16_t)sub_1151B0(244, 455, (int)&unk_179716, (_WORD *)dword_192F00, asc_179717, 40);
    result = sub_11438B(0, 0, 639, 479, &unk_179716, 41);
    word_19C15C = result;
  }
  else
  {
    sub_918D5(2);
    word_19C15C = -1000;
    word_19C17C = (uint16_t)sub_1151B0(249, 5, (int)&unk_179716, (_WORD *)dword_192EEC, aG, 41);
    word_19C162 = (uint16_t)sub_1151B0(544, 441, (int)&unk_179716, (_WORD *)dword_192E7C, aT, 40);
    word_19C176 = (uint16_t)sub_1151B0(244, 428, (int)&unk_179716, (_WORD *)dword_192EF8, asc_179714, 40);
    word_19C178 = (uint16_t)sub_1151B0(244, 455, (int)&unk_179716, (_WORD *)dword_192F00, asc_179717, 40);
    word_19C17E = sub_11A92E(17, 434, 79, 471, (int)&unk_179716, dword_192F10, 0, 425, aC_2, 40);
    word_19C184 = sub_11A92E(91, 434, 154, 471, (int)&unk_179716, dword_1932C8, 0, 425, aP, 40);
    word_19C188 = sub_11A92E(167, 434, 230, 471, (int)&unk_179716, dword_192ED8, 0, 425, asc_179721, 40);
    word_19C182 = sub_11A92E(312, 435, 379, 471, (int)&unk_179716, dword_1932A8, 306, 425, asc_179723, 40);
    word_19C172 = sub_11A92E(386, 435, 453, 471, (int)&unk_179716, dword_192E8C, 306, 425, aR_0, 40);
    word_19C17A = sub_11A92E(462, 435, 526, 471, (int)&unk_179716, dword_192EC4, 306, 425, aI, 40);
    word_19C15A = sub_11438B(545, 49, 613, 119, &unk_179716, 41);
    word_19C158 = sub_11438B(545, 122, 613, 192, &unk_179716, 41);
    word_19C16A = sub_11438B(545, 197, 613, 267, &unk_179716, 41);
    word_19C166 = sub_11438B(545, 270, 613, 340, &unk_179716, 41);
    word_19C168 = sub_11438B(545, 344, 613, 415, &unk_179716, 41);
    sub_90430();
    v3 = 22;
    sub_8FD71(&v5);
    sub_128AB6(22, 22, 527, 421);
    sub_12B634();
    sub_8FD56(v5);
    word_19C16E = word_190208[0];
    if ( byte_19C190 )
    {
      v3 = 470;
      word_19C18C = sub_11438B(630, 470, 639, 479, &unk_179716, 0);
    }
    else
    {
      word_19C18C = -1000;
    }
    sub_128BE7();
    HIDWORD(v4) = &word_1999C2;
    LODWORD(v4) = &word_1999C4;
    word_19C170 = sub_11ADB4((int)aQ, v3);
    result = sub_114DCA(22, 22, 1, 1, 506, 400, v4, 0);
    word_1999C8 = result;
  }
  return result;
}
// 190208: using guessed type int16_t word_190208[72];
// 192E7C: using guessed type int dword_192E7C;
// 192E8C: using guessed type int dword_192E8C;
// 192EC4: using guessed type int dword_192EC4;
// 192ED8: using guessed type int dword_192ED8;
// 192EEC: using guessed type int dword_192EEC;
// 192EF8: using guessed type int dword_192EF8;
// 192F00: using guessed type int dword_192F00;
// 192F10: using guessed type int dword_192F10;
// 192FEA: using guessed type int16_t word_192FEA[];
// 192FEC: using guessed type int16_t word_192FEC[];
// 1932A8: using guessed type int dword_1932A8;
// 1932C8: using guessed type int dword_1932C8;
// 1999C2: using guessed type int16_t word_1999C2;
// 1999C4: using guessed type int16_t word_1999C4;
// 1999C8: using guessed type int16_t word_1999C8;
// 199F0C: using guessed type char byte_199F0C;
// 19C158: using guessed type int16_t word_19C158;
// 19C15A: using guessed type int16_t word_19C15A;
// 19C15C: using guessed type int16_t word_19C15C;
// 19C162: using guessed type int16_t word_19C162;
// 19C166: using guessed type int16_t word_19C166;
// 19C168: using guessed type int16_t word_19C168;
// 19C16A: using guessed type int16_t word_19C16A;
// 19C16E: using guessed type int16_t word_19C16E;
// 19C170: using guessed type int16_t word_19C170;
// 19C172: using guessed type int16_t word_19C172;
// 19C176: using guessed type int16_t word_19C176;
// 19C178: using guessed type int16_t word_19C178;
// 19C17A: using guessed type int16_t word_19C17A;
// 19C17C: using guessed type int16_t word_19C17C;
// 19C17E: using guessed type int16_t word_19C17E;
// 19C182: using guessed type int16_t word_19C182;
// 19C184: using guessed type int16_t word_19C184;
// 19C188: using guessed type int16_t word_19C188;
// 19C18C: using guessed type int16_t word_19C18C;
// 19C190: using guessed type char byte_19C190;


//----- (000821A6) --------------------------------------------------------
unsigned int __fastcall sub_821A6(uint16_t *a1, uint16_t *a2, _WORD *a3, _WORD *a4)
{
  int v4; // kr00_4
  int v5; // kr04_4
  uint16_t v6; // ax
  _WORD *v7; // ecx
  uint16_t v8; // ax
  _WORD *v9; // ecx
  unsigned int result; // eax

  v4 = 506 - *(int16_t *)dword_1975CC;
  v5 = 400 - *(int16_t *)(dword_1975CC + 2);
  v6 = (uint16_t)sub_1151B0(v4 / 2 + 85, v5 / 2 + 111, (int)&unk_179716, (_WORD *)dword_1975D0, aA_1, 40);
  v7 = (_WORD *)dword_1975B4;
  *a1 = v6;
  v8 = (uint16_t)sub_1151B0(v4 / 2 + 209, v5 / 2 + 111, (int)&unk_179716, v7, aI, 40);
  v9 = (_WORD *)dword_1975C0;
  *a2 = v8;
  *a3 = (uint16_t)sub_1151B0(v4 / 2 + 336, v5 / 2 + 111, (int)&unk_179716, v9, &off_17972D, 40);
  sub_11438B(
    v4 / 2 + 21,
    v5 / 2 + 21,
    v4 / 2 + 21 + *(_WORD *)dword_1975CC,
    *(_WORD *)(dword_1975CC + 2) + v5 / 2 + 21,
    &unk_179716,
    0);
  result = sub_11438B(0, 0, 639, 479, (_BYTE *)&off_17972D + 2, 41);
  *a4 = result;
  return result;
}
// 17972D: using guessed type _UNKNOWN *off_17972D;
// 1975B4: using guessed type int dword_1975B4;
// 1975C0: using guessed type int dword_1975C0;
// 1975CC: using guessed type int dword_1975CC;
// 1975D0: using guessed type int dword_1975D0;


//----- (000822AF) --------------------------------------------------------
void sub_822AF()
{
  int16_t i; // si
  int16_t v1; // bx
  int v2; // eax
  int16_t v3; // ax
  int16_t v4; // dx
  int16_t v5; // bx
  int v6; // eax
  _DWORD v7[2]; // [esp+0h] [ebp-10h]
  int16_t v8; // [esp+8h] [ebp-8h] BYREF
  int16_t v9; // [esp+Ch] [ebp-4h] BYREF

  v7[0] = *(_DWORD *)asc_81BFC;
  v7[1] = *(_DWORD *)&asc_81BFC[2];
  for ( i = 0; i < word_19999A; ++i )
  {
    sub_85B93(i, &v9, &v8);
    v1 = sub_79917();
    v2 = dword_19306C + 113 * i;
    if ( *(_BYTE *)(v2 + 22) == 6 )
    {
      v3 = *((_WORD *)v7 + v1);
    }
    else
    {
      v4 = *(uint8_t *)(v2 + 19);
      v3 = word_1931AC[(int16_t)(v4 + sub_79917())];
    }
    v5 = sub_1146FD(v9, v8, v3 / 2 - 2, &unk_179716, 0);
    v6 = i;
    word_190208[v6] = v5;
  }
  JUMPOUT(0x83CFF);
}
// 82343: control flows out of bounds to 83CFF
// 81BFC: using guessed type wchar_t asc_81BFC[3];
// 190208: using guessed type int16_t word_190208[72];
// 19306C: using guessed type int dword_19306C;
// 1931AC: using guessed type int16_t word_1931AC[];
// 19999A: using guessed type int16_t word_19999A;


//----- (00082348) --------------------------------------------------------
_DWORD *sub_82348()
{
  int v0; // eax
  _DWORD *result; // eax

  dword_1933F4 = (int)sub_110CEE(dword_192ED4, 76000);
  sub_111499(dword_192ED4);
  v0 = sub_12DAA4(60, 60);
  result = sub_110D3C(dword_192ED4, v0);
  dword_1932D0 = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 1932D0: using guessed type int dword_1932D0;
// 1933F4: using guessed type int dword_1933F4;


//----- (0008238B) --------------------------------------------------------
int16_t __fastcall sub_8238B( int a1, int a2)
{
  int16_t v4; // cx
  int16_t v5; // dx
  int16_t v6; // ax
  int16_t v7; // ax
  int16_t v8; // ax
  int16_t v9; // ax
  int16_t v10; // ax
  int16_t v11; // ax
  int16_t result; // ax

  v4 = word_19998C;
  v5 = word_199990;
  sub_7927F();
  word_19998C = a1 - v6;
  sub_7927F();
  word_199990 = a2 - v7;
  if ( word_19998C < 0 )
    word_19998C = 0;
  sub_7927F();
  if ( word_19998C > word_199A0C - v8 )
  {
    sub_7927F();
    word_19998C = word_199A0C - v9;
  }
  if ( word_199990 < 0 )
    word_199990 = 0;
  sub_7927F();
  if ( word_199990 > word_199A0A - v10 )
  {
    sub_7927F();
    word_199990 = word_199A0A - v11;
  }
  result = word_19998C - v4;
  if ( word_19998C != v4 || word_199990 != v5 )
    result = sub_8590A(v4, v5, 1);
  byte_199F28 = 1;
  return result;
}
// 823B1: variable 'v6' is possibly undefined
// 823BF: variable 'v7' is possibly undefined
// 823E3: variable 'v8' is possibly undefined
// 8240F: variable 'v9' is possibly undefined
// 82433: variable 'v10' is possibly undefined
// 8245F: variable 'v11' is possibly undefined
// 19998C: using guessed type int16_t word_19998C;
// 199990: using guessed type int16_t word_199990;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;
// 199F28: using guessed type char byte_199F28;


//----- (0008249C) --------------------------------------------------------
int __usercall sub_8249C(int16_t *a1)
{
  int v1; // ebx
  int v2; // edx
  int16_t v3; // ax
  int v4; // eax
  int v5; // eax

  v1 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_197F98 + 3753 * word_19999C + 41) + 2);
  v2 = (int16_t)sub_923D0();
  v3 = sub_923CA();
  sub_922A2(v3, v2, v1);
  sub_11C2F0();
  v4 = sub_89F8A();
  sub_81D15(v4, v2);
  sub_81D73();
  sub_124D41();
  LOWORD(v5) = sub_84E9D();
  sub_1077D(v5, v2, v1, a1);
  return sub_1191CA((int)sub_84555, 1);
}
// 824F5: variable 'v5' is possibly undefined
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0008250C) --------------------------------------------------------
int __usercall sub_8250C(int16_t *a1)
{
  int16_t v1; // dx
  int v2; // ecx
  int v3; // ebx
  uint16_t v4; // ax

  v1 = sub_FA5CE();
  v2 = 0;
  v3 = 0;
  while ( v1 != -1 )
  {
    if ( (int16_t)v3 > 0 )
      sub_8A6C2();
    v2 = 1;
    sub_8354E(v1, v3, a1);
    if ( v4 < 2u )
    {
      if ( v4 == 1 )
      {
        byte_19C1A2 = 1;
        sub_FA623(v1, a1);
      }
    }
    else if ( v4 <= 2u )
    {
      sub_FA728(v1);
    }
    else if ( v4 == 3 )
    {
      sub_FA774();
    }
    v1 = sub_FA5CE();
    ++v3;
  }
  return v2;
}
// 8253F: variable 'v4' is possibly undefined
// 19C1A2: using guessed type char byte_19C1A2;


//----- (000825A8) --------------------------------------------------------
void __fastcall sub_825A8(int a1, _WORD *a2, int a3, int a4)
{
  int16_t v5; // di
  int v6; // ebx
  int16_t v7; // bx
  char v8; // al
  uint16_t v9; // ax
  char *v10; // edx
  char *v11; // eax
  uint16_t v12; // ax
  char v13[200]; // [esp+0h] [ebp-11Ch] BYREF
  char v14[80]; // [esp+C8h] [ebp-54h] BYREF
  int v15; // [esp+118h] [ebp-4h] BYREF

  v5 = -1;
  if ( (int16_t)a1 != -1110 )
  {
    if ( (int16_t)a1 > -1109 && (int16_t)a1 <= -1101 )
      sub_8A216(-1101 - a1, (char)a2);
    v6 = a1 + 1010;
    switch ( (int16_t)v6 )
    {
      case 0:
        if ( word_1999E4 )
        {
          v12 = 212;
        }
        else
        {
          sub_1160B(9, (int)a2, v6, a4);
          v12 = 211;
        }
        v10 = v13;
        strcpy(v13, sub_7A990(v12));
        goto LABEL_37;
      case 1:
        word_199A08 = 28;
        word_199A10 = 0;
        *a2 = 1;
        return;
      case 4:
        sub_8302C(&word_1999D0, word_19999C, 0);
        if ( word_1999D0 <= -1 || word_1999D0 >= word_19999A )
          return;
        if ( byte_199BE3 )
          v5 = sub_7819E(word_1999D0, word_19999C);
        v11 = (char *)v5;
        if ( v5 <= -1 )
          goto LABEL_26;
        goto LABEL_25;
      case 5:
        sub_8302C(&word_1999D0, word_19999C, 1);
        if ( word_1999D0 <= -1 || word_1999D0 >= word_19999A )
          return;
        if ( byte_199BE3 )
          v5 = sub_7819E(word_1999D0, word_19999C);
        v11 = (char *)v5;
        if ( v5 <= -1 )
        {
LABEL_26:
          word_192FDE[0] = word_1999D0;
          sub_83669(word_1999D0);
        }
        else
        {
LABEL_25:
          sub_8310E(v11, a2);
        }
        break;
      case 6:
        v8 = sub_782ED(word_19999C);
        if ( v8 <= 1 )
        {
          if ( v8 == 1 )
            v9 = 209;
          else
            v9 = 210;
          strcpy(v14, sub_7A990(v9));
          v10 = v14;
LABEL_37:
          sub_7A25F(&byte_199F28, (int)v10, 0);
        }
        else if ( byte_19C19C )
        {
          sub_123E6C((int)&unk_17CF00, 1);
          byte_19C19C = 0;
        }
        else
        {
          sub_123E6C((int)&unk_1821B1, 2);
          byte_19C19C = 1;
        }
        return;
      case 8:
        v7 = 0;
        goto LABEL_7;
      case 9:
        v7 = 1;
LABEL_7:
        sub_82DFF(&word_1999B8, (int16_t *)&v15, v7);
        if ( (int16_t)v15 > -1 && (int16_t)v15 < word_1999F8 )
          sub_831B1((int16_t)v15, 0, v7, (int16_t *)0xFFFFFFFF);
        break;
      default:
        return;
    }
  }
}
// 192FDE: using guessed type int16_t word_192FDE[];
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999D0: using guessed type int16_t word_1999D0;
// 1999E4: using guessed type int16_t word_1999E4;
// 1999F8: using guessed type int16_t word_1999F8;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199BE3: using guessed type char byte_199BE3;
// 199F28: using guessed type char byte_199F28;
// 19C19C: using guessed type char byte_19C19C;


//----- (00082809) --------------------------------------------------------
int16_t __usercall sub_82809(int a1, char *a2)
{
  int16_t v2; // cx
  int v3; // eax
  _BOOL1 v4; // dl
  int v5; // edx
  int16_t i; // bx
  int v7; // edx
  char v8; // bl
  char *v9; // eax
  char *v10; // eax
  int16_t v11; // ax
  int v13; // [esp-4h] [ebp-1E8h]
  char v14[200]; // [esp+0h] [ebp-1E4h] BYREF
  _BYTE v15[200]; // [esp+C8h] [ebp-11Ch] BYREF
  _BYTE v16[80]; // [esp+190h] [ebp-54h] BYREF
  int16_t v17; // [esp+1E0h] [ebp-4h]

  v2 = a1;
  if ( (_WORD)a1 == word_182153 && (LOWORD(a1) = IsMemPoolReady_110B5C(), !(_WORD)a1) || v2 == word_18215D )
  {
    v3 = dword_197F98 + 3753 * word_19999C;
    v4 = *(_BYTE *)(v3 + 2234) == 0;
    *(_BYTE *)(v3 + 2234) = v4;
    if ( v4 )
    {
      strcpy(v14, sub_7A990(0xD5u));
      a2 = v14;
      sub_7A25F(&byte_199F28, (int)v14, 0);
      a1 = 3753 * word_19999C;
      v5 = dword_197F98;
      *(_BYTE *)(dword_197F98 + a1 + 3689) = 1;
      *(_BYTE *)(v5 + a1 + 3703) = 1;
    }
    else
    {
      strcpy(v14, sub_7A990(0xD6u));
      a2 = v14;
      LOWORD(a1) = sub_7A25F(&byte_199F28, (int)v14, 0);
    }
    byte_199F28 = 1;
    for ( i = 0; i < word_19999A; ++i )
    {
      v17 = sub_7A1A8(i, word_19999C);
      a1 = dword_19306C + 113 * i;
      *(_BYTE *)(a1 + 20) = v17;
    }
  }
  if ( v2 == word_182155 )
  {
    sub_85FF2((int)a2);
    a1 = 3753 * word_19999C;
    v7 = dword_197F98;
    v8 = 2;
LABEL_12:
    *(_BYTE *)(v7 + a1 + 3689) = 1;
    *(_BYTE *)(v7 + a1 + 3703) = v8;
    return a1;
  }
  if ( v2 == word_182159 )
  {
    *(_DWORD *)(3753 * word_19999C + dword_197F98 + 50) += 1000;
    v9 = sub_7A990(0xD7u);
    sprintf(v16, v9);
    sub_7A25F(&byte_199F28, (int)v16, 0);
    a1 = 3753 * word_19999C;
    v7 = dword_197F98;
    v8 = 3;
    goto LABEL_12;
  }
  if ( v2 == word_18215B )
  {
    v13 = *(int *)((char *)&off_17E079 + 13 * *(uint8_t *)(dword_197F98 + 3753 * word_19999C + 802));
    v10 = sub_7A990(0xD8u);
    sprintf(v16, v10, v13);
    *(_DWORD *)(dword_197F98 + 3753 * word_19999C + 491) = 9999;
    sub_7A25F(&byte_199F28, (int)v16, 0);
    a1 = 3753 * word_19999C;
    v7 = dword_197F98;
    v8 = 4;
    goto LABEL_12;
  }
  if ( v2 == word_18215F )
  {
    LOWORD(a1) = sub_FEC99((int)a2);
  }
  else if ( v2 == word_182163 )
  {
    v11 = sub_9DB51(word_19999C);
    sprintf(v15, "Current score for %s is %d", (char *)(3753 * word_19999C + dword_197F98 + 1), v11);
    LOWORD(a1) = sub_7A25F(&byte_199F28, (int)v15, 0);
  }
  return a1;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 182153: using guessed type int16_t word_182153;
// 182155: using guessed type int16_t word_182155;
// 182159: using guessed type int16_t word_182159;
// 18215B: using guessed type int16_t word_18215B;
// 18215D: using guessed type int16_t word_18215D;
// 18215F: using guessed type int16_t word_18215F;
// 182163: using guessed type int16_t word_182163;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 199F28: using guessed type char byte_199F28;


//----- (00082AC1) --------------------------------------------------------
void sub_82AC1()
{
  int16_t v0; // bx
  int16_t v1; // ax
  char v2; // cl
  int16_t v3; // dx
  int16_t v4; // si

  v0 = sub_123ABA();
  v1 = sub_123AE7();
  v2 = 0;
  word_199ECD = -1;
  word_199EC9 = -1;
  v3 = v1;
  v4 = v1;
  byte_199ECF = 0;
  if ( sub_918D5(0) )
  {
    if ( v0 > word_192FE4[0]
      && v0 < (int16_t)(word_192FE2[0] + word_192FE4[0])
      && v3 > word_192FE6[0]
      && v3 < (int16_t)(word_192FE0[0] + word_192FE6[0]) )
    {
LABEL_12:
      v2 = 1;
    }
  }
  else if ( sub_918D5(2)
         && v0 > word_19301C
         && v0 < (int16_t)(word_19301A + word_19301C)
         && v3 > word_19301E
         && v3 < (int16_t)(word_193018 + word_19301E) )
  {
    goto LABEL_12;
  }
  if ( v0 > 21 && v0 < 527 && v4 > 21 && v4 < 421 && !v2 )
  {
    sub_897CC();
    sub_896A7(v0, v4);
  }
  JUMPOUT(0x83CFF);
}
// 82BE3: control flows out of bounds to 83CFF
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 193018: using guessed type int16_t word_193018;
// 19301A: using guessed type int16_t word_19301A;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 199EC9: using guessed type int16_t word_199EC9;
// 199ECD: using guessed type int16_t word_199ECD;
// 199ECF: using guessed type char byte_199ECF;


//----- (00082BE8) --------------------------------------------------------
int __fastcall sub_82BE8(int result, int a2, int a3)
{
  int16_t v3; // di
  int16_t i; // cx
  int16_t v5; // ax
  int v6; // ebx
  char v8; // [esp+Ch] [ebp-4h]

  v3 = result;
  v8 = 0;
  word_199ECB = -1;
  word_199EC7 = -1;
  for ( i = 0; i < word_1999F8 && !v8; ++i )
  {
    v5 = sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * word_1906C2[6 * i]));
    result = sub_A0D78(v5, 0);
    if ( v3 >= word_1906C8[6 * i] && v3 <= *(int16_t *)result + word_1906C8[6 * i] && a2 >= word_1906CA[6 * i] )
    {
      v6 = *(int16_t *)(result + 2) + word_1906CA[6 * i];
      result = a2;
      if ( a2 <= v6 )
      {
        v8 = 1;
        byte_199ECF = a3;
        word_199EC7 = i;
        result = sub_147D7(41);
      }
    }
  }
  return result;
}
// 1906C2: using guessed type int16_t word_1906C2[];
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 1975D4: using guessed type int16_t word_1975D4;
// 1999F8: using guessed type int16_t word_1999F8;
// 199EC7: using guessed type int16_t word_199EC7;
// 199ECB: using guessed type int16_t word_199ECB;
// 199ECF: using guessed type char byte_199ECF;


//----- (00082CB7) --------------------------------------------------------
int __fastcall sub_82CB7(int result, int a2, int a3)
{
  int16_t v3; // cx
  int16_t v4; // [esp+8h] [ebp-1Ch]
  _DWORD v5[3]; // [esp+Ch] [ebp-18h]
  int16_t v6; // [esp+18h] [ebp-Ch] BYREF
  int16_t v7; // [esp+1Ch] [ebp-8h] BYREF
  char v8; // [esp+20h] [ebp-4h]

  v4 = result;
  v8 = 0;
  word_199ECB = -1;
  word_199EC7 = -1;
  v3 = 0;
  v5[0] = 12;
  v5[1] = dword_81C04[1];
  v5[2] = dword_81C04[2];
  while ( v3 < word_19999A && !v8 )
  {
    sub_85B93(v3, &v6, &v7);
    sub_79917();
    if ( *(_BYTE *)(dword_19306C + 113 * v3 + 22) != 6 )
      sub_79917();
    result = *(uint8_t *)(113 * v3 + dword_19306C + 19);
    if ( (v6 - v4) * (v6 - v4) + (v7 - a2) * (v7 - a2) <= v5[result] * v5[result] )
    {
      v8 = 1;
      byte_199ECF = a3;
      word_199ECB = v3;
      result = sub_147D7(41);
    }
    ++v3;
  }
  return result;
}
// 81C04: using guessed type int dword_81C04[15];
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 199EC7: using guessed type int16_t word_199EC7;
// 199ECB: using guessed type int16_t word_199ECB;
// 199ECF: using guessed type char byte_199ECF;


//----- (00082D82) --------------------------------------------------------
int sub_82D82()
{
  return memset(&word_199EC7, -1, 9);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 199EC7: using guessed type int16_t word_199EC7;


//----- (00082D9B) --------------------------------------------------------
int sub_82D9B()
{
  int v0; // edx
  int result; // eax
  int v2; // ebx

  v0 = 0;
  do
  {
    result = 113 * (int16_t)v0;
    v2 = dword_19306C;
    *(_BYTE *)(dword_19306C + result + 100) = -1;
    ++v0;
    *(_BYTE *)(v2 + result + 101) = -1;
  }
  while ( (int16_t)v0 < 72 );
  word_19C164 = 0;
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 19C164: using guessed type int16_t word_19C164;


//----- (00082DC8) --------------------------------------------------------
int __fastcall sub_82DC8(_WORD *a1, _WORD *a2)
{
  int result; // eax

  *a1 = sub_7926C(*a1 - word_19998C) + 21;
  result = sub_7926C(*a2 - word_199990) + 21;
  *a2 = result;
  return result;
}
// 19998C: using guessed type int16_t word_19998C;
// 199990: using guessed type int16_t word_199990;


//----- (00082DFF) --------------------------------------------------------
int16_t __fastcall sub_82DFF(int16_t *a1, int16_t *a2, int a3)
{
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // edi
  _BOOL1 v10; // al
  int v11; // edx
  int v12; // eax
  int v13; // edi
  int16_t v14; // ax
  int v15; // edi
  _BOOL1 v16; // al
  int16_t i; // dx
  int16_t v19; // [esp+4h] [ebp-1Ch]
  int16_t v20; // [esp+8h] [ebp-18h]
  int16_t v21; // [esp+Ch] [ebp-14h]
  int16_t v22; // [esp+10h] [ebp-10h]
  char v23; // [esp+14h] [ebp-Ch]
  char v24; // [esp+18h] [ebp-8h]
  _BOOL1 v25; // [esp+1Ch] [ebp-4h]

  if ( word_1999B8 > 0 && word_1999B8 < 500 && sub_918D5(2) )
    LOWORD(v5) = sub_77FE9(word_192248[word_1999B8]);
  else
    LOWORD(v5) = word_19999C;
  v22 = v5;
  v23 = 0;
  v24 = 0;
  v20 = -1;
  v19 = -1;
  v21 = -1;
  if ( word_1999F8 > 0 )
  {
    v5 = *a1;
    if ( v5 != -1 )
    {
      if ( a3 )
        v6 = v5 - 1;
      else
        v6 = v5 + 1;
      while ( 1 )
      {
        v10 = a3 ? (int16_t)v6 > -1 : (int16_t)v6 < word_199A02;
        if ( !v10 || v23 )
          break;
        v19 = word_192248[(int16_t)v6];
        v7 = *(int16_t *)((char *)&word_1975D4 + 5 * v19);
        v8 = 129 * v7;
        v25 = sub_77FF5(v7) == v22;
        v9 = dword_197F9C + v8;
        if ( v25 && *(char *)(v9 + 100) < 3 )
        {
          v23 = 1;
          v20 = v6;
        }
        if ( a3 )
          --v6;
        else
          ++v6;
      }
      if ( !v23 )
      {
        if ( a3 )
          v11 = word_199A02 - 1;
        else
          v11 = 0;
        while ( 1 )
        {
          v16 = a3 ? (int16_t)v11 > *a1 - 1 : (int16_t)v11 < word_199A02;
          if ( !v16 || v23 )
            break;
          v19 = word_192248[(int16_t)v11];
          v12 = *(int16_t *)((char *)&word_1975D4 + 5 * v19);
          v13 = 129 * v12;
          v14 = sub_77FF5(v12);
          v15 = v13 + dword_197F9C;
          if ( v14 == v22 && *(char *)(v15 + 100) < 3 )
          {
            v23 = 1;
            v20 = v11;
          }
          if ( a3 )
            --v11;
          else
            ++v11;
        }
      }
      LOWORD(v5) = v19;
      if ( v19 > -1 )
      {
        for ( i = 0; i < word_1999F8 && !v24; ++i )
        {
          LOWORD(v5) = word_1906C2[6 * i];
          if ( (_WORD)v5 == v19 )
          {
            v24 = 1;
            v21 = i;
          }
        }
      }
    }
  }
  if ( v24 )
  {
    *a2 = v21;
    LOWORD(v5) = v20;
    *a1 = v20;
  }
  else
  {
    *a2 = -1;
    *a1 = -1;
  }
  return v5;
}
// 1906C2: using guessed type int16_t word_1906C2[];
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999F8: using guessed type int16_t word_1999F8;
// 199A02: using guessed type int16_t word_199A02;


//----- (0008302C) --------------------------------------------------------
_BOOL1 __fastcall sub_8302C(int16_t *a1, int a2, int a3)
{
  int v6; // ebx
  _BOOL1 result; // al
  int v8; // ebx
  int v9; // edx
  char v10; // [esp+0h] [ebp-4h]

  v10 = 0;
  if ( !a3 )
  {
    v6 = *a1;
LABEL_3:
    ++v6;
    goto LABEL_9;
  }
  v6 = *a1 - 1;
LABEL_9:
  while ( 1 )
  {
    result = a3 ? (int16_t)v6 > -1 : (int16_t)v6 < word_19999A;
    if ( !result || v10 )
      break;
    if ( sub_79D1C(a2, v6) )
    {
      v10 = 1;
      *a1 = v6;
    }
    if ( !a3 )
      goto LABEL_3;
    --v6;
  }
  if ( !v10 )
  {
    if ( a3 )
      v8 = word_19999A - 1;
    else
      v8 = 0;
    while ( 1 )
    {
      if ( a3 )
      {
        result = (int16_t)v8 > *a1 - 1;
        v9 = result;
      }
      else
      {
        result = (int16_t)v8 < word_19999A;
        v9 = (int16_t)v8 < word_19999A;
      }
      if ( !v9 || v10 )
        break;
      if ( sub_79D1C(a2, v8) )
      {
        v10 = 1;
        *a1 = v8;
      }
      if ( a3 )
        --v8;
      else
        ++v8;
    }
  }
  if ( !v10 )
    *a1 = -1;
  return result;
}
// 19999A: using guessed type int16_t word_19999A;


//----- (0008310E) --------------------------------------------------------
int16_t __fastcall sub_8310E(char *a1, _WORD *a2)
{
  int16_t v2; // bx
  char *v3; // eax
  int64_t v4; // rax
  int v5; // ebx
  int16_t *v7; // [esp-4h] [ebp-54h]
  _BYTE v8[80]; // [esp+0h] [ebp-50h] BYREF

  if ( (int16_t)a1 > -1 )
  {
    a1 = (char *)(361 * (int16_t)a1 + dword_192B18);
    if ( *a1 == word_19999C )
    {
      v2 = *((_WORD *)a1 + 1);
      if ( a1[6] )
      {
        v7 = sub_77B28(v2);
        v3 = sub_7A990(0xD9u);
        v4 = sprintf(v8, v3, v7);
        LOWORD(a1) = sub_7A25F(&byte_199F28, SHIDWORD(v4), 0);
      }
      else
      {
        v5 = 17 * v2;
        word_199A08 = 1;
        word_199A10 = 0;
        LOWORD(a1) = *(uint8_t *)(v5 + dword_1930D4 + 3);
        word_199830 = *(uint8_t *)(v5 + dword_1930D4 + 2);
        word_199832 = (int16_t)a1;
        *a2 = 1;
      }
    }
  }
  return (int16_t)a1;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199F28: using guessed type char byte_199F28;


//----- (000831B1) --------------------------------------------------------
void __usercall sub_831B1(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // esi
  int v5; // edx
  int16_t v6; // ax
  int v7; // edx
  int16_t v8; // ax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int16_t v14; // cx
  int16_t v15; // di
  int v16; // [esp+0h] [ebp-10h] BYREF
  int v17; // [esp+4h] [ebp-Ch] BYREF
  int v18; // [esp+8h] [ebp-8h]
  int16_t v19; // [esp+Ch] [ebp-4h] BYREF

  v16 = a1;
  LOBYTE(a3) = a2;
  v4 = -1;
  v5 = sub_79917();
  sub_A20CD();
  word_199966 = -1;
  word_1999CA = -1;
  word_19995C = -1;
  sub_77BF1();
  sub_702C5();
  v6 = 1 - v5;
  byte_199F00 = 1;
  byte_199F33 = 0;
  v7 = 1 - v5 + 12;
  v8 = v6 + 8;
  if ( (_BYTE)a3 )
  {
    a3 = v8;
    v7 = (int16_t)v7;
    if ( (uint16_t)sub_A0FA8((int16_t *)&v16, (int16_t)v7, v8) )
      byte_199F28 = 1;
  }
  if ( sub_918D5(0) )
  {
    sub_91ABC();
    sub_1172D4();
    sub_124D41();
    LOWORD(v9) = sub_84E9D();
    sub_1077D(v9, v7, a3, a4);
    sub_1172FC();
    word_199A06 = -1;
  }
  else if ( sub_918D5(2) )
  {
    v4 = sub_77FE9(word_192248[word_1999B8]);
  }
  word_193016 = 1;
  word_1999B8 = sub_78ABA(v16);
  if ( word_1999B8 == -1 )
  {
    sub_91A40();
  }
  else
  {
    v10 = (int16_t)v16;
    sub_856F7(2, v16, &word_19301C, &word_19301E);
    if ( byte_199BE0 )
      byte_199F23 = 1;
    v11 = sub_77FE9(word_192248[word_1999B8]);
    v12 = v11;
    if ( (_WORD)v11 != (_WORD)v4 || byte_199F1D != 2 )
    {
      LOBYTE(v10) = (_WORD)v11 != (uint16_t)word_19999C;
      if ( byte_19BFC4 )
      {
        sub_C5B94(0);
        byte_19BFC4 = 0;
        sub_84E9D();
      }
      else
      {
        sub_1172D4();
        sub_91A40();
        sub_88D39(0, v10, v12, a4);
        sub_1172FC();
      }
      word_193016 = 1;
      sub_71B0E(v12, (uint8_t)v10);
    }
    sub_9128C(2);
    word_199A04 = 102;
    v13 = word_1999B8;
    byte_199F1B = 0;
    if ( word_1999B8 > -1 && word_19301C <= 31 && word_19301E <= 31 )
    {
      LOWORD(v4) = word_19301C;
      LOWORD(v13) = word_19301A;
      v14 = word_19301E;
      v18 = v4 + v13;
      v15 = word_193018;
      sub_A0A5C(v16, &v17, &v19);
      if ( sub_8FAF6(v4, v14, v18, v14 + v15, v17, v19, v17 + 10, v17 + 13) )
      {
        word_19301C = 619;
        word_19301E = 421;
      }
    }
  }
  JUMPOUT(0x82ABB);
}
// 832A6: control flows out of bounds to 82ABB
// 83249: variable 'v9' is possibly undefined
// 192248: using guessed type int16_t word_192248[500];
// 193016: using guessed type int16_t word_193016;
// 193018: using guessed type int16_t word_193018;
// 19301A: using guessed type int16_t word_19301A;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 19995C: using guessed type int16_t word_19995C;
// 199966: using guessed type int16_t word_199966;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999CA: using guessed type int16_t word_1999CA;
// 199A04: using guessed type int16_t word_199A04;
// 199A06: using guessed type int16_t word_199A06;
// 199BE0: using guessed type char byte_199BE0;
// 199F00: using guessed type char byte_199F00;
// 199F1B: using guessed type char byte_199F1B;
// 199F1D: using guessed type char byte_199F1D;
// 199F23: using guessed type char byte_199F23;
// 199F28: using guessed type char byte_199F28;
// 199F33: using guessed type char byte_199F33;
// 19BFC4: using guessed type char byte_19BFC4;


//----- (00083411) --------------------------------------------------------
int16_t __fastcall sub_83411(_WORD *a1, int a2, int a3)
{
  char v4; // cl
  int16_t result; // ax
  int v6; // eax

  byte_199F2C = 0;
  byte_199F17 = 0;
  v4 = word_19999C;
  byte_199F33 = 0;
  word_199988 = -1;
  byte_19C19F = 1 << word_19999C;
  if ( byte_199F3A == 1 )
    sub_88F5D();
  if ( byte_199F3A == 1 )
  {
    a3 = dword_197F98;
    word_199A08 = 17;
    *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 45) = 1;
  }
  else
  {
    if ( byte_199F3A == 2 || byte_199F3A == 3 )
      word_199A08 = 37;
    else
      word_199A08 = 12;
    word_199A10 = 39;
  }
  byte_199F1D = 101;
  word_199966 = -1;
  sub_A20CD();
  if ( a2 )
  {
    byte_19C196 = 1;
    LOWORD(v6) = sub_8F855();
    result = sub_1171AB(v6, a2, a3, v4);
    byte_199F2D = result;
    if ( (_BYTE)result )
    {
      byte_19C194 = 0;
      sub_123E6C((int)&unk_17CF00, 1);
      byte_19C198 = 0;
      result = sub_11C2F0();
      word_199A08 = 0;
    }
  }
  else
  {
    byte_19C196 = 0;
    sub_11C2F0();
    result = sub_89F8A();
    if ( !byte_199BDD )
    {
      result = sub_11438B(0, 0, 639, 479, (_BYTE *)&off_17972D + 2, 41);
      word_1999DE = result;
    }
  }
  *a1 = 1;
  return result;
}
// 8350C: variable 'v6' is possibly undefined
// 17972D: using guessed type _UNKNOWN *off_17972D;
// 197F98: using guessed type int dword_197F98;
// 199966: using guessed type int16_t word_199966;
// 199988: using guessed type int16_t word_199988;
// 19999C: using guessed type int16_t word_19999C;
// 1999DE: using guessed type int16_t word_1999DE;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199BDD: using guessed type char byte_199BDD;
// 199F17: using guessed type char byte_199F17;
// 199F1D: using guessed type char byte_199F1D;
// 199F2C: using guessed type char byte_199F2C;
// 199F2D: using guessed type char byte_199F2D;
// 199F33: using guessed type char byte_199F33;
// 199F3A: using guessed type char byte_199F3A;
// 19C194: using guessed type char byte_19C194;
// 19C196: using guessed type char byte_19C196;
// 19C198: using guessed type char byte_19C198;
// 19C19F: using guessed type char byte_19C19F;


//----- (0008354E) --------------------------------------------------------
void __usercall sub_8354E(int a1, int a2, int16_t *a3)
{
  int v4; // eax
  int v5; // ebx
  int v6; // ecx
  int16_t v7; // si
  int v8; // edx
  int v9; // edi
  int v10; // eax
  int16_t v11; // ax
  int v12; // eax
  int16_t v13; // [esp+0h] [ebp-10h] BYREF
  uint16_t v14; // [esp+4h] [ebp-Ch] BYREF
  int16_t v15; // [esp+8h] [ebp-8h] BYREF
  uint16_t v16; // [esp+Ch] [ebp-4h] BYREF

  sub_11C2F0();
  sub_89F8A();
  sub_124D41();
  sub_84E9D();
  sub_124DEC();
  sub_124C08();
  sub_1077D(v4, a1, a2, a3);
  LOBYTE(word_18FF78) = 0;
  word_199830 = a1;
  sub_11C2F0();
  sub_89F8A();
  sub_86111();
  sub_821A6(&v14, &v16, &v13, &v15);
  sub_1191CA((int)sub_853D3, 1);
  v5 = dword_1975CC;
  v6 = (506 - *(int16_t *)dword_1975CC) / 2 + 21;
  v7 = 0;
  v8 = (int16_t)((400 - *(int16_t *)(dword_1975CC + 2)) / 2 + 21);
  v9 = 0;
  sub_6FB73();
  while ( 1 )
  {
    v11 = sub_1171AB(v10, v8, v5, v6);
    if ( v11 == v14 )
    {
      v9 = 1;
      v7 = 1;
      goto LABEL_9;
    }
    if ( v11 == v16 )
    {
      v9 = 2;
    }
    else
    {
      if ( v11 != v13 )
        goto LABEL_9;
      v9 = 3;
    }
    v7 = 1;
LABEL_9:
    if ( v7 )
    {
      sub_1113CC(dword_192ED4, v8);
      sub_6F280();
      word_19994C = 1;
      byte_19C18E = 0;
      JUMPOUT(0x83CFF);
    }
    sub_124D41();
    sub_853D3();
    v10 = sub_1077D(v12, v8, v5, (int16_t *)v9);
  }
}
// 83664: control flows out of bounds to 83CFF
// 83577: variable 'v4' is possibly undefined
// 835F9: variable 'v10' is possibly undefined
// 83639: variable 'v12' is possibly undefined
// 18FF78: using guessed type int16_t word_18FF78;
// 192ED4: using guessed type int dword_192ED4;
// 1975CC: using guessed type int dword_1975CC;
// 199830: using guessed type int16_t word_199830;
// 19994C: using guessed type int16_t word_19994C;
// 19C18E: using guessed type char byte_19C18E;


//----- (00083669) --------------------------------------------------------
void __fastcall sub_83669( int a1)
{
  int v2; // eax
  int v3; // eax
  int16_t v4; // [esp+0h] [ebp-Ch] BYREF
  int16_t v5; // [esp+4h] [ebp-8h] BYREF
  char v6; // [esp+8h] [ebp-4h]

  v6 = 0;
  sub_7229E(0, 0);
  word_192FDE[0] = a1;
  if ( sub_918D5(2) )
  {
    sub_91A40();
    sub_A20CD();
    v6 = 1;
  }
  sub_A3FE6(word_192FDE[0]);
  sub_85B93(a1, &v5, &v4);
  sub_856F7(0, a1, word_192FE4, word_192FE6);
  if ( byte_199BE0 )
  {
    sub_83EFD(v5, v4, word_192FE4[0], word_192FE6[0], word_192FE2[0], word_192FE0[0], 0);
  }
  else if ( v6 )
  {
    sub_11C2F0();
    sub_89F8A();
    sub_1172D4();
    v2 = sub_124D41();
    v3 = sub_84E9D(v2);
    sub_1077D(v3);
    sub_1172FC();
  }
  sub_9128C(0);
}
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 84E9D: using guessed type int __fastcall sub_84E9D(_DWORD);
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 199BE0: using guessed type char byte_199BE0;


//----- (00083741) --------------------------------------------------------
void __fastcall sub_83741( int a1)
{
  int v1; // ebx
  int16_t v2; // dx
  int v3; // eax
  int16_t v4; // si
  int16_t v5; // di
  int v6; // edx
  char v7; // al
  int16_t v8; // cx
  int v9; // eax
  int16_t *v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int16_t v15; // ax
  int16_t *v16; // ebx
  int v17; // eax
  int16_t v18; // di
  int16_t v19; // cx
  int v20; // eax
  int v21; // edi
  int16_t v22; // [esp+0h] [ebp-58h]
  int16_t *v23; // [esp+4h] [ebp-54h]
  int16_t *v24; // [esp+8h] [ebp-50h]
  int v25; // [esp+14h] [ebp-44h]
  int16_t *v26; // [esp+18h] [ebp-40h]
  int v27; // [esp+1Ch] [ebp-3Ch] BYREF
  int v28; // [esp+20h] [ebp-38h] BYREF
  int v29; // [esp+24h] [ebp-34h] BYREF
  int v30; // [esp+28h] [ebp-30h] BYREF
  int v31; // [esp+2Ch] [ebp-2Ch] BYREF
  int v32; // [esp+30h] [ebp-28h]
  int v33; // [esp+34h] [ebp-24h] BYREF
  int v34; // [esp+38h] [ebp-20h]
  int v35; // [esp+3Ch] [ebp-1Ch]
  int v36; // [esp+40h] [ebp-18h]
  int v37; // [esp+44h] [ebp-14h]
  int v38; // [esp+48h] [ebp-10h]
  char v39; // [esp+4Ch] [ebp-Ch]
  char v40; // [esp+50h] [ebp-8h]
  uint8_t v41; // [esp+54h] [ebp-4h]

  v28 = 0;
  v31 = 0;
  v35 = 0;
  v38 = 0;
  v32 = 20;
  v34 = 75;
  v30 = 0;
  v1 = a1;
  v29 = 0;
  if ( !sub_79E32(word_19999C, a1) )
LABEL_30:
    JUMPOUT(0x83CFF);
  v2 = *(uint8_t *)(113 * v1 + dword_19306C + 19);
  v3 = (int16_t)(v2 + sub_79917());
  v41 = 0;
  LOWORD(v3) = word_1931AC[v3];
  v4 = 0;
  v36 = v3;
  v27 = 0;
  v5 = ((uint16_t)sub_79917() != 0) + 2;
  v33 = 0;
  sub_79DEA();
  sub_79D68(word_19999C, v1);
  v25 = 3753 * word_19999C;
  v40 = sub_79CF9(v25 + dword_197F98, 113 * v1 + dword_19306C);
  v6 = 113 * v1 + dword_19306C;
  sub_79D50();
  v39 = v7;
  v8 = 0;
  sub_1112EC(dword_192ED4, v6);
  do
  {
    v9 = sub_12DAA4(18, 18);
    v10 = (int16_t *)sub_110D3C(dword_192ED4, v9);
    (&v23)[v8] = v10;
    v11 = 18;
    ++v8;
    sub_12D8F5(18, 18, (int)v10);
  }
  while ( v8 < 4 );
  if ( v39 )
  {
    v11 = sub_127C27((int)aBuffer0Lbx_2, (int16_t)(v5 + 19), dword_193174);
    dword_190498[v5] = v11;
    sub_12F578((int)(&v23)[v41], v11);
    v12 = dword_190498[v5];
    if ( *(int16_t *)(v12 + 2) > 0 )
      v4 = *(_WORD *)(v12 + 2);
    ++v41;
  }
  if ( v40 )
  {
    v11 = sub_127C27((int)aBuffer0Lbx_2, (int16_t)(v5 + 31), dword_193174);
    dword_1904C8[v5] = v11;
    sub_12F578((int)(&v23)[v41], v11);
    v13 = dword_1904C8[v5];
    if ( v4 < *(int16_t *)(v13 + 2) )
      v4 = *(_WORD *)(v13 + 2);
    ++v41;
  }
  if ( v41 )
  {
    v11 = (int)&v30;
    sub_85B93(v22, &v30, &v29);
    if ( v41 )
    {
      if ( v41 <= 1u )
      {
        sub_131528(v23, (int16_t *)&v27, (int16_t *)&v33, &v31, &v28);
        v14 = (int16_t)v36 / 2 + (int16_t)v29 - v4;
        if ( v39 )
          LOWORD(v14) = v14 + 2;
        v11 = (int16_t)v14;
        v15 = v30 - v31 - 4;
        v16 = v23;
      }
      else if ( v41 <= 2u )
      {
        sub_131528(v23, (int16_t *)&v27, (int16_t *)&v33, &v31, &v28);
        v17 = (int16_t)v36 / 2 + (int16_t)v29 - v4;
        if ( v39 )
          LOWORD(v17) = v17 + 2;
        sub_12A478(v30 - v31 - 4, v17, (int)v23);
        sub_131528(v24, (int16_t *)&v27, (int16_t *)&v33, &v31, &v28);
        v11 = (int16_t)((int16_t)v36 / 2 + v29 - v4);
        v15 = v30 + 4;
        v16 = v24;
      }
      else
      {
        if ( v41 > 4u )
          goto LABEL_29;
        v18 = v32;
        v19 = v34;
        v20 = sub_12DAA4(v34, v32);
        v26 = (int16_t *)sub_110D3C(dword_192ED4, v20);
        v37 = 0;
        sub_12D8F5(v19, v18, (int)v26);
        while ( v41 > (int16_t)v37 )
        {
          v21 = (int16_t)v37;
          sub_12F7E6((int16_t)v35, (int16_t)v38, (&v23)[(int16_t)v37], v26);
          sub_131528((&v23)[v21], (int16_t *)&v27, (int16_t *)&v33, &v31, &v28);
          ++v37;
          v35 += v31 + 1;
        }
        sub_131528(v26, (int16_t *)&v27, (int16_t *)&v33, &v31, &v28);
        v11 = (int16_t)((int16_t)v36 / 2 + v29 - v4);
        v15 = v30 - (int16_t)v31 / 2;
        v16 = v26;
      }
      sub_12A478(v15, v11, (int)v16);
    }
  }
LABEL_29:
  sub_1113CC(dword_192ED4, v11);
  goto LABEL_30;
}
// 83AFD: control flows out of bounds to 83CFF
// 83841: variable 'v7' is possibly undefined
// 83937: variable 'v22' is possibly undefined
// 190498: using guessed type int dword_190498[];
// 1904C8: using guessed type int dword_1904C8[];
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 193174: using guessed type int dword_193174;
// 1931AC: using guessed type int16_t word_1931AC[];
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (00083B02) --------------------------------------------------------
void __fastcall sub_83B02( int a1)
{
  int16_t v2; // dx
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ebx
  int v7; // ebx
  int v8; // edx
  int16_t v9; // ax
  int v10; // ebx
  int v11; // eax
  int v13; // [esp+4h] [ebp-10h]
  int v14; // [esp+8h] [ebp-Ch] BYREF
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h] BYREF

  v13 = 113 * a1;
  v2 = *(uint8_t *)(v13 + dword_19306C + 19);
  v3 = (int16_t)(v2 + sub_79917());
  LOWORD(v3) = word_1931AC[v3];
  v15 = v3;
  v4 = sub_81CD3(
         *(_BYTE *)(v13 + dword_19306C + 22),
         *(uint8_t *)(v13 + dword_19306C + 21),
         *(_BYTE *)(v13 + dword_19306C + 19));
  sub_85B93(a1, &v14, &v16);
  v5 = (int16_t)v15 / 2;
  v14 = (int16_t)v14 - v5;
  v6 = v13 + dword_19306C;
  v16 = (int16_t)v16 - v5;
  if ( *(char *)(v13 + dword_19306C + 100) >= 0 )
  {
    v8 = (char)++*(_BYTE *)(v6 + 100) / 2 % *(int16_t *)(v4 + 6);
    if ( *(_BYTE *)(v6 + 100) >= *(_BYTE *)(v6 + 101) )
    {
      v9 = word_19C164 - 1;
      if ( word_19C164 - 1 <= 0 )
        v9 = 0;
      word_19C164 = v9;
      v10 = 113 * a1;
      v11 = dword_19306C;
      *(_BYTE *)(v10 + dword_19306C + 100) = -1;
      *(_BYTE *)(v10 + v11 + 101) = -1;
    }
    sub_12B753(v4, (int16_t)v8);
    v7 = v4;
  }
  else
  {
    sub_12B726(v4);
    v7 = v4;
  }
  sub_12A478(v14, v16, v7);
  JUMPOUT(0x83CFF);
}
// 83BF4: control flows out of bounds to 83CFF
// 19306C: using guessed type int dword_19306C;
// 1931AC: using guessed type int16_t word_1931AC[];
// 19C164: using guessed type int16_t word_19C164;


//----- (00083BF9) --------------------------------------------------------
void sub_83BF9()
{
  int16_t v0; // di
  int16_t v1; // si
  int v2; // ecx
  int v3; // kr00_4
  int v4; // ebx
  uint8_t v5; // dl
  int v6; // ecx
  _DWORD v7[2]; // [esp+0h] [ebp-1Ch]
  int v8; // [esp+8h] [ebp-14h]
  int v9; // [esp+Ch] [ebp-10h] BYREF
  int v10; // [esp+10h] [ebp-Ch] BYREF
  int16_t v11; // [esp+14h] [ebp-8h] BYREF
  int v12; // [esp+18h] [ebp-4h]

  v7[0] = *(_DWORD *)asc_81C68;
  v7[1] = *(_DWORD *)&asc_81C68[2];
  v12 = sub_79917();
  v0 = 0;
  sub_8FD71(&v11);
  v1 = 0;
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  while ( v1 < word_19999A )
  {
    v2 = 113 * v1;
    if ( *(_BYTE *)(v2 + dword_19306C + 22) == 6 )
    {
      sub_85B93(v1, &v10, &v9);
      v3 = *((int16_t *)v7 + (int16_t)v12);
      v10 = (int16_t)v10 - v3 / 2;
      v9 = (int16_t)v9 - v3 / 2;
      v4 = sub_81CD3(
             *(_BYTE *)(v2 + dword_19306C + 22),
             *(uint8_t *)(v2 + dword_19306C + 21),
             *(_BYTE *)(v2 + dword_19306C + 19));
      v8 = 2 * *(int16_t *)(v4 + 6);
      v5 = ((uint8_t)byte_1992F2[v0] + 1) % v8;
      byte_1992F2[v0] = v5;
      sub_12B753(v4, v5 / 2);
      v6 = v0 + 1;
      sub_12A478(v10, v9, v4);
      if ( v6 > 10 )
        LOWORD(v6) = 10;
      v0 = v6;
    }
    ++v1;
  }
  sub_8FD56(v11);
}
// 81C68: using guessed type wchar_t asc_81C68[3];
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (00083D06) --------------------------------------------------------
char sub_83D06()
{
  int v0; // eax
  int16_t i; // di
  int v2; // ecx
  int v3; // ecx
  int v4; // eax
  int16_t v5; // dx
  int16_t v7; // [esp+0h] [ebp-14h]
  int16_t v8; // [esp+4h] [ebp-10h]
  int16_t v9; // [esp+8h] [ebp-Ch]
  uint8_t v10; // [esp+10h] [ebp-4h]

  LOBYTE(v0) = sub_FA795();
  v9 = 0;
  v10 = v0;
  for ( i = 0; i < word_199998; ++i )
  {
    v0 = (int)v10 >> i;
    if ( (v0 & 1) != 0 )
    {
      v2 = 3753 * i + dword_197F98;
      v8 = *(uint8_t *)(v2 + 38);
      v3 = *(uint8_t *)(v2 + 38);
      v4 = dword_19C128[v3];
      v7 = 506 - *(_WORD *)dword_19C128[0] * v9;
      v5 = *(_WORD *)(v4 + 4);
      sub_12B753(v4, (uint8_t)byte_19C148[v3]);
      sub_12A478(v7, 5, dword_19C128[v8]);
      if ( (uint8_t)++byte_19C148[v8] >= *(int16_t *)(dword_19C128[v8] + 6) )
        byte_19C148[v8] = 0;
      ++v9;
      LOBYTE(v0) = sub_12B753(dword_19C128[v8], v5);
    }
  }
  return v0;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19C128: using guessed type int dword_19C128[8];


//----- (00083DEA) --------------------------------------------------------
void sub_83DEA()
{
  int v0; // eax
  int16_t v1; // cx
  int16_t v2; // ax
  int16_t v3; // ax
  void *v4; // esi
  _BYTE v5[8]; // [esp+0h] [ebp-18h] BYREF
  int16_t v6; // [esp+8h] [ebp-10h] BYREF
  int16_t v7; // [esp+Ch] [ebp-Ch] BYREF
  int v8; // [esp+10h] [ebp-8h] BYREF
  int v9; // [esp+14h] [ebp-4h] BYREF

  v0 = 3 - (int16_t)sub_79917();
  if ( v0 <= 0 )
    LOWORD(v0) = 0;
  v1 = v0;
  sub_7836A(word_1999B8);
  sub_78800(v2);
  sub_A0A5C(v3, &v9, (int16_t *)&v8);
  sub_A1BC9(v1, &byte_192E80[v1], &byte_192ECC[v1]);
  v9 = (int16_t)v9 + (uint8_t)byte_192E80[v1] / 2;
  v8 = (int16_t)v8 + (uint8_t)byte_192ECC[v1] / 2;
  sub_85B93(word_19995C, &v7, &v6);
  if ( byte_1992AD && byte_1992AC )
  {
    v4 = &unk_182135;
  }
  else
  {
    if ( !byte_1992A8 && !byte_1992B5 && (!byte_1992AE || byte_1992AA) )
LABEL_12:
      JUMPOUT(0x83CFF);
    v4 = &unk_18213D;
  }
  qmemcpy(v5, v4, sizeof(v5));
  sub_A11C0(v9, v8, v7, v6, (int)v5, word_19995E);
  goto LABEL_12;
}
// 83EF8: control flows out of bounds to 83CFF
// 83E1D: variable 'v2' is possibly undefined
// 83E26: variable 'v3' is possibly undefined
// 1992A8: using guessed type char byte_1992A8;
// 1992AA: using guessed type char byte_1992AA;
// 1992AC: using guessed type char byte_1992AC;
// 1992AD: using guessed type char byte_1992AD;
// 1992AE: using guessed type char byte_1992AE;
// 1992B5: using guessed type char byte_1992B5;
// 19995C: using guessed type int16_t word_19995C;
// 19995E: using guessed type int16_t word_19995E;
// 1999B8: using guessed type int16_t word_1999B8;


//----- (00083EFD) --------------------------------------------------------
void __fastcall sub_83EFD(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // edi
  int v8; // esi
  int v9; // eax
  int16_t v10; // ax
  int16_t v11; // ax
  char v12; // al
  unsigned int v13; // eax
  int16_t v14; // cx
  int16_t v15; // ax
  int v16; // esi
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // edx
  int v21; // esi
  int v22; // eax
  unsigned int v23; // eax
  int v24; // edx
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int16_t v28; // [esp+0h] [ebp-4Ch]
  _BYTE v30[8]; // [esp+8h] [ebp-44h] BYREF
  int v31; // [esp+10h] [ebp-3Ch]
  int v32; // [esp+14h] [ebp-38h]
  int16_t v33; // [esp+18h] [ebp-34h] BYREF
  int v34; // [esp+1Ch] [ebp-30h]
  int v35; // [esp+20h] [ebp-2Ch]
  int v36; // [esp+24h] [ebp-28h]
  int v37; // [esp+28h] [ebp-24h]
  int16_t v38; // [esp+2Ch] [ebp-20h]
  int v39; // [esp+30h] [ebp-1Ch]
  int v40; // [esp+34h] [ebp-18h]
  int v41; // [esp+38h] [ebp-14h]
  int v42; // [esp+3Ch] [ebp-10h]
  int v43; // [esp+40h] [ebp-Ch]
  unsigned int v44; // [esp+44h] [ebp-8h]
  uint8_t v45; // [esp+48h] [ebp-4h]
  int16_t v46; // [esp+5Ch] [ebp+10h]
  int16_t v47; // [esp+60h] [ebp+14h]

  v28 = a2;
  v7 = a3;
  v8 = a4;
  v9 = sub_12484C();
  v45 = 3;
  word_199988 = -1;
  v32 = v9;
  if ( a7 == 2 )
  {
    sub_7836A(word_1999B8);
    v11 = sub_71465(v10);
    sub_71A37(v11);
    a5 = word_199BB2;
    a6 = word_199BB0;
  }
  sub_8FD71(&v33);
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  if ( word_1845D8 == 1 )
  {
    if ( (int16_t)a3 < SHIWORD(dword_1BBA4A) )
      LOWORD(v7) = HIWORD(dword_1BBA4A);
    if ( (int16_t)a4 < SHIWORD(dword_1BBA4E) )
      LOWORD(v8) = HIWORD(dword_1BBA4E);
    if ( (int16_t)v7 + a5 > (int16_t)dword_1BBA4E )
      a5 = dword_1BBA4E - v7;
    if ( (int16_t)v8 + a6 > (int16_t)dword_1BBA52 )
      a6 = dword_1BBA52 - v8;
  }
  sub_1172D4();
  v46 = a5 - v45;
  v47 = a6 - v45;
  sub_918F4(a7);
  sub_124D41();
  sub_84A95(1);
  v38 = 0;
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_8440E();
  sub_124DEC();
  v12 = 2 * v38 + 14;
  do
  {
    v30[v38++] = v12;
    v12 += 2;
  }
  while ( v38 < 8 );
  v42 = 3;
  v13 = sub_1247A0(8u);
  v36 = v7;
  v37 = v8;
  v14 = 0;
  v44 = v13 - 1;
  if ( (int16_t)v7 <= (int16_t)a1 )
  {
    if ( (int16_t)v8 >= (int16_t)a2 )
    {
      v31 = (int16_t)v7;
      if ( (int16_t)v7 + v46 <= 527 )
        LOWORD(v7) = v7 + v46;
      LOWORD(v7) = v7 - v45;
      goto LABEL_30;
    }
    v31 = (int16_t)v7;
    if ( (int16_t)v7 + v46 <= 527 )
      LOWORD(v7) = v7 + v46;
    if ( (int16_t)v8 + v47 <= 459 )
      LOWORD(v8) = v47 + v8;
    v15 = v45;
    LOWORD(v7) = v7 - v45;
    goto LABEL_29;
  }
  if ( (int16_t)v8 < (int16_t)a2 )
  {
    if ( (int16_t)v8 + v47 <= 421 )
      LOWORD(v8) = v47 + v8;
    v15 = v45;
LABEL_29:
    LOWORD(v8) = v8 - v15;
    goto LABEL_30;
  }
  LOWORD(v7) = v45 + (_WORD)v7;
  LOWORD(v8) = v45 + (_WORD)v8;
LABEL_30:
  v40 = ((int16_t)v8 - (int16_t)a2) / 10;
  v41 = ((int16_t)v7 - (int16_t)a1) / 10;
  v35 = a2;
  v38 = 0;
  v34 = a1;
  do
  {
    if ( (int16_t)v36 <= (int16_t)a1 )
    {
      if ( (int16_t)v37 >= v28 )
      {
        v16 = v38;
        v17 = v38 * v46 / -10;
        goto LABEL_34;
      }
      v18 = v38 * v46 / -10;
      v19 = v38 * v47 / -10;
    }
    else
    {
      if ( (int16_t)v37 >= v28 )
      {
        v16 = v38;
        v17 = v38 * v46 / 10;
LABEL_34:
        v18 = v17;
        v19 = v16 * v47 / 10;
        goto LABEL_39;
      }
      v18 = v38 * v46 / 10;
      v19 = v38 * v47 / -10;
    }
LABEL_39:
    v20 = v19;
    v21 = v18 + v34;
    v22 = v19 + v35;
    if ( (int16_t)(v18 + v34) < 21 )
      v21 = 22;
    if ( (int16_t)v21 > 527 )
      v21 = 526;
    if ( (int16_t)v22 < 21 )
      v22 = 22;
    if ( (int16_t)v22 > 421 )
      v22 = 420;
    v43 = v21 - v18;
    v39 = v22 - v20;
    if ( v38 > 0 )
      sub_124D41();
    sub_136728(v43, v39, v18, v20, v42, v14, v44, (int)v30);
    v23 = sub_1247A0(0xAu);
    v24 = (int)(v14 + v23) % 256;
    sub_1077D((int)(v14 + v23) / 256);
    ++v38;
    v35 += v40;
    v14 = v24;
    v34 += v41;
  }
  while ( v38 < 10 );
  if ( word_1845D8 == 1 )
  {
    HIWORD(v25) = HIWORD(v36);
    if ( (int16_t)v36 < SHIWORD(dword_1BBA4A) )
    {
      LOWORD(v25) = HIWORD(dword_1BBA4A);
      v36 = v25;
    }
    HIWORD(v26) = HIWORD(v37);
    if ( (int16_t)v37 < SHIWORD(dword_1BBA4E) )
    {
      LOWORD(v26) = HIWORD(dword_1BBA4E);
      v37 = v26;
    }
    if ( v46 + (int16_t)v36 > (int16_t)dword_1BBA4E )
      v46 = dword_1BBA4E - v36;
    if ( v47 + (int16_t)v37 > (int16_t)dword_1BBA52 )
      v47 = dword_1BBA52 - v37;
  }
  v27 = sub_136728(v36, v37, v46, v47, v42, v24, v44, (int)v30);
  sub_1077D(v27);
  sub_1172FC();
  byte_199F28 = 1;
  sub_124820(v32);
  sub_8FD56(v33);
}
// 83F32: variable 'v10' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 1845D8: using guessed type int16_t word_1845D8;
// 199988: using guessed type int16_t word_199988;
// 1999B8: using guessed type int16_t word_1999B8;
// 199BB0: using guessed type int16_t word_199BB0;
// 199BB2: using guessed type int16_t word_199BB2;
// 199F28: using guessed type char byte_199F28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00084357) --------------------------------------------------------
int sub_84357()
{
  sub_12B726(dword_192E7C);
  sub_12A478(544, 441, dword_192E7C);
  sub_12B726(dword_192EEC);
  return sub_12A478(249, 5, dword_192EEC);
}
// 192E7C: using guessed type int dword_192E7C;
// 192EEC: using guessed type int dword_192EEC;


//----- (000843B3) --------------------------------------------------------
void sub_843B3()
{
  int16_t v0; // ax
  int16_t v1; // ax
  int v2; // ecx
  int16_t v3; // ax
  int v4; // esi
  int16_t v5; // [esp+0h] [ebp-8h] BYREF
  int16_t v6; // [esp+4h] [ebp-4h] BYREF

  sub_7836A(word_1999B8);
  sub_78800(v0);
  v2 = v1;
  v3 = sub_78879(v1);
  v4 = sub_A0D78(v3, 1);
  sub_A0A5C(v2, &v5, &v6);
  sub_12A478(word_1906C8[6 * v2], word_1906CA[6 * v2], v4);
  JUMPOUT(0x8373B);
}
// 84409: control flows out of bounds to 8373B
// 843C8: variable 'v0' is possibly undefined
// 843CD: variable 'v1' is possibly undefined
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 1999B8: using guessed type int16_t word_1999B8;


//----- (0008440E) --------------------------------------------------------
int sub_8440E()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int16_t i; // dx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // eax

  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_85593();
  sub_FE8BE(v0);
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_85320();
  sub_FE8BE(v1);
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_85550();
  sub_FE8BE(v2);
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  for ( i = 0; i < word_19999A; ++i )
    sub_83741(i);
  sub_FE8BE(v3);
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_88CB7();
  sub_FE8BE(v5);
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_83BF9();
  sub_FE8BE(v6);
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_A070F(1);
  sub_FE8BE(v7);
  sub_128BE7();
  sub_12B65C();
  sub_87BAE();
  result = sub_FE8BE(v8);
  if ( byte_199F3A )
  {
    LOBYTE(v10) = sub_83D06();
    return sub_FE8BE(v10);
  }
  return result;
}
// 84431: variable 'v0' is possibly undefined
// 84456: variable 'v1' is possibly undefined
// 8447B: variable 'v2' is possibly undefined
// 844B1: variable 'v3' is possibly undefined
// 844D6: variable 'v5' is possibly undefined
// 844FB: variable 'v6' is possibly undefined
// 84525: variable 'v7' is possibly undefined
// 84539: variable 'v8' is possibly undefined
// 8454C: variable 'v10' is possibly undefined
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 19999A: using guessed type int16_t word_19999A;
// 199F3A: using guessed type char byte_199F3A;


//----- (00084555) --------------------------------------------------------
void __usercall sub_84555(_DWORD *a1)
{
  int v1; // edx
  char *v2; // eax
  int64_t v3; // rax
  int16_t i; // bx
  char *v5; // eax
  int16_t j; // bx
  int16_t k; // bx
  int16_t v8; // si
  int v9; // ecx
  int v10; // eax
  int v11; // [esp-8h] [ebp-60h]
  int v12; // [esp-4h] [ebp-5Ch]
  _BYTE v13[80]; // [esp+0h] [ebp-58h] BYREF
  int v14; // [esp+50h] [ebp-8h]
  int v15; // [esp+54h] [ebp-4h]
  _DWORD savedregs[6]; // [esp+58h] [ebp+0h] BYREF

  if ( word_199964 <= -1 || word_199964 >= 5 )
  {
    sub_128AB6(22, 22, 527, 421);
    sub_12B634();
    if ( byte_199F28 == 1 || word_19994C )
    {
      sub_84A95(1);
      byte_199F28 = 0;
    }
    else
    {
      sub_85593();
      sub_85320();
      sub_88CB7();
    }
    v1 = 22;
    sub_128AB6(22, 22, 527, 421);
    sub_12B634();
    if ( byte_199BDD )
    {
      v12 = dword_192FD8 % 10;
      v11 = dword_192FD8 / 10;
      v14 = 235670016;
      v15 = dword_81C78[1];
      a1 = savedregs;
      v2 = sub_7A990(0xDAu);
      v3 = sprintf(v13, v2, v11, v12);
      sub_120BB5(1, SHIDWORD(v3));
      v1 = 0;
      sub_1210B7(639, 0, (int)v13);
    }
    sub_83BF9();
    for ( i = 0; i < word_19999A; ++i )
      sub_83741(i);
    sub_A080D();
    if ( word_19995C > -1 && word_1999CA == -1 )
    {
      sub_83DEA();
      v1 = word_19995C;
      if ( *(_BYTE *)(dword_19306C + 113 * word_19995C + 22) != 6 )
      {
        sub_87AF9(word_19995C);
        byte_199F31 += byte_199F30;
        if ( byte_199F31 == 3 || byte_199F31 == -1 )
          byte_199F30 = -byte_199F30;
      }
    }
    if ( word_19C18A != -1 )
    {
      v1 = 113 * word_19C18A;
      if ( *(_BYTE *)(v1 + dword_19306C + 22) != 6 )
      {
        sub_87AF9(word_19C18A);
        byte_199F31 += byte_199F30;
        if ( byte_199F31 == 3 || byte_199F31 == -1 )
          byte_199F30 = -byte_199F30;
      }
    }
    sub_85550();
    sub_A070F(0);
    if ( sub_124075() == 1 && sub_918D5(2) && sub_72651(0) && sub_91B0B() )
    {
      v5 = sub_114177();
      v1 = (int)v5;
      if ( (_WORD)v5 != word_193022 )
      {
        if ( !byte_19C19E )
          byte_19C199 = sub_7252F((int16_t)v5) == 0;
        sub_8A0B7(v1);
      }
      byte_19C19E = 1;
    }
    for ( j = 4; j > -1; --j )
    {
      if ( sub_918D5(word_1992E8[j]) && !word_1992E8[j] && *(_BYTE *)(dword_19306C + 113 * word_192FDE[0] + 22) != 6 )
      {
        sub_87AF9(word_192FDE[0]);
        byte_199F31 += byte_199F30;
        if ( byte_199F31 == 3 || byte_199F31 == -1 )
          byte_199F30 = -byte_199F30;
      }
      v1 = 2 * j;
      if ( sub_918D5(*(int16_t *)((char *)word_1992E8 + v1)) && word_1992E8[j] == 2 )
        sub_843B3();
    }
    if ( word_19C180 > -1 && word_19C180 < word_1999F8 )
      sub_854C0();
    for ( k = 4; k > -1; --k )
    {
      v1 = 2 * k;
      if ( sub_918D5(*(int16_t *)((char *)word_1992E8 + v1)) && word_1992E8[k] != word_199964 )
      {
        v8 = sub_124075();
        if ( v8 )
        {
          v9 = 14 * word_1992E8[k];
          if ( sub_113F8C() == word_192FEA[v9] || word_192FE8[14 * word_1992E8[k]] == 1 )
          {
            v1 = v8;
            sub_91349(word_1992E8[k], v8, (int16_t)a1);
          }
        }
        sub_91099(word_1992E8[k]);
      }
    }
    v10 = word_199960;
    if ( word_199960 > -1 )
    {
      LOWORD(v10) = word_199960;
      if ( word_199960 < word_19999A )
        sub_879BC(v10, v1, k);
    }
    sub_12B65C();
    sub_128BE7();
    sub_87BAE();
    word_19995E = (word_19995E + 1) % 8;
  }
  else
  {
    sub_84DB2((int16_t)a1);
    sub_12B65C();
    sub_128BE7();
  }
  if ( byte_199F3A == 2 || byte_199F3A == 3 )
    sub_83D06();
  if ( byte_199F3A == 2 || byte_199F3A == 3 || byte_199F3A == 1 )
    sub_8520C();
  sub_82AC1();
  if ( word_19994C )
  {
    word_199976 = 1;
    word_19994C = 0;
  }
  byte_199F07 += byte_199F06;
  if ( !byte_199F07 || byte_199F07 == 8 )
    byte_199F06 = -byte_199F06;
  JUMPOUT(0x83CFF);
}
// 849C7: control flows out of bounds to 83CFF
// 81C78: using guessed type int dword_81C78[2];
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192FD8: using guessed type int dword_192FD8;
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FE8: using guessed type int16_t word_192FE8[];
// 192FEA: using guessed type int16_t word_192FEA[];
// 193022: using guessed type int16_t word_193022;
// 19306C: using guessed type int dword_19306C;
// 1992E8: using guessed type int16_t word_1992E8[5];
// 19994C: using guessed type int16_t word_19994C;
// 19995C: using guessed type int16_t word_19995C;
// 19995E: using guessed type int16_t word_19995E;
// 199960: using guessed type int16_t word_199960;
// 199964: using guessed type int16_t word_199964;
// 199976: using guessed type int16_t word_199976;
// 19999A: using guessed type int16_t word_19999A;
// 1999CA: using guessed type int16_t word_1999CA;
// 1999F8: using guessed type int16_t word_1999F8;
// 199BDD: using guessed type char byte_199BDD;
// 199F06: using guessed type char byte_199F06;
// 199F07: using guessed type char byte_199F07;
// 199F28: using guessed type char byte_199F28;
// 199F30: using guessed type char byte_199F30;
// 199F31: using guessed type char byte_199F31;
// 199F3A: using guessed type char byte_199F3A;
// 19C180: using guessed type int16_t word_19C180;
// 19C18A: using guessed type int16_t word_19C18A;
// 19C199: using guessed type char byte_19C199;
// 19C19E: using guessed type char byte_19C19E;


//----- (000849CC) --------------------------------------------------------
void __usercall sub_849CC( int a1)
{
  int16_t i; // cx
  int16_t v2; // ax

  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_8440E();
  sub_124DEC();
  for ( i = 4; i > -1; --i )
  {
    if ( sub_918D5(word_1992E8[i]) && word_1992E8[i] != word_199964 )
    {
      v2 = sub_124075();
      sub_91349(word_1992E8[i], v2, a1);
      sub_91099(word_1992E8[i]);
    }
  }
  sub_12B726(dword_192E7C);
  sub_12A478(544, 441, dword_192E7C);
  sub_12B726(dword_192EEC);
  sub_12A478(249, 5, dword_192EEC);
  sub_91099(word_199964);
}
// 192E7C: using guessed type int dword_192E7C;
// 192EEC: using guessed type int dword_192EEC;
// 1992E8: using guessed type int16_t word_1992E8[5];
// 199964: using guessed type int16_t word_199964;


//----- (00084A95) --------------------------------------------------------
void __fastcall sub_84A95( int a1)
{
  sub_128BE7();
  sub_12B65C();
  sub_128C32(0, 0, 639, 479, 0);
  sub_128AB6(0, 0, 639, 479);
  sub_12B634();
  sub_8500F();
  dword_192EE4 = sub_127C27((int)aBuffer0Lbx_2, 0, dword_193174);
  sub_12A478(0, 0, dword_192EE4);
  sub_85593();
  sub_85320();
  if ( byte_199F3A == 2 || byte_199F3A == 3 )
  {
    dword_1975BC = sub_127C27((int)aBuffer0Lbx_2, 13, dword_193174);
    sub_12A478(415, 0, dword_1975BC);
  }
  if ( byte_199F3A == 2 || byte_199F3A == 3 || byte_199F3A == 1 )
  {
    dword_1975C8 = sub_127C27((int)aBuffer0Lbx_2, 13, dword_193174);
    sub_12A478(74, 0, dword_1975C8);
  }
  sub_12B65C();
  sub_128BE7();
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_84F8F();
  sub_12B65C();
  sub_128BE7();
  if ( a1 == 1 )
    sub_124DEC();
  sub_88CB7();
  sub_87BAE();
}
// 192EE4: using guessed type int dword_192EE4;
// 193174: using guessed type int dword_193174;
// 1975BC: using guessed type int dword_1975BC;
// 1975C8: using guessed type int dword_1975C8;
// 199F3A: using guessed type char byte_199F3A;


//----- (00084BCE) --------------------------------------------------------
void sub_84BCE()
{
  int v0; // edi
  int16_t i; // ax
  int16_t v2; // dx
  int16_t v3; // ax
  int v4; // ebx
  int v5; // esi
  _BYTE v6[8]; // [esp+0h] [ebp-Ch] BYREF
  int v7; // [esp+8h] [ebp-4h]

  v0 = sub_12484C();
  for ( i = 0; i < 8; ++i )
  {
    if ( i >= 2 && i <= 5 )
    {
      if ( i == 2 || i == 5 )
        v6[i] = 16;
      else
        v6[i] = 19;
    }
    else
    {
      v6[i] = 12;
    }
  }
  if ( sub_123ABA() <= 22 )
    v2 = 22;
  else
    v2 = sub_123ABA();
  word_19C15E = v2;
  if ( sub_123AE7() <= 22 )
    v3 = 22;
  else
    v3 = sub_123AE7();
  word_19C160 = v3;
  v4 = 506 * (int16_t)sub_790A4(word_19999E) / word_199992;
  v7 = v4;
  v5 = 400 * (int16_t)sub_790A4(word_19999E) / word_199992;
  if ( (int16_t)v4 + word_19C15E >= 536 )
    word_19C15E = 526 - v4;
  if ( word_19C160 + (int16_t)v5 >= 420 )
    word_19C160 = 420 - v5;
  sub_128AB6(word_19C15E, word_19C160, v7 + word_19C15E, (int16_t)(v5 + word_19C160));
  sub_12B634();
  sub_12A478(22, 22, dword_19C150);
  sub_7A5F7(
    word_19C15E,
    word_19C160,
    v7 + word_19C15E,
    (int16_t)(word_19C160 + v5),
    (int)v6,
    (uint8_t)byte_19C192);
  if ( !((uint8_t)++byte_19C193 % 3) )
    byte_19C192 += byte_19C197;
  if ( !((uint8_t)byte_19C193 % 12) )
  {
    byte_19C193 = 0;
    byte_19C197 = -1;
  }
  sub_12B65C();
  sub_128BE7();
  sub_124820(v0);
  JUMPOUT(0x83CFF);
}
// 84DAD: control flows out of bounds to 83CFF
// 199992: using guessed type int16_t word_199992;
// 19999E: using guessed type int16_t word_19999E;
// 19C150: using guessed type int dword_19C150;
// 19C15E: using guessed type int16_t word_19C15E;
// 19C160: using guessed type int16_t word_19C160;
// 19C192: using guessed type char byte_19C192;
// 19C193: using guessed type char byte_19C193;
// 19C197: using guessed type char byte_19C197;


//----- (00084DB2) --------------------------------------------------------
void __usercall sub_84DB2( int a1)
{
  int16_t i; // bx
  int16_t v2; // ax
  int16_t v3; // ax
  int v4; // eax

  if ( word_199956 == 1 )
  {
    sub_849CC(a1);
    word_199956 = 0;
  }
  else
  {
    sub_128AB6(22, 22, 527, 421);
    sub_12B634();
    for ( i = 4; i > -1; --i )
    {
      if ( sub_918D5(word_1992E8[i]) )
      {
        v2 = word_1992E8[i];
        if ( v2 != word_199964 )
          sub_91099(v2);
      }
    }
    if ( word_199964 > -1 && word_199964 < 5 )
    {
      v3 = sub_124075();
      sub_91349(word_199964, v3, a1);
    }
    if ( word_199964 > -1 && word_199964 < 5 )
      sub_91099(word_199964);
    sub_12B65C();
    sub_128BE7();
    sub_87BAE();
    if ( word_199964 == -2 )
    {
      v4 = sub_124D41();
      sub_84555(v4);
      word_199964 = -1;
    }
  }
}
// 84555: using guessed type int __fastcall sub_84555(_DWORD);
// 1992E8: using guessed type int16_t word_1992E8[5];
// 199956: using guessed type int16_t word_199956;
// 199964: using guessed type int16_t word_199964;


//----- (00084E9D) --------------------------------------------------------
int16_t sub_84E9D()
{
  int16_t v0; // dx
  int16_t v1; // cx
  int16_t v2; // bx
  int16_t v3; // si
  int v4; // eax

  if ( byte_199F39 )
  {
    byte_199F39 = 0;
    sub_8A6C2();
  }
  v0 = word_199992;
  v1 = word_19999E;
  v2 = word_19998C;
  v3 = word_199990;
  if ( byte_199F37 )
  {
    sub_84A95(0);
    byte_199F37 = 0;
  }
  else
  {
    sub_84A95(1);
  }
  sub_8440E();
  word_199992 = v0;
  word_19998C = v2;
  v4 = (word_19995E + 1) / 8;
  word_19999E = v1;
  word_199990 = v3;
  word_19995E = (word_19995E + 1) % 8;
  if ( !byte_199BDD )
  {
    if ( byte_19C194 )
    {
      LOWORD(v4) = sub_124075();
      if ( (_WORD)v4 )
        byte_199F2D = 1;
    }
  }
  if ( byte_19C194 )
    LOWORD(v4) = sub_12A478(544, 441, dword_1933F0);
  if ( word_19994C )
  {
    word_199976 = 1;
    word_19994C = 0;
  }
  return v4;
}
// 1933F0: using guessed type int dword_1933F0;
// 19994C: using guessed type int16_t word_19994C;
// 19995E: using guessed type int16_t word_19995E;
// 199976: using guessed type int16_t word_199976;
// 19998C: using guessed type int16_t word_19998C;
// 199990: using guessed type int16_t word_199990;
// 199992: using guessed type int16_t word_199992;
// 19999E: using guessed type int16_t word_19999E;
// 199BDD: using guessed type char byte_199BDD;
// 199F2D: using guessed type char byte_199F2D;
// 199F37: using guessed type char byte_199F37;
// 199F39: using guessed type char byte_199F39;
// 19C194: using guessed type char byte_19C194;


//----- (00084F8F) --------------------------------------------------------
void sub_84F8F()
{
  int16_t i; // cx
  int16_t v1; // dx
  int v2; // ebx
  int16_t v3; // ax
  int v4; // ebx
  int v5; // [esp+0h] [ebp-4h]

  for ( i = 0; i < (uint8_t)byte_199F0D; ++i )
  {
    v1 = sub_79917();
    v2 = 5 * i;
    v5 = sub_7926C(*(_WORD *)(v2 + dword_193068) - word_19998C) + 21;
    v3 = sub_7926C(*(_WORD *)(v2 + dword_193068 + 2) - word_199990);
    v4 = dword_190298[4 * i + v1];
    sub_12A478(v5, v3 + 21, v4);
  }
  JUMPOUT(0x83CFF);
}
// 8500A: control flows out of bounds to 83CFF
// 190298: using guessed type int dword_190298[];
// 193068: using guessed type int dword_193068;
// 19998C: using guessed type int16_t word_19998C;
// 199990: using guessed type int16_t word_199990;
// 199F0D: using guessed type char byte_199F0D;


//----- (0008500F) --------------------------------------------------------
void sub_8500F()
{
  int16_t v0; // [esp+0h] [ebp-4h] BYREF

  sub_8FD71(&v0);
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  dword_192E84 = sub_127C27((int)aStarbgLbx, 0, dword_193174);
  sub_12A478(word_199980, word_19997E, dword_192E84);
  sub_12A478(word_199980 - 640, word_19997E, dword_192E84);
  sub_12A478(word_199980 - 640, word_19997E - 480, dword_192E84);
  sub_12A478(word_199980, word_19997E - 480, dword_192E84);
  dword_192E90 = sub_127C27((int)aStarbgLbx, 1, dword_193174);
  sub_12A478(word_19998A, word_19998E, dword_192E90);
  sub_12A478(word_19998A - 640, word_19998E, dword_192E90);
  sub_12A478(word_19998A - 640, word_19998E - 480, dword_192E90);
  sub_12A478(word_19998A, word_19998E - 480, dword_192E90);
  dword_192E88 = sub_127C27((int)aStarbgLbx, 2, dword_193174);
  sub_12A478(word_199984, word_199986, dword_192E88);
  sub_12A478(word_199984 - 640, word_199986, dword_192E88);
  sub_12A478(word_199984 - 640, word_199986 - 480, dword_192E88);
  sub_12A478(word_199984, word_199986 - 480, dword_192E88);
  sub_8FD56(v0);
}
// 192E84: using guessed type int dword_192E84;
// 192E88: using guessed type int dword_192E88;
// 192E90: using guessed type int dword_192E90;
// 193174: using guessed type int dword_193174;
// 19997E: using guessed type int16_t word_19997E;
// 199980: using guessed type int16_t word_199980;
// 199984: using guessed type int16_t word_199984;
// 199986: using guessed type int16_t word_199986;
// 19998A: using guessed type int16_t word_19998A;
// 19998E: using guessed type int16_t word_19998E;


//----- (0008520C) --------------------------------------------------------
void sub_8520C()
{
  int16_t v0; // di
  int16_t v1; // dx
  int16_t i; // cx
  int16_t v3; // si
  int16_t j; // cx
  int16_t v5; // bx
  int16_t v6; // [esp+0h] [ebp-8h]
  char v7; // [esp+4h] [ebp-4h]

  v7 = 0;
  v0 = sub_7A54F();
  v1 = 0;
  for ( i = 0; ; ++i )
  {
    if ( i >= word_199998 )
    {
      if ( v1 >= v0 - 1 )
        v7 = 1;
      v3 = 0;
      for ( j = 0; j < word_199998; ++j )
      {
        if ( (byte_199F3A == 2 || byte_199F3A == 3) && byte_1AAF7E[j]
          || byte_199F3A == 1 && (uint16_t)sub_F3E09(j) == 1 )
        {
          v5 = *(uint8_t *)(dword_197F98 + 3753 * j + 38);
          v6 = v3 * *(_WORD *)dword_19C128[0] + 73;
          if ( !v7 )
            sub_12B753(dword_19C128[*(uint8_t *)(dword_197F98 + 3753 * j + 38)], 5);
          ++v3;
          sub_12A478(v6, 5, dword_19C128[v5]);
        }
      }
      JUMPOUT(0x83CFF);
    }
    if ( byte_199F3A )
    {
      if ( (uint8_t)byte_199F3A <= 1u )
      {
        if ( (uint16_t)sub_F3E09(i) != 1 )
          continue;
LABEL_8:
        ++v1;
        continue;
      }
      if ( (uint8_t)byte_199F3A <= 3u && byte_1AAF7E[i] )
        goto LABEL_8;
    }
  }
}
// 8531B: control flows out of bounds to 83CFF
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199F3A: using guessed type char byte_199F3A;
// 19C128: using guessed type int dword_19C128[8];


//----- (00085320) --------------------------------------------------------
void sub_85320()
{
  int16_t i; // si
  int16_t v1; // ax
  _BYTE v2[8]; // [esp+0h] [ebp-1Ch] BYREF
  int16_t v3; // [esp+8h] [ebp-14h] BYREF
  int16_t v4; // [esp+Ch] [ebp-10h] BYREF
  int16_t v5; // [esp+10h] [ebp-Ch] BYREF
  int16_t v6; // [esp+14h] [ebp-8h] BYREF
  int16_t v7; // [esp+18h] [ebp-4h] BYREF

  qmemcpy(v2, "noppnopp", sizeof(v2));
  sub_8FD71(&v6);
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  if ( byte_199BE4 )
  {
    for ( i = 0; i < word_19999A; ++i )
    {
      if ( sub_78C94(i, word_19999C) )
      {
        sub_85B93(i, &v3, &v4);
        v1 = sub_784F0(i, word_19999C);
        sub_85B93(v1, &v7, &v5);
        sub_A11C0(v3, v4, v7, v5, (int)v2, word_19995E);
      }
    }
  }
  JUMPOUT(0x83CF6);
}
// 853CE: control flows out of bounds to 83CF6
// 19995E: using guessed type int16_t word_19995E;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 199BE4: using guessed type char byte_199BE4;


//----- (000853D3) --------------------------------------------------------
void sub_853D3()
{
  int v0; // kr04_4
  int v1; // eax
  int v2; // esi
  int v3; // ecx
  int v4; // esi
  char *v5; // eax
  char v6[8]; // [esp+0h] [ebp-10h] BYREF
  int v7; // [esp+8h] [ebp-8h]
  int v8; // [esp+Ch] [ebp-4h]

  v7 = (506 - *(int16_t *)dword_1975CC) / 2 + 21;
  v0 = 400 - *(int16_t *)(dword_1975CC + 2);
  v1 = v0 / 2 + 21;
  v2 = 3753 * word_199830;
  v3 = *(uint8_t *)(dword_197F98 + v2 + 38);
  LOWORD(v1) = (uint8_t)byte_10010[v3];
  v8 = v1;
  sub_84E9D();
  sub_8440E();
  sub_12A478(v7, v0 / 2 + 21, dword_1975CC);
  sub_8F6F8(4u, (uint8_t)byte_10010[v3], v8 + 3, v6);
  sub_120BB5(4, (int)v6);
  v4 = dword_197F98 + v2;
  v5 = sub_7A990(0xDBu);
  sprintf(&word_18FF78, v5, v4 + 1, v4 + 21);
  sub_1212B3(v7 + 39, v0 / 2 + 81, (int)&word_18FF78);
  JUMPOUT(0x83CFF);
}
// 854BB: control flows out of bounds to 83CFF
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 18FF78: using guessed type int16_t word_18FF78;
// 1975CC: using guessed type int dword_1975CC;
// 197F98: using guessed type int dword_197F98;
// 199830: using guessed type int16_t word_199830;


//----- (000854C0) --------------------------------------------------------
int sub_854C0()
{
  int16_t v0; // ax
  int v1; // ecx
  int v2; // edx
  int v3; // eax
  int v5; // [esp+0h] [ebp-8h] BYREF
  int v6; // [esp+4h] [ebp-4h] BYREF

  v0 = sub_78879(word_19C180);
  v1 = sub_A0D78(v0, 1);
  sub_A0A5C(word_19C180, &v5, (int16_t *)&v6);
  v2 = 6 * word_19C180;
  LOWORD(v3) = word_1906C8[v2];
  v5 = v3;
  LOWORD(v3) = word_1906CA[v2];
  v6 = v3;
  return sub_12A478(v5, v3, v1);
}
// 85530: variable 'v3' is possibly undefined
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 197F98: using guessed type int dword_197F98;
// 19C180: using guessed type int16_t word_19C180;


//----- (00085550) --------------------------------------------------------
void sub_85550()
{
  int16_t i; // bx

  word_19C164 = 0;
  for ( i = 0; i < word_19999A; ++i )
  {
    if ( *(_BYTE *)(dword_19306C + 113 * i + 22) != 6 && sub_8A188(i) )
      sub_83B02(i);
  }
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 19C164: using guessed type int16_t word_19C164;


//----- (00085593) --------------------------------------------------------
void sub_85593()
{
  int16_t v0; // si
  int16_t v1; // di
  int16_t v2; // [esp+0h] [ebp-14h] BYREF
  int16_t v3; // [esp+4h] [ebp-10h] BYREF
  int16_t v4; // [esp+8h] [ebp-Ch] BYREF
  int16_t v5; // [esp+Ch] [ebp-8h] BYREF
  int16_t v6; // [esp+10h] [ebp-4h] BYREF

  sub_8FD71(&v6);
  v0 = 0;
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  while ( v0 < word_19999A )
  {
    if ( *(char *)(113 * v0 + dword_19306C + 41) != -1 && (sub_79E32(word_19999C, v0) || sub_79E06(word_19999C)) )
    {
      v1 = *(char *)(dword_19306C + 113 * v0 + 41);
      sub_85B93(v0, &v4, &v3);
      sub_85B93(v1, &v5, &v2);
      sub_134D2D(v4, v3, v5, v2, 4);
    }
    ++v0;
  }
  JUMPOUT(0x83CFA);
}
// 85651: control flows out of bounds to 83CFA
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;


//----- (00085656) --------------------------------------------------------
char __fastcall sub_85656( int a1, int a2, int a3)
{
  sub_11C358(a1, a2, a3);
  sub_11C358(a1 - 1, a2 - 1, a3);
  sub_11C358(a1, a2 - 1, a3);
  sub_11C358(a1 + 1, a2 - 1, a3);
  sub_11C358(a1 + 1, a2, a3);
  sub_11C358(a1 + 1, a2 + 1, a3);
  sub_11C358(a1, a2 + 1, a3);
  sub_11C358(a1 - 1, a2 + 1, a3);
  return sub_11C358(a1 - 1, a2, a3);
}


//----- (000856F7) --------------------------------------------------------
_WORD *__fastcall sub_856F7(int a1, int a2, _WORD *a3, _WORD *a4)
{
  int16_t v4; // si
  int v5; // edx
  int v6; // eax
  int v8; // [esp+0h] [ebp-8h] BYREF
  int v9; // [esp+4h] [ebp-4h] BYREF

  v4 = a1;
  if ( (_WORD)a1 == 2 )
  {
    v5 = 6 * a2;
    LOWORD(a1) = word_1906C8[v5];
    v6 = a1 - 21;
    v9 = v6;
    LOWORD(v6) = word_1906CA[v5];
    v8 = v6 - 21;
  }
  else
  {
    sub_85B93(a2, &v9, &v8);
  }
  return sub_8574E(v4, v9, v8, a3, a4);
}
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];


//----- (0008574E) --------------------------------------------------------
_WORD *__fastcall sub_8574E( int a1, int a2, int a3, _WORD *a4, _WORD *a5)
{
  _WORD *result; // eax
  int v7; // edx

  result = a5;
  if ( a2 < 253 && a3 < 200 )
  {
    v7 = 14 * a1;
    *a4 = 527 - word_192FE2[v7];
    if ( !a1 )
    {
LABEL_4:
      *a5 = 421 - word_192FE0[v7];
      return result;
    }
LABEL_5:
    *a5 = 421;
    return result;
  }
  if ( a2 >= 253 || a3 <= 200 )
  {
    if ( a2 > 253 && a3 < 200 )
    {
      *a4 = 22;
      if ( !a1 )
      {
        v7 = 0;
        goto LABEL_4;
      }
      goto LABEL_5;
    }
    *a4 = 22;
  }
  else
  {
    *a4 = 527 - word_192FE2[14 * a1];
  }
  *a5 = 22;
  return result;
}
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];


//----- (000857F8) --------------------------------------------------------
int __fastcall sub_857F8( int a1, int16_t *a2, int16_t *a3)
{
  int v4; // ecx
  _BOOL2 v5; // ax
  bool v6; // edx
  int16_t v7; // ax
  int16_t v9; // ax

  v4 = -1;
  v5 = sub_918D5(2);
  *a2 = -1;
  *a3 = -1;
  if ( !v5 )
  {
    if ( word_199EC7 > -1 && a1 == 1 )
      goto LABEL_8;
    if ( word_199ECB > -1 && !a1 )
      goto LABEL_4;
    if ( word_199EC9 <= -1 || a1 != 1 )
    {
      if ( word_199ECD <= -1 || a1 )
        return v4;
      v9 = word_199ECD;
      goto LABEL_24;
    }
    goto LABEL_14;
  }
  if ( word_199ECB > -1 && !a1 )
  {
LABEL_4:
    v6 = byte_199ECF != 1;
    v7 = word_199ECB;
LABEL_5:
    *a3 = v7;
    return v6;
  }
  if ( word_199EC7 > -1 && a1 == 1 )
  {
LABEL_8:
    v6 = byte_199ECF != 1;
    v7 = word_199EC7;
    goto LABEL_5;
  }
  if ( word_199ECD <= -1 || a1 )
  {
    if ( word_199EC9 <= -1 || a1 != 1 )
      return v4;
LABEL_14:
    v9 = word_199EC9;
    goto LABEL_24;
  }
  v9 = word_199ECD;
LABEL_24:
  v4 = 4;
  *a2 = v9;
  return v4;
}
// 199EC7: using guessed type int16_t word_199EC7;
// 199EC9: using guessed type int16_t word_199EC9;
// 199ECB: using guessed type int16_t word_199ECB;
// 199ECD: using guessed type int16_t word_199ECD;
// 199ECF: using guessed type char byte_199ECF;


//----- (0008590A) --------------------------------------------------------
int16_t __fastcall sub_8590A( int a1, int a2, int a3)
{
  int v5; // edi
  int v6; // ebx
  int v7; // edi
  int16_t v8; // ax
  int16_t v9; // dx
  int16_t v10; // ax
  int16_t v11; // dx
  int16_t result; // ax

  v5 = a3;
  v6 = (a1 - word_19998C) / a3;
  v7 = (a2 - word_199990) / v5;
  if ( (int16_t)v6 <= 0 )
    v8 = (v6 & 0x8000u) != 0;
  else
    v8 = -1;
  if ( (int16_t)v7 <= 0 )
    v9 = (v7 & 0x8000u) != 0;
  else
    v9 = -1;
  if ( a1 != word_19998C )
  {
    v10 = v6 * v8;
    word_199980 -= v10;
    word_19998A -= 2 * v10;
    word_199984 -= 4 * v10;
  }
  if ( a2 != word_199990 )
  {
    v11 = v7 * v9;
    word_19997E -= v11;
    word_19998E -= 2 * v11;
    word_199986 -= 4 * v11;
  }
  word_199984 += word_199984 < 0 ? 0x280 : 0;
  word_199986 += word_199986 < 0 ? 0x1E0 : 0;
  word_19998A += word_19998A < 0 ? 0x280 : 0;
  word_19998E += word_19998E < 0 ? 0x1E0 : 0;
  word_199980 += word_199980 < 0 ? 0x280 : 0;
  word_19997E += word_19997E < 0 ? 0x1E0 : 0;
  word_199984 %= 640;
  word_199986 %= 480;
  word_19998A %= 640;
  word_19998E %= 480;
  word_199980 %= 640;
  result = word_19997E / 480;
  word_19997E %= 480;
  return result;
}
// 19997E: using guessed type int16_t word_19997E;
// 199980: using guessed type int16_t word_199980;
// 199984: using guessed type int16_t word_199984;
// 199986: using guessed type int16_t word_199986;
// 19998A: using guessed type int16_t word_19998A;
// 19998C: using guessed type int16_t word_19998C;
// 19998E: using guessed type int16_t word_19998E;
// 199990: using guessed type int16_t word_199990;


//----- (00085ABF) --------------------------------------------------------
int __fastcall sub_85ABF( int a1, int a2, _WORD *a3, _WORD *a4)
{
  int16_t v4; // ax
  int16_t v5; // dx
  int result; // eax

  v4 = sub_7926C(a1 - word_19998C);
  v5 = a2 - word_199990;
  *a3 = v4 + 21;
  result = sub_7926C(v5) + 21;
  *a4 = result;
  return result;
}
// 19998C: using guessed type int16_t word_19998C;
// 199990: using guessed type int16_t word_199990;


//----- (00085AEC) --------------------------------------------------------
int sub_85AEC()
{
  int16_t v0; // dx
  int16_t i; // bx
  int16_t v3; // ax

  v0 = 0;
  if ( word_192248[0] <= -1 )
LABEL_7:
    JUMPOUT(0x8558F);
  for ( i = *(char *)(dword_197F9C + 129 * *(int16_t *)((char *)&word_1975D4 + 5 * word_192248[0]) + 99);
        ;
        i = *(char *)(dword_197F9C + 129 * *(int16_t *)((char *)&word_1975D4 + 5 * v3) + 99) )
  {
    if ( i == word_19999C )
      goto LABEL_7;
    if ( v0 >= word_199A02 )
      break;
    v3 = word_192248[v0++];
  }
  return -1;
}
// 85AFD: control flows out of bounds to 8558F
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 199A02: using guessed type int16_t word_199A02;


//----- (00085B71) --------------------------------------------------------
int16_t __fastcall sub_85B71( int a1)
{
  int16_t v1; // dx

  v1 = *(uint8_t *)(113 * a1 + dword_19306C + 19);
  return word_1931AC[(int16_t)(v1 + sub_79917())];
}
// 19306C: using guessed type int dword_19306C;
// 1931AC: using guessed type int16_t word_1931AC[];


//----- (00085B93) --------------------------------------------------------
int __fastcall sub_85B93( int a1, _WORD *a2, _WORD *a3)
{
  int v3; // ecx
  int result; // eax

  v3 = 113 * a1;
  *a2 = sub_7926C(*(_WORD *)(v3 + dword_19306C + 15) - word_19998C) + 21;
  result = sub_7926C(*(_WORD *)(v3 + dword_19306C + 17) - word_199990) + 21;
  *a3 = result;
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 19998C: using guessed type int16_t word_19998C;
// 199990: using guessed type int16_t word_199990;


//----- (00085BDD) --------------------------------------------------------
void sub_85BDD()
{
  int16_t v0; // di
  int16_t v1; // bx
  int v2; // ecx
  int v3; // ebx

  v0 = *(_WORD *)(3753 * word_19999C + dword_197F98 + 41);
  v1 = -1;
  if ( sub_918D5(0) )
    v1 = word_192FDE[0];
  if ( v1 == -1 || !sub_79D1C(word_19999C, v1) )
  {
    v2 = 0;
    LOWORD(v3) = *(uint8_t *)(17 * v0 + dword_1930D4 + 2);
    do
    {
      if ( sub_79D1C(word_19999C, v3) )
        break;
      ++v2;
      v3 = ((int16_t)v3 + 1) % word_19999A;
    }
    while ( (int16_t)v2 < word_19999A );
  }
  JUMPOUT(0x83D00);
}
// 85C85: control flows out of bounds to 83D00
// 192FDE: using guessed type int16_t word_192FDE[];
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;


//----- (00085C8A) --------------------------------------------------------
void __fastcall sub_85C8A(int a1, int a2, _BYTE *a3, char *a4, int16_t **a5)
{
  _BOOL1 v5; // al
  _BOOL1 v6; // dl
  int v7; // eax
  int16_t v8; // cx
  int16_t i; // si
  int v10; // eax
  int16_t v11; // ax
  char v12; // al
  int v13; // edx
  int16_t j; // si
  int v15; // eax
  char *v16; // [esp-4h] [ebp-2Ch]
  int16_t v17; // [esp+0h] [ebp-28h]
  _BYTE v18[8]; // [esp+4h] [ebp-24h] BYREF
  char *v19; // [esp+Ch] [ebp-1Ch]
  char *v20; // [esp+10h] [ebp-18h]
  int v21; // [esp+14h] [ebp-14h]
  int v22; // [esp+18h] [ebp-10h]
  int v23; // [esp+1Ch] [ebp-Ch]
  _BOOL1 v24; // [esp+20h] [ebp-8h]
  char v25; // [esp+24h] [ebp-4h]

  v25 = a2;
  v19 = a4;
  v5 = sub_79E06(word_19999C);
  *a4 = 0;
  v6 = v5;
  *a3 = 0;
  v7 = sub_79917();
  if ( v25 )
  {
    LOWORD(v7) = byte_199F31;
    v21 = v7;
  }
  else
  {
    v21 = 0;
  }
  v24 = sub_7A133(v17);
  v8 = *(char *)(dword_19306C + 113 * v17 + 20);
  if ( v6 || *(char *)(dword_19306C + 113 * v17 + 20) > -1 && v8 < 8 && sub_78F4B(v17) )
  {
    if ( !v6 || v8 == word_19999C || (a2 = v17, sub_79E32(word_19999C, v17)) )
    {
      strcpy(v19, (char *)(113 * v17 + dword_19306C));
    }
    else
    {
      HIWORD(a2) = HIWORD(dword_19306C);
      sprintf(v19, "(%s)", (char *)(dword_19306C + 113 * v17));
    }
    if ( v8 <= -1 || v8 >= 8 )
    {
      LOWORD(a2) = (uint8_t)sub_7A440();
      v23 = a2;
      qmemcpy(v18, sub_8E5C5(a2, 1, 12), sizeof(v18));
      if ( (int16_t)v21 > 0 )
      {
        for ( i = 1; i < 8; ++i )
        {
          v10 = 9 * (int16_t)v21 / 5 + (uint8_t)v18[i];
          v18[i] = v10;
          if ( (uint8_t)v10 < v18[0] )
            v18[i] = v18[0];
          if ( v18[i] > 0x10u )
            v18[i] = 16;
        }
      }
      sub_120BB5((int16_t)v23, (int)v18);
    }
    else
    {
      sub_7A00A(v8, v25, v17);
    }
    if ( v24 )
    {
      sub_8EBFE(1);
      sub_132FCD((int)v19);
    }
    sub_79979(v17);
    if ( v11 > 1 )
    {
      v12 = sub_88B5B(v17, v19, a5);
      *v20 = v12;
    }
  }
  else
  {
    v13 = v17;
    if ( sub_79E32(word_19999C, v17) )
    {
      LOWORD(v13) = (uint8_t)sub_7A440();
      v22 = v13;
      qmemcpy(v18, sub_8E5C5(v13, 1, 12), sizeof(v18));
      if ( (int16_t)v21 > 0 )
      {
        for ( j = 1; j < 8; ++j )
        {
          v15 = 9 * (int16_t)v21 / 5 + (uint8_t)v18[j];
          v18[j] = v15;
          if ( (uint8_t)v15 < v18[0] )
            v18[j] = v18[0];
          if ( v18[j] > 0x10u )
            v18[j] = 16;
        }
      }
      sub_120BB5((int16_t)v22, (int)v18);
      v16 = v19;
      strcpy(v19, (char *)(dword_19306C + 113 * v17));
      if ( v24 )
      {
        sub_8EBFE(2);
        sub_132FCD((int)v16);
      }
    }
  }
  JUMPOUT(0x857F2);
}
// 85E50: control flows out of bounds to 857F2
// 85EA0: conditional instruction was optimized away because %var_14.2>=1
// 85CD3: variable 'v17' is possibly undefined
// 85E38: variable 'v11' is possibly undefined
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 19999C: using guessed type int16_t word_19999C;
// 199F31: using guessed type char byte_199F31;


//----- (00085F2F) --------------------------------------------------------
void sub_85F2F()
{
  int16_t v0; // cx
  int16_t i; // dx
  int v2; // eax
  int v3; // eax
  int16_t v4; // di
  int v5; // eax
  uint64_t v6; // rax
  _WORD v7[72]; // [esp+0h] [ebp-94h] BYREF
  int v8; // [esp+90h] [ebp-4h]

  v0 = 0;
  for ( i = 0; i < word_19999A; ++i )
  {
    if ( word_199992 != word_1999A0 || *(char *)(dword_19306C + 113 * i + 100) >= 0 )
    {
      if ( !sub_8A188(i) )
        continue;
      v2 = 113 * i + dword_19306C;
      if ( *(_BYTE *)(v2 + 22) == 6 || *(char *)(v2 + 100) >= 0 )
        continue;
    }
    v3 = v0++;
    v7[v3] = i;
  }
  if ( v0 > 0 )
  {
    v4 = 1;
    v5 = sub_79F26((int)v7, v0, 1);
    while ( v4 < v0 )
    {
      v8 = v4 + 1;
      v6 = j___clock(v5, 0, v4);
      v5 = v6 / (unsigned int)v8;
      ++v4;
    }
  }
  JUMPOUT(0x83CFF);
}
// 85FED: control flows out of bounds to 83CFF
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 199992: using guessed type int16_t word_199992;
// 19999A: using guessed type int16_t word_19999A;
// 1999A0: using guessed type int16_t word_1999A0;


//----- (00085FF2) --------------------------------------------------------
void __usercall sub_85FF2(int a1)
{
  int16_t v1; // bx
  int16_t v2; // si
  char *v3; // eax
  int64_t v4; // rax
  _BYTE v5[80]; // [esp+0h] [ebp-50h] BYREF

  v1 = 1;
  v2 = 0;
  while ( 1 )
  {
    if ( sub_E412B(3753 * word_19999C + dword_197F98, v1) )
    {
      ++v2;
      sub_E4204(3753 * word_19999C + dword_197F98, v1, a1);
    }
    if ( ++v1 >= 204 )
    {
      v3 = sub_7A990(0xDCu);
      v4 = sprintf(v5, v3, v2);
      sub_7A25F(&byte_199F28, SHIDWORD(v4), 0);
      JUMPOUT(0x8373B);
    }
  }
}
// 86071: control flows out of bounds to 8373B
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199F28: using guessed type char byte_199F28;


//----- (00086076) --------------------------------------------------------
int16_t __fastcall sub_86076( int a1)
{
  int v2; // eax

  v2 = 113 * a1;
  if ( *(_BYTE *)(dword_19306C + v2 + 22) != 6 )
  {
    sub_87AF9(a1);
    byte_199F31 += byte_199F30;
    if ( byte_199F31 == 3 || (LOWORD(v2) = byte_199F31, byte_199F31 == -1) )
    {
      LOWORD(v2) = -byte_199F30;
      byte_199F30 = -byte_199F30;
    }
  }
  return v2;
}
// 19306C: using guessed type int dword_19306C;
// 199F30: using guessed type char byte_199F30;
// 199F31: using guessed type char byte_199F31;


//----- (000860C3) --------------------------------------------------------
_BOOL1 sub_860C3()
{
  return !byte_199F19
      || byte_199F19 == 11
      || byte_199F19 == 30
      || byte_199F19 == 31
      || byte_199F19 == 35
      || byte_199F19 == 28
      || byte_199F19 == 36
      || byte_199F19 == 8
      || byte_199F19 == 39
      || byte_199F19 == 43
      || byte_199F19 == 40
      || byte_199F19 == 12;
}
// 199F19: using guessed type char byte_199F19;


//----- (00086111) --------------------------------------------------------
_DWORD *sub_86111()
{
  _DWORD *result; // eax

  sub_1112EC(dword_192ED4, 15);
  dword_1975CC = (int)sub_126B42((int)aBuffer0Lbx_2, 15, dword_192ED4);
  dword_1975D0 = (int)sub_126B42((int)aBuffer0Lbx_2, 16, dword_192ED4);
  dword_1975B4 = (int)sub_126B42((int)aBuffer0Lbx_2, 17, dword_192ED4);
  result = sub_126B42((int)aBuffer0Lbx_2, 18, dword_192ED4);
  dword_1975C0 = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 1975B4: using guessed type int dword_1975B4;
// 1975C0: using guessed type int dword_1975C0;
// 1975CC: using guessed type int dword_1975CC;
// 1975D0: using guessed type int dword_1975D0;


//----- (00086188) --------------------------------------------------------
void __usercall sub_86188(char *a1)
{
  _BOOL1 v1; // al
  int v2; // eax
  int v3; // edx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int i; // ecx
  int v8; // esi
  void *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // eax
  int16_t v17; // dx
  int16_t v18; // bx
  char v19; // cl
  int16_t v20; // ax
  int16_t v21; // si
  _BOOL1 v22; // cl
  char *v23; // eax
  int16_t v24; // bx
  char *v25; // edx
  int16_t v26; // dx
  uint16_t v27; // ax
  int16_t v28; // si
  int16_t v29; // ax
  int16_t v30; // ax
  int16_t v31; // ax
  char *v32; // eax
  int16_t v33; // si
  int16_t v34; // bx
  int16_t v35; // ax
  int16_t v36; // dx
  int v37; // edx
  char *v38; // eax
  int v39; // eax
  int16_t v40; // ax
  void *v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // edx
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int16_t v48; // bx
  int16_t v49; // si
  int16_t v50; // dx
  int v51; // ecx
  int16_t v52; // ax
  int16_t v53; // ax
  int16_t v54; // ax
  int16_t v55; // ax
  int16_t v56; // ax
  int16_t v57; // ax
  int16_t v58; // ax
  int16_t v59; // ax
  int16_t v60; // ax
  int16_t v61; // ax
  int v62; // eax
  int v63; // eax
  int v64; // [esp-4h] [ebp-64Eh]
  int v65[23]; // [esp+0h] [ebp-64Ah] BYREF
  int64_t v66; // [esp+5Ch] [ebp-5EEh]
  int64_t v67; // [esp+64h] [ebp-5E6h]
  int v68; // [esp+6Ch] [ebp-5DEh]
  char v69[200]; // [esp+3E8h] [ebp-262h] BYREF
  char v70[200]; // [esp+4B0h] [ebp-19Ah] BYREF
  char v71[200]; // [esp+578h] [ebp-D2h] BYREF
  _BYTE v72[80]; // [esp+640h] [ebp-Ah] BYREF
  int16_t v73; // [esp+690h] [ebp+46h] BYREF
  int v74; // [esp+694h] [ebp+4Ah] BYREF
  int16_t v75; // [esp+698h] [ebp+4Eh] BYREF
  char *v76; // [esp+69Ch] [ebp+52h]
  int16_t v77; // [esp+6A0h] [ebp+56h] BYREF
  int v78; // [esp+6A4h] [ebp+5Ah] BYREF
  int16_t v79; // [esp+6A8h] [ebp+5Eh] BYREF
  int v80; // [esp+6ACh] [ebp+62h] BYREF
  int16_t v81; // [esp+6B0h] [ebp+66h] BYREF
  int v82; // [esp+6B4h] [ebp+6Ah]
  int v83; // [esp+6B8h] [ebp+6Eh] BYREF
  int v84; // [esp+6BCh] [ebp+72h]
  int v85; // [esp+6C0h] [ebp+76h]
  int v86; // [esp+6C4h] [ebp+7Ah] BYREF
  _BOOL1 v87; // [esp+6C8h] [ebp+7Eh]

  v1 = sub_860C3();
  byte_19C19A = 0;
  v87 = v1;
  byte_19C19B = 1;
  sub_1191CA((int)sub_84555, 1);
  dword_1933F4 = (int)sub_110CEE(dword_192ED4, 76000);
  sub_111499(dword_192ED4);
  v2 = sub_12DAA4(60, 60);
  dword_1932D0 = (int)sub_110D3C(dword_192ED4, v2);
  sub_A20CD();
  memset(&word_199EC7, -1, 9);
  sub_6F280();
  v3 = 0;
  do
  {
    v4 = 113 * (int16_t)v3;
    v5 = dword_19306C;
    *(_BYTE *)(dword_19306C + v4 + 100) = -1;
    ++v3;
    *(_BYTE *)(v5 + v4 + 101) = -1;
  }
  while ( (int16_t)v3 < 72 );
  word_19C164 = 0;
  word_1999CA = -1;
  word_199960 = -1;
  sub_11946A(20);
  sub_113E92();
  word_199976 = 0;
  byte_19C197 = 1;
  byte_19C19D = -1;
  byte_199F21 = 0;
  word_19C18A = -1;
  if ( byte_199F3A != 1 && sub_918D5(2) )
  {
    if ( !sub_780D3() )
      sub_91A40();
    word_199966 = -1;
  }
  sub_124C08();
  byte_199F28 = 1;
  v82 = 0;
  v74 = 0;
  word_19999E = sub_79917();
  sub_11C2F0();
  v6 = sub_89F8A();
  sub_81D15(v6, v3);
  if ( !v87 && byte_199F19 == 39 && sub_918D5(0) && byte_199F2C )
    byte_19D32C = 1;
  for ( i = 0; (int16_t)i < word_19999A; ++i )
  {
    v8 = (int16_t)i;
    v3 = sub_7A1A8(i, word_19999C);
    v5 = dword_19306C;
    *(_BYTE *)(dword_19306C + 113 * v8 + 20) = v3;
  }
  sub_A0305();
  sub_A07C8();
  if ( byte_19C18F )
  {
    word_199A06 = -1;
  }
  else if ( sub_72617() )
  {
    sub_71B1C();
  }
  if ( byte_19C1A2 || !v87 && (byte_19C1A0 || byte_199F39) )
  {
    sub_8A6C2();
    byte_199EFE = 1;
  }
  else
  {
    if ( sub_918D5(0) )
    {
      word_1999C6 = -1;
      sub_A20CD();
    }
    v5 = 173;
    v3 = 0;
    sub_1205E6(0, 0, 173);
    if ( byte_199F19 == 36 )
    {
      sub_124D41();
      sub_84E9D();
      v9 = sub_124DEC();
      sub_1077D((int)v9, 0, 173, (int16_t *)a1);
      sub_124C08();
    }
    sub_81D73();
  }
  byte_19C19B = 0;
  byte_19C18F = 1;
  if ( !byte_190488[word_19999C] )
  {
    if ( dword_192FD8 == 35000 )
    {
      sub_1196F7();
      sub_8249C((int16_t *)a1);
      sub_6F280();
    }
    byte_190488[word_19999C] = 1;
  }
  byte_19C1A0 = 1;
  byte_199F39 = 0;
  if ( byte_199F3A )
  {
    i = word_19999C;
    if ( (((int)(uint8_t)byte_19C19F >> word_19999C) & 1) != 0 )
    {
      LOBYTE(i) = word_19999C;
      byte_19C19F &= ~(1 << word_19999C);
      sub_8A571();
    }
  }
  while ( 1 )
  {
    if ( (_WORD)v74 || word_199A0E )
    {
      byte_199F1D = 101;
      word_199966 = -1;
      sub_119281();
      word_1999FC = 0;
      if ( byte_19C18F )
        word_199A06 = -1;
      word_19995C = -1;
      word_199964 = -1;
      word_199956 = 0;
      sub_A20CD();
      word_199988 = -1;
      sub_1196F7();
      byte_19C18E = 0;
      byte_199F38 = 0;
      JUMPOUT(0x83D00);
    }
    if ( (byte_199F3A == 2 || byte_199F3A == 3) && (uint16_t)sub_8250C((int16_t *)a1) == 1 )
    {
      v3 = 1;
      sub_1191CA((int)sub_84555, 1);
      sub_11C2F0();
      v10 = sub_89F8A();
      sub_81D15(v10, 1);
      sub_C5BB9();
      sub_81D73();
      if ( sub_918D5(2) )
      {
        byte_19C18E = 0;
        byte_199F38 = 0;
      }
      else if ( sub_918D5(0) )
      {
        sub_A20CD();
      }
      sub_8A6C2();
    }
    byte_19C195 = -1;
    sub_12C2A0();
    v85 = sub_1171AB(v11, v3, v5, i);
    if ( (v85 & 0x8000u) != 0 && byte_19C19C )
      byte_19C19C = 0;
    if ( (v85 & 0x8000u) != 0 && byte_199F0C == 1 )
    {
      byte_199F0C = 0;
      sub_123E6C((int)&unk_17CF00, 1);
      v3 = 1;
      v82 = 0;
      sub_1191CA((int)sub_84555, 1);
      sub_6F280();
    }
    if ( byte_1ACE74 )
    {
      sub_124D41();
      sub_84555(a1);
      v13 = sub_1077D(v12, v3, v5, (int16_t *)a1);
      LOWORD(v13) = word_19C162;
      v85 = v13;
    }
    v14 = dword_197F98;
    if ( *(char *)(dword_197F98 + 3753 * word_19999C + 3698) != -1 )
    {
      sub_124D41();
      sub_84555(a1);
      v16 = sub_1077D(v15, v14, v5, (int16_t *)a1);
      LOWORD(v16) = word_19C162;
      v85 = v16;
    }
    v76 = sub_114177();
    if ( (_WORD)v85 == word_1999C8 || (int16_t)v85 == -word_1999C8 )
    {
      v17 = sub_123ABA();
      v18 = sub_123AE7();
      v19 = ((int16_t)v85 <= 0) + 1;
      if ( sub_918D5(2) )
      {
        a1 = (char *)v17;
        sub_82CB7(v17, v18, v19);
        if ( word_199ECB == -1 )
          sub_82BE8(v17, v18, v19);
      }
      else
      {
        a1 = (char *)v18;
        sub_82BE8(v17, v18, v19);
        if ( word_199EC7 == -1 )
          sub_82CB7(v17, v18, v19);
      }
    }
    else
    {
      word_199EC7 = -1;
      word_199ECB = -1;
    }
    if ( !word_199976 )
    {
      v20 = sub_857F8(0, (int16_t *)&v78, &v73);
      v21 = v20;
      v22 = 0;
      word_19C18A = v78;
      if ( (!v20 || v20 == 4) && sub_918D5(2) )
        v22 = sub_72617();
      if ( !v21 && *(_BYTE *)(dword_19306C + 113 * v73 + 22) != 6 && byte_19C19C )
      {
        byte_19C19C = 0;
        sub_123E6C((int)&unk_17CF00, 1);
        sub_785EC(v73, word_19999C);
        v64 = dword_19306C + 113 * v73;
        v23 = sub_7A990(0xDDu);
        v24 = 0;
        sprintf(v72, v23, v64);
        v25 = v72;
LABEL_74:
        sub_7A25F(&byte_199F28, (int)v25, v24);
        goto LABEL_115;
      }
      if ( v21 || v73 <= -1 || v22 )
      {
        if ( !v22 || v73 <= -1 || v21 || *(_BYTE *)(dword_19306C + 113 * v73 + 22) == 6 )
        {
          if ( v22 && v21 == 4 && sub_918D5(2) )
          {
            word_1999CA = -1;
            if ( *(_BYTE *)(dword_19306C + 113 * (int16_t)v78 + 22) == 6 )
              word_19995C = -1;
            else
              word_19995C = v78;
          }
        }
        else
        {
          sub_7802A((int)v65, 500);
          sub_FF799((int16_t *)v65, v73, &byte_1992A8);
          if ( !byte_1992AD )
          {
            v69[0] = 0;
            if ( byte_1992A8 )
            {
              v27 = 33;
              goto LABEL_97;
            }
            if ( byte_1992A9 )
            {
              v27 = 34;
              goto LABEL_97;
            }
            if ( byte_1992AA )
            {
              v27 = 35;
              goto LABEL_97;
            }
            if ( byte_1992B5 )
            {
              v27 = 36;
LABEL_97:
              strcpy(v69, sub_7A990(v27));
              a1 = v69;
            }
            if ( !v69[0] )
              goto LABEL_115;
            v24 = 3;
            v25 = v69;
            goto LABEL_74;
          }
          v28 = sub_712E1();
          sub_FFD08((int16_t *)v65, v73, &byte_1992A8);
          word_19995C = -1;
          if ( v28 == word_199BB8 )
            byte_199F33 = 1;
          else
            v84 = sub_7109B();
          sub_A0305();
          sub_A07C8();
          if ( v28 == word_199BB8 )
            v29 = 0;
          else
            v29 = v84;
          v30 = sub_78013(v29);
          sub_78B0E(v30);
          word_1999B8 = v31;
          sub_7229E(0, 0);
          sub_77BF1();
          if ( word_1999B8 == -1 )
            sub_91A40();
          byte_199F28 = 1;
          word_199A06 = -1;
        }
      }
      else
      {
        v26 = -1;
        if ( byte_199BE3 && *(_BYTE *)(113 * v73 + dword_19306C + 22) != 6 )
          v26 = sub_7819E(v73, word_19999C);
        if ( v26 == -1 )
          sub_83669(v73);
        else
          sub_8310E((char *)v26, &v74);
      }
    }
LABEL_115:
    if ( sub_918D5(0) && !word_199976 && word_1999C6 > -1 && word_1999C6 < word_19999A && (_WORD)v85 != word_192FEC[0] )
    {
      LOWORD(v32) = sub_123ABA();
      a1 = v32;
      v33 = sub_123AE7();
      v34 = sub_899AB((int16_t)v76, v85, (int)word_1992D4, &v75, &v79, (int16_t *)&v86, &v77, (int16_t *)&v80);
      word_1999DC = v86;
      if ( (int16_t)v80 == -1 && word_1999C0 > 2000 && word_1999C0 < 2004 )
      {
        word_1999C0 = -1;
      }
      else if ( (int16_t)v80 > -1 )
      {
        word_1999C0 = v80;
      }
      if ( (int16_t)a1 < word_192FE4[0]
        || (int16_t)a1 > word_192FE4[0] + word_192FE2[0]
        || v33 < word_192FE6[0]
        || v33 > word_192FE6[0] + word_192FE0[0] )
      {
        word_1999C0 = -1;
      }
      if ( !v34 )
      {
        if ( v77 <= -1 )
        {
          v36 = *(_WORD *)(dword_1930D4 + 17 * sub_79C54(word_192FDE[0], v79));
          if ( v36 > -1 && v36 < word_199996 && *(char *)(361 * v36 + dword_192B18) == word_19999C )
            sub_8310E((char *)v36, &v74);
        }
        else
        {
          sub_78800(v77);
          sub_831B1(v35, 0, 0, (int16_t *)a1);
        }
      }
    }
    v5 = (int16_t)v76;
    v37 = (int16_t)v85;
    i = (int)&v74;
    sub_89183(
      (int)a1,
      v65[0],
      v65[1],
      v65[2],
      v65[3],
      v65[4],
      v65[5],
      v65[6],
      v65[7],
      v65[8],
      v65[9],
      v65[10],
      v65[11],
      v65[12],
      v65[13],
      v65[14],
      v65[15],
      v65[16],
      v65[17],
      v65[18],
      v65[19],
      v65[20],
      v65[21],
      v65[22],
      v66,
      v67,
      v68);
    if ( !word_199976 )
    {
      v5 = (int)&v81;
      v37 = sub_857F8(1, (int16_t *)&v83, &v81);
      word_19C180 = v83;
      if ( (int16_t)v83 != -1 )
        word_19995C = -1;
      if ( !(_WORD)v37 )
      {
        v37 = 1;
        sub_831B1(v81, 1, (int16_t)&v81, (int16_t *)a1);
      }
    }
    if ( !word_199976 )
    {
      i = (int16_t)v85;
      sub_825A8((int16_t)v85, &v74, v5, (int16_t)v85);
      v37 = (int)&v74;
      sub_82809(i, a1);
    }
    if ( (_WORD)v85 == word_19C170 && !word_199976 )
    {
      v38 = sub_7A990(0xDEu);
      sub_126487(v38, v37);
    }
    if ( (_WORD)v85 != word_19C17C || word_199976 )
    {
      if ( word_199976 || byte_199BF1 <= -1 || byte_199BF1 >= 10 || (int16_t)v85 != -1109 )
      {
        if ( !word_199976 && byte_199BF1 > -1 && byte_199BF1 < 10 && (int16_t)v85 == -1110 )
          sub_80715(&v74);
      }
      else if ( (uint8_t)byte_199F3A > 1u )
      {
        v5 = 3;
        v37 = (int)v71;
        strcpy(v71, sub_7A990(0x20u));
        a1 = v71;
        sub_7A25F(&byte_199F28, (int)v71, 3);
      }
      else
      {
        sub_807A6(&v74);
      }
    }
    else
    {
      word_199830 = 0;
      word_199A08 = 8;
      word_199A10 = 0;
      v74 = 1;
    }
    if ( (_WORD)v85 == word_19C188 && !word_199976 )
    {
      if ( sub_918D5(2) || sub_918D5(0) )
      {
        sub_11C2F0();
        sub_124D41();
        LOWORD(v39) = sub_84E9D();
        sub_1077D(v39, v37, v5, (int16_t *)a1);
      }
      word_199A08 = 4;
      word_199A10 = 0;
      v74 = 1;
      byte_19C19D = 4;
    }
    if ( (_WORD)v85 == word_19C17E && !word_199976 )
    {
      word_199A08 = 20;
      word_199A10 = 0;
      v74 = 1;
    }
    if ( (_WORD)v85 == word_19C17A && !word_199976 )
    {
      word_199A08 = 9;
      word_199A10 = 0;
      v74 = 1;
    }
    if ( (_WORD)v85 == word_19C162 && !word_199976 )
    {
      nullsub_14(v85);
      byte_19C198 = 1;
      byte_199F2D = 0;
      v37 = 0;
      word_1999DE = -1000;
      sub_83411(&v74, 0, v5);
    }
    if ( (_WORD)v85 == word_19C172 && !word_199976 )
    {
      word_199A08 = 6;
      word_199A10 = 0;
      v74 = 1;
    }
    if ( (_WORD)v85 == word_19C184 && !word_199976 )
    {
      word_199A08 = 32;
      word_199A10 = 0;
      v74 = 1;
    }
    if ( (_WORD)v85 == word_19C182 && !word_199976 )
    {
      if ( byte_199F1F )
      {
        sub_85BDD();
      }
      else if ( sub_918D5(2) )
      {
        v40 = word_1999B8;
      }
      else
      {
        v40 = sub_85AEC();
      }
      word_199838 = v40;
      byte_19C19D = 0;
      word_199A08 = 29;
      word_199A10 = 0;
      v74 = 1;
    }
    if ( (_WORD)v85 == word_19C168 && !word_199976 )
    {
      byte_199F37 = 1;
      sub_11C2F0();
      sub_89F8A();
      sub_124D41();
      sub_84E9D();
      v41 = sub_124DEC();
      sub_1077D((int)v41, v37, v5, (int16_t *)a1);
      sub_124C08();
      if ( sub_918D5(2) )
        byte_19C1A2 = 1;
      word_199A08 = 36;
      goto LABEL_197;
    }
    if ( (_WORD)v85 == word_19C166 )
    {
      if ( *(int16_t *)(dword_197F98 + 3753 * word_19999C + 54) <= 0 )
      {
        v5 = 3;
        strcpy(v70, sub_7A990(0xDFu));
        a1 = v70;
        sub_7A25F(&byte_199F28, (int)v70, 3);
      }
      else
      {
        word_199A08 = 35;
        word_199A10 = 0;
        v74 = 1;
        byte_19C18F = 0;
      }
      goto LABEL_207;
    }
    if ( (_WORD)v85 == word_19C158 && !word_199976 )
    {
      word_199A08 = 43;
LABEL_197:
      word_199A10 = 0;
      byte_19C18F = 0;
      v74 = 1;
      goto LABEL_207;
    }
    if ( (_WORD)v85 == word_19C15A )
    {
      sub_11C2F0();
      sub_89F8A();
      sub_1191CA((int)sub_84E9D, 1);
      sub_124D41();
      sub_84E9D();
      sub_124DEC();
      sub_124C08();
      v43 = sub_1077D(v42, 1, v5, (int16_t *)a1);
      sub_CC20B(v43, 1, (int *)v5, i);
      v85 = -1;
      sub_E2D72(word_19999C, (int)a1);
      v74 = 1;
      byte_19C18F = 0;
      word_199A08 = 0;
    }
LABEL_207:
    if ( (_WORD)v85 == word_19C178 && word_199992 < word_1999A0 || (_WORD)v85 == word_19C176 && word_199992 > 10 )
    {
      v44 = 0;
      do
      {
        v45 = 113 * (int16_t)v44;
        v5 = dword_19306C;
        *(_BYTE *)(dword_19306C + v45 + 100) = -1;
        ++v44;
        *(_BYTE *)(v5 + v45 + 101) = -1;
      }
      while ( (int16_t)v44 < 72 );
      word_19C164 = 0;
      sub_1196F7();
    }
    if ( (_WORD)v85 != word_19C176 || word_199992 <= 10 || word_199976 )
    {
      if ( (_WORD)v85 == word_19C178 && byte_199F0C == 1 && !word_199976 )
      {
        v47 = sub_796E2();
        if ( !(_WORD)v47 )
        {
          v82 = v47;
          byte_199F0C = 0;
          sub_123E6C((int)&unk_17CF00, 1);
          sub_1191CA((int)sub_84555, 1);
          sub_6F280();
        }
      }
      else if ( (_WORD)v85 != word_19C178 || word_199992 >= word_1999A0 || word_199976 )
      {
        if ( (_WORD)v85 == word_19C15C && byte_199F0C == 1 && !word_199976 )
        {
          sub_9191D();
          byte_199F0C = 0;
          sub_6F280();
          sub_123E6C((int)&unk_17CF00, 1);
          sub_1191CA((int)sub_84555, 1);
          sub_7927F();
          word_19998C += v57;
          sub_7927F();
          word_199990 += v58;
          v82 = 0;
          v59 = sub_790A4(word_19999E);
          word_199980 = 22;
          word_19998A = 22;
          word_199984 = 22;
          word_19997E = 22;
          word_19998E = 22;
          word_199986 = 22;
          byte_199F28 = 1;
          word_199992 = v59;
        }
      }
      else
      {
        v48 = word_19998C;
        v49 = word_199990;
        v50 = sub_79917();
        sub_796BF();
        word_199992 = sub_790A4(word_19999E);
        v51 = (int16_t)sub_79917() - v50;
        word_19998C -= (506 * v51 - (__CFSHL__((506 * v51) >> 31, 2) + 4 * ((506 * v51) >> 31))) >> 2;
        word_199990 -= (400 * v51 - (__CFSHL__((400 * v51) >> 31, 2) + 4 * ((400 * v51) >> 31))) >> 2;
        v82 = 0;
        if ( word_19998C > 506 * (word_1999A0 - word_199992) / 10 )
          word_19998C = 506 * (word_1999A0 - word_199992) / 10;
        i = 10;
        if ( word_199990 > 400 * (word_1999A0 - word_199992) / 10 )
          word_199990 = 400 * (word_1999A0 - word_199992) / 10;
        if ( word_19998C < 0 )
          word_19998C = 0;
        if ( word_199990 < 0 )
          word_199990 = 0;
        if ( word_199992 == word_1999A0 )
        {
          word_19998C = 0;
          word_199990 = 0;
        }
        sub_7927F();
        if ( v52 < word_19998C )
        {
          sub_7927F();
          word_19998C = v53;
        }
        sub_7927F();
        if ( word_199990 > word_199A0A - v54 )
        {
          sub_7927F();
          word_199990 = word_199A0A - v55;
        }
        v56 = word_19998C - v48;
        v5 = 1;
        byte_199F28 = 1;
        sub_8590A(v56, word_199990 - v49, 1);
      }
    }
    else
    {
      if ( !(_WORD)v82 )
        sub_919A4();
      ++v82;
      if ( !byte_199F0C )
      {
        sub_1196F7();
        byte_199F0C = 1;
        sub_1318D4(0, 255);
        sub_133237();
        sub_124B65();
        sub_124D41();
        sub_84E9D();
        sub_1112EC(dword_192ED4, 401);
        v46 = sub_12DAA4(507, 401);
        dword_19C150 = (int)sub_110D3C(dword_192ED4, v46);
        sub_12E148(22, 22, 527, 421, dword_19C150);
        i = 421;
        v5 = 527;
        sub_1113CC(dword_192ED4, 22);
        sub_90006(22, 22, 527, 421);
        sub_124DEC();
        sub_124C08();
        sub_1191CA((int)sub_84BCE, 1);
      }
      byte_199F0C = 1;
      sub_119400(word_19C154);
      sub_81D73();
      sub_123E6C((int)&unk_182175, 5);
      sub_78FE6();
      byte_199F28 = 1;
    }
    v3 = -word_1999C8;
    if ( (int16_t)v85 == v3 && !word_199976 && word_199992 != word_1999A0 )
    {
      sub_7927F();
      v3 = (int16_t)(word_199990 + v60);
      sub_7927F();
      sub_89DF9(word_19998C + v61, v3);
    }
    if ( !(_WORD)v74 && !word_199A0E )
    {
      if ( word_199976 )
      {
        word_199976 = 0;
        sub_1172D4();
        sub_11C2F0();
        v62 = sub_89F8A();
        sub_81D15(v62, v3);
      }
      else
      {
        sub_119400(word_19C154);
        sub_1172FC();
        sub_1194C4();
      }
      sub_81D73();
      if ( byte_199F0C == 1 )
      {
        sub_124D41();
        sub_84BCE();
      }
      else
      {
        sub_124D41();
        sub_84555(a1);
      }
      sub_1077D(v63, v3, v5, (int16_t *)a1);
    }
    if ( sub_918D5(2) )
    {
      if ( byte_19C19E && !sub_124075() )
      {
        byte_19C19E = 0;
        sub_117174(2);
      }
      sub_71B91();
      if ( !sub_72617() )
        word_19995C = -1;
    }
    sub_12C2C6(1);
  }
}
// 8763F: control flows out of bounds to 83D00
// 86516: variable 'v11' is possibly undefined
// 86587: variable 'v12' is possibly undefined
// 865BF: variable 'v15' is possibly undefined
// 86906: variable 'v31' is possibly undefined
// 869DD: variable 'v32' is possibly undefined
// 86AAE: variable 'v35' is possibly undefined
// 86CDF: variable 'v39' is possibly undefined
// 86E3E: variable 'v40' is possibly undefined
// 86FBB: variable 'v42' is possibly undefined
// 87342: variable 'v52' is possibly undefined
// 87356: variable 'v53' is possibly undefined
// 87366: variable 'v54' is possibly undefined
// 87390: variable 'v55' is possibly undefined
// 8742A: variable 'v57' is possibly undefined
// 87440: variable 'v58' is possibly undefined
// 874D3: variable 'v60' is possibly undefined
// 874F0: variable 'v61' is possibly undefined
// 8756E: variable 'v63' is possibly undefined
// FE8BD: using guessed type int __fastcall nullsub_14(_DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 192FD8: using guessed type int dword_192FD8;
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 192FEC: using guessed type int16_t word_192FEC[];
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1932D0: using guessed type int dword_1932D0;
// 1933F4: using guessed type int dword_1933F4;
// 197F98: using guessed type int dword_197F98;
// 1992A8: using guessed type char byte_1992A8;
// 1992A9: using guessed type char byte_1992A9;
// 1992AA: using guessed type char byte_1992AA;
// 1992AD: using guessed type char byte_1992AD;
// 1992B5: using guessed type char byte_1992B5;
// 1992D4: using guessed type int16_t word_1992D4[10];
// 199830: using guessed type int16_t word_199830;
// 199838: using guessed type int16_t word_199838;
// 199956: using guessed type int16_t word_199956;
// 19995C: using guessed type int16_t word_19995C;
// 199960: using guessed type int16_t word_199960;
// 199964: using guessed type int16_t word_199964;
// 199966: using guessed type int16_t word_199966;
// 199976: using guessed type int16_t word_199976;
// 19997E: using guessed type int16_t word_19997E;
// 199980: using guessed type int16_t word_199980;
// 199984: using guessed type int16_t word_199984;
// 199986: using guessed type int16_t word_199986;
// 199988: using guessed type int16_t word_199988;
// 19998A: using guessed type int16_t word_19998A;
// 19998C: using guessed type int16_t word_19998C;
// 19998E: using guessed type int16_t word_19998E;
// 199990: using guessed type int16_t word_199990;
// 199992: using guessed type int16_t word_199992;
// 199996: using guessed type int16_t word_199996;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 19999E: using guessed type int16_t word_19999E;
// 1999A0: using guessed type int16_t word_1999A0;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999C0: using guessed type int16_t word_1999C0;
// 1999C2: using guessed type int16_t word_1999C2;
// 1999C4: using guessed type int16_t word_1999C4;
// 1999C6: using guessed type int16_t word_1999C6;
// 1999C8: using guessed type int16_t word_1999C8;
// 1999CA: using guessed type int16_t word_1999CA;
// 1999DC: using guessed type int16_t word_1999DC;
// 1999DE: using guessed type int16_t word_1999DE;
// 1999FC: using guessed type int16_t word_1999FC;
// 199A06: using guessed type int16_t word_199A06;
// 199A08: using guessed type int16_t word_199A08;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;
// 199A0E: using guessed type int16_t word_199A0E;
// 199A10: using guessed type int16_t word_199A10;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BE3: using guessed type char byte_199BE3;
// 199BF1: using guessed type char byte_199BF1;
// 199EC7: using guessed type int16_t word_199EC7;
// 199ECB: using guessed type int16_t word_199ECB;
// 199EFE: using guessed type char byte_199EFE;
// 199F0C: using guessed type char byte_199F0C;
// 199F19: using guessed type char byte_199F19;
// 199F1D: using guessed type char byte_199F1D;
// 199F1F: using guessed type char byte_199F1F;
// 199F21: using guessed type char byte_199F21;
// 199F28: using guessed type char byte_199F28;
// 199F2C: using guessed type char byte_199F2C;
// 199F2D: using guessed type char byte_199F2D;
// 199F33: using guessed type char byte_199F33;
// 199F37: using guessed type char byte_199F37;
// 199F38: using guessed type char byte_199F38;
// 199F39: using guessed type char byte_199F39;
// 199F3A: using guessed type char byte_199F3A;
// 19C150: using guessed type int dword_19C150;
// 19C154: using guessed type int16_t word_19C154;
// 19C158: using guessed type int16_t word_19C158;
// 19C15A: using guessed type int16_t word_19C15A;
// 19C15C: using guessed type int16_t word_19C15C;
// 19C15E: using guessed type int16_t word_19C15E;
// 19C160: using guessed type int16_t word_19C160;
// 19C162: using guessed type int16_t word_19C162;
// 19C164: using guessed type int16_t word_19C164;
// 19C166: using guessed type int16_t word_19C166;
// 19C168: using guessed type int16_t word_19C168;
// 19C170: using guessed type int16_t word_19C170;
// 19C172: using guessed type int16_t word_19C172;
// 19C176: using guessed type int16_t word_19C176;
// 19C178: using guessed type int16_t word_19C178;
// 19C17A: using guessed type int16_t word_19C17A;
// 19C17C: using guessed type int16_t word_19C17C;
// 19C17E: using guessed type int16_t word_19C17E;
// 19C180: using guessed type int16_t word_19C180;
// 19C182: using guessed type int16_t word_19C182;
// 19C184: using guessed type int16_t word_19C184;
// 19C188: using guessed type int16_t word_19C188;
// 19C18A: using guessed type int16_t word_19C18A;
// 19C18E: using guessed type char byte_19C18E;
// 19C18F: using guessed type char byte_19C18F;
// 19C195: using guessed type char byte_19C195;
// 19C197: using guessed type char byte_19C197;
// 19C198: using guessed type char byte_19C198;
// 19C19A: using guessed type char byte_19C19A;
// 19C19B: using guessed type char byte_19C19B;
// 19C19C: using guessed type char byte_19C19C;
// 19C19D: using guessed type char byte_19C19D;
// 19C19E: using guessed type char byte_19C19E;
// 19C19F: using guessed type char byte_19C19F;
// 19C1A0: using guessed type char byte_19C1A0;
// 19C1A2: using guessed type char byte_19C1A2;
// 19D32C: using guessed type char byte_19D32C;
// 1ACE74: using guessed type char byte_1ACE74;


//----- (00087644) --------------------------------------------------------
void __usercall sub_87644(int a1, int a2, int16_t *a3)
{
  int v4; // eax

  sub_124B65();
  sub_A5EB2(a1, a2);
  sub_124D41();
  sub_128C32(0, 0, 639, 479, 0);
  byte_199F28 = 1;
  if ( word_199A08 )
    LOWORD(v4) = sub_84E9D();
  else
    sub_84555(a3);
  sub_1077D(v4, 0, 639, a3);
  sub_124C08();
}
// 8768B: variable 'v4' is possibly undefined
// 199A08: using guessed type int16_t word_199A08;
// 199F28: using guessed type char byte_199F28;


//----- (00087698) --------------------------------------------------------
void __usercall sub_87698(int a1, int a2, int16_t *a3)
{
  int v4; // eax

  sub_124B65();
  sub_A5EB2(a1, a2);
  sub_124D41();
  sub_128C32(0, 0, 639, 479, 0);
  LOWORD(v4) = sub_84E9D();
  sub_1077D(v4, 0, 639, a3);
  sub_124C08();
  byte_199F28 = 1;
}
// 876C7: variable 'v4' is possibly undefined
// 199F28: using guessed type char byte_199F28;


//----- (000876DB) --------------------------------------------------------
void sub_876DB()
{
  int v0; // eax

  byte_199BE3 = 0;
  LOWORD(v0) = word_1999C6;
  do
  {
    if ( (int16_t)v0 == -1 )
      LOWORD(v0) = 0;
    else
      v0 = ((int16_t)v0 + 1) % word_19999A;
  }
  while ( *(_BYTE *)(113 * (int16_t)v0 + dword_19306C + 22) >= 6u );
  sub_83669(v0);
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 1999C6: using guessed type int16_t word_1999C6;
// 199BE3: using guessed type char byte_199BE3;


//----- (00087720) --------------------------------------------------------
void sub_87720()
{
  int16_t v0; // ax

  byte_199BE3 = 0;
  v0 = word_1999C6;
  do
  {
    if ( v0 != -1 && --v0 >= 0 )
      continue;
    v0 = word_19999A - 1;
  }
  while ( *(_BYTE *)(113 * v0 + dword_19306C + 22) >= 6u );
  sub_83669(v0);
}
// 87720: could not find valid save-restore pair for esi
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 1999C6: using guessed type int16_t word_1999C6;
// 199BE3: using guessed type char byte_199BE3;


//----- (00087768) --------------------------------------------------------
int __fastcall sub_87768( int a1, int a2, int a3, int a4)
{
  int v5; // edi
  int16_t v6; // dx
  int v7; // eax
  int v8; // eax
  int16_t v9; // di
  int16_t v10; // bx
  int16_t v11; // si
  int16_t v12; // ax
  int result; // eax
  uint8_t v14; // cl
  int v15; // eax
  int16_t v16; // dx
  uint8_t v17; // bl
  int16_t v18; // dx
  int16_t v19; // dx
  int v20; // ecx
  int v21; // eax
  int16_t v22; // bx
  int16_t v23; // cx
  int v24; // esi
  int v25; // edx
  int16_t v26; // di
  int16_t v27; // ax
  _BYTE v28[8]; // [esp+0h] [ebp-40h] BYREF
  _DWORD v29[2]; // [esp+8h] [ebp-38h]
  int v30; // [esp+10h] [ebp-30h]
  int v31; // [esp+14h] [ebp-2Ch]
  int v32; // [esp+18h] [ebp-28h]
  int v33; // [esp+1Ch] [ebp-24h]
  int v34; // [esp+20h] [ebp-20h]
  int v35; // [esp+24h] [ebp-1Ch]
  int v36; // [esp+28h] [ebp-18h]
  int16_t v37; // [esp+2Ch] [ebp-14h] BYREF
  int v38; // [esp+30h] [ebp-10h] BYREF
  char v39; // [esp+34h] [ebp-Ch]
  uint8_t v40; // [esp+38h] [ebp-8h]
  uint8_t v41; // [esp+3Ch] [ebp-4h]

  v39 = a2;
  v31 = a3;
  v5 = a1;
  sub_79917();
  v30 = 113 * v5;
  v6 = *(uint8_t *)(113 * v5 + dword_19306C + 19);
  v7 = (int16_t)(v6 + sub_79917());
  LOWORD(v7) = word_1931AC[v7];
  v36 = v7;
  v34 = v7;
  sub_85B93(v5, &v38, &v37);
  v30 = *(uint8_t *)(113 * v5 + dword_19306C + 19);
  v8 = v37 + (int16_t)v36 / 2 - v30;
  v9 = v38 + 1;
  v10 = v8;
  if ( v39 )
  {
    v11 = v8;
    v12 = sub_12066F(v31);
    return sub_12A478(v9 - v12 / 2, v11, a4);
  }
  else
  {
    v14 = sub_7A440();
    sub_8F625((int)v28);
    sub_120DED(2, 1);
    sub_120D79(v14, (int)v28);
    sub_120E8C(1);
    v33 = sub_12066F(v31);
    v15 = v9 - (int16_t)v33 / 2;
    if ( word_199992 == word_1999A0 && (int16_t)v15 < 22 )
    {
      v16 = v10;
      v17 = v31;
      sub_1212B3(22, v16, v31);
    }
    else if ( word_199992 == word_1999A0 && (int16_t)v15 + (int16_t)v33 > 527 )
    {
      v18 = v10;
      v17 = v31;
      sub_1210B7(527, v18, v31);
    }
    else
    {
      v19 = v10;
      v17 = v31;
      sub_1210FD(v9, v19, v31);
    }
    v20 = 113 * a1;
    result = dword_19306C + v20 + word_19999C;
    if ( (unsigned int)*(char *)(result + 103) < 8 )
    {
      LOWORD(result) = *(char *)(result + 103);
      v32 = result;
      v29[0] = 746093440;
      v29[1] = dword_81C88[1];
      sub_7A00A(0, 0, v17);
      sub_120E8C(1);
      v21 = sub_12066F(v31);
      v22 = v21;
      v35 = v21;
      v41 = *(_BYTE *)(3753 * (int16_t)v32 + dword_197F98 + 38);
      v40 = *((_BYTE *)v29 + v41);
      v23 = *(uint8_t *)(v20 + dword_19306C + 19);
      v24 = (int16_t)v38 - (int16_t)v21 / 2;
      v25 = (int16_t)v34 / 2 + v37;
      v26 = v25 - v23 + sub_122259();
      result = sub_134D2D((int16_t)v24, v26, (int16_t)(v24 + v22), v26, v40);
      if ( word_199992 < 30 )
      {
        v27 = v40 + 1;
        if ( v41 == 3 || v41 == 5 )
          v27 = v40 - 3;
        return sub_134D2D((int16_t)v24, (int16_t)(v26 + 1), (int16_t)(v24 + v35), (int16_t)(v26 + 1), v27);
      }
    }
  }
  return result;
}
// 81C88: using guessed type int dword_81C88[4];
// 19306C: using guessed type int dword_19306C;
// 1931AC: using guessed type int16_t word_1931AC[];
// 197F98: using guessed type int dword_197F98;
// 199992: using guessed type int16_t word_199992;
// 19999C: using guessed type int16_t word_19999C;
// 1999A0: using guessed type int16_t word_1999A0;


//----- (000879BC) --------------------------------------------------------
void __fastcall sub_879BC(int a1, int a2, unsigned int a3)
{
  int v3; // edx
  int16_t v4; // cx
  int v5; // eax
  int16_t *v6; // eax
  int16_t i; // cx
  int16_t j; // cx
  _BYTE v9[80]; // [esp+0h] [ebp-58h] BYREF
  _BYTE v10[8]; // [esp+50h] [ebp-8h] BYREF

  v3 = 113 * word_199960;
  v4 = *(char *)(v3 + dword_19306C + 20);
  v5 = *(char *)(v3 + dword_19306C + 20);
  if ( v5 <= -1 || v4 >= 8 )
  {
    if ( *(char *)(v3 + dword_19306C + 20) == -1 )
    {
      for ( i = 0; i < 8; ++i )
      {
        if ( i / 2 )
          v10[i] = 12;
        else
          v10[i] = 8;
      }
      sprintf(v9, "%s", 113 * word_199960 + dword_19306C);
    }
    else if ( *(char *)(v3 + dword_19306C + 20) == -2 )
    {
      for ( j = 0; j < 8; ++j )
      {
        if ( j / 2 )
          v10[j] = 31;
        else
          v10[j] = 20;
      }
      sprintf(v9, "%s (contested)", dword_19306C + 113 * word_199960);
    }
  }
  else
  {
    sub_7A00A(v5, 0, a3);
    v6 = sub_78477(v4);
    sprintf(v9, "%s (%s)", (char *)(dword_19306C + 113 * word_199960), (char *)v6);
  }
  sub_120BB5(2, (int)v10);
  JUMPOUT(0x854B5);
}
// 87AF4: control flows out of bounds to 854B5
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192FFC: using guessed type int16_t word_192FFC;
// 19306C: using guessed type int dword_19306C;
// 199960: using guessed type int16_t word_199960;


//----- (00087AF9) --------------------------------------------------------
void __fastcall sub_87AF9( int a1)
{
  char v2[32]; // [esp+0h] [ebp-2Ch] BYREF
  int16_t *v3; // [esp+20h] [ebp-Ch] BYREF
  int16_t v4; // [esp+24h] [ebp-8h] BYREF
  char v5[4]; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  sub_8FD71(&v4);
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_85C8A(a1, 1, v5, v2, &v3);
  if ( v2[0] )
  {
    if ( v5[0] )
    {
      sub_8FF08(0, 0, 0, 0, 1, byte_182146, v3);
      byte_182146 += byte_182145;
      if ( !byte_182146 || byte_182146 == 3 )
        byte_182145 = -byte_182145;
    }
    sub_87768(a1, v5[0], (int)v2, (int)v3);
  }
  sub_8FD56(v4);
  JUMPOUT(0x8373B);
}
// 87BA9: control flows out of bounds to 8373B
// 182145: using guessed type char byte_182145;
// 182146: using guessed type char byte_182146;


//----- (00087BAE) --------------------------------------------------------
void sub_87BAE()
{
  uint8_t v0; // bl
  int16_t v1; // ax
  int v2; // esi
  int v3; // ecx
  int16_t v4; // ax
  int v5; // ecx
  int16_t v6; // ax
  char *v7; // eax
  int16_t v8; // di
  int16_t v9; // si
  int16_t v10; // dx
  int16_t *v11; // eax
  int v12; // edx
  int16_t v13; // ax
  char *v14; // eax
  int16_t v15; // dx
  int16_t v16; // di
  int16_t v17; // ax
  int v18; // eax
  int16_t v19; // si
  char *v20; // eax
  int16_t v21; // di
  int v22; // eax
  char *v23; // eax
  int v24; // eax
  int v25; // ecx
  int16_t v26; // si
  int v27; // eax
  char *v28; // eax
  char *v29; // eax
  int v30; // eax
  char *v31; // eax
  int16_t v32; // di
  int16_t v33; // cx
  int v34; // eax
  char *v35; // eax
  int v36; // edx
  int16_t v37; // ax
  int16_t v38; // si
  int16_t v39; // bx
  int v40; // eax
  int16_t v41; // di
  int16_t v42; // cx
  uint16_t v43; // ax
  int16_t v44; // dx
  char *v45; // ebx
  int16_t v46; // ax
  int16_t v47; // ax
  int16_t v48; // si
  int v49; // eax
  int16_t v50; // ax
  uint16_t v51; // ax
  char *v52; // eax
  int16_t v53; // di
  int16_t v54; // di
  int16_t v55; // ax
  int v56; // ecx
  uint16_t v57; // ax
  char *v58; // eax
  int16_t v59; // ax
  int16_t v60; // di
  int16_t *v61; // eax
  int v62; // eax
  int16_t *v63; // [esp-8h] [ebp-DEh]
  int16_t *v64; // [esp-8h] [ebp-DEh]
  int v65; // [esp-8h] [ebp-DEh]
  int16_t v66; // [esp-4h] [ebp-DAh]
  int16_t v67; // [esp-4h] [ebp-DAh]
  int v68; // [esp-4h] [ebp-DAh]
  int v69; // [esp-4h] [ebp-DAh]
  int16_t *v70; // [esp-4h] [ebp-DAh]
  int16_t *v71; // [esp-4h] [ebp-DAh]
  int v72; // [esp-4h] [ebp-DAh]
  int v73; // [esp-4h] [ebp-DAh]
  int v74; // [esp-4h] [ebp-DAh]
  int v75; // [esp-4h] [ebp-DAh]
  char v76[80]; // [esp+0h] [ebp-D6h] BYREF
  _BYTE v77[80]; // [esp+50h] [ebp-86h] BYREF
  char v78[32]; // [esp+A0h] [ebp-36h] BYREF
  uint8_t v79; // [esp+C0h] [ebp-16h] BYREF
  uint8_t v80; // [esp+C1h] [ebp-15h]
  char v81[8]; // [esp+C8h] [ebp-Eh] BYREF
  _BYTE v82[8]; // [esp+D0h] [ebp-6h] BYREF
  char v83[8]; // [esp+D8h] [ebp+2h] BYREF
  char v84[8]; // [esp+E0h] [ebp+Ah] BYREF
  int v85; // [esp+E8h] [ebp+12h]
  int v86; // [esp+ECh] [ebp+16h]
  int v87; // [esp+F0h] [ebp+1Ah]
  int v88; // [esp+F4h] [ebp+1Eh]
  int v89; // [esp+F8h] [ebp+22h]
  int v90; // [esp+FCh] [ebp+26h]
  int v91; // [esp+100h] [ebp+2Ah]
  int v92; // [esp+104h] [ebp+2Eh]
  int v93; // [esp+108h] [ebp+32h]
  int v94; // [esp+10Ch] [ebp+36h]
  int v95; // [esp+110h] [ebp+3Ah]
  int v96; // [esp+114h] [ebp+3Eh]
  int v97; // [esp+118h] [ebp+42h]
  int v98; // [esp+11Ch] [ebp+46h]
  int v99; // [esp+120h] [ebp+4Ah]
  int v100; // [esp+124h] [ebp+4Eh]
  int v101; // [esp+128h] [ebp+52h]
  int v102; // [esp+12Ch] [ebp+56h]
  int v103; // [esp+130h] [ebp+5Ah]
  int v104; // [esp+134h] [ebp+5Eh]
  int v105; // [esp+138h] [ebp+62h]
  int v106; // [esp+13Ch] [ebp+66h]
  int v107; // [esp+140h] [ebp+6Ah]
  int v108; // [esp+144h] [ebp+6Eh]
  int v109; // [esp+148h] [ebp+72h]
  int v110; // [esp+14Ch] [ebp+76h]
  int v111; // [esp+150h] [ebp+7Ah]
  uint8_t v112; // [esp+154h] [ebp+7Eh]

  v112 = 23;
  v104 = 549;
  v110 = 28;
  v100 = 62;
  v99 = 548;
  v105 = 97;
  v96 = 181;
  v93 = 255;
  v97 = 330;
  v98 = 403;
  v102 = 67;
  v101 = 2;
  v103 = 2;
  v0 = 46;
  if ( byte_199CAE == 1 || byte_199CAE == 2 )
    v0 = 44;
  sub_120BB5(0, (int)&v79);
  sub_122259();
  sprintf(v76, "%d%c%d", dword_192FD8 / 10, v0, dword_192FD8 % 10);
  sub_8FDA1((int)v76, (int)v82, v101, v103, -1, v102, 1);
  v1 = sub_8F64C();
  v86 = v1;
  qmemcpy(v82, sub_8E5C5(v1, 14, 23), sizeof(v82));
  sub_120DED(2, 1);
  sub_120D79(v86, (int)v82);
  sub_1210FD(v104 + (int16_t)v100 / 2, v110 + 1, (int)v76);
  if ( sub_233FA() )
  {
    sub_8F6F8(3u, 73, 76, (char *)&v79);
    sub_120BB5(3, (int)&v79);
    sub_8F7DF(5 * (uint8_t)byte_199F07 / 9);
    strcpy(v78, sub_7A990(0xE0u));
    v2 = (int16_t)(526 - sub_12066F((int)v78));
    sub_134D2D(v2, 21, 526, 21, v79);
    sub_134D2D(v2, 22, 526, 22, v80);
    sub_1210B7(526, 24, (int)v78);
    v66 = v80;
    v3 = (int16_t)(sub_122259() + 25);
    v4 = sub_122259();
    sub_134D2D(v2, (int16_t)(v4 + 25), 526, v3, v66);
    v67 = v79;
    v5 = (int16_t)(sub_122259() + 26);
    v6 = sub_122259();
    sub_134D2D(v2, (int16_t)(v6 + 26), 526, v5, v67);
  }
  sub_122259();
  sub_7ABA6((int)v84);
  v63 = sub_8E6DE();
  if ( *(int16_t *)(dword_197F98 + 3753 * word_19999C + 178) < 0 )
    v7 = (char *)&unk_179716;
  else
    v7 = asc_179714;
  v8 = v103;
  sprintf(v76, "%s%s %s", v7, (char *)v63, v84);
  v9 = v101;
  v91 = (int16_t)v102;
  sub_8FDA1((int)v76, (int)v81, v101, v8, 4, v102, 1);
  v10 = sub_8F64C();
  sub_8F645();
  v86 = v10;
  sub_8F6F8(v10, 75, 77, (char *)&v79);
  sub_8F6F8(v86, 14, v112, v81);
  v92 = v105;
  v11 = sub_8E6DE();
  sprintf(v76, "%s %s", (char *)v11, v84);
  v95 = v105 - 1;
  if ( *(int *)(dword_197F98 + 3753 * word_19999C + 50) >= 0 )
  {
    sub_8FDA1((int)v76, (int)v81, v9, v8, 4, v91, 1);
    v12 = 1;
    v13 = 2;
  }
  else
  {
    sub_8FDA1((int)v76, (int)&v79, v9, v8, 4, v91, 1);
    sub_88B0A(75, 77);
    v12 = 73;
    sub_8F7DF(4 * (uint8_t)byte_199F07 / 7);
    v13 = 73;
  }
  sub_120DED(v13, v12);
  sub_1210FD(v99 + (int16_t)v100 / 2, v95, (int)v76);
  v64 = sub_8E6DE();
  if ( *(int16_t *)(dword_197F98 + 3753 * word_19999C + 178) < 0 )
    v14 = (char *)&unk_179716;
  else
    v14 = asc_179714;
  sprintf(v76, "%s%s %s", v14, (char *)v64, v84);
  sub_8FDA1((int)v76, (int)v81, v101, v103, 4, v102, 1);
  v15 = sub_8F64C();
  v16 = sub_8F645();
  sub_8F6F8(v15, 75, 77, (char *)&v79);
  sub_8F6F8(v15, 14, v112, v81);
  if ( *(int16_t *)(dword_197F98 + 3753 * word_19999C + 178) >= 0 )
  {
    sub_120D79(v15, (int)v81);
    sub_120DED(2, 1);
    sub_120E8C(v16);
  }
  else
  {
    sub_120DED(73, 73);
    sub_120D79(v15, (int)&v79);
    sub_120E8C(v16);
    sub_8F7DF(4 * (uint8_t)byte_199F07 / 7);
  }
  v17 = sub_122259();
  sub_1210FD(v99 + (int16_t)v100 / 2, v92 + v17 - 1, (int)v76);
  v18 = 3753 * word_19999C;
  v19 = *(_WORD *)(dword_197F98 + v18 + 58) - *(_WORD *)(dword_197F98 + v18 + 60);
  v68 = *(int16_t *)(dword_197F98 + v18 + 58);
  if ( v19 < 0 )
    v20 = (char *)&unk_179716;
  else
    v20 = asc_179714;
  sprintf(v76, "%s%d (%d)", v20, v19, v68);
  sub_8FDA1((int)v76, (int)v81, v101, v103, 4, v102, 0);
  v21 = HIWORD(dword_1B61E4);
  LOWORD(v22) = sub_8F645();
  v111 = v22;
  v86 = v21;
  sub_8F6F8(v21, 75, 77, (char *)&v79);
  sub_8F6F8(v86, 14, v112, v81);
  if ( v19 < 0 )
    v23 = (char *)&unk_179716;
  else
    v23 = asc_179714;
  sprintf(v76, "%s%d", v23, v19);
  v24 = sub_12066F((int)v76);
  v69 = *(int16_t *)(dword_197F98 + 3753 * word_19999C + 58);
  v25 = v24 + 4;
  v108 = v96;
  sprintf(v77, "(%d)", v69);
  v106 = sub_12066F((int)v77) + v25;
  if ( v19 >= 0 )
  {
    sub_120D79(v21, (int)v81);
    sub_120DED(2, 1);
    sub_120E8C(v111);
  }
  else
  {
    sub_120D79(v21, (int)&v79);
    sub_120DED(73, 73);
    sub_120E8C(v111);
    sub_8F7DF(4 * (uint8_t)byte_199F07 / 7);
  }
  v26 = v108;
  v86 = (int16_t)v100 / 2 + (int16_t)v99 + 2 - (int16_t)v106 / 2;
  sub_1212B3((int16_t)v100 / 2 + v99 + 2 - (int16_t)v106 / 2, v108, (int)v76);
  sub_120BB5(v21, (int)v81);
  sub_120E8C(v111);
  sub_1212B3(v86 + v25, v26, (int)v77);
  LOWORD(v27) = sub_122259();
  v109 = v27;
  if ( *(int16_t *)(3753 * word_19999C + dword_197F98 + 176) >= 0 )
  {
    v71 = sub_8E6DE();
    if ( *(int16_t *)(dword_197F98 + 3753 * word_19999C + 176) < 0 )
      v29 = (char *)&unk_179716;
    else
      v29 = asc_179714;
    sprintf(v76, "%s%s", v29, (char *)v71);
    sub_8FDA1((int)v76, (int)v81, v101, v103, 4, v102, 1);
    sub_88B0A(14, v112);
    sub_120DED(2, 1);
  }
  else
  {
    v70 = sub_8E6DE();
    if ( *(int16_t *)(dword_197F98 + 3753 * word_19999C + 176) < 0 )
      v28 = (char *)&unk_179716;
    else
      v28 = asc_179714;
    sprintf(v76, "%s%s", v28, (char *)v70);
    sub_8FDA1((int)v76, (int)&v79, v101, v103, 4, v102, 1);
    sub_88B0A(75, 77);
    sub_120DED(73, 73);
    sub_8F7DF(4 * (uint8_t)byte_199F07 / 7);
  }
  sub_1210FD(v99 + (int16_t)v100 / 2, v93, (int)v76);
  v30 = dword_197F98 + 3753 * word_19999C;
  v72 = *(int16_t *)(v30 + 54);
  v65 = *(int16_t *)(v30 + 56);
  if ( *(int16_t *)(v30 + 56) < 0 )
    v31 = (char *)&unk_179716;
  else
    v31 = asc_179714;
  sprintf(v76, "%s%d (%d)", v31, v65, v72);
  sub_8FDA1((int)v76, (int)&v79, v101, v103, 4, v102, 1);
  v32 = sub_8F64C();
  sub_8F6F8(v32, 75, 77, (char *)&v79);
  sub_8F6F8(v32, 14, v112, v81);
  v33 = sub_8F645();
  v107 = sub_12066F((int)v76) + 4;
  v34 = dword_197F98 + 3753 * word_19999C;
  v73 = *(int16_t *)(v34 + 56);
  if ( *(int16_t *)(v34 + 56) < 0 )
    v35 = (char *)&unk_179716;
  else
    v35 = asc_179714;
  sprintf(v76, "%s%d", v35, v73);
  if ( *(int16_t *)(3753 * word_19999C + dword_197F98 + 56) >= 0 )
  {
    sub_120D79(v32, (int)v81);
    v36 = 1;
    sub_120E8C(v33);
    v37 = 2;
  }
  else
  {
    sub_120D79(v32, (int)&v79);
    sub_120E8C(v33);
    v36 = 73;
    sub_8F7DF(4 * (uint8_t)byte_199F07 / 7);
    v37 = 73;
  }
  sub_120DED(v37, v36);
  v90 = (int16_t)v99;
  v85 = (int16_t)v100 / 2;
  v38 = v97;
  v87 = v85 + (int16_t)v99 + 2 - (int16_t)v107 / 2;
  sub_1212B3(v85 + v99 + 2 - (int16_t)v107 / 2, v97, (int)v76);
  sub_120DED(2, 1);
  v39 = sub_12066F((int)v76);
  v86 = 3753 * word_19999C;
  sprintf(v76, "(%d)", *(int16_t *)(v86 + dword_197F98 + 54));
  sub_120D79(v32, (int)v81);
  sub_120E8C(v33);
  sub_1212B3(v87 + v39 + 2, v38, (int)v76);
  sub_8A7FC((int)v83);
  v40 = 3753 * word_19999C + dword_197F98;
  v41 = v85 + v90;
  if ( *(_BYTE *)(v40 + 48) )
  {
    sub_120DED(2, 1);
    v42 = v41;
    sub_120D79(0, (int)v81);
    v43 = 387;
  }
  else
  {
    if ( *(_BYTE *)(v40 + 801) )
    {
      v47 = sub_E1F24(v40);
      v48 = v47;
      if ( v47 <= 0 )
      {
        if ( v47 >= 0 )
        {
          v62 = sub_E1EF4(dword_197F98 + 3753 * word_19999C);
          v94 = v98 - 12;
          sprintf(v76, "%d%%", v62);
          v86 = (int16_t)v102;
          v87 = (int16_t)v103;
          v88 = (int16_t)v101;
          sub_8FDA1((int)v76, (int)v81, v101, v103, 4, v102, 1);
          v89 = v112;
          sub_88B0A(14, v112);
          sub_120DED(2, 1);
          sub_1210FD(v41, v94, (int)v76);
          v94 += v109;
          sprintf(v76, "%d %s", *(int16_t *)(3753 * word_19999C + dword_197F98 + 172), v83);
          sub_8FDA1((int)v76, (int)v81, v88, v87, 4, v86, 1);
          sub_88B0A(14, v89);
          v45 = v76;
          sub_120DED(2, 1);
          v44 = v94;
        }
        else
        {
          sprintf(v76, "0 %s", v83);
          sub_8FDA1((int)v76, (int)v81, v101, v103, 4, v102, 1);
          sub_88B0A(14, v112);
          v45 = v76;
          sub_120DED(2, 1);
          v44 = v98;
        }
        v46 = v41;
      }
      else
      {
        v49 = sub_E1EF4(dword_197F98 + 3753 * word_19999C);
        if ( v49 > 0 )
        {
          sprintf(v76, "%d%%", v49);
          sub_8FDA1((int)v76, (int)v81, v101, v103, 4, v102, 1);
          sub_88B0A(14, v112);
          sub_120DED(2, 1);
          v50 = sub_122259();
          sub_1210FD(v41, v98 - 2 * v50, (int)v76);
        }
        if ( v48 == 1 )
        {
          v74 = 1;
          v51 = 225;
        }
        else
        {
          v74 = v48;
          v51 = 226;
        }
        v52 = sub_7A990(v51);
        sprintf(v76, v52, v74);
        sprintf(v77, "@%s", v76);
        sub_8FDA1((int)v77, (int)v81, v101, v103, 4, v102, 1);
        v53 = v98;
        sub_88B0A(14, v112);
        v54 = v53 - sub_122259();
        sub_120DED(2, 1);
        sub_12066F((int)v76);
        v55 = sub_12066F((int)v76);
        v56 = (int16_t)v99 + ((int16_t)v100 - v55) / 2;
        sub_1212B3(v99 + ((int16_t)v100 - v55) / 2, v54 + 3, (int)asc_1797AD);
        if ( v48 == 1 )
        {
          v75 = 1;
          v57 = 225;
        }
        else
        {
          v75 = v48;
          v57 = 226;
        }
        v58 = sub_7A990(v57);
        sprintf(v76, v58, v75);
        v59 = sub_12066F((int)asc_1797AD);
        sub_1212B3(v56 + v59, v54, (int)v76);
        v60 = sub_122259() + v54;
        v61 = sub_8E6DE();
        sprintf(v76, "%s %s", (char *)v61, v83);
        sub_8FDA1((int)v76, (int)v81, v101, v103, 4, v102, 1);
        sub_88B0A(14, v112);
        sub_120DED(2, 1);
        v45 = v76;
        v46 = v99 + (int16_t)v100 / 2;
        v44 = v60;
      }
LABEL_64:
      sub_1210FD(v46, v44, (int)v45);
      JUMPOUT(0x87638);
    }
    sub_120DED(2, 1);
    sub_8FDA1((int)v76, (int)v81, v101, v103, 4, v102, 1);
    sub_88B0A(14, v112);
    v42 = v41;
    v43 = 392;
  }
  v44 = v98;
  v45 = sub_7A990(v43);
  v46 = v42;
  goto LABEL_64;
}
// 88B05: control flows out of bounds to 87638
// 88192: variable 'v22' is possibly undefined
// 882FB: variable 'v27' is possibly undefined
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199CAE: using guessed type char byte_199CAE;
// 199F07: using guessed type char byte_199F07;
// 1B61E4: using guessed type int dword_1B61E4;


//----- (00088B0A) --------------------------------------------------------
void __fastcall sub_88B0A( int a1, int a2)
{
  int16_t v3; // cx
  int16_t v4; // di
  char v5[8]; // [esp+0h] [ebp-8h] BYREF

  v3 = sub_8F64C();
  v4 = sub_8F645();
  sub_8F6F8(v3, a1, a2, v5);
  sub_120DED(2, 1);
  sub_120D79(v3, (int)v5);
  sub_120E8C(v4);
  JUMPOUT(0x82ABB);
}
// 88B56: control flows out of bounds to 82ABB


