#include "orion_common.h"

/* Adresni rozsah: 0x64311 - 0x71C01  (200 funkci) */

//----- (00064311) --------------------------------------------------------
int sub_64311( int a1, int a2, int16_t *a3)
{
  int16_t i; // cx
  int16_t j; // di
  int16_t v7; // dx
  int16_t v8; // ax
  int16_t v9; // cx
  int result; // eax

  *a3 = 0;
  for ( i = 0; i < word_19999A; ++i )
  {
    if ( sub_7826A(i, a1) )
      *(_WORD *)(a2 + 2 * (*a3)++) = i;
  }
  for ( j = 0; ; ++j )
  {
    result = *a3 / 2;
    if ( result <= j )
      break;
    v7 = sub_1247A0(*a3) - 1;
    v8 = sub_1247A0(*a3) - 1;
    if ( v7 != v8 )
    {
      v9 = *(_WORD *)(a2 + 2 * v7);
      *(_WORD *)(a2 + 2 * v7) = *(_WORD *)(a2 + 2 * v8);
      *(_WORD *)(a2 + 2 * v8) = v9;
    }
  }
  return result;
}
// 19999A: using guessed type int16_t word_19999A;


//----- (00064395) --------------------------------------------------------
int sub_64395()
{
  return dword_192FD8 - 35000;
}
// 192FD8: using guessed type int dword_192FD8;


//----- (000643A0) --------------------------------------------------------
void sub_643A0( int a1)
{
  int16_t v1; // ax
  int16_t *v2; // edi
  int64_t v3; // rax
  char *v4; // edi
  int64_t v5; // rax
  int16_t *v6; // edi
  char *v7; // edi
  int16_t v8; // ax
  int16_t v9; // si
  int16_t v10; // ax
  int16_t v11; // cx
  int v12; // edx
  int v13; // eax
  int v14; // eax
  int16_t v15; // si
  int v16; // eax
  int16_t v17; // dx
  int16_t v18; // dx
  int16_t *v19; // [esp-4h] [ebp-3Ah]
  int16_t *v20; // [esp-4h] [ebp-3Ah]
  _BYTE v21[100]; // [esp+0h] [ebp-36h] BYREF
  char v22[20]; // [esp+64h] [ebp+2Eh] BYREF
  char v23[20]; // [esp+78h] [ebp+42h] BYREF
  _BYTE v24[16]; // [esp+8Ch] [ebp+56h] BYREF
  int16_t v25; // [esp+9Ch] [ebp+66h] BYREF
  int v26; // [esp+A0h] [ebp+6Ah]
  int v27; // [esp+A4h] [ebp+6Eh]
  int v28; // [esp+A8h] [ebp+72h]
  int v29; // [esp+ACh] [ebp+76h]
  int v30; // [esp+B0h] [ebp+7Ah]
  char v31; // [esp+B4h] [ebp+7Eh]

  sub_22F5C(a1);
  v31 = 0;
  v30 = 0;
  v2 = &word_18FF78;
  v29 = sub_645A4(v1);
  v3 = sprintf(&word_18FF78, aShipsBySize);
  do
  {
    HIDWORD(v3) = ((uint64_t)sprintf(v23, "%2d ", word_19918C[SWORD2(v3)]) >> 32) + 1;
    v19 = v2;
    v4 = (char *)v2 - 1;
    do
      ++v4;
    while ( *v4 );
    strcpy(v4, v23);
    v2 = v19;
  }
  while ( SWORD2(v3) < 9 );
  v5 = sprintf(v19, aShipsDeployedB);
  v6 = &word_18FF78;
  do
  {
    HIDWORD(v5) = ((uint64_t)sprintf(v22, "%2d ", word_19919E[SWORD2(v5)]) >> 32) + 1;
    v20 = v6;
    v7 = (char *)v6 - 1;
    do
      ++v7;
    while ( *v7 );
    strcpy(v7, v22);
    v6 = v20;
  }
  while ( SWORD2(v5) < 9 );
  v26 = v29 + 500;
  while ( !v31 )
  {
    memset(&v25, -1, 4);
    sub_6478D();
    v9 = v8;
    if ( v8 < 0 )
    {
      v31 = 1;
    }
    else
    {
      sub_5514C((int)v21, v8);
      if ( (_WORD)v30 )
      {
        v11 = sub_100010(8, v21, v27, v28);
      }
      else
      {
        v10 = sub_A1762(v29, 8, v21, 1);
        v11 = v10;
        if ( v10 == -1 )
          break;
        v12 = 129 * v10;
        v13 = v12 + dword_197F9C;
        LOWORD(v12) = *(_WORD *)(v12 + dword_197F9C + 103);
        LOWORD(v13) = *(_WORD *)(v13 + 105);
        v27 = v12;
        v28 = v13;
      }
      if ( v11 == -1 )
      {
        v31 = 1;
      }
      else
      {
        v14 = v9;
        v15 = v29;
        ++word_19919E[v14];
        v25 = v11;
        sub_FF799(&v25, v15, v24);
        if ( v24[5] )
        {
          sub_FFD08(&v25, v15, v24);
          v16 = dword_197F9C + 129 * v11;
          v17 = v26;
          *(_BYTE *)(v16 + 100) = 1;
          *(_WORD *)(v16 + 101) = v17;
          v18 = word_17D17E;
          *(_BYTE *)(v16 + 113) = 2;
          *(_WORD *)(v16 + 114) = v18 + 1;
        }
      }
      if ( (int16_t)v30 >= 5 || v11 == -1 )
        v31 = 1;
      ++v30;
    }
  }
  JUMPOUT(0x63FC5);
}
// 6459F: control flows out of bounds to 63FC5
// 643B9: variable 'v1' is possibly undefined
// 64492: variable 'v8' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 17D17E: using guessed type int16_t word_17D17E;
// 18FF78: using guessed type int16_t word_18FF78;
// 197F9C: using guessed type int dword_197F9C;
// 19918C: using guessed type int16_t word_19918C[9];
// 19919E: using guessed type int16_t word_19919E[9];


//----- (000645A4) --------------------------------------------------------
int sub_645A4( int a1)
{
  int v1; // ecx
  int16_t i; // dx
  _BYTE v4[144]; // [esp+0h] [ebp-94h] BYREF
  int16_t v5; // [esp+90h] [ebp-4h] BYREF

  v1 = -1;
  sub_64311(a1, (int)v4, &v5);
  for ( i = 0; i < v5; ++i )
  {
    if ( sub_1247A0(i + 1) == 1 )
    {
      v1 = 2 * i;
      LOWORD(v1) = *(_WORD *)&v4[v1];
    }
  }
  return v1;
}


//----- (000645EC) --------------------------------------------------------
char sub_645EC()
{
  int v0; // edx
  int v1; // eax
  int v2; // edx
  int v3; // ebx
  int16_t v4; // ax
  int16_t v5; // si
  int v6; // ecx

  v0 = dword_192FD8;
  LOWORD(v1) = sub_63E4C();
  v2 = v0 - 35000 - (int16_t)v1;
  if ( v2 > 0 )
  {
    v1 = v2 / 25;
    if ( !(v2 % 25) )
    {
      v3 = v2 / 25;
      v4 = 100;
      if ( byte_199CB0 == 3 )
      {
        v4 = 150;
      }
      else if ( byte_199CB0 == 4 )
      {
        v4 = 200;
      }
      v5 = 100;
      if ( byte_199CB0 == 3 )
      {
        v5 = 150;
      }
      else if ( byte_199CB0 == 4 )
      {
        v5 = 200;
      }
      word_199176 += (v3 * v4 + 99) / 100;
      v6 = (v3 * v5 + 99) / 100;
      LOBYTE(v1) = sub_646BD();
      if ( (_BYTE)v1 )
        word_199176 += v6;
      else
        word_199178 += v6;
    }
  }
  return v1;
}
// 192FD8: using guessed type int dword_192FD8;
// 199176: using guessed type int16_t word_199176;
// 199178: using guessed type int16_t word_199178;
// 199CB0: using guessed type char byte_199CB0;


//----- (000646BD) --------------------------------------------------------
char sub_646BD()
{
  char v0; // dl
  int16_t i; // bx

  v0 = 1;
  for ( i = 0; i < 9 && v0; ++i )
  {
    if ( byte_181746[i] && (uint8_t)byte_181746[i] > word_19917A[i] )
      v0 = 0;
  }
  return v0;
}
// 19917A: using guessed type int16_t word_19917A[4];


//----- (000646F9) --------------------------------------------------------
int sub_646F9( int a1)
{
  int v2; // eax
  int16_t v3; // bx
  int result; // eax
  int v5; // eax
  int16_t v6; // bx

  v2 = word_19917A[a1] - 1;
  if ( v2 <= 0 )
    LOWORD(v2) = 0;
  v3 = v2;
  result = 2 * a1;
  *(int16_t *)((char *)word_19917A + result) = v3;
  if ( *(int16_t *)((char *)word_19918C + result) > 0 )
  {
    v5 = word_19918C[a1] - 1;
    if ( v5 <= 0 )
      LOWORD(v5) = 0;
    v6 = v5;
    result = a1;
    word_19918C[a1] = v6;
    ++word_19917A[a1];
  }
  return result;
}
// 19917A: using guessed type int16_t word_19917A[4];
// 19918C: using guessed type int16_t word_19918C[9];


//----- (0006474B) --------------------------------------------------------
int sub_6474B( int a1)
{
  int v2; // eax
  int16_t v3; // ax
  int16_t v4; // bx
  int16_t v5; // dx
  int result; // eax

  v2 = word_19918C[a1] - 1;
  if ( v2 <= 0 )
    LOWORD(v2) = 0;
  word_19918C[a1] = v2;
  v3 = word_19919E[a1] - 1;
  v4 = a1;
  if ( word_19919E[a1] - 1 <= 0 )
    v3 = 0;
  v5 = v3;
  result = v4;
  word_19919E[v4] = v5;
  return result;
}
// 19918C: using guessed type int16_t word_19918C[9];
// 19919E: using guessed type int16_t word_19919E[9];


//----- (0006478D) --------------------------------------------------------
void sub_6478D()
{
  int16_t v0; // bx
  int16_t i; // dx
  int16_t v2; // ax

  v0 = -1;
  for ( i = 8; i >= 0 && v0 == -1; --i )
  {
    v2 = word_19918C[i] - word_19919E[i];
    if ( word_19918C[i] - word_19919E[i] <= 0 )
      v2 = 0;
    if ( v2 > 0 )
      v0 = i;
  }
  JUMPOUT(0x63E00);
}
// 647D2: control flows out of bounds to 63E00
// 19918C: using guessed type int16_t word_19918C[9];
// 19919E: using guessed type int16_t word_19919E[9];


//----- (000647D7) --------------------------------------------------------
int sub_647D7()
{
  int16_t v0; // ax

  v0 = 100;
  if ( byte_199CB0 == 3 )
  {
    v0 = 150;
  }
  else if ( byte_199CB0 == 4 )
  {
    v0 = 200;
  }
  if ( (uint8_t)byte_199CB0 >= 3u )
    return 12500 / v0;
  else
    return 100;
}
// 199CB0: using guessed type char byte_199CB0;


//----- (0006481B) --------------------------------------------------------
int sub_6481B()
{
  int16_t v0; // ax

  v0 = 100;
  if ( byte_199CB0 == 3 )
  {
    v0 = 150;
  }
  else if ( byte_199CB0 == 4 )
  {
    v0 = 200;
  }
  if ( (uint8_t)byte_199CB0 >= 3u )
    return 20000 / v0;
  else
    return 199;
}
// 199CB0: using guessed type char byte_199CB0;


//----- (0006485F) --------------------------------------------------------
int16_t sub_6485F( int result)
{
  int16_t v1; // dx

  v1 = word_19919E[result] - 1;
  if ( word_19919E[result] - 1 <= 0 )
    v1 = 0;
  word_19919E[result] = v1;
  return result;
}
// 19919E: using guessed type int16_t word_19919E[9];


//----- (00064883) --------------------------------------------------------
char sub_64883(int a1, char *a2, char *a3, int a4)
{
  int v4; // eax
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  _BOOL1 v8; // zf
  _BYTE v11[64]; // [esp+4h] [ebp-4Ch] BYREF
  char v12[8]; // [esp+44h] [ebp-Ch] BYREF
  int v13; // [esp+4Ch] [ebp-4h]

  v13 = a4;
  v4 = 0;
  do
  {
    v5 = (int16_t)v4++;
    v11[v5] = 32;
  }
  while ( (int16_t)v4 < 64 );
  v11[63] = 0;
  sub_121CE5(0, 0, (int)v11);
  itoa(v13, v12, 10, a4);
  v6 = strlen(a3) + strlen(a2) + strlen(v12);
  if ( (int16_t)v6 <= 56 )
    sprintf(byte_19B89C, "Assert (%s) failed in %s at %d", a2, a3, v13);
  else
    sprintf(byte_19B89C, "Assert failed in %s at %d", a3, v13);
  sub_121CE5(0, 0, (int)byte_19B89C);
  byte_199F09 = 117;
  LOBYTE(v7) = sub_6497C();
  if ( (uint8_t)v7 < 0x44u )
  {
    if ( (uint8_t)v7 >= 9u )
    {
      if ( (uint8_t)v7 <= 9u )
      {
        LOBYTE(v7) = sub_1101F0(v7, 0, (int)byte_19B89C, v6);
      }
      else if ( (_BYTE)v7 == 27 )
      {
        goto LABEL_17;
      }
    }
  }
  else
  {
    if ( (uint8_t)v7 > 0x44u )
    {
      if ( (uint8_t)v7 < 0x64u )
      {
        v8 = (_BYTE)v7 == 81;
LABEL_11:
        if ( !v8 )
          goto LABEL_20;
LABEL_17:
        sub_126487(byte_19B89C, 0);
      }
      if ( (uint8_t)v7 > 0x64u )
      {
        v8 = (_BYTE)v7 == 113;
        goto LABEL_11;
      }
    }
    hr_debugbreak();
  }
LABEL_20:
  byte_199F09 = 0;
  return v7;
}
// 64969: variable 'v7' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 199F09: using guessed type char byte_199F09;


//----- (0006497C) --------------------------------------------------------
char sub_6497C()
{
  int v0; // eax
  char v1; // cl

  sub_121CE5(0, 24, (int)asc_1791A9);
  v0 = sub_12C574();
  v1 = v0;
  if ( (v0 == 27 || v0 == 81 || v0 == 113) && byte_199F09 != 117 )
    sub_12643D(v0, 24);
  if ( v0 == 9 )
    sub_1101F0(9, 24, (int)asc_1791A9, 9);
  sub_121CE5(0, 24, (int)asc_1791AB);
  return v1;
}
// 199F09: using guessed type char byte_199F09;


//----- (00064A02) --------------------------------------------------------
unsigned int sub_64A02(uint16_t *a1, _WORD *a2, _WORD *a3)
{
  int v3; // ecx
  int16_t v4; // di
  uint16_t v5; // ax
  _WORD *v6; // esi
  int16_t v7; // cx
  unsigned int result; // eax
  int16_t v10; // [esp+14h] [ebp-10h]
  int v11; // [esp+18h] [ebp-Ch]
  int v12; // [esp+20h] [ebp-4h]

  v12 = 0;
  v3 = 0;
  if ( (uint16_t)word_199860 >= 2u && ((uint16_t)word_199860 <= 2u || word_199860 == 8) )
    v3 = dword_19275C;
  v10 = *(_WORD *)(v3 + 2);
  v4 = 0;
  v11 = 0;
  while ( v4 < *(int16_t *)(dword_1975C4 + 8) )
  {
    if ( word_18B0E0[v4] == -1 )
    {
      word_192738[v4] = -1000;
    }
    else
    {
      word_192738[v4] = sub_11438B(
                          word_19B96C + 10,
                          v11 + v10 + word_19B96E + 18,
                          word_19B96C + 600,
                          v11 + v10 + word_19B96E + 18 + 13,
                          &unk_1791B0,
                          41);
      ++v12;
      v11 += 14;
    }
    ++v4;
  }
  v5 = (uint16_t)sub_1151B0(
                           word_19B974 + word_19B96C - *(_WORD *)dword_192788 - 35,
                           word_19B97A + word_19B96E - *(_WORD *)(dword_192788 + 2) - 16,
                           (int)&unk_1791B0,
                           (_WORD *)dword_192788,
                           asc_1791B1,
                           40);
  v6 = (_WORD *)dword_1927C4;
  v7 = word_19B97A + word_19B96E;
  *a1 = v5;
  *a3 = sub_11438B(word_19B96C, word_19B96E, *v6 + word_19B96C, v7, &unk_1791B0, 0);
  result = sub_11438B(0, 0, 639, 479, asc_1791B1, 41);
  *a2 = result;
  return result;
}
// 18B0E0: using guessed type int16_t word_18B0E0[40];
// 192738: using guessed type int16_t word_192738[10];
// 19275C: using guessed type int dword_19275C;
// 192788: using guessed type int dword_192788;
// 1927C4: using guessed type int dword_1927C4;
// 1975C4: using guessed type int dword_1975C4;
// 199860: using guessed type int16_t word_199860;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;
// 19B974: using guessed type int16_t word_19B974;
// 19B97A: using guessed type int16_t word_19B97A;


//----- (00064B94) --------------------------------------------------------
void sub_64B94(int a1, int a2, int a3)
{
  int v3; // eax
  int v4; // edx
  int v5; // ebx
  int v6; // esi
  int v7; // edx
  int v8; // edi
  int16_t v9; // ax
  int v10; // eax
  char *v11; // eax
  char *v12; // edx
  int v13; // eax
  int16_t v14; // dx
  int16_t v15; // bx
  int v16; // edi
  int v17; // eax
  int v18; // edi
  int16_t v19; // dx
  int16_t v20; // bx
  int16_t v21; // ax
  int16_t v22; // ax
  int16_t v23; // dx
  int16_t v24; // cx
  int16_t v25; // dx
  int16_t v26; // bx
  int v27; // edi
  int16_t v28; // ax
  int16_t v29; // dx
  uint16_t v30; // ax
  int16_t v31; // dx
  int16_t v32; // ax
  int16_t v33; // bx
  uint16_t v34; // ax
  int16_t v35; // cx
  int16_t v36; // dx
  int16_t v37; // ax
  int v38; // edx
  _WORD *v39; // [esp+0h] [ebp-86h]
  _WORD *v40; // [esp+0h] [ebp-86h]
  _WORD *v41; // [esp+4h] [ebp-82h]
  uint16_t *v42; // [esp+4h] [ebp-82h]
  char v43[80]; // [esp+8h] [ebp-7Eh] BYREF
  _WORD v44[16]; // [esp+58h] [ebp-2Eh] BYREF
  int16_t v45[16]; // [esp+78h] [ebp-Eh] BYREF
  _WORD v46[16]; // [esp+98h] [ebp+12h] BYREF
  _DWORD v47[2]; // [esp+B8h] [ebp+32h]
  int16_t v48; // [esp+C0h] [ebp+3Ah]
  int v49; // [esp+C4h] [ebp+3Eh]
  int v50; // [esp+C8h] [ebp+42h]
  int v51; // [esp+CCh] [ebp+46h]
  char *v52; // [esp+D0h] [ebp+4Ah]
  int v53; // [esp+D4h] [ebp+4Eh]
  int v54; // [esp+D8h] [ebp+52h]
  int v55; // [esp+DCh] [ebp+56h]
  int v56; // [esp+E0h] [ebp+5Ah]
  int v57; // [esp+E4h] [ebp+5Eh]
  int v58; // [esp+E8h] [ebp+62h]
  int v59; // [esp+ECh] [ebp+66h]
  int v60; // [esp+F0h] [ebp+6Ah]
  int v61; // [esp+F4h] [ebp+6Eh]
  int v62; // [esp+F8h] [ebp+72h]
  int v63; // [esp+FCh] [ebp+76h]
  int v64; // [esp+100h] [ebp+7Ah]
  int v65; // [esp+104h] [ebp+7Eh]

  v47[0] = 327682;
  v47[1] = 983050;
  v48 = 20;
  LOWORD(v3) = *(_WORD *)(dword_19280C + 2);
  if ( *(int16_t *)(dword_1975C4 + 8) >= 7 )
    v3 = (int16_t)v3;
  else
    v3 = 102;
  word_19B964 = -1000;
  v58 = 0;
  HIWORD(v6) = HIWORD(dword_1927C4);
  HIWORD(v4) = HIWORD(dword_1927C8);
  LOWORD(a3) = word_19B96C;
  v65 = v3;
  v5 = a3 + 22;
  LOWORD(v6) = *(_WORD *)(dword_1927C4 + 2);
  LOWORD(v3) = *(_WORD *)(dword_1927C8 + 2);
  LOWORD(v4) = word_19B96E;
  v56 = v3;
  v7 = v6 + v4;
  v62 = v6;
  *v41 = -1000;
  v8 = v7 + 31;
  *v39 = -1000;
  sub_654EA();
  v61 = v7 + 19;
  v57 = v5 + 576;
  v54 = v5 + 6;
  while ( 1 )
  {
    v10 = *(int16_t *)(dword_1975C4 + 8) >= 10 ? 10 : *(int16_t *)(dword_1975C4 + 8);
    v50 = (int16_t)v58;
    if ( v10 <= (int16_t)v58 )
      break;
    ++v58;
    v9 = sub_11438B(v54, v61, v57, v8, &unk_1791B0, 41);
    v61 += 14;
    v8 += 14;
    word_192738[v50] = v9;
  }
  word_19B964 = -1000;
  if ( *(int16_t *)(dword_1975C4 + 8) <= 10 )
    word_19B968 = -1000;
  else
    word_19B968 = (uint16_t)sub_1151B0(
                                      word_19B974 + word_19B96C - 32,
                                      v6 + word_19B96E + 1,
                                      (int)&unk_1791B0,
                                      (_WORD *)dword_192800,
                                      asc_1791B3,
                                      40);
  if ( *(int16_t *)(dword_1975C4 + 8) <= 10 )
    word_19B964 = -1000;
  else
    word_19B964 = sub_115478(
                    word_19B96C + 605,
                    v6 + word_19B96E + 20,
                    0,
                    120,
                    0,
                    120,
                    9,
                    120,
                    dword_1975C4,
                    &unk_1791B0,
                    0);
  v11 = (char *)(v65 - 9);
  v62 += v65 - 9;
  if ( *(int16_t *)(dword_1975C4 + 8) <= 10 )
  {
    word_19B970 = -1000;
  }
  else
  {
    v11 = sub_1151B0(
            word_19B974 + word_19B96C - 32,
            v65 + v6 + word_19B96E - 14,
            (int)&unk_1791B0,
            (_WORD *)dword_192760,
            asc_1791B5,
            40);
    word_19B970 = (int16_t)v11;
  }
  LOWORD(v11) = word_19B96E;
  v12 = &v11[v6 + v65];
  v52 = v12 + 10;
  word_199842 = sub_11438B(word_19B96C + 102, (_WORD)v12 + 10, word_19B96C + 197, (_WORD)v12 + 34, aB, 41);
  v49 = (int16_t)((_WORD)v12 + 34);
  word_199846 = sub_11438B(word_19B96C + 204, (_WORD)v12 + 10, word_19B96C + 319, (_WORD)v12 + 34, aM, 41);
  word_199844 = sub_11438B(word_19B96C + 326, (_WORD)v12 + 10, word_19B96C + 422, v49, aO, 41);
  word_199840 = sub_11438B(word_19B96C + 429, (_WORD)v12 + 10, word_19B96C + 527, v49, aS_0, 41);
  if ( word_19B972 > -1 )
  {
    v13 = 6 * word_19B972;
    v64 = 0;
    v59 = 0;
    LOWORD(v13) = *(_WORD *)(dword_192694 + v13);
    v60 = 0;
    v55 = v13;
    do
    {
      v14 = v55;
      v15 = sub_6EFEB(v55);
      if ( sub_6EDAE(v14) )
      {
        v16 = (int16_t)v64;
        v17 = sub_6EE8E(word_19999C, v14, 1, word_19B976, *((_WORD *)v47 + (int16_t)v64), word_19B966);
        LOWORD(v17) = word_19B96C;
        v53 = v17 + 119;
        LOWORD(v17) = v60 + v65 + v6 + word_19B96E + 70 + 14;
        word_1991D4[v16] = sub_11438B(v53, v17, word_19B96C + 204, v17 + 15, &unk_1791B0, 41);
        byte_19B980[v16] = 1;
      }
      else if ( word_19B972 <= -1 || v15 )
      {
        word_19B978 = 0;
      }
      else
      {
        v18 = (int16_t)v64;
        v19 = v65 + v6 + word_19B96E + 70 + 14 + v59;
        v20 = word_19B96C;
        sub_66810(v64);
        v20 += 119;
        v51 = (int16_t)(v20 + 92);
        v21 = sub_11438B(v20, v19, v20 + 92, v19 + 13, &unk_1791B0, 41);
        word_19B978 = 0;
        byte_19B980[v18] = 1;
        word_1991DE[v18] = v21;
      }
      v59 += 16;
      ++v64;
      v60 += 15;
    }
    while ( (int16_t)v64 < 5 );
  }
  v22 = v65 + v6 + word_19B96E + 70;
  v23 = word_19B96C + 29 + *(_WORD *)dword_1927E0;
  v24 = v22 + *(_WORD *)(dword_1927E0 + 2);
  v51 = v22;
  word_19B97E = sub_11438B(word_19B96C + 29, v22, v23, v24, &unk_1791B0, 41);
  memset(v45, 0, 30);
  memset(v46, 0, 30);
  memset(v44, 0, 30);
  sub_6908A((int)byte_19B985);
  v63 = 1;
  sub_6649D(v45, (int)v46, (int)v44);
  while ( 1 )
  {
    v25 = v6 + word_19B96E + v65;
    v26 = word_19B96C;
    if ( word_19B972 > -1 )
    {
      v27 = (int16_t)v63;
      if ( sub_6678C(v63) )
      {
        if ( sub_6825F(v27) )
        {
          v28 = v25 + v44[v27];
          v51 = (int16_t)(v28 + 13);
          v29 = v46[v27];
          v49 = v28;
          word_1991E8[v27] = sub_11438B(v26 + v29, v28, v26 + v29 + 140, v28 + 13, &unk_1791B0, 41);
        }
      }
    }
    if ( (int16_t)++v63 >= 15 )
    {
      v30 = (uint16_t)sub_1151B0(
                                word_19B96C + 537,
                                v62 + word_19B96E + 91,
                                (int)&unk_1791B0,
                                (_WORD *)dword_192804,
                                asc_1791B1,
                                40);
      *v42 = v30;
      v31 = sub_691A3(v43);
      v32 = word_19B96C + 538;
      v33 = v62 + word_19B96E + 139;
      if ( v31 )
      {
        v34 = (uint16_t)sub_1151B0(v32, v33, (int)&unk_1791B0, (_WORD *)dword_1927D8, aA_0, 40);
      }
      else
      {
        v35 = v33 + *(_WORD *)(dword_1927D8 + 2);
        v36 = v32 + *(_WORD *)dword_1927D8;
        v51 = v33;
        v34 = sub_11438B(v32, v33, v36, v35, &unk_1791B0, 41);
      }
      word_199848 = v34;
      sub_11438B(
        word_19B96C,
        word_19B96E,
        *(_WORD *)dword_1927C4 + word_19B96C,
        v56 + v65 + v6 + word_19B96E,
        &unk_1791B0,
        0);
      v37 = sub_11438B(0, 0, 639, 479, asc_1791B1, 41);
      *v40 = v37;
      v38 = dword_1975C4;
      *(_WORD *)(dword_1975C4 + 16) = word_19B968;
      *(_WORD *)(v38 + 18) = word_19B970;
      JUMPOUT(0x672E8);
    }
  }
}
// 65283: control flows out of bounds to 672E8
// 64C17: variable 'v41' is possibly undefined
// 64C28: variable 'v39' is possibly undefined
// 6518A: variable 'v42' is possibly undefined
// 65266: variable 'v40' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192694: using guessed type int dword_192694;
// 192738: using guessed type int16_t word_192738[10];
// 192760: using guessed type int dword_192760;
// 1927C4: using guessed type int dword_1927C4;
// 1927C8: using guessed type int dword_1927C8;
// 1927D8: using guessed type int dword_1927D8;
// 1927E0: using guessed type int dword_1927E0;
// 192800: using guessed type int dword_192800;
// 192804: using guessed type int dword_192804;
// 19280C: using guessed type int dword_19280C;
// 1975C4: using guessed type int dword_1975C4;
// 1991D4: using guessed type int16_t word_1991D4[5];
// 1991DE: using guessed type int16_t word_1991DE[5];
// 1991E8: using guessed type int16_t word_1991E8[15];
// 199840: using guessed type int16_t word_199840;
// 199842: using guessed type int16_t word_199842;
// 199844: using guessed type int16_t word_199844;
// 199846: using guessed type int16_t word_199846;
// 199848: using guessed type int16_t word_199848;
// 19999C: using guessed type int16_t word_19999C;
// 19B964: using guessed type int16_t word_19B964;
// 19B966: using guessed type int16_t word_19B966;
// 19B968: using guessed type int16_t word_19B968;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;
// 19B970: using guessed type int16_t word_19B970;
// 19B972: using guessed type int16_t word_19B972;
// 19B974: using guessed type int16_t word_19B974;
// 19B976: using guessed type int16_t word_19B976;
// 19B978: using guessed type int16_t word_19B978;
// 19B97E: using guessed type int16_t word_19B97E;


//----- (00065288) --------------------------------------------------------
int16_t sub_65288(_WORD *a1, _WORD *a2)
{
  int16_t v2; // di
  int16_t v3; // si
  int16_t v4; // ax
  int v5; // eax
  int16_t v6; // ax
  int v7; // ecx
  int16_t result; // ax
  int v10; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]
  int16_t v12; // [esp+14h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  v12 = 0;
  for ( i = 0; ; i += 16 )
  {
    v5 = *(int16_t *)(dword_1975C4 + 8) >= 10 ? 10 : *(int16_t *)(dword_1975C4 + 8);
    v10 = v12;
    if ( v5 <= v12 )
      break;
    v4 = sub_11438B(
           word_19B96C + 25,
           i + word_19B96E + 89,
           word_19B96C + 584,
           i + word_19B96E + 89 + 16,
           &unk_1791B0,
           41);
    ++v12;
    word_192738[v10] = v4;
  }
  word_19B964 = -1000;
  if ( *(int16_t *)(dword_1975C4 + 8) <= 10 )
  {
    word_19B964 = -1000;
  }
  else
  {
    v2 = word_19B96C + 602;
    v3 = word_19B96E + 93;
    word_19B964 = sub_115478(word_19B96C + 602, word_19B96E + 93, 0, 140, 0, 140, 9, 140, dword_1975C4, &unk_1791B0, 0);
  }
  if ( *(int16_t *)(dword_1975C4 + 8) <= 10 || v2 <= 0 || v3 <= 0 )
  {
    word_199862 = -1000;
    word_199850 = -1000;
    word_19B964 = -1000;
  }
  else
  {
    word_199862 = (uint16_t)sub_1151B0(
                                      v2,
                                      v3 - *(_WORD *)(dword_192800 + 2) - 3,
                                      (int)&unk_1791B0,
                                      (_WORD *)dword_192800,
                                      asc_1791B3,
                                      40);
    word_199850 = (uint16_t)sub_1151B0(
                                      v2,
                                      v3 + *(_WORD *)(dword_192698 + 2) + 3,
                                      (int)&unk_1791B0,
                                      (_WORD *)dword_192760,
                                      asc_1791B5,
                                      40);
  }
  *a1 = (uint16_t)sub_1151B0(
                            word_19B974 + word_19B96C - *(_WORD *)dword_192788 - 35,
                            word_19B97A + word_19B96E - *(_WORD *)(dword_192788 + 2) - 16,
                            (int)&unk_1791B0,
                            (_WORD *)dword_192788,
                            asc_1791B1,
                            40);
  sub_11438B(word_19B96C, word_19B96E, word_19B974 + word_19B96C, word_19B97A + word_19B96E, &unk_1791B0, 0);
  v6 = sub_11438B(0, 0, 639, 479, &unk_1791B0, 41);
  v7 = dword_1975C4;
  *a2 = v6;
  *(_WORD *)(v7 + 16) = word_199862;
  result = word_199850;
  *(_WORD *)(v7 + 18) = word_199850;
  return result;
}
// 192698: using guessed type int dword_192698;
// 192738: using guessed type int16_t word_192738[10];
// 192760: using guessed type int dword_192760;
// 192788: using guessed type int dword_192788;
// 192800: using guessed type int dword_192800;
// 1975C4: using guessed type int dword_1975C4;
// 199850: using guessed type int16_t word_199850;
// 199862: using guessed type int16_t word_199862;
// 19B964: using guessed type int16_t word_19B964;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;
// 19B974: using guessed type int16_t word_19B974;
// 19B97A: using guessed type int16_t word_19B97A;


//----- (000654DD) --------------------------------------------------------
int16_t sub_654DD( int a1)
{
  return (uint8_t)byte_17E085[13 * a1];
}


//----- (000654EA) --------------------------------------------------------
int sub_654EA()
{
  int v0; // eax
  int v1; // edx
  int v2; // edx
  int v3; // eax
  int result; // eax
  int v5; // edx

  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    word_192738[v1] = -1000;
  }
  while ( (int16_t)v0 < 10 );
  v2 = 0;
  do
  {
    v3 = (int16_t)v2++;
    word_1991DE[v3] = -1000;
    word_1991D4[v3] = -1000;
  }
  while ( (int16_t)v2 < 5 );
  result = 0;
  do
  {
    v5 = (int16_t)result++;
    word_1991E8[v5] = -1000;
  }
  while ( (int16_t)result < 15 );
  return result;
}
// 192738: using guessed type int16_t word_192738[10];
// 1991D4: using guessed type int16_t word_1991D4[5];
// 1991DE: using guessed type int16_t word_1991DE[5];
// 1991E8: using guessed type int16_t word_1991E8[15];


//----- (00065539) --------------------------------------------------------
void sub_65539(int a1, int a2, int16_t *a3)
{
  int v3; // eax

  sub_124D41();
  v3 = sub_6C6CD();
  sub_1077D(v3, a1, a2, a3);
  sub_124DEC();
  sub_128BE7();
  sub_12B65C();
  sub_133237();
  sub_1318D4(0, 255);
  sub_124D41();
  JUMPOUT(0x6557A);
}
// 65575: control flows out of bounds to 6557A


//----- (0006558C) --------------------------------------------------------
char sub_6558C( int a1, int a2, int a3, int a4)
{
  int16_t v5; // ax
  char v6; // bl
  int v7; // esi
  int16_t v8; // dx
  char result; // al
  int16_t i; // si
  int v11; // ebx
  char *v12; // esi
  int v13; // ebx
  char v14[1332]; // [esp+0h] [ebp-5A4h] BYREF
  char v15[100]; // [esp+534h] [ebp-70h] BYREF
  int v16; // [esp+598h] [ebp-Ch]
  int v17; // [esp+59Ch] [ebp-8h]
  int v18; // [esp+5A0h] [ebp-4h]

  v18 = a3;
  v17 = a4;
  v5 = -1;
  v6 = 0;
  v7 = -a2;
  v8 = -1;
  if ( a1 == v7 )
  {
    if ( (uint16_t)word_199860 >= 2u )
    {
      if ( (uint16_t)word_199860 <= 2u )
      {
        v5 = 683;
      }
      else if ( word_199860 == 8 )
      {
        v5 = 686;
      }
    }
  }
  else if ( a1 == -(int16_t)v18 )
  {
    if ( (uint16_t)word_199860 >= 2u )
    {
      if ( (uint16_t)word_199860 <= 2u )
      {
        v5 = 682;
      }
      else if ( word_199860 == 8 )
      {
        v5 = 685;
      }
    }
  }
  else if ( a1 == -(int16_t)v17 && (uint16_t)word_199860 >= 2u )
  {
    if ( (uint16_t)word_199860 <= 2u )
    {
      v5 = 681;
    }
    else if ( word_199860 == 8 )
    {
      v5 = 684;
    }
  }
  if ( v5 != -1 )
    return sub_A59A1();
  for ( i = 0; ; ++i )
  {
    result = dword_1975C4;
    if ( i >= *(int16_t *)(dword_1975C4 + 8) || v6 )
      break;
    v16 = -word_192738[i];
    if ( a1 == v16 && word_18B0E0[i] != -1 )
    {
      v6 = 1;
      v8 = word_18B0E0[i];
    }
  }
  if ( v6 && !v8 )
    return sub_A59A1();
  if ( v6 && v8 > 0 )
  {
    result = word_199860;
    v14[0] = 0;
    if ( (uint16_t)word_199860 < 2u )
      goto LABEL_42;
    if ( (uint16_t)word_199860 <= 2u )
    {
      v11 = 59 * v8;
      sub_6FBEA(v14, *(int16_t *)((char *)&word_17F6A7 + v11));
      v12 = *(char **)((char *)&off_17F6A1 + v11);
    }
    else
    {
      if ( word_199860 != 8 )
      {
LABEL_42:
        if ( v14[0] )
          return sub_A5EB2((int)v15, (int)v14);
        return result;
      }
      v13 = 11 * v8;
      sub_6FBEA(v14, word_17FDF2[v13]);
      v12 = *(char **)((char *)&off_17FDEC + v13 * 2);
    }
    strcpy(v15, v12);
    goto LABEL_42;
  }
  return result;
}
// 17F6A1: using guessed type _UNKNOWN *off_17F6A1;
// 17F6A7: using guessed type int16_t word_17F6A7;
// 17FDEC: using guessed type _UNKNOWN *off_17FDEC;
// 17FDF2: using guessed type int16_t word_17FDF2[];
// 18B0E0: using guessed type int16_t word_18B0E0[40];
// 192738: using guessed type int16_t word_192738[10];
// 1975C4: using guessed type int dword_1975C4;
// 199860: using guessed type int16_t word_199860;


//----- (00065758) --------------------------------------------------------
void sub_65758()
{
  int16_t v0; // di
  int16_t v1; // si
  int16_t v2; // si

  v0 = word_19B96C;
  v1 = word_19B96E;
  if ( (uint16_t)word_199860 >= 2u && ((uint16_t)word_199860 <= 2u || word_199860 == 8) )
    sub_12A478(word_19B96C, word_19B96E, dword_19275C);
  v2 = *(_WORD *)(dword_19275C + 2) + v1;
  sub_128AB6(v0, v2, v0 + word_19B974, (int16_t)(v2 + word_19B96A));
  sub_12B634();
  sub_12A478(v0, v2, dword_192780);
  sub_12B65C();
  sub_128BE7();
  sub_12A478(v0, word_19B96A + v2, dword_19277C);
  if ( (uint16_t)word_199860 >= 2u )
  {
    if ( (uint16_t)word_199860 <= 2u )
    {
      sub_67312();
    }
    else if ( word_199860 == 8 )
    {
      sub_668FD();
    }
  }
  sub_24677(8, -1, 1);
  JUMPOUT(0x66268);
}
// 6584E: control flows out of bounds to 66268
// 19275C: using guessed type int dword_19275C;
// 19277C: using guessed type int dword_19277C;
// 192780: using guessed type int dword_192780;
// 199860: using guessed type int16_t word_199860;
// 19B96A: using guessed type int16_t word_19B96A;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;
// 19B974: using guessed type int16_t word_19B974;


//----- (00065853) --------------------------------------------------------
void sub_65853()
{
  int16_t v0; // cx
  int16_t v1; // si
  int16_t v2; // di
  int16_t v3; // si

  v0 = word_19B96C;
  v1 = word_19B96E;
  v2 = word_19B96C;
  sub_12A478(word_19B96C, word_19B96E, dword_19275C);
  v3 = *(_WORD *)(dword_19275C + 2) + v1;
  sub_128AB6(v2, v3, word_19B974 + v0, (int16_t)(v3 + word_19B96A));
  sub_12B634();
  sub_12A478(v2, v3, dword_192780);
  sub_12B65C();
  sub_128BE7();
  sub_12A478(v2, word_19B96A + v3, dword_19277C);
  sub_6767F();
  if ( *(int16_t *)(dword_1975C4 + 8) > 10 && word_19B964 != -1000 )
    sub_A0226((int16_t *)dword_1975C4, (void (*)(_DWORD))sub_65923);
  JUMPOUT(0x6583A);
}
// 6591E: control flows out of bounds to 6583A
// 19275C: using guessed type int dword_19275C;
// 19277C: using guessed type int dword_19277C;
// 192780: using guessed type int dword_192780;
// 1975C4: using guessed type int dword_1975C4;
// 19B964: using guessed type int16_t word_19B964;
// 19B96A: using guessed type int16_t word_19B96A;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;
// 19B974: using guessed type int16_t word_19B974;


//----- (00065923) --------------------------------------------------------
void sub_65923(int a1)
{
  int v1; // eax
  int16_t v2; // di
  int v3; // edx
  int16_t v4; // si
  int16_t v5; // di
  int16_t v6; // [esp+0h] [ebp-1Ch] BYREF
  int v7; // [esp+4h] [ebp-18h]
  int v8; // [esp+8h] [ebp-14h]
  int v9; // [esp+Ch] [ebp-10h]
  int v10; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h]
  int v12; // [esp+18h] [ebp-4h]

  LOWORD(a1) = word_19B96C;
  v1 = a1 + 596;
  v11 = v1;
  LOWORD(v1) = word_19B96E;
  v1 += 92;
  v12 = v1;
  LOWORD(v1) = word_19B96E;
  v2 = word_19B96C;
  v7 = v1 + 93;
  sub_124075();
  sub_113F8C();
  sub_8FD71(&v6);
  sub_128AB6(v11, v12, *(_WORD *)dword_192698 + v11, (int16_t)(*(_WORD *)(dword_192698 + 2) + v12));
  sub_12B634();
  v3 = *(int16_t *)(dword_1975C4 + 14) - (*(int16_t *)dword_1975C4 + *(int16_t *)(dword_1975C4 + 6) / 2);
  v9 = 91;
  v4 = 0;
  v8 = v3 + v7;
  v5 = v2 + 602;
  v10 = v3 + v7 + 1;
  while ( 1 )
  {
    sub_134D2D(v5, (int16_t)v10, v5, (int16_t)(*(_WORD *)(dword_1975C4 + 6) + v8), v9);
    if ( !(v4 % 2) )
      --v9;
    ++v4;
    ++v5;
    if ( v4 >= 9 )
    {
      sub_12A478(v11, v12, dword_192698);
      sub_8FD56(v6);
      JUMPOUT(0x66268);
    }
  }
}
// 65A26: control flows out of bounds to 66268
// 192698: using guessed type int dword_192698;
// 1975C4: using guessed type int dword_1975C4;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;


//----- (00065A2B) --------------------------------------------------------
void sub_65A2B(int a1, int a2)
{
  int16_t v3; // di
  _BYTE v4[8]; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]

  memset(v4, 0, 5);
  if ( ((word_19B976 >> 1) & 1) != 0 )
  {
    v4[1] = 1;
  }
  else if ( ((word_19B976 >> 2) & 1) != 0 )
  {
    v4[2] = 1;
  }
  else if ( ((word_19B976 >> 3) & 1) != 0 )
  {
    v4[3] = 1;
  }
  else if ( ((word_19B976 >> 4) & 1) != 0 )
  {
    v4[4] = 1;
  }
  else
  {
    v4[0] = 1;
  }
  sub_12A478(a1 + 29, a2 + 70, dword_1927E0);
  v7 = a1 + 33;
  v3 = 0;
  v8 = a2 + 73;
  v6 = a1 + 119;
  v5 = a2 + 84;
  while ( 1 )
  {
    sub_12B753(dword_1927B0[v3], (uint8_t)v4[v3]);
    sub_12A478(v6, v5, dword_1927B0[v3]);
    if ( v4[v3] == 1 )
      sub_12A478(v7, v8, dword_19278C[v3]);
    ++v3;
    v5 += 16;
    if ( v3 >= 5 )
      JUMPOUT(0x654D7);
  }
}
// 65B20: control flows out of bounds to 654D7
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 19278C: using guessed type int dword_19278C[4];
// 1927B0: using guessed type int dword_1927B0[5];
// 1927E0: using guessed type int dword_1927E0;
// 19B976: using guessed type int16_t word_19B976;


//----- (00065B25) --------------------------------------------------------
void sub_65B25( int a1, int a2)
{
  int16_t v4; // cx
  int v5; // edx
  _WORD v6[16]; // [esp+0h] [ebp-60h] BYREF
  _WORD v7[16]; // [esp+20h] [ebp-40h] BYREF
  int16_t v8[16]; // [esp+40h] [ebp-20h] BYREF

  memset(v8, 0, 30);
  memset(v6, 0, 30);
  memset(v7, 0, 30);
  sub_12A478(a1 + 224, a2 + 70, dword_192778);
  v4 = 1;
  sub_6649D(v8, (int)v6, (int)v7);
  while ( 1 )
  {
    if ( word_19B972 > -1 && sub_6678C(v4) && sub_6825F(v4) )
    {
      if ( word_1991B6[v4] == 1 )
        v5 = 2;
      else
        v5 = byte_19B985[v4] == 1;
      sub_12B753(dword_18B260[v8[v4]], v5);
      sub_12A478(a1 + v6[v4], a2 + v7[v4], dword_18B260[v8[v4]]);
    }
    if ( ++v4 >= 15 )
      JUMPOUT(0x654D7);
  }
}
// 65C2D: control flows out of bounds to 654D7
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 18B260: using guessed type int dword_18B260[];
// 192778: using guessed type int dword_192778;
// 1991B6: using guessed type int16_t word_1991B6[];
// 19B972: using guessed type int16_t word_19B972;


//----- (00065C32) --------------------------------------------------------
void sub_65C32( int a1, int a2)
{
  int16_t v2; // si
  int16_t v3; // di
  int16_t v4; // si
  int16_t v5; // cx
  int v6; // edx
  int v7; // eax
  int v8; // ebx
  int16_t v9; // [esp+0h] [ebp-Ch]
  int16_t v10; // [esp+4h] [ebp-8h]

  v10 = a1 + 33;
  v2 = a1 + 127;
  sub_12A478(a1 + 29, a2 + 70, dword_1927E0);
  sub_12A478(v10, a2 + 73, dword_19279C);
  v3 = v2;
  v4 = a2 + 88;
  v5 = 0;
  while ( 1 )
  {
    v9 = v4;
    if ( v5 == word_19B978 )
    {
      v6 = 2;
      v7 = dword_192764[v5];
    }
    else
    {
      if ( !byte_19B980[v5] )
      {
        sub_12B726(dword_192764[v5]);
        goto LABEL_8;
      }
      v6 = 1;
      v7 = dword_192764[v5];
    }
    sub_12B753(v7, v6);
LABEL_8:
    v4 += 15;
    v8 = dword_192764[v5++];
    sub_12A478(v3, v9, v8);
    if ( v5 >= 5 )
      JUMPOUT(0x654D7);
  }
}
// 65CF5: control flows out of bounds to 654D7
// 192764: using guessed type int dword_192764[5];
// 19279C: using guessed type int dword_19279C;
// 1927E0: using guessed type int dword_1927E0;
// 19B978: using guessed type int16_t word_19B978;


//----- (00065CFA) --------------------------------------------------------
void sub_65CFA()
{
  int16_t v0; // di
  int16_t v1; // si
  int16_t v2; // ax
  int16_t v3; // cx
  int16_t v4; // cx
  int v5; // [esp+0h] [ebp-8h]
  int16_t v6; // [esp+4h] [ebp-4h]

  if ( *(int16_t *)(dword_1975C4 + 8) >= 7 )
    v0 = *(_WORD *)(dword_19280C + 2);
  else
    v0 = 102;
  v1 = *(_WORD *)(dword_1927C4 + 2);
  sub_12A478(word_19B96C, word_19B96E, dword_1927C4);
  v6 = v1 + word_19B96E;
  v5 = (int16_t)(v0 + v1 + word_19B96E);
  sub_128AB6(word_19B96C, v1 + word_19B96E, 639, v5);
  sub_12B634();
  sub_12A478(word_19B96C, v1 + word_19B96E, dword_19280C);
  sub_128AB6(word_19B96C, v6, 598, v5);
  sub_12B634();
  sub_66CEC();
  sub_128BE7();
  sub_12B65C();
  if ( word_19B964 != -1000 )
    sub_A0226((int16_t *)dword_1975C4, (void (*)(_DWORD))sub_65F33);
  sub_12A478(word_19B96C, v0 + v1 + word_19B96E, dword_1927C8);
  if ( word_19B972 > -1 && (v2 = sub_69529(word_19B972), sub_6EDAE(v2)) )
    sub_65C32(word_19B96C, v0 + v1 + word_19B96E);
  else
    sub_65A2B(word_19B96C, (int16_t)(v0 + v1 + word_19B96E));
  sub_65B25(word_19B96C, v0 + v1 + word_19B96E);
  v3 = word_19B96E + v1;
  sub_12B753(dword_1927D4, (uint8_t)byte_181750);
  v4 = v0 + v3 + 10;
  sub_12A478(word_19B96C + 102, v4, dword_1927D4);
  sub_12B753(dword_192808, (uint8_t)byte_181751);
  sub_12A478(word_19B96C + 204, v4, dword_192808);
  sub_12B753(dword_1927CC, (uint8_t)byte_181752);
  sub_12A478(word_19B96C + 326, v4, dword_1927CC);
  sub_12B753(dword_1927DC, (uint8_t)byte_181753);
  sub_12A478(word_19B96C + 429, v4, dword_1927DC);
  JUMPOUT(0x6583A);
}
// 65F2E: control flows out of bounds to 6583A
// 181750: using guessed type char byte_181750;
// 181751: using guessed type char byte_181751;
// 181752: using guessed type char byte_181752;
// 181753: using guessed type char byte_181753;
// 1927C4: using guessed type int dword_1927C4;
// 1927C8: using guessed type int dword_1927C8;
// 1927CC: using guessed type int dword_1927CC;
// 1927D4: using guessed type int dword_1927D4;
// 1927DC: using guessed type int dword_1927DC;
// 192808: using guessed type int dword_192808;
// 19280C: using guessed type int dword_19280C;
// 1975C4: using guessed type int dword_1975C4;
// 19B964: using guessed type int16_t word_19B964;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;
// 19B972: using guessed type int16_t word_19B972;


//----- (00065F33) --------------------------------------------------------
void sub_65F33()
{
  int v0; // eax
  int16_t v1; // di
  int16_t v2; // dx
  int16_t v3; // di
  int16_t v4; // si
  int v5; // [esp+4h] [ebp-18h]
  int v6; // [esp+8h] [ebp-14h]
  int16_t v7; // [esp+Ch] [ebp-10h]
  int16_t v8; // [esp+10h] [ebp-Ch]
  int16_t v9; // [esp+14h] [ebp-8h]
  int16_t v10; // [esp+18h] [ebp-4h] BYREF

  HIWORD(v0) = HIWORD(dword_1927C4);
  LOWORD(v0) = word_19B96E + *(_WORD *)(dword_1927C4 + 2);
  v1 = word_19B96C;
  v8 = v0 + 19;
  v5 = v0 + 20;
  v2 = word_19B96C;
  sub_113F8C();
  sub_124075();
  sub_8FD71(&v10);
  v7 = v2 + 605;
  v3 = v1 + 599;
  sub_128AB6(v3, v8, v3 + *(_WORD *)dword_1927A0, (int16_t)(*(_WORD *)(dword_1927A0 + 2) + v8 - 2));
  sub_12B634();
  v9 = 91;
  v6 = *(int16_t *)(dword_1975C4 + 14) - (*(int16_t *)dword_1975C4 + *(int16_t *)(dword_1975C4 + 6) / 2) + v5;
  v4 = 0;
  while ( 1 )
  {
    sub_134D2D(v7, (int16_t)(v6 + 1), v7, (int16_t)(*(_WORD *)(dword_1975C4 + 6) + v6), v9);
    if ( !(v4 % 2) )
      --v9;
    ++v4;
    ++v7;
    if ( v4 >= 9 )
    {
      sub_12A478(v3, v8, dword_1927A0);
      JUMPOUT(0x65A21);
    }
  }
}
// 66039: control flows out of bounds to 65A21
// 1927A0: using guessed type int dword_1927A0;
// 1927C4: using guessed type int dword_1927C4;
// 1975C4: using guessed type int dword_1975C4;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;


//----- (0006603E) --------------------------------------------------------
void sub_6603E(int16_t *a1)
{
  int16_t v1; // si
  int v2; // ecx
  int v3; // eax
  int16_t *v4; // ebx
  int v5; // edx
  int i; // eax
  int v7; // edi
  int v8; // eax
  int16_t v9; // dx
  int16_t v10; // [esp+8h] [ebp-18h] BYREF
  int16_t v11; // [esp+Ch] [ebp-14h] BYREF
  int16_t *v12; // [esp+10h] [ebp-10h]
  int16_t v13; // [esp+14h] [ebp-Ch] BYREF
  char v14; // [esp+18h] [ebp-8h]
  char v15; // [esp+1Ch] [ebp-4h]

  byte_19B995 = 1;
  v1 = 0;
  word_19995E = 0;
  sub_1112EC(dword_192EE8, 29);
  v2 = 479;
  dword_1975C4 = (int)sub_110D3C(dword_192EE8, 29);
  memset(dword_1975C4, 0, 29);
  sub_124D41();
  v3 = sub_6C6CD();
  sub_1077D(v3, 0, 29, a1);
  sub_124DEC();
  sub_128BE7();
  sub_12B65C();
  sub_133237();
  sub_1318D4(0, 255);
  sub_124D41();
  sub_90006(0, 0, 639, 479);
  sub_124DEC();
  sub_11C2F0();
  sub_1196F7();
  v4 = &v11;
  sub_1191CA((int)sub_65758, 1);
  sub_6626E();
  sub_663B8();
  v5 = (int)&v10;
  v15 = 1;
  sub_64A02((uint16_t *)&v13, &v10, &v11);
  i = word_199856;
  v14 = 1;
  if ( word_199856 == -1 )
  {
    word_19985E = 0;
    word_19B972 = 0;
    v7 = 0;
  }
  else
  {
    LOWORD(i) = word_19985E;
    word_19B972 = word_19985E;
    v7 = i;
  }
  while ( 1 )
  {
    if ( v1 )
    {
      if ( (v7 & 0x8000u) == 0 && (uint16_t)word_199860 >= 2u )
      {
        if ( (uint16_t)word_199860 <= 2u )
        {
          v5 = (int16_t)v7;
          LOWORD(v5) = word_18B0E0[(int16_t)v7];
          *(_WORD *)(dword_1927A8 + 17) = v5;
        }
        else if ( word_199860 == 8 )
        {
          v5 = dword_1927A8;
          *(_WORD *)(dword_1927A8 + 43) = word_18B0E0[(int16_t)v7];
        }
      }
      sub_1113CC(dword_192EE8, v5);
      JUMPOUT(0x68D37);
    }
    v8 = sub_1171AB(i, v5, (int)v4, v2);
    v9 = v8;
    v12 = (int16_t *)v8;
    word_19B97C = (uint16_t)sub_114177();
    if ( v9 < 0 )
    {
      v2 = v11;
      sub_6558C(v9, v13, v10, v11);
    }
    if ( (_WORD)v12 == v13 )
      break;
    if ( (_WORD)v12 == v10 )
      goto LABEL_10;
LABEL_11:
    v4 = v12;
    for ( i = 0; ; ++i )
    {
      v5 = dword_1975C4;
      if ( (int16_t)i >= *(int16_t *)(dword_1975C4 + 8) || v1 )
        break;
      if ( (_WORD)v12 == word_192738[(int16_t)i] )
      {
        v1 = 1;
        v7 = i;
      }
    }
    if ( !v1 && !v15 && v14 || word_19994C )
    {
      i = (int)sub_67E50();
      v14 = 0;
      word_19994C = 0;
    }
    if ( !v1 )
    {
      sub_124D41();
      sub_65758();
      if ( v15 )
        v15 = 0;
      else
        i = sub_1077D(i, v5, (int)v4, (int16_t *)v7);
    }
  }
  v7 = -1;
LABEL_10:
  v1 = 1;
  goto LABEL_11;
}
// 66269: control flows out of bounds to 68D37
// 6613B: variable 'i' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 18B0E0: using guessed type int16_t word_18B0E0[40];
// 192738: using guessed type int16_t word_192738[10];
// 1927A8: using guessed type int dword_1927A8;
// 192EE8: using guessed type int dword_192EE8;
// 1975C4: using guessed type int dword_1975C4;
// 199856: using guessed type int16_t word_199856;
// 19985E: using guessed type int16_t word_19985E;
// 199860: using guessed type int16_t word_199860;
// 19994C: using guessed type int16_t word_19994C;
// 19995E: using guessed type int16_t word_19995E;
// 19B972: using guessed type int16_t word_19B972;
// 19B97C: using guessed type int16_t word_19B97C;
// 19B995: using guessed type char byte_19B995;


//----- (0006626E) --------------------------------------------------------
int16_t sub_6626E()
{
  int16_t result; // ax
  int v1; // edx
  int v2; // edx

  *(_WORD *)(dword_1975C4 + 8) = 1;
  memset(word_18B0E0, 0, sizeof(word_18B0E0));
  memset(dword_1927A8 + 250, 0, 40);
  result = word_199860;
  if ( (uint16_t)word_199860 >= 2u )
  {
    if ( (uint16_t)word_199860 <= 2u )
    {
      *(_WORD *)(dword_1975C4 + 8) = 6;
      for ( result = 0; result < *(int16_t *)(dword_1975C4 + 8); ++result )
      {
        if ( result
          && *(_BYTE *)(3753 * word_19999C + dword_197F98 + *(int16_t *)((char *)&word_17F6A7 + 59 * result) + 279) != 3 )
        {
          word_18B0E0[result] = -1;
        }
        else
        {
          v1 = dword_1927A8;
          word_18B0E0[result] = result;
          *(_BYTE *)(v1 + result + 250) = 1;
        }
      }
    }
    else if ( word_199860 == 8 )
    {
      *(_WORD *)(dword_1975C4 + 8) = 6;
      for ( result = 0; result < *(int16_t *)(dword_1975C4 + 8); ++result )
      {
        if ( result && *(_BYTE *)(dword_197F98 + 3753 * word_19999C + word_17FDF2[11 * result] + 279) != 3 )
        {
          word_18B0E0[result] = -1;
        }
        else
        {
          v2 = dword_1927A8;
          word_18B0E0[result] = result;
          *(_BYTE *)(v2 + result + 250) = 1;
        }
      }
    }
  }
  return result;
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 17F6A7: using guessed type int16_t word_17F6A7;
// 17FDF2: using guessed type int16_t word_17FDF2[];
// 18B0E0: using guessed type int16_t word_18B0E0[40];
// 1927A8: using guessed type int dword_1927A8;
// 1975C4: using guessed type int dword_1975C4;
// 197F98: using guessed type int dword_197F98;
// 199860: using guessed type int16_t word_199860;
// 19999C: using guessed type int16_t word_19999C;


//----- (000663B8) --------------------------------------------------------
int sub_663B8()
{
  int16_t *v0; // eax
  int16_t v1; // cx
  int16_t v2; // dx
  int16_t v3; // ax
  int result; // eax

  v0 = 0;
  if ( (uint16_t)word_199860 >= 2u && ((uint16_t)word_199860 <= 2u || word_199860 == 8) )
    v0 = (int16_t *)dword_19275C;
  v1 = v0[1];
  if ( *(int16_t *)(dword_1975C4 + 8) <= 10 )
    v2 = *(_WORD *)(dword_1975C4 + 8);
  else
    v2 = 10;
  v3 = *v0;
  word_19B96A = *(_WORD *)(dword_192788 + 2) + 16 * v2;
  word_19B974 = v3;
  word_19B97A = *(_WORD *)(dword_19277C + 2) + v1 + word_19B96A;
  word_19B96C = (640 - v3) / 2;
  result = (440 - word_19B97A) / 2;
  word_19B96E = result;
  return result;
}
// 19275C: using guessed type int dword_19275C;
// 19277C: using guessed type int dword_19277C;
// 192788: using guessed type int dword_192788;
// 1975C4: using guessed type int dword_1975C4;
// 199860: using guessed type int16_t word_199860;
// 19B96A: using guessed type int16_t word_19B96A;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;
// 19B974: using guessed type int16_t word_19B974;
// 19B97A: using guessed type int16_t word_19B97A;


//----- (0006649D) --------------------------------------------------------
char sub_6649D(int16_t *a1, int a2, int a3)
{
  int16_t v3; // cx
  int16_t i; // si
  int16_t v5; // bx
  int16_t v6; // ax
  int16_t v7; // ax
  int16_t *v10; // [esp+8h] [ebp-18h]
  int16_t v11; // [esp+14h] [ebp-Ch]
  int16_t v12; // [esp+18h] [ebp-8h]
  int16_t v13; // [esp+1Ch] [ebp-4h]

  v10 = a1;
  v13 = 11;
  v12 = 11;
  LOBYTE(a1) = word_19B972;
  v11 = 0;
  if ( word_19B972 > -1 )
  {
    v3 = 1;
    for ( i = 0; ; ++i )
    {
      v5 = -1;
      LOBYTE(a1) = sub_6825F(v3);
      if ( (_BYTE)a1 )
        break;
LABEL_37:
      if ( ++v3 >= 15 )
        return (char)a1;
    }
    v6 = sub_6EFEB(*(_WORD *)(dword_192694 + 6 * word_19B972));
    if ( (uint16_t)v6 <= 2u )
    {
      switch ( i )
      {
        case 0:
          v5 = 0;
          break;
        case 1:
          v5 = 1;
          break;
        case 2:
          v5 = 2;
          break;
        case 3:
          v5 = 3;
          break;
        case 4:
          if ( v6 )
            v5 = 13;
          else
            v5 = 4;
          break;
        case 5:
          v5 = 5;
          break;
        case 6:
          v5 = 6;
          break;
        case 7:
          if ( v6 )
            v5 = 14;
          else
            v5 = 7;
          break;
        case 8:
          v5 = 8;
          break;
        case 9:
          if ( v6 == 1 )
            v5 = 12;
          else
            v5 = 16;
          break;
        case 10:
          v5 = 9;
          break;
        case 11:
          v5 = 10;
          break;
        case 12:
          if ( v6 == 1 )
            v5 = 11;
          else
            v5 = 15;
          break;
        case 13:
          v5 = 17;
          break;
        default:
          break;
      }
    }
    if ( !v6 )
      goto LABEL_31;
    if ( (uint16_t)v6 <= 1u )
    {
      v13 = 21;
      v12 = 21;
      goto LABEL_33;
    }
    if ( (uint16_t)v6 <= 3u )
    {
LABEL_31:
      v13 = 17;
      v12 = 17;
    }
LABEL_33:
    if ( v11 % 2 )
    {
      *(_WORD *)(a2 + 2 * v3) = 386;
      v7 = v12;
    }
    else
    {
      *(_WORD *)(a2 + 2 * v3) = 233;
      v7 = v13;
    }
    *(_WORD *)(a3 + 2 * v3) = 17 * (v11 / 2) + v7 + 70;
    a1 = &v10[v3];
    ++v11;
    *a1 = v5;
    goto LABEL_37;
  }
  return (char)a1;
}
// 192694: using guessed type int dword_192694;
// 19B972: using guessed type int16_t word_19B972;


//----- (0006667C) --------------------------------------------------------
int sub_6667C()
{
  int16_t v0; // ax
  int result; // eax

  if ( *(int16_t *)(dword_1975C4 + 8) >= 7 )
    v0 = *(_WORD *)(dword_19280C + 2);
  else
    v0 = 102;
  word_19B97A = *(_WORD *)(dword_1927C8 + 2) + *(_WORD *)(dword_1927C4 + 2) + v0;
  word_19B974 = 636;
  result = (405 - word_19B97A) / 2 + 38;
  word_19B96C = 2;
  if ( result <= 38 )
    result = 38;
  word_19B96E = result;
  return result;
}
// 1927C4: using guessed type int dword_1927C4;
// 1927C8: using guessed type int dword_1927C8;
// 19280C: using guessed type int dword_19280C;
// 1975C4: using guessed type int dword_1975C4;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;
// 19B974: using guessed type int16_t word_19B974;
// 19B97A: using guessed type int16_t word_19B97A;


//----- (000666F5) --------------------------------------------------------
_BOOL1 sub_666F5()
{
  _BOOL1 v0; // dl
  int16_t i; // ax

  v0 = 0;
  if ( word_199856 != -1 && *(_WORD *)(dword_1927A8 + 2 * word_199856 + 53) == 39 )
    return 0;
  for ( i = 0; i < 8 && !v0; ++i )
    v0 = *(_WORD *)(dword_1927A8 + 2 * i + 53) == 39;
  return v0;
}
// 1927A8: using guessed type int dword_1927A8;
// 199856: using guessed type int16_t word_199856;


//----- (00066742) --------------------------------------------------------
int sub_66742()
{
  int v0; // edx
  int16_t i; // bx
  int v2; // eax

  v0 = 0;
  for ( i = 0; ; ++i )
  {
    v2 = *(int16_t *)(dword_1975C4 + 8) >= 10 ? 10 : *(int16_t *)(dword_1975C4 + 8);
    if ( i >= v2 )
      break;
    if ( word_18B090[i] )
      ++v0;
  }
  return v0;
}
// 18B090: using guessed type int16_t word_18B090[40];
// 1975C4: using guessed type int dword_1975C4;


//----- (0006678C) --------------------------------------------------------
char sub_6678C( int a1)
{
  int16_t v2; // ax
  int v3; // edx
  int v5; // edx

  v2 = -1;
  LOBYTE(v3) = 0;
  if ( word_19B972 > -1 )
    v2 = sub_6EFEB(*(_WORD *)(dword_192694 + 6 * word_19B972));
  switch ( v2 )
  {
    case 0:
      LOBYTE(v3) = (510 >> a1) & 1;
      break;
    case 1:
      v5 = 15872;
      goto LABEL_7;
    case 2:
      v5 = 25888;
LABEL_7:
      v3 = (v5 >> a1) & 1;
      break;
    default:
      return v3;
  }
  return v3;
}
// 192694: using guessed type int dword_192694;
// 19B972: using guessed type int16_t word_19B972;


//----- (00066810) --------------------------------------------------------
int sub_66810( int a1)
{
  if ( word_19B972 <= -1 )
    return 0;
  else
    return sub_6EE8E(word_19999C, *(_WORD *)(dword_192694 + 6 * word_19B972), 1, 1 << a1, word_19B978, word_19B966);
}
// 192694: using guessed type int dword_192694;
// 19999C: using guessed type int16_t word_19999C;
// 19B966: using guessed type int16_t word_19B966;
// 19B972: using guessed type int16_t word_19B972;
// 19B978: using guessed type int16_t word_19B978;


//----- (00066870) --------------------------------------------------------
void sub_66870( int a1)
{
  int v1; // edx
  int16_t i; // ax

  v1 = 0;
  if ( word_19B972 > -1 )
  {
    for ( i = 0; i < 15; ++i )
    {
      if ( word_1991B6[i] == 1 )
        v1 |= 1 << i;
    }
    sub_6EE8E(word_19999C, *(_WORD *)(dword_192694 + 6 * word_19B972), 1, word_19B976, word_19B978, (1 << a1) | v1);
  }
  JUMPOUT(0x667F7);
}
// 668F1: control flows out of bounds to 667F7
// 192694: using guessed type int dword_192694;
// 1991B6: using guessed type int16_t word_1991B6[];
// 19999C: using guessed type int16_t word_19999C;
// 19B972: using guessed type int16_t word_19B972;
// 19B976: using guessed type int16_t word_19B976;
// 19B978: using guessed type int16_t word_19B978;


//----- (000668FD) --------------------------------------------------------
void sub_668FD()
{
  int16_t v0; // di
  int16_t v1; // si
  int v2; // ecx
  int v3; // eax
  char v4; // dl
  _BYTE *v5; // edx
  int v6; // ecx
  int16_t v7; // di
  char *v8; // eax
  int v9; // ebx
  int16_t v10; // ax
  int v11; // edx
  int16_t v12; // ax
  int16_t v13; // dx
  int16_t v14; // ax
  int v15; // [esp+0h] [ebp-7Ah]
  int v16; // [esp+0h] [ebp-7Ah]
  int v17; // [esp+0h] [ebp-7Ah]
  int v18; // [esp+4h] [ebp-76h]
  int v19; // [esp+4h] [ebp-76h]
  char v20[80]; // [esp+8h] [ebp-72h] BYREF
  char v21[80]; // [esp+58h] [ebp-22h] BYREF
  char v22[80]; // [esp+A8h] [ebp+2Eh] BYREF
  _BYTE v23[80]; // [esp+F8h] [ebp+7Eh] BYREF
  _BYTE v24[8]; // [esp+148h] [ebp+CEh] BYREF
  _BYTE v25[8]; // [esp+150h] [ebp+D6h] BYREF
  _BYTE v26[8]; // [esp+158h] [ebp+DEh] BYREF
  _BYTE v27[8]; // [esp+160h] [ebp+E6h] BYREF
  int v28; // [esp+168h] [ebp+EEh]
  int v29; // [esp+16Ch] [ebp+F2h]
  int v30; // [esp+170h] [ebp+F6h]
  int v31; // [esp+174h] [ebp+FAh]
  int v32; // [esp+178h] [ebp+FEh]

  qmemcpy(v25, sub_8E5C5(4u, 85, 91), sizeof(v25));
  sub_128AB6(v18, v15, word_19B974 + v18, (int16_t)(word_19B97A + v15));
  sub_12B634();
  v16 = v15 + 55;
  sub_120BB5(4, (int)v25);
  sub_8F6DF(0x29u, v22);
  sub_8F6DF(0x2Au, v21);
  sub_8F6DF(0x2Bu, v20);
  sub_1212B3(v18 + 23, v16, (int)v22);
  v0 = v18 + 425;
  sub_1212B3(v18 + 245, v16, (int)v21);
  v19 = v18 + 20;
  sub_1212B3(v0, v16, (int)v20);
  v17 = v16 + 18;
  v30 = sub_12066F((int)v22);
  sub_12066F((int)v21);
  v29 = sub_12066F((int)v20);
  qmemcpy(v25, sub_8E5C5(3u, 85, 91), sizeof(v25));
  qmemcpy(v24, sub_8E5C5(3u, 85, 89), sizeof(v24));
  qmemcpy(v26, sub_8E5C5(3u, 85, 87), sizeof(v26));
  v1 = 0;
  v31 = v19 + 3;
  while ( 1 )
  {
    if ( v1 >= *(int16_t *)(dword_1975C4 + 8) )
    {
      sub_128BE7();
      sub_12B65C();
      if ( (uint8_t)++byte_19B994 >= 2u )
      {
        word_19995E += byte_19B995;
        byte_19B994 = 0;
        if ( word_19995E < 3 )
        {
          if ( word_19995E <= -1 )
          {
            word_19995E = -1;
            byte_19B995 = 1;
          }
        }
        else
        {
          word_19995E = 3;
          byte_19B995 = -1;
        }
      }
      JUMPOUT(0x672EE);
    }
    if ( word_19B97C == word_192738[v1] && *(_BYTE *)(v1 + dword_1927A8 + 250) )
    {
      v27[0] = 0;
      v2 = 1;
      do
      {
        v3 = (int16_t)v2;
        v4 = word_19995E + v24[(int16_t)v2++];
        v27[v3] = v4;
      }
      while ( (int16_t)v2 < 8 );
      v5 = v27;
    }
    else if ( v1 == word_19B972 )
    {
      v5 = v25;
    }
    else if ( *(_BYTE *)(v1 + dword_1927A8 + 250) )
    {
      v5 = v24;
    }
    else
    {
      v5 = v26;
    }
    sub_120BB5(3, (int)v5);
    v32 = v17 + 14;
    if ( word_18B0E0[v1] )
    {
      if ( word_18B0E0[v1] <= 0 )
        goto LABEL_17;
      sub_6E70A(word_19999C, word_17FDF2[11 * word_18B0E0[v1]]);
      v13 = v12;
      v14 = sub_6B4D7(word_18B0E0[v1]);
      v28 = sub_6B519(v14, v13);
      sub_1212B3(v31, v17, *(int *)((char *)&off_17FDEC + 22 * word_18B0E0[v1]));
      sprintf(v23, "+%d", word_17FE00[11 * word_18B0E0[v1]]);
      sub_1210FD(v19 + 225 + (int16_t)v30 / 2, v17, (int)v23);
      v6 = (int16_t)v19 + 405;
      v9 = (int16_t)v28;
      v10 = v6 + (int16_t)v29 / 2;
      v11 = (int16_t)v17;
    }
    else
    {
      v6 = (int16_t)v17;
      v7 = v31;
      v8 = sub_7A990(0x2Du);
      sub_1212B3(v7, v17, (int)v8);
      sub_121199((int16_t)(v19 + 225 + (int16_t)v30 / 2), v6, 0, v6);
      v9 = 0;
      v10 = v19 + 405 + (int16_t)v29 / 2;
      v11 = (int16_t)v17;
    }
    sub_121199(v10, v11, v9, v6);
    v17 = v32;
LABEL_17:
    ++v1;
  }
}
// 66CE7: control flows out of bounds to 672EE
// 6695A: variable 'v18' is possibly undefined
// 6695A: variable 'v15' is possibly undefined
// 66BBB: variable 'v12' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17FDEC: using guessed type _UNKNOWN *off_17FDEC;
// 17FDF2: using guessed type int16_t word_17FDF2[];
// 17FE00: using guessed type int16_t word_17FE00[];
// 18B0E0: using guessed type int16_t word_18B0E0[40];
// 192738: using guessed type int16_t word_192738[10];
// 1927A8: using guessed type int dword_1927A8;
// 1975C4: using guessed type int dword_1975C4;
// 19995E: using guessed type int16_t word_19995E;
// 19999C: using guessed type int16_t word_19999C;
// 19B972: using guessed type int16_t word_19B972;
// 19B974: using guessed type int16_t word_19B974;
// 19B97A: using guessed type int16_t word_19B97A;
// 19B97C: using guessed type int16_t word_19B97C;
// 19B994: using guessed type char byte_19B994;
// 19B995: using guessed type char byte_19B995;


//----- (00066CEC) --------------------------------------------------------
int16_t sub_66CEC()
{
  char *v0; // eax
  char *v1; // eax
  char *v2; // eax
  char *v3; // eax
  char *v4; // eax
  int v5; // eax
  int v6; // eax
  uint16_t v7; // ax
  int16_t v8; // si
  uint16_t v9; // di
  int v10; // eax
  uint16_t v11; // ax
  int16_t v12; // si
  uint16_t v13; // di
  _BYTE *v14; // edi
  char *v15; // eax
  _BYTE *v16; // edx
  int v17; // eax
  int16_t v18; // si
  int16_t v19; // cx
  char *v20; // eax
  int v21; // eax
  int16_t v22; // dx
  int v23; // ecx
  int v24; // edx
  int16_t v25; // cx
  int16_t result; // ax
  int v27; // edx
  int v28; // [esp+0h] [ebp-56h]
  int v29; // [esp+4h] [ebp-52h]
  char v30[80]; // [esp+8h] [ebp-4Eh] BYREF
  _BYTE v31[20]; // [esp+58h] [ebp+2h] BYREF
  _BYTE v32[20]; // [esp+6Ch] [ebp+16h] BYREF
  _DWORD v33[2]; // [esp+80h] [ebp+2Ah]
  int16_t v34; // [esp+88h] [ebp+32h]
  _BYTE v35[8]; // [esp+8Ch] [ebp+36h] BYREF
  _BYTE v36[8]; // [esp+94h] [ebp+3Eh] BYREF
  _BYTE v37[8]; // [esp+9Ch] [ebp+46h] BYREF
  _BYTE v38[8]; // [esp+A4h] [ebp+4Eh] BYREF
  int v39; // [esp+ACh] [ebp+56h]
  int v40; // [esp+B0h] [ebp+5Ah]
  int v41; // [esp+B4h] [ebp+5Eh]
  int v42; // [esp+B8h] [ebp+62h]
  int v43; // [esp+BCh] [ebp+66h]
  int v44; // [esp+C0h] [ebp+6Ah]
  int v45; // [esp+C4h] [ebp+6Eh]
  int v46; // [esp+C8h] [ebp+72h]
  int v47; // [esp+CCh] [ebp+76h]
  int v48; // [esp+D0h] [ebp+7Ah]
  char v49; // [esp+D4h] [ebp+7Eh]

  v33[0] = 327682;
  v33[1] = 983050;
  v34 = *(_WORD *)((char *)&dword_649E0[1] + 3);
  qmemcpy(v35, sub_8E5C5(3u, 85, 91), sizeof(v35));
  sub_120BB5(3, (int)v35);
  v0 = sub_7A990(0x2Eu);
  sub_1212B3(v29 + 28, v28 + 3, (int)v0);
  v1 = sub_7A990(0x2Fu);
  sub_1210B7(v29 + 198, v28 + 3, (int)v1);
  v2 = sub_7A990(0x30u);
  sub_1212B3(v29 + 253, v28 + 3, (int)v2);
  v3 = sub_7A990(0x2Bu);
  sub_1212B3(v29 + 211, v28 + 3, (int)v3);
  v4 = sub_7A990(0x31u);
  sub_1212B3(v29 + 387, v28 + 3, (int)v4);
  HIWORD(v5) = HIWORD(dword_1975C4);
  LOWORD(v5) = *(_WORD *)(dword_1975C4 + 12);
  v47 = v5;
  v41 = v29 + 305;
  v39 = 0;
  v42 = v29 + 3;
  v40 = 0;
  v46 = 0;
  v45 = v28 + 19;
  do
  {
    HIWORD(v6) = HIWORD(dword_192694);
    LOWORD(v6) = *(_WORD *)(6 * (int16_t)v47 + dword_192694);
    v49 = 0;
    v48 = v6;
    if ( (int16_t)v47 > 0 )
    {
      if ( word_19B972 > -1 && (int16_t)v6 > 0 && (_WORD)v47 == word_19B972 )
      {
        v7 = sub_6EDAE(v6);
        if ( v7 )
          v7 = *((_WORD *)v33 + word_19B978);
        v8 = v48;
        v9 = v7;
        v39 = sub_6EC74(v48, 1, word_19B976, v7, word_19B966);
        v10 = sub_6EE8E(word_19999C, v8, 1, word_19B976, v9, word_19B966);
LABEL_13:
        v40 = v10;
        goto LABEL_14;
      }
      if ( (int16_t)v48 > 0 )
      {
        v11 = sub_6EDAE(v48);
        if ( v11 )
          v11 = 5;
        v12 = v48;
        v13 = v11;
        v39 = sub_6EC74(v48, 1, 1, v11, 0);
        v10 = sub_6EE8E(word_19999C, v12, 1, 1, v13, 0);
        goto LABEL_13;
      }
    }
LABEL_14:
    if ( word_19B972 > -1 && (_WORD)v47 == word_19B972 )
      v49 = 1;
    if ( word_19B97C == (_WORD)v46 && (int16_t)v47 > -1 && *(_BYTE *)(dword_1927A8 + (int16_t)v47 + 250) )
    {
      qmemcpy(v38, sub_8E5C5(2u, 85, 88), sizeof(v38));
      sub_120BB5(2, (int)v38);
      sub_8F7DF(word_19995E);
    }
    else
    {
      if ( v49 )
      {
        v14 = v36;
        v15 = sub_8E5C5(2u, 85, 92);
        v16 = v36;
      }
      else if ( (int16_t)v47 > -1 && *(_BYTE *)(dword_1927A8 + (int16_t)v47 + 250) )
      {
        v14 = v35;
        v15 = sub_8E5C5(2u, 85, 90);
        v16 = v35;
      }
      else if ( (int16_t)v47 <= -1 || *(_BYTE *)(dword_1927A8 + (int16_t)v47 + 250) )
      {
        v14 = v35;
        v15 = sub_8E5C5(2u, 85, 89);
        v16 = v35;
      }
      else
      {
        v14 = v37;
        v15 = sub_8E5C5(2u, 85, 87);
        v16 = v37;
      }
      qmemcpy(v14, v15, 8u);
      sub_120BB5(2, (int)v16);
    }
    sprintf(v31, "%d", v39);
    sprintf(v32, "%d", v40);
    v44 = v42;
    v43 = v45;
    if ( v49 )
      sub_12A478(v42 - 3, v45 + 1, dword_1927FC);
    if ( v40 <= 0 )
    {
      LOWORD(v17) = 0;
    }
    else
    {
      v17 = 0 / v40;
      if ( 0 / v40 > 99 )
        LOWORD(v17) = 99;
      if ( *(_BYTE *)((int16_t)v47 + dword_1927A8 + 250) && (int16_t)v17 <= 1 )
        LOWORD(v17) = 1;
    }
    if ( (int16_t)v48 <= 0 )
      strcpy(v30, sub_7A990(0x32u));
    else
      sprintf(v30, "%s (%d)", (char *)*(&off_17F803 + 7 * (int16_t)v48), (int16_t)v17);
    v18 = v43;
    sub_120E8C(1);
    v19 = v47;
    sub_1212B3(v44 + 9, v18, (int)v30);
    sub_8FE2E();
    sub_6C47E((int16_t)v48, v30, word_19B972, v19);
    v20 = sub_7A990(0x65u);
    v21 = strcmp(v30, v20);
    v22 = v44 + 195;
    if ( v21 )
    {
      sub_1210B7(v22, v18, (int)v30);
    }
    else
    {
      sub_8EBBB(1);
      sub_1210B7(v22, v43 + 2, (int)v30);
      sub_8EBBB(2);
    }
    v23 = (int16_t)v43;
    sub_1210B7(v44 + 230, v43, (int)v31);
    HIWORD(v24) = HIWORD(v23);
    sub_1210B7(v44 + 284, v23, (int)v32);
    if ( (int16_t)v48 > 0 )
    {
      v25 = v48;
      v24 = word_17F80D[14 * (int16_t)v48];
      sub_6E70A(word_19999C, v24);
      if ( sub_6EDAE(v25) > 0 )
        sub_6F1CC(2u);
    }
    if ( (_WORD)v48 )
    {
      strcpy(v30, (char *)dword_18B130[(int16_t)v48]);
      sub_8F625((int)v38);
      sub_120BB5(2, (int)v38);
      v24 = (int16_t)v43;
      sub_120E8C(1);
      sub_1212B3(v41, v24, (int)v30);
      sub_8FE2E();
    }
    else
    {
      v30[0] = 0;
    }
    result = dword_1975C4;
    ++v46;
    LOWORD(v24) = *(_WORD *)(dword_1975C4 + 12);
    v27 = v46 + v24;
    v45 += 14;
    v47 = v27;
  }
  while ( (int16_t)v46 < 10 && (int16_t)v27 < *(int16_t *)(dword_1975C4 + 8) );
  if ( (uint8_t)++byte_19B994 >= 2u )
  {
    result = byte_19B995;
    word_19995E += byte_19B995;
    byte_19B994 = 0;
    if ( word_19995E < 3 )
    {
      result = word_19995E;
      if ( word_19995E <= -1 )
      {
        word_19995E = -1;
        byte_19B995 = 1;
      }
    }
    else
    {
      word_19995E = 3;
      byte_19B995 = -1;
    }
  }
  return result;
}
// 66D4D: variable 'v29' is possibly undefined
// 66D42: variable 'v28' is possibly undefined
// 649E0: using guessed type int[2];
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 138B90: using guessed type int strcmp(_DWORD, _DWORD);
// 17F803: using guessed type _UNKNOWN *off_17F803;
// 17F80D: using guessed type int16_t word_17F80D[];
// 18B130: using guessed type int dword_18B130[40];
// 192694: using guessed type int dword_192694;
// 1927A8: using guessed type int dword_1927A8;
// 1927FC: using guessed type int dword_1927FC;
// 1975C4: using guessed type int dword_1975C4;
// 19995E: using guessed type int16_t word_19995E;
// 19999C: using guessed type int16_t word_19999C;
// 19B966: using guessed type int16_t word_19B966;
// 19B972: using guessed type int16_t word_19B972;
// 19B976: using guessed type int16_t word_19B976;
// 19B978: using guessed type int16_t word_19B978;
// 19B97C: using guessed type int16_t word_19B97C;
// 19B994: using guessed type char byte_19B994;
// 19B995: using guessed type char byte_19B995;


//----- (00067312) --------------------------------------------------------
void sub_67312()
{
  char *v0; // eax
  int16_t v1; // si
  int v2; // ecx
  int v3; // eax
  char v4; // dl
  _BYTE *v5; // edx
  int v6; // ecx
  int16_t v7; // di
  char *v8; // eax
  int v9; // ebx
  int v10; // edx
  int v11; // eax
  int16_t v12; // ax
  int16_t v13; // ax
  int16_t v14; // ax
  int v15; // [esp+0h] [ebp-5Eh]
  int v16; // [esp+0h] [ebp-5Eh]
  int v17; // [esp+0h] [ebp-5Eh]
  int v18; // [esp+4h] [ebp-5Ah]
  int v19; // [esp+4h] [ebp-5Ah]
  char v20[80]; // [esp+8h] [ebp-56h] BYREF
  char v21[80]; // [esp+58h] [ebp-6h] BYREF
  _BYTE v22[8]; // [esp+A8h] [ebp+4Ah] BYREF
  _BYTE v23[8]; // [esp+B0h] [ebp+52h] BYREF
  _BYTE v24[8]; // [esp+B8h] [ebp+5Ah] BYREF
  _BYTE v25[8]; // [esp+C0h] [ebp+62h] BYREF
  int v26; // [esp+C8h] [ebp+6Ah]
  int v27; // [esp+CCh] [ebp+6Eh]
  int v28; // [esp+D0h] [ebp+72h]
  int v29; // [esp+D4h] [ebp+76h]
  int v30; // [esp+D8h] [ebp+7Ah]
  int v31; // [esp+DCh] [ebp+7Eh]

  qmemcpy(v23, sub_8E5C5(4u, 85, 91), sizeof(v23));
  sub_128AB6(v18, v15, word_19B974 + v18, (int16_t)(word_19B97A + v15));
  sub_12B634();
  v16 = v15 + 55;
  sub_120BB5(4, (int)v23);
  v19 = v18 + 20;
  sub_8F6DF(0x34u, v21);
  sub_8F6DF(0x35u, v20);
  v0 = sub_7A990(0x33u);
  sub_1212B3(v19, v16, (int)v0);
  sub_1212B3(v19 + 220, v16, (int)v21);
  sub_1212B3(v19 + 350, v16, (int)v20);
  v29 = sub_12066F((int)v21);
  v31 = sub_12066F((int)v20);
  v17 = v16 + 18;
  qmemcpy(v23, sub_8E5C5(3u, 85, 91), sizeof(v23));
  qmemcpy(v22, sub_8E5C5(3u, 85, 89), sizeof(v22));
  qmemcpy(v24, sub_8E5C5(3u, 85, 87), sizeof(v24));
  v1 = 0;
  v30 = v19 + 3;
  while ( 1 )
  {
    if ( v1 >= *(int16_t *)(dword_1975C4 + 8) )
    {
      sub_128BE7();
      sub_12B65C();
      JUMPOUT(0x672A9);
    }
    if ( word_19B97C == word_192738[v1] && *(_BYTE *)(v1 + dword_1927A8 + 250) )
    {
      v25[0] = 0;
      v2 = 1;
      do
      {
        v3 = (int16_t)v2;
        v4 = word_19995E + v22[(int16_t)v2++];
        v25[v3] = v4;
      }
      while ( (int16_t)v2 < 8 );
      v5 = v25;
    }
    else if ( v1 == word_19B972 )
    {
      v5 = v23;
    }
    else if ( *(_BYTE *)(dword_1927A8 + v1 + 250) )
    {
      v5 = v22;
    }
    else
    {
      v5 = v24;
    }
    sub_120BB5(3, (int)v5);
    v6 = 2 * v1;
    v28 = v17 + 14;
    if ( *(int16_t *)((char *)word_18B0E0 + v6) )
    {
      if ( word_18B0E0[v1] <= 0 )
        goto LABEL_17;
      sub_1212B3(v30, v17, *(int *)((char *)&off_17F6A1 + 59 * word_18B0E0[v1]));
      sub_6E70A(word_19999C, *(int16_t *)((char *)&word_17F6A7 + 59 * word_18B0E0[v1]));
      v26 = 59 * word_18B0E0[v1];
      v13 = sub_6B519(*(int16_t *)((char *)&word_17F6B5[*(int16_t *)(dword_1927A8 + 229)] + v26), v12);
      v27 = (int16_t)v19;
      sub_121199((int16_t)(v19 + 220 + (int16_t)v31 / 2), (int16_t)v17, v13, v6);
      sub_6E70A(word_19999C, *(int16_t *)((char *)&word_17F6A7 + 59 * word_18B0E0[v1]));
      v9 = (int16_t)sub_6E60E(
                      *(int16_t *)((char *)&word_17F6A9 + 59 * word_18B0E0[v1] + 2 * *(int16_t *)(dword_1927A8 + 229)),
                      v14,
                      0);
      v11 = (int16_t)(v27 + 350 + (int16_t)v29 / 2);
      v10 = (int16_t)v17;
    }
    else
    {
      v6 = (int16_t)v17;
      v7 = v30;
      v8 = sub_7A990(0x36u);
      sub_1212B3(v7, v17, (int)v8);
      sub_121199((int16_t)(v19 + 220 + (int16_t)v31 / 2), v6, 0, v6);
      v9 = 0;
      v10 = (int16_t)v17;
      v11 = (int16_t)(v19 + 350 + (int16_t)v29 / 2);
    }
    sub_121199(v11, v10, v9, v6);
    v17 = v28;
LABEL_17:
    ++v1;
  }
}
// 6767A: control flows out of bounds to 672A9
// 67366: variable 'v18' is possibly undefined
// 67366: variable 'v15' is possibly undefined
// 675CB: variable 'v12' is possibly undefined
// 67636: variable 'v14' is possibly undefined
// 17F6A1: using guessed type _UNKNOWN *off_17F6A1;
// 17F6A7: using guessed type int16_t word_17F6A7;
// 17F6A9: using guessed type int16_t word_17F6A9;
// 17F6B5: using guessed type int16_t word_17F6B5[6];
// 18B0E0: using guessed type int16_t word_18B0E0[40];
// 192738: using guessed type int16_t word_192738[10];
// 1927A8: using guessed type int dword_1927A8;
// 1975C4: using guessed type int dword_1975C4;
// 19995E: using guessed type int16_t word_19995E;
// 19999C: using guessed type int16_t word_19999C;
// 19B972: using guessed type int16_t word_19B972;
// 19B974: using guessed type int16_t word_19B974;
// 19B97A: using guessed type int16_t word_19B97A;
// 19B97C: using guessed type int16_t word_19B97C;


//----- (0006767F) --------------------------------------------------------
void sub_6767F()
{
  char *v0; // eax
  char *v1; // eax
  char *v2; // eax
  char *v3; // eax
  char *v4; // edi
  int v5; // ecx
  int16_t v6; // dx
  int16_t v7; // si
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int16_t v11; // dx
  int16_t v12; // ax
  char v13; // al
  int16_t v14; // cx
  int16_t v15; // si
  char *v16; // eax
  int16_t v17; // cx
  int v18; // eax
  int v19; // [esp+0h] [ebp-11Ah]
  int v20; // [esp+0h] [ebp-11Ah]
  int v21; // [esp+4h] [ebp-116h]
  char v22[200]; // [esp+8h] [ebp-112h] BYREF
  char v23[80]; // [esp+D0h] [ebp-4Ah] BYREF
  _BYTE v24[20]; // [esp+120h] [ebp+6h] BYREF
  _BYTE v25[20]; // [esp+134h] [ebp+1Ah] BYREF
  _BYTE v26[8]; // [esp+148h] [ebp+2Eh] BYREF
  _BYTE v27[8]; // [esp+150h] [ebp+36h] BYREF
  _BYTE v28[8]; // [esp+158h] [ebp+3Eh] BYREF
  _BYTE v29[8]; // [esp+160h] [ebp+46h] BYREF
  int v30; // [esp+168h] [ebp+4Eh] BYREF
  int16_t v31; // [esp+16Ch] [ebp+52h] BYREF
  int16_t v32; // [esp+170h] [ebp+56h] BYREF
  int v33; // [esp+174h] [ebp+5Ah]
  int v34; // [esp+178h] [ebp+5Eh]
  int v35; // [esp+17Ch] [ebp+62h]
  int v36; // [esp+180h] [ebp+66h]
  int i; // [esp+184h] [ebp+6Ah]
  int v38; // [esp+188h] [ebp+6Eh]
  int v39; // [esp+18Ch] [ebp+72h]
  int v40; // [esp+190h] [ebp+76h]
  int v41; // [esp+194h] [ebp+7Ah]
  int v42; // [esp+198h] [ebp+7Eh]

  qmemcpy(v27, sub_8E5C5(4u, 85, 92), sizeof(v27));
  sub_120BB5(4, (int)v27);
  v0 = sub_7A990(0x37u);
  sub_1212B3(v21 + 68, v19 + 70, (int)v0);
  v1 = sub_7A990(0x30u);
  sub_1212B3(v21 + 190, v19 + 70, (int)v1);
  v2 = sub_7A990(0x2Bu);
  v41 = 3;
  sub_1212B3(v21 + 262, v19 + 70, (int)v2);
  v3 = sub_7A990(0x38u);
  v38 = 16;
  sub_1212B3(v21 + 342, v19 + 70, (int)v3);
  qmemcpy(v29, sub_8E5C5(2u, 85, 87), sizeof(v29));
  qmemcpy(v27, sub_8E5C5(2u, 85, 92), sizeof(v27));
  qmemcpy(v26, sub_8E5C5(3u, 85, 90), sizeof(v26));
  v4 = v26;
  v5 = (int16_t)(v19 + 64 + word_19B96A + 5);
  v6 = v19 + 64;
  v7 = 1;
  v20 = v19 + 89;
  sub_128AB6(v21 + 25, v6, v21 + 583, v5);
  sub_12B634();
  while ( 1 )
  {
    sub_120E8C(1);
    sub_8F625((int)v28);
    sub_8FDA1(*(int *)((char *)&off_17EEE0 + 47 * v7), (int)v28, v41, 1, -1, 165, 1);
    if ( sub_8F64C() < (int16_t)v41 )
    {
      LOWORD(v8) = sub_8F64C();
      v41 = v8;
    }
    if ( ++v7 >= 39 )
    {
      v36 = v21 + 318;
      v35 = v21 + 292;
      v34 = v21 + 227;
      v39 = v21 + 32;
      v33 = v38;
      v40 = 0;
      for ( i = v20; ; i += v33 )
      {
        v18 = *(int16_t *)(dword_1975C4 + 8) >= 10 ? 10 : *(int16_t *)(dword_1975C4 + 8);
        if ( (int16_t)v40 >= v18 )
          break;
        HIWORD(v9) = HIWORD(v40);
        LOWORD(v9) = *(_WORD *)(dword_1975C4 + 12) + v40;
        v42 = v9;
        if ( word_18B0E0[(int16_t)v9] > -1 )
        {
          sub_68D3D(v9, &v31, (int16_t *)&v30, (int)v4);
          strcpy(v22, (char *)dword_19269C[word_18B0E0[(int16_t)v9]]);
          strcpy(v23, *(char **)((char *)&off_17EEE0 + 47 * word_18B0E0[(int16_t)v9]));
          v4 = v23;
          if ( word_199856 <= -1 || (v10 = dword_1927A8 + 2 * word_199856, *(int16_t *)(v10 + 181) <= 0) )
            v11 = v30;
          else
            v11 = v30 - *(_WORD *)(v10 + 213);
          if ( (_WORD)v42
            && (*(_DWORD *)(dword_1927A8 + 237) + v11 > *(_DWORD *)(dword_1927A8 + 233)
             || (sub_68613(word_18B0E0[(int16_t)v42], &v32), v12)) )
          {
            sub_120BB5((int16_t)v41, (int)v29);
            v13 = 0;
          }
          else
          {
            sub_120BB5((int16_t)v41, (int)v26);
            v13 = 1;
          }
          if ( word_19B97C == (_WORD)v40 && v13 )
          {
            qmemcpy(v28, sub_8E5C5(2u, 85, 88), sizeof(v28));
            v4 = v28;
            sub_120BB5((int16_t)v41, (int)v28);
            sub_8F7DF(word_19995E);
          }
          if ( (_WORD)v42 )
          {
            sub_8F64C();
            sprintf(v25, "%d", v31);
            v17 = i;
            sprintf(v24, "%d", (int16_t)v30);
            sub_120E8C(1);
            sub_1212B3(v39, v17, (int)v23);
            sub_8FE2E();
            sub_1210B7(v34, v17, (int)v24);
            sub_1210B7(v35, v17, (int)v25);
            sub_8F625((int)v28);
            sub_120BB5((int16_t)v41, (int)v28);
            sub_120E8C(1);
            sub_1212B3(v36, v17, (int)v22);
            sub_8FE2E();
          }
          else
          {
            v14 = i;
            v15 = v39;
            v16 = sub_7A990(0x39u);
            sub_1212B3(v15, v14, (int)v16);
            sub_1210B7(v34, v14, (int)a0);
            sub_1210B7(v35, v14, (int)a0);
            sub_1212B3(v36, v14, (int)asc_1791D2);
          }
        }
        ++v40;
      }
      if ( *(int16_t *)(dword_1975C4 + 12) > 0 )
        sub_12A478(word_19B974 + word_19B96C - 32, word_19B96E + 71, dword_192784);
      if ( *(int16_t *)(dword_1975C4 + 8) > 10 && *(int16_t *)(dword_1975C4 + 12) + 10 > *(int16_t *)(dword_1975C4 + 8) )
        sub_12A478(word_19B974 + word_19B96C - 32, word_19B97A + word_19B96E - 30, dword_1927A4);
      sub_12B65C();
      sub_128BE7();
      ++byte_19B994;
      JUMPOUT(0x672B6);
    }
  }
}
// 67BC2: control flows out of bounds to 672B6
// 676DA: variable 'v21' is possibly undefined
// 676CC: variable 'v19' is possibly undefined
// 67861: variable 'v8' is possibly undefined
// 67993: variable 'v12' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17EEE0: using guessed type _UNKNOWN *off_17EEE0;
// 18B0E0: using guessed type int16_t word_18B0E0[40];
// 19269C: using guessed type int dword_19269C[39];
// 192784: using guessed type int dword_192784;
// 1927A4: using guessed type int dword_1927A4;
// 1927A8: using guessed type int dword_1927A8;
// 1975C4: using guessed type int dword_1975C4;
// 199856: using guessed type int16_t word_199856;
// 19995E: using guessed type int16_t word_19995E;
// 19B96A: using guessed type int16_t word_19B96A;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;
// 19B974: using guessed type int16_t word_19B974;
// 19B97A: using guessed type int16_t word_19B97A;
// 19B97C: using guessed type int16_t word_19B97C;
// 19B994: using guessed type char byte_19B994;


//----- (00067BC7) --------------------------------------------------------
void sub_67BC7(int a1)
{
  _DWORD *v1; // ebx
  char *v2; // edi
  char *v3; // ebx
  char *v4; // edi
  int v5; // [esp+0h] [ebp-FB8h] BYREF
  char v6[2664]; // [esp+4h] [ebp-FB4h] BYREF
  char v7[1332]; // [esp+A6Ch] [ebp-54Ch] BYREF
  char v8[20]; // [esp+FA0h] [ebp-18h] BYREF
  _DWORD *v9; // [esp+FB4h] [ebp-4h]

  v5 = a1;
  sub_A6547(v8);
  sub_1112EC(dword_192ED4, 5000);
  v9 = sub_110D3C(dword_192ED4, 5000);
  sub_110D3C(dword_192ED4, 1403);
  strcpy(v6, (char *)sub_126C37((int)v8, 0, (int)v9, 0x190u, 1u, 1403) + 103);
  v1 = v9;
  v2 = (char *)&v5 + 3;
  do
    ++v2;
  while ( *v2 );
  strcpy(v2, asc_1791D4);
  v3 = (char *)sub_126C37((int)v8, 0, (int)v1, (int16_t)(v5 + 400), 1u, 1403);
  strcpy(v7, v3 + 103);
  v4 = (char *)&v5 + 3;
  do
    ++v4;
  while ( *v4 );
  strcpy(v4, v7);
  sub_A5EB2((int)v3, (int)v6);
  JUMPOUT(0x66263);
}
// 67CB2: control flows out of bounds to 66263
// 192ED4: using guessed type int dword_192ED4;


//----- (00067CCF) --------------------------------------------------------
void sub_67CCF( int a1)
{
  char v2; // dl
  int v3; // esi
  int16_t v4; // ax
  int16_t v5; // di
  int16_t v6; // bx
  int v7; // eax
  int16_t v8; // cx
  uint16_t v9; // ax
  uint16_t v10; // ax
  int16_t v11; // bx
  char v12[200]; // [esp+0h] [ebp-4Ah] BYREF
  char v13[200]; // [esp+C8h] [ebp+7Eh] BYREF
  int v14; // [esp+190h] [ebp+146h]

  v2 = byte_19B985[a1] + 7;
  v12[0] = 0;
  v3 = 15 * a1;
  switch ( v2 )
  {
    case 0:
      sub_66870(a1);
      v5 = v4;
      sub_8F6DF(0x3Au, v13);
      sprintf(
        v12,
        v13,
        *(_UNKNOWN **)((char *)&off_17FD0B + v3),
        *(_DWORD *)(dword_1927A8 + 237) + v5 - *(_DWORD *)(dword_1927A8 + 233));
      break;
    case 1:
      v6 = word_17F80D[14 * *(int16_t *)(6 * word_19B972 + dword_192694)];
      sub_6D048(word_19999C, v6);
      v14 = v7;
      v8 = (uint8_t)byte_17FD14[v3];
      if ( (uint8_t)byte_17FD14[v3] - (int16_t)v7 == 1 )
        v9 = 59;
      else
        v9 = 60;
      sub_8F6DF(v9, v13);
      sprintf(
        v12,
        v13,
        v8 - (int16_t)v14,
        *(_UNKNOWN **)((char *)&off_17E079 + 13 * v6),
        *(_UNKNOWN **)((char *)&off_17FD0B + 15 * a1));
      break;
    case 2:
      v10 = 61;
      goto LABEL_8;
    case 3:
      v10 = 62;
      goto LABEL_8;
    case 4:
      v10 = 63;
LABEL_8:
      strcpy(v12, sub_7A990(v10));
      break;
    case 5:
      v11 = *(_WORD *)(dword_192694 + 6 * word_19B972);
      sub_8F6DF(0x40u, v13);
      sprintf(v12, v13, *(_UNKNOWN **)((char *)&off_17FD0B + v3), *(&off_17F803 + 7 * v11));
      break;
    default:
      break;
  }
  if ( v12[0] )
    sub_77423((int)v12);
  JUMPOUT(0x68D36);
}
// 67E4B: control flows out of bounds to 68D36
// 67D0D: variable 'v4' is possibly undefined
// 67D60: variable 'v7' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 17F803: using guessed type _UNKNOWN *off_17F803;
// 17F80D: using guessed type int16_t word_17F80D[];
// 17FD0B: using guessed type _UNKNOWN *off_17FD0B;
// 192694: using guessed type int dword_192694;
// 1927A8: using guessed type int dword_1927A8;
// 19999C: using guessed type int16_t word_19999C;
// 19B972: using guessed type int16_t word_19B972;


//----- (00067E50) --------------------------------------------------------
void *sub_67E50()
{
  sub_124D41();
  sub_128C32(0, 0, 639, 479, 0);
  sub_6C6CD();
  sub_128BE7();
  sub_12B65C();
  sub_133237();
  sub_1318D4(0, 255);
  sub_90006(0, 0, 639, 479);
  return sub_124DEC();
}


//----- (00067E9C) --------------------------------------------------------
int sub_67E9C( int a1, int a2, _WORD *a3, _WORD *a4)
{
  int v4; // edx
  int16_t v5; // si
  int16_t v6; // di
  int v7; // eax
  int16_t i; // cx
  int v9; // esi

  v4 = -1;
  *a3 = -1;
  v5 = 0;
  *a4 = -1;
  while ( 1 )
  {
    v7 = *(int16_t *)(dword_1975C4 + 8) <= 10 ? *(int16_t *)(dword_1975C4 + 8) : 10;
    if ( v7 <= v5 )
      break;
    if ( a2 == word_192738[v5] )
    {
      v6 = *(_WORD *)(dword_1975C4 + 12) + v5;
      v4 = 0;
    }
    else
    {
      if ( -word_192738[v5] != a2 )
        goto LABEL_7;
      v6 = *(_WORD *)(dword_1975C4 + 12) + v5;
      v4 = 1;
    }
    *a4 = v6;
LABEL_7:
    ++v5;
  }
  if ( (int16_t)v4 == -1 )
  {
    for ( i = 0; ; ++i )
    {
      v9 = *(int16_t *)(dword_1975C4 + 8) <= 10 ? *(int16_t *)(dword_1975C4 + 8) : 10;
      if ( i >= v9 )
        break;
      if ( a1 == word_192738[i] )
      {
        v4 = 4;
        *a3 = i;
      }
    }
  }
  return v4;
}
// 192738: using guessed type int16_t word_192738[10];
// 1975C4: using guessed type int dword_1975C4;


//----- (00067F5C) --------------------------------------------------------
_WORD *sub_67F5C(_WORD *result)
{
  int v1; // ebx
  int16_t v2; // dx

  v1 = word_19B972;
  *result = 0;
  if ( v1 > -1 )
  {
    v2 = 1;
    *result = 0;
    do
    {
      if ( word_1991B6[v2] == 1 )
        *result |= 1 << v2;
      ++v2;
    }
    while ( v2 < 15 );
  }
  return result;
}
// 1991B6: using guessed type int16_t word_1991B6[];
// 19B972: using guessed type int16_t word_19B972;


//----- (00067F9F) --------------------------------------------------------
int16_t sub_67F9F()
{
  _WORD *v0; // ebx
  int v1; // ecx
  int v2; // esi
  int v3; // ecx
  int16_t result; // ax

  v0 = (_WORD *)dword_1975C4;
  v1 = *(int16_t *)(dword_1975C4 + 14);
  v2 = (*(uint8_t *)(dword_1975C4 + 26) * 10 * v1 + 90) / *(int16_t *)(dword_1975C4 + 8) / 10;
  v3 = v1 - *(int16_t *)(dword_1975C4 + 6) / 2;
  result = *(uint8_t *)(dword_1927A8 + 290);
  *(_WORD *)(dword_1975C4 + 12) = result;
  LOWORD(v3) = v3 - result * v2;
  *v0 = v3;
  v0[1] = v3;
  v0[2] = v3;
  return result;
}
// 1927A8: using guessed type int dword_1927A8;
// 1975C4: using guessed type int dword_1975C4;


//----- (00067FFC) --------------------------------------------------------
void sub_67FFC( int a1)
{
  int v2; // eax
  int16_t v3; // ax
  char v4; // bl
  int16_t i; // dx
  int16_t v6; // ax
  int16_t v7; // ax
  _DWORD v8[2]; // [esp+0h] [ebp-10h] BYREF
  int16_t v9; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]

  v8[0] = 327682;
  v8[1] = 983050;
  v9 = 20;
  memset(word_1991B6, 0, 30);
  v2 = dword_1927A8 + 2 * a1;
  word_19B976 = 0;
  if ( *(int16_t *)(v2 + 53) <= 0 )
  {
    word_19B966 = 0;
  }
  else
  {
    v3 = *(_WORD *)(v2 + 93);
    v4 = 0;
    word_19B976 = *(uint8_t *)(dword_1927A8 + a1 + 85);
    word_19B966 = v3;
    for ( i = 1; i < *(int16_t *)(dword_1975C4 + 8) && !v4; ++i )
    {
      v10 = dword_1927A8 + 2 * a1;
      if ( *(_WORD *)(dword_192694 + 6 * i) == *(_WORD *)(v10 + 53) )
      {
        v4 = 1;
        word_19B972 = i;
        *(_WORD *)(dword_1975C4 + 12) = i;
        sub_68177();
      }
    }
    if ( !v4 )
      word_19B972 = -1;
    if ( sub_6EDAE(*(_WORD *)(dword_1927A8 + 2 * a1 + 53)) )
      word_19B978 = sub_C5AA7(*(uint8_t *)(a1 + dword_1927A8 + 173), (int)v8, 5u);
    else
      word_19B978 = 1;
  }
  v6 = 1;
  while ( 1 )
  {
    if ( ((word_19B966 >> v6) & 1) != 0 )
      word_1991B6[v6] = 1;
    if ( ++v6 >= 15 )
    {
      word_19B966 = 0;
      v7 = 1;
      while ( 1 )
      {
        if ( word_1991B6[v7] == 1 )
          word_19B966 |= 1 << v7;
        if ( ++v7 >= 15 )
          JUMPOUT(0x66268);
      }
    }
  }
}
// 68172: control flows out of bounds to 66268
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 192694: using guessed type int dword_192694;
// 1927A8: using guessed type int dword_1927A8;
// 1975C4: using guessed type int dword_1975C4;
// 1991B6: using guessed type int16_t word_1991B6[];
// 19B966: using guessed type int16_t word_19B966;
// 19B972: using guessed type int16_t word_19B972;
// 19B976: using guessed type int16_t word_19B976;
// 19B978: using guessed type int16_t word_19B978;


//----- (00068177) --------------------------------------------------------
int sub_68177()
{
  int16_t *v0; // ebx
  int v1; // eax
  int v2; // edx
  _WORD *v3; // ebx
  int v4; // eax
  int result; // eax

  v0 = (int16_t *)dword_1975C4;
  if ( *(int16_t *)(dword_1975C4 + 8) >= 10 )
  {
    v1 = (1200 / *(int16_t *)(dword_1975C4 + 8) + 9) / 10;
    if ( *(int16_t *)(dword_1975C4 + 12) + *(int16_t *)(dword_1975C4 + 10) <= *(int16_t *)(dword_1975C4 + 8) )
    {
      v2 = *(int16_t *)(dword_1975C4 + 10);
      *(_WORD *)dword_1975C4 = *(_WORD *)(dword_1975C4 + 14) - v1 * word_19B972;
      if ( *v0 < v2 * (int16_t)v1 )
        *v0 = v0[5] * v1;
      if ( *(_WORD *)dword_1975C4 > *(_WORD *)(dword_1975C4 + 14) )
        *(_WORD *)dword_1975C4 = *(_WORD *)(dword_1975C4 + 14);
      if ( *(int16_t *)dword_1975C4 < 0 )
        *(_WORD *)dword_1975C4 = 0;
    }
    else
    {
      *(_WORD *)dword_1975C4 = *(_WORD *)(dword_1975C4 + 10) * v1;
      v0[6] = v0[4] - 10;
    }
  }
  else
  {
    *(_WORD *)(dword_1975C4 + 12) = 0;
    *v0 = v0[7];
  }
  v3 = (_WORD *)dword_1975C4;
  v4 = *(int16_t *)dword_1975C4 - *(int16_t *)(dword_1975C4 + 6) / 2;
  *(_WORD *)dword_1975C4 = v4;
  if ( (v4 & 0x8000u) != 0 )
    *v3 = (int16_t)v3[3] / 2;
  result = dword_1975C4;
  *(_WORD *)(dword_1975C4 + 2) = -1;
  return result;
}
// 1975C4: using guessed type int dword_1975C4;
// 19B972: using guessed type int16_t word_19B972;


//----- (0006825F) --------------------------------------------------------
char sub_6825F( int a1)
{
  char v1; // dl

  v1 = 0;
  if ( byte_19B985[a1] == 1 || byte_19B985[a1] == -7 || byte_19B985[a1] == -4 || byte_19B985[a1] == -5 )
    return 1;
  return v1;
}


//----- (0006828D) --------------------------------------------------------
void sub_6828D()
{
  int16_t v0; // dx
  int16_t v1; // bx

  v0 = 1;
  *(_BYTE *)(dword_1927A8 + 250) = 1;
  while ( 1 )
  {
    v1 = *(_WORD *)(dword_192694 + 6 * v0);
    *(_BYTE *)(v0 + dword_1927A8 + 250) = 0;
    if ( v1 > -1
      && *(_BYTE *)(word_17F80D[14 * v1] + dword_197F98 + 3753 * word_19999C + 279) == 3
      && sub_6831F(v1, v0, v0) <= *(_DWORD *)(dword_1927A8 + 233) )
    {
      *(_BYTE *)(v0 + dword_1927A8 + 250) = 1;
    }
    if ( ++v0 >= 40 )
      JUMPOUT(0x68D37);
  }
}
// 6831A: control flows out of bounds to 68D37
// 17F80D: using guessed type int16_t word_17F80D[];
// 192694: using guessed type int dword_192694;
// 1927A8: using guessed type int dword_1927A8;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0006831F) --------------------------------------------------------
int16_t sub_6831F( int a1, int a2, int a3)
{
  int v3; // ecx
  char v4; // bl
  int16_t v5; // ax
  char v6; // bl
  int16_t v7; // ax
  int16_t v8; // dx
  int16_t v9; // ax
  char v10; // bl
  int16_t v11; // ax
  int16_t result; // ax

  if ( a1 > 0 )
  {
    v3 = 14 * a1;
    if ( sub_6EDAE(a1) )
    {
      v4 = sub_6F11C(word_17F80D[v3]);
      sub_6E70A(word_19999C, word_17F80D[v3]);
      a3 = sub_6E60E(word_17F811[v3], v5, v4);
      v6 = sub_6F11C(word_17F80D[v3]);
      sub_6E70A(word_19999C, word_17F80D[v3]);
      v8 = v7;
      v9 = sub_6F1CC(2u);
      a2 = sub_6E60E(v9, v8, v6);
    }
    else
    {
      v10 = sub_6F11C(word_17F80D[v3]);
      sub_6E70A(word_19999C, word_17F80D[v3]);
      a3 = sub_6E60E(word_17F811[v3], v11, v10);
      a2 = 0;
    }
  }
  result = a2 + a3 + *(_WORD *)(dword_1927A8 + 237);
  if ( word_199856 > -1 && *(int16_t *)(dword_1927A8 + 2 * word_199856 + 53) > 0 )
    result -= *(_WORD *)(dword_1927A8 + 4 * word_199856 + 141);
  return result;
}
// 6836A: variable 'v5' is possibly undefined
// 68393: variable 'v7' is possibly undefined
// 683D6: variable 'v11' is possibly undefined
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F811: using guessed type int16_t word_17F811[];
// 1927A8: using guessed type int dword_1927A8;
// 199856: using guessed type int16_t word_199856;
// 19999C: using guessed type int16_t word_19999C;


//----- (00068413) --------------------------------------------------------
void sub_68413()
{
  int v0; // edx
  int v1; // eax
  int16_t v2; // bx
  int v3; // eax
  int v4; // edi
  int16_t v5; // cx
  int16_t i; // dx
  int16_t v7; // cx
  int v8; // esi
  char v9; // di
  int16_t v10; // ax
  int16_t v11; // bx
  int v12; // eax

  memset(dword_1927A8 + 250, 0, 40);
  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    word_18B0E0[v1] = -1;
    word_18B090[v1] = 0;
  }
  while ( (int16_t)v0 < 40 );
  word_18B0E0[0] = 0;
  v2 = 0;
  *(_WORD *)(dword_1975C4 + 8) = 1;
  while ( v2 < 39 )
  {
    v3 = dword_1975C4;
    if ( *(int16_t *)(dword_1975C4 + 8) >= 40 )
      break;
    if ( *(_BYTE *)(*(int16_t *)((char *)&word_17EEE6 + 47 * v2) + dword_197F98 + 3753 * word_19999C + 279) == 3 )
    {
      word_18B0E0[*(int16_t *)(dword_1975C4 + 8)] = v2;
      if ( (int16_t)++*(_WORD *)(v3 + 8) >= 40 )
        break;
    }
    ++v2;
  }
  v4 = dword_1927A8;
  v5 = 0;
  while ( 1 )
  {
    if ( *(int16_t *)(dword_1927A8 + 2 * v5 + 181) > 0 )
    {
      for ( i = 0; i < *(int16_t *)(dword_1975C4 + 8); ++i )
      {
        if ( *(_WORD *)(v4 + 2 * v5 + 181) == word_18B0E0[i]
          && word_199856 > -1
          && *(_WORD *)(v4 + 2 * word_199856 + 181) != word_18B0E0[i] )
        {
          word_18B090[i] = 1;
        }
      }
    }
    if ( ++v5 >= 8 )
    {
      v7 = 1;
      v8 = 0;
      while ( v7 < *(int16_t *)(dword_1975C4 + 8) )
      {
        v9 = sub_6F11C(*(int16_t *)((char *)&word_17EEE6 + 47 * word_18B0E0[v7]));
        sub_6E70A(word_19999C, *(int16_t *)((char *)&word_17EEE6 + 47 * word_18B0E0[v7]));
        v11 = sub_6E60E(
                *(int16_t *)((char *)word_17EEE8 + 47 * word_18B0E0[v7] + 2 * *(int16_t *)(dword_1927A8 + 229)),
                v10,
                v9);
        v12 = 2 * word_199856 + dword_1927A8;
        if ( *(int16_t *)(v12 + 181) > 0 )
          v11 -= *(_WORD *)(v12 + 213);
        if ( *(_DWORD *)(dword_1927A8 + 237) + v11 <= *(_DWORD *)(dword_1927A8 + 233) && !word_18B090[v7] )
          ++v8;
        ++v7;
      }
      JUMPOUT(0x66268);
    }
  }
}
// 6860E: control flows out of bounds to 66268
// 685A9: variable 'v10' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EEE8: using guessed type int16_t word_17EEE8[6];
// 18B090: using guessed type int16_t word_18B090[40];
// 18B0E0: using guessed type int16_t word_18B0E0[40];
// 1927A8: using guessed type int dword_1927A8;
// 1975C4: using guessed type int dword_1975C4;
// 197F98: using guessed type int dword_197F98;
// 199856: using guessed type int16_t word_199856;
// 19999C: using guessed type int16_t word_19999C;


//----- (00068613) --------------------------------------------------------
void sub_68613(int a1, _WORD *a2)
{
  int16_t i; // bx
  int16_t j; // cx
  int16_t v4; // di
  int16_t v5; // [esp+0h] [ebp-10h]
  int16_t v6; // [esp+Ch] [ebp-4h]

  v6 = 0;
  *a2 = 0;
  for ( i = 0; i < 6 && !v6; ++i )
  {
    if ( *(int16_t *)((char *)&word_17EF00 + 47 * v5 + 2 * i) > 0 )
    {
      for ( j = 0; j < 8 && !v6; ++j )
      {
        v4 = *(_WORD *)(dword_1927A8 + 2 * j + 181);
        if ( v4 == *(int16_t *)((char *)&word_17EF00 + 47 * v5 + 2 * i)
          && v4 != *(_WORD *)(dword_1927A8 + 2 * word_199856 + 181) )
        {
          v6 = 1;
          *a2 = v4;
        }
      }
    }
  }
  JUMPOUT(0x654D7);
}
// 686C6: control flows out of bounds to 654D7
// 68636: variable 'v5' is possibly undefined
// 17EF00: using guessed type int16_t word_17EF00;
// 1927A8: using guessed type int dword_1927A8;
// 199856: using guessed type int16_t word_199856;


//----- (000686CB) --------------------------------------------------------
int sub_686CB(int a1, int a2)
{
  int16_t v2; // si
  int16_t v3; // bx
  int16_t v4; // ax
  int result; // eax

  v2 = *(_WORD *)(dword_19275C + 2);
  v3 = *(_WORD *)(dword_19277C + 2);
  if ( a2 <= 10 )
    v4 = a2;
  else
    v4 = 10;
  word_19B96A = *(_WORD *)(dword_192788 + 2) + 16 * v4 + 20;
  word_19B97A = v3 + v2 + word_19B96A;
  word_19B974 = *(_WORD *)dword_19275C;
  word_19B96C = (640 - word_19B974) / 2;
  result = (440 - word_19B97A) / 2;
  word_19B96E = result;
  return result;
}
// 19275C: using guessed type int dword_19275C;
// 19277C: using guessed type int dword_19277C;
// 192788: using guessed type int dword_192788;
// 19B96A: using guessed type int16_t word_19B96A;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;
// 19B974: using guessed type int16_t word_19B974;
// 19B97A: using guessed type int16_t word_19B97A;


//----- (00068755) --------------------------------------------------------
int16_t sub_68755(int16_t *a1)
{
  int v1; // eax
  int v2; // eax
  int16_t v3; // ax
  int v4; // ebx
  int v5; // ecx
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int16_t v10; // dx
  int16_t *v11; // edx
  int v12; // edi
  void *v13; // eax
  int16_t v14; // si
  char *v15; // eax
  int v16; // eax
  int16_t v17; // ax
  int16_t v18; // ax
  _BOOL1 v19; // al
  char *v20; // eax
  char *v21; // eax
  int16_t v22; // ax
  int v23; // eax
  _WORD *v24; // eax
  int v25; // ebx
  uint8_t *v27; // [esp-Ch] [ebp-7BEh]
  char *v28; // [esp-8h] [ebp-7BAh]
  uint8_t *v29; // [esp-4h] [ebp-7B6h]
  char v30[1332]; // [esp+0h] [ebp-7B2h] BYREF
  char v31[200]; // [esp+534h] [ebp-27Eh] BYREF
  char v32[200]; // [esp+5FCh] [ebp-1B6h] BYREF
  char v33[200]; // [esp+6C4h] [ebp-EEh] BYREF
  _BYTE v34[120]; // [esp+78Ch] [ebp-26h] BYREF
  int v35; // [esp+804h] [ebp+52h]
  int v36; // [esp+808h] [ebp+56h]
  int16_t v37; // [esp+80Ch] [ebp+5Ah] BYREF
  int16_t v38; // [esp+810h] [ebp+5Eh] BYREF
  int v39; // [esp+814h] [ebp+62h]
  int v40; // [esp+818h] [ebp+66h]
  int v41; // [esp+81Ch] [ebp+6Ah]
  char *v42; // [esp+820h] [ebp+6Eh]
  int16_t v43; // [esp+824h] [ebp+72h] BYREF
  int v44; // [esp+828h] [ebp+76h]
  char v45; // [esp+82Ch] [ebp+7Ah]
  _BOOL1 v46; // [esp+830h] [ebp+7Eh]

  sub_1112EC(dword_192EE8, 29);
  dword_1975C4 = (int)sub_110D3C(dword_192EE8, 29);
  memset(dword_1975C4, 0, 29);
  v1 = dword_1975C4;
  *(_WORD *)(dword_1975C4 + 12) = 0;
  *(_WORD *)v1 = 140;
  word_19B972 = -1;
  *(_WORD *)(v1 + 10) = 10;
  word_19995E = 0;
  *(_WORD *)(v1 + 14) = 140;
  byte_19B995 = 1;
  *(_BYTE *)(v1 + 24) = 2;
  *(_BYTE *)(v1 + 26) = 1;
  sub_124D41();
  v2 = sub_6C6CD();
  sub_1077D(v2, 255, 29, a1);
  sub_124DEC();
  sub_128BE7();
  sub_12B65C();
  sub_133237();
  sub_1318D4(0, 255);
  sub_124D41();
  sub_90006(0, 0, 639, 479);
  sub_124DEC();
  sub_68413();
  v3 = sub_A00F1((_WORD *)dword_1975C4);
  v4 = dword_1975C4;
  v45 = 1;
  v39 = 1;
  *(_WORD *)(dword_1975C4 + 6) = v3;
  v5 = *(int16_t *)(v4 + 14);
  v6 = (10 * v5 * *(uint8_t *)(v4 + 26) + 90) / *(int16_t *)(v4 + 8) / 10;
  v7 = v5 - *(int16_t *)(v4 + 6) / 2;
  HIWORD(v8) = HIWORD(dword_1927A8);
  LOWORD(v8) = *(uint8_t *)(dword_1927A8 + 290);
  *(_WORD *)(v4 + 12) = v8;
  v9 = v7 - v8 * v6;
  *(_WORD *)v4 = v9;
  v10 = *(_WORD *)(v4 + 8);
  *(_WORD *)(v4 + 2) = v9;
  *(_WORD *)(v4 + 4) = v9;
  sub_686CB(610, v10);
  sub_1191CA((int)sub_65853, 3);
  sub_11C2F0();
  v11 = &v38;
  v12 = 0;
  LOWORD(v13) = sub_65288(&v37, &v38);
  byte_19B994 = 0;
  while ( !(_WORD)v12 )
  {
    v14 = sub_1171AB((int)v13, (int)&v38, v4, v9);
    v15 = sub_114177();
    v44 = v12;
    word_19B97C = -1;
    v42 = v15;
    while ( 1 )
    {
      v23 = *(int16_t *)(dword_1975C4 + 8) >= 10 ? 10 : *(int16_t *)(dword_1975C4 + 8);
      if ( (int16_t)v44 >= v23 || (_WORD)v12 )
        break;
      HIWORD(v9) = HIWORD(v44);
      LOWORD(v9) = *(_WORD *)(dword_1975C4 + 12) + v44;
      if ( (_WORD)v42 == word_192738[(int16_t)v44] )
        word_19B97C = v44;
      if ( v14 == word_192738[(int16_t)v44] )
      {
        if ( (_WORD)v9 )
        {
          sub_68613(word_18B0E0[(int16_t)v9], &v43);
          v40 = v16;
          v41 = sub_66742();
          if ( word_18B0E0[(int16_t)v9] != 4 )
          {
            v36 = (uint8_t)sub_6F11C(*(int16_t *)((char *)&word_17EEE6 + 47 * word_18B0E0[(int16_t)v9]));
            v17 = *(int16_t *)((char *)&word_17EEE6 + 47 * word_18B0E0[(int16_t)v9]);
            v35 = word_19999C;
            sub_6E70A(word_19999C, v17);
            sub_6E60E(
              *(int16_t *)((char *)word_17EEE8 + 47 * word_18B0E0[(int16_t)v9] + 2 * *(int16_t *)(dword_1927A8 + 229)),
              v18,
              v36);
          }
          v19 = (int16_t)v41 < 8 && !(_WORD)v40;
          v4 = 2 * (int16_t)v9;
          v46 = v19;
          if ( *(int16_t *)((char *)word_18B090 + v4)
            && *(_WORD *)(dword_1927A8 + 2 * word_199856 + 181) != word_18B0E0[(int16_t)v9] )
          {
            sub_8F6DF(0x41u, v33);
            sprintf(v34, v33, *(_UNKNOWN **)((char *)&off_17EEE0 + 47 * word_18B0E0[(int16_t)v9]));
LABEL_20:
            v39 = 1;
            sub_77433(v34);
            goto LABEL_37;
          }
          if ( v46 )
          {
            v4 = dword_1927A8;
            word_19B972 = v9;
            v12 = 1;
            *(_WORD *)(dword_1927A8 + 2 * word_199856 + 181) = word_18B0E0[(int16_t)v9];
          }
          else if ( (_WORD)v40 )
          {
            v4 = 2 * (int16_t)v9;
            if ( !strcmp(
                    *(_UNKNOWN **)((char *)&off_17EEE0 + 47 * *(int16_t *)((char *)word_18B0E0 + v4)),
                    *(_UNKNOWN **)((char *)&off_17EEE0 + 47 * v43)) )
            {
              sub_8F6DF(0x42u, v32);
              sprintf(v34, v32, *(_UNKNOWN **)((char *)&off_17EEE0 + 47 * word_18B0E0[(int16_t)v9]));
            }
            else
            {
              sub_8F6DF(0x43u, v31);
              v29 = *(uint8_t **)((char *)&off_17EEE0 + 47 * word_18B0E0[(int16_t)v9]);
              if ( sub_8F8DC(*v29) )
                v20 = aAn_0;
              else
                v20 = aA_2;
              v28 = v20;
              v27 = *(uint8_t **)((char *)&off_17EEE0 + 47 * v43);
              if ( sub_8F8DC(*v27) )
                v21 = aAn_0;
              else
                v21 = aA_2;
              sprintf(v34, v31, v21, v27, v28, v29);
            }
            goto LABEL_20;
          }
        }
        else
        {
          v4 = word_199856;
          if ( *(int16_t *)(dword_1927A8 + 2 * word_199856 + 181) > 0 )
            sub_6B3B4(word_199856);
          v12 = 1;
        }
      }
      else if ( v14 == -word_192738[(int16_t)v44] )
      {
        v22 = word_18B0E0[(int16_t)v9];
        if ( v22 <= 0 )
        {
          sub_A59A1();
        }
        else
        {
          v4 = 47 * v22;
          sub_6FBEA(v30, *(int16_t *)((char *)&word_17EEE6 + v4));
          sub_A5EB2(*(int *)((char *)&off_17EEE0 + v4), (int)v30);
        }
      }
LABEL_37:
      ++v44;
    }
    if ( v14 == word_199862 )
    {
      sub_A01C6((int16_t *)dword_1975C4);
      byte_19B994 = 0;
    }
    if ( v14 == word_199850 )
    {
      sub_A015D((int16_t *)dword_1975C4);
      byte_19B994 = 0;
    }
    if ( v14 == v38 || v14 == v37 )
    {
      v12 = 1;
    }
    else if ( v14 == -v38 || v14 == -v37 )
    {
      sub_A59A1();
    }
    sub_11C2F0();
    v11 = &v38;
    LOWORD(v13) = sub_65288(&v37, &v38);
    if ( !(_WORD)v12 && !(_WORD)v39 && v45 )
    {
      v13 = sub_67E50();
      v45 = 0;
    }
    if ( !(_WORD)v12 )
    {
      sub_124D41();
      sub_65853();
      if ( (_WORD)v39 )
        v39 = v12;
      else
        v13 = (void *)sub_1077D((int)v13, (int)&v38, v4, (int16_t *)v12);
    }
  }
  v24 = (_WORD *)dword_1975C4;
  v25 = dword_1927A8;
  LOBYTE(v11) = *(_BYTE *)(dword_1975C4 + 12);
  *(_BYTE *)(dword_1927A8 + 290) = (_BYTE)v11;
  *(_WORD *)(v25 + 291) = *v24;
  dword_1975C4 = 0;
  sub_1113CC(dword_192EE8, (int)v11);
  word_199A08 = 3;
  sub_6E8DA(word_19999C);
  return sub_11C2F0();
}
// 689E6: conditional instruction was optimized away because cx.2!=0
// 688C8: variable 'v13' is possibly undefined
// 68961: variable 'v16' is possibly undefined
// 689DE: variable 'v18' is possibly undefined
// 77433: using guessed type int sub_77433(_DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 138B90: using guessed type int strcmp(_DWORD, _DWORD);
// 17EEE0: using guessed type _UNKNOWN *off_17EEE0;
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EEE8: using guessed type int16_t word_17EEE8[6];
// 18B090: using guessed type int16_t word_18B090[40];
// 18B0E0: using guessed type int16_t word_18B0E0[40];
// 192738: using guessed type int16_t word_192738[10];
// 1927A8: using guessed type int dword_1927A8;
// 192EE8: using guessed type int dword_192EE8;
// 1975C4: using guessed type int dword_1975C4;
// 199850: using guessed type int16_t word_199850;
// 199856: using guessed type int16_t word_199856;
// 199862: using guessed type int16_t word_199862;
// 19995E: using guessed type int16_t word_19995E;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 19B972: using guessed type int16_t word_19B972;
// 19B97C: using guessed type int16_t word_19B97C;
// 19B994: using guessed type char byte_19B994;
// 19B995: using guessed type char byte_19B995;


//----- (00068D3D) --------------------------------------------------------
int sub_68D3D( int a1, _WORD *a2, int16_t *a3, int a4)
{
  int16_t v6; // dx
  int v7; // ebx
  int v8; // eax
  int16_t v9; // di
  int result; // eax
  int16_t v11; // ax
  char v12; // cl
  int16_t v13; // ax
  int v14; // [esp+0h] [ebp-4h]

  v6 = word_18B0E0[a1];
  v7 = 47 * v6;
  v8 = *(int16_t *)(dword_1927A8 + 229);
  LOWORD(a4) = *(int16_t *)((char *)&word_17EEF4[v8] + v7);
  v14 = a4;
  v9 = *(int16_t *)((char *)&word_17EEE8[v8] + v7);
  if ( v6 == 4 )
  {
    result = v14;
    *a2 = v14;
    *a3 = v9;
  }
  else
  {
    sub_6E70A(word_19999C, *(int16_t *)((char *)&word_17EEE6 + 47 * v6));
    *a2 = sub_6B519(v14, v11);
    v12 = sub_6F11C(*(int16_t *)((char *)&word_17EEE6 + 47 * v6));
    sub_6E70A(word_19999C, *(int16_t *)((char *)&word_17EEE6 + 47 * v6));
    result = sub_6E60E(v9, v13, v12);
    *a3 = result;
  }
  return result;
}
// 68DA4: variable 'v11' is possibly undefined
// 68DD6: variable 'v13' is possibly undefined
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EEE8: using guessed type int16_t word_17EEE8[6];
// 17EEF4: using guessed type int16_t word_17EEF4[];
// 18B0E0: using guessed type int16_t word_18B0E0[40];
// 1927A8: using guessed type int dword_1927A8;
// 19999C: using guessed type int16_t word_19999C;


//----- (00068DE3) --------------------------------------------------------
void sub_68DE3( int a1)
{
  int16_t i; // ax
  _BOOL1 v3; // [esp+0h] [ebp-4h]

  if ( *(int16_t *)(dword_1975C4 + 8) > 1 && a1 > -1 )
  {
    v3 = 0;
    for ( i = 0; i < *(int16_t *)(dword_1975C4 + 8) && !v3; ++i )
      v3 = a1 == *(_WORD *)(6 * i + dword_192694);
  }
  JUMPOUT(0x667F7);
}
// 68E3B: control flows out of bounds to 667F7
// 192694: using guessed type int dword_192694;
// 1975C4: using guessed type int dword_1975C4;


//----- (00068E78) --------------------------------------------------------
int16_t sub_68E78(int a1, int a2, int a3)
{
  int16_t result; // ax
  int v4; // eax
  int v5; // ebx
  int16_t v6; // ax
  int v7; // edi
  int v8; // edi
  int v9; // eax
  int v10; // edx
  int v11; // edx
  int v12; // eax
  int16_t v13; // dx
  int v14; // eax
  int16_t v15; // [esp+0h] [ebp-70h]
  _WORD *v16; // [esp+4h] [ebp-6Ch]
  char v17[80]; // [esp+8h] [ebp-68h] BYREF
  _DWORD v18[2]; // [esp+58h] [ebp-18h]
  int16_t v19; // [esp+60h] [ebp-10h]
  int v20; // [esp+64h] [ebp-Ch]
  int v21; // [esp+68h] [ebp-8h]
  _BOOL1 v22; // [esp+6Ch] [ebp-4h]

  v18[0] = 327682;
  v18[1] = 983050;
  v19 = *(_WORD *)((char *)&dword_649F4[1] + 3);
  if ( !a2 )
  {
    if ( *(int16_t *)(dword_1927A8 + 2 * a3 + 53) > 0 )
    {
      sub_6B428(a3);
      sub_6E8DA(word_19999C);
    }
LABEL_18:
    result = (int16_t)v16;
    word_199A08 = 3;
    *v16 = 1;
    return result;
  }
  if ( !(uint16_t)sub_691A3(v17) )
    return sub_77423((int)v17);
  result = a2;
  if ( a2 > -1 )
  {
    HIWORD(v4) = a3 >> 15;
    LOWORD(v4) = *(_WORD *)(dword_1927A8 + 4 * a3 + 141);
    v21 = v4;
    v22 = *(_WORD *)(dword_1927A8 + 2 * a3 + 53) > 0;
    v5 = 2 * v15;
    v6 = sub_69529(a2);
    v7 = dword_1927A8;
    *(_WORD *)(dword_1927A8 + v5 + 53) = v6;
    *(_WORD *)(v7 + v5 + 69) = 1;
    sub_67F5C((_WORD *)(v5 + v7 + 93));
    *(_BYTE *)(v15 + dword_1927A8 + 85) = word_19B976;
    sub_6EFEB(*(_WORD *)(6 * a2 + dword_192694));
    if ( sub_6EDAE(*(_WORD *)(v5 + dword_1927A8 + 53)) )
      *(_BYTE *)(v15 + dword_1927A8 + 173) = *((_BYTE *)v18 + 2 * word_19B978);
    else
      *(_BYTE *)(v15 + dword_1927A8 + 173) = 0;
    v8 = 2 * v15;
    v9 = sub_6EE8E(
           word_19999C,
           *(_WORD *)(dword_1927A8 + v8 + 53),
           *(_WORD *)(dword_1927A8 + v8 + 69),
           *(uint8_t *)(dword_1927A8 + v15 + 85),
           *(uint8_t *)(dword_1927A8 + v15 + 173),
           *(_WORD *)(dword_1927A8 + v8 + 93));
    v10 = dword_1927A8;
    v20 = 4 * v15;
    *(_DWORD *)(dword_1927A8 + v20 + 141) = v9;
    v11 = sub_6EC74(
            *(_WORD *)(v10 + v8 + 53),
            *(int16_t *)(v10 + v8 + 69),
            *(uint8_t *)(v10 + v15 + 85),
            *(uint8_t *)(v10 + v15 + 173),
            *(_WORD *)(v10 + v8 + 93));
    v12 = v20 + dword_1927A8;
    *(_DWORD *)(v12 + 109) = v11;
    v13 = *(_WORD *)(v12 + 141);
    if ( v22 && v13 > 0 )
    {
      v14 = (int16_t)v21 / v13;
      if ( v14 <= 1 )
        LOWORD(v14) = 1;
      *(_WORD *)(2 * v15 + dword_1927A8 + 69) = v14;
      if ( (int16_t)v14 > 99 )
        LOWORD(v14) = 99;
      *(_WORD *)(dword_1927A8 + 2 * v15 + 69) = v14;
    }
    sub_6E8DA(word_19999C);
    goto LABEL_18;
  }
  return result;
}
// 68F11: variable 'v15' is possibly undefined
// 69074: variable 'v16' is possibly undefined
// 649F4: using guessed type int[2];
// 192694: using guessed type int dword_192694;
// 1927A8: using guessed type int dword_1927A8;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 19B976: using guessed type int16_t word_19B976;
// 19B978: using guessed type int16_t word_19B978;


//----- (0006908A) --------------------------------------------------------
void sub_6908A(int a1)
{
  int v2; // edi
  int16_t v3; // bx
  _BYTE *v4; // edx
  int16_t v5; // ax
  int16_t v6; // [esp+4h] [ebp-10h]
  int16_t v7; // [esp+Ch] [ebp-8h]

  memset(a1, 0, 15);
  v2 = 0;
  if ( word_19B972 > -1 )
  {
    v6 = *(_WORD *)(dword_192694 + 6 * word_19B972);
    v3 = 1;
    v7 = word_17F80D[14 * v6];
    do
    {
      if ( v3 == 13 )
      {
        if ( byte_17F80F[28 * v6] == 1 && *(_BYTE *)(3753 * word_19999C + dword_197F98 + 338) == 3 )
        {
          ++v2;
          sub_66870(13);
          *(_BYTE *)(a1 + 13) = 1;
        }
        else
        {
          *(_BYTE *)(a1 + 13) = -3;
        }
      }
      else if ( ((word_17F81D[14 * v6] >> v3) & 1) != 0 )
      {
        sub_6D048(word_19999C, v7);
        v4 = (_BYTE *)(a1 + v3);
        if ( v5 < (uint8_t)byte_17FD14[15 * v3] )
        {
          *v4 = -6;
        }
        else
        {
          sub_66870(v3);
          ++v2;
          *v4 = 1;
        }
      }
      else
      {
        *(_BYTE *)(a1 + v3) = -2;
      }
      ++v3;
    }
    while ( v3 < 15 );
  }
  JUMPOUT(0x66268);
}
// 6919E: control flows out of bounds to 66268
// 69176: variable 'v5' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F81D: using guessed type int16_t word_17F81D[];
// 192694: using guessed type int dword_192694;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19B972: using guessed type int16_t word_19B972;


//----- (000691A3) --------------------------------------------------------
int sub_691A3(char *a1)
{
  int v2; // edx
  int16_t v3; // ax

  *a1 = 0;
  v2 = 1;
  if ( word_19B972 > -1 )
  {
    v3 = sub_69529(word_19B972);
    if ( !sub_6EFEB(v3) && word_19B976 == -1 )
    {
      v2 = 0;
      strcpy(a1, sub_7A990(0x44u));
    }
  }
  if ( word_19B972 < 0 || word_19B972 > *(int16_t *)(dword_1975C4 + 8) )
    word_19B972 = 0;
  return v2;
}
// 1975C4: using guessed type int dword_1975C4;
// 19B972: using guessed type int16_t word_19B972;
// 19B976: using guessed type int16_t word_19B976;


//----- (0006921B) --------------------------------------------------------
void sub_6921B( int a1)
{
  int v2; // edx
  int v3; // eax
  int16_t v4; // bx
  int16_t v5; // ax
  char v6; // cl
  _BOOL1 v7; // zf
  int16_t v8; // ax
  int v9; // ecx
  int v10; // edx
  int v11; // edx
  int16_t v12; // si
  int16_t v13; // di
  int v14; // ecx
  char v15; // bl
  int16_t v16; // ax
  char v17; // bl
  int16_t v18; // ax
  int16_t v19; // dx
  int16_t v20; // ax
  int16_t v21; // dx
  char v22; // bl
  int16_t v23; // ax
  int16_t v24; // bx
  int16_t v25; // [esp+4h] [ebp-10h]
  int16_t v26; // [esp+8h] [ebp-Ch]

  memset(dword_1927A8 + 250, 0, 40);
  memset(dword_192694, -1, 240);
  v2 = dword_192694;
  *(_WORD *)dword_192694 = 0;
  v3 = dword_1927A8;
  *(_DWORD *)(v2 + 2) = 99999;
  *(_BYTE *)(v3 + 250) = 1;
  v4 = 1;
  *(_WORD *)(dword_1975C4 + 8) = 1;
  while ( 1 )
  {
    if ( v4 >= 40 )
    {
LABEL_26:
      sub_68177();
      v12 = 1;
      v13 = 0;
      while ( v12 < *(int16_t *)(dword_1975C4 + 8) )
      {
        v14 = 14 * *(int16_t *)(dword_192694 + 6 * v12);
        if ( sub_6EDAE(*(_WORD *)(dword_192694 + 6 * v12)) )
        {
          v15 = sub_6F11C(word_17F80D[v14]);
          sub_6E70A(word_19999C, word_17F80D[v14]);
          v25 = sub_6E60E(word_17F811[v14], v16, v15);
          v17 = sub_6F11C(word_17F80D[v14]);
          sub_6E70A(word_19999C, word_17F80D[v14]);
          v19 = v18;
          v20 = sub_6F1CC(2u);
          v21 = sub_6E60E(v20, v19, v17);
        }
        else
        {
          v22 = sub_6F11C(word_17F80D[v14]);
          sub_6E70A(word_19999C, word_17F80D[v14]);
          v25 = sub_6E60E(word_17F811[v14], v23, v22);
          v21 = 0;
        }
        v24 = v21 + v25 + *(_WORD *)(dword_1927A8 + 237);
        if ( *(int16_t *)(dword_1927A8 + 2 * word_199856 + 53) > 0 )
          v24 -= *(_WORD *)(dword_1927A8 + 4 * word_199856 + 141);
        if ( v24 <= *(_DWORD *)(dword_1927A8 + 233) )
          ++v13;
        ++v12;
      }
      if ( !v13 )
        strcpy((char *)&word_18FF78, sub_7A990(0x45u));
      JUMPOUT(0x66268);
    }
    *(_BYTE *)(dword_1927A8 + v4 + 250) = 0;
    v26 = word_17F80D[14 * v4];
    if ( *(_BYTE *)(v26 + 3753 * a1 + dword_197F98 + 279) == 3 )
      break;
LABEL_24:
    ++v4;
  }
  if ( v4 <= -1 )
  {
LABEL_23:
    if ( *(int16_t *)(dword_1975C4 + 8) >= 40 )
      goto LABEL_26;
    goto LABEL_24;
  }
  v5 = sub_6EFEB(v4);
  v6 = 0;
  if ( v5 )
  {
    if ( (uint16_t)v5 <= 2u )
    {
      v7 = byte_181751 == 0;
    }
    else
    {
      if ( (uint16_t)v5 > 3u )
      {
        if ( (uint16_t)v5 > 5u || !byte_181753 || word_17F80B[14 * v4] == 39 && sub_666F5() )
        {
LABEL_18:
          if ( v6 )
          {
            v8 = *(int16_t *)((char *)&word_17E07F + 13 * v26);
            v9 = dword_1975C4;
            v10 = dword_192694;
            *(_WORD *)(dword_192694 + 6 * *(int16_t *)(dword_1975C4 + 8)) = v4;
            *(_DWORD *)(6 * *(int16_t *)(v9 + 8) + v10 + 2) = *(int *)((char *)&dword_17D916 + 23 * v8);
            v11 = 2 * word_199856 + dword_1927A8;
            if ( *(int16_t *)(v11 + 53) > 0 && *(_WORD *)(v11 + 53) == v4 )
              word_19B972 = *(_WORD *)(v9 + 8);
            ++*(_WORD *)(dword_1975C4 + 8);
          }
          goto LABEL_23;
        }
LABEL_17:
        v6 = 1;
        goto LABEL_18;
      }
      v7 = byte_181752 == 0;
    }
  }
  else
  {
    v7 = byte_181750 == 0;
  }
  if ( v7 )
    goto LABEL_18;
  goto LABEL_17;
}
// 6951A: control flows out of bounds to 66268
// 692D5: conditional instruction was optimized away because bx.2<28
// 69434: variable 'v16' is possibly undefined
// 6945E: variable 'v18' is possibly undefined
// 694A5: variable 'v23' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 17D916: using guessed type int dword_17D916;
// 17E07F: using guessed type int16_t word_17E07F;
// 17F80B: using guessed type int16_t word_17F80B[];
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F811: using guessed type int16_t word_17F811[];
// 181750: using guessed type char byte_181750;
// 181751: using guessed type char byte_181751;
// 181752: using guessed type char byte_181752;
// 181753: using guessed type char byte_181753;
// 18FF78: using guessed type int16_t word_18FF78;
// 192694: using guessed type int dword_192694;
// 1927A8: using guessed type int dword_1927A8;
// 1975C4: using guessed type int dword_1975C4;
// 197F98: using guessed type int dword_197F98;
// 199856: using guessed type int16_t word_199856;
// 19999C: using guessed type int16_t word_19999C;
// 19B972: using guessed type int16_t word_19B972;


//----- (00069529) --------------------------------------------------------
int16_t sub_69529( int a1)
{
  return *(_WORD *)(6 * a1 + dword_192694);
}
// 192694: using guessed type int dword_192694;


//----- (0006953B) --------------------------------------------------------
int sub_6953B( int a1)
{
  char v1; // dl

  v1 = 0;
  if ( a1 > -1 )
    v1 = sub_6EDAE(*(_WORD *)(dword_192694 + 6 * a1));
  return sub_6F5C1(*(_WORD *)(dword_1975C4 + 8), word_19B96C, word_19B96E, v1);
}
// 192694: using guessed type int dword_192694;
// 1975C4: using guessed type int dword_1975C4;
// 19B96C: using guessed type int16_t word_19B96C;
// 19B96E: using guessed type int16_t word_19B96E;


//----- (00069583) --------------------------------------------------------
void sub_69583()
{
  int v0; // eax
  int16_t *v1; // edi
  int v2; // eax
  _WORD *v3; // eax
  int16_t v4; // ax
  int v5; // ebx
  int v6; // ecx
  int16_t v7; // dx
  int v8; // ebx
  int64_t v9; // rax
  int16_t v10; // dx
  int16_t v11; // si
  int16_t v12; // bx
  int v13; // eax
  int16_t i; // dx
  _BOOL2 v15; // bx
  int16_t v16; // ax
  int v17; // edx
  int v18; // eax
  int16_t j; // ax
  int16_t v20; // ax
  int16_t v21; // ax
  int v22; // eax
  int16_t v23; // ax
  int16_t k; // ax
  char v25[1332]; // [esp+0h] [ebp-83Eh] BYREF
  char v26[200]; // [esp+534h] [ebp-30Ah] BYREF
  char v27[200]; // [esp+5FCh] [ebp-242h] BYREF
  char v28[200]; // [esp+6C4h] [ebp-17Ah] BYREF
  char v29[30]; // [esp+78Ch] [ebp-B2h] BYREF
  char v30[30]; // [esp+7AAh] [ebp-94h] BYREF
  char v31[30]; // [esp+7C8h] [ebp-76h] BYREF
  char v32[30]; // [esp+7E6h] [ebp-58h] BYREF
  int v33; // [esp+804h] [ebp-3Ah]
  _BYTE v34[100]; // [esp+824h] [ebp-1Ah] BYREF
  int v35; // [esp+888h] [ebp+4Ah]
  char v36; // [esp+88Ch] [ebp+4Eh]
  int v37; // [esp+890h] [ebp+52h]
  int v38; // [esp+894h] [ebp+56h] BYREF
  int v39; // [esp+898h] [ebp+5Ah]
  int v40; // [esp+89Ch] [ebp+5Eh]
  char *v41; // [esp+8A0h] [ebp+62h]
  int16_t v42; // [esp+8A4h] [ebp+66h] BYREF
  int v43; // [esp+8A8h] [ebp+6Ah]
  int v44; // [esp+8ACh] [ebp+6Eh]
  int v45; // [esp+8B0h] [ebp+72h] BYREF
  int v46; // [esp+8B4h] [ebp+76h] BYREF
  int16_t v47; // [esp+8B8h] [ebp+7Ah] BYREF
  char v48; // [esp+8BCh] [ebp+7Eh]

  v35 = 252314882;
  v36 = 20;
  strcpy(v29, sub_7A990(0x46u));
  strcpy(v30, sub_7A990(0x47u));
  strcpy(v31, sub_7A990(0x48u));
  strcpy(v32, sub_7A990(0x49u));
  HIWORD(v1) = (unsigned int)v32 >> 16;
  v33 = dword_1791DC;
  sub_1112EC(dword_192EE8, 29);
  dword_1975C4 = (int)sub_110D3C(dword_192EE8, 29);
  memset(dword_1975C4, 0, 29);
  word_19B972 = -1;
  word_19B976 = 0;
  word_19995E = 0;
  byte_19B995 = 1;
  byte_19B994 = 0;
  v0 = dword_1975C4;
  LOWORD(v1) = word_199856;
  *(_WORD *)(dword_1975C4 + 12) = 0;
  *(_BYTE *)(v0 + 24) = 3;
  sub_124D41();
  v2 = sub_6C6CD();
  sub_1077D(v2, 0, 80, v1);
  sub_124DEC();
  memset(word_18B0E0, 0, sizeof(word_18B0E0));
  v38 = 0;
  sub_6921B(word_19999C);
  v48 = 1;
  if ( *(int16_t *)(dword_1975C4 + 8) > 1 )
    qsort(dword_192694, *(int16_t *)(dword_1975C4 + 8), 6);
  sub_6828D();
  v3 = (_WORD *)dword_1975C4;
  *(_WORD *)(dword_1975C4 + 10) = 10;
  v3[7] = 120;
  v4 = sub_A00F1(v3);
  v5 = dword_1975C4;
  *(_WORD *)(dword_1975C4 + 6) = v4;
  *(_WORD *)(v5 + 2) = -1;
  v6 = 479;
  v7 = *(_WORD *)(v5 + 14);
  *(_BYTE *)(v5 + 26) = 1;
  word_199972 = 0;
  *(_WORD *)v5 = v7 - v4 / 2;
  sub_128BE7();
  sub_12B65C();
  sub_133237();
  v8 = 639;
  sub_1318D4(0, 255);
  sub_124D41();
  sub_90006(0, 0, 639, 479);
  sub_124DEC();
  sub_11C2F0();
  sub_64B94((int)&v42, (int)&v47, 639);
  HIDWORD(v9) = 1;
  sub_1191CA((int)sub_65CFA, 1);
  sub_6667C();
  sub_67FFC((int16_t)v1);
  v40 = 1;
  LODWORD(v9) = sub_6953B(word_199856);
  while ( 1 )
  {
    if ( (_WORD)v38 )
    {
      dword_1975C4 = 0;
      sub_1113CC(dword_192EE8, SHIDWORD(v9));
      sub_119281();
      sub_11C2F0();
      word_199A08 = 3;
      JUMPOUT(0x68D30);
    }
    v10 = sub_1171AB(v9, SHIDWORD(v9), v8, v6);
    v11 = v10;
    v41 = sub_114177();
    if ( v10 == v47 || v10 == v42 )
    {
      v38 = 1;
    }
    else if ( v10 == -v47 )
    {
      sub_A59A1();
    }
    if ( word_19B972 > -1 )
    {
      v12 = 0;
      LOWORD(v13) = sub_6EFEB(*(_WORD *)(dword_192694 + 6 * word_19B972));
      v43 = v13;
      do
      {
        if ( (_WORD)v43 || v11 != word_1991DE[v12] )
        {
          if ( (_WORD)v43 != 1 && (_WORD)v43 != 2 || v11 != word_1991D4[v12] )
            goto LABEL_24;
          if ( !byte_19B980[v12] )
          {
            sub_8F6DF(0x4Cu, v27);
            sprintf(v34, v27, *((uint8_t *)&v35 + v12));
            goto LABEL_23;
          }
          word_19B976 = 16;
          word_19B978 = v12;
        }
        else
        {
          if ( !byte_19B980[v12] )
          {
            sub_8F6DF(0x4Bu, v26);
            sprintf(v34, v26, &v29[30 * v12]);
LABEL_23:
            sub_77423((int)v34);
            goto LABEL_24;
          }
          word_19B976 = 1 << v12;
        }
LABEL_24:
        ++v12;
      }
      while ( v12 < 5 );
    }
    if ( v11 == word_199842 )
    {
      byte_181750 = byte_181750 == 0;
    }
    else if ( v11 == word_199846 )
    {
      byte_181751 = byte_181751 == 0;
    }
    else if ( v11 == word_199844 )
    {
      byte_181752 = byte_181752 == 0;
    }
    else if ( v11 == word_199840 )
    {
      byte_181753 = byte_181753 == 0;
    }
    for ( i = 1; i < 15; ++i )
    {
      v37 = word_1991E8[i];
      v37 = -v37;
      if ( v11 == v37 )
      {
        sub_67BC7(i);
      }
      else if ( v11 == word_1991E8[i] && byte_19B985[i] == 1 )
      {
        v15 = word_1991B6[i] == 0;
        word_1991B6[i] = v15;
        if ( i == 1 && v15 )
        {
          word_1991BA = 0;
        }
        else if ( i == 2 && word_1991BA )
        {
          word_1991B8 = 0;
        }
      }
    }
    v6 = (int)&v45;
    v8 = (int)&v46;
    v16 = sub_67E9C((int16_t)v41, v11, &v46, &v45);
    word_19B97C = v46;
    if ( v16 )
    {
      if ( v16 == 1 )
      {
        v20 = *(_WORD *)(dword_192694 + 6 * (int16_t)v45);
        if ( v20 <= 0 )
        {
          sub_A59A1();
        }
        else
        {
          v8 = 28 * v20;
          sub_6FBEA(v25, *(int16_t *)((char *)word_17F80D + v8));
          sub_A5EB2(*(int *)((char *)&off_17F803 + v8), (int)v25);
        }
      }
    }
    else
    {
      if ( !(_WORD)v45 )
      {
        v38 = 1;
        word_19B976 = 0;
        word_19B966 = 0;
        word_19B972 = 0;
      }
      if ( (int16_t)v45 <= -1 || word_19B972 == (_WORD)v45 )
      {
        v8 = (int16_t)v1;
        sub_68E78((int)&v38, word_19B972, (int16_t)v1);
      }
      else
      {
        word_19B972 = v45;
        HIWORD(v17) = HIWORD(dword_192694);
        LOWORD(v17) = *(_WORD *)(dword_192694 + 6 * (int16_t)v45);
        v6 = v17;
        if ( (int16_t)v17 == -1 )
        {
          v38 = 1;
        }
        else
        {
          v8 = 2 * (int16_t)v1;
          if ( *(int16_t *)(v8 + dword_1927A8 + 53) > 0 && (_WORD)v17 == *(_WORD *)(v8 + dword_1927A8 + 53) )
          {
            sub_67FFC(word_199856);
          }
          else
          {
            v8 = 30;
            LOWORD(v18) = sub_6EFEB(v17);
            v6 = v18;
            word_19B966 = 0;
            memset(word_1991B6, 0, 30);
            if ( (_WORD)v6 )
              word_19B976 = 16;
            else
              word_19B976 = 1;
            word_19B978 = 1;
            word_19B966 = 0;
            for ( j = 1; j < 15; ++j )
            {
              if ( word_1991B6[j] == 1 )
              {
                LOBYTE(v6) = j;
                word_19B966 |= 1 << j;
              }
            }
            sub_6953B(word_19B972);
          }
        }
      }
    }
    HIDWORD(v9) = 0;
    do
    {
      LODWORD(v9) = SWORD2(v9);
      if ( v11 == word_1991E8[SWORD2(v9)] && (uint8_t)byte_19B985[SWORD2(v9)] > 0xF8u )
        sub_67CCF(v9);
      ++HIDWORD(v9);
    }
    while ( SWORD2(v9) < 15 );
    if ( v11 == word_19B97E )
    {
      if ( word_19B972 == -1 )
      {
        LODWORD(v9) = sub_7A990(0x4Eu);
LABEL_80:
        LOWORD(v9) = sub_77423(v9);
        goto LABEL_81;
      }
      HIDWORD(v9) = dword_192694;
      LOWORD(v9) = sub_6EFEB(*(_WORD *)(dword_192694 + 6 * word_19B972));
      if ( (_WORD)v9 == 3 || (_WORD)v9 == 4 || (_WORD)v9 == 5 )
      {
        sub_8F6DF(0x4Fu, v28);
        v21 = sub_69529(word_19B972);
        v9 = sprintf(v34, v28, *(&off_17F803 + 7 * v21));
        LODWORD(v9) = v34;
        goto LABEL_80;
      }
    }
LABEL_81:
    if ( v11 == word_199842 || v11 == word_199846 || v11 == word_199844 || v11 == word_199840 )
    {
      HIWORD(v22) = HIWORD(dword_1975C4);
      LOWORD(v22) = *(_WORD *)(dword_1975C4 + 8);
      v39 = v22;
      if ( word_19B972 <= -1 )
      {
        v44 = -1;
      }
      else
      {
        HIDWORD(v9) = 6 * word_19B972;
        WORD1(v9) = HIWORD(dword_192694);
        LOWORD(v9) = *(_WORD *)(HIDWORD(v9) + dword_192694);
        v44 = v9;
      }
      sub_6921B(word_19999C);
      if ( *(int16_t *)(dword_1975C4 + 8) > 0 )
      {
        v6 = (int)sub_69E59;
        v8 = 6;
        HIDWORD(v9) = *(int16_t *)(dword_1975C4 + 8);
        qsort(dword_192694, HIDWORD(v9), 6);
        if ( *(int16_t *)(dword_1975C4 + 8) >= 10 )
        {
          HIDWORD(v9) = *(int16_t *)(dword_1975C4 + 12) + 10;
          LODWORD(v9) = *(int16_t *)(dword_1975C4 + 8);
          if ( (int)v9 < SHIDWORD(v9) )
          {
            LODWORD(v9) = v9 - 10;
            if ( (int)v9 <= 0 )
              LODWORD(v9) = 0;
            HIDWORD(v9) = v9;
            *(_WORD *)(dword_1975C4 + 12) = v9;
          }
        }
        else
        {
          *(_WORD *)(dword_1975C4 + 12) = 0;
        }
      }
      sub_68DE3(v44);
      word_19B972 = v23;
      if ( *(_WORD *)(dword_1975C4 + 8) != (_WORD)v39 )
      {
        sub_6667C();
        v48 = 1;
      }
      sub_6953B(word_19B972);
      sub_6828D();
    }
    if ( v11 == word_19B968 )
    {
      byte_19B994 = 0;
      LOWORD(v9) = sub_A01C6((int16_t *)dword_1975C4);
    }
    if ( v11 == word_19B970 )
    {
      byte_19B994 = 0;
      LOWORD(v9) = sub_A015D((int16_t *)dword_1975C4);
    }
    if ( v11 == word_199848 )
    {
      HIDWORD(v9) = word_19B972;
      v8 = (int16_t)v1;
      LOWORD(v9) = sub_68E78((int)&v38, word_19B972, (int16_t)v1);
    }
    if ( !(_WORD)v38 )
    {
      word_19B966 = 0;
      for ( k = 1; k < 15; ++k )
      {
        v8 = k;
        if ( word_1991B6[k] == 1 )
        {
          LOBYTE(v6) = k;
          word_19B966 |= 1 << k;
        }
      }
      sub_11C2F0();
      HIDWORD(v9) = &v47;
      sub_64B94((int)&v42, (int)&v47, v8);
    }
    if ( !(_WORD)v38 && !(_WORD)v40 && v48 )
    {
      LODWORD(v9) = sub_67E50();
      v48 = 0;
    }
    if ( !(_WORD)v38 )
    {
      sub_124D41();
      sub_65CFA();
      if ( (_WORD)v40 )
        v40 = 0;
      else
        LODWORD(v9) = sub_1077D(v9, SHIDWORD(v9), v8, v1);
    }
  }
}
// 69E2A: control flows out of bounds to 68D30
// 697A0: variable 'v9' is possibly undefined
// 69809: variable 'v13' is possibly undefined
// 69A91: variable 'v18' is possibly undefined
// 69CEC: variable 'v23' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 1791DC: using guessed type int dword_1791DC;
// 17F803: using guessed type _UNKNOWN *off_17F803;
// 17F80D: using guessed type int16_t word_17F80D[];
// 181750: using guessed type char byte_181750;
// 181751: using guessed type char byte_181751;
// 181752: using guessed type char byte_181752;
// 181753: using guessed type char byte_181753;
// 18B0E0: using guessed type int16_t word_18B0E0[40];
// 192694: using guessed type int dword_192694;
// 1927A8: using guessed type int dword_1927A8;
// 192EE8: using guessed type int dword_192EE8;
// 1975C4: using guessed type int dword_1975C4;
// 1991B6: using guessed type int16_t word_1991B6[];
// 1991B8: using guessed type int16_t word_1991B8;
// 1991BA: using guessed type int16_t word_1991BA;
// 1991D4: using guessed type int16_t word_1991D4[5];
// 1991DE: using guessed type int16_t word_1991DE[5];
// 1991E8: using guessed type int16_t word_1991E8[15];
// 199840: using guessed type int16_t word_199840;
// 199842: using guessed type int16_t word_199842;
// 199844: using guessed type int16_t word_199844;
// 199846: using guessed type int16_t word_199846;
// 199848: using guessed type int16_t word_199848;
// 199856: using guessed type int16_t word_199856;
// 19995E: using guessed type int16_t word_19995E;
// 199972: using guessed type int16_t word_199972;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 19B966: using guessed type int16_t word_19B966;
// 19B968: using guessed type int16_t word_19B968;
// 19B970: using guessed type int16_t word_19B970;
// 19B972: using guessed type int16_t word_19B972;
// 19B976: using guessed type int16_t word_19B976;
// 19B978: using guessed type int16_t word_19B978;
// 19B97C: using guessed type int16_t word_19B97C;
// 19B97E: using guessed type int16_t word_19B97E;
// 19B994: using guessed type char byte_19B994;
// 19B995: using guessed type char byte_19B995;


//----- (00069E2F) --------------------------------------------------------
int sub_69E2F( int a1, int a2, int a3, int a4, int a5, int a6)
{
  return sub_1297C3(a1, a2, a3 - a1 + 1, a4 - a2 + 1, a5, a6);
}


//----- (00069E59) --------------------------------------------------------
int sub_69E59(int a1, int a2)
{
  return *(_DWORD *)(a2 + 2) - *(_DWORD *)(a1 + 2);
}


//----- (00069E62) --------------------------------------------------------
unsigned int sub_69E62()
{
  int16_t i; // si
  int v1; // edx
  int v2; // esi
  int v3; // ecx
  int16_t v4; // ax
  int16_t v5; // si
  int v6; // eax
  int16_t v7; // di
  int16_t v8; // di
  int v9; // eax
  int v10; // eax
  int16_t v11; // bx
  int16_t v12; // dx
  int16_t v13; // ax
  int v14; // eax
  int16_t v15; // di
  int16_t v16; // cx
  int16_t v17; // dx
  int16_t v18; // cx
  int16_t v19; // ax
  int v21; // [esp-18h] [ebp-58h]
  char v22[8]; // [esp+0h] [ebp-40h] BYREF
  int v23; // [esp+8h] [ebp-38h]
  int16_t v24; // [esp+Ch] [ebp-34h] BYREF
  int16_t v25; // [esp+10h] [ebp-30h] BYREF
  int16_t v26; // [esp+14h] [ebp-2Ch] BYREF
  int v27; // [esp+18h] [ebp-28h]
  int v28; // [esp+1Ch] [ebp-24h]
  int v29; // [esp+20h] [ebp-20h]
  int v30; // [esp+24h] [ebp-1Ch]
  int v31; // [esp+28h] [ebp-18h]
  int v32; // [esp+2Ch] [ebp-14h]
  int v33; // [esp+30h] [ebp-10h]
  int v34; // [esp+34h] [ebp-Ch]
  int v35; // [esp+38h] [ebp-8h]
  int16_t v36; // [esp+3Ch] [ebp-4h] BYREF

  for ( i = 0; i < 6; ++i )
  {
    v1 = i;
    byte_19B9AC[v1] = sub_6A3E5();
  }
  v35 = 0;
  do
  {
    v2 = (int16_t)v35;
    sub_6C8F9(v35, &v24, &v26, &v25, &v36);
    if ( byte_19B9AC[v2] == 1 )
    {
      v3 = dword_18B248[v2];
      v4 = sub_115383(v24, v26, (int)&byte_1791EB, (_WORD *)v3, (int)&word_199854, v2, &byte_1791EB, 41);
    }
    else
    {
      v3 = v36;
      v4 = sub_11438B(v24, v26, v25, v36, &byte_1791EB, 41);
    }
    word_192750[v2] = v4;
    ++v35;
  }
  while ( (int16_t)v35 < 6 );
  v34 = 13;
  v33 = 182;
  sub_6E1DC(3);
  v5 = 0;
  v28 = v6;
  do
  {
    v7 = (uint8_t)byte_199EF5;
    word_18B1F0[v5] = -1000;
    v8 = v5 + v7;
    if ( v5 > 0 && *(int16_t *)(dword_1927A8 + 2 * v8 + 53) > 0 || (_WORD)v28 )
    {
      v9 = dword_1927A8 + 2 * v8;
      if ( *(int16_t *)(v9 + 53) <= 0 || *(int16_t *)(v9 + 69) <= 1 )
      {
        word_18B200[v5] = -1000;
        if ( *(int16_t *)(2 * v8 + dword_1927A8 + 53) > 0 )
        {
          v3 = (int16_t)(13 * v5 + 181);
          sub_11438B(55, 13 * v5 + 169, 68, v3, &byte_1791EB, 0);
        }
      }
      else
      {
        HIWORD(v3) = HIWORD(dword_1927EC);
        word_18B200[v5] = (uint16_t)sub_1151B0(
                                              55,
                                              13 * v5 + 169,
                                              (int)&byte_1791EB,
                                              (_WORD *)dword_1927EC,
                                              &byte_1791EB,
                                              40);
      }
      v10 = v8;
      LOWORD(v10) = *(_WORD *)(dword_1927A8 + 4 * v8 + 141);
      v29 = v10;
      v23 = 2 * v8;
      LOWORD(v3) = *(_WORD *)(dword_1927A8 + v23 + 53);
      v27 = v3;
      v11 = sub_6EE8E(
              word_19999C,
              v3,
              *(_WORD *)(dword_1927A8 + v23 + 69) + 1,
              *(uint8_t *)(dword_1927A8 + v8 + 85),
              *(uint8_t *)(dword_1927A8 + v8 + 173),
              *(_WORD *)(dword_1927A8 + v23 + 93));
      if ( *(int16_t *)(v23 + dword_1927A8 + 53) <= 0
        || *(_DWORD *)(dword_1927A8 + 233) - (*(_DWORD *)(dword_1927A8 + 237) + v11 - (int16_t)v29) < 0 )
      {
        word_18B1E0[v5] = -1000;
        if ( *(int16_t *)(dword_1927A8 + 2 * v8 + 53) > 0 )
          sub_11438B(19, 13 * v5 + 169, 32, 13 * v5 + 181, &byte_1791EB, 41);
      }
      else
      {
        word_18B1E0[v5] = (uint16_t)sub_1151B0(
                                              19,
                                              13 * v5 + 169,
                                              (int)&byte_1791EB,
                                              (_WORD *)dword_1927F8,
                                              &byte_1791EB,
                                              40);
      }
      v12 = 13 * v5 + 169;
      v3 = (int16_t)v33;
      if ( *(int16_t *)(2 * v8 + dword_1927A8 + 53) <= 0 )
        v13 = sub_11438B(16, v12, 623, v33, &byte_1791EB, 41);
      else
        v13 = sub_11438B(77, v12, 556, v33, &byte_1791EB, 41);
      word_18B210[v5] = v13;
    }
    else
    {
      word_18B200[v5] = -1000;
      word_18B1E0[v5] = -1000;
      word_18B210[v5] = -1000;
    }
    ++v5;
    v33 += 13;
  }
  while ( v5 < 8 );
  sub_6E1DC(9);
  v31 = v14;
  v15 = 0;
  v30 = v34;
  v32 = v34 + 319;
  do
  {
    if ( (_WORD)v31 )
    {
      v16 = v32;
      v17 = v15 * v34 + 319;
      word_18B1D0[v15] = -1000;
      word_18B220[v15] = sub_11438B(17, v17, 623, v16, &byte_1791EB, 41);
    }
    else
    {
      word_18B1D0[v15] = -1000;
      word_18B220[v15] = -1000;
    }
    ++v15;
    v32 += v30;
  }
  while ( v15 < 8 );
  word_199866 = (uint16_t)sub_1151B0(17, 82, (int)&byte_1791EB, (_WORD *)dword_192810, &byte_1791EB, 40);
  word_199852 = (uint16_t)sub_1151B0(94, 82, (int)&byte_1791EB, (_WORD *)dword_1927D0, &byte_1791EB, 40);
  sub_8F6F8(4u, 85, 89, v22);
  sub_120BB5(4, (int)v22);
  v21 = dword_1927A8;
  v18 = sub_122259() + 2;
  v19 = sub_122259();
  word_19985C = (uint16_t)sub_115BEA(18, (27 - v19) / 2 + 17, 134, v18, v21, 15, 0, 0, 41, 0);
  word_19B9B4 = sub_11438B(437, 56, 627, 95, &byte_1791EB, 41);
  word_19B9B2 = sub_11438B(437, 97, 627, 123, &byte_1791EB, 41);
  word_199864 = (uint16_t)sub_1151B0(461, 443, (int)&byte_1791EB, (_WORD *)dword_1927F0, aLb, 40);
  word_19984C = (uint16_t)sub_1151B0(374, 443, (int)&byte_1791EB, (_WORD *)dword_1927E8, &aLb[1], 40);
  if ( *(_DWORD *)(dword_1927A8 + 233) < *(_DWORD *)(dword_1927A8 + 237) )
    word_19984E = -1000;
  else
    word_19984E = (uint16_t)sub_1151B0(547, 443, (int)&byte_1791EB, (_WORD *)dword_1927E4, &aLb[2], 40);
  word_19C18C = sub_11438B(0, 470, 10, 479, &byte_1791EB, 41);
  return sub_11438B(0, 0, 639, 479, &byte_1791EB, 0);
}
// 69F1E: variable 'v6' is possibly undefined
// 6A184: variable 'v14' is possibly undefined
// 1791EB: using guessed type char byte_1791EB;
// 1791EC: using guessed type wchar_t aLb[3];
// 18B1D0: using guessed type int16_t word_18B1D0[];
// 18B1E0: using guessed type int16_t word_18B1E0[];
// 18B1F0: using guessed type int16_t word_18B1F0[];
// 18B200: using guessed type int16_t word_18B200[];
// 18B210: using guessed type int16_t word_18B210[];
// 18B220: using guessed type int16_t word_18B220[];
// 18B248: using guessed type int dword_18B248[];
// 192750: using guessed type int16_t word_192750[6];
// 1927A8: using guessed type int dword_1927A8;
// 1927D0: using guessed type int dword_1927D0;
// 1927E4: using guessed type int dword_1927E4;
// 1927E8: using guessed type int dword_1927E8;
// 1927EC: using guessed type int dword_1927EC;
// 1927F0: using guessed type int dword_1927F0;
// 1927F8: using guessed type int dword_1927F8;
// 192810: using guessed type int dword_192810;
// 19984C: using guessed type int16_t word_19984C;
// 19984E: using guessed type int16_t word_19984E;
// 199852: using guessed type int16_t word_199852;
// 199854: using guessed type int16_t word_199854;
// 19985C: using guessed type int16_t word_19985C;
// 199864: using guessed type int16_t word_199864;
// 199866: using guessed type int16_t word_199866;
// 19999C: using guessed type int16_t word_19999C;
// 199EF5: using guessed type char byte_199EF5;
// 19B9B2: using guessed type int16_t word_19B9B2;
// 19B9B4: using guessed type int16_t word_19B9B4;
// 19C18C: using guessed type int16_t word_19C18C;


//----- (0006A3E5) --------------------------------------------------------
char sub_6A3E5()
{
  char result; // al

  result = 1;
  if ( byte_199EF1 )
    return -12;
  return result;
}
// 199EF1: using guessed type char byte_199EF1;


//----- (0006A406) --------------------------------------------------------
int16_t sub_6A406( int result, _WORD *a2, _WORD *a3)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int16_t v15; // [esp+0h] [ebp-4h]

  v15 = result;
  *a2 = 0;
  *a3 = 0;
  if ( (result & 0x4000) != 0 )
  {
    v3 = 15 * (int16_t)sub_8E94D(0x4000, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v3);
    result = *(int16_t *)((char *)&word_17FD17 + v3);
    *a3 += result;
  }
  if ( (v15 & 8) != 0 )
  {
    v4 = 15 * (int16_t)sub_8E94D(8, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v4);
    result = *(int16_t *)((char *)&word_17FD17 + v4);
    *a3 += result;
  }
  if ( (v15 & 0x10) != 0 )
  {
    v5 = 15 * (int16_t)sub_8E94D(16, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v5);
    result = *(int16_t *)((char *)&word_17FD17 + v5);
    *a3 += result;
  }
  if ( (v15 & 0x20) != 0 )
  {
    v6 = 15 * (int16_t)sub_8E94D(32, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v6);
    result = *(int16_t *)((char *)&word_17FD17 + v6);
    *a3 += result;
  }
  if ( (v15 & 0x40) != 0 )
  {
    v7 = 15 * (int16_t)sub_8E94D(64, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v7);
    result = *(int16_t *)((char *)&word_17FD17 + v7);
    *a3 += result;
  }
  if ( (v15 & 0x80u) != 0 )
  {
    v8 = 15 * (int16_t)sub_8E94D(128, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v8);
    result = *(int16_t *)((char *)&word_17FD17 + v8);
    *a3 += result;
  }
  if ( (v15 & 0x100) != 0 )
  {
    v9 = 15 * (int16_t)sub_8E94D(256, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v9);
    result = *(int16_t *)((char *)&word_17FD17 + v9);
    *a3 += result;
  }
  if ( (v15 & 0x200) != 0 )
  {
    v10 = 15 * (int16_t)sub_8E94D(512, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v10);
    result = *(int16_t *)((char *)&word_17FD17 + v10);
    *a3 += result;
  }
  if ( (v15 & 0x400) != 0 )
  {
    v11 = 15 * (int16_t)sub_8E94D(1024, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v11);
    result = *(int16_t *)((char *)&word_17FD17 + v11);
    *a3 += result;
  }
  if ( (v15 & 0x800) != 0 )
  {
    v12 = 15 * (int16_t)sub_8E94D(2048, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v12);
    result = *(int16_t *)((char *)&word_17FD17 + v12);
    *a3 += result;
  }
  if ( (v15 & 0x1000) != 0 )
  {
    v13 = 15 * (int16_t)sub_8E94D(4096, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v13);
    result = *(int16_t *)((char *)&word_17FD17 + v13);
    *a3 += result;
  }
  if ( (v15 & 0x2000) != 0 )
  {
    v14 = 15 * (int16_t)sub_8E94D(0x2000, 15);
    *a2 += *(int16_t *)((char *)&word_17FD15 + v14);
    result = *(int16_t *)((char *)&word_17FD17 + v14);
    *a3 += result;
  }
  return result;
}
// 17FD15: using guessed type int16_t word_17FD15;
// 17FD17: using guessed type int16_t word_17FD17;


//----- (0006A636) --------------------------------------------------------
int16_t sub_6A636( int result, _WORD *a2, _WORD *a3)
{
  int v3; // eax
  int v4; // eax

  *a2 = 100;
  *a3 = 100;
  if ( (result & 2) != 0 )
  {
    v3 = 2;
  }
  else
  {
    if ( (result & 4) == 0 )
      return result;
    v3 = 4;
  }
  v4 = 15 * (int16_t)sub_8E94D(v3, 15);
  *a2 += *(int16_t *)((char *)&word_17FD15 + v4);
  result = *(int16_t *)((char *)&word_17FD17 + v4);
  *a3 += result;
  return result;
}
// 17FD15: using guessed type int16_t word_17FD15;
// 17FD17: using guessed type int16_t word_17FD17;


//----- (0006A6A1) --------------------------------------------------------
void sub_6A6A1(int a1)
{
  _BYTE *v2; // eax
  char v3; // dl
  int v4; // eax
  int v5; // ecx
  int16_t v6; // cx
  unsigned int v7; // edx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  char v11; // [esp+0h] [ebp-8h]
  int v12; // [esp+4h] [ebp-4h]

  strcpy((char *)a1, (char *)dword_1927A8);
  v2 = (_BYTE *)dword_1927A8;
  v3 = *(_BYTE *)(dword_1927A8 + 229);
  *(_BYTE *)(a1 + 18) = 0;
  *(_BYTE *)(a1 + 16) = v3;
  *(_BYTE *)(a1 + 19) = v2[27];
  *(_BYTE *)(a1 + 21) = v2[43];
  *(_BYTE *)(a1 + 22) = v2[49];
  v4 = 0;
  do
  {
    v5 = (int16_t)v4++;
    *(_BYTE *)(v5 + a1 + 23) = 0;
  }
  while ( (int16_t)v4 < 5 );
  v6 = 0;
  while ( 1 )
  {
    HIWORD(v7) = HIWORD(dword_1927A8);
    v8 = dword_1927A8 + 2 * v6;
    if ( *(int16_t *)(v8 + 181) > 0 )
    {
      v7 = *(int16_t *)(v8 + 181);
      sub_127712(a1 + 23, v7);
    }
    if ( ++v6 >= 8 )
    {
      v12 = 0;
      do
      {
        v9 = dword_1927A8;
        v10 = (int16_t)v12;
        *(_WORD *)(a1 + 8 * (int16_t)v12 + 28) = *(_WORD *)(dword_1927A8 + 2 * (int16_t)v12 + 53);
        *(_BYTE *)(a1 + 8 * (int16_t)v12 + 30) = *(_BYTE *)(v9 + 2 * (int16_t)v12 + 69);
        *(_BYTE *)(a1 + 8 * (int16_t)v12 + 32) = *(_BYTE *)(v9 + (int16_t)v12 + 85);
        LOWORD(v7) = *(_WORD *)(v9 + 2 * (int16_t)v12 + 93);
        *(_WORD *)(a1 + 8 * (int16_t)v12 + 33) = v7;
        LOBYTE(v7) = *(_BYTE *)(v9 + (int16_t)v12++ + 173);
        *(_BYTE *)(a1 + 8 * v10 + 35) = v7;
      }
      while ( (int16_t)v12 < 8 );
      *(_BYTE *)(a1 + 92) = *(_BYTE *)(v9 + 231);
      *(_WORD *)(a1 + 94) = *(_WORD *)(v9 + 241);
      *(_WORD *)(a1 + 97) = dword_192FD8;
      v11 = sub_6B86A(v9, v7, a1, v9);
      if ( (uint8_t)sub_6B7FF(v9, 2) && byte_19B9B8 )
        v11 += 5;
      *(_BYTE *)(a1 + 96) = v11;
      JUMPOUT(0x6A3DE);
    }
  }
}
// 6A7C3: control flows out of bounds to 6A3DE
// 1927A8: using guessed type int dword_1927A8;
// 192FD8: using guessed type int dword_192FD8;
// 19B9B8: using guessed type char byte_19B9B8;


//----- (0006A7C8) --------------------------------------------------------
int sub_6A7C8( int a1, int a2)
{
  int16_t v4; // dx
  int v5; // eax
  uint8_t v6; // al
  int v7; // eax
  int16_t v8; // ax
  int16_t v9; // ax
  int v10; // ebx
  int v11; // ecx
  int v12; // eax
  char v13; // al
  int v14; // edx
  int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // ecx
  int v19; // eax
  int v20; // ebx
  int16_t v21; // si
  int16_t i; // cx
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  uint8_t v26; // bl
  int v27; // eax
  int v31; // [esp+8h] [ebp-10h]
  int16_t v32; // [esp+14h] [ebp-4h]

  memset(dword_1927A8, 0, 293);
  strcpy((char *)dword_1927A8, (char *)sub_77AE6(a1, a2));
  v4 = sub_56726(a1);
  v5 = dword_1927A8;
  *(_WORD *)(dword_1927A8 + 27) = v4;
  *(_WORD *)(v5 + 29) = word_17FE9C[23 * v4];
  v6 = sub_77D13(a1, a2);
  *(_WORD *)(dword_1927A8 + 229) = v6;
  v7 = word_180020[18 * v6];
  if ( *(_BYTE *)(3753 * word_19999C + dword_197F98 + 368) == 3 )
    v7 = 125 * v7 / 100;
  *(_DWORD *)(dword_1927A8 + 233) = v7;
  *(_WORD *)(dword_1927A8 + 43) = sub_5680D(a1);
  *(_WORD *)(dword_1927A8 + 231) = (uint8_t)sub_77CD5(a1, a2);
  sub_5685F(a1);
  *(_WORD *)(dword_1927A8 + 49) = v8;
  sub_5709F(a1);
  *(_WORD *)(dword_1927A8 + 47) = v9;
  v10 = 0;
  *(_WORD *)(dword_1927A8 + 17) = sub_5679E(word_19999C);
  do
  {
    v11 = dword_1927A8;
    v12 = (int16_t)v10;
    *(_DWORD *)(dword_1927A8 + 4 * (int16_t)v10++ + 141) = 0;
    *(_DWORD *)(v11 + 4 * v12 + 109) = 0;
  }
  while ( (int16_t)v10 < 8 );
  v32 = 0;
  *(_WORD *)(v11 + 246) = 0;
  do
  {
    v31 = 2 * v32;
    *(_WORD *)(v31 + dword_1927A8 + 53) = sub_77D69(a1, a2, v32);
    *(_WORD *)(v31 + dword_1927A8 + 69) = (uint8_t)sub_77DB2(a1, a2, v32);
    *(_WORD *)(v31 + dword_1927A8 + 93) = sub_77DFA(a1, a2, v32);
    *(_BYTE *)(v32 + dword_1927A8 + 85) = sub_77DD6(a1, a2, v32);
    v13 = sub_77D8E(a1, a2, v32);
    v14 = dword_1927A8;
    *(_BYTE *)(v32 + dword_1927A8 + 173) = v13;
    v15 = *(int16_t *)(v14 + v31 + 53);
    if ( byte_17F80F[28 * v15] == 2 || sub_6EDAE(v15) && (*(_BYTE *)(v32 + dword_1927A8 + 85) & 0xF) == 0 )
    {
      v16 = v32 + dword_1927A8;
      if ( *(_BYTE *)(v16 + 85) != 16 )
        *(_BYTE *)(v16 + 85) = 16;
    }
    if ( *(int16_t *)(dword_1927A8 + 2 * v32 + 53) > 0 )
      ++*(_WORD *)(dword_1927A8 + 246);
    ++v32;
  }
  while ( v32 < 8 );
  v17 = 0;
  do
  {
    v18 = dword_1927A8;
    v19 = (int16_t)v17;
    *(_WORD *)(dword_1927A8 + 2 * (int16_t)v17 + 181) = 0;
    *(_WORD *)(v18 + 2 * (int16_t)v17++ + 197) = 0;
    *(_WORD *)(v18 + 2 * v19 + 213) = 0;
  }
  while ( (int16_t)v17 < 8 );
  v20 = 0;
  v21 = 0;
  *(_WORD *)(v18 + 248) = 0;
  for ( i = 0; i < 39 && !(_WORD)v20; ++i )
  {
    if ( (uint16_t)sub_1276F0(dword_197F98 + 3753 * a1 + 806 + 99 * a2 + 23, i) )
    {
      v23 = v21++;
      *(_WORD *)(dword_1927A8 + 2 * v23 + 181) = i;
      if ( v21 >= 8 )
        v20 = 1;
    }
  }
  v24 = dword_1927A8;
  v25 = dword_1927A8;
  *(_WORD *)(dword_1927A8 + 248) = v21;
  v26 = sub_6B86A(v25, 2, v20, v24);
  if ( (uint8_t)sub_6B7FF(v24, 2) && byte_19B9B8 )
    v26 += 5;
  v27 = dword_1927A8;
  *(_WORD *)(dword_1927A8 + 291) = 140;
  *(_WORD *)(v27 + 37) = v26;
  return sub_6E8DA(a1);
}
// 6A8C9: variable 'v8' is possibly undefined
// 6A8DB: variable 'v9' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 17FE9C: using guessed type int16_t word_17FE9C[];
// 180020: using guessed type int16_t word_180020[];
// 1927A8: using guessed type int dword_1927A8;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19B9B8: using guessed type char byte_19B9B8;


//----- (0006AB1B) --------------------------------------------------------
int sub_6AB1B()
{
  int16_t v0; // dx
  int result; // eax

  v0 = 0;
  *(_WORD *)(dword_1927A8 + 246) = 0;
  do
  {
    result = dword_1927A8;
    if ( *(int16_t *)(dword_1927A8 + 2 * v0 + 53) > 0 )
      ++*(_WORD *)(dword_1927A8 + 246);
    ++v0;
  }
  while ( v0 < 8 );
  return result;
}
// 1927A8: using guessed type int dword_1927A8;


//----- (0006AB4E) --------------------------------------------------------
int sub_6AB4E()
{
  int result; // eax
  _BOOL1 v1; // cl
  int16_t v2; // dx

  result = dword_1927A8;
  v1 = 0;
  v2 = 0;
  *(_WORD *)(dword_1927A8 + 248) = 0;
  while ( v2 < 8 && !v1 )
  {
    result = dword_1927A8;
    if ( *(int16_t *)(dword_1927A8 + 2 * v2 + 181) > 0 )
    {
      ++*(_WORD *)(dword_1927A8 + 248);
      v1 = *(_WORD *)(result + 248) >= 8;
    }
    ++v2;
  }
  return result;
}
// 1927A8: using guessed type int dword_1927A8;


//----- (0006AB9A) --------------------------------------------------------
void sub_6AB9A()
{
  char v0; // dl
  int16_t v1; // si
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int16_t v7; // [esp+4h] [ebp-Ch]
  int16_t v8; // [esp+8h] [ebp-8h]
  char v9; // [esp+Ch] [ebp-4h]

  if ( sub_124075() == 1 )
  {
    v9 = 0;
    ++word_181760;
    v0 = 0;
    v1 = 0;
    v8 = sub_113F8C();
    while ( v1 < 8 && !v0 )
    {
      v2 = v1;
      if ( word_18B1E0[v2] == -1000
        || v8 != word_18B1E0[v1]
        || (v3 = dword_1927A8 + v2 * 2, *(int16_t *)(v3 + 53) <= 0)
        || word_181760 <= 4 )
      {
        v5 = v1;
        if ( word_18B200[v5] != -1000
          && v8 == word_18B200[v1]
          && *(int16_t *)(dword_1927A8 + v5 * 2 + 53) > 0
          && word_181760 > 5 )
        {
          v6 = dword_1927A8 + 2 * (int16_t)(v1 + (uint8_t)byte_199EF5);
          --*(_WORD *)(v6 + 69);
          v0 = 1;
          if ( *(int16_t *)(v6 + 69) < 1 )
            *(_WORD *)(v6 + 69) = 1;
          v9 = 1;
        }
      }
      else
      {
        v7 = v1 + (uint8_t)byte_199EF5;
        v0 = 1;
        if ( *(_DWORD *)(dword_1927A8 + 237)
           + (int16_t)sub_6EE8E(
                        word_19999C,
                        *(_WORD *)(v3 + 53),
                        1,
                        *(uint8_t *)(dword_1927A8 + v1 + 85),
                        *(uint8_t *)(dword_1927A8 + v1 + 173),
                        *(_WORD *)(v3 + 93)) <= *(_DWORD *)(dword_1927A8 + 233) )
        {
          v4 = 2 * v7 + dword_1927A8;
          if ( (int16_t)++*(_WORD *)(v4 + 69) > 99 )
            *(_WORD *)(v4 + 69) = 99;
          v9 = 1;
          v0 = 1;
        }
      }
      ++v1;
    }
    ++byte_19B9B9;
    if ( v9 )
      sub_6E8DA(word_19999C);
  }
  else
  {
    word_181760 = 0;
  }
  JUMPOUT(0x6A3DE);
}
// 6ABB9: control flows out of bounds to 6A3DE
// 6ABF9: conditional instruction was optimized away because di.2==1
// 6ACBF: conditional instruction was optimized away because di.2==1
// 6AD1B: conditional instruction was optimized away because di.2==1
// 181760: using guessed type int16_t word_181760;
// 18B1E0: using guessed type int16_t word_18B1E0[];
// 18B200: using guessed type int16_t word_18B200[];
// 1927A8: using guessed type int dword_1927A8;
// 19999C: using guessed type int16_t word_19999C;
// 199EF5: using guessed type char byte_199EF5;
// 19B9B9: using guessed type char byte_19B9B9;


//----- (0006AD3E) --------------------------------------------------------
_BOOL1 sub_6AD3E()
{
  _BOOL1 result; // al
  int16_t i; // dx

  result = 0;
  for ( i = 0; i < 8 && !result; ++i )
    result = *(_WORD *)(dword_1927A8 + 2 * i + 181) == 7;
  if ( result )
    *(_WORD *)(dword_1927A8 + 17) = 0;
  return result;
}
// 1927A8: using guessed type int dword_1927A8;


//----- (0006AD7C) --------------------------------------------------------
int sub_6AD7C(int result, _WORD *a2, _WORD *a3, int16_t *a4)
{
  int16_t v4; // cx
  int v5; // eax
  char *v6; // eax
  uint16_t v7; // ax
  int16_t v8; // cx
  int v9; // eax
  char *v10; // eax

  v4 = result;
  if ( (_WORD)result == word_19B9B2 )
  {
    if ( (uint8_t)sub_5680D(word_19999C) )
    {
      word_199860 = 8;
      v5 = *(int16_t *)(dword_1927A8 + 45);
      word_19985E = *(_WORD *)(dword_1927A8 + 43);
      dword_19B998 -= v5;
      sub_6603E(a4);
      result = dword_1927A8;
      *(_BYTE *)(dword_1927A8 + 245) = 1;
      *a2 = 1;
      word_199A08 = 3;
      *a3 = 99;
    }
    else
    {
      v6 = sub_7A990(0x50u);
      result = sub_77433(v6);
    }
  }
  if ( v4 == word_19B9B4 )
  {
    if ( sub_6AD3E() )
    {
      v7 = 81;
    }
    else
    {
      if ( (uint8_t)sub_5679E(word_19999C) )
      {
        v8 = *(_WORD *)(dword_1927A8 + 17);
        word_199860 = 2;
        word_19985E = v8;
        v9 = *(int16_t *)(dword_1927A8 + 21);
        dword_19B998 -= *(int16_t *)(dword_1927A8 + 19);
        dword_19B9A4 += v9;
        sub_6603E(a4);
        result = dword_1927A8;
        *(_BYTE *)(dword_1927A8 + 245) = 1;
        *a2 = 1;
        word_199A08 = 3;
        *a3 = 99;
        return result;
      }
      v7 = 82;
    }
    v10 = sub_7A990(v7);
    return sub_77433(v10);
  }
  return result;
}
// 77433: using guessed type int sub_77433(_DWORD);
// 1927A8: using guessed type int dword_1927A8;
// 19985E: using guessed type int16_t word_19985E;
// 199860: using guessed type int16_t word_199860;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 19B998: using guessed type int dword_19B998;
// 19B9A4: using guessed type int dword_19B9A4;
// 19B9B2: using guessed type int16_t word_19B9B2;
// 19B9B4: using guessed type int16_t word_19B9B4;


//----- (0006AE96) --------------------------------------------------------
char sub_6AE96( int a1)
{
  int v2; // eax
  int16_t v3; // si
  int16_t v4; // bx
  int16_t v5; // dx
  int v6; // ecx
  int16_t v7; // bx
  int16_t v8; // dx

  v2 = 3753 * word_19999C;
  v3 = *(uint8_t *)(dword_197F98 + v2 + 37);
  if ( a1 == word_199866 )
  {
    v2 = dword_1927A8;
    v4 = 8 * *(_WORD *)(dword_1927A8 + 229);
    v5 = 0;
    if ( *(_WORD *)(dword_1927A8 + 229) != 5 )
    {
      --*(_WORD *)(dword_1927A8 + 231);
      if ( v4 > *(int16_t *)(v2 + 231) )
        *(_WORD *)(v2 + 231) = v4 + 7;
      LOWORD(v2) = *(int16_t *)(dword_1927A8 + 231) / 8;
      v5 = *(int16_t *)(dword_1927A8 + 231) % 8;
    }
    if ( !byte_19B9BA )
    {
      v6 = dword_1927A8;
      v7 = v5;
LABEL_15:
      LOBYTE(v2) = sub_6C897(v3, *(int16_t *)(v6 + 229), v7, (char *)v6);
    }
  }
  else if ( a1 == word_199852 )
  {
    v2 = dword_1927A8;
    v8 = 8 * *(_WORD *)(dword_1927A8 + 229);
    v7 = 0;
    if ( *(_WORD *)(dword_1927A8 + 229) != 5 )
    {
      ++*(_WORD *)(dword_1927A8 + 231);
      if ( (int16_t)(v8 + 7) < *(int16_t *)(v2 + 231) )
        *(_WORD *)(v2 + 231) = v8;
      LOWORD(v2) = *(int16_t *)(dword_1927A8 + 231) / 8;
      v7 = *(int16_t *)(dword_1927A8 + 231) % 8;
    }
    if ( !byte_19B9BA )
    {
      v6 = dword_1927A8;
      goto LABEL_15;
    }
  }
  return v2;
}
// 1927A8: using guessed type int dword_1927A8;
// 197F98: using guessed type int dword_197F98;
// 199852: using guessed type int16_t word_199852;
// 199866: using guessed type int16_t word_199866;
// 19999C: using guessed type int16_t word_19999C;
// 19B9BA: using guessed type char byte_19B9BA;


//----- (0006AF9B) --------------------------------------------------------
int16_t sub_6AF9B( int a1, _WORD *a2, int16_t *a3)
{
  int16_t i; // bx
  int16_t v5; // dx
  int v6; // eax
  int16_t j; // ax
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  char v14[1332]; // [esp+4h] [ebp-538h] BYREF
  int v15; // [esp+538h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    v5 = i + (uint8_t)byte_199EF4;
    if ( word_1999BC == word_18B220[i] )
      word_1999BC = i + 2000;
    v6 = 2 * i;
    if ( a1 == *(int16_t *)((char *)word_18B220 + v6) )
    {
      if ( !*(_WORD *)(dword_1927A8 + 2 * v5 + 181) )
      {
        v15 = 0;
        a3 = (int16_t *)dword_1927A8;
        for ( j = 0; j < 8 && !(_WORD)v15; ++j )
        {
          if ( !*(_WORD *)(dword_1927A8 + 2 * j + 181) )
          {
            v15 = 1;
            v5 = j;
          }
        }
      }
      word_199856 = v5;
      v8 = dword_1927A8 + 2 * v5;
      word_199860 = 9;
      v9 = *(int16_t *)(v8 + 213);
      v10 = *(int16_t *)(v8 + 197);
      dword_19B9A4 += v9;
      dword_19B998 -= v10;
      sub_1196F7();
      sub_68755(a3);
      LOWORD(v6) = dword_1927A8;
      *(_BYTE *)(dword_1927A8 + 245) = 1;
      word_199A08 = 3;
      *a2 = 99;
    }
    else if ( a1 == -word_18B220[i] )
    {
      LOWORD(v6) = *(_WORD *)(dword_1927A8 + v6 + 181);
      if ( (int16_t)v6 > 0 )
      {
        v11 = 47 * (int16_t)v6;
        sub_6FBEA(v14, *(int16_t *)((char *)&word_17EEE6 + v11));
        LOWORD(v6) = sub_A5EB2(*(int *)((char *)&off_17EEE0 + v11), (int)v14);
      }
    }
  }
  return v6;
}
// 17EEE0: using guessed type _UNKNOWN *off_17EEE0;
// 17EEE6: using guessed type int16_t word_17EEE6;
// 18B220: using guessed type int16_t word_18B220[];
// 1927A8: using guessed type int dword_1927A8;
// 199856: using guessed type int16_t word_199856;
// 199860: using guessed type int16_t word_199860;
// 1999BC: using guessed type int16_t word_1999BC;
// 199A08: using guessed type int16_t word_199A08;
// 199EF4: using guessed type char byte_199EF4;
// 19B998: using guessed type int dword_19B998;
// 19B9A4: using guessed type int dword_19B9A4;


//----- (0006B0EF) --------------------------------------------------------
void sub_6B0EF( int a1, int a2, _WORD *a3)
{
  int16_t i; // bx
  int16_t v5; // cx
  unsigned int v6; // edx
  int16_t j; // dx
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int16_t v11; // ax
  int v12; // ecx
  char v14[1332]; // [esp+4h] [ebp-53Ch] BYREF
  int v15; // [esp+538h] [ebp-8h]
  int v16; // [esp+53Ch] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    v5 = i + (uint8_t)byte_199EF5;
    if ( word_1999BC == word_18B210[i] )
      word_1999BC = i + 1000;
    v6 = 2 * i;
    if ( a1 == word_18B210[v6 / 2] )
    {
      sub_119441();
      sub_117174(20);
      if ( !*(_WORD *)(v6 + dword_1927A8 + 53) )
      {
        v16 = 0;
        for ( j = 0; j < 8 && !(_WORD)v16; ++j )
        {
          v15 = 2 * j;
          if ( !*(_WORD *)(v15 + dword_1927A8 + 53) )
          {
            v16 = 1;
            v5 = j;
          }
        }
      }
      v8 = 4 * v5 + dword_1927A8;
      v9 = *(_DWORD *)(v8 + 141);
      word_199860 = 3;
      dword_19B9A4 += v9;
      v10 = *(_DWORD *)(v8 + 109);
      word_199856 = v5;
      dword_19B998 -= v10;
      sub_1196F7();
      sub_69583();
      *(_BYTE *)(dword_1927A8 + 245) = 1;
      word_199A08 = 3;
      *a3 = 99;
    }
    else if ( a1 == -word_18B210[i] )
    {
      v11 = *(_WORD *)(v6 + dword_1927A8 + 53);
      if ( v11 > 0 )
      {
        v12 = 14 * v11;
        sub_6FBEA(v14, word_17F80D[v12]);
        sub_A5EB2(*(int *)((char *)&off_17F803 + v12 * 2), (int)v14);
      }
    }
  }
}
// 17F803: using guessed type _UNKNOWN *off_17F803;
// 17F80D: using guessed type int16_t word_17F80D[];
// 18B210: using guessed type int16_t word_18B210[];
// 1927A8: using guessed type int dword_1927A8;
// 199856: using guessed type int16_t word_199856;
// 199860: using guessed type int16_t word_199860;
// 1999BC: using guessed type int16_t word_1999BC;
// 199A08: using guessed type int16_t word_199A08;
// 199EF5: using guessed type char byte_199EF5;
// 19B998: using guessed type int dword_19B998;
// 19B9A4: using guessed type int dword_19B9A4;


//----- (0006B247) --------------------------------------------------------
int sub_6B247()
{
  int16_t v0; // dx
  int v1; // eax
  int16_t v2; // ax
  int v3; // ebx
  int16_t v4; // ax
  int v5; // esi
  int v6; // eax
  int v7; // edx
  int v8; // esi
  int v9; // eax

  v0 = sub_56726(word_19999C);
  v1 = dword_1927A8;
  *(_WORD *)(dword_1927A8 + 27) = v0;
  *(_WORD *)(v1 + 29) = word_17FE9C[23 * v0];
  *(_WORD *)(dword_1927A8 + 43) = sub_5680D(word_19999C);
  sub_5685F(word_19999C);
  *(_WORD *)(dword_1927A8 + 49) = v2;
  sub_5709F(word_19999C);
  v3 = 0;
  *(_WORD *)(dword_1927A8 + 47) = v4;
  do
  {
    v5 = dword_1927A8;
    v6 = (int16_t)v3;
    *(_WORD *)(dword_1927A8 + 2 * (int16_t)v3 + 53) = 0;
    *(_WORD *)(v5 + 2 * (int16_t)v3 + 69) = 0;
    *(_BYTE *)((int16_t)v3 + v5 + 85) = 0;
    *(_WORD *)(v5 + 2 * (int16_t)v3 + 93) = 0;
    *(_BYTE *)((int16_t)v3 + v5 + 173) = 0;
    *(_DWORD *)(v5 + 4 * (int16_t)v3++ + 141) = 0;
    *(_DWORD *)(v5 + 4 * v6 + 109) = 0;
  }
  while ( (int16_t)v3 < 8 );
  v7 = 0;
  do
  {
    v8 = dword_1927A8;
    v9 = (int16_t)v7;
    *(_WORD *)(dword_1927A8 + 2 * (int16_t)v7 + 181) = 0;
    *(_WORD *)(v8 + 2 * (int16_t)v7++ + 197) = 0;
    *(_WORD *)(v8 + 2 * v9 + 213) = 0;
  }
  while ( (int16_t)v7 < 8 );
  return sub_6E8DA(word_19999C);
}
// 6B29D: variable 'v2' is possibly undefined
// 6B2B6: variable 'v4' is possibly undefined
// 17FE9C: using guessed type int16_t word_17FE9C[];
// 1927A8: using guessed type int dword_1927A8;
// 19999C: using guessed type int16_t word_19999C;


//----- (0006B342) --------------------------------------------------------
void sub_6B342( int a1, int a2)
{
  int v2; // ecx
  char v3[20]; // [esp+0h] [ebp-18h] BYREF
  int v4; // [esp+14h] [ebp-4h]

  v2 = 99 * a2;
  v4 = 3753 * a1;
  strcpy(v3, (char *)(v4 + dword_197F98 + 806 + v2));
  memset(v2 + v4 + dword_197F98 + 806, 0, 99);
  strcpy((char *)(v2 + v4 + dword_197F98 + 806), v3);
  JUMPOUT(0x6AB15);
}
// 6B3AF: control flows out of bounds to 6AB15
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;


//----- (0006B3B4) --------------------------------------------------------
int sub_6B3B4( int a1)
{
  int v2; // eax
  int v3; // ebx
  int result; // eax

  while ( 1 )
  {
    v3 = (uint8_t)byte_199EF3;
    if ( a1 >= (uint8_t)byte_199EF3 - 1 )
      break;
    v2 = 2 * a1 + dword_1927A8;
    *(_WORD *)(v2 + 181) = *(_WORD *)(v2 + 183);
    *(_WORD *)(v2 + 197) = *(_WORD *)(v2 + 199);
    ++a1;
    *(_WORD *)(v2 + 213) = *(_WORD *)(v2 + 215);
  }
  result = dword_1927A8;
  *(_WORD *)(dword_1927A8 + 2 * (uint8_t)byte_199EF3 + 179) = 0;
  *(_WORD *)(result + 2 * v3 + 195) = 0;
  *(_WORD *)(result + 2 * v3 + 211) = 0;
  return result;
}
// 1927A8: using guessed type int dword_1927A8;
// 199EF3: using guessed type char byte_199EF3;


//----- (0006B428) --------------------------------------------------------
void sub_6B428( int a1)
{
  int v2; // esi
  char v3; // al
  int v4; // ebx
  int v5; // ecx
  int v6; // ecx

  while ( 1 )
  {
    v4 = (uint8_t)byte_199EED;
    v5 = a1;
    if ( a1 >= (uint8_t)byte_199EED - 1 )
      break;
    v2 = dword_1927A8;
    *(_WORD *)(dword_1927A8 + 2 * a1 + 53) = *(_WORD *)(dword_1927A8 + 2 * a1 + 55);
    *(_WORD *)(v2 + 2 * a1 + 69) = *(_WORD *)(v2 + 2 * a1 + 71);
    *(_BYTE *)(a1 + v2 + 85) = *(_BYTE *)(a1 + v2 + 86);
    *(_WORD *)(v2 + 2 * a1 + 93) = *(_WORD *)(v2 + 2 * a1 + 95);
    *(_DWORD *)(v2 + 4 * a1 + 109) = *(_DWORD *)(v2 + 4 * a1 + 113);
    *(_DWORD *)(v2 + 4 * a1 + 141) = *(_DWORD *)(v2 + 4 * a1 + 145);
    v3 = *(_BYTE *)(a1++ + v2 + 174);
    *(_BYTE *)(v5 + v2 + 173) = v3;
  }
  v6 = dword_1927A8;
  *(_WORD *)(dword_1927A8 + 2 * (uint8_t)byte_199EED + 51) = 0;
  *(_WORD *)(v6 + 2 * v4 + 67) = 0;
  *(_BYTE *)(v6 + v4 + 84) = 0;
  *(_WORD *)(v6 + 2 * v4 + 91) = 0;
  *(_DWORD *)(v6 + 4 * v4 + 105) = 0;
  *(_DWORD *)(v6 + 4 * v4 + 137) = 0;
  *(_BYTE *)(v6 + v4 + 172) = 0;
  JUMPOUT(0x6A3DF);
}
// 6B4D2: control flows out of bounds to 6A3DF
// 1927A8: using guessed type int dword_1927A8;
// 199EED: using guessed type char byte_199EED;


//----- (0006B4D7) --------------------------------------------------------
int16_t sub_6B4D7( int a1)
{
  int16_t result; // ax

  result = word_17FDF4[11 * a1 + *(int16_t *)(dword_1927A8 + 229)];
  if ( !result )
    return a1 > 0;
  return result;
}
// 17FDF4: using guessed type int16_t word_17FDF4[];
// 1927A8: using guessed type int dword_1927A8;


//----- (0006B519) --------------------------------------------------------
int sub_6B519( int a1, int a2)
{
  int16_t v3; // ax
  int result; // eax

  switch ( a2 )
  {
    case 0:
      v3 = 100;
      break;
    case 1:
      v3 = 75;
      break;
    case 2:
      v3 = 55;
      break;
    case 3:
      v3 = 40;
      break;
    case 4:
      v3 = 30;
      break;
    default:
      v3 = 25;
      break;
  }
  result = a1 * v3 / 100;
  if ( !(_WORD)result && a1 > 0 )
    return 1;
  return result;
}


//----- (0006B577) --------------------------------------------------------
int sub_6B577(int a1, int a2)
{
  int v3; // eax
  int16_t v4; // dx
  int16_t v5; // dx
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int16_t v9; // ax
  int v10; // edx
  int v11; // edx
  char v12; // al
  int v13; // edx
  int v14; // eax
  int v15; // ebx
  int v16; // ecx
  int v17; // esi
  _BOOL2 v18; // di
  int i; // ebx
  int v20; // ecx
  uint8_t v21; // bl
  int16_t v23; // [esp+0h] [ebp+7Ah]
  char v24[296]; // [esp+4h] [ebp+7Eh] BYREF
  int v25; // [esp+12Ch] [ebp+1A6h]

  memset(v24, 0, 293);
  dword_1927A8 = (int)v24;
  strcpy(v24, (char *)a2);
  v3 = dword_1927A8;
  v4 = *(uint8_t *)(a2 + 19);
  *(_WORD *)(dword_1927A8 + 27) = v4;
  *(_WORD *)(v3 + 29) = word_17FE9C[23 * v4];
  v5 = *(uint8_t *)(a2 + 16);
  *(_WORD *)(v3 + 229) = v5;
  v6 = word_180020[18 * v5];
  if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 368) == 3 )
    v6 = 125 * v6 / 100;
  v7 = dword_1927A8;
  *(_DWORD *)(dword_1927A8 + 233) = v6;
  *(_WORD *)(v7 + 43) = *(uint8_t *)(a2 + 21);
  *(_WORD *)(v7 + 231) = *(char *)(a2 + 92);
  *(_WORD *)(v7 + 49) = *(uint8_t *)(a2 + 22);
  sub_5709F(v23);
  v8 = 0;
  *(_WORD *)(dword_1927A8 + 47) = v9;
  do
  {
    v10 = dword_1927A8 + 2 * (int16_t)v8;
    v25 = dword_1927A8;
    *(_WORD *)(v10 + 53) = *(_WORD *)(a2 + 8 * (int16_t)v8 + 28);
    *(_WORD *)(v10 + 69) = *(uint8_t *)(a2 + 8 * (int16_t)v8 + 30);
    *(_WORD *)(v10 + 93) = *(_WORD *)(a2 + 8 * (int16_t)v8 + 33);
    v11 = (int16_t)v8 + v25;
    *(_BYTE *)(v11 + 85) = *(_BYTE *)(a2 + 8 * (int16_t)v8 + 32);
    v12 = *(_BYTE *)(a2 + 8 * (int16_t)v8++ + 35);
    *(_BYTE *)(v11 + 173) = v12;
  }
  while ( (int16_t)v8 < 8 );
  v13 = 0;
  do
  {
    v14 = dword_1927A8;
    v15 = 2 * (int16_t)v13;
    *(_WORD *)(v15 + dword_1927A8 + 181) = 0;
    *(_WORD *)(v15 + v14 + 197) = 0;
    ++v13;
    *(_WORD *)(v15 + v14 + 213) = 0;
  }
  while ( (int16_t)v13 < 8 );
  v16 = a2 + 23;
  v17 = 0;
  v18 = 0;
  for ( i = 0; (int16_t)i < 39 && !v18; ++i )
  {
    if ( (uint16_t)sub_1276F0(v16, (int16_t)i) )
    {
      v25 = 2 * (int16_t)v17++;
      *(_WORD *)(v25 + dword_1927A8 + 181) = i;
      v18 = (int16_t)v17 >= 8;
    }
  }
  v20 = dword_1927A8;
  v21 = sub_6B86A(dword_1927A8, 2, i, dword_1927A8);
  if ( (uint8_t)sub_6B7FF(v20, 2) && byte_19B9B8 )
    v21 += 5;
  *(_WORD *)(dword_1927A8 + 37) = v21;
  sub_6E8DA(v23);
  return *(_DWORD *)(dword_1927A8 + 241);
}
// 6B63D: variable 'v23' is possibly undefined
// 6B64B: variable 'v9' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 17FE9C: using guessed type int16_t word_17FE9C[];
// 180020: using guessed type int16_t word_180020[];
// 1927A8: using guessed type int dword_1927A8;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19B9B8: using guessed type char byte_19B9B8;


//----- (0006B77B) --------------------------------------------------------
int sub_6B77B()
{
  int v0; // ecx
  int v1; // ecx

  v0 = word_180024[18 * *(int16_t *)(dword_1927A8 + 229)];
  v1 = v0 * *(int16_t *)((char *)&word_17F642 + 15 * *(int16_t *)(dword_1927A8 + 49)) / 100 + v0;
  if ( (uint8_t)sub_6B7FF(dword_1927A8, 14) )
    v1 *= 3;
  return v1;
}
// 17F642: using guessed type int16_t word_17F642;
// 180024: using guessed type int16_t word_180024[];
// 1927A8: using guessed type int dword_1927A8;


//----- (0006B7CF) --------------------------------------------------------
char sub_6B7CF(int a1, int a2, int a3, int a4)
{
  char v5; // cl

  v5 = sub_6B86A(a1, a2, a1, a4);
  if ( (uint8_t)sub_6B7FF(a1, 2) && byte_19B9B8 )
    v5 += 5;
  return v5;
}
// 19B9B8: using guessed type char byte_19B9B8;


//----- (0006B7FF) --------------------------------------------------------
int sub_6B7FF(int result, int a2)
{
  int v2; // ecx
  int16_t i; // dx

  v2 = result;
  LOBYTE(result) = 0;
  for ( i = 0; i < 8 && !(_BYTE)result; ++i )
    LOBYTE(result) = a2 == *(_WORD *)(v2 + 2 * i + 181);
  return result;
}


//----- (0006B82A) --------------------------------------------------------
char sub_6B82A(int a1)
{
  return byte_17FE90[46 * *(int16_t *)(a1 + 27) + *(int16_t *)(a1 + 229)];
}


//----- (0006B84A) --------------------------------------------------------
char sub_6B84A(int a1)
{
  return byte_17FE96[46 * *(int16_t *)(a1 + 27) + *(int16_t *)(a1 + 229)];
}


//----- (0006B86A) --------------------------------------------------------
int sub_6B86A(int a1, int a2, int a3, int a4)
{
  int v5; // eax
  int v6; // edx
  int result; // eax

  v5 = 46 * *(int16_t *)(a1 + 27);
  v6 = *(int16_t *)(a1 + 229);
  LOWORD(a4) = (uint8_t)byte_17FE90[v6 + v5];
  result = (uint8_t)byte_17FE96[v6 + v5]
         - (int16_t)((uint8_t)byte_17FE96[v6 + v5] - (_WORD)a4)
         * (100
          * *(_DWORD *)(a1 + 237)
          / *(_DWORD *)(a1 + 233))
         / 100;
  if ( (uint8_t)a4 >= (int16_t)result )
    return a4;
  return result;
}


//----- (0006B8D2) --------------------------------------------------------
char sub_6B8D2()
{
  return *(_BYTE *)(dword_1927A8 + 17);
}
// 1927A8: using guessed type int dword_1927A8;


//----- (0006B8DB) --------------------------------------------------------
int16_t sub_6B8DB()
{
  return *(_WORD *)(dword_1927A8 + 19);
}
// 1927A8: using guessed type int dword_1927A8;


//----- (0006B8E5) --------------------------------------------------------
int16_t sub_6B8E5()
{
  return *(_WORD *)(dword_1927A8 + 21);
}
// 1927A8: using guessed type int dword_1927A8;


//----- (0006B8EF) --------------------------------------------------------
int sub_6B8EF()
{
  int v0; // ebx

  v0 = 59 * *(int16_t *)(dword_1927A8 + 17);
  LOWORD(v0) = *(int16_t *)((char *)&word_17F6C1 + v0);
  if ( (uint8_t)sub_6B7FF(dword_1927A8, 13) )
    v0 += 3;
  return v0;
}
// 17F6C1: using guessed type int16_t word_17F6C1;
// 1927A8: using guessed type int dword_1927A8;


//----- (0006B91A) --------------------------------------------------------
int sub_6B91A()
{
  int16_t v0; // bx
  char v1; // al

  v0 = word_19999C;
  v1 = sub_6B7FF(dword_1927A8, 27);
  return sub_58330(*(_WORD *)(dword_1927A8 + 229), v1, v0);
}
// 1927A8: using guessed type int dword_1927A8;
// 19999C: using guessed type int16_t word_19999C;


//----- (0006B949) --------------------------------------------------------
int16_t sub_6B949()
{
  _BYTE v1[100]; // [esp+0h] [ebp-64h] BYREF

  if ( !byte_199EF1 )
    return dword_19B998;
  sub_6A6A1((int)v1);
  return sub_D108B(word_19999C, 99 * word_199838 + dword_197F98 + 3753 * word_19999C + 806, (int)v1);
}
// 197F98: using guessed type int dword_197F98;
// 199838: using guessed type int16_t word_199838;
// 19999C: using guessed type int16_t word_19999C;
// 199EF1: using guessed type char byte_199EF1;
// 19B998: using guessed type int dword_19B998;


//----- (0006B9B2) --------------------------------------------------------
void sub_6B9B2(int a1, int a2, int16_t *a3)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int16_t v6; // ax
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int16_t v13; // si
  int16_t *v14; // eax
  int v15; // eax
  int v16; // edx
  int i; // edi
  int v18; // ecx
  int16_t v19; // ax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // ebx
  int v25; // eax
  int v26; // eax
  int16_t *v27; // eax
  uint16_t v28; // [esp-8h] [ebp-6h]
  int16_t v29; // [esp-4h] [ebp-2h]
  int v30; // [esp-4h] [ebp-2h]
  _BYTE v31[100]; // [esp+0h] [ebp+2h] BYREF
  int v32; // [esp+64h] [ebp+66h]
  int v33; // [esp+68h] [ebp+6Ah]
  int v34; // [esp+6Ch] [ebp+6Eh]
  int v35; // [esp+70h] [ebp+72h]
  int v36; // [esp+74h] [ebp+76h]
  int v37; // [esp+78h] [ebp+7Ah] BYREF
  int v38; // [esp+7Ch] [ebp+7Eh] BYREF

  sub_124B65();
  word_19995E = 0;
  byte_19B995 = 1;
  byte_199EF5 = 0;
  byte_199EF4 = 0;
  byte_19B9B9 = 0;
  LOWORD(v3) = word_199838;
  v35 = v3;
  byte_19B9B8 = 1;
  sub_1191CA((int)sub_6C6CD, 2);
  sub_11C2F0();
  word_19B9B6 = -1000;
  LOWORD(v4) = sub_123E6C((int)&unk_17CF0C, 1);
  if ( byte_199EF2 )
  {
    byte_199EEF = 1;
    sub_6C98D(v4, 1, a2, a3);
    sub_6A7C8(word_19999C, word_199838);
    sub_6E777();
    dword_19274C = v5;
    if ( byte_199EF1 )
      *(_DWORD *)(dword_1927A8 + 241) = 0;
    dword_19B9A4 = *(_DWORD *)(dword_1927A8 + 233) - *(_DWORD *)(dword_1927A8 + 237);
    v6 = *(_WORD *)(dword_1927A8 + 229);
    dword_19B998 = *(_DWORD *)(dword_1927A8 + 241);
    word_199854 = v6;
    sub_11C2F0();
    word_19B9B6 = -1000;
    sub_69E62();
    sub_1172D4();
    sub_124B65();
    sub_C5BB9();
    sub_1205E6(4, 0, 255);
    sub_1318D4(0, 255);
    sub_585E0(word_19999C, 255);
    sub_131F7B();
    sub_132C80(100);
    sub_124D41();
    sub_12A478(0, 0, dword_1927F4);
    sub_6C704();
    sub_6D29C();
    sub_6AB9A();
    v7 = 1;
    sub_24677(8, -1, 1);
    v36 = 1;
    v8 = sub_131922(0, 255);
    sub_1077D(v8, 255, 1, a3);
    sub_C5C44();
    sub_1172FC();
    byte_199EF2 = 0;
    sub_128BE7();
    sub_12B65C();
  }
  else
  {
    byte_19B9BA = 0;
    sub_585E0(word_19999C, 1);
    sub_128BE7();
    sub_12B65C();
    word_199854 = *(_WORD *)(dword_1927A8 + 229);
    sub_11C2F0();
    word_19B9B6 = -1000;
    sub_69E62();
    byte_199EEF = 1;
    sub_124D41();
    v9 = *(_DWORD *)(dword_1927A8 + 241);
    dword_19B9A4 = *(_DWORD *)(dword_1927A8 + 233) - *(_DWORD *)(dword_1927A8 + 237);
    dword_19B998 = v9;
    sub_12A478(0, 0, dword_1927F4);
    sub_6C704();
    sub_6D29C();
    sub_6AB9A();
    v7 = 1;
    v36 = 1;
    v10 = sub_24677(8, -1, 1);
    sub_1077D(v10, -1, 1, a3);
  }
  sub_123E6C((int)&unk_17CF00, 1);
  v11 = *(int16_t *)(dword_1927A8 + 248);
  sub_6F544(*(_WORD *)(dword_1927A8 + 246), v11);
  v38 = 0;
  while ( 1 )
  {
    if ( (_WORD)v38 )
    {
      sub_113F0A();
      sub_11C2F0();
      byte_199F38 = 0;
      if ( word_199A08 != 3 )
        sub_2484F();
      JUMPOUT(0x6A3DF);
    }
    sub_12C2A0();
    v13 = sub_1171AB(v12, v11, v7, a1);
    word_1999BC = (uint16_t)sub_114177();
    if ( !byte_19B9BA )
    {
      v14 = sub_77AE6(word_19999C, word_199838);
      if ( strcmp(dword_1927A8, v14) )
        byte_19B9BA = 1;
    }
    if ( v13 == word_19985C )
    {
      v36 = 0;
    }
    else if ( v13 )
    {
      v36 = 1;
    }
    if ( v13 == word_199864 )
    {
      v38 = 1;
      word_199838 = 0;
      word_199A08 = word_199A10;
    }
    if ( v13 == word_19984C )
    {
      sub_6B247();
      sub_6F544(*(_WORD *)(dword_1927A8 + 246), *(_WORD *)(dword_1927A8 + 248));
    }
    if ( v13 == word_19984E )
    {
      sub_6EA48(word_19999C, v35);
      v38 = 1;
      word_199838 = 1;
      word_199A08 = word_199A10;
    }
    if ( v13 == word_19C18C )
      sprintf(v31, "cstdes%d.log", *(int16_t *)(dword_1927A8 + 229));
    a1 = v13;
    v37 = 0;
    sub_6AD7C(v13, &v37, &v38, a3);
    sub_6B0EF(v13, (int)&v37, &v38);
    v7 = (int)&v38;
    sub_6AF9B(v13, &v38, a3);
    v11 = (int)&v37;
    sub_6AE96(v13);
    v15 = dword_1927A8;
    LOWORD(v11) = word_199854;
    if ( word_199854 != *(_WORD *)(dword_1927A8 + 229) )
    {
      a1 = 36 * word_199854;
      *(_WORD *)(dword_1927A8 + 229) = word_199854;
      v16 = *(int16_t *)((char *)word_180020 + a1);
      *(_DWORD *)(v15 + 233) = v16;
      v37 = 1;
      LOWORD(v16) = *(_WORD *)(v15 + 229);
      v11 = 8 * v16;
      if ( *(_WORD *)(v15 + 229) == 5 )
        *(_WORD *)(v15 + 231) = 43;
      else
        *(_WORD *)(v15 + 231) = v11;
    }
    LOBYTE(a1) = 0;
    for ( i = 0; (int16_t)i < 8 && !(_BYTE)a1; ++i )
    {
      LOWORD(v11) = (uint8_t)byte_199EF5;
      v11 += i;
      if ( v13 == word_18B1E0[(int16_t)i] )
      {
        v34 = 2 * (int16_t)v11;
        v33 = dword_1927A8 + 4 * (int16_t)v11;
        v18 = (int16_t)v11 + dword_1927A8;
        v29 = *(_WORD *)(dword_1927A8 + v34 + 93);
        v28 = *(uint8_t *)(v18 + 173);
        a1 = *(uint8_t *)(v18 + 85);
        v7 = (int16_t)(*(_WORD *)(dword_1927A8 + v34 + 69) + 1);
        v19 = *(_WORD *)(dword_1927A8 + v34 + 53);
        v32 = word_19999C;
        v11 = (int16_t)(*(_WORD *)(dword_1927A8 + 237)
                      + sub_6EE8E(word_19999C, v19, v7, a1, v28, v29)
                      - *(_WORD *)(v33 + 141));
        LOBYTE(a1) = 1;
        if ( v11 <= *(_DWORD *)(dword_1927A8 + 233) )
        {
          v20 = v34 + dword_1927A8;
          if ( (int16_t)++*(_WORD *)(v20 + 69) > 99 )
            *(_WORD *)(v20 + 69) = 99;
          byte_19B9B9 = 0;
          v37 = 1;
        }
      }
      else if ( v13 == word_18B200[(int16_t)i] )
      {
        v21 = (int16_t)v11;
        v11 = dword_1927A8;
        v22 = dword_1927A8 + 2 * v21;
        if ( (int16_t)--*(_WORD *)(v22 + 69) < 1 )
          *(_WORD *)(v22 + 69) = 1;
        v37 = 1;
        byte_19B9B9 = 0;
      }
    }
    if ( (_WORD)v37 )
    {
      sub_6E8DA(word_19999C);
      v37 = 0;
    }
    if ( (_WORD)v36 )
    {
      sub_11C2F0();
      word_19B9B6 = -1000;
      sub_69E62();
    }
    a3 = 0;
    do
    {
      if ( v13 == word_192750[(int16_t)a3] )
      {
        if ( (uint8_t)byte_19B9AC[(int16_t)a3] <= 0xF0u )
        {
          a1 = dword_1927A8;
          v7 = *(int16_t *)(dword_1927A8 + 231) % 8;
          v23 = *(uint8_t *)(dword_197F98 + 3753 * word_19999C + 37);
          v11 = *(int16_t *)(dword_1927A8 + 229);
          byte_19B9BA = 0;
          sub_6C897(v23, v11, v7, (char *)dword_1927A8);
        }
        else
        {
          sub_6E091((int16_t)a3);
        }
      }
      a3 = (int16_t *)((char *)a3 + 1);
    }
    while ( (int16_t)a3 < 6 );
    if ( (_WORD)v38 )
    {
      if ( (_WORD)v38 != 99 )
        goto LABEL_55;
      sub_124D41();
      v24 = dword_1927F4;
    }
    else
    {
      sub_124D41();
      v24 = dword_1927F4;
      v25 = *(_DWORD *)(dword_1927A8 + 241);
      dword_19B9A4 = *(_DWORD *)(dword_1927A8 + 233) - *(_DWORD *)(dword_1927A8 + 237);
      dword_19B998 = v25;
    }
    sub_12A478(0, 0, v24);
    sub_6C704();
    sub_6D29C();
    sub_6AB9A();
    v7 = 1;
    v11 = -1;
    v26 = sub_24677(8, -1, 1);
    sub_1077D(v26, -1, 1, a3);
LABEL_55:
    sub_13303E(dword_1927A8);
    if ( !*(_BYTE *)dword_1927A8 )
    {
      v11 = (int16_t)v35;
      v27 = sub_77AE6(word_19999C, v35);
      v30 = dword_1927A8;
      strcpy((char *)dword_1927A8, (char *)v27);
      a3 = (int16_t *)v30;
    }
    sub_12C2C6(2);
  }
}
// 6C082: control flows out of bounds to 6A3DF
// 6B9F6: variable 'v3' is possibly undefined
// 6BA3B: variable 'v4' is possibly undefined
// 6BA58: variable 'v5' is possibly undefined
// 6BC5A: variable 'v12' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 138B90: using guessed type int strcmp(_DWORD, _DWORD);
// 180020: using guessed type int16_t word_180020[];
// 18B1E0: using guessed type int16_t word_18B1E0[];
// 18B200: using guessed type int16_t word_18B200[];
// 19274C: using guessed type int dword_19274C;
// 192750: using guessed type int16_t word_192750[6];
// 1927A8: using guessed type int dword_1927A8;
// 1927F4: using guessed type int dword_1927F4;
// 197F98: using guessed type int dword_197F98;
// 199838: using guessed type int16_t word_199838;
// 19984C: using guessed type int16_t word_19984C;
// 19984E: using guessed type int16_t word_19984E;
// 199854: using guessed type int16_t word_199854;
// 19985C: using guessed type int16_t word_19985C;
// 199864: using guessed type int16_t word_199864;
// 19995E: using guessed type int16_t word_19995E;
// 19999C: using guessed type int16_t word_19999C;
// 1999BC: using guessed type int16_t word_1999BC;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199EEF: using guessed type char byte_199EEF;
// 199EF1: using guessed type char byte_199EF1;
// 199EF2: using guessed type char byte_199EF2;
// 199EF4: using guessed type char byte_199EF4;
// 199EF5: using guessed type char byte_199EF5;
// 199F38: using guessed type char byte_199F38;
// 19B995: using guessed type char byte_19B995;
// 19B998: using guessed type int dword_19B998;
// 19B9A4: using guessed type int dword_19B9A4;
// 19B9B6: using guessed type int16_t word_19B9B6;
// 19B9B8: using guessed type char byte_19B9B8;
// 19B9B9: using guessed type char byte_19B9B9;
// 19B9BA: using guessed type char byte_19B9BA;
// 19C18C: using guessed type int16_t word_19C18C;


//----- (0006C087) --------------------------------------------------------
void sub_6C087( int a1)
{
  int16_t v2; // dx
  int16_t v3; // cx
  int16_t v4; // ax
  int16_t v5; // dx
  int v6; // eax
  int16_t v7; // ax
  int16_t v8; // ax
  int v9; // ebx
  int16_t v10; // di
  int v11; // eax
  int16_t v12; // bx
  int v13; // eax
  int16_t v14; // cx
  int16_t v15; // ax
  int16_t v16; // dx
  int16_t v17; // bx
  int16_t v18; // ax
  int v19; // [esp+4h] [ebp-4h]

  v2 = *(_WORD *)(dword_1927A8 + 17);
  v3 = *(int16_t *)((char *)&word_17F6B5 + 59 * v2 + 2 * *(int16_t *)(dword_1927A8 + 229));
  if ( v2 > 0 && !v3 )
    v3 = 1;
  sub_6E70A(a1, *(int16_t *)((char *)&word_17F6A7 + 59 * v2));
  v5 = sub_6B519(v3, v4);
  v6 = dword_1927A8;
  *(_WORD *)(dword_1927A8 + 19) = v5;
  sub_6E70A(a1, word_17FE76[23 * *(int16_t *)(v6 + 27)]);
  v8 = sub_6B519(word_17FE84[23 * *(int16_t *)(dword_1927A8 + 27) + *(int16_t *)(dword_1927A8 + 229)], v7);
  v9 = dword_1927A8;
  *(_WORD *)(dword_1927A8 + 31) = v8;
  v10 = 0;
  *(_WORD *)(v9 + 51) = *(int16_t *)((char *)&word_17F644 + 15 * *(int16_t *)(v9 + 49))
                      * word_18001E[18 * *(int16_t *)(v9 + 229)]
                      / 100;
  while ( 1 )
  {
    v11 = dword_1927A8 + 2 * v10;
    if ( *(int16_t *)(v11 + 53) > 0 )
      *(_DWORD *)(dword_1927A8 + 4 * v10 + 109) = sub_6EC74(
                                                    *(_WORD *)(v11 + 53),
                                                    *(int16_t *)(v11 + 69),
                                                    *(uint8_t *)(v10 + dword_1927A8 + 85),
                                                    *(uint8_t *)(v10 + dword_1927A8 + 173),
                                                    *(_WORD *)(v11 + 93));
    if ( ++v10 >= 8 )
    {
      v12 = 0;
      while ( 1 )
      {
        v19 = 2 * v12;
        v13 = dword_1927A8 + v19;
        v14 = *(int16_t *)((char *)&word_17EEF4
                         + 47 * *(int16_t *)(dword_1927A8 + v19 + 181)
                         + 2 * *(int16_t *)(dword_1927A8 + 229));
        if ( *(int16_t *)(dword_1927A8 + v19 + 181) > 0 )
        {
          if ( *(_WORD *)(v13 + 181) == 4 )
          {
            *(_WORD *)(v13 + 197) = v14;
          }
          else
          {
            sub_6E70A(a1, *(int16_t *)((char *)&word_17EEE6 + 47 * *(int16_t *)(dword_1927A8 + v19 + 181)));
            *(_WORD *)(v19 + dword_1927A8 + 197) = sub_6B519(v14, v15);
          }
        }
        if ( ++v12 >= 8 )
        {
          v16 = *(_WORD *)(dword_1927A8 + 43);
          v17 = word_17FDF4[11 * v16 + *(int16_t *)(dword_1927A8 + 229)];
          if ( !v17 )
            v17 = v16 > 0;
          sub_6E70A(a1, word_17FDF2[11 * *(int16_t *)(dword_1927A8 + 43)]);
          *(_WORD *)(dword_1927A8 + 45) = sub_6B519(v17, v18);
          JUMPOUT(0x6A3DE);
        }
      }
    }
  }
}
// 6C282: control flows out of bounds to 6A3DE
// 6C0DC: variable 'v4' is possibly undefined
// 6C11F: variable 'v7' is possibly undefined
// 6C207: variable 'v15' is possibly undefined
// 6C272: variable 'v18' is possibly undefined
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EEF4: using guessed type int16_t word_17EEF4;
// 17F644: using guessed type int16_t word_17F644;
// 17F6A7: using guessed type int16_t word_17F6A7;
// 17F6B5: using guessed type int16_t word_17F6B5;
// 17FDF2: using guessed type int16_t word_17FDF2[];
// 17FDF4: using guessed type int16_t word_17FDF4[];
// 17FE76: using guessed type int16_t word_17FE76[];
// 17FE84: using guessed type int16_t word_17FE84[];
// 18001E: using guessed type int16_t word_18001E[];
// 1927A8: using guessed type int dword_1927A8;


//----- (0006C287) --------------------------------------------------------
void sub_6C287( int a1)
{
  char v2; // bl
  int16_t v3; // ax
  int16_t v4; // dx
  int v5; // eax
  int16_t v6; // si
  int v7; // eax
  int16_t v8; // dx
  int16_t v9; // bx
  int16_t v10; // si
  int16_t v11; // ax
  int16_t v12; // ax
  int16_t v13; // si
  int v14; // ecx
  int v15; // eax
  int16_t v16; // ax
  char v17; // [esp+0h] [ebp-10h]

  v2 = sub_6F11C(word_17FE76[23 * *(int16_t *)(dword_1927A8 + 27)]);
  sub_6E70A(a1, word_17FE76[23 * *(int16_t *)(dword_1927A8 + 27)]);
  v4 = sub_6E60E(word_17FE78[23 * *(int16_t *)(dword_1927A8 + 27) + *(int16_t *)(dword_1927A8 + 229)], v3, v2);
  v5 = dword_1927A8;
  *(_WORD *)(dword_1927A8 + 41) = 0;
  v6 = 0;
  *(_WORD *)(v5 + 33) = v4;
  while ( 1 )
  {
    v7 = dword_1927A8 + 2 * v6;
    if ( *(int16_t *)(v7 + 53) > 0 )
      *(_DWORD *)(dword_1927A8 + 4 * v6 + 141) = sub_6EE8E(
                                                   word_19999C,
                                                   *(_WORD *)(v7 + 53),
                                                   *(_WORD *)(v7 + 69),
                                                   *(uint8_t *)(v6 + dword_1927A8 + 85),
                                                   *(uint8_t *)(v6 + dword_1927A8 + 173),
                                                   *(_WORD *)(v7 + 93));
    if ( ++v6 >= 8 )
    {
      v8 = word_19999C;
      v9 = *(_WORD *)(dword_1927A8 + 17);
      v10 = sub_6E369(v9, *(_WORD *)(dword_1927A8 + 229));
      sub_6E70A(v8, *(int16_t *)((char *)&word_17F6A7 + 59 * v9));
      v12 = sub_6E60E(v10, v11, 0);
      v13 = 0;
      *(_WORD *)(dword_1927A8 + 21) = v12;
      while ( 1 )
      {
        v14 = 2 * v13;
        v15 = dword_1927A8 + v14;
        if ( *(int16_t *)(dword_1927A8 + v14 + 181) > 0 )
        {
          if ( *(_WORD *)(v15 + 181) == 4 )
          {
            *(_WORD *)(v15 + 213) = *(int16_t *)((char *)&word_17EEE8
                                               + 47 * *(int16_t *)(v15 + 181)
                                               + 2 * *(int16_t *)(dword_1927A8 + 229));
          }
          else
          {
            v17 = sub_6F11C(*(int16_t *)((char *)&word_17EEE6 + 47 * *(int16_t *)(v15 + 181)));
            sub_6E70A(a1, *(int16_t *)((char *)&word_17EEE6 + 47 * *(int16_t *)(v14 + dword_1927A8 + 181)));
            *(_WORD *)(v14 + dword_1927A8 + 213) = sub_6E60E(
                                                     *(int16_t *)((char *)&word_17EEE8
                                                                + 47 * *(int16_t *)(v14 + dword_1927A8 + 181)
                                                                + 2 * *(int16_t *)(dword_1927A8 + 229)),
                                                     v16,
                                                     v17);
          }
        }
        if ( ++v13 >= 8 )
          JUMPOUT(0x6A3DE);
      }
    }
  }
}
// 6C479: control flows out of bounds to 6A3DE
// 6C2E6: variable 'v3' is possibly undefined
// 6C39A: variable 'v11' is possibly undefined
// 6C45B: variable 'v16' is possibly undefined
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EEE8: using guessed type int16_t word_17EEE8;
// 17F6A7: using guessed type int16_t word_17F6A7;
// 17FE76: using guessed type int16_t word_17FE76[];
// 17FE78: using guessed type int16_t word_17FE78[];
// 1927A8: using guessed type int dword_1927A8;
// 19999C: using guessed type int16_t word_19999C;


//----- (0006C47E) --------------------------------------------------------
char sub_6C47E(int a1, char *a2, int a3, int a4)
{
  _BOOL1 v4; // bl
  int16_t v5; // bx
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  char result; // al
  char v13[20]; // [esp+Ch] [ebp-20h] BYREF
  int v14; // [esp+20h] [ebp-Ch]
  int v15; // [esp+24h] [ebp-8h]
  _BOOL1 v16; // [esp+28h] [ebp-4h]

  v14 = 0;
  v4 = a4 == -1 && a3 == -1;
  v16 = v4;
  if ( v4 )
  {
    v14 = a1;
    a1 = (int16_t)a1;
    v5 = *(_WORD *)(dword_1927A8 + 2 * (int16_t)a1 + 53);
  }
  else
  {
    v5 = a1;
  }
  v6 = 28 * v5;
  LOWORD(a1) = *(int16_t *)((char *)word_17F817 + v6);
  v15 = a1;
  LOWORD(v6) = *(int16_t *)((char *)word_17F819 + v6);
  *a2 = 0;
  v13[0] = 0;
  if ( v5 == 13
    || v5 == 28
    || v5 == 32
    || v5 == 33
    || v5 == 34
    || v5 == 26
    || v5 == 25
    || v5 == 31
    || v5 == 30
    || v5 == 29
    || v5 == 36
    || v5 == 35
    || v5 == 37
    || v5 == 39 )
  {
    strcpy(v13, sub_7A990(0x65u));
  }
  if ( v16 )
  {
    v7 = dword_1927A8 + 2 * (int16_t)v14;
    if ( (*(_BYTE *)(v7 + 94) & 0x40) == 0 )
    {
      if ( (*(_BYTE *)(v7 + 93) & 4) != 0 )
      {
        v15 = (50 * (int16_t)v15 + 50) / 100;
        v8 = 50 * (int16_t)v6 / 100;
        LOWORD(v6) = v15;
        if ( (int16_t)v15 < v8 )
          LOWORD(v6) = v8;
        goto LABEL_37;
      }
      if ( (*(_BYTE *)(v7 + 93) & 2) == 0 )
        goto LABEL_37;
    }
LABEL_36:
    v15 = 150 * (int16_t)v15 / 100;
    v6 = 150 * (int16_t)v6 / 100;
    goto LABEL_37;
  }
  if ( a3 != a4 )
    goto LABEL_37;
  if ( word_1991D2 > 0 )
    goto LABEL_36;
  if ( word_1991BA <= 0 )
  {
    if ( word_1991B8 <= 0 )
      goto LABEL_37;
    goto LABEL_36;
  }
  v15 = (50 * (int16_t)v15 + 50) / 100;
  v9 = 50 * (int16_t)v6 / 100;
  LOWORD(v6) = v15;
  if ( (int16_t)v15 < v9 )
    LOWORD(v6) = v9;
LABEL_37:
  if ( v5 )
  {
    if ( v13[0] )
    {
      strcpy(a2, v13);
    }
    else if ( (_WORD)v6 == (_WORD)v15 )
    {
      return sprintf(a2, "%d", (int16_t)v6);
    }
    else
    {
      return sprintf(a2, "%d-%d", (int16_t)v15, (int16_t)v6);
    }
  }
  else
  {
    result = word_1791FF;
    *(_WORD *)a2 = word_1791FF;
  }
  return result;
}
// 6C557: conditional instruction was optimized away because bx.2 is in (<Du|E..18|==1B|==26|>=28u)
// 6C55D: conditional instruction was optimized away because bx.2 is in (<Du|E..18|==1B|==26|>=28u)
// 6C571: conditional instruction was optimized away because bx.2 is in (<Du|E..18|==1B|==26|>=28u)
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1791FF: using guessed type int16_t word_1791FF;
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 1927A8: using guessed type int dword_1927A8;
// 1991B8: using guessed type int16_t word_1991B8;
// 1991BA: using guessed type int16_t word_1991BA;
// 1991D2: using guessed type int16_t word_1991D2;
// 19999C: using guessed type int16_t word_19999C;


//----- (0006C6CD) --------------------------------------------------------
int sub_6C6CD()
{
  sub_12A478(0, 0, dword_1927F4);
  sub_6C704();
  sub_6D29C();
  sub_6AB9A();
  return sub_24677(8, -1, 1);
}
// 1927F4: using guessed type int dword_1927F4;


//----- (0006C704) --------------------------------------------------------
void sub_6C704()
{
  int16_t i; // cx
  int16_t v1; // si
  int16_t j; // si
  int16_t v3; // [esp+0h] [ebp-20h] BYREF
  int16_t v4; // [esp+4h] [ebp-1Ch] BYREF
  int16_t v5; // [esp+8h] [ebp-18h] BYREF
  int16_t v6; // [esp+Ch] [ebp-14h] BYREF
  int16_t v7; // [esp+10h] [ebp-10h] BYREF
  int16_t v8; // [esp+14h] [ebp-Ch] BYREF
  int16_t v9; // [esp+18h] [ebp-8h] BYREF
  int16_t v10; // [esp+1Ch] [ebp-4h] BYREF

  for ( i = 0; i < 8; ++i )
  {
    v1 = i + (uint8_t)byte_199EF5;
    if ( word_18B200[i] == -1000 && *(int16_t *)(dword_1927A8 + 2 * v1 + 53) > 0 )
      sub_12A478(55, 13 * i + 169, dword_19B99C);
    if ( word_18B1E0[i] == -1000 && *(int16_t *)(dword_1927A8 + 2 * v1 + 53) > 0 )
      sub_12A478(19, 13 * i + 169, dword_19B9A8);
  }
  if ( word_19984E == -1000 )
    sub_12A478(544, 439, dword_19B9A0);
  for ( j = 0; ; ++j )
  {
    if ( j >= 6 )
      goto LABEL_19;
    if ( byte_199EF1 )
    {
      if ( j == *(_WORD *)(dword_1927A8 + 229) )
      {
        sub_6C8F9(j, &v4, &v3, &v9, &v10);
        sub_12B726(dword_18B230[j]);
        sub_12A478(v4, v3, dword_18B230[j]);
LABEL_19:
        JUMPOUT(0x6A3DE);
      }
    }
    else if ( byte_19B9AC[j] != 1 )
    {
      sub_6C8F9(j, &v7, &v6, &v8, &v5);
      sub_12B726(dword_18B230[j]);
      sub_12A478(v7, v6, dword_18B230[j]);
    }
  }
}
// 6C81C: control flows out of bounds to 6A3DE
// 18B1E0: using guessed type int16_t word_18B1E0[];
// 18B200: using guessed type int16_t word_18B200[];
// 18B230: using guessed type int dword_18B230[6];
// 1927A8: using guessed type int dword_1927A8;
// 19984E: using guessed type int16_t word_19984E;
// 199EF1: using guessed type char byte_199EF1;
// 199EF5: using guessed type char byte_199EF5;
// 19B99C: using guessed type int dword_19B99C;
// 19B9A0: using guessed type int dword_19B9A0;
// 19B9A8: using guessed type int dword_19B9A8;


//----- (0006C897) --------------------------------------------------------
char sub_6C897(int a1, int a2, int a3, char *a4)
{
  int v4; // edx
  char *v5; // esi
  char result; // al

  v4 = 48 * a1 + 8 * a2;
  sub_1112EC(dword_192EE8, v4);
  v5 = (char *)sub_126C37((int)aShipnameLbx, 0, dword_192EE8, (int16_t)(a3 + v4), 1u, 16);
  sub_1113CC(dword_192EE8, 0);
  strcpy(a4, v5);
  return result;
}
// 192EE8: using guessed type int dword_192EE8;


//----- (0006C8F9) --------------------------------------------------------
int16_t sub_6C8F9( int a1, _WORD *a2, _WORD *a3, int16_t *a4, int16_t *a5)
{
  int16_t result; // ax

  result = (int16_t)a5;
  switch ( a1 )
  {
    case 0:
      *a3 = 54;
      *a5 = 69;
      break;
    case 1:
      *a3 = 70;
      *a5 = 84;
      break;
    case 2:
      *a3 = 85;
      *a5 = 102;
      break;
    case 3:
      *a3 = 103;
      *a5 = 117;
      break;
    case 4:
      *a3 = 118;
      *a5 = 132;
      break;
    case 5:
      *a3 = 133;
      *a5 = 149;
      break;
    default:
      break;
  }
  if ( a1 <= -1 || a1 >= 6 )
  {
    *a5 = 0;
    result = *a5;
    *a4 = *a5;
    *a3 = result;
    *a2 = result;
  }
  else
  {
    *a2 = 118;
    *a4 = 227;
  }
  return result;
}


//----- (0006C98D) --------------------------------------------------------
void sub_6C98D(int a1, int a2, int a3, int16_t *a4)
{
  int16_t v4; // cx
  int v5; // esi
  _DWORD *v6; // eax
  int v7; // ebx
  int v8; // edi
  _DWORD *v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // esi
  _DWORD *v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // ebx
  int v17; // edx
  _DWORD *v18; // eax
  int16_t v19; // cx
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // eax
  _DWORD *v23; // eax
  _DWORD *v24; // eax
  _DWORD *v25; // eax
  _DWORD *v26; // eax
  _DWORD *v27; // eax
  _DWORD *v28; // eax
  _DWORD *v29; // eax
  _DWORD *v30; // eax
  _DWORD *v31; // eax
  _DWORD *v32; // eax
  _DWORD *v33; // eax
  int v34; // ebx
  int v35; // edx
  _DWORD *v36; // eax
  _DWORD *v37; // eax
  _DWORD *v38; // eax
  _DWORD *v39; // eax
  int v40; // ebx
  int v41; // edx
  _DWORD *v42; // eax
  int v43; // esi
  _DWORD *v44; // eax
  int16_t v45; // cx
  _DWORD *v46; // eax
  int v47; // edx
  int v48; // eax
  int v49; // esi
  int v50; // ebx
  _DWORD *v51; // eax
  int v52; // edx
  int v53; // eax
  int v54; // esi
  _DWORD *v55; // eax
  int v56; // edx
  int v57; // eax
  _DWORD *v58; // eax
  int16_t v59; // cx
  _DWORD *v60; // eax
  _DWORD *v61; // eax
  _DWORD *v62; // eax
  _DWORD *v63; // eax
  _DWORD *v64; // eax
  _DWORD *v65; // eax
  _DWORD *v66; // eax
  _DWORD *v67; // eax
  _DWORD *v68; // eax
  _DWORD *v69; // eax
  _DWORD *v70; // eax
  _DWORD *v71; // eax
  _DWORD *v72; // eax
  _DWORD *v73; // eax
  _DWORD *v74; // eax
  _DWORD *v75; // eax
  _DWORD *v76; // eax
  int v77; // ebx
  int v78; // edx
  _DWORD *v79; // eax
  _DWORD *v80; // eax
  _DWORD *v81; // eax
  _DWORD *v82; // eax
  int16_t v83; // si
  int16_t *v84; // edi
  int v85; // ebx
  _DWORD *v86; // eax
  int16_t i; // si
  int16_t *v88; // edi
  int v89; // ebx
  _DWORD *v90; // eax
  char v91[20]; // [esp+0h] [ebp-14h] BYREF

  sub_FE8BE(a1, a2, a3, a4);
  dword_1927F4 = (int)sub_126AFD((int)off_18175C, 0, dword_192ED4);
  dword_192810 = (int)sub_126B42((int)off_18175C, 1, dword_192ED4);
  dword_1927D0 = (int)sub_126B42((int)off_18175C, 2, dword_192ED4);
  v4 = 6;
  dword_1927E8 = (int)sub_126B42((int)off_18175C, 3, dword_192ED4);
  v5 = 0;
  v6 = sub_126B42((int)off_18175C, 4, dword_192ED4);
  v7 = dword_192ED4;
  dword_1927F0 = (int)v6;
  v8 = 6;
  dword_1927E4 = (int)sub_126B42((int)off_18175C, 5, dword_192ED4);
  sub_FE8BE(dword_1927E4, 5, v7, (int16_t *)6);
  do
  {
    v9 = sub_126B42((int)off_18175C, (int16_t)v8++, dword_192ED4);
    v10 = (int)v9;
    v11 = (int16_t)v5++;
    dword_18B248[v11] = v10;
  }
  while ( (int16_t)v5 < 6 );
  v12 = 0;
  do
  {
    v13 = sub_126B42((int)off_18175C, v4++, dword_192ED4);
    v14 = (int)v13;
    v15 = (int16_t)v12++;
    dword_18B230[v15] = v14;
  }
  while ( (int16_t)v12 < 6 );
  v16 = dword_192ED4;
  v17 = v4;
  v18 = sub_126B42((int)off_18175C, v4, dword_192ED4);
  v19 = v4 + 1;
  dword_19B9A0 = (int)v18;
  sub_FE8BE((int)v18, v17, v16, (int16_t *)v8);
  v20 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_1927F8 = (int)v20;
  v21 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_1927EC = (int)v21;
  v22 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_192800 = (int)v22;
  v23 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_192760 = (int)v23;
  v24 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_19B9A8 = (int)v24;
  v25 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_19B99C = (int)v25;
  v26 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_192784 = (int)v26;
  v27 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_1927A4 = (int)v27;
  v28 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_1927A0 = (int)v28;
  v29 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_1927D4 = (int)v29;
  v30 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_192808 = (int)v30;
  v31 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_1927CC = (int)v31;
  v32 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_1927DC = (int)v32;
  v33 = sub_126B42((int)off_18175C, v19, dword_192ED4);
  v34 = dword_192ED4;
  ++v19;
  dword_192804 = (int)v33;
  v35 = v19;
  v36 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_1927D8 = (int)v36;
  sub_FE8BE((int)v36, v35, v34, (int16_t *)v8);
  v37 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_1927C4 = (int)v37;
  v38 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_19280C = (int)v38;
  v39 = sub_126B42((int)off_18175C, v19, dword_192ED4);
  v40 = dword_192ED4;
  ++v19;
  dword_1927C8 = (int)v39;
  v41 = v19;
  v42 = sub_126B42((int)off_18175C, v19++, dword_192ED4);
  dword_1927FC = (int)v42;
  sub_FE8BE((int)v42, v41, v40, (int16_t *)v8);
  v43 = 0;
  v44 = sub_126B42((int)off_18175C, v19, dword_192ED4);
  v45 = v19 + 1;
  dword_1927E0 = (int)v44;
  do
  {
    v46 = sub_126B42((int)off_18175C, v45++, dword_192ED4);
    v47 = (int)v46;
    v48 = (int16_t)v43++;
    dword_19278C[v48] = v47;
  }
  while ( (int16_t)v43 < 5 );
  v49 = 0;
  do
  {
    v50 = dword_192ED4;
    v51 = sub_126B42((int)off_18175C, v45++, dword_192ED4);
    v52 = (int)v51;
    v53 = (int16_t)v49++;
    dword_1927B0[v53] = v52;
  }
  while ( (int16_t)v49 < 5 );
  sub_FE8BE(v53, v52, v50, (int16_t *)v8);
  v54 = 0;
  do
  {
    v55 = sub_126B42((int)off_18175C, v45++, dword_192ED4);
    v56 = (int)v55;
    v57 = (int16_t)v54++;
    dword_192764[v57] = v56;
  }
  while ( (int16_t)v54 < 5 );
  v58 = sub_126B42((int)off_18175C, v45, dword_192ED4);
  v59 = v45 + 1;
  dword_192778 = (int)v58;
  v60 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B260[0] = (int)v60;
  v61 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B264 = (int)v61;
  v62 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B268 = (int)v62;
  v63 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B26C = (int)v63;
  v64 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B270 = (int)v64;
  v65 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B274 = (int)v65;
  v66 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B278 = (int)v66;
  v67 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B27C = (int)v67;
  v68 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B280 = (int)v68;
  v69 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B284 = (int)v69;
  v70 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B288 = (int)v70;
  v71 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B28C = (int)v71;
  v72 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B290 = (int)v72;
  v73 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B294 = (int)v73;
  v74 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B298 = (int)v74;
  v75 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B29C = (int)v75;
  v76 = sub_126B42((int)off_18175C, v59, dword_192ED4);
  v77 = dword_192ED4;
  ++v59;
  dword_18B2A0 = (int)v76;
  v78 = v59;
  v79 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_18B2A4 = (int)v79;
  sub_FE8BE((int)v79, v78, v77, (int16_t *)v8);
  v80 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_192698 = (int)v80;
  v81 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_19275C = (int)v81;
  v82 = sub_126B42((int)off_18175C, v59++, dword_192ED4);
  dword_192780 = (int)v82;
  dword_19277C = (int)sub_126B42((int)off_18175C, v59, dword_192ED4);
  dword_192788 = (int)sub_126B42((int)off_18175C, (int16_t)(v59 + 1), dword_192ED4);
  sub_111499(dword_192ED4);
  dword_1927A8 = (int)sub_110CEE(dword_192EE8, 293);
  dword_192694 = (int)sub_110D3C(dword_192EE8, 240);
  v83 = 0;
  sub_6F23C(v91);
  do
  {
    v84 = (int16_t *)v83;
    v85 = dword_192EE8;
    v86 = sub_126C37((int)v91, 1, dword_192EE8, v83++, 1u, 100);
    dword_19269C[(_DWORD)v84] = (int)v86;
    sub_FE8BE((int)v86, 1, v85, v84);
  }
  while ( v83 < 39 );
  for ( i = 0; i < 40; ++i )
  {
    v88 = (int16_t *)i;
    v89 = dword_192EE8;
    v90 = sub_126C37((int)v91, 3, dword_192EE8, i, 1u, 100);
    dword_18B130[(_DWORD)v88] = (int)v90;
    sub_FE8BE((int)v90, 3, v89, v88);
  }
  JUMPOUT(0x6A3DE);
}
// 6D026: control flows out of bounds to 6A3DE
// 18175C: using guessed type char *off_18175C;
// 18B130: using guessed type int dword_18B130[40];
// 18B230: using guessed type int dword_18B230[6];
// 18B248: using guessed type int dword_18B248[];
// 18B260: using guessed type int dword_18B260[];
// 18B264: using guessed type int dword_18B264;
// 18B268: using guessed type int dword_18B268;
// 18B26C: using guessed type int dword_18B26C;
// 18B270: using guessed type int dword_18B270;
// 18B274: using guessed type int dword_18B274;
// 18B278: using guessed type int dword_18B278;
// 18B27C: using guessed type int dword_18B27C;
// 18B280: using guessed type int dword_18B280;
// 18B284: using guessed type int dword_18B284;
// 18B288: using guessed type int dword_18B288;
// 18B28C: using guessed type int dword_18B28C;
// 18B290: using guessed type int dword_18B290;
// 18B294: using guessed type int dword_18B294;
// 18B298: using guessed type int dword_18B298;
// 18B29C: using guessed type int dword_18B29C;
// 18B2A0: using guessed type int dword_18B2A0;
// 18B2A4: using guessed type int dword_18B2A4;
// 192694: using guessed type int dword_192694;
// 192698: using guessed type int dword_192698;
// 19269C: using guessed type int dword_19269C[39];
// 19275C: using guessed type int dword_19275C;
// 192760: using guessed type int dword_192760;
// 192764: using guessed type int dword_192764[5];
// 192778: using guessed type int dword_192778;
// 19277C: using guessed type int dword_19277C;
// 192780: using guessed type int dword_192780;
// 192784: using guessed type int dword_192784;
// 192788: using guessed type int dword_192788;
// 19278C: using guessed type int dword_19278C[4];
// 1927A0: using guessed type int dword_1927A0;
// 1927A4: using guessed type int dword_1927A4;
// 1927A8: using guessed type int dword_1927A8;
// 1927B0: using guessed type int dword_1927B0[5];
// 1927C4: using guessed type int dword_1927C4;
// 1927C8: using guessed type int dword_1927C8;
// 1927CC: using guessed type int dword_1927CC;
// 1927D0: using guessed type int dword_1927D0;
// 1927D4: using guessed type int dword_1927D4;
// 1927D8: using guessed type int dword_1927D8;
// 1927DC: using guessed type int dword_1927DC;
// 1927E0: using guessed type int dword_1927E0;
// 1927E4: using guessed type int dword_1927E4;
// 1927E8: using guessed type int dword_1927E8;
// 1927EC: using guessed type int dword_1927EC;
// 1927F0: using guessed type int dword_1927F0;
// 1927F4: using guessed type int dword_1927F4;
// 1927F8: using guessed type int dword_1927F8;
// 1927FC: using guessed type int dword_1927FC;
// 192800: using guessed type int dword_192800;
// 192804: using guessed type int dword_192804;
// 192808: using guessed type int dword_192808;
// 19280C: using guessed type int dword_19280C;
// 192810: using guessed type int dword_192810;
// 192ED4: using guessed type int dword_192ED4;
// 192EE8: using guessed type int dword_192EE8;
// 19B99C: using guessed type int dword_19B99C;
// 19B9A0: using guessed type int dword_19B9A0;
// 19B9A8: using guessed type int dword_19B9A8;


//----- (0006D048) --------------------------------------------------------
void sub_6D048( int a1, int a2)
{
  int v3; // edx
  int16_t v4; // bx
  int v5; // eax
  int16_t v6; // dx
  int v7; // ebx

  v3 = 23 * *(int16_t *)((char *)&word_17E07F + 13 * a2);
  v4 = 0;
  v5 = 0;
LABEL_2:
  v6 = *(int16_t *)((char *)&word_17D90C + v3);
  while ( 1 )
  {
    if ( v4 )
      JUMPOUT(0x6AB15);
    if ( v6 )
    {
      if ( v6 < 75 )
      {
        if ( *(_BYTE *)(v6 + 3753 * a1 + dword_197F98 + 196) == 3 )
        {
          v3 = 23 * v6;
          ++v5;
          goto LABEL_2;
        }
      }
      else
      {
        v7 = (int16_t)(v6 - 75);
        LOWORD(v7) = *(uint8_t *)(dword_197F98 + 3753 * a1 + v7 + 540);
        v5 += v7;
      }
    }
    v4 = 1;
  }
}
// 6D073: control flows out of bounds to 6AB15
// 17D90C: using guessed type int16_t word_17D90C;
// 17E07F: using guessed type int16_t word_17E07F;
// 197F98: using guessed type int dword_197F98;


//----- (0006D0DE) --------------------------------------------------------
int sub_6D0DE(int a1, int a2)
{
  int16_t v3; // ax
  int16_t v4; // ax

  v3 = sub_6D10F(a2);
  if ( v3 == 2 )
  {
    v4 = 50;
  }
  else if ( v3 <= 2 )
  {
    v4 = 0;
  }
  else
  {
    v4 = 100;
  }
  return a1 * v4 / 100;
}


//----- (0006D10F) --------------------------------------------------------
int sub_6D10F( int a1)
{
  int result; // eax

  result = (a1 & 1) != 0;
  if ( (a1 & 2) != 0 )
    ++result;
  if ( (a1 & 4) != 0 )
    ++result;
  if ( (a1 & 8) != 0 )
    ++result;
  return result;
}


//----- (0006D167) --------------------------------------------------------
void sub_6D167()
{
  char v0; // dl
  int16_t v1; // ax

  v0 = 0;
  v1 = 0;
  while ( 1 )
  {
    if ( *(int16_t *)(dword_1927A8 + 2 * v1 + 181) > 0 )
      ++v0;
    if ( ++v1 >= 8 )
      JUMPOUT(0x6D18B);
  }
}
// 6D189: control flows out of bounds to 6D18B
// 1927A8: using guessed type int dword_1927A8;


//----- (0006D191) --------------------------------------------------------
char sub_6D191()
{
  char v1; // dl
  int16_t i; // ax

  v1 = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( *(int16_t *)(dword_1927A8 + 2 * i + 53) > 0 )
      ++v1;
  }
  return v1;
}
// 1927A8: using guessed type int dword_1927A8;


//----- (0006D1B4) --------------------------------------------------------
int sub_6D1B4( int a1, int a2, unsigned int a3, int a4)
{
  int v6; // ecx
  int16_t v7; // ax
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int16_t v11; // ax
  int16_t v12; // si
  int16_t v14; // [esp+0h] [ebp-10h] BYREF
  int16_t v15; // [esp+4h] [ebp-Ch] BYREF
  int16_t v16; // [esp+8h] [ebp-8h]
  int16_t v17; // [esp+Ch] [ebp-4h] BYREF

  v16 = a2;
  v6 = 14 * a1;
  v7 = 0;
  v8 = word_17F811[v6];
  if ( a3 < 0xAu )
  {
    if ( a3 >= 2u )
    {
      if ( a3 <= 2u )
      {
        v7 = 10;
      }
      else if ( a3 == 5 )
      {
        v7 = 20;
      }
    }
  }
  else if ( a3 <= 0xAu )
  {
    v7 = 30;
  }
  else if ( a3 >= 0xFu )
  {
    if ( a3 <= 0xFu )
    {
      v7 = 35;
    }
    else if ( a3 == 20 )
    {
      v7 = 40;
    }
  }
  v9 = v7 + v8;
  sub_6A636(a4, &v17, &v15);
  v10 = v9 * v15 / 100;
  v11 = (uint8_t)byte_17F80F[28 * a1];
  if ( byte_17F80F[28 * a1] )
  {
    v12 = 0;
  }
  else
  {
    if ( (v16 & 2) != 0 || (v16 & 4) != 0 )
    {
      v11 = 25;
    }
    else if ( (v16 & 0x10) != 0 )
    {
      v11 = 50;
    }
    v12 = v11;
  }
  sub_6A406(a4, &v17, &v14);
  return v10 * (v14 + v12 + 100) / 100;
}
// 17F811: using guessed type int16_t word_17F811[];


//----- (0006D29C) --------------------------------------------------------
void sub_6D29C()
{
  int v0; // ebx
  int v1; // eax
  char *v2; // eax
  char *v3; // eax
  int16_t v4; // bx
  char v5; // al
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // ebx
  int v11; // eax
  char *v12; // eax
  int16_t v13; // bx
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  char *v19; // eax
  int64_t v20; // rax
  int v21; // eax
  int v22; // esi
  int v23; // ecx
  int v24; // esi
  char *v25; // esi
  int v26; // edx
  char *v27; // ebx
  int16_t v28; // dx
  int v29; // edi
  int16_t v30; // si
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int64_t v35; // rax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int16_t v40; // cx
  uint16_t v41; // ax
  char *v42; // esi
  char *v43; // eax
  char *v44; // eax
  char *v45; // eax
  int16_t v46; // si
  int16_t v47; // bx
  int v48; // edi
  int16_t v49; // cx
  int v50; // ebx
  char v51; // al
  uint16_t v52; // ax
  char *v53; // esi
  char *v54; // eax
  int16_t *v55; // eax
  char *v56; // eax
  int v57; // edx
  char *v58; // eax
  int16_t v59; // ax
  char *v60; // eax
  int v61[27]; // [esp-70h] [ebp-1CAh] BYREF
  char *v62; // [esp-4h] [ebp-15Eh]
  char v63[120]; // [esp+0h] [ebp-15Ah] BYREF
  _BYTE v64[100]; // [esp+78h] [ebp-E2h] BYREF
  char v65[80]; // [esp+DCh] [ebp-7Eh] BYREF
  char v66[56]; // [esp+12Ch] [ebp-2Eh] BYREF
  _BYTE v67[8]; // [esp+164h] [ebp+Ah] BYREF
  _BYTE v68[8]; // [esp+16Ch] [ebp+12h] BYREF
  char v69[16]; // [esp+174h] [ebp+1Ah] BYREF
  char v70[8]; // [esp+184h] [ebp+2Ah] BYREF
  char v71[8]; // [esp+18Ch] [ebp+32h] BYREF
  _BYTE v72[12]; // [esp+194h] [ebp+3Ah] BYREF
  _BYTE v73[8]; // [esp+1A0h] [ebp+46h] BYREF
  _BYTE v74[8]; // [esp+1A8h] [ebp+4Eh] BYREF
  int16_t v75; // [esp+1B0h] [ebp+56h] BYREF
  int v76; // [esp+1B4h] [ebp+5Ah]
  int v77; // [esp+1B8h] [ebp+5Eh]
  int16_t v78; // [esp+1BCh] [ebp+62h] BYREF
  int v79; // [esp+1C0h] [ebp+66h]
  int16_t v80; // [esp+1C4h] [ebp+6Ah] BYREF
  int v81; // [esp+1C8h] [ebp+6Eh]
  int v82; // [esp+1CCh] [ebp+72h]
  int v83; // [esp+1D0h] [ebp+76h]
  int v84; // [esp+1D4h] [ebp+7Ah]
  int v85; // [esp+1D8h] [ebp+7Eh]
  char v86; // [esp+1DCh] [ebp+82h]
  char v87; // [esp+1E0h] [ebp+86h]

  sub_6A6A1((int)v64);
  qmemcpy(v61, v64, 0x63u);
  sub_54D80(
    v61[0],
    v61[1],
    v61[2],
    v61[3],
    v61[4],
    v61[5],
    v61[6],
    v61[7],
    v61[8],
    v61[9],
    v61[10],
    v61[11],
    v61[12],
    v61[13],
    v61[14],
    v61[15],
    v61[16],
    v61[17],
    v61[18],
    v61[19],
    v61[20],
    v61[21],
    v61[22],
    v61[23],
    v61[24],
    &v75,
    &v78,
    &v80);
  sub_128BE7();
  sub_12B65C();
  sub_120DED(0, 0);
  sub_8F6F8(3u, 85, 91, v71);
  sub_8F6F8(2u, 85, 91, v70);
  qmemcpy(v67, v70, sizeof(v67));
  v0 = 1;
  v62 = v68;
  qmemcpy(v68, v71, sizeof(v68));
  do
  {
    v1 = (int16_t)v0;
    v68[(int16_t)v0++] += 2;
    v67[v1] += 2;
  }
  while ( (int16_t)v0 < 8 );
  sub_120BB5(3, (int)v71);
  sub_120E8C(1);
  sub_1212B3(236, 56, *(int *)((char *)&off_17FE70 + 46 * *(int16_t *)(dword_1927A8 + 27)));
  sub_120BB5(2, (int)v70);
  sub_120E8C(1);
  v62 = (char *)word_17FE9C[23 * *(int16_t *)(dword_1927A8 + 27)];
  v2 = sub_7A990(0x17Eu);
  sprintf(v65, v2);
  sub_1212B3(251, 71, (int)v65);
  v62 = (char *)(uint8_t)sub_6B7CF(dword_1927A8, 71, (int)v65, 0);
  v3 = sub_7A990(0x54u);
  sprintf(v65, v3);
  sub_1212B3(251, 86, (int)v65);
  sub_120BB5(3, (int)v71);
  sub_120E8C(1);
  sub_1212B3(236, 107, *(int *)((char *)&off_17F638 + 15 * *(int16_t *)(dword_1927A8 + 49)));
  sub_120BB5(2, (int)v70);
  sub_120E8C(1);
  v4 = word_19999C;
  v5 = sub_6B7FF(dword_1927A8, 27);
  v62 = (char *)(int16_t)sub_58330(*(_WORD *)(dword_1927A8 + 229), v5, v4);
  v6 = sub_7A990(0x55u);
  sprintf(v65, v6);
  sub_1212B3(251, 122, (int)v65);
  v62 = (char *)(int16_t)sub_6B77B();
  v7 = sub_7A990(0x56u);
  sprintf(v65, v7);
  sub_1212B3(251, 137, (int)v65);
  sub_120BB5(3, (int)v71);
  sub_120E8C(1);
  if ( word_1999BC == word_19B9B4 )
    sub_6E240(3, 1);
  if ( *(_WORD *)(dword_1927A8 + 17) )
  {
    strcpy(v65, *(char **)((char *)&off_17F6A1 + 59 * *(int16_t *)(dword_1927A8 + 17)));
    sub_1212B3(437, 56, (int)v65);
    sub_12066F((int)v65);
    sub_120BB5(2, (int)v70);
    LOWORD(v11) = sub_120E8C(1);
    v62 = (char *)(int16_t)sub_6E3D3(v11, (int)v70, (int)v65);
    v12 = sub_7A990(0x59u);
    sprintf(v65, v12);
    sub_1212B3(453, 71, (int)v65);
    v13 = *(int16_t *)((char *)&word_17F6C1 + 59 * *(int16_t *)(dword_1927A8 + 17));
    if ( (uint8_t)sub_6B7FF(dword_1927A8, 13) )
      v13 += 3;
    if ( v13 == 1 )
      v14 = &byte_1791EB;
    else
      v14 = aS_1;
    v62 = v14;
    v61[26] = v13;
    v15 = sub_7A990(0x5Au);
    v10 = v65;
    sprintf(v65, v15);
  }
  else
  {
    v8 = sub_7A990(0x36u);
    sub_1212B3(437, 56, (int)v8);
    sub_120BB5(2, (int)v70);
    sub_120E8C(1);
    v9 = sub_7A990(0x57u);
    sub_1212B3(453, 71, (int)v9);
    v10 = sub_7A990(0x58u);
  }
  sub_1212B3(453, 85, (int)v10);
  sub_120BB5(3, (int)v71);
  sub_120E8C(1);
  if ( word_1999BC == word_19B9B2 )
    sub_6E240(3, 1);
  sub_1212B3(437, 97, *(int *)((char *)&off_17FDEC + 22 * *(int16_t *)(dword_1927A8 + 43)));
  sub_120BB5(2, (int)v70);
  sub_120E8C(1);
  v62 = (char *)word_17FE00[11 * *(int16_t *)(dword_1927A8 + 43)];
  v16 = sub_7A990(0x5Bu);
  sprintf(v65, v16);
  sub_1212B3(453, 112, (int)v65);
  sub_120BB5(3, (int)v71);
  sub_120E8C(1);
  v17 = sub_7A990(0x5Cu);
  sub_1212B3(437, 125, (int)v17);
  v62 = (char *)v78;
  if ( v78 >= 0 )
    v18 = asc_17921B;
  else
    v18 = asc_179219;
  sprintf(v65, "%s%d", v18, v62);
  sub_1210B7(618, 125, (int)v65);
  v19 = sub_7A990(0x5Du);
  sub_1212B3(437, 137, (int)v19);
  v20 = sprintf(v65, "%d%%", v80);
  sub_1210B7(618, SWORD2(v20), (int)v65);
  sub_120E8C(2);
  sub_128AB6(16, 155, 626, 284);
  sub_12B634();
  v77 = 19;
  sub_120BB5(3, (int)v71);
  LODWORD(v20) = sub_7A990(0x5Eu);
  v82 = 13;
  sub_1212B3(83, 156, v20);
  LODWORD(v20) = sub_7A990(0x5Fu);
  sub_1212B3(249, 156, v20);
  LODWORD(v20) = sub_7A990(0x60u);
  sub_1212B3(316, 156, v20);
  LODWORD(v20) = sub_7A990(0x30u);
  sub_1212B3(414, 156, v20);
  LODWORD(v20) = sub_7A990(0x185u);
  v81 = 170;
  sub_1212B3(359, 156, v20);
  LODWORD(v20) = sub_7A990(0x61u);
  v87 = 0;
  sub_1212B3(479, 156, v20);
  v79 = 0;
  v21 = sub_120BB5(2, (int)v70);
  while ( 1 )
  {
    LOWORD(v21) = (uint8_t)byte_199EF5;
    v84 = v21 + v79;
    if ( word_1999BC == (int16_t)v79 + 1000 && *(int16_t *)(dword_1927A8 + 2 * (int16_t)v84 + 53) > 0 )
    {
      sub_6E240(2, 2);
    }
    else if ( word_1999BC == (int16_t)v79 + 1000
           && (v21 = (int16_t)v84, *(int16_t *)(dword_1927A8 + 2 * (int16_t)v84 + 53) <= 0) )
    {
      v87 = 1;
    }
    else
    {
      v21 = sub_120BB5(2, (int)v70);
    }
    v22 = 2 * (int16_t)v84;
    if ( *(int16_t *)(dword_1927A8 + v22 + 53) > 0 )
    {
      v23 = (int16_t)v79;
      sub_6F07F(*(_WORD *)(dword_1927A8 + 2 * (int16_t)v79 + 93), v66);
      sub_6EFF8(*(_BYTE *)(v23 + dword_1927A8 + 85), v72);
      v24 = dword_1927A8 + v22;
      if ( *(int16_t *)(v24 + 69) <= 1 )
        v25 = (char *)*(&off_17F803 + 7 * *(int16_t *)(v24 + 53));
      else
        v25 = (char *)*(&off_17F807 + 7 * *(int16_t *)(v24 + 53));
      v62 = v63;
      strcpy(v63, v25);
      v26 = (int16_t)v84;
      if ( sub_6EFEB(*(_WORD *)(dword_1927A8 + 2 * (int16_t)v84 + 53)) == 1 )
      {
        v27 = v65;
        sprintf(v65, "%s (%d)", v63, *(uint8_t *)(v26 + dword_1927A8 + 173));
        v28 = v81;
      }
      else
      {
        v28 = v81;
        v27 = v63;
      }
      sub_1212B3(85, v28, (int)v27);
      v29 = (int16_t)v84;
      v30 = v81;
      sub_121153(49, (int16_t)v81, *(int16_t *)(dword_1927A8 + 2 * (int16_t)v84 + 69), -1);
      sub_6C47E(v29, v65, -1, -1);
      if ( !strcmp(v65, aSpecial) )
      {
        sub_8EBBB(1);
        sub_1210FD(267, v30, (int)v65);
        sub_8EBBB(2);
      }
      else
      {
        sub_1210FD(267, v30, (int)v65);
      }
      sub_1210FD(329, v81, (int)v72);
      v31 = dword_1927A8 + 2 * (int16_t)v84;
      if ( *(_WORD *)(v31 + 69) )
        v32 = *(_DWORD *)(dword_1927A8 + 4 * (int16_t)v84 + 141) / *(int16_t *)(v31 + 69);
      else
        v32 = 0;
      if ( v32 <= 1 )
      {
        v34 = 1;
      }
      else
      {
        v33 = dword_1927A8 + 2 * (int16_t)v84;
        if ( *(_WORD *)(v33 + 69) )
          v34 = *(_DWORD *)(dword_1927A8 + 4 * (int16_t)v84 + 141) / *(int16_t *)(v33 + 69);
        else
          v34 = 0;
      }
      v35 = sprintf(v65, "%d", v34);
      sub_1210FD(436, SWORD2(v35), (int)v65);
      v36 = dword_1927A8 + 2 * (int16_t)v84;
      if ( *(_WORD *)(v36 + 69) )
        v37 = *(_DWORD *)(dword_1927A8 + 4 * (int16_t)v84 + 109) / *(int16_t *)(v36 + 69);
      else
        v37 = 0;
      if ( v37 <= 1 )
      {
        v39 = 1;
      }
      else
      {
        v38 = dword_1927A8 + 2 * (int16_t)v84;
        if ( *(_WORD *)(v38 + 69) )
          v39 = *(_DWORD *)(dword_1927A8 + 4 * (int16_t)v84 + 109) / *(int16_t *)(v38 + 69);
        else
          v39 = 0;
      }
      v40 = v81;
      sprintf(v65, "%d", v39);
      sub_1210FD(377, v40, (int)v65);
      v81 += 13;
      v21 = sub_1210FD(529, v40, (int)v66);
    }
    if ( (int16_t)++v79 >= 8 )
    {
      if ( v87 && 8 - (uint8_t)byte_199EED > 0 )
      {
        if ( 8 - (uint8_t)byte_199EED > 1 )
          v81 = (127 - (int16_t)v82 * (uint8_t)byte_199EED) / 2 - 14 + (int16_t)v81;
        if ( sub_6E571() )
        {
          sub_120BB5(2, (int)v70);
          sub_6E240(2, 2);
          v41 = 383;
        }
        else
        {
          v42 = sub_8E5C5(2u, 73, 77);
          v62 = v73;
          qmemcpy(v73, v42, sizeof(v73));
          sub_120BB5(2, (int)v73);
          sub_6E240(2, 2);
          if ( dword_19B9A4 > 0 )
            v41 = 24;
          else
            v41 = 26;
        }
        v43 = sub_7A990(v41);
        sub_1210FD((640 - (int16_t)v77) / 2, v81, (int)v43);
      }
      sub_12B65C();
      v76 = 20;
      sub_128AB6(17, 305, 626, 432);
      sub_12B634();
      v85 = 13;
      sub_120BB5(3, (int)v71);
      v44 = sub_7A990(0x62u);
      v83 = 320;
      sub_1212B3(30, 306, (int)v44);
      v45 = sub_7A990(0x38u);
      v86 = 0;
      sub_1212B3(280, 306, (int)v45);
      v46 = 0;
      sub_120BB5(2, (int)v70);
      while ( 1 )
      {
        v47 = v46 + (uint8_t)byte_199EF4;
        if ( word_1999BC == v46 + 2000 && *(int16_t *)(dword_1927A8 + 2 * v47 + 181) > 0 )
        {
          sub_120BB5(2, (int)v70);
          sub_6E240(2, 2);
        }
        else if ( word_1999BC == v46 + 2000 && *(int16_t *)(dword_1927A8 + 2 * v47 + 181) <= 0 )
        {
          v86 = 1;
        }
        else
        {
          sub_120BB5(2, (int)v70);
        }
        v48 = 2 * v47;
        if ( *(int16_t *)(v48 + dword_1927A8 + 181) > 0 )
        {
          v49 = v83;
          sub_1212B3(35, v83, *(int *)((char *)&off_17EEE0 + 47 * *(int16_t *)(v48 + dword_1927A8 + 181)));
          v50 = dword_19269C[*(int16_t *)(v48 + dword_1927A8 + 181)];
          v83 += 13;
          sub_1212B3(270, v49, v50);
        }
        if ( ++v46 >= 8 )
        {
          if ( v86 && 8 - (uint8_t)byte_199EF3 > 0 )
          {
            if ( 8 - (uint8_t)byte_199EF3 > 1 )
              v83 = (125 - (uint8_t)byte_199EF3 * (int16_t)v85) / 2 - 14 + (int16_t)v83;
            sub_6E42E();
            if ( v51 )
            {
              sub_120BB5(2, (int)v70);
              sub_6E240(2, 2);
              v52 = 384;
            }
            else
            {
              v53 = sub_8E5C5(2u, 73, 78);
              v62 = v74;
              qmemcpy(v74, v53, sizeof(v74));
              sub_120BB5(2, (int)v74);
              sub_6E240(2, 2);
              if ( dword_19B9A4 > 0 )
                v52 = 25;
              else
                v52 = 27;
            }
            v54 = sub_7A990(v52);
            sub_1210FD((640 - (int16_t)v76) / 2, v83, (int)v54);
          }
          sub_12B65C();
          sub_128BE7();
          v55 = (int16_t *)sub_58697(word_19999C, *(_WORD *)(dword_1927A8 + 231));
          sub_12A478((54 - *v55) / 2 + 39, (58 - v55[1]) / 2 + 58, (int)v55);
          sub_120BB5(3, (int)v71);
          sub_122259();
          v56 = sub_7A990(0x30u);
          sub_1212B3(25, 129, (int)v56);
          sub_121153(106, 129, *(_DWORD *)(dword_1927A8 + 233), (int)v69);
          sub_8F6F8(4u, 85, 89, v69);
          sub_120BB5(4, (int)v69);
          v57 = (24 - sub_122259()) / 2 + 444;
          v58 = sub_7A990(0x185u);
          sub_1212B3(24, v57, (int)v58);
          v59 = sub_6B949();
          sub_121153(135, (int16_t)v57, v59, (int)v69);
          v60 = sub_7A990(0x63u);
          sub_1212B3(163, v57, (int)v60);
          sub_121153(352, (int16_t)v57, dword_19B9A4, (int)v69);
          JUMPOUT(0x6C081);
        }
      }
    }
  }
}
// 6E078: control flows out of bounds to 6C081
// 6D5D7: variable 'v11' is possibly undefined
// 6D8E0: variable 'v21' is possibly undefined
// 6DE9F: variable 'v51' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 138B90: using guessed type int strcmp(_DWORD, _DWORD);
// 1791EB: using guessed type char byte_1791EB;
// 17EEE0: using guessed type _UNKNOWN *off_17EEE0;
// 17F638: using guessed type _UNKNOWN *off_17F638;
// 17F6A1: using guessed type _UNKNOWN *off_17F6A1;
// 17F6C1: using guessed type int16_t word_17F6C1;
// 17F803: using guessed type _UNKNOWN *off_17F803;
// 17F807: using guessed type _UNKNOWN *off_17F807;
// 17FDEC: using guessed type _UNKNOWN *off_17FDEC;
// 17FE00: using guessed type int16_t word_17FE00[];
// 17FE70: using guessed type _UNKNOWN *off_17FE70;
// 17FE9C: using guessed type int16_t word_17FE9C[];
// 19269C: using guessed type int dword_19269C[39];
// 1927A8: using guessed type int dword_1927A8;
// 19999C: using guessed type int16_t word_19999C;
// 1999BC: using guessed type int16_t word_1999BC;
// 199EED: using guessed type char byte_199EED;
// 199EF3: using guessed type char byte_199EF3;
// 199EF4: using guessed type char byte_199EF4;
// 199EF5: using guessed type char byte_199EF5;
// 19B9A4: using guessed type int dword_19B9A4;
// 19B9B2: using guessed type int16_t word_19B9B2;
// 19B9B4: using guessed type int16_t word_19B9B4;


//----- (0006E091) --------------------------------------------------------
int16_t sub_6E091( int a1)
{
  int16_t v1; // bx
  int16_t v2; // dx
  char v3; // cl
  int16_t v4; // ax
  int16_t *v5; // eax
  int16_t result; // ax
  char *v7; // eax
  char v8[200]; // [esp+0h] [ebp-AEh] BYREF
  _BYTE v9[100]; // [esp+C8h] [ebp+1Ah] BYREF
  _BYTE v10[80]; // [esp+12Ch] [ebp+7Eh] BYREF

  v1 = -1;
  v2 = (uint8_t)byte_19B9AC[a1];
  v3 = 0;
  v10[0] = 0;
  switch ( v2 )
  {
    case 241:
      v1 = a1 - 3;
      break;
    case 242:
      v1 = a1 + 1;
      break;
    case 243:
      v1 = a1 + 7;
      break;
    case 244:
      v1 = 13;
      break;
    case 245:
      v1 = 14;
      if ( word_199A10 == 25 )
      {
        v4 = sub_79C54(word_199830, word_199832);
        v5 = sub_77B28(*(_WORD *)(dword_192B18 + 361 * *(int16_t *)(17 * v4 + dword_1930D4) + 2));
        v3 = 1;
        sprintf(v10, (char *)v5);
      }
      break;
    default:
      break;
  }
  result = v1;
  if ( v1 > -1 )
  {
    sub_8F6DF(v1, v8);
    if ( v3 == 1 )
    {
      sprintf(v9, v8, v10, *(&off_18003A + 9 * *(int16_t *)(dword_1927A8 + 229)));
      v7 = v9;
    }
    else
    {
      v7 = v8;
    }
    return sub_77423((int)v7);
  }
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 18003A: using guessed type _UNKNOWN *off_18003A;
// 1927A8: using guessed type int dword_1927A8;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 199A10: using guessed type int16_t word_199A10;


//----- (0006E1A0) --------------------------------------------------------
int sub_6E1A0( int a1, int *a2)
{
  int result; // eax
  int v3; // eax

  result = dword_197F98 + 3753 * a1;
  if ( *(_BYTE *)(result + 2207) )
  {
    if ( *(_BYTE *)(result + 2207) != 1 )
      return result;
    v3 = *a2;
  }
  else
  {
    v3 = 2 * *a2;
  }
  result = (v3 + 2) / 3;
  *a2 = result;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0006E1DC) --------------------------------------------------------
void sub_6E1DC( int a1)
{
  int v2; // ecx
  int16_t v3; // bx

  v2 = a1 == 2 || a1 == 5;
  v3 = 0;
  while ( 1 )
  {
    if ( *(_BYTE *)(v3 + 3753 * word_19999C + dword_197F98 + 279) == 3 && sub_654DD(v3) == a1 )
      ++v2;
    if ( ++v3 >= 212 )
      JUMPOUT(0x6A3DF);
  }
}
// 6E23B: control flows out of bounds to 6A3DF
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0006E240) --------------------------------------------------------
int16_t sub_6E240( int a1, int a2)
{
  int16_t i; // ax
  int v5; // edx
  char v6; // cl
  int v7; // edx
  int16_t result; // ax
  _BYTE v9[8]; // [esp+0h] [ebp-Ch] BYREF
  uint8_t v10; // [esp+8h] [ebp-4h]

  sub_8F625((int)v9);
  v10 = v9[0];
  for ( i = 1; i < 8; ++i )
  {
    v5 = word_19995E + (uint8_t)v9[i];
    if ( v10 >= v5 )
      LOBYTE(v5) = v10;
    v6 = v5;
    v7 = i;
    v9[v7] = v6;
  }
  sub_120BB5(a1, (int)v9);
  sub_120E8C(a2);
  word_19995E += byte_19B995;
  result = -byte_19B995;
  if ( word_19995E < 3 )
  {
    if ( word_19995E > -2 )
      return result;
    word_19995E = -2;
  }
  else
  {
    word_19995E = 3;
  }
  byte_19B995 = -byte_19B995;
  return result;
}
// 19995E: using guessed type int16_t word_19995E;
// 19B995: using guessed type char byte_19B995;


//----- (0006E2E8) --------------------------------------------------------
int16_t sub_6E2E8( int a1)
{
  int16_t result; // ax

  result = *(int16_t *)((char *)&word_17F6B5 + 59 * a1 + 2 * *(int16_t *)(dword_1927A8 + 229));
  if ( a1 > 0 && !result )
    return 1;
  return result;
}
// 17F6B5: using guessed type int16_t word_17F6B5;
// 1927A8: using guessed type int dword_1927A8;


//----- (0006E316) --------------------------------------------------------
int sub_6E316( int a1)
{
  int16_t v1; // bx
  int16_t v2; // ax

  v1 = *(int16_t *)((char *)word_17F6B5 + 59 * a1 + 2 * *(int16_t *)(dword_1927A8 + 229));
  if ( a1 > 0 && !v1 )
    v1 = 1;
  sub_6E70A(word_19999C, *(int16_t *)((char *)&word_17F6A7 + 59 * a1));
  return sub_6B519(v1, v2);
}
// 6E361: variable 'v2' is possibly undefined
// 17F6A7: using guessed type int16_t word_17F6A7;
// 17F6B5: using guessed type int16_t word_17F6B5[6];
// 1927A8: using guessed type int dword_1927A8;
// 19999C: using guessed type int16_t word_19999C;


//----- (0006E369) --------------------------------------------------------
int16_t sub_6E369( int a1, int a2)
{
  int16_t result; // ax

  result = *(int16_t *)((char *)&word_17F6A9 + 59 * a1 + 2 * a2);
  if ( a1 > 0 && !result )
    return 1;
  return result;
}
// 17F6A9: using guessed type int16_t word_17F6A9;


//----- (0006E38E) --------------------------------------------------------
int sub_6E38E( int a1, int a2, int a3)
{
  int16_t v4; // bx
  int16_t v5; // ax

  v4 = *(int16_t *)((char *)&word_17F6A9 + 59 * a1 + 2 * a2);
  if ( a1 > 0 && !v4 )
    v4 = 1;
  sub_6E70A(a3, *(int16_t *)((char *)&word_17F6A7 + 59 * a1));
  return sub_6E60E(v4, v5, 0);
}
// 6E3CC: variable 'v5' is possibly undefined
// 17F6A7: using guessed type int16_t word_17F6A7;
// 17F6A9: using guessed type int16_t word_17F6A9;


//----- (0006E3D3) --------------------------------------------------------
int sub_6E3D3(int a1, int a2, int a3)
{
  int v3; // edx
  int v4; // ebx

  LOWORD(a3) = *(_WORD *)(dword_1927A8 + 229);
  if ( (int16_t)a3 >= 5 )
    ++a3;
  v3 = 59 * *(int16_t *)(dword_1927A8 + 17);
  LOWORD(v3) = 5 * *(int16_t *)((char *)&word_17F6C1 + v3);
  v4 = v3 * (a3 + 1);
  if ( (uint8_t)sub_6B7FF(dword_1927A8, 20) )
    return 3 * (int16_t)v4 / 2;
  return v4;
}
// 17F6C1: using guessed type int16_t word_17F6C1;
// 1927A8: using guessed type int dword_1927A8;


//----- (0006E42E) --------------------------------------------------------
void sub_6E42E()
{
  int16_t v0; // di
  int16_t i; // si
  int16_t j; // cx
  int16_t k; // ax
  int v4; // ebx
  int16_t v5; // ax
  char v6; // [esp+0h] [ebp-10h]
  _BOOL2 v7; // [esp+8h] [ebp-8h]
  char v8; // [esp+Ch] [ebp-4h]

  v0 = 0;
  for ( i = 0; i < 212 && !v0; ++i )
  {
    if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C + i + 279) == 3 && sub_654DD(i) == 9 )
    {
      v8 = 0;
      for ( j = 1; j < 39 && !v8; ++j )
      {
        if ( *(int16_t *)((char *)&word_17EEE6 + 47 * j) == *(int16_t *)((char *)&word_17E07D + 13 * i) )
        {
          v7 = 0;
          for ( k = 0; k < 8 && !v7; ++k )
            v7 = j == *(_WORD *)(dword_1927A8 + 2 * k + 181);
          if ( !v7 )
          {
            v4 = 47 * j;
            v6 = sub_6F11C(*(int16_t *)((char *)&word_17EEE6 + v4));
            sub_6E70A(word_19999C, *(int16_t *)((char *)&word_17EEE6 + v4));
            if ( *(_DWORD *)(dword_1927A8 + 237)
               + (int16_t)sub_6E60E(*(int16_t *)((char *)&word_17EEE8[*(int16_t *)(dword_1927A8 + 229)] + v4), v5, v6) <= *(_DWORD *)(dword_1927A8 + 233) )
            {
              v8 = 1;
              ++v0;
            }
          }
        }
      }
    }
  }
  JUMPOUT(0x6A3DE);
}
// 6E56C: control flows out of bounds to 6A3DE
// 6E525: variable 'v5' is possibly undefined
// 17E07D: using guessed type int16_t word_17E07D;
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EEE8: using guessed type int16_t word_17EEE8[6];
// 1927A8: using guessed type int dword_1927A8;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0006E571) --------------------------------------------------------
_BOOL2 sub_6E571()
{
  int16_t v0; // si
  int16_t i; // cx
  int16_t v2; // ax

  v0 = 0;
  for ( i = 0; i < 212 && !v0; ++i )
  {
    if ( *(_BYTE *)(i + dword_197F98 + 3753 * word_19999C + 279) == 3 && sub_654DD(i) == 3 )
    {
      v2 = sub_6E69E(i, 3u);
      v0 = (int16_t)sub_6EDC6(v2) <= dword_19B9A4;
    }
  }
  return v0 > 0;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19B9A4: using guessed type int dword_19B9A4;


//----- (0006E60E) --------------------------------------------------------
int sub_6E60E( int a1, int a2, int a3)
{
  int v4; // eax
  int result; // eax

  if ( a3 )
  {
    if ( a3 == 1 )
    {
      switch ( a2 )
      {
        case 0:
          goto LABEL_13;
        case 1:
LABEL_3:
          v4 = 800;
          break;
        case 2:
          v4 = 700;
          break;
        case 3:
          v4 = 600;
          break;
        case 4:
LABEL_5:
          v4 = 500;
          break;
        default:
          v4 = 400;
          break;
      }
    }
    else
    {
LABEL_13:
      v4 = 1000;
    }
  }
  else
  {
    switch ( a2 )
    {
      case 0:
        goto LABEL_13;
      case 1:
        goto LABEL_3;
      case 2:
        v4 = 650;
        break;
      case 3:
        goto LABEL_5;
      case 4:
        v4 = 350;
        break;
      default:
        v4 = 250;
        break;
    }
  }
  result = (a1 * v4 + 500) / 1000;
  if ( !result )
    return a1 > 0;
  return result;
}


//----- (0006E69E) --------------------------------------------------------
int sub_6E69E( int a1, unsigned int a2)
{
  int result; // eax
  int i; // edx
  int j; // edx

  result = -1;
  if ( a2 >= 3u )
  {
    if ( a2 <= 3u )
    {
      for ( i = 0; (int16_t)i < 40 && (int16_t)result == -1; ++i )
      {
        if ( a1 == word_17F80D[14 * (int16_t)i] )
          result = i;
      }
    }
    else if ( a2 == 9 )
    {
      for ( j = 0; (int16_t)j < 39 && (int16_t)result == -1; ++j )
      {
        if ( a1 == *(int16_t *)((char *)&word_17EEE6 + 47 * (int16_t)j) )
          result = j;
      }
    }
  }
  return result;
}
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17F80D: using guessed type int16_t word_17F80D[];


//----- (0006E70A) --------------------------------------------------------
void sub_6E70A( int a1, int a2)
{
  if ( a1 > -1 && a1 < word_199998 )
  {
    if ( (uint16_t)a2 >= 0xD4u )
    {
      _wcpp_1_unwind_leave(0, 2, "Bad required_tech in Tech_Level()... %d", a2);
      sub_6497C();
    }
    if ( a2 )
    {
      if ( *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 279) != 1 )
        sub_6D048(a1, a2);
    }
  }
}
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0006E777) --------------------------------------------------------
void sub_6E777()
{
  int v0; // ecx
  int16_t v1; // dx
  int v2; // ebx
  int16_t v3; // dx
  int v4; // eax
  int v5; // [esp+0h] [ebp-4h] BYREF

  v0 = 0;
  v5 = *(int16_t *)(dword_1927A8 + 45)
     + *(int16_t *)(dword_1927A8 + 31)
     + word_18001E[18 * *(int16_t *)(dword_1927A8 + 229)]
     + *(int16_t *)(dword_1927A8 + 19)
     + *(int16_t *)(dword_1927A8 + 51);
  v1 = 0;
  while ( 1 )
  {
    if ( *(int16_t *)(dword_1927A8 + 2 * v1 + 53) > 0 )
      v0 += *(_DWORD *)(dword_1927A8 + 4 * v1 + 109);
    if ( ++v1 >= 8 )
    {
      v2 = 0;
      v3 = 0;
      while ( 1 )
      {
        v4 = dword_1927A8 + 2 * v3;
        if ( *(int16_t *)(v4 + 181) > 0 )
          v2 += *(int16_t *)(v4 + 197);
        if ( ++v3 >= 8 )
        {
          v5 += v0 + v2;
          sub_6E1A0(word_19999C, &v5);
          JUMPOUT(0x6B8CC);
        }
      }
    }
  }
}
// 6E81A: control flows out of bounds to 6B8CC
// 18001E: using guessed type int16_t word_18001E[];
// 1927A8: using guessed type int dword_1927A8;
// 19999C: using guessed type int16_t word_19999C;


//----- (0006E81F) --------------------------------------------------------
int sub_6E81F()
{
  int result; // eax

  result = word_180020[18 * *(int16_t *)(dword_1927A8 + 229)];
  if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 368) == 3 )
    return 125 * result / 100;
  return result;
}
// 180020: using guessed type int16_t word_180020[];
// 1927A8: using guessed type int dword_1927A8;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0006E862) --------------------------------------------------------
void sub_6E862()
{
  int v0; // ecx
  int16_t v1; // dx
  int16_t v2; // bx
  int v3; // ecx
  int v4; // edx

  v0 = 0;
  v1 = 0;
  while ( 1 )
  {
    if ( *(int16_t *)(dword_1927A8 + 2 * v1 + 53) > 0 )
      v0 += *(_DWORD *)(dword_1927A8 + 4 * v1 + 141);
    if ( ++v1 >= 8 )
    {
      v2 = 0;
      v3 = 0;
      while ( 1 )
      {
        v4 = dword_1927A8 + 2 * v2;
        if ( *(int16_t *)(v4 + 181) > 0 )
          v3 += *(int16_t *)(v4 + 213);
        if ( ++v2 >= 8 )
          JUMPOUT(0x6A3DF);
      }
    }
  }
}
// 6E8D5: control flows out of bounds to 6A3DF
// 1927A8: using guessed type int dword_1927A8;


//----- (0006E8DA) --------------------------------------------------------
int sub_6E8DA( int a1)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  char v10; // dl
  int16_t i; // ax
  int16_t v12; // ax
  char v13; // dl
  int v14; // eax
  int16_t v15; // dx
  int result; // eax

  sub_6AD3E();
  sub_6B8D2();
  v2 = 0;
  do
    ++v2;
  while ( (int16_t)v2 < 8 );
  v3 = 0;
  do
    ++v3;
  while ( (int16_t)v3 < 8 );
  sub_6C087(a1);
  sub_6C287(a1);
  sub_6E777();
  *(_DWORD *)(dword_1927A8 + 241) = v4;
  sub_6E862();
  v6 = v5;
  v7 = dword_1927A8;
  *(_DWORD *)(dword_1927A8 + 237) = v6;
  v8 = word_180020[18 * *(int16_t *)(v7 + 229)];
  if ( *(_BYTE *)(3753 * word_19999C + dword_197F98 + 368) == 3 )
    v8 = 125 * v8 / 100;
  v9 = dword_1927A8;
  *(_DWORD *)(dword_1927A8 + 233) = v8;
  v10 = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( *(int16_t *)(v9 + 2 * i + 53) > 0 )
      ++v10;
  }
  byte_199EED = v10;
  v12 = 0;
  v13 = 0;
  do
  {
    if ( *(int16_t *)(dword_1927A8 + 2 * v12 + 181) > 0 )
      ++v13;
    ++v12;
  }
  while ( v12 < 8 );
  byte_199EF3 = v13;
  v14 = *(_DWORD *)(dword_1927A8 + 241);
  dword_19B9A4 = *(_DWORD *)(dword_1927A8 + 233) - *(_DWORD *)(dword_1927A8 + 237);
  dword_19B998 = v14;
  sub_6AB4E();
  v15 = 0;
  *(_WORD *)(dword_1927A8 + 246) = 0;
  do
  {
    if ( *(int16_t *)(2 * v15 + dword_1927A8 + 53) > 0 )
      ++*(_WORD *)(dword_1927A8 + 246);
    ++v15;
  }
  while ( v15 < 8 );
  result = dword_1927A8;
  if ( *(_BYTE *)(dword_1927A8 + 245) )
  {
    sub_6F544(*(_WORD *)(dword_1927A8 + 246), *(_WORD *)(dword_1927A8 + 248));
    result = dword_1927A8;
    *(_BYTE *)(dword_1927A8 + 245) = 0;
  }
  return result;
}
// 6E918: variable 'v4' is possibly undefined
// 6E923: variable 'v5' is possibly undefined
// 180020: using guessed type int16_t word_180020[];
// 1927A8: using guessed type int dword_1927A8;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199EED: using guessed type char byte_199EED;
// 199EF3: using guessed type char byte_199EF3;
// 19B998: using guessed type int dword_19B998;
// 19B9A4: using guessed type int dword_19B9A4;


//----- (0006EA48) --------------------------------------------------------
void sub_6EA48( int a1, int a2)
{
  int v2; // ebx
  int v3; // ecx
  _BYTE *v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int16_t v8; // bx
  int v9; // eax
  int v10; // esi
  int v11; // ebx
  int v12; // eax
  int v13; // edx
  int v16; // [esp+Ch] [ebp-Ch]
  int v17; // [esp+10h] [ebp-8h]
  int v18; // [esp+14h] [ebp-4h]

  sub_13303E(dword_1927A8);
  if ( !*(_BYTE *)dword_1927A8 )
    strcpy((char *)dword_1927A8, (char *)sub_77AE6(word_19999C, a2));
  v2 = 3753 * a1;
  v3 = 99 * a2;
  strcpy((char *)(v2 + dword_197F98 + 806 + v3), (char *)dword_1927A8);
  v4 = (_BYTE *)dword_1927A8;
  v5 = v2 + dword_197F98;
  *(_BYTE *)(v3 + v5 + 822) = *(_BYTE *)(dword_1927A8 + 229);
  *(_BYTE *)(v3 + v5 + 824) = v4[17];
  *(_BYTE *)(v3 + v5 + 825) = v4[27];
  *(_BYTE *)(v3 + v5 + 827) = v4[43];
  *(_BYTE *)(v3 + v5 + 828) = v4[49];
  v6 = 0;
  do
  {
    v7 = (int16_t)v6++;
    *(_BYTE *)(v7 + dword_197F98 + 3753 * a1 + 99 * a2 + 829) = 0;
  }
  while ( (int16_t)v6 < 5 );
  v8 = 0;
  while ( 1 )
  {
    v9 = dword_1927A8 + 2 * v8;
    if ( *(int16_t *)(v9 + 181) > 0 )
    {
      v3 = dword_197F98 + 3753 * a1 + 806;
      sub_127712(v3 + 99 * a2 + 23, *(int16_t *)(v9 + 181));
    }
    if ( ++v8 >= 8 )
    {
      v18 = 0;
      do
      {
        v17 = 3753 * a1;
        v10 = dword_1927A8;
        HIWORD(v13) = (int16_t)v18 >> 15;
        v16 = 99 * a2;
        v11 = v16 + v17 + dword_197F98;
        v12 = (int16_t)v18;
        LOWORD(v3) = *(_WORD *)(dword_1927A8 + 2 * (int16_t)v18 + 53);
        *(_WORD *)(v11 + 8 * (int16_t)v18 + 834) = v3;
        LOBYTE(v3) = *(_BYTE *)(v10 + 2 * (int16_t)v18 + 69);
        *(_BYTE *)(v11 + 8 * (int16_t)v18 + 836) = v3;
        *(_BYTE *)(v11 + 8 * (int16_t)v18 + 837) = v3;
        LOBYTE(v3) = *(_BYTE *)((int16_t)v18 + v10 + 85);
        *(_BYTE *)(v11 + 8 * (int16_t)v18 + 838) = v3;
        LOWORD(v13) = *(_WORD *)(v10 + 2 * (int16_t)v18 + 93);
        *(_WORD *)(v11 + 8 * (int16_t)v18 + 839) = v13;
        LOBYTE(v13) = *(_BYTE *)((int16_t)v18++ + v10 + 173);
        *(_BYTE *)(v11 + 8 * v12 + 841) = v13;
      }
      while ( (int16_t)v18 < 8 );
      *(_BYTE *)(v11 + 898) = *(_BYTE *)(v10 + 231);
      *(_WORD *)(v11 + 900) = *(_WORD *)(v10 + 241);
      *(_WORD *)(v11 + 903) = dword_192FD8;
      byte_19B9B8 = 0;
      *(_BYTE *)(v16 + v17 + dword_197F98 + 902) = sub_6B7CF(v10, v13, v11, v3);
      *(_BYTE *)(v16 + v17 + dword_197F98 + 826) = sub_575D6(a1, *(_WORD *)(dword_1927A8 + 27));
      JUMPOUT(0x6AB15);
    }
  }
}
// 6EC6F: control flows out of bounds to 6AB15
// 1927A8: using guessed type int dword_1927A8;
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19B9B8: using guessed type char byte_19B9B8;


//----- (0006EC74) --------------------------------------------------------
int sub_6EC74( int a1, int a2, int a3, unsigned int a4, int a5)
{
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int v9; // esi
  int16_t v10; // ax
  int16_t v11; // cx
  int v12; // ebx
  int16_t v13; // ax
  int16_t v15; // [esp+0h] [ebp-14h] BYREF
  int16_t v16; // [esp+4h] [ebp-10h] BYREF
  int16_t v17; // [esp+8h] [ebp-Ch] BYREF
  int16_t v18; // [esp+Ch] [ebp-8h]
  int v19; // [esp+10h] [ebp-4h]

  v19 = a2;
  v18 = a3;
  v6 = word_17F813[14 * a1];
  if ( sub_6EFEB(a1) == 1 )
  {
    LOWORD(v7) = 0;
    if ( a4 < 0xAu )
    {
      if ( a4 >= 2u )
      {
        if ( a4 <= 2u )
        {
          LOWORD(v7) = 10;
        }
        else if ( a4 == 5 )
        {
          LOWORD(v7) = 20;
        }
      }
    }
    else if ( a4 <= 0xAu )
    {
      LOWORD(v7) = 30;
    }
    else if ( a4 >= 0xFu )
    {
      if ( a4 <= 0xFu )
      {
        LOWORD(v7) = 35;
      }
      else if ( a4 == 20 )
      {
        LOWORD(v7) = 40;
      }
    }
    v7 = (int16_t)v7;
  }
  else
  {
    v7 = 0;
  }
  v8 = v7 + v6;
  sub_6A636(a5, &v17, &v15);
  v9 = v8 * v17 / 100;
  v10 = (uint8_t)byte_17F80F[28 * a1];
  if ( byte_17F80F[28 * a1] )
  {
    v11 = 0;
  }
  else
  {
    if ( (v18 & 2) != 0 || (v18 & 4) != 0 )
    {
      v10 = 25;
    }
    else if ( (v18 & 0x10) != 0 )
    {
      v10 = 50;
    }
    v11 = v10;
  }
  sub_6A406(a5, &v16, &v15);
  v12 = (int16_t)v19 * (v9 * (v16 + v11 + 100) / 100);
  sub_6E70A(word_19999C, word_17F80D[14 * a1]);
  return (int16_t)sub_6B519(v12, v13);
}
// 6ED9E: variable 'v13' is possibly undefined
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F813: using guessed type int16_t word_17F813[];
// 19999C: using guessed type int16_t word_19999C;


//----- (0006EDAE) --------------------------------------------------------
_BOOL2 sub_6EDAE( int a1)
{
  return byte_17F80F[28 * a1] == 1;
}


//----- (0006EDC6) --------------------------------------------------------
int sub_6EDC6( int a1)
{
  int v2; // ecx
  char v3; // bl
  int16_t v4; // ax
  int v5; // esi
  char v6; // bl
  int16_t v7; // ax
  int v8; // eax
  char v9; // bl
  int16_t v10; // ax

  v2 = 14 * a1;
  if ( sub_6EFEB(a1) == 1 )
  {
    v3 = sub_6F11C(word_17F80D[v2]);
    sub_6E70A(word_19999C, word_17F80D[14 * a1]);
    v5 = sub_6E60E(word_17F811[v2], v4, v3);
    v6 = sub_6F11C(word_17F80D[v2]);
    sub_6E70A(word_19999C, word_17F80D[v2]);
    v8 = sub_6E60E(10, v7, v6);
  }
  else
  {
    v9 = sub_6F11C(word_17F80D[v2]);
    sub_6E70A(word_19999C, word_17F80D[14 * a1]);
    v5 = sub_6E60E(word_17F811[v2], v10, v9);
    v8 = 0;
  }
  return v5 + v8;
}
// 6EE14: variable 'v4' is possibly undefined
// 6EE45: variable 'v7' is possibly undefined
// 6EE7E: variable 'v10' is possibly undefined
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F811: using guessed type int16_t word_17F811[];
// 19999C: using guessed type int16_t word_19999C;


//----- (0006EE8E) --------------------------------------------------------
int sub_6EE8E(int a1, int a2, int a3, int a4, unsigned int a5, int a6)
{
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  char v13; // bl
  int16_t v14; // ax
  int v15; // ecx
  int16_t v17; // [esp+0h] [ebp-18h]
  int16_t v18; // [esp+4h] [ebp-14h] BYREF
  int v19; // [esp+8h] [ebp-10h]
  int16_t v20; // [esp+Ch] [ebp-Ch]
  int16_t v21; // [esp+10h] [ebp-8h] BYREF
  int16_t v22; // [esp+14h] [ebp-4h] BYREF

  v20 = a4;
  v7 = word_17F811[14 * a2];
  if ( sub_6EFEB(a2) == 1 )
  {
    LOWORD(v8) = 0;
    if ( a5 < 0xAu )
    {
      if ( a5 >= 2u )
      {
        if ( a5 <= 2u )
        {
          LOWORD(v8) = 10;
        }
        else if ( a5 == 5 )
        {
          LOWORD(v8) = 20;
        }
      }
    }
    else if ( a5 <= 0xAu )
    {
      LOWORD(v8) = 30;
    }
    else if ( a5 >= 0xFu )
    {
      if ( a5 <= 0xFu )
      {
        LOWORD(v8) = 35;
      }
      else if ( a5 == 20 )
      {
        LOWORD(v8) = 40;
      }
    }
    v8 = (int16_t)v8;
  }
  else
  {
    v8 = 0;
  }
  v9 = v8 + v7;
  sub_6A636(a6, &v21, &v18);
  v10 = v9 * v18 / 100;
  v11 = 28 * a2;
  LOWORD(v11) = (uint8_t)byte_17F80F[v11];
  if ( (_WORD)v11 )
  {
    v19 = 0;
  }
  else
  {
    if ( (v20 & 2) != 0 || (v20 & 4) != 0 )
    {
      v11 = 25;
    }
    else if ( (v20 & 0x10) != 0 )
    {
      v11 = 50;
    }
    v19 = v11;
  }
  sub_6A406(a6, &v21, &v22);
  v12 = v10 * (v22 + (int16_t)v19 + 100) / 100;
  v13 = sub_6F11C(word_17F80D[14 * a2]);
  sub_6E70A(v17, word_17F80D[14 * a2]);
  v15 = a3 * (int16_t)sub_6E60E(v12, v14, v13);
  if ( v15 <= 1 )
    return 1;
  else
    return v15;
}
// 6EFBE: variable 'v17' is possibly undefined
// 6EFC9: variable 'v14' is possibly undefined
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F811: using guessed type int16_t word_17F811[];


//----- (0006EFEB) --------------------------------------------------------
int16_t sub_6EFEB( int a1)
{
  return (uint8_t)byte_17F80F[28 * a1];
}


//----- (0006EFF8) --------------------------------------------------------
char sub_6EFF8( int result, _BYTE *a2)
{
  int v2; // eax
  char *v3; // edi
  char v4[8]; // [esp+0h] [ebp-8h] BYREF

  *a2 = byte_1791EB;
  if ( (result & 1) != 0 )
  {
    v2 = 3;
    goto LABEL_3;
  }
  if ( (result & 2) != 0 )
  {
    v2 = 4;
    goto LABEL_3;
  }
  if ( (result & 4) != 0 )
  {
    v2 = 6;
    goto LABEL_3;
  }
  if ( (result & 8) != 0 )
  {
    v2 = 5;
LABEL_3:
    sub_58F1E(v2, v4, 6);
    v3 = a2 - 1;
    do
      ++v3;
    while ( *v3 );
    strcpy(v3, v4);
    return result;
  }
  if ( (result & 0x10) != 0 )
    *(_DWORD *)a2 = dword_17925F;
  return result;
}
// 1791EB: using guessed type char byte_1791EB;
// 17925F: using guessed type int dword_17925F;


//----- (0006F07F) --------------------------------------------------------
int sub_6F07F( int a1, char *a2)
{
  char *v2; // edi
  char v3; // al
  int16_t v4; // bx
  char *v5; // edi
  char *v6; // edi
  int result; // eax
  int16_t v8; // cx
  char *v9; // edx
  char *v10; // [esp-4h] [ebp-8h]

  v2 = a2;
  v3 = 0;
  v4 = 0;
  *a2 = 0;
  do
  {
    if ( ((a1 >> v4) & 1) != 0 )
    {
      v10 = v2;
      v5 = v2 - 1;
      do
        ++v5;
      while ( *v5 );
      strcpy(v5, *(char **)((char *)&off_17FD0F + 15 * v4));
      v6 = v10 - 1;
      do
        ++v6;
      while ( *v6 );
      strcpy(v6, ", ");
      v2 = v10;
      v3 = 1;
    }
    ++v4;
  }
  while ( v4 < 15 );
  if ( !v3 )
    strcpy(a2, sub_7A990(0x64u));
  result = 0;
  v8 = strlen(a2);
  if ( v8 > 2 )
  {
    result = v8;
    v9 = &a2[v8];
    if ( *(v9 - 2) == 44 )
      *(v9 - 2) = 0;
  }
  return result;
}
// 17FD0F: using guessed type _UNKNOWN *off_17FD0F;


//----- (0006F11C) --------------------------------------------------------
char sub_6F11C( int a1)
{
  int16_t v2; // cx
  char v3; // dl
  int v4; // ebx
  int16_t v5; // ax

  v2 = (uint8_t)byte_17E085[13 * a1];
  v3 = 1;
  if ( v2 == 3 )
  {
    if ( a1 == word_17FB71 || a1 == word_17FB55 || a1 == word_17FB1D || a1 == word_17FB39 )
      return 2;
    v4 = 28 * (int16_t)sub_78D3E(a1);
    v5 = (uint8_t)byte_17F80F[v4];
    if ( v5 == 3 || v5 == 1 || !byte_17F80F[v4] )
      return 0;
  }
  else if ( v2 == 9
         && (a1 == word_17EF44 || a1 == word_17F3DB || a1 == word_17F0EB || a1 == word_17F178 || a1 == word_17F582) )
  {
    return 2;
  }
  return v3;
}
// 17EF44: using guessed type int16_t word_17EF44;
// 17F0EB: using guessed type int16_t word_17F0EB;
// 17F178: using guessed type int16_t word_17F178;
// 17F3DB: using guessed type int16_t word_17F3DB;
// 17F582: using guessed type int16_t word_17F582;
// 17FB1D: using guessed type int16_t word_17FB1D;
// 17FB39: using guessed type int16_t word_17FB39;
// 17FB55: using guessed type int16_t word_17FB55;
// 17FB71: using guessed type int16_t word_17FB71;


//----- (0006F1CC) --------------------------------------------------------
int sub_6F1CC( unsigned int a1)
{
  int v1; // edx

  v1 = 0;
  if ( a1 >= 0xAu )
  {
    if ( a1 <= 0xAu )
      return 30;
    if ( a1 >= 0xFu )
    {
      if ( a1 <= 0xFu )
        return 35;
      if ( a1 != 20 )
        return 0;
      return 40;
    }
    return v1;
  }
  if ( a1 < 2u )
    return v1;
  if ( a1 <= 2u )
    return 10;
  if ( a1 == 5 )
    return 20;
  return 0;
}


//----- (0006F23C) --------------------------------------------------------
char *sub_6F23C(char *a1)
{
  char *v1; // edi
  char *result; // eax
  char *v3; // kr00_4
  char *v4; // esi
  _DWORD *v5; // edi
  _DWORD *v6; // esi

  v1 = a1;
  LOBYTE(a1) = byte_199CAE;
  v3 = a1;
  result = (char *)(uint8_t)byte_199CAE;
  switch ( byte_199CAE )
  {
    case 1:
      v4 = aGertecdLbx;
      goto LABEL_6;
    case 2:
      v4 = aFretecdLbx;
      goto LABEL_6;
    case 3:
      v4 = aSpatecdLbx;
      goto LABEL_6;
    case 4:
      v4 = aItatecdLbx;
LABEL_6:
      *(_DWORD *)v1 = *(_DWORD *)v4;
      v6 = v4 + 4;
      v5 = v1 + 4;
      *v5 = *v6;
      v5[1] = v6[1];
      break;
    default:
      result = v3;
      strcpy(v1, "TECHDESC.LBX");
      break;
  }
  return result;
}
// 199CAE: using guessed type char byte_199CAE;


//----- (0006F280) --------------------------------------------------------
int sub_6F280()
{
  int16_t v0; // dx
  int16_t v1; // cx
  int16_t v2; // di
  _WORD *v3; // eax
  int16_t v4; // dx
  _WORD *v5; // eax
  int16_t v6; // bx
  _WORD *v7; // eax
  _WORD *v8; // eax
  _WORD *v9; // eax
  _WORD *v10; // eax
  _WORD *v11; // eax
  int16_t v13; // [esp+10h] [ebp-10h]
  int16_t v14; // [esp+14h] [ebp-Ch]
  int16_t v15; // [esp+18h] [ebp-8h]
  int16_t v16; // [esp+18h] [ebp-8h]
  int16_t v17; // [esp+18h] [ebp-8h]

  v0 = 15;
  if ( byte_199F3A == 2 )
  {
    unk_1817FE = 303;
    unk_181800 = 73;
    unk_181802 = 0;
    unk_181804 = 156;
    unk_181806 = 19;
    unk_18180A = 418;
    unk_18180C = 0;
    unk_18180E = 519;
    unk_181810 = 19;
    v0 = 17;
    unk_181808 = 302;
  }
  else if ( byte_199F3A == 1 )
  {
    unk_1817FE = 303;
    unk_181800 = 73;
    unk_181802 = 0;
    unk_181804 = 156;
    v0 = 16;
    unk_181806 = 19;
  }
  if ( sub_918D5(2) )
  {
    v13 = word_199BB2;
    v1 = *(_WORD *)(dword_193278 + 2);
    v14 = word_199BAE + word_199BBA - v1;
    v2 = word_199BAC + 2;
    v3 = (_WORD *)((char *)&unk_181768 + 10 * v0);
    *v3 = 310;
    v3[1] = v2;
    v3[2] = v14 - 35;
    v3[3] = v2 + v13;
    v3[4] = v14;
    v4 = v0 + 1;
    v5 = (_WORD *)((char *)&unk_181768 + 10 * v4);
    *v5 = 304;
    v5[1] = v2;
    v5[2] = v14;
    v5[3] = v2 + v13;
    v0 = v4 + 1;
    v5[4] = v1 + v14;
    v6 = v1;
    if ( byte_199BCC )
    {
      v7 = (_WORD *)((char *)&unk_181768 + 10 * v0);
      *v7 = 309;
      v7[1] = v2;
      v7[2] = v14;
      v6 = 2 * v1;
      v7[3] = v2 + v13;
      ++v0;
      v7[4] = v1 + v1 + v14;
    }
    if ( byte_199BCA )
    {
      v15 = v6 + v1 + v14;
      v8 = (_WORD *)((char *)&unk_181768 + 10 * v0);
      *v8 = 306;
      v8[1] = v2;
      v8[2] = v14;
      v6 += v1;
      v8[3] = v2 + v13;
      ++v0;
      v8[4] = v15;
    }
    if ( byte_199BC9 )
    {
      v16 = v6 + v1 + v14;
      v9 = (_WORD *)((char *)&unk_181768 + 10 * v0);
      *v9 = 307;
      v9[1] = v2;
      v9[2] = v14;
      v6 += v1;
      v9[3] = v2 + v13;
      ++v0;
      v9[4] = v16;
    }
    if ( byte_199BCB )
    {
      v17 = v6 + v1 + v14;
      v10 = (_WORD *)((char *)&unk_181768 + 10 * v0);
      *v10 = 308;
      v10[1] = v2;
      v10[2] = v14;
      v6 += v1;
      v10[3] = v2 + v13;
      ++v0;
      v10[4] = v17;
    }
    if ( byte_199BC8 )
    {
      v11 = (_WORD *)((char *)&unk_181768 + 10 * v0);
      *v11 = 305;
      v11[1] = v2;
      v11[2] = v14;
      v11[3] = v2 + v13;
      ++v0;
      v11[4] = v14 + v1 + v6;
    }
  }
  sub_1196F7();
  return sub_1196B8((int)&unk_181768, v0);
}
// 193278: using guessed type int dword_193278;
// 199BAC: using guessed type int16_t word_199BAC;
// 199BAE: using guessed type int16_t word_199BAE;
// 199BB2: using guessed type int16_t word_199BB2;
// 199BBA: using guessed type int16_t word_199BBA;
// 199BC8: using guessed type char byte_199BC8;
// 199BC9: using guessed type char byte_199BC9;
// 199BCA: using guessed type char byte_199BCA;
// 199BCB: using guessed type char byte_199BCB;
// 199BCC: using guessed type char byte_199BCC;
// 199F3A: using guessed type char byte_199F3A;


//----- (0006F52D) --------------------------------------------------------
int sub_6F52D()
{
  sub_1196F7();
  return sub_1196B8((int)&unk_181862, 15);
}


//----- (0006F544) --------------------------------------------------------
void sub_6F544( int a1, int a2)
{
  int v2; // ebx
  int16_t v3; // ax
  int v4; // ebx
  int16_t v5; // ax

  qmemcpy(&unk_19BE34, &off_1818F8, 0x82u);
  if ( a1 > 0 )
  {
    v2 = 14 * a1 + 15;
    v3 = word_19BE78;
    v4 = word_19BE74 + v2;
    if ( word_19BE78 > v4 )
      v3 = v4;
    word_19BE74 = v3;
  }
  if ( a2 > 0 )
  {
    v5 = word_19BE82;
    if ( word_19BE82 > 14 * a2 + 15 + word_19BE7E )
      v5 = 14 * a2 + 15 + word_19BE7E;
    word_19BE7E = v5;
  }
  sub_1196F7();
  JUMPOUT(0x6FB54);
}
// 6F5BC: control flows out of bounds to 6FB54
// 1818F8: using guessed type _UNKNOWN *off_1818F8;
// 19BE74: using guessed type int16_t word_19BE74;
// 19BE78: using guessed type int16_t word_19BE78;
// 19BE7E: using guessed type int16_t word_19BE7E;
// 19BE82: using guessed type int16_t word_19BE82;


//----- (0006F5C1) --------------------------------------------------------
int sub_6F5C1( int a1, int a2, int a3, int a4)
{
  int16_t v5; // ax
  int16_t v6; // di
  int16_t v7; // bx
  int16_t v8; // ax
  int16_t v9; // bx
  int16_t v10; // ax
  int16_t v11; // bx
  int16_t v12; // ax
  int16_t v13; // bx
  int16_t v14; // ax
  int16_t v15; // ax
  int16_t v16; // bx
  int16_t v17; // bx
  int16_t v19; // [esp+38h] [ebp-Ch]

  v5 = *(_WORD *)(dword_19280C + 2);
  if ( a1 < 7 )
    v5 = 102;
  v6 = a3 + *(_WORD *)(dword_1927C4 + 2) + v5;
  memset(word_19BC14, 0, sizeof(word_19BC14));
  v7 = *(_WORD *)dword_1927D4 + a2 + 101;
  v8 = *(_WORD *)(dword_1927D4 + 2);
  word_19BC14[0] = 392;
  word_19BC14[1] = a2 + 101;
  word_19BC14[2] = v6 + 10;
  word_19BC14[3] = v7;
  word_19BC14[4] = v6 + 10 + v8;
  v9 = *(_WORD *)dword_192808 + a2 + 203;
  v10 = *(_WORD *)(dword_192808 + 2);
  word_19BC14[5] = 393;
  word_19BC14[6] = a2 + 203;
  word_19BC14[7] = v6 + 10;
  word_19BC14[8] = v9;
  word_19BC14[9] = v6 + 10 + v10;
  v11 = *(_WORD *)dword_1927CC + a2 + 326;
  v12 = *(_WORD *)(dword_1927CC + 2);
  word_19BC14[10] = 394;
  word_19BC14[11] = a2 + 326;
  word_19BC14[12] = v6 + 10;
  word_19BC14[13] = v11;
  word_19BC14[14] = v6 + 10 + v12;
  v13 = *(_WORD *)dword_1927DC + a2 + 429;
  v14 = *(_WORD *)(dword_1927DC + 2);
  word_19BC14[15] = 395;
  word_19BC14[16] = a2 + 429;
  word_19BC14[17] = v6 + 10;
  word_19BC14[18] = v13;
  word_19BC14[19] = v6 + 10 + v14;
  v15 = *(_WORD *)(dword_192804 + 2);
  v16 = a2 + 538 + *(_WORD *)dword_192804;
  word_19BC14[20] = 396;
  word_19BC14[21] = a2 + 538;
  word_19BC14[22] = v6 + 82;
  word_19BC14[23] = v16;
  word_19BC14[24] = v6 + 82 + v15;
  v17 = *(_WORD *)dword_1927D8;
  v19 = v6 + 130 + *(_WORD *)(dword_1927D8 + 2);
  word_19BC14[25] = 397;
  word_19BC14[26] = a2 + 538;
  word_19BC14[27] = v6 + 130;
  word_19BC14[28] = a2 + 538 + v17;
  word_19BC14[29] = v19;
  word_19BC14[30] = (a4 != 0) + 398;
  word_19BC14[31] = a2 + 24;
  word_19BC14[32] = v6 + 69;
  word_19BC14[34] = v6 + 170;
  word_19BC14[33] = a2 + 210;
  sub_1196F7();
  return sub_1196B8((int)word_19BC14, 7);
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 1927C4: using guessed type int dword_1927C4;
// 1927CC: using guessed type int dword_1927CC;
// 1927D4: using guessed type int dword_1927D4;
// 1927D8: using guessed type int dword_1927D8;
// 1927DC: using guessed type int dword_1927DC;
// 192804: using guessed type int dword_192804;
// 192808: using guessed type int dword_192808;
// 19280C: using guessed type int dword_19280C;
// 19BC14: using guessed type _WORD word_19BC14[60];


//----- (0006F826) --------------------------------------------------------
void sub_6F826()
{
  sub_1196F7();
  JUMPOUT(0x6F53D);
}
// 6F836: control flows out of bounds to 6F53D


//----- (0006F83B) --------------------------------------------------------
void sub_6F83B()
{
  sub_1196F7();
  JUMPOUT(0x6F53D);
}
// 6F84B: control flows out of bounds to 6F53D


//----- (0006F850) --------------------------------------------------------
void sub_6F850()
{
  sub_1196F7();
  JUMPOUT(0x6F53D);
}
// 6F860: control flows out of bounds to 6F53D


//----- (0006F865) --------------------------------------------------------
void sub_6F865()
{
  sub_1196F7();
  JUMPOUT(0x6F53D);
}
// 6F875: control flows out of bounds to 6F53D


//----- (0006F87A) --------------------------------------------------------
void sub_6F87A()
{
  sub_1196F7();
  JUMPOUT(0x6F53D);
}
// 6F88A: control flows out of bounds to 6F53D


//----- (0006F88F) --------------------------------------------------------
void sub_6F88F( int a1)
{
  int v1; // ebx
  int16_t v2; // cx
  _WORD *v3; // eax
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v1 = 12;
  qmemcpy(&unk_19BAD4, &unk_181B3C, 0x140u);
  if ( a1 )
  {
    v2 = a1;
    while ( v2 < 20 )
    {
      v4 = ((v2 % 4) << 6) + 406;
      v5 = ((int)(v2 - (__CFSHL__((uint64_t)v2 >> 32, 2) + 4 * ((uint64_t)v2 >> 32))) >> 2 << 6) + 114;
      v3 = (_WORD *)((char *)&unk_19BAD4 + 10 * (int16_t)v1);
      *v3 = 360;
      v3[1] = ((v2 % 4) << 6) + 342;
      v3[2] = ((uint16_t)((int)(v2
                                      - (__CFSHL__((uint64_t)v2 >> 32, 2)
                                       + 4 * ((uint64_t)v2 >> 32))) >> 2) << 6)
            + 52;
      ++v2;
      v3[3] = v4;
      ++v1;
      v3[4] = v5;
    }
  }
  else
  {
    unk_19BB4C = 360;
    unk_19BB4E = 344;
    unk_19BB50 = 53;
    unk_19BB52 = 591;
    unk_19BB54 = 353;
  }
  sub_1196F7();
  JUMPOUT(0x6F521);
}
// 6F95A: control flows out of bounds to 6F521


//----- (0006F95F) --------------------------------------------------------
void sub_6F95F(int a1)
{
  int16_t v1; // bx
  int16_t *v2; // eax

  qmemcpy(&unk_19BA34, &off_181C7C, 0xA0u);
  v1 = 0;
  while ( 1 )
  {
    v2 = (int16_t *)(a1 + 2 * v1);
    if ( *v2 > 0 )
      word_19BA38[5 * v1 + 15] += 17 * *v2 + 16;
    if ( ++v1 >= 4 )
    {
      sub_1196F7();
      JUMPOUT(0x6F521);
    }
  }
}
// 6F9B8: control flows out of bounds to 6F521
// 181C7C: using guessed type _UNKNOWN *off_181C7C;
// 19BA38: using guessed type int16_t word_19BA38[78];


//----- (0006F9BD) --------------------------------------------------------
void sub_6F9BD(int a1, int a2)
{
  int16_t v2; // bx
  int16_t v3; // si
  int16_t *v4; // edx
  int16_t v5; // si
  _WORD *v6; // eax
  int v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v2 = 18;
  qmemcpy(&unk_19BC90, &off_181D1C, 0x14Au);
  v3 = 0;
  while ( 1 )
  {
    v4 = (int16_t *)(a1 + 2 * v3);
    if ( *v4 > 0 )
      word_19BC94[5 * v3 + 10] += 17 * *v4 + 16;
    if ( ++v3 >= 4 )
    {
      if ( a2 )
      {
        v5 = a2;
        while ( v5 < 15 )
        {
          v9 = 63 * (v5 % 5) + 364;
          v8 = 62 * (v5 / 5) + 78;
          v6 = (_WORD *)((char *)&unk_19BC90 + 10 * v2);
          *v6 = 333;
          v6[1] = 63 * (v5 % 5) + 301;
          v6[2] = 62 * (v5 / 5) + 16;
          ++v5;
          v6[3] = v9;
          ++v2;
          v6[4] = v8;
        }
      }
      else
      {
        unk_19BD44 = 333;
        unk_19BD46 = 301;
        unk_19BD48 = 16;
        unk_19BD4A = 610;
        v2 = 19;
        unk_19BD4C = 198;
      }
      sub_1196F7();
      sub_1196B8((int)&unk_19BC90, v2);
      JUMPOUT(0x6FC53);
    }
  }
}
// 6FABB: control flows out of bounds to 6FC53
// 181D1C: using guessed type _UNKNOWN *off_181D1C;
// 19BC94: using guessed type int16_t word_19BC94[163];


//----- (0006FAC0) --------------------------------------------------------
void sub_6FAC0()
{
  sub_1196F7();
  JUMPOUT(0x6F53D);
}
// 6FAD0: control flows out of bounds to 6F53D


//----- (0006FAD5) --------------------------------------------------------
void sub_6FAD5()
{
  sub_1196F7();
  JUMPOUT(0x6F53D);
}
// 6FAE5: control flows out of bounds to 6F53D


//----- (0006FAEA) --------------------------------------------------------
void sub_6FAEA( int a1, int a2)
{
  qmemcpy(&unk_19BDDA, &unk_181F06, 0x5Au);
  sub_6FC7E((int)&unk_19BDDA, 9, a1, a2);
  sub_1196F7();
  JUMPOUT(0x6FB52);
}
// 6FB1D: control flows out of bounds to 6FB52


//----- (0006FB1F) --------------------------------------------------------
int sub_6FB1F( int a1, int a2)
{
  qmemcpy(&unk_19B9BC, &unk_181F60, 0x28u);
  sub_6FC7E((int)&unk_19B9BC, 4, a1, a2);
  sub_1196F7();
  return sub_1196B8((int)&unk_19B9BC, 4);
}


//----- (0006FB5E) --------------------------------------------------------
void sub_6FB5E()
{
  sub_1196F7();
  JUMPOUT(0x6F53D);
}
// 6FB6E: control flows out of bounds to 6F53D


//----- (0006FB73) --------------------------------------------------------
void sub_6FB73()
{
  JUMPOUT(0x6FB32);
}
// 6FB86: control flows out of bounds to 6FB32


//----- (0006FB88) --------------------------------------------------------
void sub_6FB88()
{
  JUMPOUT(0x6FB32);
}
// 6FB9B: control flows out of bounds to 6FB32


//----- (0006FBEA) --------------------------------------------------------
_DWORD *sub_6FBEA(char *a1, int a2)
{
  _DWORD *v3; // ebx
  char v5[20]; // [esp+0h] [ebp-14h] BYREF

  sub_A6547(v5);
  sub_1112EC(dword_192ED4, 2000);
  v3 = sub_110D3C(dword_192ED4, 2000);
  sub_110D3C(dword_192ED4, 1403);
  strcpy(a1, (char *)sub_126C37((int)v5, 0, (int)v3, a2, 1u, 1403) + 103);
  return sub_1113CC(dword_192ED4, 0);
}
// 192ED4: using guessed type int dword_192ED4;


//----- (0006FC59) --------------------------------------------------------
void sub_6FC59(int a1, int a2)
{
  char v2[20]; // [esp+0h] [ebp-14h] BYREF

  sub_1112EC(dword_192ED4, a2);
  sub_A6547(v2);
  JUMPOUT(0x6FC0D);
}
// 6FC7C: control flows out of bounds to 6FC0D
// 192ED4: using guessed type int dword_192ED4;


//----- (0006FC7E) --------------------------------------------------------
int sub_6FC7E(int result, int a2, int a3, int a4)
{
  int v4; // esi
  int16_t i; // dx

  v4 = result;
  for ( i = 0; i < a2; ++i )
  {
    result = 10 * i;
    *(_WORD *)(v4 + result + 2) += a3;
    *(_WORD *)(v4 + result + 4) += a4;
    *(_WORD *)(v4 + result + 6) += a3;
    *(_WORD *)(v4 + result + 8) += a4;
  }
  return result;
}


//----- (0006FCAB) --------------------------------------------------------
int sub_6FCAB()
{
  int result; // eax

  word_19BEB8 = word_1844DA;
  word_19BEB6 = word_1844D8;
  result = dword_1B0838;
  dword_19BC8C = dword_1B0838;
  return result;
}
// 1844D8: using guessed type int16_t word_1844D8;
// 1844DA: using guessed type int16_t word_1844DA;
// 19BC8C: using guessed type int dword_19BC8C;
// 19BEB6: using guessed type int16_t word_19BEB6;
// 19BEB8: using guessed type int16_t word_19BEB8;
// 1B0838: using guessed type int dword_1B0838;


//----- (0006FCCE) --------------------------------------------------------
void sub_6FCCE()
{
  word_1844DA = word_19BEB8;
  word_1844D8 = word_19BEB6;
  dword_1B0838 = dword_19BC8C;
  if ( word_19BEB6 )
    sub_1196B8(dword_19BC8C, word_19BEB8);
  else
    sub_1196F7();
}
// 1844D8: using guessed type int16_t word_1844D8;
// 1844DA: using guessed type int16_t word_1844DA;
// 19BC8C: using guessed type int dword_19BC8C;
// 19BEB6: using guessed type int16_t word_19BEB6;
// 19BEB8: using guessed type int16_t word_19BEB8;
// 1B0838: using guessed type int dword_1B0838;


//----- (0006FD10) --------------------------------------------------------
int sub_6FD10(int a1, int a2)
{
  sub_1196F7();
  return sub_1196B8(a1, a2);
}


//----- (0006FD24) --------------------------------------------------------
int sub_6FD24( int a1, int a2)
{
  int16_t *v3; // eax
  int16_t v4; // si
  int16_t v5; // di
  int result; // eax
  int v7; // edx
  int v8; // edx
  int v9; // edx
  int16_t *v10; // [esp+4h] [ebp-24h]
  int16_t *v11; // [esp+8h] [ebp-20h]
  int16_t *v12; // [esp+Ch] [ebp-1Ch]
  int16_t *v13; // [esp+10h] [ebp-18h]
  int16_t *v14; // [esp+14h] [ebp-14h]
  int16_t v15; // [esp+18h] [ebp-10h]
  int16_t v16; // [esp+24h] [ebp-4h]

  v3 = (int16_t *)dword_193278;
  v4 = *(_WORD *)(dword_193278 + 2);
  v16 = v4;
  if ( word_199BB8 <= 9 )
  {
    v14 = (int16_t *)dword_1932C4;
    v12 = (int16_t *)dword_1932B8;
    v10 = (int16_t *)dword_193280;
    v13 = (int16_t *)dword_193288;
    v11 = (int16_t *)dword_19329C;
    v3 = (int16_t *)dword_1931B8;
  }
  else
  {
    v14 = (int16_t *)dword_193284;
    v12 = (int16_t *)dword_1932A0;
    v10 = (int16_t *)dword_193290;
    v13 = (int16_t *)dword_1932B4;
    v11 = (int16_t *)dword_1932C0;
  }
  v15 = a1 + 2;
  v5 = word_199BBA + a2 - v4;
  result = sub_11C3C5(v15, v5, (int)&unk_1792A6, v3, asc_1792A4, 40);
  word_193024 = result;
  if ( byte_199BCC )
  {
    v4 *= 2;
    result = sub_11C3C5(v15, (int16_t)(v16 + v5), (int)&unk_1792A6, v13, &unk_1792A6, 40);
    word_1999CC = result;
  }
  if ( byte_199BCA )
  {
    v7 = (int16_t)(v4 + v5);
    v4 += v16;
    result = sub_11C3C5(v15, v7, (int)&unk_1792A6, v12, &unk_1792A6, 40);
    word_1999CE = result;
  }
  if ( byte_199BC9 )
  {
    v8 = (int16_t)(v4 + v5);
    v4 += v16;
    result = sub_11C3C5(v15, v8, (int)&unk_1792A6, v11, &unk_1792A6, 40);
    word_1999DA = result;
  }
  if ( byte_199BCB )
  {
    v9 = (int16_t)(v4 + v5);
    v4 += v16;
    result = sub_11C3C5(v15, v9, (int)&unk_1792A6, v10, &unk_1792A6, 40);
    word_1999D6 = result;
  }
  if ( byte_199BC8 )
  {
    result = sub_11C3C5(v15, (int16_t)(v4 + v5), (int)&unk_1792A6, v14, &unk_1792A6, 40);
    word_1999D4 = result;
  }
  return result;
}
// 193024: using guessed type int16_t word_193024;
// 1931B8: using guessed type int dword_1931B8;
// 193278: using guessed type int dword_193278;
// 193280: using guessed type int dword_193280;
// 193284: using guessed type int dword_193284;
// 193288: using guessed type int dword_193288;
// 193290: using guessed type int dword_193290;
// 19329C: using guessed type int dword_19329C;
// 1932A0: using guessed type int dword_1932A0;
// 1932B4: using guessed type int dword_1932B4;
// 1932B8: using guessed type int dword_1932B8;
// 1932C0: using guessed type int dword_1932C0;
// 1932C4: using guessed type int dword_1932C4;
// 1999CC: using guessed type int16_t word_1999CC;
// 1999CE: using guessed type int16_t word_1999CE;
// 1999D4: using guessed type int16_t word_1999D4;
// 1999D6: using guessed type int16_t word_1999D6;
// 1999DA: using guessed type int16_t word_1999DA;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BBA: using guessed type int16_t word_199BBA;
// 199BC8: using guessed type char byte_199BC8;
// 199BC9: using guessed type char byte_199BC9;
// 199BCA: using guessed type char byte_199BCA;
// 199BCB: using guessed type char byte_199BCB;
// 199BCC: using guessed type char byte_199BCC;


//----- (0006FF08) --------------------------------------------------------
void sub_6FF08()
{
  int16_t v0; // ax
  int16_t v1; // ax
  int16_t v2; // ax
  int16_t v3; // di
  int16_t v4; // si
  int v5; // eax
  int v6; // eax
  int16_t v7; // dx
  int16_t v8; // bx
  int16_t v9; // ax
  int16_t v10; // ax
  int v11; // edx
  int16_t v12; // [esp+0h] [ebp-20h]
  int v13; // [esp+4h] [ebp-1Ch]
  int16_t v14; // [esp+10h] [ebp-10h]
  int16_t v15; // [esp+14h] [ebp-Ch]
  int16_t v16; // [esp+18h] [ebp-8h]
  int16_t i; // [esp+1Ch] [ebp-4h]

  v15 = -1;
  v16 = -1;
  sub_7836A(word_1999B8);
  if ( v0 == word_199A06 )
  {
    sub_7836A(word_1999B8);
    v2 = sub_71465(v1);
    sub_71A37(v2);
    word_193026 = -1000;
    v3 = word_19301C;
    v4 = word_19301E;
    word_193022 = sub_11438B(
                    word_19301C,
                    word_19301E,
                    word_19301C + *(_WORD *)dword_199BBE,
                    word_19301E + 35,
                    &unk_1792A6,
                    0);
    v5 = word_1999FE + word_1999FC;
    if ( word_199BB8 <= v5 )
      LOWORD(v5) = word_199BB8;
    v14 = v5;
    for ( i = word_1999FC; i < v14; ++i )
    {
      v6 = 9 * i;
      v7 = *(int16_t *)((char *)&word_197FBD + v6);
      v8 = *(int16_t *)((char *)&word_197FBF + v6);
      if ( v15 < 0 )
        v15 = *(int16_t *)((char *)&word_197FBD + 9 * i);
      if ( v16 < 0 )
        v16 = *(int16_t *)((char *)&word_197FBF + 9 * i);
      v13 = i;
      sub_78013(i);
      *(int16_t *)((char *)&word_197FC1 + 9 * v13) = sub_11438B(v7, v8, v7 + 53, v8 + 53, &unk_1792A6, 41);
    }
    sub_7836A(word_1999B8);
    v10 = *(int16_t *)((char *)&word_1975D4 + 5 * v9);
    if ( word_1992E8[0] == 2
      && v12
      && (v11 = v10, sub_77FF5(v10) == word_19999C)
      && sub_7843D(word_19999C, 129 * v11 + dword_197F9C) )
    {
      word_199982 = sub_11C3C5(
                      v3 + 16 + (byte_199BC6 == 1),
                      (int16_t)(v4 + word_199BBC),
                      (int)&unk_1792A6,
                      (int16_t *)dword_19328C,
                      &unk_1792A6,
                      40);
    }
    else
    {
      word_199982 = -1000;
    }
    if ( word_199BB8 > 9 )
    {
      word_19994E = -1000;
      word_199950 = -1000;
      if ( v12 )
      {
        word_19994E = (uint16_t)sub_1151B0(
                                          v3 + 191,
                                          v4 + 42,
                                          (int)&unk_1792A6,
                                          (_WORD *)dword_193294,
                                          asc_1792A7,
                                          40);
        word_199950 = (uint16_t)sub_1151B0(
                                          v3 + 191,
                                          v4 + 174,
                                          (int)&unk_1792A6,
                                          (_WORD *)dword_1932A4,
                                          asc_1792A9,
                                          40);
      }
      word_199EE0 = word_19994E;
      word_199EE2 = word_199950;
      word_199A00 = sub_115478(v3 + 192, v4 + 66, 0, 102, 0, 102, 10, 102, (int)&word_199ED0, &unk_1792A6, 0);
    }
    word_1999CC = -1000;
    word_1999CE = -1000;
    word_1999DA = -1000;
    word_1999D6 = -1000;
    word_1999D4 = -1000;
    sub_6FD24(v3, v4);
    sub_905B8(2);
  }
  JUMPOUT(0x6FF02);
}
// 70205: control flows out of bounds to 6FF02
// 6FF32: variable 'v0' is possibly undefined
// 6FF41: variable 'v1' is possibly undefined
// 7004F: variable 'v9' is possibly undefined
// 7006D: variable 'v12' is possibly undefined
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 193022: using guessed type int16_t word_193022;
// 193026: using guessed type int16_t word_193026;
// 19328C: using guessed type int dword_19328C;
// 193294: using guessed type int dword_193294;
// 1932A4: using guessed type int dword_1932A4;
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 197FBD: using guessed type int16_t word_197FBD;
// 197FBF: using guessed type int16_t word_197FBF;
// 197FC1: using guessed type int16_t word_197FC1;
// 1992E8: using guessed type int16_t word_1992E8[5];
// 19994E: using guessed type int16_t word_19994E;
// 199950: using guessed type int16_t word_199950;
// 199982: using guessed type int16_t word_199982;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999CC: using guessed type int16_t word_1999CC;
// 1999CE: using guessed type int16_t word_1999CE;
// 1999D4: using guessed type int16_t word_1999D4;
// 1999D6: using guessed type int16_t word_1999D6;
// 1999DA: using guessed type int16_t word_1999DA;
// 1999FC: using guessed type int16_t word_1999FC;
// 1999FE: using guessed type int16_t word_1999FE;
// 199A00: using guessed type int16_t word_199A00;
// 199A06: using guessed type int16_t word_199A06;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BBC: using guessed type int16_t word_199BBC;
// 199BBE: using guessed type int dword_199BBE;
// 199BC6: using guessed type char byte_199BC6;
// 199ED0: using guessed type int16_t word_199ED0;
// 199EE0: using guessed type int16_t word_199EE0;
// 199EE2: using guessed type int16_t word_199EE2;


//----- (0007020A) --------------------------------------------------------
_BOOL1 sub_7020A()
{
  _BYTE v1[1000]; // [esp+0h] [ebp-3E8h] BYREF

  return (int16_t)sub_7802A((int)v1, 500) > 0;
}


//----- (0007022D) --------------------------------------------------------
_BOOL1 sub_7022D( int a1)
{
  _BOOL1 v2; // al

  v2 = a1 > -1 && *(int16_t *)(dword_1930D4 + 17 * a1) == -1;
  return v2 && !sub_79C1D(a1);
}
// 1930D4: using guessed type int dword_1930D4;


//----- (000702C5) --------------------------------------------------------
int sub_702C5()
{
  int result; // eax
  int v1; // edx

  result = 0;
  do
  {
    v1 = 5 * (int16_t)result;
    byte_199F08 = 0;
    ++result;
    byte_1975D8[v1] = 0;
  }
  while ( (int16_t)result < 500 );
  return result;
}
// 199F08: using guessed type char byte_199F08;


//----- (000702EA) --------------------------------------------------------
void sub_702EA( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // ebx
  int v7; // edx
  int16_t v8; // cx
  int v9; // eax
  int16_t v10; // ax
  int v11; // edi
  int v12; // esi
  int v13; // esi
  int v14; // edi
  int16_t v15; // [esp+1Ch] [ebp-18h]
  int16_t v16; // [esp+20h] [ebp-14h]
  int16_t v17; // [esp+24h] [ebp-10h]
  int16_t v18; // [esp+28h] [ebp-Ch]
  int16_t v19; // [esp+2Ch] [ebp-8h]
  int16_t v20; // [esp+30h] [ebp-4h]

  v19 = a1 + a5;
  v6 = a3 - 4;
  v20 = sub_5F2F6(a6, a2, v6, a4);
  v7 = a4 + a2;
  v8 = sub_5F2C3(a6, v7, v6, a4);
  v17 = v7 - 5;
  v9 = v8 * (int16_t)v6 / v20;
  if ( v9 <= 2 )
    LOWORD(v9) = 2;
  v16 = v9;
  v10 = v6 - v9;
  v15 = v10;
  if ( v8 != v20 )
  {
    if ( v10 == 1 )
    {
      v15 = 2;
      v16 = v6 - 2;
    }
    if ( v16 > 0 )
    {
      v11 = (int16_t)(v16 + v19);
      v12 = (int16_t)(v17 + 4);
      sub_134D2D(v19, v17, v11, v17, 112);
      sub_134D2D(v19, v17, v19, v12, 112);
      sub_134D2D(v11, (int16_t)(v17 + 1), v11, v12, 114);
      sub_134D2D(v11, v12, (int16_t)(v19 + 1), v12, 114);
      sub_128C32((int16_t)(v19 + 1), (int16_t)(v17 + 1), (int16_t)(v16 + v19 - 1), (int16_t)(v17 + 3), 113);
    }
    if ( v15 > 1 )
    {
      v18 = v16 + v19 + 1;
      v13 = (int16_t)(v15 + v18);
      v14 = (int16_t)(v17 + 4);
      sub_134D2D(v18, v17, v13, v17, 75);
      sub_134D2D(v18, v17, v18, v14, 75);
      sub_134D2D(v13, (int16_t)(v17 + 1), v13, v14, 78);
      sub_134D2D(v13, v14, (int16_t)(v16 + v19 + 2), v14, 78);
      sub_128C32((int16_t)(v16 + v19 + 2), (int16_t)(v17 + 1), (int16_t)(v15 + v16 + v19), (int16_t)(v17 + 3), 77);
    }
  }
  JUMPOUT(0x705FC);
}
// 704A1: control flows out of bounds to 705FC


//----- (000704A6) --------------------------------------------------------
int16_t sub_704A6(int a1, int a2, int a3, int a4, int a5, int16_t *a6)
{
  int v7; // eax
  int v8; // edi
  int v9; // ecx
  int v10; // ebx
  int v11; // ebx
  int v12; // ebx
  int16_t result; // ax
  int16_t v14; // [esp+8h] [ebp-28h]
  int16_t v15; // [esp+18h] [ebp-18h]
  int16_t v16; // [esp+1Ch] [ebp-14h] BYREF
  int v17; // [esp+20h] [ebp-10h]
  int v18; // [esp+24h] [ebp-Ch]
  int v19; // [esp+28h] [ebp-8h]
  int v20; // [esp+2Ch] [ebp-4h]

  v7 = a3 + a1;
  v15 = v7;
  LOWORD(v7) = word_199BBA;
  v18 = v7;
  LOWORD(v7) = word_199BB2;
  v17 = v7;
  *a6 = a4 + a2;
  sub_8FD71(&v16);
  if ( (int16_t)v18 + (int16_t)a4 + (int16_t)a2 <= 421 )
    v14 = v18 + a4 + a2;
  else
    v14 = 421;
  v8 = a3 + a1;
  v20 = a4 + a2;
  v19 = v8 + v17;
  sub_128AB6(v8, a4 + a2, v8 + v17, v14);
  sub_12B634();
  sub_128C32((int16_t)(v8 + 6), (int16_t)(v20 + 41), (int16_t)(v19 - 6), (int16_t)(v20 + 35 + v18 - 6), 0);
  sub_8FD56(v16);
  v9 = sub_127C27((int)aBuffer0Lbx_0, 51, dword_193174);
  sub_12A478(v15, *a6, v9);
  v10 = dword_193174;
  *a6 += *(_WORD *)(v9 + 2);
  dword_1932D4 = sub_127C27((int)aBuffer0Lbx_0, 53, v10);
  sub_12A478(v15, *a6, dword_1932D4);
  v11 = dword_193174;
  *a6 += *(_WORD *)(dword_1932D4 + 2);
  v12 = sub_127C27((int)aBuffer0Lbx_0, 55, v11);
  sub_12A478(v15, *a6, v12);
  result = *(_WORD *)(v12 + 2);
  *a6 += result;
  return result;
}
// 193174: using guessed type int dword_193174;
// 1932D4: using guessed type int dword_1932D4;
// 199BB2: using guessed type int16_t word_199BB2;
// 199BBA: using guessed type int16_t word_199BBA;


//----- (00070602) --------------------------------------------------------
void sub_70602(int a1, int a2, int a3, int a4, int a5, int16_t *a6)
{
  int v6; // eax
  int v7; // eax
  int16_t v8; // di
  int v9; // ebx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int16_t v13; // dx
  int16_t v14; // di
  int16_t v15; // [esp+8h] [ebp-24h]
  int16_t v16; // [esp+Ch] [ebp-20h] BYREF
  int v17; // [esp+10h] [ebp-1Ch]
  int v18; // [esp+14h] [ebp-18h]
  int v19; // [esp+18h] [ebp-14h]
  int v20; // [esp+1Ch] [ebp-10h]
  int v21; // [esp+20h] [ebp-Ch]
  int v22; // [esp+24h] [ebp-8h]
  int v23; // [esp+28h] [ebp-4h]

  v17 = a1;
  v6 = (a5 - 1) / 3 + 1;
  if ( v6 > 3 )
    v6 = 3;
  v22 = v6;
  LOWORD(v6) = word_199BBA;
  v19 = v6;
  LOWORD(v6) = word_199BB2;
  v20 = v6;
  *a6 = a4 + a2;
  sub_8FD71(&v16);
  v7 = a2 + a4 + (int16_t)v19;
  if ( v7 > 421 )
    LOWORD(v7) = 421;
  v18 = a3 + v17;
  v15 = v20 + a3 + v17;
  v8 = a3 + v17;
  sub_128AB6(a3 + v17, a4 + a2, v15, (int16_t)v7);
  sub_12B634();
  sub_128C32((int16_t)(v18 + 6), (int16_t)(a4 + a2 + 41), (int16_t)(v15 - 6), (int16_t)(a4 + a2 + 35 + v19 - 6), 0);
  sub_8FD56(v16);
  v21 = v18;
  v9 = dword_193174;
  *a6 = a4 + a2;
  v10 = sub_127C27((int)aBuffer0Lbx_0, 52, v9);
  sub_12A478(v8, *a6, v10);
  *a6 += *(_WORD *)(v10 + 2);
  v11 = (int16_t)v22;
  LOWORD(v11) = sub_71198(v22);
  v23 = v11;
  v12 = *a6 + (int16_t)v11;
  if ( v12 >= 421 )
    LOWORD(v12) = 421;
  v13 = v12;
  v14 = v21;
  sub_8FD71(&v16);
  sub_128AB6(v14, *a6, v20 + v21, v13);
  sub_12B634();
  dword_1932BC = sub_127C27((int)aBuffer0Lbx_0, 54, dword_193174);
  sub_12A478(v14, *a6, dword_1932BC);
  sub_8FD56(v16);
  JUMPOUT(0x705D4);
}
// 70786: control flows out of bounds to 705D4
// 193174: using guessed type int dword_193174;
// 1932BC: using guessed type int dword_1932BC;
// 199BB2: using guessed type int16_t word_199BB2;
// 199BBA: using guessed type int16_t word_199BBA;


//----- (0007078B) --------------------------------------------------------
int sub_7078B(int a1, int a2, int a3, int a4)
{
  int16_t v4; // si
  int16_t v5; // di
  int16_t v7; // [esp+4h] [ebp-18h]
  int16_t v8; // [esp+8h] [ebp-14h]
  int16_t v9; // [esp+Ch] [ebp-10h]
  int v10; // [esp+10h] [ebp-Ch]
  int16_t v11; // [esp+14h] [ebp-8h]
  uint8_t v12; // [esp+18h] [ebp-4h]

  v9 = word_199BAC;
  v8 = word_19302C;
  LOWORD(a1) = word_19302E;
  LOWORD(a4) = word_199BAE;
  v12 = 116;
  v4 = 0;
  v7 = word_199BAE + word_19302E;
  v5 = word_19302C + word_199BAC + 192;
  v10 = word_199EDE - (word_199ED0 + word_199ED6 / 2) + a4 + a1 + 67;
  v11 = word_199ED6 + v10;
  do
  {
    sub_134D2D(v5, (int16_t)v10, v5, v11, v12);
    if ( !(v4 % 2) )
      --v12;
    ++v4;
    ++v5;
  }
  while ( v4 < 9 );
  dword_193270 = sub_127C27((int)aBuffer0Lbx_0, 57, dword_193174);
  return sub_12A478(v8 + v9 + 189, v7 + 66, dword_193270);
}
// 19302C: using guessed type int16_t word_19302C;
// 19302E: using guessed type int16_t word_19302E;
// 193174: using guessed type int dword_193174;
// 193270: using guessed type int dword_193270;
// 199BAC: using guessed type int16_t word_199BAC;
// 199BAE: using guessed type int16_t word_199BAE;
// 199ED0: using guessed type int16_t word_199ED0;
// 199ED6: using guessed type int16_t word_199ED6;
// 199EDE: using guessed type int16_t word_199EDE;


//----- (00070875) --------------------------------------------------------
void sub_70875()
{
  char v0; // dl
  int v1; // eax
  int v2; // eax
  int16_t v3; // ax
  int16_t v4; // ax
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char *v9; // eax
  int16_t v10; // di
  int16_t v11; // dx
  int v12; // eax
  int16_t v13; // bx
  int v14; // eax
  int v15; // eax
  int16_t v16; // di
  int v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // esi
  int v21; // ecx
  int v22; // edx
  int v23; // ebx
  int16_t v24; // si
  int v25; // eax
  int16_t v26; // cx
  int v27; // eax
  int v28; // ebx
  int16_t v29; // cx
  int v30; // edx
  int16_t v31; // ax
  int v32; // eax
  int v33; // edx
  int v34; // eax
  char v35[120]; // [esp+0h] [ebp-9Eh] BYREF
  char v36[88]; // [esp+78h] [ebp-26h] BYREF
  char v37[8]; // [esp+D0h] [ebp+32h] BYREF
  int v38; // [esp+D8h] [ebp+3Ah]
  int v39; // [esp+DCh] [ebp+3Eh]
  int v40; // [esp+E0h] [ebp+42h]
  int v41; // [esp+E4h] [ebp+46h]
  int v42; // [esp+E8h] [ebp+4Ah]
  int16_t v43; // [esp+ECh] [ebp+4Eh] BYREF
  int v44; // [esp+F0h] [ebp+52h]
  int v45; // [esp+F4h] [ebp+56h]
  int v46; // [esp+F8h] [ebp+5Ah]
  int v47; // [esp+FCh] [ebp+5Eh]
  int v48; // [esp+100h] [ebp+62h]
  int v49; // [esp+104h] [ebp+66h]
  int v50; // [esp+108h] [ebp+6Ah]
  int v51; // [esp+10Ch] [ebp+6Eh]
  int v52; // [esp+110h] [ebp+72h]
  int v53; // [esp+114h] [ebp+76h]
  int v54; // [esp+118h] [ebp+7Ah]
  char v55; // [esp+11Ch] [ebp+7Eh]

  LOWORD(v52) = 0;
  v0 = 113;
  do
  {
    v1 = (int16_t)v52;
    v36[(int16_t)v52 + 80] = 108;
    if ( (_WORD)v52 )
      v37[v1] = v0;
    else
      v37[v1] = 110;
    LOWORD(v52) = v52 + 1;
    ++v0;
  }
  while ( (int16_t)v52 < 8 );
  LOWORD(v1) = word_19302C;
  v47 = v1;
  LOWORD(v1) = word_19302E;
  v48 = v1;
  sub_7836A(word_1999B8);
  v49 = v2;
  v46 = v2;
  if ( (_WORD)v2 == word_199A06 )
  {
    v55 = 0;
  }
  else
  {
    sub_7836A(word_1999B8);
    v4 = sub_71465(v3);
    v5 = v4;
    sub_71A37(v4);
    v6 = (v5 + 2) / 3;
    if ( v6 <= 1 )
      LOWORD(v6) = 1;
    word_199EDA = 3;
    word_199EDE = 102;
    word_199ED8 = v6;
    word_199EDC = 0;
    word_199ED6 = sub_A00F1(&word_199ED0);
    v55 = 1;
    word_199ED2 = -1;
    byte_199EE8 = 2;
    byte_199EEA = 1;
    dword_1975C4 = (int)&word_199ED0;
    word_199ED0 = word_199EDE - word_199ED6 / 2;
    sub_77BF1();
  }
  v7 = sub_77FE9(v49);
  v40 = v7;
  if ( (_WORD)v7 != word_199966 )
    word_199966 = v7;
  v8 = sub_72590();
  LOWORD(v8) = word_199BAC;
  v51 = v8;
  LOWORD(v8) = word_199BAE;
  v50 = v8;
  LOWORD(v8) = word_199BB2;
  v54 = v8;
  if ( !byte_199F23 )
  {
    if ( byte_199BC6 )
      sub_70602((int16_t)v51, v50, (int16_t)v47, v48, word_199BB8, &v43);
    else
      sub_704A6((int16_t)v51, (int16_t)v50, (int16_t)v47, (int16_t)v48, word_199BB8, &v43);
    sub_70F02(v47 + v51, v48 + v50);
    if ( (int16_t)v40 >= 9 )
    {
      sub_8F6F8(4u, 75, 78, v37);
      strcpy(v35, (char *)(129 * *(int16_t *)((char *)&word_1975D4 + 5 * (int16_t)v46) + dword_197F9C));
      sub_132F5C((int)v35);
      sub_120D79(4, (int)v37);
      sub_120DED(2, 1);
    }
    else
    {
      byte_199F34 = 113;
      sub_8F6F8(4u, 111, 115, v37);
      sub_784A0(v40, v36);
      v9 = sub_7A990(0x66u);
      sprintf(v35, v9, v36);
      sub_120D79(4, (int)v37);
      sub_120DED(2, 1);
      sub_120E8C(1);
    }
    sub_1210FD(v51 + v47 + (int16_t)v54 / 2, v48 + v50 + 14, (int)v35);
  }
  if ( word_199A06 != (_WORD)v46 || word_199A06 == -1 )
  {
    memset(&unk_197FBC, 0, 4500);
    word_1999FE = 0;
  }
  v10 = 0;
  v11 = 0;
  word_1999FC = 3 * word_199EDC;
  while ( !v10 && word_199A06 != (_WORD)v46 )
  {
    if ( (int16_t)v49 == -1 || v11 >= 500 )
      v10 = 1;
    if ( word_1999FE < 9 )
      ++word_1999FE;
    if ( v11 >= 500 )
      break;
    v12 = 9 * v11;
    v13 = v49;
    *(int16_t *)((char *)&word_197FC1 + v12) = -1000;
    *(int16_t *)((char *)&word_197FC3 + v12) = v13;
    v14 = 5 * v13;
    LOWORD(v14) = *(int16_t *)((char *)&word_1975D6 + v14);
    v49 = v14;
    ++v11;
    if ( (int16_t)v14 == -1 )
      v10 = 1;
  }
  if ( byte_199F00 && byte_199BE1 && (_WORD)v40 == word_19999C )
    sub_7229E(1, 1);
  if ( v55 )
    sub_77B4E();
  v15 = word_199BB8;
  v16 = 0;
  if ( word_199BB8 > word_1999FE + word_1999FC )
    v15 = word_1999FE + word_1999FC;
  v39 = v15;
  LOWORD(v52) = word_1999FC;
  v44 = v47 + v51;
  v42 = v48 + v50;
  while ( (int16_t)v52 < (int16_t)v39 && !byte_199F23 )
  {
    v17 = 9 * (int16_t)v52;
    v18 = 5 * *(int16_t *)((char *)&word_197FC3 + v17);
    LOWORD(v18) = *(int16_t *)((char *)&word_1975D4 + v18);
    v53 = v18;
    saveSlotInfo_199699[1 + v16/37].name[0] = v52;
    v19 = 129 * (int16_t)v53;
    v20 = v44 + 58 * (v16 % 3) + 14;
    v41 = 2;
    *(int16_t *)((char *)&word_197FBD + v17) = v20;
    v21 = v42 + 56 * (v16 / 3) + 38;
    v22 = dword_197F9C;
    *(int16_t *)((char *)&word_197FBF + v17) = v21;
    v45 = 2;
    if ( *(_BYTE *)(v22 + v19 + 16) == 5 )
      v45 = 0;
    v23 = (int16_t)v52;
    if ( sub_77F5D(v52) == 1 )
    {
      v38 = dword_19340C;
      sub_12A478(v20 + (byte_199BC6 == 1), v21, dword_19340C);
      v24 = v41 + v20;
      v25 = *(int16_t *)((char *)&word_197FC3 + 9 * (int16_t)v52);
      v26 = v45 + v21;
    }
    else
    {
      v26 = v45 + v21;
      v25 = *(int16_t *)((char *)&word_197FC3 + 9 * v23);
      v24 = v41 + v20;
    }
    v27 = sub_58678(*(int16_t *)((char *)&word_1975D4 + 5 * v25));
    sub_12A478(v24, v26, v27);
    if ( (_WORD)v40 == word_19999C )
    {
      v28 = (int16_t)v52;
      v29 = sub_78013(v52);
      if ( sub_78182(v29) )
        sub_702EA(
          *(int16_t *)((char *)&word_197FBD + 9 * v28) - 1,
          *(int16_t *)((char *)&word_197FBF + 9 * v28),
          53,
          53,
          4,
          v29);
    }
    LOWORD(v52) = v52 + 1;
    ++v16;
  }
  v30 = 129 * *(int16_t *)((char *)&word_1975D4 + 5 * (int16_t)v46);
  sub_585E0(*(char *)(v30 + dword_197F9C + 99), v30);
  word_199A06 = v46;
  if ( !byte_199F23 )
  {
    sub_71506();
    if ( word_199BB8 > 9 )
      sub_A0226(&word_199ED0, (void (*)(_DWORD))sub_7078B);
  }
  byte_199F00 = 0;
  if ( byte_199F23 )
  {
    sub_78800(word_199A06);
    v32 = 6 * v31;
    v33 = (int16_t)(word_1906CA[v32] + 3);
    v34 = (int16_t)(word_1906C8[v32] + 3);
    byte_199F23 = 0;
    sub_83EFD(v34, v33, word_19301C, word_19301E, word_19301A, word_193018, 2);
    sub_70875();
  }
  if ( !byte_199F1B )
  {
    byte_199F1B = -1;
    sub_6F280();
  }
  JUMPOUT(0x7086F);
}
// 70EFD: control flows out of bounds to 7086F
// 708D6: variable 'v2' is possibly undefined
// 708F6: variable 'v3' is possibly undefined
// 70E92: variable 'v31' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 193018: using guessed type int16_t word_193018;
// 19301A: using guessed type int16_t word_19301A;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 19302C: using guessed type int16_t word_19302C;
// 19302E: using guessed type int16_t word_19302E;
// 19340C: using guessed type int dword_19340C;
// 1975C4: using guessed type int dword_1975C4;
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;
// 197FBD: using guessed type int16_t word_197FBD;
// 197FBF: using guessed type int16_t word_197FBF;
// 197FC1: using guessed type int16_t word_197FC1;
// 197FC3: using guessed type int16_t word_197FC3;
// 1996AC: using guessed type int16_t word_1996AC[9];
// 199966: using guessed type int16_t word_199966;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999FC: using guessed type int16_t word_1999FC;
// 1999FE: using guessed type int16_t word_1999FE;
// 199A06: using guessed type int16_t word_199A06;
// 199BAC: using guessed type int16_t word_199BAC;
// 199BAE: using guessed type int16_t word_199BAE;
// 199BB2: using guessed type int16_t word_199BB2;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BC6: using guessed type char byte_199BC6;
// 199BE1: using guessed type char byte_199BE1;
// 199ED0: using guessed type int16_t word_199ED0;
// 199ED2: using guessed type int16_t word_199ED2;
// 199ED6: using guessed type int16_t word_199ED6;
// 199ED8: using guessed type int16_t word_199ED8;
// 199EDA: using guessed type int16_t word_199EDA;
// 199EDC: using guessed type int16_t word_199EDC;
// 199EDE: using guessed type int16_t word_199EDE;
// 199EE8: using guessed type char byte_199EE8;
// 199EEA: using guessed type char byte_199EEA;
// 199F00: using guessed type char byte_199F00;
// 199F1B: using guessed type char byte_199F1B;
// 199F23: using guessed type char byte_199F23;
// 199F34: using guessed type char byte_199F34;


//----- (00070F02) --------------------------------------------------------
void sub_70F02( int a1, int a2)
{
  int v2; // ebx
  int16_t v3; // si
  int16_t v4; // di
  int16_t v5; // cx
  int16_t v6; // dx
  int16_t v7; // dx
  int16_t v8; // dx
  int v9; // [esp+0h] [ebp-24h]
  int v10; // [esp+4h] [ebp-20h]
  int v11; // [esp+8h] [ebp-1Ch]
  int v12; // [esp+Ch] [ebp-18h]
  int v13; // [esp+10h] [ebp-14h]
  int16_t v14; // [esp+14h] [ebp-10h]
  int16_t v15; // [esp+20h] [ebp-4h]

  v14 = word_199BBA;
  v2 = dword_193278;
  v3 = *(_WORD *)(dword_193278 + 2);
  if ( word_199BB8 <= 9 )
  {
    v10 = dword_1932C4;
    v9 = dword_1932B8;
    v12 = dword_193280;
    v11 = dword_193288;
    v13 = dword_19329C;
    v2 = dword_1931B8;
  }
  else
  {
    v10 = dword_193284;
    v9 = dword_1932A0;
    v12 = dword_193290;
    v11 = dword_1932B4;
    v13 = dword_1932C0;
  }
  v4 = a1 + 2;
  sub_12B726(v2);
  v15 = v14 + a2 - v3;
  v5 = v3;
  sub_12A478(v4, v15, v2);
  if ( byte_199BCC )
  {
    sub_12B726(v11);
    v5 = 2 * v3;
    sub_12A478(v4, v14 + a2, v11);
  }
  if ( byte_199BCA )
  {
    sub_12B726(v9);
    v6 = v5 + v15;
    v5 += v3;
    sub_12A478(v4, v6, v9);
  }
  if ( byte_199BC9 )
  {
    sub_12B726(v13);
    v7 = v5 + v15;
    v5 += v3;
    sub_12A478(v4, v7, v13);
  }
  if ( byte_199BCB )
  {
    sub_12B726(v12);
    v8 = v5 + v15;
    v5 += v3;
    sub_12A478(v4, v8, v12);
  }
  if ( byte_199BC8 )
  {
    sub_12B726(v10);
    sub_12A478(v4, v15 + v5, v10);
  }
  JUMPOUT(0x6FF02);
}
// 71096: control flows out of bounds to 6FF02
// 1931B8: using guessed type int dword_1931B8;
// 193278: using guessed type int dword_193278;
// 193280: using guessed type int dword_193280;
// 193284: using guessed type int dword_193284;
// 193288: using guessed type int dword_193288;
// 193290: using guessed type int dword_193290;
// 19329C: using guessed type int dword_19329C;
// 1932A0: using guessed type int dword_1932A0;
// 1932B4: using guessed type int dword_1932B4;
// 1932B8: using guessed type int dword_1932B8;
// 1932C0: using guessed type int dword_1932C0;
// 1932C4: using guessed type int dword_1932C4;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BBA: using guessed type int16_t word_199BBA;
// 199BC8: using guessed type char byte_199BC8;
// 199BC9: using guessed type char byte_199BC9;
// 199BCA: using guessed type char byte_199BCA;
// 199BCB: using guessed type char byte_199BCB;
// 199BCC: using guessed type char byte_199BCC;


//----- (0007109B) --------------------------------------------------------
int sub_7109B()
{
  int v0; // ebx
  char v1; // cl
  int i; // edx

  v0 = 0;
  v1 = 0;
  for ( i = 0; (int16_t)i < word_199BB8 && !v1; ++i )
  {
    if ( !sub_77F5D(i) )
    {
      v1 = 1;
      v0 = i;
    }
  }
  return v0;
}
// 199BB8: using guessed type int16_t word_199BB8;


//----- (00071198) --------------------------------------------------------
int16_t sub_71198( unsigned int a1)
{
  int16_t result; // ax

  result = 0;
  if ( a1 < 2u )
  {
    if ( a1 == 1 )
      return 56;
  }
  else if ( a1 <= 2u )
  {
    return 112;
  }
  else if ( a1 == 3 )
  {
    dword_1932BC = sub_127C27((int)aBuffer0Lbx_0, 54, dword_193174);
    return *(_WORD *)(dword_1932BC + 2);
  }
  return result;
}
// 193174: using guessed type int dword_193174;
// 1932BC: using guessed type int dword_1932BC;


//----- (000711E6) --------------------------------------------------------
void sub_711E6( int a1)
{
  int v2; // eax
  int v3; // eax

  if ( byte_199BC6 )
  {
    dword_1932B0 = sub_127C27((int)aBuffer0Lbx_0, 52, dword_193174);
    dword_199BBE = dword_1932B0;
    v2 = sub_127C27((int)aBuffer0Lbx_0, 56, dword_193174);
    dword_1932AC = v2;
  }
  else
  {
    dword_193298 = sub_127C27((int)aBuffer0Lbx_0, 51, dword_193174);
    dword_199BBE = dword_193298;
    v2 = sub_127C27((int)aBuffer0Lbx_0, 55, dword_193174);
    dword_1932CC = v2;
  }
  dword_199BC2 = v2;
  if ( a1 <= 9 )
  {
    v3 = (a1 - 1) / 3 + 1;
    if ( v3 > 3 )
      LOWORD(v3) = 3;
    sub_71198(v3);
  }
  else
  {
    dword_1932D4 = sub_127C27((int)aBuffer0Lbx_0, 53, dword_193174);
  }
  JUMPOUT(0x7086E);
}
// 712D3: control flows out of bounds to 7086E
// 193174: using guessed type int dword_193174;
// 193278: using guessed type int dword_193278;
// 193298: using guessed type int dword_193298;
// 1932AC: using guessed type int dword_1932AC;
// 1932B0: using guessed type int dword_1932B0;
// 1932CC: using guessed type int dword_1932CC;
// 1932D4: using guessed type int dword_1932D4;
// 199BBE: using guessed type int dword_199BBE;
// 199BC2: using guessed type int dword_199BC2;
// 199BC6: using guessed type char byte_199BC6;


//----- (000712D8) --------------------------------------------------------
int16_t sub_712D8()
{
  return *(_WORD *)dword_199BBE;
}
// 199BBE: using guessed type int dword_199BBE;


//----- (000712E1) --------------------------------------------------------
int sub_712E1()
{
  int v0; // edx
  int16_t i; // ax

  v0 = 0;
  for ( i = 0; i < word_199BB8; ++i )
  {
    if ( byte_1975D8[5 * *(int16_t *)((char *)&word_197FC3 + 9 * i)] )
      ++v0;
  }
  return v0;
}
// 197FC3: using guessed type int16_t word_197FC3;
// 199BB8: using guessed type int16_t word_199BB8;


//----- (00071315) --------------------------------------------------------
int16_t sub_71315( int a1, int16_t *a2, int16_t *a3, _WORD *a4)
{
  int16_t v5; // ax
  int16_t result; // ax
  int v7; // [esp+4h] [ebp-8h]
  int16_t v8; // [esp+8h] [ebp-4h]

  v7 = 129 * a1;
  v5 = sub_78E07(*(int16_t *)(v7 + dword_197F9C + 101));
  v8 = v5;
  if ( v5 == word_19999A || sub_79E32(word_19999C, v5) )
  {
    *a2 = *(uint8_t *)(dword_197F9C + 129 * a1 + 109);
    result = v8;
    *a3 = v8;
    *a4 = 2;
  }
  else
  {
    result = *(uint8_t *)(v7 + dword_197F9C + 109);
    *a2 = result;
    *a4 = 3;
  }
  return result;
}
// 197F9C: using guessed type int dword_197F9C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;


//----- (0007139F) --------------------------------------------------------
int sub_7139F( int a1, _WORD *a2, _WORD *a3)
{
  int result; // eax

  *a2 = 58 * (a1 % 3) + 14;
  result = 56 * (a1 / 3) + 38;
  *a3 = result;
  return result;
}


//----- (000713CE) --------------------------------------------------------
void sub_713CE(char *a1)
{
  int16_t v2; // dx
  int16_t v3; // ax
  int v4; // esi
  int16_t v5; // bx

  *a1 = 0;
  if ( word_1999CA > -1 )
  {
    v2 = sub_78013(word_1999CA);
    v3 = sub_77FF5(v2);
    v4 = 129 * v2 + dword_197F9C;
    v5 = *(uint8_t *)(v4 + 16);
    if ( v3 != word_19999C )
    {
      if ( v3 <= 8 && sub_78182(v2) )
      {
        sprintf(a1, "%s", (char *)*(&off_18003A + 9 * v5));
        goto LABEL_8;
      }
      v4 = 129 * v2 + dword_197F9C;
    }
    strcpy(a1, (char *)v4);
  }
LABEL_8:
  JUMPOUT(0x7086F);
}
// 71440: control flows out of bounds to 7086F
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 18003A: using guessed type _UNKNOWN *off_18003A;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 1999CA: using guessed type int16_t word_1999CA;


//----- (00071465) --------------------------------------------------------
int sub_71465( int a1)
{
  int i; // ebx
  int v2; // edx

  for ( i = 1; ; ++i )
  {
    v2 = 5 * a1;
    if ( *(int16_t *)((char *)&word_1975D6 + v2) == -1 || (int16_t)i >= 500 )
      break;
    sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * a1));
    a1 = *(int16_t *)((char *)&word_1975D6 + v2);
  }
  return i;
}
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;


//----- (000714A1) --------------------------------------------------------
char sub_714A1( int a1)
{
  char v1; // dl
  int16_t *v2; // eax
  int v3; // eax

  v1 = 0;
  if ( a1 > -1 )
  {
    v2 = (int16_t *)(17 * a1 + dword_1930D4);
    if ( *((_BYTE *)v2 + 4) == 3 )
    {
      v3 = *v2;
      if ( v3 == -1 || *(_BYTE *)(dword_192B18 + 361 * v3 + 6) )
        return 1;
    }
  }
  return v1;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;


//----- (00071506) --------------------------------------------------------
void sub_71506()
{
  int16_t v0; // si
  int v1; // eax
  _BOOL1 v2; // bl
  int v3; // ecx
  int v4; // edx
  int v5; // edx
  int v6; // eax
  int v7; // eax
  uint16_t v8; // ax
  char *v9; // eax
  char *v10; // esi
  uint16_t v11; // ax
  char *v12; // eax
  uint16_t v13; // ax
  uint16_t v14; // ax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  int16_t v18; // bx
  int16_t v19; // dx
  uint16_t v20; // ax
  int16_t v21; // ax
  int v22; // [esp-8h] [ebp-Ah]
  int v23; // [esp-8h] [ebp-Ah]
  int v24; // [esp-4h] [ebp-6h]
  int v25; // [esp-4h] [ebp-6h]
  int v26; // [esp-4h] [ebp-6h]
  int v27; // [esp-4h] [ebp-6h]
  char v28[80]; // [esp+0h] [ebp-2h] BYREF
  char v29[8]; // [esp+50h] [ebp+4Eh] BYREF
  char v30[8]; // [esp+58h] [ebp+56h] BYREF
  int v31; // [esp+60h] [ebp+5Eh] BYREF
  int v32; // [esp+64h] [ebp+62h] BYREF
  int v33; // [esp+68h] [ebp+66h] BYREF
  int v34; // [esp+6Ch] [ebp+6Ah]
  int v35; // [esp+70h] [ebp+6Eh]
  int v36; // [esp+74h] [ebp+72h]
  int v37; // [esp+78h] [ebp+76h]
  int v38; // [esp+7Ch] [ebp+7Ah]
  char v39; // [esp+80h] [ebp+7Eh]

  v31 = -1;
  v32 = -1;
  v39 = 1;
  v36 = 3;
  v34 = 2;
  v0 = sub_78013(0);
  v33 = 9;
  v2 = sub_72617();
  if ( byte_199BC6 )
    v3 = 56;
  else
    v3 = 66;
  if ( word_199BB8 <= 9 )
  {
    HIWORD(v1) = HIWORD(dword_199BBE);
    HIWORD(v5) = HIWORD(dword_199BBE);
    LOWORD(v5) = word_199BB4 + *(_WORD *)(dword_199BBE + 2);
    v38 = 112;
    v4 = v5 + 10;
  }
  else
  {
    v38 = 132;
    v4 = 214;
  }
  LOWORD(v1) = word_19302C + word_199BAC;
  v6 = v3 + v1 + 72;
  v35 = v6;
  LOWORD(v6) = word_19302E + word_19301E;
  v37 = v4 + v6;
  if ( word_19995C == -1 && word_1999CA != -1 )
  {
    v33 = 0;
    goto LABEL_44;
  }
  if ( word_19995C == -1 && !v2 )
  {
    if ( word_1999CA == -1 && word_19C186 != -1 )
      word_1999CA = word_19C186;
    if ( word_1999CA == -1 )
    {
      v7 = dword_197F9C + 129 * v0;
      if ( !*(_BYTE *)(v7 + 100) )
      {
        LOWORD(v7) = *(_WORD *)(v7 + 101);
LABEL_18:
        v33 = 1;
LABEL_19:
        v31 = v7;
        goto LABEL_44;
      }
LABEL_20:
      sub_71315(v0, (int16_t *)&v31, (int16_t *)&v32, &v33);
    }
LABEL_44:
    switch ( (int16_t)v33 )
    {
      case 0:
        sub_713CE(v28);
        goto LABEL_71;
      case 1:
        v24 = dword_19306C + 113 * (int16_t)v31;
        v8 = 103;
        goto LABEL_47;
      case 2:
        if ( (_WORD)v32 == word_19999A )
        {
          v10 = sub_7A990(0x68u);
LABEL_59:
          strcpy(v28, v10);
        }
        else
        {
          v25 = dword_19306C + 113 * (int16_t)v32;
          if ( (_WORD)v31 == 1 )
          {
            v22 = 1;
            v11 = 105;
          }
          else
          {
            v22 = (int16_t)v31;
            v11 = 106;
          }
          v12 = sub_7A990(v11);
          sprintf(v28, v12, v22, v25);
        }
LABEL_71:
        if ( v28[0] )
        {
          sub_8FDA1((int)v28, (int)v29, v36, v34, 0, v38, 1);
          if ( v39 )
          {
            v18 = 115;
            v19 = 112;
            v20 = HIWORD(dword_1B61E4);
            byte_199F34 = 113;
          }
          else
          {
            v18 = 80;
            v19 = 75;
            v20 = HIWORD(dword_1B61E4);
          }
          sub_8F6F8(v20, v19, v18, v30);
          sub_8FE0A((int)v30);
          if ( HIWORD(dword_1B61E4) == 1 )
            v37 += 2;
          v21 = sub_12066F((int)v28);
          if ( v21 <= (int16_t)v38 )
            sub_1210FD(v35, v37, (int)v28);
          else
            sub_C5F14((int16_t)v35 - (int16_t)v38 / 2, (int16_t)v37 - 6, v38, 20, (int)v28);
        }
        JUMPOUT(0x70EF6);
      case 3:
        if ( (_WORD)v31 == 1 )
        {
          v24 = 1;
          v8 = 107;
        }
        else
        {
          v24 = (int16_t)v31;
          v8 = 108;
        }
LABEL_47:
        v9 = sub_7A990(v8);
        sprintf(v28, v9, v24);
        goto LABEL_71;
      case 4:
        v13 = 109;
        goto LABEL_58;
      case 5:
        v13 = 110;
        goto LABEL_58;
      case 6:
        v26 = dword_19306C + 113 * (int16_t)v32;
        if ( (_WORD)v31 == 1 )
        {
          v23 = 1;
          v14 = 111;
        }
        else
        {
          v23 = (int16_t)v31;
          v14 = 112;
        }
        v15 = sub_7A990(v14);
        sprintf(v28, v15, v23, v26);
        goto LABEL_65;
      case 7:
        if ( (_WORD)v31 )
        {
          v27 = (int16_t)v31;
          v17 = sub_7A990(0xEBu);
          sprintf(v28, v17, v27);
        }
        else
        {
          v16 = sub_7A990(0x71u);
          sprintf(v28, v16);
        }
LABEL_65:
        v39 = 0;
        goto LABEL_71;
      case 8:
        v13 = 115;
LABEL_58:
        v10 = sub_7A990(v13);
        v39 = 0;
        goto LABEL_59;
      case 9:
        v28[0] = 0;
        goto LABEL_71;
      default:
        goto LABEL_71;
    }
  }
  v7 = word_19995C;
  if ( word_19995C == -1 && v2 )
  {
    v7 = dword_197F9C + 129 * v0;
    if ( !*(_BYTE *)(v7 + 100) )
    {
      v33 = 1;
      LOWORD(v7) = *(_WORD *)(v7 + 101);
      goto LABEL_19;
    }
    goto LABEL_20;
  }
  if ( word_19995C <= -1 || !v2 )
    goto LABEL_44;
  if ( byte_1992AD )
  {
    if ( !byte_1992AC )
    {
      LOWORD(v7) = word_19995C;
      goto LABEL_18;
    }
    if ( !sub_79E32(word_19999C, word_19995C) )
    {
      LOWORD(v7) = (uint8_t)byte_1992AC;
      v33 = 3;
      goto LABEL_19;
    }
    LOWORD(v7) = (uint8_t)byte_1992AC;
    v31 = v7;
    LOWORD(v7) = word_19995C;
    v33 = 2;
  }
  else
  {
    if ( byte_1992A8 )
    {
      v33 = 4;
      goto LABEL_44;
    }
    if ( byte_1992AA )
    {
      v33 = 5;
      goto LABEL_44;
    }
    if ( !byte_1992AE )
    {
      if ( byte_1992B5 )
        v33 = 8;
      goto LABEL_44;
    }
    if ( !sub_79E32(word_19999C, word_19995C) )
    {
      LOWORD(v7) = (uint8_t)byte_1992B1;
      v33 = 7;
      goto LABEL_19;
    }
    LOWORD(v7) = (uint8_t)byte_1992B1;
    v31 = v7;
    LOWORD(v7) = word_19995C;
    v33 = 6;
  }
  v32 = v7;
  goto LABEL_44;
}
// 719FD: control flows out of bounds to 70EF6
// 715A9: variable 'v1' is possibly undefined
// 71657: variable 'v7' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19301E: using guessed type int16_t word_19301E;
// 19302C: using guessed type int16_t word_19302C;
// 19302E: using guessed type int16_t word_19302E;
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 1992A8: using guessed type char byte_1992A8;
// 1992AA: using guessed type char byte_1992AA;
// 1992AC: using guessed type char byte_1992AC;
// 1992AD: using guessed type char byte_1992AD;
// 1992AE: using guessed type char byte_1992AE;
// 1992B1: using guessed type char byte_1992B1;
// 1992B5: using guessed type char byte_1992B5;
// 19995C: using guessed type int16_t word_19995C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1999CA: using guessed type int16_t word_1999CA;
// 199BAC: using guessed type int16_t word_199BAC;
// 199BB4: using guessed type int16_t word_199BB4;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BBE: using guessed type int dword_199BBE;
// 199BC6: using guessed type char byte_199BC6;
// 199F34: using guessed type char byte_199F34;
// 19C186: using guessed type int16_t word_19C186;
// 1B61E4: using guessed type int dword_1B61E4;


//----- (00071A17) --------------------------------------------------------
int16_t sub_71A17()
{
  int16_t v0; // ax
  int16_t v1; // ax

  if ( !sub_780D3() )
    return sub_91A40();
  sub_7836A(word_1999B8);
  v1 = sub_71465(v0);
  return sub_71A37(v1);
}
// 71A31: variable 'v0' is possibly undefined
// 1999B8: using guessed type int16_t word_1999B8;


//----- (00071A37) --------------------------------------------------------
int16_t sub_71A37( int a1)
{
  int16_t v1; // ax
  int16_t result; // ax
  int16_t v4; // ax
  int16_t v5; // ax

  if ( byte_199F00 )
  {
    byte_199F20 = 0;
    byte_199BC7 = 0;
  }
  if ( a1 <= 9 )
  {
    byte_199BC6 = 1;
    dword_1932AC = sub_127C27((int)aBuffer0Lbx_0, 56, dword_193174);
    dword_199BC2 = dword_1932AC;
    dword_1932B0 = sub_127C27((int)aBuffer0Lbx_0, 52, dword_193174);
    dword_199BBE = dword_1932B0;
    sub_7226A(a1);
    word_199BAC = word_19301C;
    word_199BAE = word_19301E;
    word_199BB2 = *(_WORD *)dword_199BBE;
    sub_711E6(a1);
    word_199BB0 = v1;
    word_199BB4 = word_199962;
    v5 = word_199962 + *(_WORD *)(dword_199BBE + 2);
  }
  else
  {
    byte_199BC6 = 0;
    dword_1932CC = sub_127C27((int)aBuffer0Lbx_0, 55, dword_193174);
    dword_199BC2 = dword_1932CC;
    dword_193298 = sub_127C27((int)aBuffer0Lbx_0, 51, dword_193174);
    dword_199BBE = dword_193298;
    word_199BAC = word_19301C;
    word_199BB2 = *(_WORD *)dword_193298;
    word_199BAE = word_19301E;
    sub_711E6(a1);
    word_199BB0 = v4;
    dword_1932D4 = sub_127C27((int)aBuffer0Lbx_0, 53, dword_193174);
    word_199BB4 = *(_WORD *)(dword_1932D4 + 2);
    v5 = word_199BB4 + *(_WORD *)(dword_199BBE + 2);
  }
  word_199BBC = v5 + 4;
  result = word_199BB0;
  word_199BB8 = a1;
  word_199BBA = word_199BB0;
  if ( !byte_199BC7 )
    return sub_71C01();
  return result;
}
// 71ADA: variable 'v4' is possibly undefined
// 71146: variable 'v1' is possibly undefined
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 193174: using guessed type int dword_193174;
// 193298: using guessed type int dword_193298;
// 1932AC: using guessed type int dword_1932AC;
// 1932B0: using guessed type int dword_1932B0;
// 1932CC: using guessed type int dword_1932CC;
// 1932D4: using guessed type int dword_1932D4;
// 199962: using guessed type int16_t word_199962;
// 199BAC: using guessed type int16_t word_199BAC;
// 199BAE: using guessed type int16_t word_199BAE;
// 199BB0: using guessed type int16_t word_199BB0;
// 199BB2: using guessed type int16_t word_199BB2;
// 199BB4: using guessed type int16_t word_199BB4;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BBA: using guessed type int16_t word_199BBA;
// 199BBC: using guessed type int16_t word_199BBC;
// 199BBE: using guessed type int dword_199BBE;
// 199BC2: using guessed type int dword_199BC2;
// 199BC6: using guessed type char byte_199BC6;
// 199BC7: using guessed type char byte_199BC7;
// 199F00: using guessed type char byte_199F00;
// 199F20: using guessed type char byte_199F20;


//----- (00071B0E) --------------------------------------------------------
int sub_71B0E( int a1, int a2)
{
  int result; // eax

  result = sub_585E0(a1, a2);
  byte_199F1D = 2;
  return result;
}
// 199F1D: using guessed type char byte_199F1D;


//----- (00071B1C) --------------------------------------------------------
char sub_71B1C()
{
  int16_t v0; // ax
  int v1; // ebx
  int16_t v2; // ax
  int16_t i; // cx
  unsigned int v4; // esi

  sub_7836A(word_1999B8);
  v1 = (int16_t)sub_77FE9(v0);
  LOBYTE(v2) = word_19999C;
  if ( v1 == word_19999C )
  {
    for ( i = 0; i < 500; ++i )
    {
      v4 = *(int16_t *)((char *)&word_1975D4 + 5 * i);
      v2 = sub_1276F0((int)byte_199E05, v4);
      byte_1975D8[5 * i] = v2 && (LOBYTE(v2) = sub_8A16A(v4), (_BYTE)v2);
    }
  }
  return v2;
}
// 71B2D: variable 'v0' is possibly undefined
// 1975D4: using guessed type int16_t word_1975D4;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;


//----- (00071B91) --------------------------------------------------------
int sub_71B91()
{
  int16_t v0; // ax
  int result; // eax
  int16_t i; // bx
  int v3; // eax
  int16_t v4; // dx

  sub_7836A(word_1999B8);
  result = sub_77FE9(v0);
  if ( (_WORD)result == word_19999C )
  {
    for ( i = 0; i < word_199BB8; ++i )
    {
      result = *(int16_t *)((char *)&word_197FC3 + 9 * i);
      if ( result != -1 )
      {
        v3 = 5 * result;
        v4 = *(int16_t *)((char *)&word_1975D4 + v3);
        if ( byte_1975D8[v3] )
          result = sub_127712((int)byte_199E05, v4);
        else
          result = sub_12772A((int)byte_199E05, v4);
      }
    }
  }
  return result;
}
// 71BA0: variable 'v0' is possibly undefined
// 1975D4: using guessed type int16_t word_1975D4;
// 197FC3: using guessed type int16_t word_197FC3;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;
// 199BB8: using guessed type int16_t word_199BB8;


//----- (00071C01) --------------------------------------------------------
int16_t sub_71C01()
{
  int16_t v0; // dx
  char v1; // al
  char v2; // al
  char v3; // al
  char v4; // al
  char v5; // al

  byte_19BEBC = 1;
  sub_71F35(word_199BB8);
  v0 = 0;
  byte_199BCA = v1;
  if ( v1 )
  {
    ++byte_19BEBC;
    v0 = *(_WORD *)(dword_1932A0 + 2);
  }
  sub_72346(word_199BB8);
  byte_199BCB = v2;
  if ( v2 )
  {
    ++byte_19BEBC;
    v0 += *(_WORD *)(dword_193290 + 2);
  }
  sub_71DD8(word_199BB8);
  byte_199BCC = v3;
  if ( v3 )
  {
    ++byte_19BEBC;
    v0 += *(_WORD *)(dword_1932B4 + 2);
  }
  sub_7209D(word_199BB8);
  byte_199BC9 = v4;
  if ( v4 )
  {
    ++byte_19BEBC;
    v0 += *(_WORD *)(dword_1932C0 + 2);
  }
  sub_71CE7();
  byte_199BC8 = v5;
  if ( v5 )
  {
    ++byte_19BEBC;
    v0 += *(_WORD *)(dword_193284 + 2);
  }
  word_199BB0 = word_199BBA + v0;
  return sub_721EB();
}
// 71C17: variable 'v1' is possibly undefined
// 71C40: variable 'v2' is possibly undefined
// 71C69: variable 'v3' is possibly undefined
// 71C92: variable 'v4' is possibly undefined
// 71CB4: variable 'v5' is possibly undefined
// 193284: using guessed type int dword_193284;
// 193290: using guessed type int dword_193290;
// 1932A0: using guessed type int dword_1932A0;
// 1932B4: using guessed type int dword_1932B4;
// 1932C0: using guessed type int dword_1932C0;
// 199BB0: using guessed type int16_t word_199BB0;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BBA: using guessed type int16_t word_199BBA;
// 199BC8: using guessed type char byte_199BC8;
// 199BC9: using guessed type char byte_199BC9;
// 199BCA: using guessed type char byte_199BCA;
// 199BCB: using guessed type char byte_199BCB;
// 199BCC: using guessed type char byte_199BCC;
// 19BEBC: using guessed type char byte_19BEBC;


