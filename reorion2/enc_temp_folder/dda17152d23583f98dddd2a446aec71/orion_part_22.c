#include "orion_common.h"

/* Adresni rozsah: 0x14818E - 0x1555FC  (200 funkci) */

//----- (0014818E) --------------------------------------------------------
int64_t __fastcall sub_14818E(int64_t a1, int a2)
{
  unsigned int v3; // ebx
  _DWORD *v4; // edi
  int *v5; // esi
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  __SET_PAIR__(v3, (unsigned int)v5, a1);
  v4 = (_DWORD *)a1;
  v6 = 0;
  do
  {
    v7 = *v5++;
    LOBYTE(v6) = v7;
    LOBYTE(v7) = *(_BYTE *)(v3 + v6);
    v8 = __ROR4__(v7, 8);
    LOBYTE(v6) = v8;
    LOBYTE(v8) = *(_BYTE *)(v3 + v6);
    v9 = __ROR4__(v8, 8);
    LOBYTE(v6) = v9;
    LOBYTE(v9) = *(_BYTE *)(v3 + v6);
    v10 = __ROR4__(v9, 8);
    LOBYTE(v6) = v10;
    LOBYTE(v10) = *(_BYTE *)(v3 + v6);
    *v4++ = __ROR4__(v10, 8);
    --a2;
  }
  while ( a2 );
  return a1;
}
// 14818E: could not find valid save-restore pair for ebx


//----- (001481C2) --------------------------------------------------------
int64_t __fastcall sub_1481C2(int64_t a1)
{
  unsigned int v1; // ebx
  _DWORD *v2; // edi
  int *v3; // esi
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax

  __SET_PAIR__(v1, (unsigned int)v3, a1);
  v2 = (_DWORD *)a1;
  v4 = 0;
  dword_189020 = 240;
  do
  {
    v5 = 160;
    do
    {
      v6 = *v3++;
      LOBYTE(v4) = v6;
      LOBYTE(v6) = *(_BYTE *)(v1 + v4);
      v7 = __ROR4__(v6, 8);
      LOBYTE(v4) = v7;
      LOBYTE(v7) = *(_BYTE *)(v1 + v4);
      v8 = __ROR4__(v7, 8);
      LOBYTE(v4) = v8;
      LOBYTE(v8) = *(_BYTE *)(v1 + v4);
      v9 = __ROR4__(v8, 8);
      LOBYTE(v4) = v9;
      LOBYTE(v9) = *(_BYTE *)(v1 + v4);
      *v2++ = __ROR4__(v9, 8);
      --v5;
    }
    while ( v5 );
    v3 += 160;
    v2 += 160;
    --dword_189020;
  }
  while ( dword_189020 );
  return a1;
}
// 189020: using guessed type int dword_189020;


//----- (0014852C) --------------------------------------------------------
// Wave 20: RLE sprite blitter. Original register signature RECOVERED from the
// running game (DOSBox DUMPREGS at entry + machine-code disassembly of the
// function and all 4 call sites, see PROGRESS.md wave 20):
//   eax = x, edx = y, ebx = pointer to RLE data; returns eax unchanged.
// IDA fused eax:edx into a fake int64 "a1" and lost the argument setup at
// every call site (callers passed leftover registers -> garbage pointer
// crash). On x64 the fused form was broken even with correct values, because
// "(char *)(a1 + ...)" kept y<<32 inside the 64-bit pointer (the original
// 32-bit code naturally truncated into edi).
// Formula: dst = framebuffer + x + 640*(y + startRow); (y<<7)+(y<<9) = y*640.
void sub_14852C(int x, int y, int a2)
{
  char *v2; // edi
  int v3; // esi
  int v4; // edx
  char *v5; // eax
  uint16_t v6; // cx
  _WORD *v7; // esi
  char *v8; // edi
  unsigned int v9; // ebx
  int v10; // ecx
  char *v11; // edi
  char *v12; // esi
  int rc; // run byte counter (was scratch reuse of the a2 slot)

  v2 = (char *)(intptr_t)(x
              + ((y + *(uint16_t *)(a2 + 2)) << 7)
              + ((y + *(uint16_t *)(a2 + 2)) << 9)
              + dword_1BB904);
  v3 = a2 + 4;
  v4 = *(uint16_t *)(dword_1BC2A8 + 2) - *(uint16_t *)(a2 + 2);
  v5 = v2;
  rc = 0;
  while ( v4 > 0 )
  {
    v6 = *(_WORD *)v3;
    v7 = (_WORD *)(v3 + 2);
    LOWORD(rc) = *v7;
    v3 = (int)(intptr_t)(v7 + 1);
    if ( v6 )
    {
      v8 = &v2[rc];
      v9 = v6 & 3;
      v10 = v6 >> 2;
      qmemcpy(v8, (void *)(intptr_t)v3, 4 * v10);
      v12 = (char *)(intptr_t)(v3 + 4 * v10);
      v11 = &v8[4 * v10];
      qmemcpy(v11, v12, v9);
      v3 = (int)(intptr_t)&v12[v9];
      v2 = &v11[v9];
      rc = v3 & 1;
      if ( (v3 & 1) != 0 )
        ++v3;
    }
    else
    {
      v4 -= rc;
      v5 += 512 * rc + 128 * rc;
      v2 = v5;
      rc = 0;
    }
  }
}
// 14852C: could not find valid save-restore pair for ebx
// 1BB904: using guessed type int dword_1BB904;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (001485B3) --------------------------------------------------------
int64_t __fastcall sub_1485B3(int64_t a1, char *a2)
{
  int v3; // edi
  int v4; // ecx
  int v5; // edx
  _BYTE *v6; // edi
  int i; // ebx
  char v8; // al

  v3 = a1 + (HIDWORD(a1) << 7) + (HIDWORD(a1) << 9) + dword_1BB904;
  v4 = *(uint16_t *)dword_1BC2A8;
  v5 = *(uint16_t *)(dword_1BC2A8 + 2);
  v6 = (_BYTE *)(v4 + v3 - 640);
  while ( v5 )
  {
    --v5;
    v6 = &v6[-v4 + 639];
    for ( i = v4; ; --i )
    {
      ++v6;
      if ( !i )
        break;
      v8 = *a2++;
      if ( v8 )
        *v6 = v8;
    }
  }
  return a1;
}
// 1485B3: could not find valid save-restore pair for ebx
// 1BB904: using guessed type int dword_1BB904;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (00148605) --------------------------------------------------------
char *__fastcall sub_148605(char *a1, int a2, int a3)
{
  char *v3; // esi
  _BYTE *v4; // edi
  char v5; // al

  v3 = a1;
  v4 = (_BYTE *)(a2 - 1);
  while ( 1 )
  {
    ++v4;
    if ( !a3 )
      break;
    --a3;
    v5 = *v3++;
    if ( v5 )
      *v4 = v5;
  }
  return a1;
}


//----- (0014861D) --------------------------------------------------------
int __fastcall sub_14861D( int a1, int a2, char *a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-2Ch]
  _BYTE v5[6]; // [esp+4h] [ebp-28h]
  int v6; // [esp+Ah] [ebp-22h]
  int i; // [esp+10h] [ebp-1Ch]
  int v8; // [esp+14h] [ebp-18h]
  char *v9; // [esp+18h] [ebp-14h]

  v9 = a3;
  v8 = a1 + 640 * a2 + dword_1BB904;
  if ( a1 + *(int16_t *)dword_1BC2A8 - 1 <= *(int *)((char *)&dword_1BBA4A + 2) >> 16 )
    *(_DWORD *)v5 = a1 + *(int16_t *)dword_1BC2A8 - 1;
  else
    *(_DWORD *)v5 = *(int *)((char *)&dword_1BBA4A + 2) >> 16;
  if ( a1 >= SHIWORD(dword_1BBA4A) )
    HIWORD(v6) = a1;
  else
    HIWORD(v6) = HIWORD(dword_1BBA4A);
  if ( a2 + (*(int *)dword_1BC2A8 >> 16) - 1 <= *(int *)((char *)&dword_1BBA4E + 2) >> 16 )
    v4 = a2 + (*(int *)dword_1BC2A8 >> 16) - 1;
  else
    v4 = *(int *)((char *)&dword_1BBA4E + 2) >> 16;
  if ( a2 >= SHIWORD(dword_1BBA4E) )
    *(_WORD *)&v5[4] = a2;
  else
    *(_WORD *)&v5[4] = HIWORD(dword_1BBA4E);
  if ( a1 < SHIWORD(dword_1BBA4A) )
  {
    v9 = &a3[(dword_1BBA4A >> 16) - a1];
    v8 += (dword_1BBA4A >> 16) - a1;
  }
  if ( a2 < SHIWORD(dword_1BBA4E) )
  {
    v9 += ((dword_1BBA4E >> 16) - a2) * *(int16_t *)dword_1BC2A8;
    v8 += 640 * ((dword_1BBA4E >> 16) - a2);
  }
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= v4 - (*(int *)&v5[2] >> 16) + 1 )
      break;
    sub_148605(v9, v8, *(_DWORD *)v5 - (v6 >> 16) + 1);
    v9 += *(int16_t *)dword_1BC2A8;
    v8 += 640;
  }
  return result;
}
// 14861D: could not find valid save-restore pair for ebx
// 1486B2: variable 'v6' is possibly undefined
// 1BB904: using guessed type int dword_1BB904;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (001487E0) --------------------------------------------------------
int __fastcall sub_1487E0(int a1, int a2, _BYTE *a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-38h]
  int v5; // [esp+4h] [ebp-34h]
  int v6; // [esp+8h] [ebp-30h]
  int v7; // [esp+Ch] [ebp-2Ch]
  _BYTE *v8; // [esp+18h] [ebp-20h]
  int i; // [esp+1Ch] [ebp-1Ch]
  int j; // [esp+20h] [ebp-18h]
  _BYTE *v11; // [esp+24h] [ebp-14h]
  _BYTE *v12; // [esp+28h] [ebp-10h]
  int v13; // [esp+2Ch] [ebp-Ch]

  v8 = a3;
  v13 = 640 * a2 + dword_1BB904 + a1;
  if ( *(int16_t *)dword_1BC2A8 + a1 <= *(int *)((char *)&dword_1BBA4A + 2) >> 16 )
    v4 = *(int16_t *)dword_1BC2A8 + a1;
  else
    v4 = *(int *)((char *)&dword_1BBA4A + 2) >> 16;
  if ( dword_1BBA4A >> 16 <= a1 )
    v5 = a1;
  else
    v5 = dword_1BBA4A >> 16;
  if ( (*(int *)dword_1BC2A8 >> 16) + a2 <= *(int *)((char *)&dword_1BBA4E + 2) >> 16 )
    v6 = (*(int *)dword_1BC2A8 >> 16) + a2;
  else
    v6 = *(int *)((char *)&dword_1BBA4E + 2) >> 16;
  if ( dword_1BBA4E >> 16 <= a2 )
    v7 = a2;
  else
    v7 = dword_1BBA4E >> 16;
  if ( dword_1BBA4A >> 16 > a1 )
  {
    v8 = &a3[(dword_1BBA4A >> 16) - a1];
    v13 = (dword_1BBA4A >> 16) + 640 * a2 + dword_1BB904;
  }
  if ( dword_1BBA4E >> 16 > a2 )
  {
    v8 += ((dword_1BBA4E >> 16) - a2) * *(int16_t *)dword_1BC2A8;
    v13 += 640 * ((dword_1BBA4E >> 16) - a2);
  }
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= v6 - v7 )
      break;
    v11 = v8;
    v12 = (_BYTE *)v13;
    for ( j = 0; j < v4 - v5; ++j )
    {
      if ( *v11 )
      {
        if ( (uint8_t)*v11 >= 0xF0u )
          *v12 = byte_1AB358[256 * (uint8_t)*v11 + (uint8_t)*v12];
        else
          *v12 = *v11;
      }
      ++v12;
      ++v11;
    }
    v8 += *(int16_t *)dword_1BC2A8;
    v13 += 640;
  }
  return result;
}
// 1BB904: using guessed type int dword_1BB904;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (001489F4) --------------------------------------------------------
int __fastcall sub_1489F4(int a1, int a2, int *a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-40h]
  int v6; // [esp+10h] [ebp-30h]
  int v7; // [esp+10h] [ebp-30h]
  int v8; // [esp+14h] [ebp-2Ch]
  int v9; // [esp+18h] [ebp-28h]
  int v10; // [esp+1Ch] [ebp-24h]
  int v11; // [esp+20h] [ebp-20h]
  int v12; // [esp+24h] [ebp-1Ch]
  int v13; // [esp+28h] [ebp-18h]
  int v14; // [esp+28h] [ebp-18h]
  char *v15; // [esp+2Ch] [ebp-14h]
  int16_t *v16; // [esp+2Ch] [ebp-14h]
  int v17; // [esp+30h] [ebp-10h]
  int v18; // [esp+34h] [ebp-Ch]
  int v19; // [esp+38h] [ebp-8h]

  v9 = a1;
  v10 = a2;
  v11 = 639;
  v12 = 479;
  v15 = (char *)(a3 + 1);
  if ( dword_1BBA4A >> 16 > a1 )
    v9 = dword_1BBA4A >> 16;
  if ( dword_1BBA4E >> 16 > a2 )
    v10 = dword_1BBA4E >> 16;
  if ( *(int *)((char *)&dword_1BBA4A + 2) >> 16 < a1 + *(int16_t *)dword_1BC2A8 )
    v11 = *(int *)((char *)&dword_1BBA4A + 2) >> 16;
  if ( *(int *)((char *)&dword_1BBA4E + 2) >> 16 < a2 + (*(int *)dword_1BC2A8 >> 16) )
    v12 = *(int *)((char *)&dword_1BBA4E + 2) >> 16;
  v6 = a1;
  v8 = (*a3 >> 16) + a2;
  v17 = dword_1BB904 + 640 * v8 + a1;
  v13 = v17;
  if ( a2 + (*(int *)dword_1BC2A8 >> 16) >= v12 )
    v4 = v12;
  else
    v4 = (*(int *)dword_1BC2A8 >> 16) + a2;
  while ( 1 )
  {
    result = v8;
    if ( v8 > v4 )
      break;
    v18 = *(int16_t *)v15;
    v16 = (int16_t *)(v15 + 2);
    v19 = *v16;
    v15 = (char *)(v16 + 1);
    if ( v18 )
    {
      if ( v8 >= v10 && v6 < v11 )
      {
        v14 = v19 + v13;
        v7 = v19 + v6;
        if ( v7 < v9 )
        {
          v15 += v9 - v7;
          v14 += v9 - v7;
          v18 -= v9 - v7;
          v7 = v9;
        }
        if ( v18 + v7 <= v11 )
        {
          if ( v18 > 0 )
            sub_148605(v15, v14, v18);
        }
        else if ( v11 - v7 > 0 )
        {
          sub_148605(v15, v14, v11 - v7 + 1);
        }
        v6 = v18 + v7;
        v15 += v18;
        v13 = v18 + v14;
      }
      else
      {
        v15 += v18;
      }
    }
    else
    {
      v17 += 640 * v19;
      v13 = v17;
      v6 = a1;
      v8 += v19;
    }
    if ( ((uint8_t)v15 & 1) != 0 )
      ++v15;
  }
  return result;
}
// 1BB904: using guessed type int dword_1BB904;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (00148C33) --------------------------------------------------------
int __fastcall sub_148C33(int a1, int a2, int *a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-4Ch]
  int j; // [esp+10h] [ebp-3Ch]
  int i; // [esp+10h] [ebp-3Ch]
  int v8; // [esp+14h] [ebp-38h]
  int v9; // [esp+14h] [ebp-38h]
  int v10; // [esp+18h] [ebp-34h]
  int v11; // [esp+1Ch] [ebp-30h]
  int v12; // [esp+20h] [ebp-2Ch]
  int v13; // [esp+24h] [ebp-28h]
  int v14; // [esp+28h] [ebp-24h]
  _BYTE *v15; // [esp+2Ch] [ebp-20h]
  _BYTE *v16; // [esp+2Ch] [ebp-20h]
  int16_t *v17; // [esp+30h] [ebp-1Ch]
  int16_t *v18; // [esp+30h] [ebp-1Ch]
  int v19; // [esp+34h] [ebp-18h]
  _BYTE *v20; // [esp+38h] [ebp-14h]
  _BYTE *v21; // [esp+3Ch] [ebp-10h]
  int v22; // [esp+40h] [ebp-Ch]
  int v23; // [esp+44h] [ebp-8h]

  v11 = a1;
  v12 = a2;
  v13 = 639;
  v14 = 479;
  v17 = (int16_t *)(a3 + 1);
  if ( dword_1BBA4A >> 16 > a1 )
    v11 = dword_1BBA4A >> 16;
  if ( dword_1BBA4E >> 16 > a2 )
    v12 = dword_1BBA4E >> 16;
  if ( *(int *)((char *)&dword_1BBA4A + 2) >> 16 < a1 + (*(int *)dword_1BC2A8 >> 16) )
    v13 = *(int *)((char *)&dword_1BBA4A + 2) >> 16;
  if ( *(int *)((char *)&dword_1BBA4E + 2) >> 16 < a2 + (*(int *)dword_1BC2A8 >> 16) )
    v14 = *(int *)((char *)&dword_1BBA4E + 2) >> 16;
  v8 = a1;
  v10 = (*a3 >> 16) + a2;
  v19 = dword_1BB904 + 640 * v10 + a1;
  v15 = (_BYTE *)v19;
  if ( a2 + (*(int *)dword_1BC2A8 >> 16) >= v14 )
    v4 = v14;
  else
    v4 = (*(int *)dword_1BC2A8 >> 16) + a2;
  while ( 1 )
  {
    result = v10;
    if ( v10 > v4 )
      break;
    v22 = *v17;
    v18 = v17 + 1;
    v23 = *v18;
    v17 = v18 + 1;
    if ( v22 )
    {
      if ( v10 >= v12 && v8 < v13 )
      {
        v16 = &v15[v23];
        v9 = v23 + v8;
        if ( v9 < v11 )
        {
          v17 = (int16_t *)((char *)v17 + v11 - v9);
          v16 += v11 - v9;
          v22 -= v11 - v9;
          v9 = v11;
        }
        v20 = v17;
        v21 = v16;
        if ( v22 + v9 <= v13 )
        {
          if ( v22 > 0 )
          {
            for ( i = 0; i < v22; ++i )
            {
              if ( *v20 )
              {
                if ( (uint8_t)*v20 >= 0xF0u )
                  *v21 = byte_1AB358[256 * (uint8_t)*v20 + (uint8_t)*v21];
                else
                  *v21 = *v20;
              }
              ++v20;
              ++v21;
            }
          }
        }
        else if ( v13 - v9 > 0 )
        {
          for ( j = 0; v13 - v9 + 1 > j; ++j )
          {
            if ( *v20 )
            {
              if ( (uint8_t)*v20 >= 0xF0u )
                *v21 = byte_1AB358[256 * (uint8_t)*v20 + (uint8_t)*v21];
              else
                *v21 = *v20;
            }
            ++v20;
            ++v21;
          }
        }
        v8 = v22 + v9;
        v17 = (int16_t *)((char *)v17 + v22);
        v15 = &v16[v22];
      }
      else
      {
        v17 = (int16_t *)((char *)v17 + v22);
      }
    }
    else
    {
      v19 += 640 * v23;
      v15 = (_BYTE *)v19;
      v8 = a1;
      v10 += v23;
    }
    if ( ((uint8_t)v17 & 1) != 0 )
      v17 = (int16_t *)((char *)v17 + 1);
  }
  return result;
}
// 1BB904: using guessed type int dword_1BB904;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (00148F57) --------------------------------------------------------
int __fastcall sub_148F57( int a1, int a2, int a3)
{
  int16_t v3; // ax
  int result; // eax
  int16_t v5; // ax
  int v6; // [esp+0h] [ebp-A4h]
  int v7; // [esp+4h] [ebp-A0h]
  int v8; // [esp+4h] [ebp-A0h]
  int v9; // [esp+14h] [ebp-90h]
  int v10; // [esp+1Ch] [ebp-88h]
  int v11; // [esp+1Ch] [ebp-88h]
  int v12; // [esp+24h] [ebp-80h]
  int v13; // [esp+28h] [ebp-7Ch]
  int v14; // [esp+2Ch] [ebp-78h]
  int v15; // [esp+30h] [ebp-74h]
  int v16; // [esp+3Ch] [ebp-68h]
  int v17; // [esp+40h] [ebp-64h]
  int v18; // [esp+48h] [ebp-5Ch]
  int16_t v19; // [esp+5Ch] [ebp-48h]
  int16_t v20; // [esp+60h] [ebp-44h]
  int16_t v21; // [esp+64h] [ebp-40h]
  int16_t v22; // [esp+68h] [ebp-3Ch]
  int16_t v23; // [esp+6Ch] [ebp-38h]
  int16_t v24; // [esp+70h] [ebp-34h]
  int16_t v25; // [esp+74h] [ebp-30h]
  int16_t v26; // [esp+78h] [ebp-2Ch]
  int16_t v27; // [esp+88h] [ebp-1Ch]
  int16_t v28; // [esp+8Ch] [ebp-18h]
  int16_t v29; // [esp+98h] [ebp-Ch]

  v17 = 100000000;
  v29 = *(_WORD *)dword_1BC2A8;
  if ( a1 < SHIWORD(dword_1BBA4A) )
  {
    v19 = HIWORD(dword_1BBA4A) - a1;
    v20 = HIWORD(dword_1BBA4A);
  }
  else
  {
    v19 = 0;
    v20 = a1;
  }
  if ( a2 < SHIWORD(dword_1BBA4E) )
  {
    v21 = HIWORD(dword_1BBA4E) - a2;
    v22 = HIWORD(dword_1BBA4E);
  }
  else
  {
    v21 = 0;
    v22 = a2;
  }
  if ( (int16_t)(v29 + a1 - 1) >= (int16_t)dword_1BBA4E )
    v23 = dword_1BBA4E - v20 + 1;
  else
    v23 = v29 + a1 - v20;
  if ( (int16_t)(*(_WORD *)(dword_1BC2A8 + 2) + a2 - 1) >= (int16_t)dword_1BBA52 )
    v24 = dword_1BBA52 - v22 + 1;
  else
    v24 = *(_WORD *)(dword_1BC2A8 + 2) + a2 - v22;
  v10 = *(uint16_t *)(a3 + 2);
  v12 = a1 + v22 * HIDWORD(qword_184530);
  v9 = v12;
  v14 = 2;
  while ( v21 > v10 )
  {
    v3 = *(_WORD *)(a3 + 2 * v14);
    if ( v3 )
      v14 += (v3 + 1) / 2;
    else
      v10 += *(uint16_t *)(a3 + 2 * v14 + 2);
    v14 += 2;
  }
  if ( v21 < v10 )
  {
    v12 += HIDWORD(qword_184530) * (v10 - v21);
    v9 = v12;
  }
  v11 = v10 - v21;
  v18 = v19 + v12;
  v6 = v23 + v19 + v12;
  v16 = v9;
  v15 = 0;
  while ( 1 )
  {
    result = v24;
    if ( v24 <= v11 )
      break;
    v27 = *(_WORD *)(a3 + 2 * v14);
    v5 = *(_WORD *)(a3 + 2 * v14 + 2);
    v28 = v5;
    v14 += 2;
    if ( v27 )
    {
      v9 += v5;
      v13 = 2 * v14;
      v7 = v27 + v9;
      if ( v9 < v6 )
      {
        if ( v9 < v18 )
        {
          v25 = v18 - v9;
          if ( (int16_t)(v18 - v9) > v27 )
            v25 = v27;
          v13 += v25;
          v9 += v25;
        }
        v26 = v6 - v9;
        if ( v9 + (int16_t)(v6 - v9) >= v7 )
          v26 = v7 - v9;
        v8 = v26 + v9;
        while ( v9 < v8 )
        {
          if ( !v15 )
          {
            v16 = v9;
            v15 = 1;
          }
          v17 = v9;
          *(_BYTE *)(v9 + dword_1BB904) = *(_BYTE *)(v13 + a3);
          ++v13;
          ++v9;
        }
      }
      v14 += (v27 + 1) / 2;
    }
    else
    {
      v11 += v5;
      if ( v15 == 1 )
        sub_125FFB(v16 % 640, v16 / 640, v17 % 640);
      v12 += 640 * v28;
      v9 = v12;
      v18 = v19 + v12;
      v6 = v23 + v19 + v12;
      v16 = v12;
      v15 = 0;
    }
  }
  return result;
}
// 184530: using guessed type int64_t qword_184530;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (00149890) --------------------------------------------------------
char __stdcall sub_149890(unsigned int a1, int a2)
{
  unsigned int v2; // ebx

  v2 = a1;
  if ( !dword_18A5AC )
  {
    dword_18916C = 0;
    dword_1C3C34 = (int (__fastcall *)(_DWORD))sub_149F20;
    dword_189164 = (int)sub_149C80;
    dword_1C3C3C = (int)sub_149BC0;
    dword_1C3C38 = (int (__stdcall *)(_DWORD))sub_149ED0;
    dword_1C3C30 = sub_149C40;
    dword_189168 = sub_149C40;
    dword_189170 = sub_149950;
    off_18A5B8 = (int (*)())sub_149A20;
    dword_18A5AC = (int (__fastcall *)(_DWORD))sub_149B30;
    dword_1C9830 = (int)sub_1499C0;
  }
  if ( dword_18913C )
    return 0;
  dword_189140 = a2;
  if ( a1 <= 0xC8 )
    v2 = 200;
  dword_1C3C1C = v2;
  dword_1C3C18 = 0x1234DD / v2;
  return 1;
}
// 149950: using guessed type int __stdcall sub_149950(int, int, int);
// 1499C0: using guessed type int sub_1499C0();
// 149B30: using guessed type int sub_149B30();
// 149C40: using guessed type int __stdcall sub_149C40(int);
// 18913C: using guessed type int dword_18913C;
// 189140: using guessed type int dword_189140;
// 189164: using guessed type int dword_189164;
// 189168: using guessed type int (__stdcall *dword_189168)(_DWORD);
// 18916C: using guessed type int (__stdcall *dword_18916C)(_DWORD);
// 189170: using guessed type int (__stdcall *dword_189170)(_DWORD, _DWORD, _DWORD);
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);
// 18A5B8: using guessed type int (*off_18A5B8)();
// 1C3C18: using guessed type int dword_1C3C18;
// 1C3C1C: using guessed type int dword_1C3C1C;
// 1C3C30: using guessed type int (__stdcall *dword_1C3C30)(_DWORD);
// 1C3C34: using guessed type int (__fastcall *dword_1C3C34)(_DWORD);
// 1C3C38: using guessed type int (__stdcall *dword_1C3C38)(_DWORD);
// 1C3C3C: using guessed type int dword_1C3C3C;
// 1C9830: using guessed type int dword_1C9830;


//----- (00149A20) --------------------------------------------------------
void sub_149A20()
{
  int v0; // eax
  uint8_t v1; // al
  uint8_t v2; // ah

  if ( ++dword_18914C == 1 )
  {
    /* __asm: int     2Fh; - Multiplex - MS WINDOWS - GET DEVICE API ENTRY POINT */ DECOMP_TODO("inline asm");
    *(_WORD *)byte_1C3C22 = 0;
    *(_WORD *)&byte_1C3C22[2] = 0;
    *(_WORD *)&byte_1C3C22[4] = 0;
    if ( !*(_DWORD *)byte_1C3C22 )
    {
      sub_15421D((unsigned int)sub_149B30, (unsigned int)sub_149A20);
      sub_1543A1((unsigned int)&dword_189148, 4);
      sub_1400A9((int)sub_149BB0);
      dword_1C3C10 = v0;
      sub_1402FD(v0, dword_1C3C1C);
      sub_1404C7(dword_1C3C10);
      sub_1403E9();
      hr_outbyte(0x43u, 0x34u);
      hr_outbyte(0x40u, v1);
      hr_outbyte(0x40u, v2);
      while ( 1 )
        ;
    }
    dword_18A5AC = (int (__fastcall *)(_DWORD))sub_149B10;
  }
}
// 149AB3: variable 'v0' is possibly undefined
// 149AEE: variable 'v1' is possibly undefined
// 149AF4: variable 'v2' is possibly undefined
// 149B10: using guessed type int sub_149B10();
// 149B30: using guessed type int sub_149B30();
// 149BB0: using guessed type int __stdcall sub_149BB0(int);
// 189148: using guessed type int dword_189148;
// 18914C: using guessed type int dword_18914C;
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);
// 1C3C10: using guessed type int dword_1C3C10;
// 1C3C1C: using guessed type int dword_1C3C1C;


//----- (00149BC0) --------------------------------------------------------
void __stdcall sub_149BC0(_DWORD *a1)
{
  int v1; // eax
  _DWORD *v2; // ecx

  if ( dword_18913C )
  {
    sub_1411BA(a1[14]);
    sub_140D8F(a1[14]);
    sub_1543D5(a1[21], 2 * a1[15]);
    sub_132614(a1[21]);
    v1 = dword_18913C;
    if ( a1 == (_DWORD *)dword_18913C )
    {
      dword_18913C = *(_DWORD *)(dword_18913C + 52);
    }
    else if ( *(_DWORD *)(dword_18913C + 52) )
    {
      while ( 1 )
      {
        v2 = *(_DWORD **)(v1 + 52);
        if ( a1 == v2 )
          break;
        v1 = *(_DWORD *)(v1 + 52);
        if ( !*(_DWORD *)(v1 + 52) )
          return;
      }
      *(_DWORD *)(v1 + 52) = v2[13];
    }
  }
}
// 18913C: using guessed type int dword_18913C;


//----- (00149C80) --------------------------------------------------------
char __stdcall sub_149C80( int a1, _DWORD *a2)
{
  bool v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  char result; // al
  int v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax

  if ( dword_189140 )
    goto LABEL_12;
  if ( dword_189144 )
  {
    sub_13F84F(6, dword_189140);
    v2 = (a1 & 0x20) != 0 || a2[19];
    sub_13F84F(7, v2);
    sub_13F84F(8, a2[18] != 0);
    sub_140A57(aSb16Dig, 0);
    dword_189140 = v3;
    if ( !v3 )
    {
      sub_140A57(aSbproDig, 0);
      dword_189140 = v4;
      if ( !v4 )
      {
        sub_140A57(aSblasterDig, 0);
        dword_189140 = v5;
      }
    }
  }
  if ( dword_189140 )
  {
LABEL_12:
    if ( dword_189140 == -1 )
    {
      return 0;
    }
    else
    {
      if ( a2[18] )
      {
        if ( a2[19] )
          v7 = 3;
        else
          v7 = 1;
      }
      else if ( a2[19] )
      {
        v7 = 2;
      }
      else
      {
        v7 = 0;
      }
      sub_14197D((_DWORD *)dword_189140, a2[16], v7);
      v8 += 3;
      LOBYTE(v8) = v8 & 0xFC;
      a2[25] = v8;
      v9 = (a2[5] >> 2) + 4095;
      LOWORD(v9) = v9 & 0xF000;
      a2[15] = v9;
      v10 = a2[25];
      if ( v10 > a2[15] )
        a2[15] = v10;
      v11 = sub_13259F(2 * a2[15]);
      a2[21] = v11;
      if ( v11 )
      {
        sub_1543A1(a2[21], 2 * a2[15]);
        sub_140BB1(dword_189140);
        a2[14] = v12;
        if ( a2[14] )
        {
          a2[22] = a2[15] + a2[21];
          sub_149E40((int)a2);
          v13 = dword_18913C;
          dword_18913C = (int)a2;
          a2[13] = v13;
          return 1;
        }
        else
        {
          sub_132614(a2[21]);
          return 0;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    result = 0;
    dword_189140 = -1;
  }
  return result;
}
// 149CF4: variable 'v3' is possibly undefined
// 149D11: variable 'v4' is possibly undefined
// 149D2D: variable 'v5' is possibly undefined
// 149D98: variable 'v8' is possibly undefined
// 149DFC: variable 'v12' is possibly undefined
// 18913C: using guessed type int dword_18913C;
// 189140: using guessed type int dword_189140;
// 189144: using guessed type int dword_189144;


//----- (00149E40) --------------------------------------------------------
void __fastcall sub_149E40(int a1)
{
  int v2; // ebx
  int v3; // eax

  sub_140DFC(*(int **)(a1 + 56));
  v2 = *(_DWORD *)(a1 + 72);
  if ( v2 )
  {
    if ( *(_DWORD *)(a1 + 76) )
      v3 = 3;
    else
      v3 = 1;
  }
  else if ( *(_DWORD *)(a1 + 76) )
  {
    v3 = 2;
  }
  else
  {
    v3 = 0;
  }
  sub_140FF1(*(_DWORD *)(a1 + 56), v3, v2 != 0);
  sub_141227(*(_DWORD *)(a1 + 56), *(_DWORD *)(a1 + 64));
  sub_1420F9(*(_DWORD *)(a1 + 56), 0, a1);
  sub_14129D(*(_DWORD *)(a1 + 56), 127);
}


//----- (00149ED0) --------------------------------------------------------
unsigned int __stdcall sub_149ED0(unsigned int *a1)
{
  int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // ecx

  sub_149F20();
  if ( a1[27] )
    v2 = (dword_18A5AC(v1) - a1[27]) * (uint64_t)a1[5] / 0x3E8;
  else
    v2 = a1[26];
  v3 = v2;
  if ( v2 > a1[26] )
  {
    a1[27] = 0;
    v3 = a1[26];
  }
  return v3 + a1[20];
}
// 149EE6: variable 'v1' is possibly undefined
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);


//----- (00149F20) --------------------------------------------------------
void sub_149F20()
{
  int i; // esi
  unsigned int v1; // eax
  unsigned int v2; // eax
  int v3; // ebp
  int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  char *v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // [esp+0h] [ebp-10h]

  for ( i = dword_18913C; i; i = *(_DWORD *)(i + 52) )
  {
    v1 = *(_DWORD *)(i + 16);
    if ( v1 > *(_DWORD *)(i + 100) || *(_DWORD *)(i + 68) && v1 > 3 )
    {
      sub_141A76(*(_DWORD **)(i + 56));
      v3 = v2;
      if ( v2 <= 1 )
      {
        v4 = dword_18A5AC(v2);
        v5 = *(_DWORD *)(i + 16);
        v13 = v4;
        LOWORD(v5) = v5 & 0xFFFC;
        v6 = *(_DWORD *)(i + 60);
        if ( v5 > v6 )
          v5 = v6 & 0xFFFFFFFC;
        v7 = sub_14A010(v5, *(_DWORD *)(i + 4), *(char **)i, *(char **)(i + 8), *(char **)(i + 4 * v3 + 84));
        v8 = *(_DWORD *)(i + 108);
        *(_DWORD *)(i + 8) = v7;
        if ( !v8 || (sub_1413FF(*(_DWORD *)(i + 56)), v9 == 2) )
        {
          *(_DWORD *)(i + 108) = v13;
          v10 = *(_DWORD *)(i + 80);
          v11 = *(_DWORD *)(i + 104);
          *(_DWORD *)(i + 104) = 0;
          *(_DWORD *)(i + 80) = v11 + v10;
        }
        sub_141B5B(*(int **)(i + 56), v3, *(_DWORD *)(i + 4 * v3 + 84), v5);
        v12 = *(_DWORD *)(i + 16) - v5;
        *(_DWORD *)(i + 104) += v5;
        *(_DWORD *)(i + 16) = v12;
      }
    }
  }
}
// 149F5D: variable 'v2' is possibly undefined
// 149FB4: variable 'v9' is possibly undefined
// 18913C: using guessed type int dword_18913C;
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);


//----- (0014A010) --------------------------------------------------------
char *__stdcall sub_14A010(unsigned int a1, int a2, char *a3, char *a4, char *a5)
{
  char *v5; // edx
  unsigned int v6; // ebp

  v5 = a4;
  v6 = a2 - (_DWORD)a4;
  if ( a2 - (int)a4 <= a1 )
  {
    if ( v6 )
    {
      qmemcpy(a5, a4, v6);
      a5 += v6;
      a1 -= v6;
    }
    v5 = a3;
  }
  if ( a1 )
  {
    qmemcpy(a5, v5, a1);
    v5 += a1;
  }
  return v5;
}


//----- (0014A090) --------------------------------------------------------
int __fastcall sub_14A090(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v6; // ebx
  int v7; // edx
  unsigned int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // ebx
  unsigned int v11; // edi

  if ( !a5 )
    return 0;
  if ( dword_189154 )
    a1 = ((int(*)())(void*)dword_1C3C34)();
  v6 = a5[264];
  if ( v6 != -1 )
  {
    if ( !a5[265] || a5[266] )
      return 0;
    if ( (unsigned int)dword_1C3C38(a5[v6 + 257]) >= *(_DWORD *)(a5[a5[264] + 257] + 32) >> 7 )
    {
      a5[265] = 0;
      return 0;
    }
    goto LABEL_21;
  }
  if ( a5[254] )
    return 0;
  v7 = dword_18A5AC(a1);
  v8 = a5[255];
  v9 = 100 * v7;
  if ( v8 == -1 )
  {
    a5[255] = a5[256] + v9;
LABEL_21:
    sub_14D000(a5);
    return 1;
  }
  if ( v9 < v8 )
    goto LABEL_21;
  v10 = v8 + a5[256];
  v11 = a5[256];
  a5[255] = v10;
  if ( v9 - v10 > v11 )
    a5[255] = v11 + v9;
  if ( a5[256] )
    a5[254] = 1;
  return 0;
}
// 189154: using guessed type int dword_189154;
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);
// 1C3C34: using guessed type int (*dword_1C3C34)(void);
// 1C3C38: using guessed type int (__stdcall *dword_1C3C38)(_DWORD);


//----- (0014A1C0) --------------------------------------------------------
void __stdcall sub_14A1C0(void (__noreturn *a1)(), void (__noreturn *a2)(), int a3, int a4)
{
  void (__noreturn *v4)(); // esi
  void (__noreturn *v5)(); // ebp
  int v6; // eax
  uint8_t i; // dl
  int v8; // eax

  v4 = a1;
  v5 = a2;
  if ( a4 && *(_DWORD *)(a4 + 1056) != -1 )
  {
    if ( (unsigned int)a2 > (unsigned int)sub_10000 )
      v5 = sub_10000;
    if ( (unsigned int)a1 > (unsigned int)sub_10000 )
      v4 = sub_10000;
    while ( (a3 & 0xFE000) != 0 )
    {
      v6 = 0x2000;
      for ( i = 0; i < 7u; ++i )
      {
        if ( (a3 & v6) != 0 )
        {
          a3 &= ~v6;
          goto LABEL_13;
        }
        v6 *= 2;
      }
      i = -1;
LABEL_13:
      if ( i < 7u )
      {
        v8 = a4 + 4 * i;
        if ( *(_DWORD *)(v8 + 1028) )
        {
          if ( dword_189170 )
            dword_189170(v4, v5, *(_DWORD *)(v8 + 1028));
        }
      }
    }
  }
}
// 10000: using guessed type void __noreturn sub_10000();
// 189170: using guessed type int (__stdcall *dword_189170)(_DWORD, _DWORD, _DWORD);


//----- (0014A2D0) --------------------------------------------------------
int __fastcall sub_14A2D0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  unsigned int v10; // ebx
  unsigned int v11; // edi
  unsigned int v12; // ebp
  unsigned int v13; // ecx
  unsigned int v14; // eax
  int v15; // eax
  int v16; // [esp+10h] [ebp-14h]
  int v17; // [esp+14h] [ebp-10h]

  if ( !a6 )
    return 0;
  if ( dword_189154 )
    a1 = ((int(*)())(void*)dword_1C3C34)();
  if ( !*(_DWORD *)(a6 + 996) || a5 == 2 )
    return 0;
  if ( !*(_DWORD *)(a6 + 1128) )
  {
    v7 = dword_18A5AC(a1);
    v8 = *(_DWORD *)(a6 + 1124);
    *(_DWORD *)(a6 + 1128) = v7;
    if ( v8 )
    {
      v9 = *(_DWORD *)(a6 + 1156);
      *(_DWORD *)(a6 + 1124) = 0;
      *(_DWORD *)(a6 + 1156) = v7 - v8 + v9;
    }
  }
  if ( *(_DWORD *)(a6 + 996) == 1 )
  {
    if ( !(uint8_t)sub_167F40(*(_DWORD *)(a6 + 928), (unsigned int *)(a6 + 1000)) )
    {
      result = *(_DWORD *)(a6 + 104);
      *(_DWORD *)(a6 + 996) = 0;
      if ( result )
      {
        *(_DWORD *)(a6 + 884) = 0;
        *(_DWORD *)(a6 + 888) = 0;
        *(_DWORD *)(a6 + 892) = 0;
        result = 1;
        *(_DWORD *)(a6 + 896) = 0;
      }
      return result;
    }
    *(_DWORD *)(a6 + 996) = 2;
  }
  v10 = *(_DWORD *)(a6 + 1000);
  v16 = *(_DWORD *)(a6 + 1004);
  v11 = v10 + *(_DWORD *)(a6 + 1008);
  v17 = *(_DWORD *)(a6 + 1012) + v16;
  if ( a5 == 1 )
  {
    while ( (uint8_t)sub_167F40(*(_DWORD *)(a6 + 928), (unsigned int *)(a6 + 1000)) )
    {
      if ( v10 > *(_DWORD *)(a6 + 1000) )
        v10 = *(_DWORD *)(a6 + 1000);
      if ( *(_DWORD *)(a6 + 1008) + *(_DWORD *)(a6 + 1000) > v11 )
        v11 = *(_DWORD *)(a6 + 1008) + *(_DWORD *)(a6 + 1000);
      v17 = *(_DWORD *)(a6 + 1012) + *(_DWORD *)(a6 + 1004);
    }
  }
  else
  {
    v12 = (unsigned int)(5 * *(_DWORD *)(a6 + 1012) * *(_DWORD *)(a6 + 1008)) >> 2;
    while ( (uint8_t)sub_167F40(*(_DWORD *)(a6 + 928), (unsigned int *)(a6 + 1000)) )
    {
      v13 = *(_DWORD *)(a6 + 1000);
      v12 += (unsigned int)(5 * *(_DWORD *)(a6 + 1012) * *(_DWORD *)(a6 + 1008)) >> 2;
      if ( v10 <= v13 )
        v13 = v10;
      v14 = *(_DWORD *)(a6 + 1008) + *(_DWORD *)(a6 + 1000);
      if ( v11 > v14 )
        v14 = v11;
      if ( v12 < (v14 - v13) * (*(_DWORD *)(a6 + 1012) + *(_DWORD *)(a6 + 1004) - v16) )
        goto LABEL_32;
      v11 = v14;
      v10 = v13;
      v17 = *(_DWORD *)(a6 + 1012) + *(_DWORD *)(a6 + 1004);
    }
  }
  *(_DWORD *)(a6 + 996) = 0;
LABEL_32:
  if ( (*(_BYTE *)(a6 + 902) & 0x30) != 0 )
  {
    v16 *= 2;
    v17 *= 2;
  }
  v15 = *(_DWORD *)(a6 + 908);
  *(_DWORD *)(a6 + 884) = v10 + *(_DWORD *)(a6 + 904);
  *(_DWORD *)(a6 + 888) = v15 + v16;
  *(_DWORD *)(a6 + 892) = v11 - v10;
  *(_DWORD *)(a6 + 896) = v17 - v16;
  return 1;
}
// 189154: using guessed type int dword_189154;
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);
// 1C3C34: using guessed type int (*dword_1C3C34)(void);


//----- (0014A580) --------------------------------------------------------
int __stdcall sub_14A580(int a1, void *a2, int a3)
{
  int result; // eax
  int v4; // eax
  uint8_t v5; // dl
  int v6; // eax
  _DWORD *v7; // ebp
  int v8; // eax
  unsigned int v9; // esi
  unsigned int v10; // edx

  if ( !a3 )
    return 0;
  v4 = 0x2000;
  v5 = 0;
  while ( (a1 & v4) == 0 )
  {
    ++v5;
    v4 *= 2;
    if ( v5 >= 7u )
    {
      v5 = -1;
      break;
    }
  }
  if ( v5 >= 7u )
    return 0;
  v6 = a3 + 4 * v5;
  v7 = *(_DWORD **)(v6 + 964);
  if ( !v7 )
    return 0;
  if ( (HIBYTE(*(_DWORD *)(v6 + 72)) & 0x80u) == 0 )
  {
    if ( *v7 != 4 && *v7 != 3 )
      qmemcpy(a2, v7 + 1, *v7 - 4);
    return *v7 - 4;
  }
  else
  {
    v8 = v7[1];
    if ( !v8 || v8 == -1 )
      return v7[1];
    if ( dword_189158 )
      goto LABEL_18;
    v9 = *(_DWORD *)(a3 + 1116) + 0x2000;
    v10 = *(_DWORD *)(a3 + 1180);
    *(_DWORD *)(a3 + 1116) = v9;
    if ( v9 > v10 )
      *(_DWORD *)(a3 + 1180) = v9;
    result = sub_13259F(0x2000);
    dword_189158 = result;
    if ( result )
    {
LABEL_18:
      sub_1676F0(v7 + 2, v7[1], dword_189158, (int)a2, (int)a2 + 0x1000000, (int)a2);
      return v7[1];
    }
  }
  return result;
}
// 189158: using guessed type int dword_189158;


//----- (0014A6BC) --------------------------------------------------------
void __stdcall sub_14A6BC( int a1, unsigned int a2, int a3, int a4)
{
  int v4; // edi
  int v5; // ebx
  uint8_t *v6; // ebp
  uint8_t v7; // cl
  uint8_t v8; // ch
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // ebp
  int v14; // eax
  int v15; // eax
  int v16; // ebp
  unsigned int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ebp
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // edx
  int v25; // eax
  int v26; // eax
  int v27; // edx
  _BYTE v28[256]; // [esp+0h] [ebp-130h] BYREF
  int v29; // [esp+100h] [ebp-30h]
  int v30; // [esp+104h] [ebp-2Ch]
  uint8_t *v31; // [esp+108h] [ebp-28h]
  unsigned int v32; // [esp+110h] [ebp-20h]
  unsigned int v33; // [esp+114h] [ebp-1Ch]
  unsigned int v34; // [esp+118h] [ebp-18h]
  char v35; // [esp+11Ch] [ebp-14h]
  uint8_t v36; // [esp+120h] [ebp-10h]

  if ( a4 )
  {
    if ( a2 > 0x100 )
      a2 = 256;
    if ( (a1 & 8) != 0 )
      v4 = 8;
    else
      v4 = ((a1 & 1) != 0) + 3;
    v32 = a1 & 0xE;
    v31 = (uint8_t *)(a4 + 108);
    v30 = 0;
    do
    {
      v5 = v30;
      v6 = v31 + 1;
      v33 = -1;
      v7 = *v31;
      v31 += 2;
      v8 = *v6;
      v36 = *v31;
      v34 = 0;
      ++v31;
      if ( a2 )
      {
        do
        {
          if ( v32 > 6 )
          {
LABEL_15:
            v29 = (int)*(uint8_t *)(a3 + v4 * v5 + 2) >> 2;
            v29 = (v7 - v29) * (v7 - v29);
            v26 = v8 - ((int)*(uint8_t *)(a3 + v4 * v5 + 4) >> 2);
            v11 = v26 * v26 + v29;
            v13 = v36;
            v12 = (int)*(uint8_t *)(a3 + v4 * v5 + 6) >> 2;
LABEL_16:
            v29 = v11;
            v21 = v13 - v12;
LABEL_17:
            v17 = v29 + v21 * v21;
          }
          else
          {
            switch ( v5 )
            {
              case 0:
                v9 = v7 - *(uint8_t *)(a3 + v4 * v5);
                v29 = v9 * v9;
                v10 = v8 - *(uint8_t *)(a3 + v4 * v5 + 1);
                v11 = v10 * v10 + v29;
                v12 = *(uint8_t *)(a3 + v4 * v5 + 2);
                v13 = v36;
                goto LABEL_16;
              case 1:
              case 3:
              case 5:
                goto LABEL_15;
              case 2:
                v14 = v7 - ((int)*(uint8_t *)(a3 + v4 * v5) >> 2);
                v29 = v14 * v14;
                v15 = v8 - ((int)*(uint8_t *)(a3 + v4 * v5 + 1) >> 2);
                v16 = (int)*(uint8_t *)(a3 + v4 * v5 + 2) >> 2;
                v29 += v15 * v15;
                v17 = v29 + (v36 - v16) * (v36 - v16);
                break;
              case 4:
                v18 = v7 - *(uint8_t *)(a3 + v4 * v5 + 2);
                v29 = v18 * v18;
                v19 = v8 - *(uint8_t *)(a3 + v4 * v5 + 1);
                v20 = *(uint8_t *)(a3 + v4 * v5);
                v29 += v19 * v19;
                v21 = v36 - v20;
                goto LABEL_17;
              case 6:
                v22 = v7 - ((int)*(uint8_t *)(a3 + v4 * v5 + 2) >> 2);
                v29 = v22 * v22;
                v23 = v8 - ((int)*(uint8_t *)(a3 + v4 * v5 + 1) >> 2);
                v24 = v23 * v23 + v29;
                v25 = v36 - ((int)*(uint8_t *)(a3 + v4 * v5) >> 2);
                v29 = v24;
                v17 = v24 + v25 * v25;
                break;
            }
          }
          if ( v17 < v33 )
          {
            v35 = v5;
            v33 = v17;
            if ( !v17 )
              break;
          }
          if ( ++v5 == 256 )
            v5 = 0;
          ++v34;
        }
        while ( v34 < a2 );
      }
      v27 = v30;
      v28[v30] = v35;
      v30 = v27 + 1;
    }
    while ( (unsigned int)(v27 + 1) < 0x100 );
    sub_168060(*(_DWORD *)(a4 + 924), v28);
  }
}


//----- (0014AA40) --------------------------------------------------------
void __stdcall sub_14AA40(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int v8; // ebp
  int v9; // ebp
  char v10; // dl
  _BYTE *v11; // edi
  int v12; // edi
  unsigned int v13; // ebx
  int v14; // eax
  unsigned int v15; // eax
  int v16; // eax
  unsigned int v17; // ecx
  char *v18; // edi
  int v19; // eax
  char v20; // bl
  _BYTE *v21; // eax
  _DWORD *v22; // eax
  int v23; // edx
  int v24; // ebx
  unsigned int *v25; // eax
  int *v26; // edx
  _DWORD *v27; // edi
  _DWORD *v28; // eax
  _DWORD *v29; // eax
  unsigned int *v30; // eax
  _DWORD *v31; // [esp+0h] [ebp-1Ch]
  int *v32; // [esp+4h] [ebp-18h]
  int v33; // [esp+8h] [ebp-14h]
  unsigned int v34; // [esp+Ch] [ebp-10h]

  if ( !a7 )
    return;
  if ( !a2 )
  {
    if ( *(_DWORD *)(a7 + 928) )
    {
      sub_132614(*(_DWORD *)(a7 + 928));
      v7 = *(_DWORD *)(a7 + 932);
      v8 = *(_DWORD *)(a7 + 1116);
      *(_DWORD *)(a7 + 928) = 0;
      *(_DWORD *)(a7 + 1116) = v8 - v7;
    }
    return;
  }
  v9 = a4;
  v10 = *(_BYTE *)(a7 + 902);
  v33 = 3;
  v34 = *(_DWORD *)(a7 + 8);
  if ( (v10 & 0x10) != 0 )
  {
    v34 >>= 1;
    v9 = 2 * a4;
  }
  else if ( (v10 & 0x20) != 0 )
  {
    v34 >>= 1;
    v33 = 7;
  }
  v11 = *(_BYTE **)(a7 + 928);
  if ( v11 )
  {
    if ( *v11 == 1 )
    {
LABEL_16:
      *(_DWORD *)(a7 + 908) = a5;
      *(_DWORD *)(a7 + 904) = a6;
      v21 = *(_BYTE **)(a7 + 928);
      *v21 = 1;
      v22 = v21 + 4;
      *((_BYTE *)v22 - 3) = (*(_BYTE *)(a7 + 902) & 0x20) != 0;
      if ( a1 )
        v23 = a3 - a5 - 1;
      else
        v23 = a5;
      v24 = v9 * v33;
      *v22 = v23 * a4 + a6 + a2;
      v25 = v22 + 1;
      *v25++ = *(_DWORD *)(a7 + 4) >> 2;
      *v25 = v34 >> 2;
      v26 = (int *)(v25 + 2);
      v27 = v25 + 4;
      v32 = (int *)(v25 + 3);
      v31 = v25 + 5;
      v28 = v25 + 1;
      if ( a1 )
      {
        *v28 = -(v24 + 4);
        *v26 = -v24;
        *v32 = -v9;
        *v27 = v9 - *(_DWORD *)(a7 + 4) - v9 * (v33 + 2);
        v29 = v31;
      }
      else
      {
        *v28 = v24 - 4;
        *v26 = v24;
        *v32 = v9;
        v29 = v31;
        *v27 = v9 - *(_DWORD *)(a7 + 4) + v24;
      }
      v30 = v29 + 2;
      *(v30 - 1) = *(_DWORD *)(a7 + 4);
      *v30 = v34;
      return;
    }
    sub_132614(*(_DWORD *)(a7 + 928));
    *(_DWORD *)(a7 + 1116) -= *(_DWORD *)(a7 + 932);
  }
  v12 = sub_167F20(*(_DWORD *)(a7 + 4), v34) + 32;
  v13 = *(_DWORD *)(a7 + 1180);
  v14 = *(_DWORD *)(a7 + 1116);
  *(_DWORD *)(a7 + 932) = v12;
  v15 = v12 + v14;
  *(_DWORD *)(a7 + 1116) = v15;
  if ( v15 > v13 )
    *(_DWORD *)(a7 + 1180) = v15;
  v16 = sub_13259F(v12);
  *(_DWORD *)(a7 + 928) = v16;
  if ( v16 )
  {
    v17 = v12;
    v18 = (char *)v16;
    LOWORD(v16) = 0;
    v19 = v16 << 16;
    LOWORD(v19) = 0;
    v20 = v17;
    v17 >>= 2;
    memset32(v18, v19, v17);
    memset(&v18[4 * v17], 0, v20 & 3);
    goto LABEL_16;
  }
}


//----- (0014AC60) --------------------------------------------------------
void __stdcall sub_14AC60(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // ebp
  int v7; // esi
  unsigned int v8; // ebp
  char v9; // cl
  int v10; // ecx
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _BYTE *v14; // eax
  int16_t *v15; // eax
  int16_t v16; // dx
  int16_t *v17; // edx
  _WORD *v18; // eax
  _WORD *v19; // ebp
  _WORD *v20; // ebp
  _WORD *v21; // eax
  _WORD *v22; // eax
  _WORD *v23; // ebp
  _WORD *v24; // eax
  unsigned int i; // edx
  int16_t v26; // dx
  _WORD *v27; // ebp
  _WORD *v28; // ebp
  int16_t v29; // ax
  unsigned int v30; // eax
  _WORD *v31; // ebp
  _WORD *v32; // ebp
  char *v33; // [esp+0h] [ebp-40h]
  unsigned int v34; // [esp+4h] [ebp-3Ch]
  unsigned int v35; // [esp+8h] [ebp-38h]
  int v36; // [esp+Ch] [ebp-34h]
  int v37; // [esp+Ch] [ebp-34h]
  int v38; // [esp+18h] [ebp-28h]
  int v39; // [esp+1Ch] [ebp-24h]
  int16_t v40; // [esp+20h] [ebp-20h]
  int v41; // [esp+24h] [ebp-1Ch]
  int16_t v42; // [esp+28h] [ebp-18h]
  unsigned int v43; // [esp+2Ch] [ebp-14h]
  char *v44; // [esp+30h] [ebp-10h]

  v33 = 0;
  if ( a6 )
  {
    if ( a3 == 320 )
    {
      a1 = 0;
      a2 = 655360;
    }
    v6 = *(_DWORD *)(a6 + 928);
    if ( v6 )
    {
      if ( *(_BYTE *)v6 == 1 )
      {
        v38 = *(_DWORD *)(v6 + 24);
        v33 = *(char **)(v6 + 4);
      }
      sub_132614(*(_DWORD *)(a6 + 928));
      *(_DWORD *)(a6 + 1116) -= *(_DWORD *)(a6 + 932);
    }
    v7 = a3;
    v41 = a3;
    v43 = 4;
    v36 = 0;
    v8 = *(_DWORD *)(a6 + 8);
    v40 = 3;
    v9 = *(_BYTE *)(a6 + 902);
    if ( (v9 & 0x10) != 0 )
    {
      v41 = 2 * a3;
      v7 = 2 * a3;
      v8 >>= 1;
    }
    else if ( (v9 & 0x20) != 0 )
    {
      v36 = a3;
      v7 = 2 * a3;
      v8 >>= 1;
      v43 = 8;
      v40 = 7;
    }
    v10 = *(_DWORD *)(a6 + 4) + 3 * v7 + v36;
    v11 = ((v8 * v7 + a3 * a4) >> 16) * v43 * *(_DWORD *)(a6 + 4) + 1024;
    *(_DWORD *)(a6 + 932) = v11;
    v37 = v10;
    v12 = v11 + *(_DWORD *)(a6 + 1116);
    *(_DWORD *)(a6 + 1116) = v12;
    if ( v12 > *(_DWORD *)(a6 + 1180) )
      *(_DWORD *)(a6 + 1180) = v12;
    v13 = sub_13259F(v11);
    *(_DWORD *)(a6 + 928) = v13;
    if ( v13 )
    {
      LOBYTE(a5) = a5 & 0xFC;
      *(_DWORD *)(a6 + 908) = a4;
      *(_DWORD *)(a6 + 904) = a5;
      v44 = (char *)(*(_DWORD *)(a6 + 928) + 1024);
      v14 = *(_BYTE **)(a6 + 928);
      *v14 = 0;
      v14[1] = (*(_BYTE *)(a6 + 902) & 0x20) != 0;
      v35 = a4 * a3 + a5;
      v14 += 8;
      v34 = HIWORD(v35);
      *((_DWORD *)v14 - 1) = a1;
      v15 = (int16_t *)(v14 + 2);
      *(v15 - 1) = v41 - *(_WORD *)(a6 + 4);
      if ( a1 )
      {
        v17 = (int16_t *)(a2 + 2 * v34++);
        v16 = *v17;
      }
      else
      {
        v16 = -2;
      }
      *v15 = v16;
      v18 = sub_14B1C0(v15 + 1, v41, *(_DWORD *)(a6 + 4), v40, v43);
      if ( a1 )
      {
        HIWORD(v35) = 0;
        *(_DWORD *)v18 = (uint16_t)v35 + 655360;
        v42 = 0;
        v39 = v8 * *(_DWORD *)(a6 + 4);
        v19 = v18 + 2;
        while ( v39 )
        {
          if ( v35 <= (unsigned int)sub_10000 )
          {
            if ( v35 + v37 <= (unsigned int)sub_10000 )
            {
              if ( v33 )
                v33 += 4 * v38;
              ++v42;
              v35 += 4 * v7;
            }
            else
            {
              v23 = v19 + 1;
              *(v23 - 1) = v42;
              *v23 = -2;
              v42 = 0;
              v24 = sub_14B1C0(v23 + 1, *(_DWORD *)(a6 + 4), *(_DWORD *)(a6 + 4), v40, v43);
              *(_DWORD *)v24 = v44;
              v24[2] = 1;
              v24[3] = -3;
              *((_DWORD *)v24 + 2) = v44;
              if ( v33 )
              {
                for ( i = 0; i < v43; ++i )
                {
                  qmemcpy(v44, v33, *(_DWORD *)(a6 + 4));
                  v44 += *(_DWORD *)(a6 + 4);
                  v33 += v38;
                }
              }
              else
              {
                v44 += v43 * *(_DWORD *)(a6 + 4);
              }
              v26 = 0;
              *((_DWORD *)v24 + 3) = v35 + 655360;
              while ( v41 + v35 <= (unsigned int)sub_10000 )
              {
                ++v26;
                v35 += v41;
              }
              v27 = v24 + 9;
              v24[8] = v26;
              if ( v35 <= (unsigned int)sub_10000 )
              {
                v30 = (unsigned int)sub_10000 - v35;
                if ( (unsigned int)sub_10000 - v35 > *(_DWORD *)(a6 + 4) )
                  v30 = *(_DWORD *)(a6 + 4);
                *v27 = v30 >> 2;
                v27[1] = *(_WORD *)(a2 + 2 * v34);
                v31 = v27 + 2;
                *v31 = (*(_DWORD *)(a6 + 4) - v30) >> 2;
                v28 = v31 + 2;
                v29 = v43 - v26 - 1;
                ++v34;
              }
              else
              {
                *v27 = 0;
                v24[10] = *(_WORD *)(a2 + 2 * v34);
                v24[11] = 0;
                v28 = v24 + 13;
                v29 = v43 - v26;
                ++v34;
              }
              *(v28 - 1) = v29;
              v35 = (uint16_t)(v35 + v41 * (v43 - v26));
              v19 = sub_14B1C0(v28, v41, *(_DWORD *)(a6 + 4), v40, v43);
            }
            v39 -= 4 * *(_DWORD *)(a6 + 4);
          }
          else
          {
            v20 = v19 + 1;
            *(v20 - 1) = v42;
            v42 = 0;
            v21 = (_WORD *)(a2 + 2 * v34++);
            *v20 = *v21;
            v22 = sub_14B1C0(v20 + 1, v41, *(_DWORD *)(a6 + 4), v40, v43);
            HIWORD(v35) = 0;
            v19 = v22 + 2;
            *(_DWORD *)v22 = (uint16_t)v35 + 655360;
          }
        }
        v32 = v19 + 1;
        *(v32 - 1) = v42;
        *v32 = -1;
      }
      else
      {
        *(_DWORD *)v18 = v35 + a2;
        v18[2] = v8 >> 2;
        v18[3] = -1;
      }
    }
  }
}
// 14AFDC: conditional instruction was optimized away because %var_14.4 is in (==4|==8)
// 14B01A: variable 'v38' is possibly undefined
// 10000: using guessed type void __noreturn sub_10000();


//----- (0014B1C0) --------------------------------------------------------
_WORD *__fastcall sub_14B1C0(_WORD *a1, int a2, unsigned int a3, int a4, int a5)
{
  int16_t v5; // cx
  _WORD *result; // eax

  v5 = a2 * a4;
  *a1 = a2;
  a1[1] = a3 >> 2;
  a1[2] = v5 - 4;
  a1[3] = v5;
  result = a1 + 5;
  *(result - 1) = a5 * a2 - a3;
  return result;
}


//----- (0014B200) --------------------------------------------------------
void __stdcall sub_14B200(int a1)
{
  unsigned int v1; // ecx
  int v2; // edx
  int v3; // ebx
  unsigned int v4; // edi
  int v5; // eax

  if ( a1 )
  {
    if ( dword_189154 )
      ((void (*)(void))dword_1C3C34)();
    sub_14B3B0((_DWORD *)a1);
    v1 = *(_DWORD *)(a1 + 880) + 1;
    v2 = *(_DWORD *)(*(_DWORD *)(a1 + 952) + 4 * *(_DWORD *)(a1 + 880));
    v3 = *(_DWORD *)(a1 + 944);
    *(_DWORD *)(a1 + 880) = v1;
    v4 = *(_DWORD *)(a1 + 12);
    *(_DWORD *)(a1 + 944) = v2 + v3;
    if ( v1 < v4 && (*(_BYTE *)(a1 + 901) & 2) == 0 )
    {
      *(_DWORD *)(a1 + 944) = *(_DWORD *)(a1 + 940);
      sub_14CD50(a1, *(char **)(a1 + 940), *(_DWORD *)(*(_DWORD *)(a1 + 952) + 4 * *(_DWORD *)(a1 + 880)));
    }
    LOBYTE(v5) = sub_14C740(a1);
    if ( dword_189154 )
      dword_1C3C34(v5);
  }
}
// 14B296: variable 'v5' is possibly undefined
// 189154: using guessed type int dword_189154;
// 1C3C34: using guessed type int (__fastcall *dword_1C3C34)(_DWORD);


//----- (0014B2B0) --------------------------------------------------------
int __stdcall sub_14B2B0(_DWORD *a1, _DWORD *a2)
{
  int v2; // eax
  int v3; // ebx
  int v4; // eax
  int result; // eax

  v2 = sub_14B3B0(a2);
  *a1 = dword_18A5AC(v2) - a2[283];
  a1[1] = a2[256];
  a1[2] = a2[284];
  a1[3] = a2[286];
  a1[4] = a2[287];
  a1[5] = a2[288];
  a1[6] = a2[275] - a2[285];
  a1[8] = a2[277];
  a1[7] = a2[289];
  v3 = a2[275] + a2[277];
  if ( v3 )
    v4 = 1000 * (uint64_t)(unsigned int)(a2[276] + a2[274]) / (unsigned int)v3;
  else
    v4 = 0;
  a1[9] = v4;
  a1[10] = a2[290];
  a1[12] = a2[292] + 1;
  a1[11] = a2[291];
  a1[13] = a2[293] + 1;
  a1[14] = a2[294];
  a1[17] = a2[295];
  a1[18] = a2[272];
  a1[19] = a2[278];
  a1[15] = a2[297];
  result = a2[298] + 1;
  a1[16] = result;
  return result;
}
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);


//----- (0014B3B0) --------------------------------------------------------
int __fastcall sub_14B3B0(_DWORD *a1)
{
  int v2; // edx
  int result; // eax
  unsigned int v4; // ecx
  unsigned int v5; // edx
  int v6; // ebx
  int v7; // edx
  int v8; // ebp

  v2 = a1[280];
  result = -1;
  if ( v2 )
  {
    result = dword_18A5AC(-1);
    v4 = a1[290];
    v5 = result - a1[280];
    a1[280] = 0;
    if ( v5 <= v4 )
    {
      if ( v5 > a1[291] && a1[292] != a1[220] )
      {
        a1[291] = v5;
        a1[293] = a1[220];
      }
    }
    else
    {
      if ( a1[292] != a1[220] )
      {
        a1[291] = a1[290];
        a1[293] = a1[292];
        a1[292] = a1[220];
      }
      a1[290] = v5;
    }
  }
  if ( a1[282] )
  {
    if ( result == -1 )
      result = dword_18A5AC(-1);
    v6 = a1[288];
    v7 = result - a1[282];
    a1[282] = 0;
    a1[288] = v7 + v6;
  }
  if ( a1[281] )
  {
    if ( result == -1 )
      result = dword_18A5AC(-1);
    v8 = a1[289];
    result -= a1[281];
    a1[281] = 0;
    a1[289] = result + v8;
  }
  return result;
}
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);


//----- (0014B4D0) --------------------------------------------------------
int __fastcall sub_14B4D0(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  int v7; // edx
  void *v8; // eax
  unsigned int *v9; // [esp-Ch] [ebp-18h]
  int v10; // [esp-8h] [ebp-14h]
  int v11; // [esp-4h] [ebp-10h]
  uint8_t v12; // [esp+0h] [ebp-Ch]

  if ( !a5 )
    return 0;
  v6 = dword_18A5AC(a1);
  *(_DWORD *)(a5 + 1124) = v6;
  v7 = *(_DWORD *)(a5 + 1132);
  *(_DWORD *)(a5 + 1120) = v6;
  if ( !v7 )
    *(_DWORD *)(a5 + 1132) = v6;
  if ( *(_DWORD *)(a5 + 104) )
    *(_DWORD *)(a5 + 948) = *(_DWORD *)(a5 + 880);
  ++*(_DWORD *)(a5 + 1144);
  v8 = sub_14B620((_DWORD *)a5);
  if ( (*(_BYTE *)(a5 + 901) & 4) == 0 && *(_DWORD *)(a5 + 1024) )
    LOBYTE(v8) = sub_14B5B0((_DWORD *)a5);
  else
    LOBYTE(v8) = 0;
  v12 = (uint8_t)v8;
  if ( *(_DWORD *)(a5 + 928) )
  {
    if ( (_BYTE)v8 )
    {
      ++*(_DWORD *)(a5 + 1148);
    }
    else
    {
      v11 = *(_DWORD *)(a5 + 928);
      v10 = *(_DWORD *)(a5 + 924);
      v9 = *(unsigned int **)(a5 + 992);
      *(_DWORD *)(a5 + 996) = 1;
      v8 = sub_167320(v9, v10, v11);
    }
  }
  if ( dword_189154 )
    dword_1C3C34(v8);
  return v12;
}
// 14B592: variable 'v8' is possibly undefined
// 189154: using guessed type int dword_189154;
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);
// 1C3C34: using guessed type int (__fastcall *dword_1C3C34)(_DWORD);


//----- (0014B5B0) --------------------------------------------------------
char __fastcall sub_14B5B0(_DWORD *a1)
{
  int v2; // edx
  char result; // al

  v2 = a1[264];
  if ( v2 == -1 || a1[266] )
    return 0;
  if ( !a1[265] )
    return 1;
  if ( *(_DWORD *)(a1[v2 + 257] + 68)
    || (unsigned int)dword_1C3C38(a1[v2 + 257]) < *(_DWORD *)(a1[a1[264] + 257] + 36) >> 7 )
  {
    return 0;
  }
  result = 1;
  a1[265] = 0;
  return result;
}
// 1C3C38: using guessed type int (__stdcall *dword_1C3C38)(_DWORD);


//----- (0014B620) --------------------------------------------------------
_DWORD *__fastcall sub_14B620(_DWORD *result)
{
  int v1; // ebp
  int v2; // eax
  uint8_t v3; // dl
  int v4; // eax
  char *v5; // eax
  _DWORD *v6; // esi
  int v7; // eax
  bool v8; // edx
  int v9; // eax
  int *v10; // ebp
  unsigned int v11; // ecx
  char *v12; // edi
  unsigned int v13; // ebx
  char *v14; // edx
  int v15; // eax
  unsigned int v16; // ecx
  char *v17; // esi
  int v18; // edi
  int v19; // edx
  unsigned int v20; // edx
  unsigned int v21; // ebx
  int v22; // eax
  uint8_t i; // dl
  char *v24; // eax
  int v25; // eax
  unsigned int v26; // ebx
  int v27; // [esp+0h] [ebp-2Ch]
  _DWORD *v28; // [esp+4h] [ebp-28h]
  _DWORD *v29; // [esp+8h] [ebp-24h]
  int v30; // [esp+Ch] [ebp-20h]
  uint8_t v31; // [esp+10h] [ebp-1Ch]

  v29 = result;
  if ( result[264] != -1 && !result[266] )
  {
    if ( result[256] )
      result[265] = 1;
    v28 = (_DWORD *)result[result[264] + 257];
    v1 = v28[9];
    v2 = v28[7];
    v28[8] += v2;
    v28[9] = v2 + v1;
    v3 = 0;
    v27 = v29[225];
    v4 = 0x2000;
    do
    {
      if ( (v27 & v4) != 0 )
      {
        v27 &= ~v4;
        goto LABEL_10;
      }
      ++v3;
      v4 *= 2;
    }
    while ( v3 < 7u );
    v3 = -1;
LABEL_10:
    v5 = (char *)&v29[v3];
    v6 = (_DWORD *)*((_DWORD *)v5 + 241);
    v31 = v3;
    if ( v6 )
    {
      if ( v5[75] >= 0 )
        v7 = *v6 - 4;
      else
        v7 = v6[1];
    }
    else
    {
      v7 = 0;
    }
    v30 = v7;
    v8 = v7 == 0;
    v9 = v29[v31 + 257];
    *(_DWORD *)(v9 + 68) = v8;
    if ( !v8 )
    {
      if ( dword_189154 )
        dword_1C3C34(v9);
      while ( 1 )
      {
        v10 = (int *)v29[v31 + 257];
        v11 = v10[6];
        if ( v30 + v10[4] > v11 )
        {
          v30 = v11 - v10[4];
          ++v10[11];
        }
        if ( v29[v31 + 18] >= 0 )
        {
          v12 = (char *)v10[3];
          v13 = v10[1];
          v14 = (char *)(v6 + 1);
          if ( (unsigned int)&v12[v30] <= v13 )
          {
            v16 = v30;
            v17 = (char *)(v6 + 1);
          }
          else
          {
            qmemcpy(v12, v14, v13 - (_DWORD)v12);
            v15 = v10[1] - v10[3];
            v16 = v30 - v15;
            v12 = (char *)*v10;
            v17 = &v14[4 * v15];
          }
          qmemcpy(v12, v17, v16);
        }
        else
        {
          sub_1676F0(v6 + 2, v30, dword_189158, *v10, v10[1], v10[3]);
        }
        v18 = v10[4];
        v10[10] += v30;
        v19 = v10[3];
        v10[4] = v30 + v18;
        v20 = v30 + v19;
        v21 = v10[1];
        v10[3] = v20;
        if ( v20 >= v21 )
          v10[3] = v20 - v21 + *v10;
        v22 = 0x2000;
        for ( i = 0; i < 7u; ++i )
        {
          if ( (v27 & v22) != 0 )
          {
            v27 &= ~v22;
            goto LABEL_33;
          }
          v22 *= 2;
        }
        i = -1;
LABEL_33:
        v31 = i;
        if ( i == 0xFF )
          break;
        v24 = (char *)&v29[i];
        v6 = (_DWORD *)*((_DWORD *)v24 + 241);
        if ( v6 )
        {
          if ( v24[75] >= 0 )
            v25 = *v6 - 4;
          else
            v25 = v6[1];
        }
        else
        {
          v25 = 0;
        }
        v30 = v25;
      }
    }
    v26 = v28[10];
    result = (_DWORD *)(v28[8] >> 7);
    if ( (unsigned int)result > v26 )
    {
      result = (_DWORD *)(v26 << 7);
      v28[8] = v26 << 7;
    }
  }
  return result;
}
// 189154: using guessed type int dword_189154;
// 189158: using guessed type int dword_189158;
// 1C3C34: using guessed type int (__fastcall *dword_1C3C34)(_DWORD);


//----- (0014B8B0) --------------------------------------------------------
void __stdcall sub_14B8B0(int a1)
{
  int v1; // esi
  int v2; // ecx
  int v3; // eax
  int v4; // esi
  int v5; // eax

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 1056) != -1 )
    {
      v1 = a1;
      do
      {
        if ( *(_DWORD *)(v1 + 1028) )
        {
          dword_1C3C3C(*(_DWORD *)(v1 + 1028));
          sub_132614(**(_DWORD **)(v1 + 1028));
          sub_132614(*(_DWORD *)(v1 + 1028));
          v2 = dword_189154 - 1;
          *(_DWORD *)(v1 + 1028) = 0;
          dword_189154 = v2;
        }
        v1 += 4;
      }
      while ( v1 != a1 + 28 );
      *(_DWORD *)(a1 + 1056) = -1;
    }
    if ( !dword_189154 && dword_189158 )
    {
      sub_132614(dword_189158);
      dword_189158 = 0;
    }
    if ( *(_DWORD *)(a1 + 916) != -1 && (*(_BYTE *)(a1 + 901) & 0x10) == 0 )
      sub_15C971();
    if ( *(_DWORD *)(a1 + 928) )
      sub_132614(*(_DWORD *)(a1 + 928));
    if ( *(_DWORD *)(a1 + 924) )
      sub_132614(*(_DWORD *)(a1 + 924));
    if ( *(_DWORD *)(a1 + 956) )
      sub_132614(*(_DWORD *)(a1 + 956));
    if ( *(_DWORD *)(a1 + 940) )
      sub_132614(*(_DWORD *)(a1 + 940));
    v3 = *(_DWORD *)(a1 + 1068);
    if ( v3 )
      v3 = sub_132614(*(_DWORD *)(a1 + 1068));
    LOWORD(v3) = 0;
    v4 = *(_DWORD *)(a1 + 900) & 0x2000000;
    v5 = v3 << 16;
    LOWORD(v5) = 0;
    memset32((void *)a1, v5, 0x12Bu);
    if ( !v4 )
      v5 = sub_132614(a1);
    dword_1C9830(v5);
  }
}
// 1C3C3C: invalid function type '?' has been ignored
// 189154: using guessed type int dword_189154;
// 189158: using guessed type int dword_189158;
// 1C3C3C: using guessed type int (__stdcall *dword_1C3C3C)(_DWORD);
// 1C9830: using guessed type int (__fastcall *dword_1C9830)(_DWORD);


//----- (0014BA00) --------------------------------------------------------
int __stdcall sub_14BA00(int a1, unsigned int a2)
{
  void **v3; // esi
  int v4; // eax
  unsigned int v5; // ebp
  char *v6; // edx
  unsigned int v7; // ecx
  unsigned int v8; // ebp
  unsigned int v9; // edi
  unsigned int v10; // ebp
  char v11; // al
  char *v12; // edi
  unsigned int v13; // ebx
  char *v14; // eax
  unsigned int v15; // ecx
  int16_t v16; // bx
  int v17; // eax
  int v18; // eax
  int v19; // edi
  unsigned int v20; // ecx
  char *v21; // edi
  int16_t v22; // bx
  int16_t v23; // bx
  int v24; // eax
  unsigned int v25; // ecx
  unsigned int v26; // edi
  int *v27; // esi
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  char v31; // [esp+8h] [ebp-14h]
  unsigned int v32; // [esp+Ch] [ebp-10h]

  if ( !a2 )
    return 0;
  if ( !a1 )
  {
    if ( !*(_DWORD *)(a2 + 1064) )
    {
      v26 = a2;
      *(_DWORD *)(a2 + 1064) = 1;
      do
      {
        if ( *(_DWORD *)(v26 + 1028) )
        {
          if ( dword_189168 )
            dword_189168(*(_DWORD *)(v26 + 1028));
          v27 = *(int **)(v26 + 1028);
          v28 = *v27;
          v27[3] = *v27;
          v27[2] = v28;
          v29 = v27[4];
          v30 = v27[10];
          v27[4] = 0;
          v27[10] = v30 - v29;
        }
        v26 += 4;
      }
      while ( v26 != a2 + 28 );
    }
    return 1;
  }
  if ( !*(_DWORD *)(a2 + 1064) )
    return 1;
  v32 = a2;
  *(_DWORD *)(a2 + 1064) = 0;
  do
  {
    if ( *(_DWORD *)(v32 + 1028) )
    {
      v3 = *(void ***)(v32 + 1028);
      if ( dword_18916C && !(uint8_t)dword_18916C(*(_DWORD *)(v32 + 1028)) )
        return 0;
      v4 = dword_1C3C38(v3);
      v5 = (unsigned int)v3[10] - v4;
      v3[9] = (void *)((_BYTE *)v3[9] - (_BYTE *)v3[8]);
      v4 <<= 7;
      v6 = (char *)v3[9];
      v3[8] = (void *)v4;
      v3[9] = &v6[v4];
      if ( *(_DWORD *)(a2 + 880) )
      {
        v7 = (unsigned int)v3[12];
        if ( v5 < v7 )
        {
          v8 = v7 - v5;
          v9 = (unsigned int)v3[6];
          if ( (unsigned int)v3[4] + v8 > v9 )
            v8 = v9 - (_DWORD)v3[4];
          v10 = v8 & 0xFFFFFFFC;
          if ( v3[18] )
            v11 = 0;
          else
            v11 = 0x80;
          v31 = v11;
          v12 = (char *)v3[3];
          v13 = (unsigned int)v3[1];
          v14 = &v12[v10];
          LOBYTE(v14) = v31;
          if ( (unsigned int)&v12[v10] < v13 )
          {
            BYTE1(v14) = v31;
            v23 = (int16_t)v14;
            v24 = (_DWORD)v14 << 16;
            LOWORD(v24) = v23;
            memset32(v12, v24, v10 >> 2);
            memset(&v12[4 * (v10 >> 2)], v23, v10 & 3);
            v3[3] = (char *)v3[3] + v10;
          }
          else
          {
            v15 = v13 - (_DWORD)v12;
            BYTE1(v14) = v31;
            v16 = (int16_t)v14;
            v17 = (_DWORD)v14 << 16;
            LOWORD(v17) = v16;
            LOBYTE(v16) = v15;
            v15 >>= 2;
            memset32(v12, v17, v15);
            memset(&v12[4 * v15], v17, v16 & 3);
            v18 = (int)v3[3];
            v19 = (int)v3[1] - v18;
            LOBYTE(v18) = v31;
            v20 = v10 - v19;
            v21 = (char *)*v3;
            BYTE1(v18) = v31;
            v22 = v18;
            v18 <<= 16;
            LOWORD(v18) = v22;
            LOBYTE(v22) = v20;
            v20 >>= 2;
            memset32(*v3, v18, v20);
            memset(&v21[4 * v20], v18, v22 & 3);
            v3[3] = (char *)*v3 + v10 - ((_BYTE *)v3[3] - (_BYTE *)v3[1]);
          }
          v25 = (unsigned int)v3[10] + v10;
          v3[4] = (char *)v3[4] + v10;
          v3[10] = (void *)v25;
        }
      }
    }
    v32 += 4;
  }
  while ( v32 < a2 + 28 );
  return 1;
}
// 189168: using guessed type int (__stdcall *dword_189168)(_DWORD);
// 18916C: using guessed type int (__stdcall *dword_18916C)(_DWORD);
// 1C3C38: using guessed type int (__stdcall *dword_1C3C38)(_DWORD);


//----- (0014BC30) --------------------------------------------------------
int __stdcall sub_14BC30(int a1)
{
  int result; // eax

  result = a1;
  dword_18915C = a1;
  return result;
}
// 18915C: using guessed type int dword_18915C;


//----- (0014BC40) --------------------------------------------------------
_DWORD *__stdcall sub_14BC40(unsigned int a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // esi
  unsigned int v4; // ebp
  int v6; // eax
  _DWORD *v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // ebx
  int v17; // edx
  char *v18; // edx
  int v19; // eax
  unsigned int v20; // edi
  unsigned int v21; // ecx
  int v22; // eax
  unsigned int v23; // edx
  unsigned int v24; // ecx
  unsigned int v25; // edi
  int v26; // eax
  int v27; // edi
  int v28; // ebx
  int v29; // ecx
  int v30; // edx
  int v31; // eax
  unsigned int v32; // ecx
  unsigned int *v33; // eax
  unsigned int v34; // ebx
  int v35; // edx
  unsigned int v36; // edx
  unsigned int i; // ebx
  unsigned int *v38; // eax
  int v39; // edx
  unsigned int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // edi
  unsigned int v43; // ecx
  int v44; // eax
  unsigned int v45; // ecx
  unsigned int v46; // ebx
  int v47; // edx
  int v48; // eax
  int v49; // eax
  uint8_t j; // dl
  int v51; // eax
  void *v52; // eax
  int v53; // eax
  unsigned int v54; // eax
  int v55; // eax
  int v56; // ebx
  int v57; // ecx
  int v58; // eax
  int v59; // ebx
  int v60; // eax
  int v61; // ecx
  int v62; // eax
  unsigned int v63; // [esp+0h] [ebp-2Ch] BYREF
  unsigned int v64; // [esp+4h] [ebp-28h]
  int v65; // [esp+8h] [ebp-24h]
  unsigned int v66; // [esp+Ch] [ebp-20h]
  unsigned int v67; // [esp+10h] [ebp-1Ch]
  unsigned int v68; // [esp+14h] [ebp-18h]
  unsigned int v69; // [esp+18h] [ebp-14h]
  unsigned int *v70; // [esp+1Ch] [ebp-10h]
  unsigned int v71; // [esp+30h] [ebp+4h]

  v3 = a3;
  v4 = 0;
  v64 = 0;
  if ( !a3 )
    return 0;
  LOBYTE(v6) = off_18A5B8();
  v65 = dword_18A5AC(v6);
  if ( (a2 & 0x1000) != 0 )
  {
    if ( (a2 & 0x2000000) != 0 )
      v7 = (_DWORD *)*a3;
    else
      v7 = a3;
    v66 = (unsigned int)v7;
    sub_15C965();
    v63 = v8;
  }
  else
  {
    v8 = sub_15C850(0, (int)a3, __DS__, 0);
    v66 = v8;
    v63 = 0;
  }
  if ( v66 == -1 )
    goto LABEL_12;
  if ( (a2 & 0x2000000) == 0 )
  {
    v8 = sub_13259F(1196);
    v3 = (_DWORD *)v8;
    if ( !v8 )
      goto LABEL_12;
  }
  LOWORD(v8) = 0;
  v9 = v8 << 16;
  LOWORD(v9) = 0;
  memset32(v3, v9, 0x12Bu);
  v10 = v66;
  v3[279] = 1196;
  v3[229] = v10;
  v3[234] = v63;
  if ( (a2 & 0x800) != 0 )
    v3[296] = dword_18915C;
  v63 = 0;
  *v3 = 0;
  v8 = sub_14CD50((int)v3, (char *)v3, 0x68u);
  if ( *v3 == 843795795 )
  {
    if ( (a2 & 0x80u) != 0 )
      v3[4] = dword_189160;
    v12 = v3[4];
    if ( v12 >= 0 )
      v13 = 100 * v12;
    else
      v13 = -v12;
    v3[256] = v13;
    if ( v13 )
      v14 = (unsigned int)&loc_186A0 / v3[256];
    else
      v14 = (unsigned int)&loc_186A0;
    v69 = v14;
    if ( !v14 )
      v69 = 1;
    v63 = (v3[5] & 1) + v3[3];
    v15 = v3[295];
    v16 = 5 * v63 + 4 + v3[279];
    v17 = 5 * v63 + 4;
    v3[279] = v16;
    if ( v16 > v15 )
      v3[295] = v16;
    v8 = sub_13259F(v17);
    v3[239] = v8;
    if ( v8 )
    {
      v18 = (char *)(v8 + v63);
      v3[238] = v8 + v63;
      sub_14CD50((int)v3, v18, 4 * v63);
      sub_14CD50((int)v3, (char *)v3[239], v63);
      v3[234] += 5 * v63;
      v19 = v3[17] + v3[16] + v3[15] + v3[14] + sub_164690();
      v20 = v3[295];
      v21 = v19 + v3[279];
      v3[279] = v21;
      if ( v21 > v20 )
        v3[295] = v21;
      v22 = sub_13259F(v19);
      v3[231] = v22;
      if ( !v22 )
      {
        v8 = sub_132614(v3[239]);
        goto LABEL_16;
      }
      v23 = v3[13] + 4099;
      LOBYTE(v23) = v23 & 0xFC;
      if ( v23 < 0x2000 )
        v23 = 0x2000;
      v24 = v23 + v3[279];
      v25 = v3[295];
      v3[279] = v24;
      if ( v24 > v25 )
        v3[295] = v24;
      v26 = sub_13259F(v23);
      v27 = v26;
      if ( !v26 )
      {
LABEL_42:
        sub_132614(v3[231]);
        v8 = sub_132614(v3[239]);
        goto LABEL_16;
      }
      sub_14CD50((int)v3, (char *)(v26 + 4096), v3[13]);
      sub_1646A0(v27, v3[231], v3[14], v3[15], v3[16], v3[17]);
      sub_132614(v27);
      v28 = v3[13];
      v29 = v3[234];
      v3[279] -= v28 + 4096;
      v30 = v3[3] - 1;
      v31 = v3[5] & 1;
      v3[234] = v28 + 104 + v29;
      v63 = v31 + v30;
      v32 = 0;
      v33 = (unsigned int *)v3[238];
      if ( v63 >= v69 )
      {
        v36 = 0;
        for ( i = 0; i < v69; ++v33 )
        {
          ++i;
          v36 += *v33;
        }
        v38 = (unsigned int *)v3[238];
        v67 = v63 - v69;
        v34 = 0;
        v70 = &v38[v69];
        do
        {
          if ( v36 > v32 && v34 )
          {
            v32 = v36;
            v68 = v34;
          }
          v36 = *v70 + v36 - *v38;
          if ( *v38 > v64 )
            v64 = *v38;
          v4 += *v38;
          ++v34;
          ++v70;
          ++v38;
        }
        while ( v34 <= v67 );
        while ( v34 <= v63 )
        {
          if ( *v38 > v64 )
            v64 = *v38;
          v39 = *v38++;
          ++v34;
          v4 += v39;
        }
      }
      else
      {
        v68 = 0;
        v34 = 0;
        do
        {
          v32 += *v33;
          if ( *v33 > v64 )
            v64 = *v33;
          v35 = *v33++;
          ++v34;
          v4 += v35;
        }
        while ( v34 <= v63 );
      }
      v3[298] = v68;
      v3[297] = v32;
      v3[294] = v4 / v34;
      if ( (a2 & 0x200) != 0 )
      {
        v3[230] = v4;
      }
      else
      {
        if ( a1 == -1 )
        {
          if ( v3[256] )
            v40 = v3[297];
          else
            v40 = 12288;
          a1 = v40;
          if ( v40 > v4 >> 2 )
            a1 = v4 >> 2;
          if ( a1 < 0x3000 )
            a1 = 12288;
        }
        v71 = (a1 + 4095) >> 12 << 12;
        if ( v71 < 0x2000 )
          v71 = 0x2000;
        if ( 4 * v4 / 5 > v71 )
        {
          v41 = v64;
          v3[272] = v71;
          v3[230] = v41;
          v42 = v3[295];
          v43 = v71 + 4096 + v3[279];
          v3[279] = v43;
          if ( v43 > v42 )
            v3[295] = v43;
          v44 = sub_13259F(v71 + 4096);
          v3[267] = v44;
          v3[269] = v44;
          v3[270] = v44;
          if ( !v44 )
            goto LABEL_42;
          v3[268] = v3[272] + v44;
        }
        else
        {
          BYTE1(a2) |= 2u;
          v3[230] = v4;
        }
      }
      v45 = v3[295];
      v46 = v3[230] + 8 + v3[279];
      v47 = v3[230] + 8;
      v3[279] = v46;
      if ( v46 > v45 )
        v3[295] = v46;
      v48 = sub_13259F(v47);
      v3[235] = v48;
      if ( !v48 )
      {
        if ( v3[267] )
          sub_132614(v3[267]);
        goto LABEL_42;
      }
      v3[273] = v3[234];
      if ( (a2 & 0x200) != 0 )
      {
        sub_14CD50((int)v3, (char *)v3[235], v4);
        if ( (a2 & 0x1000) == 0 )
          sub_15C971();
        v3[229] = -1;
        v3[236] = v3[235];
      }
      else
      {
        v63 = v3[234] & 0xFFF;
        if ( v63 )
        {
          sub_15C8A9(__DS__, v3[229], v3[267], __DS__, 4096 - v63, &v63);
          v3[270] = v3[267] + v63;
          v3[271] = v63;
        }
        if ( (*((_BYTE *)v3 + 901) & 2) == 0 )
        {
          v3[236] = v3[235];
          sub_14CD50((int)v3, (char *)v3[235], *(_DWORD *)(v3[238] + 4 * v3[220]));
        }
      }
      v3[237] = -1;
      sub_14C740((int)v3);
      v3[264] = -1;
      v3[225] = a2 & 0xFFC01FFF;
      while ( (a2 & 0xFE000) != 0 )
      {
        v49 = 0x2000;
        for ( j = 0; j < 7u; ++j )
        {
          if ( (a2 & v49) != 0 )
          {
            a2 &= ~v49;
            goto LABEL_101;
          }
          v49 *= 2;
        }
        j = -1;
LABEL_101:
        v63 = j;
        v51 = sub_14D110((int)v3, 116);
        v3[v63 + 257] = v51;
        if ( v3[v63 + 257] )
        {
          if ( sub_14C4C0(v3, v63) )
          {
            v3[225] |= 1 << (v63 + 13);
          }
          else
          {
            sub_132614(v3[v63 + 257]);
            v3[279] -= 116;
            v3[v63 + 257] = 0;
          }
        }
      }
      v3[255] = -1;
      if ( (a2 & 0x100) != 0 )
      {
        while ( sub_14D000(v3) )
          ;
      }
      v52 = (void *)(a2 & 0x300000);
      if ( (a2 & 0x300000u) < 0x200000 )
      {
        if ( v52 != &loc_100000 )
          goto LABEL_118;
        v53 = v3[5];
        LOBYTE(v53) = v53 & 0xF9 | 2;
      }
      else
      {
        if ( (a2 & 0x300000u) > 0x200000 )
        {
          if ( v52 == (void *)3145728 )
            *((_BYTE *)v3 + 20) &= 0xF9u;
          goto LABEL_118;
        }
        v53 = v3[5];
        LOBYTE(v53) = v53 & 0xF9 | 4;
      }
      v3[5] = v53;
LABEL_118:
      v54 = v3[5] & 6;
      if ( v54 >= 2 )
      {
        if ( v54 <= 2 )
        {
          *((_BYTE *)v3 + 902) |= 0x10u;
        }
        else if ( v54 == 4 )
        {
          *((_BYTE *)v3 + 902) |= 0x20u;
        }
      }
      if ( (*((_BYTE *)v3 + 902) & 0x30) != 0 )
      {
        v54 = 2 * v3[2];
        v3[2] = v54;
      }
      v55 = dword_18A5AC(v54);
      v3[284] = v55 - v65;
      v56 = v3[275];
      v57 = v3[274];
      v58 = v3[277];
      v3[277] = 0;
      v59 = v58 + v56;
      v60 = v3[276];
      v3[275] = v59;
      v61 = v60 + v57;
      v62 = v3[275];
      v3[274] = v61;
      v3[285] = v62;
      return v3;
    }
  }
LABEL_16:
  if ( (a2 & 0x1000) == 0 )
    v8 = sub_15C971();
  if ( (a2 & 0x2000000) != 0 )
  {
LABEL_12:
    dword_1C9830(v8);
    return 0;
  }
  v11 = sub_132614((int)v3);
  dword_1C9830(v11);
  return 0;
}
// 1C9830: invalid function type '?' has been ignored
// 14C13C: conditional instruction was optimized away because edx.4>=2000u
// 14BC63: variable 'v6' is possibly undefined
// 14BC90: variable 'v8' is possibly undefined
// 18915C: using guessed type int dword_18915C;
// 189160: using guessed type int dword_189160;
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);
// 18A5B8: using guessed type char (*off_18A5B8)();
// 1C9830: using guessed type int (__fastcall *dword_1C9830)(_DWORD);


//----- (0014C490) --------------------------------------------------------
char __fastcall sub_14C490(_DWORD *a1)
{
  int v2; // edx
  char result; // al

  v2 = 0x2000;
  for ( result = 0; (uint8_t)result < 7u; ++result )
  {
    if ( (*a1 & v2) != 0 )
    {
      *a1 &= ~v2;
      return result;
    }
    v2 *= 2;
  }
  return -1;
}


//----- (0014C4C0) --------------------------------------------------------
char __fastcall sub_14C4C0(_DWORD *a1, unsigned int a2)
{
  char result; // al
  _DWORD *v4; // eax
  _BOOL1 v5; // zf
  int v6; // eax
  _DWORD *v7; // edi
  int v8; // edx
  int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // eax
  _DWORD *v16; // edi
  int v17; // eax
  _DWORD *v18; // eax
  int v19; // [esp+0h] [ebp-28h]
  int v20; // [esp+4h] [ebp-24h]
  _BOOL1 v21; // [esp+8h] [ebp-20h]
  _BOOL1 v22; // [esp+Ch] [ebp-1Ch]

  if ( !dword_189164 )
    return 0;
  v4 = &a1[a2];
  if ( (v4[18] & 0x40000000) != 0 )
  {
    v6 = v4[18] & 0xFFFFFF;
    v5 = v6 == 0;
  }
  else
  {
    v6 = 0;
    v5 = 1;
  }
  v19 = v6;
  if ( v5 )
    return 0;
  v7 = &a1[a2];
  v22 = (v7[18] & 0x10000000) != 0;
  v21 = (v7[18] & 0x20000000) != 0;
  v8 = v6 * (v21 + 1);
  v9 = v22 + 1;
  v20 = v9 * v8;
  if ( !dword_189158 )
  {
    v10 = a1[279] + 0x2000;
    v11 = a1[295];
    a1[279] = v10;
    if ( v10 > v11 )
      a1[295] = v10;
    v9 = sub_13259F(0x2000);
    dword_189158 = v9;
    if ( !v9 )
      return 0;
  }
  LOWORD(v9) = 0;
  v12 = v9 << 16;
  LOWORD(v12) = 0;
  memset32((void *)a1[a2 + 257], v12, 0x1Du);
  *(_DWORD *)(a1[a2 + 257] + 28) = (unsigned int)(a1[256] << 7)
                                 * (uint64_t)(unsigned int)v20
                                 / (unsigned int)&loc_186A0;
  *(_DWORD *)(a1[a2 + 257] + 36) = v20 << 6;
  v13 = a1[a2 + 257];
  v14 = v20 + (*(_DWORD *)(v13 + 28) >> 6) + 4095;
  LOWORD(v14) = v14 & 0xF000;
  *(_DWORD *)(v13 + 24) = v14;
  v15 = a1[a2 + 257];
  if ( *(_DWORD *)(v15 + 24) < 0x2000u )
    *(_DWORD *)(v15 + 24) = 0x2000;
  v16 = &a1[a2];
  v17 = sub_14D110((int)a1, *(_DWORD *)(v16[257] + 24));
  *(_DWORD *)(v16[257] + 8) = v17;
  *(_DWORD *)(v16[257] + 12) = v17;
  *(_DWORD *)v16[257] = v17;
  *(_DWORD *)(v16[257] + 4) = *(_DWORD *)(v16[257] + 24) + v17;
  v18 = (_DWORD *)v16[257];
  if ( !*v18 )
    return 0;
  v18[5] = v20;
  *(_DWORD *)(v16[257] + 64) = v19;
  *(_DWORD *)(v16[257] + 72) = v21;
  *(_DWORD *)(v16[257] + 76) = v22;
  if ( (uint8_t)dword_189164(a1[225], v16[257]) )
  {
    *(_DWORD *)(v16[257] + 48) = v16[6] - (*(_DWORD *)(v16[257] + 28) >> 7);
    if ( a1[264] == -1 )
      a1[264] = a2;
    result = 1;
    ++dword_189154;
  }
  else
  {
    sub_132614(*(_DWORD *)v16[257]);
    result = 0;
    a1[279] -= *(_DWORD *)(v16[257] + 24);
  }
  return result;
}
// 189164: invalid function type '?' has been ignored
// 189154: using guessed type int dword_189154;
// 189158: using guessed type int dword_189158;
// 189164: using guessed type int (__stdcall *dword_189164)(_DWORD, _DWORD);


//----- (0014C740) --------------------------------------------------------
char __fastcall sub_14C740(int a1)
{
  int v1; // edx
  int v2; // ebx
  int v3; // ebx
  _DWORD *v4; // edx
  char result; // al
  _DWORD *v6; // esi
  _DWORD *v7; // esi
  _DWORD *v8; // esi
  _DWORD *v9; // esi
  _DWORD *v10; // esi
  _DWORD *v11; // esi
  _DWORD *v12; // esi
  int v13; // ebx
  int v14; // edx
  char *v15; // ebp
  char *v16; // edx
  char v17; // bh
  uint8_t v18; // al
  char *v19; // esi
  unsigned int v20; // ecx
  char *v21; // edi
  char *v22; // esi
  unsigned int v23; // ecx
  char *v24; // esi
  void *v25; // esi
  int v26; // esi
  int v27; // ecx
  _BYTE v28[768]; // [esp+0h] [ebp-330h] BYREF
  int v29; // [esp+300h] [ebp-30h]
  _BYTE *v30; // [esp+304h] [ebp-2Ch]
  unsigned int v31; // [esp+308h] [ebp-28h]
  int v32; // [esp+30Ch] [ebp-24h]
  uint8_t v33; // [esp+310h] [ebp-20h]
  uint8_t v34; // [esp+314h] [ebp-1Ch]

  v29 = a1;
  v1 = *(_DWORD *)(a1 + 880) - *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 1016) = 0;
  if ( v1 < 0 )
    goto LABEL_9;
  if ( (*(_BYTE *)(a1 + 20) & 1) == 0 )
  {
    *(_DWORD *)(v29 + 880) = 0;
    goto LABEL_8;
  }
  if ( v1 )
  {
    *(_DWORD *)(v29 + 880) = 1;
LABEL_8:
    sub_14CAA0(v29);
    goto LABEL_9;
  }
  if ( (*(_BYTE *)(v29 + 901) & 2) == 0 )
  {
    v2 = v29;
    *(_DWORD *)(v29 + 944) = *(_DWORD *)(v29 + 940);
    sub_14CD50(v29, *(char **)(v29 + 940), *(_DWORD *)(*(_DWORD *)(v2 + 952) + 4 * *(_DWORD *)(v2 + 880)));
  }
LABEL_9:
  v3 = v29;
  v4 = *(_DWORD **)(v29 + 944);
  *(_DWORD *)(v29 + 960) = v4;
  result = *(_BYTE *)(*(_DWORD *)(v29 + 880) + *(_DWORD *)(v3 + 956));
  if ( (result & 1) != 0 )
    v4 += *(uint8_t *)v4;
  if ( (result & 2) != 0 )
    v6 = v4;
  else
    v6 = 0;
  *(_DWORD *)(v29 + 964) = v6;
  if ( v6 )
    v4 = (_DWORD *)((char *)v4 + *v4);
  if ( (result & 4) != 0 )
    v7 = v4;
  else
    v7 = 0;
  *(_DWORD *)(v29 + 968) = v7;
  if ( v7 )
    v4 = (_DWORD *)((char *)v4 + *v4);
  if ( (result & 8) != 0 )
    v8 = v4;
  else
    v8 = 0;
  *(_DWORD *)(v29 + 972) = v8;
  if ( v8 )
    v4 = (_DWORD *)((char *)v4 + *v4);
  if ( (result & 0x10) != 0 )
    v9 = v4;
  else
    v9 = 0;
  *(_DWORD *)(v29 + 976) = v9;
  if ( v9 )
    v4 = (_DWORD *)((char *)v4 + *v4);
  if ( (result & 0x20) != 0 )
    v10 = v4;
  else
    v10 = 0;
  *(_DWORD *)(v29 + 980) = v10;
  if ( v10 )
    v4 = (_DWORD *)((char *)v4 + *v4);
  if ( (result & 0x40) != 0 )
    v11 = v4;
  else
    v11 = 0;
  *(_DWORD *)(v29 + 984) = v11;
  if ( v11 )
    v4 = (_DWORD *)((char *)v4 + *v4);
  if ( result >= 0 )
    v12 = 0;
  else
    v12 = v4;
  *(_DWORD *)(v29 + 988) = v12;
  if ( v12 )
    v4 = (_DWORD *)((char *)v4 + *v4);
  v13 = v29;
  *(_DWORD *)(v29 + 992) = v4;
  if ( (result & 1) == 0 )
    goto LABEL_56;
  v14 = *(_DWORD *)(v13 + 944);
  v15 = (char *)(v29 + 108);
  v32 = 0;
  qmemcpy(v28, (void *)(v29 + 108), sizeof(v28));
  v16 = (char *)(v14 + 1);
  v30 = v28;
  do
  {
    v17 = *v16;
    if ( *v16 >= 0 )
    {
      if ( (v17 & 0x40) != 0 )
      {
        result = (v17 & 0x3F) + 1;
        v31 = 3 * (uint8_t)result;
        v25 = &v30[3 * (uint8_t)v16[1]];
        v33 = result;
        qmemcpy(v15, v25, v31);
        HIWORD(v25) = HIWORD(v31);
        v15 += v31;
        LOWORD(v25) = v33;
        v16 += 2;
        v32 += (int)v25;
      }
      else
      {
        v15 += 3;
        v26 = *(_DWORD *)v16;
        v16 += 3;
        v27 = v32 + 1;
        *(_DWORD *)(v15 - 3) = v26;
        v32 = v27;
      }
    }
    else
    {
      v18 = (v17 & 0x7F) + 1;
      v31 = 3 * v18;
      v19 = &v30[3 * (uint16_t)v32];
      v34 = v18;
      v20 = v31 >> 2;
      qmemcpy(v15, v19, 4 * (v31 >> 2));
      v22 = &v19[4 * v20];
      v21 = &v15[4 * v20];
      v23 = (3 * v18) & 3;
      qmemcpy(v21, v22, v23);
      v24 = &v22[v23];
      LOWORD(v24) = v34;
      v15 += v31;
      result = v34 + v32;
      ++v16;
      v32 += (int)v24;
    }
  }
  while ( (uint16_t)v32 < 0x100u );
  if ( *(_DWORD *)(v29 + 948) == *(_DWORD *)(v29 + 880) )
LABEL_56:
    *(_DWORD *)(v29 + 104) = 0;
  else
    *(_DWORD *)(v29 + 104) = 1;
  return result;
}


//----- (0014CAA0) --------------------------------------------------------
unsigned int __fastcall sub_14CAA0(int a1)
{
  int v1; // ebp
  void *v2; // edi
  int v3; // eax
  int v4; // ebx
  int v5; // edx
  int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int *v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // esi
  unsigned int v14; // edx
  int *v15; // eax
  int v16; // ecx
  unsigned int v18; // edx
  unsigned int v19; // esi
  int v20; // ebx
  int v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // edi
  int v24; // eax
  char *v25; // edx
  unsigned int v26; // eax
  int v27; // edi
  int v28; // edi
  int v29; // eax
  char v30; // dl
  int v31; // [esp-4h] [ebp-24h]

  v1 = a1;
  if ( !*(_DWORD *)(a1 + 880) )
  {
    v2 = (void *)(a1 + 108);
    LOWORD(a1) = 0;
    v3 = a1 << 16;
    LOWORD(v3) = 0;
    memset32(v2, v3, 0xC1u);
    v4 = *(_DWORD *)(v1 + 1056);
    if ( v4 != -1 )
    {
      if ( *(_DWORD *)(*(_DWORD *)(v1 + 4 * v4 + 1028) + 40) )
      {
        v5 = 1;
        v6 = v4 + 1;
        if ( (unsigned int)(v4 + 1) < 7 )
        {
          v7 = v1 + 4 * v6;
          do
          {
            if ( *(_DWORD *)(v7 + 1028) )
              ++v5;
            v7 += 4;
            ++v6;
          }
          while ( v7 < v1 + 28 );
        }
        if ( v5 == dword_189154 )
        {
          v8 = v1;
          do
          {
            v9 = *(int **)(v8 + 1028);
            if ( v9 )
            {
              dword_1C3C30(*(_DWORD *)(v8 + 1028));
              v9[4] = 0;
              v10 = *v9;
              v9[10] = 0;
              v9[3] = v10;
              v9[2] = v10;
              v11 = v9[9];
              v12 = v9[8];
              v9[8] = 0;
              v9[9] = v11 - v12;
            }
            v8 += 4;
          }
          while ( v8 != v1 + 28 );
        }
      }
    }
  }
  v13 = 0;
  v14 = 0;
  if ( *(_DWORD *)(v1 + 880) )
  {
    v15 = *(int **)(v1 + 952);
    do
    {
      ++v14;
      v16 = *v15++;
      v13 += v16;
    }
    while ( v14 < *(_DWORD *)(v1 + 880) );
  }
  if ( (*(_BYTE *)(v1 + 901) & 2) != 0 )
  {
    *(_DWORD *)(v1 + 944) = v13 + *(_DWORD *)(v1 + 940);
    return 0;
  }
  else
  {
    v18 = *(_DWORD *)(v1 + 1092);
    v19 = *(_DWORD *)(v1 + 936) + v13;
    if ( v19 < v18 || (v20 = *(_DWORD *)(v1 + 1084), v18 + v20 < v19) )
    {
      v24 = *(_DWORD *)(v1 + 1068);
      *(_DWORD *)(v1 + 1084) = 0;
      *(_DWORD *)(v1 + 1080) = v24;
      *(_DWORD *)(v1 + 1076) = v24;
      v31 = *(_DWORD *)(v1 + 916);
      *(_DWORD *)(v1 + 1072) = *(_DWORD *)(v1 + 1088) + v24;
      sub_15C941(v31, v19);
      if ( (v19 & 0xFFF) != 0 )
      {
        v25 = *(char **)(v1 + 1076);
        *(_DWORD *)(v1 + 1068) = 0;
        v26 = sub_14CD50(v1, v25, 4096 - (v19 & 0xFFF));
        v27 = *(_DWORD *)(v1 + 1080);
        *(_DWORD *)(v1 + 1084) = v26;
        v28 = v26 + v27;
        v29 = *(_DWORD *)(v1 + 1076);
        *(_DWORD *)(v1 + 1080) = v28;
        *(_DWORD *)(v1 + 1068) = v29;
      }
    }
    else
    {
      v21 = *(_DWORD *)(v1 + 1076);
      *(_DWORD *)(v1 + 1084) = v20 - (v19 - v18);
      v22 = v19 - v18 + v21;
      v23 = *(_DWORD *)(v1 + 1072);
      *(_DWORD *)(v1 + 1076) = v22;
      if ( v22 >= v23 )
      {
        *(_DWORD *)(v1 + 1076) = v22 - v23 + *(_DWORD *)(v1 + 1068);
        *(_DWORD *)(v1 + 1072) = *(_DWORD *)(v1 + 1088) + *(_DWORD *)(v1 + 1068);
      }
    }
    v30 = *(_BYTE *)(v1 + 901);
    *(_DWORD *)(v1 + 1092) = v19;
    if ( (v30 & 2) != 0 )
    {
      return 0;
    }
    else
    {
      *(_DWORD *)(v1 + 944) = *(_DWORD *)(v1 + 940);
      return sub_14CD50(v1, *(char **)(v1 + 940), *(_DWORD *)(*(_DWORD *)(v1 + 952) + 4 * *(_DWORD *)(v1 + 880)));
    }
  }
}
// 189154: using guessed type int dword_189154;
// 1C3C30: using guessed type int (__stdcall *dword_1C3C30)(_DWORD);


//----- (0014CD10) --------------------------------------------------------
unsigned int __fastcall sub_14CD10(int a1)
{
  if ( (*(_BYTE *)(a1 + 901) & 2) != 0 )
    return 0;
  *(_DWORD *)(a1 + 944) = *(_DWORD *)(a1 + 940);
  return sub_14CD50(a1, *(char **)(a1 + 940), *(_DWORD *)(*(_DWORD *)(a1 + 952) + 4 * *(_DWORD *)(a1 + 880)));
}


//----- (0014CD50) --------------------------------------------------------
unsigned int __fastcall sub_14CD50(int a1, char *a2, unsigned int a3)
{
  int v4; // eax
  int v5; // ecx
  unsigned int v6; // ebx
  unsigned int v7; // ecx
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int v11; // esi
  _BOOL1 i; // zf
  unsigned int v13; // eax
  char *v14; // edi
  int v15; // edi
  int v16; // eax
  int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // ebx
  unsigned int v20; // eax
  int v21; // edi
  unsigned int result; // eax
  unsigned int v23; // [esp+0h] [ebp-28h] BYREF
  unsigned int v24; // [esp+4h] [ebp-24h] BYREF
  int v25; // [esp+8h] [ebp-20h]
  unsigned int v26; // [esp+Ch] [ebp-1Ch]
  unsigned int v27; // [esp+10h] [ebp-18h]
  char *v28; // [esp+14h] [ebp-14h]

  v28 = a2;
  v26 = a3;
  v27 = 0;
  v23 = 0;
  v4 = dword_18A5AC(a1);
  v5 = *(_DWORD *)(a1 + 1068);
  v25 = v4;
  if ( v5 )
  {
    while ( 1 )
    {
      do
      {
        if ( !*(_DWORD *)(a1 + 1084) )
          break;
        v24 = *(_DWORD *)(a1 + 1072) - *(_DWORD *)(a1 + 1076);
        if ( v24 > v26 )
          v24 = v26;
        if ( *(_DWORD *)(a1 + 1084) < v24 )
          v24 = *(_DWORD *)(a1 + 1084);
        qmemcpy(v28, *(void **)(a1 + 1076), v24);
        *(_DWORD *)(a1 + 1084) -= v24;
        *(_DWORD *)(a1 + 1092) += v24;
        v6 = v24 + *(_DWORD *)(a1 + 1076);
        v7 = *(_DWORD *)(a1 + 1072);
        *(_DWORD *)(a1 + 1076) = v6;
        if ( v6 >= v7 )
        {
          v8 = *(_DWORD *)(a1 + 1068);
          v9 = *(_DWORD *)(a1 + 1088);
          *(_DWORD *)(a1 + 1076) = v8;
          v10 = v9 + v8;
          v11 = *(_DWORD *)(a1 + 1084);
          *(_DWORD *)(a1 + 1072) = v10;
          if ( !v11 )
            *(_DWORD *)(a1 + 1080) = *(_DWORD *)(a1 + 1076);
        }
        v27 += v24;
        v26 -= v24;
        v28 += v24;
      }
      while ( v26 );
      for ( i = dword_189154 == 0; ; i = v16 == 0 )
      {
        if ( !i )
          ((int(*)())(void*)dword_1C3C34)();
        if ( v26 <= 0x1000 )
          break;
        if ( v26 <= 0x4000 )
          v13 = v26 >> 12 << 12;
        else
          v13 = 0x4000;
        v24 = v13;
        v14 = v28;
        sub_15C8A9(*(_DWORD *)(a1 + 916), *(_DWORD *)(a1 + 916), (int)v28, __DS__, v13, &v24);
        v26 -= v24;
        v23 += v24;
        v28 = &v14[v24];
        v15 = *(_DWORD *)(a1 + 1092);
        v27 += v24;
        v16 = dword_189154;
        *(_DWORD *)(a1 + 1092) = v24 + v15;
      }
      if ( !v26 )
        break;
      v24 = (v26 + 4095) >> 12 << 12;
      sub_15C8A9(__DS__, *(_DWORD *)(a1 + 916), *(_DWORD *)(a1 + 1068), __DS__, v24, &v24);
      v23 += v24;
      v17 = *(_DWORD *)(a1 + 1068);
      *(_DWORD *)(a1 + 1076) = v17;
      *(_DWORD *)(a1 + 1080) = v17 + v24;
      *(_DWORD *)(a1 + 1084) = v24;
    }
  }
  else
  {
    sub_15C8A9(*(_DWORD *)(a1 + 916), *(_DWORD *)(a1 + 916), (int)v28, __DS__, v26, &v23);
    v27 = v23;
  }
  v18 = v23;
  v19 = *(_DWORD *)(a1 + 1184);
  *(_DWORD *)(a1 + 1096) += v23;
  if ( v19 )
  {
    v20 = 1000 * (uint64_t)v23 / v19;
    v23 = v20 + v25;
    do
      v20 = dword_18A5AC(v20);
    while ( v20 < v23 );
  }
  else
  {
    v20 = dword_18A5AC(v18);
  }
  v21 = v20 - v25 + *(_DWORD *)(a1 + 1100);
  result = v27;
  *(_DWORD *)(a1 + 1100) = v21;
  return result;
}
// 189154: using guessed type int dword_189154;
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);
// 1C3C34: using guessed type int (*dword_1C3C34)(void);


//----- (0014D000) --------------------------------------------------------
int __fastcall sub_14D000(_DWORD *a1)
{
  int v2; // eax
  int v3; // ebp
  unsigned int v4; // ebx
  unsigned int v5; // ecx
  int v6; // eax
  unsigned int v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // eax
  unsigned int v11; // edi
  _DWORD v13[7]; // [esp+0h] [ebp-1Ch] BYREF

  v13[0] = 0;
  if ( a1[220] < a1[3] )
  {
    v2 = a1[272] - a1[271];
    if ( v2 >= 4096 )
    {
      v3 = dword_18A5AC(v2);
      sub_15C8A9(__DS__, a1[229], a1[270], __DS__, 0x1000u, v13);
      a1[271] += v13[0];
      v4 = v13[0] + a1[270];
      v5 = a1[268];
      a1[270] = v4;
      if ( v4 > v5 )
      {
        v6 = a1[267];
        a1[268] = v4;
        a1[270] = v6;
      }
      v7 = a1[271];
      if ( v7 > a1[278] )
        a1[278] = v7;
      v8 = v13[0];
      v9 = a1[296];
      a1[276] += v13[0];
      if ( v9 )
      {
        v10 = 1000 * (uint64_t)v13[0] / v9;
        v11 = v10 + v3;
        do
          v10 = dword_18A5AC(v10);
        while ( v10 < v11 );
      }
      else
      {
        v10 = dword_18A5AC(v8);
      }
      a1[277] += v10 - v3;
    }
  }
  return v13[0];
}
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);


//----- (0014D110) --------------------------------------------------------
int __fastcall sub_14D110(int a1, int a2)
{
  unsigned int v2; // ebx
  unsigned int v3; // ecx

  v2 = a2 + *(_DWORD *)(a1 + 1116);
  v3 = *(_DWORD *)(a1 + 1180);
  *(_DWORD *)(a1 + 1116) = v2;
  if ( v2 > v3 )
    *(_DWORD *)(a1 + 1180) = v2;
  return sub_13259F(a2);
}


//----- (0014D1C2) --------------------------------------------------------
int __fastcall sub_14D1C2(int (**a1)(void))
{
  return (*a1)();
}


//----- (0014D1C9) --------------------------------------------------------
int __fastcall sub_14D1C9(int a1, int a2)
{
  return (*(int (**)(void))(a2 + 4))();
}


//----- (0014D1D1) --------------------------------------------------------
int __fastcall sub_14D1D1(int a1, uint8_t *a2, int *a3)
{
  int v5; // ebp
  char v6; // ah
  uint8_t *v7; // ebx
  uint8_t *v8; // ecx
  int v9; // ebx
  int v10; // eax
  uint8_t *v11; // eax
  unsigned int v12; // ebx
  int *v13; // edx
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // ebx
  uint8_t *v19; // [esp+0h] [ebp-18h] BYREF
  int v20; // [esp+4h] [ebp-14h]

  v19 = a2;
  v5 = 0;
  v6 = *(_BYTE *)(a1 + 16) & 0xFD;
  v20 = 0;
  *(_BYTE *)(a1 + 16) = v6;
  while ( 1 )
  {
    v7 = v19;
    v8 = ++v19;
    v9 = *v7;
    if ( !v9 )
      break;
    if ( (IsTable[(uint8_t)(v9 + 1)] & 2) != 0 )
    {
      v5 += sub_14D50D(a1);
    }
    else
    {
      if ( v9 != 37 )
      {
        v10 = sub_14D1C2((int (**)(void))a1);
        if ( v10 != v9 )
          goto LABEL_7;
LABEL_53:
        ++v5;
        goto LABEL_54;
      }
      v11 = sub_14D418(v8, a1);
      v19 = v11;
      v12 = *v11;
      if ( *v11 )
        v19 = v11 + 1;
      if ( v12 < 0x65 )
      {
        if ( v12 < 0x58 )
        {
          if ( v12 < 0x45 )
          {
            if ( v12 != 37 )
              goto LABEL_54;
            v10 = sub_14D1C2((int (**)(void))a1);
            if ( v10 != 37 )
            {
LABEL_7:
              if ( (*(_BYTE *)(a1 + 16) & 2) == 0 )
                sub_14D1C9(v10, a1);
              break;
            }
            goto LABEL_53;
          }
          if ( v12 <= 0x45 || v12 == 71 )
          {
LABEL_44:
            sub_14D89F(a1, a3);
            goto LABEL_48;
          }
        }
        else
        {
          if ( v12 <= 0x58 )
          {
LABEL_43:
            v16 = 1;
            v17 = 16;
            goto LABEL_39;
          }
          if ( v12 >= 0x63 )
          {
            if ( v12 <= 0x63 )
            {
              v15 = sub_14D54C(a1, a3, v12, v8);
              goto LABEL_48;
            }
            v16 = 1;
            v17 = 10;
LABEL_39:
            v13 = a3;
            v14 = a1;
LABEL_40:
            v15 = sub_14DBB6(v14, v13, v17, v16);
LABEL_48:
            if ( v15 <= 0 )
              break;
            v5 += v15;
            if ( (*(_BYTE *)(a1 + 16) & 1) != 0 )
              ++v20;
            goto LABEL_54;
          }
          if ( v12 == 91 )
          {
            v15 = sub_14D7A5(a1, a3, &v19, (_BYTE *)a1);
            goto LABEL_48;
          }
        }
      }
      else
      {
        if ( v12 <= 0x67 )
          goto LABEL_44;
        if ( v12 < 0x70 )
        {
          if ( v12 < 0x6E )
          {
            if ( v12 == 105 )
            {
              v16 = 1;
              v13 = a3;
              v14 = a1;
              v17 = 0;
              goto LABEL_40;
            }
          }
          else
          {
            if ( v12 > 0x6E )
            {
              v16 = 1;
              v17 = 8;
              goto LABEL_39;
            }
            sub_14D704(a1, a3, v5);
          }
        }
        else
        {
          if ( v12 <= 0x70 )
            goto LABEL_43;
          if ( v12 < 0x75 )
          {
            if ( v12 == 115 )
            {
              sub_14D5E1(a1, a3, 115, v8);
              goto LABEL_48;
            }
          }
          else
          {
            if ( v12 <= 0x75 )
            {
              v17 = 10;
              v13 = a3;
              v14 = a1;
              v16 = 0;
              goto LABEL_40;
            }
            if ( v12 == 120 )
              goto LABEL_43;
          }
        }
      }
    }
LABEL_54:
    if ( (*(_BYTE *)(a1 + 16) & 2) != 0 )
    {
      if ( *v19 == 37 )
      {
        ++v19;
        v19 = sub_14D418(v19, a1);
        if ( *v19 == 110 )
          sub_14D704(a1, a3, v5);
      }
      break;
    }
  }
  if ( v20 || (*(_BYTE *)(a1 + 16) & 2) == 0 )
    return v20;
  else
    return -1;
}
// 14D385: variable 'v15' is possibly undefined


//----- (0014D418) --------------------------------------------------------
uint8_t *__fastcall sub_14D418(uint8_t *result, int a2)
{
  char v3; // dl
  int v4; // edx
  int v5; // edx
  uint8_t v6; // dl
  int v7; // [esp+0h] [ebp-10h]

  v3 = *(_BYTE *)(a2 + 16) | 1;
  *(_BYTE *)(a2 + 16) = v3;
  *(_DWORD *)(a2 + 12) = -1;
  *(_BYTE *)(a2 + 16) = v3 & 3;
  if ( *result == 42 )
  {
    ++result;
    *(_BYTE *)(a2 + 16) &= ~1u;
  }
  v7 = *result;
  if ( (IsTable[(uint8_t)(v7 + 1)] & 0x20) != 0 )
  {
    v4 = 0;
    do
    {
      ++result;
      v4 = v7 - 48 + 10 * v4;
      v7 = *result;
    }
    while ( (IsTable[(uint8_t)(v7 + 1)] & 0x20) != 0 );
    *(_DWORD *)(a2 + 12) = v4;
  }
  v5 = *result;
  if ( v5 == 78 )
  {
    *(_BYTE *)(a2 + 16) |= 8u;
    ++result;
  }
  else if ( v5 == 70 )
  {
    ++result;
    *(_BYTE *)(a2 + 16) |= 4u;
  }
  v6 = *result;
  if ( *result < 0x68u )
  {
    if ( v6 == 76 )
    {
      ++result;
      *(_BYTE *)(a2 + 16) |= 0x40u;
    }
  }
  else if ( *result <= 0x68u )
  {
    ++result;
    *(_BYTE *)(a2 + 16) |= 0x10u;
  }
  else if ( v6 >= 0x6Cu && (v6 <= 0x6Cu || v6 == 119) )
  {
    ++result;
    *(_BYTE *)(a2 + 16) |= 0x20u;
  }
  return result;
}


//----- (0014D50D) --------------------------------------------------------
int __fastcall sub_14D50D(int a1)
{
  int i; // esi
  int v3; // eax

  for ( i = 0; ; ++i )
  {
    v3 = sub_14D1C2((int (**)(void))a1);
    if ( (IsTable[(uint8_t)(v3 + 1)] & 2) == 0 )
      break;
  }
  if ( (*(_BYTE *)(a1 + 16) & 2) == 0 )
    sub_14D1C9(v3, a1);
  return i;
}


//----- (0014D54C) --------------------------------------------------------
int __fastcall sub_14D54C(int a1, int *a2, int a3, _WORD *a4)
{
  char v5; // cl
  int v6; // edi
  int v7; // esi
  int v8; // ecx
  int v9; // edx
  int v10; // esi
  char v11; // al
  int16_t v13; // [esp+0h] [ebp-18h]

  if ( (*(_BYTE *)(a1 + 16) & 1) != 0 )
  {
    v5 = *(_BYTE *)(a1 + 16);
    if ( (v5 & 4) != 0 )
    {
      v6 = *a2 + 8;
      *a2 = v6;
      a4 = *(_WORD **)(v6 - 8);
      __ES__ = *(_WORD *)(v6 - 8 + 4);
    }
    else if ( (v5 & 8) != 0 )
    {
      v7 = *a2 + 4;
      *a2 = v7;
      __ES__ = __DS__;
      a4 = *(_WORD **)(v7 - 4);
    }
    else
    {
      v8 = *a2 + 4;
      *a2 = v8;
      __ES__ = __DS__;
      a4 = *(_WORD **)(v8 - 4);
    }
  }
  v9 = *(_DWORD *)(a1 + 12);
  v10 = 0;
  if ( v9 == -1 )
    v9 = 1;
  while ( v9 > 0 )
  {
    v13 = sub_14D1C2((int (**)(void))a1);
    v11 = *(_BYTE *)(a1 + 16);
    if ( (v11 & 2) != 0 )
      break;
    ++v10;
    --v9;
    if ( (v11 & 1) != 0 )
    {
      if ( (v11 & 0x20) != 0 )
      {
        *a4++ = v13;
      }
      else
      {
        *(_BYTE *)a4 = v13;
        a4 = (_WORD *)((char *)a4 + 1);
      }
    }
  }
  return v10;
}


//----- (0014D5E1) --------------------------------------------------------
void __fastcall sub_14D5E1(int a1, int *a2, int a3, _BYTE *a4)
{
  char v5; // al
  int v6; // edi
  int v7; // esi
  int v8; // ecx
  int i; // esi
  int v10; // eax
  int v11; // [esp+0h] [ebp-1Ch]
  uint8_t v12; // [esp+4h] [ebp-18h]

  if ( (*(_BYTE *)(a1 + 16) & 0x20) != 0 )
    v12 = 2;
  else
    v12 = 1;
  v5 = *(_BYTE *)(a1 + 16);
  if ( (v5 & 1) != 0 )
  {
    if ( (v5 & 4) != 0 )
    {
      v6 = *a2 + 8;
      *a2 = v6;
      a4 = *(_BYTE **)(v6 - 8);
      __ES__ = *(_WORD *)(v6 - 8 + 4);
    }
    else if ( (v5 & 8) != 0 )
    {
      v7 = *a2 + 4;
      *a2 = v7;
      __ES__ = __DS__;
      a4 = *(_BYTE **)(v7 - 4);
    }
    else
    {
      v8 = *a2 + 4;
      *a2 = v8;
      __ES__ = __DS__;
      a4 = *(_BYTE **)(v8 - 4);
    }
  }
  for ( i = 0; ; ++i )
  {
    v11 = sub_14D1C2((int (**)(void))a1);
    if ( (IsTable[(uint8_t)(v11 + 1)] & 2) == 0 )
      break;
  }
  if ( (*(_BYTE *)(a1 + 16) & 2) != 0 )
  {
    i = 0;
  }
  else
  {
    v10 = *(_DWORD *)(a1 + 12);
    *(_DWORD *)(a1 + 12) = v10 - 1;
    if ( v10 )
    {
      while ( 1 )
      {
        ++i;
        if ( (*(_BYTE *)(a1 + 16) & 1) != 0 )
        {
          if ( v12 == 1 )
            *a4 = v11;
          else
            *(_WORD *)a4 = v11;
          a4 += v12;
        }
        v11 = sub_14DDCD(a1);
        if ( v11 == -1 )
          break;
        if ( (IsTable[(uint8_t)(v11 + 1)] & 2) != 0 )
          goto LABEL_23;
      }
    }
    else
    {
LABEL_23:
      sub_14D1C9(v11, a1);
    }
  }
  if ( (*(_BYTE *)(a1 + 16) & 1) != 0 && i > 0 )
  {
    if ( v12 == 1 )
      *a4 = 0;
    else
      *(_WORD *)a4 = 0;
  }
  JUMPOUT(0x14D5DB);
}
// 14D6FF: control flows out of bounds to 14D5DB


//----- (0014D704) --------------------------------------------------------
int __fastcall sub_14D704(int result, int *a2, int a3)
{
  char v3; // cl
  int v4; // edi
  _WORD *v5; // edx
  int v6; // esi
  int v7; // ecx

  v3 = *(_BYTE *)(result + 16);
  if ( (v3 & 1) != 0 )
  {
    if ( (v3 & 4) != 0 )
    {
      v4 = *a2 + 8;
      *a2 = v4;
      v5 = *(_WORD **)(v4 - 8);
      __ES__ = *(_WORD *)(v4 - 8 + 4);
    }
    else if ( (v3 & 8) != 0 )
    {
      v6 = *a2 + 4;
      *a2 = v6;
      __ES__ = __DS__;
      v5 = *(_WORD **)(v6 - 4);
    }
    else
    {
      v7 = *a2 + 4;
      *a2 = v7;
      __ES__ = __DS__;
      v5 = *(_WORD **)(v7 - 4);
    }
    if ( (*(_BYTE *)(result + 16) & 0x10) != 0 )
      *v5 = a3;
    else
      *(_DWORD *)v5 = a3;
  }
  return result;
}


//----- (0014D762) --------------------------------------------------------
_BYTE *__fastcall sub_14D762(uint8_t *a1, int a2)
{
  int v3; // eax
  _BYTE *v4; // ecx

  memset(a2, 0, 32);
  v3 = *a1;
  v4 = a1 + 1;
  if ( v3 )
  {
    do
    {
      *(_BYTE *)((v3 >> 3) + a2) |= byte_17CD98[v3 & 7];
      v3 = (uint8_t)*v4;
      if ( !*v4 )
        break;
      ++v4;
    }
    while ( v3 != 93 );
  }
  return v4;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (0014D7A5) --------------------------------------------------------
int __usercall sub_14D7A5(int a1, int *a2, uint8_t **a3, _BYTE *a4)
{
  uint8_t *v6; // eax
  _BOOL1 v7; // zf
  char v8; // ah
  int v9; // esi
  int v10; // eoff
  int v11; // ebx
  int v12; // edx
  int v13; // edx
  int i; // edi
  int v15; // eax
  char v16; // bl
  _BYTE v18[32]; // [esp+0h] [ebp-40h] BYREF
  int v19; // [esp+20h] [ebp-20h]
  bool v20; // [esp+24h] [ebp-1Ch]
  int v21; // [esp+28h] [ebp-18h]

  v6 = *a3;
  v7 = **a3 != 94;
  v20 = **a3 == 94;
  if ( !v7 )
    *a3 = v6 + 1;
  *a3 = sub_14D762(*a3, (int)v18);
  v8 = *(_BYTE *)(a1 + 16);
  if ( (v8 & 1) != 0 )
  {
    if ( (v8 & 4) != 0 )
    {
      v9 = *a2 + 8;
      *a2 = v9;
      v10 = v9 - 8;
      a4 = *(_BYTE **)(v9 - 8);
      __ES__ = *(_WORD *)(v10 + 4);
    }
    else if ( (v8 & 8) != 0 )
    {
      v11 = *a2 + 4;
      *a2 = v11;
      __ES__ = __DS__;
      a4 = *(_BYTE **)(v11 - 4);
    }
    else
    {
      v12 = *a2 + 4;
      *a2 = v12;
      __ES__ = __DS__;
      a4 = *(_BYTE **)(v12 - 4);
    }
  }
  v13 = *(_DWORD *)(a1 + 12);
  for ( i = 0; v13; ++i )
  {
    v15 = sub_14D1C2((int (**)(void))a1);
    v16 = *(_BYTE *)(a1 + 16);
    v21 = v15;
    if ( (v16 & 2) != 0 )
      break;
    v19 = (uint8_t)v18[v15 >> 3];
    if ( ((uint8_t)(v19 & byte_17CD98[v15 & 7]) == 0) != v20 )
    {
      sub_14D1C9(v15, a1);
      break;
    }
    --v13;
    if ( (*(_BYTE *)(a1 + 16) & 1) != 0 )
      *a4++ = v21;
  }
  if ( (*(_BYTE *)(a1 + 16) & 1) != 0 && i > 0 )
    *a4 = 0;
  return i;
}


//----- (0014D89F) --------------------------------------------------------
void __fastcall sub_14D89F(int a1, int *a2)
{
  int v3; // edi
  char *v4; // ebx
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // ebp
  int v9; // ebp
  int v10; // eax
  int v11; // eax
  char *v12; // ebp
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char v16; // bl
  int v17; // ecx
  int *v18; // ebx
  int v19; // ebx
  int v20; // edx
  char v21; // cl
  int v22; // eax
  char v23; // [esp+0h] [ebp-84h] BYREF
  _BYTE v24[3]; // [esp+1h] [ebp-83h] BYREF
  int v25; // [esp+50h] [ebp-34h]
  int v26; // [esp+54h] [ebp-30h]
  unsigned int j; // [esp+58h] [ebp-2Ch]
  int *v28; // [esp+5Ch] [ebp-28h]
  int i; // [esp+60h] [ebp-24h]
  int v30; // [esp+64h] [ebp-20h]
  int v31; // [esp+68h] [ebp-1Ch]

  v28 = a2;
  v3 = 0;
  v4 = &v23;
  for ( i = 0; ; ++i )
  {
    v5 = sub_14D1C2((int (**)(void))a1);
    v6 = v5;
    if ( (IsTable[(uint8_t)(v5 + 1)] & 2) == 0 )
      break;
  }
  if ( (*(_BYTE *)(a1 + 16) & 2) != 0 )
    goto LABEL_42;
  v7 = *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 12) = v7 - 1;
  if ( v7 )
  {
    if ( v5 == 43 || v5 == 45 )
    {
      v8 = i;
      v23 = v5;
      v4 = v24;
      v6 = sub_14DDCD(a1);
      i = v8 + 1;
      if ( v6 == -1 )
        goto LABEL_42;
    }
    if ( (IsTable[(uint8_t)(v6 + 1)] & 0x20) != 0 || v6 == 46 )
    {
      v31 = 0;
      v9 = 0;
      if ( (IsTable[(uint8_t)(v6 + 1)] & 0x20) != 0 )
      {
        v9 = 1;
        while ( 1 )
        {
          *v4++ = v6;
          if ( (*(_BYTE *)(a1 + 16) & 0x10) != 0 )
            HIWORD(v31) = 10 * HIWORD(v31) + v6 - 48;
          ++v3;
          v10 = sub_14DDCD(a1);
          v6 = v10;
          if ( v10 == -1 )
            break;
          if ( (IsTable[(uint8_t)(v10 + 1)] & 0x20) == 0 )
            goto LABEL_17;
        }
LABEL_42:
        if ( v3 > 0 && (*(_BYTE *)(a1 + 16) & 1) != 0 )
        {
          *v4 = 0;
          if ( (*(_BYTE *)(a1 + 16) & 0x10) != 0 )
          {
            if ( v23 == 45 )
              v31 = -v31;
          }
          else
          {
            off_18A54C();
          }
          v16 = *(_BYTE *)(a1 + 16);
          if ( (v16 & 4) != 0 )
          {
            v17 = *v28 + 8;
            *v28 = v17;
            v18 = *(int **)(v17 - 8);
            __ES__ = *(_WORD *)(v17 - 8 + 4);
          }
          else if ( (v16 & 8) != 0 )
          {
            v19 = *v28 + 4;
            *v28 = v19;
            __ES__ = __DS__;
            v18 = *(int **)(v19 - 4);
          }
          else
          {
            v20 = *v28 + 4;
            *v28 = v20;
            __ES__ = __DS__;
            v18 = *(int **)(v20 - 4);
          }
          v21 = *(_BYTE *)(a1 + 16);
          if ( (v21 & 0x10) != 0 )
          {
            v22 = v31;
          }
          else
          {
            if ( (v21 & 0x20) != 0 || (v21 & 0x40) != 0 )
            {
              *v18 = v25;
              v18[1] = v26;
              goto LABEL_60;
            }
            v22 = _FDFS(v25, v26, v18);
          }
          *v18 = v22;
        }
LABEL_60:
        JUMPOUT(0x14D5DB);
      }
LABEL_17:
      if ( v6 == 46 )
      {
        *v4 = 46;
        v11 = sub_14DDCD(a1);
        ++v4;
        v6 = v11;
        if ( v11 == -1 )
          goto LABEL_42;
        if ( !v9 && (IsTable[(uint8_t)(v11 + 1)] & 0x20) == 0 )
          goto LABEL_41;
        ++v3;
        do
        {
          if ( (IsTable[(uint8_t)(v6 + 1)] & 0x20) == 0 )
            break;
          ++v3;
          *v4++ = v6;
          v6 = sub_14DDCD(a1);
        }
        while ( v6 != -1 );
        if ( (*(_BYTE *)(a1 + 16) & 0x10) != 0 )
        {
          v12 = v4;
          for ( j = 0; ; j /= 0xAu )
          {
            v13 = (uint8_t)*--v12;
            if ( v13 == 46 )
              break;
            v30 = 10;
            BYTE2(j) = v13 - 48;
          }
          LOWORD(v31) = j;
        }
        if ( v6 == -1 )
          goto LABEL_42;
      }
      if ( (*(_BYTE *)(a1 + 16) & 0x10) == 0 && (v6 == 101 || v6 == 69) )
      {
        ++v3;
        *v4 = v6;
        v14 = sub_14DDCD(a1);
        ++v4;
        v6 = v14;
        if ( v14 == -1 )
          goto LABEL_42;
        if ( v14 == 43 || v14 == 45 )
        {
          ++v3;
          *v4++ = v14;
          v6 = sub_14DDCD(a1);
          if ( v6 == -1 )
            goto LABEL_42;
        }
        if ( (IsTable[(uint8_t)(v6 + 1)] & 0x20) != 0 )
        {
          while ( 1 )
          {
            ++v3;
            *v4 = v6;
            v15 = sub_14DDCD(a1);
            ++v4;
            v6 = v15;
            if ( v15 == -1 )
              goto LABEL_42;
            if ( (IsTable[(uint8_t)(v15 + 1)] & 0x20) == 0 )
              goto LABEL_41;
          }
        }
        v3 = 0;
      }
    }
  }
LABEL_41:
  sub_14D1C9(v6, a1);
  goto LABEL_42;
}
// 14DBB1: control flows out of bounds to 14D5DB
// 15C9DA: using guessed type int __fastcall _FDFS(_DWORD, _DWORD, _DWORD);
// 18A54C: using guessed type void (*off_18A54C)(void);


//----- (0014DBB6) --------------------------------------------------------
int __fastcall sub_14DBB6(int a1, int *a2, int a3, int a4)
{
  int v6; // edi
  int v7; // ecx
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char v16; // ah
  int v17; // edx
  _WORD *v18; // eax
  int v19; // ebp
  int v20; // ebx
  int i; // [esp+0h] [ebp-20h]
  int v24; // [esp+8h] [ebp-18h]

  v6 = 0;
  v7 = 0;
  for ( i = 0; ; ++i )
  {
    v8 = sub_14D1C2((int (**)(void))a1);
    if ( (IsTable[(uint8_t)(v8 + 1)] & 2) == 0 )
      break;
  }
  if ( (*(_BYTE *)(a1 + 16) & 2) != 0 )
    goto LABEL_34;
  v9 = *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 12) = v9 - 1;
  if ( !v9 )
    goto LABEL_33;
  v24 = 43;
  if ( a4 && (v8 == 43 || v8 == 45) )
  {
    ++i;
    v24 = v8;
    v8 = sub_14DDCD(a1);
    if ( v8 == -1 )
      goto LABEL_34;
  }
  if ( !a3 )
  {
    if ( v8 != 48 )
    {
      a3 = 10;
      goto LABEL_26;
    }
    v7 = 1;
    v10 = sub_14DDCD(a1);
    v8 = v10;
    if ( v10 != -1 )
    {
      if ( v10 != 120 && v10 != 88 )
      {
        a3 = 8;
        goto LABEL_26;
      }
      v7 = 0;
      v8 = sub_14DDCD(a1);
      i += 2;
      if ( v8 != -1 )
      {
        a3 = 16;
        goto LABEL_26;
      }
    }
    goto LABEL_34;
  }
  if ( a3 != 16 || v8 != 48 )
    goto LABEL_26;
  v7 = 1;
  v11 = sub_14DDCD(a1);
  v8 = v11;
  if ( v11 != -1 )
  {
    if ( v11 == 120 || v11 == 88 )
    {
      v12 = sub_14DDCD(a1);
      v7 = 0;
      i += 2;
      goto LABEL_25;
    }
LABEL_26:
    while ( 1 )
    {
      v13 = sub_14DDA6(v8);
      if ( v13 >= a3 )
        break;
      v6 = v13 + a3 * v6;
      ++v7;
      v12 = sub_14DDCD(a1);
LABEL_25:
      v8 = v12;
      if ( v12 == -1 )
        goto LABEL_34;
    }
    if ( v8 == 58 && *(char *)(a1 + 16) < 0 )
    {
      while ( 1 )
      {
        ++v7;
        v14 = sub_14DDCD(a1);
        v8 = v14;
        if ( v14 == -1 )
          goto LABEL_34;
        v15 = sub_14DDA6(v14);
        if ( v15 >= a3 )
          break;
        v6 = v15 + a3 * v6;
      }
    }
LABEL_33:
    sub_14D1C9(v8, a1);
  }
LABEL_34:
  if ( v24 == 45 )
    v6 = -v6;
  if ( v7 > 0 )
  {
    v16 = *(_BYTE *)(a1 + 16);
    v7 += i;
    if ( (v16 & 1) != 0 )
    {
      if ( (v16 & 4) != 0 )
      {
        v17 = *a2 + 8;
        *a2 = v17;
        v18 = *(_WORD **)(v17 - 8);
        __ES__ = *(_WORD *)(v17 - 8 + 4);
      }
      else if ( (v16 & 8) != 0 )
      {
        v19 = *a2 + 4;
        *a2 = v19;
        __ES__ = __DS__;
        v18 = *(_WORD **)(v19 - 4);
      }
      else
      {
        v20 = *a2 + 4;
        *a2 = v20;
        __ES__ = __DS__;
        v18 = *(_WORD **)(v20 - 4);
      }
      if ( (*(_BYTE *)(a1 + 16) & 0x10) != 0 )
        *v18 = v6;
      else
        *(_DWORD *)v18 = v6;
    }
  }
  return v7;
}
// 14DD33: variable 'v24' is possibly undefined


//----- (0014DDA6) --------------------------------------------------------
int __fastcall sub_14DDA6(int a1)
{
  int v2; // eax

  if ( a1 >= 48 && a1 <= 57 )
    return a1 - 48;
  v2 = tolower();
  if ( v2 < 97 || v2 > 102 )
    return 16;
  else
    return v2 - 87;
}
// 13E238: using guessed type int tolower(void);


//----- (0014DDCD) --------------------------------------------------------
int __fastcall sub_14DDCD(int a1)
{
  int v2; // eax
  int result; // eax

  v2 = *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 12) = v2 - 1;
  if ( !v2 )
    return -1;
  result = sub_14D1C2((int (**)(void))a1);
  if ( (*(_BYTE *)(a1 + 16) & 2) != 0 )
    return -1;
  return result;
}


//----- (0014DDF3) --------------------------------------------------------
int __fastcall sub_14DDF3( unsigned int a1, char *a2, int a3, int (__fastcall *a4)(_DWORD, _DWORD, _DWORD, _DWORD))
{
  int v4; // eax

  if ( !sub_13D2A6(0x8000u) )
    exit(1, (int)a2);
  if ( !a4 )
    return -203;
  dword_1C3C68 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD))sub_13DABB;
  dword_1C0990 = a4;
  word_1C3C96 = a1 + 10;
  v4 = nmalloc((uint16_t)(a1 + 10));
  dword_1C3C70 = v4;
  if ( !v4 )
    return -202;
  dword_1C3C80 = nmalloc((uint16_t)word_1C3C96);
  if ( !dword_1C3C80 )
    return -202;
  dword_1C3C4C = dword_1C3C80;
  dword_1C3C54 = 0;
  dword_1C3C78 = nmalloc((uint16_t)word_1C3C96);
  if ( !dword_1C3C78 )
    return -202;
  dword_1C3C5C = dword_1C3C78;
  dword_1C3C7C = time(0);
  byte_189712 = a3;
  dword_1C40E4 = 0;
  strcpy(&byte_1C3C88, a2);
  dword_1C3C92 = a1;
  if ( sub_14F297((int *)&word_1C3C84, a2, a3) )
  {
    sub_14F4CE();
    return -201;
  }
  else
  {
    word_189708 = word_1C3C84;
    dword_1C3C6C = 0;
    dword_189174 = 0;
    sub_14E46B(0, (int)a2, a3);
    return 1;
  }
}
// 13C905: using guessed type int64_t __fastcall time(_DWORD);
// 13CB78: using guessed type int __fastcall nmalloc(_DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 189174: using guessed type int dword_189174;
// 189708: using guessed type int16_t word_189708;
// 189712: using guessed type char byte_189712;
// 1C0990: using guessed type int (__fastcall *dword_1C0990)(_DWORD, _DWORD, _DWORD, _DWORD);
// 1C3C4C: using guessed type int dword_1C3C4C;
// 1C3C54: using guessed type int dword_1C3C54;
// 1C3C5C: using guessed type int dword_1C3C5C;
// 1C3C68: using guessed type int (__fastcall *dword_1C3C68)(_DWORD, _DWORD, _DWORD);
// 1C3C6C: using guessed type int dword_1C3C6C;
// 1C3C70: using guessed type int dword_1C3C70;
// 1C3C78: using guessed type int dword_1C3C78;
// 1C3C7C: using guessed type int dword_1C3C7C;
// 1C3C80: using guessed type int dword_1C3C80;
// 1C3C84: using guessed type int16_t word_1C3C84;
// 1C3C88: using guessed type char byte_1C3C88;
// 1C3C92: using guessed type int dword_1C3C92;
// 1C3C96: using guessed type int16_t word_1C3C96;
// 1C40E4: using guessed type int dword_1C40E4;


//----- (0014DF7A) --------------------------------------------------------
int sub_14DF7A()
{
  int result; // eax

  dword_1C3C68 = 0;
  word_1C3C96 = 0;
  nfree(dword_1C3C80);
  dword_1C3C80 = 0;
  dword_1C3C4C = 0;
  nfree(dword_1C3C78);
  dword_1C3C78 = 0;
  dword_1C3C5C = 0;
  nfree(dword_1C3C70);
  dword_1C3C70 = 0;
  dword_1C3C7C = 0;
  sub_14F4CE();
  byte_1C3C88 = 0;
  dword_1C3C92 = 0;
  result = sub_13D344();
  word_189708 = 0;
  return result;
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);
// 189708: using guessed type int16_t word_189708;
// 1C3C4C: using guessed type int dword_1C3C4C;
// 1C3C5C: using guessed type int dword_1C3C5C;
// 1C3C68: using guessed type int (__fastcall *dword_1C3C68)(_DWORD, _DWORD, _DWORD);
// 1C3C70: using guessed type int dword_1C3C70;
// 1C3C78: using guessed type int dword_1C3C78;
// 1C3C7C: using guessed type int dword_1C3C7C;
// 1C3C80: using guessed type int dword_1C3C80;
// 1C3C88: using guessed type char byte_1C3C88;
// 1C3C92: using guessed type int dword_1C3C92;
// 1C3C96: using guessed type int16_t word_1C3C96;


//----- (0014E02A) --------------------------------------------------------
int __fastcall sub_14E02A(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int v4; // eax
  int v5; // eax

  v3 = sub_14E46B(a1, a2, a3);
  v4 = sub_14E6C8(v3, a2, a3);
  v5 = sub_13D6D8(v4, a2, a3);
  sub_14E1F2(v5, a2, a3);
  return 1;
}


//----- (0014E069) --------------------------------------------------------
int __fastcall sub_14E069(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // ebx
  int v7; // edx
  _WORD v9[4]; // [esp+0h] [ebp-44h] BYREF
  _BYTE v10[20]; // [esp+8h] [ebp-3Ch] BYREF
  int16_t v11; // [esp+1Ch] [ebp-28h]
  _WORD *v12; // [esp+20h] [ebp-24h]
  _WORD *v13; // [esp+24h] [ebp-20h]
  int v14; // [esp+28h] [ebp-1Ch]
  int v15; // [esp+2Ch] [ebp-18h]
  int v16; // [esp+30h] [ebp-14h]
  int v17; // [esp+34h] [ebp-10h]
  int v18; // [esp+38h] [ebp-Ch]
  int v20; // [esp+40h] [ebp-4h]

  v12 = (_WORD *)a1;
  v20 = a2;
  v17 = a3;
  v18 = a4;
  if ( (uint16_t)a4 < 0x64u )
    return -205;
  if ( (uint16_t)v20 > 0x15Eu || a5 == 2 )
    return sub_13DFBF(a6, (int)v12, v20, v17);
  v9[0] = 99;
  v9[1] = v20;
  v9[2] = word_189708;
  v9[3] = v17;
  v11 = v18;
  memcpy(v10, &byte_184654, 10);
  dword_1C3C48 = (uint16_t)v17;
  dword_1C3C54 = 0;
  v14 = dword_1C3C4C;
  v16 = 0;
  v13 = v9;
  memcpy(dword_1C3C4C, v9, 30);
  v16 += 30;
  if ( (uint16_t)v16 % 4 )
    v16 = 4 - (uint16_t)v16 % 4 + (uint16_t)v16;
  v13 = v12;
  v6 = (uint16_t)v20;
  v7 = (int)v12;
  memcpy(v14 + (uint16_t)v16, v12, (uint16_t)v20);
  v16 += v20;
  dword_1C3C50 = (uint16_t)v16;
  do
    v15 = sub_14F2F3(&dword_1C3C48, v7, v6);
  while ( v15 == 5 );
  if ( v15 == 1 )
    exit(1, v7);
  return 1;
}
// 13F35A: using guessed type int __fastcall memcpy(_DWORD, _DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 189708: using guessed type int16_t word_189708;
// 1C3C48: using guessed type int dword_1C3C48;
// 1C3C4C: using guessed type int dword_1C3C4C;
// 1C3C50: using guessed type int dword_1C3C50;
// 1C3C54: using guessed type int dword_1C3C54;


//----- (0014E1F2) --------------------------------------------------------
char __fastcall sub_14E1F2(int a1, int a2, int a3)
{
  int64_t v3; // rax
  uint16_t *v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  v7 = 40;
  v6 = -1;
  v3 = j___clock(a1, a2, a3);
  while ( (_WORD)--v7 != 0xFFFF )
  {
    LODWORD(v3) = sub_14F435((int)&unk_1C3C58);
    if ( (_DWORD)v3 != 3 )
      break;
    if ( v6 == -1 )
      v6 = 0;
    ++v6;
    v5 = (uint16_t *)dword_1C3C5C;
    WORD1(v3) = HIWORD(dword_1C3C5C);
    LOWORD(v3) = *(_WORD *)dword_1C3C5C;
    if ( *(_WORD *)dword_1C3C5C < 0x40u )
    {
LABEL_13:
      if ( *(_WORD *)(dword_1C3C5C + 4) == word_189708 )
      {
        LOBYTE(v3) = v6--;
      }
      else
      {
        sub_14E853(*(_WORD *)(dword_1C3C5C + 4), SHIDWORD(v3), a3);
        if ( v5[3] == 0x7FFF || (v3 = __PAIR64__(&byte_184654, strcmp(v5 + 4, &byte_184654)), !(_DWORD)v3) )
        {
          LODWORD(v3) = *v5;
          if ( (_DWORD)v3 == 99 )
            LOBYTE(v3) = sub_14E30F(v5);
        }
      }
    }
    else if ( (uint16_t)v3 <= 0x40u )
    {
      LOBYTE(v3) = sub_14E579(dword_1C3C5C, SHIDWORD(v3), a3);
    }
    else
    {
      if ( (_WORD)v3 != 66 )
        goto LABEL_13;
      LOBYTE(v3) = sub_14E46B(v3, SHIDWORD(v3), a3);
    }
  }
  return v3;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 189708: using guessed type int16_t word_189708;
// 1C3C5C: using guessed type int dword_1C3C5C;


//----- (0014E30F) --------------------------------------------------------
char __fastcall sub_14E30F(uint16_t *a1)
{
  if ( a1[2] == word_189708 )
    return 1;
  if ( a1[3] != 0x7FFF && a1[3] != 32766 && a1[3] != word_189708 )
    return 1;
  memcpy(dword_1C3C70, a1 + 16, a1[1]);
  if ( dword_1C3C68 )
    dword_1C3C68(a1[14], a1[1], dword_1C3C70);
  return 0;
}
// 13F35A: using guessed type int __fastcall memcpy(_DWORD, _DWORD, _DWORD);
// 189708: using guessed type int16_t word_189708;
// 1C3C68: using guessed type int (__fastcall *dword_1C3C68)(_DWORD, _DWORD, _DWORD);
// 1C3C70: using guessed type int dword_1C3C70;


//----- (0014E46B) --------------------------------------------------------
int __fastcall sub_14E46B(int a1, int a2, int a3)
{
  int64_t v3; // rax
  int v5; // [esp+4h] [ebp-4h]

  v3 = j___clock(a1, a2, a3);
  if ( (unsigned int)v3 >= dword_1C3C6C )
  {
    dword_1C3C6C = j___clock(v3, HIDWORD(v3), a3) + 100;
    v5 = dword_1C3C4C;
    memcpy(dword_1C3C4C + 8, &byte_184654, 10);
    *(_WORD *)(v5 + 4) = *(uint8_t *)dword_18970E;
    *(_WORD *)(v5 + 28) = dword_184650;
    *(_DWORD *)(v5 + 18) = dword_189714;
    *(_DWORD *)(v5 + 22) = dword_189718;
    *(_WORD *)(v5 + 26) = word_18971C;
    *(_WORD *)v5 = 64;
    HIDWORD(v3) = dword_1C3C7C;
    *(_DWORD *)(v5 + 30) = dword_1C3C7C;
    *(_WORD *)(v5 + 2) = 34;
    *(_WORD *)(v5 + 6) = 0x7FFF;
    dword_1C3C48 = 0x7FFF;
    dword_1C3C50 = *(uint16_t *)(v5 + 2);
    dword_1C3C54 = 0;
    do
      LODWORD(v3) = sub_14F2F3(&dword_1C3C48, SHIDWORD(v3), 10);
    while ( (_DWORD)v3 == 5 );
    if ( (_DWORD)v3 == 1 )
      exit(1, SHIDWORD(v3));
  }
  return v3;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 13F35A: using guessed type int __fastcall memcpy(_DWORD, _DWORD, _DWORD);
// 184650: using guessed type int dword_184650;
// 184654: using guessed type char byte_184654;
// 18970E: using guessed type int dword_18970E;
// 189714: using guessed type int dword_189714;
// 189718: using guessed type int dword_189718;
// 18971C: using guessed type int16_t word_18971C;
// 1C3C48: using guessed type int dword_1C3C48;
// 1C3C4C: using guessed type int dword_1C3C4C;
// 1C3C50: using guessed type int dword_1C3C50;
// 1C3C54: using guessed type int dword_1C3C54;
// 1C3C6C: using guessed type int dword_1C3C6C;
// 1C3C7C: using guessed type int dword_1C3C7C;


//----- (0014E579) --------------------------------------------------------
int __fastcall sub_14E579(int a1, int a2, int a3)
{
  uint8_t *v3; // eax
  int result; // eax
  int v5; // edx
  int v6; // eax
  uint8_t *v8; // [esp+4h] [ebp-4h]

  if ( *(_WORD *)(a1 + 4) == word_189708 )
  {
    result = *(_DWORD *)(a1 + 30);
    if ( result < (unsigned int)dword_1C3C7C )
    {
      v5 = dword_18970E;
      v6 = *(_DWORD *)(a1 + 30);
      *(_DWORD *)(dword_18970E + 26) = v6;
      *(_DWORD *)(dword_18970E + 22) = j___clock(v6, v5, a3);
      word_189708 = sub_14FD3B((uint16_t)word_189708);
      return sub_14FB47((uint16_t)word_189708, dword_1C3C7C, 0, (int)&byte_184654);
    }
  }
  else
  {
    v3 = sub_14E7F3(*(_WORD *)(a1 + 4));
    v8 = v3;
    if ( v3 )
    {
      *(_DWORD *)(v3 + 22) = j___clock(v3, a2, a3);
      strcpy(v8 + 2, a1 + 8);
      v8[1] = *(_BYTE *)(a1 + 28);
      result = *(uint16_t *)(a1 + 28);
      if ( result >= dword_184650 )
      {
        result = strcmp(&byte_184654, a1 + 8);
        if ( !result )
        {
          result = *(uint16_t *)(a1 + 28);
          dword_184650 = result;
        }
      }
    }
    else
    {
      return (int)sub_14F93A(
                    *(_WORD *)(a1 + 4),
                    *(_DWORD *)(a1 + 30),
                    *(uint16_t *)(a1 + 28),
                    a1 + 8,
                    *(_DWORD *)(a1 + 18),
                    *(_DWORD *)(a1 + 22),
                    HIWORD(*(_DWORD *)(a1 + 24)));
    }
  }
  return result;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 184650: using guessed type int dword_184650;
// 184654: using guessed type char byte_184654;
// 189708: using guessed type int16_t word_189708;
// 18970E: using guessed type int dword_18970E;
// 1C3C7C: using guessed type int dword_1C3C7C;


//----- (0014E6C8) --------------------------------------------------------
unsigned int __fastcall sub_14E6C8(int a1, int a2, int a3)
{
  unsigned int result; // eax
  int v4; // edx
  uint8_t *v5; // [esp+0h] [ebp-4h]

  v5 = (uint8_t *)dword_1C40EA;
  result = j___clock(dword_1C40EA, a2, a3);
  if ( result > dword_189174 + 3000 )
  {
    result = j___clock(result, dword_189174 + 3000, a3);
    dword_189174 = result;
    while ( v5 )
    {
      v4 = *v5;
      if ( v4 != (uint16_t)word_189708
        && (unsigned int)j___clock((uint16_t)word_189708, v4, a3) - *(_DWORD *)(v5 + 22) > 0x1770 )
      {
        sub_14FCB0(*v5);
      }
      result = *(_DWORD *)(v5 + 30);
      v5 = (uint8_t *)result;
    }
  }
  return result;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 189174: using guessed type int dword_189174;
// 189708: using guessed type int16_t word_189708;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0014E7F3) --------------------------------------------------------
uint8_t *__fastcall sub_14E7F3( int a1)
{
  uint8_t *i; // [esp+0h] [ebp-Ch]

  for ( i = (uint8_t *)dword_1C40EA; i; i = *(uint8_t **)(i + 30) )
  {
    if ( *i == a1 )
      return i;
  }
  return 0;
}
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0014E853) --------------------------------------------------------
int __fastcall sub_14E853( unsigned int a1, int a2, int a3)
{
  int result; // eax
  int v4; // edx
  int v5; // edx
  uint8_t *i; // [esp+0h] [ebp-8h]

  result = dword_1C40EA;
  for ( i = (uint8_t *)dword_1C40EA; i; i = (uint8_t *)result )
  {
    v4 = *i;
    if ( v4 == a1 )
    {
      v5 = j___clock(a1, v4, a3);
      result = (int)i;
      *(_DWORD *)(i + 22) = v5;
      return result;
    }
    result = *(_DWORD *)(i + 30);
  }
  return result;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0014E8B0) --------------------------------------------------------
char __fastcall sub_14E8B0(int a1, int a2, int a3, int a4)
{
  if ( !a1 )
    return 0;
  dword_1C3CBC = nmalloc(a1);
  dword_1C3CD4 = nmalloc(a1);
  dword_1C3CE0 = nmalloc(a1);
  if ( !dword_1C3CBC || !dword_1C3CE0 || !dword_1C3CD4 )
    return 0;
  dword_1C3CC8 = a1;
  byte_1896F8 = 1;
  dword_1C3CD8 = 0;
  sub_1527B0(dword_18497C, a2, a3, a4);
  dword_1896FE = 0;
  return 1;
}
// 13CB78: using guessed type int __fastcall nmalloc(_DWORD);
// 18497C: using guessed type int dword_18497C;
// 1896F8: using guessed type char byte_1896F8;
// 1896FE: using guessed type int dword_1896FE;
// 1C3CBC: using guessed type int dword_1C3CBC;
// 1C3CC8: using guessed type int dword_1C3CC8;
// 1C3CD4: using guessed type int dword_1C3CD4;
// 1C3CD8: using guessed type int dword_1C3CD8;
// 1C3CE0: using guessed type int dword_1C3CE0;


//----- (0014E961) --------------------------------------------------------
int sub_14E961()
{
  int result; // eax

  if ( dword_1C3CBC )
    result = nfree(dword_1C3CBC);
  dword_1C3CD8 = 0;
  dword_1C3CC8 = 0;
  byte_1896F8 = 0;
  return result;
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);
// 1896F8: using guessed type char byte_1896F8;
// 1C3CBC: using guessed type int dword_1C3CBC;
// 1C3CC8: using guessed type int dword_1C3CC8;
// 1C3CD8: using guessed type int dword_1C3CD8;


//----- (0014E9AE) --------------------------------------------------------
int __fastcall sub_14E9AE(int a1)
{
  char v2[2]; // [esp+0h] [ebp-1Ch] BYREF
  int v3; // [esp+2h] [ebp-1Ah]
  int v4; // [esp+6h] [ebp-16h]
  int v5; // [esp+Ah] [ebp-12h]
  int v6; // [esp+Eh] [ebp-Eh]
  int v7; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]

  v8 = a1;
  v2[0] = 101;
  v3 = 0;
  v4 = 1;
  v5 = 0;
  v6 = 0;
  v7 = a1;
  return (*(int (__fastcall **)(int, char *, int))(dword_18497C + 87))(dword_18497C, v2, 24);
}
// 18497C: using guessed type int dword_18497C;


//----- (0014EA0E) --------------------------------------------------------
int __fastcall sub_14EA0E(int a1)
{
  char v2[2]; // [esp+0h] [ebp-1Ch] BYREF
  int v3; // [esp+2h] [ebp-1Ah]
  int v4; // [esp+6h] [ebp-16h]
  int v5; // [esp+Ah] [ebp-12h]
  int v6; // [esp+Eh] [ebp-Eh]
  int v7; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]

  v8 = a1;
  v2[0] = 102;
  v3 = 0;
  v4 = 1;
  v5 = 0;
  v6 = 0;
  v7 = a1;
  return (*(int (__fastcall **)(int, char *, int))(dword_18497C + 87))(dword_18497C, v2, 24);
}
// 18497C: using guessed type int dword_18497C;


//----- (0014EA6E) --------------------------------------------------------
int __fastcall sub_14EA6E(int a1, unsigned int a2, int a3, unsigned int a4)
{
  int result; // eax

  if ( byte_184980 )
    return sub_14EAF4(a2, a3, a4);
  return result;
}
// 184980: using guessed type char byte_184980;


//----- (0014EAB2) --------------------------------------------------------
int sub_14EAB2()
{
  int v1; // [esp+0h] [ebp-8h]

  v1 = 4;
  if ( byte_1896F9 )
    return 6;
  return v1;
}
// 1896F9: using guessed type char byte_1896F9;


//----- (0014EAF4) --------------------------------------------------------
int __fastcall sub_14EAF4(int a1, int a2, int a3)
{
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  char v7; // [esp+0h] [ebp-3Ch] BYREF
  char v8; // [esp+1h] [ebp-3Bh]
  int v9; // [esp+2h] [ebp-3Ah]
  int v10; // [esp+6h] [ebp-36h]
  int v11; // [esp+Ah] [ebp-32h]
  int v12; // [esp+Eh] [ebp-2Eh]
  int16_t v13; // [esp+12h] [ebp-2Ah]
  int v14; // [esp+14h] [ebp-28h]
  int i; // [esp+18h] [ebp-24h]
  int v16; // [esp+1Ch] [ebp-20h]
  int v17; // [esp+20h] [ebp-1Ch]
  int v19; // [esp+28h] [ebp-14h] BYREF
  int j; // [esp+2Ch] [ebp-10h]
  int v21; // [esp+30h] [ebp-Ch]
  int v22; // [esp+34h] [ebp-8h]
  char v23; // [esp+38h] [ebp-4h]

  v22 = a1;
  v16 = a2;
  v21 = a3;
  v17 = a2;
  v19 = a3;
  if ( !a3 || !dword_18497C )
    return 0;
  if ( v21 < 256 )
  {
    memcpy(dword_1C3CE0, v17, v21);
    v8 = 0;
  }
  else
  {
    v19 = dword_1C3CC8;
    sub_15CA26(v17, v21, dword_1C3CE0, &v19);
    v8 = 1;
  }
  v17 = dword_1C3CE0;
  v21 = v19;
  dword_1C3CD0 = 0;
  dword_1C3CB4 = 0;
  dword_1C3CCC = v19;
  dword_1C3CB8 = 0;
  if ( v19 <= 512 )
  {
    dword_1C3CD0 = v21 % 512 > 0;
  }
  else
  {
    dword_1C3CD0 = (v21 - (__CFSHL__(v21 >> 31, 9) + (v21 >> 31 << 9))) >> 9;
    if ( v21 % 512 > 0 )
      ++dword_1C3CD0;
  }
  ++dword_1896FE;
  v23 = 0;
  while ( !v23 )
  {
    do
    {
      v7 = 100;
      v9 = dword_1C3CB8;
      v10 = dword_1C3CD0;
      v13 = v22;
      v14 = dword_1896FE;
      if ( dword_1C3CD0 - 1 == dword_1C3CB8 )
      {
        if ( v21 % 512 <= 0 )
          v11 = 512;
        else
          v11 = v21 % 512;
      }
      else
      {
        v11 = 512;
      }
      v12 = 0;
      for ( i = 0; i < v11; ++i )
        v12 += *(uint8_t *)(v17 + i + (v9 << 9));
      (*(void (__fastcall **)(int, char *, int))(dword_18497C + 87))(dword_18497C, &v7, 24);
      v3 = v11;
      (*(void (__fastcall **)(int, int, int))(dword_18497C + 87))(dword_18497C, v17 + (v9 << 9), v11);
      v4 = dword_18497C;
      v5 = (*(int (__fastcall **)(int))(dword_18497C + 71))(dword_18497C);
      for ( j = v5; j; j = v5 )
      {
        v4 = dword_18497C;
        v5 = (*(int (__fastcall **)(int))(dword_18497C + 71))(dword_18497C);
      }
    }
    while ( !sub_14ED47(v5, v4, v3) );
    if ( v10 - 1 == v9 )
      v23 = 1;
    ++dword_1C3CB8;
  }
  return 0;
}
// 13F35A: using guessed type int __fastcall memcpy(_DWORD, _DWORD, _DWORD);
// 18497C: using guessed type int dword_18497C;
// 1896FE: using guessed type int dword_1896FE;
// 1C3CB4: using guessed type int dword_1C3CB4;
// 1C3CB8: using guessed type int dword_1C3CB8;
// 1C3CC8: using guessed type int dword_1C3CC8;
// 1C3CCC: using guessed type int dword_1C3CCC;
// 1C3CD0: using guessed type int dword_1C3CD0;
// 1C3CE0: using guessed type int dword_1C3CE0;


//----- (0014ED47) --------------------------------------------------------
bool __fastcall sub_14ED47(int a1, int a2, int a3)
{
  byte_1C3C98 = 0;
  sub_14EE75(a1, a2, a3);
  return byte_1C3C98 == 101 && dword_1C3CAC == dword_1896FE;
}
// 1896FE: using guessed type int dword_1896FE;
// 1C3C98: using guessed type char byte_1C3C98;
// 1C3CAC: using guessed type int dword_1C3CAC;


//----- (0014EDD9) --------------------------------------------------------
void __fastcall sub_14EDD9(int a1, int a2, int a3)
{
  int v3; // edx
  unsigned int v4; // eax

  if ( byte_184980 && byte_1896F8 && (dword_1BD150 != 1 || sub_13CFDD()) )
  {
    v3 = dword_18497C;
    v4 = (*(int (__fastcall **)(int))(dword_18497C + 79))(dword_18497C);
    if ( v4 >= 0x18 )
    {
      sub_14EE75(v4, v3, a3);
      if ( dword_1896FA == 1 )
      {
        dword_1BF388(
          (uint8_t)byte_1BF38C,
          (uint16_t)dword_1C3CC4,
          (uint16_t)dword_1C3CD8,
          dword_1C3CBC);
        dword_1896FA = 0;
      }
    }
  }
}
// 18497C: using guessed type int dword_18497C;
// 184980: using guessed type char byte_184980;
// 1896F8: using guessed type char byte_1896F8;
// 1896FA: using guessed type int dword_1896FA;
// 1BD150: using guessed type int dword_1BD150;
// 1BF388: using guessed type int (__fastcall *dword_1BF388)(_DWORD, _DWORD, _DWORD, _DWORD);
// 1BF38C: using guessed type char byte_1BF38C;
// 1C3CBC: using guessed type int dword_1C3CBC;
// 1C3CC4: using guessed type int dword_1C3CC4;
// 1C3CD8: using guessed type int dword_1C3CD8;


//----- (0014EE75) --------------------------------------------------------
int __fastcall sub_14EE75(int a1, int a2, int a3)
{
  int v3; // edx
  int v4; // eax
  int v5; // ecx
  _BYTE v7[512]; // [esp+4h] [ebp-224h] BYREF
  int i; // [esp+204h] [ebp-24h]
  int v9; // [esp+208h] [ebp-20h]
  unsigned int v10; // [esp+20Ch] [ebp-1Ch]
  int v11; // [esp+210h] [ebp-18h] BYREF
  unsigned int v12; // [esp+214h] [ebp-14h]
  int v13; // [esp+218h] [ebp-10h]
  unsigned int v14; // [esp+21Ch] [ebp-Ch]
  char v16; // [esp+224h] [ebp-4h]

  v10 = 2000;
  v16 = 0;
  v13 = j___clock(a1, a2, a3);
  v14 = 0;
  do
  {
    v3 = dword_18497C;
    v4 = (*(int (__fastcall **)(int))(dword_18497C + 79))(dword_18497C);
    v12 = v4;
    if ( v4 == v14 )
    {
      if ( (unsigned int)j___clock(v4, v3, a3) - v13 >= v10 )
        return 0;
    }
    else
    {
      v13 = j___clock(v4, v3, a3);
      v14 = v12;
    }
  }
  while ( v12 < 0x18 );
  v5 = dword_18497C;
  (*(void (__fastcall **)(int, char *, int))(dword_18497C + 91))(dword_18497C, &byte_1C3C98, 24);
  if ( (uint8_t)byte_1C3C98 < 0x65u )
  {
    if ( byte_1C3C98 == 100 )
    {
      sprintf(v7, aTypeModemPacke);
      goto LABEL_17;
    }
  }
  else
  {
    if ( (uint8_t)byte_1C3C98 <= 0x65u )
    {
      sprintf(v7, aTypeModemRecei);
      goto LABEL_17;
    }
    if ( byte_1C3C98 == 102 )
    {
      sprintf(v7, aTypeModemRecei_0);
      goto LABEL_17;
    }
  }
  sprintf(v7, aClearingBuffer);
  sub_1527B0(dword_18497C, (int)&byte_1C3C98, 24, v5);
  fclose(dword_1C3CB0);
LABEL_17:
  sprintf(v7, "Receiving %d of %d\n", dword_1C3C9A, dword_1C3C9E - 1);
  if ( byte_1C3C98 == 100 )
  {
    while ( (*(int (__fastcall **)(int))(dword_18497C + 79))(dword_18497C) < dword_1C3CA2 )
      ;
    if ( !byte_1896F9 )
    {
      dword_1C3CC4 = (uint16_t)word_1C3CAA;
      byte_1896F9 = 1;
      dword_1C3CD8 = 0;
      dword_1C3CC0 = 0;
    }
    (*(void (__fastcall **)(int, int, int))(dword_18497C + 91))(
      dword_18497C,
      dword_1C3CD4 + (dword_1C3C9A << 9),
      dword_1C3CA2);
    dword_1C3CD8 += dword_1C3CA2;
    v16 = 1;
    v9 = 0;
    for ( i = 0; i < dword_1C3CA2; ++i )
      v9 += *(uint8_t *)((dword_1C3C9A << 9) + i + dword_1C3CD4);
    if ( v9 == dword_1C3CA6 )
    {
      if ( dword_1C3C9E - 1 == dword_1C3C9A )
      {
        byte_1896F9 = 0;
        if ( byte_1C3C99 == 1 )
        {
          sub_15CB10(dword_1C3CD4, dword_1C3CD8, dword_1C3CBC, &v11);
          sprintf(v7, "Decompressed from %d to %d\n", dword_1C3CD8, v11);
          dword_1C3CD8 = v11;
        }
        else
        {
          memcpy(dword_1C3CBC, dword_1C3CD4, dword_1C3CD8);
        }
        if ( dword_1C3CAC > (unsigned int)dword_189702 )
        {
          dword_1896FA = 1;
          dword_189702 = dword_1C3CAC;
        }
      }
      sub_14E9AE(dword_1C3CAC);
      ++dword_1C3CC0;
      return 1;
    }
    else
    {
      sub_14EA0E(dword_1C3CAC);
      return 1;
    }
  }
  else
  {
    v16 = 1;
    return 1;
  }
}
// 14EEAB: conditional instruction was optimized away because %var_4.1==0
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 13F35A: using guessed type int __fastcall memcpy(_DWORD, _DWORD, _DWORD);
// 18497C: using guessed type int dword_18497C;
// 1896F9: using guessed type char byte_1896F9;
// 1896FA: using guessed type int dword_1896FA;
// 189702: using guessed type int dword_189702;
// 1C3C98: using guessed type char byte_1C3C98;
// 1C3C99: using guessed type char byte_1C3C99;
// 1C3C9A: using guessed type int dword_1C3C9A;
// 1C3C9E: using guessed type int dword_1C3C9E;
// 1C3CA2: using guessed type int dword_1C3CA2;
// 1C3CA6: using guessed type int dword_1C3CA6;
// 1C3CAA: using guessed type int16_t word_1C3CAA;
// 1C3CAC: using guessed type int dword_1C3CAC;
// 1C3CB0: using guessed type int dword_1C3CB0;
// 1C3CBC: using guessed type int dword_1C3CBC;
// 1C3CC0: using guessed type int dword_1C3CC0;
// 1C3CC4: using guessed type int dword_1C3CC4;
// 1C3CD4: using guessed type int dword_1C3CD4;
// 1C3CD8: using guessed type int dword_1C3CD8;


//----- (0014F19F) --------------------------------------------------------
int __fastcall sub_14F19F(int *a1, char *a2, int a3)
{
  int v3; // eax
  int v4; // eax
  char v6[120]; // [esp+0h] [ebp-80h] BYREF
  int *v7; // [esp+78h] [ebp-8h]

  v7 = a1;
  if ( !byte_189713 )
  {
    strcpy(v6, "rkernel.com");
    if ( !sub_11181C((int)aRkernelCom) )
    {
      strcpy(v6, byte_184544);
      a2 = aRkernelCom;
      strcat(v6, aRkernelCom);
      if ( !sub_11181C((int)v6) )
        sub_126487(aRkernelComNotF, (int)aRkernelCom);
    }
    dword_18AC7A = (int)v6;
    sub_14FEE6((int)v6);
    dword_18AC86 = 0;
    sub_15DBCA();
    sub_15DCEE();
    sub_15DD1A();
    dword_18AC86 = 1;
    sub_15DBCA();
  }
  do
    v3 = sub_14F435((int)&unk_1C3C58);
  while ( v3 == 3 );
  byte_1C40EE = 1;
  word_1C40E8 = 0;
  dword_1C40EA = 0;
  v4 = sub_14F591(v3, (int)a2, a3);
  *v7 = v4;
  byte_1C40EE = 0;
  return 0;
}
// 13F220: using guessed type int __fastcall strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 189713: using guessed type char byte_189713;
// 18AC7A: using guessed type int dword_18AC7A;
// 18AC86: using guessed type int dword_18AC86;
// 1C40E8: using guessed type int16_t word_1C40E8;
// 1C40EA: using guessed type int dword_1C40EA;
// 1C40EE: using guessed type char byte_1C40EE;


//----- (0014F297) --------------------------------------------------------
int __fastcall sub_14F297(int *a1, char *a2, int a3)
{
  if ( !byte_189712 )
    return 0;
  if ( byte_189712 == 1 )
    return sub_14F19F(a1, a2, a3);
  return 0;
}
// 189712: using guessed type char byte_189712;


//----- (0014F2F3) --------------------------------------------------------
int __fastcall sub_14F2F3(_DWORD *a1, int a2, int a3)
{
  int v3; // eax
  int v5; // [esp+0h] [ebp-18h]
  uint8_t *v6; // [esp+4h] [ebp-14h]

  if ( !a1 )
    return -2;
  v3 = a1[2] + 4;
  dword_18ACC0 = a1[2] + 4;
  if ( dword_18ACC0 > 500 )
    return -2;
  j___clock(v3, a2, a3);
  if ( byte_189712 == 1 )
  {
    v5 = 0;
    v6 = (uint8_t *)dword_1C40EA;
    dword_18AC8A = 0;
    dword_18AC8E = -1;
    word_18AC92 = -1;
    if ( *a1 != 0x7FFF && *a1 != 32766 )
    {
      while ( v6 )
      {
        if ( !strcmp(v6 + 2, &byte_184654) )
        {
          if ( *v6 == *a1 )
          {
            dword_18AC8A = *((_DWORD *)v6 + 3);
            dword_18AC8E = *((_DWORD *)v6 + 4);
            word_18AC92 = *((_WORD *)v6 + 10);
            break;
          }
          ++v5;
        }
        v6 = *(uint8_t **)(v6 + 30);
      }
    }
    dword_18ACBC = a1[1];
    sub_15DD55();
    dword_18AC86 = 2;
    sub_15DBCA();
  }
  return 0;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 189712: using guessed type char byte_189712;
// 18AC86: using guessed type int dword_18AC86;
// 18AC8A: using guessed type int dword_18AC8A;
// 18AC8E: using guessed type int dword_18AC8E;
// 18AC92: using guessed type int16_t word_18AC92;
// 18ACBC: using guessed type int dword_18ACBC;
// 18ACC0: using guessed type int dword_18ACC0;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0014F435) --------------------------------------------------------
int __fastcall sub_14F435(int a1)
{
  int v3; // [esp+4h] [ebp-10h]

  v3 = 2000;
  if ( byte_189712 == 1 )
    v3 = sub_15DDE1();
  if ( v3 || byte_189712 != 1 )
    return 0;
  dword_18ACBC = *(_DWORD *)(a1 + 4);
  if ( !sub_15DE09() )
    return 0;
  *(_DWORD *)(a1 + 8) = dword_18ACC0;
  return 3;
}
// 189712: using guessed type char byte_189712;
// 18ACBC: using guessed type int dword_18ACBC;
// 18ACC0: using guessed type int dword_18ACC0;


//----- (0014F4CE) --------------------------------------------------------
int sub_14F4CE()
{
  _DWORD v1[3]; // [esp+0h] [ebp-28h] BYREF
  int16_t v2; // [esp+Ch] [ebp-1Ch]
  int v3; // [esp+18h] [ebp-10h]
  int v4; // [esp+1Ch] [ebp-Ch]
  int v5; // [esp+20h] [ebp-8h]

  v5 = dword_1C40EA;
  v4 = dword_1C40EA;
  if ( byte_189713 )
  {
    dword_18AC86 = 3;
    sub_15DBCA();
    byte_189713 = 0;
    memset(v1, 0, 28);
    v1[0] = 257;
    v2 = word_18AC84;
    int386(49, v1, v1);
    if ( v3 )
      sub_126487(aMemoryReleaseE, (int)v1);
  }
  while ( v5 )
  {
    v4 = *(_DWORD *)(v5 + 30);
    nfree(v5);
    v5 = v4;
  }
  dword_1C40EA = 0;
  return 0;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 189713: using guessed type char byte_189713;
// 18AC84: using guessed type int16_t word_18AC84;
// 18AC86: using guessed type int dword_18AC86;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0014F591) --------------------------------------------------------
int __fastcall sub_14F591(int a1, int a2, int a3)
{
  int64_t v3; // rax
  int64_t v4; // rax
  int64_t v5; // rax
  int v7; // [esp+8h] [ebp-34h]
  int v8; // [esp+Ch] [ebp-30h]
  int v9; // [esp+10h] [ebp-2Ch]
  int v10; // [esp+18h] [ebp-24h]
  int v11; // [esp+1Ch] [ebp-20h]
  int v12; // [esp+2Ch] [ebp-10h]
  uint16_t v13; // [esp+38h] [ebp-4h]

  v10 = 0;
  v3 = j___clock(a1, a2, a3);
  v11 = v3;
  v4 = j___clock(v3, HIDWORD(v3), a3);
  while ( 1 )
  {
    LODWORD(v4) = j___clock(v4, HIDWORD(v4), a3);
    HIDWORD(v4) = v11 + 500;
    if ( (unsigned int)v4 >= v11 + 500 )
      break;
    LODWORD(v4) = sub_14F435((int)&unk_1C3C58);
    if ( (_DWORD)v4 == 3 )
    {
      LODWORD(v4) = *(uint16_t *)dword_1C3C5C;
      if ( (_DWORD)v4 == 64 )
      {
        v9 = dword_1C3C5C;
        a3 = *(uint16_t *)(dword_1C3C5C + 28);
        HIDWORD(v4) = *(_DWORD *)(dword_1C3C5C + 30);
        sub_14F93A(
          *(_WORD *)(dword_1C3C5C + 4),
          SHIDWORD(v4),
          (uint16_t)a3,
          dword_1C3C5C + 8,
          *(_DWORD *)(dword_1C3C5C + 18),
          *(_DWORD *)(dword_1C3C5C + 22),
          HIWORD(*(_DWORD *)(dword_1C3C5C + 24)));
        LODWORD(v4) = *(_DWORD *)(v9 + 30);
        if ( (_DWORD)v4 == dword_1C3C7C )
          ++dword_1C3C7C;
      }
    }
  }
  v13 = sub_14FD3B(0);
  LODWORD(v4) = v13;
  if ( v13 > 0x40u )
    _assert(0, aTempstationidN, aNetNetC, 426);
  v5 = j___clock(v4, HIDWORD(v4), a3);
  v12 = v5;
  while ( v10 < 5 )
  {
    LODWORD(v5) = sub_14F435((int)&unk_1C3C58);
    if ( (_DWORD)v5 == 3 )
    {
      v8 = dword_1C3C5C;
      if ( *(_WORD *)dword_1C3C5C == 64 )
      {
        a3 = 0;
        HIDWORD(v5) = *(_DWORD *)(dword_1C3C5C + 30);
        sub_14F93A(
          *(_WORD *)(dword_1C3C5C + 4),
          SHIDWORD(v5),
          0,
          dword_1C3C5C + 8,
          *(_DWORD *)(dword_1C3C5C + 18),
          *(_DWORD *)(dword_1C3C5C + 22),
          HIWORD(*(_DWORD *)(dword_1C3C5C + 24)));
        WORD1(v5) = HIWORD(v8);
        LOWORD(v5) = *(_WORD *)(v8 + 4);
        if ( (_WORD)v5 == v13 )
        {
          v10 = 0;
          v13 = sub_14FD3B(v13);
          LODWORD(v5) = v13;
          if ( v13 > 0x40u )
            _assert(0, a0_1, aNetNetC, 452);
        }
      }
      else
      {
        LODWORD(v5) = *(uint16_t *)dword_1C3C5C;
        if ( (_DWORD)v5 == 67 )
        {
          WORD1(v5) = HIWORD(dword_1C3C5C);
          LOWORD(v5) = *(_WORD *)(dword_1C3C5C + 32);
          if ( (_WORD)v5 == v13 )
          {
            v7 = *(_DWORD *)(dword_1C3C5C + 28);
            LODWORD(v5) = v7;
            if ( v7 != dword_1C3C7C )
            {
              LODWORD(v5) = *(_DWORD *)(dword_1C3C5C + 28);
              if ( v7 < dword_1C3C7C )
              {
                v10 = 0;
                v13 = sub_14FD3B(v13);
                LODWORD(v5) = v13;
                if ( v13 > 0x40u )
                  _assert(0, a0_1, aNetNetC, 475);
              }
            }
          }
        }
      }
    }
    v5 = j___clock(v5, HIDWORD(v5), a3);
    if ( (unsigned int)(v5 - v12) > 0x32 )
    {
      v12 = v5;
      ++v10;
      sub_14F887(v13);
    }
  }
  sub_14FB47(v13, dword_1C3C7C, 0, (int)&byte_184654);
  return v13;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 15DF24: using guessed type void __fastcall __noreturn _assert(_DWORD, _DWORD, _DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 1C3C5C: using guessed type int dword_1C3C5C;
// 1C3C7C: using guessed type int dword_1C3C7C;


//----- (0014F887) --------------------------------------------------------
int __fastcall sub_14F887(int a1)
{
  _DWORD v2[2]; // [esp+0h] [ebp-10h] BYREF
  int v3; // [esp+8h] [ebp-8h]

  v2[0] = a1;
  v3 = dword_1C3C4C;
  *(_WORD *)dword_1C3C4C = 67;
  *(_WORD *)(v3 + 2) = 36;
  *(_WORD *)(v3 + 4) = -1;
  dword_1C3C48 = 0x7FFF;
  dword_1C3C50 = *(uint16_t *)(v3 + 2);
  dword_1C3C54 = 0;
  memcpy(v3 + 28, &dword_1C3C7C, 4);
  v2[1] = v3 + 32;
  memcpy(v3 + 32, v2, 4);
  while ( sub_14F2F3(&dword_1C3C48, (int)v2, 4) == 5 )
    ;
  return 0;
}
// 13F35A: using guessed type int __fastcall memcpy(_DWORD, _DWORD, _DWORD);
// 1C3C48: using guessed type int dword_1C3C48;
// 1C3C4C: using guessed type int dword_1C3C4C;
// 1C3C50: using guessed type int dword_1C3C50;
// 1C3C54: using guessed type int dword_1C3C54;
// 1C3C7C: using guessed type int dword_1C3C7C;


//----- (0014F93A) --------------------------------------------------------
uint8_t *__fastcall sub_14F93A( unsigned int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // edx
  uint8_t *result; // eax
  int v9; // edx
  int v10; // [esp+0h] [ebp-20h]
  uint8_t *i; // [esp+8h] [ebp-18h]
  int v12; // [esp+8h] [ebp-18h]
  int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-Ch]
  char v17; // [esp+18h] [ebp-8h]

  v17 = a1;
  v10 = a2;
  v15 = dword_1C40EA;
  if ( dword_1C40EA )
  {
    for ( i = (uint8_t *)dword_1C40EA; i; i = *(uint8_t **)(i + 30) )
    {
      a2 = *i;
      if ( a2 == a1 )
      {
        v9 = j___clock(a1, a2, a3);
        result = i;
        *(_DWORD *)(i + 22) = v9;
        return result;
      }
    }
    v12 = nmalloc(34);
    if ( !v12 )
      exit(1, a2);
    *(_DWORD *)(v12 + 30) = 0;
    *(_BYTE *)v12 = v17;
    *(_BYTE *)(v12 + 1) = a3;
    *(_DWORD *)(v12 + 12) = a5;
    *(_DWORD *)(v12 + 16) = a6;
    *(_WORD *)(v12 + 20) = a7;
    strcpy(v12 + 2, a4);
    *(_DWORD *)(v12 + 26) = v10;
    *(_DWORD *)(v12 + 22) = j___clock(v10, v12, a3);
    ++word_1C40E8;
    result = (uint8_t *)v15;
    if ( *(_BYTE *)v12 >= *(_BYTE *)v15 )
    {
      v14 = 0;
      while ( !v14 )
      {
        if ( *(_DWORD *)(v15 + 30) )
        {
          if ( *(_BYTE *)v12 < **(_BYTE **)(v15 + 30) )
          {
            v13 = *(_DWORD *)(v15 + 30);
            *(_DWORD *)(v15 + 30) = v12;
            *(_DWORD *)(v12 + 30) = v13;
            v14 = 1;
          }
        }
        else
        {
          *(_DWORD *)(v15 + 30) = v12;
          v14 = 1;
        }
        result = *(uint8_t **)(v15 + 30);
        v15 = (int)result;
      }
    }
    else
    {
      *(_DWORD *)(v12 + 30) = v15;
      result = (uint8_t *)v12;
      dword_1C40EA = v12;
    }
  }
  else
  {
    dword_1C40EA = nmalloc(34);
    if ( !dword_1C40EA )
      exit(1, a2);
    v16 = dword_1C40EA;
    *(_DWORD *)(dword_1C40EA + 30) = 0;
    *(_BYTE *)v16 = v17;
    *(_BYTE *)(v16 + 1) = a3;
    strcpy(v16 + 2, a4);
    *(_DWORD *)(v16 + 12) = a5;
    *(_DWORD *)(v16 + 16) = a6;
    *(_WORD *)(v16 + 20) = a7;
    *(_DWORD *)(v16 + 26) = a2;
    v7 = j___clock(a2, v16, a3);
    result = (uint8_t *)v16;
    *(_DWORD *)(v16 + 22) = v7;
    word_1C40E8 = 1;
  }
  return result;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 13CB78: using guessed type int __fastcall nmalloc(_DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 1C40E8: using guessed type int16_t word_1C40E8;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0014FB47) --------------------------------------------------------
int __fastcall sub_14FB47(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // [esp+0h] [ebp-2Ch]
  int v6; // [esp+8h] [ebp-24h]
  int v7; // [esp+10h] [ebp-1Ch]
  int v8; // [esp+14h] [ebp-18h] BYREF
  int v9; // [esp+18h] [ebp-14h]
  _DWORD v10[2]; // [esp+1Ch] [ebp-10h] BYREF
  int v11; // [esp+24h] [ebp-8h]
  int v12; // [esp+28h] [ebp-4h] BYREF

  v11 = a1;
  v10[1] = a3;
  v9 = dword_1C40EA;
  v7 = nmalloc(34);
  if ( !v7 )
    exit(1, a2);
  sub_14FDC5(&v8, v10, &v12);
  dword_189714 = v8;
  dword_189718 = v10[0];
  word_18971C = v12;
  dword_18970E = v7;
  *(_DWORD *)(v7 + 30) = 0;
  *(_BYTE *)v7 = v11;
  *(_BYTE *)(v7 + 1) = dword_184650;
  *(_DWORD *)(v7 + 12) = v8;
  *(_DWORD *)(v7 + 16) = v10[0];
  *(_WORD *)(v7 + 20) = v12;
  strcpy(v7 + 2, a4);
  *(_DWORD *)(v7 + 26) = a2;
  ++word_1C40E8;
  if ( v9 )
  {
    result = v9;
    if ( *(_BYTE *)v7 >= *(_BYTE *)v9 )
    {
      v6 = 0;
      while ( !v6 )
      {
        if ( *(_DWORD *)(v9 + 30) )
        {
          if ( *(_BYTE *)v7 < **(_BYTE **)(v9 + 30) )
          {
            v5 = *(_DWORD *)(v9 + 30);
            *(_DWORD *)(v9 + 30) = v7;
            *(_DWORD *)(v7 + 30) = v5;
            v6 = 1;
          }
        }
        else
        {
          *(_DWORD *)(v9 + 30) = v7;
          v6 = 1;
        }
        result = *(_DWORD *)(v9 + 30);
        v9 = result;
      }
    }
    else
    {
      *(_DWORD *)(v7 + 30) = v9;
      result = v7;
      dword_1C40EA = v7;
    }
  }
  else
  {
    result = v7;
    dword_1C40EA = v7;
  }
  return result;
}
// 13CB78: using guessed type int __fastcall nmalloc(_DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 184650: using guessed type int dword_184650;
// 18970E: using guessed type int dword_18970E;
// 189714: using guessed type int dword_189714;
// 189718: using guessed type int dword_189718;
// 18971C: using guessed type int16_t word_18971C;
// 1C40E8: using guessed type int16_t word_1C40E8;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0014FCB0) --------------------------------------------------------
int __fastcall sub_14FCB0( int a1)
{
  int result; // eax
  uint8_t *v2; // [esp+0h] [ebp-Ch]
  uint8_t *v3; // [esp+4h] [ebp-8h]

  result = dword_1C40EA;
  v2 = (uint8_t *)dword_1C40EA;
  v3 = 0;
  while ( v2 )
  {
    if ( *v2 == a1 )
    {
      if ( v3 )
        *(_DWORD *)(v3 + 30) = *(_DWORD *)(v2 + 30);
      else
        dword_1C40EA = *(_DWORD *)(v2 + 30);
      result = nfree(v2);
      --word_1C40E8;
      return result;
    }
    v3 = v2;
    result = *(_DWORD *)(v2 + 30);
    v2 = (uint8_t *)result;
  }
  return result;
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);
// 1C40E8: using guessed type int16_t word_1C40E8;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0014FD3B) --------------------------------------------------------
int __fastcall sub_14FD3B(int a1)
{
  uint8_t *v2; // [esp+0h] [ebp-10h]
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]

  for ( i = a1 + 1; (uint16_t)i <= 0x40u; ++i )
  {
    v2 = (uint8_t *)dword_1C40EA;
    if ( !dword_1C40EA )
      break;
    v3 = 0;
    while ( v2 )
    {
      if ( *v2 == (uint16_t)i )
        v3 = 1;
      v2 = *(uint8_t **)(v2 + 30);
    }
    if ( !v3 )
      break;
  }
  return i;
}
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0014FDC5) --------------------------------------------------------
int __fastcall sub_14FDC5(_DWORD *a1, _DWORD *a2, _WORD *a3)
{
  int result; // eax
  int v4; // edx
  _BYTE v5[4]; // [esp+0h] [ebp-48h] BYREF
  int v6; // [esp+4h] [ebp-44h]
  int v7; // [esp+10h] [ebp-38h]
  int v8; // [esp+1Ch] [ebp-2Ch]
  int16_t v9; // [esp+22h] [ebp-26h]
  _DWORD *v10; // [esp+34h] [ebp-14h]
  _WORD *v11; // [esp+38h] [ebp-10h]
  _DWORD *v12; // [esp+3Ch] [ebp-Ch]
  int v13; // [esp+40h] [ebp-8h]
  _WORD *v14; // [esp+44h] [ebp-4h]

  v12 = a1;
  v10 = a2;
  v11 = a3;
  memset(&dword_1BB8E0, 0, 28);
  memset(&unk_1BB8C4, 0, 28);
  memset(v5, 0, 50);
  memset(dword_1B06FC, 0, 100);
  v8 = 0;
  v7 = 9;
  v9 = dword_1B06F8;
  v6 = 0;
  LOWORD(dword_1BB8E0) = 768;
  LOWORD(dword_1BB8E4) = 122;
  LOWORD(dword_1BB8E8) = 0;
  word_1BBA1C[0] = __SS__;
  dword_1BB8F4 = (int)v5;
  int386x(49, &dword_1BB8E0);
  v13 = dword_1B06FC;
  v14 = (_WORD *)(dword_1B06FC + 8);
  *v12 = *(_DWORD *)dword_1B06FC;
  *v10 = *(_DWORD *)(v13 + 4);
  HIWORD(result) = HIWORD(v14);
  LOWORD(result) = *v14;
  v4 = (int)v11;
  *v11 = *v14;
  if ( (_BYTE)v8 )
    sub_126487(aErrorGettingLo, v4);
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 144A4A: using guessed type int __fastcall int386x(_DWORD, _DWORD);
// 1B06F8: using guessed type int dword_1B06F8;
// 1B06FC: using guessed type int dword_1B06FC;
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8F4: using guessed type int dword_1BB8F4;
// 1BBA1C: using guessed type int16_t word_1BBA1C;


//----- (0014FEE6) --------------------------------------------------------
int __fastcall sub_14FEE6(int a1)
{
  int result; // eax
  _DWORD v2[3]; // [esp+0h] [ebp-50h] BYREF
  int v3; // [esp+Ch] [ebp-44h]
  int v4; // [esp+18h] [ebp-38h]
  _DWORD v5[7]; // [esp+1Ch] [ebp-34h] BYREF
  int v6; // [esp+38h] [ebp-18h]
  int v7; // [esp+3Ch] [ebp-14h]
  int v8; // [esp+44h] [ebp-Ch]
  int v9; // [esp+48h] [ebp-8h]
  int v10; // [esp+4Ch] [ebp-4h]

  v7 = a1;
      // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    v6 = fopen(a1, aRb);
  if ( !v6 )
    sub_126487(aCanTFindRkerne, (int)aRb_7);
    // DECOMP_TODO (vyreseno ve vlne 07): klasicky "zjisti velikost souboru"
    // idiom - fseek(f,0,SEEK_END); size=ftell(f); fseek(f,0,SEEK_SET); - byl
    // rozbity na 3 mista: dve prazdna fseek() a "ftell(v6,0,2)" se 3 parametry
    // (spravny ftell bere jen 1 arg - ty dalsi 2 jsou zbytky z fseek(v6,0,2)
    // volani, ktere Hex-Rays chybne pripsal k ftell). Vsechny 3 pouzivaji
    // stejny handle v6.
  fseek(v6, 0, SEEK_END);
  v8 = ftell(v6);
  dword_18AC7E = v8;
  fseek(v6, 0, SEEK_SET);
  v5[0] = 256;
  v5[1] = ((v8 + 256) >> 4) + 1;
  int386(49, v5, v2);
  if ( v4 )
    sub_126487(aErrorDpmiInt0x, (int)v5);
  v9 = 16 * LOWORD(v2[0]);
  if ( !v9 )
  {
    sub_13E186((int)aNullBuffer, v2[0]);
    sub_126487(aNullBuffer, (int)v5);
  }
  word_18AC82 = v2[0];
  v10 = v3;
  word_18AC84 = v3;
  memset(v9, 0, 256);
  fread(v9 + 256, v8, 1, v6);
  result = fclose(v6);
  byte_189713 = 1;
  return result;
}
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 147449: using guessed type int __fastcall ftell(_DWORD, _DWORD, _DWORD);
// 189713: using guessed type char byte_189713;
// 18AC7E: using guessed type int dword_18AC7E;
// 18AC82: using guessed type int16_t word_18AC82;
// 18AC84: using guessed type int16_t word_18AC84;


//----- (0015001F) --------------------------------------------------------
int __fastcall sub_15001F(int a1)
{
  _BYTE v2[256]; // [esp+0h] [ebp-11Ch]
  int v3; // [esp+100h] [ebp-1Ch]
  int i; // [esp+104h] [ebp-18h]
  int v5; // [esp+108h] [ebp-14h]
  int v6; // [esp+110h] [ebp-Ch] BYREF
  int v7; // [esp+118h] [ebp-4h] BYREF

  v5 = a1;
  strcpy(byte_1C8358, a1);
  for ( i = 0; i < 12 && byte_1C8358[i]; ++i )
  {
    if ( byte_1C8358[i] == 46 )
      byte_1C8358[i] = 0;
  }
  strcat(byte_1C8358, aLbx_0);
  for ( i = 0; i < 256; ++i )
    v2[i] = 0;
  v3 = fopen(v5, aWb_7);
  v6 = 0;
  fwrite(&v6, 2, 1, v3);
  v7 = 65197;
  fwrite(&v7, 2, 1, v3);
  fwrite(&unk_1C40F0, 2, 1, v3);
  fwrite(&unk_1C40F0, 2, 1, v3);
  HIWORD(dword_1C83BC) = 0;
  fwrite(&unk_1C40F0, 2040, 1, v3);
  LOWORD(dword_1C83BC) = v6;
  return fclose(v3);
}
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);
// 13F220: using guessed type int __fastcall strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 1C83BC: using guessed type int dword_1C83BC;


//----- (00151D1F) --------------------------------------------------------
int sub_151D1F()
{
  return 0;
}


//----- (00151D54) --------------------------------------------------------
int __fastcall sub_151D54(char *a1, int a2)
{
  int v3; // ebp
  char *v4; // esi
  char *v5; // edi
  char v6; // al
  char v7; // al

  v3 = sub_15E124();
  v4 = (char *)v3;
  itoa(a2, v3, 10, a2);
  v5 = (char *)&a1[strlen(a1)];
  do
  {
    v6 = *v4;
    *v5 = *v4;
    if ( !v6 )
      break;
    v7 = v4[1];
    v4 += 2;
    v5[1] = v7;
    v5 += 2;
  }
  while ( v7 );
  return j__nfree(v3);
}
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 15E134: using guessed type int __fastcall j__nfree(_DWORD);


//----- (00151DA8) --------------------------------------------------------
int __fastcall sub_151DA8(int a1, int a2, int a3)
{
  int v4; // edx
  char *v5; // ebp
  char *v6; // esi
  char *v7; // edi
  char v8; // al
  char v9; // al
  char *v10; // esi
  unsigned int v11; // kr08_4
  char *v12; // edi
  char v13; // al
  char v14; // al
  char *v15; // esi
  char *v16; // edi
  char v17; // al
  char v18; // al
  int v19; // edx
  int v21; // [esp+0h] [ebp-1Ch]
  int v22; // [esp+0h] [ebp-1Ch]

  v4 = dword_17C21C;
  v5 = (char *)sub_15E124();
  *(_DWORD *)v5 = v4;
  v21 = sub_15E124();
  v6 = (char *)v21;
  itoa(a2, v21, 10, a2);
  v7 = &v5[strlen(v5)];
  do
  {
    v8 = *v6;
    *v7 = *v6;
    if ( !v8 )
      break;
    v9 = v6[1];
    v6 += 2;
    v7[1] = v9;
    v7 += 2;
  }
  while ( v9 );
  v10 = (char *)&unk_17C220;
  j__nfree(v21);
  v11 = strlen(v5) + 1;
  v12 = &v5[v11 - 1];
  do
  {
    v13 = *v10;
    *v12 = *v10;
    if ( !v13 )
      break;
    v14 = v10[1];
    v10 += 2;
    v12[1] = v14;
    v12 += 2;
  }
  while ( v14 );
  v22 = sub_15E124();
  v15 = (char *)v22;
  itoa(a3, v22, 10, ~v11);
  v16 = &v5[strlen(v5)];
  do
  {
    v17 = *v15;
    *v16 = *v15;
    if ( !v17 )
      break;
    v18 = v15[1];
    v15 += 2;
    v16[1] = v18;
    v16 += 2;
  }
  while ( v18 );
  j__nfree(v22);
  v19 = sub_1523FC(a1, v5);
  j__nfree(v5);
  if ( v19 >= 0 )
    return 0;
  return v19;
}
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 15E134: using guessed type int __fastcall j__nfree(_DWORD);
// 17C21C: using guessed type int dword_17C21C;


//----- (00151EC8) --------------------------------------------------------
int __fastcall sub_151EC8(int a1, unsigned int a2)
{
  return sub_151DA8(a1, 2, a2);
}


//----- (00151EDC) --------------------------------------------------------
int __fastcall sub_151EDC(int a1, unsigned int a2)
{
  return sub_151DA8(a1, 3, a2);
}


//----- (00151EF0) --------------------------------------------------------
int __fastcall sub_151EF0(int a1, unsigned int a2)
{
  return sub_151DA8(a1, 4, a2);
}


//----- (00151F04) --------------------------------------------------------
int __fastcall sub_151F04(int a1, unsigned int a2)
{
  return sub_151DA8(a1, 5, a2);
}


//----- (00151F18) --------------------------------------------------------
int __fastcall sub_151F18(int a1, int a2)
{
  return sub_151DA8(a1, 6, a2);
}


//----- (00151F28) --------------------------------------------------------
int __fastcall sub_151F28(int a1, int a2)
{
  return sub_151DA8(a1, 7, a2);
}


//----- (00151F38) --------------------------------------------------------
int __fastcall sub_151F38(int a1, int a2)
{
  return sub_151DA8(a1, 8, a2);
}


//----- (00151F48) --------------------------------------------------------
int __fastcall sub_151F48(int a1, int a2)
{
  return sub_151DA8(a1, 9, a2);
}


//----- (00151F58) --------------------------------------------------------
int __fastcall sub_151F58(int a1, int a2)
{
  return sub_151DA8(a1, 10, a2);
}


//----- (00151F68) --------------------------------------------------------
int __fastcall sub_151F68(int a1, int a2)
{
  return sub_151DA8(a1, 11, a2);
}


//----- (00151F78) --------------------------------------------------------
int __fastcall sub_151F78(int a1, int a2)
{
  return sub_151DA8(a1, 12, a2);
}


//----- (00151FB8) --------------------------------------------------------
int __fastcall sub_151FB8(int a1)
{
  int result; // eax

  result = sub_1524D0(a1, "ATO", 13);
  if ( result >= 0 )
    return 0;
  return result;
}


//----- (00151FD4) --------------------------------------------------------
int __fastcall sub_151FD4(int a1, unsigned int a2)
{
  if ( !a1 )
    return -7;
  if ( a2 <= 2 )
  {
    *(_DWORD *)(a1 + 19) = a2;
    return 0;
  }
  else
  {
    *(_DWORD *)(a1 + 14) = -7;
    return *(_DWORD *)(a1 + 14);
  }
}


//----- (00151FF8) --------------------------------------------------------
int __fastcall sub_151FF8(int a1, char *a2)
{
  char *v2; // edi
  char *v3; // ebp
  int v4; // ebx
  char *v6; // edi
  char v7; // al
  char v8; // al
  int v9; // edi

  v2 = (char *)sub_15E124();
  v3 = v2;
  v4 = *(_DWORD *)(a1 + 19);
  if ( v4 == 1 )
  {
    strcpy(v2, "ATDP");
  }
  else if ( v4 )
  {
    *(_DWORD *)v2 = dword_17C238;
  }
  else
  {
    strcpy(v2, "ATDT");
  }
  v6 = &v2[strlen(v2)];
  do
  {
    v7 = *a2;
    *v6 = *a2;
    if ( !v7 )
      break;
    v8 = a2[1];
    a2 += 2;
    v6[1] = v8;
    v6 += 2;
  }
  while ( v8 );
  v9 = sub_1524D0(a1, v3, 13);
  j__nfree(v3);
  if ( v9 >= 0 )
    return 0;
  return v9;
}
// 15E134: using guessed type int __fastcall j__nfree(_DWORD);
// 17C238: using guessed type int dword_17C238;


//----- (00152088) --------------------------------------------------------
int __fastcall sub_152088(int a1)
{
  int result; // eax

  result = sub_1524D0(a1, "A/", -1);
  if ( result >= 0 )
    return 0;
  return result;
}


//----- (001520A4) --------------------------------------------------------
int __fastcall sub_1520A4(int a1, char *a2)
{
  char *v2; // edi
  char *v3; // ebp
  int v4; // ebx
  char *v6; // edi
  char v7; // al
  char v8; // al
  char *v9; // esi
  char *v10; // edi
  char v11; // al
  char v12; // al
  int v13; // edi

  v2 = (char *)sub_15E124();
  v3 = v2;
  v4 = *(_DWORD *)(a1 + 19);
  if ( v4 == 1 )
  {
    strcpy(v2, "ATDP");
  }
  else if ( v4 )
  {
    *(_DWORD *)v2 = dword_17C238;
  }
  else
  {
    strcpy(v2, "ATDT");
  }
  v6 = &v2[strlen(v2)];
  do
  {
    v7 = *a2;
    *v6 = *a2;
    if ( !v7 )
      break;
    v8 = a2[1];
    a2 += 2;
    v6[1] = v8;
    v6 += 2;
  }
  while ( v8 );
  v9 = (char *)&unk_17C240;
  v10 = (char *)&v3[strlen(v3)];
  do
  {
    v11 = *v9;
    *v10 = *v9;
    if ( !v11 )
      break;
    v12 = v9[1];
    v9 += 2;
    v10[1] = v12;
    v10 += 2;
  }
  while ( v12 );
  v13 = sub_1524D0(a1, v3, 13);
  j__nfree(v3);
  if ( v13 >= 0 )
    return 0;
  return v13;
}
// 15E134: using guessed type int __fastcall j__nfree(_DWORD);
// 17C238: using guessed type int dword_17C238;


//----- (0015215C) --------------------------------------------------------
int __fastcall sub_15215C(int a1, char *a2)
{
  char *v2; // edi
  char *v3; // ebp
  int v4; // ebx
  char *v6; // edi
  char v7; // al
  char v8; // al
  char *v9; // esi
  char *v10; // edi
  char v11; // al
  char v12; // al
  int v13; // edi

  v2 = (char *)sub_15E124();
  v3 = v2;
  v4 = *(_DWORD *)(a1 + 19);
  if ( v4 == 1 )
  {
    strcpy(v2, "ATDP");
  }
  else if ( v4 )
  {
    *(_DWORD *)v2 = dword_17C238;
  }
  else
  {
    strcpy(v2, "ATDT");
  }
  v6 = &v2[strlen(v2)];
  do
  {
    v7 = *a2;
    *v6 = *a2;
    if ( !v7 )
      break;
    v8 = a2[1];
    a2 += 2;
    v6[1] = v8;
    v6 += 2;
  }
  while ( v8 );
  v9 = (char *)&unk_17C244;
  v10 = (char *)&v3[strlen(v3)];
  do
  {
    v11 = *v9;
    *v10 = *v9;
    if ( !v11 )
      break;
    v12 = v9[1];
    v9 += 2;
    v10[1] = v12;
    v10 += 2;
  }
  while ( v12 );
  v13 = sub_1524D0(a1, v3, 13);
  j__nfree(v3);
  if ( v13 >= 0 )
    return 0;
  return v13;
}
// 15E134: using guessed type int __fastcall j__nfree(_DWORD);
// 17C238: using guessed type int dword_17C238;


//----- (00152214) --------------------------------------------------------
int __fastcall sub_152214(int a1)
{
  int result; // eax

  result = sub_1524D0(a1, "ATA", 13);
  if ( result >= 0 )
    return 0;
  return result;
}


//----- (00152230) --------------------------------------------------------
int __fastcall sub_152230(int a1, char *a2, int a3)
{
  char *v4; // edi
  char *v5; // ebp
  char v6; // al
  char v7; // al
  char *v8; // esi
  char *v9; // edi
  char v10; // al
  char v11; // al
  int v12; // edx
  char *v14; // [esp-4h] [ebp-1Ch]
  int v15; // [esp+0h] [ebp-18h]

  v4 = (char *)sub_15E124();
  v5 = v4;
  v14 = v4;
  do
  {
    v6 = *a2;
    *v4 = *a2;
    if ( !v6 )
      break;
    v7 = a2[1];
    a2 += 2;
    v4[1] = v7;
    v4 += 2;
  }
  while ( v7 );
  v15 = sub_15E124();
  v8 = (char *)v15;
  itoa(a3, v15, 10, a3);
  v9 = (char *)&v14[strlen(v14)];
  do
  {
    v10 = *v8;
    *v9 = *v8;
    if ( !v10 )
      break;
    v11 = v8[1];
    v8 += 2;
    v9[1] = v11;
    v9 += 2;
  }
  while ( v11 );
  j__nfree(v15);
  v12 = sub_1523FC(a1, v5);
  j__nfree(v5);
  if ( v12 < 0 )
    return v12;
  else
    return 0;
}
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 15E134: using guessed type int __fastcall j__nfree(_DWORD);


//----- (001522D8) --------------------------------------------------------
int __fastcall sub_1522D8(int a1, unsigned int a2)
{
  if ( a2 < 2 )
    return sub_152230(a1, aAtc, a2);
  else
    return -7;
}


//----- (001522F8) --------------------------------------------------------
int __fastcall sub_1522F8(int a1, unsigned int a2)
{
  if ( a2 < 2 )
    return sub_152230(a1, aAte, a2);
  else
    return -7;
}


//----- (00152318) --------------------------------------------------------
int __fastcall sub_152318(int a1, unsigned int a2)
{
  if ( a2 < 2 )
    return sub_152230(a1, aAtf, a2);
  else
    return -7;
}


//----- (00152338) --------------------------------------------------------
int __fastcall sub_152338(int a1, unsigned int a2)
{
  if ( a2 <= 2 )
    return sub_152230(a1, aAth, a2);
  else
    return -7;
}


//----- (00152358) --------------------------------------------------------
int __fastcall sub_152358(int a1, unsigned int a2)
{
  if ( a2 <= 2 )
    return sub_152230(a1, aAtm, a2);
  else
    return -7;
}


//----- (00152378) --------------------------------------------------------
int __fastcall sub_152378(int a1, unsigned int a2)
{
  if ( a2 < 2 )
    return sub_152230(a1, aAtq, a2);
  else
    return -7;
}


//----- (00152398) --------------------------------------------------------
int __fastcall sub_152398(int a1, unsigned int a2)
{
  if ( a2 < 2 )
    return sub_152230(a1, aAtx, a2);
  else
    return -7;
}


//----- (001523B8) --------------------------------------------------------
int __fastcall sub_1523B8(int a1, unsigned int a2)
{
  if ( a2 < 2 )
    return sub_152230(a1, aAtv, a2);
  else
    return -7;
}


//----- (001523D8) --------------------------------------------------------
int __fastcall sub_1523D8(int a1, char *a2)
{
  int result; // eax

  if ( a2 )
    off_1897C4 = a2;
  result = -a1;
  dword_1897C0 = result;
  return result;
}
// 1897C0: using guessed type int dword_1897C0;
// 1897C4: using guessed type char *off_1897C4;


//----- (001523EC) --------------------------------------------------------
int __fastcall sub_1523EC(int result)
{
  dword_1897C8 = result;
  return result;
}
// 1897C8: using guessed type int dword_1897C8;


//----- (001523F4) --------------------------------------------------------
int __fastcall sub_1523F4(int result)
{
  dword_1897CC = result;
  return result;
}
// 1897CC: using guessed type int dword_1897CC;


//----- (001523FC) --------------------------------------------------------
int __fastcall sub_1523FC(int a1, char *a2)
{
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v7; // edx
  int v8; // edi
  int v9; // eax

  v3 = sub_15E124();
  v4 = sub_1524D0(a1, a2, 13);
  if ( v4 >= 0 )
  {
    if ( !dword_1897C0 )
      goto LABEL_4;
    if ( dword_1897C0 > 0 )
    {
      v7 = sub_15E1D4(a1, dword_1897C0, dword_1897C0, v3);
      j__nfree(v3);
      return v7;
    }
    v8 = -dword_1897C0;
    if ( !off_1897C4 )
    {
LABEL_4:
      j__nfree(v3);
      return v4;
    }
    while ( 1 )
    {
      v9 = sub_152690(a1, v8, v3, 40);
      v4 = v9;
      v8 = v9;
      if ( v9 < 0 )
        break;
      if ( !v9 )
      {
        j__nfree(v3);
        return -22;
      }
      if ( !strcmp(off_1897C4, v3) )
      {
        v4 = sub_15E1D4(a1, 500, v3, 40);
        break;
      }
    }
    v5 = v3;
  }
  else
  {
    v5 = v3;
  }
  j__nfree(v5);
  return v4;
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 15E134: using guessed type int __fastcall j__nfree(_DWORD);
// 1897C0: using guessed type int dword_1897C0;
// 1897C4: using guessed type char *off_1897C4;


//----- (001524D0) --------------------------------------------------------
int __fastcall sub_1524D0(int a1, char *a2, int a3)
{
  int v4; // eax
  int v5; // ebx
  int v6; // edx

  v4 = sub_15E200(a1, a2, a3);
  v5 = *(_DWORD *)(a1 + 14);
  v6 = v4;
  if ( v5 < 0 )
    return *(_DWORD *)(a1 + 14);
  while ( (*(int (__fastcall **)(int, int))(a1 + 71))(a1, v6) > 0 )
    ;
  if ( *(_DWORD *)(a1 + 14) == -24 )
    *(_DWORD *)(a1 + 14) = v5;
  return v6;
}


//----- (001524FC) --------------------------------------------------------
int __fastcall sub_1524FC(int a1, int a2)
{
  char *v2; // ebp
  char *v3; // esi
  char *v4; // edi
  char v5; // al
  char v6; // al
  char *v7; // esi
  char *v8; // edi
  char v9; // al
  char v10; // al
  int v11; // edx
  int v13; // eax
  char *v14; // edx
  uint8_t v15; // bl
  int i; // esi
  char v17; // bh
  int v18; // edx
  int v19; // [esp+0h] [ebp-20h]
  int v20; // [esp+4h] [ebp-1Ch]

  v2 = (char *)sub_15E124();
  *(_DWORD *)v2 = dword_17C21C;
  v20 = sub_15E124();
  v3 = (char *)v20;
  itoa(a2, v20, 10, a2);
  v4 = &v2[strlen(v2)];
  do
  {
    v5 = *v3;
    *v4 = *v3;
    if ( !v5 )
      break;
    v6 = v3[1];
    v3 += 2;
    v4[1] = v6;
    v4 += 2;
  }
  while ( v6 );
  v7 = (char *)&unk_17C26C;
  j__nfree(v20);
  v8 = &v2[strlen(v2)];
  do
  {
    v9 = *v7;
    *v8 = *v7;
    if ( !v9 )
      break;
    v10 = v7[1];
    v7 += 2;
    v8[1] = v10;
    v8 += 2;
  }
  while ( v10 );
  v11 = sub_1524D0(a1, v2, 13);
  if ( v11 >= 0 )
  {
    v19 = 1500;
    while ( 1 )
    {
      v13 = sub_152690(a1, v19, (int)v2, 40);
      v11 = v13;
      v19 = v13;
      if ( v13 < 0 )
        break;
      if ( !v13 )
      {
        j__nfree(v2);
        return -23;
      }
      v14 = v2;
      v15 = 0;
      for ( i = 0; i < (int)strlen(v2) && (IsTable[(uint8_t)(*v14 + 1)] & 0x20) != 0; ++i )
      {
        v17 = *v14++;
        v15 = v17 + 10 * v15 - 48;
      }
      if ( i > 0 && i == strlen(v2) )
      {
        v18 = sub_1523FC(a1, byte_17C270);
        j__nfree(v2);
        if ( v18 >= 0 )
          return v15;
        else
          return v18;
      }
    }
  }
  j__nfree(v2);
  return v11;
}
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 15E134: using guessed type int __fastcall j__nfree(_DWORD);
// 17C21C: using guessed type int dword_17C21C;


//----- (00152690) --------------------------------------------------------
int __fastcall sub_152690(int a1, int a2, int a3, int a4)
{
  int v5; // eax
  int v6; // ecx
  int v7; // ebx
  int result; // eax
  _BYTE *v9; // eax
  int v10; // edi
  _BYTE *v11; // ebx
  int v13; // [esp+4h] [ebp-10h]

  v5 = sub_15E270(a1, a2, a3, a4);
  v6 = a4 - 1;
  v7 = 0;
  v13 = a2 + v5;
  if ( v6 <= 0 )
    return -7;
  while ( 1 )
  {
    v9 = (_BYTE *)((int (__fastcall *)(int, int))off_18ACD4[0])(a1, a2);
    v10 = (int)v9;
    if ( (int)v9 < 0 )
      break;
    v9 = (_BYTE *)(*(int (__fastcall **)(int))(a1 + 27))(a1);
    a2 = (int)v9;
    if ( (int)v9 < 0 )
    {
      if ( v9 != (_BYTE *)-8 )
      {
        v10 = (int)v9;
        break;
      }
      v9 = (_BYTE *)off_18ACD8();
      v10 = (int)v9;
      if ( (int)v9 < 0 )
        break;
      a2 = v13;
      v9 = (_BYTE *)sub_15E270((int)v9, v13, v7, v6);
      if ( (int)v9 >= v13 )
        break;
    }
    else
    {
      if ( dword_1897C8 )
        v9 = (_BYTE *)dword_1897C8((uint8_t)v9);
      if ( a2 == 13 )
        break;
      if ( a2 != 10 )
      {
        v9 = (_BYTE *)(a3 + v7);
        --v6;
        ++v7;
        *v9 = a2;
        if ( v6 <= 0 )
          break;
      }
    }
  }
  v11 = (_BYTE *)(a3 + v7);
  *v11 = 0;
  if ( v10 < 0 )
    return v10;
  result = v13 - sub_15E270((int)v9, v13, (int)v11, v6);
  if ( result < 0 )
    return 0;
  return result;
}
// 18ACD4: invalid function type '?' has been ignored
// 1897C8: invalid function type '?' has been ignored
// 1897C8: using guessed type int (__fastcall *dword_1897C8)(_DWORD);
// 18ACD4: using guessed type int (*off_18ACD4[2])();
// 18ACD8: using guessed type int (*off_18ACD8)();


//----- (00152754) --------------------------------------------------------
int __fastcall sub_152754(int a1, unsigned int a2)
{
  return sub_151DA8(a1, 5, a2);
}


//----- (00152768) --------------------------------------------------------
int __fastcall sub_152768(int a1, unsigned int a2)
{
  return sub_151DA8(a1, 3, a2);
}


//----- (0015277C) --------------------------------------------------------
int __fastcall sub_15277C(int a1, unsigned int a2)
{
  return sub_151DA8(a1, 2, a2);
}


//----- (00152790) --------------------------------------------------------
int __fastcall sub_152790(int a1, unsigned int a2)
{
  return sub_151DA8(a1, 4, a2);
}


//----- (001527B0) --------------------------------------------------------
int __fastcall sub_1527B0(int a1, int a2, int a3, int a4)
{
  int result; // eax
  _DWORD v6[19]; // [esp-48h] [ebp-4Ch] BYREF

  v6[17] = a4;
  while ( 1 )
  {
    result = (*(int (__fastcall **)(int, _DWORD *, int))(a1 + 91))(a1, v6, 64);
    if ( result < 0 && result != -8 )
      break;
    if ( !*(_DWORD *)(a1 + 23) )
      return 0;
  }
  return result;
}


//----- (001527F4) --------------------------------------------------------
int __fastcall sub_1527F4(int a1)
{
  int v1; // eax
  int v2; // edx

  v1 = (*(int (**)(void))(a1 + 103))();
  v2 = v1;
  if ( v1 > 0 )
    return v1 & 0x80;
  return v2;
}


//----- (00152840) --------------------------------------------------------
int __fastcall sub_152840(int result, int a2)
{
  dword_1897D0 = result;
  dword_1897D4 = a2;
  return result;
}
// 1897D0: using guessed type int dword_1897D0;
// 1897D4: using guessed type int dword_1897D4;


//----- (00152850) --------------------------------------------------------
int __fastcall sub_152850(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+4h] [ebp-1Ch]
  _DWORD v6[6]; // [esp+8h] [ebp-18h] BYREF

  v6[4] = a4;
  LOWORD(v5) = *(_WORD *)(a1 + 4);
  sub_15E3A8((int)v6, *(_DWORD *)a1 + 14, v5, a4, *(_DWORD *)a1 + 14, v5, 4);
  return sub_168549(v6[0] + 6);
}
// 152872: variable 'v5' is possibly undefined


//----- (00152894) --------------------------------------------------------
int __fastcall sub_152894(int a1)
{
  int v1; // ebx
  int v2; // edx
  int v4; // [esp+Ch] [ebp-28h]
  int v5; // [esp+10h] [ebp-24h] BYREF
  int v6; // [esp+14h] [ebp-20h] BYREF
  int v7; // [esp+18h] [ebp-1Ch] BYREF

  LOWORD(v4) = *(_WORD *)(a1 + 4);
  v1 = *(_DWORD *)a1 + 14;
  v2 = *(_DWORD *)a1 + 30;
  sub_15E3A8((int)&v5, v2, v1, v4, v1, v4, 4);
  sub_168545();
  v6 = sub_168549(v5 + 5);
  sub_15E3A8((int)&v7, v2, v1, v4, v2, v4, 4);
  v6 |= v7;
  sub_15E37C(v2, v4, (uint8_t *)&v6, 4);
  sub_168541();
  return v6 & 0x1E;
}
// 1528CF: variable 'v4' is possibly undefined


//----- (00152934) --------------------------------------------------------
int __fastcall sub_152934(int *a1)
{
  int v2; // [esp+0h] [ebp-30h]
  int16_t v3; // [esp+4h] [ebp-2Ch]
  int v4; // [esp+8h] [ebp-28h]
  int16_t v5; // [esp+Ch] [ebp-24h]
  int v6; // [esp+10h] [ebp-20h] BYREF
  _DWORD v7[7]; // [esp+14h] [ebp-1Ch] BYREF

  v2 = *a1;
  v3 = *((_WORD *)a1 + 2);
  v6 = 0;
  v5 = *((_WORD *)a1 + 2);
  v4 = *a1 + 30;
  sub_15E3A8((int)v7, 0, v4, v2 + 14, v2 + 14, v3, 4);
  sub_168545();
  sub_15E37C(v4, v5, (uint8_t *)&v6, 4);
  sub_168549(v7[0] + 5);
  sub_168541();
  return 0;
}


//----- (001529B8) --------------------------------------------------------
int __fastcall sub_1529B8(int a1, int a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // esi
  int v5; // eax
  int v7; // [esp+4h] [ebp-20h]
  int v8; // [esp+8h] [ebp-1Ch] BYREF
  int v9; // [esp+Ch] [ebp-18h]

  LOWORD(v7) = *(_WORD *)(a1 + 4);
  sub_15E3A8((int)&v8, a2, *(_DWORD *)a1 + 14, v7, *(_DWORD *)a1 + 14, v7, 4);
  v2 = 18 * a2 / 1000;
  v3 = 18 * a2 % 1000;
  v4 = v2;
  if ( v2 <= 0 )
    v4 = 1;
  v5 = sub_168549(v8 + 3);
  LOBYTE(v5) = v5 | 0x40;
  v9 = v5;
  sub_168560(v8 + 3, v5);
  sub_15E1A0(v4, v3, 1000, v7);
  LOBYTE(v9) = v9 & 0xBF;
  sub_168560(v8 + 3, v9);
  return 0;
}
// 1529E7: variable 'v7' is possibly undefined


//----- (00152A5C) --------------------------------------------------------
int __fastcall sub_152A5C(int *a1, int a2, unsigned int a3)
{
  int v5; // ecx
  int v6; // ebx
  unsigned int v7; // eax
  int v8; // edx
  int v9; // esi
  int v10; // eax
  unsigned int v11; // ecx
  char v12[14]; // [esp+0h] [ebp-64h] BYREF
  int v13; // [esp+Eh] [ebp-56h]
  int v14; // [esp+12h] [ebp-52h]
  _DWORD v15[9]; // [esp+16h] [ebp-4Eh] BYREF
  unsigned int v16; // [esp+3Ch] [ebp-28h]
  int v17; // [esp+40h] [ebp-24h]
  unsigned int v18; // [esp+44h] [ebp-20h]
  int v19; // [esp+48h] [ebp-1Ch]
  unsigned int v20; // [esp+4Ch] [ebp-18h]
  int v21; // [esp+50h] [ebp-14h]

  v21 = a2;
  v20 = a3;
  *(int *)((char *)a1 + 23) = 0;
  if ( a2 )
  {
    sub_168545();
    v5 = *a1;
    sub_15E3A8((int)v12, a2, a1[1], *a1, *a1, a1[1], 58);
    sub_168541();
    v6 = v14 - v15[0] + (v14 - v15[0] < 0 ? 0x400 : 0);
    while ( 1 )
    {
      v7 = *(int *)((char *)a1 + 23);
      if ( v7 >= v20 || !v6 )
        break;
      v8 = v20 - v7;
      if ( (int)(v20 - v7) > v6 )
        v8 = v6;
      if ( v8 > 1024 - v15[0] )
        v8 = 1024 - v15[0];
      v18 = *a1;
      LOWORD(v19) = *((_WORD *)a1 + 2);
      v18 += 58 + v15[0];
      sub_15E3A8(v21, v8, v6, v5, v18, v19, v8);
      v15[0] += v8;
      v6 -= v8;
      v9 = v21;
      *(int *)((char *)a1 + 23) += v8;
      v21 = v8 + v9;
      if ( v15[0] >= 1024 )
      {
        v5 = 0;
        v15[0] = 0;
      }
    }
    if ( v6 <= 256 && v15[5] )
    {
      sub_168545();
      v10 = sub_168549(v13 + 4);
      sub_168560(v13 + 4, v15[3] | v10);
      sub_168541();
    }
    v16 = *a1;
    LOWORD(v17) = *((_WORD *)a1 + 2);
    v11 = v20;
    v16 += 22;
    sub_15E37C(v16, v17, (uint8_t *)v15, 4);
    if ( v11 <= *(int *)((char *)a1 + 23) )
      return 0;
    else
      return -8;
  }
  else
  {
    *(int *)((char *)a1 + 14) = -7;
    return *(int *)((char *)a1 + 14);
  }
}


//----- (00152BCC) --------------------------------------------------------
int __fastcall sub_152BCC(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v6; // [esp+4h] [ebp-1Ch]
  _DWORD v7[6]; // [esp+8h] [ebp-18h] BYREF

  LOWORD(v6) = *(_WORD *)(a1 + 4);
  sub_15E3A8((int)v7, *(_DWORD *)a1 + 14, v6, a4, *(_DWORD *)a1 + 14, v6, 4);
  sub_168545();
  v4 = sub_168549(v7[0] + 4);
  if ( a2 )
    LOBYTE(v4) = v4 | 1;
  else
    LOBYTE(v4) = v4 & 0xFE;
  sub_168560(v7[0] + 4, v4);
  sub_168541();
  return 0;
}
// 152BF4: variable 'v6' is possibly undefined


//----- (00152C3C) --------------------------------------------------------
int __fastcall sub_152C3C(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v6; // [esp+4h] [ebp-1Ch]
  _DWORD v7[6]; // [esp+8h] [ebp-18h] BYREF

  LOWORD(v6) = *(_WORD *)(a1 + 4);
  sub_15E3A8((int)v7, *(_DWORD *)a1 + 14, v6, a4, *(_DWORD *)a1 + 14, v6, 4);
  sub_168545();
  v4 = sub_168549(v7[0] + 4);
  if ( a2 )
    LOBYTE(v4) = v4 | 2;
  else
    LOBYTE(v4) = v4 & 0xFD;
  sub_168560(v7[0] + 4, v4);
  sub_168541();
  return 0;
}
// 152C64: variable 'v6' is possibly undefined


//----- (00152CAC) --------------------------------------------------------
int __fastcall sub_152CAC(int a1, int a2, int a3, int a4, unsigned int a5, int a6)
{
  int v6; // ecx
  int v8; // eax
  uint8_t v9[20]; // [esp+0h] [ebp-E0h] BYREF
  unsigned int v10; // [esp+14h] [ebp-CCh]
  int16_t v11; // [esp+18h] [ebp-C8h]
  int v12; // [esp+1Ah] [ebp-C6h]
  unsigned int v13; // [esp+40h] [ebp-A0h] BYREF
  int16_t v14; // [esp+44h] [ebp-9Ch]
  int v15; // [esp+46h] [ebp-9Ah]
  int v16; // [esp+4Eh] [ebp-92h]
  int v17; // [esp+5Ah] [ebp-86h]
  unsigned int v18; // [esp+7Ch] [ebp-64h] BYREF
  _WORD v19[3]; // [esp+80h] [ebp-60h]
  int v20; // [esp+86h] [ebp-5Ah]
  unsigned int v21; // [esp+B8h] [ebp-28h]
  int v22; // [esp+BCh] [ebp-24h]
  unsigned int v23; // [esp+C0h] [ebp-20h] BYREF
  int v24; // [esp+C4h] [ebp-1Ch]

  sub_15E3A8((int)&v13, a6, a5, a4, a5, a6, 58);
  v6 = v16;
  if ( !v16 )
    return -6;
  sub_168560(v16 + 1, 0);
  v8 = sub_168549(v16 + 4);
  LOBYTE(v8) = v8 & 0xF7;
  sub_168560(v16 + 4, v8);
  v16 = 0;
  sub_168545();
  sub_15E918(v17, (int)&v23);
  if ( !(_WORD)v24 )
    goto LABEL_15;
  sub_15E3A8((int)v9, a6, a5, v6, v23, v24, 62);
  if ( (_WORD)a6 != v11 || a5 != v10 )
  {
    v21 = v10;
    LOWORD(v22) = v11;
    do
    {
      sub_15E3A8((int)&v18, a5, a5, v6, v21, v22, 58);
      if ( v20 != 16634 )
        break;
      if ( v19[0] == (_WORD)a6 && a5 == v18 )
      {
        v18 = v13;
        v19[0] = v14;
        *(_DWORD *)&v19[1] = v15;
        sub_15E37C(v21, v22, (uint8_t *)&v18, 58);
        sub_168541();
        return 0;
      }
      v21 = v18;
      LOWORD(v22) = v19[0];
    }
    while ( v19[0] );
LABEL_15:
    sub_168541();
    return -38;
  }
  if ( v14 )
  {
    v10 = v13;
    v11 = v14;
    v12 = v15;
    sub_15E37C(v23, v24, v9, 62);
    sub_168541();
    return 0;
  }
  else
  {
    sub_168541();
    return sub_15E814(v17);
  }
}


//----- (00152EC0) --------------------------------------------------------
int __fastcall sub_152EC0(int a1)
{
  int v3; // ebx

  if ( *(_BYTE *)(a1 + 18) == 0xFF )
    return -5;
  v3 = sub_152CAC(a1, a1, *(_DWORD *)(a1 + 4), *(_DWORD *)a1, *(_DWORD *)a1, *(_DWORD *)(a1 + 4));
  sub_15EB04(*(_DWORD *)a1, *(_DWORD *)(a1 + 4));
  sub_15F014(a1);
  return v3;
}


//----- (00152F00) --------------------------------------------------------
int __fastcall sub_152F00(int *a1, int a2, int a3, int a4)
{
  int v5; // edx
  int v6; // ebx
  int v7; // ecx
  int16_t v8; // di
  int v9; // esi
  int v10; // eax
  _BYTE v12[14]; // [esp+2h] [ebp-60h] BYREF
  int v13; // [esp+10h] [ebp-52h]
  int v14; // [esp+28h] [ebp-3Ah]
  int v15; // [esp+3Eh] [ebp-24h]
  int v16; // [esp+42h] [ebp-20h]
  int v17; // [esp+46h] [ebp-1Ch] BYREF
  int v18; // [esp+4Ah] [ebp-18h]

  v18 = a2;
  v5 = a1[1];
  v6 = *a1;
  sub_15E3A8((int)v12, v5, *a1, a4, *a1, v5, 58);
  v15 = *a1;
  LOWORD(v16) = *((_WORD *)a1 + 2);
  v7 = v15 + 30;
  v8 = v16;
  v15 += 30;
  do
  {
    sub_168545();
    v9 = sub_168549(v13 + 5);
    sub_15E3A8((int)&v17, v5, v6, v7, v15, v8, 4);
    v7 = v15;
    v5 = v9 | v17;
    v17 |= v9;
    sub_15E37C(v15, v8, (uint8_t *)&v17, 4);
    sub_168541();
  }
  while ( (v9 & 0x20) == 0 );
  v10 = sub_168549(v13 + 6);
  if ( (v14 & v10) == v14 )
  {
    sub_168560(v13, v18);
    return 0;
  }
  else
  {
    *(int *)((char *)a1 + 14) = -36;
    return *(int *)((char *)a1 + 14);
  }
}


//----- (00152FCC) --------------------------------------------------------
int __fastcall sub_152FCC(int *a1, int a2, unsigned int a3)
{
  unsigned int v5; // eax
  int v6; // esi
  int16_t v7; // bx
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // [esp-2h] [ebp-64h]
  _BYTE v12[14]; // [esp+2h] [ebp-60h] BYREF
  int v13; // [esp+10h] [ebp-52h]
  int v14; // [esp+28h] [ebp-3Ah]
  int v15; // [esp+34h] [ebp-2Eh]
  unsigned int v16; // [esp+3Eh] [ebp-24h]
  int v17; // [esp+42h] [ebp-20h]
  unsigned int v18; // [esp+46h] [ebp-1Ch]
  int v19; // [esp+4Ah] [ebp-18h] BYREF
  uint8_t *v20; // [esp+4Eh] [ebp-14h]

  v20 = (uint8_t *)a2;
  v18 = a3;
  *(int *)((char *)a1 + 23) = 0;
  if ( !a2 )
  {
    *(int *)((char *)a1 + 14) = -7;
    return *(int *)((char *)a1 + 14);
  }
  sub_15E3A8((int)v12, a2, a1[1], *a1, *a1, a1[1], 58);
  v16 = *a1;
  LOWORD(v17) = *((_WORD *)a1 + 2);
  v5 = *(int *)((char *)a1 + 23);
  v16 += 30;
  if ( v5 < v18 )
  {
    do
    {
      v6 = sub_168549(v13 + 5);
      sub_168545();
      v7 = v17;
      v8 = v16;
      sub_15E3A8((int)&v19, a2, v17, v16, v16, v17, 4);
      v19 |= v6;
      sub_15E37C(v8, v7, (uint8_t *)&v19, 4);
      sub_168541();
      if ( (v6 & 0x20) != 0 )
      {
        v9 = sub_168549(v13 + 6);
        if ( (v14 & v9) != v14 )
        {
          *(int *)((char *)a1 + 14) = -36;
          return *(int *)((char *)a1 + 14);
        }
        if ( v15 )
        {
          v10 = 16;
          if ( *(int *)((char *)a1 + 23) + 16 > v18 )
            v10 = v18 - *(int *)((char *)a1 + 23);
        }
        else
        {
          v10 = 1;
        }
        while ( v10 > 0 )
        {
          v11 = *v20++;
          sub_168560(v13, v11);
          --v10;
          ++*(int *)((char *)a1 + 23);
        }
      }
      a2 = v18;
    }
    while ( v18 > *(int *)((char *)a1 + 23) );
  }
  return 0;
}


//----- (00153118) --------------------------------------------------------
int __fastcall sub_153118(int a1)
{
  int v1; // edx
  int v2; // ebx
  int v3; // esi
  int v5; // [esp+Ch] [ebp-24h]
  int v6; // [esp+10h] [ebp-20h] BYREF
  _DWORD v7[7]; // [esp+14h] [ebp-1Ch] BYREF

  LOWORD(v5) = *(_WORD *)(a1 + 4);
  v1 = *(_DWORD *)a1 + 30;
  v2 = *(_DWORD *)a1 + 14;
  sub_15E3A8((int)v7, v1, v2, v5, v2, v5, 4);
  do
  {
    v3 = sub_168549(v7[0] + 5);
    sub_168545();
    sub_15E3A8((int)&v6, v1, v2, v5, v1, v5, 4);
    v6 |= v3;
    sub_15E37C(v1, v5, (uint8_t *)&v6, 4);
    sub_168541();
  }
  while ( (v3 & 0x20) == 0 );
  return 0;
}
// 15315D: variable 'v5' is possibly undefined


//----- (001531B8) --------------------------------------------------------
bool __fastcall sub_1531B8(int *a1, int a2, int a3, int a4)
{
  int v5; // [esp+10h] [ebp-30h]
  int16_t v6; // [esp+14h] [ebp-2Ch]
  int v7; // [esp+1Ch] [ebp-24h]
  int v8; // [esp+20h] [ebp-20h] BYREF
  int v9; // [esp+24h] [ebp-1Ch] BYREF
  int v10; // [esp+28h] [ebp-18h]
  int v11; // [esp+38h] [ebp-8h]

  v11 = a4;
  v5 = *a1;
  v6 = *((_WORD *)a1 + 2);
  LOWORD(v7) = v6;
  sub_15E3A8((int)&v8, v5 + 14, v7, a4, v5 + 14, v6, 4);
  sub_168545();
  v10 = sub_168549(v8 + 5);
  sub_15E3A8((int)&v9, v5 + 14, v7, a4, v5 + 30, v6, 4);
  v9 |= v10;
  sub_15E37C(v5 + 30, v6, (uint8_t *)&v9, 4);
  sub_168541();
  return (v10 & 0x20) != 0;
}
// 1531E7: variable 'v7' is possibly undefined


//----- (0015325C) --------------------------------------------------------
bool __fastcall sub_15325C(int *a1, int a2, int a3, int a4)
{
  int v5; // [esp+10h] [ebp-30h]
  int16_t v6; // [esp+14h] [ebp-2Ch]
  int v7; // [esp+1Ch] [ebp-24h]
  int v8; // [esp+20h] [ebp-20h] BYREF
  int v9; // [esp+24h] [ebp-1Ch] BYREF
  int v10; // [esp+28h] [ebp-18h]
  int v11; // [esp+38h] [ebp-8h]

  v11 = a4;
  v5 = *a1;
  v6 = *((_WORD *)a1 + 2);
  LOWORD(v7) = v6;
  sub_15E3A8((int)&v8, v5 + 14, v7, a4, v5 + 14, v6, 4);
  sub_168545();
  v10 = sub_168549(v8 + 5);
  sub_15E3A8((int)&v9, v5 + 14, v7, a4, v5 + 30, v6, 4);
  v9 |= v10;
  sub_15E37C(v5 + 30, v6, (uint8_t *)&v9, 4);
  sub_168541();
  return (v10 & 0x20) == 0;
}
// 15328B: variable 'v7' is possibly undefined


//----- (00153300) --------------------------------------------------------
int __fastcall sub_153300(int *a1, int a2, int a3, int a4)
{
  _BYTE v6[18]; // [esp+0h] [ebp-4Ch] BYREF
  int v7; // [esp+12h] [ebp-3Ah]
  int v8; // [esp+16h] [ebp-36h]
  int v9; // [esp+44h] [ebp-8h]

  v9 = a4;
  sub_168545();
  sub_15E3A8((int)v6, a1[1], *a1, a4, *a1, a1[1], 58);
  sub_168541();
  return 1023 - (v7 - v8 + (v7 - v8 < 0 ? 0x400 : 0));
}


//----- (00153348) --------------------------------------------------------
int __fastcall sub_153348(int *a1, int a2, int a3, int a4)
{
  _BYTE v6[18]; // [esp+0h] [ebp-4Ch] BYREF
  int v7; // [esp+12h] [ebp-3Ah]
  int v8; // [esp+16h] [ebp-36h]
  int v9; // [esp+44h] [ebp-8h]

  v9 = a4;
  sub_168545();
  sub_15E3A8((int)v6, a1[1], *a1, a4, *a1, a1[1], 58);
  sub_168541();
  return v7 - v8 + (v7 - v8 < 0 ? 0x400 : 0);
}


//----- (00153388) --------------------------------------------------------
int __fastcall sub_153388(int *a1, int a2, int a3, int a4)
{
  int v5; // eax
  uint8_t v7[14]; // [esp+2h] [ebp-50h] BYREF
  int v8; // [esp+10h] [ebp-42h]
  int v9; // [esp+24h] [ebp-2Eh]
  int v10; // [esp+28h] [ebp-2Ah]

  sub_168545();
  sub_15E3A8((int)v7, a1[1], *a1, a4, *a1, a1[1], 58);
  if ( a2 )
  {
    v9 = 2;
    v10 = 16;
  }
  else
  {
    v10 = 0;
    v9 = 0;
  }
  sub_15E37C(*a1, a1[1], v7, 58);
  sub_168541();
  sub_168545();
  v5 = sub_168549(v8 + 4);
  LOBYTE(v5) = v5 | 2;
  sub_168560(v8 + 4, v5);
  sub_168541();
  return 0;
}


//----- (00153420) --------------------------------------------------------
int __fastcall sub_153420(int *a1, int a2, int a3, int a4)
{
  int v5; // eax
  uint8_t v7[14]; // [esp+2h] [ebp-50h] BYREF
  int v8; // [esp+10h] [ebp-42h]
  int v9; // [esp+24h] [ebp-2Eh]
  int v10; // [esp+28h] [ebp-2Ah]

  sub_168545();
  sub_15E3A8((int)v7, a1[1], *a1, a4, *a1, a1[1], 58);
  if ( a2 )
  {
    v9 = 1;
    v10 = 32;
  }
  else
  {
    v10 = 0;
    v9 = 0;
  }
  sub_15E37C(*a1, a1[1], v7, 58);
  sub_168541();
  sub_168545();
  v5 = sub_168549(v8 + 4);
  LOBYTE(v5) = v5 | 1;
  sub_168560(v8 + 4, v5);
  sub_168541();
  return 0;
}


//----- (001534B8) --------------------------------------------------------
int __fastcall sub_1534B8(int *a1, int a2, int a3, int a4)
{
  int v5; // eax
  int v7; // eax
  int v8; // ecx
  uint8_t v9; // si
  unsigned int v10; // [esp-10h] [ebp-6Ch]
  int v11; // [esp-Ch] [ebp-68h]
  uint8_t v12[14]; // [esp+0h] [ebp-5Ch] BYREF
  int v13; // [esp+Eh] [ebp-4Eh]
  int v14; // [esp+12h] [ebp-4Ah]
  int v15; // [esp+16h] [ebp-46h]
  int v16; // [esp+22h] [ebp-3Ah]
  int v17; // [esp+2Ah] [ebp-32h]
  int v18; // [esp+3Ch] [ebp-20h]
  int16_t v19; // [esp+40h] [ebp-1Ch]

  sub_168545();
  sub_15E3A8((int)v12, a1[1], *a1, a4, *a1, a1[1], 58);
  v5 = v14 - v15 + (v14 - v15 < 0 ? 0x400 : 0);
  if ( v5 )
  {
    if ( v5 == 256 && !v17 )
    {
      v7 = sub_168549(v13 + 4);
      sub_168560(v13 + 4, v16 | v7);
    }
    v18 = *a1;
    v19 = *((_WORD *)a1 + 2);
    v18 += 58;
    v8 = v18 + v15;
    v9 = hr_readgsbyte(v18 + v15);
    v15 = ((_WORD)v15 + 1) & 0x3FF;
    v11 = a1[1];
    v10 = *a1;
    v18 = v8;
    sub_15E37C(v10, v11, v12, 58);
    sub_168541();
    return v9;
  }
  else
  {
    sub_168541();
    return -8;
  }
}


//----- (00153598) --------------------------------------------------------
int __fastcall sub_153598(int *a1, int a2, int a3, int a4)
{
  _BYTE v6[18]; // [esp+0h] [ebp-58h] BYREF
  int v7; // [esp+12h] [ebp-46h]
  int v8; // [esp+16h] [ebp-42h]
  int v9; // [esp+50h] [ebp-8h]

  v9 = a4;
  sub_168545();
  sub_15E3A8((int)v6, a1[1], *a1, a4, *a1, a1[1], 58);
  sub_168541();
  if ( v7 - v8 + (v7 - v8 < 0 ? 0x400 : 0) )
    return hr_readgsbyte(*a1 + 58 + v8);
  else
    return -8;
}


//----- (00153610) --------------------------------------------------------
int __fastcall sub_153610(int *a1, int a2, int a3, int a4)
{
  int v6; // eax
  int v7; // eax
  int v8; // eax
  uint8_t v9[14]; // [esp+0h] [ebp-4Ch] BYREF
  int v10; // [esp+Eh] [ebp-3Eh]
  int v11; // [esp+22h] [ebp-2Ah]
  int v12; // [esp+2Ah] [ebp-22h]

  sub_168545();
  sub_15E3A8((int)v9, a1[1], *a1, a4, *a1, a1[1], 58);
  if ( a2 )
  {
    if ( !v11 )
    {
      sub_168541();
      *(int *)((char *)a1 + 14) = -1;
      return *(int *)((char *)a1 + 14);
    }
    v12 = 1;
    v6 = sub_168549(v10 + 4);
    v7 = ~v11 & v6;
  }
  else
  {
    v12 = 0;
    v8 = sub_168549(v10 + 4);
    v7 = v11 | v8;
  }
  sub_168560(v10 + 4, v7);
  sub_15E37C(*a1, a1[1], v9, 58);
  sub_168541();
  return 0;
}


//----- (001536B8) --------------------------------------------------------
int __fastcall sub_1536B8(int *a1, int a2, unsigned int a3, int a4, unsigned int a5)
{
  int v7; // ecx
  unsigned int v8; // eax
  _BYTE v9[14]; // [esp+0h] [ebp-4Ch] BYREF
  int v10; // [esp+Eh] [ebp-3Eh]
  int v11; // [esp+3Ch] [ebp-10h]

  if ( a4 < 5 || a4 > 8 )
    return -27;
  v7 = a4 - 5;
  v11 = v7;
  v8 = toupper(a3, a5);
  if ( v8 < 0x4E )
  {
    if ( v8 < 0x45 )
      return -26;
    if ( v8 <= 0x45 )
    {
      LOBYTE(v11) = v11 | 0x18;
    }
    else
    {
      if ( v8 != 77 )
        return -26;
      LOBYTE(v11) = v11 | 0x28;
    }
  }
  else if ( v8 > 0x4E )
  {
    if ( v8 <= 0x4F )
    {
      LOBYTE(v11) = v11 | 8;
    }
    else
    {
      if ( v8 != 83 )
        return -26;
      LOBYTE(v11) = v11 | 0x38;
    }
  }
  if ( !a5 )
    return -28;
  if ( a5 > 1 )
  {
    if ( a5 == 2 )
    {
      LOBYTE(v11) = v11 | 4;
      goto LABEL_23;
    }
    return -28;
  }
LABEL_23:
  if ( a2 < 1 || a2 > 115200 )
    return -25;
  sub_15E3A8((int)v9, a1[1], *a1, v7, *a1, a1[1], 58);
  if ( !v10 )
    return -6;
  sub_168560(v10 + 3, 128);
  sub_168560(v10, (uint8_t)(115200 / a2));
  sub_168560(v10 + 1, (115200 / a2) >> 8);
  sub_168560(v10 + 3, v11);
  return 0;
}
// 13E22A: using guessed type int __fastcall toupper(_DWORD, _DWORD);


//----- (00153800) --------------------------------------------------------
int __fastcall sub_153800(int a1, int a2, int a3, int a4, unsigned int a5, int a6)
{
  int v6; // ebx
  int v7; // ecx
  int v9; // ecx
  int v10; // ebx
  int v11; // eax
  uint8_t v12[20]; // [esp+0h] [ebp-46h] BYREF
  unsigned int v13; // [esp+14h] [ebp-32h]
  int16_t v14[20]; // [esp+18h] [ebp-2Eh]
  unsigned int v15; // [esp+40h] [ebp-6h] BYREF
  int16_t v16; // [esp+44h] [ebp-2h]
  int v17; // [esp+46h] [ebp+0h]
  int v18; // [esp+4Ah] [ebp+4h]
  int v19; // [esp+5Ah] [ebp+14h]
  _BYTE v20[60]; // [esp+7Ch] [ebp+36h] BYREF
  unsigned int v21; // [esp+B8h] [ebp+72h] BYREF
  int v22; // [esp+BCh] [ebp+76h]

  sub_15E3A8((int)&v15, a6, a5, a4, a5, a6, 58);
  if ( sub_15F090() && (sub_168545(), sub_15E918(v19, (int)&v21), (_WORD)v22) )
  {
    v6 = v22;
    v7 = v21;
    sub_15E3A8((int)v12, a6, v22, v21, v21, v22, 62);
    sub_15E3A8((int)v20, a6, v6, v7, v13, v14[0], 58);
    if ( v18 == 16634 )
    {
      v15 = v13;
      v16 = v14[0];
      v17 = *(_DWORD *)&v14[1];
      v13 = a5;
      v14[0] = a6;
      *(_DWORD *)&v14[1] = sub_15EBF0(*(int *)&v14[1], a6, a5, v7, a5, a6);
      sub_15E37C(v21, v22, v12, 62);
      sub_15E37C(a5, a6, (uint8_t *)&v15, 58);
      sub_168541();
      return 0;
    }
    else
    {
      sub_168541();
      return -39;
    }
  }
  else
  {
    v16 = 0;
    v15 = 0;
    v17 = 0;
    v9 = 8;
    HIWORD(v10) = HIWORD(dword_1C9CAC);
    if ( v19 <= 15 )
      v11 = 0;
    else
      v11 = 160;
    LOWORD(v10) = &loc_16845A - (_UNKNOWN *)&byte_168130;
    LOBYTE(v9) = v19 % 8;
    return sub_15E3F0(v19, (int)sub_168577, v10, v9, a5, a6, 0, 32, v11, 1 << v9);
  }
}
// 168130: using guessed type char byte_168130;
// 1C9CAC: using guessed type int dword_1C9CAC;


//----- (0015396C) --------------------------------------------------------
int __fastcall sub_15396C(int *a1, int a2, unsigned int a3, int a4, unsigned int a5)
{
  unsigned int v7; // esi
  int result; // eax
  int v9; // eax
  int v10; // edx
  int v11; // esi
  int v12; // ebx
  int v13; // eax
  uint8_t v14[10]; // [esp+12h] [ebp-50h] BYREF
  int v15; // [esp+1Ch] [ebp-46h]
  int v16; // [esp+20h] [ebp-42h]
  int v17; // [esp+24h] [ebp-3Eh]
  int v18; // [esp+28h] [ebp-3Ah]
  int v19; // [esp+2Ch] [ebp-36h]
  int v20; // [esp+30h] [ebp-32h]
  int v21; // [esp+34h] [ebp-2Eh]
  int v22; // [esp+38h] [ebp-2Ah]
  _WORD v23[3]; // [esp+3Eh] [ebp-24h]
  int v24; // [esp+44h] [ebp-1Eh]
  int v25; // [esp+48h] [ebp-1Ah]
  int v26; // [esp+4Eh] [ebp-14h]
  uint8_t v27; // [esp+52h] [ebp-10h]

  v27 = a3;
  v26 = a4;
  sub_15E3A8((int)v14, a1[1], *a1, 16634, *a1, a1[1], 58);
  v15 = 16634;
  v7 = *(int *)((char *)a1 + 10);
  v20 = 0;
  v21 = 0;
  if ( sub_15F090() )
  {
    if ( v7 >= 8 )
      return -2;
    v16 = dword_1897F8[v7];
    v9 = dword_189838[v7];
  }
  else
  {
    if ( v7 >= 4 )
      return -2;
    v16 = dword_1897D8[v7];
    v9 = dword_189818[v7];
  }
  v19 = v9;
  v17 = 0;
  v18 = 0;
  v22 = 0;
  if ( (sub_168549(v16 + 2) & 0x30) != 0 )
    return -14;
  sub_168560(v16 + 1, 0);
  v10 = *a1;
  sub_15E37C(*a1, a1[1], v14, 58);
  v11 = 0;
  sub_168560(v16 + 2, 0);
  do
  {
    v12 = v16;
    ++v11;
    v13 = sub_168549(v16);
  }
  while ( v11 < 16 );
  result = sub_153800(v13, v10, v12, a1[1], *a1, a1[1]);
  if ( result >= 0 )
  {
    result = sub_1536B8(a1, a2, v27, v26, a5);
    if ( result >= 0 )
    {
      sub_168560(v16 + 4, 11);
      sub_15E3A8((int)v14, a1[1], *a1, 0, *a1, a1[1], 58);
      *(_DWORD *)&v23[1] = 0;
      v24 = 0;
      v25 = 0;
      if ( byte_189858 && !sub_15F1E0() )
      {
        sub_168560(v16 + 2, (uint8_t)byte_189858);
        if ( (sub_168549(v16 + 2) & 0xC0) == 0xC0 )
        {
          *(_DWORD *)&v23[1] = 1;
          v24 = dword_18985C;
          if ( (uint8_t)byte_189858 < 0x41u )
          {
            if ( byte_189858 == 1 )
              v25 = 1;
          }
          else if ( (uint8_t)byte_189858 <= 0x41u )
          {
            v25 = 4;
          }
          else if ( (uint8_t)byte_189858 >= 0x81u )
          {
            if ( (uint8_t)byte_189858 <= 0x81u )
            {
              v25 = 8;
            }
            else if ( byte_189858 == -63 )
            {
              v25 = 14;
            }
          }
        }
        else
        {
          sub_168560(v16 + 2, 0);
        }
      }
      sub_15E37C(*a1, a1[1], v14, 58);
      sub_168549(v16 + 5);
      sub_168560(v16 + 1, 1);
      return 0;
    }
  }
  return result;
}
// 1897D8: using guessed type int dword_1897D8[8];
// 1897F8: using guessed type int dword_1897F8[8];
// 189818: using guessed type int dword_189818[8];
// 189838: using guessed type int dword_189838[8];
// 189858: using guessed type char byte_189858;
// 18985C: using guessed type int dword_18985C;


//----- (00153BD8) --------------------------------------------------------
int *__fastcall sub_153BD8(unsigned int a1, int a2, unsigned int a3, int a4, unsigned int a5)
{
  int v6; // eax
  int v7; // ebp
  int v9; // [esp+0h] [ebp-18h] BYREF
  int16_t v10; // [esp+4h] [ebp-14h]
  int v11; // [esp+8h] [ebp-10h]

  v11 = a2;
  sub_15E68C();
  v6 = sub_15E0F0(a1);
  v7 = v6;
  if ( !v6 )
    return sub_15F048();
  *(_BYTE *)(v6 + 18) = 7;
  *(_DWORD *)(v6 + 10) = a1;
  sub_15EF24(v6);
  sub_15EA74(1082, (int)&v9);
  *(_DWORD *)v7 = v9;
  *(_WORD *)(v7 + 4) = v10;
  if ( *(_WORD *)(v7 + 4) )
  {
    *(_DWORD *)(v7 + 43) = sub_1536B8;
    *(_DWORD *)(v7 + 27) = sub_1534B8;
    *(_DWORD *)(v7 + 31) = sub_153598;
    *(_DWORD *)(v7 + 35) = sub_152F00;
    *(_DWORD *)(v7 + 75) = sub_153300;
    *(_DWORD *)(v7 + 79) = sub_153348;
    *(_DWORD *)(v7 + 67) = sub_1531B8;
    *(_DWORD *)(v7 + 71) = sub_15325C;
    *(_DWORD *)(v7 + 83) = sub_153118;
    *(_DWORD *)(v7 + 87) = sub_152FCC;
    *(_DWORD *)(v7 + 39) = sub_152EC0;
    *(_DWORD *)(v7 + 51) = sub_153388;
    *(_DWORD *)(v7 + 55) = sub_153420;
    *(_DWORD *)(v7 + 59) = sub_152BCC;
    *(_DWORD *)(v7 + 63) = sub_152C3C;
    *(_DWORD *)(v7 + 91) = sub_152A5C;
    *(_DWORD *)(v7 + 99) = sub_1529B8;
    *(_DWORD *)(v7 + 107) = sub_152894;
    *(_DWORD *)(v7 + 111) = sub_152934;
    *(_DWORD *)(v7 + 115) = sub_153610;
    *(_DWORD *)(v7 + 103) = sub_152850;
    *(_DWORD *)(v7 + 95) = sub_15F884;
    *(_DWORD *)(v7 + 14) = sub_15396C((int *)v7, v11, a3, a4, a5);
    return (int *)v7;
  }
  else
  {
    sub_15F014(v7);
    return sub_15F048();
  }
}


//----- (00153D54) --------------------------------------------------------
int __fastcall sub_153D54(unsigned int a1, int *a2, int *a3)
{
  int v5; // eax
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // ebx

  if ( a1 >= 8 )
    return -2;
  if ( a3 )
  {
    if ( sub_15F090() )
      v5 = dword_1897F8[a1];
    else
      v5 = dword_1897D8[a1];
    *a3 = v5;
  }
  if ( a2 )
  {
    v6 = a1;
    if ( sub_15F090() )
      v7 = dword_189838[v6];
    else
      v7 = dword_189818[v6];
    *a2 = v7;
    v8 = *a2;
    if ( *a2 <= 15 )
    {
      if ( v8 >= 8 )
        *a2 = v8 - 8;
    }
    else
    {
      *a2 = v8 - 104;
    }
  }
  return 0;
}
// 1897D8: using guessed type int dword_1897D8[8];
// 1897F8: using guessed type int dword_1897F8[8];
// 189818: using guessed type int dword_189818[8];
// 189838: using guessed type int dword_189838[8];


//----- (00153DF4) --------------------------------------------------------
int __fastcall sub_153DF4(int result)
{
  dword_18985C = result;
  return result;
}
// 18985C: using guessed type int dword_18985C;


//----- (00153E1B) --------------------------------------------------------
char *sub_153E1B()
{
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  return (char *)&retaddr - dword_184A04;
}
// 153E1D: returning address of temporary local variable '%__return_address'
// 184A04: using guessed type int dword_184A04;


//----- (00153FD7) --------------------------------------------------------
int __cdecl sub_153FD7(int a1, int a2, int a3, int a4, int a5)
{
  if ( (a3 & 1) != 0 )
  {
    memcpy(a4, a2 + a1, a5);
  }
  else
  {
    lseek(a1, a2, 0);
    read(a1, a4, a5);
  }
  return a5 + a2;
}
// 13F35A: using guessed type int __fastcall memcpy(_DWORD, _DWORD, _DWORD);
// 14748B: using guessed type int __fastcall lseek(_DWORD, _DWORD, _DWORD);
// 15FF11: using guessed type int __fastcall read(_DWORD, _DWORD, _DWORD);


//----- (001540A6) --------------------------------------------------------
unsigned int __cdecl sub_1540A6(int a1)
{
  unsigned int v2; // [esp+0h] [ebp-8h]

  v2 = off_189864(a1);
  if ( v2 )
    sub_1543A1(v2, a1);
  return v2;
}
// 13CB78: using guessed type int __fastcall nmalloc(_DWORD);
// 189864: using guessed type int (__fastcall *off_189864)(_DWORD);


//----- (001540EC) --------------------------------------------------------
int __cdecl sub_1540EC(unsigned int a1, int a2)
{
  int result; // eax

  if ( a1 )
  {
    sub_1543D5(a1, a2);
    return off_189868(a1);
  }
  return result;
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);
// 189868: using guessed type int (__fastcall *off_189868)(_DWORD);


//----- (00154124) --------------------------------------------------------
int __cdecl sub_154124(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD v5[3]; // [esp+0h] [ebp-48h] BYREF
  int v6; // [esp+Ch] [ebp-3Ch]
  int v7; // [esp+18h] [ebp-30h]
  _DWORD v8[7]; // [esp+1Ch] [ebp-2Ch] BYREF
  int v9; // [esp+38h] [ebp-10h]
  unsigned int v10; // [esp+3Ch] [ebp-Ch]
  unsigned int v11; // [esp+40h] [ebp-8h]

  v8[0] = 256;
  v8[1] = a1;
  int386(49, v8, v5);
  if ( v7 )
  {
    v9 = 0;
  }
  else
  {
    *a3 = v5[0] << 16;
    *a2 = 16 * LOWORD(v5[0]);
    *a4 = (uint16_t)v6;
    v9 = 1;
  }
  if ( v9 )
  {
    v10 = *a3 >> 12;
    v11 = v10 + 16 * a1 - 1;
    sub_15421D(v10, v11);
  }
  return v9;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);


//----- (001541D2) --------------------------------------------------------
int __cdecl sub_1541D2(int a1, int a2, unsigned int a3)
{
  _BYTE v4[28]; // [esp+0h] [ebp-38h] BYREF
  _DWORD v5[7]; // [esp+1Ch] [ebp-1Ch] BYREF

  v5[0] = 257;
  v5[3] = a3;
  return int386(49, v5, v4);
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);


//----- (0015421D) --------------------------------------------------------
bool __cdecl sub_15421D(unsigned int a1, unsigned int a2)
{
  unsigned int v3; // [esp+0h] [ebp-54h]
  unsigned int v4; // [esp+4h] [ebp-50h]
  _DWORD v5[7]; // [esp+Ch] [ebp-48h] BYREF
  _BYTE v6[24]; // [esp+28h] [ebp-2Ch] BYREF
  int v7 = 0; // [esp+40h] [ebp-14h]
  int v8; // [esp+44h] [ebp-10h]
  unsigned int v9; // [esp+48h] [ebp-Ch]
  unsigned int v10; // [esp+4Ch] [ebp-8h]

  v8 = 0;
  if ( a1 >= a2 )
    v3 = a2;
  else
    v3 = a1;
  v9 = v3;
  if ( a1 < a2 )
    v4 = a2;
  else
    v4 = a1;
  v10 = v4 - v9 + 1;
  v5[0] = 1536;
  v5[1] = HIWORD(v9);
  v5[2] = (uint16_t)v9;
  v5[4] = HIWORD(v10);
  v5[5] = (uint16_t)(v4 - v9 + 1);
  int386(49, v5, v6);
  return v7 == 0;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);


//----- (001542DF) --------------------------------------------------------
bool __cdecl sub_1542DF(unsigned int a1, unsigned int a2)
{
  unsigned int v3; // [esp+0h] [ebp-54h]
  unsigned int v4; // [esp+4h] [ebp-50h]
  _DWORD v5[7]; // [esp+Ch] [ebp-48h] BYREF
  _BYTE v6[24]; // [esp+28h] [ebp-2Ch] BYREF
  int v7; // [esp+40h] [ebp-14h]
  int v8; // [esp+44h] [ebp-10h]
  unsigned int v9; // [esp+48h] [ebp-Ch]
  unsigned int v10; // [esp+4Ch] [ebp-8h]

  v8 = 0;
  if ( a1 >= a2 )
    v3 = a2;
  else
    v3 = a1;
  v9 = v3;
  if ( a1 < a2 )
    v4 = a2;
  else
    v4 = a1;
  v10 = v4 - v9 + 1;
  v5[0] = 1537;
  v5[1] = HIWORD(v9);
  v5[2] = (uint16_t)v9;
  v5[4] = HIWORD(v10);
  v5[5] = (uint16_t)(v4 - v9 + 1);
  int386(49, v5, v6);
  return v7 == 0;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);


//----- (001543A1) --------------------------------------------------------
bool __cdecl sub_1543A1(unsigned int a1, int a2)
{
  return sub_15421D(a1, a2 + a1);
}


//----- (001543D5) --------------------------------------------------------
bool __cdecl sub_1543D5(unsigned int a1, int a2)
{
  return sub_1542DF(a1, a2 + a1);
}


//----- (00154409) --------------------------------------------------------
int __cdecl sub_154409(int a1, int a2)
{
  _BYTE v3[64]; // [esp+0h] [ebp-E0h] BYREF
  int v4; // [esp+40h] [ebp-A0h]
  unsigned int v5; // [esp+44h] [ebp-9Ch]
  _DWORD v6[6]; // [esp+ACh] [ebp-34h] BYREF
  int v7; // [esp+C4h] [ebp-1Ch] BYREF
  int v8; // [esp+C8h] [ebp-18h]
  int v9; // [esp+CCh] [ebp-14h]
  unsigned int i; // [esp+D0h] [ebp-10h]
  int v11; // [esp+D4h] [ebp-Ch] BYREF
  int v12; // [esp+D8h] [ebp-8h]

  v7 = 8224;
  v12 = 0;
  if ( (a2 & 1) != 0 )
  {
    v9 = a1;
  }
  else
  {
    v9 = open(a1, 512);
    if ( v9 == -1 )
      return 0;
  }
  v8 = sub_153FD7(v9, 60, a2, (int)&v11, 4);
  v8 = sub_153FD7(v9, v11, a2, (int)&v7, 2);
  if ( !strcmp(&v7, &unk_17C274) )
  {
    sub_153FD7(v9, v11, a2, (int)v3, 172);
    v8 = v4 + v11;
    for ( i = 0; i < v5; ++i )
    {
      v8 = sub_153FD7(v9, v8, a2, (int)v6, 24);
      v12 += v6[0];
    }
    if ( (a2 & 1) == 0 )
      close(v9);
    v12 += 15 * v5;
    return v12;
  }
  else
  {
    close(v9);
    return 0;
  }
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 16000C: using guessed type int __fastcall close(_DWORD);


//----- (00154A9A) --------------------------------------------------------
int __cdecl sub_154A9A(int a1)
{
  int v2; // [esp+0h] [ebp-Ch]
  int v3; // [esp+4h] [ebp-8h]

  dword_189860 = 0;
  v2 = open(a1, 512);
  if ( v2 == -1 )
  {
    dword_189860 = 3;
    return -1;
  }
  else
  {
    v3 = filelength(v2);
    if ( v3 == -1 )
      dword_189860 = 5;
    close(v2);
    return v3;
  }
}
// 16000C: using guessed type int __fastcall close(_DWORD);
// 16002C: using guessed type int __fastcall filelength(_DWORD);
// 189860: using guessed type int dword_189860;


//----- (00154B18) --------------------------------------------------------
int __cdecl sub_154B18(int a1, int a2)
{
  int v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+8h] [ebp-14h]
  int v5; // [esp+Ch] [ebp-10h]

  dword_189860 = 0;
  v5 = sub_154A9A(a1);
  if ( v5 == -1 )
  {
    dword_189860 = 3;
    return 0;
  }
  else
  {
    if ( a2 )
      v3 = a2;
    else
      v3 = off_189864(v5);
    if ( v3 )
    {
      v4 = open(a1, 512);
      if ( v4 == -1 )
      {
        off_189868(v3);
        dword_189860 = 3;
        return 0;
      }
      else if ( read(v4, v3, v5) == v5 )
      {
        close(v4);
        return v3;
      }
      else
      {
        off_189868(v3);
        dword_189860 = 5;
        return 0;
      }
    }
    else
    {
      dword_189860 = 2;
      return 0;
    }
  }
}
// 15FF11: using guessed type int __fastcall read(_DWORD, _DWORD, _DWORD);
// 16000C: using guessed type int __fastcall close(_DWORD);
// 189860: using guessed type int dword_189860;
// 189864: using guessed type int (__fastcall *off_189864)(_DWORD);
// 189868: using guessed type int (__fastcall *off_189868)(_DWORD);


//----- (00154D80) --------------------------------------------------------
void sub_154D80()
{
  ++dword_189A02;
}
// 189A02: using guessed type int dword_189A02;


//----- (00154D8D) --------------------------------------------------------
void sub_154D8D()
{
  --dword_189A02;
}
// 189A02: using guessed type int dword_189A02;


//----- (00154D9A) --------------------------------------------------------
int __usercall sub_154D9A(
        int32_t a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int32_t a6,
        int32_t a7)
{
  int v7; // edx
  unsigned int i; // edi
  unsigned int v9; // eax
  unsigned int j; // edi
  int32_t v11; // eax
  int32_t v12; // ecx
  int32_t v13; // eax
  _DWORD v15[10]; // [esp-30h] [ebp-30h] BYREF
  int32_t v16; // [esp-8h] [ebp-8h] BYREF
  int32_t v17; // [esp-4h] [ebp-4h] BYREF
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h] BYREF

  if ( dword_1899FE )
  {
    v17 = a1;
    hr_outbyte(0x20u, 0x20u);
    /* __asm: iret */ DECOMP_TODO("inline asm");
  }
  v17 = a7;
  v16 = a6;
  v15[9] = a5;
  v15[8] = retaddr;
  v15[7] = a4;
  v15[6] = a3;
  v15[5] = a2;
  v15[4] = a1;
  v15[3] = (uint16_t)__DS__;
  v15[2] = (uint16_t)__ES__;
  v15[1] = (uint16_t)__FS__;
  v15[0] = (uint16_t)__GS__;
  __DS__ = word_189A06;
  dword_1899FE = 1;
  word_18A414 = __SS__;
  dword_18A418 = (int)v15;
  v7 = dword_1899FA;
  for ( i = 0; i < 16; ++i )
  {
    if ( dword_1898AC[i] == 2 )
    {
      v9 = v7 + dword_1898EC[i];
      if ( v9 >= dword_18992C[i] )
      {
        v9 -= dword_18992C[i];
        ++dword_18996C[i];
      }
      dword_1898EC[i] = v9;
    }
  }
  hr_outbyte(0x20u, 0x20u);
  _enable();
  if ( dword_189A02 <= 0 )
  {
    for ( j = 0; j < 15; ++j )
    {
      while ( dword_18996C[j] )
      {
        --dword_18996C[j];
        ((void (__stdcall *)(int))dword_18986C[j])(dword_1899AC[j]);
      }
    }
  }
  if ( !dword_1899A8 )
  {
    --dword_1899FE;
    /* __asm: iret */ DECOMP_TODO("inline asm");
  }
  --dword_1899A8;
  --dword_1899FE;
  v11 = (uint16_t)word_1899F0;
  v12 = _InterlockedExchange(&v16, dword_1899EC);
  v13 = _InterlockedExchange(&v17, v11);
  return ((int(*)())(void*)MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr))(v13, v17, v16, v12);
}
// 154D9A: could not find valid save-restore pair for ebx
// 154D9A: could not find valid save-restore pair for ebp
// 154D9A: could not find valid save-restore pair for edi
// 154D9A: could not find valid save-restore pair for esi
// 18986C: using guessed type int dword_18986C[];
// 1898AC: using guessed type int dword_1898AC[];
// 1898EC: using guessed type int dword_1898EC[];
// 18992C: using guessed type int dword_18992C[];
// 18996C: using guessed type int dword_18996C[];
// 1899A8: using guessed type int dword_1899A8;
// 1899AC: using guessed type int dword_1899AC[];
// 1899EC: using guessed type int dword_1899EC;
// 1899F0: using guessed type int16_t word_1899F0;
// 1899FA: using guessed type int dword_1899FA;
// 1899FE: using guessed type int dword_1899FE;
// 189A02: using guessed type int dword_189A02;
// 189A06: using guessed type int16_t word_189A06;
// 18A414: using guessed type int16_t word_18A414;
// 18A418: using guessed type int dword_18A418;


//----- (00154EC0) --------------------------------------------------------
char __cdecl sub_154EC0(int a1)
{
  unsigned int v1; // kr00_4
  uint8_t v2; // ah
  char result; // al
  _BOOL1 v4; // zf
  _UNKNOWN *retaddr = 0; // [esp+10h] [ebp+4h]

  v1 = hr_readeflags();
  _disable();
  hr_outbyte(0x43u, 0x36u);
  v2 = BYTE1(a1);
  dword_1899F6 = a1;
  hr_outbyte(0x40u, a1);
  result = BYTE1(a1);
  hr_outbyte(0x40u, v2);
  v4 = (BYTE1(retaddr) & 2) == 0;
  _disable();
  if ( !v4 )
    _enable();
  hr_writeeflags(v1);
  return result;
}
// 1899F6: using guessed type int dword_1899F6;


//----- (00154EF0) --------------------------------------------------------
char __cdecl sub_154EF0(unsigned int a1)
{
  int v1; // eax

  v1 = 0;
  if ( a1 < 0xD68D )
    v1 = 10000 * (uint64_t)a1 / 0x20BC;
  return sub_154EC0(v1);
}


//----- (00154F23) --------------------------------------------------------
void sub_154F23()
{
  unsigned int v0; // ecx
  unsigned int i; // edi

  sub_13F949();
  v0 = -1;
  for ( i = 0; i < 16; ++i )
  {
    if ( dword_1898AC[i] && dword_18992C[i] < v0 )
      v0 = dword_18992C[i];
  }
  if ( v0 != dword_1899FA )
  {
    dword_1899FA = v0;
    sub_154EF0(v0);
    memset(dword_1898EC, 0, 0x40u);
  }
  sub_13F94E();
}
// 1898AC: using guessed type int dword_1898AC[];
// 1898EC: using guessed type int dword_1898EC[];
// 18992C: using guessed type int dword_18992C[];
// 1899FA: using guessed type int dword_1899FA;


//----- (00154F88) --------------------------------------------------------
void __fastcall sub_154F88(int a1, unsigned int a2)
{
  unsigned int v2; // kr00_4
  _BOOL1 v3; // zf
  char v4; // [esp-7h] [ebp-13h]

  v2 = hr_readeflags();
  v4 = BYTE1(v2);
  _disable();
  word_189A06 = __DS__;
  sub_155752();
  dword_1899FE = 0;
  dword_189A02 = 0;
  dword_1899FA = -1;
  dword_189A08 = -1;
  memset(dword_1898AC, 0, 0x40u);
  memset(dword_1898EC, 0, 0x40u);
  memset(dword_18992C, 0, 0x40u);
  memset(dword_18996C, 0, 0x40u);
  /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
  /* __asm: int     21h; DOS - 2+ - GET INTERRUPT VECTOR */ DECOMP_TODO("inline asm");
  dword_1899EC = 8;
  word_1899F0 = __DS__;
  dword_1899F2 = a2;
  /* __asm: int     21h; DOS - SET INTERRUPT VECTOR */ DECOMP_TODO("inline asm");
  dword_1898E8 = 2;
  sub_140287(60, 54925);
  v3 = (v4 & 2) == 0;
  _disable();
  if ( !v3 )
    _enable();
  hr_writeeflags(v2);
}
// 1898AC: using guessed type int dword_1898AC[];
// 1898E8: using guessed type int dword_1898E8;
// 1898EC: using guessed type int dword_1898EC[];
// 18992C: using guessed type int dword_18992C[];
// 18996C: using guessed type int dword_18996C[];
// 1899EC: using guessed type int dword_1899EC;
// 1899F0: using guessed type int16_t word_1899F0;
// 1899F2: using guessed type int dword_1899F2;
// 1899FA: using guessed type int dword_1899FA;
// 1899FE: using guessed type int dword_1899FE;
// 189A02: using guessed type int dword_189A02;
// 189A06: using guessed type int16_t word_189A06;
// 189A08: using guessed type int dword_189A08;


//----- (00155076) --------------------------------------------------------
int sub_155076()
{
  unsigned int v0; // kr00_4
  int result; // eax
  _BOOL1 v2; // zf
  char v3; // [esp-3h] [ebp-Fh]

  v0 = hr_readeflags();
  v3 = BYTE1(v0);
  _disable();
  sub_154EC0(0);
  result = 9480;
  /* __asm: int     21h; DOS - SET INTERRUPT VECTOR */ DECOMP_TODO("inline asm");
  v2 = (v3 & 2) == 0;
  _disable();
  if ( !v2 )
    _enable();
  hr_writeeflags(v0);
  return result;
}
// 1899EC: using guessed type int dword_1899EC;
// 1899F0: using guessed type int16_t word_1899F0;


//----- (001550B1) --------------------------------------------------------
int __fastcall sub_1550B1(int a1, int a2, int a3, int a4)
{
  int v4; // ecx

  /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
  v4 = a4 << 16;
  LOWORD(v4) = a2;
  /* __asm: int     21h; DOS - 2+ - GET INTERRUPT VECTOR */ DECOMP_TODO("inline asm");
  return v4;
}


//----- (001550DD) --------------------------------------------------------
int sub_1550DD()
{
  int result; // eax

  result = 513;
  /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
  return result;
}


//----- (00155149) --------------------------------------------------------
void sub_155149()
{
  /* __asm: retfw */ DECOMP_TODO("inline asm");
}
// 15514C: control flows out of bounds to 15514E


//----- (00155159) --------------------------------------------------------
// write access to memory has been detected, the output may be wrong!
int __cdecl sub_155159(int a1, int a2, int a3)
{
  int result; // eax

  if ( dword_189A08 == -1 )
  {
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: lar     ecx, edx */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: lar     ecx, edx */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: lar     ecx, edx */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    /* __asm: lar     ecx, edx */ DECOMP_TODO("inline asm");
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    dword_155120 = (int)&unk_189A14 - ((unsigned int)&unk_189A14 & 0xFFFFFFF0) + 512;
    word_15511A = 0;
    word_15510B = 0;
    word_155140 = 0;
    word_155147 = a3;
    word_155136 = (uint16_t)&dword_155104 - ((unsigned int)&dword_155104 & 0xFFFFFFF0) + 74;
    dword_189A08 = a1;
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    dword_189A0C = 49407;
    dword_189A10 = __DS__;
    result = 517;
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
  }
  return result;
}
// 1552F6: write access to memory at 155120 has been detected
// 1552FE: write access to memory at 15511A has been detected
// 155307: write access to memory at 15510B has been detected
// 155310: write access to memory at 155140 has been detected
// 155319: write access to memory at 155147 has been detected
// 155327: write access to memory at 155136 has been detected
// 155104: using guessed type int dword_155104;
// 15510B: using guessed type int16_t word_15510B;
// 15511A: using guessed type int16_t word_15511A;
// 155120: using guessed type int dword_155120;
// 155136: using guessed type int16_t word_155136;
// 155140: using guessed type int16_t word_155140;
// 155147: using guessed type int16_t word_155147;
// 189A08: using guessed type int dword_189A08;
// 189A0C: using guessed type int dword_189A0C;
// 189A10: using guessed type int dword_189A10;


//----- (0015536F) --------------------------------------------------------
int __cdecl sub_15536F(int a1)
{
  int result; // eax

  if ( a1 != -1 && a1 == dword_189A08 )
  {
    result = 517;
    /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
    dword_189A08 = -1;
  }
  return result;
}
// 189A08: using guessed type int dword_189A08;
// 189A0C: using guessed type int dword_189A0C;
// 189A10: using guessed type int dword_189A10;


//----- (001553B4) --------------------------------------------------------
unsigned int sub_1553B4()
{
  unsigned int v0; // kr00_4
  unsigned int result; // eax

  v0 = hr_getcallerseflags();
  result = v0;
  _disable();
  return result;
}


//----- (001553B8) --------------------------------------------------------
void __cdecl sub_1553B8(unsigned int a1)
{
  _BOOL1 v1; // zf
  _UNKNOWN *retaddr; // [esp+4h] [ebp+4h]

  v1 = (BYTE1(retaddr) & 2) == 0;
  _disable();
  if ( !v1 )
    _enable();
  hr_writeeflags(a1);
}


//----- (0015541F) --------------------------------------------------------
int __cdecl sub_15541F(int a1, int a2, _WORD *a3, _WORD *a4)
{
  int16_t v8; // dx
  int16_t v9; // si
  int16_t v10; // di
  int16_t v11; // cx
  int16_t v12; // dx
  int16_t v13; // si
  int16_t v14; // di
  int v16; // [esp-Ch] [ebp-54h]
  _WORD v17[25]; // [esp+Eh] [ebp-3Ah] BYREF

  sub_13F949();
  memset(v17, 0, sizeof(v17));
  _CF = __CFSHR__(50, 2);
  _ZF = 0;
  _SF = 0;
  v17[18] = 0;
  v17[17] = 0;
  /* __asm: pushfw */ DECOMP_TODO("inline asm");
  v17[16] = 0;
  v17[14] = a2;
  if ( a3 )
  {
    v8 = a3[3];
    v9 = a3[4];
    v10 = a3[5];
    v17[12] = a3[2];
    v17[10] = v8;
    v17[2] = v9;
    v17[0] = v10;
  }
  v17[8] = *(_WORD *)(*(_DWORD *)(a1 + 8) + 50);
  /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
  if ( a4 )
  {
    v11 = v17[12];
    v12 = v17[10];
    v13 = v17[2];
    v14 = v17[0];
    *a4 = v17[14];
    a4[2] = v11;
    a4[3] = v12;
    a4[4] = v13;
    a4[5] = v14;
    a4[1] = v17[8];
  }
  v16 = v17[14];
  sub_13F94E();
  return v16;
}


//----- (001554F9) --------------------------------------------------------
uint8_t __cdecl sub_1554F9(int a1)
{
  uint8_t result; // al
  uint16_t v2; // dx
  int i; // ecx
  uint8_t v4; // al

  result = MEMORY[0x463];
  v2 = MEMORY[0x463] + 6;
  for ( i = a1; i; --i )
  {
    do
      v4 = hr_inbyte(v2);
    while ( (v4 & 8) == 0 );
    do
      result = hr_inbyte(v2);
    while ( (result & 8) != 0 );
  }
  return result;
}


//----- (00155536) --------------------------------------------------------
int sub_155536()
{
  return dword_1899FE;
}
// 1899FE: using guessed type int dword_1899FE;


//----- (00155542) --------------------------------------------------------
unsigned int __cdecl sub_155542(int a1)
{
  unsigned int v1; // eax
  unsigned int v3; // [esp-4h] [ebp-10h]

  sub_13F949();
  v1 = 0;
  while ( *(int *)((char *)dword_1898AC + v1) )
  {
    v1 += 4;
    if ( v1 >= 0x3C )
    {
      v1 = -1;
      goto LABEL_6;
    }
  }
  *(int *)((char *)dword_1898AC + v1) = 1;
  *(int *)((char *)dword_18986C + v1) = a1;
LABEL_6:
  v3 = v1;
  sub_13F94E();
  return v3;
}
// 18986C: using guessed type int dword_18986C[];
// 1898AC: using guessed type int dword_1898AC[];


//----- (00155589) --------------------------------------------------------
int32_t __cdecl sub_155589(int a1, int32_t a2)
{
  int32_t v2; // eax
  int32_t v4; // [esp-4h] [ebp-10h]

  sub_13F949();
  if ( a1 != -1 )
    v2 = _InterlockedExchange((int *)((char *)dword_1899AC + a1), a2);
  v4 = v2;
  sub_13F94E();
  return v4;
}
// 1555A5: variable 'v2' is possibly undefined
// 1899AC: using guessed type int dword_1899AC[];


//----- (001555B1) --------------------------------------------------------
void __cdecl sub_1555B1(int a1)
{
  sub_13F949();
  if ( a1 != -1 )
    *(int *)((char *)dword_1898AC + a1) = 0;
  sub_13F94E();
}
// 1898AC: using guessed type int dword_1898AC[];


//----- (001555D8) --------------------------------------------------------
void sub_1555D8()
{
  int v0; // esi
  _BOOL1 v1; // sf
  _BOOL1 v2; // of

  sub_13F949();
  v0 = 56;
  do
  {
    sub_140665(v0);
    v2 = __OFSUB__(v0, 4);
    v1 = v0 - 4 < 0;
    v0 -= 4;
  }
  while ( v1 == v2 );
  sub_13F94E();
}


//----- (001555FC) --------------------------------------------------------
void __cdecl sub_1555FC(int a1)
{
  sub_13F949();
  if ( a1 != -1 && *(int *)((char *)dword_1898AC + a1) == 1 )
    *(int *)((char *)dword_1898AC + a1) = 2;
  sub_13F94E();
}
// 1898AC: using guessed type int dword_1898AC[];


