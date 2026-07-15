#include "orion_common.h"

/* Adresni rozsah: 0xE5B69 - 0xF53CB  (200 funkci) */

//----- (000E5B69) --------------------------------------------------------
void __fastcall sub_E5B69( int a1, int a2)
{
  int v4; // ebx
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax

  v4 = 10;
  v5 = 0;
  while ( 1 )
  {
    v4 -= 2;
    v6 = *(int16_t *)(v4 + dword_19306C + 113 * a2 + 74);
    if ( v6 != -1 )
    {
      v7 = *(int16_t *)(17 * v6 + dword_1930D4);
      if ( v7 != -1 )
      {
        v8 = 361 * v7 + dword_192B18;
        if ( a1 == *(char *)v8 )
        {
          LOWORD(v8) = *(uint8_t *)(v8 + 10);
          v5 += v8;
        }
      }
    }
    if ( !v4 )
      JUMPOUT(0xDEB17);
  }
}
// E5BD3: control flows out of bounds to DEB17
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000E5BD8) --------------------------------------------------------
int __fastcall sub_E5BD8(int a1, int a2)
{
  return *(uint8_t *)(a1 + 1) - *(uint8_t *)(a2 + 1);
}


//----- (000E5BE3) --------------------------------------------------------
int __usercall sub_E5BE3( int a1, int a2,
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
        hr_int128_t a28)
{
  int16_t v28; // ax
  int v29; // esi
  int v30; // edi
  int v31; // eax
  int v32; // ebx
  int v33; // ebx
  int v34; // ebx
  char *v35; // ebx
  unsigned int v36; // eax
  unsigned int v37; // eax
  int16_t v39; // [esp+82h] [ebp-66h]
  int16_t v40; // [esp+86h] [ebp-62h]
  _BYTE v41[2]; // [esp+88h] [ebp-60h]
  _BYTE v42[94]; // [esp+8Ah] [ebp-5Eh] BYREF

  v28 = sub_E5CD4(a1, a2, (int)&a10 + 2);
  v29 = v28;
  v30 = -1;
  if ( v28 )
  {
    v30 = v28;
    v31 = 2 * v28;
    while ( v30 > 0 )
    {
      v32 = *((uint8_t *)&a10 + v30 + 1);
      v41[v31] = v32;
      v31 -= 2;
      *(_DWORD *)((char *)&a28 + 6) = 10;
      --v30;
      v42[v31 + 1] = 0;
      *(_DWORD *)((char *)&a28 + 2) = 113 * v32;
      do
      {
        *(_DWORD *)((char *)&a28 + 6) -= 2;
        v33 = *(int16_t *)(*(_DWORD *)((char *)&a28 + 6) + *(_DWORD *)((char *)&a28 + 2) + dword_19306C + 74);
        if ( v33 != -1 )
        {
          v34 = *(int16_t *)(dword_1930D4 + 17 * v33);
          if ( v34 != -1 )
          {
            v35 = (char *)(dword_192B18 + 361 * v34);
            if ( *v35 == v40 )
              v42[v31 + 1] += v35[10];
          }
        }
      }
      while ( *(int *)((char *)&a28 + 6) > 0 );
    }
    qsort(v42, v29, 2);
    v36 = (v29 + 1) / 2;
    if ( v39 )
      v37 = v29 - sub_1247A0(v36);
    else
      v37 = sub_1247A0(v36) - 1;
    LOWORD(v30) = (uint8_t)v42[2 * v37];
  }
  return v30;
}
// E5C7A: variable 'v40' is possibly undefined
// E5CAE: variable 'v39' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000E5CD4) --------------------------------------------------------
int __fastcall sub_E5CD4( int a1, int a2, int a3)
{
  int v3; // edi
  unsigned int v4; // esi
  int v5; // eax
  unsigned int v6; // edx
  char v7; // bl
  int v8; // eax
  int v9; // eax
  char *v10; // eax
  int v15; // [esp+14h] [ebp-Ch]
  int16_t v16; // [esp+18h] [ebp-8h]
  int16_t v17; // [esp+1Ch] [ebp-4h]

  v17 = *(_WORD *)(dword_197F98 + 3753 * a2 + 804);
  v16 = 0;
  v3 = 0;
  v4 = 113 * word_19999A + dword_19306C;
  while ( v4 > dword_19306C )
  {
    v5 = (int)*(uint8_t *)(v4 - 57) >> a1;
    v4 -= 113;
    if ( (v5 & 1) != 0 )
    {
      ++v16;
      if ( sub_FF5F8(v4, a2, v17) )
      {
        v15 = 5;
        v6 = v4 + 10;
        v7 = 0;
        do
        {
          --v15;
          v8 = *(int16_t *)(v6 + 72);
          v6 -= 2;
          if ( v8 != -1 )
          {
            v9 = *(int16_t *)(17 * v8 + dword_1930D4);
            if ( v9 != -1 )
            {
              v10 = (char *)(361 * v9 + dword_192B18);
              if ( *v10 == a1 )
              {
                if ( v10[319] )
                  v7 = 1;
              }
            }
          }
        }
        while ( v15 > 0 && !v7 );
        if ( !v7 )
        {
          if ( a3 )
            *(_BYTE *)(a3 + (int16_t)v3) = (int)(v4 - dword_19306C) / 113;
          ++v3;
        }
      }
    }
  }
  if ( v16 == 1 )
    return 0;
  return v3;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E5DE8) --------------------------------------------------------
int __fastcall sub_E5DE8(int a1)
{
  if ( a1 >= 8 )
    return dword_192644[a1];
  else
    return 3753 * a1 + dword_197F98 + 21;
}
// 192644: using guessed type int dword_192644[];
// 197F98: using guessed type int dword_197F98;


//----- (000E5E09) --------------------------------------------------------
void __fastcall sub_E5E09(int a1)
{
  int v1; // edi
  int v2; // esi
  unsigned int v3; // ebx
  int v4; // ecx
  int v6; // eax
  int v7; // ecx

  v1 = dword_197F98 + 3753 * a1;
  v2 = 0;
  v3 = dword_1930DC + 3953;
  while ( v3 > dword_1930DC )
  {
    v4 = *(char *)(v3 - 1);
    v3 -= 59;
    if ( v4 == (v1 - dword_197F98) / 3753 && *(_BYTE *)(v3 + 57) <= 1u )
    {
      v6 = (int)(v3 - dword_1930DC) / 59;
      v7 = 0;
      if ( (*(_BYTE *)(v3 + 38) & 0x20) != 0 )
      {
        v7 = 15 * ((int16_t)sub_94951(v6) + 1);
      }
      else if ( (*(_BYTE *)(v3 + 38) & 0x10) != 0 )
      {
        v7 = 10 * ((int16_t)sub_94951(v6) + 1);
      }
      if ( v2 < v7 )
        v2 = v7;
    }
  }
  JUMPOUT(0xE1F95);
}
// E5EAE: control flows out of bounds to E1F95
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (000E5EB3) --------------------------------------------------------
void __fastcall sub_E5EB3( int a1, int a2, int a3)
{
  uint8_t *v4; // esi
  int v5; // ecx
  unsigned int i; // ecx
  _WORD *v7; // eax
  int v8; // edx
  _BYTE *j; // eax
  int v10; // eax
  int v11; // edx
  int16_t v12; // [esp+0h] [ebp-18h]
  char v13; // [esp+14h] [ebp-4h]

  v13 = 0;
  v4 = (uint8_t *)(dword_1930D4 + 17 * a1);
  if ( a3 || (v5 = *(int16_t *)v4, v5 == -1) )
  {
    for ( i = dword_192B18; *(char *)(i + 1) != (_WORD)a2; i += 361 )
      ;
  }
  else
  {
    v13 = 1;
    i = dword_192B18 + 361 * v5;
  }
  if ( dword_192B18 + 361 * word_199996 <= i )
    word_199996 = (int)(i - dword_192B18) / 361 + 1;
  sub_12D75((int)(i - dword_192B18) / 361, v12, a2);
  *(_BYTE *)(i + 1) = -1;
  if ( a3 )
  {
    *(_BYTE *)(i + 6) = 1;
    *(_BYTE *)(i + 10) = 0;
    *(_BYTE *)(i + 226) = v4[8];
  }
  else
  {
    *(_BYTE *)(i + 10) = 1;
    v7 = (_WORD *)(i + 12);
    if ( !v4[11] || (v8 = dword_197F98 + 3753 * (int16_t)a2, *(_BYTE *)(v8 + 2225)) || *(_BYTE *)(v8 + 2224) )
    {
      *v7 &= 0xFE7Fu;
      *(_BYTE *)v7 |= 0x80u;
    }
    else
    {
      *v7 &= 0xFE7Fu;
    }
    *(_BYTE *)v7 &= 0xF0u;
    *(_DWORD *)v7 |= a2 & 0xF;
    *(_BYTE *)v7 &= 0x8Fu;
    *(_DWORD *)v7 |= 16 * (a2 & 7);
    *(_BYTE *)(i + 13) |= 2u;
    if ( v4[15] == 6 )
    {
      for ( j = (_BYTE *)(i + 16); (unsigned int)j < i + 28; *(j - 3) |= 2u )
      {
        *j |= 9u;
        *(_WORD *)j &= 0xFE09u;
        *(_DWORD *)j |= 16 * (a2 & 7);
        j += 4;
      }
      *(_BYTE *)(i + 10) = 4;
      v10 = 113 * v4[2];
      v11 = dword_19306C;
      v4[15] = 0;
      *(_BYTE *)(v11 + v10 + 40) = 0;
    }
    if ( v13 )
      *(_BYTE *)(i + 332) = 1;
    sub_E2A70((int)(i - dword_192B18) / 361, a2);
    *(_WORD *)(i + 291) = -39;
  }
  *(_WORD *)(i + 277) = -1;
  sub_E5296((_BYTE *)(dword_19306C + 113 * v4[2]));
}
// E5F56: variable 'v12' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;


//----- (000E6071) --------------------------------------------------------
void __fastcall sub_E6071( int a1, int a2)
{
  sub_E5EB3(a1, a2, 0);
}


//----- (000E607F) --------------------------------------------------------
void sub_E607F()
{
  JUMPOUT(0xE6078);
}
// E6089: control flows out of bounds to E6078


//----- (000E608B) --------------------------------------------------------
int __fastcall sub_E608B(int a1)
{
  int16_t v2; // ax
  int v3; // edx
  int v4; // ebx

  v2 = 5;
  v3 = 0;
  do
  {
    v4 = *(int16_t *)(a1 + 2 * --v2 + 74);
    if ( v4 != -1 && *(int16_t *)(dword_1930D4 + 17 * v4) == -1 )
      ++v3;
  }
  while ( v2 > 0 );
  return v3;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (000E60C8) --------------------------------------------------------
int __fastcall sub_E60C8(int a1, int a2)
{
  int16_t v4; // bx
  int v5; // edx
  int v6; // eax
  int16_t *v7; // eax
  int v8; // eax
  char *v9; // eax

  v4 = 5;
  v5 = 0;
  do
  {
    v6 = *(int16_t *)(a1 + 2 * --v4 + 74);
    if ( v6 != -1 )
    {
      v7 = (int16_t *)(dword_1930D4 + 17 * v6);
      if ( *((_BYTE *)v7 + 4) == 3 )
      {
        v8 = *v7;
        if ( v8 == -1 || (v9 = (char *)(361 * v8 + dword_192B18), v9[6]) && *v9 == a2 )
          ++v5;
      }
    }
  }
  while ( v4 > 0 );
  return v5;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;


//----- (000E6132) --------------------------------------------------------
int __fastcall sub_E6132(int a1)
{
  int16_t v2; // ax
  int v3; // edx
  int v4; // ebx

  v2 = 5;
  v3 = 0;
  do
  {
    v4 = *(int16_t *)(a1 + 2 * --v2 + 74);
    if ( v4 != -1 && *(int16_t *)(17 * v4 + dword_1930D4) == -1 )
      ++v3;
  }
  while ( v2 > 0 );
  return v3;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (000E6170) --------------------------------------------------------
char sub_E6170()
{
  unsigned int i; // eax
  unsigned int v1; // ebx
  int v2; // edx
  int v3; // eax
  int v4; // eax
  char *v5; // ebx
  int v6; // edx
  int v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  int v10; // ebx
  unsigned int v11; // edx
  uint8_t v12; // dl
  int16_t v13; // ax
  uint8_t *v14; // ebx
  _BOOL1 v15; // cl
  int v16; // edx
  int v17; // eax
  int v18; // ecx
  int16_t v20; // [esp-4h] [ebp-1Ch]
  _BYTE v21[72]; // [esp+0h] [ebp-18h] BYREF
  _BYTE v22[72]; // [esp+48h] [ebp+30h] BYREF
  int v23; // [esp+90h] [ebp+78h]
  int v24; // [esp+94h] [ebp+7Ch]
  int v25; // [esp+98h] [ebp+80h]
  int v26; // [esp+9Ch] [ebp+84h]
  int16_t v27; // [esp+A0h] [ebp+88h]

  memset(v21, 0, sizeof(v21));
  memset(v22, 0, sizeof(v22));
  for ( i = dword_19306C + 113 * word_19999A; i > dword_19306C; i -= 113 )
    *(_BYTE *)(i - 58) = 8;
  v1 = dword_197F9C + 129 * word_199994;
  while ( v1 > dword_197F9C )
  {
    v1 -= 129;
    if ( !*(_BYTE *)(v1 + 100) && (*(_BYTE *)(v1 + 17) == 1 || *(_BYTE *)(v1 + 17) == 4) && *(int16_t *)(v1 + 101) < 72 )
    {
      v2 = dword_19306C;
      v3 = dword_19306C + 113 * *(int16_t *)(v1 + 101);
      if ( *(_BYTE *)(v3 + 55) == 8 )
      {
        *(_BYTE *)(v3 + 55) = *(_BYTE *)(v1 + 99);
        v4 = (v3 - v2) / 113;
        if ( *(_BYTE *)(v1 + 17) == 4 )
          v21[v4] |= 1 << *(_BYTE *)(v1 + 99);
        else
          v22[v4] |= 1 << *(_BYTE *)(v1 + 99);
      }
      else if ( *(_BYTE *)(v3 + 55) != *(_BYTE *)(v1 + 99) )
      {
        *(_BYTE *)(v3 + 55) = -1;
      }
    }
  }
  v5 = (char *)(361 * word_199996 + dword_192B18);
  while ( (unsigned int)v5 > dword_192B18 )
  {
    v5 -= 361;
    if ( *v5 != -1 && v5[321] )
    {
      v6 = dword_19306C;
      v7 = dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)v5 + 1) + 2);
      if ( *(_BYTE *)(v7 + 55) == 8 )
      {
        *(_BYTE *)(v7 + 55) = *v5;
        v22[(v7 - v6) / 113] |= 1 << *v5;
      }
      else if ( *(_BYTE *)(v7 + 55) != *v5 )
      {
        *(_BYTE *)(v7 + 55) = -1;
      }
    }
  }
  v8 = 113 * word_19999A + dword_19306C;
  while ( v8 > dword_19306C )
  {
    v8 -= 113;
    if ( *(_BYTE *)(v8 + 55) == 8
      || ((((int)(uint8_t)v22[(int)(v8 - dword_19306C) / 113] >> *(_BYTE *)(v8 + 55)) & 1) == 0
       || (int16_t)sub_E60C8(v8, *(char *)(v8 + 55)) <= 0)
      && ((((int)(uint8_t)v21[(int)(v8 - dword_19306C) / 113] >> *(_BYTE *)(v8 + 55)) & 1) == 0
       || (int16_t)sub_E6132(v8) <= 0) )
    {
      *(_BYTE *)(v8 + 55) = -1;
    }
  }
  v9 = dword_197F9C + 129 * word_199994;
  while ( v9 > dword_197F9C )
  {
    v9 -= 129;
    if ( !*(_BYTE *)(v9 + 100) && !*(_BYTE *)(v9 + 17) && *(int16_t *)(v9 + 101) < 72 )
    {
      v10 = 113 * *(int16_t *)(v9 + 101) + dword_19306C;
      v11 = *(char *)(v10 + 55);
      if ( v11 < 8 && *(_BYTE *)(v10 + 55) != *(_BYTE *)(v9 + 99) )
      {
        if ( *(char *)(v9 + 99) >= 8
          || (v12 = *(_BYTE *)(3753 * v11 + dword_197F98 + *(char *)(v9 + 99) + 1575), v12 >= 4u) && v12 <= 6u )
        {
          *(_BYTE *)(v10 + 55) = -1;
        }
      }
    }
  }
  LOBYTE(v13) = dword_192B18;
  v14 = (uint8_t *)(dword_192B18 + 361 * word_199996);
  while ( (unsigned int)v14 > dword_192B18 )
  {
    v14 -= 361;
    if ( (char)*v14 != -1 && v14[321] )
    {
      LOBYTE(v13) = *(_BYTE *)(dword_19306C
                             + 113
                             * *(uint8_t *)(dword_1930D4
                                                  + 17
                                                  * *(int16_t *)(361 * ((int)&v14[-dword_192B18] / 361)
                                                               + dword_192B18
                                                               + 2)
                                                  + 2)
                             + 55) != *v14;
      v15 = v13;
      if ( *(_BYTE *)(dword_19306C
                    + 113
                    * *(uint8_t *)(dword_1930D4
                                         + 17 * *(int16_t *)(361 * ((int)&v14[-dword_192B18] / 361) + dword_192B18 + 2)
                                         + 2)
                    + 55) == *v14 )
      {
        v13 = sub_E60C8(
                dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)v14 + 1) + 2),
                (char)*v14);
        v15 = v13 == 0;
      }
      if ( v15 )
      {
        v16 = dword_17EC16 / 2;
        BYTE2(v23) = v14[2];
        v17 = 3753 * (char)*v14;
        v18 = dword_197F98;
        v14[321] = 0;
        *(_DWORD *)(v18 + v17 + 50) += v16;
        v20 = (char)*v14;
        LOBYTE(v23) = 0;
        HIBYTE(v23) = 0;
        LOWORD(v24) = 11;
        HIWORD(v24) = v16;
        LOBYTE(v13) = sub_EF629(v23, v24, v25, v26, v27, v20);
      }
    }
  }
  return v13;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17EC16: using guessed type int dword_17EC16;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E64F4) --------------------------------------------------------
int sub_E64F4()
{
  int v0; // ecx
  unsigned int v1; // edx
  int v2; // ebx
  int16_t i; // dx
  int v4; // eax
  int v5; // eax
  int result; // eax
  int v7; // edx
  int v8; // ecx
  int16_t v9; // bx
  int v10; // ebx
  _BYTE v11[252]; // [esp+0h] [ebp-11Ch]
  _WORD v12[8]; // [esp+FCh] [ebp-20h] BYREF
  _WORD v13[8]; // [esp+10Ch] [ebp-10h] BYREF

  sub_E6170();
  memset(v12, 0, sizeof(v12));
  v0 = 0;
  v1 = 113 * word_19999A + dword_19306C;
  while ( v1 > dword_19306C )
  {
    v2 = *(char *)(v1 - 58);
    v1 -= 113;
    if ( v2 != -1 )
      v12[v2] += sub_E608B(v1);
  }
  for ( i = 0; i < 250; ++i )
  {
    v4 = dword_192B18 + 361 * i;
    *(_BYTE *)(v4 + 1) = -1;
    if ( i >= word_199996 || *(int16_t *)(v4 + 2) == -1 )
    {
      v5 = (int16_t)v0++;
      v11[v5] = i;
    }
  }
  memset(v13, 0, sizeof(v13));
  result = dword_192FD8 / word_199998;
  v7 = dword_192FD8 % word_199998;
  v8 = 0;
  v9 = 0;
  while ( v9 < word_199998 )
  {
    result = 2 * (int16_t)v7;
    if ( *(_WORD *)((char *)v13 + result) >= *(_WORD *)((char *)v12 + result) )
    {
      ++v9;
    }
    else
    {
      v10 = 361 * (uint8_t)v11[(int16_t)v8++];
      *(_BYTE *)(dword_192B18 + v10 + 1) = v7;
      v9 = 0;
      ++v13[(int16_t)v7];
    }
    LOWORD(v7) = v7 + 1;
    if ( (_WORD)v7 == word_199998 )
      LOWORD(v7) = 0;
  }
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 192FD8: using guessed type int dword_192FD8;
// 19306C: using guessed type int dword_19306C;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E65F8) --------------------------------------------------------
void __fastcall sub_E65F8( int a1)
{
  unsigned int v1; // esi
  char *v2; // edi
  unsigned int v3; // eax
  int16_t v4; // bx
  int16_t v5; // cx
  int16_t *v6; // eax
  uint16_t v7; // ax
  int16_t v8; // dx
  unsigned int v9; // ebx
  unsigned int v11; // [esp+4h] [ebp-14h]
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int16_t v13; // [esp+10h] [ebp-8h]
  char v14; // [esp+14h] [ebp-4h]

  v1 = 113 * word_19999A + dword_19306C;
  while ( v1 > dword_19306C )
  {
    v14 = 0;
    v1 -= 113;
    do
    {
      if ( *(char *)(v1 + 55) == a1
        && ((v2 = sub_FDA3F(a1, (int)(v1 - dword_19306C) / 113),
             v3 = sub_FDAA7(a1, 1, (int)(v1 - dword_19306C) / 113, 1),
             v11 = v3,
             v2)
         || v3) )
      {
        v13 = -1;
        v12 = 0;
        v4 = 5;
        do
        {
          v5 = *(_WORD *)(v1 + 2 * --v4 + 74);
          if ( v5 != -1 )
          {
            v6 = (int16_t *)(dword_1930D4 + 17 * v5);
            if ( *v6 == -1 )
            {
              v7 = sub_D27A7((int)v6, (_BYTE *)(3753 * a1 + dword_197F98));
              if ( v7 > v12 )
              {
                v12 = v7;
                v13 = v5;
              }
            }
          }
        }
        while ( v4 > 0 );
        if ( v13 == -1 )
        {
          v14 = 1;
          while ( v2 )
          {
            *(_DWORD *)(dword_197F98 + 3753 * a1 + 50) += dword_17EC16 / 2;
            v8 = (int)(v1 - dword_19306C) / 113;
            v2[321] = 0;
            v2 = sub_FDA3F(a1, v8);
          }
        }
        else
        {
          sub_E5EB3(v13, a1, 0);
          if ( v2 )
          {
            sub_145EA((int)&v2[-dword_192B18] / 361, 0xBu, (int)v2);
          }
          else
          {
            v9 = 129 * word_199994 + dword_197F9C;
            while ( v9 > dword_197F9C )
            {
              v9 -= 129;
              if ( *(_BYTE *)(v9 + 127) == 4
                && *(char *)(v9 + 99) == a1
                && *(int16_t *)(v9 + 101) == (int)(v1 - dword_19306C) / 113 )
              {
                *(_BYTE *)(v9 + 127) = 0;
              }
            }
            sub_A163A((int)(v11 - dword_197F9C) / 129, 0);
            sub_8A4C4();
          }
        }
      }
      else
      {
        v14 = 1;
      }
    }
    while ( !v14 );
  }
  JUMPOUT(0xE64EE);
}
// E67F1: control flows out of bounds to E64EE
// 17EC16: using guessed type int dword_17EC16;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E67F6) --------------------------------------------------------
void sub_E67F6()
{
  int16_t v0; // dx

  v0 = word_199998;
  while ( v0 > 0 )
  {
    if ( *(_BYTE *)(3753 * --v0 + dword_197F98 + 40) != 100 )
      sub_E65F8(v0);
  }
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000E6828) --------------------------------------------------------
unsigned int __fastcall sub_E6828(char *a1)
{
  dword_1AA3C4 = (int)a1;
  dword_1AA3CC = (int)&a1[strlen(a1) + 1];
  dword_1AA3C8 = strlen((char *)dword_1AA3CC) + 1 + dword_1AA3CC;
  dword_1AA3C0 = strlen((char *)dword_1AA3C8) + 1 + dword_1AA3C8;
  dword_1AA3D4 = strlen((char *)dword_1AA3C0) + 1 + dword_1AA3C0;
  dword_1AA3D0 = strlen((char *)dword_1AA3D4) + 1 + dword_1AA3D4;
  dword_1AA3D8 = strlen((char *)dword_1AA3D0) + 1 + dword_1AA3D0;
  dword_1AA3B8 = strlen((char *)dword_1AA3D8) + 1 + dword_1AA3D8;
  dword_1AA3BC = strlen((char *)dword_1AA3B8) + 1 + dword_1AA3B8;
  dword_1AA3DC = strlen((char *)dword_1AA3BC) + 1 + dword_1AA3BC;
  return dword_1AA3DC + strlen((char *)dword_1AA3DC) + 1;
}
// 1AA3B8: using guessed type int dword_1AA3B8;
// 1AA3BC: using guessed type int dword_1AA3BC;
// 1AA3C0: using guessed type int dword_1AA3C0;
// 1AA3C4: using guessed type int dword_1AA3C4;
// 1AA3C8: using guessed type int dword_1AA3C8;
// 1AA3CC: using guessed type int dword_1AA3CC;
// 1AA3D0: using guessed type int dword_1AA3D0;
// 1AA3D4: using guessed type int dword_1AA3D4;
// 1AA3D8: using guessed type int dword_1AA3D8;
// 1AA3DC: using guessed type int dword_1AA3DC;


//----- (000E6903) --------------------------------------------------------
void *__fastcall sub_E6903(void *result)
{
  qmemcpy(&word_1AA380, result, 0x2Cu);
  return result;
}
// 1AA380: using guessed type int16_t word_1AA380;


//----- (000E691A) --------------------------------------------------------
void **__fastcall sub_E691A(void **result, int a2)
{
  void *v2; // esi
  void *v3; // esi

  if ( a2 == -1 )
    v2 = (void *)dword_1AA3E0;
  else
    v2 = (void *)(dword_1AA3B0 + 88 * a2);
  qmemcpy(*result, v2, 0x58u);
  *result = (char *)*result + 88;
  if ( a2 == -1 )
    v3 = (void *)dword_1AA3E4;
  else
    v3 = (void *)(dword_1AA3B4 + a2);
  qmemcpy(*result, v3, 1u);
  *result = (char *)*result + 1;
  return result;
}
// 1AA3B0: using guessed type int dword_1AA3B0;
// 1AA3B4: using guessed type int dword_1AA3B4;
// 1AA3E0: using guessed type int dword_1AA3E0;
// 1AA3E4: using guessed type int dword_1AA3E4;


//----- (000E6979) --------------------------------------------------------
void **__fastcall sub_E6979(void **result, int a2)
{
  void *v2; // esi
  void *v3; // edi
  void *v4; // esi
  void *v5; // edi

  if ( a2 == -1 )
  {
    v3 = (void *)dword_1AA3E0;
    v2 = *result;
  }
  else
  {
    v2 = *result;
    v3 = (void *)(dword_1AA3B0 + 88 * a2);
  }
  qmemcpy(v3, v2, 0x58u);
  *result = (char *)*result + 88;
  if ( a2 == -1 )
  {
    v5 = (void *)dword_1AA3E4;
    v4 = *result;
  }
  else
  {
    v4 = *result;
    v5 = (void *)(dword_1AA3B4 + a2);
  }
  qmemcpy(v5, v4, 1u);
  *result = (char *)*result + 1;
  return result;
}
// 1AA3B0: using guessed type int dword_1AA3B0;
// 1AA3B4: using guessed type int dword_1AA3B4;
// 1AA3E0: using guessed type int dword_1AA3E0;
// 1AA3E4: using guessed type int dword_1AA3E4;


//----- (000E69DE) --------------------------------------------------------
int __fastcall sub_E69DE(int result)
{
  if ( result != -1 )
    return *(int16_t *)(dword_192B18 + 361 * result + 2);
  return result;
}
// 192B18: using guessed type int dword_192B18;


//----- (000E69F7) --------------------------------------------------------
int __fastcall sub_E69F7(int result)
{
  if ( result != -1 )
    return *(int16_t *)(dword_1930D4 + 17 * result);
  return result;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (000E6A0C) --------------------------------------------------------
int16_t __fastcall sub_E6A0C(int a1, int a2, int a3, _WORD *a4, int16_t *a5, int a6, _WORD *a7, _WORD *a8)
{
  int16_t v8; // si
  int v10; // [esp+0h] [ebp-10h]

  v10 = a1;
  *a4 = 0;
  *a5 = 0;
  *a7 = 500;
  v8 = 0;
  *a8 = 0;
  while ( v8 < word_199994 )
  {
    a1 = 129 * v8 + dword_197F9C;
    if ( *(_WORD *)(a1 + 101) == a2 && !*(_BYTE *)(a1 + 100) )
    {
      LOWORD(a1) = *(char *)(a1 + 99);
      if ( (_WORD)a1 == a3 )
      {
        a1 = v10 + 2 * *a5;
        *(_WORD *)a1 = v8;
        ++*a5;
      }
      else if ( (_WORD)a1 == a6 )
      {
        a1 = v10 + 2 * (int16_t)--*a7;
        *(_WORD *)a1 = v8;
        ++*a8;
      }
    }
    ++v8;
  }
  return a1;
}
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000E6AA2) --------------------------------------------------------
int __fastcall sub_E6AA2(int a1, int a2, int a3)
{
  int v3; // esi
  int result; // eax
  int v5; // ecx

  if ( a2 < 8 )
  {
    if ( *(_BYTE *)(dword_1AA3B0 + 88 * a1 + 11 * a2 + 6) )
      goto LABEL_6;
  }
  else if ( (((int)*(uint8_t *)(dword_1AA3B4 + a1) >> a2) & 1) != 0 )
  {
    goto LABEL_6;
  }
  *(_WORD *)(2 * a1 + dword_1AA3AC) &= ~(uint16_t)(1 << a2);
LABEL_6:
  v3 = 2 * a1;
  if ( a3 < 8 )
  {
    v5 = dword_1AA3B0 + 88 * a1;
    result = 11 * a3;
    if ( *(_BYTE *)(v5 + 11 * a3 + 6) )
      return result;
  }
  else
  {
    result = (int)*(uint8_t *)(dword_1AA3B4 + a1) >> a3;
    if ( (result & 1) != 0 )
      return result;
  }
  result = dword_1AA3AC;
  *(_WORD *)(v3 + dword_1AA3AC) &= ~(uint16_t)(1 << a3);
  return result;
}
// 1AA3AC: using guessed type int dword_1AA3AC;
// 1AA3B0: using guessed type int dword_1AA3B0;
// 1AA3B4: using guessed type int dword_1AA3B4;


//----- (000E6B44) --------------------------------------------------------
int16_t *__usercall sub_E6B44(int16_t *result, int a2, int a3)
{
  int16_t *v3; // ebx
  int16_t *i; // edx

  v3 = result;
  if ( a2 > 0 )
  {
    if ( *(_BYTE *)(dword_197F98 + 3753 * *(char *)(129 * *result + dword_197F9C + 99) + 40) == 100
      && (uint8_t)byte_199F3A <= 1u )
    {
      sub_77423(dword_1AA3C4);
    }
    for ( i = &v3[a2]; v3 < i; sub_A163A(*i, a3) )
      --i;
    *(_BYTE *)(dword_1AA3E0 + 11 * *(char *)(129 * *v3 + dword_197F9C + 99) + 6) = 0;
    return (int16_t *)sub_8A4C4();
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199F3A: using guessed type char byte_199F3A;
// 1AA3C4: using guessed type int dword_1AA3C4;
// 1AA3E0: using guessed type int dword_1AA3E0;


//----- (000E6BCD) --------------------------------------------------------
int __usercall sub_E6BCD( int a1, int a2)
{
  int v3; // ebx
  int v4; // edi
  char *v5; // ebx
  int v6; // edx
  int16_t v8; // [esp+0h] [ebp-14h]
  int v9; // [esp+4h] [ebp-10h]
  int v10; // [esp+8h] [ebp-Ch]
  unsigned int v11; // [esp+Ch] [ebp-8h]
  unsigned int v12; // [esp+10h] [ebp-4h]

  v3 = 113 * a1 + dword_19306C;
  v10 = *(int16_t *)(v3 + 15);
  v9 = *(int16_t *)(v3 + 17);
  v11 = -1;
  v4 = -1;
  v5 = (char *)(361 * word_199996 + dword_192B18);
  while ( (unsigned int)v5 > dword_192B18 )
  {
    v5 -= 361;
    if ( *v5 == v8 )
    {
      v6 = 17 * *((int16_t *)v5 + 1);
      LOWORD(a2) = *(uint8_t *)(v6 + dword_1930D4 + 2);
      if ( (_WORD)a2 != a1 && (_WORD)a2 != (_WORD)v4 )
      {
        v12 = *(uint8_t *)(v6 + dword_1930D4 + 2);
        if ( !(uint16_t)sub_1276F0(dword_19306C + 113 * a1 + 31, v12)
          && (*(int16_t *)(dword_19306C + 113 * v12 + 15) - v10) * (*(int16_t *)(dword_19306C + 113 * v12 + 15) - v10)
           + (*(int16_t *)(dword_19306C + 113 * v12 + 17) - v9) * (*(int16_t *)(dword_19306C + 113 * v12 + 17) - v9) < v11 )
        {
          v11 = (*(int16_t *)(dword_19306C + 113 * v12 + 15) - v10)
              * (*(int16_t *)(dword_19306C + 113 * v12 + 15) - v10)
              + (*(int16_t *)(dword_19306C + 113 * v12 + 17) - v9) * (*(int16_t *)(dword_19306C + 113 * v12 + 17) - v9);
          v4 = a2;
        }
      }
    }
  }
  return v4;
}
// E6C28: variable 'v8' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 199996: using guessed type int16_t word_199996;


//----- (000E6CAA) --------------------------------------------------------
unsigned int __fastcall sub_E6CAA( int a1, int a2, int a3)
{
  char v4; // bl
  unsigned int result; // eax
  int v6; // ebx
  int16_t v7; // di
  bool v8; // eax
  unsigned int v9; // ebx
  int16_t v10; // ax
  int v11; // eax
  int v12; // edi
  unsigned int v13; // eax
  int16_t v14; // bx

  if ( a3 == -1 && *(_BYTE *)(dword_1AA3E0 + 11 * a2 + 7) || *(_BYTE *)(dword_1AA3E0 + 11 * a2 + 7) >= 2u )
  {
    v4 = 0;
    result = 129 * word_199994 + dword_197F9C;
    while ( result > dword_197F9C )
    {
      v7 = *(char *)(result - 30);
      result -= 129;
      if ( v7 == a2 && a1 == *(_WORD *)(result + 101) && !*(_BYTE *)(result + 100) )
      {
        v4 = 1;
        break;
      }
    }
    if ( !v4 )
    {
      v6 = 11 * a2;
      result = dword_1AA3E0;
LABEL_8:
      *(_BYTE *)(v6 + result + 6) = 0;
    }
  }
  else
  {
    v8 = a2 < 8 && !*(_BYTE *)(3753 * a2 + dword_197F98 + 2236);
    if ( v8 && sub_233FA() )
    {
      v9 = 129 * word_199994 + dword_197F9C;
      while ( v9 > dword_197F9C )
      {
        v10 = *(char *)(v9 - 30);
        v9 -= 129;
        if ( v10 == a2 && a1 == *(_WORD *)(v9 + 101) && !*(_BYTE *)(v9 + 100) )
        {
          v11 = *(int16_t *)(v9 + 116);
          if ( v11 != -1 )
          {
            v12 = dword_1930DC + 59 * v11;
            if ( *(char *)(v12 + 55) <= 0 )
              sub_941C6(v11, v12);
            else
              sub_944A3(v11, v12);
          }
          sub_A163A((int)(v9 - dword_197F9C) / 129, 129);
        }
      }
      result = 11 * a2;
      v6 = dword_1AA3E0;
      goto LABEL_8;
    }
    v13 = dword_197F9C + 129 * word_199994;
    while ( v13 > dword_197F9C )
    {
      v14 = *(char *)(v13 - 30);
      v13 -= 129;
      if ( v14 == a2 && a1 == *(_WORD *)(v13 + 101) && !*(_BYTE *)(v13 + 100) )
        *(_BYTE *)(v13 + 100) = 9;
    }
    *(_BYTE *)(dword_1AA3E0 + 11 * a2 + 6) = 0;
    return sub_8A4C4();
  }
  return result;
}
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 1AA3E0: using guessed type int dword_1AA3E0;


//----- (000E6E52) --------------------------------------------------------
void __usercall sub_E6E52(int a1)
{
  unsigned int v1; // esi
  int v2; // ebx
  int v3; // edx
  int v4; // eax
  int v5; // edx
  int16_t v6; // ax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // ebx
  int v13; // ecx
  int16_t v14; // dx
  int v15; // ebx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int16_t v19; // dx
  int i; // ebx
  int v21; // eax
  int v22; // edx
  uint8_t v23; // al
  _BOOL1 v24; // zf
  int16_t v25; // ax
  int v26; // eax
  int v27; // edx
  int v28; // ecx
  int v29; // ebx
  _BYTE v30[2304]; // [esp+0h] [ebp-D38h] BYREF
  int16_t v31[502]; // [esp+900h] [ebp-438h] BYREF
  int v32; // [esp+CECh] [ebp-4Ch]
  int v33; // [esp+CF0h] [ebp-48h]
  int v34; // [esp+CF4h] [ebp-44h]
  int v35; // [esp+CF8h] [ebp-40h]
  int16_t v36; // [esp+CFCh] [ebp-3Ch]
  _BYTE v37[16]; // [esp+D00h] [ebp-38h] BYREF
  _BYTE v38[8]; // [esp+D10h] [ebp-28h] BYREF
  int v39; // [esp+D18h] [ebp-20h]
  int v40; // [esp+D1Ch] [ebp-1Ch]
  int v41; // [esp+D20h] [ebp-18h]
  int v42; // [esp+D24h] [ebp-14h]
  int v43; // [esp+D28h] [ebp-10h]
  int v44; // [esp+D2Ch] [ebp-Ch]
  char v45; // [esp+D30h] [ebp-8h]
  char v46; // [esp+D34h] [ebp-4h]

  v1 = 129 * word_199994 + dword_197F9C;
  memset(v30, 0, sizeof(v30));
  memset(v38, -1, sizeof(v38));
  while ( 1 )
  {
    while ( 1 )
    {
      do
      {
        while ( 1 )
        {
          while ( 1 )
          {
            if ( v1 <= dword_197F9C )
            {
              v27 = word_199998;
              v41 = 288 * word_199998;
              while ( v27 > 0 )
              {
                v28 = word_19999A + 1;
                v41 -= 288;
                --v27;
                v29 = v41 + 4 * v28;
                while ( v28 > 0 )
                {
                  v29 -= 4;
                  --v28;
                  if ( *(_WORD *)&v30[v29 + 1] )
                  {
                    HIBYTE(v32) = v30[v29];
                    LOWORD(v33) = *(_WORD *)&v30[v29 + 1];
                    BYTE2(v33) = v30[v29 + 3];
                    LOBYTE(v32) = 14;
                    BYTE2(v32) = v28;
                    sub_EF629(v32, v33, v34, v35, v36, v27);
                  }
                }
              }
              sub_8A4C4();
              JUMPOUT(0xEA8C3);
            }
            v25 = *(_WORD *)(v1 - 28);
            v1 -= 129;
            if ( v25 != word_19999A )
              break;
            v26 = *(char *)(v1 + 99);
            if ( (char)v38[v26] == -1 )
            {
              v2 = word_19999A;
              v38[v26] = 72;
              v3 = 0;
              a1 = 113 * v2;
              while ( v2 > 0 )
              {
                a1 -= 113;
                --v2;
                if ( (((int)*(uint8_t *)(a1 + dword_19306C + 64) >> *(_BYTE *)(v1 + 99)) & 1) != 0
                  && sub_1247A0(++v3) == 1 )
                {
                  v38[*(char *)(v1 + 99)] = v2;
                }
              }
            }
            v4 = *(char *)(v1 + 99);
            if ( v38[v4] == 72 )
            {
              v7 = *(int16_t *)(v1 + 116);
              if ( v7 != -1 )
              {
                v8 = dword_1930DC + 59 * v7;
                if ( *(char *)(v8 + 55) <= 0 )
                {
                  *(_WORD *)(v8 + 53) = -1;
                  *(_WORD *)(v1 + 116) = -1;
                  sub_941C6(v7, a1);
                  v9 = 288 * *(char *)(v1 + 99) + 4 * word_19999A;
                  ++v30[v9 + 3];
                }
                else
                {
                  sub_944A3(v7, a1);
                }
              }
              v10 = 4 * word_19999A;
              v11 = v10 + 288 * *(char *)(v1 + 99);
              ++*(_WORD *)&v30[v11 + 1];
              v30[288 * *(char *)(v1 + 99) + v10] = 0;
LABEL_13:
              sub_A163A((int)(v1 - dword_197F9C) / 129, a1);
            }
            else
            {
              *(_WORD *)(v1 + 101) = (char)v38[v4];
              v5 = dword_19306C;
              *(_WORD *)(v1 + 103) = *(_WORD *)(dword_19306C + 113 * (char)v38[*(char *)(v1 + 99)] + 15);
              v6 = *(_WORD *)(v5 + 113 * (char)v38[*(char *)(v1 + 99)] + 17);
              *(_BYTE *)(v1 + 100) = 0;
              *(_WORD *)(v1 + 105) = v6;
            }
          }
          if ( *(_BYTE *)(v1 + 100) != 9 )
            break;
          v40 = v25;
          v39 = *(char *)(v1 + 99);
          v43 = -1;
          v45 = 0;
          a1 = 1;
          v46 = 0;
          v12 = v1;
          v31[0] = (int)(v1 - dword_197F9C) / 129;
          v13 = 1;
          *(_BYTE *)(v1 + 127) = 0;
          while ( v12 > dword_197F9C )
          {
            v12 -= 129;
            if ( *(_BYTE *)(v12 + 100) == 9 && *(int16_t *)(v12 + 101) == v40 && *(char *)(v12 + 99) == v39 )
            {
              v44 = 129;
              *(_WORD *)&v30[++v13 * 2 + 2302] = (int)(v12 - dword_197F9C) / 129;
              ++a1;
              *(_BYTE *)(v12 + 127) = 0;
            }
          }
          v42 = (int16_t)sub_E6BCD(v40, v1);
          if ( v42 == -1 || v46 == 2 )
          {
            v45 = 1;
LABEL_27:
            v43 = 2;
            goto LABEL_28;
          }
          v14 = v42;
          v31[v13] = -1;
          sub_FF799(v31, v14, v37);
          if ( !v37[5] )
          {
            v45 = 1;
            if ( !v37[13] )
              goto LABEL_27;
            v43 = 1;
          }
LABEL_28:
          if ( v45 )
          {
            v15 = 2 * a1;
            while ( v15 > 0 )
            {
              a1 = *(int16_t *)&v30[v15 + 2302];
              v18 = *(int16_t *)(129 * a1 + dword_197F9C + 116);
              v15 -= 2;
              if ( v18 != -1 )
              {
                if ( *(char *)(dword_1930DC + 59 * v18 + 55) <= 0 )
                {
                  sub_941C6(v18, a1);
                  v16 = 288 * *(char *)(v1 + 99) + 4 * *(int16_t *)(v1 + 101);
                  ++v30[v16 + 3];
                }
                else
                {
                  sub_944A3(v18, a1);
                }
              }
              v17 = 288 * *(char *)(v1 + 99) + 4 * *(int16_t *)(v1 + 101);
              ++*(_WORD *)&v30[v17 + 1];
              v30[288 * *(char *)(v1 + 99) + 4 * *(int16_t *)(v1 + 101)] = v43;
              sub_A163A(a1, a1);
            }
          }
          else
          {
            v19 = v42;
            v31[a1] = -1;
            sub_FFD08(v31, v19, v37);
            for ( i = 2 * a1; i > 0; i -= 2 )
            {
              v21 = 129 * *(int16_t *)&v30[i + 2302];
              v22 = dword_197F9C;
              *(_BYTE *)(dword_197F9C + v21 + 100) = 1;
              *(_WORD *)(v22 + v21 + 101) -= 500;
            }
          }
        }
        if ( *(_BYTE *)(v1 + 99) == 8 && !*(_BYTE *)(v1 + 100) )
        {
          sub_6485F(*(uint8_t *)(v1 + 16));
          goto LABEL_13;
        }
      }
      while ( *(char *)(v1 + 99) < 8 || *(_BYTE *)(v1 + 100) || !*(_BYTE *)(v1 + 20) );
      v23 = *(_BYTE *)(v1 + 99);
      if ( v23 >= 0xBu )
        break;
      v24 = v23 == 10;
LABEL_50:
      if ( v24 )
      {
        sub_A163A((int)(v1 - dword_197F9C) / 129, a1);
        sub_F9711(*(char *)(v1 + 99), -1, -1);
      }
    }
    if ( v23 <= 0xCu || v23 == 14 )
    {
      v24 = sub_1247A0(2u) == 1;
      goto LABEL_50;
    }
  }
}
// E72FE: control flows out of bounds to EA8C3
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E7303) --------------------------------------------------------
char __fastcall sub_E7303(int a1, int a2)
{
  int v3; // ebx
  int v4; // eax

  v3 = word_199996;
  v4 = 361 * word_199996;
  do
  {
    if ( v4 <= 0 )
      return 0;
    v4 -= 361;
    --v3;
  }
  while ( *(char *)(dword_192B18 + v4) != a1 || v4 == 361 * a2 );
  return 1;
}
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (000E7343) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=225)) - nutno dohledat rucne v IDA @ 0xE7651 */
_DWORD __stdcall sub_E7343(_DWORD _p0, int _p1, _DWORD _p2, int _p3, int _p4, _DWORD _p5)
{
  DECOMP_TODO("call analysis failed (funcsize=225)");
}


//----- (000E7678) --------------------------------------------------------
int __fastcall sub_E7678( int a1, int a2)
{
  _BYTE v4[3]; // [esp+0h] [ebp-50h] BYREF
  int16_t v5; // [esp+3h] [ebp-4Dh]
  int16_t v6; // [esp+6h] [ebp-4Ah]
  int16_t v7; // [esp+4Ch] [ebp-4h]

  v7 = a2;
  memset(v4, 0, 73);
  v4[1] = v7;
  v4[0] = a1;
  sub_4267B((int)v4);
  return v5 + v6;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (000E76B2) --------------------------------------------------------
int16_t __fastcall sub_E76B2(int a1, unsigned int *a2, int a3, int a4, int a5)
{
  unsigned int v5; // eax
  _BYTE *v6; // ebx
  int16_t v7; // cx
  int v8; // eax
  uint16_t v9; // ax
  int16_t i; // di
  uint16_t v11; // ax
  int v12; // ecx
  _DWORD *v13; // ecx
  unsigned int *v14; // ebx
  unsigned int v15; // ecx
  int v17; // [esp+0h] [ebp-24h]
  _WORD v18[4]; // [esp+4h] [ebp-20h] BYREF
  int v19; // [esp+Ch] [ebp-18h]
  int v20; // [esp+10h] [ebp-14h]
  int v21; // [esp+14h] [ebp-10h]
  unsigned int v22; // [esp+18h] [ebp-Ch]
  int v23; // [esp+1Ch] [ebp-8h]
  int v24; // [esp+20h] [ebp-4h]

  v20 = a3;
  v24 = a4;
  memset(a1, 0, 60);
  memset(a2, 0, 60);
  memset(a3, 0, 16);
  v5 = 129 * word_199994;
  v22 = 0;
  v6 = (_BYTE *)(v5 + dword_197F9C);
  while ( (unsigned int)v6 > dword_197F9C )
  {
    LOWORD(v5) = *((_WORD *)v6 - 14);
    v6 -= 129;
    if ( (_WORD)v5 == (_WORD)v24 && !v6[100] )
    {
      if ( (char)v6[99] == a5 )
      {
        v7 = word_199998;
        v22 += 1 << v6[16];
        while ( v7 > 0 )
        {
          if ( --v7 != a5 )
          {
            v8 = 11 * v7 + dword_1AA3B0 + 88 * (int16_t)v24;
            if ( *(_BYTE *)(v8 + 6) || *(_BYTE *)(v8 + 7) )
            {
              v23 = 129;
              sub_5EF17((int)&v6[-dword_197F9C] / 129, v7);
              a2[v7] += v9;
            }
          }
        }
        for ( i = 8; ; ++i )
        {
          v21 = (int)&v6[-dword_197F9C] / 129;
          if ( i >= 15 )
            break;
          v19 = (int16_t)v24;
          if ( (((int)*(uint8_t *)((int16_t)v24 + dword_1AA3B4) >> (i - 8)) & 1) != 0 )
          {
            v23 = 2 * v19;
            if ( (((int)*(uint16_t *)(2 * v19 + dword_1AA3AC) >> i) & 1) == 0 )
            {
              sub_5EF17(v21, i);
              a2[i] += v11;
            }
          }
        }
        v12 = 4;
        sub_5F379((int16_t)v21, (int)v18);
        do
        {
          v5 = v20 + 4 * (int16_t)--v12;
          *(_DWORD *)v5 += (uint16_t)v18[(int16_t)v12];
        }
        while ( (int16_t)v12 > 0 );
      }
      else
      {
        v23 = 129;
        v13 = (_DWORD *)(v17 + 4 * (char)v6[99]);
        sub_5EF17((int)&v6[-dword_197F9C] / 129, a5);
        *v13 += (uint16_t)v5;
      }
    }
  }
  if ( v22 > 0x96 )
  {
    v14 = a2 + 15;
    do
    {
      v15 = *--v14;
      v5 = v22 * (*v14 / 0x96);
      *v14 = v5;
      if ( v15 > v5 )
        *v14 = v15;
    }
    while ( v14 != a2 );
  }
  return v5;
}
// E7799: variable 'v9' is possibly undefined
// E77F0: variable 'v11' is possibly undefined
// E785C: variable 'v17' is possibly undefined
// E7864: variable 'v5' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199998: using guessed type int16_t word_199998;
// 1AA3AC: using guessed type int dword_1AA3AC;
// 1AA3B0: using guessed type int dword_1AA3B0;
// 1AA3B4: using guessed type int dword_1AA3B4;


//----- (000E78A7) --------------------------------------------------------
void __fastcall sub_E78A7(int a1, int a2, int a3, int a4, int a5, unsigned int *a6, int16_t *a7, int a8)
{
  _BYTE *v8; // ebx
  int16_t v9; // ax
  unsigned int v10; // ecx
  int v11; // esi
  unsigned int v12; // ebx
  unsigned int v13; // esi
  _BOOL1 v14; // dl
  int v15; // edx
  int v16; // eax
  int v17; // eax
  unsigned int v18; // eax
  unsigned int v21; // [esp+Ch] [ebp-38h]
  int v23; // [esp+1Ch] [ebp-28h]
  int v24; // [esp+24h] [ebp-20h]
  unsigned int v25; // [esp+28h] [ebp-1Ch]
  int v26; // [esp+2Ch] [ebp-18h]
  int16_t v27; // [esp+30h] [ebp-14h]
  int16_t v29; // [esp+38h] [ebp-Ch]
  _BOOL1 v30; // [esp+3Ch] [ebp-8h]
  char v31; // [esp+40h] [ebp-4h]

  *a6 = 0;
  *a7 = -1;
  v25 = 0;
  v24 = -1;
  v29 = word_1AA38A;
  while ( v29 > 0 )
  {
    v27 = word_1AA380[--v29];
    v8 = (_BYTE *)(dword_192B18 + 361 * v27);
    v9 = sub_E5AE7(v8);
    v26 = (char)*v8;
    v10 = *(_DWORD *)(a2 + 4 * v26);
    v11 = *(_DWORD *)(a1 + 4 * v26);
    v12 = *(_DWORD *)(a3 + 4 * v9);
    v23 = (uint16_t)sub_5F804(v27);
    v13 = v23 + v11;
    v21 = (uint16_t)sub_5F747(v27, a5);
    v31 = 0;
    v14 = *(_BYTE *)(dword_197F98 + 3753 * a5 + 2232) && !*(_BYTE *)(dword_197F98 + 3753 * v26 + 2232);
    v30 = v14;
    if ( (v10
       || v12
       || *(_BYTE *)(11 * a5 + 88 * a4 + dword_1AA3B0 + 5)
       || v14
       || *(_BYTE *)(dword_192B18 + 361 * v27 + 6))
      && v13 < v10
      && v12 > v21 )
    {
      v15 = dword_1AA3B0 + 88 * a4;
      if ( *(_BYTE *)(v15 + 11 * v26 + 7) < 2u || v12 || *(_BYTE *)(v15 + 11 * a5 + 5) || v30 || v23 )
      {
        v16 = dword_192B18 + 361 * v27;
        if ( *(_BYTE *)(v16 + 10) != 1
          || (*(_DWORD *)(v16 + 12) & 0xF) != a5
          || *(_BYTE *)(dword_1AA3B0 + 88 * a4 + 11 * a5 + 2)
          || *(_BYTE *)(3753 * a5 + dword_197F98 + 39) == 1 )
        {
          v31 = 1;
        }
      }
    }
    if ( v31 )
    {
      sub_D8D11();
      if ( 3 * v13 >= v10 )
      {
        if ( !v10 )
        {
          v10 = 1;
          v13 = 1;
        }
      }
      else
      {
        v10 = 3;
        v13 = 1;
      }
      if ( 3 * v21 >= v12 )
      {
        if ( !v12 )
        {
          v12 = 1;
          v21 = 1;
        }
      }
      else
      {
        v12 = 3;
        v21 = 1;
      }
      if ( v13 >= (unsigned int)sub_10000 )
      {
        v10 >>= 8;
        v13 >>= 8;
      }
      if ( v21 >= (unsigned int)sub_10000 )
      {
        v21 >>= 8;
        v12 >>= 8;
      }
      v18 = v12 * (v10 * v17 / v13) / v21;
      if ( v18 > *a6 )
      {
        *a6 = v18;
        *a7 = v27;
      }
      if ( v26 == a8 && v18 > v25 )
      {
        v25 = v18;
        v24 = v27;
      }
    }
  }
  if ( a8 != -1 && v24 != -1 )
  {
    *a6 = v25;
    *a7 = v24;
  }
  JUMPOUT(0xE6A9C);
}
// E7B74: control flows out of bounds to E6A9C
// E7B12: variable 'v17' is possibly undefined
// 10000: using guessed type void __noreturn sub_10000();
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 1AA380: using guessed type int16_t word_1AA380[5];
// 1AA38A: using guessed type int16_t word_1AA38A;
// 1AA3B0: using guessed type int dword_1AA3B0;


//----- (000E7B79) --------------------------------------------------------
void __fastcall sub_E7B79(int a1, int a2)
{
  int64_t v4; // rax
  int v5; // edx
  int v6; // ecx
  uint8_t v7; // al
  int64_t v8; // rax
  int64_t v9; // rax
  int64_t v10; // rax
  int64_t v11; // rax
  char v12; // al
  _BYTE v13[400]; // [esp+0h] [ebp-19Ch] BYREF
  int v14; // [esp+190h] [ebp-Ch]
  int v15; // [esp+194h] [ebp-8h]
  char v16; // [esp+198h] [ebp-4h]

  v16 = 1;
  if ( a2 < 8 && !*(_BYTE *)(8 * a1 + dword_1AA378 + a2) )
  {
    v4 = sprintf(v13, (char *)&off_17A034, dword_1AA3CC);
    v5 = v4 + HIDWORD(v4);
    v15 = 3753 * a1;
    v6 = 0;
    v7 = *(_BYTE *)(a2 + 3753 * a1 + dword_197F98 + 1575);
    if ( v7 && v7 <= 3u )
    {
      v6 = 1;
      v8 = sprintf(v5, (char *)&off_17A034, dword_199150[(char)v7]);
      v5 = v8 + HIDWORD(v8);
    }
    if ( *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1583) )
    {
      ++v6;
      v9 = sprintf(v5, (char *)&off_17A034, dword_1AA3C8);
      v5 = v9 + HIDWORD(v9);
    }
    if ( *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1591) )
    {
      ++v6;
      v10 = sprintf(v5, (char *)&off_17A034, dword_1AA3C0);
      v5 = v10 + HIDWORD(v10);
    }
    v14 = 3753 * a2 + dword_197F98;
    if ( *(_WORD *)(v14 + 2 * a1 + 1599) )
    {
      ++v6;
      v11 = sprintf(v5, (char *)&off_17A034, dword_1AA3D4);
      v5 = v11 + HIDWORD(v11);
    }
    if ( v6 )
    {
      sprintf(v5, (char *)dword_1AA3D0);
      sub_77658((int)v13);
      v16 = v12;
      if ( v12 )
        *(_BYTE *)(a2 + 8 * a1 + dword_1AA378) = 1;
    }
  }
  JUMPOUT(0xE6CA4);
}
// E7CD6: control flows out of bounds to E6CA4
// E7CBE: variable 'v12' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17A034: using guessed type _UNKNOWN *off_17A034;
// 197F98: using guessed type int dword_197F98;
// 199150: using guessed type int dword_199150[];
// 1AA378: using guessed type int dword_1AA378;
// 1AA3C0: using guessed type int dword_1AA3C0;
// 1AA3C8: using guessed type int dword_1AA3C8;
// 1AA3CC: using guessed type int dword_1AA3CC;
// 1AA3D0: using guessed type int dword_1AA3D0;
// 1AA3D4: using guessed type int dword_1AA3D4;


//----- (000E7CDB) --------------------------------------------------------
void __fastcall sub_E7CDB(int16_t *a1, int a2, _WORD *a3, _WORD *a4)
{
  void *v6; // eax
  int v7; // ecx
  int16_t v8; // ax
  int16_t v9; // ax
  char v10; // al

  *a4 = -1;
  *a3 = -1;
  if ( (_WORD)a1 == word_19999A )
  {
    *a3 = 8;
  }
  else if ( word_1AA38A[0] > 0 || word_1AA3AA > 0 )
  {
    sub_124D41();
    sub_84E9D();
    v6 = sub_124DEC();
    sub_1077D((int)v6, a2, (int)a3, a1);
    sub_84E9D();
    byte_1AB124[a2] = 1;
    *(_BYTE *)(dword_19306C + 113 * (int16_t)a1 + 51) |= 1 << a2;
    word_19999C = a2;
    sub_8A4C4();
    do
    {
      v7 = -1;
      *a4 = -1;
      *a3 = -1;
      v8 = sub_C9676((int16_t)a1, a2);
      if ( v8 != -1 )
      {
        byte_183578 = 1;
        if ( v8 < 15 )
        {
          v7 = v8;
          *a3 = v8;
        }
        else
        {
          v9 = v8 - 15;
          *a4 = v9;
          v7 = *(char *)(dword_192B18 + 361 * v9);
        }
      }
      if ( v7 == -1 )
        break;
      sub_E7B79(a2, v7);
    }
    while ( !v10 );
  }
}
// E7DC4: variable 'v10' is possibly undefined
// 183578: using guessed type char byte_183578;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1AA38A: using guessed type int16_t word_1AA38A[];
// 1AA3AA: using guessed type int16_t word_1AA3AA;


//----- (000E7DCA) --------------------------------------------------------
unsigned int __fastcall sub_E7DCA(int a1, int a2, _WORD *a3, _WORD *a4, _BYTE *a5)
{
  unsigned int result; // eax
  int v7; // eax
  int v8; // edx
  int v9; // edx
  int v10; // eax
  int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // ebx
  uint8_t v14; // al
  unsigned int v15; // eax
  int16_t v16; // ax
  int16_t v17; // [esp+0h] [ebp-42h]
  unsigned int v18; // [esp+4h] [ebp-3Eh]
  _DWORD v19[15]; // [esp+8h] [ebp-3Ah] BYREF
  unsigned int v20[15]; // [esp+44h] [ebp+2h] BYREF
  _BYTE v21[16]; // [esp+80h] [ebp+3Eh] BYREF
  int v22; // [esp+90h] [ebp+4Eh]
  unsigned int v23; // [esp+94h] [ebp+52h]
  int v24; // [esp+98h] [ebp+56h]
  int v25; // [esp+9Ch] [ebp+5Ah]
  unsigned int v26; // [esp+A0h] [ebp+5Eh] BYREF
  int v27; // [esp+A4h] [ebp+62h]
  int v28; // [esp+A8h] [ebp+66h]
  int v29; // [esp+ACh] [ebp+6Ah] BYREF
  int v30; // [esp+B0h] [ebp+6Eh]
  int v31; // [esp+B4h] [ebp+72h]
  int v32; // [esp+B8h] [ebp+76h]
  char v33; // [esp+BCh] [ebp+7Ah]

  *a5 = 0;
  *a4 = -1;
  result = v18;
  *a3 = -1;
  if ( (_WORD)v18 == word_19999A )
  {
    *a3 = 8;
    return result;
  }
  if ( word_1AA38A > 0 || word_1AA3AA > 0 )
  {
    v7 = 3753 * v17 + dword_197F98;
    v8 = *(int16_t *)(v7 + 1991);
    v28 = -1;
    if ( v8 != -1 && *(uint8_t *)(dword_1930D4 + 17 * v8 + 2) == (_WORD)v18 )
    {
      *(_WORD *)(v7 + 1991) = -1;
      v9 = *(char *)(v7 + 1994);
      *(_BYTE *)(v7 + 2070) = 0;
      v28 = v9;
      *(_BYTE *)(v7 + 1994) = -1;
    }
    v24 = v17;
    v23 = 0;
    v25 = (int16_t)v18;
    v32 = -1;
    sub_E76B2((int)v19, v20, (int)v21, (int16_t)v18, v17);
    v26 = 0;
    v29 = -1;
    sub_E78A7((int)v19, (int)v20, (int)v21, v25, v24, &v26, (int16_t *)&v29, v28);
    if ( v28 == -1 || (v10 = (int16_t)v29, (int16_t)v29 == -1) )
    {
      LOWORD(v10) = word_1AA3AA;
      v31 = v10;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( (int16_t)v31 <= 0 )
            goto LABEL_31;
          v11 = (int16_t)--v31;
          LOWORD(v11) = word_1AA38C[(int16_t)v31];
          v12 = v20[(int16_t)v11];
          v13 = v19[(int16_t)v11];
          v30 = v11;
          if ( v13 <= v12 )
          {
            if ( (v33 = 0, v13 < v12)
              || (v22 = 113 * (int16_t)v18,
                  v27 = dword_19306C + v22,
                  (((int)*(uint8_t *)(dword_19306C + v22 + 56) >> v17) & 1) != 0)
              && (((int)*(uint8_t *)(v27 + v17 + 43) >> v30) & 1) != 0
              || (int16_t)v30 == v28
              || (v14 = *(_BYTE *)(dword_197F98 + 3753 * v17 + 39), v14 <= 1u) )
            {
              v33 = 1;
            }
            else if ( v14 <= 3u )
            {
              v33 = sub_1247A0(2u) - 1;
            }
            if ( v33 )
              break;
          }
        }
        if ( 3 * v13 >= v12 )
        {
          if ( v12 )
            goto LABEL_25;
        }
        else
        {
          v12 = 3;
        }
        v13 = 1;
LABEL_25:
        if ( (int16_t)v30 == v28 )
          v15 = -1;
        else
          v15 = 16 * v12 / v13;
        if ( v15 > v23 )
        {
          v23 = v15;
          v32 = v30;
        }
      }
    }
LABEL_31:
    result = v26;
    if ( v26 < v23 )
    {
      LOWORD(result) = v32;
      *a3 = v32;
      result = (int16_t)result;
      if ( (int16_t)result != v28 )
        return result;
      goto LABEL_36;
    }
    if ( v26 )
    {
      v16 = v29;
      *a4 = v29;
      result = *(char *)(361 * v16 + dword_192B18);
      if ( result == v28 )
      {
LABEL_36:
        result = (unsigned int)a5;
        *a5 = 1;
      }
    }
  }
  return result;
}
// E7DE7: variable 'v18' is possibly undefined
// E7E1A: variable 'v17' is possibly undefined
// E7EE7: variable 'v10' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;
// 1AA38A: using guessed type int16_t word_1AA38A;
// 1AA38C: using guessed type int16_t word_1AA38C[15];
// 1AA3AA: using guessed type int16_t word_1AA3AA;


//----- (000E8029) --------------------------------------------------------
int __fastcall sub_E8029(int result, int a2, _WORD *a3, _WORD *a4)
{
  int v4; // edx
  int v5; // esi
  int j; // ebx
  int v7; // esi
  int i; // ecx
  int v9; // edx
  int v10; // [esp+4h] [ebp-20h]
  int v11; // [esp+8h] [ebp-1Ch]
  int v12; // [esp+Ch] [ebp-18h]
  int v13; // [esp+10h] [ebp-14h]
  int v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+18h] [ebp-Ch]
  int v16; // [esp+1Ch] [ebp-8h]
  int v17; // [esp+20h] [ebp-4h]

  *a4 = -1;
  *a3 = -1;
  if ( a2 != 13 )
  {
    if ( (_WORD)result == word_19999A )
    {
      *a3 = 8;
    }
    else if ( word_1AA38A[0] <= 0 )
    {
      if ( word_1AA3AA > 0 )
      {
        v11 = -1;
        v17 = -1;
        v7 = 0;
        v14 = 0;
        v15 = word_1AA3AA;
        for ( i = word_1AA3AA; i > 0; --i )
        {
          --v15;
          v9 = word_1AA38A[i];
          if ( v9 >= 8 || *(_BYTE *)(3753 * v9 + dword_197F98 + 2233) )
          {
            if ( sub_1247A0(++v7) == 1 )
              v11 = v9;
          }
          else if ( sub_1247A0(++v14) == 1 )
          {
            v17 = v9;
          }
        }
        if ( v17 == -1 )
          result = v11;
        else
          result = v17;
        *a3 = result;
      }
    }
    else
    {
      v10 = -1;
      v13 = -1;
      v4 = 0;
      v5 = 0;
      v16 = word_1AA38A[0];
      for ( j = 2 * word_1AA38A[0]; j > 0; j -= 2 )
      {
        v12 = *(int16_t *)((char *)&dword_1AA37C + j + 2);
        --v16;
        if ( *(_BYTE *)(dword_197F98 + 3753 * *(char *)(361 * v12 + dword_192B18) + 2233) )
        {
          if ( sub_1247A0(++v4) == 1 )
            v10 = v12;
        }
        else if ( sub_1247A0(++v5) == 1 )
        {
          v13 = v12;
        }
      }
      if ( v13 == -1 )
        result = v10;
      else
        result = v13;
      *a4 = result;
    }
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;
// 1AA37C: using guessed type int dword_1AA37C;
// 1AA38A: using guessed type int16_t word_1AA38A[];
// 1AA3AA: using guessed type int16_t word_1AA3AA;


//----- (000E8194) --------------------------------------------------------
void __fastcall sub_E8194( int a1)
{
  _WORD *v2; // eax
  int v3; // edx
  int j; // ebx
  int i; // ebx

  v2 = (_WORD *)(2 * a1 + dword_1AA3AC);
  if ( *v2 )
  {
    v3 = 0;
    if ( *v2 < 0x100u )
    {
      for ( i = 0; i < word_199998; ++i )
      {
        if ( (((int)*(uint16_t *)(dword_1AA3AC + 2 * a1) >> i) & 1) != 0 )
          sub_1247A0(++v3);
      }
    }
    else
    {
      for ( j = 8; j < 15; ++j )
      {
        if ( (((int)*(uint16_t *)(dword_1AA3AC + 2 * a1) >> j) & 1) != 0 )
          sub_1247A0(++v3);
      }
    }
  }
  JUMPOUT(0xEA8C4);
}
// E822C: control flows out of bounds to EA8C4
// 199998: using guessed type int16_t word_199998;
// 1AA3AC: using guessed type int dword_1AA3AC;


//----- (000E8231) --------------------------------------------------------
_BOOL1 __fastcall sub_E8231(int a1, int a2)
{
  char v3; // bl
  int v4; // edx
  _BYTE *v5; // eax
  uint8_t v6; // bh
  char v8; // al

  v3 = 0;
  if ( a1 == a2 )
    return v3;
  if ( a1 >= 8 )
    return 1;
  v4 = 3753 * a1 + dword_197F98;
  if ( *(_BYTE *)(v4 + 40) == 100 )
    return 1;
  v5 = (_BYTE *)(v4 + a2);
  v6 = *(_BYTE *)(v4 + a2 + 1575);
  if ( !v6 )
  {
    if ( v5[2062] )
      return v3;
    if ( v5[1583] )
      return v3;
    if ( v5[1591] )
      return v3;
    v8 = *(_BYTE *)(v4 + 39);
    if ( v8 )
    {
      if ( v8 != 3 || sub_1247A0(0xAu) != 1 )
        return v3;
    }
    return 1;
  }
  if ( v6 >= 4u )
    return v6 <= 6u;
  return v3;
}
// 197F98: using guessed type int dword_197F98;


//----- (000E82B4) --------------------------------------------------------
void __fastcall sub_E82B4( int a1, int a2)
{
  int16_t v3; // bx
  int16_t v4; // ax
  int16_t v5; // cx
  int16_t v6; // bx
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int16_t v10; // [esp+8h] [ebp-4h]

  word_1AA38A[0] = 0;
  if ( a1 < word_19999A )
  {
    v3 = 5;
    do
    {
      v4 = *(_WORD *)(113 * a1 + dword_19306C + 2 * --v3 + 74);
      if ( v4 >= 0 )
      {
        v5 = *(_WORD *)(dword_1930D4 + 17 * v4);
        if ( v5 >= 0 && sub_E8231(a2, *(char *)(dword_192B18 + 361 * v5)) )
          word_1AA380[word_1AA38A[0]++] = v5;
      }
    }
    while ( v3 > 0 );
  }
  word_1AA3AA = 0;
  v6 = word_199998;
  while ( v6 > 0 )
  {
    if ( --v6 != a2 )
    {
      v7 = 88 * a1 + dword_1AA3B0 + 11 * v6;
      if ( *(_BYTE *)(v7 + 6) )
      {
        if ( !*(_BYTE *)(v7 + 7) && sub_E8231(a2, v6) )
          word_1AA38C[word_1AA3AA++] = v6;
      }
    }
  }
  if ( *(_BYTE *)(a1 + dword_1AA3B4) )
  {
    v8 = 7;
    v9 = 15;
    v10 = 15;
    do
    {
      --v10;
      --v9;
      --v8;
      if ( a2 != v9 && (((int)*(uint8_t *)(dword_1AA3B4 + a1) >> v8) & 1) != 0 )
        word_1AA38C[word_1AA3AA++] = v10;
    }
    while ( v8 > 0 );
  }
  JUMPOUT(0xE6CA4);
}
// E8415: control flows out of bounds to E6CA4
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 1AA380: using guessed type int16_t word_1AA380[5];
// 1AA38A: using guessed type int16_t word_1AA38A[];
// 1AA38C: using guessed type int16_t word_1AA38C[15];
// 1AA3AA: using guessed type int16_t word_1AA3AA;
// 1AA3B0: using guessed type int dword_1AA3B0;
// 1AA3B4: using guessed type int dword_1AA3B4;


//----- (000E841A) --------------------------------------------------------
char __fastcall sub_E841A( int a1)
{
  int16_t v2; // dx
  int v3; // eax

  v2 = word_199998;
  while ( v2 > 0 )
  {
    if ( *(_BYTE *)(dword_197F98 + 3753 * --v2 + 40) == 100 )
    {
      v3 = dword_1AA3B0 + 88 * a1 + 11 * v2;
      if ( (*(_BYTE *)(v3 + 7) || *(_BYTE *)(v3 + 6))
        && (byte_1AAF94[12 * v2] != -1
         || v2 == word_19999C
         && ((uint8_t)byte_1AB03F >= 0x21u && (uint8_t)byte_1AB03F <= 0x22u || dword_1AAF72)) )
      {
        return 1;
      }
    }
  }
  return 0;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 1AA3B0: using guessed type int dword_1AA3B0;
// 1AAF72: using guessed type int dword_1AAF72;
// 1AB03F: using guessed type char byte_1AB03F;


//----- (000E84A5) --------------------------------------------------------
void __usercall sub_E84A5(int16_t *a1, int16_t *a2, int a3)
{
  int v5; // edi
  int16_t v6; // ax
  int v7; // eax
  int v8; // edx
  _BYTE *v9; // edx
  _BYTE *v10; // eax

  LOWORD(a3) = word_1AA3E8;
  *a1 = -1;
  v5 = a3 - 1;
  while ( *a1 == -1 && (v5 & 0x8000u) == 0 )
  {
    sub_FE8BE();
    *a1 = *(uint8_t *)((int16_t)v5 + dword_1AA37C);
    if ( (byte_199F3A == 2 || byte_199F3A == 3) && sub_E841A(*a1) )
    {
      --v5;
      *a1 = -1;
    }
    else
    {
      do
      {
        sub_E8194(*a1);
        *a2 = v6;
        if ( v6 == -1 )
        {
          --word_1AA3E8;
          v7 = dword_1AA37C;
          v8 = word_1AA3E8;
          *a1 = -1;
          v9 = (_BYTE *)(v7 + v8);
          v10 = (_BYTE *)((int16_t)v5-- + v7);
          *v10 = *v9;
        }
        else
        {
          *(_WORD *)(dword_1AA3AC + 2 * *a1) &= ~(uint16_t)(1 << *(_BYTE *)a2);
          sub_E82B4(*a1, *a2);
          if ( !word_1AA3AA && !word_1AA38A[0] )
            *a2 = -1;
        }
      }
      while ( *a2 == -1 && *a1 != -1 );
    }
  }
  JUMPOUT(0xE6CA5);
}
// E84C0: control flows out of bounds to E6CA5
// E8512: variable 'v6' is possibly undefined
// FE8BE: using guessed type int sub_FE8BE(void);
// 199F3A: using guessed type char byte_199F3A;
// 1AA37C: using guessed type int dword_1AA37C;
// 1AA38A: using guessed type int16_t word_1AA38A[];
// 1AA3AA: using guessed type int16_t word_1AA3AA;
// 1AA3AC: using guessed type int dword_1AA3AC;
// 1AA3E8: using guessed type int16_t word_1AA3E8;


//----- (000E859D) --------------------------------------------------------
int __fastcall sub_E859D(int a1)
{
  sub_147D7(51);
  sub_8A4C4();
  sub_3FDAA(a1 + 641, a1 + 741);
  if ( *(_WORD *)(a1 + 639) )
  {
    sub_C6650();
    sub_98282(word_19999C, a1 + 631, *(_WORD *)(a1 + 639));
  }
  return sub_F3E42(0);
}
// 19999C: using guessed type int16_t word_19999C;


//----- (000E85F7) --------------------------------------------------------
void __fastcall sub_E85F7(int a1)
{
  int v2; // edi

  if ( *(_BYTE *)(a1 + 12) )
  {
    sub_77423(dword_1AA3D8);
  }
  else if ( *(_BYTE *)(a1 + 630) )
  {
    sub_C6513();
    byte_183578 = 1;
  }
  else if ( *(_BYTE *)(a1 + 80) )
  {
    if ( *(_BYTE *)(a1 + 15) == 10 )
      sub_C64AB();
    sub_B4D02((_BYTE *)(a1 + 15));
  }
  if ( *(_WORD *)(a1 + 100) )
  {
    v2 = sub_12484C();
    sub_B7491(a1 + 88, a1 + 143, *(_DWORD *)(a1 + 198), *(_WORD *)(dword_1930D4 + 17 * *(int16_t *)(a1 + 4)));
    sub_F3E42(1);
    sub_124820(v2);
  }
  if ( *(_BYTE *)(a1 + 1741) )
    sub_77423(dword_1AA3B8);
  JUMPOUT(0xEA8C4);
}
// E869B: control flows out of bounds to EA8C4
// 183578: using guessed type char byte_183578;
// 1930D4: using guessed type int dword_1930D4;
// 1AA3B8: using guessed type int dword_1AA3B8;
// 1AA3D8: using guessed type int dword_1AA3D8;


//----- (000E86A0) --------------------------------------------------------
char __fastcall sub_E86A0(int a1, int a2)
{
  int v2; // ecx
  int16_t *v3; // ebx
  int v5; // esi
  int16_t v6; // ax

  v2 = a2;
  v3 = (int16_t *)(2 * a2 + a1);
  while ( 1 )
  {
    if ( v2 <= 0 )
      return 0;
    v5 = *--v3;
    --v2;
    if ( !*(_BYTE *)(129 * v5 + dword_197F9C + 100) )
    {
      sub_58270(v5, 38);
      if ( v6 )
        break;
    }
  }
  return 1;
}
// E86DF: variable 'v6' is possibly undefined
// 197F9C: using guessed type int dword_197F9C;


//----- (000E86E7) --------------------------------------------------------
void __fastcall sub_E86E7( int a1, int a2)
{
  int v4; // esi
  unsigned int v5; // ebx
  int v6; // edx

  v4 = 0;
  v5 = dword_19306C + 113 * word_19999A;
  while ( v5 > dword_19306C )
  {
    v6 = (int)*(uint8_t *)(v5 - 57) >> a2;
    v5 -= 113;
    if ( (v6 & 1) != 0 )
    {
      if ( sub_FF666(v5, a1) )
        ++v4;
    }
  }
  JUMPOUT(0xE6CA4);
}
// E8734: control flows out of bounds to E6CA4
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E8739) --------------------------------------------------------
int __fastcall sub_E8739( int a1)
{
  int v2; // edx
  unsigned int i; // eax
  int v4; // esi

  v2 = 0;
  for ( i = 113 * word_19999A + dword_19306C; i > dword_19306C; i -= 113 )
  {
    v4 = (int)*(uint8_t *)(i - 57) >> a1;
    if ( (v4 & 1) != 0 )
      ++v2;
  }
  return v2;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E8776) --------------------------------------------------------
char __fastcall sub_E8776(int a1)
{
  unsigned int v2; // eax
  int v4; // ebx

  v2 = dword_197F9C + 129 * word_199994;
  do
  {
    if ( v2 <= dword_197F9C )
      return 0;
    v4 = *(char *)(v2 - 30);
    v2 -= 129;
  }
  while ( v4 != a1 || *(_BYTE *)(v2 + 17) != 2 || *(char *)(v2 + 100) >= 5 );
  return 1;
}
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000E87D2) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (function frame is wrong (funcsize=0)) - nutno dohledat rucne v IDA @ 0xE87D2 */
int __fastcall sub_E87D2(_DWORD _p0, _DWORD _p1)
{
  DECOMP_TODO("function frame is wrong (funcsize=0)");
}


//----- (000E9358) --------------------------------------------------------
int __fastcall sub_E9358(int a1)
{
  int v1; // edx
  int v2; // eax
  int result; // eax

  v1 = 11 * a1;
  v2 = dword_1AA3E0;
  *(_BYTE *)(v1 + dword_1AA3E0) = 0;
  *(_BYTE *)(v1 + v2 + 6) = 0;
  result = 5;
  do
  {
    --result;
    if ( *(_BYTE *)(v1 + dword_1AA3E0 + result) )
      *(_BYTE *)(v1 + dword_1AA3E0 + 6) = 1;
  }
  while ( result > 0 );
  return result;
}
// 1AA3E0: using guessed type int dword_1AA3E0;


//----- (000E938C) --------------------------------------------------------
int16_t __fastcall sub_E938C(int a1, int a2, int a3, int a4, _BYTE *a5, int a6)
{
  _BYTE *v6; // esi
  int v8; // eax
  int16_t v9; // ax
  void *v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // ecx
  int16_t *v14; // edx
  int v15; // eax
  int v16; // eax
  int16_t v17; // ax
  int v18; // ecx
  int16_t v19; // ax
  int v20; // ecx
  void *v22; // [esp-4h] [ebp-BBCh]
  _BYTE v23[1744]; // [esp+0h] [ebp-BB8h] BYREF
  int16_t v24[500]; // [esp+6D0h] [ebp-4E8h] BYREF
  _BYTE v25[200]; // [esp+AB8h] [ebp-100h] BYREF
  int v26; // [esp+B80h] [ebp-38h]
  int v27; // [esp+B84h] [ebp-34h]
  int v28; // [esp+B88h] [ebp-30h]
  int v29; // [esp+B8Ch] [ebp-2Ch]
  int v30; // [esp+B90h] [ebp-28h]
  int16_t v31; // [esp+B94h] [ebp-24h] BYREF
  int16_t v32; // [esp+B98h] [ebp-20h] BYREF
  int v33; // [esp+B9Ch] [ebp-1Ch]
  int16_t v34; // [esp+BA0h] [ebp-18h] BYREF
  int v35; // [esp+BA4h] [ebp-14h]
  int v36; // [esp+BA8h] [ebp-10h]
  int v37; // [esp+BACh] [ebp-Ch]
  int16_t v38; // [esp+BB0h] [ebp-8h] BYREF
  int v39; // [esp+BB4h] [ebp-4h]

  v6 = a5;
  LOWORD(v37) = a2;
  v33 = a4;
  v8 = (int16_t)a4;
  if ( (int16_t)a4 != -1 )
    v8 = *(int16_t *)(17 * (int16_t)a4 + dword_1930D4);
  v35 = v8;
  if ( a3 == -1 )
    v9 = *(char *)(dword_192B18 + 361 * (int16_t)v8);
  else
    v9 = a3;
  LOWORD(v39) = v9;
  if ( (int16_t)v37 < 8 && v9 < 8 )
    *(_BYTE *)(3753 * (int16_t)v37 + dword_197F98 + (int16_t)v39 + 1815) = 0;
  if ( !a5 )
  {
    v6 = v23;
    memset(v23, 0, 1742);
  }
  if ( (uint8_t)byte_199F3A < 2u || (uint8_t)byte_199F3A > 3u )
  {
    dword_1AA3E0 = 88 * (int16_t)a1 + dword_1AA3B0;
    dword_1AA3E4 = (int16_t)a1 + dword_1AA3B4;
  }
  else
  {
    if ( word_1AAF86 == word_1AAF5E )
    {
      dword_1AA3E0 = 88 * (int16_t)a1 + dword_1AA3B0;
      dword_1AA3E4 = (int16_t)a1 + dword_1AA3B4;
    }
    if ( (_WORD)v39 == word_19999C && !byte_199CB4 )
    {
      if ( (int16_t)v33 == -1 )
        v10 = sub_FEB51((int16_t)a1);
      else
        v10 = sub_77B28(v33);
      v22 = v10;
      v11 = sub_E5DE8((int16_t)v37);
      sprintf(v25, (char *)dword_1AA3BC, v11, v22);
      sub_77423((int)v25);
    }
  }
  v26 = (int16_t)v39;
  v27 = (int16_t)v37;
  v28 = (int16_t)a1;
  sub_E6A0C((int)v24, a1, v37, &v38, &v31, v39, &v32, &v34);
  v12 = v31;
  v13 = v26;
  v14 = &v24[v38];
  v6[10] = sub_E7343(&v24[v32], v34, v28, v35, a6, v6);
  v15 = (int16_t)v33;
  if ( (int16_t)v33 != -1 )
  {
    v14 = (int16_t *)dword_1930D4;
    v15 = *(int16_t *)(dword_1930D4 + 17 * (int16_t)v33);
  }
  v36 = v15;
  if ( (uint8_t)byte_199F3A >= 2u
    && (uint8_t)byte_199F3A <= 3u
    && ((_WORD)v37 == word_19999C || (_WORD)v39 == word_19999C) )
  {
    v16 = sub_F3E42(1);
    word_19994C = 1;
    sub_F55A4(v16, (int)v14, v12, v13);
  }
  if ( (char)v6[10] >= 0 )
  {
    if ( (int16_t)v39 >= 8 )
    {
      *(_BYTE *)dword_1AA3E4 &= ~(1 << (v39 - 8));
    }
    else if ( *(_BYTE *)(dword_1AA3E0 + 11 * (int16_t)v39) || (int16_t)v36 != -1 )
    {
      sub_E6CAA(a1, v39, v36);
    }
    else
    {
      sub_E6B44(&v24[v32], v34, a1);
    }
  }
  if ( (char)v6[10] > 0 )
  {
    if ( (_WORD)v39 == 9 )
    {
      v19 = v37;
      v20 = 3753 * (int16_t)v37;
      *(_BYTE *)(v20 + dword_197F98 + 495) = 1;
      sub_980DB(v19, (int)(v6 + 631), v6 + 639);
      if ( *(_BYTE *)(v20 + dword_197F98 + 40) == 100 && ((uint8_t)byte_199F3A < 2u || !byte_199CB4) )
      {
        sub_C6650();
        sub_98282((int16_t)v37, (int)(v6 + 631), *(_WORD *)(v6 + 639));
      }
    }
    if ( (_WORD)a1 == word_19999A )
    {
      *(_BYTE *)(3753 * (int16_t)v37 + dword_197F98 + 496) = 1;
      memset(dword_1AA3AC, 0, 144);
    }
    else
    {
      v30 = (int16_t)v37;
      sub_E6A0C((int)v24, a1, v37, &v38, &v31, v39, &v32, &v34);
      if ( !v31 )
      {
        if ( (int16_t)v37 < 8 )
          sub_E9358(v30);
        else
          *(_BYTE *)dword_1AA3E4 &= ~(1 << (v37 - 8));
      }
      if ( (int16_t)v36 != -1 && *(char *)(dword_192B18 + 361 * (int16_t)v36) != -1 )
        sub_E87D2(&v24[v38], v31);
    }
  }
  else
  {
    if ( (int16_t)v37 >= 8 )
      *(_BYTE *)dword_1AA3E4 &= ~(1 << (v37 - 8));
    else
      sub_E6CAA(a1, v37, -1);
    if ( (_WORD)v37 == 9 )
    {
      v17 = v39;
      v18 = 3753 * (int16_t)v39;
      *(_BYTE *)(v18 + dword_197F98 + 495) = 1;
      sub_980DB(v17, (int)(v6 + 631), v6 + 639);
      if ( *(_BYTE *)(v18 + dword_197F98 + 40) == 100 && ((uint8_t)byte_199F3A < 2u || !byte_199CB4) )
      {
        sub_C6650();
        sub_98282((int16_t)v39, (int)(v6 + 631), *(_WORD *)(v6 + 639));
      }
    }
    if ( (char)v6[10] < 0 )
    {
      v29 = (int16_t)v39;
      sub_E6A0C((int)v24, a1, v37, &v38, &v31, v39, &v32, &v34);
      if ( !v34 )
      {
        if ( (int16_t)v39 < 8 )
          sub_E9358(v29);
        else
          *(_BYTE *)dword_1AA3E4 &= ~(1 << (v39 - 8));
      }
    }
  }
  return (char)v6[10];
}
// E7343: using guessed type _DWORD __stdcall sub_E7343(_DWORD, int16_t, _DWORD, int16_t, char, _DWORD);
// E87D2: using guessed type int __fastcall sub_E87D2(_DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 199CB4: using guessed type char byte_199CB4;
// 199F3A: using guessed type char byte_199F3A;
// 1AA3AC: using guessed type int dword_1AA3AC;
// 1AA3B0: using guessed type int dword_1AA3B0;
// 1AA3B4: using guessed type int dword_1AA3B4;
// 1AA3BC: using guessed type int dword_1AA3BC;
// 1AA3E0: using guessed type int dword_1AA3E0;
// 1AA3E4: using guessed type int dword_1AA3E4;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF86: using guessed type int16_t word_1AAF86;


//----- (000E9869) --------------------------------------------------------
_BOOL1 __fastcall sub_E9869(int a1)
{
  return *(_BYTE *)(a1 + 15) == 7;
}


//----- (000E9871) --------------------------------------------------------
int __fastcall sub_E9871(int a1, uint8_t (__fastcall *a2)(int), int a3, int a4)
{
  int16_t i; // dx

  for ( i = 0; i < 5; ++i )
  {
    LOWORD(a4) = *(_WORD *)(a1 + 2 * i + 74);
    if ( (int16_t)a4 != -1 && a2(dword_1930D4 + 17 * (int16_t)a4) )
      return a4;
  }
  return -1;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (000E98BB) --------------------------------------------------------
int sub_E98BB()
{
  int result; // eax
  int16_t i; // dx

  result = dword_192B18;
  for ( i = 0; i < word_199996 && *(int16_t *)(result + 2) != -1; ++i )
    result += 361;
  if ( i >= word_199996 )
    word_199996 = i + 1;
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (000E98F2) --------------------------------------------------------
int __fastcall sub_E98F2(int result)
{
  int v1; // ebx
  int v2; // edx

  if ( *(char *)(result + 40) >= 50 )
  {
    if ( *(char *)(result + 40) < 90 )
    {
      v2 = result + 10;
      do
      {
        v1 = *(int16_t *)(v2 + 72);
        v2 -= 2;
        if ( v1 != -1 )
          *(_BYTE *)(dword_1930D4 + 17 * v1 + 15) = 0;
      }
      while ( v2 != result );
    }
    *(_BYTE *)(result + 40) = 0;
  }
  return result;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (000E9927) --------------------------------------------------------
void __fastcall sub_E9927(_BYTE *a1)
{
  int16_t v2; // di
  int16_t v3; // ax
  int16_t v4; // si
  uint8_t v5; // al
  char v6; // al
  int v7; // eax
  int v8; // esi
  int16_t i; // ax
  int v10; // edi
  uint8_t v11; // al
  _WORD *v12; // esi
  _BYTE *j; // edx
  char v14; // al
  char v15; // bl
  int v16; // eax
  char v17; // al
  signed int v18; // eax
  int v19; // esi
  signed int v20; // ecx
  int v21; // edi
  int v22; // ebx
  int v23[4]; // [esp+0h] [ebp-3Ch] BYREF
  int16_t v24; // [esp+10h] [ebp-2Ch]
  _BYTE v25[8]; // [esp+14h] [ebp-28h] BYREF
  int v26; // [esp+1Ch] [ebp-20h]
  int v27; // [esp+20h] [ebp-1Ch]
  int v28; // [esp+24h] [ebp-18h]
  int v29; // [esp+28h] [ebp-14h]
  int v30; // [esp+2Ch] [ebp-10h]
  int v31; // [esp+30h] [ebp-Ch]
  int16_t v32; // [esp+34h] [ebp-8h]
  int v33; // [esp+38h] [ebp-4h]

  v30 = (int)&a1[-dword_19306C] / 113;
  sub_E98F2((int)a1);
  if ( a1[40] && !*(_BYTE *)(v30 + dword_1AA3B4) )
  {
    memset(v25, 0, sizeof(v25));
    v2 = 0;
    v3 = word_199998;
    v28 = 88 * v30;
    while ( v3 > 0 )
    {
      if ( *(_BYTE *)(11 * --v3 + dword_1AA3B0 + v28 + 6) )
      {
        ++v2;
        v25[v3] = 1;
      }
    }
    if ( v2 > 0 )
    {
      v4 = sub_FE8DA((int)v25, word_199998);
      v32 = v4;
      v5 = a1[40];
      if ( v5 < 7u )
      {
        if ( v5 < 2u )
          goto LABEL_53;
        if ( v5 <= 2u )
        {
          *(_DWORD *)(dword_197F98 + 3753 * v4 + 50) += 50;
          v6 = v32 + 50;
        }
        else
        {
          if ( v5 != 3 )
            goto LABEL_53;
          *(_DWORD *)(dword_197F98 + 3753 * v4 + 50) += 100;
          v6 = v32 + 60;
        }
        goto LABEL_18;
      }
      if ( v5 > 7u )
      {
        if ( v5 > 8u )
        {
          if ( v5 == 10 && !a1[112] )
          {
            a1[40] = v32 + 90;
            a1[112] = 1;
            v18 = sub_1247A0(4u);
            v19 = ((v18 - (__CFSHL__(v18 >> 31, 2) + 4 * (v18 >> 31))) >> 2) + 1;
            BYTE2(v23[0]) = v30;
            LOBYTE(v23[0]) = 20;
            memset((char *)v23 + 3, 0, 2);
            while ( v19 )
            {
              v20 = 1;
              v21 = 13;
              v22 = 0;
              --v19;
              do
              {
                v29 = *(int16_t *)((char *)&word_17E07F + v21);
                v31 = 3753 * v32 + dword_197F98;
                if ( *(_BYTE *)(v29 + v31 + 196) == 2 )
                {
                  if ( sub_E412B(v31, v20) )
                  {
                    if ( sub_1247A0(++v22) == 1 )
                      *((_BYTE *)v23 + v19 + 3) = v20;
                  }
                }
                ++v20;
                v21 += 13;
              }
              while ( v20 < 204 );
              if ( v22 )
                sub_E4204(3753 * v32 + dword_197F98, *((uint8_t *)v23 + v19 + 3), v21);
            }
            if ( HIBYTE(v23[0]) )
              sub_EF629(v23[0], v23[1], v23[2], v23[3], v24, v32);
          }
          goto LABEL_53;
        }
        v6 = v32 + 80;
LABEL_18:
        a1[40] = v6;
        goto LABEL_53;
      }
      a1[40] = v32 + 70;
      v7 = 11 * v4;
      v8 = dword_192B18;
      *(_BYTE *)(88 * ((int)&a1[-dword_19306C] / 113) + dword_1AA3B0 + v7 + 7) = 1;
      for ( i = 0; i < word_199996 && *(int16_t *)(v8 + 2) != -1; ++i )
        v8 += 361;
      if ( i >= word_199996 )
        word_199996 = i + 1;
      v33 = sub_E9871((int)a1, (uint8_t (__fastcall *)(int))sub_E9869, 113, (int)a1);
      v27 = (int16_t)v33;
      v26 = v32;
      sub_12D75((v8 - dword_192B18) / 361, (int16_t)v33, v32);
      v10 = v8;
      v11 = sub_E0C1D((char *)v8, v26);
      *(_BYTE *)(v8 + 10) = v11;
      if ( v11 > 3u )
        *(_BYTE *)(v8 + 10) = 3;
      memset(v8 + 310, 0, 49);
      v12 = (_WORD *)(v8 + 12);
      memset(v10 + 12, 0, 168);
      for ( j = &v12[2 * *(uint8_t *)(v10 + 10)]; v12 < (_WORD *)j; j[1] |= 2u )
      {
        v14 = v32;
        j -= 4;
        v15 = v32;
        *j &= 0xF0u;
        *(_DWORD *)j |= v15 & 0xF;
        *j &= 0x8Fu;
        *(_DWORD *)j |= 16 * (v14 & 7);
        if ( *(_BYTE *)(dword_1930D4 + 17 * (int16_t)v33 + 11)
          && (v16 = dword_197F98 + 3753 * v32, !*(_BYTE *)(v16 + 2225)) )
        {
          if ( *(_BYTE *)(v16 + 2224) && j == (_BYTE *)v12 )
          {
            *v12 &= 0xFE7Fu;
            *(_BYTE *)v12 |= 0x80u;
          }
          else
          {
            *(_WORD *)j &= 0xFE7Fu;
          }
        }
        else
        {
          v17 = sub_1247A0(2u);
          *(_WORD *)j &= 0xFE7Fu;
          *(_DWORD *)j |= (v17 & 3) << 7;
        }
      }
      sub_E5296(a1);
      sub_E2A70((v10 - dword_192B18) / 361, v10);
      *(_WORD *)(v10 + 291) = -39;
    }
  }
LABEL_53:
  JUMPOUT(0xEA8C3);
}
// E99E1: control flows out of bounds to EA8C3
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17E07F: using guessed type int16_t word_17E07F;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 1AA3B0: using guessed type int dword_1AA3B0;
// 1AA3B4: using guessed type int dword_1AA3B4;


//----- (000E9CD3) --------------------------------------------------------
int __fastcall sub_E9CD3(int a1, int a2, int a3)
{
  int v5; // edx
  int v6; // ecx
  int16_t v7; // cx
  int result; // eax
  int v9; // edx
  _BYTE v10[16]; // [esp+0h] [ebp-18h] BYREF
  int16_t v11[2]; // [esp+10h] [ebp-8h] BYREF
  int v12; // [esp+14h] [ebp-4h]

  v12 = a3;
  v11[0] = -1;
  v5 = word_199994;
  v11[1] = -1;
  v6 = 129 * word_199994;
  while ( v5 > 0 )
  {
    v6 -= 129;
    --v5;
    if ( *(_BYTE *)(v6 + dword_197F9C + 99) == 12 && *(int16_t *)(v6 + dword_197F9C + 101) == a2 )
      v11[0] = v5;
  }
  v7 = v12;
  sub_FF799(v11, v12, v10);
  sub_FFD08(v11, v7, v10);
  result = dword_197F98 + 3753 * a1;
  v9 = dword_1AA3B4;
  *(_DWORD *)(result + 50) -= 500;
  *(_BYTE *)(v9 + a2) &= ~0x10u;
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 1AA3B4: using guessed type int dword_1AA3B4;


//----- (000E9D62) --------------------------------------------------------
void __usercall sub_E9D62(int a1, int16_t *a2)
{
  int16_t v2; // si
  char *v3; // eax
  int v4; // edx
  int v5; // ebx
  int16_t v6; // si
  int v7; // eax
  int16_t v8; // dx
  int16_t v9; // dx
  _BYTE *v10; // edx
  int v11; // ecx
  int16_t v12; // si
  int16_t v13; // ax
  int v14; // ebx
  int16_t v15; // ax
  _BYTE *j; // edx
  _BYTE v17[6424]; // [esp+0h] [ebp-1A1Eh] BYREF
  _BYTE v18[148]; // [esp+1918h] [ebp-106h] BYREF
  _BYTE v19[76]; // [esp+19ACh] [ebp-72h] BYREF
  char v20; // [esp+19F8h] [ebp-26h] BYREF
  _BYTE v21[64]; // [esp+1A44h] [ebp+26h] BYREF
  int v22; // [esp+1A84h] [ebp+66h] BYREF
  int v23; // [esp+1A88h] [ebp+6Ah]
  int16_t v24; // [esp+1A8Ch] [ebp+6Eh] BYREF
  int v25; // [esp+1A90h] [ebp+72h] BYREF
  int v26; // [esp+1A94h] [ebp+76h] BYREF
  int16_t i; // [esp+1A98h] [ebp+7Ah] BYREF
  char v28[4]; // [esp+1A9Ch] [ebp+7Eh] BYREF

  sub_107AF(&v22);
  if ( (uint8_t)byte_199F3A <= 1u )
    sub_1191CA((int)sub_84E9D, 1);
  sub_8A4C4();
  dword_1AA3B0 = (int)v17;
  memset(v17, 0, sizeof(v17));
  dword_1AA3B4 = (int)v19;
  memset(v19, 0, 73);
  dword_1AA3AC = (int)v18;
  memset(v18, 0, 146);
  v2 = word_199996;
  dword_1AA37C = (int)&v20;
  while ( v2 > 0 )
  {
    v3 = (char *)(dword_192B18 + 361 * --v2);
    v4 = *v3;
    if ( v4 != -1 )
    {
      v5 = 88 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)v3 + 1) + 2) + dword_1AA3B0;
      ++*(_BYTE *)(v5 + 11 * v4 + 7);
    }
  }
  v6 = 0;
  *(_BYTE *)(word_19999A + dword_1AA3B4) |= 1u;
  while ( 1 )
  {
    if ( v6 >= word_199994 )
    {
      word_1AA3E8 = 0;
      for ( i = 0; i <= word_19999A + 1; ++i )
      {
        if ( *(_WORD *)(dword_1AA3AC + 2 * i) && !sub_242CF(i) )
        {
          v10 = (_BYTE *)(dword_1AA37C + word_1AA3E8++);
          *v10 = i;
        }
      }
      sub_FE9B5((_BYTE *)dword_1AA37C, word_1AA3E8);
      if ( (uint8_t)byte_199F3A <= 1u )
      {
        memset(v21, 0, sizeof(v21));
        dword_1AA378 = (int)v21;
        while ( word_1AA3E8 > 0 )
        {
          sub_E84A5(&i, &v24, (int)a2);
          if ( i != -1 )
          {
            v26 = -1;
            v25 = -1;
            v28[0] = 0;
            if ( v24 >= 8 )
            {
              v11 = (int)&v25;
              sub_E8029(i, v24, &v26, &v25);
            }
            else if ( *(_BYTE *)(dword_197F98 + 3753 * v24 + 40) == 100 )
            {
              v11 = v24;
              if ( (((int)*(uint8_t *)(dword_19306C + 113 * i + 54) >> v24) & 1) == 0 )
              {
                v11 = (int)&v25;
                sub_E7CDB((int16_t *)i, v24, &v26, &v25);
                if ( (int16_t)v25 == -1 && (int16_t)v26 == -1 )
                {
                  LOBYTE(v11) = v24;
                  *(_BYTE *)(dword_19306C + 113 * i + 54) |= 1 << v24;
                }
              }
            }
            else
            {
              v11 = (int)&v25;
              sub_E7DCA(i, v24, &v26, &v25, v28);
            }
            if ( (int16_t)v25 == -1 )
            {
              v12 = v26;
            }
            else
            {
              v12 = *(char *)(dword_192B18 + 361 * (int16_t)v25);
              *(_BYTE *)(3753 * *(char *)(dword_192B18 + 361 * (int16_t)v25) + dword_197F98 + 516) = v24;
            }
            if ( v24 == 12 && (int16_t)v25 != -1 )
            {
              if ( *(_BYTE *)(3753 * v12 + dword_197F98 + 40) == 100 )
              {
                sub_CC735(v12, i, (int *)v12, v11);
                v14 = v13;
              }
              else
              {
                v14 = -1;
              }
              if ( v14 != -1 )
              {
                sub_E9CD3(v12, i, v14);
                v12 = -1;
              }
            }
            if ( v12 != -1 )
            {
              v15 = v25;
              if ( (int16_t)v25 != -1 )
                v15 = *(_WORD *)(361 * (int16_t)v25 + dword_192B18 + 2);
              *(_BYTE *)(113 * i + dword_19306C + 54) = 0;
              sub_E938C(i, v24, v26, v15, 0, v28[0]);
              dword_1AA3E0 = 0;
              dword_1AA3E4 = 0;
              sub_E6AA2(i, v24, v12);
            }
          }
        }
        dword_1AA378 = 0;
      }
      else if ( (uint8_t)byte_199F3A <= 3u )
      {
        byte_1AB03F = 14;
        sub_EA2F1(a1, a2);
        sub_F6816(32766, 26, 0, 0);
      }
      sub_E6E52((int)a2);
      if ( byte_183578 )
      {
        sub_8A159();
        byte_183578 = 0;
      }
      for ( j = (_BYTE *)(dword_19306C + 113 * word_19999A); (unsigned int)j > dword_19306C; sub_E9927(j) )
        j -= 113;
      sub_107BA(&v22);
      dword_1AA3B0 = 0;
      dword_1AA3B4 = 0;
      dword_1AA3AC = 0;
      dword_1AA37C = 0;
      sub_E4EB3();
      JUMPOUT(0xEA8C4);
    }
    v7 = 129 * v6 + dword_197F9C;
    if ( *(int16_t *)(v7 + 101) >= 72 )
    {
      if ( *(_BYTE *)(v7 + 17) == 2 && *(_BYTE *)(v7 + 100) == 1 )
      {
        v9 = *(_WORD *)(v7 + 101) - 500;
        if ( *(_BYTE *)(v7 + 109) == 1 )
          ++*(_WORD *)(dword_1AA3B0 + 88 * v9 + 11 * *(char *)(v7 + 99) + 8);
        else
          *(_BYTE *)(dword_1AA3B0 + 88 * v9 + 11 * *(char *)(v7 + 99) + 10) = 1;
      }
    }
    else
    {
      if ( *(_BYTE *)(v7 + 100) )
        goto LABEL_22;
      if ( *(char *)(v7 + 99) >= 8 )
      {
        *(_BYTE *)(dword_1AA3B4 + *(int16_t *)(v7 + 101)) |= 1 << (*(_BYTE *)(v7 + 99) - 8);
LABEL_12:
        LOWORD(a1) = *(char *)(v7 + 99);
        *(_WORD *)(dword_1AA3AC + 2 * *(int16_t *)(v7 + 101)) |= 1 << a1;
        goto LABEL_22;
      }
      a1 = dword_1AA3B0;
      v8 = *(uint8_t *)(v7 + 17);
      *(_BYTE *)(dword_1AA3B0 + 88 * *(int16_t *)(v7 + 101) + 11 * *(char *)(v7 + 99) + 6) = 1;
      v23 = 11 * *(char *)(v7 + 99) + a1 + 88 * *(int16_t *)(v7 + 101);
      a2 = (int16_t *)(v23 + v8);
      *(_BYTE *)a2 = 1;
      if ( v8 == 2 )
      {
        *(_BYTE *)(a1 + 88 * *(int16_t *)(v7 + 101) + 11 * *(char *)(v7 + 99) + 5) = 1;
      }
      else if ( !v8 )
      {
        goto LABEL_12;
      }
    }
LABEL_22:
    ++v6;
  }
}
// EA275: control flows out of bounds to EA8C4
// EA133: variable 'v13' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 183578: using guessed type char byte_183578;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 19999A: using guessed type int16_t word_19999A;
// 199F3A: using guessed type char byte_199F3A;
// 1AA378: using guessed type int dword_1AA378;
// 1AA37C: using guessed type int dword_1AA37C;
// 1AA3AC: using guessed type int dword_1AA3AC;
// 1AA3B0: using guessed type int dword_1AA3B0;
// 1AA3B4: using guessed type int dword_1AA3B4;
// 1AA3E0: using guessed type int dword_1AA3E0;
// 1AA3E4: using guessed type int dword_1AA3E4;
// 1AA3E8: using guessed type int16_t word_1AA3E8;
// 1AB03F: using guessed type char byte_1AB03F;


//----- (000EA2F1) --------------------------------------------------------
void __usercall sub_EA2F1(int a1, int16_t *a2)
{
  int v2; // ebx
  int v3; // edx
  _DWORD *v4; // eax
  int16_t v5; // ax
  int16_t v6; // ax
  int v7; // eax
  int v8; // eax
  int16_t v9; // ax
  int v10; // ebx
  int v11; // edx
  int v12; // eax
  int16_t v13; // si
  int16_t v14; // ax
  int16_t v15; // ax
  int16_t v16; // dx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  _BOOL1 v20; // zf
  int16_t v21; // ax
  int16_t v22; // [esp-4h] [ebp-14BCh]
  int16_t v23; // [esp-4h] [ebp-14BCh]
  _DWORD v24[2]; // [esp+0h] [ebp-14B8h] BYREF
  int v25; // [esp+8h] [ebp-14B0h]
  _BYTE v26[1732]; // [esp+Ch] [ebp-14ACh] BYREF
  char v27; // [esp+6D0h] [ebp-DE8h] BYREF
  _DWORD v28[2]; // [esp+DA0h] [ebp-718h] BYREF
  int v29; // [esp+DA8h] [ebp-710h]
  _BYTE v30[1732]; // [esp+DACh] [ebp-70Ch] BYREF
  _BYTE v31[64]; // [esp+1470h] [ebp-48h] BYREF
  int v32; // [esp+14B0h] [ebp-8h] BYREF
  int16_t v33; // [esp+14B4h] [ebp-4h] BYREF

  v2 = 64;
  v3 = 0;
  dword_1AB04C = (int)&v27;
  memset(v31, 0, sizeof(v31));
  v4 = v31;
  dword_1AA378 = (int)v31;
  while ( (uint8_t)byte_1AB03F >= 0xEu && (uint8_t)byte_1AB03F < 0x23u )
  {
    sub_FE8BE((int)v4, v3, v2, a2);
    v19 = sub_F55A4(v18, v3, v2, a1);
    sub_FE8BE(v19, v3, v2, a2);
    a1 = 24;
    a2 = &word_EA27A;
    LOBYTE(v4) = byte_1AB03F;
    do
    {
      if ( !a1 )
        break;
      v20 = *(_BYTE *)a2 == (uint8_t)byte_1AB03F;
      a2 = (int16_t *)((char *)a2 + 1);
      --a1;
    }
    while ( !v20 );
    switch ( a1 )
    {
      case 0:
      case 1:
      case 2:
      case 5:
      case 14:
      case 15:
      case 17:
      case 18:
      case 19:
      case 20:
      case 21:
      case 23:
        continue;
      case 3:
        while ( 1 )
        {
          LOWORD(v4) = word_1AAF6E;
          if ( word_1AAF6E >= word_1AAF70 )
            break;
          sub_FE8BE((int)v4, v3, v2, a2);
        }
        v3 = dword_1AAF6A;
        sub_F8C8E((char *)dword_1AAF72);
        goto LABEL_5;
      case 4:
        sub_1191CA((int)nullsub_15, 1);
        sub_124D41();
        byte_199F37 = 1;
        sub_84E9D();
        sub_124DEC();
        sub_124C08();
        sub_147D7(51);
        sub_E7CDB((int16_t *)byte_1AB040, word_19999C, &word_1AB041, &v33);
        v5 = v33;
        if ( v33 != -1 )
          v5 = *(_WORD *)(361 * v33 + dword_192B18 + 2);
        word_1AB043 = v5;
        sub_F3E42(0);
        byte_1AB03F = 17;
        if ( v33 != -1 )
        {
          v6 = *(char *)(dword_192B18 + 361 * v33);
LABEL_10:
          word_1AB045 = v6;
          goto LABEL_14;
        }
        if ( word_1AB041 != -1 )
        {
          v6 = word_1AB041;
          goto LABEL_10;
        }
        word_1AB045 = -1;
        byte_1AB03F = 14;
LABEL_14:
        a1 = 6;
        v2 = (int)&word_1AB041;
        v3 = 17;
        v7 = word_1AAF86;
LABEL_44:
        v4 = (_DWORD *)sub_F6816(v7, v3, v2, a1);
        break;
      case 6:
        while ( 1 )
        {
          LOWORD(v4) = word_1AAF6E;
          if ( word_1AAF6E >= word_1AAF70 )
            break;
          sub_FE8BE((int)v4, v3, v2, a2);
        }
        v3 = dword_1AAF6A;
        sub_F93E3((char *)dword_1AAF72);
LABEL_5:
        dword_1AAF72 = 0;
        v4 = sub_1113CC(dword_192ED4, v3);
        word_1AAF70 = 0;
        continue;
      case 7:
        if ( byte_1AB048 < 8 && (v3 = dword_197F98, *(_BYTE *)(dword_197F98 + 3753 * byte_1AB048 + 40) == 100) )
          byte_1AB03F = 21;
        else
          byte_1AB03F = 23;
        v4 = (_DWORD *)sub_147D7(51);
        continue;
      case 8:
        memset(v24, 0, 1742);
        v24[0] = *(_DWORD *)&byte_1AB03F;
        v24[1] = *(_DWORD *)&word_1AB043;
        v25 = *(_DWORD *)&algn_1AB047;
        a2 = (int16_t *)v26;
        *(_WORD *)&v26[1] = word_1AB043;
        BYTE2(v25) = sub_E938C(byte_1AB040, word_19999C, word_1AB041, word_1AB043, v24, 0);
        v8 = sub_F6816(*(int16_t *)(dword_197F98 + 3753 * word_1AB045 + 43), 24, (int)v24, 0x6CEu);
        while ( byte_1AB03F != 14 )
          sub_FE8BE(v8, 24, (int)v24, (int16_t *)v26);
        a1 = word_1AB041;
        v2 = word_1AB045;
        v22 = SBYTE2(v25);
        v9 = word_1AB043;
        v3 = word_19999C;
        goto LABEL_27;
      case 9:
        v10 = word_1AB041;
        v11 = byte_1AB048;
        LOWORD(v12) = sub_E938C(byte_1AB040, byte_1AB048, word_1AB041, word_1AB043, 0, 0);
        v13 = v12;
        if ( byte_1AB03F != 26 )
          byte_1AB03F = 14;
        while ( byte_1AB03F != 26 )
          sub_FE8BE(v12, v11, v10, a2);
        sub_E85F7(dword_1AB04C);
        sub_F6816(*(int16_t *)(dword_197F98 + 3753 * byte_1AB048 + 43), 25, 0, 0);
        a1 = word_1AB041;
        v2 = word_19999C;
        v23 = v13;
        v14 = word_1AB043;
        v3 = byte_1AB048;
        goto LABEL_35;
      case 10:
        v15 = sub_E938C(byte_1AB040, word_19999C, word_1AB041, word_1AB043, 0, 0);
        a1 = word_1AB041;
        goto LABEL_34;
      case 11:
        v16 = sub_E938C(byte_1AB040, byte_1AB048, word_1AB041, word_1AB043, 0, 0);
        byte_1AB03F = 14;
        sub_F3E42(1);
        a1 = word_1AB041;
        v2 = word_19999C;
        v22 = v16;
        v9 = word_1AB043;
        v3 = byte_1AB048;
LABEL_27:
        v4 = sub_F97CD(byte_1AB040, v3, v2, a1, v9, v22);
        continue;
      case 12:
        memset(v28, 0, 1742);
        v28[0] = *(_DWORD *)&byte_1AB03F;
        v28[1] = *(_DWORD *)&word_1AB043;
        v29 = *(_DWORD *)&algn_1AB047;
        a2 = (int16_t *)v30;
        *(_WORD *)&v30[1] = word_1AB043;
        BYTE2(v29) = sub_E938C(byte_1AB040, word_19999C, word_1AB041, word_1AB043, v28, 0);
        sub_F3E42(1);
        if ( word_1AB045 < 8 )
        {
          v17 = dword_197F98 + 3753 * word_1AB045;
          if ( *(_BYTE *)(v17 + 40) == 100 )
            sub_F6816(*(int16_t *)(v17 + 43), 22, (int)v28, 0x6CEu);
        }
        v15 = SBYTE2(v29);
        a1 = word_1AB041;
LABEL_34:
        v2 = word_1AB045;
        v23 = v15;
        v14 = word_1AB043;
        v3 = word_19999C;
LABEL_35:
        byte_1AB03F = 14;
        v4 = sub_F97CD(byte_1AB040, v3, v2, a1, v14, v23);
        continue;
      case 13:
        v3 = 23;
        sub_E859D(dword_1AB04C);
        a1 = 0;
        sub_E85F7(dword_1AB04C);
        v2 = 0;
        sub_F3E42(0);
        goto LABEL_43;
      case 16:
        sub_CC735(word_19999C, byte_1AB040, (int *)v2, a1);
        v32 = v21;
        sub_F3E42(0);
        if ( v32 == -1 )
        {
          v3 = 36;
          v7 = word_1AAF86;
          a1 = 0;
          v2 = 0;
          byte_1AB03F = 29;
        }
        else
        {
          a1 = 4;
          v2 = (int)&v32;
          v3 = 37;
LABEL_43:
          v7 = word_1AAF86;
          byte_1AB03F = 14;
        }
        goto LABEL_44;
      case 22:
        while ( 1 )
        {
          LOWORD(v4) = word_1AAF6E;
          if ( word_1AAF6E >= word_1AAF70 )
            break;
          sub_FE8BE((int)v4, v3, v2, a2);
        }
        v3 = dword_1AAF6A;
        sub_F9C58((char *)dword_1AAF72);
        dword_1AAF72 = 0;
        v4 = sub_1113CC(dword_192ED4, v3);
        word_1AAF70 = 0;
        byte_1AB03F = 14;
        continue;
    }
  }
  dword_1AB04C = 0;
  dword_1AA378 = 0;
  sub_FE8BE((int)v4, v3, v2, a2);
}
// EA330: variable 'v4' is possibly undefined
// EA54E: variable 'v8' is possibly undefined
// EA5C6: variable 'v12' is possibly undefined
// EA7E6: variable 'v18' is possibly undefined
// EA81D: variable 'v21' is possibly undefined
// EA27A: using guessed type int16_t word_EA27A;
// FE8D4: using guessed type int __fastcall nullsub_15(_DWORD, _DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199F37: using guessed type char byte_199F37;
// 1AA378: using guessed type int dword_1AA378;
// 1AAF6A: using guessed type int dword_1AAF6A;
// 1AAF6E: using guessed type int16_t word_1AAF6E;
// 1AAF70: using guessed type int16_t word_1AAF70;
// 1AAF72: using guessed type int dword_1AAF72;
// 1AAF86: using guessed type int16_t word_1AAF86;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB040: using guessed type char byte_1AB040;
// 1AB041: using guessed type int16_t word_1AB041;
// 1AB043: using guessed type int16_t word_1AB043;
// 1AB045: using guessed type int16_t word_1AB045;
// 1AB047: using guessed type _BYTE;
// 1AB048: using guessed type char byte_1AB048;
// 1AB04C: using guessed type int dword_1AB04C;


//----- (000EA8CA) --------------------------------------------------------
void __fastcall sub_EA8CA(int a1, int a2)
{
  int v3; // ecx
  int v4; // eax
  int v5; // [esp-4h] [ebp-CCh]
  char v6[200]; // [esp+0h] [ebp-C8h] BYREF

  v3 = a2;
  if ( sub_1247A0(2u) == 1 )
  {
    a2 = a1;
    a1 = v3;
  }
  v5 = sub_E5DE8(a1);
  v4 = sub_E5DE8(a2);
  sprintf(v6, (char *)dword_1AA3DC, v4, v5);
  sub_DD42A(v6);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1AA3DC: using guessed type int dword_1AA3DC;


//----- (000EA91B) --------------------------------------------------------
void __fastcall sub_EA91B(int a1)
{
  int16_t v1; // ax
  unsigned int v2; // esi
  unsigned int v3; // ecx
  char *v4; // esi
  int v5; // ecx
  int v6; // [esp+0h] [ebp-6E0h]
  int v7; // [esp+4h] [ebp-6DCh] BYREF
  int v8; // [esp+8h] [ebp-6D8h]
  int v9; // [esp+Ch] [ebp-6D4h]
  int16_t v10; // [esp+11h] [ebp-6CFh]
  unsigned int v11; // [esp+6D4h] [ebp-Ch]
  int v12; // [esp+6D8h] [ebp-8h]
  int v13; // [esp+6DCh] [ebp-4h]

  v11 = 12 * a1;
  v13 = byte_1AAF94[12 * a1];
  v12 = byte_1AAF8C[12 * a1];
  sub_EA8CA(v13, v6);
  if ( byte_199CB4 )
  {
    v2 = v11;
    v3 = v11;
    memset(&v7, 0, 1742);
    v4 = &byte_1AAF8B[v2];
    v7 = *(_DWORD *)v4;
    v4 += 4;
    v8 = *(_DWORD *)v4;
    v9 = *((_DWORD *)v4 + 1);
    v5 = *(int16_t *)((char *)word_1AAF8F + v3);
    v10 = v8;
    BYTE2(v9) = sub_E938C((int16_t)v12, v13, word_1AAF8D[v11 / 2], v5, &v7, 0);
    sub_E6AA2(v12, v13, v6);
    byte_1AB04B = 0;
    byte_1AAF94[12 * v13] = -1;
    byte_1AAF8B[v11] = 25;
    sub_F6816(*(int16_t *)(3753 * v6 + dword_197F98 + 43), 22, (int)&v7, 0x6CEu);
  }
  else
  {
    v1 = sub_E69F7(word_1AAF8F[v11 / 2]);
    sub_F8F98((int16_t)v6, (int16_t)v13, word_1AAF8D[v11 / 2], v1, v12);
    byte_1AAF8B[v11] = 23;
  }
  JUMPOUT(0xEA8C3);
}
// EA994: control flows out of bounds to EA8C3
// EA94B: variable 'v6' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 199CB4: using guessed type char byte_199CB4;
// 1AAF8D: using guessed type int16_t word_1AAF8D[];
// 1AAF8F: using guessed type int16_t word_1AAF8F[];
// 1AB04B: using guessed type char byte_1AB04B;


//----- (000EAAA1) --------------------------------------------------------
void __usercall sub_EAAA1(int a1, int a2, int a3)
{
  int v3; // eax
  int16_t v4; // dx
  char v5; // bl
  unsigned int v6; // ecx
  int v7; // kr00_4
  int v8; // esi
  int16_t v9; // cx
  int v10; // eax
  int16_t *v11; // edi
  int16_t v12; // bx
  int v13; // eax
  int v14; // eax
  int v15; // edx
  int16_t v16; // ax
  int v17; // ebx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // ebx
  int v22; // edx
  int v23; // ebx
  int i; // edx
  int v25; // ecx
  int16_t v26; // si
  int v27; // esi
  int v28; // edx
  int v29; // edi
  int v30; // edx
  char *v31; // eax
  int v32; // eax
  int16_t v33; // dx
  int v34; // eax
  int v35; // esi
  int16_t v36; // bx
  int v37; // eax
  int16_t *v38; // edi
  int16_t v39; // dx
  int16_t v40; // ax
  int v41; // ecx
  int v42; // edx
  int16_t v43; // [esp-4h] [ebp-2Ch]
  int v44; // [esp+4h] [ebp-24h]
  int16_t v45; // [esp+8h] [ebp-20h]
  int16_t v46; // [esp+Ch] [ebp-1Ch] BYREF
  int v47; // [esp+10h] [ebp-18h] BYREF
  int v48; // [esp+14h] [ebp-14h] BYREF
  int16_t v49; // [esp+18h] [ebp-10h] BYREF
  int v50; // [esp+1Ch] [ebp-Ch]
  int16_t v51; // [esp+20h] [ebp-8h]
  char v52[4]; // [esp+24h] [ebp-4h] BYREF

  v3 = sub_FE8BE(a1);
  if ( byte_183579 )
    goto LABEL_89;
  LOWORD(v3) = word_199998;
  byte_183579 = 1;
  v51 = word_199998;
  while ( 1 )
  {
    if ( v51 <= 0 )
    {
      if ( word_1AA3E8 )
      {
        if ( byte_1AAF8B[12 * word_19999C] != 16 && byte_1AAF8B[12 * word_19999C] != 15 && !byte_1AB04B )
        {
          sub_E84A5(&v46, &v49, a3);
          if ( v46 == -1 )
          {
            byte_1AB04B = 1;
          }
          else
          {
            v47 = -1;
            v48 = -1;
            v20 = word_1AA3AA;
            v52[0] = 0;
            v21 = word_1AA3AA;
            while ( v21 > 0 )
            {
              v22 = 12 * word_1AA38A[v21--];
              byte_1AAF8C[v22] = v46;
              --v20;
              byte_1AAF94[v22] = v49;
            }
            v23 = word_1AA38A[0];
            for ( i = 2 * word_1AA38A[0]; i > 0; i -= 2 )
            {
              v25 = 361 * *(int16_t *)((char *)&dword_1AA37C + i + 2);
              v26 = *(char *)(v25 + dword_192B18);
              byte_1AAF8C[12 * *(char *)(v25 + dword_192B18)] = v46;
              --v23;
              byte_1AAF94[12 * v26] = v49;
            }
            v27 = v49;
            v28 = 12 * v49;
            byte_1AAF8C[v28] = v46;
            byte_1AAF94[v28] = v49;
            if ( v49 >= 8
              || *(_BYTE *)(dword_197F98 + 3753 * v27 + 40) != 100
              || (v29 = v46, (((int)*(uint8_t *)(dword_19306C + 113 * v46 + 54) >> v49) & 1) != 0) )
            {
              if ( v49 < 8 && *(_BYTE *)(dword_197F98 + 3753 * v49 + 40) == 100 )
              {
                v50 = -1;
              }
              else
              {
                if ( v49 < 8 )
                  sub_E7DCA(v46, v49, &v47, &v48, v52);
                else
                  sub_E8029(v46, v49, &v47, &v48);
                if ( (int16_t)v48 == -1 )
                {
                  v50 = v47;
                }
                else
                {
                  HIWORD(v30) = HIWORD(dword_192B18);
                  v31 = (char *)(dword_192B18 + 361 * (int16_t)v48);
                  LOWORD(v30) = *v31;
                  v32 = 3753 * *v31;
                  v50 = v30;
                  *(_BYTE *)(v32 + dword_197F98 + 516) = v49;
                }
              }
              word_1AAF8D[6 * v49] = v47;
              v33 = sub_E69DE((int16_t)v48);
              v34 = 12 * v49;
              *(int16_t *)((char *)word_1AAF8F + v34) = v33;
              v35 = (int16_t)v50;
              *(int16_t *)((char *)word_1AAF91 + v34) = v50;
              if ( v35 == -1 )
              {
                byte_1AB04B = 0;
                v36 = word_199998;
                while ( v36 > 0 )
                {
                  LOWORD(v34) = byte_1AAF94[12 * --v36];
                  if ( (_WORD)v34 == v49 )
                  {
                    v34 = sub_FE8BE(v34);
                    byte_1AAF94[12 * v36] = -1;
                  }
                }
              }
              else
              {
                *(_BYTE *)(dword_19306C + 113 * v46 + 54) = 0;
                v37 = 12 * v49;
                v38 = &word_1AAF8D[6 * v35];
                v39 = word_199998;
                *(_DWORD *)v38 = *(_DWORD *)((char *)word_1AAF8D + v37);
                v38[2] = *(int16_t *)((char *)&word_1AAF8D[2] + v37);
                while ( v39 > 0 )
                {
                  if ( --v39 != v49 && v39 != (_WORD)v50 )
                  {
                    LOWORD(v37) = byte_1AAF94[12 * v39];
                    if ( (_WORD)v37 == v49 )
                    {
                      v37 = sub_FE8BE(v37);
                      byte_1AAF94[12 * v39] = -1;
                    }
                  }
                }
                if ( (int16_t)v50 < 8 && *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v50 + 40) == 100 )
                {
                  if ( v49 != 12 || (v42 = (int16_t)v48, (int16_t)v48 == -1) )
                  {
                    sub_EA91B((int16_t)v50);
                  }
                  else
                  {
                    byte_1AAF8B[12 * (int16_t)v50] = 28;
                    sub_FA104(v42);
                  }
                }
                else
                {
                  v40 = v48;
                  if ( (int16_t)v48 != -1 )
                    v40 = *(_WORD *)(361 * (int16_t)v48 + dword_192B18 + 2);
                  sub_E938C(v46, v49, v47, v40, 0, 0);
                  v41 = (int16_t)v50;
                  sub_E6AA2(v46, v49, (int16_t)v50);
                  byte_1AB04B = 0;
                  byte_1AAF94[12 * v49] = -1;
                  byte_1AAF94[12 * v41] = -1;
                }
              }
            }
            else
            {
              byte_1AAF8B[v28] = 16;
              sub_F88D8(v27, v29, word_1AA380);
            }
          }
        }
      }
      else
      {
        v4 = word_199998;
        v5 = 0;
        while ( v4 > 0 )
        {
          if ( *(_BYTE *)(3753 * --v4 + dword_197F98 + 40) == 100 && byte_1AAF8B[12 * v4] != 14 )
          {
            sub_FE8BE(12 * v4);
            v5 = 1;
          }
        }
        if ( !v5 )
          byte_1AB03F = 35;
      }
      byte_183579 = 0;
LABEL_89:
      JUMPOUT(0xEA8BE);
    }
    --v51;
    sub_FE8BE(v3);
    v3 = v51;
    v6 = 12 * v51;
    LOBYTE(a2) = byte_1AAF8B[v6] - 14;
    v7 = a2;
    a2 = (uint8_t)a2;
    switch ( (char)a2 )
    {
      case 3:
        v8 = word_1AAF91[6 * v51];
        v45 = word_1AAF91[6 * v51];
        if ( v8 == -1 )
        {
          byte_1AAF8B[12 * v51] = 14;
          v9 = word_199998;
          while ( v9 > 0 )
          {
            LOWORD(v3) = byte_1AAF94[12 * --v9];
            if ( (_WORD)v3 == v51 )
            {
              v3 = sub_FE8BE(v3);
              byte_1AAF94[12 * v9] = -1;
            }
          }
          byte_1AB04B = 0;
          a2 = dword_19306C;
          v3 = dword_19306C + 113 * byte_1AAF8C[12 * v51];
          *(_BYTE *)(v3 + 54) |= 1 << v51;
        }
        else
        {
          v10 = 113 * byte_1AAF8C[12 * v51];
          *(_BYTE *)(dword_19306C + v10 + 54) = 0;
          v11 = &word_1AAF8D[6 * v8];
          v12 = word_199998;
          *(_DWORD *)v11 = *(_DWORD *)&word_1AAF8D[v6 / 2];
          v11[2] = word_1AAF8D[v6 / 2 + 2];
          while ( v12 > 0 )
          {
            if ( --v12 != v51 && v12 != v45 )
            {
              LOWORD(v10) = byte_1AAF94[12 * v12];
              if ( (_WORD)v10 == v51 )
              {
                v10 = sub_FE8BE(v10);
                byte_1AAF94[12 * v12] = -1;
              }
            }
          }
          a3 = v51;
          sub_EA8CA(v51, v45);
          v44 = 3753 * v51;
          if ( byte_199CB4 )
          {
            byte_1AAF8B[12 * v51] = 24;
            byte_1AAF8B[12 * v45] = 25;
            a2 = 20;
            v13 = v44 + dword_197F98;
LABEL_21:
            v14 = *(int16_t *)(v13 + 43);
            goto LABEL_22;
          }
          if ( v45 < 8 && *(_BYTE *)(3753 * v45 + dword_197F98 + 40) == 100 )
          {
            byte_1AAF8B[12 * v51] = 20;
            byte_1AAF8B[12 * v45] = 21;
            v43 = byte_1AAF8C[12 * a3];
            v16 = sub_E69F7(word_1AAF8F[6 * a3]);
            sub_F8F98(v45, a3, word_1AAF8D[6 * a3], v16, v43);
            a2 = 20;
            v13 = v44 + dword_197F98;
            goto LABEL_21;
          }
          v15 = 3753 * v51;
          byte_1AAF8B[12 * v51] = 22;
          v14 = *(int16_t *)(v15 + dword_197F98 + 43);
          a2 = 20;
LABEL_22:
          v3 = sub_F6816(v14, a2, 0, 0);
        }
        break;
      case 13:
        if ( byte_1AAF94[12 * v51] == v51 )
        {
          v17 = word_1AAF91[6 * v51];
          v18 = byte_1AAF8C[12 * v51];
          a2 = v51;
        }
        else
        {
          a2 = byte_1AAF94[12 * v51];
          v18 = byte_1AAF8C[12 * v51];
          v17 = v51;
        }
        sub_E6AA2(v18, a2, v17);
        v3 = 12 * v51;
        byte_1AAF8B[v3] = 14;
        byte_1AAF94[v3] = -1;
        byte_1AB04B = 0;
        continue;
      case 15:
        sub_EA91B(v51);
        a2 = dword_1AA3B4;
        v3 = byte_1AAF8C[12 * v51];
        *(_BYTE *)(dword_1AA3B4 + v3) &= ~0x10u;
        byte_1AAF8B[v6] = 25;
        goto LABEL_32;
      case 16:
        a2 = byte_1AAF8C[12 * v51];
        v3 = sub_E9CD3(v51, a2, byte_1AB0CD);
        byte_1AAF94[12 * v51] = -1;
        byte_1AAF8B[v6] = 14;
LABEL_32:
        byte_1AB04B = 0;
        byte_1AB024 = -1;
        continue;
      case 17:
        if ( byte_1AB03F != 14 )
          continue;
        byte_1AB03F = 33;
        v19 = dword_197F98;
        byte_1AAF8B[12 * v51] = 32;
        v14 = *(int16_t *)(v19 + 3753 * v3 + 43);
        a2 = 49;
        goto LABEL_22;
      default:
        a2 = v7;
        continue;
    }
  }
}
// EB18D: control flows out of bounds to EA8BE
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 183579: using guessed type char byte_183579;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 199CB4: using guessed type char byte_199CB4;
// 1AA37C: using guessed type int dword_1AA37C;
// 1AA380: using guessed type int16_t word_1AA380[5];
// 1AA38A: using guessed type int16_t word_1AA38A[];
// 1AA3AA: using guessed type int16_t word_1AA3AA;
// 1AA3B4: using guessed type int dword_1AA3B4;
// 1AA3E8: using guessed type int16_t word_1AA3E8;
// 1AAF8D: using guessed type int16_t word_1AAF8D[];
// 1AAF8F: using guessed type int16_t word_1AAF8F[];
// 1AAF91: using guessed type int16_t word_1AAF91[];
// 1AB024: using guessed type char byte_1AB024;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB04B: using guessed type char byte_1AB04B;
// 1AB0CD: using guessed type char byte_1AB0CD;


//----- (000EB192) --------------------------------------------------------
int16_t __fastcall sub_EB192(int a1)
{
  void *v1; // eax
  int v2; // ebx
  int v3; // eax
  char *v4; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // esi
  char *v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int16_t v12; // dx
  int16_t v13; // dx
  char v14; // bl
  int16_t v15; // cx
  int v16; // eax
  unsigned int v17; // ecx
  char v18; // bh
  int v19; // eax
  int16_t v20; // si
  _BYTE v22[64]; // [esp+0h] [ebp-60h] BYREF
  void *v23; // [esp+40h] [ebp-20h]
  int v24; // [esp+44h] [ebp-1Ch]
  int v25; // [esp+48h] [ebp-18h]
  int v26; // [esp+4Ch] [ebp-14h]
  int v27; // [esp+50h] [ebp-10h]
  int v28; // [esp+54h] [ebp-Ch]
  int v29; // [esp+58h] [ebp-8h]
  char v30; // [esp+5Ch] [ebp-4h]

  LOWORD(a1) = word_199998;
  v29 = a1;
  while ( (int16_t)v29 > 0 )
  {
    v24 = (int16_t)--v29;
    v25 = 3753 * (int16_t)v29;
    v23 = (void *)(v25 + dword_197F98 + 1412);
    v1 = v23;
    qmemcpy(&v22[8 * (int16_t)v29], v23, 8u);
    memset(v1, 0, 8);
    memset(v25 + dword_197F98 + 1429, 0, 8);
    v2 = v24;
    v3 = v25 + dword_197F98;
    *(_BYTE *)(v24 + v3 + 1429) = 1;
    *(_BYTE *)(v3 + 1420) = 0;
    *((_BYTE *)v23 + v2) = 1;
  }
  v4 = (char *)(361 * word_199996 + dword_192B18);
  while ( (unsigned int)v4 > dword_192B18 )
  {
    v5 = *(int16_t *)(v4 - 359);
    v4 -= 361;
    if ( v5 != -1 )
    {
      v6 = 3753 * *v4 + dword_197F98;
      v7 = 113 * *(uint8_t *)(dword_1930D4 + 17 * v5 + 2) + dword_19306C;
      v8 = (char *)(361 * ((int)&v4[-dword_192B18] / 361) + dword_192B18);
      while ( (unsigned int)v8 > dword_192B18 )
      {
        v9 = *(int16_t *)(v8 - 359);
        v8 -= 361;
        if ( v9 != -1 )
        {
          v25 = 3753 * *v8;
          v26 = v25 + dword_197F98;
          v25 = *v4;
          v10 = dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * v9 + 2);
          v30 = 0;
          if ( sub_FF68A(v10, v25) )
          {
            v25 = *v4;
            v11 = dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)v8 + 1) + 2);
            v30 = 1;
            if ( sub_FF666(v11, v25) )
              *(_BYTE *)(v6 + *v8 + 1429) = 1;
          }
          if ( sub_FF68A(v7, *v8) )
          {
            v12 = *v8;
            v30 = 1;
            if ( sub_FF666(v7, v12) )
              *(_BYTE *)(v26 + *v4 + 1429) = 1;
          }
          if ( v30 )
          {
            *(_BYTE *)(v6 + *v8 + 1412) = 1;
            *(_BYTE *)(v26 + *v4 + 1412) = 1;
          }
        }
      }
    }
  }
  v13 = word_199998;
  while ( v13 > 0 )
  {
    --v13;
    v14 = 0;
    v27 = 3753 * v13 + dword_197F98 + 1412;
    v15 = word_199998;
    while ( v15 > 0 )
    {
      --v15;
      v28 = v13;
      v18 = v22[8 * v13 + v15];
      if ( v18 != *(_BYTE *)(v15 + v27) )
      {
        v14 = 1;
        if ( !v18 )
        {
          v19 = dword_197F98 + 3753 * v28;
          *(_BYTE *)(v19 + 1420) |= 1 << v15;
          ++*(_BYTE *)(v15 + v19 + 1421);
        }
        break;
      }
    }
    if ( v14 )
      byte_1AB124[v13] = 1;
  }
  v16 = 3753 * word_199998;
  v17 = v16 + dword_197F98;
  while ( v17 > dword_197F98 )
  {
    v20 = word_199998;
    v17 -= 3753;
    while ( v20 > 0 )
    {
      v16 = v17 + --v20;
      if ( !*(_BYTE *)(v16 + 1412) )
      {
        *(_BYTE *)(v16 + 1583) = 0;
        *(_BYTE *)(v16 + 1591) = 0;
        sub_1019F0((int)(v17 - dword_197F98) / 3753, v20);
        LOWORD(v16) = sub_1019F0(v20, (int)(v17 - dword_197F98) / 3753);
      }
    }
  }
  return v16;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;


//----- (000EB4DD) --------------------------------------------------------
int __fastcall sub_EB4DD(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int result; // eax
  int v10; // ecx
  int v11; // edx

  result = (a2 - a6) * (a7 - a5) - (a1 - a5) * (a8 - a6);
  if ( result )
  {
    v10 = (a3 - a5) * (a8 - a6);
    v11 = (a4 - a6) * (a7 - a5);
    if ( result <= 0 )
      return v10 - v11;
    else
      return v11 - v10;
  }
  return result;
}


//----- (000EB531) --------------------------------------------------------
char __fastcall sub_EB531( int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v9; // ecx
  int v10; // ebx
  int v11; // eax
  unsigned int v12; // ebx
  int v13; // eax
  _BOOL1 v14; // cc
  int v16; // [esp+0h] [ebp-60h]
  unsigned int v17; // [esp+20h] [ebp-40h]
  unsigned int v18; // [esp+24h] [ebp-3Ch]
  int v19; // [esp+2Ch] [ebp-34h]
  int v20; // [esp+34h] [ebp-2Ch]
  int v21; // [esp+38h] [ebp-28h]
  int v22; // [esp+40h] [ebp-20h]
  int i; // [esp+44h] [ebp-1Ch]
  char v26; // [esp+58h] [ebp-8h]
  char v27; // [esp+5Ch] [ebp-4h]

  while ( 1 )
  {
    v9 = a5 - a7;
    v10 = a6 - a4;
    v26 = 0;
    v11 = a1 * v9 + v10 * a2;
    v27 = 0;
    v22 = v10;
    v16 = v11 - (v9 * a6 + v10 * a7);
    v12 = v16 >= 0 ? v11 - (v9 * a6 + v10 * a7) : v9 * a6 + v10 * a7 - v11;
    v18 = v22 * v22 + v9 * v9;
    v17 = a3 * a3;
    if ( 0xFFFFFFFF / v17 >= v18 )
      break;
    if ( v12 <= 0xFFFF )
      goto LABEL_11;
    v13 = sub_134C92(v18);
    if ( v12 <= v13 * a3 )
      goto LABEL_11;
    if ( a3 * (v13 + 1) < v12 )
      goto LABEL_12;
    a1 /= 2;
    a2 /= 2;
    a3 /= 2;
    a5 /= 2;
    a4 /= 2;
    a7 /= 2;
    a6 /= 2;
  }
  if ( v12 <= 0xFFFF && v12 * v12 <= v18 * v17 )
LABEL_11:
    v27 = 1;
LABEL_12:
  if ( v27 )
  {
    if ( v16 )
    {
      v19 = a5 - a7;
      for ( i = a6 - a4; i * i + v19 * v19 <= v17; i += v22 )
        v19 += v9;
      v21 = v19 + a1;
      v20 = i + a2;
      if ( sub_EB4DD(v21, v20, a1, a2, a4, a5, a6, a7) > 0 )
      {
        v21 = a1 - v19;
        v20 = a2 - i;
        sub_EB4DD(v21, v20, a1, a2, a4, a5, a6, a7);
      }
      if ( sub_EB4DD(a4, a5, a6, a7, v21, v20, a1, a2) <= 0 )
        return 1;
    }
    else
    {
      if ( a4 >= a6 )
      {
        if ( a6 >= a4 )
        {
          if ( a5 > a7 )
          {
            if ( a2 < a7 )
              return v26;
            v14 = a2 <= a5;
          }
          else
          {
            if ( a2 < a5 )
              return v26;
            v14 = a2 <= a7;
          }
        }
        else
        {
          if ( a1 < a6 )
            return v26;
          v14 = a1 <= a4;
        }
      }
      else
      {
        if ( a1 < a4 )
          return v26;
        v14 = a1 <= a6;
      }
      if ( v14 )
        return 1;
    }
  }
  return v26;
}


//----- (000EB7C5) --------------------------------------------------------
int __fastcall sub_EB7C5(int a1)
{
  int v2; // edx
  int16_t i; // ax
  int v4; // ebx

  v2 = 0;
  for ( i = 0; i < word_19999A; ++i )
  {
    if ( *(_BYTE *)(113 * i + dword_19306C + 22) == 6 )
    {
      v4 = (int16_t)v2++;
      *(_WORD *)(a1 + 2 * v4) = i;
    }
  }
  return v2;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (000EB7FD) --------------------------------------------------------
char __fastcall sub_EB7FD(int a1, int a2, int a3, int a4)
{
  int16_t v4; // si
  int v5; // eax
  int v7; // [esp+0h] [ebp-1Eh]
  _WORD v8[72]; // [esp+4h] [ebp-1Ah] BYREF
  int v9; // [esp+94h] [ebp+76h]
  int v10; // [esp+98h] [ebp+7Ah]
  char v11; // [esp+9Ch] [ebp+7Eh]

  v9 = a3;
  v10 = a4;
  v4 = sub_EB7C5((int)v8);
  v11 = 0;
  if ( v7 != a3 || a2 != a4 )
  {
    while ( v4 > 0 )
    {
      v5 = dword_19306C + 113 * (int16_t)v8[--v4];
      if ( sub_EB531(*(_WORD *)(v5 + 15), *(_WORD *)(v5 + 17), 45, v7, a2, v9, v10) )
        return 1;
    }
  }
  return v11;
}
// EB825: variable 'v7' is possibly undefined
// 19306C: using guessed type int dword_19306C;


//----- (000EB87D) --------------------------------------------------------
int16_t sub_EB87D()
{
  int v0; // eax
  int16_t v1; // si
  int v2; // eax
  int16_t i; // si
  int v4; // ebx
  int16_t v5; // di
  int v6; // ebx
  int16_t v8; // [esp+0h] [ebp-2Eh]
  _WORD v9[72]; // [esp+4h] [ebp-2Ah] BYREF
  int v10; // [esp+94h] [ebp+66h]
  int v11; // [esp+98h] [ebp+6Ah]
  int v12; // [esp+9Ch] [ebp+6Eh]
  int v13; // [esp+A0h] [ebp+72h]
  int v14; // [esp+A4h] [ebp+76h]
  int v15; // [esp+A8h] [ebp+7Ah]
  int v16; // [esp+ACh] [ebp+7Eh]

  v0 = sub_EB7C5((int)v9);
  v1 = 0;
  v14 = v0;
  while ( v1 < word_19999A )
  {
    v2 = dword_19306C + 113 * v1++ + 31;
    LOWORD(v0) = memset(v2, 0, 9);
  }
  for ( i = 0; i < word_19999A; ++i )
  {
    HIWORD(v4) = HIWORD(dword_19306C);
    v0 = dword_19306C + 113 * i;
    if ( *(_BYTE *)(v0 + 22) != 6 )
    {
      LOWORD(v4) = *(_WORD *)(v0 + 15);
      v5 = 0;
      LOWORD(v0) = *(_WORD *)(v0 + 17);
      v16 = v4;
      v15 = v0;
      while ( v5 < i )
      {
        HIWORD(v6) = HIWORD(dword_19306C);
        v0 = dword_19306C + 113 * v5;
        if ( *(_BYTE *)(v0 + 22) != 6 )
        {
          v11 = 0;
          LOWORD(v6) = *(_WORD *)(v0 + 15);
          LOWORD(v0) = *(_WORD *)(v0 + 17);
          v13 = v6;
          v12 = v0;
          while ( 1 )
          {
            LOWORD(v0) = v11;
            if ( (int16_t)v11 >= (int16_t)v14 )
              break;
            v10 = 113 * (int16_t)v9[(int16_t)v11];
            if ( sub_EB531(
                   *(_WORD *)(v10 + dword_19306C + 15),
                   *(_WORD *)(v10 + dword_19306C + 17),
                   v8,
                   v16,
                   v15,
                   v13,
                   v12) )
            {
              v10 = 113 * i;
              sub_127712(v10 + dword_19306C + 31, v5);
              LOWORD(v0) = sub_127712(113 * v5 + dword_19306C + 31, i);
              break;
            }
            ++v11;
          }
        }
        ++v5;
      }
    }
  }
  return v0;
}
// EB95A: variable 'v8' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (000EB9C8) --------------------------------------------------------
_BOOL1 __fastcall sub_EB9C8( int a1, int a2, int a3)
{
  int v3; // esi
  int16_t *v4; // ebx
  int v5; // ecx
  int v6; // ebx
  int16_t *v7; // eax
  int v8; // edx
  _BOOL1 result; // al

  v3 = a3;
  v4 = (int16_t *)(dword_193068 + 5 * a3);
  v5 = (a1 - *v4) / 3;
  result = 0;
  if ( v5 >= 0 )
  {
    v6 = (a2 - v4[1]) / 3;
    if ( v6 >= 0 )
    {
      v7 = (int16_t *)dword_1902A4[4 * v3];
      v8 = *v7;
      if ( v5 < v8 && v6 < v7[1] && *((_BYTE *)v7 + v5 + v6 * v8 + 16) > 5u )
        return 1;
    }
  }
  return result;
}
// 1902A4: using guessed type int dword_1902A4[45];
// 193068: using guessed type int dword_193068;


//----- (000EBA3A) --------------------------------------------------------
_BOOL1 __fastcall sub_EBA3A( int a1, int a2)
{
  _BOOL1 v3; // cl
  int16_t i; // si

  v3 = 0;
  for ( i = 0; !v3 && i < (uint8_t)byte_199F0D; ++i )
    v3 = sub_EB9C8(a1, a2, i);
  return v3;
}
// 199F0D: using guessed type char byte_199F0D;


//----- (000EBA7C) --------------------------------------------------------
_BOOL1 __fastcall sub_EBA7C(int a1)
{
  return sub_EBA3A(*(_WORD *)(113 * a1 + dword_19306C + 15), *(_WORD *)(113 * a1 + dword_19306C + 17));
}
// 19306C: using guessed type int dword_19306C;


//----- (000EBA96) --------------------------------------------------------
int sub_EBA96()
{
  int v0; // edx
  int v1; // ebx
  _BOOL1 v2; // cl
  int result; // eax

  v0 = word_19999A;
  v1 = 113 * word_19999A;
  while ( v0 > 0 )
  {
    --v0;
    v1 -= 113;
    v2 = sub_EBA7C(v0);
    result = dword_19306C;
    *(_BYTE *)(v1 + dword_19306C + 111) = v2;
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (000EBAC3) --------------------------------------------------------
_BOOL1 __fastcall sub_EBAC3( int a1, int a2, int a3, int a4)
{
  char v5; // bh
  int v6; // edx
  int v7; // esi

  v5 = 0;
  if ( (*(_BYTE *)(a4 + 57) & (uint8_t)~(1 << a3)) != 0 )
  {
    v6 = a1 - *(int16_t *)(a4 + 15);
    v7 = a2 - *(int16_t *)(a4 + 17);
    return v6 * v6 + v7 * v7 <= 8100;
  }
  return v5;
}


//----- (000EBB0C) --------------------------------------------------------
_BOOL1 __fastcall sub_EBB0C( int a1, int a2, int a3,
        int a4, int a5,
        int16_t *a6,
        int16_t *a7,
        _BYTE *a8,
        _BYTE *a9)
{
  int v9; // eax
  _BOOL1 result; // al
  int16_t v11; // ax
  int v12; // eax
  int v13; // [esp+0h] [ebp-38h]
  int v14; // [esp+8h] [ebp-30h]
  int v15; // [esp+Ch] [ebp-2Ch]
  int v16; // [esp+14h] [ebp-24h]
  int v17; // [esp+18h] [ebp-20h]
  int16_t v18; // [esp+1Ch] [ebp-1Ch]
  int16_t v19; // [esp+24h] [ebp-14h]
  char v21; // [esp+30h] [ebp-8h]
  char v22; // [esp+34h] [ebp-4h]

  v9 = dword_19306C + 113 * a4;
  v15 = *(int16_t *)(v9 + 17);
  v14 = *(int16_t *)(v9 + 15);
  v17 = v14 - a2;
  v16 = v15 - a3;
  v22 = 0;
  v21 = 0;
  v13 = sub_134C92(v16 * v16 + v17 * v17);
  v19 = a5;
  if ( !a5 )
    v19 = 1;
  result = (char)a9;
  v18 = 1;
  *a9 = 0;
  while ( !a8 || !v21 )
  {
    result = (char)a9;
    if ( *a9 )
      break;
    if ( v22 )
      break;
    result = v18;
    if ( v18 > v19 )
      break;
    if ( v18 * 900 * v18 >= (v15 - a3) * (v15 - a3) + v17 * v17 )
    {
      *a6 = v14;
      v11 = v15;
      v22 = 1;
LABEL_12:
      *a7 = v11;
      goto LABEL_13;
    }
    v12 = 30 * v18;
    if ( v17 >= 0 )
      *a6 = a2 + (v13 + v17 * v12 - 1) / v13;
    else
      *a6 = a2 - (v13 + (a2 - v14) * v12 - 1) / v13;
    if ( v16 >= 0 )
    {
      v11 = a3 + (v13 + v16 * 30 * v18 - 1) / v13;
      goto LABEL_12;
    }
    *a7 = a3 - (v13 + 30 * v18 * (a3 - v15) - 1) / v13;
LABEL_13:
    if ( a8 && (result = sub_EBA3A(*a6, *a7)) )
    {
      v21 = 1;
    }
    else
    {
      result = sub_EBAC3(*a6, *a7, a1, 113 * a4 + dword_19306C);
      if ( result )
      {
        result = (char)a9;
        *a9 = 1;
      }
    }
    ++v18;
  }
  if ( v21 )
  {
    result = (char)a8;
    *a8 = 1;
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;


//----- (000EBCB2) --------------------------------------------------------
_BOOL1 __fastcall sub_EBCB2( int a1, int a2, int a3)
{
  int16_t v3; // si
  int16_t v5; // dx
  int16_t v6; // bx
  int16_t *v7; // eax
  int16_t *v8; // eax
  int v9; // edi
  int16_t *v10; // eax
  int16_t v11; // di
  int v13; // [esp+0h] [ebp-Ch]

  v3 = a1;
  v5 = a1;
  v6 = a2;
  while ( 1 )
  {
    v13 = 2 * v5;
    if ( *(int16_t *)(v13 + dword_1AA3EC) < 0 )
      break;
    v5 = *(_WORD *)(v13 + dword_1AA3EC);
  }
  while ( 1 )
  {
    v7 = (int16_t *)(dword_1AA3EC + 2 * v6);
    if ( *v7 < 0 )
      break;
    v6 = *v7;
  }
  while ( 1 )
  {
    v8 = (int16_t *)(dword_1AA3EC + 2 * v3);
    if ( *v8 < 0 )
      break;
    v9 = v3;
    v3 = *v8;
    *(_WORD *)(dword_1AA3EC + 2 * v9) = v5;
  }
  while ( 1 )
  {
    v10 = (int16_t *)(dword_1AA3EC + 2 * a2);
    if ( *v10 < 0 )
      break;
    v11 = a2;
    a2 = *v10;
    *(_WORD *)(dword_1AA3EC + 2 * v11) = v6;
  }
  if ( a3 && v5 != v6 )
  {
    if ( sub_1247A0(2u) == 1 )
      *(_WORD *)(dword_1AA3EC + 2 * v5) = v6;
    else
      *(_WORD *)(dword_1AA3EC + 2 * v6) = v5;
  }
  return v5 == v6;
}
// 1AA3EC: using guessed type int dword_1AA3EC;


//----- (000EBD80) --------------------------------------------------------
void sub_EBD80()
{
  int16_t v0; // si
  int v1; // ebx
  int16_t i; // si
  int v3; // ecx
  int16_t v4; // di
  int v5; // eax
  int v6; // edx
  int16_t j; // cx
  char v8; // [esp+0h] [ebp-16h] BYREF
  int v9; // [esp+90h] [ebp+7Ah]
  int v10; // [esp+94h] [ebp+7Eh]

  v0 = 0;
  dword_1AA3EC = (int)&v8;
  while ( v0 < word_19999A )
  {
    v1 = 2 * v0++;
    *(_WORD *)(v1 + dword_1AA3EC) = -1;
  }
  for ( i = 0; i < word_19999A; ++i )
  {
    v3 = 113 * i + dword_19306C;
    if ( *(_BYTE *)(v3 + 22) != 6 )
    {
      v4 = i + 1;
      v9 = v3 + 31;
      while ( v4 < word_19999A )
      {
        if ( *(_BYTE *)(dword_19306C + 113 * v4 + 22) != 6 && !(uint16_t)sub_1276F0(v9, v4) )
        {
          v10 = i;
          sub_EBEB7(i, v4);
          if ( v5 <= 8 )
            sub_EBCB2(v10, v4, 1);
        }
        ++v4;
      }
    }
  }
  v6 = 0;
  for ( j = 0; j < word_19999A; ++j )
  {
    if ( *(_BYTE *)(113 * j + dword_19306C + 22) != 6 && *(int16_t *)(dword_1AA3EC + 2 * j) == -1 )
      ++v6;
  }
  dword_1AA3EC = 0;
  JUMPOUT(0xEB9BB);
}
// EBE74: control flows out of bounds to EB9BB
// EBE0D: variable 'v5' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 1AA3EC: using guessed type int dword_1AA3EC;


//----- (000EBE79) --------------------------------------------------------
void __fastcall sub_EBE79( int a1, int a2, int a3, int a4)
{
  unsigned int v4; // ebx
  int i; // eax

  v4 = (a1 - a3) * (a1 - a3) + (a2 - a4) * (a2 - a4);
  for ( i = sub_134C92(v4 / 0x384); 900 * i * i < v4; ++i )
    ;
  JUMPOUT(0xEBD7F);
}
// EBEAE: control flows out of bounds to EBD7F


//----- (000EBEB7) --------------------------------------------------------
void __fastcall sub_EBEB7( int a1, int a2)
{
  sub_EBE79(
    *(_WORD *)(dword_19306C + 113 * a1 + 15),
    *(_WORD *)(dword_19306C + 113 * a1 + 17),
    *(_WORD *)(dword_19306C + 113 * a2 + 15),
    *(_WORD *)(dword_19306C + 113 * a2 + 17));
}
// 19306C: using guessed type int dword_19306C;


//----- (000EBEEB) --------------------------------------------------------
int __fastcall sub_EBEEB(int a1, int a2, int *a3, int *a4, int *a5)
{
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // [esp+4h] [ebp-8h]
  int v11; // [esp+8h] [ebp-4h]

  v10 = 5311 * (dword_192FD8 + 7 * a1) / (a1 + 100 * a2 + 150) % 360;
  v11 = sub_138776(v10, word_EB4C5[2 * a2]) + 5;
  v6 = sub_138615(v10, word_EB4C7[2 * a2]) - 5;
  if ( v11 < 0 )
    v7 = (5 - v11) / -10;
  else
    v7 = (v11 + 5) / 10;
  *a3 = v7;
  if ( v6 < 0 )
    v8 = (5 - v6) / -10;
  else
    v8 = (v6 + 5) / 10;
  *a4 = v8;
  *a4 = -*a4;
  result = (32 * v10 + 192) / 360;
  *a5 = result;
  if ( result == 32 )
    *a5 = 0;
  return result;
}
// EB4C5: using guessed type int16_t word_EB4C5[];
// EB4C7: using guessed type int16_t word_EB4C7[];
// 192FD8: using guessed type int dword_192FD8;


//----- (000EBFCB) --------------------------------------------------------
void __fastcall sub_EBFCB(int a1, int a2)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  unsigned int v8; // eax
  int v9; // [esp+0h] [ebp-1Ch]
  int v10; // [esp+4h] [ebp-18h]
  int v11; // [esp+8h] [ebp-14h]
  int16_t v12; // [esp+Ch] [ebp-10h]
  unsigned int v13; // [esp+14h] [ebp-8h]

  if ( a1 || a2 )
  {
    v13 = -1;
    v2 = 7;
    v3 = 14;
    do
    {
      v10 = *(int16_t *)((char *)&loc_EB4BD + v3 * 2);
      v12 = sub_1384B9(*(int16_t *)((char *)&loc_EB4BF + v3 * 2) * v9, -a2 * v10);
      v3 -= 2;
      v4 = sub_138776(v12, v10) + 5;
      --v2;
      if ( v4 < 0 )
        v5 = (5 - v4) / -10;
      else
        v5 = (v4 + 5) / 10;
      v11 = v5;
      v6 = sub_138615(v12, word_EB4C3[v3]) - 5;
      if ( v6 < 0 )
        v7 = (5 - v6) / -10;
      else
        v7 = (v6 + 5) / 10;
      v8 = (v11 - v9) * (v11 - v9) + (v7 + a2) * (v7 + a2);
      if ( v8 < v13 )
        v13 = v8;
    }
    while ( v2 > 0 );
  }
  JUMPOUT(0xEBA76);
}
// EC0D9: control flows out of bounds to EBA76
// EC01D: variable 'v9' is possibly undefined
// EB4C3: using guessed type int16_t word_EB4C3[];


//----- (000EC0DE) --------------------------------------------------------
void __fastcall sub_EC0DE(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // ecx
  int i; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v12; // [esp+8h] [ebp-8h]

  v6 = 0;
  if ( a2 > a5 )
  {
    v12 = a2 + 1 - a1;
    for ( i = 0; i < 100; ++i )
    {
      if ( i + 1 >= 96 || (v8 = a4 + i + 1, v8 > 100) )
        v8 = 100;
      if ( v8 >= a3 )
      {
        if ( v8 == 100 )
        {
          v9 = a2;
        }
        else if ( a1 >= a2 )
        {
          v9 = a1;
        }
        else
        {
          v9 = a1 + v12 * (v8 - a3) / (100 - a3);
        }
        v10 = v9 - a5;
        if ( v10 > 0 )
          v6 += v10;
      }
    }
  }
  JUMPOUT(0xEBFC5);
}
// EC157: control flows out of bounds to EBFC5


//----- (000EC15C) --------------------------------------------------------
char __fastcall sub_EC15C(int a1, _BYTE *a2, int a3)
{
  _BYTE *v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char result; // al

  memset(a2, 0, 19);
  if ( a1 >= 8 )
  {
    *a2 = 10;
    a2[1] = 10;
    a2[2] = 1;
    a2[3] = 10;
    a2[4] = 1;
    a2[5] = byte_17F698;
    a2[6] = byte_17F69B;
    a2[9] = -118;
    a2[10] = 30;
    a2[7] = 124;
    a2[8] = 20;
    result = 2 * byte_199CB0 - 4;
  }
  else
  {
    v5 = (_BYTE *)(dword_197F98 + 3753 * a1);
    if ( v5[288] == 3 )
      *a2 = 10;
    if ( v5[303] == 3 )
    {
      a2[1] = 10;
      a2[2] = 1;
    }
    if ( v5[423] == 3 )
    {
      a2[3] = 10;
      a2[4] = 1;
    }
    sub_DC323((int)v5);
    v6 *= 15;
    a2[5] = *((_BYTE *)&word_17F63E + v6);
    a2[6] = byte_17F641[v6];
    sub_DC416((int)v5);
    v7 *= 3;
    a2[9] = *((_BYTE *)&word_14A88 + v7);
    a2[10] = byte_14A8A[v7];
    sub_DC449((int)v5);
    v8 *= 3;
    a2[7] = *((_BYTE *)&word_14A9A + v8);
    a2[8] = byte_14A9C[v8];
    a2[11] = v5[2215];
    if ( v5[2218] )
    {
      a2[12] = 1;
    }
    else if ( v5[2217] )
    {
      a2[13] = -10;
    }
    if ( v5[2220] && a3 )
      a2[14] = 10;
    if ( v5[40] == 100 )
      result = 0;
    else
      result = byte_199CB0 - 2;
  }
  a2[15] = result;
  return result;
}
// EC1C2: variable 'v6' is possibly undefined
// EC1DE: variable 'v7' is possibly undefined
// EC1FA: variable 'v8' is possibly undefined
// 14A88: using guessed type int16_t word_14A88;
// 14A9A: using guessed type int16_t word_14A9A;
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17F63E: using guessed type int16_t word_17F63E;
// 17F698: using guessed type char byte_17F698;
// 17F69B: using guessed type char byte_17F69B;
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (000EC2AF) --------------------------------------------------------
char __fastcall sub_EC2AF(char *a1, int a2)
{
  int v3; // eax
  int v4; // ecx

  v3 = sub_DD9F2(a1);
  if ( v3 == -1 )
    return v3;
  v4 = 59 * v3 + dword_1930DC;
  if ( (*(_BYTE *)(v4 + 38) & 8) != 0 )
  {
    v3 = 3 * (sub_94951(v3) + 1);
  }
  else
  {
    if ( (*(_BYTE *)(v4 + 38) & 4) == 0 )
      goto LABEL_7;
    v3 = 2 * (sub_94951(v3) + 1);
  }
  *(_WORD *)(a2 + 16) = v3;
LABEL_7:
  if ( *(int16_t *)(a2 + 16) > 0 )
  {
    LOBYTE(v3) = a1[4];
    *(_BYTE *)(a2 + 18) = v3;
  }
  return v3;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (000EC2FD) --------------------------------------------------------
char __fastcall sub_EC2FD(int a1, int a2, int a3)
{
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  int v8; // [esp+0h] [ebp-Ch]
  int16_t v9; // [esp+8h] [ebp-4h]

  v8 = a1;
  while ( a2 > 0 )
  {
    a1 = 129 * *(int16_t *)(v8 + 2 * --a2);
    v4 = a1 + dword_197F9C;
    if ( *(int16_t *)(a1 + dword_197F9C + 116) >= 0 )
    {
      v5 = *(int16_t *)(v4 + 116);
      a1 = 59 * v5 + dword_1930DC;
      if ( !*(_BYTE *)(a1 + 55) )
      {
        v9 = 0;
        if ( (*(_BYTE *)(a1 + 38) & 8) != 0 )
        {
          v6 = (15 * (int16_t)sub_94951(v5) + 16) / 2;
LABEL_8:
          v9 = v6;
          goto LABEL_9;
        }
        if ( (*(_BYTE *)(a1 + 38) & 4) != 0 )
        {
          v6 = 5 * (sub_94951(v5) + 1);
          goto LABEL_8;
        }
LABEL_9:
        LOWORD(a1) = *(_WORD *)(a3 + 16);
        if ( (int16_t)a1 < v9 )
        {
          *(_WORD *)(a3 + 16) = v9;
          LOBYTE(a1) = *(_BYTE *)(v4 + 116);
          *(_BYTE *)(a3 + 18) = a1;
        }
      }
    }
  }
  return a1;
}
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;


//----- (000EC3CE) --------------------------------------------------------
int __fastcall sub_EC3CE(int a1, uint8_t *a2, uint8_t *a3)
{
  int16_t v5; // bx
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  uint8_t v9; // al
  int result; // eax
  int16_t v11; // [esp+0h] [ebp-Ch]
  int16_t v12; // [esp+4h] [ebp-8h]
  int16_t v13; // [esp+8h] [ebp-4h]

  v11 = a2[10] + a2[8] + *a2 + a2[6];
  v12 = 4;
  v13 = a2[14] + (char)a2[13] + (char)a2[11] + (char)a2[15] + *((_WORD *)a2 + 8);
  do
  {
    if ( --v12 == 3 )
    {
      if ( !a3 )
      {
        *(_WORD *)(a1 + 8) = 0;
        goto LABEL_8;
      }
      v5 = a3[10] + a3[8] + *a3 + a3[6];
      v6 = 3;
    }
    else
    {
      v6 = v12;
      v5 = v11;
    }
    *(_WORD *)(a1 + 2 * v6 + 2) = v5;
LABEL_8:
    v7 = a1 + 2 * v12;
    *(_WORD *)(v7 + 2) += v13;
    v8 = a1 + v12;
    *(_BYTE *)(v8 + 18) = a2[12] + 1;
    switch ( v12 )
    {
      case 0:
        *(_WORD *)(v7 + 2) += 10;
        ++*(_BYTE *)(v8 + 18);
        *(_WORD *)(v7 + 2) += a2[1];
        v9 = a2[2];
        goto LABEL_10;
      case 1:
        *(_WORD *)(v7 + 2) += a2[3];
        v9 = a2[4];
LABEL_10:
        *(_BYTE *)(v8 + 18) += v9;
        break;
      case 2:
        *(_WORD *)(v7 + 2) -= 10;
        break;
      case 3:
        *(_WORD *)(v7 + 2) -= 20;
        break;
      default:
        break;
    }
  }
  while ( v12 > 0 );
  *(_BYTE *)(a1 + 22) = 0;
  *(_BYTE *)(a1 + 24) = -1;
  *(_BYTE *)(a1 + 25) = -1;
  while ( 1 )
  {
    result = *(uint8_t *)(a1 + 22);
    if ( *(_WORD *)(a1 + 2 * result + 10) || *(_BYTE *)(a1 + 22) >= 4u )
      break;
    ++*(_BYTE *)(a1 + 22);
  }
  *(_BYTE *)(a1 + 23) = 0;
  return result;
}


//----- (000EC4FE) --------------------------------------------------------
char __fastcall sub_EC4FE(uint8_t *a1, uint8_t *a2)
{
  uint8_t *v3; // ecx
  int16_t v4; // si
  uint8_t *v5; // ecx
  int v6; // eax
  uint8_t v7; // al
  uint8_t v8; // al
  int16_t v10; // [esp+0h] [ebp-4h]

  v3 = &a1[2 * a1[22]];
  v4 = sub_1247A0(0x64u) + *((_WORD *)v3 + 1);
  v5 = &a2[2 * a2[22]];
  LOWORD(v6) = sub_1247A0(0x64u);
  LOWORD(v5) = *((_WORD *)v5 + 1);
  a1[24] = -1;
  a1[25] = -1;
  v10 = v6 + (_WORD)v5;
  if ( v4 <= (int16_t)(v6 + (_WORD)v5) )
  {
    if ( ++a1[23] == a1[a1[22] + 18] )
    {
      v7 = a1[22];
      a1[25] = v7;
      --*(_WORD *)&a1[2 * v7 + 10];
      v6 = a1[22];
      a1[23] = 0;
      if ( !*(_WORD *)&a1[2 * v6 + 10] )
      {
        while ( 1 )
        {
          v6 = a1[22];
          if ( *(_WORD *)&a1[2 * v6 + 10] || a1[22] >= 4u )
            break;
          ++a1[22];
        }
        a1[23] = 0;
      }
    }
    else
    {
      LOBYTE(v6) = a1[22];
      a1[24] = v6;
    }
  }
  a2[24] = -1;
  a2[25] = -1;
  if ( v4 >= v10 )
  {
    if ( ++a2[23] == a2[a2[22] + 18] )
    {
      v8 = a2[22];
      a2[25] = v8;
      --*(_WORD *)&a2[2 * v8 + 10];
      v6 = a2[22];
      a2[23] = 0;
      if ( !*(_WORD *)&a2[2 * v6 + 10] )
      {
        while ( 1 )
        {
          v6 = a2[22];
          if ( *(_WORD *)&a2[2 * v6 + 10] || a2[22] >= 4u )
            break;
          ++a2[22];
        }
        a2[23] = 0;
      }
    }
    else
    {
      LOBYTE(v6) = a2[22];
      a2[24] = v6;
    }
  }
  return v6;
}


//----- (000EC601) --------------------------------------------------------
void __fastcall sub_EC601(uint8_t *a1, uint8_t *a2)
{
  while ( a1[22] < 4u && a2[22] < 4u )
    sub_EC4FE(a1, a2);
  JUMPOUT(0xEC5FE);
}
// EC60B: control flows out of bounds to EC5FE


//----- (000EC61E) --------------------------------------------------------
int __fastcall sub_EC61E(int a1)
{
  unsigned int v1; // ebx
  unsigned int v2; // eax
  int v3; // edx

  v1 = a1 + 12;
  v2 = a1 + 12 + 4 * *(uint8_t *)(a1 + 10);
  v3 = 0;
  while ( v1 < v2 )
  {
    v2 -= 4;
    if ( (*(_DWORD *)v2 & 0xFu) < 8 && (*(_BYTE *)(v2 + 1) & 4) == 0 )
      ++v3;
  }
  return v3 / 5;
}


//----- (000EC65A) --------------------------------------------------------
int __fastcall sub_EC65A( int a1, int a2, char *a3, int16_t *a4, int a5)
{
  int16_t v5; // ax
  int16_t v6; // ax
  int v7; // eax

  memset(a4, 0, 55);
  *a4 = a1;
  a4[17] = *a3;
  v5 = (int)&a3[-dword_192B18] / 361;
  *((_DWORD *)a4 + 7) = 0;
  a4[13] = v5;
  a4[8] = a2;
  a4[16] = 0;
  memset(a5, 0, 55);
  *(_WORD *)a5 = *a3;
  *(_WORD *)(a5 + 34) = *a4;
  v6 = (int)&a3[-dword_192B18] / 361;
  *(_DWORD *)(a5 + 28) = 0;
  *(_WORD *)(a5 + 32) = 0;
  *(_WORD *)(a5 + 26) = v6;
  *(_WORD *)(a5 + 10) = *((_WORD *)a3 + 153);
  *(_WORD *)(a5 + 12) = *((_WORD *)a3 + 152);
  *(_WORD *)(a5 + 14) = sub_EC61E((int)a3);
  sub_EC15C(*a4, (_BYTE *)a4 + 36, 0);
  v7 = a4[17];
  a4[26] = 0;
  sub_EC15C(v7, (_BYTE *)(a5 + 36), 1);
  sub_EC2AF(a3, a5 + 36);
  sub_EC3CE((int)a4, (uint8_t *)a4 + 36, (uint8_t *)(a5 + 36));
  return sub_EC3CE(a5, (uint8_t *)(a5 + 36), (uint8_t *)a4 + 36);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;


//----- (000EC767) --------------------------------------------------------
int __fastcall sub_EC767( int a1, int a2, int a3, int a4, int a5, int a6, int16_t *a7, int a8)
{
  memset(a7, 0, 55);
  a7[13] = -1;
  *((_DWORD *)a7 + 7) = 0;
  a7[16] = 0;
  *a7 = a1;
  a7[6] = a2;
  a7[17] = a4;
  memset(a8, 0, 55);
  *(_WORD *)(a8 + 26) = -1;
  *(_DWORD *)(a8 + 28) = 0;
  *(_WORD *)(a8 + 32) = 0;
  *(_WORD *)a8 = a4;
  *(_WORD *)(a8 + 34) = a1;
  *(_WORD *)(a8 + 12) = a5;
  sub_EC15C(*a7, (_BYTE *)a7 + 36, 0);
  a7[26] = a3;
  sub_EC15C(a7[17], (_BYTE *)(a8 + 36), 0);
  *(_WORD *)(a8 + 52) = a6;
  sub_EC3CE((int)a7, (uint8_t *)a7 + 36, (uint8_t *)(a8 + 36));
  return sub_EC3CE(a8, (uint8_t *)(a8 + 36), (uint8_t *)a7 + 36);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (000EC831) --------------------------------------------------------
void __fastcall sub_EC831(int16_t *a1, int a2, char *a3, int16_t *a4, int a5)
{
  int16_t v5; // ax

  memset(a4, 0, 55);
  *a4 = *(char *)(129 * *a1 + dword_197F9C + 99);
  a4[17] = *a3;
  a4[13] = (int)&a3[-dword_192B18] / 361;
  *((_DWORD *)a4 + 7) = a1;
  v5 = a2;
  a4[16] = a2;
  while ( v5 > 0 )
  {
    if ( *(_BYTE *)(129 * a1[--v5] + dword_197F9C + 17) == 2 )
      a4[6] += 4;
  }
  memset(a5, 0, 55);
  *(_WORD *)a5 = *a3;
  *(_WORD *)(a5 + 34) = *a4;
  *(_WORD *)(a5 + 26) = (int)&a3[-dword_192B18] / 361;
  *(_DWORD *)(a5 + 28) = a1;
  *(_WORD *)(a5 + 32) = a2;
  *(_WORD *)(a5 + 10) = *((_WORD *)a3 + 153);
  *(_WORD *)(a5 + 12) = *((_WORD *)a3 + 152);
  *(_WORD *)(a5 + 14) = sub_EC61E((int)a3);
  sub_EC15C(*a4, (_BYTE *)a4 + 36, 0);
  sub_EC2FD((int)a1, a2, (int)(a4 + 18));
  sub_EC15C(a4[17], (_BYTE *)(a5 + 36), 1);
  sub_EC2AF(a3, a5 + 36);
  sub_EC3CE((int)a4, (uint8_t *)a4 + 36, (uint8_t *)(a5 + 36));
  JUMPOUT(0xEC75A);
}
// EC977: control flows out of bounds to EC75A
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 197F9C: using guessed type int dword_197F9C;


//----- (000EC97C) --------------------------------------------------------
int __fastcall sub_EC97C(char *a1)
{
  _BYTE *v2; // esi
  _DWORD *v3; // ebx
  int v4; // edx
  int i; // eax
  int v6; // edx
  _DWORD *v7; // ebx
  int v8; // edx
  int v9; // edx
  _DWORD *v10; // ebx
  int result; // eax
  _DWORD *v12; // ecx
  _BYTE v13[44]; // [esp+0h] [ebp-74h] BYREF
  _WORD v14[10]; // [esp+2Ch] [ebp-48h] BYREF
  _WORD v15[10]; // [esp+40h] [ebp-34h] BYREF
  _DWORD *v16; // [esp+54h] [ebp-20h]
  int v17; // [esp+58h] [ebp-1Ch]
  _DWORD *v18; // [esp+5Ch] [ebp-18h]
  _DWORD *v19; // [esp+60h] [ebp-14h]
  _DWORD *v20; // [esp+64h] [ebp-10h]
  _DWORD *v21; // [esp+68h] [ebp-Ch]
  int v22; // [esp+6Ch] [ebp-8h]
  char v23; // [esp+70h] [ebp-4h]

  v2 = a1 + 12;
  memset(v13, 0, 42);
  memset(v14, 0, sizeof(v14));
  memset(v15, -1, sizeof(v15));
  v3 = &v2[4 * (uint8_t)a1[10]];
  while ( v2 < (_BYTE *)v3 )
  {
    ++v14[*--v3 & 0xF];
    v4 = *v3 & 0xF;
    if ( (int16_t)v15[v4] == -1 )
    {
      v15[*v3 & 0xF] = sub_E0C1D(a1, v4);
      v13[(int16_t)v15[*v3 & 0xF]] = 1;
    }
  }
  sub_FEA82(v2, 4u, (uint8_t)a1[10]);
  for ( i = 1; i < 42; ++i )
  {
    if ( v13[i] )
    {
      v23 = 0;
      do
      {
        v20 = 0;
        v18 = 0;
        v21 = 0;
        v16 = 0;
        v6 = (uint8_t)a1[10];
        v19 = 0;
        v17 = 0;
        v7 = &v2[4 * v6];
        while ( v2 < (_BYTE *)v7 )
        {
          v22 = *--v7 & 0xF;
          if ( (int16_t)v15[v22] <= i )
          {
            ++v17;
            if ( v22 == 9 )
            {
              v20 = v7;
            }
            else if ( v22 == 8 )
            {
              v16 = v7;
            }
            else
            {
              v8 = *a1;
              if ( v8 == v22 )
              {
                v19 = v7;
              }
              else if ( v8 == *v7 << 25 >> 29 )
              {
                v21 = v7;
              }
              else
              {
                v18 = v7;
              }
            }
          }
        }
        if ( i < v17 )
        {
          --a1[10];
          if ( v20 )
          {
            v9 = (uint8_t)a1[10];
            v10 = v20;
          }
          else if ( v18 )
          {
            v9 = (uint8_t)a1[10];
            v10 = v18;
          }
          else if ( v21 )
          {
            v9 = (uint8_t)a1[10];
            v10 = v21;
          }
          else
          {
            v9 = (uint8_t)a1[10];
            if ( v16 )
              v10 = v16;
            else
              v10 = v19;
          }
          *v10 = *(_DWORD *)&v2[4 * v9];
        }
        else
        {
          v23 = 1;
        }
      }
      while ( !v23 );
    }
  }
  result = sub_DE03E((int)a1, *a1, 0);
  if ( !(_WORD)result )
  {
    result = 4 * (uint8_t)a1[10];
    v12 = &v2[result];
    while ( v2 < (_BYTE *)v12 )
    {
      if ( (*(_WORD *)--v12 & 0x180) == 0 )
      {
        result = *v12 & 0xF;
        if ( result != 8 )
        {
          *(_WORD *)v12 &= 0xFE7Fu;
          *(_BYTE *)v12 |= 0x80u;
        }
      }
    }
  }
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (000ECB65) --------------------------------------------------------
int __fastcall sub_ECB65(int a1, int a2)
{
  int v3; // ecx
  int v4; // eax
  int v5; // ebx
  int result; // eax
  int v7; // [esp+4h] [ebp-4h]

  v3 = -1;
  v4 = word_199996;
  v7 = 0;
  v5 = 361 * word_199996;
  while ( v4 > 0 )
  {
    --v4;
    v5 -= 361;
    if ( v4 != a2 && a1 == *(char *)(v5 + dword_192B18) && *(uint8_t *)(v5 + dword_192B18 + 10) >= v7 )
    {
      v7 = *(uint8_t *)(v5 + dword_192B18 + 10);
      v3 = v4;
    }
  }
  result = 3753 * a1;
  if ( v3 == -1 )
    *(_WORD *)(dword_197F98 + result + 41) = -1;
  else
    *(_WORD *)(dword_197F98 + result + 41) = *(_WORD *)(dword_192B18 + 361 * v3 + 2);
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;


//----- (000ECBF7) --------------------------------------------------------
void __fastcall sub_ECBF7(int a1, int a2)
{
  int v3; // edi
  char *v4; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  int v12; // edi
  int v13; // edi
  int v14; // ecx
  int v15; // eax

  v3 = 361 * a1;
  v4 = (char *)(361 * a1 + dword_192B18);
  sub_DCCCC(v4);
  v6 = 3753 * *(char *)(v3 + dword_192B18) + dword_197F98;
  v5 = v6 + 2 * a2;
  LOWORD(v6) = (uint8_t)v4[10];
  *(_WORD *)(v5 + 1791) += v6;
  if ( v4[319] )
    sub_145EA(a1, 9u, v6);
  v7 = *v4;
  if ( *(_WORD *)(dword_197F98 + 3753 * v7 + 41) == *((_WORD *)v4 + 1) )
    sub_ECB65(v7, a1);
  *v4 = a2;
  sub_E53CD((int)v4);
  v8 = dword_197F98 + 3753 * a2;
  if ( *(int16_t *)(v8 + 41) == -1 )
    *(_WORD *)(v8 + 41) = *((_WORD *)v4 + 1);
  v9 = 3753 * a2;
  v10 = dword_197F98;
  v4[297] = 0;
  if ( *(char *)(3753 * a2 + v10 + 2207) / 2 == 3 )
  {
    if ( v4[330] )
    {
      sub_145EA(a1, 0x14u, v9);
      *(_DWORD *)(dword_197F98 + v9 + 50) += dword_17ECC1 / 2;
    }
    if ( v4[341] )
    {
      sub_145EA(a1, 0x1Fu, 3753 * a2);
      *(_DWORD *)(dword_197F98 + 3753 * a2 + 50) += dword_17ED92 / 2;
    }
  }
  v11 = (unsigned int)&v4[4 * (uint8_t)v4[10] + 12];
  while ( 1 )
  {
    if ( v11 <= (unsigned int)(v4 + 12) )
    {
      sub_E1CED(v4);
      sub_EC97C(v4);
      sub_B20A1(a1);
      v14 = 17 * *((int16_t *)v4 + 1);
      *(_WORD *)(v4 + 293) = 0;
      *(_WORD *)(v4 + 291) = -40;
      v4[302] = 0;
      v4[303] = 4;
      v15 = dword_1930D4;
      v4[321] = 0;
      sub_E5296((_BYTE *)(dword_19306C + 113 * *(uint8_t *)(v14 + v15 + 2)));
      v4[220] = 0;
      JUMPOUT(0xECBF1);
    }
    v11 -= 4;
    v12 = *(_DWORD *)v11 & 0xF;
    if ( v12 == a2 )
      break;
    if ( v12 == 8 || v12 == 9 )
    {
      v13 = 16 * (a2 & 7);
      *(_BYTE *)v11 &= 0x8Fu;
LABEL_15:
      *(_DWORD *)v11 |= v13;
    }
    else if ( *(_DWORD *)v11 << 25 >> 29 == a2 )
    {
      *(_BYTE *)(v11 + 1) &= ~4u;
    }
    else
    {
      if ( *(_BYTE *)(3753 * a2 + dword_197F98 + 2232) )
        break;
      *(_BYTE *)(v11 + 1) |= 4u;
    }
  }
  v13 = 16 * (a2 & 7);
  *(_WORD *)v11 &= 0xFB8Fu;
  goto LABEL_15;
}
// ECE00: control flows out of bounds to ECBF1
// 17ECC1: using guessed type int dword_17ECC1;
// 17ED92: using guessed type int dword_17ED92;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000ECE05) --------------------------------------------------------
void __stdcall sub_ECE05(
        int a1,
        int a2,
        int a3, int a4,
        int a5,
        int a6,
        int a7,
        int a8, int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14)
{
  int v14; // esi
  int v15; // ebx
  int16_t *v16; // ecx
  int16_t v17; // ax
  int v18; // [esp+0h] [ebp-4h]
  int16_t v19; // [esp+2Ch] [ebp+28h]

  v14 = a9;
  v19 = a4 - 1;
  v15 = 361 * SHIWORD(a7) + dword_192B18;
  v16 = (int16_t *)(a8 + 2 * a9);
  v17 = sub_ED59D((char *)v15);
  *(_WORD *)(v15 + 304) = 1;
  v18 = v17;
  while ( v14 > 0 )
  {
    --v16;
    --v14;
    if ( *(_BYTE *)(dword_197F9C + 129 * *v16 + 17) == 2 )
    {
      if ( v19 < 4 )
        sub_A163A(129 * *v16 / 129, 129);
      else
        v19 -= 4;
    }
  }
  *(_WORD *)(v15 + 304) += v19;
  if ( *(int16_t *)(v15 + 304) >= v18 )
    *(_WORD *)(v15 + 304) = v18;
  sub_E5296((_BYTE *)(dword_19306C + 113 * *(uint8_t *)(17 * *(int16_t *)(v15 + 2) + dword_1930D4 + 2)));
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;


//----- (000ECECA) --------------------------------------------------------
void __stdcall sub_ECECA(
        int a1,
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
        int a14)
{
  int v14; // edx
  int v15; // ebx

  v14 = 361 * SHIWORD(a7) + dword_192B18;
  v15 = (int16_t)sub_ED59D((char *)v14);
  if ( a5 >= 4 )
    *(_WORD *)(v14 + 304) = 4;
  else
    *(_WORD *)(v14 + 304) = a5;
  if ( v15 <= *(int16_t *)(v14 + 304) )
    *(_WORD *)(v14 + 304) = v15;
  sub_E5296((_BYTE *)(dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v14 + 2) + 2)));
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000ECF41) --------------------------------------------------------
int16_t __usercall sub_ECF41(char *a1, int a2, int a3, int a4)
{
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  int v8; // edi
  int v9; // edx
  uint16_t v10; // dx
  int v11; // edi
  int v12; // esi
  signed int v13; // ebx
  int v14; // ebx
  int v15; // esi
  int v16; // edx
  int16_t v17; // ax
  int v18; // edx
  int16_t v19; // ax
  int v21; // [esp+0h] [ebp-1E8h]
  _WORD v22[212]; // [esp+4h] [ebp-1E4h] BYREF
  _BYTE v23[8]; // [esp+1ACh] [ebp-3Ch] BYREF
  int v24; // [esp+1B4h] [ebp-34h]
  int v25; // [esp+1B8h] [ebp-30h]
  int v26; // [esp+1BCh] [ebp-2Ch]
  int v27; // [esp+1C0h] [ebp-28h]
  int v28; // [esp+1C4h] [ebp-24h]
  int v29; // [esp+1C8h] [ebp-20h]
  int v30; // [esp+1CCh] [ebp-1Ch]
  int v31; // [esp+1D0h] [ebp-18h]
  int v32; // [esp+1D4h] [ebp-14h]
  int v33; // [esp+1D8h] [ebp-10h]
  int v34; // [esp+1DCh] [ebp-Ch]
  unsigned int v35; // [esp+1E0h] [ebp-8h]
  int v36; // [esp+1E4h] [ebp-4h]

  v24 = a3;
  v31 = *a1;
  *(_WORD *)(dword_197F98 + 3753 * v31 + 2 * a2 + 1791) += 10;
  sub_ECBF7((v21 - dword_192B18) / 361, a2);
  if ( *(_BYTE *)(v21 + 312) )
    sub_145EA((v21 - dword_192B18) / 361, 2u, a4);
  if ( *(_BYTE *)(v21 + 332) )
    sub_145EA((v21 - dword_192B18) / 361, 0x16u, a4);
  if ( *(_BYTE *)(v21 + 311) )
    sub_145EA((v21 - dword_192B18) / 361, 1u, a4);
  *(_BYTE *)(v21 + 308) = 0;
  *(_BYTE *)(v21 + 309) = 0;
  *(_WORD *)(v21 + 304) = 0;
  *(_WORD *)(v21 + 306) = 0;
  v5 = 3753 * a2 + dword_197F98;
  *(_WORD *)(v5 + 514) += *(uint8_t *)(v21 + 10);
  if ( v24 )
  {
    v36 = 0;
    v30 = 125;
    if ( *(_BYTE *)(v5 + 40) != 100 )
      v30 = 5 * (uint8_t)byte_199CB0 + 115;
    memset(v23, 0, sizeof(v23));
    v6 = 931;
    v7 = v21 + 49;
    v8 = 2 * v36;
    v33 = 3753 * a2;
    while ( v6 > 0 )
    {
      --v7;
      v6 -= 19;
      if ( *(_BYTE *)(v7 + 310) )
      {
        v35 = *(int16_t *)((char *)&word_17EB43 + v6);
        if ( sub_E412B(v33 + dword_197F98, v35) )
        {
          v34 = v36 + 1;
          v9 = v30 / (v36 + 1);
          if ( (int)sub_1247A0(0x3E8u) <= v9 )
          {
            v10 = v35;
            *(_WORD *)&v23[v8] = v35;
            v25 = dword_197F98;
            v36 = v34;
            v8 += 2;
            sub_E4204(v33 + dword_197F98, v10, v8);
            if ( v34 == 4 )
              break;
          }
        }
      }
    }
    if ( v36 < 4 )
    {
      v32 = 65;
      v11 = *(uint8_t *)(v21 + 10);
      if ( *(_BYTE *)(dword_197F98 + 3753 * a2 + 40) != 100 )
        v32 = 5 * (uint8_t)byte_199CB0 + 55;
      memset(v22, 0, sizeof(v22));
      v26 = 3753 * a2;
      v12 = 204;
      v13 = 204;
      v28 = 3753 * v31;
      do
      {
        --v13;
        v29 = dword_197F98;
        --v12;
        if ( *(_BYTE *)(v13 + v28 + dword_197F98 + 279) == 3 && sub_E412B(v26 + v29, v13) )
          v22[v12] = 1;
      }
      while ( v13 > 0 );
      v14 = 2 * v36;
      v27 = 3753 * a2;
      do
      {
        v15 = v36 + 1;
        v16 = v32 / (v36 + 1);
        if ( (int)sub_1247A0(0x3E8u) <= v16 )
        {
          v17 = sub_FE92D((int)v22, 204);
          if ( v17 == -1 )
          {
            v11 = 0;
          }
          else
          {
            v22[v17] = 0;
            *(_WORD *)&v23[v14] = v17;
            v14 += 2;
            v36 = v15;
            sub_E4204(v27 + dword_197F98, v17, v11);
          }
        }
        --v11;
      }
      while ( v11 > 0 && v36 < 4 );
    }
    v18 = v24;
    v19 = v36;
    qmemcpy((void *)(v24 + 114), v23, 2 * v36);
    *(_WORD *)(v18 + 538) = v19;
    LOWORD(v5) = *(_WORD *)(v21 + 2);
    *(_WORD *)(v18 + 540) = v5;
  }
  return v5;
}
// ECF72: variable 'v21' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17EB43: using guessed type int16_t word_17EB43;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (000ED260) --------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __fastcall sub_ED260(int a1)
{
  int v1; // esi
  signed int v2; // ecx
  char *v3; // eax
  int v4; // edx
  int v5; // edx
  _BYTE v6[56]; // [esp-38h] [ebp-52h] BYREF
  char *v7; // [esp+0h] [ebp-1Ah]
  int16_t v8[28]; // [esp+4h] [ebp-16h] BYREF
  uint8_t v9[56]; // [esp+3Ch] [ebp+22h] BYREF
  int v10; // [esp+74h] [ebp+5Ah] BYREF
  int v11; // [esp+78h] [ebp+5Eh]
  int v12; // [esp+7Ch] [ebp+62h]
  int v13; // [esp+80h] [ebp+66h]
  int16_t v14; // [esp+84h] [ebp+6Ah]
  _BYTE v15[8]; // [esp+88h] [ebp+6Eh] BYREF
  int v16; // [esp+90h] [ebp+76h]
  unsigned int v17; // [esp+94h] [ebp+7Ah]
  int v18; // [esp+98h] [ebp+7Eh]

  if ( *(_BYTE *)(a1 + 303) != 4 )
  {
    memset(v15, 0, sizeof(v15));
    v1 = (uint8_t)v7[10];
    v2 = 0;
    v3 = &v7[4 * v1 + 12];
    while ( v1 > 0 )
    {
      v3 -= 4;
      --v1;
      if ( (v3[1] & 4) != 0 )
      {
        v4 = *(_DWORD *)v3 & 0xF;
        v16 = 3753 * v4;
        if ( !*(_BYTE *)(3753 * v4 + dword_197F98 + 36) )
        {
          ++v2;
          ++v15[v4];
        }
      }
    }
    if ( v2 > 0 )
    {
      v5 = 10 * v2;
      v18 = (int16_t)sub_FE8DA((int)v15, word_199998);
      if ( *(_BYTE *)(dword_197F98 + 3753 * *v7 + 40) == 100 && *(_BYTE *)(dword_197F98 + 3753 * v18 + 40) != 100 )
        v5 += 4 * (uint8_t)byte_199CB0 - 8;
      if ( v7[311] )
        v5 /= 2;
      if ( !v7[303] )
        v5 *= 2;
      if ( (int)sub_1247A0(0x3E8u) <= v5 )
      {
        v17 = sub_1247A0(v2);
        sub_EC65A(v18, v17, v7, v8, (int)v9);
        memset(&v10, 0, 18);
        LOBYTE(v10) = 0;
        BYTE2(v10) = v7[2];
        LOBYTE(v11) = v18;
        HIBYTE(v10) = 9;
        BYTE1(v11) = v17;
        while ( LOBYTE(v8[11]) < 4u && v9[22] < 4u )
          sub_EC4FE((uint8_t *)v8, v9);
        BYTE2(v11) = v17 - LOBYTE(v8[8]);
        sub_EF629(v10, v11, v12, v13, v14, *v7);
        sub_EF629(v10, v11, v12, v13, v14, v18);
        if ( LOBYTE(v8[11]) < 4u )
        {
          sub_ECF41(v7, v8[0], 0, (int)&v6[50]);
          qmemcpy(v6, v8, 0x37u);
          sub_ECECA(
            *(int *)v6,
            *(int *)&v6[4],
            *(int *)&v6[8],
            *(int *)&v6[12],
            *(int16_t *)&v6[16],
            *(int *)&v6[20],
            *(int *)&v6[24],
            *(int *)&v6[28],
            *(int *)&v6[32],
            *(int *)&v6[36],
            *(int *)&v6[40],
            *(int *)&v6[44],
            *(int *)&v6[48],
            *(int *)&v6[52]);
          *(_WORD *)(v7 + 291) = -41;
        }
      }
    }
  }
  JUMPOUT(0xECB5F);
}
// ED445: control flows out of bounds to ECB5F
// ED41E: bad sp value at call
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (000ED44A) --------------------------------------------------------
unsigned int sub_ED44A()
{
  char *i; // edx
  unsigned int result; // eax

  for ( i = (char *)dword_192B18; ; i += 361 )
  {
    result = dword_192B18 + 361 * word_199996;
    if ( (unsigned int)i >= result )
      break;
    if ( *i != -1 && !i[6] )
      sub_ED260((int)i);
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (000ED48B) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __fastcall sub_ED48B(
        int a1,
        int a2, int a3,
        int a4,
        int64_t a5,
        int a6,
        int64_t a7,
        arg8_ED48B a8,
        hr_int128_t a9,
        int a10,
        int a11, unsigned int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int64_t a20)
{
  char *v20; // edx
  char *v21; // edi
  int v22; // eax
  int v23; // edx
  int16_t v24; // bx
  _BYTE v26[56]; // [esp-44h] [ebp-B8h] BYREF
  int v27; // [esp-Ch] [ebp-80h]
  int v28; // [esp-8h] [ebp-7Ch]
  int v29; // [esp-4h] [ebp-78h]
  char *vars2; // [esp+76h] [ebp+2h]
  int vars6; // [esp+7Ah] [ebp+6h]
  int16_t _7E; // [esp+7Eh] [ebp+Ah] OVERLAPPED
  _UNKNOWN *retaddr; // [esp+80h] [ebp+Ch] BYREF

  v29 = a1;
  v28 = a2;
  v27 = a4;
  *(_DWORD *)((char *)&a20 + 2) = 361 * a3 + dword_192B18;
  sub_EC831(*(int16_t **)&_7E, vars6, *(char **)((char *)&a20 + 2), (int16_t *)&a9 + 1, (int)&retaddr + 2);
  qmemcpy(vars2, (char *)&a9 + 2, 0x37u);
  v20 = vars2;
  qmemcpy(vars2 + 55, (char *)&retaddr + 2, 0x37u);
  v21 = vars2 + 110;
  v22 = sub_12484C();
  *((_WORD *)vars2 + 269) = 0;
  *(_DWORD *)(v20 + 110) = v22;
  while ( a12 < 4u && a8.arr[0] < 4u )
    sub_EC4FE((uint8_t *)&a9 + 2, (uint8_t *)&retaddr + 2);
  if ( a12 >= 4u )
  {
    v23 = *(_DWORD *)((char *)&a20 + 2);
    *(_WORD *)(*(_DWORD *)((char *)&a20 + 2) + 306) = a6;
    v24 = vars6;
    *(_WORD *)(v23 + 304) = HIWORD(a6);
    while ( v24 > 0 )
    {
      if ( *(_BYTE *)(dword_197F9C + 129 * *(int16_t *)(*(_DWORD *)&_7E + 2 * --v24) + 17) == 2 )
        sub_A163A(129 * *(int16_t *)(*(_DWORD *)&_7E + 2 * v24) / 129, (int)v21);
    }
  }
  else
  {
    sub_ECF41(*(char **)((char *)&a20 + 2), SWORD1(a9), (int)vars2, (int)v21);
    qmemcpy(v26, (char *)&a9 + 2, 0x37u);
    sub_ECE05(
      *(int *)v26,
      *(int *)&v26[4],
      *(int *)&v26[8],
      *(int16_t *)&v26[12],
      *(int *)&v26[16],
      *(int *)&v26[20],
      *(int *)&v26[24],
      *(int *)&v26[28],
      *(int16_t *)&v26[32],
      *(int *)&v26[36],
      *(int *)&v26[40],
      *(int *)&v26[44],
      *(int *)&v26[48],
      *(int *)&v26[52]);
  }
  return sub_8A4C4();
}
// ED48B: variables would overlap: ^C2.2 and ^C2.4
// 192B18: using guessed type int dword_192B18;
// 197F9C: using guessed type int dword_197F9C;


//----- (000ED59D) --------------------------------------------------------
int __fastcall sub_ED59D(char *a1)
{
  int v1; // ebx

  v1 = (uint8_t)byte_17D806[*(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 5)];
  if ( !*(_BYTE *)(3753 * *a1 + dword_197F98 + 2237) )
    v1 /= 2;
  if ( !v1 )
    return 1;
  return v1;
}
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000ED5E7) --------------------------------------------------------
int __fastcall sub_ED5E7(char *a1)
{
  int v1; // ebx

  v1 = (uint8_t)a1[10];
  if ( !*(_BYTE *)(dword_197F98 + 3753 * *a1 + 2237) )
    v1 /= 2;
  if ( !v1 )
    return 1;
  return v1;
}
// 197F98: using guessed type int dword_197F98;


//----- (000ED61D) --------------------------------------------------------
int __fastcall sub_ED61D(char *a1)
{
  int v1; // ebx
  int v2; // eax
  int v3; // ebx

  v1 = (uint8_t)byte_17D806[*(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 5)];
  if ( *(_BYTE *)(3753 * *a1 + dword_197F98 + 2237) )
    v2 = v1 / 2;
  else
    v2 = (v1 - (__CFSHL__(v1 >> 31, 2) + 4 * (v1 >> 31))) >> 2;
  v3 = v2;
  if ( !v2 )
    return 1;
  return v3;
}
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000ED674) --------------------------------------------------------
int __fastcall sub_ED674(char *a1)
{
  int v1; // eax
  int v2; // ebx

  if ( *(_BYTE *)(dword_197F98 + 3753 * *a1 + 2237) )
    v1 = (uint8_t)a1[10] / 2;
  else
    v1 = (int)(uint8_t)a1[10] >> 2;
  v2 = v1;
  if ( !v1 )
    return 1;
  return v2;
}
// 197F98: using guessed type int dword_197F98;


//----- (000ED6B7) --------------------------------------------------------
int __fastcall sub_ED6B7(char *a1, int16_t *a2, int a3)
{
  int v6; // edx
  int v8; // [esp+0h] [ebp-4h]

  v6 = 0;
  v8 = (int16_t)sub_ED59D(a1);
  while ( *((int16_t *)a1 + 152) < v8 && v6 < a3 )
  {
    sub_A163A(*a2, a3);
    ++v6;
    ++a2;
    *((_WORD *)a1 + 152) += 4;
  }
  sub_E2710(dword_197F98 + 3753 * *a1);
  return v6;
}
// 197F98: using guessed type int dword_197F98;


//----- (000ED713) --------------------------------------------------------
int __fastcall sub_ED713(char *a1, int a2)
{
  int16_t v3; // ax

  memset(a2, 0, 55);
  *(_WORD *)a2 = *a1;
  v3 = (int)&a1[-dword_192B18] / 361;
  *(_WORD *)(a2 + 34) = -1;
  *(_DWORD *)(a2 + 28) = 0;
  *(_WORD *)(a2 + 32) = 0;
  *(_WORD *)(a2 + 26) = v3;
  *(_WORD *)(a2 + 10) = *((_WORD *)a1 + 153);
  *(_WORD *)(a2 + 12) = *((_WORD *)a1 + 152);
  *(_WORD *)(a2 + 14) = sub_EC61E((int)a1);
  sub_EC2AF(a1, a2 + 36);
  sub_EC15C(*a1, (_BYTE *)(a2 + 36), 1);
  return sub_EC3CE(a2, (uint8_t *)(a2 + 36), 0);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;


//----- (000ED7A3) --------------------------------------------------------
char __fastcall sub_ED7A3(int a1, int a2, int a3)
{
  int v4; // eax
  int v5; // ecx
  int v6; // esi
  int v7; // edi
  _BYTE *v9; // [esp+0h] [ebp-14h]
  int16_t v10; // [esp+8h] [ebp-Ch]
  int v11; // [esp+Ch] [ebp-8h]

  v11 = *(int16_t *)(3753 * a3 + dword_197F98 + 804);
  v4 = (3 * v11 + 1) / 2;
  v5 = word_19999A;
  v9 = (_BYTE *)(word_19999A + a2);
  v6 = word_19999A + a1;
  v7 = 113 * word_19999A;
  v10 = v4;
  while ( v7 > 0 )
  {
    v7 -= 113;
    *(_BYTE *)--v6 = sub_FF5F8(v7 + dword_19306C, a3, v11);
    --v9;
    LOBYTE(v4) = sub_FF5F8(v7 + dword_19306C, a3, v10);
    --v5;
    *v9 = v4;
  }
  return v4;
}
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;


//----- (000ED82F) --------------------------------------------------------
int16_t __fastcall sub_ED82F(int a1, int a2, int a3)
{
  int v5; // eax
  unsigned int v6; // ebx
  int v7; // ecx
  int v9; // [esp+4h] [ebp-8h]

  v5 = 129 * word_199994;
  v6 = v5 + dword_197F9C;
  v7 = v5 + dword_197F9C + 23;
  while ( v6 > dword_197F9C )
  {
    v6 -= 129;
    v7 -= 129;
    if ( !*(_BYTE *)(v6 + 100) )
    {
      LOWORD(v5) = *(char *)(v6 + 99);
      if ( (_WORD)v5 == a3 )
      {
        v9 = *(int16_t *)(v6 + 101);
        LOWORD(v5) = v9 + a2;
        if ( !*(_BYTE *)(v9 + a2)
          || (LOWORD(v5) = *(_WORD *)(v6 + 101), !*(_BYTE *)(a1 + v9))
          && (LOWORD(v5) = sub_1276F0(v7, 0xBu), !(_WORD)v5) )
        {
          *(_BYTE *)(v6 + 100) = 9;
        }
      }
    }
  }
  return v5;
}
// ED8B3: conditional instruction was optimized away because %var_4.1==0
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000ED8BF) --------------------------------------------------------
void __usercall sub_ED8BF(int a1)
{
  int16_t v1; // cx
  _BYTE v2[72]; // [esp+0h] [ebp-90h] BYREF
  _BYTE v3[72]; // [esp+48h] [ebp-48h] BYREF

  v1 = word_199998;
  while ( v1 > 0 )
  {
    sub_ED7A3((int)v3, (int)v2, --v1);
    sub_ED82F((int)v3, (int)v2, v1);
    sub_E6E52(a1);
  }
}
// 199998: using guessed type int16_t word_199998;


//----- (000ED908) --------------------------------------------------------
int __usercall sub_ED908(int a1, int a2)
{
  int result; // eax
  char v4; // dl
  char *v5; // ecx
  int v6; // esi
  int v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+4h] [ebp-Ch]

  v8 = (a1 - dword_197F98) / 3753;
  result = 361 * word_199996;
  v4 = 0;
  v5 = (char *)(result + dword_192B18);
  while ( (unsigned int)v5 > dword_192B18 )
  {
    v5 -= 361;
    result = *v5;
    if ( result == v8 )
    {
      v6 = 4;
      do
      {
        a2 = *((uint8_t *)&locret_ED903 + v6--);
        if ( v5[a2 + 310] )
        {
          v7 = *(int *)((char *)&dword_17EB45 + 19 * a2) / 2;
          sub_145EA((int)&v5[-dword_192B18] / 361, a2, a2);
          *(_DWORD *)(a1 + 50) += v7;
          v4 = 1;
          if ( *(_BYTE *)(a1 + 40) != 100 )
            *(_DWORD *)(a1 + 50) += (uint8_t)byte_199CB0;
        }
        result = *(int16_t *)(v5 + 277);
        if ( a2 == result )
          *(_WORD *)(v5 + 277) = -2;
      }
      while ( v6 > 0 );
    }
  }
  if ( v4 )
    return sub_E2D72((int16_t)v8, a2);
  return result;
}
// 17EB45: using guessed type int dword_17EB45;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 199CB0: using guessed type char byte_199CB0;


//----- (000ED9EC) --------------------------------------------------------
int __fastcall sub_ED9EC(char *a1, unsigned int a2)
{
  int v3; // ebx
  int v4; // eax

  v3 = *(int *)((char *)&dword_17EB45 + 19 * (int16_t)a2);
  if ( a2 < 0x14u )
  {
    if ( a2 >= 7u )
    {
      v4 = 8 * v3;
      if ( a2 > 7u )
      {
        if ( a2 < 0xCu )
          return v3;
        if ( a2 <= 0xCu )
        {
LABEL_26:
          v3 *= 7;
          return v3;
        }
        if ( a2 != 15 )
          return v3;
      }
      return v4;
    }
    if ( a2 != 2 )
      return v3;
LABEL_19:
    if ( (unsigned int)(*(char *)(dword_197F98 + 3753 * *a1 + 2207) / 2) > 1 )
      return v3;
    v4 = 8 * v3;
    if ( !(a2 == 22 ? a1[312] == 0 : a1[332] == 0) )
      return v3;
    return v4;
  }
  if ( a2 > 0x14u )
  {
    if ( a2 < 0x16u )
    {
      v3 *= 6;
      return v3;
    }
    if ( a2 > 0x16u )
    {
      if ( a2 < 0x19u )
        return v3;
      if ( a2 <= 0x19u )
      {
        v3 *= 4;
        return v3;
      }
      if ( a2 != 31 )
        return v3;
      goto LABEL_25;
    }
    goto LABEL_19;
  }
LABEL_25:
  if ( *(char *)(dword_197F98 + 3753 * *a1 + 2207) / 2 != 3 )
    goto LABEL_26;
  return v3;
}
// 17EB45: using guessed type int dword_17EB45;
// 197F98: using guessed type int dword_197F98;


//----- (000EDAE2) --------------------------------------------------------
_BOOL1 __fastcall sub_EDAE2( int a1)
{
  int v2; // eax
  _BOOL1 result; // al
  int v4; // eax

  v2 = 19 * a1;
  result = 0;
  if ( *(int16_t *)((char *)&word_17EB49 + v2) > 0 )
  {
    v4 = 13 * *(int16_t *)((char *)&word_17EB43 + v2);
    if ( byte_17E082[v4] != 3 && byte_17E082[v4] != 1 && a1 != 9 )
      return 1;
  }
  return result;
}
// 17EB43: using guessed type int16_t word_17EB43;
// 17EB49: using guessed type int16_t word_17EB49;


//----- (000EDB1D) --------------------------------------------------------
_BOOL1 __fastcall sub_EDB1D( int a1)
{
  return *(int16_t *)((char *)&word_17EB49 + 19 * a1) > 0;
}
// 17EB49: using guessed type int16_t word_17EB49;


//----- (000EDB35) --------------------------------------------------------
int __fastcall sub_EDB35(int a1, uint8_t (__fastcall *a2)(_DWORD))
{
  int result; // eax
  char *v4; // esi
  char *v5; // ebx
  int v6; // edi
  int v7; // eax
  int v8; // edi
  int v9; // [esp+0h] [ebp-34h] BYREF
  int v10; // [esp+4h] [ebp-30h]
  int v11; // [esp+8h] [ebp-2Ch]
  int v12; // [esp+Ch] [ebp-28h]
  int16_t v13; // [esp+10h] [ebp-24h]
  unsigned int v14; // [esp+14h] [ebp-20h]
  int v15; // [esp+18h] [ebp-1Ch]
  int v16; // [esp+1Ch] [ebp-18h]
  uint8_t (__fastcall *v17)(_DWORD); // [esp+20h] [ebp-14h]
  int v18; // [esp+24h] [ebp-10h]
  char *v19; // [esp+28h] [ebp-Ch]
  int v20; // [esp+2Ch] [ebp-8h]
  char v21; // [esp+30h] [ebp-4h]

  v17 = a2;
  v21 = 0;
  v20 = (a1 - dword_197F98) / 3753;
  while ( 1 )
  {
    result = *(_DWORD *)(a1 + 50) + *(int16_t *)(a1 + 178);
    if ( result >= 0 || v21 )
      return result;
    v16 = 0x7FFF;
    v4 = 0;
    v18 = 0;
    v14 = 0;
    v5 = (char *)(361 * word_199996 + dword_192B18);
LABEL_15:
    while ( (unsigned int)v5 > dword_192B18 )
    {
      v5 -= 361;
      if ( *v5 == (_WORD)v20 )
      {
        v6 = 49;
        v19 = v5 + 49;
        while ( 1 )
        {
          --v19;
          --v6;
          if ( !v19[310] || !v17((int16_t)v6) )
            goto LABEL_14;
          v7 = sub_ED9EC(v5, v6);
          if ( v7 >= v16 )
          {
            if ( v7 != v16 )
              goto LABEL_14;
            if ( sub_1247A0(++v14) != 1 )
              goto LABEL_14;
          }
          else
          {
            v14 = 1;
            v16 = v7;
          }
          v4 = v5;
          v18 = v6;
LABEL_14:
          if ( v6 <= 0 )
            goto LABEL_15;
        }
      }
    }
    if ( v4 )
    {
      v8 = *(int *)((char *)&dword_17EB45 + 19 * v18) / 2;
      v15 = 361;
      sub_145EA((int)&v4[-dword_192B18] / 361, v18, v8);
      *(_DWORD *)(a1 + 50) += v8;
      if ( *(_BYTE *)(a1 + 40) != 100 )
        *(_DWORD *)(a1 + 50) += (uint8_t)byte_199CB0;
      sub_E2A70((int)&v4[-dword_192B18] / 361, v8);
      memset(&v9, 0, 18);
      LOBYTE(v9) = 0;
      HIWORD(v9) = (uint8_t)v4[2];
      LOWORD(v10) = v18;
      HIWORD(v10) = v8;
      sub_EF629(v9, v10, v11, v12, v13, v20);
    }
    else
    {
      v21 = 1;
    }
  }
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17EB45: using guessed type int dword_17EB45;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 199CB0: using guessed type char byte_199CB0;


//----- (000EDCBF) --------------------------------------------------------
void __fastcall sub_EDCBF(int a1)
{
  int v1; // edi
  int v2; // edi
  int v3; // eax
  char v4; // bl
  int v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+4h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-8h]
  int v8; // [esp+Ch] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 50) + *(int16_t *)(a1 + 178);
  if ( v1 < 0 )
  {
    v8 = 0;
    v7 = 0;
    v6 = (a1 - dword_197F98) / 3753;
    v2 = -v1;
    while ( word_199998 > v8 && v2 )
    {
      if ( !*(_BYTE *)(v7 + dword_197F98 + 36) )
      {
        v3 = sub_1026CF(v6, v8);
        v5 = v3;
        if ( (_WORD)v3 )
        {
          if ( v2 < (int16_t)v3 )
          {
            v4 = v3 - v2;
            v2 = 0;
            sub_10278D(v6, v8, v4);
          }
          else
          {
            sub_10278D(v6, v8, 0);
            v2 -= v5;
          }
        }
      }
      v7 += 3753;
      ++v8;
    }
    sub_E2D09(v6, v2);
  }
  JUMPOUT(0xED9E5);
}
// EDD6E: control flows out of bounds to ED9E5
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000EDD73) --------------------------------------------------------
char __fastcall sub_EDD73(int a1)
{
  uint8_t v2; // al
  char v3; // bl

  v2 = *(_BYTE *)(a1 + 100);
  v3 = 0;
  if ( v2 < 2u )
  {
    if ( v2 )
      return v3;
    goto LABEL_6;
  }
  if ( v2 > 2u )
  {
    if ( v2 != 4 )
      return v3;
LABEL_6:
    if ( (((int)*(uint8_t *)(113 * *(int16_t *)(a1 + 101) + dword_19306C + 56) >> *(_BYTE *)(a1 + 99)) & 1) != 0 )
      return 1;
    return v3;
  }
  if ( (((int)*(uint8_t *)(dword_19306C
                                 + 113 * (int16_t)sub_7A3E3(*(_WORD *)(a1 + 103), *(_WORD *)(a1 + 105))
                                 + 56) >> *(_BYTE *)(a1 + 99))
      & 1) != 0 )
    return 1;
  return v3;
}
// 19306C: using guessed type int dword_19306C;


//----- (000EDDD8) --------------------------------------------------------
int __fastcall sub_EDDD8(int a1)
{
  if ( sub_EDD73(a1) )
    return (int)(*(int16_t *)(a1 + 94)
               - (__CFSHL__((uint64_t)*(int16_t *)(a1 + 94) >> 32, 2)
                + 4 * ((uint64_t)*(int16_t *)(a1 + 94) >> 32))) >> 2;
  else
    return 0;
}


//----- (000EDDF7) --------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __fastcall sub_EDDF7(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int16_t v5; // di
  int v6; // ecx
  _BYTE *v7; // ebx
  int16_t v8; // ax
  int v9; // eax
  int v10; // ebx
  int16_t v11; // si
  int16_t v12; // di
  int v13; // eax
  int16_t v14; // [esp-6h] [ebp-32h] BYREF
  int v15; // [esp+0h] [ebp-2Ch]
  int v16; // [esp+4h] [ebp-28h] BYREF
  int v17; // [esp+8h] [ebp-24h]
  int v18; // [esp+Ch] [ebp-20h]
  int v19; // [esp+10h] [ebp-1Ch]
  int16_t v20; // [esp+14h] [ebp-18h]
  int v21; // [esp+18h] [ebp-14h]
  int v22; // [esp+1Ch] [ebp-10h]
  char v23; // [esp+20h] [ebp-Ch]
  char v24; // [esp+24h] [ebp-8h]
  char v25; // [esp+28h] [ebp-4h]

  v24 = a2;
  v25 = a3;
  v21 = a4;
  v23 = 0;
  v22 = (a1 - dword_197F98) / 3753;
  while ( 1 )
  {
    result = *(_DWORD *)(v15 + 50) + *(int16_t *)(v15 + 178);
    if ( result >= 0 || v23 )
      break;
    v5 = 0x7FFF;
    v6 = 0;
    v7 = (_BYTE *)(129 * word_199994 + dword_197F9C);
    while ( (unsigned int)v7 > dword_197F9C )
    {
      v8 = (char)*(v7 - 30);
      v7 -= 129;
      if ( v8 == (_WORD)v22
        && (uint8_t)v7[17] == (_WORD)v21
        && (char)v7[100] < 3
        && (!v24 || sub_EDD73((int)v7))
        && (!v25 || !v7[127] || v7[127] == 3 || v7[127] == 7)
        && *(int16_t *)(dword_1AA3F0 + 4 * ((int)&v7[-dword_197F9C] / 129)) < v5 )
      {
        v5 = *(_WORD *)(dword_1AA3F0 + 4 * ((int)&v7[-dword_197F9C] / 129));
        v6 = (int)v7;
      }
    }
    if ( v6 )
    {
      if ( sub_EDD73(v6) )
        v9 = (int)(*(int16_t *)(v6 + 94)
                 - (__CFSHL__((uint64_t)*(int16_t *)(v6 + 94) >> 32, 2)
                  + 4 * ((uint64_t)*(int16_t *)(v6 + 94) >> 32))) >> 2;
      else
        v9 = 0;
      v10 = v15;
      *(_DWORD *)(v15 + 50) += v9;
      v11 = v9;
      if ( *(_BYTE *)(v10 + 40) != 100 )
        *(_DWORD *)(v10 + 50) += (uint8_t)byte_199CB0;
      v12 = v22;
      sub_E2D09(v22, (int16_t)v22);
      memset(&v16, 0, 18);
      LOBYTE(v16) = 6;
      HIWORD(v16) = *(_WORD *)(v6 + 101);
      LOWORD(v17) = v11;
      HIWORD(v17) = (v6 - dword_197F9C) / 129;
      sub_EF629(v16, v17, v18, v19, v20, v12);
      v13 = *(int16_t *)(v6 + 116);
      *(_BYTE *)(v6 + 100) = 7;
      if ( v13 != -1 )
      {
        sub_944A3(v13, (int)&v14);
        *(_WORD *)(v6 + 116) = -1;
      }
      sub_8A4C4();
    }
    else
    {
      v23 = 1;
    }
  }
  return result;
}
// EDF79: bad sp value at call
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199CB0: using guessed type char byte_199CB0;
// 1AA3F0: using guessed type int dword_1AA3F0;


//----- (000EDF92) --------------------------------------------------------
void __usercall sub_EDF92(int a1)
{
  unsigned int v1; // ebx

  v1 = 129 * word_199994 + dword_197F9C;
  while ( v1 > dword_197F9C )
  {
    v1 -= 129;
    if ( *(_BYTE *)(v1 + 100) == 7 || *(_BYTE *)(v1 + 100) == 8 )
      sub_A163A((int)(v1 - dword_197F9C) / 129, a1);
  }
}
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000EDFE0) --------------------------------------------------------
void __fastcall sub_EDFE0(int a1)
{
  int v2; // edi
  int16_t v3; // si
  int v4; // eax
  int16_t v5; // bx
  int v6[4]; // [esp+0h] [ebp-20h] BYREF
  int16_t v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+14h] [ebp-Ch]
  int v9; // [esp+18h] [ebp-8h]
  char v10; // [esp+1Ch] [ebp-4h]

  v10 = 0;
  v8 = (a1 - dword_197F98) / 3753;
  while ( 1 )
  {
LABEL_2:
    if ( *(_DWORD *)(a1 + 50) + *(int16_t *)(a1 + 178) >= 0 || v10 )
      JUMPOUT(0xED9E5);
    v10 = 1;
    v9 = 67;
    v2 = 3953;
    v3 = v8;
    while ( 1 )
    {
      if ( v9 <= 0 )
        goto LABEL_2;
      --v9;
      v4 = *(char *)(v2 + dword_1930DC - 1);
      v2 -= 59;
      if ( v4 == v8 )
      {
        v5 = v9;
        if ( (int16_t)sub_94A9D(v3, v9) > 0 )
          break;
      }
    }
    sub_933F2(v5);
    sub_E2D72((int16_t)((a1 - dword_197F98) / 3753), v2);
    memset(v6, 0, 18);
    LOBYTE(v6[0]) = 22;
    BYTE2(v6[0]) = v9;
    v10 = 0;
    sub_EF629(v6[0], v6[1], v6[2], v6[3], v7, v3);
  }
}
// EE00C: control flows out of bounds to ED9E5
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (000EE0B0) --------------------------------------------------------
void __usercall sub_EE0B0(int a1, int a2)
{
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // edi
  int v12; // edi
  int v13; // ebx
  int v14; // ebx
  uint16_t v15; // ax
  int v16; // eax
  _BYTE v17[2000]; // [esp+0h] [ebp-7F4h] BYREF
  _BYTE v18[8]; // [esp+7D0h] [ebp-24h] BYREF
  int v19; // [esp+7D8h] [ebp-1Ch]
  int v20; // [esp+7DCh] [ebp-18h]
  int v21; // [esp+7E0h] [ebp-14h]
  int v22; // [esp+7E4h] [ebp-10h]
  int v23; // [esp+7E8h] [ebp-Ch]
  int v24; // [esp+7ECh] [ebp-8h]
  int v25; // [esp+7F0h] [ebp-4h]

  if ( *(_BYTE *)(a1 + 1437) )
    sub_ED908(a1, a2);
  if ( *(_DWORD *)(a1 + 50) + *(int16_t *)(a1 + 178) < 0 )
  {
    memset(v17, 0, sizeof(v17));
    dword_1AA3F0 = (int)v17;
    memset(v18, 0, sizeof(v18));
    v3 = 0;
    v4 = word_199998;
    v5 = (a1 - dword_197F98) / 3753;
    v6 = word_199998 + a1;
    while ( v4 > 0 )
    {
      --v4;
      --v6;
      if ( v4 != v5 && *(_BYTE *)(v6 + 1412) )
      {
        ++v3;
        v18[v4] = 1;
      }
    }
    if ( !v3 )
    {
      v7 = word_199998;
      v24 = (a1 - dword_197F98) / 3753;
      v8 = 3753 * word_199998;
      while ( v7 > 0 )
      {
        --v7;
        v8 -= 3753;
        if ( v7 != v24 && !*(_BYTE *)(v8 + dword_197F98 + 36) && *(_BYTE *)(v8 + dword_197F98 + 40) == 100 )
        {
          ++v3;
          v18[v7] = 1;
        }
      }
      if ( !v3 )
      {
        v9 = word_199998;
        v22 = (a1 - dword_197F98) / 3753;
        v10 = dword_197F98;
        v11 = 3753 * word_199998;
        while ( v9 > 0 )
        {
          --v9;
          v11 -= 3753;
          if ( v9 != v22 && !*(_BYTE *)(v11 + v10 + 36) )
          {
            ++v3;
            v18[v9] = 1;
          }
        }
      }
    }
    if ( v3 )
    {
      v12 = word_199994;
      v20 = 4 * word_199994;
      v21 = 129 * word_199994;
      while ( v12 > 0 )
      {
        v21 -= 129;
        v13 = v21 + dword_197F9C;
        v23 = *(char *)(v21 + dword_197F9C + 99);
        v25 = 3753;
        v20 -= 4;
        --v12;
        if ( (a1 - dword_197F98) / 3753 == v23 && *(char *)(v13 + 100) < 5 && !*(_BYTE *)(v13 + 17) )
        {
          v14 = word_199998;
          v19 = v20;
          while ( v14 > 0 )
          {
            if ( v18[--v14] )
            {
              v25 = dword_1AA3F0 + v19;
              sub_5EF17(v12, v14);
              *(_DWORD *)v25 += v15;
            }
          }
          v16 = *(_DWORD *)(v19 + dword_1AA3F0);
          v25 = (*(uint8_t *)(v21 + dword_197F9C + 16) + 1) * v3;
          *(_DWORD *)(v19 + dword_1AA3F0) = v16 / v25;
        }
      }
    }
    if ( 4 * *(int16_t *)(a1 + 58) / 3 < *(int16_t *)(a1 + 60) )
    {
      sub_EDDF7(a1, 1, 1, 4);
      sub_EDDF7(a1, 1, 0, 4);
      sub_EDDF7(a1, 1, 1, 2);
      sub_EDDF7(a1, 1, 1, 0);
      sub_EDDF7(a1, 0, 1, 4);
      sub_EDDF7(a1, 0, 0, 4);
      sub_EDDF7(a1, 0, 1, 2);
      sub_EDDF7(a1, 0, 1, 0);
    }
    sub_EDB35(a1, (uint8_t (__fastcall *)(_DWORD))sub_EDAE2);
    sub_EDDF7(a1, 1, 1, 4);
    sub_EDDF7(a1, 1, 0, 4);
    sub_EDDF7(a1, 0, 1, 4);
    sub_EDDF7(a1, 0, 0, 4);
    sub_EDDF7(a1, 1, 1, 2);
    sub_EDDF7(a1, 1, 1, 0);
    sub_EDDF7(a1, 0, 1, 2);
    sub_EDDF7(a1, 0, 1, 0);
    sub_EDB35(a1, (uint8_t (__fastcall *)(_DWORD))sub_EDB1D);
    sub_EDDF7(a1, 1, 0, 2);
    sub_EDDF7(a1, 0, 0, 2);
    sub_EDDF7(a1, 1, 1, 1);
    sub_EDDF7(a1, 0, 1, 1);
    sub_EDDF7(a1, 1, 0, 1);
    sub_EDDF7(a1, 0, 0, 1);
    sub_EDCBF(a1);
    sub_EDDF7(a1, 1, 0, 0);
    sub_EDDF7(a1, 0, 0, 0);
    sub_EDFE0(a1);
    sub_EDB35(a1, (uint8_t (__fastcall *)(_DWORD))&off_EDB2D);
    dword_1AA3F0 = 0;
  }
  JUMPOUT(0xED9E5);
}
// EE49C: control flows out of bounds to ED9E5
// EE26D: variable 'v15' is possibly undefined
// EDB2D: using guessed type _UNKNOWN *off_EDB2D;
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199998: using guessed type int16_t word_199998;
// 1AA3F0: using guessed type int dword_1AA3F0;


//----- (000EE4A1) --------------------------------------------------------
unsigned int __fastcall sub_EE4A1(char *a1)
{
  dword_1AAC50 = (int)a1;
  dword_1AAC28 = (int)&a1[strlen(a1) + 1];
  dword_1AABFC = strlen((char *)dword_1AAC28) + 1 + dword_1AAC28;
  dword_1AAC38 = strlen((char *)dword_1AABFC) + 1 + dword_1AABFC;
  dword_1AAC24 = strlen((char *)dword_1AAC38) + 1 + dword_1AAC38;
  dword_1AABF8 = strlen((char *)dword_1AAC24) + 1 + dword_1AAC24;
  dword_1AAC40 = strlen((char *)dword_1AABF8) + 1 + dword_1AABF8;
  dword_1AA404[0] = strlen((char *)dword_1AAC40) + 1 + dword_1AAC40;
  dword_1AA408 = strlen((char *)dword_1AA404) + 1 + dword_1AA404;
  dword_1AAC34 = strlen((char *)dword_1AA408) + 1 + dword_1AA408;
  dword_1AAC0C = strlen((char *)dword_1AAC34) + 1 + dword_1AAC34;
  dword_1AAC44 = strlen((char *)dword_1AAC0C) + 1 + dword_1AAC0C;
  dword_1AAC3C = strlen((char *)dword_1AAC44) + 1 + dword_1AAC44;
  dword_1AABF0 = strlen((char *)dword_1AAC3C) + 1 + dword_1AAC3C;
  dword_1AAC10 = strlen((char *)dword_1AABF0) + 1 + dword_1AABF0;
  dword_1AAC2C = strlen((char *)dword_1AAC10) + 1 + dword_1AAC10;
  dword_1AAC04 = strlen((char *)dword_1AAC2C) + 1 + dword_1AAC2C;
  dword_1AAC20 = strlen((char *)dword_1AAC04) + 1 + dword_1AAC04;
  dword_1AAC18 = strlen((char *)dword_1AAC20) + 1 + dword_1AAC20;
  dword_1AAC30 = strlen((char *)dword_1AAC18) + 1 + dword_1AAC18;
  dword_1AAC1C = strlen((char *)dword_1AAC30) + 1 + dword_1AAC30;
  dword_1AABF4 = strlen((char *)dword_1AAC1C) + 1 + dword_1AAC1C;
  dword_1AAC4C = strlen((char *)dword_1AABF4) + 1 + dword_1AABF4;
  dword_1AAC14 = strlen((char *)dword_1AAC4C) + 1 + dword_1AAC4C;
  dword_1AAC08 = strlen((char *)dword_1AAC14) + 1 + dword_1AAC14;
  dword_1AAC48 = strlen((char *)dword_1AAC08) + 1 + dword_1AAC08;
  dword_1AAC00 = strlen((char *)dword_1AAC48) + 1 + dword_1AAC48;
  dword_1AABB0 = strlen((char *)dword_1AAC00) + 1 + dword_1AAC00;
  dword_1AABC4 = strlen((char *)dword_1AABB0) + 1 + dword_1AABB0;
  dword_1AABE0 = strlen((char *)dword_1AABC4) + 1 + dword_1AABC4;
  dword_1AABEC = strlen((char *)dword_1AABE0) + 1 + dword_1AABE0;
  dword_1AABC0 = strlen((char *)dword_1AABEC) + 1 + dword_1AABEC;
  dword_1AABA8 = strlen((char *)dword_1AABC0) + 1 + dword_1AABC0;
  dword_1AAB98 = strlen((char *)dword_1AABA8) + 1 + dword_1AABA8;
  dword_1AABE4 = strlen((char *)dword_1AAB98) + 1 + dword_1AAB98;
  dword_1AABD0 = strlen((char *)dword_1AABE4) + 1 + dword_1AABE4;
  dword_1AABD4 = strlen((char *)dword_1AABD0) + 1 + dword_1AABD0;
  dword_1AAB8C = strlen((char *)dword_1AABD4) + 1 + dword_1AABD4;
  dword_1AAB9C = strlen((char *)dword_1AAB8C) + 1 + dword_1AAB8C;
  dword_1AABAC = strlen((char *)dword_1AAB9C) + 1 + dword_1AAB9C;
  dword_1AABE8 = strlen((char *)dword_1AABAC) + 1 + dword_1AABAC;
  dword_1AABB8 = strlen((char *)dword_1AABE8) + 1 + dword_1AABE8;
  dword_1AAB94 = strlen((char *)dword_1AABB8) + 1 + dword_1AABB8;
  dword_1AABB4 = strlen((char *)dword_1AAB94) + 1 + dword_1AAB94;
  dword_1AABD8 = strlen((char *)dword_1AABB4) + 1 + dword_1AABB4;
  dword_1AABBC = strlen((char *)dword_1AABD8) + 1 + dword_1AABD8;
  dword_1AAB90 = strlen((char *)dword_1AABBC) + 1 + dword_1AABBC;
  dword_1AABC8 = strlen((char *)dword_1AAB90) + 1 + dword_1AAB90;
  dword_1AABCC = strlen((char *)dword_1AABC8) + 1 + dword_1AABC8;
  dword_1AABA4 = strlen((char *)dword_1AABCC) + 1 + dword_1AABCC;
  dword_1AABDC = strlen((char *)dword_1AABA4) + 1 + dword_1AABA4;
  dword_1AABA0 = strlen((char *)dword_1AABDC) + 1 + dword_1AABDC;
  dword_1AAB84 = strlen((char *)dword_1AABA0) + 1 + dword_1AABA0;
  dword_1AAB38 = strlen((char *)dword_1AAB84) + 1 + dword_1AAB84;
  dword_1AAB30 = strlen((char *)dword_1AAB38) + 1 + dword_1AAB38;
  dword_1AAB3C = strlen((char *)dword_1AAB30) + 1 + dword_1AAB30;
  dword_1AAB6C = strlen((char *)dword_1AAB3C) + 1 + dword_1AAB3C;
  dword_1AAB88 = strlen((char *)dword_1AAB6C) + 1 + dword_1AAB6C;
  dword_1AAB7C = strlen((char *)dword_1AAB88) + 1 + dword_1AAB88;
  dword_1AAB48[0] = strlen((char *)dword_1AAB7C) + 1 + dword_1AAB7C;
  dword_1AAB4C = strlen((char *)dword_1AAB48) + 1 + dword_1AAB48;
  dword_1AAB50 = strlen((char *)dword_1AAB4C) + 1 + dword_1AAB4C;
  dword_1AAB54 = strlen((char *)dword_1AAB50) + 1 + dword_1AAB50;
  dword_1AAB58 = strlen((char *)dword_1AAB54) + 1 + dword_1AAB54;
  dword_1AAB34 = strlen((char *)dword_1AAB58) + 1 + dword_1AAB58;
  dword_1AAB80 = strlen((char *)dword_1AAB34) + 1 + dword_1AAB34;
  dword_1AAB40 = strlen((char *)dword_1AAB80) + 1 + dword_1AAB80;
  dword_1AAB2C = strlen((char *)dword_1AAB40) + 1 + dword_1AAB40;
  dword_1AAB44 = strlen((char *)dword_1AAB2C) + 1 + dword_1AAB2C;
  dword_1AAB5C[0] = strlen((char *)dword_1AAB44) + 1 + dword_1AAB44;
  dword_1AAB60 = strlen((char *)dword_1AAB5C) + 1 + dword_1AAB5C;
  dword_1AAB64 = strlen((char *)dword_1AAB60) + 1 + dword_1AAB60;
  dword_1AAB68 = strlen((char *)dword_1AAB64) + 1 + dword_1AAB64;
  dword_1AAB70[0] = strlen((char *)dword_1AAB68) + 1 + dword_1AAB68;
  dword_1AAB74 = strlen((char *)dword_1AAB70) + 1 + dword_1AAB70;
  dword_1AAB78 = strlen((char *)dword_1AAB74) + 1 + dword_1AAB74;
  dword_1AA3F4[0] = strlen((char *)dword_1AAB78) + 1 + dword_1AAB78;
  dword_1AA3F8 = strlen((char *)dword_1AA3F4) + 1 + dword_1AA3F4;
  dword_1AA3FC = strlen((char *)dword_1AA3F8) + 1 + dword_1AA3F8;
  dword_1AA400 = strlen((char *)dword_1AA3FC) + 1 + dword_1AA3FC;
  return dword_1AA400 + strlen((char *)dword_1AA400) + 1;
}
// 1AA3F4: using guessed type int dword_1AA3F4;
// 1AA3F8: using guessed type int dword_1AA3F8;
// 1AA3FC: using guessed type int dword_1AA3FC;
// 1AA400: using guessed type int dword_1AA400;
// 1AA404: using guessed type int dword_1AA404;
// 1AA408: using guessed type int dword_1AA408;
// 1AAB2C: using guessed type int dword_1AAB2C;
// 1AAB30: using guessed type int dword_1AAB30;
// 1AAB34: using guessed type int dword_1AAB34;
// 1AAB38: using guessed type int dword_1AAB38;
// 1AAB3C: using guessed type int dword_1AAB3C;
// 1AAB40: using guessed type int dword_1AAB40;
// 1AAB44: using guessed type int dword_1AAB44;
// 1AAB48: using guessed type int dword_1AAB48;
// 1AAB4C: using guessed type int dword_1AAB4C;
// 1AAB50: using guessed type int dword_1AAB50;
// 1AAB54: using guessed type int dword_1AAB54;
// 1AAB58: using guessed type int dword_1AAB58;
// 1AAB5C: using guessed type int dword_1AAB5C;
// 1AAB60: using guessed type int dword_1AAB60;
// 1AAB64: using guessed type int dword_1AAB64;
// 1AAB68: using guessed type int dword_1AAB68;
// 1AAB6C: using guessed type int dword_1AAB6C;
// 1AAB70: using guessed type int dword_1AAB70;
// 1AAB74: using guessed type int dword_1AAB74;
// 1AAB78: using guessed type int dword_1AAB78;
// 1AAB7C: using guessed type int dword_1AAB7C;
// 1AAB80: using guessed type int dword_1AAB80;
// 1AAB84: using guessed type int dword_1AAB84;
// 1AAB88: using guessed type int dword_1AAB88;
// 1AAB8C: using guessed type int dword_1AAB8C;
// 1AAB90: using guessed type int dword_1AAB90;
// 1AAB94: using guessed type int dword_1AAB94;
// 1AAB98: using guessed type int dword_1AAB98;
// 1AAB9C: using guessed type int dword_1AAB9C;
// 1AABA0: using guessed type int dword_1AABA0;
// 1AABA4: using guessed type int dword_1AABA4;
// 1AABA8: using guessed type int dword_1AABA8;
// 1AABAC: using guessed type int dword_1AABAC;
// 1AABB0: using guessed type int dword_1AABB0;
// 1AABB4: using guessed type int dword_1AABB4;
// 1AABB8: using guessed type int dword_1AABB8;
// 1AABBC: using guessed type int dword_1AABBC;
// 1AABC0: using guessed type int dword_1AABC0;
// 1AABC4: using guessed type int dword_1AABC4;
// 1AABC8: using guessed type int dword_1AABC8;
// 1AABCC: using guessed type int dword_1AABCC;
// 1AABD0: using guessed type int dword_1AABD0;
// 1AABD4: using guessed type int dword_1AABD4;
// 1AABD8: using guessed type int dword_1AABD8;
// 1AABDC: using guessed type int dword_1AABDC;
// 1AABE0: using guessed type int dword_1AABE0;
// 1AABE4: using guessed type int dword_1AABE4;
// 1AABE8: using guessed type int dword_1AABE8;
// 1AABEC: using guessed type int dword_1AABEC;
// 1AABF0: using guessed type int dword_1AABF0;
// 1AABF4: using guessed type int dword_1AABF4;
// 1AABF8: using guessed type int dword_1AABF8;
// 1AABFC: using guessed type int dword_1AABFC;
// 1AAC00: using guessed type int dword_1AAC00;
// 1AAC04: using guessed type int dword_1AAC04;
// 1AAC08: using guessed type int dword_1AAC08;
// 1AAC0C: using guessed type int dword_1AAC0C;
// 1AAC10: using guessed type int dword_1AAC10;
// 1AAC14: using guessed type int dword_1AAC14;
// 1AAC18: using guessed type int dword_1AAC18;
// 1AAC1C: using guessed type int dword_1AAC1C;
// 1AAC20: using guessed type int dword_1AAC20;
// 1AAC24: using guessed type int dword_1AAC24;
// 1AAC28: using guessed type int dword_1AAC28;
// 1AAC2C: using guessed type int dword_1AAC2C;
// 1AAC30: using guessed type int dword_1AAC30;
// 1AAC34: using guessed type int dword_1AAC34;
// 1AAC38: using guessed type int dword_1AAC38;
// 1AAC3C: using guessed type int dword_1AAC3C;
// 1AAC40: using guessed type int dword_1AAC40;
// 1AAC44: using guessed type int dword_1AAC44;
// 1AAC48: using guessed type int dword_1AAC48;
// 1AAC4C: using guessed type int dword_1AAC4C;
// 1AAC50: using guessed type int dword_1AAC50;


//----- (000EEB3A) --------------------------------------------------------
int sub_EEB3A()
{
  int v0; // esi
  int v1; // ebx
  int v2; // ecx
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  v0 = 0;
  v1 = 0;
  v2 = 0;
  while ( v1 < word_199998 )
  {
    if ( !*(_BYTE *)(v2 + dword_197F98 + 36) )
      ++v0;
    v2 += 3753;
    ++v1;
  }
  memset(byte_1AA40C, 0, sizeof(byte_1AA40C));
  memset(byte_1AAB24, 0, sizeof(byte_1AAB24));
  v3 = 100;
  memset(&byte_1AAB1C, 0, 8);
  v4 = 0;
  v5 = 0;
  for ( i = 0; ; i += 3753 )
  {
    result = word_199998;
    if ( v4 >= word_199998 )
      break;
    if ( !*(_BYTE *)(i + dword_197F98 + 36) )
    {
      byte_1AA40C[v4] = v5 / v0;
      v6 = v3 / v0;
      v5 += 100;
      v3 += 100;
      byte_1AAB24[v4] = v6 - byte_1AA40C[v4];
    }
    ++v4;
  }
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 1AAB1C: using guessed type char byte_1AAB1C;


//----- (000EEBF8) --------------------------------------------------------
int16_t __fastcall sub_EEBF8( int a1)
{
  return (uint8_t)byte_1AA40C[a1];
}


//----- (000EEC02) --------------------------------------------------------
int16_t __fastcall sub_EEC02( int a1)
{
  return (uint8_t)byte_1AAB1C[a1];
}


//----- (000EEC98) --------------------------------------------------------
char __fastcall sub_EEC98(int64_t a1)
{
  int v1; // ecx
  int v2; // esi
  char *v3; // eax
  char *v4; // eax
  char *v5; // esi
  char *v6; // edx
  int v7; // eax
  char *v8; // edi
  int v9; // eax
  char *v10; // eax
  char *v11; // edi
  char *v12; // esi
  int v13; // eax
  int v15; // [esp-10h] [ebp-5Eh]
  int v16; // [esp-Ch] [ebp-5Ah]
  char *v17; // [esp-8h] [ebp-56h]
  int v18; // [esp-8h] [ebp-56h]
  char *v19; // [esp-8h] [ebp-56h]
  int v20; // [esp-8h] [ebp-56h]
  int v21; // [esp-4h] [ebp-52h]
  int v22; // [esp-4h] [ebp-52h]
  char *v23; // [esp-4h] [ebp-52h]
  int v24; // [esp-4h] [ebp-52h]
  int v25; // [esp-4h] [ebp-52h]
  int v26; // [esp-4h] [ebp-52h]
  int v27; // [esp-4h] [ebp-52h]
  int v28; // [esp-4h] [ebp-52h]
  char *v29; // [esp+0h] [ebp-4Eh]
  _BYTE v30[200]; // [esp+4h] [ebp-4Ah] BYREF
  char v31[52]; // [esp+CCh] [ebp+7Eh] BYREF
  char v32[20]; // [esp+100h] [ebp+B2h] BYREF

  v1 = HIDWORD(a1);
  LOBYTE(a1) = *(_BYTE *)HIDWORD(a1);
  switch ( *(_BYTE *)HIDWORD(a1) )
  {
    case 0:
      LODWORD(a1) = sub_77B28(*(uint8_t *)(HIDWORD(a1) + 2));
      switch ( *(_BYTE *)(HIDWORD(a1) + 3) )
      {
        case 0:
          LOBYTE(a1) = sprintf(
                         v29,
                         (char *)dword_1AAC44,
                         *(_UNKNOWN **)((char *)&off_17EB3D + 19 * *(int16_t *)(HIDWORD(a1) + 4)),
                         (_DWORD)a1,
                         *(int16_t *)(HIDWORD(a1) + 6));
          return a1;
        case 1:
          WORD2(a1) = *(_WORD *)(HIDWORD(a1) + 4);
          if ( SWORD2(a1) <= 0 || SWORD2(a1) >= 49 )
          {
            if ( SWORD2(a1) > -100 )
            {
              if ( WORD2(a1) < 0xFFFAu )
              {
                if ( WORD2(a1) >= 0xFFF1u )
                {
                  if ( WORD2(a1) <= 0xFFF1u )
                  {
                    sprintf(v29, (char *)dword_1AAC30, (_DWORD)a1);
                  }
                  else if ( WORD2(a1) == 0xFFF9 )
                  {
                    sprintf(v29, (char *)dword_1AAC2C, (_DWORD)a1);
                  }
                }
              }
              else if ( WORD2(a1) <= 0xFFFAu )
              {
                sprintf(v29, (char *)dword_1AAC18, (_DWORD)a1);
              }
              else if ( WORD2(a1) <= 0xFFFBu )
              {
                sprintf(v29, (char *)dword_1AAC20, (_DWORD)a1);
              }
              else if ( WORD2(a1) == 0xFFFC )
              {
                sprintf(v29, (char *)dword_1AAC04, (_DWORD)a1);
              }
            }
            else
            {
              if ( *(_BYTE *)(v1 + 8) )
                v5 = (char *)dword_1AAC10;
              else
                v5 = (char *)dword_1AABF0;
              sprintf(v29, v5, (_DWORD)a1, -129 * (SWORD2(a1) + 100) + dword_197F9C);
            }
          }
          else
          {
            sprintf(v29, (char *)dword_1AAC3C, (_DWORD)a1, *(_UNKNOWN **)((char *)&off_17EB3D + 19 * SWORD2(a1)));
          }
          LODWORD(a1) = *(int16_t *)(v1 + 6);
          if ( (_DWORD)a1 != -1 )
          {
            if ( *(_BYTE *)(v1 + 9) )
              v6 = (char *)dword_1AABF4;
            else
              v6 = (char *)dword_1AAC1C;
            v23 = sub_CF398(*(_WORD *)(v1 + 6));
            LOBYTE(a1) = sprintf(&v29[strlen(v29)], v6, v23);
          }
          return a1;
        case 2:
          v24 = a1;
          if ( *(uint8_t *)(HIDWORD(a1) + 4) >= word_199998 )
            v7 = dword_1AAC50;
          else
            v7 = dword_197F98 + 3753 * *(uint8_t *)(HIDWORD(a1) + 4) + 21;
          LOBYTE(a1) = sprintf(v29, (char *)dword_1AAC4C, v7, v24);
          return a1;
        case 3:
          LOBYTE(a1) = sprintf(
                         v29,
                         (char *)dword_1AAC14,
                         3753 * (unsigned int)*(uint8_t *)(HIDWORD(a1) + 4) + dword_197F98 + 21,
                         (_DWORD)a1);
          return a1;
        case 4:
          if ( *(_BYTE *)(HIDWORD(a1) + 4) )
          {
            if ( *(_BYTE *)(HIDWORD(a1) + 5) )
              LOBYTE(a1) = sprintf(
                             v29,
                             (char *)dword_1AAC00,
                             (_DWORD)a1,
                             *(uint8_t *)(HIDWORD(a1) + 4),
                             *(uint8_t *)(HIDWORD(a1) + 5));
            else
              LOBYTE(a1) = sprintf(v29, (char *)dword_1AAC08, (_DWORD)a1, *(uint8_t *)(HIDWORD(a1) + 4));
          }
          else
          {
            LOBYTE(a1) = sprintf(v29, (char *)dword_1AAC48, (_DWORD)a1, *(uint8_t *)(HIDWORD(a1) + 5));
          }
          return a1;
        case 5:
          v18 = *(uint8_t *)(HIDWORD(a1) + 4);
          if ( *(_BYTE *)(HIDWORD(a1) + 4) == 1 )
            LODWORD(a1) = sprintf(v29, (char *)dword_1AABB0, v18, (_DWORD)a1);
          else
            LODWORD(a1) = sprintf(v29, (char *)dword_1AABC4, v18, (_DWORD)a1);
          HIDWORD(a1) = a1;
          if ( *(_BYTE *)(v1 + 6) )
          {
            v8 = (char *)&v29[a1 - 1];
            do
              ++v8;
            while ( *v8 );
            strcpy(v8, (char *)dword_1AABE0);
            return a1;
          }
          if ( !*(_BYTE *)(v1 + 5) )
            return a1;
          v21 = *(uint8_t *)(v1 + 5);
          if ( *(_BYTE *)(v1 + 5) == 1 )
            v9 = dword_1AABEC;
          else
            v9 = dword_1AABC0;
          v17 = (char *)v9;
          LODWORD(a1) = v29;
          break;
        case 6:
          v25 = a1;
          v19 = (char *)dword_1AABA8;
          goto LABEL_67;
        case 7:
          v25 = a1;
          v19 = (char *)dword_1AAB98;
          goto LABEL_67;
        case 8:
          v25 = a1;
          v19 = (char *)dword_1AABE4;
          goto LABEL_67;
        case 9:
          if ( *(uint8_t *)(HIDWORD(a1) + 4) == word_19999C )
          {
            BYTE4(a1) = *(_BYTE *)(HIDWORD(a1) + 6);
            if ( BYTE4(a1) >= *(_BYTE *)(v1 + 5) )
              LOBYTE(a1) = sprintf(v29, (char *)dword_1AABD4, *(uint8_t *)(v1 + 5), (_DWORD)a1);
            else
              LOBYTE(a1) = sprintf(v29, (char *)dword_1AABD0, *(uint8_t *)(v1 + 5), (_DWORD)a1, BYTE4(a1));
          }
          else
          {
            BYTE4(a1) = *(_BYTE *)(HIDWORD(a1) + 6);
            if ( BYTE4(a1) >= *(_BYTE *)(v1 + 5) )
            {
              v26 = a1;
              if ( *(_BYTE *)(v1 + 5) == 1 )
                v10 = (char *)dword_1AABAC;
              else
                v10 = (char *)dword_1AABE8;
              LOBYTE(a1) = sprintf(
                             v29,
                             v10,
                             *(uint8_t *)(v1 + 5),
                             dword_197F98 + 3753 * (unsigned int)*(uint8_t *)(v1 + 4) + 21,
                             v26);
            }
            else
            {
              v16 = 3753 * *(uint8_t *)(v1 + 4) + dword_197F98 + 21;
              v15 = *(uint8_t *)(v1 + 5);
              if ( *(_BYTE *)(v1 + 5) == 1 )
                LOBYTE(a1) = sprintf(v29, (char *)dword_1AAB8C, v15, v16, (_DWORD)a1, BYTE4(a1));
              else
                LOBYTE(a1) = sprintf(v29, (char *)dword_1AAB9C, v15, v16, (_DWORD)a1, BYTE4(a1));
            }
          }
          return a1;
        case 0xA:
          v25 = a1;
          v19 = (char *)dword_1AABB8;
          goto LABEL_67;
        case 0xB:
          if ( *(_BYTE *)(HIDWORD(a1) + 4) >= 8u )
            HIDWORD(a1) = dword_1AAC50;
          else
            HIDWORD(a1) = dword_197F98 + 3753 * *(uint8_t *)(HIDWORD(a1) + 4) + 21;
          LOBYTE(a1) = sprintf(v29, (char *)dword_1AAB94, a1);
          return a1;
        default:
          return a1;
      }
      goto LABEL_64;
    case 1:
      LOBYTE(a1) = sprintf(
                     v29,
                     (char *)dword_1AAC28,
                     3753 * *(int16_t *)(HIDWORD(a1) + 2) + dword_197F98 + 21,
                     3753 * *(int16_t *)(HIDWORD(a1) + 4) + dword_197F98 + 21);
      return a1;
    case 2:
      LOBYTE(a1) = sprintf(
                     v29,
                     (char *)dword_1AABFC,
                     dword_197F98 + 3753 * *(int16_t *)(HIDWORD(a1) + 2) + 21,
                     dword_197F98 + 3753 * *(int16_t *)(HIDWORD(a1) + 4) + 21);
      return a1;
    case 4:
      LOBYTE(a1) = sprintf(
                     v29,
                     (char *)dword_1AAC38,
                     *(int16_t *)(HIDWORD(a1) + 2),
                     *(int16_t *)(HIDWORD(a1) + 4));
      return a1;
    case 5:
      v2 = sprintf(
             v29,
             (char *)dword_1AAC24,
             *(&off_18003A + 9 * *(uint8_t *)(dword_197F9C + 129 * *(int16_t *)(HIDWORD(a1) + 4) + 16)),
             dword_197F9C + 129 * *(int16_t *)(HIDWORD(a1) + 4),
             *(int16_t *)(129 * *(int16_t *)(HIDWORD(a1) + 4) + dword_197F9C + 94),
             113 * *(int16_t *)(HIDWORD(a1) + 2) + dword_19306C);
      LODWORD(a1) = *(char *)(v1 + 6);
      if ( (_DWORD)a1 == -1 )
        return a1;
      v21 = dword_1930DC + 59 * *(char *)(v1 + 6);
      v17 = (char *)dword_1AAB70[*(char *)(v1 + 7)];
      v3 = v29;
      goto LABEL_8;
    case 6:
      if ( *(int16_t *)(HIDWORD(a1) + 2) >= word_19999A )
        LOBYTE(a1) = sprintf(
                       v29,
                       (char *)dword_1AAC40,
                       *(&off_18003A + 9 * *(uint8_t *)(dword_197F9C + 129 * *(int16_t *)(HIDWORD(a1) + 6) + 16)),
                       dword_197F9C + 129 * *(int16_t *)(HIDWORD(a1) + 6),
                       *(int16_t *)(dword_197F9C + 129 * *(int16_t *)(HIDWORD(a1) + 6) + 94));
      else
        LOBYTE(a1) = sprintf(
                       v29,
                       (char *)dword_1AABF8,
                       *(&off_18003A + 9 * *(uint8_t *)(dword_197F9C + 129 * *(int16_t *)(HIDWORD(a1) + 6) + 16)),
                       dword_197F9C + 129 * *(int16_t *)(HIDWORD(a1) + 6),
                       *(int16_t *)(dword_197F9C + 129 * *(int16_t *)(HIDWORD(a1) + 6) + 94),
                       dword_19306C + 113 * *(int16_t *)(HIDWORD(a1) + 2),
                       *(int16_t *)(HIDWORD(a1) + 4));
      return a1;
    case 7:
      v22 = dword_1AA3F4[*(int16_t *)(HIDWORD(a1) + 4)];
      LODWORD(a1) = sub_77B28(*(_WORD *)(HIDWORD(a1) + 2));
      a1 = sprintf(
             v29,
             (char *)dword_1AAC34,
             dword_1AA404[*(uint8_t *)(HIDWORD(a1) + 8)],
             (_DWORD)a1,
             v22);
      v2 = a1;
      LODWORD(a1) = *(int16_t *)(HIDWORD(a1) + 6);
      if ( (_DWORD)a1 == -1 )
        return a1;
      v21 = dword_1930DC + 59 * *(int16_t *)(HIDWORD(a1) + 6);
      v3 = v29;
      v17 = (char *)dword_1AAC0C;
LABEL_8:
      v4 = &v3[v2];
      goto LABEL_65;
    case 8:
      v11 = (char *)v29;
      v12 = (char *)dword_1AABB4;
      goto LABEL_88;
    case 9:
      LODWORD(a1) = *(int16_t *)(HIDWORD(a1) + 2);
      if ( (_DWORD)a1 == -1 )
      {
        v11 = (char *)v29;
        v12 = (char *)dword_1AABD8;
        goto LABEL_88;
      }
      LODWORD(a1) = 129 * a1;
      if ( !*(_BYTE *)(HIDWORD(a1) + 7) )
      {
        v25 = dword_197F98 + 3753 * *(char *)(dword_197F9C + a1 + 99) + 21;
        v19 = (char *)dword_1AAB90;
        goto LABEL_67;
      }
      HIDWORD(a1) = sprintf(
                      v29,
                      (char *)dword_1AABBC,
                      dword_197F9C + (int)a1,
                      dword_19306C + 113 * *(char *)(HIDWORD(a1) + 4));
      LODWORD(a1) = *(char *)(v1 + 5);
      if ( (_DWORD)a1 != -1 )
      {
        v27 = dword_1930DC + 59 * a1;
        LODWORD(a1) = *(char *)(v1 + 6);
LABEL_94:
        LOBYTE(a1) = sprintf(&v29[HIDWORD(a1)], (char *)dword_1AAB70[(_DWORD)a1], v27);
      }
      return a1;
    case 0xA:
      v25 = dword_197F98 + 3753 * *(int16_t *)(HIDWORD(a1) + 2) + 21;
      v19 = (char *)dword_1AABC8;
      goto LABEL_67;
    case 0xB:
      if ( *(_WORD *)(HIDWORD(a1) + 2) != 1 )
      {
        v25 = *(int16_t *)(HIDWORD(a1) + 2);
        v19 = (char *)dword_1AABA4;
        goto LABEL_67;
      }
      v11 = (char *)v29;
      v12 = (char *)dword_1AABCC;
LABEL_88:
      strcpy(v11, v12);
      break;
    case 0xC:
      v25 = dword_19306C + 113 * *(char *)(HIDWORD(a1) + 2);
      v19 = (char *)dword_1AABDC;
      goto LABEL_67;
    case 0xD:
      HIDWORD(a1) = sprintf(v29, (char *)dword_1AABA0, dword_19306C + 113 * *(char *)(HIDWORD(a1) + 2));
      v27 = dword_1930DC + 59 * *(char *)(v1 + 3);
      LODWORD(a1) = *(char *)(v1 + 4);
      goto LABEL_94;
    case 0xE:
      v28 = dword_19306C + 113 * *(uint8_t *)(HIDWORD(a1) + 2);
      v20 = *(uint16_t *)(HIDWORD(a1) + 4);
      if ( *(_WORD *)(HIDWORD(a1) + 4) == 1 )
        v13 = sprintf(v29, (char *)dword_1AAB84, v20, v28);
      else
        v13 = sprintf(v29, (char *)dword_1AAB38, v20, v28);
      a1 = sprintf(&v29[v13], "  %s", (char *)dword_1AAB5C[*(uint8_t *)(v1 + 3)]);
      HIDWORD(a1) += a1;
      if ( !*(_BYTE *)(v1 + 6) )
        return a1;
      v21 = *(uint8_t *)(v1 + 6);
      LODWORD(a1) = v29;
      v17 = (char *)dword_1AAB68;
LABEL_64:
      v4 = (char *)(HIDWORD(a1) + a1);
LABEL_65:
      LOBYTE(a1) = sprintf(v4, v17, v21);
      return a1;
    case 0xF:
      if ( *(_BYTE *)(HIDWORD(a1) + 2) == *(_BYTE *)(HIDWORD(a1) + 3) )
        strcpy(v31, (char *)dword_1AAB30);
      else
        sprintf(v31, (char *)dword_1AAB3C, dword_197F98 + 3753 * *(uint8_t *)(HIDWORD(a1) + 3) + 1);
      if ( *(uint8_t *)(v1 + 5) == word_19999C )
      {
        if ( byte_199CAE == 4 )
          LOBYTE(a1) = sprintf(
                         v29,
                         (char *)dword_1AAB6C,
                         dword_1930DC + 59 * (unsigned int)*(uint8_t *)(v1 + 4),
                         v31,
                         dword_197F98 + 3753 * (unsigned int)*(uint8_t *)(v1 + 2) + 1);
        else
          LOBYTE(a1) = sprintf(
                         v29,
                         (char *)dword_1AAB6C,
                         dword_1930DC + 59 * (unsigned int)*(uint8_t *)(v1 + 4),
                         dword_197F98 + 3753 * (unsigned int)*(uint8_t *)(v1 + 2) + 1,
                         v31);
      }
      else
      {
        v25 = (int)v31;
        v19 = (char *)dword_1AAB88;
LABEL_67:
        LOBYTE(a1) = sprintf(v29, v19, v25);
      }
      break;
    case 0x10:
      v25 = dword_19306C + 113 * *(uint8_t *)(HIDWORD(a1) + 2);
      v19 = (char *)dword_1AAB7C;
      goto LABEL_67;
    case 0x11:
      LOBYTE(a1) = sprintf(
                     v29,
                     (char *)dword_1AAB48[*(uint8_t *)(HIDWORD(a1) + 2)],
                     3753 * (unsigned int)*(uint8_t *)(HIDWORD(a1) + 3) + dword_197F98 + 21,
                     dword_197F98 + 3753 * (unsigned int)*(uint8_t *)(HIDWORD(a1) + 4) + 21);
      return a1;
    case 0x12:
      v25 = dword_19306C + 113 * *(uint8_t *)(HIDWORD(a1) + 2);
      v19 = (char *)dword_1AAB34;
      goto LABEL_67;
    case 0x13:
      v25 = dword_19306C + 113 * *(uint8_t *)(HIDWORD(a1) + 2);
      v19 = (char *)dword_1AAB80;
      goto LABEL_67;
    case 0x14:
      if ( *(_BYTE *)(HIDWORD(a1) + 4) )
      {
        sub_58F1E(104, v32, 19);
        sprintf(
          v30,
          "%s %s %s",
          *(char **)((char *)&off_17E079 + 13 * *(uint8_t *)(HIDWORD(a1) + 3)),
          v32,
          *(char **)((char *)&off_17E079 + 13 * *(uint8_t *)(HIDWORD(a1) + 4)));
      }
      else
      {
        sprintf(v30, "%s", *(char **)((char *)&off_17E079 + 13 * *(uint8_t *)(HIDWORD(a1) + 3)));
      }
      LOBYTE(a1) = sprintf(
                     v29,
                     (char *)dword_1AAB40,
                     v30,
                     dword_19306C + 113 * (unsigned int)*(uint8_t *)(v1 + 2));
      return a1;
    case 0x15:
      v11 = (char *)v29;
      v12 = (char *)dword_1AAB2C;
      goto LABEL_88;
    case 0x16:
      v25 = dword_1930DC + 59 * *(uint8_t *)(HIDWORD(a1) + 2);
      v19 = (char *)dword_1AAB44;
      goto LABEL_67;
    default:
      return a1;
  }
  return a1;
}
// EECF1: variable 'v29' is possibly undefined
// EECF9: variable 'a1' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 18003A: using guessed type _UNKNOWN *off_18003A;
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 199CAE: using guessed type char byte_199CAE;
// 1AA3F4: using guessed type int dword_1AA3F4[];
// 1AA404: using guessed type int dword_1AA404[];
// 1AAB2C: using guessed type int dword_1AAB2C;
// 1AAB30: using guessed type int dword_1AAB30;
// 1AAB34: using guessed type int dword_1AAB34;
// 1AAB38: using guessed type int dword_1AAB38;
// 1AAB3C: using guessed type int dword_1AAB3C;
// 1AAB40: using guessed type int dword_1AAB40;
// 1AAB44: using guessed type int dword_1AAB44;
// 1AAB48: using guessed type int dword_1AAB48[];
// 1AAB5C: using guessed type int dword_1AAB5C[];
// 1AAB68: using guessed type int dword_1AAB68;
// 1AAB6C: using guessed type int dword_1AAB6C;
// 1AAB70: using guessed type int dword_1AAB70[];
// 1AAB7C: using guessed type int dword_1AAB7C;
// 1AAB80: using guessed type int dword_1AAB80;
// 1AAB84: using guessed type int dword_1AAB84;
// 1AAB88: using guessed type int dword_1AAB88;
// 1AAB8C: using guessed type int dword_1AAB8C;
// 1AAB90: using guessed type int dword_1AAB90;
// 1AAB94: using guessed type int dword_1AAB94;
// 1AAB98: using guessed type int dword_1AAB98;
// 1AAB9C: using guessed type int dword_1AAB9C;
// 1AABA0: using guessed type int dword_1AABA0;
// 1AABA4: using guessed type int dword_1AABA4;
// 1AABA8: using guessed type int dword_1AABA8;
// 1AABAC: using guessed type int dword_1AABAC;
// 1AABB0: using guessed type int dword_1AABB0;
// 1AABB4: using guessed type int dword_1AABB4;
// 1AABB8: using guessed type int dword_1AABB8;
// 1AABBC: using guessed type int dword_1AABBC;
// 1AABC0: using guessed type int dword_1AABC0;
// 1AABC4: using guessed type int dword_1AABC4;
// 1AABC8: using guessed type int dword_1AABC8;
// 1AABCC: using guessed type int dword_1AABCC;
// 1AABD0: using guessed type int dword_1AABD0;
// 1AABD4: using guessed type int dword_1AABD4;
// 1AABD8: using guessed type int dword_1AABD8;
// 1AABDC: using guessed type int dword_1AABDC;
// 1AABE0: using guessed type int dword_1AABE0;
// 1AABE4: using guessed type int dword_1AABE4;
// 1AABE8: using guessed type int dword_1AABE8;
// 1AABEC: using guessed type int dword_1AABEC;
// 1AABF0: using guessed type int dword_1AABF0;
// 1AABF4: using guessed type int dword_1AABF4;
// 1AABF8: using guessed type int dword_1AABF8;
// 1AABFC: using guessed type int dword_1AABFC;
// 1AAC00: using guessed type int dword_1AAC00;
// 1AAC04: using guessed type int dword_1AAC04;
// 1AAC08: using guessed type int dword_1AAC08;
// 1AAC0C: using guessed type int dword_1AAC0C;
// 1AAC10: using guessed type int dword_1AAC10;
// 1AAC14: using guessed type int dword_1AAC14;
// 1AAC18: using guessed type int dword_1AAC18;
// 1AAC1C: using guessed type int dword_1AAC1C;
// 1AAC20: using guessed type int dword_1AAC20;
// 1AAC24: using guessed type int dword_1AAC24;
// 1AAC28: using guessed type int dword_1AAC28;
// 1AAC2C: using guessed type int dword_1AAC2C;
// 1AAC30: using guessed type int dword_1AAC30;
// 1AAC34: using guessed type int dword_1AAC34;
// 1AAC38: using guessed type int dword_1AAC38;
// 1AAC3C: using guessed type int dword_1AAC3C;
// 1AAC40: using guessed type int dword_1AAC40;
// 1AAC44: using guessed type int dword_1AAC44;
// 1AAC48: using guessed type int dword_1AAC48;
// 1AAC4C: using guessed type int dword_1AAC4C;
// 1AAC50: using guessed type int dword_1AAC50;


//----- (000EF629) --------------------------------------------------------
uint8_t __stdcall sub_EF629(int a1, int a2, int a3, int a4, int a5, int a6)
{
  uint8_t result; // al
  uint8_t v7; // dl
  char *v8; // edi
  char *v9; // edi
  unsigned int v10; // esi
  uint8_t v11; // al
  char *v12; // edi

  result = a6;
  if ( byte_1AAB24[a6] )
  {
    v7 = byte_1AAB1C[a6];
    if ( v7 >= (uint8_t)byte_1AAB24[a6] )
    {
      v9 = (char *)&unk_1AA414 + 18 * (uint8_t)byte_1AA40C[a6];
      v10 = (unsigned int)&v9[18 * v7 + 18];
      while ( (unsigned int)(v9 + 18) < v10 )
      {
        v11 = *(_BYTE *)(v10 - 17);
        v10 -= 18;
        if ( v11 < (uint8_t)v9[1] )
          v9 = (char *)v10;
      }
      result = v9[1];
      if ( result < BYTE1(a1) )
      {
        *(_DWORD *)v9 = a1;
        v12 = v9 + 4;
        *(_DWORD *)v12 = a2;
        v12 += 4;
        *(_DWORD *)v12 = a3;
        v12 += 4;
        *(_DWORD *)v12 = a4;
        *((_WORD *)v12 + 2) = a5;
      }
    }
    else
    {
      v8 = (char *)&unk_1AA414 + 18 * (uint8_t)byte_1AA40C[a6] + 18 * v7;
      *(_DWORD *)v8 = a1;
      v8 += 4;
      *(_DWORD *)v8 = a2;
      v8 += 4;
      *(_DWORD *)v8 = a3;
      v8 += 4;
      *(_DWORD *)v8 = a4;
      *((_WORD *)v8 + 2) = a5;
      ++byte_1AAB1C[a6];
    }
  }
  return result;
}


//----- (000EF6BE) --------------------------------------------------------
uint8_t __stdcall sub_EF6BE(int a1, int a2, int a3, int a4, int a5)
{
  int i; // edx
  uint8_t result; // al

  for ( i = word_199998; i > 0; result = sub_EF629(a1, a2, a3, a4, a5, i) )
    --i;
  return result;
}
// 199998: using guessed type int16_t word_199998;


//----- (000EF6F0) --------------------------------------------------------
char __fastcall sub_EF6F0(_BYTE *a1)
{
  char v1; // dl
  int v2; // eax
  char *v3; // eax
  int v4; // eax
  int16_t v5; // bx

  v1 = 0;
  if ( !*a1 )
  {
    v2 = *(int16_t *)(dword_1930D4 + 17 * (uint8_t)a1[2]);
    if ( v2 != -1 )
    {
      v3 = (char *)(dword_192B18 + 361 * v2);
      if ( *v3 == word_19999C )
      {
        v1 = 1;
        v4 = dword_1930D4 + 17 * *((int16_t *)v3 + 1);
        word_199A08 = 1;
        word_199A10 = 9;
        v5 = *(uint8_t *)(v4 + 2);
        LOWORD(v4) = *(uint8_t *)(v4 + 3);
        word_199830 = v5;
        word_199832 = v4;
      }
    }
  }
  return v1;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;


//----- (000EF766) --------------------------------------------------------
uint8_t __fastcall sub_EF766(int a1, int a2, int a3)
{
  int v4; // edx
  uint8_t result; // al
  int v6; // ebx
  int v7; // [esp+0h] [ebp-1Ch] BYREF
  int v8; // [esp+4h] [ebp-18h]
  int v9; // [esp+8h] [ebp-14h]
  int v10; // [esp+Ch] [ebp-10h]
  int16_t v11; // [esp+10h] [ebp-Ch]
  int v12; // [esp+14h] [ebp-8h]
  int v13; // [esp+18h] [ebp-4h]

  v12 = a2;
  v13 = a3;
  memset(&v7, 0, 18);
  LOBYTE(v7) = 17;
  v4 = word_199998;
  BYTE2(v7) = v13;
  result = v12;
  HIBYTE(v7) = a1;
  LOBYTE(v8) = v12;
  v6 = 3753 * word_199998;
  while ( v4 > 0 )
  {
    v6 -= 3753;
    --v4;
    if ( v13 == 4 )
    {
      if ( v4 == a1 || v4 == v12 )
        goto LABEL_8;
    }
    else if ( *(_BYTE *)(a1 + v6 + dword_197F98 + 1412) || *(_BYTE *)(v12 + v6 + dword_197F98 + 1412) )
    {
LABEL_8:
      result = sub_EF629(v7, v8, v9, v10, v11, v4);
    }
  }
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000EF7FD) --------------------------------------------------------
uint8_t __fastcall sub_EF7FD(int a1, int a2)
{
  return sub_EF766(a1, a2, 0);
}


//----- (000EF807) --------------------------------------------------------
void sub_EF807()
{
  JUMPOUT(0xEF800);
}
// EF80D: control flows out of bounds to EF800


//----- (000EF80F) --------------------------------------------------------
void sub_EF80F()
{
  JUMPOUT(0xEF800);
}
// EF815: control flows out of bounds to EF800


//----- (000EF817) --------------------------------------------------------
void sub_EF817()
{
  JUMPOUT(0xEF800);
}
// EF81D: control flows out of bounds to EF800


//----- (000EF81F) --------------------------------------------------------
void sub_EF81F()
{
  JUMPOUT(0xEF800);
}
// EF825: control flows out of bounds to EF800


//----- (000EF827) --------------------------------------------------------
void sub_EF827()
{
  int i; // ecx
  int v1; // ecx
  int v2; // ecx
  int v3; // edx
  int64_t v4; // rax
  int v5; // eax
  int v6; // ecx
  int v7[4]; // [esp+0h] [ebp-16h] BYREF
  int16_t v8; // [esp+10h] [ebp-6h]
  int v9; // [esp+14h] [ebp-2h]
  int v10; // [esp+18h] [ebp+2h]
  int v11; // [esp+1Ch] [ebp+6h]
  int v12; // [esp+20h] [ebp+Ah]
  int16_t v13; // [esp+24h] [ebp+Eh]
  int v14; // [esp+28h] [ebp+12h]
  int v15; // [esp+2Ch] [ebp+16h]
  int v16; // [esp+30h] [ebp+1Ah]
  int v17; // [esp+34h] [ebp+1Eh]
  int16_t v18; // [esp+38h] [ebp+22h]
  int v19[4]; // [esp+3Ch] [ebp+26h] BYREF
  int16_t v20; // [esp+4Ch] [ebp+36h]
  int v21[4]; // [esp+50h] [ebp+3Ah] BYREF
  int16_t v22; // [esp+60h] [ebp+4Ah]
  int v23[4]; // [esp+64h] [ebp+4Eh] BYREF
  int16_t v24; // [esp+74h] [ebp+5Eh]
  int v25[4]; // [esp+78h] [ebp+62h] BYREF
  int16_t v26; // [esp+88h] [ebp+72h]
  int v27; // [esp+8Ch] [ebp+76h]
  int v28; // [esp+90h] [ebp+7Ah]
  int v29; // [esp+94h] [ebp+7Eh] BYREF

  if ( sub_233FA() )
  {
    memset(v21, 0, 18);
    LOBYTE(v21[0]) = 8;
    for ( i = word_199998; i > 0; sub_EF629(v21[0], v21[1], v21[2], v21[3], v22, i) )
      --i;
  }
  v1 = word_199996;
  v28 = 361 * word_199996;
  while ( v1 > 0 )
  {
    v28 -= 361;
    --v1;
    v27 = *(char *)(v28 + dword_192B18);
    if ( v27 >= 0 )
    {
      if ( sub_234B8(v1) )
      {
        memset(v7, 0, 18);
        LOBYTE(v7[0]) = 0;
        BYTE2(v7[0]) = *(_BYTE *)(v28 + dword_192B18 + 2);
        HIBYTE(v7[0]) = 6;
        sub_EF629(v7[0], v7[1], v7[2], v7[3], v8, v27);
      }
      if ( sub_23509(v1) )
      {
        memset(v23, 0, 18);
        LOBYTE(v23[0]) = 0;
        BYTE2(v23[0]) = *(_BYTE *)(v28 + dword_192B18 + 2);
        HIBYTE(v23[0]) = 7;
        sub_EF629(v23[0], v23[1], v23[2], v23[3], v24, v27);
      }
      if ( sub_23536(v1) )
      {
        memset(v25, 0, 18);
        LOBYTE(v25[0]) = 0;
        BYTE2(v25[0]) = *(_BYTE *)(v28 + dword_192B18 + 2);
        HIBYTE(v25[0]) = 8;
        sub_EF629(v25[0], v25[1], v25[2], v25[3], v26, v27);
      }
    }
  }
  v2 = word_19999A;
  while ( v2 > 0 )
  {
    if ( sub_242CF(--v2) )
    {
      memset(v19, 0, 18);
      LOBYTE(v19[0]) = 16;
      v3 = word_199998;
      BYTE2(v19[0]) = v2;
      while ( v3 > 0 )
        sub_EF629(v19[0], v19[1], v19[2], v19[3], v20, --v3);
    }
  }
  if ( dword_192FD8 == 35023 )
  {
    v4 = time(0);
    v29 = v4;
    v5 = ((int(*)())(void*)localtime)((int)&v29, (time_t *)HIDWORD(v4));
    if ( *(_DWORD *)(v5 + 16) == 3 && *(_DWORD *)(v5 + 12) == 1 )
    {
      LOBYTE(v9) = 21;
      v6 = word_199998;
      v14 = v9;
      v15 = v10;
      v16 = v11;
      v17 = v12;
      v18 = v13;
      while ( v6 > 0 )
        sub_EF629(v14, v15, v16, v17, v18, --v6);
    }
  }
  JUMPOUT(0xEEBF2);
}
// EFA4D: control flows out of bounds to EEBF2
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 13C905: using guessed type int64_t __fastcall time(_DWORD);
// 192B18: using guessed type int dword_192B18;
// 192FD8: using guessed type int dword_192FD8;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (000EFABA) --------------------------------------------------------
int __fastcall sub_EFABA( int a1, int a2)
{
  int v2; // esi
  int16_t v3; // di
  int16_t v4; // cx
  _WORD *v5; // eax
  int16_t v6; // dx
  int result; // eax

  v2 = a1;
  v3 = *(_WORD *)(dword_192680 + 243);
  v4 = 36 * a2 + 65 + *(_WORD *)(dword_192680 + 245);
  v5 = (_WORD *)sub_127C27(
                  (int)aMultigmLbx,
                  (int16_t)(8 * *(uint8_t *)(dword_197F98 + 3753 * a1 + 37)
                          + 46
                          + *(uint8_t *)(dword_197F98 + 3753 * a1 + 38)),
                  dword_193174);
  v6 = sub_11438B(v3 + 40, v4, v3 + 40 + *v5, v4 + v5[1], &unk_17A061, 41);
  result = v2;
  *(_WORD *)(dword_192680 + 2 * v2 + 167) = v6;
  return result;
}
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;


//----- (000EFB50) --------------------------------------------------------
int sub_EFB50()
{
  int v0; // eax
  int v1; // edx
  int16_t v2; // di
  int v3; // edx
  int v4; // eax
  int v5; // edx
  int v6; // edx
  int result; // eax
  uint16_t v8; // dx
  int v9; // [esp+0h] [ebp-Ch]
  int v10; // [esp+8h] [ebp-4h]

  sub_11C2F0();
  v10 = 0;
  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    *(_WORD *)(dword_192680 + 2 * v1 + 187) = -1000;
  }
  while ( (int16_t)v0 < 8 );
  v2 = 0;
  v9 = 64;
  while ( v2 < word_199998 )
  {
    v3 = 3753 * v2 + dword_197F98;
    if ( *(_BYTE *)(v3 + 40) != 100 || *(_BYTE *)(v2 + dword_192680 + 260) || *(_BYTE *)(v3 + 36) )
    {
      v4 = dword_192680;
      v5 = 2 * v2;
      *(_WORD *)(v5 + dword_192680 + 187) = -1000;
      *(_WORD *)(v5 + v4 + 167) = -1000;
    }
    else
    {
      *(_WORD *)(dword_192680 + 2 * v2 + 187) = sub_11438B(
                                                  *(_WORD *)(dword_192680 + 243) + 106,
                                                  v9 + *(_WORD *)(dword_192680 + 245),
                                                  *(_WORD *)(dword_192680 + 243) + 435,
                                                  v9 + *(_WORD *)(dword_192680 + 245) + 29,
                                                  &unk_17A061,
                                                  41);
      v9 += 36;
      sub_EFABA(v2, v10++);
    }
    ++v2;
  }
  v6 = sub_127C27((int)aMultigmLbx, 27, dword_193174);
  result = dword_192680;
  *(_DWORD *)(dword_192680 + 35) = v6;
  if ( *(_BYTE *)(result + 259) )
  {
    v8 = (uint16_t)sub_1151B0(
                             *(_WORD *)(result + 243),
                             *(_WORD *)(result + 245)
                           + *(_WORD *)(*(_DWORD *)(result + 35) + 2)
                           + *(_WORD *)(*(_DWORD *)(result + 39) + 2) * (*(_WORD *)(result + 481) - 1)
                           + *(_WORD *)(*(_DWORD *)(result + 43) + 2)
                           + 1,
                             (int)&unk_17A061,
                             *(_WORD **)(result + 143),
                             aS_21,
                             40);
    result = dword_192680;
    *(_WORD *)(dword_192680 + 237) = v8;
  }
  else
  {
    *(_WORD *)(result + 237) = -1000;
  }
  return result;
}
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000EFCEA) --------------------------------------------------------
int __fastcall sub_EFCEA(int a1, int a2)
{
  int v2; // eax
  int v3; // edx
  char *v4; // eax
  int16_t v5; // ax
  int16_t v6; // dx
  int result; // eax
  _BYTE v8[80]; // [esp+0h] [ebp-74h] BYREF
  _BYTE v9[8]; // [esp+50h] [ebp-24h] BYREF
  _BYTE v10[8]; // [esp+58h] [ebp-1Ch] BYREF
  int v11; // [esp+60h] [ebp-14h]
  int v12; // [esp+64h] [ebp-10h]
  _BYTE v13[4]; // [esp+68h] [ebp-Ch] BYREF
  _BYTE v14[4]; // [esp+6Ch] [ebp-8h] BYREF
  char v15[4]; // [esp+70h] [ebp-4h] BYREF

  HIWORD(v2) = HIWORD(dword_192680);
  LOWORD(a2) = *(_WORD *)(dword_192680 + 243);
  LOWORD(v2) = *(_WORD *)(dword_192680 + 245);
  v11 = v2;
  sub_11C2F0();
  v12 = a2;
  HIWORD(v3) = HIWORD(v11);
  LOWORD(v3) = *(_WORD *)(dword_192680 + 191) + v11;
  v11 = v3 + 187;
  sub_F30B9(word_19999C, v15, v14, v13);
  byte_199F34 = v14[0] + 1;
  qmemcpy(
    v10,
    sub_8E5C5(*(uint8_t *)(dword_192680 + 270), (uint8_t)v15[0] + 1, v13[0] + 2),
    sizeof(v10));
  byte_199F34 = v14[0] + 3;
  v4 = sub_8E5C5(*(uint8_t *)(dword_192680 + 270), (uint8_t)v15[0] + 1, v13[0] + 4);
  v12 += 25;
  qmemcpy(v9, v4, sizeof(v9));
  sub_120BB5(*(uint8_t *)(dword_192680 + 270), (int)v10);
  sub_120F07((int)v9);
  sprintf(v8, "(%s)  ", (char *)(dword_197F98 + 3753 * word_19999C + 1));
  v5 = sub_12066F((int)v8);
  byte_1AAC54 = 0;
  *(_WORD *)(dword_192680 + 187) = (uint16_t)sub_115BEA(
                                                       v12 + v5,
                                                       v11,
                                                       570 - v5 - 3,
                                                       17,
                                                       (int)&byte_1AAC54,
                                                       80,
                                                       0,
                                                       0,
                                                       41,
                                                       0);
  v6 = sub_11438B(0, 0, 639, 479, &off_17A06B, 41);
  result = dword_192680;
  *(_WORD *)(dword_192680 + 189) = v6;
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17A06B: using guessed type _UNKNOWN *off_17A06B;
// 192680: using guessed type int dword_192680;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199F34: using guessed type char byte_199F34;
// 1AAC54: using guessed type char byte_1AAC54;


//----- (000EFE7A) --------------------------------------------------------
char sub_EFE7A()
{
  char v0; // dl
  char *v1; // eax
  int v2; // edi
  int v3; // esi
  int16_t v4; // dx
  int v5; // ebx
  int v6; // edx
  int v7; // eax
  char v9; // [esp+4h] [ebp-4h]

  v0 = sub_F33AE(dword_192680 + 203);
  if ( !v0 )
  {
    v1 = sub_7A990(0xF4u);
    sub_77433(v1);
  }
  v9 = v0;
  if ( v0 )
  {
    v2 = 64;
    v3 = 0;
    do
    {
      v4 = v2 + *(_WORD *)(dword_192680 + 245);
      v2 += 27;
      v5 = (int16_t)v3++;
      *(_WORD *)(dword_192680 + 2 * v5 + 167) = sub_11438B(
                                                  *(_WORD *)(dword_192680 + 243) + 38,
                                                  v4,
                                                  *(_WORD *)(dword_192680 + 243) + 400,
                                                  v4 + 22,
                                                  &unk_17A061,
                                                  41);
    }
    while ( (int16_t)v3 < 10 );
    v6 = sub_127C27((int)aMultigmLbx, 18, dword_193174);
    v7 = dword_192680;
    *(_DWORD *)(dword_192680 + 27) = v6;
    *(_WORD *)(dword_192680 + 223) = (uint16_t)sub_1151B0(
                                                         *(_WORD *)(v7 + 243) + 191,
                                                         *(_WORD *)(v7 + 245) + 344,
                                                         (int)&unk_17A061,
                                                         *(_WORD **)(v7 + 115),
                                                         (_BYTE *)&off_17A06B + 2,
                                                         40);
  }
  return v9;
}
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// 17A06B: using guessed type _UNKNOWN *off_17A06B;
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;


//----- (000EFF87) --------------------------------------------------------
int sub_EFF87()
{
  int16_t v0; // ax
  int v1; // eax
  int v2; // edx
  int v3; // edi
  int16_t i; // si
  int16_t v5; // dx
  int16_t v6; // dx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int result; // eax
  int16_t v11; // [esp+4h] [ebp-4h]

  if ( sub_139659() >= 10 )
    v0 = 10;
  else
    v0 = sub_139659();
  v11 = v0;
  v1 = 0;
  do
  {
    v2 = (int16_t)v1++;
    *(_WORD *)(dword_192680 + 2 * v2 + 167) = -1000;
  }
  while ( (int16_t)v1 < 10 );
  v3 = 64;
  for ( i = 0; i < v11; ++i )
  {
    v5 = v3 + *(_WORD *)(dword_192680 + 245);
    v3 += 27;
    v6 = sub_11438B(
           *(_WORD *)(dword_192680 + 243) + 38,
           v5,
           *(_WORD *)(dword_192680 + 243) + 400,
           v5 + 22,
           &unk_17A061,
           41);
    v7 = i;
    *(_WORD *)(dword_192680 + 2 * v7 + 167) = v6;
  }
  v8 = sub_127C27((int)aMultigmLbx, 41, dword_193174);
  v9 = dword_192680;
  *(_DWORD *)(dword_192680 + 27) = v8;
  LOWORD(v8) = (uint16_t)sub_1151B0(
                                   *(_WORD *)(v9 + 243) + 191,
                                   *(_WORD *)(v9 + 245) + 344,
                                   (int)&unk_17A061,
                                   *(_WORD **)(v9 + 115),
                                   (_BYTE *)&off_17A06B + 2,
                                   41);
  result = dword_192680;
  *(_WORD *)(dword_192680 + 223) = v8;
  return result;
}
// 17A06B: using guessed type _UNKNOWN *off_17A06B;
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;


//----- (000F009A) --------------------------------------------------------
int sub_F009A()
{
  int16_t v0; // dx
  int v1; // eax
  int16_t v2; // bx
  int16_t v3; // dx
  int v4; // eax
  int16_t v5; // bx
  int16_t v6; // dx
  int v7; // eax
  int16_t v8; // dx
  int v9; // eax
  uint16_t v10; // dx
  int v11; // eax
  uint16_t v12; // dx
  int v13; // eax
  uint16_t v14; // dx
  int v15; // eax
  uint16_t v16; // dx
  int v17; // eax

  sub_11C2F0();
  v0 = sub_11438B(
         *(_WORD *)(dword_192680 + 243) + 59,
         *(_WORD *)(dword_192680 + 245) + 91,
         *(_WORD *)(dword_192680 + 243) + 59 + **(_WORD **)(dword_192680 + 95),
         *(_WORD *)(dword_192680 + 245) + 91 + *(_WORD *)(*(_DWORD *)(dword_192680 + 95) + 2),
         byte_17A06F,
         40);
  v1 = dword_192680;
  v2 = *(_WORD *)(dword_192680 + 245);
  *(_WORD *)(dword_192680 + 215) = v0;
  v3 = sub_11438B(
         *(_WORD *)(v1 + 243) + 59,
         v2 + 122,
         *(_WORD *)(v1 + 243) + 59 + **(_WORD **)(v1 + 99),
         v2 + 122 + *(_WORD *)(*(_DWORD *)(v1 + 99) + 2),
         byte_17A071,
         40);
  v4 = dword_192680;
  v5 = *(_WORD *)(dword_192680 + 245);
  *(_WORD *)(dword_192680 + 217) = v3;
  v6 = sub_11438B(
         *(_WORD *)(v4 + 243) + 59,
         v5 + 155,
         *(_WORD *)(v4 + 243) + 59 + **(_WORD **)(v4 + 103),
         v5 + 155 + *(_WORD *)(*(_DWORD *)(v4 + 103) + 2),
         byte_17A073,
         40);
  v7 = dword_192680;
  *(_WORD *)(dword_192680 + 219) = v6;
  v8 = sub_11438B(
         *(_WORD *)(v7 + 243) + 59,
         *(_WORD *)(v7 + 245) + 187,
         *(_WORD *)(v7 + 243) + 59 + **(_WORD **)(v7 + 107),
         *(_WORD *)(v7 + 245) + 187 + *(_WORD *)(*(_DWORD *)(v7 + 107) + 2),
         byte_17A075,
         40);
  v9 = dword_192680;
  *(_WORD *)(dword_192680 + 221) = v8;
  v10 = (uint16_t)sub_1151B0(
                            *(_WORD *)(v9 + 243) + 110,
                            *(_WORD *)(v9 + 245) + 220,
                            (int)&unk_17A061,
                            *(_WORD **)(v9 + 139),
                            byte_17A077,
                            40);
  v11 = dword_192680;
  *(_WORD *)(dword_192680 + 255) = 0;
  *(_WORD *)(v11 + 235) = v10;
  v12 = (uint16_t)sub_1151B0(
                            *(_WORD *)(v11 + 243) + 176,
                            *(_WORD *)(v11 + 245) + 286,
                            (int)&unk_17A061,
                            *(_WORD **)(v11 + 115),
                            (_BYTE *)&off_17A06B + 2,
                            40);
  v13 = dword_192680;
  *(_WORD *)(dword_192680 + 223) = v12;
  if ( *(_WORD *)(v13 + 247) != 1
    && *(_WORD *)(v13 + 249) != 1
    && *(_WORD *)(v13 + 251) != 1
    && *(_WORD *)(v13 + 253) != 1 )
  {
    *(_WORD *)(v13 + 227) = -1000;
    *(_WORD *)(v13 + 229) = -1000;
    *(_WORD *)(v13 + 231) = -1000;
LABEL_12:
    *(_WORD *)(v13 + 233) = -1000;
    return sub_F5691();
  }
  v14 = (uint16_t)sub_1151B0(
                            *(_WORD *)(dword_192680 + 243) + 269,
                            *(_WORD *)(dword_192680 + 245) + 91,
                            (int)&unk_17A061,
                            *(_WORD **)(dword_192680 + 123),
                            aS_21,
                            40);
  v15 = dword_192680;
  *(_WORD *)(dword_192680 + 227) = v14;
  v16 = (uint16_t)sub_1151B0(
                            *(_WORD *)(v15 + 243) + 269,
                            *(_WORD *)(v15 + 245) + 122,
                            (int)&unk_17A061,
                            *(_WORD **)(v15 + 127),
                            byte_17A079,
                            40);
  v17 = dword_192680;
  *(_WORD *)(dword_192680 + 229) = v16;
  if ( *(_WORD *)(v17 + 253) == 1 )
    *(_WORD *)(v17 + 231) = -1000;
  else
    *(_WORD *)(dword_192680 + 231) = (uint16_t)sub_1151B0(
                                                         *(_WORD *)(v17 + 243) + 269,
                                                         *(_WORD *)(v17 + 245) + 155,
                                                         (int)&unk_17A061,
                                                         *(_WORD **)(v17 + 131),
                                                         byte_17A07B,
                                                         40);
  v13 = dword_192680;
  if ( *(_WORD *)(dword_192680 + 249) != 2 && *(_WORD *)(dword_192680 + 251) != 1 )
    goto LABEL_12;
  *(_WORD *)(dword_192680 + 233) = (uint16_t)sub_1151B0(
                                                       *(_WORD *)(dword_192680 + 243) + 269,
                                                       *(_WORD *)(dword_192680 + 245) + 187,
                                                       (int)&unk_17A061,
                                                       *(_WORD **)(dword_192680 + 135),
                                                       &off_17A06B,
                                                       40);
  return sub_F5691();
}
// 17A06B: using guessed type _UNKNOWN *off_17A06B;
// 17A06F: using guessed type _BYTE byte_17A06F[2];
// 17A071: using guessed type _BYTE byte_17A071[2];
// 17A073: using guessed type _BYTE byte_17A073[2];
// 17A075: using guessed type _BYTE byte_17A075[2];
// 17A077: using guessed type _BYTE byte_17A077[2];
// 17A079: using guessed type _BYTE byte_17A079[2];
// 17A07B: using guessed type _BYTE byte_17A07B[2];
// 192680: using guessed type int dword_192680;


//----- (000F03F2) --------------------------------------------------------
void __usercall sub_F03F2(int a1)
{
  int v1; // eax
  int16_t v2; // si
  int v3; // esi
  int16_t v4; // cx
  int16_t v5; // dx
  int v6; // eax
  int v7; // esi
  int16_t v8; // cx
  int16_t v9; // dx
  int v10; // eax
  uint16_t v11; // ax
  _WORD *v12; // ecx
  int16_t v13; // [esp+8h] [ebp-20h]
  int16_t v14; // [esp+Ch] [ebp-1Ch]
  int16_t v15; // [esp+10h] [ebp-18h]
  int16_t v16; // [esp+14h] [ebp-14h]
  int v17; // [esp+1Ch] [ebp-Ch]
  int v18; // [esp+20h] [ebp-8h]

  v1 = dword_192680;
  *(_WORD *)(dword_192680 + 223) = -1000;
  v2 = *(_WORD *)(v1 + 243);
  LOWORD(a1) = *(_WORD *)(v1 + 245);
  if ( *(_WORD *)(v1 + 249) == 1 )
  {
    v18 = 0;
    v15 = v2 + 148;
    v13 = v2 + 233;
    v3 = a1 + 101;
    do
    {
      v4 = v3;
      v3 += 15;
      v5 = sub_11438B(v15, a1 + 86 + 15 * v18, v13, v4, &unk_17A061, 40);
      v6 = (int16_t)v18++;
      *(_WORD *)(dword_192680 + 2 * v6 + 167) = v5;
    }
    while ( (int16_t)v18 < 8 );
  }
  else if ( *(_WORD *)(v1 + 249) == 2 )
  {
    v17 = 0;
    v14 = v2 + 303;
    v16 = v2 + 383;
    v7 = a1 + 111;
    do
    {
      v8 = v7;
      v7 += 15;
      v9 = sub_11438B(v14, a1 + 96 + 15 * v17, v16, v8, &unk_17A061, 40);
      v10 = (int16_t)v17++;
      *(_WORD *)(dword_192680 + 2 * v10 + 167) = v9;
    }
    while ( (int16_t)v17 < 8 );
  }
  else
  {
    v11 = (uint16_t)sub_1151B0(
                              v2 + 61,
                              a1 + 199,
                              (int)&unk_17A061,
                              *(_WORD **)(v1 + 115),
                              (_BYTE *)&off_17A06B + 2,
                              40);
    v12 = *(_WORD **)(dword_192680 + 111);
    *(_WORD *)(dword_192680 + 223) = v11;
    *(_WORD *)(dword_192680 + 225) = (uint16_t)sub_1151B0(
                                                         v2 + 255,
                                                         a1 + 199,
                                                         (int)&unk_17A061,
                                                         v12,
                                                         (_BYTE *)&off_17A06B + 2,
                                                         40);
    *(_WORD *)(dword_192680 + 167) = sub_11438B(v2 + 122, a1 + 62, v2 + 202, a1 + 77, &unk_17A061, 40);
    *(_WORD *)(dword_192680 + 169) = sub_11438B(v2 + 292, a1 + 62, v2 + 372, a1 + 77, &unk_17A061, 40);
    *(_WORD *)(dword_192680 + 177) = sub_11438B(v2 + 294, a1 + 157, v2 + 374, a1 + 172, &unk_17A061, 40);
  }
  sub_127C27((int)aMultigmLbx, 32, dword_193174);
  JUMPOUT(0xF0659);
}
// F0654: control flows out of bounds to F0659
// 17A06B: using guessed type _UNKNOWN *off_17A06B;
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;


//----- (000F0678) --------------------------------------------------------
int __fastcall sub_F0678(int a1, int a2)
{
  int v2; // eax
  int16_t v3; // si
  uint16_t v4; // dx
  int result; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-10h] BYREF
  int v7; // [esp+8h] [ebp-8h]
  int v8; // [esp+Ch] [ebp-4h]

  HIWORD(v2) = HIWORD(dword_192680);
  LOWORD(a2) = *(_WORD *)(dword_192680 + 243);
  v7 = a2;
  LOWORD(v2) = *(_WORD *)(dword_192680 + 245);
  v8 = v2;
  qmemcpy(v6, sub_8E5C5(1u, 146, 152), sizeof(v6));
  sub_120BB5(*(uint8_t *)(dword_192680 + 270), (int)v6);
  v3 = v7 + 124;
  *(_WORD *)(dword_192680 + 173) = (uint16_t)sub_115BEA(
                                                       v7 + 124,
                                                       v8 + 129,
                                                       154,
                                                       16,
                                                       (int)byte_1AAED5,
                                                       30,
                                                       0,
                                                       0,
                                                       41,
                                                       0);
  *(_WORD *)(dword_192680 + 175) = (uint16_t)sub_115BEA(
                                                       v3,
                                                       v8 + 153,
                                                       154,
                                                       16,
                                                       (int)&unk_1AAEF3,
                                                       30,
                                                       0,
                                                       0,
                                                       41,
                                                       0);
  *(_WORD *)(dword_192680 + 179) = (uint16_t)sub_115BEA(
                                                       v3,
                                                       v8 + 177,
                                                       154,
                                                       16,
                                                       (int)&unk_1AAF11,
                                                       30,
                                                       0,
                                                       0,
                                                       41,
                                                       0);
  byte_199F34 = -106;
  qmemcpy(v6, sub_8E5C5(4u, 146, 152), sizeof(v6));
  sub_120BB5(4, (int)v6);
  v4 = (uint16_t)sub_115BEA(v7 + 145, v8 + 91, 150, 16, (int)&unk_1AAF2F, 32, 0, 0, 41, 0);
  result = dword_192680;
  *(_WORD *)(dword_192680 + 171) = v4;
  return result;
}
// 192680: using guessed type int dword_192680;
// 199F34: using guessed type char byte_199F34;


//----- (000F0801) --------------------------------------------------------
int sub_F0801()
{
  uint16_t v0; // dx
  int result; // eax

  v0 = (uint16_t)sub_1151B0(
                           *(_WORD *)(dword_192680 + 243) + 158,
                           *(_WORD *)(dword_192680 + 245) + 106,
                           (int)&unk_17A061,
                           *(_WORD **)(dword_192680 + 143),
                           aS_21,
                           40);
  result = dword_192680;
  *(_WORD *)(dword_192680 + 237) = v0;
  return result;
}
// 192680: using guessed type int dword_192680;


//----- (000F084F) --------------------------------------------------------
void __fastcall sub_F084F(int a1, int a2)
{
  int v2; // eax
  int16_t v3; // cx
  _BYTE v4[8]; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+8h] [ebp-8h]
  int v6; // [esp+Ch] [ebp-4h]

  HIWORD(v2) = HIWORD(dword_192680);
  LOWORD(a2) = *(_WORD *)(dword_192680 + 243);
  v5 = a2;
  LOWORD(v2) = *(_WORD *)(dword_192680 + 245);
  v6 = v2;
  qmemcpy(v4, sub_8E5C5(1u, 146, 152), sizeof(v4));
  sub_120BB5(1, (int)v4);
  v3 = v5 + 134;
  sub_1212B3(v5 + 134, v6 + 133, (int)byte_1AAED5);
  sub_1212B3(v3, v6 + 157, (int)&unk_1AAEF3);
  sub_1212B3(v3, v6 + 181, (int)&unk_1AAF11);
  byte_199F34 = -106;
  qmemcpy(v4, sub_8E5C5(4u, 146, 152), sizeof(v4));
  sub_120BB5(4, (int)v4);
  JUMPOUT(0xF2F43);
}
// F093E: control flows out of bounds to F2F43
// 192680: using guessed type int dword_192680;
// 199F34: using guessed type char byte_199F34;


//----- (000F0943) --------------------------------------------------------
int __usercall sub_F0943(int a1)
{
  int16_t v1; // dx
  int result; // eax
  int16_t v3; // si
  int v4; // esi
  int16_t v5; // cx
  int16_t v6; // dx
  int v7; // eax
  int16_t v8; // si
  int16_t v9; // ax
  int v10; // ebx
  int16_t v11; // cx
  int16_t v12; // dx
  int16_t v13; // di
  int16_t v14; // ax
  _WORD *v15; // ecx
  uint16_t v16; // ax
  _WORD *v17; // ecx
  int16_t v18; // [esp+0h] [ebp-20h]
  int16_t v19; // [esp+Ch] [ebp-14h]
  int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  int16_t v22; // [esp+18h] [ebp-8h]
  int16_t v23; // [esp+1Ch] [ebp-4h]

  v3 = *(_WORD *)(dword_192680 + 243);
  LOWORD(a1) = *(_WORD *)(dword_192680 + 245);
  if ( *(_WORD *)(dword_192680 + 251) == 1 )
  {
    v20 = 0;
    v19 = v3 + 134;
    v23 = v3 + 214;
    v4 = a1 + 130;
    do
    {
      v5 = v4;
      v4 += 15;
      v6 = sub_11438B(v19, a1 + 116 + 15 * v20, v23, v5, &unk_17A061, 41);
      v7 = (int16_t)v20++;
      *(_WORD *)(dword_192680 + 2 * v7 + 167) = v6;
    }
    while ( (int16_t)v20 < 8 );
  }
  else if ( *(_WORD *)(dword_192680 + 251) == 2 )
  {
    v21 = 0;
    v22 = v3 + 300;
    v18 = v3 + 380;
    v8 = a1 + 129;
    do
    {
      v9 = sub_11438B(v22, a1 + 115 + 15 * v21, v18, v8, &unk_17A061, 41);
      v10 = 2 * (int16_t)v21;
      v8 += 15;
      ++v21;
      *(_WORD *)(v10 + dword_192680 + 167) = v9;
    }
    while ( (int16_t)v21 < 8 );
  }
  else
  {
    *(_WORD *)(dword_192680 + 167) = sub_11438B(v3 + 118, a1 + 82, v3 + 198, a1 + 97, &unk_17A061, 41);
    v11 = a1 + 96;
    v12 = a1 + 81;
    v13 = a1 + 124;
    v14 = sub_11438B(v3 + 289, v12, v3 + 367, v11, &unk_17A061, 41);
    v15 = *(_WORD **)(dword_192680 + 115);
    *(_WORD *)(dword_192680 + 169) = v14;
    v16 = (uint16_t)sub_1151B0(v3 + 59, v13, (int)&unk_17A061, v15, (_BYTE *)&off_17A06B + 2, 40);
    v17 = *(_WORD **)(dword_192680 + 111);
    *(_WORD *)(dword_192680 + 223) = v16;
    *(_WORD *)(dword_192680 + 225) = (uint16_t)sub_1151B0(
                                                         v3 + 253,
                                                         v13,
                                                         (int)&unk_17A061,
                                                         v17,
                                                         (_BYTE *)&off_17A06B + 2,
                                                         40);
  }
  *(_DWORD *)(dword_192680 + 47) = sub_127C27((int)aMultigmLbx, 35, dword_193174);
  v1 = sub_11438B(0, 0, 639, 479, (_BYTE *)&off_17A06B + 2, 41);
  result = dword_192680;
  *(_WORD *)(dword_192680 + 213) = v1;
  return result;
}
// 17A06B: using guessed type _UNKNOWN *off_17A06B;
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;


//----- (000F0B8C) --------------------------------------------------------
char __fastcall sub_F0B8C( int a1, int a2)
{
  int16_t v3; // dx
  char v4; // cl

  v3 = -1;
  v4 = 0;
  if ( a1 == -*(int16_t *)(dword_192680 + 167) )
  {
    v3 = 666;
  }
  else if ( a1 == -*(int16_t *)(dword_192680 + 169) )
  {
    v3 = 667;
  }
  else if ( a1 == -*(int16_t *)(dword_192680 + 177) )
  {
    v3 = 672;
  }
  else if ( a1 == -*(int16_t *)(dword_192680 + 223) )
  {
    v3 = 673;
  }
  else if ( a1 == -*(int16_t *)(dword_192680 + 225) )
  {
    v3 = 674;
  }
  else if ( a1 == -*(int16_t *)(dword_192680 + 173) )
  {
    v3 = 669;
  }
  else if ( a1 == -*(int16_t *)(dword_192680 + 175) )
  {
    v3 = 670;
  }
  else if ( a1 == -*(int16_t *)(dword_192680 + 179) )
  {
    v3 = 671;
  }
  else if ( a1 == -*(int16_t *)(dword_192680 + 171) )
  {
    v3 = 668;
  }
  if ( v3 != -1 )
  {
    byte_199CAE = a2;
    sub_7AA05();
    v4 = 1;
    sub_A59A1();
    byte_199CAE = 0;
    sub_7AA05();
  }
  return v4;
}
// 192680: using guessed type int dword_192680;
// 199CAE: using guessed type char byte_199CAE;


//----- (000F0C8E) --------------------------------------------------------
int __usercall sub_F0C8E(int16_t *a1)
{
  int v1; // ecx
  int v2; // ebx
  void *v3; // eax
  int i; // edx
  int v5; // eax
  int16_t v6; // si
  int v7; // eax
  int v8; // eax
  char *v9; // eax
  int v10; // eax
  int v12; // [esp+0h] [ebp-Ch] BYREF
  int v13; // [esp+4h] [ebp-8h]
  int v14; // [esp+8h] [ebp-4h]

  sub_107AF(&v12);
  sub_11C2F0();
  v1 = 479;
  sub_117174(3);
  sub_11946A(240);
  sub_124D7A();
  sub_128C32(0, 0, 639, 479, 0);
  v2 = sub_127C27((int)aMultigmLbx, 0, dword_193174);
  *(_DWORD *)(dword_192680 + 15) = v2;
  sub_12A478(0, 0, v2);
  v3 = sub_124E36();
  sub_1077D((int)v3, 0, v2, a1);
  i = 1;
  v5 = sub_1191CA((int)sub_F1AF4, 1);
  sub_F40D3(v5, 1, v2, a1);
  v6 = 0;
  *(_BYTE *)(dword_192680 + 270) = 4;
  while ( 1 )
  {
    sub_11C2F0();
    sub_EFF87();
    sub_12C2A0();
    v2 = sub_1171AB(v7, i, v2, v1);
    *(_WORD *)(dword_192680 + 257) = (uint16_t)sub_114177();
    v8 = sub_139659() >= 10 ? 10 : sub_139659();
    v14 = v8;
    for ( i = 0; (int16_t)i < (int16_t)v14; ++i )
    {
      if ( (int16_t)v2 > 0 )
      {
        a1 = (int16_t *)dword_192680;
        v1 = dword_192680 + 2 * (int16_t)i;
        if ( (_WORD)v2 == *(_WORD *)(v1 + 167) )
        {
          v9 = sub_13968A((int16_t)i);
          if ( *v9 )
          {
            strcpy((char *)byte_1AB082, v9);
            a1 = byte_1AB082;
            v6 = 1;
          }
        }
      }
    }
    if ( (_WORD)v2 == *(_WORD *)(dword_192680 + 223) )
    {
      v13 = -1;
      word_199A08 = 15;
      v6 = 1;
      sub_139062();
      LOBYTE(byte_1AB082[0]) = 0;
    }
    if ( v6 )
      break;
    sub_124D41();
    sub_F1AF4();
    sub_1077D(v10, i, v2, a1);
  }
  sub_107BA(&v12);
  sub_11C2F0();
  sub_117174(3);
  return v13;
}
// F0D32: variable 'v7' is possibly undefined
// F0DEA: variable 'v10' is possibly undefined
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 199A08: using guessed type int16_t word_199A08;
// 1AB082: using guessed type int16_t byte_1AB082[2];


//----- (000F0E17) --------------------------------------------------------
int __usercall sub_F0E17(void *a1, int a2, int a3, int16_t *a4)
{
  _DWORD *v5; // eax
  int16_t v6; // ax
  int v7; // ebx
  int16_t *v8; // eax
  int v9; // ebx
  int v10; // eax
  int i; // ebx
  _BYTE *v12; // edx
  void *v13; // edi
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  char *v17; // eax
  int16_t v18; // ax
  void *v19; // eax
  int v20; // eax
  _WORD *v22; // [esp+0h] [ebp-28h]
  _BYTE v23[16]; // [esp+4h] [ebp-24h] BYREF
  int v24; // [esp+14h] [ebp-14h] BYREF
  int v25; // [esp+18h] [ebp-10h]
  int v26; // [esp+1Ch] [ebp-Ch]
  _BYTE v27[4]; // [esp+20h] [ebp-8h] BYREF
  char v28; // [esp+24h] [ebp-4h]

  v28 = a3;
  v27[0] = 0;
  v25 = 0;
  memset(v23, -1, sizeof(v23));
  v26 = 0;
  v5 = sub_107AF(&v24);
  if ( a2 )
    sub_F3FC6((int)v5, -1, 16, a4);
  v6 = sub_7A54F();
  v7 = dword_193174;
  *(_WORD *)(dword_192680 + 481) = v6;
  v8 = (int16_t *)sub_127C27((int)aMultigmLbx, 27, v7);
  v9 = dword_192680;
  *(_DWORD *)(dword_192680 + 35) = v8;
  *(_WORD *)(v9 + 243) = (640 - *v8) / 2;
  v10 = (480
       - (int16_t)(*(_WORD *)(*(_DWORD *)(v9 + 43) + 2)
                 + *(_WORD *)(*(_DWORD *)(v9 + 35) + 2)
                 + *(_WORD *)(v9 + 481) * *(_WORD *)(*(_DWORD *)(v9 + 39) + 2)
                 - 1))
      / 2;
  *(_BYTE *)(v9 + 488) = 0;
  *(_BYTE *)(v9 + 489) = 1;
  *(_WORD *)(v9 + 245) = v10;
  sub_EFB50();
  sub_1191CA((int)sub_F166E, 1);
  i = 11;
  v12 = v27;
  *(_BYTE *)(dword_192680 + 270) = 4;
  sub_8F1C4((void (__fastcall *)(int, int))sub_F166E, v27, 11);
  LOBYTE(v12) = v28;
  v13 = (void *)(dword_192680 + 260);
  *(_BYTE *)(dword_192680 + 259) = v28;
  qmemcpy(v13, a1, 8u);
  v14 = 0;
  do
  {
    sub_12C2A0();
    v12 = (_BYTE *)sub_1171AB(v15, (int)v12, i, v14);
    *(_WORD *)(dword_192680 + 257) = (uint16_t)sub_114177();
    for ( i = 0; (int16_t)i < word_199998 && !(_WORD)v25; ++i )
    {
      v16 = 2 * (int16_t)i + dword_192680;
      if ( ((_WORD)v12 == *(_WORD *)(v16 + 187) || (_WORD)v12 == *(_WORD *)(v16 + 167))
        && !*(_BYTE *)(dword_192680 + (int16_t)i + 260) )
      {
        v25 = 1;
        *v22 = i;
      }
    }
    if ( v28 && (_WORD)v12 == *(_WORD *)(dword_192680 + 237) )
    {
      v17 = sub_7A990(0xF5u);
      sub_77658((int)v17);
      if ( v18 )
      {
        v25 = 1;
        v26 = 1;
      }
      else
      {
        sub_124D7A();
        v14 = 479;
        i = 639;
        v12 = 0;
        sub_128C32(0, 0, 639, 479, 0);
        v19 = sub_124E36();
        sub_1077D((int)v19, 0, 639, (int16_t *)v13);
        sub_EFB50();
      }
    }
    if ( !(_WORD)v25 )
    {
      sub_124D41();
      sub_F166E();
      sub_1077D(v20, (int)v12, i, (int16_t *)v13);
    }
    sub_12C2C6(2);
  }
  while ( !(_WORD)v25 && !word_199A0E );
  sub_107BA(&v24);
  sub_11C2F0();
  sub_117174(3);
  dword_192680 = 0;
  return v26;
}
// F0F3B: variable 'v15' is possibly undefined
// F0F94: variable 'v22' is possibly undefined
// F0FCE: variable 'v18' is possibly undefined
// F101A: variable 'v20' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 199998: using guessed type int16_t word_199998;
// 199A0E: using guessed type int16_t word_199A0E;


//----- (000F1075) --------------------------------------------------------
void __fastcall sub_F1075(int a1, int a2)
{
  int16_t v2; // cx
  int16_t v3; // dx
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // edi
  int v11; // ecx
  int16_t v12; // si
  _BYTE *v13; // edx
  int16_t v14; // cx
  int16_t *v15; // eax
  int16_t v16; // ax
  int v17; // eax
  int64_t v18; // rax
  _BYTE v19[100]; // [esp+0h] [ebp-4Ah] BYREF
  _BYTE v20[8]; // [esp+64h] [ebp+1Ah] BYREF
  _BYTE v21[8]; // [esp+6Ch] [ebp+22h] BYREF
  _BYTE v22[8]; // [esp+74h] [ebp+2Ah] BYREF
  _BYTE v23[8]; // [esp+7Ch] [ebp+32h] BYREF
  int v24; // [esp+84h] [ebp+3Ah]
  int v25; // [esp+88h] [ebp+3Eh]
  int v26; // [esp+8Ch] [ebp+42h]
  int i; // [esp+90h] [ebp+46h]
  int v28; // [esp+94h] [ebp+4Ah]
  int v29; // [esp+98h] [ebp+4Eh]
  int v30; // [esp+9Ch] [ebp+52h]
  int v31; // [esp+A0h] [ebp+56h]
  int v32; // [esp+A4h] [ebp+5Ah]
  int v33; // [esp+A8h] [ebp+5Eh]
  int v34; // [esp+ACh] [ebp+62h]
  int v35; // [esp+B0h] [ebp+66h]
  int v36; // [esp+B4h] [ebp+6Ah]
  int v37; // [esp+B8h] [ebp+6Eh]
  int v38; // [esp+BCh] [ebp+72h]
  _BYTE v39[4]; // [esp+C0h] [ebp+76h] BYREF
  char v40[4]; // [esp+C4h] [ebp+7Ah] BYREF
  char v41[4]; // [esp+C8h] [ebp+7Eh] BYREF

  v29 = 4;
  LOWORD(a2) = *(_WORD *)(dword_192680 + 243);
  v38 = 0;
  v28 = a2;
  LOWORD(a2) = *(_WORD *)(dword_192680 + 245);
  ++*(_BYTE *)(dword_192680 + 490);
  v37 = a2;
  v34 = a2;
  if ( word_19994C )
  {
    sub_124D41();
    byte_199F37 = 1;
    sub_128C32(0, 0, 639, 479, 0);
    sub_84E9D();
    word_19994C = 0;
    *(_BYTE *)(dword_192680 + 480) = 1;
  }
  v2 = 0;
  for ( *(_DWORD *)(dword_192680 + 35) = sub_127C27((int)aMultigmLbx, 42, dword_193174);
        ;
        sub_12A478(v28, v37, *(_DWORD *)(dword_192680 + 35)) )
  {
    v3 = *(uint8_t *)(dword_192680 + 490);
    if ( v2 >= v3 )
      break;
    sub_12B753(*(_DWORD *)(dword_192680 + 35), v2++);
  }
  if ( v3 >= *(int16_t *)(*(_DWORD *)(dword_192680 + 35) + 6) )
    *(_BYTE *)(dword_192680 + 490) = 0;
  v4 = *(_DWORD *)(dword_192680 + 35);
  LOWORD(v4) = *(_WORD *)(v4 + 2);
  v34 += v4;
  v5 = sub_127C27((int)aMultigmLbx, 43, dword_193174);
  v6 = dword_192680;
  *(_DWORD *)(dword_192680 + 39) = v5;
  if ( *(_BYTE *)(v6 + 480) )
  {
    v7 = v5;
    v5 = (int16_t)v34;
    sub_12A478(v28, v34, v7);
  }
  LOWORD(v5) = *(_WORD *)(*(_DWORD *)(dword_192680 + 39) + 2);
  v34 += v5;
  v33 = v34;
  if ( *(_BYTE *)(dword_192680 + 480) )
  {
    v8 = sub_127C27((int)aMultigmLbx, 40, dword_193174);
    *(_DWORD *)(dword_192680 + 31) = v8;
    sub_12A478(v28, v34, v8);
  }
  for ( i = 0; (int16_t)i < word_199998; ++i )
  {
    v24 = (int16_t)i;
    sub_F30B9(i, v40, v41, v39);
    byte_199F34 = v41[0] + 1;
    v25 = (int16_t)v29;
    qmemcpy(v21, sub_8E5C5(v29, (uint8_t)v40[0] + 1, v39[0] + 2), sizeof(v21));
    byte_199F34 = v41[0];
    qmemcpy(v22, sub_8E5C5(v25, (uint8_t)v40[0], v39[0]), sizeof(v22));
    byte_199F34 = v41[0] + 3;
    qmemcpy(v20, sub_8E5C5(v25, (uint8_t)v40[0] + 1, v39[0] + 4), sizeof(v20));
    v9 = 3753 * v24 + dword_197F98;
    if ( *(_BYTE *)(v9 + 40) == 100 && !*(_BYTE *)(v9 + 36) )
    {
      v10 = *(int16_t *)(dword_192680 + 243) + 92 + 294 * (v24 % 2);
      v11 = 36 * (v24 / 2) + 63 + *(int16_t *)(dword_192680 + 245);
      v12 = i;
      if ( byte_1AAF7E[v24] )
      {
        sub_F2742(v24);
        v13 = v22;
      }
      else
      {
        sub_F27B7(v24, v38, 1);
        v13 = v21;
      }
      sub_120BB5(4, (int)v13);
      sub_120E8C(1);
      v14 = v11 + (29 - sub_122259()) / 2;
      sub_1212B3(v10, v14, dword_197F98 + 3753 * v12 + 1);
      if ( (int16_t)sub_12066F(dword_197F98 + 3753 * (int16_t)i + 1) < 152 )
      {
        v15 = sub_78477(v12);
        sub_1210B7(v10 + 205, v14, (int)v15);
      }
      ++v38;
    }
  }
  v36 = v28 + 24;
  v32 = 0;
  v35 = v34 + 14;
  while ( (int16_t)v32 < *(_DWORD *)(dword_1AA250 + 1148) )
  {
    v26 = 82 * (int16_t)v32;
    v30 = v36;
    v16 = *(uint8_t *)(v26 + dword_1AA250);
    v31 = v35;
    if ( v16 >= 8 )
    {
      byte_199F34 = 16;
      qmemcpy(v23, sub_8E5C5(*(uint8_t *)(dword_192680 + 270), 12, 23), sizeof(v23));
      sub_120BB5(*(uint8_t *)(dword_192680 + 270), (int)v23);
      sprintf(v19, "( GNN )  %s", (char *)(v26 + dword_1AA250 + 1));
    }
    else
    {
      v25 = v16;
      sub_F30B9(v16, v40, v41, v39);
      byte_199F34 = v41[0] + 1;
      qmemcpy(
        v21,
        sub_8E5C5(*(uint8_t *)(dword_192680 + 270), (uint8_t)v40[0] + 1, v39[0] + 2),
        sizeof(v21));
      sub_120BB5(*(uint8_t *)(dword_192680 + 270), (int)v21);
      sprintf(v19, "(%s)  %s", (char *)(dword_197F98 + 3753 * v25 + 1), (char *)(v26 + dword_1AA250 + 1));
    }
    if ( !(_WORD)v32 )
    {
      sub_128AB6(v30, v31, v30 + 570, (int16_t)(v31 + 11));
      sub_12B634();
      v17 = sub_127C27((int)aMultigmLbx, 40, dword_193174);
      *(_DWORD *)(dword_192680 + 31) = v17;
      sub_12A478(v28, v33, v17);
      sub_12B65C();
      sub_128BE7();
    }
    v35 += 12;
    ++v32;
    sub_1212B3(v30, v31, (int)v19);
  }
  v18 = sprintf(v19, "(%s)  ", (char *)(dword_197F98 + 3753 * word_19999C + 1));
  sub_F30B9(word_19999C, (char *)HIDWORD(v18), v41, v39);
  qmemcpy(v21, sub_8E5C5(v29, (uint8_t)v40[0] + 1, v39[0] + 2), sizeof(v21));
  byte_199F34 = v41[0];
  sub_120BB5(*(uint8_t *)(dword_192680 + 270), (int)v21);
  sub_1212B3(v28 + 25, *(_WORD *)(dword_192680 + 191) + v37 + 190, (int)v19);
  if ( *(_BYTE *)(dword_192680 + 480) )
  {
    sub_124DEC();
    sub_124C08();
  }
  *(_BYTE *)(dword_192680 + 480) = 0;
  JUMPOUT(0xF5204);
}
// F1669: control flows out of bounds to F5204
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 199F34: using guessed type char byte_199F34;
// 199F37: using guessed type char byte_199F37;
// 1AA250: using guessed type int dword_1AA250;


//----- (000F166E) --------------------------------------------------------
void sub_F166E()
{
  int16_t v0; // di
  int16_t v1; // cx
  int v2; // eax
  int v3; // edx
  int v4; // eax
  int16_t v5; // si
  int16_t v6; // bx
  int16_t v7; // cx
  int16_t v8; // si
  int v9; // eax
  _BYTE *v10; // ebx
  int16_t v11; // si
  _BYTE *v12; // eax
  int v13; // edx
  int16_t v14; // ax
  char *v15; // edx
  int v16; // eax
  int v17; // edx
  int16_t v18; // bx
  int16_t v19; // cx
  int16_t v20; // dx
  int v21; // eax
  int16_t *v22; // eax
  _BYTE v23[100]; // [esp+0h] [ebp-1Ah] BYREF
  char v24[8]; // [esp+64h] [ebp+4Ah] BYREF
  char v25[8]; // [esp+6Ch] [ebp+52h] BYREF
  char v26[8]; // [esp+74h] [ebp+5Ah] BYREF
  int v27; // [esp+7Ch] [ebp+62h]
  _BYTE *v28; // [esp+80h] [ebp+66h]
  int v29; // [esp+84h] [ebp+6Ah]
  int v30; // [esp+88h] [ebp+6Eh]
  int v31; // [esp+8Ch] [ebp+72h]
  char v32; // [esp+90h] [ebp+76h]
  char v33; // [esp+94h] [ebp+7Ah]
  char v34; // [esp+98h] [ebp+7Eh]

  v29 = 0;
  v0 = *(_WORD *)(dword_192680 + 243);
  v1 = *(_WORD *)(dword_192680 + 245);
  if ( *(_BYTE *)(dword_192680 + 480) )
  {
    sub_124D41();
    v2 = sub_127C27((int)aMultigmLbx, 0, dword_193174);
    *(_DWORD *)(dword_192680 + 15) = v2;
    sub_12A478(0, 0, v2);
    sub_124DEC();
    sub_124C08();
    *(_BYTE *)(dword_192680 + 480) = 0;
  }
  v3 = sub_127C27((int)aMultigmLbx, 27, dword_193174);
  v4 = dword_192680;
  *(_DWORD *)(dword_192680 + 35) = v3;
  v5 = 0;
  ++*(_BYTE *)(v4 + 490);
  while ( 1 )
  {
    v6 = *(uint8_t *)(dword_192680 + 490);
    if ( v5 >= v6 )
      break;
    sub_12B753(*(_DWORD *)(dword_192680 + 35), v5++);
    sub_12A478(v0, v1, *(_DWORD *)(dword_192680 + 35));
  }
  if ( v6 >= *(int16_t *)(*(_DWORD *)(dword_192680 + 35) + 6) )
    *(_BYTE *)(dword_192680 + 490) = 0;
  v7 = *(_WORD *)(*(_DWORD *)(dword_192680 + 35) + 2) + v1;
  v8 = 0;
  *(_DWORD *)(dword_192680 + 39) = sub_127C27((int)aMultigmLbx, 28, dword_193174);
  while ( *(int16_t *)(dword_192680 + 481) - 1 > v8 )
  {
    sub_12A478(v0, v7, *(_DWORD *)(dword_192680 + 39));
    ++v8;
    v7 += *(_WORD *)(*(_DWORD *)(dword_192680 + 39) + 2);
  }
  v9 = sub_127C27((int)aMultigmLbx, 29, dword_193174);
  HIWORD(v10) = HIWORD(v9);
  *(_DWORD *)(dword_192680 + 43) = v9;
  sub_12A478(v0, v7, v9);
  v11 = 0;
  v30 = 36 * v29 + 64;
  while ( v11 < word_199998 )
  {
    v12 = (_BYTE *)(3753 * v11 + dword_197F98);
    if ( v12[40] == 100 && !v12[36] )
    {
      HIWORD(v13) = HIWORD(dword_192680);
      LOWORD(v10) = *(_WORD *)(dword_192680 + 243);
      v14 = (uint8_t)v12[38];
      LOWORD(v13) = *(_WORD *)(dword_192680 + 245);
      v28 = v10 + 106;
      v31 = v30 + v13;
      sub_F3119(v14, v26, v24, v25);
      if ( *(_BYTE *)(v11 + dword_192680 + 260) )
      {
        v15 = v24;
        v16 = *(uint8_t *)(dword_192680 + 270);
        v32 = 0;
      }
      else
      {
        v17 = dword_192680 + 2 * v11;
        v18 = *(_WORD *)(dword_192680 + 257);
        v32 = 1;
        if ( v18 == *(_WORD *)(v17 + 187) || v18 == *(_WORD *)(v17 + 167) )
        {
          v19 = (uint8_t)v26[0];
          v33 = v26[0] + 5;
          v20 = 1;
          v34 = v26[0] + 1;
          do
          {
            v26[v20] += *(_BYTE *)(dword_192680 + 488);
            if ( (uint8_t)v26[v20] < v19 + 1 )
              v26[v20] = v34;
            v27 = (uint8_t)v26[v20];
            if ( v19 + 5 < v27 )
              v26[v20] = v33;
            ++v20;
          }
          while ( v20 < 8 );
          v21 = dword_192680;
          *(_BYTE *)(dword_192680 + 488) += *(_BYTE *)(dword_192680 + 489);
          if ( *(char *)(v21 + 488) < 2 )
          {
            if ( *(char *)(v21 + 488) <= -1 )
            {
              *(_BYTE *)(v21 + 488) = -1;
              *(_BYTE *)(v21 + 489) = 1;
            }
          }
          else
          {
            *(_BYTE *)(v21 + 488) = 2;
            *(_BYTE *)(v21 + 489) = -1;
          }
        }
        v15 = v26;
        v16 = *(uint8_t *)(dword_192680 + 270);
      }
      sub_120BB5(v16, (int)v15);
      v22 = sub_78477(v11);
      sprintf(v23, "%s (%s)", (char *)(dword_197F98 + 3753 * v11 + 1), (char *)v22);
      v10 = v23;
      v31 = (int16_t)v31 + (29 - sub_122259()) / 2;
      sub_1212B3((int16_t)v28, v31, (int)v23);
      if ( v32 )
      {
        HIWORD(v10) = 0;
        sub_F27B7(v11, v29, 0);
      }
      v30 += 36;
      ++v29;
    }
    ++v11;
  }
  JUMPOUT(0xF1662);
}
// F19C2: control flows out of bounds to F1662
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000F19C7) --------------------------------------------------------
int sub_F19C7()
{
  int v0; // eax
  int v1; // eax
  int v2; // ebx
  int v3; // edx
  int16_t v4; // cx
  int result; // eax
  int16_t v6; // bx

  sub_124D41();
  if ( sub_C5BB0() <= 0 )
  {
    if ( *(_BYTE *)(dword_192680 + 480) )
    {
      sub_128C32(0, 0, 639, 479, 0);
      v1 = sub_127C27((int)aMultigmLbx, 0, dword_193174);
      *(_DWORD *)(dword_192680 + 15) = v1;
      sub_12A478(0, 0, v1);
      sub_124DEC();
      sub_124C08();
      *(_BYTE *)(dword_192680 + 480) = 0;
    }
  }
  else
  {
    sub_128C32(0, 0, 639, 479, 0);
    v0 = sub_127C27((int)aMultigmLbx, 0, dword_193174);
    *(_DWORD *)(dword_192680 + 15) = v0;
    sub_12A478(0, 0, v0);
  }
  v2 = dword_193174;
  v3 = *(int16_t *)(dword_192680 + 241);
  ++*(_BYTE *)(dword_192680 + 490);
  v4 = 0;
  for ( *(_DWORD *)(dword_192680 + 47) = sub_127C27((int)aMultigmLbx, v3, v2);
        ;
        sub_12A478(*(_WORD *)(dword_192680 + 243), *(_WORD *)(dword_192680 + 245), *(_DWORD *)(dword_192680 + 47)) )
  {
    result = dword_192680;
    v6 = *(uint8_t *)(dword_192680 + 490);
    if ( v4 >= v6 )
      break;
    sub_12B753(*(_DWORD *)(dword_192680 + 47), v4++);
  }
  if ( v6 >= *(int16_t *)(*(_DWORD *)(dword_192680 + 47) + 6) )
    *(_BYTE *)(dword_192680 + 490) = 0;
  return result;
}
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;


//----- (000F1AF4) --------------------------------------------------------
void sub_F1AF4()
{
  int v0; // edx
  int v1; // edx
  int v2; // eax
  int v3; // ebx
  _BYTE *v4; // edi
  int v5; // ebx
  char *v6; // eax
  int v7; // edx
  int v8; // edx
  char *v9; // esi
  int v10; // eax
  int16_t v11; // ax
  char v12[100]; // [esp+0h] [ebp-2h] BYREF
  _BYTE v13[8]; // [esp+64h] [ebp+62h] BYREF
  _BYTE *v14; // [esp+6Ch] [ebp+6Ah]
  int v15; // [esp+70h] [ebp+6Eh]
  int v16; // [esp+74h] [ebp+72h]
  int v17; // [esp+78h] [ebp+76h]
  int v18; // [esp+7Ch] [ebp+7Ah]
  char v19; // [esp+80h] [ebp+7Eh]

  if ( sub_139659() >= 10 )
    v0 = 10;
  else
    v0 = sub_139659();
  v16 = v0;
  v1 = sub_127C27((int)aMultigmLbx, 41, dword_193174);
  v2 = dword_192680;
  v18 = 0;
  *(_DWORD *)(dword_192680 + 27) = v1;
  v3 = v1;
  LOWORD(v1) = *(_WORD *)(v2 + 245);
  LOWORD(v2) = *(_WORD *)(v2 + 243);
  v17 = 67;
  sub_12A478(v2, v1, v3);
  qmemcpy(&unk_1BB598, &unk_183580, 0x40u);
  v4 = &unk_1BB598;
  while ( (int16_t)v18 < (int16_t)v16 )
  {
    v5 = (int16_t)v18;
    v19 = 0;
    v6 = sub_13968A((int16_t)v18);
    if ( *v6 )
    {
      HIWORD(v7) = HIWORD(dword_192680);
      LOWORD(v4) = *(_WORD *)(dword_192680 + 243);
      LOWORD(v7) = *(_WORD *)(dword_192680 + 245);
      v14 = v4 + 38;
      v8 = v17 + v7;
      strcpy(v12, v6);
      v15 = v8;
      if ( *(_WORD *)(dword_192680 + 257) == *(_WORD *)(dword_192680 + 2 * v5 + 167) )
      {
        byte_199F34 = -105;
        v9 = sub_8E5C5(*(uint8_t *)(dword_192680 + 270), 145, 153);
        v19 = 1;
      }
      else
      {
        byte_199F34 = -107;
        v9 = sub_8E5C5(*(uint8_t *)(dword_192680 + 270), 145, 151);
      }
      qmemcpy(v13, v9, sizeof(v13));
      v4 = v13;
      sub_120BB5(*(uint8_t *)(dword_192680 + 270), (int)v13);
      if ( v19 )
      {
        sub_8F7DF(*(char *)(dword_192680 + 488));
        v10 = dword_192680;
        if ( *(char *)(dword_192680 + 488) < 4 )
        {
          if ( *(char *)(dword_192680 + 488) <= -3 )
          {
            *(_BYTE *)(dword_192680 + 488) = -3;
            *(_BYTE *)(v10 + 489) = 1;
          }
        }
        else
        {
          *(_BYTE *)(dword_192680 + 488) = 4;
          *(_BYTE *)(v10 + 489) = -1;
        }
        *(_BYTE *)(dword_192680 + 488) += *(_BYTE *)(dword_192680 + 489);
      }
      v11 = sub_122259();
      sub_1212B3((_WORD)v14 + 9, v15 + (22 - v11) / 2, (int)v12);
    }
    v17 += 27;
    ++v18;
  }
  JUMPOUT(0xF1662);
}
// F1CE1: control flows out of bounds to F1662
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 199F34: using guessed type char byte_199F34;


//----- (000F1CE6) --------------------------------------------------------
int sub_F1CE6()
{
  int v0; // ebx
  int v1; // eax
  int v2; // edx
  int v3; // ebx
  int v4; // edx
  int16_t v5; // ax
  int v6; // eax
  char v7; // dl
  int v8; // eax
  int v9; // kr00_4
  int v10; // eax
  int16_t v11; // bx
  int v12; // edx
  char *v13; // eax
  int16_t v14; // cx
  int16_t v15; // dx
  int16_t v16; // ax
  int result; // eax
  uint8_t v18; // dl
  int v19; // ebx
  int16_t v20; // dx
  _BYTE v21[28]; // [esp+0h] [ebp-5Ch] BYREF
  _BYTE v22[28]; // [esp+1Ch] [ebp-40h] BYREF
  _BYTE v23[8]; // [esp+38h] [ebp-24h] BYREF
  int v24; // [esp+40h] [ebp-1Ch]
  int v25; // [esp+44h] [ebp-18h]
  int v26; // [esp+48h] [ebp-14h]
  int v27; // [esp+4Ch] [ebp-10h]
  int v28; // [esp+50h] [ebp-Ch]
  int v29; // [esp+54h] [ebp-8h]
  char v30; // [esp+58h] [ebp-4h]

  if ( *(_BYTE *)(dword_192680 + 480) || word_19994C )
  {
    v0 = dword_193174;
    *(_BYTE *)(dword_192680 + 480) = 0;
    word_19994C = 0;
    v1 = sub_127C27((int)aMultigmLbx, 0, v0);
    *(_DWORD *)(dword_192680 + 15) = v1;
    sub_12A478(0, 0, v1);
    sub_124DEC();
  }
  if ( (uint8_t)byte_199F3A < 2u )
  {
    if ( byte_199F3A != 1 )
      goto LABEL_14;
    v2 = 255;
  }
  else if ( (uint8_t)byte_199F3A <= 2u )
  {
    v2 = 18;
  }
  else
  {
    if ( byte_199F3A != 3 )
      goto LABEL_14;
    v2 = 254;
  }
  *(_DWORD *)(dword_192680 + 27) = sub_127C27((int)aMultigmLbx, v2, dword_193174);
LABEL_14:
  v29 = 0;
  v25 = 64;
  v3 = *(_DWORD *)(dword_192680 + 27);
  v4 = *(int16_t *)(dword_192680 + 245);
  v5 = *(_WORD *)(dword_192680 + 243);
  v26 = 0;
  sub_12A478(v5, v4, v3);
  qmemcpy(&unk_1BB598, &unk_183580, 0x40u);
  do
  {
    HIWORD(v6) = HIWORD(dword_192680);
    LOWORD(v4) = *(_WORD *)(dword_192680 + 243);
    LOWORD(v6) = *(_WORD *)(dword_192680 + 245);
    v28 = v25 + v6 + 2;
    v24 = (int16_t)v29;
    v27 = v4 + 38;
    sub_80658(&saveSlotInfo_199699[1 + (int16_t)v29]);
    qmemcpy(v22, (void *)((int16_t)v26 + dword_192688), 0x19u);
    qmemcpy(v21, (void *)((int16_t)v26 + dword_19268C), 0x19u);
    qmemcpy(v23, sub_8E5C5(*(uint8_t *)(dword_192680 + 270), 144, 147), sizeof(v23));
    v30 = 0;
    if ( *(_BYTE *)(v24 + dword_192680 + 203) )
    {
      if ( *(_WORD *)(dword_192680 + 257) == *(_WORD *)(dword_192680 + 2 * v24 + 167) )
      {
        qmemcpy(v23, sub_8E5C5(*(uint8_t *)(dword_192680 + 270), 144, 153), sizeof(v23));
        v7 = *(_BYTE *)(dword_192680 + 489);
        v30 = 1;
        *(_BYTE *)(dword_192680 + 488) += v7;
      }
      else
      {
        qmemcpy(v23, sub_8E5C5(*(uint8_t *)(dword_192680 + 270), 144, 151), sizeof(v23));
      }
    }
    sub_120BB5(*(uint8_t *)(dword_192680 + 270), (int)v23);
    if ( v30 )
    {
      sub_8F7DF(*(char *)(dword_192680 + 488));
      v8 = dword_192680;
      if ( *(char *)(dword_192680 + 488) < 4 )
      {
        if ( *(char *)(dword_192680 + 488) <= -2 )
        {
          *(_BYTE *)(dword_192680 + 488) = -2;
          *(_BYTE *)(v8 + 489) = 1;
        }
      }
      else
      {
        *(_BYTE *)(dword_192680 + 488) = 4;
        *(_BYTE *)(v8 + 489) = -1;
      }
      *(_BYTE *)(dword_192680 + 488) += *(_BYTE *)(dword_192680 + 489);
    }
    v9 = 22 - sub_122259();
    v10 = 37 * (int16_t)v29;
    v11 = v27 + 9;
    v12 = v28 + v9 / 2;
    if (saveSlotInfo_199699[1 + v10/37].name[0])
      v13 = &saveSlotInfo_199699[1 + v10/37];
    else
      v13 = sub_7A990(0x184u);
    sub_1212B3(v11, v12, (int)v13);
    sub_120BB5(1, (int)v23);
    v14 = v27 + 243;
    sub_1212B3(v27 + 243, v28, (int)v22);
    v15 = v28 + 2;
    v16 = sub_122259();
    sub_1212B3(v14, v15 + v16, (int)v21);
    v4 = (int16_t)v29;
    result = 37 * (int16_t)v29;
    if (saveSlotInfo_199699[1 + result/37].name[0])
    {
      v18 = *(_BYTE *)((int16_t)v29 + dword_192680 + 203);
      result = 0;
      if ( v18 )
      {
        if ( v18 <= 1u )
        {
          result = 259;
        }
        else if ( v18 <= 3u )
        {
          result = 260;
        }
      }
      else
      {
        result = 258;
      }
      if ( (int16_t)result > 0 )
      {
        v19 = sub_127C27((int)off_17CF22, (int16_t)result, dword_193174);
        v20 = v28 + 2;
        v4 = (int16_t)(v20 + sub_122259());
        result = sub_12A478(v27 + 380, v4, v19);
      }
    }
    v25 += 27;
    ++v29;
    v26 += 25;
  }
  while ( (int16_t)v29 < 10 );
  return result;
}
// 17CF22: using guessed type char *off_17CF22;
// 192680: using guessed type int dword_192680;
// 192688: using guessed type int dword_192688;
// 19268C: using guessed type int dword_19268C;
// 193174: using guessed type int dword_193174;
// 19994C: using guessed type int16_t word_19994C;
// 199F3A: using guessed type char byte_199F3A;


//----- (000F2082) --------------------------------------------------------
int sub_F2082()
{
  int v0; // edx
  int v1; // eax

  v0 = sub_127C27((int)aMultigmLbx, 1, dword_193174);
  v1 = dword_192680;
  *(_DWORD *)(dword_192680 + 19) = v0;
  sub_12A478(*(_WORD *)(v1 + 243), *(_WORD *)(v1 + 245), v0);
  sub_12B753(*(_DWORD *)(dword_192680 + 95), *(int16_t *)(dword_192680 + 247));
  sub_12A478(*(_WORD *)(dword_192680 + 243) + 59, *(_WORD *)(dword_192680 + 245) + 91, *(_DWORD *)(dword_192680 + 95));
  sub_12B753(*(_DWORD *)(dword_192680 + 99), *(int16_t *)(dword_192680 + 249));
  sub_12A478(*(_WORD *)(dword_192680 + 243) + 59, *(_WORD *)(dword_192680 + 245) + 122, *(_DWORD *)(dword_192680 + 99));
  sub_12B753(*(_DWORD *)(dword_192680 + 103), *(int16_t *)(dword_192680 + 251));
  sub_12A478(*(_WORD *)(dword_192680 + 243) + 59, *(_WORD *)(dword_192680 + 245) + 155, *(_DWORD *)(dword_192680 + 103));
  sub_12B753(*(_DWORD *)(dword_192680 + 107), *(int16_t *)(dword_192680 + 253));
  sub_12A478(*(_WORD *)(dword_192680 + 243) + 59, *(_WORD *)(dword_192680 + 245) + 187, *(_DWORD *)(dword_192680 + 107));
  return sub_F21B2();
}
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;


//----- (000F21B2) --------------------------------------------------------
int sub_F21B2()
{
  int16_t v0; // cx
  int16_t v1; // si
  int result; // eax

  v0 = *(_WORD *)(dword_192680 + 243);
  v1 = *(_WORD *)(dword_192680 + 245);
  if ( *(int16_t *)(dword_192680 + 227) == -1000 )
  {
    sub_12B753(*(_DWORD *)(dword_192680 + 123), 2);
    sub_12A478(v0 + 269, v1 + 91, *(_DWORD *)(dword_192680 + 123));
  }
  if ( *(int16_t *)(dword_192680 + 229) == -1000 )
  {
    sub_12B753(*(_DWORD *)(dword_192680 + 127), 2);
    sub_12A478(v0 + 269, v1 + 122, *(_DWORD *)(dword_192680 + 127));
  }
  if ( *(int16_t *)(dword_192680 + 231) == -1000 )
  {
    sub_12B753(*(_DWORD *)(dword_192680 + 131), 2);
    sub_12A478(v0 + 269, v1 + 155, *(_DWORD *)(dword_192680 + 131));
  }
  result = dword_192680;
  if ( *(int16_t *)(dword_192680 + 233) == -1000 )
  {
    sub_12B753(*(_DWORD *)(dword_192680 + 135), 2);
    return sub_12A478(v0 + 269, v1 + 187, *(_DWORD *)(dword_192680 + 135));
  }
  return result;
}
// 192680: using guessed type int dword_192680;


//----- (000F22D5) --------------------------------------------------------
void __fastcall sub_F22D5(int a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int16_t v5; // cx
  uint16_t v6; // ax
  char *v7; // eax
  int16_t v8; // ax
  int v9; // edi
  int v10; // esi
  int v11; // edi
  int v12; // edx
  int v13; // esi
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int64_t v17; // rax
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int16_t v21; // dx
  char *v22; // ebx
  _BYTE v23[120]; // [esp+0h] [ebp-32h] BYREF
  _BYTE v24[8]; // [esp+78h] [ebp+46h] BYREF
  int v25; // [esp+80h] [ebp+4Eh]
  int v26; // [esp+84h] [ebp+52h]
  int v27; // [esp+88h] [ebp+56h]
  int v28; // [esp+8Ch] [ebp+5Ah]
  int v29; // [esp+90h] [ebp+5Eh]
  int v30; // [esp+94h] [ebp+62h]
  int v31; // [esp+98h] [ebp+66h]
  int v32; // [esp+9Ch] [ebp+6Ah]
  int v33; // [esp+A0h] [ebp+6Eh]
  int v34; // [esp+A4h] [ebp+72h]
  int v35; // [esp+A8h] [ebp+76h]
  int v36; // [esp+ACh] [ebp+7Ah]
  int v37; // [esp+B0h] [ebp+7Eh]

  HIWORD(v2) = HIWORD(dword_192680);
  LOWORD(a2) = *(_WORD *)(dword_192680 + 243);
  LOWORD(v2) = *(_WORD *)(dword_192680 + 245);
  v34 = a2;
  v33 = v2;
  sub_124D41();
  v3 = sub_127C27((int)aMultigmLbx, 0, dword_193174);
  *(_DWORD *)(dword_192680 + 15) = v3;
  sub_12A478(0, 0, v3);
  v4 = sub_127C27((int)aMultigmLbx, 32, dword_193174);
  *(_DWORD *)(dword_192680 + 47) = v4;
  sub_12A478(v34, v33, v4);
  qmemcpy(&unk_1BB598, &unk_183580, 0x40u);
  byte_199F34 = -106;
  qmemcpy(v24, sub_8E5C5(4u, 146, 152), sizeof(v24));
  sub_120BB5(4, (int)v24);
  sprintf(v23, "COM%d", dword_1AAEC4 + 1);
  v5 = v33 + 63;
  sub_1212B3(v34 + 130, v33 + 63, (int)v23);
  sub_120BB5(4, (int)v24);
  sprintf(v23, "%ld", dword_1AAEC8);
  sub_1212B3(v34 + 300, v5, (int)v23);
  if ( byte_1AAF57 )
    v6 = 247;
  else
    v6 = 248;
  v7 = sub_7A990(v6);
  sprintf(v23, "%s", v7);
  sub_8FDA1((int)v23, (int)v24, 3, 2, 0, 77, 0);
  v8 = sub_8F64C();
  v9 = v33;
  v10 = v33;
  sub_1210FD(v34 + 339, v33 + 158 + 5 - v8, (int)v23);
  v11 = v9 + 93;
  sub_120BB5(4, (int)v24);
  v12 = v33 + 81;
  v13 = v10 + 96;
  v27 = v33 + 81;
  if ( *(_WORD *)(dword_192680 + 249) == 1 )
  {
    sub_F084F(dword_192680, v12);
    v14 = v34;
    v32 = 0;
    v15 = sub_127C27((int)aMultigmLbx, 38, dword_193174);
    v14 += 143;
    *(_DWORD *)(dword_192680 + 83) = v15;
    v29 = v11;
    sub_12A478(v14, v27, v15);
    v30 = v13;
    v37 = v14 + 27;
    v25 = v14 + 5;
    do
    {
      if ( *(_WORD *)(dword_192680 + 257) == *(_WORD *)(dword_192680 + 2 * (int16_t)v32 + 167) )
      {
        qmemcpy(v24, sub_8E5C5(3u, 146, 154), sizeof(v24));
        sub_120BB5(3, (int)v24);
        v16 = sub_127C27((int)aMultigmLbx, 39, dword_193174);
        *(_DWORD *)(dword_192680 + 87) = v16;
        sub_12A478(v25, v29, v16);
      }
      else
      {
        qmemcpy(v24, sub_8E5C5(3u, 146, 151), sizeof(v24));
        sub_120BB5(3, (int)v24);
      }
      v29 += 15;
      v30 += 15;
      v17 = sprintf(v23, "COM%d", (int16_t)v32++ + 1);
      sub_1212B3(v37, SWORD2(v17), (int)v23);
    }
    while ( (int16_t)v32 < 8 );
  }
  else if ( *(_WORD *)(dword_192680 + 249) == 2 )
  {
    sub_F084F(dword_192680, v12);
    v18 = v34;
    v31 = 0;
    v19 = sub_127C27((int)aMultigmLbx, 38, dword_193174);
    v28 = v11;
    v18 += 298;
    *(_DWORD *)(dword_192680 + 83) = v19;
    sub_12A478(v18, v27, v19);
    v36 = v13;
    v35 = v18 + 68;
    v26 = v18 + 5;
    do
    {
      if ( *(_WORD *)(dword_192680 + 257) == *(_WORD *)(dword_192680 + 2 * (int16_t)v31 + 167) )
      {
        qmemcpy(v24, sub_8E5C5(3u, 146, 154), sizeof(v24));
        sub_120BB5(3, (int)v24);
        v20 = sub_127C27((int)aMultigmLbx, 39, dword_193174);
        *(_DWORD *)(dword_192680 + 87) = v20;
        sub_12A478(v26, v28, v20);
      }
      else
      {
        qmemcpy(v24, sub_8E5C5(3u, 146, 151), sizeof(v24));
        sub_120BB5(3, (int)v24);
      }
      v21 = v36;
      v28 += 15;
      v36 += 15;
      v22 = &a1200[6 * (int16_t)v31++];
      sub_1210B7(v35, v21, (int)v22);
    }
    while ( (int16_t)v31 < 8 );
  }
  JUMPOUT(0xF1662);
}
// F273D: control flows out of bounds to F1662
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 199F34: using guessed type char byte_199F34;
// 1AAEC4: using guessed type int dword_1AAEC4;
// 1AAEC8: using guessed type int dword_1AAEC8;
// 1AAF57: using guessed type char byte_1AAF57;


//----- (000F2742) --------------------------------------------------------
int __fastcall sub_F2742( int a1)
{
  int v1; // esi
  int v2; // ecx
  int v3; // eax

  v1 = *(int16_t *)(dword_192680 + 243) + 40 + 294 * (a1 % 2);
  v2 = *(int16_t *)(dword_192680 + 245) + 36 * (a1 / 2) + 65;
  v3 = sub_127C27((int)aMultigmLbx, 45, dword_193174);
  *(_DWORD *)(dword_192680 + 147) = v3;
  return sub_12A478(v1, v2, v3);
}
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;


//----- (000F27B7) --------------------------------------------------------
int __fastcall sub_F27B7( int a1, int a2, int a3)
{
  int v4; // ebx
  int v5; // eax
  int16_t v6; // si
  int16_t v7; // ax
  int16_t v8; // di
  int16_t v9; // cx
  int v10; // ebx
  int16_t v11; // dx
  int16_t v12; // ax
  int v13; // esi
  int v14; // ecx
  int v16; // [esp+0h] [ebp-8h]
  int16_t v17; // [esp+4h] [ebp-4h]

  v4 = a1;
  v5 = 3753 * a1;
  v6 = *(uint8_t *)(dword_197F98 + v5 + 38);
  v7 = 8 * *(uint8_t *)(dword_197F98 + v5 + 37);
  v16 = 4 * v4;
  if ( a3 )
  {
    v17 = v6 + v7 + 150;
    v13 = *(int16_t *)(dword_192680 + 243) + 40 + 294 * (v4 % 2);
    v14 = *(int16_t *)(dword_192680 + 245) + 36 * (v4 / 2) + 65;
    v10 = sub_127C27((int)aMultigmLbx, v17, dword_193174);
    *(_DWORD *)(v16 + dword_192680 + 51) = v10;
    v11 = v14;
    v12 = v13;
  }
  else
  {
    v8 = *(_WORD *)(dword_192680 + 243);
    v9 = 36 * a2 + 65 + *(_WORD *)(dword_192680 + 245);
    v10 = sub_127C27((int)aMultigmLbx, (int16_t)(v7 + 46 + v6), dword_193174);
    *(_DWORD *)(v16 + dword_192680 + 51) = v10;
    v11 = v9;
    v12 = v8 + 40;
  }
  return sub_12A478(v12, v11, v10);
}
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;


//----- (000F28B4) --------------------------------------------------------
int __fastcall sub_F28B4(int a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int16_t v5; // cx
  int result; // eax
  int v7; // ecx
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int64_t v11; // rax
  int v12; // esi
  int v13; // ecx
  int v14; // eax
  int v15; // eax
  int16_t v16; // dx
  char *v17; // ebx
  _BYTE v18[20]; // [esp+0h] [ebp-4Ch] BYREF
  _BYTE v19[8]; // [esp+14h] [ebp-38h] BYREF
  int v20; // [esp+1Ch] [ebp-30h]
  int v21; // [esp+20h] [ebp-2Ch]
  int v22; // [esp+24h] [ebp-28h]
  int v23; // [esp+28h] [ebp-24h]
  int v24; // [esp+2Ch] [ebp-20h]
  int v25; // [esp+30h] [ebp-1Ch]
  int v26; // [esp+34h] [ebp-18h]
  int v27; // [esp+38h] [ebp-14h]
  int v28; // [esp+3Ch] [ebp-10h]
  int v29; // [esp+40h] [ebp-Ch]
  int v30; // [esp+44h] [ebp-8h]
  int v31; // [esp+48h] [ebp-4h]

  HIWORD(v2) = HIWORD(dword_192680);
  LOWORD(a2) = *(_WORD *)(dword_192680 + 243);
  LOWORD(v2) = *(_WORD *)(dword_192680 + 245);
  v27 = a2;
  v26 = v2;
  sub_124D41();
  v3 = sub_127C27((int)aMultigmLbx, 0, dword_193174);
  *(_DWORD *)(dword_192680 + 15) = v3;
  sub_12A478(0, 0, v3);
  v4 = sub_127C27((int)aMultigmLbx, 35, dword_193174);
  *(_DWORD *)(dword_192680 + 47) = v4;
  sub_12A478(v27, v26, v4);
  qmemcpy(&unk_1BB598, &unk_183580, 0x40u);
  byte_199F34 = -106;
  qmemcpy(v19, sub_8E5C5(4u, 146, 152), sizeof(v19));
  sub_120BB5(4, (int)v19);
  sprintf(v18, "COM:%d", dword_1AAEC4 + 1);
  v5 = v26 + 83;
  sub_1212B3(v27 + 119, v26 + 83, (int)v18);
  sprintf(v18, "%ld", dword_1AAEC8);
  sub_1212B3(v27 + 293, v5, (int)v18);
  result = dword_192680;
  if ( *(_WORD *)(dword_192680 + 251) == 1 )
  {
    v7 = v27;
    v8 = v26;
    v9 = sub_127C27((int)aMultigmLbx, 38, dword_193174);
    v7 += 129;
    v8 += 101;
    *(_DWORD *)(dword_192680 + 83) = v9;
    v29 = 0;
    sub_12A478(v7, v8, v9);
    v31 = v7 + 27;
    v20 = v7 + 5;
    v24 = v8 + 15;
    v25 = v8 + 18;
    do
    {
      if ( *(_WORD *)(dword_192680 + 257) == *(_WORD *)(dword_192680 + 2 * (int16_t)v29 + 167) )
      {
        qmemcpy(v19, sub_8E5C5(3u, 146, 154), sizeof(v19));
        sub_120BB5(3, (int)v19);
        v10 = sub_127C27((int)aMultigmLbx, 39, dword_193174);
        *(_DWORD *)(dword_192680 + 87) = v10;
        sub_12A478(v20, v24, v10);
      }
      else
      {
        qmemcpy(v19, sub_8E5C5(3u, 146, 151), sizeof(v19));
        sub_120BB5(3, (int)v19);
      }
      v24 += 15;
      v25 += 15;
      v11 = sprintf(v18, "COM:%d", (int16_t)v29++ + 1);
      result = sub_1212B3(v31, SWORD2(v11), (int)v18);
    }
    while ( (int16_t)v29 < 8 );
  }
  else if ( *(_WORD *)(dword_192680 + 251) == 2 )
  {
    v12 = v27;
    v13 = v26;
    v14 = sub_127C27((int)aMultigmLbx, 38, dword_193174);
    v12 += 295;
    v13 += 100;
    *(_DWORD *)(dword_192680 + 83) = v14;
    v28 = 0;
    sub_12A478(v12, v13, v14);
    v21 = v12 + 68;
    v30 = v12 + 5;
    v22 = v13 + 18;
    v23 = v13 + 15;
    do
    {
      if ( *(_WORD *)(dword_192680 + 257) == *(_WORD *)(dword_192680 + 2 * (int16_t)v28 + 167) )
      {
        qmemcpy(v19, sub_8E5C5(3u, 146, 154), sizeof(v19));
        sub_120BB5(3, (int)v19);
        v15 = sub_127C27((int)aMultigmLbx, 39, dword_193174);
        *(_DWORD *)(dword_192680 + 87) = v15;
        sub_12A478(v30, v23, v15);
      }
      else
      {
        qmemcpy(v19, sub_8E5C5(3u, 146, 151), sizeof(v19));
        sub_120BB5(3, (int)v19);
      }
      v16 = v22;
      v23 += 15;
      v22 += 15;
      v17 = &a1200[6 * (int16_t)v28++];
      result = sub_1210B7(v21, v16, (int)v17);
    }
    while ( (int16_t)v28 < 8 );
  }
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 199F34: using guessed type char byte_199F34;
// 1AAEC4: using guessed type int dword_1AAEC4;
// 1AAEC8: using guessed type int dword_1AAEC8;


//----- (000F2C8B) --------------------------------------------------------
int16_t *sub_F2C8B()
{
  int v0; // eax
  int v1; // ebx
  int v2; // edx
  int16_t v3; // cx
  int16_t v4; // bx
  int16_t *result; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-8h] BYREF

  sub_128C32(0, 0, 639, 479, 0);
  v0 = sub_127C27((int)aMultigmLbx, 0, dword_193174);
  *(_DWORD *)(dword_192680 + 15) = v0;
  sub_12A478(0, 0, v0);
  v1 = dword_193174;
  v2 = *(int16_t *)(dword_192680 + 241);
  ++*(_BYTE *)(dword_192680 + 490);
  v3 = 0;
  for ( *(_DWORD *)(dword_192680 + 47) = sub_127C27((int)aMultigmLbx, v2, v1);
        ;
        sub_12A478(*(_WORD *)(dword_192680 + 243), *(_WORD *)(dword_192680 + 245), *(_DWORD *)(dword_192680 + 47)) )
  {
    v4 = *(uint8_t *)(dword_192680 + 490);
    if ( v3 >= v4 )
      break;
    sub_12B753(*(_DWORD *)(dword_192680 + 47), v3++);
  }
  if ( v4 >= *(int16_t *)(*(_DWORD *)(dword_192680 + 47) + 6) )
    *(_BYTE *)(dword_192680 + 490) = 0;
  result = &word_18FF78;
  if ( &word_18FF78 && (_BYTE)word_18FF78 )
  {
    byte_199F34 = -14;
    qmemcpy(v6, sub_8E5C5(4u, 156, 248), sizeof(v6));
    sub_120BB5(4, (int)v6);
    JUMPOUT(0xF2F44);
  }
  return result;
}
// F2DE0: control flows out of bounds to F2F44
// 18FF78: using guessed type int16_t word_18FF78;
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 199F34: using guessed type char byte_199F34;


//----- (000F2DE5) --------------------------------------------------------
int sub_F2DE5()
{
  int v0; // eax
  int v1; // edx
  int v2; // eax
  int16_t v3; // cx
  int16_t v4; // bx
  int16_t i; // ax
  int16_t v6; // ax
  uint16_t v7; // ax
  char *v8; // eax
  int v10; // [esp-4h] [ebp-5Ch]
  _BYTE v11[80]; // [esp+0h] [ebp-58h] BYREF
  _BYTE v12[8]; // [esp+50h] [ebp-8h] BYREF

  sub_124D41();
  sub_128C32(0, 0, 639, 479, 0);
  v0 = sub_127C27((int)aMultigmLbx, 0, dword_193174);
  *(_DWORD *)(dword_192680 + 15) = v0;
  sub_12A478(0, 0, v0);
  v1 = sub_127C27((int)aMultigmLbx, *(int16_t *)(dword_192680 + 241), dword_193174);
  v2 = dword_192680;
  *(_DWORD *)(dword_192680 + 47) = v1;
  v3 = 0;
  ++*(_BYTE *)(v2 + 490);
  while ( 1 )
  {
    v4 = *(uint8_t *)(dword_192680 + 490);
    if ( v3 >= v4 )
      break;
    sub_12B753(*(_DWORD *)(dword_192680 + 47), v3++);
    sub_12A478(*(_WORD *)(dword_192680 + 243), *(_WORD *)(dword_192680 + 245), *(_DWORD *)(dword_192680 + 47));
  }
  if ( v4 >= *(int16_t *)(*(_DWORD *)(dword_192680 + 47) + 6) )
    *(_BYTE *)(dword_192680 + 490) = 0;
  byte_199F34 = -14;
  qmemcpy(v12, sub_8E5C5(4u, 156, 248), sizeof(v12));
  for ( i = 0; i < word_199998; ++i )
    ;
  v6 = sub_139294(0);
  if ( v6 == 1 )
  {
    v10 = 1;
    v7 = 249;
  }
  else
  {
    v10 = v6;
    v7 = 250;
  }
  v8 = sub_7A990(v7);
  sprintf(v11, v8, v10);
  sub_120BB5(*(uint8_t *)(dword_192680 + 270), (int)v12);
  return sub_1212B3(*(_WORD *)(dword_192680 + 243) + 120, *(_WORD *)(dword_192680 + 245) + 71, (int)v11);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 199998: using guessed type int16_t word_199998;
// 199F34: using guessed type char byte_199F34;


//----- (000F2F4E) --------------------------------------------------------
void sub_F2F4E()
{
  int v0; // eax
  int v1; // ebx
  int v2; // edx
  int v3; // eax
  int16_t v4; // cx
  int16_t v5; // bx
  int16_t i; // ax
  char *v7; // eax
  int v8; // [esp-8h] [ebp-78h]
  int v9; // [esp-4h] [ebp-74h]
  _BYTE v10[100]; // [esp+0h] [ebp-70h] BYREF
  _BYTE v11[8]; // [esp+64h] [ebp-Ch] BYREF
  int v12; // [esp+6Ch] [ebp-4h]

  byte_199F34 = -14;
  qmemcpy(v11, sub_8E5C5(4u, 156, 248), sizeof(v11));
  sub_124D41();
  sub_128C32(0, 0, 639, 479, 0);
  v0 = sub_127C27((int)aMultigmLbx, 0, dword_193174);
  *(_DWORD *)(dword_192680 + 15) = v0;
  sub_12A478(0, 0, v0);
  v1 = dword_193174;
  v2 = *(int16_t *)(dword_192680 + 241);
  ++*(_BYTE *)(dword_192680 + 490);
  v3 = sub_127C27((int)aMultigmLbx, v2, v1);
  v12 = 0;
  v4 = 0;
  for ( *(_DWORD *)(dword_192680 + 47) = v3;
        ;
        sub_12A478(*(_WORD *)(dword_192680 + 243), *(_WORD *)(dword_192680 + 245), *(_DWORD *)(dword_192680 + 47)) )
  {
    v5 = *(uint8_t *)(dword_192680 + 490);
    if ( v4 >= v5 )
      break;
    sub_12B753(*(_DWORD *)(dword_192680 + 47), v4++);
  }
  if ( v5 >= *(int16_t *)(*(_DWORD *)(dword_192680 + 47) + 6) )
    *(_BYTE *)(dword_192680 + 490) = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    if ( byte_1AAF60[i] )
      ++v12;
  }
  v9 = sub_139294(0);
  v8 = (int16_t)v12;
  v7 = sub_7A990(0xFBu);
  sprintf(v10, v7, v8, v9);
  sub_120BB5(*(uint8_t *)(dword_192680 + 270), (int)v11);
  JUMPOUT(0xF2F40);
}
// F30B4: control flows out of bounds to F2F40
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 199998: using guessed type int16_t word_199998;
// 199F34: using guessed type char byte_199F34;


//----- (000F30B9) --------------------------------------------------------
char __fastcall sub_F30B9( int a1, char *a2, _BYTE *a3, _BYTE *a4)
{
  int v4; // esi
  char result; // al
  int16_t v6; // si

  v4 = 3753 * a1;
  result = dword_197F98;
  v6 = *(uint8_t *)(v4 + dword_197F98 + 38);
  *a2 = 0;
  *a3 = 0;
  *a4 = 0;
  if ( v6 == 3 )
  {
    *a2 = 10;
    *a3 = 14;
    *a4 = 23;
  }
  else if ( v6 == 4 )
  {
    *a2 = 59;
    *a3 = 60;
    *a4 = 61;
  }
  else
  {
    result = byte_10010[v6];
    *a2 = result;
    *a3 = result + 2;
    *a4 = byte_10010[v6] + 3;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (000F3119) --------------------------------------------------------
char *__fastcall sub_F3119( int a1, char *a2, char *a3, char *a4)
{
  int16_t v4; // ax
  char *result; // eax
  int16_t v6; // [esp+0h] [ebp-10h]
  int16_t v7; // [esp+Ch] [ebp-4h]

  v4 = 6 * a1;
  v7 = v4 + 112;
  v6 = v4 + 112;
  qmemcpy(a2, sub_8E5C5(*(uint8_t *)(dword_192680 + 270), v4 + 112, v4 + 116), 8u);
  qmemcpy(a3, sub_8E5C5(*(uint8_t *)(dword_192680 + 270), v6, v7 + 2), 8u);
  result = sub_8E5C5(*(uint8_t *)(dword_192680 + 270), v6, v7 + 5);
  qmemcpy(a4, result, 8u);
  return result;
}
// 192680: using guessed type int dword_192680;


//----- (000F31BB) --------------------------------------------------------
int sub_F31BB()
{
  int v0; // eax
  char *v1; // esi
  int result; // eax
  int v3; // [esp+4h] [ebp-10h]
  int16_t v4; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  for ( i = 0; ; ++i )
  {
    result = i;
    if ( (int16_t)i >= word_199998 )
      break;
    v0 = dword_197F98 + 3753 * (int16_t)i;
    v3 = 8 * (int16_t)i;
    v4 = (uint8_t)byte_10010[*(uint8_t *)(v0 + 38)];
    if ( *(_BYTE *)(v0 + 38) == 3 )
    {
      byte_199F34 = 12;
      qmemcpy((void *)(dword_192680 + 280 + v3), sub_8E5C5(*(uint8_t *)(dword_192680 + 270), 10, 16), 8u);
      byte_199F34 = 8;
      qmemcpy((void *)(dword_192680 + 408 + v3), sub_8E5C5(*(uint8_t *)(dword_192680 + 270), 6, 12), 8u);
      byte_199F34 = 12;
      v1 = sub_8E5C5(*(uint8_t *)(dword_192680 + 270), 10, 16);
    }
    else
    {
      byte_199F34 = v4 + 2;
      qmemcpy((void *)(v3 + dword_192680 + 280), sub_8E5C5(*(uint8_t *)(dword_192680 + 270), v4, v4 + 5), 8u);
      byte_199F34 = v4 + 1;
      qmemcpy((void *)(dword_192680 + 408 + v3), sub_8E5C5(*(uint8_t *)(dword_192680 + 270), v4, v4 + 3), 8u);
      byte_199F34 = v4 + 2;
      v1 = sub_8E5C5(*(uint8_t *)(dword_192680 + 270), v4, v4 + 6);
    }
    qmemcpy((void *)(dword_192680 + 344 + v3), v1, 8u);
  }
  return result;
}
// 192680: using guessed type int dword_192680;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199F34: using guessed type char byte_199F34;


//----- (000F33AE) --------------------------------------------------------
char __fastcall sub_F33AE(int a1)
{
  char v2; // cl
  int16_t i; // dx
  uint8_t v4; // al

  v2 = 0;
  for ( i = 0; i < 10; ++i )
  {
    sub_11FCC(i);
    if ( v4 && v4 <= 3u )
    {
      v2 = 1;
      *(_BYTE *)(i + a1) = v4;
    }
    else
    {
      *(_BYTE *)(a1 + i) = 0;
    }
  }
  return v2;
}
// F33CA: variable 'v4' is possibly undefined


//----- (000F33EE) --------------------------------------------------------
void sub_F33EE()
{
  int v0; // edi
  int16_t i; // si
  int v2; // eax
  int v3; // eax
  int16_t v4; // bx
  int16_t v5; // [esp+Ch] [ebp-8h]

  v5 = 64;
  v0 = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    v2 = dword_197F98 + 3753 * i;
    if ( *(_BYTE *)(v2 + 40) == 100 )
    {
      if ( *(_BYTE *)(v2 + 36) )
      {
        v3 = dword_192680;
        *(_WORD *)(dword_192680 + 2 * i + 187) = -1000;
        *(_WORD *)(v3 + 2 * i + 167) = -1000;
      }
      else
      {
        v4 = v5 + *(_WORD *)(dword_192680 + 245);
        if ( *(_BYTE *)(i + dword_192680 + 272) == 1 || *(_BYTE *)(i + dword_192680 + 272) == 2 )
        {
          v5 += 36;
          *(_WORD *)(dword_192680 + 2 * i + 187) = sub_11438B(
                                                     *(_WORD *)(dword_192680 + 243) + 106,
                                                     v4,
                                                     *(_WORD *)(dword_192680 + 243) + 435,
                                                     v4 + 29,
                                                     &unk_17A061,
                                                     41);
          sub_EFABA(i, v0++);
        }
      }
    }
  }
}
// 192680: using guessed type int dword_192680;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000F34EA) --------------------------------------------------------
int sub_F34EA()
{
  int16_t v0; // si
  int16_t v1; // cx
  int v2; // eax
  int v3; // eax
  int16_t v4; // cx
  int16_t v5; // di
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  char *v9; // ebx
  int16_t v10; // dx
  int16_t v11; // ax
  int v12; // esi
  int16_t v13; // dx
  int16_t v14; // ax
  char *v15; // esi
  int16_t v16; // dx
  char v17; // al
  int v18; // eax
  int v19; // eax
  int v20; // eax
  char *v21; // edx
  int result; // eax
  char v23[8]; // [esp+0h] [ebp-30h] BYREF
  char v24[8]; // [esp+8h] [ebp-28h] BYREF
  char v25[8]; // [esp+10h] [ebp-20h] BYREF
  int16_t v26; // [esp+18h] [ebp-18h]
  int16_t v27; // [esp+1Ch] [ebp-14h]
  int v28; // [esp+20h] [ebp-10h]
  int v29; // [esp+24h] [ebp-Ch]
  char v30; // [esp+28h] [ebp-8h]
  char v31; // [esp+2Ch] [ebp-4h]

  v0 = *(_WORD *)(dword_192680 + 243);
  v1 = *(_WORD *)(dword_192680 + 245);
  v26 = *(uint8_t *)(dword_192680 + 270);
  v2 = sub_127C27((int)aMultigmLbx, 0, dword_193174);
  *(_DWORD *)(dword_192680 + 15) = v2;
  sub_12A478(0, 0, v2);
  v3 = sub_127C27((int)aMultigmLbx, 19, dword_193174);
  *(_DWORD *)(dword_192680 + 35) = v3;
  sub_12A478(v0, v1, v3);
  v4 = *(_WORD *)(*(_DWORD *)(dword_192680 + 35) + 2) + v1;
  v5 = 0;
  *(_DWORD *)(dword_192680 + 39) = sub_127C27((int)aMultigmLbx, 20, dword_193174);
  while ( *(int16_t *)(dword_192680 + 481) - 1 > v5 )
  {
    sub_12A478(v0, v4, *(_DWORD *)(dword_192680 + 39));
    ++v5;
    v4 += *(_WORD *)(*(_DWORD *)(dword_192680 + 39) + 2);
  }
  v6 = sub_127C27((int)aMultigmLbx, 21, dword_193174);
  *(_DWORD *)(dword_192680 + 43) = v6;
  sub_12A478(v0, v4, v6);
  v28 = 0;
  v29 = 0;
  *(_BYTE *)(dword_192680 + 270) = 4;
  do
  {
    v7 = (int16_t)v29;
    v8 = (int)v25;
    v9 = v23;
    sub_F3119(*(uint8_t *)(3753 * (int16_t)v29 + dword_197F98 + 38), v24, v23, v25);
    if ( *(_BYTE *)(v7 + dword_192680 + 272) == 1 )
    {
      sub_120BB5(4, (int)v23);
      v10 = v28;
      sub_120E8C(1);
      v11 = v7;
    }
    else
    {
      if ( *(_BYTE *)(v7 + dword_192680 + 272) != 2 )
        goto LABEL_24;
      v9 = 0;
      sub_F27B7(v7, v28, 0);
      v12 = dword_192680 + 2 * v7;
      v13 = *(_WORD *)(dword_192680 + 257);
      if ( v13 == *(_WORD *)(v12 + 187) || v13 == *(_WORD *)(v12 + 167) )
      {
        v14 = 6 * *(uint8_t *)(dword_197F98 + 3753 * (int16_t)v29 + 38);
        v27 = v14 + 112;
        v15 = sub_8E5C5(4u, v14 + 112, v14 + 115);
        v16 = 1;
        v31 = v27 + 5;
        v17 = v27 + 1;
        qmemcpy((void *)(dword_192680 + 472), v15, 8u);
        v30 = v17;
        do
        {
          v18 = dword_192680 + v16;
          *(_BYTE *)(v18 + 472) += *(_BYTE *)(dword_192680 + 488);
          if ( *(uint8_t *)(v18 + 472) < v27 + 1 )
            *(_BYTE *)(v18 + 472) = v30;
          v19 = dword_192680 + v16;
          v8 = *(uint8_t *)(v19 + 472);
          v9 = (char *)(v27 + 5);
          if ( v8 > (int)v9 )
          {
            LOBYTE(v9) = v31;
            *(_BYTE *)(v19 + 472) = v31;
          }
          ++v16;
        }
        while ( v16 < 8 );
        v20 = dword_192680;
        *(_BYTE *)(dword_192680 + 488) += *(_BYTE *)(dword_192680 + 489);
        if ( *(char *)(v20 + 488) < 2 )
        {
          if ( *(char *)(v20 + 488) <= -2 )
          {
            *(_BYTE *)(v20 + 488) = -2;
            *(_BYTE *)(v20 + 489) = 1;
          }
        }
        else
        {
          *(_BYTE *)(v20 + 488) = 2;
          *(_BYTE *)(v20 + 489) = -1;
        }
        v21 = (char *)(dword_192680 + 472);
      }
      else
      {
        v21 = v24;
      }
      sub_120BB5(4, (int)v21);
      v10 = v28;
      sub_120E8C(1);
      v11 = v29;
    }
    ++v28;
    sub_F3A27(v11, v10, (int)v9, v8);
LABEL_24:
    ++v29;
  }
  while ( (int16_t)v29 < 8 );
  result = dword_192680;
  *(_BYTE *)(dword_192680 + 270) = v26;
  return result;
}
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;


//----- (000F37FC) --------------------------------------------------------
int sub_F37FC()
{
  int result; // eax
  int16_t i; // dx
  int v2; // ebx
  uint8_t v3; // cl
  int v4; // ebx
  int v5; // ecx
  _DWORD v6[2]; // [esp+0h] [ebp-10h]
  int16_t v7; // [esp+8h] [ebp-8h]
  uint8_t v8; // [esp+Ch] [ebp-4h]

  result = 0;
  v6[0] = 33619968;
  v6[1] = 84214787;
  while ( (int16_t)result < word_199998 )
  {
    v7 = 6 * *(uint8_t *)(dword_197F98 + 3753 * (int16_t)result + 38) + 112;
    for ( i = 0; i < 8; ++i )
    {
      if ( i )
      {
        v8 = *((_BYTE *)v6 + i) + v7;
        v3 = v8;
        *(_BYTE *)(dword_192680 + 8 * (int16_t)result + i + 280) = v8;
        v4 = v7 + 1;
        v5 = v3 - 3;
        if ( v4 < v5 )
          LOBYTE(v4) = v5;
        *(_BYTE *)(i + dword_192680 + 8 * (int16_t)result + 408) = v4;
      }
      else
      {
        v8 = LOBYTE(v6[0]) + v7;
        v2 = dword_192680 + 8 * (int16_t)result;
        *(_BYTE *)(v2 + 280) = LOBYTE(v6[0]) + v7;
        *(_BYTE *)(v2 + 408) = v7;
      }
    }
    ++result;
  }
  return result;
}
// EFA54: using guessed type int[14];
// 192680: using guessed type int dword_192680;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000F38DC) --------------------------------------------------------
int sub_F38DC()
{
  int v0; // ebx
  int16_t i; // dx
  int v2; // eax

  v0 = 0;
  for ( i = 0; i < 8; ++i )
  {
    v2 = dword_192680 + i;
    if ( *(_BYTE *)(v2 + 272) == 2 || *(_BYTE *)(v2 + 272) == 1 )
      ++v0;
  }
  return v0;
}
// 192680: using guessed type int dword_192680;


//----- (000F390E) --------------------------------------------------------
int __fastcall sub_F390E(int a1, int a2)
{
  int16_t *v2; // eax
  int v3; // ebx
  int16_t v4; // si
  int v5; // eax
  int16_t v6; // cx
  int v7; // eax
  int16_t v8; // dx
  int16_t v9; // ax
  int v10; // eax

  sub_1112EC(dword_192ED4, a2);
  dword_192680 = (int)&unk_1AACB4;
  memset(&unk_1AACB4, 0, 491);
  *(_DWORD *)(dword_192680 + 15) = sub_127C27((int)aMultigmLbx, 0, dword_193174);
  v2 = (int16_t *)sub_127C27((int)aMultigmLbx, 19, dword_193174);
  v3 = dword_192680;
  *(_DWORD *)(dword_192680 + 35) = v2;
  v4 = v2[1];
  *(_WORD *)(v3 + 243) = (640 - *v2) / 2;
  v5 = sub_127C27((int)aMultigmLbx, 20, dword_193174);
  *(_DWORD *)(dword_192680 + 39) = v5;
  v6 = *(_WORD *)(v5 + 2);
  v7 = sub_127C27((int)aMultigmLbx, 21, dword_193174);
  *(_DWORD *)(dword_192680 + 43) = v7;
  v8 = *(_WORD *)(v7 + 2);
  sub_F3D67();
  v9 = sub_F38DC();
  *(_WORD *)(dword_192680 + 481) = v9;
  v10 = (480 - (int16_t)(v4 + v6 * v9 + v8)) / 2;
  if ( v10 <= 0 )
    LOWORD(v10) = 0;
  *(_WORD *)(dword_192680 + 245) = v10;
  return sub_F37FC();
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192680: using guessed type int dword_192680;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;


//----- (000F3A27) --------------------------------------------------------
int __fastcall sub_F3A27( int a1, int a2, int a3, int a4)
{
  int16_t v5; // cx
  int16_t *v6; // eax
  int16_t v7; // cx
  _BYTE v9[200]; // [esp+0h] [ebp-194h] BYREF
  char v10[200]; // [esp+C8h] [ebp-CCh] BYREF
  int v11; // [esp+190h] [ebp-4h]

  LOWORD(a4) = *(_WORD *)(dword_192680 + 243);
  v11 = a4 + 106;
  v5 = *(_WORD *)(dword_192680 + 245);
  strcpy(v10, sub_7A990(0xFCu));
  sub_9ED88(a1);
  v6 = sub_8E6DE();
  v7 = 36 * a2 + 64 + v5 + 8;
  sprintf(v9, v10, 3753 * a1 + dword_197F98 + 1, 3753 * a1 + dword_197F98 + 21, v6);
  return sub_1212B3(v11 + 10, v7, (int)v9);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192680: using guessed type int dword_192680;
// 197F98: using guessed type int dword_197F98;


//----- (000F3AC8) --------------------------------------------------------
char sub_F3AC8()
{
  return sub_128C32(0, 0, 639, 479, 0);
}


//----- (000F3AE4) --------------------------------------------------------
void __usercall sub_F3AE4(int16_t *a1)
{
  int v1; // ebx
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int16_t v5; // si
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int16_t v11; // [esp+0h] [ebp-10h]
  int v12; // [esp+4h] [ebp-Ch]
  _BYTE v13[4]; // [esp+8h] [ebp-8h] BYREF
  char v14; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v13[0] = 0;
  sub_8F1C4((void (__fastcall *)(int, int))sub_F3AC8, v13, 0);
  v2 = 2;
  sub_1191CA((int)sub_F34EA, 2);
  sub_11C2F0();
  LOWORD(v3) = sub_117174(3);
  sub_F390E(v3, 2);
  sub_11946A(240);
  v4 = dword_192680;
  v14 = 0;
  v5 = -1;
  *(_BYTE *)(dword_192680 + 488) = 0;
  v6 = 0;
  *(_BYTE *)(v4 + 489) = 1;
  v12 = -1;
  if ( *(_WORD *)(v4 + 483) == 1 )
  {
    byte_199F3A = 0;
    v6 = 1;
    v5 = *(_WORD *)(v4 + 485);
  }
  else if ( *(_BYTE *)(v4 + 487) )
  {
    v14 = 1;
    v6 = 1;
  }
  else
  {
    sub_F33EE();
    v1 = 11;
    v2 = (int)v13;
    sub_8F1C4((void (__fastcall *)(int, int))sub_F34EA, v13, 11);
  }
  while ( !(_WORD)v6 )
  {
    v11 = sub_1171AB(v4, v2, v1, v6);
    v2 = (int)sub_114177();
    v4 = dword_192680;
    v1 = 0;
    *(_WORD *)(dword_192680 + 257) = v2;
    while ( (int16_t)v1 < word_199998 && !(_WORD)v6 )
    {
      if ( *(_BYTE *)(dword_192680 + (int16_t)v1 + 272) == 2 )
      {
        v7 = dword_192680 + 2 * (int16_t)v1;
        if ( v11 == *(_WORD *)(v7 + 187) || v11 == *(_WORD *)(v7 + 167) )
        {
          v6 = 1;
          byte_19C1A2 = 1;
          v5 = v1;
        }
      }
      v2 = (int16_t)v1;
      v4 = dword_192680;
      a1 = (int16_t *)(int16_t)v1;
      if ( *(_BYTE *)((int16_t)v1 + dword_192680 + 272) == 2 )
      {
        LOWORD(a1) = *(_WORD *)(dword_192680 + 257);
        v2 = dword_192680 + 2 * (int16_t)v1;
        if ( (_WORD)a1 == *(_WORD *)(v2 + 187) || (_WORD)a1 == *(_WORD *)(v2 + 167) )
        {
          v8 = dword_192680;
          v2 = v12;
          if ( (_WORD)v12 != *(_WORD *)(dword_192680 + 257) )
          {
            *(_BYTE *)(dword_192680 + 488) = 0;
            *(_BYTE *)(v8 + 489) = 1;
          }
          HIWORD(v4) = HIWORD(dword_192680);
          LOWORD(v4) = *(_WORD *)(dword_192680 + 257);
          v12 = v4;
        }
      }
      ++v1;
    }
    if ( !(_WORD)v6 )
    {
      sub_124D41();
      v9 = sub_F34EA();
      v4 = sub_1077D(v9, v2, v1, a1);
    }
  }
  sub_11C2F0();
  sub_117174(3);
  sub_119281();
  sub_1113CC(dword_192ED4, v2);
  dword_192680 = 0;
  if ( v14 )
  {
    word_199A08 = 12;
    word_199A10 = 17;
  }
  else
  {
    sub_88E5A();
    if ( v5 != -1 )
      word_19999C = v5;
    word_199A08 = 39;
    word_199A10 = 17;
    sub_88E5A();
    v10 = 113 * *(uint8_t *)(17 * *(int16_t *)(dword_197F98 + 3753 * word_19999C + 41) + dword_1930D4 + 2)
        + dword_19306C;
    sub_8238B(*(_WORD *)(v10 + 15), *(_WORD *)(v10 + 17));
  }
  if ( sub_FE86B(word_19999C, a1) )
  {
    sub_8A4C4();
    dword_1975B8 = dword_192FD8;
    sub_8A6C2();
  }
}
// F3B1E: variable 'v3' is possibly undefined
// F3BA1: variable 'v4' is possibly undefined
// 192680: using guessed type int dword_192680;
// 192ED4: using guessed type int dword_192ED4;
// 192FD8: using guessed type int dword_192FD8;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1975B8: using guessed type int dword_1975B8;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199F3A: using guessed type char byte_199F3A;
// 19C1A2: using guessed type char byte_19C1A2;


//----- (000F3D67) --------------------------------------------------------
int sub_F3D67()
{
  int16_t v0; // si
  int16_t i; // dx
  int v2; // eax
  int v3; // ebx
  int result; // eax
  char v5; // [esp+0h] [ebp-4h]

  v0 = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( i < word_199998 )
    {
      v5 = sub_F3E09(i);
      v2 = dword_192680;
      *(_BYTE *)(i + dword_192680 + 272) = v5;
      v3 = dword_197F98 + 3753 * i;
      if ( *(_BYTE *)(v3 + 40) == 100 && !*(_BYTE *)(v3 + 36) )
      {
        *(_WORD *)(v2 + 485) = i;
        ++*(_WORD *)(v2 + 483);
      }
      if ( *(_BYTE *)(i + dword_192680 + 272) == 1 && !*(_BYTE *)(dword_197F98 + 3753 * i + 36) )
        ++v0;
    }
  }
  result = dword_192680;
  *(_BYTE *)(dword_192680 + 487) = v0 == *(_WORD *)(dword_192680 + 483);
  return result;
}
// 192680: using guessed type int dword_192680;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000F3E09) --------------------------------------------------------
int __fastcall sub_F3E09( int a1)
{
  _BYTE *v1; // eax
  int v2; // edx

  v1 = (_BYTE *)(dword_197F98 + 3753 * a1);
  v2 = 0;
  if ( v1[40] == 100 && !v1[36] )
  {
    if ( v1[45] )
      return 1;
    return 2;
  }
  return v2;
}
// 197F98: using guessed type int dword_197F98;


//----- (000F3E42) --------------------------------------------------------
int __fastcall sub_F3E42(int a1)
{
  char v1; // cl
  int v2; // edi
  int v3; // ebx
  int16_t *v4; // eax
  int v5; // ebx
  int v6; // eax
  int16_t v7; // si
  int v8; // eax
  int16_t v9; // dx
  int v10; // eax
  int v11; // eax
  int16_t v12; // dx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int16_t v17; // [esp+0h] [ebp-8h]
  _BYTE v18[4]; // [esp+4h] [ebp-4h] BYREF

  v1 = a1;
  sub_FE8BE(a1);
  byte_1AAC54 = 0;
  dword_192680 = (int)&unk_1AACB4;
  memset(&unk_1AACB4, 0, 491);
  v2 = dword_192680;
  v3 = dword_193174;
  *(_DWORD *)dword_192680 = *(_DWORD *)aEvanAxelrad;
  strcpy((char *)(v2 + 4), " Axelrad");
  v4 = (int16_t *)sub_127C27((int)aMultigmLbx, 42, v3);
  v5 = dword_192680;
  *(_DWORD *)(dword_192680 + 35) = v4;
  v17 = v4[1];
  *(_WORD *)(v5 + 243) = (640 - *v4) / 2;
  v6 = sub_127C27((int)aMultigmLbx, 43, dword_193174);
  *(_DWORD *)(dword_192680 + 39) = v6;
  v7 = *(_WORD *)(v6 + 2);
  v8 = sub_127C27((int)aMultigmLbx, 40, dword_193174);
  *(_DWORD *)(dword_192680 + 31) = v8;
  LOWORD(v2) = *(_WORD *)(v8 + 2);
  *(_DWORD *)(dword_192680 + 147) = sub_127C27((int)aMultigmLbx, 45, dword_193174);
  v9 = sub_7A54F();
  v10 = dword_192680;
  *(_BYTE *)(dword_192680 + 480) = 1;
  *(_WORD *)(v10 + 481) = v9;
  sub_F31BB();
  *(_WORD *)(dword_192680 + 191) = v7 + v17;
  v11 = (480 - (int16_t)(v2 + v7 + v17)) / 2;
  if ( v11 <= 0 )
    LOWORD(v11) = 0;
  v12 = v11;
  v13 = dword_192680;
  *(_BYTE *)(dword_192680 + 270) = 2;
  *(_WORD *)(v13 + 245) = v12;
  v14 = 1;
  sub_1191CA((int)sub_F1075, 1);
  word_19994C = 1;
  LOWORD(v15) = sub_11C2F0();
  if ( v1 )
  {
    v14 = (int)v18;
    sub_8F1C4(sub_F1075, v18, 0);
  }
  return sub_EFCEA(v15, v14);
}
// F3FBC: variable 'v15' is possibly undefined
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 19994C: using guessed type int16_t word_19994C;
// 1AAC54: using guessed type char byte_1AAC54;


//----- (000F3FC6) --------------------------------------------------------
int __usercall sub_F3FC6(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  int result; // eax

  sub_FE8BE(a1, a2, a3, a4);
  dword_192680 = (int)&unk_1AACB4;
  memset(&unk_1AACB4, 0, 491);
  v4 = dword_192680;
  v5 = dword_192680;
  v6 = dword_193174;
  *(_DWORD *)dword_192680 = *(_DWORD *)aEvanAxelrad;
  strcpy((char *)(v5 + 4), " Axelrad");
  *(_BYTE *)(v4 + 480) = 1;
  *(_DWORD *)(dword_192680 + 15) = sub_127C27((int)aMultigmLbx, 0, v6);
  *(_DWORD *)(dword_192680 + 35) = sub_127C27((int)aMultigmLbx, 27, dword_193174);
  *(_DWORD *)(dword_192680 + 39) = sub_127C27((int)aMultigmLbx, 28, dword_193174);
  *(_DWORD *)(dword_192680 + 43) = sub_127C27((int)aMultigmLbx, 29, dword_193174);
  *(_DWORD *)(dword_192680 + 143) = sub_126B42((int)aMultigmLbx, 16, dword_192ED4);
  *(_DWORD *)(dword_192680 + 115) = sub_126B42((int)aMultigmLbx, 257, dword_192ED4);
  LOWORD(v6) = sub_7A54F();
  result = dword_192680;
  *(_WORD *)(dword_192680 + 481) = v6;
  return result;
}
// F3FC6: could not find valid save-restore pair for edi
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192680: using guessed type int dword_192680;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;


//----- (000F40D3) --------------------------------------------------------
int __usercall sub_F40D3(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // edi
  int v5; // ebx
  _DWORD *v6; // eax
  int v7; // ebx
  int v8; // eax
  int result; // eax

  sub_FE8BE(a1, a2, a3, a4);
  dword_192680 = (int)&unk_1AACB4;
  memset(&unk_1AACB4, 0, 491);
  v4 = dword_192680;
  v5 = dword_193174;
  *(_DWORD *)dword_192680 = *(_DWORD *)aEvanAxelrad;
  strcpy((char *)(v4 + 4), " Axelrad");
  *(_DWORD *)(dword_192680 + 15) = sub_127C27((int)aMultigmLbx, 0, v5);
  *(_DWORD *)(dword_192680 + 27) = sub_127C27((int)aMultigmLbx, 41, dword_193174);
  v6 = sub_126AFD((int)aMultigmLbx, 257, dword_192ED4);
  v7 = dword_192680;
  *(_DWORD *)(dword_192680 + 115) = v6;
  *(_WORD *)(v7 + 243) = (640 - **(int16_t **)(v7 + 27)) / 2;
  v8 = (480 - *(int16_t *)(*(_DWORD *)(v7 + 27) + 2) - 81) / 2;
  *(_BYTE *)(v7 + 488) = 0;
  *(_BYTE *)(v7 + 489) = 1;
  result = v8 + 37;
  *(_WORD *)(v7 + 245) = result;
  return result;
}
// F40D3: could not find valid save-restore pair for edi
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192680: using guessed type int dword_192680;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;


//----- (000F41AD) --------------------------------------------------------
void __usercall sub_F41AD(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // edi
  int v5; // eax
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // ebx

  sub_FE8BE(a1, a2, a3, a4);
  dword_192680 = (int)&unk_1AACB4;
  memset(&unk_1AACB4, 0, 491);
  v4 = dword_192680;
  v5 = dword_192EE8;
  *(_DWORD *)dword_192680 = *(_DWORD *)aEvanAxelrad;
  strcpy((char *)(v4 + 4), " Axelrad");
  dword_19268C = (int)sub_110CEE(v5, 1000);
  dword_192688 = (int)sub_110D3C(dword_192EE8, 1000);
  *(_DWORD *)(dword_192680 + 15) = sub_127C27((int)aMultigmLbx, 0, dword_193174);
  if ( (uint8_t)byte_199F3A < 2u )
  {
    if ( byte_199F3A != 1 )
      goto LABEL_11;
    v6 = 255;
  }
  else if ( (uint8_t)byte_199F3A <= 2u )
  {
    v6 = 18;
  }
  else
  {
    if ( byte_199F3A != 3 )
      goto LABEL_11;
    v6 = 254;
  }
  *(_DWORD *)(dword_192680 + 27) = sub_127C27((int)aMultigmLbx, v6, dword_193174);
LABEL_11:
  v7 = sub_126AFD((int)aMultigmLbx, 257, dword_192ED4);
  v8 = dword_192680;
  *(_DWORD *)(dword_192680 + 115) = v7;
  *(_WORD *)(v8 + 243) = (640 - **(int16_t **)(v8 + 27)) / 2;
  *(_BYTE *)(v8 + 489) = 1;
  *(_BYTE *)(v8 + 488) = 0;
  JUMPOUT(0xF419E);
}
// F42C5: control flows out of bounds to F419E
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192680: using guessed type int dword_192680;
// 192688: using guessed type int dword_192688;
// 19268C: using guessed type int dword_19268C;
// 192ED4: using guessed type int dword_192ED4;
// 192EE8: using guessed type int dword_192EE8;
// 193174: using guessed type int dword_193174;
// 199F3A: using guessed type char byte_199F3A;


//----- (000F42CA) --------------------------------------------------------
void __usercall sub_F42CA(int a1, int a2, int a3, int16_t *a4)
{
  char *v4; // edi
  int v5; // ebx
  int16_t *v6; // eax
  int v7; // ebx

  sub_FE8BE(a1, a2, a3, a4);
  dword_192680 = (int)&unk_1AACB4;
  memset(&unk_1AACB4, 0, 491);
  v4 = (char *)dword_192680;
  v5 = dword_193174;
  *(_BYTE *)(dword_192680 + 480) = 1;
  strcpy(v4, "Evan Axelrad");
  *(_DWORD *)(dword_192680 + 15) = sub_127C27((int)aMultigmLbx, 0, v5);
  v6 = (int16_t *)sub_127C27((int)aMultigmLbx, 1, dword_193174);
  v7 = dword_192680;
  *(_DWORD *)(dword_192680 + 19) = v6;
  *(_WORD *)(v7 + 243) = (640 - *v6) / 2;
  *(_WORD *)(v7 + 245) = (480 - *(int16_t *)(*(_DWORD *)(v7 + 19) + 2)) / 2;
  *(_DWORD *)(dword_192680 + 95) = sub_126AFD((int)aMultigmLbx, 2, dword_192ED4);
  *(_DWORD *)(dword_192680 + 99) = sub_126B42((int)aMultigmLbx, 3, dword_192ED4);
  *(_DWORD *)(dword_192680 + 103) = sub_126B42((int)aMultigmLbx, 4, dword_192ED4);
  *(_DWORD *)(dword_192680 + 107) = sub_126B42((int)aMultigmLbx, 5, dword_192ED4);
  *(_DWORD *)(dword_192680 + 115) = sub_126B42((int)aMultigmLbx, 6, dword_192ED4);
  *(_DWORD *)(dword_192680 + 123) = sub_126B42((int)aMultigmLbx, 7, dword_192ED4);
  *(_DWORD *)(dword_192680 + 127) = sub_126B42((int)aMultigmLbx, 8, dword_192ED4);
  *(_DWORD *)(dword_192680 + 131) = sub_126B42((int)aMultigmLbx, 9, dword_192ED4);
  *(_DWORD *)(dword_192680 + 135) = sub_126B42((int)aMultigmLbx, 10, dword_192ED4);
  *(_DWORD *)(dword_192680 + 139) = sub_126B42((int)aMultigmLbx, 256, dword_192ED4);
  sub_F45DB();
}
// F42CA: could not find valid save-restore pair for edi
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192680: using guessed type int dword_192680;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;


//----- (000F44BB) --------------------------------------------------------
void sub_F44BB()
{
  int v0; // edi
  int v1; // ebx
  _DWORD *v2; // eax
  int v3; // ebx

  dword_192680 = (int)&unk_1AACB4;
  memset(&unk_1AACB4, 0, 491);
  v0 = dword_192680;
  v1 = dword_193174;
  *(_DWORD *)dword_192680 = *(_DWORD *)aEvanAxelrad;
  strcpy((char *)(v0 + 4), " Axelrad");
  *(_DWORD *)(dword_192680 + 15) = sub_127C27((int)aMultigmLbx, 0, v1);
  *(_DWORD *)(dword_192680 + 47) = sub_127C27((int)aMultigmLbx, 32, dword_193174);
  *(_DWORD *)(dword_192680 + 83) = sub_127C27((int)aMultigmLbx, 38, dword_193174);
  *(_DWORD *)(dword_192680 + 87) = sub_127C27((int)aMultigmLbx, 39, dword_193174);
  *(_DWORD *)(dword_192680 + 115) = sub_126B42((int)aMultigmLbx, 33, dword_192ED4);
  v2 = sub_126B42((int)aMultigmLbx, 34, dword_192ED4);
  v3 = dword_192680;
  *(_DWORD *)(dword_192680 + 111) = v2;
  *(_WORD *)(v3 + 243) = (640 - **(int16_t **)(v3 + 47)) / 2;
  *(_BYTE *)(v3 + 270) = 1;
  JUMPOUT(0xF41A1);
}
// F45D6: control flows out of bounds to F41A1
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192680: using guessed type int dword_192680;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;


//----- (000F45DB) --------------------------------------------------------
void sub_F45DB()
{
  qmemcpy(&unk_1AAED5, &dword_199C0D, 0x83u);
  qmemcpy(&dword_1AAEC4, &dword_199BFC, 0x11u);
  if ( (unsigned int)dword_1AAEC4 >= 8 )
    dword_1AAEC4 = 1;
  if ( dword_1AAEC8 != 1200
    && dword_1AAEC8 != 4800
    && dword_1AAEC8 != 9600
    && dword_1AAEC8 != 14400
    && dword_1AAEC8 != 19200
    && dword_1AAEC8 != 28800
    && dword_1AAEC8 != 38400 )
  {
    dword_1AAEC8 = 14400;
  }
  if ( byte_1AAECC != 69 && byte_1AAECC != 79 )
    byte_1AAECC = 69;
  if ( (unsigned int)dword_1AAEC4 >= 8 )
    dword_1AAEC4 = 0;
  if ( dword_1AAEC8 >= 1200 )
  {
    if ( dword_1AAEC8 > 38400 )
      dword_1AAEC8 = 38400;
  }
  else
  {
    dword_1AAEC8 = 1200;
  }
}
// 199BFC: using guessed type int dword_199BFC;
// 199C0D: using guessed type int dword_199C0D;
// 1AAEC4: using guessed type int dword_1AAEC4;
// 1AAEC8: using guessed type int dword_1AAEC8;
// 1AAECC: using guessed type char byte_1AAECC;


//----- (000F46E7) --------------------------------------------------------
int sub_F46E7()
{
  int result; // eax

  dword_199C00 = 19200;
  byte_199C04 = 69;
  dword_199C05 = 7;
  result = dword_17A0BB;
  dword_199C09 = 0;
  dword_199C0D = dword_17A0BB;
  strcpy(byte_199C2B, "AT &K0 M1 &D2");
  strcpy(byte_199C49, "AT H0 S0=0");
  strcpy(byte_199C67, "5551212");
  byte_199C8F = 1;
  dword_199BFC = 0;
  return result;
}
// 17A0BB: using guessed type int dword_17A0BB;
// 199BFC: using guessed type int dword_199BFC;
// 199C00: using guessed type int dword_199C00;
// 199C04: using guessed type char byte_199C04;
// 199C05: using guessed type int dword_199C05;
// 199C09: using guessed type int dword_199C09;
// 199C0D: using guessed type int dword_199C0D;
// 199C8F: using guessed type char byte_199C8F;


//----- (000F4760) --------------------------------------------------------
void __usercall sub_F4760(int a1, int16_t *a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // ebx
  int64_t v6; // rax
  int16_t *v7; // edi
  int v8; // eax
  int i; // ecx
  _BYTE v10[120]; // [esp+0h] [ebp-2Ah] BYREF
  _BYTE v11[40]; // [esp+78h] [ebp+4Eh] BYREF
  int v12; // [esp+A0h] [ebp+76h]
  int v13; // [esp+A4h] [ebp+7Ah] BYREF
  int v14; // [esp+A8h] [ebp+7Eh]

  v2 = 0;
  if ( byte_199F3A == 2 )
  {
    sub_F5777(byte_1AB082);
    strcpy((char *)byte_1AB082, &byte_199BF3);
    a2 = byte_1AB082;
    if ( !LOBYTE(byte_1AB082[0]) )
    {
      a1 = 25;
      strcpy((char *)byte_1AB082, "MooII ");
      a2 = (int16_t *)&unk_1AB089;
      byte_1AB087 = j___clock(v3, 0, 25) % 0x19uLL + 97;
    }
  }
  sub_107AF(&v13);
  sub_11C2F0();
  LOWORD(v4) = sub_11946A(240);
  sub_F41AD(v4, 1, a1, a2);
  sub_1191CA((int)sub_F1CE6, 1);
  *(_BYTE *)(dword_192680 + 270) = 2;
  sub_11C83();
  sub_7E7FF((int)v11, dword_192688, a1, 0);
  sub_7E752(dword_19268C);
  if ( sub_EFE7A() )
  {
    v5 = 11;
    HIDWORD(v6) = dword_192680 + 480;
    sub_8F1C4((void (__fastcall *)(int, int))sub_F1CE6, (_BYTE *)(dword_192680 + 480), 11);
    while ( 1 )
    {
      sub_12C2A0();
      v7 = (int16_t *)sub_1171AB(v6, SHIDWORD(v6), v5, v2);
      *(_WORD *)(dword_192680 + 257) = (uint16_t)sub_114177();
      HIDWORD(v6) = 0;
      do
      {
        if ( (int16_t)v7 > 0 )
        {
          LODWORD(v6) = SWORD2(v6);
          v12 = 2 * SWORD2(v6);
          v5 = dword_192680;
          if ( (_WORD)v7 == *(_WORD *)(v12 + dword_192680 + 167) )
          {
            if ( *(_BYTE *)(dword_192680 + SWORD2(v6) + 203) )
            {
              v5 = (uint8_t)byte_199F3A;
              if ( sub_10E2F(v6, SHIDWORD(v6), (uint8_t)byte_199F3A, v2) )
              {
                byte_199F3A = v5;
                v8 = 0;
                for ( i = 0; ; *(_WORD *)(i + dword_197F98 - 3710) = -1 )
                {
                  v5 = word_199998;
                  if ( v8 >= word_199998 )
                    break;
                  i += 3753;
                  ++v8;
                }
                v2 = 1;
                v14 = HIDWORD(v6);
              }
              else
              {
                v14 = -1;
                v2 = 1;
              }
            }
            else
            {
              LODWORD(v6) = sub_7A990(0xFDu);
              v6 = sprintf(v10, (char *)v6, SWORD2(v6));
              v14 = -1;
              sub_77433(v10);
            }
          }
        }
        ++HIDWORD(v6);
      }
      while ( SWORD2(v6) < 10 );
      if ( (_WORD)v7 == *(_WORD *)(dword_192680 + 223) )
      {
        v14 = -1;
        word_199A08 = 15;
        v2 = 1;
      }
      if ( (_WORD)v2 )
        break;
      sub_124D41();
      LODWORD(v6) = sub_F1CE6();
      sub_1077D(v6, SHIDWORD(v6), v5, v7);
    }
    sub_107BA(&v13);
    sub_11C2F0();
    sub_117174(3);
  }
  JUMPOUT(0xF1662);
}
// F4826: control flows out of bounds to F1662
// F47B1: variable 'v3' is possibly undefined
// F47DD: variable 'v4' is possibly undefined
// F484B: variable 'v6' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 192680: using guessed type int dword_192680;
// 192688: using guessed type int dword_192688;
// 19268C: using guessed type int dword_19268C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199A08: using guessed type int16_t word_199A08;
// 199BF3: using guessed type char byte_199BF3;
// 199F3A: using guessed type char byte_199F3A;
// 1AB082: using guessed type int16_t byte_1AB082[2];
// 1AB087: using guessed type char byte_1AB087;


//----- (000F4981) --------------------------------------------------------
void sub_F4981()
{
  int v0; // edi
  int v1; // ebx
  _DWORD *v2; // eax
  int v3; // ebx

  dword_192680 = (int)&unk_1AACB4;
  memset(&unk_1AACB4, 0, 491);
  v0 = dword_192680;
  v1 = dword_193174;
  *(_DWORD *)dword_192680 = *(_DWORD *)aEvanAxelrad;
  strcpy((char *)(v0 + 4), " Axelrad");
  *(_DWORD *)(dword_192680 + 15) = sub_127C27((int)aMultigmLbx, 0, v1);
  *(_DWORD *)(dword_192680 + 47) = sub_127C27((int)aMultigmLbx, 35, dword_193174);
  *(_DWORD *)(dword_192680 + 83) = sub_127C27((int)aMultigmLbx, 38, dword_193174);
  *(_DWORD *)(dword_192680 + 87) = sub_127C27((int)aMultigmLbx, 39, dword_193174);
  *(_DWORD *)(dword_192680 + 115) = sub_126B42((int)aMultigmLbx, 36, dword_192ED4);
  v2 = sub_126B42((int)aMultigmLbx, 37, dword_192ED4);
  v3 = dword_192680;
  *(_DWORD *)(dword_192680 + 111) = v2;
  *(_WORD *)(v3 + 243) = (640 - **(int16_t **)(v3 + 47)) / 2;
  *(_WORD *)(v3 + 245) = (480 - *(int16_t *)(*(_DWORD *)(v3 + 47) + 2)) / 2;
  qmemcpy(&unk_1AAED5, &dword_199C0D, 0x83u);
  qmemcpy(&dword_1AAEC4, &dword_199BFC, 0x11u);
  JUMPOUT(0xF5204);
}
// F4AC3: control flows out of bounds to F5204
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192680: using guessed type int dword_192680;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 199BFC: using guessed type int dword_199BFC;
// 199C0D: using guessed type int dword_199C0D;
// 1AAEC4: using guessed type int dword_1AAEC4;


//----- (000F4B41) --------------------------------------------------------
int __fastcall sub_F4B41( int a1, int a2, int a3)
{
  _BOOL1 v3; // zf

  v3 = a1 == 6;
  if ( a1 == 6 )
    v3 = byte_1783DA == -1;
  if ( v3 )
    sub_1247A0(6u);
  return 113 * a3;
}
// 1783DA: using guessed type char byte_1783DA;


//----- (000F4B81) --------------------------------------------------------
void *GetGameFlagsTable_F4B81()
{
  return &unk_1784DD;
}


//----- (000F4C45) --------------------------------------------------------
char __usercall sub_F4C45(int a1)
{
  int v1; // ecx

  v1 = dword_197F98
     + 3753 * *(uint8_t *)(113 * *(uint8_t *)(17 * a1 + dword_1930D4 + 2) + dword_19306C + 20);
  return *(_BYTE *)(v1 + 2218) + 1 - *(_BYTE *)(v1 + 2217);
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000F4D0E) --------------------------------------------------------
void sub_F4D0E()
{
  ;
}


//----- (000F4D24) --------------------------------------------------------
char __fastcall sub_F4D24(int a1, int a2)
{
  char result; // al

  result = sub_FE92D(a1, a2);
  if ( byte_178461 == -1 && result == 7 )
    return 4;
  return result;
}
// 178461: using guessed type char byte_178461;


//----- (000F4D39) --------------------------------------------------------
char __fastcall sub_F4D39( int a1, _WORD *a2, _BYTE *a3, int a4, int a5)
{
  byte_178461 |= 1u;
  return sub_8C840(a1, a2, a3, a4, a5);
}
// 178461: using guessed type char byte_178461;


//----- (000F4D46) --------------------------------------------------------
char __fastcall sub_F4D46( int a1, _WORD *a2, _BYTE *a3, int a4, int a5)
{
  byte_178461 &= ~1u;
  return sub_8C840(a1, a2, a3, a4, a5);
}
// 178461: using guessed type char byte_178461;


//----- (000F4D53) --------------------------------------------------------
void sub_F4D53()
{
  ;
}


//----- (000F4D99) --------------------------------------------------------
void __usercall sub_F4D99(int16_t *a1)
{
  int v1; // eax
  int v2; // ebx
  int v3; // eax
  int v4; // ebx
  int v5; // ecx
  int64_t v6; // rax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  int16_t v10; // ax
  _BYTE v11[12]; // [esp+61Ch] [ebp-10h] BYREF
  int v12; // [esp+628h] [ebp-4h] BYREF

  LOBYTE(word_18FF78) = 0;
  sub_123E6C((int)&unk_17CF4A, 1);
  sub_107AF(&v12);
  sub_123E6C((int)&unk_17CF4A, 1);
  LOWORD(v1) = sub_11C2F0();
  sub_F42CA(v1, 1, 255, a1);
  sub_C5BB9();
  sub_1205E6(11, 0, 255);
  sub_1318D4(0, 255);
  sub_131F7B();
  sub_132C80(100);
  sub_123E6C((int)&unk_17CF00, 1);
  sub_6FAD5();
  sub_124D41();
  v2 = sub_127C27((int)aMultigmLbx, 0, dword_193174);
  *(_DWORD *)(dword_192680 + 15) = v2;
  sub_12A478(0, 0, v2);
  v3 = sub_131922(0, 255);
  sub_1077D(v3, 255, v2, a1);
  sub_C5C44();
  sub_124D7A();
  v4 = *(_DWORD *)(dword_192680 + 15);
  sub_12A478(0, 0, v4);
  sub_124E36();
  sub_1191CA((int)sub_F2082, 1);
  HIDWORD(v6) = 1;
  v5 = 0;
  sub_123E6C((int)&unk_17CF00, 1);
  sub_F009A();
  while ( 1 )
  {
    if ( (_WORD)v5 )
    {
      sub_11C2F0();
      sub_107BA(&v12);
      sub_11C2F0();
      dword_192680 = 0;
      sub_1196F7();
      sub_11BE4();
      JUMPOUT(0xF5203);
    }
    sub_12C2A0();
    HIDWORD(v6) = sub_1171AB(v6, SHIDWORD(v6), v4, v5);
    v4 = HIDWORD(v6);
    if ( WORD2(v6) != *(_WORD *)(dword_192680 + 215) || *(_WORD *)(dword_192680 + 247) )
    {
      if ( WORD2(v6) != *(_WORD *)(dword_192680 + 217) || *(_WORD *)(dword_192680 + 249) )
      {
        if ( WORD2(v6) != *(_WORD *)(dword_192680 + 219) || *(_WORD *)(dword_192680 + 251) )
        {
          if ( WORD2(v6) != *(_WORD *)(dword_192680 + 221) || *(_WORD *)(dword_192680 + 253) )
          {
            if ( WORD2(v6) == *(_WORD *)(dword_192680 + 223) )
            {
              v5 = 1;
              word_199A08 = 10;
            }
          }
          else
          {
            byte_199BF2 = 4;
          }
        }
        else
        {
          byte_199BF2 = 3;
        }
      }
      else
      {
        byte_199BF2 = 2;
      }
    }
    else
    {
      byte_199BF2 = 1;
    }
    if ( WORD2(v6) == *(_WORD *)(dword_192680 + 233) )
    {
      if ( *(_WORD *)(dword_192680 + 251) )
      {
        sub_124D41();
        LODWORD(v6) = sub_F2082();
        sub_1077D(v6, SHIDWORD(v6), SHIDWORD(v6), a1);
        byte_199BF2 = 3;
        HIDWORD(v6) = 1;
        sub_F520A(v4, (int)a1);
LABEL_20:
        sub_F42CA(v6, 1, v4, a1);
        sub_1191CA((int)sub_F2082, 1);
        sub_11C2F0();
        sub_F009A();
        sub_6FAD5();
        goto LABEL_44;
      }
      if ( *(_WORD *)(dword_192680 + 249) )
      {
        sub_124D41();
        LODWORD(v6) = sub_F2082();
        v6 = (unsigned int)sub_1077D(v6, SHIDWORD(v6), SHIDWORD(v6), a1) | 0x100000000LL;
        byte_199BF2 = 2;
        LODWORD(v6) = nullsub_13(v6, 1);
        goto LABEL_20;
      }
    }
    else
    {
      if ( WORD2(v6) != *(_WORD *)(dword_192680 + 229) )
      {
        if ( WORD2(v6) == *(_WORD *)(dword_192680 + 227) )
        {
          if ( byte_199BF2 == 3 )
          {
            v9 = sub_7A990(0x1Cu);
            sub_77658((int)v9);
            if ( !v10 )
              goto LABEL_44;
          }
          else if ( !byte_199BF3 )
          {
            strcpy(&byte_199BF3, "Moo II ");
            a1 = (int16_t *)&algn_199BFA[1];
            v6 = j___clock(dword_192680, HIDWORD(v6), HIDWORD(v6));
            byte_199BF9 = (v6 & 0x1F) + 97;
          }
          word_199A08 = 13;
        }
        else
        {
          if ( WORD2(v6) != *(_WORD *)(dword_192680 + 231) )
            goto LABEL_44;
          word_199A08 = 22;
        }
        goto LABEL_43;
      }
      BYTE4(v6) = 1;
      word_199A08 = 15;
      BYTE5(v6) = sub_F33AE((int)v11);
      if ( !BYTE5(v6) )
      {
        v7 = sub_7A990(0xF4u);
        sub_77433(v7);
        goto LABEL_44;
      }
      if ( byte_199BF2 == 3 )
      {
        v8 = sub_7A990(0x1Cu);
        sub_77658((int)v8);
        BYTE4(v6) = (_WORD)v6 != 0;
      }
      if ( BYTE4(v6) )
      {
        word_199A08 = 41;
        sub_11BE4();
        sub_11C2F0();
        sub_F4760(v4, a1);
        HIDWORD(v6) = (int16_t)v6;
        if ( (int16_t)v6 <= -1 || (int16_t)v6 >= 10 )
        {
          sub_F42CA(v6, (int16_t)v6, v4, a1);
          word_199A08 = 15;
        }
        else if ( byte_199F3A == 1 )
        {
          word_199A08 = 17;
        }
        else
        {
          word_199A08 = 41;
        }
LABEL_43:
        v5 = 1;
      }
    }
LABEL_44:
    if ( !(_WORD)v5 )
    {
      sub_F009A();
      sub_124D41();
      LODWORD(v6) = sub_F2082();
      sub_1077D(v6, SHIDWORD(v6), v4, a1);
    }
    sub_12C2C6(2);
  }
}
// F51FE: control flows out of bounds to F5203
// F4DD9: variable 'v1' is possibly undefined
// F4EAE: variable 'v6' is possibly undefined
// F516C: variable 'v10' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// F4AC8: using guessed type int __fastcall nullsub_13(_DWORD, _DWORD);
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 18FF78: using guessed type int16_t word_18FF78;
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;
// 199A08: using guessed type int16_t word_199A08;
// 199BF2: using guessed type char byte_199BF2;
// 199BF3: using guessed type char byte_199BF3;
// 199BF9: using guessed type char byte_199BF9;
// 199BFA: using guessed type _BYTE[2];
// 199F3A: using guessed type char byte_199F3A;


//----- (000F4FD5) --------------------------------------------------------
// DECOMP_TODO (opraveno v teto vlne): puvodni kod volal strstr pres
// podezrely pretypovany ukazatel na funkci s JEDINYM parametrem:
//   result = ((int (__fastcall *)(int))strstr)(a2 + 34);
// strstr ale potrebuje DVA parametry (haystack, needle). Stejny druh
// artefaktu jako u ParseCommandLine_107E6 (viz vlna 02) - puvodni Watcom
// kod spolehal na to, ze parametr a1 uz sedi ve spravnem registru z doby,
// kdy byla tato funkce zavolana, takze zadna instrukce pro jeho predani
// nebyla treba. Pri prekladu modernim kompilatorem uz tohle NEPLATI (jiny
// stack frame, jine registry) - proto to v runtime padalo na Access
// Violation (viz obrazek v zadani - ctenie z nesmyslne adresy).
// Oprava: explicitni volani strstr se DVEMA parametry.
//
// DECOMP_TODO (a2 - zdroj textu k prohledani): puvodni kod pocital cilovou
// adresu jako "&stackAnchor_v16 - 67 + 34" (viz puvodni verze
// ParseCommandLine_107E6 pred vlnou 05) - vyraz zavisly na PRESNEM stack
// frame puvodniho Watcom prekladace, ktery se pri prekladu modernim
// kompilatorem NEZACHOVA (jiny layout lokalnich promennych), takze
// vysledna adresa byla po prekompilovani nesmyslna - to je skutecna
// prvotni pricina padu, ne jen chybejici druhy parametr strstr vyse.
// Funkcne davá jednoznacny smysl, ze tato funkce ma - stejne jako vsechny
// sousedni "strstr(currentArg_v17, ...)" kontroly ve stejne smycce - hledat
// vzor v prave zpracovavanem argumentu prikazove radky, takze volajici
// (ParseCommandLine_107E6) uz ted primo predava "currentArg_v17" misto
// puvodniho nepresnosneho vypoctu. Presny puvodni bytovy posun (+34) se
// nepodarilo overit (neodpovida zadne pojmenovane lokalni promenne v
// puvodnim rozpisu stack frame) - ale funkcni zamer je jednoznacny.
int MarkCheatPatternFlag_F4FD5(char *pattern_a1, char *argText_a2)
{
  int patternFound_result; // eax - 1 pokud se vzor v argText_a2 nasel, jinak 0
  char *patternEnd_v3;     // edx - ukazatel na bajt hned za koncem vzoru v pameti

  // DECOMP_TODO: zapis "*patternEnd_v3 = -1" pri nalezeni vzoru spoleha na
  // to, ze bezprostredne za textovym literalem "pattern_a1" v pameti lezi
  // samostatny bajt slouzici jako priznak (potvrzeno v orion_data.c - napr.
  // za "aNowh" nasleduje "byte_1783D3"). To je krehky trik zavisly na
  // PRESNEM poradi globalnich promennych v pameti, jak je usporadal puvodni
  // Watcom linker - moderni linker (MSVC) stejne poradi negarantuje (mj.
  // muze slucovat identicke retezcove literaly, pridavat zarovnani atd.).
  // Zatim ponechano 1:1 kvuli zachovani chovani (a protoze presny vyznam
  // vsech takto ulozenych priznaku - zejmena uvnitr GetGameFlagsTable_F4B81
  // tabulky - jeste neni prozkoumany), ale je to jasny kandidat na
  // nahrazeni radnou strukturou v nekterI z pristich vln, az bude jasne,
  // co presne kazdy priznak rika a kdo ho cte.
  patternFound_result = strstr(argText_a2, pattern_a1) != NULL;
  patternEnd_v3 = pattern_a1;
  while ( *patternEnd_v3 )
    ++patternEnd_v3;
  ++patternEnd_v3;
  if ( patternFound_result )
    *patternEnd_v3 = -1;
  return patternFound_result;
}


//----- (000F520A) --------------------------------------------------------
void __usercall sub_F520A(int j, int a2)
{
  int v2; // edx
  int v3; // ecx
  int v4; // eax
  int16_t i; // bx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // [esp+0h] [ebp-8h]
  int v10; // [esp+4h] [ebp-4h]

  v9 = dword_1AAEC4;
  v10 = dword_1AAEC8;
  sub_F4981();
  sub_1191CA((int)sub_F28B4, 1);
  v2 = *(int16_t *)(dword_192680 + 245);
  v3 = 0;
  sub_6FB1F(*(_WORD *)(dword_192680 + 243), v2);
  while ( 1 )
  {
    sub_11C2F0();
    v4 = sub_F0943(a2);
    v2 = sub_1171AB(v4, v2, j, v3);
    *(_WORD *)(dword_192680 + 257) = (uint16_t)sub_114177();
    for ( i = 0; i < 8 && *(_WORD *)(dword_192680 + 251) == 1; ++i )
    {
      a2 = i;
      if ( (_WORD)v2 == *(_WORD *)(2 * i + dword_192680 + 167) )
      {
        v2 = -1;
        dword_1AAEC4 = i;
        *(_WORD *)(dword_192680 + 251) = 0;
      }
    }
    for ( j = 0; (int16_t)j < 8 && *(_WORD *)(dword_192680 + 251) == 2; ++j )
    {
      a2 = 2 * (int16_t)j;
      if ( (_WORD)v2 == *(_WORD *)(a2 + dword_192680 + 167) )
      {
        dword_1AAEC8 = atoi(&a1200[6 * (int16_t)j]);
        v2 = -1;
        *(_WORD *)(dword_192680 + 251) = 0;
      }
    }
    v6 = dword_192680;
    if ( (_WORD)v2 == *(_WORD *)(dword_192680 + 167) )
    {
      *(_WORD *)(dword_192680 + 251) = 1;
    }
    else
    {
      if ( (_WORD)v2 != *(_WORD *)(dword_192680 + 169) )
        goto LABEL_19;
      *(_WORD *)(dword_192680 + 251) = 2;
    }
    *(_WORD *)(v6 + 257) = -1;
    sub_11C2F0();
LABEL_19:
    if ( (_WORD)v2 == *(_WORD *)(dword_192680 + 213) )
    {
      *(_WORD *)(dword_192680 + 251) = 0;
    }
    else if ( (_WORD)v2 == *(_WORD *)(dword_192680 + 223) )
    {
      dword_1AAEC4 = v9;
      v3 = 1;
      dword_1AAEC8 = v10;
    }
    else if ( (_WORD)v2 == *(_WORD *)(dword_192680 + 225) )
    {
      v3 = 1;
    }
    if ( (_WORD)v3 )
    {
      qmemcpy(&dword_199C0D, &unk_1AAED5, 0x83u);
      qmemcpy(&dword_199BFC, &dword_1AAEC4, 0x11u);
      JUMPOUT(0xF51FE);
    }
    v7 = sub_124D41();
    v8 = sub_F28B4(v7, v2);
    sub_1077D(v8, v2, j, (int16_t *)a2);
  }
}
// F53C6: control flows out of bounds to F51FE
// 126622: using guessed type int __fastcall atoi(_DWORD);
// 192680: using guessed type int dword_192680;
// 199BFC: using guessed type int dword_199BFC;
// 199C0D: using guessed type int dword_199C0D;
// 1AAEC4: using guessed type int dword_1AAEC4;
// 1AAEC8: using guessed type int dword_1AAEC8;


//----- (000F53CB) --------------------------------------------------------
int sub_F53CB()
{
  byte_1AAE9F = 1;
  return sub_F53D7(30);
}
// F53D7: using guessed type int __fastcall sub_F53D7(_DWORD);
// 1AAE9F: using guessed type char byte_1AAE9F;


