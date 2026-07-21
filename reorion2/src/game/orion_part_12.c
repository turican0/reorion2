#include "orion_common.h"

/* Adresni rozsah: 0xBBC8B - 0xC5F52  (200 funkci) */

//----- (000BBC8B) --------------------------------------------------------
int sub_BBC8B()
{
  int16_t *v0; // eax
  int16_t *v1; // esi

  sub_BBC6F();
  v1 = v0;
  sub_12D8F5(30, 30, dword_19F7B0);
  sub_12F7E6(1, 1, v1, (int16_t *)dword_19F7B0);
  sub_12E64F((int16_t *)dword_19F7B0, (int16_t *)dword_19F7B0, 237, 0);
  return dword_19F7B0;
}
// BBCA4: variable 'v0' is possibly undefined
// 19F7B0: using guessed type int dword_19F7B0;


//----- (000BBCDC) --------------------------------------------------------
int sub_BBCDC()
{
  return memset(&word_19F99C, -1, 20);
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 19F99C: using guessed type int16_t word_19F99C;


//----- (000BBCF5) --------------------------------------------------------
void sub_BBCF5()
{
  JUMPOUT(0xBBCED);
}
// BBD03: control flows out of bounds to BBCED


//----- (000BBD05) --------------------------------------------------------
int sub_BBD05()
{
  int i; // edx
  int v1; // eax
  int j; // ebx

  for ( i = 0; i < 144; i += 24 )
  {
    v1 = i;
    for ( j = 0; j < 6; ++j )
    {
      if ( *(int *)((char *)dword_182AFD + v1) )
        return 0;
      v1 += 4;
    }
  }
  return 1;
}
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BBD37) --------------------------------------------------------
_BOOL1 sub_BBD37(int a1, int16_t *a2, int16_t *a3)
{
  int16_t v3; // si
  int16_t i; // cx
  int v5; // edi
  _BOOL1 result; // al
  int16_t v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-4h]

  v8 = 0;
  *a2 = 0;
  v3 = 0;
  *a3 = 0;
  while ( v3 < 6 )
  {
    for ( i = 0; i < 6; ++i )
    {
      v5 = dword_182AFD[6 * v3 + i];
      if ( v5 == v7 )
      {
        *a2 = v3;
        result = 1;
        *a3 = i;
        return result;
      }
      if ( !v5 && sub_1247A0((int16_t)++v8) == 1 )
      {
        *a2 = v3;
        *a3 = i;
      }
    }
    ++v3;
  }
  return v7 == -1;
}
// BBD6E: variable 'v7' is possibly undefined
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BBDC9) --------------------------------------------------------
void sub_BBDC9()
{
  int16_t v0; // bx
  int16_t k; // si
  int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  int v5; // ecx
  unsigned int v6; // eax
  int v7; // edi
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // [esp+0h] [ebp-10h]
  int16_t j; // [esp+8h] [ebp-8h]
  int16_t i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 6; ++i )
  {
    v0 = 0;
    for ( j = 0; j < 6; ++j )
    {
      for ( k = 0; k < 6; ++k )
      {
        v2 = j + 1;
        if ( v2 < 6 && k + 1 < 6 )
        {
          v11 = 6 * v2;
          v3 = 4 * k;
          v4 = v3 + v11 * 4;
          v5 = 19 * dword_182B01[v3 / 4 + v11];
          v6 = 24 * j + v3;
          if ( (uint8_t)byte_17EB4B[19 * *(int *)((char *)dword_182AFD + v6)] > (uint8_t)byte_17EB4B[v5]
            && *(int *)((char *)dword_182AFD + v6)
            && *(int *)((char *)dword_182B01 + v4) )
          {
            v0 = *(_WORD *)((char *)dword_182AFD + v6);
            *(int *)((char *)dword_182AFD + v6) = *(int *)((char *)dword_182B01 + v4);
            *(int *)((char *)dword_182B01 + v4) = v0;
          }
          v7 = 4 * k;
          v8 = v7 + 24 * (j + 1);
          v9 = v7 + 24 * j;
          if ( (uint8_t)byte_17EB4B[19 * *(int *)((char *)dword_182AFD + v9)] > (uint8_t)byte_17EB4B[19 * *(int *)((char *)dword_182AFD + v8)]
            && *(int *)((char *)dword_182AFD + v9)
            && *(int *)((char *)dword_182AFD + v8) )
          {
            v0 = *(_WORD *)((char *)dword_182AFD + v9);
            *(int *)((char *)dword_182AFD + v9) = *(int *)((char *)dword_182AFD + v8);
            *(int *)((char *)dword_182AFD + v8) = v0;
          }
          v10 = 24 * j + 4 * k;
          if ( (uint8_t)byte_17EB4B[19 * *(int *)((char *)dword_182AFD + v10)] > (uint8_t)byte_17EB4B[19 * *(int *)((char *)dword_182B01 + v10)]
            && *(int *)((char *)dword_182AFD + v10) )
          {
            if ( *(int *)((char *)dword_182B01 + v10) )
            {
              v0 = *(_WORD *)((char *)dword_182AFD + v10);
              *(int *)((char *)dword_182AFD + v10) = *(int *)((char *)dword_182B01 + v10);
              *(int *)((char *)dword_182B01 + v10) = v0;
            }
          }
        }
      }
    }
    if ( !v0 )
      break;
  }
}
// 182AFD: using guessed type int dword_182AFD[];
// 182B01: using guessed type int dword_182B01[];


//----- (000BBF5E) --------------------------------------------------------
void sub_BBF5E()
{
  int v0; // edx
  int16_t v1; // bx
  int16_t i; // cx
  int v3; // eax

  v0 = 0;
  v1 = 0;
  while ( 1 )
  {
    for ( i = 0; i < 6; ++i )
    {
      v3 = 24 * v1 + 4 * i;
      if ( *(int *)((char *)dword_182AFD + v3) == 3
        || *(int *)((char *)dword_182AFD + v3) == 14
        || *(int *)((char *)dword_182AFD + v3) == 40
        || *(int *)((char *)dword_182AFD + v3) == 41 )
      {
        ++v0;
      }
    }
    if ( ++v1 >= 6 )
      JUMPOUT(0xBA904);
  }
}
// BBFA9: control flows out of bounds to BA904
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BBFAE) --------------------------------------------------------
int sub_BBFAE(int result, _WORD *a2, int16_t *a3)
{
  int16_t i; // cx
  int16_t v4; // si
  int v5; // esi
  int16_t v6; // [esp+4h] [ebp-4h]

  v6 = 1000;
  if ( (result & 0x8000u) == 0 )
  {
    *a2 = 0;
    result = 0;
    *a3 = 0;
    do
    {
      for ( i = 0; i < 6; ++i )
      {
        v4 = dword_182AFD[6 * (int16_t)result + i];
        if ( v4 == 3 || v4 == 14 || v4 == 40 || v4 == 41 )
        {
          *a2 = result;
          v6 = 0;
          *a3 = i;
        }
        else
        {
          v5 = 19 * v4;
          if ( *(int *)((char *)&dword_17EB45 + v5) < v6 )
          {
            *a2 = result;
            *a3 = i;
            v6 = *(_WORD *)((char *)&dword_17EB45 + v5);
          }
        }
      }
      ++result;
    }
    while ( (int16_t)result < 6 );
  }
  return result;
}
// 17EB45: using guessed type int dword_17EB45;
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BC05E) --------------------------------------------------------
int sub_BC05E( int a1, int a2, int a3, int a4)
{
  int16_t v6; // ax
  int v7; // edi
  int v8; // ebx
  int v9; // edx
  int result; // eax
  int v11; // [esp+4h] [ebp-Ch] BYREF
  int v12; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h] BYREF

  v11 = -1;
  v13 = -1;
  sub_BBF5E();
  v7 = (a1 + v6) % 4;
  if ( a3 >= 36 )
  {
    sub_BBFAE(a2, &v11, (int16_t *)&v13);
LABEL_19:
    if ( a2 < 0 )
    {
      result = a2;
      if ( a2 == -3 )
      {
        switch ( (int16_t)(v7 + 1) % 4 )
        {
          case 0:
            result = (int16_t)v13;
            dword_182AFD[6 * (int16_t)v11 + (int16_t)v13] = 3;
            break;
          case 2:
            result = 24 * (int16_t)v11;
            *(int *)((char *)&dword_182AFD[(int16_t)v13] + result) = 40;
            break;
          case 3:
            result = (int16_t)v13;
            dword_182AFD[6 * (int16_t)v11 + (int16_t)v13] = 41;
            break;
          default:
            result = (int16_t)v13;
            dword_182AFD[6 * (int16_t)v11 + (int16_t)v13] = 14;
            break;
        }
      }
      else if ( a2 == -1 )
      {
        result = (int16_t)v13;
        dword_182AFD[6 * (int16_t)v11 + (int16_t)v13] = 8;
      }
    }
    else
    {
      result = (int16_t)v13;
      dword_182AFD[6 * (int16_t)v11 + (int16_t)v13] = a2;
    }
    return result;
  }
  if ( a4 == 1 )
  {
    sub_BEBAE(a3, &v11, &v13);
    goto LABEL_19;
  }
  v12 = 0;
  v8 = 0;
  do
  {
    v9 = 0;
    do
    {
      if ( !dword_182AFD[6 * (int16_t)v8 + (int16_t)v9] && sub_1247A0((int16_t)++v12) == 1 )
      {
        v11 = v8;
        v13 = v9;
      }
      ++v9;
    }
    while ( (int16_t)v9 < 6 );
    ++v8;
  }
  while ( (int16_t)v8 < 6 );
  if ( (int16_t)v11 == -1 || (int16_t)v13 == -1 && a2 != -3 )
    sub_BBFAE(a2, &v11, (int16_t *)&v13);
  result = (int16_t)v11;
  if ( (int16_t)v11 != -1 )
  {
    result = (int16_t)v13;
    if ( (int16_t)v13 != -1 )
      goto LABEL_19;
  }
  return result;
}
// BC07E: variable 'v6' is possibly undefined
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BC21B) --------------------------------------------------------
_BOOL1 sub_BC21B( int a1)
{
  int v2; // eax
  _BOOL1 result; // al

  result = 0;
  if ( a1 == 40 || a1 == 8 )
  {
    if ( a1 == 40 )
    {
      v2 = dword_192B18 + 361 * dword_19F7A8;
      if ( *(_BYTE *)(v2 + 318) || *(_BYTE *)(v2 + 351) )
        return 1;
    }
    if ( a1 == 8 && *(_BYTE *)(dword_192B18 + 361 * dword_19F7A8 + 351) )
      return 1;
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BC27F) --------------------------------------------------------
int sub_BC27F( int a1)
{
  int16_t i; // dx
  int v2; // ebx

  for ( i = 0; i < 10; ++i )
  {
    if ( a1 == word_19F99C[i] )
    {
      word_19F99C[i] = 0;
      if ( word_19F99E[i] )
      {
        v2 = 0;
        do
        {
          ++v2;
          word_19F99C[i] = word_19F99E[i];
        }
        while ( (int16_t)v2 < 9 );
        word_19F9AE = -1;
      }
    }
  }
  byte_182ACA = 1;
  return sub_BC30B((int16_t)dword_19F7A8, 0);
}
// 182ACA: using guessed type char byte_182ACA;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F99C: using guessed type int16_t word_19F99C[];
// 19F99E: using guessed type int16_t word_19F99E[8];
// 19F9AE: using guessed type int16_t word_19F9AE;


//----- (000BC2EE) --------------------------------------------------------
char sub_BC2EE( int a1, int16_t *a2)
{
  int v3; // eax

  LOBYTE(v3) = sub_BC21B(a1);
  if ( !(_BYTE)v3 )
  {
    v3 = *a2;
    word_19F99C[v3] = a1;
    ++*a2;
  }
  return v3;
}
// 19F99C: using guessed type int16_t word_19F99C[];


//----- (000BC30B) --------------------------------------------------------
int sub_BC30B(int a1, int a2)
{
  int16_t v2; // si
  int16_t v3; // di
  int16_t v4; // bx
  int v5; // eax
  int16_t i; // di
  int16_t v7; // cx
  int16_t j; // si
  int16_t k; // di
  int v10; // eax
  int16_t v11; // dx
  int v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int16_t v18; // [esp+0h] [ebp-30h]
  _DWORD v19[2]; // [esp+4h] [ebp-2Ch]
  int v20; // [esp+Ch] [ebp-24h]
  int v21; // [esp+10h] [ebp-20h]
  int v22; // [esp+14h] [ebp-1Ch]
  int16_t v23; // [esp+18h] [ebp-18h] BYREF
  int16_t v24; // [esp+1Ch] [ebp-14h] BYREF
  int v25; // [esp+20h] [ebp-10h]
  int v26; // [esp+24h] [ebp-Ch]
  char v27; // [esp+28h] [ebp-8h]
  char v28; // [esp+2Ch] [ebp-4h]

  v28 = a2;
  v21 = sub_12484C();
  v2 = 0;
  sub_124820(v18);
  v3 = 0;
  memset(dword_182AFD, 0, 144);
  v26 = 0;
  memset(word_19F99C, -1, 20);
  do
  {
    if ( *(_BYTE *)(v3 + dword_192B18 + 361 * v18 + 310) && (v28 && v2 < 18 || !v28) )
    {
      if ( byte_17EB4B[19 * v3] == 7 )
      {
        if ( !sub_BC21B(v3) )
        {
          v5 = (int16_t)v26++;
          word_19F99C[v5] = v3;
        }
      }
      else
      {
        v4 = v2;
        v20 = v18;
        ++v2;
        sub_BC05E(v18, v3, v4, v28);
      }
    }
    ++v3;
  }
  while ( v3 < 49 );
  for ( i = 0; i < *(uint8_t *)(dword_192B18 + 361 * v18 + 10) / 3 + 1; ++i )
  {
    if ( v2 < 36 && (v28 == 1 && v2 < 18 || !v28) )
      sub_BC05E(v18, -3, v2++, v28);
  }
  sub_BBDC9();
  if ( !v28 )
  {
    v7 = 0;
    v19[0] = (char *)&loc_E0002 + 1;
    v19[1] = 2687016;
    do
    {
      if ( sub_BBD37(*((int16_t *)v19 + v7 % 4), &v24, &v23) )
      {
        v27 = 0;
        for ( j = 1; j > -2 && !v27; --j )
        {
          for ( k = 1; k > -2 && !v27; --k )
          {
            v10 = v24 - j;
            if ( v10 < 0 )
              LOWORD(v10) = 0;
            if ( (int16_t)v10 <= 5 )
              v11 = v10;
            else
              v11 = 5;
            v22 = v11;
            v20 = 24 * v11;
            if ( dword_182AFD[7 * v11] && sub_1247A0(3u) == 1 || sub_1247A0(3u) == 1 )
            {
              v12 = 24 * v11;
              v13 = v12 + 4 * (int16_t)v22;
              LOWORD(v12) = *(_WORD *)((char *)dword_182AFD + v13);
              v25 = v12;
              v20 = 24 * v24;
              v14 = v20 + 4 * v23;
              *(int *)((char *)dword_182AFD + v13) = *(int *)((char *)dword_182AFD + v14);
              v27 = 1;
              *(int *)((char *)dword_182AFD + v14) = (int16_t)v25;
            }
          }
        }
      }
      ++v7;
    }
    while ( v7 < 8 );
    if ( sub_BBD37(9, &v24, &v23) && dword_182B19 )
    {
      v15 = 4 * v23 + 24 * v24;
      v16 = (int16_t)dword_182B19;
      dword_182B19 = *(int *)((char *)dword_182AFD + v15);
      *(int *)((char *)dword_182AFD + v15) = v16;
    }
  }
  sub_B6099();
  if ( v28 )
    sub_B6932();
  else
    sub_B6977();
  return sub_124820(v21);
}
// BC4AA: conditional instruction was optimized away because dx.2<6
// BC326: variable 'v18' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 182AFD: using guessed type int dword_182AFD[];
// 182B19: using guessed type int dword_182B19;
// 192B18: using guessed type int dword_192B18;
// 19F99C: using guessed type int16_t word_19F99C[];


//----- (000BC5D8) --------------------------------------------------------
int16_t sub_BC5D8( int a1, int a2, int a3)
{
  return word_182C9C[28 * a1 + 4 * a2 + 2 * a3];
}
// 182C9C: using guessed type int16_t word_182C9C[];


//----- (000BC5F2) --------------------------------------------------------
int16_t sub_BC5F2( int a1, int a2, int16_t *a3, int16_t *a4)
{
  int16_t v4; // di
  int16_t result; // ax

  v4 = a1 + 1;
  *a3 = sub_BC5D8(a1, a2, 0);
  a3[1] = sub_BC5D8(v4, a2, 0);
  a3[2] = sub_BC5D8(v4, a2 + 1, 0);
  a3[3] = sub_BC5D8(a1, a2 + 1, 0);
  *a4 = sub_BC5D8(a1, a2, 1);
  a4[1] = sub_BC5D8(v4, a2, 1);
  a4[2] = sub_BC5D8(v4, a2 + 1, 1);
  result = sub_BC5D8(a1, a2 + 1, 1);
  a4[3] = result;
  return result;
}


//----- (000BC6A5) --------------------------------------------------------
void sub_BC6A5(int16_t *a1, int16_t *a2, int16_t *a3, int16_t *a4, int16_t *a5, int16_t *a6)
{
  int16_t v6; // si
  int16_t v7; // si
  int16_t *v8; // esi
  int16_t v9; // si
  int16_t *v10; // esi
  int16_t v11; // si
  int16_t v12; // si
  int16_t v13; // si
  int16_t *v14; // [esp+0h] [ebp-10h]
  int16_t *v15; // [esp+4h] [ebp-Ch]
  int16_t v16; // [esp+Ch] [ebp-4h]

  v6 = *a1;
  *a3 = *a1;
  *a5 = v6;
  v7 = *a2;
  *a4 = *a2;
  v16 = 1;
  *a6 = v7;
  while ( 1 )
  {
    v8 = &a1[v16];
    if ( *v8 <= *a3 )
      v9 = *v8;
    else
      v9 = *a3;
    *a3 = v9;
    v10 = &a2[v16];
    if ( *v10 <= *a4 )
      v11 = *v10;
    else
      v11 = *a4;
    *a4 = v11;
    v14 = &a1[v16];
    if ( *v14 >= *a5 )
      v12 = *v14;
    else
      v12 = *a5;
    *a5 = v12;
    v15 = &a2[v16];
    if ( *v15 >= *a6 )
      v13 = *v15;
    else
      v13 = *a6;
    ++v16;
    *a6 = v13;
    if ( v16 >= 4 )
      JUMPOUT(0xBC762);
  }
}
// BC75C: control flows out of bounds to BC762


//----- (000BC768) --------------------------------------------------------
_BOOL1 sub_BC768( int a1, int a2, int a3, int a4)
{
  int16_t v4; // di
  int16_t v5; // si
  int16_t v8[4]; // [esp+8h] [ebp-10h] BYREF
  int16_t v9[4]; // [esp+10h] [ebp-8h] BYREF

  v4 = 0;
  v5 = 0;
  sub_BC5F2(a3, a4, v8, v9);
  do
  {
    if ( sub_EB4DD(a1, a2, v8[v5], v9[v5], v8[(v5 + 1) % 4], v9[(v5 + 1) % 4], v8[(v5 + 2) % 4], v9[(v5 + 2) % 4]) > 0 )
      ++v4;
    ++v5;
  }
  while ( v5 < 4 );
  return v4 == 4;
}


//----- (000BC7E3) --------------------------------------------------------
char sub_BC7E3(int16_t *a1)
{
  int16_t i; // cx
  int v2; // ebx
  int v3; // eax
  char result; // al

  for ( i = 0; i < 6; ++i )
  {
    v2 = 0;
    do
    {
      sub_BC811(i, v2);
      sub_1077D(v3, (int16_t)v2, v2, a1);
      ++v2;
      result = sub_6497C();
    }
    while ( (int16_t)v2 < 6 );
  }
  return result;
}
// BC7F5: variable 'v3' is possibly undefined


//----- (000BC811) --------------------------------------------------------
void sub_BC811( int a1, int a2)
{
  int16_t v3[4]; // [esp+0h] [ebp-10h] BYREF
  int16_t v4[4]; // [esp+8h] [ebp-8h] BYREF

  sub_128AB6(0, 0, 639, 479);
  sub_12B634();
  sub_BC5F2(a1, a2, v4, v3);
  sub_C5E2D((int)v4, (int)v3, 1, 2);
  JUMPOUT(0xBC85B);
}
// BC856: control flows out of bounds to BC85B


//----- (000BC866) --------------------------------------------------------
int sub_BC866(int a1, int a2, int a3)
{
  return (dword_182E2C[14 * a1 + 14 + 2 * a2 + a3] + dword_182E24[14 * a1 + 2 * a2 + a3]) / 2;
}
// 182E24: using guessed type int dword_182E24[];
// 182E2C: using guessed type int dword_182E2C[96];


//----- (000BC8A6) --------------------------------------------------------
int sub_BC8A6(int a1, int a2)
{
  int v3; // eax

  v3 = 6 * a2;
  if ( a2 % 2 )
    return v3 + 5 - a1;
  else
    return a1 + v3;
}


//----- (000BC8DF) --------------------------------------------------------
int sub_BC8DF(int a1)
{
  int16_t v1; // ax

  switch ( *(_BYTE *)(361 * a1 + dword_192B18 + 11) )
  {
    case 0xFF:
      v1 = 12;
      break;
    case 0:
      v1 = 600;
      break;
    case 1:
      v1 = 601;
      break;
    case 2:
      v1 = 602;
      break;
    default:
      v1 = 602;
      break;
  }
  return sub_CDF5C(v1);
}
// 192B18: using guessed type int dword_192B18;


//----- (000BC928) --------------------------------------------------------
void sub_BC928()
{
  word_182AB9 = 0;
}
// 182AB9: using guessed type int16_t word_182AB9;


//----- (000BC932) --------------------------------------------------------
char sub_BC932( int a1)
{
  int16_t i; // ax
  int v4; // edx

  for ( i = 0; ; ++i )
  {
    v4 = 361 * a1 + dword_192B18;
    if ( i >= *(uint8_t *)(v4 + 10) )
      break;
    if ( (*(_DWORD *)(v4 + 4 * i + 12) & 0xF) == 8 )
      return 1;
  }
  return 0;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BC972) --------------------------------------------------------
int16_t sub_BC972( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int16_t i; // bx
  int16_t v8; // ax
  unsigned int v9; // eax

  word_19F9FA = 0;
  for ( i = 0; i < *(uint8_t *)(361 * a1 + dword_192B18 + 10); ++i )
  {
    v8 = sub_BADCC(a1, i);
    if ( (*(uint8_t *)(dword_197F98 + 3753 * v8 + 37) != a4
       || (*(_DWORD *)(361 * a1 + dword_192B18 + 4 * i + 12) & 0xF) != v8)
      && a4 != -1 )
    {
      v9 = *(_DWORD *)(361 * a1 + dword_192B18 + 4 * i + 12) & 0xF;
      if ( v9 < 0xE || v9 != a4 )
        continue;
    }
    if ( ((uint16_t)sub_BCACF(a1, i) == a3 || a3 == -1)
      && (*(_DWORD *)(361 * a1 + dword_192B18 + 4 * i + 12) << 23 >> 30 == a2 || a2 == -1)
      && (*(_DWORD *)(dword_192B18 + 361 * a1 + 4 * i + 12) << 21 >> 31 == a6 || a6 == -1)
      && (*(_BYTE *)(361 * a1 + dword_192B18 + 4 * i + 13) & 2) != 0 )
    {
      ++word_19F9FA;
    }
  }
  return word_19F9FA;
}
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 19F9FA: using guessed type int16_t word_19F9FA;


//----- (000BCACF) --------------------------------------------------------
int sub_BCACF( int a1, int a2)
{
  int v2; // eax

  v2 = *(_DWORD *)(361 * a1 + dword_192B18 + 4 * a2 + 12) & 0xF;
  if ( v2 == 9 )
    return 3;
  if ( v2 == 8 )
    return 4;
  return 2;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BCB07) --------------------------------------------------------
void sub_BCB07()
{
  JUMPOUT(0xBCB90);
}
// BCB49: control flows out of bounds to BCB90


//----- (000BCB4B) --------------------------------------------------------
int sub_BCB4B( int a1)
{
  return sub_B4EF6(
           dword_19F7A8,
           a1,
           1,
           310,
           30 * a1 + 62,
           510,
           1,
           (int)&unk_19F888 + 84 * a1,
           &word_19F9D4[a1],
           &word_19F9DA[a1],
           &word_19F9E0[a1]);
}
// 19F7A8: using guessed type int dword_19F7A8;
// 19F9D4: using guessed type _WORD word_19F9D4[3];
// 19F9DA: using guessed type int16_t word_19F9DA[3];
// 19F9E0: using guessed type int16_t word_19F9E0[];


//----- (000BCBA0) --------------------------------------------------------
void sub_BCBA0()
{
  JUMPOUT(0xBCB8F);
}
// BCBE4: control flows out of bounds to BCB8F


//----- (000BCBE6) --------------------------------------------------------
void sub_BCBE6()
{
  word_182AB7 = dword_19F7A8;
  JUMPOUT(0xBCB8F);
}
// BCC38: control flows out of bounds to BCB8F
// 182AB7: using guessed type int16_t word_182AB7;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BCC3D) --------------------------------------------------------
int sub_BCC3D()
{
  int16_t i; // dx
  int result; // eax

  for ( i = 0; i < 3; ++i )
  {
    if ( byte_182ABB )
    {
      if ( byte_182ABB == 1 )
        result = sub_BCC6D(i);
    }
    else
    {
      result = sub_BCB4B(i);
    }
  }
  return result;
}
// 182ABB: using guessed type char byte_182ABB;


//----- (000BCC6D) --------------------------------------------------------
int sub_BCC6D( int a1)
{
  _BYTE *v2; // eax
  int16_t v3; // dx
  int result; // eax

  v2 = (_BYTE *)sub_CDF5C(12);
  v3 = sub_11438B(310, 30 * a1 + 60, 510, 30 * a1 + 88, v2, 0);
  result = a1;
  word_19F9E0[a1] = v3;
  return result;
}
// 19F9E0: using guessed type int16_t word_19F9E0[];


//----- (000BCD70) --------------------------------------------------------
int sub_BCD70(int a1)
{
  int16_t v1; // ax
  char *v2; // eax
  int result; // eax
  int16_t v4; // ax
  int v5; // eax
  int v6; // [esp-210h] [ebp-210h]
  int v7; // [esp-20Ch] [ebp-20Ch]
  int v8; // [esp-208h] [ebp-208h]
  int v9; // [esp-204h] [ebp-204h]

  sub_BCB07();
  sub_BCB07();
  sub_BCB07();
  result = word_182ABC;
  if ( word_182ABC != -1 )
  {
    if ( byte_199CAE == 4 )
    {
      v4 = sub_BCACF(dword_19F7A8, word_182ABC);
      v9 = sub_BB147(v4);
      v8 = sub_BB121((*(_DWORD *)(dword_192B18 + 361 * dword_19F7A8 + 4 * word_182ABC + 12) & 0x400) != 0);
      v7 = sub_BAE1A(dword_19F7A8, word_182ABC);
      v5 = sub_BB0F0((uint16_t)(*(_WORD *)(dword_192B18 + 361 * dword_19F7A8 + 4 * word_182ABC + 12) << 7) >> 14);
    }
    else
    {
      v9 = sub_BB0F0((uint16_t)(*(_WORD *)(361 * dword_19F7A8 + dword_192B18 + 4 * word_182ABC + 12) << 7) >> 14);
      v1 = sub_BCACF(dword_19F7A8, word_182ABC);
      v8 = sub_BB147(v1);
      v7 = sub_BAE1A(dword_19F7A8, word_182ABC);
      v5 = sub_BB121((*(_DWORD *)(361 * dword_19F7A8 + dword_192B18 + 4 * word_182ABC + 12) & 0x400) != 0);
    }
    v6 = v5;
    v2 = (char *)sub_CDF5C(76);
    sprintf(a1 - 500, v2, v6, v7, v8, v9);
    sub_120DED(80, 80);
    sub_BB04E(3u);
    return sub_BD727(a1 - 500);
  }
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ABC: using guessed type int16_t word_182ABC;
// 192B18: using guessed type int dword_192B18;
// 199CAE: using guessed type char byte_199CAE;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BCE5E) --------------------------------------------------------
void sub_BCE5E()
{
  sub_BCE7E(3);
  sub_BCE7E(0);
  sub_BCE7E(1);
  sub_BCE7E(2);
}


//----- (000BCE7E) --------------------------------------------------------
void sub_BCE7E(int a1)
{
  int16_t v1; // dx
  int16_t v2; // cx

  if ( a1 == 3 )
  {
    v1 = -1;
    v2 = -3;
  }
  else
  {
    v2 = -1;
    v1 = a1;
  }
  sub_B55A3(dword_19F7A8, a1, 128, v2 + 30 * v1 + 65, 301, 20);
}
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BCEA2) --------------------------------------------------------
int sub_BCEA2(int a1, int a2, int a3, unsigned int a4)
{
  char *v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // kr00_4
  int v11; // ebx
  int v12; // eax
  char *v13; // eax
  int64_t v14; // rax
  int16_t v15; // bx
  int v16; // eax
  int v17; // esi
  int v18; // ebx
  int v19; // esi
  _BYTE *v21; // [esp-8h] [ebp-218h]
  int v22; // [esp+0h] [ebp-210h]
  _BYTE v23[500]; // [esp+4h] [ebp-20Ch] BYREF
  int v24; // [esp+1FCh] [ebp-14h]
  unsigned int v25; // [esp+200h] [ebp-10h]
  char *v26; // [esp+204h] [ebp-Ch]
  int v27; // [esp+208h] [ebp-8h]
  int v28; // [esp+20Ch] [ebp-4h]

  v25 = a4;
  v5 = (char *)(dword_192B18 + 361 * dword_19F7A8);
  v6 = *(int16_t *)&v5[2 * v22 + 304];
  LOWORD(v5) = *v5;
  word_182AB9 = 0;
  v26 = v5;
  if ( a4 != 2 )
    sub_BCEA2(v22, a2, a3, 2);
  sub_120DED(80, 80);
  sub_BB04E(3u);
  if ( word_182AB9 )
  {
    word_182AB9 = 0;
    v28 = 0;
    if ( v6 > 0 )
    {
      v24 = 3753 * (int16_t)v26;
      v11 = sub_BB5DB(v22, *(uint8_t *)(v24 + dword_197F98 + 37));
      v12 = sub_BB5DB(v22, *(uint8_t *)(v24 + dword_197F98 + 37));
      sub_12A478(a2 * (30 - word_182AB9), 479 - *(_WORD *)(v12 + 2), v11);
      v13 = (char *)sub_CDF5C(124);
      v14 = sprintf(v23, v13, v6);
      sub_120DED(SWORD2(v14), SHIDWORD(v14));
      sub_120CCB(3, (int)&unk_182C2E);
      sub_120EB9((int)&unk_182C26);
      sub_120F07((int)&unk_182C46);
      WORD2(v14) = 479 - *(_WORD *)(sub_BB5DB(v22, *(uint8_t *)(v24 + dword_197F98 + 37)) + 2);
      v28 = 3;
      sub_1212B3((30 - word_182AB9) * (a2 + 1), SWORD2(v14), (int)v23);
    }
  }
  else
  {
    v28 = 0;
    v7 = v25;
    v27 = a2;
    while ( 1 )
    {
      v10 = v7;
      v7 = (int16_t)v28;
      if ( (int16_t)v28 >= v6 )
        break;
      if ( v25 <= 3 )
      {
        switch ( v10 )
        {
          case 0:
            v24 = 3753 * (int16_t)v26;
            v8 = sub_BB5DB(v22, *(uint8_t *)(v24 + dword_197F98 + 37));
            v9 = sub_BB5DB(v22, *(uint8_t *)(v24 + dword_197F98 + 37));
            v7 = sub_12A478(v27 * (30 - word_182AB9), 479 - *(_WORD *)(v9 + 2), v8);
            break;
          case 1:
          case 2:
          case 3:
            break;
        }
      }
      ++v27;
      ++v28;
    }
  }
  if ( v25 )
  {
    if ( v25 <= 1 )
    {
      if ( (int16_t)v28 <= 0 )
      {
        word_182AF9[v22] = -1000;
      }
      else
      {
        v21 = (_BYTE *)sub_CDF5C(12);
        v15 = (30 - word_182AB9) * (a2 + v28) - 1;
        v16 = sub_BB5DB(v22, *(uint8_t *)(dword_197F98 + 3753 * (int16_t)v26 + 37));
        word_182AF9[v22] = sub_11438B(a2 * (30 - word_182AB9), 479 - *(_WORD *)(v16 + 2), v15, 479, v21, 0);
      }
    }
    else if ( v25 == 2 )
    {
      v17 = *(int16_t *)(dword_192B18 + 361 * dword_19F7A8 + 2 * ((v22 + 1) % 2) + 304) + v6;
      if ( v17 <= 1 )
        v18 = 1;
      else
        v18 = v17;
      if ( 260 / v18 <= 1 )
      {
        LOWORD(v19) = 1;
      }
      else
      {
        if ( v17 <= 1 )
          v17 = 1;
        v19 = 260 / v17;
      }
      if ( (int16_t)v19 >= 30 )
        word_182AB9 = 0;
      else
        word_182AB9 = 30 - v19;
    }
  }
  return a2 + (int16_t)v28;
}
// BCEC6: variable 'v22' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182AB9: using guessed type int16_t word_182AB9;
// 182AF9: using guessed type int16_t word_182AF9[2];
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BD1FB) --------------------------------------------------------
int sub_BD1FB()
{
  int v0; // edi
  int v1; // edx
  int v2; // esi
  int result; // eax
  int v4; // [esp+0h] [ebp-4h]

  v0 = 0;
  v1 = 0;
  v2 = 0;
  v4 = 0;
  do
  {
    result = sub_BCEA2(v2, v1, v0, 0);
    v1 = result;
    if ( result > v4 )
    {
      v4 = result;
      ++v0;
    }
    ++v2;
  }
  while ( v2 < 2 );
  return result;
}


//----- (000BD236) --------------------------------------------------------
int sub_BD236()
{
  int v0; // edi
  int v1; // edx
  int v2; // esi
  int result; // eax
  int v4; // [esp+0h] [ebp-4h]

  v0 = 0;
  v1 = 0;
  v2 = 0;
  v4 = 0;
  do
  {
    result = sub_BCEA2(v2, v1, v0, 1u);
    v1 = result;
    if ( result > v4 )
    {
      v4 = result;
      ++v0;
    }
    ++v2;
  }
  while ( v2 < 2 );
  return result;
}


//----- (000BD26C) --------------------------------------------------------
int sub_BD26C()
{
  int result; // eax
  int v1; // eax
  int v2; // eax
  int v3; // eax
  char *v4; // eax
  _BYTE *v5; // ebx
  int v6; // [esp-4h] [ebp-1F8h]
  _BYTE v7[500]; // [esp+0h] [ebp-1F4h] BYREF

  result = *(char *)(dword_19306C + 113 * dword_19F7B8 + word_19999C + 66);
  if ( result != -1 )
  {
    dword_192EE4 = sub_127C27((int)aBuffer0Lbx_5, 0, dword_193174);
    sub_133C9C(dword_192EE4, 0);
    v1 = sub_BBA8E(33);
    sub_12A478(544, 351, v1);
    v2 = sub_BBA8E(30);
    sub_12A478(550, 357, v2);
    sub_120DED(80, 80);
    sub_120CCB(2, (int)&unk_182C2E);
    sub_120EB9((int)&unk_182C26);
    sub_120F07((int)&unk_182C46);
    v3 = dword_1930DC + 59 * *(char *)(word_19999C + 113 * dword_19F7B8 + dword_19306C + 66);
    if ( *(char *)(v3 + 55) <= 0 )
    {
      sub_1298DE(550, 433, 623, 442);
      v5 = (_BYTE *)(59 * *(char *)(113 * dword_19F7B8 + dword_19306C + word_19999C + 66) + dword_1930DC);
    }
    else
    {
      v6 = *(char *)(v3 + 55);
      v4 = (char *)sub_CDF5C(285);
      v5 = v7;
      sprintf(v7, v4, v6);
    }
    return sub_1210FD(586, 433, (int)v5);
  }
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192EE4: using guessed type int dword_192EE4;
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 193174: using guessed type int dword_193174;
// 19999C: using guessed type int16_t word_19999C;
// 19F7B8: using guessed type int dword_19F7B8;


//----- (000BD3C1) --------------------------------------------------------
int sub_BD3C1()
{
  return sub_B53B6(dword_19F7A8, 310, 33, 510);
}
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BD3E3) --------------------------------------------------------
void sub_BD3E3()
{
  int v0; // eax
  int v1; // eax

  if ( byte_182ACA )
  {
    sub_1298DE(0, 0, 640, 150);
    if ( (int16_t)sub_B9AD7(dword_19F7A8) == -1 )
      v0 = 3;
    else
      v0 = 4;
    v1 = sub_BBA8E(v0);
    sub_12A478(0, 0, v1);
  }
}
// 182ACA: using guessed type char byte_182ACA;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BD434) --------------------------------------------------------
int sub_BD434()
{
  int v0; // esi
  int v1; // edi
  char *v2; // eax
  int64_t v3; // rax
  char *v4; // eax
  uint8_t v5; // al
  uint8_t v6; // al
  int16_t v7; // ax
  uint8_t v8; // al
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  char *v13; // eax
  int64_t v14; // rax
  int v16; // [esp-8h] [ebp-70h]
  int16_t *v17; // [esp-4h] [ebp-6Ch]
  int16_t *v18; // [esp-4h] [ebp-6Ch]
  _BYTE v19[104]; // [esp+0h] [ebp-68h] BYREF

  v0 = 0;
  v1 = 0;
  if ( *(_BYTE *)(dword_192B18 + 361 * dword_19F7A8 + 303) )
  {
    v17 = sub_77B28(dword_19F7BC);
    v16 = sub_BC8DF(dword_19F7A8);
    v2 = (char *)sub_CDF5C(97);
    v3 = sprintf(v19, v2, v16, v17);
    sub_120DED(SWORD2(v3), SHIDWORD(v3));
    sub_120CCB(4, (int)&unk_182C2E);
    sub_120EB9((int)&unk_182C26);
    sub_120F07((int)&unk_182C46);
  }
  else
  {
    v18 = sub_77B28(dword_19F7BC);
    v4 = (char *)sub_CDF5C(181);
    sprintf(v19, v4, v18);
    v5 = sub_C5D97(30, 2);
    sub_BB012(4u, v5);
  }
  sub_120E8C(2);
  sub_1210FD(320, 0, (int)v19);
  if ( (((int)*(uint8_t *)(113
                                 * *(uint8_t *)(dword_1930D4
                                                      + 17 * *(int16_t *)(361 * dword_19F7A8 + dword_192B18 + 2)
                                                      + 2)
                                 + dword_19306C
                                 + 42) >> word_19999C)
      & 1) != 0 )
  {
    v6 = sub_C5D97(30, 2);
    sub_BB012(4u, v6);
    sub_120E8C(2);
    v7 = 202;
LABEL_10:
    v9 = sub_CDF5C(v7);
    sub_1212B3(0, 0, v9);
    goto LABEL_11;
  }
  if ( sub_234B8(dword_19F7A8) )
  {
    v8 = sub_C5D97(30, 2);
    sub_BB012(4u, v8);
    sub_120E8C(2);
    v7 = 415;
    goto LABEL_10;
  }
  if ( sub_23509(dword_19F7A8) )
  {
    sub_120DED(80, 80);
    sub_120CCB(4, (int)&unk_182C2E);
    sub_120EB9((int)&unk_182C26);
    sub_120F07((int)&unk_182C46);
    sub_120E8C(2);
    v7 = 426;
    goto LABEL_10;
  }
LABEL_11:
  sub_120DED(80, 80);
  sub_120CCB(4, (int)&unk_182C2E);
  sub_120EB9((int)&unk_182C26);
  sub_120F07((int)&unk_182C46);
  v10 = 0;
  sub_120E8C(3);
  v11 = 361 * dword_19F7A8;
  do
  {
    v10 += 2;
    v0 += *(int16_t *)(v10 + v11 + dword_192B18 + 178);
    v1 += *(int16_t *)(v10 + v11 + dword_192B18 + 198);
  }
  while ( v10 != 20 );
  v12 = sub_BC972(dword_19F7A8, -1, -1, -1, -1, -1);
  v13 = (char *)sub_CDF5C(424);
  v14 = sprintf(v19, v13, v12 + v0 / 1000, v0 % 1000, v1);
  sub_120CCB(2, SHIDWORD(v14));
  sub_1210B7(638, 3, (int)v19);
  sub_120DED(80, 80);
  return sub_BB04E(3u);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F7BC: using guessed type int dword_19F7BC;


//----- (000BD707) --------------------------------------------------------
int sub_BD707()
{
  if ( word_182AC0 == -1 )
    JUMPOUT(0xBD433);
  return sub_BD727(*(_UNKNOWN **)((char *)&off_17EB3D + 19 * word_182AC0));
}
// BD711: control flows out of bounds to BD433
// BD727: using guessed type int sub_BD727(_DWORD);
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 182AC0: using guessed type int16_t word_182AC0;


//----- (000BD727) --------------------------------------------------------
int sub_BD727(int a1)
{
  int16_t v2; // ax

  sub_120DED(80, 80);
  sub_BB04E(3u);
  v2 = sub_103971(640, a1, 0);
  sub_1298DE(319 - v2 / 2 - 10, 463, v2 / 2 + 329, 478);
  return sub_1210FD(319, 467, a1);
}
// 103971: using guessed type int sub_103971(_DWORD, _DWORD, _DWORD);


//----- (000BD790) --------------------------------------------------------
int sub_BD790()
{
  int result; // eax
  char *v1; // eax
  int v2; // [esp-8h] [ebp-1FCh]
  int v3; // [esp-4h] [ebp-1F8h]
  _BYTE v4[500]; // [esp+0h] [ebp-1F4h] BYREF

  result = word_182ABE;
  if ( word_182ABE != -1 )
  {
    v3 = (int)*(&off_17FFB2 + 3 * word_182ABE + 3);
    v2 = *(int16_t *)(dword_192B18 + 361 * dword_19F7A8 + 2 * word_182ABE + 304);
    v1 = (char *)sub_CDF5C(14);
    sprintf(v4, v1, v2, v3);
    return sub_BD727((int)v4);
  }
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17FFB2: using guessed type _UNKNOWN *off_17FFB2;
// 182ABE: using guessed type int16_t word_182ABE;
// 192B18: using guessed type int dword_192B18;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BD7F2) --------------------------------------------------------
int sub_BD7F2()
{
  int v0; // eax
  int result; // eax
  int v2; // eax

  sub_BD790();
  if ( word_182AC0 != -1 )
  {
    v0 = sub_BB40D(word_182AC0);
    sub_BD727(v0);
  }
  result = word_182AC2;
  if ( word_182AC2 != -1 && word_182AC4 != -1 )
  {
    v2 = sub_BB3DB(dword_182AFD[6 * word_182AC2 + word_182AC4]);
    return sub_BD727(v2);
  }
  return result;
}
// 182AC0: using guessed type int16_t word_182AC0;
// 182AC2: using guessed type int16_t word_182AC2;
// 182AC4: using guessed type int16_t word_182AC4;
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BD840) --------------------------------------------------------
int sub_BD840()
{
  sub_BD1FB();
  sub_BD26C();
  sub_BCE7E(3);
  sub_BCE7E(0);
  sub_BCE7E(1);
  sub_BCE7E(2);
  sub_BCB07();
  sub_BCB07();
  sub_BCB07();
  ((void (*)(void))loc_BCD8B)();
  sub_B53B6(dword_19F7A8, 310, 33, 510);
  sub_BD434();
  sub_BDD2F();
  if ( byte_182AC8 )
  {
    if ( byte_182AC8 == 1 )
      sub_BF5D4();
  }
  else
  {
    sub_BF615();
  }
  sub_BD790();
  sub_BD707();
  return sub_BE508(word_182AC2, word_182AC4);
}
// 182AC2: using guessed type int16_t word_182AC2;
// 182AC4: using guessed type int16_t word_182AC4;
// 182AC8: using guessed type char byte_182AC8;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BD8F6) --------------------------------------------------------
int sub_BD8F6( int a1)
{
  int v1; // ebx
  int16_t v2; // dx
  int v3; // eax
  int16_t v4; // bx

  v1 = 361 * a1;
  v2 = sub_E0F95(v1 + dword_192B18);
  v3 = v1 + dword_192B18;
  v4 = *(_WORD *)(v1 + dword_192B18 + 293);
  if ( !v4 )
    return -1;
  if ( *(_WORD *)(v3 + 300) )
    return 0;
  return (v2 - v4) / v4;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BD947) --------------------------------------------------------
int sub_BD947( int a1)
{
  int v1; // edx
  int16_t v2; // cx
  int16_t v3; // ax
  int v4; // ebx

  v1 = 361 * a1;
  v2 = sub_E0F95(v1 + dword_192B18);
  v3 = *(_WORD *)(v1 + dword_192B18 + 233);
  if ( v3 <= 1 )
    v4 = 1;
  else
    v4 = v3;
  return v2 / v4;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BD988) --------------------------------------------------------
int sub_BD988( int a1, int a2, int a3, int a4, int a5)
{
  int16_t *v5; // edi
  int16_t v6; // si
  int16_t v9; // [esp+8h] [ebp-14h]
  int16_t v10; // [esp+Ch] [ebp-10h] BYREF
  int v11; // [esp+10h] [ebp-Ch] BYREF
  int16_t v12; // [esp+14h] [ebp-8h] BYREF
  int v13; // [esp+18h] [ebp-4h] BYREF

  v5 = (int16_t *)sub_AF6DC(a4, a5, a3);
  v9 = sub_BC5D8(a4, a5, 0) - 60;
  v6 = sub_BC5D8(a4, a5, 1) - 120;
  sub_12D8F5(120, 120, dword_19DD8C);
  sub_12F7E6((int16_t)-v9, (int16_t)-v6, v5, (int16_t *)dword_19DD8C);
  sub_12F2A2((int16_t *)dword_19DD8C, 240, 255);
  sub_131528((_WORD *)dword_19DD8C, &v10, (int16_t *)&v11, &v12, &v13);
  return sub_12A478(a1 - v12 / 2 - v10, a2 - v11 - v13, dword_19DD8C);
}
// 19DD8C: using guessed type int dword_19DD8C;


//----- (000BDA57) --------------------------------------------------------
void sub_BDA57()
{
  int16_t v0; // dx
  int16_t v1; // cx

  v0 = sub_E0F95(dword_192B18 + 361 * dword_19F7A8);
  v1 = *(_WORD *)(361 * dword_19F7A8 + dword_192B18 + 293);
  if ( *(_WORD *)(361 * dword_19F7A8 + dword_192B18 + 300) )
    v1 = v0;
  sub_B5ED2(606, 43, v0, v1);
}
// 192B18: using guessed type int dword_192B18;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BDAB4) --------------------------------------------------------
void sub_BDAB4( int a1, int a2, int a3)
{
  int16_t v4; // ax
  int16_t *v5; // ebx

  if ( a3 == -3 )
  {
    sub_128AB6(517, 17, 639, 158);
    sub_12B634();
    sub_BD988(579, 106, 14, 5, 5);
LABEL_3:
    sub_12B65C();
    return;
  }
  if ( byte_17EB4B[19 * a3] != 7 )
  {
    sub_128AB6(517, 17, 639, 158);
    sub_12B634();
    sub_BD988(579, 106, a3, 5, 5);
    goto LABEL_3;
  }
  v4 = sub_BBBBA(a3);
  v5 = (int16_t *)sub_BBB9F(v4);
  sub_C5CFF(a1, a2 - 70, v5);
}


//----- (000BDB62) --------------------------------------------------------
void sub_BDB62( int a1)
{
  sub_BDAB4(578, 148, a1);
}


//----- (000BDB79) --------------------------------------------------------
void sub_BDB79( int a1)
{
  sub_128AB6(517, 17, 639, 158);
  sub_12B634();
  sub_BAAC5(578, 77, a1);
  sub_12B65C();
}


//----- (000BDBB9) --------------------------------------------------------
int sub_BDBB9( int a1, int a2)
{
  int v2; // ebx
  int16_t v3; // cx
  int16_t v4; // ax
  int v6; // ebx

  v2 = 361 * a1;
  v3 = sub_E0DD6((char *)(v2 + dword_192B18), a2);
  v4 = *(_WORD *)(v2 + dword_192B18 + 233);
  if ( v4 >= v3 )
    return 1;
  if ( v4 <= 0 )
    return 10000;
  if ( v4 <= 1 )
    v6 = 1;
  else
    v6 = v4;
  return v3 / v6 + 1;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BDC18) --------------------------------------------------------
int sub_BDC18( int a1, int a2)
{
  int v3; // eax
  int16_t v4; // si
  int16_t v5; // di
  int v6; // ecx
  int v7; // eax
  int16_t v8; // bx
  int v9; // edx
  int v10; // eax

  v3 = 361 * a1 + dword_192B18;
  v4 = *(_WORD *)(v3 + 277);
  v5 = *(_WORD *)(v3 + 300);
  *(_WORD *)(v3 + 277) = a2;
  if ( a2 != v4 )
    *(_WORD *)(v3 + 300) = 0;
  v6 = 361 * a1;
  v7 = sub_E0FA4(v6 + dword_192B18);
  v8 = v7;
  v9 = v7;
  v10 = dword_192B18;
  *(_WORD *)(v6 + dword_192B18 + 277) = v4;
  *(_WORD *)(v6 + v10 + 300) = v5;
  if ( v8 == -1 )
    return 10000;
  return v9;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BDC93) --------------------------------------------------------
int sub_BDC93( int a1)
{
  int v1; // edx
  int result; // eax

  v1 = 361 * a1;
  result = sub_E0FA4(v1 + dword_192B18);
  if ( *(_WORD *)(dword_192B18 + v1 + 300) )
    return 1;
  if ( (int16_t)result == -1 )
    return 10000;
  return result;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BDCD8) --------------------------------------------------------
int sub_BDCD8()
{
  int16_t v0; // bx
  char *v1; // eax
  int64_t v2; // rax
  _BYTE v4[500]; // [esp+0h] [ebp-1F4h] BYREF

  v0 = sub_BDC93(dword_19F7A8);
  sub_120CCB(0, (int)&unk_182C2E);
  v1 = (char *)sub_CDF5C(32);
  v2 = sprintf(v4, v1, v0);
  return sub_1210B7(624, SWORD2(v2), (int)v4);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BDD2F) --------------------------------------------------------
int sub_BDD2F()
{
  int16_t v0; // si
  int16_t v1; // bx
  int v2; // eax
  int v3; // edx
  int16_t *v4; // eax
  int16_t v5; // bx
  int v6; // edx
  char *v7; // eax
  int v8; // eax
  char v10[100]; // [esp+0h] [ebp-64h] BYREF

  v0 = *(_WORD *)(361 * dword_19F7A8 + dword_192B18 + 277);
  if ( v0 >= -6 )
  {
    if ( v0 <= -6 )
    {
      v3 = 3753 * word_19999C;
      v2 = dword_197F98;
    }
    else
    {
      if ( v0 >= -3 )
      {
        if ( v0 <= -3 )
        {
          v1 = -3;
LABEL_18:
          sub_BDAB4(578, 148, v1);
          goto LABEL_33;
        }
        if ( v0 <= 0 )
          goto LABEL_33;
        goto LABEL_27;
      }
      v2 = 3753 * word_19999C;
      v3 = dword_197F98;
    }
    v4 = (int16_t *)sub_BB54D(0, 4u, *(uint8_t *)(v3 + v2 + 37));
LABEL_20:
    sub_C5CFF(578, 77, v4);
    goto LABEL_33;
  }
  if ( v0 < -11 )
  {
    if ( v0 < -15 )
      goto LABEL_27;
    if ( v0 <= -15 )
    {
      v5 = 48;
      v6 = 77;
      goto LABEL_24;
    }
    if ( v0 != -12 )
      goto LABEL_27;
    v5 = 45;
LABEL_23:
    v6 = 57;
LABEL_24:
    sub_BABA4(578, v6, v5);
    goto LABEL_33;
  }
  if ( v0 <= -11 )
  {
    v5 = 47;
    goto LABEL_23;
  }
  if ( v0 >= -8 )
  {
    if ( v0 <= -8 )
      goto LABEL_33;
    v4 = (int16_t *)sub_127C27(
                      (int)aRaceiconLbx,
                      (int16_t)(13 * *(uint8_t *)(dword_197F98 + 3753 * word_19999C + 37) + 11),
                      dword_193174);
    goto LABEL_20;
  }
LABEL_27:
  sub_120DED(80, 80);
  sub_BB04E(3u);
  if ( v0 > 0 && v0 < 49 )
  {
    v1 = v0;
    goto LABEL_18;
  }
  if ( v0 > -100 )
  {
    v7 = (char *)sub_CDF5C(247);
    _wcpp_1_unwind_leave(0, 0, v7, v0);
    sub_6497C();
  }
  else
  {
    sub_128AB6(517, 17, 639, 158);
    sub_12B634();
    sub_BAAC5(578, 77, -(int16_t)(v0 + 100));
    sub_12B65C();
  }
LABEL_33:
  sub_BDA57();
  strcpy(v10, sub_B2FFA(v0));
  sub_120CCB(1, (int)&unk_182C2E);
  sub_10315D((int)v10, 2);
  if ( *(_BYTE *)(dword_192B18 + 361 * dword_19F7A8 + 297) )
  {
    sub_120CCB(1, (int)&unk_182C26);
    v8 = sub_CDF5C(189);
    sub_1210FD(578, 28, v8);
  }
  return sub_BDCD8();
}
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 192B18: using guessed type int dword_192B18;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BDFB9) --------------------------------------------------------
int sub_BDFB9()
{
  int16_t i; // si
  int result; // eax
  int16_t v2; // ax
  int16_t *v3; // eax
  int16_t v4; // di
  int16_t v5; // bx
  int16_t v6; // dx
  int16_t v7; // ax
  int16_t v8; // dx
  _BYTE *v9; // [esp-8h] [ebp-Ch]

  for ( i = 0; i < 10; ++i )
  {
    result = 2 * i;
    if ( *(int16_t *)((char *)word_19F99C + result) == -1 )
    {
      word_19F984[i] = -1000;
    }
    else
    {
      v2 = sub_BBBBA(word_19F99C[i]);
      v3 = (int16_t *)sub_BBB9F(v2);
      v4 = *v3;
      v5 = v3[1];
      v9 = (_BYTE *)sub_CDF5C(12);
      if ( i % 2 )
        v6 = -1;
      else
        v6 = 1;
      if ( i % 2 )
        v7 = -1;
      else
        v7 = 1;
      v8 = sub_11438B(50 * i * v7 + 295, 162, v4 + 50 * i * v6 + 295, v5 + 162, v9, 0);
      result = i;
      word_19F984[i] = v8;
    }
  }
  return result;
}
// 19F984: using guessed type int16_t word_19F984[12];
// 19F99C: using guessed type int16_t word_19F99C[];


//----- (000BE09C) --------------------------------------------------------
int16_t sub_BE09C(int16_t *a1, _WORD *a2)
{
  int16_t i; // si
  int16_t v5; // dx
  int v6; // ebx
  char *v7; // eax
  int16_t v8; // ax
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v13; // [esp-8h] [ebp-204h]
  int v14; // [esp-4h] [ebp-200h]
  char v15[500]; // [esp+0h] [ebp-1FCh] BYREF
  int v16; // [esp+1F4h] [ebp-8h]
  int v17; // [esp+1F8h] [ebp-4h]

  word_182AC0 = -1;
  for ( i = 0; i < 10; ++i )
  {
    v5 = word_19F984[i];
    if ( v5 == *a1 )
    {
      v6 = word_19F99C[i];
      v17 = *(int *)((char *)&dword_17EB45 + 19 * v6) / 2;
      if ( *(uint16_t *)(dword_192B18 + 361 * dword_19F7A8 + 359) == dword_192FD8 )
      {
        v9 = sub_CDF5C(579);
        sub_C5B5F(v9);
        word_19994C = 0;
        sub_119281();
        byte_182ACA = 1;
        sub_1191CA((int)sub_BED21, 1);
        sub_CDB01();
      }
      else
      {
        v14 = (int16_t)v17;
        v16 = (int16_t)v17;
        v13 = sub_BB40D(v6);
        v7 = (char *)sub_CDF5C(263);
        sprintf(v15, v7, v13, v14);
        sub_77658((int)v15);
        if ( v8 )
        {
          *(_WORD *)(dword_192B18 + 361 * dword_19F7A8 + 359) = dword_192FD8;
          sub_145EA(dword_19F7A8, v6, (int)a2);
          sub_BC27F(v6);
          sub_E2A70(dword_19F7A8, (int)a2);
          *(_DWORD *)(dword_197F98 + 3753 * word_19999C + 50) += v16;
        }
      }
      word_19994C = 0;
      sub_119281();
      byte_182ACA = 1;
      sub_1191CA((int)sub_BED21, 1);
      sub_CDB01();
    }
    else if ( -v5 == *a1 )
    {
      v10 = 19 * word_19F99C[i];
      sub_AFBCB(v15, *(int16_t *)((char *)&word_17EB43 + v10));
      sub_A5EB2(*(int *)((char *)&off_17EB3D + v10), (int)v15);
    }
    v11 = 2 * i;
    if ( *(int16_t *)((char *)word_19F984 + v11) == *a2 )
    {
      LOWORD(v11) = word_19F99C[i];
      word_182AC0 = v11;
    }
  }
  return v11;
}
// BE140: variable 'v8' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 17EB43: using guessed type int16_t word_17EB43;
// 17EB45: using guessed type int dword_17EB45;
// 182AC0: using guessed type int16_t word_182AC0;
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F984: using guessed type int16_t word_19F984[12];
// 19F99C: using guessed type int16_t word_19F99C[];


//----- (000BE271) --------------------------------------------------------
void sub_BE271( int a1, int a2, unsigned int a3)
{
  int16_t v3; // ax
  int16_t *v4; // esi

  v3 = sub_BBBBA(a3);
  v4 = (int16_t *)sub_BBB9F(v3);
  sub_12D8F5(120, 120, dword_19DD8C);
  sub_12F7E6(0, 0, v4, (int16_t *)dword_19DD8C);
  sub_12F2A2((int16_t *)dword_19DD8C, 240, 255);
  sub_12E8D4((int16_t *)dword_19DD8C, (int16_t *)dword_19DD8C, 2);
  sub_128AB6(0, 0, 639, 479);
  sub_12B634();
  sub_12A478(a1, a2, dword_19DD8C);
  sub_12B65C();
}
// 19DD8C: using guessed type int dword_19DD8C;


//----- (000BE306) --------------------------------------------------------
void sub_BE306()
{
  JUMPOUT(0xBBBAF);
}
// BE361: control flows out of bounds to BBBAF


//----- (000BE366) --------------------------------------------------------
void sub_BE366()
{
  int16_t i; // cx
  int16_t v1; // ax
  int v2; // eax
  int v3; // edi
  int16_t v4; // ax

  if ( !sub_7A7F6() )
  {
    for ( i = 0; i < 10; ++i )
    {
      if ( word_19F99C[i] != -1 )
      {
        if ( word_182AC0 == word_19F99C[i] && (uint16_t)sub_C5D97(30, 2) )
        {
          if ( i % 2 )
            v1 = -1;
          else
            v1 = 1;
          sub_BE271(50 * i * v1 + 295, 162, word_19F99C[i]);
        }
        else
        {
          sub_BE306();
          v3 = v2;
          if ( i % 2 )
            v4 = -1;
          else
            v4 = 1;
          sub_12A478(50 * i * v4 + 295, 162, v3);
        }
      }
    }
  }
  JUMPOUT(0xBAD9A);
}
// BE445: control flows out of bounds to BAD9A
// BE401: variable 'v2' is possibly undefined
// 182AC0: using guessed type int16_t word_182AC0;
// 19F99C: using guessed type int16_t word_19F99C[];


//----- (000BE44A) --------------------------------------------------------
unsigned int sub_BE44A()
{
  int i; // esi
  int v1; // edi
  int v2; // ecx
  unsigned int result; // eax
  int16_t v4; // cx
  _BYTE *v5; // eax
  _BYTE v6[72]; // [esp+0h] [ebp-50h] BYREF
  int v7; // [esp+48h] [ebp-8h]
  int v8; // [esp+4Ch] [ebp-4h]

  qmemcpy(v6, dword_BA784, sizeof(v6));
  for ( i = 70; i != -2; i -= 2 )
  {
    v1 = (uint8_t)v6[i];
    v2 = (uint8_t)v6[i + 1];
    result = 24 * v1 + 4 * v2;
    v7 = 12 * v1 + 2 * v2;
    if ( *(int *)((char *)dword_182AFD + result) )
    {
      v8 = sub_BC866(v1, v2, 0);
      v4 = sub_BC866(v1, v2, 1);
      v5 = (_BYTE *)sub_CDF5C(12);
      result = sub_11438B(v8 - 20, v4 - 30, v8 + 20, v4 + 10, v5, 0);
      *(int16_t *)((char *)word_19F71C + v7) = result;
    }
    else
    {
      word_19F71C[6 * v1 + v2] = -1000;
    }
  }
  return result;
}
// BA784: using guessed type int dword_BA784[18];
// 182AFD: using guessed type int dword_182AFD[];
// 19F71C: using guessed type int16_t word_19F71C[70];


//----- (000BE508) --------------------------------------------------------
int sub_BE508(int result, int a2)
{
  int v2; // ebx
  int v3; // eax

  v2 = (int16_t)result;
  if ( (int16_t)result != -1 )
  {
    result = a2;
    if ( a2 != -1 )
    {
      v3 = sub_BB3DB(dword_182AFD[6 * v2 + a2]);
      return sub_BD727(v3);
    }
  }
  return result;
}
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BE530) --------------------------------------------------------
char sub_BE530(int16_t *a1, _WORD *a2)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // edi
  int16_t v6; // si
  int v7; // ecx
  int v8; // eax
  char *v9; // eax
  int16_t v10; // ax
  int v11; // eax
  int v12; // eax
  bool v13; // edx
  int16_t v14; // si
  int v15; // eax
  int v17; // [esp-8h] [ebp-410h]
  char v19[1000]; // [esp+8h] [ebp-400h] BYREF
  int v20; // [esp+3F0h] [ebp-18h]
  unsigned int v21; // [esp+3F4h] [ebp-14h]
  int v22; // [esp+3F8h] [ebp-10h]
  int v23; // [esp+3FCh] [ebp-Ch]
  int16_t v24; // [esp+400h] [ebp-8h] BYREF
  int16_t v25; // [esp+404h] [ebp-4h] BYREF

  word_182AC2 = -1;
  word_182AC4 = -1;
  LOWORD(v2) = sub_123ABA();
  v3 = 0;
  v23 = v2;
  LOWORD(v4) = sub_123AE7();
  v22 = v4;
  while ( 2 )
  {
    v20 = 0;
    v21 = 24 * v3;
    v5 = 6 * v3;
    do
    {
      if ( *a1 == word_19F71C[v5] || *a1 == word_182ACF[0] && sub_BC768(v23, v22, v3, v20) && dword_182AFD[v21 / 4] )
      {
        v6 = dword_182AFD[6 * v3 + v20];
        v7 = *(int *)((char *)&dword_17EB45 + 19 * v6) / 2;
        v8 = v6 != 3 && v6 != 14 && v6 != 40 && v6 != 41;
        if ( v8 )
        {
          LOBYTE(v8) = v6 != 8;
          if ( v6 != 8 && v6 != 9 )
          {
            if ( *(uint16_t *)(dword_192B18 + 361 * dword_19F7A8 + 359) == dword_192FD8 )
            {
              v11 = sub_CDF5C(579);
              sub_C5B5F(v11);
              word_19994C = 0;
            }
            else
            {
              v17 = sub_BB3DB(v6);
              v9 = (char *)sub_CDF5C(263);
              sprintf(v19, v9, v17, (int16_t)v7);
              sub_77658((int)v19);
              if ( v10 )
              {
                *(_WORD *)(dword_192B18 + 361 * dword_19F7A8 + 359) = dword_192FD8;
                if ( sub_BBD37(v6, &v24, &v25) )
                {
                  byte_182ACA = 1;
                  dword_182AFD[6 * v24 + v25] = 8;
                }
                sub_145EA(dword_19F7A8, v6, v6);
                sub_E2A70(dword_19F7A8, v6);
                *(_DWORD *)(3753 * word_19999C + dword_197F98 + 50) += (int16_t)v7;
              }
LABEL_21:
              word_19994C = 0;
            }
            sub_119281();
            byte_182ACA = 1;
            sub_1191CA((int)sub_BED21, 1);
            LOBYTE(v8) = sub_CDB01();
            return v8;
          }
        }
        return v8;
      }
      v12 = *a1;
      if ( v12 == -word_19F71C[v5] || v12 == -word_182ACF[0] && sub_BC768(v23, v22, v3, v20) && dword_182AFD[v21 / 4] )
      {
        LOWORD(v8) = dword_182AFD[6 * v3 + v20];
        v13 = (_WORD)v8 != 3 && (_WORD)v8 != 14 && (_WORD)v8 != 40 && (_WORD)v8 != 41;
        if ( v13 && (_WORD)v8 != 8 )
        {
          v14 = dword_182AFD[6 * v3 + v20];
          sub_AFBCB(v19, *(int16_t *)((char *)&word_17EB43 + 19 * (int16_t)v8));
          v15 = sub_BB3DB(v14);
          sub_A5EB2(v15, (int)v19);
          goto LABEL_21;
        }
        return v8;
      }
      if ( *a2 == word_19F71C[v5]
        || (LOBYTE(v8) = sub_BC768(v23, v22, v3, v20), (_BYTE)v8) && (LOBYTE(v8) = v21, dword_182AFD[v21 / 4]) )
      {
        LOBYTE(v8) = v20;
        word_182AC2 = v3;
        word_182AC4 = v20;
        return v8;
      }
      v21 += 4;
      ++v20;
      ++v5;
    }
    while ( v20 < 6 );
    if ( ++v3 < 6 )
      continue;
    return v8;
  }
}
// BE553: variable 'v2' is possibly undefined
// BE55B: variable 'v4' is possibly undefined
// BE683: variable 'v10' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17EB43: using guessed type int16_t word_17EB43;
// 17EB45: using guessed type int dword_17EB45;
// 182AC2: using guessed type int16_t word_182AC2;
// 182AC4: using guessed type int16_t word_182AC4;
// 182ACA: using guessed type char byte_182ACA;
// 182ACF: using guessed type int16_t word_182ACF[];
// 182AFD: using guessed type int dword_182AFD[];
// 192B18: using guessed type int dword_192B18;
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 19F71C: using guessed type int16_t word_19F71C[70];
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BE896) --------------------------------------------------------
void sub_BE896( int a1, int a2)
{
  int16_t *v3; // edi
  int16_t v4; // si
  int16_t v5; // [esp+0h] [ebp-4h]

  v3 = (int16_t *)sub_AF6DC(a1, a2, dword_182AFD[6 * a1 + a2]);
  v5 = sub_BC5D8(a1, a2, 0) - 60;
  v4 = sub_BC5D8(a1, a2, 1) - 120;
  sub_12D8F5(120, 120, dword_19DD8C);
  sub_12F7E6((int16_t)-v5, (int16_t)-v4, v3, (int16_t *)dword_19DD8C);
  sub_12F2A2((int16_t *)dword_19DD8C, 240, 255);
  sub_12E8D4((int16_t *)dword_19DD8C, (int16_t *)dword_19DD8C, 2);
  sub_128AB6(0, 0, 639, 479);
  sub_12B634();
  sub_12A478(v5, v4, dword_19DD8C);
  sub_12B65C();
  JUMPOUT(0xBC860);
}
// BC85B: control flows out of bounds to BC860
// 182AFD: using guessed type int dword_182AFD[];
// 19DD8C: using guessed type int dword_19DD8C;


//----- (000BE960) --------------------------------------------------------
void sub_BE960( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v7; // bx
  int16_t v8; // si
  int16_t *v9; // edi
  int v10; // eax
  int16_t v11; // si
  int v12; // [esp+0h] [ebp-18h] BYREF
  int v13; // [esp+4h] [ebp-14h]
  int16_t v14; // [esp+8h] [ebp-10h] BYREF
  int16_t v15; // [esp+Ch] [ebp-Ch] BYREF
  int16_t v16; // [esp+10h] [ebp-8h] BYREF
  int v17; // [esp+14h] [ebp-4h]

  v17 = a4;
  v7 = a1;
  v8 = a3;
  v9 = (int16_t *)sub_AF6DC(a2, a3, v7);
  LOWORD(v10) = sub_BC5D8(a2, v8, 0);
  v13 = v10 - 60;
  v11 = sub_BC5D8(a2, v8, 1) - 120;
  sub_12D8F5(120, 120, dword_19DD8C);
  sub_12F7E6((int16_t)-(int16_t)v13, (int16_t)-v11, v9, (int16_t *)dword_19DD8C);
  sub_12F2A2((int16_t *)dword_19DD8C, 240, 255);
  sub_131528((_WORD *)dword_19DD8C, &v16, &v15, &v14, &v12);
  sub_12B634();
  sub_12A478(v17 - v14 / 2, a5 - v12, dword_19DD8C);
  sub_12B65C();
  JUMPOUT(0xBDA51);
}
// BEA2E: control flows out of bounds to BDA51
// BE996: variable 'v10' is possibly undefined
// 19DD8C: using guessed type int dword_19DD8C;


//----- (000BEA33) --------------------------------------------------------
void sub_BEA33( int a1, int a2)
{
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int16_t v8; // dx

  if ( a1 < 6 && a2 < 6 && a1 >= 0 && a2 >= 0 )
  {
    v5 = 4 * a2 + 24 * a1;
    if ( *(int *)((char *)dword_182AFD + v5) )
    {
      v6 = sub_AF6DC(a1, a2, *(_WORD *)((char *)dword_182AFD + v5));
      v7 = v6;
      if ( byte_182ACA )
      {
        v8 = *(_WORD *)(v6 + 4);
        sub_12B726(v6);
        while ( *(int16_t *)(v7 + 4) < v8 )
          sub_12A478(0, 0, v7);
      }
      if ( byte_182ACA )
      {
        sub_12A478(0, 0, v7);
      }
      else if ( a1 == word_182AC2 && a2 == word_182AC4 && (uint16_t)sub_C5D97(30, 2) )
      {
        sub_BE896(a1, a2);
      }
      else
      {
        sub_129FF9(0, 0, v7);
      }
    }
  }
}
// 182AC2: using guessed type int16_t word_182AC2;
// 182AC4: using guessed type int16_t word_182AC4;
// 182ACA: using guessed type char byte_182ACA;
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BEB1D) --------------------------------------------------------
int sub_BEB1D(int result, int a2, int16_t *a3)
{
  int v3; // esi
  int v4; // eax
  int16_t *v5; // esi
  int16_t *v6; // [esp+0h] [ebp-8h]
  int16_t v7; // [esp+4h] [ebp-4h]

  if ( (int16_t)result < 6 && a2 < 6 && (result & 0x8000u) == 0 && a2 >= 0 )
  {
    result = (int16_t)result;
    v3 = 24 * (int16_t)result + 4 * a2;
    if ( *(int *)((char *)dword_182AFD + v3) )
    {
      v4 = sub_AF6DC(result, a2, *(_WORD *)((char *)dword_182AFD + v3));
      v5 = (int16_t *)v4;
      v6 = (int16_t *)v4;
      if ( byte_182ACA )
      {
        v7 = *(_WORD *)(v4 + 4);
        sub_12B726(v4);
        sub_12F7E6(0, 0, v5, a3);
        sub_12B753((int)v5, v7);
      }
      return sub_12F7E6(0, 0, v6, a3);
    }
  }
  return result;
}
// 182ACA: using guessed type char byte_182ACA;
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BEBAE) --------------------------------------------------------
int16_t sub_BEBAE( int a1, _WORD *a2, _WORD *a3)
{
  int16_t result; // ax
  _BYTE v4[72]; // [esp+0h] [ebp-48h] BYREF

  qmemcpy(v4, dword_BA7CC, sizeof(v4));
  *a2 = (uint8_t)v4[2 * a1];
  result = (uint8_t)v4[2 * a1 + 1];
  *a3 = result;
  return result;
}
// BA7CC: using guessed type int dword_BA7CC[36];


//----- (000BEBDC) --------------------------------------------------------
void sub_BEBDC()
{
  _BOOL1 v0; // al
  int16_t v1; // cx
  int v2; // eax
  int16_t v3; // [esp+0h] [ebp-10h] BYREF
  int16_t v4; // [esp+4h] [ebp-Ch] BYREF
  uint8_t v5; // [esp+8h] [ebp-8h]
  _BOOL1 v6; // [esp+Ch] [ebp-4h]

  v0 = word_182AC2 != -1 && word_182AC4 != -1;
  v6 = v0;
  v1 = 0;
  v5 = !v0;
  while ( 1 )
  {
    sub_BEBAE(v1, &v4, &v3);
    if ( byte_182ACA || word_182AC2 != -1 && word_182AC4 != -1 )
    {
      sub_B6B95(v4, v3, v5);
      v2 = 4 * v3 + 24 * v4;
      if ( *(int *)((char *)dword_182AFD + v2)
        && (*(int16_t *)(sub_AF6DC(v4, v3, *(_WORD *)((char *)dword_182AFD + v2)) + 6) > 1 || byte_182ACA || v6) )
      {
        sub_BEA33(v4, v3);
      }
    }
    if ( ++v1 >= 36 )
      JUMPOUT(0xBA9E6);
  }
}
// BECA4: control flows out of bounds to BA9E6
// 182AC2: using guessed type int16_t word_182AC2;
// 182AC4: using guessed type int16_t word_182AC4;
// 182ACA: using guessed type char byte_182ACA;
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BECA9) --------------------------------------------------------
int sub_BECA9(int16_t *a1)
{
  int16_t i; // cx
  int result; // eax
  int16_t v4; // [esp+4h] [ebp-8h] BYREF
  int16_t v5; // [esp+8h] [ebp-4h] BYREF

  for ( i = 0; i < 36; ++i )
  {
    sub_BEBAE(i, &v4, &v5);
    result = 24 * v4 + 4 * v5;
    if ( *(int *)((char *)dword_182AFD + result) )
    {
      result = sub_AF6DC(v4, v5, *(_WORD *)((char *)dword_182AFD + result));
      if ( *(int16_t *)(result + 6) > 1 || byte_182ACA )
        result = sub_BEB1D(v4, v5, a1);
    }
  }
  return result;
}
// 182ACA: using guessed type char byte_182ACA;
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BED21) --------------------------------------------------------
char sub_BED21(int a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int16_t v6; // dx
  int16_t v7; // ax
  int16_t v9; // [esp-28h] [ebp-2Ch]
  int16_t v10; // [esp-24h] [ebp-28h]

  sub_124D41();
  if ( word_19994C )
  {
    word_19994C = 0;
    byte_182ACA = 1;
  }
  if ( byte_182ACA )
  {
    sub_128C32(0, 0, 639, 479, 0);
    v2 = sub_BBA8E(1);
    sub_12A478(0, 0, v2);
    v3 = sub_BBA8E(0);
    sub_12A478(0, 0, v3);
    sub_B6255();
    if ( byte_182AC9 )
      sub_BD3E3();
    if ( byte_182AC8 && byte_182AC8 != 2 )
    {
      if ( byte_182AC8 == 1 )
      {
        if ( byte_182978 )
        {
          v5 = sub_CDF5C(273);
          sub_121CE5(0, 0, v5);
        }
        v10 = word_199970;
        v9 = word_19995A;
        sub_BBA8E(12);
        sub_BBA8E(11);
        sub_90C4F(24, 7, a2, v9, v10, 11, 31, 0, 0, 3, 0);
      }
    }
    else
    {
      if ( byte_182978 )
      {
        v4 = sub_CDF5C(274);
        sub_121CE5(0, 0, v4);
      }
      sub_120DED(80, 80);
      sub_BB04E(3u);
      sub_C49C9(7, 24);
    }
    if ( byte_182AC9 )
    {
      sub_BEBDC();
      sub_BE366();
    }
    sub_124DEC();
    sub_124C08();
    byte_182ACA = 0;
  }
  else if ( byte_182AC9 )
  {
    sub_BEBDC();
    sub_BE366();
  }
  if ( byte_182AC8 == 1 )
  {
    sub_BEF4D(dword_19F7B8);
    if ( dword_19F7B8 != dword_19F82C )
      sub_BEF4D(dword_19F82C);
  }
  if ( byte_182AC9 )
  {
    sub_BD1FB();
    sub_BD26C();
    sub_BCE5E();
    sub_BCD70(a1);
    sub_BD3C1();
    sub_BD434();
    sub_BDD2F();
    sub_BF581();
    sub_BD7F2();
  }
  sub_C6782();
  sub_11E718();
  if ( byte_182ABB == 1 )
  {
    v6 = sub_123AE7();
    v7 = sub_123ABA();
    sub_B9B49(v7, v6);
  }
  return sub_131B5D(255, 19, 16, 9, 32, 40, 21, 2);
}
// 182978: using guessed type char byte_182978;
// 182ABB: using guessed type char byte_182ABB;
// 182AC8: using guessed type char byte_182AC8;
// 182AC9: using guessed type char byte_182AC9;
// 182ACA: using guessed type char byte_182ACA;
// 19994C: using guessed type int16_t word_19994C;
// 19995A: using guessed type int16_t word_19995A;
// 199970: using guessed type int16_t word_199970;
// 19F7B8: using guessed type int dword_19F7B8;
// 19F82C: using guessed type int dword_19F82C;


//----- (000BEF4D) --------------------------------------------------------
int sub_BEF4D( int a1)
{
  int16_t v2; // [esp+0h] [ebp-8h] BYREF
  int16_t v3; // [esp+4h] [ebp-4h] BYREF

  sub_911D5(a1, 7, 24, word_19995A, word_199970, 11, 31, 0, &v2, &v3);
  sub_C5DE7(v2, v3, 5, 5, 1, 1, 2);
  return sub_12C2C6(2);
}
// 19995A: using guessed type int16_t word_19995A;
// 199970: using guessed type int16_t word_199970;


//----- (000BEFA8) --------------------------------------------------------
_BOOL1 sub_BEFA8( int a1)
{
  int v1; // edx
  int v2; // eax
  int v3; // eax
  _BOOL1 result; // al

  v1 = a1;
  result = 0;
  if ( sub_E10EA(a1) )
  {
    v2 = 361 * v1 + dword_192B18;
    if ( !*(_WORD *)(v2 + 300)
      && !(uint16_t)sub_1276F0(
                              113 * *(uint8_t *)(17 * *(int16_t *)(v2 + 2) + dword_1930D4 + 2)
                            + dword_19306C
                            + 42,
                              word_19999C) )
    {
      sub_E1085(361 * v1 + dword_192B18);
      if ( v3 > 0 )
        return 1;
    }
  }
  return result;
}
// BF00D: variable 'v3' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;


//----- (000BF01B) --------------------------------------------------------
unsigned int sub_BF01B(int a1, int a2)
{
  _BYTE *v2; // eax
  _BYTE *v3; // eax
  _BYTE *v4; // eax
  int v5; // eax
  int v6; // eax
  _WORD *v7; // ecx
  int v8; // eax
  _BYTE *v9; // eax
  _BYTE *v10; // eax
  uint16_t v11; // ax
  _WORD *v12; // ecx
  int v13; // eax
  _BYTE *v14; // eax
  _BYTE *v15; // eax
  _BYTE *v16; // eax
  _BYTE *v17; // eax
  _BYTE *v18; // eax
  _WORD *v19; // ecx
  int v20; // eax
  _BYTE *v21; // eax
  _WORD *v22; // ecx
  int v23; // eax
  uint16_t v24; // ax
  int16_t v25; // cx
  _WORD *v26; // eax
  _BYTE *v27; // eax
  unsigned int result; // eax
  _BYTE *v29; // [esp-10h] [ebp-14h]
  _BYTE *v30; // [esp-10h] [ebp-14h]
  _BYTE *v31; // [esp-10h] [ebp-14h]
  _BYTE *v32; // [esp-10h] [ebp-14h]
  _BYTE *v33; // [esp-10h] [ebp-14h]

  word_182AE3 = -1000;
  word_182AE1 = -1000;
  v2 = (_BYTE *)sub_CDF5C(135);
  word_182AD3 = sub_114C72(v2, a2);
  v3 = (_BYTE *)sub_CDF5C(139);
  word_182ADB = sub_114C72(v3, a2);
  v4 = (_BYTE *)sub_CDF5C(140);
  word_182ADD = sub_114C72(v4, a2);
  v5 = sub_CDF5C(245);
  word_182AF5 = sub_11ADB4(v5, a2);
  v6 = sub_CDF5C(536);
  word_182AF7 = sub_11ADB4(v6, a2);
  v29 = (_BYTE *)sub_CDF5C(12);
  v7 = (_WORD *)sub_BBA8E(21);
  v8 = sub_CDF5C(12);
  word_182AD1 = (uint16_t)sub_1151B0(556, 459, v8, v7, v29, 40);
  v9 = (_BYTE *)sub_CDF5C(213);
  word_182AD9 = sub_114C72(v9, 459);
  if ( *(char *)(113 * dword_19F7B8 + dword_19306C + word_19999C + 66) == -1 )
  {
    v30 = (_BYTE *)sub_CDF5C(344);
    v12 = (_WORD *)sub_BBA8E(32);
    v13 = sub_CDF5C(12);
    v11 = (uint16_t)sub_1151B0(556, 427, v13, v12, v30, 40);
  }
  else
  {
    v10 = (_BYTE *)sub_CDF5C(344);
    v11 = sub_11438B(550, 357, 623, 445, v10, 0);
  }
  word_182AF1 = v11;
  v14 = (_BYTE *)sub_CDF5C(12);
  word_182AE7 = sub_11438B(310, 32, 510, 61, v14, 0);
  v15 = (_BYTE *)sub_CDF5C(12);
  word_182AE9 = sub_11438B(128, 32, 301, 61, v15, 0);
  v16 = (_BYTE *)sub_CDF5C(12);
  word_182AEB = sub_11438B(128, 62, 301, 91, v16, 0);
  v17 = (_BYTE *)sub_CDF5C(12);
  word_182AED = sub_11438B(128, 92, 301, 121, v17, 0);
  v18 = (_BYTE *)sub_CDF5C(12);
  word_182AEF = sub_11438B(128, 122, 301, 151, v18, 0);
  if ( byte_182AC9 )
  {
    v31 = (_BYTE *)sub_CDF5C(213);
    v19 = (_WORD *)sub_BBA8E(19);
    v20 = sub_CDF5C(12);
    word_182AD7 = (uint16_t)sub_1151B0(519, 123, v20, v19, v31, 40);
    v21 = (_BYTE *)sub_CDF5C(166);
    word_182AF3 = sub_11438B(525, 26, 630, 37, v21, 41);
    if ( sub_BEFA8(dword_19F7A8) )
    {
      v32 = (_BYTE *)sub_CDF5C(193);
      v22 = (_WORD *)sub_BBA8E(20);
      v23 = sub_CDF5C(12);
      v24 = (uint16_t)sub_1151B0(590, 123, v23, v22, v32, 40);
    }
    else
    {
      v33 = (_BYTE *)sub_CDF5C(193);
      v25 = *(_WORD *)(sub_BBA8E(20) + 2) + 123;
      v26 = (_WORD *)sub_BBA8E(20);
      v24 = sub_11438B(590, 123, *v26 + 590, v25, v33, 40);
    }
    word_182AD5 = v24;
  }
  else
  {
    word_182AD7 = -1000;
    word_182AD5 = -1000;
  }
  sub_BF399();
  sub_BDFB9();
  sub_BE44A();
  v27 = (_BYTE *)sub_CDF5C(12);
  result = sub_11438B(0, 0, 639, 479, v27, 0);
  word_182ACF[0] = result;
  return result;
}
// 182AC9: using guessed type char byte_182AC9;
// 182ACF: using guessed type int16_t word_182ACF[];
// 182AD1: using guessed type int16_t word_182AD1;
// 182AD3: using guessed type int16_t word_182AD3;
// 182AD5: using guessed type int16_t word_182AD5;
// 182AD7: using guessed type int16_t word_182AD7;
// 182AD9: using guessed type int16_t word_182AD9;
// 182ADB: using guessed type int16_t word_182ADB;
// 182ADD: using guessed type int16_t word_182ADD;
// 182AE1: using guessed type int16_t word_182AE1;
// 182AE3: using guessed type int16_t word_182AE3;
// 182AE7: using guessed type int16_t word_182AE7;
// 182AE9: using guessed type int16_t word_182AE9;
// 182AEB: using guessed type int16_t word_182AEB;
// 182AED: using guessed type int16_t word_182AED;
// 182AEF: using guessed type int16_t word_182AEF;
// 182AF1: using guessed type int16_t word_182AF1;
// 182AF3: using guessed type int16_t word_182AF3;
// 182AF5: using guessed type int16_t word_182AF5;
// 182AF7: using guessed type int16_t word_182AF7;
// 19306C: using guessed type int dword_19306C;
// 19999C: using guessed type int16_t word_19999C;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F7B8: using guessed type int dword_19F7B8;


//----- (000BF399) --------------------------------------------------------
char *sub_BF399()
{
  _BYTE *v0; // eax
  char *result; // eax
  _WORD *v2; // ecx
  int v3; // eax
  _BYTE *v4; // [esp-10h] [ebp-14h]

  if ( *(_BYTE *)(361 * dword_19F7A8 + dword_192B18 + 303) )
  {
    word_182ADF = -1000;
  }
  else
  {
    v0 = (_BYTE *)sub_CDF5C(12);
    word_182ADF = sub_11438B(0, 0, 639, 19, v0, 40);
  }
  result = (char *)(int16_t)sub_B9AD7(dword_19F7A8);
  if ( (int16_t)result == -1 || !byte_182AC9 )
  {
    word_182AE5 = -1000;
  }
  else
  {
    v4 = (_BYTE *)sub_CDF5C(12);
    v2 = (_WORD *)sub_BBA8E(24);
    v3 = sub_CDF5C(12);
    result = sub_1151B0(307, 159, v3, v2, v4, 40);
    word_182AE5 = (int16_t)result;
  }
  return result;
}
// 182AC9: using guessed type char byte_182AC9;
// 182ADF: using guessed type int16_t word_182ADF;
// 182AE5: using guessed type int16_t word_182AE5;
// 192B18: using guessed type int dword_192B18;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BF456) --------------------------------------------------------
unsigned int sub_BF456()
{
  int v0; // eax
  int v1; // edx

  sub_BF500();
  word_19F9EA[0] = -1000;
  word_19997A = -1000;
  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    word_190178[v1] = -1000;
  }
  while ( (int16_t)v0 < 72 );
  if ( byte_182AC9 )
  {
    sub_BCC3D();
    v0 = sub_BD236();
  }
  if ( byte_182AC8 )
  {
    if ( byte_182AC8 == 1 )
    {
      v1 = 24;
      LOWORD(v0) = sub_9023B(
                     7,
                     24,
                     word_19995A,
                     word_199970,
                     11,
                     31,
                     0,
                     0,
                     0,
                     word_19F9EA,
                     (int)word_190178,
                     &word_19997A);
    }
  }
  else
  {
    v1 = 24;
    v0 = sub_C4ED1(7, 24, 115);
  }
  return sub_BF01B(v0, v1);
}
// BF4F7: variable 'v0' is possibly undefined
// 182AC8: using guessed type char byte_182AC8;
// 182AC9: using guessed type char byte_182AC9;
// 190178: using guessed type int16_t word_190178[72];
// 19995A: using guessed type int16_t word_19995A;
// 199970: using guessed type int16_t word_199970;
// 19997A: using guessed type int16_t word_19997A;
// 19F9EA: using guessed type int16_t word_19F9EA[2];


//----- (000BF500) --------------------------------------------------------
int sub_BF500()
{
  int v0; // eax
  int v1; // edx
  int result; // eax
  int v3; // edx

  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    word_19F9CA[v1] = -1000;
  }
  while ( (int16_t)v0 < 5 );
  result = 0;
  do
  {
    v3 = (int16_t)result++;
    word_19F9BA[v3] = -1000;
  }
  while ( (int16_t)result < 3 );
  return result;
}
// 19F9BA: using guessed type int16_t word_19F9BA[];
// 19F9CA: using guessed type int16_t word_19F9CA[5];


//----- (000BF52F) --------------------------------------------------------
int sub_BF52F()
{
  int result; // eax
  int v1; // edx

  word_19F9EA[0] = -1000;
  word_19997A = -1000;
  result = 0;
  do
  {
    v1 = (int16_t)result++;
    word_190178[v1] = -1000;
  }
  while ( (int16_t)result < 72 );
  return result;
}
// 190178: using guessed type int16_t word_190178[72];
// 19997A: using guessed type int16_t word_19997A;
// 19F9EA: using guessed type int16_t word_19F9EA;


//----- (000BF55A) --------------------------------------------------------
char sub_BF55A()
{
  int v0; // eax

  sub_1205E6(1, 0, 255);
  v0 = sub_BBA8E(0);
  sub_12B79D(v0);
  return sub_133237();
}


//----- (000BF581) --------------------------------------------------------
void sub_BF581()
{
  if ( byte_182AC8 )
  {
    if ( byte_182AC8 == 1 && word_19F9F0 != -1 )
    {
      sub_BADA0(dword_19306C + 113 * word_19F9F0);
      sub_BEF4D(word_19F9F0);
    }
  }
  else
  {
    sub_C500B(7, 24);
  }
}
// 182AC8: using guessed type char byte_182AC8;
// 19306C: using guessed type int dword_19306C;
// 19F9F0: using guessed type int16_t word_19F9F0;


//----- (000BF5D4) --------------------------------------------------------
int sub_BF5D4()
{
  int result; // eax
  int v1; // ebx

  result = word_19F9F0;
  if ( word_19F9F0 != -1 )
  {
    v1 = 113 * word_19F9F0 + dword_19306C;
    sub_BAEFE();
    sub_1210FD(61, 135, v1);
    return sub_BEF4D(word_19F9F0);
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 19F9F0: using guessed type int16_t word_19F9F0;


//----- (000BF615) --------------------------------------------------------
void sub_BF615()
{
  sub_C500B(7, 24);
}


//----- (000BF627) --------------------------------------------------------
void sub_BF627(int16_t *a1, _WORD *a2)
{
  int16_t j; // cx
  int16_t v4; // di
  int16_t v5; // ax
  int16_t v6; // ax
  int16_t i; // cx

  sub_120DED(80, 80);
  sub_BB04E(3u);
  word_182ABC = -1;
  if ( byte_182ABB )
  {
    if ( byte_182ABB == 1 )
    {
      for ( i = 0; i < 3; ++i )
      {
        if ( *a1 == word_19F9E0[i] )
        {
          sub_B9E94(dword_19F7A8);
          word_19994C = 0;
          sub_119281();
          byte_182ACA = 1;
          sub_1191CA((int)sub_BED21, 1);
          sub_CDB01();
          *a1 = 0;
        }
      }
    }
  }
  else
  {
    for ( j = 0; j < 3; ++j )
    {
      v4 = *a1;
      if ( *a1 == word_19F9E0[j] )
      {
        sub_BCBA0();
        if ( v5 != -1 )
        {
          byte_182ABB = 1;
          sub_B9C3D(dword_19F7A8, v5, v4);
          byte_182ACA = 1;
          sub_BB1A6(dword_19F7A8, v4);
          *a1 = 0;
        }
      }
      if ( *a2 == word_19F9E0[j] )
      {
        sub_BCBE6();
        word_182ABC = v6;
      }
    }
  }
}
// BF672: variable 'v5' is possibly undefined
// BF6BC: variable 'v6' is possibly undefined
// 182ABB: using guessed type char byte_182ABB;
// 182ABC: using guessed type int16_t word_182ABC;
// 182ACA: using guessed type char byte_182ACA;
// 19994C: using guessed type int16_t word_19994C;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F9E0: using guessed type int16_t word_19F9E0[];


//----- (000BF72C) --------------------------------------------------------
int sub_BF72C(_WORD *a1, _WORD *a2, int16_t *a3)
{
  int v4; // eax
  int v5; // ecx
  int result; // eax

  word_182ABE = -1;
  if ( byte_182ABB == 2 && *a1 )
  {
    v4 = sub_CDF5C(394);
    sub_C5B5F(v4);
    sub_BB0C4();
    ++*(_WORD *)(361 * dword_19F7A8 + dword_192B18 + 2 * word_182AC6 + 304);
    sub_BB1FA();
    sub_BB1A6(dword_19F7A8, (int)a3);
    sub_BB2CB((int)a3);
    *a1 = 0;
  }
  v5 = 0;
  do
  {
    if ( *a1 == word_182AF9[(int16_t)v5] )
    {
      sub_CF1E0(v5, (int)a1, a3);
      word_19994C = 0;
      sub_119281();
      byte_182ACA = 1;
      sub_1191CA((int)sub_BED21, 1);
      sub_CDB01();
      *a1 = 0;
    }
    result = (int16_t)v5;
    if ( *a2 == word_182AF9[(int16_t)v5] )
      word_182ABE = v5;
    ++v5;
  }
  while ( (int16_t)v5 < 2 );
  return result;
}
// 182ABB: using guessed type char byte_182ABB;
// 182ABE: using guessed type int16_t word_182ABE;
// 182AC6: using guessed type int16_t word_182AC6;
// 182ACA: using guessed type char byte_182ACA;
// 182AF9: using guessed type int16_t word_182AF9[2];
// 192B18: using guessed type int dword_192B18;
// 19994C: using guessed type int16_t word_19994C;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BF802) --------------------------------------------------------
char sub_BF802(int16_t *a1, int16_t *a2)
{
  int i; // edi
  int v4; // ebx
  int v5; // eax
  int16_t v6; // bx
  int16_t v7; // ax
  int16_t v9; // ax
  int16_t v10; // ax
  int16_t v11; // ax
  int16_t v12; // dx
  int v13; // eax
  _BYTE v14[2000]; // [esp+0h] [ebp-7D8h] BYREF
  int16_t v15; // [esp+7D0h] [ebp-8h] BYREF
  int v16; // [esp+7D4h] [ebp-4h] BYREF

  if ( byte_182AC8 )
  {
    if ( byte_182AC8 != 1 )
    {
      if ( byte_182AC8 == 2 )
      {
        sub_CA16D(word_182ACC, (int)v14);
        byte_182AC8 = 0;
        word_182ACC = -1;
        sub_C5B5F((int)v14);
        word_19994C = 0;
        sub_119281();
        byte_182ACA = 1;
        sub_1191CA((int)sub_BED21, 1);
        sub_CDB01();
      }
      return 1;
    }
    v11 = sub_890EF(*a2, *a1, (int16_t *)&v16, &v15);
    v12 = *a1;
    dword_19F828 = -1;
    if ( v12 == word_19F9EA[0] )
    {
      byte_182AC8 = 0;
      word_19F9EE = -1;
    }
    else
    {
      if ( v11 == 4 )
      {
        word_19F9F0 = v16;
        return 1;
      }
      if ( v11 != 2 )
      {
        if ( !v11 )
        {
          if ( byte_182978 )
          {
            v13 = sub_CDF5C(312);
            sub_121CE5(0, 0, v13);
          }
          byte_182AC8 = 0;
          word_19F9EE = -1;
          byte_182ACA = 1;
          dword_19F82C = v15;
        }
        return 1;
      }
      sub_8238B(
        5060 / word_19995A * (word_1999A0 * word_199968 / 10) / 10,
        4000 / word_199970 * (word_1999A0 * word_19996A / 10) / 10);
    }
    goto LABEL_4;
  }
  if ( *a1 == word_19F9BA[0] )
  {
    byte_182AC8 = 1;
LABEL_4:
    byte_182ACA = 1;
    return 1;
  }
  for ( i = 0; (int16_t)i < 5; ++i )
  {
    if ( *a1 == word_19F9CA[(int16_t)i] )
    {
      if ( byte_182ABB != 1 )
      {
        if ( *(int16_t *)(dword_1930D4 + 17 * sub_79C54(dword_19F82C, i)) == -1
          || *(_BYTE *)(361 * *(int16_t *)(dword_1930D4 + 17 * sub_79C54(dword_19F82C, i)) + dword_192B18 + 6) == 1
          || *(int16_t *)(dword_1930D4 + 17 * sub_79C54(dword_19F82C, i)) == dword_19F7A8
          || *(char *)(361 * *(int16_t *)(17 * sub_79C54(dword_19F82C, i) + dword_1930D4) + dword_192B18) != word_19999C )
        {
          return 1;
        }
        word_199830 = dword_19F82C;
        word_199832 = i;
        word_199834 = *(_WORD *)(dword_1930D4 + 17 * sub_79C54(dword_19F82C, i));
        v4 = (int16_t)dword_19F7A8;
        sub_BAA3B(dword_19F7A8);
        v5 = dword_192B18 + 361 * v4;
        if ( *(int16_t *)(v5 + 277) == -1 )
          *(_WORD *)(v5 + 277) = -2;
        sub_BB2CB(i);
        sub_11C2F0();
        sub_C683E();
        sub_119281();
        byte_182ACA = 1;
        v6 = word_19999C;
        v7 = sub_79C54(dword_19F82C, i);
        sub_786E9(*(_WORD *)(dword_1930D4 + 17 * v7), v6);
        return 0;
      }
      v9 = sub_79C54(dword_19F82C, i);
      sub_B9E94(*(_WORD *)(17 * v9 + dword_1930D4));
      word_19994C = 0;
      sub_119281();
      byte_182ACA = 1;
      sub_1191CA((int)sub_BED21, 1);
      sub_CDB01();
    }
    else if ( *a1 == word_19F9C0[(int16_t)i] )
    {
      if ( *(_BYTE *)(dword_1930D4 + 17 * sub_79C54(dword_19F82C, i) + 4) == 3 )
      {
        v10 = sub_79C54(dword_19F82C, i);
        byte_182AC8 = 2;
        word_182ACC = v10;
        return 1;
      }
    }
    else if ( *a2 == word_19F9CA[(int16_t)i] )
    {
      word_19F9EE = sub_79C54(dword_19F82C, i);
    }
  }
  return 1;
}
// 182978: using guessed type char byte_182978;
// 182ABB: using guessed type char byte_182ABB;
// 182AC8: using guessed type char byte_182AC8;
// 182ACA: using guessed type char byte_182ACA;
// 182ACC: using guessed type int16_t word_182ACC;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 199834: using guessed type int16_t word_199834;
// 19994C: using guessed type int16_t word_19994C;
// 19995A: using guessed type int16_t word_19995A;
// 199968: using guessed type int16_t word_199968;
// 19996A: using guessed type int16_t word_19996A;
// 199970: using guessed type int16_t word_199970;
// 19999C: using guessed type int16_t word_19999C;
// 1999A0: using guessed type int16_t word_1999A0;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F828: using guessed type int dword_19F828;
// 19F82C: using guessed type int dword_19F82C;
// 19F9BA: using guessed type int16_t word_19F9BA[];
// 19F9C0: using guessed type int16_t word_19F9C0[5];
// 19F9CA: using guessed type int16_t word_19F9CA[5];
// 19F9EA: using guessed type int16_t word_19F9EA[2];
// 19F9EE: using guessed type int16_t word_19F9EE;
// 19F9F0: using guessed type int16_t word_19F9F0;


//----- (000BFC0B) --------------------------------------------------------
int sub_BFC0B( int a1)
{
  int v3; // ebx
  int v4; // eax
  int v5; // edi
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  char *v10; // eax
  int64_t v11; // rax
  int16_t v13; // ax
  _BYTE *v14; // eax
  int16_t v15; // ax
  char *v16; // eax
  int v17; // [esp-8h] [ebp-200h]
  int v18; // [esp-4h] [ebp-1FCh]
  int v19; // [esp-4h] [ebp-1FCh]
  _BYTE v20[500]; // [esp+0h] [ebp-1F8h] BYREF
  int v21; // [esp+1F4h] [ebp-4h]

  v3 = 361 * a1;
  v4 = v3 + dword_192B18;
  if ( *(_WORD *)(v3 + dword_192B18 + 300) )
  {
    v14 = (_BYTE *)sub_CDF5C(586);
    goto LABEL_20;
  }
  v21 = *(uint8_t *)(dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v4 + 2) + 2) + 42);
  v5 = v21 >> word_19999C;
  if ( ((v21 >> word_19999C) & 1) != 0 )
  {
    v13 = 569;
    goto LABEL_12;
  }
  v6 = *(int16_t *)(v4 + 277);
  if ( v6 == -2 || v6 == -3 )
  {
    v13 = 568;
    goto LABEL_12;
  }
  sub_E1085(v4);
  if ( v7 <= 0 )
  {
    if ( *(int16_t *)(v3 + dword_192B18 + 277) == -1 )
      v13 = 587;
    else
      v13 = 578;
    goto LABEL_12;
  }
  if ( !sub_E10EA(a1) )
  {
    sub_E1085(v3 + dword_192B18);
    v19 = (int16_t)(v15 - *(_WORD *)(3753 * *(char *)(v3 + dword_192B18) + dword_197F98 + 50));
    v16 = (char *)sub_CDF5C(564);
    sprintf(v20, v16, v19);
    v14 = v20;
    goto LABEL_20;
  }
  if ( !sub_BEFA8(a1) )
  {
    v13 = 432;
LABEL_12:
    v14 = (_BYTE *)sub_CDF5C(v13);
LABEL_20:
    sub_C5B5F((int)v14);
    word_19994C = 0;
    sub_119281();
    byte_182ACA = 1;
    sub_1191CA((int)sub_BED21, 1);
    return sub_CDB01();
  }
  v8 = *(int16_t *)(v3 + dword_192B18 + 293);
  v18 = (int16_t)sub_E0F95(v3 + dword_192B18) - v8;
  sub_E1085(v3 + dword_192B18);
  v17 = v9;
  v10 = (char *)sub_CDF5C(269);
  v11 = sprintf(v20, v10, v17, v18);
  sub_77658((int)v20);
  if ( (_WORD)v11 )
    sub_E109D(SWORD2(v11));
  return sub_BB1A6(a1, v5);
}
// BFC90: variable 'v7' is possibly undefined
// BFCD3: variable 'v9' is possibly undefined
// BFCFC: variable 'v11' is possibly undefined
// BFD4D: variable 'v15' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;


//----- (000BFDEE) --------------------------------------------------------
char sub_BFDEE(_WORD *a1, int a2, int a3)
{
  _WORD *v3; // ebx
  int16_t v4; // ax
  int16_t v5; // ax
  int16_t v6; // ax
  int16_t v7; // bx
  _BOOL1 v8; // al
  int v9; // eax
  int16_t v10; // dx
  int16_t v11; // ax
  int16_t v13; // ax

  v3 = a1;
  if ( *a1 != word_182ADF )
  {
    v4 = *a1;
    if ( *v3 == word_182AF1 )
    {
      word_199836 = 1;
      word_199838 = dword_19F7B8;
      v5 = word_199A08;
      word_199A08 = 29;
LABEL_7:
      word_199A10 = v5;
      return 0;
    }
    if ( v4 == word_182AE1 && !byte_182AC8 )
    {
      byte_182AC8 = 1;
LABEL_11:
      byte_182ACA = 1;
      return 1;
    }
    if ( *v3 == word_182AE3 && byte_182AC8 == 1 )
    {
      byte_182AC8 = 0;
      word_19F9EE = -1;
      goto LABEL_11;
    }
    LOWORD(a1) = *v3;
    if ( *v3 == word_182AE5 )
    {
      sub_C5934((int)a1, a2, (int)v3);
      word_19994C = 0;
      v7 = v6;
      sub_119281();
      byte_182ACA = 1;
      sub_1191CA((int)sub_BED21, 1);
      sub_CDB01();
      if ( v7 != -1 )
        sub_B9E94(v7);
      goto LABEL_3;
    }
    if ( (_WORD)a1 == word_182AF3 )
    {
      v8 = *(_BYTE *)(361 * dword_19F7A8 + dword_192B18 + 297) == 0;
      word_19994C = 0;
      *(_BYTE *)(dword_192B18 + 361 * dword_19F7A8 + 297) = v8;
      sub_119281();
LABEL_29:
      byte_182ACA = 1;
      sub_1191CA((int)sub_BED21, 1);
      sub_CDB01();
      return 1;
    }
    if ( (_WORD)a1 == word_182AD5 )
    {
      sub_BFC0B(dword_19F7A8);
      sub_11C2F0();
      sub_C683E();
      sub_BF456();
      word_19994C = 0;
      sub_119281();
      byte_182ACA = 1;
      sub_1191CA((int)sub_BED21, 1);
      sub_CDB01();
      *v3 = 0;
      sub_119441();
      sub_117174(3);
      return 1;
    }
    if ( (_WORD)a1 == word_182AD9 )
    {
      if ( !byte_182ACB )
        goto LABEL_4;
      sub_C0B87();
      word_19994C = 0;
      goto LABEL_28;
    }
    if ( (_WORD)a1 == word_182AE7 )
    {
      sub_DDEFB(dword_19F7A8);
LABEL_27:
      word_19994C = 0;
LABEL_28:
      sub_119281();
      goto LABEL_29;
    }
    if ( (_WORD)a1 == word_182AE9 )
    {
      sub_E08C8(dword_19F7A8);
      goto LABEL_27;
    }
    if ( (_WORD)a1 == word_182AEB )
    {
      sub_DEB1D(dword_19F7A8);
      goto LABEL_27;
    }
    if ( (_WORD)a1 == word_182AED )
    {
      sub_DF518(dword_19F7A8);
      goto LABEL_27;
    }
    if ( (_WORD)a1 == word_182AEF )
    {
      sub_E03C3(dword_19F7A8);
      goto LABEL_27;
    }
    if ( (_WORD)a1 == word_182AD7 )
    {
      v5 = word_199A08;
      word_199A08 = 25;
      goto LABEL_7;
    }
    if ( (_WORD)a1 == word_182ADB )
    {
      v9 = (int16_t)dword_19F7A8;
      v10 = 0;
LABEL_42:
      v11 = sub_C01FC(v9, v10);
      if ( v11 == dword_19F7A8 )
        return 1;
      sub_C0257(v11, a3);
      return 0;
    }
    if ( (_WORD)a1 == word_182AF7 && IsMemPoolReady_110B5C() )
    {
      byte_182ACB = byte_182ACB == 0;
    }
    else
    {
      v13 = *v3;
      if ( *v3 != word_182AF5 )
      {
        if ( v13 != word_182ADD )
        {
          if ( v13 == word_182AD3 )
          {
            *v3 = word_182AD1;
          }
          else if ( word_19994C )
          {
            word_19994C = 0;
            sub_119281();
            byte_182ACA = 1;
            sub_1191CA((int)sub_BED21, 1);
            sub_CDB01();
            word_19994C = 0;
          }
          return 1;
        }
        v10 = 1;
        v9 = (int16_t)dword_19F7A8;
        goto LABEL_42;
      }
      *(_WORD *)(dword_192B18 + 361 * dword_19F7A8 + 293) = sub_E0F95(dword_192B18 + 361 * dword_19F7A8);
    }
    sub_8A552(word_19999C, 6);
    sub_147D7(51);
    return 1;
  }
  sub_CD969();
LABEL_3:
  word_19994C = 0;
  sub_119281();
  byte_182ACA = 1;
  sub_1191CA((int)sub_BED21, 1);
  sub_CDB01();
LABEL_4:
  sub_BB1A6(dword_19F7A8, a3);
  return 1;
}
// BFEE4: variable 'v6' is possibly undefined
// 182AC8: using guessed type char byte_182AC8;
// 182ACA: using guessed type char byte_182ACA;
// 182ACB: using guessed type char byte_182ACB;
// 182AD1: using guessed type int16_t word_182AD1;
// 182AD3: using guessed type int16_t word_182AD3;
// 182AD5: using guessed type int16_t word_182AD5;
// 182AD7: using guessed type int16_t word_182AD7;
// 182AD9: using guessed type int16_t word_182AD9;
// 182ADB: using guessed type int16_t word_182ADB;
// 182ADD: using guessed type int16_t word_182ADD;
// 182ADF: using guessed type int16_t word_182ADF;
// 182AE1: using guessed type int16_t word_182AE1;
// 182AE3: using guessed type int16_t word_182AE3;
// 182AE5: using guessed type int16_t word_182AE5;
// 182AE7: using guessed type int16_t word_182AE7;
// 182AE9: using guessed type int16_t word_182AE9;
// 182AEB: using guessed type int16_t word_182AEB;
// 182AED: using guessed type int16_t word_182AED;
// 182AEF: using guessed type int16_t word_182AEF;
// 182AF1: using guessed type int16_t word_182AF1;
// 182AF3: using guessed type int16_t word_182AF3;
// 182AF5: using guessed type int16_t word_182AF5;
// 182AF7: using guessed type int16_t word_182AF7;
// 192B18: using guessed type int dword_192B18;
// 199836: using guessed type int16_t word_199836;
// 199838: using guessed type int16_t word_199838;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F7B8: using guessed type int dword_19F7B8;
// 19F9EE: using guessed type int16_t word_19F9EE;


//----- (000C01FC) --------------------------------------------------------
int sub_C01FC(int result, int a2)
{
  int16_t v2; // bx
  _BYTE *v4; // edx

  v2 = result;
  do
  {
    if ( a2 )
    {
      if ( (--result & 0x8000u) != 0 )
        LOWORD(result) = word_199996;
    }
    else
    {
      result = ((int16_t)result + 1) % word_199996;
    }
    v4 = (_BYTE *)(361 * (int16_t)result + dword_192B18);
  }
  while ( (*(_BYTE *)(dword_192B18 + 361 * v2) != *v4 || v4[6]) && (_WORD)result != v2 );
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (000C0257) --------------------------------------------------------
int sub_C0257( int a1, int a2)
{
  int v3; // edx
  int v4; // eax
  int v5; // eax
  int16_t v6; // dx

  v3 = (int16_t)dword_19F7A8;
  sub_BAA3B(dword_19F7A8);
  v4 = dword_192B18 + 361 * v3;
  if ( *(int16_t *)(v4 + 277) == -1 )
    *(_WORD *)(v4 + 277) = -2;
  v5 = dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * a1 + 2);
  word_199834 = a1;
  v6 = *(uint8_t *)(v5 + 2);
  LOWORD(v5) = *(uint8_t *)(v5 + 3);
  word_199830 = v6;
  word_199832 = v5;
  sub_BB2CB(a2);
  sub_11C2F0();
  sub_C683E();
  sub_119281();
  byte_182ACA = 1;
  return sub_786E9(a1, word_19999C);
}
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 199834: using guessed type int16_t word_199834;
// 19999C: using guessed type int16_t word_19999C;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000C02F9) --------------------------------------------------------
char sub_C02F9(int16_t *a1, int16_t *a2, int16_t *a3)
{
  char v4; // al
  char v6; // [esp+0h] [ebp-4h]

  v4 = sub_BF802(a1, a2);
  v6 = v4;
  if ( byte_182AC8 != 2 && v4 )
  {
    v6 = sub_BFDEE(a1, (int)a2, (int)a3);
    sub_BF627(a1, a2);
    sub_BF72C(a1, a2, a3);
    sub_BE09C(a1, a2);
    sub_BE530(a1, a2);
  }
  return v6;
}
// 182AC8: using guessed type char byte_182AC8;


//----- (000C035E) --------------------------------------------------------
int sub_C035E(int a1)
{
  int v1; // eax
  int v2; // edx
  char *v3; // eax
  int v4; // edx
  int v5; // eax
  int16_t v6; // ax
  char *v7; // eax
  char *v8; // eax
  int16_t *v10; // [esp-8h] [ebp+76h]
  int16_t *v11; // [esp-4h] [ebp+7Ah]
  int16_t *v12; // [esp-4h] [ebp+7Ah]
  _BYTE *v13; // [esp-4h] [ebp+7Ah]
  _BYTE v14[500]; // [esp+0h] [ebp+7Eh] BYREF

  if ( *(_BYTE *)(dword_192B18 + 361 * dword_19F7A8 + 303) == 4
    && (sub_BC972(dword_19F7A8, -1, -1, -1, -1, 1) > 0 || sub_BC932(dword_19F7A8)) )
  {
    sub_CD969();
    sub_BB1A6(dword_19F7A8, a1);
    word_19994C = 0;
    sub_119281();
    byte_182ACA = 1;
    sub_1191CA((int)sub_BED21, 1);
    sub_CDB01();
  }
  v1 = 361 * dword_19F7A8 + dword_192B18;
  v2 = *(int16_t *)(v1 + 291);
  if ( v2 != -1 )
  {
    if ( v2 == -39 )
    {
      v11 = sub_77B28(*(_WORD *)(v1 + 2));
      v3 = (char *)sub_CDF5C(64);
      sprintf(v14, v3, v11);
      sub_C5B5F((int)v14);
      word_19994C = 0;
      sub_119281();
      byte_182ACA = 1;
      sub_1191CA((int)sub_BED21, 1);
      sub_CDB01();
      v4 = 361 * dword_19F7A8;
      v5 = dword_192B18;
    }
    else
    {
      if ( v2 == -40 )
      {
        v12 = sub_77B28(*(_WORD *)(v1 + 2));
        v6 = 65;
      }
      else
      {
        if ( v2 != -41 )
        {
          v13 = sub_B2FFA(*(_WORD *)(v1 + 291));
          v10 = sub_77B28(*(_WORD *)(361 * dword_19F7A8 + dword_192B18 + 2));
          v8 = (char *)sub_CDF5C(57);
          sprintf(v14, v8, v10, v13);
          sub_C5B5F((int)v14);
          word_19994C = 0;
          sub_119281();
          byte_182ACA = 1;
          sub_1191CA((int)sub_BED21, 1);
          sub_CDB01();
          v5 = 361 * dword_19F7A8;
          v4 = dword_192B18;
          goto LABEL_14;
        }
        v12 = sub_77B28(*(_WORD *)(v1 + 2));
        v6 = 66;
      }
      v7 = (char *)sub_CDF5C(v6);
      sprintf(v14, v7, v12);
      sub_C5B5F((int)v14);
      word_19994C = 0;
      sub_119281();
      byte_182ACA = 1;
      sub_1191CA((int)sub_BED21, 1);
      sub_CDB01();
      v5 = 361 * dword_19F7A8;
      v4 = dword_192B18;
    }
LABEL_14:
    *(_WORD *)(v4 + v5 + 291) = -1;
  }
  return nullsub_8();
}
// C0589: using guessed type int nullsub_8(void);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 19994C: using guessed type int16_t word_19994C;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000C058A) --------------------------------------------------------
int16_t sub_C058A(int a1, int16_t *a2)
{
  int v2; // ebp
  int v3; // esi
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  int v10; // eax
  _DWORD *v11; // eax
  int v12; // eax
  int16_t result; // ax
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // [esp+0h] [ebp-10h] BYREF
  char *v21; // [esp+4h] [ebp-Ch] BYREF
  _BOOL1 v22; // [esp+8h] [ebp-8h]
  char v23; // [esp+Ch] [ebp-4h]

  v20 = 0;
  v21 = 0;
  v3 = sub_12484C();
  sub_124820(dword_19F7A8);
  sub_12B65C();
  dword_19F7B8 = word_199830;
  dword_19F7C8 = word_199832;
  byte_182ACE = 1;
  dword_19F7BC = sub_79C54(word_199830, word_199832);
  v23 = 0;
  v22 = 0;
  v4 = *(int16_t *)(dword_1930D4 + 17 * dword_19F7BC);
  word_19F9EE = -1;
  dword_19F7A8 = v4;
  word_19F9F0 = -1;
  dword_19F82C = dword_19F7B8;
  if ( v4 == -1 )
  {
    byte_182AC9 = 0;
    byte_182AC8 = 2;
    word_182ACC = dword_19F7BC;
  }
  else
  {
    byte_182AC9 = 1;
    byte_182AC8 = 0;
    word_19F9EE = -1;
  }
  sub_119441();
  sub_117174(3);
  sub_CDB01();
  v5 = dword_192B18;
  LOWORD(a2) = word_19999C;
  word_19999C = *(char *)(dword_192B18 + 361 * dword_19F7A8);
  v6 = sub_B0A24();
  sub_FE8BE((int)v6, v5, a1, a2);
  v7 = sub_C52F6();
  sub_FE8BE((int)v7, v5, a1, a2);
  v8 = sub_BB7DB();
  sub_FE8BE((int)v8, v5, a1, a2);
  v9 = sub_BB7BB();
  sub_FE8BE((int)v9, v5, a1, a2);
  v10 = sub_BB8DD();
  sub_FE8BE(v10, v5, a1, a2);
  sub_B5FBE();
  v11 = sub_AF74F();
  sub_FE8BE((int)v11, v5, a1, a2);
  v12 = sub_BB91D();
  sub_FE8BE(v12, v5, a1, a2);
  sub_BB822();
  if ( byte_182AC9 )
  {
    sub_BC30B((int16_t)dword_19F7A8, 0);
    if ( word_199A08 != word_199A10 )
      word_19F9E8 = word_199A10;
    sub_11C2F0();
    sub_120DED(80, 80);
    sub_BB04E(3u);
    sub_123E6C((int)&unk_1828C0, 1);
    sub_124D41();
    sub_124C08();
    if ( sub_C5C85() )
      sub_C5BB9();
    sub_1205E6(1, 0, 255);
    v14 = sub_BBA8E(0);
    sub_12B79D(v14);
    sub_133237();
    if ( sub_C5C85() )
    {
      sub_132C80(100);
      sub_131922(0, 255);
    }
    sub_131F7B();
    sub_BAE88();
    sub_11C2F0();
    sub_C683E();
    sub_BF456();
    byte_182ACA = 1;
    sub_1191CA((int)sub_BED21, 1);
    sub_128C32(0, 0, 639, 479, 0);
    sub_BED21(v2, v3);
    sub_C5C44();
    sub_124C08();
    v15 = 1;
    sub_123E6C((int)&unk_17CF00, 1);
    sub_C035E((uint16_t)a2);
    do
    {
      sub_12C2A0();
      ++dword_19F7B4;
      if ( v22 )
      {
        sub_11C2F0();
        sub_C683E();
        sub_BF456();
        v20 = 0;
      }
      LOBYTE(v16) = sub_BED21(v2, v3);
      v17 = sub_1077D(v16, v15, 639, a2);
      v20 = sub_1171AB(v17, v15, 639, 479);
      v21 = sub_114177();
      v15 = (int)&v21;
      v22 = (_WORD)v20 != 0;
      if ( !sub_C02F9((int16_t *)&v20, (int16_t *)&v21, a2) )
        v23 = 1;
      sub_12C2C6(1);
    }
    while ( !v23
         && (byte_182AC9 && (_WORD)v20 != word_182AD1
          || !byte_182AC9 && ((_WORD)v20 != word_182ACF[0] || (_WORD)v20 != word_182AD1)) );
    sub_BB2CB((uint16_t)a2);
    sub_11C2F0();
    sub_C683E();
    sub_119281();
    byte_182ACE = 0;
    word_19999C = (int16_t)a2;
    if ( !v23 )
    {
      v18 = (int16_t)dword_19F7A8;
      sub_BAA3B(dword_19F7A8);
      v19 = dword_192B18 + 361 * v18;
      if ( *(int16_t *)(v19 + 277) == -1 )
        *(_WORD *)(v19 + 277) = -2;
      if ( word_199A08 == word_199A10 )
      {
        word_199A08 = word_19F9E8;
        word_199A10 = word_19F9E8;
      }
      else
      {
        word_199A08 = word_199A10;
      }
    }
    sub_1196F7();
    return sub_124820(v3);
  }
  else
  {
    result = word_199A10;
    word_199A08 = word_199A10;
  }
  return result;
}
// C07F1: variable 'v2' is possibly undefined
// C0840: variable 'v16' is possibly undefined
// 182AC8: using guessed type char byte_182AC8;
// 182AC9: using guessed type char byte_182AC9;
// 182ACA: using guessed type char byte_182ACA;
// 182ACC: using guessed type int16_t word_182ACC;
// 182ACE: using guessed type char byte_182ACE;
// 182ACF: using guessed type int16_t word_182ACF[];
// 182AD1: using guessed type int16_t word_182AD1;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F7B4: using guessed type int dword_19F7B4;
// 19F7B8: using guessed type int dword_19F7B8;
// 19F7BC: using guessed type int dword_19F7BC;
// 19F7C8: using guessed type int dword_19F7C8;
// 19F82C: using guessed type int dword_19F82C;
// 19F9E8: using guessed type int16_t word_19F9E8;
// 19F9EE: using guessed type int16_t word_19F9EE;
// 19F9F0: using guessed type int16_t word_19F9F0;


//----- (000C0965) --------------------------------------------------------
void sub_C0965()
{
  JUMPOUT(0xBBBB2);
}
// C0975: control flows out of bounds to BBBB2


//----- (000C097A) --------------------------------------------------------
void sub_C097A(int16_t *a1)
{
  int v2; // ecx
  char *v3; // ebx
  int v4; // eax
  int16_t *v5; // ecx
  int16_t *v6; // eax

  sub_12E332(19);
  sub_12D8F5(30, 30, dword_19F7C4);
  if ( (unsigned int)a1 < 0xFFFFFFFE )
  {
    if ( a1 != (int16_t *)-3 )
    {
      if ( *a1 > 24 || a1[1] > 24 )
      {
        if ( byte_182978 )
        {
          v4 = sub_CDF5C(290);
          sub_121CE5(0, 1, v4);
        }
        sub_12C574();
      }
      sub_12F578(dword_19F7C4, (int)a1);
LABEL_14:
      v5 = (int16_t *)dword_19F7C4;
      v6 = (int16_t *)sub_BBA8E(15);
      sub_12F7E6(0, 0, v6, v5);
      JUMPOUT(0xC0A45);
    }
    v2 = dword_19F7C4;
    v3 = (char *)sub_CDF5C(535);
  }
  else
  {
    if ( a1 == (int16_t *)-1 )
      goto LABEL_14;
    v3 = aWho;
    v2 = dword_19F7C4;
  }
  sub_122A6E(0, 0, (int)v3, v2);
  goto LABEL_14;
}
// C0A43: control flows out of bounds to C0A45
// 182978: using guessed type char byte_182978;
// 19F7C4: using guessed type int dword_19F7C4;


//----- (000C0A5F) --------------------------------------------------------
int16_t sub_C0A5F(int16_t *a1)
{
  int v3; // eax

  if ( *a1 > 24 || a1[1] > 24 )
  {
    if ( byte_182978 )
    {
      v3 = sub_CDF5C(290);
      sub_121CE5(0, 1, v3);
    }
    sub_12C574();
  }
  sub_12F578(dword_19F7C4, (int)a1);
  sub_12E332(19);
  sub_12E1E0(0, 0, (int16_t *)dword_19F7C4, 19);
  return sub_123E6C((int)&unk_17CF0C, 1);
}
// 182978: using guessed type char byte_182978;
// 19F7C4: using guessed type int dword_19F7C4;


//----- (000C0ABC) --------------------------------------------------------
void sub_C0ABC()
{
  sub_12E332(19);
  sub_123E6C((int)&unk_17CF0C, 1);
  if ( word_182974 != -1 && (int16_t)sub_B9AD7(word_182974) != -1 )
    sub_1172D4();
}
// 182974: using guessed type int16_t word_182974;


//----- (000C0AF4) --------------------------------------------------------
void sub_C0AF4()
{
  sub_123E6C((int)&unk_17CF00, 1);
  JUMPOUT(0xBB218);
}
// C0B04: control flows out of bounds to BB218


//----- (000C0B09) --------------------------------------------------------
char sub_C0B09()
{
  int v0; // eax

  sub_12D8F5(30, 30, dword_19F7C4);
  v0 = sub_BB54D(0, 2u, *(uint8_t *)(dword_197F98 + 3753 * word_19999C + 37));
  sub_12F578(dword_19F7C4, v0);
  sub_13743E(dword_19F7C4, 240);
  sub_12DAFC(dword_19F7C4);
  return sub_12E64F((int16_t *)dword_19F7C4, (int16_t *)dword_19F7C4, 229, 0);
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19F7C4: using guessed type int dword_19F7C4;


//----- (000C0B81) --------------------------------------------------------
int sub_C0B81()
{
  return dword_19F7C4;
}
// 19F7C4: using guessed type int dword_19F7C4;


//----- (000C0B87) --------------------------------------------------------
int sub_C0B87()
{
  char *v0; // edi
  char *v1; // eax
  char *v2; // eax
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  char v14[20]; // [esp+0h] [ebp-14h] BYREF

  strcpy(v14, (char *)sub_CDF5C(12));
  v0 = v14;
  v1 = (char *)sub_CDF5C(282);
  _wcpp_1_unwind_leave(0, 23, v1);
  v2 = (char *)sub_CDF5C(433);
  _wcpp_1_unwind_leave(0, 22, v2);
  v3 = (char *)sub_CDF5C(406);
  _wcpp_1_unwind_leave(0, 21, v3);
  v4 = (char *)sub_CDF5C(212);
  _wcpp_1_unwind_leave(0, 20, v4);
  v5 = (char *)sub_CDF5C(287);
  _wcpp_1_unwind_leave(0, 19, v5);
  v6 = (char *)sub_CDF5C(191);
  _wcpp_1_unwind_leave(0, 18, v6);
  v14[0] = sub_12C574();
  v14[1] = 0;
  v7 = sub_CDF5C(407);
  if ( !stricmp(v14, v7) )
  {
    v0 = (char *)dword_192B18;
    byte_182ACA = 1;
    *(_WORD *)(dword_192B18 + 361 * dword_19F7A8 + 293) += 100;
  }
  v8 = sub_CDF5C(434);
  if ( !stricmp(v14, v8) )
  {
    result = 361 * dword_19F7A8;
    byte_182ACA = 1;
    *(_WORD *)(dword_192B18 + 361 * dword_19F7A8 + 293) += 10000;
  }
  else
  {
    v10 = sub_CDF5C(214);
    result = stricmp(v14, v10);
    if ( result )
    {
      v12 = sub_CDF5C(288);
      if ( !stricmp(v14, v12) )
      {
        result = dword_197F98;
        *(_WORD *)(3753 * word_19999C + dword_197F98 + 54) += 5;
      }
      else
      {
        v13 = sub_CDF5C(192);
        if ( !stricmp(v14, v13) )
        {
          result = dword_197F98;
          *(_DWORD *)(3753 * word_19999C + dword_197F98 + 50) += 100;
        }
        else
        {
          return sub_BB1A6(dword_19F7A8, (int)v0);
        }
      }
    }
    else if ( byte_182AC8 == 2 )
    {
      result = sub_BB082(word_182ACC, v10);
      if ( !(_BYTE)result )
      {
        v11 = sub_CDF5C(416);
        sub_C5B5F(v11);
        word_19994C = 0;
        sub_119281();
        byte_182ACA = 1;
        sub_1191CA((int)sub_BED21, 1);
        return sub_CDB01();
      }
    }
  }
  return result;
}
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 13C896: using guessed type int stricmp(_DWORD, _DWORD);
// 182AC8: using guessed type char byte_182AC8;
// 182ACA: using guessed type char byte_182ACA;
// 182ACC: using guessed type int16_t word_182ACC;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000C0DBC) --------------------------------------------------------
void sub_C0DBC()
{
  sub_CDF5C(222);
  JUMPOUT(0xBBBB2);
}
// C0E18: control flows out of bounds to BBBB2
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;


//----- (000C0E1D) --------------------------------------------------------
void sub_C0E1D( int a1, int a2, int a3)
{
  int v4; // eax
  int v5; // eax
  _BYTE v6[2000]; // [esp+0h] [ebp-7D8h] BYREF
  int v7; // [esp+7D0h] [ebp-8h]
  int v8; // [esp+7D4h] [ebp-4h]

  v8 = a3;
  sub_120CCB(1, (int)&unk_182C2E);
  sub_128C32((int16_t)(a1 + 5), (int16_t)(a2 + 2), (int16_t)(a1 + 176), (int16_t)(a2 + 195), 233);
  sub_C0DBC();
  sub_133C9C(v4, a2);
  v7 = a1;
  v5 = sub_BBA8E(14);
  sub_12A478(a1, a2, v5);
  sub_CA16D(a3, (int)v6);
  sub_1031AA((int)v6, 0);
}
// C0E78: variable 'v4' is possibly undefined


//----- (000C0ED4) --------------------------------------------------------
_DWORD *sub_C0ED4()
{
  _DWORD *result; // eax

  dword_1830D2 = (int)sub_126B42((int)aRefitpupLbx, 0, dword_192ED4);
  dword_1830DA = (int)sub_126B42((int)aRefitpupLbx, 1, dword_192ED4);
  dword_1830D6 = (int)sub_126B42((int)aRefitpupLbx, 2, dword_192ED4);
  result = sub_126B42((int)aRefitpupLbx, 3, dword_192ED4);
  dword_1830DE = (int)result;
  return result;
}
// 1830D2: using guessed type int dword_1830D2;
// 1830D6: using guessed type int dword_1830D6;
// 1830DA: using guessed type int dword_1830DA;
// 1830DE: using guessed type int dword_1830DE;
// 192ED4: using guessed type int dword_192ED4;


//----- (000C0F3E) --------------------------------------------------------
int sub_C0F3E(int16_t *a1, int16_t *a2)
{
  int v3; // esi
  int result; // eax
  int16_t v5; // ax

  v3 = 5 * ((word_19FA28 + 5) / 5);
  result = v3;
  if ( (int16_t)v3 >= 15 )
  {
    if ( (int16_t)v3 - 15 - *a1 != *a2 )
    {
      v5 = v3 - 15 - *a2;
      *a1 = v5;
      *a1 = 5 * (v5 / 5);
      result = word_1830CC;
      byte_182ACA = 1;
      word_1830CE = v3 - 15 - word_1830CC;
    }
  }
  else
  {
    *a2 = -1;
    *a1 = 0;
  }
  return result;
}
// 182ACA: using guessed type char byte_182ACA;
// 1830CC: using guessed type int16_t word_1830CC;
// 1830CE: using guessed type int16_t word_1830CE;
// 19FA28: using guessed type int16_t word_19FA28;


//----- (000C0FBD) --------------------------------------------------------
void sub_C0FBD()
{
  int v0; // edi
  int v1; // esi

  sub_C0F3E(&word_1830CC, &word_1830CE);
  if ( word_19FA28 >= 15 )
  {
    v0 = (int16_t)(335 * word_1830CC / word_19FA28 + 69);
    v1 = (int16_t)(335 * (word_1830CC + 15) / (5 * ((word_19FA28 + 5) / 5)) + 69);
    sub_128C32(468, v0, 478, v1, 229);
    sub_134D2D(468, v0, 478, v0, 230);
    sub_134D2D(468, v0, 468, v1, 230);
    sub_134D2D(478, v0, 478, v1, 228);
    sub_134D2D(468, v1, 478, v1, 228);
    sub_12972D(468, 69, 80);
    sub_12972D(478, 69, 80);
    sub_12972D(468, 404, 80);
    sub_12972D(478, 404, 80);
  }
  JUMPOUT(0xC12A5);
}
// C10E0: control flows out of bounds to C12A5
// 1830CC: using guessed type int16_t word_1830CC;
// 1830CE: using guessed type int16_t word_1830CE;
// 19FA28: using guessed type int16_t word_19FA28;


//----- (000C10EA) --------------------------------------------------------
unsigned int sub_C10EA()
{
  _WORD *v0; // ecx
  int v1; // eax
  _WORD *v2; // ecx
  int v3; // eax
  _WORD *v4; // ecx
  int v5; // eax
  int16_t v6; // ax
  _BYTE *v7; // eax
  unsigned int result; // eax
  _BYTE *v9; // [esp-10h] [ebp-14h]
  _BYTE *v10; // [esp-10h] [ebp-14h]
  _BYTE *v11; // [esp-10h] [ebp-14h]
  _BYTE *v12; // [esp-10h] [ebp-14h]

  sub_C1209();
  v9 = (_BYTE *)sub_CDF5C(137);
  v0 = (_WORD *)dword_1830D6;
  v1 = sub_CDF5C(12);
  word_19F9FE = (uint16_t)sub_1151B0(469, 407, v1, v0, v9, 40);
  v10 = (_BYTE *)sub_CDF5C(11);
  v2 = (_WORD *)dword_1830DA;
  v3 = sub_CDF5C(12);
  word_19FA00 = (uint16_t)sub_1151B0(468, 46, v3, v2, v10, 40);
  v11 = (_BYTE *)sub_CDF5C(12);
  v4 = (_WORD *)dword_1830DE;
  v5 = sub_CDF5C(12);
  word_19FA02 = (uint16_t)sub_1151B0(274, 440, v5, v4, v11, 40);
  v12 = (_BYTE *)sub_CDF5C(12);
  v6 = 5 * ((word_19FA28 + 5) / 5);
  word_19FA04 = sub_115478(468, 69, 0, v6, 0, v6 - 15, 11, 336, (int)&word_1830CE, v12, 0);
  v7 = (_BYTE *)sub_CDF5C(12);
  result = sub_11438B(0, 0, 639, 479, v7, 0);
  word_19F9FC = result;
  return result;
}
// 1830CE: using guessed type int16_t word_1830CE;
// 1830D6: using guessed type int dword_1830D6;
// 1830DA: using guessed type int dword_1830DA;
// 1830DE: using guessed type int dword_1830DE;
// 19F9FC: using guessed type int16_t word_19F9FC;
// 19F9FE: using guessed type int16_t word_19F9FE;
// 19FA00: using guessed type int16_t word_19FA00;
// 19FA02: using guessed type int16_t word_19FA02;
// 19FA04: using guessed type int16_t word_19FA04;
// 19FA28: using guessed type int16_t word_19FA28;


//----- (000C1209) --------------------------------------------------------
unsigned int sub_C1209()
{
  int16_t i; // si
  int v1; // edi
  _BYTE *v2; // eax
  unsigned int result; // eax

  for ( i = 0; i < 15; ++i )
  {
    v1 = 2 * i;
    if ( *(int16_t *)(v1 + dword_19FA14) == -1 )
    {
      result = dword_19FA20;
      *(_WORD *)(v1 + dword_19FA20) = -1000;
    }
    else
    {
      v2 = (_BYTE *)sub_CDF5C(12);
      result = sub_11438B(60 * (i % 5) + 161, 61 * (i / 5) + 49, 60 * (i % 5) + 216, 61 * (i / 5) + 105, v2, 0);
      *(_WORD *)(dword_19FA20 + 2 * i) = result;
    }
  }
  return result;
}
// 19FA14: using guessed type int dword_19FA14;
// 19FA20: using guessed type int dword_19FA20;


//----- (000C12AB) --------------------------------------------------------
int sub_C12AB()
{
  int16_t v0; // dx
  int16_t i; // bx
  int result; // eax

  v0 = 0;
  for ( i = 0; i < 500; ++i )
  {
    result = 129 * i + dword_197F9C;
    if ( *(char *)(result + 99) == word_19999C
      && *(char *)(result + 100) < 3
      && *(_WORD *)(result + 101) == word_199830
      && !*(_BYTE *)(result + 17)
      && v0 < 500 )
    {
      result = v0++;
      *(_WORD *)(dword_19FA14 + 2 * result) = i;
    }
  }
  word_19FA28 = v0;
  while ( v0 < 500 )
  {
    result = v0++;
    *(_WORD *)(dword_19FA14 + 2 * result) = -1;
  }
  return result;
}
// 197F9C: using guessed type int dword_197F9C;
// 199830: using guessed type int16_t word_199830;
// 19999C: using guessed type int16_t word_19999C;
// 19FA14: using guessed type int dword_19FA14;
// 19FA28: using guessed type int16_t word_19FA28;


//----- (000C132A) --------------------------------------------------------
void sub_C132A( int a1, int a2)
{
  int v3; // esi
  int16_t v4; // ax
  char v5; // al
  int16_t v6; // ax
  int v7; // eax
  int v8; // eax

  v3 = a1;
  sub_BAAC5(60 * (a2 % 5) + 188, 61 * (a2 / 5) + 77, a1);
  v4 = sub_79C54(word_199830, word_199832);
  sub_E11BC((char *)(dword_192B18 + 361 * *(int16_t *)(17 * v4 + dword_1930D4)), -(int16_t)(a1 + 100));
  if ( v5 )
  {
    v7 = 129 * v3 + dword_197F9C;
    if ( *(char *)(v7 + 93) == word_19999C )
    {
      if ( *(_BYTE *)(v7 + 92) != 44 )
        goto LABEL_8;
      sub_BB012(1u, 1u);
      v6 = 362;
    }
    else
    {
      sub_BB012(1u, 1u);
      v6 = 216;
    }
  }
  else
  {
    sub_BB012(1u, 1u);
    v6 = 395;
  }
  v8 = sub_CDF5C(v6);
  sub_1031C6(v8, 2);
LABEL_8:
  JUMPOUT(0xC1875);
}
// C1439: control flows out of bounds to C1875
// C13BA: variable 'v5' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 19999C: using guessed type int16_t word_19999C;


//----- (000C143E) --------------------------------------------------------
void sub_C143E( int a1)
{
  int v1; // edx
  int v2; // ecx
  _BYTE v3[10000]; // [esp+0h] [ebp-2710h] BYREF

  v1 = 129 * a1;
  v2 = dword_197F9C;
  sub_BB04E(1u);
  sub_B0CF6(v1 + v2, (int)v3, 1);
  sub_1031AA((int)v3, 0);
}
// 197F9C: using guessed type int dword_197F9C;


//----- (000C1499) --------------------------------------------------------
void sub_C1499()
{
  int16_t i; // bx
  int v1; // eax

  sub_BB04E(1u);
  for ( i = 0; i < 15; ++i )
  {
    v1 = *(int16_t *)(dword_19FA14 + 2 * (i + word_1830CC));
    if ( v1 != -1 )
    {
      if ( byte_182ACA )
        sub_C132A(v1, i);
    }
  }
}
// 182ACA: using guessed type char byte_182ACA;
// 1830CC: using guessed type int16_t word_1830CC;
// 19FA14: using guessed type int dword_19FA14;


//----- (000C14E8) --------------------------------------------------------
void sub_C14E8()
{
  int16_t v0; // ax

  if ( byte_182ACA )
  {
    sub_BAEFE();
    sub_124D41();
    sub_107C2(&dword_19FA1C);
    byte_182ACA = 1;
    sub_12A478(147, 6, dword_1830D2);
    sub_C0FBD();
    sub_C1499();
    sub_124DEC();
    byte_182ACA = 0;
    if ( word_1830E2 == -1 )
      return;
    v0 = *(_WORD *)(dword_19FA14 + 2 * word_1830E2);
  }
  else
  {
    sub_C0FBD();
    if ( word_1830E2 == -1 )
      return;
    v0 = *(_WORD *)(2 * word_1830E2 + dword_19FA14);
  }
  sub_C143E(v0);
}
// 182ACA: using guessed type char byte_182ACA;
// 1830D2: using guessed type int dword_1830D2;
// 1830E2: using guessed type int16_t word_1830E2;
// 19FA14: using guessed type int dword_19FA14;
// 19FA1C: using guessed type int (*dword_19FA1C)(void);


//----- (000C1576) --------------------------------------------------------
int sub_C1576(_WORD *a1, _WORD *a2)
{
  int i; // edi
  int v4; // ebx
  int v5; // ecx
  int16_t v6; // ax
  char v7; // al
  int v8; // eax
  char *v9; // eax
  int16_t v10; // ax
  int v12; // eax
  int16_t j; // di
  int v14; // eax
  int16_t v15; // ax
  int v16; // eax
  int16_t *v17; // [esp-4h] [ebp-208h]
  _BYTE v18[500]; // [esp+0h] [ebp-204h] BYREF
  int v19; // [esp+1F4h] [ebp-10h]
  int v20; // [esp+1F8h] [ebp-Ch]
  _WORD *v21; // [esp+1FCh] [ebp-8h]
  int v22; // [esp+200h] [ebp-4h]

  v21 = a2;
  word_1830E2 = -1;
  for ( i = 0; (int16_t)i < 15; ++i )
  {
    v4 = 2 * ((int16_t)i + word_1830CC);
    LOWORD(v4) = *(_WORD *)(dword_19FA14 + v4);
    if ( *(_WORD *)(dword_19FA20 + 2 * (int16_t)i) == *a1 && (int16_t)v4 != -1 )
    {
      v5 = 129 * (int16_t)v4;
      if ( *(_BYTE *)(v5 + dword_197F9C + 92) == 44 )
      {
        v6 = 575;
      }
      else
      {
        v20 = (int16_t)-(int16_t)(v4 + 100);
        v19 = 17 * sub_79C54(word_199830, word_199832);
        sub_E11BC((char *)(dword_192B18 + 361 * *(int16_t *)(v19 + dword_1930D4)), v20);
        if ( v7 )
        {
          if ( *(char *)(v5 + dword_197F9C + 93) == word_19999C )
          {
            v8 = *(int16_t *)(v5 + dword_197F9C + 116);
            if ( v8 == -1
              || (v17 = sub_97588(v8, 0),
                  v9 = (char *)sub_CDF5C(530),
                  sprintf(v18, v9, v17),
                  sub_77658((int)v18),
                  !v10) )
            {
              word_1830D0 = 1;
            }
            else
            {
              sub_944A3(*(_WORD *)(v5 + dword_197F9C + 116), i);
              word_1830D0 = 1;
              *(_WORD *)(v5 + dword_197F9C + 116) = -1;
            }
            return v4;
          }
          v6 = 573;
        }
        else
        {
          v6 = 574;
        }
      }
      v12 = sub_CDF5C(v6);
      sub_C5B5F(v12);
      byte_182ACA = 1;
    }
  }
  for ( j = 0; j < 15; ++j )
  {
    v14 = j + word_1830CC;
    LOWORD(v14) = *(_WORD *)(dword_19FA14 + 2 * v14);
    v22 = v14;
    if ( *(_WORD *)(dword_19FA20 + 2 * j) == *v21 && (int16_t)v22 != -1 )
    {
      v20 = (int16_t)(61 * (j / 5) + 49);
      sub_C5DE7(60 * (j % 5) + 161, 61 * (j / 5) + 49, 55, 56, 1, 1, 2);
      word_1830E2 = j + word_1830CC;
    }
  }
  if ( word_19F9FE == *a1 && *(int16_t *)(dword_19FA14 + 2 * word_1830CC + 30) != -1 )
  {
    v15 = word_1830CC + 5;
    if ( word_1830CC + 5 > 500 )
      v15 = 500;
    word_1830CC = v15;
    word_1830CE = 5 * ((word_19FA28 + 5) / 5) - 15 - v15;
    byte_182ACA = 1;
    sub_C0F3E(&word_1830CC, &word_1830CE);
  }
  if ( word_19FA00 == *a1 )
  {
    v16 = word_1830CC - 5;
    if ( v16 < 0 )
      LOWORD(v16) = 0;
    word_1830CC = v16;
    word_1830CE = 5 * ((word_19FA28 + 5) / 5) - 15 - v16;
    sub_C0F3E(&word_1830CC, &word_1830CE);
    byte_182ACA = 1;
  }
  if ( word_19FA02 == *a1 )
    word_1830D0 = 1;
  if ( word_19994C )
  {
    byte_182ACA = 1;
    word_19994C = 0;
  }
  return -1;
}
// C1631: variable 'v7' is possibly undefined
// C168B: variable 'v10' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 1830CC: using guessed type int16_t word_1830CC;
// 1830CE: using guessed type int16_t word_1830CE;
// 1830D0: using guessed type int16_t word_1830D0;
// 1830E2: using guessed type int16_t word_1830E2;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 19F9FE: using guessed type int16_t word_19F9FE;
// 19FA00: using guessed type int16_t word_19FA00;
// 19FA02: using guessed type int16_t word_19FA02;
// 19FA14: using guessed type int dword_19FA14;
// 19FA20: using guessed type int dword_19FA20;
// 19FA28: using guessed type int16_t word_19FA28;


//----- (000C187B) --------------------------------------------------------
int sub_C187B(int16_t *a1)
{
  int v1; // edx
  int v2; // eax
  char v4; // [esp+0h] [ebp-7F0h] BYREF
  char v5; // [esp+3E8h] [ebp-408h] BYREF
  _BYTE v6[24]; // [esp+7D0h] [ebp-20h] BYREF
  int v7; // [esp+7E8h] [ebp-8h] BYREF
  char *v8; // [esp+7ECh] [ebp-4h] BYREF

  v7 = 0;
  memset(v6, 0, sizeof(v6));
  dword_19FA18 = (int)v6;
  dword_19FA14 = (int)&v4;
  dword_19FA20 = (int)&v5;
  sub_C12AB();
  word_1830CE = 5 * ((word_19FA28 + 5) / 5) - 15;
  word_1830CC = 0;
  sub_1112EC(dword_192ED4, (word_19FA28 + 5) % 5);
  sub_BAEFE();
  word_1830D0 = 0;
  sub_C0ED4();
  sub_107AF(&dword_19FA1C);
  sub_119281();
  sub_1191CA((int)sub_C14E8, 1);
  sub_CDB2A();
  sub_11C2F0();
  sub_C10EA();
  v1 = 0;
  sub_128AB6(0, 0, 639, 479);
  sub_12B634();
  sub_C14E8();
  sub_124C08();
  byte_182ACA = 1;
  do
  {
    v7 = sub_1171AB(v2, v1, 639, 479);
    v8 = sub_114177();
    sub_C14E8();
    v1 = sub_C1576(&v7, &v8);
    v2 = sub_1077D(v1, v1, 639, a1);
  }
  while ( !word_1830D0 );
  sub_11C2F0();
  sub_1196F7();
  sub_119281();
  sub_107BA((int *)&dword_19FA1C);
  sub_124E36();
  sub_1113CC(dword_192ED4, v1);
  sub_12B65C();
  return v1;
}
// C1955: variable 'v2' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 182ACA: using guessed type char byte_182ACA;
// 1830CC: using guessed type int16_t word_1830CC;
// 1830CE: using guessed type int16_t word_1830CE;
// 1830D0: using guessed type int16_t word_1830D0;
// 192ED4: using guessed type int dword_192ED4;
// 19FA14: using guessed type int dword_19FA14;
// 19FA18: using guessed type int dword_19FA18;
// 19FA1C: using guessed type int (*dword_19FA1C)(void);
// 19FA20: using guessed type int dword_19FA20;
// 19FA28: using guessed type int16_t word_19FA28;


//----- (000C19BA) --------------------------------------------------------
void sub_C19BA()
{
  JUMPOUT(0xC0EE3);
}
// C19CC: control flows out of bounds to C0EE3


//----- (000C19D6) --------------------------------------------------------
void sub_C19D6()
{
  _WORD *v0; // ecx
  int v1; // eax
  int16_t v2; // si
  _BYTE *v3; // edx
  int v4; // eax
  _BYTE *v5; // eax
  int16_t v6; // si
  _BYTE *v7; // eax
  _BYTE *v8; // eax
  _BYTE *v9; // [esp-8h] [ebp-Ch]
  int16_t v10; // [esp+0h] [ebp-4h]

  v10 = -50;
  v9 = (_BYTE *)sub_CDF5C(12);
  v0 = (_WORD *)dword_1830DE;
  v1 = sub_CDF5C(12);
  v2 = 0;
  word_19FA02 = (uint16_t)sub_1151B0(274, 440, v1, v0, v9, 40);
  while ( 1 )
  {
    v3 = sub_B2FFA(v10);
    v4 = sub_CDF5C(12);
    if ( !strcmp(v4, v3) )
    {
      word_19FA06[v2] = -1000;
    }
    else
    {
      v5 = (_BYTE *)sub_CDF5C(12);
      word_19FA06[v2] = sub_11438B(
                          161,
                          ((179 * (v2 + 1) - (__CFSHL__((179 * (v2 + 1)) >> 31, 3) + 8 * ((179 * (v2 + 1)) >> 31))) >> 3)
                        + 49,
                          478,
                          ((179 * (v2 + 2) - (__CFSHL__((179 * (v2 + 2)) >> 31, 3) + 8 * ((179 * (v2 + 2)) >> 31))) >> 3)
                        + 48,
                          v5,
                          41);
    }
    ++v2;
    --v10;
    if ( v2 >= 5 )
    {
      v6 = v2 + 1;
      v7 = (_BYTE *)sub_CDF5C(12);
      word_19FA12 = sub_11438B(
                      161,
                      ((179 * (v6 + 1) - (__CFSHL__((179 * (v6 + 1)) >> 31, 3) + 8 * ((179 * (v6 + 1)) >> 31))) >> 3)
                    + 49,
                      478,
                      ((179 * (v6 + 2) - (__CFSHL__((179 * (v6 + 2)) >> 31, 3) + 8 * ((179 * (v6 + 2)) >> 31))) >> 3)
                    + 48,
                      v7,
                      41);
      v8 = (_BYTE *)sub_CDF5C(12);
      word_19F9FC = sub_11438B(0, 0, 639, 479, v8, 0);
      JUMPOUT(0xC12A4);
    }
  }
}
// C1B2A: control flows out of bounds to C12A4
// 138B90: using guessed type int strcmp(_DWORD, _DWORD);
// 1830DE: using guessed type int dword_1830DE;
// 19F9FC: using guessed type int16_t word_19F9FC;
// 19FA02: using guessed type int16_t word_19FA02;
// 19FA06: using guessed type int16_t word_19FA06[6];
// 19FA12: using guessed type int16_t word_19FA12;


//----- (000C1B2F) --------------------------------------------------------
void sub_C1B2F(int a1)
{
  _BYTE v2[10000]; // [esp+0h] [ebp-2710h] BYREF

  sub_BB04E(1u);
  sub_B0CF6(a1, (int)v2, 0);
  JUMPOUT(0xC1484);
}
// C1B63: control flows out of bounds to C1484


//----- (000C1B68) --------------------------------------------------------
void sub_C1B68()
{
  int16_t v0; // di
  int16_t v1; // cx
  char v2; // al
  _BYTE *v3; // edx
  int v4; // eax
  _BYTE *v5; // eax
  int16_t v6; // si
  char v7; // al
  int16_t v8; // cx
  int v9; // eax
  char *v10; // eax
  int64_t v11; // rax
  int v12; // [esp-4h] [ebp-1FCh]
  _BYTE v13[500]; // [esp+0h] [ebp-1F8h] BYREF
  int v14; // [esp+1F4h] [ebp-4h]

  v0 = -50;
  v1 = 0;
  while ( 1 )
  {
    v2 = 0;
    if ( word_19FA06[v1] == word_1830E6 )
      v2 = *(_BYTE *)(dword_197F9C + 129 * word_19FA26 + 16) == *(_BYTE *)(3753 * word_19999C
                                                                         + dword_197F98
                                                                         + 99 * v1
                                                                         + 822);
    if ( *(_BYTE *)(dword_197F9C + 129 * word_19FA26 + 16) == *(_BYTE *)(99 * v1
                                                                       + dword_197F98
                                                                       + 3753 * word_19999C
                                                                       + 822) )
      ++v2;
    sub_BAFC9(4u, v2);
    v3 = sub_B2FFA(v0);
    v4 = sub_CDF5C(12);
    if ( strcmp(v4, v3) )
    {
      v5 = sub_B2FFA(v0);
      v14 = v1;
      v6 = ((179 * (v1 + 1) - (__CFSHL__((179 * (v1 + 1)) >> 31, 3) + 8 * ((179 * (v1 + 1)) >> 31))) >> 3) + 49;
      sub_1212B3(183, v6, (int)v5);
      sub_1210B7(
        457,
        v6,
        (int)*(&off_18003A + 9 * *(uint8_t *)(99 * v1 + dword_197F98 + 3753 * word_19999C + 822)));
      sub_1210FD(320, v6, (int)asc_179DFD);
    }
    ++v1;
    --v0;
    if ( v1 >= 5 )
    {
      v7 = 1;
      v8 = v1 + 1;
      if ( word_19FA12 == word_1830E6 )
        v7 = 2;
      sub_BAFC9(4u, v7);
      v9 = sub_CDF5C(800);
      sub_1210FD(
        320,
        ((179 * (v8 + 1) - (__CFSHL__((179 * (v8 + 1)) >> 31, 3) + 8 * ((179 * (v8 + 1)) >> 31))) >> 3) + 49,
        v9);
      v12 = dword_197F9C + 129 * word_19FA26;
      v10 = (char *)sub_CDF5C(801);
      v11 = sprintf(v13, v10, v12);
      sub_BAFC9(4u, SBYTE4(v11));
      sub_1210FD(320, 20, (int)v13);
      JUMPOUT(0xC12A4);
    }
  }
}
// C1D66: control flows out of bounds to C12A4
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 138B90: using guessed type int strcmp(_DWORD, _DWORD);
// 18003A: using guessed type _UNKNOWN *off_18003A;
// 1830E6: using guessed type int16_t word_1830E6;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 19FA06: using guessed type int16_t word_19FA06[6];
// 19FA12: using guessed type int16_t word_19FA12;
// 19FA26: using guessed type int16_t word_19FA26;


//----- (000C1D6B) --------------------------------------------------------
void sub_C1D6B()
{
  int v0; // ecx
  int v1; // eax
  _BYTE v2[10000]; // [esp+0h] [ebp-2710h] BYREF

  if ( byte_182ACA )
  {
    sub_BAEFE();
    sub_124D41();
    sub_107C2(&dword_19FA1C);
    byte_182ACA = 1;
    sub_12A478(147, 6, dword_1830D2);
    sub_C1B68();
    sub_124DEC();
    byte_182ACA = 0;
  }
  else
  {
    sub_C1B68();
  }
  if ( word_1830E4 != -1 )
  {
    v0 = 3753 * word_19999C + dword_197F98 + 806 + 99 * word_1830E4;
    sub_BB04E(1u);
    sub_B0CF6(v0, (int)v2, 0);
    sub_1031AA((int)v2, 0);
  }
  if ( word_19FA12 == word_1830E6 )
  {
    sub_BAFC9(4u, 1);
    v1 = sub_CDF5C(802);
    sub_10323B(v1, 2);
  }
}
// 182ACA: using guessed type char byte_182ACA;
// 1830D2: using guessed type int dword_1830D2;
// 1830E4: using guessed type int16_t word_1830E4;
// 1830E6: using guessed type int16_t word_1830E6;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19FA12: using guessed type int16_t word_19FA12;
// 19FA1C: using guessed type int (*dword_19FA1C)(void);


//----- (000C1E74) --------------------------------------------------------
void sub_C1E74(int16_t *a1, _WORD *a2)
{
  int16_t i; // si
  int v5; // eax
  char *v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // [esp-8h] [ebp-208h]
  int v15; // [esp-4h] [ebp-204h]
  _BYTE v16[500]; // [esp+0h] [ebp-200h] BYREF
  int v17; // [esp+1F4h] [ebp-Ch]
  int v18; // [esp+1F8h] [ebp-8h]
  int v19; // [esp+1FCh] [ebp-4h]

  word_1830E4 = -1;
  word_1830E6 = -1000;
  for ( i = 0; i < 5; ++i )
  {
    if ( word_19FA06[i] == *a2 )
    {
      word_1830E6 = word_19FA06[i];
      word_1830E4 = i;
    }
    if ( word_19FA06[i] == *a1 )
    {
      v18 = 99 * i;
      v19 = 3753 * word_19999C + dword_197F98;
      if ( *(_BYTE *)(dword_197F9C + 129 * word_19FA26 + 16) == *(_BYTE *)(v18 + v19 + 822) )
      {
        sub_12779E((_BYTE *)(v19 + 1301), (_BYTE *)(v18 + v19 + 806), 0x63u);
        word_199838 = 5;
        word_1830D0 = 1;
        goto LABEL_24;
      }
      v5 = sub_CDF5C(803);
      sub_C5B5F(v5);
      word_1830D0 = 0;
    }
    v17 = word_19FA06[i];
    if ( -*a1 == v17 )
    {
      v15 = 99 * i + dword_197F98 + 3753 * word_19999C + 806;
      v14 = dword_197F9C + 129 * word_19FA26;
      v6 = (char *)sub_CDF5C(804);
      sprintf(v16, v6, v14, v15);
      v7 = sub_CDF5C(805);
      sub_A5EB2(v7, (int)v16);
    }
  }
  if ( word_19FA12 == *a2 )
    word_1830E6 = word_19FA12;
  if ( word_19FA12 != *a1 )
  {
    if ( word_19FA12 == -*a1 )
    {
      v8 = sub_CDF5C(807);
      v9 = sub_CDF5C(806);
      sub_A5EB2(v9, v8);
    }
    if ( word_19FA02 == *a1 )
      word_1830D0 = 1;
    if ( word_19F9FC == -*a1 )
    {
      v10 = sub_CDF5C(809);
      v11 = sub_CDF5C(808);
      sub_A5EB2(v11, v10);
    }
    if ( word_19FA02 == -*a1 )
    {
      v12 = sub_CDF5C(811);
      v13 = sub_CDF5C(810);
      sub_A5EB2(v13, v12);
    }
    JUMPOUT(0xC1856);
  }
  word_1830D0 = 1;
LABEL_24:
  JUMPOUT(0xC1875);
}
// C1F41: control flows out of bounds to C1875
// C20AA: control flows out of bounds to C1856
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1830D0: using guessed type int16_t word_1830D0;
// 1830E4: using guessed type int16_t word_1830E4;
// 1830E6: using guessed type int16_t word_1830E6;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199838: using guessed type int16_t word_199838;
// 19999C: using guessed type int16_t word_19999C;
// 19F9FC: using guessed type int16_t word_19F9FC;
// 19FA02: using guessed type int16_t word_19FA02;
// 19FA06: using guessed type int16_t word_19FA06[6];
// 19FA12: using guessed type int16_t word_19FA12;
// 19FA26: using guessed type int16_t word_19FA26;


//----- (000C20AF) --------------------------------------------------------
int sub_C20AF( int a1, int16_t *a2)
{
  int16_t v3; // bx
  int16_t i; // ax
  int v6; // edx
  int v7; // eax
  int v8; // eax
  char v9; // [esp+0h] [ebp-7F0h] BYREF
  char v10; // [esp+3E8h] [ebp-408h] BYREF
  _BYTE v11[24]; // [esp+7D0h] [ebp-20h] BYREF
  int v12; // [esp+7E8h] [ebp-8h] BYREF
  char *v13; // [esp+7ECh] [ebp-4h] BYREF

  v12 = 0;
  memset(v11, 0, sizeof(v11));
  dword_19FA18 = (int)v11;
  word_19FA26 = a1;
  dword_19FA14 = (int)&v9;
  v3 = 0;
  dword_19FA20 = (int)&v10;
  for ( i = 0; i < 5; ++i )
  {
    if ( *(_BYTE *)(dword_197F9C + 129 * word_19FA26 + 16) == *(_BYTE *)(99 * i + 3753 * word_19999C + dword_197F98 + 822) )
      ++v3;
  }
  if ( !v3 )
    return -2;
  sub_1112EC(dword_192ED4, 1);
  sub_BAEFE();
  word_1830D0 = 0;
  sub_C19BA();
  sub_107AF(&dword_19FA1C);
  sub_119281();
  sub_1191CA((int)sub_C1D6B, 1);
  sub_11C2F0();
  sub_C19D6();
  v6 = 0;
  sub_128AB6(0, 0, 639, 479);
  sub_12B634();
  sub_C1D6B();
  sub_124C08();
  byte_182ACA = 1;
  do
  {
    v12 = sub_1171AB(v7, v6, 639, 479);
    v13 = sub_114177();
    sub_C1D6B();
    sub_C1E74((int16_t *)&v12, &v13);
    v6 = v8;
    v7 = sub_1077D(v8, v8, 639, a2);
  }
  while ( !word_1830D0 );
  sub_11C2F0();
  sub_1196F7();
  sub_119281();
  sub_107BA((int *)&dword_19FA1C);
  sub_124E36();
  sub_1113CC(dword_192ED4, v6);
  sub_12B65C();
  return v6;
}
// C21B9: variable 'v7' is possibly undefined
// C21D9: variable 'v8' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 182ACA: using guessed type char byte_182ACA;
// 1830D0: using guessed type int16_t word_1830D0;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 19FA14: using guessed type int dword_19FA14;
// 19FA18: using guessed type int dword_19FA18;
// 19FA1C: using guessed type int (*dword_19FA1C)(void);
// 19FA20: using guessed type int dword_19FA20;
// 19FA26: using guessed type int16_t word_19FA26;


//----- (000C2259) --------------------------------------------------------
void sub_C2259()
{
  if ( !byte_183184 )
  {
    byte_183184 = 1;
    dword_19FA2C[0] = sub_CDF5C(260);
    dword_19FA30 = sub_CDF5C(221);
    dword_19FA34 = sub_CDF5C(240);
    dword_19FA38 = sub_CDF5C(551);
    dword_19FA3C = sub_CDF5C(204);
    dword_19FA40 = sub_CDF5C(369);
    dword_19FA44 = sub_CDF5C(270);
    dword_19FA48 = sub_CDF5C(279);
    dword_19FA4C = sub_CDF5C(167);
    dword_19FA50 = sub_CDF5C(295);
    dword_19FA54 = sub_CDF5C(167);
    dword_19FA58 = sub_CDF5C(258);
    dword_19FA5C = sub_CDF5C(259);
    dword_19FA60 = sub_CDF5C(381);
    dword_19FA64 = sub_CDF5C(414);
    dword_19FA68 = sub_CDF5C(413);
    dword_19FA6C = sub_CDF5C(415);
    dword_19FA70 = sub_CDF5C(206);
    dword_19FA74 = sub_CDF5C(466);
    dword_19FA78 = sub_CDF5C(173);
    dword_19FA7C = sub_CDF5C(246);
    dword_19FA80 = sub_CDF5C(272);
    dword_19FA84 = sub_CDF5C(281);
    dword_19FA88 = sub_CDF5C(324);
    dword_19FA8C = sub_CDF5C(398);
    dword_19FA90 = sub_CDF5C(182);
    dword_19FA94 = sub_CDF5C(198);
    dword_19FA98 = sub_CDF5C(302);
    dword_19FA9C = sub_CDF5C(558);
    dword_19FAA0 = sub_CDF5C(438);
    dword_19FAA4 = sub_CDF5C(417);
    dword_19FAA8 = sub_CDF5C(309);
    dword_19FAAC = sub_CDF5C(403);
    dword_19FAB0 = sub_CDF5C(255);
    dword_19FAB4 = sub_CDF5C(500);
    dword_19FAB8 = sub_CDF5C(390);
  }
}
// 183184: using guessed type char byte_183184;
// 19FA2C: using guessed type int dword_19FA2C;
// 19FA30: using guessed type int dword_19FA30;
// 19FA34: using guessed type int dword_19FA34;
// 19FA38: using guessed type int dword_19FA38;
// 19FA3C: using guessed type int dword_19FA3C;
// 19FA40: using guessed type int dword_19FA40;
// 19FA44: using guessed type int dword_19FA44;
// 19FA48: using guessed type int dword_19FA48;
// 19FA4C: using guessed type int dword_19FA4C;
// 19FA50: using guessed type int dword_19FA50;
// 19FA54: using guessed type int dword_19FA54;
// 19FA58: using guessed type int dword_19FA58;
// 19FA5C: using guessed type int dword_19FA5C;
// 19FA60: using guessed type int dword_19FA60;
// 19FA64: using guessed type int dword_19FA64;
// 19FA68: using guessed type int dword_19FA68;
// 19FA6C: using guessed type int dword_19FA6C;
// 19FA70: using guessed type int dword_19FA70;
// 19FA74: using guessed type int dword_19FA74;
// 19FA78: using guessed type int dword_19FA78;
// 19FA7C: using guessed type int dword_19FA7C;
// 19FA80: using guessed type int dword_19FA80;
// 19FA84: using guessed type int dword_19FA84;
// 19FA88: using guessed type int dword_19FA88;
// 19FA8C: using guessed type int dword_19FA8C;
// 19FA90: using guessed type int dword_19FA90;
// 19FA94: using guessed type int dword_19FA94;
// 19FA98: using guessed type int dword_19FA98;
// 19FA9C: using guessed type int dword_19FA9C;
// 19FAA0: using guessed type int dword_19FAA0;
// 19FAA4: using guessed type int dword_19FAA4;
// 19FAA8: using guessed type int dword_19FAA8;
// 19FAAC: using guessed type int dword_19FAAC;
// 19FAB0: using guessed type int dword_19FAB0;
// 19FAB4: using guessed type int dword_19FAB4;
// 19FAB8: using guessed type int dword_19FAB8;


//----- (000C24B1) --------------------------------------------------------
int sub_C24B1()
{
  int result; // eax
  int v1; // edx

  result = 0;
  do
  {
    v1 = (int16_t)result++;
    word_1A0534[v1] = -1;
  }
  while ( (int16_t)result < 10 );
  return result;
}
// 1A0534: using guessed type int16_t word_1A0534[9];


//----- (000C24CA) --------------------------------------------------------
int sub_C24CA()
{
  int16_t i; // cx
  int v1; // esi
  _DWORD *v2; // eax

  sub_B0A24();
  for ( i = 0; i < 21; ++i )
  {
    v1 = i;
    v2 = sub_126B42((int)aColsumLbx, i, dword_192ED4);
    dword_183106[v1] = (int)v2;
  }
  return sub_BB91D();
}
// 183106: using guessed type int dword_183106[];
// 192ED4: using guessed type int dword_192ED4;


//----- (000C2539) --------------------------------------------------------
void sub_C2539()
{
  int16_t v0; // si
  int v1; // esi
  int v2; // [esp+0h] [ebp-4h]

  v0 = sub_C5560(word_19999C);
  sub_C2685(10, &word_18315A, &word_18315C);
  if ( v0 >= 10 )
  {
    v2 = 271 * word_18315A / v0 + 40;
    v1 = 271 * (word_18315A + 10) / v0 + 40;
    sub_128AB6(0, 0, 639, 479);
    sub_12B634();
    sub_128C32(621, (int16_t)v2, 626, (int16_t)v1, 229);
    sub_134D2D(621, (int16_t)v2, 626, (int16_t)v2, 230);
    sub_134D2D(621, (int16_t)v2, 621, (int16_t)v1, 230);
    sub_134D2D(626, (int16_t)v2, 626, (int16_t)v1, 228);
    sub_134D2D(621, (int16_t)v1, 626, (int16_t)v1, 228);
    sub_12972D(621, 40, 80);
    sub_12972D(626, 40, 80);
    sub_12972D(621, 311, 80);
    sub_12972D(626, 311, 80);
  }
  sub_12B65C();
}
// 18315A: using guessed type int16_t word_18315A;
// 18315C: using guessed type int16_t word_18315C;
// 19999C: using guessed type int16_t word_19999C;


//----- (000C2685) --------------------------------------------------------
int16_t sub_C2685( int a1, int16_t *a2, int16_t *a3)
{
  int v4; // eax
  int16_t v5; // cx
  int16_t v6; // cx

  LOWORD(v4) = sub_C5560(word_19999C);
  if ( (int16_t)v4 >= a1 )
  {
    v4 = sub_C5560(word_19999C) - a1 - *a2;
    if ( *a3 != v4 )
    {
      byte_182ACA = 1;
      v5 = sub_C5560(word_19999C) - a1;
      LOWORD(v4) = *a3;
      v6 = v5 - *a3;
      word_182ABC = -1;
      *a2 = v6;
    }
  }
  else
  {
    *a3 = -1;
    *a2 = 0;
  }
  return v4;
}
// 182ABC: using guessed type int16_t word_182ABC;
// 182ACA: using guessed type char byte_182ACA;
// 19999C: using guessed type int16_t word_19999C;


//----- (000C26F4) --------------------------------------------------------
int sub_C26F4()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  char v7[200]; // [esp+0h] [ebp+7Eh] BYREF

  sub_BB04E(2u);
  v0 = sub_CDF5C(118);
  sub_C5AC8(v7, 0, v0, (char)&unk_179E03);
  sub_C603D(*(_WORD *)(3753 * word_19999C + dword_197F98 + 178));
  v1 = sub_CDF5C(106);
  sub_C5AC8(v7, 1, v1, (char)&unk_179E03);
  v2 = sub_CDF5C(114);
  sub_C5AC8(v7, 2, v2, (char)&unk_179E03);
  v3 = sub_CDF5C(103);
  sub_C5AC8(v7, 3, v3, (char)&unk_179E03);
  v4 = sub_CDF5C(102);
  sub_C5AC8(v7, 4, v4, (char)&unk_179E03);
  v5 = sub_CDF5C(117);
  sub_C5AC8(v7, 5, v5, (char)&unk_179E03);
  sub_103BC4(0x208u, 0x162u, 104, (int)v7, 3);
  return sub_BAEFE();
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (000C28A8) --------------------------------------------------------
void sub_C28A8( int a1)
{
  int16_t v2; // si
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int16_t v5; // ax
  int16_t v6; // ax
  int v7; // edx
  int16_t v8; // [esp-18h] [ebp-28h]
  char *v9; // [esp-10h] [ebp-20h]
  _WORD *v10; // [esp-Ch] [ebp-1Ch]
  int16_t *v11; // [esp-8h] [ebp-18h]
  int16_t *v12; // [esp-4h] [ebp-14h]
  int16_t v13; // [esp+8h] [ebp-8h]
  int16_t v14; // [esp+Ch] [ebp-4h]

  v14 = word_1A0534[a1];
  v2 = 0;
  v13 = 31 * a1 + 38;
  while ( 1 )
  {
    v3 = 6 * a1;
    v4 = 2 * v2;
    v12 = &word_1A04F8[v3 / 2 + v4 / 2];
    v11 = (int16_t *)((char *)&unk_1A04A8 + v3 + v4);
    v10 = (_WORD *)((char *)&unk_1A055C + v3 + v4);
    v9 = (char *)&unk_19FABC + 252 * a1 + 84 * v2;
    if ( v2 == -1 )
    {
      v5 = 101;
    }
    else if ( v2 )
    {
      if ( v2 == 1 )
        v5 = 378;
      else
        v5 = 512;
    }
    else
    {
      v5 = 236;
    }
    v8 = v5 - 10;
    if ( v2 )
    {
      if ( v2 == 1 )
      {
        v6 = 236;
      }
      else if ( v2 == 2 )
      {
        v6 = 378;
      }
      else
      {
        v6 = 512;
      }
    }
    else
    {
      v6 = 101;
    }
    v7 = v2++;
    sub_B4EF6(v14, v7, 0, v6, v13, v8, 0, (int)v9, v10, v11, v12);
    if ( v2 >= 3 )
      JUMPOUT(0xC267E);
  }
}
// C298F: control flows out of bounds to C267E
// 1A04F8: using guessed type int16_t word_1A04F8[30];
// 1A0534: using guessed type int16_t word_1A0534[9];


//----- (000C2994) --------------------------------------------------------
int sub_C2994( int a1, int a2)
{
  int v2; // ebx
  unsigned int v3; // esi
  unsigned int v4; // eax
  int16_t v5; // ax
  int16_t v6; // ax
  int result; // eax
  int16_t v8; // [esp-18h] [ebp-24h]
  _WORD *v9; // [esp-Ch] [ebp-18h]
  int16_t *v10; // [esp-8h] [ebp-14h]
  int16_t *v11; // [esp-4h] [ebp-10h]
  int16_t v12; // [esp+0h] [ebp-Ch]
  int16_t v13; // [esp+8h] [ebp-4h]

  v2 = a1;
  v3 = 6 * a1;
  v13 = word_1A0534[a1];
  v4 = 2 * a2;
  v11 = &word_1A04F8[v3 / 2 + v4 / 2];
  v10 = (int16_t *)((char *)&unk_1A04A8 + v3 + v4);
  v9 = (_WORD *)((char *)&unk_1A055C + v3 + v4);
  if ( a2 == -1 )
  {
    v5 = 101;
  }
  else if ( a2 )
  {
    if ( a2 == 1 )
      v5 = 378;
    else
      v5 = 512;
  }
  else
  {
    v5 = 236;
  }
  v8 = v5 - 10;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v6 = 236;
    }
    else if ( a2 == 2 )
    {
      v6 = 378;
    }
    else
    {
      v6 = 512;
    }
  }
  else
  {
    v6 = 101;
  }
  result = sub_B4EF6(v13, a2, 4, v6, 31 * v12 + 38, v8, 0, (int)&unk_19FABC + 252 * v2 + 84 * a2, v9, v10, v11);
  word_182AB7 = v13;
  word_199960 = *(uint8_t *)(17 * *(int16_t *)(361 * v13 + dword_192B18 + 2) + dword_1930D4 + 2);
  return result;
}
// C2A17: variable 'v12' is possibly undefined
// 182AB7: using guessed type int16_t word_182AB7;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199960: using guessed type int16_t word_199960;
// 1A04F8: using guessed type int16_t word_1A04F8[30];
// 1A0534: using guessed type int16_t word_1A0534[9];


//----- (000C2A9A) --------------------------------------------------------
void sub_C2A9A( int a1, int a2)
{
  int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int16_t v6; // ax
  int16_t v7; // ax
  int16_t v8; // [esp-18h] [ebp-24h]
  _WORD *v9; // [esp-Ch] [ebp-18h]
  int16_t *v10; // [esp-8h] [ebp-14h]
  int16_t *v11; // [esp-4h] [ebp-10h]
  int16_t v12; // [esp+8h] [ebp-4h]

  v3 = a1;
  v4 = 6 * a1;
  v12 = word_1A0534[a1];
  v5 = 2 * a2;
  v11 = &word_1A04F8[v4 / 2 + v5 / 2];
  v10 = (int16_t *)((char *)&unk_1A04A8 + v4 + v5);
  v9 = (_WORD *)((char *)&unk_1A055C + v4 + v5);
  if ( a2 == -1 )
  {
    v6 = 101;
  }
  else if ( a2 )
  {
    if ( a2 == 1 )
      v6 = 378;
    else
      v6 = 512;
  }
  else
  {
    v6 = 236;
  }
  v8 = v6 - 10;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v7 = 236;
    }
    else if ( a2 == 2 )
    {
      v7 = 378;
    }
    else
    {
      v7 = 512;
    }
  }
  else
  {
    v7 = 101;
  }
  sub_B4EF6(v12, a2, 3, v7, 31 * a1 + 38, v8, 0, (int)&unk_19FABC + 252 * v3 + 84 * a2, v9, v10, v11);
  JUMPOUT(0xC2A94);
}
// C2B6D: control flows out of bounds to C2A94
// 1A04F8: using guessed type int16_t word_1A04F8[30];
// 1A0534: using guessed type int16_t word_1A0534[9];


//----- (000C2B72) --------------------------------------------------------
void sub_C2B72( int a1)
{
  int16_t v2; // si
  unsigned int v3; // ebx
  unsigned int v4; // eax
  int16_t v5; // ax
  int16_t v6; // ax
  int16_t v7; // [esp-18h] [ebp-28h]
  _WORD *v8; // [esp-Ch] [ebp-1Ch]
  int16_t *v9; // [esp-8h] [ebp-18h]
  int16_t *v10; // [esp-4h] [ebp-14h]
  int16_t v11; // [esp+8h] [ebp-8h]
  int16_t v12; // [esp+Ch] [ebp-4h]

  v11 = word_1A0534[a1];
  v2 = 0;
  v12 = 31 * a1 + 34;
  while ( 1 )
  {
    if ( v11 == -1 )
    {
      word_1A04F8[3 * a1 + v2] = -1000;
    }
    else
    {
      v3 = 6 * a1;
      v4 = 2 * v2;
      v10 = &word_1A04F8[v3 / 2 + v4 / 2];
      v9 = (int16_t *)((char *)&unk_1A04A8 + v3 + v4);
      v8 = (_WORD *)((char *)&unk_1A055C + v3 + v4);
      if ( v2 == -1 )
      {
        v5 = 101;
      }
      else if ( v2 )
      {
        if ( v2 == 1 )
          v5 = 378;
        else
          v5 = 512;
      }
      else
      {
        v5 = 236;
      }
      v7 = v5 - 10;
      if ( v2 )
      {
        if ( v2 == 1 )
        {
          v6 = 236;
        }
        else if ( v2 == 2 )
        {
          v6 = 378;
        }
        else
        {
          v6 = 512;
        }
      }
      else
      {
        v6 = 101;
      }
      sub_B4EF6(v11, v2, 1, v6, v12, v7, 0, (int)&unk_19FABC + 252 * a1 + 84 * v2, v8, v9, v10);
    }
    if ( ++v2 >= 3 )
      JUMPOUT(0xC267E);
  }
}
// C2C7F: control flows out of bounds to C267E
// 1A04F8: using guessed type int16_t word_1A04F8[30];
// 1A0534: using guessed type int16_t word_1A0534[9];


//----- (000C2E4D) --------------------------------------------------------
void sub_C2E4D()
{
  _BYTE *v0; // eax
  int16_t v1; // di
  int v2; // esi
  _BYTE *v3; // eax
  int16_t v4; // ax
  int16_t v5; // cx
  _BYTE *v6; // eax
  _WORD *v7; // ecx
  int v8; // eax
  int16_t v9; // dx
  int16_t v10; // ax
  _BYTE *v11; // eax
  int16_t v12; // ax
  int v13; // eax
  _WORD *v14; // ecx
  int v15; // eax
  _WORD *v16; // ecx
  int v17; // eax
  _WORD *v18; // ecx
  int v19; // eax
  _BYTE *v20; // eax
  _WORD *v21; // ecx
  int v22; // eax
  _WORD *v23; // ecx
  int v24; // eax
  _WORD *v25; // ecx
  int v26; // eax
  _WORD *v27; // ecx
  int v28; // eax
  _WORD *v29; // ecx
  int v30; // eax
  _WORD *v31; // ecx
  int v32; // eax
  int v33; // edx
  _WORD *v34; // ecx
  int v35; // eax
  _BYTE *v36; // eax
  _BYTE *v37; // [esp-8h] [ebp-48h]
  _BYTE *v38; // [esp-8h] [ebp-48h]
  _BYTE *v39; // [esp-8h] [ebp-48h]
  _BYTE *v40; // [esp-8h] [ebp-48h]
  _BYTE *v41; // [esp-8h] [ebp-48h]
  _BYTE *v42; // [esp-8h] [ebp-48h]
  _BYTE *v43; // [esp-8h] [ebp-48h]
  _BYTE *v44; // [esp-8h] [ebp-48h]
  _DWORD v45[2]; // [esp+0h] [ebp-40h]
  int64_t v46; // [esp+8h] [ebp-38h]
  int v47; // [esp+10h] [ebp-30h]
  _DWORD v48[2]; // [esp+14h] [ebp-2Ch]
  int64_t v49; // [esp+1Ch] [ebp-24h]
  int v50; // [esp+24h] [ebp-1Ch]
  int v51; // [esp+28h] [ebp-18h]
  int v52; // [esp+2Ch] [ebp-14h]
  int v53; // [esp+30h] [ebp-10h]
  int v54; // [esp+34h] [ebp-Ch]
  int v55; // [esp+38h] [ebp-8h]
  int v56; // [esp+3Ch] [ebp-4h]

  LOWORD(v13) = sub_C5560(word_19999C);
  v45[0] = 39256663;
  v45[1] = 39256663;
  v46 = *(_QWORD *)((char *)&dword_C2220[1] + 3);
  v47 = *(int *)((char *)&dword_C2220[3] + 3);
  v55 = v13;
  v48[0] = 4259875;
  v48[1] = 8388704;
  v49 = *(_QWORD *)((char *)&dword_C2234[1] + 3);
  v50 = *(int *)((char *)&dword_C2234[3] + 3);
  v38 = (_BYTE *)sub_CDF5C(137);
  v14 = (_WORD *)dword_18310E;
  v15 = sub_CDF5C(12);
  word_1830EA = (uint16_t)sub_1151B0(619, 15, v15, v14, v38, 40);
  v39 = (_BYTE *)sub_CDF5C(11);
  v16 = (_WORD *)dword_183112;
  v17 = sub_CDF5C(12);
  word_1830EC = (uint16_t)sub_1151B0(619, 316, v17, v16, v39, 40);
  v40 = (_BYTE *)sub_CDF5C(12);
  v18 = (_WORD *)dword_18310A;
  v19 = sub_CDF5C(12);
  word_1830EE = (uint16_t)sub_1151B0(531, 445, v19, v18, v40, 40);
  v20 = (_BYTE *)sub_CDF5C(135);
  word_1830F0 = sub_114C72(v20, 445);
  v41 = (_BYTE *)sub_CDF5C(384);
  v21 = (_WORD *)dword_183116;
  v22 = sub_CDF5C(12);
  word_1830F2 = sub_115383(89, 446, v22, v21, (int)&word_183104, 0, v41, 41);
  v23 = (_WORD *)dword_18311A;
  v24 = sub_CDF5C(12);
  word_1830F4 = sub_115383(140, 446, v24, v23, (int)&word_183104, 1, byte_179E06, 41);
  v25 = (_WORD *)dword_18311E;
  v26 = sub_CDF5C(12);
  word_1830F6 = sub_115383(219, 446, v26, v25, (int)&word_183104, 2, aFs, 41);
  v42 = (_BYTE *)sub_CDF5C(327);
  v27 = (_WORD *)dword_183122;
  v28 = sub_CDF5C(12);
  word_1830F8 = sub_115383(262, 446, v28, v27, (int)&word_183104, 3, v42, 41);
  v29 = (_WORD *)dword_183126;
  v30 = sub_CDF5C(12);
  word_1830FA = sub_115383(326, 446, v30, v29, (int)&word_183104, 4, &aFs[1], 41);
  v43 = (_BYTE *)sub_CDF5C(436);
  v31 = (_WORD *)dword_18312A;
  v32 = sub_CDF5C(12);
  word_1830FC = sub_115383(393, 446, v32, v31, (int)&word_183104, 5, v43, 41);
  v44 = (_BYTE *)sub_CDF5C(193);
  v33 = 446;
  v34 = (_WORD *)dword_18312E;
  v35 = sub_CDF5C(12);
  word_1830FE = sub_115383(480, 446, v35, v34, (int)&word_183104, 6, v44, 41);
  if ( (int16_t)v55 < 10 )
  {
    word_183100 = -1000;
  }
  else
  {
    v36 = (_BYTE *)sub_CDF5C(12);
    v33 = 40;
    word_183100 = sub_115478(621, 40, 0, v55, 0, v55 - 10, 5, 271, (int)&word_18315C, v36, 0);
  }
  v56 = 35;
  v54 = 65;
  v0 = (_BYTE *)sub_CDF5C(596);
  v1 = 0;
  word_183102 = sub_114C72(v0, v33);
  while ( 1 )
  {
    v52 = v1;
    v2 = v1;
    if ( word_1A0534[v2] == -1 )
    {
      word_1A0598[v1] = -1000;
      word_1A0548[v1] = -1000;
      word_1A04E4[v1] = -1000;
    }
    else
    {
      v3 = (_BYTE *)sub_CDF5C(12);
      v51 = (int16_t)v54;
      v53 = (int16_t)v56;
      v4 = sub_11438B(12, v56, 101, v54, v3, 0);
      v5 = v51;
      word_1A0598[v1] = v4;
      v6 = (_BYTE *)sub_CDF5C(12);
      word_1A0548[v1] = sub_11438B(512, v53, 597, v5, v6, 0);
      if ( sub_BEFA8(word_1A0534[v1]) || *(_WORD *)(dword_192B18 + 361 * word_1A0534[v1] + 300) )
      {
        v37 = (_BYTE *)sub_CDF5C(12);
        v2 = v1;
        v7 = (_WORD *)dword_183132[v1];
        v8 = sub_CDF5C(12);
        v9 = *(_WORD *)((char *)v48 + v2 * 2);
        v53 = *(int16_t *)((char *)v45 + v2 * 2);
        v10 = sub_1152DF(v53, v9, v8, v7, (int)&word_1A0494[v2], v37, 41);
      }
      else
      {
        v11 = (_BYTE *)sub_CDF5C(12);
        v10 = sub_11438B(
                *((_WORD *)v45 + v1),
                *((_WORD *)v48 + v1),
                *(_WORD *)dword_183132[v52] + *((_WORD *)v45 + v1),
                *(_WORD *)(dword_183132[v52] + 2) + *((_WORD *)v48 + v1),
                v11,
                0);
      }
      word_1A04E4[v2] = v10;
    }
    v56 += 31;
    v54 += 31;
    v12 = v1++;
    sub_C2B72(v12);
    if ( v1 >= 10 )
    {
      word_1830E8 = sub_11438B(0, 0, 639, 479, &aFs[2], 0);
      JUMPOUT(0xC267E);
    }
  }
}
// C2E39: control flows out of bounds to C267E
// C2E7E: variable 'v13' is possibly undefined
// C2220: using guessed type int[4];
// C2234: using guessed type int dword_C2234[7];
// 179E06: using guessed type _BYTE byte_179E06[2];
// 179E08: using guessed type wchar_t aFs[3];
// 1830E8: using guessed type int16_t word_1830E8;
// 1830EA: using guessed type int16_t word_1830EA;
// 1830EC: using guessed type int16_t word_1830EC;
// 1830EE: using guessed type int16_t word_1830EE;
// 1830F0: using guessed type int16_t word_1830F0;
// 1830F2: using guessed type int16_t word_1830F2;
// 1830F4: using guessed type int16_t word_1830F4;
// 1830F6: using guessed type int16_t word_1830F6;
// 1830F8: using guessed type int16_t word_1830F8;
// 1830FA: using guessed type int16_t word_1830FA;
// 1830FC: using guessed type int16_t word_1830FC;
// 1830FE: using guessed type int16_t word_1830FE;
// 183100: using guessed type int16_t word_183100;
// 183102: using guessed type int16_t word_183102;
// 183104: using guessed type int16_t word_183104;
// 18310A: using guessed type int dword_18310A;
// 18310E: using guessed type int dword_18310E;
// 183112: using guessed type int dword_183112;
// 183116: using guessed type int dword_183116;
// 18311A: using guessed type int dword_18311A;
// 18311E: using guessed type int dword_18311E;
// 183122: using guessed type int dword_183122;
// 183126: using guessed type int dword_183126;
// 18312A: using guessed type int dword_18312A;
// 18312E: using guessed type int dword_18312E;
// 183132: using guessed type int dword_183132[10];
// 18315C: using guessed type int16_t word_18315C;
// 192B18: using guessed type int dword_192B18;
// 19999C: using guessed type int16_t word_19999C;
// 1A0494: using guessed type int16_t word_1A0494[];
// 1A04E4: using guessed type int16_t word_1A04E4[10];
// 1A0534: using guessed type int16_t word_1A0534[9];
// 1A0548: using guessed type int16_t word_1A0548[10];
// 1A0598: using guessed type int16_t word_1A0598[10];


//----- (000C3111) --------------------------------------------------------
void sub_C3111( int a1)
{
  int16_t v3; // di
  int v4; // eax
  int16_t v5; // cx
  char *v6; // eax
  int v7; // eax
  char *v8; // eax
  char *v9; // eax
  int16_t v10; // ax
  char *v11; // eax
  char *v12; // eax
  int v13; // eax
  char *v14; // eax
  int16_t v15; // bx
  int v16; // eax
  int v17; // edx
  char *v18; // eax
  char *v19; // eax
  int v20; // eax
  char *v21; // eax
  char *v22; // eax
  char *v23; // eax
  int v24; // [esp-Ch] [ebp-376h]
  int v25; // [esp-8h] [ebp-372h]
  _BYTE *v26; // [esp-8h] [ebp-372h]
  _BYTE *v27; // [esp-8h] [ebp-372h]
  char *v28; // [esp-4h] [ebp-36Eh]
  int v29; // [esp-4h] [ebp-36Eh]
  _BYTE *v30; // [esp-4h] [ebp-36Eh]
  _BYTE *v31; // [esp-4h] [ebp-36Eh]
  _BYTE *v32; // [esp-4h] [ebp-36Eh]
  _BYTE v33[500]; // [esp+0h] [ebp-36Ah] BYREF
  _BYTE v34[500]; // [esp+1F4h] [ebp-176h] BYREF
  _BYTE v35[500]; // [esp+3E8h] [ebp+7Eh] BYREF
  int v36; // [esp+5DCh] [ebp+272h]

  v3 = word_1A0534[a1];
  v4 = 361 * v3;
  LOWORD(v4) = *(_WORD *)(dword_192B18 + v4 + 2);
  v36 = v4;
  sub_120DED(80, 80);
  if ( v3 == word_182AB7 )
    sub_C28A8(a1);
  v5 = sub_23E60(v3);
  sub_BAF84(2u, v3 == word_182AB7);
  if ( v5 == -1 )
  {
    if ( (((int)*(uint8_t *)(dword_19306C
                                   + 113
                                   * *(uint8_t *)(dword_1930D4
                                                        + 17 * *(int16_t *)(dword_192B18 + 361 * v3 + 2)
                                                        + 2)
                                   + 42) >> word_19999C)
        & 1) != 0 )
    {
      v11 = (char *)sub_CDF5C(70);
      sprintf(v34, v11, a2);
      v10 = 134;
    }
    else
    {
      v9 = (char *)sub_CDF5C(12);
      sprintf(v34, v9);
      v10 = 12;
    }
    v12 = (char *)sub_CDF5C(v10);
    sprintf(v33, v12);
    sub_77B42();
    v25 = v13;
    v14 = (char *)sub_CDF5C(81);
    sprintf(v35, v14, v34, v25, v33);
  }
  else
  {
    if ( byte_183160[v5] )
      v28 = a1;
    else
      v28 = a2;
    v6 = (char *)sub_CDF5C(70);
    sprintf(v34, v6, v28);
    v29 = dword_19FA2C[v5];
    sub_77B42();
    v24 = v7;
    v8 = (char *)sub_CDF5C(85);
    sprintf(v35, v8, v24, v34, v29);
  }
  sub_10323B((int)v35, 0);
  if ( byte_182ACA )
  {
    sub_120CCB(0, (int)&unk_182C2E);
    sub_C28A8(a1);
    v15 = sub_BDC93(v3);
    sub_BB04E(1u);
    v16 = dword_192B18 + 361 * v3;
    v17 = *(int16_t *)(v16 + 277);
    if ( v17 == -1 )
    {
      if ( !*(_BYTE *)(v16 + 297) )
        goto LABEL_26;
      v32 = sub_B2FFA(*(_WORD *)(v16 + 277));
      v23 = (char *)sub_CDF5C(93);
      sprintf(v35, v23, a1, a0_0, v32);
      sub_1031AA((int)v35, 0);
    }
    else
    {
      if ( v15 <= 0 || v15 >= 10000 )
      {
        v20 = dword_192B18 + 361 * v3;
        if ( *(_BYTE *)(v20 + 297) )
        {
          v30 = sub_B2FFA(*(_WORD *)(v20 + 277));
          v21 = (char *)sub_CDF5C(93);
          sprintf(v35, v21, a1, a0_0, v30);
        }
        else
        {
          v31 = sub_B2FFA(*(_WORD *)(v20 + 277));
          v22 = (char *)sub_CDF5C(70);
          sprintf(v35, v22, v31);
        }
      }
      else if ( *(_BYTE *)(v16 + 297) )
      {
        v26 = sub_B2FFA(v17);
        v18 = (char *)sub_CDF5C(92);
        sprintf(v35, v18, a1, a0_0, v26, v15);
      }
      else
      {
        v27 = sub_B2FFA(v17);
        v19 = (char *)sub_CDF5C(39);
        sprintf(v35, v19, v27, v15);
      }
      sub_BAF84(2u, 0);
      sub_1031AA((int)v35, 0);
    }
    sub_120CCB(1, (int)&unk_182C2E);
  }
LABEL_26:
  JUMPOUT(0xC267F);
}
// C34D8: control flows out of bounds to C267F
// C31E3: variable 'v7' is possibly undefined
// C32CB: variable 'v13' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182AB7: using guessed type int16_t word_182AB7;
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;
// 19FA2C: using guessed type int dword_19FA2C[];
// 1A0534: using guessed type int16_t word_1A0534[9];


//----- (000C34DD) --------------------------------------------------------
int sub_C34DD( int a1, int a2)
{
  if ( a1 >= a2 )
    return a1 > a2;
  else
    return -1;
}


//----- (000C34F3) --------------------------------------------------------
int sub_C34F3()
{
  char *v0; // eax
  char *v1; // eax
  char v3[52]; // [esp+0h] [ebp-68h] BYREF
  char v4[52]; // [esp+34h] [ebp-34h] BYREF

  sub_77B42();
  strcpy(v4, v0);
  sub_77B42();
  strcpy(v3, v1);
  return stricmp(v4, v3);
}
// C351C: variable 'v0' is possibly undefined
// C3546: variable 'v1' is possibly undefined
// 13C896: using guessed type int stricmp(_DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;


//----- (000C3555) --------------------------------------------------------
int sub_C3555( int a1)
{
  int v1; // eax
  int v3; // eax

  if ( a1 <= -100 )
  {
    HIWORD(v1) = HIWORD(dword_197F9C);
    LOWORD(v1) = *(uint8_t *)(-129 * (a1 + 100) + dword_197F9C + 16);
    return v1 + 10000;
  }
  if ( a1 == -15 )
    return 9999;
  if ( a1 > 0 && a1 < 49 )
  {
    v3 = 19 * a1;
    LOWORD(v3) = *(_WORD *)((char *)&dword_17EB45 + v3);
    return v3 + 10;
  }
  if ( a1 == -6 || a1 == -4 || a1 == -5 || a1 == -7 )
    return -1;
  if ( a1 == -3 || a1 == -2 || a1 == -10 )
    return -2;
  if ( (a1 <= -100 || a1 > -50)
    && a1 != -11
    && a1 != -12
    && a1 != -13
    && a1 != -17
    && a1 != -16
    && a1 != -8
    && a1 != -9
    && a1 < 49
    && a1 == -1 )
  {
    return -1;
  }
  return 0;
}
// 17EB45: using guessed type int dword_17EB45;
// 197F9C: using guessed type int dword_197F9C;


//----- (000C3614) --------------------------------------------------------
int sub_C3614( int a1, int a2)
{
  int16_t v4; // cx
  int16_t v5; // dx
  int16_t v6; // ax
  int v7; // eax
  int v8; // edx
  _BYTE *v9; // edx
  _BYTE *v10; // eax
  int16_t v11; // dx
  int16_t v12; // ax

  v4 = *(_WORD *)(dword_192B18 + 361 * a2 + 277);
  v5 = sub_C3555(*(_WORD *)(dword_192B18 + 361 * a1 + 277));
  v6 = sub_C3555(v4);
  if ( v5 >= v6 )
    v7 = v5 > v6;
  else
    v7 = -1;
  v8 = v7;
  if ( (_WORD)v7 )
    return -v8;
  v9 = sub_B2FFA(*(_WORD *)(361 * a2 + dword_192B18 + 277));
  v10 = sub_B2FFA(*(_WORD *)(361 * a1 + dword_192B18 + 277));
  v8 = strcmp(v10, v9);
  if ( (_WORD)v8 )
    return -v8;
  v11 = sub_BDC93(a1);
  v12 = sub_BDC93(a2);
  if ( v11 >= v12 )
    return v11 > v12;
  else
    return -1;
}
// 138B90: using guessed type int strcmp(_DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;


//----- (000C36F5) --------------------------------------------------------
int sub_C36F5( int a1, int a2)
{
  int16_t v2; // bx
  int16_t v3; // ax

  v2 = *(uint8_t *)(dword_192B18 + 361 * a1 + 10);
  v3 = *(uint8_t *)(dword_192B18 + 361 * a2 + 10);
  if ( v2 >= v3 )
    return v2 > v3;
  else
    return -1;
}
// 192B18: using guessed type int dword_192B18;


//----- (000C3737) --------------------------------------------------------
int sub_C3737( int a1, int a2)
{
  int16_t v2; // bx
  int16_t v3; // ax

  v2 = *(_WORD *)(dword_192B18 + 361 * a1 + 231);
  v3 = *(_WORD *)(dword_192B18 + 361 * a2 + 231);
  if ( v2 >= v3 )
    return v2 > v3;
  else
    return -1;
}
// 192B18: using guessed type int dword_192B18;


//----- (000C377D) --------------------------------------------------------
int sub_C377D( int a1, int a2)
{
  int16_t v2; // bx
  int16_t v3; // ax

  v2 = *(_WORD *)(dword_192B18 + 361 * a1 + 233);
  v3 = *(_WORD *)(dword_192B18 + 361 * a2 + 233);
  if ( v2 >= v3 )
    return v2 > v3;
  else
    return -1;
}
// 192B18: using guessed type int dword_192B18;


//----- (000C37C3) --------------------------------------------------------
int sub_C37C3( int a1, int a2)
{
  int16_t v2; // bx
  int16_t v3; // ax

  v2 = *(_WORD *)(dword_192B18 + 361 * a1 + 235);
  v3 = *(_WORD *)(dword_192B18 + 361 * a2 + 235);
  if ( v2 >= v3 )
    return v2 > v3;
  else
    return -1;
}
// 192B18: using guessed type int dword_192B18;


//----- (000C3809) --------------------------------------------------------
int sub_C3809( int a1, int a2)
{
  int16_t v2; // bx
  int16_t v3; // ax

  v2 = *(_WORD *)(dword_192B18 + 361 * a1 + 237);
  v3 = *(_WORD *)(dword_192B18 + 361 * a2 + 237);
  if ( v2 >= v3 )
    return v2 > v3;
  else
    return -1;
}
// 192B18: using guessed type int dword_192B18;


//----- (000C386B) --------------------------------------------------------
int sub_C386B( int a1, int a2)
{
  int v2; // esi
  int v3; // ecx
  int16_t v5; // bx
  int16_t v6; // ax
  int16_t v7; // dx

  if ( a1 != -1 && a2 != -1 )
  {
    v2 = 361 * a1;
    v3 = 361 * a2;
    switch ( word_183104 )
    {
      case 0:
        return sub_C34F3();
      case 1:
        v5 = *(uint8_t *)(v3 + dword_192B18 + 10);
        v6 = *(uint8_t *)(dword_192B18 + v2 + 10);
        goto LABEL_7;
      case 2:
        v7 = *(_WORD *)(v3 + dword_192B18 + 231);
        v6 = *(_WORD *)(v2 + dword_192B18 + 231);
        return -sub_C34DD(v6, v7);
      case 3:
        v5 = *(_WORD *)(v3 + dword_192B18 + 233);
        v6 = *(_WORD *)(dword_192B18 + v2 + 233);
LABEL_7:
        v7 = v5;
        return -sub_C34DD(v6, v7);
      case 4:
        v7 = *(_WORD *)(v3 + dword_192B18 + 235);
        v6 = *(_WORD *)(v2 + dword_192B18 + 235);
        return -sub_C34DD(v6, v7);
      case 5:
        return sub_C3614(a1, a2);
      case 6:
        v7 = *(_WORD *)(v3 + dword_192B18 + 237);
        v6 = *(_WORD *)(v2 + dword_192B18 + 237);
        return -sub_C34DD(v6, v7);
      default:
        break;
    }
  }
  JUMPOUT(0xC36F0);
}
// C38AB: control flows out of bounds to C36F0
// 183104: using guessed type int16_t word_183104;
// 192B18: using guessed type int dword_192B18;


//----- (000C3947) --------------------------------------------------------
_WORD *sub_C3947()
{
  int v0; // ecx
  int16_t i; // bx
  int v2; // esi
  _WORD *result; // eax
  int16_t v4; // dx

  v0 = 0;
  do
  {
    for ( i = 0; i < 249; ++i )
    {
      v2 = 2 * i;
      result = (_WORD *)sub_C386B(*(_WORD *)(v2 + dword_1A08B0), *(_WORD *)(v2 + dword_1A08B0 + 2));
      if ( (int16_t)result > 0 )
      {
        result = (_WORD *)(v2 + dword_1A08B0);
        v4 = *(_WORD *)(v2 + dword_1A08B0);
        *result = *(_WORD *)(v2 + dword_1A08B0 + 2);
        result[1] = v4;
      }
    }
    ++v0;
  }
  while ( (int16_t)v0 < 250 );
  return result;
}
// 1A08B0: using guessed type int dword_1A08B0;


//----- (000C3996) --------------------------------------------------------
void sub_C3996()
{
  int16_t i; // dx
  int16_t v1; // bx

  for ( i = 0; i < 10; ++i )
  {
    v1 = *(_WORD *)(dword_1A08B0 + 2 * (i + word_18315A));
    word_1A0534[i] = v1;
    if ( v1 == -1 )
      word_1A0494[i] = 0;
    else
      word_1A0494[i] = *(_WORD *)(dword_192B18 + 361 * v1 + 300);
  }
  sub_11C2F0();
  sub_C683E();
  sub_BF52F();
  sub_C2E4D();
}
// 18315A: using guessed type int16_t word_18315A;
// 192B18: using guessed type int dword_192B18;
// 1A0494: using guessed type int16_t word_1A0494[10];
// 1A0534: using guessed type int16_t word_1A0534[9];
// 1A08B0: using guessed type int dword_1A08B0;


//----- (000C3A07) --------------------------------------------------------
int sub_C3A07( int a1, int a2, int a3)
{
  int v4; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+4h] [ebp-Ch] BYREF
  int v6; // [esp+8h] [ebp-8h] BYREF
  int v7; // [esp+Ch] [ebp-4h] BYREF

  sub_911D5(a1, 380, 349, 128, 91, 0, 0, 0, &v6, &v7);
  sub_911D5(a2, 380, 349, 128, 91, 0, 0, 0, &v5, &v4);
  return sub_A11C0(v6 + 2, v7 + 2, v5 + 2, v4 + 2, a3, (int16_t)dword_19F7B4 % 6);
}
// 19F7B4: using guessed type int dword_19F7B4;


//----- (000C3A9A) --------------------------------------------------------
void sub_C3A9A( int a1, unsigned int a2)
{
  int v2; // ebx
  int16_t v3; // ax
  int v4; // [esp+0h] [ebp-18h]
  int64_t v5; // [esp+4h] [ebp-14h]
  int16_t v6; // [esp+Ch] [ebp-Ch] BYREF
  int16_t v7; // [esp+10h] [ebp-8h] BYREF
  uint8_t v8; // [esp+14h] [ebp-4h]

  v8 = a2;
  v4 = -336926232;
  v5 = *(_QWORD *)((char *)&dword_C2234[5] + 3);
  sub_911D5(a1, 380, 349, 128, 91, 0, 0, 0, &v6, &v7);
  v2 = 6 * v8;
  v3 = sub_C5D97(30, 5);
  sub_1297C3(v6, v7, 5, 5, 1, *((uint8_t *)&v4 + v2 + v3));
  JUMPOUT(0xC2A94);
}
// C3B0A: control flows out of bounds to C2A94
// C2234: using guessed type int dword_C2234[7];


//----- (000C3B0F) --------------------------------------------------------
void sub_C3B0F( int a1)
{
  sub_90C4F(349, 380, a1, 128, 91, 0, 0, 0, 0, 3, 0);
}


//----- (000C3B3C) --------------------------------------------------------
void sub_C3B3C()
{
  int16_t v0; // si
  int v1; // eax
  int16_t v2; // di
  uint8_t v3; // dl
  int v4; // eax
  int v5; // edx
  char *v6; // eax
  int16_t v7; // ax
  uint8_t *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // [esp-28h] [ebp-41Ch]
  int v12; // [esp-24h] [ebp-418h]
  int v13; // [esp-20h] [ebp-414h]
  int v14; // [esp-1Ch] [ebp-410h]
  int v15; // [esp-18h] [ebp-40Ch]
  int v16; // [esp-14h] [ebp-408h]
  int v17; // [esp-10h] [ebp-404h]
  char *v18; // [esp-Ch] [ebp-400h]
  _BYTE v19[1000]; // [esp+0h] [ebp-3F4h] BYREF
  int v20; // [esp+3E8h] [ebp-Ch]
  int v21; // [esp+3ECh] [ebp-8h]
  uint8_t v22; // [esp+3F0h] [ebp-4h]

  v0 = 0;
  if ( word_182AB7 != -1 )
  {
    v1 = dword_192B18 + 361 * word_182AB7;
    v21 = 349;
    v2 = 0;
    v3 = *(_BYTE *)(v1 + 226);
    LOWORD(v1) = *(_WORD *)(v1 + 2);
    v22 = v3;
    v20 = v1;
    do
    {
      v21 += 18;
      ++v2;
      sub_B55C7(366, 20);
    }
    while ( v2 < 4 );
    sub_B53C8();
    sub_BB04E(1u);
    v4 = 0;
    do
    {
      v5 = (int16_t)v4++;
      v0 += *(_WORD *)(dword_192B18 + 361 * word_182AB7 + 2 * v5 + 200);
    }
    while ( (int16_t)v4 < 10 );
    sub_BC972(word_182AB7, -1, -1, -1, -1, -1);
    if ( v0 < 0 )
      v6 = a2;
    else
      v6 = (char *)&unk_179E17;
    v18 = v6;
    sub_E0B4F((int16_t *)(17 * *(int16_t *)(dword_192B18 + 361 * word_182AB7 + 2) + dword_1930D4), word_19999C);
    v17 = v7;
    v16 = *(uint8_t *)(361 * word_182AB7 + dword_192B18 + 10);
    v8 = (uint8_t *)(dword_1930D4 + 17 * (int16_t)v20);
    v15 = dword_192BF4[v8[10]];
    v14 = dword_192C74[v8[6]];
    v13 = dword_18F990[v22];
    v12 = dword_192BE0[v8[5]];
    if ( v0 < 0 )
      v9 = a2;
    else
      v9 = (char *)&unk_179E17;
    v11 = v9;
    v10 = (char *)sub_CDF5C(74);
    sprintf(v19, v10, v11, v12, v13, v14, v15, v16, v17, v18, v0, a0_0);
    sub_1031AA((int)v19, 0);
  }
  JUMPOUT(0xC267E);
}
// C3CF6: control flows out of bounds to C267E
// C3C54: variable 'v7' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182AB7: using guessed type int16_t word_182AB7;
// 18F990: using guessed type int dword_18F990[];
// 192B18: using guessed type int dword_192B18;
// 192BE0: using guessed type int dword_192BE0[];
// 192BF4: using guessed type int dword_192BF4[];
// 192C74: using guessed type int dword_192C74[];
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;


//----- (000C3CFB) --------------------------------------------------------
int sub_C3CFB()
{
  int result; // eax

  sub_C3B3C();
  result = sub_BB04E(1u);
  if ( word_199960 != -1 )
    return sub_1210FD(444, 431, dword_19306C + 113 * word_199960);
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 199960: using guessed type int16_t word_199960;


//----- (000C3D34) --------------------------------------------------------
void sub_C3D34( int a1)
{
  int v1; // edx
  int v2; // eax
  int16_t v3; // dx
  int16_t v4; // ax
  int16_t v5; // dx
  int16_t v6; // ax
  int v7; // [esp+0h] [ebp-Ch] BYREF
  int16_t v8; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h]

  LOWORD(dword_19F7B4) = dword_19F7B4 + 1;
  sub_124D41();
  sub_128AB6(0, 0, 639, 479);
  sub_12B634();
  sub_C2685(10, &word_18315A, &word_18315C);
  if ( byte_182ACA )
  {
    sub_120CCB(1, (int)&unk_182C2E);
    sub_128C32(0, 0, 639, 479, 0);
    sub_12A478(0, 0, dword_183106[0]);
    v1 = 0;
    do
    {
      v2 = (int16_t)v1++;
      word_1A0534[v2] = -1;
    }
    while ( (int16_t)v1 < 10 );
    sub_C3996();
    sub_C26F4();
  }
  sub_90C4F(349, 380, a1, 128, 91, 0, 0, 0, 0, 3, 0);
  v3 = 0;
  while ( 1 )
  {
    if ( word_1A0534[v3] != -1 )
      sub_C3111(v3);
    if ( ++v3 >= 10 )
    {
      if ( byte_182ACA )
      {
        if ( (_WORD)dword_1844E6 )
        {
          sub_11E718();
        }
        else
        {
          sub_1172FC();
          sub_11E718();
          sub_1172D4();
        }
        sub_124DEC();
      }
      sub_C3B3C();
      sub_BB04E(1u);
      if ( word_199960 != -1 )
        sub_1210FD(444, 431, 113 * word_199960 + dword_19306C);
      v9 = word_182974;
      if ( word_182974 != -1 && word_182AB7 != -1 )
      {
        v7 = -336926232;
        v8 = -5654;
        sub_C3A07(
          *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * v9 + 2) + 2),
          *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * word_182AB7 + 2) + 2),
          (int)&v7);
      }
      if ( byte_18315F == 1 )
      {
        v4 = sub_79C54(word_199830, word_199832);
        sub_C0E1D(229, 135, v4);
      }
      sub_C2539();
      sub_C6782();
      sub_11E718();
      v5 = sub_123AE7();
      v6 = sub_123ABA();
      sub_B9B49(v6, v5);
      JUMPOUT(0xC2679);
    }
  }
}
// C3F2B: control flows out of bounds to C2679
// 182974: using guessed type int16_t word_182974;
// 182AB7: using guessed type int16_t word_182AB7;
// 182ACA: using guessed type char byte_182ACA;
// 183106: using guessed type int dword_183106[];
// 18315A: using guessed type int16_t word_18315A;
// 18315C: using guessed type int16_t word_18315C;
// 18315F: using guessed type char byte_18315F;
// 1844E6: using guessed type int dword_1844E6;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 199960: using guessed type int16_t word_199960;
// 19F7B4: using guessed type int dword_19F7B4;
// 1A0534: using guessed type int16_t word_1A0534[9];


//----- (000C3F30) --------------------------------------------------------
char sub_C3F30(int16_t *a1, int16_t *a2)
{
  _BOOL1 v3; // sf
  int16_t i; // si
  int v5; // eax
  int v6; // ecx
  int16_t v7; // dx
  int16_t v8; // ax
  int v10; // eax

  if ( byte_18315F != 1 )
  {
LABEL_5:
    for ( i = 0; ; ++i )
    {
      if ( i >= 10 )
        return 1;
      if ( *a1 == word_1A0598[i] )
        break;
      if ( *a1 == word_1A0548[i] )
      {
        sub_119281();
        sub_C683E();
        sub_BF52F();
        sub_11C2F0();
        v6 = 17 * *(int16_t *)(dword_192B18 + 361 * word_1A0534[i] + 2) + dword_1930D4;
        word_199830 = *(uint8_t *)(v6 + 2);
        v7 = *(uint8_t *)(v6 + 3);
        word_199832 = v7;
        *(_WORD *)(dword_1930D4 + 17 * sub_79C54(*(uint8_t *)(v6 + 2), v7)) = word_1A0534[i];
        if ( word_182974 != -1 )
        {
          sub_B9A8C();
          sub_C0AF4();
        }
        v8 = word_199A08;
        word_199A08 = 25;
        word_199A10 = v8;
        return 0;
      }
      if ( word_1A0598[i] == -*a1 )
      {
        v10 = 17 * *(int16_t *)(361 * word_1A0534[i] + dword_192B18 + 2);
        word_199830 = *(uint8_t *)(v10 + dword_1930D4 + 2);
        LOWORD(v10) = *(uint8_t *)(v10 + dword_1930D4 + 3);
        byte_18315F = 1;
        word_199832 = v10;
        goto LABEL_19;
      }
      if ( *a1 == word_1A04E4[i] )
      {
        sub_BFC0B(word_1A0534[i]);
        sub_119281();
LABEL_18:
        sub_1191CA((int)sub_C3D34, 1);
        byte_182ACA = 1;
        sub_124D41();
        sub_C3D34(i);
        sub_124DEC();
        sub_124C08();
        sub_CDB18();
      }
LABEL_19:
      sub_C4169(a1, a2, i);
    }
    if ( word_182974 == -1 )
    {
      v5 = 17 * *(int16_t *)(dword_192B18 + 361 * word_1A0534[i] + 2);
      word_199830 = *(uint8_t *)(v5 + dword_1930D4 + 2);
      word_199832 = *(uint8_t *)(v5 + dword_1930D4 + 3);
      word_199A10 = word_199A08;
      word_199A08 = 1;
      *a1 = word_1830EE;
      goto LABEL_19;
    }
    sub_B9E94(word_1A0534[i]);
    sub_119281();
    goto LABEL_18;
  }
  v3 = *a1 < 0;
  if ( *a1 )
  {
    byte_18315F = 0;
    if ( !v3 )
      *a1 = 0;
    goto LABEL_5;
  }
  return 1;
}
// 182974: using guessed type int16_t word_182974;
// 182ACA: using guessed type char byte_182ACA;
// 1830EE: using guessed type int16_t word_1830EE;
// 18315F: using guessed type char byte_18315F;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 1A04E4: using guessed type int16_t word_1A04E4[10];
// 1A0534: using guessed type int16_t word_1A0534[9];
// 1A0548: using guessed type int16_t word_1A0548[10];
// 1A0598: using guessed type int16_t word_1A0598[10];


//----- (000C4169) --------------------------------------------------------
int16_t sub_C4169(_WORD *a1, int16_t *a2, int a3)
{
  int v4; // edi
  int16_t v5; // ax
  int v6; // eax
  int16_t v7; // dx

  if ( !a3 )
    word_182ABC = -1;
  v4 = 0;
  do
  {
    if ( *a1 == word_1A04F8[3 * a3 + (int16_t)v4] )
    {
      if ( word_182974 == -1 )
      {
        sub_C2A9A(a3, v4);
        if ( v5 != -1 )
          sub_B9C3D(word_1A0534[a3], v5, v4);
        byte_182ACA = 1;
      }
      else
      {
        sub_B9E94(word_1A0534[a3]);
        sub_119281();
        sub_1191CA((int)sub_C3D34, 1);
        byte_182ACA = 1;
        sub_124D41();
        sub_C3D34(a3);
        sub_124DEC();
        sub_124C08();
        sub_CDB18();
      }
    }
    if ( *a2 == word_1A04F8[3 * a3 + (int16_t)v4] )
      word_182ABC = sub_C2994(a3, v4);
    ++v4;
  }
  while ( (int16_t)v4 < 3 );
  v6 = 2 * a3;
  v7 = *a2;
  if ( *a2 == *(int16_t *)((char *)word_1A0598 + v6) || v7 == word_1A0548[a3] || v7 == word_1A04E4[a3] )
  {
    word_182AB7 = word_1A0534[a3];
    LOWORD(v6) = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * word_182AB7 + 2) + 2);
    word_199960 = v6;
  }
  return v6;
}
// C4204: variable 'v5' is possibly undefined
// 182974: using guessed type int16_t word_182974;
// 182AB7: using guessed type int16_t word_182AB7;
// 182ABC: using guessed type int16_t word_182ABC;
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199960: using guessed type int16_t word_199960;
// 1A04E4: using guessed type int16_t word_1A04E4[10];
// 1A04F8: using guessed type int16_t word_1A04F8[30];
// 1A0534: using guessed type int16_t word_1A0534[9];
// 1A0548: using guessed type int16_t word_1A0548[10];
// 1A0598: using guessed type int16_t word_1A0598[10];


//----- (000C42B4) --------------------------------------------------------
int16_t sub_C42B4( int a1)
{
  int16_t result; // ax
  int16_t v3; // ax

  result = sub_C5560(word_19999C);
  if ( result >= a1 )
  {
    v3 = word_18315A - 1;
    if ( word_18315A - 1 <= 0 )
      v3 = 0;
    word_18315A = v3;
    result = sub_C5560(word_19999C) - a1 - v3;
    byte_182ACA = 1;
    word_18315C = result;
  }
  return result;
}
// 182ACA: using guessed type char byte_182ACA;
// 18315A: using guessed type int16_t word_18315A;
// 18315C: using guessed type int16_t word_18315C;
// 19999C: using guessed type int16_t word_19999C;


//----- (000C4302) --------------------------------------------------------
int16_t sub_C4302( int a1)
{
  int16_t result; // ax

  result = sub_C5560(word_19999C);
  if ( result >= a1 )
  {
    ++word_18315A;
    result = sub_C5560(word_19999C) - a1 - word_18315A;
    byte_182ACA = 1;
    word_18315C = result;
  }
  return result;
}
// 182ACA: using guessed type char byte_182ACA;
// 18315A: using guessed type int16_t word_18315A;
// 18315C: using guessed type int16_t word_18315C;
// 19999C: using guessed type int16_t word_19999C;


//----- (000C4343) --------------------------------------------------------
char sub_C4343(int16_t *a1, int16_t *a2, int a3)
{
  int16_t v4; // ax
  int16_t v5; // ax
  int v6; // eax
  int v7; // ebx
  char v9; // [esp+0h] [ebp-4h]

  v9 = 1;
  if ( *a1 == word_1830EA )
  {
    sub_C42B4(10);
    return v9;
  }
  if ( *a1 != word_1830EC || *(int16_t *)(dword_1A08B0 + 2 * word_18315A + 20) == -1 )
  {
    v5 = *a1;
    if ( *a1 != word_1830EE && v5 != word_1830F0 )
    {
      if ( v5 != word_183102 )
      {
        if ( v5 != word_1830F2
          && v5 != word_1830F4
          && v5 != word_1830F6
          && v5 != word_1830F8
          && v5 != word_1830FA
          && v5 != word_1830FC
          && v5 != word_1830FE )
        {
          if ( word_19994C )
          {
            sub_119281();
            sub_1191CA((int)sub_C3D34, 1);
            byte_182ACA = 1;
            sub_124D41();
            sub_C3D34(a3);
            sub_124DEC();
            sub_124C08();
            sub_CDB18();
            word_19994C = 0;
          }
          else
          {
            v9 = sub_C3F30(a1, a2);
            sub_C47C1(a1, a2);
          }
          return v9;
        }
        sub_C3947();
        v6 = 0;
        do
        {
          v7 = (int16_t)v6++;
          word_1A0534[v7] = -1;
        }
        while ( (int16_t)v6 < 10 );
        word_18315A = 0;
        sub_C42B4(10);
        sub_C2685(10, &word_18315A, &word_18315C);
        sub_C3996();
      }
      byte_182ACA = 1;
      return v9;
    }
    if ( word_182974 != -1 )
    {
      sub_B9A8C();
      sub_C0AF4();
    }
    if ( word_199A08 == word_199A10 && byte_1827BD )
    {
      word_199A08 = 25;
    }
    else
    {
      word_199A08 = word_1A05AC;
      word_199A10 = word_1A05AC;
    }
    if ( *a1 == word_1830F0 )
      *a1 = word_1830EE;
  }
  else if ( sub_C5560(word_19999C) >= 10 )
  {
    ++word_18315A;
    v4 = sub_C5560(word_19999C);
    byte_182ACA = 1;
    word_18315C = v4 - 10 - word_18315A;
  }
  return v9;
}
// 1827BD: using guessed type char byte_1827BD;
// 182974: using guessed type int16_t word_182974;
// 182ACA: using guessed type char byte_182ACA;
// 1830EA: using guessed type int16_t word_1830EA;
// 1830EC: using guessed type int16_t word_1830EC;
// 1830EE: using guessed type int16_t word_1830EE;
// 1830F0: using guessed type int16_t word_1830F0;
// 1830F2: using guessed type int16_t word_1830F2;
// 1830F4: using guessed type int16_t word_1830F4;
// 1830F6: using guessed type int16_t word_1830F6;
// 1830F8: using guessed type int16_t word_1830F8;
// 1830FA: using guessed type int16_t word_1830FA;
// 1830FC: using guessed type int16_t word_1830FC;
// 1830FE: using guessed type int16_t word_1830FE;
// 183102: using guessed type int16_t word_183102;
// 18315A: using guessed type int16_t word_18315A;
// 18315C: using guessed type int16_t word_18315C;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 1A0534: using guessed type int16_t word_1A0534[9];
// 1A05AC: using guessed type int16_t word_1A05AC;
// 1A08B0: using guessed type int dword_1A08B0;


//----- (000C4562) --------------------------------------------------------
void sub_C4562(int a1, int16_t *a2, int a3)
{
  int v3; // eax
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char v9; // [esp+0h] [ebp-200h] BYREF
  int v10; // [esp+1F4h] [ebp-Ch] BYREF
  char *v11; // [esp+1F8h] [ebp-8h] BYREF
  int v12; // [esp+1FCh] [ebp-4h] BYREF

  v12 = 0;
  v11 = 0;
  dword_1A08B0 = (int)&v9;
  byte_18315F = 0;
  if ( word_199A08 != word_199A10 && !byte_1827BD && word_199A10 != 25 )
    word_1A05AC = word_199A10;
  sub_C24CA();
  sub_C2259();
  nullsub_8();
  sub_C58D1();
  sub_C3947();
  sub_C3996();
  if ( word_1A0546 == -1 )
  {
    word_18315A = 0;
    sub_C24B1();
    sub_C3996();
    sub_C3996();
  }
  sub_120CCB(1, (int)&unk_182C2E);
  sub_107AF(&v10);
  sub_123E6C((int)&unk_1828C0, 1);
  sub_119281();
  if ( sub_C5C85() )
  {
    sub_C5BB9();
    a1 = 479;
    sub_128C32(0, 0, 639, 479, 0);
  }
  sub_1205E6(1, 0, 255);
  sub_12B79D(dword_183106[0]);
  sub_133237();
  if ( sub_C5C85() )
  {
    sub_132C80(100);
    sub_131922(0, 255);
  }
  sub_131F7B();
  word_182AB7 = word_1A0534[0];
  v3 = 17 * *(int16_t *)(dword_192B18 + 361 * word_1A0534[0] + 2);
  byte_182ACE = 1;
  byte_182ACA = 1;
  word_199960 = *(uint8_t *)(dword_1930D4 + v3 + 2);
  sub_CDB18();
  sub_1191CA((int)sub_C3D34, 1);
  sub_C3D34(a3);
  sub_131922(0, 255);
  sub_124C08();
  v4 = sub_11E718();
  sub_1077D(v4, 255, 255, a2);
  byte_182ACA = 0;
  v5 = 1;
  sub_C5C44();
  sub_123E6C((int)&unk_17CF00, 1);
  sub_124C08();
  sub_C3996();
  do
  {
    sub_12C2A0();
    v7 = sub_1171AB(v6, v5, 255, a1);
    v5 = (int)&v11;
    v12 = v7;
    v11 = sub_114177();
    if ( !sub_C4343((int16_t *)&v12, (int16_t *)&v11, a3) )
    {
      sub_C683E();
      sub_BF52F();
      sub_11C2F0();
      sub_119281();
      goto LABEL_18;
    }
    sub_C3D34(a3);
    if ( byte_182ACA )
    {
      sub_C3996();
      byte_182ACA = 0;
    }
    sub_1077D(v8, (int)&v11, 255, a2);
    sub_12C2C6(1);
  }
  while ( (_WORD)v12 != word_1830EE );
  sub_C683E();
  sub_BF52F();
  sub_11C2F0();
  sub_119281();
  sub_1196F7();
  sub_107BA(&v10);
LABEL_18:
  byte_182ACE = 0;
}
// C472A: variable 'v6' is possibly undefined
// C4779: variable 'v8' is possibly undefined
// C0589: using guessed type int nullsub_8(void);
// 1827BD: using guessed type char byte_1827BD;
// 182AB7: using guessed type int16_t word_182AB7;
// 182ACA: using guessed type char byte_182ACA;
// 182ACE: using guessed type char byte_182ACE;
// 1830EE: using guessed type int16_t word_1830EE;
// 183106: using guessed type int dword_183106[];
// 18315A: using guessed type int16_t word_18315A;
// 18315F: using guessed type char byte_18315F;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199960: using guessed type int16_t word_199960;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 1A0534: using guessed type int16_t word_1A0534[9];
// 1A0546: using guessed type int16_t word_1A0546;
// 1A05AC: using guessed type int16_t word_1A05AC;
// 1A08B0: using guessed type int dword_1A08B0;


//----- (000C47C1) --------------------------------------------------------
void sub_C47C1(_WORD *a1, _WORD *a2)
{
  int16_t i; // cx
  int v4; // edx
  int v5; // eax
  int16_t j; // si
  int v7; // eax
  int16_t v8; // ax
  int v10; // [esp+4h] [ebp-4h]

  for ( i = 0; i < word_19999A; ++i )
  {
    v4 = i;
    v5 = sub_C48EF(i, i);
    v10 = v5;
    if ( *a1 == word_190178[i] && (int16_t)v5 != -1 )
    {
      for ( j = 0; j < word_199996; ++j )
      {
        v4 = dword_1A08B0;
        v7 = *(int16_t *)(dword_1A08B0 + 2 * j);
        if ( v7 != -1 )
        {
          v4 = v10;
          if ( (_WORD)v10 == *(_WORD *)(361 * v7 + dword_192B18 + 2) )
          {
            word_18315A = j;
            while ( *(int16_t *)(dword_1A08B0 + 2 * word_18315A + 18) == -1 )
              sub_C42B4(10);
            v4 = (int)&word_18315A;
            word_18315C = sub_C5560(word_19999C) - 10 - word_18315A;
            sub_C2685(10, &word_18315A, &word_18315C);
            sub_C3996();
            byte_182ACA = 1;
          }
        }
      }
    }
    if ( *a2 == word_190178[i] )
    {
      v8 = sub_C48EF(i, v4);
      word_199960 = i;
      if ( v8 != -1 )
        word_182AB7 = *(_WORD *)(dword_1930D4 + 17 * v8);
    }
  }
  JUMPOUT(0xC2A94);
}
// C48EA: control flows out of bounds to C2A94
// 182AB7: using guessed type int16_t word_182AB7;
// 182ACA: using guessed type char byte_182ACA;
// 18315A: using guessed type int16_t word_18315A;
// 18315C: using guessed type int16_t word_18315C;
// 190178: using guessed type int16_t word_190178[72];
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199960: using guessed type int16_t word_199960;
// 199996: using guessed type int16_t word_199996;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1A08B0: using guessed type int dword_1A08B0;


//----- (000C48EF) --------------------------------------------------------
int sub_C48EF( int a1, int a2)
{
  int v3; // ebx
  int v4; // eax
  int16_t i; // ax
  int v6; // esi
  int v7; // ebx

  v3 = 113 * a1 + dword_19306C;
  LOWORD(a2) = *(char *)(v3 + word_19999C + 23);
  if ( *(char *)(v3 + word_19999C + 23) == -1
    || (v4 = *(int16_t *)(dword_1930D4 + 17 * *(char *)(v3 + word_19999C + 23)), v4 == -1)
    || *(_BYTE *)(dword_192B18 + 361 * v4) )
  {
    for ( i = 0; i < 5; ++i )
    {
      v6 = 113 * a1 + dword_19306C;
      LOWORD(v6) = *(_WORD *)(v6 + 2 * i + 74);
      if ( (int16_t)v6 != -1 )
      {
        v7 = *(int16_t *)(17 * (int16_t)v6 + dword_1930D4);
        if ( v7 != -1 && *(char *)(361 * v7 + dword_192B18) == word_19999C )
          a2 = v6;
      }
    }
  }
  return a2;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;


//----- (000C49AA) --------------------------------------------------------
int sub_C49AA( int a1, int a2)
{
  int v2; // eax

  v2 = sub_127C27((int)aColsysdiLbx, 5 * a1 + 11 + a2, dword_193174);
  return nullsub_9(v2);
}
// C49C8: using guessed type int nullsub_9(_DWORD);
// 193174: using guessed type int dword_193174;


//----- (000C49C9) --------------------------------------------------------
int sub_C49C9(int a1, int a2)
{
  int16_t v2; // di
  int16_t v3; // si
  int16_t v4; // cx
  int16_t *v5; // eax
  int v6; // edx
  uint8_t v7; // al
  int v8; // eax
  int16_t *v9; // eax
  int16_t *v10; // eax
  int16_t *v11; // eax
  int16_t v12; // dx
  int result; // eax
  int v14; // [esp+0h] [ebp-214h]
  _BYTE v15[500]; // [esp+4h] [ebp-210h] BYREF
  int v16; // [esp+1F8h] [ebp-1Ch]
  int v17; // [esp+1FCh] [ebp-18h]
  int v18; // [esp+200h] [ebp-14h]
  int v19; // [esp+204h] [ebp-10h]
  int v20; // [esp+208h] [ebp-Ch]
  int v21; // [esp+20Ch] [ebp-8h]
  uint8_t v22; // [esp+210h] [ebp-4h]

  v2 = a2;
  LOWORD(a1) = dword_19F82C;
  v17 = a1;
  v19 = v14 + 28;
  v18 = 117 - (v14 + 28);
  v3 = 0;
  v21 = 0;
  v20 = a2 + 7;
  do
  {
    v4 = *(_WORD *)(113 * (int16_t)v17 + dword_19306C + 2 * (int16_t)v21 + 74);
    if ( v4 == -1 )
      goto LABEL_14;
    v5 = (int16_t *)(dword_1930D4 + 17 * v4);
    v6 = *v5;
    if ( v6 == -1 )
      v7 = *((_BYTE *)v5 + 8);
    else
      v7 = *(_BYTE *)(dword_192B18 + 361 * v6 + 226);
    v22 = v7;
    v8 = dword_1930D4 + 17 * v4;
    if ( *(_BYTE *)(v8 + 4) == 3 )
    {
      v9 = (int16_t *)sub_C49AA(v22, *(uint8_t *)(v8 + 5));
    }
    else
    {
      if ( *(_BYTE *)(v8 + 4) == 2 )
      {
        v10 = (int16_t *)sub_127C27((int)aColsysdiLbx, 62, dword_193174);
        v16 = (int16_t)v14 + 15;
        sub_C5CFF(v14 + 15, v2 + 14 + 24 * v3, v10);
      }
      if ( *(_BYTE *)(17 * v4 + dword_1930D4 + 4) != 1 )
        goto LABEL_13;
      v9 = (int16_t *)sub_127C27((int)aColsysdiLbx, 63, dword_193174);
    }
    v16 = (int16_t)v14 + 15;
    sub_C5CFF(v14 + 15, v2 + 14 + 24 * v3, v9);
LABEL_13:
    sub_BB04E(1u);
    sub_C4B98((int)v15, v4, 1);
    sub_103915(0);
LABEL_14:
    v11 = (int16_t *)sub_127C27((int)aColsysdiLbx, 65, dword_193174);
    v20 += 24;
    ++v21;
    v12 = v2 + 14 + 24 * v3++ - 2;
    result = sub_C5CFF(v14 + 2, v12, v11);
  }
  while ( (int16_t)v21 < 5 );
  return result;
}
// C49E8: variable 'v14' is possibly undefined
// 103915: using guessed type _DWORD sub_103915(int16_t);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 19F82C: using guessed type int dword_19F82C;


//----- (000C4B98) --------------------------------------------------------
int sub_C4B98(int a1, int a2, int a3)
{
  int v4; // edi
  int16_t v5; // bx
  int v6; // esi
  uint8_t v7; // al
  int v8; // eax
  int v9; // edi
  int16_t v10; // dx
  int16_t v11; // ax
  char *v12; // eax
  uint8_t *v13; // eax
  char *v14; // eax
  int result; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  int v19; // [esp-14h] [ebp-250h]
  int v20; // [esp-10h] [ebp-24Ch]
  int v21; // [esp-10h] [ebp-24Ch]
  int v22; // [esp-Ch] [ebp-248h]
  int v23; // [esp-8h] [ebp-244h]
  int v24; // [esp-8h] [ebp-244h]
  int v25; // [esp-4h] [ebp-240h]
  int v26; // [esp+0h] [ebp-23Ch]
  char v27[500]; // [esp+4h] [ebp-238h] BYREF
  _DWORD v28[5]; // [esp+1F8h] [ebp-44h]
  _DWORD v29[5]; // [esp+20Ch] [ebp-30h]
  _DWORD v30[3]; // [esp+220h] [ebp-1Ch]
  int v31; // [esp+22Ch] [ebp-10h]
  int v32; // [esp+230h] [ebp-Ch]
  int16_t v33; // [esp+234h] [ebp-8h]
  uint8_t v34; // [esp+238h] [ebp-4h]

  v33 = a3;
  v4 = 17 * a2;
  v5 = *(_WORD *)(v4 + dword_1930D4);
  v30[0] = sub_CDF5C(361);
  v30[1] = sub_CDF5C(12);
  v30[2] = sub_CDF5C(603);
  v29[0] = sub_CDF5C(502);
  v29[1] = sub_CDF5C(604);
  v29[2] = sub_CDF5C(605);
  v29[3] = sub_CDF5C(606);
  v29[4] = sub_CDF5C(607);
  v28[0] = sub_CDF5C(546);
  v28[1] = sub_CDF5C(423);
  v28[2] = sub_CDF5C(12);
  v28[3] = sub_CDF5C(450);
  v28[4] = sub_CDF5C(547);
  sub_CDF5C(441);
  sub_CDF5C(334);
  sub_CDF5C(539);
  sub_CDF5C(194);
  sub_CDF5C(262);
  sub_CDF5C(543);
  sub_CDF5C(399);
  sub_CDF5C(501);
  sub_CDF5C(184);
  sub_CDF5C(508);
  sub_CDF5C(303);
  v6 = sub_CDF5C(306);
  v32 = sub_CDF5C(186);
  if ( v5 == -1 )
    v7 = *(_BYTE *)(v4 + dword_1930D4 + 8);
  else
    v7 = *(_BYTE *)(dword_192B18 + 361 * v5 + 226);
  v34 = v7;
  v8 = dword_1930D4 + 17 * a2;
  if ( *(_BYTE *)(v8 + 4) == 3 )
  {
    if ( v5 == -1 )
    {
      strcpy(v27, (char *)sub_CDF5C(12));
    }
    else
    {
      if ( v33 != -1 )
        sub_BAF3C(v33, *(_BYTE *)(dword_192B18 + 361 * v5));
      v9 = 361 * v5;
      v10 = *(char *)(v9 + dword_192B18);
      v31 = 17 * a2;
      sub_E0B4F((int16_t *)(v31 + dword_1930D4), v10);
      v25 = v11;
      v23 = *(uint8_t *)(v9 + dword_192B18 + 10);
      v12 = (char *)sub_CDF5C(8);
      sprintf(v27, v12, v23, v25);
    }
    v13 = (uint8_t *)(17 * a2 + dword_1930D4);
    v24 = v28[v13[10]];
    v22 = v30[v13[6]];
    if ( v5 == -1 )
    {
      v21 = dword_18F990[v34];
      v19 = v29[v13[5]];
      v16 = (char *)sub_CDF5C(44);
      return sprintf(v26, v16, v19, v21, v22, v24, v27);
    }
    else
    {
      v20 = 3753 * *(char *)(dword_192B18 + 361 * v5) + dword_197F98 + 21;
      v14 = (char *)sub_CDF5C(41);
      return sprintf(v26, v14, v20, v22, v24, v27);
    }
  }
  else
  {
    if ( *(_BYTE *)(v8 + 4) == 2 )
    {
      v17 = (char *)sub_CDF5C(70);
      sprintf(v26, v17, v6);
    }
    result = dword_1930D4;
    if ( *(_BYTE *)(17 * a2 + dword_1930D4 + 4) == 1 )
    {
      v18 = (char *)sub_CDF5C(70);
      return sprintf(v26, v18, v32);
    }
  }
  return result;
}
// C4D7A: variable 'v11' is possibly undefined
// C4E1C: variable 'v26' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 18F990: using guessed type int dword_18F990[];
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000C4ED1) --------------------------------------------------------
unsigned int sub_C4ED1( int a1, int a2, int a3)
{
  int v3; // ecx
  unsigned int result; // eax
  int16_t *v5; // eax
  int16_t v6; // dx
  int16_t v7; // di
  _BYTE *v8; // eax
  _BYTE *v9; // [esp-8h] [ebp-30h]
  int16_t v12; // [esp+10h] [ebp-18h]
  int16_t v13; // [esp+14h] [ebp-14h]
  int16_t v14; // [esp+18h] [ebp-10h]
  int16_t i; // [esp+20h] [ebp-8h]

  v3 = 0;
  v14 = dword_19F82C;
  for ( i = 0; i < 5; ++i )
  {
    result = *(int16_t *)(2 * i + dword_19306C + 113 * v14 + 74);
    if ( result == -1 )
    {
      ++v3;
      word_19F9CA[i] = -1000;
    }
    else
    {
      v5 = (int16_t *)sub_127C27(
                        (int)aColsysdiLbx,
                        *(uint8_t *)(dword_1930D4 + 17 * result + 5)
                      + 5 * *(uint8_t *)(dword_1930D4 + 17 * result + 8)
                      + 11,
                        dword_193174);
      v6 = v5[1];
      v13 = *v5;
      v9 = (_BYTE *)sub_CDF5C(12);
      v7 = v6 / 2 + 24 * v3 + a2 + 14;
      v12 = 24 * v3 + a2 + 14 - v6 / 2;
      word_19F9CA[i] = sub_11438B(a1 + 15 - v13 / 2, v12, a1 + 15 + v13 / 2, v7, v9, 0);
      v8 = (_BYTE *)sub_CDF5C(12);
      result = sub_11438B(a1 + 15 + v13 / 2 + 2, v12, a3 - 2, v7, v8, 0);
      ++v3;
      word_19F9C0[i] = result;
    }
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 19F82C: using guessed type int dword_19F82C;
// 19F9C0: using guessed type int16_t word_19F9C0[5];
// 19F9CA: using guessed type int16_t word_19F9CA[5];


//----- (000C500B) --------------------------------------------------------
void sub_C500B(int a1, int a2)
{
  int16_t v3; // ax
  int16_t *v4; // eax
  int v5; // edx
  uint8_t v6; // dl
  int16_t i; // cx
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int16_t *v11; // eax
  int16_t v12; // [esp+0h] [ebp-8h]
  int16_t v13; // [esp+4h] [ebp-4h]

  v3 = *(_WORD *)(dword_192B18 + 361 * dword_19F7A8 + 2);
  v13 = v3;
  if ( v3 != -1 )
  {
    v4 = (int16_t *)(dword_1930D4 + 17 * v3);
    v5 = *v4;
    if ( v5 == -1 )
      v6 = *((_BYTE *)v4 + 8);
    else
      v6 = *(_BYTE *)(dword_192B18 + 361 * v5 + 226);
    for ( i = 0; ; ++i )
    {
      v8 = dword_1930D4 + 17 * v13;
      if ( i > *(uint8_t *)(v8 + 3) )
        break;
    }
    sub_127C27((int)aColsysdiLbx, 5 * v6 + 11 + *(uint8_t *)(v8 + 5), dword_193174);
    v9 = (int16_t)sub_C5D97(50, 6);
    v10 = sub_127C27((int)aColsysdiLbx, 64, dword_193174);
    sub_12B753(v10, v9);
    v11 = (int16_t *)sub_127C27((int)aColsysdiLbx, 64, dword_193174);
    sub_C5CFF(v12 + 2, a2 + 14 + 24 * (i - 1) - 2, v11);
  }
  JUMPOUT(0xC4B92);
}
// C50FD: control flows out of bounds to C4B92
// C50F6: variable 'v12' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000C52F6) --------------------------------------------------------
_DWORD *sub_C52F6()
{
  _DWORD *result; // eax

  dword_183194 = (int)sub_126B42((int)aColpupsLbx, 17, dword_192ED4);
  dword_18318C = (int)sub_126B42((int)aColpupsLbx, 19, dword_192ED4);
  result = sub_126B42((int)aColpupsLbx, 20, dword_192ED4);
  dword_183190 = (int)result;
  return result;
}
// 18318C: using guessed type int dword_18318C;
// 183190: using guessed type int dword_183190;
// 183194: using guessed type int dword_183194;
// 192ED4: using guessed type int dword_192ED4;


//----- (000C534E) --------------------------------------------------------
unsigned int sub_C534E()
{
  int16_t v0; // si
  _BYTE *v1; // eax
  _WORD *v2; // ecx
  int v3; // eax
  _WORD *v4; // ecx
  int v5; // eax
  _WORD *v6; // ecx
  int v7; // eax
  int16_t v8; // di
  unsigned int result; // eax
  _BYTE *v10; // eax
  _BYTE *v11; // [esp-8h] [ebp-10h]
  _BYTE *v12; // [esp-8h] [ebp-10h]
  _BYTE *v13; // [esp-8h] [ebp-10h]
  int16_t v14; // [esp+0h] [ebp-8h]
  int16_t v15; // [esp+4h] [ebp-4h]

  v0 = sub_C5560(word_19999C);
  if ( v0 < 6 )
  {
    word_1A06A4 = -1000;
  }
  else
  {
    v1 = (_BYTE *)sub_CDF5C(12);
    word_1A06A4 = sub_115478(449, 75, 0, v0, 0, v0 - 6, 14, 164, (int)&word_18315C, v1, 0);
  }
  v11 = (_BYTE *)sub_CDF5C(12);
  v2 = (_WORD *)dword_18318C;
  v3 = sub_CDF5C(12);
  v15 = 52;
  word_1A06A8 = (uint16_t)sub_1151B0(448, 52, v3, v2, v11, 40);
  v12 = (_BYTE *)sub_CDF5C(12);
  v4 = (_WORD *)dword_183190;
  v5 = sub_CDF5C(12);
  v14 = 83;
  word_1A06AA = (uint16_t)sub_1151B0(447, 243, v5, v4, v12, 40);
  v13 = (_BYTE *)sub_CDF5C(12);
  v6 = (_WORD *)dword_183194;
  v7 = sub_CDF5C(12);
  v8 = 0;
  word_1A06A6 = (uint16_t)sub_1151B0(352, 285, v7, v6, v13, 40);
  do
  {
    result = word_1A08C0[v8];
    if ( result != -1 )
    {
      v10 = (_BYTE *)sub_CDF5C(12);
      result = sub_11438B(15, v15, 441, v14, v10, 0);
      word_1A08E4[v8] = result;
    }
    v15 += 38;
    ++v8;
    v14 += 38;
  }
  while ( v8 < 6 );
  return result;
}
// 18315C: using guessed type int16_t word_18315C;
// 18318C: using guessed type int dword_18318C;
// 183190: using guessed type int dword_183190;
// 183194: using guessed type int dword_183194;
// 19999C: using guessed type int16_t word_19999C;
// 1A06A4: using guessed type int16_t word_1A06A4;
// 1A06A6: using guessed type int16_t word_1A06A6;
// 1A06A8: using guessed type int16_t word_1A06A8;
// 1A06AA: using guessed type int16_t word_1A06AA;
// 1A08C0: using guessed type int16_t word_1A08C0[12];
// 1A08E4: using guessed type int16_t word_1A08E4[];


//----- (000C53C9) --------------------------------------------------------
int sub_C53C9( int a1)
{
  return sub_B4EF6(
           word_1A08C0[a1],
           -1,
           0,
           148,
           38 * a1 + 54,
           441,
           0,
           (int)&unk_1A06AC + 84 * a1,
           &word_1A08D8[a1],
           &word_1A08B4[a1],
           &word_1A08A4[a1]);
}
// 1A08A4: using guessed type _WORD word_1A08A4[6];
// 1A08B4: using guessed type int16_t word_1A08B4[6];
// 1A08C0: using guessed type int16_t word_1A08C0[12];
// 1A08D8: using guessed type _WORD word_1A08D8[6];


//----- (000C5426) --------------------------------------------------------
int sub_C5426( int a1, int a2)
{
  int16_t *v3; // eax

  word_1A08C0[a2] = a1;
  if ( (((int)*(uint8_t *)(dword_19306C
                                 + 113
                                 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * a1 + 2) + 2)
                                 + 42) >> word_19999C)
      & 1) != 0
    || sub_234B8(a1) )
  {
    sub_BB012(4u, 0);
  }
  else
  {
    sub_BB04E(4u);
  }
  v3 = sub_77B28(*(_WORD *)(dword_192B18 + 361 * a1 + 2));
  sub_10315D((int)v3, 0);
  return sub_C53C9(a2);
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;
// 1A08C0: using guessed type int16_t word_1A08C0[12];


//----- (000C54DF) --------------------------------------------------------
int16_t sub_C54DF( int result)
{
  char v1; // cl
  int16_t i; // dx
  int v3; // ebx

  v1 = result;
  if ( (_BYTE)result == 1 )
  {
    for ( i = 0; i < word_199998; ++i )
    {
      v3 = i;
      result = sub_C5560(i);
      word_1A0694[v3] = result;
    }
  }
  byte_183198 = v1;
  return result;
}
// 183198: using guessed type char byte_183198;
// 199998: using guessed type int16_t word_199998;
// 1A0694: using guessed type int16_t word_1A0694[8];


//----- (000C5512) --------------------------------------------------------
int16_t sub_C5512( int a1)
{
  int16_t v2; // dx
  int16_t i; // ax

  v2 = 0;
  if ( byte_183198 )
    return word_1A0694[a1];
  for ( i = 0; i < word_199996; ++i )
  {
    if ( *(char *)(dword_192B18 + 361 * i) == a1 )
      ++v2;
  }
  return v2;
}
// 183198: using guessed type char byte_183198;
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;
// 1A0694: using guessed type int16_t word_1A0694[8];


//----- (000C5560) --------------------------------------------------------
int16_t sub_C5560( int a1)
{
  int16_t v2; // si
  int16_t i; // dx
  char *v5; // eax

  v2 = 0;
  if ( byte_183198 )
    return word_1A0694[a1];
  for ( i = 0; i < word_199996; ++i )
  {
    v5 = (char *)(361 * i + dword_192B18);
    if ( *v5 == a1 && !v5[6] )
      ++v2;
  }
  return v2;
}
// 183198: using guessed type char byte_183198;
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;
// 1A0694: using guessed type int16_t word_1A0694[8];


//----- (000C56BB) --------------------------------------------------------
void sub_C56BB()
{
  int16_t v0; // cx
  int v1; // edi
  int v2; // esi

  v0 = sub_C5560(word_19999C);
  sub_C2685(6, &word_18315A, &word_18315C);
  if ( v0 < 6 )
  {
    sub_128C32(449, 75, 457, 239, 80);
  }
  else
  {
    v1 = (int16_t)(164 * word_18315A / v0 + 75);
    v2 = (int16_t)(164 * (word_18315A + 6) / v0 + 75);
    sub_128C32(449, v1, 457, v2, 229);
    sub_134D2D(449, v1, 457, v1, 230);
    sub_134D2D(449, v1, 449, v2, 230);
    sub_134D2D(457, v1, 457, v2, 228);
    sub_134D2D(449, v2, 457, v2, 228);
    sub_12972D(449, 75, 80);
    sub_12972D(457, 75, 80);
    sub_12972D(449, 239, 80);
    sub_12972D(457, 239, 80);
  }
  JUMPOUT(0xC56B5);
}
// C57DB: control flows out of bounds to C56B5
// 18315A: using guessed type int16_t word_18315A;
// 18315C: using guessed type int16_t word_18315C;
// 19999C: using guessed type int16_t word_19999C;


//----- (000C5800) --------------------------------------------------------
void sub_C5800()
{
  int v0; // ebx
  int v1; // eax
  int16_t i; // bx
  int v3; // eax
  int16_t v4; // dx
  int16_t v5; // ax

  sub_BAEFE();
  if ( byte_182ACA )
  {
    byte_182976 = 1;
    sub_107C2(&dword_1A08F0);
    byte_182976 = 0;
    byte_182ACA = 1;
    dword_183188 = sub_127C27((int)aColpupsLbx, 16, dword_193174);
    sub_12A478(0, 0, dword_183188);
    sub_124DEC();
    byte_182ACA = 0;
  }
  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    word_1A08C0[v1] = -1;
  }
  while ( (int16_t)v0 < 6 );
  sub_C2685(6, &word_18315A, &word_18315C);
  for ( i = 0; i < 6; ++i )
  {
    v3 = *(int16_t *)(2 * (i + word_18315A) + dword_1A08B0);
    if ( v3 != -1 )
      sub_C5426(v3, i);
  }
  sub_C56BB();
  v4 = sub_123AE7();
  v5 = sub_123ABA();
  sub_B9B49(v5, v4);
}
// 182976: using guessed type char byte_182976;
// 182ACA: using guessed type char byte_182ACA;
// 18315A: using guessed type int16_t word_18315A;
// 18315C: using guessed type int16_t word_18315C;
// 183188: using guessed type int dword_183188;
// 193174: using guessed type int dword_193174;
// 1A08B0: using guessed type int dword_1A08B0;
// 1A08C0: using guessed type int16_t word_1A08C0[12];
// 1A08F0: using guessed type int (*dword_1A08F0)(void);


//----- (000C58D1) --------------------------------------------------------
int sub_C58D1()
{
  int v0; // ebx
  int16_t i; // dx
  char *v2; // eax
  int v3; // eax
  int result; // eax
  int v5; // edx

  v0 = 0;
  for ( i = 0; i < word_199996; ++i )
  {
    v2 = (char *)(dword_192B18 + 361 * i);
    if ( *v2 == word_19999C && !v2[6] )
    {
      v3 = (int16_t)v0++;
      *(_WORD *)(dword_1A08B0 + 2 * v3) = i;
    }
  }
  for ( result = v0; (int16_t)result < 250; ++result )
  {
    v5 = (int16_t)result;
    *(_WORD *)(dword_1A08B0 + 2 * v5) = -1;
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;
// 19999C: using guessed type int16_t word_19999C;
// 1A08B0: using guessed type int dword_1A08B0;


//----- (000C5934) --------------------------------------------------------
void sub_C5934(int a1, int a2, int a3)
{
  int v3; // ecx
  unsigned int v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax
  unsigned int v8; // eax
  _BYTE v9[500]; // [esp+0h] [ebp-1F4h] BYREF
  _DWORD savedregs[6]; // [esp+1F4h] [ebp+0h] BYREF

  byte_182ACA = 1;
  dword_1A08B0 = (int)v9;
  qmemcpy(v9, &word_C5102, sizeof(v9));
  v3 = 0;
  sub_C58D1();
  sub_120CCB(1, (int)&unk_182C2E);
  sub_107AF(&dword_1A08F0);
  sub_119281();
  sub_1191CA((int)sub_C5800, 1);
  sub_CDB4E();
  sub_C5800();
  sub_124C08();
  sub_11C2F0();
  v4 = sub_C534E();
  v5 = sub_1077D(v4, 1, a3, (int16_t *)savedregs);
  v6 = -1;
  while ( 1 )
  {
    v7 = sub_1171AB(v5, v6, a3, v3);
    v3 = v7;
    if ( (_WORD)v7 == word_1A06A8 )
    {
      sub_C42B4(6);
    }
    else if ( (_WORD)v7 != word_1A06AA || (a3 = dword_1A08B0, *(int16_t *)(dword_1A08B0 + 2 * word_18315A + 12) == -1) )
    {
      a3 = 0;
      do
      {
        if ( (_WORD)v7 == word_1A08E4[(int16_t)a3] )
          LOWORD(v6) = word_1A08C0[(int16_t)a3];
        ++a3;
      }
      while ( (int16_t)a3 < 6 );
    }
    else
    {
      sub_C4302(6);
    }
    if ( word_19994C )
    {
      byte_182ACA = 1;
      word_19994C = 0;
      sub_CDB4E();
    }
    sub_C5800();
    sub_11C2F0();
    v8 = sub_C534E();
    sub_1077D(v8, v6, a3, (int16_t *)savedregs);
    if ( (_WORD)v3 != word_1A06A6 )
    {
      v5 = (int16_t)v6;
      if ( (int16_t)v6 == -1 )
        continue;
    }
    sub_11C2F0();
    sub_1196F7();
    sub_119281();
    sub_107BA((int *)&dword_1A08F0);
    JUMPOUT(0xC56B4);
  }
}
// C5A7F: control flows out of bounds to C56B4
// C5102: using guessed type int16_t word_C5102;
// 182ACA: using guessed type char byte_182ACA;
// 18315A: using guessed type int16_t word_18315A;
// 19994C: using guessed type int16_t word_19994C;
// 1A06A6: using guessed type int16_t word_1A06A6;
// 1A06A8: using guessed type int16_t word_1A06A8;
// 1A06AA: using guessed type int16_t word_1A06AA;
// 1A08B0: using guessed type int dword_1A08B0;
// 1A08C0: using guessed type int16_t word_1A08C0[12];
// 1A08E4: using guessed type int16_t word_1A08E4[];
// 1A08F0: using guessed type int (*dword_1A08F0)(void);


//----- (000C5A84) --------------------------------------------------------
char sub_C5A84( int a1, int a2, unsigned int a3)
{
  uint16_t i; // ax

  for ( i = 0; i < a3; ++i )
  {
    if ( a1 == *(_WORD *)(a2 + 2 * i) )
      return 1;
  }
  return 0;
}


//----- (000C5AA7) --------------------------------------------------------
int sub_C5AA7( int a1, int a2, unsigned int a3)
{
  int result; // eax

  for ( result = 0; (uint16_t)result < a3; ++result )
  {
    if ( a1 == *(_WORD *)(a2 + 2 * (uint16_t)result) )
      return result;
  }
  return -1;
}


//----- (000C5AC8) --------------------------------------------------------
char sub_C5AC8(char *a1, int a2, int a3, int a4)
{
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char v8[1000]; // [esp+0h] [ebp-3ECh] BYREF
  char *v9; // [esp+3E8h] [ebp-4h] BYREF

  v4 = &a4;
  v9 = &a4;
  if ( a2 >= 0 )
  {
    if ( (unsigned int)vsprintf(v8, a3, &v9) > 0x3E8 )
    {
      v5 = (char *)sub_CDF5C(408);
      sub_126487(v5, a3);
    }
    if ( a2 )
    {
      v6 = (char *)sub_CDF5C(71);
      LOBYTE(v4) = sprintf(a1, v6, a1, 13, v8);
    }
    else
    {
      strcpy(a1, v8);
    }
  }
  return (char)v4;
}
// C5B4B: variable 'v4' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 13C8F0: using guessed type int vsprintf(_DWORD, _DWORD, _DWORD);


//----- (000C5B64) --------------------------------------------------------
void sub_C5B64( unsigned int a1)
{
  if ( a1 < 2u )
  {
    if ( !a1 )
      sub_124B65();
  }
  else if ( a1 <= 2u )
  {
    sub_124C9B();
  }
  else if ( a1 == 3 )
  {
    sub_124C08();
  }
}


//----- (000C5B85) --------------------------------------------------------
char sub_C5B85( int result)
{
  byte_18319D = result;
  return result;
}
// 18319D: using guessed type char byte_18319D;


//----- (000C5B94) --------------------------------------------------------
int16_t sub_C5B94( int result)
{
  byte_18319C = result;
  if ( !result )
    return sub_123E6C((int)&unk_17CF00, 1);
  return result;
}
// 18319C: using guessed type char byte_18319C;


//----- (000C5BB0) --------------------------------------------------------
int16_t sub_C5BB0()
{
  return (uint8_t)byte_18319C;
}
// 18319C: using guessed type char byte_18319C;


//----- (000C5BB9) --------------------------------------------------------
void sub_C5BB9()
{
  char v0; // bl
  int16_t i; // dx
  int v2; // eax
  int v3; // eax

  IsMemPoolReady_110B5C();
  v0 = 0;
  if ( !byte_18319C )
  {
    sub_124B65();
    for ( i = (uint8_t)byte_18319C; i <= 100; i += (uint8_t)byte_18319D )
    {
      v2 = sub_132C80(i);
      byte_18319C = i;
      sub_FE8BE(v2);
      v0 = 1;
    }
    if ( v0 )
    {
      sub_124D7A();
      sub_128C32(0, 0, 639, 479, 0);
      sub_124E36();
      v3 = sub_131922(0, 255);
      sub_1077D(v3);
    }
    sub_124C08();
  }
}
// 1077D: using guessed type int sub_1077D(_DWORD);
// FE8BE: using guessed type int sub_FE8BE(_DWORD);
// 18319C: using guessed type char byte_18319C;
// 18319D: using guessed type char byte_18319D;


//----- (000C5C44) --------------------------------------------------------
void sub_C5C44()
{
  int16_t i; // dx
  int v1; // eax

  if ( byte_18319C )
  {
    sub_124B65();
    for ( i = (uint8_t)byte_18319C; i >= 0; i -= 10 )
    {
      v1 = sub_132C80(i);
      byte_18319C = i;
      sub_FE8BE(v1);
    }
  }
  sub_124C08();
}
// FE8BE: using guessed type int sub_FE8BE(_DWORD);
// 18319C: using guessed type char byte_18319C;


//----- (000C5C7F) --------------------------------------------------------
char sub_C5C7F( int result)
{
  byte_18319E = result;
  return result;
}
// 18319E: using guessed type char byte_18319E;


//----- (000C5C85) --------------------------------------------------------
char sub_C5C85()
{
  _BOOL1 v1; // zf
  int v2; // eax

  if ( !byte_18319E )
  {
    if ( (uint16_t)word_199A08 < 0x14u )
    {
      if ( word_199A08 == 1 )
      {
        if ( byte_199F19 == 25 )
          goto LABEL_13;
        v1 = byte_199F19 == 33;
LABEL_10:
        if ( !v1 )
        {
          v2 = 1;
          return v2 != 0;
        }
LABEL_13:
        v2 = 0;
        return v2 != 0;
      }
    }
    else
    {
      if ( (uint16_t)word_199A08 <= 0x14u )
        return byte_199F19 != 25;
      if ( (uint16_t)word_199A08 >= 0x19u )
      {
        if ( (uint16_t)word_199A08 > 0x19u )
          return 1;
        if ( byte_199F19 == 1 || byte_199F19 == 33 )
          goto LABEL_13;
        v1 = byte_199F19 == 20;
        goto LABEL_10;
      }
    }
  }
  return 1;
}
// 18319E: using guessed type char byte_18319E;
// 199A08: using guessed type int16_t word_199A08;
// 199F19: using guessed type char byte_199F19;


//----- (000C5CFF) --------------------------------------------------------
int sub_C5CFF( int a1, int a2, int16_t *a3)
{
  return sub_12A478(a1 - *a3 / 2, a2 - a3[1] / 2, (int)a3);
}


//----- (000C5D55) --------------------------------------------------------
void sub_C5D55()
{
  JUMPOUT(0xC5D22);
}
// C5D73: control flows out of bounds to C5D22


//----- (000C5D75) --------------------------------------------------------
int sub_C5D75( int a1, int a2, int16_t *a3)
{
  return sub_129FF9(a1 - *a3 / 2, a2 - a3[1], (int)a3);
}


//----- (000C5D97) --------------------------------------------------------
unsigned int sub_C5D97(int a1, int a2)
{
  return (unsigned int)(j___clock(a1, 0, a2) / (uint64_t)(unsigned int)(int16_t)a1) % (int16_t)a2;
}
// 129FE4: using guessed type int64_t j___clock(_DWORD, _DWORD, _DWORD);


//----- (000C5DB5) --------------------------------------------------------
int sub_C5DB5(int a1, int a2, int a3, int a4)
{
  dword_1A08F8 = dword_1A08FC;
  dword_1A08FC = j___clock(dword_1A08FC, a2, a3);
  return sub_12102B(0, 0, (int16_t)(dword_1A08FC - dword_1A08F8), a4);
}
// 129FE4: using guessed type int64_t j___clock(_DWORD, _DWORD, _DWORD);
// 1A08F8: using guessed type int dword_1A08F8;
// 1A08FC: using guessed type int dword_1A08FC;


//----- (000C5DE7) --------------------------------------------------------
char sub_C5DE7( int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  sub_1297C3(a1, a2, a3, a4, a5, 255);
  return sub_131B5D(255, 19, 16, 9, 32, 40, 21, a7);
}


//----- (000C5E2D) --------------------------------------------------------
int sub_C5E2D(int a1, int a2, int a3, int a4)
{
  int16_t i; // si
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v12; // [esp+0h] [ebp-Ch]

  for ( i = 0; i < 4; ++i )
  {
    v6 = (i + 1) % 4;
    v7 = *(int16_t *)(a2 + 2 * v6);
    v12 = *(int16_t *)(a1 + 2 * v6);
    v8 = *(int16_t *)(a2 + 2 * i);
    v9 = *(int16_t *)(a1 + 2 * i);
    sub_134D2D(v9, v8, v12, v7, 255);
  }
  LOBYTE(v10) = sub_131B5D(255, 19, 16, 9, 32, 40, 21, a4);
  return nullsub_10(v10);
}
// C5E9E: variable 'v10' is possibly undefined
// C5E9F: using guessed type int nullsub_10(_DWORD);


//----- (000C5ED3) --------------------------------------------------------
int sub_C5ED3(int a1, int a2, int a3, int a4, int a5, int a6)
{
  sub_103952(a3, a5, a3);
  return sub_103915(a6);
}
// 103915: using guessed type _DWORD sub_103915(int16_t);
// 103952: using guessed type int sub_103952(_DWORD, _DWORD, _DWORD);


//----- (000C5F14) --------------------------------------------------------
int sub_C5F14(int a1, int a2, int a3, int a4, int a5)
{
  sub_103952(a3, a5, a3);
  return sub_103915(2);
}
// 103915: using guessed type _DWORD sub_103915(int16_t);
// 103952: using guessed type int sub_103952(_DWORD, _DWORD, _DWORD);


//----- (000C5F52) --------------------------------------------------------
int sub_C5F52()
{
  nullsub_6();
  return sub_201A4();
}
// BB0C3: using guessed type int nullsub_6(void);


