#include "orion_common.h"

/* Adresni rozsah: 0xD614D - 0xE5B17  (200 funkci) */

//----- (000D614D) --------------------------------------------------------
int __fastcall sub_D614D(int a1, int a2)
{
  char *v3; // edi
  int16_t v4; // ax
  int16_t v5; // ax
  char *v6; // edi
  int16_t v7; // ax
  int16_t v8; // ax
  int16_t v9; // ax
  int v10; // ecx
  int16_t v11; // ax
  int16_t v13; // [esp+0h] [ebp-8h]
  int16_t v14; // [esp+4h] [ebp-4h]
  int16_t v15; // [esp+4h] [ebp-4h]

  v3 = (char *)dword_1AA224;
  sub_DDFD3((char *)dword_1AA224, a1, 0);
  v14 = v4;
  sub_DDFD3(v3, a1, 1);
  v13 = v14 - v5;
  v6 = (char *)dword_1AA224;
  sub_DDFD3((char *)dword_1AA224, a2, 0);
  v15 = v7;
  sub_DDFD3(v6, a2, 1);
  if ( v15 - v8 != v13 )
    return (int16_t)(v15 - v8) - v13;
  sub_DDFD3((char *)dword_1AA224, a1, 0);
  v10 = v9;
  sub_DDFD3((char *)dword_1AA224, a2, 0);
  return v10 - v11;
}
// D616F: variable 'v4' is possibly undefined
// D6182: variable 'v5' is possibly undefined
// D6199: variable 'v7' is possibly undefined
// D61A8: variable 'v8' is possibly undefined
// D61C0: variable 'v9' is possibly undefined
// D61D1: variable 'v11' is possibly undefined
// 1AA224: using guessed type int dword_1AA224;


//----- (000D61E7) --------------------------------------------------------
void __fastcall sub_D61E7(uint8_t *a1)
{
  int v2; // edi
  int v3; // eax
  char v4; // al
  int v5; // edx
  uint8_t v6; // al

  v2 = 361 * *a1 + dword_192B18;
  sub_D5FE1(a1);
  dword_1AA224 = v2;
  qsort(v2 + 12 + 4 * a1[3], *(uint8_t *)(v2 + 10) - a1[3], 4);
  if ( *(_BYTE *)(v2 + 221) )
  {
    while ( 1 )
    {
      sub_E1D59((char *)v2);
      if ( a1[4] >= a1[5] )
        break;
      if ( 2 * *(int16_t *)(v2 + 231) >= *(uint8_t *)(v2 + 254)
                                       + *(uint8_t *)(v2 + 253)
                                       + *(uint8_t *)(v2 + 252)
                                       + *(uint8_t *)(v2 + 255) )
      {
        v3 = --a1[5];
        *(_WORD *)(v2 + 4 * v3 + 12) &= 0xFE7Fu;
        *(_BYTE *)(v2 + 4 * v3 + 12) |= 0x80u;
        *(_BYTE *)(v2 + 4 * a1[5] + 13) |= 2u;
      }
      else if ( a1[1] < *(_BYTE *)(v2 + 224) )
      {
        *(_WORD *)(v2 + 4 * a1[4] + 12) &= 0xFE7Fu;
        *(_BYTE *)(v2 + 4 * a1[4] + 13) |= 2u;
        ++a1[1];
        ++a1[4];
      }
    }
  }
  else
  {
    if ( sub_23DFE(*a1) )
      v4 = 2;
    else
      v4 = 1;
    v5 = (v4 & 3) << 7;
    while ( 1 )
    {
      v6 = a1[4];
      if ( v6 >= a1[5] )
        break;
      *(_WORD *)(v2 + 4 * v6 + 12) &= 0xFE7Fu;
      *(_DWORD *)(v2 + 4 * v6 + 12) |= v5;
      *(_BYTE *)(v2 + 4 * a1[4]++ + 13) |= 2u;
    }
  }
  sub_E1D59((char *)v2);
  JUMPOUT(0xD5CE8);
}
// D6310: control flows out of bounds to D5CE8
// 192B18: using guessed type int dword_192B18;
// 1AA224: using guessed type int dword_1AA224;


//----- (000D6315) --------------------------------------------------------
void __fastcall sub_D6315(int a1, int a2)
{
  sub_DDFD3((char *)dword_1AA224, a1, 1);
  sub_DDFD3((char *)dword_1AA224, a2, 1);
  sub_DDFD3((char *)dword_1AA224, a1, 2);
  sub_DDFD3((char *)dword_1AA224, a2, 2);
  JUMPOUT(0xD61D2);
}
// D638A: control flows out of bounds to D61D2
// 1AA224: using guessed type int dword_1AA224;


//----- (000D63A6) --------------------------------------------------------
void __fastcall sub_D63A6(int a1, int a2)
{
  if ( *(_BYTE *)(dword_1AA224 + 221) )
  {
    sub_DDFD3((char *)dword_1AA224, a1, 0);
    sub_DDFD3((char *)dword_1AA224, a1, 1);
    sub_DDFD3((char *)dword_1AA224, a1, 2);
    sub_DDFD3((char *)dword_1AA224, a2, 0);
    sub_DDFD3((char *)dword_1AA224, a2, 1);
    sub_DDFD3((char *)dword_1AA224, a2, 2);
  }
  else
  {
    sub_D6315(a1, a2);
  }
  JUMPOUT(0xD61D6);
}
// D646A: control flows out of bounds to D61D6
// 1AA224: using guessed type int dword_1AA224;


//----- (000D648A) --------------------------------------------------------
void __fastcall sub_D648A(uint8_t *a1)
{
  char *v2; // esi
  uint8_t v3; // al
  int v4; // edi
  int16_t v5; // ax
  int16_t v6; // ax
  int16_t v7; // ax
  int16_t v8; // ax
  int v9; // [esp+0h] [ebp-8h]
  int16_t v10; // [esp+4h] [ebp-4h]

  v2 = (char *)(361 * *a1 + dword_192B18);
  v3 = a1[4];
  if ( v3 >= a1[5] )
  {
    *((_WORD *)a1 + 4) = -32767;
    *((_WORD *)a1 + 5) = 0x7FFF;
  }
  else
  {
    v4 = (int)&v2[4 * v3 + 12];
    v9 = (int)&v2[4 * a1[5] + 8];
    sub_DDFD3(v2, v4, 2);
    v10 = v5;
    sub_DDFD3(v2, v4, 1);
    *((_WORD *)a1 + 4) = v10 - v6;
    sub_DDFD3(v2, v9, 2);
    LOWORD(v4) = v7;
    sub_DDFD3(v2, v9, 1);
    *((_WORD *)a1 + 5) = v4 - v8;
  }
  JUMPOUT(0xD5CE7);
}
// D6516: control flows out of bounds to D5CE7
// D64DB: variable 'v5' is possibly undefined
// D64EF: variable 'v6' is possibly undefined
// D6507: variable 'v7' is possibly undefined
// D6510: variable 'v8' is possibly undefined
// 192B18: using guessed type int dword_192B18;


//----- (000D652C) --------------------------------------------------------
void __fastcall sub_D652C(uint8_t *a1)
{
  int v2; // edi
  char *v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-4h]

  v2 = 361 * *a1 + dword_192B18;
  v5 = (*(uint8_t *)(v2 + 10) + 4) / 5;
  sub_D5FE1(a1);
  dword_1AA224 = v2;
  qsort(v2 + 12 + 4 * a1[3], *(uint8_t *)(v2 + 10) - a1[3], 4);
  if ( sub_23DFE(*a1) )
    v5 = 0;
  v3 = (char *)v2;
  while ( 1 )
  {
    sub_E1D59(v3);
    if ( a1[4] >= a1[6]
      || a1[2] >= v5
      && 2 * *(int16_t *)(v2 + 233) >= *(uint8_t *)(v2 + 259)
                                     + *(uint8_t *)(v2 + 258)
                                     + *(uint8_t *)(v2 + 256)
                                     + *(uint8_t *)(v2 + 257) )
    {
      break;
    }
    v4 = --a1[6];
    *(_WORD *)(v2 + 4 * v4 + 12) &= 0xFE7Fu;
    *(_BYTE *)(v2 + 4 * v4 + 12) |= 0x80u;
    *(_BYTE *)(v2 + 4 * a1[6] + 13) |= 2u;
    v3 = (char *)v2;
    ++a1[2];
  }
  a1[5] = a1[6];
  a1[7] = *(_BYTE *)(v2 + 8);
  dword_1AA224 = v2;
  qsort(4 * a1[3] + v2 + 12, a1[5] - a1[4], 4);
  sub_D648A(a1);
  JUMPOUT(0xD5CE7);
}
// D6646: control flows out of bounds to D5CE7
// 192B18: using guessed type int dword_192B18;
// 1AA224: using guessed type int dword_1AA224;


//----- (000D664B) --------------------------------------------------------
void __fastcall sub_D664B(uint8_t *a1)
{
  int v1; // edx
  int v2; // ebx
  int v3; // ebx
  int v4; // edx

  v1 = 361 * *a1;
  v2 = dword_192B18;
  --a1[5];
  v3 = v1 + v2;
  v4 = a1[5];
  *(_WORD *)(v3 + 4 * v4 + 12) &= 0xFE7Fu;
  *(_BYTE *)(v3 + 4 * v4 + 12) |= 0x80u;
  *(_BYTE *)(v3 + 4 * a1[5] + 13) |= 2u;
  sub_D648A(a1);
}
// 192B18: using guessed type int dword_192B18;


//----- (000D6682) --------------------------------------------------------
void __fastcall sub_D6682(uint8_t *a1)
{
  int v1; // ebx
  int v2; // edx

  v1 = 361 * *a1 + dword_192B18;
  v2 = a1[4];
  *(_WORD *)(v1 + 4 * v2 + 12) &= 0xFE7Fu;
  *(_BYTE *)(v1 + 4 * v2 + 13) |= 1u;
  *(_BYTE *)(v1 + 4 * a1[4]++ + 13) |= 2u;
  JUMPOUT(0xD667A);
}
// D66B1: control flows out of bounds to D667A
// 192B18: using guessed type int dword_192B18;


//----- (000D66B3) --------------------------------------------------------
void __usercall sub_D66B3(int a1)
{
  int v1; // ebx
  int v2; // ecx
  unsigned int v3; // eax
  uint8_t *v4; // edx
  int16_t v5; // si
  int v6; // esi
  int v7; // eax
  uint8_t *v8; // eax
  int v9; // edi
  int16_t v10; // si
  unsigned int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // esi
  int v15; // eax
  char v16; // [esp+0h] [ebp-4h]

  v1 = 10;
  v2 = 18;
  v16 = 0;
  if ( *(int16_t *)(dword_1AA21C + 178) < 0 )
    v2 = sub_134C92(-*(int16_t *)(dword_1AA21C + 178)) + 18;
  if ( *(_BYTE *)(dword_1AA21C + 1437) )
  {
    v1 = 0;
  }
  else if ( *(_BYTE *)(dword_1AA21C + 40) == 3 )
  {
    v1 = 12;
  }
  else if ( *(_BYTE *)(dword_1AA21C + 40) == 4 )
  {
    v2 += 2;
  }
  sub_E2D72(word_1AA234, a1);
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v16 )
        JUMPOUT(0xD5CE7);
      if ( v2 * *(int16_t *)(dword_1AA21C + 172) >= (unsigned int)(v1 * *(int16_t *)(dword_1AA21C + 170)) )
        break;
      v5 = -32767;
      v9 = dword_1AA230;
      v4 = 0;
      v3 = dword_1AA230 + 13 * word_1AA236;
      while ( v3 > dword_1AA230 )
      {
        v3 -= 13;
        if ( v5 < *(int16_t *)(v3 + 8) )
        {
          v4 = (uint8_t *)v3;
          v5 = *(_WORD *)(v3 + 8);
        }
      }
      if ( !v4 )
        goto LABEL_14;
      v6 = 361 * *v4 + dword_192B18;
      v7 = v4[4];
      *(_WORD *)(v6 + 4 * v7 + 12) &= 0xFE7Fu;
      *(_BYTE *)(v6 + 4 * v7 + 13) |= 1u;
      *(_BYTE *)(v6 + 4 * v4[4] + 13) |= 2u;
      v8 = v4;
      ++v4[4];
LABEL_16:
      sub_D648A(v8);
      sub_E2A70(*v4, v9);
    }
    v10 = 0x7FFF;
    v9 = dword_1AA230;
    v4 = 0;
    v11 = dword_1AA230 + 13 * word_1AA236;
    while ( v11 > dword_1AA230 )
    {
      v11 -= 13;
      if ( v10 > *(int16_t *)(v11 + 10) )
      {
        v4 = (uint8_t *)v11;
        v10 = *(_WORD *)(v11 + 10);
      }
    }
    if ( v4 )
    {
      v12 = 361 * *v4;
      v13 = dword_192B18;
      --v4[5];
      v14 = v13 + v12;
      v15 = v4[5];
      *(_WORD *)(v14 + 4 * v15 + 12) &= 0xFE7Fu;
      *(_BYTE *)(v14 + 4 * v15 + 12) |= 0x80u;
      *(_BYTE *)(v14 + 4 * v4[5] + 13) |= 2u;
      v8 = v4;
      goto LABEL_16;
    }
LABEL_14:
    v16 = 1;
  }
}
// D677C: control flows out of bounds to D5CE7
// 192B18: using guessed type int dword_192B18;
// 1AA21C: using guessed type int dword_1AA21C;
// 1AA230: using guessed type int dword_1AA230;
// 1AA234: using guessed type int16_t word_1AA234;
// 1AA236: using guessed type int16_t word_1AA236;


//----- (000D682A) --------------------------------------------------------
int __fastcall sub_D682A(uint8_t *a1, _DWORD *a2)
{
  int16_t v3; // ax
  int v4; // edi
  int16_t v5; // ax
  int v6; // edi
  int result; // eax
  int16_t v8; // ax

  sub_DDFD3((char *)(dword_192B18 + 361 * *a1), (int)a2, 0);
  v4 = v3;
  if ( (*a2 & 0x180) == 0x80 )
  {
    sub_DDFD3((char *)(361 * *a1 + dword_192B18), (int)a2, 1);
    v6 = v4 - v5;
    result = v6;
    if ( a1[7] < *(int16_t *)(361 * *a1 + dword_192B18 + 8) )
      return v6 + 1000;
  }
  else
  {
    sub_DDFD3((char *)(361 * *a1 + dword_192B18), (int)a2, 2);
    return v4 - v8;
  }
  return result;
}
// D684C: variable 'v3' is possibly undefined
// D6882: variable 'v5' is possibly undefined
// D68C1: variable 'v8' is possibly undefined
// 192B18: using guessed type int dword_192B18;


//----- (000D68CB) --------------------------------------------------------
void __fastcall sub_D68CB(_DWORD *a1, _DWORD *a2)
{
  sub_DDFD3((char *)dword_1AA224, (int)a1, 0);
  sub_DDFD3((char *)dword_1AA224, (int)a2, 0);
  if ( (*a1 & 0x180) == 0x80 )
    sub_DDFD3((char *)dword_1AA224, (int)a1, 1);
  else
    sub_DDFD3((char *)dword_1AA224, (int)a1, 2);
  if ( (*a2 & 0x180) == 0x80 )
    sub_DDFD3((char *)dword_1AA224, (int)a2, 1);
  else
    sub_DDFD3((char *)dword_1AA224, (int)a2, 2);
  JUMPOUT(0xD61D6);
}
// D69EC: control flows out of bounds to D61D6
// 1AA224: using guessed type int dword_1AA224;
// 1AA228: using guessed type int dword_1AA228;


//----- (000D6A00) --------------------------------------------------------
void __fastcall sub_D6A00(uint8_t *a1)
{
  int v2; // edi
  int v3; // edx
  int v4; // eax
  int v5; // edx

  v2 = 361 * *a1 + dword_192B18;
  v3 = *(int16_t *)(v2 + 8);
  *(_WORD *)(v2 + 4 * a1[4] + 12) &= 0xFE7Fu;
  *(_BYTE *)(v2 + 4 * a1[4]++ + 13) |= 2u;
  ++a1[1];
  sub_E1D59((char *)v2);
  if ( *(int16_t *)(v2 + 8) < v3 )
  {
    dword_1AA224 = 361 * *a1 + dword_192B18;
    v4 = a1[4];
    v5 = a1[5] - v4;
    dword_1AA228 = (int)a1;
    qsort(dword_1AA224 + 12 + 4 * v4, v5, 4);
  }
  if ( a1[1] >= *(_BYTE *)(v2 + 224) || a1[4] >= *(_BYTE *)(v2 + 10) )
    *((_WORD *)a1 + 4) = -32767;
  else
    *((_WORD *)a1 + 4) = sub_D682A(a1, (_DWORD *)(dword_192B18 + 361 * *a1 + 12 + 4 * a1[4]));
  JUMPOUT(0xD5CE8);
}
// D6AC4: control flows out of bounds to D5CE8
// 192B18: using guessed type int dword_192B18;
// 1AA224: using guessed type int dword_1AA224;
// 1AA228: using guessed type int dword_1AA228;


//----- (000D6AD4) --------------------------------------------------------
void sub_D6AD4()
{
  int v0; // edi
  uint8_t *v1; // esi
  int v2; // edx
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // edx
  int v9; // esi
  int v10; // esi
  int v11; // ebx
  uint8_t *v12; // eax
  int v13; // esi
  uint8_t *v14; // esi
  signed int v15; // edx
  _DWORD v16[250]; // [esp+0h] [ebp-400h] BYREF
  int v17; // [esp+3E8h] [ebp-18h]
  int v18; // [esp+3ECh] [ebp-14h]
  int v19; // [esp+3F0h] [ebp-10h]
  int v20; // [esp+3F4h] [ebp-Ch]
  char v21; // [esp+3F8h] [ebp-8h]
  char v22; // [esp+3FCh] [ebp-4h]
  _DWORD savedregs[6]; // [esp+400h] [ebp+0h] BYREF

  v22 = 0;
  v21 = 0;
  if ( word_1AA236 > 0 )
  {
    v0 = 0;
    v19 = 0;
    v1 = (uint8_t *)(13 * word_1AA236 + dword_1AA230);
    while ( (unsigned int)v1 > dword_1AA230 )
    {
      v1 -= 13;
      v2 = 361 * *v1 + dword_192B18;
      v1[4] = v1[3];
      v1[5] = v1[6];
      if ( v1[4] < v1[5] && v1[1] < *(_BYTE *)(v2 + 224) && *(_BYTE *)(v2 + 221) )
      {
        v3 = v1[5];
        v4 = v1[4];
        dword_1AA224 = v2;
        v17 = v3 - v4;
        v18 = v2 + 12;
        dword_1AA228 = (int)v1;
        qsort(v2 + 12 + 4 * v4, v3 - v4, 4);
        *((_WORD *)v1 + 4) = sub_D682A(v1, (_DWORD *)(4 * v1[4] + v18));
        v5 = v19;
        ++v0;
        v19 += 4;
        *(_DWORD *)((char *)v16 + v5) = v1;
      }
    }
    sub_E2D09(word_1AA234, v0);
    while ( (*(int16_t *)(dword_1AA21C + 176) < 0 || *(int16_t *)(dword_1AA21C + 56) < 0) && v0 > 0 && !v21 )
    {
      if ( *(int16_t *)(dword_1AA21C + 56) <= 0 )
      {
        v8 = -1;
        v22 = 1;
        v20 = v0;
        v11 = v0;
        while ( v20 > 0 )
        {
          v12 = (uint8_t *)savedregs[v11 - 257];
          v13 = dword_192B18 + 361 * *v12;
          v18 = *(uint8_t *)(v13 + 252);
          v17 = *(uint8_t *)(v13 + 253);
          v18 += v17;
          v17 = *(uint8_t *)(v13 + 254);
          --v20;
          v17 += v18;
          --v11;
          v18 = *(uint8_t *)(v13 + 255);
          if ( 2 * *(int16_t *)(v13 + 231) < v18 + v17 && (v8 == -1 || *(_WORD *)(v16[v8] + 8) < *((_WORD *)v12 + 4)) )
            v8 = v20;
        }
      }
      else
      {
        v6 = v0;
        v7 = v0;
        v8 = 0;
        while ( 1 )
        {
          v10 = v6;
          --v7;
          --v6;
          if ( v10 <= 1 )
            break;
          v9 = v16[v8];
          v17 = v16[v7];
          if ( *(_WORD *)(v9 + 8) < *(_WORD *)(v17 + 8) )
            v8 = v6;
        }
      }
      if ( v8 == -1 )
      {
        v21 = 1;
      }
      else
      {
        v14 = (uint8_t *)v16[v8];
        sub_D6A00(v14);
        sub_E2A70(*v14, v0);
        if ( v14[4] >= v14[5] || v14[1] >= *(_BYTE *)(361 * *v14 + dword_192B18 + 224) )
          memmove(&v16[v8], &v16[v8 + 1], 4 * (--v0 - v8));
      }
    }
  }
  if ( v22 )
  {
    v15 = (uint8_t)byte_199CB0;
    if ( (int)sub_1247A0(0xAu) <= v15 )
      *(_WORD *)(dword_1AA21C + 54) += 5;
  }
  JUMPOUT(0xD5CE7);
}
// D6D7B: control flows out of bounds to D5CE7
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 199CB0: using guessed type char byte_199CB0;
// 1AA21C: using guessed type int dword_1AA21C;
// 1AA224: using guessed type int dword_1AA224;
// 1AA228: using guessed type int dword_1AA228;
// 1AA230: using guessed type int dword_1AA230;
// 1AA234: using guessed type int16_t word_1AA234;
// 1AA236: using guessed type int16_t word_1AA236;


//----- (000D6D80) --------------------------------------------------------
void __usercall sub_D6D80(int a1)
{
  uint8_t *v1; // edx
  int v2; // ebx
  int v3; // ecx
  int i; // eax

  v1 = (uint8_t *)(dword_1AA230 + 13 * word_1AA236);
  while ( (unsigned int)v1 > dword_1AA230 )
  {
    v1 -= 13;
    v2 = 361 * *v1 + dword_192B18;
    if ( *(int16_t *)(v2 + 277) == -2 && !*(_BYTE *)(dword_1AA21C + 1437) || sub_23DFE(*v1) )
    {
      v3 = v1[6] - 1;
      for ( i = v2 + 4 * v3; v1[3] <= v3 && (*(_DWORD *)(i + 12) & 0x180) == 0x80; *(_BYTE *)(i + 17) |= 1u )
      {
        i -= 4;
        *(_WORD *)(i + 16) &= 0xFE7Fu;
        --v3;
      }
      sub_E2A70(*v1, a1);
    }
  }
}
// 192B18: using guessed type int dword_192B18;
// 1AA21C: using guessed type int dword_1AA21C;
// 1AA230: using guessed type int dword_1AA230;
// 1AA236: using guessed type int16_t word_1AA236;


//----- (000D6E1D) --------------------------------------------------------
void __usercall sub_D6E1D(int16_t *a1)
{
  uint8_t *i; // edx
  uint8_t *j; // edx
  uint8_t *k; // edx

  for ( i = (uint8_t *)(dword_1AA220 + 13 * word_1AA23A); (unsigned int)i > dword_1AA220; sub_D61E7(i) )
    i -= 13;
  for ( j = (uint8_t *)(dword_1AA230 + 13 * word_1AA236); (unsigned int)j > dword_1AA230; sub_D652C(j) )
    j -= 13;
  sub_D66B3((int)a1);
  sub_D10EE(word_1AA234, a1);
  for ( k = (uint8_t *)(13 * word_1AA238 + dword_1AA22C);
        (unsigned int)k > dword_1AA22C;
        sub_D2754(361 * *k + dword_192B18) )
  {
    k -= 13;
  }
  sub_D6D80((int)a1);
  if ( word_1AA236 <= 0 )
    sub_E2D09(word_1AA234, (int)a1);
  else
    sub_D6AD4();
}
// 192B18: using guessed type int dword_192B18;
// 1AA220: using guessed type int dword_1AA220;
// 1AA22C: using guessed type int dword_1AA22C;
// 1AA230: using guessed type int dword_1AA230;
// 1AA234: using guessed type int16_t word_1AA234;
// 1AA236: using guessed type int16_t word_1AA236;
// 1AA238: using guessed type int16_t word_1AA238;
// 1AA23A: using guessed type int16_t word_1AA23A;


//----- (000D6ED4) --------------------------------------------------------
void __usercall sub_D6ED4( int a1, int a2, int16_t *a3)
{
  int v3; // edx
  int v4; // eax
  char v5; // [esp+0h] [ebp-CB4h] BYREF

  word_1AA234 = a1;
  v3 = 3753 * a1;
  dword_1AA21C = v3 + dword_197F98;
  dword_1AA22C = (int)&v5;
  sub_D5795();
  if ( byte_199CB0 && (int16_t)sub_D1006(word_1AA234) < 3 )
    sub_D58D4(*(_BYTE *)(dword_1AA21C + 803));
  sub_D5CEE();
  sub_D5D99(word_1AA234);
  sub_D5E19();
  sub_D0D2F((int16_t *)word_1AA234);
  sub_D6E1D(a3);
  sub_FE8BE(v4, v3, a2, a3);
  dword_1AA22C = 0;
}
// D6F55: variable 'v4' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;
// 1AA21C: using guessed type int dword_1AA21C;
// 1AA22C: using guessed type int dword_1AA22C;
// 1AA234: using guessed type int16_t word_1AA234;


//----- (000D6F67) --------------------------------------------------------
unsigned int __usercall sub_D6F67(int a1, int16_t *a2)
{
  int v2; // edx
  int v3; // ebx
  unsigned int result; // eax
  int v5; // edx

  v2 = word_199998;
  v3 = 3753 * word_199998;
  while ( v2 > 0 )
  {
    a1 = dword_197F98;
    v3 -= 3753;
    --v2;
    if ( *(_BYTE *)(v3 + dword_197F98 + 40) != 100 )
    {
      sub_FE8BE(dword_197F98, v2, v3, a2);
      sub_D6ED4(v2, v3, a2);
    }
  }
  sub_FE8BE(a1, v2, v3, a2);
  result = dword_192B18 + 361 * word_199996;
  while ( result > dword_192B18 )
  {
    v5 = *(int16_t *)(result - 84);
    result -= 361;
    if ( v5 == -37 )
      *(_WORD *)(result + 277) = -2;
  }
  return result;
}
// D6F9C: variable 'a1' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;


//----- (000D6FDA) --------------------------------------------------------
unsigned int __fastcall sub_D6FDA(int a1, int a2)
{
  int v4; // ebx
  unsigned int result; // eax
  int v6; // edx

  v4 = 0;
  result = dword_197F9C + 129 * word_199994;
  while ( result > dword_197F9C )
  {
    v6 = *(char *)(result - 30);
    result -= 129;
    if ( v6 == a1
      && *(char *)(result + 100) <= 2
      && !*(_BYTE *)(result + 17)
      && *(int16_t *)(result + 116) == -1
      && (!v4
       || *(_BYTE *)(v4 + 16) <= *(_BYTE *)(result + 16)
       && *(_BYTE *)(v4 + 18) <= *(_BYTE *)(result + 18)
       && *(_BYTE *)(v4 + 22) <= *(_BYTE *)(result + 22)
       && *(_BYTE *)(v4 + 21) <= *(_BYTE *)(result + 21)
       && *(_WORD *)(v4 + 114) < *(_WORD *)(result + 114)) )
    {
      v4 = result;
    }
  }
  if ( v4 )
    return sub_98C23(3753 * a1 + dword_197F98, dword_1930DC + 59 * a2, v4);
  return result;
}
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000D7078) --------------------------------------------------------
char __fastcall sub_D7078(int a1, int a2)
{
  int v3; // eax
  int v4; // ecx
  unsigned int v5; // ebx
  int v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-4h]

  v8 = *(int16_t *)(59 * a2 + dword_1930DC + 53);
  v3 = 129 * word_199994;
  v7 = dword_197F9C + 129 * v8;
  v4 = v7;
  v5 = v3 + dword_197F9C;
  while ( v5 > dword_197F9C )
  {
    v3 = *(char *)(v5 - 30);
    v5 -= 129;
    if ( v3 == a1 && *(char *)(v5 + 100) <= 2 && !*(_BYTE *)(v5 + 17) )
    {
      v3 = *(int16_t *)(v5 + 116);
      if ( v3 == -1 )
      {
        LOWORD(v3) = sub_97287((int)(v5 - dword_197F9C) / 129, v8);
        if ( (_WORD)v3 )
        {
          LOBYTE(v3) = *(_BYTE *)(v4 + 16);
          if ( (uint8_t)v3 <= *(_BYTE *)(v5 + 16) )
          {
            LOBYTE(v3) = *(_BYTE *)(v4 + 18);
            if ( (uint8_t)v3 <= *(_BYTE *)(v5 + 18) )
            {
              LOBYTE(v3) = *(_BYTE *)(v4 + 22);
              if ( (uint8_t)v3 <= *(_BYTE *)(v5 + 22) )
              {
                LOBYTE(v3) = *(_BYTE *)(v4 + 21);
                if ( (uint8_t)v3 <= *(_BYTE *)(v5 + 21) )
                {
                  LOWORD(v3) = *(_WORD *)(v4 + 114);
                  if ( (int16_t)v3 < *(int16_t *)(v5 + 114) )
                    v4 = v5;
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v4 != v7 )
    LOBYTE(v3) = sub_98C23(dword_197F98 + 3753 * a1, dword_1930DC + 59 * a2, v4);
  return v3;
}
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000D7171) --------------------------------------------------------
void __fastcall sub_D7171(int a1, int a2)
{
  int v2; // ecx
  char *v3; // ebx
  int v4; // edi
  int v5; // esi
  int v6; // edx
  int v7; // edi
  int v8; // ecx
  int i; // ebx
  int v11; // [esp+4h] [ebp-130h]
  _DWORD v12[72]; // [esp+8h] [ebp-12Ch] BYREF
  int v13; // [esp+128h] [ebp-Ch]
  int v14; // [esp+12Ch] [ebp-8h]
  int v15; // [esp+130h] [ebp-4h]

  v11 = a1;
  v2 = *(_DWORD *)(59 * a2 + dword_1930DC + 42);
  memset(v12, 0, sizeof(v12));
  v14 = 6 * v11;
  v3 = (char *)(dword_192B18 + 361 * word_199996);
  v4 = 361 * word_199996;
  v13 = 3753 * v11;
  while ( (unsigned int)v3 > dword_192B18 )
  {
    v3 -= 361;
    v4 -= 361;
    if ( *v3 == v11 && !v3[6] )
    {
      v5 = *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)v3 + 1) + 2);
      if ( *(char *)(v11 + dword_19306C + 113 * v5 + 66) == -1 )
      {
        if ( (v2 & 1) != 0 || (v2 & 2) != 0 )
        {
          v15 = 7 * (v4 / 361);
          if ( *(_BYTE *)(v15 + dword_1AA1EC + 4) )
            v12[v5] += *((int16_t *)v3 + 4);
        }
        if ( ((v2 & 4) != 0 || (v2 & 8) != 0) && v3[221] )
          v12[v5] += *(int16_t *)(v3 + 231);
        if ( (v2 & 0x10) != 0 || (v2 & 0x20) != 0 )
          v12[v5] += (uint8_t)v3[10];
        if ( (v2 & 0x100) != 0 || (v2 & 0x200) != 0 )
          v12[v5] += *(int16_t *)(v3 + 233);
        if ( (v2 & 0x1000) != 0 || (v2 & 0x2000) != 0 )
          v12[v5] += *(int16_t *)(v3 + 235);
        if ( ((v2 & 0x4000) != 0 || (v2 & 0x8000) != 0) && *(char *)(v13 + dword_197F98 + 2207) / 2 != 3 )
          v12[v5] += (uint8_t)v3[10];
        if ( (v2 & 0x400) != 0 || (v2 & 0x800) != 0 )
        {
          v15 = 361;
          v15 = *(uint8_t *)(dword_1AA1EC + 7 * (v4 / 361) + 1);
          v6 = v15 - (uint8_t)v3[10];
          if ( v6 > 0 )
            v12[v5] += v6;
        }
        if ( ((unsigned int)sub_10000 & v2) != 0 || ((unsigned int)&loc_20000 & v2) != 0 )
          v12[v5] += *(uint8_t *)(v14 + 49 * v5 + dword_1AA1F8 + 2)
                   + *(uint8_t *)(v14 + 49 * v5 + dword_1AA1F8 + 3);
      }
    }
  }
  v7 = word_19999A - 1;
  v8 = word_19999A - 2;
  for ( i = v8; ; --i )
  {
    if ( v12[v7] < v12[i] )
      v7 = v8;
    if ( --v8 < 0 )
    {
      if ( v12[v7] )
        sub_98C87(dword_197F98 + 3753 * v11, 59 * a2 + dword_1930DC, dword_19306C + 113 * v7);
      JUMPOUT(0xD716B);
    }
  }
}
// D73CF: control flows out of bounds to D716B
// 10000: using guessed type void __noreturn sub_10000();
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 19999A: using guessed type int16_t word_19999A;
// 1AA1EC: using guessed type int dword_1AA1EC;
// 1AA1F8: using guessed type int dword_1AA1F8;


//----- (000D73D4) --------------------------------------------------------
void __fastcall sub_D73D4(int a1)
{
  int v2; // ebx
  int v3; // esi
  int v4; // eax
  char v5; // dl

  v2 = 67;
  v3 = 3953;
  do
  {
    v3 -= 59;
    v4 = v3 + dword_1930DC;
    --v2;
    if ( *(char *)(v3 + dword_1930DC + 58) == a1 )
    {
      v5 = *(_BYTE *)(v4 + 57);
      if ( v5 )
      {
        if ( v5 == 1 && !*(_BYTE *)(v4 + 35) )
          sub_D7078(a1, v2);
      }
      else if ( *(_BYTE *)(v4 + 35) )
      {
        sub_D7171(a1, v2);
      }
      else
      {
        sub_D6FDA(a1, v2);
      }
    }
  }
  while ( v2 > 0 );
}
// 1930DC: using guessed type int dword_1930DC;


//----- (000D7439) --------------------------------------------------------
void sub_D7439()
{
  int v0; // ecx
  int v1; // edi
  int v2; // esi
  int v3; // ebx
  _BYTE *v4; // eax
  int v5; // esi
  unsigned int v6; // esi
  int v7; // ecx
  int v8; // ecx
  int v9; // ebx
  int16_t v10; // [esp+0h] [ebp-Ch] BYREF
  char v11; // [esp+4h] [ebp-8h]
  char v12; // [esp+8h] [ebp-4h]

  v0 = word_199998;
  v1 = 3753 * word_199998;
  while ( v0 > 0 )
  {
    v1 -= 3753;
    v2 = v1 + dword_197F98;
    --v0;
    if ( *(_BYTE *)(v1 + dword_197F98 + 40) != 100 )
    {
      v3 = *(char *)(v2 + 1441);
      if ( v3 != -1 )
      {
        v12 = 0;
        v4 = (_BYTE *)(dword_1930DC + 59 * v3);
        v11 = 0;
        if ( (v4[39] & 2) != 0
          || (v4[39] & 1) != 0
          || (v4[39] & 0x20) != 0 && !*(_BYTE *)(v2 + 1437)
          || (v4[39] & 0x10) != 0 && !*(_BYTE *)(v1 + dword_197F98 + 1437)
          || (char)v4[39] < 0
          || (v4[39] & 0x40) != 0
          || (v4[40] & 2) != 0
          || (v4[40] & 1) != 0
          || (v4[38] & 2) != 0
          || (v4[38] & 1) != 0
          || (char)v4[38] < 0
          || (v4[38] & 0x40) != 0
          || (v4[39] & 8) != 0
          || (v4[39] & 4) != 0
          || (v4[40] & 8) != 0 && !*(_BYTE *)(v1 + dword_197F98 + 2226)
          || (v4[40] & 4) != 0 && !*(_BYTE *)(v1 + dword_197F98 + 2226)
          || !v4[35] && ((char)v4[43] < 0 || (v4[43] & 0x40) != 0 || (char)v4[42] < 0 || (v4[42] & 0x40) != 0) )
        {
          v12 = 1;
        }
        if ( v12 )
        {
          v5 = (int16_t)sub_97A29(v0, v3);
          if ( v5 + 50 < *(_DWORD *)(v1 + dword_197F98 + 50) )
          {
            v11 = 1;
            *(_DWORD *)(v1 + dword_197F98 + 50) -= v5;
          }
        }
        sub_9718F(v3, v0, v11, v1);
      }
      *(_BYTE *)(v1 + dword_197F98 + 1441) = -1;
    }
  }
  v6 = 113 * word_19999A + dword_19306C;
  while ( v6 > dword_19306C )
  {
    v6 -= 113;
    if ( *(char *)(v6 + 40) >= 80 && *(char *)(v6 + 40) < 90 )
    {
      v7 = *(char *)(v6 + 40) - 80;
      if ( *(_BYTE *)(dword_197F98 + 3753 * v7 + 40) != 100 )
        sub_97F8D(&v10, v7, v1);
    }
  }
  v8 = word_199998;
  v9 = 3753 * word_199998;
  while ( v8 > 0 )
  {
    v9 -= 3753;
    --v8;
    if ( *(_BYTE *)(v9 + dword_197F98 + 40) != 100 )
      sub_D73D4(v8);
  }
}
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (000D7662) --------------------------------------------------------
int __fastcall sub_D7662(int a1, int a2)
{
  return *(_DWORD *)(a1 + 2) - *(_DWORD *)(a2 + 2);
}


//----- (000D7669) --------------------------------------------------------
_BOOL1 __fastcall sub_D7669( int a1, int a2)
{
  char v2; // bl
  _BYTE *v3; // eax
  uint8_t v4; // al

  v2 = 0;
  if ( a1 != a2 )
  {
    v3 = (_BYTE *)(3753 * a1 + dword_197F98 + a2);
    if ( !v3[2062] && !v3[1583] && !v3[1591] )
    {
      v4 = v3[1575];
      if ( v4 >= 4u )
        return v4 <= 6u;
    }
  }
  return v2;
}
// 197F98: using guessed type int dword_197F98;


//----- (000D76B8) --------------------------------------------------------
int __fastcall sub_D76B8(int a1, int16_t *a2)
{
  int result; // eax
  int v5; // esi
  int16_t *v6; // esi
  int v7; // eax
  int v8; // edx

  result = 17 * word_1999A2;
  v5 = dword_1930D4;
  *a2 = 0;
  v6 = (int16_t *)(result + v5);
  while ( (unsigned int)v6 > dword_1930D4 )
  {
    v6 = (int16_t *)((char *)v6 - 17);
    result = *v6;
    if ( result == -1 && *((_BYTE *)v6 + 4) == 3 )
    {
      result = 1 << word_1AA24C;
      if ( ((1 << word_1AA24C) & *(uint8_t *)(*((uint8_t *)v6 + 2) + dword_1AA200)) != 0 )
      {
        v7 = ((int)v6 - dword_1930D4) / 17;
        *(_WORD *)(6 * *a2 + a1) = v7;
        v8 = *((uint16_t *)off_183558 + 360 * word_1AA24C + v7);
        result = 6 * *a2;
        *(_DWORD *)(a1 + result + 2) = v8;
        ++*a2;
      }
    }
  }
  return result;
}
// 183558: using guessed type _UNKNOWN *off_183558;
// 1930D4: using guessed type int dword_1930D4;
// 1999A2: using guessed type int16_t word_1999A2;
// 1AA200: using guessed type int dword_1AA200;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D7764) --------------------------------------------------------
void __fastcall sub_D7764(int a1, int16_t *a2)
{
  unsigned int v3; // esi
  int16_t v4; // ax
  int16_t *v5; // eax
  char *v6; // esi
  int16_t *v7; // eax
  int16_t v8; // [esp+8h] [ebp-14h]
  int16_t v9; // [esp+Ch] [ebp-10h]
  int16_t v10; // [esp+10h] [ebp-Ch]
  char v11; // [esp+18h] [ebp-4h]

  if ( *(_BYTE *)(dword_1AA248 + 370) != 3 )
  {
    v3 = dword_197F9C + 129 * word_199994;
LABEL_11:
    while ( v3 > dword_197F9C )
    {
      v4 = *(char *)(v3 - 30);
      v3 -= 129;
      if ( v4 == word_1AA24C && *(_BYTE *)(v3 + 17) == 1 && *(_BYTE *)(v3 + 100) == 1 && !sub_FF6BE(v3) )
      {
        v8 = *a2;
        do
        {
          if ( v8 <= 0 )
            goto LABEL_11;
          v5 = (int16_t *)(a1 + 6 * --v8);
        }
        while ( *(uint8_t *)(dword_1930D4 + 17 * *v5 + 2) != *(_WORD *)(v3 + 101) - 500 );
        memmove(v5, a1 + 6 * (v8 + 1), 6 * (--*a2 - v8));
      }
    }
  }
  if ( *(_BYTE *)(dword_197F98 + 3753 * word_1AA24C + 40) != 100 )
  {
    v6 = (char *)(361 * word_199996 + dword_192B18);
    while ( (unsigned int)v6 > dword_192B18 )
    {
      v6 -= 361;
      if ( *v6 == word_1AA24C && *(_WORD *)(v6 + 277) == 11 )
      {
        v10 = *(uint8_t *)(17 * *((int16_t *)v6 + 1) + dword_1930D4 + 2);
        v11 = 0;
        v9 = *a2;
        while ( v9 > 0 && !v11 )
        {
          v7 = (int16_t *)(a1 + 6 * --v9);
          if ( *(uint8_t *)(dword_1930D4 + 17 * *v7 + 2) == v10 )
          {
            --*a2;
            v11 = 1;
            memmove(v7, a1 + 6 * (v9 + 1), 6 * (*a2 - v9));
          }
        }
        if ( !v11 )
          *(_WORD *)(v6 + 277) = -2;
      }
    }
  }
  JUMPOUT(0xD775E);
}
// D791E: control flows out of bounds to D775E
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 1AA248: using guessed type int dword_1AA248;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D7923) --------------------------------------------------------
int __fastcall sub_D7923(int16_t *a1, int a2, _WORD *a3, int16_t *a4)
{
  int v6; // edx
  int v7; // eax
  int result; // eax
  int v9; // eax
  int v10; // eax
  int16_t v11; // bx
  int v12; // edx
  int v13; // eax
  int16_t *v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // eax
  int v18; // edx
  char v19[4]; // [esp+0h] [ebp-40h] BYREF
  uint8_t v20; // [esp+4h] [ebp-3Ch]
  uint8_t v21; // [esp+5h] [ebp-3Bh]
  char *v22; // [esp+10h] [ebp-30h]
  int v23; // [esp+14h] [ebp-2Ch]
  int v24; // [esp+18h] [ebp-28h]
  int v25; // [esp+1Ch] [ebp-24h]
  int v26; // [esp+20h] [ebp-20h]
  int v27; // [esp+24h] [ebp-1Ch]
  int v28; // [esp+28h] [ebp-18h]
  int v29; // [esp+2Ch] [ebp-14h]
  int v30; // [esp+30h] [ebp-10h]
  int v31; // [esp+34h] [ebp-Ch]
  int v32; // [esp+38h] [ebp-8h]
  int v33; // [esp+3Ch] [ebp-4h]

  v30 = a2;
  HIWORD(v6) = HIWORD(dword_197F9C);
  v7 = dword_197F9C + 129 * *a1;
  LOWORD(v6) = *(_WORD *)(v7 + 101);
  v29 = v6;
  LOWORD(v6) = *(_WORD *)(v7 + 103);
  v27 = v6;
  LOWORD(v7) = *(_WORD *)(v7 + 105);
  LOWORD(v6) = v30;
  v25 = v7;
  *a3 = -1;
  *a4 = 0x7FFF;
  sub_FF799(a1, v6, v19);
  if ( v21 )
  {
    *a4 = v20;
    result = v30;
LABEL_22:
    *a3 = result;
    return result;
  }
  v26 = 0x7FFF;
  v32 = -1;
  v22 = (char *)(361 * word_199996 + dword_192B18);
  while ( dword_192B18 < (unsigned int)v22 )
  {
    v22 -= 361;
    if ( *v22 == word_1AA24C )
    {
      v9 = 17 * *((int16_t *)v22 + 1);
      LOWORD(v9) = *(uint8_t *)(dword_1930D4 + v9 + 2);
      v31 = v9;
      if ( (_WORD)v9 != (_WORD)v29 && (_WORD)v9 != (_WORD)v30 )
      {
        sub_FF799(a1, v9, v19);
        if ( v21 )
        {
          if ( v21 < (int16_t)v26 )
          {
            LOWORD(v10) = v20;
            v28 = 0;
            v33 = v10;
            while ( 1 )
            {
              v14 = &a1[(int16_t)v28];
              v15 = *v14;
              if ( v15 == -1 )
                break;
              v23 = dword_197F9C;
              v11 = v31;
              *(_WORD *)(dword_197F9C + 129 * v15 + 101) = v31;
              v12 = 129 * *v14;
              v24 = 113 * v11 + dword_19306C;
              *(_WORD *)(v12 + v23 + 103) = *(_WORD *)(v24 + 15);
              v13 = 129 * *v14;
              ++v28;
              *(_WORD *)(v23 + v13 + 105) = *(_WORD *)(v24 + 17);
            }
            sub_FF799(a1, v30, v19);
            while ( (int16_t)v28 > 0 )
            {
              v17 = (int16_t)--v28;
              v18 = dword_197F9C + 129 * a1[(int16_t)v28];
              v24 = dword_197F9C;
              *(_WORD *)(v18 + 101) = v29;
              *(_WORD *)(v24 + 129 * a1[v17] + 103) = v27;
              v16 = v24 + 129 * a1[v17];
              *(_WORD *)(v16 + 105) = v25;
            }
            if ( v21 )
            {
              LOWORD(v16) = v20;
              v33 += v16;
              if ( (int16_t)v33 < (int16_t)v26 )
              {
                v26 = v33;
                v32 = v31;
              }
            }
          }
        }
      }
    }
  }
  result = (int16_t)v32;
  if ( (int16_t)v32 != -1 )
  {
    result = v26;
    if ( (int16_t)v26 < *a4 )
    {
      *a4 = v26;
      result = v32;
      goto LABEL_22;
    }
  }
  return result;
}
// D7A29: variable 'v10' is possibly undefined
// D7B07: variable 'v16' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;
// 199996: using guessed type int16_t word_199996;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D7B48) --------------------------------------------------------
int16_t __usercall sub_D7B48(_WORD *a1, int a2, int a3)
{
  int16_t result; // ax
  int16_t *v4; // ecx
  int16_t v5; // di
  int v6; // [esp+0h] [ebp-30h]
  _BYTE v7[16]; // [esp+4h] [ebp-2Ch] BYREF
  int16_t v8[2]; // [esp+14h] [ebp-1Ch] BYREF
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  int v11; // [esp+20h] [ebp-10h] BYREF
  int v12; // [esp+24h] [ebp-Ch] BYREF
  int v13; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h]

  v13 = a2;
  v10 = 0x7FFF;
  v14 = -1;
  v8[1] = -1;
  v9 = -1;
  LOWORD(a3) = *a1;
  while ( (int16_t)a3 > 0 )
  {
    v8[0] = *(_WORD *)(v6 + 2 * (int16_t)--a3);
    sub_D7923(v8, (int16_t)v13, &v11, (int16_t *)&v12);
    if ( (int16_t)v11 != -1 && (int16_t)v12 < (int16_t)v10 )
    {
      v10 = v12;
      v14 = a3;
      v9 = v11;
    }
  }
  result = v14;
  if ( (int16_t)v14 != -1 )
  {
    v4 = (int16_t *)(2 * (int16_t)v14 + v6);
    v5 = v9;
    v8[0] = *v4;
    sub_FF799(v8, v9, v7);
    sub_FFD08(v8, v5, v7);
    result = *(_WORD *)(v6 + 2 * (int16_t)--*a1);
    *v4 = result;
  }
  return result;
}
// D7B7B: variable 'v6' is possibly undefined


//----- (000D7C04) --------------------------------------------------------
_DWORD *__fastcall sub_D7C04( int a1, _DWORD *a2, _DWORD *a3)
{
  unsigned int v4; // ebx
  int16_t v5; // ax
  int16_t v6; // ax
  int v7; // esi
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // ebx
  int v11; // esi
  _DWORD *result; // eax
  int16_t v13; // [esp+0h] [ebp-10h]
  char v14; // [esp+Ch] [ebp-4h]

  v14 = *(_BYTE *)(113 * a1 + dword_19306C + 111);
  memset(a2, 0, 40);
  v4 = 129 * word_199994 + dword_197F9C;
  while ( v4 > dword_197F9C )
  {
    v5 = *(char *)(v4 - 30);
    v4 -= 129;
    if ( v5 != word_1AA24C && *(char *)(v4 + 100) < 3 )
    {
      v6 = *(_WORD *)(v4 + 101);
      if ( v6 == v13 )
      {
        if ( v14 )
          v7 = dword_1AA1F4;
        else
          v7 = dword_1AA1DC;
        *a2 += *(uint16_t *)(16 * ((int)(v4 - dword_197F9C) / 129) + v7 + 2 * word_1AA24C);
      }
      else if ( (v6 == v13 + 500 || v6 == v13 + 1000) && *(_BYTE *)(v4 + 109) < 0xAu )
      {
        if ( v14 )
          v9 = dword_1AA1F4;
        else
          v9 = dword_1AA1DC;
        v8 = &a2[*(uint8_t *)(v4 + 109)];
        *v8 += *(uint16_t *)(16 * ((int)(v4 - dword_197F9C) / 129) + v9 + 2 * word_1AA24C);
      }
    }
  }
  v10 = 1;
  *a3 = *a2;
  do
  {
    v11 = (int16_t)v10;
    result = &a3[v11];
    ++v10;
    a3[v11] = a2[v11] + a3[v11 - 1];
  }
  while ( (int16_t)v10 < 10 );
  return result;
}
// D7C72: variable 'v13' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 1AA1DC: using guessed type int dword_1AA1DC;
// 1AA1F4: using guessed type int dword_1AA1F4;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D7D53) --------------------------------------------------------
void __fastcall sub_D7D53( int a1, int a2)
{
  int v3; // eax
  unsigned int v4; // ebx
  int v5; // edx
  int v6; // ecx
  unsigned int v7; // ecx
  int v8; // ecx
  unsigned int v9; // ecx
  int v10; // [esp+Ch] [ebp-1Ch]
  unsigned int v11; // [esp+10h] [ebp-18h]
  int v12; // [esp+14h] [ebp-14h]
  int v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+1Ch] [ebp-Ch]
  char v16; // [esp+24h] [ebp-4h]

  v16 = *(_BYTE *)(dword_19306C + 113 * a2 + 111);
  v3 = word_199998;
  v4 = -1;
  v12 = 0;
  v11 = -1;
  v5 = 0;
  v13 = 3753 * word_199998;
  v10 = 0;
  v14 = 2 * word_199998;
  while ( v3 > 0 )
  {
    v13 -= 3753;
    --v3;
    v14 -= 2;
    if ( v3 != word_1AA24C )
    {
      if ( (((int)*(uint8_t *)(a2 + dword_1AA200) >> v3) & 1) != 0
        && ((((int)*(uint8_t *)(a2 + dword_1AA214) >> v3) & 1) != 0 || *(_BYTE *)(v13 + dword_197F98 + 40) == 100) )
      {
        v6 = v16 ? dword_1AA1F4 : dword_1AA1DC;
        ++v5;
        v7 = *(uint16_t *)(v14 + 16 * a1 + v6);
        v12 += v7;
        if ( v7 < v4 )
          v4 = v7;
      }
      if ( *(_BYTE *)(dword_1AA204 + 58 * word_1AA24C + v3 + 14) )
      {
        v8 = v16 ? dword_1AA1F4 : dword_1AA1DC;
        v9 = *(uint16_t *)(v14 + 16 * a1 + v8);
        v10 += v9;
        if ( v9 < v11 )
          v11 = v9;
      }
    }
  }
  if ( *(_BYTE *)(a2 + dword_1AA23C) )
  {
    if ( v16 )
      sub_5EF09(a1, *(uint8_t *)(a2 + dword_1AA23C));
    else
      sub_5EF17(a1, *(uint8_t *)(a2 + dword_1AA23C));
  }
  JUMPOUT(0xD775E);
}
// D7F2F: control flows out of bounds to D775E
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199998: using guessed type int16_t word_199998;
// 1AA1DC: using guessed type int dword_1AA1DC;
// 1AA1F4: using guessed type int dword_1AA1F4;
// 1AA200: using guessed type int dword_1AA200;
// 1AA204: using guessed type int dword_1AA204;
// 1AA214: using guessed type int dword_1AA214;
// 1AA23C: using guessed type int dword_1AA23C;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D7F34) --------------------------------------------------------
int __fastcall sub_D7F34(int a1, unsigned int a2, int a3)
{
  int16_t v3; // di
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  int v7; // edx
  int v8; // edx
  int i; // ebx
  uint16_t v10; // ax
  int v12; // [esp+0h] [ebp-10h]
  char v14; // [esp+Ch] [ebp-4h]

  v3 = a1;
  v4 = 0x7FFF;
  v14 = *(_BYTE *)(dword_19306C + 113 * a3 + 111);
  if ( (_BYTE)a2 )
  {
    v5 = word_199998;
    v12 = 16 * a1;
    v6 = 2 * word_199998;
    while ( v5 > 0 )
    {
      --v5;
      v6 -= 2;
      if ( (((int)a2 >> v5) & 1) != 0 )
      {
        v7 = v14 ? dword_1AA1F4 : dword_1AA1DC;
        v8 = *(uint16_t *)(v12 + v7 + v6);
        if ( v8 < (int16_t)v4 )
          v4 = v8;
      }
    }
  }
  if ( HIBYTE(a2) )
  {
    for ( i = 8; i < 15; ++i )
    {
      if ( (((int)a2 >> i) & 1) != 0 )
      {
        if ( v14 )
          v10 = ((int (__fastcall *)(_DWORD, _DWORD))sub_5EF09)(v3, (int16_t)i);
        else
          v10 = ((int (__fastcall *)(_DWORD, _DWORD))sub_5EF17)(v3, (int16_t)i);
        if ( v10 < (int16_t)v4 )
          v4 = v10;
      }
    }
  }
  return v4;
}
// 19306C: using guessed type int dword_19306C;
// 199998: using guessed type int16_t word_199998;
// 1AA1DC: using guessed type int dword_1AA1DC;
// 1AA1F4: using guessed type int dword_1AA1F4;


//----- (000D7FF7) --------------------------------------------------------
char __fastcall sub_D7FF7(int a1, int16_t *a2, int a3, int a4)
{
  int v6; // ebx
  uint8_t v7; // al
  int i; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // ecx
  _BOOL1 v12; // al
  int16_t v13; // bx
  int v14; // eax
  int16_t v15; // ax
  int v16; // ebx
  int16_t v17; // ax
  unsigned int v18; // edx
  int v19; // edx
  int v20; // eax
  _BOOL1 v21; // bl
  int16_t v22; // ax
  int v23; // ecx
  unsigned int v24; // ebx
  int16_t v25; // ax
  int v26; // eax
  int16_t v27; // ax
  int v28; // eax
  int v29; // ebx
  int16_t v30; // bx
  int v31; // eax
  int16_t v32; // ax
  char v33; // bl
  int16_t v34; // ax
  int v35; // edi
  unsigned int v36; // ebx
  int16_t v37; // ax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // edx
  int v42; // ebx
  _WORD *v43; // ecx
  int v44; // eax
  _WORD *v45; // eax
  int16_t v46; // cx
  int16_t v47; // dx
  int v49; // [esp+0h] [ebp-48Eh]
  int16_t v50[502]; // [esp+4h] [ebp-48Ah] BYREF
  _DWORD v51[10]; // [esp+3F0h] [ebp-9Eh] BYREF
  _DWORD v52[10]; // [esp+418h] [ebp-76h] BYREF
  _DWORD v53[10]; // [esp+440h] [ebp-4Eh] BYREF
  _BYTE v54[16]; // [esp+468h] [ebp-26h] BYREF
  int v55; // [esp+478h] [ebp-16h]
  int v56; // [esp+47Ch] [ebp-12h]
  unsigned int v57; // [esp+480h] [ebp-Eh]
  int v58; // [esp+484h] [ebp-Ah]
  int v59; // [esp+488h] [ebp-6h]
  int v60; // [esp+48Ch] [ebp-2h]
  int v61; // [esp+490h] [ebp+2h]
  int v62; // [esp+494h] [ebp+6h]
  int v63; // [esp+498h] [ebp+Ah]
  int v64; // [esp+49Ch] [ebp+Eh]
  int v65; // [esp+4A0h] [ebp+12h]
  unsigned int v66; // [esp+4A4h] [ebp+16h]
  int v67; // [esp+4A8h] [ebp+1Ah]
  int v68; // [esp+4ACh] [ebp+1Eh]
  int v69; // [esp+4B0h] [ebp+22h]
  int v70; // [esp+4B4h] [ebp+26h]
  int16_t *v71; // [esp+4B8h] [ebp+2Ah]
  int v72; // [esp+4BCh] [ebp+2Eh]
  int v73; // [esp+4C0h] [ebp+32h]
  int v74; // [esp+4C4h] [ebp+36h]
  int v75; // [esp+4C8h] [ebp+3Ah]
  int v76; // [esp+4CCh] [ebp+3Eh]
  unsigned int v77; // [esp+4D0h] [ebp+42h]
  int16_t v78; // [esp+4D4h] [ebp+46h] BYREF
  int v79; // [esp+4D8h] [ebp+4Ah]
  int v80; // [esp+4DCh] [ebp+4Eh]
  int v81; // [esp+4E0h] [ebp+52h]
  int v82; // [esp+4E4h] [ebp+56h]
  int v83; // [esp+4E8h] [ebp+5Ah] BYREF
  int v84; // [esp+4ECh] [ebp+5Eh]
  int v85; // [esp+4F0h] [ebp+62h] BYREF
  int16_t v86; // [esp+4F4h] [ebp+66h] BYREF
  char v87; // [esp+4F8h] [ebp+6Ah]
  char v88; // [esp+4FCh] [ebp+6Eh]
  _BOOL1 v89; // [esp+500h] [ebp+72h]
  char v90; // [esp+504h] [ebp+76h]
  char v91; // [esp+508h] [ebp+7Ah]
  char v92; // [esp+50Ch] [ebp+7Eh]

  v76 = a4;
  memset(v51, 0, sizeof(v51));
  sub_D7C04(a3, v53, v52);
  v6 = word_199998;
  v63 = 2560 * a3;
  v70 = 3753 * word_199998;
  v87 = 0;
  v65 = 0x7FFF;
  v64 = -1;
  v92 = -1;
  v75 = -1;
  v58 = -1;
  v72 = -1;
  v62 = 320 * word_199998;
  while ( v6 > 0 )
  {
    v70 -= 3753;
    --v6;
    v62 -= 320;
    if ( v6 != word_1AA24C )
    {
      v7 = *(_BYTE *)(v6 + dword_1AA248 + 1575);
      if ( !v7 || v7 > 3u || *(_BYTE *)(v70 + dword_197F98 + 40) == 100 )
      {
        v55 = v62;
        for ( i = 10; i > 0; v51[i] += *(_DWORD *)(v63 + dword_1AA208 + v55 + 40 * word_1AA24C + i * 4) )
          --i;
      }
    }
  }
  v67 = *a2;
  v71 = (int16_t *)(v49 + 2 * v67);
  while ( v67 > 0 )
  {
    --v71;
    HIWORD(v9) = HIWORD(v71);
    LOWORD(v9) = *v71;
    v10 = 129 * *v71;
    --v67;
    v69 = 0;
    v11 = dword_197F9C + v10;
    v50[0] = v9;
    v73 = 1;
    if ( *(int16_t *)(v11 + 101) >= 72 )
    {
      v77 = 0;
      v23 = 1;
      v24 = 129 * word_199994 + dword_197F9C;
      while ( v24 > dword_197F9C )
      {
        v25 = *(char *)(v24 - 30);
        v24 -= 129;
        if ( v25 == word_1AA24C )
        {
          v61 = dword_197F9C;
          v26 = dword_197F9C + 129 * v50[0];
          if ( *(_WORD *)(v24 + 101) == *(_WORD *)(v26 + 101)
            && *(char *)(v24 + 100) < 3
            && *(_WORD *)(v24 + 103) == *(_WORD *)(v26 + 103)
            && *(_WORD *)(v24 + 105) == *(_WORD *)(v26 + 105) )
          {
            v59 = (int16_t)a3;
            v74 = 129;
            sub_D7D53((int)(v24 - v61) / 129, a3);
            v77 += v27;
            v74 = 129;
            ++v23;
            ++v73;
            v50[v23 - 1] = (int)(v24 - dword_197F9C) / 129;
          }
        }
      }
      v50[v23] = -1;
      v28 = dword_197F9C + 129 * v50[0];
      if ( *(int16_t *)(v28 + 101) - 500 == a3 )
      {
        if ( *(_BYTE *)(v28 + 109) < 0xAu )
        {
          v29 = *(uint8_t *)(v28 + 109);
          if ( v29 <= v76 && v29 < v65 && v52[v29] < v77 )
          {
            v90 = 1;
            v30 = *(uint8_t *)(v28 + 109);
LABEL_65:
            ++v30;
            while ( v30 < 10 && v90 )
            {
              if ( v77 > v53[v30] )
                goto LABEL_65;
              v90 = 0;
            }
            if ( v90 )
            {
              v65 = *(uint8_t *)(v28 + 109);
              v64 = v67;
              v92 = 0;
              v31 = v73 - 1;
              v75 = a3;
              goto LABEL_85;
            }
          }
        }
      }
      else
      {
        sub_D7923(v50, (int16_t)a3, &v78, (int16_t *)&v83);
        if ( v78 != -1 && (int16_t)v83 < 10 && (int16_t)v83 <= v76 && (int16_t)v83 < v65 && v52[(int16_t)v83] < v77 )
        {
          v32 = v83;
          v33 = 1;
LABEL_78:
          ++v32;
          while ( v32 < 10 && v33 )
          {
            if ( v77 > v53[v32] )
              goto LABEL_78;
            v33 = 0;
          }
          if ( v33 )
          {
            v65 = (int16_t)v83;
            v64 = v67;
            v75 = v78;
            v31 = v73 - 1;
            v92 = 1;
LABEL_85:
            v58 = v31;
            v72 = v31;
          }
        }
      }
    }
    else
    {
      LOWORD(v9) = *(_WORD *)(v11 + 101);
      v82 = v9;
      v9 = (int16_t)v9;
      LOWORD(v9) = *(_WORD *)(146 * word_1AA24C + dword_1AA1C8 + 2 * (int16_t)v9);
      v79 = v9;
      if ( (int16_t)v9 != -1 )
      {
        v57 = 0;
        v56 = 0;
        v12 = v76 < 10 || v52[9];
        v88 = 0;
        v13 = v79;
        v89 = v12;
        while ( !v88 )
        {
          if ( v13 < word_1AA218
            && (v14 = dword_197F9C + 129 * *(int16_t *)(dword_1AA1D4 + 2 * v13),
                v60 = dword_197F9C,
                *(char *)(v14 + 99) == word_1AA24C)
            && *(_WORD *)(v14 + 101) == (_WORD)v82 )
          {
            v74 = 129;
            ++v69;
            sub_D7D53((v14 - v60) / 129, a3);
            ++v13;
            v56 += v15;
          }
          else
          {
            v88 = 1;
          }
        }
        v81 = v79;
        v66 = 2 * v73;
        v91 = 0;
        v68 = v73 - 1;
        while ( !v91 )
        {
          if ( word_1AA218 > (int16_t)v81 )
          {
            v16 = dword_197F9C + 129 * *(int16_t *)(2 * (int16_t)v81 + dword_1AA1D4);
            if ( *(char *)(v16 + 99) == word_1AA24C && *(_WORD *)(v16 + 101) == (_WORD)v82 )
            {
              v59 = (int16_t)a3;
              sub_D7D53((v16 - dword_197F9C) / 129, a3);
              v57 += v17;
              ++v81;
              v18 = v66;
              v66 += 2;
              *(int16_t *)((char *)v50 + v18) = (v16 - dword_197F9C) / 129;
              v19 = v59;
              v50[v66 / 2] = -1;
              ++v68;
              sub_D7923(v50, v19, &v86, (int16_t *)&v85);
              ++v73;
              if ( v86 != -1 && (int16_t)v85 <= v76 )
              {
                if ( !v89 && (int)(2 * v57) < v56 )
                  continue;
                if ( (int16_t)v85 >= 10 || (int16_t)v85 >= v65 )
                {
                  v91 = 1;
                }
                else
                {
                  v20 = (int16_t)v85 + 2;
                  if ( v20 >= 10 )
                    v20 = 9;
                  if ( v52[v20] < v57 )
                  {
                    v21 = 1;
                    v22 = v85 + 1;
                    if ( v57 < v51[(int16_t)v85] )
                      v21 = (int)v57 >= v56;
                    while ( v22 < 10 && v21 )
                    {
                      if ( v57 >= v53[v22] )
                        ++v22;
                      else
                        v21 = 0;
                    }
                    if ( v21 )
                    {
                      v65 = (int16_t)v85;
                      v64 = v67;
                      v75 = v86;
                      v58 = v68;
                      v92 = 2;
                      v72 = v69;
                    }
                  }
                }
                if ( v89 || (int)(2 * v57) < v56 )
                  continue;
              }
            }
          }
          v91 = 1;
        }
      }
    }
  }
  if ( v64 != -1 )
  {
    v34 = *(_WORD *)(v49 + 2 * v64);
    v50[0] = v34;
    if ( v92 )
    {
      if ( (uint8_t)v92 <= 1u )
      {
        v35 = 1;
        v36 = 129 * word_199994 + dword_197F9C;
        while ( v36 > dword_197F9C )
        {
          v37 = *(char *)(v36 - 30);
          v36 -= 129;
          if ( v37 == word_1AA24C )
          {
            v38 = dword_197F9C + 129 * v50[0];
            if ( *(_WORD *)(v36 + 101) == *(_WORD *)(v38 + 101)
              && *(char *)(v36 + 100) < 3
              && *(_WORD *)(v36 + 103) == *(_WORD *)(v38 + 103)
              && *(_WORD *)(v36 + 105) == *(_WORD *)(v38 + 105) )
            {
              v39 = (int)(v36 - dword_197F9C) / 129;
              ++v35;
              *(_BYTE *)(v36 + 127) = 4;
              v50[v35 - 1] = v39;
            }
          }
        }
        v50[v35] = -1;
      }
      else if ( v92 == 2 )
      {
        v40 = 129 * v34;
        LOWORD(v40) = *(_WORD *)(dword_197F9C + v40 + 101);
        v84 = v40;
        v41 = (int16_t)v40;
        v42 = 0;
        v43 = (_WORD *)(2 * *(int16_t *)(dword_1AA1C8 + 146 * word_1AA24C + 2 * (int16_t)v40) + dword_1AA1D4);
        v44 = 1;
        while ( v42 < v58 )
        {
          LOWORD(v41) = *v43;
          v80 = v41;
          ++v44;
          ++v42;
          *(_BYTE *)(129 * (int16_t)v41 + dword_197F9C + 127) = 4;
          HIWORD(v41) = HIWORD(v80);
          ++v43;
          v50[v44 - 1] = v80;
        }
        v50[v44] = -1;
        if ( v58 >= v72 )
        {
          *(_WORD *)(146 * word_1AA24C + dword_1AA1C8 + 2 * (int16_t)v84) = -1;
        }
        else
        {
          v45 = (_WORD *)(146 * word_1AA24C + dword_1AA1C8 + 2 * (int16_t)v84);
          *v45 += v58;
        }
      }
    }
    if ( v92 )
    {
      v46 = v75;
      sub_FF799(v50, v75, v54);
      sub_FFD08(v50, v46, v54);
    }
    v47 = *(_WORD *)(2 * --*a2 + v49);
    v87 = 1;
    *(_WORD *)(v49 + 2 * v64) = v47;
  }
  return v87;
}
// D8208: variable 'v15' is possibly undefined
// D8295: variable 'v17' is possibly undefined
// D8454: variable 'v27' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199998: using guessed type int16_t word_199998;
// 1AA1C8: using guessed type int dword_1AA1C8;
// 1AA1D4: using guessed type int dword_1AA1D4;
// 1AA208: using guessed type int dword_1AA208;
// 1AA218: using guessed type int16_t word_1AA218;
// 1AA248: using guessed type int dword_1AA248;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D87BB) --------------------------------------------------------
int __fastcall sub_D87BB(int a1, int a2, int a3)
{
  int v5; // ebx
  int v6; // edx
  int v7; // esi
  int v9; // [esp+0h] [ebp-Ch]
  int16_t v10; // [esp+4h] [ebp-8h]
  int16_t v11; // [esp+8h] [ebp-4h]

  v5 = -1;
  v11 = 0x7FFF;
  while ( (int16_t)a2 > 0 )
  {
    v10 = *(_WORD *)(v9 + 2 * (int16_t)--a2);
    v6 = 129 * v10 + dword_197F9C;
    if ( a3 == *(_WORD *)(v6 + 101) )
      return a2;
    v7 = *(int16_t *)(v6 + 101);
    if ( (a3 == v7 - 500 || v7 - 1000 == a3) && *(uint8_t *)(dword_197F9C + 129 * v10 + 109) < v11 )
    {
      v11 = *(uint8_t *)(dword_197F9C + 129 * v10 + 109);
      v5 = a2;
    }
  }
  return v5;
}
// D87DB: variable 'v9' is possibly undefined
// 197F9C: using guessed type int dword_197F9C;


//----- (000D8847) --------------------------------------------------------
void __fastcall sub_D8847(uint8_t *a1, uint8_t *a2)
{
  unsigned int v3; // esi
  int16_t v4; // ax
  unsigned int v5; // edx
  unsigned int *v6; // ebx
  unsigned int *v7; // ebx
  int v9; // [esp+8h] [ebp-4h]

  v3 = -1;
  v4 = word_199998;
  v5 = -1;
  while ( v4 > 0 )
  {
    if ( --v4 != word_1AA24C )
    {
      v9 = *a1;
      if ( (((int)*(uint8_t *)(v9 + dword_1AA214) >> v4) & 1) != 0 )
      {
        v6 = (unsigned int *)(2560 * v9 + dword_1AA208 + 320 * word_1AA24C + 40 * v4);
        if ( v3 > *v6 )
          v3 = *v6;
        v7 = (unsigned int *)(320 * word_1AA24C + 2560 * *a2 + dword_1AA208 + 40 * v4);
        if ( v5 > *v7 )
          v5 = *v7;
      }
    }
  }
  JUMPOUT(0xD775E);
}
// D8911: control flows out of bounds to D775E
// 199998: using guessed type int16_t word_199998;
// 1AA208: using guessed type int dword_1AA208;
// 1AA214: using guessed type int dword_1AA214;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D892B) --------------------------------------------------------
char __fastcall sub_D892B(int a1)
{
  unsigned int v2; // eax

  v2 = dword_197F9C + 129 * word_199994;
  do
  {
    if ( v2 <= dword_197F9C )
      return 0;
    v2 -= 129;
  }
  while ( *(char *)(v2 + 99) < 8 || *(int16_t *)(v2 + 101) != a1 || *(_BYTE *)(v2 + 100) );
  return 1;
}
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000D896F) --------------------------------------------------------
char __fastcall sub_D896F(int a1, int16_t *a2)
{
  int v3; // esi
  _BYTE *v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int16_t v10; // dx
  int16_t v11; // dx
  unsigned int v12; // ebx
  int16_t v13; // di
  int v14; // esi
  char v15; // cl
  int v16; // edx
  int16_t v17; // cx
  int16_t v18; // dx
  int v20; // [esp+0h] [ebp-42Eh]
  _WORD v21[500]; // [esp+4h] [ebp-42Ah] BYREF
  _BYTE v22[72]; // [esp+3ECh] [ebp-42h] BYREF
  _BYTE v23[72]; // [esp+434h] [ebp+6h] BYREF
  _BYTE v24[16]; // [esp+47Ch] [ebp+4Eh] BYREF
  int16_t v25[2]; // [esp+48Ch] [ebp+5Eh] BYREF
  int v26; // [esp+490h] [ebp+62h]
  int v27; // [esp+494h] [ebp+66h] BYREF
  int v28; // [esp+498h] [ebp+6Ah]
  int v29; // [esp+49Ch] [ebp+6Eh]
  int v30; // [esp+4A0h] [ebp+72h]
  int v31; // [esp+4A4h] [ebp+76h]
  int v32; // [esp+4A8h] [ebp+7Ah]
  int16_t v33; // [esp+4ACh] [ebp+7Eh]

  v27 = 0;
  v3 = (int)v22;
  v4 = (_BYTE *)(129 * word_199994 + dword_197F9C);
  while ( (unsigned int)v4 > dword_197F9C )
  {
    v4 -= 129;
    if ( v4[17] == 1 )
    {
      if ( (char)v4[99] == word_1AA24C && sub_FF6BE((int)v4) )
      {
        v5 = (int16_t)v27++;
        v21[v5] = (int)&v4[-dword_197F9C] / 129;
      }
      else if ( (char)v4[100] < 3 )
      {
        v3 -= 2;
        *(_WORD *)v3 = (int)&v4[-dword_197F9C] / 129;
      }
    }
  }
  v6 = (int)&v22[-v3] >> 1;
  v30 = v6;
  while ( *a2 > 0 && (int16_t)v27 > 0 )
  {
    HIWORD(v7) = HIWORD(dword_1930D4);
    v8 = dword_1930D4 + 17 * *(int16_t *)(v20 + 6 * (*a2 - 1));
    LOWORD(v7) = *(uint8_t *)(v8 + 2);
    v31 = v7;
    if ( (~(1 << word_1AA24C) & *(uint8_t *)(dword_1AA200 + *(uint8_t *)(v8 + 2))) != 0
      || *(_BYTE *)(dword_1AA1F8 + 49 * (int16_t)v31 + 6 * word_1AA24C + 6)
      || sub_D892B((int16_t)v31) )
    {
      v9 = sub_D87BB(v3, (int16_t)v30, v31);
      v29 = v9;
      if ( (int16_t)v9 == -1 )
        v10 = 0x7FFF;
      else
        v10 = *(uint8_t *)(dword_197F9C + 129 * *(int16_t *)(v3 + 2 * (int16_t)v9) + 109);
      LOBYTE(v6) = sub_D7FF7((int)v21, (int16_t *)&v27, (int16_t)v31, v10);
      if ( !(_BYTE)v6 )
      {
        LOBYTE(v6) = v29;
        if ( (int16_t)v29 != -1 )
        {
          v11 = *(_WORD *)v3;
          --v30;
          *(_WORD *)(v3 + 2 * (int16_t)v29) = v11;
          v3 += 2;
        }
      }
    }
    else if ( (uint8_t)byte_199CB0 >= 2u
           || byte_199CB0 && *(_BYTE *)(dword_1AA248 + 40) == 2
           || (v6 = (int)*(uint8_t *)((int16_t)v31 + dword_1AA214) >> word_1AA24C, (v6 & 1) != 0) )
    {
      LOBYTE(v6) = sub_D7B48(&v27, (int16_t)v31, (int)a2);
    }
    --*a2;
  }
  if ( (int16_t)v27 > 0 )
  {
    v25[1] = -1;
    memset(v22, 0, sizeof(v22));
    v12 = dword_19306C + 113 * word_19999A;
    v13 = 0;
    v14 = 113 * word_19999A;
    while ( v12 > dword_19306C )
    {
      v26 = *(uint8_t *)(v12 - 48);
      v14 -= 113;
      v12 -= 113;
      if ( ((v26 >> word_1AA24C) & 1) != 0 && (((int)*(uint8_t *)(v12 + 42) >> word_1AA24C) & 1) == 0 )
      {
        v33 = v14 / 113;
        if ( !v22[v33] )
        {
          v15 = v33;
          v16 = v13;
          v22[v33] = 1;
          ++v13;
          v23[v16] = v15;
        }
      }
    }
    LOBYTE(v6) = v27;
    v28 = v27;
LABEL_37:
    while ( (int16_t)v28 > 0 )
    {
      sub_FE9B5(v23, v13);
      --v28;
      v6 = qsort(v23, v13, 1);
      v17 = v13;
      while ( v17 > 0 )
      {
        LOWORD(v6) = (uint8_t)v23[--v17];
        v32 = v6;
        v18 = (uint8_t)v23[v17];
        v25[0] = v21[(int16_t)v28];
        LOBYTE(v6) = sub_FF799(v25, v18, v24);
        if ( v24[5] )
        {
          --v13;
          sub_FFD08(v25, v32, v24);
          LOBYTE(v6) = v23[v13];
          v23[v17] = v6;
          goto LABEL_37;
        }
      }
    }
  }
  return v6;
}
// D8A32: variable 'v20' is possibly undefined
// D8C33: variable 'v6' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999A: using guessed type int16_t word_19999A;
// 199CB0: using guessed type char byte_199CB0;
// 1AA1F8: using guessed type int dword_1AA1F8;
// 1AA200: using guessed type int dword_1AA200;
// 1AA214: using guessed type int dword_1AA214;
// 1AA248: using guessed type int dword_1AA248;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D8C79) --------------------------------------------------------
int __fastcall sub_D8C79( int a1)
{
  int v1; // esi
  _BYTE v3[2160]; // [esp+0h] [ebp-870h] BYREF

  word_1AA24C = a1;
  dword_1AA248 = 3753 * a1 + dword_197F98;
  dword_1AA244 = (int)v3;
  sub_D76B8((int)v3, &word_1AA24E);
  qsort(dword_1AA244, word_1AA24E, 6);
  v1 = -1;
  sub_D7764(dword_1AA244, &word_1AA24E);
  if ( word_1AA24E > 0 )
    v1 = *(int16_t *)(dword_1AA244 + 6 * (word_1AA24E - 1));
  dword_1AA244 = 0;
  return v1;
}
// 197F98: using guessed type int dword_197F98;
// 1AA244: using guessed type int dword_1AA244;
// 1AA248: using guessed type int dword_1AA248;
// 1AA24C: using guessed type int16_t word_1AA24C;
// 1AA24E: using guessed type int16_t word_1AA24E;


//----- (000D8D11) --------------------------------------------------------
void sub_D8D11()
{
  JUMPOUT(0xD775E);
}
// D8DDC: control flows out of bounds to D775E
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000D8DE1) --------------------------------------------------------
char __fastcall sub_D8DE1(int a1, int a2)
{
  uint8_t v3; // dl
  char result; // al
  uint8_t v5; // dl

  v3 = *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1575);
  result = 2;
  if ( v3 >= 4u && v3 <= 6u )
    result = 1;
  if ( result == 2 )
  {
    v5 = *(_BYTE *)(dword_197F98 + 3753 * a1 + 39);
    if ( v5 <= 3u )
    {
      result = 1;
    }
    else if ( v5 <= 5u )
    {
      result = 0;
    }
  }
  if ( result == 2 && *(_BYTE *)(3753 * a1 + dword_197F98 + 40) == 1 )
    result = 1;
  if ( result == 2 )
    return 1;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (000D8E52) --------------------------------------------------------
int __fastcall sub_D8E52(int a1, int a2, int a3)
{
  int v3; // ebx
  int v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v10; // [esp+8h] [ebp-8h]
  int v11; // [esp+Ch] [ebp-4h]

  v3 = word_19999A;
  v4 = 0;
  v10 = 3753 * a1;
  v5 = 113 * word_19999A;
  while ( v3 > 0 )
  {
    v6 = *(uint8_t *)(dword_19306C + v5 - 57);
    v5 -= 113;
    --v3;
    if ( ((v6 >> a2) & 1) != 0 )
    {
      v11 = *(int16_t *)(v10 + dword_197F98 + 804);
      sub_EBEB7(v3, a3);
      if ( v7 <= v11 && !(uint16_t)sub_1276F0(v5 + dword_19306C + 31, a3) )
        ++v4;
    }
  }
  return v4;
}
// D8EAE: variable 'v7' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;


//----- (000D8ED2) --------------------------------------------------------
int __fastcall sub_D8ED2( int a1, int a2, int a3, _BYTE *a4, _BYTE *a5, _WORD *a6, int a7)
{
  char *v7; // edi
  int v8; // ecx
  unsigned int v9; // esi
  unsigned int v10; // ebx
  char v11; // al
  int v12; // ecx
  int v13; // eax
  char *v14; // ecx
  int16_t v15; // ax
  int v16; // edx
  unsigned int v17; // ecx
  int v18; // ecx
  signed int v19; // edx
  uint16_t v20; // ax
  int v21; // eax
  int v22; // ebx
  uint16_t v23; // ax
  int v24; // eax
  int v25; // ecx
  unsigned int v26; // edi
  unsigned int v27; // ecx
  int v29; // eax
  int v30; // eax
  int v31; // edx
  int v33; // eax
  int v38; // [esp+14h] [ebp-54h]
  int v39; // [esp+18h] [ebp-50h]
  char *v40; // [esp+1Ch] [ebp-4Ch]
  int v41; // [esp+24h] [ebp-44h]
  int v42; // [esp+28h] [ebp-40h]
  int v43; // [esp+2Ch] [ebp-3Ch]
  int v44; // [esp+30h] [ebp-38h]
  int v45; // [esp+34h] [ebp-34h]
  int v46; // [esp+38h] [ebp-30h]
  int v47; // [esp+38h] [ebp-30h]
  unsigned int v48; // [esp+40h] [ebp-28h]
  unsigned int v49; // [esp+44h] [ebp-24h]
  int16_t v50; // [esp+48h] [ebp-20h]
  int16_t v51; // [esp+4Ch] [ebp-1Ch]
  int16_t v52; // [esp+50h] [ebp-18h]
  int16_t v53; // [esp+54h] [ebp-14h]
  int16_t v54; // [esp+58h] [ebp-10h]
  char v55; // [esp+5Ch] [ebp-Ch]
  uint8_t v56; // [esp+60h] [ebp-8h]
  char v57; // [esp+64h] [ebp-4h]

  v7 = (char *)(361 * a1 + dword_192B18);
  v52 = *v7;
  v53 = *((_WORD *)v7 + 1);
  v8 = 17 * v53 + dword_1930D4;
  v54 = *(uint8_t *)(v8 + 2);
  v49 = 0;
  v57 = 1;
  v9 = 0;
  v10 = 0;
  v55 = *(_BYTE *)(dword_19306C + 113 * *(uint8_t *)(v8 + 2) + 111);
  v48 = 0;
  v11 = sub_D8DE1(word_1AA24C, *v7);
  v12 = (uint8_t)v7[10];
  v56 = v11;
  if ( v12 < a7 && !v7[6] && *(_BYTE *)(dword_1AA248 + 39) != 1 )
  {
    v13 = (uint8_t)v7[10];
    v14 = &v7[4 * v12];
    while ( v13 > 0 )
    {
      v38 = *((_DWORD *)v14 + 2) & 0xF;
      v14 -= 4;
      --v13;
      if ( v38 == word_1AA24C )
        v57 = 0;
    }
  }
  if ( v57 )
  {
    v51 = 0;
    v50 = sub_E5AE7(v7);
    while ( 1 )
    {
      v15 = *(_WORD *)(a2 + 2 * v51);
      if ( v15 == -1 )
        break;
      if ( v55 )
        v16 = dword_1AA1F4;
      else
        v16 = dword_1AA1DC;
      v9 += *(uint16_t *)(v16 + 16 * v15 + 2 * v52);
      v48 += *(uint16_t *)(2 * v50 + dword_1AA1FC + 8 * v15);
      ++v51;
      v10 += 1 << *(_BYTE *)(129 * v15 + dword_197F9C + 16);
    }
    if ( !a6 && v10 > 0x96 )
    {
      v17 = v9;
      v9 = v10 * (__PAIR64__(v15 != -1, v9) / 0x96);
      if ( v9 < v17 )
        v9 = v17;
    }
    v46 = *(_DWORD *)(40 * word_1AA24C + dword_1AA208 + 2560 * v54 + 320 * *(char *)(dword_192B18 + 361 * a1) + 4 * a3);
    v45 = 0;
    v42 = 0;
    v44 = 0;
    v40 = v7;
    v18 = *(int16_t *)(v7 + 293);
    v43 = *(_DWORD *)(dword_197F98 + 3753 * v52 + 50);
    while ( v42 < 7 && v18 + v43 > 0 && a3 > v44 )
    {
      v19 = *(int16_t *)(v40 + 277);
      if ( v19 <= -100 )
      {
        v41 = -(v19 + 100);
        if ( !*(_BYTE *)(dword_197F9C - 129 * (v19 + 100) + 17) )
        {
          if ( *(int16_t *)(-129 * (v19 + 100) + dword_197F9C + 94) > v18 )
          {
            sub_E1002(v7, v19, v18);
            v22 = v21;
            if ( v21 <= v43 )
            {
              sub_5EF17(v41, word_1AA24C);
              v43 -= v22;
              v45 += v23;
              v18 = 0;
              ++v44;
            }
          }
          else
          {
            sub_5EF17(v41, word_1AA24C);
            v45 += v20;
            ++v44;
            v18 -= *(int16_t *)(-129 * (v19 + 100) + dword_197F9C + 94);
          }
        }
      }
      v40 += 2;
      ++v42;
    }
    v47 = v45 + v46;
    if ( !(v9 + v48) || 4 * v47 > 3 * v9 )
    {
      v33 = a3;
      *a5 = 1;
      while ( v33 < 10 )
        *(_BYTE *)(10 * v54 + dword_1AA240 + v33++) = 1;
LABEL_67:
      if ( v49 > 0xFFFF )
        return 0xFFFF;
      return v49;
    }
    sub_D8D11();
    v39 = v24;
    v25 = (uint16_t)sub_5F804(a1);
    v26 = (uint16_t)sub_5F747(a1, word_1AA24C);
    v27 = v47 + v25;
    if ( v27 >= v9 + v56 || v26 >= v48 + v56 )
    {
      *a4 = 2;
      if ( 3 * v47 >= v9 )
      {
        if ( !v9 )
        {
          v9 = 1;
          v47 = 1;
        }
      }
      else
      {
        v9 = 3;
        v47 = 1;
      }
      v49 = v9 * v39 / (2 * v47);
      v30 = dword_19306C + 113 * v54;
      if ( (((int)*(uint8_t *)(v30 + 42) >> v52) & 1) == 0 )
        goto LABEL_65;
      v31 = *(uint8_t *)(v52 + v30 + 43);
      if ( (~(1 << word_1AA24C) & v31) == 0 && ((v31 >> word_1AA24C) & 1) != 0 )
        goto LABEL_65;
      goto LABEL_64;
    }
    *a4 = 1;
    if ( 3 * v27 >= v9 )
    {
      if ( !v9 )
      {
        v9 = 1;
        v27 = 1;
      }
    }
    else
    {
      v9 = 3;
      v27 = 1;
    }
    if ( 3 * v26 >= v48 )
    {
      if ( v48 )
      {
LABEL_46:
        if ( !a6 && v9 == 3 && v27 == 1 )
          *a4 = 6;
        if ( v27 >= (unsigned int)sub_10000 )
        {
          v9 >>= 8;
          v27 >>= 8;
        }
        if ( v26 >= (unsigned int)sub_10000 )
        {
          v48 >>= 8;
          v26 >>= 8;
        }
        v29 = sub_D8E52(word_1AA24C, v52, v54);
        v49 = v48 * (v9 * v39 / v27) / v26 * sub_134C92(100 * v29) / 0xA;
        if ( !a6 )
          goto LABEL_65;
        a6[4] = v48 * (100 * v9 / v27) / v26;
        if ( a6[1] < a6[4] )
        {
          a6[2] = v53;
          a6[3] = v39;
          goto LABEL_65;
        }
LABEL_64:
        v49 = 0;
LABEL_65:
        if ( a3 <= 1 )
          v49 += v49 / 6;
        goto LABEL_67;
      }
      v48 = 1;
    }
    else
    {
      v48 = 3;
    }
    v26 = 1;
    goto LABEL_46;
  }
  return v49;
}
// D914F: variable 'v20' is possibly undefined
// D9171: variable 'v21' is possibly undefined
// D9188: variable 'v23' is possibly undefined
// D91E2: variable 'v24' is possibly undefined
// 10000: using guessed type void __noreturn sub_10000();
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 1AA1DC: using guessed type int dword_1AA1DC;
// 1AA1F4: using guessed type int dword_1AA1F4;
// 1AA1FC: using guessed type int dword_1AA1FC;
// 1AA208: using guessed type int dword_1AA208;
// 1AA240: using guessed type int dword_1AA240;
// 1AA248: using guessed type int dword_1AA248;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D93F8) --------------------------------------------------------
int __fastcall sub_D93F8( int a1, int a2, _WORD *a3)
{
  int16_t v4; // dx
  int v5; // eax
  int v6; // eax
  int result; // eax
  int16_t v8; // [esp+0h] [ebp-10h]
  int v9; // [esp+4h] [ebp-Ch]
  int16_t v10; // [esp+8h] [ebp-8h]
  char v11; // [esp+Ch] [ebp-4h]

  v4 = *(_WORD *)(146 * a1 + dword_1AA1C8 + 2 * a2);
  v11 = 0;
  v10 = 1;
  *a3 = *(_WORD *)(dword_1AA1D4 + 2 * v4);
  while ( !v11 )
  {
    if ( ++v4 != word_1AA218
      && (v9 = *(int16_t *)(dword_1AA1D4 + 2 * v4), v5 = dword_197F9C + 129 * v9, *(char *)(v5 + 99) == v8)
      && a2 == *(_WORD *)(v5 + 101) )
    {
      if ( a2 == *(char *)(dword_1AA248 + 1438) || *(_BYTE *)(v5 + 127) != 5 )
      {
        v6 = v10++;
        a3[v6] = v9;
      }
    }
    else
    {
      v11 = 1;
    }
  }
  result = v10;
  a3[v10] = -1;
  return result;
}
// D9472: variable 'v8' is possibly undefined
// 197F9C: using guessed type int dword_197F9C;
// 1AA1C8: using guessed type int dword_1AA1C8;
// 1AA1D4: using guessed type int dword_1AA1D4;
// 1AA218: using guessed type int16_t word_1AA218;
// 1AA248: using guessed type int dword_1AA248;


//----- (000D94B3) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_D94B3(
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
        __int128 a23,
        int64_t a24,
        int64_t a25,
        int64_t a26)
{
  _WORD *v26; // edi
  int v27; // esi
  int v28; // ebx
  int16_t v29; // ax
  uint8_t v30; // al
  int v31; // eax
  int v32; // eax
  int16_t v33; // ax
  int16_t v34; // ax
  char v35; // cl
  int16_t v36; // dx
  int v37; // [esp+72h] [ebp-6FAh]
  int v38; // [esp+76h] [ebp-6F6h]
  int16_t *v39; // [esp+7Ah] [ebp-6F2h]
  int16_t v40; // [esp+7Eh] [ebp-6EEh]
  int16_t v41[502]; // [esp+82h] [ebp-6EAh] BYREF
  _BYTE v42[752]; // [esp+46Eh] [ebp-2FEh] BYREF
  _BYTE v43[14]; // [esp+75Eh] [ebp-Eh] BYREF

  BYTE6(a26) = 0;
  *(_DWORD *)((char *)&a25 + 6) = 0;
  v26 = 0;
  if ( a2 )
  {
    *(_DWORD *)((char *)&a23 + 2) = *(_DWORD *)a2;
    *(_DWORD *)((char *)&a23 + 6) = *(_DWORD *)(a2 + 4);
    WORD5(a23) = *(_WORD *)(a2 + 8);
    v26 = (_WORD *)&a23 + 1;
  }
  memset(v43, 0, 72);
  memset(v42, 0, 500);
  *(_DWORD *)((char *)&a26 + 2) = sub_D93F8(word_1AA24C, v40, v41);
  *(_DWORD *)((char *)&a24 + 6) = word_199996;
  *(_DWORD *)((char *)&a24 + 2) = 361 * word_199996;
  v27 = 2 * word_199996;
  *(_DWORD *)((char *)&a25 + 2) = &v42[word_199996 + 500];
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        if ( *(int *)((char *)&a24 + 6) <= 0 )
        {
          if ( BYTE6(a26) && !v39 )
          {
            v33 = 250;
            do
            {
              if ( 3 * *(uint16_t *)&v42[2 * --v33] < 2 * HIWORD(a25) )
                *(_WORD *)&v42[2 * v33] = 0;
            }
            while ( v33 > 0 );
            v34 = sub_FE92D((int)v42, 250);
            v35 = v42[v34 + 500];
            v36 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(361 * v34 + dword_192B18 + 2) + 2);
            *(_WORD *)(dword_1AA1C8 + 146 * word_1AA24C + 2 * v40) = -1;
            sub_FF799(v41, v36, (_BYTE *)&a19 + 2);
            sub_FFD08(v41, v36, (_BYTE *)&a19 + 2);
            while ( SWORD1(a26) > 0 )
            {
              --*(_DWORD *)((char *)&a26 + 2);
              *(_BYTE *)(dword_197F9C + 129 * v41[SWORD1(a26)] + 127) = v35;
            }
          }
          JUMPOUT(0xD87B1);
        }
        *(_DWORD *)((char *)&a24 + 2) -= 361;
        --*(_DWORD *)((char *)&a25 + 2);
        --*(_DWORD *)((char *)&a24 + 6);
        v28 = *(char *)(*(_DWORD *)((char *)&a24 + 2) + dword_192B18);
        v27 -= 2;
        if ( v28 != -1 && (v39 || sub_D7669(word_1AA24C, v28)) && (!v39 || *v39 == v28) )
        {
          *(_DWORD *)((char *)&a23 + 14) = *(uint8_t *)(17
                                                              * *(int16_t *)(*(_DWORD *)((char *)&a24 + 2)
                                                                           + dword_192B18
                                                                           + 2)
                                                              + dword_1930D4
                                                              + 2);
          if ( !v43[*(_DWORD *)((char *)&a23 + 14)]
            && (((int)*(uint8_t *)(*(_DWORD *)((char *)&a23 + 14) + dword_1AA214) >> word_1AA24C) & 1) != 0 )
          {
            sub_FF799(v41, SHIWORD(a23), (_BYTE *)&a15 + 2);
            if ( HIBYTE(a16) )
            {
              if ( BYTE2(a16) < 0xAu )
              {
                v29 = sub_D8ED2(
                        SHIWORD(a24),
                        (int)v41,
                        BYTE2(a16),
                        *(_BYTE **)((char *)&a25 + 2),
                        &v43[*(_DWORD *)((char *)&a23 + 14)],
                        v26,
                        v37);
                *(_WORD *)&v42[v27] = v29;
                if ( v29 )
                  break;
              }
            }
          }
        }
      }
      v30 = v42[*(_DWORD *)((char *)&a24 + 6) + 500];
      if ( v30 >= 2u )
        break;
      if ( v30 == 1 )
      {
        if ( v38 != 1 )
          goto LABEL_30;
        HIWORD(v32) = a26;
        if ( HIWORD(a25) < *(_WORD *)&v42[v27] )
        {
          LOWORD(v32) = *(_WORD *)&v42[v27];
          *(_DWORD *)((char *)&a25 + 6) = v32;
          if ( v26 )
          {
            if ( (int16_t)v26[2] != -1 )
            {
              v39[2] = v26[2];
              v39[3] = v26[3];
              v39[4] = v26[4];
            }
          }
        }
LABEL_23:
        BYTE6(a26) = 1;
      }
    }
    if ( v30 <= 2u )
      break;
    if ( v30 == 6 )
    {
      if ( v38 == 6 )
        goto LABEL_21;
LABEL_30:
      *(_WORD *)&v42[v27] = 0;
    }
  }
  if ( v38 != 2 )
    goto LABEL_30;
LABEL_21:
  HIWORD(v31) = a26;
  if ( HIWORD(a25) < *(_WORD *)&v42[v27] )
  {
    LOWORD(v31) = *(_WORD *)&v42[v27];
    *(_DWORD *)((char *)&a25 + 6) = v31;
  }
  goto LABEL_23;
}
// D9701: control flows out of bounds to D87B1
// D95BC: inconsistent variable size for '^7E0.16'
// D95BF: inconsistent variable size for '^7E0.16'
// D95CF: inconsistent variable size for '^7E0.16'
// D9626: inconsistent variable size for '^7E0.16'
// D9524: inconsistent variable size for '^7F0.8'
// D9558: inconsistent variable size for '^7F0.8'
// D9644: inconsistent variable size for '^7F0.8'
// D96F7: inconsistent variable size for '^7F0.8'
// D94C7: inconsistent variable size for '^7F8.8'
// D9689: inconsistent variable size for '^7F8.8'
// D96B0: inconsistent variable size for '^7F8.8'
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;
// 199996: using guessed type int16_t word_199996;
// 1AA1C8: using guessed type int dword_1AA1C8;
// 1AA214: using guessed type int dword_1AA214;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D97EE) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=26)) - nutno dohledat rucne v IDA @ 0xD9830 */
int64_t __fastcall sub_D97EE(_DWORD, _DWORD)
{
  DECOMP_TODO("call analysis failed (funcsize=26)");
}


//----- (000D983F) --------------------------------------------------------
int __fastcall sub_D983F(int a1, int *a2, int a3, _DWORD *a4, int a5)
{
  int *v6; // edi
  int v7; // edx
  unsigned int *v8; // eax
  _BYTE *v9; // eax
  int result; // eax
  int v11; // [esp+0h] [ebp-40h]
  unsigned int v12; // [esp+8h] [ebp-38h]
  int v13; // [esp+Ch] [ebp-34h]
  int v14; // [esp+10h] [ebp-30h]
  int v15; // [esp+14h] [ebp-2Ch]
  int v16; // [esp+1Ch] [ebp-24h]
  unsigned int v17; // [esp+20h] [ebp-20h]
  int v18; // [esp+24h] [ebp-1Ch]
  int v19; // [esp+28h] [ebp-18h]
  char *v20; // [esp+2Ch] [ebp-14h]
  int v21; // [esp+30h] [ebp-10h]
  int v22; // [esp+34h] [ebp-Ch]
  int v23; // [esp+38h] [ebp-8h]
  char v24; // [esp+3Ch] [ebp-4h]

  *a4 = 0;
  v22 = *a2;
  v6 = (int *)(63 * *a2 + v11);
  v16 = v11 + 63 * *a2 + 63;
  while ( 1 )
  {
    result = v22;
    v16 -= 63;
    v6 = (int *)((char *)v6 - 63);
    --v22;
    if ( result <= 0 )
      break;
    v18 = *v6;
    v24 = 0;
    v13 = 0;
    v23 = 2560 * *v6;
    while ( !v24 && v13 < 10 )
    {
      v7 = word_199998;
      v14 = 4 * v13;
      v20 = (char *)v6 + 2 * word_199998;
      v19 = 40 * word_199998;
      v12 = -1;
      v17 = 0;
      v21 = 320 * word_199998;
      while ( v7 > 0 )
      {
        v20 -= 2;
        v19 -= 40;
        v21 -= 320;
        --v7;
        if ( v20[47] )
        {
          v8 = (unsigned int *)(v14 + v19 + dword_1AA208 + v23 + 320 * word_1AA24C);
          if ( *v8 < v12 )
            v12 = *v8;
          v17 += *(_DWORD *)(v14 + v23 + dword_1AA1F0 + v21 + 40 * word_1AA24C);
        }
      }
      if ( v17 < v12 )
        v24 = 1;
      ++v13;
    }
    if ( !v24 && (!a5 || *a2 > 1) )
    {
      memmove(v6, v16, 63 * (--*a2 - v22));
      *(_BYTE *)(*a4 + a3) = v18;
      v15 = 0;
      ++*a4;
      do
      {
        v9 = (_BYTE *)(v15 + 10 * v18 + dword_1AA240);
        ++v15;
        *v9 = 1;
      }
      while ( v15 < 10 );
    }
  }
  return result;
}
// D985C: variable 'v11' is possibly undefined
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 199998: using guessed type int16_t word_199998;
// 1AA1F0: using guessed type int dword_1AA1F0;
// 1AA208: using guessed type int dword_1AA208;
// 1AA240: using guessed type int dword_1AA240;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D99D8) --------------------------------------------------------
int __fastcall sub_D99D8(int a1, _DWORD *a2)
{
  int result; // eax
  int v3; // ebx
  int v4; // esi
  int v5; // ecx
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]

  result = word_1AA218;
  *a2 = 0;
  v8 = result;
  v3 = 2 * result;
  while ( v3 > 0 )
  {
    v3 -= 2;
    v4 = *(int16_t *)(v3 + dword_1AA1D4);
    v5 = 129 * v4;
    result = 129 * v4 + dword_197F9C;
    --v8;
    if ( *(char *)(result + 99) == word_1AA24C )
    {
      if ( sub_FF6BE(result) )
      {
        result = dword_197F9C;
        LOBYTE(result) = *(_BYTE *)(v5 + dword_197F9C + 127);
        switch ( (char)result )
        {
          case 0:
          case 2:
          case 3:
          case 5:
          case 7:
            result = v7 + 2 * *a2;
            *(_WORD *)result = v4;
            ++*a2;
            break;
          default:
            continue;
        }
      }
      else
      {
        result = *(char *)(v6 + (int16_t)sub_1003F2(v5 + dword_197F9C, (int)a2));
        if ( result != -1 )
        {
          result = v7 + 2 * *a2;
          *(_WORD *)result = v4;
          ++*a2;
        }
      }
    }
  }
  return result;
}
// D9A47: variable 'v7' is possibly undefined
// D9A5E: variable 'v6' is possibly undefined
// 197F9C: using guessed type int dword_197F9C;
// 1AA1D4: using guessed type int dword_1AA1D4;
// 1AA218: using guessed type int16_t word_1AA218;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D9A7E) --------------------------------------------------------
void __fastcall sub_D9A7E(int a1, int a2, int a3, int a4)
{
  int16_t *v4; // edi
  int v5; // ebx
  int v6; // eax
  int v7; // esi
  char v8; // al
  uint16_t v9; // dx
  int16_t v10; // ax
  int16_t v11; // ax
  int v12; // eax
  int v13; // edx
  int i; // eax
  int v15; // edx
  int v16; // eax
  int v17; // edx
  unsigned int v18; // ecx
  int v19; // ebx
  int v20; // ecx
  int v21; // edx
  int v22; // eax
  int v23; // esi
  int j; // esi
  uint8_t v25; // cl
  int v26; // edx
  int v27; // [esp+0h] [ebp-1672h]
  _BYTE v28[2880]; // [esp+4h] [ebp-166Eh] BYREF
  _BYTE v29[1000]; // [esp+B44h] [ebp-B2Eh] BYREF
  _BYTE v30[1000]; // [esp+F2Ch] [ebp-746h] BYREF
  _BYTE v31[788]; // [esp+1314h] [ebp-35Eh] BYREF
  _BYTE v32[72]; // [esp+1628h] [ebp-4Ah] BYREF
  _BYTE v33[4]; // [esp+1670h] [ebp-2h] BYREF
  uint8_t v34; // [esp+1674h] [ebp+2h]
  int v35; // [esp+1680h] [ebp+Eh] BYREF
  int v36; // [esp+1684h] [ebp+12h] BYREF
  int v37; // [esp+1688h] [ebp+16h]
  int v38; // [esp+168Ch] [ebp+1Ah]
  signed int v39; // [esp+1690h] [ebp+1Eh]
  int16_t v40[2]; // [esp+1694h] [ebp+22h] BYREF
  unsigned int v41; // [esp+1698h] [ebp+26h]
  int v42; // [esp+169Ch] [ebp+2Ah]
  int v43; // [esp+16A0h] [ebp+2Eh]
  int v44; // [esp+16A4h] [ebp+32h]
  _DWORD *v45; // [esp+16A8h] [ebp+36h]
  int v46; // [esp+16ACh] [ebp+3Ah]
  _DWORD *v47; // [esp+16B0h] [ebp+3Eh]
  int v48; // [esp+16B4h] [ebp+42h]
  int v49; // [esp+16B8h] [ebp+46h]
  int v50; // [esp+16BCh] [ebp+4Ah]
  int v51; // [esp+16C0h] [ebp+4Eh]
  int v52; // [esp+16C4h] [ebp+52h]
  int v53; // [esp+16C8h] [ebp+56h]
  int v54; // [esp+16CCh] [ebp+5Ah]
  int v55; // [esp+16D0h] [ebp+5Eh]
  int v56; // [esp+16D4h] [ebp+62h]
  int16_t v57; // [esp+16D8h] [ebp+66h] BYREF
  char v58; // [esp+16DCh] [ebp+6Ah]
  char v59; // [esp+16E0h] [ebp+6Eh]
  char v60; // [esp+16E4h] [ebp+72h]
  char v61; // [esp+16E8h] [ebp+76h]
  char v62; // [esp+16ECh] [ebp+7Ah]
  char v63; // [esp+16F0h] [ebp+7Eh]

  v4 = (int16_t *)a2;
  v61 = a4;
  sub_D99D8((int)v29, &v36);
  v5 = (int)v32;
  v59 = 0;
  v6 = sub_D983F(v27, (int *)a2, (int)v32, &v35, a4);
  while ( !v59 && *(int *)v4 > 0 )
  {
    sub_FE8BE(v6, a2, v5, v4);
    memset(v31, -1, 500);
    memset(v30, -1, 500);
    v5 = 2880;
    memset(v28, 0, sizeof(v28));
    v52 = 2 * v36;
    while ( v52 > 0 )
    {
      v52 -= 2;
      v7 = *(int16_t *)&v29[v52];
      v5 = 129 * v7;
      v8 = sub_1276F0(129 * v7 + dword_197F9C + 23, 0xBu);
      v30[v7 + 500] = 10;
      v58 = v8;
      v42 = *(_DWORD *)v4;
      v37 = -1;
      v44 = 129 * v7;
      v38 = v27 + 63 * v42;
      while ( v42 > 0 )
      {
        v38 -= 63;
        v9 = *(_WORD *)(v38 + 4);
        v53 = *(_DWORD *)v38;
        v10 = sub_D7F34(v7, v9, v53);
        *(_WORD *)&v31[2 * v53 + 500] = v10;
        --v42;
        if ( *(int16_t *)(v44 + dword_197F9C + 101) >= 72 )
        {
          v5 = (int)&v57;
          v11 = sub_D383F(v7, v53, &v57);
        }
        else
        {
          v5 = (int16_t)v53;
          v11 = sub_D3576(word_1AA24C, *(_WORD *)(v44 + dword_197F9C + 101), v53, &v57, v58);
        }
        v43 = v11;
        if ( v11 < 10 )
        {
          v12 = (uint8_t)v30[v7 + 500];
          v60 = 0;
          if ( v12 > v43 )
            goto LABEL_20;
          if ( v12 == v43 )
          {
            if ( v37 == -1 )
              goto LABEL_20;
            v13 = v12;
            v46 = 63 * v37 + v27;
            for ( i = v38 + 4 * v12; ; i += 4 )
            {
              v5 = 4 * v13;
              if ( *(_DWORD *)(i + 7) )
                break;
              v5 += v46;
              if ( *(_DWORD *)(v5 + 7) )
                break;
              ++v13;
            }
            v15 = 4 * v13;
            v16 = v15 + v38;
            v50 = v15;
            if ( *(_DWORD *)(v15 + v38 + 7) )
            {
              v5 = v27 + 63 * v37;
              v17 = v5 + v15;
              if ( !*(_DWORD *)(v17 + 7)
                || (v18 = *(_DWORD *)(v17 + 7),
                    v39 = *(_DWORD *)&v28[40 * *(_DWORD *)v5 + v50],
                    v5 = v39,
                    sub_FEB70(*(_DWORD *)&v28[40 * v53 + v50], *(_DWORD *)(v16 + 7), v39, v18) < 0) )
              {
LABEL_20:
                v60 = 1;
              }
            }
          }
          if ( v60 )
          {
            v37 = v42;
            v30[v7 + 500] = v43;
            v31[v7] = *(_BYTE *)v38;
            v30[v7] = v57;
          }
        }
      }
      if ( v37 != -1 )
      {
        v19 = *(_DWORD *)(v27 + 63 * v37);
        v20 = 40 * v19;
        v21 = (uint8_t)v30[v7 + 500];
        v5 = 2 * v19;
        v22 = v20 + 4 * v21;
        while ( v21 < 10 )
        {
          v22 += 4;
          ++v21;
          *(_DWORD *)&v28[v22 - 4] += *(int16_t *)&v31[v5 + 500];
        }
      }
    }
    v6 = *(_DWORD *)v4;
    v51 = v6;
    v62 = 0;
    a2 = v27 + 63 * v6;
    while ( v51 > 0 )
    {
      --v51;
      v63 = 0;
      a2 -= 63;
      v5 = 0;
      v45 = (_DWORD *)a2;
      v47 = (_DWORD *)a2;
      v48 = a2;
      v6 = *(_DWORD *)a2;
      v55 = a2;
      v54 = a2;
      v31[v6 + 644] = 10;
      while ( v31[v6 + 644] == 10 && v5 < 10 )
      {
        if ( *(_DWORD *)(v54 + 4 * v5 + 7) || !*(_DWORD *)(v54 + 43) )
        {
          v39 = 40 * *v47;
          if ( *(_DWORD *)(v48 + 7) <= *(_DWORD *)&v28[4 * v5 + v39] )
          {
            if ( !v63 )
              v31[v6 + 716] = v5;
            v39 = 4 * v5;
            v41 = 4 * (*(_DWORD *)(v55 + 7) + 2);
            v23 = 4 * v5 + 40 * *v45;
            v63 = 1;
            if ( v41 < *(_DWORD *)&v28[v23] )
              v31[v6 + 644] = v5;
          }
        }
        v48 += 4;
        v55 += 4;
        ++v5;
      }
      if ( !v63 && !v61 )
      {
        v62 = 1;
        v31[v6 + 716] = -1;
      }
    }
    if ( v62 )
    {
      --*(_DWORD *)v4;
    }
    else
    {
      v59 = 1;
      v40[1] = -1;
      for ( j = 2 * v36; j > 0; j -= 2 )
      {
        v40[0] = *(_WORD *)&v28[j + 2878];
        v6 = v40[0];
        a2 = (char)v30[v40[0]];
        if ( a2 != -1 )
        {
          a2 = dword_197F9C;
          LOBYTE(v6) = sub_FF6BE(dword_197F9C + 129 * v40[0]);
          if ( (_BYTE)v6 )
          {
            sub_FF799(v40, (char)v30[v40[0]], v33);
            v6 = v40[0];
            v5 = (char)v31[(char)v31[v40[0]] + 644];
            a2 = v34;
            if ( v5 >= v34 )
            {
              v49 = (int16_t)sub_7A3E3(
                               *(_WORD *)(dword_197F9C + 129 * v40[0] + 103),
                               *(_WORD *)(dword_197F9C + 129 * v40[0] + 105));
              v26 = dword_197F9C;
              *(_BYTE *)(dword_197F9C + 129 * v40[0] + 127) = 5;
              v6 = v40[0];
              v56 = v26;
              a2 = (char)v31[v40[0]];
              v39 = (char)v31[a2 + 716];
              v41 = v34;
              v5 = -1;
              if ( v39 > v34 )
              {
                a2 = v56 + 129 * v40[0];
                v25 = *(_BYTE *)(a2 + 100);
                if ( v25 )
                {
                  if ( v25 <= 1u )
                  {
                    v5 = (char)v30[v40[0]];
                  }
                  else if ( v25 == 2 )
                  {
                    *(_WORD *)(a2 + 101) = v49;
                    v6 = v56 + 129 * v40[0];
                    *(_BYTE *)(v6 + 100) = 0;
                  }
                }
              }
              else
              {
                v5 = a2;
              }
              if ( v5 != -1 )
              {
                v5 = (int)v33;
                sub_FFD08(v40, (char)v30[v40[0]], v33);
                a2 = 146 * word_1AA24C + dword_1AA1C8;
                v6 = v49;
                *(_WORD *)(a2 + 2 * v49) = -1;
              }
            }
          }
        }
      }
    }
  }
  JUMPOUT(0xD87B1);
}
// D9ABD: control flows out of bounds to D87B1
// D9ACC: variable 'v6' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F9C: using guessed type int dword_197F9C;
// 1AA1C8: using guessed type int dword_1AA1C8;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000D9F85) --------------------------------------------------------
void __usercall sub_D9F85(int16_t *a1)
{
  int v1; // ebx
  int v2; // eax
  int v3; // edx
  _BYTE *v4; // eax
  _BYTE *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int i; // esi
  int v10; // eax
  int v11; // ecx
  char *v12; // eax
  char v13; // cl
  int v14; // esi
  int v15; // esi
  int j; // edx
  int v17; // eax
  char v18; // ch
  unsigned int v19; // ebx
  uint8_t v20; // al
  int v21; // edx
  _BYTE *v22; // ecx
  uint16_t v23; // ax
  _BOOL1 v24; // zf
  int v25; // eax
  uint8_t *v26; // ecx
  uint16_t v27; // ax
  uint8_t v28; // al
  int v29; // esi
  int v30; // ebx
  int v31; // ecx
  char v32; // al
  int v33; // eax
  uint8_t v34; // dl
  int v35; // eax
  int v36; // edi
  int v37; // eax
  _DWORD v38[1134]; // [esp+0h] [ebp-1B9Ah] BYREF
  _BYTE v39[2520]; // [esp+11B8h] [ebp-9E2h] BYREF
  _BYTE v40[10]; // [esp+1B90h] [ebp-Ah] BYREF
  _BYTE v41[62]; // [esp+1B9Ah] [ebp+0h] BYREF
  int v42; // [esp+1BD8h] [ebp+3Eh]
  int v43; // [esp+1BDCh] [ebp+42h] BYREF
  int v44; // [esp+1BE0h] [ebp+46h]
  int v45; // [esp+1BE4h] [ebp+4Ah]
  int v46; // [esp+1BE8h] [ebp+4Eh]
  int v47; // [esp+1BECh] [ebp+52h]
  int v48; // [esp+1BF0h] [ebp+56h]
  int v49; // [esp+1BF4h] [ebp+5Ah]
  int v50; // [esp+1BF8h] [ebp+5Eh]
  int v51; // [esp+1BFCh] [ebp+62h]
  int v52; // [esp+1C00h] [ebp+66h]
  int v53; // [esp+1C04h] [ebp+6Ah]
  int v54; // [esp+1C08h] [ebp+6Eh]
  int v55; // [esp+1C0Ch] [ebp+72h]
  int v56; // [esp+1C10h] [ebp+76h]
  int16_t v57; // [esp+1C14h] [ebp+7Ah]
  int v58; // [esp+1C18h] [ebp+7Eh]

  v43 = 0;
  v38[0] = -1;
  memset(v38, 0, sizeof(v38));
  memset(v40, -1, 72);
  v1 = word_19999A;
  v42 = 113 * word_19999A;
  v55 = 8 * word_19999A;
  v54 = 2560 * word_19999A;
  while ( v1 > 0 )
  {
    v42 -= 113;
    v55 -= 8;
    v2 = *(uint8_t *)(v42 + dword_19306C + 56);
    v54 -= 2560;
    --v1;
    if ( ((v2 >> word_1AA24C) & 1) != 0 )
    {
      v50 = v54;
      v56 = 80 * v1;
      v3 = word_199998;
      v49 = v55;
      v45 = 10 * word_199998;
      v46 = 320 * word_199998;
      v52 = 2 * word_199998;
LABEL_19:
      while ( v3 > 0 )
      {
        v45 -= 10;
        v46 -= 320;
        --v3;
        v52 -= 2;
        if ( v3 != word_1AA24C )
        {
          v4 = (_BYTE *)(v45 + v56 + dword_1AA1E4);
          if ( v4[9] )
          {
            if ( *v4 || *(_BYTE *)(v3 + v49 + dword_1AA20C) )
            {
              v51 = 0;
              while ( 1 )
              {
                v5 = (_BYTE *)(v51 + v45 + v56 + dword_1AA1E4);
                if ( *v5 )
                  break;
                if ( ++v51 >= 10 )
                  goto LABEL_19;
              }
              sub_FE8BE((int)v5, v3, v1, a1);
              if ( (char)v40[v1] == -1 )
              {
                v6 = 63 * v43;
                *((_BYTE *)&v38[1] + v6 + 2) = -1;
                *(_DWORD *)((char *)v38 + v6) = v1;
                LOBYTE(v6) = v43++;
                v40[v1] = v6;
              }
              v7 = 63 * (char)v40[v1];
              v8 = *((uint8_t *)&v38[1] + v7 + 2);
              *(_WORD *)((char *)&v38[1] + v7) |= 1 << v3;
              if ( v8 > v51 )
                *((_BYTE *)&v38[1] + v7 + 2) = v51;
              v48 = v46;
              for ( i = 4 * v51; i < 40; i += 4 )
              {
                a1 = (int16_t *)(40 * word_1AA24C);
                v10 = i + 63 * (char)v40[v1];
                v11 = *(_DWORD *)((char *)a1 + v48 + v50 + dword_1AA1F0 + i);
                *(_DWORD *)((char *)&v38[1] + v10 + 3) += v11;
              }
              v12 = (char *)&v38[11] + 63 * (char)v40[v1] + v52 + 3;
              v13 = v51;
              *v12 = 1;
              v12[1] = v13;
            }
          }
        }
      }
      v14 = (char)v40[v1];
      if ( v14 != -1 )
      {
        v15 = *((uint8_t *)&v38[1] + 63 * v14 + 2);
        for ( j = 4 * v15; j < 40; j += 4 )
        {
          v17 = j + 63 * (char)v40[v1];
          if ( !*(_DWORD *)((char *)&v38[1] + v17 + 3) )
            *(_DWORD *)((char *)&v38[1] + v17 + 3) = 1;
          ++v15;
        }
      }
    }
  }
  memset(v39, 0, sizeof(v39));
  v18 = 0;
  v19 = 129 * word_199994 + dword_197F9C;
  while ( v19 > dword_197F9C )
  {
    v19 -= 129;
    if ( *(char *)(v19 + 99) >= 8 && *(_BYTE *)(v19 + 20) )
    {
      v20 = *(_BYTE *)(v19 + 100);
      if ( v20 )
      {
        if ( v20 <= 2u )
        {
          v25 = v20 == 1 ? *(int16_t *)(v19 + 101) - 500 : *(int16_t *)(v19 + 101) - 1000;
          if ( (((int)*(uint8_t *)(113 * v25 + dword_19306C + 56) >> word_1AA24C) & 1) != 0 )
          {
            v26 = &v39[35 * v25 - 40 + 5 * *(char *)(v19 + 99)];
            sub_5EF17((int)(v19 - dword_197F9C) / 129, word_1AA24C);
            v24 = v27 + *(_DWORD *)(v26 + 1) == 0;
            *(_DWORD *)(v26 + 1) += v27;
            if ( v24 )
              *(_DWORD *)(v26 + 1) = 1;
            v28 = *(_BYTE *)(v19 + 109);
            if ( v28 < *v26 )
              *v26 = v28;
            goto LABEL_45;
          }
        }
      }
      else
      {
        v21 = *(int16_t *)(v19 + 101);
        if ( (((int)*(uint8_t *)(113 * v21 + dword_19306C + 56) >> word_1AA24C) & 1) != 0 )
        {
          v22 = &v39[35 * v21 - 40 + 5 * *(char *)(v19 + 99)];
          sub_5EF17((int)(v19 - dword_197F9C) / 129, word_1AA24C);
          v24 = v23 + *(_DWORD *)(v22 + 1) == 0;
          *(_DWORD *)(v22 + 1) += v23;
          if ( v24 )
            *(_DWORD *)(v22 + 1) = 1;
          *v22 = 0;
LABEL_45:
          v18 = 1;
        }
      }
    }
  }
  if ( v18 )
  {
    v44 = 7;
    v57 = 15;
    do
    {
      v29 = 63 * v43;
      --v44;
      --v57;
      v30 = word_19999A;
      v58 = 1 << v57;
      v31 = 5 * v44 + 35 * word_19999A;
      while ( v30 > 0 )
      {
        v31 -= 35;
        --v30;
        if ( *(_DWORD *)&v39[v31 + 1] )
        {
          if ( (char)v40[v30] == -1 )
          {
            v29 += 63;
            v41[v29 - 7123] = -1;
            v32 = v43;
            *(_DWORD *)&v41[v29 - 7129] = v30;
            ++v43;
            v40[v30] = v32;
          }
          v33 = 63 * (char)v40[v30];
          *(_WORD *)((char *)&v38[1] + v33) |= v58;
          v34 = v39[v31];
          if ( v34 < *((_BYTE *)&v38[1] + v33 + 2) )
            *((_BYTE *)&v38[1] + v33 + 2) = v34;
          v53 = *((uint8_t *)&v38[1] + 63 * (char)v40[v30] + 2);
          v47 = 4 * v53;
          while ( v47 < 40 )
          {
            v35 = 63 * (char)v40[v30];
            ++v53;
            v36 = *(_DWORD *)&v39[v31 + 1];
            v37 = v47 + v35;
            v47 += 4;
            *(_DWORD *)((char *)&v38[1] + v37 + 3) += v36;
          }
        }
      }
    }
    while ( v44 > 0 );
  }
  if ( v43 > 0 )
    sub_D9A7E((int)v38, (int)&v43, (int)v40, *(_WORD *)(dword_1AA204 + 58 * word_1AA24C + 6) <= 3);
}
// DA298: variable 'v23' is possibly undefined
// DA31D: variable 'v27' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 1AA1E4: using guessed type int dword_1AA1E4;
// 1AA1F0: using guessed type int dword_1AA1F0;
// 1AA204: using guessed type int dword_1AA204;
// 1AA20C: using guessed type int dword_1AA20C;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000DA485) --------------------------------------------------------
void sub_DA485()
{
  _BOOL1 v0; // al
  int v1; // ebx
  int v2; // esi
  int v3; // edi
  int16_t v4; // dx
  int v5; // ecx
  int v6; // ebx
  int v7; // edx
  int v8; // ecx
  int v9; // edi
  int v10; // eax
  _BYTE *v11; // ecx
  int16_t v12; // ax
  int16_t v13; // di
  int16_t v14; // bx
  int v15; // esi
  char v16; // dl
  int v17; // esi
  int v18; // edx
  int v19; // eax
  int v20; // edi
  int v21; // edx
  unsigned int v22; // eax
  int v23; // eax
  int v24; // eax
  char v25; // cl
  int v26; // edx
  int v27; // eax
  int v28; // edx
  int16_t v29; // cx
  int16_t v30; // dx
  int v31; // ecx
  int16_t v32; // ax
  _WORD v33[500]; // [esp+0h] [ebp-596h] BYREF
  _BYTE v34[360]; // [esp+3E8h] [ebp-1AEh]
  _BYTE v35[72]; // [esp+550h] [ebp-46h] BYREF
  _BYTE v36[16]; // [esp+598h] [ebp+2h] BYREF
  _BYTE v37[16]; // [esp+5A8h] [ebp+12h] BYREF
  int v38; // [esp+5B8h] [ebp+22h]
  int v39; // [esp+5BCh] [ebp+26h]
  int v40; // [esp+5C0h] [ebp+2Ah]
  int16_t v41[2]; // [esp+5C4h] [ebp+2Eh] BYREF
  unsigned int v42; // [esp+5C8h] [ebp+32h]
  int16_t v43[2]; // [esp+5CCh] [ebp+36h] BYREF
  unsigned int v44; // [esp+5D0h] [ebp+3Ah]
  int v45; // [esp+5D4h] [ebp+3Eh]
  int v46; // [esp+5D8h] [ebp+42h]
  unsigned int v47; // [esp+5DCh] [ebp+46h]
  unsigned int v48; // [esp+5E0h] [ebp+4Ah]
  int v49; // [esp+5E4h] [ebp+4Eh]
  int v50; // [esp+5E8h] [ebp+52h]
  int v51; // [esp+5ECh] [ebp+56h]
  int16_t v52; // [esp+5F0h] [ebp+5Ah] BYREF
  int16_t v53; // [esp+5F4h] [ebp+5Eh] BYREF
  int16_t v54; // [esp+5F8h] [ebp+62h] BYREF
  int16_t v55; // [esp+5FCh] [ebp+66h] BYREF
  int16_t v56; // [esp+600h] [ebp+6Ah]
  int16_t v57; // [esp+604h] [ebp+6Eh] BYREF
  int v58; // [esp+608h] [ebp+72h]
  int v59; // [esp+60Ch] [ebp+76h]
  char v60; // [esp+610h] [ebp+7Ah]
  _BOOL1 v61; // [esp+614h] [ebp+7Eh]

  v0 = sub_234E5() && !*(_BYTE *)(dword_1AA248 + 2233);
  v56 = 0;
  v1 = 72;
  v61 = v0;
  v2 = 0;
  v3 = 0;
  memset(v35, -1, sizeof(v35));
  v4 = word_19999A;
  while ( v4 > 0 )
  {
    v1 = dword_1AA240 + 10 * --v4;
    if ( !*(_BYTE *)(v1 + 9) )
    {
      v1 = (int)*(uint8_t *)(dword_19306C + 113 * v4 + 65) >> word_1AA24C;
      if ( (v1 & 1) != 0 )
      {
        v5 = 5 * v56;
        v35[v4] = v56;
        v6 = dword_1AA1E0;
        *(_DWORD *)&v34[v5 + 1] = 0;
        v34[v5] = v4;
        v1 = 32 * v4 + v6;
        ++v56;
        v3 += *(_DWORD *)(v1 + 4 * word_1AA24C);
      }
    }
  }
  v7 = 32 * *(char *)(dword_1AA248 + 1438) + dword_1AA1E0;
  v8 = word_1AA24C;
  v9 = ((int16_t)sub_D1006(word_1AA24C) + 1) * v3;
  v10 = 129 * word_199994;
  *(_DWORD *)(v7 + 4 * v8) += v9;
  v11 = (_BYTE *)(v10 + dword_197F9C);
  while ( (unsigned int)v11 > dword_197F9C )
  {
    v12 = (char)*(v11 - 30);
    v11 -= 129;
    if ( v12 == word_1AA24C
      && (char)v11[100] <= 2
      && !v11[17]
      && v11[127] != 1
      && v11[127] != 2
      && v11[127] != 4
      && v11[127] != 5
      && v11[127] != 6
      && v11[127] != 7 )
    {
      if ( sub_FF6BE((int)v11) )
      {
        v1 = 129;
        v7 = (int)&v11[-dword_197F9C] / 129;
        v10 = (int16_t)v2++;
        v33[v10] = v7;
      }
      else
      {
        v10 = sub_1003F2((int)v11, v7);
        v1 = (int16_t)v10;
        v9 = (char)v35[(int16_t)v10];
        if ( v9 != -1 )
        {
          v51 = 129;
          v7 = (int16_t)v10;
          v9 *= 5;
          sub_D7D53((int)&v11[-dword_197F9C] / 129, v10);
          v10 = (int16_t)v10;
          *(_DWORD *)&v34[v9 + 1] += (int16_t)v10;
        }
      }
    }
  }
  if ( !v56 )
    goto LABEL_67;
  if ( v56 == 1 )
  {
    LOWORD(v10) = v34[0];
    v41[1] = -1;
    v13 = v2;
    v58 = v10;
    while ( v13 > 0 )
    {
      v14 = v33[--v13];
      v15 = 129 * v14;
      v16 = sub_1276F0(v15 + dword_197F9C + 23, 0xBu);
      v17 = dword_197F9C + v15;
      v41[0] = v14;
      if ( *(int16_t *)(v17 + 101) >= 72 )
        sub_D7923(v41, (int16_t)v58, &v52, &v55);
      else
        sub_D3576(word_1AA24C, *(_WORD *)(v17 + 101), v58, &v52, v16);
      if ( v52 != -1 )
      {
        *(_BYTE *)(v17 + 127) = 3;
        sub_FF799(v41, v52, v36);
        if ( v36[4] <= 1u || !v61 )
          sub_FFD08(v41, v52, v36);
      }
    }
    goto LABEL_67;
  }
  v18 = (int16_t)v2;
  sub_FE9F5((int)v33, v2);
LABEL_37:
  if ( (int16_t)v2 <= 0 || v56 <= 0 )
LABEL_67:
    JUMPOUT(0xDA478);
  v46 = -1;
  v42 = -1;
  v47 = 1;
  v49 = -1;
  v45 = -1;
  if ( v61 )
    v19 = 2;
  else
    v19 = 255;
  v50 = v19;
  sub_FE8BE(v19, v18, v1, (int16_t *)v9);
  v43[1] = -1;
  v40 = v56;
  v20 = 5 * v56;
  while ( 1 )
  {
    if ( v40 <= 0 )
    {
      v9 = v2;
      v39 = (uint8_t)v34[5 * v46];
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            if ( (int16_t)v9 <= 0 )
            {
              if ( v49 == -1 )
              {
                --v56;
                v18 = v46;
                v35[v46] = v35[v56];
              }
              else
              {
                v9 = v49;
                v43[0] = v33[v49];
                v29 = v45;
                *(_BYTE *)(129 * v43[0] + dword_197F9C + 127) = 3;
                sub_FF799(v43, v29, v37);
                v30 = v29;
                v31 = 5 * v46;
                v1 = (int)v37;
                sub_FFD08(v43, v30, v37);
                v18 = (int16_t)v39;
                sub_D7D53(v43[0], v39);
                --v2;
                *(_DWORD *)&v34[v31 + 1] += v32;
                v33[v9] = v33[(int16_t)v2];
              }
              goto LABEL_37;
            }
            v24 = (int16_t)--v9;
            v38 = (int16_t)v9;
            LOWORD(v24) = v33[(int16_t)v9];
            v1 = 129 * (int16_t)v24;
            v59 = v24;
            v25 = sub_1276F0(v1 + dword_197F9C + 23, 0xBu);
            v26 = *(int16_t *)(v1 + dword_197F9C + 101);
            if ( v26 != v39 )
              break;
            v50 = 0;
            v45 = v26;
            v49 = v38;
          }
          if ( *(int16_t *)(v1 + dword_197F9C + 101) >= 72 )
            break;
          v1 = (int16_t)v39;
          v27 = sub_D3576(word_1AA24C, v26, v39, &v57, v25);
          if ( (int16_t)v27 < v50 )
          {
            v49 = v38;
            v28 = v57;
            goto LABEL_62;
          }
        }
        v1 = (int)&v54;
        v43[0] = v59;
        sub_D7923(v43, (int16_t)v39, &v54, &v53);
        v27 = v53;
        if ( v53 < v50 )
        {
          v49 = v38;
          v28 = v54;
LABEL_62:
          v50 = v27;
          v45 = v28;
        }
      }
    }
    v21 = *((uint8_t *)&v33[497] + v20 + 1);
    v48 = *(_DWORD *)((char *)&v33[498] + v20);
    --v40;
    v60 = 0;
    v22 = *(_DWORD *)(dword_1AA1E0 + 32 * v21 + 4 * word_1AA24C);
    v20 -= 5;
    v44 = v22;
    if ( v46 == -1 )
      goto LABEL_50;
    v1 = v42;
    v23 = sub_FEB70(v48, v22, v42, v47);
    if ( v23 >= 0 )
      break;
    if ( v23 == -1 )
      goto LABEL_50;
LABEL_51:
    if ( v60 )
    {
      v46 = v40;
      v42 = v48;
      v47 = v44;
    }
  }
  if ( v23 > 0 || v47 >= v44 )
    goto LABEL_51;
LABEL_50:
  v60 = 1;
  goto LABEL_51;
}
// DA667: control flows out of bounds to DA478
// DA64E: variable 'v10' is possibly undefined
// DA963: variable 'v32' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999A: using guessed type int16_t word_19999A;
// 1AA1E0: using guessed type int dword_1AA1E0;
// 1AA240: using guessed type int dword_1AA240;
// 1AA248: using guessed type int dword_1AA248;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000DA99C) --------------------------------------------------------
void __usercall sub_DA99C(int a1)
{
  int v1; // ebx
  int v2; // edx
  int v3; // eax
  unsigned int v4; // esi
  int v5; // ecx
  char *v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  char v10; // cl
  char v11; // ch
  int v12; // esi
  int v13; // esi
  int v14; // edi
  int v15; // eax
  int16_t *v16; // edi
  int v17; // esi
  _WORD v18[500]; // [esp+0h] [ebp-4EAh]
  _BYTE v19[72]; // [esp+3E8h] [ebp-102h] BYREF
  _BYTE v20[72]; // [esp+430h] [ebp-BAh] BYREF
  char v21[72]; // [esp+478h] [ebp-72h] BYREF
  _BYTE v22[16]; // [esp+4C0h] [ebp-2Ah] BYREF
  _BYTE v23[16]; // [esp+4D0h] [ebp-1Ah] BYREF
  _BYTE v24[16]; // [esp+4E0h] [ebp-Ah] BYREF
  _BYTE v25[16]; // [esp+4F0h] [ebp+6h] BYREF
  _BYTE v26[16]; // [esp+500h] [ebp+16h] BYREF
  char v27[4]; // [esp+510h] [ebp+26h] BYREF
  uint8_t v28; // [esp+514h] [ebp+2Ah]
  char v29; // [esp+515h] [ebp+2Bh]
  int v30; // [esp+520h] [ebp+36h]
  int16_t v31[2]; // [esp+524h] [ebp+3Ah] BYREF
  int v32; // [esp+528h] [ebp+3Eh]
  int v33; // [esp+52Ch] [ebp+42h]
  int v34; // [esp+530h] [ebp+46h]
  int v35; // [esp+534h] [ebp+4Ah]
  int v36; // [esp+538h] [ebp+4Eh]
  int16_t v37; // [esp+53Ch] [ebp+52h] BYREF
  int v38; // [esp+540h] [ebp+56h]
  int v39; // [esp+544h] [ebp+5Ah]
  int v40; // [esp+548h] [ebp+5Eh] BYREF
  int16_t v41; // [esp+54Ch] [ebp+62h] BYREF
  int v42; // [esp+550h] [ebp+66h] BYREF
  int v43; // [esp+554h] [ebp+6Ah] BYREF
  int v44; // [esp+558h] [ebp+6Eh]
  int v45; // [esp+55Ch] [ebp+72h]
  char v46; // [esp+560h] [ebp+76h]
  char v47; // [esp+564h] [ebp+7Ah]
  char v48; // [esp+568h] [ebp+7Eh]

  memset(v19, 0, sizeof(v19));
  memset(v20, 0, sizeof(v20));
  v1 = 72;
  v2 = -1;
  memset(v21, -1, sizeof(v21));
  v3 = 129 * word_199994;
  v44 = 0;
  v4 = v3 + dword_197F9C;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        do
        {
          if ( v4 <= dword_197F9C )
          {
            while ( 1 )
            {
              do
              {
                if ( (int16_t)v44 <= 0 )
                  JUMPOUT(0xDA478);
                v31[0] = v18[(int16_t)--v44];
                v15 = 129 * v31[0];
                v16 = (int16_t *)*(int16_t *)(dword_197F9C + v15 + 101);
                sub_FE8BE(v15, v2, v1, v16);
                v31[1] = -1;
              }
              while ( (int)v16 >= 72 );
              v46 = 1;
              v7 = v21[(_DWORD)v16];
              LOWORD(v2) = v21[(_DWORD)v16];
              if ( v7 == -1 )
                goto LABEL_41;
              v1 = (int)&v41;
              v17 = v21[(_DWORD)v16];
              v7 = sub_D7923(v31, v17, &v41, &v37);
              v2 = v41;
              if ( v41 == -1 )
                goto LABEL_41;
              v7 = v37;
              if ( (uint8_t)v20[v17] - 1 <= v37 )
                break;
              v1 = (uint8_t)v19[v17] - 1;
              if ( v1 == v37 )
              {
                sub_FF799(v31, v41, v24);
                v2 = v41;
                v1 = (int)v24;
LABEL_39:
                v7 = sub_FFD08(v31, v2, (_BYTE *)v1);
              }
              v46 = 0;
LABEL_41:
              if ( v46 )
              {
                v45 = -1;
                v38 = 0x7FFF;
                LOWORD(v7) = word_19999A;
                v47 = 0;
                v39 = v7;
                while ( (int16_t)v39 > 0 )
                {
                  if ( v19[(int16_t)--v39] || v20[(int16_t)v39] )
                  {
                    if ( (uint8_t)v19[(int16_t)v39] >= 0xBu
                      || v19[(_DWORD)v16] < 2u
                      || (v1 = (uint8_t)v19[(int16_t)v39],
                          v2 = dword_1AA240,
                          !*(_BYTE *)(v1 + dword_1AA240 + 10 * (int16_t)v39 - 1)) )
                    {
                      if ( (uint8_t)v20[(int16_t)v39] >= 0xBu
                        || v20[(_DWORD)v16] < 2u
                        || (v1 = (uint8_t)v20[(int16_t)v39],
                            v2 = dword_1AA240,
                            !*(_BYTE *)(v1 + dword_1AA240 + 10 * (int16_t)v39 - 1)) )
                      {
                        v8 = (int16_t)v39;
                        v1 = (int)&v43;
                        v2 = (int16_t)v39;
                        sub_D7923(v31, (int16_t)v39, &v43, (int16_t *)&v40);
                        if ( (int16_t)v43 != -1 )
                        {
                          v9 = v40;
                          v34 = (uint8_t)v20[v8];
                          v10 = 0;
                          v11 = 0;
                          v1 = v34 - 1;
                          v2 = (int16_t)v40;
                          if ( (int16_t)v40 < v34 - 1 || (v1 = (uint8_t)v19[v8] - 1, (int16_t)v40 < v1) )
                          {
                            LOWORD(v9) = (uint8_t)v19[v8];
                            v10 = 1;
                            --v9;
                          }
                          else if ( (int16_t)v40 > v1 && !v20[v8]
                                 || (int16_t)v40 >= 10
                                 || (v1 = 10 * (int16_t)v39 + dword_1AA240,
                                     v2 = (int16_t)v40,
                                     *(_BYTE *)((int16_t)v40 + v1)) )
                          {
                            v11 = 1;
                          }
                          if ( !v11 && (int16_t)v9 < (int16_t)v38 )
                          {
                            v2 = v43;
                            v38 = v9;
                            v47 = v10;
                            v45 = v43;
                          }
                        }
                      }
                    }
                  }
                }
                v12 = (int16_t)v45;
                if ( (int16_t)v45 == -1 )
                {
                  v2 = *(char *)(dword_1AA248 + 1438);
                  v1 = dword_1AA240;
                  v48 = 0;
                  if ( !*(_BYTE *)(dword_1AA240 + 10 * v2 + 9) )
                  {
                    v1 = 113 * v2;
                    if ( (((int)*(uint8_t *)(113 * v2 + dword_19306C + 42) >> word_1AA24C) & 1) == 0
                      && v16 != (int16_t *)v2 )
                    {
                      v1 = (int)v23;
                      sub_FF799(v31, v2, v23);
                      if ( v23[5] )
                      {
                        v1 = (int)v23;
                        v2 = *(char *)(dword_1AA248 + 1438);
                        v48 = 1;
                        sub_FFD08(v31, v2, v23);
                      }
                    }
                  }
                  if ( !v48 && *(_BYTE *)(10 * (_DWORD)v16 + dword_1AA240 + 1) )
                  {
                    v13 = word_19999A;
                    v30 = 10 * word_19999A;
                    v32 = 113 * word_19999A;
                    v35 = 0x7FFF;
                    v14 = -1;
                    v33 = 49 * word_19999A;
                    while ( v13 > 0 )
                    {
                      v30 -= 10;
                      v32 -= 113;
                      v33 -= 49;
                      --v13;
                      if ( !*(_BYTE *)(v30 + dword_1AA240 + 9)
                        && (((int)*(uint8_t *)(v32 + dword_19306C + 56) >> word_1AA24C) & 1) != 0 )
                      {
                        v1 = (int)v27;
                        v2 = (int16_t)v13;
                        sub_FF799(v31, v13, v27);
                        if ( v29 )
                        {
                          v2 = 6 * word_1AA24C;
                          if ( *(_BYTE *)(v2 + v33 + dword_1AA1F8 + 6) )
                            v28 -= 24;
                          if ( v28 < v35 )
                          {
                            v35 = v28;
                            v14 = v13;
                          }
                        }
                      }
                    }
                    if ( v14 != -1 )
                    {
                      v12 = (int16_t)v14;
                      sub_FF799(v31, v14, v22);
                      v1 = (int)v22;
                      goto LABEL_83;
                    }
                  }
                }
                else if ( !v47 )
                {
                  sub_FF799(v31, v45, v26);
                  v1 = (int)v26;
LABEL_83:
                  v2 = v12;
                  sub_FFD08(v31, v12, (_BYTE *)v1);
                }
              }
            }
            sub_FF799(v31, v41, v25);
            v2 = v41;
            v1 = (int)v25;
            goto LABEL_39;
          }
          LOWORD(v3) = *(char *)(v4 - 30);
          v4 -= 129;
        }
        while ( (_WORD)v3 != word_1AA24C || *(char *)(v4 + 100) > 2 );
        LOBYTE(v3) = *(_BYTE *)(v4 + 17);
        if ( !(_BYTE)v3 )
          break;
        if ( (_BYTE)v3 == 2 )
        {
          if ( *(int16_t *)(v4 + 101) < 72 )
          {
            v1 = *(int16_t *)(v4 + 101);
            sub_FE8BE(v3, v2, v1, (int16_t *)a1);
            if ( byte_199CB0 )
            {
              v2 = dword_19306C;
              v3 = (int)*(uint8_t *)(dword_19306C + 113 * v1 + 56) >> word_1AA24C;
              if ( (v3 & 1) != 0 )
              {
                if ( (uint8_t)byte_199CB0 >= 2u
                  || (HIWORD(v3) = HIWORD(dword_1AA248), *(_BYTE *)(dword_1AA248 + 40) == 1) )
                {
                  v2 = (int)(v4 - dword_197F9C) % 129;
                  v1 *= 113;
                  v36 = v1;
                  v5 = 10;
                  v42 = (int)(v4 - dword_197F9C) / 129;
                  do
                  {
                    v3 = *(int16_t *)(v5 + v36 + dword_19306C + 72);
                    v5 -= 2;
                    if ( v3 != -1 )
                    {
                      v3 *= 17;
                      v2 = *(int16_t *)(dword_1930D4 + v3);
                      if ( v2 != -1 )
                      {
                        HIWORD(v1) = HIWORD(dword_192B18);
                        v3 = dword_192B18 + 361 * v2;
                        LOWORD(v1) = *(char *)v3;
                        if ( (_WORD)v1 == word_1AA24C && !*(_BYTE *)(v3 + 6) )
                        {
                          v1 = 7 * v2;
                          a1 = 7 * v2 + dword_1AA1EC;
                          if ( *(_BYTE *)(a1 + 5)
                            || (v34 = *(int16_t *)(v3 + 304), v3 = 2 * *(uint8_t *)(a1 + 6), v3 > v34) )
                          {
                            v1 = 1;
                            v6 = (char *)(dword_192B18 + 361 * v2);
                            v2 = (int)&v42;
                            v3 = sub_ED6B7(v6, (int16_t *)&v42, 1);
                            if ( v3 == 1 )
                              break;
                          }
                        }
                      }
                    }
                  }
                  while ( v5 > 0 );
                }
              }
            }
          }
          if ( *(_BYTE *)(v4 + 100) != 5 )
          {
            v1 = 129;
            v2 = (int)(v4 - dword_197F9C) / 129;
            v3 = (int16_t)v44++;
            v18[v3] = v2;
          }
        }
      }
      if ( *(_BYTE *)(v4 + 127) != 1 )
        break;
      if ( *(int16_t *)(v4 + 101) < 72 )
      {
        v19[*(int16_t *)(v4 + 101)] = 1;
        goto LABEL_25;
      }
      v3 = (int16_t)sub_1003F2(v4, v2);
      if ( v19[(int16_t)v3] )
      {
        v1 = (uint8_t)v19[(int16_t)v3];
        v2 = *(uint8_t *)(v4 + 109) + 1;
        if ( v2 >= v1 )
          continue;
      }
      LOBYTE(v2) = *(_BYTE *)(v4 + 109) + 1;
      v19[(int16_t)v3] = v2;
    }
    if ( *(_BYTE *)(v4 + 127) == 6 )
    {
      if ( *(int16_t *)(v4 + 101) >= 72 )
      {
        v3 = (int16_t)sub_1003F2(v4, v2);
        if ( !v20[(int16_t)v3]
          || (v1 = (uint8_t)v20[(int16_t)v3], v2 = *(uint8_t *)(v4 + 109) + 1, v2 < v1) )
        {
          LOBYTE(v2) = *(_BYTE *)(v4 + 109) + 1;
          v20[(int16_t)v3] = v2;
        }
      }
      else
      {
        v20[*(int16_t *)(v4 + 101)] = 1;
LABEL_25:
        v3 = *(int16_t *)(v4 + 101);
        LOBYTE(v2) = *(_BYTE *)(v4 + 101);
        v21[v3] = v2;
      }
    }
  }
}
// DAF16: control flows out of bounds to DA478
// DAA46: variable 'v3' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999A: using guessed type int16_t word_19999A;
// 199CB0: using guessed type char byte_199CB0;
// 1AA1EC: using guessed type int dword_1AA1EC;
// 1AA1F8: using guessed type int dword_1AA1F8;
// 1AA240: using guessed type int dword_1AA240;
// 1AA248: using guessed type int dword_1AA248;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000DAFD4) --------------------------------------------------------
void sub_DAFD4()
{
  int v0; // edi
  int v1; // esi
  int v2; // ebx
  int v3; // edx
  int v4; // eax
  uint8_t v5; // cl
  int v6; // esi
  int v7; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  int16_t v11; // ax
  int16_t v12; // cx
  _WORD v13[500]; // [esp+0h] [ebp-436h]
  _BYTE v14[72]; // [esp+3E8h] [ebp-4Eh] BYREF
  int v15; // [esp+430h] [ebp-6h] BYREF
  _BYTE v16[34]; // [esp+436h] [ebp+0h] BYREF
  _DWORD v17[10]; // [esp+458h] [ebp+22h] BYREF
  _BYTE v18[16]; // [esp+480h] [ebp+4Ah] BYREF
  int16_t v19[2]; // [esp+490h] [ebp+5Ah] BYREF
  int v20; // [esp+494h] [ebp+5Eh]
  unsigned int v21; // [esp+498h] [ebp+62h]
  int v22; // [esp+49Ch] [ebp+66h]
  int v23; // [esp+4A0h] [ebp+6Ah]
  int v24; // [esp+4A4h] [ebp+6Eh]
  int v25; // [esp+4A8h] [ebp+72h]
  int v26; // [esp+4ACh] [ebp+76h]
  int v27; // [esp+4B0h] [ebp+7Ah]
  int v28; // [esp+4B4h] [ebp+7Eh]

  memset(v14, 0, sizeof(v14));
  v0 = 0;
  v1 = word_199994;
  v2 = 0;
  v3 = 129 * word_199994;
  while ( v1 > 0 )
  {
    v3 -= 129;
    v4 = v3 + dword_197F9C;
    --v1;
    if ( *(char *)(v3 + dword_197F9C + 99) == word_1AA24C )
    {
      v5 = *(_BYTE *)(v4 + 100);
      if ( v5 )
      {
        if ( v5 <= 1u )
        {
          *((_BYTE *)&v13[250] + *(int16_t *)(v4 + 101)) = 1;
        }
        else if ( v5 == 2 )
        {
          *((_BYTE *)v13 + *(int16_t *)(v4 + 101)) = 1;
        }
      }
      else
      {
        if ( (!*(_BYTE *)(v4 + 127) || *(_BYTE *)(v4 + 127) == 3) && !*(_BYTE *)(v3 + dword_197F9C + 17) )
        {
          v2 += 2;
          ++v0;
          *(_WORD *)&v16[v2 - 1080] = v1;
        }
        v14[*(int16_t *)(v3 + dword_197F9C + 101)] = 1;
      }
    }
  }
  v6 = word_19999A;
  v24 = 113 * word_19999A;
  v23 = 8 * word_19999A;
  v21 = 2 * v0;
  while ( v6 > 0 )
  {
    v7 = *(uint8_t *)(--v6 + dword_1AA200);
    v24 -= 113;
    v23 -= 8;
    if ( ((v7 >> word_1AA24C) & 1) != 0
      && (((int)*(uint8_t *)(v24 + dword_19306C + 51) >> word_1AA24C) & 1) == 0
      && !v14[v6]
      && (byte_199CB0 || !*(_BYTE *)(v24 + dword_19306C + 56)) )
    {
      v28 = -1;
      v25 = -1;
      v27 = 255;
      sub_D7C04(v6, &v15, v17);
      if ( !v0 )
        break;
      v22 = v0;
      v26 = v23;
      v8 = 2 * v0;
      while ( v22 > 0 )
      {
        v20 = *(int16_t *)&v16[v8 - 1080];
        --v22;
        v8 -= 2;
        if ( (uint8_t)sub_1276F0(dword_197F9C + 129 * v20 + 23, 0xBu)
          || (((int)*(uint8_t *)(v6 + dword_1AA214) >> word_1AA24C) & 1) != 0 )
        {
          v9 = dword_1AA1E8 + 576 * *(int16_t *)(129 * v20 + dword_197F9C + 101) + v26;
          v10 = *(uint8_t *)(v9 + word_1AA24C);
          if ( v10 < v27 && *(uint8_t *)(v9 + word_1AA24C) < 0xAu && !v17[v10] )
          {
            v27 = *(uint8_t *)(v9 + word_1AA24C);
            v25 = v6;
            v28 = v22;
          }
        }
      }
      if ( v28 != -1 )
      {
        v11 = v13[v28];
        v21 -= 2;
        v19[0] = v11;
        v12 = v25;
        v13[v28] = v13[v21 / 2];
        v19[1] = -1;
        sub_FF799(v19, v12, v18);
        *(_BYTE *)(dword_197F9C + 129 * v19[0] + 127) = 7;
        --v0;
        sub_FFD08(v19, v12, v18);
      }
    }
  }
  JUMPOUT(0xDA478);
}
// DB252: control flows out of bounds to DA478
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999A: using guessed type int16_t word_19999A;
// 199CB0: using guessed type char byte_199CB0;
// 1AA1E8: using guessed type int dword_1AA1E8;
// 1AA200: using guessed type int dword_1AA200;
// 1AA214: using guessed type int dword_1AA214;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000DB257) --------------------------------------------------------
void sub_DB257()
{
  int v0; // edx
  int16_t *v1; // edx
  int v2; // ebx
  int v3; // ecx
  int16_t v4; // di
  int v5; // esi
  int i; // eax
  int v7; // ebx
  int v8; // edx
  int16_t v9[502]; // [esp+0h] [ebp-3FCh] BYREF
  _BYTE v10[16]; // [esp+3ECh] [ebp-10h] BYREF
  _DWORD savedregs[6]; // [esp+3FCh] [ebp+0h] BYREF

  if ( *(int16_t *)(dword_1AA248 + 1991) != -1 && (uint16_t)sub_D1006(word_1AA24C) )
    *(_WORD *)(dword_1AA248 + 1991) = -1;
  v0 = *(int16_t *)(dword_1AA248 + 1991);
  if ( v0 != -1 )
  {
    v1 = (int16_t *)(dword_1930D4 + 17 * v0);
    v2 = *v1;
    if ( v2 != -1 && *(char *)(361 * v2 + dword_192B18) == *(char *)(dword_1AA248 + 1994) )
    {
      v3 = *(char *)(3753 * word_1AA24C + dword_197F98 + 1438);
      if ( *(int16_t *)(146 * word_1AA24C + dword_1AA1C8 + 2 * v3) != -1 )
      {
        v4 = *((uint8_t *)v1 + 2);
        v5 = sub_D93F8(word_1AA24C, *(char *)(3753 * word_1AA24C + dword_197F98 + 1438), v9);
        sub_FF799(v9, v4, v10);
        if ( v10[5] )
        {
          for ( i = 2 * v5; i > 0; i -= 2 )
          {
            v7 = 129 * *(int16_t *)((char *)&savedregs[-256] + i + 2);
            *(_BYTE *)(dword_197F9C + v7 + 127) = 6;
          }
          sub_FFD08(v9, v4, v10);
          *(_WORD *)(dword_1AA1C8 + 146 * word_1AA24C + 2 * v3) = -1;
        }
      }
    }
    v8 = *(char *)(dword_1AA248 + 1994);
    if ( *(_DWORD *)(320 * word_1AA24C
                   + dword_1AA1F0
                   + 2560 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_1AA248 + 1991) + 2)
                   + 40 * v8
                   + 4) )
      sub_51078(word_1AA24C, v8);
  }
  JUMPOUT(0xDA47F);
}
// DB3E0: control flows out of bounds to DA47F
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 1AA1C8: using guessed type int dword_1AA1C8;
// 1AA1F0: using guessed type int dword_1AA1F0;
// 1AA248: using guessed type int dword_1AA248;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000DB3E5) --------------------------------------------------------
void __fastcall sub_DB3E5(int a1)
{
  int v1; // edx
  int v2; // eax
  int v3; // ebx
  int v4; // edx
  int i; // esi
  int v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = 3753 * a1;
  v2 = word_199998;
  v7 = v1;
  while ( v2 > 0 )
  {
    --v2;
    if ( *(_BYTE *)(v7 + dword_197F98 + v2 + 2062) )
    {
      v6 = word_19999A;
      v3 = 113 * word_19999A;
      v4 = 10 * word_19999A;
      while ( v3 > 0 )
      {
        v4 -= 10;
        --v6;
        v3 -= 113;
        if ( !*(_BYTE *)(v4 + dword_1AA240) && (((int)*(uint8_t *)(dword_19306C + v3 + 56) >> v2) & 1) != 0 )
        {
          for ( i = 10; i > 0; *(_BYTE *)(v4 + dword_1AA240 + i) = 1 )
            --i;
        }
      }
    }
  }
  JUMPOUT(0xDB3DF);
}
// DB479: control flows out of bounds to DB3DF
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 1AA240: using guessed type int dword_1AA240;


//----- (000DB47E) --------------------------------------------------------
void __usercall sub_DB47E(int a1, int a2, int16_t *a3)
{
  int16_t v3; // dx
  int v4; // ebx
  int v5; // edx
  unsigned int v6; // eax
  int v7; // eax
  int v8; // eax
  int64_t v9; // rax
  int64_t v10; // rax
  int64_t v11; // rax
  int64_t v12; // rax
  int64_t v13; // rax
  int64_t v14; // rax
  _BYTE v15[2160]; // [esp+0h] [ebp-B88h] BYREF
  _BYTE v16[720]; // [esp+870h] [ebp-318h] BYREF
  _BYTE v17[72]; // [esp+B40h] [ebp-48h] BYREF

  v3 = a1;
  sub_FE8BE(a1, a1, a2, a3);
  word_1AA24C = v3;
  dword_1AA248 = 3753 * v3 + dword_197F98;
  dword_1AA244 = (int)v15;
  sub_D76B8((int)v15, &word_1AA24E);
  qsort(dword_1AA244, word_1AA24E, 6);
  dword_1AA240 = (int)v16;
  memset(v16, 0, sizeof(v16));
  v4 = 72;
  sub_DB3E5(v3);
  dword_1AA23C = (int)v17;
  memset(v17, 0, sizeof(v17));
  v5 = dword_197F9C;
  v6 = dword_197F9C + 129 * word_199994;
  while ( v6 > dword_197F9C )
  {
    v6 -= 129;
    if ( *(char *)(v6 + 99) >= 8 && !*(_BYTE *)(v6 + 100) )
    {
      v5 = dword_1AA23C;
      LOBYTE(v4) = *(_BYTE *)(v6 + 99);
      *(_BYTE *)(dword_1AA23C + *(int16_t *)(v6 + 101)) = v4;
    }
  }
  sub_FE8BE(v6, v5, v4, a3);
  sub_D7764(dword_1AA244, &word_1AA24E);
  sub_FE8BE(v7, (int)&word_1AA24E, v4, a3);
  sub_DB257();
  sub_FE8BE(v8, (int)&word_1AA24E, v4, a3);
  v9 = sub_D97EE(6, 2);
  sub_FE8BE(v9, SHIDWORD(v9), v4, a3);
  sub_D9F85(a3);
  sub_FE8BE(v9, SHIDWORD(v9), v4, a3);
  v10 = sub_D97EE(1, 2);
  sub_FE8BE(v10, SHIDWORD(v10), v4, a3);
  LOBYTE(v10) = sub_D896F(dword_1AA244, &word_1AA24E);
  sub_FE8BE(v10, 2, v4, a3);
  v11 = sub_D97EE(2, 2);
  sub_FE8BE(v11, SHIDWORD(v11), v4, a3);
  v12 = sub_D97EE(6, 0);
  sub_FE8BE(v12, SHIDWORD(v12), v4, a3);
  v13 = sub_D97EE(1, 0);
  sub_FE8BE(v13, SHIDWORD(v13), v4, a3);
  v14 = sub_D97EE(2, 0);
  sub_FE8BE(v14, SHIDWORD(v14), v4, a3);
  sub_DA99C((int)a3);
  sub_FE8BE(v14, SHIDWORD(v14), v4, a3);
  sub_DA485();
  sub_FE8BE(v14, SHIDWORD(v14), v4, a3);
  if ( *(_WORD *)(dword_1AA204 + 58 * word_1AA24C + 24) == *(_WORD *)(dword_1AA204 + 58 * word_1AA24C + 10)
    || !byte_199CB0 )
  {
    sub_DAFD4();
  }
  dword_1AA244 = 0;
  dword_1AA240 = 0;
  dword_1AA23C = 0;
  JUMPOUT(0xD8D0B);
}
// DB654: control flows out of bounds to D8D0B
// DB55F: variable 'v7' is possibly undefined
// DB569: variable 'v8' is possibly undefined
// DB587: variable 'v9' is possibly undefined
// DB5B4: variable 'v10' is possibly undefined
// DB5FD: variable 'v14' is possibly undefined
// D97EE: using guessed type int64_t __fastcall sub_D97EE(_DWORD, _DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199CB0: using guessed type char byte_199CB0;
// 1AA204: using guessed type int dword_1AA204;
// 1AA23C: using guessed type int dword_1AA23C;
// 1AA240: using guessed type int dword_1AA240;
// 1AA244: using guessed type int dword_1AA244;
// 1AA248: using guessed type int dword_1AA248;
// 1AA24C: using guessed type int16_t word_1AA24C;
// 1AA24E: using guessed type int16_t word_1AA24E;


//----- (000DB659) --------------------------------------------------------
void sub_DB659()
{
  JUMPOUT(0xD775E);
}
// DB6CD: control flows out of bounds to D775E


//----- (000DB6D2) --------------------------------------------------------
void __fastcall sub_DB6D2(int a1, int a2)
{
  int v2; // esi
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  int v6; // edx
  unsigned int v7; // eax
  int v8; // esi
  int v9; // edx
  int v10; // ebx
  int v11; // edi
  int v12; // edx
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  int16_t v15; // ax
  char v16; // al
  int i; // edx
  int v18; // ebx
  int v19; // ecx
  int v20; // edx
  _BYTE v22[896]; // [esp+4h] [ebp-390h] BYREF
  int v23; // [esp+384h] [ebp-10h]
  int v24; // [esp+388h] [ebp-Ch]
  int v25; // [esp+38Ch] [ebp-8h]
  int v26; // [esp+390h] [ebp-4h]

  v24 = *(int16_t *)(dword_197F9C + 129 * a1 + 101);
  memset(v22, 0, 864);
  v2 = word_199998;
  v3 = 3753 * word_199998;
  v25 = -1;
  v4 = 4 * word_199998;
  while ( v4 > 0 )
  {
    v3 -= 3753;
    v5 = v3 + dword_197F98;
    v4 -= 4;
    --v2;
    if ( !*(_BYTE *)(v3 + dword_197F98 + 36) )
    {
      v6 = *(int16_t *)(v5 + 1514);
      v7 = sub_134C92(*(_DWORD *)(v5 + 50));
      v23 = v6 + sub_134C92(v7);
      *(_DWORD *)&v22[v4 + 864] = ((int)(*(int16_t *)(dword_197F98 + v3 + 1512)
                                       - (__CFSHL__((uint64_t)*(int16_t *)(dword_197F98 + v3 + 1512) >> 32, 2)
                                        + 4 * ((uint64_t)*(int16_t *)(dword_197F98 + v3 + 1512) >> 32))) >> 2)
                                + v23
                                + 4 * *(int16_t *)(dword_197F98 + v3 + 1548);
    }
  }
  v26 = word_199996;
  v8 = 361 * word_199996;
  while ( v8 > 0 )
  {
    v8 -= 361;
    v9 = *(char *)(v8 + dword_192B18);
    --v26;
    if ( v9 != -1 )
    {
      v10 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v8 + dword_192B18 + 2) + 2);
      if ( v10 != v24 && !*(_BYTE *)(v10 + a2) )
      {
        v11 = dword_197F98 + 3753 * v9;
        v12 = 4 * v9;
        if ( *(_BYTE *)(v11 + 2233) )
        {
          v13 = *(_DWORD *)&v22[12 * v10 + 4];
          v22[12 * v10 + 2] = 1;
          if ( v13 < *(_DWORD *)&v22[v12 + 864] )
            *(_DWORD *)&v22[12 * v10 + 4] = *(_DWORD *)&v22[v12 + 864];
        }
        else
        {
          v14 = *(_DWORD *)&v22[12 * v10 + 8];
          v22[12 * v10 + 3] = 1;
          if ( v14 < *(_DWORD *)&v22[v12 + 864] )
            *(_DWORD *)&v22[12 * v10 + 8] = *(_DWORD *)&v22[v12 + 864];
        }
        v15 = v24;
        v22[12 * v10] = v10;
        sub_EBEB7(v15, v10);
        v22[12 * v10 + 1] = v16;
      }
    }
  }
  qsort(v22, word_19999A, 12);
  for ( i = 0; i < word_19999A; ++i )
    ;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  while ( v19 < word_19999A && v18 < 7 )
  {
    if ( v22[v20 + 1] && v22[v20 + 1] < 0xFu && sub_1247A0(++v18) == 1 )
      v25 = (uint8_t)v22[v20];
    v20 += 12;
    ++v19;
  }
  JUMPOUT(0xD775E);
}
// DB8D3: control flows out of bounds to D775E
// DB84D: variable 'v16' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (000DB8D8) --------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void sub_DB8D8()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edx
  char v9; // al
  int v10; // eax
  char v11; // al
  int16_t v12; // cx
  int16_t v13; // [esp-2h] [ebp-C0h] BYREF
  _BYTE v14[100]; // [esp+0h] [ebp-BEh] BYREF
  _BYTE v15[72]; // [esp+64h] [ebp-5Ah] BYREF
  _BYTE v16[18]; // [esp+ACh] [ebp-12h] BYREF
  int16_t v17; // [esp+BEh] [ebp+0h] BYREF
  int v18; // [esp+F4h] [ebp+36h]
  int v19; // [esp+F8h] [ebp+3Ah]
  int v20; // [esp+FCh] [ebp+3Eh]
  int v21; // [esp+100h] [ebp+42h]
  int16_t v22; // [esp+104h] [ebp+46h]
  int v23; // [esp+108h] [ebp+4Ah]
  int v24; // [esp+10Ch] [ebp+4Eh]
  int v25; // [esp+110h] [ebp+52h]
  int v26; // [esp+114h] [ebp+56h]
  int16_t v27; // [esp+118h] [ebp+5Ah]
  _BYTE v28[16]; // [esp+11Ch] [ebp+5Eh] BYREF
  int16_t v29[2]; // [esp+12Ch] [ebp+6Eh] BYREF
  int v30; // [esp+130h] [ebp+72h]
  int v31; // [esp+134h] [ebp+76h]
  int v32; // [esp+138h] [ebp+7Ah]
  _BOOL1 v33; // [esp+13Ch] [ebp+7Eh]

  memset(v15, 0, sizeof(v15));
  memset(v16, 0, 72);
  v32 = word_199994;
  v30 = -1;
  v31 = 129 * word_199994;
  while ( v32 > 0 )
  {
    v31 -= 129;
    v0 = v31 + dword_197F9C;
    --v32;
    if ( *(char *)(v31 + dword_197F9C + 99) >= 8 && *(_BYTE *)(v0 + 20) )
    {
      if ( *(_BYTE *)(v0 + 100) == 1 )
      {
        *((_BYTE *)&v17 + *(int16_t *)(v0 + 101) - 518) = 1;
      }
      else if ( !*(_BYTE *)(v0 + 100) )
      {
        v33 = 0;
        if ( *(_BYTE *)(v0 + 99) == 13 )
        {
          v33 = v15[*(int16_t *)(v0 + 101)] != 0;
          v1 = v31 + dword_197F9C;
          v15[*(int16_t *)(v31 + dword_197F9C + 101)] = 1;
          v16[*(int16_t *)(v1 + 101)] = 1;
          if ( ++*(_WORD *)(v1 + 97) == 30 )
          {
            sub_DB6D2(v32, (int)v16);
            *(_WORD *)(v31 + dword_197F9C + 97) = 0;
            if ( v2 != -1 && v30 == -1 )
            {
              v3 = word_199994;
              v30 = 0;
              v4 = 129 * word_199994;
              while ( v4 > 0 )
              {
                v4 -= 129;
                v5 = v4 + dword_197F9C;
                --v3;
                if ( *(_BYTE *)(v4 + dword_197F9C + 99) == 13 && *(_BYTE *)(v5 + 20) && *(char *)(v5 + 100) < 5 )
                  ++v30;
              }
            }
            if ( v30 < 4 )
            {
              sub_57D14((int)v14, 1);
              v6 = 113 * *(int16_t *)(v31 + dword_197F9C + 101);
              v7 = sub_100010(13, v14, *(_WORD *)(dword_19306C + v6 + 15), *(_WORD *)(dword_19306C + v6 + 17));
              if ( v7 != -1 )
              {
                v8 = 129 * v7;
                v9 = *(_BYTE *)(v31 + dword_197F9C + 101);
                LOBYTE(v23) = 18;
                BYTE2(v23) = v9;
                sub_EF6BE(v23, v24, v25, v26, v27);
                *(_WORD *)(v8 + dword_197F9C + 97) = 0;
              }
              ++v30;
            }
          }
        }
        else
        {
          v33 = 1;
        }
        if ( v33 )
        {
          sub_DB6D2(v32, (int)v16);
          if ( v10 == -1 )
          {
            v11 = *(_BYTE *)(v31 + dword_197F9C + 101);
            LOBYTE(v18) = 19;
            BYTE2(v18) = v11;
            sub_EF6BE(v18, v19, v20, v21, v22);
            sub_A163A(v32, (int)&v13);
          }
          else
          {
            v12 = v10;
            v29[0] = v32;
            v29[1] = -1;
            sub_FF799(v29, v10, v28);
            sub_FFD08(v29, v12, v28);
          }
        }
      }
    }
  }
  JUMPOUT(0xDA478);
}
// DBB24: control flows out of bounds to DA478
// DBAE9: bad sp value at call
// DB9D9: variable 'v2' is possibly undefined
// DBABE: variable 'v10' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000DBB29) --------------------------------------------------------
void __usercall sub_DBB29(int16_t *a1)
{
  int v1; // edx
  int v2; // ebx
  int v3; // eax
  int i; // eax

  v1 = word_199998;
  v2 = 3753 * word_199998;
  while ( v1 > 0 )
  {
    v2 -= 3753;
    v3 = v2 + dword_197F98;
    --v1;
    if ( *(_BYTE *)(v2 + dword_197F98 + 40) != 100 )
    {
      if ( *(_BYTE *)(v3 + 1440) )
      {
        sub_FE8BE(v3, v1, v2, a1);
        if ( *(_BYTE *)(v2 + dword_197F98 + 2236) || !sub_233FA() )
          sub_DB47E((int16_t)v1, v2, a1);
      }
    }
    for ( i = word_199998; i > 0; --i )
      ;
  }
  sub_DB8D8();
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000DBB9F) --------------------------------------------------------
void __fastcall sub_DBB9F( int a1, int a2, int a3, int a4, int16_t *a5, _WORD *a6, _DWORD *a7)
{
  int v7[18]; // [esp+0h] [ebp-2E0h] BYREF
  __int128 v8; // [esp+48h] [ebp-298h]
  int64_t v9; // [esp+58h] [ebp-288h]
  int64_t v10; // [esp+60h] [ebp-280h]
  int64_t v11; // [esp+68h] [ebp-278h]
  _WORD v12[2]; // [esp+2D0h] [ebp-10h] BYREF
  int16_t v13; // [esp+2D4h] [ebp-Ch]
  int16_t v14; // [esp+2D6h] [ebp-Ah]
  int16_t v15; // [esp+2D8h] [ebp-8h]
  int v16; // [esp+2DCh] [ebp-4h]

  *a5 = -1;
  v16 = a1;
  if ( *(int16_t *)(146 * a1 + dword_1AA1C8 + 2 * a4) != -1 && (uint8_t)byte_199CB0 > 1u )
  {
    v12[0] = a2;
    v13 = -1;
    v12[1] = a3;
    dword_1AA240 = (int)v7;
    dword_1AA248 = 3753 * v16 + dword_197F98;
    word_1AA24C = a1;
    sub_D94B3(
      (int16_t)a4,
      (int)v12,
      1,
      2,
      v7[0],
      v7[1],
      v7[2],
      v7[3],
      v7[4],
      v7[5],
      v7[6],
      v7[7],
      v7[8],
      v7[9],
      v7[10],
      v7[11],
      v7[12],
      v7[13],
      v7[14],
      v7[15],
      v7[16],
      v7[17],
      v8,
      v9,
      v10,
      v11);
    if ( v13 != -1 )
    {
      *a5 = v13;
      *a6 = v14;
      *a7 = v15;
    }
    dword_1AA240 = 0;
  }
  JUMPOUT(0xD93CD);
}
// DBC57: control flows out of bounds to D93CD
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;
// 1AA1C8: using guessed type int dword_1AA1C8;
// 1AA240: using guessed type int dword_1AA240;
// 1AA248: using guessed type int dword_1AA248;
// 1AA24C: using guessed type int16_t word_1AA24C;


//----- (000DBC5C) --------------------------------------------------------
void __fastcall sub_DBC5C( int a1, int a2, int a3, int16_t *a4, _WORD *a5, _DWORD *a6)
{
  *a4 = -1;
  if ( dword_1AA1C8 && (*(_BYTE *)(dword_197F98 + 3753 * a1 + 2236) || !sub_233FA()) )
    sub_DBB9F(a1, a2, a3, *(char *)(3753 * a1 + dword_197F98 + 1438), a4, a5, a6);
}
// 197F98: using guessed type int dword_197F98;
// 1AA1C8: using guessed type int dword_1AA1C8;


//----- (000DBCC8) --------------------------------------------------------
void __fastcall sub_DBCC8(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // esi
  int v7; // [esp+4h] [ebp-28h] BYREF
  int v8; // [esp+8h] [ebp-24h]
  int *v9; // [esp+Ch] [ebp-20h]
  int v10; // [esp+10h] [ebp-1Ch]
  int v11; // [esp+14h] [ebp-18h]
  _DWORD *v12; // [esp+18h] [ebp-14h]
  int v13; // [esp+1Ch] [ebp-10h]
  int v14; // [esp+20h] [ebp-Ch]
  int16_t v15; // [esp+24h] [ebp-8h] BYREF
  int16_t v16; // [esp+28h] [ebp-4h] BYREF

  v12 = a4;
  *a5 = -1;
  if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 2236) || !sub_233FA() )
  {
    v10 = 320 * a1;
    v13 = 40 * a2;
    v11 = 58 * a1;
    v6 = word_19999A;
    v8 = 4 * a2;
    v14 = 2560 * word_19999A;
    while ( 1 )
    {
      if ( v6 <= 0 )
        goto LABEL_8;
      v14 -= 2560;
      --v6;
      if ( *(_DWORD *)(v8 + v11 + dword_1AA204 + 26) >> 2 <= *(_DWORD *)(v13 + v10 + v14 + dword_1AA208) / 0xAu )
      {
        sub_DBB9F(a1, a2, 150, v6, &v16, &v15, &v7);
        if ( v16 != -1 )
          break;
      }
    }
    *v9 = v6;
    *v12 = v7;
    *a5 = v16;
  }
LABEL_8:
  JUMPOUT(0xD99B2);
}
// DBDB3: control flows out of bounds to D99B2
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;
// 1AA204: using guessed type int dword_1AA204;
// 1AA208: using guessed type int dword_1AA208;


//----- (000DBDB8) --------------------------------------------------------
void __fastcall sub_DBDB8(int a1, int a2)
{
  int v3; // esi
  unsigned int v4; // eax
  int v5; // edx
  uint8_t v6; // bl
  int v7; // edx
  int i; // edx
  int v9; // eax
  _BYTE v10[72]; // [esp+0h] [ebp-4Ch] BYREF
  int v11; // [esp+48h] [ebp-4h]
  _DWORD savedregs[5]; // [esp+4Ch] [ebp+0h] BYREF

  v11 = a2;
  memset(v10, 0, sizeof(v10));
  v3 = 0;
  v4 = dword_197F9C + 129 * word_199994;
  while ( v4 > dword_197F9C )
  {
    v5 = *(char *)(v4 - 30);
    v4 -= 129;
    if ( v5 == a1 && !*(_BYTE *)(v4 + 17) )
    {
      v6 = *(_BYTE *)(v4 + 100);
      v7 = -1;
      if ( v6 )
      {
        if ( v6 <= 1u )
        {
          v7 = *(int16_t *)(v4 + 101) - 500;
        }
        else if ( v6 == 2 )
        {
          v7 = *(int16_t *)(v4 + 101) - 1000;
        }
      }
      else
      {
        v7 = *(int16_t *)(v4 + 101);
      }
      if ( v7 != -1 && (((int)*(uint8_t *)(dword_19306C + 113 * v7 + 56) >> v11) & 1) != 0 )
        v10[v7] = 1;
    }
  }
  for ( i = word_19999A; i > 0; --i )
  {
    v9 = *((uint8_t *)&savedregs[-20] + i + 3);
    v3 += v9;
  }
  JUMPOUT(0xD775E);
}
// DBE7F: control flows out of bounds to D775E
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999A: using guessed type int16_t word_19999A;


//----- (000DBE84) --------------------------------------------------------
int __fastcall sub_DBE84( int a1)
{
  int v1; // ecx
  int result; // eax
  int16_t i; // dx
  int16_t v4; // bx
  int16_t v5; // dx
  unsigned int v6; // esi
  unsigned int *v7; // eax
  int16_t v8; // si
  unsigned int v9; // esi
  int16_t v10; // di
  int v11; // eax
  int16_t v12; // bx
  unsigned int *v13; // eax
  int16_t v14; // di
  int v15; // eax
  unsigned int *v16; // eax
  int16_t v17; // bx
  unsigned int *v18; // eax
  int16_t v19; // [esp+0h] [ebp-78h]
  _BYTE v20[72]; // [esp+4h] [ebp-74h] BYREF
  int v21; // [esp+4Ch] [ebp-2Ch]
  int v22; // [esp+50h] [ebp-28h]
  int v23; // [esp+54h] [ebp-24h]
  int v24; // [esp+58h] [ebp-20h]
  int v25; // [esp+5Ch] [ebp-1Ch]
  int v26; // [esp+60h] [ebp-18h]
  int v27; // [esp+64h] [ebp-14h]
  int v28; // [esp+68h] [ebp-10h]
  int16_t v29; // [esp+6Ch] [ebp-Ch]
  char v30; // [esp+70h] [ebp-8h]
  char v31; // [esp+74h] [ebp-4h]

  v1 = 3753 * a1;
  result = dword_197F98;
  v31 = 0;
  v24 = 0;
  if ( !*(_BYTE *)(v1 + dword_197F98 + 36) )
  {
    memset(v20, 0, sizeof(v20));
    *(_BYTE *)(v1 + dword_197F98 + 1438) = -1;
    for ( i = word_19999A; i > 0; *(_BYTE *)(dword_19306C + 113 * i + 65) &= ~(1 << v19) )
      --i;
    v30 = 1 << v19;
    do
    {
      v4 = -1;
      v5 = word_19999A;
      v6 = 0;
      while ( v5 > 0 )
      {
        if ( !v20[--v5] )
        {
          v7 = (unsigned int *)(4 * v19 + 32 * v5 + dword_1AA1E0);
          if ( v6 < *v7 )
          {
            v4 = v5;
            v6 = *v7;
          }
        }
      }
      result = v4;
      if ( v4 == -1 )
      {
        v31 = 1;
      }
      else
      {
        *(_BYTE *)(dword_19306C + 113 * v4 + 65) |= v30;
        if ( !v24 )
          *(_BYTE *)(dword_197F98 + 3753 * v19 + 1438) = v4;
        ++v24;
        result = v4;
        v8 = word_19999A;
        v20[v4] = 1;
        while ( v8 > 0 )
        {
          if ( --v8 != v4 )
          {
            v22 = v19;
            result = 4 * v19 + dword_1AA1E0 + 32 * v8;
            if ( *(_DWORD *)result )
            {
              v21 = *(uint8_t *)(dword_19306C + 113 * v8 + 65);
              if ( ((v21 >> v19) & 1) == 0 && *(_BYTE *)(576 * v4 + dword_1AA1E8 + 8 * v8 + v22) <= 1u )
              {
                *(_DWORD *)result = 0;
                v20[v8] = 1;
              }
            }
          }
        }
      }
    }
    while ( !v31 );
    if ( !v24 )
    {
      v29 = -1;
      v9 = 0;
      v25 = *(uint8_t *)(3753 * v19 + dword_197F98 + 1440);
      do
      {
        v10 = word_19999A;
LABEL_30:
        while ( v10 > 0 )
        {
          v21 = *(uint8_t *)(113 * --v10 + dword_19306C + 56);
          if ( ((v21 >> v19) & 1) != 0 && (~(1 << v19) & *(uint8_t *)(v10 + dword_1AA214)) != 0 )
          {
            v27 = word_199998;
            while ( v27 > 0 )
            {
              --v27;
              v23 = v19;
              if ( v27 != v19 )
              {
                v26 = v10;
                if ( (((int)*(uint8_t *)(v10 + dword_1AA214) >> v27) & 1) != 0 )
                {
                  v21 = 113 * v26;
                  if ( sub_FF5F8(113 * v26 + dword_19306C, v27, v25) )
                  {
                    v13 = (unsigned int *)(dword_1AA210 + 32 * v26 + 4 * v23);
                    if ( v9 < *v13 )
                    {
                      v29 = v10;
                      v9 = *v13;
                      goto LABEL_30;
                    }
                  }
                }
              }
            }
          }
        }
        if ( v29 != -1 )
          break;
        v25 += 3;
      }
      while ( v25 < 50 );
      if ( v29 == -1 )
      {
        v11 = 3753 * v19;
        LOWORD(v11) = *(_WORD *)(dword_197F98 + v11 + 804);
        v12 = word_19999A;
        v28 = v11;
        while ( v12 > 0 )
        {
          if ( (((int)*(uint8_t *)(113 * --v12 + dword_19306C + 56) >> v19) & 1) != 0 )
          {
            v14 = word_19999A;
            while ( v14 > 0 )
            {
              v21 = *(uint8_t *)(dword_19306C + 113 * --v14 + 56);
              if ( (~(1 << v19) & v21) != 0 )
              {
                sub_EBEB7(v12, v14);
                if ( v15 <= (int16_t)v28 )
                {
                  v16 = (unsigned int *)(dword_1AA210 + 32 * v12 + 4 * v19);
                  if ( v9 < *v16 )
                  {
                    v29 = v12;
                    v9 = *v16;
                  }
                }
              }
            }
          }
        }
        if ( v29 == -1 )
        {
          v17 = word_19999A;
          while ( v17 > 0 )
          {
            if ( (((int)*(uint8_t *)(113 * --v17 + dword_19306C + 56) >> v19) & 1) != 0 )
            {
              v18 = (unsigned int *)(dword_1AA210 + 32 * v17 + 4 * v19);
              if ( v9 <= *v18 )
              {
                v29 = v17;
                v9 = *v18;
              }
            }
          }
        }
      }
      *(_BYTE *)(3753 * v19 + dword_197F98 + 1438) = v29;
      result = 113 * v29 + dword_19306C;
      *(_BYTE *)(result + 65) |= 1 << v19;
    }
  }
  return result;
}
// DBEDA: variable 'v19' is possibly undefined
// DC1D3: variable 'v15' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 1AA1E0: using guessed type int dword_1AA1E0;
// 1AA1E8: using guessed type int dword_1AA1E8;
// 1AA210: using guessed type int dword_1AA210;
// 1AA214: using guessed type int dword_1AA214;


//----- (000DC288) --------------------------------------------------------
char __fastcall sub_DC288(uint8_t *a1)
{
  int v2; // eax
  char v3; // dl

  v2 = a1[801];
  v3 = 0;
  if ( a1[v2 + 196] == 3 || a1[803] )
    v3 = 1;
  a1[803] = 0;
  if ( v3 )
  {
    LOBYTE(v2) = sub_FD335((int)&a1[-dword_197F98] / 3753);
    a1[802] = v2;
    LOBYTE(v2) = *((_BYTE *)&word_17E07F + 13 * (uint8_t)v2);
    a1[801] = v2;
    if ( (uint8_t)v2 >= 0x4Bu )
      a1[1437] = 1;
  }
  return v2;
}
// 17E07F: using guessed type int16_t word_17E07F;
// 197F98: using guessed type int dword_197F98;


//----- (000DC2F3) --------------------------------------------------------
int __fastcall sub_DC2F3(int a1)
{
  int v2; // edx
  int i; // eax

  v2 = 5;
  for ( i = 295; i > 0 && *(_BYTE *)(a1 + *(int16_t *)((char *)&word_17F6A7 + i) + 279) != 3; i -= 59 )
    --v2;
  return v2;
}
// 17F6A7: using guessed type int16_t word_17F6A7;


//----- (000DC323) --------------------------------------------------------
void __fastcall sub_DC323(int a1)
{
  int v2; // edx
  int i; // eax

  v2 = 6;
  for ( i = 90; i > 0 && *(_BYTE *)(a1 + *(int16_t *)((char *)&word_17F63E + i) + 279) != 3; i -= 15 )
    --v2;
  JUMPOUT(0xDC31D);
}
// DC34D: control flows out of bounds to DC31D
// 17F63E: using guessed type int16_t word_17F63E;


//----- (000DC34F) --------------------------------------------------------
void __fastcall sub_DC34F(int a1)
{
  int v2; // edx
  int i; // eax

  v2 = 5;
  for ( i = 55; i > 0 && *(_BYTE *)(a1 + word_17FDF2[i] + 279) != 3; i -= 11 )
    --v2;
  JUMPOUT(0xDC31D);
}
// DC379: control flows out of bounds to DC31D
// 17FDF2: using guessed type int16_t word_17FDF2[];


//----- (000DC37B) --------------------------------------------------------
void __fastcall sub_DC37B(int a1)
{
  int v2; // edx
  int i; // eax

  v2 = 5;
  for ( i = 25; i > 0 && *(_BYTE *)(a1 + word_17FFE8[i] + 279) != 3; i -= 5 )
    --v2;
  JUMPOUT(0xDC31D);
}
// DC3A5: control flows out of bounds to DC31D
// 17FFE8: using guessed type int16_t word_17FFE8[];


//----- (000DC3AA) --------------------------------------------------------
int __fastcall sub_DC3AA(_BYTE *a1)
{
  if ( a1[408] == 3 )
    return 3;
  if ( a1[409] == 3 )
    return 2;
  return a1[413] == 3;
}


//----- (000DC3E3) --------------------------------------------------------
void __fastcall sub_DC3E3(int a1)
{
  int v2; // edx
  int i; // eax

  v2 = 6;
  for ( i = 138; i > 0 && *(_BYTE *)(a1 + word_17FE76[i] + 279) != 3; i -= 23 )
    --v2;
  JUMPOUT(0xDC31D);
}
// DC411: control flows out of bounds to DC31D
// 17FE76: using guessed type int16_t word_17FE76[];


//----- (000DC416) --------------------------------------------------------
void __fastcall sub_DC416(int a1)
{
  int v2; // edx
  int i; // eax

  v2 = 5;
  for ( i = 15; i > 0 && *(_BYTE *)(a1 + *(int16_t *)((char *)&word_14A88 + i) + 279) != 3; i -= 3 )
    --v2;
  JUMPOUT(0xDC31D);
}
// DC444: control flows out of bounds to DC31D
// 14A88: using guessed type int16_t word_14A88;


//----- (000DC449) --------------------------------------------------------
void __fastcall sub_DC449(int a1)
{
  int v2; // edx
  int i; // eax

  v2 = 1;
  for ( i = 3; i > 0 && *(_BYTE *)(a1 + *(int16_t *)((char *)&word_14A9A + i) + 279) != 3; i -= 3 )
    --v2;
  JUMPOUT(0xDC31D);
}
// DC477: control flows out of bounds to DC31D
// 14A9A: using guessed type int16_t word_14A9A;


//----- (000DC47C) --------------------------------------------------------
int __fastcall sub_DC47C(int a1)
{
  _BYTE *v2; // esi
  int v3; // edi
  int v4; // edx
  char v5; // al
  char v6; // al
  char v7; // al
  int16_t v8; // bx
  char v9; // al
  int v10; // eax
  int v11; // eax
  uint8_t v12; // dl
  int v13; // eax
  int16_t i; // bx
  int v15; // eax
  int v16; // eax
  uint8_t v17; // dl
  int v18; // eax
  int v19; // ebx
  int result; // eax
  _BYTE *v21; // ebx
  int v22; // eax
  int16_t v23; // si
  int v24; // edx
  int v25; // eax
  uint8_t *v26; // edx
  int v27; // edi
  int v28; // edi
  int v29; // edi
  int v30; // edi
  int v31; // edi
  int v32; // edi
  char v33; // al
  int v34; // edx
  char v35; // al
  int v36; // eax
  uint8_t v37; // al
  int v38; // eax
  int v39; // edi
  int v40; // eax
  _BOOL1 v41; // dl
  _BYTE v42[20]; // [esp+0h] [ebp-4Ch] BYREF
  int v43; // [esp+14h] [ebp-38h]
  unsigned int v44; // [esp+18h] [ebp-34h]
  int16_t v45; // [esp+1Ch] [ebp-30h]
  int16_t v46; // [esp+20h] [ebp-2Ch]
  int16_t v47; // [esp+24h] [ebp-28h]
  int16_t v48; // [esp+28h] [ebp-24h]
  int v49; // [esp+2Ch] [ebp-20h]
  int v50; // [esp+30h] [ebp-1Ch]
  int16_t v51; // [esp+34h] [ebp-18h]
  int16_t v52; // [esp+38h] [ebp-14h]
  int v53; // [esp+3Ch] [ebp-10h]
  int v54; // [esp+40h] [ebp-Ch]
  int v55; // [esp+44h] [ebp-8h]
  int16_t v56; // [esp+48h] [ebp-4h]

  memset(a1, 0, 168);
  v2 = (_BYTE *)(3753 * word_199998 + dword_197F98);
  while ( (unsigned int)v2 > dword_197F98 )
  {
    v2 -= 3753;
    if ( !v2[36] )
    {
      v3 = (int)&v2[-dword_197F98] / 3753;
      v4 = 21 * (int16_t)v3;
      *(_BYTE *)(a1 + v4) = sub_DC2F3((int)v2);
      sub_DC323((int)v2);
      *(_BYTE *)(a1 + v4 + 2) = v5;
      sub_DC34F((int)v2);
      *(_BYTE *)(a1 + v4 + 4) = v6;
      sub_DC37B((int)v2);
      *(_BYTE *)(a1 + v4 + 6) = v7;
      *(_BYTE *)(a1 + v4 + 7) = sub_DC3AA(v2);
      v8 = 1;
      sub_DC3E3((int)v2);
      *(_BYTE *)(a1 + v4 + 11) = v9;
      do
      {
        v10 = word_17F80D[14 * v8];
        if ( v2[v10 + 279] == 3 )
        {
          v11 = *(int *)((char *)&dword_17D916 + 23 * *(int16_t *)((char *)&word_17E07F + 13 * v10));
          v44 = 100;
          v12 = v11 / 100;
          v13 = a1 + 21 * (int16_t)v3;
          if ( v12 > *(_BYTE *)(v13 + 12) )
            *(_BYTE *)(v13 + 12) = v12;
        }
        ++v8;
      }
      while ( v8 <= 13 );
      for ( i = 14; i <= 20; ++i )
      {
        v15 = word_17F80D[14 * i];
        if ( v2[v15 + 279] == 3 )
        {
          v16 = *(int *)((char *)&dword_17D916 + 23 * *(int16_t *)((char *)&word_17E07F + 13 * v15));
          v44 = 100;
          v17 = v16 / 100;
          v18 = a1 + 21 * (int16_t)v3;
          if ( v17 > *(_BYTE *)(v18 + 14) )
            *(_BYTE *)(v18 + 14) = v17;
        }
      }
      sub_EC15C((int16_t)v3, v42, 1);
      v19 = 21 * (int16_t)v3;
      *(_WORD *)(a1 + v19 + 17) = v42[3] + v42[11] + v42[0] + v42[6] + v42[8] + v42[10] + v42[13];
      *(_WORD *)(a1 + v19 + 17) += v42[14] / 2;
      *(_WORD *)(a1 + v19 + 17) += (int)v42[1] >> 2;
      *(_BYTE *)(a1 + v19 + 16) = v42[2] + 4 * (v42[4] + v42[12] + 1);
    }
  }
  result = dword_197F98;
  v21 = (_BYTE *)(dword_197F98 + 3753 * word_199998);
LABEL_81:
  while ( 2 )
  {
    if ( (unsigned int)v21 > dword_197F98 )
    {
      v21 -= 3753;
      if ( v21[36] )
        continue;
      v22 = (int)&v21[-dword_197F98] / 3753;
      v23 = v22;
      LOWORD(v22) = word_199998;
      v49 = v22;
      while ( 1 )
      {
        HIWORD(v39) = 0;
        v40 = (int)&v21[-dword_197F98] / 3753;
        if ( (int16_t)v49 <= 0 )
        {
          v41 = v21[463] != 3 && (int16_t)sub_D8C79(v40) == -1;
          result = 21 * v23;
          *(_BYTE *)(a1 + result + 20) = v41;
          goto LABEL_81;
        }
        v43 = (int16_t)--v49;
        if ( v40 == (int16_t)v49 )
          goto LABEL_67;
        HIWORD(v24) = HIWORD(dword_197F98);
        if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v49 + 36) )
          goto LABEL_67;
        v25 = 21 * v43;
        LOWORD(v24) = *(uint8_t *)(a1 + 21 * v43);
        v54 = v24;
        v26 = (uint8_t *)(a1 + 21 * v23);
        LOWORD(v39) = *v26;
        v50 = v39;
        v27 = v54 - v39;
        v47 = v27;
        LOWORD(v27) = *(uint8_t *)(a1 + 21 * v43 + 2);
        v50 = v27;
        LOWORD(v27) = v26[2];
        v54 = v27;
        v28 = v50 - v27;
        v48 = v28;
        LOWORD(v28) = *(uint8_t *)(a1 + 21 * v43 + 4);
        v54 = v28;
        LOWORD(v28) = v26[4];
        v50 = v28;
        v29 = v54 - v28;
        v46 = v29;
        LOWORD(v29) = *(uint8_t *)(a1 + 21 * v43 + 7);
        v50 = v29;
        LOWORD(v29) = v26[7];
        v54 = v29;
        v30 = v50 - v29;
        v45 = v30;
        LOWORD(v30) = *(uint8_t *)(a1 + 21 * v43 + 12);
        v54 = v30;
        LOWORD(v30) = v26[12];
        v50 = v30;
        v31 = v54 - v30;
        v52 = v31;
        LOWORD(v31) = *(uint8_t *)(a1 + 21 * v43 + 14);
        v54 = v31;
        LOWORD(v31) = v26[14];
        v50 = v31;
        v32 = v54 - v31;
        v51 = v32;
        LOWORD(v32) = *(uint8_t *)(a1 + 21 * v43 + 16);
        v50 = v32;
        LOWORD(v32) = v26[16];
        LOWORD(v25) = *(_WORD *)(a1 + 21 * v43 + 17);
        v54 = v32;
        LOWORD(v25) = v25 - *(_WORD *)(v26 + 17);
        v53 = v25;
        v55 = v50 - v32;
        if ( v47 <= 0 )
        {
          if ( v47 )
            goto LABEL_27;
          v44 = sub_1247A0(2u);
          v33 = v44 - 1;
        }
        else if ( v21[v43 + 1412] )
        {
          v33 = 3 * v47;
        }
        else
        {
          v33 = v47;
        }
        v26[1] += v33;
LABEL_27:
        if ( v48 <= 0 )
        {
          if ( !v48 )
          {
            v44 = sub_1247A0(2u);
            *(_BYTE *)(a1 + 21 * v23 + 3) += v44 - 1;
          }
        }
        else if ( v21[(int16_t)v49 + 1412] )
        {
          *(_BYTE *)(a1 + 21 * v23 + 3) += 3 * v48;
        }
        else
        {
          *(_BYTE *)(a1 + 21 * v23 + 3) += v48;
        }
        if ( v46 <= 0 )
        {
          if ( !v46 )
          {
            v44 = sub_1247A0(2u);
            *(_BYTE *)(a1 + 21 * v23 + 5) += v44 - 1;
          }
        }
        else if ( v21[(int16_t)v49 + 1412] )
        {
          *(_BYTE *)(a1 + 21 * v23 + 5) += 3 * v46;
        }
        else
        {
          *(_BYTE *)(a1 + 21 * v23 + 5) += v46;
        }
        if ( v45 > 0 && v21[(int16_t)v49 + 1412] )
          *(_BYTE *)(a1 + 21 * v23 + 8) += v45;
        if ( v52 <= 0 )
        {
          if ( v52 )
            goto LABEL_49;
          v34 = a1 + 21 * v23;
          v44 = sub_1247A0(2u);
          v35 = v44 - 1;
        }
        else
        {
          if ( !v21[(int16_t)v49 + 1412] )
          {
            *(_BYTE *)(a1 + 21 * v23 + 13) += v52;
            goto LABEL_49;
          }
          v34 = a1 + 21 * v23;
          v35 = 3 * v52;
        }
        *(_BYTE *)(v34 + 13) += v35;
LABEL_49:
        if ( v51 <= 0 )
        {
          if ( !v51 )
          {
            v44 = sub_1247A0(2u);
            *(_BYTE *)(a1 + 21 * v23 + 15) += v44 - 1;
          }
        }
        else if ( v21[(int16_t)v49 + 1412] )
        {
          *(_BYTE *)(a1 + 21 * v23 + 15) += 3 * v51;
        }
        else
        {
          *(_BYTE *)(a1 + 21 * v23 + 15) += v51;
        }
        if ( v21[(int16_t)v49 + 1412] )
        {
          v56 = 1;
          ++*(_BYTE *)(a1 + 21 * v23 + 10);
          if ( (int16_t)v55 > 0 && (int16_t)v53 > 0 )
          {
            v36 = (int16_t)v53 * (int16_t)v55 / 20;
            goto LABEL_63;
          }
          if ( (int16_t)v55 > 0 )
          {
            v36 = (int)((int16_t)v55
                      - (__CFSHL__((uint64_t)(int16_t)v55 >> 32, 2)
                       + 4 * ((uint64_t)(int16_t)v55 >> 32))) >> 2;
            goto LABEL_63;
          }
          if ( (int16_t)v53 > 0 )
          {
            LOWORD(v36) = (int16_t)v53 / 5;
LABEL_63:
            v56 = v36;
          }
          if ( !v56 )
            v56 = 1;
          *(_BYTE *)(a1 + 21 * v23 + 19) += v56;
        }
LABEL_67:
        v37 = v21[40];
        if ( v37 )
        {
          if ( v37 <= 1u )
          {
            ++*(_BYTE *)(a1 + 21 * v23 + 1);
          }
          else if ( v37 != 3 )
          {
            goto LABEL_73;
          }
          ++*(_BYTE *)(a1 + 21 * v23 + 5);
        }
LABEL_73:
        if ( v21[39] == 2 )
        {
          v38 = 21 * v23;
          ++*(_BYTE *)(a1 + v38 + 1);
          ++*(_BYTE *)(a1 + v38 + 5);
        }
      }
    }
    return result;
  }
}
// DC4E6: variable 'v5' is possibly undefined
// DC4F1: variable 'v6' is possibly undefined
// DC4FC: variable 'v7' is possibly undefined
// DC517: variable 'v9' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17D916: using guessed type int dword_17D916;
// 17E07F: using guessed type int16_t word_17E07F;
// 17F80D: using guessed type int16_t word_17F80D[];
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000DCA69) --------------------------------------------------------
void sub_DCA69()
{
  uint8_t *v0; // ebx
  _BYTE v1[168]; // [esp+0h] [ebp-A8h] BYREF

  dword_1AA1D0 = (int)v1;
  sub_DC47C((int)v1);
  v0 = (uint8_t *)(dword_197F98 + 3753 * word_199998);
  while ( (unsigned int)v0 > dword_197F98 )
  {
    v0 -= 3753;
    if ( !v0[36] && v0[40] != 100 )
    {
      sub_DC288(v0);
      if ( v0[341] == 3 && !v0[2269] )
        sub_5B0AA((int)&v0[-dword_197F98] / 3753);
    }
  }
  dword_1AA1D0 = 0;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 1AA1D0: using guessed type int dword_1AA1D0;


//----- (000DCAEE) --------------------------------------------------------
int __fastcall sub_DCAEE( int a1)
{
  int v2; // edx
  int v3; // eax
  int v4; // ebx

  v2 = 83;
  v3 = 1909;
  v4 = 0;
  do
  {
    --v2;
    v3 -= 23;
    if ( *(_BYTE *)(v2 + 3753 * a1 + dword_197F98 + 196) == 3 && v4 < *(int *)((char *)&dword_17D916 + v3) )
      v4 = *(int *)((char *)&dword_17D916 + v3);
  }
  while ( v2 > 0 );
  return v4 / 25;
}
// 17D916: using guessed type int dword_17D916;
// 197F98: using guessed type int dword_197F98;


//----- (000DCB47) --------------------------------------------------------
int __fastcall sub_DCB47(int a1, int a2)
{
  int v2; // ecx
  unsigned int v3; // ebx
  uint8_t v4; // al
  int16_t v6; // [esp+0h] [ebp-Ch]

  v2 = 0;
  v3 = dword_19306C + 113 * word_19999A;
  while ( v3 > dword_19306C )
  {
    v4 = *(_BYTE *)(v3 - 57);
    v3 -= 113;
    if ( ((uint8_t)(1 << a2) & v4) != 0 )
    {
      if ( ((uint8_t)(1 << v6) & v4) != 0 )
      {
        v2 += 5;
      }
      else if ( sub_FF666(v3, v6) )
      {
        ++v2;
      }
    }
  }
  return v2;
}
// DCB5F: variable 'v6' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (000DCBB0) --------------------------------------------------------
void sub_DCBB0()
{
  _BYTE *v0; // eax
  char *v1; // edx
  char *v2; // ebx
  char v3; // [esp+0h] [ebp-4h]

  v0 = (_BYTE *)(3753 * word_199998 + dword_197F98);
  v1 = v0 + 2207;
  v2 = v0 + 2238;
  while ( (unsigned int)v0 > dword_197F98 )
  {
    v0 -= 3753;
    v1 -= 3753;
    v2 -= 3753;
    if ( v0[2269] )
    {
      if ( !v0[2270] )
      {
        v3 = v0[2207];
        qmemcpy(v1, v2, 0x1Fu);
        v0[2270] = 1;
        v0[2207] = v3;
      }
    }
  }
  JUMPOUT(0xDCA62);
}
// DCC2C: control flows out of bounds to DCA62
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000DCC31) --------------------------------------------------------
char __fastcall sub_DCC31(int a1, int a2)
{
  int16_t v3; // ax
  char v4; // cl
  int16_t v5; // si

  v3 = word_199998;
  v4 = 0;
  v5 = 0;
  while ( v3 > 0 )
  {
    if ( *(_BYTE *)(--v3 + a1 + 1583) )
      v5 += *(_WORD *)(2 * v3 + a1 + 1444);
  }
  if ( v5 >= 0 && (int16_t)sub_101B3C(a1, a2) < *(int16_t *)(a1 + 178) )
    return 1;
  return v4;
}
// 199998: using guessed type int16_t word_199998;


//----- (000DCC83) --------------------------------------------------------
void __fastcall sub_DCC83(int a1, int a2)
{
  int16_t v3; // ax
  int16_t v4; // si

  v3 = word_199998;
  v4 = 0;
  while ( v3 > 0 )
  {
    if ( *(_BYTE *)(--v3 + a1 + 1591) )
      v4 += *(_WORD *)(2 * v3 + a1 + 1478);
  }
  if ( v4 >= 0 )
  {
    sub_101C93(a1, a2);
    JUMPOUT(0xDCC78);
  }
  JUMPOUT(0xDCC7C);
}
// DCCCA: control flows out of bounds to DCC78
// DCCB7: control flows out of bounds to DCC7C
// 199998: using guessed type int16_t word_199998;


//----- (000DCCCC) --------------------------------------------------------
int __fastcall sub_DCCCC(char *a1)
{
  int v2; // eax
  int v3; // edi
  int v4; // esi
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v9; // [esp+4h] [ebp-14h]
  int v10; // [esp+8h] [ebp-10h]
  int v11; // [esp+Ch] [ebp-Ch]
  char v12; // [esp+14h] [ebp-4h]

  v11 = *a1;
  v2 = 113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 2);
  v3 = v2 + dword_19306C;
  v4 = *(char *)(v2 + dword_19306C + v11 + 66);
  v10 = -1;
  if ( v4 != -1 )
  {
    v5 = v3 + 10;
    v12 = 0;
    v9 = v2 + dword_19306C;
    do
    {
      v6 = *(int16_t *)(v5 + 72);
      v5 -= 2;
      if ( v6 != -1 )
      {
        v7 = *(int16_t *)(dword_1930D4 + 17 * v6);
        if ( v7 != -1 && *(char *)(dword_192B18 + 361 * v7) == v11 && (int)&a1[-dword_192B18] / 361 != v7 )
          v12 = 1;
      }
    }
    while ( v5 != v9 );
    if ( !v12 )
    {
      if ( *(char *)(dword_1930DC + 59 * v4 + 55) <= 0 )
      {
        sub_941C6(v4, v3);
        v10 = v4;
      }
      else
      {
        sub_944A3(v4, v3);
      }
      *(_BYTE *)(v11 + v3 + 66) = -1;
    }
  }
  return v10;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;


//----- (000DCDAC) --------------------------------------------------------
void __fastcall sub_DCDAC(char *a1, int a2)
{
  int16_t v3; // si
  _BYTE *v4; // eax
  int v5; // [esp+0h] [ebp-18h] BYREF
  int v6; // [esp+4h] [ebp-14h]
  int v7; // [esp+8h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-Ch]
  int16_t v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v10 = 113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 2) + dword_19306C;
  sub_2401F((int)&a1[-dword_192B18] / 361);
  v3 = sub_DCCCC(a1);
  if ( a2 != -1 )
  {
    memset(&v5, 0, 18);
    LOBYTE(v5) = 7;
    HIWORD(v5) = *((_WORD *)a1 + 1);
    LOWORD(v6) = a2;
    HIWORD(v6) = v3;
    LOBYTE(v7) = a1[6];
    sub_EF629(v5, v6, v7, v8, v9, *a1);
  }
  if ( *(_WORD *)(dword_197F98 + 3753 * *a1 + 41) == *((_WORD *)a1 + 1) )
    sub_ECB65(*a1, (int)&a1[-dword_192B18] / 361);
  sub_B20A1((int)&a1[-dword_192B18] / 361);
  *(_WORD *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1)) = -1;
  memset(a1, 0, 361);
  *a1 = -1;
  v4 = (_BYTE *)v10;
  *((_WORD *)a1 + 1) = -1;
  sub_E5296(v4);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000DCEBD) --------------------------------------------------------
int __fastcall sub_DCEBD(char *a1, char *a2, int a3)
{
  int v5; // edi
  int result; // eax
  int v7; // ebx
  char *v8; // edi
  signed int v9; // edx
  int v10; // edi
  int v11; // ebx
  char *v12; // eax
  signed int v13; // ebx
  int v14; // ebx
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  int v18; // ebx
  _BYTE v19[52]; // [esp+0h] [ebp-44h]
  int v20; // [esp+34h] [ebp-10h]
  _BYTE *v21; // [esp+38h] [ebp-Ch]
  signed int v22; // [esp+3Ch] [ebp-8h]
  unsigned int v23; // [esp+40h] [ebp-4h]

  v20 = a3;
  v5 = 3753 * *a1;
  result = 0;
  v23 = 0;
  v21 = (_BYTE *)(v5 + dword_197F98);
  v7 = 49;
  v22 = 0;
  v8 = a1 + 49;
  do
  {
    --v8;
    --v7;
    if ( v8[310] && v7 != 9 && v7 != 26 && v7 != 27 && v7 != 42 && v7 != 47 && v7 != 8 && v7 != 40 && v7 != 41 )
    {
      v9 = v22++;
      v19[v9] = v7;
    }
  }
  while ( v7 > 0 );
  v10 = *((int16_t *)a1 + 152);
  v11 = *((int16_t *)a1 + 153);
  v23 += v22;
  v23 += v10 + v11;
  if ( *(_WORD *)(a1 + 293) )
    ++v23;
  if ( a1[10] == 1 )
  {
    if ( !v23 )
    {
      v12 = &a1[2 * (*((_DWORD *)a1 + 3) & 0xF)];
      if ( *((int16_t *)v12 + 90) > 100 )
      {
        *((_WORD *)v12 + 90) -= 100;
      }
      else
      {
        ++*((_WORD *)a2 + 6);
        *(_WORD *)&a1[2 * (*((_DWORD *)a1 + 3) & 0xF) + 180] = 0;
        a1[10] = 0;
        if ( a1[319] )
          sub_145EA((int)&a1[-dword_192B18] / 361, 9u, v10);
        a2[66] = 1;
        *(_WORD *)(3753 * *a1 + dword_197F98 + 2 * *a2 + 1791) += 10;
      }
      result = 1;
      a2[65] = 1;
    }
  }
  else
  {
    v23 += (uint8_t)a1[10];
  }
  if ( !result && v23 )
  {
    v13 = sub_1247A0(v23) - 1;
    if ( v13 < v22 )
    {
      sub_145EA((int)&a1[-dword_192B18] / 361, (uint8_t)v19[v13], (uint8_t)v19[v13]);
      a2[(uint8_t)v19[v13] + 14] = 1;
LABEL_46:
      result = 1;
      a2[65] = 1;
      return result;
    }
    v14 = v13 - v22;
    v15 = *((int16_t *)a1 + 152);
    if ( v14 >= v15 )
    {
      v16 = v14 - v15;
      v17 = *((int16_t *)a1 + 153);
      if ( v16 >= v17 )
      {
        v18 = v16 - v17;
        if ( v18 >= *(int16_t *)(a1 + 293) )
        {
          ++*((_WORD *)a2 + 6);
          *(_DWORD *)&a1[4 * v18 + 12] = *(_DWORD *)&a1[4 * (uint8_t)--a1[10] + 12];
          ++*(_WORD *)(dword_197F98 + 3753 * *a1 + 2 * *a2 + 1791);
        }
        else
        {
          *(_WORD *)(a2 + 67) = *(_WORD *)(a1 + 293);
          *(_WORD *)(a1 + 293) = 0;
        }
        goto LABEL_46;
      }
      result = 2;
      if ( v21[303] == 3 )
        result = 3;
      if ( v21[2218] )
        ++result;
      if ( result <= v20 )
      {
        --*((_WORD *)a1 + 153);
        a2[65] = 1;
        ++*((_WORD *)a2 + 5);
        return result;
      }
    }
    else
    {
      result = 1;
      if ( v21[423] == 3 )
        result = 2;
      if ( v21[2218] )
        ++result;
      if ( result <= v20 )
      {
        --*((_WORD *)a1 + 152);
        a2[65] = 1;
        ++*((_WORD *)a2 + 4);
        return result;
      }
    }
    return 0;
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000DD13E) --------------------------------------------------------
void __fastcall sub_DD13E(char *a1, char *a2)
{
  int v3; // esi
  int v4; // edi
  char *v5; // ecx
  int v6; // eax
  signed int v7; // ecx
  signed int v8; // ecx
  signed int v9; // ecx
  int v10; // esi
  char v11; // cl
  char *v12; // eax
  int v13; // eax
  int v14; // [esp+0h] [ebp-4h]

  v3 = (uint8_t)a1[10];
  v14 = -1;
  v4 = 0;
  v5 = &a1[4 * v3];
  while ( v3 > 0 )
  {
    v6 = *((_DWORD *)v5 + 2);
    v5 -= 4;
    --v3;
    if ( (v6 & 0xF) != 8 && sub_1247A0(++v4) == 1 )
      v14 = v3;
  }
  if ( v14 >= 0 )
  {
    a2[65] = 1;
    if ( (uint8_t)a1[10] >= 2u )
    {
      v7 = (uint8_t)a1[10];
      if ( (int)sub_1247A0(v7 + *((int16_t *)a1 + 152) + *((int16_t *)a1 + 153)) <= v7 )
      {
        ++*((_WORD *)a2 + 6);
        ++*(_WORD *)(a2 + 63);
        *(_DWORD *)&a1[4 * v14 + 12] = *(_DWORD *)&a1[4 * (uint8_t)--a1[10] + 12];
        ++*(_WORD *)(3753 * *a1 + dword_197F98 + 2 * *a2 + 1791);
        goto LABEL_25;
      }
      if ( *((_WORD *)a1 + 152) )
      {
        v8 = *((int16_t *)a1 + 152);
        if ( (int)sub_1247A0(v8 + *((int16_t *)a1 + 153)) <= v8 )
          goto LABEL_12;
      }
LABEL_13:
      --*((_WORD *)a1 + 153);
      ++*((_WORD *)a2 + 5);
      goto LABEL_25;
    }
    if ( *((_WORD *)a1 + 152) )
    {
      v9 = *((int16_t *)a1 + 152);
      if ( (int)sub_1247A0(v9 + *((int16_t *)a1 + 153)) <= v9 )
      {
LABEL_12:
        --*((_WORD *)a1 + 152);
        ++*((_WORD *)a2 + 4);
        goto LABEL_25;
      }
    }
    if ( *((_WORD *)a1 + 153) )
      goto LABEL_13;
    if ( *(int16_t *)&a1[2 * (*((_DWORD *)a1 + 3) & 0xF) + 180] > 100 )
    {
      v13 = *(_DWORD *)&a1[4 * v14 + 12] & 0xF;
      *(_WORD *)&a1[2 * v13 + 180] -= 100;
    }
    else
    {
      ++*((_WORD *)a2 + 6);
      ++*(_WORD *)(a2 + 63);
      v10 = 49;
      v11 = 0;
      *(_WORD *)&a1[2 * (*((_DWORD *)a1 + 3) & 0xF) + 180] = 0;
      v12 = a1 + 49;
      a1[10] = 0;
      do
      {
        if ( v10 <= 0 )
          goto LABEL_20;
        --v12;
        --v10;
      }
      while ( !v12[310] );
      v11 = 1;
LABEL_20:
      if ( !v11 )
      {
        a2[66] = 1;
        *(_WORD *)(3753 * *a1 + dword_197F98 + 2 * *a2 + 1791) += 10;
      }
    }
  }
LABEL_25:
  JUMPOUT(0xDCEB7);
}
// DD1EF: control flows out of bounds to DCEB7
// 197F98: using guessed type int dword_197F98;


//----- (000DD2F2) --------------------------------------------------------
void __fastcall sub_DD2F2(int a1)
{
  int v2; // edi
  int v3; // esi
  int v4; // eax
  char *v5; // [esp+0h] [ebp-4h]

  v2 = *(int16_t *)(a1 + 6);
  v5 = (char *)(361 * *(uint8_t *)(a1 + 1) + dword_192B18);
  v3 = *(int16_t *)(a1 + 3);
  while ( v3 + v2 > 0 )
  {
    if ( v2 )
    {
      sub_DD13E(v5, (char *)a1);
      --v2;
    }
    else
    {
      v4 = sub_DCEBD(v5, (char *)a1, v3);
      if ( v4 )
      {
        v3 -= v4;
        *(_DWORD *)(a1 + 69) += v4;
      }
      else
      {
        v3 = 0;
      }
    }
  }
  JUMPOUT(0xDCDA5);
}
// DD31F: control flows out of bounds to DCDA5
// 192B18: using guessed type int dword_192B18;


//----- (000DD351) --------------------------------------------------------
int __fastcall sub_DD351( int a1, char *a2)
{
  int v3; // eax
  int result; // eax

  if ( *(_DWORD *)(dword_1AA250 + 1148) == 14 )
  {
    memmove(dword_1AA250, dword_1AA250 + 82, 1066);
    *(_DWORD *)(dword_1AA250 + 1148) = 13;
  }
  v3 = dword_1AA250;
  *(_BYTE *)(82 * *(_DWORD *)(dword_1AA250 + 1148) + dword_1AA250) = a1;
  strcpy((char *)(82 * *(_DWORD *)(v3 + 1148) + v3 + 1), a2);
  result = dword_1AA250;
  ++*(_DWORD *)(dword_1AA250 + 1148);
  return result;
}
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 1AA250: using guessed type int dword_1AA250;


//----- (000DD3B8) --------------------------------------------------------
int __fastcall sub_DD3B8(char *a1)
{
  int result; // eax
  int v3; // eax
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v5 = word_199998;
  result = 3753 * word_199998;
  v4 = result;
  while ( v4 > 0 )
  {
    v4 -= 3753;
    result = v4 + dword_197F98;
    --v5;
    if ( *(_BYTE *)(v4 + dword_197F98 + 40) == 100 )
    {
      v3 = sub_F6816(*(int16_t *)(v4 + dword_197F98 + 43), 39, (int)a1, strlen(a1) + 1);
      result = sub_FE8BE(v3);
    }
  }
  return result;
}
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000DD42A) --------------------------------------------------------
void __fastcall sub_DD42A(char *a1)
{
  unsigned int v2; // kr04_4
  int16_t v3; // ax
  int v4; // eax
  int v5; // [esp+0h] [ebp-Ch]
  _BYTE *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v5 = word_199998;
  v6 = a1 + 80;
  v7 = 3753 * word_199998;
  while ( v7 > 0 )
  {
    v7 -= 3753;
    --v5;
    if ( *(_BYTE *)(v7 + dword_197F98 + 40) == 100 )
    {
      v2 = strlen(a1) + 1;
      v3 = v2 - 1;
      if ( (int)(v2 - 1) > 80 )
      {
        v3 = 80;
        *v6 = 0;
      }
      v4 = sub_F6816(*(int16_t *)(v7 + dword_197F98 + 43), 45, (int)a1, v3 + 1);
      sub_FE8BE(v4);
    }
  }
  JUMPOUT(0xDD423);
}
// DD4B0: control flows out of bounds to DD423
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000DD4FD) --------------------------------------------------------
unsigned int __fastcall sub_DD4FD(char *a1)
{
  dword_1AA31C = (int)a1;
  dword_1AA32C = (int)&a1[strlen(a1) + 1];
  dword_1AA2FC = strlen((char *)dword_1AA32C) + 1 + dword_1AA32C;
  dword_1AA308 = strlen((char *)dword_1AA2FC) + 1 + dword_1AA2FC;
  dword_1AA320 = strlen((char *)dword_1AA308) + 1 + dword_1AA308;
  dword_1AA314 = strlen((char *)dword_1AA320) + 1 + dword_1AA320;
  dword_1AA30C = strlen((char *)dword_1AA314) + 1 + dword_1AA314;
  dword_1AA328 = strlen((char *)dword_1AA30C) + 1 + dword_1AA30C;
  dword_1AA324 = strlen((char *)dword_1AA328) + 1 + dword_1AA328;
  dword_1AA310 = strlen((char *)dword_1AA324) + 1 + dword_1AA324;
  dword_1AA304 = strlen((char *)dword_1AA310) + 1 + dword_1AA310;
  dword_1AA33C = strlen((char *)dword_1AA304) + 1 + dword_1AA304;
  dword_1AA318 = strlen((char *)dword_1AA33C) + 1 + dword_1AA33C;
  dword_1AA300 = strlen((char *)dword_1AA318) + 1 + dword_1AA318;
  dword_1AA2F4 = strlen((char *)dword_1AA300) + 1 + dword_1AA300;
  dword_1AA2F8 = strlen((char *)dword_1AA2F4) + 1 + dword_1AA2F4;
  dword_1AA330 = strlen((char *)dword_1AA2F8) + 1 + dword_1AA2F8;
  dword_1AA338 = strlen((char *)dword_1AA330) + 1 + dword_1AA330;
  dword_1AA334 = strlen((char *)dword_1AA338) + 1 + dword_1AA338;
  dword_1AA340 = strlen((char *)dword_1AA334) + 1 + dword_1AA334;
  dword_1AA2D0 = strlen((char *)dword_1AA340) + 1 + dword_1AA340;
  dword_1AA2E4 = strlen((char *)dword_1AA2D0) + 1 + dword_1AA2D0;
  dword_1AA290 = strlen((char *)dword_1AA2E4) + 1 + dword_1AA2E4;
  dword_1AA2CC = strlen((char *)dword_1AA290) + 1 + dword_1AA290;
  dword_1AA2EC = strlen((char *)dword_1AA2CC) + 1 + dword_1AA2CC;
  dword_1AA294 = strlen((char *)dword_1AA2EC) + 1 + dword_1AA2EC;
  dword_1AA2A8 = strlen((char *)dword_1AA294) + 1 + dword_1AA294;
  dword_1AA2BC = strlen((char *)dword_1AA2A8) + 1 + dword_1AA2A8;
  dword_1AA2C4 = strlen((char *)dword_1AA2BC) + 1 + dword_1AA2BC;
  dword_1AA2E8 = strlen((char *)dword_1AA2C4) + 1 + dword_1AA2C4;
  dword_1AA2C8 = strlen((char *)dword_1AA2E8) + 1 + dword_1AA2E8;
  dword_1AA2D4 = strlen((char *)dword_1AA2C8) + 1 + dword_1AA2C8;
  dword_1AA2B0 = strlen((char *)dword_1AA2D4) + 1 + dword_1AA2D4;
  dword_1AA2B8 = strlen((char *)dword_1AA2B0) + 1 + dword_1AA2B0;
  dword_1AA2A4 = strlen((char *)dword_1AA2B8) + 1 + dword_1AA2B8;
  dword_1AA298 = strlen((char *)dword_1AA2A4) + 1 + dword_1AA2A4;
  dword_1AA2AC = strlen((char *)dword_1AA298) + 1 + dword_1AA298;
  dword_1AA2D8 = strlen((char *)dword_1AA2AC) + 1 + dword_1AA2AC;
  dword_1AA29C = strlen((char *)dword_1AA2D8) + 1 + dword_1AA2D8;
  dword_1AA2C0 = strlen((char *)dword_1AA29C) + 1 + dword_1AA29C;
  dword_1AA2DC = strlen((char *)dword_1AA2C0) + 1 + dword_1AA2C0;
  dword_1AA2A0 = strlen((char *)dword_1AA2DC) + 1 + dword_1AA2DC;
  dword_1AA2E0 = strlen((char *)dword_1AA2A0) + 1 + dword_1AA2A0;
  dword_1AA2F0 = strlen((char *)dword_1AA2E0) + 1 + dword_1AA2E0;
  dword_1AA2B4 = strlen((char *)dword_1AA2F0) + 1 + dword_1AA2F0;
  dword_1AA260 = strlen((char *)dword_1AA2B4) + 1 + dword_1AA2B4;
  dword_1AA288 = strlen((char *)dword_1AA260) + 1 + dword_1AA260;
  dword_1AA258 = strlen((char *)dword_1AA288) + 1 + dword_1AA288;
  dword_1AA28C = strlen((char *)dword_1AA258) + 1 + dword_1AA258;
  dword_1AA270 = strlen((char *)dword_1AA28C) + 1 + dword_1AA28C;
  dword_1AA264 = strlen((char *)dword_1AA270) + 1 + dword_1AA270;
  dword_1AA274 = strlen((char *)dword_1AA264) + 1 + dword_1AA264;
  dword_1AA284 = strlen((char *)dword_1AA274) + 1 + dword_1AA274;
  dword_1AA254 = strlen((char *)dword_1AA284) + 1 + dword_1AA284;
  dword_1AA26C = strlen((char *)dword_1AA254) + 1 + dword_1AA254;
  dword_1AA280 = strlen((char *)dword_1AA26C) + 1 + dword_1AA26C;
  dword_1AA27C = strlen((char *)dword_1AA280) + 1 + dword_1AA280;
  dword_1AA268 = strlen((char *)dword_1AA27C) + 1 + dword_1AA27C;
  dword_1AA278 = strlen((char *)dword_1AA268) + 1 + dword_1AA268;
  dword_1AA25C = strlen((char *)dword_1AA278) + 1 + dword_1AA278;
  return dword_1AA25C + strlen((char *)dword_1AA25C) + 1;
}
// 1AA254: using guessed type int dword_1AA254;
// 1AA258: using guessed type int dword_1AA258;
// 1AA25C: using guessed type int dword_1AA25C;
// 1AA260: using guessed type int dword_1AA260;
// 1AA264: using guessed type int dword_1AA264;
// 1AA268: using guessed type int dword_1AA268;
// 1AA26C: using guessed type int dword_1AA26C;
// 1AA270: using guessed type int dword_1AA270;
// 1AA274: using guessed type int dword_1AA274;
// 1AA278: using guessed type int dword_1AA278;
// 1AA27C: using guessed type int dword_1AA27C;
// 1AA280: using guessed type int dword_1AA280;
// 1AA284: using guessed type int dword_1AA284;
// 1AA288: using guessed type int dword_1AA288;
// 1AA28C: using guessed type int dword_1AA28C;
// 1AA290: using guessed type int dword_1AA290;
// 1AA294: using guessed type int dword_1AA294;
// 1AA298: using guessed type int dword_1AA298;
// 1AA29C: using guessed type int dword_1AA29C;
// 1AA2A0: using guessed type int dword_1AA2A0;
// 1AA2A4: using guessed type int dword_1AA2A4;
// 1AA2A8: using guessed type int dword_1AA2A8;
// 1AA2AC: using guessed type int dword_1AA2AC;
// 1AA2B0: using guessed type int dword_1AA2B0;
// 1AA2B4: using guessed type int dword_1AA2B4;
// 1AA2B8: using guessed type int dword_1AA2B8;
// 1AA2BC: using guessed type int dword_1AA2BC;
// 1AA2C0: using guessed type int dword_1AA2C0;
// 1AA2C4: using guessed type int dword_1AA2C4;
// 1AA2C8: using guessed type int dword_1AA2C8;
// 1AA2CC: using guessed type int dword_1AA2CC;
// 1AA2D0: using guessed type int dword_1AA2D0;
// 1AA2D4: using guessed type int dword_1AA2D4;
// 1AA2D8: using guessed type int dword_1AA2D8;
// 1AA2DC: using guessed type int dword_1AA2DC;
// 1AA2E0: using guessed type int dword_1AA2E0;
// 1AA2E4: using guessed type int dword_1AA2E4;
// 1AA2E8: using guessed type int dword_1AA2E8;
// 1AA2EC: using guessed type int dword_1AA2EC;
// 1AA2F0: using guessed type int dword_1AA2F0;
// 1AA2F4: using guessed type int dword_1AA2F4;
// 1AA2F8: using guessed type int dword_1AA2F8;
// 1AA2FC: using guessed type int dword_1AA2FC;
// 1AA300: using guessed type int dword_1AA300;
// 1AA304: using guessed type int dword_1AA304;
// 1AA308: using guessed type int dword_1AA308;
// 1AA30C: using guessed type int dword_1AA30C;
// 1AA310: using guessed type int dword_1AA310;
// 1AA314: using guessed type int dword_1AA314;
// 1AA318: using guessed type int dword_1AA318;
// 1AA31C: using guessed type int dword_1AA31C;
// 1AA320: using guessed type int dword_1AA320;
// 1AA324: using guessed type int dword_1AA324;
// 1AA328: using guessed type int dword_1AA328;
// 1AA32C: using guessed type int dword_1AA32C;
// 1AA330: using guessed type int dword_1AA330;
// 1AA334: using guessed type int dword_1AA334;
// 1AA338: using guessed type int dword_1AA338;
// 1AA33C: using guessed type int dword_1AA33C;
// 1AA340: using guessed type int dword_1AA340;


//----- (000DD9F2) --------------------------------------------------------
int __fastcall sub_DD9F2(char *a1)
{
  int result; // eax

  result = *(char *)(113 * *(uint8_t *)(17 * *((int16_t *)a1 + 1) + dword_1930D4 + 2) + dword_19306C + *a1 + 66);
  if ( result != -1 )
  {
    if ( *(_BYTE *)(59 * result + dword_1930DC + 55) )
      return -1;
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;


//----- (000DDA36) --------------------------------------------------------
void __fastcall sub_DDA36(int a1, int a2)
{
  int v2; // ebx
  int v3; // esi
  int v4; // edi
  int i; // ebx
  char *v6; // [esp+4h] [ebp-4h]

  v2 = a1;
  if ( a1 >= 0 )
  {
    byte_1AA344 = 43;
  }
  else
  {
    byte_1AA344 = 45;
    v2 = -a1;
  }
  v6 = (char *)&unk_1AA345 + sprintf(&unk_1AA345, "%d", v2 / a2);
  v3 = v2 % a2;
  if ( v2 % a2 )
  {
    v4 = 1;
    for ( i = 10; a2 * (v3 * i / a2) != v3 * i && v4 < 5; i *= 10 )
      ++v4;
    if ( i )
      sprintf(v6, ".%d", v3 * i / a2);
  }
  JUMPOUT(0xDEB17);
}
// DDACF: control flows out of bounds to DEB17
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 1AA344: using guessed type char byte_1AA344;


//----- (000DDAD4) --------------------------------------------------------
int __fastcall sub_DDAD4(int a1)
{
  int v1; // ebx
  int v2; // ecx
  int v3; // edx
  int v5; // eax
  int v6; // eax

  if ( *(_BYTE *)(a1 + 10) >= 2u && !*(_BYTE *)(a1 + 311) )
  {
    v1 = *(uint8_t *)(a1 + 10);
    v2 = -1;
    v3 = a1 + 4 * v1;
    while ( v1 > 0 )
    {
      v5 = *(_DWORD *)(v3 + 8);
      v3 -= 4;
      v6 = v5 & 0xF;
      --v1;
      if ( v6 < 8 )
      {
        if ( v2 == -1 )
        {
          v2 = v6;
        }
        else if ( v6 != v2 )
        {
          return -4;
        }
      }
    }
  }
  return 0;
}


//----- (000DDB25) --------------------------------------------------------
void __fastcall sub_DDB25(char *a1, char *a2)
{
  int v4; // ecx
  unsigned int v5; // esi
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  char *v13; // edi
  char *v14; // edi
  char *v15; // edi
  char *v16; // [esp+0h] [ebp-2Ch]
  int v17; // [esp+8h] [ebp-24h]
  int v18; // [esp+Ch] [ebp-20h]
  int v19; // [esp+10h] [ebp-1Ch]
  int v20; // [esp+14h] [ebp-18h]
  int v21; // [esp+18h] [ebp-14h]
  int v22; // [esp+1Ch] [ebp-10h]
  int v23; // [esp+20h] [ebp-Ch]
  int v24; // [esp+24h] [ebp-8h]
  int v25; // [esp+28h] [ebp-4h]

  v4 = 3753 * *a1 + dword_197F98;
  v17 = 0;
  v24 = 0;
  v19 = 0;
  v25 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v5 = *(char *)(v4 + 2207) / 2;
  v22 = 0;
  v18 = sub_DDAD4((int)a1);
  v16 = (char *)&unk_179F5F;
  a1[7] = byte_DD4C4[*(char *)(v4 + 2207)];
  if ( v5 == 3 )
    goto LABEL_31;
  v6 = sub_DD9F2(a1);
  if ( v6 != -1 )
  {
    v7 = 59 * v6 + dword_1930DC;
    if ( *(char *)(v7 + 43) < 0 )
    {
      v8 = (3 * (int16_t)sub_94951(v6) + 4) / 2;
LABEL_7:
      v25 = v8;
      goto LABEL_8;
    }
    if ( (*(_BYTE *)(v7 + 43) & 0x40) != 0 )
    {
      v8 = (int16_t)sub_94951(v6) + 1;
      goto LABEL_7;
    }
  }
LABEL_8:
  if ( a1[330] )
    v9 = 4;
  else
    v9 = 0;
  v17 = v9;
  if ( *(_BYTE *)(v4 + 474) == 3 )
    v10 = 4;
  else
    v10 = 0;
  v24 = v10;
  if ( a1[341] )
    v11 = 6;
  else
    v11 = 0;
  v19 = v11;
  if ( *(char *)(3753 * *a1 + dword_197F98 + 2207) / 2 != 3 )
  {
    v12 = *(int16_t *)(v4 + 41);
    if ( v12 == -1 || !*(_BYTE *)(dword_192B18 + 361 * *(int16_t *)(dword_1930D4 + 17 * v12) + 319) )
      v20 = byte_DD4CC[*(char *)(3753 * *a1 + dword_197F98 + 2207) / 2];
  }
  if ( v5 <= 1 && *(_BYTE *)(v4 + 426) == 3 )
    v23 = 2;
  if ( a1[332] )
  {
    v22 = (uint8_t)byte_DD4CF[*(char *)(v4 + 2207)];
  }
  else if ( a1[312] )
  {
    v21 = (uint8_t)byte_DD4CF[*(char *)(v4 + 2207)];
  }
  else if ( v5 <= 1 )
  {
    v16 = (char *)dword_1AA32C;
  }
  a1[7] += v18 + v25 + v19 + v24 + v17;
  a1[7] += v23;
  a1[7] += v22 + v21;
  a1[7] += v20;
LABEL_31:
  if ( a2 )
  {
    if ( v5 != 3 )
    {
      v13 = &a2[sprintf(a2, "%s", aT1565)];
      v14 = &v13[sprintf(v13, "%s", byte_179F6E)];
      v15 = &v14[sprintf(v14, "\t%+d%%\t%s%s\r", 5 * byte_DD4C4[*(char *)(v4 + 2207)], (char *)dword_1AA308, v16)];
      if ( v20 )
        v15 += sprintf(v15, "\t%+d%%\t%s\r", 5 * v20, (char *)dword_1AA320);
      if ( v18 )
        v15 += sprintf(v15, "\t%d%%\t%s\r", 5 * v18, (char *)dword_1AA314);
      if ( v21 )
        v15 += sprintf(v15, "\t%+d%%\t%s\r", 5 * v21, (char *)off_17EB63);
      if ( v22 )
        v15 += sprintf(v15, "\t%+d%%\t%s\r", 5 * v22, (char *)off_17ECDF);
      if ( v23 )
        v15 += sprintf(v15, "\t%+d%%\t%s\r", 5 * v23, (char *)off_17E7F0);
      if ( v17 )
        v15 += sprintf(v15, "\t%+d%%\t%s\r", 5 * v17, (char *)off_17ECB9);
      if ( v24 )
        v15 += sprintf(v15, "\t%+d%%\t%s\r", 5 * v24, (char *)off_17EA60);
      if ( v19 )
        v15 += sprintf(v15, "\t%+d%%\t%s\r", 5 * v19, (char *)off_17ED8A);
      if ( v25 )
        v15 += sprintf(v15, "\t%+d%%\t%s\r", 5 * v25, (char *)dword_1AA328);
      sprintf(v15, asc_179F93);
      JUMPOUT(0xDEB0E);
    }
    strcpy(a2, (char *)dword_1AA2FC);
  }
  JUMPOUT(0xDEB17);
}
// DDD50: control flows out of bounds to DEB17
// DDEF6: control flows out of bounds to DEB0E
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 17E7F0: using guessed type _UNKNOWN *off_17E7F0;
// 17EA60: using guessed type _UNKNOWN *off_17EA60;
// 17EB63: using guessed type _UNKNOWN *off_17EB63;
// 17ECB9: using guessed type _UNKNOWN *off_17ECB9;
// 17ECDF: using guessed type _UNKNOWN *off_17ECDF;
// 17ED8A: using guessed type _UNKNOWN *off_17ED8A;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 1AA2FC: using guessed type int dword_1AA2FC;
// 1AA308: using guessed type int dword_1AA308;
// 1AA314: using guessed type int dword_1AA314;
// 1AA320: using guessed type int dword_1AA320;
// 1AA324: using guessed type int dword_1AA324;
// 1AA328: using guessed type int dword_1AA328;
// 1AA32C: using guessed type int dword_1AA32C;


//----- (000DDEFB) --------------------------------------------------------
int16_t __fastcall sub_DDEFB( int a1)
{
  char v2[2000]; // [esp+0h] [ebp-7D0h] BYREF

  sub_DDB25((char *)(361 * a1 + dword_192B18), v2);
  return sub_A5EB2(dword_1AA310, (int)v2);
}
// 192B18: using guessed type int dword_192B18;
// 1AA310: using guessed type int dword_1AA310;


//----- (000DDF2C) --------------------------------------------------------
int __fastcall sub_DDF2C(int a1, int a2, int a3)
{
  uint8_t v3; // al

  if ( *(_BYTE *)(a1 + 335) || a2 >= 8 )
    return 4;
  v3 = *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(a1 + 2) + 6);
  if ( !v3 )
  {
    if ( *(_BYTE *)(3753 * a2 + dword_197F98 + 2217) )
      return 4;
    return 3;
  }
  if ( v3 <= 1u )
  {
    if ( !*(_BYTE *)(dword_197F98 + 3753 * a2 + 2217) )
      return 4;
    return 3;
  }
  if ( v3 != 2 )
    return a3;
  if ( !*(_BYTE *)(dword_197F98 + 3753 * a2 + 2218) )
    return 2;
  return 4;
}
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000DDFD3) --------------------------------------------------------
void __fastcall sub_DDFD3(char *a1, int a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // [esp+0h] [ebp-8h]

  v3 = ((int (__fastcall *)(char *, int16_t, int16_t, int))funcs_DDFF0[a3])(a1, *a1, *(_DWORD *)a2 & 0xF, 0);
  if ( (int16_t)v3 > 0 )
  {
    if ( (*(_BYTE *)(a2 + 1) & 4) != 0 )
      v4 = 3 * v3;
    else
      v4 = 4 * v3;
    sub_DDF2C(v5, *(_WORD *)a2 & 0xF, v4);
  }
  JUMPOUT(0xE0B48);
}
// DE039: control flows out of bounds to E0B48
// DE01A: variable 'v5' is possibly undefined
// 18355C: using guessed type int (*funcs_DDFF0[3])();


//----- (000DE03E) --------------------------------------------------------
int __fastcall sub_DE03E(int a1, int a2, int a3)
{
  int v4; // edx
  int v5; // edx

  v4 = 17 * *(int16_t *)(a1 + 2);
  LOWORD(v4) = *(uint8_t *)(v4 + dword_1930D4 + 11);
  v5 = 2 * v4;
  if ( a3 )
    *(_DWORD *)a3 = (int16_t)v5;
  if ( !(_WORD)v5 && *(_BYTE *)(3753 * a2 + dword_197F98 + 308) == 3 )
  {
    v5 = 2;
    if ( a3 )
      *(_WORD *)(a3 + 82) = 2;
  }
  if ( (int16_t)v5 > 0 )
  {
    if ( *(_BYTE *)(a1 + 356) )
    {
      v5 += 4;
      if ( a3 )
        *(_WORD *)(a3 + 540) = 4;
    }
    if ( *(_BYTE *)(a1 + 314) )
    {
      v5 += 2;
      if ( a3 )
        *(_WORD *)(a3 + 456) = 2;
    }
  }
  return v5;
}
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000DE0C6) --------------------------------------------------------
int __fastcall sub_DE0C6(char *a1, int a2, int a3, int a4)
{
  int16_t v6; // ax
  int16_t v7; // dx
  int v8; // ebx
  int v9; // esi
  uint8_t v10; // al
  int v11; // eax
  int v12; // ebx
  int v14; // [esp+0h] [ebp-8h]

  if ( *a1 != a2 || a4 )
    v6 = sub_DE03E((int)a1, a2, a4);
  else
    v6 = (uint8_t)a1[221];
  LOWORD(v14) = v6;
  if ( v6 > 0 )
  {
    if ( a1 != (char *)dword_183568 || (uint8_t)byte_18356C != a2 || a4 )
    {
      memset(byte_1AA358, 99, sizeof(byte_1AA358));
      dword_183568 = (int)a1;
      byte_18356C = a2;
    }
    if ( byte_1AA358[a3] != 99 )
    {
      LOWORD(v14) = byte_1AA358[a3];
      return v14;
    }
    v7 = 0;
    v8 = 0;
    if ( a3 >= 8 )
    {
      if ( a3 == 8 )
      {
        v7 = 6;
      }
      else if ( a3 == 9 )
      {
        v7 = 4;
      }
      goto LABEL_26;
    }
    v9 = 3753 * a3;
    v7 = *(char *)(v9 + dword_197F98 + 2209);
    if ( *(_BYTE *)(v9 + dword_197F98 + 2219) )
    {
      v10 = *(_BYTE *)(dword_183568 + 226);
      if ( v10 >= 5u )
      {
        if ( v10 <= 5u )
        {
LABEL_21:
          v11 = (uint8_t)byte_17D81C[*(uint8_t *)(dword_183568 + 226)];
          v12 = (uint8_t)byte_17D825;
          goto LABEL_20;
        }
        if ( v10 > 6u )
        {
          if ( v10 != 8 )
            goto LABEL_26;
          goto LABEL_21;
        }
LABEL_19:
        v11 = (uint8_t)byte_17D81C[*(uint8_t *)(dword_183568 + 226)];
        v12 = (uint8_t)byte_17D824;
LABEL_20:
        v8 = 2 * (v12 - v11);
        goto LABEL_26;
      }
      if ( v10 == 4 )
        goto LABEL_19;
    }
LABEL_26:
    if ( a4 )
    {
      *(_WORD *)(a4 + 2 * a3 + 4) = v7;
      *(_DWORD *)(a4 + 546) = v8;
    }
    LOWORD(v14) = v8 + v7 + v14;
    byte_1AA358[a3] = v14;
  }
  return v14;
}
// DE225: variable 'v14' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17D824: using guessed type char byte_17D824;
// 17D825: using guessed type char byte_17D825;
// 183568: using guessed type int dword_183568;
// 18356C: using guessed type char byte_18356C;
// 197F98: using guessed type int dword_197F98;


//----- (000DE22C) --------------------------------------------------------
void __fastcall sub_DE22C(char *a1, _WORD *a2, int a3, int a4)
{
  int16_t v5; // ax
  int16_t v6; // [esp+4h] [ebp-4h]

  v6 = 0;
  v5 = ((int (__fastcall *)(char *, int16_t, int16_t, int))funcs_DDFF0[a3])(a1, *a1, *a2 & 0xF, a4);
  if ( v5 <= 0 && (a3 || a1[221]) )
    v6 = 1;
  if ( v5 < v6 )
    JUMPOUT(0xDEE14);
  JUMPOUT(0xDEE17);
}
// DE27B: control flows out of bounds to DEE14
// DE275: control flows out of bounds to DEE17
// 18355C: using guessed type int (*funcs_DDFF0[3])();


//----- (000DE280) --------------------------------------------------------
int __fastcall sub_DE280(char *a1, int a2, void *a3)
{
  int v4; // edi
  int v5; // ebx
  _BOOL1 v6; // cl
  int v7; // eax
  int v8; // eax
  _BOOL1 v9; // zf
  int v10; // edi
  char *v11; // edi
  _WORD *v12; // ecx
  int16_t v13; // ax
  int16_t v14; // dx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // ebx
  _WORD v23[275]; // [esp+0h] [ebp-4D4h] BYREF
  int v24; // [esp+226h] [ebp-2AEh]
  int v25; // [esp+22Ah] [ebp-2AAh]
  int v26; // [esp+22Eh] [ebp-2A6h]
  int v27; // [esp+232h] [ebp-2A2h]
  int v28; // [esp+236h] [ebp-29Eh]
  int v29; // [esp+23Ah] [ebp-29Ah]
  int v30; // [esp+23Eh] [ebp-296h]
  int v31; // [esp+242h] [ebp-292h]
  int v32; // [esp+246h] [ebp-28Eh]
  int v33; // [esp+24Ah] [ebp-28Ah]
  int v34; // [esp+24Eh] [ebp-286h]
  int v35; // [esp+252h] [ebp-282h]
  _DWORD v36[150]; // [esp+258h] [ebp-27Ch] BYREF
  void *v37; // [esp+4B0h] [ebp-24h]
  char *v38; // [esp+4B4h] [ebp-20h]
  unsigned int v39; // [esp+4B8h] [ebp-1Ch]
  int v40; // [esp+4BCh] [ebp-18h]
  int v41; // [esp+4C0h] [ebp-14h]
  int v42; // [esp+4C4h] [ebp-10h]
  _BOOL1 v43; // [esp+4C8h] [ebp-Ch]
  _BOOL1 v44; // [esp+4CCh] [ebp-8h]
  char v45; // [esp+4D0h] [ebp-4h]

  v42 = a2;
  v37 = a3;
  v45 = ((int)*(uint8_t *)(113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 2)
                                 + dword_19306C
                                 + 42) >> *a1)
      & 1;
  v4 = sub_DD9F2(a1);
  v39 = *(char *)(dword_197F98 + 3753 * *a1 + 2207);
  v5 = 598;
  v6 = (int)v39 / 2 == 3;
  v41 = 0;
  memset(v36, 0, 598);
  if ( v4 == -1 )
    goto LABEL_17;
  v7 = 59 * v4 + dword_1930DC;
  if ( !(_WORD)v42 )
  {
    if ( (*(_BYTE *)(v7 + 42) & 8) == 0 )
    {
      v9 = (*(_BYTE *)(v7 + 42) & 4) == 0;
      goto LABEL_9;
    }
LABEL_7:
    v8 = 3 * (sub_94951(v4) + 1);
LABEL_16:
    v41 = v8;
    goto LABEL_17;
  }
  if ( (uint16_t)v42 <= 1u )
  {
    if ( (*(_BYTE *)(v7 + 43) & 2) == 0 )
    {
      v9 = (*(_BYTE *)(v7 + 43) & 1) == 0;
LABEL_9:
      if ( !v9 )
        goto LABEL_15;
      goto LABEL_17;
    }
    goto LABEL_7;
  }
  if ( (_WORD)v42 != 2 )
    goto LABEL_17;
  if ( (*(_BYTE *)(v7 + 43) & 0x20) != 0 )
    goto LABEL_7;
  if ( (*(_BYTE *)(v7 + 43) & 0x10) != 0 )
  {
LABEL_15:
    v8 = 2 * (sub_94951(v4) + 1);
    goto LABEL_16;
  }
LABEL_17:
  v10 = 4 * (uint8_t)a1[10];
  v38 = a1 + 12;
  v11 = &a1[v10 + 12];
  v43 = !v6;
  while ( v11 > v38 )
  {
    v11 -= 4;
    if ( (v11[1] & 2) != 0 && *(_DWORD *)v11 << 23 >> 30 == (int16_t)v42 )
    {
      v40 = 4 - sub_DDF2C((int)a1, *(_WORD *)v11 & 0xF, v5);
      v44 = v43;
      memset(v23, 0, 598);
      if ( v37 )
        v12 = v23;
      else
        v12 = 0;
      sub_DE22C(a1, v11, v42, (int)v12);
      v14 = v13;
      if ( v37 )
      {
        v36[0] += *(_DWORD *)v23;
        *((_WORD *)&v36[1] + (*(_DWORD *)v11 & 0xF)) += v23[(*(_DWORD *)v11 & 0xF) + 2];
        v15 = 204;
        do
        {
          --v15;
          *(_WORD *)((char *)&v36[6] + v15 * 2) += v23[v15 + 12];
        }
        while ( v15 * 2 );
        v16 = 49;
        do
        {
          --v16;
          *(_WORD *)((char *)&v36[112] + v16 * 2) += v23[v16 + 224];
        }
        while ( v16 * 2 );
        *(_DWORD *)((char *)&v36[136] + 2) += *(_DWORD *)&v23[273];
        *(_DWORD *)((char *)&v36[137] + 2) += v24;
        *(_DWORD *)((char *)&v36[138] + 2) += v25;
      }
      v26 = 20 * v14;
      *(_DWORD *)((char *)&v36[139] + 2) += v26;
      if ( (_WORD)v42 != 1 && (*(_DWORD *)v11 & 0xF) == 8 )
        v44 = 0;
      v5 = v14;
      v27 = -5 * v14 * (int16_t)v40;
      *(_DWORD *)((char *)&v36[140] + 2) += v27;
      v33 = (int16_t)v41 * v14;
      *(_DWORD *)((char *)&v36[146] + 2) += v33;
      if ( (v11[1] & 4) != 0 )
      {
        v28 = -5 * v14;
        *(_DWORD *)((char *)&v36[141] + 2) += v28;
      }
      if ( v44 )
      {
        v5 = a1[7];
        v30 = v5 * v14;
      }
      *(_DWORD *)((char *)&v36[143] + 2) += v30;
      if ( (uint16_t)v42 <= 1u )
      {
        if ( v39 < 6 )
          goto LABEL_46;
        if ( v39 <= 6 )
        {
          v17 = 10 * v14;
        }
        else
        {
          if ( v39 != 7 )
          {
LABEL_46:
            *(_DWORD *)((char *)&v36[144] + 2) += v31;
            if ( v45 )
            {
              v32 = -10 * v14;
              *(_DWORD *)((char *)&v36[145] + 2) += v32;
            }
            goto LABEL_60;
          }
          v17 = 20 * v14;
        }
        v31 = v17;
        goto LABEL_46;
      }
      if ( (_WORD)v42 == 2 )
      {
        if ( !v39 )
        {
          v18 = -10 * v14;
          goto LABEL_58;
        }
        if ( v39 > 1 )
        {
          if ( v39 >= 4 )
          {
            if ( v39 <= 4 )
            {
              v18 = 10 * v14;
            }
            else
            {
              if ( v39 != 5 )
                goto LABEL_59;
              v18 = 15 * v14;
            }
LABEL_58:
            v31 = v18;
          }
LABEL_59:
          *(_DWORD *)((char *)&v36[144] + 2) += v31;
          goto LABEL_60;
        }
        v18 = -5 * v14;
        goto LABEL_58;
      }
LABEL_60:
      if ( *(_BYTE *)(dword_197F98 + 3753 * *a1 + 40) != 100 )
      {
        v34 = byte_DD4D7[(uint8_t)byte_199CB0];
        *(_DWORD *)((char *)&v36[147] + 2) += v34;
      }
      v19 = v24 + v32 + v31 + v29 + v30 + v28 + v33 + v27 + v26 + v34;
      v35 = v19;
      if ( v19 > 0 )
        *(_DWORD *)((char *)&v36[148] + 2) += v19;
    }
  }
  if ( v37 )
    qmemcpy(v37, v36, 0x256u);
  if ( (_WORD)v42 )
  {
    v20 = *(_DWORD *)((char *)&v36[148] + 2) + 10;
    v21 = 20;
  }
  else
  {
    v20 = *(_DWORD *)((char *)&v36[148] + 2) + 20;
    v21 = 40;
  }
  return v20 / v21;
}
// DE3FF: variable 'v13' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (000DE664) --------------------------------------------------------
char __fastcall sub_DE664(int a1, char *a2)
{
  int v2; // esi
  _DWORD *v3; // ebx
  char *v4; // edi
  char *v5; // edi
  int v6; // ebx
  int v7; // ecx
  char *v8; // eax
  int v9; // ebx
  int v10; // ecx
  int v11; // ebx
  int v12; // ecx
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  char *v19; // eax
  char *v20; // eax
  char *v21; // edi
  char *v23; // [esp-8h] [ebp-268h]
  char *v24; // [esp-4h] [ebp-264h]
  char *v25; // [esp-4h] [ebp-264h]
  char *v26; // [esp-4h] [ebp-264h]
  char *v27; // [esp-4h] [ebp-264h]
  char *v28; // [esp-4h] [ebp-264h]
  char *v29; // [esp-4h] [ebp-264h]
  char *v30; // [esp-4h] [ebp-264h]
  char *v31; // [esp-4h] [ebp-264h]
  char *v32; // [esp-4h] [ebp-264h]
  _DWORD v33[5]; // [esp+0h] [ebp-260h] BYREF
  int16_t v34; // [esp+14h] [ebp-24Ch]
  int16_t v35; // [esp+16h] [ebp-24Ah]
  _BYTE v36[522]; // [esp+18h] [ebp-248h]
  int v37; // [esp+222h] [ebp-3Eh]
  int v38; // [esp+232h] [ebp-2Eh]
  int v39; // [esp+236h] [ebp-2Ah]
  int v40; // [esp+23Eh] [ebp-22h]
  int v41; // [esp+242h] [ebp-1Eh]
  int v42; // [esp+246h] [ebp-1Ah]
  int v43; // [esp+24Ah] [ebp-16h]
  int v44; // [esp+258h] [ebp-8h]
  int v45; // [esp+25Ch] [ebp-4h]

  v2 = a1;
  if ( *(_BYTE *)(a1 + 10) )
  {
    a1 = sub_2341E((a1 - dword_192B18) / 361);
    if ( (_WORD)a1 )
    {
      *(_WORD *)(v2 + 231) = 0;
      if ( a2 )
        strcpy(a2, (char *)dword_1AA31C);
    }
    else
    {
      v44 = a1;
      v45 = a1;
      if ( *(_BYTE *)(v2 + 221) )
      {
        if ( a2 )
          v3 = v33;
        else
          v3 = 0;
        LOWORD(a1) = sub_DE280((char *)v2, 0, v3);
      }
      else
      {
        memset(v33, 0, 598);
        LOWORD(a1) = 0;
      }
      if ( *(_BYTE *)(v2 + 331) )
        v44 = 2;
      if ( *(_BYTE *)(v2 + 353) )
        v45 = 4;
      LOWORD(a1) = v44 + a1;
      *(_WORD *)(v2 + 231) = a1 + v45;
      if ( a2 )
      {
        v4 = &a2[sprintf(a2, "%s", aT1565)];
        v5 = &v4[sprintf(v4, "%s", byte_179F6E)];
        if ( v33[0] )
          v5 += sprintf(v5, "\t%+d\t%s\r", v33[0] / 2, (char *)dword_1AA304);
        if ( v37 )
          v5 += sprintf(v5, "\t%+d\t%s\r", v37 / 2, (char *)dword_1AA33C);
        v6 = 16;
        v7 = 30024;
        do
        {
          v6 -= 2;
          v7 -= 3753;
          if ( *(int16_t *)((char *)&v33[1] + v6) > 0 )
            v5 += sprintf(
                    v5,
                    "\t%+d\t%s %s\r",
                    *(int16_t *)((char *)&v33[1] + v6) / 2,
                    (char *)(v7 + dword_197F98 + 21),
                    (char *)dword_1AA30C);
          if ( *(int16_t *)((char *)&v33[1] + v6) < 0 )
          {
            v24 = (char *)dword_1AA30C;
            v23 = (char *)(v7 + dword_197F98 + 21);
            sub_DDA36(*(int16_t *)((char *)&v33[1] + v6), 2);
            v5 += sprintf(v5, "\t%s\t%s %s\r", v8, v23, v24);
          }
        }
        while ( v6 );
        if ( v35 )
          v5 += sprintf(v5, "\t%+d\t %s\r", v35 / 2, (char *)dword_1AA318);
        if ( v34 )
          v5 += sprintf(v5, "\t%+d\t%s\r", v34 / 2, (char *)dword_1AA300);
        v9 = 408;
        v10 = 2652;
        do
        {
          v9 -= 2;
          v10 -= 13;
          if ( *(_WORD *)&v36[v9] )
            v5 += sprintf(v5, "\t%+d\t%s\r", *(int16_t *)&v36[v9] / 2, *(char **)((char *)&off_17E079 + v10));
        }
        while ( v9 );
        v11 = 98;
        v12 = 931;
        do
        {
          v11 -= 2;
          v12 -= 19;
          if ( *(_WORD *)&v36[v11 + 424] )
            v5 += sprintf(
                    v5,
                    "\t%+d\t%s\r",
                    *(int16_t *)&v36[v11 + 424] / 2,
                    *(char **)((char *)&off_17EB3D + v12));
        }
        while ( v11 );
        if ( v38 )
        {
          v25 = (char *)dword_1AA2F8;
          sub_DDA36(v38, 40);
          v5 += sprintf(v5, "\t%s\t%s\r", v13, v25);
        }
        if ( v39 )
        {
          v26 = (char *)dword_1AA330;
          sub_DDA36(v39, 40);
          v5 += sprintf(v5, "\t%s\t%s\r", v14, v26);
        }
        if ( v42 )
        {
          v27 = (char *)dword_1AA338;
          sub_DDA36(v42, 40);
          v5 += sprintf(v5, "\t%s\t%s\r", v15, v27);
        }
        if ( v40 > 0 )
        {
          v28 = (char *)dword_1AA334;
          sub_DDA36(v40, 40);
          v5 += sprintf(v5, "\t%s\t%s\r", v16, v28);
        }
        if ( v40 < 0 )
        {
          v29 = (char *)dword_1AA340;
          sub_DDA36(v40, 40);
          v5 += sprintf(v5, "\t%s\t%s\r", v17, v29);
        }
        if ( v41 > 0 )
        {
          v30 = (char *)dword_1AA2D0;
          sub_DDA36(v41, 40);
          v5 += sprintf(v5, "\t%s\t%s\r", v18, v30);
        }
        if ( v41 < 0 )
        {
          v31 = (char *)dword_1AA2E4;
          sub_DDA36(v41, 40);
          v5 += sprintf(v5, "\t%s\t%s\r", v19, v31);
        }
        if ( v43 )
        {
          v32 = (char *)dword_1AA328;
          sub_DDA36(v43, 40);
          v5 += sprintf(v5, "\t%s\t%s\r", v20, v32);
        }
        if ( (_WORD)v44 )
          v5 += sprintf(v5, "\t%+d\t%s\r", (int16_t)v44, (char *)off_17ECCC);
        if ( (_WORD)v45 )
          v5 += sprintf(v5, "\t%+d\t%s\r", (int16_t)v45, (char *)off_17EE6E);
        if ( *(_BYTE *)(v2 + 276) )
        {
          v5 += sprintf(v5, "\t%+d\t%s\r", *(uint8_t *)(v2 + 276), (char *)off_17EC6D);
          *(_WORD *)(v2 + 231) += *(uint8_t *)(v2 + 276);
        }
        v21 = &v5[sprintf(v5, asc_179F93)];
        LOBYTE(a1) = sprintf(v21, "\t%+d\t%s\r", *(int16_t *)(v2 + 231), (char *)dword_1AA290);
      }
    }
  }
  else
  {
    *(_WORD *)(a1 + 231) = 0;
  }
  return a1;
}
// DE831: variable 'v8' is possibly undefined
// DE941: variable 'v13' is possibly undefined
// DE96B: variable 'v14' is possibly undefined
// DE995: variable 'v15' is possibly undefined
// DE9BF: variable 'v16' is possibly undefined
// DE9E9: variable 'v17' is possibly undefined
// DEA13: variable 'v18' is possibly undefined
// DEA3D: variable 'v19' is possibly undefined
// DEA67: variable 'v20' is possibly undefined
// DEB17: variable 'a1' is possibly undefined
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 17EC6D: using guessed type _UNKNOWN *off_17EC6D;
// 17ECCC: using guessed type _UNKNOWN *off_17ECCC;
// 17EE6E: using guessed type _UNKNOWN *off_17EE6E;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 1AA290: using guessed type int dword_1AA290;
// 1AA2D0: using guessed type int dword_1AA2D0;
// 1AA2E4: using guessed type int dword_1AA2E4;
// 1AA2F8: using guessed type int dword_1AA2F8;
// 1AA300: using guessed type int dword_1AA300;
// 1AA304: using guessed type int dword_1AA304;
// 1AA30C: using guessed type int dword_1AA30C;
// 1AA318: using guessed type int dword_1AA318;
// 1AA31C: using guessed type int dword_1AA31C;
// 1AA328: using guessed type int dword_1AA328;
// 1AA330: using guessed type int dword_1AA330;
// 1AA334: using guessed type int dword_1AA334;
// 1AA338: using guessed type int dword_1AA338;
// 1AA33C: using guessed type int dword_1AA33C;
// 1AA340: using guessed type int dword_1AA340;


//----- (000DEB1D) --------------------------------------------------------
void __fastcall sub_DEB1D( int a1)
{
  char v1[3000]; // [esp+0h] [ebp-BB8h] BYREF

  sub_DE664(361 * a1 + dword_192B18, v1);
  JUMPOUT(0xDDF24);
}
// DEB46: control flows out of bounds to DDF24
// 192B18: using guessed type int dword_192B18;
// 1AA2CC: using guessed type int dword_1AA2CC;


//----- (000DEB4B) --------------------------------------------------------
void __fastcall sub_DEB4B(uint8_t *a1)
{
  int16_t v2; // si
  uint8_t *v3; // edi
  int v4; // edx
  int v5; // eax
  char v6; // al
  int16_t v7; // [esp+4h] [ebp-4h]

  v7 = (char)*a1;
  if ( sub_2341E((int)&a1[-dword_192B18] / 361) )
  {
    a1[239] = 0;
  }
  else
  {
    memset(a1 + 260, 0, 8);
    a1[252] = 0;
    a1[255] = 0;
    v2 = 0;
    a1[254] = 0;
    v3 = a1 + 12;
    a1[253] = 0;
    while ( v2 < a1[10] )
    {
      v4 = *(_DWORD *)&v3[4 * v2] & 0xF;
      if ( (*(_WORD *)&v3[4 * v2] & 0xFu) >= 8 )
      {
        if ( (_WORD)v4 == 9 )
          a1[255] += 2;
      }
      else
      {
        v5 = dword_197F98 + 3753 * (int16_t)v4;
        if ( *(_BYTE *)(v5 + 2224) )
        {
          v6 = 1;
        }
        else if ( *(_BYTE *)(v5 + 2225) )
        {
          v6 = 0;
        }
        else
        {
          v6 = 2;
        }
        if ( (_WORD)v4 == v7 )
        {
          a1[252] += v6;
        }
        else if ( (*(_WORD *)&v3[4 * v2] & 0x400) != 0 )
        {
          a1[254] += v6;
        }
        else
        {
          a1[253] += v6;
        }
        a1[(int16_t)v4 + 260] += v6;
      }
      ++v2;
    }
    a1[239] = ((int16_t)(a1[253] + a1[255] + a1[252] + a1[254]) + 1) / 2;
  }
  JUMPOUT(0xE1F97);
}
// DEB7F: control flows out of bounds to E1F97
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000DEC95) --------------------------------------------------------
int __fastcall sub_DEC95(int a1, int a2, int a3)
{
  int v4; // edx

  v4 = 17 * *(int16_t *)(a1 + 2);
  LOWORD(v4) = (uint8_t)byte_DD4B5[*(uint8_t *)(v4 + dword_1930D4 + 10)];
  if ( a3 )
    *(_DWORD *)a3 = (int16_t)v4;
  if ( *(_BYTE *)(a1 + 314) )
  {
    ++v4;
    if ( a3 )
      *(_WORD *)(a3 + 456) = 1;
  }
  if ( *(_BYTE *)(a1 + 317) )
  {
    ++v4;
    if ( a3 )
      *(_WORD *)(a3 + 462) = 1;
  }
  if ( *(_BYTE *)(a1 + 346) )
  {
    v4 += 2;
    if ( a3 )
      *(_WORD *)(a3 + 520) = 2;
  }
  if ( *(_BYTE *)(a1 + 322) )
  {
    v4 += 3;
    if ( a3 )
      *(_WORD *)(a3 + 472) = 3;
  }
  if ( *(_BYTE *)(3753 * a2 + dword_197F98 + 387) == 3 )
  {
    ++v4;
    if ( a3 )
      *(_WORD *)(a3 + 240) = 1;
  }
  return v4;
}
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000DED47) --------------------------------------------------------
int __fastcall sub_DED47(char *a1, int a2, int a3, int a4)
{
  int16_t v5; // ax
  int16_t v6; // ax
  int v8; // [esp+4h] [ebp-4h]
  int16_t v9; // [esp+4h] [ebp-4h]

  if ( *a1 != a2 || a4 )
    v5 = sub_DEC95((int)a1, a2, a4);
  else
    v5 = (uint8_t)a1[222];
  v9 = v5;
  if ( a1 != (char *)dword_18356D || (uint8_t)byte_183571 != a2 || a4 )
  {
    memset(byte_1AA362, 99, sizeof(byte_1AA362));
    dword_18356D = (int)a1;
    byte_183571 = a2;
  }
  if ( byte_1AA362[a3] == 99 )
  {
    v6 = 0;
    if ( a3 >= 8 )
    {
      if ( a3 == 8 )
        v6 = 3;
    }
    else
    {
      v6 = *(char *)(dword_197F98 + 3753 * a3 + 2210);
    }
    if ( a4 )
      *(_WORD *)(a4 + 2 * a3 + 4) = v6;
    LOWORD(v8) = v6 + v9;
    byte_1AA362[a3] = v8;
  }
  else
  {
    LOWORD(v8) = byte_1AA362[a3];
  }
  return v8;
}
// DEE14: variable 'v8' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 18356D: using guessed type int dword_18356D;
// 183571: using guessed type char byte_183571;
// 197F98: using guessed type int dword_197F98;


//----- (000DEE1B) --------------------------------------------------------
char __fastcall sub_DEE1B(char *a1, char *a2)
{
  char *v2; // esi
  int v4; // ecx
  _DWORD *v5; // ebx
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // edx
  int v13; // ebx
  int v14; // eax
  char *v15; // edi
  char *v16; // edi
  int v17; // ebx
  int v18; // edx
  int v19; // ebx
  int v20; // edx
  int v21; // edx
  int v22; // ebx
  char *v23; // eax
  char *v24; // eax
  char *v25; // eax
  char *v26; // eax
  char *v27; // eax
  char *v28; // eax
  char *v29; // eax
  char *v30; // eax
  char *v31; // eax
  int v32; // eax
  char *v34; // [esp-4h] [ebp-272h]
  char *v35; // [esp-4h] [ebp-272h]
  char *v36; // [esp-4h] [ebp-272h]
  char *v37; // [esp-4h] [ebp-272h]
  char *v38; // [esp-4h] [ebp-272h]
  char *v39; // [esp-4h] [ebp-272h]
  char *v40; // [esp-4h] [ebp-272h]
  char *v41; // [esp-4h] [ebp-272h]
  char *v42; // [esp-4h] [ebp-272h]
  _DWORD v43[5]; // [esp+0h] [ebp-26Eh] BYREF
  int16_t v44; // [esp+14h] [ebp-25Ah]
  _BYTE v45[538]; // [esp+18h] [ebp-256h]
  int v46; // [esp+232h] [ebp-3Ch]
  int v47; // [esp+236h] [ebp-38h]
  int v48; // [esp+23Ah] [ebp-34h]
  int v49; // [esp+23Eh] [ebp-30h]
  int v50; // [esp+242h] [ebp-2Ch]
  int v51; // [esp+246h] [ebp-28h]
  int v52; // [esp+24Ah] [ebp-24h]
  char v53[100]; // [esp+258h] [ebp-16h] BYREF
  char *v54; // [esp+2BCh] [ebp+4Eh]
  int v55; // [esp+2C0h] [ebp+52h]
  int v56; // [esp+2C4h] [ebp+56h]
  int v57; // [esp+2C8h] [ebp+5Ah]
  int v58; // [esp+2CCh] [ebp+5Eh]
  int v59; // [esp+2D0h] [ebp+62h]
  int v60; // [esp+2D4h] [ebp+66h]
  int v61; // [esp+2D8h] [ebp+6Ah]
  int v62; // [esp+2DCh] [ebp+6Eh]
  int v63; // [esp+2E0h] [ebp+72h]
  int v64; // [esp+2E4h] [ebp+76h]
  int v65; // [esp+2E8h] [ebp+7Ah]
  int v66; // [esp+2ECh] [ebp+7Eh]

  v2 = a1;
  v4 = (uint8_t)a1[10];
  a1[251] = 0;
  if ( v4 )
  {
    LOWORD(a1) = sub_2341E((int)&a1[-dword_192B18] / 361);
    if ( (_WORD)a1 )
    {
      *(_WORD *)(v2 + 233) = 0;
      if ( a2 )
        strcpy(a2, (char *)dword_1AA31C);
    }
    else
    {
      if ( a2 )
        v5 = v43;
      else
        v5 = 0;
      v64 = 0;
      v6 = (int16_t)sub_DE280(v2, 1, v5);
      if ( v2[317] )
        v7 = 5;
      else
        v7 = 0;
      v60 = v7;
      if ( v2[346] )
        v8 = 10;
      else
        v8 = 0;
      v55 = v8;
      if ( v2[322] )
        v9 = 15;
      else
        v9 = 0;
      v65 = 0;
      v56 = v9;
      if ( v2[344] )
        v65 = (uint8_t)byte_DD4DC[*(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)v2 + 1) + 10)];
      if ( v2[343] )
      {
        v64 = v4;
        v2[251] = v4;
      }
      v66 = 3753 * *v2;
      if ( *(_BYTE *)(v66 + dword_197F98 + 40) != 100 )
        v2[251] += (v4 * (uint8_t)byte_199CB0
                  + 4
                  - (__CFSHL__((v4 * (uint8_t)byte_199CB0 + 4) >> 31, 3)
                   + 8 * ((v4 * (uint8_t)byte_199CB0 + 4) >> 31))) >> 3;
      v61 = v65 + v56 + v55 + v6 + v60 + v64;
      if ( v2[323] )
      {
        *((_WORD *)v2 + 4) = 0;
      }
      else
      {
        v63 = sub_DD9F2(v2);
        v58 = (uint8_t)byte_DD4E1[*(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)v2 + 1) + 5)];
        v10 = v65 + v6;
        if ( *(_BYTE *)(dword_197F98 + 3753 * *v2 + 392) == 3 )
          v58 *= 2;
        if ( v2[342] )
          v10 = (v10 + 1) / 2;
        if ( v2[315] )
          v10 = (v10 + 3 - (__CFSHL__((v10 + 3) >> 31, 2) + 4 * ((v10 + 3) >> 31))) >> 2;
        if ( v63 != -1 )
        {
          v66 = 59 * v63;
          v11 = 59 * v63 + dword_1930DC;
          v12 = 0;
          if ( (*(_BYTE *)(v11 + 42) & 2) != 0 )
          {
            v12 = 15 * ((int16_t)sub_94951(v63) + 1);
          }
          else if ( (*(_BYTE *)(v11 + 42) & 1) != 0 )
          {
            v12 = 10 * ((int16_t)sub_94951(v63) + 1);
          }
          v66 = 100;
          v10 -= v10 * v12 / 100;
        }
        v13 = (v10 - v58 + 1) / 2;
        if ( v13 > 0 )
        {
          v62 = 0;
          v57 = v4;
          v54 = &v2[4 * v4];
          while ( v57 > 0 )
          {
            v54 -= 4;
            v14 = *((_DWORD *)v54 + 3) & 0xF;
            --v57;
            v59 = v14;
            if ( v14 < 8 && (v66 = 3753 * v14, *(_BYTE *)(3753 * v14 + dword_197F98 + 2230)) || v59 == 8 )
              ++v62;
          }
          if ( v62 )
            v13 = ((v4 - v62) * v13 + v4 / 2) / v4;
        }
        if ( v13 <= 0 )
        {
          LOWORD(v13) = 0;
        }
        else
        {
          v48 = -20 * v13;
          v61 -= v13;
        }
        *((_WORD *)v2 + 4) = v13;
      }
      LOBYTE(a1) = v61;
      *(_WORD *)(v2 + 233) = v61;
      if ( a2 )
      {
        v15 = &a2[sprintf(a2, "%s", aT1565)];
        v16 = &v15[sprintf(v15, "%s", byte_179F6E)];
        if ( v43[0] )
          v16 += sprintf(v16, "\t%+d\t%s\r", v43[0], (char *)dword_1AA2EC);
        v17 = 16;
        v18 = 30024;
        do
        {
          v17 -= 2;
          v18 -= 3753;
          if ( *(_WORD *)((char *)&v43[1] + v17) )
            v16 += sprintf(
                     v16,
                     "\t%+d\t%s %s\r",
                     *(int16_t *)((char *)&v43[1] + v17),
                     (char *)(v18 + dword_197F98 + 21),
                     (char *)dword_1AA30C);
        }
        while ( v17 );
        if ( v44 )
          v16 += sprintf(v16, "\t%+d\t%s\r", v44, (char *)dword_1AA300);
        v19 = 408;
        v20 = 2652;
        do
        {
          v19 -= 2;
          v20 -= 13;
          if ( *(_WORD *)&v45[v19] )
            v16 += sprintf(v16, "\t%+d\t%s\r", *(int16_t *)&v45[v19], *(char **)((char *)&off_17E079 + v20));
        }
        while ( v19 );
        v21 = 98;
        v22 = 931;
        do
        {
          v21 -= 2;
          v22 -= 19;
          if ( *(_WORD *)&v45[v21 + 424] )
            v16 += sprintf(v16, "\t%+d\t%s\r", *(int16_t *)&v45[v21 + 424], *(char **)((char *)&off_17EB3D + v22));
        }
        while ( v21 );
        if ( v46 )
        {
          v34 = (char *)dword_1AA2F8;
          sub_DDA36(v46, 20);
          v16 += sprintf(v16, "\t%s\t%s\r", v23, v34);
        }
        if ( v47 )
        {
          v35 = (char *)dword_1AA330;
          sub_DDA36(v47, 20);
          v16 += sprintf(v16, "\t%s\t%s\r", v24, v35);
        }
        if ( v51 )
        {
          v36 = (char *)dword_1AA338;
          sub_DDA36(v51, 20);
          v16 += sprintf(v16, "\t%s\t%s\r", v25, v36);
        }
        if ( v49 > 0 )
        {
          v37 = (char *)dword_1AA334;
          sub_DDA36(v49, 20);
          v16 += sprintf(v16, "\t%s\t%s\r", v26, v37);
        }
        if ( v49 < 0 )
        {
          v38 = (char *)dword_1AA340;
          sub_DDA36(v49, 20);
          v16 += sprintf(v16, "\t%s\t%s\r", v27, v38);
        }
        if ( v50 > 0 )
        {
          v39 = (char *)dword_1AA2D0;
          sub_DDA36(v50, 20);
          v16 += sprintf(v16, "\t%s\t%s\r", v28, v39);
        }
        if ( v50 < 0 )
        {
          v40 = (char *)dword_1AA2E4;
          sub_DDA36(v50, 20);
          v16 += sprintf(v16, "\t%s\t%s\r", v29, v40);
        }
        if ( v52 )
        {
          v41 = (char *)dword_1AA328;
          sub_DDA36(v52, 20);
          v16 += sprintf(v16, "\t%s\t%s\r", v30, v41);
        }
        if ( v64 )
          v16 += sprintf(v16, "\t%+d\t%s\r", v64, (char *)off_17EDB0);
        if ( v60 )
          v16 += sprintf(v16, "\t%+d\t%s\r", v60, (char *)off_17EBC2);
        if ( v55 )
          v16 += sprintf(v16, "\t%+d\t%s\r", v55, (char *)off_17EDE9);
        if ( v56 )
          v16 += sprintf(v16, "\t%+d\t%s\r", v56, (char *)off_17EC21);
        if ( v65 )
          v16 += sprintf(v16, "\t%+d\t%s %s\r", v65, (char *)off_17EDC3, (char *)dword_1AA294);
        if ( v48 )
        {
          v42 = (char *)dword_1AA2A8;
          sub_DDA36(v48, 20);
          v16 += sprintf(v16, "\t%s\t%s\r", v31, v42);
        }
        if ( v2[276] )
        {
          sprintf(v53, (char *)dword_1AA2BC, (uint8_t)v2[276]);
          v16 += sprintf(v16, "\t%d\t%s\r", -2 * (uint8_t)v2[276], v53);
          *(_WORD *)(v2 + 233) -= 2 * (uint8_t)v2[276];
        }
        if ( *(_WORD *)(v2 + 295) )
        {
          v16 += sprintf(v16, "\t-%d\t%s\r", *(int16_t *)(v2 + 295), (char *)dword_1AA2C0);
          *(_WORD *)(v2 + 233) -= *(_WORD *)(v2 + 295);
        }
        v32 = sprintf(v16, asc_179F93);
        LOBYTE(a1) = sprintf(&v16[v32], "\t%+d\t%s\r", *(int16_t *)(v2 + 233), (char *)dword_1AA2E8);
      }
    }
  }
  else
  {
    *(_WORD *)(a1 + 233) = 0;
  }
  return (char)a1;
}
// DF25B: variable 'v23' is possibly undefined
// DF285: variable 'v24' is possibly undefined
// DF2AF: variable 'v25' is possibly undefined
// DF2D9: variable 'v26' is possibly undefined
// DF303: variable 'v27' is possibly undefined
// DF32D: variable 'v28' is possibly undefined
// DF357: variable 'v29' is possibly undefined
// DF381: variable 'v30' is possibly undefined
// DF44C: variable 'v31' is possibly undefined
// DF50C: variable 'a1' is possibly undefined
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 17EBC2: using guessed type _UNKNOWN *off_17EBC2;
// 17EC21: using guessed type _UNKNOWN *off_17EC21;
// 17EDB0: using guessed type _UNKNOWN *off_17EDB0;
// 17EDC3: using guessed type _UNKNOWN *off_17EDC3;
// 17EDE9: using guessed type _UNKNOWN *off_17EDE9;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;
// 1AA294: using guessed type int dword_1AA294;
// 1AA2A8: using guessed type int dword_1AA2A8;
// 1AA2BC: using guessed type int dword_1AA2BC;
// 1AA2C0: using guessed type int dword_1AA2C0;
// 1AA2D0: using guessed type int dword_1AA2D0;
// 1AA2E4: using guessed type int dword_1AA2E4;
// 1AA2E8: using guessed type int dword_1AA2E8;
// 1AA2EC: using guessed type int dword_1AA2EC;
// 1AA2F8: using guessed type int dword_1AA2F8;
// 1AA300: using guessed type int dword_1AA300;
// 1AA30C: using guessed type int dword_1AA30C;
// 1AA31C: using guessed type int dword_1AA31C;
// 1AA328: using guessed type int dword_1AA328;
// 1AA330: using guessed type int dword_1AA330;
// 1AA334: using guessed type int dword_1AA334;
// 1AA338: using guessed type int dword_1AA338;
// 1AA340: using guessed type int dword_1AA340;


//----- (000DF518) --------------------------------------------------------
void __fastcall sub_DF518( int a1)
{
  char v1[3000]; // [esp+0h] [ebp-BB8h] BYREF

  sub_DEE1B((char *)(361 * a1 + dword_192B18), v1);
  JUMPOUT(0xDDF24);
}
// DF541: control flows out of bounds to DDF24
// 192B18: using guessed type int dword_192B18;
// 1AA2C8: using guessed type int dword_1AA2C8;


//----- (000DF546) --------------------------------------------------------
void __fastcall sub_DF546(uint8_t *a1)
{
  uint8_t *v2; // edi
  int16_t i; // bx
  int v4; // edx
  char v5; // al
  int16_t v6; // [esp+0h] [ebp-8h]

  v6 = (char)*a1;
  if ( sub_2341E((int)&a1[-dword_192B18] / 361) )
  {
    a1[240] = 0;
  }
  else
  {
    memset(a1 + 268, 0, 8);
    a1[256] = 0;
    a1[257] = 0;
    a1[259] = 0;
    v2 = a1 + 12;
    a1[258] = 0;
    for ( i = 0; i < a1[10]; ++i )
    {
      v4 = *(_DWORD *)&v2[4 * i] & 0xF;
      if ( (*(_WORD *)&v2[4 * i] & 0xFu) >= 8 )
      {
        if ( (_WORD)v4 == 8 )
          a1[257] += 2;
      }
      else
      {
        v5 = *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v4 + 2224) != 0;
        if ( (_WORD)v4 == v6 )
        {
          a1[256] += v5;
        }
        else if ( (*(_WORD *)&v2[4 * i] & 0x400) != 0 )
        {
          a1[259] += v5;
        }
        else
        {
          a1[258] += v5;
        }
        a1[(int16_t)v4 + 268] += v5;
      }
    }
    a1[240] = ((int16_t)(a1[259] + a1[257] + a1[256] + a1[258]) + 1) / 2;
  }
  JUMPOUT(0xE1F97);
}
// DF57A: control flows out of bounds to E1F97
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000DF66F) --------------------------------------------------------
void __fastcall sub_DF66F(int a1)
{
  int v2; // edi
  int v3; // ecx
  int16_t v4; // si
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // kr1C_4
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // kr2C_4
  int16_t v15; // di
  int v16; // eax
  int v17; // eax
  int16_t v18; // ax
  int16_t v19; // [esp+Ch] [ebp-10h]
  int16_t v20; // [esp+10h] [ebp-Ch]
  int16_t v21; // [esp+14h] [ebp-8h]

  *(_BYTE *)(a1 + 276) = 0;
  if ( *(_BYTE *)(a1 + 326) )
  {
    LOWORD(v2) = 2 * *(_WORD *)(a1 + 233);
    LOWORD(v3) = 0;
    v4 = 2 * *(_WORD *)(a1 + 231);
    v19 = (int16_t)(v2 - *(uint8_t *)(a1 + 256)) / 2;
    if ( v19 > 0 )
    {
      v5 = ((int16_t)(*(uint8_t *)(a1 + 252) - v4) + 1) / 2;
      if ( (int16_t)v5 > 0 )
      {
        v6 = 2 * (int16_t)v5;
        if ( v6 > v19 )
          v6 = v19;
        v3 = 2 * (v6 / 2);
        v4 += v3;
        v2 = (int16_t)v2 - v3 / 2;
      }
      v21 = (int16_t)(v2
                    - *(uint8_t *)(a1 + 256)
                    - *(uint8_t *)(a1 + 257)
                    - *(uint8_t *)(a1 + 258))
          / 2;
      if ( v21 > 0 )
      {
        v7 = ((int16_t)(*(uint8_t *)(a1 + 252) + *(uint8_t *)(a1 + 253) - v4) + 1) / 2;
        if ( (int16_t)v7 > 0 )
        {
          v8 = 2 * (int16_t)v7;
          v9 = v21;
          if ( v21 >= v8 )
            v9 = v8;
          v10 = 2 * (v9 / 2);
          LOWORD(v3) = v10 + v3;
          v4 += v10;
          v2 = (int16_t)v2 - v10 / 2;
        }
        v20 = (int16_t)(v2
                      - *(uint8_t *)(a1 + 256)
                      - *(uint8_t *)(a1 + 257)
                      - *(uint8_t *)(a1 + 258)
                      - *(uint8_t *)(a1 + 259))
            / 2;
        if ( v20 > 0 )
        {
          v11 = ((int16_t)(*(uint8_t *)(a1 + 253)
                         + *(uint8_t *)(a1 + 252)
                         + *(uint8_t *)(a1 + 254)
                         - v4)
               + 1)
              / 2;
          if ( (int16_t)v11 > 0 )
          {
            v12 = 2 * (int16_t)v11;
            v13 = v20;
            if ( v20 >= v12 )
              v13 = v12;
            v14 = 2 * (v13 / 2);
            LOWORD(v3) = v14 + v3;
            v4 += v14;
            v2 = (int16_t)v2 - v14 / 2;
          }
          v15 = (int16_t)(v2
                        - *(uint8_t *)(a1 + 256)
                        - *(uint8_t *)(a1 + 257)
                        - *(uint8_t *)(a1 + 258)
                        - *(uint8_t *)(a1 + 259))
              / 2;
          if ( v15 > 0 )
          {
            v16 = ((int16_t)(*(uint8_t *)(a1 + 254)
                           + *(uint8_t *)(a1 + 252)
                           + *(uint8_t *)(a1 + 253)
                           + *(uint8_t *)(a1 + 255)
                           - v4)
                 + 1)
                / 2;
            if ( (int16_t)v16 > 0 )
            {
              v17 = 2 * (int16_t)v16;
              if ( v15 < v17 )
                v17 = v15;
              LOWORD(v3) = 2 * (v17 / 2) + v3;
            }
          }
        }
      }
    }
    *(_BYTE *)(a1 + 276) = (int16_t)v3 / 2;
    v18 = *(_WORD *)(a1 + 231);
    *(_WORD *)(a1 + 233) -= v3;
    *(_WORD *)(a1 + 231) = (int16_t)v3 / 2 + v18;
  }
  JUMPOUT(0xE1F97);
}
// DF8BC: control flows out of bounds to E1F97


//----- (000DF8C1) --------------------------------------------------------
int __fastcall sub_DF8C1(int a1)
{
  return ((int)*(uint8_t *)(113 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(a1 + 2) + 2)
                                  + dword_19306C
                                  + 42) >> *(_BYTE *)a1)
       & 1;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000DF8F0) --------------------------------------------------------
void __usercall sub_DF8F0( int a1, char *a2, int a3)
{
  int v3; // eax
  _WORD *v4; // ebx
  int v5; // esi
  int v6; // edi
  char *v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int16_t i; // cx
  int v15; // eax
  int16_t v16; // di
  int16_t v17; // cx
  int16_t v18; // cx
  int v19; // eax
  int16_t v20; // cx
  int v21; // eax
  int16_t v22; // cx
  int v23; // eax
  int16_t v24; // ax
  int16_t v25; // ax
  char v26; // dl
  int16_t j; // bx
  int v28; // esi
  int v29; // ecx
  _WORD v32[250]; // [esp+8h] [ebp-22Ch]
  int v33; // [esp+1FCh] [ebp-38h]
  int v34; // [esp+200h] [ebp-34h]
  int v35; // [esp+204h] [ebp-30h]
  int v36; // [esp+208h] [ebp-2Ch]
  int v37; // [esp+20Ch] [ebp-28h]
  int v38; // [esp+210h] [ebp-24h]
  int v39; // [esp+214h] [ebp-20h]
  int v40; // [esp+218h] [ebp-1Ch]
  int v41; // [esp+21Ch] [ebp-18h]
  int v42; // [esp+220h] [ebp-14h]
  int v43; // [esp+224h] [ebp-10h]
  int v44; // [esp+228h] [ebp-Ch]
  int v45; // [esp+22Ch] [ebp-8h]
  int v46; // [esp+230h] [ebp-4h]

  HIWORD(v3) = HIWORD(dword_197F98);
  v4 = (_WORD *)(dword_197F98 + 3753 * a1);
  LOWORD(a3) = 5 * v4[32];
  v37 = 0;
  v39 = 0;
  LOWORD(v3) = v4[27];
  v5 = 0;
  v46 = 0;
  v6 = v3 - a3;
  while ( (int16_t)v46 < word_199996 )
  {
    v7 = (char *)(dword_192B18 + 361 * (int16_t)v46);
    if ( *v7 == a1 && !v7[6] )
    {
      v36 = 361;
      v8 = 361 * (int16_t)v46 % 361;
      v9 = sub_2341E(361 * (int16_t)v46 / 361);
      if ( !(_WORD)v9 )
      {
        LOWORD(v9) = (uint8_t)v7[239];
        LOWORD(v8) = *(_WORD *)(v7 + 231);
        v10 = v8 - v9;
        v44 = v10;
        if ( (v10 & 0x8000u) == 0 )
        {
          v12 = 17 * *((int16_t *)v7 + 1);
          *(_WORD *)(v7 + 243) = v10;
          v13 = dword_1930D4 + v12;
          *(_WORD *)(v7 + 243) = -*(_WORD *)(v7 + 243);
          if ( (((int)*(uint8_t *)(dword_19306C + 113 * *(uint8_t *)(v13 + 2) + 42) >> *v7) & 1) == 0 )
            v5 += v44;
        }
        else
        {
          v11 = dword_1930D4 + 17 * *((int16_t *)v7 + 1);
          *(_WORD *)(v7 + 243) = 0;
          if ( (((int)*(uint8_t *)(dword_19306C + 113 * *(uint8_t *)(v11 + 2) + 42) >> *v7) & 1) == 0 )
          {
            v32[(int16_t)v37++] = v46;
            v39 -= v44;
          }
        }
      }
    }
    ++v46;
  }
  v4[88] = v5 - v39;
  if ( (int16_t)v5 < (int16_t)v39 || (int16_t)v6 < (int16_t)v39 )
  {
    v40 = v6;
    v17 = 0;
    v41 = v5;
    v43 = 0;
    while ( (int16_t)v6 > 0 && (int16_t)v43 < (int16_t)v37 )
    {
      if ( (int16_t)v5 <= 0
        || (v33 = 361 * (int16_t)v32[v17],
            v35 = *(int16_t *)(v33 + dword_192B18 + 243),
            v34 = *(int16_t *)(v33 + dword_192B18 + 231),
            v35 = 2 * (v34 + v35),
            v34 = *(uint8_t *)(v33 + dword_192B18 + 252),
            v35 >= v34) )
      {
        ++v43;
      }
      else
      {
        v43 = 0;
        LOWORD(v5) = v5 - 1;
        LOWORD(v6) = v6 - 1;
        ++*(_WORD *)(v33 + dword_192B18 + 243);
      }
      if ( ++v17 == (_WORD)v37 )
        v17 = 0;
    }
    v18 = 0;
    v42 = 0;
    while ( (int16_t)v6 > 0 && (int16_t)v42 < (int16_t)v37 )
    {
      if ( (int16_t)v5 <= 0
        || (v19 = dword_192B18 + 361 * (int16_t)v32[v18],
            v35 = *(int16_t *)(v19 + 243),
            v34 = *(int16_t *)(v19 + 231),
            v35 = 2 * (v34 + v35),
            v36 = *(uint8_t *)(v19 + 252),
            v34 = *(uint8_t *)(v19 + 253),
            v34 += v36,
            v35 >= v34) )
      {
        ++v42;
      }
      else
      {
        v42 = 0;
        LOWORD(v5) = v5 - 1;
        LOWORD(v6) = v6 - 1;
        ++*(_WORD *)(v19 + 243);
      }
      if ( ++v18 == (_WORD)v37 )
        v18 = 0;
    }
    v20 = 0;
    v38 = 0;
    while ( (int16_t)v6 > 0 && (int16_t)v38 < (int16_t)v37 )
    {
      if ( (int16_t)v5 <= 0 )
        goto LABEL_42;
      v21 = dword_192B18 + 361 * (int16_t)v32[v20];
      v34 = *(uint8_t *)(v21 + 252);
      v35 = *(uint8_t *)(v21 + 253);
      v35 += v34;
      v34 = *(uint8_t *)(v21 + 254);
      v35 += v34;
      v34 = *(int16_t *)(v21 + 243);
      v36 = *(int16_t *)(v21 + 231);
      if ( 2 * (v36 + v34) >= v35 )
      {
LABEL_42:
        ++v38;
      }
      else
      {
        v38 = 0;
        LOWORD(v5) = v5 - 1;
        LOWORD(v6) = v6 - 1;
        ++*(_WORD *)(v21 + 243);
      }
      if ( ++v20 == (_WORD)v37 )
        v20 = 0;
    }
    v22 = 0;
    v45 = 0;
    while ( (int16_t)v6 > 0 && (int16_t)v45 < (int16_t)v37 )
    {
      if ( (int16_t)v5 <= 0
        || (v23 = dword_192B18 + 361 * (int16_t)v32[v22],
            v36 = *(int16_t *)(v23 + 243),
            v35 = *(int16_t *)(v23 + 231),
            v35 += v36,
            v36 = *(uint8_t *)(v23 + 239),
            v35 >= v36) )
      {
        ++v45;
      }
      else
      {
        v45 = 0;
        LOWORD(v5) = v5 - 1;
        LOWORD(v6) = v6 - 1;
        ++*(_WORD *)(v23 + 243);
      }
      if ( ++v22 == (_WORD)v37 )
        v22 = 0;
    }
    v24 = v41 - v5;
    v4[31] = v41 - v5;
    if ( (_WORD)v6 )
    {
      v4[28] = v40 - v24;
    }
    else
    {
      if ( (int16_t)v39 >= (int16_t)v41 )
        v25 = v41;
      else
        v25 = v39;
      v4[28] = v25 - v4[31];
      v4[28] = -v4[28];
    }
  }
  else
  {
    for ( i = 0; i < (int16_t)v37; ++i )
    {
      v15 = dword_192B18 + 361 * (int16_t)v32[i];
      *(_WORD *)(v15 + 243) = *(uint8_t *)(v15 + 239) - *(_WORD *)(v15 + 231);
    }
    v16 = v6 - v39;
    v4[31] = v39;
    v4[28] = v16;
  }
  if ( a2 )
  {
    v26 = 0;
    for ( j = 0; j < (int16_t)v37; ++j )
    {
      v28 = 361 * (int16_t)v32[j];
      v29 = v28 + dword_192B18;
      sub_E1839((char *)(v28 + dword_192B18));
      sub_E1E1F(v29);
      if ( (char *)(v28 + dword_192B18) == a2 )
        v26 = 1;
    }
    if ( !v26 )
    {
      sub_E1839(a2);
      sub_E1E1F((int)a2);
    }
  }
  JUMPOUT(0xDEB17);
}
// DFDC1: control flows out of bounds to DEB17
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;


//----- (000DFDC6) --------------------------------------------------------
int __fastcall sub_DFDC6(int a1, int a2, int a3)
{
  int v3; // edx
  uint8_t v4; // al

  v3 = 3;
  if ( a3 )
    *(_DWORD *)a3 = 3;
  if ( *(_BYTE *)(a1 + 314) )
  {
    v3 = 4;
    if ( a3 )
      *(_WORD *)(a3 + 456) = 1;
  }
  if ( *(_BYTE *)(a1 + 340) )
  {
    v3 += 2;
    if ( a3 )
      *(_WORD *)(a3 + 508) = 2;
  }
  if ( *(_BYTE *)(a1 + 329) )
  {
    v3 += 3;
    if ( a3 )
      *(_WORD *)(a3 + 486) = 3;
  }
  if ( *(_BYTE *)(a1 + 345) )
  {
    ++v3;
    if ( a3 )
      *(_WORD *)(a3 + 518) = 1;
  }
  v4 = *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(a1 + 2) + 15);
  if ( v4 >= 0xAu )
  {
    if ( v4 <= 0xAu )
    {
      v3 += 2;
      if ( a3 )
      {
        *(_DWORD *)(a3 + 550) += 2;
        return v3;
      }
    }
    else
    {
      if ( v4 != 11 )
        return v3;
      v3 += 5;
      if ( a3 )
        *(_DWORD *)(a3 + 550) += 5;
    }
  }
  return v3;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (000DFE77) --------------------------------------------------------
void __fastcall sub_DFE77(char *a1, int a2, int a3, int a4)
{
  char v5; // al
  int16_t v6; // dx
  int v7; // eax
  bool v8; // [esp+0h] [ebp-Ch]
  char v9; // [esp+8h] [ebp-4h]

  if ( *a1 != a2 || a4 )
    v5 = sub_DFDC6((int)a1, a2, a4);
  else
    v5 = a1[223];
  v9 = v5;
  if ( a1 != (char *)dword_183572 || (uint8_t)byte_183576 != a2 || a4 )
  {
    memset(byte_1AA36C, 99, 10);
    dword_183572 = (int)a1;
    byte_183576 = a2;
  }
  if ( byte_1AA36C[a3] == 99 )
  {
    v6 = 0;
    v8 = 0;
    if ( a3 >= 8 )
    {
      if ( a3 == 8 )
        v6 = 3;
    }
    else
    {
      v7 = 3753 * a3 + dword_197F98;
      v6 = *(char *)(v7 + 2211);
      if ( a3 == *a1 )
        v8 = *(_BYTE *)(v7 + 363) == 3;
    }
    if ( a4 )
    {
      *(_WORD *)(a4 + 2 * a3 + 4) = v6;
      *(_DWORD *)(a4 + 554) = v8;
    }
    byte_1AA36C[a3] = v8 + v6 + v9;
    JUMPOUT(0xDEE14);
  }
  JUMPOUT(0xDEE10);
}
// DFF62: control flows out of bounds to DEE14
// DFF6F: control flows out of bounds to DEE10
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 183572: using guessed type int dword_183572;
// 183576: using guessed type char byte_183576;
// 197F98: using guessed type int dword_197F98;


//----- (000DFF74) --------------------------------------------------------
void __fastcall sub_DFF74(int a1, char *a2)
{
  _DWORD *v4; // ebx
  int16_t v5; // dx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  char *v10; // edi
  char *v11; // edi
  int v12; // edx
  int v13; // ebx
  int v14; // edx
  int v15; // ebx
  int v16; // edx
  int v17; // ebx
  char *v18; // eax
  char *v19; // eax
  char *v20; // eax
  char *v21; // eax
  char *v22; // eax
  char *v23; // eax
  char *v24; // eax
  char *v25; // eax
  char *v26; // [esp-4h] [ebp-268h]
  char *v27; // [esp-4h] [ebp-268h]
  char *v28; // [esp-4h] [ebp-268h]
  char *v29; // [esp-4h] [ebp-268h]
  char *v30; // [esp-4h] [ebp-268h]
  char *v31; // [esp-4h] [ebp-268h]
  char *v32; // [esp-4h] [ebp-268h]
  char *v33; // [esp-4h] [ebp-268h]
  _DWORD v34[5]; // [esp+0h] [ebp-264h] BYREF
  int16_t v35; // [esp+14h] [ebp-250h]
  _BYTE v36[526]; // [esp+18h] [ebp-24Ch]
  int v37; // [esp+226h] [ebp-3Eh]
  int v38; // [esp+22Ah] [ebp-3Ah]
  int v39; // [esp+232h] [ebp-32h]
  int v40; // [esp+236h] [ebp-2Eh]
  int v41; // [esp+23Eh] [ebp-26h]
  int v42; // [esp+242h] [ebp-22h]
  int v43; // [esp+246h] [ebp-1Eh]
  int v44; // [esp+24Ah] [ebp-1Ah]
  int v45; // [esp+258h] [ebp-Ch]
  int v46; // [esp+25Ch] [ebp-8h]
  int v47; // [esp+260h] [ebp-4h]

  if ( *(_BYTE *)(a1 + 10) )
  {
    if ( sub_2341E((a1 - dword_192B18) / 361) )
    {
      *(_WORD *)(a1 + 235) = 0;
      if ( a2 )
        strcpy(a2, (char *)dword_1AA31C);
    }
    else
    {
      if ( a2 )
        v4 = v34;
      else
        v4 = 0;
      v5 = sub_DE280((char *)a1, 2, v4);
      if ( *(_BYTE *)(a1 + 345) )
        v6 = 5;
      else
        v6 = 0;
      v47 = v6;
      if ( *(_BYTE *)(a1 + 340) )
        v7 = 10;
      else
        v7 = 0;
      v45 = v7;
      if ( *(_BYTE *)(a1 + 329) )
        v8 = 15;
      else
        v8 = 0;
      if ( *(_BYTE *)(a1 + 316) )
        v9 = 30;
      else
        v9 = 0;
      v46 = v9;
      *(_WORD *)(a1 + 235) = v8 + v45 + v5 + v47 + v9;
      if ( a2 )
      {
        v10 = &a2[sprintf(a2, "%s", aT1565)];
        v11 = &v10[sprintf(v10, "%s", byte_179F6E)];
        if ( v34[0] )
          v11 += sprintf(v11, "\t%+d\t%s\r", v34[0], (char *)dword_1AA2D4);
        if ( v37 )
          v11 += sprintf(v11, "\t%+d\t%s\r", v37, (char *)dword_1AA2B0);
        if ( v38 )
          v11 += sprintf(v11, "\t%+d\t%s\r", v38, (char *)dword_1AA2B8);
        v12 = 16;
        v13 = 30024;
        while ( 1 )
        {
          v12 -= 2;
          v13 -= 3753;
          if ( *(_WORD *)((char *)&v34[1] + v12) )
            v11 += sprintf(
                     v11,
                     "\t%+d\t%s %s\r",
                     *(int16_t *)((char *)&v34[1] + v12),
                     (char *)(v13 + dword_197F98 + 21),
                     (char *)dword_1AA30C);
          if ( !v12 )
          {
            if ( v35 )
              v11 += sprintf(v11, "\t%+d\t%s\r", v35, (char *)dword_1AA300);
            v14 = 408;
            v15 = 2652;
            while ( 1 )
            {
              v14 -= 2;
              v15 -= 13;
              if ( *(_WORD *)&v36[v14] )
                v11 += sprintf(v11, "\t%+d\t%s\r", *(int16_t *)&v36[v14], *(char **)((char *)&off_17E079 + v15));
              if ( !v14 )
              {
                v16 = 98;
                v17 = 931;
                while ( 1 )
                {
                  v16 -= 2;
                  v17 -= 19;
                  if ( *(_WORD *)&v36[v16 + 424] )
                    v11 += sprintf(
                             v11,
                             "\t%+d\t%s\r",
                             *(int16_t *)&v36[v16 + 424],
                             *(char **)((char *)&off_17EB3D + v17));
                  if ( !v16 )
                  {
                    if ( v39 )
                    {
                      v26 = (char *)dword_1AA2F8;
                      sub_DDA36(v39, 20);
                      v11 += sprintf(v11, "\t%s\t%s\r", v18, v26);
                    }
                    if ( v40 )
                    {
                      v27 = (char *)dword_1AA330;
                      sub_DDA36(v40, 20);
                      v11 += sprintf(v11, "\t%s\t%s\r", v19, v27);
                    }
                    if ( v43 )
                    {
                      v28 = (char *)dword_1AA338;
                      sub_DDA36(v43, 20);
                      v11 += sprintf(v11, "\t%s\t%s\r", v20, v28);
                    }
                    if ( v41 > 0 )
                    {
                      v29 = (char *)dword_1AA334;
                      sub_DDA36(v41, 20);
                      v11 += sprintf(v11, "\t%s\t%s\r", v21, v29);
                    }
                    if ( v41 < 0 )
                    {
                      v30 = (char *)dword_1AA340;
                      sub_DDA36(v41, 20);
                      v11 += sprintf(v11, "\t%s\t%s\r", v22, v30);
                    }
                    if ( v42 > 0 )
                    {
                      v31 = (char *)dword_1AA2D0;
                      sub_DDA36(v42, 20);
                      v11 += sprintf(v11, "\t%s\t%s\r", v23, v31);
                    }
                    if ( v42 < 0 )
                    {
                      v32 = (char *)dword_1AA2E4;
                      sub_DDA36(v42, 20);
                      v11 += sprintf(v11, "\t%s\t%s\r", v24, v32);
                    }
                    if ( v44 )
                    {
                      v33 = (char *)dword_1AA328;
                      sub_DDA36(v44, 20);
                      v11 += sprintf(v11, "\t%s\t%s\r", v25, v33);
                    }
                    if ( v47 )
                      v11 += sprintf(v11, "\t+%d\t%s\r", v47, (char *)off_17EDD6);
                    if ( v45 )
                      v11 += sprintf(v11, "\t+%d\t%s\r", v45, (char *)off_17ED77);
                    if ( v8 )
                      v11 += sprintf(v11, "\t+%d\t%s\r", v8, (char *)off_17ECA6);
                    if ( v46 )
                      v11 += sprintf(v11, "\t+%d\t%s\r", v46, (char *)off_17EBAF);
                    sprintf(v11, asc_179F93);
                    JUMPOUT(0xDEB08);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    *(_WORD *)(a1 + 235) = 0;
  }
  JUMPOUT(0xDEB17);
}
// DFF8F: control flows out of bounds to DEB17
// E03BE: control flows out of bounds to DEB08
// E01F9: variable 'v18' is possibly undefined
// E0223: variable 'v19' is possibly undefined
// E024D: variable 'v20' is possibly undefined
// E0277: variable 'v21' is possibly undefined
// E02A1: variable 'v22' is possibly undefined
// E02CB: variable 'v23' is possibly undefined
// E02F5: variable 'v24' is possibly undefined
// E031F: variable 'v25' is possibly undefined
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 17EBAF: using guessed type _UNKNOWN *off_17EBAF;
// 17ECA6: using guessed type _UNKNOWN *off_17ECA6;
// 17ED77: using guessed type _UNKNOWN *off_17ED77;
// 17EDD6: using guessed type _UNKNOWN *off_17EDD6;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 1AA2A4: using guessed type int dword_1AA2A4;
// 1AA2B0: using guessed type int dword_1AA2B0;
// 1AA2B8: using guessed type int dword_1AA2B8;
// 1AA2D0: using guessed type int dword_1AA2D0;
// 1AA2D4: using guessed type int dword_1AA2D4;
// 1AA2E4: using guessed type int dword_1AA2E4;
// 1AA2F8: using guessed type int dword_1AA2F8;
// 1AA300: using guessed type int dword_1AA300;
// 1AA30C: using guessed type int dword_1AA30C;
// 1AA31C: using guessed type int dword_1AA31C;
// 1AA328: using guessed type int dword_1AA328;
// 1AA330: using guessed type int dword_1AA330;
// 1AA334: using guessed type int dword_1AA334;
// 1AA338: using guessed type int dword_1AA338;
// 1AA340: using guessed type int dword_1AA340;


//----- (000E03C3) --------------------------------------------------------
void __fastcall sub_E03C3( int a1)
{
  char v1[3000]; // [esp+0h] [ebp-BB8h] BYREF

  sub_DFF74(361 * a1 + dword_192B18, v1);
  JUMPOUT(0xDDF24);
}
// E03EC: control flows out of bounds to DDF24
// 192B18: using guessed type int dword_192B18;
// 1AA298: using guessed type int dword_1AA298;


//----- (000E03F1) --------------------------------------------------------
void __fastcall sub_E03F1(char *a1, char *a2)
{
  int v3; // ecx
  int v4; // ebx
  unsigned int v5; // eax
  int v6; // eax
  uint8_t v7; // al
  uint16_t v8; // ax
  int v9; // ebx
  uint8_t v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // ebx
  char *v15; // edi
  char *v16; // edi
  int v17; // [esp+0h] [ebp-40h]
  int v18; // [esp+4h] [ebp-3Ch]
  int v19; // [esp+8h] [ebp-38h]
  int v20; // [esp+10h] [ebp-30h]
  int v21; // [esp+14h] [ebp-2Ch]
  int v22; // [esp+18h] [ebp-28h]
  char *v23; // [esp+1Ch] [ebp-24h]
  int v24; // [esp+20h] [ebp-20h]
  int v25; // [esp+24h] [ebp-1Ch]
  int v26; // [esp+28h] [ebp-18h]
  int v27; // [esp+2Ch] [ebp-14h]
  int v28; // [esp+30h] [ebp-10h]
  int v29; // [esp+34h] [ebp-Ch]
  int v30; // [esp+38h] [ebp-8h]
  int v31; // [esp+3Ch] [ebp-4h]

  if ( !a1[10] )
  {
    *(_WORD *)(a1 + 237) = 0;
    goto LABEL_76;
  }
  if ( sub_2341E((int)&a1[-dword_192B18] / 361) )
  {
    *(_WORD *)(a1 + 237) = 0;
    if ( a2 )
      strcpy(a2, (char *)dword_1AA31C);
    goto LABEL_76;
  }
  v3 = 0;
  v4 = 3753 * *a1 + dword_197F98;
  v30 = 0;
  v25 = sub_DD9F2(a1);
  v27 = 0;
  v24 = 0;
  v26 = 0;
  v20 = 2 * *(char *)(v4 + 2212) + 4;
  v29 = 0;
  v28 = 0;
  v22 = 0;
  v21 = 0;
  v23 = &a1[4 * (uint8_t)a1[10] + 12];
  while ( a1 + 12 < v23 )
  {
    v23 -= 4;
    v5 = *(_DWORD *)v23 & 0xF;
    if ( v5 < 8 )
    {
      if ( *(_BYTE *)(dword_197F98 + 3753 * v5 + 2230) )
        ++v21;
      else
        ++v22;
    }
  }
  v18 = v21 + v22;
  if ( *(_BYTE *)(3753 * *a1 + dword_197F98 + 40) != 100 )
    v20 += (uint8_t)byte_DD4E6[(uint8_t)byte_199CB0];
  v17 = (v20 * v18 + 2 - (__CFSHL__((v20 * v18 + 2) >> 31, 2) + 4 * ((v20 * v18 + 2) >> 31))) >> 2;
  if ( v18 > 0 && *(char *)(dword_197F98 + 3753 * ((v4 - dword_197F98) / 3753) + 2207) / 2 != 3 )
  {
    v6 = v17 * a1[7];
    if ( v6 < 0 )
      v3 = (10 - v6) / -20;
    else
      v3 = (v6 + 10) / 20;
  }
  v7 = *(_BYTE *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 15);
  if ( v7 < 4u )
    goto LABEL_25;
  if ( v7 <= 4u )
  {
    v31 = 5;
    goto LABEL_26;
  }
  if ( v7 == 5 )
    v31 = 10;
  else
LABEL_25:
    v31 = 0;
LABEL_26:
  v8 = *(_WORD *)(a1 + 277);
  if ( v8 >= 0xFFDBu && (v8 <= 0xFFDBu || v8 >= 0xFFFEu) )
  {
    v19 = *(int16_t *)(a1 + 233);
    if ( v19 - (uint8_t)a1[240] > 0 )
    {
      if ( *(_BYTE *)(v4 + 2231) )
        v30 = v19 - (uint8_t)a1[240];
      else
        v30 = (v19 - (uint8_t)a1[240] + 1) / 2;
    }
  }
  v9 = v31 + v17;
  if ( *(_BYTE *)(3753 * *a1 + dword_197F98 + 354) == 3 )
    v27 = v9 / 2;
  if ( a1[339] )
    v24 = v31 + v17;
  if ( a1[349] )
    v26 = v9 / 2;
  v10 = *(_BYTE *)(dword_197F98 + 3753 * *a1 + 2207);
  if ( v10 >= 4u )
  {
    if ( v10 <= 4u )
    {
      v11 = v9 / 2;
    }
    else
    {
      if ( v10 != 5 )
        goto LABEL_46;
      v11 = (3 * v9 - (__CFSHL__((3 * v9) >> 31, 2) + 4 * ((3 * v9) >> 31))) >> 2;
    }
    v29 = v11;
  }
LABEL_46:
  if ( v25 == -1 )
    goto LABEL_52;
  v12 = dword_1930DC + 59 * v25;
  if ( (*(_BYTE *)(v12 + 42) & 0x20) != 0 )
  {
    v13 = 3 * ((int16_t)sub_94951(v25) + 1) * v9 + 10;
    v14 = 20;
  }
  else
  {
    if ( (*(_BYTE *)(v12 + 42) & 0x10) == 0 )
      goto LABEL_52;
    v13 = v9 * ((int16_t)sub_94951(v25) + 1) + 5;
    v14 = 10;
  }
  v28 = v13 / v14;
LABEL_52:
  *(_WORD *)(a1 + 237) = *(_WORD *)(a1 + 295) + v29 + v26 + v24 + v27 + v30 + v31 + v3 + v17 + v28;
  if ( a2 )
  {
    v15 = &a2[sprintf(a2, "%s", aT1565)];
    v16 = &v15[sprintf(v15, "%s", byte_179F6E)];
    if ( v17 )
      v16 += sprintf(v16, "\t%+d\t%s\r", v17, (char *)dword_1AA2AC);
    if ( v3 > 0 )
      v16 += sprintf(v16, "\t%+d\t%s\r", v3, (char *)dword_1AA334);
    if ( v3 < 0 )
      v16 += sprintf(v16, "\t%+d\t%s\r", v3, (char *)dword_1AA340);
    if ( v31 )
      v16 += sprintf(v16, "\t%+d\t%s\r", v31, (char *)dword_1AA2D8);
    if ( v28 )
      v16 += sprintf(v16, "\t%+d\t%s\r", v28, (char *)dword_1AA328);
    if ( v27 )
      v16 += sprintf(v16, "\t%+d\t%s\r", v27, (char *)off_17EC93);
    if ( v24 )
      v16 += sprintf(v16, "\t%+d\t%s\r", v24, (char *)off_17ED64);
    if ( v26 )
      v16 += sprintf(v16, "\t%+d\t%s\r", v26, (char *)off_17EE22);
    if ( v29 )
      v16 += sprintf(v16, "\t%+d\t%s\r", v29, (char *)dword_1AA2D0);
    if ( v30 )
      v16 += sprintf(v16, "\t%+d\t%s\r", v30, (char *)dword_1AA29C);
    if ( *(_WORD *)(a1 + 295) )
      v16 += sprintf(v16, "\t%+d\t%s\r", *(int16_t *)(a1 + 295), (char *)dword_1AA2C0);
    sprintf(v16, asc_179F93);
    JUMPOUT(0xDEB08);
  }
LABEL_76:
  JUMPOUT(0xDEB17);
}
// E040C: control flows out of bounds to DEB17
// E08C3: control flows out of bounds to DEB08
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 17EC93: using guessed type _UNKNOWN *off_17EC93;
// 17ED64: using guessed type _UNKNOWN *off_17ED64;
// 17EE22: using guessed type _UNKNOWN *off_17EE22;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;
// 1AA29C: using guessed type int dword_1AA29C;
// 1AA2AC: using guessed type int dword_1AA2AC;
// 1AA2C0: using guessed type int dword_1AA2C0;
// 1AA2D0: using guessed type int dword_1AA2D0;
// 1AA2D8: using guessed type int dword_1AA2D8;
// 1AA2DC: using guessed type int dword_1AA2DC;
// 1AA31C: using guessed type int dword_1AA31C;
// 1AA328: using guessed type int dword_1AA328;
// 1AA334: using guessed type int dword_1AA334;
// 1AA340: using guessed type int dword_1AA340;


//----- (000E08C8) --------------------------------------------------------
void __fastcall sub_E08C8( int a1)
{
  char v1[3000]; // [esp+0h] [ebp-BB8h] BYREF

  sub_E03F1((char *)(361 * a1 + dword_192B18), v1);
  JUMPOUT(0xDDF24);
}
// E08F1: control flows out of bounds to DDF24
// 192B18: using guessed type int dword_192B18;
// 1AA2A0: using guessed type int dword_1AA2A0;


//----- (000E08F6) --------------------------------------------------------
int __fastcall sub_E08F6(char *a1)
{
  int result; // eax

  result = *(int16_t *)(a1 + 233) - (uint8_t)a1[240];
  if ( result > 0 )
  {
    result = result * *(uint8_t *)(dword_197F98 + 3753 * *a1 + 49) / 100;
    *(_WORD *)(a1 + 295) = result;
    *(_WORD *)(a1 + 233) -= result;
  }
  else
  {
    *(_WORD *)(a1 + 295) = 0;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (000E094F) --------------------------------------------------------
void __fastcall sub_E094F(int a1)
{
  int v2; // esi
  int16_t i; // dx

  if ( *(_BYTE *)(a1 + 10) )
  {
    if ( sub_2341E((a1 - dword_192B18) / 361) )
    {
      *(_BYTE *)(a1 + 242) = 0;
    }
    else
    {
      v2 = 0;
      for ( i = 0; i < 49; ++i )
      {
        if ( *(_BYTE *)(i + a1 + 310) )
          v2 += *(int16_t *)((char *)&word_17EB49 + 19 * i);
      }
      *(_BYTE *)(a1 + 242) = ((*((uint8_t *)&word_DD4BA + *(uint8_t *)(a1 + 226)) + 100)
                            * (100 * *(uint8_t *)(a1 + 276) + 100 * v2)
                            + 5000)
                           / 10000;
    }
  }
  else
  {
    *(_BYTE *)(a1 + 242) = 0;
  }
  *(_WORD *)(a1 + 249) = *(uint8_t *)(a1 + 242) - *(_WORD *)(a1 + 237);
  JUMPOUT(0xE1F97);
}
// E0A0F: control flows out of bounds to E1F97
// DD4BA: using guessed type int16_t word_DD4BA;
// 17EB49: using guessed type int16_t word_17EB49;
// 192B18: using guessed type int dword_192B18;


//----- (000E0A14) --------------------------------------------------------
int __fastcall sub_E0A14(int a1)
{
  return 2 * (a1 + 1);
}


//----- (000E0A18) --------------------------------------------------------
int __fastcall sub_E0A18(int a1, int a2, unsigned int a3)
{
  int v3; // ecx
  int v4; // eax

  v3 = (uint8_t)byte_17D806[a1];
  v4 = 25 * a3 + (uint8_t)byte_DD4EB[a2];
  if ( v4 > 100 )
    v4 = 100;
  return (v3 * v4 + 50) / 100;
}


//----- (000E0A49) --------------------------------------------------------
int __fastcall sub_E0A49(int a1, unsigned int a2)
{
  int result; // eax

  result = a2;
  if ( a1 < 8 && *(_BYTE *)(3753 * a1 + dword_197F98 + 2219) )
  {
    if ( a2 < 5 )
    {
      if ( a2 != 4 )
        return result;
    }
    else
    {
      if ( a2 <= 5 )
        return 9;
      if ( a2 > 6 )
      {
        if ( a2 != 8 )
          return result;
        return 9;
      }
    }
    return 8;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (000E0A93) --------------------------------------------------------
int __fastcall sub_E0A93(int a1, unsigned int a2, int a3)
{
  _BOOL1 v5; // al
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  uint8_t v10; // [esp+0h] [ebp-4h]

  v5 = a3 < 8 && *(_BYTE *)(3753 * a3 + dword_197F98 + 2230) || a3 == 8;
  v10 = v5;
  v6 = a2;
  if ( a3 < 8 && *(_BYTE *)(dword_197F98 + 3753 * a3 + 2219) )
  {
    if ( a2 >= 5 )
    {
      if ( a2 <= 5 )
      {
LABEL_15:
        v6 = 9;
        goto LABEL_16;
      }
      if ( a2 > 6 )
      {
        if ( a2 != 8 )
          goto LABEL_16;
        goto LABEL_15;
      }
      goto LABEL_14;
    }
    if ( a2 == 4 )
LABEL_14:
      v6 = 8;
  }
LABEL_16:
  v7 = sub_E0A18(a1, v6, v10);
  v8 = v7;
  if ( a3 < 8 && *(_BYTE *)(3753 * a3 + dword_197F98 + 2220) )
    return v7 + (int16_t)(2 * (a1 + 1));
  return v8;
}
// 197F98: using guessed type int dword_197F98;


//----- (000E0B4F) --------------------------------------------------------
void __fastcall sub_E0B4F(int16_t *a1, int a2)
{
  int v3; // edx
  int v4; // edx
  int v5; // ecx
  char *v6; // edi
  int v7; // edx
  int v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // ecx
  int16_t v12; // ax
  _BYTE v13[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = *a1;
  if ( v3 == -1 || (v4 = 361 * v3, v5 = v4 + dword_192B18, *(_BYTE *)(v4 + dword_192B18 + 6)) )
  {
    sub_E0A93(*((uint8_t *)a1 + 5), *((uint8_t *)a1 + 8), a2);
  }
  else
  {
    v6 = (char *)(v4 + dword_192B18);
    if ( *(_BYTE *)(v5 + 10) )
    {
      memset(v13, 0, 10);
      v7 = *(uint8_t *)(v5 + 10);
      v8 = 0;
      v9 = v5 + 4 * v7;
      while ( v7 > 0 )
      {
        v10 = *(_DWORD *)(v9 + 8) & 0xF;
        v9 -= 4;
        --v7;
        v13[v10] = 1;
      }
      v11 = 10;
      do
      {
        if ( v13[--v11] )
        {
          v12 = sub_E0C1D(v6, v11);
          if ( v8 < v12 )
            v8 = v12;
        }
      }
      while ( v11 > 0 );
    }
    else
    {
      sub_E0C1D((char *)v5, a2);
    }
  }
  JUMPOUT(0xDEB17);
}
// E0C18: control flows out of bounds to DEB17
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000E0C1D) --------------------------------------------------------
int __fastcall sub_E0C1D(char *a1, int a2)
{
  int result; // eax

  result = (int16_t)sub_E0A93(
                      *(uint8_t *)(17 * *((int16_t *)a1 + 1) + dword_1930D4 + 5),
                      (uint8_t)a1[226],
                      a2);
  if ( *(_BYTE *)(3753 * *a1 + dword_197F98 + 282) == 3 )
    result = (int16_t)result + 5;
  if ( a1[325] )
    result += 2;
  return result;
}
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000E0C6E) --------------------------------------------------------
int __fastcall sub_E0C6E(int a1, int a2)
{
  unsigned int v3; // ecx
  int v4; // edx
  _DWORD *v5; // eax

  v3 = a1 + 12;
  v4 = 0;
  v5 = (_DWORD *)(a1 + 12 + 4 * *(uint8_t *)(a1 + 10));
  while ( v3 < (unsigned int)v5 )
  {
    if ( (*--v5 & 0xF) == a2 )
      ++v4;
  }
  return v4;
}


//----- (000E0C9B) --------------------------------------------------------
void __fastcall sub_E0C9B(int a1, int a2)
{
  unsigned int v3; // edi
  int16_t v4; // ax
  int v5; // eax
  _DWORD *v6; // ebx
  int i; // eax
  int v8; // ebx
  int v9; // ecx
  _BYTE v10[44]; // [esp+0h] [ebp-6h] BYREF
  _DWORD v11[10]; // [esp+2Ch] [ebp+26h] BYREF
  _DWORD v12[10]; // [esp+54h] [ebp+4Eh] BYREF
  int v13; // [esp+7Ch] [ebp+76h]
  int v14; // [esp+80h] [ebp+7Ah]
  char v15; // [esp+84h] [ebp+7Eh]

  v3 = a1 + 12;
  memset(v10, 0, 42);
  memset(v12, 0, sizeof(v12));
  memset(v11, -1, sizeof(v11));
  v4 = sub_E0C1D((char *)a1, a2);
  v10[v4] = 1;
  v11[a2] = v4;
  v5 = 4 * *(uint8_t *)(a1 + 10);
  v15 = 0;
  v6 = (_DWORD *)(v3 + v5);
  while ( v3 < (unsigned int)v6 )
  {
    ++v12[*--v6 & 0xF];
    v14 = *v6 & 0xF;
    if ( v11[v14] == -1 )
    {
      v13 = (int16_t)sub_E0C1D((char *)a1, v14);
      v11[*v6 & 0xF] = v13;
      v10[v11[*v6 & 0xF]] = 1;
    }
  }
  for ( i = v11[a2]; i < 42; ++i )
  {
    if ( v10[i] )
    {
      v8 = 10;
      v9 = 0;
      do
      {
        if ( (int)v12[--v8] > 0 && i >= v11[v8] )
          v9 += v12[v8];
      }
      while ( v8 * 4 );
      if ( i <= v9 )
        v15 = 1;
    }
  }
  JUMPOUT(0xDF50C);
}
// E0D93: control flows out of bounds to DF50C
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (000E0D98) --------------------------------------------------------
int __fastcall sub_E0D98(unsigned int a1, int a2)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = 0;
  if ( a1 < 2 )
  {
    if ( a1 == 1 )
      v3 = 500;
  }
  else if ( a1 <= 2 || a1 == 4 )
  {
    v3 = 100;
  }
  sub_6E1A0(a2, &v3);
  return v3;
}


//----- (000E0DD6) --------------------------------------------------------
int __fastcall sub_E0DD6(char *a1, int a2)
{
  int v2; // ebx
  int16_t v3; // ax
  int16_t v4; // ax
  int16_t v5; // ax
  int v7; // [esp+0h] [ebp-Ch] BYREF
  int v8; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h] BYREF

  v2 = 0;
  if ( a2 <= 0 || a2 >= 49 )
  {
    if ( a2 <= -100 )
      return *(int16_t *)(-129 * (a2 + 100) + dword_197F9C + 94);
    if ( a2 <= -50 )
      return *(int16_t *)(-99 * (a2 + 50) + 3753 * *a1 + dword_197F98 + 900);
    if ( (uint16_t)a2 < 0xFFF4u )
    {
      if ( (uint16_t)a2 < 0xFFEFu )
        return v2;
      if ( (uint16_t)a2 <= 0xFFEFu )
      {
        v5 = *a1;
        v9 = 100;
        sub_6E1A0(v5, &v9);
        return v9;
      }
      if ( a2 != -15 )
        return v2;
    }
    else
    {
      if ( (uint16_t)a2 <= 0xFFF4u )
      {
        v4 = *a1;
        v8 = 500;
        sub_6E1A0(v4, &v8);
        return v8;
      }
      if ( (uint16_t)a2 < 0xFFF9u )
      {
        if ( a2 == -11 )
        {
          v3 = *a1;
          v7 = 100;
          sub_6E1A0(v3, &v7);
          return v7;
        }
        return v2;
      }
      if ( (uint16_t)a2 <= 0xFFF9u )
        return 100;
      if ( (uint16_t)a2 > 0xFFFCu )
        return v2;
    }
    return 50;
  }
  v2 = *(int *)((char *)&dword_17EB45 + 19 * a2);
  if ( (uint16_t)a2 < 0x17u )
  {
    if ( a2 != 8 )
      return v2;
LABEL_16:
    if ( a1[350] )
      v2 -= dword_17EE3D;
    return v2;
  }
  if ( (uint16_t)a2 <= 0x17u )
  {
    if ( a1[334] )
    {
      v2 -= dword_17ED0D;
      return v2;
    }
  }
  else
  {
    if ( (uint16_t)a2 >= 0x29u )
    {
      if ( (uint16_t)a2 > 0x29u )
      {
        if ( a2 == 44 )
          v2 += 250 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 12);
        return v2;
      }
      if ( a1[318] )
      {
        v2 -= dword_17EBDD;
        return v2;
      }
      goto LABEL_16;
    }
    if ( a2 != 24 )
      return v2;
  }
  if ( a1[338] )
    v2 -= dword_17ED59;
  return v2;
}
// 17EB45: using guessed type int dword_17EB45;
// 17EBDD: using guessed type int dword_17EBDD;
// 17ED0D: using guessed type int dword_17ED0D;
// 17ED59: using guessed type int dword_17ED59;
// 17EE3D: using guessed type int dword_17EE3D;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;


//----- (000E0F95) --------------------------------------------------------
int __fastcall sub_E0F95(int a1)
{
  return sub_E0DD6((char *)a1, *(_WORD *)(a1 + 277));
}


//----- (000E0FA4) --------------------------------------------------------
int __fastcall sub_E0FA4(int a1)
{
  int16_t v2; // ax
  int result; // eax
  int16_t v4; // cx

  v2 = sub_E0DD6((char *)a1, *(_WORD *)(a1 + 277));
  if ( v2 <= *(int16_t *)(a1 + 293) )
    return 1;
  v4 = *(_WORD *)(a1 + 233) - *(uint8_t *)(a1 + 240);
  if ( v4 <= 0 )
    return -1;
  result = (v4 + v2 - *(int16_t *)(a1 + 293) - 1) / v4;
  if ( (int16_t)result <= 0 )
    return 1;
  return result;
}


//----- (000E1002) --------------------------------------------------------
void __fastcall sub_E1002(char *a1, unsigned int a2, int a3)
{
  int v3; // esi

  if ( a2 < 0xFFFFFFDA || a2 > 0xFFFFFFDB && a2 < 0xFFFFFFFD )
  {
    v3 = (int16_t)sub_E0DD6(a1, a2);
    if ( v3 > a3 && v3 / 2 > a3 && v3 / 10 > a3 )
      JUMPOUT(0xE0B46);
  }
  JUMPOUT(0xE0B48);
}
// E1058: control flows out of bounds to E0B48
// E1080: control flows out of bounds to E0B46


//----- (000E1085) --------------------------------------------------------
void __fastcall sub_E1085(int a1)
{
  sub_E1002((char *)a1, *(int16_t *)(a1 + 277), *(int16_t *)(a1 + 293));
}


//----- (000E109D) --------------------------------------------------------
int __fastcall sub_E109D( int a1)
{
  char *v1; // ebx
  int v2; // edx
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int result; // eax

  v1 = (char *)(361 * a1 + dword_192B18);
  v2 = 3753 * *v1 + dword_197F98;
  sub_E1085((int)v1);
  *(_DWORD *)(v2 + 50) -= v3;
  v4 = *(int16_t *)(v1 + 277);
  v5 = sub_E0DD6(v1, v4);
  LOWORD(v4) = *(_WORD *)(v1 + 293);
  result = v5 - v4;
  *((_WORD *)v1 + 150) = result;
  return result;
}
// E10C6: variable 'v3' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000E10EA) --------------------------------------------------------
_BOOL1 __fastcall sub_E10EA( int a1)
{
  char *v1; // ecx
  int v2; // eax

  v1 = (char *)(361 * a1 + dword_192B18);
  sub_E1002(v1, *(int16_t *)(v1 + 277), *(int16_t *)(v1 + 293));
  return v2 <= *(_DWORD *)(dword_197F98 + 3753 * *v1 + 50);
}
// E1124: variable 'v2' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000E112B) --------------------------------------------------------
char __fastcall sub_E112B(int a1)
{
  int v1; // eax
  int16_t *v2; // esi
  char v3; // dl
  int16_t *v4; // eax
  int v5; // ebx
  uint8_t v6; // bl

  v1 = 113 * a1 + dword_19306C;
  v2 = (int16_t *)(v1 + 74);
  v3 = 0;
  v4 = (int16_t *)(v1 + 84);
  do
  {
    v5 = *--v4;
    if ( v5 != -1 )
    {
      v6 = *(_BYTE *)(17 * v5 + dword_1930D4 + 4);
      if ( v6 )
      {
        if ( v6 <= 2u )
          v3 = 1;
      }
    }
  }
  while ( v4 != v2 );
  return v3;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000E116F) --------------------------------------------------------
void __fastcall sub_E116F(int a1)
{
  int v2; // ebx
  int v3; // ecx
  int16_t *v4; // ebx
  int v5; // eax
  int v6; // eax

  if ( !sub_E112B(a1) )
  {
    v2 = 113 * a1;
    v3 = v2 + dword_19306C + 74;
    v4 = (int16_t *)(v2 + dword_19306C + 84);
    do
    {
      v5 = *--v4;
      if ( v5 != -1 )
      {
        v6 = *(int16_t *)(dword_1930D4 + 17 * v5);
        if ( v6 != -1 )
          sub_B206F(v6, 48);
      }
    }
    while ( v4 != (int16_t *)v3 );
  }
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000E11BC) --------------------------------------------------------
void __fastcall sub_E11BC(char *a1, int a2)
{
  _BYTE *v3; // esi
  int16_t v4; // si
  int v5; // eax
  int16_t *v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  _BYTE *v10; // eax
  unsigned int i; // eax
  unsigned int v12; // esi
  int v13; // edi
  unsigned int v14; // eax
  _BOOL1 v15; // zf
  int v16; // [esp+0h] [ebp-18h]
  char *v17; // [esp+8h] [ebp-10h]
  int16_t v18; // [esp+14h] [ebp-4h]

  v3 = (_BYTE *)(dword_197F98 + 3753 * *a1);
  if ( a2 > 0 && a2 < 49 )
  {
    if ( v3[*(int16_t *)((char *)&word_17EB43 + 19 * a2) + 279] == 3 && !a1[a2 + 310] )
    {
      if ( (uint16_t)a2 < 0x14u )
      {
        if ( (uint16_t)a2 < 9u )
        {
          if ( (uint16_t)a2 < 3u )
          {
            if ( a2 == 1 )
            {
              v12 = (unsigned int)&a1[4 * (uint8_t)a1[10] + 12];
              v13 = -1;
              while ( v12 > (unsigned int)(a1 + 12) )
              {
                v12 -= 4;
                if ( (*(_BYTE *)(v12 + 1) & 4) != 0 )
                  break;
                v14 = *(_DWORD *)v12 & 0xF;
                if ( v14 < 8 )
                {
                  if ( v13 == -1 )
                  {
                    v13 = *(_DWORD *)v12 & 0xF;
                  }
                  else if ( v13 != v14 && *(char *)(dword_197F98 + 3753 * *a1 + 2207) / 2 != 3 )
                  {
                    break;
                  }
                }
              }
            }
          }
          else if ( (uint16_t)a2 <= 3u )
          {
            v16 = dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 2);
            v7 = v16 + 10;
            do
            {
              v8 = *(int16_t *)(v7 + 72);
              v7 -= 2;
              if ( v8 != -1 )
              {
                v9 = *(int16_t *)(dword_1930D4 + 17 * v8);
                v18 = v9;
                if ( v9 != -1 )
                {
                  v10 = (_BYTE *)(dword_192B18 + 361 * v9);
                  if ( *v10 == *a1 && !v10[a2 + 310] )
                    sub_AFE0C(v18, 3);
                }
              }
            }
            while ( v7 != v16 );
          }
        }
        else if ( a2 == 11 )
        {
          v4 = 5;
          while ( v4 > 0 )
          {
            v5 = *(int16_t *)(dword_19306C
                            + 113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 2)
                            + 74
                            + 2 * --v4);
            if ( v5 != -1 )
            {
              v6 = (int16_t *)(dword_1930D4 + 17 * v5);
              if ( *((_BYTE *)v6 + 4) == 3 && *v6 == -1 )
                break;
            }
          }
        }
      }
      else if ( (uint16_t)a2 > 0x14u )
      {
        if ( (uint16_t)a2 < 0x20u )
        {
          if ( a2 == 25 )
          {
            v17 = a1 + 12;
            for ( i = (unsigned int)&a1[4 * (uint8_t)a1[10] + 12]; i > (unsigned int)v17; i -= 4 )
              ;
          }
        }
        else if ( a2 == 48 )
        {
          sub_E112B(*(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 2));
        }
      }
    }
LABEL_62:
    JUMPOUT(0xDEB17);
  }
  if ( a2 <= -50 || (uint16_t)a2 < 0xFFFAu )
    goto LABEL_62;
  if ( (uint16_t)a2 < 0xFFFCu )
  {
    if ( (uint16_t)a2 <= 0xFFFAu )
    {
      if ( v3[286] != 3 )
        goto LABEL_62;
      goto LABEL_61;
    }
    v15 = v3[287] == 3;
  }
  else
  {
    if ( (uint16_t)a2 > 0xFFFCu )
      goto LABEL_62;
    v15 = v3[285] == 3;
  }
  if ( !v15 )
    goto LABEL_62;
LABEL_61:
  sub_E0C9B((int)a1, 8);
  goto LABEL_62;
}
// E1834: control flows out of bounds to DEB17
// 17EB43: using guessed type int16_t word_17EB43;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;


//----- (000E1839) --------------------------------------------------------
void __fastcall sub_E1839(char *a1)
{
  char *v2; // eax
  _BOOL1 v3; // al
  int v4; // ebx
  int v5; // edx
  int v6; // edi
  int v7; // esi
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // edi
  int v12; // eax
  char *v13; // edi
  char *v14; // esi
  int v15; // ebx
  char *v16; // eax
  int i; // ebx
  int v18; // edi
  char *v19; // ebx
  int v20; // eax
  int v21; // ebx
  char *j; // edi
  int v23; // esi
  int v24; // eax
  char v25; // zf
  int v26; // eax
  int v27; // eax
  _BYTE v28[12]; // [esp+0h] [ebp-58h] BYREF
  _BYTE v29[12]; // [esp+Ch] [ebp-4Ch] BYREF
  int v30; // [esp+18h] [ebp-40h]
  int v31; // [esp+1Ch] [ebp-3Ch]
  int v32; // [esp+20h] [ebp-38h]
  int v33; // [esp+24h] [ebp-34h]
  int v34; // [esp+28h] [ebp-30h]
  int v35; // [esp+2Ch] [ebp-2Ch]
  int v36; // [esp+30h] [ebp-28h]
  int v37; // [esp+34h] [ebp-24h]
  int v38; // [esp+38h] [ebp-20h]
  int v39; // [esp+3Ch] [ebp-1Ch]
  int v40; // [esp+40h] [ebp-18h]
  int v41; // [esp+44h] [ebp-14h]
  int v42; // [esp+48h] [ebp-10h]
  int v43; // [esp+4Ch] [ebp-Ch]
  _BOOL1 v44; // [esp+50h] [ebp-8h]
  _BOOL1 v45; // [esp+54h] [ebp-4h]

  v43 = (uint8_t)a1[10];
  if ( !v43 )
  {
    memset(a1 + 200, 0, 20);
    v2 = a1 + 180;
LABEL_3:
    memset(v2, 0, 20);
LABEL_88:
    JUMPOUT(0xE1F97);
  }
  if ( sub_2341E((int)&a1[-dword_192B18] / 361) )
  {
    v2 = a1 + 200;
    goto LABEL_3;
  }
  v45 = sub_23509((int)&a1[-dword_192B18] / 361);
  v3 = sub_234B8((int)&a1[-dword_192B18] / 361);
  v4 = *(int16_t *)(a1 + 231) + *(int16_t *)(a1 + 243);
  v5 = (uint8_t)a1[252];
  v44 = v3;
  v33 = v5;
  v6 = (uint8_t)a1[256];
  v32 = (uint8_t)a1[253];
  v7 = (uint8_t)a1[257];
  v40 = (uint8_t)a1[254];
  v8 = *(int16_t *)(a1 + 233);
  v34 = (uint8_t)a1[255];
  v9 = 2 * v4;
  v42 = (uint8_t)a1[258];
  v10 = 2 * v8;
  v41 = (uint8_t)a1[259];
  while ( v9 > 0 && v33 > 0 )
  {
    --v33;
    --v9;
  }
  while ( v9 > 0 && v32 > 0 )
  {
    --v32;
    --v9;
  }
  while ( v9 > 0 && v40 > 0 )
  {
    --v40;
    --v9;
  }
  while ( v9 > 0 && v34 > 0 )
  {
    --v34;
    --v9;
  }
  while ( v10 > 0 && v6 > 0 )
  {
    --v10;
    --v6;
  }
  while ( v10 > 1 && v7 > 1 )
  {
    v10 -= 2;
    v7 -= 2;
  }
  while ( v10 > 0 && v42 > 0 )
  {
    --v42;
    --v10;
  }
  while ( v10 > 0 && v41 > 0 )
  {
    --v41;
    --v10;
  }
  v11 = v33 + v6;
  memset(a1 + 200, 0, 20);
  if ( v11 <= 0 )
    *(_WORD *)&a1[2 * *a1 + 200] = 0;
  else
    *(_WORD *)&a1[2 * *a1 + 200] = -25 * v11;
  if ( v7 <= 0 )
    *((_WORD *)a1 + 108) = 0;
  else
    *((_WORD *)a1 + 108) = -500 * v7;
  v12 = v42 + v41 + v32 + v40;
  if ( v12 <= 0 )
  {
    v16 = a1;
    for ( i = 0; i < word_199998; ++i )
    {
      if ( i != *a1 )
        *((_WORD *)v16 + 100) = 0;
      v16 += 2;
    }
  }
  else
  {
    v13 = a1;
    v14 = a1;
    v15 = 0;
    v37 = -25 * v12;
    while ( v15 < word_199998 )
    {
      if ( v15 != *a1 )
      {
        v36 = v37
            * ((uint8_t)v13[260] + (uint8_t)v13[268])
            / ((uint8_t)a1[258] + (uint8_t)a1[259] + (uint8_t)a1[253] + (uint8_t)a1[254]);
        *((_WORD *)v14 + 100) += v36;
      }
      ++v13;
      v14 += 2;
      ++v15;
    }
  }
  if ( v34 <= 0 )
    *((_WORD *)a1 + 109) = 0;
  else
    *((_WORD *)a1 + 109) = -25 * v34;
  memset(v28, 0, 10);
  v18 = v43;
  memset(v29, 0, 10);
  v19 = &a1[4 * v18];
  while ( v18 > 0 )
  {
    v20 = *((_DWORD *)v19 + 2) & 0xF;
    v19 -= 4;
    ++v28[v20];
    --v18;
    if ( (v19[13] & 4) != 0 )
      ++v29[*((_DWORD *)v19 + 3) & 0xF];
  }
  v21 = word_199998;
  v38 = 3753 * word_199998;
  for ( j = &a1[2 * word_199998]; ; *((_WORD *)j + 100) += v30 )
  {
    do
    {
      if ( v21 <= 0 )
        goto LABEL_88;
      --v21;
      v38 -= 3753;
      j -= 2;
    }
    while ( !v28[v21] );
    v35 = (int16_t)sub_E0C1D(a1, v21);
    if ( v35 <= v43 )
    {
      v30 = 0;
      continue;
    }
    v39 = sub_DD9F2(a1);
    v23 = *(char *)(dword_197F98 + v38 + 2208) + 100;
    v24 = dword_197F98 + 3753 * *a1;
    v31 = 0;
    sub_16946E();
    if ( v25 )
    {
      v23 += 50;
    }
    else if ( *(_BYTE *)(v24 + 386) == 3 )
    {
      v23 += 25;
    }
    if ( v39 != -1 )
    {
      v26 = dword_1930DC + 59 * v39;
      if ( (*(_BYTE *)(v26 + 43) & 8) != 0 )
      {
        v27 = 15 * ((int16_t)sub_94951(v39) + 1);
LABEL_69:
        v23 += v27;
        goto LABEL_70;
      }
      if ( (*(_BYTE *)(v26 + 43) & 4) != 0 )
      {
        v27 = 10 * ((int16_t)sub_94951(v39) + 1);
        goto LABEL_69;
      }
    }
LABEL_70:
    if ( a1[320] )
      v31 += 100 * (uint8_t)v28[v21] / v43;
    if ( v45 )
      v23 += 100;
    if ( v44 )
      v23 -= 200;
    if ( *(int16_t *)(a1 + 277) == -3 )
    {
      v36 = *(int16_t *)(a1 + 233);
      v23 += 40 * (v36 - (uint8_t)a1[240]) / v43;
    }
    if ( v21 == *a1 || !v29[v21] )
    {
      v36 = 3753 * *a1;
      if ( *(_BYTE *)(v36 + dword_197F98 + 40) != 100 )
        v23 += (uint8_t)byte_199CB0;
    }
    else if ( v23 > 0 && !a1[303] )
    {
      v36 = (uint8_t)v28[v21];
      v23 = v23 * (v36 - (uint8_t)v29[v21]) / v36;
    }
    v30 = v23 * sub_134C92(2000 * (uint8_t)v28[v21] * (v35 - v43) / v35) / 100 + v31;
  }
}
// E1875: control flows out of bounds to E1F97
// E1B9F: variable 'v25' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (000E1CED) --------------------------------------------------------
int __fastcall sub_E1CED(char *a1)
{
  char v2; // al
  int result; // eax

  v2 = *(_BYTE *)(17 * *((int16_t *)a1 + 1) + dword_1930D4 + 8);
  a1[226] = v2;
  if ( v2 == 1 && (a1[333] || a1[334] || a1[338]) )
    a1[226] = 2;
  result = sub_DE03E((int)a1, *a1, 0);
  if ( (_WORD)result )
    a1[224] = -1;
  else
    a1[224] = 0;
  return result;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (000E1D59) --------------------------------------------------------
void __fastcall sub_E1D59(char *a1)
{
  char v2; // al
  int v3; // edx
  int16_t v4; // ax

  memset(a1 + 239, 0, 4);
  a1[221] = sub_DE03E((int)a1, *a1, 0);
  sub_E1CED(a1);
  v2 = sub_DEC95((int)a1, *a1, 0);
  v3 = *a1;
  a1[222] = v2;
  a1[223] = sub_DFDC6((int)a1, v3, 0);
  sub_DDB25(a1, 0);
  sub_DF546((uint8_t *)a1);
  sub_DEE1B(a1, 0);
  sub_DE664((int)a1, 0);
  sub_DEB4B((uint8_t *)a1);
  sub_DF66F((int)a1);
  v4 = (uint8_t)a1[240];
  if ( v4 >= *(int16_t *)(a1 + 233) )
    v4 = *(_WORD *)(a1 + 233);
  *(_WORD *)(a1 + 245) = v4;
  sub_DFF74((int)a1, 0);
  sub_E08F6(a1);
  sub_E03F1(a1, 0);
  sub_E094F((int)a1);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (000E1E1F) --------------------------------------------------------
char __fastcall sub_E1E1F(int a1)
{
  int16_t v2; // dx
  int16_t v3; // cx
  int16_t v4; // ax
  int16_t v5; // si
  int v6; // eax
  char v8; // [esp+0h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  v4 = 0;
  v8 = 0;
  do
  {
    v5 = *(_WORD *)(a1 + 2 * v4 + 231);
    v2 += v5;
    if ( v3 < v5 )
    {
      v8 = v4;
      v3 = *(_WORD *)(a1 + 2 * v4 + 231);
    }
    ++v4;
  }
  while ( v4 < 3 );
  v6 = v2 / 2;
  if ( v6 >= v3 )
  {
    *(_BYTE *)(a1 + 11) = -1;
  }
  else
  {
    LOBYTE(v6) = v8;
    *(_BYTE *)(a1 + 11) = v8;
  }
  return v6;
}


//----- (000E1E84) --------------------------------------------------------
void __usercall sub_E1E84(char *a1, int a2)
{
  sub_E1D59(a1);
  sub_DF8F0(*a1, a1, a2);
}


//----- (000E1E96) --------------------------------------------------------
int __fastcall sub_E1E96(int a1, int a2)
{
  int result; // eax

  result = 0;
  if ( a2 > 0 )
  {
    result = *(int *)((char *)&dword_17D916 + 23 * a2);
    if ( a2 >= 75 )
      result += 10000 * *(uint8_t *)(a1 + a2 + 465);
  }
  return result;
}
// 17D916: using guessed type int dword_17D916;


//----- (000E1EC6) --------------------------------------------------------
int __fastcall sub_E1EC6(int a1, int a2, int a3)
{
  int result; // eax

  result = 0;
  if ( a3 > 0 && a3 < a1 )
  {
    result = 100 * (a1 - a3) / a3;
    if ( result <= 100 )
    {
      if ( !result )
        return 1;
    }
    else
    {
      return 100;
    }
  }
  return result;
}


//----- (000E1EF4) --------------------------------------------------------
int __fastcall sub_E1EF4(int a1)
{
  int v2; // eax

  v2 = sub_E1E96(a1, *(uint8_t *)(a1 + 801));
  return sub_E1EC6(*(int16_t *)(a1 + 172) + *(_DWORD *)(a1 + 491), *(int16_t *)(a1 + 172), v2);
}


//----- (000E1F24) --------------------------------------------------------
int __fastcall sub_E1F24(int a1)
{
  int v2; // edx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  int v8; // [esp+0h] [ebp-8h]
  int v9; // [esp+4h] [ebp-4h]

  v2 = *(uint8_t *)(a1 + 801);
  if ( *(_BYTE *)(v2 + a1 + 196) == 3 )
    return 0;
  v4 = *(int16_t *)(a1 + 172);
  v5 = sub_E1E96(a1, v2);
  v8 = v5;
  v6 = *(_DWORD *)(a1 + 491);
  if ( !v4 && v6 <= v5 )
    return -1;
  v9 = 0;
  v3 = 0;
  while ( v6 <= v5 )
  {
    ++v3;
    v6 += v4;
  }
  while ( v9 < 100 )
  {
    v6 += v4;
    ++v3;
    v9 += sub_E1EC6(v6, v4, v8);
  }
  return v3;
}


//----- (000E1F9E) --------------------------------------------------------
_BOOL1 __fastcall sub_E1F9E(int a1)
{
  char v1; // dl

  v1 = 0;
  if ( *(_BYTE *)(a1 + 57) == 1 && !*(_BYTE *)(a1 + 55) && *(_BYTE *)(a1 + 35) == 1 )
    return sub_242CF(*(_WORD *)(a1 + 53));
  return v1;
}


//----- (000E1FC7) --------------------------------------------------------
int __fastcall sub_E1FC7(int a1, int a2)
{
  int result; // eax

  result = (*(int16_t *)(dword_197F98 + 3753 * a2 + 174) - *(_DWORD *)(dword_197F98 + 3753 * a2 + 3704))
         * *(int16_t *)(dword_197F98 + 3753 * a2 + 2 * a1 + 1599)
         / 20;
  if ( result < 0 )
    return 0;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (000E2000) --------------------------------------------------------
void __fastcall sub_E2000(int a1, int a2)
{
  int v4; // eax
  unsigned int v5; // ebx
  int16_t v6; // ax
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int v10; // edi
  char *v11; // eax
  int16_t v12; // dx
  int v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // edi
  _BYTE *v19; // eax
  int v20; // edx
  int v21; // ebx
  int v22; // edi
  int v23; // eax
  int v24; // eax
  char *v25; // eax
  int v26; // esi
  int16_t v27; // ax
  int v28; // edx
  int v29; // eax
  int16_t i; // si
  int16_t v31; // ax
  int v32; // ebx
  int v33; // esi
  int v34; // esi
  int v35; // eax
  _DWORD v36[9]; // [esp+0h] [ebp-58h] BYREF
  int v37; // [esp+24h] [ebp-34h]
  int v38; // [esp+28h] [ebp-30h]
  int v39; // [esp+2Ch] [ebp-2Ch]
  int v40; // [esp+30h] [ebp-28h]
  int v41; // [esp+34h] [ebp-24h]
  int v42; // [esp+38h] [ebp-20h]
  int v43; // [esp+3Ch] [ebp-1Ch]
  int v44; // [esp+40h] [ebp-18h]
  int v45; // [esp+44h] [ebp-14h]
  int v46; // [esp+48h] [ebp-10h]
  int v47; // [esp+4Ch] [ebp-Ch]
  int v48; // [esp+50h] [ebp-8h]
  int v49; // [esp+54h] [ebp-4h]

  v4 = (a1 - dword_197F98) / 3753;
  v42 = -1;
  *(_WORD *)(a1 + 58) = 0;
  v49 = v4;
  *(_WORD *)(a1 + 60) = 0;
  memset(a1 + 184, 0, 12);
  v41 = 0;
  v5 = dword_1930DC + 3953;
  while ( v5 > dword_1930DC )
  {
    v6 = *(char *)(v5 - 1);
    v5 -= 59;
    if ( v6 == (_WORD)v49 && *(_BYTE *)(v5 + 57) < 3u && !sub_E1F9E(v5) )
    {
      v47 = 59;
      *(_WORD *)(a1 + 194) += sub_94A9D(v49, (int)(v5 - dword_1930DC) / 59);
      v47 = 59;
      v7 = (int)(v5 - dword_1930DC) / 59;
      v8 = 0;
      if ( (*(_BYTE *)(v5 + 39) & 8) != 0 )
      {
        v8 = 3 * ((int16_t)sub_94951(v7) + 1);
      }
      else if ( (*(_BYTE *)(v5 + 39) & 4) != 0 )
      {
        v8 = 2 * (int16_t)sub_94951(v7) + 2;
      }
      if ( v8 > v41 )
      {
        v47 = 59;
        v41 = v8;
        v42 = (int)(v5 - dword_1930DC) / 59;
      }
    }
  }
  v45 = -1;
  v9 = 0;
  v10 = 0;
  v39 = 0;
  v40 = 0;
  v38 = 0;
  v44 = 0;
  v11 = (char *)(dword_192B18 + 361 * word_199996);
  while ( (unsigned int)v11 > dword_192B18 )
  {
    v11 -= 361;
    if ( *v11 == (_WORD)v49 && !v11[6] )
    {
      *(_WORD *)(a1 + 184) += (uint8_t)v11[242];
      if ( *(_BYTE *)(a1 + 2237) )
        v44 += 2;
      if ( v11[350] )
      {
        ++v9;
      }
      else if ( v11[318] )
      {
        ++v39;
      }
      else if ( v11[351] )
      {
        ++v10;
      }
    }
  }
  if ( *(_BYTE *)(a1 + 370) == 3 )
  {
    v45 = 91;
    v40 = 3;
  }
  else if ( *(_BYTE *)(a1 + 455) == 3 )
  {
    v45 = 176;
    v40 = 2;
  }
  else if ( *(_BYTE *)(a1 + 459) == 3 )
  {
    v45 = 180;
    v40 = 1;
  }
  v40 *= v10 + v9 + v39;
  v48 = v9 + 5;
  v12 = v41 + v40 + 2 * v39 + v9 + 5 + 3 * v10 + v44;
  *(_WORD *)(a1 + 58) = v12;
  if ( *(_BYTE *)(a1 + 2207) == 3 )
  {
    v38 = v12 / 2;
    *(_WORD *)(a1 + 58) += v12 / 2;
  }
  if ( a2 )
  {
    v13 = sprintf(a2, "%d %s\n", 5, (char *)dword_1AA2E0) + a2;
    if ( v9 )
    {
      if ( v9 == 1 )
        v14 = sprintf(v13, (char *)dword_1AA2B4, 1);
      else
        v14 = sprintf(v13, (char *)dword_1AA2F0, v9, v9);
      v13 += v14;
    }
    if ( v39 )
    {
      if ( v39 == 1 )
        v15 = sprintf(v13, (char *)dword_1AA288, 2);
      else
        v15 = sprintf(v13, (char *)dword_1AA260, 2 * v39, v39);
      v13 += v15;
    }
    if ( v10 )
    {
      if ( v10 == 1 )
        v16 = sprintf(v13, (char *)dword_1AA28C, 3);
      else
        v16 = sprintf(v13, (char *)dword_1AA258, 3 * v10, v10);
      v13 += v16;
    }
    if ( v40 )
      v13 += sprintf(v13, "%d : %s\n", v40, *(char **)((char *)&off_17E079 + 13 * v45));
    if ( v41 )
      v13 += sprintf(v13, "%d : %s\n", v41, (char *)(59 * v42 + dword_1930DC));
    if ( v44 )
      v13 += sprintf(v13, "%d %s\n", v44, (char *)dword_1AA270);
    if ( v38 )
      v13 += sprintf(v13, "%d %s\n", v38, (char *)dword_1AA264);
    if ( *(int16_t *)(a1 + 58) > 5 )
      v13 += sprintf(v13, "%d %s\n", *(int16_t *)(a1 + 58), (char *)dword_1AA274);
    a2 = sprintf(v13, asc_179FF1) + v13;
  }
  if ( *(int16_t *)(a1 + 56) > 0 )
    v17 = *(int16_t *)(a1 + 54) - *(int16_t *)(a1 + 56);
  else
    v17 = *(int16_t *)(a1 + 54);
  *(_WORD *)(a1 + 186) = v17 / 2;
  v46 = 0;
  v37 = 0;
  memset(v36, 0, sizeof(v36));
  v18 = 0;
  while ( word_199994 > v37 )
  {
    v19 = (_BYTE *)(v18 + dword_197F9C);
    if ( *(char *)(v18 + dword_197F9C + 99) == (_WORD)v49 && (char)v19[100] <= 2 && !v19[128] )
    {
      if ( v19[17] )
        ++v46;
      else
        ++v36[(uint8_t)v19[16]];
      *(_WORD *)(a1 + 60) += (uint8_t)v19[16] + 1;
    }
    ++v37;
    v18 += 129;
  }
  if ( a2 )
  {
    v20 = 0;
    v21 = 0;
    v22 = 0;
    do
    {
      if ( v36[v21] )
      {
        v43 = v20 + 1;
        if ( v36[v21] == 1 )
          v23 = sprintf(a2, (char *)dword_1AA284, v20 + 1, *(_UNKNOWN **)((char *)&off_18003A + v22));
        else
          v23 = sprintf(
                  a2,
                  (char *)dword_1AA254,
                  v43 * v36[v21],
                  v36[v21],
                  *(_UNKNOWN **)((char *)&off_18003E + v22));
        a2 += v23;
      }
      ++v21;
      ++v20;
      v22 += 36;
    }
    while ( v20 < 9 );
    if ( v46 )
    {
      if ( v46 == 1 )
        v24 = sprintf(a2, (char *)dword_1AA26C, 1);
      else
        v24 = sprintf(a2, (char *)dword_1AA280, v46, v46);
      a2 += v24;
    }
    if ( *(_WORD *)(a1 + 60) == 1 )
      v25 = (char *)dword_1AA27C;
    else
      v25 = (char *)dword_1AA268;
    v26 = sprintf(a2, "%d %s\n", *(int16_t *)(a1 + 60), v25) + a2;
    a2 = sprintf(v26, asc_179FF1) + v26;
  }
  if ( *(_WORD *)(a1 + 60) )
  {
    v27 = *(_WORD *)(a1 + 60);
    if ( v27 > *(int16_t *)(a1 + 58) )
    {
      v28 = v27 - *(int16_t *)(a1 + 58);
      if ( *(_BYTE *)(a1 + 40) == 100 )
        v29 = 10;
      else
        v29 = 12 - (uint8_t)byte_199CB0;
      *(_WORD *)(a1 + 188) = v28 * v29;
      if ( a2 )
        sprintf(
          a2,
          "(%s %d * %d + %d * %d : %d BC)\n",
          (char *)dword_1AA278,
          0,
          *(int16_t *)(a1 + 58),
          v29,
          v28,
          (int16_t)(v28 * v29));
    }
    else
    {
      *(_WORD *)(a1 + 188) = 0;
      if ( a2 )
        sprintf(a2, "(%s 0 BC)\n", (char *)dword_1AA278);
    }
  }
  else
  {
    *(_WORD *)(a1 + 188) = 0;
  }
  for ( i = 0; i < word_199998; ++i )
  {
    v31 = sub_1026CF(v49, i);
    *(_WORD *)(a1 + 190) += v31;
  }
  v32 = word_199998;
  v33 = 2 * word_199998;
  *(_WORD *)(a1 + 192) = 0;
  v34 = a1 + v33;
  while ( v32 > 0 )
  {
    v34 -= 2;
    --v32;
    if ( *(_WORD *)(v34 + 1599) )
      *(_WORD *)(a1 + 192) += sub_E1FC7(v32, (a1 - dword_197F98) / 3753);
  }
  v35 = 6;
  *(_DWORD *)(a1 + 180) = 0;
  do
    *(_DWORD *)(a1 + 180) += *(int16_t *)(a1 + 2 * (int16_t)--v35 + 184);
  while ( (int16_t)v35 > 0 );
  JUMPOUT(0xDEB17);
}
// E263F: control flows out of bounds to DEB17
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 18003A: using guessed type _UNKNOWN *off_18003A;
// 18003E: using guessed type _UNKNOWN *off_18003E;
// 192B18: using guessed type int dword_192B18;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;
// 1AA254: using guessed type int dword_1AA254;
// 1AA258: using guessed type int dword_1AA258;
// 1AA260: using guessed type int dword_1AA260;
// 1AA264: using guessed type int dword_1AA264;
// 1AA268: using guessed type int dword_1AA268;
// 1AA26C: using guessed type int dword_1AA26C;
// 1AA270: using guessed type int dword_1AA270;
// 1AA274: using guessed type int dword_1AA274;
// 1AA278: using guessed type int dword_1AA278;
// 1AA27C: using guessed type int dword_1AA27C;
// 1AA280: using guessed type int dword_1AA280;
// 1AA284: using guessed type int dword_1AA284;
// 1AA288: using guessed type int dword_1AA288;
// 1AA28C: using guessed type int dword_1AA28C;
// 1AA2B4: using guessed type int dword_1AA2B4;
// 1AA2E0: using guessed type int dword_1AA2E0;
// 1AA2F0: using guessed type int dword_1AA2F0;


//----- (000E2644) --------------------------------------------------------
void __fastcall sub_E2644(int a1)
{
  _BYTE v1[3000]; // [esp+0h] [ebp-BB8h] BYREF

  sub_E2000(3753 * a1 + dword_197F98, (int)v1);
  JUMPOUT(0xDDF24);
}
// E266C: control flows out of bounds to DDF24
// 197F98: using guessed type int dword_197F98;
// 1AA25C: using guessed type int dword_1AA25C;


//----- (000E2671) --------------------------------------------------------
void __fastcall sub_E2671(int a1)
{
  char *v2; // eax
  int v3; // ebx
  char *v4; // ecx

  memset(a1, 0, 32);
  v2 = (char *)(dword_192B18 + 361 * word_199996);
  while ( (unsigned int)v2 > dword_192B18 )
  {
    v2 -= 361;
    if ( *v2 != -1 && !v2[6] )
    {
      v3 = 931;
      v4 = v2 + 49;
      do
      {
        --v4;
        v3 -= 19;
        if ( v4[310] )
          *(_DWORD *)(a1 + 4 * *v2) += *(int *)((char *)&dword_17EB45 + v3);
      }
      while ( v3 > 0 );
    }
  }
  JUMPOUT(0xE1F98);
}
// E26DB: control flows out of bounds to E1F98
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17EB45: using guessed type int dword_17EB45;
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (000E26E0) --------------------------------------------------------
_BOOL1 __fastcall sub_E26E0(int a1, int a2)
{
  return *(char *)(a2 + 58) == (a1 - dword_197F98) / 3753 && *(_BYTE *)(a2 + 57) <= 1u;
}
// 197F98: using guessed type int dword_197F98;


//----- (000E2710) --------------------------------------------------------
void __fastcall sub_E2710(int a1)
{
  int v2; // edi
  char *v3; // esi
  int16_t v4; // dx
  unsigned int v5; // esi
  int v6; // eax
  unsigned int v7; // ecx
  int v8; // edx
  _BOOL1 v9; // al
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // esi
  int v14; // eax
  int v15; // esi
  int16_t v16; // ax
  int v17; // edi
  int16_t v18; // ax
  int16_t v19; // [esp+0h] [ebp-34h]
  int16_t v20; // [esp+4h] [ebp-30h]
  int v21; // [esp+Ch] [ebp-28h]
  int v22; // [esp+10h] [ebp-24h]
  int v23; // [esp+14h] [ebp-20h]
  int16_t v24; // [esp+18h] [ebp-1Ch]
  int v25; // [esp+1Ch] [ebp-18h]
  int v26; // [esp+20h] [ebp-14h]
  int16_t v27; // [esp+24h] [ebp-10h]
  int16_t v28; // [esp+28h] [ebp-Ch]
  int v29; // [esp+30h] [ebp-4h]

  v19 = 0;
  v20 = 0;
  v28 = 0;
  v2 = 0;
  v29 = 0;
  v24 = 0;
  v22 = (a1 - dword_197F98) / 3753;
  v27 = 0;
  v3 = (char *)(dword_192B18 + 361 * word_199996);
  while ( (unsigned int)v3 > dword_192B18 )
  {
    v3 -= 361;
    if ( *v3 == v22 && !v3[6] )
    {
      v19 += (uint8_t)v3[10];
      v4 = *(_WORD *)(v3 + 231);
      v20 += v4;
      if ( (((int)*(uint8_t *)(dword_19306C
                                     + 113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)v3 + 1) + 2)
                                     + 42) >> *v3)
          & 1) == 0 )
      {
        v24 += v4;
        v27 += (uint8_t)v3[239];
      }
      v28 += *(_WORD *)(v3 + 233);
      if ( !sub_23DFE((int)&v3[-dword_192B18] / 361) )
        v29 += *(int16_t *)(v3 + 235);
      v2 += *(int16_t *)(v3 + 237);
    }
  }
  v5 = dword_197F9C + 129 * word_199994;
  v25 = v5 + 23;
  while ( v5 > dword_197F9C )
  {
    v25 -= 129;
    v6 = *(char *)(v5 - 30);
    v5 -= 129;
    if ( v6 == v22 && (uint16_t)sub_1276F0(v25, 0x1Cu) && *(char *)(v5 + 100) < 4 )
      v29 += 1 << *(_BYTE *)(v5 + 16);
  }
  v7 = dword_1930DC + 3953;
  while ( 1 )
  {
    do
    {
      if ( v7 <= dword_1930DC )
      {
        v12 = word_199998;
        v13 = 2 * word_199998;
        v26 = word_199998 + a1;
        v14 = 3753 * word_199998;
        *(_DWORD *)(a1 + 3704) = 0;
        v15 = a1 + v13;
        v21 = v14;
        while ( v12 > 0 )
        {
          --v26;
          v21 -= 3753;
          v15 -= 2;
          --v12;
          if ( *(_BYTE *)(v26 + 1583) )
            v2 += *(int16_t *)(v15 + 1444);
          if ( *(_BYTE *)(v26 + 1591) )
          {
            v16 = *(_WORD *)(v15 + 1478);
            if ( v16 < 0 )
              v2 += v16;
            else
              v29 += v16;
          }
          v23 = (a1 - dword_197F98) / 3753;
          if ( *(_WORD *)(dword_197F98 + v21 + 2 * v23 + 1599) )
            *(_DWORD *)(a1 + 3704) += sub_E1FC7(v23, v12);
        }
        *(_WORD *)(a1 + 166) = v19;
        *(_WORD *)(a1 + 168) = v20;
        v17 = *(_DWORD *)(a1 + 3704) + v2;
        *(_WORD *)(a1 + 170) = v28;
        if ( v29 <= 0x7FFF )
          *(_WORD *)(a1 + 172) = v29;
        else
          *(_WORD *)(a1 + 172) = 0x7FFF;
        v18 = v24 - v27;
        *(_WORD *)(a1 + 176) = v24 - v27;
        if ( (int16_t)(v24 - v27) > 0 )
        {
          if ( !*(_BYTE *)(a1 + 2231) )
            v18 /= 2;
          v17 += v18;
        }
        if ( v17 > 0x7FFF )
          LOWORD(v17) = 0x7FFF;
        *(_WORD *)(a1 + 174) = v17;
        sub_E2000(a1, 0);
        *(_WORD *)(a1 + 178) = v17 - *(_WORD *)(a1 + 180);
        JUMPOUT(0xE1F97);
      }
      v8 = *(char *)(v7 - 1);
      v7 -= 59;
      v9 = v8 == (a1 - dword_197F98) / 3753 && *(_BYTE *)(v7 + 57) <= 1u;
    }
    while ( !v9 || sub_E1F9E(v7) );
    if ( (*(_BYTE *)(v7 + 39) & 2) != 0 )
    {
      v2 += 15;
    }
    else if ( (*(_BYTE *)(v7 + 39) & 1) != 0 )
    {
      v2 += 10;
    }
    v10 = (int)(v7 - dword_1930DC) / 59;
    if ( (*(_BYTE *)(v7 + 39) & 0x20) != 0 )
      break;
    if ( (*(_BYTE *)(v7 + 39) & 0x10) != 0 )
    {
      v11 = 5 * ((int16_t)sub_94951(v10) + 1);
LABEL_31:
      v29 += v11;
    }
  }
  v11 = 75 * ((int16_t)sub_94951(v10) + 1) / 10;
  goto LABEL_31;
}
// E2A6B: control flows out of bounds to E1F97
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;


//----- (000E2A70) --------------------------------------------------------
void __usercall sub_E2A70( int a1, int a2)
{
  int v2; // eax
  char *v3; // ebx

  v2 = 361 * a1;
  v3 = (char *)(v2 + dword_192B18);
  if ( !*(_BYTE *)(v2 + dword_192B18 + 6) )
  {
    sub_E1D59((char *)(v2 + dword_192B18));
    sub_DF8F0(*v3, v3, a2);
  }
  sub_E2710(dword_197F98 + 3753 * *v3);
}
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000E2AB1) --------------------------------------------------------
void __usercall sub_E2AB1( int a1, int a2, int a3)
{
  int v5; // ebx
  int v6; // edx
  int v7; // eax
  char *v8; // edx

  v5 = 10;
  do
  {
    v6 = *(int16_t *)(113 * a1 + dword_19306C + v5 + 72);
    v5 -= 2;
    if ( v6 != -1 )
    {
      v7 = *(int16_t *)(17 * v6 + dword_1930D4);
      if ( v7 != -1 )
      {
        v8 = (char *)(361 * v7 + dword_192B18);
        if ( *v8 == a2 && !v8[6] )
        {
          sub_E1D59(v8);
          sub_DF8F0(*v8, v8, a3);
        }
      }
    }
  }
  while ( v5 );
  sub_E2710(3753 * a2 + dword_197F98);
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000E2B31) --------------------------------------------------------
_BYTE *__usercall sub_E2B31(int a1, int a2)
{
  char *v2; // edx
  int16_t i; // cx
  char *v4; // edx
  int16_t j; // cx
  int v6; // eax
  int16_t k; // cx
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  char *v12; // eax
  _BYTE *result; // eax
  int v14; // edx

  nullsub_14(a1);
  v2 = (char *)(361 * word_199996 + dword_192B18);
  while ( (unsigned int)v2 > dword_192B18 )
  {
    v2 -= 361;
    if ( *v2 != -1 && !v2[6] )
      sub_E1D59(v2);
  }
  for ( i = 0; i < word_199998; ++i )
    sub_DF8F0(i, 0, a2);
  v4 = (char *)(361 * word_199996 + dword_192B18);
  while ( (unsigned int)v4 > dword_192B18 )
  {
    v4 -= 361;
    if ( *v4 != -1 && !v4[6] )
    {
      sub_E1839(v4);
      sub_E1E1F((int)v4);
    }
  }
  for ( j = 0; j < word_199998; ++j )
  {
    v6 = dword_197F98 + 3753 * j;
    sub_E2710(v6);
  }
  for ( k = 0; k < word_199998; ++k )
  {
    *(_WORD *)(dword_197F98 + 3753 * k + 1512) = 0;
    v8 = 83;
    do
    {
      --v8;
      v9 = 3753 * k + dword_197F98;
      if ( *(_BYTE *)(v8 + v9 + 196) == 3 )
        ++*(_WORD *)(v9 + 1512);
    }
    while ( v8 > 0 );
    v10 = 3753 * k;
    v11 = dword_197F98;
    *(_WORD *)(v10 + dword_197F98 + 1514) = 0;
    *(_WORD *)(v10 + v11 + 1548) = 0;
  }
  v12 = (char *)(dword_192B18 + 361 * word_199996);
  while ( (unsigned int)v12 > dword_192B18 )
  {
    v12 -= 361;
    if ( *v12 >= 0 && (uint8_t)v12[10] >= 5u )
      ++*(_WORD *)(3753 * *v12 + dword_197F98 + 1548);
  }
  result = (_BYTE *)(dword_197F9C + 129 * word_199994);
  while ( (unsigned int)result > dword_197F9C )
  {
    result -= 129;
    if ( (char)result[99] < 8 && (char)result[100] < 5 && !result[17] )
    {
      v14 = 3753 * (char)result[99] + dword_197F98;
      *(_WORD *)(v14 + 1514) += 1 << result[16];
    }
  }
  return result;
}
// FE8BD: using guessed type int __fastcall nullsub_14(_DWORD);
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;


//----- (000E2D09) --------------------------------------------------------
void __usercall sub_E2D09( int a1, int a2)
{
  char *v3; // edx
  int v4; // eax

  sub_DF8F0(a1, 0, a2);
  v3 = (char *)(361 * word_199996 + dword_192B18);
  while ( (unsigned int)v3 > dword_192B18 )
  {
    v3 -= 361;
    if ( *v3 == a1 && !v3[6] )
    {
      sub_E1839(v3);
      LOBYTE(v4) = sub_E1E1F((int)v3);
      sub_FE8BE(v4);
    }
  }
  JUMPOUT(0xE2AA9);
}
// E2D6D: control flows out of bounds to E2AA9
// E2D4F: variable 'v4' is possibly undefined
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;


//----- (000E2D72) --------------------------------------------------------
int __usercall sub_E2D72(int a1, int a2)
{
  int16_t v2; // bx
  char *v3; // edx
  int v4; // eax
  int v5; // eax

  v2 = a1;
  sub_FE8BE(a1);
  v3 = (char *)(dword_192B18 + 361 * word_199996);
  while ( (unsigned int)v3 > dword_192B18 )
  {
    v3 -= 361;
    if ( *v3 == v2 && !v3[6] )
    {
      sub_E1D59(v3);
      sub_FE8BE(v4);
    }
  }
  sub_E2D09(v2, a2);
  return sub_FE8BE(v5);
}
// E2DAD: variable 'v4' is possibly undefined
// E2DC2: variable 'v5' is possibly undefined
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (000E2DCA) --------------------------------------------------------
void __fastcall sub_E2DCA(char *a1)
{
  int16_t v2; // di
  unsigned int v3; // esi
  unsigned int v4; // eax
  int16_t i; // dx
  int v6; // eax
  int v7; // edx
  int16_t v8; // bx
  int16_t v9; // dx
  int16_t v10; // si
  int16_t v11; // dx
  char *v12; // eax
  int16_t v13; // bx
  char *v14; // esi
  int16_t v15; // di
  int j; // esi
  char *v17; // eax
  int16_t v18; // bx
  char v19; // al
  int16_t k; // dx
  int16_t v21; // dx
  int16_t v22; // di
  int v23; // eax
  char *v24; // esi
  int v25; // esi
  int v26; // eax
  char *v27; // eax
  char v28; // dl
  int16_t v29; // ax
  int16_t m; // dx
  int v31; // eax
  int v32; // eax
  int v33; // edx
  _WORD v34[10]; // [esp+0h] [ebp-22h] BYREF
  int16_t v35[9]; // [esp+14h] [ebp-Eh]
  int16_t v36[9]; // [esp+16h] [ebp-Ch] BYREF
  int v37; // [esp+28h] [ebp+6h] BYREF
  int v38; // [esp+2Ch] [ebp+Ah]
  int v39; // [esp+30h] [ebp+Eh]
  int v40; // [esp+34h] [ebp+12h]
  int16_t v41; // [esp+38h] [ebp+16h]
  int v42; // [esp+3Ch] [ebp+1Ah] BYREF
  int v43; // [esp+40h] [ebp+1Eh]
  int v44; // [esp+44h] [ebp+22h]
  int v45; // [esp+48h] [ebp+26h]
  int16_t v46; // [esp+4Ch] [ebp+2Ah]
  _DWORD v47[3]; // [esp+50h] [ebp+2Eh] BYREF
  _BYTE v48[12]; // [esp+5Ch] [ebp+3Ah] BYREF
  char *v49; // [esp+68h] [ebp+46h]
  char *v50; // [esp+6Ch] [ebp+4Ah]
  _DWORD *v51; // [esp+70h] [ebp+4Eh]
  char *v52; // [esp+74h] [ebp+52h]
  int v53; // [esp+78h] [ebp+56h]
  int v54; // [esp+7Ch] [ebp+5Ah]
  int v55; // [esp+80h] [ebp+5Eh]
  int16_t v56; // [esp+84h] [ebp+62h]
  int v57; // [esp+88h] [ebp+66h]
  int v58; // [esp+8Ch] [ebp+6Ah]
  int v59; // [esp+90h] [ebp+6Eh]
  int v60; // [esp+94h] [ebp+72h]
  int v61; // [esp+98h] [ebp+76h]
  int16_t v62; // [esp+9Ch] [ebp+7Ah]
  char v63; // [esp+A0h] [ebp+7Eh]

  if ( !sub_2341E((int)&a1[-dword_192B18] / 361) && a1[10] )
  {
    if ( !a1[303] )
    {
      v51 = 0;
      v2 = 0;
      v3 = (unsigned int)&a1[4 * (uint8_t)a1[10] + 12];
      while ( (unsigned int)(a1 + 12) < v3 )
      {
        v3 -= 4;
        v4 = *(_DWORD *)v3 & 0xF;
        if ( (v4 == 9 || v4 < 8 && v4 != *a1 && (*(_BYTE *)(v3 + 1) & 4) != 0) && sub_1247A0(++v2) == 1 )
          v51 = (_DWORD *)v3;
      }
      if ( v2 )
      {
        if ( v2 == 1 )
        {
          a1[303] = 4;
          memset(&v37, 0, 18);
          LOBYTE(v37) = 0;
          BYTE2(v37) = a1[2];
          HIBYTE(v37) = 2;
          LOBYTE(v38) = *v51 & 0xF;
          sub_EF629(v37, v38, v39, v40, v41, *a1);
        }
        *v51 = *(_DWORD *)&a1[4 * (uint8_t)--a1[10] + 12];
      }
      else
      {
        a1[303] = 4;
      }
    }
    if ( a1[10] )
    {
      v55 = 3753 * *a1 + dword_197F98;
      v63 = 0;
      memset(v34, 0, sizeof(v34));
      for ( i = 0; i < (uint8_t)a1[10]; ++i )
      {
        v6 = *(_DWORD *)&a1[4 * i + 12] & 0xF;
        ++v34[v6];
      }
      memset(v48, 0, 10);
      v7 = *a1;
      if ( (int16_t)v34[v7] <= 0 )
      {
        v8 = -1;
        v9 = word_199998;
        v10 = 0;
        while ( v9 > 0 )
        {
          if ( v10 < (int16_t)v34[--v9] )
          {
            v8 = v9;
            v10 = v34[v9];
          }
        }
        if ( v8 == -1 )
        {
          if ( v34[8] <= 0 )
            v48[9] = 1;
          else
            v48[8] = 1;
        }
        else
        {
          v48[v8] = 1;
        }
      }
      else
      {
        v48[v7] = 1;
      }
      v11 = 0;
      v50 = a1 + 12;
      do
      {
        if ( v11 < word_199998 || v11 == 8 || v11 == 9 )
        {
          v12 = &a1[2 * v11];
          if ( *((int16_t *)v12 + 100) < 0 )
          {
            v13 = *((_WORD *)v12 + 100);
            v63 = 1;
            *((_WORD *)v12 + 90) += v13;
            while ( 1 )
            {
              v14 = &a1[2 * v11];
              if ( *((int16_t *)v14 + 90) >= 0 )
                break;
              if ( (uint8_t)v48[v11] < (int16_t)v34[v11] )
              {
                v60 = -1;
                v58 = 0;
                v59 = -1;
                v15 = 0;
                for ( j = 0; (int16_t)j < (uint8_t)a1[10]; ++j )
                {
                  v17 = &v50[4 * (int16_t)j];
                  v53 = *(_DWORD *)v17 & 0xF;
                  v54 = v11;
                  if ( v53 == v11 )
                  {
                    if ( (*(_WORD *)v17 & 0x180) != 0 )
                    {
                      if ( sub_1247A0(++v15) == 1 )
                        v59 = j;
                    }
                    else if ( sub_1247A0((int16_t)++v58) == 1 )
                    {
                      v60 = j;
                    }
                  }
                }
                if ( v15 <= 0 )
                  v18 = v60;
                else
                  v18 = v59;
                --v34[v11];
                *(_DWORD *)&a1[4 * v18 + 12] = *(_DWORD *)&a1[4 * (uint8_t)--a1[10] + 12];
                *(_WORD *)&a1[2 * v11 + 180] += 1000;
              }
              else
              {
                *((_WORD *)v14 + 90) = 0;
              }
            }
          }
        }
        ++v11;
      }
      while ( v11 < 10 );
      if ( v63 )
      {
        v62 = (uint8_t)a1[239] - *(_WORD *)(a1 + 231) - *(_WORD *)(a1 + 243);
        v56 = (uint8_t)a1[240] - *(_WORD *)(a1 + 233);
        memset(&v42, 0, 18);
        LOBYTE(v42) = 0;
        v19 = a1[2];
        HIBYTE(v42) = 4;
        BYTE2(v42) = v19;
        if ( v62 > 0 )
          LOBYTE(v43) = v62;
        if ( v56 > 0 )
          BYTE1(v43) = v56;
        if ( v62 > 0 || v56 > 0 )
          sub_EF629(v42, v43, v44, v45, v46, *a1);
      }
      for ( k = 0; k < word_199998; ++k )
        v35[k] = k;
      v21 = v35[0];
      v35[0] = v35[*a1];
      v35[*a1] = v21;
      sub_FE9F5((int)v36, word_199998 - 1);
      v52 = a1 + 12;
      v61 = 0;
      v49 = a1 + 361;
      while ( (int16_t)v61 < word_199998 )
      {
        v22 = v35[(int16_t)v61];
        v23 = (int)&a1[2 * v22];
        if ( *(int16_t *)(v23 + 200) > 0 )
        {
          *(_WORD *)(v23 + 180) += *(_WORD *)(v23 + 200);
          while ( 1 )
          {
            v24 = &a1[2 * v22];
            if ( *((int16_t *)v24 + 90) < 1000 )
              break;
            LOWORD(v23) = (uint8_t)a1[10];
            v57 = v23;
            v23 = sub_E0C1D(a1, v22);
            if ( (int16_t)v23 <= (int16_t)v57 )
            {
              *((_WORD *)v24 + 90) = 999;
            }
            else
            {
              v25 = -1;
              if ( a1[221] )
              {
                v54 = (uint8_t)a1[252];
                if ( (uint8_t)a1[253]
                   + v54
                   + (uint8_t)a1[255]
                   + (uint8_t)a1[254]
                   - 2 * *(int16_t *)(a1 + 231) > 0
                  || (uint8_t)a1[253] + v54 + (uint8_t)a1[255] + (uint8_t)a1[254] == 2 * *(int16_t *)(a1 + 231)
                  && !*(_BYTE *)(dword_197F98 + 3753 * v22 + 2225) )
                {
                  goto LABEL_88;
                }
                if ( (uint8_t)a1[253]
                   + v54
                   + (uint8_t)a1[255]
                   + (uint8_t)a1[254]
                   - 2 * *(int16_t *)(a1 + 231) == -1 )
                {
                  v26 = 3753 * v22 + dword_197F98;
                  if ( !*(_BYTE *)(v26 + 2225) && !*(_BYTE *)(v26 + 2224) )
                    goto LABEL_88;
                }
                if ( *(int16_t *)(v55 + 176) < 0 )
                  goto LABEL_88;
                if ( !*(_WORD *)(v55 + 176) && !*(_BYTE *)(v55 + 2225) )
                {
                  v27 = v49;
                  v28 = 0;
                  while ( 1 )
                  {
                    v54 = 361 * word_199996;
                    if ( (unsigned int)v27 >= v54 + dword_192B18 )
                      goto LABEL_87;
                    if ( *v27 == *a1 && !v27[6] )
                      break;
                    v27 += 361;
                  }
                  v28 = 1;
LABEL_87:
                  if ( v28 )
LABEL_88:
                    v25 = 0;
                }
              }
              if ( v25 == -1 )
              {
                v29 = (uint8_t)a1[240];
                if ( v29 > *(int16_t *)(a1 + 233)
                  || v29 == *(_WORD *)(a1 + 233)
                  && *(_BYTE *)(dword_197F98 + 3753 * v22 + 2224)
                  && !(((uint8_t)a1[259]
                      + (uint8_t)a1[257]
                      + (uint8_t)a1[256]
                      + (uint8_t)a1[258])
                     % 2) )
                {
                  v25 = 1;
                }
              }
              if ( v25 == -1 && sub_23DFE((int)&a1[-dword_192B18] / 361) )
                v25 = 2;
              if ( v25 == -1 )
              {
                memset(v47, 0, sizeof(v47));
                for ( m = 0; m < (int16_t)v57; ++m )
                {
                  v31 = *(_DWORD *)&v52[4 * m] << 23 >> 30;
                  ++v47[v31];
                }
                if ( v47[2] + v47[1] )
                {
                  v47[0] = 0;
                  LOBYTE(v25) = sub_FE96F((int)v47, 3);
                }
                else
                {
                  LOBYTE(v25) = 1;
                }
              }
              v54 = 4 * (int16_t)v57;
              memset(&v52[v54], 0, 4);
              v32 = v54;
              *(_WORD *)&a1[v54 + 12] &= 0xFE7Fu;
              *(_DWORD *)&a1[v32 + 12] |= (v25 & 3) << 7;
              a1[v32 + 13] |= 2u;
              a1[v32 + 12] &= 0xF0u;
              *(_DWORD *)&a1[v32 + 12] |= v22 & 0xF;
              v33 = *a1 & 7;
              a1[v32 + 12] &= 0x8Fu;
              *(_DWORD *)&a1[v32 + 12] |= 16 * v33;
              v23 = v22;
              ++a1[10];
              *(_WORD *)&a1[2 * v22 + 180] -= 1000;
            }
          }
        }
        ++v61;
      }
    }
  }
  JUMPOUT(0xE1F98);
}
// E3451: control flows out of bounds to E1F98
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;


//----- (000E3456) --------------------------------------------------------
void __fastcall sub_E3456(char *a1)
{
  int v2; // edx
  int v3; // eax
  int v4; // edx
  char *v5; // eax
  int v6; // edi
  int v7; // eax
  int16_t v8; // dx
  int i; // ebx
  char *v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // [esp+0h] [ebp-24h] BYREF
  int v14; // [esp+4h] [ebp-20h]
  int v15; // [esp+8h] [ebp-1Ch]
  int v16; // [esp+Ch] [ebp-18h]
  int16_t v17; // [esp+10h] [ebp-14h]
  char *v18; // [esp+14h] [ebp-10h]
  char *v19; // [esp+18h] [ebp-Ch]
  unsigned int v20; // [esp+1Ch] [ebp-8h]
  int v21; // [esp+20h] [ebp-4h]

  if ( !sub_2341E((int)&a1[-dword_192B18] / 361) && a1[303] == 3 )
  {
    v20 = (uint8_t)a1[302];
    v2 = *(char *)(dword_197F98 + 3753 * *a1 + 2207);
    v3 = (uint8_t)a1[10];
    v18 = a1 + 12;
    v4 = (uint8_t)byte_DD4F5[v2];
    v5 = &a1[4 * v3 + 12];
    while ( v5 > v18 )
    {
      v5 -= 4;
      if ( !*(_BYTE *)(3753 * (*(_DWORD *)v5 << 25 >> 29) + dword_197F98 + 2207) )
      {
        v6 = *a1 & 7;
        *v5 &= 0x8Fu;
        *(_DWORD *)v5 |= 16 * v6;
      }
    }
    if ( a1[311] )
      v4 = 120;
    v7 = 3753 * *a1 + dword_197F98;
    if ( *(_BYTE *)(v7 + 2227) )
    {
      v4 *= 2;
    }
    else if ( *(_BYTE *)(v7 + 2226) )
    {
      v4 /= 2;
    }
    v20 += v4;
    v19 = a1 + 12;
    while ( v20 >= 0xF0 )
    {
      v21 = -1;
      v8 = 0;
      for ( i = 0; (int16_t)i < (uint8_t)a1[10]; ++i )
      {
        v10 = &v19[4 * (int16_t)i];
        if ( (v10[1] & 4) != 0 && (*(_DWORD *)v10 & 0xFu) < 8 && sub_1247A0(++v8) == 1 )
          v21 = i;
      }
      if ( v8 )
      {
        if ( v8 == 1 )
        {
          a1[303] = 4;
          memset(&v13, 0, 18);
          LOBYTE(v13) = 0;
          BYTE2(v13) = a1[2];
          HIBYTE(v13) = 3;
          LOBYTE(v14) = *(_DWORD *)&a1[4 * (int16_t)v21 + 12] & 0xF;
          sub_EF629(v13, v14, v15, v16, v17, *a1);
        }
        v11 = (int16_t)v21;
        a1[4 * (int16_t)v21 + 13] &= ~4u;
        v12 = *a1 & 7;
        a1[4 * v11 + 12] &= 0x8Fu;
        *(_DWORD *)&a1[4 * v11 + 12] |= 16 * v12;
      }
      v20 -= 240;
    }
    a1[302] = v20;
  }
  JUMPOUT(0xE1F97);
}
// E3611: control flows out of bounds to E1F97
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000E3616) --------------------------------------------------------
char *__fastcall sub_E3616(char *result)
{
  char *v1; // edx

  v1 = result;
  if ( result[332] )
  {
    result = (char *)sub_ED5E7(result);
    if ( (int16_t)result <= *((int16_t *)v1 + 152) )
    {
      result = (char *)sub_ED59D(v1);
      if ( (int16_t)result < *((int16_t *)v1 + 152) )
        --*((_WORD *)v1 + 152);
    }
    else if ( ++v1[309] == 5 )
    {
      v1[309] = 0;
      ++*((_WORD *)v1 + 152);
    }
  }
  if ( v1[312] )
  {
    result = (char *)sub_ED674(v1);
    if ( (int16_t)result <= *((int16_t *)v1 + 153) )
    {
      result = (char *)sub_ED61D(v1);
      if ( (int16_t)result < *((int16_t *)v1 + 153) )
        --*((_WORD *)v1 + 153);
    }
    else if ( ++v1[308] == 5 )
    {
      v1[308] = 0;
      ++*((_WORD *)v1 + 153);
    }
  }
  return result;
}


//----- (000E36B7) --------------------------------------------------------
_BOOL1 __fastcall sub_E36B7(char *a1)
{
  int16_t v1; // cx
  int16_t v2; // ax

  v1 = (uint8_t)a1[10];
  sub_E0B4F((int16_t *)(17 * *((int16_t *)a1 + 1) + dword_1930D4), *a1);
  return v1 == v2;
}
// E36D8: variable 'v2' is possibly undefined
// 1930D4: using guessed type int dword_1930D4;


//----- (000E36DF) --------------------------------------------------------
void __usercall sub_E36DF(char *a1, int a2)
{
  int v2; // ecx
  char *v3; // eax
  uint16_t v4; // ax
  int16_t v5; // cx
  int16_t v6; // ax
  char *v7; // eax
  char *v8; // eax
  int v9; // eax
  unsigned int v10; // ebx
  int v11; // eax
  char *v12; // ecx
  char v13; // al
  char v14; // al
  _BYTE *v15; // edx
  uint8_t v16; // al
  char *v17; // eax
  int16_t v18; // ax
  int v19; // edx
  char *v20; // eax
  int16_t v21; // ax
  _WORD *v22; // eax
  int v23; // eax
  uint16_t v24; // ax
  int16_t v25; // ax
  int v26; // ebx
  char v27; // al
  char *v28; // edx
  char *v29; // ecx
  int v30; // eax
  char *v31; // eax
  int v32; // ebx
  char *v33; // eax
  char *v34; // ecx
  char *v35; // eax
  int v36; // eax
  uint16_t v37; // ax
  char *v38; // eax
  _BYTE v39[2]; // [esp-6h] [ebp-6Ah] BYREF
  int v40; // [esp-4h] [ebp-68h]
  char *v41; // [esp+0h] [ebp-64h]
  int v42[4]; // [esp+4h] [ebp-60h] BYREF
  int16_t v43; // [esp+14h] [ebp-50h]
  int v44; // [esp+18h] [ebp-4Ch] BYREF
  int v45; // [esp+1Ch] [ebp-48h]
  int v46; // [esp+20h] [ebp-44h]
  int v47; // [esp+24h] [ebp-40h]
  int16_t v48; // [esp+28h] [ebp-3Ch]
  int v49; // [esp+2Ch] [ebp-38h] BYREF
  int v50; // [esp+30h] [ebp-34h]
  int v51; // [esp+34h] [ebp-30h]
  int v52; // [esp+38h] [ebp-2Ch]
  int16_t v53; // [esp+3Ch] [ebp-28h]
  char *v54; // [esp+40h] [ebp-24h]
  char *v55; // [esp+44h] [ebp-20h]
  int v56; // [esp+48h] [ebp-1Ch]
  char *v57; // [esp+4Ch] [ebp-18h]
  int v58; // [esp+50h] [ebp-14h]
  char *v59; // [esp+54h] [ebp-10h]
  _WORD *v60; // [esp+58h] [ebp-Ch]
  char v61; // [esp+5Ch] [ebp-8h]
  char v62; // [esp+60h] [ebp-4h]

  v2 = 3753 * *a1 + dword_197F98;
  v62 = 0;
  if ( sub_2341E((int)&v41[-dword_192B18] / 361) )
    goto LABEL_102;
  if ( v41[297] && *(_WORD *)(v41 + 277) >= 0xFFFDu )
    sub_D2783(v41, a2);
  v58 = (int16_t)sub_E0DD6(v41, *(_WORD *)(v41 + 277));
  v3 = v41;
  *(_WORD *)(v41 + 291) = -1;
  v4 = *(_WORD *)(v3 + 277);
  if ( v4 >= 0xFFFDu )
  {
    if ( v4 <= 0xFFFDu )
    {
      v5 = (uint8_t)v41[10];
      sub_E0B4F((int16_t *)(dword_1930D4 + 17 * *((int16_t *)v41 + 1)), *v41);
      if ( v5 == v6 )
      {
        v7 = v41;
        *(_WORD *)(v41 + 291) = -3;
        *(_WORD *)(v7 + 277) = -1;
        sub_BAA3B((int)&v7[-dword_192B18] / 361);
      }
    }
LABEL_102:
    JUMPOUT(0xE1F97);
  }
  v56 = *((int16_t *)v41 + 150) + *(int16_t *)(v41 + 293);
  v8 = v41;
  *((_WORD *)v41 + 150) = 0;
  if ( (uint8_t)v8[240] < *(int16_t *)(v41 + 233) )
    v56 += *(int16_t *)(v41 + 233) - (uint8_t)v41[240];
  if ( v58 > v56 )
  {
LABEL_99:
    if ( v56 < 0x7FFF )
      *(_WORD *)(v41 + 293) = v56;
    else
      *(_WORD *)(v41 + 293) = 0x7FFF;
    goto LABEL_102;
  }
  memset(&v49, 0, 18);
  LOBYTE(v49) = 0;
  BYTE2(v49) = v41[2];
  HIBYTE(v49) = 1;
  LOWORD(v50) = *(_WORD *)(v41 + 277);
  if ( *(int16_t *)(v41 + 277) <= -100 )
  {
    v9 = dword_197F9C + 129 * (int16_t)-(int16_t)(*(_WORD *)(v41 + 277) + 100);
    if ( *(_BYTE *)(v9 + 100) == 4 )
    {
      LOBYTE(v51) = 1;
    }
    else if ( v41[348] )
    {
      *(_WORD *)(v9 + 114) = word_17D16E[4 * (uint8_t)++*(_BYTE *)(v9 + 113)];
    }
  }
  if ( *(int16_t *)(v41 + 279) == -1 )
    *(_WORD *)(v41 + 291) = *(_WORD *)(v41 + 277);
  if ( *(int16_t *)(v41 + 277) > 0 && *(int16_t *)(v41 + 277) < 49 )
  {
    v10 = *(int16_t *)(v41 + 277);
    a2 = (int16_t)v10;
    sub_13FD9((int)&v41[-dword_192B18] / 361, v10);
    *(_DWORD *)(v2 + 50) += *(int16_t *)((char *)&word_17EB49 + 19 * v10);
    if ( *(int16_t *)(v41 + 279) != -10 )
      goto LABEL_25;
    v11 = 361 * (int16_t)((int)&v41[-dword_192B18] / 361);
    v12 = (char *)(v11 + dword_192B18);
    if ( !*(_BYTE *)(v11 + dword_192B18 + 6) )
      sub_E1E84((char *)(v11 + dword_192B18), (int16_t)v10);
    sub_E2710(3753 * *v12 + dword_197F98);
    sub_E11BC(v41, *(_WORD *)(v41 + 277));
    if ( !v13 )
LABEL_25:
      *(_WORD *)(v41 + 277) = -1;
    if ( v10 >= 0x2C )
    {
      if ( v10 <= 0x2C )
      {
        sub_E11BC(v41, 44);
        if ( !v14 )
          sub_B206F((int)&v41[-dword_192B18] / 361, 44);
      }
      else if ( v10 == 48 )
      {
        sub_E116F(*(uint8_t *)(17 * *(int16_t *)(361 * ((int)&v41[-dword_192B18] / 361) + dword_192B18 + 2)
                                     + dword_1930D4
                                     + 2));
      }
    }
LABEL_95:
    v56 -= v58;
    sub_BAA3B((int)&v41[-dword_192B18] / 361);
    if ( *(int16_t *)(v41 + 277) == -1 && v41[297] )
    {
      sub_D2783(v41, a2);
      BYTE1(v51) = 1;
    }
    HIWORD(v50) = *(_WORD *)(v41 + 277);
    sub_EF629(v49, v50, v51, v52, v53, *v41);
    goto LABEL_99;
  }
  if ( *(int16_t *)(v41 + 277) > -100 )
  {
    v24 = *(_WORD *)(v41 + 277);
    if ( v24 < 0xFFF9u )
    {
      if ( v24 == 0xFFF1 )
      {
        *(_WORD *)(dword_197F98 + 3753 * *v41 + 54) += 5;
        *(_DWORD *)(v2 + 50) += 5;
      }
    }
    else if ( v24 <= 0xFFF9u )
    {
      if ( !(uint16_t)sub_10294B(*v41, *v41) )
      {
        v25 = (int)&v41[-dword_192B18] / 361;
        *(_DWORD *)(v2 + 50) += 100;
        sub_B206F(v25, -7);
      }
      ++*(_DWORD *)(v2 + 50);
    }
    else if ( v24 <= 0xFFFCu )
    {
      v26 = (int16_t)sub_E0C1D(v41, 8);
      v61 = 1;
      if ( v26 > sub_E0C6E((int)v41, 8) )
      {
        sub_E0C9B((int)v41, 8);
        if ( !v27 )
        {
          v28 = 0;
          v29 = 0;
          v59 = 0;
          v54 = 0;
          v55 = 0;
          v30 = 4 * (uint8_t)v41[10];
          v57 = v41 + 12;
          v31 = &v41[v30 + 12];
          while ( v31 > v57 )
          {
            v31 -= 4;
            v32 = *(_DWORD *)v31 & 0xF;
            if ( v32 == 9 )
            {
              v28 = v31;
            }
            else if ( v32 != 8 )
            {
              if ( (v31[1] & 4) != 0 )
              {
                v59 = v31;
              }
              else if ( v32 == *v41 )
              {
                v55 = v31;
              }
              else
              {
                v54 = v31;
              }
            }
          }
          if ( v28 )
          {
            v29 = v28;
          }
          else if ( v59 )
          {
            v29 = v59;
          }
          else if ( v54 )
          {
            v29 = v54;
          }
          else if ( v55 )
          {
            v29 = v55;
          }
          else
          {
            v61 = 0;
          }
          if ( v29 )
          {
            memset(&v44, 0, 18);
            LOBYTE(v44) = 0;
            HIBYTE(v44) = 11;
            BYTE2(v44) = v41[2];
            LOBYTE(v45) = *(_DWORD *)v29 & 0xF;
            a2 = (int)v39;
            sub_EF629(v44, v45, v46, v47, v48, *v41);
            v33 = v41;
            --v41[10];
            *(_DWORD *)v29 = *(_DWORD *)&v41[4 * (uint8_t)v33[10] + 12];
          }
          v62 = 1;
        }
      }
      else
      {
        v61 = 0;
      }
      if ( v61 )
      {
        v34 = &v41[4 * (uint8_t)v41[10] + 12];
        memset(v34, 0, 4);
        *(_WORD *)v34 &= 0xFDF0u;
        v35 = v41;
        *(_WORD *)v34 |= 0x208u;
        v36 = *v35 & 7;
        *v34 &= 0x8Fu;
        *(_DWORD *)v34 |= 16 * v36;
        v37 = *(_WORD *)(v41 + 277);
        if ( v37 < 0xFFFBu )
        {
          if ( v37 == 0xFFFA )
          {
            *(_WORD *)v34 &= 0xFE7Fu;
            v34[1] |= 1u;
          }
        }
        else if ( v37 <= 0xFFFBu )
        {
          *(_WORD *)v34 &= 0xFE7Fu;
          *v34 |= 0x80u;
        }
        else if ( v37 == 0xFFFC )
        {
          *(_WORD *)v34 &= 0xFE7Fu;
        }
        ++v41[10];
      }
      else
      {
        memset(v42, 0, 18);
        LOBYTE(v42[0]) = 0;
        HIBYTE(v42[0]) = 10;
        BYTE2(v42[0]) = v41[2];
        a2 = (int)v39;
        sub_EF629(v42[0], v42[1], v42[2], v42[3], v43, *v41);
        v56 += v58;
      }
    }
    if ( *(int16_t *)(v41 + 279) == -10 )
    {
      if ( v62 )
      {
        v38 = v41;
        *(_WORD *)(v41 + 277) = -1;
        *(_WORD *)(v38 + 279) = -1;
      }
    }
    else
    {
      *(_WORD *)(v41 + 277) = -1;
    }
    goto LABEL_95;
  }
  v15 = (_BYTE *)(129 * (int16_t)-(int16_t)(*(_WORD *)(v41 + 277) + 100) + dword_197F9C);
  v16 = v15[100];
  v60 = v15;
  if ( v16 >= 4u )
  {
    if ( v16 <= 4u )
    {
      v20 = v41;
      v15[100] = 0;
      v21 = sub_6B577(*v20, (int)v15);
      v60[47] = v21;
      goto LABEL_41;
    }
    if ( v16 == 6 )
    {
      v17 = v41;
      v15[100] = 0;
      if ( *(int16_t *)(v17 + 279) == -10 )
      {
        v18 = sub_AF7B4(*v41, 0, (int)&v41[-dword_192B18] / 361);
        if ( v18 != -1 )
        {
          v19 = 129 * v18;
          v40 = v19 + dword_197F9C;
          qmemcpy((void *)(v19 + dword_197F9C), v60, 0x63u);
          a2 = v40;
          *(_BYTE *)(v19 + dword_197F9C + 100) = 6;
          *(_WORD *)(v41 + 277) = -(int16_t)(v18 + 100);
          goto LABEL_42;
        }
      }
LABEL_41:
      *(_WORD *)(v41 + 277) = -1;
    }
  }
LABEL_42:
  v22 = v60;
  *((_BYTE *)v60 + 128) = 1;
  *(_BYTE *)(dword_19306C + 113 * *(int16_t *)((char *)v22 + 101) + 54) = 0;
  if ( *((_BYTE *)v60 + 17) == 1 || *((_BYTE *)v60 + 17) == 4 )
  {
    v23 = dword_19306C + 113 * *(int16_t *)((char *)v60 + 101);
    *(_BYTE *)(v23 + 53) |= 1 << *((_BYTE *)v60 + 99);
  }
  goto LABEL_95;
}
// E377A: control flows out of bounds to E1F97
// E37A9: variable 'v6' is possibly undefined
// E398E: variable 'v13' is possibly undefined
// E39C0: variable 'v14' is possibly undefined
// E3C16: variable 'v27' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17D16E: using guessed type int16_t word_17D16E[];
// 17EB49: using guessed type int16_t word_17EB49;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;


//----- (000E3E9A) --------------------------------------------------------
void __fastcall sub_E3E9A(int a1)
{
  int v2; // esi
  int v3; // edi
  int v4; // ecx
  char v5; // dl
  unsigned int v6; // eax
  int v7; // esi
  unsigned int v8; // ecx
  int v9; // [esp+0h] [ebp-8h]

  v2 = 49;
  v3 = 0;
  v4 = a1 + 49;
  while ( 1 )
  {
    --v4;
    --v2;
    if ( *(_BYTE *)(v4 + 310) )
    {
      if ( sub_1247A0(0xAu) == 1 )
        sub_145EA((a1 - dword_192B18) / 361, v2, v3);
      else
        ++v3;
    }
    if ( v2 <= 0 )
    {
      if ( !v3 )
      {
        v5 = 0;
        v6 = dword_197F98 + 3753 * word_199998;
        while ( v6 > dword_197F98 )
        {
          v7 = *(int16_t *)(v6 - 3689);
          v6 -= 3753;
          v8 = v6 + 4 * v7;
          while ( v7 > 0 )
          {
            v9 = *(_DWORD *)(v8 + 62) << 16 >> 24;
            v8 -= 4;
            --v7;
            if ( v9 == *(int16_t *)(a1 + 2) )
              v5 = 1;
          }
        }
        if ( !v5 )
          sub_DCDAC((char *)a1, 3);
      }
      JUMPOUT(0xE1F97);
    }
  }
}
// E3F69: control flows out of bounds to E1F97
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000E3F6E) --------------------------------------------------------
void __usercall sub_E3F6E(char *a1, int a2)
{
  if ( !sub_2341E((int)&a1[-dword_192B18] / 361) )
  {
    if ( a1[303] == 4 )
      a1[303] = 3;
    if ( a1[220] != -1 )
      ++a1[220];
    if ( a1[10] )
    {
      sub_E2DCA(a1);
      sub_E3456(a1);
      sub_E3616(a1);
      sub_E36DF(a1, a2);
    }
    else
    {
      sub_E3E9A((int)a1);
    }
  }
}
// 192B18: using guessed type int dword_192B18;


//----- (000E3FDC) --------------------------------------------------------
unsigned int __usercall sub_E3FDC(int a1)
{
  char *i; // edx
  unsigned int result; // eax

  for ( i = (char *)dword_192B18; ; i += 361 )
  {
    result = dword_192B18 + 361 * word_199996;
    if ( (unsigned int)i >= result )
      break;
    if ( *i != -1 && !i[6] )
      sub_E3F6E(i, a1);
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (000E401D) --------------------------------------------------------
int __fastcall sub_E401D(int a1, int a2, int a3)
{
  int v4; // edi
  int result; // eax
  int v6; // esi
  int v7; // [esp+4h] [ebp-8h]

  v7 = 0;
  v4 = 0;
  do
  {
    if ( !a3 || v7 )
    {
      *(_BYTE *)(a1 + a2 + 196) = 3;
      a2 = *(int16_t *)((char *)&word_17D90C + 23 * a2);
      *(_BYTE *)(a1 + a2 + 196) = 2;
    }
    result = 23 * a2 + 8;
    do
    {
      v6 = *(int16_t *)((char *)&word_17D90C + result);
      result -= 2;
      if ( v6 > 0 && *(_BYTE *)(a1 + v6 + 279) == 1 )
        ++v4;
    }
    while ( result != 23 * a2 );
    ++v7;
  }
  while ( !v4 && a2 < 75 );
  return result;
}
// 17D90C: using guessed type int16_t word_17D90C;


//----- (000E408F) --------------------------------------------------------
unsigned int __fastcall sub_E408F(int a1, int a2)
{
  unsigned int result; // eax
  int v3; // edi
  int v4; // edx
  int v5; // ebx
  int v6; // esi
  int v9; // [esp+8h] [ebp-8h]
  unsigned int v10; // [esp+Ch] [ebp-4h]

  result = 23 * a2;
  v9 = -1;
  v3 = 0;
  v4 = 23 * a2 + 8;
  v5 = 0;
  v10 = result;
  do
  {
    v6 = *(int16_t *)((char *)&word_17D90C + v4);
    v4 -= 2;
    if ( v6 > 0 )
    {
      result = v6 + a1;
      if ( *(_BYTE *)(v6 + a1 + 279) == 1 )
      {
        ++v3;
      }
      else if ( !*(_BYTE *)(result + 279) && (byte_199CAF || v6 != 52) && a2 != 6 )
      {
        if ( !byte_199CB4 || (result = 13 * v6, byte_17E084[13 * v6]) )
        {
          result = sub_1247A0(++v5);
          if ( result == 1 )
            v9 = v6;
        }
      }
    }
  }
  while ( v4 != v10 );
  if ( !v3 && v5 > 0 )
  {
    result = v9 + a1;
    *(_BYTE *)(v9 + a1 + 279) = 1;
  }
  return result;
}
// 17D90C: using guessed type int16_t word_17D90C;
// 199CAF: using guessed type char byte_199CAF;
// 199CB4: using guessed type char byte_199CB4;


//----- (000E412B) --------------------------------------------------------
char __fastcall sub_E412B(int a1, unsigned int a2)
{
  _BOOL1 v2; // bl
  _BOOL1 v3; // zf

  v2 = *(_BYTE *)(a2 + a1 + 279) != 3;
  if ( *(_BYTE *)(a2 + a1 + 279) == 3 )
    return v2;
  if ( a2 < 0x34 )
  {
    if ( a2 < 0x20 )
    {
      if ( a2 )
        goto LABEL_23;
    }
    else if ( a2 > 0x20 )
    {
      if ( a2 == 42 )
      {
        v3 = *(_BYTE *)(a1 + 2207) == 0;
        goto LABEL_17;
      }
      goto LABEL_23;
    }
    return 0;
  }
  if ( a2 <= 0x34 )
    return byte_199CAF;
  if ( a2 < 0x4D )
  {
    if ( a2 == 65 )
    {
      v3 = *(_BYTE *)(a1 + 2207) == 4;
      goto LABEL_17;
    }
LABEL_23:
    if ( byte_199CB4 && !byte_17E084[13 * a2] || (int)a2 >= 204 || *(int16_t *)((char *)&word_17E07F + 13 * a2) == -1 )
      return 0;
    return v2;
  }
  if ( a2 <= 0x4D )
  {
    v3 = *(_BYTE *)(a1 + 2207) == 6;
  }
  else
  {
    if ( a2 != 92 )
      goto LABEL_23;
    v3 = *(_BYTE *)(a1 + 2207) == 2;
  }
LABEL_17:
  if ( !v3 )
    return 0;
  return v2;
}
// 17E07F: using guessed type int16_t word_17E07F;
// 199CAF: using guessed type char byte_199CAF;
// 199CB4: using guessed type char byte_199CB4;


//----- (000E41DB) --------------------------------------------------------
char __fastcall sub_E41DB(unsigned int a1)
{
  if ( a1 < 0x1C )
    return a1 >= 0x16 && a1 <= 0x17;
  if ( a1 <= 0x1D )
    return 1;
  if ( a1 >= 0x37 )
    return a1 <= 0x37 || a1 == 57;
  return 0;
}


//----- (000E4204) --------------------------------------------------------
char __usercall sub_E4204(int a1, unsigned int a2, int a3)
{
  _BOOL1 v5; // zf
  _BYTE *i; // edx
  int j; // eax
  unsigned int v8; // edx
  int v9; // esi
  int v11; // [esp+0h] [ebp-8h]
  char v12; // [esp+4h] [ebp-4h]

  *(_BYTE *)(a1 + (int16_t)a2 + 279) = 3;
  *(_BYTE *)(a1 + 803) = 1;
  if ( a2 >= 0x5Cu )
  {
    if ( a2 <= 0x5Cu )
    {
      *(_BYTE *)(a1 + 2207) = 3;
      goto LABEL_29;
    }
    if ( a2 < 0xAAu )
    {
      v5 = a2 == 99;
LABEL_8:
      if ( !v5 )
        goto LABEL_28;
      goto LABEL_23;
    }
    if ( a2 <= 0xAAu )
    {
LABEL_23:
      for ( i = (_BYTE *)(113 * word_19999A + dword_19306C); (unsigned int)i > dword_19306C; sub_E5296(i) )
        i -= 113;
      goto LABEL_29;
    }
    if ( a2 >= 0xB0u )
    {
      if ( a2 > 0xB0u )
      {
        v5 = a2 == 180;
        goto LABEL_8;
      }
      goto LABEL_23;
    }
LABEL_28:
    sub_57112((a1 - dword_197F98) / 3753);
    sub_10038C();
    goto LABEL_29;
  }
  if ( a2 < 0x2Au )
  {
    if ( a2 != 24 )
      goto LABEL_28;
    if ( sub_E412B(a1, 0xEu) )
      sub_E4204(a1, 14, a2);
  }
  else
  {
    if ( a2 <= 0x2Au )
    {
      *(_BYTE *)(a1 + 2207) = 1;
      goto LABEL_29;
    }
    if ( a2 < 0x41u )
      goto LABEL_28;
    if ( a2 <= 0x41u )
    {
      *(_BYTE *)(a1 + 2207) = 5;
    }
    else
    {
      if ( a2 != 77 )
        goto LABEL_28;
      *(_BYTE *)(a1 + 2207) = 7;
    }
  }
LABEL_29:
  sub_E2D72((int16_t)((a1 - dword_197F98) / 3753), a3);
  LOWORD(j) = *(uint8_t *)(a1 + 802);
  if ( a2 == (_WORD)j && (v8 = *(uint8_t *)(a1 + 801), *(_BYTE *)(a1 + v8 + 196) == 2) )
  {
    v12 = 1;
    if ( *(_BYTE *)(a1 + 2229) || (LOBYTE(j) = sub_E41DB(v8), (_BYTE)j) )
    {
      for ( j = 0; j != 8; j += 2 )
      {
        v11 = *(int16_t *)((char *)&word_17D90E + 23 * *(uint8_t *)(a1 + 801) + j);
        if ( (int16_t)a2 != v11 && *(_BYTE *)(a1 + v11 + 279) == 1 )
        {
          v12 = 0;
          *(_BYTE *)(a1 + 802) = v11;
        }
      }
    }
    if ( v12 )
    {
      LOBYTE(j) = sub_E401D(a1, *(uint8_t *)(a1 + 801), 1);
      *(_BYTE *)(a1 + 801) = 0;
      *(_DWORD *)(a1 + 491) = 0;
    }
  }
  else
  {
    v9 = *(int16_t *)((char *)&word_17E07F + 13 * (int16_t)a2);
    if ( *(_BYTE *)(a1 + 2228) )
      LOBYTE(j) = sub_E408F(a1, *(int16_t *)((char *)&word_17E07F + 13 * (int16_t)a2));
    if ( *(_BYTE *)(a1 + v9 + 196) == 2 )
      LOBYTE(j) = sub_E401D(a1, v9, 1);
  }
  return j;
}
// 17D90E: using guessed type int16_t word_17D90E;
// 17E07F: using guessed type int16_t word_17E07F;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E4410) --------------------------------------------------------
void __usercall sub_E4410(int a1, unsigned int a2, int a3, int a4)
{
  _BOOL1 v5; // al
  char v6; // bl
  int v7; // esi
  int v8; // edi
  int v9; // eax

  if ( (int)a2 < 75 )
    sub_E401D(a1, a2, 0);
  else
    ++*(_BYTE *)(a1 + a2 + 465);
  if ( (int)a2 >= 75 )
    return;
  v5 = *(_BYTE *)(a1 + 2229) || a3;
  v6 = 0;
  if ( a2 < 0x1C )
  {
    if ( a2 < 0x16 )
      goto LABEL_21;
    if ( a2 <= 0x16 )
      goto LABEL_19;
    if ( a2 != 23 )
      goto LABEL_21;
LABEL_20:
    v5 = 1;
    goto LABEL_21;
  }
  if ( a2 <= 0x1D )
    goto LABEL_20;
  if ( a2 >= 0x37 && (a2 <= 0x37 || a2 == 57) )
  {
LABEL_19:
    v6 = 1;
    goto LABEL_20;
  }
LABEL_21:
  if ( v5 )
  {
    v7 = 23 * a2;
    v8 = 23 * a2 + 8;
    do
    {
      v9 = *(int16_t *)((char *)&word_17D90E + v7);
      if ( v9 > 0 && *(_BYTE *)(a1 + v9 + 279) == 1 )
        sub_E4204(a1, v9, v8);
      v7 += 2;
    }
    while ( v7 != v8 );
    if ( v6 )
      sub_54FBF((a1 - dword_197F98) / 3753);
  }
  else
  {
    sub_E4204(a1, *(uint8_t *)(a1 + 802), a4);
  }
}
// 17D90E: using guessed type int16_t word_17D90E;
// 197F98: using guessed type int dword_197F98;


//----- (000E44E0) --------------------------------------------------------
void __usercall sub_E44E0(int a1, int a2)
{
  signed int v3; // edx
  int v4; // eax

  v3 = *(uint8_t *)(a1 + 801);
  if ( *(_BYTE *)(a1 + 801) )
  {
    v4 = sub_E1EF4(a1);
    *(_BYTE *)(a1 + 48) = 0;
    *(_DWORD *)(a1 + 491) += *(int16_t *)(a1 + 172);
    if ( v3 > 0 && (int)sub_1247A0(0x64u) <= v4 )
    {
      *(_BYTE *)(a1 + 48) = 1;
      *(_DWORD *)(a1 + 491) = 0;
      sub_E4410(a1, v3, 0, a2);
    }
  }
}


//----- (000E4535) --------------------------------------------------------
void __fastcall sub_E4535(int a1)
{
  int16_t v2; // cx
  int16_t v3; // si
  int16_t v4; // ax
  int16_t v5; // dx
  int16_t v6; // ax
  int16_t v7; // [esp+4h] [ebp-4h]

  v2 = 75;
  *(_DWORD *)(a1 + 548) = 0;
  while ( 1 )
  {
    --v2;
    v3 = 1;
    v7 = *(_BYTE *)(a1 + v2 + 196) == 3;
    v4 = 4;
    do
    {
      v5 = *(int16_t *)((char *)&word_17D90E + 23 * v2 + 2 * --v4);
      if ( v5 > 0 )
      {
        ++v3;
        if ( *(_BYTE *)(v5 + a1 + 279) == 3 )
          ++v7;
      }
    }
    while ( v4 > 0 );
    *(_DWORD *)(a1 + 548) += v7 * *(int *)((char *)&dword_17D916 + 23 * v2) / v3;
    if ( v2 <= 0 )
    {
      v6 = 75;
      while ( 1 )
      {
        if ( *(_BYTE *)(v6 + a1 + 465) )
          *(_DWORD *)(a1 + 548) += 10000 * (*(uint8_t *)(v6 + a1 + 465) - 1)
                                 + *(int *)((char *)&dword_17D916 + 23 * v6);
        if ( ++v6 >= 83 )
          JUMPOUT(0xE1F97);
      }
    }
  }
}
// E45FA: control flows out of bounds to E1F97
// 17D90E: using guessed type int16_t word_17D90E;
// 17D916: using guessed type int dword_17D916;


//----- (000E45FF) --------------------------------------------------------
void __fastcall sub_E45FF(int a1)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  char *v5; // ebx
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  unsigned int v9; // esi
  int16_t v10; // ax
  int v11; // esi
  int v12; // eax
  int v13; // ebx
  unsigned int v14; // eax
  int v15; // [esp+0h] [ebp-14h]
  int v16; // [esp+4h] [ebp-10h]
  int v17; // [esp+8h] [ebp-Ch]

  v2 = (a1 - dword_197F98) / 3753;
  v3 = 361 * word_199996;
  v4 = dword_192B18;
  *(_BYTE *)(a1 + 36) = 1;
  v5 = (char *)(v3 + v4);
  while ( (unsigned int)v5 > dword_192B18 )
  {
    v5 -= 361;
    if ( *v5 == (_WORD)v2 && v5[6] )
      sub_DCDAC(v5, -1);
  }
  v6 = 3953;
  while ( 1 )
  {
    v6 -= 59;
    v7 = v6 + dword_1930DC;
    if ( *(char *)(v6 + dword_1930DC + 58) == (_WORD)v2 )
    {
      *(_BYTE *)(v7 + 57) = -2;
      v8 = *(int16_t *)(v7 + 53);
      *(_BYTE *)(v7 + 55) = 0;
      if ( v8 != -1 )
      {
        if ( *(_BYTE *)(v7 + 35) )
          *(_BYTE *)(dword_19306C + 113 * v8 + (int16_t)v2 + 66) = -1;
        else
          *(_WORD *)(dword_197F9C + 129 * v8 + 116) = -1;
        *(_WORD *)(v6 + dword_1930DC + 53) = -1;
      }
      *(_BYTE *)(v6 + dword_1930DC + 58) = -1;
    }
    if ( !v6 )
    {
      v9 = 129 * word_199994 + dword_197F9C;
      while ( v9 > dword_197F9C )
      {
        v10 = *(char *)(v9 - 30);
        v9 -= 129;
        if ( v10 == (_WORD)v2 )
          sub_A163A((int)(v9 - dword_197F9C) / 129, v2);
      }
      sub_8A4C4();
      v11 = word_199998;
      v15 = 2 * word_199998;
      v16 = 3753 * word_199998;
      while ( v11 > 0 )
      {
        v15 -= 2;
        v16 -= 3753;
        sub_10278D(v2, --v11, 0);
        if ( v11 != (int16_t)v2 )
          sub_1019F0(v11, v2);
        v17 = dword_197F98;
        v12 = v16 + dword_197F98;
        *(_BYTE *)((int16_t)v2 + v12 + 1575) = 0;
        *(_BYTE *)((int16_t)v2 + v12 + 1583) = 0;
        *(_BYTE *)((int16_t)v2 + v12 + 1591) = 0;
        v13 = v17 + 3753 * (int16_t)v2;
        *(_WORD *)(v12 + 2 * (int16_t)v2 + 1599) = 0;
        *(_BYTE *)(v11 + v13 + 1575) = 0;
        *(_BYTE *)(v11 + v13 + 1583) = 0;
        *(_BYTE *)(v11 + v13 + 1591) = 0;
        *(_WORD *)(v13 + v15 + 1599) = 0;
      }
      *(_WORD *)(a1 + 54) = 0;
      *(_WORD *)(a1 + 64) = 0;
      v14 = *(char *)(a1 + 516);
      *(_DWORD *)(a1 + 50) = 0;
      if ( v14 < 8 )
        *(_WORD *)(3753 * *(char *)(a1 + 516) + dword_197F98 + 2 * (int16_t)v2 + 498) = dword_192FD8;
      JUMPOUT(0xE1F97);
    }
  }
}
// E481A: control flows out of bounds to E1F97
// 192B18: using guessed type int dword_192B18;
// 192FD8: using guessed type int dword_192FD8;
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;


//----- (000E481F) --------------------------------------------------------
int __usercall sub_E481F(char *a1, int a2, int a3)
{
  int v5; // esi
  int v6; // eax
  char *v7; // eax
  int v8; // eax
  char *v9; // edx
  int v10; // eax
  int v11; // edx
  int result; // eax

  v5 = *a1;
  if ( a1[319] )
    a1[319] = 0;
  a1[297] = 0;
  v6 = (uint8_t)a1[10];
  *a1 = a2;
  v7 = &a1[4 * v6 + 12];
  while ( v7 > a1 + 12 )
  {
    v7 -= 4;
    if ( *(_DWORD *)v7 << 25 >> 29 == v5 )
    {
      *v7 &= 0x8Fu;
      *(_DWORD *)v7 |= 16 * (a2 & 7);
    }
  }
  sub_E5296((_BYTE *)(dword_19306C + 113 * *(uint8_t *)(17 * *((int16_t *)a1 + 1) + dword_1930D4 + 2)));
  if ( a1[355] )
    sub_10041C(-1);
  sub_E1CED(a1);
  sub_EC97C(a1);
  sub_B20A1((int)&a1[-dword_192B18] / 361);
  v8 = 361 * (int16_t)((int)&a1[-dword_192B18] / 361);
  v9 = (char *)(v8 + dword_192B18);
  if ( !*(_BYTE *)(v8 + dword_192B18 + 6) )
    sub_E1E84((char *)(v8 + dword_192B18), a3);
  sub_E2710(3753 * *v9 + dword_197F98);
  v10 = 17 * *((int16_t *)a1 + 1);
  v11 = dword_1930D4;
  a1[220] = 0;
  result = dword_19306C + 113 * *(uint8_t *)(v11 + v10 + 2);
  *(_BYTE *)(result + 51) |= 1 << a2;
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000E493A) --------------------------------------------------------
int __usercall sub_E493A( int a1, int a2, int a3, int a4)
{
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  char *v8; // eax
  int v9; // edx
  _BYTE *v10; // eax
  char v11; // bl
  int v12; // eax
  int v13; // eax
  int result; // eax

  v5 = 10;
  do
  {
    v6 = *(int16_t *)(v5 + dword_19306C + 113 * a1 + 72);
    v5 -= 2;
    if ( v6 != -1 )
    {
      v7 = *(int16_t *)(dword_1930D4 + 17 * v6);
      if ( v7 != -1 )
      {
        v8 = (char *)(dword_192B18 + 361 * v7);
        if ( *v8 == a2 )
          sub_E481F(v8, a3, a4);
      }
    }
  }
  while ( v5 );
  v9 = 113 * a1;
  v10 = (_BYTE *)(v9 + dword_19306C);
  v10[56] &= ~(1 << a2);
  v11 = 1 << a3;
  v10[56] |= v11;
  v10[51] |= v11;
  sub_E5296(v10);
  v12 = v9 + dword_19306C;
  *(_BYTE *)(v12 + 55) = -1;
  v13 = *(char *)(a2 + v12 + 66);
  if ( v13 != -1 )
  {
    sub_944A3(v13, a4);
    *(_BYTE *)(a2 + v9 + dword_19306C + 66) = -1;
  }
  result = a2;
  *(_BYTE *)(dword_19306C + 113 * a1 + a2 + 103) = -1;
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000E4A09) --------------------------------------------------------
char __fastcall sub_E4A09(int a1, int a2, int a3)
{
  int v4; // eax
  char result; // al
  int v6; // ecx
  int v7; // eax
  char v8; // dl
  unsigned int v9; // eax
  int v10; // ebx
  char v11; // [esp+0h] [ebp-4h]

  v11 = a2;
  v4 = *(int16_t *)(3753 * a2 + dword_197F98 + 41);
  if ( v4 != -1 && *(uint8_t *)(dword_1930D4 + 17 * v4 + 2) == a1 )
    return 0;
  v6 = 113 * a1;
  v7 = v6 + dword_19306C;
  if ( *(char *)(a3 + v6 + dword_19306C + 103) == a2 || *(char *)(a2 + v7 + 103) != -1 )
    return 0;
  result = sub_FF666(v7, a3);
  if ( result )
  {
    v8 = 0;
    v9 = dword_19306C + 113 * word_19999A;
    while ( v9 > dword_19306C )
    {
      v10 = (int)*(uint8_t *)(v9 - 57) >> v11;
      v9 -= 113;
      if ( (v10 & 1) != 0 && v9 != v6 + dword_19306C )
        v8 = 1;
    }
    return v8;
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E4AB3) --------------------------------------------------------
void __fastcall sub_E4AB3( int a1, int a2, int a3)
{
  int v5; // edx
  int v6; // eax
  int v7; // esi
  int v8; // edi
  int16_t i; // ax

  *(_BYTE *)(a2 + dword_19306C + 113 * a1 + 103) = a3;
  v5 = word_199998;
  while ( v5 > 0 )
  {
    v6 = --v5 + 113 * a1 + dword_19306C;
    if ( a2 == *(char *)(v6 + 103) )
      *(_BYTE *)(v6 + 103) = a3;
  }
  if ( *(char *)(a3 + 113 * a1 + dword_19306C + 103) != -1 )
  {
    v7 = word_199998;
    while ( v7 > 0 )
    {
      --v7;
      v8 = 113 * a1 + dword_19306C;
      if ( a3 == *(char *)(v8 + v7 + 103) )
        *(_BYTE *)(v8 + v7 + 103) = *(_BYTE *)(*(char *)(v8 + v7 + 103) + v8 + 103);
    }
  }
  for ( i = word_199998; i > 0; --i )
    ;
  JUMPOUT(0xE44DB);
}
// E4B56: control flows out of bounds to E44DB
// 19306C: using guessed type int dword_19306C;
// 199998: using guessed type int16_t word_199998;


//----- (000E4B5F) --------------------------------------------------------
void __fastcall sub_E4B5F( int a1, int a2)
{
  int v2; // esi
  int v3; // ecx
  unsigned int v4; // edx
  int16_t v5; // ax
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  char *v9; // ebx
  int16_t v10; // ax
  int v11; // edi
  int v12; // ebx
  int v13; // ebx
  int v16; // [esp+8h] [ebp-4h]

  v2 = dword_197F98 + 3753 * a1;
  v3 = 3753 * a2 + dword_197F98;
  v4 = 129 * word_199994 + dword_197F9C;
  while ( v4 > dword_197F9C )
  {
    v5 = *(char *)(v4 - 30);
    v4 -= 129;
    if ( v5 == a1 )
    {
      *(_BYTE *)(v4 + 99) = a2;
      v6 = *(int16_t *)(v4 + 116);
      if ( v6 != -1 )
      {
        sub_933F2(v6);
        *(_WORD *)(v4 + 116) = -1;
      }
    }
  }
  v7 = 83;
  sub_8A4C4();
  v8 = v2 + 83;
  while ( 1 )
  {
    --v8;
    --v7;
    if ( *(_BYTE *)(v8 + 279) == 3 && sub_E412B(v3, v7) )
      sub_E4204(v3, v7, v8);
    if ( v7 <= 0 )
    {
      v9 = (char *)(361 * word_199996 + dword_192B18);
      while ( (unsigned int)v9 > dword_192B18 )
      {
        v9 -= 361;
        if ( *v9 == a1 )
        {
          sub_E481F(v9, a2, v8);
          sub_E5296((_BYTE *)(dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)v9 + 1) + 2)));
        }
      }
      v16 = 0;
      v10 = sub_1026CF(a2, a2);
      v11 = word_199998;
      v12 = v10;
      while ( v11 > 0 )
        v16 += sub_1026CF(a1, --v11);
      v13 = v16 + v12;
      if ( v13 >= 63 )
        LOBYTE(v13) = 63;
      sub_10278D(a2, a2, v13);
      *(_WORD *)(v3 + 54) += *(_WORD *)(v2 + 54);
      *(_DWORD *)(v3 + 50) += *(_DWORD *)(v2 + 50);
      *(_BYTE *)(v2 + 3698) = -1;
      sub_E45FF(v2);
      JUMPOUT(0xDEB17);
    }
  }
}
// E4CCD: control flows out of bounds to DEB17
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;


//----- (000E4CD2) --------------------------------------------------------
_BOOL1 __fastcall sub_E4CD2(int a1, int a2)
{
  return *(char *)(3753 * a2 + dword_197F98 + 3698) != a1 && *(char *)(dword_197F98 + 3753 * a1 + 3698) == -1;
}
// 197F98: using guessed type int dword_197F98;


//----- (000E4D06) --------------------------------------------------------
void __fastcall sub_E4D06( int a1, int a2)
{
  int v2; // esi
  int v3; // ebx
  int v4; // esi
  int v5; // ebx
  int16_t i; // ax

  v2 = word_199998;
  *(_BYTE *)(dword_197F98 + 3753 * a1 + 3698) = a2;
  v3 = 3753 * v2;
  while ( v3 > 0 )
  {
    v3 -= 3753;
    --v2;
    if ( a1 == *(char *)(v3 + dword_197F98 + 3698) )
      *(_BYTE *)(v3 + dword_197F98 + 3698) = a2;
  }
  if ( *(char *)(dword_197F98 + 3753 * a2 + 3698) != -1 )
  {
    v4 = word_199998;
    v5 = 3753 * word_199998;
    while ( v5 > 0 )
    {
      v5 -= 3753;
      --v4;
      if ( a2 == *(char *)(dword_197F98 + v5 + 3698) )
        *(_BYTE *)(dword_197F98 + v5 + 3698) = *(_BYTE *)(3753 * *(char *)(dword_197F98 + v5 + 3698)
                                                        + dword_197F98
                                                        + 3698);
    }
  }
  for ( i = word_199998; i > 0; --i )
    ;
  JUMPOUT(0xDF513);
}
// E4DC0: control flows out of bounds to DF513
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000E4DC9) --------------------------------------------------------
void sub_E4DC9()
{
  int v0; // esi
  int v1; // edi
  int v2; // ecx
  int v3; // ebx
  int v4; // ecx
  int v5; // edi
  int v6; // edx

  v0 = word_19999A;
  v1 = 113 * word_19999A;
  while ( v0 > 0 )
  {
    v2 = word_199998;
    v1 -= 113;
    --v0;
    while ( v2 > 0 )
    {
      v3 = *(char *)(v2 + v1 + dword_19306C + 102);
      --v2;
      if ( v3 != -1 )
        sub_E493A(v0, v2, v3, v1);
    }
  }
  v4 = word_199998;
  v5 = 3753 * word_199998;
  while ( v4 > 0 )
  {
    v5 -= 3753;
    v6 = *(char *)(v5 + dword_197F98 + 3698);
    --v4;
    if ( v6 != -1 )
      sub_E4B5F(v4, v6);
  }
  JUMPOUT(0xE1F97);
}
// E4E4F: control flows out of bounds to E1F97
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E4E54) --------------------------------------------------------
int sub_E4E54()
{
  int v0; // esi
  int i; // ecx
  int v2; // esi
  int result; // eax

  v0 = word_19999A;
  for ( i = 113 * word_19999A; i > 0; memset(i + dword_19306C + 103, -1, word_199998) )
  {
    i -= 113;
    --v0;
  }
  v2 = word_199998;
  for ( result = 3753 * word_199998; result > 0; *(_BYTE *)(dword_197F98 + result + 3698) = -1 )
  {
    result -= 3753;
    --v2;
  }
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E4EB3) --------------------------------------------------------
char sub_E4EB3()
{
  char *v0; // eax
  unsigned int v1; // edx
  int v2; // edx
  int v3; // ecx
  int v4; // ebx
  _BYTE v6[8]; // [esp+0h] [ebp-8h] BYREF

  memset(v6, 0, sizeof(v6));
  v0 = (char *)(361 * word_199996 + dword_192B18);
  while ( (unsigned int)v0 > dword_192B18 )
  {
    v0 -= 361;
    v1 = *v0;
    if ( v1 < 8 && !v0[6] )
      v6[v1] = 1;
  }
  v2 = word_199998;
  v3 = 3753 * word_199998;
  while ( v2 > 0 )
  {
    v3 -= 3753;
    v4 = v3 + dword_197F98;
    --v2;
    if ( !*(_BYTE *)(v3 + dword_197F98 + 36) )
    {
      if ( !v6[v2] )
      {
        sub_E45FF(v3 + dword_197F98);
        LOBYTE(v0) = sub_233AB(v2);
      }
      *(_BYTE *)(v4 + 516) = -1;
    }
  }
  return (char)v0;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;


//----- (000E4F49) --------------------------------------------------------
void __usercall sub_E4F49(int16_t *a1)
{
  int v1; // ecx
  int16_t v2; // [esp-6h] [ebp-22h] BYREF
  int v3; // [esp+0h] [ebp-1Ch] BYREF
  int v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]
  int16_t v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h]

  v8 = word_199998;
  v9 = 3753 * word_199998;
  while ( v8 > 0 )
  {
    v9 -= 3753;
    v1 = v9 + dword_197F98;
    --v8;
    if ( !*(_BYTE *)(v9 + dword_197F98 + 36) )
    {
      sub_EE0B0(v9 + dword_197F98, (int)a1);
      *(_DWORD *)(v1 + 50) += *(int16_t *)(v1 + 178);
      sub_E2710(v1);
      sub_E44E0(v1, (int)a1);
      sub_E4535(v1);
      if ( *(int16_t *)(v1 + 178) < 0 && *(int *)(v1 + 50) < 50 )
      {
        memset(&v3, 0, 18);
        LOBYTE(v3) = 4;
        HIWORD(v3) = *(_WORD *)(v1 + 50);
        LOWORD(v4) = *(_WORD *)(v1 + 178);
        a1 = &v2;
        sub_EF629(v3, v4, v5, v6, v7, v8);
      }
      if ( *(int16_t *)(v1 + 176) < 0 || *(int16_t *)(v1 + 56) < 0 )
        byte_1AB124[v8] = 1;
    }
  }
  sub_100828();
  JUMPOUT(0xE1F97);
}
// E5025: control flows out of bounds to E1F97
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000E502A) --------------------------------------------------------
int sub_E502A()
{
  int v0; // edx
  unsigned int v1; // eax

  v0 = 0;
  v1 = dword_197F98 + 3753 * word_199998;
  while ( v1 > dword_197F98 )
  {
    v1 -= 3753;
    if ( !*(_BYTE *)(v1 + 36) )
      ++v0;
  }
  return v0;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000E505E) --------------------------------------------------------
int sub_E505E()
{
  int v0; // edx
  unsigned int v1; // eax

  v0 = 0;
  v1 = 3753 * word_199998 + dword_197F98;
  while ( v1 > dword_197F98 )
  {
    v1 -= 3753;
    if ( !*(_BYTE *)(v1 + 36) && *(_BYTE *)(v1 + 40) == 100 )
      ++v0;
  }
  return v0;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000E5097) --------------------------------------------------------
void sub_E5097()
{
  unsigned int v0; // esi
  unsigned int v1; // ecx
  unsigned int v2; // eax
  int v3; // edx
  int v4; // ebx
  int v5; // esi
  uint8_t v6; // cl
  unsigned int v7; // esi
  unsigned int v8; // edi
  int16_t v9; // ax
  int16_t v10; // [esp-8h] [ebp-24h]
  int v11; // [esp+0h] [ebp-1Ch]
  int v12; // [esp+8h] [ebp-14h]
  int v13; // [esp+14h] [ebp-8h]

  v0 = 113 * word_19999A + dword_19306C;
  v1 = v0 + 43;
  while ( v0 > dword_19306C )
  {
    v1 -= 113;
    *(_BYTE *)(v0 - 71) = 0;
    v0 -= 113;
    memset(v1, 0, 8);
  }
  v2 = dword_197F9C + 129 * word_199994;
  while ( v2 > dword_197F9C )
  {
    v2 -= 129;
    if ( !*(_BYTE *)(v2 + 100) && *(int16_t *)(v2 + 101) < 72 && !*(_BYTE *)(v2 + 17) )
    {
      v3 = dword_19306C + 113 * *(int16_t *)(v2 + 101);
      if ( *(char *)(v2 + 99) >= 8 )
      {
        *(_BYTE *)(v3 + 42) = *(_BYTE *)(v3 + 56);
      }
      else
      {
        v11 = *(char *)(v2 + 99);
        v4 = word_199998;
        v5 = word_199998 + v3;
        while ( v4 > 0 )
        {
          --v4;
          --v5;
          if ( v4 != v11 && (((int)*(uint8_t *)(v3 + 56) >> v4) & 1) != 0 )
          {
            v6 = *(_BYTE *)(3753 * v11 + dword_197F98 + v4 + 1575);
            if ( v6 >= 4u && v6 <= 6u )
            {
              *(_BYTE *)(v3 + 42) |= 1 << v4;
              *(_BYTE *)(v5 + 43) |= 1 << v11;
            }
          }
        }
      }
    }
  }
  v7 = 113 * word_19999A + dword_19306C;
  while ( v7 > dword_19306C )
  {
    v7 -= 113;
    if ( *(_BYTE *)(v7 + 42) )
    {
      v13 = word_199998;
      v8 = word_199998 + v7;
      while ( v13 > 0 )
      {
        --v13;
        --v8;
        if ( (((int)*(uint8_t *)(v7 + 42) >> v13) & 1) != 0 )
        {
          v12 = word_199998;
          while ( v12 > 0 )
          {
            if ( (((int)*(uint8_t *)(v8 + 43) >> --v12) & 1) != 0
              && (((int)*(uint8_t *)(v7 + 56) >> v12) & 1) == 0 )
            {
              v10 = (int)(v7 - dword_19306C) / 113;
              v9 = sub_1247A0(5u);
              sub_4E3B5((int16_t)-v9, v12, v13, 7, v10, 0);
            }
          }
        }
      }
    }
  }
  JUMPOUT(0xE1F97);
}
// E5270: control flows out of bounds to E1F97
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E5275) --------------------------------------------------------
_BOOL1 __fastcall sub_E5275(_BYTE *a1)
{
  return a1[350] || a1[318] || a1[351];
}


//----- (000E5296) --------------------------------------------------------
void __fastcall sub_E5296(_BYTE *a1)
{
  int16_t v1; // si
  int v2; // edx
  int v3; // edx
  char *v4; // edx
  char v5; // bl
  _BYTE *v6; // edx
  int16_t v7; // [esp+4h] [ebp-4h]

  a1[56] = 0;
  a1[57] = 0;
  a1[62] = 0;
  a1[61] = 0;
  a1[59] = 0;
  a1[60] = 0;
  a1[63] = 0;
  v1 = 5;
  a1[64] = 0;
  while ( 1 )
  {
    v2 = *(int16_t *)&a1[2 * --v1 + 74];
    if ( v2 != -1 )
    {
      v3 = *(int16_t *)(dword_1930D4 + 17 * v2);
      if ( v3 != -1 )
      {
        v4 = (char *)(dword_192B18 + 361 * v3);
        v7 = *v4;
        v5 = 1 << v7;
        v6 = v4 + 310;
        a1[56] |= 1 << v7;
        if ( v6[45] )
          a1[57] |= v5;
        if ( v6[40] || v6[8] || v6[41] )
        {
          if ( *(_BYTE *)(dword_197F98 + 3753 * v7 + 459) == 3 )
            a1[59] |= v5;
          if ( *(_BYTE *)(3753 * v7 + dword_197F98 + 455) == 3 )
            a1[60] |= v5;
        }
        if ( v6[3] )
          a1[63] |= v5;
        if ( v6[14] )
          a1[64] |= v5;
        if ( *(_BYTE *)(dword_197F98 + 3753 * v7 + 378) == 3 )
          a1[62] |= v5;
        if ( *(_BYTE *)(dword_197F98 + 3753 * v7 + 449) == 3 )
          a1[61] |= v5;
      }
    }
    if ( v1 <= 0 )
      JUMPOUT(0xE1F97);
  }
}
// E53C8: control flows out of bounds to E1F97
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000E53CD) --------------------------------------------------------
int __fastcall sub_E53CD(int a1)
{
  sub_E5296((_BYTE *)(113 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(a1 + 2) + 2) + dword_19306C));
  if ( *(_BYTE *)(a1 + 355) )
    sub_10041C(-1);
  return nullsub_12();
}
// E5407: using guessed type int nullsub_12(void);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000E5408) --------------------------------------------------------
void sub_E5408()
{
  _BYTE *i; // edx

  for ( i = (_BYTE *)(dword_19306C + 113 * word_19999A); (unsigned int)i > dword_19306C; sub_E5296(i) )
    i -= 113;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (000E5430) --------------------------------------------------------
uint8_t __fastcall sub_E5430(_BYTE *a1, _BYTE *a2, _WORD *a3)
{
  uint8_t v4; // al
  int16_t v5; // ax
  uint8_t v6; // al
  uint8_t result; // al

  memset(a3, 0, 14);
  *a3 = (char)a1[2208];
  if ( !a1[2230] )
    a3[1] += *((uint8_t *)&word_DD4BA + (uint8_t)a2[8]);
  v4 = a2[6];
  if ( !v4 )
  {
    if ( a1[2217] )
      goto LABEL_13;
LABEL_8:
    a3[3] = -25;
    goto LABEL_13;
  }
  if ( v4 <= 1u )
  {
    if ( !a1[2217] )
      goto LABEL_13;
    goto LABEL_8;
  }
  if ( v4 == 2 && !a1[2218] )
    a3[3] = -50;
LABEL_13:
  v5 = (uint8_t)a2[11];
  a3[4] = 2 * v5;
  if ( !(2 * v5) && a1[308] == 3 )
    a3[4] = 2;
  if ( (int16_t)a3[4] > 0 )
  {
    a3[4] += (char)a1[2209];
    if ( !a1[2219] )
      goto LABEL_26;
    v6 = a2[8];
    if ( v6 < 5u )
    {
      if ( v6 != 4 )
        goto LABEL_26;
    }
    else
    {
      if ( v6 <= 5u )
        goto LABEL_25;
      if ( v6 > 6u )
      {
        if ( v6 != 8 )
        {
LABEL_26:
          if ( (int16_t)a3[4] <= 0 )
            a3[4] = 1;
          goto LABEL_28;
        }
LABEL_25:
        a3[4] += 2 * ((uint8_t)byte_17D825 - (uint8_t)byte_17D81C[(uint8_t)a2[8]]);
        goto LABEL_26;
      }
    }
    a3[4] += 2 * ((uint8_t)byte_17D824 - (uint8_t)byte_17D81C[(uint8_t)a2[8]]);
    goto LABEL_26;
  }
LABEL_28:
  a3[5] = (uint8_t)byte_DD4B5[(uint8_t)a2[10]];
  if ( a1[387] == 3 )
    ++a3[5];
  a3[5] += (char)a1[2210];
  if ( (int16_t)a3[5] <= 0 )
    a3[5] = 1;
  a3[6] = 3;
  a3[6] += (char)a1[2211];
  if ( a1[363] == 3 )
    ++a3[6];
  result = a2[15];
  if ( result >= 0xAu )
  {
    if ( result <= 0xAu )
    {
      a3[6] += 2;
    }
    else if ( result == 11 )
    {
      a3[6] += 5;
    }
  }
  return result;
}
// DD4BA: using guessed type int16_t;
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17D824: using guessed type char byte_17D824;
// 17D825: using guessed type char byte_17D825;


//----- (000E55BE) --------------------------------------------------------
void __usercall sub_E55BE(char *a1, int16_t *a2)
{
  char *v3; // edx
  int v4; // esi
  int v5; // edi
  unsigned int v6; // esi
  char *i; // eax
  int v8; // eax
  char *v9; // edx
  int16_t v10; // ax
  _WORD *j; // ecx
  _WORD *v12; // ecx
  int v13; // ecx
  int v14; // eax
  uint8_t v15; // bl
  int v16; // ecx
  int v17; // eax
  int v18; // edx
  int v19; // edx
  int v20; // esi

  v3 = a1 + 12;
  v4 = (uint8_t)a1[10];
  sub_FE8BE((int)a1, (int)(a1 + 12), (int)a1, a2);
  v5 = (int)v3;
  v6 = (unsigned int)&v3[4 * v4];
  for ( i = &v3[4 * (uint8_t)a1[10]]; v3 < i; i[1] |= 1u )
  {
    i -= 4;
    *(_WORD *)i &= 0xFE7Fu;
  }
  v8 = 113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 2) + dword_19306C;
  *(_BYTE *)(v8 + 53) |= 1 << *a1;
  sub_E1D59(a1);
  v9 = a1;
  v10 = *a1;
  for ( j = (_WORD *)v5; ; j += 2 )
  {
    sub_DF8F0(v10, v9, v5);
    if ( (unsigned int)j >= v6 || (uint8_t)a1[240] <= *(int16_t *)(a1 + 233) )
      break;
    *j &= 0xFE7Fu;
    v9 = a1;
    *(_BYTE *)j |= 0x80u;
    sub_E1D59(a1);
    v10 = *a1;
  }
  if ( a1[221] )
  {
    while ( (unsigned int)j < v6 && (uint8_t)a1[239] > *(int16_t *)(a1 + 231) )
    {
      *j &= 0xFE7Fu;
      sub_E1D59(a1);
      j += 2;
      sub_DF8F0(*a1, a1, v5);
    }
  }
  while ( (unsigned int)j < v6 && *(_WORD *)(a1 + 233) < *(_WORD *)(a1 + 235) )
  {
    *j &= 0xFE7Fu;
    *(_BYTE *)j |= 0x80u;
    sub_E1D59(a1);
    j += 2;
    sub_DF8F0(*a1, a1, v5);
  }
  if ( *(_WORD *)(a1 + 235) <= *(_WORD *)(a1 + 233) )
  {
    v12 = j - 2;
    *v12 &= 0xFE7Fu;
    *((_BYTE *)v12 + 1) |= 1u;
    sub_E1D59(a1);
    sub_DF8F0(*a1, a1, v5);
  }
  v13 = *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 2);
  v14 = 113 * v13 + dword_19306C;
  v15 = *(_BYTE *)(v14 + 40);
  if ( v15 < 6u )
  {
    if ( v15 >= 2u && v15 <= 3u )
      *(_BYTE *)(v14 + 40) = 0;
  }
  else if ( v15 <= 7u )
  {
    v16 = 113 * v13;
    *(_BYTE *)(v14 + 40) = 0;
    v17 = 10;
    do
    {
      v18 = *(int16_t *)(v16 + dword_19306C + v17 + 72);
      v17 -= 2;
      if ( v18 != -1 )
        *(_BYTE *)(dword_1930D4 + 17 * v18 + 15) = 0;
    }
    while ( v17 );
  }
  else if ( v15 < 9u )
  {
    v19 = 67;
    v20 = 3953;
    do
    {
      v20 -= 59;
      --v19;
      if ( *(_BYTE *)(v20 + dword_1930DC + 57) == 5 && *(int16_t *)(v20 + dword_1930DC + 53) == v13 )
        sub_933F2(v19);
    }
    while ( v19 > 0 );
    *(_BYTE *)(dword_19306C + 113 * v13 + 40) = 0;
  }
  else if ( v15 == 10 )
  {
    *(_BYTE *)(v14 + 112) = 1;
  }
  JUMPOUT(0xE1F98);
}
// E572E: control flows out of bounds to E1F98
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;


//----- (000E57D0) --------------------------------------------------------
void __fastcall sub_E57D0(int a1)
{
  int v2; // eax
  int i; // ebx

  v2 = 0;
  for ( i = 0; *(char *)(dword_192B18 + i) != a1; i += 361 )
    ++v2;
  JUMPOUT(0xE4F45);
}
// E57E5: control flows out of bounds to E4F45
// 192B18: using guessed type int dword_192B18;


//----- (000E57F4) --------------------------------------------------------
char __fastcall sub_E57F4(int a1)
{
  unsigned int v2; // eax

  v2 = dword_197F9C + 129 * word_199994;
  do
  {
    if ( v2 <= dword_197F9C )
      return 0;
    v2 -= 129;
  }
  while ( *(char *)(v2 + 99) < 8 || *(int16_t *)(v2 + 101) != a1 );
  return 1;
}
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000E5832) --------------------------------------------------------
void __usercall sub_E5832(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // eax
  char *i; // ebx
  int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // esi
  int j; // eax
  int v10; // ebx
  int64_t v11; // rax
  unsigned int v12; // ebx
  uint8_t v13; // al
  uint8_t v14; // al
  int v15; // ebx
  int16_t v16; // cx
  int v17; // ebx
  int v18; // edx
  int v19; // ecx
  int16_t v20; // [esp+4h] [ebp-18h]
  int v21; // [esp+8h] [ebp-14h]
  int v22; // [esp+Ch] [ebp-10h]
  int v23; // [esp+10h] [ebp-Ch]
  int v24; // [esp+14h] [ebp-8h]

  LOWORD(v4) = sub_EB192(a1);
  sub_FE8BE(v4, a2, a3, a4);
  v22 = 30000;
  for ( i = (char *)(dword_192B18 + 361 * word_199996); (unsigned int)i > dword_192B18; sub_E55BE(i, a4) )
    i -= 361;
  LOWORD(v6) = sub_10038C();
  sub_E2B31(v6, (int)a4);
  v7 = dword_197F98 + 3753 * word_199998;
  while ( v7 > dword_197F98 )
  {
    v7 -= 3753;
    *(_BYTE *)(113 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v7 + 41) + 2) + dword_19306C + 55) = (int)(v7 - dword_197F98) / 3753;
    if ( *(int16_t *)(v7 + 58) < v22 )
      v22 = *(int16_t *)(v7 + 58);
  }
  if ( byte_199CB5 == 2 )
  {
    v8 = 3753 * word_199998 + dword_197F98;
    j = (v22 - 2) / 2;
    v24 = j;
    while ( v8 > dword_197F98 )
    {
      v8 -= 3753;
      v23 = (int)(v8 - dword_197F98) / 3753;
      sub_FE8BE(v23, (int)(v8 - dword_197F98) % 3753, 3753, a4);
      v10 = dword_19306C;
      *(_BYTE *)(dword_19306C + 113 * *(uint8_t *)(17 * *(int16_t *)(v8 + 41) + dword_1930D4 + 2) + 55) = v23;
      v11 = 400 * (*(char *)(v8 + 2212) + 2);
      *(_DWORD *)(v8 + 50) = (int)(v11 - (__CFSHL__(HIDWORD(v11), 2) + 4 * HIDWORD(v11))) >> 2;
      v12 = 113 * word_19999A + v10;
      while ( v12 > dword_19306C )
      {
        v13 = *(_BYTE *)(v12 - 73);
        v12 -= 113;
        if ( v13 < 7u || v13 > 8u )
        {
          if ( sub_FF666(v12, v23) )
          {
            v14 = *(_BYTE *)(v12 + 40);
            *(_BYTE *)(v12 + 51) |= 1 << v23;
            if ( v14 >= 2u && v14 <= 3u && !sub_E57F4((int)(v12 - dword_19306C) / 113) )
              *(_BYTE *)(v12 + 40) = 0;
          }
        }
      }
      v15 = 10;
      if ( *(int16_t *)(v8 + 56) < 0 )
        v15 = 10 - *(int16_t *)(v8 + 56);
      if ( *(int16_t *)(v8 + 176) < 0 )
        v15 -= *(int16_t *)(v8 + 176);
      *(_WORD *)(v8 + 54) = 5 * ((v15 + 4) / 5);
      v16 = 0;
      v17 = dword_192B18;
      v21 = (int)(v8 - dword_197F98) / 3753;
      for ( j = 0; ; j += 361 )
      {
        v18 = *(char *)(dword_192B18 + j);
        if ( v18 == (int)(v8 - dword_197F98) / 3753 )
          break;
        ++v16;
      }
      v20 = v16;
      v19 = (v22 - 2) / 2;
      a4 = (int16_t *)v22;
      if ( v24 >= 0 )
      {
        if ( v24 >= 4 )
        {
          if ( *(_BYTE *)(v8 + 465) == 3 )
            v19 = 4;
          else
            v19 = 3;
        }
      }
      else
      {
        v19 = 0;
      }
      do
      {
        sub_FE8BE(j, v18, v17, a4);
        if ( a4 )
        {
          if ( (int)a4 - 1 < v19 )
            v19 = (int)a4 - 1;
          v17 = v20;
          *(_BYTE *)(dword_197F9C + 129 * word_199994 + 99) = (int)(v8 - dword_197F98) / 3753;
          v18 = (int16_t)v19;
          sub_57112(v21);
          sub_AF7B4((int16_t)v21, v19, v20);
          j = v19 + 1;
          a4 = (int16_t *)((char *)a4 - v19 - 1);
        }
      }
      while ( a4 );
    }
    sub_E2B31(j, (int)a4);
  }
  JUMPOUT(0xE1F97);
}
// E5AE2: control flows out of bounds to E1F97
// E5840: variable 'v4' is possibly undefined
// E587C: variable 'v6' is possibly undefined
// E5A6D: variable 'j' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 199CB5: using guessed type char byte_199CB5;


//----- (000E5AE7) --------------------------------------------------------
int __fastcall sub_E5AE7(_BYTE *a1)
{
  if ( a1[333] )
    return 3;
  if ( a1[334] )
    return 2;
  return a1[338] != 0;
}


//----- (000E5B17) --------------------------------------------------------
int __fastcall sub_E5B17( int a1)
{
  int v2; // ecx
  char *v3; // ebx

  v2 = 0;
  v3 = (char *)(361 * word_199996 + dword_192B18);
  while ( (unsigned int)v3 > dword_192B18 )
  {
    v3 -= 361;
    if ( *v3 == a1 && !v3[6] )
      v2 += (int16_t)sub_E0C1D(v3, a1);
  }
  return v2;
}
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


