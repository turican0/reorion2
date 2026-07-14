#include "orion_common.h"

/* Adresni rozsah: 0x16615C - 0x1694D9  (98 funkci) */

//----- (0016615C) --------------------------------------------------------
int16_t __fastcall sub_16615C(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00166168) --------------------------------------------------------
int16_t __fastcall sub_166168(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (00166178) --------------------------------------------------------
int __fastcall sub_166178(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00166188) --------------------------------------------------------
int __fastcall sub_166188(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00166198) --------------------------------------------------------
int __fastcall sub_166198(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(__ROR4__(v2, 8), 16);
}


//----- (001661A8) --------------------------------------------------------
char __fastcall sub_1661A8(int a1, int a2)
{
  return a2;
}


//----- (001661B8) --------------------------------------------------------
int __fastcall sub_1661B8(int a1, int a2)
{
  return __ROR4__(a2, 24);
}


//----- (001661C8) --------------------------------------------------------
int16_t __fastcall sub_1661C8(int a1, int a2)
{
  return a2;
}


//----- (001661D8) --------------------------------------------------------
int16_t __fastcall sub_1661D8(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = __ROR4__(a2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (001661E8) --------------------------------------------------------
int16_t __fastcall sub_1661E8(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (001661F4) --------------------------------------------------------
int16_t __fastcall sub_1661F4(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = HIBYTE(a2);
  HIBYTE(result) = a2;
  return result;
}


//----- (00166200) --------------------------------------------------------
int __fastcall sub_166200(int a1, int a2)
{
  return a2;
}


//----- (0016620C) --------------------------------------------------------
char __usercall sub_16620C( int a1)
{
  return a1;
}


//----- (00166218) --------------------------------------------------------
int __fastcall sub_166218(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00166224) --------------------------------------------------------
int __fastcall sub_166224(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00166230) --------------------------------------------------------
int __fastcall sub_166230(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (0016623C) --------------------------------------------------------
int16_t __fastcall sub_16623C(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = result;
  return result;
}


//----- (00166248) --------------------------------------------------------
int16_t __fastcall sub_166248(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (00166258) --------------------------------------------------------
int __fastcall sub_166258(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00166268) --------------------------------------------------------
int __fastcall sub_166268(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00166278) --------------------------------------------------------
int __fastcall sub_166278(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00166288) --------------------------------------------------------
int __fastcall sub_166288(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00166298) --------------------------------------------------------
int __fastcall sub_166298(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (001662A8) --------------------------------------------------------
char __fastcall sub_1662A8(int a1, int a2)
{
  return a2;
}


//----- (001662B8) --------------------------------------------------------
int __fastcall sub_1662B8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 24);
}


//----- (001662C8) --------------------------------------------------------
int16_t __fastcall sub_1662C8(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (001662D4) --------------------------------------------------------
int16_t __fastcall sub_1662D4(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = HIBYTE(a2);
  HIBYTE(result) = a2;
  return result;
}


//----- (001662E0) --------------------------------------------------------
int __fastcall sub_1662E0(int a1, int a2)
{
  return a2;
}


//----- (001662EC) --------------------------------------------------------
char __usercall sub_1662EC( int a1)
{
  return a1;
}


//----- (001662F8) --------------------------------------------------------
char __fastcall sub_1662F8(int a1, int a2)
{
  return a2;
}


//----- (00166304) --------------------------------------------------------
int __fastcall sub_166304(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00166310) --------------------------------------------------------
int __fastcall sub_166310(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00166320) --------------------------------------------------------
int16_t __fastcall sub_166320(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (0016632C) --------------------------------------------------------
int16_t __fastcall sub_16632C(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (0016633C) --------------------------------------------------------
int __fastcall sub_16633C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (0016634C) --------------------------------------------------------
int __fastcall sub_16634C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (0016635C) --------------------------------------------------------
int __fastcall sub_16635C(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (0016636C) --------------------------------------------------------
int __fastcall sub_16636C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (0016637C) --------------------------------------------------------
int __fastcall sub_16637C(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (0016638C) --------------------------------------------------------
char __fastcall sub_16638C(int a1, int a2)
{
  return a2;
}


//----- (0016639C) --------------------------------------------------------
int __fastcall sub_16639C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 24);
}


//----- (001663AC) --------------------------------------------------------
int16_t __fastcall sub_1663AC(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (001663B8) --------------------------------------------------------
int16_t __fastcall sub_1663B8(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = HIBYTE(a2);
  HIBYTE(result) = a2;
  return result;
}


//----- (001663C4) --------------------------------------------------------
int __fastcall sub_1663C4(int a1, int a2)
{
  return a2;
}


//----- (001663D0) --------------------------------------------------------
char __usercall sub_1663D0( int a1)
{
  return a1;
}


//----- (001663DC) --------------------------------------------------------
int16_t __fastcall sub_1663DC(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (001663E8) --------------------------------------------------------
int __fastcall sub_1663E8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (001663F8) --------------------------------------------------------
int __fastcall sub_1663F8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00166404) --------------------------------------------------------
char __usercall sub_166404( int a1)
{
  return a1;
}


//----- (00166410) --------------------------------------------------------
int16_t __fastcall sub_166410(int a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  int16_t result; // ax

  v2 = a2;
  v3 = a2;
  LOBYTE(v3) = BYTE1(a2);
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = (uint16_t)__ROR4__(v3, 8) >> 8;
  return result;
}


//----- (00166420) --------------------------------------------------------
int __fastcall sub_166420(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00166430) --------------------------------------------------------
int __fastcall sub_166430(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00166440) --------------------------------------------------------
int __fastcall sub_166440(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = (uint16_t)__ROR4__(v2, 8) >> 8;
  return __ROR4__(v2, 24);
}


//----- (00166450) --------------------------------------------------------
char __fastcall sub_166450(int a1, int a2)
{
  int v2; // ebx

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return (uint16_t)__ROR4__(v2, 8) >> 8;
}


//----- (00166460) --------------------------------------------------------
int __fastcall sub_166460(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (00166470) --------------------------------------------------------
char __fastcall sub_166470(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return (uint16_t)__ROR4__(v2, 8) >> 8;
}


//----- (00166480) --------------------------------------------------------
int __fastcall sub_166480(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 24);
}


//----- (00166490) --------------------------------------------------------
int16_t __fastcall sub_166490(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (0016649C) --------------------------------------------------------
int16_t __fastcall sub_16649C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = (uint16_t)__ROR4__(v2, 8) >> 8;
  return v2;
}


//----- (001664A8) --------------------------------------------------------
int __fastcall sub_1664A8(int a1, int a2)
{
  return a2;
}


//----- (001664B4) --------------------------------------------------------
char __usercall sub_1664B4( int a1)
{
  return a1;
}


//----- (001664C0) --------------------------------------------------------
char __fastcall sub_1664C0(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return (uint16_t)__ROR4__(v2, 8) >> 8;
}


//----- (001664CC) --------------------------------------------------------
int __fastcall sub_1664CC(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (001664D8) --------------------------------------------------------
int __fastcall sub_1664D8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (001664E4) --------------------------------------------------------
int16_t __fastcall sub_1664E4(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (001664F0) --------------------------------------------------------
int __usercall sub_1664F0(int a1, unsigned int a2, _DWORD *a3, unsigned int *a4)
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
  int **v40; // edi
  _DWORD *v41; // edi
  _DWORD *v42; // eax
  int **v43; // edi
  int v44; // edi
  uint16_t *v46; // edi

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
      v40 = (int **)((char *)a3 + dword_18A660);
      *v40 = v22;
      v41 = (int **)((char *)v40 + dword_18A660);
      LOWORD(v42) = ((int16_t (__fastcall *)(int, int))funcs_164C45[v38])(v38, v37);
      *v41 = v42;
      v43 = (int **)((char *)v41 + dword_18A660);
      *v43 = v22;
      a3 = (int **)((char *)v43 - dword_18A66C);
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
    v44 = dword_18A6A0;
    LOWORD(v42) = *(_WORD *)dword_18A6A0;
    if ( *(_WORD *)dword_18A6A0 < 0xFFFDu )
    {
      dword_18A69C(v42);
LABEL_42:
      v46 = (uint16_t *)(v44 + 2);
      dword_18A660 = *v46;
      dword_18A674 = v46[1];
      dword_18A668 = dword_18A674;
      dword_18A66C = v46[2];
      dword_18A684 = v46[3];
      dword_18A688 = v46[4];
      v46 += 5;
      dword_18A670 = v46[2];
      v42 = *(_DWORD **)v46;
      dword_18A6A0 = (int)(v46 + 3);
      a3 = v42;
      if ( dword_18A670 )
        goto LABEL_34;
      continue;
    }
    break;
  }
  if ( (_WORD)v42 == 0xFFFE )
    goto LABEL_42;
  if ( (_WORD)v42 == 0xFFFF )
LABEL_45:
    JUMPOUT(0x1676C0);
  return sub_164920(dword_18A6A0);
}
// 16673E: control flows out of bounds to 1675C0
// 16678A: control flows out of bounds to 1676C0
// 1666FC: variable 'v39' is possibly undefined
// 16671A: variable 'v42' is possibly undefined
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


//----- (00167320) --------------------------------------------------------
_BYTE *__cdecl sub_167320(unsigned int *a1, int a2, int a3)
{
  _DWORD *v3; // esi
  _DWORD *v4; // edi
  int v5; // ecx
  int v6; // eax
  _DWORD **v7; // esi
  _DWORD *v8; // edi
  int v9; // edx
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  unsigned int v13; // ebp
  unsigned int *v14; // esi
  int v15; // eax
  int v16; // edi
  _BYTE *result; // eax
  uint16_t *v18; // edi
  int v19; // eax
  unsigned int v20; // edx
  unsigned int v21; // ebp
  unsigned int v22; // ecx
  unsigned int v23; // ebp
  char v24; // al
  unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // edx
  char v30; // cf
  int v31; // edx
  int v32; // edx
  int *v33; // ebx
  int *v34; // ecx
  int v35; // edx
  int v36; // [esp-18h] [ebp-18h]

  dword_18A6A4 = a2;
  v3 = (_DWORD *)(a2 + 29716);
  LOWORD(dword_18A6D0) = *(_DWORD *)(a2 + 29712);
  v4 = &unk_18A610;
  v5 = 4;
  do
  {
    v6 = *v3;
    v7 = (_DWORD **)(v3 + 1);
    *v4 = v6;
    v8 = v4 + 1;
    v9 = v6;
    v10 = *v7++;
    *v8++ = v10;
    *v10 = v9;
    v11 = *v7++;
    *v8++ = v11;
    *v11 = v9;
    v12 = *v7;
    v3 = v7 + 1;
    *v8 = v12;
    v4 = v8 + 1;
    *v12 = v9;
    --v5;
  }
  while ( v5 );
  dword_18A600 = a2 + 16;
  dword_18A604 = a2 + 8208;
  dword_18A608 = a2 + 12304;
  dword_18A60C = a2 + 28688;
  v13 = *a1;
  v14 = a1 + 1;
  byte_18A6C0 = 33;
  dword_18A6AC = !(*(_BYTE *)a3 & 1);
  if ( (*(_BYTE *)(a3 + 1) & 1) != 0 )
  {
    if ( (dword_18A6AC & 1) != 0 )
    {
      dword_18A650 = (int)&loc_164A90;
      dword_18A654 = (int)&loc_164DF0;
      dword_18A658 = (int)&loc_167084;
      dword_18A65C = (int)&loc_165600;
    }
    else
    {
      dword_18A650 = (int)sub_164A40;
      dword_18A654 = (int)sub_164DA0;
      dword_18A658 = (int)sub_167040;
      dword_18A65C = (int)sub_1655B0;
    }
    dword_18A6A8 = 1;
  }
  else
  {
    if ( (dword_18A6AC & 1) != 0 )
    {
      dword_18A650 = (int)&loc_166540;
      dword_18A654 = (int)&loc_166880;
      dword_18A658 = (int)&loc_167084;
      dword_18A65C = (int)&loc_1671E0;
    }
    else
    {
      dword_18A650 = (int)sub_1664F0;
      dword_18A654 = (int)sub_166830;
      dword_18A658 = (int)sub_167040;
      dword_18A65C = (int)sub_167190;
    }
    dword_18A6A8 = 0;
  }
  if ( (dword_18A6AC & 1) == 0 )
  {
    dword_18A674 = *(_DWORD *)(a3 + 8);
    dword_18A668 = dword_18A674;
    dword_18A670 = *(_DWORD *)(a3 + 12);
    dword_18A66C = *(_DWORD *)(a3 + 16);
    dword_18A684 = *(_DWORD *)(a3 + 20);
    dword_18A660 = *(_DWORD *)(a3 + 24);
    dword_18A688 = *(_DWORD *)(a3 + 28);
    v19 = *(_DWORD *)(a3 + 4);
    *(_DWORD *)(a3 + 32) = 0;
    *(_DWORD *)(a3 + 44) = 0;
    *(_DWORD *)(a3 + 48) = 0;
    dword_18A7F8 = a3 + 56;
    dword_18A7F4 = 0;
    dword_18A7F0 = 0;
LABEL_22:
    if ( (uint8_t)byte_18A6C0 > 8u )
    {
      v27 = *(_DWORD *)(dword_18A60C + 4 * (uint8_t)v13);
      v23 = v13 >> v27;
      v24 = byte_18A6C0 - v27;
      v25 = (unsigned int *)(dword_18A6A4 + (v27 >> 8));
      v26 = *v25;
      if ( (_WORD)dword_18A6D0 != (uint16_t)*v25 )
        goto LABEL_31;
    }
    else
    {
      v20 = *v14;
      v14 = (unsigned int *)((char *)a1 + 6);
      v21 = v13 | (v20 << (byte_18A6C0 - 1));
      v22 = *(_DWORD *)(dword_18A60C + 4 * (uint8_t)v21);
      v23 = v21 >> v22;
      v24 = byte_18A6C0 + 16 - v22;
      v25 = (unsigned int *)(dword_18A6A4 + (v22 >> 8));
      v26 = *v25;
      if ( (_WORD)dword_18A6D0 != (uint16_t)*v25 )
        goto LABEL_31;
    }
    do
    {
      v28 = v26 >> 13;
      if ( !--v24 )
      {
        v23 = *v14++;
        v24 = 32;
      }
      v29 = (unsigned int)&loc_FFFF8 & v28;
      v30 = v23 & 1;
      v23 >>= 1;
      if ( !v30 )
        v29 = 4;
      v25 = (unsigned int *)((char *)v25 + v29);
      v26 = *v25;
    }
    while ( (_WORD)dword_18A6D0 == (uint16_t)*v25 );
LABEL_31:
    v31 = __ROR4__(v26, 16);
    byte_18A6C0 = v24;
    LOWORD(v19) = v31;
    v32 = __ROR4__(v31, 16);
    if ( *(_DWORD *)dword_18A644 != v32 )
    {
      dword_18A678 = v19;
      v19 = *(_DWORD *)dword_18A644;
      v33 = (int *)dword_18A648;
      *(_DWORD *)dword_18A644 = v32;
      v34 = (int *)dword_18A64C;
      v35 = *v33;
      *v33 = v19;
      LOBYTE(v19) = dword_18A678;
      *v34 = v35;
    }
    dword_18A664 = *(int *)((char *)&dword_18A6E0 + (v19 & 0xFC));
    /* __asm: jmp     dword_18A650[ecx*4] */ DECOMP_TODO("inline asm");
  }
  dword_18A69C = *(int (__fastcall **)(_DWORD))(a3 + 4);
  v15 = *(uint16_t *)(a3 + 8);
  dword_18A680 = v15;
  dword_18A6A0 = a3 + 10;
  v36 = v15;
  while ( 1 )
  {
    v16 = dword_18A6A0;
    LOWORD(v15) = *(_WORD *)dword_18A6A0;
    if ( *(_WORD *)dword_18A6A0 < 0xFFFDu )
    {
      dword_18A69C(v15);
      goto LABEL_19;
    }
    if ( (_WORD)v15 != 0xFFFE )
      break;
LABEL_19:
    v18 = (uint16_t *)(v16 + 2);
    dword_18A660 = *v18;
    dword_18A674 = v18[1];
    dword_18A668 = dword_18A674;
    dword_18A66C = v18[2];
    dword_18A684 = v18[3];
    dword_18A688 = v18[4];
    v18 += 5;
    dword_18A670 = v18[2];
    v15 = *(_DWORD *)v18;
    dword_18A6A0 = (int)(v18 + 3);
    if ( dword_18A670 )
    {
      HIWORD(v19) = HIWORD(v36);
      goto LABEL_22;
    }
  }
  if ( (_WORD)v15 != 0xFFFF )
    return (_BYTE *)sub_164920(dword_18A6A0);
  if ( (dword_18A6AC & 1) != 0 )
    return (_BYTE *)v36;
  result = (_BYTE *)(dword_18A7F8 + ((unsigned int)dword_18A7F0 >> 4));
  *result = 0;
  return result;
}
// 164DA0: using guessed type int sub_164DA0();
// 1655B0: using guessed type int sub_1655B0();
// 166830: using guessed type int sub_166830();
// 167040: using guessed type int sub_167040();
// 167190: using guessed type int sub_167190();
// 18A600: using guessed type int dword_18A600;
// 18A604: using guessed type int dword_18A604;
// 18A608: using guessed type int dword_18A608;
// 18A60C: using guessed type int dword_18A60C;
// 18A644: using guessed type int dword_18A644;
// 18A648: using guessed type int dword_18A648;
// 18A64C: using guessed type int dword_18A64C;
// 18A650: using guessed type int dword_18A650;
// 18A654: using guessed type int dword_18A654;
// 18A658: using guessed type int dword_18A658;
// 18A65C: using guessed type int dword_18A65C;
// 18A660: using guessed type int dword_18A660;
// 18A664: using guessed type int dword_18A664;
// 18A668: using guessed type int dword_18A668;
// 18A66C: using guessed type int dword_18A66C;
// 18A670: using guessed type int dword_18A670;
// 18A674: using guessed type int dword_18A674;
// 18A678: using guessed type int dword_18A678;
// 18A680: using guessed type int dword_18A680;
// 18A684: using guessed type int dword_18A684;
// 18A688: using guessed type int dword_18A688;
// 18A69C: using guessed type int (__fastcall *dword_18A69C)(_DWORD);
// 18A6A0: using guessed type int dword_18A6A0;
// 18A6A4: using guessed type int dword_18A6A4;
// 18A6A8: using guessed type int dword_18A6A8;
// 18A6AC: using guessed type int dword_18A6AC;
// 18A6C0: using guessed type char byte_18A6C0;
// 18A6D0: using guessed type int dword_18A6D0;
// 18A6E0: using guessed type int dword_18A6E0;
// 18A7F0: using guessed type int dword_18A7F0;
// 18A7F4: using guessed type int dword_18A7F4;
// 18A7F8: using guessed type int dword_18A7F8;


//----- (001676F0) --------------------------------------------------------
void __cdecl sub_1676F0(unsigned int *a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v6; // ebp
  unsigned int *v7; // esi
  _BOOL1 v8; // cf
  unsigned int v9; // ebp
  unsigned int v10; // ebp
  unsigned int v11; // ebp
  unsigned int v12; // ebp
  _BYTE *v13; // edi
  int v14; // edx
  char v15; // bl
  unsigned int v16; // ebp
  char v17; // al
  char v18; // cl
  char v19; // al
  unsigned int v20; // ebp
  char i2; // cl
  int *v22; // edx
  int i3; // eax
  unsigned int v24; // ebp
  unsigned int v25; // ebp
  _WORD *v26; // edi
  int v27; // edx
  char v28; // bl
  unsigned int v29; // ebp
  char v30; // al
  char v31; // cl
  char v32; // al
  unsigned int v33; // ebp
  int16_t v34; // ax
  char v35; // bl
  unsigned int v36; // ebp
  char v37; // cl
  char v38; // al
  unsigned int v39; // ebp
  int16_t mm; // cx
  int *v41; // edx
  int nn; // eax
  int *v43; // edx
  int i1; // eax
  unsigned int v45; // ebp
  unsigned int v46; // ebp
  unsigned int v47; // ebp
  _WORD *v48; // edi
  int v49; // edx
  char v50; // bl
  unsigned int v51; // ebp
  char v52; // al
  char v53; // cl
  char v54; // al
  unsigned int v55; // ebp
  int16_t v56; // ax
  char v57; // bl
  unsigned int v58; // ebp
  char v59; // cl
  char v60; // al
  unsigned int v61; // ebp
  int16_t ii; // cx
  int *v63; // edx
  int jj; // eax
  int *v65; // edx
  int kk; // eax
  unsigned int v67; // ebp
  unsigned int v68; // ebp
  unsigned int v69; // ebp
  unsigned int v70; // ebp
  int v71; // eax
  _DWORD *v72; // edi
  int v73; // edx
  char v74; // bl
  unsigned int v75; // ebp
  char v76; // al
  char v77; // cl
  char v78; // al
  unsigned int v79; // ebp
  char v80; // bl
  unsigned int v81; // ebp
  char v82; // cl
  char v83; // al
  unsigned int v84; // ebp
  int v85; // eax
  char v86; // bl
  unsigned int v87; // ebp
  char v88; // al
  char v89; // cl
  char v90; // al
  unsigned int v91; // ebp
  char v92; // bl
  unsigned int v93; // ebp
  char v94; // cl
  char v95; // al
  unsigned int v96; // ebp
  int i; // ecx
  int *v98; // edx
  int j; // eax
  int *v100; // edx
  int k; // eax
  int v102; // ecx
  int *v103; // edx
  int m; // eax
  int *v105; // edx
  int n; // eax

  dword_18AC20 = a2;
  dword_18AC24 = a3;
  dword_18AC28 = a4;
  dword_18AC2C = a5;
  dword_18AC30 = a6;
  byte_18A6C0 = 0;
  v6 = *a1;
  v7 = a1 + 1;
  byte_18A6C0 = 32;
  v8 = v6 & 1;
  v9 = v6 >> 1;
  if ( v8 )
  {
    if ( !--byte_18A6C0 )
    {
      v9 = *v7;
      v7 = a1 + 2;
      byte_18A6C0 = 32;
    }
    v8 = v9 & 1;
    v10 = v9 >> 1;
    if ( v8 )
    {
      if ( !--byte_18A6C0 )
      {
        v10 = *v7++;
        byte_18A6C0 = 32;
      }
      v8 = v10 & 1;
      v45 = v10 >> 1;
      if ( v8 )
      {
        if ( !--byte_18A6C0 )
        {
          v45 = *v7++;
          byte_18A6C0 = 32;
        }
        v67 = v45 >> 1;
        dword_18A68C = dword_18AC24;
        sub_164200(v67, (unsigned int *)dword_18AC24, v7);
        if ( !--byte_18A6C0 )
        {
          v67 = *v7++;
          byte_18A6C0 = 32;
        }
        v68 = v67 >> 1;
        dword_18A690 = dword_18AC24 + 2048;
        sub_164200(v68, (unsigned int *)(dword_18AC24 + 2048), v7);
        if ( !--byte_18A6C0 )
        {
          v68 = *v7++;
          byte_18A6C0 = 32;
        }
        v69 = v68 >> 1;
        dword_18A694 = dword_18AC24 + 4096;
        sub_164200(v69, (unsigned int *)(dword_18AC24 + 4096), v7);
        if ( !--byte_18A6C0 )
        {
          v69 = *v7++;
          byte_18A6C0 = 32;
        }
        v70 = v69 >> 1;
        dword_18A698 = dword_18AC24 + 6144;
        sub_164200(v70, (unsigned int *)(dword_18AC24 + 6144), v7);
        if ( dword_18AC20 )
        {
          v72 = (_DWORD *)dword_18AC30;
          v73 = dword_18AC30 + dword_18AC20;
          if ( dword_18AC2C < (unsigned int)(dword_18AC30 + dword_18AC20) )
            v73 = dword_18AC28 + v73 - dword_18AC2C;
          dword_18A7FC = v73;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v77 = byte_18A6C0;
            byte_18A6C0 += 24;
            v78 = v70;
            --v77;
            v79 = *v7;
            v76 = (*v7++ << v77) | v78;
            v75 = v79 >> ~(v77 - 9);
          }
          else
          {
            v74 = v70;
            byte_18A6C0 -= 8;
            v75 = v70 >> 8;
            v76 = v74;
          }
          BYTE1(v71) = v76;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v82 = byte_18A6C0;
            byte_18A6C0 += 24;
            v83 = v75;
            --v82;
            v84 = *v7;
            LOBYTE(v71) = (*v7++ << v82) | v83;
            v81 = v84 >> ~(v82 - 9);
          }
          else
          {
            v80 = v75;
            byte_18A6C0 -= 8;
            v81 = v75 >> 8;
            LOBYTE(v71) = v80;
          }
          v85 = v71 << 16;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v89 = byte_18A6C0;
            byte_18A6C0 += 24;
            v90 = v81;
            --v89;
            v91 = *v7;
            v88 = (*v7++ << v89) | v90;
            v87 = v91 >> ~(v89 - 9);
          }
          else
          {
            v86 = v81;
            byte_18A6C0 -= 8;
            v87 = v81 >> 8;
            v88 = v86;
          }
          BYTE1(v85) = v88;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v94 = byte_18A6C0;
            byte_18A6C0 += 24;
            v95 = v87;
            --v94;
            v96 = *v7;
            LOBYTE(v85) = (*v7++ << v94) | v95;
            v93 = v96 >> ~(v94 - 9);
          }
          else
          {
            v92 = v87;
            byte_18A6C0 -= 8;
            v93 = v87 >> 8;
            LOBYTE(v85) = v92;
          }
          for ( i = v85; ; i = __ROR4__(v102, 16) )
          {
            *v72++ = i;
            if ( (_DWORD *)dword_18A7FC == v72 )
              break;
            if ( (_DWORD *)dword_18AC2C == v72 )
              v72 = (_DWORD *)dword_18AC28;
            v98 = (int *)dword_18A68C;
            for ( j = *(_DWORD *)dword_18A68C; *v98 >= 0; j = *v98 )
            {
              if ( !--byte_18A6C0 )
              {
                v93 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v93 & 1;
              v93 >>= 1;
              if ( !v8 )
                j = 4;
              v98 = (int *)((char *)v98 + j);
            }
            v8 = __CFADD__((_BYTE)j, (_BYTE)i);
            LOBYTE(i) = j + i;
            BYTE1(i) += v8;
            v100 = (int *)dword_18A690;
            for ( k = *(_DWORD *)dword_18A690; *v100 >= 0; k = *v100 )
            {
              if ( !--byte_18A6C0 )
              {
                v93 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v93 & 1;
              v93 >>= 1;
              if ( !v8 )
                k = 4;
              v100 = (int *)((char *)v100 + k);
            }
            BYTE1(i) += k;
            v102 = __ROR4__(i, 16);
            v103 = (int *)dword_18A694;
            for ( m = *(_DWORD *)dword_18A694; *v103 >= 0; m = *v103 )
            {
              if ( !--byte_18A6C0 )
              {
                v93 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v93 & 1;
              v93 >>= 1;
              if ( !v8 )
                m = 4;
              v103 = (int *)((char *)v103 + m);
            }
            v8 = __CFADD__((_BYTE)m, (_BYTE)v102);
            LOBYTE(v102) = m + v102;
            BYTE1(v102) += v8;
            v105 = (int *)dword_18A698;
            for ( n = *(_DWORD *)dword_18A698; *v105 >= 0; n = *v105 )
            {
              if ( !--byte_18A6C0 )
              {
                v93 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v93 & 1;
              v93 >>= 1;
              if ( !v8 )
                n = 4;
              v105 = (int *)((char *)v105 + n);
            }
            BYTE1(v102) += n;
          }
        }
      }
      else
      {
        if ( !--byte_18A6C0 )
        {
          v45 = *v7++;
          byte_18A6C0 = 32;
        }
        v46 = v45 >> 1;
        dword_18A68C = dword_18AC24;
        sub_164200(v46, (unsigned int *)dword_18AC24, v7);
        if ( !--byte_18A6C0 )
        {
          v46 = *v7++;
          byte_18A6C0 = 32;
        }
        v47 = v46 >> 1;
        dword_18A690 = dword_18AC24 + 2048;
        sub_164200(v47, (unsigned int *)(dword_18AC24 + 2048), v7);
        if ( dword_18AC20 )
        {
          v48 = (_WORD *)dword_18AC30;
          v49 = dword_18AC30 + dword_18AC20;
          if ( dword_18AC2C < (unsigned int)(dword_18AC30 + dword_18AC20) )
            v49 = dword_18AC28 + v49 - dword_18AC2C;
          dword_18A7FC = v49;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v53 = byte_18A6C0;
            byte_18A6C0 += 24;
            v54 = v47;
            --v53;
            v55 = *v7;
            v52 = (*v7++ << v53) | v54;
            v51 = v55 >> ~(v53 - 9);
          }
          else
          {
            v50 = v47;
            byte_18A6C0 -= 8;
            v51 = v47 >> 8;
            v52 = v50;
          }
          HIBYTE(v56) = v52;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v59 = byte_18A6C0;
            byte_18A6C0 += 24;
            v60 = v51;
            --v59;
            v61 = *v7;
            LOBYTE(v56) = (*v7++ << v59) | v60;
            v58 = v61 >> ~(v59 - 9);
          }
          else
          {
            v57 = v51;
            byte_18A6C0 -= 8;
            v58 = v51 >> 8;
            LOBYTE(v56) = v57;
          }
          for ( ii = v56; ; HIBYTE(ii) += kk )
          {
            *v48++ = ii;
            if ( (_WORD *)dword_18A7FC == v48 )
              break;
            if ( (_WORD *)dword_18AC2C == v48 )
              v48 = (_WORD *)dword_18AC28;
            v63 = (int *)dword_18A68C;
            for ( jj = *(_DWORD *)dword_18A68C; *v63 >= 0; jj = *v63 )
            {
              if ( !--byte_18A6C0 )
              {
                v58 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v58 & 1;
              v58 >>= 1;
              if ( !v8 )
                jj = 4;
              v63 = (int *)((char *)v63 + jj);
            }
            LOBYTE(ii) = jj + ii;
            v65 = (int *)dword_18A690;
            for ( kk = *(_DWORD *)dword_18A690; *v65 >= 0; kk = *v65 )
            {
              if ( !--byte_18A6C0 )
              {
                v58 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v58 & 1;
              v58 >>= 1;
              if ( !v8 )
                kk = 4;
              v65 = (int *)((char *)v65 + kk);
            }
          }
        }
      }
    }
    else
    {
      if ( !--byte_18A6C0 )
      {
        v10 = *v7++;
        byte_18A6C0 = 32;
      }
      v8 = v10 & 1;
      v11 = v10 >> 1;
      if ( v8 )
      {
        if ( !--byte_18A6C0 )
        {
          v11 = *v7++;
          byte_18A6C0 = 32;
        }
        v24 = v11 >> 1;
        dword_18A68C = dword_18AC24;
        sub_164200(v24, (unsigned int *)dword_18AC24, v7);
        if ( !--byte_18A6C0 )
        {
          v24 = *v7++;
          byte_18A6C0 = 32;
        }
        v25 = v24 >> 1;
        dword_18A690 = dword_18AC24 + 2048;
        sub_164200(v25, (unsigned int *)(dword_18AC24 + 2048), v7);
        if ( dword_18AC20 )
        {
          v26 = (_WORD *)dword_18AC30;
          v27 = dword_18AC30 + dword_18AC20;
          if ( dword_18AC2C < (unsigned int)(dword_18AC30 + dword_18AC20) )
            v27 = dword_18AC28 + v27 - dword_18AC2C;
          dword_18A7FC = v27;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v31 = byte_18A6C0;
            byte_18A6C0 += 24;
            v32 = v25;
            --v31;
            v33 = *v7;
            v30 = (*v7++ << v31) | v32;
            v29 = v33 >> ~(v31 - 9);
          }
          else
          {
            v28 = v25;
            byte_18A6C0 -= 8;
            v29 = v25 >> 8;
            v30 = v28;
          }
          HIBYTE(v34) = v30;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v37 = byte_18A6C0;
            byte_18A6C0 += 24;
            v38 = v29;
            --v37;
            v39 = *v7;
            LOBYTE(v34) = (*v7++ << v37) | v38;
            v36 = v39 >> ~(v37 - 9);
          }
          else
          {
            v35 = v29;
            byte_18A6C0 -= 8;
            v36 = v29 >> 8;
            LOBYTE(v34) = v35;
          }
          for ( mm = v34; ; HIBYTE(mm) += i1 )
          {
            *v26++ = mm;
            if ( (_WORD *)dword_18A7FC == v26 )
              break;
            if ( (_WORD *)dword_18AC2C == v26 )
              v26 = (_WORD *)dword_18AC28;
            v41 = (int *)dword_18A68C;
            for ( nn = *(_DWORD *)dword_18A68C; *v41 >= 0; nn = *v41 )
            {
              if ( !--byte_18A6C0 )
              {
                v36 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v36 & 1;
              v36 >>= 1;
              if ( !v8 )
                nn = 4;
              v41 = (int *)((char *)v41 + nn);
            }
            v8 = __CFADD__((_BYTE)nn, (_BYTE)mm);
            LOBYTE(mm) = nn + mm;
            HIBYTE(mm) += v8;
            v43 = (int *)dword_18A690;
            for ( i1 = *(_DWORD *)dword_18A690; *v43 >= 0; i1 = *v43 )
            {
              if ( !--byte_18A6C0 )
              {
                v36 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v36 & 1;
              v36 >>= 1;
              if ( !v8 )
                i1 = 4;
              v43 = (int *)((char *)v43 + i1);
            }
          }
        }
      }
      else
      {
        if ( !--byte_18A6C0 )
        {
          v11 = *v7++;
          byte_18A6C0 = 32;
        }
        v12 = v11 >> 1;
        dword_18A68C = dword_18AC24;
        sub_164200(v12, (unsigned int *)dword_18AC24, v7);
        if ( dword_18AC20 )
        {
          v13 = (_BYTE *)dword_18AC30;
          v14 = dword_18AC30 + dword_18AC20;
          if ( dword_18AC2C < (unsigned int)(dword_18AC30 + dword_18AC20) )
            v14 = dword_18AC28 + v14 - dword_18AC2C;
          dword_18A7FC = v14;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v18 = byte_18A6C0;
            byte_18A6C0 += 24;
            v19 = v12;
            --v18;
            v20 = *v7;
            v17 = (*v7++ << v18) | v19;
            v16 = v20 >> ~(v18 - 9);
          }
          else
          {
            v15 = v12;
            byte_18A6C0 -= 8;
            v16 = v12 >> 8;
            v17 = v15;
          }
          for ( i2 = v17; ; i2 += i3 )
          {
            *v13++ = i2;
            if ( (_BYTE *)dword_18A7FC == v13 )
              break;
            if ( (_BYTE *)dword_18AC2C == v13 )
              v13 = (_BYTE *)dword_18AC28;
            v22 = (int *)dword_18A68C;
            for ( i3 = *(_DWORD *)dword_18A68C; *v22 >= 0; i3 = *v22 )
            {
              if ( !--byte_18A6C0 )
              {
                v16 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v16 & 1;
              v16 >>= 1;
              if ( !v8 )
                i3 = 4;
              v22 = (int *)((char *)v22 + i3);
            }
          }
        }
      }
    }
  }
}
// 167D64: variable 'v71' is possibly undefined
// 18A68C: using guessed type int dword_18A68C;
// 18A690: using guessed type int dword_18A690;
// 18A694: using guessed type int dword_18A694;
// 18A698: using guessed type int dword_18A698;
// 18A6C0: using guessed type char byte_18A6C0;
// 18A7FC: using guessed type int dword_18A7FC;
// 18AC20: using guessed type int dword_18AC20;
// 18AC24: using guessed type int dword_18AC24;
// 18AC28: using guessed type int dword_18AC28;
// 18AC2C: using guessed type int dword_18AC2C;
// 18AC30: using guessed type int dword_18AC30;


//----- (00167F20) --------------------------------------------------------
unsigned int __cdecl sub_167F20(int a1, int a2)
{
  return ((unsigned int)(a2 * a1) >> 8) + 32;
}


//----- (00167F40) --------------------------------------------------------
int __cdecl sub_167F40(int a1, unsigned int *a2)
{
  _WORD *v2; // edi
  unsigned int v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // eax
  int result; // eax
  unsigned int v8; // eax
  unsigned int v9; // ecx

  if ( *(_BYTE *)(a1 + 32) )
    return 0;
  v2 = *(_WORD **)(a1 + 52);
  if ( *(_BYTE *)(a1 + 33) )
  {
    v8 = *(_DWORD *)(a1 + 48);
    if ( *(_DWORD *)(a1 + 40) > v8 )
    {
      a2[1] = v8;
      *a2 = 0;
      v3 = *(_DWORD *)(a1 + 44);
      if ( *(_DWORD *)(a1 + 36) <= v3 )
      {
        v9 = *(_DWORD *)(a1 + 36);
        a2[2] = v9;
        *(_DWORD *)(a1 + 44) = v3 - v9;
        *(_DWORD *)(a1 + 48) += 4;
      }
      else
      {
        *(_BYTE *)(a1 + 33) = 0;
        a2[2] = v3;
        if ( *v2 )
          goto LABEL_14;
      }
      a2[3] = 4;
      return 1;
    }
    goto LABEL_27;
  }
  if ( !*(_BYTE *)(a1 + 34) )
  {
    v2 = (_WORD *)(a1 + 56);
    *(_BYTE *)(a1 + 34) = 1;
  }
  v3 = *(_DWORD *)(a1 + 44);
  v4 = *(_DWORD *)(a1 + 48);
  if ( *(_DWORD *)(a1 + 40) <= v4 )
  {
LABEL_27:
    *(_BYTE *)(a1 + 32) = 1;
    return 0;
  }
  if ( !*(_BYTE *)v2 )
  {
    while ( !*(_BYTE *)v2 )
    {
      v2 = (_WORD *)((char *)v2 + 1);
      for ( v3 += 64; *(_DWORD *)(a1 + 36) <= v3; v3 -= *(_DWORD *)(a1 + 36) )
      {
        v4 += 4;
        if ( *(_DWORD *)(a1 + 40) <= v4 )
          goto LABEL_27;
      }
    }
    *(_DWORD *)(a1 + 48) = v4;
  }
  *a2 = v3;
  a2[1] = v4;
  a2[3] = 4;
  a2[2] = 0;
LABEL_14:
  while ( 1 )
  {
    v5 = v3 + 64;
    if ( *(_DWORD *)(a1 + 36) <= v3 + 64 )
      break;
    v2 = (_WORD *)((char *)v2 + 1);
    v3 += 64;
    a2[2] += 64;
    if ( !*(_BYTE *)v2 )
    {
      *(_DWORD *)(a1 + 44) = v5;
      goto LABEL_20;
    }
  }
  v6 = v5 - *(_DWORD *)(a1 + 36);
  *(_DWORD *)(a1 + 44) = v6;
  if ( v6 )
    *(_BYTE *)(a1 + 33) = 1;
  a2[2] += 64 - v6;
  *(_DWORD *)(a1 + 48) += 4;
  v2 = (_WORD *)((char *)v2 + 1);
LABEL_20:
  result = 1;
  *(_DWORD *)(a1 + 52) = v2;
  return result;
}


//----- (00168060) --------------------------------------------------------
int __cdecl sub_168060(int a1, _BYTE *a2)
{
  int v2; // ebx
  int16_t v3; // cx
  int *v4; // esi
  int i; // ecx
  int v6; // eax
  int *v7; // esi
  int j; // ecx
  int v9; // eax
  int result; // eax
  int *v11; // esi
  int k; // ecx

  v2 = 0;
  LOWORD(dword_18A6D0) = *(_WORD *)(a1 + 29712);
  LOBYTE(v3) = *a2;
  HIBYTE(v3) = *a2;
  *(_WORD *)(a1 + 29734) = v3;
  *(_WORD *)(a1 + 29750) = v3;
  v4 = (int *)(*(_DWORD *)a1 + a1 + 29800);
  for ( i = *(_DWORD *)(a1 + 4) >> 2; i; --i )
  {
    v6 = *v4++;
    if ( (_WORD)dword_18A6D0 != (_WORD)v6 )
    {
      LOBYTE(v2) = v6;
      LOBYTE(v6) = a2[v2];
      LOBYTE(v2) = BYTE1(v6);
      BYTE1(v6) = a2[v2];
      *((_WORD *)v4 - 1) = v6;
    }
  }
  v7 = (int *)(*(_DWORD *)(a1 + 4) + *(_DWORD *)a1 + a1 + 29800);
  for ( j = *(_DWORD *)(a1 + 8) >> 2; j; --j )
  {
    v9 = *v7++;
    if ( (_WORD)dword_18A6D0 != (_WORD)v9 )
    {
      LOBYTE(v2) = v9;
      LOBYTE(v9) = a2[v2];
      LOBYTE(v2) = BYTE1(v9);
      BYTE1(v9) = a2[v2];
      *((_WORD *)v7 - 1) = v9;
    }
  }
  result = *(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 4) + *(_DWORD *)a1;
  v11 = (int *)(result + a1 + 29800);
  for ( k = *(_DWORD *)(a1 + 12) >> 2; k; --k )
  {
    result = *v11++;
    if ( (_WORD)dword_18A6D0 != (_WORD)result && (result & 3) == 3 )
    {
      LOBYTE(v2) = BYTE1(result);
      BYTE1(result) = a2[v2];
      *((_BYTE *)v11 - 1) = BYTE1(result);
    }
  }
  return result;
}
// 18A6D0: using guessed type int dword_18A6D0;


//----- (00168541) --------------------------------------------------------
int sub_168541()
{
  _enable();
  return 0;
}


//----- (00168545) --------------------------------------------------------
int sub_168545()
{
  _disable();
  return 0;
}


//----- (00168549) --------------------------------------------------------
int __cdecl sub_168549(int a1)
{
  uint8_t v1; // al

  v1 = hr_inbyte(a1);
  return (uint8_t)nullsub_22(v1, a1);
}
// 168692: using guessed type int __fastcall nullsub_22(_DWORD, _DWORD);


//----- (00168560) --------------------------------------------------------
int __cdecl sub_168560(int a1, int a2)
{
  hr_outbyte(a1, a2);
  return (uint8_t)nullsub_22(a2, a1);
}
// 168692: using guessed type int __fastcall nullsub_22(_DWORD, _DWORD);


//----- (00168577) --------------------------------------------------------
char __cdecl sub_168577(int a1, int a2)
{
  uint16_t v3; // dx
  int16_t v4; // cx
  _BOOL1 v5; // cc
  int16_t v6; // cx
  uint16_t v7; // dx
  uint8_t v8; // al
  int v9; // eax
  uint8_t v10; // al
  uint16_t v11; // dx

  _enable();
  do
  {
    v3 = *MK_FP(a2, a1 + 14);
    v4 = *MK_FP(a2, a1 + 18);
    v5 = v4 < *MK_FP(a2, a1 + 22);
    v6 = v4 - *MK_FP(a2, a1 + 22);
    if ( v5 )
      v6 += 1024;
    while ( 1 )
    {
      v7 = v3 + 5;
      v8 = hr_inbyte(v7);
      v9 = nullsub_22(v8, v7);
      v3 = v7 - 5;
      *MK_FP(a2, a1 + 30) = v9 | *MK_FP(a2, a1 + 30);
      LOBYTE(v9) = v9 & 1;
      if ( !(_BYTE)v9 )
        break;
      v10 = hr_inbyte(v3);
      if ( v6 < 1023 )
      {
        *MK_FP(a2, a1 + *MK_FP(a2, a1 + 18) + 58) = v10;
        *MK_FP(a2, a1 + 18) = *MK_FP(a2, a1 + 18) + 1;
        *MK_FP(a2, a1 + 18) = *MK_FP(a2, a1 + 18) & 0x3FF;
        ++v6;
      }
    }
    if ( v6 > 768 )
    {
      v11 = v3 + 4;
      LOBYTE(v9) = hr_inbyte(v11);
      LOBYTE(v9) = ~*MK_FP(a2, a1 + 34) & nullsub_22(v9, v11);
      hr_outbyte(v11, v9);
    }
    a1 = *MK_FP(a2, a1);
  }
  while ( a1 );
  return v9;
}
// 168692: using guessed type int __fastcall nullsub_22(_DWORD, _DWORD);


//----- (001685E9) --------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_1685E9(int a1)
{
  int v1; // esi
  int v2; // [esp-14h] [ebp-2Ch]
  int v3; // [esp-10h] [ebp-28h]

  __ES__ = *(_WORD *)&byte_18B040[4];
  v1 = a1 + *(_DWORD *)byte_18B040;
  v3 = *(_DWORD *)(a1 + *(_DWORD *)byte_18B040 + 42);
  v2 = *(_DWORD *)(a1 + *(_DWORD *)byte_18B040 + 46);
  ++*(_DWORD *)(v1 + 54);
  (*(void (__cdecl **)(_DWORD, _DWORD))(v1 + 10))(*(_DWORD *)(v1 + 20), *(uint16_t *)(v1 + 24));
  if ( (_WORD)v2 )
    hr_outbyte(v2, 0x20u);
  if ( (_WORD)v3 )
    hr_outbyte(v3, 0x20u);
  /* __asm: iret */ DECOMP_TODO("inline asm");
}
// 168635: positive sp value 4 has been found
// 168635: control flows out of bounds to 168636


//----- (00169020) --------------------------------------------------------
int __fastcall sub_169020(int result, int a2, int a3)
{
  if ( a3 == 1 )
    result -= 66154;
  return result;
}


//----- (001690CF) --------------------------------------------------------
int __usercall sub_1690CF(int a1, int a2)
{
  int v3; // [esp-4h] [ebp-4h]

  v3 = a1;
  if ( *(_BYTE *)(a1 + 37828) == 1 )
    a1 = sub_1690F9(a1, 5, (uint16_t *)(a1 - 128918), a2);
  sub_1690F9(a1, 23, (uint16_t *)(a1 - 128908), a2);
  return v3;
}


//----- (001690F9) --------------------------------------------------------
int __usercall sub_1690F9(int a1, int a2, uint16_t *a3, int a4)
{
  int v4; // eax
  char v6; // [esp-1Ch] [ebp-20h]
  int v7; // [esp-18h] [ebp-1Ch]
  uint16_t *v8; // [esp-14h] [ebp-18h]
  int v9; // [esp-10h] [ebp-14h]

  BYTE1(a2) = *(_BYTE *)(a1 + 6656);
  v4 = *(_DWORD *)a1;
  do
  {
    v9 = a2;
    v8 = a3;
    do
    {
      v7 = v4;
      v6 = a2;
      sub_E4204(v4, *a3, a4);
      v4 = v7;
      ++a3;
      LOBYTE(a2) = a2 - 1;
    }
    while ( v6 != 1 );
    v4 = v7 + 3753;
    a3 = v8;
    a2 = v9;
    BYTE1(a2) = BYTE1(v9) - 1;
  }
  while ( BYTE1(v9) != 1 );
  return a1;
}


//----- (0016915C) --------------------------------------------------------
int __fastcall sub_16915C(int result, int a2)
{
  *(_BYTE *)(result + 108) = HIBYTE(a2);
  if ( *(_BYTE *)(result + 100) != 5 )
    *(_BYTE *)(result + 100) = a2;
  return result;
}


//----- (00169169) --------------------------------------------------------
int __fastcall sub_169169(int a1, int a2)
{
  int v3; // [esp-8h] [ebp-Ch]

  v3 = 5 * a2;
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 2500) + 129 * *(int16_t *)(a1 + v3 - 4) + 100) == 5 )
    *(_BYTE *)(v3 + a1) = 0;
  return 5 * a2;
}


//----- (001691A0) --------------------------------------------------------
void sub_1691A0()
{
  if ( !*(_BYTE *)sub_F4B81() )
    sub_7BBBC();
}


//----- (001691E7) --------------------------------------------------------
int __usercall sub_1691E7(int *a1, int a2)
{
  int v3; // eax

  v3 = (int)a1 - 7454;
  if ( *(_BYTE *)(v3 - 129003) == 0xFF )
    sub_1690F9(v3, 3, (uint16_t *)(v3 - 128982), a2);
  if ( *((_BYTE *)a1 - 137176) == 1 )
    sub_1692E4((int)a1 - 7454, a2);
  return sub_124820(*a1);
}


//----- (00169245) --------------------------------------------------------
void sub_169245()
{
  char v0; // bl
  int v1; // eax
  _BYTE *v2; // [esp-Ch] [ebp-Ch]

  sub_1691A0();
  v2 = sub_F4B81();
  v0 = v2[2] | v2[740] & 2 | v2[731] & 4;
  v1 = sub_16945B((int)v2);
  *(_BYTE *)(v1 + 14) = v0;
  *(_BYTE *)(v1 + 13) = 0;
}


//----- (001692A2) --------------------------------------------------------
_BOOL1 __fastcall sub_1692A2( int a1, int a2, _BYTE *a3)
{
  _BOOL1 result; // al

  if ( (*(_BYTE *)(*(_DWORD *)((char *)sub_F4B81() + 109455) + 14) & 4) == 0 )
    return sub_17847(a1, a2, a3);
  sub_17847(a1, a2, a3);
  result = (char)a3;
  a3[4] = 0;
  return result;
}


//----- (001692C7) --------------------------------------------------------
void __usercall sub_1692C7( int a1, int a2, int a3)
{
  if ( (*(_BYTE *)(*(_DWORD *)((char *)sub_F4B81() + 109455) + 14) & 4) != 0 )
    *(_BYTE *)(a3 + 40) = 0;
  sub_1C417(a1, a2);
}


//----- (001692E4) --------------------------------------------------------
int __usercall sub_1692E4(int a1, int a2)
{
  char v2; // dh
  int v3; // eax
  int v5; // [esp-4h] [ebp-4h]

  v5 = sub_1690CF(a1, a2);
  v2 = *(_BYTE *)(v5 + 6656);
  v3 = *(_DWORD *)v5;
  do
  {
    *(_WORD *)(v3 + 199) = 771;
    *(_WORD *)(v3 + 216) = 770;
    v3 += 3753;
    --v2;
  }
  while ( v2 );
  return v5;
}


//----- (0016933A) --------------------------------------------------------
int __fastcall sub_16933A( int a1)
{
  int v1; // eax
  _BYTE *v2; // eax
  int v4; // [esp-4h] [ebp-4h]

  LOBYTE(v1) = sub_8C4D3(a1);
  v4 = v1;
  v2 = sub_F4B81();
  if ( v2[620] )
    v2[137776] = 0;
  return v4;
}
// 16933F: variable 'v1' is possibly undefined


//----- (0016937A) --------------------------------------------------------
void __fastcall sub_16937A(char *a1)
{
  *(_WORD *)a1 = (*(_BYTE *)(*(_DWORD *)((char *)sub_F4B81() + 109455) + 14) & 2) == 0
              || a1 - (char *)((_BYTE *)sub_F4B81() != 136183);
  JUMPOUT(0x11E68A);
}
// 1693A5: control flows out of bounds to 11E68A


//----- (001693B6) --------------------------------------------------------
int sub_1693B6()
{
  int v0; // eax
  char *v1; // eax
  int result; // eax
  int v3; // [esp-4h] [ebp-4h]

  LOWORD(v0) = sub_798D2();
  v3 = v0;
  if ( (*((_BYTE *)sub_F4B81() + 2) & 1) != 0 )
  {
    v1 = (char *)sub_F4B81();
    *(_WORD *)((char *)&loc_2152F + (_DWORD)v1) = 1011;
    *(_WORD *)(v1 + 136493) = 800;
    *(_WORD *)(v1 + 136373) = 15;
    *(_WORD *)(v1 + 136387) = 20;
    *(_WORD *)(v1 + 136385) = 3;
    *(_WORD *)(v1 + 136351) = 3;
    return v3;
  }
  else
  {
    result = (uint16_t)v3;
    switch ( (int16_t)v3 )
    {
      case 0:
        word_199A0C = 506;
        word_199A0A = 400;
        word_199992 = 10;
        word_1999A0 = 10;
        word_19997C = 0;
        word_19999E = 0;
        break;
      case 1:
        word_199A0C = 759;
        word_199A0A = 600;
        word_199992 = 15;
        word_1999A0 = 15;
        word_19997C = 1;
        word_19999E = 1;
        break;
      case 2:
        word_199A0C = 1012;
        word_199A0A = 800;
        word_199992 = 20;
        word_1999A0 = 20;
        word_19999E = 2;
        word_19997C = 2;
        break;
      case 3:
        word_199A0C = 1518;
        word_199A0A = 1200;
        word_199992 = 30;
        word_1999A0 = 30;
        word_19997C = 3;
        word_19999E = 3;
        break;
      default:
        result = v3;
        break;
    }
  }
  return result;
}
// 1693BB: variable 'v0' is possibly undefined
// 19997C: using guessed type int16_t word_19997C;
// 199992: using guessed type int16_t word_199992;
// 19999E: using guessed type int16_t word_19999E;
// 1999A0: using guessed type int16_t word_1999A0;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;


//----- (00169410) --------------------------------------------------------
int __stdcall sub_169410(int a1, int a2)
{
  sub_F4B81();
  return sub_12479(a1, a2);
}
// 12479: using guessed type _DWORD __stdcall sub_12479(_DWORD, _DWORD);


//----- (0016945B) --------------------------------------------------------
int __fastcall sub_16945B(int a1)
{
  return *(_DWORD *)(a1 + 109455);
}


//----- (0016946E) --------------------------------------------------------
void sub_16946E()
{
  sub_F4B81();
}


//----- (0016948F) --------------------------------------------------------
void sub_16948F()
{
  if ( (*(_BYTE *)(*(_DWORD *)((char *)sub_F4B81() + 109455) + 14) & 8) != 0 )
    *(_DWORD *)((char *)sub_F4B81() + 41713) = -65537;
}


//----- (001694B7) --------------------------------------------------------
// attributes: thunk
unsigned int __usercall sub_1694B7(int a1, int a2, int a3)
{
  unsigned int v3; // eax

  v3 = 4 * a1;
  if ( v3 >= 0x4B000 || a2 < 0 || (int)(v3 + 4 * a2) >= 307200 )
    v3 = 0;
  return *(_DWORD *)(a3 - 4) + v3;
}


//----- (001694B9) --------------------------------------------------------
void __fastcall sub_1694B9( int a1)
{
  sub_4A4E4(a1);
  sub_4A5CE();
}


//----- (001694D9) --------------------------------------------------------
void *__fastcall sub_1694D9(void *a1, void *a2, int a3)
{
  void *v4; // [esp-20h] [ebp-20h]

  v4 = a1;
  if ( (unsigned int)a1 >= 0xBFFFC )
    a1 = &loc_BFFF4 + 8;
  if ( a3 <= 0 || (unsigned int)a1 + a3 >= 0xBFFFC )
    a3 = 1;
  qmemcpy(a1, a2, 4 * a3);
  return v4;
}

// nfuncs=5399 queued=5098 decompiled=5098 lumina nreq=0 worse=0 better=0
// error "There were 35 decompilation failure(s) on 5098 function(s)"

