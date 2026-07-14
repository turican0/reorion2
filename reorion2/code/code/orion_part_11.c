#include "orion_common.h"

/* Adresni rozsah: 0xB04FD - 0xBBC6F  (200 funkci) */

//----- (000B04FD) --------------------------------------------------------
void sub_B04FD()
{
  int v0; // eax
  int16_t v1; // si
  int v2; // edx
  int16_t j; // ax
  char v4; // al
  int16_t v5; // ax
  void *v6; // edx
  int16_t i; // ax
  char v8; // dl
  _BYTE *v9; // eax
  int16_t v10; // dx
  int v11; // [esp+0h] [ebp-4h] BYREF

  sub_B4E64(13, 469, word_18283A, 19);
  v0 = 0;
  if ( word_182AB9 )
  {
    if ( word_182AB9 >= 5 )
      v0 = 3;
    else
      v0 = 2;
  }
  v11 = v0;
  sub_B0397((int)&v11);
  v1 = 0;
  sub_120CCB(4 - v11, (int)&unk_1827AD);
  while ( v1 < word_18283A )
  {
    v2 = word_1827CE[v1];
    if ( v2 == -3 || v2 == -2 || v2 == -10 )
    {
      for ( i = 0; i < 7; ++i )
      {
        if ( word_1827CE[v1] == word_1828AC[i] )
        {
          v8 = 1;
          goto LABEL_24;
        }
      }
      v8 = 0;
LABEL_24:
      v5 = 4 - v11;
      if ( v8 )
        v6 = &unk_1827AD;
      else
        v6 = &unk_1827B5;
    }
    else
    {
      for ( j = 0; j < 7; ++j )
      {
        if ( word_1827CE[v1] == word_1828AC[j] )
        {
          v4 = 1;
          goto LABEL_15;
        }
      }
      v4 = 0;
LABEL_15:
      if ( v4 )
      {
        v5 = 4 - v11;
        v6 = &unk_1827AD;
      }
      else
      {
        v5 = 4 - v11;
        v6 = &unk_1827B5;
      }
    }
    sub_120CCB(v5, (int)v6);
    v9 = sub_B2FFA(word_1827CE[v1]);
    v10 = v1 * (19 - word_182AB9) + 20;
    ++v1;
    sub_102F10(13, v10, (int)v9, 171);
  }
}
// 1827CE: using guessed type int16_t word_1827CE[];
// 18283A: using guessed type int16_t word_18283A;
// 1828AC: using guessed type int16_t word_1828AC[];
// 182AB9: using guessed type int16_t word_182AB9;


//----- (000B0663) --------------------------------------------------------
void sub_B0663()
{
  int v0; // eax
  int16_t v1; // si
  int v2; // eax
  _BYTE *v3; // eax
  int v4; // eax
  int v5; // edx
  char v6; // al
  int v7; // eax
  char v8; // al
  int16_t v9; // ax
  void *v10; // edx
  _BYTE *v11; // eax
  int16_t v12; // dx
  int v13; // [esp+0h] [ebp-4h] BYREF

  sub_B4E64(13, 308, word_1828A8, 19);
  v0 = 0;
  if ( word_182AB9 )
  {
    if ( word_182AB9 >= 5 )
      v0 = 3;
    else
      v0 = 2;
  }
  v13 = v0;
  sub_B0499((int)&v13);
  v1 = 0;
  sub_120CCB(4 - v13, (int)&unk_1827AD);
  while ( v1 < word_1828A8 )
  {
    v2 = word_18283C[v1];
    if ( v2 > -100
      && v2 <= -50
      && ((v3 = (_BYTE *)(361 * dword_19F7A8 + dword_192B18), v3[350]) || v3[351] || v3[318] ? (v4 = 0) : (v4 = 1),
          v4
       && *(_BYTE *)(-99 * (word_18283C[v1] + 50) + dword_197F98 + 3753 * word_19999C + 822) >= 2u
       && byte_1827BF != 1)
      || byte_1827BF == 1
      && word_19DEAA == word_18283C[v1]
      && word_19DEAA > -100
      && word_19DEAA <= -50
      && (uint16_t)sub_C5D97(30, 2)
      || (v5 = word_18283C[v1], v5 > -100)
      && v5 <= -50
      && (sub_E11BC((char *)(361 * dword_19F7A8 + dword_192B18), v5), !v6)
      && byte_1827BF != 1
      || ((v7 = word_18283C[v1], v7 == -11) || v7 == -12 || v7 == -13 || v7 == -17 || v7 == -16)
      && !(uint16_t)sub_B16F0(word_18283C[v1])
      && word_18283C[v1] == -16
      && (sub_E11BC((char *)(dword_192B18 + 361 * dword_19F7A8), -55), !v8) )
    {
      v9 = 4 - v13;
      v10 = &unk_1827B5;
    }
    else
    {
      v9 = 4 - v13;
      v10 = &unk_1827AD;
    }
    sub_120CCB(v9, (int)v10);
    v11 = sub_B2FFA(word_18283C[v1]);
    v12 = v1 * (19 - word_182AB9) + 20;
    ++v1;
    sub_102F10(485, v12, (int)v11, 138);
  }
  JUMPOUT(0xAFDE3);
}
// AFDE2: control flows out of bounds to AFDE3
// B07EC: variable 'v6' is possibly undefined
// B085D: variable 'v8' is possibly undefined
// 1827BF: using guessed type char byte_1827BF;
// 18283C: using guessed type int16_t word_18283C[54];
// 1828A8: using guessed type int16_t word_1828A8;
// 182AB9: using guessed type int16_t word_182AB9;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19DEAA: using guessed type int16_t word_19DEAA;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B08CA) --------------------------------------------------------
int sub_B08CA()
{
  int result; // eax
  int16_t i; // si
  _BYTE *v2; // eax
  int16_t v3; // dx

  result = sub_B4E64(13, 469, word_18283A, 19);
  for ( i = 0; i < word_18283A; ++i )
  {
    v2 = (_BYTE *)sub_CDF5C(12);
    v3 = sub_11438B(13, i * (19 - word_182AB9) + 20, 184, (19 - word_182AB9) * (i + 1) + 19, v2, 41);
    result = i;
    word_19DDB4[result] = v3;
  }
  return result;
}
// 18283A: using guessed type int16_t word_18283A;
// 182AB9: using guessed type int16_t word_182AB9;
// 19DDB4: using guessed type int16_t word_19DDB4[54];


//----- (000B094C) --------------------------------------------------------
int sub_B094C()
{
  int result; // eax
  int16_t i; // si
  _BYTE *v2; // eax
  int16_t v3; // dx

  result = sub_B4E64(13, 308, word_1828A8, 19);
  for ( i = 0; i < word_1828A8; ++i )
  {
    v2 = (_BYTE *)sub_CDF5C(12);
    v3 = sub_11438B(485, i * (19 - word_182AB9) + 20, 623, (19 - word_182AB9) * (i + 1) + 19, v2, 41);
    result = i;
    word_19DE20[result] = v3;
  }
  return result;
}
// 1828A8: using guessed type int16_t word_1828A8;
// 182AB9: using guessed type int16_t word_182AB9;
// 19DE20: using guessed type int16_t word_19DE20[54];


//----- (000B09CE) --------------------------------------------------------
char sub_B09CE()
{
  int16_t v0; // cx
  char v1; // bl
  int16_t i; // ax
  int v3; // edx

  v0 = -1;
  v1 = 0;
  for ( i = 0; i < 7; ++i )
  {
    if ( v0 == -1 )
    {
      v3 = word_1828AC[i];
      if ( v3 != -1 && (v3 == -3 || v3 == -2 || v3 == -10) )
        v0 = i;
    }
    else if ( word_1828AC[i] != -1 )
    {
      v1 = 1;
    }
  }
  return v1;
}
// 1828AC: using guessed type int16_t word_1828AC[];


//----- (000B0A24) --------------------------------------------------------
_DWORD *sub_B0A24()
{
  int16_t i; // cx
  int v1; // esi
  _DWORD *v2; // eax
  _DWORD *result; // eax

  for ( i = 0; i < 7; ++i )
  {
    if ( i )
    {
      v1 = i;
      v2 = sub_126B42((int)aColbldgLbx, i, dword_192ED4);
    }
    else
    {
      v1 = 0;
      v2 = sub_126AFD((int)aColbldgLbx, 0, dword_192ED4);
    }
    dword_19DD98[v1] = (int)v2;
  }
  dword_19DD8C = (int)sub_110D3C(dword_192ED4, 8100);
  result = sub_126B42((int)aColsumLbx, 21, dword_192ED4);
  dword_19DD90 = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 19DD8C: using guessed type int dword_19DD8C;
// 19DD90: using guessed type int dword_19DD90;
// 19DD98: using guessed type int dword_19DD98[];


//----- (000B0A9C) --------------------------------------------------------
void __fastcall sub_B0A9C( int a1)
{
  sub_128AB6(203, 9, 285, 103);
  sub_12B634();
  sub_BD988(244, 93, a1, 5, 5);
  sub_12B65C();
}


//----- (000B0AE3) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=51)) - nutno dohledat rucne v IDA @ 0xB0BA4 */
int __fastcall sub_B0AE3(_DWORD _p0)
{
  DECOMP_TODO("call analysis failed (funcsize=51)");
}


//----- (000B0BAE) --------------------------------------------------------
int64_t __fastcall sub_B0BAE(int16_t *a1, int a2, int a3, unsigned int a4)
{
  int v4; // ebp
  int v5; // ebp
  char *v6; // esi
  int16_t v7; // bx
  char *v8; // edi
  char *v9; // esi
  char *v10; // edi
  char *v11; // edi
  char *v12; // eax
  char *v13; // eax
  char *v15; // [esp-4h] [ebp+72h]
  int v16; // [esp+0h] [ebp+76h]
  int v17; // [esp+4h] [ebp+7Ah]
  char v18[500]; // [esp+8h] [ebp+7Eh] BYREF
  char v19[500]; // [esp+1FCh] [ebp+272h] BYREF
  char v20[500]; // [esp+3F0h] [ebp+466h] BYREF
  int v21; // [esp+5E4h] [ebp+65Ah]
  char v22; // [esp+5E8h] [ebp+65Eh]

  v5 = v4 - 1634;
  v22 = a3;
  if ( a4 > 1u )
    v6 = (char *)*(&off_17F807 + 7 * *a1);
  else
    v6 = (char *)*(&off_17F803 + 7 * *a1);
  strcpy(v20, v6);
  strcpy(v19, (char *)sub_CDF5C(12));
  strcpy(v18, (char *)sub_CDF5C(12));
  v7 = 0;
  v21 = v17 + 5;
  do
  {
    if ( (uint16_t)sub_1276F0(v21, v7) )
    {
      if ( v7 == 1 || v7 == 2 )
      {
        v8 = (char *)(v5 - 1 + 626);
        do
          ++v8;
        while ( *v8 );
        strcpy(v8, *(char **)((char *)&off_17FD0F + 15 * v7));
        v9 = asc_179D88;
        v10 = v19;
      }
      else
      {
        v10 = v18;
        v9 = *(char **)((char *)&off_17FD0F + 15 * v7);
      }
      v11 = v10 - 1;
      do
        ++v11;
      while ( *v11 );
      strcpy(v11, v9);
    }
    ++v7;
  }
  while ( v7 < 15 );
  if ( v22 )
    v12 = v18;
  else
    v12 = (char *)sub_CDF5C(12);
  v15 = v12;
  v13 = (char *)sub_CDF5C(81);
  return sprintf(v16, v13, v19, v20, v15);
}
// B0BB6: variable 'v4' is possibly undefined
// B0C34: variable 'v17' is possibly undefined
// B0CE4: variable 'v16' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17F803: using guessed type _UNKNOWN *off_17F803;
// 17F807: using guessed type _UNKNOWN *off_17F807;
// 17FD0F: using guessed type _UNKNOWN *off_17FD0F;


//----- (000B0CF6) --------------------------------------------------------
char __fastcall sub_B0CF6(int a1, int a2, int a3)
{
  char *v4; // eax
  int64_t v5; // rax
  int v6; // eax
  int v7; // ebx
  int16_t v8; // ax
  char *v9; // eax
  int v10; // eax
  char *v11; // eax
  int v12; // eax
  char *v13; // eax
  int v14; // eax
  char *v15; // eax
  int v16; // eax
  char *v17; // eax
  int v18; // eax
  char *v19; // eax
  int v20; // eax
  char *v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // edx
  int v25; // eax
  int16_t v26; // ax
  char *v27; // eax
  int v28; // eax
  char *v29; // eax
  int v30; // eax
  int16_t i; // bx
  char *v32; // eax
  int v33; // eax
  char *v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // edx
  int16_t v38; // cx
  int64_t v39; // rax
  char *v40; // eax
  int v41; // eax
  char *v42; // esi
  int16_t v43; // ax
  char *v44; // eax
  char *v45; // eax
  int v46; // eax
  int v48; // [esp-Ch] [ebp-C90h]
  int16_t *v49; // [esp-8h] [ebp-C8Ch]
  int v50; // [esp-8h] [ebp-C8Ch]
  int v51; // [esp-8h] [ebp-C8Ch]
  char *v52; // [esp-4h] [ebp-C88h]
  int v53; // [esp-4h] [ebp-C88h]
  int v54; // [esp-4h] [ebp-C88h]
  int v55; // [esp-4h] [ebp-C88h]
  int v56; // [esp-4h] [ebp-C88h]
  int v57; // [esp-4h] [ebp-C88h]
  _BYTE *v58; // [esp-4h] [ebp-C88h]
  int v59; // [esp-4h] [ebp-C88h]
  _BYTE v61[1600]; // [esp+4h] [ebp-C80h] BYREF
  char v62[500]; // [esp+644h] [ebp-640h] BYREF
  char v63[500]; // [esp+838h] [ebp-44Ch] BYREF
  char v64[532]; // [esp+A2Ch] [ebp-258h] BYREF
  int v65; // [esp+C40h] [ebp-44h] BYREF
  char v66[12]; // [esp+C44h] [ebp-40h] BYREF
  int v67; // [esp+C50h] [ebp-34h]
  int v68; // [esp+C54h] [ebp-30h]
  int v69; // [esp+C58h] [ebp-2Ch]
  char *v70; // [esp+C5Ch] [ebp-28h]
  char *v71; // [esp+C60h] [ebp-24h]
  int v72; // [esp+C64h] [ebp-20h]
  int v73; // [esp+C68h] [ebp-1Ch]
  int v74; // [esp+C6Ch] [ebp-18h]
  int v75; // [esp+C70h] [ebp-14h]
  int v76; // [esp+C74h] [ebp-10h]
  int v77; // [esp+C78h] [ebp-Ch]
  int v78; // [esp+C7Ch] [ebp-8h]
  char v79; // [esp+C80h] [ebp-4h]

  v65 = 1409774615;
  strcpy(v66, "0,5,124.");
  v4 = (char *)sub_CDF5C(70);
  v79 = 0;
  v74 = 0;
  v5 = sprintf(a2, v4, &v65);
  v75 = v5 + HIDWORD(v5);
  v6 = 0;
  do
  {
    v7 = 200 * (int16_t)v6++;
    v61[v7] = 0;
  }
  while ( (int16_t)v6 < 8 );
  if ( a3 )
  {
    if ( *(int16_t *)(a1 + 116) > 0 )
    {
      strcpy(v64, (char *)sub_97588(*(_WORD *)(a1 + 116), 0));
      strcpy(v63, (char *)sub_753F2((a1 - dword_197F9C) / 129));
      v52 = v63;
      v49 = (int16_t *)v64;
      v48 = a1;
      v8 = 78;
    }
    else
    {
      v52 = (char *)&unk_179D8A;
      v49 = sub_753F2((a1 - dword_197F9C) / 129);
      v48 = a1;
      v8 = 79;
    }
    v9 = (char *)sub_CDF5C(v8);
    v10 = sprintf(v75, v9, &unk_179D8D, v48, v49, v52);
    v75 += v10;
  }
  v53 = *(int16_t *)(a1 + 94);
  v11 = (char *)sub_CDF5C(99);
  v12 = sprintf(v75, v11, &unk_179D8D, &unk_179D90, v53);
  v75 += v12;
  v54 = *(int *)((char *)&off_17F6A1 + 59 * *(uint8_t *)(a1 + 18));
  v13 = (char *)sub_CDF5C(119);
  v14 = sprintf(v75, v13, &unk_179D8D, &unk_179D90, v54);
  v75 += v14;
  v55 = *(int *)((char *)&off_17FDEC + 22 * *(uint8_t *)(a1 + 21));
  v15 = (char *)sub_CDF5C(98);
  v16 = sprintf(v75, v15, &unk_179D8D, &unk_179D90, v55);
  v75 += v16;
  v56 = *(int *)((char *)&off_17F638 + 15 * *(uint8_t *)(a1 + 22));
  v17 = (char *)sub_CDF5C(91);
  v18 = sprintf(v75, v17, &unk_179D8D, &unk_179D90, v56);
  v75 += v18;
  v57 = *(int *)((char *)&off_17FE70 + 46 * *(uint8_t *)(a1 + 19));
  v19 = (char *)sub_CDF5C(104);
  v20 = sprintf(v75, v19, &unk_179D8D, &unk_179D90, v57);
  v75 += v20;
  v21 = (char *)sub_CDF5C(130);
  v22 = sprintf(v75, v21, &unk_179D8D);
  v75 += v22;
  v69 = a1 + 28;
  v72 = 4 * v74;
  v78 = 0;
  v76 = 0;
  v70 = &v61[200 * v74];
  do
  {
    v23 = 8 * (int16_t)v76;
    v73 = v23 + a1;
    if ( *(_WORD *)(v23 + a1 + 28) )
    {
      sub_B0BAE((int16_t *)(v69 + v23), (int)v62, 0, *(_BYTE *)(v23 + a1 + 30));
      if ( (int16_t)sub_12066F((int)v62) <= 110 )
      {
        v50 = *(uint8_t *)(v73 + 30);
        if ( (int16_t)v78 % 2 )
          v26 = 88;
        else
          v26 = 87;
        v27 = (char *)sub_CDF5C(v26);
        v28 = sprintf(v75, v27, &unk_179D8D, v50, v62);
        v75 += v28;
        ++v78;
      }
      else
      {
        v24 = v72;
        strcpy(v70, v62);
        ++v74;
        v72 += 4;
        v25 = *(uint8_t *)(v73 + 30);
        v70 += 200;
        *(_DWORD *)&v64[v24 + 500] = v25;
      }
    }
    ++v76;
  }
  while ( (int16_t)v76 < 8 );
  if ( v74 > 0 )
  {
    if ( (int16_t)v78 % 2 )
    {
      v29 = (char *)sub_CDF5C(127);
      v30 = sprintf(v75, v29);
      v75 += v30;
    }
    for ( i = 0; i < v74; ++i )
    {
      v58 = &v61[200 * i];
      v51 = *(_DWORD *)&v64[4 * i + 500];
      v32 = (char *)sub_CDF5C(88);
      v33 = sprintf(v75, v32, &unk_179D8D, v51, v58);
      v75 += v33;
    }
  }
  if ( (int16_t)v78 % 2 == 1 )
  {
    v34 = (char *)sub_CDF5C(127);
    v35 = sprintf(v75, v34);
    v75 += v35;
  }
  v36 = 0;
  do
  {
    v37 = 200 * (int16_t)v36++;
    v61[v37] = 0;
  }
  while ( (int16_t)v36 < 8 );
  v67 = 0;
  v77 = 0;
  v68 = a1 + 23;
  v38 = 0;
  v71 = v61;
  do
  {
    LOWORD(v39) = sub_1276F0(v68, v38);
    if ( (_WORD)v39 )
    {
      if ( !v79 )
      {
        v40 = (char *)sub_CDF5C(129);
        v79 = 1;
        v41 = sprintf(v75, v40, &unk_179D8D);
        v75 += v41;
      }
      if ( (int16_t)sub_12066F(*(int *)((char *)&off_17EEE0 + 47 * v38)) <= 115 )
      {
        v59 = *(int *)((char *)&off_17EEE0 + 47 * v38);
        if ( (int16_t)v77 % 2 )
          v43 = 90;
        else
          v43 = 89;
        v44 = (char *)sub_CDF5C(v43);
        LODWORD(v39) = sprintf(v75, v44, &unk_179D8D, v59);
        v75 += v39;
        ++v77;
      }
      else
      {
        v42 = *(char **)((char *)&off_17EEE0 + 47 * v38);
        ++v67;
        strcpy(v71, v42);
        v71 += 200;
      }
    }
    ++v38;
  }
  while ( v38 < 39 );
  if ( v67 > 0 )
  {
    if ( (int16_t)v77 % 2 )
    {
      v45 = (char *)sub_CDF5C(127);
      v46 = sprintf(v75, v45);
      v75 += v46;
    }
    WORD2(v39) = 0;
    while ( 1 )
    {
      LOBYTE(v39) = BYTE4(v39);
      if ( SWORD2(v39) >= v67 )
        break;
      LODWORD(v39) = sub_CDF5C(90);
      v39 = sprintf(v75, (char *)v39, &unk_179D8D, &v61[200 * SWORD2(v39)]);
      v75 += v39;
    }
  }
  return v39;
}
// B1245: variable 'v39' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17EEE0: using guessed type _UNKNOWN *off_17EEE0;
// 17F638: using guessed type _UNKNOWN *off_17F638;
// 17F6A1: using guessed type _UNKNOWN *off_17F6A1;
// 17FDEC: using guessed type _UNKNOWN *off_17FDEC;
// 17FE70: using guessed type _UNKNOWN *off_17FE70;
// 197F9C: using guessed type int dword_197F9C;


//----- (000B124A) --------------------------------------------------------
void __fastcall sub_B124A(int a1)
{
  _BYTE v2[20000]; // [esp+0h] [ebp-4E20h] BYREF

  sub_120CCB(1, (int)&unk_1827AD);
  sub_120E8C(1);
  sub_120E60(2);
  sub_B0CF6(a1, (int)v2, 0);
  sub_1031AA((int)v2, 0);
}


//----- (000B12AC) --------------------------------------------------------
void __fastcall sub_B12AC(int a1)
{
  int16_t v1; // bx
  int v2; // esi
  int16_t v3; // cx
  int v4; // edi
  int16_t v5; // dx
  int v6; // [esp+0h] [ebp-4h] BYREF

  v1 = a1;
  v2 = -(a1 + 50);
  v3 = a1;
  if ( (int16_t)a1 > -100 && (int16_t)a1 <= -50 )
  {
    v6 = 0;
    sub_120CCB(4, (int)&unk_1827AD);
    if ( v1 != 4 )
    {
      v4 = 99 * (int16_t)v2;
      v5 = 13 * v6++ + 21;
      sub_1212B3(306, v5, v4 + dword_197F98 + 3753 * word_19999C + 806);
      ++v6;
      sub_120CCB(3, (int)&unk_1827AD);
      sub_120E8C(1);
      sub_120E60(2);
      sub_B3B56(dword_19F7A8, v3, &v6);
      sub_B124A(v4 + dword_197F98 + 3753 * word_19999C + 806);
    }
  }
  sub_BAC4C(244, 56, v2);
  JUMPOUT(0xAFDE3);
}
// AFDE2: control flows out of bounds to AFDE3
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B13A0) --------------------------------------------------------
void __fastcall sub_B13A0(int a1)
{
  int v1; // edi
  int16_t v2; // cx
  int v3; // esi
  int v4; // [esp+0h] [ebp-4h] BYREF

  v1 = -(a1 + 100);
  v2 = a1;
  if ( (int16_t)a1 <= -100 )
  {
    v3 = 129 * (int16_t)v1;
    sub_120CCB(4, (int)&unk_1827AD);
    sub_1212B3(306, 21, v3 + dword_197F9C);
    v4 = 2;
    sub_120CCB(3, (int)&unk_1827AD);
    sub_120E8C(1);
    sub_120E60(2);
    sub_B3B56(dword_19F7A8, v2, &v4);
    sub_B124A(v3 + dword_197F9C);
  }
  sub_BAAC5(244, 56, v1);
  JUMPOUT(0xAFDE3);
}
// AFDE2: control flows out of bounds to AFDE3
// 197F9C: using guessed type int dword_197F9C;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B1458) --------------------------------------------------------
void sub_B1458()
{
  int16_t v0; // si
  int16_t i; // si

  if ( word_1828AA[0] != -1 )
  {
    if ( word_1828AA[0] < 49 )
    {
      for ( i = 0; i < word_18283A; ++i )
      {
        if ( word_1828AA[0] == word_1827CE[i] )
          sub_1297C3(8, i * (19 - word_182AB9) + 18, 171, 19 - word_182AB9 - 1, 1, 100);
      }
    }
    else
    {
      v0 = word_1828AA[0] - 49;
      if ( (word_19DEAA == word_1828AC[(int16_t)(word_1828AA[0] - 49)]
         || word_1828AA[0] != 49 && word_1828AC[v0] == -10 && word_19DEAA == word_1828AA[v0]
         || v0 < 6 && word_1828AE[v0] == -10 && word_19DEAA == word_1828AE[v0])
        && word_1828BE >= word_1827C0
        && word_1828BE <= word_1827CC
        && word_1828AC[v0] != -1 )
      {
        sub_1297C3(207, 20 * v0 + 332, 252, 16, 1, 239);
        if ( v0 && word_1828AC[v0] == -10 )
          sub_1297C3(207, 20 * (v0 - 1) + 332, 252, 16, 1, 239);
        if ( v0 < 6 && word_1828AE[v0] == -10 )
          sub_1297C3(207, 20 * (v0 + 1) + 332, 252, 16, 1, 239);
        sub_C0AF4();
      }
      else
      {
        sub_1297C3(207, 20 * v0 + 332, 252, 16, 1, 100);
        if ( v0 && word_1828AC[v0] == -10 )
          sub_1297C3(207, 20 * (v0 - 1) + 332, 252, 16, 1, 100);
        if ( v0 < 6 && word_1828AE[v0] == -10 )
          sub_1297C3(207, 20 * (v0 + 1) + 332, 252, 16, 1, 100);
        sub_123E6C((int)&unk_182765, 4);
      }
    }
  }
}
// 1827C0: using guessed type int16_t word_1827C0;
// 1827CC: using guessed type int16_t word_1827CC;
// 1827CE: using guessed type int16_t word_1827CE[];
// 18283A: using guessed type int16_t word_18283A;
// 1828AA: using guessed type int16_t word_1828AA[];
// 1828AC: using guessed type int16_t word_1828AC[];
// 1828AE: using guessed type int16_t word_1828AE[5];
// 1828BE: using guessed type int16_t word_1828BE;
// 182AB9: using guessed type int16_t word_182AB9;
// 19DEAA: using guessed type int16_t word_19DEAA;


//----- (000B16F0) --------------------------------------------------------
int __fastcall sub_B16F0( int a1)
{
  switch ( a1 )
  {
    case -12:
      return 1;
    case -17:
      return 4;
    case -11:
      return 2;
  }
  return 0;
}


//----- (000B1715) --------------------------------------------------------
char __fastcall sub_B1715( int a1)
{
  int16_t i; // bx
  int16_t v3; // si
  int v5; // ebx
  int16_t v6; // ax
  int v7; // edx
  int16_t v8; // ax
  int v9; // edx
  int16_t v10; // ax
  int v11; // ebx
  int16_t v12; // ax
  int v13; // eax
  int16_t v14; // ax
  int16_t v15; // di
  int v16; // eax
  char v17; // al
  int v18; // eax
  int v19; // eax
  int16_t v20; // ax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  char v25; // al
  int16_t v26; // ax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax

  for ( i = 0; i < 7; ++i )
  {
    if ( word_1828AC[i] == -1 )
      goto LABEL_6;
  }
  i = -1;
LABEL_6:
  v3 = i;
  if ( i == -1 )
  {
    if ( byte_1827BF )
    {
      byte_1827BF = 0;
      sub_C0AF4();
    }
    return 0;
  }
  if ( a1 > 0 && a1 < 49 || a1 == -3 || a1 == -2 || a1 == -10 || a1 == -15 || a1 <= -100 )
  {
LABEL_17:
    word_1828AC[v3] = a1;
    goto LABEL_45;
  }
  if ( a1 == -6 || a1 == -4 || a1 == -5 || a1 == -7 )
  {
    if ( a1 != -7 )
    {
      v5 = *(uint8_t *)(361 * dword_19F7A8 + dword_192B18 + 10);
      sub_AFDE9(-6);
      v7 = v6;
      sub_AFDE9(-4);
      v9 = v8 + v5 + v7;
      sub_AFDE9(-5);
      v11 = v9 + v10;
      sub_E0B4F((int16_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * dword_19F7A8 + 2)), word_19999C);
      if ( v11 + 1 >= v12 )
      {
        v13 = sub_CDF5C(520);
        sub_77658(v13);
        if ( !v14 )
          goto LABEL_45;
      }
    }
    goto LABEL_17;
  }
  if ( a1 != -11 && a1 != -12 && a1 != -13 && a1 != -17 && a1 != -16 )
  {
    if ( a1 <= -100 || a1 > -50 )
    {
      v29 = sub_CDF5C(332);
      sub_C5B5F(v29);
      sub_119281();
      v30 = sub_1191CA((int)sub_B3CF7, 1);
      sub_B3E75(v30);
      byte_182ACA = 1;
      return 0;
    }
    sub_E11BC((char *)(dword_192B18 + 361 * dword_19F7A8), a1);
    if ( !v25 )
    {
      if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C - 99 * (a1 + 50) + 822) != 4
        || *(_BYTE *)(dword_197F98 + 3753 * *(char *)(361 * dword_19F7A8 + dword_192B18) + 465) == 3 )
      {
        if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C - 99 * (a1 + 50) + 822) != 5
          || *(_BYTE *)(dword_197F98 + 3753 * *(char *)(dword_192B18 + 361 * dword_19F7A8) + 334) == 3 )
        {
          v26 = 567;
        }
        else
        {
          v26 = 581;
        }
      }
      else
      {
        v26 = 582;
      }
      v27 = sub_CDF5C(v26);
      sub_C5B5F(v27);
      sub_119281();
      v28 = sub_1191CA((int)sub_B3CF7, 1);
      sub_B3E75(v28);
      byte_182ACA = 1;
      goto LABEL_45;
    }
    v20 = sub_AF76F(-(int16_t)(a1 + 50));
    if ( v20 == -1 )
      goto LABEL_43;
    goto LABEL_44;
  }
  v15 = 4;
  if ( (uint16_t)sub_B16F0(a1) == 1 )
  {
    v15 = 5;
    sub_564CD(
      *(char *)(dword_192B18 + 361 * dword_19F7A8),
      dword_197F98 + 3753 * *(char *)(dword_192B18 + 361 * dword_19F7A8) + 1301);
    goto LABEL_42;
  }
  if ( (uint16_t)sub_B16F0(a1) == 4 )
  {
    v15 = 5;
    sub_56586(
      *(char *)(dword_192B18 + 361 * dword_19F7A8),
      dword_197F98 + 3753 * *(char *)(dword_192B18 + 361 * dword_19F7A8) + 1301);
    goto LABEL_42;
  }
  if ( (uint16_t)sub_B16F0(a1) == 2 )
  {
    v15 = 5;
    sub_5663E(
      *(char *)(dword_192B18 + 361 * dword_19F7A8),
      dword_197F98 + 3753 * *(char *)(dword_192B18 + 361 * dword_19F7A8) + 1301);
    goto LABEL_42;
  }
  if ( (uint16_t)sub_B16F0(a1) )
    goto LABEL_42;
  v16 = 361 * dword_19F7A8;
  if ( a1 == -16 )
  {
    v15 = 5;
    sub_E11BC((char *)(dword_192B18 + v16), -55);
    if ( !v17 )
    {
      v18 = sub_CDF5C(581);
      sub_C5B5F(v18);
      sub_119281();
      v19 = sub_1191CA((int)sub_B3CF7, 1);
      sub_B3E75(v19);
      byte_182ACA = 1;
      return 1;
    }
LABEL_42:
    v20 = sub_AF76F(v15);
    if ( v20 == -1 )
    {
LABEL_43:
      v21 = sub_CDF5C(538);
      sub_C5B5F(v21);
      sub_119281();
      v22 = sub_1191CA((int)sub_B3CF7, 1);
      sub_B3E75(v22);
      byte_182ACA = 1;
      byte_1827BF = 0;
      goto LABEL_45;
    }
LABEL_44:
    word_1828AC[i] = -(int16_t)(v20 + 100);
LABEL_45:
    if ( word_1828AA[0] != -1 && byte_1827BF != 2 )
    {
      sub_B230D(v3, word_1828AA[0] - 49);
      sub_C0AF4();
    }
    if ( byte_1827BF == 2 )
    {
      byte_1827BF = 0;
      sub_C0AF4();
      if ( a1 != -3 && a1 != -2 && a1 != -10 && !(uint8_t)sub_B1715(-10) )
      {
        v23 = sub_CDF5C(392);
        sub_C5B5F(v23);
        sub_119281();
        v24 = sub_1191CA((int)sub_B3CF7, 1);
        sub_B3E75(v24);
        byte_182ACA = 1;
        if ( byte_1827BF )
        {
          byte_1827BF = 0;
          sub_C0AF4();
        }
      }
    }
    sub_B20BD();
    return 1;
  }
  byte_1827BD = 1;
  word_199838 = 4;
  *(_BYTE *)(dword_192B18 + v16 + 297) = word_19DEAC;
  return 1;
}
// B17DD: variable 'v6' is possibly undefined
// B17EC: variable 'v8' is possibly undefined
// B17F9: variable 'v10' is possibly undefined
// B182B: variable 'v12' is possibly undefined
// B1846: variable 'v14' is possibly undefined
// B19A0: variable 'v17' is possibly undefined
// B1B18: variable 'v25' is possibly undefined
// B3E75: using guessed type int __fastcall sub_B3E75(_DWORD);
// 1827BD: using guessed type char byte_1827BD;
// 1827BF: using guessed type char byte_1827BF;
// 1828AA: using guessed type int16_t word_1828AA[];
// 1828AC: using guessed type int16_t word_1828AC[];
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199838: using guessed type int16_t word_199838;
// 19999C: using guessed type int16_t word_19999C;
// 19DEAC: using guessed type int16_t word_19DEAC;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B1C5D) --------------------------------------------------------
int __fastcall sub_B1C5D( int a1, int a2)
{
  int result; // eax
  int v4; // ebx

  for ( result = 0; (int16_t)result < 7; ++result )
  {
    if ( a2 <= 0 || a2 >= 49 )
    {
      if ( a2 > -100 && a2 <= -50 )
        return -1;
      v4 = 2 * (int16_t)result + dword_192B18 + 361 * a1;
      if ( *(int16_t *)(v4 + 277) > -100 )
      {
        if ( a2 < 49 )
        {
          if ( (a2 == -6 || a2 == -4 || a2 == -5 || a2 == -7 || a2 == -3 || a2 == -2 || a2 == -10 || a2 == -15)
            && a2 == *(_WORD *)(dword_192B18 + 361 * a1 + 2 * (int16_t)result + 277) )
          {
            return result;
          }
        }
        else if ( a2 - 49 == (int16_t)result )
        {
          return result;
        }
      }
      else if ( a2 == *(_WORD *)(v4 + 277) )
      {
        return result;
      }
    }
    else if ( a2 == *(_WORD *)(dword_192B18 + 361 * a1 + 2 * (int16_t)result + 277) )
    {
      return result;
    }
  }
  return -1;
}
// 192B18: using guessed type int dword_192B18;


//----- (000B1D57) --------------------------------------------------------
int __fastcall sub_B1D57( int a1)
{
  int i; // edx

  for ( i = 0; (int16_t)i < 7; ++i )
  {
    if ( a1 <= 0 || a1 >= 49 )
    {
      if ( a1 > -100 && a1 <= -50 )
        return -1;
      if ( word_1828AC[(int16_t)i] > -100 )
      {
        if ( a1 < 49 )
        {
          if ( (a1 == -6 || a1 == -4 || a1 == -5 || a1 == -7 || a1 == -3 || a1 == -2 || a1 == -10 || a1 == -15)
            && a1 == word_1828AC[(int16_t)i] )
          {
            return i;
          }
        }
        else if ( a1 - 49 == (int16_t)i )
        {
          return i;
        }
      }
      else if ( a1 == word_1828AC[(int16_t)i] )
      {
        return i;
      }
    }
    else if ( a1 == word_1828AC[(int16_t)i] )
    {
      return i;
    }
  }
  return -1;
}
// 1828AC: using guessed type int16_t word_1828AC[];


//----- (000B1E19) --------------------------------------------------------
int16_t __fastcall sub_B1E19( int a1, int a2)
{
  int16_t result; // ax
  int v4; // eax
  int v5; // ecx

  result = *(_WORD *)(361 * a1 + dword_192B18 + 2 * a2 + 277);
  if ( a2 != -1 )
  {
    if ( result <= -100 )
    {
      v4 = 129 * (int16_t)-(int16_t)(result + 100);
      v5 = dword_197F9C;
      *(_BYTE *)(dword_197F9C + v4 + 100) = 5;
      *(_WORD *)(v5 + v4 + 101) = -1;
    }
    return sub_B20ED(a1, a2);
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 197F9C: using guessed type int dword_197F9C;


//----- (000B1E77) --------------------------------------------------------
int16_t __fastcall sub_B1E77( int a1)
{
  int16_t v1; // cx
  int v2; // esi
  int16_t result; // ax
  int v4; // eax
  int16_t v5; // ax
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int16_t v10; // si
  int v11; // eax
  int16_t v12; // ax
  int v13; // edx
  int v14; // eax
  int v15; // eax
  int16_t v16; // ax

  v1 = a1;
  v2 = a1;
  result = word_1828AC[a1];
  if ( v2 != -1 )
  {
    if ( result <= -100 )
    {
      if ( *(_BYTE *)(dword_197F9C - 129 * (result + 100) + 100) == 4 )
      {
        v4 = sub_CDF5C(531);
        sub_77658(v4);
        if ( !v5 )
          goto LABEL_7;
      }
      if ( !sub_C5A84(word_1828AC[v1], 361 * dword_19F7A8 + dword_192B18 + 277, 0xEu) )
      {
        v6 = 129 * (int16_t)-(int16_t)(word_1828AC[v1] + 100);
        v7 = dword_197F9C;
        *(_BYTE *)(dword_197F9C + v6 + 100) = 5;
        *(_WORD *)(v7 + v6 + 101) = -1;
      }
      sub_119281();
      v9 = sub_1191CA((int)sub_B3CF7, 1);
      sub_B3E75(v9);
      byte_182ACA = 1;
    }
    if ( v1 && word_1828AC[v1] == -10 )
    {
      v10 = word_1828AC[--v1];
      if ( v10 <= -100 )
      {
        if ( *(_BYTE *)(dword_197F9C - 129 * (v10 + 100) + 100) != 4 || (v11 = sub_CDF5C(531), sub_77658(v11), v12) )
        {
          if ( !sub_C5A84(v10, dword_192B18 + 361 * dword_19F7A8 + 277, 0xEu) )
          {
            v13 = 129 * (int16_t)-(int16_t)(v10 + 100);
            v14 = dword_197F9C;
            *(_BYTE *)(v13 + dword_197F9C + 100) = 5;
            *(_WORD *)(v13 + v14 + 101) = -1;
          }
          sub_119281();
          v15 = sub_1191CA((int)sub_B3CF7, 1);
          sub_B3E75(v15);
          byte_182ACA = 1;
          goto LABEL_20;
        }
LABEL_7:
        sub_119281();
        v8 = sub_1191CA((int)sub_B3CF7, 1);
        result = sub_B3E75(v8);
        byte_182ACA = 1;
        return result;
      }
    }
    else if ( v1 >= 6 || word_1828AE[v1] != -10 )
    {
      v16 = v1;
      return sub_B2150(v16);
    }
LABEL_20:
    sub_B2150(v1 + 1);
    v16 = v1;
    return sub_B2150(v16);
  }
  return result;
}
// B1EC3: variable 'v5' is possibly undefined
// B1FC3: variable 'v12' is possibly undefined
// B3E75: using guessed type int __fastcall sub_B3E75(_DWORD);
// 1828AC: using guessed type int16_t word_1828AC[];
// 1828AE: using guessed type int16_t word_1828AE[5];
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 197F9C: using guessed type int dword_197F9C;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B206F) --------------------------------------------------------
void __fastcall sub_B206F( int a1, int a2)
{
  int16_t i; // ax

  for ( i = sub_B1C5D(a1, a2); i != -1; i = sub_B1C5D(a1, a2) )
    sub_B1E19(a1, i);
  JUMPOUT(0xB1E73);
}
// B2088: control flows out of bounds to B1E73


//----- (000B20A1) --------------------------------------------------------
int16_t __fastcall sub_B20A1( int a1)
{
  int16_t i; // bx
  int16_t result; // ax

  for ( i = 0; i < 7; ++i )
    result = sub_B1E19(a1, 0);
  return result;
}


//----- (000B20BD) --------------------------------------------------------
int sub_B20BD()
{
  int v0; // ebx
  int16_t i; // dx
  int result; // eax

  v0 = 0;
  do
  {
    for ( i = 0; i < 7; ++i )
    {
      result = word_1828AC[i];
      if ( result == -1 )
        result = sub_B2150(i);
    }
    ++v0;
  }
  while ( (int16_t)v0 < 2 );
  return result;
}
// 1828AC: using guessed type int16_t word_1828AC[];


//----- (000B20ED) --------------------------------------------------------
int __fastcall sub_B20ED( int a1, int a2)
{
  int16_t i; // cx
  int v4; // eax
  int v5; // eax
  int result; // eax

  do
  {
    for ( i = a2; i < 6; ++i )
    {
      v4 = 2 * i;
      *(_WORD *)(361 * a1 + dword_192B18 + v4 + 277) = *(_WORD *)(361 * a1 + dword_192B18 + v4 + 279);
    }
    v5 = 361 * a1 + dword_192B18;
    *(_WORD *)(v5 + 289) = -1;
    result = *(int16_t *)(v5 + 2 * a2 + 277);
  }
  while ( result == -10 );
  return result;
}
// 192B18: using guessed type int dword_192B18;


//----- (000B2150) --------------------------------------------------------
int __fastcall sub_B2150( int a1)
{
  int16_t i; // bx
  int v3; // eax
  int16_t v4; // cx
  int result; // eax

  do
  {
    for ( i = a1; i < 6; ++i )
    {
      v3 = i;
      v4 = word_1828AE[i];
      word_1828AC[v3] = v4;
    }
    word_1828B8 = -1;
    result = word_1828AC[a1];
  }
  while ( result == -10 );
  return result;
}
// 1828AC: using guessed type int16_t word_1828AC[];
// 1828AE: using guessed type int16_t word_1828AE[5];
// 1828B8: using guessed type int16_t word_1828B8;


//----- (000B2190) --------------------------------------------------------
void sub_B2190()
{
  int16_t v0; // si
  int v1; // ecx
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int64_t v5; // rax
  int v6; // eax
  int64_t v7; // rax
  int16_t v8; // [esp+4h] [ebp-4h]

  v0 = word_19DEA8;
  v1 = 129 * word_19DEA8;
  v8 = *(_WORD *)(v1 + dword_197F9C + 94);
  byte_199EF1 = 0;
  if ( sub_B1715(-(int16_t)(word_19DEA8 + 100)) )
  {
    sub_12779E(
      (_BYTE *)(v1 + dword_197F9C),
      (_BYTE *)(dword_197F98 + 3753 * *(char *)(361 * dword_19F7A8 + dword_192B18) + 1301),
      0x63u);
    v4 = dword_197F9C;
    *(_BYTE *)(v1 + dword_197F9C + 100) = 4;
    v5 = word_18001E[18 * *(uint8_t *)(v1 + v4 + 16)];
    if ( (int)(v5 - (__CFSHL__(HIDWORD(v5), 2) + 4 * HIDWORD(v5))) >> 2 >= 2
                                                                         * ((int16_t)sub_6B577(
                                                                                       *(char *)(361 * dword_19F7A8
                                                                                               + dword_192B18),
                                                                                       3753
                                                                                     * *(char *)(361 * dword_19F7A8
                                                                                               + dword_192B18)
                                                                                     + dword_197F98
                                                                                     + 1301)
                                                                          - v8) )
    {
      v7 = word_18001E[18 * *(uint8_t *)(v1 + dword_197F9C + 16)];
      v6 = (int)(v7 - (__CFSHL__(HIDWORD(v7), 2) + 4 * HIDWORD(v7))) >> 2;
    }
    else
    {
      v6 = 2
         * ((int16_t)sub_6B577(
                       *(char *)(361 * dword_19F7A8 + dword_192B18),
                       dword_197F98 + 3753 * *(char *)(361 * dword_19F7A8 + dword_192B18) + 1301)
          - v8);
    }
    *(_WORD *)(129 * v0 + dword_197F9C + 94) = v6;
  }
  else
  {
    v2 = sub_CDF5C(393);
    sub_C5B5F(v2);
    sub_119281();
    v3 = sub_1191CA((int)sub_B3CF7, 1);
    sub_B3E75(v3);
    byte_182ACA = 1;
  }
  sub_8A4C4();
  JUMPOUT(0xAFDE3);
}
// AFDE2: control flows out of bounds to AFDE3
// B3E75: using guessed type int __fastcall sub_B3E75(_DWORD);
// 18001E: using guessed type int16_t word_18001E[];
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199EF1: using guessed type char byte_199EF1;
// 19DEA8: using guessed type int16_t word_19DEA8;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B230D) --------------------------------------------------------
void __fastcall sub_B230D( int a1, int a2)
{
  int16_t v2; // bx
  int16_t v3; // si
  int16_t v4; // cx
  int v5; // eax
  int16_t v6; // di
  _BOOL2 v7; // si
  int16_t v8; // cx
  int v9; // eax
  int16_t v10; // bx
  int v11; // eax
  int16_t v12; // [esp+0h] [ebp-4h]

  v2 = a1;
  v3 = word_1828AC[a1];
  v12 = word_1828AE[a1];
  if ( word_1828AC[a2] == -10 )
    --a2;
  if ( v3 == -10 )
  {
    v2 = a1 - 1;
    v3 = word_1828AC[(int16_t)(a1 - 1)];
    v12 = word_1828AE[(int16_t)(a1 - 1)];
  }
  v4 = 5;
  sub_B2150(v2);
  while ( v4 >= a2 )
  {
    v5 = v4;
    v6 = word_1828AC[v4--];
    word_1828AE[v5] = v6;
  }
  word_1828AC[a2] = v3;
  if ( v12 == -10 )
  {
    v7 = a2 <= v2;
    v8 = 5;
    sub_B2150(v2 + v7);
    while ( 1 )
    {
      v11 = v7 + a2;
      if ( v8 < v11 )
        break;
      v9 = v8;
      v10 = word_1828AC[v8--];
      word_1828AE[v9] = v10;
    }
    word_1828AC[v11] = v12;
  }
  if ( byte_1827BF != 2 )
    word_1828AA[0] = -1;
  JUMPOUT(0xAFC1F);
}
// B23F5: control flows out of bounds to AFC1F
// 1827BF: using guessed type char byte_1827BF;
// 1828AA: using guessed type int16_t word_1828AA;
// 1828AC: using guessed type int16_t word_1828AC[];
// 1828AE: using guessed type int16_t word_1828AE[5];


//----- (000B23FA) --------------------------------------------------------
int __usercall sub_B23FA( int a1, int a2, int a3)
{
  int16_t i; // bx
  int v5; // edx
  int result; // eax
  int v7; // edx
  int v8; // eax
  int v9; // edx
  int v10; // edx
  int v11; // eax

  for ( i = 0; i < 7; ++i )
  {
    if ( a1 )
    {
      v5 = i;
      LOWORD(v5) = *(_WORD *)(361 * dword_19F7A8 + dword_192B18 + 2 * i + 277);
      result = (int16_t)v5;
      if ( (int16_t)v5 <= -100 )
      {
        result = (int16_t)sub_B1D57(v5);
        if ( (int16_t)result == -1 )
        {
          a3 = -(v5 + 100);
          v7 = 129 * (int16_t)a3;
          v8 = *(int16_t *)(v7 + dword_197F9C + 116);
          if ( v8 != -1 )
          {
            sub_944A3(v8, a2);
            *(_WORD *)(v7 + dword_197F9C + 116) = -1;
          }
          result = 129 * (int16_t)a3;
          v9 = dword_197F9C;
LABEL_13:
          *(_BYTE *)(v9 + result + 100) = 5;
          *(_WORD *)(v9 + result + 101) = -1;
          continue;
        }
      }
    }
    else
    {
      result = i;
      LOWORD(a3) = word_1828AC[i];
      if ( (int16_t)a3 <= -100 )
      {
        result = (int16_t)sub_B1C5D(dword_19F7A8, a3);
        if ( (int16_t)result == -1 )
        {
          v10 = -(a3 + 100);
          a3 = 129 * (int16_t)v10;
          v11 = *(int16_t *)(a3 + dword_197F9C + 116);
          if ( v11 != -1 )
          {
            sub_944A3(v11, a2);
            *(_WORD *)(a3 + dword_197F9C + 116) = -1;
          }
          v9 = 129 * (int16_t)v10;
          result = dword_197F9C;
          goto LABEL_13;
        }
      }
    }
  }
  return result;
}
// 1828AC: using guessed type int16_t word_1828AC[];
// 192B18: using guessed type int dword_192B18;
// 197F9C: using guessed type int dword_197F9C;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B2501) --------------------------------------------------------
int16_t __usercall sub_B2501(int a1, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // ebx
  int16_t result; // ax

  sub_B23FA(1, a1, a2);
  v2 = 0;
  do
  {
    v3 = (int16_t)v2;
    v4 = v3 * 2 + 361 * dword_19F7A8 + dword_192B18;
    result = word_1828AC[v3];
    ++v2;
    *(_WORD *)(v4 + 277) = result;
  }
  while ( (int16_t)v2 < 7 );
  return result;
}
// 1828AC: using guessed type int16_t word_1828AC[];
// 192B18: using guessed type int dword_192B18;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B2542) --------------------------------------------------------
void __usercall sub_B2542(int16_t *a1, int16_t *a2, int a3)
{
  int16_t v5; // ax
  int16_t v6; // ax
  int16_t v7; // bx
  int16_t i; // dx
  int v9; // eax
  char *v10; // eax
  int16_t v11; // ax
  int16_t j; // dx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int16_t v18; // ax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int16_t v22; // ax
  int16_t v23; // bx
  int v24; // eax
  int16_t v25; // ax
  _BYTE *v26; // edx
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int16_t v31; // ax
  int16_t v32; // dx
  int16_t v33; // ax
  int v34; // eax
  int v35; // eax
  int16_t m; // bx
  int v37; // eax
  int16_t v38; // dx
  int16_t n; // ax
  char v40; // al
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int16_t ii; // bx
  int v47; // eax
  int16_t v48; // dx
  int16_t v49; // ax
  int16_t v50; // ax
  int v51; // eax
  int v52; // eax
  int v53; // edx
  int16_t v54; // ax
  int16_t jj; // bx
  int v56; // edx
  int16_t v57; // ax
  int v58; // edx
  int v59; // edx
  char v60; // zf
  int v61; // eax
  int v62; // eax
  int v63; // eax
  _BYTE *v64; // [esp-8h] [ebp-214h]
  _BYTE *v65; // [esp-4h] [ebp-210h]
  _BYTE v66[500]; // [esp+0h] [ebp-20Ch] BYREF
  int v67; // [esp+1F4h] [ebp-18h]
  int v68; // [esp+1F8h] [ebp-14h]
  int v69; // [esp+1FCh] [ebp-10h]
  int v70; // [esp+200h] [ebp-Ch]
  int k; // [esp+204h] [ebp-8h]
  char v72; // [esp+208h] [ebp-4h]

  v72 = 0;
  v5 = *a2;
  word_19DEAA = -1;
  word_1828BE = v5;
  if ( byte_1827BD || byte_1827BE )
  {
    byte_1827BD = 0;
    byte_1827BE = 0;
    byte_1827BF = 0;
    sub_C0AF4();
    if ( word_199838 )
    {
      if ( !byte_199EF1 )
        goto LABEL_7;
      sub_B2190();
    }
    byte_199EF1 = 0;
  }
LABEL_7:
  v6 = *a1;
  if ( *a1 == word_19DE96 )
  {
    byte_1827BF = 0;
    sub_C0AF4();
    *(_BYTE *)(dword_192B18 + 361 * dword_19F7A8 + 297) = word_19DEAC;
    while ( 1 )
    {
      if ( !sub_B09CE() )
        goto LABEL_30;
      v7 = 0;
      for ( i = 0; ; ++i )
      {
        if ( i >= 7 )
          goto LABEL_18;
        v9 = word_1828AC[i];
        if ( v9 == -3 || v9 == -2 || v9 == -10 )
        {
          if ( sub_B09CE() )
            break;
        }
      }
      v7 = word_1828AC[i];
LABEL_18:
      a3 = v7;
      v65 = sub_B2FFA(v7);
      v64 = sub_B2FFA(v7);
      v10 = (char *)sub_CDF5C(59);
      sprintf(v66, v10, v64, v65);
      if ( !byte_199BE6 )
      {
        sub_77658((int)v66);
        if ( !v11 )
          break;
      }
      for ( j = 0; j < 7; ++j )
      {
        v13 = word_1828AC[j];
        if ( v13 == -3 || v13 == -2 || v13 == -10 )
        {
          if ( sub_B09CE() )
            sub_B2150(j);
        }
      }
      sub_119281();
      v15 = sub_1191CA((int)sub_B3CF7, 1);
      sub_B3E75(v15);
      byte_182ACA = 1;
    }
    sub_119281();
    v14 = sub_1191CA((int)sub_B3CF7, 1);
    sub_B3E75(v14);
    byte_182ACA = 1;
LABEL_30:
    sub_B2501(a3, (int)a2);
    goto LABEL_79;
  }
  if ( v6 == word_19DE90 || v6 == word_19DE92 )
  {
    if ( !byte_1827BF && word_1828AA[0] == -1 )
    {
      for ( k = 0; (int16_t)k < 7 && !v72; ++k )
      {
        v16 = word_1828AC[(int16_t)k];
        if ( v16 <= -100
          && !sub_C5A84(v16, dword_192B18 + 361 * dword_19F7A8 + 277, 0xEu)
          && *(_BYTE *)(dword_197F9C - 129 * (word_1828AC[(int16_t)k] + 100) + 100) == 4 )
        {
          v17 = sub_CDF5C(476);
          sub_77658(v17);
          if ( !v18 )
          {
            *a1 = 0;
            goto LABEL_156;
          }
          sub_119281();
          v72 = 1;
          v19 = sub_1191CA((int)sub_B3CF7, 1);
          sub_B3E75(v19);
          byte_182ACA = 1;
        }
      }
      a3 = 0;
      do
      {
        v20 = word_1828AC[(int16_t)a3];
        if ( v20 <= -100 )
          sub_C5A84(v20, dword_192B18 + 361 * dword_19F7A8 + 277, 0xEu);
        ++a3;
      }
      while ( (int16_t)a3 < 7 );
      sub_B23FA(0, a3, (int)a2);
    }
    else
    {
      byte_1827BF = 0;
      sub_C0AF4();
      word_1828AA[0] = -1;
      *a1 = 0;
      sub_C0AF4();
    }
    goto LABEL_79;
  }
  if ( v6 == word_19DE9A )
  {
    sub_123E6C((int)&unk_1827A1, 1);
    byte_1827BF = 1;
  }
  else
  {
    if ( v6 != word_19DE9C )
    {
      if ( v6 == word_19DE98 )
      {
        v21 = dword_197F98 + 3753 * *(char *)(dword_192B18 + 361 * dword_19F7A8);
        if ( *(_BYTE *)(v21 + 218) == 3 && *(_BYTE *)(v21 + 219) == 3 )
        {
          byte_1827BF = 0;
          sub_C0AF4();
          v22 = sub_C187B((int16_t *)a3);
          a3 = v22;
          v23 = v22;
          if ( v22 != -1 )
          {
            sub_119281();
            v24 = sub_1191CA((int)sub_B3CF7, 1);
            sub_B3E75(v24);
            byte_182ACA = 1;
            v25 = sub_C20AF(a3, (int16_t *)a3);
            if ( v25 == -3 )
            {
              byte_199EF1 = 1;
              byte_1827BE = 1;
              word_199838 = 1;
              word_19DEA8 = v23;
            }
            else if ( v25 == -2 )
            {
              v26 = (_BYTE *)(dword_197F9C + 129 * a3);
              v27 = 3753 * *(char *)(dword_192B18 + 361 * dword_19F7A8);
              a3 = dword_197F98;
              word_19DEA8 = v23;
              byte_199EF1 = 1;
              sub_12779E((_BYTE *)(dword_197F98 + v27 + 1301), v26, 0x63u);
              byte_1827BD = 1;
              word_199838 = 5;
            }
          }
          sub_119281();
        }
        else
        {
          v29 = sub_CDF5C(580);
          sub_C5B5F(v29);
          sub_119281();
        }
        v28 = sub_1191CA((int)sub_B3CF7, 1);
        sub_B3E75(v28);
      }
      else
      {
        if ( v6 == word_19DE94 )
          goto LABEL_79;
        if ( v6 == word_19DEA4 )
        {
          sub_B2501(a3, (int)a2);
          sub_BFC0B(dword_19F7A8);
          sub_119281();
          v30 = sub_1191CA((int)sub_B3CF7, 1);
          sub_B3E75(v30);
          byte_182ACA = 1;
          sub_119441();
          sub_117174(3);
          goto LABEL_79;
        }
        if ( v6 == word_19DEA0 )
        {
          v31 = sub_C01FC((int16_t)dword_19F7A8, 0);
          byte_1827BF = 0;
          v32 = v31;
          sub_C0AF4();
          a3 = dword_192B18;
          *(_BYTE *)(dword_192B18 + 361 * dword_19F7A8 + 297) = word_19DEAC;
          sub_B2501(a3, (int)a2);
          if ( v32 != dword_19F7A8 )
            sub_C0257(v32, a3);
        }
        else if ( v6 == word_19DEA2 )
        {
          v33 = sub_C01FC((int16_t)dword_19F7A8, 1);
          if ( v33 != dword_19F7A8 )
            sub_C0257(v33, a3);
          byte_1827BF = 0;
          sub_C0AF4();
          *(_BYTE *)(361 * dword_19F7A8 + dword_192B18 + 297) = word_19DEAC;
          sub_B2501(a3, (int)a2);
        }
        else
        {
          if ( v6 != word_19DE9E )
            goto LABEL_79;
          byte_182ACB = byte_182ACB == 0;
          v34 = sub_CDF5C(218);
          sub_C5B5F(v34);
          sub_119281();
          v35 = sub_1191CA((int)sub_B3CF7, 1);
          sub_B3E75(v35);
        }
      }
      byte_182ACA = 1;
      goto LABEL_79;
    }
    byte_1827BF = 2;
    sub_123E6C((int)&unk_182795, 1);
  }
LABEL_79:
  if ( byte_1827BF != 1 )
  {
    for ( m = 0; m < word_18283A; ++m )
    {
      if ( *a2 == word_19DDB4[m] )
        word_19DEAA = word_1827CE[m];
      v37 = 2 * m;
      if ( *a1 == *(int16_t *)((char *)word_19DDB4 + v37) )
      {
        LOWORD(v37) = word_1827CE[m];
        v70 = v37;
        v68 = v37;
        v38 = v37;
        for ( n = 0; ; ++n )
        {
          if ( n >= 7 )
          {
            v40 = 0;
            goto LABEL_90;
          }
          a3 = n;
          if ( v38 == word_1828AC[n] )
            break;
        }
        v40 = 1;
LABEL_90:
        if ( v40 )
        {
          v43 = sub_B1D57(v70);
          v69 = v43;
          v67 = 361 * dword_19F7A8;
          if ( *(_WORD *)(361 * dword_19F7A8 + dword_192B18 + 300) && !(_WORD)v43 )
          {
LABEL_95:
            v44 = sub_CDF5C(570);
            sub_C5B5F(v44);
            sub_119281();
            v45 = sub_1191CA((int)sub_B3CF7, 1);
            sub_B3E75(v45);
            byte_182ACA = 1;
            word_1828AA[0] = -1;
LABEL_96:
            sub_C0AF4();
            goto LABEL_156;
          }
          sub_B1E77(v69);
          if ( word_1828AA[0] >= 49 && word_1828AA[0] - 49 == (_WORD)v69 )
            word_1828AA[0] = -1;
        }
        else if ( !sub_B1715(v70) )
        {
          v41 = sub_CDF5C(392);
          sub_C5B5F(v41);
          sub_119281();
          v42 = sub_1191CA((int)sub_B3CF7, 1);
          sub_B3E75(v42);
          byte_182ACA = 1;
        }
      }
    }
  }
  for ( ii = 0; ; ++ii )
  {
    if ( ii >= word_1828A8 )
    {
      for ( jj = 0; jj < 7; ++jj )
      {
        if ( *a2 == word_1827C0[jj] )
          word_19DEAA = word_1828AC[jj];
        if ( *a1 == word_1827C0[jj] )
        {
          v56 = 361 * dword_19F7A8;
          if ( word_1828AA[0] == -1 )
          {
            sub_169020((int)&dword_192B18, v56, jj);
            if ( !v60 )
            {
              v61 = sub_CDF5C(570);
              sub_C5B5F(v61);
              sub_119281();
              v62 = sub_1191CA((int)sub_B3CF7, 1);
              sub_B3E75(v62);
              byte_182ACA = 1;
              goto LABEL_156;
            }
            word_1828AA[0] = jj + 49;
          }
          else
          {
            v57 = word_1828AA[0] - 49;
            if ( *(_WORD *)(v56 + dword_192B18 + 300) && (!jj || word_1828AA[0] == 49) )
              goto LABEL_95;
            if ( v57 == jj
              || (word_1828AC[v57] == -10 && word_1828AA[0] != 49 && (a3 = jj, v57 - 1 == jj)
               || (a3 = word_1828AE[v57], a3 == -10) && (v58 = v57 + 1, v58 < 7) && (a3 = jj, v58 == jj)
                ? (v59 = 0)
                : (v59 = 1),
                  !v59) )
            {
              a3 = dword_192B18 + 361 * dword_19F7A8;
              if ( *(_WORD *)(a3 + 300) && !jj && word_1828AA[0] == 49 )
                goto LABEL_95;
              sub_B1E77(jj);
              word_1828AA[0] = -1;
            }
            else
            {
              sub_B230D(v57, jj);
              sub_B20BD();
            }
            sub_C0AF4();
          }
          if ( byte_1827BF )
          {
            byte_1827BF = 0;
            sub_C0AF4();
            word_1828AA[0] = -1;
            *a1 = 0;
            sub_C0AF4();
          }
        }
      }
      if ( word_19994C )
      {
        sub_119281();
        v63 = sub_1191CA((int)sub_B3CF7, 1);
        sub_B3E75(v63);
        byte_182ACA = 1;
        word_19994C = 0;
      }
      sub_E2A70(dword_19F7A8, a3);
LABEL_156:
      JUMPOUT(0xAFC1F);
    }
    if ( *a2 == word_19DE20[ii] && word_18283C[ii] != -9 )
      word_19DEAA = word_18283C[ii];
    if ( *a1 == word_19DE20[ii] )
    {
      v47 = word_18283C[ii];
      if ( v47 != -9 )
      {
        if ( v47 == 11 )
        {
          sub_AFF9E();
          byte_182ACA = 1;
        }
        if ( word_18283C[ii] == 11 )
        {
          v48 = sub_AFE6E(*(uint8_t *)(dword_1930D4
                                             + 17 * *(int16_t *)(dword_192B18 + 361 * dword_19F7A8 + 2)
                                             + 2));
          sub_AFDE9(11);
          if ( v48 <= v49 )
          {
            v50 = 562;
LABEL_113:
            v51 = sub_CDF5C(v50);
            sub_C5B5F(v51);
            sub_119281();
            v52 = sub_1191CA((int)sub_B3CF7, 1);
            sub_B3E75(v52);
            byte_182ACA = 1;
            continue;
          }
        }
        if ( byte_1827BF == 1 )
        {
          v53 = word_18283C[ii];
          if ( v53 > -100 && v53 <= -50 )
          {
            v54 = word_18283C[ii];
            byte_1827BD = 1;
            word_199838 = -(int16_t)(v54 + 50);
            goto LABEL_96;
          }
        }
        else if ( !sub_B1715(word_18283C[ii]) )
        {
          v50 = 392;
          goto LABEL_113;
        }
      }
    }
  }
}
// B27CB: control flows out of bounds to AFC1F
// B2677: variable 'v11' is possibly undefined
// B27C6: variable 'v18' is possibly undefined
// B2D74: variable 'v49' is possibly undefined
// B2F39: variable 'v60' is possibly undefined
// B3E75: using guessed type int __fastcall sub_B3E75(_DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1827BD: using guessed type char byte_1827BD;
// 1827BE: using guessed type char byte_1827BE;
// 1827BF: using guessed type char byte_1827BF;
// 1827C0: using guessed type int16_t word_1827C0[6];
// 1827CE: using guessed type int16_t word_1827CE[];
// 18283A: using guessed type int16_t word_18283A;
// 18283C: using guessed type int16_t word_18283C[54];
// 1828A8: using guessed type int16_t word_1828A8;
// 1828AA: using guessed type int16_t word_1828AA[];
// 1828AC: using guessed type int16_t word_1828AC[];
// 1828AE: using guessed type int16_t word_1828AE[5];
// 1828BE: using guessed type int16_t word_1828BE;
// 182ACA: using guessed type char byte_182ACA;
// 182ACB: using guessed type char byte_182ACB;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199838: using guessed type int16_t word_199838;
// 19994C: using guessed type int16_t word_19994C;
// 199BE6: using guessed type char byte_199BE6;
// 199EF1: using guessed type char byte_199EF1;
// 19DDB4: using guessed type int16_t word_19DDB4[54];
// 19DE20: using guessed type int16_t word_19DE20[54];
// 19DE90: using guessed type int16_t word_19DE90;
// 19DE92: using guessed type int16_t word_19DE92;
// 19DE94: using guessed type int16_t word_19DE94;
// 19DE96: using guessed type int16_t word_19DE96;
// 19DE98: using guessed type int16_t word_19DE98;
// 19DE9A: using guessed type int16_t word_19DE9A;
// 19DE9C: using guessed type int16_t word_19DE9C;
// 19DE9E: using guessed type int16_t word_19DE9E;
// 19DEA0: using guessed type int16_t word_19DEA0;
// 19DEA2: using guessed type int16_t word_19DEA2;
// 19DEA4: using guessed type int16_t word_19DEA4;
// 19DEA8: using guessed type int16_t word_19DEA8;
// 19DEAA: using guessed type int16_t word_19DEAA;
// 19DEAC: using guessed type int16_t word_19DEAC;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B2FFA) --------------------------------------------------------
_BYTE *__fastcall sub_B2FFA( int a1)
{
  _BYTE *result; // eax
  char *v2; // eax
  int v3; // [esp-Ch] [ebp-Ch]
  _BYTE *v4; // [esp-8h] [ebp-8h]

  if ( a1 > 0 && a1 < 49 )
    return (_BYTE *)sub_BB40D(a1);
  if ( a1 > -100 )
    return (_BYTE *)sub_AFC6D(a1);
  result = (_BYTE *)(dword_197F9C - 129 * (a1 + 100));
  if ( result[100] == 4 )
  {
    word_1828BC = -1;
    v4 = result;
    word_1828BA = -1;
    v3 = sub_AFC6D(-8);
    v2 = (char *)sub_CDF5C(45);
    sprintf(&unk_19DA6C, v2, v3, v4);
    return &unk_19DA6C;
  }
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1828BA: using guessed type int16_t word_1828BA;
// 1828BC: using guessed type int16_t word_1828BC;
// 197F9C: using guessed type int dword_197F9C;


//----- (000B306F) --------------------------------------------------------
void sub_B306F()
{
  int16_t v0; // di
  int16_t v1; // si
  int16_t v2; // ax
  char *v3; // eax
  int64_t v4; // rax
  _BYTE *v5; // ebx
  _BYTE *v6; // [esp-4h] [ebp-1F8h]
  _BYTE v7[500]; // [esp+0h] [ebp-1F4h] BYREF

  v0 = 335;
  v1 = 0;
  while ( 1 )
  {
    if ( word_1828AA[0] < 49 )
      v2 = -1;
    else
      v2 = word_1828AA[0] - 49;
    if ( (v1 == v2 && word_19DEAA == word_1828AC[v2]
       || v1 == v2
       && (v2 < 6 && word_19DEAA == word_1828AE[v2] && word_1828AE[v2] == -10
        || v1 && word_19DEAA == word_1828AA[v2] && word_1828AC[v1] == -10)
       || v1
       && word_1828AC[v1] == -10
       && (word_19DEAA == word_1828AC[v1] || word_19DEAA == word_1828AA[v1])
       && (v2 == v1 - 1 || v1 == v2)
       || v1 < 6
       && word_1828AE[v1] == -10
       && (word_19DEAA == word_1828AC[v1] || word_19DEAA == word_1828AE[v1])
       && (v2 == v1 + 1 || v1 == v2))
      && word_1828BE >= word_1827C0
      && word_1828BE <= word_1827CC
      && word_1828AC[v1] != -1 )
    {
      sub_120CCB(3, (int)&unk_1827AD);
      v6 = sub_B2FFA(word_1828AC[v1]);
      v3 = (char *)sub_CDF5C(257);
      v4 = sprintf(v7, v3, v6);
      v5 = v7;
    }
    else
    {
      sub_120CCB(3, (int)&unk_1827AD);
      v5 = sub_B2FFA(word_1828AC[v1]);
      WORD2(v4) = v0;
    }
    sub_102F4F(332, SWORD2(v4), (int)v5, 251);
    ++v1;
    v0 += 20;
    if ( v1 >= 7 )
      JUMPOUT(0xAFDE3);
  }
}
// AFDE2: control flows out of bounds to AFDE3
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1827C0: using guessed type int16_t word_1827C0;
// 1827CC: using guessed type int16_t word_1827CC;
// 1828AA: using guessed type int16_t word_1828AA[];
// 1828AC: using guessed type int16_t word_1828AC[];
// 1828AE: using guessed type int16_t word_1828AE[5];
// 1828BE: using guessed type int16_t word_1828BE;
// 19DEAA: using guessed type int16_t word_19DEAA;


//----- (000B325A) --------------------------------------------------------
void sub_B325A()
{
  int v0; // edi
  int v1; // esi
  int16_t v2; // cx
  _BYTE *v3; // eax
  int16_t v4; // dx
  int16_t v5; // dx
  int v6; // eax
  int v7; // [esp+0h] [ebp-4h]

  v0 = 329;
  v7 = 350;
  v1 = 0;
  do
  {
    v2 = v7;
    v3 = (_BYTE *)sub_CDF5C(12);
    v4 = v0;
    v7 += 20;
    v0 += 20;
    v5 = sub_11438B(207, v4, 458, v2, v3, 41);
    v6 = (int16_t)v1++;
    word_1827C0[v6] = v5;
  }
  while ( (int16_t)v1 < 7 );
  JUMPOUT(0xAFDE3);
}
// AFDE2: control flows out of bounds to AFDE3
// 1827C0: using guessed type int16_t word_1827C0[6];


//----- (000B32B4) --------------------------------------------------------
int __fastcall sub_B32B4(int16_t *a1)
{
  return sub_C5CFF(244, 56, a1);
}


//----- (000B32CA) --------------------------------------------------------
int __fastcall sub_B32CA(int a1)
{
  return sub_1210FD(244, 56, a1);
}


//----- (000B3328) --------------------------------------------------------
void sub_B3328()
{
  int16_t v0; // cx
  int16_t v1; // si
  _BYTE *v2; // eax
  int16_t v3; // dx
  int v4; // eax
  int16_t v5; // cx
  int16_t v6; // si
  _BYTE *v7; // eax
  int16_t v8; // dx
  _BYTE *v9; // eax
  int16_t v10; // dx
  char *v11; // eax
  int16_t v12; // dx
  _BYTE *v13; // eax
  _BYTE *v14; // eax
  int16_t v15; // dx
  int16_t *v16; // ebx
  _BYTE *v17; // eax
  int16_t *v18; // eax
  int v19; // eax
  int16_t v20; // dx
  _BYTE *v21; // ebx
  int16_t v22; // dx
  char *v23; // eax
  int16_t v24; // dx
  int v25; // eax
  int v26; // eax
  _BYTE *v27; // eax
  _BYTE *v28; // eax
  int16_t v29; // dx
  int16_t v30; // bx
  _BYTE *v31; // eax
  int16_t v32; // dx
  _BYTE *v33; // eax
  int16_t v34; // dx
  _BYTE *v35; // eax
  int16_t v36; // dx
  char *v37; // eax
  int v38; // [esp-8h] [ebp-200h]
  int v39; // [esp-8h] [ebp-200h]
  int v40; // [esp-4h] [ebp-1FCh]
  int v41; // [esp-4h] [ebp-1FCh]
  int v42; // [esp+0h] [ebp-1F8h] BYREF
  int v43; // [esp+4h] [ebp-1F4h]
  int v44; // [esp+8h] [ebp-1F0h]
  int v45; // [esp+Ch] [ebp-1ECh]
  int v46; // [esp+10h] [ebp-1E8h]
  int v47; // [esp+14h] [ebp-1E4h]
  int v48; // [esp+18h] [ebp-1E0h]
  int v49; // [esp+1Ch] [ebp-1DCh]
  int v50; // [esp+20h] [ebp-1D8h]
  int v51; // [esp+24h] [ebp-1D4h]
  int v52; // [esp+28h] [ebp-1D0h]
  int v53; // [esp+2Ch] [ebp-1CCh]
  int v54; // [esp+30h] [ebp-1C8h]
  int v55; // [esp+34h] [ebp-1C4h]
  int v56; // [esp+38h] [ebp-1C0h]
  int v57; // [esp+3Ch] [ebp-1BCh]
  int v58; // [esp+40h] [ebp-1B8h]
  int v59; // [esp+44h] [ebp-1B4h]
  int v60; // [esp+48h] [ebp-1B0h]
  int v61; // [esp+4Ch] [ebp-1ACh]
  int v62; // [esp+50h] [ebp-1A8h]
  int v63; // [esp+54h] [ebp-1A4h]
  int v64; // [esp+58h] [ebp-1A0h]
  int v65; // [esp+5Ch] [ebp-19Ch]
  int v66; // [esp+60h] [ebp-198h]
  int v67; // [esp+64h] [ebp-194h]
  int v68; // [esp+68h] [ebp-190h]
  int v69; // [esp+6Ch] [ebp-18Ch]
  int v70; // [esp+1F4h] [ebp-4h] BYREF

  v70 = 0;
  if ( word_19DEAA == -1 )
    v0 = word_1828AC[0];
  else
    v0 = word_19DEAA;
  switch ( v0 )
  {
    case -17:
      sub_120CCB(4, (int)&unk_1827AD);
      v28 = sub_B2FFA(v0);
      v29 = 13 * v70++ + 21;
      sub_102F10(306, v29, (int)v28, 156);
      ++v70;
      sub_120CCB(3, (int)&unk_1827AD);
      sub_B3B56(dword_19F7A8, v0, &v70);
      sub_AFB0D(
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69);
      v30 = 46;
      goto LABEL_17;
    case -16:
      sub_120CCB(4, (int)&unk_1827AD);
      v27 = sub_B2FFA(v0);
      sub_102F10(306, 13 * v70 + 21, (int)v27, 156);
      v70 += 2;
      sub_120CCB(3, (int)&unk_1827AD);
      v26 = -55;
      goto LABEL_14;
    case -15:
      sub_120CCB(4, (int)&unk_1827AD);
      v33 = sub_B2FFA(v0);
      v34 = 13 * v70++ + 21;
      sub_1212B3(306, v34, (int)v33);
      ++v70;
      sub_120CCB(3, (int)&unk_1827AD);
      sub_B3B56(dword_19F7A8, v0, &v70);
      sub_AFB0D(
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69);
      v30 = 48;
      goto LABEL_17;
    case -13:
      ++v70;
      sub_120CCB(3, (int)&unk_1827AD);
      v26 = -54;
      goto LABEL_14;
    case -12:
      sub_120CCB(4, (int)&unk_1827AD);
      v31 = sub_B2FFA(v0);
      v32 = 13 * v70++ + 21;
      sub_102F10(306, v32, (int)v31, 156);
      ++v70;
      sub_120CCB(3, (int)&unk_1827AD);
      sub_B3B56(dword_19F7A8, v0, &v70);
      sub_AFB0D(
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69);
      v30 = 45;
LABEL_17:
      sub_BABA4(244, 56, v30);
      break;
    case -11:
      sub_120CCB(4, (int)&unk_1827AD);
      v35 = sub_B2FFA(v0);
      v36 = 13 * v70++ + 21;
      sub_1212B3(306, v36, (int)v35);
      ++v70;
      sub_120CCB(3, (int)&unk_1827AD);
      sub_B3B56(dword_19F7A8, v0, &v70);
      sub_BABA4(244, 56, 47);
      goto LABEL_10;
    case -10:
      sub_120CCB(4, (int)&unk_1827AD);
      v9 = sub_B2FFA(v0);
      v10 = 13 * v70++ + 21;
      sub_102F10(306, v10, (int)v9, 156);
      ++v70;
      sub_120CCB(3, (int)&unk_1827AD);
      v40 = sub_CDF5C(490);
      v38 = sub_CDF5C(243);
      v11 = (char *)sub_CDF5C(84);
      sprintf(&v42, v11, v38, v40);
      v12 = 13 * v70++ + 21;
      sub_1212B3(306, v12, (int)&v42);
      v13 = sub_B2FFA(v0);
      sub_1210FD(244, 56, (int)v13);
      break;
    case -8:
      sub_120CCB(4, (int)&unk_1827AD);
      v19 = sub_CDF5C(445);
      v20 = 13 * v70++ + 21;
      sub_1212B3(306, v20, v19);
      ++v70;
      sub_120CCB(3, (int)&unk_1827AD);
      v21 = sub_B2FFA(v0);
      v22 = 13 * v70++ + 21;
      sub_1212B3(306, v22, (int)v21);
      v41 = sub_CDF5C(490);
      v39 = sub_CDF5C(243);
      v23 = (char *)sub_CDF5C(84);
      sprintf(&v42, v23, v39, v41);
      v24 = 13 * v70++ + 21;
      sub_1212B3(306, v24, (int)&v42);
      sub_120CCB(5, (int)&unk_1827AD);
      v25 = sub_CDF5C(125);
      sub_1210FD(244, 56, v25);
      sub_120CCB(4, (int)&unk_1827AD);
      break;
    case -7:
      sub_120CCB(4, (int)&unk_1827AD);
      v17 = sub_B2FFA(v0);
      sub_1212B3(306, 13 * v70 + 21, (int)v17);
      v70 += 2;
      sub_B3B56(dword_19F7A8, v0, &v70);
      sub_AFB0D(
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69);
      sub_BB382();
      sub_C5CFF(244, 56, v18);
      break;
    case -6:
    case -5:
    case -4:
      sub_120CCB(4, (int)&unk_1827AD);
      v14 = sub_B2FFA(v0);
      v15 = 13 * v70++ + 21;
      sub_102F10(306, v15, (int)v14, 156);
      ++v70;
      sub_120CCB(3, (int)&unk_1827AD);
      sub_B3B56(dword_19F7A8, v0, &v70);
      v16 = (int16_t *)sub_BB54D(0, 4u, *(uint8_t *)(dword_197F98 + 3753 * word_19999C + 37));
      sub_C5CFF(244, 56, v16);
LABEL_10:
      sub_AFB0D(
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69);
      break;
    case -3:
      v6 = v0;
      sub_120CCB(4, (int)&unk_1827AD);
      v7 = sub_B2FFA(v0);
      v8 = 13 * v70++ + 21;
      sub_102F10(306, v8, (int)v7, 156);
      ++v70;
      v5 = 13;
      sub_B3B56(dword_19F7A8, v6, &v70);
      sub_B0A9C(14);
      goto LABEL_6;
    case -2:
      v1 = v0;
      sub_120CCB(4, (int)&unk_1827AD);
      v2 = sub_B2FFA(v0);
      v3 = 13 * v70++ + 21;
      sub_102F10(306, v3, (int)v2, 156);
      ++v70;
      v4 = sub_BBC46(3, 1, 0);
      sub_12A478(235, 54, v4);
      v5 = 12;
      sub_B3B56(dword_19F7A8, v1, &v70);
LABEL_6:
      sub_AFA5C(209, 119, 248, v5);
      break;
    case -1:
    case 0:
      break;
    default:
      if ( v0 <= 0 || v0 >= 49 )
      {
        v26 = v0;
        if ( v0 > -100 )
        {
          if ( v0 <= -50 )
          {
LABEL_14:
            sub_B12AC(v26);
          }
          else
          {
            v37 = (char *)sub_CDF5C(248);
            _wcpp_1_unwind_leave(0, 0, v37, v0);
            sub_6497C();
          }
        }
        else
        {
          sub_B13A0(v0);
        }
      }
      else
      {
        sub_B0AE3(v0);
      }
      break;
  }
  JUMPOUT(0xB065D);
}
// B3367: control flows out of bounds to B065D
// B3787: variable 'v18' is possibly undefined
// B0AE3: using guessed type int __fastcall sub_B0AE3(_DWORD);
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1828AC: using guessed type int16_t word_1828AC[];
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19DEAA: using guessed type int16_t word_19DEAA;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B3B56) --------------------------------------------------------
void __fastcall sub_B3B56( int a1, int a2, _WORD *a3)
{
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  int v8; // eax
  int16_t v9; // ax
  char *v10; // eax
  int v11; // [esp-4h] [ebp+7Ah]
  int v12; // [esp-4h] [ebp+7Ah]
  int v13; // [esp-4h] [ebp+7Ah]
  int v14; // [esp-4h] [ebp+7Ah]
  _BYTE v15[500]; // [esp+0h] [ebp+7Eh] BYREF
  int v16; // [esp+1F4h] [ebp+272h]
  int v17; // [esp+1F8h] [ebp+276h]

  v16 = a2;
  v11 = (int16_t)sub_E0DD6((char *)(dword_192B18 + 361 * a1), a2);
  v5 = (char *)sub_CDF5C(242);
  sprintf(v15, v5, v11);
  sub_1212B3(306, 13 * *a3 + 21, (int)v15);
  ++*a3;
  if ( a2 > 0 && a2 < 49 )
  {
    v12 = *(int16_t *)((char *)&word_17EB49 + 19 * v16);
    v6 = (char *)sub_CDF5C(367);
    sprintf(v15, v6, v12);
    sub_1212B3(306, 13 * *a3 + 21, (int)v15);
    ++*a3;
  }
  v17 = a1;
  v13 = (int16_t)sub_BDBB9(a1, a2);
  v7 = (char *)sub_CDF5C(211);
  sprintf(v15, v7, v13);
  sub_102F10(306, 13 * *a3 + 21, (int)v15, 156);
  v8 = dword_192B18 + 361 * v17;
  ++*a3;
  if ( a2 == *(_WORD *)(v8 + 277) )
  {
    v14 = (int16_t)sub_BDC93(v17);
    v9 = 544;
  }
  else
  {
    if ( a2 != 25 )
      return;
    v14 = dword_192C74[*(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v8 + 2) + 6)];
    v9 = 314;
  }
  v10 = (char *)sub_CDF5C(v9);
  sprintf(v15, v10, v14);
  sub_102F10(306, 13 * *a3 + 21, (int)v15, 156);
  ++*a3;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17EB49: using guessed type int16_t word_17EB49;
// 192B18: using guessed type int dword_192B18;
// 192C74: using guessed type int dword_192C74[];
// 1930D4: using guessed type int dword_1930D4;


//----- (000B3CF7) --------------------------------------------------------
void sub_B3CF7()
{
  int v0; // eax
  char *v1; // eax
  int64_t v2; // rax
  int16_t *v3; // [esp-4h] [ebp-CCh]
  _BYTE v4[200]; // [esp+0h] [ebp-C8h] BYREF

  if ( byte_182ACA )
  {
    sub_128C32(0, 0, 640, 479, 0);
    v0 = sub_BBA8E(0);
    sub_12A478(0, 0, v0);
    sub_B6255();
    sub_BEBDC();
    sub_1382BF(246, 9, 244, 10, 0);
    sub_12B79D(dword_19DD98[0]);
    sub_1318D4(0, 255);
    sub_133237();
    sub_1298DE(202, 304, 463, 470);
    sub_12A478(0, 0, dword_19DD98[0]);
    v3 = sub_77B28(*(_WORD *)(361 * dword_19F7A8 + dword_192B18 + 2));
    v1 = (char *)sub_CDF5C(210);
    v2 = sprintf(v4, v1, v3);
    sub_120CCB(3, SHIDWORD(v2));
    sub_1031C6((int)v4, 2);
    if ( byte_199F19 == 20 || word_19DEA6 == 20 )
    {
      sub_12B79D(dword_19DD98[0]);
      sub_133237();
      sub_12B79D(dword_19DD90);
    }
    else
    {
      sub_133237();
    }
    sub_124DEC();
    byte_182ACA = 0;
  }
  sub_120CCB(4, (int)&unk_1827AD);
  sub_120E8C(1);
  sub_B04FD();
  sub_B0663();
  sub_B306F();
  sub_B3328();
  sub_B1458();
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 199F19: using guessed type char byte_199F19;
// 19DD90: using guessed type int dword_19DD90;
// 19DD98: using guessed type int dword_19DD98[];
// 19DEA6: using guessed type int16_t word_19DEA6;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B3E7A) --------------------------------------------------------
int sub_B3E7A()
{
  _WORD *v0; // ecx
  int v1; // eax
  _WORD *v2; // ecx
  int v3; // eax
  _BYTE *v4; // eax
  _BYTE *v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  _WORD *v8; // ecx
  int v9; // eax
  _WORD *v10; // ecx
  int v11; // eax
  _WORD *v12; // ecx
  int v13; // eax
  _WORD *v14; // ecx
  int v15; // eax
  uint16_t v16; // ax
  _BYTE *v18; // [esp-10h] [ebp-14h]
  _BYTE *v19; // [esp-10h] [ebp-14h]
  _BYTE *v20; // [esp-10h] [ebp-14h]
  _BYTE *v21; // [esp-10h] [ebp-14h]
  _BYTE *v22; // [esp-10h] [ebp-14h]

  v18 = (_BYTE *)sub_CDF5C(12);
  v0 = (_WORD *)dword_19DD9C;
  v1 = sub_CDF5C(12);
  word_19DE90 = (uint16_t)sub_1151B0(493, 447, v1, v0, v18, 40);
  v19 = (_BYTE *)sub_CDF5C(12);
  v2 = (_WORD *)dword_19DDA4;
  v3 = sub_CDF5C(12);
  word_19DE96 = (uint16_t)sub_1151B0(560, 447, v3, v2, v19, 40);
  v4 = (_BYTE *)sub_CDF5C(135);
  word_19DE92 = sub_114C72(v4, 447);
  v5 = (_BYTE *)sub_CDF5C(139);
  word_19DEA0 = sub_114C72(v5, 447);
  v6 = (_BYTE *)sub_CDF5C(140);
  word_19DEA2 = sub_114C72(v6, 447);
  v7 = (_BYTE *)sub_CDF5C(193);
  word_19DEA4 = sub_114C72(v7, 447);
  v20 = (_BYTE *)sub_CDF5C(12);
  v8 = (_WORD *)dword_19DDA0;
  v9 = sub_CDF5C(12);
  word_19DE94 = sub_11523B(490, 342, v9, v8, (int)&word_19DEAC, v20, 41);
  if ( byte_199CB4 )
  {
    word_19DE98 = -1000;
    word_19DE9A = -1000;
  }
  else
  {
    v21 = (_BYTE *)sub_CDF5C(436);
    v10 = (_WORD *)dword_19DDA8;
    v11 = sub_CDF5C(12);
    word_19DE98 = (uint16_t)sub_1151B0(492, 379, v11, v10, v21, 40);
    v22 = (_BYTE *)sub_CDF5C(251);
    v12 = (_WORD *)dword_19DDAC;
    v13 = sub_CDF5C(12);
    word_19DE9A = (uint16_t)sub_1151B0(561, 379, v13, v12, v22, 40);
  }
  v14 = (_WORD *)dword_19DDB0;
  v15 = sub_CDF5C(12);
  v16 = (uint16_t)sub_1151B0(503, 411, v15, v14, byte_179D92, 40);
  word_19DE9E = -1000;
  word_19DE9C = v16;
  sub_B325A();
  sub_B08CA();
  return sub_B094C();
}
// 179D92: using guessed type _BYTE byte_179D92[2];
// 199CB4: using guessed type char byte_199CB4;
// 19DD9C: using guessed type int dword_19DD9C;
// 19DDA0: using guessed type int dword_19DDA0;
// 19DDA4: using guessed type int dword_19DDA4;
// 19DDA8: using guessed type int dword_19DDA8;
// 19DDAC: using guessed type int dword_19DDAC;
// 19DDB0: using guessed type int dword_19DDB0;
// 19DE90: using guessed type int16_t word_19DE90;
// 19DE92: using guessed type int16_t word_19DE92;
// 19DE94: using guessed type int16_t word_19DE94;
// 19DE96: using guessed type int16_t word_19DE96;
// 19DE98: using guessed type int16_t word_19DE98;
// 19DE9A: using guessed type int16_t word_19DE9A;
// 19DE9C: using guessed type int16_t word_19DE9C;
// 19DE9E: using guessed type int16_t word_19DE9E;
// 19DEA0: using guessed type int16_t word_19DEA0;
// 19DEA2: using guessed type int16_t word_19DEA2;
// 19DEA4: using guessed type int16_t word_19DEA4;
// 19DEAC: using guessed type int16_t word_19DEAC;


//----- (000B4041) --------------------------------------------------------
void __usercall sub_B4041( int a1, int16_t *a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  char *v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int16_t v14; // ax
  int v15; // [esp+0h] [ebp-8h] BYREF
  char *v16; // [esp+4h] [ebp-4h] BYREF

  v15 = 0;
  v2 = sub_12484C();
  sub_124820(dword_19F7A8);
  dword_19F7B8 = word_199830;
  dword_19F7C8 = word_199832;
  dword_19F7BC = sub_79C54(word_199830, word_199832);
  word_1828BA = -1;
  v3 = *(int16_t *)(dword_1930D4 + 17 * dword_19F7BC);
  byte_182ACE = 1;
  dword_19F7A8 = v3;
  if ( byte_199CB4 )
  {
    v4 = *(char *)(361 * v3 + dword_192B18);
    a1 = 3753 * v4;
    sub_56460(v4, (char *)(3753 * v4 + dword_197F98 + 1301));
  }
  if ( word_199A08 != word_199A10 && !byte_1827BD )
    word_19DEA6 = word_199A10;
  dword_19F82C = dword_19F7B8;
  sub_AFBC1();
  v5 = (char *)&unk_1827AD;
  dword_19DE8C = (int)sub_110D3C(dword_192ED4, 2806);
  sub_120CCB(4, (int)&unk_1827AD);
  LOWORD(v6) = sub_120E8C(1);
  v7 = sub_BB954(v6, (int)&unk_1827AD);
  nullsub_7(v7, &unk_1827AD);
  sub_CDB3C();
  if ( !byte_1827BD )
  {
    v5 = 0;
    v9 = 361 * dword_19F7A8;
    do
    {
      v8 = (int16_t)v5;
      a1 = *(_WORD *)(v9 + dword_192B18 + 2 * (int16_t)v5++ + 277);
      word_1828AC[v8] = a1;
    }
    while ( (int16_t)v5 < 7 );
  }
  if ( !byte_1827BD )
    word_1828AA[0] = -1;
  sub_AFEFC(v8, (int)v5, a1);
  sub_AFF9E();
  if ( !byte_1827BD )
    word_19DEAC = *(uint8_t *)(361 * dword_19F7A8 + dword_192B18 + 297);
  sub_BC30B((int16_t)dword_19F7A8, 0);
  if ( sub_C5C85() )
  {
    sub_C5BB9();
    sub_BF55A();
  }
  sub_11C2F0();
  sub_B3E7A();
  byte_182ACA = 1;
  sub_1191CA((int)sub_B3CF7, 1);
  sub_CDB3C();
  v10 = 255;
  sub_131922(0, 255);
  sub_B3CF7();
  sub_C5C44();
  sub_124C08();
  do
  {
    sub_B3CF7();
    v12 = sub_1077D(v11, v10, a1, a2);
    v13 = sub_1171AB(v12, v10, a1, v2);
    v10 = (int)&v16;
    v15 = v13;
    v16 = sub_114177();
    sub_B2542((int16_t *)&v15, (int16_t *)&v16, (int)a2);
  }
  while ( (_WORD)v15 != word_19DE96
       && (_WORD)v15 != word_19DE90
       && (_WORD)v15 != word_19DE92
       && !byte_1827BD
       && (_WORD)v15 != word_19DEA2
       && (_WORD)v15 != word_19DEA0 );
  sub_11C2F0();
  if ( word_1828AA[0] != -1 )
    sub_C0AF4();
  sub_120E8C(3);
  sub_1196F7();
  sub_119281();
  sub_124E36();
  if ( (_WORD)v15 != word_19DEA2 && (_WORD)v15 != word_19DEA0 )
  {
    if ( byte_1827BD )
    {
      byte_199EF2 = 1;
      v14 = word_199A08;
      word_199A08 = 3;
LABEL_31:
      word_199A10 = v14;
      goto LABEL_32;
    }
    if ( word_199A08 == word_199A10 )
    {
      v14 = word_19DEA6;
      word_199A08 = word_19DEA6;
      goto LABEL_31;
    }
    word_199A08 = word_199A10;
  }
LABEL_32:
  sub_124820(v2);
  JUMPOUT(0xB065D);
}
// B4328: control flows out of bounds to B065D
// B4145: variable 'v6' is possibly undefined
// B419D: variable 'v8' is possibly undefined
// B4234: variable 'v11' is possibly undefined
// BB9FD: using guessed type int __fastcall nullsub_7(_DWORD, _DWORD);
// 1827BD: using guessed type char byte_1827BD;
// 1828AA: using guessed type int16_t word_1828AA[];
// 1828AC: using guessed type int16_t word_1828AC[];
// 1828BA: using guessed type int16_t word_1828BA;
// 182ACA: using guessed type char byte_182ACA;
// 182ACE: using guessed type char byte_182ACE;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199CB4: using guessed type char byte_199CB4;
// 199EF2: using guessed type char byte_199EF2;
// 19DE8C: using guessed type int dword_19DE8C;
// 19DE90: using guessed type int16_t word_19DE90;
// 19DE92: using guessed type int16_t word_19DE92;
// 19DE96: using guessed type int16_t word_19DE96;
// 19DEA0: using guessed type int16_t word_19DEA0;
// 19DEA2: using guessed type int16_t word_19DEA2;
// 19DEA6: using guessed type int16_t word_19DEA6;
// 19DEAC: using guessed type int16_t word_19DEAC;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F7B8: using guessed type int dword_19F7B8;
// 19F7BC: using guessed type int dword_19F7BC;
// 19F7C8: using guessed type int dword_19F7C8;
// 19F82C: using guessed type int dword_19F82C;


//----- (000B432D) --------------------------------------------------------
unsigned int sub_B432D()
{
  _BYTE *v0; // eax
  unsigned int result; // eax

  v0 = (_BYTE *)sub_CDF5C(12);
  result = sub_11438B(0, 0, 639, 479, v0, 0);
  word_19DEBE = result;
  return result;
}
// 19DEBE: using guessed type int16_t word_19DEBE;


//----- (000B435A) --------------------------------------------------------
_DWORD *sub_B435A()
{
  _DWORD *result; // eax

  result = sub_126B42((int)aColonyLbx, 1, dword_192ED4);
  dword_19DEB0 = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 19DEB0: using guessed type int dword_19DEB0;


//----- (000B4379) --------------------------------------------------------
void sub_B4379()
{
  sub_11C2F0();
  JUMPOUT(0xB4330);
}
// B4381: control flows out of bounds to B4330


//----- (000B4383) --------------------------------------------------------
_BYTE *__fastcall sub_B4383( int a1)
{
  _BYTE *result; // eax

  result = sub_1331D2(a1, (int)&dword_19DEC0, 15, 25);
  --word_19DEBC;
  return result;
}
// 19DEBC: using guessed type int16_t word_19DEBC;
// 19DEC0: using guessed type int dword_19DEC0;


//----- (000B43A6) --------------------------------------------------------
unsigned int sub_B43A6()
{
  int16_t v0; // cx
  unsigned int result; // eax
  int16_t v2; // dx
  char v3; // bl
  char v4; // bh
  int16_t i; // si
  char v6; // [esp+4h] [ebp-4h]

  v0 = -1;
  result = dword_19DEB8;
  v6 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  if ( *(int16_t *)(dword_19DEB8 + 3) + *(int16_t *)(dword_19DEB8 + 6) )
  {
    if ( *(int16_t *)(dword_19DEB8 + 3) > 0 )
    {
      for ( i = 0; i < 49; ++i )
      {
        if ( *(_BYTE *)(dword_19DEB8 + i + 14) )
        {
          if ( sub_1247A0(++v2) == 1 )
          {
            v6 = 1;
            v3 = 0;
            v0 = i;
            v4 = 0;
          }
        }
        if ( !*(_WORD *)(dword_19DEB8 + 3) )
          break;
      }
      if ( *(int16_t *)(dword_19DEB8 + 8) > 0 && sub_1247A0(++v2) == 1 )
      {
        v0 = 22;
        v3 = 0;
        v6 = 0;
        v4 = 1;
      }
      if ( *(int16_t *)(dword_19DEB8 + 10) > 0 && sub_1247A0(++v2) == 1 )
      {
        v0 = 2;
        v3 = 0;
        v6 = 0;
        v4 = 2;
      }
      if ( *(int16_t *)(dword_19DEB8 + 12) > 0 && sub_1247A0(++v2) == 1 )
      {
        v0 = 14;
        v3 = 0;
        v6 = 0;
        v4 = 0;
      }
    }
    result = dword_19DEB8;
    if ( *(int16_t *)(dword_19DEB8 + 6) > 0 )
    {
      result = sub_1247A0(++v2);
      if ( result == 1 )
      {
        v0 = -1;
        v3 = 1;
        v6 = 0;
        v4 = 3;
      }
    }
    if ( v2 > 0 )
      return sub_B4733(v0, v6, v3, v4);
  }
  return result;
}
// 19DEB8: using guessed type int dword_19DEB8;


//----- (000B44EB) --------------------------------------------------------
unsigned int __fastcall sub_B44EB( int a1)
{
  sub_1331D2(a1, (int)&dword_19DEC0, 15, 25);
  --word_19DEBC;
  return sub_B43A6();
}
// 19DEBC: using guessed type int16_t word_19DEBC;
// 19DEC0: using guessed type int dword_19DEC0;


//----- (000B4523) --------------------------------------------------------
int __fastcall sub_B4523( int a1)
{
  int result; // eax

  result = 15 * a1;
  switch ( byte_19DECD[result] )
  {
    case 0:
      if ( *(int16_t *)((char *)&word_19DECB + result) == 3
        || *(int16_t *)((char *)&word_19DECB + result) == 14
        || *(int16_t *)((char *)&word_19DECB + result) == 40
        || *(int16_t *)((char *)&word_19DECB + result) == 41 )
      {
        --*(_WORD *)(dword_19DEB8 + 12);
      }
      if ( byte_19DECA[15 * a1] )
        *(_BYTE *)(*(int16_t *)((char *)&word_19DECB + 15 * a1) + dword_19DEB8 + 14) = 0;
      result = dword_19DEB8;
      goto LABEL_10;
    case 1:
      result = dword_19DEB8;
      --*(_WORD *)(dword_19DEB8 + 8);
      goto LABEL_10;
    case 2:
      result = dword_19DEB8;
      --*(_WORD *)(dword_19DEB8 + 10);
LABEL_10:
      --*(_WORD *)(result + 3);
      break;
    case 3:
      result = dword_19DEB8;
      --*(_WORD *)(dword_19DEB8 + 6);
      break;
    default:
      return result;
  }
  return result;
}
// 19DEB8: using guessed type int dword_19DEB8;
// 19DECB: using guessed type int16_t word_19DECB;


//----- (000B45D4) --------------------------------------------------------
int __fastcall sub_B45D4( int a1)
{
  int result; // eax

  result = 15 * a1;
  if ( !byte_19DECD[result] )
  {
    if ( byte_19DECA[result] )
      LOWORD(result) = sub_BB39F(*(int16_t *)((char *)&word_19DECB + result));
  }
  return result;
}
// 19DECB: using guessed type int16_t word_19DECB;


//----- (000B4606) --------------------------------------------------------
void __fastcall sub_B4606( int a1)
{
  int v2; // esi
  int16_t v3; // dx

  v2 = 15 * a1;
  v3 = *(_WORD *)(*(int *)((char *)&dword_19DEC0 + v2) + 6);
  if ( byte_19DECE[v2] )
  {
    if ( *(int16_t *)((char *)&word_19DEC8 + 15 * a1) >= v3 )
    {
      sub_B4383(a1);
      sub_B43A6();
    }
    else
    {
      sub_12B753(*(int *)((char *)&dword_19DEC0 + 15 * a1), ++*(int16_t *)((char *)&word_19DEC8 + 15 * a1));
      sub_128AB6(0, 0, 639, 479);
      sub_12B634();
      sub_12A478(
        *(int16_t *)((char *)&word_19DEC4 + v2),
        *(int16_t *)((char *)&word_19DEC6 + v2),
        *(int *)((char *)&dword_19DEC0 + v2));
      sub_12B65C();
    }
  }
  else if ( sub_1247A0(5u) == 1 )
  {
    byte_19DECE[v2] = 1;
  }
  if ( *(int16_t *)((char *)&word_19DEC8 + 15 * a1) > v3 - 1 )
    sub_B45D4(a1);
  JUMPOUT(0xB44D8);
}
// B46CA: control flows out of bounds to B44D8
// 19DEC0: using guessed type int dword_19DEC0;
// 19DEC4: using guessed type int16_t word_19DEC4;
// 19DEC6: using guessed type int16_t word_19DEC6;
// 19DEC8: using guessed type int16_t word_19DEC8;


//----- (000B46CF) --------------------------------------------------------
void sub_B46CF()
{
  int16_t v0; // bx
  int v1; // eax
  int16_t v2; // cx
  int16_t i; // dx
  int16_t j; // dx

  if ( word_19DEBC < 1 )
  {
    v0 = *(_WORD *)(dword_19DEB8 + 6) + *(_WORD *)(dword_19DEB8 + 3);
    v1 = v0 / 2;
    if ( v1 >= 25 )
      LOWORD(v1) = 25;
    v2 = v1;
    if ( v0 < 8 )
      v2 = *(_WORD *)(dword_19DEB8 + 6) + *(_WORD *)(dword_19DEB8 + 3);
    for ( i = 0; i < v2; ++i )
      sub_B43A6();
  }
  for ( j = 0; j < word_19DEBC; ++j )
    sub_B4606(j);
}
// 19DEB8: using guessed type int dword_19DEB8;
// 19DEBC: using guessed type int16_t word_19DEBC;


//----- (000B4733) --------------------------------------------------------
int __fastcall sub_B4733( int a1, int a2, int a3, int a4)
{
  _BOOL2 v5; // di
  int16_t v6; // dx
  int v7; // eax
  int v8; // eax
  int result; // eax
  int16_t v10; // [esp+0h] [ebp-10h] BYREF
  int16_t v11; // [esp+4h] [ebp-Ch] BYREF
  char v12; // [esp+8h] [ebp-8h]
  char v13; // [esp+Ch] [ebp-4h]

  v13 = a2;
  v12 = a3;
  v5 = sub_BBD37(a1, &v10, &v11);
  *(int16_t *)((char *)&word_19DEC4 + 15 * word_19DEBC) = sub_BC866(v10, v11, 0) - 563;
  v6 = sub_BC866(v10, v11, 1);
  v7 = 15 * word_19DEBC;
  *(int16_t *)((char *)&word_19DEC6 + v7) = v6 - 432;
  if ( v5 )
    byte_19DECA[v7] = v13;
  v8 = 15 * word_19DEBC;
  *(int16_t *)((char *)&word_19DEC8 + v8) = 0;
  byte_19DECE[v8] = 0;
  *(int16_t *)((char *)&word_19DECB + v8) = a1;
  byte_19DECD[v8] = a4;
  *(int *)((char *)&dword_19DEC0 + v8) = dword_19DEB0;
  result = sub_B4523(word_19DEBC);
  ++word_19DEBC;
  return result;
}
// 19DEB0: using guessed type int dword_19DEB0;
// 19DEBC: using guessed type int16_t word_19DEBC;
// 19DEC0: using guessed type int dword_19DEC0;
// 19DEC4: using guessed type int16_t word_19DEC4;
// 19DEC6: using guessed type int16_t word_19DEC6;
// 19DEC8: using guessed type int16_t word_19DEC8;
// 19DECB: using guessed type int16_t word_19DECB;


//----- (000B4800) --------------------------------------------------------
void sub_B4800()
{
  int v0; // eax
  int v1; // eax
  char *v2; // eax
  int64_t v3; // rax
  int16_t *v4; // [esp-4h] [ebp-1F8h]
  _BYTE v5[500]; // [esp+0h] [ebp-1F4h] BYREF

  sub_124D41();
  if ( byte_182ACA )
  {
    sub_128C32(0, 0, 639, 479, 0);
    v0 = sub_BBA8E(1);
    sub_12A478(0, 0, v0);
    v1 = sub_BBA8E(0);
    sub_12A478(0, 0, v1);
    sub_BB04E(4u);
    v4 = sub_77B28(*(_WORD *)(dword_192B18 + 361 * dword_19F7A8 + 2));
    v2 = (char *)sub_CDF5C(283);
    v3 = sprintf(v5, v2, v4);
    sub_1210FD(319, SWORD2(v3), (int)v5);
  }
  sub_BEBDC();
  if ( byte_182ACA )
  {
    sub_124DEC();
    sub_124C08();
    byte_182ACA = 0;
  }
  else
  {
    sub_B46CF();
    if ( word_19DEBC < 1 )
      sub_B4B51();
  }
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 19DEBC: using guessed type int16_t word_19DEBC;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B48EB) --------------------------------------------------------
int __usercall sub_B48EB(int a1)
{
  int16_t i; // bx
  int result; // eax

  for ( i = 0; i < 49; ++i )
  {
    result = dword_19DEB8;
    if ( *(_BYTE *)(i + dword_19DEB8 + 14) )
    {
      result = 361 * dword_19F7A8 + dword_192B18;
      if ( *(_BYTE *)(i + result + 310) )
      {
        sub_145EA(dword_19F7A8, i, a1);
        result = dword_19DEB8;
        *(_WORD *)(dword_19DEB8 + 3) = 0;
        word_19DEBC = 0;
        *(_WORD *)(result + 6) = 0;
      }
    }
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 19DEB8: using guessed type int dword_19DEB8;
// 19DEBC: using guessed type int16_t word_19DEBC;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B494B) --------------------------------------------------------
int16_t sub_B494B()
{
  char *v0; // eax
  int64_t v1; // rax
  int v2; // edx
  int16_t v3; // bx
  char *v4; // eax
  int64_t v5; // rax
  char *v6; // eax
  int64_t v7; // rax
  char *v8; // eax
  int64_t v9; // rax
  char *v10; // eax
  int64_t v11; // rax
  int16_t i; // si
  int64_t v13; // rax
  char *v14; // eax
  int64_t v15; // rax
  int v16; // eax
  int16_t *v18; // [esp-8h] [ebp-119Ch]
  char *v19; // [esp-8h] [ebp-119Ch]
  char *v20; // [esp-8h] [ebp-119Ch]
  int v21; // [esp-4h] [ebp-1198h]
  int v22; // [esp-4h] [ebp-1198h]
  int v23; // [esp-4h] [ebp-1198h]
  int v24; // [esp-4h] [ebp-1198h]
  int v25; // [esp-4h] [ebp-1198h]
  int16_t *v26; // [esp-4h] [ebp-1198h]
  int16_t *v27; // [esp-4h] [ebp-1198h]
  _BYTE v28[4000]; // [esp+0h] [ebp-1194h] BYREF
  char v29[500]; // [esp+FA0h] [ebp-1F4h] BYREF

  sub_BB04E(4u);
  sub_784A0(*(char *)dword_19DEB4, v29);
  v18 = sub_77B28(*(_WORD *)(361 * *(uint8_t *)(dword_19DEB4 + 1) + dword_192B18 + 2));
  v0 = (char *)sub_CDF5C(51);
  v1 = sprintf(v28, v0, v18, v29);
  v2 = v1 + HIDWORD(v1);
  v3 = 1;
  if ( *(_WORD *)(dword_19DEB4 + 12) )
  {
    v21 = *(int16_t *)(dword_19DEB4 + 12);
    v4 = (char *)sub_CDF5C(29);
    v3 = 2;
    v5 = sprintf(v2, v4, v21);
    v2 = v5 + HIDWORD(v5);
  }
  if ( *(_WORD *)(dword_19DEB4 + 8) )
  {
    v22 = *(int16_t *)(dword_19DEB4 + 8);
    v6 = (char *)sub_CDF5C(24);
    ++v3;
    v7 = sprintf(v2, v6, v22);
    v2 = v7 + HIDWORD(v7);
  }
  if ( *(_WORD *)(dword_19DEB4 + 10) )
  {
    v23 = *(int16_t *)(dword_19DEB4 + 10);
    v8 = (char *)sub_CDF5C(17);
    ++v3;
    v9 = sprintf(v2, v8, v23);
    v2 = v9 + HIDWORD(v9);
  }
  if ( *(_BYTE *)(dword_19DEB4 + 5) )
  {
    v24 = *(int16_t *)(dword_19DEB4 + 63);
    v10 = (char *)sub_CDF5C(27);
    ++v3;
    v11 = sprintf(v2, v10, v24);
    v2 = v11 + HIDWORD(v11);
  }
  for ( i = 0; i < 49 && v3 < 15; ++i )
  {
    if ( *(_BYTE *)(i + dword_19DEB4 + 14) )
    {
      if ( byte_199CAE == 4 )
      {
        v13 = sprintf(v2, "Edificio distrutto: %s", *(_UNKNOWN **)((char *)&off_17EB3D + 19 * i));
      }
      else
      {
        v25 = *(int *)((char *)&off_17EB3D + 19 * i);
        v19 = (char *)sub_CDF5C(55);
        v13 = sprintf(v2, v19, v25);
      }
      v2 = v13 + HIDWORD(v13);
      ++v3;
    }
  }
  if ( v3 > 15 )
  {
    v14 = (char *)sub_CDF5C(378);
    v15 = sprintf(v2, v14);
    v2 = v15 + HIDWORD(v15);
  }
  if ( *(_BYTE *)(dword_19DEB4 + 66) )
  {
    if ( byte_199CAE == 4 )
    {
      v26 = sub_77B28(*(_WORD *)(dword_192B18 + 361 * *(uint8_t *)(dword_19DEB4 + 1) + 2));
      sprintf(v2, "Perdita di:%s", v26);
    }
    else
    {
      v27 = sub_77B28(*(_WORD *)(361 * *(uint8_t *)(dword_19DEB4 + 1) + dword_192B18 + 2));
      v20 = (char *)sub_CDF5C(55);
      sprintf(v2, v20, v27);
    }
  }
  v16 = sub_CDF5C(498);
  return sub_A5EB2(v16, (int)v28);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 192B18: using guessed type int dword_192B18;
// 199CAE: using guessed type char byte_199CAE;
// 19DEB4: using guessed type int dword_19DEB4;


//----- (000B4B51) --------------------------------------------------------
void sub_B4B51()
{
  char *v0; // eax
  char *v1; // eax
  char *v2; // eax
  char *v3; // eax
  int v4; // esi
  char *v5; // eax
  int64_t v6; // rax
  int16_t v7; // cx
  int v8; // edi
  char *v9; // eax
  int64_t v10; // rax
  int16_t *v11; // [esp-8h] [ebp+76h]
  int v12; // [esp-4h] [ebp+7Ah]
  int v13; // [esp-4h] [ebp+7Ah]
  int v14; // [esp-4h] [ebp+7Ah]
  int v15; // [esp-4h] [ebp+7Ah]
  int v16; // [esp-4h] [ebp+7Ah]
  int v17; // [esp-4h] [ebp+7Ah]
  _BYTE v18[500]; // [esp+0h] [ebp+7Eh] BYREF

  sub_BB04E(4u);
  v12 = 3753 * *(char *)dword_19DEB4 + dword_197F98 + 21;
  v11 = sub_77B28(*(_WORD *)(dword_192B18 + 361 * *(uint8_t *)(dword_19DEB4 + 1) + 2));
  v0 = (char *)sub_CDF5C(50);
  sprintf(v18, v0, v11, v12);
  sub_1212B3(20, 40, (int)v18);
  v13 = *(int16_t *)(dword_19DEB4 + 12);
  v1 = (char *)sub_CDF5C(28);
  sprintf(v18, v1, v13);
  sub_1212B3(20, 60, (int)v18);
  v14 = *(int16_t *)(dword_19DEB4 + 8);
  v2 = (char *)sub_CDF5C(34);
  sprintf(v18, v2, v14);
  sub_1212B3(20, 80, (int)v18);
  v15 = *(int16_t *)(dword_19DEB4 + 10);
  v3 = (char *)sub_CDF5C(33);
  sprintf(v18, v3, v15);
  sub_1212B3(20, 100, (int)v18);
  v4 = 4;
  if ( *(_BYTE *)(dword_19DEB4 + 5) )
  {
    v16 = *(int16_t *)(dword_19DEB4 + 63);
    v5 = (char *)sub_CDF5C(26);
    v6 = sprintf(v18, v5, v16);
    v4 = 5;
    sub_1212B3(20, SWORD2(v6), (int)v18);
  }
  v7 = 0;
  v8 = 20 * v4 + 40;
  while ( 1 )
  {
    if ( *(_BYTE *)(v7 + dword_19DEB4 + 14) )
    {
      v17 = *(int *)((char *)&off_17EB3D + 19 * v7);
      v9 = (char *)sub_CDF5C(54);
      ++v4;
      v10 = sprintf(v18, v9, v17);
      v8 += 20;
      sub_1212B3(20, SWORD2(v10), (int)v18);
    }
    if ( ++v7 >= 49 )
      JUMPOUT(0xB44D9);
  }
}
// B4CFD: control flows out of bounds to B44D9
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 19DEB4: using guessed type int dword_19DEB4;


//----- (000B4D02) --------------------------------------------------------
int16_t __fastcall sub_B4D02(_BYTE *a1)
{
  int16_t result; // ax
  _BYTE v2[76]; // [esp+0h] [ebp-4Ch] BYREF

  dword_19DEB8 = (int)a1;
  sub_12779E(v2, a1, 0x49u);
  dword_19DEB4 = (int)v2;
  sub_B494B();
  sub_BB16A(*(uint8_t *)(dword_19DEB8 + 1));
  result = word_199A10;
  word_199A08 = word_199A10;
  return result;
}
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 19DEB4: using guessed type int dword_19DEB4;
// 19DEB8: using guessed type int dword_19DEB8;


//----- (000B4E64) --------------------------------------------------------
int __fastcall sub_B4E64( int a1, int a2, int a3, int a4)
{
  int v4; // edi
  int v5; // esi
  int v6; // esi
  int result; // eax

  v4 = a2 - a1 - a4 / 3;
  if ( a3 <= 1 )
    v5 = 1;
  else
    v5 = a3;
  if ( (int16_t)v4 / v5 <= 1 )
  {
    result = 1;
  }
  else
  {
    if ( a3 <= 1 )
      v6 = 1;
    else
      v6 = a3;
    result = (int16_t)v4 / v6;
  }
  if ( (int16_t)result >= a4 )
    word_182AB9 = 0;
  else
    word_182AB9 = a4 - result;
  return result;
}
// 182AB9: using guessed type int16_t word_182AB9;


//----- (000B4EF6) --------------------------------------------------------
int __fastcall sub_B4EF6( int a1,
        int a2, int a3, int a4, int a5, int a6, int a7,
        int a8,
        _WORD *a9,
        int16_t *a10,
        _WORD *a11)
{
  int v11; // esi
  int16_t n; // di
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // ebx
  int16_t v19; // ax
  _BYTE *v20; // eax
  int v21; // eax
  int v23; // [esp-8h] [ebp-58h]
  _DWORD v25[2]; // [esp+10h] [ebp-40h]
  int64_t v26; // [esp+18h] [ebp-38h]
  int v27; // [esp+20h] [ebp-30h]
  int v28; // [esp+24h] [ebp-2Ch]
  int v29; // [esp+28h] [ebp-28h]
  int v30; // [esp+2Ch] [ebp-24h]
  int v31; // [esp+30h] [ebp-20h]
  int v32; // [esp+34h] [ebp-1Ch]
  int i; // [esp+38h] [ebp-18h]
  int j; // [esp+3Ch] [ebp-14h]
  int m; // [esp+40h] [ebp-10h]
  int v36; // [esp+44h] [ebp-Ch]
  int v37; // [esp+48h] [ebp-8h]
  int k; // [esp+4Ch] [ebp-4h]

  v25[0] = 9;
  v25[1] = 131073;
  v26 = *(_QWORD *)((char *)&dword_B4D48[1] + 3);
  v27 = *(int *)((char *)&dword_B4D48[3] + 3);
  v11 = 0;
  if ( a3 != 2 )
    ((int __fastcall(*)())(void*)sub_B4EF6)(a5, a6, a7, a8, a9, a10, a11);
  if ( (int16_t)a2 == -1 )
  {
    v37 = 0;
    v36 = 3;
  }
  else
  {
    v37 = a2;
    v36 = a2 + 1;
  }
  if ( !a3 && !(_WORD)a2 && !*(_BYTE *)(dword_192B18 + 361 * a1 + 224) )
  {
    sub_BB04E(3u);
    v23 = sub_CDF5C(387);
    sub_10315D(v23, 2);
  }
  for ( i = 0; (int16_t)i < 7; ++i )
  {
    for ( j = 0; (int16_t)j < 2; ++j )
    {
      for ( k = v37; (int16_t)k < (int16_t)v36; ++k )
      {
        for ( m = 0; (int16_t)m < 10; ++m )
        {
          for ( n = 0; ; ++n )
          {
            v31 = 361 * a1;
            if ( n >= *(uint8_t *)(v31 + dword_192B18 + 10) )
              break;
            v28 = *(_DWORD *)(4 * n + v31 + dword_192B18 + 12) & 0xF;
            v13 = *((int16_t *)v25 + (int16_t)m);
            v30 = 4 * n;
            if ( v13 == v28 && (uint16_t)sub_BCACF(a1, n) == (_WORD)i )
            {
              v14 = v30 + v31 + dword_192B18;
              v28 = *(_DWORD *)(v14 + 12) << 23 >> 30;
              v29 = (int16_t)k;
              if ( v28 == (int16_t)k
                && (*(_BYTE *)(v14 + 13) & 2) != 0
                && *(_DWORD *)(v14 + 12) << 21 >> 31 == (int16_t)j )
              {
                switch ( a3 )
                {
                  case 0:
                    sub_BB04E(2u);
                    if ( n == word_182ABC && word_182AB7 == a1 && (uint16_t)sub_C5D97(30, 2) )
                    {
                      v32 = v11 * (uint16_t)(30 - word_182AB9);
                      sub_BA90B(v32 + a4, a5, a1, n);
                    }
                    else
                    {
                      v15 = sub_BB4A9(a1, n);
                      sub_12A478(a4 + v11 * (30 - word_182AB9), a5, v15);
                    }
                    ++v11;
                    continue;
                  case 1:
                    v16 = 2 * (int16_t)v11++;
                    *(_WORD *)(a8 + v16) = n;
                    continue;
                  case 2:
                    goto LABEL_39;
                  case 3:
                    if ( a4 + ((int16_t)v11 + 1) * (30 - word_182AB9) < *a10 && (_WORD)v11 != *a9 )
                      goto LABEL_39;
                    LOWORD(v11) = *(_WORD *)(a8 + 2 * (int16_t)v11);
                    if ( byte_182978 )
                      sub_6497C();
                    return v11;
                  case 4:
                    if ( a4 + ((int16_t)v11 + 1) * (30 - word_182AB9) >= sub_123ABA() || (_WORD)v11 == *a9 )
                    {
                      LOWORD(v11) = *(_WORD *)(a8 + 2 * (int16_t)v11);
                      return v11;
                    }
LABEL_39:
                    ++v11;
                    break;
                  default:
                    continue;
                }
              }
            }
          }
        }
      }
    }
  }
  switch ( a3 )
  {
    case 0:
      if ( a7 )
      {
        if ( !(_WORD)a2 )
        {
          v17 = 361 * a1 + dword_192B18;
          if ( *(_BYTE *)(v17 + 224) != 0xFF && (int16_t)v11 < *(uint8_t *)(v17 + 224) )
          {
            sub_C0B09();
            while ( (int16_t)v11 < *(uint8_t *)(dword_192B18 + 361 * a1 + 224) )
            {
              v18 = sub_C0B81();
              v19 = a4 + v11 * (30 - word_182AB9);
              LOWORD(v11) = v11 + 1;
              sub_12A478(v19, a5, v18);
            }
          }
        }
      }
      goto LABEL_54;
    case 1:
      *a9 = v11 - 1;
      v20 = (_BYTE *)sub_CDF5C(12);
      *a11 = sub_115478(a4, a5, a4, a6 + 8, a4, a6, a6 - a4 + 8, 30, (int)a10, v20, 0);
      goto LABEL_54;
    case 2:
      if ( a7 )
      {
        if ( !(_WORD)a2 )
        {
          v21 = dword_192B18 + 361 * a1;
          if ( *(_BYTE *)(v21 + 224) != 0xFF )
            LOWORD(v11) = *(uint8_t *)(v21 + 224);
        }
      }
      sub_B4E64(a4, a6, v11, 30);
      return -1;
    case 3:
    case 4:
LABEL_54:
      sub_BC928();
      break;
    default:
      return -1;
  }
  return -1;
}
// B4D48: using guessed type int[4];
// 182978: using guessed type char byte_182978;
// 182AB7: using guessed type int16_t word_182AB7;
// 182AB9: using guessed type int16_t word_182AB9;
// 182ABC: using guessed type int16_t word_182ABC;
// 192B18: using guessed type int dword_192B18;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199CAE: using guessed type char byte_199CAE;


//----- (000B53B6) --------------------------------------------------------
int __fastcall sub_B53B6( int a1, int a2, int a3, int a4)
{
  return sub_B53CC(a1, a2, a3, a4, 0);
}


//----- (000B53C8) --------------------------------------------------------
void sub_B53C8()
{
  JUMPOUT(0xB53B8);
}
// B53CA: control flows out of bounds to B53B8


//----- (000B53CC) --------------------------------------------------------
int __fastcall sub_B53CC( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v6; // si
  uint16_t v7; // cx
  int v8; // eax
  int result; // eax
  int16_t v10; // cx
  int16_t i; // di
  int v12; // eax
  int v13; // eax
  int16_t v14; // bx
  int16_t v15; // dx
  int v16; // [esp+0h] [ebp-20h]
  int16_t v18; // [esp+10h] [ebp-10h]
  int16_t v20; // [esp+18h] [ebp-8h]

  v6 = a2;
  v16 = 361 * a1;
  v18 = *(char *)(v16 + dword_192B18 + 7) / 2;
  v7 = abs16(v18);
  v20 = v7;
  if ( *(char *)(dword_197F98 + 3753 * *(char *)(v16 + dword_192B18) + 2207) >= 6 )
    v20 = v7 - abs16(*(char *)(v16 + dword_192B18 + 7) / 2);
  if ( !a5 )
  {
    sub_BBB8A();
    v6 = a2 + 30;
    sub_12A478(a2, a3 - 1, v8);
  }
  sub_B4E64(v6, a4, v20, 30);
  result = 3753 * *(char *)(dword_192B18 + 361 * a1);
  if ( *(char *)(dword_197F98 + result + 2207) < 6 )
  {
    v10 = 0;
    for ( i = 0; ; ++i )
    {
      if ( abs16(v18) >= 0x14u )
        result = 20;
      else
        result = abs16(v18);
      if ( i >= result )
        return result;
      if ( v18 <= 0 )
      {
        if ( a5 )
        {
          v12 = 9;
          goto LABEL_10;
        }
        v13 = sub_BBA8E(6);
        v14 = v6 + v10 * (30 - word_182AB9);
        v15 = a3 + 2;
      }
      else
      {
        if ( a5 )
        {
          v12 = 8;
LABEL_10:
          v13 = sub_BBA8E(v12);
          v14 = v6 + v10 * (30 - word_182AB9);
          v15 = a3 + 1;
          goto LABEL_15;
        }
        v13 = sub_BBA8E(5);
        v14 = v6 + v10 * (30 - word_182AB9);
        v15 = a3 + 2;
      }
LABEL_15:
      sub_12A478(v14, v15, v13);
      ++v10;
    }
  }
  return result;
}
// B5481: variable 'v8' is possibly undefined
// 182AB9: using guessed type int16_t word_182AB9;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000B55A3) --------------------------------------------------------
void __fastcall sub_B55A3( int a1, int a2, int a3, int a4, int a5, int a6)
{
  sub_B55CF(a1, a2, a3, a4, a5, a6, 0);
}


//----- (000B55C7) --------------------------------------------------------
void __stdcall sub_B55C7(int a1, int a2)
{
  JUMPOUT(0xB55A9);
}
// B55CD: control flows out of bounds to B55A9


//----- (000B55CF) --------------------------------------------------------
void __fastcall sub_B55CF( int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // esi
  int v9; // ebx
  int v10; // ebx
  int v11; // eax
  int16_t v12; // ax
  int v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // ecx
  int v17; // ebx
  int v18; // eax
  int v19; // eax
  int16_t v20; // ax
  int16_t v21; // cx
  int v22; // ebx
  int16_t v23; // ax
  int16_t v24; // cx
  int v25; // ebx
  int16_t v26; // ax
  int16_t v27; // cx
  int v28; // eax
  int v29; // ebx
  int16_t v30; // cx
  int v31; // eax
  int v32; // ebx
  int16_t v33; // cx
  int v34; // ebx
  int16_t v35; // ax
  int16_t v36; // cx
  int v37; // ebx
  int16_t v38; // ax
  int v39; // esi
  int16_t v40; // cx
  int v41; // eax
  int v42; // ebx
  int16_t v43; // cx
  int v44; // eax
  int v45; // ebx
  int16_t v46; // cx
  int v47; // ebx
  int16_t v48; // ax
  int16_t v49; // cx
  int v50; // ebx
  int16_t v51; // ax
  int16_t v52; // cx
  int v53; // ebx
  int16_t v54; // ax
  int16_t v55; // cx
  int v56; // ebx
  int16_t v57; // ax
  int16_t v58; // [esp+0h] [ebp-48h]
  int v59; // [esp+1Ch] [ebp-2Ch]
  int v60; // [esp+20h] [ebp-28h]
  int v61; // [esp+24h] [ebp-24h]
  int v62; // [esp+28h] [ebp-20h]
  int v63; // [esp+2Ch] [ebp-1Ch]
  int v64; // [esp+30h] [ebp-18h]
  int v66; // [esp+40h] [ebp-8h]

  LOWORD(v60) = 0;
  LOWORD(v62) = 0;
  LOWORD(v66) = 0;
  LOWORD(v64) = 0;
  v8 = 0;
  if ( a2 != 1 )
  {
    v9 = 361 * a1;
    v62 = abs16(*(_WORD *)(v9 + dword_192B18 + 2 * a2 + 243)) / 10;
    v60 = abs16(*(_WORD *)(v9 + dword_192B18 + 2 * a2 + 243)) % 10;
  }
  if ( a2 )
  {
    if ( a2 != 1 )
      goto LABEL_8;
    LOWORD(v64) = *(int16_t *)(361 * v58 + dword_192B18 + 8) / 10;
    v11 = *(int16_t *)(361 * v58 + dword_192B18 + 8);
  }
  else
  {
    v10 = 361 * v58;
    v64 = abs16(*(_WORD *)(v10 + dword_192B18 + 245)) / 10;
    v11 = abs16(*(_WORD *)(v10 + dword_192B18 + 245));
  }
  v66 = v11 % 10;
LABEL_8:
  v12 = *(uint8_t *)(361 * v58 + dword_192B18 + a2 + 239)
      - (*(_WORD *)(361 * v58 + dword_192B18 + 2 * a2 + 231)
       + *(_WORD *)(361 * v58 + dword_192B18 + 2 * a2 + 243));
  if ( v12 <= 0 )
    v12 = 0;
  v59 = abs16(v12) / 10;
  v61 = abs16(v12) % 10;
  v13 = 361 * v58 + dword_192B18;
  if ( *(char *)(v13 + 2 * a2 + 243) >= 0 && (*(_BYTE *)(v13 + 240) && a2 == 1 ? (v14 = 0) : (v14 = 1), v14) )
  {
    LOWORD(v63) = *(int16_t *)(361 * v58 + dword_192B18 + 2 * a2 + 231) / 10;
    LOWORD(v15) = *(int16_t *)(361 * v58 + dword_192B18 + 2 * a2 + 231) % 10;
  }
  else if ( a2 == 1 )
  {
    v18 = *(int16_t *)(361 * v58 + dword_192B18 + 233) - *(uint8_t *)(361 * v58 + dword_192B18 + 240);
    if ( v18 <= 0 )
      v18 = 0;
    v63 = v18 / 10;
    v19 = *(int16_t *)(361 * v58 + dword_192B18 + 233) - *(uint8_t *)(361 * v58 + dword_192B18 + 240);
    if ( v19 <= 0 )
      v19 = 0;
    v15 = v19 % 10;
  }
  else
  {
    v16 = 361 * v58;
    v17 = 2 * a2;
    v63 = (*(int16_t *)(v17 + v16 + dword_192B18 + 231) - abs16(*(_WORD *)(v17 + v16 + dword_192B18 + 243))) / 10;
    v15 = (*(int16_t *)(v17 + v16 + dword_192B18 + 231) - abs16(*(_WORD *)(v17 + v16 + dword_192B18 + 243))) % 10;
  }
  v20 = v61 + v66 + v15 + v60;
  if ( *(_WORD *)(361 * v58 + dword_192B18 + 2 * a2 + 243) && a2 != 1 )
    ++v20;
  if ( (_WORD)v66 || (_WORD)v64 )
    ++v20;
  sub_B4E64(a3, a5, v64 + v63 + v62 + v59 + v20, a6);
  if ( word_182AB9 + 1 >= a6 )
  {
    word_182AB9 = a6 - 2;
    sub_128AB6(a3, a4 - 20, a5, (int16_t)(a4 + 20));
    sub_12B634();
  }
  v21 = 0;
  while ( v21 < (int16_t)v63 )
  {
    ++v21;
    v22 = sub_BBC46(a2, 1, a7);
    v23 = v8++ * (a6 - word_182AB9) + a3;
    sub_12A478(v23, a4, v22);
  }
  v24 = 0;
  while ( v24 < (int16_t)v15 )
  {
    ++v24;
    v25 = sub_BBC46(a2, 0, a7);
    v26 = v8++ * (a6 - word_182AB9) + a3;
    sub_12A478(v26, a4, v25);
  }
  if ( (_WORD)v64 || (_WORD)v66 )
  {
    if ( a2 == 1 )
    {
      v27 = 0;
      while ( v27 < (int16_t)v64 )
      {
        sub_BBC6F();
        ++v27;
        v29 = v28;
        LOWORD(v28) = v8++ * (a6 - word_182AB9) + a3;
        sub_12A478(v28, a4, v29);
      }
      v30 = 0;
      while ( v30 < (int16_t)v66 )
      {
        sub_BBC6F();
        ++v30;
        v32 = v31;
        LOWORD(v31) = v8++ * (a6 - word_182AB9) + a3;
        sub_12A478(v31, a4, v32);
      }
    }
    else if ( !a2 )
    {
      v33 = 0;
      while ( v33 < (int16_t)v64 )
      {
        ++v33;
        v34 = sub_BBC46(1, 1, a7);
        v35 = v8++ * (a6 - word_182AB9) + a3;
        sub_12A478(v35, a4, v34);
      }
      v36 = 0;
      while ( v36 < (int16_t)v66 )
      {
        ++v36;
        v37 = sub_BBC46(1, 0, a7);
        v38 = v8++ * (a6 - word_182AB9) + a3;
        sub_12A478(v38, a4, v37);
      }
    }
    ++v8;
  }
  v39 = v8 + 1;
  if ( *(int16_t *)(361 * v58 + dword_192B18 + 2 * a2 + 243) <= 0 || a2 == 1 )
  {
    v52 = 0;
    while ( v52 < (int16_t)v62 )
    {
      ++v52;
      v53 = sub_BBC46(a2, 1, a7);
      v54 = v39++ * (a6 - word_182AB9) + a3;
      sub_12A478(v54, a4, v53);
    }
    v55 = 0;
    while ( v55 < (int16_t)v60 )
    {
      ++v55;
      v56 = sub_BBC46(a2, 0, a7);
      v57 = v39++ * (a6 - word_182AB9) + a3;
      sub_12A478(v57, a4, v56);
    }
  }
  else
  {
    v40 = 0;
    while ( v40 < (int16_t)v62 )
    {
      sub_BBC6F();
      ++v40;
      v42 = v41;
      LOWORD(v41) = v39++ * (a6 - word_182AB9) + a3;
      sub_12A478(v41, a4, v42);
    }
    v43 = 0;
    while ( v43 < (int16_t)v60 )
    {
      sub_BBC6F();
      ++v43;
      v45 = v44;
      LOWORD(v44) = v39++ * (a6 - word_182AB9) + a3;
      sub_12A478(v44, a4, v45);
    }
    v46 = 0;
    while ( v46 < (int16_t)v59 )
    {
      ++v46;
      v47 = sub_BBC8B();
      v48 = v39++ * (a6 - word_182AB9) + a3;
      sub_12A478(v48, a4, v47);
    }
    v49 = 0;
    while ( v49 < (int16_t)v61 )
    {
      ++v49;
      v50 = sub_BBC8B();
      v51 = v39++ * (a6 - word_182AB9) + a3;
      sub_12A478(v51, a4, v50);
    }
  }
  sub_12B65C();
}
// B5670: variable 'v58' is possibly undefined
// B5AD5: variable 'v28' is possibly undefined
// B5B3C: variable 'v31' is possibly undefined
// B5CB1: variable 'v41' is possibly undefined
// B5D16: variable 'v44' is possibly undefined
// 182AB9: using guessed type int16_t word_182AB9;
// 192B18: using guessed type int dword_192B18;


//----- (000B5ED2) --------------------------------------------------------
void __fastcall sub_B5ED2( int a1, int a2, int a3, int a4)
{
  int16_t v4; // ax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v11; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h]

  if ( a3 >= 1000 )
    v4 = a3;
  else
    v4 = 1000;
  if ( a4 > a3 )
    a4 = a3;
  v11 = 50 * a4 / v4;
  v12 = -50 * (a3 - a4) / v4 + 50;
  v5 = -10 * (v4 - a4) / v4 + 10 + (int16_t)(((a3 - a4) << 6) / v4 - (a3 << 6) / v4);
  sub_128AB6(0, 0, 639, 479);
  sub_12B634();
  v6 = sub_BBA8E(35);
  sub_12B753(v6, (int16_t)v11);
  v7 = sub_BBA8E(35);
  sub_12A478(a1, a2, v7);
  v8 = sub_BBA8E(34);
  sub_12B753(v8, (int16_t)v12);
  v9 = sub_BBA8E(34);
  sub_12A478(a1, a2 + v5, v9);
  sub_12B65C();
}


//----- (000B5FBE) --------------------------------------------------------
uint8_t sub_B5FBE()
{
  int v0; // esi
  uint8_t result; // al
  int16_t i; // bx
  int16_t j; // dx

  memset(&unk_19E564, 0, 1421);
  v0 = 0;
  for ( result = 0; result < 4u; ++result )
  {
    for ( i = 0; i < 7; ++i )
    {
      for ( j = 0; j < 7; ++j )
      {
        if ( i == 6 && result || j == 6 && !result || result > 1u && (j == 6 || i == 6) )
        {
          *(int16_t *)((char *)&word_19E574 + 203 * i + 29 * j + 2 * result) = -1;
          byte_19E57C[203 * i + 29 * j + result] = 0;
        }
        else
        {
          *(int16_t *)((char *)&word_19E574 + 203 * i + 29 * j + 2 * result) = v0++;
          byte_19E57C[203 * i + 29 * j + result] = 0;
        }
      }
    }
  }
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19E574: using guessed type int16_t word_19E574;


//----- (000B6099) --------------------------------------------------------
void sub_B6099()
{
  int v0; // edi
  int v1; // esi
  int v2; // ecx
  int v3; // edx
  int v4; // eax
  int v5; // edx
  int v6; // edx
  int v7; // edx
  int v8; // [esp+0h] [ebp-Ch] BYREF
  int v9; // [esp+4h] [ebp-8h] BYREF
  int v10; // [esp+8h] [ebp-4h] BYREF

  sub_B62D3();
  v0 = 0;
  while ( 1 )
  {
    v1 = 0;
    do
    {
      v2 = 203 * (int16_t)v0;
      if ( dword_182AFD[6 * (int16_t)v0 + (int16_t)v1] )
      {
        v3 = v2 + 29 * (int16_t)v1;
        if ( sub_1247A0(2u) == 1 )
          byte_19E57C[v3] = 1;
        else
          byte_19E57D[v3] = 1;
        if ( sub_1247A0(2u) != 1 )
          byte_19E57C[203 * (int16_t)v0 + 203 + 29 * (int16_t)v1] = 1;
        if ( sub_1247A0(2u) != 1 )
          byte_19E57D[203 * (int16_t)v0 + 29 + 29 * (int16_t)v1] = 1;
        v4 = 203 * (int16_t)v0;
        v5 = 29 * ((int16_t)v1 + 1);
        byte_19E57E[v5 + v4] = 0;
        byte_19E57F[v5 + v4] = 0;
      }
      else
      {
        v6 = v2 + 29 * ((int16_t)v1 + 1);
        if ( byte_19E57E[v6] && byte_19E57F[v6] )
        {
          if ( sub_1247A0(2u) == 1 )
            byte_19E57F[v6] = 0;
          else
            byte_19E57E[v6] = 0;
        }
        if ( (uint16_t)sub_B67E4(v0, v1) == 4 )
        {
          v7 = 29 * (int16_t)v1 + 203 * (int16_t)v0;
          if ( byte_19E57E[v7] == 1 || byte_19E57F[v7] == 1 )
          {
            v10 = 0;
            v9 = v0;
            v8 = v1;
            if ( (uint16_t)sub_B6860(&v9, &v8, &v10, 4) )
              byte_19E57C[203 * (int16_t)v9 + 29 * (int16_t)v8 + (int16_t)v10] = 0;
          }
        }
      }
      ++v1;
    }
    while ( (int16_t)v1 < 6 );
    if ( (int16_t)++v0 >= 6 )
      JUMPOUT(0xB6092);
  }
}
// B6222: control flows out of bounds to B6092
// 182AFD: using guessed type int dword_182AFD[];


//----- (000B6227) --------------------------------------------------------
int16_t __fastcall sub_B6227( int a1, _WORD *a2, _WORD *a3)
{
  int16_t result; // ax
  _BYTE v4[100]; // [esp+0h] [ebp-64h] BYREF

  qmemcpy(v4, &byte_B4D5B, 0x62u);
  *a2 = (uint8_t)v4[2 * a1];
  result = (uint8_t)v4[2 * a1 + 1];
  *a3 = result;
  return result;
}
// B4D5B: using guessed type char byte_B4D5B;


//----- (000B6255) --------------------------------------------------------
void sub_B6255()
{
  int16_t v0; // si
  uint8_t i; // cl
  int v2; // edi
  int v3; // edx
  int v4; // eax
  int v5; // [esp+0h] [ebp-Ch]
  int16_t v6; // [esp+4h] [ebp-8h] BYREF
  int16_t v7; // [esp+8h] [ebp-4h] BYREF

  v0 = 0;
  v5 = 16777731;
  while ( 1 )
  {
    sub_B6227(v0, &v7, &v6);
    for ( i = 0; i < 4u; ++i )
    {
      v2 = 29 * v6 + 203 * v7;
      v3 = *((uint8_t *)&v5 + i);
      if ( byte_19E57C[v3 + v2] )
      {
        v4 = sub_127C27((int)aColroadsLbx, *(int16_t *)((char *)&word_19E574[v3] + v2), dword_193174);
        sub_12A478(0, 0, v4);
      }
    }
    if ( ++v0 >= 49 )
      JUMPOUT(0xB6092);
  }
}
// B62CE: control flows out of bounds to B6092
// 193174: using guessed type int dword_193174;
// 19E574: using guessed type int16_t word_19E574[4];


//----- (000B62D3) --------------------------------------------------------
void sub_B62D3()
{
  int16_t v0; // si
  int v1; // [esp+4h] [ebp-Ch] BYREF
  int v2; // [esp+8h] [ebp-8h] BYREF
  int v3; // [esp+Ch] [ebp-4h]

  v3 = -1;
  v0 = 36;
  while ( 1 )
  {
    sub_BEBAE(--v0, &v2, &v1);
    if ( dword_182AFD[6 * (int16_t)v2 + (int16_t)v1] )
    {
      if ( (int16_t)v3 == -1 )
        v3 = v2;
      else
        sub_B634B((int)&unk_19E538, (int)&unk_19E562);
    }
    if ( v0 <= 0 )
      JUMPOUT(0xB6092);
  }
}
// B6346: control flows out of bounds to B6092
// 182AFD: using guessed type int dword_182AFD[];


//----- (000B634B) --------------------------------------------------------
void __stdcall sub_B634B(int a1, int a2)
{
  ;
}


//----- (000B6352) --------------------------------------------------------
int __fastcall sub_B6352( int a1, int a2, int a3, int a4, int a5, int16_t *a6, int a7)
{
  int16_t i; // si
  int v8; // eax
  int16_t v9; // bx
  int16_t v10; // dx
  int16_t v11; // cx
  int16_t v12; // ax
  _BOOL1 v13; // al
  int v18; // [esp+10h] [ebp-3Ch]
  int64_t v19; // [esp+14h] [ebp-38h]
  int64_t v20; // [esp+1Ch] [ebp-30h]
  int v21; // [esp+24h] [ebp-28h]
  _DWORD v22[2]; // [esp+28h] [ebp-24h]
  int64_t v23; // [esp+30h] [ebp-1Ch]
  int16_t v24; // [esp+38h] [ebp-14h]
  int16_t v25; // [esp+3Ch] [ebp-10h]
  int16_t v26; // [esp+40h] [ebp-Ch]
  char v27; // [esp+44h] [ebp-8h]
  _BOOL1 v28; // [esp+48h] [ebp-4h]

  v22[0] = -65279;
  v22[1] = -16711169;
  v23 = *(_QWORD *)((char *)&dword_B4DC4[1] + 1);
  byte_19E580[203 * a1 + 29 * a2] = 1;
  v18 = -16646144;
  v19 = *(_QWORD *)((char *)&dword_B4DC4[4] + 1);
  v20 = *(_QWORD *)((char *)&dword_B4DC4[6] + 1);
  v21 = *(int *)((char *)&dword_B4DC4[8] + 1);
  v27 = 0;
  if ( *a6 == 13 )
    goto LABEL_30;
  for ( i = 0; ; ++i )
  {
    if ( i >= 8 )
    {
      if ( v27 )
        byte_19E580[203 * a1 + 29 * a2] = 0;
      goto LABEL_30;
    }
    v8 = 3 * i;
    v9 = a1 + *((char *)v22 + 2 * i);
    v10 = a2 + *((char *)v22 + 2 * i + 1);
    v25 = *((char *)&v18 + v8) + a1;
    v11 = *((char *)&v18 + v8 + 1);
    v12 = *((char *)&v18 + v8 + 2);
    v26 = v12;
    v24 = v11 + a2;
    if ( v9 <= 7
      && v10 <= 7
      && v9 >= 0
      && v10 >= 0
      && (v12 != 2 && v12 != 3 || !dword_182AFD[6 * v25 + v24])
      && (v26 != 3 || !byte_19E57E[203 * v25 + 29 * v24])
      && (v26 != 2 || !byte_19E57F[203 * v25 + 29 * v24])
      && !byte_19E580[203 * v9 + 29 * v10]
      && a7 <= *a6 )
    {
      v13 = byte_19E57C[203 * v25 + 29 * v24 + v26] == 0;
      v28 = v13;
      if ( v9 == a3 && v10 == a4 )
      {
        if ( a7 <= *a6 )
        {
          *a6 = 0;
          if ( v13 )
          {
            *(_BYTE *)(a5 + 3 * *a6) = v25;
            *(_BYTE *)(a5 + 3 * *a6 + 1) = v24;
            *(_BYTE *)(a5 + 3 * (*a6)++ + 2) = v26;
          }
LABEL_30:
          JUMPOUT(0xB5ECC);
        }
      }
      else if ( (uint8_t)((int __fastcall(*)())(void*)sub_B6352)(a5, a6, (int16_t)(a7 + v28)) )
      {
        if ( v28 )
        {
          *(_BYTE *)(a5 + 3 * *a6) = v25;
          *(_BYTE *)(a5 + 3 * *a6 + 1) = v24;
          *(_BYTE *)(a5 + 3 * (*a6)++ + 2) = v26;
        }
        v27 = 1;
      }
    }
  }
}
// B639D: control flows out of bounds to B5ECC
// B4DC4: using guessed type int dword_B4DC4[9];
// 182AFD: using guessed type int dword_182AFD[];


//----- (000B65D8) --------------------------------------------------------
int __fastcall sub_B65D8( int a1, int a2)
{
  return sub_127C27((int)aColveggiLbx, (int16_t)(8 * a2 + a1), dword_193174);
}
// 193174: using guessed type int dword_193174;


//----- (000B6647) --------------------------------------------------------
int __fastcall sub_B6647( int a1, int a2, int a3)
{
  int16_t v4; // si
  int v5; // ecx
  int v6; // eax

  v4 = sub_1247A0(8u);
  v5 = sub_B66D0(a1);
  v6 = (int16_t)(v4 - 1) - (a3 + a2) / 2;
  if ( v6 <= 0 )
    v6 = 0;
  return v6 + 8 * v5;
}


//----- (000B66D0) --------------------------------------------------------
int __fastcall sub_B66D0( int a1)
{
  int result; // eax

  switch ( *(_BYTE *)(17 * *(int16_t *)(dword_192B18 + 361 * a1 + 2) + dword_1930D4 + 8) )
  {
    case 0:
      if ( sub_1247A0(2u) == 1 )
        return 5;
      else
        return 9;
    case 1:
      if ( sub_1247A0(2u) != 1 )
        goto LABEL_19;
      goto LABEL_15;
    case 2:
      if ( sub_1247A0(2u) != 1 )
        goto LABEL_19;
LABEL_15:
      result = 6;
      break;
    case 3:
      return 8;
    case 5:
      switch ( sub_1247A0(4u) )
      {
        case 1u:
          result = 7;
          break;
        case 2u:
          return 9;
        case 3u:
          result = 11;
          break;
        default:
          goto LABEL_19;
      }
      return result;
    case 6:
      return 10;
    case 7:
      return 1;
    case 8:
    case 9:
      switch ( sub_1247A0(4u) )
      {
        case 1u:
          result = 12;
          break;
        case 2u:
          result = 3;
          break;
        case 3u:
          result = 0;
          break;
        case 4u:
          result = 2;
          break;
        default:
          goto LABEL_19;
      }
      return result;
    default:
LABEL_19:
      result = 4;
      break;
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;


//----- (000B67E4) --------------------------------------------------------
int __fastcall sub_B67E4( int a1, int a2)
{
  int v2; // edx
  int16_t v3; // bx
  int v4; // eax
  int16_t v5; // cx
  int v9; // [esp+8h] [ebp-10h]
  int64_t v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+14h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  v9 = 0;
  v10 = 0x100010001000100LL;
  do
  {
    v4 = 3 * v3;
    v5 = a2 + *((uint8_t *)&v9 + v4 + 1);
    v11 = 203 * (int16_t)(*((uint8_t *)&v9 + v4) + a1);
    if ( byte_19E57C[29 * v5 + v11 + *((uint8_t *)&v9 + v4 + 2)] )
      ++v2;
    ++v3;
  }
  while ( v3 < 4 );
  return v2;
}


//----- (000B6860) --------------------------------------------------------
int __fastcall sub_B6860(_WORD *a1, _WORD *a2, _WORD *a3, int a4)
{
  int v4; // edi
  char *v5; // esi
  int v6; // ecx
  int v7; // eax
  int v8; // esi
  int v9; // edi
  _WORD *v12; // [esp+4h] [ebp-34h]
  int v13; // [esp+8h] [ebp-30h]
  int64_t v14; // [esp+Ch] [ebp-2Ch]
  int v15; // [esp+14h] [ebp-24h] BYREF
  int v16; // [esp+18h] [ebp-20h]
  char *v17; // [esp+1Ch] [ebp-1Ch]
  char *v18; // [esp+20h] [ebp-18h]
  _WORD *v19; // [esp+24h] [ebp-14h]
  char *v20; // [esp+28h] [ebp-10h]
  int v21; // [esp+2Ch] [ebp-Ch]
  _WORD *v22; // [esp+30h] [ebp-8h]
  char *v23; // [esp+34h] [ebp-4h]

  v12 = a1;
  v13 = 0;
  v14 = 0x100010001000100LL;
  v5 = (char *)&unk_B4E01;
  v4 = (int)&v15;
  LOWORD(a1) = *a1;
  v20 = (char *)a1;
  LOWORD(a1) = *a2;
  v6 = 0;
  v23 = (char *)a1;
  LOWORD(a1) = *a3;
  v21 = 0;
  v19 = a1;
  while ( (int16_t)v21 < a4 )
  {
    v7 = 3 * (int16_t)v21;
    LOWORD(v5) = *((uint8_t *)&v13 + v7);
    v17 = v5;
    HIWORD(v8) = HIWORD(v12);
    LOWORD(v8) = *v12;
    v5 = &v17[v8];
    LOWORD(v4) = *((uint8_t *)&v13 + v7 + 2);
    v18 = v5;
    v22 = (_WORD *)v4;
    v9 = 203 * (int16_t)v5;
    LOWORD(v5) = *a2 + *((uint8_t *)&v13 + v7 + 1);
    v15 = v9;
    v16 = 29 * (int16_t)v5;
    v4 = v16 + v9;
    if ( (uint8_t)byte_19E57C[v4 + *((uint8_t *)&v13 + v7 + 2)] == *a3 && sub_1247A0((int16_t)++v6) == 1 )
    {
      v20 = v18;
      v23 = v5;
      v19 = v22;
    }
    ++v21;
  }
  *v12 = (_WORD)v20;
  *a2 = (_WORD)v23;
  *a3 = (_WORD)v19;
  return v6;
}


//----- (000B6932) --------------------------------------------------------
int sub_B6932()
{
  int16_t i; // bx
  int result; // eax
  int v2; // edx
  int v3; // ecx

  for ( i = 0; i < 6; ++i )
  {
    result = 0;
    do
    {
      v2 = 0;
      do
      {
        v3 = 3 * (int16_t)v2++;
        word_19E048[72 * i + 12 * (int16_t)result + v3] = 0;
      }
      while ( (int16_t)v2 < 2 );
      ++result;
    }
    while ( (int16_t)result < 6 );
  }
  return result;
}
// 19E048: using guessed type int16_t word_19E048[632];


//----- (000B6977) --------------------------------------------------------
void sub_B6977()
{
  int16_t v0; // ax
  int16_t v1; // cx
  int16_t v2; // ax
  int16_t v3; // dx
  int v4; // eax
  int v6; // ecx
  int v7; // esi
  _BOOL2 v8; // ax
  int16_t v9; // ax
  int16_t v10; // ax
  int v11; // ebx
  int16_t *v12; // ecx
  int16_t v13; // dx
  int16_t j; // [esp+Ch] [ebp-Ch]
  int16_t v15; // [esp+10h] [ebp-8h]
  int16_t i; // [esp+14h] [ebp-4h]

  v0 = sub_79C54(word_199830, word_199832);
  v15 = 0;
  sub_BA96D(*(_WORD *)(dword_1930D4 + 17 * v0));
  sub_B6932();
  while ( 1 )
  {
    for ( i = 0; i < 6; ++i )
    {
      if ( !dword_182AFD[6 * v15 + i] )
      {
        v1 = sub_B67E4(v15, i);
        v2 = sub_79C54(word_199830, word_199832);
        v3 = sub_BA96D(*(_WORD *)(dword_1930D4 + 17 * v2));
        if ( (int)(sub_1247A0(7u) - 2) < v1 || !v1 && sub_1247A0(v3 + 2) )
        {
          v4 = 29 * i + 203 * v15;
          if ( !byte_19E57E[v4] && !byte_19E57F[v4] )
          {
            for ( j = 0; j < 2; ++j )
            {
              v6 = 24 * i + 144 * v15;
              v7 = v6 + 6 * j;
              v8 = sub_1247A0(3u) == 1;
              *(int16_t *)((char *)word_19E048 + v7) = v8;
              if ( v8 )
              {
                v9 = sub_79C54(word_199830, word_199832);
                v10 = sub_B6647(*(_WORD *)(dword_1930D4 + 17 * v9), v15, i);
                v11 = dword_193174;
                *(int16_t *)((char *)&word_19E040[j] + v6) = v10;
                v12 = (int16_t *)sub_127C27((int)aColveggiLbx, v10, v11);
                v13 = sub_BC866(v15, i, 0);
                *(int16_t *)((char *)word_19E044 + v7) = sub_1247A0(*v12) + v13 - *v12 / 2;
                LOWORD(v11) = sub_BC866(v15, i, 1);
                *(int16_t *)((char *)word_19E046 + v7) = sub_1247A0(v12[1])
                                                       + v11
                                                       - ((int)(v12[1]
                                                              - (__CFSHL__((uint64_t)v12[1] >> 32, 2)
                                                               + 4 * ((uint64_t)v12[1] >> 32))) >> 2);
              }
            }
          }
        }
      }
    }
    if ( ++v15 >= 6 )
      JUMPOUT(0xB6092);
  }
}
// B6B90: control flows out of bounds to B6092
// 182AFD: using guessed type int dword_182AFD[];
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 19E040: using guessed type int16_t word_19E040[];
// 19E044: using guessed type int16_t word_19E044[];
// 19E046: using guessed type int16_t word_19E046[];
// 19E048: using guessed type int16_t word_19E048[632];


//----- (000B6B95) --------------------------------------------------------
void __fastcall sub_B6B95( int a1, int a2, unsigned int a3)
{
  int16_t j; // di
  int v4; // ecx
  int16_t *v5; // ebx
  int16_t i; // [esp+10h] [ebp-8h]

  for ( i = a3; i >= 0; --i )
  {
    for ( j = 0; j < 2; ++j )
    {
      if ( word_19E048[72 * a1 + 12 * a2 + 3 * j] )
      {
        sub_128AB6(0, 0, 639, 479);
        sub_12B634();
        if ( a3 && a3 == i )
        {
          sub_127C27((int)aColveggiLbx, word_19E040[72 * a1 + 12 * a2 + j], dword_193174);
          sub_C5D55();
        }
        else
        {
          v4 = 144 * a1 + 24 * a2;
          v5 = (int16_t *)sub_127C27((int)aColveggiLbx, *(int16_t *)((char *)&word_19E040[j] + v4), dword_193174);
          sub_C5D75(*(int16_t *)((char *)&word_19E044[3 * j] + v4), *(int16_t *)((char *)&word_19E046[3 * j] + v4), v5);
        }
        sub_12B65C();
      }
    }
  }
}
// 193174: using guessed type int dword_193174;
// 19E040: using guessed type int16_t word_19E040[];
// 19E044: using guessed type int16_t word_19E044[];
// 19E046: using guessed type int16_t word_19E046[];
// 19E048: using guessed type int16_t word_19E048[632];


//----- (000B6D05) --------------------------------------------------------
unsigned int sub_B6D05()
{
  _BYTE *v0; // eax
  _BYTE *v1; // eax
  unsigned int result; // eax

  v0 = (_BYTE *)sub_CDF5C(12);
  word_19F380 = sub_11438B(0, 0, 639, 479, v0, 0);
  v1 = (_BYTE *)sub_CDF5C(135);
  result = sub_114C72(v1, 0);
  word_19F382 = result;
  return result;
}
// 19F380: using guessed type int16_t word_19F380;
// 19F382: using guessed type int16_t word_19F382;


//----- (000B6D47) --------------------------------------------------------
void sub_B6D47()
{
  sub_11C2F0();
  JUMPOUT(0xB6D08);
}
// B6D4F: control flows out of bounds to B6D08


//----- (000B6D51) --------------------------------------------------------
_DWORD *sub_B6D51()
{
  _DWORD *v0; // eax
  int v1; // edx
  _DWORD *result; // eax

  dword_19F364 = (int)sub_126B42((int)aColonyLbx, 7, dword_192ED4);
  dword_19EB14 = (int)sub_126B42((int)aColgcbtLbx, 0, dword_192ED4);
  dword_19EB08 = (int)sub_126B42((int)aColgcbtLbx, 1, dword_192ED4);
  dword_19EB10 = (int)sub_126B42((int)aColgcbtLbx, 2, dword_192ED4);
  dword_19EB18 = (int)sub_126B42((int)aColgcbtLbx, 3, dword_192ED4);
  dword_19EB0C = (int)sub_126B42((int)aColgcbtLbx, 4, dword_192ED4);
  sub_B8EFB(dword_19EB14, *(_WORD *)dword_19F378);
  sub_B8EFB(dword_19EB08, *(_WORD *)dword_19F378);
  sub_B8EFB(dword_19EB10, *(_WORD *)dword_19F378);
  sub_B8EFB(dword_19EB18, *(_WORD *)dword_19F378);
  sub_B8EFB(dword_19EB0C, *(_WORD *)dword_19F378);
  dword_19EB28 = dword_19EB14;
  dword_19EB1C = dword_19EB08;
  dword_19EB24 = dword_19EB10;
  dword_19EB2C = dword_19EB18;
  dword_19EB20 = dword_19EB0C;
  dword_19EB3C = dword_19EB14;
  dword_19EB30 = dword_19EB08;
  dword_19EB38 = dword_19EB10;
  dword_19EB40 = dword_19EB18;
  dword_19EB34 = dword_19EB0C;
  dword_19EB64 = (int)sub_126B42((int)aColgcbtLbx, 5, dword_192ED4);
  dword_19EB58 = (int)sub_126B42((int)aColgcbtLbx, 6, dword_192ED4);
  dword_19EB60 = (int)sub_126B42((int)aColgcbtLbx, 7, dword_192ED4);
  dword_19EB68 = (int)sub_126B42((int)aColgcbtLbx, 8, dword_192ED4);
  dword_19EB5C = (int)sub_126B42((int)aColgcbtLbx, 9, dword_192ED4);
  sub_B8EFB(dword_19EB64, *(_WORD *)dword_19F37C);
  sub_B8EFB(dword_19EB58, *(_WORD *)dword_19F37C);
  sub_B8EFB(dword_19EB60, *(_WORD *)dword_19F37C);
  sub_B8EFB(dword_19EB68, *(_WORD *)dword_19F37C);
  sub_B8EFB(dword_19EB5C, *(_WORD *)dword_19F37C);
  dword_19EB78 = dword_19EB64;
  dword_19EB6C = dword_19EB58;
  dword_19EB74 = dword_19EB60;
  dword_19EB7C = dword_19EB68;
  dword_19EB70 = dword_19EB5C;
  dword_19EB8C = dword_19EB64;
  dword_19EB80 = dword_19EB58;
  dword_19EB88 = dword_19EB60;
  dword_19EB90 = dword_19EB68;
  dword_19EB84 = dword_19EB5C;
  if ( *(_BYTE *)(dword_197F98 + 3753 * *(int16_t *)dword_19F37C + 303) == 3 )
  {
    dword_19EB50 = (int)sub_126B42((int)aColgcbtLbx, 15, dword_192ED4);
    dword_19EB44 = (int)sub_126B42((int)aColgcbtLbx, 16, dword_192ED4);
    dword_19EB4C = (int)sub_126B42((int)aColgcbtLbx, 17, dword_192ED4);
    v0 = sub_126B42((int)aColgcbtLbx, 18, dword_192ED4);
    v1 = 19;
  }
  else
  {
    dword_19EB50 = (int)sub_126B42((int)aColgcbtLbx, 10, dword_192ED4);
    dword_19EB44 = (int)sub_126B42((int)aColgcbtLbx, 11, dword_192ED4);
    dword_19EB4C = (int)sub_126B42((int)aColgcbtLbx, 12, dword_192ED4);
    v0 = sub_126B42((int)aColgcbtLbx, 13, dword_192ED4);
    v1 = 14;
  }
  dword_19EB54 = (int)v0;
  dword_19EB48 = (int)sub_126B42((int)aColgcbtLbx, v1, dword_192ED4);
  sub_B8EFB(dword_19EB50, *(_WORD *)dword_19F37C);
  sub_B8EFB(dword_19EB44, *(_WORD *)dword_19F37C);
  sub_B8EFB(dword_19EB4C, *(_WORD *)dword_19F37C);
  sub_B8EFB(dword_19EB54, *(_WORD *)dword_19F37C);
  sub_B8EFB(dword_19EB48, *(_WORD *)dword_19F37C);
  dword_19F368 = (int)sub_126B42((int)aColgcbtLbx, 20, dword_192ED4);
  result = sub_126B42((int)aColgcbtLbx, 21, dword_192ED4);
  dword_19F36C = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 19EB08: using guessed type int dword_19EB08;
// 19EB0C: using guessed type int dword_19EB0C;
// 19EB10: using guessed type int dword_19EB10;
// 19EB14: using guessed type int dword_19EB14;
// 19EB18: using guessed type int dword_19EB18;
// 19EB1C: using guessed type int dword_19EB1C;
// 19EB20: using guessed type int dword_19EB20;
// 19EB24: using guessed type int dword_19EB24;
// 19EB28: using guessed type int dword_19EB28;
// 19EB2C: using guessed type int dword_19EB2C;
// 19EB30: using guessed type int dword_19EB30;
// 19EB34: using guessed type int dword_19EB34;
// 19EB38: using guessed type int dword_19EB38;
// 19EB3C: using guessed type int dword_19EB3C;
// 19EB40: using guessed type int dword_19EB40;
// 19EB44: using guessed type int dword_19EB44;
// 19EB48: using guessed type int dword_19EB48;
// 19EB4C: using guessed type int dword_19EB4C;
// 19EB50: using guessed type int dword_19EB50;
// 19EB54: using guessed type int dword_19EB54;
// 19EB58: using guessed type int dword_19EB58;
// 19EB5C: using guessed type int dword_19EB5C;
// 19EB60: using guessed type int dword_19EB60;
// 19EB64: using guessed type int dword_19EB64;
// 19EB68: using guessed type int dword_19EB68;
// 19EB6C: using guessed type int dword_19EB6C;
// 19EB70: using guessed type int dword_19EB70;
// 19EB74: using guessed type int dword_19EB74;
// 19EB78: using guessed type int dword_19EB78;
// 19EB7C: using guessed type int dword_19EB7C;
// 19EB80: using guessed type int dword_19EB80;
// 19EB84: using guessed type int dword_19EB84;
// 19EB88: using guessed type int dword_19EB88;
// 19EB8C: using guessed type int dword_19EB8C;
// 19EB90: using guessed type int dword_19EB90;
// 19F364: using guessed type int dword_19F364;
// 19F368: using guessed type int dword_19F368;
// 19F36C: using guessed type int dword_19F36C;
// 19F378: using guessed type int dword_19F378;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B7185) --------------------------------------------------------
unsigned int __fastcall sub_B7185( int a1, int a2)
{
  return sub_C6CAE(a1, a2, dword_19F364, 1, 1);
}
// 19F364: using guessed type int dword_19F364;


//----- (000B71A0) --------------------------------------------------------
void sub_B71A0()
{
  JUMPOUT(0xB7194);
}
// B71B7: control flows out of bounds to B7194


//----- (000B71B9) --------------------------------------------------------
int sub_B71B9()
{
  char v0; // bl
  int16_t i; // ax
  int16_t v2; // ax
  char *v3; // eax
  int16_t *v5; // [esp-8h] [ebp-1FCh]
  int v6; // [esp-4h] [ebp-1F8h]
  _BYTE v7[500]; // [esp+0h] [ebp-1F4h] BYREF

  v0 = 1;
  for ( i = 0; i < 4; ++i )
  {
    if ( *(int16_t *)(dword_19F378 + 2 * i + 10) > 0 )
      v0 = 0;
  }
  sub_BB04E(4u);
  v6 = 3753 * *(int16_t *)dword_19F378 + dword_197F98 + 21;
  v5 = sub_77B28(*(_WORD *)(dword_192B18 + 361 * dword_19F7A8 + 2));
  if ( v0 )
    v2 = 61;
  else
    v2 = 62;
  v3 = (char *)sub_CDF5C(v2);
  sprintf(v7, v3, v5, v6);
  return sub_1210FD(319, 10, (int)v7);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 19F378: using guessed type int dword_19F378;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B7289) --------------------------------------------------------
char sub_B7289()
{
  int v0; // esi
  int v1; // eax
  int v2; // eax
  char *v3; // eax
  int16_t v4; // ax
  int16_t *v6; // [esp-8h] [ebp-1FCh]
  int v7; // [esp-4h] [ebp-1F8h]
  _BYTE v8[500]; // [esp+0h] [ebp-1F4h] BYREF

  v0 = sub_12484C();
  sub_124D41();
  if ( byte_182ACA )
  {
    sub_128C32(0, 0, 639, 479, 0);
    v1 = sub_BBA8E(1);
    sub_12A478(0, 0, v1);
    v2 = sub_BBA8E(0);
    sub_12A478(0, 0, v2);
  }
  sub_BB04E(1u);
  sub_B8BC7();
  sub_B8C8B();
  sub_BB04E(1u);
  sub_BEBDC();
  if ( byte_182ACA )
  {
    sub_124DEC();
    sub_124C08();
    byte_182ACA = 0;
  }
  sub_BB04E(3u);
  if ( *(_BYTE *)(dword_19F378 + 22) < 4u && *(_BYTE *)(dword_19F37C + 22) < 4u )
  {
    v7 = dword_197F98 + 3753 * *(int16_t *)dword_19F378 + 21;
    v6 = sub_77B28(*(_WORD *)(361 * dword_19F7A8 + dword_192B18 + 2));
    v3 = (char *)sub_CDF5C(47);
    sprintf(v8, v3, v6, v7);
    sub_1210FD(319, 10, (int)v8);
  }
  else
  {
    sub_B71B9();
    if ( !byte_1828D0 )
    {
      byte_1828D0 = 1;
      byte_182ACA = 1;
    }
  }
  sub_128AB6(0, 0, 639, 479);
  sub_12B634();
  sub_B7ACC();
  sub_C6CF7();
  sub_12B65C();
  sub_124820(v0);
  do
  {
    LOBYTE(v4) = dword_19F378;
    ++word_1828CC;
    if ( *(_BYTE *)(dword_19F378 + 22) < 4u
      && (LOBYTE(v4) = dword_19F37C, *(_BYTE *)(dword_19F37C + 22) < 4u)
      && word_19F388 )
    {
      v4 = word_1828CC / 6;
      if ( !(word_1828CC % 6) || word_19F384 )
        LOBYTE(v4) = sub_EC4FE((uint8_t *)dword_19F378, (uint8_t *)dword_19F37C);
      if ( !word_19F384 )
        LOBYTE(v4) = sub_12C2C6(1);
    }
    else if ( !word_19F388 )
    {
      word_19F388 = 1;
    }
    if ( !word_19F384 )
      break;
    LOBYTE(v4) = dword_19F378;
    if ( *(_BYTE *)(dword_19F378 + 22) >= 4u )
      break;
    LOBYTE(v4) = dword_19F37C;
  }
  while ( *(_BYTE *)(dword_19F37C + 22) < 4u );
  return v4;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1828CC: using guessed type int16_t word_1828CC;
// 1828D0: using guessed type char byte_1828D0;
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 19F378: using guessed type int dword_19F378;
// 19F37C: using guessed type int dword_19F37C;
// 19F384: using guessed type int16_t word_19F384;
// 19F388: using guessed type int16_t word_19F388;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B7491) --------------------------------------------------------
int16_t __fastcall sub_B7491(int a1, int a2, int a3, int a4)
{
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int16_t v10; // dx
  int16_t result; // ax
  int v12; // [esp+4h] [ebp-8h] BYREF
  int v13; // [esp+8h] [ebp-4h]

  byte_199F39 = 1;
  byte_1828D0 = 0;
  word_19F388 = 0;
  word_19F384 = 0;
  byte_1828CF = 3;
  byte_1828CE = 3;
  dword_19F378 = a1;
  dword_19F37C = a2;
  v6 = sub_BAEFE();
  sub_BB954(v6, a2);
  sub_B6D51();
  byte_182ACE = 1;
  sub_BB16A(a4);
  byte_182AC9 = 1;
  byte_182AC8 = 0;
  dword_19F82C = dword_19F7B8;
  nullsub_7(dword_19F7B8, 0);
  sub_C6CA4();
  v13 = 0;
  memset(word_19EB94, 0, 2000);
  sub_B77A6();
  sub_B7825();
  if ( byte_182AC9 )
    sub_BC30B((int16_t)dword_19F7A8, 1);
  sub_123E6C((int)&unk_1828C0, 1);
  sub_C5BB9();
  sub_BF55A();
  sub_132C80(100);
  sub_131922(0, 255);
  sub_131F7B();
  sub_BAE88();
  sub_11C2F0();
  sub_B6D05();
  byte_182ACA = 1;
  sub_107AF(&v12);
  sub_1191CA((int)sub_B7289, 1);
  sub_CDAED((int)&unk_182953, 3);
  sub_128C32(0, 0, 639, 479, 0);
  sub_B7289();
  sub_132C80(100);
  v7 = sub_131922(0, 255);
  sub_1077D(v7);
  sub_C5C44();
  sub_123E6C((int)&unk_17CF00, 1);
  sub_124C08();
  sub_119441();
  sub_117174(5);
  sub_12C2A0();
  sub_12C2C6(16);
  sub_124820(a3);
  do
  {
    sub_12C2A0();
    sub_24677(10, -1, 1);
    sub_11C2F0();
    sub_B6D05();
    LOBYTE(v8) = sub_B7289();
    v9 = sub_1077D(v8);
    v10 = sub_1171AB(v9, -1, 1, 479);
    sub_114177();
    if ( v10 )
    {
      if ( word_19F384 || *(_BYTE *)(a1 + 22) >= 4u || *(_BYTE *)(a2 + 22) >= 4u )
        v13 = 1;
      else
        word_19F384 = 1;
      if ( word_19994C )
      {
        byte_182ACA = 1;
        word_19994C = 0;
        sub_CDAED((int)&unk_182953, 3);
      }
    }
    sub_12C2C6(1);
  }
  while ( !(_WORD)v13 );
  sub_2484F();
  sub_112816();
  sub_BB2CB(a1);
  sub_11C2F0();
  sub_1196F7();
  sub_119281();
  sub_107BA(&v12);
  sub_C6CA4();
  result = word_199A10;
  byte_182ACE = 0;
  word_199A08 = word_199A10;
  return result;
}
// B765F: variable 'v8' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// BB9FD: using guessed type int __fastcall nullsub_7(_DWORD, _DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1828CE: using guessed type char byte_1828CE;
// 1828CF: using guessed type char byte_1828CF;
// 1828D0: using guessed type char byte_1828D0;
// 182AC8: using guessed type char byte_182AC8;
// 182AC9: using guessed type char byte_182AC9;
// 182ACA: using guessed type char byte_182ACA;
// 182ACE: using guessed type char byte_182ACE;
// 19994C: using guessed type int16_t word_19994C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199F39: using guessed type char byte_199F39;
// 19EB94: using guessed type int16_t word_19EB94[];
// 19F378: using guessed type int dword_19F378;
// 19F37C: using guessed type int dword_19F37C;
// 19F384: using guessed type int16_t word_19F384;
// 19F388: using guessed type int16_t word_19F388;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F7B8: using guessed type int dword_19F7B8;
// 19F82C: using guessed type int dword_19F82C;


//----- (000B771D) --------------------------------------------------------
int __fastcall sub_B771D( unsigned int a1)
{
  int result; // eax
  int16_t i; // dx

  result = 0;
  for ( i = 0; i < 40; ++i )
  {
    if ( !byte_19EB99[1000 * a1 + 25 * i] )
      ++result;
  }
  return result;
}


//----- (000B774D) --------------------------------------------------------
int16_t sub_B774D()
{
  _DWORD v1[2]; // [esp+0h] [ebp-8h]

  v1[0] = 28180941;
  v1[1] = dword_B6CB0[1];
  return *((_WORD *)v1 + word_19F386);
}
// B6CB0: using guessed type int dword_B6CB0[2];
// 19F386: using guessed type int16_t word_19F386;


//----- (000B776D) --------------------------------------------------------
int16_t __fastcall sub_B776D( unsigned int a1)
{
  int v2; // [esp+0h] [ebp-4h]

  v2 = 25624818;
  return *((_WORD *)&v2 + a1);
}


//----- (000B7786) --------------------------------------------------------
_BYTE *sub_B7786()
{
  memset(word_19EB94, 0, 2000);
  sub_B77A6();
  return sub_B7825();
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19EB94: using guessed type int16_t word_19EB94[];


//----- (000B77A6) --------------------------------------------------------
int sub_B77A6()
{
  int result; // eax

  if ( dword_182AFD[0] <= 0 )
  {
    if ( dword_182B15 <= 0 && dword_182B01 <= 0 && dword_182B19 <= 0 )
    {
      if ( dword_182B2D <= 0 && dword_182B05 <= 0 && dword_182B31 <= 0 && dword_182B1D <= 0 && dword_182B35 <= 0 )
        result = 3;
      else
        result = 2;
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = 1;
    dword_182AFD[0] = 0;
  }
  word_19F386 = result;
  return result;
}
// 182AFD: using guessed type int dword_182AFD[];
// 182B01: using guessed type int dword_182B01;
// 182B05: using guessed type int dword_182B05;
// 182B15: using guessed type int dword_182B15;
// 182B19: using guessed type int dword_182B19;
// 182B1D: using guessed type int dword_182B1D;
// 182B2D: using guessed type int dword_182B2D;
// 182B31: using guessed type int dword_182B31;
// 182B35: using guessed type int dword_182B35;
// 19F386: using guessed type int16_t word_19F386;


//----- (000B7825) --------------------------------------------------------
_BYTE *sub_B7825()
{
  uint8_t i; // dl
  int v1; // ebx
  int v2; // esi
  int v3; // eax
  int16_t v4; // bx
  _BOOL2 v5; // si
  uint8_t v6; // al
  _BYTE *result; // eax

  for ( i = 0; i < 2u; ++i )
  {
    v1 = 0;
    do
    {
      v2 = 500 * i;
      v3 = 25 * (int16_t)v1;
      *(int16_t *)((char *)&word_19EB94[v2] + v3) = 0;
      *(int16_t *)((char *)&word_19EB96[v2] + v3) = 0;
      ++v1;
      byte_19EB99[v2 * 2 + v3] = 0;
    }
    while ( (int16_t)v1 < 40 );
    v4 = sub_B771D(i);
    v5 = v4 == 0;
    if ( v4 > 10 )
      v4 = 10;
    while ( !v5 )
    {
      sub_B88B2(i);
      if ( !--v4 || (int16_t)sub_B877D(i) == -1 )
        v5 = 1;
    }
    v6 = i;
    result = sub_B7B92(v6);
  }
  return result;
}
// 19EB94: using guessed type int16_t word_19EB94[];
// 19EB96: using guessed type int16_t word_19EB96[];


//----- (000B78BE) --------------------------------------------------------
char *__fastcall sub_B78BE( unsigned int a1)
{
  int16_t i; // dx
  unsigned int v2; // esi
  int v3; // ebx

  for ( i = 0; i < 40; ++i )
  {
    v2 = 1000 * a1;
    v3 = 25 * i;
    if ( byte_19EB99[v2 + v3] == 1 && !byte_19EBA0[v2 + v3] )
      return (char *)&word_19EB94[v2 / 2] + v3;
  }
  return 0;
}
// 19EB94: using guessed type int16_t word_19EB94[];


//----- (000B7908) --------------------------------------------------------
char *__fastcall sub_B7908( unsigned int a1, int a2, int a3)
{
  int16_t v4; // si
  char *v5; // ebx
  int16_t i; // dx
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int16_t *v10; // ebx

  v4 = 100;
  v5 = 0;
  for ( i = 0; i < 40; ++i )
  {
    v7 = 1000 * a1 + 25 * i;
    if ( byte_19EB99[v7] == a2 && v4 >= byte_19EB9C[v7] && (!a3 || !*(int *)((char *)&dword_19EBA1 + v7)) )
    {
      v8 = 500 * a1;
      v9 = 25 * i;
      v10 = &word_19EB94[v8];
      v4 = byte_19EB9C[v8 * 2 + v9];
      v5 = (char *)v10 + v9;
    }
  }
  return v5;
}
// B7956: conditional instruction was optimized away because %var_4.1!=0
// 19EB94: using guessed type int16_t word_19EB94[];
// 19EBA1: using guessed type int dword_19EBA1;


//----- (000B7990) --------------------------------------------------------
int sub_B7990()
{
  int16_t i; // dx
  int result; // eax

  for ( i = 0; i < 40; ++i )
  {
    if ( byte_19EB99[25 * i] > 1 && byte_19EB9A[25 * i] < (int)*(uint8_t *)(dword_19F378 + 22) )
    {
      byte_19EB99[25 * i] = 1;
      byte_19EB9C[25 * i] = 0;
      byte_19EBA0[25 * i] = 0;
    }
    result = 25 * i;
    if ( byte_19EF81[result] > 1 && byte_19EF82[25 * i] < (int)*(uint8_t *)(dword_19F37C + 22) )
    {
      byte_19EF81[25 * i] = 1;
      byte_19EF84[25 * i] = 0;
      byte_19EF88[25 * i] = 0;
    }
  }
  return result;
}
// 19F378: using guessed type int dword_19F378;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B7A12) --------------------------------------------------------
void sub_B7A12()
{
  char *v0; // ecx
  char *v1; // eax
  uint8_t v2; // [esp+0h] [ebp-4h]

  v2 = 0;
  while ( 1 )
  {
    v0 = sub_B78BE(v2);
    if ( v0 )
    {
      v1 = sub_B7908(v2 == 0, 3, 1);
      if ( !v1 )
        v1 = sub_B7908(v2 == 0, 2, 0);
      if ( !v1 )
        v1 = sub_B7908(v2 == 0, 4, 0);
      if ( v1 )
      {
        v1[5] = 3;
        v1[8] = 0;
        *(_DWORD *)(v1 + 13) = v0;
        v0[12] = 1;
      }
      else
      {
        sub_C6CAE((int16_t)(*(_WORD *)v0 + 15), *((_WORD *)v0 + 1) + 15, dword_19F364, 1, 1);
      }
    }
    if ( ++v2 >= 2u )
      JUMPOUT(0xB748B);
  }
}
// B7AC7: control flows out of bounds to B748B
// 19F364: using guessed type int dword_19F364;


//----- (000B7ACC) --------------------------------------------------------
_BYTE *sub_B7ACC()
{
  uint8_t i; // bl
  int16_t j; // cx
  char *v2; // eax
  uint8_t v3; // al
  _BYTE *result; // eax

  sub_B7990();
  for ( i = 0; i < 2u; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      v2 = (char *)&word_19EB94[500 * i] + 25 * j;
      sub_B7E84((unsigned int)v2);
    }
    sub_B7A12();
    sub_B86B4(i);
    v3 = i;
    result = sub_B7B92(v3);
  }
  return result;
}
// 19EB94: using guessed type int16_t word_19EB94[];


//----- (000B7B1C) --------------------------------------------------------
int __fastcall sub_B7B1C(_BYTE *a1)
{
  unsigned int v1; // edx
  int v2; // ebx

  v1 = (unsigned int)a1;
  v2 = 0;
  do
  {
    if ( *(_BYTE *)(v1 + 5) == a1[5] && *(_BYTE *)(v1 + 6) == a1[6] )
      ++v2;
    v1 += 25;
  }
  while ( v1 < (unsigned int)&word_19EB94[500 * (char)a1[7] + 500] );
  return v2;
}
// 19EB94: using guessed type int16_t word_19EB94[];


//----- (000B7B57) --------------------------------------------------------
void __fastcall sub_B7B57(unsigned int a1)
{
  unsigned int v1; // edx
  int v2; // ebx

  v1 = a1;
  v2 = 0;
  while ( 1 )
  {
    if ( *(_BYTE *)(a1 + 5) >= 2u && *(_BYTE *)(a1 + 6) == *(_BYTE *)(v1 + 6) )
      ++v2;
    a1 += 25;
    if ( a1 >= (unsigned int)&word_19EB94[500 * *(char *)(v1 + 7) + 500] )
      JUMPOUT(0xB7B51);
  }
}
// B7B90: control flows out of bounds to B7B51
// 19EB94: using guessed type int16_t word_19EB94[];


//----- (000B7B92) --------------------------------------------------------
_BYTE *__fastcall sub_B7B92( unsigned int a1)
{
  unsigned int v1; // ecx
  uint8_t v2; // bl
  char v3; // dl
  unsigned int v4; // esi
  int v5; // edi
  int v6; // esi
  _BYTE *result; // eax
  int16_t *v8; // ecx
  _BYTE *v9; // esi
  _BYTE *v10; // ecx
  _BYTE v11[28]; // [esp+0h] [ebp-34h] BYREF
  unsigned int v12; // [esp+1Ch] [ebp-18h]
  int v13; // [esp+20h] [ebp-14h]
  int v14; // [esp+24h] [ebp-10h]
  int v15; // [esp+28h] [ebp-Ch]
  int v16; // [esp+2Ch] [ebp-8h]
  uint8_t v17; // [esp+30h] [ebp-4h]

  v17 = a1;
  v16 = 0;
  do
  {
    v15 = 0;
    do
    {
      v12 = 1000 * v17;
      v1 = 25 * (int16_t)v15 + v12;
      v13 = 25 * (int16_t)v15;
      v2 = byte_19EB9A[v1];
      v3 = byte_19EB99[v1];
      v14 = 25 * ((int16_t)v15 + 1);
      v4 = v14 + v12;
      v5 = sub_B81F7(byte_19EB9B[v1], v3, v2);
      v6 = *(int16_t *)((char *)&word_19EB96 + v4)
         + *(int16_t *)(sub_B81F7(byte_19EB9B[v4], byte_19EB99[v4], byte_19EB9A[v4]) + 2);
      result = (_BYTE *)(*(int16_t *)((char *)&word_19EB96 + v1) + *(int16_t *)(v5 + 2));
      if ( (int)result > v6 )
      {
        v8 = &word_19EB94[v12 / 2];
        v9 = (char *)&word_19EB94[v12 / 2] + v13;
        sub_12779E(v11, v9, 0x19u);
        v10 = (char *)v8 + v14;
        sub_12779E(v9, v10, 0x19u);
        result = sub_12779E(v10, v11, 0x19u);
      }
      ++v15;
    }
    while ( (int16_t)v15 < 39 );
    ++v16;
  }
  while ( (int16_t)v16 < 40 );
  return result;
}
// 19EB94: using guessed type int16_t word_19EB94[];
// 19EB96: using guessed type int16_t word_19EB96;


//----- (000B7C8D) --------------------------------------------------------
char __fastcall sub_B7C8D(int a1, _WORD *a2, _WORD *a3)
{
  int16_t v5; // bx
  int v6; // eax

  v5 = *(_WORD *)sub_B81F7(*(_BYTE *)(a1 + 7), *(_BYTE *)(a1 + 5), *(_BYTE *)(a1 + 6));
  LOBYTE(v6) = *(_BYTE *)(a1 + 7);
  if ( (_BYTE)v6 )
  {
    if ( (_BYTE)v6 != 1 )
      return v6;
    LOBYTE(v6) = *(_BYTE *)(a1 + 6);
    if ( !(_BYTE)v6 )
    {
      v6 = 3753 * *(int16_t *)dword_19F37C;
      if ( *(_BYTE *)(dword_197F98 + v6 + 303) == 3 )
      {
        *a2 = 9;
        goto LABEL_9;
      }
      *a2 = 10;
      goto LABEL_11;
    }
  }
  else
  {
    LOBYTE(v6) = *(_BYTE *)(a1 + 6);
    if ( !(_BYTE)v6 )
    {
      LOBYTE(v6) = dword_197F98;
      if ( *(_BYTE *)(3753 * *(int16_t *)dword_19F37C + dword_197F98 + 303) == 3 )
      {
        *a2 = v5 - 9;
LABEL_9:
        *a3 = 13;
        return v6;
      }
      *a2 = v5 - 10;
LABEL_11:
      *a3 = 20;
      return v6;
    }
  }
  if ( (uint8_t)v6 <= 3u )
  {
    *a2 = 16;
    *a3 = 19;
  }
  return v6;
}
// 197F98: using guessed type int dword_197F98;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B7D48) --------------------------------------------------------
char __fastcall sub_B7D48(int a1, _WORD *a2, _WORD *a3)
{
  int16_t v5; // bx
  int v6; // eax

  v5 = *(_WORD *)sub_B81F7(*(_BYTE *)(a1 + 7), *(_BYTE *)(a1 + 5), *(_BYTE *)(a1 + 6));
  LOBYTE(v6) = *(_BYTE *)(a1 + 7);
  if ( (_BYTE)v6 )
  {
    if ( (_BYTE)v6 != 1 )
      return v6;
    LOBYTE(v6) = *(_BYTE *)(a1 + 6);
    if ( (_BYTE)v6 )
    {
      if ( (uint8_t)v6 > 3u )
        return v6;
      *a2 = 10;
LABEL_22:
      *a3 = 18;
      return v6;
    }
    v6 = 3753 * *(int16_t *)dword_19F37C;
    if ( *(_BYTE *)(dword_197F98 + v6 + 303) == 3 )
    {
      *a2 = 15;
      goto LABEL_9;
    }
    if ( *(_BYTE *)(a1 + 5) == 5 )
    {
      *a2 = 14;
      *a3 = 23;
      return v6;
    }
    *a2 = 22;
LABEL_11:
    *a3 = 26;
    return v6;
  }
  LOBYTE(v6) = *(_BYTE *)(a1 + 6);
  if ( (_BYTE)v6 )
  {
    if ( (uint8_t)v6 > 3u )
      return v6;
    *a2 = 14;
    goto LABEL_22;
  }
  LOBYTE(v6) = dword_197F98;
  if ( *(_BYTE *)(3753 * *(int16_t *)dword_19F37C + dword_197F98 + 303) != 3 )
  {
    *a2 = v5 - 22;
    goto LABEL_11;
  }
  *a2 = v5 - 15;
LABEL_9:
  *a3 = 14;
  return v6;
}
// 197F98: using guessed type int dword_197F98;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B7E22) --------------------------------------------------------
char *__fastcall sub_B7E22( unsigned int a1)
{
  int16_t i; // dx
  int v3; // eax
  int v4; // ecx
  int v5; // esi

  for ( i = 0; i < 40; ++i )
  {
    v3 = 1000 * a1 + 25 * i;
    if ( byte_19EB99[v3] == 5 || byte_19EB99[v3] == 1 )
    {
      v4 = 500 * a1;
      v5 = 25 * i;
      if ( !byte_19EBA0[v4 * 2 + v5] )
        return (char *)&word_19EB94[v4] + v5;
    }
  }
  return 0;
}
// 19EB94: using guessed type int16_t word_19EB94[];


//----- (000B7E84) --------------------------------------------------------
void __fastcall sub_B7E84(unsigned int a1)
{
  int v2; // eax
  int16_t v3; // ax
  int16_t v4; // ax
  int v5; // ebx
  char *v6; // eax
  int16_t v7; // ax
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // eax

  sub_BB04E(1u);
  if ( !*(_BYTE *)(a1 + 5) )
    return;
  if ( *(_BYTE *)(a1 + 7) )
  {
    v2 = dword_19F37C;
    if ( *(_BYTE *)(dword_19F37C + 25) != *(_BYTE *)(a1 + 6) || *(_BYTE *)(a1 + 5) == 1 )
    {
      if ( *(_BYTE *)(dword_19F37C + 24) != *(_BYTE *)(a1 + 6) )
        goto LABEL_21;
      if ( *(_BYTE *)(a1 + 5) == 1 )
        goto LABEL_21;
      if ( *(_BYTE *)(a1 + 5) == 5 )
        goto LABEL_21;
      sub_B7B57(a1);
      if ( (int)sub_1247A0(v4) > 1 )
        goto LABEL_21;
      *(_BYTE *)(a1 + 5) = 5;
      *(_BYTE *)(a1 + 12) = 0;
      v2 = dword_19F37C;
      *(_BYTE *)(a1 + 8) = 0;
      goto LABEL_20;
    }
    *(_BYTE *)(a1 + 5) = 1;
    *(_BYTE *)(a1 + 12) = 0;
    *(_BYTE *)(a1 + 8) = 0;
    goto LABEL_6;
  }
  v2 = dword_19F378;
  if ( *(_BYTE *)(dword_19F378 + 25) == *(_BYTE *)(a1 + 6) && *(_BYTE *)(a1 + 5) != 1 )
  {
    *(_BYTE *)(a1 + 5) = 1;
    *(_BYTE *)(a1 + 8) = 0;
    *(_BYTE *)(a1 + 12) = 0;
LABEL_6:
    *(_BYTE *)(v2 + 25) = -1;
    byte_182ACA = 1;
    goto LABEL_20;
  }
  if ( *(_BYTE *)(dword_19F378 + 24) != *(_BYTE *)(a1 + 6) )
    goto LABEL_21;
  if ( *(_BYTE *)(a1 + 5) == 1 )
    goto LABEL_21;
  if ( *(_BYTE *)(a1 + 5) == 5 )
    goto LABEL_21;
  sub_B7B57(a1);
  if ( (int)sub_1247A0(v3) > 1 )
    goto LABEL_21;
  *(_BYTE *)(a1 + 5) = 5;
  *(_BYTE *)(a1 + 12) = 0;
  v2 = dword_19F378;
  *(_BYTE *)(a1 + 8) = 0;
LABEL_20:
  *(_BYTE *)(v2 + 24) = -1;
LABEL_21:
  v5 = sub_B81F7(*(_BYTE *)(a1 + 7), *(_BYTE *)(a1 + 5), *(_BYTE *)(a1 + 6));
  if ( *(_BYTE *)(a1 + 5) == 3 || *(_BYTE *)(a1 + 5) && *(_DWORD *)(a1 + 13) )
  {
    if ( !*(_BYTE *)(a1 + 8) && *(_BYTE *)(a1 + 5) == 3 && *(char *)(a1 + 9) >= 10 )
      *(_DWORD *)(a1 + 13) = 0;
    if ( !*(_DWORD *)(a1 + 13) )
    {
      v6 = sub_B7E22(*(_BYTE *)(a1 + 7) == 0);
      *(_DWORD *)(a1 + 13) = v6;
      if ( !v6 || (v7 = sub_B7B1C((_BYTE *)a1), (int)(sub_1247A0(v7) - 1) <= 1) )
      {
        *(_DWORD *)(a1 + 13) = 0;
        if ( sub_1247A0(2u) == 1 )
        {
          *(_BYTE *)(a1 + 5) = 4;
        }
        else
        {
          *(_BYTE *)(a1 + 5) = 2;
          *(_BYTE *)(a1 + 8) = 0;
        }
        v5 = sub_B81F7(*(_BYTE *)(a1 + 7), *(_BYTE *)(a1 + 5), *(_BYTE *)(a1 + 6));
      }
      *(_BYTE *)(a1 + 9) = 0;
      *(_DWORD *)(a1 + 17) = 0;
    }
    if ( *(_DWORD *)(a1 + 13) )
    {
      v8 = *(_DWORD *)(a1 + 13);
      if ( *(char *)(v8 + 6) != -1 )
      {
        *(_BYTE *)(v8 + 12) = 1;
        sub_B8F5F(a1);
      }
    }
  }
  else if ( *(_DWORD *)(a1 + 13) && *(char *)(*(_DWORD *)(a1 + 13) + 6) == -1 )
  {
    *(_DWORD *)(a1 + 13) = 0;
  }
  if ( *(char *)(a1 + 8) >= *(int16_t *)(v5 + 6) - 1 || *(_BYTE *)(a1 + 5) == 2 )
  {
    sub_B828C(a1);
  }
  else
  {
    v9 = word_1828CC % 2;
    if ( !v9 )
      ++*(_BYTE *)(a1 + 8);
    if ( *(_DWORD *)(a1 + 13) )
    {
      if ( *(_BYTE *)(a1 + 9) == 5 )
      {
        v10 = *(_DWORD *)(a1 + 13);
        if ( *(_BYTE *)(v10 + 6) || *(_BYTE *)(v10 + 5) != 1 )
          v11 = 28;
        else
          v11 = 30;
        sub_147D7(v11);
      }
      if ( !*(_BYTE *)(a1 + 9) )
        sub_B92F8(a1, v9, v5, a1);
      if ( *(_BYTE *)(a1 + 9) == 10 )
        sub_112C96(*(_DWORD *)(a1 + 17), 10);
      if ( (char)++*(_BYTE *)(a1 + 9) > 11 )
        *(_DWORD *)(a1 + 13) = 0;
    }
  }
  if ( *(_BYTE *)(a1 + 5) )
  {
    sub_12B753(v5, *(char *)(a1 + 8));
    sub_12A478(*(_WORD *)a1, *(_WORD *)(a1 + 2), v5);
  }
  if ( *(_BYTE *)(a1 + 5) == 4
    && (*(int16_t *)a1 < 310 || *(int16_t *)a1 > 330)
    && (*(char *)(a1 + 6) >= 1 && !(*(char *)(a1 + 8) % 2)
     || !*(_BYTE *)(a1 + 6)
     && *(_BYTE *)(dword_197F98 + 3753 * *(int16_t *)dword_19F37C + 303) == 3
     && !(*(char *)(a1 + 8) % 2)
     && *(char *)(a1 + 8) > 1
     || *(_BYTE *)(dword_197F98 + 3753 * *(int16_t *)dword_19F37C + 303) != 3) )
  {
    *(_WORD *)a1 += 1 - 2 * *(char *)(a1 + 7);
  }
  sub_B861F(a1);
}
// B7F03: variable 'v3' is possibly undefined
// B7F66: variable 'v4' is possibly undefined
// 1828CC: using guessed type int16_t word_1828CC;
// 182ACA: using guessed type char byte_182ACA;
// 197F98: using guessed type int dword_197F98;
// 19F378: using guessed type int dword_19F378;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B81F7) --------------------------------------------------------
int __fastcall sub_B81F7( unsigned int a1, int a2, unsigned int a3)
{
  int result; // eax

  switch ( a2 )
  {
    case 0:
      result = dword_19F364;
      break;
    case 1:
      result = dword_19EAF4[20 * a1 + 5 * a3];
      break;
    case 2:
      result = dword_19EAF8[20 * a1 + 5 * a3];
      break;
    case 3:
      result = dword_19EAFC[20 * a1 + 5 * a3];
      break;
    case 4:
      result = dword_19EB00[20 * a1 + 5 * a3];
      break;
    case 5:
      result = dword_19EB04[20 * a1 + 5 * a3];
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
// 19EAF4: using guessed type int dword_19EAF4[];
// 19EAF8: using guessed type int dword_19EAF8[];
// 19EAFC: using guessed type int dword_19EAFC[];
// 19EB00: using guessed type int dword_19EB00[];
// 19EB04: using guessed type int dword_19EB04[];
// 19F364: using guessed type int dword_19F364;


//----- (000B828C) --------------------------------------------------------
void __fastcall sub_B828C(int a1)
{
  char v2; // dl
  int v3; // eax
  unsigned int v4; // eax
  int v5; // eax

  v2 = *(_BYTE *)(a1 + 5);
  *(_BYTE *)(a1 + 8) = 0;
  switch ( v2 )
  {
    case 0:
      if ( *(char *)(a1 + 6) != -1 )
        *(_BYTE *)(a1 + 6) = -1;
      goto LABEL_24;
    case 1:
      v5 = *(_DWORD *)(a1 + 21);
      *(_BYTE *)(a1 + 5) = 0;
      sub_112C96(v5, 10);
      byte_182ACA = 1;
      goto LABEL_24;
    case 2:
      if ( *(_BYTE *)(dword_19F378 + 22) >= 4u || *(_BYTE *)(dword_19F37C + 22) >= 4u )
        goto LABEL_5;
      goto LABEL_4;
    case 3:
      if ( *(_BYTE *)(dword_19F378 + 22) >= 4u || *(_BYTE *)(dword_19F37C + 22) >= 4u )
        goto LABEL_10;
      v4 = sub_1247A0(4u);
      if ( v4 < 2 )
      {
        if ( v4 == 1 )
          goto LABEL_5;
      }
      else
      {
        if ( v4 <= 2 )
        {
          *(_BYTE *)(a1 + 5) = 3;
          *(_WORD *)a1 += sub_1247A0(3u) - 2;
          goto LABEL_24;
        }
        if ( v4 == 3 )
          goto LABEL_5;
      }
      *(_BYTE *)(a1 + 5) = 4;
      *(_WORD *)(a1 + 10) = sub_1247A0(3u) - 2;
LABEL_24:
      sub_B8575(a1);
      if ( *(_BYTE *)(a1 + 5) == 4 && !*(_BYTE *)(a1 + 6) && !*(_DWORD *)(a1 + 21) )
        *(_DWORD *)(a1 + 21) = sub_147D7(31);
      return;
    case 4:
      sub_B81F7(*(_BYTE *)(a1 + 7), v2, *(_BYTE *)(a1 + 6));
      sub_112C96(*(_DWORD *)(a1 + 21), 10);
      v3 = dword_19F378;
      *(_DWORD *)(a1 + 21) = 0;
      if ( *(_BYTE *)(v3 + 22) < 4u && *(_BYTE *)(dword_19F37C + 22) < 4u && sub_1247A0(2u) == 1 )
      {
LABEL_4:
        *(_BYTE *)(a1 + 5) = 3;
      }
      else if ( sub_1247A0(2u) == 1 )
      {
LABEL_10:
        *(_BYTE *)(a1 + 5) = 2;
      }
      else
      {
LABEL_5:
        *(_BYTE *)(a1 + 5) = 4;
      }
      goto LABEL_24;
    case 5:
      goto LABEL_10;
    default:
      goto LABEL_24;
  }
}
// 182ACA: using guessed type char byte_182ACA;
// 19F378: using guessed type int dword_19F378;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B83ED) --------------------------------------------------------
void __fastcall sub_B83ED(int a1)
{
  _WORD *v2; // eax
  int16_t v3; // bx
  int16_t v4; // dx
  int v5; // eax

  v2 = (_WORD *)sub_B81F7(*(_BYTE *)(a1 + 7), *(_BYTE *)(a1 + 5), *(_BYTE *)(a1 + 6));
  v3 = *(_WORD *)a1 + *v2;
  v4 = v2[1] + *(_WORD *)(a1 + 2) + *(int16_t *)(a1 + 10) * (int16_t)v2[3] / 5;
  if ( *(_BYTE *)(a1 + 5) == 4 && !*(_BYTE *)(a1 + 6) )
    v3 += 40 * (1 - 2 * *(char *)(a1 + 7));
  if ( v4 >= 480
    || v4 <= sub_B774D()
    || *(_BYTE *)(a1 + 5) == 4
    && (*(_BYTE *)(a1 + 7) || v3 >= sub_B776D(0))
    && (*(_BYTE *)(a1 + 7) != 1 || v3 <= sub_B776D(1u)) )
  {
    if ( v4 < 480 )
    {
      if ( v4 > sub_B774D() )
      {
        if ( *(_BYTE *)(a1 + 5) != 2 )
        {
          *(_BYTE *)(a1 + 5) = 2;
          if ( *(_DWORD *)(a1 + 21) )
          {
            sub_112C96(*(_DWORD *)(a1 + 21), 10);
            *(_DWORD *)(a1 + 21) = 0;
          }
          *(_WORD *)(a1 + 10) = sub_1247A0(3u) - 2;
        }
      }
      else
      {
        if ( *(_BYTE *)(a1 + 7) )
          v5 = sub_EB4DD(v3, v4, 630, 479, 406, 461, 629, 364);
        else
          v5 = sub_EB4DD(v3, v4, 0, 479, 10, 361, 225, 461);
        if ( v5 <= 0 )
          *(_WORD *)(a1 + 10) = 1;
      }
    }
    else
    {
      *(_WORD *)(a1 + 10) = -1;
    }
  }
  JUMPOUT(0xB7C86);
}
// B84A4: control flows out of bounds to B7C86
// B8519: conditional instruction was optimized away because %var_4.1==1


//----- (000B8575) --------------------------------------------------------
void __fastcall sub_B8575(int a1)
{
  int v2; // eax
  int16_t v3; // bx
  char v4; // al

  v2 = sub_B81F7(*(_BYTE *)(a1 + 7), *(_BYTE *)(a1 + 5), *(_BYTE *)(a1 + 6));
  v3 = *(_WORD *)(v2 + 2) + *(_WORD *)(a1 + 2) + *(int16_t *)(v2 + 6) * *(int16_t *)(a1 + 10) / 5;
  while ( 1 )
  {
    sub_B83ED(a1);
    if ( v4 )
      break;
    switch ( sub_1247A0(4u) )
    {
      case 1u:
        *(_WORD *)(a1 + 10) = 0;
        break;
      case 2u:
        *(_WORD *)(a1 + 10) = 1;
        break;
      case 3u:
        *(_WORD *)(a1 + 10) = -1;
        break;
      case 4u:
        *(_BYTE *)(a1 + 5) = 2;
        if ( *(_DWORD *)(a1 + 21) )
        {
          sub_112C96(*(_DWORD *)(a1 + 21), 10);
          *(_DWORD *)(a1 + 21) = 0;
        }
        break;
      default:
        break;
    }
    if ( v3 > 478 )
      *(_WORD *)(a1 + 10) = -1;
  }
  JUMPOUT(0xB81DA);
}
// B85BC: control flows out of bounds to B81DA
// B85BC: variable 'v4' is possibly undefined


//----- (000B861F) --------------------------------------------------------
void __fastcall sub_B861F(int a1)
{
  _DWORD v2[5]; // [esp+0h] [ebp-18h]
  int16_t v3; // [esp+14h] [ebp-4h]

  sub_B81F7(*(_BYTE *)(a1 + 7), *(_BYTE *)(a1 + 5), *(_BYTE *)(a1 + 6));
  v2[0] = 1;
  v2[1] = dword_B6CC4[1];
  v2[2] = dword_B6CC4[2];
  v2[3] = 1;
  v2[4] = dword_B6CD0[1];
  v3 = 0;
  if ( *(_BYTE *)(a1 + 5) == 4
    && !*(_BYTE *)(a1 + 6)
    && *(_BYTE *)(dword_197F98 + 3753 * *(int16_t *)dword_19F37C + 303) != 3
    && *(char *)(a1 + 8) % 3 == 2
    || *(_BYTE *)(a1 + 5) == 4 && *((_WORD *)v2 + *(char *)(a1 + 8)) == 1 )
  {
    *(_WORD *)(a1 + 2) += *(_WORD *)(a1 + 10);
  }
  JUMPOUT(0xB7C86);
}
// B86AF: control flows out of bounds to B7C86
// B6CC4: using guessed type int[3];
// B6CD0: using guessed type int[2];
// 197F98: using guessed type int dword_197F98;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B86B4) --------------------------------------------------------
void __fastcall sub_B86B4( unsigned int a1)
{
  int16_t v2; // dx
  _BOOL2 v3; // cx

  v2 = sub_B771D(a1);
  v3 = v2 == 0;
  if ( v2 > 10 )
    v2 = 10;
  while ( !v3 )
  {
    sub_B87CD(a1);
    v3 = --v2 == 0;
  }
  JUMPOUT(0xB83E9);
}
// B86DD: control flows out of bounds to B83E9


//----- (000B86F6) --------------------------------------------------------
char *__fastcall sub_B86F6( unsigned int a1)
{
  int16_t i; // ax
  int v3; // esi
  int v4; // ebx

  for ( i = 0; i < 40; ++i )
  {
    v3 = 500 * a1;
    v4 = 25 * i;
    if ( !byte_19EB99[v3 * 2 + v4] )
      return (char *)&word_19EB94[v3] + v4;
  }
  return 0;
}
// 19EB94: using guessed type int16_t word_19EB94[];


//----- (000B8732) --------------------------------------------------------
int __fastcall sub_B8732( int a1, unsigned int a2)
{
  int v4; // edx
  int16_t i; // bx
  int v6; // eax

  v4 = 0;
  for ( i = 0; i < 40; ++i )
  {
    v6 = 1000 * a2 + 25 * i;
    if ( a1 == byte_19EB9A[v6] && byte_19EB99[v6] )
      ++v4;
  }
  return v4;
}


//----- (000B877D) --------------------------------------------------------
int __fastcall sub_B877D( unsigned int a1)
{
  int i; // ebx
  int v3; // esi
  int v4; // edx

  for ( i = 0; (int16_t)i < 4; ++i )
  {
    if ( a1 )
    {
      v4 = dword_19F37C;
      v3 = 2 * (int16_t)i;
    }
    else
    {
      v3 = dword_19F378;
      v4 = 2 * (int16_t)i;
    }
    if ( (int16_t)sub_B8732(i, a1) < *(int16_t *)(v4 + v3 + 10) )
      return i;
  }
  return -1;
}
// 19F378: using guessed type int dword_19F378;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B87CD) --------------------------------------------------------
void __fastcall sub_B87CD( unsigned int a1)
{
  int v1; // edx
  char *v2; // ecx
  char v3; // al
  int v4; // edx
  int16_t v5; // dx
  int16_t v6; // ax
  int v7; // [esp+0h] [ebp-8h]
  uint8_t v8; // [esp+4h] [ebp-4h]

  v8 = a1;
  v1 = a1;
  v7 = 42008566;
  v2 = sub_B86F6(a1);
  if ( v2 )
  {
    v3 = sub_B877D(v1);
    v2[6] = v3;
    if ( v3 == -1 )
    {
      *(_WORD *)v2 = *((_WORD *)&v7 + v1);
    }
    else
    {
      v2[5] = 2;
      *(_WORD *)v2 = *((_WORD *)&v7 + v1);
      v4 = 480 - *(int16_t *)(sub_B81F7(v2[7], v2[5], v2[6]) + 2);
      if ( v4 <= (int)(sub_1247A0(0x55u) + 360) )
        v5 = 480 - *(_WORD *)(sub_B81F7(v2[7], v2[5], v2[6]) + 2);
      else
        v5 = sub_1247A0(0x55u) + 360;
      v2[7] = v8;
      *((_WORD *)v2 + 1) = v5;
      v6 = sub_1247A0(3u);
      v2[8] = 0;
      *(_DWORD *)(v2 + 13) = 0;
      *((_WORD *)v2 + 5) = v6 - 2;
    }
  }
  JUMPOUT(0xB748B);
}
// B88A0: control flows out of bounds to B748B


//----- (000B88B2) --------------------------------------------------------
int16_t __fastcall sub_B88B2( unsigned int a1)
{
  int v1; // ecx
  char *v2; // eax
  char *v3; // edx
  char *v4; // ebx
  int16_t v5; // ax
  int v6; // ecx
  int16_t v7; // ax
  int v9; // [esp+0h] [ebp-Ch]
  int16_t v10; // [esp+4h] [ebp-8h]
  uint8_t v11; // [esp+8h] [ebp-4h]

  v11 = a1;
  v1 = a1;
  v9 = 38666290;
  v2 = sub_B86F6(a1);
  v3 = v2;
  v4 = v2;
  if ( v2 )
  {
    v5 = sub_B877D(v1);
    v10 = v5;
    v3[6] = v5;
    v6 = 2 * v1;
    if ( (char)v5 == -1 )
    {
      LOWORD(v2) = *(_WORD *)((char *)&v9 + v6);
      *(_WORD *)v3 = (_WORD)v2;
    }
    else
    {
      v3[5] = 2;
      *(_WORD *)v3 = sub_1247A0(0x32u) - 20 + *(_WORD *)((char *)&v9 + v6);
      if ( (int)(sub_1247A0(0x55u) + 360) >= 430 )
        v7 = 430;
      else
        v7 = sub_1247A0(0x55u) + 360;
      *((_WORD *)v4 + 1) = v7;
      v4[7] = v11;
      v2 = (char *)(sub_1247A0(3u) - 2);
      v4[8] = 0;
      *((_WORD *)v4 + 5) = (_WORD)v2;
    }
  }
  return (int16_t)v2;
}


//----- (000B896D) --------------------------------------------------------
int __fastcall sub_B896D(int a1, int a2, int16_t *a3)
{
  int16_t v4; // di
  int16_t v5; // si
  int16_t i; // si
  int result; // eax
  char *v8; // eax
  int v9; // ebx
  int16_t v10; // ax
  char *v11; // eax
  int64_t v12; // rax
  int v13; // eax
  int16_t v14; // dx
  char *v15; // eax
  char *v16; // [esp-Ch] [ebp-224h]
  int v17; // [esp-8h] [ebp-220h]
  int v18; // [esp-8h] [ebp-220h]
  int v19; // [esp-4h] [ebp-21Ch]
  int v20; // [esp-4h] [ebp-21Ch]
  int v21; // [esp-4h] [ebp-21Ch]
  int v22; // [esp-4h] [ebp-21Ch]
  int v23; // [esp-4h] [ebp-21Ch]
  int16_t v24; // [esp+0h] [ebp-218h]
  _BYTE v25[500]; // [esp+4h] [ebp-214h] BYREF
  int v26; // [esp+1F8h] [ebp-20h]
  int v27; // [esp+1FCh] [ebp-1Ch]
  int v28; // [esp+200h] [ebp-18h]
  char *v29; // [esp+204h] [ebp-14h]
  int v30; // [esp+208h] [ebp-10h]
  int v31; // [esp+20Ch] [ebp-Ch]
  int v32; // [esp+210h] [ebp-8h]
  int v33; // [esp+214h] [ebp-4h]

  v4 = 0;
  v5 = 0;
  v32 = 0;
  do
  {
    if ( a3[v5 + 5] )
      ++v32;
    ++v5;
  }
  while ( v5 < 4 );
  for ( i = 0; i < 4; ++i )
  {
    v31 = i;
    result = 2 * i;
    v29 = (char *)a3 + result;
    if ( *(int16_t *)((char *)a3 + result + 10) )
    {
      v26 = *a3;
      v28 = sub_BB723(v26, v31, *(uint8_t *)(3753 * v26 + dword_197F98 + 37));
      sub_BAF3C(1u, *(_BYTE *)dword_19F378);
      v19 = *((int16_t *)v29 + 1) - *((char *)a3 + 51);
      v8 = (char *)sub_CDF5C(13);
      v9 = (int16_t)v32;
      sprintf(v25, v8, v19);
      v30 = (int16_t)(v24 + (v4 + 1) * (261 / (v9 + 1)));
      sub_1210FD(v30, 176, (int)v25);
      v20 = *((uint8_t *)a3 + v31 + 18);
      if ( *((_BYTE *)a3 + v31 + 18) <= 1u )
        v10 = 22;
      else
        v10 = 23;
      v11 = (char *)sub_CDF5C(v10);
      v12 = sprintf(v25, v11, v20);
      v33 = 2;
      sub_1210FD(v30, SWORD2(v12), (int)v25);
      if ( byte_199CAE == 4 )
      {
        v21 = a3[i + 5];
        v26 = *a3;
        v17 = sub_BB695(v26, i);
        sprintf(v25, "%s: %d", v17, v21);
      }
      else
      {
        v27 = *a3;
        v26 = i;
        v22 = sub_BB695(v27, i);
        v18 = a3[v26 + 5];
        v16 = (char *)sub_CDF5C(14);
        sprintf(v25, v16, v18, v22);
      }
      v27 = (int16_t)(185 - 9 * (v33 + 1));
      v13 = (v4 + 1) * (261 / ((int16_t)v32 + 1));
      v26 = v13 + v24;
      v14 = 185 - 9 * ++v33;
      sub_1210FD(v13 + v24, v14, (int)v25);
      sub_C5D55();
      v23 = a3[i + 5];
      v15 = (char *)sub_CDF5C(124);
      ++v4;
      result = sprintf(v25, v15, v23);
    }
  }
  if ( v4 != word_1828D1 )
  {
    byte_182ACA = 1;
    word_1828D1 = v4;
  }
  return result;
}
// B8A27: variable 'v24' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1828D1: using guessed type int16_t word_1828D1;
// 182ACA: using guessed type char byte_182ACA;
// 197F98: using guessed type int dword_197F98;
// 199CAE: using guessed type char byte_199CAE;
// 19F378: using guessed type int dword_19F378;


//----- (000B8BC7) --------------------------------------------------------
void sub_B8BC7()
{
  int v0; // eax
  int v1; // [esp+0h] [ebp-4h] BYREF

  v1 = 0;
  if ( byte_182ACA )
  {
    sub_1298DE(2, 41, 259, 184);
    sub_12A478(1, 40, dword_19F36C);
    sub_BAF3C(2u, *(_BYTE *)dword_19F378);
    v0 = sub_CDF5C(187);
    sub_1210FD(130, 11 * v1++ + 50, v0);
    sub_B8DBE(dword_19F378, &v1);
    sub_B8E43((int16_t *)dword_19F378, &v1);
    sub_B896D(1, (int16_t)(11 * (v1 + 1) + 50), (int16_t *)dword_19F378);
  }
}
// 182ACA: using guessed type char byte_182ACA;
// 19F36C: using guessed type int dword_19F36C;
// 19F378: using guessed type int dword_19F378;


//----- (000B8C8B) --------------------------------------------------------
void sub_B8C8B()
{
  int v0; // eax
  int v1; // [esp+0h] [ebp-4h] BYREF

  v1 = 0;
  if ( byte_182ACA )
  {
    sub_1298DE(379, 41, 638, 184);
    sub_12A478(378, 40, dword_19F36C);
    sub_BAF3C(2u, *(_BYTE *)dword_19F37C);
    v0 = sub_CDF5C(256);
    sub_1210FD(508, 11 * v1++ + 50, v0);
    sub_B8DBE(dword_19F37C, &v1);
    sub_B8E43((int16_t *)dword_19F37C, &v1);
    sub_B896D(378, (int16_t)(11 * (v1 + 1) + 50), (int16_t *)dword_19F37C);
  }
}
// 182ACA: using guessed type char byte_182ACA;
// 19F36C: using guessed type int dword_19F36C;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B8D4A) --------------------------------------------------------
int __fastcall sub_B8D4A(int a1, int a2, _WORD *a3, int a4)
{
  int16_t v4; // cx
  char *v5; // eax
  uint16_t v6; // dx
  int result; // eax
  _BYTE v9[500]; // [esp+0h] [ebp-1F4h] BYREF

  if ( a4 == dword_19F378 )
    v4 = 1;
  else
    v4 = 378;
  v5 = (char *)sub_CDF5C(75);
  v6 = (uint64_t)sprintf(v9, v5, &unk_179DC6, a1, &unk_179DC3, a2) >> 32;
  result = sub_103BC4(v4 + 9, v6, 243, (int)v9, 0);
  ++*a3;
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19F378: using guessed type int dword_19F378;


//----- (000B8DBE) --------------------------------------------------------
int __fastcall sub_B8DBE(int result, _WORD *a2)
{
  uint8_t *v2; // esi

  v2 = (uint8_t *)result;
  if ( *(_BYTE *)(result + 36) )
    result = sub_B8D4A((int)off_17E0EE, *(uint8_t *)(result + 36), a2, result);
  if ( v2[41] )
    result = sub_B8D4A(*(int *)((char *)&off_17E079 + 13 * v2[41]), v2[42], a2, (int)v2);
  if ( v2[43] )
    result = sub_B8D4A(*(int *)((char *)&off_17E079 + 13 * v2[43]), v2[44], a2, (int)v2);
  if ( v2[45] )
    return sub_B8D4A(*(int *)((char *)&off_17E079 + 13 * v2[45]), v2[46], a2, (int)v2);
  return result;
}
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 17E0EE: using guessed type _UNKNOWN *off_17E0EE;


//----- (000B8E43) --------------------------------------------------------
void __fastcall sub_B8E43(int16_t *a1, _WORD *a2)
{
  int16_t v5; // dx
  int v6; // eax
  int16_t v7; // dx
  int v8; // eax
  int16_t v9; // dx
  int v10; // eax
  int16_t v11; // dx
  int v12; // eax
  char v13[52]; // [esp+0h] [ebp-34h] BYREF

  if ( *((_BYTE *)a1 + 47) )
  {
    v5 = *((char *)a1 + 47);
    v6 = sub_CDF5C(437);
    sub_B8D4A(v6, v5, a2, (int)a1);
  }
  if ( *((_BYTE *)a1 + 49) )
  {
    v7 = *((char *)a1 + 49);
    v8 = sub_CDF5C(364);
    sub_B8D4A(v8, v7, a2, (int)a1);
  }
  if ( *((_BYTE *)a1 + 50) )
  {
    v9 = *((uint8_t *)a1 + 50);
    v10 = sub_CDF5C(497);
    sub_B8D4A(v10, v9, a2, (int)a1);
  }
  if ( *((char *)a1 + 51) > 0 && sub_110B5C() )
  {
    v11 = *((char *)a1 + 51);
    v12 = sub_CDF5C(123);
    sub_B8D4A(v12, v11, a2, (int)a1);
  }
  if ( *((char *)a1 + 54) > 0 )
  {
    sub_97565(v13, *a1, *((char *)a1 + 54));
    sub_B8D4A((int)v13, a1[26], a2, (int)a1);
  }
  JUMPOUT(0xB8777);
}
// B8EF6: control flows out of bounds to B8777


//----- (000B8EFB) --------------------------------------------------------
int __fastcall sub_B8EFB(int a1, int a2)
{
  int v3; // edi
  int result; // eax

  v3 = 3753 * a2;
  result = v3 + dword_197F98;
  if ( *(_BYTE *)(v3 + dword_197F98 + 38) != 2 )
  {
    sub_137D86(a1, (int)&unk_1828D3 + 8 * *(uint8_t *)(result + 38), 192, 8);
    return sub_137D86(a1, (int)&unk_182913 + 8 * *(uint8_t *)(v3 + dword_197F98 + 38), 232, 4);
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (000B8F5F) --------------------------------------------------------
void __fastcall sub_B8F5F(int a1)
{
  int *v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int16_t *v7; // eax
  char *v8; // edx
  int64_t v9; // rax
  signed int v10; // ebx
  int64_t v11; // rax
  int v12; // eax
  int v13; // edx
  int64_t v14; // rax
  int16_t v15; // di
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // [esp+0h] [ebp-30h] BYREF
  int v20; // [esp+4h] [ebp-2Ch] BYREF
  int v21; // [esp+8h] [ebp-28h]
  int v22; // [esp+Ch] [ebp-24h] BYREF
  char *v23; // [esp+10h] [ebp-20h]
  int v24; // [esp+14h] [ebp-1Ch] BYREF
  int v25; // [esp+18h] [ebp-18h] BYREF
  int v26; // [esp+1Ch] [ebp-14h] BYREF
  int v27; // [esp+20h] [ebp-10h] BYREF
  int v28; // [esp+24h] [ebp-Ch] BYREF
  int v29; // [esp+28h] [ebp-8h]
  char *v30; // [esp+2Ch] [ebp-4h]

  sub_B7C8D(a1, &v19, &v28);
  v2 = &v27;
  sub_B7D48(*(_DWORD *)(a1 + 13), &v27, &v26);
  LOWORD(v3) = *(_WORD *)a1;
  v4 = v19 + v3;
  v25 = v4;
  LOWORD(v4) = *(_WORD *)(a1 + 2);
  v5 = v28 + v4;
  v24 = v5;
  LOWORD(v5) = *(_WORD *)a1;
  v6 = v19 + v5;
  v20 = v6;
  LOWORD(v6) = *(_WORD *)(a1 + 2);
  v22 = v28 + v6;
  v7 = *(int16_t **)(a1 + 13);
  LOWORD(v2) = *v7;
  v8 = (char *)v2 + v27;
  v30 = v8;
  LOWORD(v8) = v7[1];
  v23 = &v8[v26];
  v9 = (int16_t)v25 - (*v7 + (int16_t)v27);
  v10 = (HIDWORD(v9) ^ v9) - HIDWORD(v9);
  v11 = (int16_t)v24 - (*(int16_t *)(*(_DWORD *)(a1 + 13) + 2) + (int16_t)v26);
  if ( v10 >= (int)((HIDWORD(v11) ^ v11) - HIDWORD(v11)) )
  {
    v12 = **(int16_t **)(a1 + 13) + (int16_t)v27;
    v13 = (int16_t)v25;
  }
  else
  {
    v12 = *(int16_t *)(*(_DWORD *)(a1 + 13) + 2) + (int16_t)v26;
    v13 = (int16_t)v24;
  }
  v14 = v13 - v12;
  v15 = (WORD2(v14) ^ v14) - WORD2(v14);
  v21 = sub_B92A4(*(_BYTE *)(a1 + 7), SHIDWORD(v14));
  v16 = *(char *)(a1 + 9) * (v15 / 5);
  v29 = v16;
  if ( v15 < (int16_t)v16 )
    LOWORD(v16) = v15;
  if ( (v16 & 0x8000u) == 0 )
  {
    if ( v15 >= (int16_t)v29 )
      LOWORD(v17) = v29;
    else
      LOWORD(v17) = v15;
    v17 = (int16_t)v17;
  }
  else
  {
    v17 = 0;
  }
  sub_A6A2E((int16_t *)&v25, (int16_t *)&v24, (int16_t)v30, (int16_t)v23, v17);
  v18 = v15;
  if ( (int16_t)v21 + (int16_t)v29 <= v15 )
    v18 = (int16_t)v21 + (int16_t)v29;
  sub_A6A2E((int16_t *)&v20, (int16_t *)&v22, (int16_t)v30, (int16_t)v23, v18);
  sub_B90BA(v25, v24, v22, v20, v15, a1, *(_BYTE *)(a1 + 7));
  JUMPOUT(0xB7C86);
}
// B90B5: control flows out of bounds to B7C86
// B8F86: variable 'v3' is possibly undefined


//----- (000B90BA) --------------------------------------------------------
char __userpurge sub_B90BA( int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int16_t v9; // [esp+0h] [ebp-28h]
  int v10; // [esp+4h] [ebp-24h]
  int16_t v11; // [esp+8h] [ebp-20h]
  int16_t v12; // [esp+Ch] [ebp-1Ch]
  int16_t v13; // [esp+10h] [ebp-18h]
  int16_t v14; // [esp+14h] [ebp-14h]
  int16_t v15; // [esp+18h] [ebp-10h]
  int16_t v16; // [esp+1Ch] [ebp-Ch]
  int16_t v17; // [esp+20h] [ebp-8h]
  int16_t v18; // [esp+24h] [ebp-4h]

  v9 = a1;
  if ( a4 == a1 && a2 == a3 )
    return a1;
  if ( !a7 )
  {
    v7 = dword_19F378;
LABEL_8:
    v10 = v7;
    goto LABEL_9;
  }
  if ( a7 == 1 )
  {
    v7 = dword_19F37C;
    goto LABEL_8;
  }
LABEL_9:
  LOBYTE(a1) = *(_BYTE *)(v10 + 45);
  if ( (uint8_t)a1 < 0x80u )
  {
    if ( (uint8_t)a1 >= 0x49u )
    {
      if ( (uint8_t)a1 <= 0x49u )
      {
        v13 = 183;
        a5 = 11;
        v16 = 40;
        v15 = 4;
        v14 = 186;
        a6 = 0;
        v12 = 189;
        v17 = 0;
      }
      else
      {
        if ( (_BYTE)a1 != 101 )
          goto LABEL_26;
        v13 = 236;
        a5 = 4;
        v16 = 10;
        v15 = 1;
        v14 = 236;
        v12 = 239;
        a6 = 0;
        v17 = 1;
      }
      v18 = 0;
LABEL_25:
      v11 = a6;
    }
  }
  else if ( (uint8_t)a1 <= 0x80u )
  {
    v13 = 236;
    a5 = 4;
    v16 = 40;
    v15 = 2;
    v14 = 236;
    v12 = 239;
    v17 = 1;
    v18 = 1;
    v11 = 1;
    a6 = 0;
  }
  else if ( (uint8_t)a1 >= 0x8Au )
  {
    if ( (uint8_t)a1 <= 0x8Au )
    {
      v13 = 236;
      a5 = 4;
      v16 = 70;
      v15 = 2;
      v14 = 236;
      v12 = 239;
      a6 = 1;
      v17 = 0;
      v18 = 0;
    }
    else
    {
      if ( (_BYTE)a1 != 0x91 )
        goto LABEL_26;
      v13 = 95;
      a5 = 11;
      v16 = 10;
      v15 = 2;
      v14 = 96;
      v12 = 104;
      a6 = 1;
      v17 = 0;
      v18 = 0;
    }
    goto LABEL_25;
  }
LABEL_26:
  if ( a4 != v9 && a2 != a3 )
    LOBYTE(a1) = sub_13BEC4(v9, a2, a4, a3, v13, a5, v16, v15, v14, v12, a6, v17, v18, v11);
  return a1;
}
// B90EF: variable 'v10' is possibly undefined
// B9299: variable 'v13' is possibly undefined
// B9299: variable 'v16' is possibly undefined
// B9299: variable 'v15' is possibly undefined
// B9299: variable 'v14' is possibly undefined
// B9299: variable 'v12' is possibly undefined
// B9299: variable 'v17' is possibly undefined
// B9299: variable 'v18' is possibly undefined
// B9299: variable 'v11' is possibly undefined
// 19F378: using guessed type int dword_19F378;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B92A4) --------------------------------------------------------
int __fastcall sub_B92A4( int a1, int a2)
{
  uint8_t v2; // al

  if ( a1 )
  {
    if ( a1 == 1 )
      a2 = dword_19F37C;
  }
  else
  {
    a2 = dword_19F378;
  }
  v2 = *(_BYTE *)(a2 + 45);
  if ( v2 < 0x80u )
  {
    if ( v2 < 0x49u )
      return 1;
    if ( v2 > 0x49u )
    {
      if ( v2 == 101 )
        return 100;
      return 1;
    }
    return 70;
  }
  if ( v2 <= 0x80u )
    return 20;
  if ( v2 == 0x8A )
    return 70;
  return 1;
}
// 19F378: using guessed type int dword_19F378;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B92F8) --------------------------------------------------------
int __fastcall sub_B92F8(int a1, int a2, int a3, int a4)
{
  char v5; // al
  uint8_t v6; // al
  int result; // eax

  v5 = *(_BYTE *)(a1 + 7);
  if ( v5 )
  {
    if ( v5 == 1 )
      a4 = dword_19F37C;
  }
  else
  {
    a4 = dword_19F378;
  }
  v6 = *(_BYTE *)(a4 + 45);
  if ( v6 < 0x80u )
  {
    if ( v6 >= 0x49u )
    {
      if ( v6 <= 0x49u )
      {
        a3 = 9;
      }
      else if ( v6 == 101 )
      {
        a3 = 1;
      }
    }
  }
  else if ( v6 <= 0x80u )
  {
    a3 = 19;
  }
  else if ( v6 >= 0x8Au )
  {
    if ( v6 <= 0x8Au )
    {
      a3 = 13;
    }
    else if ( v6 == 0x91 )
    {
      a3 = 12;
    }
  }
  result = sub_147D7(a3);
  *(_DWORD *)(a1 + 17) = result;
  return result;
}
// 19F378: using guessed type int dword_19F378;
// 19F37C: using guessed type int dword_19F37C;


//----- (000B937B) --------------------------------------------------------
unsigned int sub_B937B()
{
  _BYTE *v0; // eax
  unsigned int result; // eax

  v0 = (_BYTE *)sub_CDF5C(12);
  result = sub_11438B(0, 0, 639, 479, v0, 0);
  word_19F3A0 = result;
  return result;
}
// 19F3A0: using guessed type int16_t word_19F3A0;


//----- (000B93A8) --------------------------------------------------------
_DWORD *sub_B93A8()
{
  _DWORD *result; // eax

  result = sub_126B42((int)aColonyLbx, 6, dword_192ED4);
  dword_19F394 = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 19F394: using guessed type int dword_19F394;


//----- (000B93C7) --------------------------------------------------------
void sub_B93C7()
{
  sub_11C2F0();
  JUMPOUT(0xB937E);
}
// B93CF: control flows out of bounds to B937E


//----- (000B93D1) --------------------------------------------------------
int sub_B93D1()
{
  int v0; // eax
  int v1; // eax
  char *v2; // eax
  int16_t v3; // dx
  int result; // eax
  int16_t *v5; // [esp-4h] [ebp-1F8h]
  _BYTE v6[500]; // [esp+0h] [ebp-1F4h] BYREF

  sub_124D41();
  if ( byte_182ACA )
  {
    sub_128C32(0, 0, 639, 479, 0);
    v0 = sub_BBA8E(1);
    sub_12A478(0, 0, v0);
    v1 = sub_BBA8E(0);
    sub_12A478(0, 0, v1);
    sub_BB04E(4u);
    v5 = sub_77B28(dword_19F7BC);
    v2 = (char *)sub_CDF5C(229);
    sprintf(v6, v2, v5);
    sub_1210FD(319, 10, (int)v6);
  }
  if ( byte_182ACA )
  {
    sub_124DEC();
    sub_124C08();
    byte_182ACA = 0;
  }
  sub_12A478(0, 0, dword_19F394);
  v3 = *(_WORD *)(dword_19F394 + 4);
  result = (int16_t)(*(_WORD *)(dword_19F394 + 6) - 1) - 1;
  if ( v3 >= result )
    result = sub_B953E(dword_19F7BC);
  switch ( v3 )
  {
    case 1:
      result = sub_147D7(58);
      dword_19F398 = result;
      break;
    case 2:
      result = sub_147D7(58);
      dword_19F390 = result;
      break;
    case 57:
      sub_112C96(dword_19F398, 2);
      result = sub_147D7(57);
      dword_19F38C = result;
      break;
    case 62:
      sub_112C96(dword_19F390, 2);
      result = sub_147D7(57);
      dword_19F39C = result;
      break;
  }
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 19F38C: using guessed type int dword_19F38C;
// 19F390: using guessed type int dword_19F390;
// 19F394: using guessed type int dword_19F394;
// 19F398: using guessed type int dword_19F398;
// 19F39C: using guessed type int dword_19F39C;
// 19F7BC: using guessed type int dword_19F7BC;


//----- (000B953E) --------------------------------------------------------
int __fastcall sub_B953E( int a1)
{
  int v2; // edx
  char *v3; // eax
  char *v4; // eax
  _BYTE *v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  char *v10; // eax
  int result; // eax
  int v12; // ecx
  int16_t v13; // ax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // [esp-Ch] [ebp+72h]
  int16_t *v18; // [esp-8h] [ebp+76h]
  int v19; // [esp-8h] [ebp+76h]
  int16_t *v20; // [esp-4h] [ebp+7Ah]
  int v21; // [esp-4h] [ebp+7Ah]
  int v22; // [esp-4h] [ebp+7Ah]
  int v23; // [esp-4h] [ebp+7Ah]
  int v24; // [esp-4h] [ebp+7Ah]
  int v25; // [esp-4h] [ebp+7Ah]
  int v26; // [esp-4h] [ebp+7Ah]
  _BYTE v27[500]; // [esp+0h] [ebp+7Eh] BYREF
  int v28; // [esp+1F4h] [ebp+272h]

  sub_BB04E(4u);
  v2 = *(int16_t *)(dword_1930D4 + 17 * a1);
  if ( v2 == -1 )
  {
    v20 = sub_77B28(a1);
    v3 = (char *)sub_CDF5C(70);
    sprintf(v27, v3, v20);
  }
  else
  {
    v21 = dword_197F98 + 3753 * *(char *)(dword_192B18 + 361 * v2) + 21;
    v18 = sub_77B28(a1);
    v4 = (char *)sub_CDF5C(40);
    sprintf(v27, v4, v18, v21);
  }
  sub_1212B3(20, 40, (int)v27);
  v5 = (_BYTE *)(dword_1930D4 + 17 * a1);
  v6 = *(int16_t *)v5;
  if ( v6 == -1 )
  {
    if ( v5[4] != 3 )
    {
      v10 = (char *)sub_CDF5C(306);
      sprintf(v27, v10);
      return sub_1212B3(20, 60, (int)v27);
    }
    if ( byte_199CAE == 4 )
    {
      v22 = dword_18F990[(uint8_t)v5[8]];
      v8 = (uint8_t)v5[5];
      goto LABEL_7;
    }
    v23 = dword_18F990[(uint8_t)v5[8]];
    v9 = (uint8_t)v5[5];
  }
  else
  {
    v7 = 361 * v6;
    if ( byte_199CAE == 4 )
    {
      v8 = (uint8_t)v5[5];
      v22 = dword_18F990[*(uint8_t *)(v7 + dword_192B18 + 226)];
LABEL_7:
      sprintf(v27, "%s, %s", dword_192BE0[v8], v22);
      goto LABEL_10;
    }
    v9 = (uint8_t)v5[5];
    v23 = dword_18F990[*(uint8_t *)(v7 + dword_192B18 + 226)];
  }
  v19 = dword_192BE0[v9];
  v17 = (char *)sub_CDF5C(45);
  sprintf(v27, v17, v19, v23);
LABEL_10:
  sub_103915(0);
  v12 = 17 * a1;
  sub_E0B4F((int16_t *)(v12 + dword_1930D4), word_19999C);
  v24 = v13;
  v14 = (char *)sub_CDF5C(31);
  sprintf(v27, v14, v24);
  v28 = 5;
  sub_1212B3(20, 80, (int)v27);
  v25 = dword_192BF4[*(uint8_t *)(v12 + dword_1930D4 + 10)];
  v15 = (char *)sub_CDF5C(374);
  sprintf(v27, v15, v25);
  sub_1212B3(20, 20 * v28, (int)v27);
  sub_1212B3(20, 120, dword_192C74[*(uint8_t *)(v12 + dword_1930D4 + 6)]);
  result = v12 + dword_1930D4;
  if ( *(_BYTE *)(v12 + dword_1930D4 + 15) )
  {
    v26 = dword_18F9B8[*(char *)(result + 15)];
    v16 = (char *)sub_CDF5C(70);
    sprintf(v27, v16, v26);
    return sub_103915(0);
  }
  return result;
}
// B9705: variable 'v13' is possibly undefined
// 103915: using guessed type _DWORD __stdcall sub_103915(int16_t);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 18F990: using guessed type int dword_18F990[];
// 18F9B8: using guessed type int dword_18F9B8[];
// 192B18: using guessed type int dword_192B18;
// 192BE0: using guessed type int dword_192BE0[];
// 192BF4: using guessed type int dword_192BF4[];
// 192C74: using guessed type int dword_192C74[];
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199CAE: using guessed type char byte_199CAE;


//----- (000B9802) --------------------------------------------------------
int __usercall sub_B9802(int a1, int a2, int16_t *a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // edx
  int v6; // eax
  int16_t v7; // bx
  int16_t v8; // dx
  int16_t v9; // ax
  int result; // eax
  int v11; // [esp+0h] [ebp-4h] BYREF

  v3 = sub_BAEFE();
  sub_BB954(v3, a1);
  sub_12B65C();
  dword_19F7B8 = word_199830;
  dword_19F7C8 = word_199832;
  byte_182ACE = 1;
  dword_19F7BC = sub_79C54(word_199830, word_199832);
  byte_182AC9 = 1;
  v4 = dword_192ED4;
  dword_19F7A8 = *(int16_t *)(dword_1930D4 + 17 * dword_19F7BC);
  dword_19F82C = dword_19F7B8;
  byte_182AC8 = 0;
  dword_19F394 = (int)sub_126B42((int)aColonyLbx, 6, dword_192ED4);
  nullsub_7(dword_19F394, 6);
  if ( sub_C5C85() )
  {
    sub_C5BB9();
    a2 = 479;
    v4 = 639;
    sub_128C32(0, 0, 639, 479, 0);
    sub_BF55A();
  }
  if ( sub_C5C85() )
  {
    sub_132C80(100);
    sub_131922(0, 255);
  }
  sub_131F7B();
  sub_BAE88();
  sub_11C2F0();
  sub_B937B();
  byte_182ACA = 1;
  sub_107AF(&v11);
  sub_1191CA((int)sub_B93D1, 1);
  sub_B93D1();
  sub_C5C44();
  sub_124C08();
  HIWORD(v5) = HIWORD(dword_192B18);
  if ( *(_BYTE *)(dword_192B18 + 361 * dword_19F7A8 + 303) == 4 )
  {
    a2 = -1;
    v4 = -1;
    HIWORD(v5) = -1;
    if ( sub_BC972(dword_19F7A8, -1, -1, -1, -1, 1) )
    {
      sub_CD969();
      sub_BB1A6(dword_19F7A8, (int)a3);
    }
  }
  do
  {
    sub_12C2A0();
    sub_11C2F0();
    sub_B937B();
    sub_B93D1();
    LOWORD(v5) = *(_WORD *)(dword_19F394 + 4);
    v6 = sub_1077D(dword_19F394, v5, v4, a3);
    v5 = sub_1171AB(v6, v5, v4, a2);
    sub_114177();
    sub_12C2C6(1);
  }
  while ( !(_WORD)v5 );
  sub_BB2CB((int)a3);
  sub_11C2F0();
  sub_119281();
  sub_112C96(dword_19F398, 10);
  sub_112C96(dword_19F390, 10);
  sub_112C96(dword_19F38C, 10);
  sub_112C96(dword_19F39C, 10);
  if ( (uint16_t)sub_BA8BF(*(uint8_t *)(dword_1930D4
                                                      + 17 * *(int16_t *)(dword_192B18 + 361 * dword_19F7A8 + 2)
                                                      + 2)) == 1
    && byte_199BE2 )
  {
    v7 = *(uint8_t *)(17 * *(int16_t *)(dword_192B18 + 361 * dword_19F7A8 + 2) + dword_1930D4 + 2);
    v8 = sub_923C4();
    v9 = sub_923BE();
    sub_92281(v9, v8, v7, 1);
  }
  result = sub_107BA(&v11);
  byte_182ACE = 0;
  word_199A08 = 1;
  return result;
}
// BB9FD: using guessed type int __fastcall nullsub_7(_DWORD, _DWORD);
// 182AC8: using guessed type char byte_182AC8;
// 182AC9: using guessed type char byte_182AC9;
// 182ACA: using guessed type char byte_182ACA;
// 182ACE: using guessed type char byte_182ACE;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 1930D4: using guessed type int dword_1930D4;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 199A08: using guessed type int16_t word_199A08;
// 199BE2: using guessed type char byte_199BE2;
// 19F38C: using guessed type int dword_19F38C;
// 19F390: using guessed type int dword_19F390;
// 19F394: using guessed type int dword_19F394;
// 19F398: using guessed type int dword_19F398;
// 19F39C: using guessed type int dword_19F39C;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F7B8: using guessed type int dword_19F7B8;
// 19F7BC: using guessed type int dword_19F7BC;
// 19F7C8: using guessed type int dword_19F7C8;
// 19F82C: using guessed type int dword_19F82C;


//----- (000B9A8C) --------------------------------------------------------
void sub_B9A8C()
{
  int16_t v0; // ax
  int v1; // eax

  while ( 1 )
  {
    v0 = sub_B9AD7(word_182974);
    if ( v0 == -1 )
      break;
    v1 = 361 * word_182974 + dword_192B18 + 4 * v0;
    if ( (*(_BYTE *)(v1 + 13) & 2) == 0 )
      *(_BYTE *)(v1 + 13) |= 2u;
  }
  word_182974 = -1;
  sub_C0AF4();
}
// 182974: using guessed type int16_t word_182974;
// 192B18: using guessed type int dword_192B18;


//----- (000B9AD7) --------------------------------------------------------
int __fastcall sub_B9AD7( int a1)
{
  int result; // eax
  int v3; // edx

  for ( result = 0; ; ++result )
  {
    v3 = dword_192B18 + 361 * a1;
    if ( (int16_t)result >= *(uint8_t *)(v3 + 10) )
      break;
    if ( (*(_BYTE *)(v3 + 4 * (int16_t)result + 13) & 2) == 0 )
      return result;
  }
  return -1;
}
// 192B18: using guessed type int dword_192B18;


//----- (000B9B0F) --------------------------------------------------------
int __fastcall sub_B9B0F( int a1)
{
  int v2; // edx
  int16_t i; // ax
  int v4; // ebx

  v2 = 0;
  for ( i = 0; ; ++i )
  {
    v4 = dword_192B18 + 361 * a1;
    if ( i >= *(uint8_t *)(v4 + 10) )
      break;
    if ( (*(_BYTE *)(v4 + 4 * i + 13) & 2) == 0 )
      ++v2;
  }
  return v2;
}
// 192B18: using guessed type int dword_192B18;


//----- (000B9B49) --------------------------------------------------------
void __fastcall sub_B9B49(int a1, int a2)
{
  int v3; // ebx
  int16_t v4; // ax
  int v5; // esi
  int16_t i; // cx
  int v7; // ebx
  int16_t v8; // ax
  int v9; // eax

  if ( word_182974 != -1 && !byte_182ACA && (int16_t)sub_B9AD7(word_182974) != -1 && !sub_7A7F6() && byte_182976 != 1 )
  {
    sub_1172FC();
    sub_11E718();
    sub_1172D4();
    sub_128AB6(0, 0, 639, 479);
    sub_12B634();
    v3 = sub_BBA8E(15);
    v4 = a1;
    v5 = a1 + 5;
    sub_12A478(v4, a2, v3);
    for ( i = 0; ; ++i )
    {
      v9 = dword_192B18 + 361 * word_182974;
      if ( i >= *(uint8_t *)(v9 + 10) )
        break;
      if ( (*(_BYTE *)(4 * i + v9 + 13) & 2) == 0 )
      {
        v7 = sub_BB4A9(word_182974, i);
        v8 = v5;
        v5 += 20;
        sub_12A478(v8, a2 - 10, v7);
      }
    }
    sub_12B65C();
  }
}
// 182974: using guessed type int16_t word_182974;
// 182976: using guessed type char byte_182976;
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;


//----- (000B9C3D) --------------------------------------------------------
void __usercall sub_B9C3D( int a1, int a2, int a3)
{
  int v4; // eax
  int v5; // edi
  int v6; // [esp+4h] [ebp-8h]

  if ( (*(_DWORD *)(dword_192B18 + 361 * a1 + 4 * (int16_t)a2 + 12) & 0xF) == 9 )
  {
    v4 = sub_CDF5C(382);
    sub_C5B5F(v4);
    sub_BB2CB(a3);
  }
  else
  {
    v5 = a2;
    word_182974 = a1;
    while ( 1 )
    {
      v6 = 361 * a1;
      if ( (int16_t)v5 >= *(uint8_t *)(v6 + dword_192B18 + 10) )
        break;
      if ( sub_B9CE3(a1, a2, a1, v5) )
        *(_BYTE *)(dword_192B18 + v6 + 4 * (int16_t)v5 + 13) &= ~2u;
      ++v5;
    }
    sub_E2A70(a1, v5);
    sub_C0ABC();
  }
  JUMPOUT(0xB9C37);
}
// B9C7C: control flows out of bounds to B9C37
// 182974: using guessed type int16_t word_182974;
// 192B18: using guessed type int dword_192B18;


//----- (000B9CE3) --------------------------------------------------------
_BOOL1 __fastcall sub_B9CE3( int a1, int a2, int a3, int a4)
{
  int v6; // edi
  int16_t v7; // bx
  int v8; // edx
  int v9; // eax
  _BOOL1 result; // al
  int v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]

  v12 = 361 * a1;
  v11 = 361 * a3;
  v6 = 4 * a4;
  result = 0;
  if ( *(_DWORD *)(v6 + v11 + dword_192B18 + 12) << 23 >> 30 == *(_DWORD *)(4 * a2 + v12 + dword_192B18 + 12) << 23 >> 30 )
  {
    v7 = sub_BCACF(a1, a2);
    if ( v7 == (uint16_t)sub_BCACF(a3, a4) )
    {
      v8 = 4 * a2 + dword_192B18 + v12;
      v9 = v6 + v11 + dword_192B18;
      if ( (*(_DWORD *)(v8 + 12) & 0xF) == (*(_DWORD *)(v9 + 12) & 0xF)
        && *(_DWORD *)(v8 + 12) << 21 >> 31 == *(_DWORD *)(v9 + 12) << 21 >> 31 )
      {
        return 1;
      }
    }
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;


//----- (000B9DA2) --------------------------------------------------------
int64_t __fastcall sub_B9DA2( int a1, int a2, int a3)
{
  int v4; // edi
  int16_t v5; // ax
  int v6; // eax
  int16_t v7; // ax
  char *v8; // eax
  int v10; // [esp-8h] [ebp-Ch]
  int v11; // [esp-4h] [ebp-8h]
  int v12; // [esp+0h] [ebp-4h]

  if ( byte_199CAE == 4 )
  {
    v4 = 361 * a1;
    v5 = sub_BCACF(a1, a2);
    v11 = sub_BB147(v5);
    sub_BB121((*(_DWORD *)(4 * a2 + v4 + dword_192B18 + 12) & 0x400) != 0);
    sub_BAE1A(a1, a2);
    v6 = sub_BB0F0((uint16_t)(*(_WORD *)(4 * a2 + v4 + dword_192B18 + 12) << 7) >> 14);
  }
  else
  {
    v12 = 361 * a1;
    v11 = sub_BB0F0((uint16_t)(*(_WORD *)(dword_192B18 + v12 + 4 * a2 + 12) << 7) >> 14);
    v7 = sub_BCACF(a1, a2);
    sub_BB147(v7);
    sub_BAE1A(a1, a2);
    v6 = sub_BB121((*(_DWORD *)(v12 + dword_192B18 + 4 * a2 + 12) & 0x400) != 0);
  }
  v10 = v6;
  v8 = (char *)sub_CDF5C(76);
  return sprintf(a3, v8, v10, v11);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192B18: using guessed type int dword_192B18;
// 199CAE: using guessed type char byte_199CAE;


//----- (000B9E94) --------------------------------------------------------
char __fastcall sub_B9E94( int a1)
{
  int v1; // edi
  int v2; // eax
  int16_t v3; // ax
  int16_t v4; // dx
  int16_t v5; // si
  char *v6; // eax
  int16_t v7; // ax
  char *v8; // eax
  char *v9; // eax
  int16_t v10; // ax
  char *v11; // eax
  char *v12; // eax
  char v13; // al
  int v14; // ebx
  int16_t v15; // dx
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
  int v28; // eax
  int16_t v29; // dx
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  char v35; // [esp-14h] [ebp-402h]
  int v36; // [esp-Ch] [ebp-3FAh]
  int v37; // [esp-8h] [ebp-3F6h]
  int v38; // [esp-8h] [ebp-3F6h]
  int v39; // [esp-8h] [ebp-3F6h]
  int v40; // [esp-8h] [ebp-3F6h]
  int16_t v41; // [esp-8h] [ebp-3F6h]
  int16_t v42; // [esp-8h] [ebp-3F6h]
  int16_t v43; // [esp-8h] [ebp-3F6h]
  int16_t v44; // [esp-8h] [ebp-3F6h]
  int16_t v45; // [esp-8h] [ebp-3F6h]
  int16_t v46; // [esp-8h] [ebp-3F6h]
  int16_t v47; // [esp-8h] [ebp-3F6h]
  int16_t v48; // [esp-8h] [ebp-3F6h]
  int16_t v49; // [esp-8h] [ebp-3F6h]
  int v50; // [esp-4h] [ebp-3F2h]
  int v51; // [esp-4h] [ebp-3F2h]
  int v52; // [esp-4h] [ebp-3F2h]
  char v53; // [esp-4h] [ebp-3F2h]
  char v54; // [esp-4h] [ebp-3F2h]
  char v55; // [esp-4h] [ebp-3F2h]
  int16_t v56; // [esp+0h] [ebp-3EEh]
  int16_t v57; // [esp+4h] [ebp-3EAh]
  char v58[1000]; // [esp+8h] [ebp-3E6h] BYREF
  _BYTE v59[52]; // [esp+3F0h] [ebp+2h] BYREF
  char v60[20]; // [esp+424h] [ebp+36h] BYREF
  char v61[20]; // [esp+438h] [ebp+4Ah] BYREF
  _BYTE v62[9]; // [esp+44Ch] [ebp+5Eh] BYREF
  char v63; // [esp+455h] [ebp+67h]
  char v64; // [esp+456h] [ebp+68h]
  char v65; // [esp+457h] [ebp+69h]
  uint8_t v66; // [esp+459h] [ebp+6Bh]
  char v67; // [esp+45Ah] [ebp+6Ch]
  int v68; // [esp+45Ch] [ebp+6Eh]
  int v69; // [esp+460h] [ebp+72h]
  int v70; // [esp+464h] [ebp+76h]
  int v71; // [esp+468h] [ebp+7Ah]
  char v72; // [esp+46Ch] [ebp+7Eh]

  v72 = 0;
  v1 = 0;
  if ( a1 < 0 )
  {
    v2 = sub_CDF5C(528);
    LOBYTE(v3) = sub_C5B5F(v2);
    return v3;
  }
  v71 = 0;
  v4 = sub_B9AD7(word_182974);
  v5 = v4;
  if ( v4 != -1 )
    sub_B9DA2(word_182974, v4, (int)v59);
  while ( v5 != -1 )
  {
    if ( word_182974 != v57 )
    {
      v68 = dword_192B18 + 361 * word_182974;
      sub_FEE4C((char *)v68, v5, dword_192B18 + 361 * v57, v62);
      if ( v62[0] && (v66 || v63) )
      {
        if ( v66 && !v63 && (_WORD)v1 != 1 )
        {
          v50 = v66;
          v6 = (char *)sub_CDF5C(521);
          sprintf(v58, v6, v50);
          sub_C0AF4();
          v1 = 1;
          goto LABEL_28;
        }
        if ( v63 && !v66 && (_WORD)v1 != 2 )
        {
          v7 = sub_B9B0F(word_182974);
          if ( (_WORD)v71 )
          {
            v51 = v7;
            v37 = (int16_t)v71;
            v9 = (char *)sub_CDF5C(515);
            sprintf(v58, v9, v37, v51);
          }
          else
          {
            v8 = (char *)sub_CDF5C(517);
            sprintf(v58, v8);
          }
          sub_C0AF4();
          v1 = 2;
          goto LABEL_28;
        }
        if ( v63 && v66 && (_WORD)v1 != 3 )
        {
          v10 = sub_B9B0F(word_182974);
          v52 = v66;
          if ( (_WORD)v71 )
          {
            v38 = v10;
            v36 = (int16_t)v71;
            v12 = (char *)sub_CDF5C(516);
            sprintf(v58, v12, v36, v38, v52);
          }
          else
          {
            v11 = (char *)sub_CDF5C(518);
            sprintf(v58, v11, v52);
          }
          sub_C0AF4();
          v1 = 3;
LABEL_28:
          sub_77658((int)v58);
          byte_182ACA = 1;
          v62[0] = v13;
          sub_C0ABC();
        }
      }
      if ( v62[0] )
      {
        if ( v64 )
          v72 = 1;
        v14 = *(_DWORD *)(4 * v5 + 361 * word_182974 + dword_192B18 + 12);
        v70 = 4 * v5;
        if ( (unsigned int)(v14 << 23) >> 30 != v56 && v56 != -1 )
        {
          LOBYTE(v3) = sub_BA5DA(word_182974, v5, v56);
          if ( !(_BYTE)v3 )
            return v3;
          v72 = 1;
          *(_BYTE *)(v70 + dword_192B18 + 361 * word_182974 + 13) &= ~2u;
        }
        ++v71;
        sub_FF116((char *)(361 * word_182974 + dword_192B18), v5, dword_192B18 + 361 * v57, 361 * word_182974);
      }
      else
      {
        v5 = -1;
        v15 = 0;
        if ( !v66 || v63 )
        {
          if ( !v63 || v66 )
          {
            if ( v63 && v66 )
            {
              v54 = v66;
              v40 = sub_CDF5C(252);
              v15 = 1;
              sub_C5AC8(v58, 0, v40, v54);
            }
          }
          else
          {
            v16 = sub_CDF5C(253);
            v15 = 1;
            sub_C5AC8(v58, 0, v16, v56);
          }
        }
        else
        {
          v53 = v66;
          v39 = sub_CDF5C(254);
          v15 = 1;
          sub_C5AC8(v58, 0, v39, v53);
        }
        if ( v62[4] )
        {
          v17 = sub_CDF5C(509);
          v41 = v15++;
          sub_C5AC8(v58, v41, v17, v56);
        }
        if ( v62[5] )
        {
          v18 = sub_CDF5C(577);
          v42 = v15++;
          sub_C5AC8(v58, v42, v18, v56);
        }
        if ( v62[7] )
        {
          v19 = sub_CDF5C(589);
          v43 = v15++;
          sub_C5AC8(v58, v43, v19, v56);
        }
        if ( v62[2] )
        {
          v20 = sub_CDF5C(519);
          v44 = v15++;
          sub_C5AC8(v58, v44, v20, v56);
        }
        if ( v62[6] )
        {
          v21 = sub_CDF5C(388);
          v45 = v15++;
          sub_C5AC8(v58, v45, v21, v56);
        }
        if ( v62[1] )
        {
          v22 = sub_CDF5C(529);
          v46 = v15++;
          sub_C5AC8(v58, v46, v22, v56);
        }
        if ( v64 )
        {
          v23 = sub_CDF5C(527);
          v47 = v15++;
          sub_C5AC8(v58, v47, v23, v56);
        }
        if ( v67 )
        {
          v24 = sub_CDF5C(526);
          v48 = v15++;
          sub_C5AC8(v58, v48, v24, v56);
        }
        if ( v15 <= 0 )
        {
          sub_C0AF4();
          byte_182ACA = 1;
          v27 = sub_CDF5C(228);
          sub_C5B5F(v27);
        }
        else
        {
          if ( (int16_t)v71 > 0 )
          {
            v55 = v71;
            v25 = sub_CDF5C(128);
            sub_C5AC8(v58, v15, v25, v55);
          }
          sub_C0AF4();
          byte_182ACA = 1;
          v26 = sub_CDF5C(470);
          sub_A5EB2(v26, (int)v58);
        }
        sub_C0ABC();
      }
      goto LABEL_72;
    }
    v69 = v56;
    if ( v56 == -1 || (v68 = 361 * word_182974, *(_DWORD *)(dword_192B18 + v68 + 4 * v5 + 12) << 23 >> 30 == v56) )
    {
      *(_BYTE *)(361 * word_182974 + dword_192B18 + 4 * v5 + 13) |= 2u;
    }
    else
    {
      LOBYTE(v3) = sub_BA5DA(word_182974, v5, v69);
      if ( !(_BYTE)v3 )
        return v3;
    }
LABEL_72:
    if ( v5 != -1 )
      v5 = sub_B9AD7(word_182974);
  }
  sub_BB1A6(word_182974, v1);
  if ( word_182974 != v57 )
    sub_BB1A6(v57, v1);
  if ( (int16_t)v71 > 0 )
  {
    strcpy(v60, (char *)sub_77B28(*(_WORD *)(dword_192B18 + 361 * word_182974 + 2)));
    strcpy(v61, (char *)sub_77B28(*(_WORD *)(361 * v57 + dword_192B18 + 2)));
    v1 = (int)v61;
    v35 = v71;
    v28 = sub_CDF5C(465);
    v29 = 1;
    sub_C5AC8(v58, 0, v28, v35);
    if ( v65 )
    {
      v30 = sub_CDF5C(132);
      v29 = 2;
      sub_C5AC8(v58, 1, v30, v56);
    }
    if ( v64 )
    {
      v31 = sub_CDF5C(133);
      v49 = v29++;
      sub_C5AC8(v58, v49, v31, v56);
    }
    if ( v72 )
    {
      v32 = sub_CDF5C(131);
      sub_C5AC8(v58, v29, v32, v56);
    }
    sub_C0AF4();
    v33 = sub_CDF5C(469);
    sub_A5EB2(v33, (int)v58);
    sub_C0ABC();
    sub_E2A70(word_182974, (int)v61);
    sub_E2A70(v57, (int)v61);
  }
  v3 = sub_B9AD7(word_182974);
  if ( v3 == -1 )
  {
    sub_C0AF4();
    LOBYTE(v3) = sub_BB2CB(v1);
    word_182974 = -1;
  }
  return v3;
}
// B9F05: variable 'v57' is possibly undefined
// BA0B6: variable 'v13' is possibly undefined
// BA0FA: variable 'v56' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182974: using guessed type int16_t word_182974;
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;


//----- (000BA5DA) --------------------------------------------------------
char __fastcall sub_BA5DA( int a1, int a2, int a3)
{
  int16_t v4; // ax
  int16_t v5; // ax
  int v6; // eax
  int16_t v7; // ax
  int v8; // eax
  char v10; // [esp+10h] [ebp-4h]

  v10 = 0;
  v4 = sub_BCACF(a1, a2);
  if ( (v4 == 3 || v4 == 6) && (a3 == 2 || a3 == 1) )
  {
    v5 = 522;
  }
  else if ( v4 != 4 || a3 == *(_DWORD *)(361 * a1 + dword_192B18 + 4 * a2 + 12) << 23 >> 30 )
  {
    if ( sub_BC972(a1, a3, -1, -1, 0, -1) < 42 )
    {
      v7 = *(uint8_t *)(dword_192B18 + 361 * a1 + 224);
      if ( sub_BC972(a1, a3, -1, -1, 0, -1) < v7 || a3 )
      {
        v8 = 361 * a1 + dword_192B18 + 4 * a2;
        *(_WORD *)(v8 + 12) &= 0xFE7Fu;
        *(_DWORD *)(v8 + 12) |= (a3 & 3) << 7;
        v10 = 1;
        *(_BYTE *)(v8 + 13) |= 2u;
        return v10;
      }
    }
    v5 = 391;
  }
  else
  {
    v5 = 524;
  }
  v6 = sub_CDF5C(v5);
  sub_C5B5F(v6);
  return v10;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BA8BF) --------------------------------------------------------
int __fastcall sub_BA8BF( int a1)
{
  int v2; // edx
  int16_t i; // ax
  int v4; // ebx

  v2 = 0;
  for ( i = 0; i < 5; ++i )
  {
    v4 = *(int16_t *)(113 * a1 + dword_19306C + 2 * i + 74);
    if ( v4 > -1 && *(int16_t *)(dword_1930D4 + 17 * v4) > -1 )
      ++v2;
  }
  return v2;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000BA90B) --------------------------------------------------------
int __fastcall sub_BA90B( int a1, int a2, int a3, int a4)
{
  int16_t *v5; // esi

  v5 = (int16_t *)sub_BB4A9(a3, a4);
  sub_12D8F5(30, 30, dword_19F7B0);
  sub_12F7E6(0, 0, v5, (int16_t *)dword_19F7B0);
  sub_12E8D4((int16_t *)dword_19F7B0, (int16_t *)dword_19F7B0, 2);
  return sub_12A478(a1, a2, dword_19F7B0);
}
// 19F7B0: using guessed type int dword_19F7B0;


//----- (000BA96D) --------------------------------------------------------
int __fastcall sub_BA96D( int a1)
{
  int16_t v2; // dx
  int result; // eax

  v2 = 1;
  result = 0;
  do
  {
    if ( *(_BYTE *)(v2 + 361 * a1 + dword_192B18 + 310) )
      ++result;
    ++v2;
  }
  while ( v2 < 49 );
  return result;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BA9A5) --------------------------------------------------------
int __fastcall sub_BA9A5( int a1)
{
  int16_t i; // bx
  int result; // eax

  for ( i = 0; i < 7; ++i )
  {
    result = a1;
    if ( *(int16_t *)(361 * a1 + dword_192B18 + 2 * i + 277) == -1 )
      result = sub_BA9EC(a1, i);
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BA9EC) --------------------------------------------------------
int __fastcall sub_BA9EC( int a1, int a2)
{
  int v3; // eax
  int result; // eax

  while ( a2 < 6 )
  {
    v3 = 2 * a2++;
    *(_WORD *)(361 * a1 + dword_192B18 + v3 + 277) = *(_WORD *)(361 * a1 + dword_192B18 + v3 + 279);
  }
  result = 361 * a1;
  *(_WORD *)(dword_192B18 + result + 289) = -1;
  return result;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BAA3B) --------------------------------------------------------
void __fastcall sub_BAA3B( int a1)
{
  sub_BA9A5(a1);
  while ( *(int16_t *)(361 * a1 + dword_192B18 + 277) == -10 )
    sub_BA9EC(a1, 0);
  JUMPOUT(0xBA9E8);
}
// BAA60: control flows out of bounds to BA9E8
// 192B18: using guessed type int dword_192B18;


//----- (000BAA6B) --------------------------------------------------------
int __fastcall sub_BAA6B( int a1)
{
  int result; // eax

  sub_BA9A5(a1);
  while ( *(int16_t *)(dword_192B18 + 361 * a1 + 277) == -10 )
    sub_BA9EC(a1, 0);
  result = dword_192B18 + 361 * a1;
  if ( *(int16_t *)(result + 277) == -1 )
    *(_WORD *)(result + 277) = -2;
  return result;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BAAC5) --------------------------------------------------------
int __fastcall sub_BAAC5( int a1, int a2, int a3)
{
  int v3; // eax
  int16_t v4; // cx
  int16_t v5; // ax
  int16_t v6; // di
  int v7; // eax
  int16_t v8; // si
  char v9; // bl
  _BYTE v12[32]; // [esp+8h] [ebp-24h] BYREF
  int v13; // [esp+28h] [ebp-4h]

  v3 = 129 * a3;
  qmemcpy(v12, &byte_BA6FB, 0x1Fu);
  v4 = *(char *)(dword_197F9C + v3 + 92);
  v5 = *(char *)(dword_197F9C + v3 + 93);
  if ( v4 != word_182C1D || v5 != dword_182C96 )
  {
    v13 = 208;
    v6 = 192;
    word_182C1D = v4;
    dword_182C96 = v5;
    v7 = sub_58697(v5, v4);
    sub_12F578(dword_19F7C0, v7);
    v8 = 0;
    sub_137D86(dword_19F7C0, (int)v12, 1, 31);
    do
    {
      sub_13719F(dword_19F7C0, v6++, v12[2 * v8]);
      v9 = v12[2 * v8++];
      sub_13719F(dword_19F7C0, v13++, v9);
    }
    while ( v8 < 16 );
  }
  return sub_C5CFF(a1, a2, (int16_t *)dword_19F7C0);
}
// BA6FB: using guessed type char byte_BA6FB;
// 182C1D: using guessed type int16_t word_182C1D;
// 182C96: using guessed type int dword_182C96;
// 197F9C: using guessed type int dword_197F9C;
// 19F7C0: using guessed type int dword_19F7C0;


//----- (000BABA4) --------------------------------------------------------
void __fastcall sub_BABA4(int a1, int a2, int a3)
{
  int v3; // eax
  int16_t v4; // di
  int16_t v5; // si
  char v6; // bl
  _BYTE v7[32]; // [esp+0h] [ebp-24h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  qmemcpy(v7, &word_BA71A, 0x1Fu);
  if ( a3 != word_182C1D )
  {
    v8 = 208;
    word_182C1D = a3;
    dword_182C96 = word_19999C;
    v3 = sub_58697(word_19999C, a3);
    v4 = 192;
    sub_12F578(dword_19F7C0, v3);
    v5 = 0;
    sub_137D86(dword_19F7C0, (int)v7, 1, 31);
    do
    {
      sub_13719F(dword_19F7C0, v4++, v7[2 * v5]);
      v6 = v7[2 * v5++];
      sub_13719F(dword_19F7C0, v8++, v6);
    }
    while ( v5 < 16 );
  }
  JUMPOUT(0xBAB8C);
}
// BAC47: control flows out of bounds to BAB8C
// BA71A: using guessed type int16_t word_BA71A;
// BA71C: using guessed type int dword_BA71C[24];
// 182C1D: using guessed type int16_t word_182C1D;
// 182C96: using guessed type int dword_182C96;
// 19999C: using guessed type int16_t word_19999C;
// 19F7C0: using guessed type int dword_19F7C0;


//----- (000BAC4C) --------------------------------------------------------
void __fastcall sub_BAC4C( int a1, int a2, int a3)
{
  sub_BABA4(a1, a2, *(char *)(3753 * word_19999C + dword_197F98 + 99 * a3 + 898));
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (000BAC81) --------------------------------------------------------
int __fastcall sub_BAC81( unsigned int a1)
{
  int v2; // ebx
  int v3; // edx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int16_t i; // cx
  char v8; // al
  int16_t v9; // dx
  _BYTE v10[32]; // [esp+0h] [ebp-24h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  qmemcpy(v10, (char *)&dword_BA71C[7] + 1, 0x1Fu);
  if ( a1 >= 0xEu )
  {
    if ( a1 > 0xEu )
    {
      if ( a1 >= 0x28u )
      {
        if ( a1 <= 0x28u )
        {
          v11 = 40;
        }
        else if ( a1 == 41 )
        {
          v11 = 42;
        }
      }
      goto LABEL_15;
    }
    return sub_BBA8E(29);
  }
  if ( a1 >= 3u )
  {
    if ( a1 > 3u )
    {
      if ( a1 == 8 )
        v11 = 41;
      goto LABEL_15;
    }
    return sub_BBA8E(29);
  }
LABEL_15:
  if ( word_182C9A != (_WORD)v11 )
  {
    word_182C9A = v11;
    v2 = dword_193174;
    v3 = 50 * *(uint8_t *)(3753 * word_19999C + dword_197F98 + 38) + 49;
    v4 = sub_CDF5C(477);
    v5 = sub_127C27(v4, v3, v2);
    sub_133C9C(v5, v3);
    v6 = sub_58697(word_19999C, v11);
    sub_12F578(dword_19F7CC, v6);
    sub_137D86(dword_19F7CC, (int)v10, 1, 31);
    for ( i = 192; i < 256; ++i )
    {
      v8 = sub_133DE1(i);
      v9 = i;
      sub_13719F(dword_19F7CC, v9, v8);
    }
  }
  return dword_19F7CC;
}
// BA71C: using guessed type int dword_BA71C[24];
// 182C9A: using guessed type int16_t word_182C9A;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19F7CC: using guessed type int dword_19F7CC;


//----- (000BADA0) --------------------------------------------------------
int __fastcall sub_BADA0(int a1)
{
  sub_120DED(80, 80);
  sub_BB04E(3u);
  return sub_1210FD(61, 135, a1);
}


//----- (000BADCC) --------------------------------------------------------
int16_t __fastcall sub_BADCC( int a1, int a2)
{
  char *v4; // eax
  unsigned int v5; // edx

  v4 = (char *)(dword_192B18 + 361 * a1);
  v5 = *(_DWORD *)&v4[4 * a2 + 12] & 0xF;
  if ( v5 < 8 || v5 > 9 )
    return *(_DWORD *)(361 * a1 + dword_192B18 + 4 * a2 + 12) & 0xF;
  else
    LOWORD(v4) = *v4;
  return (int16_t)v4;
}
// 192B18: using guessed type int dword_192B18;


//----- (000BAE1A) --------------------------------------------------------
int __fastcall sub_BAE1A( int a1, int a2)
{
  unsigned int v3; // eax
  int16_t v4; // ax

  v3 = *(_DWORD *)(361 * a1 + dword_192B18 + 4 * a2 + 12) & 0xF;
  if ( v3 < 8 )
    return dword_197F98 + 3753 * (*(_DWORD *)(361 * a1 + dword_192B18 + 4 * a2 + 12) & 0xF) + 21;
  if ( v3 <= 8 )
  {
    v4 = 179;
    return sub_CDF5C(v4);
  }
  if ( v3 == 9 )
  {
    v4 = 597;
    return sub_CDF5C(v4);
  }
  return dword_197F98 + 3753 * (*(_DWORD *)(361 * a1 + dword_192B18 + 4 * a2 + 12) & 0xF) + 21;
}
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000BAE88) --------------------------------------------------------
int sub_BAE88()
{
  int v0; // eax
  int v1; // edx
  int v2; // eax
  int v3; // edx
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edx
  int result; // eax
  int v9; // edx

  sub_BF500();
  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    word_19F9C0[v1] = -1000;
  }
  while ( (int16_t)v0 < 5 );
  v2 = 0;
  do
  {
    v3 = (int16_t)v2++;
    word_182ACF[v3] = -1000;
  }
  while ( (int16_t)v2 < 21 );
  v4 = 0;
  do
  {
    v5 = (int16_t)v4++;
    word_182AF9[v5] = -1000;
  }
  while ( (int16_t)v4 < 2 );
  v6 = 0;
  do
  {
    v7 = (int16_t)v6++;
    word_19F7D4[v7] = -1000;
  }
  while ( (int16_t)v6 < 42 );
  result = 0;
  do
  {
    v9 = (int16_t)result++;
    word_19F9E0[v9] = -1000;
  }
  while ( (int16_t)result < 3 );
  return result;
}
// 182ACF: using guessed type int16_t word_182ACF[];
// 182AF9: using guessed type int16_t word_182AF9[2];
// 19F7D4: using guessed type int16_t word_19F7D4[42];
// 19F9C0: using guessed type int16_t word_19F9C0[5];
// 19F9E0: using guessed type int16_t word_19F9E0[];


//----- (000BAEFE) --------------------------------------------------------
int sub_BAEFE()
{
  sub_120DED(80, 80);
  sub_120DED(80, 80);
  sub_120CCB(3, (int)&unk_182C2E);
  sub_120EB9((int)&unk_182C26);
  return sub_120F07((int)&unk_182C46);
}


//----- (000BAF3C) --------------------------------------------------------
void __fastcall sub_BAF3C( unsigned int a1, unsigned int a2)
{
  sub_120DED(80, 80);
  sub_120CCB(a1, (int)&unk_182C56 + 8 * *(uint8_t *)(dword_197F98 + 3753 * a2 + 38));
  sub_120EB9((int)&unk_182C26);
  JUMPOUT(0xBAFC2);
}
// BAF82: control flows out of bounds to BAFC2
// 197F98: using guessed type int dword_197F98;


//----- (000BAF84) --------------------------------------------------------
int __fastcall sub_BAF84( unsigned int a1, unsigned int a2)
{
  void *v4; // edx

  sub_120DED(80, 80);
  if ( a2 )
    v4 = &unk_182C3E;
  else
    v4 = &unk_182C2E;
  sub_120CCB(a1, (int)v4);
  sub_120EB9((int)&unk_182C26);
  return sub_120F07((int)&unk_182C46 + 8 * a2);
}


//----- (000BAFC9) --------------------------------------------------------
void __fastcall sub_BAFC9( unsigned int a1, int a2)
{
  void *v3; // edx

  sub_120DED(80, 80);
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v3 = &unk_182C2E;
    }
    else
    {
      if ( a2 != 2 )
      {
LABEL_8:
        sub_120EB9((int)&unk_182C26);
        JUMPOUT(0xBAFBA);
      }
      v3 = &unk_182C3E;
    }
  }
  else
  {
    v3 = &unk_182C36;
  }
  sub_120CCB(a1, (int)v3);
  goto LABEL_8;
}
// BB010: control flows out of bounds to BAFBA


//----- (000BB012) --------------------------------------------------------
int __fastcall sub_BB012( unsigned int a1, unsigned int a2)
{
  char *v3; // edx

  sub_120DED(80, 80);
  v3 = (char *)&unk_182C46 + 8 * a2;
  sub_120CCB(a1, (int)v3);
  sub_120EB9((int)&unk_182C26);
  return sub_120F07((int)v3);
}


//----- (000BB04E) --------------------------------------------------------
int __fastcall sub_BB04E( unsigned int a1)
{
  sub_120DED(80, 80);
  sub_120CCB(a1, (int)&unk_182C2E);
  sub_120EB9((int)&unk_182C26);
  return sub_120F07((int)&unk_182C46);
}


//----- (000BB082) --------------------------------------------------------
int __fastcall sub_BB082( int a1, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int result; // eax

  v2 = a1;
  v3 = *(int16_t *)(dword_1930D4 + 17 * a1);
  if ( v3 == -1 )
  {
    v4 = word_199996++;
    result = sub_12D75(v4, v2, word_19999C);
    LOBYTE(result) = 1;
  }
  else
  {
    LOBYTE(v3) = 0;
    return nullsub_6(v3, a2);
  }
  return result;
}
// BB0C3: using guessed type int __fastcall nullsub_6(_DWORD, _DWORD);
// 1930D4: using guessed type int dword_1930D4;
// 199996: using guessed type int16_t word_199996;
// 19999C: using guessed type int16_t word_19999C;


//----- (000BB0C4) --------------------------------------------------------
int sub_BB0C4()
{
  word_19994C = 0;
  sub_119281();
  byte_182ACA = 1;
  sub_1191CA((int)sub_BED21, 1);
  return sub_CDB01();
}
// 182ACA: using guessed type char byte_182ACA;
// 19994C: using guessed type int16_t word_19994C;


//----- (000BB0F0) --------------------------------------------------------
int __fastcall sub_BB0F0( unsigned int a1)
{
  if ( !a1 )
    return sub_CDF5C(291);
  if ( a1 <= 1u )
    return sub_CDF5C(557);
  return sub_CDF5C(455);
}


//----- (000BB121) --------------------------------------------------------
int __fastcall sub_BB121( int a1)
{
  if ( a1 )
    return sub_CDF5C(598);
  else
    return sub_CDF5C(12);
}


//----- (000BB147) --------------------------------------------------------
int __fastcall sub_BB147( int a1)
{
  if ( a1 )
    JUMPOUT(0xBB12F);
  return sub_CDF5C(286);
}
// BB159: control flows out of bounds to BB12F


//----- (000BB16A) --------------------------------------------------------
int __fastcall sub_BB16A( int a1)
{
  int v1; // eax
  int v2; // edx
  int result; // eax

  dword_19F7A8 = a1;
  dword_19F7BC = *(int16_t *)(361 * a1 + dword_192B18 + 2);
  v1 = dword_1930D4 + 17 * dword_19F7BC;
  v2 = *(uint8_t *)(v1 + 2);
  result = *(uint8_t *)(v1 + 3);
  dword_19F7B8 = v2;
  dword_19F7C8 = result;
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 19F7A8: using guessed type int dword_19F7A8;
// 19F7B8: using guessed type int dword_19F7B8;
// 19F7BC: using guessed type int dword_19F7BC;
// 19F7C8: using guessed type int dword_19F7C8;


//----- (000BB1A6) --------------------------------------------------------
int __usercall sub_BB1A6( int a1, int a2)
{
  int result; // eax
  int v4; // edx

  sub_E2A70(a1, a2);
  result = word_182AC6;
  if ( word_182AC6 != -1 && byte_182ABB == 1 )
  {
    for ( result = 0; ; ++result )
    {
      v4 = dword_192B18 + 361 * a1;
      if ( (int16_t)result >= *(uint8_t *)(v4 + 10) )
        break;
      if ( (*(_BYTE *)(v4 + 4 * (int16_t)result + 13) & 2) == 0 )
        word_182AC6 = result;
    }
  }
  return result;
}
// 182ABB: using guessed type char byte_182ABB;
// 182AC6: using guessed type int16_t word_182AC6;
// 192B18: using guessed type int dword_192B18;


//----- (000BB1FA) --------------------------------------------------------
void sub_BB1FA()
{
  word_182AC6 = -1;
  sub_123E6C((int)&unk_17CF00, 1);
  sub_1172FC();
  sub_1172FC();
}
// 182AC6: using guessed type int16_t word_182AC6;


//----- (000BB2CB) --------------------------------------------------------
int __usercall sub_BB2CB(int a1)
{
  int result; // eax
  int v2; // eax
  int v3; // eax

  result = (int16_t)sub_B9AD7(dword_19F7A8);
  if ( (int16_t)result != -1 )
  {
    if ( byte_182ABB == 1 )
    {
      sub_B9A8C();
    }
    else if ( byte_182ABB == 2 )
    {
      v2 = sub_CDF5C(394);
      sub_C5B5F(v2);
      sub_BB0C4();
      ++*(_WORD *)(dword_192B18 + 361 * dword_19F7A8 + 2 * word_182AC6 + 304);
      sub_BB1FA();
      v3 = sub_BB1A6(dword_19F7A8, a1);
      sub_BB2CB(v3);
    }
    result = sub_BB1A6(dword_19F7A8, a1);
  }
  byte_182ABB = 0;
  return result;
}
// 182ABB: using guessed type char byte_182ABB;
// 182AC6: using guessed type int16_t word_182AC6;
// 192B18: using guessed type int dword_192B18;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BB382) --------------------------------------------------------
void sub_BB382()
{
  JUMPOUT(0xBBBB2);
}
// BB39A: control flows out of bounds to BBBB2


//----- (000BB39F) --------------------------------------------------------
int16_t __fastcall sub_BB39F( int a1)
{
  unsigned int v1; // eax
  int16_t v3; // [esp+0h] [ebp-8h] BYREF
  int16_t v4; // [esp+4h] [ebp-4h] BYREF

  LOWORD(v1) = sub_BBD37(a1, &v3, &v4);
  if ( (_BYTE)v1 )
  {
    v1 = 24 * v3;
    byte_182ACA = 1;
    dword_182AFD[v4 + v1 / 4] = 8;
  }
  return v1;
}
// 182ACA: using guessed type char byte_182ACA;
// 182AFD: using guessed type int dword_182AFD[];


//----- (000BB3DB) --------------------------------------------------------
int __fastcall sub_BB3DB( int a1)
{
  if ( a1 == 3 || a1 == 14 || a1 == 40 || a1 == 41 )
    return sub_CDF5C(322);
  if ( a1 == 8 )
    return sub_CDF5C(452);
  return sub_BB40D(a1);
}


//----- (000BB40D) --------------------------------------------------------
int __fastcall sub_BB40D( int a1)
{
  return *(int *)((char *)&off_17EB3D + 19 * a1);
}
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;


//----- (000BB418) --------------------------------------------------------
char __fastcall sub_BB418( int a1)
{
  int16_t *v1; // edi
  int i; // ecx
  int v3; // esi
  int v4; // ebx
  int v5; // eax
  char result; // al

  v1 = (int16_t *)a1;
  for ( i = 0; i < 6; ++i )
  {
    v3 = 0;
    do
    {
      sub_BB469(i, v3, (int16_t)v1);
      v4 = *(int *)((char *)&off_17EB3D + 19 * (_DWORD)v1);
      ++v3;
      v5 = sub_1210FD(320, 240, v4);
      sub_1077D(v5, 240, v4, v1);
      result = sub_6497C();
    }
    while ( v3 < 6 );
  }
  return result;
}
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;


//----- (000BB469) --------------------------------------------------------
int64_t __fastcall sub_BB469( int a1, int a2, int a3)
{
  int v3; // ebx

  v3 = sub_AF6DC(a1, a2, a3);
  if ( byte_182ACA )
    return (unsigned int)sub_12A478(0, 0, v3);
  else
    return (unsigned int)sub_129FF9(0, 0, v3);
}
// 182ACA: using guessed type char byte_182ACA;


//----- (000BB4A9) --------------------------------------------------------
int __fastcall sub_BB4A9( int a1, int a2)
{
  int v3; // esi
  int v4; // edi
  int16_t v5; // dx
  int v7; // [esp+0h] [ebp-8h]
  uint16_t v8; // [esp+4h] [ebp-4h]

  v3 = 361 * a1;
  v4 = a2;
  v7 = *(_DWORD *)(v3 + dword_192B18 + 4 * a2 + 12) << 23 >> 30;
  v8 = sub_BCACF(a1, a2);
  v5 = *(uint8_t *)(dword_197F98 + 3753 * sub_BADCC(a1, a2) + 37);
  if ( (*(_BYTE *)(v3 + dword_192B18 + 4 * v4 + 13) & 4) != 0 )
    return sub_127C27((int)aRaceiconLbx, (int16_t)(13 * v5 + 12), dword_193174);
  else
    return sub_BB54D(v7, v8, v5);
}
// 192B18: using guessed type int dword_192B18;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;


//----- (000BB53E) --------------------------------------------------------
void sub_BB53E()
{
  JUMPOUT(0xBB38C);
}
// BB548: control flows out of bounds to BB38C


//----- (000BB54D) --------------------------------------------------------
int __fastcall sub_BB54D( int a1, unsigned int a2, int a3)
{
  int v3; // edx
  int v4; // eax
  int v6; // edx

  if ( a2 == 2 )
  {
    v3 = dword_193174;
    v4 = 13 * a3 + 2 * a1 + 1;
    return sub_127C27((int)aRaceiconLbx, v4, v3);
  }
  if ( !a2 )
  {
    v3 = dword_193174;
    v4 = 13 * a3 + 2 * a1;
    return sub_127C27((int)aRaceiconLbx, v4, v3);
  }
  if ( a2 < 3u )
    return 0;
  if ( a2 <= 3u )
  {
    v6 = 170;
  }
  else
  {
    if ( a2 != 4 )
      return 0;
    v6 = 169;
  }
  return sub_127C27((int)aRaceiconLbx, v6, dword_193174);
}
// 193174: using guessed type int dword_193174;


//----- (000BB5BB) --------------------------------------------------------
int __fastcall sub_BB5BB( int a1, int a2)
{
  return sub_127C27((int)aRaceiconLbx, (int16_t)(13 * a2 + a1 + 6), dword_193174);
}
// 193174: using guessed type int dword_193174;


//----- (000BB5DB) --------------------------------------------------------
int __fastcall sub_BB5DB( int a1, int a2)
{
  int v3; // ecx
  int16_t v4; // ax
  int16_t v5; // ax

  v3 = a1;
  v4 = 13 * a2;
  if ( v3 == -1 )
  {
    v5 = v4 + 6;
  }
  else if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( *(_BYTE *)(3753 * word_19999C + dword_197F98 + 303) == 3 )
        v5 = v4 + 10;
      else
        v5 = v4 + 9;
    }
    else
    {
      v5 = a1 + 6 + v4;
    }
  }
  else if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 423) == 3 )
  {
    v5 = v4 + 8;
  }
  else
  {
    v5 = v4 + 7;
  }
  return sub_127C27((int)aRaceiconLbx, v5, dword_193174);
}
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (000BB670) --------------------------------------------------------
int __fastcall sub_BB670( int a1, int a2)
{
  return sub_BB723(word_19999C, a1, a2);
}
// 19999C: using guessed type int16_t word_19999C;


//----- (000BB695) --------------------------------------------------------
int __fastcall sub_BB695( int a1, int a2)
{
  int result; // eax

  switch ( a2 )
  {
    case 0:
      if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 303) == 3 )
        result = sub_CDF5C(195);
      else
        result = sub_CDF5C(504);
      break;
    case 1:
      if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 423) == 3 )
        result = sub_CDF5C(428);
      else
        result = sub_CDF5C(333);
      break;
    case 2:
      result = sub_CDF5C(372);
      break;
    case 3:
      result = sub_CDF5C(444);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (000BB723) --------------------------------------------------------
int __fastcall sub_BB723( int a1, int a2, int a3)
{
  int16_t v4; // ax
  int16_t v5; // si
  int16_t v6; // ax
  int v7; // ebx
  int v8; // edx
  int result; // eax

  v4 = 13 * a3;
  v5 = 13 * a3 + 7;
  switch ( a2 )
  {
    case 0:
      if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 303) == 3 )
        v6 = v4 + 10;
      else
        v6 = v4 + 9;
      goto LABEL_4;
    case 1:
      if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 423) != 3 )
        goto LABEL_9;
      v6 = v4 + 8;
LABEL_4:
      v7 = dword_193174;
      v8 = v6;
      goto LABEL_5;
    case 2:
      v6 = v4 + 6;
      goto LABEL_4;
    case 3:
LABEL_9:
      v7 = dword_193174;
      v8 = v5;
LABEL_5:
      result = sub_127C27((int)aRaceiconLbx, v8, v7);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;


//----- (000BB7BB) --------------------------------------------------------
_DWORD *sub_BB7BB()
{
  _DWORD *result; // eax

  result = sub_110D3C(dword_192ED4, 14432);
  word_182C1F = -1;
  dword_19DD8C = (int)result;
  return result;
}
// 182C1F: using guessed type int16_t word_182C1F;
// 192ED4: using guessed type int dword_192ED4;
// 19DD8C: using guessed type int dword_19DD8C;


//----- (000BB7DB) --------------------------------------------------------
_DWORD *sub_BB7DB()
{
  _DWORD *result; // eax

  dword_19F7C0 = (int)sub_110D3C(dword_192ED4, 3632);
  result = sub_110D3C(dword_192ED4, 3632);
  word_182C1D = -1;
  word_182C9A = -1;
  dword_182C96 = -1;
  dword_19F7CC = (int)result;
  return result;
}
// 182C1D: using guessed type int16_t word_182C1D;
// 182C96: using guessed type int dword_182C96;
// 182C9A: using guessed type int16_t word_182C9A;
// 192ED4: using guessed type int dword_192ED4;
// 19F7C0: using guessed type int dword_19F7C0;
// 19F7CC: using guessed type int dword_19F7CC;


//----- (000BB822) --------------------------------------------------------
_DWORD *sub_BB822()
{
  _DWORD *result; // eax

  dword_182BD9 = (int)sub_126B42((int)aColpupsLbx, 1, dword_192ED4);
  dword_182BDD = (int)sub_126B42((int)aColpupsLbx, 2, dword_192ED4);
  dword_182BE1 = (int)sub_126B42((int)aColpupsLbx, 4, dword_192ED4);
  dword_182BE5 = (int)sub_126B42((int)aColpupsLbx, 7, dword_192ED4);
  dword_182BE9 = (int)sub_126B42((int)aColpupsLbx, 8, dword_192ED4);
  dword_182BED = (int)sub_126B42((int)aColpupsLbx, 9, dword_192ED4);
  result = sub_126B42((int)aColpupsLbx, 21, dword_192ED4);
  dword_182C0D = (int)result;
  return result;
}
// 182BD9: using guessed type int dword_182BD9;
// 182BDD: using guessed type int dword_182BDD;
// 182BE1: using guessed type int dword_182BE1;
// 182BE5: using guessed type int dword_182BE5;
// 182BE9: using guessed type int dword_182BE9;
// 182BED: using guessed type int dword_182BED;
// 182C0D: using guessed type int dword_182C0D;
// 192ED4: using guessed type int dword_192ED4;


//----- (000BB8DD) --------------------------------------------------------
int sub_BB8DD()
{
  int result; // eax
  int v1; // edx

  result = word_19999C;
  v1 = *(char *)(113 * dword_19F7B8 + dword_19306C + word_19999C + 66);
  if ( v1 != -1 )
  {
    result = (int)sub_925AE(word_19999C, v1, dword_192ED4, 0, 1u);
    dword_182C05 = result;
  }
  return result;
}
// 182C05: using guessed type int dword_182C05;
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 19999C: using guessed type int16_t word_19999C;
// 19F7B8: using guessed type int dword_19F7B8;


//----- (000BB91D) --------------------------------------------------------
int sub_BB91D()
{
  int16_t v0; // si
  int v1; // ecx
  _DWORD *v2; // eax
  int v3; // edx
  int result; // eax

  v0 = 23;
  v1 = 0;
  do
  {
    v2 = sub_126B42((int)aGstarLbx_0, v0++, dword_192ED4);
    v3 = (int)v2;
    result = (int16_t)v1++;
    dword_190688[result] = v3;
  }
  while ( (int16_t)v1 < 10 );
  return result;
}
// 190688: using guessed type int dword_190688[10];
// 192ED4: using guessed type int dword_192ED4;


//----- (000BB954) --------------------------------------------------------
int __fastcall sub_BB954(int a1, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // eax
  _DWORD *v9; // eax

  v2 = sub_B0A24();
  sub_FE8BE(v2);
  v3 = sub_C52F6();
  sub_FE8BE(v3);
  dword_19F7C0 = (int)sub_110D3C(dword_192ED4, 3632);
  v4 = sub_110D3C(dword_192ED4, 3632);
  word_182C1D = -1;
  word_182C9A = -1;
  dword_182C96 = -1;
  dword_19F7CC = (int)v4;
  sub_FE8BE(v4);
  v5 = sub_110D3C(dword_192ED4, 14432);
  word_182C1F = -1;
  dword_19DD8C = (int)v5;
  sub_FE8BE(v5);
  v6 = sub_BB8DD();
  sub_FE8BE(v6);
  sub_B5FBE();
  v7 = sub_AF74F();
  sub_FE8BE(v7);
  v8 = sub_BB91D();
  sub_FE8BE(v8);
  v9 = sub_BB822();
  return nullsub_7(v9, a2);
}
// BB9FD: using guessed type int __fastcall nullsub_7(_DWORD, _DWORD);
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 182C1D: using guessed type int16_t word_182C1D;
// 182C1F: using guessed type int16_t word_182C1F;
// 182C96: using guessed type int dword_182C96;
// 182C9A: using guessed type int16_t word_182C9A;
// 192ED4: using guessed type int dword_192ED4;
// 19DD8C: using guessed type int dword_19DD8C;
// 19F7C0: using guessed type int dword_19F7C0;
// 19F7CC: using guessed type int dword_19F7CC;


//----- (000BBA8E) --------------------------------------------------------
int __fastcall sub_BBA8E(int a1)
{
  int16_t v1; // dx
  int v2; // edx
  char *v3; // eax
  int v4; // ebx
  int result; // eax

  v1 = a1;
  sub_FE8BE(a1);
  switch ( v1 )
  {
    case 0:
      v4 = dword_193174;
      v2 = (int16_t)(*(uint8_t *)(17 * *(int16_t *)(dword_192B18 + 361 * dword_19F7A8 + 2) + dword_1930D4 + 9)
                   + 3 * *(uint8_t *)(dword_192B18 + 361 * dword_19F7A8 + 226));
      v3 = aPlanetsLbx;
      goto LABEL_21;
    case 1:
      v2 = 49;
      goto LABEL_3;
    case 2:
    case 11:
    case 12:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 30:
    case 31:
    case 32:
      return dword_182B8D[v1];
    case 3:
      v2 = 5;
      goto LABEL_6;
    case 4:
      v2 = 6;
      goto LABEL_6;
    case 5:
      v2 = 16;
      goto LABEL_3;
    case 6:
      v2 = 17;
      goto LABEL_3;
    case 7:
      v2 = 18;
      goto LABEL_3;
    case 8:
      v2 = 43;
      goto LABEL_3;
    case 9:
      v2 = 44;
      goto LABEL_3;
    case 10:
      v2 = 45;
      goto LABEL_3;
    case 13:
      v2 = 50;
      goto LABEL_3;
    case 14:
      v2 = 51;
      goto LABEL_3;
    case 15:
      v2 = 52;
LABEL_3:
      v3 = aColony2Lbx;
      goto LABEL_20;
    case 33:
      v2 = 22;
LABEL_6:
      v3 = aColpupsLbx;
      goto LABEL_20;
    case 34:
      v2 = 17;
      goto LABEL_19;
    case 35:
      v2 = 18;
LABEL_19:
      v3 = aColonyLbx;
LABEL_20:
      v4 = dword_193174;
LABEL_21:
      result = sub_127C27((int)v3, v2, v4);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 182B8D: using guessed type int dword_182B8D[19];
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000BBB8A) --------------------------------------------------------
void sub_BBB8A()
{
  JUMPOUT(0xBBBB2);
}
// BBB9D: control flows out of bounds to BBBB2


//----- (000BBB9F) --------------------------------------------------------
int __fastcall sub_BBB9F( int a1)
{
  return sub_127C27((int)aColonyLbx, a1 + 9, dword_193174);
}
// 193174: using guessed type int dword_193174;


//----- (000BBBBA) --------------------------------------------------------
int __fastcall sub_BBBBA( unsigned int a1)
{
  int v1; // edx

  v1 = -1;
  if ( a1 >= 0xEu )
  {
    if ( a1 <= 0xEu )
      return 3;
    if ( a1 >= 0x28u )
    {
      if ( a1 <= 0x28u )
        return 2;
      if ( a1 != 41 )
        return -1;
      return 0;
    }
    return v1;
  }
  if ( a1 < 3u )
    return v1;
  if ( a1 <= 3u )
    return 7;
  if ( a1 == 8 )
    return 1;
  return -1;
}


//----- (000BBC16) --------------------------------------------------------
int sub_BBC16()
{
  dword_19F7B0 = (int)sub_110D3C(dword_192EF4, 932);
  dword_19F7C4 = (int)sub_110D3C(dword_192EF4, 932);
  return nullsub_9(dword_19F7C4);
}
// C49C8: using guessed type int __fastcall nullsub_9(_DWORD);
// 192EF4: using guessed type int dword_192EF4;
// 19F7B0: using guessed type int dword_19F7B0;
// 19F7C4: using guessed type int dword_19F7C4;


//----- (000BBC46) --------------------------------------------------------
int __fastcall sub_BBC46( int a1, int a2, int a3)
{
  int v3; // edx

  if ( a3 )
    v3 = 4 * a2 + 27;
  else
    v3 = 4 * a2;
  return sub_127C27((int)aColony2Lbx, a1 + v3, dword_193174);
}
// 193174: using guessed type int dword_193174;


//----- (000BBC6F) --------------------------------------------------------
void sub_BBC6F()
{
  JUMPOUT(0xBBC5D);
}
// BBC7D: control flows out of bounds to BBC5D


