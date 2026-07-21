#include "orion_common.h"

/* Adresni rozsah: 0x10CE64 - 0x11A2C8  (200 funkci) */

//----- (0010CE64) --------------------------------------------------------
int16_t sub_10CE64(int a1, int a2, int a3, _WORD *a4, int a5)
{
  *(_WORD *)a1 = *(_WORD *)a2;
  *(_WORD *)(a1 + 2) = *(_WORD *)(a2 + 2);
  *(_WORD *)(a1 + 4) = *(_WORD *)(a2 + 4);
  *(_WORD *)(a1 + 6) = *(_WORD *)(a2 + 6);
  *(_WORD *)(a1 + 8) = *(_WORD *)(a2 + 8);
  *(_DWORD *)(a1 + 28) = *(_DWORD *)(a2 + 10);
  *(_WORD *)(a1 + 12) = a3;
  if ( a4 )
    *(_WORD *)(a1 + 16) = *a4;
  else
    *(_WORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = a4;
  *(_DWORD *)(a1 + 24) = a5;
  return sub_10CDD8((_WORD *)a1);
}


//----- (0010CEBE) --------------------------------------------------------
int16_t sub_10CEBE(int a1, int a2, unsigned int a3)
{
  int16_t result; // ax

  result = a2;
  if ( a3 > *(_WORD *)(a1 + 12) )
    a3 = *(_WORD *)(a1 + 12);
  if ( a3 )
  {
    *(_WORD *)(a2 + 12) += a3;
    *(_WORD *)(a1 + 12) -= a3;
    *(_WORD *)(a2 + 16) = *(_WORD *)(a1 + 16);
    *(_DWORD *)(a2 + 20) = *(_DWORD *)(a1 + 20);
    sub_10CDD8((_WORD *)a2);
    return sub_10CDD8((_WORD *)a1);
  }
  return result;
}


//----- (0010CEF6) --------------------------------------------------------
int sub_10CEF6(int16_t *a1, int a2, int a3, int a4)
{
  int16_t v5; // bx
  int v6; // edi
  int v7; // edx
  int16_t v8; // ax
  int v9; // edx
  int v10; // ecx
  int16_t v12; // [esp+0h] [ebp-Ch]

  if ( !a1[6] )
  {
    sub_1297C3(*a1, a1[1], a1[8], a1[4], 1, a3);
    return 0;
  }
  v5 = a1[5] + *a1 - 1;
  if ( a2 > v5 )
    a2 = a1[5] + *a1 - 1;
  if ( a2 < (int)(uint16_t)*a1 )
    a2 = *a1;
  v6 = (a2 - (uint16_t)*a1) / (uint16_t)a1[9];
  v7 = (uint16_t)a1[6];
  if ( (int16_t)v6 >= v7 )
  {
    LOWORD(v6) = a1[6];
    --v6;
  }
  v8 = v6 * a1[9];
  LOWORD(v7) = a1[6];
  v9 = v7 - v6;
  if ( (int16_t)v9 <= 0 )
    return 0;
  v10 = a1[4];
  v12 = v8 + *a1;
  sub_1297C3(v12, a1[1], v5 - v12 + 1, v10, 1, a3);
  if ( a4 )
  {
    if ( (int16_t)v9 > 1 )
      sub_12102B((int16_t)(v12 + 3), (int16_t)(a1[1] + 3), (int16_t)v9, v10);
  }
  return v9;
}


//----- (0010CFD7) --------------------------------------------------------
void sub_10CFD7(int a1)
{
  int16_t v2; // di
  int v3; // [esp+0h] [ebp-4h]

  if ( *(_DWORD *)(a1 + 28) )
    (*(void (**)(void))(a1 + 28))();
  if ( *(_WORD *)(a1 + 12) )
  {
    v3 = 0;
    v2 = *(_WORD *)a1;
    do
    {
      if ( *(_DWORD *)(a1 + 24) )
        sub_12F7E6(v2, *(int16_t *)(a1 + 2), *(int16_t **)(a1 + 20), *(int16_t **)(a1 + 24));
      else
        sub_12A478(v2, *(_WORD *)(a1 + 2), *(_DWORD *)(a1 + 20));
      ++v3;
      v2 += *(_WORD *)(a1 + 18);
    }
    while ( (int16_t)v3 < (int)*(uint16_t *)(a1 + 12) );
  }
  JUMPOUT(0x10BDE6);
}
// 10D03C: control flows out of bounds to 10BDE6


//----- (0010D041) --------------------------------------------------------
int sub_10D041( int a1)
{
  _DWORD *v1; // eax
  int64_t v2; // rax
  int v4; // [esp+0h] [ebp+7Ah]
  int v5[17]; // [esp+4h] [ebp+7Eh] BYREF
  hr_int128_t v6; // [esp+48h] [ebp+C2h]
  int64_t v7; // [esp+58h] [ebp+D2h]
  int64_t v8; // [esp+60h] [ebp+DAh]
  int v9; // [esp+68h] [ebp+E2h]
  int v10; // [esp+6Ch] [ebp+E6h]

  sub_1112EC(dword_192ED4, (int)&loc_7C830);
  v1 = sub_110CEE(dword_192ED4, (int)&loc_7C830);
  sub_12D7B7((int)v1);
  sub_249F9(aBilltextLbx_2, 2, (char *)v5, 256);
  sub_24E73(256);
  HIDWORD(v2) = 1;
  sub_1034CB();
  sub_10D31C(
    v2,
    a1,
    v4,
    v5[0],
    v5[1],
    v5[2],
    v5[3],
    v5[4],
    v5[5],
    v5[6],
    v5[7],
    v5[8],
    v5[9],
    v5[10],
    v5[11],
    v5[12],
    v5[13],
    v5[14],
    v5[15],
    v5[16],(int)LODWORD(v6),
    v7,
    v8,
    v9,
    v10);
  sub_12D78E();
  sub_1113CC(dword_192ED4, 1);
  sub_C0AF4();
  return sub_2484F();
}
// 10D0B1: variable 'v2' is possibly undefined
// 10D0B1: variable 'v4' is possibly undefined
// 192ED4: using guessed type int dword_192ED4;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010D0DA) --------------------------------------------------------
int sub_10D0DA(int64_t a1, int a2)
{
  int v4[18]; // [esp+0h] [ebp-104h] BYREF
  hr_int128_t v5; // [esp+48h] [ebp-BCh]
  int64_t v6; // [esp+58h] [ebp-ACh]
  int64_t v7; // [esp+60h] [ebp-A4h]
  int v8; // [esp+68h] [ebp-9Ch]
  int v9; // [esp+6Ch] [ebp-98h]
  int v10; // [esp+100h] [ebp-4h]

  v10 = a2;
  sub_1112EC(dword_192ED4, (int)&loc_7C830);
  LODWORD(a1) = sub_110CEE(dword_192ED4, (int)&loc_7C830);
  sub_12D7B7(a1);
  sub_249F9(aBilltextLbx_2, 3, (char *)v4, 256);
  sub_24E27();
  HIDWORD(a1) = WORD2(a1);
  sub_103521();
  sub_10D31C(
    a1,
    SWORD2(a1),
    v4[0],
    v4[1],
    v4[2],
    v4[3],
    v4[4],
    v4[5],
    v4[6],
    v4[7],
    v4[8],
    v4[9],
    v4[10],
    v4[11],
    v4[12],
    v4[13],
    v4[14],
    v4[15],
    v4[16],
    v4[17],(int)LODWORD(v5),
    v6,
    v7,
    v8,
    v9);
  sub_12D78E();
  sub_1113CC(dword_192ED4, WORD2(a1));
  sub_C0AF4();
  LODWORD(a1) = sub_2484F();
  return a1;
}
// 10D144: variable 'a1' is possibly undefined
// 192ED4: using guessed type int dword_192ED4;


//----- (0010D167) --------------------------------------------------------
int sub_10D167( int a1, int a2, int a3)
{
  _DWORD *v4; // eax
  int64_t v5; // rax
  int v7[18]; // [esp+0h] [ebp-104h] BYREF
  hr_int128_t v8; // [esp+48h] [ebp-BCh]
  int64_t v9; // [esp+58h] [ebp-ACh]
  int64_t v10; // [esp+60h] [ebp-A4h]
  int v11; // [esp+68h] [ebp-9Ch]
  int v12; // [esp+6Ch] [ebp-98h]
  int v13; // [esp+100h] [ebp-4h] BYREF

  v13 = a2;
  sub_1112EC(dword_192ED4, (int)&loc_7C830);
  v4 = sub_110CEE(dword_192ED4, (int)&loc_7C830);
  sub_12D7B7((int)v4);
  sub_249F9(aBilltextLbx_2, 0, (char *)v7, 256);
  sub_24D83();
  v5 = ((int64_t (*)(_DWORD, int, int *, int *))loc_103428)(a1, 1, &v13, v7);
  sub_10D31C(
    v5,
    a3,
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
    v7[17],(int)LODWORD(v8),
    v9,
    v10,
    v11,
    v12);
  sub_12D78E();
  sub_1113CC(dword_192ED4, SHIDWORD(v5));
  sub_C0AF4();
  return sub_2484F();
}
// 192ED4: using guessed type int dword_192ED4;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010D1FC) --------------------------------------------------------
void sub_10D1FC( int a1)
{
  int v2; // edx
  uint16_t v3; // si
  int v4; // ecx
  uint16_t v5; // dx
  char *v6; // eax
  int v7; // ebx
  int64_t v8; // rax
  int v9[18]; // [esp+0h] [ebp-14Ch] BYREF
  hr_int128_t v10; // [esp+48h] [ebp-104h]
  int64_t v11; // [esp+58h] [ebp-F4h]
  int64_t v12; // [esp+60h] [ebp-ECh]
  int v13; // [esp+68h] [ebp-E4h]
  int v14; // [esp+6Ch] [ebp-E0h]
  _BYTE v15[72]; // [esp+100h] [ebp-4Ch] BYREF
  char *v16; // [esp+148h] [ebp-4h]

  v2 = 3753 * a1 + dword_197F98;
  v3 = 0;
  dword_192BD8 = v2;
  if ( *(_BYTE *)(v2 + 801) )
  {
    sub_10F772(*(uint8_t *)(v2 + 801));
    v4 = dword_192BD8;
    v5 = 0;
    v16 = (char *)&off_17D904 + 23 * *(uint8_t *)(dword_192BD8 + 801) + 10;
    do
    {
      v6 = &v16[2 * v5];
      if ( *(int16_t *)v6 > 0 && *(_BYTE *)(v4 + *(int16_t *)v6 + 279) == 3 )
      {
        v7 = v3++;
        *(_WORD *)&v15[2 * v7 + 64] = *(_WORD *)v6;
      }
      ++v5;
    }
    while ( v5 < 4u );
  }
  if ( v3 )
  {
    sub_249F9(aBilltextLbx_2, 1, (char *)v9, 250);
    sub_24E3E();
  }
  else
  {
    LOBYTE(v9[0]) = 0;
  }
  if ( v3 )
  {
    sprintf(v15, "SR_R%x_SC.LBX", *(uint8_t *)(dword_197F98 + 3753 * a1 + 37));
    HIDWORD(v8) = v3;
    LODWORD(v8) = v15;
    sub_10D31C(
      v8,
      a1,
      v9[0],
      v9[1],
      v9[2],
      v9[3],
      v9[4],
      v9[5],
      v9[6],
      v9[7],
      v9[8],
      v9[9],
      v9[10],
      v9[11],
      v9[12],
      v9[13],
      v9[14],
      v9[15],
      v9[16],
      v9[17],(int)LODWORD(v10),
      v11,
      v12,
      v13,
      v14);
  }
  else
  {
    sub_11C2F0();
    sub_C5BB9();
  }
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17D904: using guessed type _UNKNOWN *off_17D904;
// 192BD8: using guessed type int dword_192BD8;
// 197F98: using guessed type int dword_197F98;


//----- (0010D31C) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int16_t sub_10D31C(
        int64_t a1, int a2,
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
        hr_int128_t a21,
        int64_t a22,
        int64_t a23,
        int a24,
        int a25)
{
  _DWORD *v25; // esi
  int v26; // eax
  int v27; // eax
  int v28; // eax
  _DWORD *v29; // ecx
  int v30; // eax
  int v31; // ecx
  int v32; // edx
  int16_t v33; // si
  int v34; // ebx
  int v35; // eax
  int v36; // eax
  int16_t v37; // ax
  int v38; // eax
  int v39; // ecx
  _BYTE *v40; // eax
  int16_t *v41; // edx
  int v42; // ebx
  _DWORD *v43; // esi
  uint16_t v44; // bx
  int v45; // edx
  char *v46; // edi
  char *v47; // edi
  int v48; // eax
  int16_t i; // di
  int v50; // eax
  int v51; // ebx
  int16_t v52; // dx
  int16_t v53; // ax
  int v54; // eax
  int v55; // eax
  int v57; // [esp+72h] [ebp-21Eh]
  int v58; // [esp+76h] [ebp-21Ah]
  int16_t v59; // [esp+7Ah] [ebp-216h]
  int v60; // [esp+7Eh] [ebp-212h] BYREF
  _BYTE v61[512]; // [esp+82h] [ebp-20Eh] BYREF
  char v62[14]; // [esp+282h] [ebp-Eh] BYREF

  sub_107AF((int *)((char *)&a20 + 2));
  sub_1196F7();
  sub_12B65C();
  *(_DWORD *)((char *)&a23 + 2) = HIDWORD(a1);
  sub_1112EC(dword_192ED4, SHIDWORD(a1));
  LOWORD(a1) = sub_11C2F0();
  WORD2(a1) = 0;
  while ( WORD2(a1) < WORD1(a23) )
  {
    LOWORD(a1) = *(_WORD *)(v58 + 2 * WORD2(a1));
    BYTE1(a1) &= 1u;
    a1 = sprintf(&v61[64 * WORD2(a1) + 256], "TANM_%03hi.LBX", (uint16_t)a1);
  }
  sub_FE8BE(a1);
  v25 = sub_126B42((int)aScienceLbx, 0, dword_192ED4);
  dword_1AD598 = (int)sub_110D3C(dword_192ED4, 917);
  *(_DWORD *)((char *)&a21 + 2) = sub_110D3C(dword_192ED4, 1404);
  v26 = sub_12DAA4(175, 195);
  *(_DWORD *)((char *)&a21 + 10) = sub_110D3C(dword_192ED4, v26);
  v27 = sub_12DAA4(175, 195);
  *(_DWORD *)((char *)&a21 + 6) = sub_110D3C(dword_192ED4, v27);
  v28 = sub_12DAA4(600, 60);
  v29 = sub_110D3C(dword_192ED4, v28);
  sub_1278A3();
  if ( !byte_199BE2 )
  {
    v30 = sub_127C27((int)aScienceLbx, 1, dword_193174);
    sub_12B753(v30, 5);
  }
  sub_12D8F5(175, 195, *(int *)((char *)&a21 + 10));
  sub_12D8F5(175, 195, *(int *)((char *)&a21 + 6));
  sub_12D8F5(600, 60, (int)v29);
  sub_120DED(0, 240);
  sub_120D79(4, (int)&unk_184144);
  sub_123E6C((int)&unk_17CF4A, 1);
  sub_C5BB9();
  sub_12D1C5(v60, 0, 1, (int)v29);
  sub_11438B(0, 0, 639, 479, &unk_17A399, 0);
  *(_DWORD *)((char *)&a23 + 6) = sub_114C72(&off_17A39A, 2);
  sub_124D41();
  sub_1191CA((int)nullsub_19, 2);
  sub_C0ABC();
  sub_12E332(0);
  sub_12D8F5(30, 30, dword_1AD598);
  sub_12F578(dword_1AD598, (int)v25);
  sub_12E1E0(0, 0, (int16_t *)dword_1AD598, 0);
  sub_123E6C((int)&unk_17CF00, 1);
  sub_249F9(aBilltextLbx_2, 4, v62, 80);
  sub_127C27((int)aScienceLbx, 1, dword_193174);
  v31 = 479;
  sub_1318D4(0, 255);
  sub_12B79D((int)v25);
  sub_102CDF();
  sub_124C08();
  sub_128C32(0, 0, 639, 479, 0);
  v32 = 255;
  sub_12D408(1);
  sub_124DEC();
  v33 = 100;
  sub_102CDF();
  sub_113EE2();
  sub_119441();
  while ( v33 > 0 )
  {
    sub_24677(117, -2, 1);
    v33 -= 20;
    sub_12C2A0();
    if ( v33 < 0 )
      v33 = 0;
    sub_1318D4(0, 255);
    sub_132C80(v33);
    sub_131922(0, 255);
    v34 = sub_127C27((int)aScienceLbx, 2, dword_193174);
    v32 = 0;
    v35 = sub_12A478(0, 0, v34);
    sub_1077D(v35);
    sub_12C2C6(1);
  }
  sub_C5B94(0);
  if ( v59 )
  {
    *(_DWORD *)((char *)&a21 + 14) = 0;
    BYTE2(a25) = 1;
    BYTE2(a24) = 0;
    while ( 1 )
    {
      sub_24677(117, -2, 1);
      sub_12C2A0();
      v37 = sub_1171AB(v36, -2, 1, v31);
      if ( v37 || BYTE2(a25) == 1 )
      {
        if ( !WORD1(a23) || v37 == HIWORD(a23) )
        {
          for ( i = *(_WORD *)(sub_127C27((int)aScienceLbx, 1, dword_193174) + 4) - 1; i >= 0 && byte_199BE2; --i )
          {
            sub_12C2A0();
            v50 = sub_127C27((int)aScienceLbx, 1, dword_193174);
            sub_12B753(v50, i);
            sub_10DA98(0, 0, 1, 1);
            if ( i >= 5 )
            {
              v51 = *(_DWORD *)((char *)&a21 + 10);
              v52 = 44;
              v53 = 221;
            }
            else
            {
              sub_12E374(
                *(int16_t **)((char *)&a21 + 6),
                *(int16_t **)((char *)&a21 + 10),
                word_18414C[i],
                word_184158[i]);
              v51 = *(_DWORD *)((char *)&a21 + 6);
              v52 = word_18416E[i];
              v53 = word_184164[i];
            }
            sub_12A478(v53, v52, v51);
            v54 = sub_12C2C6(1);
            sub_1077D(v54);
            sub_24677(117, -2, 1);
          }
          v32 = 0;
          v55 = sub_10DA98(0, 0, 0, 0);
          sub_1077D(v55);
          break;
        }
        v38 = sub_10DA98(1, 0, 1, 1);
        v39 = HIWORD(a21);
        sub_1077D(v38);
        v40 = &v61[64 * v39 + 256];
        v39 *= 2;
        sub_12D1C5((int)v40, 0, 0, v39);
        sub_124D41();
        v41 = *(int16_t **)((char *)&a21 + 10);
        sub_12D7E3(0);
        sub_131F7B();
        sub_12E0B2(*(int *)((char *)&a21 + 6), v41);
        v42 = *(_DWORD *)((char *)&a21 + 2);
        sub_A6547((char *)&a15 + 2);
        v43 = sub_126BDD((int)&a15 + 2, 0, v42, *(_WORD *)(v39 + v58) & 0x1FF, 1u, 1403);
        sub_12D8F5(175, 195, *(int *)((char *)&a21 + 10));
        sub_120BB5(3, (int)&unk_18413C);
        sub_103BE2(2u, 1u, 171, (int)v43, 2, *(int *)((char *)&a21 + 10));
        *(_DWORD *)((char *)&a22 + 2) = sub_103CAF(171, (int)v43) + 1;
        sub_120BB5(2, (int)&unk_18413C);
        sub_120E24(1);
        if ( (*(_BYTE *)(v39 + v58 + 1) & 0x40) != 0 )
        {
          ++*(_DWORD *)((char *)&a21 + 14);
          sub_122A6E(2, SWORD1(a22), (int)v62, *(int *)((char *)&a21 + 10));
          v44 = 1;
          v45 = *(uint16_t *)(v58 + 2 * HIWORD(a21));
          v61[0] = 0;
          while ( v45 )
          {
            if ( (v45 & 1) != 0 )
            {
              v46 = (char *)&v60 + 3;
              do
                ++v46;
              while ( *v46 );
              strcpy(v46, *(char **)((char *)&off_17FD0B + 15 * v44));
              v47 = (char *)&v60 + 3;
              do
                ++v47;
              while ( *v47 );
              strcpy(v47, (char *)&off_17A39A + 2);
            }
            v45 >>= 1;
            ++v44;
          }
          sub_103BE2(2u, WORD1(a22) + 15, 171, (int)v61, 2, *(int *)((char *)&a21 + 10));
        }
        else
        {
          sub_103BE2(2u, WORD1(a22), 171, (int)v43 + 103, 2, *(int *)((char *)&a21 + 10));
        }
        BYTE2(a25) = 0;
        ++*(_DWORD *)((char *)&a21 + 14);
        --*(_DWORD *)((char *)&a23 + 2);
        if ( byte_199BE2 )
          a2 = 100;
        else
          a2 = 0;
        *(_DWORD *)((char *)&a22 + 6) = 6;
        do
          sub_10DA98(1, 0, 1, 1);
        while ( sub_124075() );
        sub_119441();
      }
      else
      {
        sub_10DA98(1, 1, 1, 1);
      }
      if ( BYTE2(a24) )
      {
        if ( a2 > 0 )
        {
          sub_12EEE7(*(int16_t **)((char *)&a21 + 6), *(int16_t **)((char *)&a21 + 10), a2, SHIWORD(a22));
          sub_12A478(221, 44, *(int *)((char *)&a21 + 6));
          a2 -= 20;
          if ( SHIWORD(a22) > 1 )
            --*(_DWORD *)((char *)&a22 + 6);
        }
        else
        {
          sub_12A478(221, 44, *(int *)((char *)&a21 + 10));
        }
      }
      else
      {
        BYTE2(a24) = *(_WORD *)(sub_127C27((int)aScienceLbx, 1, dword_193174) + 4) >= 5;
      }
      v31 = v57;
      sub_120DED(0, 242);
      sub_120D79(4, (int)&unk_184144);
      sub_103BC4(0x91u, 0x1A4u, 380, v57, 2);
      v48 = sub_12C2C6(1);
      sub_1077D(v48);
    }
  }
  sub_1113CC(dword_192ED4, v32);
  sub_11C2F0();
  sub_119441();
  sub_113F0A();
  sub_107BA((int *)((char *)&a20 + 2));
  return sub_C5B94(0);
}
// 10D675: inconsistent variable size for '^304.16'
// 10D7C2: inconsistent variable size for '^304.16'
// 10D872: inconsistent variable size for '^304.16'
// 10D88A: inconsistent variable size for '^314.8'
// 10D90F: inconsistent variable size for '^314.8'
// 10D4FC: inconsistent variable size for '^31C.8'
// 1077D: using guessed type int sub_1077D(_DWORD);
// FE8BE: using guessed type int sub_FE8BE(_DWORD);
// 10DB16: using guessed type int nullsub_19(_DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17A39A: using guessed type _UNKNOWN *off_17A39A;
// 17FD0B: using guessed type _UNKNOWN *off_17FD0B;
// 18414C: using guessed type int16_t word_18414C[6];
// 184158: using guessed type int16_t word_184158[6];
// 184164: using guessed type int16_t word_184164[5];
// 18416E: using guessed type int16_t word_18416E[5];
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 199BE2: using guessed type char byte_199BE2;
// 1AD598: using guessed type int dword_1AD598;


//----- (0010DA98) --------------------------------------------------------
int sub_10DA98(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // ebx
  int v6; // ebx

  if ( byte_199BE2 )
    v4 = sub_12CAD6(1);
  else
    v4 = sub_12D6B2(18);
  if ( a3 == 1 )
  {
    v5 = sub_127C27((int)aScienceLbx, 2, dword_193174);
    v4 = sub_12A478(0, 0, v5);
  }
  if ( a2 )
    v4 = sub_12D408(0);
  if ( a4 == 1 )
  {
    v6 = sub_127C27((int)aScienceLbx, 1, dword_193174);
    v4 = sub_12A478(0, 0, v6);
  }
  return nullsub_19(v4);
}
// 10DB16: using guessed type int nullsub_19(_DWORD);
// 193174: using guessed type int dword_193174;
// 199BE2: using guessed type char byte_199BE2;


//----- (0010DB17) --------------------------------------------------------
void sub_10DB17(int a1, int a2, unsigned int a3)
{
  char *v3; // esi
  char *v4; // edi
  int16_t v5; // [esp+0h] [ebp-54h]
  char v6; // [esp+3h] [ebp-51h] BYREF
  int16_t v7[40]; // [esp+4h] [ebp-50h] BYREF

  v7[0] = word_17A3A0;
  v3 = sub_10F7A1(a3, word_19999C);
  v4 = &v6;
  do
    ++v4;
  while ( *v4 );
  strcpy(v4, v3);
  sub_102F10(v5, a2, (int)v7, 213);
}
// 10DB5F: variable 'v5' is possibly undefined
// 17A3A0: using guessed type int16_t word_17A3A0;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010DB69) --------------------------------------------------------
int sub_10DB69(int a1, int16_t *a2)
{
  _DWORD *v2; // eax

  sub_131970();
  v2 = sub_110CEE(dword_192ED4, (int)&loc_7C830);
  sub_12D7B7((int)v2);
  sub_10D1FC(word_19999C);
  sub_10DC12(0, 255, a1, a2);
  sub_C5BB9();
  sub_1319A3();
  sub_102CDF();
  sub_131922(0, 255);
  sub_1196F7();
  sub_C0AF4();
  sub_12D78E();
  return sub_2484F();
}
// 192ED4: using guessed type int dword_192ED4;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010DBCE) --------------------------------------------------------
int16_t sub_10DBCE(int a1, int16_t *a2)
{
  int16_t result; // ax

  sub_110CEE(dword_192ED4, 4);
  sub_124D41();
  sub_11E718();
  sub_124DEC();
  sub_10DC12(1, 4, a1, a2);
  result = word_199A10;
  word_199A08 = word_199A10;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;


//----- (0010DC12) --------------------------------------------------------
void sub_10DC12(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // edx
  int16_t v5; // si
  int v6; // eax
  char v7; // bl
  int16_t v8; // cx
  int v9; // edx
  int v10; // ebx
  int v11; // eax
  int v12; // ebx
  _DWORD *v13; // eax
  int v14; // ebx
  int v15; // ebx
  _DWORD *v16; // eax
  int v17; // edx
  int v18; // ebx
  _DWORD *v19; // eax
  int v20; // ebx
  _DWORD *v21; // eax
  int v22; // ebx
  int v23; // ebx
  int v24; // edi
  int v25; // eax
  int v26; // eax
  uint16_t v27; // si
  int16_t *v28; // eax
  int v29; // ebx
  uint64_t v30; // rax
  int16_t v31; // si
  int v32; // ebx
  int v33; // eax
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // edx
  int v38; // eax
  int16_t *v39; // ecx
  int v40; // eax
  int v41; // edx
  int16_t v42; // si
  int v43; // ecx
  char v44; // al
  _BYTE v45[64]; // [esp+0h] [ebp-1Ah] BYREF
  _DWORD *v46; // [esp+40h] [ebp+26h]
  _WORD *v47; // [esp+44h] [ebp+2Ah] BYREF
  _DWORD *v48; // [esp+48h] [ebp+2Eh]
  _DWORD *v49; // [esp+4Ch] [ebp+32h]
  _DWORD *v50; // [esp+50h] [ebp+36h]
  _DWORD *v51; // [esp+54h] [ebp+3Ah]
  _DWORD *v52; // [esp+58h] [ebp+3Eh]
  _DWORD *v53; // [esp+5Ch] [ebp+42h]
  _DWORD *v54; // [esp+60h] [ebp+46h]
  _WORD *v55; // [esp+74h] [ebp+5Ah]
  int v56; // [esp+78h] [ebp+5Eh] BYREF
  _DWORD *v57; // [esp+7Ch] [ebp+62h]
  int16_t *v58; // [esp+80h] [ebp+66h]
  int v59; // [esp+84h] [ebp+6Ah]
  unsigned int v60; // [esp+88h] [ebp+6Eh]
  int v61; // [esp+8Ch] [ebp+72h]
  int v62; // [esp+90h] [ebp+76h]
  int16_t v63; // [esp+94h] [ebp+7Ah]
  uint8_t v64; // [esp+98h] [ebp+7Eh]

  v64 = a1;
  sub_FE8BE(a1, a2, a3, a4);
  sub_11C2F0();
  sub_124C08();
  sub_107AF(&v56);
  v4 = 0;
  sub_1112EC(dword_192ED4, 0);
  v5 = word_19999C;
  do
  {
    v6 = (int16_t)v4;
    v7 = *(_BYTE *)(3753 * v5 + dword_197F98 + (int16_t)v4++ + 540);
    byte_1AD59C[v6] = v7;
  }
  while ( (int16_t)v4 < 8 );
  v8 = word_19999C;
  v9 = 0;
  do
  {
    v10 = 3753 * v8 + dword_197F98;
    v11 = (int16_t)v9++;
    ++*(_BYTE *)(v10 + v11 + 540);
  }
  while ( (int16_t)v9 < 8 );
  sub_113E92();
  dword_192BD8 = 3753 * word_19999C + dword_197F98;
  byte_1AD6BA = v64;
  v63 = *(uint8_t *)(dword_192BD8 + 801);
  v58 = (int16_t *)sub_110D3C(dword_192ED4, 3136);
  dword_192BC8 = (int)sub_110D3C(dword_192ED4, 1404);
  sub_FE8BE(dword_192BC8, 1404, v10, a4);
  if ( v64 == 1 )
  {
    word_1AD6B4 = 80;
    word_1AD6B6 = 0;
    byte_1AD6BB = -17;
    v12 = dword_192ED4;
    qmemcpy(&unk_1AD5A4, &unk_18426F, 0x28u);
    v46 = sub_126B42((int)aTechselLbx, 14, dword_192ED4);
    sub_FE8BE((int)v46, 15, v12, (int16_t *)byte_1AD5CC);
    v47 = sub_126B42((int)aTechselLbx, 15, dword_192ED4);
    v48 = sub_126B42((int)aTechselLbx, 16, dword_192ED4);
    v13 = sub_126B42((int)aTechselLbx, 17, dword_192ED4);
    v14 = dword_192ED4;
    v49 = v13;
    v50 = sub_126B42((int)aTechselLbx, 18, dword_192ED4);
    sub_FE8BE((int)v50, 19, v14, (int16_t *)byte_1AD5CC);
    v51 = sub_126B42((int)aTechselLbx, 19, dword_192ED4);
    v52 = sub_126B42((int)aTechselLbx, 20, dword_192ED4);
    v15 = dword_192ED4;
    v53 = sub_126B42((int)aTechselLbx, 21, dword_192ED4);
    sub_FE8BE((int)v53, 22, v15, (int16_t *)byte_1AD5CC);
    v16 = sub_126B42((int)aTechselLbx, 22, dword_192ED4);
    v17 = 27;
  }
  else
  {
    word_1AD6B4 = 161;
    word_1AD6B6 = 0;
    byte_1AD6BB = -1;
    v18 = dword_192ED4;
    qmemcpy(&unk_1AD5A4, &unk_184247, 0x28u);
    v46 = sub_126B42((int)aTechselLbx, 0, dword_192ED4);
    sub_FE8BE((int)v46, 1, v18, (int16_t *)byte_1AD5CC);
    v47 = sub_126B42((int)aTechselLbx, 1, dword_192ED4);
    v19 = sub_126B42((int)aTechselLbx, 2, dword_192ED4);
    v20 = dword_192ED4;
    v48 = v19;
    v49 = sub_126B42((int)aTechselLbx, 3, dword_192ED4);
    sub_FE8BE((int)v49, 4, v20, (int16_t *)byte_1AD5CC);
    v50 = sub_126B42((int)aTechselLbx, 4, dword_192ED4);
    v21 = sub_126B42((int)aTechselLbx, 5, dword_192ED4);
    v22 = dword_192ED4;
    v51 = v21;
    v52 = sub_126B42((int)aTechselLbx, 6, dword_192ED4);
    sub_FE8BE((int)v52, 6, v22, (int16_t *)byte_1AD5CC);
    v53 = sub_126B42((int)aTechselLbx, 7, dword_192ED4);
    v16 = sub_126B42((int)aTechselLbx, 8, dword_192ED4);
    v17 = 13;
  }
  v23 = dword_192ED4;
  v54 = v16;
  v55 = sub_126B42((int)aTechselLbx, v17, dword_192ED4);
  sub_FE8BE((int)v55, v17, v23, (int16_t *)byte_1AD5CC);
  byte_1842BE = byte_1AD6BB;
  if ( v64 == 1 )
  {
    v24 = (int)sub_1151B0(word_1AD6B4 + 189, word_1AD6B6 + 452, (int)&unk_17A3A4, v55, byte_17A3A2, 40);
    *(_BYTE *)(dword_192BD8 + 801) = 0;
    sub_10EFC3(v58);
    sub_10F089();
    v61 = v25;
    *(_BYTE *)(dword_192BD8 + 801) = v63;
  }
  else
  {
    sub_10EFC3(v58);
    v24 = -1;
    if ( *(_BYTE *)(dword_192BD8 + 801) >= 0x4Bu )
      *(_BYTE *)(dword_192BD8 + 801) = 0;
    sub_10F089();
    v61 = v26;
  }
  word_1AD6B2 = sub_113E65();
  v27 = 0;
  do
  {
    v28 = &v58[196 * v27];
    v29 = (int16_t)(*v28 + 215);
    ++v27;
    HIDWORD(v30) = (int16_t)(v28[1] + 18);
    LODWORD(v30) = sub_11438B(*v28 - 2, SWORD2(v30), v29, v28[1] + 99, &unk_17A3A4, 0);
    word_1AD6B8 = v30;
  }
  while ( v27 < 8u );
  sub_FE8BE(v30, SHIDWORD(v30), v29, (int16_t *)v24);
  if ( !(_WORD)v61 )
  {
LABEL_63:
    sub_1113CC(dword_192ED4, SHIDWORD(v30));
    v41 = 0;
    sub_107BA(&v56);
    sub_11C2F0();
    v42 = word_19999C;
    do
    {
      v43 = (int16_t)v41 + 3753 * v42 + dword_197F98;
      v44 = byte_1AD59C[(int16_t)v41++];
      *(_BYTE *)(v43 + 540) = v44;
    }
    while ( (int16_t)v41 < 8 );
    sub_1196F7();
    JUMPOUT(0x10E6C1);
  }
  v31 = sub_113E65();
  v32 = 639;
  sub_10F409((int)v58, &v47);
  LOWORD(v33) = sub_113E65();
  v62 = v33 - 1;
  sub_11438B(0, 0, 639, 479, &unk_17A3A4, 0);
  dword_1AD698 = (int)v58;
  v30 = sprintf(v45, "SR_R%x_SC.LBX", *(uint8_t *)(dword_197F98 + 3753 * word_19999C + 37));
  sub_FE8BE(v30, SHIDWORD(v30), 639, (int16_t *)v24);
  if ( !v64 )
  {
    sub_12C607((int)v45, 0, 639, 479);
    v32 = dword_192ED4;
    HIDWORD(v30) = 0;
    v57 = sub_126B42((int)aScienceLbx_0, 0, dword_192ED4);
  }
  LODWORD(v30) = v58 + 1568;
  v60 = (unsigned int)(v58 + 1568);
LABEL_19:
  sub_FE8BE(v30, SHIDWORD(v30), v32, (int16_t *)v24);
  if ( !v64 )
  {
    sub_124D41();
    sub_128C32(0, 0, 639, 479, 0);
    if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 37) == 7 )
      v34 = 17;
    else
      v34 = 0;
    sub_12D6B2(v34);
    sub_12C7CC();
    v32 = (int16_t)(word_1AD6B4 + 471);
    HIDWORD(v30) = (int16_t)(word_1AD6B6 + 4);
    sub_128C32((int16_t)(word_1AD6B4 + 4), SHIDWORD(v30), v32, (int16_t)(word_1AD6B6 + 472), 0);
    sub_12B79D((int)v46);
    sub_131F7B();
    sub_12B79D((int)v57);
    sub_131F7B();
  }
  sub_117174(5);
  if ( v64 == 1 )
    sub_103A3F();
  else
    sub_103A2D();
  sub_FE8BE(v30, SHIDWORD(v30), v32, (int16_t *)v24);
  word_19994C = 0;
  sub_1191CA((int)sub_10E4B2, 4);
  sub_128C32(
    (int16_t)(word_1AD6B4 + 4),
    (int16_t)(word_1AD6B6 + 4),
    (int16_t)(word_1AD6B4 + 471),
    (int16_t)(word_1AD6B6 + 472),
    0);
  v32 = (int)v46;
  sub_12A478(word_1AD6B4, word_1AD6B6, (int)v46);
  v35 = dword_1AD698;
  HIDWORD(v30) = dword_1AD698 + 3136;
  do
  {
    LODWORD(v30) = v35;
    v35 += 392;
    sub_10ED00(v30);
  }
  while ( v35 != HIDWORD(v30) );
  sub_FE8BE(v30, SHIDWORD(v30), v32, (int16_t *)v24);
  sub_124DEC();
  sub_10E4B2(v24);
  if ( !v64 )
    sub_24E96((int)v55);
  sub_C5C44();
  sub_131B34();
  LOWORD(v30) = sub_119441();
  sub_FE8BE(v30, SHIDWORD(v30), v32, (int16_t *)v24);
  while ( 1 )
  {
    if ( !v64 )
    {
      v32 = 1;
      v30 = (unsigned int)sub_24677(117, -2, 1) | 0xFFFFFFFE00000000LL;
    }
    LODWORD(v30) = sub_1171AB(v30, SHIDWORD(v30), v32, v35);
    HIDWORD(v30) = v30;
    if ( word_19994C )
      goto LABEL_19;
    if ( (v30 & 0x8000u) != 0LL )
    {
      HIDWORD(v30) = -(int)v30;
      if ( (int16_t)-(int16_t)v30 < v31 || SWORD2(v30) > (int16_t)v62 )
      {
        LODWORD(v30) = sub_10EF45((int)v58, SWORD2(v30));
        if ( (_DWORD)v30 )
        {
          LODWORD(v30) = dword_1AD698;
          HIDWORD(v30) = dword_1AD698 + 3136;
          do
          {
            if ( *(_BYTE *)(v30 + 6) )
              goto LABEL_43;
            LODWORD(v30) = v30 + 392;
          }
          while ( (_DWORD)v30 != HIDWORD(v30) );
          LODWORD(v30) = HIDWORD(v30) ^ v30;
LABEL_43:
          HIDWORD(v30) = *(uint16_t *)(v30 + 7);
          dword_1AD69C = v30;
          WORD2(v30) = *(_WORD *)(v30 + 2 * HIDWORD(v30) + 382);
          if ( WORD2(v30) )
          {
            sub_10EE6F(v30);
            HIDWORD(v30) = WORD2(v30);
            sub_10F62F(281, SWORD2(v30));
            goto LABEL_19;
          }
        }
        HIDWORD(v30) = 0;
      }
    }
    if ( SWORD2(v30) <= 0 )
    {
      sub_12C2A0();
      sub_10E4B2(v24);
      LODWORD(v30) = sub_12C2C6(2);
      LODWORD(v30) = sub_1077D(v30, SHIDWORD(v30), v32, (int16_t *)v24);
    }
    else if ( SWORD2(v30) <= (int16_t)v24 || SWORD2(v30) >= v31 )
    {
      if ( SWORD2(v30) >= v31 && SWORD2(v30) <= (int16_t)v62 )
      {
        v59 = (uint16_t)(WORD2(v30) - v31);
        v39 = &v58[196 * v59];
        sub_12B753(*(_DWORD *)((char *)v39 + 77), 1);
        v40 = v59;
        v59 = (int16_t)(word_184221[2 * v59] + word_1AD6B6);
        v32 = *(_DWORD *)((char *)v39 + 77);
        sub_12A478(word_18421F[2 * v40] + word_1AD6B4, v59, v32);
        sub_124DEC();
        HIDWORD(v30) = v64;
        *(int16_t *)((char *)v39 + 75) = 0;
        LODWORD(v30) = sub_10E6C7((int)v39, SHIDWORD(v30), v32, (int16_t *)v24);
        goto LABEL_19;
      }
    }
    else
    {
      v36 = (int)v58;
      do
      {
        if ( *(_BYTE *)(v36 + 6) )
          goto LABEL_53;
        v36 += 392;
      }
      while ( v36 != v60 );
      v36 ^= v60;
LABEL_53:
      v37 = 3;
      dword_1AD69C = v36;
      do
      {
        sub_12C2A0();
        if ( (v37 & 1) == 0 )
          v38 = sub_10EE6F(dword_1AD69C);
        sub_1077D(v38, v37--, v32, (int16_t *)v24);
        sub_12C2C6(4);
      }
      while ( (_WORD)v37 );
      LODWORD(v30) = dword_1AD69C;
      v35 = dword_192BD8;
      *(_BYTE *)(dword_192BD8 + 801) = *(_BYTE *)(dword_1AD69C + 81);
      LOBYTE(v30) = *(_BYTE *)(v30 + 2 * *(uint16_t *)(v30 + 7) + 382);
      HIDWORD(v30) = v24;
      *(_BYTE *)(v35 + 802) = v30;
    }
    if ( WORD2(v30) == (_WORD)v24 )
      goto LABEL_63;
  }
}
// 10E4AD: control flows out of bounds to 10E6C1
// 10DFB4: variable 'v25' is possibly undefined
// 10DFF3: variable 'v26' is possibly undefined
// 10E089: variable 'v33' is possibly undefined
// 10E0FA: variable 'v30' is possibly undefined
// 10E374: variable 'v38' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17A3A2: using guessed type _BYTE byte_17A3A2[2];
// 18421F: using guessed type int16_t word_18421F[];
// 184221: using guessed type int16_t word_184221[15];
// 1842BE: using guessed type char byte_1842BE;
// 192BC8: using guessed type int dword_192BC8;
// 192BD8: using guessed type int dword_192BD8;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 1AD698: using guessed type int dword_1AD698;
// 1AD69C: using guessed type int dword_1AD69C;
// 1AD6B2: using guessed type int16_t word_1AD6B2;
// 1AD6B4: using guessed type int16_t word_1AD6B4;
// 1AD6B6: using guessed type int16_t word_1AD6B6;
// 1AD6B8: using guessed type int16_t word_1AD6B8;
// 1AD6BA: using guessed type char byte_1AD6BA;
// 1AD6BB: using guessed type char byte_1AD6BB;


//----- (0010E4B2) --------------------------------------------------------
char sub_10E4B2(int a1)
{
  int16_t v1; // ax
  int16_t v2; // dx
  int v3; // eax
  int v4; // edx

  v1 = (uint16_t)sub_114177();
  v2 = v1;
  if ( v1 >= word_1AD6B2 && v1 <= word_1AD6B8 )
  {
    dword_1AD69C = 392 * (v1 - word_1AD6B2) + dword_1AD698;
    v2 = *(_WORD *)(dword_1AD69C + 2 * *(uint8_t *)(dword_1AD69C + 107) + 372);
  }
  if ( v2 > 0 )
    sub_10EF45(dword_1AD698, v2);
  v3 = dword_1AD698;
  v4 = dword_1AD698 + 3136;
  while ( !*(_BYTE *)(v3 + 6) )
  {
    v3 += 392;
    if ( v3 == v4 )
    {
      v3 ^= v4;
      break;
    }
  }
  dword_1AD69C = v3;
  sub_10EE6F(v3);
  sub_10E563(dword_1AD69C, a1);
  return sub_131B5D((uint8_t)byte_1AD6BB, 8, 32, 0, 40, 63, 8, 8);
}
// 1AD698: using guessed type int dword_1AD698;
// 1AD69C: using guessed type int dword_1AD69C;
// 1AD6B2: using guessed type int16_t word_1AD6B2;
// 1AD6B8: using guessed type int16_t word_1AD6B8;
// 1AD6BB: using guessed type char byte_1AD6BB;


//----- (0010E563) --------------------------------------------------------
int sub_10E563(int result, int a2)
{
  int v2; // esi
  int v3; // [esp+4h] [ebp-20h]
  int16_t v4; // [esp+Ch] [ebp-18h]
  int16_t v5; // [esp+10h] [ebp-14h]
  int16_t v6; // [esp+14h] [ebp-10h]
  int16_t v7; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int16_t v9; // [esp+20h] [ebp-4h]

  v2 = result;
  if ( result && *(_BYTE *)(result + 6) && *(_WORD *)(result + 81) )
  {
    LOWORD(a2) = *(_WORD *)(result + 7);
    v7 = a2 + 1;
    if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 2229) == 1
      || *(_WORD *)(result + 81) == 55
      || *(_WORD *)(result + 81) == 57
      || *(_WORD *)(result + 81) == 29
      || *(_WORD *)(result + 81) == 22
      || *(_WORD *)(result + 81) == 28
      || *(_WORD *)(result + 81) == 23 )
    {
      a2 = 0;
      v7 = *(uint8_t *)(result + 107);
    }
    for ( i = a2; ; ++i )
    {
      result = i;
      if ( (int16_t)i >= v7 )
        break;
      v9 = *(_WORD *)(v2 + 364) - 2;
      v4 = *(_WORD *)(v2 + 2 * (int16_t)i + 366) + 5;
      v6 = *(_WORD *)(v2 + 364) - 5;
      v5 = (uint8_t)byte_1AD6BB;
      v3 = (int16_t)(*(_WORD *)(v2 + 364) - 9);
      sub_134D2D(v3, (int16_t)(*(_WORD *)(v2 + 366) - 3), v3, v4, (uint8_t)byte_1AD6BB);
      sub_134D2D(v3, v4, v9, v4, v5);
      sub_134D2D(v6, (int16_t)(v4 - 3), v9, v4, v5);
      sub_134D2D(v6, (int16_t)(v4 + 3), v9, v4, v5);
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 1AD6BB: using guessed type char byte_1AD6BB;


//----- (0010E6C7) --------------------------------------------------------
int16_t *sub_10E6C7(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  _DWORD *v9; // eax
  int v10; // ebx
  _DWORD *v11; // eax
  int v12; // edx
  _DWORD *v13; // eax
  int v14; // ebx
  int v15; // ebx
  _DWORD *v16; // eax
  int v17; // edx
  int v18; // eax
  _DWORD *v19; // ecx
  int v20; // edx
  _WORD *v21; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // esi
  char *v25; // edi
  int v26; // ebx
  int v27; // edx
  int v28; // eax
  int v29; // eax
  int v30; // ecx
  int v31; // ebx
  int16_t *v32; // edi
  int v33; // edx
  int v34; // eax
  int v35; // esi
  int v36; // eax
  _DWORD *v37; // ebx
  int v38; // eax
  int v40; // [esp+0h] [ebp-56h]
  char v41[116]; // [esp+4h] [ebp-52h] BYREF
  _DWORD *v42; // [esp+78h] [ebp+22h]
  _DWORD *v43; // [esp+7Ch] [ebp+26h]
  _WORD *v44; // [esp+80h] [ebp+2Ah]
  _WORD *v45; // [esp+84h] [ebp+2Eh]
  char v46; // [esp+8Bh] [ebp+35h] BYREF
  int16_t v47[16]; // [esp+8Ch] [ebp+36h] BYREF
  int v48; // [esp+ACh] [ebp+56h] BYREF
  _DWORD *v49; // [esp+B0h] [ebp+5Ah]
  char *v50; // [esp+B4h] [ebp+5Eh]
  char *v51; // [esp+B8h] [ebp+62h]
  int v52; // [esp+BCh] [ebp+66h]
  int v53; // [esp+C0h] [ebp+6Ah]
  int v54; // [esp+C4h] [ebp+6Eh]
  int v55; // [esp+C8h] [ebp+72h]
  int v56; // [esp+CCh] [ebp+76h]
  int v57; // [esp+D0h] [ebp+7Ah]
  char v58; // [esp+D4h] [ebp+7Eh]

  v58 = a2;
  sub_FE8BE(a1, a2, a3, a4);
  sub_249F9(aBilltextLbx_3, 63, v41, 80);
  sub_249F9(aBilltextLbx_3, 64, byte_1AD5CC, 20);
  LOBYTE(v4) = sub_249F9(aBilltextLbx_3, 65, byte_1AD5E0, 20);
  sub_FE8BE(v4, 65, (int)byte_1AD5E0, a4);
  sub_249F9(aBilltextLbx_3, 66, byte_1AD5F4, 20);
  LOBYTE(v5) = sub_249F9(aBilltextLbx_3, 67, byte_1AD608, 20);
  sub_FE8BE(v5, 67, (int)byte_1AD608, a4);
  sub_249F9(aBilltextLbx_3, 68, byte_1AD61C, 20);
  LOBYTE(v6) = sub_249F9(aBilltextLbx_3, 69, byte_1AD630, 20);
  sub_FE8BE(v6, 69, (int)byte_1AD630, a4);
  sub_249F9(aBilltextLbx_3, 70, byte_1AD644, 20);
  LOBYTE(v7) = sub_249F9(aBilltextLbx_3, 71, byte_1AD658, 20);
  sub_FE8BE(v7, 71, (int)byte_1AD658, a4);
  sub_249F9(aBilltextLbx_3, 72, byte_1AD66C, 20);
  LOBYTE(v8) = sub_249F9(aBilltextLbx_3, 73, byte_1AD680, 20);
  sub_FE8BE(v8, 73, (int)byte_1AD680, a4);
  sub_107AF(&v48);
  sub_1112EC(dword_192ED4, 73);
  sub_10FE41((int)&unk_1AD6A0);
  sub_113E92();
  if ( v58 == 1 )
  {
    v9 = sub_126B42((int)aTechselLbx, 23, dword_192ED4);
    v10 = dword_192ED4;
    v42 = v9;
    v43 = sub_126B42((int)aTechselLbx, 24, dword_192ED4);
    sub_FE8BE((int)v43, 25, v10, a4);
    v11 = sub_126B42((int)aTechselLbx, 25, dword_192ED4);
    v12 = 26;
  }
  else
  {
    v13 = sub_126B42((int)aTechselLbx, 9, dword_192ED4);
    v14 = dword_192ED4;
    v42 = v13;
    v43 = sub_126B42((int)aTechselLbx, 10, dword_192ED4);
    sub_FE8BE((int)v43, 11, v14, a4);
    v11 = sub_126B42((int)aTechselLbx, 11, dword_192ED4);
    v12 = 12;
  }
  v15 = dword_192ED4;
  v44 = v11;
  v45 = sub_126B42((int)aTechselLbx, v12, dword_192ED4);
  sub_FE8BE((int)v45, v12, v15, a4);
  v16 = sub_110D3C(dword_192ED4, 13280);
  HIWORD(v17) = HIWORD(v40);
  LOWORD(v17) = *(_WORD *)(v40 + 390);
  dword_1842AD = (int)v16;
  v52 = v17;
  word_184297 = v17 + 16;
  v18 = sub_12DAA4(437, 400);
  v19 = sub_110D3C(dword_192ED4, v18);
  v49 = v19;
  sub_12D8F5(437, 400, (int)v19);
  sub_12E148(84, 40, 519, 439, (int)v19);
  if ( (uint16_t)v52 - (uint16_t)word_1AD6B4 <= 6 )
  {
    if ( v58 )
      sub_103A8D();
    else
      sub_103A63();
  }
  else if ( v58 )
  {
    sub_103A78();
  }
  else
  {
    sub_103A51();
  }
  v20 = *(uint16_t *)(v40 + 4);
  sub_10F49B((int)&word_184297, v20);
  v21 = v44;
  sub_10A0A7((int)&word_184297, v20, 519);
  v50 = sub_1151B0(v52 + 247, 77, (int)&unk_17A3A4, v21, &unk_17A3A4, 0);
  v51 = sub_1151B0(v52 + 248, 398, (int)&unk_17A3A4, v45, &unk_17A3A4, 0);
  LOWORD(v22) = sub_113E65();
  v23 = v22;
  v53 = v22;
  sub_1191CA((int)sub_10EC96, 4);
  v57 = v52 + 267;
  v55 = v23 - 1;
  v54 = v52 + 134;
LABEL_12:
  word_19994C = 0;
  v24 = (int16_t)v52;
  sub_128C32(84, 40, 519, 439, 0);
  sub_12A478(84, 40, (int)v49);
  sub_128C32(v24, 31, (int16_t)v57, 449, 0);
  sub_12A478(v24, 31, (int)v42);
  strcpy((char *)v47, &byte_1AD5CC[20 * *(uint16_t *)(v40 + 4)]);
  v25 = &v46;
  do
    ++v25;
  while ( *v25 );
  strcpy(v25, v41);
  sub_120BB5(4, (int)&unk_1AD5A4);
  sub_1210FD(v54, 47, (int)v47);
  v26 = (int16_t)v51;
  v27 = (int16_t)v50;
  sub_10A4A7((int)&word_184297);
  sub_124DEC();
  LOWORD(v28) = sub_10A689((int)&word_184297, v27, v26);
  sub_1077D(v28, v27, v26, v47);
  sub_12C2A0();
  sub_119400(v55);
  sub_10A188((int)&word_184297);
  v56 = v29;
  v30 = 479;
  v31 = 639;
  v32 = (int16_t *)sub_11438B(0, 0, 639, 479, byte_17A3A2, 0);
  v33 = 0;
  sub_11438B(0, 0, 639, 479, &unk_17A3A4, 0);
  v34 = sub_12C2C6(4);
  do
  {
    v34 = sub_1171AB(v34, v33, v31, v30);
    v30 = v34;
    if ( word_19994C )
      goto LABEL_12;
    if ( (int16_t)v34 <= 0 )
    {
      if ( (v34 & 0x8000u) == 0 || (v33 = (int16_t)v34, v31 = -(int16_t)v32, (int16_t)v34 == v31) )
      {
        sub_12C2A0();
        sub_10EC96();
        sub_1077D(v36, v33, v31, v32);
        v34 = sub_12C2C6(4);
      }
      else
      {
        v30 = -v34;
        if ( (int16_t)-(int16_t)v34 >= (int16_t)v53 && (int16_t)v30 <= (int16_t)v56 )
        {
          v34 = sub_10A659((int)&word_184297);
          dword_1AD694 = v34;
          if ( v34 )
          {
            v35 = *(uint8_t *)(v34 + 6);
            LOWORD(v31) = *(uint8_t *)(v35 + v34 + 126);
            if ( *(_BYTE *)(v35 + v34 + 126) )
            {
              sub_10A21D((int)&word_184297, v34);
              sub_10F62F(281, v31);
              goto LABEL_12;
            }
          }
        }
      }
    }
    else
    {
      if ( (_WORD)v34 == (_WORD)v51 )
      {
        v34 = (int)&word_184297;
        LOBYTE(v34) = sub_10A527((int)&word_184297);
        if ( (_BYTE)v34 )
          goto LABEL_12;
      }
      if ( (_WORD)v30 == (_WORD)v50 )
      {
        LOBYTE(v34) = sub_10A540((int)&word_184297);
        if ( (_BYTE)v34 )
          goto LABEL_12;
      }
    }
  }
  while ( (_WORD)v30 != (_WORD)v32 );
  v37 = v43;
  sub_12A478(v52 + 187, 434, (int)v43);
  sub_12C2A0();
  sub_1077D(v38, 434, (int)v37, v32);
  sub_12C2C6(4);
  sub_107BA(&v48);
  sub_10FEC1((int)&unk_1AD6A0);
  sub_1113CC(dword_192ED4, 434);
  sub_1196F7();
  return v32;
}
// 10E727: variable 'v4' is possibly undefined
// 10E75E: variable 'v5' is possibly undefined
// 10E795: variable 'v6' is possibly undefined
// 10E7CC: variable 'v7' is possibly undefined
// 10E803: variable 'v8' is possibly undefined
// 10E8F9: variable 'v40' is possibly undefined
// 10EA0D: variable 'v22' is possibly undefined
// 10EB0C: variable 'v28' is possibly undefined
// 10EB3C: variable 'v29' is possibly undefined
// 10EB6C: variable 'v34' is possibly undefined
// 10EC25: variable 'v36' is possibly undefined
// 10EC58: variable 'v38' is possibly undefined
// 17A3A2: using guessed type _BYTE byte_17A3A2[2];
// 184297: using guessed type int16_t word_184297;
// 1842AD: using guessed type int dword_1842AD;
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 1AD694: using guessed type int dword_1AD694;
// 1AD6B4: using guessed type int16_t word_1AD6B4;


//----- (0010EC96) --------------------------------------------------------
void sub_10EC96()
{
  int16_t v0; // ax

  v0 = (uint16_t)sub_114177();
  if ( v0 > 0 )
    sub_10A5E3((int)&word_184297, v0);
  dword_1AD694 = sub_10A659((int)&word_184297);
  sub_10A345((int)&word_184297, dword_1AD694);
  JUMPOUT(0x10E551);
}
// 10ECDD: control flows out of bounds to 10E551
// 184297: using guessed type int16_t word_184297;
// 1AD694: using guessed type int dword_1AD694;


//----- (0010ECE2) --------------------------------------------------------
void sub_10ECE2(int a1)
{
  int v1; // edx
  int v2; // ebx
  int v3; // eax

  v1 = a1;
  v2 = a1 + 3136;
  do
  {
    v3 = v1;
    v1 += 392;
    sub_10ED00(v3);
  }
  while ( v1 != v2 );
}


//----- (0010ED00) --------------------------------------------------------
void sub_10ED00(int a1)
{
  void *v2; // edi
  uint16_t v3; // di
  void *v4; // ebx
  int16_t v5; // dx
  int v6; // ebx
  int v7; // [esp+0h] [ebp-Ch]
  int16_t v8; // [esp+4h] [ebp-8h]
  int16_t v9; // [esp+8h] [ebp-4h]

  if ( a1 && *(_WORD *)(a1 + 81) )
  {
    if ( *(_WORD *)(a1 + 81) == *(uint8_t *)(dword_192BD8 + 801) )
    {
      v2 = &unk_1AD5B4;
      v8 = 1;
    }
    else
    {
      v2 = &unk_1AD5A4;
      v8 = 0;
    }
    sub_120BB5(4, (int)v2);
    sub_102F10(*(_WORD *)a1, *(_WORD *)(a1 + 2) + 21, a1 + 9, 218);
    sub_120BB5(3, (int)v2);
    v9 = 0;
    sub_1210B7(*(_WORD *)a1 + 212, *(_WORD *)(a1 + 2) + 2, a1 + 87);
    if ( v8 == 1
      && (*(_BYTE *)(dword_192BD8 + 2229) == 1
       || *(_WORD *)(a1 + 81) == 55
       || *(_WORD *)(a1 + 81) == 57
       || *(_WORD *)(a1 + 81) == 29
       || *(_WORD *)(a1 + 81) == 22
       || *(_WORD *)(a1 + 81) == 28
       || *(_WORD *)(a1 + 81) == 23) )
    {
      v9 = 1;
    }
    v3 = 0;
    v7 = a1 + 108;
    do
    {
      v4 = &unk_1AD5A4;
      if ( v8 == 1
        && (v9 == 1
         || !stricmp(
               v7 + (v3 << 6),
               *(_UNKNOWN **)((char *)&off_17E079 + 13 * *(uint8_t *)(dword_192BD8 + 802)))) )
      {
        v4 = &unk_1AD5B4;
      }
      sub_120BB5(3, (int)v4);
      v5 = *(_WORD *)(a1 + 2 * v3 + 366);
      v6 = v7 + (v3++ << 6);
      sub_102F10(*(_WORD *)(a1 + 364), v5, v6, 208);
    }
    while ( v3 < (int)*(uint8_t *)(a1 + 107) );
  }
  JUMPOUT(0x10E6C0);
}
// 10EE6A: control flows out of bounds to 10E6C0
// 13C896: using guessed type int stricmp(_DWORD, _DWORD);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 192BD8: using guessed type int dword_192BD8;


//----- (0010EE6F) --------------------------------------------------------
int sub_10EE6F(int result)
{
  int v1; // esi
  int v2; // eax

  v1 = result;
  if ( result && *(_BYTE *)(result + 6) && *(_WORD *)(result + 81) )
  {
    sub_120BB5(4, (int)&unk_1AD5AC);
    sub_102F10(*(_WORD *)v1, *(_WORD *)(v1 + 2) + 21, v1 + 9, 218);
    sub_120BB5(3, (int)&unk_1AD5AC);
    sub_1210B7(*(_WORD *)v1 + 212, *(_WORD *)(v1 + 2) + 2, v1 + 87);
    v2 = *(uint16_t *)(v1 + 7);
    if ( v2 < *(uint8_t *)(v1 + 107) )
      sub_102F10(*(_WORD *)(v1 + 364), *(_WORD *)(v1 + 2 * v2 + 366), v1 + 108 + (v2 << 6), 208);
    return sub_1297C3(*(_WORD *)v1 - 2, *(_WORD *)(v1 + 2) + 18, 218, 82, 1, (uint8_t)byte_1AD6BB);
  }
  return result;
}
// 1AD6BB: using guessed type char byte_1AD6BB;


//----- (0010EF45) --------------------------------------------------------
int sub_10EF45(int a1, int a2)
{
  int v3; // ecx
  uint16_t i; // dx
  int v6; // [esp+0h] [ebp-8h]
  char v7; // [esp+4h] [ebp-4h]

  v7 = 1;
  v3 = 0;
  v6 = a1 + 3136;
  do
  {
    *(_BYTE *)(a1 + 6) = 0;
    if ( v7 && *(_WORD *)(a1 + 81) )
    {
      for ( i = 0; i < (int)*(uint8_t *)(a1 + 107); ++i )
      {
        if ( a2 == *(_WORD *)(a1 + 2 * i + 374) )
        {
          v7 = 0;
          *(_BYTE *)(a1 + 6) = 1;
          v3 = a1;
          *(_WORD *)(a1 + 7) = i;
        }
      }
    }
    a1 += 392;
  }
  while ( a1 != v6 );
  return v3;
}


//----- (0010EFC3) --------------------------------------------------------
void sub_10EFC3(int16_t *a1)
{
  uint16_t v1; // bx
  int v2; // edx
  int16_t v3; // dx
  int v4; // edx
  int v5; // ecx
  int16_t v6; // di

  v1 = 0;
  while ( 1 )
  {
    a1[2] = (uint8_t)byte_18423F[v1];
    if ( byte_1AD6BA )
      v2 = dword_1841D5[v1];
    else
      v2 = dword_1841B5[v1];
    *(_DWORD *)a1 = v2;
    *((_BYTE *)a1 + 9) = 0;
    *(int16_t *)((char *)a1 + 81) = 0;
    *((_BYTE *)a1 + 6) = 0;
    v3 = *a1;
    *(int16_t *)((char *)a1 + 7) = 0;
    a1[182] = v3 + 10;
    *((_BYTE *)a1 + 107) = 0;
    a1[195] = word_1AD6B4 + word_18420F[v1];
    v4 = 0;
    do
    {
      v5 = (int16_t)v4;
      v6 = word_184205[(int16_t)v4++] + 21;
      a1[v5 + 183] = a1[1] + v6;
      LOBYTE(a1[32 * v5 + 54]) = 0;
    }
    while ( (int16_t)v4 < 4 );
    ++v1;
    a1 += 196;
    if ( v1 >= 8u )
      JUMPOUT(0x10E6C1);
  }
}
// 10F070: control flows out of bounds to 10E6C1
// 1841B5: using guessed type int dword_1841B5[8];
// 1841D5: using guessed type int dword_1841D5[8];
// 184205: using guessed type int16_t word_184205[5];
// 18420F: using guessed type int16_t word_18420F[8];
// 1AD6B4: using guessed type int16_t word_1AD6B4;
// 1AD6BA: using guessed type char byte_1AD6BA;


//----- (0010F089) --------------------------------------------------------
void sub_10F089()
{
  int v0; // eax
  uint16_t v1; // bx
  char *v2; // eax
  int v3; // edx
  int v4; // esi
  int16_t v5; // cx
  int16_t v6; // bx
  int16_t v7; // cx
  int16_t v8; // dx
  int16_t v9; // ax
  int16_t v10; // bx
  int v11; // ebx
  int16_t v12; // dx
  int16_t v13; // ax
  int16_t v14; // ax
  int16_t v15; // ax
  int v16; // eax
  char *v17; // esi
  char *v18; // edi
  char *v19; // esi
  int v20; // [esp+0h] [ebp-Eh]
  int v21; // [esp+4h] [ebp-Ah]
  char v22[80]; // [esp+8h] [ebp-6h] BYREF
  int v23; // [esp+58h] [ebp+4Ah] BYREF
  int16_t v24; // [esp+5Ch] [ebp+4Eh]
  char *v25; // [esp+6Ch] [ebp+5Eh]
  char *v26; // [esp+70h] [ebp+62h]
  int v27; // [esp+74h] [ebp+66h]
  char *v28; // [esp+78h] [ebp+6Ah]
  int v29; // [esp+7Ch] [ebp+6Eh]
  int v30; // [esp+80h] [ebp+72h]
  int v31; // [esp+84h] [ebp+76h]
  int v32; // [esp+88h] [ebp+7Ah]
  uint16_t v33; // [esp+8Ch] [ebp+7Eh]

  sub_249F9(aBilltextLbx_3, 62, v22, 80);
  v28 = (char *)(v21 + 108);
  v26 = (char *)(v21 + 9);
  v32 = 0;
  v29 = 0;
  v27 = v21 + 87;
  while ( 1 )
  {
    v0 = *(uint16_t *)(v21 + 4);
    for ( LOWORD(v0) = (uint8_t)byte_17CF18[v0]; ; LOWORD(v0) = *(int16_t *)((char *)&word_17D90C + v0) )
    {
      v31 = v0;
      if ( !(_WORD)v0
        || *(_BYTE *)((uint16_t)v31 + dword_192BD8 + 196) == 2
        && (uint16_t)v31 != *(uint8_t *)(dword_192BD8 + 801) )
      {
        break;
      }
      v0 = 23 * (uint16_t)v31;
    }
    if ( (_WORD)v31 )
    {
      v33 = 0;
      if ( (uint16_t)v31 >= 0x4Bu )
      {
        v11 = (int16_t)v31;
        v12 = word_19999C;
        v13 = sub_1032FB((int16_t)v31);
        strcpy(v28, sub_10F7A1(v13, v12));
        *(_WORD *)(v21 + 382) = sub_1032FB(v11);
        v14 = sub_11438B(
                *(_WORD *)v21,
                word_1841F5[0] + *(_WORD *)(v21 + 2) + 21,
                *(_WORD *)v21 + 218,
                word_1841FD[0] + *(_WORD *)(v21 + 2) + 21,
                &unk_17A3A4,
                0);
        *(_BYTE *)(v21 + 107) = 1;
        *(_WORD *)(v21 + 374) = v14;
      }
      else
      {
        v30 = 0;
        v25 = v28;
        while ( (uint16_t)v30 < 4u && v33 < 4u )
        {
          v1 = *(int16_t *)((char *)word_17D90E + 23 * (uint16_t)v31 + 2 * (uint16_t)v30);
          if ( *(_BYTE *)(dword_192BD8 + v1 + 279) == 1 )
          {
            v2 = sub_10F7A1(v1, word_19999C);
            v3 = v33;
            strcpy(&v25[64 * v33], v2);
            v4 = 2 * v3 + v21;
            *(_WORD *)(v4 + 382) = v1;
            v5 = word_1841FD[v3] + *(_WORD *)(v21 + 2) + 21;
            LOWORD(v3) = word_1841F5[v3] + *(_WORD *)(v21 + 2) + 21;
            LOWORD(v2) = *(_WORD *)v21;
            v6 = *(_WORD *)v21 + 218;
            ++v33;
            *(_WORD *)(v4 + 374) = sub_11438B((int16_t)v2, v3, v6, v5, &unk_17A3A4, 0);
          }
          ++v30;
        }
        if ( !v33 )
        {
          strcpy(v28, v22);
          *(_WORD *)(v21 + 382) = 0;
          v7 = word_1841FD[0] + *(_WORD *)(v21 + 2) + 21;
          v8 = word_1841F5[0] + *(_WORD *)(v21 + 2) + 21;
          v9 = *(_WORD *)v21;
          v10 = *(_WORD *)v21 + 218;
          ++v33;
          *(_WORD *)(v21 + 374) = sub_11438B(v9, v8, v10, v7, &unk_17A3A4, 0);
        }
        *(_BYTE *)(v21 + 107) = v33;
      }
      v15 = v31;
      *(_WORD *)(v21 + 81) = v31;
      v16 = sub_E1E96(dword_192BD8, v15) - v20;
      *(_DWORD *)(v21 + 83) = v16;
      if ( v16 < 0 )
        *(_DWORD *)(v21 + 83) = 0;
      switch ( byte_199CAE )
      {
        case 0:
        case 2:
        case 3:
          v17 = aIRp;
          break;
        case 1:
          v17 = aIFp;
          break;
        case 4:
          v17 = aIPr;
          break;
        default:
          v17 = aIRp;
          break;
      }
      v23 = *(_DWORD *)v17;
      v24 = *((_WORD *)v17 + 2);
      sprintf(v27, (char *)&v23, *(_DWORD *)(v21 + 83));
      v18 = v26;
      v19 = sub_10F772(v31);
      ++v32;
      strcpy(v18, v19);
    }
    ++v29;
    v28 += 392;
    v26 += 392;
    v27 += 392;
    v21 += 392;
    if ( (uint16_t)v29 >= 8u )
      JUMPOUT(0x10EC8A);
  }
}
// 10F404: control flows out of bounds to 10EC8A
// 10F0B6: variable 'v21' is possibly undefined
// 10F359: variable 'v20' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17D90C: using guessed type int16_t word_17D90C;
// 17D90E: using guessed type int16_t word_17D90E[];
// 1841F5: using guessed type int16_t word_1841F5[4];
// 1841FD: using guessed type int16_t word_1841FD[4];
// 192BD8: using guessed type int dword_192BD8;
// 19999C: using guessed type int16_t word_19999C;
// 199CAE: using guessed type char byte_199CAE;


//----- (0010F409) --------------------------------------------------------
void sub_10F409(int a1, _WORD **a2)
{
  int v2; // esi
  int16_t v4; // dx
  int v5; // [esp+0h] [ebp-Ch]
  uint16_t v6; // [esp+8h] [ebp-4h]

  v2 = a1;
  v6 = 0;
  v5 = a1 + 75;
  while ( 1 )
  {
    if ( *(_WORD *)(v2 + 81) )
    {
      v4 = word_1AD6B6;
      *(_WORD *)(v2 + 75) = 0;
      *(_WORD *)(v2 + 73) = sub_11523B(
                              word_18421F[2 * v6] + word_1AD6B4,
                              word_184221[2 * v6] + v4,
                              (int)&unk_17A3A4,
                              *a2,
                              v5,
                              &unk_17A3A4,
                              40);
      *(_DWORD *)(v2 + 77) = *a2;
    }
    ++v6;
    v5 += 392;
    ++a2;
    v2 += 392;
    if ( v6 >= 8u )
      JUMPOUT(0x10EFA3);
  }
}
// 10F496: control flows out of bounds to 10EFA3
// 18421F: using guessed type int16_t word_18421F[];
// 184221: using guessed type int16_t word_184221[15];
// 1AD6B4: using guessed type int16_t word_1AD6B4;
// 1AD6B6: using guessed type int16_t word_1AD6B6;


//----- (0010F49B) --------------------------------------------------------
void sub_10F49B(int a1, unsigned int a2)
{
  int v3; // edx
  uint16_t v4; // cx
  char v5; // bl
  uint16_t v6; // ax
  uint16_t i; // si
  char v8; // al
  int v9; // eax
  int v10; // [esp+0h] [ebp-20h]
  char *v11; // [esp+4h] [ebp-1Ch]
  uint16_t v12; // [esp+10h] [ebp-10h]
  char v13; // [esp+14h] [ebp-Ch]
  uint8_t v14; // [esp+18h] [ebp-8h]
  char v15; // [esp+1Ch] [ebp-4h]

  v3 = *(_DWORD *)(v10 + 22);
  v4 = (uint8_t)byte_17CF18[a2];
  v13 = 0;
  v11 = (char *)(v3 + 7);
  while ( 1 )
  {
    if ( !v4 )
    {
      *(_BYTE *)(v10 + 21) = v13;
      JUMPOUT(0x10EFA3);
    }
    v5 = *(_BYTE *)(v4 + dword_192BD8 + 196);
    *(_BYTE *)(v3 + 71) = v4;
    strcpy(v11, sub_10F772((uint8_t)v4));
    if ( *(uint8_t *)(dword_192BD8 + 801) == v4 )
    {
      v5 = 4;
    }
    else if ( v4 >= 0x4Bu && *(_BYTE *)(v4 + dword_192BD8 + 465) > 0x14u )
    {
      v5 = 3;
    }
    if ( v5 != 3 )
    {
      if ( !v5 )
      {
        v6 = 0;
        while ( *(_BYTE *)(dword_192BD8 + *(int16_t *)((char *)word_17D90E + 23 * v4 + 2 * v6) + 279) != 3 )
        {
          if ( ++v6 >= 4u )
            goto LABEL_14;
        }
        v5 = 1;
      }
LABEL_14:
      if ( v5 )
      {
        v12 = 0;
        for ( i = 0; i < 4u; ++i )
        {
          v14 = *((_BYTE *)word_17D90E + 23 * v4 + 2 * i);
          v8 = *(_BYTE *)(v14 + dword_192BD8 + 279);
          v15 = v8;
          if ( v8 )
          {
            if ( v5 == 4 || v8 == 1 && v5 == 2 )
              v15 = v5;
            v9 = v12;
            *(_BYTE *)(v3 + v12++ + 126) = v14;
            *(_BYTE *)(v3 + v9 + 142) = v15;
          }
        }
        if ( v12 )
        {
          v3 += 158;
          v11 += 158;
          *(_BYTE *)(v3 - 86) = v5;
          ++v13;
          *(_BYTE *)(v3 - 85) = v12;
        }
      }
    }
    v4 = *(int16_t *)((char *)&word_17D90C + 23 * v4);
  }
}
// 10F616: control flows out of bounds to 10EFA3
// 10F4AC: variable 'v10' is possibly undefined
// 17D90C: using guessed type int16_t word_17D90C;
// 17D90E: using guessed type int16_t word_17D90E[];
// 192BD8: using guessed type int dword_192BD8;


//----- (0010F62F) --------------------------------------------------------
void sub_10F62F(int a1, int a2)
{
  _DWORD *v2; // ebx
  int v3; // esi
  char *v4; // edi
  char *v5; // esi
  char *v6; // edi
  _BYTE v7[1419]; // [esp+0h] [ebp-608h] BYREF
  char v8; // [esp+58Bh] [ebp-7Dh] BYREF
  char v9[80]; // [esp+58Ch] [ebp-7Ch] BYREF
  char v10[20]; // [esp+5DCh] [ebp-2Ch] BYREF
  char v11[20]; // [esp+5F0h] [ebp-18h] BYREF
  _DWORD *v12; // [esp+604h] [ebp-4h]

  sub_119281();
  sub_1112EC(dword_192ED4, 1404);
  sub_1172D4();
  v2 = sub_110D3C(dword_192ED4, 1404);
  sub_A6547(v11);
  v12 = sub_126BDD((int)v11, 0, (int)v2, a2, 1u, 1403);
  v3 = sub_E1E96(dword_197F98 + 3753 * word_19999C, *(int16_t *)((char *)&word_17E07F + 13 * a2));
  sub_249F9(aBilltextLbx_3, 61, v9, 80);
  itoa(v3, v10, 10, 80);
  v4 = &v8;
  do
    ++v4;
  while ( *v4 );
  strcpy(v4, v10);
  switch ( byte_199CAE )
  {
    case 0:
    case 2:
    case 3:
      v5 = aRp_1;
      break;
    case 1:
      v5 = aFp_0;
      break;
    case 4:
      v5 = aPr_0;
      break;
    default:
      v5 = aRp_1;
      break;
  }
  v6 = &v8;
  do
    ++v6;
  while ( *v6 );
  strcpy(v6, v5);
  sprintf(v7, aF3, (char *)v12 + 103, v9);
  sub_A5EB2((int)v12, (int)v7);
  sub_1113CC(dword_192ED4, (int)v7);
  sub_1192A9();
  sub_119441();
  sub_1172FC();
  JUMPOUT(0x10EFA3);
}
// 10F76D: control flows out of bounds to 10EFA3
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 17E07F: using guessed type int16_t word_17E07F;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199CAE: using guessed type char byte_199CAE;


//----- (0010F772) --------------------------------------------------------
char *sub_10F772( int a1)
{
  if ( a1 < 75 )
    return *(char **)((char *)&off_17D904 + 23 * a1);
  strcpy(byte_17D640, (char *)dword_199170);
  return byte_17D640;
}
// 17D904: using guessed type _UNKNOWN *off_17D904;
// 199170: using guessed type int dword_199170;


//----- (0010F7A1) --------------------------------------------------------
char *sub_10F7A1( int a1, int a2)
{
  int16_t v3; // dx
  char *v4; // edi
  char *v5; // edi
  unsigned int v6; // kr04_4

  if ( a1 < 204 )
    return *(char **)((char *)&off_17E079 + 13 * a1);
  v3 = *(uint8_t *)(a1 + dword_197F98 + 3753 * a2 + 336);
  strcpy(byte_17D640, *(char **)((char *)&off_17E079 + 13 * a1));
  v4 = &byte_17D640[-1];
  do
    ++v4;
  while ( *v4 );
  strcpy(v4, asc_17A3EA);
  if ( v3 > 20 || v3 <= 0 )
  {
    v6 = strlen(byte_17D640) + 1;
    itoa(v3, &byte_17D640[v6 - 1], 10, &byte_17D640[v6 - 1]);
  }
  else
  {
    v5 = &byte_17D640[-1];
    do
      ++v5;
    while ( *v5 );
    strcpy(v5, off_17D5E0[v3]);
  }
  return byte_17D640;
}
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 17D5E0: using guessed type char *off_17D5E0[21];
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 197F98: using guessed type int dword_197F98;


//----- (0010F884) --------------------------------------------------------
int sub_10F884( int a1)
{
  int result; // eax
  int v3; // edx
  char v4; // bl

  result = 0;
  do
  {
    v3 = (int16_t)result;
    v4 = *(_BYTE *)((int16_t)result++ + dword_197F98 + 3753 * a1 + 540);
    byte_1AD59C[v3] = v4;
  }
  while ( (int16_t)result < 8 );
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0010F8B7) --------------------------------------------------------
char sub_10F8B7( int a1)
{
  int v2; // edx
  int v3; // ebx
  char result; // al

  v2 = 0;
  do
  {
    v3 = (int16_t)v2 + 3753 * a1 + dword_197F98;
    result = byte_1AD59C[(int16_t)v2++];
    *(_BYTE *)(v3 + 540) = result;
  }
  while ( (int16_t)v2 < 8 );
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0010F8ED) --------------------------------------------------------
int sub_10F8ED( int a1)
{
  int v2; // edx
  int result; // eax
  int v4; // ecx

  v2 = 0;
  do
  {
    result = 3753 * a1 + dword_197F98;
    v4 = (int16_t)v2++;
    ++*(_BYTE *)(v4 + result + 540);
  }
  while ( (int16_t)v2 < 8 );
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0010F919) --------------------------------------------------------
int sub_10F919(int result, int a2)
{
  if ( (int16_t)result >= 75 )
  {
    result = (int16_t)result;
    ++*(_BYTE *)(3753 * a2 + dword_197F98 + (int16_t)result + 465);
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0010F94B) --------------------------------------------------------
int sub_10F94B(int result, int a2, int a3, int a4)
{
  int v4; // esi
  int v6; // ebx
  int *v7; // edx
  int *v8; // eax
  int16_t v9; // ax
  int v10; // [esp+0h] [ebp-24h]
  uint16_t v11; // [esp+Ch] [ebp-18h]
  int v13; // [esp+14h] [ebp-10h]
  uint16_t v14; // [esp+1Ch] [ebp-8h]
  uint16_t v15; // [esp+20h] [ebp-4h]

  v4 = result;
  if ( a4 > 0 )
  {
    v14 = a4 - 1;
    v11 = a3 + 1;
    do
    {
      v6 = a3;
      v13 = 0;
      v15 = v11;
      while ( (uint16_t)v6 < v14 )
      {
        v7 = (int *)(a2 + 4 * (uint16_t)v6);
        v8 = (int *)(a2 + 4 * v15);
        if ( *v7 < *v8 )
        {
          v10 = *v7;
          *v7 = *v8;
          *v8 = v10;
          v9 = *(_WORD *)(v4 + 2 * (uint16_t)v6);
          *(_WORD *)(v4 + 2 * (uint16_t)v6) = *(_WORD *)(v4 + 2 * v15);
          v13 = v6;
          *(_WORD *)(v4 + 2 * v15) = v9;
        }
        ++v15;
        ++v6;
      }
      result = v13;
      v14 = v13;
    }
    while ( (_WORD)v13 );
  }
  return result;
}


//----- (0010F9E0) --------------------------------------------------------
void sub_10F9E0( int a1, int a2)
{
  int v3; // edx

  while ( 1 )
  {
    v3 = a2 + 2 * a1;
    if ( (*(_BYTE *)(v3 + 1) & 0x40) == 0 )
    {
      if ( *(_WORD *)v3 )
        break;
    }
    if ( a1 <= 0 )
      break;
    --a1;
  }
  JUMPOUT(0x10F939);
}
// 10F9F4: control flows out of bounds to 10F939


//----- (0010FA35) --------------------------------------------------------
int sub_10FA35(int result, int a2, unsigned int a3)
{
  int16_t v3; // cx
  int64_t v4[32]; // [esp+0h] [ebp-100h] BYREF

  v3 = result;
  if ( a3 <= 0xFAu )
  {
    sub_120E24(10);
    sub_EEC98(v4[0]);
    sub_1212B3(v3, a2, (int)asc_17A3EC);
    return sub_103BC4(v3 + 13, a2, 320, (int)v4, 0);
  }
  return result;
}


//----- (0010FA95) --------------------------------------------------------
int sub_10FA95(int a1, int a2)
{
  return sub_108EC3(a1, a2, 4, 10);
}


//----- (0010FAAC) --------------------------------------------------------
void sub_10FAAC()
{
  int16_t v0; // ax

  off_184350[0] = &aNrqqqrrsnutstt[8];
  v0 = (uint16_t)sub_114177();
  if ( v0 >= word_1AD1FC && v0 <= word_1AD200 )
    sub_10A5E3((int)&unk_184324, v0);
  dword_1AD6BC = sub_10A659((int)&unk_184324);
  sub_10A3AD((int)&unk_184324, dword_1AD6BC);
  off_184350[0] = aNrqqqrrsnutstt;
}
// 184350: using guessed type char *off_184350[5];
// 1AD1FC: using guessed type int16_t word_1AD1FC;
// 1AD200: using guessed type int16_t word_1AD200;
// 1AD6BC: using guessed type int dword_1AD6BC;


//----- (0010FB02) --------------------------------------------------------
int16_t sub_10FB02()
{
  int v0; // eax
  int16_t *v1; // edi
  int v2; // esi
  int16_t v3; // ax
  unsigned int v4; // ecx
  int16_t v5; // dx
  int v6; // edx
  int v7; // eax
  void *v8; // eax
  int v9; // eax
  char v11; // [esp+0h] [ebp-3DD8h] BYREF
  int v12; // [esp+3DB8h] [ebp-20h] BYREF
  _WORD *v13; // [esp+3DBCh] [ebp-1Ch]
  _WORD *v14; // [esp+3DC0h] [ebp-18h]
  _DWORD *v15; // [esp+3DC4h] [ebp-14h]
  int v16; // [esp+3DC8h] [ebp-10h]
  char *v17; // [esp+3DCCh] [ebp-Ch]
  char *v18; // [esp+3DD0h] [ebp-8h]
  char *v19; // [esp+3DD4h] [ebp-4h]

  word_199A08 = 0;
  LOWORD(v0) = sub_EEC02(word_19999C);
  v16 = v0;
  if ( (int16_t)v0 > 0 )
  {
    if ( word_199A10 == 39 )
    {
      byte_1AD6C0 = 0;
    }
    else
    {
      sub_C5BB9();
      sub_1205E6(0, 0, 255);
      sub_102CDF();
    }
    sub_119441();
    sub_1196F7();
    sub_107AF(&v12);
    sub_11C2F0();
    sub_124C08();
    v15 = sub_126AFD((int)aTurnsumLbx, 0, dword_192ED4);
    v14 = sub_126B42((int)aTurnsumLbx, 1, dword_192ED4);
    v13 = sub_126B42((int)aTurnsumLbx, 2, dword_192ED4);
    v1 = (int16_t *)sub_126B42((int)aTurnsumLbx, 3, dword_192ED4);
LABEL_6:
    word_19994C = 0;
    sub_11C2F0();
    sub_1191CA((int)sub_10FAAC, 2);
    v19 = sub_1151B0(441, 95, (int)&unk_17A3FA, v14, &unk_17A3FA, 0);
    v17 = sub_1151B0(441, 353, (int)&unk_17A3FA, v13, &unk_17A3FA, 0);
    dword_18433A = (int)&v11;
    sub_108EC3((int)&unk_184324, (int16_t)v16, 4, 10);
    dword_1AD6BC = sub_10A5A3((int)&unk_184324, byte_1AD6C0);
    sub_84E9D();
    sub_1039D7();
LABEL_7:
    v2 = (int16_t)v17;
    sub_119400((int16_t)v17);
    word_1AD1FC = sub_113E65();
    sub_10A188((int)&unk_184324);
    word_1AD200 = v3;
    v18 = sub_1151B0(242, 374, (int)&unk_17A3FA, v1, asc_17A3FB, 0);
    sub_11438B(84, 51, 464, 393, asc_17A3FB, 0);
    v4 = sub_11438B(0, 0, 639, 479, asc_17A3FB, 0);
    sub_12A478(84, 51, (int)v15);
    v5 = (int16_t)v19;
    sub_10A4A7((int)&unk_184324);
    sub_10A689((int)&unk_184324, v5, v2);
    sub_124DEC();
    v6 = 255;
    v7 = sub_131922(0, 255);
    sub_1077D(v7, 255, v2, v1);
    sub_C5C44();
    do
    {
      v8 = (void *)sub_1171AB((int)v8, v6, v2, v4);
      v6 = (int)v8;
      if ( word_19994C )
        goto LABEL_6;
      if ( (int16_t)v8 < word_1AD1FC || (int16_t)v8 > word_1AD200 )
      {
        if ( (int16_t)v8 <= 0 || (int16_t)v8 >= (int16_t)v4 || (_WORD)v8 == (_WORD)v18 )
        {
          if ( !(_WORD)v8 )
          {
            sub_12C2A0();
            sub_10FAAC();
            sub_1077D(v9, v6, v2, v1);
            v8 = (void *)sub_12C2C6(2);
          }
        }
        else
        {
          if ( (_WORD)v8 == (_WORD)v17 )
          {
            v8 = &unk_184324;
            LOBYTE(v8) = sub_10A527((int)&unk_184324);
            if ( (_BYTE)v8 )
              goto LABEL_7;
          }
          if ( (_WORD)v6 == (_WORD)v19 )
          {
            LOBYTE(v8) = sub_10A540((int)&unk_184324);
            if ( (_BYTE)v8 )
              goto LABEL_7;
          }
        }
      }
      else
      {
        LOBYTE(v8) = sub_EF6F0(&byte_1AA414[18 * *(uint8_t *)(dword_1AD6BC + 71)]);
        if ( (_BYTE)v8 )
        {
          word_199A08 = 1;
          word_199A10 = 40;
          LOBYTE(v8) = *(_BYTE *)(dword_1AD6BC + 71);
          v6 = v4;
          byte_1AD6C0 = (char)v8;
        }
      }
    }
    while ( (int16_t)v6 < (int16_t)v4 && (_WORD)v6 != (_WORD)v18 );
    sub_107BA(&v12);
    LOWORD(v0) = sub_11C2F0();
  }
  if ( !word_199A08 )
    word_199A08 = 39;
  return v0;
}
// 10FB20: variable 'v0' is possibly undefined
// 10FCAB: variable 'v3' is possibly undefined
// 10FD41: variable 'v8' is possibly undefined
// 10FDFC: variable 'v9' is possibly undefined
// 18433A: using guessed type int dword_18433A;
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 1AA414: using guessed type _BYTE byte_1AA414[1800];
// 1AD1FC: using guessed type int16_t word_1AD1FC;
// 1AD200: using guessed type int16_t word_1AD200;
// 1AD6BC: using guessed type int dword_1AD6BC;
// 1AD6C0: using guessed type char byte_1AD6C0;


//----- (0010FE41) --------------------------------------------------------
int16_t sub_10FE41(int a1)
{
  *(_WORD *)a1 = word_1B3E0E;
  *(_WORD *)(a1 + 2) = HIWORD(dword_1B3E10);
  *(_WORD *)(a1 + 4) = HIWORD(dword_18448E);
  *(_WORD *)(a1 + 6) = word_1844A6;
  *(_WORD *)(a1 + 8) = word_1844CA;
  *(_WORD *)(a1 + 10) = HIWORD(dword_1844CE);
  *(_WORD *)(a1 + 12) = word_18447E;
  *(_DWORD *)(a1 + 14) = off_184480;
  off_184480 = (_UNKNOWN *)((char *)off_184480 + 55 * word_1B3E0E);
  word_18447E -= word_1B3E0E;
  return sub_11C2F0();
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 18448E: using guessed type int dword_18448E;
// 1844A6: using guessed type int16_t word_1844A6;
// 1844CA: using guessed type int16_t word_1844CA;
// 1844CE: using guessed type int dword_1844CE;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1B3E10: using guessed type int dword_1B3E10;


//----- (0010FEC1) --------------------------------------------------------
int16_t sub_10FEC1(int a1)
{
  void *v1; // edx
  int16_t result; // ax

  word_1B3E0E = *(_WORD *)a1;
  HIWORD(dword_1B3E10) = *(_WORD *)(a1 + 2);
  HIWORD(dword_18448E) = *(_WORD *)(a1 + 4);
  word_1844A6 = *(_WORD *)(a1 + 6);
  word_1844CA = *(_WORD *)(a1 + 8);
  HIWORD(dword_1844CE) = *(_WORD *)(a1 + 10);
  v1 = *(void **)(a1 + 14);
  result = *(_WORD *)(a1 + 12);
  off_184480 = v1;
  word_18447E = result;
  return result;
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 18448E: using guessed type int dword_18448E;
// 1844A6: using guessed type int16_t word_1844A6;
// 1844CA: using guessed type int16_t word_1844CA;
// 1844CE: using guessed type int dword_1844CE;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1B3E10: using guessed type int dword_1B3E10;


//----- (001101F0) --------------------------------------------------------
int sub_1101F0(int a1, int a2, int a3, int a4)
{
  int result; // eax
  _WORD v5[384]; // [esp+0h] [ebp-41Ch] BYREF
  _BYTE v6[4]; // [esp+300h] [ebp-11Ch] BYREF
  int16_t v7; // [esp+304h] [ebp-118h]
  int16_t v8; // [esp+306h] [ebp-116h]
  int16_t v9; // [esp+308h] [ebp-114h]
  int16_t v10; // [esp+30Ah] [ebp-112h]
  int16_t v11; // [esp+30Ch] [ebp-110h]
  int16_t v12; // [esp+30Eh] [ebp-10Eh]
  _BYTE v13[50]; // [esp+310h] [ebp-10Ch] BYREF
  int16_t v14; // [esp+342h] [ebp-DAh]
  int16_t v15; // [esp+344h] [ebp-D8h]
  int16_t v16; // [esp+346h] [ebp-D6h]
  int16_t v17; // [esp+348h] [ebp-D4h]
  _BYTE v18[54]; // [esp+34Ah] [ebp-D2h] BYREF
  char v19[32]; // [esp+380h] [ebp-9Ch] BYREF
  _BYTE v20[28]; // [esp+3A0h] [ebp-7Ch] BYREF
  int v21; // [esp+3BCh] [ebp-60h] BYREF
  int v22; // [esp+3C0h] [ebp-5Ch]
  int v23; // [esp+3C8h] [ebp-54h]
  _BYTE v24[16]; // [esp+3D8h] [ebp-44h] BYREF
  int v25; // [esp+3E8h] [ebp-34h]
  int j; // [esp+3ECh] [ebp-30h]
  unsigned int i; // [esp+3F4h] [ebp-28h]
  int v28; // [esp+3FCh] [ebp-20h]
  int v29; // [esp+404h] [ebp-18h]
  uint8_t v30; // [esp+40Ch] [ebp-10h]
  _BYTE v31[8]; // [esp+410h] [ebp-Ch] BYREF
  _BYTE v32[4]; // [esp+418h] [ebp-4h] BYREF

  result = IsMemPoolReady_110B5C();
  if ( (int16_t)result != 1 )
  {
    byte_1B922A = 1;
    ((int(*)())(void*)dword_1B9208)();
    sub_123A30();
    v29 = 0;
    strcpy(v19, "SCR00.PCX");
    while ( FindMoxSetPath_1114D7(v19, v5) )
    {
      if ( ++v29 >= 10 )
      {
        itoa(v29, v5, 10, a4);
      }
      else
      {
        v5[0] = word_17A40A;
        itoa(v29, v24, 10, a4);
        strcat(v5, v24);
      }
      strcpy(v19, "SCR");
      strcat(v19, v5);
      strcat(v19, aPcx);
    }
    v25 = fopen(v19, aWb_4);
    memset(v20, 0, sizeof(v20));
    memset(&v21, 0, 28);
    v21 = 20229;
    LOBYTE(v22) = 1;
    int386(16, &v21, v20);
    v30 = v20[12];
    v28 = 5 * (dword_1BBA64 >> 16);
    dword_1BB8A8(v28);
    v6[0] = 10;
    v6[1] = 5;
    v6[2] = 1;
    v6[3] = 8;
    v7 = 0;
    v8 = 0;
    v9 = 639;
    v10 = 479;
    v11 = 640;
    v12 = 480;
    memset(v13, 0, 48);
    v13[48] = 0;
    v13[49] = 1;
    v14 = 640;
    v15 = 0;
    v16 = 0;
    v17 = 0;
    memset(v18, 0, sizeof(v18));
    fwrite(v6, 128, 1, v25);
    for ( i = 0; i < (unsigned int)sub_10000; i += v31[0] & 0x3F )
    {
      v31[0] = 1;
      v32[0] = *(_BYTE *)(i + dword_1BB910[0]);
      while ( v32[0] == *(_BYTE *)(v31[0] + i + dword_1BB910[0])
           && i + v31[0] < (unsigned int)sub_10000
           && v31[0] < 0x3Fu
           && (i + v31[0]) % 0x280 )
        ++v31[0];
      if ( v31[0] > 1u || (v32[0] & 0xC0) == 0xC0 )
      {
        v31[0] |= 0xC0u;
        fwrite(v31, 1, 1, v25);
        fwrite(v32, 1, 1, v25);
      }
      else
      {
        fwrite(v32, 1, 1, v25);
        v31[0] |= 0xC0u;
      }
    }
    dword_1BB8A8(++v28);
    for ( i = 0; i < (unsigned int)sub_10000; i += v31[0] & 0x3F )
    {
      v31[0] = 1;
      v32[0] = *(_BYTE *)(i + dword_1BB910[0]);
      while ( v32[0] == *(_BYTE *)(v31[0] + i + dword_1BB910[0])
           && i + v31[0] < (unsigned int)sub_10000
           && v31[0] < 0x3Fu
           && (i + 256 + v31[0]) % 0x280 )
        ++v31[0];
      if ( v31[0] > 1u || (v32[0] & 0xC0) == 0xC0 )
      {
        v31[0] |= 0xC0u;
        fwrite(v31, 1, 1, v25);
        fwrite(v32, 1, 1, v25);
      }
      else
      {
        fwrite(v32, 1, 1, v25);
        v31[0] |= 0xC0u;
      }
    }
    dword_1BB8A8(++v28);
    for ( i = 0; i < (unsigned int)sub_10000; i += v31[0] & 0x3F )
    {
      v31[0] = 1;
      v32[0] = *(_BYTE *)(i + dword_1BB910[0]);
      while ( v32[0] == *(_BYTE *)(v31[0] + i + dword_1BB910[0])
           && i + v31[0] < (unsigned int)sub_10000
           && v31[0] < 0x3Fu
           && (i + 512 + v31[0]) % 0x280 )
        ++v31[0];
      if ( v31[0] > 1u || (v32[0] & 0xC0) == 0xC0 )
      {
        v31[0] |= 0xC0u;
        fwrite(v31, 1, 1, v25);
        fwrite(v32, 1, 1, v25);
      }
      else
      {
        fwrite(v32, 1, 1, v25);
        v31[0] |= 0xC0u;
      }
    }
    dword_1BB8A8(++v28);
    for ( i = 0; i < (unsigned int)sub_10000; i += v31[0] & 0x3F )
    {
      v31[0] = 1;
      v32[0] = *(_BYTE *)(i + dword_1BB910[0]);
      while ( v32[0] == *(_BYTE *)(v31[0] + i + dword_1BB910[0])
           && i + v31[0] < (unsigned int)sub_10000
           && v31[0] < 0x3Fu
           && (i + 768 + v31[0]) % 0x280 )
        ++v31[0];
      if ( v31[0] > 1u || (v32[0] & 0xC0) == 0xC0 )
      {
        v31[0] |= 0xC0u;
        fwrite(v31, 1, 1, v25);
        fwrite(v32, 1, 1, v25);
      }
      else
      {
        fwrite(v32, 1, 1, v25);
        v31[0] |= 0xC0u;
      }
    }
    dword_1BB8A8(++v28);
    for ( i = 0; i < 0xB000; i += v31[0] & 0x3F )
    {
      v31[0] = 1;
      v32[0] = *(_BYTE *)(i + dword_1BB910[0]);
      while ( v32[0] == *(_BYTE *)(v31[0] + i + dword_1BB910[0])
           && i + v31[0] < 0xB000
           && v31[0] < 0x3Fu
           && (i + 1024 + v31[0]) % 0x280 )
        ++v31[0];
      if ( v31[0] > 1u || (v32[0] & 0xC0) == 0xC0 )
      {
        v31[0] |= 0xC0u;
        fwrite(v31, 1, 1, v25);
        fwrite(v32, 1, 1, v25);
      }
      else
      {
        fwrite(v32, 1, 1, v25);
        v31[0] |= 0xC0u;
      }
    }
    for ( j = 0; j < 256; ++j )
    {
      *((_BYTE *)v5 + 3 * j) = 4 * byte_1BB359[4 * j];
      *((_BYTE *)v5 + 3 * j + 1) = 4 * byte_1BB35A[4 * j];
      *((_BYTE *)&v5[1] + 3 * j) = 4 * byte_1BB35B[4 * j];
    }
    v31[0] = 12;
    fwrite(v31, 1, 1, v25);
    fwrite(v5, 768, 1, v25);
    fclose(v25);
    sub_123A64();
    sub_110AFC();
    memset(v20, 0, sizeof(v20));
    memset(&v21, 0, 28);
    v21 = 20229;
    v22 = 0;
    v23 = v30;
    result = int386(16, &v21, v20);
    byte_1B922A = 0;
  }
  return result;
}
// 10000: using guessed type void __noreturn sub_10000();
// 12685D: using guessed type int fopen(_DWORD, _DWORD);
// 12697A: using guessed type int fclose(_DWORD);
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 129CAB: using guessed type int fwrite(_DWORD, _DWORD, _DWORD, _DWORD);
// 13F220: using guessed type int strcat(_DWORD, _DWORD);
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);
// 17A40A: using guessed type int16_t word_17A40A;
// 1B9208: using guessed type int (*dword_1B9208)(void);
// 1B922A: using guessed type char byte_1B922A;
// 1BB8A8: using guessed type int (*dword_1BB8A8)(_DWORD);
// 1BB910: using guessed type int dword_1BB910[];
// 1BBA64: using guessed type int dword_1BBA64;


//----- (00110AFC) --------------------------------------------------------
int sub_110AFC()
{
  int v0; // eax

  sound(110);
  v0 = j___delay(250);
  return nosound(v0);
}
// 13F270: using guessed type int sound(_DWORD);
// 13F2BA: using guessed type int nosound(_DWORD);
// 13F2CC: using guessed type int j___delay(_DWORD);


//----- (00110B34) --------------------------------------------------------
void MarkMemPoolReady_110B34()
{
  flagMemPoolReady_184374 = 1;
}
// 184374: using guessed type int16_t flagMemPoolReady_184374;


//----- (00110B5C) --------------------------------------------------------
int16_t IsMemPoolReady_110B5C()
{
  return flagMemPoolReady_184374;
}
// 184374: using guessed type int16_t flagMemPoolReady_184374;


//----- (00110B89) --------------------------------------------------------
_DWORD *PoolAlloc_110B89(int a1, int a2)
{
  _DWORD *v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-8h]

  v5 = a1;
  if ( (a1 & 3) != 0 )
    v5 = 4 * (a1 >> 2) + 4;
  v4 = (_DWORD *)sub_110DFE(v5 + 12);
  if ( !v4 )
    v4 = sub_110C62(v5 + 12, a2);
  if ( !v4 )
    sub_110EC3(a1, a2);
  *v4 = 0;
  v4[1] = a1;
  v4[2] = 0;
  return v4 + 3;
}


//----- (00110C29) --------------------------------------------------------
int sub_110C29(int a1)
{
  return *(_DWORD *)(a1 - 12 + 4);
}


//----- (00110C62) --------------------------------------------------------
_DWORD *sub_110C62(int a1, int a2)
{
  _DWORD *v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-8h]

  v5 = a1;
  if ( (a1 & 3) != 0 )
    v5 = 4 * (a1 >> 2) + 4;
  v4 = (_DWORD *)sub_110E36(v5 + 12);
  if ( !v4 )
    sub_110EC3(a1, a2);
  *v4 = 0;
  v4[1] = a1;
  v4[2] = 0;
  return v4 + 3;
}


//----- (00110CEE) --------------------------------------------------------
_DWORD *sub_110CEE(int a1, int a2)
{
  *(_DWORD *)(a1 - 12) = 0;
  return sub_110D3C(a1, a2);
}


//----- (00110D3C) --------------------------------------------------------
_DWORD *sub_110D3C(int a1, int a2)
{
  _DWORD *v3; // [esp+8h] [ebp-14h]
  _DWORD *v4; // [esp+10h] [ebp-Ch]
  int v5; // [esp+14h] [ebp-8h]

  v5 = a2;
  if ( (a2 & 3) != 0 )
    v5 = 4 * (a2 >> 2) + 4;
  v4 = (_DWORD *)(a1 - 12);
  if ( v5 + *(_DWORD *)(a1 - 12) + 12 > *(_DWORD *)(a1 - 12 + 4) )
    sub_110F3A(a2, a2 + *v4 - v4[1], v4[1]);
  v3 = (_DWORD *)(*v4 + a1);
  *v4 += v5 + 12;
  *v3 = 0;
  v3[1] = a2;
  v3[2] = 0;
  return v3 + 3;
}


//----- (00110DFE) --------------------------------------------------------
int sub_110DFE(int a1)
{
  return nmalloc(a1);
}
// 13CB78: using guessed type int nmalloc(_DWORD);


//----- (00110E36) --------------------------------------------------------
// Puvodne alokace DOS real-mode pameti pres DPMI 0x0100 (ALLOCATE DOS
// MEMORY BLOCK, INT 31h): prevede bajty na paragrafy (16 B), vrati
// 16*segment = linearni adresu bloku POD 1 MiB. Hra ji pouziva primo
// (sub_113E08: 8KiB buffer, jehoz adresu deli 16 zpet na "segment") i
// jako zalozni cestu PoolAlloc_110B89/sub_110C62.
// VLNA 11 - PORT: zadny real mode neexistuje; puvodni telo s int386
// stubem cetlo NEINICIALIZOVANY vystupni buffer (v3[6]) a vracelo bud
// falesne selhani (-> "Insufficient Memory!" a drive nekonecna sonda
// sub_110FE7) nebo nahodny "ukazatel" (-> pad v sub_113E08). Ted se
// alokuje bezny blok z rozpoctu port_memory. malloc na x64 vraci
// 16-zarovnane bloky, takze prevod adresa>>4 a zpet 16*(addr>>4), ktery
// volajici delaji, funguje. POZOR: 16bit "segment" (word_1B0700 v
// sub_113E08) se pri adresach nad 1 MiB orizne - smi se pouzivat jen
// pro real-mode sluzby, ktere v portu stejne neexistuji (DECOMP_TODO:
// az na ne narazime, presmerovat na port vrstvu).
// Puvodni dekompilovane telo (pro srovnani):
//   v4 = (a1 & 0xF) ? (a1 >> 4) + 1 : a1 >> 4;  // bajty -> paragrafy
//   if ( v4 > 0xFFFF ) return 0;                 // DOS blok max ~1 MiB
//   v2[0] = 256; v2[1] = v4;                     // DPMI fn 0x0100
//   int386(49, v2, v3);                          // INT 31h
//   return v3[6] ? 0 : 16 * v3[0];               // CF ? chyba : 16*segment
int sub_110E36(int a1)
{
  if ( a1 < 0 || ((a1 + 15) >> 4) > 0xFFFF )     // stejny limit jako original
    return 0;
  return (int)(intptr_t)PortMemory_Alloc((unsigned int)a1);
}


//----- (00110EC3) --------------------------------------------------------
void __noreturn sub_110EC3(int a1, int a2)
{
  int v2; // eax
  int v3; // eax

  PortDebug_Checkpoint("110EC3.attempted_bytes", a1); // kolik chtel alokovat
  sub_113DBD();
  printf("Insufficient Memory!\n\n");
  printf("Attempted to allocate %d bytes\n", a1);
  v2 = sub_110FE7();
  printf("Linear space remaining %d bytes\n", v2);
  v3 = sub_111090();
  printf("Dos space remaining %d bytes\n", v3);
  exit(1, a2);
}
// 13F2D1: using guessed type _DWORD printf(char *, ...);


//----- (00110F3A) --------------------------------------------------------
void __noreturn sub_110F3A(int a1, int a2, int a3)
{
  sub_113DBD();
  printf("Unable to Allocate %d bytes (short by %d bytes) in a block size of %d!\n\n", a1, a2, a3);
  exit(1, a2);
}
// 13F2D1: using guessed type _DWORD printf(char *, ...);


//----- (00110F89) --------------------------------------------------------
unsigned int sub_110F89()
{
  int v0; // eax
  int v1; // eax
  _DWORD v3[15]; // [esp+0h] [ebp-7Ch] BYREF
  _BYTE v4[28]; // [esp+3Ch] [ebp-40h] BYREF
  _DWORD v5[8]; // [esp+58h] [ebp-24h] BYREF

  memset(v3, 0, sizeof(v3));
  v5[0] = 1280;
  v5[5] = v3;
  v0 = int386(49, v5, v4);
  v1 = memavl(v0);
  return (unsigned int)(v3[0] + v1) >> 10;
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);
// 13F322: using guessed type int memavl(_DWORD);


//----- (00110FE7) --------------------------------------------------------
// "Linear space remaining" (vola se jen z chyboveho hlaseni sub_110EC3):
// klasicka Watcom sonda volne pameti - alokovala rostouci bloky (po 8 KiB,
// pak po 1 KiB), dokud nmalloc neselhal, a vratila memavl() + posledni
// velikost. VLNA 11 - PORT: presne tady se port zasekaval, ze DVOU duvodu:
//  1) bez emulovaneho rozpoctu pameti (viz port_memory.h) moderni malloc
//     prakticky NEselze -> smycka rostla donekonecna;
//  2) i s rozpoctem je sonda nepouzitelne pomala v Debug buildu - CRT
//     vyplnuje kazdy alokovany blok vzorem 0xCD, takze sonda 8KiB krokem
//     az k 32 MiB znamena ~64 GB zapisu do pameti (na DOSu nmalloc nic
//     nevyplnoval, proto byl original okamzity).
// Port zna volnou pamet primo (memavl = zbytek rozpoctu), takze sondovat
// neni co - vysledek je tentyz udaj, ktery sonda pracne merila. Funkce
// se pouziva jen pro vypis cisla v chybovem hlaseni pred exit(1).
// Puvodni dekompilovane telo (pro srovnani):
//   v2 = 0x2000; v3 = nmalloc(0x2000); nfree(v3);
//   while (v3) { v2 += 0x2000; v3 = nmalloc(v2); nfree(v3); }      // hrube nahoru
//   do { v2 += 1024; v4 = nmalloc(v2); v0 = nfree(v4); } while(v4); // podezrele - roste
//     // NAD uz selhavsi velikost (original mel mozna v2 -= ..., bisekci);
//     // nejde overit pasivnim behem originalu - vetev bezi jen pri
//     // skutecnem nedostatku pameti
//   return memavl(v0) + v2;
int sub_110FE7()
{
  PortDebug_Checkpoint("sub_110FE7.enter", 0); // = jsme v chybove vetvi!
  return memavl();
}
// 13CAF6: using guessed type int nfree(_DWORD);
// 13CB78: using guessed type int nmalloc(_DWORD);
// 13F322: using guessed type int memavl(_DWORD);


//----- (00111090) --------------------------------------------------------
int sub_111090()
{
  _DWORD v1[7]; // [esp+0h] [ebp-44h] BYREF
  _BYTE v2[12]; // [esp+1Ch] [ebp-28h] BYREF
  int v3; // [esp+28h] [ebp-1Ch]
  int v4; // [esp+34h] [ebp-10h]
  int v5; // [esp+38h] [ebp-Ch]
  int i; // [esp+3Ch] [ebp-8h]

  for ( i = 1; ; i += 64 )
  {
    if ( i >= 64000 )
      return -1000;
    v1[0] = 256;
    v1[1] = i;
    int386(49, v1, v2);
    v5 = v3;
    if ( v4 )
      break;
    v1[0] = 257;
    v1[3] = v5;
    int386(49, v1, v2);
  }
  return (i - 1 - (__CFSHL__((i - 1) >> 31, 6) + ((i - 1) >> 31 << 6))) >> 6;
}
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);


//----- (00111131) --------------------------------------------------------
_DWORD *sub_111131(int a1, int a2)
{
  _DWORD *v4; // [esp+4h] [ebp-8h]

  v4 = (_DWORD *)sub_110DFE(a1);
  if ( !v4 )
    v4 = sub_110C62(a1, a2);
  if ( !v4 )
    sub_110EC3(a1, a2);
  return v4;
}


//----- (00111188) --------------------------------------------------------
_DWORD *sub_111188(int a1, int a2)
{
  *(_DWORD *)(a1 - 12) = 0;
  return sub_1111D6(a1, a2);
}


//----- (001111D6) --------------------------------------------------------
_DWORD *sub_1111D6(int a1, int a2)
{
  _DWORD *v3; // [esp+8h] [ebp-14h]
  _DWORD *v4; // [esp+10h] [ebp-Ch]
  int v5; // [esp+14h] [ebp-8h]

  v5 = a2;
  if ( (a2 & 3) != 0 )
    v5 = 4 * (a2 >> 2) + 4;
  v4 = (_DWORD *)(a1 - 12);
  if ( v5 + *(_DWORD *)(a1 - 12) > *(_DWORD *)(a1 - 12 + 4) )
    return 0;
  v3 = (_DWORD *)(*v4 + a1);
  *v4 += v5;
  *v3 = 0;
  v3[1] = a2;
  v3[2] = 0;
  return v3;
}


//----- (0011127C) --------------------------------------------------------
_DWORD *sub_11127C(int a1)
{
  _DWORD *result; // eax

  result = (_DWORD *)(a1 - 12);
  result[2] = *result;
  return result;
}


//----- (001112B4) --------------------------------------------------------
_DWORD *sub_1112B4(int a1)
{
  _DWORD *result; // eax

  result = (_DWORD *)(a1 - 12);
  *result = result[2];
  return result;
}


//----- (001112EC) --------------------------------------------------------
int sub_1112EC(int a1, int a2)
{
  int result; // eax

  if ( dword_184378 >= 40 )
    sub_126487(aMarkBlockStack, a2);
  dword_1AD6C4[2 * dword_184378] = a1;
  result = *(_DWORD *)(a1 - 12);
  dword_1AD6C8[2 * dword_184378++] = *(_DWORD *)(a1 - 12);
  return result;
}
// 184378: using guessed type int dword_184378;
// 1AD6C4: using guessed type int dword_1AD6C4[];
// 1AD6C8: using guessed type int dword_1AD6C8[79];


//----- (001113CC) --------------------------------------------------------
_DWORD *sub_1113CC(int a1, int a2)
{
  _DWORD *result; // eax

  if ( dword_184378 <= 0 )
    sub_126487(aMarkBlockStack_0, a2);
  --dword_184378;
  result = (_DWORD *)(dword_1AD6C4[2 * dword_184378] - 12);
  *result = dword_1AD6C8[2 * dword_184378];
  return result;
}
// 184378: using guessed type int dword_184378;
// 1AD6C4: using guessed type int dword_1AD6C4[];
// 1AD6C8: using guessed type int dword_1AD6C8[79];


//----- (00111499) --------------------------------------------------------
int sub_111499(int a1)
{
  return *(_DWORD *)(a1 - 12 + 4) - *(_DWORD *)(a1 - 12);
}


//----- (001114D7) --------------------------------------------------------
int FindMoxSetPath_1114D7(_BYTE *a1, _BYTE *a2)
{
  int v3; // [esp+8h] [ebp-8h]

  if ( *a1 )
    v3 = unknown_libname_1(a1, 0, &unk_1AD828);
  else
    v3 = unknown_libname_2(&unk_1AD828);
  if ( v3 )
  {
    *a2 = 0;
    return 0;
  }
  else
  {
    strcpy(a2, &unk_1AD846);
    return 1;
  }
}
// 139A4C: using guessed type int unknown_libname_1(_DWORD, _DWORD, _DWORD);
// 139A69: using guessed type int unknown_libname_2(_DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);


//----- (00111610) --------------------------------------------------------
int sub_111610(int a1)
{
  if ( unknown_libname_1(a1, 0, &unk_1AD828) )
    return 0;
  else
    return dword_1AD842;
}
// 139A4C: using guessed type int unknown_libname_1(_DWORD, _DWORD, _DWORD);
// 1AD842: using guessed type int dword_1AD842;


//----- (00111660) --------------------------------------------------------
int *sub_111660(int a1)
{
  if ( unknown_libname_1(a1, 0, &unk_1AD828) )
    return 0;
  dword_1AD818 = ((word_1AD840 & 0xFE00) >> 9) + 1980;
  dword_1AD814 = ((word_1AD840 & 0x1E0) >> 5) - 1;
  dword_1AD810 = word_1AD840 & 0x1F;
  dword_1AD80C = (word_1AD83E & 0xF800) >> 11;
  dword_1AD808 = (word_1AD83E & 0x7E0) >> 5;
  dword_1AD804 = 2 * (word_1AD83E & 0x1F);
  dword_1AD81C = 0;
  dword_1AD820 = 0;
  dword_1AD824 = 0;
  return &dword_1AD804;
}
// 139A4C: using guessed type int unknown_libname_1(_DWORD, _DWORD, _DWORD);
// 1AD804: using guessed type int dword_1AD804;
// 1AD808: using guessed type int dword_1AD808;
// 1AD80C: using guessed type int dword_1AD80C;
// 1AD810: using guessed type int dword_1AD810;
// 1AD814: using guessed type int dword_1AD814;
// 1AD818: using guessed type int dword_1AD818;
// 1AD81C: using guessed type int dword_1AD81C;
// 1AD820: using guessed type int dword_1AD820;
// 1AD824: using guessed type int dword_1AD824;
// 1AD83E: using guessed type int16_t word_1AD83E;
// 1AD840: using guessed type int16_t word_1AD840;


//----- (00111763) --------------------------------------------------------
// Vrati volne misto na aktualnim disku v bajtech (0 = chyba nebo nic) -
// hra s tim testuje, jestli se jeste vejde ulozena pozice (orion_part_20.c,
// srovnani s dword_1BF35C). Puvodni dekompilat mel misto struktury 4 volne
// 16bitove lokaly (v1..v4) lezici nahodou spravne za sebou na zasobniku -
// vytknuto do DosDiskFree (layout viz port_dos.h), soucin poli odpovida
// puvodnimu "v4 * v3 * v2" (bytes_per_sector * sectors_per_cluster *
// avail_clusters). Diky 16bitovym stropum v dos_getdiskfree se soucin
// vzdy vejde do int bez preteceni.
int GetFreeDiskSpace_111763()
{
  struct DosDiskFree v1; // [esp+0h] [ebp-10h] BYREF

  if ( dos_getdiskfree(0, &v1) )
    return 0;
  return v1.bytes_per_sector * v1.sectors_per_cluster * v1.avail_clusters;
}


//----- (001117BF) --------------------------------------------------------
int sub_1117BF(int a1)
{
  return j_unlink(a1);
}
// 13F3F9: using guessed type int j_unlink(_DWORD);


//----- (0011181C) --------------------------------------------------------
bool sub_11181C(int a1)
{
  _BYTE v2[44]; // [esp+4h] [ebp-34h] BYREF
  int v3; // [esp+30h] [ebp-8h]

  v3 = a1;
  return unknown_libname_1(a1, 0, v2) == 0;
}
// 139A4C: using guessed type int unknown_libname_1(_DWORD, _DWORD, _DWORD);


//----- (0011190B) --------------------------------------------------------
int sub_11190B(int a1)
{
  return strcpy(aSoundLbx, a1);
}
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);


//----- (00111932) --------------------------------------------------------
int sub_111932(int a1)
{
  return strcpy(aMusicLbx, a1);
}
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);


//----- (00111959) --------------------------------------------------------
int SelectResourceModule_111959(int a1)
{
  if ( a1 )
  {
    dword_184398 = sub_111499(a1);
    if ( dword_184398 )
      dword_184394 = a1;
    else
      dword_184394 = 0;
  }
  else
  {
    dword_184398 = 0;
    dword_184394 = 0;
  }
  return sub_1121BA();
}
// 184394: using guessed type int dword_184394;
// 184398: using guessed type int dword_184398;


//----- (001119BE) --------------------------------------------------------
int sub_1119BE(int a1)
{
  int result; // eax
  int v2; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  ++dword_18445B;
  v2 = 1;
LABEL_2:
  if ( v2 < 33 )
  {
    for ( i = 0; ; ++i )
    {
      if ( i >= dword_1AE0B4[10 * v2] )
      {
        result = v2++;
        goto LABEL_2;
      }
      if ( a1 == dword_1B0670[(uint8_t)byte_1AE0B8[40 * v2 + i]] )
        break;
    }
    if ( dword_1AE0B4[10 * v2] <= 1 )
    {
      result = 40 * v2;
      dword_1AE0B4[10 * v2] = -1;
    }
    else
    {
      --dword_1AE0B4[10 * v2];
      result = i + 40 * v2;
      byte_1AE0B8[result] = byte_1AE0B8[40 * v2 + dword_1AE0B4[10 * v2]];
    }
  }
  return result;
}
// 18445B: using guessed type int dword_18445B;
// 1AE0B4: using guessed type int dword_1AE0B4[];
// 1B0670: using guessed type int dword_1B0670[17];


//----- (00111A82) --------------------------------------------------------
int sub_111A82()
{
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  for ( i = 1; i < 33; ++i )
  {
    if ( &dword_1AE0AC[10 * i] == (int *)5 )
      dword_1AE0B4[10 * i] = -1;
    result = i;
  }
  return result;
}
// 1AE0AC: using guessed type int dword_1AE0AC[];
// 1AE0B4: using guessed type int dword_1AE0B4[];


//----- (00111ACD) --------------------------------------------------------
void sub_111ACD()
{
  ++dword_1843A0;
}
// 1843A0: using guessed type int dword_1843A0;


//----- (00111AE2) --------------------------------------------------------
int sub_111AE2()
{
  int v0; // eax
  int v1; // eax
  int i; // [esp+0h] [ebp-8h]
  int j; // [esp+0h] [ebp-8h]

  for ( i = 1; i < 16; ++i )
  {
    sub_1413FF(dword_1B0670[i]);
    if ( v0 == 2 )
      return i;
  }
  for ( j = 1; ; ++j )
  {
    if ( j >= 16 )
      return 0;
    sub_1413FF(dword_1B0670[j]);
    if ( v1 == 8 )
      break;
  }
  return j;
}
// 111B1E: variable 'v0' is possibly undefined
// 111B58: variable 'v1' is possibly undefined
// 1B0670: using guessed type int dword_1B0670[17];


//----- (00111B77) --------------------------------------------------------
int sub_111B77()
{
  int i; // [esp+0h] [ebp-8h]

  for ( i = 1; ; ++i )
  {
    if ( i >= 33 )
    {
      hr_debugbreak();
      return -1;
    }
    if ( dword_1AE0CC[10 * i] == -1 && dword_1AE0D0[10 * i] == -1 )
      break;
  }
  return i;
}
// 1AE0CC: using guessed type int dword_1AE0CC[];
// 1AE0D0: using guessed type int dword_1AE0D0[];


//----- (00111BD6) --------------------------------------------------------
int sub_111BD6()
{
  int result; // eax
  int i; // [esp+0h] [ebp-Ch]
  int *v2; // [esp+4h] [ebp-8h]
  int *v3; // [esp+8h] [ebp-4h]

  for ( i = 1; i != -1; i = result )
  {
    result = 40 * i;
    if ( dword_1AE0CC[10 * i] == -1 )
      break;
    v2 = &dword_1AE0AC[10 * i];
    v3 = &dword_1AE0AC[10 * v2[8]];
    if ( !v2[2] && !v3[2] )
    {
      v2[8] = v3[8];
      v2[1] += v3[1];
      v2[2] = 0;
      *((_BYTE *)v2 + 12) = 0;
      v2[7] = 0;
      memset(v3, 0, 40);
      v3[8] = -1;
      v3[9] = -1;
    }
    result = v2[8];
  }
  return result;
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 1AE0AC: using guessed type int dword_1AE0AC[];
// 1AE0CC: using guessed type int dword_1AE0CC[];


//----- (00111CA3) --------------------------------------------------------
int sub_111CA3()
{
  int result; // eax
  int i; // [esp+0h] [ebp-Ch]
  int *v2; // [esp+4h] [ebp-8h]
  int *v3; // [esp+8h] [ebp-4h]

  for ( i = 1; i != -1; i = result )
  {
    result = 40 * i;
    if ( dword_1AE0CC[10 * i] == -1 )
      break;
    v2 = &dword_1AE0AC[10 * i];
    v3 = &dword_1AE0AC[10 * v2[8]];
    if ( v2[2] < 1 && v3[2] < 1 )
    {
      v2[8] = v3[8];
      v2[1] += v3[1];
      v2[2] = 0;
      *((_BYTE *)v2 + 12) = 0;
      v2[7] = 0;
      memset(v3, 0, 40);
      v3[8] = -1;
      v3[9] = -1;
    }
    result = v2[8];
  }
  return result;
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 1AE0AC: using guessed type int dword_1AE0AC[];
// 1AE0CC: using guessed type int dword_1AE0CC[];


//----- (00111D70) --------------------------------------------------------
int sub_111D70( int a1, int a2, int a3)
{
  bool v4; // [esp+0h] [ebp-2Ch]
  int v6; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int *v8; // [esp+20h] [ebp-Ch]
  int v9; // [esp+24h] [ebp-8h]

  v8 = dword_1AE0AC;
  v9 = 0;
  if ( a3 > dword_184398 )
    return 0;
  sub_111BD6();
  for ( i = 0; i < 3; ++i )
  {
    while ( 1 )
    {
      if ( i )
        v4 = v8[2] < 1;
      else
        v4 = v8[2] == 0;
      if ( v4 && a3 <= v8[1] )
      {
        v6 = sub_111B77();
        if ( v6 < 0 )
          return 0;
        dword_1AE0D0[10 * v6] = v9;
        dword_1AE0CC[10 * v6] = v8[8];
        dword_1AE0AC[10 * v6] = a3 + *v8;
        dword_1AE0B0[10 * v6] = v8[1] - a3;
        dword_1AE0B4[10 * v6] = 0;
        byte_1AE0B8[40 * v6] = 0;
        dword_1AE0C8[10 * v6] = 0;
        v8[8] = v6;
        *((_BYTE *)v8 + 12) = a1;
        v8[7] = a2;
        v8[1] = a3;
        v8[2] = 1;
        return dword_184394 + *v8;
      }
      if ( v8[8] < 0 )
        break;
      v9 = v8[8];
      v8 = &dword_1AE0AC[10 * v9];
    }
    v8 = dword_1AE0AC;
    v9 = 0;
    if ( i == 1 )
      sub_111CA3();
  }
  return 0;
}
// 184394: using guessed type int dword_184394;
// 184398: using guessed type int dword_184398;
// 1AE0AC: using guessed type int dword_1AE0AC[];
// 1AE0B0: using guessed type int dword_1AE0B0[];
// 1AE0B4: using guessed type int dword_1AE0B4[];
// 1AE0C8: using guessed type int dword_1AE0C8[];
// 1AE0CC: using guessed type int dword_1AE0CC[];
// 1AE0D0: using guessed type int dword_1AE0D0[];


//----- (00111F3E) --------------------------------------------------------
void sub_111F3E()
{
  int v0 = 0; // eax
  int v1 = 0; // eax
  int v2; // eax
  int i; // [esp+0h] [ebp-8h]
  int j; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  if ( !dword_18439C )
  {
    dword_18439C = 1;
    memset(word_1AE5D4, 0, sizeof(word_1AE5D4));
    memset(&unk_1AF620, 0, 4172);
    memset(dword_1B06B4, 0, sizeof(dword_1B06B4));
    PortDebug_Checkpoint("111F3E.after_memsets", 0);
    sub_13F640();
    PortDebug_Checkpoint("111F3E.after_13F640", 0);
    sub_1400A9((int)sub_111ACD);
    PortDebug_Checkpoint("111F3E.after_1400A9", 0);
    v5 = v0;
    if ( v0 == -1 )
    {
      printf("\r\nCould not register timer with AIL.\r\n");
      sub_13F7BC();
      exit(255, 0);
    }
    sub_1402FD(v0, 0x3Cu);
    PortDebug_Checkpoint("111F3E.after_1402FD", 0);
    sub_1404C7(v5);
    PortDebug_Checkpoint("111F3E.after_1404C7", 0);
    sub_13F84F(4, 17);
    sub_13F84F(7, 1);
    sub_13F84F(1, 22050);
    sub_13F84F(8, 0);
    sub_13F84F(0, 80);
    PortDebug_Checkpoint("111F3E.after_13F84F", 0);
    sub_140979();
    PortDebug_Checkpoint("111F3E.after_140979", 0);
    dword_184388 = v1;
    if ( v1 )
    {
      sub_13AD33(word_1AE5D4, (int)aSoundLbx);
      memset(dword_1B0670, 0, 4);
      for ( i = 1; i <= 16; ++i )
      {
        sub_140BB1(dword_184388);
        dword_1B0670[i] = v2;
        sub_140DFC((int *)dword_1B0670[i]);
      }
      dword_184380 = 1;
    }
    if ( dword_184394 )
    {
      dword_184398 = sub_111499(dword_184394);
      memset(dword_184394, 0, dword_184398);
    }
    PortDebug_Checkpoint("111F3E.before_slots_memset", 0);
    memset(dword_1AE0AC, 0, 1320);
    for ( j = 0; j < 33; ++j )
    {
      dword_1AE0CC[10 * j] = -1;
      dword_1AE0D0[10 * j] = -1;
    }
    dword_1AE0CC[0] = 1;
    dword_1AE0C8[0] = -1;
    dword_1AE0B4[0] = 1000000; // vlna 12: IDA false-positive "&loc_F4240" = konstanta 1e6 (AIL us)
    dword_1AE0D8 = dword_184398;
    dword_1AE0F8 = 0;
  }
}
// 111FA9: variable 'v0' is possibly undefined
// 11202D: variable 'v1' is possibly undefined
// 11208A: variable 'v2' is possibly undefined
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 13F2D1: using guessed type _DWORD printf(char *, ...);
// 184380: using guessed type int dword_184380;
// 184388: using guessed type int dword_184388;
// 184394: using guessed type int dword_184394;
// 184398: using guessed type int dword_184398;
// 18439C: using guessed type int dword_18439C;
// 1AE0AC: using guessed type int dword_1AE0AC[];
// 1AE0B4: using guessed type int dword_1AE0B4[];
// 1AE0C8: using guessed type int dword_1AE0C8[];
// 1AE0CC: using guessed type int dword_1AE0CC[];
// 1AE0D0: using guessed type int dword_1AE0D0[];
// 1AE0D8: using guessed type int dword_1AE0D8;
// 1AE0F8: using guessed type int dword_1AE0F8;
// 1AE5D4: using guessed type int16_t word_1AE5D4[2086];
// 1B0670: using guessed type int dword_1B0670[17];
// 1B06B4: using guessed type int dword_1B06B4[17];


//----- (0011215B) --------------------------------------------------------
int sub_11215B()
{
  int result=0; // eax

  if ( dword_18439C )
  {
    dword_18439C = 0;
    sub_112816();
    sub_112FD4();
    sub_13AE74((int)&unk_1AE5D4);
    sub_13AE74((int)&unk_1AF620);
    result = sub_13F7BC();
    dword_184380 = 0;
    dword_184384 = 0;
  }
  return result;
}
// 184380: using guessed type int dword_184380;
// 184384: using guessed type int dword_184384;
// 18439C: using guessed type int dword_18439C;


//----- (001121BA) --------------------------------------------------------
int sub_1121BA()
{
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  sub_112816();
  if ( dword_184394 )
    memset(dword_184394, 0, dword_184398);
  memset(dword_1AE0AC, 0, 1320);
  for ( i = 0; i < 33; ++i )
  {
    dword_1AE0CC[10 * i] = -1;
    dword_1AE0D0[10 * i] = -1;
  }
  dword_1AE0CC[0] = 1;
  dword_1AE0C8[0] = -1;
  dword_1AE0B4[0] = 1000000; // vlna 12: IDA false-positive "&loc_F4240" = konstanta 1e6 (AIL us)
  result = dword_184398;
  dword_1AE0D8 = dword_184398;
  dword_1AE0F8 = 0;
  return result;
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 184394: using guessed type int dword_184394;
// 184398: using guessed type int dword_184398;
// 1AE0AC: using guessed type int dword_1AE0AC[];
// 1AE0B4: using guessed type int dword_1AE0B4[];
// 1AE0C8: using guessed type int dword_1AE0C8[];
// 1AE0CC: using guessed type int dword_1AE0CC[];
// 1AE0D0: using guessed type int dword_1AE0D0[];
// 1AE0D8: using guessed type int dword_1AE0D8;
// 1AE0F8: using guessed type int dword_1AE0F8;


//----- (00112269) --------------------------------------------------------
void sub_112269()
{
  if ( dword_18439C )
  {
    if ( dword_184388 )
      dword_184380 = 1;
  }
}
// 184380: using guessed type int dword_184380;
// 184388: using guessed type int dword_184388;
// 18439C: using guessed type int dword_18439C;


//----- (0011229C) --------------------------------------------------------
int sub_11229C()
{
  int result; // eax

  result = sub_112816();
  dword_184380 = 0;
  return result;
}
// 184380: using guessed type int dword_184380;


//----- (001122C0) --------------------------------------------------------
int sub_1122C0(int a1)
{
  int v1; // eax
  int v4; // [esp+4h] [ebp-8h]

  if ( !dword_184380 )
    return 0;
  v4 = sub_111AE2();
  if ( !v4 )
    return 0;
  sub_140DFC((int *)dword_1B0670[v4]);
  sub_14129D(dword_1B0670[v4], (uint8_t)byte_1843A4);
  sub_141313(dword_1B0670[v4], (uint8_t)byte_1843A5);
  sub_140E69((_DWORD *)dword_1B0670[v4], a1, -1);
  if ( !v1 )
    return 0;
  sub_141073((_DWORD *)dword_1B0670[v4]);
  return v4;
}
// 112368: variable 'v1' is possibly undefined
// 184380: using guessed type int dword_184380;
// 1843A4: using guessed type char byte_1843A4;
// 1843A5: using guessed type char byte_1843A5;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (00112399) --------------------------------------------------------
int sub_112399(int a1)
{
  int v1; // eax
  int v2; // eax
  int i; // [esp+4h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]

  if ( !dword_184380 )
    return 0;
  v7 = sub_111AE2();
  if ( !v7 || !a1 || !dword_184394 || !dword_184398 )
    return 0;
  for ( i = 0; i < 33; ++i )
  {
    if ( dword_1AE0C8[10 * i] == a1 && dword_1AE0B4[10 * i] )
    {
      if ( dword_1AE0B4[10 * i] == -1 )
      {
        dword_1AE0B4[10 * i] = 1;
        byte_1AE0B8[40 * i] = v7;
LABEL_21:
        sub_140DFC((int *)dword_1B0670[v7]);
        sub_14129D(dword_1B0670[v7], (uint8_t)byte_1843A4);
        sub_141313(dword_1B0670[v7], (uint8_t)byte_1843A5);
        sub_141F1F(dword_1B0670[v7], (int)sub_1119BE);
        sub_140E69((_DWORD *)dword_1B0670[v7], dword_184394 + dword_1AE0AC[10 * i], -1);
        sub_141073((_DWORD *)dword_1B0670[v7]);
        ++dword_184457;
        return v7;
      }
      if ( dword_1AE0B4[10 * i] > 0 )
      {
        byte_1AE0B8[40 * i + dword_1AE0B4[10 * i]++] = v7;
        goto LABEL_21;
      }
    }
  }
  v1 = sub_13AFD2((int)&unk_1AE5D4, a1);
  if ( !v1 )
    return 0;
  v6 = sub_111D70(v7, a1, v1);
  if ( !v6 )
    return 0;
  sub_13AEBB((int)&unk_1AE5D4, a1, v6);
  sub_140DFC((int *)dword_1B0670[v7]);
  sub_14129D(dword_1B0670[v7], (uint8_t)byte_1843A4);
  sub_141313(dword_1B0670[v7], (uint8_t)byte_1843A5);
  sub_140E69((_DWORD *)dword_1B0670[v7], v6, -1);
  if ( !v2 )
    return 0;
  sub_141F1F(dword_1B0670[v7], (int)sub_1119BE);
  sub_141073((_DWORD *)dword_1B0670[v7]);
  ++dword_184457;
  return v7;
}
// 112605: variable 'v2' is possibly undefined
// 184380: using guessed type int dword_184380;
// 184394: using guessed type int dword_184394;
// 184398: using guessed type int dword_184398;
// 1843A4: using guessed type char byte_1843A4;
// 1843A5: using guessed type char byte_1843A5;
// 184457: using guessed type int dword_184457;
// 1AE0AC: using guessed type int dword_1AE0AC[];
// 1AE0B4: using guessed type int dword_1AE0B4[];
// 1AE0C8: using guessed type int dword_1AE0C8[];
// 1B0670: using guessed type int dword_1B0670[17];


//----- (00112656) --------------------------------------------------------
int sub_112656()
{
  return 100 * dword_1843A7 / 127;
}
// 1843A7: using guessed type int dword_1843A7;


//----- (00112686) --------------------------------------------------------
char sub_112686(int a1)
{
  char result; // al
  int v2; // [esp+0h] [ebp-10h]
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  if ( 127 * a1 / 100 >= 0 )
  {
    if ( 127 * a1 / 100 <= 127 )
      v3 = 127 * a1 / 100;
    else
      v3 = 127;
    v2 = v3;
  }
  else
  {
    v2 = 0;
  }
  dword_1843A7 = v2;
  result = v2;
  byte_1843A4 = v2;
  for ( i = 1; i <= 16; ++i )
  {
    if ( sub_1128EA(i) && sub_11299D(i) > (uint8_t)byte_1843A4 && i != dword_184447 )
      sub_1129FA(i, (uint8_t)byte_1843A4);
    result = i;
  }
  return result;
}
// 1843A4: using guessed type char byte_1843A4;
// 1843A7: using guessed type int dword_1843A7;
// 184447: using guessed type int dword_184447;


//----- (0011275E) --------------------------------------------------------
void sub_11275E(int a1)
{
  if ( dword_184380 && a1 > 0 && a1 < 33 )
    sub_141073((_DWORD *)dword_1B0670[a1]);
}
// 184380: using guessed type int dword_184380;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (001127A3) --------------------------------------------------------
int sub_1127A3(int result)
{
  int v1; // [esp+0h] [ebp-4h]

  v1 = result;
  if ( dword_184380 )
  {
    if ( result == -1 )
    {
      return sub_112816();
    }
    else if ( result && result <= 16 && result != dword_184447 )
    {
      sub_1410E0(dword_1B0670[result]);
      return sub_1119BE(dword_1B0670[v1]);
    }
  }
  return result;
}
// 112816: using guessed type int sub_112816(void);
// 184380: using guessed type int dword_184380;
// 184447: using guessed type int dword_184447;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (00112816) --------------------------------------------------------
int sub_112816()
{
  int result=0; // eax
  int i; // [esp+0h] [ebp-4h]

  if ( dword_184380 )
  {
    for ( i = 1; i <= 16; ++i )
    {
      sub_1127A3(i);
      result = i;
    }
  }
  return result;
}
// 184380: using guessed type int dword_184380;


//----- (00112857) --------------------------------------------------------
void sub_112857(int a1)
{
  if ( dword_184380 )
  {
    if ( a1 == -1 )
    {
      sub_1128A9();
    }
    else if ( a1 )
    {
      if ( a1 <= 16 )
        sub_14114D(dword_1B0670[a1]);
    }
  }
}
// 184380: using guessed type int dword_184380;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (001128A9) --------------------------------------------------------
int sub_1128A9()
{
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  if ( dword_184380 )
  {
    for ( i = 1; i <= 16; ++i )
    {
      sub_112857(i);
      result = i;
    }
  }
  return result;
}
// 112857: using guessed type int sub_112857(_DWORD);
// 184380: using guessed type int dword_184380;


//----- (001128EA) --------------------------------------------------------
int sub_1128EA(int a1)
{
  int i; // [esp+4h] [ebp-Ch]
  int j; // [esp+8h] [ebp-8h]

  if ( !dword_184380 )
    return 0;
  if ( !a1 )
    return 0;
  for ( i = 0; i < 16; ++i )
  {
    if ( dword_1AE0B4[10 * i] > 0 )
    {
      for ( j = 0; j < dword_1AE0B4[10 * i]; ++j )
      {
        if ( (uint8_t)byte_1AE0B8[40 * i + j] == a1 )
          return 1;
      }
    }
  }
  return 0;
}
// 184380: using guessed type int dword_184380;
// 1AE0B4: using guessed type int dword_1AE0B4[];


//----- (0011299D) --------------------------------------------------------
int sub_11299D(int a1)
{
  int v1; // eax

  if ( !dword_184380 )
    return 0;
  if ( !a1 || a1 > 16 )
    return 0;
  sub_1415D5(dword_1B0670[a1]);
  return v1;
}
// 1129E2: variable 'v1' is possibly undefined
// 184380: using guessed type int dword_184380;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (001129FA) --------------------------------------------------------
void sub_1129FA(int a1, int a2)
{
  if ( dword_184380 )
  {
    if ( a1 == -1 )
    {
      sub_112A5C(a2);
    }
    else if ( a1 && a1 <= 16 && a2 <= 127 )
    {
      sub_14129D(dword_1B0670[a1], a2);
    }
  }
}
// 184380: using guessed type int dword_184380;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (00112A5C) --------------------------------------------------------
char sub_112A5C(int a1)
{
  char v2; // [esp+4h] [ebp-Ch]
  int v3; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v3 = a1;
  if ( dword_184380 )
  {
    if ( a1 >= 0 )
    {
      if ( a1 > 127 )
        v3 = 127;
    }
    else
    {
      v3 = 0;
    }
    if ( v3 <= dword_1843A7 )
      v2 = v3;
    else
      v2 = dword_1843A7;
    LOBYTE(a1) = v2;
    byte_1843A4 = v2;
    for ( i = 1; i <= 16; ++i )
    {
      if ( i != dword_184447 )
        sub_1129FA(i, v3);
      LOBYTE(a1) = i;
    }
  }
  return a1;
}
// 112A9A: conditional instruction was optimized away because %var_8.4<80u
// 1129FA: using guessed type int sub_1129FA(_DWORD, _DWORD);
// 184380: using guessed type int dword_184380;
// 1843A4: using guessed type char byte_1843A4;
// 1843A7: using guessed type int dword_1843A7;
// 184447: using guessed type int dword_184447;


//----- (00112B06) --------------------------------------------------------
int sub_112B06(int a1)
{
  int v1; // eax

  if ( !dword_184380 || !a1 || a1 > 16 )
    return 64;
  sub_1416BA(dword_1B0670[a1]);
  return v1;
}
// 112B44: variable 'v1' is possibly undefined
// 184380: using guessed type int dword_184380;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (00112B5C) --------------------------------------------------------
void sub_112B5C(int a1, int a2)
{
  if ( dword_184380 )
  {
    if ( a1 == -1 )
    {
      sub_112BBE(a2);
    }
    else if ( a1 && a1 <= 16 && a2 <= 127 )
    {
      sub_141313(dword_1B0670[a1], a2);
    }
  }
}
// 184380: using guessed type int dword_184380;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (00112BBE) --------------------------------------------------------
char sub_112BBE(int a1)
{
  int v2; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  v2 = a1;
  if ( dword_184380 )
  {
    if ( a1 >= 0 )
    {
      if ( a1 > 127 )
        v2 = 127;
    }
    else
    {
      v2 = 0;
    }
    LOBYTE(a1) = v2;
    byte_1843A5 = v2;
    for ( i = 1; i <= 16; ++i )
    {
      sub_112B5C(i, v2);
      LOBYTE(a1) = i;
    }
  }
  return a1;
}
// 112B5C: using guessed type int sub_112B5C(_DWORD, _DWORD);
// 184380: using guessed type int dword_184380;
// 1843A5: using guessed type char byte_1843A5;


//----- (00112C29) --------------------------------------------------------
void sub_112C29(int a1, int a2)
{
  int v3; // [esp+4h] [ebp-4h]

  v3 = a2;
  if ( a1 >= 1 && a1 <= 16 && a2 && dword_184380 )
  {
    if ( a2 == -1 )
      v3 = 0;
    if ( sub_1128EA(a1) )
      sub_141389(dword_1B0670[a1], v3);
  }
}
// 184380: using guessed type int dword_184380;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (00112C96) --------------------------------------------------------
int sub_112C96(int result, int a2)
{
  int v2; // [esp+0h] [ebp-8h]

  v2 = result;
  if ( result >= 1 && result <= 16 )
  {
    if ( dword_184380 )
    {
      result = a2;
      dword_1B06B4[v2] = a2;
    }
  }
  return result;
}
// 184380: using guessed type int dword_184380;
// 1B06B4: using guessed type int dword_1B06B4[17];


//----- (00112CD9) --------------------------------------------------------
void sub_112CD9(int a1, int a2)
{
  int v2; // eax
  int v4; // [esp+8h] [ebp-4h]

  if ( a1 >= 1 && a1 <= 16 && dword_184380 )
  {
    sub_1414E4(dword_1B0670[a1]);
    v4 = a2 + v2;
    if ( a2 + v2 < 0 )
      v4 = 0;
    sub_141227(dword_1B0670[a1], v4);
  }
}
// 112D1F: variable 'v2' is possibly undefined
// 184380: using guessed type int dword_184380;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (00112D4F) --------------------------------------------------------
void sub_112D4F()
{
  if ( dword_18439C )
  {
    if ( dword_18438C )
      dword_184384 = 1;
  }
}
// 184384: using guessed type int dword_184384;
// 18438C: using guessed type int dword_18438C;
// 18439C: using guessed type int dword_18439C;


//----- (00112D82) --------------------------------------------------------
void sub_112D82()
{
  sub_112FD4();
  dword_184384 = 0;
}
// 184384: using guessed type int dword_184384;


//----- (00112DA6) --------------------------------------------------------
void sub_112DA6(int a1)
{
  int v1; // eax

  if ( dword_184384 )
  {
    sub_1426D1((int **)dword_1B066C, a1, 0);
    if ( v1 > 0 )
    {
      sub_142A00((_DWORD *)dword_1B066C, (uint8_t)byte_1843A6, 200);
      sub_1427CA((_DWORD *)dword_1B066C);
    }
  }
}
// 112DDB: variable 'v1' is possibly undefined
// 184384: using guessed type int dword_184384;
// 1843A6: using guessed type char byte_1843A6;
// 1B066C: using guessed type int dword_1B066C;


//----- (00112E0F) --------------------------------------------------------
void sub_112E0F(int a1)
{
  int v1; // eax
  int i; // [esp+4h] [ebp-Ch]
  int v4; // [esp+Ch] [ebp-4h]

  if ( a1 && dword_184384 )
  {
    for ( i = 0; i < 33; ++i )
    {
      if ( a1 + 512 == dword_1AE0C8[10 * i] && dword_1AE0B4[10 * i] )
      {
        if ( dword_1AE0B4[10 * i] == -1 )
        {
          dword_1AE0B4[10 * i] = 1;
LABEL_16:
          sub_142837((_DWORD *)dword_1B066C);
          sub_14390B(dword_1B066C, (int)sub_111A82);
          sub_1426D1((int **)dword_1B066C, dword_1AE0AC[10 * i] + dword_184394, 0);
          sub_142A00((_DWORD *)dword_1B066C, (uint8_t)byte_1843A6, 200);
          sub_1427CA((_DWORD *)dword_1B066C);
          return;
        }
        if ( dword_1AE0B4[10 * i] > 0 )
        {
          ++dword_1AE0B4[10 * i];
          goto LABEL_16;
        }
      }
    }
    v1 = sub_13AFD2((int)&unk_1AF620, a1);
    if ( v1 )
    {
      v4 = sub_111D70(17, a1 + 512, v1);
      if ( v4 )
      {
        sub_13AEBB((int)&unk_1AF620, a1, v4);
        sub_142837((_DWORD *)dword_1B066C);
        sub_1426D1((int **)dword_1B066C, v4, 0);
        sub_142A00((_DWORD *)dword_1B066C, (uint8_t)byte_1843A6, 200);
        sub_14390B(dword_1B066C, (int)sub_111A82);
        sub_1427CA((_DWORD *)dword_1B066C);
      }
    }
  }
}
// 184384: using guessed type int dword_184384;
// 184394: using guessed type int dword_184394;
// 1843A6: using guessed type char byte_1843A6;
// 1AE0AC: using guessed type int dword_1AE0AC[];
// 1AE0B4: using guessed type int dword_1AE0B4[];
// 1AE0C8: using guessed type int dword_1AE0C8[];
// 1B066C: using guessed type int dword_1B066C;


//----- (00112FD4) --------------------------------------------------------
void sub_112FD4()
{
  if ( dword_184384 )
    sub_142911((_DWORD *)dword_1B066C);
}
// 184384: using guessed type int dword_184384;
// 1B066C: using guessed type int dword_1B066C;


//----- (00113000) --------------------------------------------------------
void sub_113000()
{
  if ( dword_184384 )
    sub_1428A4((_DWORD *)dword_1B066C);
}
// 184384: using guessed type int dword_184384;
// 1B066C: using guessed type int dword_1B066C;


//----- (0011302C) --------------------------------------------------------
unsigned int sub_11302C(unsigned int result)
{
  if ( result < 0x80 )
  {
    if ( dword_184384 )
    {
      byte_1843A6 = result;
      return sub_142A00((_DWORD *)dword_1B066C, result, 200);
    }
  }
  return result;
}
// 184384: using guessed type int dword_184384;
// 1843A6: using guessed type char byte_1843A6;
// 1B066C: using guessed type int dword_1B066C;


//----- (0011307E) --------------------------------------------------------
int sub_11307E()
{
  int v0; // eax

  if ( !dword_184384 )
    return 0;
  sub_142CC2(dword_1B066C);
  return v0;
}
// 1130AC: variable 'v0' is possibly undefined
// 184384: using guessed type int dword_184384;
// 1B066C: using guessed type int dword_1B066C;


//----- (001130BB) --------------------------------------------------------
void sub_1130BB(int a1)
{
  if ( dword_184384 )
    sub_142A82(dword_1B066C, a1);
}
// 184384: using guessed type int dword_184384;
// 1B066C: using guessed type int dword_1B066C;


//----- (001130F0) --------------------------------------------------------
int sub_1130F0(int result)
{
  if ( dword_184384 )
    return sub_142A00((_DWORD *)dword_1B066C, 0, 1000 * result);
  return result;
}
// 184384: using guessed type int dword_184384;
// 1B066C: using guessed type int dword_1B066C;


//----- (0011312B) --------------------------------------------------------
int sub_11312B(int result)
{
  if ( dword_184384 )
    return sub_142A00((_DWORD *)dword_1B066C, 127, 1000 * result);
  return result;
}
// 184384: using guessed type int dword_184384;
// 1B066C: using guessed type int dword_1B066C;


//----- (00113166) --------------------------------------------------------
bool sub_113166()
{
  int v0; // eax

  if ( !dword_184384 )
    return 0;
  sub_142AF8(dword_1B066C);
  return v0 == 4;
}
// 113197: variable 'v0' is possibly undefined
// 184384: using guessed type int dword_184384;
// 1B066C: using guessed type int dword_1B066C;


//----- (001131BB) --------------------------------------------------------
void sub_1131BB(int a1)
{
  if ( dword_184384 )
    sub_14390B(dword_1B066C, a1);
}
// 184384: using guessed type int dword_184384;
// 1B066C: using guessed type int dword_1B066C;


//----- (001131F0) --------------------------------------------------------
void sub_1131F0(int a1, int a2)
{
  int v2; // eax
  unsigned int v3; // eax
  int v4; // [esp+0h] [ebp-20h]
  int v5; // [esp+8h] [ebp-18h]
  int i; // [esp+Ch] [ebp-14h]
  int v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+10h] [ebp-10h]
  int v9; // [esp+14h] [ebp-Ch]
  int v10; // [esp+18h] [ebp-8h]
  bool v11; // [esp+1Ch] [ebp-4h]

  if ( dword_184380 )
  {
    for ( i = 1; i < 16; ++i )
    {
      if ( dword_1B06B4[i] && sub_1128EA(i) )
      {
        v5 = sub_11299D(i) - dword_1B06B4[i] <= 0 ? 0 : sub_11299D(i) - dword_1B06B4[i];
        a2 = v5;
        sub_1129FA(i, v5);
        if ( !v5 )
        {
          sub_1127A3(i);
          dword_1B06B4[i] = 0;
        }
      }
    }
    if ( dword_184437 && dword_18442B )
    {
      if ( dword_1843AB )
      {
        a2 = sub_113B56() + dword_18444F;
        v7 = a2;
        if ( a2 >= dword_18444B )
        {
          v7 = dword_18444B;
          dword_1843AB = 0;
        }
        sub_113AF2(v7);
      }
      sub_1413FF(dword_18442B);
      v11 = v2 == 2;
      sub_141A76((_DWORD *)dword_18442B);
      v10 = v3;
      if ( v3 == -1 )
      {
        if ( v11 )
        {
          v8 = sub_113B56();
          sub_1410E0(dword_18442B);
          dword_184437 = 0;
          fclose(dword_18442F);
          dword_18442F = 0;
          dword_18442B = 0;
          dword_184447 = 0;
          dword_18444F = -1;
          if ( dword_18443B )
          {
            if ( dword_184443 >= 1 )
              sub_113765(dword_184443, v8);
            else
              sub_113475(byte_1AE054, a2);
            if ( dword_18443B > 0 )
              --dword_18443B;
          }
        }
      }
      else
      {
        if ( v3 > 1 )
          sub_126487(aAilError, a2);
        if ( dword_18443F <= dword_184433 )
          v4 = dword_18443F;
        else
          v4 = dword_184433;
        v9 = fread(dword_1AE0A4[v3], 1, v4, dword_18442F);
        dword_18443F -= v9;
        sub_141B5B((int *)dword_18442B, v10, dword_1AE0A4[v10], v9);
      }
    }
  }
}
// 113314: variable 'v2' is possibly undefined
// 11333A: variable 'v3' is possibly undefined
// 113765: using guessed type int sub_113765(_DWORD, _DWORD);
// 12697A: using guessed type int fclose(_DWORD);
// 1288DB: using guessed type int fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 184380: using guessed type int dword_184380;
// 1843AB: using guessed type int dword_1843AB;
// 18442B: using guessed type int dword_18442B;
// 18442F: using guessed type int dword_18442F;
// 184433: using guessed type int dword_184433;
// 184437: using guessed type int dword_184437;
// 18443B: using guessed type int dword_18443B;
// 18443F: using guessed type int dword_18443F;
// 184443: using guessed type int dword_184443;
// 184447: using guessed type int dword_184447;
// 18444B: using guessed type int dword_18444B;
// 18444F: using guessed type int dword_18444F;
// 1AE0A4: using guessed type int dword_1AE0A4[];
// 1B06B4: using guessed type int dword_1B06B4[17];


//----- (00113475) --------------------------------------------------------
int sub_113475(char *a1, int a2)
{
  int v2; // eax
  char v4[80]; // [esp+0h] [ebp-60h] BYREF
  char *v5; // [esp+50h] [ebp-10h]
  int v6; // [esp+58h] [ebp-8h]

  v5 = a1;
  if ( !dword_184380 || !dword_184453 )
    return 0;
  v6 = sub_111AE2();
  if ( !v6 )
    return 0;
  if ( !dword_184427 )
  {
    sub_14197D((_DWORD *)dword_184388, 22050, 2);
    dword_184433 = 32 * v2;
    dword_1AE0A4[0] = nmalloc(32 * v2);
    dword_1AE0A8 = nmalloc(dword_184433);
    if ( !dword_1AE0A4 || !dword_1AE0A8 )
      sub_126487(aOutOfMemory, a2);
    dword_184427 = 1;
  }
  if ( dword_18442B )
    sub_1410E0(dword_18442B);
  if ( dword_18442F && dword_184443 < 1 )
    fclose(dword_18442F);
  dword_18443F = 0;
  dword_184443 = -1;
  memset(dword_1AE0A4, 0, dword_184433);
  memset(dword_1AE0A8, 0, dword_184433);
  if ( sub_11181C((int)v5) )
  {
    dword_18442F = fopen(v5, aRb_2);
  }
  else
  {
    strcpy(v4, byte_184544);
    strcat(v4, v5);
    if ( !sub_11181C((int)v4) )
      return 0;
    dword_18442F = fopen(v4, aRb_2);
  }
  if ( !dword_18442F )
  {
    sprintf(v4, "\nError opening %s\n", v5);
    sub_126487(v4, (int)aRb_2);
  }
  fread(dword_1AE0A4, 1, 44, dword_18442F);
  dword_18443F = *(_DWORD *)(dword_1AE0A4 + 40);
  if ( !dword_18442F )
    return 0;
  strcpy(&unk_1AE054, v5);
  dword_184437 = 1;
  dword_18442B = dword_1B0670[v6];
  sub_140DFC((int *)dword_18442B);
  sub_140FF1(dword_18442B, 2, 0);
  sub_141227(dword_18442B, 22050);
  ((void (*)())(void*)sub_1131F0)();
  return v6;
}
// 1134DF: variable 'v2' is possibly undefined
// 1131F0: using guessed type int sub_1131F0(void);
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 12685D: using guessed type int fopen(_DWORD, _DWORD);
// 12697A: using guessed type int fclose(_DWORD);
// 1288DB: using guessed type int fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 13CB78: using guessed type int nmalloc(_DWORD);
// 13F220: using guessed type int strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184380: using guessed type int dword_184380;
// 184388: using guessed type int dword_184388;
// 184427: using guessed type int dword_184427;
// 18442B: using guessed type int dword_18442B;
// 18442F: using guessed type int dword_18442F;
// 184433: using guessed type int dword_184433;
// 184437: using guessed type int dword_184437;
// 18443F: using guessed type int dword_18443F;
// 184443: using guessed type int dword_184443;
// 184453: using guessed type int dword_184453;
// 1AE0A4: using guessed type int dword_1AE0A4;
// 1AE0A8: using guessed type int dword_1AE0A8;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (001136CA) --------------------------------------------------------
int sub_1136CA(int result)
{
  dword_18443B = result;
  return result;
}
// 18443B: using guessed type int dword_18443B;


//----- (001136EC) --------------------------------------------------------
int sub_1136EC(_BYTE *a1)
{
  unsigned int i; // [esp+4h] [ebp-4h]

  if ( *a1 )
    strcpy(aStreamLbx_0, a1);
  for ( i = 0; strlen(a1) > i; ++i )
  {
    if ( a1[i] == 46 )
    {
      a1[i] = 0;
      return strcat(a1, aLbx);
    }
  }
  return strcat(a1, aLbx);
}
// 13F220: using guessed type int strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 14432F: using guessed type int strlen(_DWORD);


//----- (00113765) --------------------------------------------------------
int sub_113765(int a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int v5; // [esp+0h] [ebp-68h]
  _BYTE v6[80]; // [esp+4h] [ebp-64h] BYREF
  int v7; // [esp+54h] [ebp-14h]
  int v8; // [esp+58h] [ebp-10h]
  int v9; // [esp+60h] [ebp-8h]

  v8 = a1;
  v7 = a2;
  if ( a1 < 1 || !dword_184453 || !dword_184380 )
    return 0;
  v9 = sub_111AE2();
  if ( !v9 )
    return 0;
  if ( !dword_184427 )
  {
    v5 = 16;
    dword_1AE0A4[0] = 0;
    dword_1AE0A8 = 0;
    while ( v5 && (!dword_1AE0A4[0] || !dword_1AE0A8) )
    {
      sub_14197D((_DWORD *)dword_184388, 22050, 2);
      a2 = v2 * v5;
      dword_184433 = v2 * v5;
      dword_1AE0A4[0] = nmalloc(v2 * v5);
      dword_1AE0A8 = nmalloc(dword_184433);
      v5 -= 2;
    }
    if ( !dword_1AE0A4[0] || !dword_1AE0A8 )
      sub_126487(aOutOfMemory, a2);
    dword_184427 = 1;
  }
  if ( dword_18442B )
    sub_1410E0(dword_18442B);
  if ( dword_18442F )
    fclose(dword_18442F);
  dword_18443F = 0;
  dword_184443 = v8;
  memset(dword_1AE0A4[0], 0, dword_184433);
  memset(dword_1AE0A8, 0, dword_184433);
  if ( sub_11181C((int)aStreamLbx_0) )
  {
    dword_18442F = fopen(aStreamLbx_0, aRb_2);
  }
  else
  {
    strcpy(v6, byte_184544);
    strcat(v6, aStreamLbx_0);
    if ( !sub_11181C((int)v6) )
      return 0;
    dword_18442F = fopen(v6, aRb_2);
  }
  if ( !dword_18442F )
    return 0;
  fread(&unk_1AD854, 2048, 1, dword_18442F);
  // DECOMP_TODO - NEJISTE (vlna 07): fseek() melo 0 parametru. Na rozdil
  // od podobnych pripadu v orion_part_19/20.c (jasny LBX "table[idx]"
  // vzor) tu zadna offset-tabulka neni pouzita pred timto seekem - jen
  // primy prechod z 2048bajtoveho header cteni na 44bajtove cteni.
  // Soubor je po fread() jiz presne na pozici 2048 (kam by SEEK_SET s
  // offsetem 2048 i tak smeroval), takze jako bezpecny, chovani-zachovavajici
  // placeholder pouzito "seek na aktualni pozici" (SEEK_CUR, 0) - funkcne
  // no-op, nez se najde duvod pro jiny cil.
  fseek(dword_18442F, 0, SEEK_CUR);
  fread(dword_1AE0A4[0], 1, 44, dword_18442F);
  dword_18443F = *(_DWORD *)(dword_1AE0A4[0] + 40);
  strcpy(byte_1AE054, aStreamLbx_0);
  dword_184437 = 1;
  dword_18442B = dword_1B0670[v9];
  dword_184447 = v9;
  sub_140DFC((int *)dword_18442B);
  sub_140FF1(dword_18442B, 2, 0);
  sub_141227(dword_18442B, 22050);
  sub_113AF2(v7);
  sub_1131F0(v3, (int)aStreamLbx_0);
  return v9;
}
// 113814: variable 'v2' is possibly undefined
// 113A0A: variable 'v3' is possibly undefined
// 12685D: using guessed type int fopen(_DWORD, _DWORD);
// 12697A: using guessed type int fclose(_DWORD);
// 1288DB: using guessed type int fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 13CB78: using guessed type int nmalloc(_DWORD);
// 13F220: using guessed type int strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184380: using guessed type int dword_184380;
// 184388: using guessed type int dword_184388;
// 184427: using guessed type int dword_184427;
// 18442B: using guessed type int dword_18442B;
// 18442F: using guessed type int dword_18442F;
// 184433: using guessed type int dword_184433;
// 184437: using guessed type int dword_184437;
// 18443F: using guessed type int dword_18443F;
// 184443: using guessed type int dword_184443;
// 184447: using guessed type int dword_184447;
// 184453: using guessed type int dword_184453;
// 1AE0A4: using guessed type int dword_1AE0A4[];
// 1AE0A8: using guessed type int dword_1AE0A8;
// 1B0670: using guessed type int dword_1B0670[17];


//----- (00113A20) --------------------------------------------------------
int sub_113A20(int a1)
{
  return sub_113765(a1, dword_18444B);
}
// 18444B: using guessed type int dword_18444B;


//----- (00113A4E) --------------------------------------------------------
int sub_113A4E()
{
  int result=0; // eax

  if ( dword_184380 && dword_18442B )
  {
    sub_1410E0(dword_18442B);
    result = 4 * dword_184447;
    dword_1B06B4[dword_184447] = 0;
    dword_184437 = 0;
    if ( dword_18442F )
      result = fclose(dword_18442F);
    dword_18442F = 0;
    dword_18442B = 0;
    dword_184447 = 0;
    dword_18444F = -1;
    dword_18443B = 0;
    dword_1843AB = 0;
  }
  return result;
}
// 12697A: using guessed type int fclose(_DWORD);
// 184380: using guessed type int dword_184380;
// 1843AB: using guessed type int dword_1843AB;
// 18442B: using guessed type int dword_18442B;
// 18442F: using guessed type int dword_18442F;
// 184437: using guessed type int dword_184437;
// 18443B: using guessed type int dword_18443B;
// 184447: using guessed type int dword_184447;
// 18444F: using guessed type int dword_18444F;
// 1B06B4: using guessed type int dword_1B06B4[17];


//----- (00113AF2) --------------------------------------------------------
void sub_113AF2(int a1)
{
  int v1; // [esp+0h] [ebp-4h]
  int v2; // [esp+0h] [ebp-4h]

  v1 = a1;
  if ( dword_184380 )
  {
    if ( a1 > dword_18444B )
      v1 = dword_18444B;
    v2 = 127 * v1 / 100;
    if ( dword_18442B )
      sub_14129D(dword_18442B, v2);
  }
}
// 184380: using guessed type int dword_184380;
// 18442B: using guessed type int dword_18442B;
// 18444B: using guessed type int dword_18444B;


//----- (00113B56) --------------------------------------------------------
int sub_113B56()
{
  int v0; // eax

  if ( !dword_18442B )
    return 0;
  sub_1415D5(dword_18442B);
  return 100 * v0 / 127;
}
// 113B87: variable 'v0' is possibly undefined
// 18442B: using guessed type int dword_18442B;


//----- (00113BAC) --------------------------------------------------------
int sub_113BAC(int result)
{
  dword_18443B = result;
  return result;
}
// 18443B: using guessed type int dword_18443B;


//----- (00113BCE) --------------------------------------------------------
bool sub_113BCE()
{
  int v0; // eax
  int v2; // [esp+0h] [ebp-4h]

  if ( dword_184380 )
  {
    v2 = 0;
    if ( dword_18442B )
    {
      sub_1413FF(dword_18442B);
      if ( v0 == 4 )
        return 1;
    }
  }
  else
  {
    return 0;
  }
  return v2;
}
// 113C08: variable 'v0' is possibly undefined
// 184380: using guessed type int dword_184380;
// 18442B: using guessed type int dword_18442B;


//----- (00113C28) --------------------------------------------------------
int sub_113C28(int result)
{
  if ( dword_184380 )
  {
    if ( dword_184447 > 0 )
    {
      dword_1843AB = 0;
      return sub_112C96(dword_184447, result);
    }
  }
  return result;
}
// 184380: using guessed type int dword_184380;
// 1843AB: using guessed type int dword_1843AB;
// 184447: using guessed type int dword_184447;


//----- (00113C6B) --------------------------------------------------------
unsigned int sub_113C6B(unsigned int result)
{
  if ( result <= 0x64 )
    dword_18444B = result;
  return result;
}
// 18444B: using guessed type int dword_18444B;


//----- (00113C9B) --------------------------------------------------------
int sub_113C9B()
{
  return dword_18444B;
}
// 18444B: using guessed type int dword_18444B;


//----- (00113CBD) --------------------------------------------------------
int sub_113CBD(int result)
{
  dword_1B06B4[dword_184447] = 0;
  dword_18444F = result;
  dword_1843AB = 1;
  return result;
}
// 1843AB: using guessed type int dword_1843AB;
// 184447: using guessed type int dword_184447;
// 18444F: using guessed type int dword_18444F;
// 1B06B4: using guessed type int dword_1B06B4[17];


//----- (00113CFB) --------------------------------------------------------
void sub_113CFB()
{
  if ( dword_18439C )
    dword_184453 = 1;
}
// 18439C: using guessed type int dword_18439C;
// 184453: using guessed type int dword_184453;


//----- (00113D23) --------------------------------------------------------
int sub_113D23()
{
  int result; // eax

  result = sub_113A4E();
  dword_184453 = 0;
  return result;
}
// 184453: using guessed type int dword_184453;


//----- (00113D47) --------------------------------------------------------
void RunGameAndExit_113D47(int a1, _BYTE *a2) // vlna 13: __noreturn odebran, funkce se vraci
{
  int v2; // eax
  int16_t v3; // [esp+0h] [ebp-8h]

  v3 = a1;
  PortDebug_Checkpoint("RunGame.enter", a1);
  sub_113E08(a1, (int)a2);
  PortDebug_Checkpoint("RunGame.after_113E08", 0);
  sub_1248AB(v3);
  PortDebug_Checkpoint("RunGame.after_1248AB", 0);
  LOBYTE(v2) = sub_13372A();
  InstallKeyboardIsr_12C420(v2, (int16_t)a2);
  PortDebug_Checkpoint("RunGame.after_InstallKbd", 0);
  sub_117262();
  PortDebug_Checkpoint("RunGame.after_117262", 0);
  sub_111F3E();
  PortDebug_Checkpoint("RunGame.after_111F3E", 0);
  if ( *a2 )
    sub_120526((int)a2);
  else
    sub_144348((int)a2, (int)a2);
  PortDebug_Checkpoint("RunGame.after_mainloop", 0);
  sub_12D78E();
  atexit(sub_113DBD);
  CalibrateCpuTick_132AA4();
  // VLNA 13: nasledujici dve akce v dekompilatu CHYBELY - Hex-Rays je
  // zahodil jako nedosazitelne, protoze CalibrateCpuTick_132AA4 mylne oznacil za
  // __noreturn (selhana dekompilace, viz komentar u ni). Overeno
  // disassemblovanim originalu (DOSBox DUMPMEM, runtime 0x337D47):
  //   call 0x356AA4 (CalibrateCpuTick_132AA4)  ; kalibrace - VRACI SE
  //   call 0x347491 (sub_123491)  ; inicializace mysi (INT 33h)
  //   mov esp,ebp; pop ...; ret   ; normalni navrat!
  PortDebug_Checkpoint("RunGame.before_MouseInit", 0);
  sub_123491();
  PortDebug_Checkpoint("RunGame.after_MouseInit", 0);
}
// 113D76: variable 'v2' is possibly undefined
// 144906: using guessed type int atexit(_DWORD);


//----- (00113DBD) --------------------------------------------------------
int sub_113DBD()
{
  int result; // eax

  if ( !dword_184460 )
  {
    sub_123DD9();
    sub_124ACE();
    RestoreKeyboardIsr_12C493();
    sub_11215B();
    result = sub_139062();
  }
  dword_184460 = 1;
  return result;
}
// 184460: using guessed type int dword_184460;


//----- (00113E08) --------------------------------------------------------
int sub_113E08(int a1, int a2)
{
  int result; // eax

  dword_1B06F8 = (unsigned int)sub_110C62(0x2000, a2) >> 4;
  dword_1B06FC = 16 * dword_1B06F8;
  word_1B0700 = dword_1B06F8;
  result = 16 * dword_1B06F8;
  sub_127678((char *)(16 * dword_1B06F8), 0x2000u, 0);
  return result;
}
// 1B06F8: using guessed type int dword_1B06F8;
// 1B06FC: using guessed type int dword_1B06FC;
// 1B0700: using guessed type int16_t word_1B0700;


//----- (00113E65) --------------------------------------------------------
int16_t sub_113E65()
{
  return word_1B3E0E;
}
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (00113E92) --------------------------------------------------------
void sub_113E92()
{
  word_1844B0 = 1;
}
// 1844B0: using guessed type int16_t word_1844B0;


//----- (00113EE2) --------------------------------------------------------
void sub_113EE2()
{
  LOWORD(off_1844B2) = 1;
}
// 1844B2: using guessed type _UNKNOWN *off_1844B2;


//----- (00113F0A) --------------------------------------------------------
void sub_113F0A()
{
  LOWORD(off_1844B2) = 0;
}
// 1844B2: using guessed type _UNKNOWN *off_1844B2;


//----- (00113F32) --------------------------------------------------------
int16_t sub_113F32()
{
  return word_1844DE;
}
// 1844DE: using guessed type int16_t word_1844DE;


//----- (00113F5F) --------------------------------------------------------
int16_t sub_113F5F()
{
  return word_1844E0;
}
// 1844E0: using guessed type int16_t word_1844E0;


//----- (00113F8C) --------------------------------------------------------
int16_t sub_113F8C()
{
  return word_1844A6;
}
// 1844A6: using guessed type int16_t word_1844A6;


//----- (00113FB9) --------------------------------------------------------
int sub_113FB9()
{
  int v1; // [esp+4h] [ebp-2Ch]
  int v2; // [esp+8h] [ebp-28h]
  int16_t v3; // [esp+Ch] [ebp-24h]
  int16_t v4; // [esp+10h] [ebp-20h]
  int i; // [esp+14h] [ebp-1Ch]
  int v6; // [esp+18h] [ebp-18h]

  v3 = sub_123ABA();
  v4 = sub_123AE7();
  v6 = 0;
  sub_123EA7();
  LOWORD(dword_1B3E14) = sub_123FFB();
  for ( i = 1; (int16_t)i < word_1B3E0E; ++i )
  {
    if ( (*(int *)((char *)&dword_1B3E10 + 2) >> 16) + v3 >= *(int16_t *)((char *)off_184480 + 55 * (int16_t)i)
      && (*(int *)((char *)&dword_1B3E10 + 2) >> 16) + v3 <= *(int16_t *)((char *)off_184480 + 55 * (int16_t)i + 4)
      && (*(int *)((char *)&dword_1B3E10 + 2) >> 16) + v4 >= *(int16_t *)((char *)off_184480 + 55 * (int16_t)i + 2)
      && (*(int *)((char *)&dword_1B3E10 + 2) >> 16) + v4 <= *(int16_t *)((char *)off_184480 + 55 * (int16_t)i + 6) )
    {
      if ( *(int *)((char *)off_184480 + 55 * (int16_t)i + 6) >> 16 != 14 )
        return i;
      v2 = v3 - (*(int *)((char *)off_184480 + 55 * (int16_t)i + 22) >> 16);
      v1 = v4 - (*(int *)((char *)off_184480 + 55 * (int16_t)i + 26) >> 16);
      if ( v1 * v1 + v2 * v2 <= *(_DWORD *)((char *)off_184480 + 55 * (int16_t)i + 32) )
        return i;
    }
  }
  return v6;
}
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1B3E10: using guessed type int dword_1B3E10;
// 1B3E14: using guessed type int dword_1B3E14;


//----- (00114177) --------------------------------------------------------
char *sub_114177()
{
  char *v0; // eax
  int v1; // ebx
  int v2; // edx
  int v4; // [esp+Ch] [ebp-18h]

  sub_123ABA();
  sub_123AE7();
  sub_123EA7();
  LOWORD(dword_1B3E14) = sub_123FFB();
  v4 = sub_113FB9();
  if ( *(int *)((char *)off_184480 + 55 * (int16_t)v4 + 6) >> 16 == 9 )
  {
    **(_WORD **)((char *)off_184480 + 55 * (int16_t)v4 + 32) = *(_WORD *)((char *)off_184480 + 55 * (int16_t)v4 + 28);
    v0 = (char *)off_184480 + 55 * (int16_t)v4;
    LOWORD(v0) = *((_WORD *)v0 + 12);
    return v0;
  }
  else if ( *(int *)((char *)off_184480 + 55 * (int16_t)v4 + 6) >> 16 != 10
         || *(_WORD *)((char *)off_184480 + 55 * (int16_t)v4 + 18) )
  {
    if ( *(int *)((char *)off_184480 + 55 * (int16_t)v4 + 6) >> 16 == 12
      && (dword_18448E >> 16 == -1 || *(int *)((char *)off_184480 + 55 * (dword_18448E >> 16) + 6) >> 16 != 12) )
    {
      v1 = *(int16_t *)((char *)off_184480 + 55 * (int16_t)v4);
      **(_WORD **)((char *)off_184480 + 55 * (int16_t)v4 + 36) = (sub_123ABA() - v1)
                                                               / (*(int *)((char *)off_184480 + 55 * (int16_t)v4 + 26) >> 16);
      v2 = *(int *)((char *)off_184480 + 55 * (int16_t)v4) >> 16;
      **(_WORD **)((char *)off_184480 + 55 * (int16_t)v4 + 40) = (sub_123AE7() - v2)
                                                               / (*(int *)((char *)off_184480 + 55 * (int16_t)v4 + 30) >> 16);
    }
    return (char *)v4;
  }
  else
  {
    return 0;
  }
}
// 184480: using guessed type _UNKNOWN *off_184480;
// 18448E: using guessed type int dword_18448E;
// 1B3E14: using guessed type int dword_1B3E14;


//----- (0011438B) --------------------------------------------------------
unsigned int sub_11438B( int a1, int a2, int a3, int a4, _BYTE *a5, int a6)
{
  unsigned int v6; // eax

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, a2);
  if ( a1 > a3 || a2 > a4 )
    sub_126487(aErrorBadRectIn, a2);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = a2;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = a3;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = a4;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 8) = 7;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 53) = a6;
  *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) = *a5;
  HIWORD(v6) = HIWORD(off_184480);
  if ( *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) > 0x60u )
  {
    v6 = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
    if ( v6 < 0x7B )
    {
      v6 = (unsigned int)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
      *(_BYTE *)(v6 + 52) -= 32;
    }
  }
  LOWORD(v6) = ++word_1B3E0E;
  return v6 - 1;
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (001146FD) --------------------------------------------------------
int sub_1146FD( int a1, int a2, int a3, _BYTE *a4, int a5)
{
  int v5; // edx
  unsigned int v6; // eax
  int v8; // [esp+0h] [ebp-24h]
  int v9; // [esp+4h] [ebp-20h]
  int v10; // [esp+10h] [ebp-14h]

  v8 = a1 - a3;
  v9 = a3 + a1;
  v10 = a2 - a3;
  v5 = a3 + a2;
  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, v5);
  if ( dword_1BBA4A >> 16 > v9 || *(int *)((char *)&dword_1BBA4A + 2) >> 16 < v8 )
    return -10000;
  if ( dword_1BBA4E >> 16 > v5 || *(int *)((char *)&dword_1BBA4E + 2) >> 16 < v10 )
    return -10000;
  if ( dword_1BBA4A >> 16 > v8 )
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = HIWORD(dword_1BBA4A);
  else
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = v8;
  if ( *(int *)((char *)&dword_1BBA4A + 2) >> 16 < v9 )
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = dword_1BBA4E;
  else
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = v9;
  if ( dword_1BBA4E >> 16 > v10 )
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = HIWORD(dword_1BBA4E);
  else
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = v10;
  if ( *(int *)((char *)&dword_1BBA4E + 2) >> 16 < v5 )
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = dword_1BBA52;
  else
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = v5;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 24) = a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 28) = a2;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 32) = a3 * a3;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 8) = 14;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 53) = a5;
  *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) = *a4;
  v6 = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
  if ( v6 > 0x60 )
  {
    v6 = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
    if ( v6 < 0x7B )
    {
      v6 = (unsigned int)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
      *(_BYTE *)(v6 + 52) -= 32;
    }
  }
  LOWORD(v6) = ++word_1B3E0E;
  return v6 - 1;
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00114A00) --------------------------------------------------------
int sub_114A00( int a1, int a2, int a3, int a4, _BYTE *a5, int a6)
{
  unsigned int v6; // eax

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, a2);
  if ( a3 < SHIWORD(dword_1BBA4A) || a1 > (int16_t)dword_1BBA4E )
    return -10000;
  if ( a4 < SHIWORD(dword_1BBA4E) || a2 > (int16_t)dword_1BBA52 )
    return -10000;
  if ( a1 < SHIWORD(dword_1BBA4A) )
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = HIWORD(dword_1BBA4A);
  else
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = a1;
  if ( a3 > (int16_t)dword_1BBA4E )
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = dword_1BBA4E;
  else
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = a3;
  if ( a2 < SHIWORD(dword_1BBA4E) )
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = HIWORD(dword_1BBA4E);
  else
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = a2;
  if ( a4 > (int16_t)dword_1BBA52 )
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = dword_1BBA52;
  else
    *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = a4;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 8) = 7;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 53) = a6;
  *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) = *a5;
  v6 = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
  if ( v6 > 0x60 )
  {
    v6 = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
    if ( v6 < 0x7B )
    {
      v6 = (unsigned int)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
      *(_BYTE *)(v6 + 52) -= 32;
    }
  }
  LOWORD(v6) = ++word_1B3E0E;
  return v6 - 1;
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00114C72) --------------------------------------------------------
unsigned int sub_114C72(_BYTE *a1, int a2)
{
  unsigned int v2; // eax

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, a2);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = 5000;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = 5000;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = 5000;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = 5000;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 8) = 7;
  *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) = *a1;
  v2 = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
  if ( v2 > 0x60 )
  {
    v2 = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
    if ( v2 < 0x7B )
    {
      v2 = (unsigned int)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
      *(_BYTE *)(v2 + 52) -= 32;
    }
  }
  LOWORD(v2) = ++word_1B3E0E;
  return v2 - 1;
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (00114DCA) --------------------------------------------------------
unsigned int sub_114DCA( int a1, int a2, int a3, int a4, int a5, int a6,
        int64_t a7, int a8)
{
  unsigned int v8; // eax

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, a2);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = a2;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = a1 + a5 * a3 - 1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = a2 + a6 * a4 - 1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 53) = a8;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 8) = 12;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 28) = a3;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 32) = a4;
  *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) = 0;
  *(_QWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 36) = a7;
  v8 = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
  if ( v8 > 0x60 )
  {
    v8 = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
    if ( v8 < 0x7B )
    {
      v8 = (unsigned int)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
      *(_BYTE *)(v8 + 52) -= 32;
    }
  }
  LOWORD(v8) = ++word_1B3E0E;
  return v8 - 1;
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (00114FBA) --------------------------------------------------------
unsigned int sub_114FBA( int a1, int a2, int a3, _WORD *a4, _BYTE *a5, int a6)
{
  unsigned int result; // eax

  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = a2;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 24) = a3;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = *a4
                                                                                        + *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16))
                                                                                        - 1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = a4[1]
                                                                                        + *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2)
                                                                                        - 1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 10) = sub_122201();
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 12) = sub_12222E();
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 53) = a6;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 44) = a4;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 36) = sub_12B6D4((int)a4);
  *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) = *a5;
  result = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
  if ( result > 0x60 )
  {
    result = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
    if ( result < 0x7B )
    {
      result = (unsigned int)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
      *(_BYTE *)(result + 52) -= 32;
    }
  }
  return result;
}
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;


//----- (001151B0) --------------------------------------------------------
char *sub_1151B0( int a1, int a2, int a3, _WORD *a4, _BYTE *a5, int a6)
{
  char *v6; // eax

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, a2);
  sub_114FBA(a1, a2, a3, a4, a5, a6);
  v6 = (char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
  *((_WORD *)v6 + 4) = 0;
  LOWORD(v6) = ++word_1B3E0E;
  return v6 - 1;
}
// 1151B0: could not find valid save-restore pair for ebx
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (0011523B) --------------------------------------------------------
int sub_11523B( int a1, int a2, int a3, _WORD *a4, int a5, _BYTE *a6, int a7)
{
  int v7; // eax

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, a2);
  sub_114FBA(a1, a2, a3, a4, a6, a7);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 8) = 1;
  HIWORD(v7) = HIWORD(a5);
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 32) = a5;
  LOWORD(v7) = ++word_1B3E0E;
  return v7 - 1;
}
// 11523B: could not find valid save-restore pair for ebx
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (001152DF) --------------------------------------------------------
int sub_1152DF( int a1, int a2, int a3, _WORD *a4, int a5, _BYTE *a6, int a7)
{
  int v7; // eax

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, a2);
  sub_114FBA(a1, a2, a3, a4, a6, a7);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 8) = 2;
  HIWORD(v7) = HIWORD(a5);
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 32) = a5;
  LOWORD(v7) = ++word_1B3E0E;
  return v7 - 1;
}
// 1152DF: could not find valid save-restore pair for ebx
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (00115383) --------------------------------------------------------
int sub_115383( int a1, int a2, int a3, _WORD *a4, int a5, int a6, _BYTE *a7, int a8)
{
  int v8; // eax

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, a2);
  sub_114FBA(a1, a2, a3, a4, a7, a8);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 8) = 3;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 32) = a5;
  HIWORD(v8) = HIWORD(a6);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 28) = a6;
  LOWORD(v8) = ++word_1B3E0E;
  return v8 - 1;
}
// 115383: could not find valid save-restore pair for ebx
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (00115478) --------------------------------------------------------
unsigned int sub_115478( int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8,
        int a9,
        _BYTE *a10, int a11)
{
  unsigned int v11; // eax

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, a2);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = a2;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = a7
                                                                                        + *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16));
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = a8
                                                                                        + *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 24) = a5;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 28) = a6;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 36) = a3;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 40) = a4;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 53) = a11;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 44) = a7 <= a8;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 8) = 6;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 32) = a9;
  *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) = *a10;
  v11 = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
  if ( v11 > 0x60 )
  {
    v11 = *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52);
    if ( v11 < 0x7B )
    {
      v11 = (unsigned int)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
      *(_BYTE *)(v11 + 52) -= 32;
    }
  }
  LOWORD(v11) = ++word_1B3E0E;
  return v11 - 1;
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (001156E2) --------------------------------------------------------
int sub_1156E2( int a1)
{
  char *v1; // eax
  char *v2; // eax
  int16_t v3; // ax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  int result; // eax
  int16_t v9; // [esp+4h] [ebp-10h]
  int v11; // [esp+Ch] [ebp-8h]
  int16_t v12; // [esp+10h] [ebp-4h]
  int16_t v13; // [esp+10h] [ebp-4h]

  if ( *(_WORD *)((char *)off_184480 + 55 * a1 + 44) )
  {
    v13 = *(_WORD *)((char *)off_184480 + 55 * a1 + 6) - *(_WORD *)((char *)off_184480 + 55 * a1 + 2);
    v3 = sub_123AE7();
    if ( (int16_t)(v3 + dword_1B3E14) < *(int16_t *)((char *)off_184480 + 55 * a1 + 6) )
    {
      if ( (int16_t)(v3 + dword_1B3E14) > *(int16_t *)((char *)off_184480 + 55 * a1 + 2) )
      {
        v11 = ((*(int *)((char *)off_184480 + 55 * a1 + 38) >> 16) - (*(int *)((char *)off_184480 + 55 * a1 + 34) >> 16))
            * ((*(int *)((char *)off_184480 + 55 * a1 + 4) >> 16) - (int16_t)(v3 + dword_1B3E14))
            / v13;
      }
      else
      {
        v5 = (char *)off_184480 + 55 * a1;
        LOWORD(v5) = *((_WORD *)v5 + 20);
        v11 = (int)v5;
      }
    }
    else
    {
      v4 = (char *)off_184480 + 55 * a1;
      LOWORD(v4) = *((_WORD *)v4 + 18);
      v11 = (int)v4;
    }
  }
  else
  {
    v12 = *(_WORD *)((char *)off_184480 + 55 * a1 + 4) - *(_WORD *)((char *)off_184480 + 55 * a1);
    v9 = sub_123ABA() + dword_1B3E14;
    if ( v9 < *(int16_t *)((char *)off_184480 + 55 * a1 + 4) )
    {
      v2 = (char *)off_184480 + 55 * a1;
      LOWORD(v2) = *((_WORD *)v2 + 18);
      if ( v9 > *(int16_t *)((char *)off_184480 + 55 * a1) )
        v2 += ((*(int *)((char *)off_184480 + 55 * a1 + 38) >> 16) - (*(int *)((char *)off_184480 + 55 * a1 + 34) >> 16))
            * (v9 - *(int16_t *)((char *)off_184480 + 55 * a1))
            / v12;
      v11 = (int)v2;
    }
    else
    {
      v1 = (char *)off_184480 + 55 * a1;
      LOWORD(v1) = *((_WORD *)v1 + 20);
      v11 = (int)v1;
    }
  }
  if ( (int16_t)v11 < *(int16_t *)((char *)off_184480 + 55 * a1 + 24) )
  {
    v6 = (char *)off_184480 + 55 * a1;
    LOWORD(v6) = *((_WORD *)v6 + 12);
    v11 = (int)v6;
  }
  if ( (int16_t)v11 > *(int16_t *)((char *)off_184480 + 55 * a1 + 28) )
  {
    v7 = (char *)off_184480 + 55 * a1;
    LOWORD(v7) = *((_WORD *)v7 + 14);
    v11 = (int)v7;
  }
  result = v11;
  **(_WORD **)((char *)off_184480 + 55 * a1 + 32) = v11;
  return result;
}
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E14: using guessed type int dword_1B3E14;


//----- (00115994) --------------------------------------------------------
char *sub_115994( int a1)
{
  char *v1; // eax
  char *v2; // eax
  char *result; // eax
  int v4; // [esp+4h] [ebp-10h]
  char *v6; // [esp+Ch] [ebp-8h]
  int16_t v7; // [esp+10h] [ebp-4h]

  v7 = *(_WORD *)((char *)off_184480 + 55 * a1 + 40) - *(_WORD *)((char *)off_184480 + 55 * a1 + 36);
  v4 = 100
     * (**(int16_t **)((char *)off_184480 + 55 * a1 + 32) - (*(int *)((char *)off_184480 + 55 * a1 + 34) >> 16))
     / v7
     + 5;
  v1 = (char *)off_184480 + 55 * a1;
  if ( (int16_t)v4 <= 100 )
  {
    LOWORD(v1) = *((_WORD *)v1 + 18);
    v1 += v7 * (int16_t)v4 / 100;
  }
  else
  {
    LOWORD(v1) = *((_WORD *)v1 + 14);
  }
  v6 = v1;
  if ( (int16_t)v1 > *(int16_t *)((char *)off_184480 + 55 * a1 + 28) )
  {
    v2 = (char *)off_184480 + 55 * a1;
    LOWORD(v2) = *((_WORD *)v2 + 14);
    v6 = v2;
  }
  result = v6;
  **(_WORD **)((char *)off_184480 + 55 * a1 + 32) = (_WORD)v6;
  return result;
}
// 184480: using guessed type _UNKNOWN *off_184480;


//----- (00115AC0) --------------------------------------------------------
char *sub_115AC0( int a1)
{
  char *v1; // eax
  char *v2; // eax
  char *result; // eax
  int16_t v4; // [esp+4h] [ebp-10h]
  char *v6; // [esp+Ch] [ebp-8h]
  int16_t v7; // [esp+10h] [ebp-4h]

  v7 = *(_WORD *)((char *)off_184480 + 55 * a1 + 40) - *(_WORD *)((char *)off_184480 + 55 * a1 + 36);
  v4 = 100
     * (**(int16_t **)((char *)off_184480 + 55 * a1 + 32) - (*(int *)((char *)off_184480 + 55 * a1 + 34) >> 16))
     / v7
     - 5;
  v1 = (char *)off_184480 + 55 * a1;
  if ( v4 >= 0 )
  {
    LOWORD(v1) = *((_WORD *)v1 + 18);
    v1 += v7 * v4 / 100;
  }
  else
  {
    LOWORD(v1) = *((_WORD *)v1 + 12);
  }
  v6 = v1;
  if ( (int16_t)v1 < *(int16_t *)((char *)off_184480 + 55 * a1 + 24) )
  {
    v2 = (char *)off_184480 + 55 * a1;
    LOWORD(v2) = *((_WORD *)v2 + 12);
    v6 = v2;
  }
  result = v6;
  **(_WORD **)((char *)off_184480 + 55 * a1 + 32) = (_WORD)v6;
  return result;
}
// 184480: using guessed type _UNKNOWN *off_184480;


//----- (00115BEA) --------------------------------------------------------
char *sub_115BEA( int a1, int a2, int a3, int a4,
        int a5, int a6, int a7,
        int a8, int a9, int a10)
{
  char *v10; // eax
  int i; // [esp+0h] [ebp-20h]
  char *v13; // [esp+4h] [ebp-1Ch]
  char *v14; // [esp+8h] [ebp-18h]

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, a2);
  v13 = sub_12222E();
  v14 = sub_12222E();
  for ( i = 0; i < 8; ++i )
  {
    byte_1B070C[i] = v13[i];
    byte_1B0704[i] = v14[i];
  }
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = a2;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 10) = sub_122201();
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 12) = byte_1B070C;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 20) = byte_1B0704;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = a3 + a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = a4 + a2;
  if ( a6 > 256 )
    a6 = 256;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 44) = a6;
  *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) = 0;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 53) = a9;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 24) = a5;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 36) = 0;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 28) = a8;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 32) = a7;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 48) = a10;
  v10 = (char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
  *((_WORD *)v10 + 4) = 11;
  LOWORD(v10) = ++word_1B3E0E;
  return v10 - 1;
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (00115E3B) --------------------------------------------------------
char *sub_115E3B( int a1, int a2, int a3,
        int a4, int a5, int a6, int a7, int a8,
        int a9,
        _BYTE *a10, int a11)
{
  char *v11; // eax

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, a2);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = a2;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 10) = sub_122201();
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 12) = sub_12222E();
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 20) = sub_12222E();
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = a3 + a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = sub_122259() + a2;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 44) = a5;
  *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) = *a10;
  if ( *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) > 0x60u
    && *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) < 0x7Bu )
  {
    *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) -= 32;
  }
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 53) = a11;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 24) = a4;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 32) = a6;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 36) = a7;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 40) = a8;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 48) = a9;
  v11 = (char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
  *((_WORD *)v11 + 4) = 4;
  LOWORD(v11) = ++word_1B3E0E;
  return v11 - 1;
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (001160AE) --------------------------------------------------------
int16_t sub_1160AE(int a1)
{
  char *v1; // eax
  _WORD *v2; // eax
  int16_t v3; // ax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int16_t v7; // ax
  int16_t v8; // ax
  int16_t v9; // ax
  int16_t result; // ax
  int v11; // [esp+0h] [ebp-74h]
  _BYTE v12[68]; // [esp+4h] [ebp-70h] BYREF
  int v13; // [esp+48h] [ebp-2Ch]
  int v14; // [esp+4Ch] [ebp-28h]
  char *v15; // [esp+50h] [ebp-24h]
  int v16; // [esp+54h] [ebp-20h]
  int v17; // [esp+58h] [ebp-1Ch]
  int v18; // [esp+5Ch] [ebp-18h]
  int v19; // [esp+60h] [ebp-14h]
  int i; // [esp+64h] [ebp-10h]
  int v21; // [esp+68h] [ebp-Ch]
  int v22; // [esp+6Ch] [ebp-8h]
  _WORD *v23; // [esp+70h] [ebp-4h]

  v17 = a1;
  v21 = 4;
  while ( sub_124075() )
    sub_1192D1();
  HIWORD(dword_1844C2) = 0;
  LOWORD(dword_1844C6) = 0;
  v1 = (char *)off_184480 + 55 * (int16_t)v17;
  LOWORD(v1) = *((_WORD *)v1 + 22);
  v15 = v1;
  v2 = (_WORD *)((char *)off_184480 + 55 * (int16_t)v17);
  LOWORD(v2) = v2[2] - *v2;
  v23 = v2;
  v16 = 0;
  sub_123A30();
  v13 = 0;
  v22 = 0;
  sub_120BB5(
    *(int *)((char *)off_184480 + 55 * (int16_t)v17 + 8) >> 16,
    *(_DWORD *)((char *)off_184480 + 55 * (int16_t)v17 + 12));
  strcpy(v12, *(_DWORD *)((char *)off_184480 + 55 * (int16_t)v17 + 24));
  while ( v12[(int16_t)v13] )
    ++v13;
  while ( 1 )
  {
    v3 = sub_12066F((int)v12);
    if ( v3 <= (int16_t)v23 || (int16_t)v13 <= 0 )
      break;
    v13 = 0;
    v12[0] = 0;
  }
  HIWORD(dword_1844C2) = v13;
  if ( (int16_t)v13 >= (int16_t)v15 )
    HIWORD(dword_1844C2) = (_WORD)v15;
  strcpy(*(_DWORD *)((char *)off_184480 + 55 * (int16_t)v17 + 24), v12);
  LOWORD(v4) = sub_122259();
  v18 = v4;
  sub_1166F5((int16_t)v17, (int)v12);
  v19 = 0;
  while ( (int16_t)v22 != 7181 && (int16_t)v22 != -8179 && !(_WORD)v19 )
  {
    v22 = 0;
    while ( !(_WORD)v22 )
    {
      if ( (_WORD)v19 )
        break;
      v22 = sub_12C5AE();
      if ( !(_WORD)v21 )
        break;
      if ( sub_124075() || (LOWORD(v5) = sub_123C48(), v5) )
      {
        v19 = 1;
        break;
      }
      LOWORD(dword_1844C6) = dword_1844C6 + 1;
      if ( *(int *)((char *)&dword_1844C2 + 2) >> 16 > 2 * (int16_t)v18 - 1 )
        LOWORD(dword_1844C6) = 0;
      sub_1166F5((int16_t)v17, (int)v12);
    }
    if ( !(_WORD)v21 || (_WORD)v19 )
      break;
    HIWORD(v6) = HIWORD(v22);
    v11 = v22;
    if ( (uint16_t)v22 < 0x4BE0u )
    {
      if ( (uint16_t)v11 < 0xE08u )
        goto LABEL_76;
      if ( (uint16_t)v11 > 0xE08u )
      {
        if ( (_WORD)v11 == 7181 )
          goto LABEL_105;
LABEL_76:
        v14 = 0;
        if ( (int16_t)v22 == 283 )
        {
          v19 = 2;
          v14 = 0;
        }
        else
        {
          v22 = (int16_t)v22 % 256;
          if ( (int16_t)v22 > 64 && (int16_t)v22 < 93
            || (int16_t)v22 > 45 && (int16_t)v22 < 59
            || (int16_t)v22 == 32
            || (int16_t)v22 == 45
            || (int16_t)v22 > 96 && (int16_t)v22 < 123 )
          {
            v14 = 1;
          }
        }
        if ( (int16_t)v14 == 1 )
        {
          v16 = 1;
          v12[(int16_t)v13] = v22;
          v12[(int16_t)v13 + 1] = 0;
          if ( (int16_t)v13 < (int16_t)v15 && (v8 = sub_12066F((int)v12), v8 <= (int16_t)v23) )
          {
            v12[(int16_t)v13] = 0;
            if ( SHIWORD(dword_1844C2) >= (int16_t)v13 )
            {
              v12[(int16_t)v13++] = v22;
              v12[(int16_t)v13] = 32;
              v12[(int16_t)v13 + 1] = 0;
              if ( (int16_t)v13 < (int16_t)v15 )
              {
                v9 = sub_12066F((int)v12);
                if ( v9 <= (int16_t)v23 )
                  ++HIWORD(dword_1844C2);
              }
              v12[(int16_t)v13] = 0;
              LOWORD(dword_1844C6) = 0;
            }
            else
            {
              for ( i = v13; (int16_t)i > SHIWORD(dword_1844C2); --i )
                v12[(int16_t)i] = v12[(int16_t)i - 1];
              ++v13;
              v12[dword_1844C2 >> 16] = v22;
              ++HIWORD(dword_1844C2);
              v12[(int16_t)v13] = 0;
              LOWORD(dword_1844C6) = 0;
            }
          }
          else
          {
            v12[(int16_t)v13] = 0;
          }
        }
        goto LABEL_105;
      }
      if ( (_WORD)v16 )
      {
        if ( (int16_t)v13 > 0 )
        {
          if ( SHIWORD(dword_1844C2) < (int16_t)v13 )
          {
            if ( SHIWORD(dword_1844C2) > 0 )
            {
              LOWORD(v6) = HIWORD(dword_1844C2);
              for ( i = v6; (int16_t)i < (int16_t)v13; ++i )
                v12[(int16_t)i - 1] = v12[(int16_t)i];
              --v13;
              --HIWORD(dword_1844C2);
              LOWORD(dword_1844C6) = 0;
              v12[(int16_t)v13] = 0;
            }
          }
          else
          {
            v12[(int16_t)--v13] = 0;
            --HIWORD(dword_1844C2);
            LOWORD(dword_1844C6) = 0;
          }
        }
      }
      else
      {
        v12[0] = 0;
        v13 = 0;
        HIWORD(dword_1844C2) = 0;
        LOWORD(dword_1844C6) = 0;
        v16 = 1;
      }
    }
    else if ( (uint16_t)v11 <= 0x4BE0u )
    {
      v16 = 1;
      if ( SHIWORD(dword_1844C2) > 0 )
      {
        --HIWORD(dword_1844C2);
        LOWORD(dword_1844C6) = 0;
      }
    }
    else if ( (uint16_t)v11 < 0x53E0u )
    {
      if ( (_WORD)v11 != 19936 )
        goto LABEL_76;
      if ( SHIWORD(dword_1844C2) < (int16_t)v15 && SHIWORD(dword_1844C2) < (int16_t)v13 )
      {
        ++HIWORD(dword_1844C2);
        LOWORD(dword_1844C6) = 0;
        if ( SHIWORD(dword_1844C2) >= (int16_t)v13 )
        {
          v12[(int16_t)v13] = 32;
          v12[(int16_t)v13 + 1] = 0;
          if ( SHIWORD(dword_1844C2) >= (int16_t)v15 || (v7 = sub_12066F((int)v12), v7 > (int16_t)v23) )
            --HIWORD(dword_1844C2);
          v12[(int16_t)v13] = 0;
        }
      }
    }
    else
    {
      if ( (uint16_t)v11 > 0x53E0u )
      {
        if ( (_WORD)v11 == 0xE00D )
          goto LABEL_105;
        goto LABEL_76;
      }
      if ( (int16_t)v13 > 0 && SHIWORD(dword_1844C2) < (int16_t)v13 )
      {
        LOWORD(v6) = HIWORD(dword_1844C2);
        for ( i = v6; (int16_t)i < (int16_t)v13; ++i )
          v12[(int16_t)i] = v12[(int16_t)i + 1];
        --v13;
        LOWORD(dword_1844C6) = 0;
        v12[(int16_t)v13] = 0;
      }
    }
LABEL_105:
    sub_1166F5((int16_t)v17, (int)v12);
  }
  strcpy(*(_DWORD *)((char *)off_184480 + 55 * (int16_t)v17 + 24), v12);
  if ( (_WORD)v19 )
  {
    while ( sub_124075() )
      ;
  }
  result = sub_123A64();
  HIWORD(dword_18448E) = -1;
  HIWORD(dword_1844C2) = 0;
  LOWORD(dword_1844C6) = 0;
  return result;
}
// 116202: variable 'v4' is possibly undefined
// 116273: variable 'v5' is possibly undefined
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184480: using guessed type _UNKNOWN *off_184480;
// 18448E: using guessed type int dword_18448E;
// 1844C2: using guessed type int dword_1844C2;
// 1844C6: using guessed type int dword_1844C6;


//----- (001166F5) --------------------------------------------------------
int sub_1166F5(int a1, int a2)
{
  _WORD *v2; // edx
  int v3; // eax
  int16_t v4; // ax
  _WORD *v5; // edx
  int v6; // eax
  int v7; // eax
  char *v8; // eax
  _WORD *v9; // edx
  int v10; // eax
  char *v11; // eax
  _BYTE v13[64]; // [esp+4h] [ebp-7Ch] BYREF
  _BYTE v14[16]; // [esp+44h] [ebp-3Ch] BYREF
  int v15; // [esp+54h] [ebp-2Ch]
  int v16; // [esp+58h] [ebp-28h]
  int v17; // [esp+5Ch] [ebp-24h]
  char *v18; // [esp+60h] [ebp-20h]
  int v19; // [esp+64h] [ebp-1Ch]
  char *v20; // [esp+68h] [ebp-18h]
  _WORD *v21; // [esp+6Ch] [ebp-14h]
  int v22; // [esp+70h] [ebp-10h]
  int v23; // [esp+74h] [ebp-Ch]
  _BYTE v24[4]; // [esp+78h] [ebp-8h] BYREF
  int v25; // [esp+7Ch] [ebp-4h]

  v19 = a1;
  v15 = a2;
  sub_12C2A0();
  sub_124D41();
  strcpy(v14, *(_DWORD *)((char *)off_184480 + 55 * (int16_t)v19 + 48));
  strcpy(v13, v15);
  sub_1192D1();
  v2 = (_WORD *)((char *)off_184480 + 55 * (int16_t)v19);
  LOWORD(v2) = v2[2] - *v2;
  v21 = v2;
  v17 = v19;
  sub_120BB5(
    *(int *)((char *)off_184480 + 55 * (int16_t)v19 + 8) >> 16,
    *(_DWORD *)((char *)off_184480 + 55 * (int16_t)v19 + 12));
  LOWORD(v3) = sub_122259();
  v25 = v3 - 1;
  if ( *(_WORD *)((char *)off_184480 + 55 * (int16_t)v17 + 32) )
    sub_128C32(
      (int16_t)(*(_WORD *)((char *)off_184480 + 55 * (int16_t)v17) - 1),
      *(int *)((char *)off_184480 + 55 * (int16_t)v17) >> 16,
      *(int *)((char *)off_184480 + 55 * (int16_t)v17 + 2) >> 16,
      *(int *)((char *)off_184480 + 55 * (int16_t)v17 + 4) >> 16,
      HIWORD(*(_DWORD *)((char *)off_184480 + 55 * (int16_t)v17 + 30)));
  v24[1] = 0;
  v4 = *(_WORD *)((char *)off_184480 + 55 * (int16_t)v17 + 40);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v24[0] = v13[dword_1844C2 >> 16];
      v13[dword_1844C2 >> 16] = 0;
      v9 = (_WORD *)((char *)off_184480 + 55 * (int16_t)v17);
      v10 = sub_12066F((int)v13);
      LOWORD(v9) = *v9;
      v18 = (char *)v9 + v10;
      v13[dword_1844C2 >> 16] = v24[0];
      if ( !v24[0] )
        v24[0] = 32;
      v23 = sub_12066F((int)v24);
      v22 = (*(int *)((char *)&dword_1844C2 + 2) >> 16) % 3;
      if ( (_WORD)v22 || HIWORD(dword_1844C6) )
      {
        if ( !(_WORD)v22 && dword_1844C6 >> 16 == 1 )
          HIWORD(dword_1844C6) = 0;
      }
      else
      {
        HIWORD(dword_1844C6) = 1;
      }
      v11 = (char *)off_184480 + 55 * (int16_t)v17;
      LOWORD(v11) = *((_WORD *)v11 + 1);
      v20 = &v11[v25];
      if ( HIWORD(dword_1844C6) )
        sub_134D2D(
          (int16_t)v18,
          (int16_t)((_WORD)v20 + 1),
          (int16_t)(v23 + (_WORD)v18 + 1),
          (int16_t)((_WORD)v20 + 1),
          v14[0]);
    }
  }
  else
  {
    v24[0] = v13[dword_1844C2 >> 16];
    v13[dword_1844C2 >> 16] = 0;
    v5 = (_WORD *)((char *)off_184480 + 55 * (int16_t)v17);
    v6 = sub_12066F((int)v13);
    LOWORD(v5) = *v5;
    v18 = (char *)v5 + v6;
    v13[dword_1844C2 >> 16] = v24[0];
    if ( !v24[0] )
      v24[0] = 32;
    v7 = sub_12066F((int)v24);
    v23 = v7;
    if ( (int16_t)dword_1844C6 > 0 && (int16_t)dword_1844C6 <= (int16_t)v25 )
    {
      LOWORD(v7) = dword_1844C6;
      v22 = v7;
      v8 = (char *)off_184480 + 55 * (int16_t)v17;
      LOWORD(v8) = *((_WORD *)v8 + 1);
      v20 = &v8[v25];
      v16 = 0;
      while ( (int16_t)v22 > 0 )
      {
        sub_134D2D(
          (int16_t)v18,
          (int16_t)((_WORD)v20 - v22 + 1),
          (int16_t)(v23 + (_WORD)v18 + 1),
          (int16_t)((_WORD)v20 - v22 + 1),
          (uint8_t)v14[(int16_t)v16++]);
        --v22;
      }
    }
    else if ( (_WORD)dword_1844C6 )
    {
      LOWORD(v7) = dword_1844C6;
      v22 = v25 - (v7 - v25);
      v16 = 0;
      while ( (int16_t)v22 > 0 )
      {
        sub_134D2D(
          (int16_t)v18,
          (int16_t)(v22 + *(_WORD *)((char *)off_184480 + 55 * (int16_t)v17 + 2) - 1),
          (int16_t)(v23 + (_WORD)v18 + 1),
          (int16_t)(v22 + *(_WORD *)((char *)off_184480 + 55 * (int16_t)v17 + 2) - 1),
          (uint8_t)v13[(int16_t)v25 - (int16_t)v16++ + 63]);
        --v22;
      }
    }
  }
  sub_120BB5(
    *(int *)((char *)off_184480 + 55 * (int16_t)v17 + 8) >> 16,
    *(_DWORD *)((char *)off_184480 + 55 * (int16_t)v17 + 12));
  sub_1212B3(
    *(_WORD *)((char *)off_184480 + 55 * (int16_t)v19),
    HIWORD(*(_DWORD *)((char *)off_184480 + 55 * (int16_t)v19)),
    (int)v13);
  sub_131F7B();
  sub_124ECB();
  return sub_12C2C6((int)off_184496 >> 16);
}
// 1167A6: variable 'v3' is possibly undefined
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184480: using guessed type _UNKNOWN *off_184480;
// 184496: using guessed type _UNKNOWN *off_184496;
// 1844C2: using guessed type int dword_1844C2;
// 1844C6: using guessed type int dword_1844C6;


//----- (00117174) --------------------------------------------------------
int16_t sub_117174( int a1)
{
  HIWORD(dword_1B3E10) = a1;
  sub_123C48();
  return sub_123C84();
}
// 1B3E10: using guessed type int dword_1B3E10;


//----- (001171AB) --------------------------------------------------------
int sub_1171AB(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]

  if ( SHIWORD(dword_1B3E10) <= 0 )
  {
    if ( dword_1B3E10 < 0 )
      HIWORD(dword_1B3E10) = 0;
    if ( *(int *)((char *)&dword_1B3E0A + 2) >> 16 > 1 )
    {
      sub_11CEF5(*(int *)((char *)&dword_1B3E0A + 2) >> 16, a2, a3, a4);
      v6 = v4;
      sub_124D41();
      if ( (_WORD)v6 )
      {
        if ( (v6 & 0x8000u) == 0 )
          LOWORD(v7) = v6;
        else
          v7 = -v6;
        sub_112399(*(uint16_t *)((char *)off_184480 + 55 * (int16_t)v7 + 53));
      }
      return v6;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    --HIWORD(dword_1B3E10);
    return 0;
  }
}
// 11720E: variable 'v4' is possibly undefined
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E10: using guessed type int dword_1B3E10;


//----- (00117262) --------------------------------------------------------
int16_t sub_117262()
{
  sub_123E6C((int)&unk_18449A, 1);
  HIWORD(dword_1B3E10) = 0;
  HIWORD(dword_18448E) = -1;
  word_1844B0 = 0;
  return sub_11C2F0();
}
// 18448E: using guessed type int dword_18448E;
// 1844B0: using guessed type int16_t word_1844B0;
// 1B3E10: using guessed type int dword_1B3E10;


//----- (001172B0) --------------------------------------------------------
void __noreturn sub_1172B0(int a1, int a2)
{
  sub_12643D(a1, a2);
}


//----- (001172D4) --------------------------------------------------------
void sub_1172D4()
{
  LOWORD(dword_1844E6) = 0;
}
// 1844E6: using guessed type int dword_1844E6;


//----- (001172FC) --------------------------------------------------------
void sub_1172FC()
{
  LOWORD(dword_1844E6) = 1;
}
// 1844E6: using guessed type int dword_1844E6;


//----- (00117324) --------------------------------------------------------
char *sub_117324( int a1)
{
  char *result; // eax

  result = (char *)off_184480 + 55 * a1;
  LOWORD(result) = *((_WORD *)result + 4);
  switch ( (int16_t)result )
  {
    case 0:
      result = (char *)off_184480 + 55 * a1;
      *((_WORD *)result + 4) = -1001;
      break;
    case 1:
      result = (char *)off_184480 + 55 * a1;
      *((_WORD *)result + 4) = -1;
      break;
    case 2:
      result = (char *)off_184480 + 55 * a1;
      *((_WORD *)result + 4) = -2;
      break;
    case 3:
      result = (char *)off_184480 + 55 * a1;
      *((_WORD *)result + 4) = -3;
      break;
    default:
      return result;
  }
  return result;
}
// 184480: using guessed type _UNKNOWN *off_184480;


//----- (001173DC) --------------------------------------------------------
int16_t sub_1173DC( int a1)
{
  char *v1; // eax

  LOWORD(v1) = *(_WORD *)((char *)off_184480 + 55 * a1 + 8);
  if ( (uint16_t)v1 < 0xFFFDu )
  {
    if ( (_WORD)v1 == 0xFC17 )
    {
      v1 = (char *)off_184480 + 55 * a1;
      *((_WORD *)v1 + 4) = 0;
    }
  }
  else if ( (uint16_t)v1 <= 0xFFFDu )
  {
    v1 = (char *)off_184480 + 55 * a1;
    *((_WORD *)v1 + 4) = 3;
  }
  else if ( (_WORD)v1 == 0xFFFF )
  {
    v1 = (char *)off_184480 + 55 * a1;
    *((_WORD *)v1 + 4) = 1;
  }
  else
  {
    v1 = (char *)off_184480 + 55 * a1;
    *((_WORD *)v1 + 4) = 2;
  }
  return (int16_t)v1;
}
// 184480: using guessed type _UNKNOWN *off_184480;


//----- (00117493) --------------------------------------------------------
int sub_117493()
{
  int result; // eax

  *(int *)((char *)&dword_1844E6 + 2) = 1;
  result = sub_11E718();
  *(int *)((char *)&dword_1844E6 + 2) = 0;
  return result;
}
// 1844E6: using guessed type int dword_1844E6;


//----- (001174CB) --------------------------------------------------------
int sub_1174CB()
{
  int v0; // kr04_4
  int16_t v1; // ax
  int16_t v2; // ax
  int16_t v3; // ax
  int16_t v5; // [esp+Ch] [ebp-30h]
  int16_t k; // [esp+Ch] [ebp-30h]
  int16_t j; // [esp+10h] [ebp-2Ch]
  int16_t i; // [esp+10h] [ebp-2Ch]
  int16_t v9; // [esp+10h] [ebp-2Ch]
  int v10; // [esp+14h] [ebp-28h]
  int v11; // [esp+14h] [ebp-28h]
  int v12; // [esp+18h] [ebp-24h]
  int16_t v13; // [esp+1Ch] [ebp-20h]
  _BOOL2 v14; // [esp+28h] [ebp-14h]
  int16_t v15; // [esp+2Ch] [ebp-10h]
  int16_t v16; // [esp+38h] [ebp-4h]

  v15 = HIWORD(dword_1BBA4A);
  v0 = dword_1BBA4E;
  v16 = dword_1BBA52;
  sub_128BE7();
  sub_124D7A();
  if ( (_WORD)dword_1844E6 )
  {
    v5 = 1;
    while ( v5 < word_1B3E0E )
    {
      if ( HIWORD(dword_18448E) == v5
        && *(int *)((char *)off_184480 + 55 * v5 + 6) >> 16 != 4
        && *(int *)((char *)off_184480 + 55 * v5 + 6) >> 16 != 12
        && *(int *)((char *)off_184480 + 55 * v5 + 6) >> 16 != 10 )
      {
        sub_11B05A((char *)v5, 1);
        goto LABEL_5;
      }
      switch ( *(_WORD *)((char *)off_184480 + 55 * v5 + 8) )
      {
        case 0:
          sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
          sub_12A478(
            *(_WORD *)((char *)off_184480 + 55 * v5),
            HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
            *(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
          if ( *(_DWORD *)((char *)off_184480 + 55 * v5 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v5 + 24) )
            goto LABEL_46;
          goto LABEL_114;
        case 1:
          if ( **(_WORD **)((char *)off_184480 + 55 * v5 + 32) )
          {
            if ( *(_WORD *)((char *)off_184480 + 55 * v5 + 36) )
            {
              sub_12B753(*(_DWORD *)((char *)off_184480 + 55 * v5 + 44), 1);
            }
            else
            {
              sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
              sub_12A478(
                *(_WORD *)((char *)off_184480 + 55 * v5),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            }
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v5),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v5 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v5 + 24) )
              goto LABEL_53;
          }
          else
          {
            sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v5),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v5 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v5 + 24) )
              goto LABEL_46;
          }
          goto LABEL_114;
        case 2:
          if ( **(_WORD **)((char *)off_184480 + 55 * v5 + 32) )
          {
            if ( *(_WORD *)((char *)off_184480 + 55 * v5 + 36) )
            {
              sub_12B753(*(_DWORD *)((char *)off_184480 + 55 * v5 + 44), 1);
            }
            else
            {
              sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
              sub_12A478(
                *(_WORD *)((char *)off_184480 + 55 * v5),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            }
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v5),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v5 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v5 + 24) )
              goto LABEL_53;
          }
          else
          {
            sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v5),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v5 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v5 + 24) )
              goto LABEL_46;
          }
          goto LABEL_114;
        case 3:
          if ( **(_WORD **)((char *)off_184480 + 55 * v5 + 32) == *(_WORD *)((char *)off_184480 + 55 * v5 + 28) )
          {
            if ( *(_WORD *)((char *)off_184480 + 55 * v5 + 36) )
            {
              sub_12B753(*(_DWORD *)((char *)off_184480 + 55 * v5 + 44), 1);
            }
            else
            {
              sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
              sub_12A478(
                *(_WORD *)((char *)off_184480 + 55 * v5),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            }
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v5),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v5 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v5 + 24) )
            {
LABEL_53:
              sub_120BB5(
                *(int *)((char *)off_184480 + 55 * v5 + 8) >> 16,
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 12));
              v11 = (sub_122259() - 1) / 2;
              sub_1210FD(
                *(_WORD *)((char *)off_184480 + 55 * v5)
              + ((*(int *)((char *)off_184480 + 55 * v5 + 2) >> 16) - *(int16_t *)((char *)off_184480 + 55 * v5)) / 2
              + dword_184492,
                HIWORD(dword_184492)
              + ((*(int *)((char *)off_184480 + 55 * v5 + 4) >> 16) - (*(int *)((char *)off_184480 + 55 * v5) >> 16))
              / 2
              + HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5))
              - v11,
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 24));
            }
          }
          else
          {
            sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v5),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v5 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v5 + 24) )
            {
LABEL_46:
              sub_120BB5(
                *(int *)((char *)off_184480 + 55 * v5 + 8) >> 16,
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 12));
              v10 = (sub_122259() - 1) / 2;
              sub_1210FD(
                ((*(int *)((char *)off_184480 + 55 * v5 + 2) >> 16) - *(int16_t *)((char *)off_184480 + 55 * v5)) / 2
              + *(_WORD *)((char *)off_184480 + 55 * v5),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5))
              + ((*(int *)((char *)off_184480 + 55 * v5 + 4) >> 16) - (*(int *)((char *)off_184480 + 55 * v5) >> 16))
              / 2
              - v10,
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 24));
            }
          }
          goto LABEL_114;
        case 4:
          if ( HIWORD(dword_18448E) != v5 )
          {
            sub_120BB5(*(int *)((char *)off_184480 + 55 * v5 + 8) >> 16, *(_DWORD *)((char *)off_184480 + 55 * v5 + 12));
            sub_120EB9(*(_DWORD *)((char *)off_184480 + 55 * v5 + 20));
            if ( *(_WORD *)((char *)off_184480 + 55 * v5 + 32) )
              sub_128C32(
                (int16_t)(*(_WORD *)((char *)off_184480 + 55 * v5) - 1),
                *(int *)((char *)off_184480 + 55 * v5) >> 16,
                *(int *)((char *)off_184480 + 55 * v5 + 2) >> 16,
                *(int *)((char *)off_184480 + 55 * v5 + 4) >> 16,
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5 + 30)));
            if ( *(_WORD *)((char *)off_184480 + 55 * v5 + 36) )
              sub_1210B7(
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5 + 2)),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 24));
            else
              sub_1212B3(
                *(_WORD *)((char *)off_184480 + 55 * v5),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 24));
          }
          goto LABEL_114;
        case 6:
          v13 = **(_WORD **)((char *)off_184480 + 55 * v5 + 32);
          if ( v13 < *(int16_t *)((char *)off_184480 + 55 * v5 + 24) )
            v13 = *(_WORD *)((char *)off_184480 + 55 * v5 + 24);
          if ( v13 > *(int16_t *)((char *)off_184480 + 55 * v5 + 28) )
            v13 = *(_WORD *)((char *)off_184480 + 55 * v5 + 28);
          **(_WORD **)((char *)off_184480 + 55 * v5 + 32) = v13;
          goto LABEL_114;
        case 0xA:
          sub_120BB5(*(int *)((char *)off_184480 + 55 * v5 + 8) >> 16, *(_DWORD *)((char *)off_184480 + 55 * v5 + 12));
          v12 = sub_122286() / 2;
          if ( !(_WORD)v12 )
            LOWORD(v12) = 1;
          v1 = sub_122259();
          if ( **(_WORD **)((char *)off_184480 + 55 * v5 + 32) == *(_WORD *)((char *)off_184480 + 55 * v5 + 28) )
          {
            sub_129B84(
              *(_WORD *)((char *)off_184480 + 55 * v5) - 1,
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)) - v12 + 1,
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5 + 2)),
              v1 + HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)) + 1,
              *(int *)((char *)off_184480 + 55 * v5 + 14) >> 16,
              *(uint8_t **)((char *)off_184480 + 55 * v5 + 36),
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 40),
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 44),
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 48));
            sub_1212B3(
              *(_WORD *)((char *)off_184480 + 55 * v5),
              *(_WORD *)((char *)off_184480 + 55 * v5 + 2) + 1,
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 24));
          }
          else
          {
            if ( !*(_WORD *)((char *)off_184480 + 55 * v5 + 18) )
              sub_120BB5(
                *(int *)((char *)off_184480 + 55 * v5 + 8) >> 16,
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 20));
            sub_1212B3(
              *(_WORD *)((char *)off_184480 + 55 * v5),
              *(_WORD *)((char *)off_184480 + 55 * v5 + 2) + 1,
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 24));
          }
          goto LABEL_114;
        case 0xB:
          if ( HIWORD(dword_1844CE) == v5 )
          {
            v3 = *(_WORD *)((char *)off_184480 + 55 * v5 + 48);
            if ( v3 < 0 )
            {
              if ( v3 == -1 )
              {
                sub_120CCB(
                  HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5 + 8)),
                  *(_DWORD *)((char *)off_184480 + 55 * v5 + 12));
                sub_120EB9(*(_DWORD *)((char *)off_184480 + 55 * v5 + 20));
              }
              else
              {
LABEL_92:
                sub_120BB5(
                  *(int *)((char *)off_184480 + 55 * v5 + 8) >> 16,
                  *(_DWORD *)((char *)off_184480 + 55 * v5 + 12));
                sub_120EB9(*(_DWORD *)((char *)off_184480 + 55 * v5 + 20));
              }
            }
            else
            {
              if ( v3 != 1 )
                goto LABEL_92;
              sub_120D05(
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5 + 8)),
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 12));
              sub_120EB9(*(_DWORD *)((char *)off_184480 + 55 * v5 + 20));
            }
            sub_121B8C();
            if ( *(_WORD *)((char *)off_184480 + 55 * v5 + 32) )
              sub_128C32(
                (int16_t)(*(_WORD *)((char *)off_184480 + 55 * v5) - 1),
                *(int *)((char *)off_184480 + 55 * v5) >> 16,
                *(int *)((char *)off_184480 + 55 * v5 + 2) >> 16,
                *(int *)((char *)off_184480 + 55 * v5 + 4) >> 16,
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5 + 30)));
            v14 = dword_1844C6 >> 16 != (*(int *)((char *)&dword_1844C2 + 2) >> 16) / 2;
            HIWORD(dword_1844C6) = (*(int *)((char *)&dword_1844C2 + 2) >> 16) / 2;
            LOWORD(dword_1844C6) = dword_1844C6 + 1;
            if ( *(int *)((char *)&dword_1844C2 + 2) >> 16 > 3 )
              LOWORD(dword_1844C6) = 0;
            if ( v14 )
            {
              if ( HIWORD(dword_1844C6) )
              {
                for ( i = 0; byte_1B071C[i] && i < (*(int *)((char *)off_184480 + 55 * v5 + 42) >> 16) - 1; ++i )
                  ;
                if ( i < (*(int *)((char *)off_184480 + 55 * v5 + 42) >> 16) - 1 )
                  strcat(byte_1B071C, asc_17A59D);
              }
              else
              {
                for ( j = 0; byte_1B071C[j] != 95 && j < *(int16_t *)((char *)off_184480 + 55 * v5 + 44); ++j )
                  ;
                byte_1B071C[j] = 0;
              }
            }
            if ( *(_DWORD *)((char *)off_184480 + 55 * v5 + 28) )
              sub_12A478(
                *(_WORD *)((char *)off_184480 + 55 * v5),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 28));
            sub_1212B3(
              *(_WORD *)((char *)off_184480 + 55 * v5) + 10,
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
              (int)byte_1B071C);
            sub_121B40();
            goto LABEL_114;
          }
          v2 = *(_WORD *)((char *)off_184480 + 55 * v5 + 48);
          if ( v2 < 0 )
          {
            if ( v2 != -1 )
            {
LABEL_81:
              sub_120BB5(
                *(int *)((char *)off_184480 + 55 * v5 + 8) >> 16,
                *(_DWORD *)((char *)off_184480 + 55 * v5 + 12));
              goto LABEL_82;
            }
            sub_120CCB(
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5 + 8)),
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 12));
          }
          else
          {
            if ( v2 != 1 )
              goto LABEL_81;
            sub_120D05(
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5 + 8)),
              *(_DWORD *)((char *)off_184480 + 55 * v5 + 12));
          }
LABEL_82:
          if ( *(_WORD *)((char *)off_184480 + 55 * v5 + 32) )
            sub_128C32(
              (int16_t)(*(_WORD *)((char *)off_184480 + 55 * v5) - 1),
              *(int *)((char *)off_184480 + 55 * v5) >> 16,
              *(int *)((char *)off_184480 + 55 * v5 + 2) >> 16,
              *(int *)((char *)off_184480 + 55 * v5 + 4) >> 16,
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5 + 30)));
          sub_1212B3(
            *(_WORD *)((char *)off_184480 + 55 * v5) + 10,
            HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v5)),
            *(_DWORD *)((char *)off_184480 + 55 * v5 + 24));
LABEL_114:
          if ( word_1844CC && *(int *)((char *)off_184480 + 55 * v5 + 6) >> 16 != 8 )
          {
            sub_12B634();
            sub_134D2D(
              *(int16_t *)((char *)off_184480 + 55 * v5),
              *(int *)((char *)off_184480 + 55 * v5) >> 16,
              *(int *)((char *)off_184480 + 55 * v5 + 2) >> 16,
              *(int *)((char *)off_184480 + 55 * v5) >> 16,
              SHIWORD(off_1844B2));
            sub_134D2D(
              *(int16_t *)((char *)off_184480 + 55 * v5),
              *(int *)((char *)off_184480 + 55 * v5) >> 16,
              *(int16_t *)((char *)off_184480 + 55 * v5),
              *(int *)((char *)off_184480 + 55 * v5 + 4) >> 16,
              SHIWORD(off_1844B2));
            sub_134D2D(
              *(int16_t *)((char *)off_184480 + 55 * v5),
              *(int *)((char *)off_184480 + 55 * v5 + 4) >> 16,
              *(int *)((char *)off_184480 + 55 * v5 + 2) >> 16,
              *(int *)((char *)off_184480 + 55 * v5 + 4) >> 16,
              SHIWORD(off_1844B2));
            sub_134D2D(
              *(int *)((char *)off_184480 + 55 * v5 + 2) >> 16,
              *(int *)((char *)off_184480 + 55 * v5) >> 16,
              *(int *)((char *)off_184480 + 55 * v5 + 2) >> 16,
              *(int *)((char *)off_184480 + 55 * v5 + 4) >> 16,
              SHIWORD(off_1844B2));
            sub_12B65C();
          }
LABEL_5:
          ++v5;
          break;
        default:
          goto LABEL_114;
      }
    }
  }
  if ( (_WORD)dword_1844CE && word_1844DA )
  {
    for ( k = 0; k < word_1844DA; ++k )
    {
      v9 = 5 * k;
      if ( *(int16_t *)(2 * (int16_t)(5 * k) + dword_1B0838) != -1 )
      {
        sub_12B634();
        sub_134D2D(
          *(int *)(dword_1B0838 + 2 * v9) >> 16,
          *(int *)(2 * v9 + dword_1B0838 + 2) >> 16,
          *(int *)(dword_1B0838 + 2 * v9 + 4) >> 16,
          *(int *)(2 * v9 + dword_1B0838 + 2) >> 16,
          word_1844B6);
        sub_134D2D(
          *(int *)(dword_1B0838 + 2 * v9) >> 16,
          *(int *)(2 * v9 + dword_1B0838 + 2) >> 16,
          *(int *)(2 * v9 + dword_1B0838) >> 16,
          *(int *)(2 * v9 + dword_1B0838 + 6) >> 16,
          word_1844B6);
        sub_134D2D(
          *(int *)(dword_1B0838 + 2 * v9) >> 16,
          *(int *)(2 * v9 + dword_1B0838 + 6) >> 16,
          *(int *)(dword_1B0838 + 2 * v9 + 4) >> 16,
          *(int *)(2 * v9 + dword_1B0838 + 6) >> 16,
          word_1844B6);
        sub_134D2D(
          *(int *)(dword_1B0838 + 2 * v9 + 4) >> 16,
          *(int *)(2 * v9 + dword_1B0838 + 2) >> 16,
          *(int *)(dword_1B0838 + 2 * v9 + 4) >> 16,
          *(int *)(2 * v9 + dword_1B0838 + 6) >> 16,
          word_1844B6);
        sub_12B65C();
      }
    }
  }
  return sub_128AB6(v15, SHIWORD(v0), v0, v16);
}
// 13F220: using guessed type int strcat(_DWORD, _DWORD);
// 184480: using guessed type _UNKNOWN *off_184480;
// 18448E: using guessed type int dword_18448E;
// 184492: using guessed type int dword_184492;
// 1844B2: using guessed type _UNKNOWN *off_1844B2;
// 1844B6: using guessed type int16_t word_1844B6;
// 1844C2: using guessed type int dword_1844C2;
// 1844C6: using guessed type int dword_1844C6;
// 1844CC: using guessed type int16_t word_1844CC;
// 1844CE: using guessed type int dword_1844CE;
// 1844DA: using guessed type int16_t word_1844DA;
// 1844E6: using guessed type int dword_1844E6;
// 1B0838: using guessed type int dword_1B0838;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00118FD4) --------------------------------------------------------
int16_t sub_118FD4( int result, int a2, int a3)
{
  int16_t v3; // [esp+0h] [ebp-10h]
  int16_t v4; // [esp+4h] [ebp-Ch]
  int16_t v5; // [esp+8h] [ebp-8h]

  v3 = result;
  v4 = a2;
  v5 = a3;
  if ( a2 >= 0 )
  {
    result = a2;
    if ( a2 < 640 && a3 >= 0 )
    {
      result = a3;
      if ( a3 < 480 )
      {
        sub_123A30();
        if ( v3 != HIWORD(dword_18448E) )
        {
          if ( dword_18448E >> 16 == -1 )
          {
            HIWORD(dword_18448E) = v3;
            sub_11B05A((char *)v3, 1);
            if ( *(int *)((char *)off_184480 + 55 * v3 + 6) >> 16 == 4 )
            {
              v4 = sub_123ABA();
              v5 = sub_123AE7();
            }
LABEL_23:
            sub_123B14(v4, v5);
            return sub_123A64();
          }
          if ( HIWORD(dword_18448E) != v3 )
          {
            if ( *(int *)((char *)off_184480 + 55 * (dword_18448E >> 16) + 6) >> 16 != 3
              || *(int *)((char *)off_184480 + 55 * v3 + 6) >> 16 == 3 )
            {
              if ( *(int *)((char *)off_184480 + 55 * (dword_18448E >> 16) + 6) >> 16 == 10 )
              {
                if ( *(int *)((char *)off_184480 + 55 * v3 + 6) >> 16 == 10
                  && *(_WORD *)((char *)off_184480 + 55 * v3 + 18) )
                {
                  sub_11B05A((char *)(dword_18448E >> 16), 0);
                }
              }
              else
              {
                sub_11B05A((char *)(dword_18448E >> 16), 0);
              }
            }
            HIWORD(dword_18448E) = v3;
            sub_11B05A((char *)v3, 1);
            if ( *(int *)((char *)off_184480 + 55 * v3 + 6) >> 16 == 4 )
            {
              v4 = sub_123ABA();
              v5 = sub_123AE7();
            }
            goto LABEL_23;
          }
        }
        return sub_123A64();
      }
    }
  }
  return result;
}
// 184480: using guessed type _UNKNOWN *off_184480;
// 18448E: using guessed type int dword_18448E;


//----- (0011919E) --------------------------------------------------------
int sub_11919E(int result)
{
  dword_184488 = result;
  return result;
}
// 184488: using guessed type int dword_184488;


//----- (001191CA) --------------------------------------------------------
int sub_1191CA(int result, int a2)
{
  dword_1B0840 = result;
  word_18448C = 1;
  if ( (int16_t)a2 > 0 && (result = (int16_t)a2, (int16_t)a2 < 10) )
  {
    result = a2;
    HIWORD(off_184496) = a2;
  }
  else
  {
    HIWORD(off_184496) = 2;
  }
  return result;
}
// 18448C: using guessed type int16_t word_18448C;
// 184496: using guessed type _UNKNOWN *off_184496;
// 1B0840: using guessed type int dword_1B0840;


//----- (00119226) --------------------------------------------------------
int sub_119226()
{
  int result; // eax

  result = dword_1B0840;
  dword_1B0844 = dword_1B0840;
  return result;
}
// 1B0840: using guessed type int dword_1B0840;
// 1B0844: using guessed type int dword_1B0844;


//----- (0011924F) --------------------------------------------------------
int sub_11924F()
{
  int result; // eax

  result = dword_1B0844;
  dword_1B0840 = dword_1B0844;
  word_18448C = 1;
  return result;
}
// 18448C: using guessed type int16_t word_18448C;
// 1B0840: using guessed type int dword_1B0840;
// 1B0844: using guessed type int dword_1B0844;


//----- (00119281) --------------------------------------------------------
void sub_119281()
{
  word_18448C = 0;
}
// 18448C: using guessed type int16_t word_18448C;


//----- (001192A9) --------------------------------------------------------
void sub_1192A9()
{
  word_18448C = 1;
}
// 18448C: using guessed type int16_t word_18448C;


//----- (001192D1) --------------------------------------------------------
int sub_1192D1()
{
  int result; // eax

  if ( word_18448C )
    return dword_1B0840();
  return result;
}
// 1B0840: invalid function type '?' has been ignored
// 18448C: using guessed type int16_t word_18448C;
// 1B0840: using guessed type int (*dword_1B0840)(void);


//----- (00119300) --------------------------------------------------------
int sub_119300()
{
  return dword_1B0844();
}
// 1B0844: invalid function type '?' has been ignored
// 1B0844: using guessed type int (*dword_1B0844)(void);


//----- (00119325) --------------------------------------------------------
int sub_119325()
{
  int result; // eax

  if ( word_18448C )
  {
    sub_12C2A0();
    sub_124D41();
    sub_1192D1();
    sub_124ECB();
    result = sub_12C2C6(1);
    if ( dword_184488 )
      return dword_184488(result);
  }
  else
  {
    sub_12C2A0();
    sub_124ECB();
    result = sub_12C2C6(1);
    if ( dword_184488 )
      return dword_184488(result);
  }
  return result;
}
// 184488: invalid function type '?' has been ignored
// 184488: using guessed type int (*dword_184488)(_DWORD);
// 18448C: using guessed type int16_t word_18448C;


//----- (001193A0) --------------------------------------------------------
int sub_1193A0()
{
  int result; // eax

  if ( word_18448C )
  {
    sub_12C2A0();
    sub_124D41();
    sub_1192D1();
    sub_124ECB();
    result = sub_12C2C6((int)off_184496 >> 16);
  }
  else
  {
    result = sub_124ECB();
  }
  if ( dword_184488 )
    return dword_184488(result);
  return result;
}
// 184488: using guessed type int (*dword_184488)(_DWORD);
// 18448C: using guessed type int16_t word_18448C;
// 184496: using guessed type _UNKNOWN *off_184496;


//----- (00119400) --------------------------------------------------------
int16_t sub_119400( int a1)
{
  word_1B3E0E = a1 + 1;
  HIWORD(dword_18448E) = -1;
  sub_123C48();
  return sub_123C84();
}
// 18448E: using guessed type int dword_18448E;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (00119441) --------------------------------------------------------
int16_t sub_119441()
{
  sub_123C48();
  return sub_123C84();
}


//----- (0011946A) --------------------------------------------------------
int16_t sub_11946A( int result)
{
  HIWORD(off_1844B2) = result;
  return result;
}
// 1844B2: using guessed type _UNKNOWN *off_1844B2;


//----- (001194C4) --------------------------------------------------------
int16_t sub_1194C4()
{
  word_1844E4 = 1;
  sub_123C48();
  return sub_123C84();
}
// 1844E4: using guessed type int16_t word_1844E4;


//----- (001194F6) --------------------------------------------------------
void sub_1194F6()
{
  word_1844E4 = 0;
}
// 1844E4: using guessed type int16_t word_1844E4;


//----- (0011951E) --------------------------------------------------------
int16_t sub_11951E()
{
  int v0; // eax

  word_1844A6 = 0;
  while ( 1 )
  {
    LOBYTE(v0) = sub_12C392();
    if ( !v0 )
      break;
    sub_12C2E1();
  }
  while ( sub_124075() )
    sub_1193A0();
  sub_123C48();
  return sub_123C84();
}
// 119546: variable 'v0' is possibly undefined
// 1844A6: using guessed type int16_t word_1844A6;


//----- (001196B8) --------------------------------------------------------
int sub_1196B8(int a1, int a2)
{
  int result; // eax

  dword_1B0838 = a1;
  word_1844D8 = 1;
  result = a2;
  word_1844DA = a2;
  return result;
}
// 1844D8: using guessed type int16_t word_1844D8;
// 1844DA: using guessed type int16_t word_1844DA;
// 1B0838: using guessed type int dword_1B0838;


//----- (001196F7) --------------------------------------------------------
void sub_1196F7()
{
  word_1844D8 = 0;
  word_1844DA = 0;
  dword_1B0838 = 0;
}
// 1844D8: using guessed type int16_t word_1844D8;
// 1844DA: using guessed type int16_t word_1844DA;
// 1B0838: using guessed type int dword_1B0838;


//----- (00119732) --------------------------------------------------------
int sub_119732()
{
  int16_t v0; // ax
  int16_t v3; // [esp+4h] [ebp-14h]
  int16_t i; // [esp+Ch] [ebp-Ch]
  int16_t v5; // [esp+10h] [ebp-8h]

  v3 = sub_123ABA();
  v0 = sub_123AE7();
  if ( !word_1844DA )
    return 1;
  for ( i = 0; ; ++i )
  {
    if ( i >= word_1844DA )
      return 1;
    v5 = 5 * i;
    if ( *(int16_t *)(2 * (int16_t)(5 * i) + dword_1B0838) != -1
      && v3 >= *(int16_t *)(2 * v5 + dword_1B0838 + 2)
      && v3 <= *(int16_t *)(2 * v5 + dword_1B0838 + 6)
      && v0 >= *(int16_t *)(2 * v5 + dword_1B0838 + 4)
      && v0 <= *(int16_t *)(2 * v5 + dword_1B0838 + 8) )
    {
      break;
    }
  }
  sub_A59A1();
  return 0;
}
// 1844DA: using guessed type int16_t word_1844DA;
// 1B0838: using guessed type int dword_1B0838;


//----- (00119861) --------------------------------------------------------
int16_t sub_119861()
{
  dword_1B0828 = *(int *)((char *)&dword_1B3E0A + 2) >> 16;
  dword_1B0830 = dword_1B3E10 >> 16;
  dword_1B0834 = dword_18448E >> 16;
  dword_1B0820 = (int)unk_1844A4 >> 16;
  dword_1B082C = *(int *)((char *)&dword_1844C6 + 2) >> 16;
  dword_1B0824 = dword_1844CE >> 16;
  off_184480 = (_UNKNOWN *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16));
  word_18447E -= word_1B3E0E;
  return sub_11C2F0();
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 18448E: using guessed type int dword_18448E;
// 1844C6: using guessed type int dword_1844C6;
// 1844CE: using guessed type int dword_1844CE;
// 1B0820: using guessed type int dword_1B0820;
// 1B0824: using guessed type int dword_1B0824;
// 1B0828: using guessed type int dword_1B0828;
// 1B082C: using guessed type int dword_1B082C;
// 1B0830: using guessed type int dword_1B0830;
// 1B0834: using guessed type int dword_1B0834;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1B3E10: using guessed type int dword_1B3E10;


//----- (001198F9) --------------------------------------------------------
void *sub_1198F9()
{
  void *result; // eax

  word_1B3E0E = dword_1B0828;
  HIWORD(dword_1B3E10) = dword_1B0830;
  HIWORD(dword_18448E) = dword_1B0834;
  word_1844A6 = dword_1B0820;
  word_1844CA = dword_1B082C;
  HIWORD(dword_1844CE) = dword_1B0824;
  result = off_184484;
  off_184480 = off_184484;
  word_18447E = 250;
  return result;
}
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 184484: using guessed type _UNKNOWN *off_184484;
// 18448E: using guessed type int dword_18448E;
// 1844A6: using guessed type int16_t word_1844A6;
// 1844CA: using guessed type int16_t word_1844CA;
// 1844CE: using guessed type int dword_1844CE;
// 1B0820: using guessed type int dword_1B0820;
// 1B0824: using guessed type int dword_1B0824;
// 1B0828: using guessed type int dword_1B0828;
// 1B082C: using guessed type int dword_1B082C;
// 1B0830: using guessed type int dword_1B0830;
// 1B0834: using guessed type int dword_1B0834;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1B3E10: using guessed type int dword_1B3E10;


//----- (00119D61) --------------------------------------------------------
int sub_119D61( int a1, int a2, int a3)
{
  int result; // eax
  int16_t i; // [esp+Ch] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= 6 )
      break;
    sub_11C358(i + a1 + 3, a2 + 2, *(_BYTE *)(a3 + i + 1));
    sub_11C358(i + a1 + 3, a2 + 3, *(_BYTE *)(a3 + i + 1));
  }
  return result;
}


//----- (0011A2C8) --------------------------------------------------------
int sub_11A2C8()
{
  int result; // eax
  int v1; // eax
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  _BYTE v7[200]; // [esp+0h] [ebp-E0h] BYREF
  int v8; // [esp+C8h] [ebp-18h]
  int v9; // [esp+CCh] [ebp-14h]
  int v10; // [esp+D0h] [ebp-10h]
  int i; // [esp+D4h] [ebp-Ch]
  int v12; // [esp+D8h] [ebp-8h]
  int v13; // [esp+DCh] [ebp-4h]

  sub_11A7B9();
  for ( i = 0; ; ++i )
  {
    result = (uint8_t)byte_1B3E1C;
    if ( (uint8_t)byte_1B3E1C <= (int16_t)i )
      break;
    if ( **(_BYTE **)(dword_1B081C + 40 * (int16_t)i) )
    {
      sub_120BB5(*(uint8_t *)(40 * (int16_t)i + dword_1B081C + 37), 40 * (int16_t)i + dword_1B081C + 13);
      LOWORD(v1) = sub_122259();
      v13 = v1;
      v2 = 40 * (int16_t)i + dword_1B081C;
      LOWORD(v2) = *(_WORD *)(v2 + 10) - *(_WORD *)(v2 + 6);
      v12 = v2 + 1;
      sub_1212B3(
        word_184475 + *(_WORD *)(dword_1B081C + 40 * (int16_t)i + 4),
        HIWORD(*(_DWORD *)(40 * (int16_t)i + dword_1B081C + 4)),
        *(_DWORD *)(40 * (int16_t)i + dword_1B081C));
    }
    if ( dword_1B3E02 >> 16 != -1
      && *(_BYTE *)(40 * (dword_1B3E02 >> 16) + dword_1B081C + 39)
      && (_WORD)i == HIWORD(dword_1B3E02) )
    {
      sub_120BB5(*(uint8_t *)(40 * (int16_t)i + dword_1B081C + 37), 40 * (int16_t)i + dword_1B081C + 13);
      LOWORD(v3) = sub_122259();
      v13 = v3;
      v4 = dword_1B081C + 40 * (int16_t)i;
      LOWORD(v4) = *(_WORD *)(v4 + 10) - *(_WORD *)(v4 + 6);
      v12 = v4 + 1;
      if ( strlen(*(_DWORD *)(dword_1B081C + 40 * (dword_1B3E02 >> 16))) < 200 && (uint8_t)byte_1B3E1B < 0xC8u )
      {
        strcpy(v7, *(_DWORD *)(dword_1B081C + 40 * (dword_1B3E02 >> 16)));
        v7[(uint8_t)byte_1B3E1B] = 0;
        v10 = sub_12066F((int)v7);
      }
      else
      {
        v10 = sub_12066F(*(_DWORD *)(dword_1B081C + 40 * (dword_1B3E02 >> 16)));
      }
      v5 = 40 * (dword_1B3E02 >> 16) + dword_1B081C;
      LOWORD(v5) = *(_WORD *)(v5 + 4);
      v8 = v10 + v5;
      v6 = dword_1B081C + 40 * (dword_1B3E02 >> 16);
      LOWORD(v6) = *(_WORD *)(v6 + 6);
      v9 = v13 + v6;
      if ( byte_184479 )
        sub_119D61(v8, v9, dword_1B081C + 40 * (dword_1B3E02 >> 16) + 13);
    }
  }
  return result;
}
// 11A351: variable 'v1' is possibly undefined
// 11A42D: variable 'v3' is possibly undefined
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 14432F: using guessed type int strlen(_DWORD);
// 184475: using guessed type int16_t word_184475;
// 184479: using guessed type char byte_184479;
// 1B081C: using guessed type int dword_1B081C;
// 1B3E02: using guessed type int dword_1B3E02;
// 1B3E1B: using guessed type char byte_1B3E1B;
// 1B3E1C: using guessed type char byte_1B3E1C;


