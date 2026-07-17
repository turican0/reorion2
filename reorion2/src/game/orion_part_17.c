#include "orion_common.h"

/* Adresni rozsah: 0x10278D - 0x10CDD8  (200 funkci) */

//----- (0010278D) --------------------------------------------------------
int __fastcall sub_10278D( int a1, int a2, int a3)
{
  int v3; // ecx
  int result; // eax

  v3 = dword_197F98 + 3753 * a1;
  result = a2;
  *(_BYTE *)(v3 + a2 + 3671) &= 0xC0u;
  *(_BYTE *)(v3 + a2 + 3671) |= a3 & 0x3F;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (001027B5) --------------------------------------------------------
void __fastcall sub_1027B5( int a1, int a2)
{
  *(_BYTE *)(a2 + 3753 * a1 + dword_197F98 + 3671) &= 0x3Fu;
  JUMPOUT(0x1027AC);
}
// 1027D7: control flows out of bounds to 1027AC
// 197F98: using guessed type int dword_197F98;


//----- (001027D9) --------------------------------------------------------
int __fastcall sub_1027D9( int a1, int a2)
{
  int result; // eax

  result = 3753 * word_19999C + dword_197F98 + a1;
  *(_BYTE *)(result + 3671) &= 0xC0u;
  *(_BYTE *)(result + 3671) |= a2 & 0x3F;
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010280D) --------------------------------------------------------
void __fastcall sub_10280D( int a1)
{
  int v1; // eax

  v1 = 3753 * word_19999C + dword_197F98 + a1;
  *(_BYTE *)(v1 + 3671) &= 0x3Fu;
  JUMPOUT(0x102804);
}
// 10283B: control flows out of bounds to 102804
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010283D) --------------------------------------------------------
int __fastcall sub_10283D( int a1)
{
  int result; // eax

  result = dword_197F98 + 3753 * word_19999C + word_19999C;
  *(_BYTE *)(result + 3671) &= 0xC0u;
  *(_BYTE *)(result + 3671) |= a1 & 0x3F;
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (00102872) --------------------------------------------------------
void sub_102872()
{
  int v0; // eax

  v0 = dword_197F98 + 3753 * word_19999C + word_19999C;
  *(_BYTE *)(v0 + 3671) &= 0x3Fu;
  JUMPOUT(0x102868);
}
// 1028A0: control flows out of bounds to 102868
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (001028A2) --------------------------------------------------------
int __fastcall sub_1028A2( int a1, int a2)
{
  int v2; // eax

  v2 = a2 + dword_197F98 + 3753 * a1;
  if ( (*(_BYTE *)(v2 + 3671) & 0x3F) == 0 )
    return 0;
  --*(_BYTE *)(v2 + 3671);
  return 1;
}
// 197F98: using guessed type int dword_197F98;


//----- (001028D5) --------------------------------------------------------
int __fastcall sub_1028D5( int a1)
{
  int v1; // eax

  v1 = dword_197F98 + 3753 * word_19999C + a1;
  if ( (*(_BYTE *)(v1 + 3671) & 0x3F) == 0 )
    return 0;
  --*(_BYTE *)(v1 + 3671);
  return 1;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (00102912) --------------------------------------------------------
int sub_102912()
{
  int v0; // eax

  v0 = dword_197F98 + 3753 * word_19999C + word_19999C;
  if ( (*(_BYTE *)(v0 + 3671) & 0x3F) == 0 )
    return 0;
  --*(_BYTE *)(v0 + 3671);
  return 1;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010294B) --------------------------------------------------------
int __fastcall sub_10294B( int a1, int a2)
{
  int v2; // eax
  int v3; // edx

  v2 = 3753 * a1 + dword_197F98 + (int16_t)a2;
  LOWORD(a2) = *(_BYTE *)(v2 + 3671) & 0x3F;
  v3 = a2 + 1;
  if ( (int16_t)v3 > 63 )
    return 0;
  *(_BYTE *)(v2 + 3671) = v3;
  return v3;
}
// 197F98: using guessed type int dword_197F98;


//----- (00102994) --------------------------------------------------------
int sub_102994()
{
  int v0; // edx
  int v1; // eax
  int v2; // edx

  v0 = dword_197F98 + 3753 * word_19999C;
  v1 = v0 + word_19999C;
  LOWORD(v0) = *(_BYTE *)(v1 + 3671) & 0x3F;
  v2 = v0 + 1;
  if ( (int16_t)v2 > 63 )
    return 0;
  *(_BYTE *)(v1 + 3671) = v2;
  return v2;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (001029D1) --------------------------------------------------------
int16_t __fastcall sub_1029D1(_WORD *a1)
{
  if ( (int16_t)(dword_192FD8 + 30536) <= 350 )
  {
    *a1 = dword_192FD8 + 30536;
    return 0;
  }
  else
  {
    *a1 = 350;
    return word_17D636;
  }
}
// 17D636: using guessed type int16_t word_17D636;
// 192FD8: using guessed type int dword_192FD8;


//----- (001029FA) --------------------------------------------------------
void __fastcall sub_1029FA(int a1)
{
  int16_t v2; // di
  int16_t i; // ax
  int v4; // ecx
  int16_t v5; // ax
  int16_t v6; // cx
  int16_t v7; // si
  int16_t v8; // si
  int16_t v9; // cx
  int16_t v10; // dx
  _WORD *v11; // ecx
  int16_t v12; // dx
  int16_t *v13; // eax
  int16_t v14; // cx
  int v15; // edx
  int v16; // eax
  int16_t v17; // si
  int v18; // edi
  int v19; // eax
  int16_t j; // [esp+4h] [ebp-8h]
  int16_t v21; // [esp+8h] [ebp-4h]

  if ( *(int16_t *)(a1 + 28) > 0 )
  {
    sub_117324(*(_WORD *)(a1 + 28));
    sub_117324(*(_WORD *)(a1 + 28) + 1);
  }
  *(_WORD *)(*(_DWORD *)a1 + 2 * *(int16_t *)(a1 + 8)) = 0;
  if ( !*(_WORD *)(a1 + 8) )
LABEL_70:
    JUMPOUT(0x102421);
  v2 = sub_113F8C();
  if ( v2 == *(_WORD *)(a1 + 28) && *(int16_t *)(a1 + 16) > 0 )
  {
    *(_WORD *)(a1 + 16) -= *(_WORD *)(a1 + 14);
    if ( *(int16_t *)(a1 + 16) < 0 )
      *(_WORD *)(a1 + 16) = 0;
    for ( i = *(_WORD *)(a1 + 16); (*(_BYTE *)(*(_DWORD *)a1 + 2 * i + 1) & 0x40) != 0 && i >= 0; --i )
      ;
    if ( i < 0 )
      goto LABEL_30;
  }
  else
  {
    if ( v2 != *(int16_t *)(a1 + 28) + 1 )
      goto LABEL_30;
    v4 = *(int16_t *)(a1 + 8);
    if ( *(int16_t *)(a1 + 18) >= v4 - 1 )
      goto LABEL_30;
    v5 = *(_WORD *)(a1 + 14) + *(_WORD *)(a1 + 16);
    if ( v5 + *(int16_t *)(a1 + 12) >= v4 )
    {
      v6 = *(_WORD *)(a1 + 8);
      v7 = *(_WORD *)(a1 + 22);
      do
      {
        if ( --v6 <= *(int16_t *)(a1 + 16) )
          break;
        v7 -= (*(_BYTE *)(*(_DWORD *)a1 + 2 * v6 + 1) & 0x40) != 0
            ? *(_WORD *)(a1 + 26)
            : *(_WORD *)(a1 + 24) + *(int16_t *)(a1 + 26) / 2;
      }
      while ( v7 >= *(int16_t *)(a1 + 20) );
      *(_WORD *)(a1 + 16) = v6 + 1;
    }
    else
    {
      *(_WORD *)(a1 + 16) = v5;
    }
    for ( i = *(_WORD *)(a1 + 16); (*(_BYTE *)(*(_DWORD *)a1 + 2 * i + 1) & 0x40) != 0; ++i )
      ;
    if ( i >= *(int16_t *)(a1 + 8) )
      goto LABEL_30;
  }
  *(_WORD *)(a1 + 16) = i;
LABEL_30:
  **(_WORD **)(a1 + 4) = *(_WORD *)(a1 + 20);
  v8 = 0;
  v9 = *(_WORD *)(a1 + 12);
  v21 = v9 + *(_WORD *)(a1 + 16);
  if ( v21 > *(int16_t *)(a1 + 8) )
    v21 = *(_WORD *)(a1 + 8) + 1;
  for ( j = *(_WORD *)(a1 + 16); j < v21; ++j )
  {
    if ( (*(_BYTE *)(*(_DWORD *)a1 + 2 * j + 1) & 0x40) != 0 )
    {
      v10 = *(_WORD *)(a1 + 26) + *(_WORD *)(2 * v8 + *(_DWORD *)(a1 + 4));
    }
    else
    {
      if ( v8 )
      {
        v11 = (_WORD *)(2 * v8 + *(_DWORD *)(a1 + 4));
        *v11 += *(int16_t *)(a1 + 26) / 2;
      }
      v9 = v8;
      v10 = *(_WORD *)(a1 + 24) + *(_WORD *)(*(_DWORD *)(a1 + 4) + 2 * v8);
    }
    *(_WORD *)(2 * ++v8 + *(_DWORD *)(a1 + 4)) = v10;
    if ( v10 > *(int16_t *)(a1 + 22) )
      break;
  }
  if ( v8 >= *(int16_t *)(a1 + 8) )
    v9 = *(_WORD *)(a1 + 8);
  if ( v9 > 0 )
    --v9;
  if ( !v2 )
    v2 = (uint16_t)sub_114177();
  if ( v2 == *(int16_t *)(a1 + 28) + 2 && *(int16_t *)(a1 + 10) >= 0 )
  {
    v12 = sub_123AE7();
    for ( *(_WORD *)(a1 + 10) = 0; v9 > *(int16_t *)(a1 + 10); ++*(_WORD *)(a1 + 10) )
    {
      v13 = (int16_t *)(2 * *(int16_t *)(a1 + 10) + *(_DWORD *)(a1 + 4));
      if ( v12 >= *v13 && v12 < v13[1] )
        break;
    }
    *(_WORD *)(a1 + 10) += *(_WORD *)(a1 + 16);
  }
  v14 = *(_WORD *)(a1 + 16) + v9;
  *(_WORD *)(a1 + 18) = v14;
  if ( *(int16_t *)(a1 + 10) >= 0 )
  {
    v15 = *(int16_t *)(a1 + 10);
    v16 = 2 * v15 + *(_DWORD *)a1;
    if ( (*(_BYTE *)(v16 + 1) & 0x40) == 0 && (*(_BYTE *)(v16 + 3) & 0x40) != 0 && v15 + 1 <= v14 )
      ++*(_WORD *)(a1 + 10);
  }
  v17 = *(_WORD *)(a1 + 16);
  v18 = 0;
  while ( v17 <= v14 )
  {
    v19 = 2 * (int16_t)v18++;
    (*(void (__fastcall **)(_DWORD, _DWORD))(a1 + 30))(v17++, *(int16_t *)(*(_DWORD *)(a1 + 4) + v19));
  }
  if ( *(int16_t *)(a1 + 28) > 0 )
  {
    if ( *(_WORD *)(a1 + 16) )
      sub_1173DC(*(_WORD *)(a1 + 28));
    if ( *(int16_t *)(a1 + 18) < *(int16_t *)(a1 + 8) - 1 )
      sub_1173DC(*(_WORD *)(a1 + 28) + 1);
  }
  if ( *(int16_t *)(a1 + 10) < 0 )
    *(_WORD *)(a1 + 10) = 0;
  goto LABEL_70;
}
// 102CDA: control flows out of bounds to 102421


//----- (00102CDF) --------------------------------------------------------
int sub_102CDF()
{
  sub_132C80(100);
  return sub_131922(0, 255);
}


//----- (00102CF9) --------------------------------------------------------
int16_t sub_102CF9()
{
  int16_t result; // ax
  int16_t v1; // dx
  int16_t v2; // bx

  result = sub_113E65();
  v1 = 1;
  v2 = result - 1;
  while ( v1 <= v2 )
    result = (uint16_t)sub_117324(v1++);
  return result;
}


//----- (00102D1B) --------------------------------------------------------
int16_t sub_102D1B()
{
  int16_t result; // ax
  int16_t v1; // dx
  int16_t v2; // bx

  result = sub_113E65();
  v1 = 1;
  v2 = result - 1;
  while ( v1 <= v2 )
    result = sub_1173DC(v1++);
  return result;
}


//----- (00102D3D) --------------------------------------------------------
char *__fastcall sub_102D3D(char *result)
{
  int16_t v1; // bx
  int16_t v2; // dx
  int16_t v3; // cx
  int16_t i; // dx

  v1 = (int16_t)result;
  if ( (int16_t)result >= 1 )
  {
    v2 = 1;
    v3 = (int16_t)result;
    while ( v2 <= v3 )
      sub_1173DC(v2++);
    result = (char *)sub_11E718();
    for ( i = 1; i <= v1; ++i )
      result = sub_117324(i);
  }
  return result;
}


//----- (00102D7D) --------------------------------------------------------
char *__fastcall sub_102D7D(char *result, int a2)
{
  int16_t i; // dx

  for ( i = (int16_t)result; i <= a2; ++i )
    result = sub_117324(i);
  return result;
}


//----- (00102D94) --------------------------------------------------------
int16_t __fastcall sub_102D94( int result, int a2)
{
  int16_t i; // dx

  for ( i = result; i <= a2; ++i )
    result = sub_1173DC(i);
  return result;
}


//----- (00102DAB) --------------------------------------------------------
void __fastcall sub_102DAB( int a1, int a2, int a3, int a4, int a5, unsigned int a6, int a7)
{
  uint16_t v8; // [esp+4h] [ebp-1Ch]
  int16_t v9; // [esp+8h] [ebp-18h]
  int16_t v10; // [esp+Ch] [ebp-14h]
  int16_t v11; // [esp+10h] [ebp-10h]
  int v12; // [esp+14h] [ebp-Ch]
  char v13; // [esp+18h] [ebp-8h]
  char v14; // [esp+1Ch] [ebp-4h]

  v14 = 0;
  if ( (int16_t)sub_12066F(a3) <= a4 )
  {
    sub_1035AF(a1, a2, a4, a3, a6, 1, a5);
  }
  else
  {
    v13 = byte_1B3EC8;
    v10 = word_1B3EA6;
    v9 = HIWORD(dword_1B61E4);
    LOWORD(v12) = 0;
    v11 = word_1B3E86;
    v8 = sub_122259();
    while ( 1 )
    {
      while ( (uint8_t)byte_1B3EC8 > (uint8_t)byte_183684[SHIWORD(dword_1B61E4)]
           && (int16_t)sub_12066F(a3) > a4 )
        --byte_1B3EC8;
      while ( (int16_t)sub_12066F(a3) > a4 && word_1B3EA6 > 1 )
        --word_1B3EA6;
      if ( (int16_t)sub_12066F(a3) <= a4 || SHIWORD(dword_1B61E4) <= 0 )
        break;
      sub_120BB5(SHIWORD(dword_1B61E4) - 1, (int)byte_1B3E88);
      if ( a7 )
        v12 = (v8 - sub_122259()) / 2;
      v14 = 1;
    }
    word_1B3E86 = v11;
    sub_1035AF(a1, v12 + a2, a4, a3, a6, 1, a5);
    byte_1B3EC8 = v13;
    word_1B3EA6 = v10;
    if ( v14 )
    {
      sub_120BB5(v9, (int)byte_1B3E7C);
      word_1B3E86 = v11;
    }
  }
}
// 1B3E86: using guessed type int16_t word_1B3E86;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1B3EC8: using guessed type char byte_1B3EC8;
// 1B61E4: using guessed type int dword_1B61E4;


//----- (00102F10) --------------------------------------------------------
void __fastcall sub_102F10( int a1, int a2, int a3, int a4)
{
  sub_102DAB(a1, a2, a3, a4, 0, 0, 1);
}


//----- (00102F4F) --------------------------------------------------------
void __fastcall sub_102F4F( int a1, int a2, int a3, int a4)
{
  sub_102DAB(a1 - a4 / 2, a2, a3, a4, 0, 2u, 1);
}


//----- (00102F78) --------------------------------------------------------
void __fastcall sub_102F78( int a1, int a2, int a3, int a4, int a5)
{
  sub_102DAB(a1 - a4 / 2, a2, a3, a4, a5, 2u, 1);
}


//----- (00102FA8) --------------------------------------------------------
void sub_102FA8()
{
  JUMPOUT(0x102F14);
}
// 102FAC: control flows out of bounds to 102F14


//----- (00102FD8) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=111)) - nutno dohledat rucne v IDA @ 0x10311B */
_DWORD __stdcall sub_102FD8(_DWORD _p0, int _p1, _DWORD _p2, int _p3, int _p4)
{
  DECOMP_TODO("call analysis failed (funcsize=111)");
}


//----- (0010315D) --------------------------------------------------------
int __stdcall sub_10315D(int a1, int a2)
{
  return sub_102FD8(a1, a2, 0, 0, 0);
}
// 102FD8: using guessed type _DWORD __stdcall sub_102FD8(_DWORD, int16_t, _DWORD, char, char);


//----- (00103183) --------------------------------------------------------
int __stdcall sub_103183(int a1, int a2, int a3)
{
  return sub_102FD8(a1, a2, a3, 0, 0);
}
// 102FD8: using guessed type _DWORD __stdcall sub_102FD8(_DWORD, int16_t, _DWORD, char, char);


//----- (001031AA) --------------------------------------------------------
void __stdcall sub_1031AA(int a1, int a2)
{
  JUMPOUT(0x103169);
}
// 1031B6: control flows out of bounds to 103169


//----- (001031B8) --------------------------------------------------------
void __stdcall sub_1031B8(int a1, int a2, int a3)
{
  JUMPOUT(0x10318F);
}
// 1031C4: control flows out of bounds to 10318F


//----- (001031C6) --------------------------------------------------------
int __stdcall sub_1031C6(int a1, int a2)
{
  return sub_102FD8(a1, a2, 0, 0, 1);
}
// 102FD8: using guessed type _DWORD __stdcall sub_102FD8(_DWORD, int16_t, _DWORD, char, char);


//----- (00103200) --------------------------------------------------------
void __cdecl sub_103200(int a1, int a2, int a3)
{
  sub_102FD8(a1, a2, a3, 0, 1);
  JUMPOUT(0x103235);
}
// 103230: control flows out of bounds to 103235
// 102FD8: using guessed type _DWORD __stdcall sub_102FD8(_DWORD, int16_t, _DWORD, char, char);


//----- (0010323B) --------------------------------------------------------
void __stdcall sub_10323B(int a1, int a2)
{
  JUMPOUT(0x1031D3);
}
// 103248: control flows out of bounds to 1031D3


//----- (0010324A) --------------------------------------------------------
void sub_10324A()
{
  JUMPOUT(0x10320D);
}
// 103257: control flows out of bounds to 10320D


//----- (00103259) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=44)) - nutno dohledat rucne v IDA @ 0x10327D */
_DWORD __stdcall sub_103259(_DWORD _p0)
{
  DECOMP_TODO("call analysis failed (funcsize=44)");
}


//----- (001032D8) --------------------------------------------------------
int __stdcall sub_1032D8(int a1)
{
  return sub_103259(a1);
}
// 103259: using guessed type _DWORD __stdcall sub_103259(_DWORD);


//----- (001032FB) --------------------------------------------------------
int __fastcall sub_1032FB(int result)
{
  if ( (int16_t)result >= 75 )
    result += 129;
  return result;
}


//----- (00103313) --------------------------------------------------------
int __fastcall sub_103313(int a1)
{
  int v1; // eax
  int v2; // esi
  int64_t v3; // rax
  int64_t v4; // rax
  int v5; // edi
  int v6; // eax
  int64_t v7; // rax
  char *v9; // [esp+0h] [ebp-1012h]
  char *v10; // [esp+4h] [ebp-100Eh]
  _BYTE v11[4096]; // [esp+8h] [ebp-100Ah] BYREF
  char v12[128]; // [esp+1008h] [ebp-Ah] BYREF
  int v13; // [esp+1088h] [ebp+76h]
  int v14; // [esp+108Ch] [ebp+7Ah]
  int v15; // [esp+1090h] [ebp+7Eh]

      // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    v14 = fopen(a1, aRb);
      // DECOMP_TODO (castecne vyreseno ve vlne 06): chybel mod parametr - v okoli se nenaslo jednoznacne fread/fwrite, takze "aRb" je bezpecny odhad (needela zadnou zapisovou vedlejsi ucinek jako by mohl "wb"), potrebuje overit.
    v1 = fopen(v9, aRb);
  v2 = v1;
  if ( !v14 )
  {
    v3 = sprintf(v12, "Could not open %s", v10);
    sub_126487(v12, SHIDWORD(v3));
  }
  if ( !v1 )
  {
    v4 = sprintf(v12, "Could not open %s", v9);
    sub_126487(v12, SHIDWORD(v4));
  }
  v15 = 0;
  do
  {
    v5 = fread(v11, 1, 4096, v14);
    v13 = v5;
    sub_FE8BE(v5, 1, 4096, (int16_t *)v5);
    v6 = fwrite(v11, 1, v5, v2);
    v15 += v5;
    if ( v5 != v6 )
    {
      v7 = sprintf(v12, "Error copying %s to %s (bytes: %i)", v10, v9, v15);
      sub_126487(v12, SHIDWORD(v7));
    }
  }
  while ( v13 == 4096 );
  fflush(v2);
  fclose(v2);
  return fclose(v14);
}
// 10333D: variable 'v9' is possibly undefined
// 103357: variable 'v10' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);
// 129FE9: using guessed type int __fastcall fflush(_DWORD);


//----- (00103421) --------------------------------------------------------
_BYTE *sub_103421()
{
  char *v0; // edi
  char *v2; // [esp-4h] [ebp-6h] BYREF
  char v3[128]; // [esp+0h] [ebp-2h] BYREF
  _BYTE v4[52]; // [esp+80h] [ebp+7Eh] BYREF

  sprintf(byte_1ACE98, "SR_R%x_SC.LBX", *(uint8_t *)(3753 * word_19999C + dword_197F98 + 37));
  if ( !FindMoxSetPath_1114D7(byte_1ACE98, v4) )
  {
    if ( FindMoxSetPath_1114D7(aSrRScLbx, v4) )
      sub_1117BF((int)v4);
    strcpy(v3, byte_184544);
    v2 = v3;
    v0 = (char *)&v2 + 3;
    do
      ++v0;
    while ( *v0 );
    strcpy(v0, byte_1ACE98);
    sub_103313((int)v3);
  }
  return byte_1ACE98;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 1ACE98: using guessed type _BYTE byte_1ACE98[32];


//----- (001034CB) --------------------------------------------------------
void sub_1034CB()
{
  _BYTE v0[52]; // [esp+80h] [ebp+7Eh] BYREF

  sprintf(byte_1ACE98, "SR_R%x_SP.LBX", *(uint8_t *)(dword_197F98 + 3753 * word_19999C + 37));
  if ( !FindMoxSetPath_1114D7(byte_1ACE98, v0) )
    JUMPOUT(0x103472);
  JUMPOUT(0x1034BB);
}
// 10351C: control flows out of bounds to 103472
// 103512: control flows out of bounds to 1034BB
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 1ACE98: using guessed type _BYTE byte_1ACE98[32];


//----- (00103521) --------------------------------------------------------
void sub_103521()
{
  _BYTE v0[52]; // [esp+80h] [ebp+7Eh] BYREF

  sprintf(byte_1ACE98, "SR_R%x_TR.LBX", *(uint8_t *)(dword_197F98 + 3753 * word_19999C + 37));
  if ( !FindMoxSetPath_1114D7(byte_1ACE98, v0) )
    JUMPOUT(0x103472);
  JUMPOUT(0x1034BB);
}
// 103576: control flows out of bounds to 103472
// 103568: control flows out of bounds to 1034BB
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 1ACE98: using guessed type _BYTE byte_1ACE98[32];


//----- (001035AF) --------------------------------------------------------
void __fastcall sub_1035AF( int a1, int a2, int a3, int a4, unsigned int a5, int a6, int a7)
{
  uint16_t v9; // cx
  uint16_t v10; // ax
  int v11; // ecx
  char *v12; // edi
  _BOOL1 v13; // zf
  int16_t v14; // ax
  int16_t v15; // [esp+0h] [ebp-8h]

  v9 = a5;
  if ( a3 >= 10 && a3 <= 640 && (uint16_t)a1 < 0x280u && (uint16_t)a2 < 0x1E0u && a4 )
  {
    v15 = sub_12066F(a4);
    if ( a5 == 1 || a5 == 3 )
      v15 = a3;
    if ( a6 )
    {
      if ( a7 )
        HIBYTE(v9) = HIBYTE(a5) | 8;
      v10 = v9;
      v11 = 9;
      v12 = &byte_10357B;
      do
      {
        if ( !v11 )
          break;
        v13 = *(_WORD *)v12 == v10;
        v12 += 2;
        --v11;
      }
      while ( !v13 );
      v14 = a1 + a3 - 1;
      switch ( v11 )
      {
        case 0:
          break;
        case 1:
          sub_1212B3(a1, a2, a4);
          break;
        case 2:
          sub_1210B7(v14, a2, a4);
          break;
        case 3:
          sub_1210FD(a1 + a3 / 2, a2, a4);
          break;
        case 4:
          sub_12126B(a1, a2, a4, a3);
          break;
        case 5:
          sub_122A6E(a1, a2, a4, a7);
          break;
        case 6:
          sub_12297B(v14, a2, a4, a7);
          break;
        case 7:
          sub_1229C5(a1 + a3 / 2, a2, a4, a7);
          break;
        case 8:
          sub_122A1F(a1, a2, a4, a3, a7);
          break;
      }
    }
    if ( v15 > (int)(uint16_t)word_1ACEBA )
      word_1ACEBA = v15;
  }
  JUMPOUT(0x102F0A);
}
// 103705: control flows out of bounds to 102F0A
// 10357B: using guessed type char byte_10357B;
// 1ACEBA: using guessed type int16_t word_1ACEBA;


//----- (0010370A) --------------------------------------------------------
int __userpurge sub_10370A(
        int result, unsigned int a2,
        int a3, int a4,
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
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int64_t a36)
{
  int v36; // esi
  int v37; // eax
  uint16_t v38; // bx
  char v39; // dh
  uint8_t v40; // dl
  uint16_t v41; // bx
  int v42; // ecx
  int v43; // ecx
  int v44; // eax
  int v45; // eax
  int v46; // [esp+66h] [ebp-72h]
  int16_t v47; // [esp+6Ah] [ebp-6Eh]
  int v48; // [esp+6Eh] [ebp-6Ah]
  int16_t v49; // [esp+72h] [ebp-66h]
  _BYTE v51[98]; // [esp+76h] [ebp-62h] BYREF
  int16_t v52; // [esp+13Eh] [ebp+66h]
  int v53; // [esp+142h] [ebp+6Ah]
  int v54; // [esp+146h] [ebp+6Eh]
  int v55; // [esp+14Ah] [ebp+72h]

  if ( a4 < 10 || a4 > 640 || (uint16_t)result >= 0x280u || a2 >= 0x1E0u || !a3 )
    return result;
  word_1ACEBA = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v54 = v48;
  v55 = 0;
  v53 = 0;
  v52 = 479 - word_1B3EA0;
  while ( 1 )
  {
    v40 = *(_BYTE *)(v46 + (int16_t)v36);
    if ( !v40 )
      break;
    if ( v40 == 9 )
      v40 = 32;
    if ( v40 == 32 || v40 == 8 && v47 >= (uint8_t)byte_1B3ED5 + v38 )
    {
      v39 = v40;
      v55 = v36;
      v53 = v37;
    }
    if ( v40 == 13 || v40 == 10 )
    {
      v39 = 13;
      goto LABEL_25;
    }
    if ( v40 < 0x20u )
    {
      ++v36;
    }
    else
    {
      v41 = (uint8_t)byte_1B3EA8[v40] + v38;
      if ( v40 == 32 || v41 <= v47 )
      {
        v42 = (int16_t)v37;
        ++v36;
        v38 = word_1B3EA6 + v41;
        ++v37;
        v51[v42] = v40;
      }
      else
      {
        if ( (_WORD)v53 )
          v37 = v53;
        if ( (_WORD)v55 )
          v36 = v55;
LABEL_25:
        while ( v51[(int16_t)v37 - 1] == 32 && (int16_t)v37 > 1 )
          --v37;
        if ( (int16_t)v37 > 0 || v39 == 13 )
        {
          if ( v39 == 8 )
          {
            v43 = (int16_t)v37;
            LOWORD(v37) = v37 + 1;
            v51[v43] = 45;
          }
          else
          {
            ++v36;
          }
          v51[(int16_t)v37] = 0;
          sub_1035AF(v49, v54, v47, (int)v51, HIWORD(a34), SBYTE2(a35), *(int *)((char *)&a36 + 2));
          LOWORD(v44) = word_1B3EA2;
          v54 += v44;
          v37 = 0;
          if ( (int16_t)v54 > v52 )
            break;
        }
        v38 = 0;
        v39 = 0;
        v55 = 0;
        v53 = 0;
      }
    }
  }
  v51[(int16_t)v37] = 0;
  if ( (_WORD)v37 )
  {
    if ( HIWORD(a34) == 3 )
      HIWORD(a34) = 0;
    sub_1035AF(v49, v54, v47, (int)v51, HIWORD(a34), SBYTE2(a35), *(int *)((char *)&a36 + 2));
  }
  HIWORD(v45) = HIWORD(v54);
  LOWORD(v45) = word_1B3EA0 + v54;
  result = v45 - v48;
  word_1ACEB8 = result;
  return result;
}
// 103851: conditional instruction was optimized away because dh.1 is in (==0|==D|==20)
// 10376F: variable 'v48' is possibly undefined
// 10378A: variable 'v46' is possibly undefined
// 1037B4: variable 'v47' is possibly undefined
// 103881: variable 'v49' is possibly undefined
// 10388C: variable 'v44' is possibly undefined
// 1ACEB8: using guessed type int16_t word_1ACEB8;
// 1ACEBA: using guessed type int16_t word_1ACEBA;
// 1B3EA0: using guessed type int16_t word_1B3EA0;
// 1B3EA2: using guessed type int16_t word_1B3EA2;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1B3ED5: using guessed type char byte_1B3ED5;


//----- (00103915) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=14)) - nutno dohledat rucne v IDA @ 0x103929 */
_DWORD __stdcall sub_103915( int _p0)
{
  DECOMP_TODO("call analysis failed (funcsize=14)");
}


//----- (00103933) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=14)) - nutno dohledat rucne v IDA @ 0x103948 */
_DWORD __stdcall sub_103933( int _p0, _DWORD _p1)
{
  DECOMP_TODO("call analysis failed (funcsize=14)");
}


//----- (00103952) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=14)) - nutno dohledat rucne v IDA @ 0x103963 */
int __fastcall sub_103952(_DWORD _p0, _DWORD _p1, _DWORD _p2)
{
  DECOMP_TODO("call analysis failed (funcsize=14)");
}


//----- (00103971) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=13)) - nutno dohledat rucne v IDA @ 0x103983 */
int __fastcall sub_103971(_DWORD _p0, _DWORD _p1, _DWORD _p2)
{
  DECOMP_TODO("call analysis failed (funcsize=13)");
}


//----- (00103990) --------------------------------------------------------
int sub_103990()
{
  unk_1836B4 = unk_1836C8;
  unk_1836B8 = unk_1836CC;
  unk_1836BC = unk_1836D0;
  sub_1196F7();
  return sub_1196B8((int)&unk_1836A0, 3);
}


//----- (001039B9) --------------------------------------------------------
void sub_1039B9()
{
  JUMPOUT(0x10399D);
}
// 1039C6: control flows out of bounds to 10399D


//----- (001039C8) --------------------------------------------------------
void sub_1039C8()
{
  JUMPOUT(0x10399D);
}
// 1039D5: control flows out of bounds to 10399D


//----- (001039D7) --------------------------------------------------------
int sub_1039D7()
{
  sub_1196F7();
  return sub_1196B8((int)&unk_1836F0, 1);
}


//----- (001039EE) --------------------------------------------------------
void sub_1039EE()
{
  JUMPOUT(0x10399D);
}
// 1039FB: control flows out of bounds to 10399D


//----- (001039FD) --------------------------------------------------------
void sub_1039FD()
{
  JUMPOUT(0x10399D);
}
// 103A0A: control flows out of bounds to 10399D


//----- (00103A0C) --------------------------------------------------------
void sub_103A0C()
{
  JUMPOUT(0x10399D);
}
// 103A19: control flows out of bounds to 10399D


//----- (00103A1B) --------------------------------------------------------
void sub_103A1B()
{
  JUMPOUT(0x10399D);
}
// 103A28: control flows out of bounds to 10399D


//----- (00103A2D) --------------------------------------------------------
void sub_103A2D()
{
  sub_1196F7();
  JUMPOUT(0x1039E7);
}
// 103A3D: control flows out of bounds to 1039E7


//----- (00103A3F) --------------------------------------------------------
void sub_103A3F()
{
  sub_1196F7();
  JUMPOUT(0x1039E7);
}
// 103A4F: control flows out of bounds to 1039E7


//----- (00103A51) --------------------------------------------------------
void sub_103A51()
{
  sub_1196F7();
  JUMPOUT(0x1039E7);
}
// 103A61: control flows out of bounds to 1039E7


//----- (00103A63) --------------------------------------------------------
void sub_103A63()
{
  sub_1196F7();
  JUMPOUT(0x1039E7);
}
// 103A73: control flows out of bounds to 1039E7


//----- (00103A78) --------------------------------------------------------
void sub_103A78()
{
  sub_1196F7();
  JUMPOUT(0x1039E7);
}
// 103A88: control flows out of bounds to 1039E7


//----- (00103A8D) --------------------------------------------------------
void sub_103A8D()
{
  sub_1196F7();
  JUMPOUT(0x1039E7);
}
// 103A9D: control flows out of bounds to 1039E7


//----- (00103AA2) --------------------------------------------------------
void sub_103AA2()
{
  sub_1196F7();
  JUMPOUT(0x1039E7);
}
// 103AB2: control flows out of bounds to 1039E7


//----- (00103AB7) --------------------------------------------------------
void sub_103AB7()
{
  sub_1196F7();
  JUMPOUT(0x1039E7);
}
// 103AC7: control flows out of bounds to 1039E7


//----- (00103BB3) --------------------------------------------------------
int __fastcall sub_103BB3(int a1, int a2)
{
  sub_1196F7();
  return sub_1196B8(a1, a2);
}


//----- (00103BC4) --------------------------------------------------------
int __fastcall sub_103BC4( unsigned int a1, unsigned int a2, int a3, int a4, int a5)
{
  return sub_103D53(a1, a2, a3, a4, a5, 0, 1);
}


//----- (00103BE2) --------------------------------------------------------
int __fastcall sub_103BE2( unsigned int a1, unsigned int a2, int a3, int a4, int a5, int a6)
{
  return sub_103D53(a1, a2, a3, a4, a5, a6, 1);
}


//----- (00103C01) --------------------------------------------------------
int __fastcall sub_103C01(int result)
{
  dword_1ACF70 = result;
  return result;
}
// 1ACF70: using guessed type int dword_1ACF70;


//----- (00103C07) --------------------------------------------------------
int __fastcall sub_103C07(int result, int a2)
{
  if ( (uint16_t)result < 0x10u )
  {
    result = (uint16_t)result;
    dword_1ACF20[(uint16_t)result] = a2;
    byte_1ACF60[(uint16_t)result] = 1;
  }
  return result;
}
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (00103C23) --------------------------------------------------------
int __fastcall sub_103C23(int result, int a2)
{
  if ( (uint16_t)result < 0x10u )
  {
    result = (uint16_t)result;
    dword_1ACF20[(uint16_t)result] = a2;
    byte_1ACF60[(uint16_t)result] = 2;
  }
  return result;
}
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (00103C3F) --------------------------------------------------------
int __fastcall sub_103C3F(int result, int a2)
{
  if ( (uint16_t)result < 0x10u )
  {
    result = (uint16_t)result;
    dword_1ACF20[(uint16_t)result] = a2;
    byte_1ACF60[(uint16_t)result] = 3;
  }
  return result;
}
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (00103C5B) --------------------------------------------------------
int __fastcall sub_103C5B(int result, int a2)
{
  if ( (uint16_t)result < 0x10u )
  {
    result = (uint16_t)result;
    dword_1ACF20[(uint16_t)result] = a2;
    byte_1ACF60[(uint16_t)result] = 4;
  }
  return result;
}
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (00103C77) --------------------------------------------------------
int __fastcall sub_103C77(int result, int a2)
{
  if ( (uint16_t)result < 0x10u )
  {
    result = (uint16_t)result;
    dword_1ACF20[(uint16_t)result] = a2;
    byte_1ACF60[(uint16_t)result] = 5;
  }
  return result;
}
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (00103C93) --------------------------------------------------------
int __fastcall sub_103C93(int result, int a2)
{
  if ( (uint16_t)result < 0x10u )
  {
    result = (uint16_t)result;
    dword_1ACF20[(uint16_t)result] = a2;
    byte_1ACF60[(uint16_t)result] = 6;
  }
  return result;
}
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (00103CAF) --------------------------------------------------------
int __fastcall sub_103CAF( int a1, int a2)
{
  int v2; // eax

  v2 = sub_103D53(0, 0, a1, a2, 0, 0, 0);
  LOWORD(v2) = word_1ACF1E - word_1ACF1A;
  return v2 + 1;
}
// 1ACF1A: using guessed type int16_t word_1ACF1A;
// 1ACF1E: using guessed type int16_t word_1ACF1E;


//----- (00103CD6) --------------------------------------------------------
int __fastcall sub_103CD6( int a1, int a2, int a3)
{
  int v3; // eax

  v3 = sub_103D53(0, 0, a1, a2, a3, 0, 0);
  LOWORD(v3) = word_1ACF1C - word_1ACF18;
  return v3 + 1;
}
// 1ACF18: using guessed type int16_t word_1ACF18;
// 1ACF1C: using guessed type int16_t word_1ACF1C;


//----- (00103D0C) --------------------------------------------------------
int16_t sub_103D0C()
{
  return word_1ACF1C - word_1ACF18 + 1;
}
// 1ACF18: using guessed type int16_t word_1ACF18;
// 1ACF1C: using guessed type int16_t word_1ACF1C;


//----- (00103D53) --------------------------------------------------------
int __fastcall sub_103D53( unsigned int a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7)
{
  int result; // eax
  char v8; // dl
  uint8_t *v9; // eax
  char v10; // al
  _WORD *v11; // eax
  char v12; // al
  int16_t v13; // dx
  _BYTE v14[9052]; // [esp+0h] [ebp-28B4h] BYREF
  _BYTE v15[26]; // [esp+235Ch] [ebp-558h] BYREF
  _BYTE v16[13]; // [esp+2376h] [ebp-53Eh] BYREF
  char v17; // [esp+2383h] [ebp-531h] BYREF
  _BYTE v18[1202]; // [esp+23A6h] [ebp-50Eh] BYREF
  uint16_t v19; // [esp+2858h] [ebp-5Ch] BYREF
  int v20; // [esp+285Ah] [ebp-5Ah]
  uint16_t v21; // [esp+285Eh] [ebp-56h]
  int16_t v22; // [esp+2860h] [ebp-54h]
  uint16_t v23; // [esp+2862h] [ebp-52h]
  int16_t v24; // [esp+2864h] [ebp-50h]
  int16_t v25; // [esp+2866h] [ebp-4Eh]
  int v26; // [esp+2868h] [ebp-4Ch]
  char v27; // [esp+286Ch] [ebp-48h]
  int16_t v28; // [esp+2875h] [ebp-3Fh]
  int16_t v29; // [esp+2877h] [ebp-3Dh]
  int16_t v30; // [esp+2879h] [ebp-3Bh]
  int16_t v31; // [esp+287Bh] [ebp-39h]
  int16_t v32; // [esp+287Dh] [ebp-37h]
  char v33; // [esp+287Fh] [ebp-35h]
  char v34; // [esp+2880h] [ebp-34h]
  int16_t v35; // [esp+2881h] [ebp-33h]
  _BYTE *v36; // [esp+28A7h] [ebp-Dh]
  int16_t *v37; // [esp+28ABh] [ebp-9h]
  int16_t *v38; // [esp+28AFh] [ebp-5h]

  if ( a3 < 10 || a3 > 640 || a1 >= 0x280u || a2 >= 0x1E0u || !a4 )
    return a4;
  v24 = 479;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v34 = 1;
  v35 = 0;
  v37 = &word_1838F7;
  v38 = &word_1ACF18;
  v16[1] = 0;
  v19 = a2;
  v20 = a4;
  v21 = a1;
  v23 = a2;
  v25 = a3;
  dword_1ACF14 = (int)&v19;
  dword_1ACF08 = (int)v15;
  v22 = a3 + a1 - 1;
  dword_1ACF00 = (int)v16;
  v26 = a6;
  v27 = a7;
  dword_1ACEFC = (int)v18;
  v33 = a5;
  dword_1ACF04 = (int)v18;
  v36 = v15;
  v16[0] = BYTE2(dword_1B61E4);
  dword_1ACF0C = (int)&v17;
  v16[2] = word_1B3E86;
  v8 = sub_1067F0();
  v9 = (uint8_t *)dword_1ACF00;
  *(_BYTE *)(dword_1ACF00 + 4) = v8;
  *(_WORD *)(v9 + 5) = word_1B43A8[*v9];
  *(_WORD *)(dword_1ACF14 + 29) = *(_WORD *)(v9 + 5) + word_1B43C8[*v9];
  *(_WORD *)(dword_1ACF08 + 22) = word_1B43B8[*v9];
  *(_DWORD *)(v9 + 7) = &byte_1B43D8[256 * *v9];
  sub_1049DB();
  v29 = v28;
  *(_WORD *)(dword_1ACF14 + 25) = 480 - *(_WORD *)(dword_1ACF00 + 5);
  while ( 1 )
  {
    sub_106AF3();
    if ( v10 )
      break;
    v11 = (_WORD *)dword_1ACF14;
    ++*(_WORD *)dword_1ACF14;
    if ( *v11 > *(_WORD *)((char *)v11 + 25) )
    {
      v12 = 0;
      goto LABEL_12;
    }
  }
  v12 = 1;
LABEL_12:
  if ( !v12 )
    return 0;
  word_1ACF1C = 0;
  word_1ACF1E = 0;
  word_1ACF18 = *(_WORD *)(dword_1ACF14 + 6);
  v13 = HIWORD(dword_1B61E4);
  word_1ACF1A = *(_WORD *)(dword_1ACF14 + 10);
  qmemcpy(v14, byte_1B3E7C, sizeof(v14));
  sub_103F5D((int)byte_1B61D8);
  result = v20;
  HIWORD(dword_1B61E4) = v13;
  qmemcpy(byte_1B3E7C, v14, 0x235Cu);
  return result;
}
// 103ED0: variable 'v10' is possibly undefined
// 1838F7: using guessed type int16_t word_1838F7;
// 1ACEFC: using guessed type int dword_1ACEFC;
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF04: using guessed type int dword_1ACF04;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF0C: using guessed type int dword_1ACF0C;
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF18: using guessed type int16_t word_1ACF18;
// 1ACF1A: using guessed type int16_t word_1ACF1A;
// 1ACF1C: using guessed type int16_t word_1ACF1C;
// 1ACF1E: using guessed type int16_t word_1ACF1E;
// 1B3E86: using guessed type int16_t word_1B3E86;
// 1B43A8: using guessed type int16_t word_1B43A8[8];
// 1B43B8: using guessed type int16_t word_1B43B8[];
// 1B43C8: using guessed type int16_t word_1B43C8[8];
// 1B61E4: using guessed type int dword_1B61E4;


//----- (00103F5D) --------------------------------------------------------
int __usercall sub_103F5D(int a1)
{
  char v1; // cl
  int v2; // eax
  int v3; // edx
  char v4; // al
  int16_t v5; // bx
  int16_t v6; // bx
  _WORD *v7; // eax
  int16_t v8; // bx
  char v9; // al
  int16_t *v10; // eax
  int16_t v11; // bx
  int v12; // edx

  v1 = 0;
  dword_1ACF10 = dword_1ACEFC;
  do
  {
    v2 = dword_1ACF08;
    *(_BYTE *)(dword_1ACF08 + 24) = 0;
    *(_BYTE *)(v2 + 25) = 1;
    *(_WORD *)(v2 + 18) = 0;
    *(_WORD *)(v2 + 10) = *(_WORD *)v2;
    sub_104292(0);
    do
    {
      v3 = *(_DWORD *)(dword_1ACF14 + 2);
      LOBYTE(v3) = *(_BYTE *)v3;
      if ( (uint8_t)v3 < 0x20u )
        goto LABEL_30;
      if ( (IsTable[(uint8_t)(v3 + 1)] & 0xC0) != 0 && word_1ACF76 )
      {
        if ( word_1ACF76 == 1 || word_1ACF76 == 3 )
        {
          v4 = toupper((uint8_t)v3, v3);
        }
        else
        {
          if ( word_1ACF76 != 2 )
            goto LABEL_12;
          v4 = tolower((uint8_t)v3);
        }
        LOBYTE(v3) = v4;
      }
LABEL_12:
      if ( (_BYTE)v3 == 32 )
        v5 = *(_WORD *)(dword_1ACF00 + 11) + *(_WORD *)dword_1ACF08;
      else
        v5 = *(_WORD *)dword_1ACF08 + *(uint8_t *)((uint8_t)v3 + *(_DWORD *)(dword_1ACF00 + 7));
      v6 = v5 - 1;
      if ( *(int16_t *)(dword_1ACF08 + 12) < 150
        && (v6 <= *(int16_t *)(dword_1ACF08 + 4) || *(_BYTE *)(dword_1ACF08 + 25)) )
      {
        *(_WORD *)(dword_1ACF08 + 10) = v6;
        sub_104141(v3);
        v7 = (_WORD *)dword_1ACF08;
        LOWORD(a1) = *(_WORD *)dword_1ACF08;
        v8 = *(_WORD *)(dword_1ACF08 + 22) + v6;
        *(_BYTE *)(dword_1ACF08 + 25) = 0;
        v7[9] = a1;
        *v7 = v8 + 1;
        if ( word_1ACF76 == 3 && (IsTable[(uint8_t)(v3 + 1)] & 0xC0) != 0 )
          word_1ACF76 = 0;
      }
      else
      {
        if ( (_BYTE)v3 != 32 && (_BYTE)v3 != 9 )
        {
          sub_1041BB();
          if ( v9 && *(_BYTE *)(dword_1ACF0C + 20) )
            *(_BYTE *)(dword_1ACF10 + 7) = 45;
          --*(_DWORD *)(dword_1ACF14 + 2);
        }
        v10 = (int16_t *)dword_1ACF08;
        v11 = *(_WORD *)(dword_1ACF08 + 6);
        if ( v11 <= *(int16_t *)dword_1ACF08 )
        {
          LOBYTE(v3) = 13;
        }
        else
        {
          *(_WORD *)(dword_1ACF08 + 6) = 0;
          *v10 = v11;
          v10[5] = v11;
          v10[1] = v11;
          v10[2] = v10[4];
        }
      }
LABEL_30:
      if ( (uint8_t)v3 < 0x20u )
        v1 = sub_1043B0(v3, v3, v1, a1);
      v12 = dword_1ACF08;
      ++*(_DWORD *)(dword_1ACF14 + 2);
    }
    while ( !*(_BYTE *)(v12 + 24) && !v1 );
  }
  while ( !v1 );
  return sub_138CEE(word_1ACF18, word_1ACF1A, word_1ACF1C, word_1ACF1E);
}
// 10409F: variable 'v9' is possibly undefined
// 13E22A: using guessed type int __fastcall toupper(_DWORD, _DWORD);
// 13E238: using guessed type int __fastcall tolower(_DWORD);
// 1ACEFC: using guessed type int dword_1ACEFC;
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF0C: using guessed type int dword_1ACF0C;
// 1ACF10: using guessed type int dword_1ACF10;
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF18: using guessed type int16_t word_1ACF18;
// 1ACF1A: using guessed type int16_t word_1ACF1A;
// 1ACF1C: using guessed type int16_t word_1ACF1C;
// 1ACF1E: using guessed type int16_t word_1ACF1E;
// 1ACF76: using guessed type int16_t word_1ACF76;


//----- (00104141) --------------------------------------------------------
int __fastcall sub_104141( int a1)
{
  int v2; // eax
  _WORD *v3; // edx
  _BYTE *v4; // edx
  int result; // eax

  v2 = dword_1ACF10;
  v3 = (_WORD *)dword_1ACF14;
  *(_BYTE *)(dword_1ACF10 + 7) = a1;
  *(_WORD *)(v2 + 2) = *v3;
  v4 = (_BYTE *)dword_1ACF00;
  *(_WORD *)v2 = *(_WORD *)dword_1ACF08 - *(_WORD *)(dword_1ACF08 + 18);
  *(_BYTE *)(v2 + 5) = v4[4] | v4[2];
  *(_BYTE *)(v2 + 4) = *v4;
  *(_BYTE *)(v2 + 6) = v4[3];
  if ( v4[1] )
    *(_BYTE *)(v2 + 4) |= 0x80u;
  dword_1ACF10 += 8;
  if ( a1 == 32 )
  {
    sub_104292(32);
    ++*(_WORD *)(dword_1ACF08 + 14);
  }
  result = dword_1ACF08;
  ++*(_WORD *)(dword_1ACF08 + 12);
  return result;
}
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF10: using guessed type int dword_1ACF10;
// 1ACF14: using guessed type int dword_1ACF14;


//----- (001041BB) --------------------------------------------------------
void sub_1041BB()
{
  int v0; // eax
  int v1; // ebx
  int v2; // edx

  v0 = dword_1ACF0C;
  if ( *(_BYTE *)(dword_1ACF0C + 21) )
  {
    v1 = dword_1ACF14;
    *(_DWORD *)(dword_1ACF14 + 2) = *(_DWORD *)dword_1ACF0C;
    v2 = dword_1ACF08;
    *(_WORD *)dword_1ACF08 = *(_WORD *)(v0 + 4);
    *(_WORD *)(v2 + 10) = *(_WORD *)(v0 + 6);
    word_1ACF76 = *(_WORD *)(v0 + 8);
    *(_WORD *)(v1 + 41) = *(_WORD *)(v0 + 14);
    *(_WORD *)(v2 + 16) = *(_WORD *)(v0 + 10);
    *(_WORD *)(v2 + 22) = *(_WORD *)(v0 + 12);
    *(_WORD *)(v2 + 12) = *(_WORD *)(v0 + 16);
    *(_WORD *)(v2 + 14) = *(_WORD *)(v0 + 18);
    *(_DWORD *)(v2 + 26) = *(_DWORD *)(v0 + 22);
    *(_DWORD *)(v2 + 30) = *(_DWORD *)(v0 + 26);
    *(_DWORD *)(v2 + 34) = *(_DWORD *)(v0 + 30);
    *(_BYTE *)(v2 + 38) = *(_BYTE *)(v0 + 34);
    if ( *(_BYTE *)(v0 + 20) && dword_1ACEFC + 8 * *(int16_t *)(v2 + 12) - 8 == dword_1ACF10 )
    {
      sub_104141(45);
      dword_1ACF10 -= 8;
      --*(_WORD *)(dword_1ACF08 + 12);
    }
    else
    {
      dword_1ACF10 = dword_1ACEFC + 8 * *(int16_t *)(dword_1ACF08 + 12) - 8;
    }
  }
  JUMPOUT(0x104386);
}
// 104286: control flows out of bounds to 104386
// 1ACEFC: using guessed type int dword_1ACEFC;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF0C: using guessed type int dword_1ACF0C;
// 1ACF10: using guessed type int dword_1ACF10;
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF76: using guessed type int16_t word_1ACF76;


//----- (00104292) --------------------------------------------------------
int __fastcall sub_104292( int a1)
{
  int result; // eax
  int v3; // ebx
  int v4; // edx
  int16_t v5; // [esp+0h] [ebp-4h]

  result = dword_1ACF08;
  if ( !*(_BYTE *)(dword_1ACF08 + 25) && a1 )
  {
    *(_BYTE *)(dword_1ACF0C + 21) = 1;
    if ( a1 != 8
      || (v5 = *(uint8_t *)(*(_DWORD *)(dword_1ACF00 + 7) + 45) + *(_WORD *)result,
          v5 <= *(int16_t *)(result + 4)) )
    {
      v3 = dword_1ACF14;
      result = dword_1ACF0C;
      *(_DWORD *)dword_1ACF0C = *(_DWORD *)(dword_1ACF14 + 2) + 1;
      v4 = dword_1ACF08;
      *(_WORD *)(result + 4) = *(_WORD *)dword_1ACF08;
      *(_WORD *)(result + 6) = *(_WORD *)(v4 + 10);
      *(_WORD *)(result + 8) = word_1ACF76;
      *(_WORD *)(result + 10) = *(_WORD *)(v4 + 16);
      *(_WORD *)(result + 12) = *(_WORD *)(v4 + 22);
      *(_WORD *)(result + 14) = *(_WORD *)(v3 + 41);
      *(_WORD *)(result + 16) = *(_WORD *)(v4 + 12);
      *(_WORD *)(result + 18) = *(_WORD *)(v4 + 14);
      *(_DWORD *)(result + 22) = *(_DWORD *)(v4 + 26);
      *(_DWORD *)(result + 26) = *(_DWORD *)(v4 + 30);
      *(_DWORD *)(result + 30) = *(_DWORD *)(v4 + 34);
      *(_BYTE *)(result + 34) = *(_BYTE *)(v4 + 38);
      *(_BYTE *)(result + 20) = 0;
      if ( a1 == 8 )
      {
        *(_BYTE *)(result + 20) = 1;
        ++*(_WORD *)(result + 16);
        *(_WORD *)(result + 4) = v5;
        *(_WORD *)(result + 6) = v5;
      }
      else if ( a1 == 32 )
      {
        *(_WORD *)(result + 6) -= *(_WORD *)(v4 + 22) + *(uint8_t *)(*(_DWORD *)(dword_1ACF00 + 7) + 32);
      }
    }
  }
  else
  {
    result = dword_1ACF0C;
    *(_BYTE *)(dword_1ACF0C + 21) = 0;
  }
  return result;
}
// 104360: variable 'v5' is possibly undefined
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF0C: using guessed type int dword_1ACF0C;
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF76: using guessed type int16_t word_1ACF76;


//----- (001043B0) --------------------------------------------------------
char __usercall sub_1043B0( unsigned int a1, int a2, int a3, int a4)
{
  int v4; // eax
  _BYTE *v5; // edx
  _BYTE *v6; // edx
  _BOOL1 v7; // zf
  int v8; // eax
  char v9; // dh
  uint16_t i; // bx
  int16_t v11; // cx
  int v12; // eax
  _BYTE *v13; // edx
  int v14; // eax
  int v15; // eax
  char v16; // dh
  int16_t v17; // bx
  _WORD *v18; // eax
  char *v19; // edx
  char v20; // bl

  LOBYTE(a2) = 0;
  if ( a1 >= 0x17u )
  {
    switch ( a1 )
    {
      case 0x17u:
        sub_104DE7();
        goto LABEL_53;
      case 0x18u:
        sub_105089(a2, a3, a4);
        --*(_DWORD *)(dword_1ACF14 + 2);
        return a2;
      case 0x19u:
        sub_104C2C();
        return a2;
      case 0x1Au:
        v15 = dword_1ACF14;
        ++*(_DWORD *)(dword_1ACF14 + 2);
        v16 = **(_BYTE **)(v15 + 2) - 48;
        if ( *(int16_t *)(dword_1ACF08 + 12) > 0 )
        {
          v17 = *(_WORD *)(dword_1ACF08 + 4);
          *(_WORD *)(dword_1ACF08 + 4) = *(_WORD *)dword_1ACF08;
          sub_10478C();
          v18 = (_WORD *)dword_1ACF08;
          *(_WORD *)(dword_1ACF08 + 4) = v17;
          *(_WORD *)(dword_1ACF14 + 21) = *v18;
          sub_10683F();
          dword_1ACF10 = dword_1ACEFC;
          *(_BYTE *)(dword_1ACF08 + 24) = 0;
        }
        *(_BYTE *)(dword_1ACF14 + 39) = v16;
        return a2;
      case 0x1Bu:
        v14 = dword_1ACF14;
        ++*(_DWORD *)(dword_1ACF14 + 2);
        *(_BYTE *)(dword_1ACF00 + 4) = 32 * (**(_BYTE **)(v14 + 2) - 48);
        return a2;
      case 0x1Cu:
        sub_104BD7();
        return a2;
      case 0x1Du:
        sub_104A24();
        return a2;
      case 0x1Fu:
LABEL_53:
        v19 = *(char **)(dword_1ACF14 + 2);
        v20 = *v19;
        *(_DWORD *)(dword_1ACF14 + 2) = v19 + 1;
        if ( v20 == 76 )
        {
          if ( byte_1ACF74 )
            sub_105508();
          goto LABEL_58;
        }
        if ( v20 != 80 )
          goto LABEL_58;
        sub_1046CE();
        break;
      default:
        return a2;
    }
    goto LABEL_29;
  }
  if ( a1 < 9u )
  {
    if ( a1 < 7u )
    {
      if ( a1 )
        return a2;
      v8 = dword_1ACF14;
      word_1ACF76 = 0;
      if ( *(int16_t *)(dword_1ACF14 + 41) <= 0 )
      {
        v9 = 0;
      }
      else
      {
        --*(_WORD *)(dword_1ACF14 + 41);
        *(_DWORD *)(v8 + 2) = *(_DWORD *)(v8 + 4 * *(int16_t *)(v8 + 41) + 43);
        v9 = 1;
        --*(_DWORD *)(v8 + 2);
      }
      if ( v9 )
        return a2;
      sub_10478C();
    }
    else
    {
      if ( a1 > 7u )
      {
        sub_104292(8);
        return a2;
      }
      sub_105533();
      if ( **(_BYTE **)(dword_1ACF14 + 2) )
        return a2;
    }
LABEL_29:
    LOBYTE(a2) = 1;
    return a2;
  }
  if ( a1 > 9u )
  {
    if ( a1 < 0xBu )
    {
      *(_BYTE *)(dword_1ACF14 + 40) = 1;
    }
    else
    {
      if ( a1 <= 0xBu )
      {
LABEL_16:
        if ( sub_10494E(*(_WORD *)(dword_1ACF14 + 29)) )
          return a2;
        v4 = dword_1ACF14;
        if ( !*(_WORD *)(dword_1ACF14 + 41) )
          goto LABEL_20;
        v5 = *(_BYTE **)(dword_1ACF14 + 43);
        *(_WORD *)(dword_1ACF14 + 41) = 0;
        while ( 1 )
        {
          *(_DWORD *)(v4 + 2) = v5;
LABEL_20:
          v4 = dword_1ACF14;
          v6 = *(_BYTE **)(dword_1ACF14 + 2);
          v7 = *v6 == 0;
          if ( !*v6 )
            break;
          v5 = v6 + 1;
        }
        goto LABEL_22;
      }
      if ( a1 <= 0xCu )
      {
        sub_10478C();
        dword_1ACF10 = dword_1ACEFC;
        v12 = dword_1ACF14;
        *(_BYTE *)(dword_1ACF14 + 40) = 1;
        if ( sub_10494E(*(_WORD *)(v12 + 31)) )
          return a2;
        v4 = dword_1ACF14;
        if ( !*(_WORD *)(dword_1ACF14 + 41) )
          goto LABEL_41;
        v13 = *(_BYTE **)(dword_1ACF14 + 43);
        *(_WORD *)(dword_1ACF14 + 41) = 0;
        while ( 1 )
        {
          *(_DWORD *)(v4 + 2) = v13;
LABEL_41:
          v4 = dword_1ACF14;
          v6 = *(_BYTE **)(dword_1ACF14 + 2);
          v7 = *v6 == 0;
          if ( !*v6 )
            break;
          v13 = v6 + 1;
        }
LABEL_22:
        if ( v7 )
          *(_DWORD *)(v4 + 2) = v6 - 1;
LABEL_58:
        LOBYTE(a2) = 0;
        return a2;
      }
      if ( a1 != 13 )
        return a2;
    }
    sub_10478C();
    dword_1ACF10 = dword_1ACEFC;
    goto LABEL_16;
  }
  sub_104292(9);
  for ( i = 0; i < word_1838F7; ++i )
  {
    v11 = word_1838F9[i];
    if ( v11 > *(int16_t *)dword_1ACF08 )
    {
      *(_WORD *)dword_1ACF08 = v11;
      return a2;
    }
  }
  return a2;
}
// 1838F7: using guessed type int16_t word_1838F7;
// 1838F9: using guessed type int16_t word_1838F9[10];
// 1ACEFC: using guessed type int dword_1ACEFC;
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF10: using guessed type int dword_1ACF10;
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF74: using guessed type char byte_1ACF74;
// 1ACF76: using guessed type int16_t word_1ACF76;


//----- (0010465A) --------------------------------------------------------
char sub_10465A()
{
  int v0; // eax
  char *v1; // edx
  char v2; // bl
  _BYTE *v4; // edx
  _BYTE *v5; // edx

  v0 = dword_1ACF14;
  v1 = *(char **)(dword_1ACF14 + 2);
  v2 = *v1;
  *(_DWORD *)(dword_1ACF14 + 2) = v1 + 1;
  if ( v2 == 76 )
  {
    if ( byte_1ACF74 && *(int16_t *)(v0 + 41) > 0 )
    {
      *(_DWORD *)(v0 + 2) = *(_DWORD *)(v0 + 4 * (int16_t)--*(_WORD *)(v0 + 41) + 43);
      --*(_DWORD *)(v0 + 2);
      return 0;
    }
    return 0;
  }
  if ( v2 != 80 )
    return 0;
  if ( !*(_WORD *)(v0 + 41) )
    goto LABEL_9;
  v4 = *(_BYTE **)(v0 + 43);
  *(_WORD *)(v0 + 41) = 0;
  while ( 1 )
  {
    *(_DWORD *)(v0 + 2) = v4;
LABEL_9:
    v0 = dword_1ACF14;
    v5 = *(_BYTE **)(dword_1ACF14 + 2);
    if ( !*v5 )
      break;
    v4 = v5 + 1;
  }
  *(_DWORD *)(dword_1ACF14 + 2) = v5 - 1;
  return 1;
}
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF74: using guessed type char byte_1ACF74;


//----- (001046CE) --------------------------------------------------------
int sub_1046CE()
{
  int result; // eax
  _BYTE *v1; // edx
  _BYTE *v2; // edx

  result = dword_1ACF14;
  if ( !*(_WORD *)(dword_1ACF14 + 41) )
    goto LABEL_4;
  v1 = *(_BYTE **)(dword_1ACF14 + 43);
  *(_WORD *)(dword_1ACF14 + 41) = 0;
  while ( 1 )
  {
    *(_DWORD *)(result + 2) = v1;
LABEL_4:
    result = dword_1ACF14;
    v2 = *(_BYTE **)(dword_1ACF14 + 2);
    if ( !*v2 )
      break;
    v1 = v2 + 1;
  }
  *(_DWORD *)(dword_1ACF14 + 2) = v2 - 1;
  return result;
}
// 1ACF14: using guessed type int dword_1ACF14;


//----- (001046FF) --------------------------------------------------------
int sub_1046FF()
{
  int v0; // eax
  char v1; // cl
  int16_t v2; // dx
  int v3; // eax
  int v4; // edx
  int v5; // edx
  int result; // eax

  v0 = dword_1ACF14;
  ++*(_DWORD *)(dword_1ACF14 + 2);
  v1 = **(_BYTE **)(v0 + 2) - 48;
  if ( *(int16_t *)(dword_1ACF08 + 12) > 0 )
  {
    v2 = *(_WORD *)(dword_1ACF08 + 4);
    *(_WORD *)(dword_1ACF08 + 4) = *(_WORD *)dword_1ACF08;
    sub_10478C();
    v3 = dword_1ACF08;
    *(_WORD *)(dword_1ACF08 + 4) = v2;
    *(_WORD *)(dword_1ACF14 + 21) = *(_WORD *)v3;
    *(_WORD *)(v3 + 16) = 0;
    *(_WORD *)(v3 + 14) = 0;
    *(_WORD *)(v3 + 12) = 0;
    v4 = dword_1ACF0C;
    *(_WORD *)(v3 + 18) = 0;
    *(_WORD *)(v4 + 16) = 0;
    *(_WORD *)(v4 + 18) = 0;
    v5 = dword_1ACEFC;
    *(_BYTE *)(v3 + 24) = 0;
    dword_1ACF10 = v5;
  }
  result = dword_1ACF14;
  *(_BYTE *)(dword_1ACF14 + 39) = v1;
  return result;
}
// 1ACEFC: using guessed type int dword_1ACEFC;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF0C: using guessed type int dword_1ACF0C;
// 1ACF10: using guessed type int dword_1ACF10;
// 1ACF14: using guessed type int dword_1ACF14;


//----- (0010478C) --------------------------------------------------------
void sub_10478C()
{
  _BYTE *v0; // eax
  uint8_t v1; // al

  sub_1047D5();
  if ( *(_BYTE *)(dword_1ACF14 + 39) == 3
    && ((v0 = *(_BYTE **)(dword_1ACF14 + 2), *v0 == 13)
     || *v0 == 10
     || *v0 == 12
     || !*(_WORD *)(dword_1ACF14 + 41) && !*v0) )
  {
    v1 = 0;
  }
  else
  {
    v1 = *(_BYTE *)(dword_1ACF14 + 39);
  }
  sub_105FE9(v1);
  sub_106171();
}
// 1ACF14: using guessed type int dword_1ACF14;


//----- (001047D5) --------------------------------------------------------
int16_t *sub_1047D5()
{
  int16_t *result; // eax
  int v1; // eax
  int64_t v2; // rax

  result = (int16_t *)dword_1ACF08;
  *(_BYTE *)(dword_1ACF08 + 24) = 1;
  if ( result[6] <= 0 )
  {
    result[10] = 0;
  }
  else
  {
    if ( result[8] )
    {
      dword_1ACF04 = dword_1ACEFC + 8 * result[6];
      dword_1ACF10 = dword_1ACEFC;
      do
      {
        v1 = dword_1ACF10;
        *(_WORD *)(dword_1ACF10 + 2) += *(_WORD *)(dword_1ACF08 + 16);
        if ( *(int16_t *)(v1 + 2) < 0 )
          *(_WORD *)(v1 + 2) = 0;
        dword_1ACF10 += 8;
      }
      while ( dword_1ACF10 != dword_1ACF04 );
      *(_WORD *)dword_1ACF14 += *(_WORD *)(dword_1ACF08 + 16);
    }
    v2 = *(int16_t *)(dword_1ACF08 + 10) - *(int16_t *)(dword_1ACF08 + 2);
    WORD2(v2) = (WORD2(v2) ^ v2) - WORD2(v2);
    result = (int16_t *)dword_1ACF08;
    *(_WORD *)(dword_1ACF08 + 20) = WORD2(v2);
  }
  return result;
}
// 1ACEFC: using guessed type int dword_1ACEFC;
// 1ACF04: using guessed type int dword_1ACF04;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF10: using guessed type int dword_1ACF10;
// 1ACF14: using guessed type int dword_1ACF14;


//----- (0010487F) --------------------------------------------------------
int sub_10487F()
{
  uint16_t i; // dx
  int16_t v1; // bx
  int result; // eax

  for ( i = 0; ; ++i )
  {
    if ( i >= word_1838F7 )
      JUMPOUT(0x10487C);
    v1 = word_1838F9[i];
    result = dword_1ACF08;
    if ( v1 > *(int16_t *)dword_1ACF08 )
      break;
  }
  *(_WORD *)dword_1ACF08 = v1;
  return result;
}
// 10488F: control flows out of bounds to 10487C
// 1838F7: using guessed type int16_t word_1838F7;
// 1838F9: using guessed type int16_t word_1838F9[10];
// 1ACF08: using guessed type int dword_1ACF08;


//----- (001048AC) --------------------------------------------------------
char sub_1048AC()
{
  _WORD *v0; // eax
  int16_t v1; // dx
  int16_t v2; // bx
  char v3; // al

  v0 = (_WORD *)dword_1ACF14;
  v1 = *(_WORD *)dword_1ACF14;
  v2 = *(_WORD *)(dword_1ACF14 + 31);
  *(_BYTE *)(dword_1ACF14 + 40) = 1;
  *v0 = v2 + v1;
  while ( 1 )
  {
    sub_106AF3();
    if ( v3 || *(_WORD *)dword_1ACF14 > *(_WORD *)(dword_1ACF14 + 25) )
      break;
    ++*(_WORD *)dword_1ACF14;
  }
  if ( *(_WORD *)dword_1ACF14 <= *(_WORD *)(dword_1ACF14 + 25) )
    return 1;
  *(_WORD *)dword_1ACF14 = v1;
  return 0;
}
// 1048CD: variable 'v3' is possibly undefined
// 1ACF14: using guessed type int dword_1ACF14;


//----- (001048FF) --------------------------------------------------------
char sub_1048FF()
{
  int16_t v0; // dx
  char v1; // al

  v0 = *(_WORD *)dword_1ACF14;
  for ( *(_WORD *)dword_1ACF14 += *(_WORD *)(dword_1ACF14 + 29); ; ++*(_WORD *)dword_1ACF14 )
  {
    sub_106AF3();
    if ( v1 || *(_WORD *)dword_1ACF14 > *(_WORD *)(dword_1ACF14 + 25) )
      break;
  }
  if ( *(_WORD *)dword_1ACF14 <= *(_WORD *)(dword_1ACF14 + 25) )
    return 1;
  *(_WORD *)dword_1ACF14 = v0;
  return 0;
}
// 10491C: variable 'v1' is possibly undefined
// 1ACF14: using guessed type int dword_1ACF14;


//----- (0010494E) --------------------------------------------------------
char __fastcall sub_10494E( int a1)
{
  int16_t v1; // bx
  char v2; // al

  v1 = *(_WORD *)dword_1ACF14;
  for ( *(_WORD *)dword_1ACF14 += a1; ; ++*(_WORD *)dword_1ACF14 )
  {
    sub_106AF3();
    if ( v2 || *(_WORD *)dword_1ACF14 > *(_WORD *)(dword_1ACF14 + 25) )
      break;
  }
  if ( *(_WORD *)dword_1ACF14 <= *(_WORD *)(dword_1ACF14 + 25) )
    return 1;
  *(_WORD *)dword_1ACF14 = v1;
  return 0;
}
// 104969: variable 'v2' is possibly undefined
// 1ACF14: using guessed type int dword_1ACF14;


//----- (0010499B) --------------------------------------------------------
uint8_t *sub_10499B()
{
  uint8_t *result; // eax

  result = (uint8_t *)dword_1ACF00;
  *(_WORD *)(dword_1ACF08 + 22) = word_1B43B8[*(uint8_t *)dword_1ACF00];
  *(_DWORD *)(result + 7) = &byte_1B43D8[256 * *result];
  *(_WORD *)(result + 11) = (uint8_t)byte_1B43F8[256 * *result];
  return result;
}
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF08: using guessed type int dword_1ACF08;
// 1B43B8: using guessed type int16_t word_1B43B8[];


//----- (001049DB) --------------------------------------------------------
int sub_1049DB()
{
  int result; // eax

  result = dword_1ACF00;
  *(_WORD *)(dword_1ACF00 + 11) = (uint8_t)byte_1B43F8[256 * *(uint8_t *)dword_1ACF00];
  return result;
}
// 1ACF00: using guessed type int dword_1ACF00;


//----- (00104A24) --------------------------------------------------------
char sub_104A24()
{
  int v0; // eax
  char v1; // dl
  uint8_t *v2; // eax
  int16_t v3; // bx
  uint16_t i; // bx
  unsigned int v5; // eax
  int v6; // edx
  uint16_t v8; // [esp+0h] [ebp-4h] BYREF

  v0 = dword_1ACF14;
  ++*(_DWORD *)(dword_1ACF14 + 2);
  LOBYTE(v0) = **(_BYTE **)(v0 + 2) & 0xF;
  v1 = byte_183915[(uint8_t)v0];
  if ( (v1 & 1) != 0 )
  {
    v2 = (uint8_t *)dword_1ACF00;
    *(_WORD *)(dword_1ACF08 + 22) = word_1B43B8[*(uint8_t *)dword_1ACF00];
    *(_DWORD *)(v2 + 7) = &byte_1B43D8[256 * *v2];
    LOBYTE(v0) = sub_1049DB();
  }
  if ( (v1 & 2) != 0 )
  {
    LOBYTE(v0) = dword_1ACF00;
    *(_WORD *)(dword_1ACF00 + 11) = (uint8_t)byte_1B43F8[256 * *(uint8_t *)dword_1ACF00];
  }
  if ( (v1 & 4) != 0 )
  {
    v0 = dword_1ACF00;
    *(_WORD *)(dword_1ACF00 + 5) = word_1B43A8[*(uint8_t *)dword_1ACF00];
    v3 = *(_WORD *)(v0 + 5) + word_1B43C8[*(uint8_t *)v0];
    LOBYTE(v0) = dword_1ACF14;
    *(_WORD *)(dword_1ACF14 + 29) = v3;
  }
  if ( (v1 & 8) != 0 )
  {
    LOBYTE(v0) = dword_1ACF14;
    *(_WORD *)(dword_1ACF14 + 31) = *(_WORD *)(dword_1ACF14 + 29);
  }
  if ( (v1 & 0x10) != 0 )
  {
    for ( i = 0; i < 0x10u; ++i )
    {
      v5 = i;
      LOBYTE(v0) = sub_104B6B(v5);
    }
  }
  if ( (v1 & 0x20) != 0 )
  {
    LOBYTE(v0) = sub_10544B(&v8);
    if ( (_BYTE)v0 )
    {
      if ( v8 < 0x10u )
      {
        v6 = v8;
        v0 = 4 * v8;
        *(int *)((char *)dword_1ACF20 + v0) = (int)dword_1ACEBC + v0;
        *(int *)((char *)dword_1ACEBC + v0) = 0;
        byte_1ACF60[v6] = 2;
      }
    }
  }
  return v0;
}
// 1ACEBC: using guessed type int dword_1ACEBC[];
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF20: using guessed type int dword_1ACF20[16];
// 1B43A8: using guessed type int16_t word_1B43A8[8];
// 1B43B8: using guessed type int16_t word_1B43B8[];
// 1B43C8: using guessed type int16_t word_1B43C8[8];


//----- (00104B2F) --------------------------------------------------------
int sub_104B2F()
{
  uint16_t i; // dx
  int result; // eax

  for ( i = 0; i < 0x10u; ++i )
  {
    result = i;
    dword_1ACF20[result] = (int)&dword_1ACEBC[result];
    dword_1ACEBC[result] = 0;
    byte_1ACF60[i] = 2;
  }
  return result * 4;
}
// 104B38: conditional instruction was optimized away because dx.2<10u
// 1ACEBC: using guessed type int dword_1ACEBC[];
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (00104B6B) --------------------------------------------------------
unsigned int __fastcall sub_104B6B(unsigned int result)
{
  int v1; // edx

  if ( (uint16_t)result < 0x10u )
  {
    v1 = (uint16_t)result;
    result = 4 * (uint16_t)result;
    dword_1ACF20[result / 4] = (int)&dword_1ACEBC[result / 4];
    dword_1ACEBC[result / 4] = 0;
    byte_1ACF60[v1] = 2;
  }
  return result;
}
// 1ACEBC: using guessed type int dword_1ACEBC[];
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (00104BD7) --------------------------------------------------------
char sub_104BD7()
{
  int v0; // eax
  uint8_t v1; // dl
  uint16_t v2; // ax
  uint16_t v4; // [esp+0h] [ebp-4h] BYREF

  v0 = dword_1ACF14;
  ++*(_DWORD *)(dword_1ACF14 + 2);
  v1 = **(_BYTE **)(v0 + 2);
  if ( v1 == 54 )
  {
    LOBYTE(v2) = sub_10544B(&v4);
    if ( (_BYTE)v2 && v4 <= 7u )
    {
      LOBYTE(v2) = v4;
      *(_BYTE *)(dword_1ACF00 + 3) = v4;
    }
  }
  else
  {
    v2 = v1 - 48;
    v4 = v2;
    if ( v2 <= 5u )
    {
      LOBYTE(v2) = dword_1ACF00;
      *(_BYTE *)(dword_1ACF00 + 2) = v1;
    }
  }
  return v2;
}
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00104C2C) --------------------------------------------------------
char sub_104C2C()
{
  int v0; // ebx
  char *v1; // ecx
  char v2; // dl
  int v3; // eax
  int v4; // ebx
  char result; // al
  _BOOL1 v6; // zf
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  uint16_t v13; // [esp+0h] [ebp-20h] BYREF
  uint16_t v14; // [esp+4h] [ebp-1Ch] BYREF
  uint16_t v15; // [esp+8h] [ebp-18h] BYREF
  uint16_t v16; // [esp+Ch] [ebp-14h] BYREF
  uint16_t v17; // [esp+10h] [ebp-10h] BYREF
  uint16_t v18; // [esp+14h] [ebp-Ch] BYREF
  uint16_t v19; // [esp+18h] [ebp-8h] BYREF
  uint16_t v20; // [esp+1Ch] [ebp-4h] BYREF

  v0 = dword_1ACF14;
  ++*(_DWORD *)(dword_1ACF14 + 2);
  byte_1ACF74 = 0;
  v1 = *(char **)(v0 + 2);
  v2 = *v1;
  if ( sub_10544B(&v15) )
    v3 = sub_104F6A(v15);
  else
    v3 = 0;
  v4 = v3;
  result = v2;
  if ( (uint8_t)v2 >= 0x35u )
  {
    if ( (uint8_t)v2 <= 0x35u )
    {
      if ( sub_10544B(&v17) )
        v7 = sub_104F6A(v17);
      else
        v7 = 0;
      result = v4 == v7;
      goto LABEL_21;
    }
    if ( (uint8_t)v2 >= 0x38u )
    {
      if ( (uint8_t)v2 <= 0x38u )
      {
        if ( sub_10544B(&v19) )
          v10 = sub_104F6A(v19);
        else
          v10 = 0;
        result = v4 > v10;
      }
      else if ( (uint8_t)v2 <= 0x39u )
      {
        if ( sub_10544B(&v16) )
          v11 = sub_104F6A(v16);
        else
          v11 = 0;
        result = v4 <= v11;
      }
      else
      {
        if ( v2 != 65 )
          return result;
        if ( sub_10544B(&v18) )
          v12 = sub_104F6A(v18);
        else
          v12 = 0;
        result = v4 >= v12;
      }
LABEL_21:
      byte_1ACF74 = result;
      return result;
    }
    if ( (uint8_t)v2 > 0x36u )
    {
      if ( sub_10544B(&v20) )
        v9 = sub_104F6A(v20);
      else
        v9 = 0;
      result = v4 < v9;
      goto LABEL_21;
    }
    if ( sub_10544B(&v13) )
      v8 = sub_104F6A(v13);
    else
      v8 = 0;
    v6 = v4 == v8;
LABEL_20:
    result = !v6;
    goto LABEL_21;
  }
  if ( (uint8_t)v2 < 0x32u )
  {
    if ( (uint8_t)v2 < 0x30u )
      return result;
    if ( (uint8_t)v2 <= 0x30u )
    {
      v6 = v4 == 0;
      goto LABEL_20;
    }
    result = byte_1ACF75;
LABEL_51:
    byte_1ACF74 = result;
    *(_DWORD *)(dword_1ACF14 + 2) = v1;
    return result;
  }
  if ( (uint8_t)v2 <= 0x32u )
  {
    result = byte_1ACF74 == 0;
    goto LABEL_51;
  }
  if ( (uint8_t)v2 <= 0x33u )
  {
    *(_DWORD *)(dword_1ACF14 + 2) = v1;
    LOWORD(v4) = (uint8_t)byte_1ACF74;
  }
  result = sub_10544B(&v14);
  if ( result )
  {
    result = sub_104FEB(v4, v14);
    goto LABEL_21;
  }
  return result;
}
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF74: using guessed type char byte_1ACF74;
// 1ACF75: using guessed type char byte_1ACF75;


//----- (00104DE7) --------------------------------------------------------
int sub_104DE7()
{
  int result; // eax
  uint8_t v1; // dl
  int16_t v2; // cx

  result = dword_1ACF14;
  v1 = *(_BYTE *)(*(_DWORD *)(dword_1ACF14 + 2) + 1);
  v2 = *(_WORD *)dword_1ACF08 - *(_WORD *)(dword_1ACF14 + 6);
  if ( v1 < 0x69u )
  {
    if ( v1 < 0x4Cu )
    {
      if ( v1 == 73 )
        *(_WORD *)(dword_1ACF14 + 33) = v2 - *(_WORD *)(dword_1ACF14 + 37);
    }
    else if ( v1 <= 0x4Cu )
    {
      *(_WORD *)(dword_1ACF14 + 37) = v2;
    }
    else if ( v1 >= 0x52u )
    {
      if ( v1 <= 0x52u )
      {
        *(_WORD *)(dword_1ACF14 + 35) = *(_WORD *)(dword_1ACF14 + 14) - v2;
      }
      else if ( v1 == 84 && word_1838F7 < 10 )
      {
        result = word_1838F7;
        word_1838F9[word_1838F7++] = *(_WORD *)dword_1ACF08;
        if ( word_1838F7 > 1 )
          return qsort(word_1838F9, word_1838F7, 2, sub_1067BB);
      }
    }
  }
  else
  {
    if ( v1 <= 0x69u )
    {
      *(_WORD *)(dword_1ACF14 + 33) = 0;
      return result;
    }
    if ( v1 >= 0x6Du )
    {
      if ( v1 <= 0x6Du )
      {
        *(_WORD *)(dword_1ACF14 + 37) = 0;
      }
      else
      {
        if ( v1 < 0x72u )
          return result;
        if ( v1 > 0x72u )
        {
          if ( v1 == 116 )
            word_1838F7 = 0;
          return result;
        }
      }
      result = dword_1ACF14;
      *(_WORD *)(dword_1ACF14 + 35) = 0;
      return result;
    }
    if ( v1 == 108 )
      *(_WORD *)(dword_1ACF14 + 37) = 0;
  }
  return result;
}
// 133EF4: using guessed type int __fastcall qsort(_DWORD, _DWORD, _DWORD, _DWORD);
// 1838F7: using guessed type int16_t word_1838F7;
// 1838F9: using guessed type int16_t word_1838F9[10];
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00104F19) --------------------------------------------------------
int sub_104F19()
{
  uint16_t v1; // [esp+0h] [ebp-4h] BYREF

  if ( sub_10544B(&v1) )
    return sub_104F6A(v1);
  else
    return 0;
}


//----- (00104F6A) --------------------------------------------------------
int __fastcall sub_104F6A( unsigned int a1)
{
  int result; // eax

  result = 0;
  if ( a1 < 0x10u )
  {
    switch ( byte_1ACF60[a1] )
    {
      case 2:
        result = *(_DWORD *)dword_1ACF20[a1];
        break;
      case 3:
        result = *(uint16_t *)dword_1ACF20[a1];
        break;
      case 4:
        result = *(int16_t *)dword_1ACF20[a1];
        break;
      case 6:
        result = *(char *)dword_1ACF20[a1];
        break;
      default:
        result = *(uint8_t *)dword_1ACF20[a1];
        break;
    }
  }
  return result;
}
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (00104FEB) --------------------------------------------------------
char __fastcall sub_104FEB( unsigned int a1, int a2)
{
  char result; // al
  char v3; // bl
  int v4; // eax

  if ( a1 >= 0x10u )
    return 0;
  v3 = byte_1ACF60[a1] - 1;
  v4 = a1;
  switch ( v3 )
  {
    case 1:
      *(_DWORD *)dword_1ACF20[v4] = a2;
      result = 1;
      break;
    case 2:
    case 3:
      *(_WORD *)dword_1ACF20[v4] = a2;
      result = 1;
      break;
    case 4:
    case 5:
      *(_BYTE *)dword_1ACF20[v4] = a2;
      result = 1;
      break;
    default:
      return 0;
  }
  return result;
}
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (00105089) --------------------------------------------------------
void __usercall sub_105089(int a1, int a2, int a3)
{
  int v3; // eax
  uint8_t v4; // bl
  char v5; // al
  int v6; // eax
  int v7; // eax
  char *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ecx
  char *v11; // ecx
  int v12; // eax
  int v13; // eax
  _BOOL1 v14; // zf
  int v15; // eax
  char *v16; // edx
  _BOOL1 v17; // zf
  char v18; // dl
  uint16_t v19; // ax
  int v20; // [esp+0h] [ebp-1Ch]
  int v21; // [esp+4h] [ebp-18h]
  uint16_t v22; // [esp+8h] [ebp-14h] BYREF
  uint16_t v23; // [esp+Ch] [ebp-10h] BYREF
  uint16_t v24; // [esp+10h] [ebp-Ch] BYREF
  int v25; // [esp+14h] [ebp-8h] BYREF
  uint16_t v26; // [esp+18h] [ebp-4h] BYREF

  v3 = dword_1ACF14;
  ++*(_DWORD *)(dword_1ACF14 + 2);
  v4 = **(_BYTE **)(v3 + 2);
  if ( aFirst[v4] == 48 )
    v5 = 1;
  else
    v5 = sub_10544B((uint16_t *)&v25);
  if ( v5 )
  {
    switch ( v4 )
    {
      case 'A':
        if ( (uint16_t)v25 < 0x10u )
          v20 = dword_1ACF20[(uint16_t)v25];
        v6 = v20;
        goto LABEL_9;
      case 'B':
        v7 = sub_104F6A(v25);
        byte_1ACF75 = v7 != 1;
        itoa(v7, byte_1ACF98, 10, a2);
        ++*(_DWORD *)(dword_1ACF14 + 2);
        v8 = byte_1ACF98;
        goto LABEL_24;
      case 'C':
        v12 = sub_104F6A(v25);
        byte_1ACF75 = v12 != 1;
        v10 = v12;
        goto LABEL_15;
      case 'D':
        v9 = sub_104F6A(v25);
        byte_1ACF75 = v9 != 1;
        v10 = v9;
        if ( v9 > 0xA )
        {
LABEL_15:
          itoa(v10, byte_1ACF98, 10, v10);
          v13 = (uint8_t)byte_1ACF97[strlen(byte_1ACF98)];
          v25 = v13 - 48;
          sprintf(&unk_1ACF78, "%s\a^2.%s\a^0.", byte_1ACF98, off_183871[(uint16_t)(v13 - 48)]);
          ++*(_DWORD *)(dword_1ACF14 + 2);
          v8 = (char *)&unk_1ACF78;
        }
        else
        {
          v11 = off_183899[v9];
          ++*(_DWORD *)(dword_1ACF14 + 2);
          v8 = v11;
        }
        goto LABEL_24;
      case 'E':
        v14 = byte_1ACF75 == 0;
        goto LABEL_17;
      case 'F':
        v14 = sub_104F6A(v25) == 1;
LABEL_17:
        if ( v14 )
          break;
        v15 = dword_1ACF14;
        v16 = (char *)&unk_18386C;
        goto LABEL_23;
      case 'G':
        v17 = byte_1ACF75 == 0;
        goto LABEL_21;
      case 'H':
        v17 = sub_104F6A(v25) == 1;
LABEL_21:
        if ( v17 )
          break;
        v15 = dword_1ACF14;
        v16 = (char *)&unk_18386E;
LABEL_23:
        ++*(_DWORD *)(v15 + 2);
        v8 = v16;
LABEL_24:
        sub_1054E1((int)v8);
        break;
      case 'I':
        if ( !byte_1ACF75 )
          goto LABEL_10;
        if ( (uint16_t)v25 < 0x10u )
          a3 = dword_1ACF20[(uint16_t)v25];
        v6 = a3;
        goto LABEL_9;
      case 'J':
        v18 = sub_104F6A(v25) != 1;
        if ( !sub_10544B(&v26) )
          break;
        v19 = v26;
        goto LABEL_32;
      case 'K':
        if ( byte_1ACF75 )
          goto LABEL_10;
        if ( (uint16_t)v25 < 0x10u )
          v21 = dword_1ACF20[(uint16_t)v25];
        v6 = v21;
        goto LABEL_9;
      case 'L':
        v18 = sub_104F6A(v25) == 1;
        if ( !sub_10544B(&v23) )
          break;
        v19 = v23;
        goto LABEL_32;
      case 'M':
        if ( !byte_1ACF74 )
          goto LABEL_10;
        if ( (uint16_t)v25 < 0x10u )
          a1 = dword_1ACF20[(uint16_t)v25];
        v6 = a1;
        goto LABEL_9;
      case 'N':
        v18 = sub_104F6A(v25) != 0;
        if ( !sub_10544B(&v24) )
          break;
        v19 = v24;
        goto LABEL_32;
      case 'O':
        if ( byte_1ACF74 )
        {
LABEL_10:
          ++*(_DWORD *)(dword_1ACF14 + 2);
        }
        else
        {
          if ( (uint16_t)v25 < 0x10u )
            a2 = dword_1ACF20[(uint16_t)v25];
          v6 = a2;
LABEL_9:
          sub_1054B7(v6);
        }
        break;
      case 'P':
        v18 = sub_104F6A(v25) == 0;
        if ( !sub_10544B(&v22) )
          break;
        v19 = v22;
LABEL_32:
        sub_10541B(v19, v18, v4);
        break;
      case 'Q':
        word_1ACF76 = 1;
        break;
      case 'R':
        word_1ACF76 = 2;
        break;
      case 'S':
        word_1ACF76 = 3;
        break;
      case 'T':
        word_1ACF76 = 0;
        break;
      default:
        break;
    }
  }
  JUMPOUT(0x104385);
}
// 1050D5: control flows out of bounds to 104385
// 1050F9: variable 'v20' is possibly undefined
// 1052D5: variable 'v21' is possibly undefined
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 183871: using guessed type char *off_183871[21];
// 183899: using guessed type char *off_183899[11];
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF20: using guessed type int dword_1ACF20[16];
// 1ACF74: using guessed type char byte_1ACF74;
// 1ACF75: using guessed type char byte_1ACF75;
// 1ACF76: using guessed type int16_t word_1ACF76;


//----- (001053DA) --------------------------------------------------------
char __fastcall sub_1053DA( int a1, int a2)
{
  char result; // al
  uint16_t v4; // [esp+0h] [ebp-4h] BYREF

  result = sub_10544B(&v4);
  if ( result )
  {
    if ( a1 )
    {
      if ( v4 < 0x10u )
        a2 = dword_1ACF20[v4];
      return sub_1054B7(a2);
    }
    else
    {
      result = dword_1ACF14;
      ++*(_DWORD *)(dword_1ACF14 + 2);
    }
  }
  return result;
}
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (0010541B) --------------------------------------------------------
int __fastcall sub_10541B( unsigned int a1, int a2, int a3)
{
  int result; // eax

  if ( a2 )
  {
    if ( a1 < 0x10u )
      a3 = dword_1ACF20[a1];
    ++*(_DWORD *)(dword_1ACF14 + 2);
    return sub_1054E1(a3);
  }
  else
  {
    result = dword_1ACF14;
    ++*(_DWORD *)(dword_1ACF14 + 2);
  }
  return result;
}
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF20: using guessed type int dword_1ACF20[16];


//----- (0010544B) --------------------------------------------------------
char __fastcall sub_10544B(uint16_t *a1)
{
  int v2; // eax
  uint8_t *v3; // eax
  uint8_t *v4; // ebx
  uint8_t v5; // al
  uint16_t v6; // ax

  v2 = dword_1ACF14;
  ++*(_DWORD *)(dword_1ACF14 + 2);
  v3 = *(uint8_t **)(v2 + 2);
  v4 = v3;
  while ( *v3 == 32 )
    ++v3;
  if ( *v3 )
    v4 = v3;
  *(_DWORD *)(dword_1ACF14 + 2) = v4;
  v5 = toupper(*v4, a1);
  if ( v5 < 0x30u || v5 > 0x39u )
  {
    if ( v5 < 0x41u || v5 > 0x5Au )
      return 0;
    v6 = v5 - 55;
  }
  else
  {
    v6 = v5 - 48;
  }
  if ( v6 < 0x10u )
  {
    *a1 = v6;
    return 1;
  }
  return 0;
}
// 13E22A: using guessed type int __fastcall toupper(_DWORD, _DWORD);
// 1ACF14: using guessed type int dword_1ACF14;


//----- (001054B7) --------------------------------------------------------
int __fastcall sub_1054B7(int a1)
{
  int result; // eax

  result = dword_1ACF14;
  ++*(_DWORD *)(dword_1ACF14 + 2);
  if ( *(int16_t *)(result + 41) < 10 )
  {
    *(_DWORD *)(result + 4 * *(int16_t *)(result + 41) + 43) = *(_DWORD *)(result + 2);
    *(_DWORD *)(result + 2) = a1;
    ++*(_WORD *)(result + 41);
  }
  return result;
}
// 1ACF14: using guessed type int dword_1ACF14;


//----- (001054E1) --------------------------------------------------------
int __fastcall sub_1054E1(int a1)
{
  int result; // eax

  result = dword_1ACF14;
  if ( *(int16_t *)(dword_1ACF14 + 41) < 10 )
  {
    *(_DWORD *)(dword_1ACF14 + 4 * *(int16_t *)(dword_1ACF14 + 41) + 43) = *(_DWORD *)(dword_1ACF14 + 2);
    *(_DWORD *)(result + 2) = a1;
    ++*(_WORD *)(result + 41);
  }
  return result;
}
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00105508) --------------------------------------------------------
char sub_105508()
{
  int v0; // eax

  v0 = dword_1ACF14;
  if ( *(int16_t *)(dword_1ACF14 + 41) <= 0 )
    return 0;
  --*(_WORD *)(dword_1ACF14 + 41);
  *(_DWORD *)(v0 + 2) = *(_DWORD *)(v0 + 4 * *(int16_t *)(v0 + 41) + 43);
  --*(_DWORD *)(v0 + 2);
  return 1;
}
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00105533) --------------------------------------------------------
void sub_105533()
{
  _BYTE *v0; // edx
  _BYTE *v1; // edx
  char *v2; // esi
  uint8_t v3; // cl
  uint8_t v4; // bl
  char v5; // al
  _BYTE *v6; // eax
  uint16_t v7; // si
  uint8_t v8; // al
  _BOOL1 v9; // zf
  char v10; // al
  int v11; // edx
  int v12; // edx
  uint8_t v13; // dh
  unsigned int v14; // eax
  unsigned int v15; // edx
  int v16; // ecx
  int v17; // ecx
  unsigned int v18; // edx
  int v19; // ebx
  _BYTE *v20; // eax
  int v21; // eax
  unsigned int v22; // [esp+0h] [ebp-Ch] BYREF
  char v23[4]; // [esp+4h] [ebp-8h] BYREF
  char v24; // [esp+8h] [ebp-4h]

  v0 = *(_BYTE **)(dword_1ACF14 + 2);
  if ( *v0 == 7 )
    *(_DWORD *)(dword_1ACF14 + 2) = v0 + 1;
  v1 = (_BYTE *)(uint16_t)(480 - *(_WORD *)(dword_1ACF00 + 5));
  *(_WORD *)(dword_1ACF14 + 12) = (_WORD)v1;
LABEL_4:
  v2 = aFrtxyshvpimoc;
  v3 = toupper(**(uint8_t **)(dword_1ACF14 + 2), v1);
  v4 = v3;
  do
  {
    v5 = *v2;
    if ( *v2 == v3 )
      goto LABEL_8;
    ++v2;
  }
  while ( v5 );
  v2 = 0;
LABEL_8:
  if ( !v2 )
  {
    while ( 1 )
    {
      v6 = *(_BYTE **)(dword_1ACF14 + 2);
      if ( *v6 == 7 || *v6 == 46 || !*v6 )
        break;
      *(_DWORD *)(dword_1ACF14 + 2) = v6 + 1;
    }
    if ( v24 )
    {
      if ( word_1838F7 > 1 )
        qsort(word_1838F9, word_1838F7, 2, sub_1067BB);
    }
    JUMPOUT(0x104385);
  }
  if ( v3 == 84 )
    word_1838F7 = 0;
  v24 = 0;
  v7 = 0;
  while ( 1 )
  {
    ++*(_DWORD *)(dword_1ACF14 + 2);
    ++v7;
    v8 = sub_10599E((int *)&v22, v23);
    if ( v4 < 0x50u )
    {
      if ( v4 >= 0x48u )
      {
        if ( v4 <= 0x48u )
        {
          v13 = v8;
          v14 = v22;
          if ( !v13 )
          {
            if ( v23[0] )
              v14 = *(int16_t *)(dword_1ACF08 + 22) + v22;
            if ( v14 < 0x40 )
              *(_WORD *)(dword_1ACF08 + 22) = v14;
          }
          v4 = 83;
          goto LABEL_94;
        }
        if ( v4 < 0x4Du )
        {
          if ( v4 == 73 )
          {
            v18 = v22;
            if ( v23[0] )
              v18 = *(int16_t *)(dword_1ACF14 + 33) + v22;
            v19 = v18 + *(int16_t *)(dword_1ACF14 + 37);
            if ( *(int16_t *)(dword_1ACF14 + 14) > v19 + *(int16_t *)(dword_1ACF14 + 35) )
            {
              if ( v19 < 0 )
                LOWORD(v18) = *(_WORD *)(dword_1ACF14 + 37);
              *(_WORD *)(dword_1ACF14 + 33) = v18;
            }
            sub_106AF3();
            goto LABEL_68;
          }
        }
        else
        {
          if ( v4 <= 0x4Du )
          {
            v4 = sub_105DEF(v4, v22, v7, v8, v23[0]);
            sub_106AF3();
            goto LABEL_94;
          }
          if ( v4 == 79 )
          {
            sub_105EDC(79, v22, v7, v8, v23[0]);
            goto LABEL_93;
          }
        }
        goto LABEL_94;
      }
      if ( v4 < 0x43u )
      {
        if ( v4 == 61 )
        {
          v10 = sub_105BA0(61, v22, v7, v8, v23[0]);
          goto LABEL_93;
        }
        goto LABEL_94;
      }
      if ( v4 <= 0x43u )
      {
        v10 = sub_105F89(v4, v22, v7, v8, (uint8_t)v23[0]);
        goto LABEL_93;
      }
      v9 = v4 == 70;
    }
    else
    {
      if ( v4 <= 0x50u )
      {
        v17 = v22;
        if ( v8 )
        {
          *(_WORD *)(dword_1ACF14 + 31) = *(_WORD *)(dword_1ACF14 + 29);
        }
        else
        {
          if ( v23[0] )
            v17 = v22 + *(int16_t *)(dword_1ACF14 + 31);
          if ( (int)abs32(v17) < 64 )
            *(_WORD *)(dword_1ACF14 + 31) = v17;
        }
        goto LABEL_68;
      }
      if ( v4 >= 0x56u )
      {
        if ( v4 <= 0x56u )
        {
          v16 = v22;
          if ( !v8 )
          {
            if ( v23[0] )
              v16 = v22 + *(int16_t *)(dword_1ACF14 + 29);
            if ( (int)abs32(v16) < 64 )
              *(_WORD *)(dword_1ACF14 + 29) = v16;
          }
          v4 = 80;
          goto LABEL_94;
        }
        if ( v4 < 0x59u )
        {
          if ( v4 == 88 )
          {
            if ( v23[0] )
              v11 = *(int16_t *)dword_1ACF08;
            else
              v11 = *(int16_t *)(dword_1ACF14 + 6);
            v12 = v22 + v11;
            if ( v12 >= *(int16_t *)(dword_1ACF14 + 6) && v12 <= *(int16_t *)(dword_1ACF14 + 8) )
              *(_WORD *)dword_1ACF08 = v12;
            v4 = 89;
          }
          goto LABEL_94;
        }
        if ( v4 <= 0x59u )
        {
          v10 = sub_105CA4(v4, v22, v7, v8, v23[0]);
          goto LABEL_93;
        }
        if ( v4 == 94 )
        {
          v10 = sub_105B24(94, v22, v7, v8, (uint8_t)v23[0]);
          goto LABEL_93;
        }
        goto LABEL_94;
      }
      if ( v4 >= 0x53u )
      {
        if ( v4 <= 0x53u )
        {
          v15 = v22;
          if ( v8 )
          {
            *(_WORD *)(dword_1ACF00 + 11) = *(_WORD *)(dword_1ACF08 + 22);
          }
          else
          {
            if ( v23[0] )
              v15 = v22 + *(int16_t *)(dword_1ACF00 + 11);
            if ( v15 < 0x40 )
              *(_WORD *)(dword_1ACF00 + 11) = v15;
          }
LABEL_68:
          v4 = 0;
          goto LABEL_94;
        }
        if ( v4 == 84 )
        {
          v24 = 1;
          v10 = sub_105BFB(84, v22, v7, v8, v23[0]);
          goto LABEL_93;
        }
        goto LABEL_94;
      }
      v9 = v4 == 82;
    }
    if ( v9 )
    {
      v10 = sub_105A2C(v4, v22, v7, v8, v23[0]);
LABEL_93:
      v4 = v10;
    }
LABEL_94:
    v20 = *(_BYTE **)(dword_1ACF14 + 2);
    v1 = v20;
    while ( *v20 == 32 )
      ++v20;
    if ( *v20 )
      v1 = v20;
    v21 = dword_1ACF14;
    *(_DWORD *)(dword_1ACF14 + 2) = v1;
    if ( *v1 != 44 )
    {
      if ( v4 == 79 )
      {
        v1 = (_BYTE *)((int __fastcall(*)())(void*)sub_103D53)(*(_BYTE *)(v21 + 39), *(_DWORD *)(v21 + 16), *(_BYTE *)(v21 + 20));
        *(_DWORD *)(dword_1ACF14 + 2) = v1;
      }
      goto LABEL_4;
    }
  }
}
// 105999: control flows out of bounds to 104385
// 1058FD: variable 'v10' is possibly undefined
// 103D53: using guessed type _DWORD __stdcall sub_103D53(char, _DWORD, char);
// 133EF4: using guessed type int __fastcall qsort(_DWORD, _DWORD, _DWORD, _DWORD);
// 13E22A: using guessed type int __fastcall toupper(_DWORD, _DWORD);
// 1838F7: using guessed type int16_t word_1838F7;
// 1838F9: using guessed type int16_t word_1838F9[10];
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF14: using guessed type int dword_1ACF14;


//----- (0010599E) --------------------------------------------------------
char __fastcall sub_10599E(int *a1, _BYTE *a2)
{
  _BYTE *v3; // eax
  char v4; // cl
  _BYTE *v5; // esi
  char *v6; // esi
  char v7; // al

  v3 = *(_BYTE **)(dword_1ACF14 + 2);
  v4 = 1;
  v5 = v3;
  while ( *v3 == 32 )
    ++v3;
  if ( *v3 )
    v5 = v3;
  *(_DWORD *)(dword_1ACF14 + 2) = v5;
  *a2 = *v5 == 43 || *v5 == 45;
  *a1 = sub_12760B(*(char **)(dword_1ACF14 + 2));
  while ( 1 )
  {
    v6 = a1234567890;
    while ( 1 )
    {
      v7 = *v6;
      if ( *v6 == **(_BYTE **)(dword_1ACF14 + 2) )
        break;
      ++v6;
      if ( !v7 )
      {
        v6 = 0;
        break;
      }
    }
    if ( !v6 )
      return v4;
    if ( **(_BYTE **)(dword_1ACF14 + 2) != 32 )
      v4 = 0;
    ++*(_DWORD *)(dword_1ACF14 + 2);
  }
}
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00105A2C) --------------------------------------------------------
char __fastcall sub_105A2C( int a1, unsigned int a2, int a3, int a4, int a5)
{
  uint8_t *v5; // eax
  int16_t v6; // cx
  int v7; // ebx
  uint8_t *v8; // eax
  int v9; // edx
  int v10; // edx
  _WORD *v11; // eax
  int v12; // ebx

  if ( a5 )
    a2 += *(uint8_t *)dword_1ACF00;
  if ( a2 <= 5 )
  {
    v5 = (uint8_t *)dword_1ACF00;
    v6 = (uint8_t)byte_18390D[*(uint8_t *)dword_1ACF00];
    *(_BYTE *)dword_1ACF00 = a2;
    v7 = *v5;
    v5[1] = a1 != 70;
    *(_WORD *)(dword_1ACF08 + 22) = word_1B43B8[v7];
    *(_DWORD *)(v5 + 7) = &byte_1B43D8[256 * *v5];
    sub_1049DB();
    v8 = (uint8_t *)dword_1ACF00;
    *(_WORD *)(dword_1ACF00 + 5) = word_1B43A8[*(uint8_t *)dword_1ACF00];
    v9 = dword_1ACF14;
    *(_WORD *)(dword_1ACF14 + 29) = *(_WORD *)(v8 + 5) + word_1B43C8[*v8];
    *(_WORD *)(v9 + 25) = 480 - *(_WORD *)(v8 + 5);
    v10 = (uint8_t)byte_18390D[*v8] - v6;
    if ( *(int16_t *)(dword_1ACF08 + 16) < v10 )
      *(_WORD *)(dword_1ACF08 + 16) = v10;
    v11 = (_WORD *)dword_1ACF14;
    v12 = *(int16_t *)dword_1ACF14 - v10;
    if ( v12 < 0 )
    {
      *(_WORD *)(dword_1ACF08 + 16) = *(_WORD *)dword_1ACF14;
      *v11 = 0;
    }
    else
    {
      *(_WORD *)dword_1ACF14 = v12;
    }
  }
  return 0;
}
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF14: using guessed type int dword_1ACF14;
// 1B43A8: using guessed type int16_t word_1B43A8[8];
// 1B43B8: using guessed type int16_t word_1B43B8[];
// 1B43C8: using guessed type int16_t word_1B43C8[8];


//----- (00105B24) --------------------------------------------------------
char __fastcall sub_105B24(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // edi
  int v6; // ebx
  uint8_t *v7; // eax

  if ( a2 )
  {
    unk_1ACFA8 = *(_DWORD *)dword_1ACF00;
    unk_1ACFAC = *(_DWORD *)(dword_1ACF00 + 4);
    unk_1ACFB0 = *(_DWORD *)(dword_1ACF00 + 8);
    unk_1ACFB4 = *(_BYTE *)(dword_1ACF00 + 12);
    v6 = *(uint8_t *)dword_1ACF00 - a2;
    if ( v6 >= 0 )
    {
      if ( v6 >= 6 )
        *(_BYTE *)dword_1ACF00 = 5;
      else
        *(_BYTE *)dword_1ACF00 = v6;
    }
    else
    {
      *(_BYTE *)dword_1ACF00 = 0;
    }
    v7 = (uint8_t *)dword_1ACF00;
    *(_WORD *)(dword_1ACF08 + 22) = word_1B43B8[*(uint8_t *)dword_1ACF00];
    *(_DWORD *)(v7 + 7) = &byte_1B43D8[256 * *v7];
    sub_1049DB();
  }
  else
  {
    v5 = dword_1ACF00;
    *(_DWORD *)dword_1ACF00 = unk_1ACFA8;
    v5 += 4;
    *(_DWORD *)v5 = unk_1ACFAC;
    v5 += 4;
    *(_DWORD *)v5 = unk_1ACFB0;
    *(_BYTE *)(v5 + 4) = unk_1ACFB4;
  }
  return 0;
}
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF08: using guessed type int dword_1ACF08;
// 1B43B8: using guessed type int16_t word_1B43B8[];


//----- (00105BA0) --------------------------------------------------------
char __fastcall sub_105BA0(int a1, int a2, int a3, int a4, int a5)
{
  char result; // al

  if ( a3 == 1 )
  {
    if ( !a4 )
      word_1ACFB5 = abs32(a2);
  }
  else
  {
    if ( a3 == 2 && (uint16_t)word_1ACFB5 < 0x10u )
    {
      if ( a5 )
        a2 += sub_104F6A(word_1ACFB5);
      sub_104FEB(word_1ACFB5, a2);
    }
    return 0;
  }
  return result;
}
// 1ACFB5: using guessed type int16_t word_1ACFB5;


//----- (00105BFB) --------------------------------------------------------
char __fastcall sub_105BFB( int a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v6; // edx

  if ( word_1838F7 >= 10 )
    return 0;
  if ( a5 )
    v5 = *(int16_t *)dword_1ACF08;
  else
    v5 = *(int16_t *)(dword_1ACF14 + 6);
  v6 = v5 + a2;
  if ( v6 >= *(int16_t *)(dword_1ACF14 + 6) && v6 <= *(int16_t *)(dword_1ACF14 + 8) && !a4 )
    word_1838F9[word_1838F7++] = v6;
  return a1;
}
// 1838F7: using guessed type int16_t word_1838F7;
// 1838F9: using guessed type int16_t word_1838F9[10];
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00105CA4) --------------------------------------------------------
char __fastcall sub_105CA4(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v6; // edx
  int v7; // ebx
  int v8; // edx

  if ( a5 )
    v5 = *(int16_t *)dword_1ACF14;
  else
    v5 = *(int16_t *)(dword_1ACF14 + 10);
  v6 = v5 + a2;
  if ( v6 <= *(int16_t *)(dword_1ACF14 + 12) )
  {
    if ( v6 < 0 )
      LOWORD(v6) = 0;
  }
  else
  {
    LOWORD(v6) = *(_WORD *)(dword_1ACF14 + 12);
  }
  v7 = *(int16_t *)(dword_1ACF14 + 10);
  *(_WORD *)dword_1ACF14 = v6;
  v8 = v7 - (int16_t)v6;
  if ( v8 > 0 && v8 > *(int16_t *)(dword_1ACF08 + 16) )
    *(_WORD *)(dword_1ACF08 + 16) = v8;
  return 0;
}
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00105D74) --------------------------------------------------------
char __fastcall sub_105D74(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // esi

  v5 = a2;
  if ( !a4 )
  {
    if ( a5 )
      v5 = a2 + *(int16_t *)(dword_1ACF14 + 29);
    if ( (int)abs32(v5) < 64 )
      *(_WORD *)(dword_1ACF14 + 29) = v5;
  }
  return 80;
}
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00105DAC) --------------------------------------------------------
char __fastcall sub_105DAC(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // esi
  int v6; // eax

  v5 = a2;
  if ( a4 )
  {
    v6 = dword_1ACF14;
    LOWORD(v5) = *(_WORD *)(dword_1ACF14 + 29);
LABEL_7:
    *(_WORD *)(v6 + 31) = v5;
    return 0;
  }
  if ( a5 )
    v5 = a2 + *(int16_t *)(dword_1ACF14 + 31);
  if ( (int)abs32(v5) < 64 )
  {
    v6 = dword_1ACF14;
    goto LABEL_7;
  }
  return 0;
}
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00105DEF) --------------------------------------------------------
char __fastcall sub_105DEF(int a1, int a2, int a3, int a4, int a5)
{
  char result; // al

  if ( !a4 )
  {
    if ( a3 == 1 )
    {
      if ( a5 )
        a2 += *(int16_t *)(dword_1ACF14 + 37);
      if ( a2 < *(int16_t *)(dword_1ACF14 + 14) )
      {
        *(_WORD *)(dword_1ACF14 + 37) = a2 < 0 ? 0 : a2;
        if ( *(int16_t *)(dword_1ACF14 + 6) + *(int16_t *)(dword_1ACF14 + 37) >= *(int16_t *)(dword_1ACF14 + 8)
                                                                               + *(int16_t *)(dword_1ACF14 + 35) )
          *(_WORD *)(dword_1ACF14 + 35) = 0;
      }
    }
    else
    {
      if ( a5 )
        a2 += *(int16_t *)(dword_1ACF14 + 35);
      if ( a2 >= 0 && a2 < *(int16_t *)(dword_1ACF14 + 14) - *(int16_t *)(dword_1ACF14 + 37) )
        *(_WORD *)(dword_1ACF14 + 35) = a2;
    }
  }
  if ( a3 != 1 )
    return 73;
  return result;
}
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00105E99) --------------------------------------------------------
void __fastcall sub_105E99(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // ebx

  if ( a5 )
    a2 += *(int16_t *)(dword_1ACF14 + 33);
  v5 = a2 + *(int16_t *)(dword_1ACF14 + 37);
  if ( v5 + *(int16_t *)(dword_1ACF14 + 35) < *(int16_t *)(dword_1ACF14 + 14) )
  {
    if ( v5 < 0 )
      LOWORD(a2) = *(_WORD *)(dword_1ACF14 + 37);
    *(_WORD *)(dword_1ACF14 + 33) = a2;
  }
  JUMPOUT(0x105DE8);
}
// 105ED7: control flows out of bounds to 105DE8
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00105EDC) --------------------------------------------------------
void __fastcall sub_105EDC(int a1, int a2, unsigned int a3, int a4, int a5)
{
  if ( !a4 )
  {
    if ( a3 < 2u )
    {
      if ( a3 == 1 )
      {
        if ( a5 )
          a2 += *(int16_t *)(dword_1ACF14 + 6);
        if ( (unsigned int)a2 < 0x280 )
          *(_WORD *)(dword_1ACF14 + 6) = a2;
      }
    }
    else if ( a3 <= 2u )
    {
      if ( a5 )
        a2 += *(int16_t *)(dword_1ACF14 + 10);
      if ( (unsigned int)a2 < 0x1E0 )
        *(_WORD *)(dword_1ACF14 + 10) = a2;
    }
    else if ( a3 == 3 )
    {
      if ( a5 )
        a2 += *(int16_t *)(dword_1ACF14 + 14);
      if ( a2 > 0 && a2 <= 640 )
        *(_WORD *)(dword_1ACF14 + 14) = a2;
    }
  }
}
// 1ACF14: using guessed type int dword_1ACF14;


//----- (00105F89) --------------------------------------------------------
char __fastcall sub_105F89(int a1, int a2, int a3, int a4, int a5)
{
  char result; // al

  if ( !dword_1ACF70 )
    return 0;
  if ( a3 == 1 )
  {
    if ( a4 )
      dword_1ACFB7 = 0;
    else
      dword_1ACFB7 = a2;
  }
  else if ( a3 == 2 || a4 )
  {
    sub_1068F1();
    dword_1ACF70(dword_1ACF14, dword_1ACFB7, a2);
    return 0;
  }
  return result;
}
// 1ACF70: invalid function type '?' has been ignored
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF70: using guessed type int (__fastcall *dword_1ACF70)(_DWORD, _DWORD, _DWORD);
// 1ACFB7: using guessed type int dword_1ACFB7;


//----- (00105FE9) --------------------------------------------------------
void __fastcall sub_105FE9( unsigned int a1)
{
  int16_t v1; // bx

  v1 = *(_WORD *)(dword_1ACF08 + 4) - *(_WORD *)(dword_1ACF08 + 2) + 1 - *(_WORD *)(dword_1ACF08 + 20);
  if ( a1 && *(int16_t *)(dword_1ACF08 + 12) > 0 && v1 > 0 )
  {
    if ( a1 < 2u )
    {
      *(_WORD *)dword_1ACEFC += v1;
    }
    else if ( a1 <= 2u )
    {
      *(_WORD *)dword_1ACEFC += v1 / 2;
    }
    else if ( a1 == 3 )
    {
      sub_106053(v1);
    }
  }
}
// 106021: conditional instruction was optimized away because dl.1==1
// 1ACEFC: using guessed type int dword_1ACEFC;
// 1ACF08: using guessed type int dword_1ACF08;


//----- (00106053) --------------------------------------------------------
void __fastcall sub_106053( int a1)
{
  int v2; // ebx
  unsigned int v3; // edx
  unsigned int v4; // edx
  uint16_t v5; // si
  unsigned int v6; // eax
  uint16_t v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+4h] [ebp-8h]
  char v9; // [esp+8h] [ebp-4h]

  if ( *(_WORD *)(dword_1ACF08 + 14)
    && (v2 = *(int16_t *)(dword_1ACF08 + 14),
        v2 <= (int)(*(int16_t *)(dword_1ACF08 + 12)
                  - (__CFSHL__((uint64_t)*(int16_t *)(dword_1ACF08 + 12) >> 32, 2)
                   + 4 * ((uint64_t)*(int16_t *)(dword_1ACF08 + 12) >> 32))) >> 2) )
  {
    if ( v2 <= (int)(*(int16_t *)(dword_1ACF08 + 12)
                   - (__CFSHL__((uint64_t)*(int16_t *)(dword_1ACF08 + 12) >> 32, 3)
                    + 8 * ((uint64_t)*(int16_t *)(dword_1ACF08 + 12) >> 32))) >> 3 )
      v7 = 2;
    else
      v7 = 1;
  }
  else
  {
    v7 = 0;
  }
  v3 = dword_1ACEFC;
  v8 = 0;
  dword_1ACF04 = dword_1ACEFC + 8 * *(int16_t *)(dword_1ACF08 + 12);
  while ( *(_BYTE *)(v3 + 7) == 32 && v3 < dword_1ACF04 )
    v3 += 8;
  if ( v3 != dword_1ACF04 )
  {
    v4 = v3 + 8;
    v5 = 0;
    do
    {
      v6 = v4;
      v9 = byte_18391E[8 * v7 + v5];
      if ( (v9 & 2) != 0 && (uint16_t)++v8 > 3u )
      {
        v9 = 1;
        if ( !*(_WORD *)(dword_1ACF08 + 14) )
          break;
      }
      while ( v6 < dword_1ACF04 )
      {
        if ( *(_BYTE *)(v6 + 7) == 32 && (v9 & 1) != 0 || (v9 & 2) != 0 )
        {
          --a1;
          ++*(_WORD *)v6;
          if ( a1 <= 0 )
            break;
        }
        v6 += 8;
      }
      if ( !byte_18391E[8 * v7 + ++v5] )
        v5 = 0;
    }
    while ( a1 > 0 );
  }
  JUMPOUT(0x104385);
}
// 10616C: control flows out of bounds to 104385
// 1ACEFC: using guessed type int dword_1ACEFC;
// 1ACF04: using guessed type int dword_1ACF04;
// 1ACF08: using guessed type int dword_1ACF08;


//----- (00106171) --------------------------------------------------------
void sub_106171()
{
  uint8_t v0; // al
  uint8_t v1; // al
  int16_t v2; // ax
  int16_t v3; // ax
  int16_t v4; // ax
  int16_t v5; // ax
  int v6; // esi
  int v7; // esi
  int16_t v8; // [esp+0h] [ebp-4h]

  if ( *(int16_t *)(dword_1ACF08 + 12) > 0 )
  {
    dword_1ACF10 = dword_1ACEFC;
    v8 = 0;
    dword_1ACF04 = 8 * *(int16_t *)(dword_1ACF08 + 12) + dword_1ACEFC;
    if ( *(_BYTE *)(dword_1ACF14 + 40) )
    {
      word_1B3E86 = *(_BYTE *)(dword_1ACF10 + 5) & 0xF;
      v0 = *(_BYTE *)(dword_1ACF10 + 5) & 0xE0;
      if ( v0 < 0x20u )
      {
        if ( !v0 )
          sub_121B40();
      }
      else if ( v0 <= 0x20u )
      {
        sub_121B8C();
      }
      else if ( v0 == 64 )
      {
        sub_121BD8();
      }
      byte_1ACFBC = *(_BYTE *)(dword_1ACF10 + 5);
      sub_10688C(*(uint8_t *)(dword_1ACF10 + 4));
      byte_1ACFBB = *(_BYTE *)(dword_1ACF10 + 4);
      *(_BYTE *)(dword_1ACF14 + 40) = 0;
    }
    do
    {
      if ( byte_1ACFBC != *(_BYTE *)(dword_1ACF10 + 5) )
      {
        word_1B3E86 = *(_BYTE *)(dword_1ACF10 + 5) & 0xF;
        if ( (byte_1ACFBC & 0xE0) != (*(_BYTE *)(dword_1ACF10 + 5) & 0xE0) )
        {
          v1 = *(_BYTE *)(dword_1ACF10 + 5) & 0xE0;
          if ( v1 < 0x20u )
          {
            if ( !v1 )
              sub_121B40();
          }
          else if ( v1 <= 0x20u )
          {
            sub_121B8C();
          }
          else if ( v1 == 64 )
          {
            sub_121BD8();
          }
        }
        byte_1ACFBC = *(_BYTE *)(dword_1ACF10 + 5);
      }
      if ( byte_1ACFBB != *(_BYTE *)(dword_1ACF10 + 4) )
      {
        sub_10688C(*(uint8_t *)(dword_1ACF10 + 4));
        byte_1ACFBB = *(_BYTE *)(dword_1ACF10 + 4);
      }
      v8 += *(_WORD *)dword_1ACF10;
      v2 = v8;
      if ( v8 > *(int16_t *)dword_1ACEFC )
        v2 = v8
           + (uint8_t)byte_1B43D8[256 * (*(_BYTE *)(dword_1ACF10 + 4) & 0x7F)
                                        + *(uint8_t *)(dword_1ACF10 + 7)];
      if ( v2 >= word_1ACF18 )
      {
        if ( v2 > word_1ACF1C )
          word_1ACF1C = v2;
      }
      else
      {
        word_1ACF18 = v2;
      }
      v3 = *(_WORD *)(dword_1ACF10 + 2);
      if ( v3 < word_1ACF1A )
        word_1ACF1A = *(_WORD *)(dword_1ACF10 + 2);
      v4 = word_1B43A8[*(_BYTE *)(dword_1ACF10 + 4) & 0x7F] + v3;
      if ( v4 > word_1ACF1E )
        word_1ACF1E = v4;
      if ( *(_BYTE *)(dword_1ACF14 + 20) )
      {
        if ( word_1B3E86 )
        {
          memset(byte_1B3E7C, word_18450C, 8);
          v5 = v8 + 1;
          if ( *(_DWORD *)(dword_1ACF14 + 16) )
          {
            if ( word_1B3E86 != 2 )
            {
              v7 = v5;
              sub_123070(
                v5,
                (int16_t)(*(_WORD *)(dword_1ACF10 + 2) + 1),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
              sub_123070(
                v8,
                (int16_t)(*(_WORD *)(dword_1ACF10 + 2) + 1),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
              sub_123070(
                v7,
                *(int16_t *)(dword_1ACF10 + 2),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
            }
            if ( word_1B3E86 != 1 && word_1B3E86 != 3 )
            {
              sub_123070(
                (int16_t)(v8 - 1),
                *(int16_t *)(dword_1ACF10 + 2),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
              sub_123070(
                (int16_t)(v8 - 1),
                (int16_t)(*(_WORD *)(dword_1ACF10 + 2) - 1),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
              sub_123070(
                v8,
                (int16_t)(*(_WORD *)(dword_1ACF10 + 2) - 1),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
            }
            if ( word_1B3E86 == 3 || word_1B3E86 == 5 )
            {
              sub_123070(
                (int16_t)(v8 + 2),
                (int16_t)(*(_WORD *)(dword_1ACF10 + 2) + 2),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
              sub_123070(
                (int16_t)(v8 + 1),
                (int16_t)(*(_WORD *)(dword_1ACF10 + 2) + 2),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
              sub_123070(
                (int16_t)(v8 + 2),
                (int16_t)(*(_WORD *)(dword_1ACF10 + 2) + 1),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
            }
            if ( word_1B3E86 > 3 )
            {
              sub_123070(
                (int16_t)(v8 + 1),
                (int16_t)(*(_WORD *)(dword_1ACF10 + 2) - 1),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
              sub_123070(
                (int16_t)(v8 - 1),
                (int16_t)(*(_WORD *)(dword_1ACF10 + 2) + 1),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
            }
            if ( word_1B3E86 == 5 )
            {
              sub_123070(
                (int16_t)(v8 + 2),
                *(int16_t *)(dword_1ACF10 + 2),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
              sub_123070(
                v8,
                (int16_t)(*(_WORD *)(dword_1ACF10 + 2) + 2),
                *(_BYTE *)(dword_1ACF10 + 7),
                *(int16_t **)(dword_1ACF14 + 16));
            }
          }
          else
          {
            if ( word_1B3E86 != 2 )
            {
              v6 = v5;
              sub_121DEB(v5, *(_WORD *)(dword_1ACF10 + 2) + 1, *(_BYTE *)(dword_1ACF10 + 7));
              sub_121DEB(v8, *(_WORD *)(dword_1ACF10 + 2) + 1, *(_BYTE *)(dword_1ACF10 + 7));
              sub_121DEB(v6, *(_WORD *)(dword_1ACF10 + 2), *(_BYTE *)(dword_1ACF10 + 7));
            }
            if ( word_1B3E86 != 1 && word_1B3E86 != 3 )
            {
              sub_121DEB((int16_t)(v8 - 1), *(_WORD *)(dword_1ACF10 + 2), *(_BYTE *)(dword_1ACF10 + 7));
              sub_121DEB((int16_t)(v8 - 1), *(_WORD *)(dword_1ACF10 + 2) - 1, *(_BYTE *)(dword_1ACF10 + 7));
              sub_121DEB(v8, *(_WORD *)(dword_1ACF10 + 2) - 1, *(_BYTE *)(dword_1ACF10 + 7));
            }
            if ( word_1B3E86 == 3 || word_1B3E86 == 5 )
            {
              sub_121DEB((int16_t)(v8 + 2), *(_WORD *)(dword_1ACF10 + 2) + 2, *(_BYTE *)(dword_1ACF10 + 7));
              sub_121DEB((int16_t)(v8 + 1), *(_WORD *)(dword_1ACF10 + 2) + 2, *(_BYTE *)(dword_1ACF10 + 7));
              sub_121DEB((int16_t)(v8 + 2), *(_WORD *)(dword_1ACF10 + 2) + 1, *(_BYTE *)(dword_1ACF10 + 7));
            }
            if ( word_1B3E86 > 3 )
            {
              sub_121DEB((int16_t)(v8 + 1), *(_WORD *)(dword_1ACF10 + 2) - 1, *(_BYTE *)(dword_1ACF10 + 7));
              sub_121DEB((int16_t)(v8 - 1), *(_WORD *)(dword_1ACF10 + 2) + 1, *(_BYTE *)(dword_1ACF10 + 7));
            }
            if ( word_1B3E86 == 5 )
            {
              sub_121DEB((int16_t)(v8 + 2), *(_WORD *)(dword_1ACF10 + 2), *(_BYTE *)(dword_1ACF10 + 7));
              sub_121DEB(v8, *(_WORD *)(dword_1ACF10 + 2) + 2, *(_BYTE *)(dword_1ACF10 + 7));
            }
          }
          qmemcpy(byte_1B3E7C, byte_1B3E88, 8u);
        }
        if ( *(_DWORD *)(dword_1ACF14 + 16) )
          sub_123070(v8, *(int16_t *)(dword_1ACF10 + 2), *(_BYTE *)(dword_1ACF10 + 7), *(int16_t **)(dword_1ACF14 + 16));
        else
          sub_121DEB(v8, *(_WORD *)(dword_1ACF10 + 2), *(_BYTE *)(dword_1ACF10 + 7));
      }
      dword_1ACF10 += 8;
    }
    while ( dword_1ACF10 != dword_1ACF04 );
  }
  JUMPOUT(0x104385);
}
// 1067B6: control flows out of bounds to 104385
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 18450C: using guessed type int16_t word_18450C;
// 1ACEFC: using guessed type int dword_1ACEFC;
// 1ACF04: using guessed type int dword_1ACF04;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF10: using guessed type int dword_1ACF10;
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF18: using guessed type int16_t word_1ACF18;
// 1ACF1A: using guessed type int16_t word_1ACF1A;
// 1ACF1C: using guessed type int16_t word_1ACF1C;
// 1ACF1E: using guessed type int16_t word_1ACF1E;
// 1ACFBB: using guessed type char byte_1ACFBB;
// 1ACFBC: using guessed type char byte_1ACFBC;
// 1B3E86: using guessed type int16_t word_1B3E86;
// 1B43A8: using guessed type int16_t word_1B43A8[8];


//----- (001067BB) --------------------------------------------------------
int __fastcall sub_1067BB(int16_t *a1, int16_t *a2)
{
  return *a1 - *a2;
}


//----- (001067C4) --------------------------------------------------------
int sub_1067C4()
{
  int result; // eax

  if ( word_1838F7 > 1 )
    return qsort(word_1838F9, word_1838F7, 2);
  return result;
}
// 1838F7: using guessed type int16_t word_1838F7;
// 1838F9: using guessed type int16_t word_1838F9[10];


//----- (001067F0) --------------------------------------------------------
char sub_1067F0()
{
  int16_t v0; // bx
  int16_t v1; // si
  uint16_t i; // dx
  char v3; // cl

  v0 = 0;
  v1 = 0;
  for ( i = 0; i < 8u; ++i )
  {
    v3 = byte_1B3E7C[i];
    if ( v3 == byte_1B3E88[i] )
    {
      ++v1;
    }
    else if ( v3 == byte_1B3E90[i] )
    {
      ++v0;
    }
  }
  if ( v1 == 8 )
    return 0;
  if ( v0 == 8 )
    return 32;
  return 64;
}


//----- (0010683F) --------------------------------------------------------
int sub_10683F()
{
  _WORD *v0; // eax
  int result; // eax

  v0 = (_WORD *)dword_1ACF08;
  *(_WORD *)(dword_1ACF08 + 16) = 0;
  v0[7] = 0;
  v0[6] = 0;
  v0[9] = 0;
  result = dword_1ACF0C;
  *(_WORD *)(dword_1ACF0C + 16) = 0;
  *(_WORD *)(result + 18) = 0;
  return result;
}
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF0C: using guessed type int dword_1ACF0C;


//----- (0010688C) --------------------------------------------------------
int16_t __fastcall sub_10688C( int result)
{
  _BYTE v1[8]; // [esp+0h] [ebp-10h] BYREF
  _BYTE v2[8]; // [esp+8h] [ebp-8h] BYREF

  qmemcpy(v2, byte_1B3E7C, sizeof(v2));
  qmemcpy(v1, byte_1B61D8, sizeof(v1));
  if ( (result & 0x80u) != 0 )
    result = sub_120940(result & 0x7F, (int)byte_1B3E88);
  qmemcpy(byte_1B3E7C, v2, 8u);
  qmemcpy(byte_1B61D8, v1, 8u);
  return result;
}
// 1B3E82: using guessed type int dword_1B3E82;


//----- (001068F1) --------------------------------------------------------
int sub_1068F1()
{
  int result; // eax
  int16_t v1; // dx
  int v2; // eax
  int16_t v3; // bx
  int16_t v4; // ax
  int16_t v5; // ax
  int64_t v6; // rax
  int16_t v7; // cx

  result = dword_1ACF08;
  v1 = 0;
  if ( *(int16_t *)(dword_1ACF08 + 12) > 0 )
  {
    v2 = 8 * *(int16_t *)(dword_1ACF08 + 12);
    dword_1ACF10 = dword_1ACEFC;
    dword_1ACF04 = v2 + dword_1ACEFC;
    while ( dword_1ACF10 != dword_1ACF04 )
    {
      v1 += *(_WORD *)dword_1ACF10;
      v3 = v1;
      if ( v1 > *(int16_t *)dword_1ACEFC )
        v3 = v1
           + (uint8_t)byte_1B43D8[256 * (*(_BYTE *)(dword_1ACF10 + 4) & 0x7F)
                                        + *(uint8_t *)(dword_1ACF10 + 7)];
      if ( v3 >= word_1ACF18 )
      {
        if ( v3 > word_1ACF1C )
          word_1ACF1C = v3;
      }
      else
      {
        word_1ACF18 = v3;
      }
      v4 = *(_WORD *)(dword_1ACF10 + 2);
      if ( v4 < word_1ACF1A )
        word_1ACF1A = *(_WORD *)(dword_1ACF10 + 2);
      v5 = word_1B43A8[*(_BYTE *)(dword_1ACF10 + 4) & 0x7F] + v4;
      if ( v5 > word_1ACF1E )
        word_1ACF1E = v5;
      dword_1ACF10 += 8;
    }
    v6 = *(int16_t *)(dword_1ACF08 + 10) - *(int16_t *)dword_1ACEFC;
    v7 = (WORD2(v6) ^ v6) - WORD2(v6);
    result = dword_1ACF08;
    *(_WORD *)(dword_1ACF08 + 20) = v7;
  }
  return result;
}
// 1ACEFC: using guessed type int dword_1ACEFC;
// 1ACF04: using guessed type int dword_1ACF04;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF10: using guessed type int dword_1ACF10;
// 1ACF18: using guessed type int16_t word_1ACF18;
// 1ACF1A: using guessed type int16_t word_1ACF1A;
// 1ACF1C: using guessed type int16_t word_1ACF1C;
// 1ACF1E: using guessed type int16_t word_1ACF1E;
// 1B43A8: using guessed type int16_t word_1B43A8[8];


//----- (001069EE) --------------------------------------------------------
int __fastcall sub_1069EE(int result, int a2)
{
  int v2; // ebx
  int v3; // edx

  if ( (int16_t)result > *(int16_t *)dword_1ACEFC )
  {
    v2 = *(_BYTE *)(a2 + 4) & 0x7F;
    v3 = *(uint8_t *)(a2 + 7);
    LOWORD(v3) = (uint8_t)byte_1B43D8[256 * v2 + v3];
    result += v3;
  }
  if ( (int16_t)result >= word_1ACF18 )
  {
    if ( (int16_t)result > word_1ACF1C )
      word_1ACF1C = result;
  }
  else
  {
    word_1ACF18 = result;
  }
  return result;
}
// 1ACEFC: using guessed type int dword_1ACEFC;
// 1ACF18: using guessed type int16_t word_1ACF18;
// 1ACF1C: using guessed type int16_t word_1ACF1C;


//----- (00106A6E) --------------------------------------------------------
int16_t sub_106A6E()
{
  int16_t result; // ax

  word_1ACF1C = 0;
  word_1ACF1E = 0;
  result = *(_WORD *)(dword_1ACF14 + 10);
  word_1ACF18 = *(_WORD *)(dword_1ACF14 + 6);
  word_1ACF1A = result;
  return result;
}
// 1ACF14: using guessed type int dword_1ACF14;
// 1ACF18: using guessed type int16_t word_1ACF18;
// 1ACF1A: using guessed type int16_t word_1ACF1A;
// 1ACF1C: using guessed type int16_t word_1ACF1C;
// 1ACF1E: using guessed type int16_t word_1ACF1E;


//----- (00106AF3) --------------------------------------------------------
void sub_106AF3()
{
  int v0; // eax
  _WORD *v1; // ecx
  int16_t v2; // bx
  int16_t v3; // dx
  int v4; // ecx
  int16_t v5; // si
  int16_t v6; // di
  int16_t v7; // cx
  int16_t v8; // ax
  int16_t *v9; // eax
  int v10; // ecx
  int16_t v11; // dx
  int16_t v12; // [esp+0h] [ebp-Ch]
  int16_t v13; // [esp+8h] [ebp-4h]

  v0 = dword_1ACF14;
  v1 = (_WORD *)dword_1ACF08;
  v2 = *(_WORD *)(dword_1ACF14 + 37) + *(_WORD *)(dword_1ACF14 + 6);
  v3 = *(_WORD *)(dword_1ACF14 + 8) - *(_WORD *)(dword_1ACF14 + 35);
  *(_WORD *)(dword_1ACF08 + 16) = 0;
  v1[7] = 0;
  v1[6] = 0;
  v1[9] = 0;
  v4 = dword_1ACF0C;
  *(_WORD *)(dword_1ACF0C + 16) = 0;
  v12 = 0;
  *(_WORD *)(v4 + 18) = 0;
  v5 = v3;
  if ( *(_BYTE *)(v0 + 40) )
    v2 += *(_WORD *)(v0 + 33);
  if ( word_1849EE > 0 )
  {
    v13 = *(_WORD *)dword_1ACF14;
    while ( *(int16_t *)(dword_1ACF00 + 5) > 0 && v2 < v3 )
    {
      v6 = 0;
      do
      {
        if ( word_1C0B04[v6] >= v13 && v13 <= word_1C0B0C[v6] )
        {
          v7 = word_1C0AF4[v6];
          v8 = word_1C0AFC[v6];
          if ( (v2 >= v7 || v7 >= v3) && (v2 >= v8 || v8 >= v3) )
          {
            if ( v7 <= v2 && v8 >= v3 )
              v3 = v2;
          }
          else
          {
            if ( v7 <= v2 || v7 >= v3 )
            {
              if ( v7 >= v3 && v7 < v5 )
                v5 = word_1C0AF4[v6];
            }
            else
            {
              v3 = word_1C0AF4[v6];
            }
            if ( v8 <= v2 || v8 >= v3 )
            {
              if ( v8 >= v3 && v8 < v5 )
                v12 = word_1C0AFC[v6];
            }
            else
            {
              v2 = word_1C0AFC[v6];
            }
          }
        }
        ++v6;
      }
      while ( v6 < word_1849EE && v2 < v3 );
    }
  }
  v9 = (int16_t *)dword_1ACF08;
  if ( v2 >= v3 )
  {
    *(_WORD *)(dword_1ACF08 + 6) = 0;
    v11 = v9[1];
    v9[2] = v11;
    *v9 = v11;
    v9[5] = v11;
  }
  else
  {
    *(_WORD *)(dword_1ACF08 + 2) = v2;
    *v9 = v2;
    v9[5] = v2;
    v9[2] = v3;
    v9[4] = v5;
    v9[3] = v12;
    v10 = dword_1ACF14;
    *(_WORD *)(dword_1ACF14 + 21) = v9[1];
    *(_WORD *)(v10 + 23) = v9[2];
  }
  JUMPOUT(0x104385);
}
// 106C72: control flows out of bounds to 104385
// 1849EE: using guessed type int16_t word_1849EE;
// 1ACF00: using guessed type int dword_1ACF00;
// 1ACF08: using guessed type int dword_1ACF08;
// 1ACF0C: using guessed type int dword_1ACF0C;
// 1ACF14: using guessed type int dword_1ACF14;
// 1C0AF4: using guessed type int16_t word_1C0AF4[4];
// 1C0AFC: using guessed type int16_t word_1C0AFC[3];
// 1C0B04: using guessed type int16_t word_1C0B04[3];
// 1C0B0C: using guessed type int16_t word_1C0B0C[3];


//----- (00106CAC) --------------------------------------------------------
void __usercall sub_106CAC( int a1)
{
  int16_t v1; // si
  _DWORD *v2; // edx
  int v3; // eax
  int v4; // esi
  int v5; // eax
  _DWORD *v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // eax
  _DWORD *v10; // edx
  int v11; // eax
  uint16_t v12; // si
  _WORD *v13; // ecx
  int16_t v14; // dx
  int16_t v15; // ax
  int v16; // eax
  int v17; // esi
  int v18; // edx
  int v19; // ebx
  int16_t v20; // ax
  int v21; // eax
  char v22; // dl
  int v23; // [esp-Ch] [ebp-6Ah]
  _DWORD *v24; // [esp+0h] [ebp-5Eh] BYREF
  int v25; // [esp+4h] [ebp-5Ah]
  _WORD *v26; // [esp+8h] [ebp-56h]
  _DWORD v27[23]; // [esp+Ch] [ebp-52h]
  int v28[7]; // [esp+68h] [ebp+Ah] BYREF
  _DWORD v29[7]; // [esp+84h] [ebp+26h] BYREF
  _BYTE v30[28]; // [esp+A0h] [ebp+42h] BYREF
  _BYTE v31[16]; // [esp+BCh] [ebp+5Eh] BYREF
  int v32; // [esp+CCh] [ebp+6Eh] BYREF
  int v33; // [esp+D0h] [ebp+72h] BYREF
  int v34; // [esp+D4h] [ebp+76h]
  int v35; // [esp+D8h] [ebp+7Ah]
  int v36; // [esp+DCh] [ebp+7Eh]

  dword_192BD8 = 3753 * word_19999C + dword_197F98;
  sub_107AF(&v32);
  sub_131970();
  sub_11C2F0();
  sub_C5BB9();
  sub_124D41();
  sub_124C08();
  byte_1AD207 = 0;
  if ( !word_199A10 )
    byte_1AD208 = 0;
  byte_199BA3[0] = word_19999C;
  sub_10248B(1, 0);
  v1 = 1;
  v24 = sub_126AFD((int)aInfoLbx, 0, dword_192ED4);
  do
  {
    v2 = sub_126B42((int)aInfoLbx, v1, dword_192ED4);
    v3 = (uint16_t)v1++;
    (&v24)[v3] = v2;
  }
  while ( (uint16_t)v1 < 0x1Au );
  v4 = 0;
  do
  {
    v5 = sub_12DAA4(24, 108);
    v6 = sub_110D3C(dword_192ED4, v5);
    v7 = (uint16_t)v4++;
    v28[v7] = (int)v6;
  }
  while ( (uint16_t)v4 < 7u );
  v8 = 0;
  do
  {
    v9 = sub_12DAA4(160, 20);
    v10 = sub_110D3C(dword_192ED4, v9);
    v11 = (uint16_t)v8++;
    v29[v11] = v10;
  }
  while ( (uint16_t)v8 < 7u );
  v36 = sub_1075AB((int)v30);
  sub_107214((int)&v24, (int)v28, (int)v29, (int)v30);
  sub_1318D4(0, 255);
  sub_12B79D(v25);
  sub_102CDF();
  sub_24E96(v25);
  v33 = (*(_BYTE *)(3753 * word_19999C + dword_197F98 + 3679) & 0x70) >> 4;
  v12 = 0;
  word_1AD204 = (uint16_t)sub_1151B0(535, 434, (int)&unk_17A28B, v26, asc_17A289, 40);
  do
  {
    v23 = (int16_t)v12;
    v13 = (_WORD *)v27[v12];
    v14 = (uint8_t)byte_183C28[2 * v12];
    v15 = (uint8_t)byte_183C27[2 * v12++];
    sub_115383(v15, v14, (int)&unk_17A28B, v13, (int)&v33, v23, &unk_17A28B, 41);
  }
  while ( v12 < 5u );
  LOWORD(v16) = sub_113E65();
  v17 = v16;
  if ( byte_199CAE )
    sprintf(v31, "%i,%i", dword_192FD8 / 10, dword_192FD8 % 10);
  else
    sprintf(v31, "%i.%i", dword_192FD8 / 10, dword_192FD8 % 10);
  v34 = v36 - 1;
  byte_1AD209 = 1;
  v35 = v17 - 1;
  while ( 1 )
  {
    word_19994C = 0;
    byte_199BA3[0] = word_19999C;
    sub_10248B(1, 0);
    sub_128C32(0, 0, 639, 479, 0);
    sub_120DED(176, 176);
    sub_129130(212, 23, 620, 457, 178, 179, 179);
    sub_12A478(0, 0, (int)v24);
    sub_120BB5(4, (int)&unk_183B1E);
    sub_1210FD(151, 27, (int)v31);
    sub_10709A(v28, (int)v29, v34);
    v18 = (int)&unk_183B1E;
    sub_1112EC(dword_192ED4, (int)&unk_183B1E);
    v19 = dword_184378;
    sub_119400(v35);
    sub_131B34();
    sub_120BB5(5, (int)&unk_183B1E);
    switch ( (int16_t)v33 )
    {
      case 0:
        sub_103A1B();
        v18 = (int16_t)v17;
        v20 = sub_107E95((int)&v24, (int16_t)v17, a1);
        goto LABEL_17;
      case 1:
        sub_103A0C();
        v18 = (int16_t)v17;
        v20 = sub_108057((int)&v24, v17);
        byte_183F42 = 0;
        goto LABEL_17;
      case 2:
        sub_1039FD();
        v18 = (int16_t)v17;
        v20 = sub_1089C6();
        goto LABEL_17;
      case 3:
        sub_1039EE();
        v18 = (int16_t)v17;
        sub_108F98((int)&v24, (int16_t)v17);
        goto LABEL_17;
      case 4:
        v18 = (int16_t)v17;
        sub_109331((int)&v24);
LABEL_17:
        a1 = v20;
        break;
      default:
        break;
    }
    while ( v19 < dword_184378 )
      --dword_184378;
    sub_1113CC(dword_192ED4, v18);
    sub_1196F7();
    if ( a1 == word_1AD204 )
    {
      v21 = 3753 * word_19999C + dword_197F98;
      v22 = v33 & 7;
      *(_BYTE *)(v21 + 3679) &= 0x8Fu;
      *(_BYTE *)(v21 + 3679) |= 16 * v22;
      sub_11C2F0();
      sub_119281();
      word_199A08 = 0;
      JUMPOUT(0x107668);
    }
  }
}
// 107095: control flows out of bounds to 107668
// 106E8E: variable 'v16' is possibly undefined
// 106FD7: variable 'v20' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 183F42: using guessed type char byte_183F42;
// 184378: using guessed type int dword_184378;
// 192BD8: using guessed type int dword_192BD8;
// 192ED4: using guessed type int dword_192ED4;
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199CAE: using guessed type char byte_199CAE;
// 1AD204: using guessed type int16_t word_1AD204;
// 1AD207: using guessed type char byte_1AD207;
// 1AD208: using guessed type char byte_1AD208;
// 1AD209: using guessed type char byte_1AD209;


//----- (0010709A) --------------------------------------------------------
int __fastcall sub_10709A(int *a1, int a2, int a3)
{
  uint16_t v4; // si
  int v5; // edi
  int *v6; // eax
  int v7; // esi
  uint16_t i; // cx
  int16_t v9; // dx
  int v10; // ebx
  int v11; // esi
  void *v12; // edx
  char v14[64]; // [esp+0h] [ebp-12h] BYREF
  char v15[40]; // [esp+40h] [ebp+2Eh] BYREF
  char v16[40]; // [esp+68h] [ebp+56h] BYREF
  int v17; // [esp+90h] [ebp+7Eh]

  v17 = a2;
  sub_12A478(30, 212, *a1);
  if ( a3 > 0 )
  {
    v4 = 6;
    v5 = (18 * (a3 - 1) - 24) / 2 + 120;
    do
    {
      v6 = &a1[v4];
      if ( *v6 )
      {
        sub_12A478(v5, 212, *v6);
        v5 -= 18;
      }
      --v4;
    }
    while ( v4 );
  }
  v7 = 344;
  for ( i = 0; i < 7u; ++i )
  {
    v9 = v7;
    v7 += 16;
    v10 = *(_DWORD *)(v17 + 4 * i);
    sub_12A478(25, v9, v10);
  }
  sub_120BB5(1, (int)&unk_183B1E);
  sub_249F9(aBilltextLbx, 17, v15, 40);
  sub_1210FD(42, 324, (int)v15);
  sub_249F9(aBilltextLbx, 18, v16, 40);
  sub_1210FD(120, 324, (int)v16);
  v11 = *(int16_t *)(dword_192BD8 + 174) - *(_DWORD *)(dword_192BD8 + 180);
  if ( v11 < 0 )
    v12 = &unk_183B2E;
  else
    v12 = &unk_183B1E;
  sub_120BB5(2, (int)v12);
  sub_249F9(aBilltextLbx, 27, v14, 64);
  sub_24E08(v14, (int16_t)v11, 64);
  return sub_1210FD(105, 196, (int)v14);
}
// 24E08: using guessed type int __fastcall sub_24E08(_DWORD, _DWORD, _DWORD);
// 192BD8: using guessed type int dword_192BD8;


//----- (00107214) --------------------------------------------------------
_DWORD *__fastcall sub_107214(int a1, int a2, int a3, int a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // eax
  uint16_t v8; // di
  int v9; // edx
  int16_t *v10; // esi
  int v11; // esi
  int16_t *v12; // ecx
  int v13; // esi
  int64_t v14; // rax
  char *v15; // edi
  int16_t *v16; // ecx
  int v17; // ebx
  int v18; // ecx
  int v19; // eax
  _DWORD *result; // eax
  char v21[39]; // [esp+0h] [ebp+2h] BYREF
  char v22; // [esp+27h] [ebp+29h] BYREF
  _BYTE v23[32]; // [esp+28h] [ebp+2Ah] BYREF
  int v24; // [esp+48h] [ebp+4Ah]
  int v25; // [esp+4Ch] [ebp+4Eh]
  int v26; // [esp+50h] [ebp+52h]
  int16_t *v27; // [esp+54h] [ebp+56h]
  int16_t *v28; // [esp+58h] [ebp+5Ah]
  int16_t *v29; // [esp+5Ch] [ebp+5Eh]
  int16_t *v30; // [esp+60h] [ebp+62h]
  int v31; // [esp+64h] [ebp+66h]
  int16_t *v32; // [esp+68h] [ebp+6Ah]
  int v33; // [esp+6Ch] [ebp+6Eh]
  int v34; // [esp+70h] [ebp+72h]
  int16_t v35; // [esp+74h] [ebp+76h]
  int v36; // [esp+78h] [ebp+7Ah]
  int v37; // [esp+7Ch] [ebp+7Eh]

  v25 = a2;
  v31 = a3;
  v26 = a4;
  sub_1112EC(dword_192ED4, 9);
  v5 = sub_12DAA4(24, 9);
  v28 = (int16_t *)sub_110D3C(dword_192ED4, v5);
  sub_12D8F5(24, 9, (int)v28);
  sub_12F7E6(0, 0, *(int16_t **)(a1 + 92), v28);
  v6 = sub_12DAA4(24, 6);
  v32 = (int16_t *)sub_110D3C(dword_192ED4, v6);
  sub_12D8F5(24, 6, (int)v32);
  sub_12F7E6(0, 0, *(int16_t **)(a1 + 100), v32);
  v7 = sub_12DAA4(24, 108);
  v27 = (int16_t *)sub_110D3C(dword_192ED4, v7);
  sub_12D8F5(24, 108, (int)v27);
  sub_12F7E6(0, 0, *(int16_t **)(a1 + 88), v27);
  v8 = 0;
  v29 = *(int16_t **)(a1 + 96);
  do
  {
    v9 = 4 * v8;
    if ( *(int *)(v9 + v26) <= 0 && v8 )
    {
      *(_DWORD *)(v9 + v25) = 0;
    }
    else
    {
      v24 = 4 * v8;
      v10 = *(int16_t **)(v24 + v25);
      sub_12D8F5(24, 108, (int)v10);
      sub_12F7E6(0, (int16_t)(100 - *(_WORD *)(v24 + v26)), v27, v10);
      sub_12EFBD(0, 99, v10, (int *)v28, 1);
      sub_12F7E6(0, 102, v32, v10);
      sub_10A064(v10, *(int *)((char *)&off_183B77 + v24), 1u, 7u);
    }
    ++v8;
  }
  while ( v8 < 7u );
  v34 = 0;
  v33 = 0;
  v36 = 0xFFFF;
  v37 = 19;
  do
  {
    v11 = (uint16_t)v34;
    v30 = *(int16_t **)(v31 + 4 * (uint16_t)v33);
    v12 = v30;
    sub_12D8F5(160, 20, (int)v30);
    v13 = 4 * v11;
    sub_12F7E6(0, 0, v29, v12);
    sub_10A064(v30, *(int *)((char *)&off_183B77 + v13), 1u, 7u);
    sub_120BB5(2, *(int *)((char *)&off_183BCB + v13));
    if ( (_WORD)v34 )
    {
      v16 = v30;
      sprintf(v23, "%3i%%", *(_DWORD *)(v26 + v13));
      sub_122A6E(27, 3, (int)v23, (int)v16);
      v17 = 0;
      do
      {
        v18 = (int16_t)v17;
        v19 = (int16_t)v17++ / 2 + 1;
        v21[v18] = v19;
      }
      while ( (int16_t)v17 < 8 );
      switch ( (int16_t)v36 )
      {
        case 0:
          v35 = 20;
          break;
        case 1:
          v35 = 168;
          break;
        case 2:
          v35 = 174;
          break;
        case 3:
          v35 = 162;
          break;
        case 4:
          v35 = 151;
          break;
        case 5:
          v35 = 185;
          break;
        default:
          break;
      }
      v21[0] = v35;
      sub_120BB5(2, (int)v21);
      sub_249F9(aBilltextLbx, (int16_t)v37, v21, 40);
      sub_1229C5(108, 3, (int)v21, (int)v30);
    }
    else
    {
      v14 = sprintf(v23, "%i", *(int16_t *)(dword_192BD8 + 174));
      sub_249F9(aBilltextLbx, SHIDWORD(v14), v21, 40);
      v15 = &v22;
      do
        ++v15;
      while ( *v15 );
      strcpy(v15, v21);
      if ( (int16_t)sub_12066F((int)v23) > 126 )
        sub_120E8C(1);
      sub_1229C5(92, 3, (int)v23, (int)v30);
      word_1B3EA6 = word_1B43BC;
    }
    ++v36;
    ++v34;
    ++v33;
    ++v37;
  }
  while ( (uint16_t)v33 < 7u );
  result = sub_1113CC(dword_192ED4, 3);
  byte_183B36 = -80;
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 183B36: using guessed type char byte_183B36;
// 183B77: using guessed type _UNKNOWN *off_183B77;
// 183BCB: using guessed type _UNKNOWN *off_183BCB;
// 192BD8: using guessed type int dword_192BD8;
// 192ED4: using guessed type int dword_192ED4;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1B43BC: using guessed type int16_t word_1B43BC;


//----- (001075AB) --------------------------------------------------------
int __fastcall sub_1075AB(int a1)
{
  int v2; // esi
  uint16_t i; // dx
  int v4; // ecx
  int v5; // eax
  _DWORD v7[8]; // [esp+0h] [ebp-24h]
  int v8; // [esp+20h] [ebp-4h]

  v7[0] = *(int16_t *)(dword_192BD8 + 174);
  v7[1] = *(int16_t *)(dword_192BD8 + 184);
  v7[2] = *(int16_t *)(dword_192BD8 + 186);
  v7[3] = *(int16_t *)(dword_192BD8 + 188);
  v7[4] = *(int16_t *)(dword_192BD8 + 190);
  v7[5] = *(int16_t *)(dword_192BD8 + 192);
  v2 = 0;
  v7[6] = *(int16_t *)(dword_192BD8 + 194);
  for ( i = 0; i <= 6u; ++i )
  {
    if ( v2 < v7[i] )
      v2 = v7[i];
  }
  v4 = 0;
  if ( v2 <= 0 )
  {
    memset(a1, 0, 28);
  }
  else
  {
    v8 = 0;
    do
    {
      v5 = 1000 * v7[(uint16_t)v8] / v2 + 5;
      v7[7] = 10;
      v5 /= 10;
      *(_DWORD *)(a1 + 4 * (uint16_t)v8) = v5;
      if ( v5 )
        ++v4;
      ++v8;
    }
    while ( (uint16_t)v8 < 7u );
  }
  return v4;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192BD8: using guessed type int dword_192BD8;


//----- (0010766E) --------------------------------------------------------
void sub_10766E()
{
  int v0; // esi
  int v1; // edi
  int16_t v2; // ax
  int16_t v3; // ax
  int v4; // esi
  int v5; // eax
  int v6; // ebx
  int v7; // edi
  int16_t v8; // cx
  int16_t v9; // cx
  int v10; // esi
  int16_t v11; // ax
  int v12; // ecx
  _BYTE v13[16]; // [esp+0h] [ebp-24h] BYREF
  int v14; // [esp+10h] [ebp-14h]
  int v15; // [esp+14h] [ebp-10h]
  int v16; // [esp+18h] [ebp-Ch]
  int v17; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]

  v0 = 237;
  v1 = 0;
  while ( 1 )
  {
    v2 = (uint8_t)byte_183D95[(uint16_t)v1++];
    v3 = v2 + 390;
    if ( (uint16_t)v1 >= 0xAu )
      v1 = 0;
    v14 = v3;
    sub_134D2D((int16_t)v0, 389, (int16_t)v0, v3, 177);
    v4 = v0 + 1;
    v5 = (int16_t)v4;
    v6 = (int16_t)v4;
    v0 = v4 + 9;
    sub_134D2D(v5, 389, v6, v14, 185);
    if ( (uint16_t)v0 > 0x24Cu )
    {
      sub_134D2D(232, 390, 588, 390, 185);
      v16 = 390;
      sub_134D2D(237, 140, 237, 396, 177);
      v7 = 0;
      sub_134D2D(238, 140, 238, 396, 185);
      while ( 1 )
      {
        v8 = (uint8_t)byte_183D95[(uint16_t)v7++];
        v9 = 238 - v8;
        if ( (uint16_t)v7 >= 0xAu )
          v7 = 0;
        v10 = (int16_t)v16;
        sub_12972D(v9 - 1, v16, 177);
        v16 -= 10;
        sub_134D2D(v9, v10, 239, v10, 185);
        if ( (uint16_t)v16 < 0x8Cu )
        {
          sub_120BB5(1, (int)&unk_183B1E);
          v11 = dword_192FD8 + 30536;
          v12 = 35000;
          if ( (int16_t)(dword_192FD8 + 30536) > 35 )
          {
            if ( v11 > 70 )
            {
              if ( v11 > 175 )
              {
                v18 = 50;
                if ( v11 > 350 )
                  v12 = 10 * ((dword_192FD8 - 345) / 10);
              }
              else
              {
                v18 = 25;
              }
            }
            else
            {
              v18 = 10;
            }
          }
          else
          {
            v18 = 5;
          }
          v15 = 239;
          v17 = 0;
          while ( 1 )
          {
            if ( v12 % 5 || !(v12 % 10) )
            {
              itoa(v12 / 10, v13, 10, v12);
            }
            else if ( byte_199CAE )
            {
              sprintf(v13, "%i,%i", v12 / 10, v12 % 10);
            }
            else
            {
              sprintf(v13, "%i.%i", v12 / 10, v12 % 10);
            }
            ++v17;
            sub_1210FD(v15, 400, (int)v13);
            v15 += 50;
            v12 += (int16_t)v18;
            if ( (int16_t)v17 >= 8 )
              JUMPOUT(0x107667);
          }
        }
      }
    }
  }
}
// 1078A4: control flows out of bounds to 107667
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 192FD8: using guessed type int dword_192FD8;
// 199CAE: using guessed type char byte_199CAE;


//----- (001078A9) --------------------------------------------------------
int __fastcall sub_1078A9(int a1)
{
  int result; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // edx

  result = 0;
  do
  {
    HIWORD(v3) = HIWORD(dword_197F98);
    LOWORD(v3) = *(uint8_t *)(3753 * word_19999C + dword_197F98 + 3679);
    v4 = v3 & (1 << result);
    v5 = (int16_t)result++;
    *(_WORD *)(a1 + 2 * v5) = v4;
  }
  while ( (int16_t)result < 4 );
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (001078ED) --------------------------------------------------------
int __fastcall sub_1078ED(int a1)
{
  int result; // eax

  result = 0;
  do
  {
    if ( *(_WORD *)(a1 + 2 * (int16_t)result) )
      *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 3679) |= 1 << result;
    else
      *(_BYTE *)(3753 * word_19999C + dword_197F98 + 3679) &= ~(1 << result);
    ++result;
  }
  while ( (int16_t)result < 4 );
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010794C) --------------------------------------------------------
void __fastcall sub_10794C(int a1)
{
  int v1; // eax
  int v2; // ebx
  int v3; // ecx
  int v4; // edx
  int16_t v5; // si
  int16_t v6; // ax
  int v7; // edx
  int16_t v8; // si
  int v9; // eax
  int16_t v10; // bx
  int16_t v11; // cx
  int v12; // eax
  int16_t v13; // cx
  int v14; // eax
  int v15; // edi
  int16_t i; // si
  int16_t v17; // dx
  int16_t v18; // di
  unsigned int v19; // edx
  int16_t v20; // cx
  int16_t v21; // bx
  int v22; // eax
  unsigned int v23; // ecx
  int16_t v24; // ax
  int16_t v25; // di
  int v26; // eax
  int16_t v27; // si
  int v28; // ebx
  int v29; // edx
  int16_t v30; // di
  int v31; // eax
  int16_t v32; // si
  int v33; // eax
  uint16_t v34; // dx
  _BYTE v36[11200]; // [esp+4h] [ebp-2C30h] BYREF
  _BYTE v37[32]; // [esp+2BC4h] [ebp-70h] BYREF
  _BYTE v38[12]; // [esp+2BE4h] [ebp-50h]
  unsigned int v39; // [esp+2BF0h] [ebp-44h]
  int v40; // [esp+2BF4h] [ebp-40h]
  int v41; // [esp+2BF8h] [ebp-3Ch]
  int v42; // [esp+2BFCh] [ebp-38h]
  int v43; // [esp+2C00h] [ebp-34h] BYREF
  int v44; // [esp+2C04h] [ebp-30h]
  int v45; // [esp+2C08h] [ebp-2Ch]
  int v46; // [esp+2C0Ch] [ebp-28h]
  int v47; // [esp+2C10h] [ebp-24h]
  int v48; // [esp+2C14h] [ebp-20h]
  int v49; // [esp+2C18h] [ebp-1Ch]
  int v50; // [esp+2C1Ch] [ebp-18h]
  int v51; // [esp+2C20h] [ebp-14h]
  int v52; // [esp+2C24h] [ebp-10h]
  int v53; // [esp+2C28h] [ebp-Ch]
  int v54; // [esp+2C2Ch] [ebp-8h]
  int v55; // [esp+2C30h] [ebp-4h]

  v1 = 0;
  do
  {
    HIWORD(v2) = HIWORD(dword_197F98);
    LOWORD(v2) = *(uint8_t *)(3753 * word_19999C + dword_197F98 + 3679);
    v3 = (1 << v1) & v2;
    v4 = (int16_t)v1++;
    *(_WORD *)&v38[2 * v4] = v3;
  }
  while ( (int16_t)v1 < 4 );
  v5 = 0;
  v6 = 0;
  do
  {
    v7 = v5;
    if ( *(_WORD *)&v38[2 * v5] )
      ++v6;
    ++v5;
  }
  while ( v5 < 4 );
  if ( !v6 )
LABEL_72:
    JUMPOUT(0x107667);
  v47 = *(_DWORD *)v38;
  v52 = *(_DWORD *)&v38[2];
  v46 = *(_DWORD *)&v38[4];
  v8 = word_199934 - 1;
  v45 = *(_DWORD *)&v38[6];
  while ( v8 >= 0 )
  {
    LOWORD(v7) = (uint8_t)byte_199BA3[v8];
    v9 = 3753 * (uint8_t)byte_199BA3[v8];
    v54 = v7;
    v10 = 0;
    v7 = v9 + dword_197F98;
    v41 = v9 + dword_197F98;
    v11 = sub_1029D1(&v43);
    while ( v10 < (int16_t)v43 )
    {
      v12 = 0;
      if ( (_WORD)v47 )
        v12 = (uint16_t)word_17D638 * *(uint8_t *)(v41 + v11 + 2971);
      if ( (_WORD)v45 )
      {
        v40 = *(uint8_t *)(v41 + v11 + 2621);
        v12 += v40 * (uint16_t)word_17D63E;
      }
      if ( (_WORD)v46 )
      {
        v40 = *(uint8_t *)(v41 + v11 + 2271);
        v12 += v40 * (uint16_t)word_17D63C;
      }
      if ( (_WORD)v52 )
      {
        v40 = *(uint8_t *)(v41 + v11 + 3321);
        v12 += v40 * (uint16_t)word_17D63A;
      }
      v7 = 4 * v10 + 1400 * (int16_t)v54;
      ++v11;
      *(_DWORD *)&v36[v7] = v12;
      if ( v11 >= 350 )
        v11 = 0;
      ++v10;
    }
    --v8;
  }
  v13 = word_199934;
  while ( --v13 >= 0 )
  {
    v14 = v13;
    LOWORD(v14) = (uint8_t)byte_199BA3[v13];
    v15 = 0;
    v55 = v14;
    do
    {
      for ( i = 0; i < (int16_t)v43; ++i )
      {
        v40 = 1400 * (int16_t)v55;
        v17 = i;
        sub_107D5B((int)&v36[v40], v17, v43);
      }
      ++v15;
    }
    while ( (int16_t)v15 < 10 );
  }
  v18 = word_199934;
  v19 = 0;
  while ( --v18 >= 0 )
  {
    v20 = 0;
    v21 = (uint8_t)byte_199BA3[v18];
    while ( v20 < (int16_t)v43 )
    {
      *(_DWORD *)&v38[8] = 1400 * v21;
      v22 = *(_DWORD *)&v38[8] + 4 * v20;
      if ( v19 < *(_DWORD *)&v36[v22] )
        v19 = *(_DWORD *)&v36[v22];
      ++v20;
    }
  }
  v23 = 25;
  v24 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v24 )
      {
        v25 = word_199934 - 1;
        v39 = 100 * v23 / 0xFA;
        while ( v25 >= 0 )
        {
          v26 = v25;
          LOWORD(v26) = (uint8_t)byte_199BA3[v25];
          v27 = 0;
          v50 = v26;
          while ( v27 < (int16_t)v43 )
          {
            v28 = 4 * v27++ + 1400 * (int16_t)v50;
            *(_DWORD *)&v36[v28] = 100 * *(_DWORD *)&v36[v28] / v39;
          }
          --v25;
        }
        sub_120BB5(1, (int)&unk_183B1E);
        itoa(v23, v37, 10, v23);
        HIWORD(v29) = 0;
        sub_1212B3(246, 138, (int)v37);
        v30 = word_199934;
        --v43;
        while ( --v30 >= 0 )
        {
          LOWORD(v29) = (uint8_t)byte_199BA3[v30];
          v31 = dword_1ACFC0[(uint8_t)byte_199BA3[v30]];
          v51 = 238;
          v32 = 0;
          LOWORD(v31) = *(uint8_t *)(v31 + 7);
          v49 = v29;
          v44 = v31;
          while ( v32 < (int16_t)v43 )
          {
            v33 = 1400 * (int16_t)v49 + 4 * v32;
            v42 = (uint16_t)(390 - *(_WORD *)&v36[v33]);
            v34 = 390 - *(_WORD *)&v36[v33 + 4];
            v48 = a1 + v51;
            v53 = v34;
            sub_134D2D((int16_t)(v51 + 1), (int16_t)(v42 + 1), (int16_t)(a1 + v51 + 1), (int16_t)(v34 + 1), 177);
            v29 = (int16_t)v42;
            sub_134D2D((int16_t)v51, (int16_t)v42, (int16_t)v48, (int16_t)v53, v44);
            ++v32;
            v51 = v48;
          }
        }
        goto LABEL_72;
      }
      if ( v19 >= v23 )
        break;
      v24 = 1;
    }
    if ( v23 < 0x64 )
    {
      if ( v23 < 0x19 )
        goto LABEL_60;
      if ( v23 <= 0x19 )
      {
        v23 = 50;
      }
      else if ( v23 == 50 )
      {
        v23 = 100;
      }
      else
      {
LABEL_60:
        v23 += 2000;
      }
    }
    else if ( v23 <= 0x64 )
    {
      v23 = 250;
    }
    else if ( v23 < 0x1F4 )
    {
      if ( v23 != 250 )
        goto LABEL_60;
      v23 = 500;
    }
    else if ( v23 <= 0x1F4 )
    {
      v23 = 1000;
    }
    else
    {
      if ( v23 != 1000 )
        goto LABEL_60;
      v23 = 2000;
    }
  }
}
// 107D56: control flows out of bounds to 107667
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 17D638: using guessed type int16_t word_17D638;
// 17D63A: using guessed type int16_t word_17D63A;
// 17D63C: using guessed type int16_t word_17D63C;
// 17D63E: using guessed type int16_t word_17D63E;
// 197F98: using guessed type int dword_197F98;
// 199934: using guessed type int16_t word_199934;
// 19999C: using guessed type int16_t word_19999C;
// 1ACFC0: using guessed type int dword_1ACFC0[];


//----- (00107D5B) --------------------------------------------------------
unsigned int __fastcall sub_107D5B(int a1, int a2, int a3)
{
  int *v6; // eax
  int v7; // edi
  int *v8; // eax
  int v9; // eax
  unsigned int v10; // edi
  unsigned int v11; // edx
  int v12; // [esp+8h] [ebp-4h]

  if ( a2 >= a3 )
    return 0;
  v6 = (int *)(a1 + 4 * a2);
  v7 = *v6;
  if ( a2 + 1 < a3 )
    v12 = v6[1];
  else
    v12 = *v6;
  v8 = (int *)(a1 + 4 * a2);
  if ( a2 + 2 < a3 )
    v9 = v8[2];
  else
    v9 = *v8;
  v10 = (v12 + v7 + v9) / 3u;
  v11 = abs32(v12 - v10);
  if ( a3 > a2 + 1 )
    *(_DWORD *)(a1 + 4 * a2 + 4) = v10;
  return v11;
}


//----- (00107DEA) --------------------------------------------------------
void sub_107DEA()
{
  int v0; // edi
  int16_t v1; // si
  int16_t i; // cx
  int16_t v3; // bx
  int16_t v4; // dx
  int16_t v5; // [esp+0h] [ebp-4h]

  v0 = 64;
  v1 = 351;
  if ( word_199934 > 3 )
  {
    v1 = 295;
    v5 = 150;
  }
  if ( word_199934 > 6 )
  {
    v1 = 233;
    v5 = 122;
  }
  for ( i = 0; i < word_199934; ++i )
  {
    v3 = (uint8_t)byte_199BA3[i];
    sub_120BB5(4, dword_1ACFC0[(uint8_t)byte_199BA3[i]]);
    v4 = v0;
    v0 += 19;
    sub_1212B3(v1, v4, dword_197F98 + 3753 * v3 + 21);
    if ( i == 2 || i == 5 )
    {
      v0 = 64;
      v1 += v5;
    }
  }
  JUMPOUT(0x107667);
}
// 107E90: control flows out of bounds to 107667
// 107E83: variable 'v5' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 199934: using guessed type int16_t word_199934;
// 1ACFC0: using guessed type int dword_1ACFC0[];


//----- (00107E95) --------------------------------------------------------
int __usercall sub_107E95(int a1, int a2, int a3)
{
  int v4; // eax
  int v5; // edx
  int16_t *v6; // edi
  int v7; // edx
  _WORD *v8; // ecx
  int16_t *i; // edx
  int16_t v10; // ax
  int v11; // eax
  int v12; // eax
  int16_t *v13; // eax
  char v15[40]; // [esp+0h] [ebp-34h] BYREF
  int16_t v16; // [esp+28h] [ebp-Ch] BYREF
  int16_t v17; // [esp+2Ah] [ebp-Ah]
  int16_t v18; // [esp+2Ch] [ebp-8h]
  int16_t v19; // [esp+2Eh] [ebp-6h]
  int v20; // [esp+30h] [ebp-4h]

  v20 = a2;
  sub_249F9(aBilltextLbx, 5, v15, 40);
  sub_1210FD(416, 31, (int)v15);
  sub_109FBA(a1);
  byte_199BA3[0] = word_19999C;
  sub_102633(1, 0);
  v4 = 0;
  do
  {
    LOWORD(a3) = *(uint8_t *)(dword_197F98 + 3753 * word_19999C + 3679);
    a3 &= 1 << v4;
    v5 = (int16_t)v4++;
    *(&v16 + v5) = a3;
  }
  while ( (int16_t)v4 < 4 );
  if ( !(v16 + v17 + v18 + v19) )
  {
    v19 = 1;
    v18 = 1;
    v17 = 1;
    v16 = 1;
    sub_1078ED((int)&v16);
  }
  v6 = 0;
  do
  {
    v7 = (uint16_t)v6;
    v8 = *(_WORD **)(a1 + 4 * (uint16_t)v6 + 32);
    v6 = (int16_t *)((char *)v6 + 1);
    sub_11523B(word_183D9F[v7], 427, (int)&unk_17A28B, v8, (int)&v16 + v7 * 2, &unk_17A28B, 40);
  }
  while ( (uint16_t)v6 < 4u );
  sub_1191CA((int)nullsub_16, 2);
  do
  {
    for ( i = (int16_t *)&unk_183C41; i < word_183C63; i = (int16_t *)((char *)i + 17) )
      sub_109E01(i);
    sub_107DEA();
    sub_10766E();
    sub_10794C(v10);
    sub_124DEC();
    sub_109DB5((int)word_183C63, v6);
    do
    {
      sub_12C2A0();
      v12 = sub_1171AB(v11, (int)i, (int)word_183C63, (int)word_183C63);
      i = (int16_t *)v12;
      if ( word_19994C )
      {
        v13 = 0;
        return nullsub_16(v13, i);
      }
      if ( (int16_t)v12 < (int16_t)v20 )
      {
        if ( !(_WORD)v12 )
        {
          sub_1077D(v12, v12, (int)word_183C63, v6);
          sub_12C2C6(2);
        }
      }
      else
      {
        sub_1078ED((int)&v16);
      }
    }
    while ( !(_WORD)i );
  }
  while ( (int16_t)i >= (int16_t)v20 );
  v13 = i;
  return nullsub_16(v13, i);
}
// 107FC8: variable 'v10' is possibly undefined
// 107FDD: variable 'v11' is possibly undefined
// 108028: using guessed type int __fastcall nullsub_16(_DWORD, _DWORD);
// 183C63: using guessed type int16_t word_183C63[34];
// 183D9F: using guessed type int16_t word_183D9F[];
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;


//----- (00108029) --------------------------------------------------------
int __fastcall sub_108029( unsigned int a1, unsigned int a2, unsigned int a3)
{
  char *v4; // eax

  v4 = sub_10F7A1(a3, word_19999C);
  return sub_103BC4(a1, a2, 197, (int)v4, 0);
}
// 19999C: using guessed type int16_t word_19999C;


//----- (00108057) --------------------------------------------------------
int __fastcall sub_108057(int a1, int a2)
{
  byte_183F42 = 1;
  return sub_108073(a1 + 48, a2, word_19999C);
}
// 183F42: using guessed type char byte_183F42;
// 19999C: using guessed type int16_t word_19999C;


//----- (00108073) --------------------------------------------------------
int __fastcall sub_108073(int a1, int a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  uint16_t v9; // si
  _WORD *v10; // ecx
  int16_t v11; // dx
  int16_t v12; // ax
  int16_t *v13; // edi
  int16_t *i; // edx
  int v15; // ecx
  int v16; // ebx
  int v17; // edx
  _BYTE *v18; // eax
  int16_t v19; // ax
  unsigned int v20; // eax
  int v21; // eax
  int16_t v22; // si
  int v23; // ebx
  _DWORD *v24; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v29; // [esp-Ch] [ebp-168h]
  int v30; // [esp-4h] [ebp-160h]
  _BYTE v34[256]; // [esp+Ch] [ebp-150h] BYREF
  char v35[40]; // [esp+10Ch] [ebp-50h] BYREF
  char v36[20]; // [esp+134h] [ebp-28h] BYREF
  _DWORD *v37; // [esp+148h] [ebp-14h]
  _DWORD *v38; // [esp+14Ch] [ebp-10h]
  char *v39; // [esp+150h] [ebp-Ch]
  int v40; // [esp+154h] [ebp-8h]
  char v41; // [esp+158h] [ebp-4h]

  v3 = 0;
  do
  {
    dword_1AD1E0 = (int)&v34[64 * (uint16_t)v3];
    qmemcpy(&v34[64 * (uint16_t)v3], &unk_183E15, 0x40u);
    v4 = sub_110D3C(dword_192ED4, (uint16_t)word_183E0D[(uint16_t)v3]);
    v5 = dword_1AD1E0;
    *(_DWORD *)(dword_1AD1E0 + 22) = v4;
    sub_108611(v5, (int16_t)v3, v3);
    v6 = dword_1AD1E0;
    *(_BYTE *)(*(_DWORD *)(dword_1AD1E0 + 22) + 5) = 1;
    ++v3;
    *(_BYTE *)(*(_DWORD *)(v6 + 22) + 6) = 0;
  }
  while ( (uint16_t)v3 < 4u );
  v37 = sub_110D3C(dword_192ED4, 1404);
  v7 = sub_12DAA4(180, 150);
  dword_1AD1F0 = (int)sub_110D3C(dword_192ED4, v7);
  v8 = sub_12DAA4(180, 48);
  dword_1AD1EC = (int)sub_110D3C(dword_192ED4, v8);
  v41 = 0;
  v38 = sub_126B42((int)aAppPicsLbx, 0, dword_192ED4);
  v9 = 0;
  sub_1191CA((int)sub_10852A, 2);
  do
  {
    v29 = (int16_t)v9;
    v10 = *(_WORD **)(a1 + 4 * v9 + 16);
    v11 = word_183C33[2 * v9];
    v12 = word_183C31[2 * v9++];
    v40 = sub_115383(v12, v11, (int)&unk_17A28B, v10, (int)&word_183E55, v29, &unk_17A28B, 40);
  }
  while ( v9 < 4u );
  v39 = sub_1151B0(410, 65, (int)&unk_17A28B, *(_WORD **)(a1 + 8), asc_17A289, 40);
  v13 = (int16_t *)sub_1151B0(410, 395, (int)&unk_17A28B, *(_WORD **)(a1 + 12), asc_17A289, 40);
  sub_249F9(aBilltextLbx, 6, v35, 40);
  sub_1210FD(416, 31, (int)v35);
  for ( i = word_183C63; i < word_183CA7; i = (int16_t *)((char *)i + 17) )
    sub_109E01(i);
  v15 = 253;
  sub_128C32(433, 115, 612, 253, 0);
  v16 = (int)v38;
  sub_12A478(433, 115, (int)v38);
LABEL_9:
  v17 = word_183E55 << 6;
  v18 = &v34[v17];
  LOBYTE(v15) = 0;
  dword_1AD1E0 = (int)&v34[v17];
LABEL_10:
  sub_FE8BE((int)v18, v17, v16, v13);
  sub_109E01(word_183C63);
  sub_12A478(410, 65, *(_DWORD *)a1);
  sub_12A478(410, 395, *(_DWORD *)(a1 + 4));
  sub_10A4A7(dword_1AD1E0);
  sub_124DEC();
  sub_119400((int16_t)v13);
  word_1AD1FC = sub_113E65();
  sub_10A188(dword_1AD1E0);
  word_1AD200 = v19;
  if ( (_BYTE)v15 )
    sub_10A5E3(dword_1AD1E0, word_1AD1FC);
  v17 = (int16_t)v39;
  v16 = (int16_t)v13;
  sub_10A689(dword_1AD1E0, (int16_t)v39, (int16_t)v13);
  v20 = sub_10A659(dword_1AD1E0);
  word_1AD202 = 0;
  byte_1AD206 = 1;
  dword_1AD1E4 = v20;
  sub_109DB5((int16_t)v13, v13);
  while ( 1 )
  {
    sub_12C2A0();
    if ( byte_1AD206 )
    {
      v21 = dword_1AD1E0;
      if ( *(_BYTE *)(dword_1AD1E0 + 21) )
      {
        sub_12D8F5(180, 150, dword_1AD1F0);
        sub_12D8F5(180, 48, dword_1AD1EC);
        v22 = *(uint8_t *)(*(uint8_t *)(dword_1AD1E4 + 6) + dword_1AD1E4 + 126);
        v23 = (int)v37;
        sub_A6547(v36);
        v24 = sub_126BDD((int)v36, 0, v23, v22, 1u, 1403);
        sub_120BB5(2, (int)&unk_183B1E);
        sub_103BE2(2u, 4u, 173, (int)v24 + 103, 0, dword_1AD1F0);
        word_1AD1FE = v22;
        sub_120BB5(4, (int)&unk_183B1E);
        v30 = dword_1AD1EC;
        v15 = (int)sub_10F7A1(word_1AD1FE, a3);
        v25 = sub_103BE2(0, 0xCu, 176, v15, 2, v30);
        sub_FE8BE(v25, 12, 176, v13);
        if ( v41 )
          sub_1113CC(dword_192ED4, 12);
        sub_1112EC(dword_192ED4, 12);
        v17 = v22;
        v16 = dword_192ED4;
        v41 = 1;
        dword_1AD1E8 = (int)sub_126B42((int)aAppPicsLbx_0, v22, dword_192ED4);
        sub_12B79D(dword_1AD1E8);
        v21 = sub_131F7B();
      }
    }
    v26 = sub_1171AB(v21, v17, v16, v15);
    v15 = v26;
    if ( word_19994C )
      break;
    if ( (int16_t)v26 <= (int16_t)v40 )
    {
      if ( !(_WORD)v26 )
      {
        LOBYTE(v27) = sub_10852A();
        sub_1077D(v27, v17, v16, v13);
        sub_12C2C6(2);
      }
    }
    else if ( (_WORD)v26 == (_WORD)v13
           && (HIWORD(v18) = HIWORD(dword_1AD1E0), LOBYTE(v18) = sub_10A527(dword_1AD1E0), (_BYTE)v18)
           || (_WORD)v15 == (_WORD)v39 && (LOBYTE(v18) = sub_10A540(dword_1AD1E0), (_BYTE)v18) )
    {
      LOBYTE(v15) = 1;
      goto LABEL_10;
    }
    if ( (_WORD)v15 && (int16_t)v15 <= (int16_t)v40 )
    {
      if ( (int16_t)v15 >= a2 )
        goto LABEL_9;
      sub_12A478(434, 264, dword_1AD1F0);
      v17 = 60;
      v16 = dword_1AD1EC;
      sub_12A478(434, 60, dword_1AD1EC);
      v26 = sub_124ECB();
      break;
    }
  }
  sub_FE8BE(v26, v17, v16, v13);
  return v15;
}
// 1084DC: conditional instruction was optimized away because cx.2!=0
// 108278: variable 'v18' is possibly undefined
// 1082E2: variable 'v19' is possibly undefined
// 108464: variable 'v21' is possibly undefined
// 1084B7: variable 'v27' is possibly undefined
// 183C31: using guessed type int16_t word_183C31[];
// 183C33: using guessed type int16_t word_183C33[7];
// 183C63: using guessed type int16_t word_183C63[34];
// 183CA7: using guessed type int16_t word_183CA7[34];
// 183E0D: using guessed type int16_t word_183E0D[4];
// 183E55: using guessed type int16_t word_183E55;
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 1AD1E0: using guessed type int dword_1AD1E0;
// 1AD1E4: using guessed type int dword_1AD1E4;
// 1AD1E8: using guessed type int dword_1AD1E8;
// 1AD1EC: using guessed type int dword_1AD1EC;
// 1AD1F0: using guessed type int dword_1AD1F0;
// 1AD1FC: using guessed type int16_t word_1AD1FC;
// 1AD1FE: using guessed type int16_t word_1AD1FE;
// 1AD200: using guessed type int16_t word_1AD200;
// 1AD202: using guessed type int16_t word_1AD202;
// 1AD206: using guessed type char byte_1AD206;


//----- (0010852A) --------------------------------------------------------
char sub_10852A()
{
  int16_t v0; // bx
  unsigned int v1; // eax

  v0 = (uint16_t)sub_114177();
  if ( sub_124075() || byte_1AD206 || v0 < word_1AD1FC || v0 > word_1AD200 || v0 == word_1AD202 )
  {
    if ( *(_BYTE *)(dword_1AD1E0 + 21) )
    {
      sub_12A478(433, 115, dword_1AD1E8);
      byte_1AD206 = 0;
      sub_12A478(434, 264, dword_1AD1F0);
      sub_12A478(434, 60, dword_1AD1EC);
    }
  }
  else
  {
    sub_10A5E3(dword_1AD1E0, v0);
    v1 = sub_10A659(dword_1AD1E0);
    byte_1AD206 = 1;
    dword_1AD1E4 = v1;
    word_1AD202 = v0;
  }
  sub_10A21D(dword_1AD1E0, dword_1AD1E4);
  return sub_131B5D(191, 8, 32, 0, 40, 63, 8, 8);
}
// 1AD1E0: using guessed type int dword_1AD1E0;
// 1AD1E4: using guessed type int dword_1AD1E4;
// 1AD1E8: using guessed type int dword_1AD1E8;
// 1AD1EC: using guessed type int dword_1AD1EC;
// 1AD1F0: using guessed type int dword_1AD1F0;
// 1AD1FC: using guessed type int16_t word_1AD1FC;
// 1AD200: using guessed type int16_t word_1AD200;
// 1AD202: using guessed type int16_t word_1AD202;
// 1AD206: using guessed type char byte_1AD206;


//----- (00108611) --------------------------------------------------------
void __fastcall sub_108611(int a1, int a2, int a3)
{
  _BYTE *v3; // esi
  uint8_t *v4; // edi
  uint8_t v5; // al
  int v6; // eax
  uint8_t v7; // cl
  int v8; // [esp+0h] [ebp-8h]
  char *v9; // [esp+4h] [ebp-4h]

  v3 = *(_BYTE **)(a1 + 22);
  v4 = (uint8_t *)*(&off_183B0E + (int16_t)a2);
  v3[73] = 0;
  *(_BYTE *)(a1 + 21) = 1;
  v9 = v3 + 7;
  while ( (v4[1] & 8) == 0 )
  {
    if ( (v4[1] & 4) != 0 )
    {
      if ( v3[73] )
      {
        v9 += 158;
        v3 += 158;
        ++*(_BYTE *)(v8 + 21);
      }
      a2 = *v4;
      sub_249F9(aBilltex2Lbx, a2, v9, 64);
      v5 = *v4;
      v3[72] = 0;
      v3[73] = 0;
      a3 = 0;
      v3[71] = v5;
    }
    else
    {
      a2 = dword_192BD8;
      if ( *(_BYTE *)(dword_192BD8 + *v4 + 279) == 3 )
      {
        v6 = (uint16_t)a3;
        v7 = *v4;
        v3[(uint16_t)a3 + 126] = *v4;
        a2 += v7;
        LOBYTE(a2) = *(_BYTE *)(a2 + 279);
        ++a3;
        v3[v6 + 142] = a2;
        ++v3[73];
      }
    }
    v4 += 2;
  }
  if ( !v3[73] )
    --*(_BYTE *)(v8 + 21);
  sub_10A0A7(v8, (uint16_t)a2, a3);
  JUMPOUT(0x108023);
}
// 1086D1: control flows out of bounds to 108023
// 10865B: variable 'v8' is possibly undefined
// 183B0E: using guessed type _UNKNOWN *off_183B0E;
// 192BD8: using guessed type int dword_192BD8;


//----- (001086D6) --------------------------------------------------------
void __usercall sub_1086D6( unsigned int a1,
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
        int64_t a12,
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
        hr_int128_t a27)
{
  char v27; // dl
  char *v28; // esi
  char *v29; // edi
  char *v30; // esi
  char *v31; // edi
  char *v32; // esi
  char *v33; // edi
  int16_t v34; // dx
  int16_t v35; // ax
  int v36; // ecx
  char *v37; // ebx
  int v38; // [esp+76h] [ebp-12h]
  int16_t v39; // [esp+7Ah] [ebp-Eh]
  int16_t v40; // [esp+7Eh] [ebp-Ah]
  char v41; // [esp+81h] [ebp-7h] BYREF
  char v42[6]; // [esp+82h] [ebp-6h] BYREF

  if ( a1 >= word_199998 )
LABEL_40:
    JUMPOUT(0x1075A1);
  *(_DWORD *)((char *)&a27 + 6) = 0;
  *(_DWORD *)((char *)&a27 + 2) = 3753 * a1 + dword_197F98 + 2207;
  while ( 1 )
  {
    v27 = *(_BYTE *)(*(_DWORD *)((char *)&a27 + 2) + WORD3(a27));
    if ( !v27 && WORD3(a27) )
      goto LABEL_39;
    strcpy((char *)&a12 + 2, "^ ");
    if ( WORD3(a27) )
    {
      if ( WORD3(a27) == 15 )
      {
        if ( v27 >= 0 )
          v28 = (char *)dword_192190[WORD3(a27)];
        else
          v28 = (char *)dword_19220C;
      }
      else
      {
        v28 = (char *)dword_192190[WORD3(a27)];
      }
    }
    else
    {
      v28 = (char *)dword_192228[v27];
    }
    v29 = (char *)&a12 + 1;
    do
      ++v29;
    while ( *v29 );
    strcpy(v29, v28);
    if ( !WORD3(a27) || WORD3(a27) >= 0xAu )
    {
      v34 = v39;
      v35 = v40;
      v36 = v38;
      v37 = (char *)&a12 + 2;
      goto LABEL_38;
    }
    if ( WORD3(a27) >= 2u )
    {
      if ( WORD3(a27) <= 2u )
      {
        strcpy(v42, (char *)&a12 + 2);
        if ( v27 >= 0 )
        {
          if ( v27 == 2 )
            v32 = a1_1;
          else
            v32 = a2_1;
        }
        else
        {
          v32 = a05;
        }
LABEL_26:
        v33 = &v41;
        do
          ++v33;
        while ( *v33 );
        strcpy(v33, v32);
        goto LABEL_36;
      }
      if ( WORD3(a27) == 5 )
      {
        strcpy(v42, (char *)&a12 + 2);
        if ( v27 >= 0 )
          v30 = asc_17A2DA;
        else
          v30 = asc_17A2D8;
        v31 = &v41;
        do
          ++v31;
        while ( *v31 );
        strcpy(v31, v30);
        if ( v27 == 2 )
          v32 = a1Bc;
        else
          v32 = a05Bc;
        goto LABEL_26;
      }
    }
    sprintf(v42, "%s%+i", (char *)&a12 + 2, v27);
LABEL_36:
    v34 = v39;
    v35 = v40;
    v36 = v38;
    v37 = v42;
LABEL_38:
    sub_122A6E(v35, v34, (int)v37, v36);
    v39 += word_1B3EA2;
LABEL_39:
    ++*(_DWORD *)((char *)&a27 + 6);
    if ( WORD3(a27) >= 0x1Fu )
      goto LABEL_40;
  }
}
// 10889B: control flows out of bounds to 1075A1
// 108861: variable 'v39' is possibly undefined
// 108865: variable 'v40' is possibly undefined
// 108869: variable 'v38' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192190: using guessed type int dword_192190[31];
// 19220C: using guessed type int dword_19220C;
// 192228: using guessed type int dword_192228[];
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 1B3EA2: using guessed type int16_t word_1B3EA2;


//----- (001088A0) --------------------------------------------------------
char __fastcall sub_1088A0( int a1, int a2, unsigned int a3)
{
  int v4; // ecx
  int16_t v5; // di
  uint16_t v6; // bx
  unsigned int v7; // eax
  int v8; // edx
  int v9; // eax
  int16_t v10; // dx
  int v12; // [esp+0h] [ebp-10h]
  int16_t v13; // [esp+4h] [ebp-Ch]
  int v14; // [esp+8h] [ebp-8h]
  int16_t v15; // [esp+Ch] [ebp-4h]

  v4 = a2;
  v12 = dword_197F98 + 3753 * a3 + 2207;
  v5 = 443;
  v15 = a1 + 175;
  v13 = 442;
  v6 = 0;
  v14 = a2 + 9;
  do
  {
    LOBYTE(v7) = *(_BYTE *)(v12 + v6);
    if ( (_BYTE)v7 || !v6 )
    {
      if ( v6 )
      {
        if ( v6 == 15 )
        {
          if ( (v7 & 0x80u) == 0 )
            word_1ACFEC[5 * word_1AD1FA] = 457;
          else
            word_1ACFEC[5 * word_1AD1FA] = 458;
          goto LABEL_14;
        }
        if ( v6 >= 0xFu )
        {
          word_1ACFEC[5 * word_1AD1FA] = v5;
          goto LABEL_14;
        }
        v9 = 5 * word_1AD1FA;
        LOWORD(v8) = v13;
      }
      else
      {
        v8 = (char)v7 / 2 + 474;
        v9 = 5 * word_1AD1FA;
      }
      word_1ACFEC[v9] = v8;
LABEL_14:
      v7 = 10 * word_1AD1FA;
      word_1ACFEE[v7 / 2] = a1;
      word_1ACFF0[v7 / 2] = v4;
      ++word_1AD1FA;
      word_1ACFF2[v7 / 2] = v15;
      v10 = v14;
      v4 += 13;
      v14 += 13;
      word_1ACFF4[v7 / 2] = v10;
    }
    ++v13;
    ++v6;
    ++v5;
  }
  while ( v6 < 0x1Fu );
  return v7;
}
// 197F98: using guessed type int dword_197F98;
// 1ACFEC: using guessed type int16_t word_1ACFEC[];
// 1ACFEE: using guessed type int16_t word_1ACFEE[];
// 1ACFF0: using guessed type int16_t word_1ACFF0[];
// 1ACFF2: using guessed type int16_t word_1ACFF2[];
// 1ACFF4: using guessed type int16_t word_1ACFF4[];
// 1AD1FA: using guessed type int16_t word_1AD1FA;


//----- (001089C6) --------------------------------------------------------
int sub_1089C6()
{
  int v0; // eax
  _DWORD *v1; // ecx
  int v2; // eax
  int v3; // ecx
  _DWORD *v4; // eax
  uint16_t v5; // bx
  int v6; // ecx
  uint16_t v7; // bx
  int v8; // ecx
  int v9; // eax
  int16_t *v10; // ecx
  int16_t *v11; // edi
  int v12; // edi
  int v13; // esi
  int v14; // ecx
  int v15; // ebx
  int v16; // ebx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // edx
  int v21; // eax
  int v22; // eax
  int v24; // [esp+0h] [ebp-8Ah]
  int v25; // [esp+4h] [ebp-86h]
  int v26[8]; // [esp+8h] [ebp-82h] BYREF
  int64_t v27; // [esp+28h] [ebp-62h]
  int v28[10]; // [esp+30h] [ebp-5Ah] BYREF
  int v29[4]; // [esp+58h] [ebp-32h] BYREF
  hr_int128_t v30; // [esp+68h] [ebp-22h]
  char v31[40]; // [esp+80h] [ebp-Ah] BYREF
  char v32[64]; // [esp+A8h] [ebp+1Eh] BYREF
  _DWORD *v33; // [esp+E8h] [ebp+5Eh]
  int v34; // [esp+ECh] [ebp+62h]
  int16_t *v35; // [esp+F0h] [ebp+66h]
  int v36; // [esp+F4h] [ebp+6Ah]
  int v37; // [esp+F8h] [ebp+6Eh]
  int v38; // [esp+FCh] [ebp+72h]
  int v39; // [esp+100h] [ebp+76h]
  int v40; // [esp+104h] [ebp+7Ah]
  int v41; // [esp+108h] [ebp+7Eh]

  sub_249F9(aBilltextLbx, 14, (char *)v26, 40);
  sub_249F9(aBilltextLbx, 15, (char *)v29, 40);
  sub_249F9(aBilltextLbx, 16, (char *)v28, 40);
  sub_249F9(aBilltextLbx, 7, v31, 40);
  sub_1210FD(416, 31, (int)v31);
  sub_109FBA(v25);
  byte_199BA3[0] = word_19999C;
  sub_102597(1, 1);
  v0 = sub_12DAA4(183, 20);
  v1 = sub_110D3C(dword_192ED4, v0);
  v33 = v1;
  sub_12D8F5(183, 20, (int)v1);
  sub_120D79(2, (int)&unk_183B2E);
  v40 = 0;
  sub_1229C5(91, 2, (int)v26, (int)v1);
  do
  {
    v2 = sub_12DAA4(183, 164);
    v3 = (uint16_t)v40;
    v4 = sub_110D3C(dword_192ED4, v2);
    v37 = 4 * v3;
    *(_DWORD *)&v32[v37 + 32] = v4;
    sub_12D8F5(183, 164, (int)v4);
    if ( v3 >= word_199934 )
    {
      v8 = v37;
      sub_120BB5(4, (int)&unk_183B1E);
      sub_1229C5(91, 0, (int)v29, *(_DWORD *)&v32[v8 + 32]);
    }
    else
    {
      v5 = (uint8_t)byte_199BA3[v3];
      sub_120BB5(4, dword_1ACFC0[(uint8_t)byte_199BA3[v3]]);
      v36 = v5;
      v6 = v37;
      strcpy(v32, (char *)(3753 * v5 + dword_197F98 + 21));
      strupr(v32);
      sub_1229C5(91, 0, (int)v32, *(_DWORD *)&v32[v6 + 32]);
      v7 = v36;
      sub_120BB5(2, dword_1ACFC0[v36]);
      sub_1086D6(
        v7,
        v24,
        v25,
        v26[0],
        v26[1],
        v26[2],
        v26[3],
        v26[4],
        v26[5],
        v26[6],
        v26[7],
        v27,
        v28[0],
        v28[1],
        v28[2],
        v28[3],
        v28[4],
        v28[5],
        v28[6],
        v28[7],
        v28[8],
        v28[9],
        v29[0],
        v29[1],
        v29[2],
        v29[3],(int)LODWORD(v30));
    }
    ++v40;
  }
  while ( (uint16_t)v40 < 8u );
  if ( word_199934 > 4 )
    sub_1151B0(385, 427, (int)&unk_17A28B, *(_WORD **)(v25 + 80), &unk_17A28B, 40);
  sub_1191CA((int)nullsub_17, 2);
  v9 = (int)&unk_183CEB;
  v35 = (int16_t *)&unk_183CEB;
  do
  {
    word_1AD1FA = 0;
    v10 = word_183CA7;
    v11 = v35;
    while ( v10 < v11 )
    {
      v9 = sub_109E01(v10);
      v10 = (int16_t *)((char *)v10 + 17);
    }
    if ( byte_1AD209 == 1 )
      v12 = 0;
    else
      v12 = 4;
    v41 = 0;
    do
    {
      v13 = (uint16_t)v41;
      LOWORD(v9) = word_183E57[v13];
      v39 = v9;
      LOWORD(v9) = word_183E5F[v13];
      v38 = v9;
      sub_134D2D(
        (int16_t)(v39 + 10),
        (int16_t)(v9 + 17),
        (int16_t)(v39 + 173),
        (int16_t)(v9 + 17),
        (uint8_t)byte_183B24);
      v14 = (uint16_t)v12;
      v15 = *(_DWORD *)&v32[4 * (uint16_t)v12 + 32];
      v34 = (int16_t)v39;
      sub_12A478(v39, v38, v15);
      v16 = (uint8_t)byte_199BA3[(uint16_t)v12];
      v36 = 3753 * v16;
      if ( *(_BYTE *)(3753 * v16 + dword_197F98 + 36) )
      {
        v16 = (int)v33;
        v9 = sub_12A478(v34, v38 + 11, (int)v33);
      }
      else
      {
        v9 = word_199934;
        if ( (uint16_t)v12 < word_199934 )
          sub_1088A0(word_183E57[v13], (int16_t)(word_183E5F[v13] + 22), v16);
      }
      ++v41;
      ++v12;
    }
    while ( (uint16_t)v41 < 4u );
    v17 = 5 * word_1AD1FA;
    word_1ACFEC[v17] = 242;
    word_1ACFEE[v17] = 0;
    word_1ACFF0[v17] = 40;
    word_1ACFF2[v17] = 205;
    ++word_1AD1FA;
    word_1ACFF4[v17] = 197;
    v18 = 5 * word_1AD1FA;
    word_1ACFEC[v18] = 243;
    word_1ACFEE[v18] = 0;
    word_1ACFF0[v18] = 198;
    word_1ACFF2[v18] = 205;
    ++word_1AD1FA;
    word_1ACFF4[v18] = 479;
    v19 = 5 * word_1AD1FA;
    word_1ACFEC[v19] = 248;
    word_1ACFEE[v19] = 206;
    word_1ACFF0[v19] = 0;
    word_1ACFF2[v19] = 639;
    ++word_1AD1FA;
    word_1ACFF4[v19] = 479;
    sub_1196F7();
    v20 = word_1AD1FA;
    sub_1196B8((int)word_1ACFEC, word_1AD1FA);
    sub_124DEC();
    sub_109DB5(v16, (int16_t *)v12);
    do
    {
      v9 = sub_1171AB(v9, v20, v16, v14);
      v20 = v9;
      if ( word_19994C )
      {
        v21 = 0;
        return nullsub_17(v21, v20);
      }
      if ( (int16_t)v9 < (int16_t)v24 )
      {
        if ( !(_WORD)v9 )
        {
          sub_12C2A0();
          sub_1077D(v22, v20, v16, (int16_t *)v12);
          v9 = sub_12C2C6(2);
        }
      }
      else
      {
        LOBYTE(v9) = byte_1AD209 == 0;
        byte_1AD209 = byte_1AD209 == 0;
      }
    }
    while ( !(_WORD)v20 );
  }
  while ( (int16_t)v20 >= (int16_t)v24 );
  v21 = v20;
  return nullsub_17(v21, v20);
}
// 108A4D: variable 'v25' is possibly undefined
// 108B9B: variable 'v24' is possibly undefined
// 108C64: variable 'v9' is possibly undefined
// 108E34: variable 'v22' is possibly undefined
// 108E62: using guessed type int __fastcall nullsub_17(_DWORD, _DWORD);
// 13EE59: using guessed type int __fastcall strupr(_DWORD);
// 183B24: using guessed type char byte_183B24;
// 183CA7: using guessed type int16_t word_183CA7[34];
// 183E57: using guessed type int16_t word_183E57[];
// 183E5F: using guessed type int16_t word_183E5F[];
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 199934: using guessed type int16_t word_199934;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 1ACFC0: using guessed type int dword_1ACFC0[];
// 1ACFEC: using guessed type int16_t word_1ACFEC[];
// 1ACFEE: using guessed type int16_t word_1ACFEE[];
// 1ACFF0: using guessed type int16_t word_1ACFF0[];
// 1ACFF2: using guessed type int16_t word_1ACFF2[];
// 1ACFF4: using guessed type int16_t word_1ACFF4[];
// 1AD1FA: using guessed type int16_t word_1AD1FA;
// 1AD209: using guessed type char byte_1AD209;


//----- (00108E63) --------------------------------------------------------
int __fastcall sub_108E63(int result, int a2, unsigned int a3)
{
  int16_t v3; // cx
  int64_t v4[32]; // [esp+0h] [ebp-100h] BYREF

  v3 = result;
  if ( a3 <= 0xFAu )
  {
    sub_120E24(10);
    sub_EEC98(v4[0]);
    sub_1212B3(v3, a2, (int)asc_17A2F9);
    return sub_103BC4(v3 + 13, a2, 345, (int)v4, 0);
  }
  return result;
}


//----- (00108EC3) --------------------------------------------------------
int __fastcall sub_108EC3(int result, int a2, int a3, int a4)
{
  int v4; // esi
  _BYTE *v5; // ebx
  int v6; // eax
  uint16_t v7; // cx
  int16_t v8; // ax
  int v9; // edx
  int v10; // eax
  int v11; // edi
  int64_t v12[32]; // [esp+0h] [ebp-10Ch] BYREF
  int v13; // [esp+100h] [ebp-Ch]
  int v14; // [esp+104h] [ebp-8h]
  int v15; // [esp+108h] [ebp-4h]

  v4 = result;
  v14 = a3;
  v13 = a4;
  if ( (_WORD)a2 )
  {
    v5 = *(_BYTE **)(result + 22);
    *(_BYTE *)(result + 21) = a2;
    LOWORD(v6) = sub_EEBF8(word_19999C);
    v7 = v6;
    v15 = a2 + v6;
    sub_120BB5((uint16_t)v14, (int)&unk_183B1E);
    sub_120E24((int16_t)v13);
    do
    {
      v5[7] = 0;
      v5[72] = 0;
      v5[71] = v7;
      v5[126] = v7;
      sub_EEC98(v12[0]);
      v8 = sub_103CAF(*(_WORD *)(v4 + 4), (int)v12);
      v9 = v8 % (int)(uint16_t)v13;
      v5[73] = v8 / (int)(uint16_t)v13;
      v10 = 0;
      do
      {
        v11 = (int16_t)v10++;
        v5[v11 + 142] = 0;
        v5[(int16_t)v10 + 126] = -1;
        LOWORD(v9) = (uint8_t)v5[73];
      }
      while ( (int16_t)v10 < (int16_t)v9 );
      ++v7;
      v5 += 158;
    }
    while ( v7 < (uint16_t)v15 );
    return sub_10A0A7(v4, v9, (int)v5);
  }
  return result;
}
// 108EF5: variable 'v6' is possibly undefined
// 19999C: using guessed type int16_t word_19999C;


//----- (00108F81) --------------------------------------------------------
int __fastcall sub_108F81(int a1, int a2)
{
  int v2; // eax

  v2 = sub_108EC3(a1, a2, 4, 10);
  return nullsub_18(v2);
}
// 108F97: using guessed type int __fastcall nullsub_18(_DWORD);


//----- (00108F98) --------------------------------------------------------
void __fastcall sub_108F98(int a1, int a2)
{
  int16_t *v3; // eax
  int16_t *v4; // edi
  char *v5; // ebx
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int16_t v10; // ax
  int16_t v11; // dx
  int v12; // edx
  void *v13; // eax
  int v14; // eax
  char v15; // [esp+0h] [ebp-3DD6h] BYREF
  char v16[64]; // [esp+3DB8h] [ebp-1Eh] BYREF
  char v17[40]; // [esp+3DF8h] [ebp+22h] BYREF
  char v18[40]; // [esp+3E20h] [ebp+4Ah] BYREF
  int16_t *v19; // [esp+3E48h] [ebp+72h]
  char *v20; // [esp+3E4Ch] [ebp+76h]
  int v21; // [esp+3E50h] [ebp+7Ah]
  char *v22; // [esp+3E54h] [ebp+7Eh]

  v21 = a2;
  sub_249F9(aBilltextLbx, 16, v17, 40);
  sub_249F9(aBilltextLbx, 8, v18, 40);
  sub_1210FD(416, 31, (int)v18);
  sub_249F9(aBilltextLbx, 26, v16, 60);
  sub_24E54(v16, 60);
  LOWORD(v3) = sub_EEC02(word_19999C);
  v4 = v3;
  v19 = v3;
  if ( (int16_t)v3 > 0 )
  {
    v20 = sub_1151B0(592, 84, (int)&unk_17A28B, *(_WORD **)(a1 + 56), asc_17A289, 40);
    v22 = sub_1151B0(592, 395, (int)&unk_17A28B, *(_WORD **)(a1 + 60), asc_17A289, 40);
    dword_183EB9 = (int)&v15;
    sub_108EC3((int)&unk_183EA3, (int16_t)v4, 4, 10);
    dword_1ACFE8 = sub_10A5A3((int)&unk_183EA3, byte_1AD208);
  }
LABEL_3:
  sub_109E01(word_183CEB);
  sub_120BB5(4, (int)&unk_183B1E);
  sub_1210FD(414, 66, (int)v16);
  sub_134D2D(238, 81, 580, 81, 184);
  sub_12A478(592, 84, *(_DWORD *)(a1 + 48));
  sub_12A478(592, 395, *(_DWORD *)(a1 + 52));
  if ( (_WORD)v19 )
  {
    v9 = (int16_t)v22;
    sub_119400((int16_t)v22);
    word_1AD1FC = sub_113E65();
    sub_10A188((int)&unk_183EA3);
    word_1AD200 = v10;
    v11 = (int16_t)v20;
    sub_10A4A7((int)&unk_183EA3);
    sub_10A689((int)&unk_183EA3, v11, v9);
    v12 = 2;
    sub_1191CA((int)sub_1092BD, 2);
    sub_124DEC();
    sub_109DB5(v9, v4);
    while ( 1 )
    {
      v13 = (void *)sub_1171AB((int)v13, v12, v9, 81);
      v12 = (int)v13;
      if ( word_19994C )
        break;
      if ( (int16_t)v13 < word_1AD1FC || (int16_t)v13 > word_1AD200 )
      {
        if ( (int16_t)v13 < (int16_t)v21 || (int16_t)v19 <= 0 )
        {
          if ( !(_WORD)v13 )
          {
            sub_12C2A0();
            sub_1092BD();
            sub_1077D(v14, v12, v9, v4);
            v13 = (void *)sub_12C2C6(2);
          }
        }
        else
        {
          if ( (_WORD)v13 == (_WORD)v22 )
          {
            v13 = &unk_183EA3;
            LOBYTE(v13) = sub_10A527((int)&unk_183EA3);
            if ( (_BYTE)v13 )
              goto LABEL_3;
          }
          if ( (_WORD)v12 == (_WORD)v20 )
          {
            LOBYTE(v13) = sub_10A540((int)&unk_183EA3);
            if ( (_BYTE)v13 )
              goto LABEL_3;
          }
        }
      }
      else
      {
        v9 = dword_1ACFE8;
        LOBYTE(v13) = sub_EF6F0(&byte_1AA414[18 * *(uint8_t *)(dword_1ACFE8 + 71)]);
        if ( (_BYTE)v13 )
        {
          v9 = dword_1ACFE8;
          word_199A08 = 1;
          word_199A10 = 9;
          LOBYTE(v13) = *(_BYTE *)(dword_1ACFE8 + 71);
          LOWORD(v12) = word_1AD204;
          byte_1AD208 = (char)v13;
        }
      }
      if ( (_WORD)v12 && (int16_t)v12 < (int16_t)v21 )
LABEL_28:
        JUMPOUT(0x108E55);
    }
  }
  else
  {
    v5 = v17;
    sub_120BB5(4, (int)&unk_183B1E);
    sub_1210FD(414, 216, (int)v17);
    v6 = 2;
    sub_1191CA((int)nullsub_18, 2);
    sub_124DEC();
    sub_109DB5((int)v17, v4);
    while ( 1 )
    {
      v5 = (char *)sub_1171AB(v7, v6, (int)v5, 81);
      v6 = (int)v5;
      if ( word_19994C )
        break;
      sub_12C2A0();
      sub_1077D(v8, (int)v5, (int)v5, v4);
      v7 = sub_12C2C6(2);
      if ( (_WORD)v5 )
        goto LABEL_28;
    }
  }
  JUMPOUT(0x108E57);
}
// 10915F: control flows out of bounds to 108E57
// 10917D: control flows out of bounds to 108E55
// 10901B: variable 'v3' is possibly undefined
// 10914A: variable 'v7' is possibly undefined
// 109169: variable 'v8' is possibly undefined
// 1091A2: variable 'v10' is possibly undefined
// 1091D9: variable 'v13' is possibly undefined
// 109296: variable 'v14' is possibly undefined
// 24E54: using guessed type int __fastcall sub_24E54(_DWORD, _DWORD);
// 108F97: using guessed type int nullsub_18();
// 183CEB: using guessed type int16_t word_183CEB[8];
// 183EB9: using guessed type int dword_183EB9;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 1AA414: using guessed type _BYTE byte_1AA414[1800];
// 1ACFE8: using guessed type int dword_1ACFE8;
// 1AD1FC: using guessed type int16_t word_1AD1FC;
// 1AD200: using guessed type int16_t word_1AD200;
// 1AD204: using guessed type int16_t word_1AD204;
// 1AD208: using guessed type char byte_1AD208;


//----- (001092BD) --------------------------------------------------------
void sub_1092BD()
{
  int16_t v0; // ax

  off_183ECF = &unk_183B26;
  v0 = (uint16_t)sub_114177();
  if ( v0 >= word_1AD1FC && v0 <= word_1AD200 )
    sub_10A5E3((int)&unk_183EA3, v0);
  dword_1ACFE8 = sub_10A659((int)&unk_183EA3);
  sub_10A3AD((int)&unk_183EA3, dword_1ACFE8);
  off_183ECF = &unk_183B1E;
  JUMPOUT(0x108608);
}
// 10932C: control flows out of bounds to 108608
// 183ECF: using guessed type _UNKNOWN *off_183ECF;
// 1ACFE8: using guessed type int dword_1ACFE8;
// 1AD1FC: using guessed type int16_t word_1AD1FC;
// 1AD200: using guessed type int16_t word_1AD200;


//----- (00109331) --------------------------------------------------------
void __fastcall sub_109331(int a1)
{
  char v2[40]; // [esp+0h] [ebp-28h] BYREF

  sub_249F9(aBilltextLbx, 9, v2, 40);
  sub_1210FD(416, 31, (int)v2);
  sub_120BB5(4, (int)&unk_183B1E);
  if ( byte_1AD207 )
  {
    if ( (uint8_t)byte_1AD207 <= 1u )
    {
      sub_1039B9();
      sub_10988E();
    }
    else
    {
      if ( byte_1AD207 != 2 )
        JUMPOUT(0x107FEE);
      sub_1039C8();
      sub_109762(a1);
    }
  }
  else
  {
    sub_103990();
    sub_1093CD();
  }
  JUMPOUT(0x108023);
}
// 109384: control flows out of bounds to 107FEE
// 1093A0: control flows out of bounds to 108023
// 1AD207: using guessed type char byte_1AD207;


//----- (001093CD) --------------------------------------------------------
void sub_1093CD()
{
  int16_t *v0; // edx
  int v1; // ecx
  int v2; // ebx
  int v3; // eax
  int16_t v4; // ax
  uint16_t v5; // si
  int v6; // edi
  _OWORD *v7; // ebx
  int64_t v8; // rax
  int16_t *v9; // edi
  uint16_t v10; // si
  char *v11; // eax
  _OWORD *v12; // ebx
  int64_t v13; // rax
  void *v14; // edx
  int v15; // eax
  int v16; // eax
  int16_t v17; // ax
  int v18; // eax
  char *v19; // [esp-4h] [ebp-64Ah]
  int16_t v20; // [esp+0h] [ebp-646h]
  _OWORD v21[48]; // [esp+4h] [ebp-642h] BYREF
  _OWORD v22[52]; // [esp+304h] [ebp-342h] BYREF
  char v23[76]; // [esp+644h] [ebp-2h] BYREF
  char v24[20]; // [esp+690h] [ebp+4Ah] BYREF
  _DWORD *v25; // [esp+6A4h] [ebp+5Eh]
  int v26; // [esp+6A8h] [ebp+62h]
  int v27; // [esp+6ACh] [ebp+66h]
  int v28; // [esp+6B0h] [ebp+6Ah]
  int v29; // [esp+6B4h] [ebp+6Eh]
  int v30; // [esp+6B8h] [ebp+72h]
  int v31; // [esp+6BCh] [ebp+76h]
  int v32; // [esp+6C0h] [ebp+7Ah]
  int v33; // [esp+6C4h] [ebp+7Eh]

  v0 = (int16_t *)&unk_183CFC;
  dword_1ACFE0 = (int)v22;
  dword_1ACFE4 = (int)v21;
  while ( v0 < word_183D40 )
  {
    sub_109E01(v0);
    v0 = (int16_t *)((char *)v0 + 17);
  }
  sub_249F9(aBilltextLbx, 10, v23, 40);
  v1 = 40;
  sub_1212B3(224, 67, (int)v23);
  sub_249F9(aBilltextLbx, 11, v23, 40);
  v2 = (int)v23;
  sub_1212B3(424, 67, (int)v23);
  if ( byte_199CAE == 1 || byte_199CAE == 2 )
    v3 = 3;
  else
    v3 = 4;
  sub_120BB5(v3, (int)&unk_183B1E);
  v4 = sub_113E65();
  v31 = 100;
  v27 = 0;
  v5 = 1;
  v33 = 98;
  v6 = 118;
  word_1AD1F6 = v4;
  do
  {
    if ( *(_BYTE *)dword_192C08[v5] > 0x39u )
    {
      v19 = (char *)dword_192C08[v5];
      v26 = (uint16_t)v27;
      v7 = &v22[3 * (uint16_t)v27];
      v1 = (int16_t)v6;
      v8 = sprintf(v7, "^ %s", v19);
      v31 += 20;
      sub_1212B3(221, SWORD2(v8), (int)v7);
      v2 = 411;
      v6 += 20;
      sub_11438B(221, v33, 411, v1, &unk_17A28B, 0);
      ++v27;
      v33 += 20;
      *(_WORD *)&v23[2 * v26 + 40] = v5;
    }
    ++v5;
  }
  while ( v5 < 0x11u );
  v30 = 100;
  v29 = 98;
  v28 = 118;
  v9 = 0;
  v25 = sub_110D3C(dword_192ED4, 84);
  word_1AD1F4 = sub_113E65();
  sub_A6547(v24);
  v10 = 0;
  v32 = sub_127233((int)v24, 15, v2, v1);
  while ( v10 < (uint16_t)v32 )
  {
    v11 = (char *)sub_126BDD((int)v24, 15, (int)v25, (int16_t)v10++, 1u, 84);
    *((_DWORD *)&v22[48] + (uint16_t)v9) = *((_DWORD *)v11 + 20);
    v30 += 20;
    v12 = &v21[3 * (uint16_t)v9];
    v9 = (int16_t *)((char *)v9 + 1);
    v1 = (int16_t)v28;
    v13 = sprintf(v12, "^ %s", v11);
    v28 += 20;
    sub_1212B3(421, SWORD2(v13), (int)v12);
    WORD2(v13) = v29;
    v2 = 611;
    v29 += 20;
    sub_11438B(421, SWORD2(v13), 611, v1, &unk_17A28B, 0);
  }
  sub_124DEC();
  sub_1191CA((int)sub_1096D9, 2);
  sub_109DB5(v2, v9);
  if ( byte_199CAE == 1 || byte_199CAE == 2 )
  {
    v14 = &unk_183B26;
    v15 = 3;
  }
  else
  {
    v14 = &unk_183B26;
    v15 = 4;
  }
  v16 = sub_120BB5(v15, (int)&unk_183B26);
  while ( 1 )
  {
    v16 = sub_1171AB(v16, (int)v14, v2, v1);
    v14 = (void *)v16;
    if ( word_19994C )
      goto LABEL_31;
    if ( (int16_t)v16 >= v20 )
      break;
    if ( !(_WORD)v16 )
    {
      sub_12C2A0();
      sub_1096D9();
      sub_1077D(v18, (int)v14, v2, v9);
      v16 = sub_12C2C6(2);
    }
    if ( (_WORD)v14 && (int16_t)v14 < v20 )
      JUMPOUT(0x108E55);
  }
  if ( (int16_t)v16 < word_1AD1F4 )
  {
    v17 = *(_WORD *)&v23[2 * ((int16_t)v16 - word_1AD1F6) + 40];
    byte_1AD207 = 1;
  }
  else
  {
    v17 = *((_WORD *)&v22[48] + 2 * ((int16_t)v16 - word_1AD1F4));
    byte_1AD207 = 2;
  }
  word_1AD1F8 = v17;
LABEL_31:
  JUMPOUT(0x108E57);
}
// 10964F: control flows out of bounds to 108E57
// 1096D4: control flows out of bounds to 108E55
// 10965B: variable 'v20' is possibly undefined
// 1096AF: variable 'v18' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 183D40: using guessed type int16_t word_183D40[17];
// 192C08: using guessed type int dword_192C08[];
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 199CAE: using guessed type char byte_199CAE;
// 1ACFE0: using guessed type int dword_1ACFE0;
// 1ACFE4: using guessed type int dword_1ACFE4;
// 1AD1F4: using guessed type int16_t word_1AD1F4;
// 1AD1F6: using guessed type int16_t word_1AD1F6;
// 1AD1F8: using guessed type int16_t word_1AD1F8;
// 1AD207: using guessed type char byte_1AD207;


//----- (001096D9) --------------------------------------------------------
void sub_1096D9()
{
  int16_t v0; // ax
  int16_t v1; // ax
  int v2; // ebx
  int16_t v3; // dx
  int16_t v4; // ax
  int16_t v5; // ax

  v0 = (uint16_t)sub_114177();
  if ( v0 < word_1AD1F4 )
  {
    if ( v0 < word_1AD1F6 )
      goto LABEL_6;
    v5 = v0 - word_1AD1F6;
    v2 = 48 * v5 + dword_1ACFE0;
    v3 = 20 * v5 + 100;
    v4 = 221;
  }
  else
  {
    v1 = v0 - word_1AD1F4;
    v2 = 48 * v1 + dword_1ACFE4;
    v3 = 20 * v1 + 100;
    v4 = 421;
  }
  sub_1212B3(v4, v3, v2);
LABEL_6:
  JUMPOUT(0x108608);
}
// 10975D: control flows out of bounds to 108608
// 1ACFE0: using guessed type int dword_1ACFE0;
// 1ACFE4: using guessed type int dword_1ACFE4;
// 1AD1F4: using guessed type int16_t word_1AD1F4;
// 1AD1F6: using guessed type int16_t word_1AD1F6;


//----- (00109762) --------------------------------------------------------
void __fastcall sub_109762(int a1)
{
  int16_t *v1; // edx
  char *v2; // esi
  char *v3; // edi
  _WORD *v4; // ecx
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // [esp+0h] [ebp-6Ch] BYREF
  int16_t v9[40]; // [esp+4h] [ebp-68h] BYREF
  char v10[20]; // [esp+54h] [ebp-18h] BYREF
  char *v11; // [esp+68h] [ebp-4h]

  v8 = a1;
  v1 = word_183D40;
  sub_A6547(v10);
  while ( v1 < word_183D62 )
  {
    sub_109E01(v1);
    v1 = (int16_t *)((char *)v1 + 17);
  }
  v2 = (char *)sub_126C37((int)v10, 0, dword_192ED4, word_1AD1F8, 1u, 1403);
  v11 = v2;
  sub_249F9(aBilltextLbx, 13, (char *)v9, 80);
  v3 = (char *)&v8 + 3;
  do
    ++v3;
  while ( *v3 );
  strcpy(v3, v2);
  sub_1210FD(414, 67, (int)v9);
  if ( byte_199CAE == 1 || byte_199CAE == 2 )
    sub_120BB5(3, (int)&unk_183B1E);
  sub_103BC4(0xE0u, 0x63u, 381, (int)(v11 + 103), 3);
  sub_124DEC();
  v4 = *(_WORD **)(v8 + 84);
  sub_1151B0(386, 427, (int)&unk_17A28B, v4, &unk_17A28B, 40);
  v5 = 2;
  sub_1191CA((int)nullsub_18, 2);
  byte_1AD207 = 0;
  sub_109DB5((int)&unk_17A28B, v9);
  while ( 1 )
  {
    v7 = sub_1171AB(v6, v5, (int)&unk_17A28B, (int)v4);
    v5 = v7;
    if ( (_WORD)v7 || word_19994C )
      break;
    v6 = sub_1077D(v7, v7, (int)&unk_17A28B, v9);
  }
  JUMPOUT(0x108021);
}
// 109873: control flows out of bounds to 108021
// 109869: variable 'v6' is possibly undefined
// 108F97: using guessed type int nullsub_18();
// 183D40: using guessed type int16_t word_183D40[17];
// 183D62: using guessed type int16_t word_183D62[8];
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 199CAE: using guessed type char byte_199CAE;
// 1AD1F8: using guessed type int16_t word_1AD1F8;
// 1AD207: using guessed type char byte_1AD207;


//----- (0010988E) --------------------------------------------------------
void sub_10988E()
{
  char *v0; // edi
  int v1; // eax
  int v2; // ebx
  char *v3; // eax
  int v4; // ecx
  int v5; // edx
  char *v6; // ebx
  char *v7; // ebx
  int v8; // edx
  int v9; // eax
  char *v10; // ecx
  int v11; // eax
  int16_t *v12; // edi
  _WORD *v13; // ecx
  int16_t *v14; // edx
  char *v15; // ebx
  int v16; // ebx
  int16_t v17; // ax
  int16_t v18; // ax
  int v19; // edx
  unsigned int v20; // eax
  int v21; // eax
  _DWORD *v22; // esi
  int v23; // eax
  int v24; // eax
  int v25; // [esp+0h] [ebp-2602h]
  _BYTE v26[9719]; // [esp+4h] [ebp-25FEh] BYREF
  char v27; // [esp+25FBh] [ebp-7h] BYREF
  char v28[80]; // [esp+25FCh] [ebp-6h] BYREF
  char v29[20]; // [esp+264Ch] [ebp+4Ah] BYREF
  char *v30; // [esp+2660h] [ebp+5Eh]
  int v31; // [esp+2664h] [ebp+62h]
  _DWORD *v32; // [esp+2668h] [ebp+66h]
  char *v33; // [esp+266Ch] [ebp+6Ah]
  int16_t v34; // [esp+2670h] [ebp+6Eh]
  uint16_t v35; // [esp+2674h] [ebp+72h]
  int i; // [esp+2678h] [ebp+76h]
  int j; // [esp+267Ch] [ebp+7Ah]
  char *v38; // [esp+2680h] [ebp+7Eh]

  sub_109E01(word_183D62);
  sub_249F9(aBilltextLbx, 12, v28, 80);
  v0 = &v27;
  do
    ++v0;
  while ( *v0 );
  strcpy(v0, (char *)dword_192C08[word_1AD1F8]);
  sub_1210FD(416, 67, (int)v28);
  dword_183EFD = (int)v26;
  v1 = sub_12DAA4(190, 314);
  v2 = dword_192ED4;
  dword_1AD1F0 = (int)sub_110D3C(dword_192ED4, v1);
  v32 = sub_110D3C(dword_192ED4, 1404);
  sub_A6547(v29);
  v34 = sub_127233((int)v29, word_1AD1F8, v2, 80);
  v35 = 0;
  byte_183EFC = v34;
  do
  {
    v3 = (char *)sub_126BDD((int)v29, word_1AD1F8, (int)v32, (int16_t)v35, 1u, 84);
    v4 = v35;
    v5 = 158 * v35;
    v6 = v3;
    strcpy(&v26[v5 + 7], v3);
    v7 = (char *)*((_DWORD *)v6 + 20);
    v26[v5 + 72] = 0;
    LOBYTE(v3) = v35;
    v26[v5 + 73] = 1;
    ++v35;
    v26[v5 + 71] = (_BYTE)v3;
    v8 = v35;
    v9 = v34;
    *(_DWORD *)&v26[4 * v4 + 9480] = v7;
  }
  while ( v8 < v9 );
  for ( i = 0; (int16_t)i < (int)v35; ++i )
  {
    for ( j = 0; ; ++j )
    {
      v31 = (int16_t)j;
      if ( v35 - 1 <= (int16_t)j )
        break;
      v7 = &v26[158 * (int16_t)j + 165];
      v10 = &v26[158 * v31 + 7];
      if ( strcmp(v10, v7) > 0 )
      {
        strcpy(v28, v10);
        strcpy(v10, v7);
        strcpy(v7, v28);
        v11 = v31;
        v7 = *(char **)&v26[4 * v31 + 9480];
        *(_DWORD *)&v26[4 * v31 + 9480] = *(_DWORD *)&v26[4 * v31 + 9484];
        *(_DWORD *)&v26[4 * v11 + 9484] = v7;
      }
    }
  }
  sub_10A0A7((int)&unk_183EE7, (int16_t)i, (int)v7);
  v33 = sub_1151B0(386, 427, (int)&unk_17A28B, *(_WORD **)(v25 + 84), &unk_17A28B, 40);
  v12 = (int16_t *)sub_1151B0(398, 96, (int)&unk_17A28B, *(_WORD **)(v25 + 56), asc_17A289, 40);
  v13 = *(_WORD **)(v25 + 60);
  v38 = sub_1151B0(398, 396, (int)&unk_17A28B, v13, asc_17A289, 40);
  sub_1191CA((int)sub_109D25, 2);
  byte_1AD207 = 0;
  v30 = byte_183D95;
  while ( 1 )
  {
    v14 = (int16_t *)&unk_183D73;
    v15 = v30;
    while ( v14 < (int16_t *)v15 )
    {
      sub_109E01(v14);
      v14 = (int16_t *)((char *)v14 + 17);
    }
    sub_12A478(398, 96, *(_DWORD *)(v25 + 48));
    sub_12A478(398, 396, *(_DWORD *)(v25 + 52));
    v16 = (int16_t)v38;
    sub_10A4A7((int)&unk_183EE7);
    sub_124DEC();
    sub_119400(v16);
    word_1AD1FC = sub_113E65();
    sub_10A188((int)&unk_183EE7);
    word_1AD200 = v17;
    sub_10A689((int)&unk_183EE7, (int16_t)v12, v16);
    v18 = (uint16_t)sub_114177();
    word_1AD202 = v18;
    if ( v18 < word_1AD1FC || v18 > word_1AD200 )
      word_1AD202 = word_1AD1FC;
    v19 = word_1AD202;
    sub_10A5E3((int)&unk_183EE7, word_1AD202);
    v20 = sub_10A659((int)&unk_183EE7);
    byte_1AD206 = 1;
    dword_1AD1E4 = v20;
    sub_109DB5(v16, v12);
    while ( 1 )
    {
      sub_12C2A0();
      if ( byte_1AD206 )
      {
        sub_12D8F5(190, 314, dword_1AD1F0);
        v22 = sub_126BDD(
                (int)v29,
                0,
                (int)v32,
                (int16_t)*(_DWORD *)&v26[4 * *(uint8_t *)(dword_1AD1E4 + 71) + 9480],
                1u,
                1403);
        sub_120BB5(4, (int)&unk_183B1E);
        sub_1032D8(dword_1AD1F0);
        v16 = 186;
        sub_120BB5(3, (int)&unk_183B1E);
        v13 = (_WORD *)((char *)v22 + 103);
        v19 = 64;
        v21 = sub_103BE2(0, 0x40u, 186, (int)v22 + 103, 3, dword_1AD1F0);
      }
      v23 = sub_1171AB(v21, v19, v16, (int)v13);
      v19 = v23;
      if ( word_19994C )
        JUMPOUT(0x108E57);
      if ( (_WORD)v23 == (_WORD)v38 && sub_10A527((int)&unk_183EE7)
        || (_WORD)v19 == (_WORD)v12 && sub_10A540((int)&unk_183EE7) )
      {
        break;
      }
      if ( (_WORD)v19 )
      {
        if ( (int16_t)v19 <= (int16_t)v33 )
          JUMPOUT(0x108E55);
      }
      else
      {
        sub_109D25();
        sub_1077D(v24, v19, v16, v12);
        sub_12C2C6(2);
      }
    }
  }
}
// 109CC0: control flows out of bounds to 108E57
// 109D20: control flows out of bounds to 108E55
// 109AB2: variable 'v25' is possibly undefined
// 109BA5: variable 'v17' is possibly undefined
// 109CAD: variable 'v21' is possibly undefined
// 109CFE: variable 'v24' is possibly undefined
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 183D62: using guessed type int16_t word_183D62[8];
// 183EFC: using guessed type char byte_183EFC;
// 183EFD: using guessed type int dword_183EFD;
// 192C08: using guessed type int dword_192C08[];
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 1AD1E4: using guessed type int dword_1AD1E4;
// 1AD1F0: using guessed type int dword_1AD1F0;
// 1AD1F8: using guessed type int16_t word_1AD1F8;
// 1AD1FC: using guessed type int16_t word_1AD1FC;
// 1AD200: using guessed type int16_t word_1AD200;
// 1AD202: using guessed type int16_t word_1AD202;
// 1AD206: using guessed type char byte_1AD206;
// 1AD207: using guessed type char byte_1AD207;


//----- (00109D25) --------------------------------------------------------
void sub_109D25()
{
  int16_t v0; // bx
  unsigned int v1; // eax

  v0 = (uint16_t)sub_114177();
  if ( sub_124075() || byte_1AD206 || v0 < word_1AD1FC || v0 > word_1AD200 || v0 == word_1AD202 )
  {
    byte_1AD206 = 0;
    sub_12A478(422, 96, dword_1AD1F0);
  }
  else
  {
    sub_10A5E3((int)&unk_183EE7, v0);
    v1 = sub_10A659((int)&unk_183EE7);
    byte_1AD206 = 1;
    dword_1AD1E4 = v1;
    word_1AD202 = v0;
  }
  JUMPOUT(0x1085EA);
}
// 109DB0: control flows out of bounds to 1085EA
// 1AD1E4: using guessed type int dword_1AD1E4;
// 1AD1F0: using guessed type int dword_1AD1F0;
// 1AD1FC: using guessed type int16_t word_1AD1FC;
// 1AD200: using guessed type int16_t word_1AD200;
// 1AD202: using guessed type int16_t word_1AD202;
// 1AD206: using guessed type char byte_1AD206;


//----- (00109DB5) --------------------------------------------------------
void __usercall sub_109DB5(int a1, int16_t *a2)
{
  int v2; // eax

  if ( sub_C5BB0() )
  {
    v2 = sub_131922(0, 255);
    sub_1077D(v2, 255, a1, a2);
    sub_102CDF();
    sub_C5C44();
  }
  else
  {
    sub_13EE7E(0, 0, 639, 479, 3);
  }
}


//----- (00109E01) --------------------------------------------------------
int __fastcall sub_109E01(int16_t *a1)
{
  sub_129130(
    (int16_t)(*a1 + 2),
    a1[1],
    (int16_t)(a1[2] - 2),
    (int16_t)(a1[1] + 2),
    *((uint8_t *)a1 + 8),
    *((uint8_t *)a1 + 9),
    *((uint8_t *)a1 + 10));
  sub_129130(
    (int16_t)(*a1 + 2),
    a1[1],
    (int16_t)(*a1 + 2),
    (int16_t)(a1[1] + 2),
    *((uint8_t *)a1 + 11),
    *((uint8_t *)a1 + 12),
    *((uint8_t *)a1 + 13));
  sub_129130(
    (int16_t)(a1[2] - 2),
    a1[1],
    (int16_t)(a1[2] - 2),
    (int16_t)(a1[1] + 2),
    *((uint8_t *)a1 + 14),
    *((uint8_t *)a1 + 15),
    *((uint8_t *)a1 + 16));
  sub_129130(
    *a1,
    (int16_t)(a1[1] + 3),
    a1[2],
    (int16_t)(a1[3] - 3),
    *((uint8_t *)a1 + 8),
    *((uint8_t *)a1 + 9),
    *((uint8_t *)a1 + 10));
  sub_129130(
    *a1,
    (int16_t)(a1[1] + 3),
    *a1,
    (int16_t)(a1[3] - 3),
    *((uint8_t *)a1 + 11),
    *((uint8_t *)a1 + 12),
    *((uint8_t *)a1 + 13));
  sub_129130(
    a1[2],
    (int16_t)(a1[1] + 3),
    a1[2],
    (int16_t)(a1[3] - 3),
    *((uint8_t *)a1 + 14),
    *((uint8_t *)a1 + 15),
    *((uint8_t *)a1 + 16));
  sub_129130(
    (int16_t)(*a1 + 2),
    (int16_t)(a1[3] - 2),
    (int16_t)(a1[2] - 2),
    a1[3],
    *((uint8_t *)a1 + 8),
    *((uint8_t *)a1 + 9),
    *((uint8_t *)a1 + 10));
  sub_129130(
    (int16_t)(*a1 + 2),
    (int16_t)(a1[3] - 2),
    (int16_t)(*a1 + 2),
    a1[3],
    *((uint8_t *)a1 + 11),
    *((uint8_t *)a1 + 12),
    *((uint8_t *)a1 + 13));
  return sub_129130(
           (int16_t)(a1[2] - 2),
           (int16_t)(a1[3] - 2),
           (int16_t)(a1[2] - 2),
           a1[3],
           *((uint8_t *)a1 + 14),
           *((uint8_t *)a1 + 15),
           *((uint8_t *)a1 + 16));
}


//----- (00109F9E) --------------------------------------------------------
void __fastcall sub_109F9E(int16_t *a1, unsigned int a2)
{
  int16_t *v2; // ebx
  unsigned int v3; // edx

  v2 = a1;
  v3 = (unsigned int)a1 + 17 * a2;
  while ( (unsigned int)v2 < v3 )
  {
    sub_109E01(v2);
    v2 = (int16_t *)((char *)v2 + 17);
  }
  JUMPOUT(0x109F9C);
}
// 109FAC: control flows out of bounds to 109F9C


//----- (00109FBA) --------------------------------------------------------
int __fastcall sub_109FBA(int a1)
{
  int result; // eax
  char *v3; // ecx
  int v4; // ebx

  sub_1318D4(192, 255);
  sub_12B79D(*(_DWORD *)(a1 + 4));
  for ( result = 0; (int16_t)result < word_199998; ++result )
  {
    v3 = (char *)&unk_183BE7 + 8 * *(uint8_t *)(dword_197F98 + 3753 * (int16_t)result + 38);
    v4 = (int16_t)result;
    dword_1ACFC0[v4] = (int)v3;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 1ACFC0: using guessed type int dword_1ACFC0[];


//----- (0010A036) --------------------------------------------------------
int __fastcall sub_10A036( int a1)
{
  int v1; // ebx
  char v2; // dl
  int result; // eax

  v1 = 3753 * word_19999C;
  v2 = a1 & 7;
  result = dword_197F98;
  *(_BYTE *)(v1 + dword_197F98 + 3679) &= 0x8Fu;
  *(_BYTE *)(v1 + result + 3679) |= 16 * v2;
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010A064) --------------------------------------------------------
int16_t *__fastcall sub_10A064(int16_t *result, int a2, unsigned int a3, unsigned int a4)
{
  int v5; // edx

  v5 = result[1] * *result;
  if ( v5 > 0 )
  {
    result = (int16_t *)((char *)result + *(_DWORD *)&result[2 * result[2] + 6]);
    do
    {
      if ( a3 <= *(_BYTE *)result && *(_BYTE *)result <= a4 )
        *(_BYTE *)result = *(_BYTE *)(*(uint8_t *)result - a3 + a2);
      --v5;
      result = (int16_t *)((char *)result + 1);
    }
    while ( v5 > 0 );
  }
  return result;
}


//----- (0010A0A7) --------------------------------------------------------
int __fastcall sub_10A0A7(int a1, int a2, int a3)
{
  int v3; // ecx
  unsigned int v4; // edx
  int16_t v5; // cx
  int16_t v6; // si
  int v7; // edi
  int v8; // esi
  int16_t v9; // cx
  int v10; // ecx
  int v11; // ecx
  int result; // eax
  unsigned int v13; // [esp+0h] [ebp-Ch]
  uint16_t v14; // [esp+4h] [ebp-8h]
  uint16_t v15; // [esp+8h] [ebp-4h]

  v14 = *(_WORD *)(a1 + 6);
  v3 = 158 * *(uint8_t *)(a1 + 21);
  *(_BYTE *)(a1 + 30) = 1;
  v4 = *(_DWORD *)(a1 + 22);
  *(_BYTE *)(a1 + 31) = 1;
  *(_DWORD *)(a1 + 26) = v4;
  LOWORD(a3) = *(_WORD *)(a1 + 2);
  v13 = v4 + v3;
  do
  {
    *(_WORD *)v4 = *(_WORD *)a1;
    *(_WORD *)(v4 + 74) = *(uint8_t *)(a1 + 38) + *(_WORD *)a1;
    v5 = *(uint8_t *)(a1 + 38);
    v6 = *(_WORD *)(a1 + 4) + *(_WORD *)a1;
    *(_BYTE *)(v4 + 5) = 0;
    *(_WORD *)(v4 + 2) = a3;
    v15 = 0;
    *(_WORD *)(v4 + 76) = v6 - v5;
    while ( 1 )
    {
      v7 = *(uint8_t *)(v4 + 73);
      v8 = 2 * v15;
      if ( v15 >= v7 )
        break;
      v9 = *(_WORD *)(*(_DWORD *)(a1 + 8) + 2 * v15++);
      *(_WORD *)(v4 + v8 + 78) = v9;
    }
    v10 = *(_DWORD *)(a1 + 8);
    LOWORD(v7) = *(uint8_t *)(a1 + 20);
    LOWORD(v10) = *(_WORD *)(v10 + 2 * v15);
    a3 += v7 + v10;
    if ( (uint16_t)a3 <= v14 )
    {
      *(_BYTE *)(v4 + 4) = 0;
    }
    else
    {
      *(_BYTE *)(v4 + 4) = 1;
      v11 = *(_DWORD *)(a1 + 8);
      LOWORD(a3) = *(_WORD *)(a1 + 2);
      ++*(_BYTE *)(a1 + 30);
      LOWORD(a3) = *(_WORD *)(v11 + 2 * v15) + a3;
      LOWORD(v11) = *(uint8_t *)(a1 + 20);
      a3 += v11;
      *(_WORD *)(v4 + 2) = *(_WORD *)(a1 + 2);
    }
    v4 += 158;
  }
  while ( v4 < v13 );
  result = *(_DWORD *)(a1 + 22);
  *(_BYTE *)(result + 4) = 1;
  return result;
}


//----- (0010A188) --------------------------------------------------------
void __fastcall sub_10A188(int a1)
{
  unsigned int v2; // esi
  char v3; // al
  unsigned int v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+8h] [ebp-8h]
  uint16_t i; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 26);
  v4 = 158 * *(uint8_t *)(a1 + 21) + *(_DWORD *)(a1 + 22);
  do
  {
    if ( v2 >= v4 )
      break;
    for ( i = 0; ; ++i )
    {
      v5 = i;
      if ( *(uint8_t *)(v2 + 73) <= (int)i )
        break;
      v3 = sub_11438B(
             *(_WORD *)v2,
             *(_WORD *)(*(_DWORD *)(a1 + 12) + 2 * i) + *(_WORD *)(v2 + 2),
             *(_WORD *)(v2 + 76),
             *(_WORD *)(*(_DWORD *)(a1 + 16) + 2 * i) + *(_WORD *)(v2 + 2),
             byte_17A300,
             0);
      *(_BYTE *)(v5 + v2 + 110) = v3;
    }
    v2 += 158;
  }
  while ( !*(_BYTE *)(v2 + 4) );
  sub_113E65();
  JUMPOUT(0x10A181);
}
// 10A218: control flows out of bounds to 10A181
// 17A300: using guessed type _BYTE byte_17A300[4];


//----- (0010A21D) --------------------------------------------------------
void __fastcall sub_10A21D(int a1, int a2)
{
  int16_t v4; // dx
  int v5; // edi
  int v6; // [esp+4h] [ebp-14h]
  int16_t v7; // [esp+Ch] [ebp-Ch]
  int16_t v8; // [esp+10h] [ebp-8h]
  int16_t v9; // [esp+14h] [ebp-4h]

  if ( a2 )
  {
    if ( a2 != -7 )
    {
      sub_120BB5(*(uint8_t *)(a1 + 32), *(_DWORD *)(a1 + 40));
      sub_102F10(*(_WORD *)a2, *(_WORD *)(a2 + 2), a2 + 7, *(_WORD *)(a1 + 4));
      if ( *(_DWORD *)(a1 + 34) )
      {
        sub_120BB5(*(uint8_t *)(a1 + 33), *(_DWORD *)(a1 + 40));
        (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD))(a1 + 34))(
          *(uint16_t *)(a2 + 74),
          (uint16_t)(*(_WORD *)(a2 + 2 * *(uint8_t *)(a2 + 6) + 78) + *(_WORD *)(a2 + 2)),
          *(uint8_t *)(*(uint8_t *)(a2 + 6) + a2 + 126));
        if ( *(_BYTE *)(a1 + 39) )
        {
          v7 = *(_WORD *)(a2 + 74) - 2;
          v4 = *(_WORD *)(a2 + 2 * *(uint8_t *)(a2 + 6) + 78) + *(_WORD *)(a2 + 2);
          v9 = *(_WORD *)(a2 + 74) - 5;
          v8 = *(uint8_t *)(a1 + 39);
          v6 = (int16_t)(*(_WORD *)a2 + 2);
          v5 = (int16_t)(v4 + 6);
          sub_134D2D(v6, (int16_t)(*(_WORD *)(a2 + 78) + *(_WORD *)(a2 + 2) - 3), v6, v5, v8);
          sub_134D2D(v6, v5, v7, v5, v8);
          sub_134D2D(v9, (int16_t)(v4 + 3), v7, v5, v8);
          sub_134D2D(v9, (int16_t)(v4 + 9), v7, v5, v8);
        }
      }
    }
  }
}


//----- (0010A345) --------------------------------------------------------
void __fastcall sub_10A345(int a1, int a2)
{
  if ( a2 && a2 != -7 )
  {
    sub_120BB5(*(uint8_t *)(a1 + 32), *(_DWORD *)(a1 + 40));
    sub_102F10(*(_WORD *)a2, *(_WORD *)(a2 + 2), a2 + 7, *(_WORD *)(a1 + 4));
    if ( *(_DWORD *)(a1 + 34) )
    {
      sub_120BB5(*(uint8_t *)(a1 + 33), *(_DWORD *)(a1 + 40));
      (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD))(a1 + 34))(
        *(uint16_t *)(a2 + 74),
        (uint16_t)(*(_WORD *)(a2 + 2 * *(uint8_t *)(a2 + 6) + 78) + *(_WORD *)(a2 + 2)),
        *(uint8_t *)(a2 + *(uint8_t *)(a2 + 6) + 126));
    }
  }
}


//----- (0010A3AD) --------------------------------------------------------
void __fastcall sub_10A3AD(int a1, int a2)
{
  uint16_t i; // cx
  int v5; // edx
  int v6; // [esp+4h] [ebp-4h]

  if ( a2 )
  {
    if ( a2 != -7 )
    {
      v6 = *(_DWORD *)(a1 + 4 * *(uint8_t *)(a2 + 72) + 44);
      sub_120BB5(*(uint8_t *)(a1 + 32), v6);
      sub_102F10(*(_WORD *)a2, *(_WORD *)(a2 + 2), a2 + 7, *(_WORD *)(a1 + 4));
      if ( *(_DWORD *)(a1 + 34) )
      {
        sub_120BB5(*(uint8_t *)(a1 + 33), v6);
        for ( i = 0; i < (int)*(uint8_t *)(a2 + 73); ++i )
        {
          v5 = *(_DWORD *)(a1 + 4 * *(uint8_t *)(i + a2 + 142) + 44);
          if ( v5 != v6 )
          {
            v6 = *(_DWORD *)(a1 + 4 * *(uint8_t *)(i + a2 + 142) + 44);
            sub_120BB5(*(uint8_t *)(a1 + 33), v5);
          }
          sub_120BB5(*(uint8_t *)(a1 + 33), v6);
          if ( byte_183F42 == 1
            && *(_BYTE *)(*(uint8_t *)(i + a2 + 126) + 3753 * word_19999C + dword_197F98 + 279) != 3 )
          {
            sub_120BB5(*(uint8_t *)(a1 + 33), *(_DWORD *)(a1 + 60));
          }
          if ( *(_DWORD *)(a1 + 34) )
            (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD))(a1 + 34))(
              *(uint16_t *)(a2 + 74),
              (uint16_t)(*(_WORD *)(a2 + 2 * i + 78) + *(_WORD *)(a2 + 2)),
              *(uint8_t *)(a2 + i + 126));
        }
      }
    }
  }
  JUMPOUT(0x10A33F);
}
// 10A3BB: control flows out of bounds to 10A33F
// 183F42: using guessed type char byte_183F42;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010A4A7) --------------------------------------------------------
void __fastcall sub_10A4A7(int a1)
{
  int v2; // ecx
  int v3; // esi
  int v4; // edx

  sub_10A4E2(a1);
  v2 = *(_DWORD *)(a1 + 26);
  v3 = 158 * *(uint8_t *)(a1 + 21) + *(_DWORD *)(a1 + 22);
  do
  {
    if ( v2 == v3 )
      break;
    v4 = v2;
    v2 += 158;
    sub_10A3AD(a1, v4);
  }
  while ( !*(_BYTE *)(v2 + 4) );
}


//----- (0010A4E2) --------------------------------------------------------
int __fastcall sub_10A4E2(int result)
{
  char v1; // bl
  unsigned int v2; // edx
  unsigned int v3; // ecx

  v1 = *(_BYTE *)(result + 31);
  *(_BYTE *)(result + 31) = 1;
  if ( !v1 )
    v1 = 1;
  v2 = *(_DWORD *)(result + 22);
  v3 = v2 + 158 * *(uint8_t *)(result + 21);
  while ( v2 < v3 )
  {
    if ( (uint8_t)v1 <= 1u )
      goto LABEL_9;
    v2 += 158;
    if ( *(_BYTE *)(v2 + 4) )
    {
      --v1;
      ++*(_BYTE *)(result + 31);
    }
  }
  v2 = *(_DWORD *)(result + 22);
LABEL_9:
  *(_DWORD *)(result + 26) = v2;
  return result;
}


//----- (0010A527) --------------------------------------------------------
char __fastcall sub_10A527(int a1)
{
  if ( *(_BYTE *)(a1 + 31) >= *(_BYTE *)(a1 + 30) )
    return 0;
  ++*(_BYTE *)(a1 + 31);
  sub_10A4E2(a1);
  return 1;
}


//----- (0010A540) --------------------------------------------------------
char __fastcall sub_10A540(int a1)
{
  if ( *(_BYTE *)(a1 + 31) <= 1u )
    return 0;
  --*(_BYTE *)(a1 + 31);
  sub_10A4E2(a1);
  return 1;
}


//----- (0010A554) --------------------------------------------------------
void __fastcall sub_10A554(int a1, int a2)
{
  int v3; // edx
  uint16_t v4; // bx
  char v5; // cl
  int v6; // [esp+4h] [ebp-4h]

  v3 = *(_DWORD *)(a1 + 22);
  v4 = 0;
  v5 = 0;
  while ( 1 )
  {
    if ( v4 >= (int)*(uint8_t *)(a1 + 21) )
      goto LABEL_8;
    if ( *(_BYTE *)(v3 + 4) )
    {
      v6 = v3;
      ++v5;
    }
    if ( v3 == a2 )
      break;
    v3 += 158;
    ++v4;
  }
  *(_BYTE *)(a1 + 31) = v5;
  *(_DWORD *)(a1 + 26) = v6;
LABEL_8:
  JUMPOUT(0x10A33F);
}
// 10A58E: control flows out of bounds to 10A33F
// 10A589: variable 'v6' is possibly undefined


//----- (0010A5A3) --------------------------------------------------------
int __fastcall sub_10A5A3(int a1, int a2)
{
  int v3; // ebx
  uint16_t v4; // dx
  int v5; // edi

  v3 = *(_DWORD *)(a1 + 22);
  v4 = 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)(a1 + 22);
    if ( a2 == *(_BYTE *)(v5 + 158 * v4 + 71) )
      break;
    if ( *(uint8_t *)(a1 + 21) <= (int)++v4 )
      goto LABEL_5;
  }
  v3 = v5 + 158 * v4;
LABEL_5:
  *(_BYTE *)(v3 + 5) = 1;
  sub_10A554(a1, v3);
  return v3;
}


//----- (0010A5E3) --------------------------------------------------------
void __fastcall sub_10A5E3(int a1, int a2)
{
  int v3; // edx
  _BYTE *v4; // eax
  uint16_t i; // bx
  int v6; // [esp+4h] [ebp-8h]
  char v7; // [esp+8h] [ebp-4h]

  v7 = 1;
  v6 = 158 * *(uint8_t *)(a1 + 21);
  v3 = *(_DWORD *)(a1 + 22);
  v4 = *(_BYTE **)(a1 + 26);
  do
  {
    if ( (unsigned int)v4 >= v3 + v6 )
      break;
    v4[5] = 0;
    if ( v7 )
    {
      for ( i = 0; i < (int)(uint8_t)v4[73]; ++i )
      {
        if ( (char)v4[i + 110] == a2 )
        {
          v7 = 0;
          v4[5] = 1;
          v4[6] = i;
        }
      }
    }
    v4 += 158;
  }
  while ( !v4[4] );
  JUMPOUT(0x10A33F);
}
// 10A654: control flows out of bounds to 10A33F


//----- (0010A659) --------------------------------------------------------
unsigned int __fastcall sub_10A659(int a1)
{
  int v1; // ebx
  int v2; // edx
  unsigned int result; // eax
  unsigned int v4; // ebx

  v1 = 158 * *(uint8_t *)(a1 + 21);
  v2 = *(_DWORD *)(a1 + 22);
  result = *(_DWORD *)(a1 + 26);
  v4 = v2 + v1;
  do
  {
    if ( result >= v4 )
      break;
    if ( *(_BYTE *)(result + 5) )
      return result;
    result += 158;
  }
  while ( !*(_BYTE *)(result + 4) );
  return 0;
}


//----- (0010A689) --------------------------------------------------------
int16_t __fastcall sub_10A689(int a1, int a2, int a3)
{
  if ( *(_BYTE *)(a1 + 31) < *(_BYTE *)(a1 + 30) )
    sub_1173DC(a3);
  else
    sub_117324(a3);
  if ( *(_BYTE *)(a1 + 31) > 1u )
    return sub_1173DC(a2);
  else
    return (uint16_t)sub_117324(a2);
}


//----- (0010A6C0) --------------------------------------------------------
int __usercall sub_10A6C0( int a1, int a2, char *a3)
{
  int v3; // edx
  int v4; // eax
  int v5; // ebx
  int v6; // edx
  int v7; // esi
  _WORD *v8; // ecx
  int v9; // ebx
  _DWORD *v10; // edx
  int v11; // eax
  int v12; // eax
  char *v13; // ebx
  int v14; // edx
  int v15; // eax
  uint16_t v16; // si
  char *v17; // esi
  char *v18; // edi
  char *v19; // edi
  char *v20; // esi
  char *v21; // edi
  char *v22; // edi
  char *v23; // edi
  char *v24; // edi
  int v25; // eax
  uint16_t v26; // ax
  int v27; // esi
  int v28; // eax
  int v29; // eax
  int v30; // edx
  _DWORD *v31; // eax
  int result; // eax
  char *v33; // [esp-4h] [ebp-2AEh]
  int16_t v34; // [esp+0h] [ebp-2AAh]
  _BYTE v35[256]; // [esp+4h] [ebp-2A6h] BYREF
  char v36[127]; // [esp+104h] [ebp-1A6h] BYREF
  char v37; // [esp+183h] [ebp-127h] BYREF
  char v38[127]; // [esp+184h] [ebp-126h] BYREF
  char v39; // [esp+203h] [ebp-A7h] BYREF
  char v40[128]; // [esp+204h] [ebp-A6h] BYREF
  int v41[2]; // [esp+284h] [ebp-26h]
  char v42[32]; // [esp+28Ch] [ebp-1Eh] BYREF
  char v43[40]; // [esp+2ACh] [ebp+2h] BYREF
  char v44[40]; // [esp+2D4h] [ebp+2Ah] BYREF
  _BYTE v45[32]; // [esp+2FCh] [ebp+52h] BYREF
  char v46[4]; // [esp+31Ch] [ebp+72h] BYREF
  _DWORD *v47; // [esp+320h] [ebp+76h]
  int v48; // [esp+324h] [ebp+7Ah]
  int v49; // [esp+328h] [ebp+7Eh]

  v3 = 3753 * a1 + dword_197F98;
  dword_192BD8 = v3;
  if ( *(_BYTE *)(v3 + 40) == 100 )
  {
    strcpy(v36, (char *)dword_197FA0[*(uint8_t *)(v3 + 39)]);
    a3 = v36;
  }
  else
  {
    sprintf(
      v36,
      "%s\r%s",
      (char *)dword_197FA0[*(uint8_t *)(v3 + 39)],
      (char *)dword_192210[*(uint8_t *)(v3 + 40)]);
  }
  sub_103C23(0, (int)v46);
  sub_11C2F0();
  sub_103AB7();
  sub_1172FC();
  sub_FE8BE(v4, (int)v46, a2, (int16_t *)a3);
  v47 = sub_126AFD((int)aRacesLbx_0, (int16_t)(*(uint8_t *)(dword_192BD8 + 37) + 32), dword_192ED4);
  v5 = dword_192ED4;
  v6 = (int16_t)(*(uint8_t *)(dword_197F98 + 3753 * v34 + 37) + 46);
  v7 = 0;
  v8 = sub_126B42((int)aRacesLbx_0, v6, dword_192ED4);
  sub_FE8BE((int)v8, v6, v5, (int16_t *)a3);
  do
  {
    v9 = dword_192ED4;
    v10 = sub_126B42((int)aRacerprtLbx, (int16_t)v7, dword_192ED4);
    v11 = (uint16_t)v7++;
    v41[v11] = (int)v10;
    sub_FE8BE(v11, (int)v10, v9, (int16_t *)a3);
  }
  while ( (uint16_t)v7 < 0xAu );
  LOWORD(v12) = sub_1026CF(v34, word_19999C);
  v48 = v12;
  sub_10CE64((int)v45, (int)&unk_183F43, v12, v8, 0);
  v38[0] = 0;
  v40[0] = 0;
  v13 = 0;
  v14 = 0;
  v49 = 0;
  while ( 1 )
  {
    v15 = (uint16_t)v13;
    if ( (uint16_t)v13 >= word_199998 )
      break;
    if ( (uint16_t)v13 == v34 )
      goto LABEL_20;
    a3 = (char *)(3753 * (uint16_t)v13);
    v16 = *(char *)(dword_192BD8 + (uint16_t)v13 + 1575);
    if ( v16 == 2 )
    {
      v17 = &a3[dword_197F98 + 21];
      v18 = &v37;
      do
        ++v18;
      while ( *v18 );
      strcpy(v18, v17);
      v19 = v38;
      ++v14;
    }
    else
    {
      if ( v16 < 4u )
        goto LABEL_20;
      v20 = &a3[dword_197F98 + 21];
      v21 = &v39;
      do
        ++v21;
      while ( *v21 );
      strcpy(v21, v20);
      v19 = v40;
      ++v49;
    }
    v33 = v19;
    v22 = v19 - 1;
    do
      ++v22;
    while ( *v22 );
    strcpy(v22, asc_17A31B);
    a3 = v33;
LABEL_20:
    ++v13;
  }
  if ( !(_WORD)v14 )
  {
    v13 = v38;
    v14 = 29;
    sub_249F9(aBilltextLbx_1, 29, v38, 40);
    v23 = &v37;
    do
      ++v23;
    while ( *v23 );
    strcpy(v23, asc_17A31B);
    a3 = v38;
  }
  if ( !(_WORD)v49 )
  {
    v13 = v40;
    v14 = 30;
    sub_249F9(aBilltextLbx_1, 30, v40, 40);
    v24 = &v39;
    do
      ++v24;
    while ( *v24 );
    strcpy(v24, asc_17A31B);
    a3 = v40;
  }
  sub_FE8BE(v15, v14, (int)v13, (int16_t *)a3);
  sub_249F9(aBilltextLbx_1, 31, v43, 40);
  LOBYTE(v25) = sub_249F9(aBilltextLbx_1, 32, v44, 40);
  sub_FE8BE(v25, 32, (int)v44, (int16_t *)a3);
  sprintf(v35, "%s\n%s\n%s\n%s", v43, v38, v44, v40);
  v26 = (uint16_t)sub_1151B0(534, 433, (int)&unk_17A32C, (_WORD *)v41[1], asc_17A32A, 40);
  byte_199F00 = 1;
  word_1AD204 = v26;
  do
  {
    if ( word_19994C == 1 )
      sub_119400(word_1AD204);
    word_19994C = 0;
    sub_124D41();
    sub_128C32(0, 0, 639, 479, 0);
    sub_129130(212, 23, 620, 457, 178, 179, 179);
    sub_12A478(0, 0, v41[0]);
    if ( byte_199F00 )
      sub_102CDF();
    v27 = 3753 * v34;
    sub_12A478(70, 28, (int)v47);
    v28 = sub_1297C3(70, 28, 76, 88, 1, (uint8_t)byte_1840B7[*(uint8_t *)(v27 + dword_197F98 + 38)]);
    sub_FE8BE(v28, 28, 76, (int16_t *)a3);
    sub_1297C3(71, 29, 74, 86, 1, (uint8_t)byte_1840BF[*(uint8_t *)(v27 + dword_197F98 + 38)]);
    sub_120BB5(3, (int)&unk_183F3A);
    sub_1031C6(dword_192BD8 + 1, 2);
    sub_120BB5(4, (int)&unk_183F3A);
    sub_1031C6((int)v36, 2);
    if ( (_WORD)v48 )
    {
      sub_10CFD7((int)v45);
      sub_120BB5(2, (int)&unk_183F3A);
      if ( (uint16_t)v48 <= 1u )
      {
        sub_249F9(aBilltextLbx_1, 75, v43, 40);
      }
      else
      {
        sub_249F9(aBilltextLbx_1, 74, v43, 40);
        sub_24E08(v43, (int16_t)v48, 40);
      }
    }
    else
    {
      sub_120BB5(3, (int)&unk_183F3A);
      sub_249F9(aBilltextLbx_1, 28, v43, 40);
    }
    sub_102FA8();
    sub_FE8BE(v29, 222, (int)v43, (int16_t *)a3);
    sub_120BB5(4, (int)&unk_183F3A);
    sub_10323B((int)v35, 2);
    sub_124DEC();
    sub_C5C44();
    byte_199F00 = 0;
    byte_183F42 = 1;
    sub_11127C(dword_192ED4);
    v30 = sub_108073((int)v42, word_1AD204 + 1, v34);
    v31 = sub_1112B4(dword_192ED4);
    sub_FE8BE((int)v31, v30, v34, (int16_t *)a3);
    byte_183F42 = 0;
  }
  while ( (_WORD)v30 != word_1AD204 );
  sub_C5BB9();
  result = 3753 * word_19999C;
  dword_192BD8 = result + dword_197F98;
  return result;
}
// 10A755: variable 'v4' is possibly undefined
// 10A77F: variable 'v34' is possibly undefined
// 10A7FB: variable 'v12' is possibly undefined
// 10A94F: variable 'v15' is possibly undefined
// 10A982: variable 'v25' is possibly undefined
// 10ABE3: variable 'v29' is possibly undefined
// 24E08: using guessed type int __fastcall sub_24E08(_DWORD, _DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 183F42: using guessed type char byte_183F42;
// 192210: using guessed type int dword_192210[];
// 192BD8: using guessed type int dword_192BD8;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 197FA0: using guessed type int dword_197FA0[];
// 19994C: using guessed type int16_t word_19994C;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 199F00: using guessed type char byte_199F00;
// 1AD204: using guessed type int16_t word_1AD204;


//----- (0010ACBA) --------------------------------------------------------
void __usercall sub_10ACBA(int16_t *a1)
{
  int v1; // eax
  int v2; // eax
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
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // ebx
  int v29; // edx
  int v30; // eax
  int v31; // eax
  int v32; // edx
  int v33; // ebx
  int v34; // ebx
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  _DWORD *v42; // eax
  int v43; // eax
  int16_t v44; // cx
  int v45; // ecx
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // esi
  int v50; // eax
  int16_t v51; // dx
  int v52; // eax
  int v53; // edx
  char v54; // al
  unsigned int v55; // eax
  int v56; // eax
  int v57; // eax
  char v58; // al
  int v59; // eax
  unsigned int v60; // eax
  int v61; // eax
  int v62; // eax
  int v63; // eax
  char v64; // ah
  int v65; // eax
  int v66; // eax
  _DWORD *v67; // ecx
  int v68; // eax
  int v69; // ebx
  int16_t *v70; // edi
  int v71; // ebx
  int v72; // ebx
  int v73; // eax
  int16_t *v74; // edi
  int v75; // eax
  int16_t v76[294]; // [esp+0h] [ebp-2AEh] BYREF
  char v77[80]; // [esp+24Ch] [ebp-62h] BYREF
  _WORD v78[10]; // [esp+29Ch] [ebp-12h] BYREF
  int v79; // [esp+2B0h] [ebp+2h]
  _DWORD *v80; // [esp+2B4h] [ebp+6h]
  int (*v81)(); // [esp+2B8h] [ebp+Ah]
  _BYTE v82[32]; // [esp+2BCh] [ebp+Eh] BYREF
  int v83; // [esp+2DCh] [ebp+2Eh] BYREF
  int v84; // [esp+2E0h] [ebp+32h]
  int16_t *v85; // [esp+2E4h] [ebp+36h]
  int v86; // [esp+2E8h] [ebp+3Ah] BYREF
  int v87; // [esp+2ECh] [ebp+3Eh]
  int v88; // [esp+2F0h] [ebp+42h] BYREF
  int16_t v89; // [esp+2F4h] [ebp+46h] BYREF
  int v90; // [esp+2F8h] [ebp+4Ah]
  int v91; // [esp+2FCh] [ebp+4Eh] BYREF
  int16_t v92; // [esp+300h] [ebp+52h] BYREF
  int16_t v93; // [esp+304h] [ebp+56h] BYREF
  int16_t v94; // [esp+308h] [ebp+5Ah] BYREF
  int v95; // [esp+30Ch] [ebp+5Eh] BYREF
  int v96; // [esp+310h] [ebp+62h] BYREF
  unsigned int v97; // [esp+314h] [ebp+66h]
  int16_t v98; // [esp+318h] [ebp+6Ah] BYREF
  int v99; // [esp+31Ch] [ebp+6Eh]
  int v100; // [esp+320h] [ebp+72h]
  char v101; // [esp+324h] [ebp+76h]
  char v102; // [esp+328h] [ebp+7Ah]
  char v103; // [esp+32Ch] [ebp+7Eh]

  sub_107AF(&v83);
  sub_131970();
  sub_1172D4();
  sub_FE8BE(v1, 33, (int)byte_1AD494, a1);
  LOBYTE(v2) = sub_249F9(aBilltextLbx_0, 33, byte_1AD494, 15);
  sub_FE8BE(v2, 33, (int)byte_1AD494, a1);
  LOBYTE(v3) = sub_249F9(aBilltextLbx_0, 34, byte_1AD4A3, 15);
  sub_FE8BE(v3, 34, (int)byte_1AD4A3, a1);
  LOBYTE(v4) = sub_249F9(aBilltextLbx_0, 35, byte_1AD4B2, 15);
  sub_FE8BE(v4, 35, (int)byte_1AD4B2, a1);
  LOBYTE(v5) = sub_249F9(aBilltextLbx_0, 36, byte_1AD4C1, 15);
  sub_FE8BE(v5, 36, (int)byte_1AD4C1, a1);
  v100 = -1;
  LOBYTE(v6) = sub_249F9(aBilltextLbx_0, 37, byte_1AD4D0, 15);
  sub_FE8BE(v6, 37, (int)byte_1AD4D0, a1);
  v90 = -1;
  LOBYTE(v7) = sub_249F9(aBilltextLbx_0, 38, byte_1AD4DF, 15);
  sub_FE8BE(v7, 38, (int)byte_1AD4DF, a1);
  LOBYTE(v8) = sub_249F9(aBilltextLbx_0, 39, byte_1AD4EE, 15);
  sub_FE8BE(v8, 39, (int)byte_1AD4EE, a1);
  LOBYTE(v9) = sub_249F9(aBilltextLbx_0, 40, byte_1AD4FD, 15);
  sub_FE8BE(v9, 40, (int)byte_1AD4FD, a1);
  LOBYTE(v10) = sub_249F9(aBilltextLbx_0, 41, byte_1AD50C, 15);
  sub_FE8BE(v10, 41, (int)byte_1AD50C, a1);
  LOBYTE(v11) = sub_249F9(aBilltextLbx_0, 42, byte_1AD51B, 15);
  sub_FE8BE(v11, 42, (int)byte_1AD51B, a1);
  LOBYTE(v12) = sub_249F9(aBilltextLbx_0, 43, byte_1AD52A, 15);
  sub_FE8BE(v12, 43, (int)byte_1AD52A, a1);
  LOBYTE(v13) = sub_249F9(aBilltextLbx_0, 44, byte_1AD539, 15);
  sub_FE8BE(v13, 44, (int)byte_1AD539, a1);
  LOBYTE(v14) = sub_249F9(aBilltextLbx_0, 45, byte_1AD548, 15);
  sub_FE8BE(v14, 45, (int)byte_1AD548, a1);
  LOBYTE(v15) = sub_249F9(aBilltextLbx_0, 46, byte_1AD557, 15);
  sub_FE8BE(v15, 46, (int)byte_1AD557, a1);
  LOBYTE(v16) = sub_249F9(aBilltextLbx_0, 47, byte_1AD566, 15);
  sub_FE8BE(v16, 47, (int)byte_1AD566, a1);
  LOBYTE(v17) = sub_249F9(aBilltextLbx_0, 48, byte_1AD575, 15);
  sub_FE8BE(v17, 48, (int)byte_1AD575, a1);
  LOBYTE(v18) = sub_249F9(aBilltextLbx_0, 49, byte_1AD584, 15);
  sub_FE8BE(v18, 49, (int)byte_1AD584, a1);
  LOBYTE(v19) = sub_249F9(aBilltextLbx_0, 50, byte_1AD404, 20);
  sub_FE8BE(v19, 50, (int)byte_1AD404, a1);
  LOBYTE(v20) = sub_249F9(aBilltextLbx_0, 51, byte_1AD418, 20);
  sub_FE8BE(v20, 51, (int)byte_1AD418, a1);
  LOBYTE(v21) = sub_249F9(aBilltextLbx_0, 52, byte_1AD440, 20);
  sub_FE8BE(v21, 52, (int)byte_1AD440, a1);
  LOBYTE(v22) = sub_249F9(aBilltextLbx_0, 53, byte_1AD42C, 20);
  sub_FE8BE(v22, 53, (int)byte_1AD42C, a1);
  LOBYTE(v23) = sub_249F9(aBilltextLbx_0, 57, byte_1AD472, 30);
  sub_FE8BE(v23, 57, (int)byte_1AD472, a1);
  sub_249F9(aBilltextLbx_0, 58, byte_1AD454, 30);
  LOBYTE(v24) = sub_249F9(aBilltextLbx_0, 59, byte_1AD2D4, 80);
  sub_FE8BE(v24, 59, (int)byte_1AD2D4, a1);
  LOBYTE(v25) = sub_249F9(aBilltextLbx_0, 60, byte_1AD284, 80);
  sub_FE8BE(v25, 60, (int)byte_1AD284, a1);
  LOBYTE(v26) = sub_249F9(aBilltextLbx_0, 76, byte_1AD3A0, 100);
  sub_FE8BE(v26, 76, (int)byte_1AD3A0, a1);
  LOBYTE(v27) = sub_249F9(aBilltextLbx_0, 77, byte_1AD334, 100);
  sub_FE8BE(v27, 77, (int)byte_1AD334, a1);
  v28 = (int)byte_1AD20C;
  v29 = 26;
  LOBYTE(v30) = sub_249F9(aBilltex2Lbx_0, 26, byte_1AD20C, 120);
  sub_FE8BE(v30, 26, (int)byte_1AD20C, a1);
  sub_C5BB9();
  while ( 1 )
  {
    while ( 1 )
    {
LABEL_88:
      word_19994C = 0;
      sub_FE8BE(v31, v29, v28, a1);
      dword_192BD8 = 3753 * word_19999C + dword_197F98;
      dword_1AD330 = (int)v76;
      dword_1AD398 = (int)v82;
      dword_1AD39C = (int)v78;
      sub_FE8BE((int)v78, 25, v28, a1);
      sub_103AA2();
      sub_11C2F0();
      sub_124D41();
      sub_124C08();
      sub_FE8BE(v65, 25, v28, a1);
      v66 = sub_12DAA4(187, 25);
      v67 = sub_110CEE(dword_192ED4, v66);
      v68 = sub_12D8F5(187, 25, (int)v67);
      sub_FE8BE(v68, 25, (int)v67, a1);
      v69 = dword_192ED4;
      v70 = (int16_t *)sub_126B42((int)aRacesLbx, 0, dword_192ED4);
      sub_FE8BE((int)v70, 1, v69, v70);
      v71 = dword_192ED4;
      dword_1AD32C = (int)sub_126B42((int)aRacesLbx, 1, dword_192ED4);
      sub_FE8BE(dword_1AD32C, 4, v71, v70);
      v72 = dword_192ED4;
      dword_1AD328 = (int)sub_126B42((int)aRacesLbx, 4, dword_192ED4);
      sub_FE8BE(dword_1AD328, 4, v72, v70);
      switch ( byte_199CAE )
      {
        case 0:
        case 3:
          v32 = 5;
          break;
        case 1:
          v32 = 61;
          break;
        case 2:
          v32 = 62;
          break;
        case 4:
          v32 = 63;
          break;
        default:
          v32 = 5;
          break;
      }
      v33 = dword_192ED4;
      v85 = (int16_t *)sub_126B42((int)aRacesLbx, v32, dword_192ED4);
      sub_FE8BE((int)v85, v32, v33, v70);
      v34 = dword_192ED4;
      dword_1AD324 = (int)sub_126B42((int)aRacesLbx, 59, dword_192ED4);
      sub_FE8BE(dword_1AD324, 59, v34, v70);
      sub_24E96(dword_1AD328);
      v35 = sub_102597(0, 0);
      sub_FE8BE(v35, 0, v34, v70);
      sub_10BA3D((int)v76, (int)v82);
      sub_FE8BE(v36, (int)v82, v34, v70);
      v78[0] = word_184099;
      v78[1] = word_18409B;
      v78[6] = 0;
      v78[2] = word_18409D;
      v78[8] = 0;
      v78[3] = word_18409F;
      v79 = 0;
      v78[4] = word_1840A1;
      v80 = v67;
      v81 = off_1840A3;
      LOWORD(v37) = sub_10CDD8(v78);
      sub_FE8BE(v37, 0, 639, v70);
      sub_128C32(0, 0, 639, 479, 0);
      v38 = sub_12A478(0, 0, (int)v70);
      sub_FE8BE(v38, 0, (int)v70, v70);
      if ( sub_C5BB0() > 0 )
        sub_102CDF();
      sub_131B34();
      sub_FE8BE(v39, 177, (int)v70, v70);
      sub_120DED(177, 177);
      sub_10BDED((int)v76);
      sub_FE8BE(v40, 177, (int)v70, v70);
      sub_10BFBD((int)v76);
      sub_FE8BE(v41, 0, (int)v70, v70);
      sub_10248B(0, 0);
      v42 = sub_10BD50((int)v76);
      sub_FE8BE((int)v42, 0, (int)v70, v70);
      sub_124DEC();
      v43 = sub_10C4E9((int)&v94, &v93, &v86, &v92, &v91, &v98, &v95, &v89, &v88);
      v44 = v43;
      v87 = v43;
      sub_FE8BE(v43, (int)&v93, (int)&v86, v70);
      sub_10C670((int)v76, v44);
      v28 = 639;
      v45 = 479;
      v97 = sub_11438B(0, 0, 639, 479, asc_17A354, 0);
      v46 = sub_1191CA((int)sub_10C8E0, 2);
      sub_FE8BE(v46, 2, 639, v70);
      sub_10C8E0();
      sub_FE8BE(v47, 2, 639, v70);
      v29 = 255;
      a1 = 0;
      v48 = sub_131922(0, 255);
      sub_1077D(v48, 255, 639, 0);
      sub_C5C44();
      byte_1AD594 = 0;
      byte_1AD595 = 0;
LABEL_10:
      v31 = sub_1171AB(v31, v29, v28, v45);
      v49 = v31;
      if ( !word_19994C )
        break;
      if ( byte_1AD594 )
        sub_10CCC5((int)a1);
      v31 = sub_10C88D(v76);
    }
    if ( (v31 & 0x8000u) != 0 )
      v49 = -v31;
    if ( !(_WORD)v49 )
    {
      sub_12C2A0();
      sub_10C8E0();
      sub_1077D(v50, v29, v28, a1);
      v31 = sub_12C2C6(2);
      goto LABEL_38;
    }
    if ( (_WORD)v49 == v94 )
      goto LABEL_38;
    if ( (int16_t)v49 <= (int16_t)v87 )
    {
      if ( byte_1AD594 )
      {
        sub_10CCC5((int)a1);
        if ( a1 != (int16_t *)v82 )
          v76[42 * (int16_t)v100 + 22] = v90;
        if ( !*(_WORD *)(dword_1AD39C + 12) )
          byte_1AD594 = 0;
      }
      if ( !byte_1AD595 )
      {
        if ( (_WORD)v49 == v98 )
        {
          v86 = 0;
          v91 = 0;
          goto LABEL_32;
        }
        if ( (_WORD)v49 != v92 )
        {
          if ( (_WORD)v49 == v93 )
          {
            v91 = 0;
            goto LABEL_31;
          }
          if ( (_WORD)v49 == v89 )
          {
            v91 = 0;
            v95 = 0;
            v86 = 0;
          }
          goto LABEL_37;
        }
        if ( (*(_BYTE *)(*(_DWORD *)((char *)GetGameFlagsTable_F4B81() + 109455) + 14) & 4) == 0 )
        {
          v86 = 0;
LABEL_31:
          v95 = 0;
LABEL_32:
          v88 = 0;
LABEL_37:
          sub_1172FC();
          sub_11E718();
          sub_1172D4();
          sub_117493();
          sub_124DEC();
          sub_10C7F6((int)v76, v87);
          v45 = 479;
          v28 = 639;
          v29 = 0;
          v97 = sub_11438B(0, 0, 639, 479, asc_17A354, 0);
          v99 = v49;
          LOWORD(v31) = sub_C0A5F(v85);
          byte_1AD595 = 1;
          goto LABEL_38;
        }
      }
      v51 = v87;
      v45 = 479;
      sub_24E96(dword_1AD328);
      v86 = 0;
      v91 = 0;
      v95 = 0;
      v88 = 0;
      sub_10C670((int)v76, v51);
      v28 = 639;
      v29 = 0;
      v99 = 0;
      v31 = sub_11438B(0, 0, 639, 479, asc_17A354, 0);
      byte_1AD595 = 0;
      v97 = v31;
LABEL_38:
      if ( (_WORD)v49 == v94 )
      {
        if ( byte_1AD594 )
        {
          sub_10CCC5((int)a1);
          if ( a1 != (int16_t *)v82 )
            v76[42 * (int16_t)v100 + 22] = v90;
        }
        sub_10C88D(v76);
        sub_C5BB9();
        sub_107BA(&v83);
        sub_1196F7();
        sub_C0AF4();
        sub_1318D4(0, 255);
        sub_1319A3();
        sub_102CDF();
        sub_1172FC();
        word_199A08 = 0;
        JUMPOUT(0x10BDE7);
      }
      goto LABEL_10;
    }
    if ( !byte_1AD595 )
    {
      v86 = 0;
      v91 = 0;
      v95 = 0;
      v88 = 0;
      v73 = sub_10CBDF(v49, (int16_t *)&v96);
      v45 = v73;
      if ( byte_1AD594 )
      {
        if ( !v73 )
        {
          v73 = (int)a1;
          if ( a1 != (int16_t *)v82 )
          {
            v45 = 84 * (int16_t)v100;
            *(int16_t *)((char *)&v76[22] + v45) = v90;
          }
        }
        sub_10CCC5(v73);
        if ( !*(_WORD *)(dword_1AD39C + 12) )
        {
          byte_1AD594 = 0;
          a1 = 0;
        }
      }
      else if ( v73 && *(_WORD *)(v73 + 12) )
      {
        v28 = (uint16_t)word_1AD492;
        v74 = (int16_t *)dword_1AD32C;
        sub_10CEBE(v73, dword_1AD39C, word_1AD492);
        sub_10CC4D(v74);
        v100 = v96;
        v75 = 84 * (int16_t)v96;
        byte_1AD594 = 1;
        LOWORD(v75) = *(int16_t *)((char *)&v76[22] + v75);
        a1 = (int16_t *)v45;
        v90 = v75;
      }
      v31 = dword_1AD330;
      v29 = dword_1AD330 + 84 * word_199934;
      while ( v31 != v29 )
      {
        if ( !*(_WORD *)(v31 + 44) )
          *(_WORD *)(v31 + 44) = 3;
        v31 += 84;
      }
      goto LABEL_38;
    }
    if ( (_WORD)v49 == (_WORD)v97 )
      goto LABEL_88;
    v100 = v49 - v87 - 1;
    v29 = (int)&v76[42 * (int16_t)v100];
    v31 = v99;
    v84 = v29;
    if ( (_WORD)v99 == v98 )
    {
      v31 = dword_192BD8;
      LOBYTE(v29) = 1 << *(_BYTE *)(v29 + 2);
      *(_BYTE *)(dword_192BD8 + 3680) ^= v29;
      goto LABEL_88;
    }
    if ( (_WORD)v99 == v92 )
    {
      sub_24E96(dword_1AD328);
      sub_C5BB9();
      sub_10C88D(v76);
      v52 = sub_10A6C0(*(_WORD *)(v29 + 2), v28, (char *)a1);
      sub_FE8BE(v52, v29, v28, a1);
      goto LABEL_88;
    }
    if ( (_WORD)v99 == v89 )
    {
      sub_10C88D(v76);
      v31 = *(int16_t *)(v29 + 2);
      v29 = dword_192BD8;
      if ( *(char *)(dword_192BD8 + v31 + 1575) < 4 )
      {
        v53 = v84;
        v28 = 120;
        strcpy(v77, byte_1AD20C);
        a1 = (int16_t *)v77;
        v29 = *(int16_t *)(v53 + 2);
        sub_24D30();
        sub_77658((int)v77);
        if ( (_WORD)v31 == 1 )
        {
          v29 = 3753 * word_19999C + dword_197F98;
          v31 = *(int16_t *)(v84 + 2);
          *(_BYTE *)(v29 + v31 + 2199) = 0;
        }
      }
    }
    else
    {
      if ( (_WORD)v99 != v93 )
        goto LABEL_88;
      sub_10C88D(v76);
      v29 = dword_197F98;
      LOBYTE(v29) = ~(1 << *(_BYTE *)(v84 + 2));
      *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 3680) &= v29;
      if ( byte_199F3A != 2 && byte_199F3A != 3 )
      {
        sub_16C4E(*(_WORD *)(v84 + 2), a1);
        goto LABEL_88;
      }
      v29 = dword_197F98;
      if ( *(_BYTE *)(dword_197F98 + 3753 * *(int16_t *)(v84 + 2) + 40) == 100 )
      {
        v102 = 0;
        v101 = 0;
        v58 = *(_BYTE *)(v84 + 2);
        byte_1AD593 = 1;
        sub_FA3F6(v58);
        while ( !v102 && !sub_FA521(SBYTE1(v59)) && !v101 && !sub_FA5A3(*(int16_t *)(v84 + 2)) )
        {
          sub_12C2A0();
          sub_11C2F0();
          v28 = 639;
          v29 = 0;
          v60 = sub_11438B(0, 0, 639, 479, asc_17A354, 0);
          if ( (uint16_t)sub_1171AB(v60, 0, 639, 479) && sub_FA54B() )
            v101 = 1;
          if ( sub_FA5B9() )
            byte_1AD593 = 2;
          if ( sub_FA79B() )
            v102 = 1;
          sub_10C8E0();
          v62 = sub_1077D(v61, 0, 639, a1);
          sub_FE8BE(v62, 0, 639, a1);
          v59 = sub_12C2C6(2);
        }
        v63 = *(int16_t *)(v84 + 2);
        byte_1AD593 = 0;
        if ( sub_FA5A3(v63) )
        {
          v28 = (int)v77;
          v29 = 55;
          goto LABEL_86;
        }
        if ( v102 )
        {
          v28 = (int)v77;
          v29 = 56;
LABEL_86:
          sub_249F9(aBilltextLbx_0, v29, v77, 80);
          sub_77423((int)v77);
        }
        else
        {
          if ( !sub_FA521(v64) )
          {
            LOBYTE(v31) = sub_FA556();
            goto LABEL_88;
          }
          sub_16C4E(*(_WORD *)(v84 + 2), a1);
        }
        sub_FA5AA();
        goto LABEL_88;
      }
      v103 = 0;
      v54 = *(_BYTE *)(v84 + 2);
      byte_1AD593 = 1;
      sub_FA270(v54);
      while ( !sub_FA2A9() && !v103 && !sub_FA3DC() )
      {
        sub_12C2A0();
        sub_11C2F0();
        v28 = 639;
        v29 = 0;
        v55 = sub_11438B(0, 0, 639, 479, asc_17A354, 0);
        if ( (uint16_t)sub_1171AB(v55, 0, 639, 479) )
          v103 = 1;
        sub_10C8E0();
        v57 = sub_1077D(v56, 0, 639, a1);
        sub_FE8BE(v57, 0, 639, a1);
        sub_12C2C6(2);
      }
      byte_1AD593 = 0;
      if ( v103 )
      {
        sub_FA38F();
        while ( 1 )
        {
          LOBYTE(v31) = sub_FA3D1();
          if ( (_BYTE)v31 )
            break;
          sub_FE8BE(v31, v29, v28, a1);
        }
      }
      else if ( sub_FA3DC() )
      {
        v28 = (int)v77;
        v29 = 27;
        sub_249F9(aBilltex2Lbx_0, 27, v77, 80);
        LOWORD(v31) = sub_77423((int)v77);
      }
      else
      {
        sub_16C4E(*(_WORD *)(v84 + 2), a1);
        LOBYTE(v31) = sub_FA2C5();
      }
    }
  }
}
// 10B49C: control flows out of bounds to 10BDE7
// 10ACEA: variable 'v1' is possibly undefined
// 10ACF9: variable 'v2' is possibly undefined
// 10AD17: variable 'v3' is possibly undefined
// 10AD35: variable 'v4' is possibly undefined
// 10AD53: variable 'v5' is possibly undefined
// 10AD78: variable 'v6' is possibly undefined
// 10AD9D: variable 'v7' is possibly undefined
// 10ADBB: variable 'v8' is possibly undefined
// 10ADD9: variable 'v9' is possibly undefined
// 10ADF7: variable 'v10' is possibly undefined
// 10AE15: variable 'v11' is possibly undefined
// 10AE33: variable 'v12' is possibly undefined
// 10AE51: variable 'v13' is possibly undefined
// 10AE6F: variable 'v14' is possibly undefined
// 10AE8D: variable 'v15' is possibly undefined
// 10AEAB: variable 'v16' is possibly undefined
// 10AEC9: variable 'v17' is possibly undefined
// 10AEE7: variable 'v18' is possibly undefined
// 10AF05: variable 'v19' is possibly undefined
// 10AF23: variable 'v20' is possibly undefined
// 10AF41: variable 'v21' is possibly undefined
// 10AF5F: variable 'v22' is possibly undefined
// 10AF7D: variable 'v23' is possibly undefined
// 10AFB4: variable 'v24' is possibly undefined
// 10AFD2: variable 'v25' is possibly undefined
// 10AFF0: variable 'v26' is possibly undefined
// 10B00E: variable 'v27' is possibly undefined
// 10B02C: variable 'v30' is possibly undefined
// 10B0B9: variable 'v36' is possibly undefined
// 10B11D: variable 'v37' is possibly undefined
// 10B160: variable 'v39' is possibly undefined
// 10B177: variable 'v40' is possibly undefined
// 10B189: variable 'v41' is possibly undefined
// 10B21D: variable 'v47' is possibly undefined
// 10B248: variable 'v31' is possibly undefined
// 10B28F: variable 'v50' is possibly undefined
// 10B687: variable 'v56' is possibly undefined
// 10B72B: variable 'v59' is possibly undefined
// 10B7B3: variable 'v61' is possibly undefined
// 10B86B: variable 'v65' is possibly undefined
// 10B928: variable 'v64' is possibly undefined
// 184099: using guessed type int16_t word_184099;
// 18409B: using guessed type int16_t word_18409B;
// 18409D: using guessed type int16_t word_18409D;
// 18409F: using guessed type int16_t word_18409F;
// 1840A1: using guessed type int16_t word_1840A1;
// 1840A3: using guessed type int (*off_1840A3)();
// 192BD8: using guessed type int dword_192BD8;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 199934: using guessed type int16_t word_199934;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199CAE: using guessed type char byte_199CAE;
// 199F3A: using guessed type char byte_199F3A;
// 1AD324: using guessed type int dword_1AD324;
// 1AD328: using guessed type int dword_1AD328;
// 1AD32C: using guessed type int dword_1AD32C;
// 1AD330: using guessed type int dword_1AD330;
// 1AD398: using guessed type int dword_1AD398;
// 1AD39C: using guessed type int dword_1AD39C;
// 1AD492: using guessed type int16_t word_1AD492;
// 1AD593: using guessed type char byte_1AD593;
// 1AD594: using guessed type char byte_1AD594;
// 1AD595: using guessed type char byte_1AD595;


//----- (0010BA3D) --------------------------------------------------------
void __fastcall sub_10BA3D(int a1, int a2)
{
  int v2; // ecx
  int v4; // esi
  int v5; // edx
  int v6; // eax
  int v7; // ebx
  int16_t v8; // ax
  char *v9; // eax
  _DWORD *v10; // eax
  int v11; // ebx
  _DWORD *v12; // eax
  int v13; // ebx
  int16_t v14; // ax
  _DWORD *v15; // [esp+0h] [ebp-38h]
  _DWORD *v16; // [esp+8h] [ebp-30h]
  _DWORD *v17; // [esp+Ch] [ebp-2Ch]
  int16_t v18; // [esp+18h] [ebp-20h]
  int16_t v19; // [esp+1Ch] [ebp-1Ch]
  int16_t v20; // [esp+20h] [ebp-18h]
  uint16_t v21; // [esp+24h] [ebp-14h]
  int16_t v22; // [esp+28h] [ebp-10h]
  int16_t v23; // [esp+2Ch] [ebp-Ch]
  int16_t v24; // [esp+30h] [ebp-8h]
  uint16_t v25; // [esp+34h] [ebp-4h]

  v2 = a1;
  memset(a1, 0, 588);
  v25 = 0;
  v22 = 24;
  v23 = 17;
  v17 = sub_126B42(
          (int)aRacesLbx,
          (int16_t)(*(uint8_t *)(dword_197F98 + 3753 * word_19999C + 37) + 46),
          dword_192ED4);
  v19 = 10;
  v16 = sub_126B42((int)aRacesLbx, 2, dword_192ED4);
  v4 = v2 + 12;
  v15 = sub_126B42((int)aRacesLbx, 31, dword_192ED4);
  while ( 1 )
  {
    v5 = word_199934;
    *(_DWORD *)(v2 + 64) = v16;
    if ( v25 < v5 )
    {
      v6 = (uint8_t)byte_199BA3[v25];
      v18 = (uint8_t)byte_199BA3[v25];
      v7 = dword_197F98 + 3753 * v6;
      v21 = 0;
      v20 = *(char *)(dword_192BD8 + v6 + 1559) + 100;
      while ( v20 > (uint8_t)byte_183F7E[v21] )
        ++v21;
      *(_DWORD *)(v2 + 50) = (char *)&unk_1AD494 + 15 * v21;
      v8 = (uint8_t)byte_183F64[(int16_t)(v20 - (__CFSHL__(v20 >> 15, 3) + 8 * (v20 >> 15))) >> 3];
      *(_DWORD *)(v2 + 4) = v7;
      *(_WORD *)v2 = v25;
      *(_WORD *)(v2 + 2) = v18;
      *(_DWORD *)(v2 + 56) = v7 + 1;
      *(_WORD *)(v2 + 8) = *(uint8_t *)(v7 + 37);
      *(_WORD *)(v2 + 46) = v8 + word_18400F[2 * v25] - 6;
      *(_DWORD *)(v2 + 68) = v15;
      if ( *(_BYTE *)(v7 + 36) )
      {
        *(_BYTE *)(v2 + 11) = 1;
      }
      else
      {
        v24 = sub_102711(v18);
        *(_WORD *)(v2 + 44) = sub_102739(v18) + 1;
        v9 = (char *)&unk_183F8F + 14 * v25;
        *(_WORD *)v4 = *(_WORD *)v9;
        *(_WORD *)(v4 + 2) = *((_WORD *)v9 + 1);
        *(_WORD *)(v4 + 4) = *((_WORD *)v9 + 2);
        *(_WORD *)(v4 + 6) = *((_WORD *)v9 + 3);
        *(_WORD *)(v4 + 8) = *((_WORD *)v9 + 4);
        *(_DWORD *)(v4 + 28) = *(_DWORD *)(v9 + 10);
        *(_WORD *)(v4 + 12) = v24;
        if ( v17 )
          *(_WORD *)(v4 + 16) = *(_WORD *)v17;
        else
          *(_WORD *)(v4 + 16) = 0;
        *(_DWORD *)(v4 + 20) = v17;
        *(_DWORD *)(v4 + 24) = 0;
        sub_10CDD8((_WORD *)v4);
        v10 = sub_126B42((int)aRacesLbx, v19, dword_192ED4);
        v11 = dword_192ED4;
        *(_DWORD *)(v2 + 72) = v10;
        v12 = sub_126B42((int)aRacesLbx, v23, v11);
        v13 = dword_192ED4;
        *(_DWORD *)(v2 + 76) = v12;
        *(_DWORD *)(v2 + 80) = sub_126B42((int)aRacesLbx, v22, v13);
      }
      *(_DWORD *)(v2 + 60) = sub_126B42((int)aRacesLbx, (int16_t)(*(_WORD *)(v2 + 8) + 32), dword_192ED4);
    }
    else
    {
      *(_BYTE *)(v2 + 10) = 1;
    }
    ++v22;
    ++v23;
    ++v19;
    ++v25;
    v4 += 84;
    v2 += 84;
    if ( v25 >= 7u )
    {
      sub_10275F();
      *(_WORD *)a2 = word_18408B;
      *(_WORD *)(a2 + 2) = word_18408D;
      *(_WORD *)(a2 + 4) = word_18408F;
      *(_WORD *)(a2 + 6) = word_184091;
      *(_WORD *)(a2 + 8) = word_184093;
      *(_DWORD *)(a2 + 28) = dword_184095;
      *(_WORD *)(a2 + 12) = v14;
      if ( v17 )
        *(_WORD *)(a2 + 16) = *(_WORD *)v17;
      else
        *(_WORD *)(a2 + 16) = 0;
      *(_DWORD *)(a2 + 20) = v17;
      *(_DWORD *)(a2 + 24) = 0;
      sub_10CDD8((_WORD *)a2);
      JUMPOUT(0x10C887);
    }
  }
}
// 10BD4B: control flows out of bounds to 10C887
// 10BD29: variable 'v14' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 18400F: using guessed type int16_t word_18400F[13];
// 18408B: using guessed type int16_t word_18408B;
// 18408D: using guessed type int16_t word_18408D;
// 18408F: using guessed type int16_t word_18408F;
// 184091: using guessed type int16_t word_184091;
// 184093: using guessed type int16_t word_184093;
// 184095: using guessed type int dword_184095;
// 192BD8: using guessed type int dword_192BD8;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 199934: using guessed type int16_t word_199934;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010BD50) --------------------------------------------------------
_DWORD *__fastcall sub_10BD50(int a1)
{
  uint16_t v2; // di
  int v3; // ebx
  int v4; // edx
  _DWORD *v6; // [esp+0h] [ebp-4h]

  sub_1112EC(dword_192ED4, 3);
  v2 = 0;
  v6 = sub_126B42((int)aRacesLbx, 3, dword_192ED4);
  do
  {
    if ( v2 >= word_199934 )
    {
      v3 = *(_DWORD *)(a1 + 64);
      v4 = (int16_t)(word_18400F[2 * v2] + 75);
    }
    else
    {
      sub_12A478(word_18400D[2 * v2], word_18400F[2 * v2], (int)v6);
      v3 = *(_DWORD *)(a1 + 64);
      v4 = *(int16_t *)(a1 + 46);
    }
    sub_12A478(word_184029[v2++], v4, v3);
    a1 += 84;
  }
  while ( v2 != 7 );
  return sub_1113CC(dword_192ED4, v4);
}
// 18400D: using guessed type int16_t word_18400D[];
// 18400F: using guessed type int16_t word_18400F[13];
// 184029: using guessed type int16_t word_184029[7];
// 192ED4: using guessed type int dword_192ED4;
// 199934: using guessed type int16_t word_199934;


//----- (0010BDED) --------------------------------------------------------
void __fastcall sub_10BDED(int a1)
{
  int v2; // esi
  char v3; // bl
  uint16_t i; // [esp+0h] [ebp-4h]

  for ( i = 0; i < word_199934; ++i )
  {
    sub_12A478(word_183FF1[2 * i], word_183FF3[2 * i], *(_DWORD *)(a1 + 60));
    if ( *(_BYTE *)(a1 + 11) )
      sub_12A478(word_183FF1[2 * i], word_183FF3[2 * i], *(_DWORD *)(a1 + 68));
    v2 = 2 * i;
    sub_1297C3(
      word_183FF1[v2],
      word_183FF3[v2],
      76,
      88,
      1,
      (uint8_t)byte_1840B7[*(uint8_t *)(3753 * *(int16_t *)(a1 + 2) + dword_197F98 + 38)]);
    sub_1297C3(
      word_183FF1[v2] + 1,
      word_183FF3[v2] + 1,
      74,
      86,
      1,
      (uint8_t)byte_1840BF[*(uint8_t *)(dword_197F98 + 3753 * *(int16_t *)(a1 + 2) + 38)]);
    sub_12972D(
      word_183FF1[v2],
      word_183FF3[v2],
      byte_1840C7[*(uint8_t *)(dword_197F98 + 3753 * *(int16_t *)(a1 + 2) + 38)]);
    sub_12972D(
      word_183FF1[v2] + 75,
      word_183FF3[v2],
      byte_1840C7[*(uint8_t *)(3753 * *(int16_t *)(a1 + 2) + dword_197F98 + 38)]);
    sub_12972D(
      word_183FF1[v2],
      word_183FF3[v2] + 87,
      byte_1840C7[*(uint8_t *)(dword_197F98 + 3753 * *(int16_t *)(a1 + 2) + 38)]);
    v3 = byte_1840C7[*(uint8_t *)(dword_197F98 + 3753 * *(int16_t *)(a1 + 2) + 38)];
    a1 += 84;
    sub_12972D(word_183FF1[v2] + 75, word_183FF3[v2] + 87, v3);
  }
  JUMPOUT(0x10BDE6);
}
// 10BE0C: control flows out of bounds to 10BDE6
// 183FF1: using guessed type int16_t word_183FF1[];
// 183FF3: using guessed type int16_t word_183FF3[13];
// 197F98: using guessed type int dword_197F98;
// 199934: using guessed type int16_t word_199934;


//----- (0010BFBD) --------------------------------------------------------
void __fastcall sub_10BFBD(int a1)
{
  int v1; // ecx
  int16_t v2; // ax
  int v3; // edx
  int v4; // edx
  char *v5; // esi
  char *v6; // edi
  int v7; // edx
  int v8; // eax
  char *v9; // edi
  char *v10; // edi
  int v11; // edx
  char *v12; // edi
  char *v13; // edi
  int v14; // [esp+0h] [ebp-4Eh] BYREF
  char v15[200]; // [esp+4h] [ebp-4Ah] BYREF
  char v16[64]; // [esp+CCh] [ebp+7Eh] BYREF
  char v17[4]; // [esp+10Ch] [ebp+BEh] BYREF
  int16_t v18; // [esp+110h] [ebp+C2h] BYREF
  int v19; // [esp+114h] [ebp+C6h]
  int v20; // [esp+118h] [ebp+CAh]
  int v21; // [esp+11Ch] [ebp+CEh]
  int16_t v22; // [esp+120h] [ebp+D2h] BYREF

  v20 = 0;
  while ( 1 )
  {
    LOWORD(a1) = word_184037[2 * (uint16_t)v20];
    v19 = a1;
    LOWORD(a1) = word_184039[2 * (uint16_t)v20];
    v21 = a1;
    if ( *(_BYTE *)(v14 + 10)
      || sub_79E06(word_19999C) && !*(_BYTE *)(3753 * word_19999C + dword_197F98 + *(int16_t *)(v14 + 2) + 1412) )
    {
      sub_120BB5(4, (int)&unk_1840A7);
      v1 = (uint16_t)v20;
      sub_1210FD(v19 + 91, v21 + 10, (int)&unk_1AD418);
      a1 = word_199934;
      if ( v1 < word_199934 )
      {
        a1 = word_19999C;
        if ( sub_79E06(word_19999C) )
        {
          a1 = dword_197F98 + 3753 * word_19999C;
          if ( !*(_BYTE *)(*(int16_t *)(v14 + 2) + a1 + 1412) )
          {
            sub_120D79(2, (int)&unk_1840AF);
            sub_102FA8();
          }
        }
      }
      goto LABEL_54;
    }
    sub_120D79(2, (int)&unk_1840AF);
    sub_102FA8();
    HIWORD(a1) = HIWORD(v14);
    if ( *(_BYTE *)(v14 + 11) )
      goto LABEL_54;
    v2 = *(char *)(*(int16_t *)(v14 + 2) + dword_192BD8 + 1575);
    v15[0] = byte_17A356;
    if ( v2 > 0 )
    {
      if ( v2 >= 6 )
        v2 = 5;
      strcpy(v15, (char *)dword_199150[v2]);
      strupr(v15);
    }
    v3 = *(int16_t *)(v14 + 2);
    if ( *(_BYTE *)(v3 + dword_192BD8 + 1591) )
    {
      v4 = *(int16_t *)(dword_192BD8 + 2 * v3 + 1478);
      switch ( byte_199CAE )
      {
        case 0:
        case 2:
        case 3:
          if ( v4 < 0 )
            goto LABEL_17;
          goto LABEL_24;
        case 1:
          if ( v4 < 0 )
            v5 = aMc_0;
          else
            v5 = aFp_1;
          break;
        case 4:
          if ( v4 < 0 )
LABEL_17:
            v5 = aBc_0;
          else
            v5 = aPr_1;
          break;
        default:
          if ( v4 < 0 )
            v5 = aBc_0;
          else
LABEL_24:
            v5 = aRp_0;
          break;
      }
      strcpy(v17, v5);
      sprintf(v16, "\r%s%i%s", byte_1AD472, v4, v17);
      v6 = (char *)&v14 + 3;
      do
        ++v6;
      while ( *v6 );
      strcpy(v6, v16);
    }
    v7 = *(int16_t *)(v14 + 2);
    if ( *(_BYTE *)(v7 + dword_192BD8 + 1583) )
    {
      v8 = dword_192BD8 + 2 * v7;
      if ( byte_199CAE == 1 )
        sprintf(v16, "\r%s%iMC", &unk_1AD454, *(int16_t *)(v8 + 1444));
      else
        sprintf(v16, "\r%s%iBC", &unk_1AD454, *(int16_t *)(v8 + 1444));
      v9 = (char *)&v14 + 3;
      do
        ++v9;
      while ( *v9 );
      strcpy(v9, v16);
    }
    if ( *(_WORD *)(dword_192BD8 + 2 * *(int16_t *)(v14 + 2) + 1599) )
      break;
    if ( *(_WORD *)(dword_197F98 + 3753 * *(int16_t *)(v14 + 2) + 2 * word_19999C + 1599) )
    {
      v12 = (char *)&v14 + 3;
      do
        ++v12;
      while ( *v12 );
      strcpy(v12, (char *)&off_17A37E);
      strcpy(v16, byte_1AD284);
      if ( *(_WORD *)(3753 * *(int16_t *)(v14 + 2) + dword_197F98 + 2 * word_19999C + 1599) == 1 )
        v11 = 5;
      else
        v11 = 10;
      goto LABEL_48;
    }
LABEL_51:
    if ( !strlen(v15) )
      strcpy(v15, (char *)dword_199150[0]);
    sub_120BB5(2, (int)&unk_1840A7);
    a1 = sub_1031C6((int)v15, 2);
LABEL_54:
    ++v20;
    v14 += 84;
    if ( (uint16_t)v20 >= 7u )
    {
      sub_120BB5(3, (int)&unk_1840A7);
      sub_100A83((_BYTE *)dword_192BD8, &v22, &v18);
      sprintf(v16, "%s%hi%%", byte_1AD440, v22);
      sub_102FA8();
      sprintf(v16, "%s%hi%%", byte_1AD42C, v18);
      sub_102FA8();
      JUMPOUT(0x10B49B);
    }
  }
  v10 = (char *)&v14 + 3;
  do
    ++v10;
  while ( *v10 );
  strcpy(v10, (char *)&off_17A37E);
  strcpy(v16, byte_1AD2D4);
  if ( *(_WORD *)(dword_192BD8 + 2 * *(int16_t *)(v14 + 2) + 1599) == 1 )
    v11 = 5;
  else
    v11 = 10;
LABEL_48:
  sub_24E08(v16, v11, 64);
  v13 = (char *)&v14 + 3;
  do
    ++v13;
  while ( *v13 );
  strcpy(v13, v16);
  goto LABEL_51;
}
// 10C4E4: control flows out of bounds to 10B49B
// 10BFE6: variable 'a1' is possibly undefined
// 24E08: using guessed type int __fastcall sub_24E08(_DWORD, _DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 13EE59: using guessed type int __fastcall strupr(_DWORD);
// 17A356: using guessed type char byte_17A356;
// 17A37E: using guessed type _UNKNOWN *off_17A37E;
// 184037: using guessed type int16_t word_184037[];
// 184039: using guessed type int16_t word_184039[13];
// 192BD8: using guessed type int dword_192BD8;
// 197F98: using guessed type int dword_197F98;
// 199150: using guessed type int dword_199150[];
// 199934: using guessed type int16_t word_199934;
// 19999C: using guessed type int16_t word_19999C;
// 199CAE: using guessed type char byte_199CAE;


//----- (0010C4E9) --------------------------------------------------------
int __fastcall sub_10C4E9(
        int a1,
        _WORD *a2,
        _WORD *a3,
        _WORD *a4,
        _WORD *a5,
        _WORD *a6,
        _WORD *a7,
        _WORD *a8,
        _WORD *a9)
{
  _WORD *v9; // eax
  _WORD *v10; // eax
  _WORD *v11; // eax
  int16_t v12; // ax
  int v13; // ebx
  _WORD *v14; // eax
  int16_t v15; // ax
  int v16; // ebx
  _WORD *v17; // eax
  int v18; // eax
  _WORD *v20; // [esp+0h] [ebp-8h]

  sub_11C2F0();
  v9 = sub_126B42((int)aRacesLbx, 9, dword_192ED4);
  *v20 = (uint16_t)sub_1151B0(535, 433, (int)&byte_17A356, v9, (_BYTE *)&off_17A37E + 2, 40);
  *a3 = 0;
  *a5 = 0;
  *a7 = 0;
  *a9 = 0;
  if ( word_199934 <= 0 )
  {
    *a6 = 0;
    *a4 = 0;
    *a2 = 0;
    *a8 = 0;
  }
  else
  {
    v10 = sub_126B42((int)aRacesLbx, 6, dword_192ED4);
    *a6 = sub_11523B(429, 444, (int)&byte_17A356, v10, (int)a7, byte_17A382, 40);
    v11 = sub_126B42((int)aRacesLbx, 7, dword_192ED4);
    v12 = sub_11523B(429, 423, (int)&byte_17A356, v11, (int)a5, aRad, 40);
    v13 = dword_192ED4;
    *a4 = v12;
    v14 = sub_126B42((int)aRacesLbx, 8, v13);
    v15 = sub_11523B(334, 423, (int)&byte_17A356, v14, (int)a3, &aRad[1], 40);
    v16 = dword_192ED4;
    *a2 = v15;
    v17 = sub_126B42((int)aRacesLbx, 60, v16);
    *a8 = sub_11523B(334, 444, (int)&byte_17A356, v17, (int)a9, &aRad[2], 40);
  }
  LOWORD(v18) = sub_113E65();
  return v18 - 1;
}
// 10C531: variable 'v20' is possibly undefined
// 10C669: variable 'v18' is possibly undefined
// 17A356: using guessed type char byte_17A356;
// 17A37E: using guessed type _UNKNOWN *off_17A37E;
// 17A382: using guessed type _BYTE byte_17A382[2];
// 17A384: using guessed type wchar_t aRad[4];
// 192ED4: using guessed type int dword_192ED4;
// 199934: using guessed type int16_t word_199934;


//----- (0010C670) --------------------------------------------------------
void __fastcall sub_10C670(int a1, int a2)
{
  int v3; // esi
  int16_t v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int16_t v6; // [esp+8h] [ebp-8h]
  uint16_t v7; // [esp+Ch] [ebp-4h]

  if ( word_199934 > 0 )
  {
    sub_119400(a2);
    word_1AD490 = sub_11438B(328, 386, 613, 415, &byte_17A356, 0);
    v7 = 0;
    v5 = a1 + 44;
    while ( v7 < word_199934 )
    {
      v3 = 2 * v7;
      v6 = word_18406F[v3];
      v4 = word_184071[v3];
      sub_115383(v6, v4, (int)&byte_17A356, *(_WORD **)(a1 + 72), v5, 1, &byte_17A356, 41);
      sub_115383(v6 + 76, v4, (int)&byte_17A356, *(_WORD **)(a1 + 76), v5, 2, &byte_17A356, 41);
      sub_115383(v6 + 149, v4, (int)&byte_17A356, *(_WORD **)(a1 + 80), v5, 3, &byte_17A356, 41);
      *(_WORD *)(a1 + 54) = sub_11438B(
                              word_184053[v3],
                              word_184055[v3] - 6,
                              word_184053[v3] + 187,
                              word_184055[v3] + 25,
                              &byte_17A356,
                              0);
      v5 += 84;
      a1 += 84;
      ++v7;
      *(_WORD *)(a1 - 36) = sub_11438B(
                              word_18400D[v3] - 6,
                              word_18400F[v3] - 6,
                              word_18400D[v3] + 8,
                              word_18400F[v3] + 88,
                              &byte_17A356,
                              0);
    }
    JUMPOUT(0x10C885);
  }
  JUMPOUT(0x10C887);
}
// 10C686: control flows out of bounds to 10C887
// 10C6D3: control flows out of bounds to 10C885
// 17A356: using guessed type char byte_17A356;
// 18400D: using guessed type int16_t word_18400D[];
// 18400F: using guessed type int16_t word_18400F[13];
// 184053: using guessed type int16_t word_184053[];
// 184055: using guessed type int16_t word_184055[];
// 18406F: using guessed type int16_t word_18406F[];
// 184071: using guessed type int16_t word_184071[];
// 199934: using guessed type int16_t word_199934;
// 1AD490: using guessed type int16_t word_1AD490;


//----- (0010C7F6) --------------------------------------------------------
char __fastcall sub_10C7F6(int a1, int a2)
{
  uint16_t i; // di
  int16_t v5; // cx
  int16_t v6; // dx
  int16_t v7; // [esp+0h] [ebp-4h]

  if ( word_199934 <= 0 )
    return 0;
  v7 = 0;
  sub_119400(a2);
  for ( i = 0; i < word_199934; ++i )
  {
    if ( i == 4 )
      v7 = 320;
    v5 = word_183FF3[2 * i] + 88;
    a1 += 84;
    v6 = word_183FF3[2 * i];
    *(_WORD *)(a1 - 30) = sub_11438B(v7, v6, v7 + 319, v5, &byte_17A356, 0);
  }
  word_1AD490 = 9999;
  return 1;
}
// 17A356: using guessed type char byte_17A356;
// 183FF3: using guessed type int16_t word_183FF3[13];
// 199934: using guessed type int16_t word_199934;
// 1AD490: using guessed type int16_t word_1AD490;


//----- (0010C88D) --------------------------------------------------------
int __fastcall sub_10C88D(int16_t *a1)
{
  int16_t *v1; // ebx
  int16_t *v2; // ecx

  v1 = a1;
  v2 = &a1[42 * word_199934];
  while ( v1 != v2 )
  {
    if ( v1[22] > 0 )
      sub_10280D(v1[1]);
    sub_1027D9(v1[1], v1[12]);
    v1 += 42;
  }
  return sub_10283D(*(_WORD *)(dword_1AD398 + 12));
}
// 199934: using guessed type int16_t word_199934;
// 1AD398: using guessed type int dword_1AD398;


//----- (0010C8E0) --------------------------------------------------------
void sub_10C8E0()
{
  uint16_t *v0; // esi
  int v1; // eax
  int16_t *v2; // edi
  int v3; // eax
  int v4; // eax
  char v5[100]; // [esp+0h] [ebp-78h] BYREF
  int v6; // [esp+64h] [ebp-14h]
  int v7; // [esp+68h] [ebp-10h]
  int v8; // [esp+6Ch] [ebp-Ch]
  char *v9; // [esp+70h] [ebp-8h]
  int v10; // [esp+74h] [ebp-4h]

  v0 = (uint16_t *)dword_1AD330;
  v6 = dword_1AD330 + 84 * word_199934;
  v9 = sub_114177();
  LOWORD(v1) = sub_123ABA();
  v2 = (int16_t *)(v0 + 6);
  v8 = v1;
  LOWORD(v3) = sub_123AE7();
  v10 = v3;
  sub_1172FC();
  sub_11E718();
  sub_1172D4();
  while ( v0 != (uint16_t *)v6 )
  {
    LOWORD(v4) = *v0;
    v7 = v4;
    sub_10CFD7((int)v2);
    if ( byte_1AD595 )
    {
      if ( v0[27] == (_WORD)v9 )
        sub_1297C3(word_183FF1[2 * (uint16_t)v7], word_183FF3[2 * (uint16_t)v7], 76, 88, 1, 255);
    }
    else if ( v0[27] == (_WORD)v9 )
    {
      if ( byte_1AD594 || v0[12] )
      {
        sub_120D79(2, (int)&unk_1840AF);
        word_1AD492 = sub_10CEF6(v2, v8, 255, 1);
      }
    }
    else if ( v0[24] == (_WORD)v9 )
    {
      sub_120D79(2, (int)&unk_1840AF);
      sub_1210FD(word_18400D[2 * (uint16_t)v7] + 4, v0[23] + 1, *(_DWORD *)(v0 + 25));
    }
    v4 = *(uint8_t *)(dword_192BD8 + 3680);
    if ( ((1 << v0[1]) & v4) != 0 )
    {
      sub_120D79(1, (int)&unk_1840AF);
      v4 = sub_1210FD(word_183FF1[2 * *v0] + 37, word_183FF3[2 * *v0] + 66, (int)&unk_1AD404);
    }
    v2 += 42;
    v0 += 42;
  }
  sub_10CFD7(dword_1AD398);
  if ( word_1AD490 == (_WORD)v9 && (*(_WORD *)(dword_1AD398 + 12) || byte_1AD594) )
  {
    sub_120D79(2, (int)&unk_1840AF);
    word_1AD492 = sub_10CEF6((int16_t *)dword_1AD398, v8, 255, 1);
  }
  if ( *(_WORD *)(dword_1AD39C + 12) )
  {
    sub_12B634();
    sub_12A478(v8 + 3, v10 + 2, *(_DWORD *)(dword_1AD39C + 24));
    sub_12B65C();
  }
  sub_131B5D(255, 10, 20, 5, 40, 60, 10, 7);
  sub_120D79(4, (int)&unk_1840AF);
  if ( byte_1AD593 )
  {
    if ( (uint8_t)byte_1AD593 <= 1u )
    {
      sub_12A478(133, 191, dword_1AD324);
      strcpy(v5, byte_1AD3A0);
      sub_FA5C6();
      sub_24D30();
      sub_103BC4(0x8Fu, 0xDAu, 350, (int)v5, 2);
    }
    else if ( byte_1AD593 == 2 )
    {
      sub_12A478(133, 191, dword_1AD324);
      strcpy(v5, byte_1AD334);
      sub_FA5C6();
      sub_24D30();
      sub_103BC4(0x8Fu, 0xD1u, 350, (int)v5, 2);
    }
  }
  JUMPOUT(0x10BDE6);
}
// 10CB33: control flows out of bounds to 10BDE6
// 10C90F: variable 'v1' is possibly undefined
// 10C917: variable 'v3' is possibly undefined
// 10C935: variable 'v4' is possibly undefined
// 183FF1: using guessed type int16_t word_183FF1[];
// 183FF3: using guessed type int16_t word_183FF3[13];
// 18400D: using guessed type int16_t word_18400D[];
// 192BD8: using guessed type int dword_192BD8;
// 199934: using guessed type int16_t word_199934;
// 1AD324: using guessed type int dword_1AD324;
// 1AD330: using guessed type int dword_1AD330;
// 1AD398: using guessed type int dword_1AD398;
// 1AD39C: using guessed type int dword_1AD39C;
// 1AD490: using guessed type int16_t word_1AD490;
// 1AD492: using guessed type int16_t word_1AD492;
// 1AD593: using guessed type char byte_1AD593;
// 1AD594: using guessed type char byte_1AD594;
// 1AD595: using guessed type char byte_1AD595;


//----- (0010CBDF) --------------------------------------------------------
int __fastcall sub_10CBDF( int a1, int16_t *a2)
{
  int v4; // eax

  *a2 = 0;
  if ( a1 == word_1AD490 )
    return dword_1AD398;
  v4 = dword_1AD330;
  while ( *a2 < word_199934 )
  {
    if ( a1 == *(_WORD *)(v4 + 54) )
      return v4 + 12;
    v4 += 84;
    ++*a2;
  }
  return 0;
}
// 199934: using guessed type int16_t word_199934;
// 1AD330: using guessed type int dword_1AD330;
// 1AD398: using guessed type int dword_1AD398;
// 1AD490: using guessed type int16_t word_1AD490;


//----- (0010CC4D) --------------------------------------------------------
void __fastcall sub_10CC4D(int16_t *a1)
{
  int16_t *v2; // ecx
  _BYTE v3[16]; // [esp+0h] [ebp-10h] BYREF

  sub_10CFD7(dword_1AD39C);
  v2 = *(int16_t **)(dword_1AD39C + 24);
  sub_12F7E6(1, 1, a1, v2);
  if ( word_1AD492 > 1 )
  {
    sub_120D79(2, (int)&unk_1840AF);
    itoa(word_1AD492, v3, 10, v2);
    sub_122A6E(8, 4, (int)v3, *(_DWORD *)(dword_1AD39C + 24));
  }
  sub_C0ABC();
}
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 1AD39C: using guessed type int dword_1AD39C;
// 1AD492: using guessed type int16_t word_1AD492;


//----- (0010CCC5) --------------------------------------------------------
void __fastcall sub_10CCC5(int a1)
{
  int v1; // esi
  int v2; // edx
  int v3; // edx
  int16_t v4; // cx
  int16_t v5; // bx

  if ( *(_WORD *)(dword_1AD39C + 12) )
  {
    v1 = *(uint16_t *)(dword_1AD39C + 12);
    v2 = *(uint16_t *)(a1 + 12);
    if ( v2 + v1 > 63 )
    {
      LOWORD(v1) = 63 - v2;
      word_1AD492 = *(_WORD *)(dword_1AD39C + 12) - (63 - v2);
    }
    v3 = dword_1AD39C;
    v4 = v1;
    if ( (uint16_t)v1 > *(_WORD *)(dword_1AD39C + 12) )
      v4 = *(_WORD *)(dword_1AD39C + 12);
    if ( v4 )
    {
      *(_WORD *)(a1 + 12) += v4;
      v5 = *(_WORD *)(v3 + 16);
      *(_WORD *)(v3 + 12) -= v4;
      *(_WORD *)(a1 + 16) = v5;
      *(_DWORD *)(a1 + 20) = *(_DWORD *)(v3 + 20);
      sub_10CDD8((_WORD *)a1);
      sub_10CDD8((_WORD *)v3);
    }
    if ( *(_WORD *)(dword_1AD39C + 12) )
      sub_10CC4D((int16_t *)dword_1AD32C);
    else
      sub_24E96(dword_1AD328);
  }
}
// 1AD328: using guessed type int dword_1AD328;
// 1AD32C: using guessed type int dword_1AD32C;
// 1AD39C: using guessed type int dword_1AD39C;
// 1AD492: using guessed type int16_t word_1AD492;


//----- (0010CD65) --------------------------------------------------------
void __fastcall sub_10CD65(int a1, int16_t *a2)
{
  int v4; // eax
  int16_t v5; // cx
  int v6; // edx
  int16_t v7; // bx

  v4 = dword_1AD39C;
  v5 = word_1AD492;
  v6 = a1;
  if ( (uint16_t)word_1AD492 > *(_WORD *)(a1 + 12) )
    v5 = *(_WORD *)(a1 + 12);
  if ( v5 )
  {
    *(_WORD *)(dword_1AD39C + 12) += v5;
    v7 = *(_WORD *)(a1 + 16);
    *(_WORD *)(v6 + 12) -= v5;
    *(_WORD *)(v4 + 16) = v7;
    *(_DWORD *)(v4 + 20) = *(_DWORD *)(v6 + 20);
    sub_10CDD8((_WORD *)v4);
    sub_10CDD8((_WORD *)v6);
  }
  sub_10CC4D(a2);
}
// 1AD39C: using guessed type int dword_1AD39C;
// 1AD492: using guessed type int16_t word_1AD492;


//----- (0010CDC1) --------------------------------------------------------
int __fastcall sub_10CDC1(int a1)
{
  return sub_12D8F5(187, 25, *(_DWORD *)(a1 + 24));
}


//----- (0010CDD8) --------------------------------------------------------
int16_t __fastcall sub_10CDD8(_WORD *a1)
{
  int16_t v2; // cx
  int16_t v3; // cx
  int v4; // esi
  int v5; // eax
  uint16_t v6; // si
  int16_t result; // ax

  v2 = a1[2] - *a1;
  a1[4] = a1[3] - a1[1] + 1;
  v3 = v2 + 1;
  if ( a1[6] <= 1u )
  {
    result = a1[8];
    a1[9] = result;
    a1[5] = result;
  }
  else
  {
    v4 = (uint16_t)a1[8];
    v5 = (v3 - v4) / ((int16_t)a1[6] - 1);
    if ( (int16_t)v5 > v4 )
      LOWORD(v5) = a1[8];
    if ( (v5 & 0x8000u) != 0 )
      LOWORD(v5) = 0;
    a1[9] = v5;
    v6 = a1[8] + (a1[6] - 1) * a1[9];
    result = v3;
    a1[5] = v6;
    if ( v6 > v3 )
      a1[5] = v3;
  }
  return result;
}


