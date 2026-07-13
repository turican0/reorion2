#include "orion_common.h"

/* Adresni rozsah: 0x1642A0 - 0x166150  (200 funkci) */

//----- (001642A0) --------------------------------------------------------
char __usercall sub_1642A0(
        int a1,
        _DWORD *a2,
        unsigned int a3,
        int *a4,
        unsigned int *a5)
{
  char v5; // bl
  unsigned int v6; // ebp
  char v7; // al
  char v8; // cl
  char v9; // al
  unsigned int v10; // ebp
  char v11; // ah
  char v12; // bl
  unsigned int v13; // ebp
  char v14; // al
  char v15; // cl
  char v16; // al
  unsigned int v17; // ebp
  int16_t v18; // ax
  char v19; // t0
  char v20; // bl
  unsigned int v21; // ebp
  char v22; // al
  char v23; // cl
  char v24; // al
  unsigned int v25; // ebp
  char v26; // ah
  char v27; // bl
  unsigned int v28; // ebp
  char v29; // al
  char v30; // cl
  char v31; // al
  unsigned int v32; // ebp
  int16_t v33; // ax
  char v34; // t1
  char v35; // bl
  unsigned int v36; // ebp
  char v37; // al
  char v38; // cl
  char v39; // al
  unsigned int v40; // ebp
  char v41; // ah
  char v42; // bl
  unsigned int v43; // ebp
  char v44; // al
  char v45; // cl
  char v46; // al
  unsigned int v47; // ebp
  char v48; // t2
  char v49; // cf
  int *v50; // ecx
  int *v51; // edx
  int i; // ecx
  int v53; // eax
  int *v54; // edx
  int j; // ecx
  int v56; // eax
  int *v58; // [esp-Ch] [ebp-Ch]
  int v59; // [esp-8h] [ebp-8h]

  if ( (uint8_t)byte_18A6C0 < 9u )
  {
    v8 = byte_18A6C0;
    byte_18A6C0 += 24;
    v9 = a3;
    --v8;
    v10 = *a5;
    v7 = (*a5++ << v8) | v9;
    v6 = v10 >> ~(v8 - 9);
  }
  else
  {
    v5 = a3;
    byte_18A6C0 -= 8;
    v6 = a3 >> 8;
    v7 = v5;
  }
  v11 = v7;
  if ( (uint8_t)byte_18A6C0 < 9u )
  {
    v15 = byte_18A6C0;
    byte_18A6C0 += 24;
    v16 = v6;
    --v15;
    v17 = *a5;
    v14 = (*a5++ << v15) | v16;
    v13 = v17 >> ~(v15 - 9);
  }
  else
  {
    v12 = v6;
    byte_18A6C0 -= 8;
    v13 = v6 >> 8;
    v14 = v12;
  }
  v19 = v11;
  HIBYTE(v18) = v14;
  LOBYTE(v18) = v19;
  word_18A7E0 = v18;
  if ( (uint8_t)byte_18A6C0 < 9u )
  {
    v23 = byte_18A6C0;
    byte_18A6C0 += 24;
    v24 = v13;
    --v23;
    v25 = *a5;
    v22 = (*a5++ << v23) | v24;
    v21 = v25 >> ~(v23 - 9);
  }
  else
  {
    v20 = v13;
    byte_18A6C0 -= 8;
    v21 = v13 >> 8;
    v22 = v20;
  }
  v26 = v22;
  if ( (uint8_t)byte_18A6C0 < 9u )
  {
    v30 = byte_18A6C0;
    byte_18A6C0 += 24;
    v31 = v21;
    --v30;
    v32 = *a5;
    v29 = (*a5++ << v30) | v31;
    v28 = v32 >> ~(v30 - 9);
  }
  else
  {
    v27 = v21;
    byte_18A6C0 -= 8;
    v28 = v21 >> 8;
    v29 = v27;
  }
  v34 = v26;
  HIBYTE(v33) = v29;
  LOBYTE(v33) = v34;
  word_18A7E2 = v33;
  if ( (uint8_t)byte_18A6C0 < 9u )
  {
    v38 = byte_18A6C0;
    byte_18A6C0 += 24;
    v39 = v28;
    --v38;
    v40 = *a5;
    v37 = (*a5++ << v38) | v39;
    v36 = v40 >> ~(v38 - 9);
  }
  else
  {
    v35 = v28;
    byte_18A6C0 -= 8;
    v36 = v28 >> 8;
    v37 = v35;
  }
  v41 = v37;
  if ( (uint8_t)byte_18A6C0 < 9u )
  {
    v45 = byte_18A6C0;
    byte_18A6C0 += 24;
    v46 = v36;
    --v45;
    v47 = *a5;
    v44 = (*a5++ << v45) | v46;
    v43 = v47 >> ~(v45 - 9);
  }
  else
  {
    v42 = v36;
    byte_18A6C0 -= 8;
    v43 = v36 >> 8;
    v44 = v42;
  }
  v48 = v41;
  BYTE1(a1) = v44;
  LOBYTE(a1) = v48;
  word_18A7E4 = a1;
  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
  v59 = -2;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !--byte_18A6C0 )
      {
        v43 = *a5++;
        byte_18A6C0 = 32;
      }
      v49 = v43 & 1;
      v43 >>= 1;
      if ( !v49 )
        break;
      if ( v59 == -2 )
        v59 = -2;
      ++a4;
    }
    v50 = (int *)v59;
    if ( v59 == -1 )
      break;
    v59 = (int)a2;
    v58 = v50;
    v51 = (int *)dword_18A68C;
    for ( i = *(_DWORD *)dword_18A68C; *v51 >= 0; i = *v51 )
    {
      if ( !--byte_18A6C0 )
      {
        v43 = *a5++;
        byte_18A6C0 = 32;
      }
      v49 = v43 & 1;
      v43 >>= 1;
      if ( !v49 )
        i = 4;
      v51 = (int *)((char *)v51 + i);
    }
    LOWORD(a1) = i;
    v53 = a1 << 24;
    v54 = (int *)dword_18A690;
    for ( j = *(_DWORD *)dword_18A690; *v54 >= 0; j = *v54 )
    {
      if ( !--byte_18A6C0 )
      {
        v43 = *a5++;
        byte_18A6C0 = 32;
      }
      v49 = v43 & 1;
      v43 >>= 1;
      if ( !v49 )
        j = 4;
      v54 = (int *)((char *)v54 + j);
    }
    LOWORD(v53) = j;
    a2 = (_DWORD *)v59;
    v56 = __ROL4__(v53, 8);
    if ( word_18A7E0 == (_WORD)v56 )
    {
      v56 = 0;
      *(_DWORD *)(v59 + 4) = a4;
    }
    else if ( word_18A7E2 == (_WORD)v56 )
    {
      v56 = 0;
      *(_DWORD *)(v59 + 8) = a4;
    }
    else if ( word_18A7E4 == (_WORD)v56 )
    {
      v56 = 0;
      *(_DWORD *)(v59 + 12) = a4;
    }
    a1 = v56 << 16;
    LOBYTE(a1) = 1;
    *a4++ = a1;
    if ( v58 != (int *)-2 )
    {
      a1 = ((char *)a4 - (char *)v58) << 13;
      *v58 = a1;
    }
  }
  if ( !a2[1] )
    a2[1] = a4;
  if ( !a2[2] )
    a2[2] = ++a4;
  if ( !a2[3] )
    a2[3] = a4 + 1;
  return a1;
}
// 18A68C: using guessed type int dword_18A68C;
// 18A690: using guessed type int dword_18A690;
// 18A6C0: using guessed type char byte_18A6C0;
// 18A7E0: using guessed type int16_t word_18A7E0;
// 18A7E2: using guessed type int16_t word_18A7E2;
// 18A7E4: using guessed type int16_t word_18A7E4;


//----- (00164590) --------------------------------------------------------
int __usercall sub_164590(int a1, int a2)
{
  int v2; // ebp
  int result; // eax
  char v4; // cl
  unsigned int *v5; // edx
  unsigned int i; // ebp
  unsigned int v7; // ebp
  char v8; // cf
  int v9; // edx
  int v10; // [esp-4h] [ebp-8h]

  dword_18A678 = a1;
  v2 = dword_18A6B4;
  do
  {
    v10 = v2;
    LOWORD(result) = v2 - 1;
    v4 = dword_18A6B0;
    v5 = (unsigned int *)dword_18A678;
    for ( i = *(_DWORD *)dword_18A678; !(uint16_t)*v5; i = *v5 )
    {
      v7 = (unsigned int)&loc_FFFF8 & (i >> 13);
      if ( !v4 )
        break;
      --v4;
      v8 = result & 1;
      LOWORD(result) = (uint16_t)result >> 1;
      if ( !v8 )
        v7 = 4;
      v5 = (unsigned int *)((char *)v5 + v7);
    }
    v9 = ((_DWORD)v5 - dword_18A6A4) << 8;
    LOBYTE(v9) = dword_18A6B0 - v4;
    *(_DWORD *)(a2 + 4 * v10 - 4) = v9;
    v2 = v10 - 1;
  }
  while ( v10 != 1 );
  return result;
}
// 18A678: using guessed type int dword_18A678;
// 18A6A4: using guessed type int dword_18A6A4;
// 18A6B0: using guessed type int dword_18A6B0;
// 18A6B4: using guessed type int dword_18A6B4;


//----- (00164600) --------------------------------------------------------
int __usercall sub_164600(
        int result,
        _DWORD *a2,
        unsigned int a3,
        int a4,
        unsigned int *a5)
{
  char v5; // cf
  unsigned int v6; // ebp
  unsigned int v7; // ebp
  unsigned int v8; // ebp
  int *v9; // [esp-10h] [ebp-10h]
  int v10; // [esp-8h] [ebp-8h]

  if ( !--byte_18A6C0 )
  {
    a3 = *a5++;
    byte_18A6C0 = 32;
  }
  v5 = a3 & 1;
  v6 = a3 >> 1;
  if ( v5 )
  {
    v10 = result;
    v9 = (int *)result;
    if ( !--byte_18A6C0 )
    {
      v6 = *a5++;
      byte_18A6C0 = 32;
    }
    v5 = v6 & 1;
    v7 = v6 >> 1;
    if ( v5 )
      sub_164200(v7, (unsigned int *)dword_18A68C, a5);
    if ( !--byte_18A6C0 )
    {
      v7 = *a5++;
      byte_18A6C0 = 32;
    }
    v5 = v7 & 1;
    v8 = v7 >> 1;
    if ( v5 )
      sub_164200(v8, (unsigned int *)dword_18A690, a5);
    sub_1642A0(result, a2, v8, v9, a5);
    return sub_164590(v10, a4);
  }
  else
  {
    *a2 = 0;
    a2[1] = result;
    a2[2] = result;
    a2[3] = result;
  }
  return result;
}
// 164600: could not find valid save-restore pair for edi
// 164678: variable 'result' is possibly undefined
// 18A68C: using guessed type int dword_18A68C;
// 18A690: using guessed type int dword_18A690;
// 18A6C0: using guessed type char byte_18A6C0;


//----- (00164690) --------------------------------------------------------
int sub_164690()
{
  return 29800;
}


//----- (001646A0) --------------------------------------------------------
unsigned int __cdecl sub_1646A0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // edi
  _DWORD *v7; // edi
  int v8; // ecx
  _BOOL1 v9; // zf
  _DWORD *v10; // edi
  unsigned int v11; // edx

  dword_18AC00 = a1;
  dword_18AC04 = a2;
  dword_18AC08 = a3;
  dword_18AC0C = a4;
  dword_18AC10 = a5;
  dword_18AC14 = a6;
  dword_18A68C = a1;
  dword_18A690 = a1 + 2048;
  byte_18A6C0 = 1;
  dword_18A6B0 = 11;
  dword_18A6B4 = 2048;
  dword_18A6A4 = a2;
  sub_164600(a2 + 29800, &dword_18A610, 0, a2 + 16, (unsigned int *)(a1 + 4096));
  dword_18A6B0 = 10;
  dword_18A6B4 = 1024;
  sub_164600(dword_18AC08 + dword_18AC04 + 29800, &dword_18A620, 0, dword_18AC04 + 8208, (unsigned int *)(a1 + 4096));
  dword_18A6B0 = 12;
  dword_18A6B4 = 4096;
  sub_164600(
    dword_18AC0C + dword_18AC08 + dword_18AC04 + 29800,
    &dword_18A630,
    0,
    dword_18AC04 + 12304,
    (unsigned int *)(a1 + 4096));
  dword_18A6B0 = 8;
  dword_18A6B4 = 256;
  sub_164600(
    dword_18AC10 + dword_18AC0C + dword_18AC08 + dword_18AC04 + 29800,
    &dword_18A640,
    0,
    dword_18AC04 + 28688,
    (unsigned int *)(a1 + 4096));
  v6 = (_DWORD *)dword_18AC04;
  *(_DWORD *)dword_18AC04 = dword_18AC08;
  v6[1] = dword_18AC0C;
  v6[2] = dword_18AC10;
  v6[3] = dword_18AC14;
  qmemcpy(v6 + 7429, &dword_18A610, 0x40u);
  memset((void *)dword_18AC00, 0, 0x2000u);
  v7 = (_DWORD *)dword_18AC00;
  sub_1649E0(*(_DWORD *)dword_18AC04, dword_18AC00, dword_18AC04);
  sub_1649E0(*(_DWORD *)(dword_18AC04 + 4), (int)v7, *(_DWORD *)dword_18AC04 + dword_18AC04);
  sub_1649E0(
    *(_DWORD *)(dword_18AC04 + 8),
    (int)v7,
    *(_DWORD *)(dword_18AC04 + 4) + *(_DWORD *)dword_18AC04 + dword_18AC04);
  sub_1649E0(
    *(_DWORD *)(dword_18AC04 + 12),
    (int)v7,
    *(_DWORD *)(dword_18AC04 + 8) + *(_DWORD *)(dword_18AC04 + 4) + *(_DWORD *)dword_18AC04 + dword_18AC04);
  v8 = 2048;
  do
  {
    if ( !v8 )
      break;
    v9 = *v7++ == -1;
    --v8;
  }
  while ( v9 );
  v10 = v7 - 1;
  _BitScanForward(&v11, ~*v10);
  LOWORD(dword_18A6D0) = v11 + 8 * ((_WORD)v10 - dword_18AC00);
  *(_WORD *)(dword_18AC04 + 29712) = dword_18A6D0;
  sub_164A10(*(_DWORD *)dword_18AC04, dword_18AC04);
  sub_164A10(*(_DWORD *)(dword_18AC04 + 4), *(_DWORD *)dword_18AC04 + dword_18AC04);
  sub_164A10(*(_DWORD *)(dword_18AC04 + 8), *(_DWORD *)(dword_18AC04 + 4) + *(_DWORD *)dword_18AC04 + dword_18AC04);
  return sub_164A10(
           *(_DWORD *)(dword_18AC04 + 12),
           *(_DWORD *)(dword_18AC04 + 8) + *(_DWORD *)(dword_18AC04 + 4) + *(_DWORD *)dword_18AC04 + dword_18AC04);
}
// 18A610: using guessed type _DWORD dword_18A610;
// 18A620: using guessed type _DWORD dword_18A620;
// 18A630: using guessed type _DWORD dword_18A630;
// 18A640: using guessed type _DWORD dword_18A640;
// 18A68C: using guessed type int dword_18A68C;
// 18A690: using guessed type int dword_18A690;
// 18A6A4: using guessed type int dword_18A6A4;
// 18A6B0: using guessed type int dword_18A6B0;
// 18A6B4: using guessed type int dword_18A6B4;
// 18A6C0: using guessed type char byte_18A6C0;
// 18A6D0: using guessed type int dword_18A6D0;
// 18AC00: using guessed type int dword_18AC00;
// 18AC04: using guessed type int dword_18AC04;
// 18AC08: using guessed type int dword_18AC08;
// 18AC0C: using guessed type int dword_18AC0C;
// 18AC10: using guessed type int dword_18AC10;
// 18AC14: using guessed type int dword_18AC14;


//----- (00164920) --------------------------------------------------------
int __usercall sub_164920(int a1)
{
  char *v2; // esi
  char *v3; // edi
  int v4; // ebx
  int v5; // ecx
  int v6; // ecx
  char *v7; // esi
  char *v8; // edi
  int v9; // ecx
  char *v10; // esi
  char *v11; // edi
  int v12; // ebx
  int v13; // ecx
  int result; // eax

  v2 = *(char **)(a1 + 2);
  v3 = *(char **)(a1 + 6);
  v4 = *(uint16_t *)(a1 + 10);
  if ( *(_WORD *)(a1 + 10) )
  {
    do
    {
      v5 = dword_18A674;
      qmemcpy(v3, v2, 4 * dword_18A674);
      v2 += 4 * v5;
      v3 += 4 * v5 + dword_18A680;
      --v4;
    }
    while ( v4 );
  }
  v6 = *(uint16_t *)(a1 + 12);
  qmemcpy(v3, v2, 4 * v6);
  v7 = &v2[4 * v6];
  dword_18A69C(*(_WORD *)(a1 + 14));
  v8 = (char *)(&v3[4 * v6] - (char *)sub_10000);
  v9 = *(uint16_t *)(a1 + 16);
  qmemcpy(v8, v7, 4 * v9);
  v10 = &v7[4 * v9];
  v11 = &v8[4 * v9 + dword_18A680];
  v12 = *(uint16_t *)(a1 + 18);
  if ( *(_WORD *)(a1 + 18) )
  {
    do
    {
      v13 = dword_18A674;
      qmemcpy(v11, v10, 4 * dword_18A674);
      v10 += 4 * v13;
      v11 += 4 * v13 + dword_18A680;
      --v12;
    }
    while ( v12 );
  }
  dword_18A660 = *(uint16_t *)(a1 + 20);
  dword_18A674 = *(uint16_t *)(a1 + 22);
  dword_18A668 = dword_18A674;
  dword_18A66C = *(uint16_t *)(a1 + 24);
  dword_18A684 = *(uint16_t *)(a1 + 26);
  dword_18A688 = *(uint16_t *)(a1 + 28);
  result = *(uint16_t *)(a1 + 30);
  dword_18A670 = result;
  dword_18A6A0 = a1 + 32;
  return result;
}
// 10000: using guessed type void __noreturn sub_10000();
// 18A660: using guessed type int dword_18A660;
// 18A668: using guessed type int dword_18A668;
// 18A66C: using guessed type int dword_18A66C;
// 18A670: using guessed type int dword_18A670;
// 18A674: using guessed type int dword_18A674;
// 18A680: using guessed type int dword_18A680;
// 18A684: using guessed type int dword_18A684;
// 18A688: using guessed type int dword_18A688;
// 18A69C: using guessed type int (__fastcall *dword_18A69C)(_DWORD);
// 18A6A0: using guessed type int dword_18A6A0;


//----- (001649E0) --------------------------------------------------------
unsigned int __usercall sub_1649E0(unsigned int a1, int a2, int a3)
{
  int v3; // esi
  unsigned int result; // eax

  v3 = a3 + 29800;
  result = a1 >> 2;
  do
  {
    while ( (*(_BYTE *)v3 & 1) == 0 )
    {
      v3 += 4;
      if ( !--result )
        return result;
    }
    *(_BYTE *)(a2 + (*(uint16_t *)(v3 + 2) >> 3)) |= 1 << (*(_WORD *)(v3 + 2) & 7);
    v3 += 4;
    --result;
  }
  while ( result );
  return result;
}


//----- (00164A10) --------------------------------------------------------
unsigned int __usercall sub_164A10(unsigned int a1, int a2)
{
  _WORD *v2; // esi
  unsigned int result; // eax
  int16_t v4; // bp

  v2 = (_WORD *)(a2 + 29800);
  result = a1 >> 2;
  v4 = dword_18A6D0;
  do
  {
    while ( (*(_BYTE *)v2 & 1) == 0 )
    {
      *v2 = v4;
      v2 += 2;
      if ( !--result )
        return result;
    }
    *v2 = v2[1];
    v2 += 2;
    --result;
  }
  while ( result );
  return result;
}
// 18A6D0: using guessed type int dword_18A6D0;


//----- (00164A40) --------------------------------------------------------
int __usercall sub_164A40(int a1, unsigned int a2, _DWORD *a3, unsigned int *a4)
{
  unsigned int v4; // ecx
  _BYTE *v5; // ebx
  _BYTE *v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // ebp
  unsigned int v9; // ecx
  unsigned int v10; // ebp
  char v11; // al
  unsigned int *v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // edx
  char v17; // cf
  int v18; // eax
  int *v19; // ebx
  int *v20; // ecx
  int v21; // edx
  int *v22; // ebx
  unsigned int v23; // edx
  unsigned int v24; // ebp
  unsigned int v25; // ecx
  char v26; // al
  unsigned int *v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // ecx
  unsigned int v30; // edx
  unsigned int v31; // edx
  int v32; // edx
  int v33; // edx
  int v34; // eax
  _DWORD *v35; // ecx
  int v36; // edx
  int v37; // edx
  uint8_t v38; // ch
  int v39; // eax
  _DWORD *v40; // edi
  int **v41; // edi
  int **v42; // edi
  _DWORD *v43; // edi
  _DWORD *v44; // eax
  _DWORD *v45; // edi
  int **v46; // edi
  int **v47; // edi
  int v48; // edi
  uint16_t *v50; // edi

  dword_18A7F4 += a1;
  if ( dword_18A7F0 <= (unsigned int)dword_18A7F4 )
  {
    v4 = (unsigned int)(dword_18A7F4 + 15) >> 4;
    if ( (unsigned int)dword_18A7F0 >> 4 != v4 )
    {
      v5 = (_BYTE *)(dword_18A7F8 + ((unsigned int)dword_18A7F0 >> 4));
      v6 = (_BYTE *)(dword_18A7F8 + v4);
      do
        *v5++ = 1;
      while ( v5 != v6 );
      v4 = (unsigned int)&v6[-dword_18A7F8];
    }
    dword_18A7F0 = 16 * v4;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      if ( (uint8_t)byte_18A6C0 > 0xAu )
      {
        v14 = *(_DWORD *)(dword_18A604 + 4 * (a2 & 0x3FF));
        v10 = a2 >> v14;
        v11 = byte_18A6C0 - v14;
        v12 = (unsigned int *)(dword_18A6A4 + (v14 >> 8));
        v13 = *v12;
        if ( (_WORD)dword_18A6D0 != (uint16_t)*v12 )
          goto LABEL_16;
      }
      else
      {
        v7 = *a4;
        a4 = (unsigned int *)((char *)a4 + 2);
        v8 = a2 | (v7 << (byte_18A6C0 - 1));
        v9 = *(_DWORD *)(dword_18A604 + 4 * (v8 & 0x3FF));
        v10 = v8 >> v9;
        v11 = byte_18A6C0 + 16 - v9;
        v12 = (unsigned int *)(dword_18A6A4 + (v9 >> 8));
        v13 = *v12;
        if ( (_WORD)dword_18A6D0 != (uint16_t)*v12 )
          goto LABEL_16;
      }
      do
      {
        v15 = v13 >> 13;
        if ( !--v11 )
        {
          v10 = *a4++;
          v11 = 32;
        }
        v16 = (unsigned int)&loc_FFFF8 & v15;
        v17 = v10 & 1;
        v10 >>= 1;
        if ( !v17 )
          v16 = 4;
        v12 = (unsigned int *)((char *)v12 + v16);
        v13 = *v12;
      }
      while ( (_WORD)dword_18A6D0 == (uint16_t)*v12 );
LABEL_16:
      byte_18A6C0 = v11;
      HIWORD(v18) = HIWORD(v13);
      if ( *(_DWORD *)dword_18A624 != v13 )
      {
        dword_18A678 = v13;
        v18 = *(_DWORD *)dword_18A624;
        v19 = (int *)dword_18A628;
        *(_DWORD *)dword_18A624 = v13;
        v20 = (int *)dword_18A62C;
        v21 = *v19;
        *v19 = v18;
        HIWORD(v18) = HIWORD(dword_18A678);
        *v20 = v21;
      }
      v22 = (int *)dword_18A6D0;
      if ( (uint8_t)byte_18A6C0 > 0xBu )
      {
        v29 = *(_DWORD *)(dword_18A600 + 4 * (v10 & 0x7FF));
        a2 = v10 >> v29;
        v26 = byte_18A6C0 - v29;
        v27 = (unsigned int *)(dword_18A6A4 + (v29 >> 8));
        v28 = *v27;
        if ( (_WORD)dword_18A6D0 != (uint16_t)*v27 )
          goto LABEL_27;
      }
      else
      {
        v23 = *a4;
        a4 = (unsigned int *)((char *)a4 + 2);
        v24 = v10 | (v23 << (byte_18A6C0 - 1));
        v25 = *(_DWORD *)(dword_18A600 + 4 * (v24 & 0x7FF));
        a2 = v24 >> v25;
        v26 = byte_18A6C0 + 16 - v25;
        v27 = (unsigned int *)(dword_18A6A4 + (v25 >> 8));
        v28 = *v27;
        if ( (_WORD)dword_18A6D0 != (uint16_t)*v27 )
          goto LABEL_27;
      }
      do
      {
        v30 = v28 >> 13;
        if ( !--v26 )
        {
          a2 = *a4++;
          v26 = 32;
        }
        v31 = (unsigned int)&loc_FFFF8 & v30;
        v17 = a2 & 1;
        a2 >>= 1;
        if ( !v17 )
          v31 = 4;
        v27 = (unsigned int *)((char *)v27 + v31);
        v28 = *v27;
      }
      while ( (_WORD)dword_18A6D0 == (uint16_t)*v27 );
LABEL_27:
      v32 = __ROR4__(v28, 16);
      byte_18A6C0 = v26;
      LOWORD(v18) = v32;
      v33 = __ROR4__(v32, 16);
      if ( *(_DWORD *)dword_18A614 != v33 )
      {
        dword_18A678 = v18;
        v34 = *(_DWORD *)dword_18A614;
        v22 = (int *)dword_18A618;
        *(_DWORD *)dword_18A614 = v33;
        v35 = (_DWORD *)dword_18A61C;
        v36 = *v22;
        *v22 = v34;
        v18 = dword_18A678;
        *v35 = v36;
      }
      HIWORD(v37) = HIWORD(v18);
      v38 = BYTE1(v18);
      LOWORD(v37) = __ROR4__(v18, 16);
      LOWORD(v39) = ((int16_t (__fastcall *)(int, int))funcs_164C45[(uint8_t)v18])((uint8_t)v18, v37);
      *a3 = v39;
      v40 = (_DWORD *)((char *)a3 + dword_18A660);
      *v40 = v39;
      v41 = (int **)((char *)v40 + dword_18A660);
      *v41 = v22;
      v42 = (int **)((char *)v41 + dword_18A660);
      *v42 = v22;
      v43 = (int **)((char *)v42 + dword_18A660);
      LOWORD(v44) = ((int16_t (__fastcall *)(int, int))funcs_164C45[v38])(v38, v37);
      *v43 = v44;
      v45 = (_DWORD *)((char *)v43 + dword_18A660);
      *v45 = v44;
      v46 = (int **)((char *)v45 + dword_18A660);
      *v46 = v22;
      v47 = (int **)((char *)v46 + dword_18A660);
      *v47 = v22;
      a3 = (int **)((char *)v47 - dword_18A66C);
      if ( !--dword_18A668 )
        break;
      if ( !--dword_18A664 )
        goto LABEL_44;
    }
    if ( !--dword_18A670 )
      break;
    a3 = (_DWORD *)((char *)a3 + dword_18A688);
LABEL_34:
    dword_18A668 = dword_18A674;
    if ( !--dword_18A664 )
LABEL_44:
      JUMPOUT(0x1675C0);
  }
  if ( (dword_18A6AC & 1) == 0 )
    goto LABEL_45;
  while ( 2 )
  {
    v48 = dword_18A6A0;
    LOWORD(v44) = *(_WORD *)dword_18A6A0;
    if ( *(_WORD *)dword_18A6A0 < 0xFFFDu )
    {
      dword_18A69C(v44);
LABEL_42:
      v50 = (uint16_t *)(v48 + 2);
      dword_18A660 = *v50;
      dword_18A674 = v50[1];
      dword_18A668 = dword_18A674;
      dword_18A66C = v50[2];
      dword_18A684 = v50[3];
      dword_18A688 = v50[4];
      v50 += 5;
      dword_18A670 = v50[2];
      v44 = *(_DWORD **)v50;
      dword_18A6A0 = (int)(v50 + 3);
      a3 = v44;
      if ( dword_18A670 )
        goto LABEL_34;
      continue;
    }
    break;
  }
  if ( (_WORD)v44 == 0xFFFE )
    goto LABEL_42;
  if ( (_WORD)v44 == 0xFFFF )
LABEL_45:
    JUMPOUT(0x1676C0);
  return sub_164920(dword_18A6A0);
}
// 164CAE: control flows out of bounds to 1675C0
// 164CFA: control flows out of bounds to 1676C0
// 164C4C: variable 'v39' is possibly undefined
// 164C7A: variable 'v44' is possibly undefined
// 18A600: using guessed type int dword_18A600;
// 18A604: using guessed type int dword_18A604;
// 18A614: using guessed type int dword_18A614;
// 18A618: using guessed type int dword_18A618;
// 18A61C: using guessed type int dword_18A61C;
// 18A624: using guessed type int dword_18A624;
// 18A628: using guessed type int dword_18A628;
// 18A62C: using guessed type int dword_18A62C;
// 18A660: using guessed type int dword_18A660;
// 18A664: using guessed type int dword_18A664;
// 18A668: using guessed type int dword_18A668;
// 18A66C: using guessed type int dword_18A66C;
// 18A670: using guessed type int dword_18A670;
// 18A674: using guessed type int dword_18A674;
// 18A678: using guessed type int dword_18A678;
// 18A684: using guessed type int dword_18A684;
// 18A688: using guessed type int dword_18A688;
// 18A69C: using guessed type int (__fastcall *dword_18A69C)(_DWORD);
// 18A6A0: using guessed type int dword_18A6A0;
// 18A6A4: using guessed type int dword_18A6A4;
// 18A6AC: using guessed type int dword_18A6AC;
// 18A6C0: using guessed type char byte_18A6C0;
// 18A6D0: using guessed type int dword_18A6D0;
// 18A7F0: using guessed type int dword_18A7F0;
// 18A7F4: using guessed type int dword_18A7F4;
// 18A7F8: using guessed type int dword_18A7F8;
// 18A800: using guessed type int (*funcs_164C45[256])();


//----- (00165760) --------------------------------------------------------
int16_t __fastcall sub_165760(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (0016576C) --------------------------------------------------------
int __fastcall sub_16576C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165778) --------------------------------------------------------
int __fastcall sub_165778(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00165784) --------------------------------------------------------
char __fastcall sub_165784(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return (uint16_t)__ROR4__(v2, 16) >> 8;
}


//----- (00165790) --------------------------------------------------------
int __fastcall sub_165790(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (001657A0) --------------------------------------------------------
int __fastcall sub_1657A0(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (001657B0) --------------------------------------------------------
int16_t __fastcall sub_1657B0(int a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  v3 = v2;
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = __ROR4__(v3, 24);
  return result;
}


//----- (001657C0) --------------------------------------------------------
int16_t __fastcall sub_1657C0(int a1, int a2)
{
  int v2; // ebx
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(a2, 8);
  HIBYTE(result) = (uint16_t)__ROR4__(v2, 16) >> 8;
  return result;
}


//----- (001657D0) --------------------------------------------------------
int16_t __fastcall sub_1657D0(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (001657DC) --------------------------------------------------------
char __fastcall sub_1657DC(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return (uint16_t)__ROR4__(v2, 16) >> 8;
}


//----- (001657E8) --------------------------------------------------------
int __fastcall sub_1657E8(int a1, int a2)
{
  return a2;
}


//----- (001657F4) --------------------------------------------------------
char __usercall sub_1657F4( int a1)
{
  return a1;
}


//----- (00165800) --------------------------------------------------------
int __fastcall sub_165800(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(v2) = __ROR4__(v2, 24);
  return __ROR4__(v2, 8);
}


//----- (00165810) --------------------------------------------------------
int __fastcall sub_165810(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00165820) --------------------------------------------------------
int __fastcall sub_165820(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00165830) --------------------------------------------------------
int16_t __fastcall sub_165830(int a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  int16_t result; // ax

  v2 = a2;
  v3 = a2;
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v3) = a2;
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = (uint16_t)__ROR4__(v3, 16) >> 8;
  return result;
}


//----- (00165840) --------------------------------------------------------
char __fastcall sub_165840(int a1, int a2)
{
  return a2;
}


//----- (0016584C) --------------------------------------------------------
int __fastcall sub_16584C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165858) --------------------------------------------------------
int __fastcall sub_165858(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00165868) --------------------------------------------------------
int16_t __fastcall sub_165868(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 24);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165874) --------------------------------------------------------
int __fastcall sub_165874(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00165884) --------------------------------------------------------
int __fastcall sub_165884(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (00165894) --------------------------------------------------------
int16_t __fastcall sub_165894(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (001658A4) --------------------------------------------------------
int __fastcall sub_1658A4(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 24);
}


//----- (001658B4) --------------------------------------------------------
int16_t __fastcall sub_1658B4(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (001658C0) --------------------------------------------------------
char __usercall sub_1658C0( int a1)
{
  return a1;
}


//----- (001658CC) --------------------------------------------------------
int __fastcall sub_1658CC(int a1, int a2)
{
  return a2;
}


//----- (001658D8) --------------------------------------------------------
char __usercall sub_1658D8( int a1)
{
  return a1;
}


//----- (001658E4) --------------------------------------------------------
int __fastcall sub_1658E4(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (001658F4) --------------------------------------------------------
int __fastcall sub_1658F4(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00165904) --------------------------------------------------------
int __fastcall sub_165904(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00165914) --------------------------------------------------------
int16_t __fastcall sub_165914(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165924) --------------------------------------------------------
int16_t __fastcall sub_165924(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (00165930) --------------------------------------------------------
int __fastcall sub_165930(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165940) --------------------------------------------------------
int __fastcall sub_165940(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (0016594C) --------------------------------------------------------
char __usercall sub_16594C( int a1)
{
  return a1;
}


//----- (00165958) --------------------------------------------------------
int __fastcall sub_165958(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00165968) --------------------------------------------------------
int __fastcall sub_165968(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (00165978) --------------------------------------------------------
int16_t __fastcall sub_165978(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165988) --------------------------------------------------------
int __fastcall sub_165988(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 24);
}


//----- (00165998) --------------------------------------------------------
int16_t __fastcall sub_165998(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (001659A4) --------------------------------------------------------
char __usercall sub_1659A4( int a1)
{
  return a1;
}


//----- (001659B0) --------------------------------------------------------
int __fastcall sub_1659B0(int a1, int a2)
{
  return a2;
}


//----- (001659BC) --------------------------------------------------------
char __usercall sub_1659BC( int a1)
{
  return a1;
}


//----- (001659C8) --------------------------------------------------------
int __fastcall sub_1659C8(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (001659D8) --------------------------------------------------------
int __fastcall sub_1659D8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (001659E8) --------------------------------------------------------
int __fastcall sub_1659E8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (001659F8) --------------------------------------------------------
int16_t __fastcall sub_1659F8(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165A08) --------------------------------------------------------
int16_t __fastcall sub_165A08(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = result;
  return result;
}


//----- (00165A14) --------------------------------------------------------
int __fastcall sub_165A14(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165A20) --------------------------------------------------------
int __fastcall sub_165A20(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00165A2C) --------------------------------------------------------
int __fastcall sub_165A2C(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165A38) --------------------------------------------------------
char __fastcall sub_165A38(int a1, int a2)
{
  return a2;
}


//----- (00165A48) --------------------------------------------------------
int __fastcall sub_165A48(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (00165A58) --------------------------------------------------------
int16_t __fastcall sub_165A58(int a1, int a2)
{
  return a2;
}


//----- (00165A68) --------------------------------------------------------
int16_t __fastcall sub_165A68(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = __ROR4__(a2, 24);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165A78) --------------------------------------------------------
int16_t __fastcall sub_165A78(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (00165A84) --------------------------------------------------------
char __usercall sub_165A84( int a1)
{
  return a1;
}


//----- (00165A90) --------------------------------------------------------
int __fastcall sub_165A90(int a1, int a2)
{
  return a2;
}


//----- (00165A9C) --------------------------------------------------------
char __usercall sub_165A9C( int a1)
{
  return a1;
}


//----- (00165AA8) --------------------------------------------------------
int __fastcall sub_165AA8(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(__ROR4__(v2, 24), 16);
}


//----- (00165AB8) --------------------------------------------------------
int __fastcall sub_165AB8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00165AC8) --------------------------------------------------------
int __fastcall sub_165AC8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00165AD8) --------------------------------------------------------
int16_t __usercall sub_165AD8( int a1)
{
  int16_t result; // ax

  HIBYTE(result) = a1;
  LOBYTE(result) = a1;
  return result;
}


//----- (00165AE8) --------------------------------------------------------
int16_t __fastcall sub_165AE8(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (00165AF8) --------------------------------------------------------
int __fastcall sub_165AF8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165B08) --------------------------------------------------------
int __fastcall sub_165B08(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00165B18) --------------------------------------------------------
char __usercall sub_165B18( int a1)
{
  return a1;
}


//----- (00165B28) --------------------------------------------------------
int __fastcall sub_165B28(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00165B34) --------------------------------------------------------
int __fastcall sub_165B34(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (00165B40) --------------------------------------------------------
int16_t __fastcall sub_165B40(int a1, int a2)
{
  return a2;
}


//----- (00165B50) --------------------------------------------------------
int16_t __fastcall sub_165B50(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = __ROR4__(a2, 8);
  HIBYTE(result) = result;
  return result;
}


//----- (00165B5C) --------------------------------------------------------
int16_t __fastcall sub_165B5C(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (00165B68) --------------------------------------------------------
char __fastcall sub_165B68(int a1, int a2)
{
  return __ROR4__(a2, 24);
}


//----- (00165B74) --------------------------------------------------------
int __fastcall sub_165B74(int a1, int a2)
{
  return a2;
}


//----- (00165B80) --------------------------------------------------------
char __fastcall sub_165B80(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (00165B8C) --------------------------------------------------------
int __fastcall sub_165B8C(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00165B9C) --------------------------------------------------------
int __fastcall sub_165B9C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00165BAC) --------------------------------------------------------
int __fastcall sub_165BAC(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00165BBC) --------------------------------------------------------
int16_t __fastcall sub_165BBC(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = __ROR4__(a2, 8);
  return result;
}


//----- (00165BCC) --------------------------------------------------------
int16_t __fastcall sub_165BCC(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (00165BDC) --------------------------------------------------------
int __fastcall sub_165BDC(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165BEC) --------------------------------------------------------
int __fastcall sub_165BEC(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00165BFC) --------------------------------------------------------
int __fastcall sub_165BFC(int a1, int a2)
{
  int v2; // eax

  v2 = __ROR4__(a2, 8);
  LOWORD(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00165C0C) --------------------------------------------------------
char __fastcall sub_165C0C(int a1, int a2)
{
  return a2;
}


//----- (00165C18) --------------------------------------------------------
int __fastcall sub_165C18(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (00165C20) --------------------------------------------------------
int16_t __fastcall sub_165C20(int a1, int a2)
{
  return a2;
}


//----- (00165C2C) --------------------------------------------------------
int16_t __fastcall sub_165C2C(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = __ROR4__(a2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165C38) --------------------------------------------------------
int16_t __fastcall sub_165C38(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (00165C44) --------------------------------------------------------
int16_t __fastcall sub_165C44(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = HIBYTE(a2);
  HIBYTE(result) = a2;
  return result;
}


//----- (00165C50) --------------------------------------------------------
int __fastcall sub_165C50(int a1, int a2)
{
  return a2;
}


//----- (00165C58) --------------------------------------------------------
char __usercall sub_165C58( int a1)
{
  return a1;
}


//----- (00165C64) --------------------------------------------------------
int __fastcall sub_165C64(int a1, int a2)
{
  int v2; // eax

  v2 = __ROR4__(a2, 8);
  LOWORD(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165C74) --------------------------------------------------------
int __fastcall sub_165C74(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00165C84) --------------------------------------------------------
int __fastcall sub_165C84(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00165C94) --------------------------------------------------------
int16_t __fastcall sub_165C94(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165CA4) --------------------------------------------------------
int16_t __fastcall sub_165CA4(int a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  v3 = v2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = (uint16_t)__ROR4__(v3, 8) >> 8;
  return result;
}


//----- (00165CB4) --------------------------------------------------------
int __fastcall sub_165CB4(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165CC4) --------------------------------------------------------
int __fastcall sub_165CC4(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00165CD4) --------------------------------------------------------
int __fastcall sub_165CD4(int a1, int a2)
{
  int v2; // eax

  v2 = __ROR4__(a2, 8);
  LOWORD(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00165CE4) --------------------------------------------------------
char __fastcall sub_165CE4(int a1, int a2)
{
  return a2;
}


//----- (00165CF4) --------------------------------------------------------
int __fastcall sub_165CF4(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (00165D00) --------------------------------------------------------
int16_t __fastcall sub_165D00(int a1, int a2)
{
  return a2;
}


//----- (00165D0C) --------------------------------------------------------
int16_t __fastcall sub_165D0C(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = __ROR4__(a2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165D1C) --------------------------------------------------------
int16_t __fastcall sub_165D1C(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (00165D2C) --------------------------------------------------------
int16_t __fastcall sub_165D2C(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (00165D38) --------------------------------------------------------
int __fastcall sub_165D38(int a1, int a2)
{
  return a2;
}


//----- (00165D44) --------------------------------------------------------
char __usercall sub_165D44( int a1)
{
  return a1;
}


//----- (00165D54) --------------------------------------------------------
int __fastcall sub_165D54(int a1, int a2)
{
  int v2; // eax

  v2 = __ROR4__(a2, 24);
  LOWORD(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165D64) --------------------------------------------------------
int __fastcall sub_165D64(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00165D74) --------------------------------------------------------
int __fastcall sub_165D74(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00165D84) --------------------------------------------------------
int16_t __fastcall sub_165D84(int a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  v3 = v2;
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = __ROR4__(v3, 24);
  return result;
}


//----- (00165D94) --------------------------------------------------------
int16_t __fastcall sub_165D94(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = (uint16_t)__ROR4__(a2, 8) >> 8;
  return result;
}


//----- (00165DA4) --------------------------------------------------------
int __fastcall sub_165DA4(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165DB4) --------------------------------------------------------
int __fastcall sub_165DB4(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00165DC4) --------------------------------------------------------
int __fastcall sub_165DC4(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165DD4) --------------------------------------------------------
char __fastcall sub_165DD4(int a1, int a2)
{
  return (uint16_t)__ROR4__(a2, 8) >> 8;
}


//----- (00165DE0) --------------------------------------------------------
int __fastcall sub_165DE0(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (00165DEC) --------------------------------------------------------
int16_t __fastcall sub_165DEC(int a1, int a2)
{
  return a2;
}


//----- (00165DFC) --------------------------------------------------------
int __fastcall sub_165DFC(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 24);
}


//----- (00165E08) --------------------------------------------------------
int16_t __fastcall sub_165E08(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = (uint16_t)__ROR4__(a2, 8) >> 8;
  return result;
}


//----- (00165E14) --------------------------------------------------------
int16_t __fastcall sub_165E14(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = BYTE1(a2);
  HIBYTE(result) = (uint16_t)__ROR4__(a2, 24) >> 8;
  return result;
}


//----- (00165E20) --------------------------------------------------------
int __fastcall sub_165E20(int a1, int a2)
{
  return a2;
}


//----- (00165E2C) --------------------------------------------------------
char __usercall sub_165E2C( int a1)
{
  return a1;
}


//----- (00165E38) --------------------------------------------------------
char __fastcall sub_165E38(int a1, int a2)
{
  return a2;
}


//----- (00165E48) --------------------------------------------------------
int __fastcall sub_165E48(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00165E58) --------------------------------------------------------
int __fastcall sub_165E58(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00165E68) --------------------------------------------------------
int16_t __fastcall sub_165E68(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165E78) --------------------------------------------------------
int16_t __fastcall sub_165E78(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (00165E84) --------------------------------------------------------
int __fastcall sub_165E84(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165E90) --------------------------------------------------------
int __fastcall sub_165E90(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00165E9C) --------------------------------------------------------
char __usercall sub_165E9C( int a1)
{
  return a1;
}


//----- (00165EA8) --------------------------------------------------------
int __fastcall sub_165EA8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00165EB4) --------------------------------------------------------
int __fastcall sub_165EB4(int a1, int a2)
{
  return __ROR4__(a2, 24);
}


//----- (00165EC0) --------------------------------------------------------
int16_t __fastcall sub_165EC0(int a1, int a2)
{
  return a2;
}


//----- (00165ED0) --------------------------------------------------------
int16_t __fastcall sub_165ED0(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = __ROR4__(a2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165EDC) --------------------------------------------------------
int16_t __fastcall sub_165EDC(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (00165EE4) --------------------------------------------------------
int16_t __fastcall sub_165EE4(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = HIBYTE(a2);
  HIBYTE(result) = a2;
  return result;
}


//----- (00165EF0) --------------------------------------------------------
int __fastcall sub_165EF0(int a1, int a2)
{
  return a2;
}


//----- (00165EF8) --------------------------------------------------------
char __usercall sub_165EF8( int a1)
{
  return a1;
}


//----- (00165F00) --------------------------------------------------------
int __fastcall sub_165F00(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00165F0C) --------------------------------------------------------
int __fastcall sub_165F0C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00165F18) --------------------------------------------------------
int __fastcall sub_165F18(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00165F24) --------------------------------------------------------
int16_t __fastcall sub_165F24(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165F30) --------------------------------------------------------
int16_t __fastcall sub_165F30(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (00165F3C) --------------------------------------------------------
int __fastcall sub_165F3C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165F4C) --------------------------------------------------------
int __fastcall sub_165F4C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00165F58) --------------------------------------------------------
int __fastcall sub_165F58(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00165F64) --------------------------------------------------------
char __fastcall sub_165F64(int a1, int a2)
{
  return a2;
}


//----- (00165F74) --------------------------------------------------------
int __fastcall sub_165F74(int a1, int a2)
{
  return __ROR4__(a2, 24);
}


//----- (00165F80) --------------------------------------------------------
int16_t __fastcall sub_165F80(int a1, int a2)
{
  return a2;
}


//----- (00165F8C) --------------------------------------------------------
int16_t __fastcall sub_165F8C(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = __ROR4__(a2, 24);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00165F9C) --------------------------------------------------------
int16_t __fastcall sub_165F9C(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (00165FA8) --------------------------------------------------------
char __usercall sub_165FA8( int a1)
{
  return a1;
}


//----- (00165FB4) --------------------------------------------------------
int __fastcall sub_165FB4(int a1, int a2)
{
  return a2;
}


//----- (00165FC0) --------------------------------------------------------
char __usercall sub_165FC0( int a1)
{
  return a1;
}


//----- (00165FCC) --------------------------------------------------------
int __fastcall sub_165FCC(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00165FD8) --------------------------------------------------------
int __fastcall sub_165FD8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00165FE8) --------------------------------------------------------
int __fastcall sub_165FE8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00165FF4) --------------------------------------------------------
int16_t __fastcall sub_165FF4(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00166000) --------------------------------------------------------
char __fastcall sub_166000(int a1, int a2)
{
  return a2;
}


//----- (0016600C) --------------------------------------------------------
int __fastcall sub_16600C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00166018) --------------------------------------------------------
int __fastcall sub_166018(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00166024) --------------------------------------------------------
char __usercall sub_166024( int a1)
{
  return a1;
}


//----- (00166030) --------------------------------------------------------
char __fastcall sub_166030(int a1, int a2)
{
  return a2;
}


//----- (0016603C) --------------------------------------------------------
int __fastcall sub_16603C(int a1, int a2)
{
  return __ROR4__(a2, 24);
}


//----- (00166044) --------------------------------------------------------
int16_t __fastcall sub_166044(int a1, int a2)
{
  return a2;
}


//----- (00166050) --------------------------------------------------------
int16_t __fastcall sub_166050(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = __ROR4__(a2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (0016605C) --------------------------------------------------------
int16_t __fastcall sub_16605C(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (00166064) --------------------------------------------------------
char __usercall sub_166064( int a1)
{
  return a1;
}


//----- (00166070) --------------------------------------------------------
int __fastcall sub_166070(int a1, int a2)
{
  return a2;
}


//----- (00166078) --------------------------------------------------------
char __usercall sub_166078( int a1)
{
  return a1;
}


//----- (00166080) --------------------------------------------------------
int16_t __fastcall sub_166080(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (0016608C) --------------------------------------------------------
int __fastcall sub_16608C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00166098) --------------------------------------------------------
int __fastcall sub_166098(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (001660A4) --------------------------------------------------------
int16_t __fastcall sub_1660A4(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (001660B0) --------------------------------------------------------
int16_t __fastcall sub_1660B0(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (001660BC) --------------------------------------------------------
int __fastcall sub_1660BC(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (001660C8) --------------------------------------------------------
int __fastcall sub_1660C8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (001660D4) --------------------------------------------------------
int __fastcall sub_1660D4(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (001660E0) --------------------------------------------------------
char __fastcall sub_1660E0(int a1, int a2)
{
  return a2;
}


//----- (001660EC) --------------------------------------------------------
int __fastcall sub_1660EC(int a1, int a2)
{
  return __ROR4__(a2, 24);
}


//----- (001660F8) --------------------------------------------------------
int16_t __fastcall sub_1660F8(int a1, int a2)
{
  return a2;
}


//----- (00166108) --------------------------------------------------------
int __fastcall sub_166108(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 24);
}


//----- (00166114) --------------------------------------------------------
int16_t __fastcall sub_166114(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (0016611C) --------------------------------------------------------
char __usercall sub_16611C( int a1)
{
  return a1;
}


//----- (00166128) --------------------------------------------------------
int __fastcall sub_166128(int a1, int a2)
{
  return a2;
}


//----- (00166130) --------------------------------------------------------
char __usercall sub_166130( int a1)
{
  return a1;
}


//----- (00166138) --------------------------------------------------------
char __fastcall sub_166138(int a1, int a2)
{
  return a2;
}


//----- (00166144) --------------------------------------------------------
int __fastcall sub_166144(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00166150) --------------------------------------------------------
int __fastcall sub_166150(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


