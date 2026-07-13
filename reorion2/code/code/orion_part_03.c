#include "orion_common.h"

/* Adresni rozsah: 0x38876 - 0x524FB  (200 funkci) */

//----- (00038876) --------------------------------------------------------
void sub_38876()
{
  JUMPOUT(0x38851);
}
// 3888A: control flows out of bounds to 38851
// 192864: using guessed type int dword_192864;


//----- (0003888C) --------------------------------------------------------
void sub_3888C()
{
  JUMPOUT(0x3886F);
}
// 388A0: control flows out of bounds to 3886F
// 192864: using guessed type int dword_192864;


//----- (000388A2) --------------------------------------------------------
void sub_388A2()
{
  JUMPOUT(0x3884E);
}
// 388B6: control flows out of bounds to 3884E
// 192864: using guessed type int dword_192864;


//----- (000388B8) --------------------------------------------------------
void sub_388B8()
{
  JUMPOUT(0x3886C);
}
// 388CC: control flows out of bounds to 3886C
// 192864: using guessed type int dword_192864;


//----- (000388CE) --------------------------------------------------------
void sub_388CE()
{
  JUMPOUT(0x3884E);
}
// 388E2: control flows out of bounds to 3884E
// 192864: using guessed type int dword_192864;


//----- (000388E7) --------------------------------------------------------
void sub_388E7()
{
  JUMPOUT(0x3886C);
}
// 388FB: control flows out of bounds to 3886C
// 192864: using guessed type int dword_192864;


//----- (0003891E) --------------------------------------------------------
void __fastcall sub_3891E( int a1)
{
  int16_t i; // dx
  int v3; // eax

  for ( i = 0; i < 300; ++i )
  {
    v3 = dword_192B14 + 26 * i;
    if ( *(int16_t *)v3 > 0 && !*(_BYTE *)(v3 + 8) )
    {
      if ( a1 == *(_WORD *)(v3 + 4) && a1 == *(_WORD *)(v3 + 6) )
      {
        sub_3BC80(i);
      }
      else if ( a1 == *(_WORD *)(dword_192B14 + 26 * i + 6) )
      {
        sub_3DDD8(i);
      }
    }
  }
}
// 192B14: using guessed type int dword_192B14;


//----- (0003897A) --------------------------------------------------------
int __fastcall sub_3897A( int a1)
{
  int v2; // ebx
  int v3; // eax

  v2 = 0;
  if ( a1 )
  {
    v3 = 313 * a1 + dword_192864;
    if ( *(_WORD *)(v3 + 192) < *(_WORD *)(v3 + 170) )
    {
      if ( !*(_WORD *)(v3 + 256) && *(_BYTE *)(v3 + 32) <= 9u && *(_BYTE *)(v3 + 49) )
        v2 = 3;
    }
    else
    {
      v2 = 1;
    }
    if ( (_WORD)v2 && sub_4B0D3(a1, 24) )
      return 4;
  }
  return v2;
}
// 192864: using guessed type int dword_192864;


//----- (000389E8) --------------------------------------------------------
int __fastcall sub_389E8( int a1, int a2, int a3, int a4)
{
  int v6; // edx
  int v7; // eax

  v6 = 1;
  if ( a4 == 1 )
  {
    v6 = sub_3A7AA(a1, a2);
    if ( byte_17F80F[28 * *(int16_t *)(26 * a3 + dword_192B14)] == 4 && a1 == 33 )
      v6 = 0;
    if ( byte_17F80F[28 * *(int16_t *)(26 * a3 + dword_192B14)] == 2 )
      return 0;
    return v6;
  }
  if ( sub_3E563(a3) )
    goto LABEL_31;
  if ( (word_17F815[14 * a1] & 8) != 0 )
  {
    v7 = 313 * a3 + dword_192864;
    if ( *(_BYTE *)(v7 + 312) >= 8u && *(_BYTE *)(v7 + 312) != 9 )
      goto LABEL_31;
  }
  if ( byte_17F80F[28 * a1] == 3 && a3 || a1 == 33 )
    goto LABEL_31;
  if ( a3 )
  {
    if ( a1 == 28 && *(_BYTE *)(dword_192864 + 313 * a3 + 32) > 8u )
      goto LABEL_31;
  }
  else
  {
    if ( a1 == 28 )
      v6 = 0;
    if ( byte_17F80F[28 * a1] == 5 )
    {
      if ( (uint16_t)a1 >= 0x22u )
      {
        if ( (uint16_t)a1 > 0x25u
          && ((uint16_t)a1 < 0x27u
           || (uint16_t)a1 > 0x27u && ((uint16_t)a1 < 0x2Cu || (uint16_t)a1 > 0x2Du)) )
        {
          goto LABEL_32;
        }
LABEL_31:
        v6 = 0;
        goto LABEL_32;
      }
      if ( (uint16_t)a1 >= 0xDu && ((uint16_t)a1 <= 0xDu || a1 == 32) )
        goto LABEL_31;
    }
  }
LABEL_32:
  if ( *(_BYTE *)(dword_192864 + 313 * a3 + 310) && a1 == 37 )
    return 0;
  return v6;
}
// 17F815: using guessed type int16_t word_17F815[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (00038B5E) --------------------------------------------------------
int __fastcall sub_38B5E(int a1, unsigned int a2, unsigned int a3, int a4, int a5, int a6, int a7)
{
  int16_t v8; // ax
  char v9; // al
  int16_t v10; // ax
  int16_t *v11; // esi
  int v12; // eax
  int v13; // ecx
  char v14; // al
  int v15; // ebx
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // ebx
  int16_t v24; // ax
  int16_t v25; // ax
  int v26; // eax
  int v27; // edx
  int16_t v28; // ax
  int v29; // edx
  _WORD *v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // esi
  int16_t v34; // ax
  int16_t v35; // ax
  int v36; // ebx
  int v37; // eax
  int16_t v38; // si
  int16_t v39; // ax
  __int128 v41; // [esp-10h] [ebp-168h]
  __int128 v42; // [esp-10h] [ebp-168h]
  uint64_t v43; // [esp+0h] [ebp-158h]
  int64_t v44; // [esp+8h] [ebp-150h] BYREF
  int64_t v45; // [esp+10h] [ebp-148h]
  int64_t v46; // [esp+18h] [ebp-140h]
  int64_t v47; // [esp+20h] [ebp-138h]
  int64_t v48; // [esp+28h] [ebp-130h]
  int64_t v49; // [esp+30h] [ebp-128h]
  int64_t v50; // [esp+38h] [ebp-120h]
  __int128 v51; // [esp+40h] [ebp-118h]
  int v52; // [esp+50h] [ebp-108h]
  int v53; // [esp+54h] [ebp-104h]
  int v54; // [esp+58h] [ebp-100h]
  int v55; // [esp+5Ch] [ebp-FCh]
  __int128 v56; // [esp+60h] [ebp-F8h]
  int v57; // [esp+FCh] [ebp-5Ch]
  int v58; // [esp+100h] [ebp-58h]
  int v59; // [esp+104h] [ebp-54h]
  int v60; // [esp+108h] [ebp-50h]
  int v61; // [esp+10Ch] [ebp-4Ch]
  int v62; // [esp+110h] [ebp-48h]
  int v63; // [esp+114h] [ebp-44h]
  int v64; // [esp+118h] [ebp-40h]
  int v65; // [esp+11Ch] [ebp-3Ch] BYREF
  int v66; // [esp+120h] [ebp-38h]
  int i; // [esp+124h] [ebp-34h]
  int v68; // [esp+128h] [ebp-30h] BYREF
  int v69; // [esp+12Ch] [ebp-2Ch] BYREF
  int v70; // [esp+130h] [ebp-28h] BYREF
  int v71; // [esp+134h] [ebp-24h]
  int v72; // [esp+138h] [ebp-20h] BYREF
  int v73; // [esp+13Ch] [ebp-1Ch]
  int v74; // [esp+140h] [ebp-18h]
  int v75; // [esp+144h] [ebp-14h]
  int v76; // [esp+148h] [ebp-10h]
  int v77; // [esp+14Ch] [ebp-Ch] BYREF
  char v78; // [esp+150h] [ebp-8h]
  uint8_t v79; // [esp+154h] [ebp-4h]

  LODWORD(v44) = a1;
  v43 = __PAIR64__(a2, a3);
  v69 = 0;
  v68 = 0;
  v76 = 0;
  v79 = 0;
  sub_127776((_BYTE *)&v44 + 4, 0xF0u);
  if ( a7 )
  {
    v8 = sub_329A4(v44, *(_WORD *)(26 * a4 + dword_192B14 + 9), *(_WORD *)(26 * a4 + dword_192B14 + 11));
    v9 = sub_32AD1(v8);
    v70 = 0;
    v77 = 0;
    v78 = v9;
  }
  else
  {
    v10 = sub_32A20(v44, a4);
    v78 = sub_32AD1(v10);
    sub_49ED1(a4, &v70, &v77);
  }
  if ( !word_1998F6 )
    v78 = 15;
  sub_3B332(v44, a4, a7);
  if ( (a7 == 1 || !sub_3E563(a4))
    && (a7 && *(int16_t *)(26 * a4 + dword_192B14 + 15) > 0 || !a7 && !(uint16_t)sub_3897A(a4)) )
  {
    for ( i = 0; (int16_t)i < 8; ++i )
    {
      if ( v79 )
        break;
      v36 = (int16_t)v44;
      v37 = sub_3897A(v44);
      if ( (_WORD)v37 )
        break;
      v66 = v37;
      v68 = v37;
      v73 = v37;
      v74 = v37;
      v11 = (int16_t *)(313 * v36 + dword_192864 + 82 + 11 * (int16_t)i);
      if ( *v11 )
      {
        v12 = 28 * *v11;
        LOWORD(v12) = (uint8_t)byte_17F80F[v12];
        v75 = v12;
        v71 = 0;
        if ( sub_4584C(v36, i)
          && ((uint8_t)v78 & *((_BYTE *)v11 + 3)) != 0
          && ((_WORD)v75 != 2 && v11[3] || (_WORD)v75 == 2 && !v11[3]) )
        {
          v60 = a7;
          v59 = a4;
          if ( (uint16_t)sub_39F1D(i, v44, a4, a7, 0) )
          {
            v13 = v60;
            if ( (uint16_t)sub_389E8(*v11, v11[2], v59, v60) )
            {
              if ( !*((_BYTE *)v11 + 9) && *((_BYTE *)v11 + 10) == 1 )
              {
                v14 = *((_BYTE *)v11 + 2);
                *((_BYTE *)v11 + 10) = 0;
                *((_BYTE *)v11 + 9) = v14;
              }
              v15 = (int16_t)v44;
              v16 = dword_192864;
              v17 = dword_192864 + 313 * (int16_t)v44;
              if ( *(_BYTE *)(v17 + 64) == 1 )
              {
                if ( word_1998F6 == 1 && !word_1998E0 )
                  sub_ACB4A(v44, 2u);
                v16 = dword_192864;
                *(_BYTE *)(dword_192864 + 313 * (int16_t)v44 + 64) = 2;
              }
              else if ( *(_BYTE *)(v17 + 64) == 4 )
              {
                if ( word_1998F6 == 1 && !word_1998E0 )
                  sub_ACB4A(v44, 5u);
                v16 = 313 * (int16_t)v44;
                *(_BYTE *)(v16 + dword_192864 + 64) = 6;
              }
              if ( word_1998F6 == 1 && !word_1998E0 )
              {
                if ( a7 && (v15 = a6 / 20, v13 = 20, v16 = v15, !sub_3D259(a5 / 20, v15))
                  || !a7 && !(uint16_t)sub_339A7(a4, v16, v15) )
                {
                  if ( !(_WORD)v75 )
                  {
                    if ( a7 )
                    {
                      v13 = 20;
                      v18 = a5 / 20;
                      v19 = a6 / 20;
                    }
                    else
                    {
                      v20 = dword_192864 + 313 * a4;
                      v19 = *(uint8_t *)(v20 + 34);
                      v18 = *(uint8_t *)(v20 + 33);
                    }
                    sub_49D09(v18, v19);
                  }
                }
                if ( WORD2(v44) && (_WORD)v75 )
                {
                  HIDWORD(v41) = a7;
                  DWORD2(v41) = (char *)&v44 + 4;
                  DWORD1(v41) = (int16_t)(a6 - 20 * word_1998F2);
                  LODWORD(v41) = (int16_t)(a5 - 20 * word_1998F0);
                  v13 = a4;
                  sub_A8197(
                    (int16_t)v44,
                    (int16_t)(WORD2(v43) - 20 * word_1998F0),
                    a4,
                    (int16_t)(v43 - 20 * word_1998F2),
                    v41,
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
                    v56);
                  v76 = 0;
                  sub_127776((_BYTE *)&v44 + 4, 0xF0u);
                }
              }
              v64 = 1;
              while ( !v79 )
              {
                if ( !*((_BYTE *)v11 + 9) )
                  break;
                if ( (_WORD)v64 != 1 )
                  break;
                v61 = (int16_t)v44;
                if ( (uint16_t)sub_3897A(v44) )
                  break;
                switch ( (int16_t)v75 )
                {
                  case 0:
                    v13 = v11[2];
                    v23 = *v11;
                    v57 = a4;
                    LOWORD(v63) = sub_394F7(v61, a4, v23, v13, a7, &v65, &v69, &v68);
                    if ( (int16_t)v68 > 0 )
                    {
                      v24 = sub_32A20(v61, v57);
                      v25 = sub_39DE0(v24);
                      v72 = 0;
                      v13 = v25;
                      sub_39985(v61, (int16_t *)&v68, (int16_t *)&v72, v25, 0, word_17F815[14 * *v11], 0, 0, 0);
                      v74 += v68;
                      v73 += v72;
                    }
                    v26 = 15 * (int16_t)v76;
                    *(_WORD *)((char *)&v45 + v26) |= v63 & 1;
                    if ( (v63 & 2) != 0 )
                      *(_WORD *)((char *)&v45 + v26 + 2) = 1;
                    v27 = 15 * (int16_t)v76;
                    v28 = v65;
                    ++*(_WORD *)((char *)&v44 + v27 + 6);
                    *(_WORD *)((char *)&v45 + v27 + 4) += v28;
                    *(_WORD *)((char *)&v45 + v27 + 6) += v69;
                    *(_WORD *)((char *)&v46 + v27) = v11[2];
                    if ( (word_17F815[14 * *v11] & 0x200) != 0 )
                      *((_BYTE *)&v46 + v27 + 1) |= 1u;
                    *((_BYTE *)&v46 + 15 * (int16_t)v76 + 2) = 0;
                    v66 += v65;
                    --*((_BYTE *)v11 + 9);
                    break;
                  case 1:
                  case 2:
                  case 4:
                    v13 = a7;
                    v58 = (int16_t)i;
                    v62 = (int16_t)v44;
                    sub_3C892((int16_t)v44, a4, (int16_t)i, a7);
                    v21 = 11 * v58;
                    v22 = 313 * v62;
                    if ( (_WORD)v75 == 2 )
                      *(_WORD *)(v21 + dword_192864 + v22 + 88) = (uint8_t)byte_17F810[28
                                                                                             * *(int16_t *)(v21 + dword_192864 + v22 + 82)];
                    else
                      --*(_WORD *)(v21 + dword_192864 + v22 + 88);
                    *((_BYTE *)v11 + 9) = 0;
                    break;
                  case 3:
                    v13 = (int16_t)i;
                    v66 = sub_3A6CA(v61, a4, i);
                    v29 = 313 * v61 + dword_192864;
                    *((_BYTE *)v11 + 9) = 0;
                    --*(_WORD *)(v29 + 11 * v13 + 88);
                    break;
                  case 5:
                    v13 = a4;
                    sub_3A82F(v61, SWORD2(v43), (int16_t)v43, a4, i, a7);
                    if ( *v11 == 32 )
                      v64 = 0;
                    break;
                  default:
                    break;
                }
                v71 = 1;
                byte_19B57C = 1;
                if ( *((_BYTE *)v11 + 10) == 2 )
                  *((_BYTE *)v11 + 10) = 0;
                if ( a7 )
                {
                  v30 = (_WORD *)(26 * a4 + dword_192B14);
                  if ( *(int16_t *)((char *)v30 + 15) - (int16_t)v66 <= 0 || !*v30 )
                    v79 = 1;
                }
                else
                {
                  v79 = sub_3897A(a4);
                }
              }
              v31 = dword_192864 + 313 * (int16_t)v44;
              if ( *(_BYTE *)(v31 + 64) == 3 )
                *(_BYTE *)(v31 + 64) = 2;
              v32 = dword_192864 + 313 * (int16_t)v44;
              if ( *(_BYTE *)(v32 + 64) == 7 )
                *(_BYTE *)(v32 + 64) = 6;
              if ( (_WORD)v71 == 1 && word_1998F6 == 1 && !word_1998E0 )
              {
                if ( (_WORD)v75 )
                {
                  if ( (_WORD)v75 == 3 )
                    sub_33F60(v44, a4, *v11, v66);
                }
                else
                {
                  *(_WORD *)((char *)&v44 + 15 * (int16_t)v76 + 4) = *v11;
                  if ( (int16_t)v74 > 0 || (int16_t)v73 > 0 )
                  {
                    v33 = 15 * ((int16_t)v76 + 1);
                    sub_12779E((_BYTE *)&v44 + v33 + 4, (_BYTE *)&v44 + 15 * (int16_t)v76 + 4, 0xFu);
                    v34 = v74;
                    *((_BYTE *)&v46 + v33 + 2) = 1;
                    *(_WORD *)((char *)&v45 + v33 + 4) = v34;
                    *(_WORD *)((char *)&v45 + v33 + 2) = v34 > 0;
                    v35 = v73;
                    *(_WORD *)((char *)&v45 + v33 + 6) = v73;
                    *(_WORD *)((char *)&v45 + v33) = v35 > 0;
                    sub_124D7A();
                    sub_2D1ED(14, 376, word_1998F8, v13);
                    sub_2CBCC(14, 376, word_1998F8);
                    ++v76;
                    sub_2F445(word_1998F8, 15, 379);
                    sub_124D41();
                  }
                  ++v76;
                }
              }
            }
          }
        }
      }
    }
  }
  if ( WORD2(v44) )
  {
    HIDWORD(v42) = a7;
    DWORD2(v42) = (char *)&v44 + 4;
    DWORD1(v42) = (int16_t)(a6 - 20 * word_1998F2);
    LODWORD(v42) = (int16_t)(a5 - 20 * word_1998F0);
    sub_A8197(
      (int16_t)v44,
      (int16_t)(WORD2(v43) - 20 * word_1998F0),
      a4,
      (int16_t)(v43 - 20 * word_1998F2),
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
      v56);
  }
  v38 = v44;
  v39 = sub_3897A(v44);
  if ( v39 > 0 )
    sub_39E15(v38, SWORD2(v43), v43, v39);
  if ( v79 && !a7 && !*(_BYTE *)(313 * a4 + dword_192864 + 36) )
    sub_39E15(a4, a5, a6, v79);
  word_1998F4 = -1;
  return v71;
}
// 38EE7: variable 'v43' is possibly undefined
// 17F815: using guessed type int16_t word_17F815[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F4: using guessed type int16_t word_1998F4;
// 1998F6: using guessed type int16_t word_1998F6;
// 1998F8: using guessed type int16_t word_1998F8;
// 19B57C: using guessed type char byte_19B57C;


//----- (00039406) --------------------------------------------------------
int16_t __fastcall sub_39406( int a1, int a2)
{
  int v2; // eax

  if ( sub_4B0D3(a1, 25) )
    v2 = a2 / 3;
  else
    v2 = a2;
  return word_17D855[v2];
}
// 17D855: using guessed type int16_t word_17D855[9];


//----- (00039434) --------------------------------------------------------
int16_t __fastcall sub_39434(int a1, int a2, int a3, int a4, _WORD *a5, _WORD *a6)
{
  int16_t v6; // si
  int v7; // eax
  int v8; // eax
  int16_t v10; // [esp+0h] [ebp-8h]

  v6 = a2;
  *a6 = 100;
  *a5 = 0;
  if ( (a3 & 2) != 0 )
  {
    LOWORD(v7) = a2 / 2;
  }
  else
  {
    if ( (a3 & 4) == 0 )
      goto LABEL_7;
    v7 = 2 * a2;
    if ( v7 >= 8 )
      LOWORD(v7) = 8;
  }
  v6 = v7;
LABEL_7:
  *a5 += sub_39406(v10, v6);
  if ( (word_17F815[14 * a4] & 2) != 0 )
    *a5 *= 2;
  LOWORD(v8) = sub_4B0D3(v10, 15);
  if ( (_WORD)v8 )
    *a6 += 50;
  if ( (a3 & 0x20) == 0 )
  {
    v8 = 28 * a4;
    if ( (*((_BYTE *)word_17F815 + v8) & 4) == 0 )
    {
      LOWORD(v8) = word_17D867[v6];
      *a6 += v8;
    }
  }
  if ( (a3 & 4) != 0 )
  {
    *a5 += 25;
    *a6 -= 50;
  }
  else if ( (a3 & 2) != 0 )
  {
    *a6 += 50;
  }
  return v8;
}
// 39483: variable 'v10' is possibly undefined
// 17D867: using guessed type int16_t word_17D867[9];
// 17F815: using guessed type int16_t word_17F815[];


//----- (000394F7) --------------------------------------------------------
int __fastcall sub_394F7(int a1, int a2, int a3, int a4, int a5, _WORD *a6, _WORD *a7, _WORD *a8)
{
  int16_t v8; // di
  int16_t v9; // ax
  int v10; // eax
  int16_t v11; // ax
  int16_t v12; // ax
  int v13; // eax
  int v14; // ecx
  int16_t *v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int16_t v21; // bx
  int16_t v22; // bx
  int v23; // eax
  int v24; // eax
  int16_t v25; // bx
  _BOOL2 v26; // ax
  int v27; // eax
  int16_t v28; // bx
  _BOOL2 v29; // ax
  int v30; // eax
  _WORD *v31; // eax
  _BOOL2 v33; // [esp-8h] [ebp-78h]
  _BOOL2 v34; // [esp-8h] [ebp-78h]
  int v35; // [esp+8h] [ebp-68h]
  int16_t v36; // [esp+Ch] [ebp-64h] BYREF
  int v37; // [esp+10h] [ebp-60h] BYREF
  int v38; // [esp+14h] [ebp-5Ch] BYREF
  int v39; // [esp+18h] [ebp-58h] BYREF
  int v40; // [esp+1Ch] [ebp-54h]
  int v41; // [esp+20h] [ebp-50h]
  int v42; // [esp+24h] [ebp-4Ch] BYREF
  int v43; // [esp+28h] [ebp-48h] BYREF
  int v44; // [esp+2Ch] [ebp-44h]
  int v45; // [esp+30h] [ebp-40h]
  int v46; // [esp+34h] [ebp-3Ch]
  int v47; // [esp+38h] [ebp-38h]
  int v48; // [esp+3Ch] [ebp-34h]
  int v49; // [esp+40h] [ebp-30h]
  int v50; // [esp+44h] [ebp-2Ch]
  int v51; // [esp+48h] [ebp-28h]
  int v52; // [esp+4Ch] [ebp-24h]
  int16_t v53; // [esp+50h] [ebp-20h]
  int v54; // [esp+54h] [ebp-1Ch]
  int v55; // [esp+58h] [ebp-18h]
  int16_t v56; // [esp+5Ch] [ebp-14h]
  int v57; // [esp+60h] [ebp-10h]
  int v58; // [esp+64h] [ebp-Ch]
  int v59; // [esp+68h] [ebp-8h]
  int v60; // [esp+6Ch] [ebp-4h]

  v51 = a1;
  v8 = a2;
  v59 = a3;
  v53 = a4;
  v39 = 0;
  v38 = 0;
  *a6 = 0;
  *a8 = 0;
  *a7 = 0;
  v44 = 0;
  v9 = word_17F815[14 * (int16_t)a3];
  v48 = 0;
  v56 = v9;
  v39 = 0;
  if ( (v9 & 0x100) != 0 )
    LOBYTE(v53) = v53 | 0x40;
  if ( (v56 & 0x200) != 0 )
    HIBYTE(v53) |= 1u;
  if ( (v56 & 0x40) != 0 )
    LOBYTE(v53) = v53 | 0x10;
  v10 = 28 * (int16_t)v59;
  LOWORD(a2) = *(int16_t *)((char *)word_17F819 + v10);
  LOWORD(v10) = *(int16_t *)((char *)word_17F817 + v10);
  v50 = a2;
  v41 = v10;
  if ( a5 )
  {
    v12 = sub_28836(v51, v8);
  }
  else
  {
    v11 = sub_32A20(v8, v51);
    v44 = sub_39DE0(v11);
    sub_2885A(v51, v8);
  }
  v35 = (int16_t)v51;
  sub_39434((int16_t)v51, v12, v53, v59, &v36, &v39);
  v13 = 313 * v35;
  if ( a5 )
  {
    v14 = dword_192864 + v13;
    v15 = (int16_t *)(dword_192B14 + 26 * v8);
    v16 = *(uint8_t *)(313 * v15[2] + dword_192864 + 32);
    v17 = sub_3DFE0(*v15, v16);
    LOWORD(v16) = *(_WORD *)(v14 + 52);
    v49 = v16 - v17;
  }
  else
  {
    LOWORD(v13) = *(_WORD *)(dword_192864 + v13 + 52) - *(_WORD *)(313 * v8 + dword_192864 + 54);
    v49 = v13;
  }
  if ( (v53 & 0x80u) == 0 )
  {
    v40 = 1;
  }
  else
  {
    v40 = 3;
    v49 -= 20;
  }
  if ( (v53 & 0x10) != 0 )
    v49 += 25;
  v18 = ((int16_t)v41 * ((int16_t)v39 + word_199224[*(uint8_t *)(313 * (int16_t)v51 + dword_192864 + 32)] - 100)
       + 50)
      / 100;
  if ( v18 <= 1 )
    v18 = 1;
  v47 = v18;
  v19 = ((word_199224[*(uint8_t *)(dword_192864 + 313 * (int16_t)v51 + 32)] - 100 + (int16_t)v39) * (int16_t)v50
       + 50)
      / 100;
  if ( v19 < (int16_t)v47 )
    v19 = (int16_t)v47;
  v60 = v19;
  v58 = v19 - v47;
  v57 = 1;
  v20 = 40 - v36;
  if ( v20 > 95 )
    v20 = 95;
  v52 = 0;
  v55 = v20;
  while ( (int16_t)v52 < (int16_t)v40 && (_WORD)v57 )
  {
    v21 = sub_1247A0(0x64u);
    if ( (v56 & 0x400) != 0 )
      v21 = 100;
    if ( v21 > 95 || (v22 = v49 + v21, v22 > 100) )
      v22 = 100;
    if ( sub_4B0D3(v8, 8) && (int)sub_1247A0(0x64u) <= 30 )
      v22 = -1000;
    if ( v22 >= (int16_t)v55 )
    {
      if ( (int16_t)v58 <= 0 )
        v23 = v47;
      else
        v23 = (int16_t)v47 + (v22 - (int16_t)v55) * ((int16_t)v58 + 1) / (100 - (int16_t)v55);
      v43 = v23;
      if ( (int16_t)v23 > (int16_t)v60 )
        v43 = v60;
      if ( a5 )
      {
        v48 = 2;
        if ( (v53 & 0x100) != 0 )
          v54 = 4;
        else
          v54 = 1;
        v45 = 0;
        while ( (int16_t)v45 < (int16_t)v54 )
        {
          v42 = v43;
          sub_3A0B9(v8, (int16_t *)&v42);
          v31 = (_WORD *)(dword_192B14 + 26 * v8);
          if ( *(int16_t *)((char *)v31 + 15) <= 0 || !*v31 )
            v57 = 0;
          ++v45;
          *a6 += v42;
        }
      }
      else
      {
        if ( !v8 )
        {
          HIWORD(v24) = HIWORD(v43);
          LOWORD(v24) = (int16_t)v43 / 2;
          v43 = v24;
        }
        if ( sub_4B0D3(v8, 26) && (int)sub_1247A0((int16_t)(v43 + 15)) > (int16_t)v43 )
        {
          *a8 += v43;
          v43 = 0;
        }
        if ( (int16_t)v43 > 0 )
        {
          if ( (v53 & 0x100) != 0 )
          {
            v46 = 0;
            do
            {
              v25 = v51;
              v37 = v43;
              v33 = sub_4B0D3(v51, 1);
              v26 = sub_4B0D3(v25, 32);
              v27 = sub_39985(v8, (int16_t *)&v37, (int16_t *)&v38, (int16_t)v46, v53, v56, v26, v33, 0);
              v48 |= v27;
              *a6 += v37;
              ++v46;
              *a7 += v38;
            }
            while ( (int16_t)v46 < 4 );
          }
          else
          {
            v28 = v51;
            v34 = sub_4B0D3(v51, 1);
            v29 = sub_4B0D3(v28, 32);
            v30 = sub_39985(v8, (int16_t *)&v43, (int16_t *)&v38, (int16_t)v44, v53, v56, v29, v34, 0);
            v48 |= v30;
            *a6 += v43;
            *a7 += v38;
          }
        }
      }
    }
    ++v52;
  }
  return v48;
}
// 395DF: variable 'v12' is possibly undefined
// 17F815: using guessed type int16_t word_17F815[];
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 199224: using guessed type int16_t word_199224[15];


//----- (00039985) --------------------------------------------------------
int __fastcall sub_39985( int a1,
        int16_t *a2,
        int16_t *a3,
        int a4, int a5,
        int a6, int a7, int a8, int a9)
{
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  int v21; // [esp+18h] [ebp-20h] BYREF
  int i; // [esp+1Ch] [ebp-1Ch] BYREF
  int v23; // [esp+20h] [ebp-18h] BYREF
  int v24; // [esp+24h] [ebp-14h]
  int v25; // [esp+28h] [ebp-10h]
  int v26; // [esp+2Ch] [ebp-Ch]
  int v27; // [esp+30h] [ebp-8h]
  int v28; // [esp+34h] [ebp-4h]

  v26 = a4;
  v21 = 0;
  v23 = 0;
  v27 = 0;
  LOWORD(v24) = 0;
  *a3 = 0;
  if ( a1 )
  {
    if ( sub_4B0D3(a1, 10) )
    {
      v11 = (int)(*a2 - (__CFSHL__((uint64_t)*a2 >> 32, 2) + 4 * ((uint64_t)*a2 >> 32))) >> 2;
      if ( v11 <= 1 )
        LOWORD(v11) = 1;
      *a2 -= v11;
      *(_WORD *)(dword_192864 + 313 * a1 + 69) += v11;
    }
    if ( sub_4B0D3(a1, 7) )
      *a2 = (int16_t)(*a2 - (__CFSHL__(*a2 >> 15, 2) + 4 * (*a2 >> 15))) >> 2;
    v12 = 313 * a1 + dword_192864;
    LOWORD(v12) = *(_WORD *)(v12 + 2 * (int16_t)v26 + 41);
    if ( (a5 & 0x40) != 0 && !sub_4B0D3(a1, 13) )
      v12 = 0;
    v13 = 313 * a1 + dword_192864;
    if ( *(_BYTE *)(v13 + 38) && *(int16_t *)(v13 + 308) > 0 )
    {
      if ( sub_4B0D3(a1, 13) && (a5 & 0x40) != 0 )
        LOBYTE(a5) = a5 ^ 0x40;
      if ( (a5 & 0x40) == 0 && (!word_1998CA || sub_4B0D3(a1, 13)) )
      {
        *a2 -= *(int16_t *)((char *)&word_17F6C1 + 59 * *(uint8_t *)(313 * a1 + dword_192864 + 38));
        if ( sub_4B0D3(a1, 13) )
          *a2 -= 3;
      }
      if ( *a2 < 0 )
        *a2 = 0;
      if ( *a2 > 0 && (!word_1998CA || sub_4B0D3(a1, 13)) )
        LOWORD(v24) = 1;
      if ( (int16_t)v12 <= *a2 )
      {
        v15 = dword_192864;
        *a2 -= v12;
        v16 = (int16_t)v26;
        *a3 = v12;
        *(_WORD *)(313 * a1 + v15 + 2 * v16 + 41) -= v12;
      }
      else
      {
        v14 = 313 * a1 + dword_192864 + 2 * (int16_t)v26;
        *(_WORD *)(v14 + 41) -= *a2;
        *a3 = *a2;
        *a2 = 0;
      }
    }
    if ( (a6 & 1) != 0 )
      *a2 = 0;
    if ( (a6 & 0x10) != 0 && !sub_4B0D3(a1, 7) && *(_BYTE *)(dword_192864 + 313 * a1 + 175) != 0xFF )
    {
      HIWORD(v12) = 0;
      sub_366AF(a1, *a2 / 5);
    }
    if ( a7 )
      *a2 *= 2;
    if ( a8 )
    {
      v12 = 1;
    }
    else
    {
      LOWORD(v12) = (a5 & 8) != 0;
      if ( sub_4B0D3(a1, 14) || *(_BYTE *)(dword_192864 + 313 * a1 + 51) == 6 )
        v12 = 0;
    }
    HIWORD(v17) = HIWORD(a6);
    LOWORD(v17) = a6 & 8;
    v25 = v17;
    if ( (a6 & 8) != 0 )
    {
      v17 = 313 * a1;
      if ( *(_BYTE *)(dword_192864 + v17 + 32) > 9u )
        *a2 = (int16_t)(*a2 - (__CFSHL__(*a2 >> 15, 2) + 4 * (*a2 >> 15))) >> 2;
    }
    if ( *a2 > 0 )
    {
      LOBYTE(v24) = v24 | 2;
      if ( (a6 & 0x20) != 0 )
      {
        v18 = 313 * a1 + dword_192864;
        *(_WORD *)(v18 + 192) += *a2 / 2;
        LOWORD(v19) = *(_WORD *)(v18 + 170);
        if ( (int16_t)v19 > *(int16_t *)(v18 + 192) )
        {
          v19 = *a2 / 2 + *(int16_t *)(v18 + 192);
          *(_WORD *)(v18 + 192) = v19;
        }
        *(_WORD *)(dword_192864 + 313 * a1 + 192) = v19;
        v17 = *a2 / 2;
        v27 = v17;
      }
      if ( (_WORD)v12 )
      {
        LOWORD(v17) = *a2;
        v28 = v17;
        for ( i = v17; (int16_t)i > 0; sub_35251(a1, (int16_t *)&i, v21, v23, 1) )
        {
          v17 = sub_3897A(a1);
          if ( (_WORD)v17 )
            break;
          sub_36810(a1, &v21, &v23, a8, v25, 1, a9);
          if ( (int16_t)v21 == -1 )
            i = 0;
        }
      }
      else
      {
        v28 = v12;
      }
      LOWORD(v17) = *a2;
      for ( i = v17 - v28; (int16_t)i > 0 && !(uint16_t)sub_3897A(a1); sub_35251(a1, (int16_t *)&i, v21, v23, 1) )
      {
        sub_36810(a1, &v21, &v23, a8, v25, 0, a9);
        if ( (int16_t)v21 == -1 )
          i = 0;
      }
    }
  }
  else
  {
    LOWORD(v24) = sub_3A3C3(a2, a5, a6);
  }
  *a2 += v27;
  return v24;
}
// 39D72: variable 'v17' is possibly undefined
// 17F6C1: using guessed type int16_t word_17F6C1;
// 192864: using guessed type int dword_192864;
// 1998CA: using guessed type int16_t word_1998CA;


//----- (00039DE0) --------------------------------------------------------
int __fastcall sub_39DE0( int a1)
{
  if ( a1 > 315 || a1 <= 45 )
    return 0;
  if ( a1 <= 135 )
    return 3;
  if ( a1 > 225 )
    return 1;
  return 2;
}
// 39DEF: conditional instruction was optimized away because ax.2 is in (2E..13B)
// 39E01: conditional instruction was optimized away because ax.2 is in (88..13B)


//----- (00039E15) --------------------------------------------------------
int __fastcall sub_39E15( int a1, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edx
  int result; // eax
  int v8; // esi
  char v10; // [esp+4h] [ebp-4h]

  if ( *(uint8_t *)(dword_192864 + 313 * a1 + 32) == word_1998AC )
    v5 = word_19988E;
  else
    v5 = word_1998AC;
  v10 = v5;
  v6 = 313 * a1;
  *(_BYTE *)(v6 + dword_192864 + 75) = 0;
  sub_3891E(a1);
  sub_4588C(a1);
  if ( word_1998F6 != 1 || word_1998E0 )
  {
    *(_BYTE *)(dword_192864 + 313 * a1 + 36) = 5;
  }
  else if ( !*(_BYTE *)(v6 + dword_192864 + 36) )
  {
    sub_AEC7B(a1, a2, a4, a3, a1);
  }
  result = dword_192864;
  if ( *(_BYTE *)(313 * a1 + dword_192864 + 312) == 11 )
  {
    for ( result = 1; (int16_t)result < word_1998C0; ++result )
    {
      v8 = 313 * (int16_t)result + dword_192864;
      if ( *(_BYTE *)(v8 + 32) == 11 && (_WORD)result != a1 )
        *(_BYTE *)(v8 + 32) = v10;
    }
  }
  return result;
}
// 192864: using guessed type int dword_192864;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F6: using guessed type int16_t word_1998F6;


//----- (00039F1D) --------------------------------------------------------
int __fastcall sub_39F1D( int a1, int a2, int a3, int a4, int a5)
{
  int v6; // esi
  int16_t v7; // si
  int16_t v8; // ax
  int16_t v9; // bx
  int v10; // ecx
  int16_t v12; // [esp+0h] [ebp-8h]

  v6 = dword_192864 + 313 * a2 + 11 * a1;
  v12 = *(_WORD *)(v6 + 86);
  v7 = *(_WORD *)(v6 + 82);
  if ( a5 )
  {
    v9 = a5;
  }
  else
  {
    if ( a4 == 1 )
      v8 = sub_28836(a2, a3);
    else
      sub_2885A(a2, a3);
    v9 = v8;
  }
  if ( (v12 & 4) != 0 )
    v9 *= 2;
  if ( (v12 & 2) != 0 )
    v9 /= 2;
  v10 = 0;
  switch ( byte_17F80F[28 * v7] )
  {
    case 0:
      if ( v9 <= 8 )
        return 1;
      return v10;
    case 1:
    case 2:
    case 4:
      v10 = 1;
      if ( v7 == 19 && v9 > 8 || v7 == 40 && v9 > 5 )
        return 0;
      return v10;
    case 3:
      if ( sub_4B0D3(a2, 35) )
      {
        if ( v9 > 4 )
          goto LABEL_23;
      }
      else if ( v9 > 1 )
      {
        goto LABEL_23;
      }
      v10 = 1;
LABEL_23:
      if ( a3 )
        return 0;
      return v10;
    case 5:
      if ( v7 == 39 && v9 <= 4
        || v7 == 32 && v9 <= 1
        || v7 == 33 && v9 <= 5
        || v7 == 34 && v9 <= 5
        || v7 == 35 && v9 <= 5
        || v7 == 36 && v9 <= 1
        || v7 == 37 && v9 <= 5
        || v7 == 38
        || v7 == 13 && v9 <= 1
        || v7 == 44 && v9 <= 1
        || v7 == 45 && v9 <= 5 )
      {
        return 1;
      }
      return v10;
    default:
      return v10;
  }
}
// 39F64: variable 'v8' is possibly undefined
// 192864: using guessed type int dword_192864;


//----- (0003A0B9) --------------------------------------------------------
int __fastcall sub_3A0B9( int a1, int16_t *a2)
{
  int16_t v3; // cx
  int16_t v4; // ax
  int result; // eax

  v3 = 0;
  v4 = sub_3E095(
         *(_WORD *)(dword_192B14 + 26 * a1),
         *(uint8_t *)(dword_192864 + 313 * *(int16_t *)(dword_192B14 + 26 * a1 + 4) + 32),
         0,
         HIBYTE(*(_WORD *)(dword_192B14 + 26 * a1 + 17)));
  if ( v4 < *a2 )
    *a2 = v4;
  for ( *a2 += *(_WORD *)(26 * a1 + dword_192B14 + 13); v4 <= *a2; *a2 -= v4 )
    ++v3;
  result = dword_192B14 + 26 * a1;
  *(_WORD *)(result + 13) = *a2;
  *a2 = v3;
  return result;
}
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (0003A142) --------------------------------------------------------
int __usercall sub_3A142(int a1, int a2)
{
  int v2; // edx
  int v3; // eax

  if ( word_199878 == -1 )
    return 0;
  HIWORD(v2) = HIWORD(dword_192B18);
  v3 = dword_192B18 + 361 * word_199878;
  LOWORD(a2) = *(uint8_t *)(v3 + 336);
  LOWORD(a1) = *(uint8_t *)(v3 + 337);
  LOWORD(v2) = *(uint8_t *)(v3 + 352);
  LOWORD(v3) = *(uint8_t *)(v3 + 357);
  return (8 * v3) | (4 * v2) | (2 * a1) | a2;
}
// 192B18: using guessed type int dword_192B18;
// 199878: using guessed type int16_t word_199878;


//----- (0003A19E) --------------------------------------------------------
int __fastcall sub_3A19E(int a1)
{
  int result; // eax
  int v3; // esi
  int v4; // eax
  int v5; // eax
  unsigned int v6; // eax
  int v7; // ebx
  uint16_t v8; // ax
  int16_t i; // bx
  int v10; // edx
  int v11; // eax
  int v12; // edx
  int16_t j; // bx
  int v14; // eax
  int16_t k; // bx
  int v16; // eax
  int16_t m; // bx
  int v18; // eax
  _WORD v19[4]; // [esp+0h] [ebp-Ch] BYREF
  unsigned int v20; // [esp+8h] [ebp-4h]

  result = word_199878;
  v3 = 0;
  if ( word_199878 != -1 )
  {
    if ( *(_BYTE *)(dword_192B18 + 361 * word_199878 + 336) )
    {
      v19[0] = 26;
      v3 = 1;
    }
    if ( *(_BYTE *)(dword_192B18 + 361 * word_199878 + 337) )
    {
      v4 = (int16_t)v3++;
      v19[v4] = 27;
    }
    if ( *(_BYTE *)(dword_192B18 + 361 * word_199878 + 352) )
    {
      v5 = (int16_t)v3++;
      v19[v5] = 42;
    }
    result = dword_192B18;
    if ( *(_BYTE *)(361 * word_199878 + dword_192B18 + 357) )
    {
      result = (int16_t)v3++;
      v19[result] = 47;
    }
    if ( (int16_t)v3 < (int16_t)a1 )
      a1 = v3;
    while ( (int16_t)a1 > 0 )
    {
      v6 = sub_1247A0((int16_t)v3);
      v20 = v6 - 1;
      v7 = (int16_t)(v6 - 1);
      sub_145EA(word_199878, v19[v7], a1);
      v8 = v19[v7];
      if ( v8 < 0x1Bu )
      {
        if ( v8 == 26 )
        {
          for ( i = 0; i < 8; ++i )
          {
            v10 = 11 * i;
            if ( byte_17F80F[28 * *(int16_t *)(v10 + dword_192864 + 82)] == 1
              || byte_17F80F[28 * *(int16_t *)(v10 + dword_192864 + 82)] == 2 )
            {
              v11 = 11 * i;
              v12 = dword_192864;
              *(_WORD *)(dword_192864 + v11 + 82) = 0;
              *(_BYTE *)(v12 + v11 + 84) = 0;
            }
          }
        }
      }
      else if ( v8 <= 0x1Bu )
      {
        for ( j = 0; j < 8; ++j )
        {
          v14 = dword_192864 + 11 * j;
          if ( !byte_17F80F[28 * *(int16_t *)(v14 + 82)] )
          {
            *(_WORD *)(v14 + 82) = 0;
            *(_BYTE *)(v14 + 84) = 0;
          }
        }
      }
      else if ( v8 >= 0x2Au )
      {
        if ( v8 <= 0x2Au )
        {
          for ( k = 0; k < 8; ++k )
          {
            v16 = dword_192864 + 11 * k;
            if ( byte_17F80F[28 * *(int16_t *)(v16 + 82)] == 5 )
            {
              *(_WORD *)(v16 + 82) = 0;
              *(_BYTE *)(v16 + 84) = 0;
            }
          }
        }
        else if ( v8 == 47 )
        {
          for ( m = 0; m < 8; ++m )
          {
            v18 = 11 * m + dword_192864;
            if ( byte_17F80F[28 * *(int16_t *)(v18 + 82)] == 4 )
            {
              *(_WORD *)(v18 + 82) = 0;
              *(_BYTE *)(v18 + 84) = 0;
            }
          }
        }
      }
      result = (int)sub_1331D2(v20, (int)v19, 2, 4);
      LOWORD(v3) = v3 - 1;
      --a1;
    }
  }
  return result;
}
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int dword_192B18;
// 199878: using guessed type int16_t word_199878;


//----- (0003A3C3) --------------------------------------------------------
int __fastcall sub_3A3C3(int16_t *a1, int a2, int a3)
{
  int16_t v4; // ax
  int v5; // eax
  int16_t v6; // si
  int16_t v7; // bx
  int16_t v8; // di
  int v9; // eax
  int16_t v10; // ax
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int16_t v14; // ax
  int v15; // eax
  int16_t v16; // dx
  int result; // eax
  char v18; // [esp+0h] [ebp-58h] BYREF
  char v19; // [esp+1h] [ebp-57h]
  char v20; // [esp+2h] [ebp-56h]
  int16_t v21; // [esp+3h] [ebp-55h]
  char v22; // [esp+5h] [ebp-53h]
  int16_t v23; // [esp+6h] [ebp-52h]
  char v24; // [esp+25h] [ebp-33h]
  char v25; // [esp+26h] [ebp-32h]
  char v26; // [esp+2Ah] [ebp-2Eh]
  int v27; // [esp+45h] [ebp-13h]
  int v28; // [esp+4Ch] [ebp-Ch]
  int v29; // [esp+50h] [ebp-8h]
  int16_t v30; // [esp+54h] [ebp-4h]

  v30 = a3;
  sub_127776(&v18, 0x49u);
  sub_5685F(*(uint8_t *)(dword_192864 + 32));
  v5 = 100 * (*(int16_t *)((char *)&word_17F642 + 15 * v4) + 100) / 100;
  v6 = 0;
  v7 = 0;
  v29 = 0;
  v8 = v5;
  if ( (v30 & 0x80u) != 0 )
  {
    word_1998E2 = 1;
    v22 = 1;
    byte_199B5F = 1;
    if ( *(_BYTE *)(dword_192864 + 38) == 23 )
      goto LABEL_47;
    v9 = 3753 * word_19988E + dword_197F98;
    if ( *(_BYTE *)(v9 + 386) == 3 )
    {
      v10 = *a1 / 2;
    }
    else
    {
      if ( *(_BYTE *)(v9 + 472) != 3 )
      {
LABEL_8:
        if ( (int)sub_1247A0(0x64u) <= *a1 )
        {
          v20 = 0;
          v21 = 0;
          byte_199B5F = 1;
          v23 = 1;
          ++word_199B60;
          v18 = word_1998AC;
          v7 = 1;
          v19 = word_199878;
          if ( word_1998F6 )
          {
            if ( word_199878 != -1 )
              sub_DD2F2((int)&v18);
          }
        }
        goto LABEL_47;
      }
      v10 = (int16_t)(*a1 - (__CFSHL__(*a1 >> 15, 2) + 4 * (*a1 >> 15))) >> 2;
    }
    *a1 = v10;
    goto LABEL_8;
  }
  if ( sub_4B0D3(0, 7) )
  {
    *a1 = (int16_t)(*a1 - (__CFSHL__(*a1 >> 15, 2) + 4 * (*a1 >> 15))) >> 2;
    --*a1;
  }
  v11 = v29;
  LOBYTE(v11) = v29 | 1;
  if ( (int16_t)sub_3A142((int)a1, 0) <= 0 )
  {
    v6 = 0;
    if ( *(_BYTE *)(dword_192864 + 38) )
      v29 = v11;
    v7 = *a1 - *(_WORD *)(dword_192864 + 43);
  }
  else
  {
    v6 = *a1 - *(_WORD *)(dword_192864 + 41);
    if ( *(_BYTE *)(dword_192864 + 38) )
      v29 = v11;
    v7 = 0;
  }
  if ( v6 <= 0 || (v30 & 8) != 0 )
  {
    v6 = 0;
  }
  else
  {
    if ( (v30 & 0x20) != 0 )
      v6 *= 2;
    v12 = dword_192864;
    *(_WORD *)(dword_192864 + 192) += v6;
    if ( v8 < *(int16_t *)(v12 + 192) )
    {
      v13 = *(int16_t *)(v12 + 192);
      v28 = v8;
      LOWORD(v13) = v13 / v8;
      *a1 = v13;
      sub_3A19E((int16_t)v13);
      *(_WORD *)(dword_192864 + 192) = *(int16_t *)(dword_192864 + 192) % v28;
    }
  }
  if ( v7 <= 0 )
    goto LABEL_46;
  if ( word_199878 == -1 )
    goto LABEL_47;
  if ( (v30 & 8) != 0 )
  {
LABEL_46:
    v7 = 0;
    goto LABEL_47;
  }
  if ( (v30 & 0x20) != 0 )
    v7 *= 2;
  if ( *(int16_t *)(dword_192864 + 170) < 32000 )
    *(_WORD *)(dword_192864 + 170) += v7;
  if ( *(int16_t *)(dword_192864 + 170) > 100 )
  {
    v18 = word_1998AC;
    v20 = 1;
    v19 = word_199878;
    v14 = *(int16_t *)(dword_192864 + 170) / 100;
    byte_199B5C = 1;
    v21 = v14;
    if ( word_1998F6 )
    {
      if ( word_199878 != -1 )
      {
        sub_DD2F2((int)&v18);
        if ( v26 )
        {
          v15 = dword_192864;
          v16 = 5;
        }
        else if ( v24 )
        {
          v15 = dword_192864;
          v16 = 20;
        }
        else
        {
          if ( !v25 )
          {
LABEL_45:
            *(_WORD *)(dword_192864 + 170) -= 100 * v27;
            goto LABEL_47;
          }
          v15 = dword_192864;
          v16 = 10;
        }
        *(_BYTE *)(v15 + 38) = 0;
        *(_WORD *)(v15 + 41) -= v16;
        *(_WORD *)(v15 + 43) -= v16;
        goto LABEL_45;
      }
    }
  }
LABEL_47:
  result = v29;
  *a1 = v7 + v6;
  return result;
}
// 3A3EB: variable 'v4' is possibly undefined
// 17F642: using guessed type int16_t word_17F642;
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int dword_197F98;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998E2: using guessed type int16_t word_1998E2;
// 1998F6: using guessed type int16_t word_1998F6;
// 199B5C: using guessed type char byte_199B5C;
// 199B5F: using guessed type char byte_199B5F;
// 199B60: using guessed type int16_t word_199B60;


//----- (0003A6CA) --------------------------------------------------------
int __fastcall sub_3A6CA( int a1, int a2, int a3)
{
  int v5; // eax
  int v6; // ebx
  int v7; // ebx
  int v8; // eax
  int v9; // ecx
  int v10; // ebx
  int v12; // [esp+0h] [ebp-1Ch]
  int v13; // [esp+8h] [ebp-14h] BYREF
  int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h]

  v5 = dword_192864 + 313 * a1;
  v6 = 11 * a3;
  LOWORD(v6) = *(_WORD *)(v6 + v5 + 82);
  v14 = v6;
  v7 = 14 * (int16_t)v6;
  v12 = word_199224[*(uint8_t *)(v5 + 32)];
  v15 = v12 * word_17F817[v7] / 100;
  v8 = v12 * word_17F819[v7];
  v9 = 0;
  v16 = 0;
  v17 = v8 / 100 - v15;
  while ( *(uint8_t *)(dword_192864 + 313 * a1 + 11 * a3 + 91) > (int16_t)v16 )
  {
    v10 = (int16_t)v17;
    v13 = (int16_t)v15 + v10 * (int16_t)sub_1247A0(0x64u) / 100;
    LOWORD(v10) = word_17F815[14 * (int16_t)v14];
    ++v16;
    sub_3A3C3((int16_t *)&v13, 0, v10);
    v9 += v13;
  }
  return v9;
}
// 17F815: using guessed type int16_t word_17F815[];
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 199224: using guessed type int16_t word_199224[15];


//----- (0003A7AA) --------------------------------------------------------
int __fastcall sub_3A7AA( int a1, int a2)
{
  bool v3; // ebx
  char v4; // dl

  v3 = 0;
  if ( !a1 )
    return v3;
  v4 = byte_17F80F[28 * a1];
  if ( v4 )
  {
    if ( (uint8_t)v4 >= 4u )
    {
      if ( (uint8_t)v4 <= 4u )
      {
        v3 = a1 == 31;
      }
      else if ( v4 != 5 )
      {
        return 0;
      }
      if ( a1 == 36 || a1 == 13 || a1 == 33 )
        return 1;
    }
  }
  else if ( (a2 & 2) == 0 )
  {
    return 1;
  }
  return v3;
}


//----- (0003A812) --------------------------------------------------------
void __fastcall sub_3A812( int a1, int a2)
{
  *(_BYTE *)(dword_192864 + 313 * a1 + 74) = a2;
  sub_3891E(a1);
}
// 192864: using guessed type int dword_192864;


//----- (0003A82F) --------------------------------------------------------
void __fastcall sub_3A82F( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  uint16_t v12; // dx
  int16_t v13; // dx
  int v14; // edx
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // [esp+4h] [ebp-18h]
  int v19; // [esp+8h] [ebp-14h] BYREF
  int v20; // [esp+Ch] [ebp-10h]
  int v21; // [esp+10h] [ebp-Ch] BYREF
  int v22; // [esp+14h] [ebp-8h]
  int v23; // [esp+18h] [ebp-4h]

  v22 = a2;
  sub_49ED1(a1, &v19, &v21);
  if ( a6 )
    v9 = (((int16_t)sub_134637(
                      v19 + v22,
                      v21 + v23,
                      *(_WORD *)(26 * a4 + dword_192B14 + 9),
                      *(_WORD *)(26 * a4 + dword_192B14 + 11))
         + 19)
        / 20
        + 2)
       / 3;
  else
    sub_2885A(a1, a4);
  v20 = v9;
  v10 = 313 * a1;
  v18 = 11 * a5;
  v11 = v10 + dword_192864 + v18;
  v12 = *(_WORD *)(v11 + 82);
  if ( v12 < 0x24u )
  {
    if ( v12 < 0x21u )
    {
      if ( v12 < 0xDu )
        goto LABEL_61;
      if ( v12 <= 0xDu )
      {
        if ( word_1998F6 == 1 )
          sub_ADE18(a1, (int16_t)v22, (int16_t)v23, 2, *(uint8_t *)(dword_192864 + 313 * a1 + 11 * a5 + 91));
        v14 = 313 * a1 + dword_192864;
        v15 = 11 * a5;
        goto LABEL_60;
      }
      if ( v12 == 32 && a4 && !a6 )
      {
        sub_AC87A(a1, a4);
        *(_BYTE *)(dword_192864 + 313 * a4 + 74) = a1;
        sub_3891E(a4);
        --*(_BYTE *)(11 * a5 + 313 * a1 + dword_192864 + 91);
      }
      goto LABEL_61;
    }
    if ( v12 <= 0x21u )
    {
      if ( a6
        && (byte_17F80F[28 * *(int16_t *)(dword_192B14 + 26 * a4)] == 1
         || byte_17F80F[28 * *(int16_t *)(dword_192B14 + 26 * a4)] == 4) )
      {
        v13 = *(uint8_t *)(dword_192864 + 313 * a1 + 32);
        if ( sub_3BB3D(a4) != v13 )
          sub_ABA09(a5, v20);
      }
      goto LABEL_61;
    }
    if ( v12 > 0x22u )
      goto LABEL_33;
    if ( !a4 || a6 )
LABEL_61:
      JUMPOUT(0x394F1);
    sub_AC136(a1, a4, *(uint8_t *)(v11 + 91));
  }
  else
  {
    if ( v12 <= 0x24u )
    {
      if ( word_1998F6 == 1 )
        sub_ADE18(a1, (int16_t)v22, (int16_t)v23, 1, *(uint8_t *)(v11 + 91));
      v15 = dword_192864 + 313 * a1;
      v14 = 11 * a5;
      goto LABEL_60;
    }
    if ( v12 >= 0x27u )
    {
      if ( v12 > 0x27u )
      {
        if ( v12 < 0x2Cu )
          goto LABEL_61;
        if ( v12 <= 0x2Cu )
        {
          if ( word_1998F6 == 1 )
            sub_ADE18(a1, (int16_t)v22, (int16_t)v23, 0, *(uint8_t *)(v11 + 91));
LABEL_36:
          v16 = 313 * a1;
          v17 = dword_192864;
LABEL_37:
          v14 = v16 + v17;
          v15 = 11 * a5;
          goto LABEL_60;
        }
        if ( v12 != 45 )
          goto LABEL_61;
LABEL_33:
        if ( a4 )
        {
          sub_ACF83(a1, a4, a5);
          v14 = dword_192864 + 313 * a1;
          v15 = 11 * a5;
LABEL_60:
          *(_BYTE *)(v14 + v15 + 91) = 0;
          goto LABEL_61;
        }
        if ( word_1998F6 )
          goto LABEL_61;
        goto LABEL_36;
      }
      if ( a4 && !a6 && *(uint8_t *)(v10 + dword_192864 + 66) != a4 && *(_BYTE *)(v11 + 91) )
      {
        sub_AD3CA(a1, a4);
        *(_BYTE *)(v18 + v10 + dword_192864 + 91) = 0;
      }
      if ( !a4 && !word_1998F6 || *(_BYTE *)(dword_192864 + 313 * a1 + 66) != 0xFF )
      {
        v17 = 313 * a1;
        v16 = dword_192864;
        goto LABEL_37;
      }
      goto LABEL_61;
    }
    if ( v12 <= 0x25u )
    {
      if ( !a4 || a6 )
        goto LABEL_61;
      sub_3B627(a1, a4);
    }
    else
    {
      if ( a6 )
        goto LABEL_61;
      sub_AD98A(a1, a4, *(uint8_t *)(v11 + 91));
    }
  }
  *(_BYTE *)(v18 + v10 + dword_192864 + 91) = 0;
  goto LABEL_61;
}
// 3A8FB: control flows out of bounds to 394F1
// 3A8A2: variable 'v9' is possibly undefined
// ABA09: using guessed type _DWORD __stdcall sub_ABA09(int16_t, int16_t);
// AC136: using guessed type int __fastcall sub_AC136(_DWORD, _DWORD, _DWORD);
// AC87A: using guessed type int __fastcall sub_AC87A(_DWORD, _DWORD);
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 1998F6: using guessed type int16_t word_1998F6;


//----- (0003AC20) --------------------------------------------------------
int __fastcall sub_3AC20( int a1, int a2, _WORD *a3, _WORD *a4)
{
  int16_t v5; // edx^2
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int16_t v9; // bx
  int v10; // eax
  int16_t v11; // ax
  int v12; // eax
  int result; // eax
  int v16; // [esp+Ch] [ebp-20h] BYREF
  int v17; // [esp+10h] [ebp-1Ch]
  int16_t v18; // [esp+14h] [ebp-18h]
  int v19; // [esp+18h] [ebp-14h]
  int v20; // [esp+1Ch] [ebp-10h]
  int v21; // [esp+20h] [ebp-Ch]
  int v22; // [esp+24h] [ebp-8h]
  int v23; // [esp+28h] [ebp-4h] BYREF

  v5 = HIWORD(dword_192B14);
  v6 = dword_192B14 + 26 * a1;
  LOWORD(v8) = *(_WORD *)(v6 + 6);
  v7 = 313 * *(int16_t *)(v6 + 4);
  v20 = v8;
  HIWORD(v8) = HIWORD(dword_192864);
  LOWORD(v7) = *(uint8_t *)(dword_192864 + v7 + 32);
  *a3 = 0;
  *a4 = 0;
  v9 = word_199242[(int16_t)v7];
  v18 = word_17F815[14 * v9];
  v17 = 0;
  if ( (v18 & 0x100) != 0 )
    v17 = 64;
  v10 = 28 * v9;
  LOWORD(v8) = *(int16_t *)((char *)word_17F819 + v10);
  LOWORD(v10) = *(int16_t *)((char *)word_17F817 + v10);
  v21 = 0;
  v22 = v10;
  v19 = v8 - v10;
  while ( 1 )
  {
    result = dword_192B14 + 26 * a1;
    if ( (int16_t)v21 >= *(int16_t *)(result + 15) )
      break;
    v11 = sub_1247A0(0x64u);
    if ( v11 > 0 )
    {
      v23 = 0;
      if ( (int16_t)v19 <= 0 )
        v12 = v22;
      else
        v12 = (int16_t)v22 + (int16_t)v19 * (v11 + 100 / (2 * (int16_t)v19)) / 100;
      v16 = v12;
      sub_39985(v20, (int16_t *)&v16, (int16_t *)&v23, a2, v17, v18, 0, 0, 0);
      *a3 += v16;
      *a4 += v23;
    }
    ++v21;
  }
  return result;
}
// 17F815: using guessed type int16_t word_17F815[];
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 199242: using guessed type int16_t word_199242[9];


//----- (0003AD57) --------------------------------------------------------
void __fastcall sub_3AD57( int a1, int a2, int a3, _WORD *a4, _WORD *a5)
{
  int v6; // eax
  int16_t v7; // di
  int16_t v8; // bx
  int16_t v9; // dx
  int v10; // eax
  int16_t v11; // cx
  int v12; // edx
  int v13; // eax
  int v14; // ebx
  int16_t v15; // ax
  int16_t v16; // ax
  int v17; // eax
  int v18; // eax
  int16_t v22; // [esp+10h] [ebp-20h]
  int v23; // [esp+14h] [ebp-1Ch] BYREF
  int16_t v24; // [esp+18h] [ebp-18h]
  int v25; // [esp+1Ch] [ebp-14h]
  int v26; // [esp+20h] [ebp-10h] BYREF
  int v27; // [esp+24h] [ebp-Ch]
  int16_t v28; // [esp+28h] [ebp-8h]
  int v29; // [esp+2Ch] [ebp-4h]

  v6 = 26 * a1;
  v23 = 0;
  v7 = *(_WORD *)(dword_192B14 + v6 + 6);
  v8 = *(uint8_t *)(dword_192864 + 313 * *(int16_t *)(dword_192B14 + v6 + 4) + 32);
  *a4 = 0;
  *a5 = 0;
  v9 = word_199254[v8];
  v28 = word_17F815[14 * v9];
  v24 = 0;
  if ( (v28 & 0x100) != 0 )
    v24 = 64;
  v10 = 28 * v9;
  v11 = *(int16_t *)((char *)word_17F819 + v10);
  LOWORD(v10) = *(int16_t *)((char *)word_17F817 + v10);
  v25 = v10;
  if ( a3 )
  {
    v14 = sub_3DF8D(v8);
    v27 = v14
        - sub_3DFE0(
            *(_WORD *)(26 * v7 + dword_192B14),
            *(uint8_t *)(313 * *(int16_t *)(26 * v7 + dword_192B14 + 4) + dword_192864 + 32));
  }
  else
  {
    v12 = 313 * v7 + dword_192864;
    v13 = sub_3DF8D(v8);
    LOWORD(v13) = v13 - *(_WORD *)(v12 + 54);
    v27 = v13;
  }
  v29 = 0;
  v22 = v11 - v25;
  while ( (int16_t)v29 < *(int16_t *)(26 * a1 + dword_192B14 + 15) && (uint16_t)sub_3D299(a1) )
  {
    v15 = sub_1247A0(0x64u);
    if ( v15 > 95 || (v16 = v27 + v15, v16 > 100) )
      v16 = 100;
    if ( v16 >= 40 )
    {
      if ( v22 <= 0 )
        v17 = v25;
      else
        v17 = (int16_t)v25 + (v22 + 1) * (v16 - 40) / 60;
      v26 = v17;
      if ( a3 )
      {
        sub_3A0B9(v7, (int16_t *)&v26);
        *(_WORD *)(26 * v7 + dword_192B14 + 15) -= v26;
        *a4 += v26;
      }
      else
      {
        v23 = 0;
        if ( !v7 )
        {
          HIWORD(v18) = HIWORD(v26);
          LOWORD(v18) = (int16_t)v26 / 2;
          v26 = v18;
        }
        sub_39985(v7, (int16_t *)&v26, (int16_t *)&v23, a2, v24, v28, 0, 0, 0);
        *a4 += v26;
        *a5 += v23;
      }
    }
    ++v29;
  }
  if ( !(uint16_t)sub_3D299(a1) && a3 == 1 )
  {
    sub_3DDD8(a1);
    sub_3BC80(v7);
  }
  JUMPOUT(0x3A0B3);
}
// 3AFAE: control flows out of bounds to 3A0B3
// 3AE52: conditional instruction was optimized away because %var_18.1 is in (==0|==40)
// 17F815: using guessed type int16_t word_17F815[];
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 199254: using guessed type int16_t word_199254[42];


//----- (0003AFB3) --------------------------------------------------------
int __fastcall sub_3AFB3( int a1)
{
  int v2; // edx
  int result; // eax
  int v4; // ebx

  v2 = 0;
  do
  {
    result = dword_192864 + 313 * a1;
    v4 = 11 * (int16_t)v2++;
    *(_BYTE *)(v4 + result + 91) = 0;
  }
  while ( (int16_t)v2 < 8 );
  *(_BYTE *)(result + 74) = -1;
  return result;
}
// 192864: using guessed type int dword_192864;


//----- (0003AFE5) --------------------------------------------------------
_BOOL1 __fastcall sub_3AFE5( int a1, int a2)
{
  return *(_BYTE *)(a2 + 313 * a1 + dword_192864 + 184) == 1;
}
// 192864: using guessed type int dword_192864;


//----- (0003B004) --------------------------------------------------------
char __fastcall sub_3B004( int a1, int a2)
{
  int16_t v3; // cx
  int16_t i; // bx
  char v6; // [esp+4h] [ebp-8h]
  char v7; // [esp+8h] [ebp-4h]

  v7 = 0;
  v6 = 0;
  v3 = 0;
  for ( i = 0; i < 39 && !v6; ++i )
  {
    if ( i == a2 && sub_3AFE5(a1, v3) )
    {
      v7 = 1;
      v6 = 1;
    }
    if ( (uint16_t)sub_1276F0(313 * a1 + dword_192864 + 76, i) == 1 )
      ++v3;
  }
  return v7;
}
// 192864: using guessed type int dword_192864;


//----- (0003B077) --------------------------------------------------------
void __fastcall sub_3B077(int a1, int a2)
{
  int v3; // eax
  int16_t v4; // ax
  int16_t v5; // dx
  int16_t v6; // ax
  int v7; // ebx
  int v8; // edx
  int v9; // eax
  _BOOL2 v10; // ax
  int v11; // eax
  __int128 v12; // [esp-10h] [ebp-12Ch]
  _BOOL2 v13; // [esp-8h] [ebp-124h]
  int64_t v14; // [esp+0h] [ebp-11Ch] BYREF
  int64_t v15; // [esp+8h] [ebp-114h]
  int64_t v16; // [esp+10h] [ebp-10Ch]
  int64_t v17; // [esp+18h] [ebp-104h]
  int64_t v18; // [esp+20h] [ebp-FCh]
  int64_t v19; // [esp+28h] [ebp-F4h]
  int64_t v20; // [esp+30h] [ebp-ECh]
  int64_t v21; // [esp+38h] [ebp-E4h]
  __int128 v22; // [esp+40h] [ebp-DCh]
  int v23; // [esp+50h] [ebp-CCh]
  int v24; // [esp+54h] [ebp-C8h]
  int v25; // [esp+58h] [ebp-C4h]
  int v26; // [esp+5Ch] [ebp-C0h]
  __int128 v27; // [esp+60h] [ebp-BCh]
  int v28; // [esp+F4h] [ebp-28h]
  int v29; // [esp+F8h] [ebp-24h]
  int v30; // [esp+FCh] [ebp-20h] BYREF
  int v31; // [esp+100h] [ebp-1Ch] BYREF
  int16_t v32; // [esp+104h] [ebp-18h] BYREF
  int v33; // [esp+108h] [ebp-14h] BYREF
  int v34; // [esp+10Ch] [ebp-10h]
  int v35; // [esp+110h] [ebp-Ch]
  int v36; // [esp+114h] [ebp-8h]
  int v37; // [esp+118h] [ebp-4h]

  v33 = 0;
  v30 = 0;
  sub_127776((_BYTE *)&v14 + 4, 0xF0u);
  v28 = 313 * (int16_t)v14;
  v3 = v28 + dword_192864;
  v33 = 0;
  LOWORD(v3) = *(_WORD *)(v28 + dword_192864 + 69);
  v36 = v3;
  v29 = a2;
  v4 = sub_32A20(a2, v14);
  v5 = v29;
  v37 = sub_39DE0(v4);
  sub_2885A(v14, v5);
  sub_39434((int16_t)v14, v6, 0, 3, &v32, &v33);
  v7 = 100;
  v8 = 8;
  v36 = ((word_199224[*(uint8_t *)(v28 + dword_192864 + 32)] - 100 + (int16_t)v33) * (int16_t)v36 + 50) / 100;
  v35 = 0;
  if ( sub_4B0D3(v29, 8) && (int)sub_1247A0(0x64u) > 30 )
    v36 = 0;
  HIWORD(v9) = HIWORD(v36);
  v31 = v36;
  if ( !a2 )
  {
    LOWORD(v8) = (int16_t)v36 >> 15;
    LOWORD(v9) = (int16_t)v36 / 2;
    v31 = v9;
  }
  if ( (int16_t)v31 > 0 )
  {
    v13 = sub_4B0D3(v14, 1);
    v10 = sub_4B0D3(v14, 32);
    v7 = (int)&v30;
    v8 = (int)&v31;
    v35 = sub_39985(a2, (int16_t *)&v31, (int16_t *)&v30, (int16_t)v37, 0, 0, v10, v13, 0);
  }
  v34 = sub_3897A(a2);
  if ( word_1998F6 && !word_1998E0 )
  {
    if ( !(uint16_t)sub_339A7(a2, v8, v7) )
      sub_49D09(*(uint8_t *)(313 * a2 + dword_192864 + 33), *(uint8_t *)(313 * a2 + dword_192864 + 34));
    HIDWORD(v14) = 65582;
    LOWORD(v15) = (v35 & 2) != 0;
    WORD1(v15) = v35 & 1;
    WORD2(v15) = v31;
    HIDWORD(v12) = 0;
    HIWORD(v15) = v30;
    DWORD2(v12) = (char *)&v14 + 4;
    v11 = 313 * a2;
    LOWORD(v16) = 0;
    BYTE2(v16) = 0;
    DWORD1(v12) = (int16_t)(20 * (*(uint8_t *)(dword_192864 + v11 + 34) - word_1998F2));
    LODWORD(v12) = (int16_t)(20 * (*(uint8_t *)(dword_192864 + v11 + 33) - word_1998F0));
    sub_A8197(
      (int16_t)v14,
      (int16_t)(20 * (*(uint8_t *)(dword_192864 + 313 * (int16_t)v14 + 33) - word_1998F0)),
      a2,
      (int16_t)(20 * (*(uint8_t *)(dword_192864 + 313 * (int16_t)v14 + 34) - word_1998F2)),
      v12,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27);
  }
  if ( (_WORD)v34 )
    sub_39E15(
      a2,
      20 * *(uint8_t *)(dword_192864 + 313 * a2 + 33),
      20 * *(uint8_t *)(dword_192864 + 313 * a2 + 34),
      v34);
  *(_WORD *)(313 * (int16_t)v14 + dword_192864 + 69) = 0;
  JUMPOUT(0x3B071);
}
// 3B32D: control flows out of bounds to 3B071
// 3B0FA: variable 'v6' is possibly undefined
// 192864: using guessed type int dword_192864;
// 199224: using guessed type int16_t word_199224[15];
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F6: using guessed type int16_t word_1998F6;


//----- (0003B332) --------------------------------------------------------
int __fastcall sub_3B332( int a1, int a2, int a3)
{
  int16_t v4; // ax
  int16_t i; // bx
  int result; // eax
  int16_t v7; // [esp+0h] [ebp-Ch]
  int16_t v8; // [esp+4h] [ebp-8h]

  if ( a3 )
  {
    sub_3BB50(a2);
    v4 = sub_28836(a1, a2);
  }
  else
  {
    sub_2885A(a1, a2);
  }
  v7 = v4;
  v8 = 0;
  for ( i = 0; i < 39; ++i )
  {
    if ( i == 10 && !a3 && v7 < 8 && *(int16_t *)(dword_192864 + 313 * a1 + 69) > 0 && sub_3AFE5(a1, v8) )
      sub_3B077(a1, a2);
    result = sub_1276F0(dword_192864 + 313 * a1 + 76, i);
    if ( (_WORD)result )
      ++v8;
  }
  return result;
}
// 3B36C: variable 'v4' is possibly undefined
// 192864: using guessed type int dword_192864;


//----- (0003B3ED) --------------------------------------------------------
int __fastcall sub_3B3ED( int a1, int a2, int a3)
{
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int16_t *v7; // esi
  int16_t v8; // di
  int v9; // edx
  int16_t v11; // [esp+0h] [ebp-18h]
  int v12; // [esp+8h] [ebp-10h] BYREF
  int v13; // [esp+Ch] [ebp-Ch] BYREF
  int v14; // [esp+10h] [ebp-8h]
  int v15; // [esp+14h] [ebp-4h]

  v15 = a3;
  v3 = 313 * a1 + dword_192864;
  v4 = 51 - (*(uint8_t *)(v3 + 37) + 1) / 2;
  if ( *(_BYTE *)(v3 + 37) == 4 )
    LOWORD(v4) = v4 - 1;
  v5 = sub_127C27((int)aCmbtsfxLbx, (int16_t)v4, dword_193174);
  v6 = v5;
  v7 = (int16_t *)v5;
  LOWORD(v5) = *(_WORD *)(v5 + 6);
  v14 = v5;
  sub_49ED1(v11, &v12, &v13);
  v15 += v13;
  v8 = v12 + a2;
  if ( v11 == word_1998FC )
    v9 = 1;
  else
    v9 = (v11 + word_19987A / 2) % (int16_t)v14;
  sub_12B753(v6, v9);
  return sub_12A478(v8 - *v7 / 2, v15 - v7[1] / 2, (int)v7);
}
// 3B44E: variable 'v11' is possibly undefined
// 192864: using guessed type int dword_192864;
// 193174: using guessed type int dword_193174;
// 19987A: using guessed type int16_t word_19987A;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (0003B4C0) --------------------------------------------------------
_BYTE *__fastcall sub_3B4C0( int a1, int a2, int a3)
{
  int v4; // ecx
  int *v5; // edx
  int v6; // eax
  _WORD *v7; // esi
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int16_t v13; // [esp+0h] [ebp-1Ch] BYREF
  int16_t v14; // [esp+4h] [ebp-18h] BYREF
  int16_t v15; // [esp+8h] [ebp-14h] BYREF
  int v16; // [esp+Ch] [ebp-10h] BYREF
  int v17; // [esp+10h] [ebp-Ch] BYREF
  int16_t v18; // [esp+14h] [ebp-8h] BYREF
  int v19; // [esp+18h] [ebp-4h]

  v19 = a3;
  v4 = 313 * a1;
  v5 = &v16;
  sub_49ED1(a1, &v16, &v17);
  HIWORD(v6) = HIWORD(dword_192864);
  LOWORD(v5) = *(uint8_t *)(v4 + dword_192864 + 33) - word_1998F0;
  v16 += a2 + 20 * (_DWORD)v5;
  LOWORD(v6) = *(uint8_t *)(v4 + dword_192864 + 34) - word_1998F2;
  v17 += 20 * v6 + v19;
  sub_1112EC(dword_192ED4, v17);
  sub_110D3C(dword_192ED4, 22500);
  v7 = sub_110D3C(dword_192ED4, 22500);
  v8 = sub_127C27((int)aCmbtsfxLbx, 46 - (*(uint8_t *)(v4 + dword_192864 + 37) + 1) / 2, dword_193174);
  if ( *(_BYTE *)(v4 + dword_192864 + 310) == 1 )
  {
    v9 = word_19987A / 2 % 8;
    v10 = v8;
  }
  else
  {
    v10 = v8;
    v9 = word_19987A / 2 % 8 + 8;
  }
  sub_12B753(v10, v9);
  sub_12F578((int)v7, v8);
  sub_1320E9((_BYTE *)dword_1928DC);
  sub_12DAFC((int)v7);
  sub_131528(v7, &v18, &v13, &v15, &v14);
  v11 = (int16_t)(v17 - v14 / 2);
  sub_12A478(v16 - v15 / 2, v11, (int)v7);
  sub_1113CC(dword_192ED4, v11);
  return sub_1320E9((_BYTE *)dword_192950);
}
// 192864: using guessed type int dword_192864;
// 1928DC: using guessed type int dword_1928DC;
// 192950: using guessed type int dword_192950;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 19987A: using guessed type int16_t word_19987A;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;


//----- (0003B627) --------------------------------------------------------
void __fastcall sub_3B627( int a1, int a2)
{
  int v2; // edi
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int16_t v7; // si
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v13; // [esp+8h] [ebp-20h]
  _DWORD *v14; // [esp+Ch] [ebp-1Ch]
  int v15; // [esp+10h] [ebp-18h] BYREF
  int v16; // [esp+14h] [ebp-14h] BYREF
  int v17; // [esp+18h] [ebp-10h] BYREF
  int v18; // [esp+1Ch] [ebp-Ch]
  int v19; // [esp+20h] [ebp-8h] BYREF
  int v20; // [esp+24h] [ebp-4h]

  if ( word_1998F6 && !word_1998E0 )
  {
    v2 = sub_127C27((int)aCmbtsfxLbx, 47, dword_193174);
    v3 = sub_12B79D(v2);
    LOWORD(v3) = *(_WORD *)(v2 + 6);
    v18 = v3;
    sub_49ED1(a1, &v16, &v15);
    HIWORD(v4) = HIWORD(dword_192864);
    v5 = dword_192864 + 313 * a1;
    LOWORD(v4) = *(uint8_t *)(v5 + 33) - word_1998F0;
    v16 += 20 * v4;
    LOWORD(v5) = *(uint8_t *)(v5 + 34) - word_1998F2;
    v15 += 20 * v5;
    sub_49ED1(a2, &v17, &v19);
    HIWORD(v4) = HIWORD(dword_192864);
    v6 = dword_192864 + 313 * a2;
    LOWORD(v4) = *(uint8_t *)(v6 + 33) - word_1998F0;
    v17 += 20 * v4;
    LOWORD(v6) = *(uint8_t *)(v6 + 34) - word_1998F2;
    v19 += 20 * v6;
    v19 = (int16_t)v19 - *(int16_t *)(v2 + 2) / 2;
    if ( word_19987E == 1 || word_1998CE )
      v20 = 2;
    else
      v20 = 1;
    sub_1112EC(dword_192ED4, 50000);
    v14 = sub_110D3C(dword_192ED4, 50000);
    v7 = 0;
    v13 = sub_147D7(10);
    while ( v7 < 12 )
    {
      sub_12C2A0();
      sub_124D41();
      sub_12B753(v2, v7 % (int16_t)v18);
      v2 = sub_127C27((int)aCmbtsfxLbx, 47, dword_193174);
      sub_12F578((int)v14, v2);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      sub_130098((int16_t)v16, (int16_t)v15, (int16_t)v17, (int16_t)v19, (int)v14);
      sub_128BE7();
      sub_12B65C();
      v9 = sub_2F4EE(v8);
      sub_1077D(v9);
      v7 += v20;
      sub_12C2C6(1);
    }
    word_1998FC = -1;
    sub_112C96(v13, 10);
    sub_1113CC(dword_192ED4, 10);
  }
  v10 = 313 * a2 + dword_192864;
  *(_BYTE *)(v10 + 310) = 1;
  *(_BYTE *)(v10 + 311) = a1;
  JUMPOUT(0x3B071);
}
// 3B838: control flows out of bounds to 3B071
// 3B7D6: variable 'v8' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 192864: using guessed type int dword_192864;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 19987E: using guessed type int16_t word_19987E;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F6: using guessed type int16_t word_1998F6;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (0003BB3D) --------------------------------------------------------
int16_t __fastcall sub_3BB3D( int a1)
{
  return *(_WORD *)(26 * a1 + dword_192B14 + 2);
}
// 192B14: using guessed type int dword_192B14;


//----- (0003BB50) --------------------------------------------------------
int __fastcall sub_3BB50( int a1)
{
  uint16_t v1; // ax
  int v2; // edx

  v1 = *(_WORD *)(dword_192B14 + 26 * a1);
  v2 = 0;
  if ( v1 < 0x13u )
  {
    if ( v1 < 0x10u )
    {
      if ( v1 <= 0xEu )
        return v2;
      return 1;
    }
    if ( v1 <= 0x10u )
      return 2;
    if ( v1 > 0x11u )
      return 4;
    return 3;
  }
  if ( v1 <= 0x13u )
    return 5;
  if ( v1 < 0x1Du )
  {
    if ( v1 <= 0x14u )
      return 6;
    if ( v1 != 28 )
      return 0;
    return 3;
  }
  if ( v1 <= 0x1Du )
    return 1;
  if ( v1 < 0x1Fu )
    return 2;
  if ( v1 > 0x1Fu )
  {
    if ( v1 != 40 )
      return 0;
    return 6;
  }
  return v2;
}
// 192B14: using guessed type int dword_192B14;


//----- (0003BBF6) --------------------------------------------------------
int __fastcall sub_3BBF6( int a1, int a2, int a3, int a4, unsigned int a5, _WORD *a6, _WORD *a7)
{
  int16_t v7; // si
  int16_t v8; // di
  int16_t v9; // ax
  int16_t v10; // ax
  int result; // eax
  int16_t v12; // ax
  int16_t v13; // ax

  v7 = a4 - a2;
  v8 = a3 - a1;
  if ( abs16(a3 - a1) >= (int)abs16(a4 - a2) )
  {
    if ( v8 >= 0 )
      v12 = 1;
    else
      v12 = -1;
    v13 = a5 * v12;
    *a6 = v13;
    result = v7 * v13 / v8;
    *a7 = result;
  }
  else
  {
    if ( v7 >= 0 )
      v9 = 1;
    else
      v9 = -1;
    v10 = a5 * v9;
    *a7 = v10;
    result = v8 * v10 / v7;
    *a6 = result;
  }
  return result;
}


//----- (0003BC80) --------------------------------------------------------
void __fastcall sub_3BC80( int a1)
{
  int16_t i; // dx
  int v3; // eax

  memset(26 * a1 + dword_192B14, 0, 26);
  for ( i = 0; i < 300; ++i )
  {
    v3 = dword_192B14 + 26 * i;
    if ( a1 == *(_WORD *)(v3 + 6) && *(_BYTE *)(v3 + 8) == 1 )
      sub_3DDD8(i);
  }
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B14: using guessed type int dword_192B14;


//----- (0003BCCD) --------------------------------------------------------
_BOOL1 __fastcall sub_3BCCD( int a1, int a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  int v6; // eax

  v3 = 26 * a1 + dword_192B14;
  v4 = (a3 - *(int16_t *)(v3 + 11)) * (a3 - *(int16_t *)(v3 + 11))
     + (a2 - *(int16_t *)(v3 + 9)) * (a2 - *(int16_t *)(v3 + 9));
  if ( *(_BYTE *)(v3 + 8) == 1 )
  {
    v5 = 64;
  }
  else
  {
    v6 = word_17D881[*(uint8_t *)(313 * *(int16_t *)(v3 + 6) + dword_192864 + 37)];
    v5 = v6 * v6;
  }
  return v4 < v5;
}
// 17D881: using guessed type int16_t word_17D881[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (0003BD2C) --------------------------------------------------------
int __fastcall sub_3BD2C( int a1)
{
  int16_t *v1; // eax
  uint16_t v2; // bx
  int v3; // edx
  int v5; // eax
  int v6; // eax

  v1 = (int16_t *)(dword_192B14 + 26 * a1);
  v2 = (uint8_t)byte_17F80F[28 * *v1];
  v3 = 1;
  if ( v2 >= 2u )
  {
    if ( v2 > 2u )
    {
      if ( v2 != 4 )
        return 1;
      if ( *(int16_t *)((char *)v1 + 15) >= 9 )
        return *(int16_t *)((char *)v1 + 15);
      return 9;
    }
    v6 = *(int16_t *)((char *)v1 + 15) / 5 + 1;
    v3 = v6;
    if ( (int16_t)v6 > 0 )
    {
      if ( (int16_t)v6 > 4 )
        return 4;
      return v3;
    }
    return 1;
  }
  if ( v2 != 1 )
    return v3;
  v5 = *(int16_t *)((char *)v1 + 15) / 5 + 1;
  v3 = v5;
  if ( (int16_t)v5 <= 0 )
    return 1;
  if ( (int16_t)v5 > 9 )
    return 9;
  return v3;
}
// 192B14: using guessed type int dword_192B14;


//----- (0003BDDA) --------------------------------------------------------
int16_t __fastcall sub_3BDDA( int a1, int a2, _WORD *a3, _WORD *a4)
{
  int16_t v4; // di
  int16_t v5; // kr08_2
  int v6; // edx
  int16_t result; // ax
  int v8; // eax
  int v9; // edx
  int v11; // [esp+8h] [ebp-4h]

  v4 = *(uint8_t *)(dword_192B14 + 26 * a1 + 21);
  memset(a3, 0, 8);
  memset(a4, 0, 8);
  v5 = a2 - 1;
  v6 = dword_192FD8 % 2;
  switch ( a2 )
  {
    case 2:
      if ( v6 == 1 )
      {
        *a3 = word_3BA3D[8 * v4];
        *a4 = word_3BA3F[8 * v4];
        a3[1] = word_3BA45[8 * v4];
        result = word_3BA47[8 * v4];
      }
      else
      {
        *a3 = word_3BA41[8 * v4];
        *a4 = word_3BA43[8 * v4];
        a3[1] = word_3BA49[8 * v4];
        result = word_3BA4B[8 * v4];
      }
      a4[1] = result;
      break;
    case 3:
      if ( v6 == 1 )
      {
        a3[1] = word_3BA3D[8 * v4];
        a4[1] = word_3BA3F[8 * v4];
        a3[2] = word_3BA45[8 * v4];
        result = word_3BA47[8 * v4];
      }
      else
      {
        a3[1] = word_3BA41[8 * v4];
        a4[1] = word_3BA43[8 * v4];
        a3[2] = word_3BA49[8 * v4];
        result = word_3BA4B[8 * v4];
      }
      a4[2] = result;
      break;
    case 4:
      v11 = 0;
      do
      {
        v8 = 16 * v4 + 4 * (int16_t)v11;
        v9 = (int16_t)v11;
        a3[v9] = *(int16_t *)((char *)word_3BA3D + v8);
        ++v11;
        result = *(int16_t *)((char *)word_3BA3F + v8);
        a4[v9] = result;
      }
      while ( (int16_t)v11 < 4 );
      break;
    default:
      result = v5;
      break;
  }
  return result;
}
// 3BA3D: using guessed type int16_t word_3BA3D[];
// 3BA3F: using guessed type int16_t word_3BA3F[];
// 3BA41: using guessed type int16_t word_3BA41[];
// 3BA43: using guessed type int16_t word_3BA43[];
// 3BA45: using guessed type int16_t word_3BA45[];
// 3BA47: using guessed type int16_t word_3BA47[];
// 3BA49: using guessed type int16_t word_3BA49[];
// 3BA4B: using guessed type int16_t word_3BA4B[];
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B14: using guessed type int dword_192B14;
// 192FD8: using guessed type int dword_192FD8;


//----- (0003BF72) --------------------------------------------------------
int16_t __fastcall sub_3BF72( int a1, int a2, _WORD *a3, _WORD *a4)
{
  int16_t v5; // di
  int v6; // ebx
  int16_t result; // ax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // ebx
  int v16; // [esp+8h] [ebp-8h]
  int v17; // [esp+Ch] [ebp-4h]

  v5 = *(uint8_t *)(dword_192B14 + 26 * a1 + 21);
  memset(a3, 0, 18);
  memset(a4, 0, 18);
  switch ( a2 )
  {
    case 2:
      v6 = 16 * v5;
      *a3 = word_3B841[v6] / 2;
      *a4 = word_3B843[v6] / 2;
      a3[1] = word_3B851[v6] / 2;
      result = word_3B853[v6] / 2;
      a4[1] = result;
      break;
    case 3:
      if ( dword_192FD8 % 2 == 1 )
      {
        a3[1] = word_3B849[16 * v5];
        a4[1] = word_3B84B[16 * v5];
        a3[2] = word_3B859[16 * v5];
        result = word_3B85B[16 * v5];
      }
      else
      {
        a3[1] = word_3B841[16 * v5];
        a4[1] = word_3B843[16 * v5];
        a3[2] = word_3B851[16 * v5];
        result = word_3B853[16 * v5];
      }
      a4[2] = result;
      break;
    case 4:
      v8 = 16 * v5;
      *a3 = word_3B841[v8];
      *a4 = word_3B843[v8];
      a3[1] = word_3B849[v8];
      a4[1] = word_3B84B[v8];
      a3[2] = word_3B851[v8];
      a4[2] = word_3B853[v8];
      a3[3] = word_3B859[v8];
      result = word_3B85B[v8];
      a4[3] = result;
      break;
    case 5:
      v9 = 16 * v5;
      a3[1] = word_3B841[v9];
      a4[1] = word_3B843[v9];
      a3[2] = word_3B849[v9];
      a4[2] = word_3B84B[v9];
      a3[3] = word_3B851[v9];
      a4[3] = word_3B853[v9];
      a3[4] = word_3B859[v9];
      result = word_3B85B[v9];
      a4[4] = result;
      break;
    case 6:
      v10 = 16 * v5;
      *a3 = word_3B841[v10];
      *a4 = word_3B843[v10];
      a3[1] = word_3B845[v10];
      a4[1] = word_3B847[v10];
      a3[2] = word_3B849[v10];
      a4[2] = word_3B84B[v10];
      a3[3] = word_3B851[v10];
      a4[3] = word_3B853[v10];
      a3[4] = word_3B855[v10];
      a4[4] = word_3B857[v10];
      a3[5] = word_3B859[v10];
      result = word_3B85B[v10];
      a4[5] = result;
      break;
    case 7:
      v11 = 16 * v5;
      a3[1] = word_3B841[v11];
      a4[1] = word_3B843[v11];
      a3[2] = word_3B845[v11];
      a4[2] = word_3B847[v11];
      a3[3] = word_3B849[v11];
      a4[3] = word_3B84B[v11];
      a3[4] = word_3B851[v11];
      a4[4] = word_3B853[v11];
      a3[5] = word_3B855[v11];
      a4[5] = word_3B857[v11];
      a3[6] = word_3B859[v11];
      result = word_3B85B[v11];
      a4[6] = result;
      break;
    case 8:
      v17 = 0;
      do
      {
        v12 = 4 * (int16_t)v17 + 32 * v5;
        v13 = (int16_t)v17;
        a3[v13] = *(int16_t *)((char *)&word_3B83D + v12);
        ++v17;
        result = *(int16_t *)((char *)&word_3B83F + v12);
        a4[v13] = result;
      }
      while ( (int16_t)v17 < 8 );
      break;
    case 9:
      v16 = 0;
      do
      {
        v14 = 32 * v5 + 4 * (int16_t)v16;
        v15 = (int16_t)v16;
        a3[v15 + 1] = *(int16_t *)((char *)&word_3B83D + v14);
        ++v16;
        result = *(int16_t *)((char *)&word_3B83F + v14);
        a4[v15 + 1] = result;
      }
      while ( (int16_t)v16 < 8 );
      break;
    default:
      result = a2 - 1;
      break;
  }
  return result;
}
// 3B83D: using guessed type int16_t word_3B83D;
// 3B83F: using guessed type int16_t word_3B83F;
// 3B841: using guessed type int16_t word_3B841[];
// 3B843: using guessed type int16_t word_3B843[];
// 3B845: using guessed type int16_t word_3B845[];
// 3B847: using guessed type int16_t word_3B847[];
// 3B849: using guessed type int16_t word_3B849[];
// 3B84B: using guessed type int16_t word_3B84B[];
// 3B851: using guessed type int16_t word_3B851[];
// 3B853: using guessed type int16_t word_3B853[];
// 3B855: using guessed type int16_t word_3B855[];
// 3B857: using guessed type int16_t word_3B857[];
// 3B859: using guessed type int16_t word_3B859[];
// 3B85B: using guessed type int16_t word_3B85B[];
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B14: using guessed type int dword_192B14;
// 192FD8: using guessed type int dword_192FD8;


//----- (0003C2DC) --------------------------------------------------------
void __fastcall sub_3C2DC( int a1, int a2, int a3, int a4)
{
  int v5; // edx
  int v6; // eax
  int16_t v7; // cx
  int16_t *v8; // eax
  int16_t v9; // si
  int16_t *v10; // edx
  int v11; // ecx
  int16_t v12; // cx
  int16_t v13; // di
  int16_t v14; // dx
  int16_t v15; // ax
  int16_t v16; // di
  int v17; // ecx
  int16_t v18; // cx
  int16_t v19; // dx
  int16_t v20; // ax
  _WORD v21[10]; // [esp+0h] [ebp-4Ch] BYREF
  _WORD v22[10]; // [esp+14h] [ebp-38h] BYREF
  int v23; // [esp+28h] [ebp-24h]
  int v24; // [esp+2Ch] [ebp-20h]
  int v25; // [esp+30h] [ebp-1Ch]
  int v26; // [esp+34h] [ebp-18h]
  int v27; // [esp+38h] [ebp-14h]
  int v28; // [esp+3Ch] [ebp-10h]
  int v29; // [esp+40h] [ebp-Ch]
  int v30; // [esp+44h] [ebp-8h]
  int v31; // [esp+48h] [ebp-4h]

  v25 = a2;
  v27 = a3;
  v30 = a4;
  if ( *(int16_t *)(26 * a1 + dword_192B14) > 0 && (sub_3CE4F(a1) || (_WORD)a4) )
  {
    v5 = 26 * a1;
    v6 = sub_3BB50(a1);
    v7 = v6;
    v26 = v6;
    v8 = (int16_t *)(v5 + dword_192B14);
    LOWORD(v5) = *(uint8_t *)(v5 + dword_192B14 + 21);
    v29 = v5;
    if ( byte_17F80F[28 * *v8] != 4 )
    {
      if ( v8[3] == word_1998F8 || *v8 == 19 )
        sub_12B753(dword_18F768[16 * (int16_t)v26 + (int16_t)v29], (a1 + word_19987A) % 3);
      else
        sub_12B726(dword_18F768[16 * v7 + (int16_t)v29]);
    }
    if ( *(_WORD *)(dword_192B14 + 26 * a1 + 6) != word_1998F8 || word_199904 == 1 )
    {
      v9 = a1;
      v10 = (int16_t *)(26 * a1 + dword_192B14);
      if ( byte_17F80F[28 * *v10] == 4 )
      {
        sub_3DBD1(a1, (int16_t)v25, (int16_t)v27, (int16_t)v30);
      }
      else
      {
        if ( byte_17F80F[28 * *v10] == 1 || *v10 == 18 )
        {
          v24 = sub_3BD2C(a1);
          sub_3BF72(a1, v24, v22, v21);
          if ( (_WORD)v30 == 1 )
            v11 = 479;
          else
            v11 = 350;
          sub_128AB6(0, 0, 639, v11);
          sub_12B634();
          v12 = 0;
          v13 = v25 - 12;
          v28 = v27 - 12;
          while ( v12 < (int16_t)v24 )
          {
            v14 = v21[v12] + v28;
            v15 = v13 + v22[v12++];
            sub_12A478(v15, v14, dword_18F768[16 * (int16_t)v26 + (int16_t)v29]);
          }
        }
        else
        {
          v16 = sub_3BD2C(a1);
          sub_3BDDA(v9, v16, v22, v21);
          if ( (_WORD)v30 == 1 )
            v17 = 479;
          else
            v17 = 350;
          sub_128AB6(0, 0, 639, v17);
          sub_12B634();
          v31 = v27 - 23;
          v18 = 0;
          v23 = v25 - 23;
          while ( v18 < v16 )
          {
            v19 = v21[v18] + v31;
            v20 = v22[v18++] + v23;
            sub_12A478(v20, v19, dword_18F768[16 * (int16_t)v26 + (int16_t)v29]);
          }
        }
        sub_12B65C();
        sub_128BE7();
      }
    }
  }
}
// 18F768: using guessed type int dword_18F768[112];
// 192B14: using guessed type int dword_192B14;
// 19987A: using guessed type int16_t word_19987A;
// 1998F8: using guessed type int16_t word_1998F8;
// 199904: using guessed type int16_t word_199904;


//----- (0003C539) --------------------------------------------------------
int __cdecl sub_3C539(
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
        int a23,
        int a24,
        int a25,
        int a26,
        int64_t a27)
{
  int v27; // eax
  int v28; // esi
  char *v29; // esi
  char *v30; // edi
  int v31; // ecx
  _WORD *v32; // esi
  int v33; // eax
  char *v34; // edi
  char *v35; // esi
  char *v36; // edi
  char *v37; // edi
  char *v38; // edi
  char *v39; // edi
  int16_t v41; // [esp+76h] [ebp-6h]
  int16_t v42; // [esp+7Ah] [ebp-2h]
  int16_t vars2; // [esp+7Eh] [ebp+2h]
  char vars6[10]; // [esp+82h] [ebp+6h] BYREF

  sub_128C32(401, 379, 488, 467, 0);
  v27 = sub_127C27((int)aCombatLbx_1, 45, dword_193174);
  sub_12A478(401, 379, v27);
  *(_DWORD *)((char *)&a27 + 2) = v41;
  sub_3C2DC(v41, (int16_t)(vars2 + 44), (int16_t)(v42 + 44), 1);
  sub_120BB5(0, (int)&unk_17D879);
  sub_58F1E(52, vars6, 80);
  strcpy((char *)&a17 + 2, vars6);
  v28 = dword_192B14 + 26 * *(_DWORD *)((char *)&a27 + 2);
  if ( *(_BYTE *)(v28 + 8) )
    v29 = (char *)*(&off_17F803 + 7 * *(int16_t *)(26 * *(int16_t *)(v28 + 6) + dword_192B14));
  else
    v29 = (char *)(313 * *(int16_t *)(v28 + 6) + dword_192864);
  v30 = (char *)&a17 + 1;
  do
    ++v30;
  while ( *v30 );
  strcpy(v30, v29);
  v31 = 26 * v41;
  sub_1210FD(vars2 + 43, v42 + 2, (int)&a17 + 2);
  itoa(*(int16_t *)(v31 + dword_192B14 + 15), (char *)&a17 + 2, 10, v31);
  v32 = (_WORD *)(v31 + dword_192B14);
  if ( byte_17F80F[28 * *(int16_t *)(v31 + dword_192B14)] == 1 )
  {
    if ( *(_WORD *)((char *)v32 + 15) == 1 )
      v33 = 53;
    else
      v33 = 107;
LABEL_37:
    sub_58F1E(v33, vars6, 80);
    v35 = vars6;
    goto LABEL_38;
  }
  if ( byte_17F80F[28 * *(int16_t *)(v31 + dword_192B14)] != 4 )
  {
    if ( *(_WORD *)((char *)v32 + 15) == 1 )
      v33 = 54;
    else
      v33 = 108;
    goto LABEL_37;
  }
  switch ( *v32 )
  {
    case 0x1E:
      v34 = (char *)&a17 + 1;
      do
        ++v34;
      while ( *v34 );
      strcpy(v34, asc_178D8B);
      if ( *(_WORD *)(v31 + dword_192B14 + 15) == 1 )
        v35 = (char *)off_17FB4B;
      else
        v35 = (char *)off_17FB4F;
      break;
    case 0x1F:
      v36 = (char *)&a17 + 1;
      do
        ++v36;
      while ( *v36 );
      strcpy(v36, asc_178D8B);
      if ( *(_WORD *)(v31 + dword_192B14 + 15) == 1 )
        v35 = (char *)off_17FB67;
      else
        v35 = (char *)off_17FB6B;
      break;
    case 0x1D:
      v37 = (char *)&a17 + 1;
      do
        ++v37;
      while ( *v37 );
      strcpy(v37, asc_178D8B);
      if ( *(_WORD *)(v31 + dword_192B14 + 15) == 1 )
        v35 = (char *)off_17FB2F;
      else
        v35 = (char *)off_17FB33;
      break;
    default:
      v38 = (char *)&a17 + 1;
      do
        ++v38;
      while ( *v38 );
      strcpy(v38, asc_178D8B);
      if ( *(_WORD *)(v31 + dword_192B14 + 15) == 1 )
        v35 = (char *)off_17FB13;
      else
        v35 = (char *)off_17FB17;
      break;
  }
LABEL_38:
  v39 = (char *)&a17 + 1;
  do
    ++v39;
  while ( *v39 );
  strcpy(v39, v35);
  return sub_1210FD(vars2 + 43, v42 + 81, (int)&a17 + 2);
}
// 3C5AC: variable 'v41' is possibly undefined
// 3C598: variable 'vars2' is possibly undefined
// 3C58D: variable 'v42' is possibly undefined
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 17F803: using guessed type _UNKNOWN *off_17F803;
// 17FB13: using guessed type _UNKNOWN *off_17FB13;
// 17FB17: using guessed type _UNKNOWN *off_17FB17;
// 17FB2F: using guessed type _UNKNOWN *off_17FB2F;
// 17FB33: using guessed type _UNKNOWN *off_17FB33;
// 17FB4B: using guessed type _UNKNOWN *off_17FB4B;
// 17FB4F: using guessed type _UNKNOWN *off_17FB4F;
// 17FB67: using guessed type _UNKNOWN *off_17FB67;
// 17FB6B: using guessed type _UNKNOWN *off_17FB6B;
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 193174: using guessed type int dword_193174;


//----- (0003C834) --------------------------------------------------------
void sub_3C834()
{
  int16_t i; // si
  int v1; // eax
  int16_t v2; // bx
  int v3; // edx

  for ( i = 299; i >= 0; --i )
  {
    v1 = 26 * i + dword_192B14;
    v2 = *(_WORD *)(v1 + 11) - 20 * word_1998F2;
    v3 = (int16_t)(*(_WORD *)(v1 + 9) - 20 * word_1998F0);
    LOWORD(v1) = i;
    sub_3C2DC(v1, v3, v2, 0);
  }
}
// 192B14: using guessed type int dword_192B14;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;


//----- (0003C892) --------------------------------------------------------
void __fastcall sub_3C892(int a1, int a2, int a3, int a4)
{
  int v5; // edx
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int *v10; // edx
  int v11; // eax
  int v12; // ebx
  char v13; // al
  int v14; // edx
  int v15; // eax
  int16_t *v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  _WORD *v22; // eax
  int16_t i; // si
  int v24; // eax
  int v25; // edx
  int16_t v26; // [esp+0h] [ebp-2Ch]
  int16_t v27; // [esp+2h] [ebp-2Ah]
  int v28; // [esp+8h] [ebp-24h]
  int v29; // [esp+Ch] [ebp-20h]
  int v30; // [esp+10h] [ebp-1Ch] BYREF
  int v31; // [esp+14h] [ebp-18h] BYREF
  int v32; // [esp+18h] [ebp-14h] BYREF
  int v33; // [esp+1Ch] [ebp-10h] BYREF
  int16_t v34; // [esp+20h] [ebp-Ch] BYREF
  int v35; // [esp+24h] [ebp-8h]
  int v36; // [esp+28h] [ebp-4h]

  v35 = a3;
  sub_3D21D(&v34);
  if ( v34 != -1 )
  {
    memset(dword_192B14 + 26 * v34, 0, 26);
    v5 = dword_192B14;
    HIWORD(v6) = v27;
    *(_WORD *)(dword_192B14 + 26 * v34 + 4) = v26;
    *(_WORD *)(v5 + 26 * v34 + 13) = 0;
    v29 = 313 * v26;
    v7 = v29 + dword_192864;
    LOWORD(v6) = *(uint8_t *)(v29 + dword_192864 + 32);
    v36 = v6;
    *(_WORD *)(v5 + 26 * v34 + 2) = v6;
    v8 = 11 * (int16_t)v35 + v7;
    v9 = 26 * v34;
    *(_WORD *)(v5 + v9) = *(_WORD *)(v8 + 82);
    LOWORD(v9) = *(uint8_t *)(v8 + 84);
    v36 = v9;
    *(_WORD *)(v5 + 26 * v34 + 15) = v9;
    *(_WORD *)(v5 + 26 * v34 + 17) = *(_WORD *)(v8 + 86);
    *(_WORD *)(v5 + 26 * v34 + 6) = a2;
    v10 = &v32;
    sub_49ED1(v26, &v32, &v30);
    v11 = v29 + dword_192864;
    LOWORD(v10) = *(uint8_t *)(v29 + dword_192864 + 33);
    v36 = 20 * (_DWORD)v10 + v32;
    v12 = dword_192B14;
    *(_WORD *)(26 * v34 + dword_192B14 + 9) = v36;
    *(_WORD *)(v12 + 26 * v34 + 11) = 20 * *(uint8_t *)(v11 + 34) + v30;
    v13 = sub_3CC9C(v34, a2, a4);
    v14 = dword_192B14;
    *(_BYTE *)(dword_192B14 + 26 * v34 + 21) = v13;
    if ( word_17D853 )
      *(_BYTE *)(v14 + 26 * v34 + 23) = -1;
    else
      *(_BYTE *)(v14 + 26 * v34 + 23) = 0;
    v28 = 313 * v26;
    LOWORD(v36) = sub_3CD21(
                    *(_WORD *)(dword_192B14 + 26 * v34),
                    HIBYTE(*(_WORD *)(dword_192B14 + 26 * v34 + 17)),
                    *(uint8_t *)(v28 + dword_192864 + 32));
    v15 = dword_192B14;
    *(_BYTE *)(26 * v34 + dword_192B14 + 22) = v36;
    *(_WORD *)(26 * v34 + v15 + 19) = 20 * *(uint8_t *)(26 * v34 + v15 + 22);
    *(_BYTE *)(26 * v34 + v15 + 25) = 1;
    *(_BYTE *)(26 * v34 + v15 + 8) = a4;
    v16 = (int16_t *)(v15 + 26 * v34);
    if ( byte_17F80F[28 * *v16] == 4 )
    {
      *(int16_t *)((char *)v16 + 15) = 4 * *(uint8_t *)(dword_192864 + v28 + 11 * (int16_t)v35 + 84);
      v17 = 26 * v34 + v15;
      switch ( *(_WORD *)v17 )
      {
        case 0x1C:
        case 0x1E:
          *(_BYTE *)(26 * v34 + dword_192B14 + 23) = 1;
          break;
        case 0x1D:
          *(_BYTE *)(v17 + 23) = 2;
          break;
        case 0x1F:
          *(_BYTE *)(v17 + 23) = 4;
          break;
        default:
          break;
      }
    }
    if ( a4 )
    {
      v20 = 26 * a2;
      v21 = v20 + dword_192B14;
      LOWORD(v20) = *(_WORD *)(v20 + dword_192B14 + 9);
      v31 = v20;
      LOWORD(v20) = *(_WORD *)(v21 + 11);
      v33 = v20;
    }
    else
    {
      sub_49ED1(a2, &v31, &v33);
      HIWORD(v18) = HIWORD(dword_192864);
      v19 = dword_192864 + 313 * a2;
      LOWORD(v18) = *(uint8_t *)(v19 + 33);
      v31 += 20 * v18;
      LOWORD(v19) = *(uint8_t *)(v19 + 34);
      v33 += 20 * v19;
    }
    if ( word_1998F6 != 1 || word_1998E0 && ((v22 = (_WORD *)(26 * v34 + dword_192B14), *v22 == 19) || *v22 == 40) )
      sub_3D2DF(v34, (int16_t)v31, (int16_t)v33);
    else
      sub_AF37E(v34, v31, v33, a4);
    if ( *(int16_t *)(dword_192B14 + 26 * v34) > 0 )
    {
      for ( i = 0; i < 300; ++i )
      {
        v24 = dword_192B14 + 26 * i;
        v25 = 26 * v34 + dword_192B14;
        if ( *(_WORD *)v24 == *(_WORD *)v25
          && *(_WORD *)(v24 + 17) == *(_WORD *)(v25 + 17)
          && *(_WORD *)(v24 + 6) == *(_WORD *)(v25 + 6)
          && *(_WORD *)(v24 + 9) == *(_WORD *)(v25 + 9)
          && *(_WORD *)(v24 + 11) == *(_WORD *)(v25 + 11)
          && *(_BYTE *)(v24 + 8) == *(_BYTE *)(v25 + 8)
          && i != v34 )
        {
          *(_WORD *)(v24 + 15) += *(_WORD *)(v25 + 15);
          sub_3BC80(v34);
        }
      }
    }
  }
}
// 3C8D7: variable 'v27' is possibly undefined
// 3C8DA: variable 'v26' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17D853: using guessed type int16_t word_17D853;
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F6: using guessed type int16_t word_1998F6;


//----- (0003CC24) --------------------------------------------------------
char *__fastcall sub_3CC24(int16_t *a1, _WORD *a2, int a3, int a4, unsigned int a5)
{
  _WORD *v6; // esi
  char *result; // eax
  int16_t v8; // [esp+0h] [ebp-10h]
  int v9; // [esp+8h] [ebp-8h] BYREF
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v6 = a2;
  v8 = *a1;
  LOWORD(a2) = *a2;
  sub_3BBF6(*a1, (int16_t)a2, a3, a4, a5, &v9, &v10);
  *a1 = v9 + v8;
  result = (char *)a2 + v10;
  *v6 = v10 + (_WORD)a2;
  return result;
}


//----- (0003CC9C) --------------------------------------------------------
int __fastcall sub_3CC9C( int a1, int a2, int a3)
{
  int v4; // eax
  int16_t v5; // dx
  int16_t v6; // bx
  int v7; // eax
  int v9; // [esp+0h] [ebp-8h] BYREF
  int v10; // [esp+4h] [ebp-4h] BYREF

  if ( a3 )
  {
    v4 = 26 * a2 + dword_192B14;
    v5 = *(_WORD *)(v4 + 9);
    v6 = *(_WORD *)(v4 + 11);
  }
  else
  {
    sub_49ED1(a2, &v9, &v10);
    v7 = dword_192864 + 313 * a2;
    v5 = v9 + 20 * *(uint8_t *)(v7 + 33);
    v6 = 20 * *(uint8_t *)(v7 + 34) + v10;
  }
  return sub_3F5F1(*(_WORD *)(dword_192B14 + 26 * a1 + 9), *(_WORD *)(dword_192B14 + 26 * a1 + 11), v5, v6);
}
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (0003CD21) --------------------------------------------------------
int __usercall sub_3CD21( unsigned int a1, int a2, int a3)
{
  int16_t v3; // cx
  int v4; // edx
  _BOOL1 v5; // zf
  int v6; // eax
  int v7; // esi

  v3 = 1;
  v4 = 0;
  if ( a1 < 0x1Cu )
  {
    if ( a1 >= 0x12u )
    {
      if ( a1 <= 0x13u )
      {
        v4 = 20;
        goto LABEL_15;
      }
      v5 = a1 == 20;
LABEL_7:
      if ( !v5 )
        goto LABEL_29;
      v4 = 24;
LABEL_15:
      v3 = 0;
      goto LABEL_29;
    }
    if ( a1 < 0xEu )
      goto LABEL_29;
LABEL_20:
    v4 = 12;
    goto LABEL_29;
  }
  if ( a1 <= 0x1Cu )
  {
    v4 = 6;
    if ( a3 < 8 && *(_BYTE *)(dword_197F98 + 3753 * a3 + 2236) )
      v4 = 10;
    goto LABEL_29;
  }
  if ( a1 < 0x1Eu )
  {
    v4 = 8;
    if ( a3 >= 8 )
      goto LABEL_29;
    v7 = 3753 * a3;
    v6 = dword_197F98;
    goto LABEL_19;
  }
  if ( a1 <= 0x1Eu )
  {
    v4 = 8;
    if ( a3 >= 8 )
      goto LABEL_29;
    v6 = 3753 * a3;
    v7 = dword_197F98;
LABEL_19:
    if ( !*(_BYTE *)(v7 + v6 + 2236) )
      goto LABEL_29;
    goto LABEL_20;
  }
  if ( a1 > 0x1Fu )
  {
    v5 = a1 == 40;
    goto LABEL_7;
  }
  v4 = 10;
  if ( a3 < 8 && *(_BYTE *)(3753 * a3 + dword_197F98 + 2236) )
    v4 = 14;
LABEL_29:
  if ( v3 )
    v4 += 2 * (sub_56726(a3) - 1);
  if ( (a2 & 0x10) != 0 )
    v4 += 4;
  return v4;
}
// 197F98: using guessed type int dword_197F98;


//----- (0003CE4F) --------------------------------------------------------
_BOOL1 __fastcall sub_3CE4F( int a1)
{
  int v1; // ebx
  int16_t v2; // cx
  int16_t v3; // ax

  v1 = dword_192B14 + 26 * a1;
  v2 = *(int16_t *)(v1 + 9) / 20;
  v3 = *(int16_t *)(v1 + 11) / 20;
  return v2 >= word_1998F0 && v2 < word_1998F0 + 32 && v3 >= word_1998F2 && v3 < word_1998F2 + 18;
}
// 192B14: using guessed type int dword_192B14;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;


//----- (0003CEB7) --------------------------------------------------------
char __fastcall sub_3CEB7( int a1, int a2, int a3, int a4)
{
  int v5; // edi
  int16_t *v6; // eax
  int v7; // eax
  int16_t *v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int16_t v16; // cx
  int v17; // eax
  _WORD *v18; // eax
  int v19; // ecx
  int16_t v20; // di
  int16_t v21; // ax
  int16_t v22; // di
  int v23; // eax
  int16_t v24; // dx
  int16_t v25; // cx
  int16_t v26; // dx
  int16_t *v27; // ebx
  int v28; // eax
  int16_t v29; // di
  int v30; // eax
  int v31; // [esp+0h] [ebp-28h]
  int v32; // [esp+0h] [ebp-28h]
  int v33; // [esp+4h] [ebp-24h]
  int v34; // [esp+8h] [ebp-20h]
  int v35; // [esp+10h] [ebp-18h] BYREF
  int v36; // [esp+14h] [ebp-14h]
  int v37; // [esp+18h] [ebp-10h]
  int v38; // [esp+1Ch] [ebp-Ch]
  int v39; // [esp+20h] [ebp-8h] BYREF
  _BOOL1 v40; // [esp+24h] [ebp-4h]

  LOWORD(v5) = a2;
  v37 = a3;
  LOWORD(v38) = a4;
  v6 = (int16_t *)(26 * a1 + dword_192B14);
  if ( byte_17F80F[28 * *v6] == 4 && !*((_BYTE *)v6 + 8) )
    v5 = word_17D881[*(uint8_t *)(dword_192864 + 313 * v6[3] + 37)] / 2 + a2;
  v7 = 26 * a1 + dword_192B14;
  if ( (_WORD)v5 == *(_WORD *)(v7 + 9) && (_WORD)v37 == *(_WORD *)(v7 + 11) )
    return 1;
  v9 = (int16_t *)(dword_192B14 + 26 * a1);
  v40 = 0;
  if ( *v9 > 0 )
  {
    if ( *(int16_t *)((char *)v9 + 19) < (int16_t)v38 )
      LOWORD(v38) = *(int16_t *)((char *)v9 + 19);
    v31 = 26 * a1;
    sub_3BBF6(*(_WORD *)(v31 + dword_192B14 + 9), *(_WORD *)(v31 + dword_192B14 + 11), v5, v37, v38, &v39, &v35);
    v10 = v31 + dword_192B14;
    *(_WORD *)(v10 + 9) += v39;
    v36 = 0;
    *(_WORD *)(v10 + 11) += v35;
    do
    {
      v33 = (int16_t)v36;
      v11 = dword_192B14 + 26 * (int16_t)v36;
      if ( *(int16_t *)v11 > 0 && *(_BYTE *)(v11 + 8) == 1 && a1 == *(_WORD *)(v11 + 6) )
      {
        v34 = 26 * a1;
        if ( (uint8_t)sub_3CEB7(
                                (int16_t)v36,
                                *(int16_t *)(dword_192B14 + v34 + 9),
                                *(int16_t *)(dword_192B14 + v34 + 11),
                                (int16_t)v38) )
          sub_3D2DF(v33, *(int16_t *)(v34 + dword_192B14 + 9), *(int16_t *)(v34 + dword_192B14 + 11));
      }
      ++v36;
    }
    while ( (int16_t)v36 < 300 );
    if ( (int16_t)v39 > 0 )
    {
      v12 = dword_192B14 + 26 * a1;
      if ( *(int16_t *)(v12 + 9) > (int16_t)v5 - 3 )
        *(_WORD *)(v12 + 9) = v5 - 3;
    }
    if ( (v39 & 0x8000u) != 0 )
    {
      v13 = 26 * a1 + dword_192B14;
      if ( *(int16_t *)(v13 + 9) < (int16_t)v5 + 3 )
        *(_WORD *)(v13 + 9) = v5 + 3;
    }
    if ( (int16_t)v35 > 0 )
    {
      v14 = dword_192B14 + 26 * a1;
      if ( *(int16_t *)(v14 + 11) > (int16_t)v37 - 3 )
        *(_WORD *)(v14 + 11) = v37 - 3;
    }
    if ( (v35 & 0x8000u) != 0 )
    {
      v15 = dword_192B14 + 26 * a1;
      if ( *(int16_t *)(v15 + 11) < (int16_t)v37 + 3 )
        *(_WORD *)(v15 + 11) = v37 + 3;
    }
    v16 = v37;
    v40 = sub_3BCCD(a1, v5, v37);
    v32 = 26 * a1;
    v17 = v32 + dword_192B14;
    *(_WORD *)(v17 + 19) -= v38;
    *(_BYTE *)(v32 + dword_192B14 + 21) = sub_3F5F1(*(_WORD *)(v17 + 9), *(_WORD *)(v17 + 11), v5, v16);
  }
  v18 = (_WORD *)(dword_192B14 + 26 * a1);
  if ( (*v18 == 20 || *v18 == 40) && !v40 )
  {
    v19 = 26 * a1;
    if ( (*(_BYTE *)(v19 + dword_192B14 + 17) & 0x20) == 0 )
    {
      v20 = *(uint8_t *)(v19 + dword_192B14 + 23);
      v21 = sub_3BB3D(a1);
      v22 = 20 * sub_3CD21(*(_WORD *)(v19 + dword_192B14), HIBYTE(*(_WORD *)(v19 + dword_192B14 + 17)), v21) * (v20 + 1);
      v23 = v19 + dword_192B14;
      v24 = *(_WORD *)(v19 + dword_192B14 + 2);
      v25 = v22 - *(_WORD *)(v19 + dword_192B14 + 19);
      v26 = word_199224[v24];
      if ( (*(_BYTE *)(v23 + 18) & 0x40) != 0 )
        v26 += 50;
      v27 = (int16_t *)(26 * a1 + dword_192B14);
      v28 = v26 * word_17F819[14 * *v27] / 100;
      v29 = v28;
      if ( *v27 == 20 )
      {
        v29 = v28;
        v30 = 5 * (v25 / 20);
      }
      else
      {
        v30 = 15 * (v25 / 20);
      }
      if ( (int16_t)(v29 - v30) <= 0 )
        sub_3BC80(a1);
    }
  }
  return v40;
}
// 17D881: using guessed type int16_t word_17D881[];
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 199224: using guessed type int16_t word_199224[15];


//----- (0003D21D) --------------------------------------------------------
int16_t *__fastcall sub_3D21D(int16_t *result)
{
  int16_t v1; // cx
  int16_t i; // dx

  *result = -1;
  v1 = 0;
  for ( i = 0; i < 300 && !v1; ++i )
  {
    if ( !*(_WORD *)(dword_192B14 + 26 * i) )
    {
      v1 = 1;
      *result = i;
    }
  }
  return result;
}
// 192B14: using guessed type int dword_192B14;


//----- (0003D259) --------------------------------------------------------
_BOOL1 __fastcall sub_3D259( int a1, int a2)
{
  return a1 >= word_1998F0 && a1 < word_1998F0 + 32 && a2 >= word_1998F2 && a2 < word_1998F2 + 18;
}
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;


//----- (0003D299) --------------------------------------------------------
int __fastcall sub_3D299( int a1)
{
  int v1; // eax
  int v2; // edx

  v1 = dword_192B14 + 26 * a1;
  v2 = 0;
  if ( *(_BYTE *)(v1 + 8) )
  {
    if ( *(int16_t *)(dword_192B14 + 26 * *(int16_t *)(v1 + 6) + 15) > 0 )
      return 1;
  }
  else if ( !*(_WORD *)(v1 + 6) || !(uint16_t)sub_3897A(*(_WORD *)(v1 + 6)) )
  {
    return 1;
  }
  return v2;
}
// 192B14: using guessed type int dword_192B14;


//----- (0003D2DF) --------------------------------------------------------
int __fastcall sub_3D2DF(int a1, int a2, int a3)
{
  int16_t v4; // di
  int v5; // eax
  int v6; // edx
  int16_t v7; // bx
  int v8; // edx
  int16_t v9; // ax
  int16_t v10; // ax
  int16_t i; // dx
  int v12; // ebx
  int16_t v13; // ax
  int v14; // eax
  int16_t v15; // ax
  _BYTE *v16; // eax
  int v17; // ebx
  int16_t v18; // ax
  int v19; // ecx
  int16_t v20; // ax
  int v21; // edx
  int16_t v22; // ax
  int v23; // eax
  int16_t v24; // cx
  int v25; // edi
  int v26; // eax
  int v27; // edi
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int16_t v31; // di
  int16_t v32; // cx
  int v33; // ecx
  int v34; // eax
  int16_t v35; // bx
  int v36; // eax
  int16_t v37; // dx
  int v39; // [esp+0h] [ebp-6Ch]
  int v40; // [esp+4h] [ebp-68h]
  int v41; // [esp+8h] [ebp-64h]
  int v42; // [esp+Ch] [ebp-60h]
  int v43; // [esp+10h] [ebp-5Ch]
  int v44; // [esp+14h] [ebp-58h] BYREF
  int v45; // [esp+18h] [ebp-54h] BYREF
  int v46; // [esp+1Ch] [ebp-50h] BYREF
  int v47; // [esp+20h] [ebp-4Ch] BYREF
  int v48; // [esp+24h] [ebp-48h]
  int v49; // [esp+28h] [ebp-44h]
  int v50; // [esp+2Ch] [ebp-40h]
  int v51; // [esp+30h] [ebp-3Ch] BYREF
  __int128 v52; // [esp+34h] [ebp-38h]
  __int128 v53; // [esp+44h] [ebp-28h]
  int64_t v54; // [esp+54h] [ebp-18h]
  int64_t v55; // [esp+5Ch] [ebp-10h] BYREF
  int64_t v56; // [esp+64h] [ebp-8h]
  int savedregs[4]; // [esp+6Ch] [ebp+0h]

  DWORD2(v52) = a2;
  HIDWORD(v56) = a3;
  v4 = 0;
  HIWORD(v6) = HIWORD(dword_192B14);
  v50 = 0;
  HIDWORD(v55) = 0;
  *(_QWORD *)((char *)&v53 + 4) = 0;
  v5 = dword_192B14 + 26 * (int16_t)a1;
  v46 = 0;
  LOWORD(v6) = *(_WORD *)(v5 + 2);
  word_1998DA = 0;
  v49 = v6;
  if ( *(_BYTE *)(v5 + 25) == 1 )
  {
    LOWORD(v6) = *(_WORD *)(v5 + 6);
    LODWORD(v54) = v6;
    LOWORD(v53) = *(_WORD *)(v5 + 17);
    LOWORD(v6) = *(_WORD *)v5;
    HIDWORD(v53) = v6;
    LOWORD(v6) = *(uint8_t *)(v5 + 8);
    v7 = *(_WORD *)(v5 + 4);
    LODWORD(v56) = v6;
    if ( v7 == (_WORD)v54 && !(_WORD)v6 )
    {
      LOWORD(v51) = (int)(*(int16_t *)(v5 + 15)
                        - (__CFSHL__((uint64_t)*(int16_t *)(v5 + 15) >> 32, 2)
                         + 4 * ((uint64_t)*(int16_t *)(v5 + 15) >> 32))) >> 2;
      while ( (_WORD)v51 && v4 < 8 )
      {
        v8 = 11 * v4 + dword_192864 + 313 * v7;
        if ( *(_WORD *)(v8 + 82) == WORD6(v53) && !*(_WORD *)(v8 + 88) )
        {
          *(_WORD *)(v8 + 88) = 1;
          *(_BYTE *)(v8 + 91) = 0;
          v9 = *(uint8_t *)(v8 + 84);
          if ( v9 > (int16_t)v51 )
          {
            *(_BYTE *)(v8 + 84) = v51;
            LOWORD(v51) = 0;
          }
          else
          {
            LOWORD(v51) = v51 - v9;
          }
        }
        ++v4;
      }
      goto LABEL_13;
    }
    if ( (uint16_t)sub_3D299(a1) )
    {
      if ( (_WORD)v56 )
        goto LABEL_41;
      if ( sub_4B0D3(v54, 19) )
      {
        for ( i = 0; ; ++i )
        {
          v12 = 26 * (int16_t)a1;
          if ( i >= *(int16_t *)(dword_192B14 + v12 + 15) )
            break;
          if ( (int)sub_1247A0(0x64u) < 50 )
            --*(_WORD *)(v12 + dword_192B14 + 15);
        }
        if ( word_1998F6 == 1 && !word_1998E0 )
          sub_AC472((int16_t)v54, (int16_t)a1, SWORD4(v52), SWORD2(v56));
      }
      v39 = (int16_t)a1;
      sub_36C9C(v54, SWORD4(v52), SWORD2(v56), (int16_t)a1);
      v40 = *(uint8_t *)(313 * (int16_t)v54 + dword_192864 + 35);
      v42 = 26 * v39;
      v13 = sub_329A4(v54, *(_WORD *)(26 * v39 + dword_192B14 + 9), *(_WORD *)(26 * v39 + dword_192B14 + 11));
      v48 = 0;
      HIDWORD(v55) = (v40 + (2 * v13 + 22) / 45) % 16;
      if ( byte_17F80F[28 * SWORD6(v53)] == 4 )
      {
        sub_3DB8F(v54);
        v50 = v14;
        v4 = 0;
      }
      else
      {
        v15 = sub_329A4(v54, *(_WORD *)(v42 + dword_192B14 + 9), *(_WORD *)(v42 + dword_192B14 + 11));
        v50 = sub_39DE0(v15);
        v4 = *(_WORD *)(313 * (int16_t)v54 + dword_192864 + 56);
      }
      if ( (int16_t)v49 < 8 )
      {
        v16 = (_BYTE *)(3753 * (int16_t)v49 + dword_197F98);
        if ( v16[439] == 3 )
        {
          v4 -= 70;
LABEL_35:
          if ( v4 >= 0 )
          {
            if ( (BYTE1(v53) & 4) != 0 )
              v4 /= 2;
          }
          else
          {
            v4 = 0;
          }
          if ( WORD6(v53) == 40 )
            v4 = 0;
LABEL_41:
          v17 = 26 * (int16_t)a1;
          if ( *(int16_t *)(v17 + dword_192B14 + 15) <= 0 )
          {
            v10 = a1;
            goto LABEL_116;
          }
          if ( (BYTE1(v53) & 2) != 0 )
            *(_WORD *)(v17 + dword_192B14 + 15) *= 4;
          if ( byte_17F80F[28 * SWORD6(v53)] == 4 )
          {
            v41 = (int16_t)a1;
            v25 = 26 * (int16_t)a1;
            v26 = v25 + dword_192B14;
            *(_BYTE *)(v25 + dword_192B14 + 25) = 0;
            if ( WORD6(v53) == 28 )
            {
              v17 = *(int16_t *)(v26 + 15);
              sub_37DA8(
                *(_WORD *)(v26 + 4),
                SWORD2(v56),
                v39,
                v17,
                a1,
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
                SDWORD1(v52),
                SDWORD2(v52),
                SWORD6(v52),
                v53,
                v54,
                v55,
                v56,
                savedregs[0],
                savedregs[1],
                savedregs[2],
                savedregs[3]);
              --*(_BYTE *)(v25 + dword_192B14 + 23);
            }
            else
            {
              if ( WORD6(v53) != 30 )
              {
                v17 = (int16_t)v56;
                sub_3AD57(a1, v50, v56, &v51, &v46);
                DWORD1(v53) += v51;
                DWORD2(v53) += v46;
                if ( WORD6(v53) != 29 )
                  --*(_BYTE *)(v25 + dword_192B14 + 23);
              }
              v43 = 26 * (int16_t)a1;
              if ( *(_BYTE *)(v43 + dword_192B14 + 23) && WORD6(v53) != 31 )
              {
                v17 = (int)&v51;
                sub_3AC20(a1, v50, &v51, &v46);
                --*(_BYTE *)(v43 + dword_192B14 + 23);
                DWORD1(v53) += v51;
                DWORD2(v53) += v46;
              }
              if ( word_1998F6 == 1 && !word_1998E0 )
              {
                v17 = SWORD2(v56);
                sub_3E1A4(a1, SWORD4(v52), SWORD2(v56), SWORD2(v53), SWORD4(v53));
              }
              *(_QWORD *)((char *)&v53 + 4) = 0;
            }
          }
          else
          {
            v18 = word_199224[*(int16_t *)(dword_192B14 + 26 * (int16_t)a1 + 2)];
            if ( (BYTE1(v53) & 0x40) != 0 )
              v18 += 50;
            HIDWORD(v52) = word_17F819[14 * SWORD6(v53)] * v18 / 100;
            if ( (WORD6(v53) == 20 || WORD6(v53) == 40) && (v53 & 0x20) == 0 )
            {
              if ( WORD6(v53) == 20 )
              {
                v19 = 26 * (int16_t)a1 + dword_192B14;
                v20 = 20 * sub_3CD21(0x14u, SBYTE1(v53), *(_WORD *)(v19 + 2)) - *(_WORD *)(v19 + 19) - 20;
                if ( v20 < 0 )
                  v20 = 0;
                v21 = 5 * (v20 / 20);
              }
              else
              {
                v22 = 10000 - *(_WORD *)(dword_192B14 + 26 * (int16_t)a1 + 19) - 20;
                if ( v22 < 0 )
                  v22 = 0;
                v21 = 15 * (v22 / 20);
              }
              HIDWORD(v52) = SWORD6(v52) - v21;
              if ( SWORD6(v52) <= 0 )
                *(_WORD *)(dword_192B14 + 26 * (int16_t)a1 + 15) = 0;
            }
            if ( !(_WORD)v54 && byte_17F80F[28 * SWORD6(v53)] == 2 )
            {
              HIWORD(v23) = HIWORD(v52);
              LOWORD(v23) = SWORD6(v52) / 2;
              HIDWORD(v52) = v23;
            }
            HIDWORD(v54) = 0;
            LODWORD(v52) = v53 & 0xFFFF2000;
            while ( 1 )
            {
              v17 = HIDWORD(v54);
              if ( SWORD2(v54) >= *(int16_t *)(26 * (int16_t)a1 + dword_192B14 + 15) )
                break;
              v24 = sub_1247A0(0x64u);
              if ( sub_4B0D3(v54, 8) && (int)sub_1247A0(0x64u) < 30 )
                v24 = -1000;
              if ( *(_BYTE *)(dword_192864 + 313 * (int16_t)v54 + 64) == 1 && (int)sub_1247A0(0x64u) < 50 )
                v24 = -1000;
              if ( v24 > v4 )
              {
                if ( (BYTE1(v53) & 1) != 0 )
                {
                  DWORD1(v52) = 0;
                  do
                  {
                    LOWORD(v51) = WORD6(v52);
                    sub_39985(v54, (int16_t *)&v51, (int16_t *)&v46, SWORD2(v52), v53, (int16_t)v48, 0, 0, v52);
                    DWORD1(v53) += v51;
                    ++DWORD1(v52);
                    DWORD2(v53) += v46;
                  }
                  while ( SWORD2(v52) < 4 );
                }
                else
                {
                  LOWORD(v51) = WORD6(v52);
                  v45 = sub_39985(v54, (int16_t *)&v51, (int16_t *)&v46, (int16_t)v50, v53, (int16_t)v48, 0, 0, v52);
                  DWORD1(v53) += v51;
                  DWORD2(v53) += v46;
                }
              }
              ++HIDWORD(v54);
            }
            sub_3BC80(a1);
          }
          if ( SWORD4(v53) + SWORD2(v53) > 0 && !(_WORD)v56 && word_1998F6 == 1 && !word_1998E0 )
          {
            if ( !(uint16_t)sub_339A7(v54, SWORD4(v53), v17) )
              sub_49D09(SWORD4(v52) / 20, SWORD2(v56) / 20);
            v27 = (int16_t)v54;
            sub_49ED1(v54, &v55, &v44);
            sub_A93AA(
              (int16_t)(WORD4(v52) - v55 - 20 * word_1998F0),
              (int16_t)(WORD2(v56) - v44 - 20 * word_1998F2),
              v27,
              1,
              SWORD2(v53),
              SWORD4(v53));
            if ( SWORD4(v53) <= 0 )
            {
              while ( !sub_A929A() )
              {
                sub_12C2A0();
                v28 = sub_124D41();
                sub_2F4EE(v28);
                sub_128AB6(0, 0, 639, 350);
                sub_12B634();
                if ( (_WORD)v54 == word_1998FC )
                {
                  v29 = (int16_t)v54;
                  sub_49ED1(v54, &v45, &v47);
                  sub_30062(
                    v29,
                    v29,
                    v39,
                    v40,
                    v41,
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
                    SDWORD1(v53),
                    SDWORD2(v53),
                    SHIDWORD(v53),
                    v54,
                    v55,
                    v56);
                }
                sub_A9223();
                sub_1077D(v30);
                sub_12C2C6(1);
                sub_12B65C();
                sub_128BE7();
              }
            }
            else
            {
              sub_A9867(
                v27,
                SWORD2(v55),
                (int16_t)(WORD4(v52) - 20 * word_1998F0),
                (int16_t)(WORD2(v56) - 20 * word_1998F2));
            }
          }
          if ( !(_WORD)v56 )
          {
            v31 = v54;
            v32 = sub_3897A(v54);
            if ( v32 )
            {
              sub_49ED1(v31, &v45, &v47);
              sub_39E15(v31, WORD4(v52) - v45, WORD2(v56) - v47, v32);
            }
          }
          if ( byte_17F80F[28 * SWORD6(v53)] == 4 )
          {
            v33 = 26 * (int16_t)a1;
            v34 = v33 + dword_192B14;
            if ( *(_BYTE *)(v33 + dword_192B14 + 23) )
            {
              if ( !*(_WORD *)(v34 + 6) && !*(_BYTE *)(v34 + 8) && !(uint16_t)sub_3A142(v33, a1) )
                sub_3DDD8(a1);
            }
            else
            {
              v35 = *(uint8_t *)(313 * *(int16_t *)(v34 + 4) + dword_192864 + 32);
              if ( v35 != sub_3BB3D(a1)
                || !sub_42A27(*(_WORD *)(v33 + dword_192B14 + 4))
                || (v36 = v33 + dword_192B14, *(_WORD *)(v33 + dword_192B14) == 28) )
              {
LABEL_13:
                v10 = a1;
LABEL_116:
                sub_3BC80(v10);
                return 0;
              }
              *(_BYTE *)(v36 + 8) = 0;
              v37 = *(_WORD *)(v36 + 4);
              *(_BYTE *)(v36 + 25) = 1;
              *(_WORD *)(v36 + 6) = v37;
            }
          }
          return 0;
        }
        if ( v16[395] != 3 )
        {
          if ( v16[460] == 3 )
            v4 -= 20;
          goto LABEL_35;
        }
      }
      v4 -= 40;
      goto LABEL_35;
    }
  }
  return 0;
}
// 3D4DF: variable 'v14' is possibly undefined
// 3D8F8: variable 'v39' is possibly undefined
// 3D8F8: variable 'v42' is possibly undefined
// 3D8F8: variable 'v43' is possibly undefined
// 3DA70: variable 'v40' is possibly undefined
// 3DA70: variable 'v41' is possibly undefined
// 3DA7A: variable 'v30' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// A9867: using guessed type int __fastcall sub_A9867(_DWORD, _DWORD, _DWORD, _DWORD);
// AC472: using guessed type int __fastcall sub_AC472(_DWORD, _DWORD, _DWORD, _DWORD);
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 197F98: using guessed type int dword_197F98;
// 199224: using guessed type int16_t word_199224[15];
// 1998DA: using guessed type int16_t word_1998DA;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F6: using guessed type int16_t word_1998F6;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (0003DB8F) --------------------------------------------------------
void __fastcall sub_3DB8F( int a1)
{
  int16_t v2; // cx
  int16_t v3; // dx
  int v4; // eax

  v2 = 200;
  v3 = 0;
  while ( 1 )
  {
    v4 = 313 * a1 + dword_192864 + 2 * v3;
    if ( v2 > *(int16_t *)(v4 + 41) )
      v2 = *(_WORD *)(v4 + 41);
    if ( ++v3 >= 4 )
      JUMPOUT(0x3C87C);
  }
}
// 3DBCC: control flows out of bounds to 3C87C
// 192864: using guessed type int dword_192864;


//----- (0003DBD1) --------------------------------------------------------
void __fastcall sub_3DBD1( int a1, int a2, int a3, int a4)
{
  int64_t v5; // rax
  int v6; // eax
  int16_t v7; // di
  int v8; // ecx
  int64_t v9; // rax
  int16_t i; // cx
  int v11; // ebx
  int v12; // eax
  int v13; // ebx
  int16_t v14; // ax
  _WORD v15[10]; // [esp+0h] [ebp-5Ch] BYREF
  _WORD v16[10]; // [esp+14h] [ebp-48h] BYREF
  unsigned int v17; // [esp+28h] [ebp-34h]
  int v18; // [esp+2Ch] [ebp-30h]
  int v19; // [esp+30h] [ebp-2Ch]
  int v20; // [esp+34h] [ebp-28h]
  int v21; // [esp+38h] [ebp-24h]
  int v22; // [esp+3Ch] [ebp-20h]
  int v23; // [esp+40h] [ebp-1Ch]
  int v24; // [esp+44h] [ebp-18h]
  int v25; // [esp+48h] [ebp-14h]
  int v26; // [esp+4Ch] [ebp-10h]
  unsigned int v27; // [esp+50h] [ebp-Ch]
  unsigned int v28; // [esp+54h] [ebp-8h]
  int v29; // [esp+58h] [ebp-4h]

  v22 = a2;
  v26 = a4;
  v5 = *(int16_t *)(26 * a1 + dword_192B14 + 15);
  v6 = (int)(v5 - (__CFSHL__(HIDWORD(v5), 2) + 4 * HIDWORD(v5))) >> 2;
  v28 = 0;
  v27 = 0;
  if ( v6 > 9 )
    LOWORD(v6) = 9;
  v7 = v6;
  if ( (int16_t)v6 <= 0 )
    v7 = 1;
  sub_3BF72(a1, v7, v16, v15);
  if ( (_WORD)v26 == 1 )
    v8 = 479;
  else
    v8 = 350;
  HIWORD(v9) = 0;
  sub_128AB6(0, 0, 639, v8);
  sub_12B634();
  for ( i = 0; i < v7; ++i )
  {
    v19 = a1;
    v11 = sub_3BB50(a1);
    if ( !(_WORD)v26 )
    {
      v18 = 3;
      HIDWORD(v9) = word_19987A % 3;
      if ( !HIDWORD(v9) )
      {
        v12 = sub_12484C();
        v9 = j___clock(v12, v12, v11);
        v18 = v9;
        v17 = i;
        sub_124820(v19 + i + (_DWORD)v9);
        v17 = sub_1247A0(3u);
        v28 = v17 - 2;
        v17 = sub_1247A0(3u);
        v27 = v17 - 2;
        sub_124820(SHIDWORD(v9));
      }
    }
    v20 = a1;
    v17 = 26 * a1;
    WORD2(v9) = *(_WORD *)(v17 + dword_192B14 + 2);
    v29 = HIDWORD(v9);
    v24 = HIDWORD(v9);
    WORD2(v9) = *(uint8_t *)(v17 + dword_192B14 + 21);
    LOWORD(v9) = *(_WORD *)(v17 + dword_192B14 + 6);
    v21 = HIDWORD(v9);
    if ( (_WORD)v9 == word_1998F8 )
    {
      v18 = (v20 + word_19987A) % 3;
      v17 = 16 * (int16_t)v11;
      sub_12B753(dword_18B2A8[64 * (int16_t)v29 + v17 + (int16_t)v21], v18);
    }
    else
    {
      v18 = 16 * (int16_t)v11;
      sub_12B726(dword_18B2A8[64 * (int16_t)v29 + v18 + SWORD2(v9)]);
    }
    v13 = dword_18B2A8[64 * (int16_t)v24 + 16 * (int16_t)v11 + (int16_t)v21];
    v25 = v27 + v23 - 12;
    v17 = (int16_t)(v15[i] + v27 + v23 - 12);
    v14 = v16[i] + v28 + v22 - 12;
    HIWORD(v9) = HIWORD(v17);
    sub_12A478(v14, v17, v13);
  }
  JUMPOUT(0x3C52B);
}
// 3DDD3: control flows out of bounds to 3C52B
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 18B2A8: using guessed type int dword_18B2A8[960];
// 192B14: using guessed type int dword_192B14;
// 19987A: using guessed type int16_t word_19987A;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (0003DDD8) --------------------------------------------------------
void __fastcall sub_3DDD8( int a1)
{
  int16_t *v2; // eax
  int v3; // edx
  int16_t v4; // ax
  int i; // esi
  int v6; // edx
  int v7; // eax
  int16_t v8; // ax
  int16_t *v9; // eax
  int16_t v10; // dx
  int16_t v11; // [esp+4h] [ebp-Ch]
  int16_t v12; // [esp+8h] [ebp-8h]
  int16_t v13; // [esp+Ch] [ebp-4h]

  v2 = (int16_t *)(dword_192B14 + 26 * a1);
  v3 = 313 * v2[2];
  v11 = -1;
  if ( byte_17F80F[28 * *v2] == 4
    || *(uint8_t *)(v3 + dword_192864 + 32) < 8u
    && *(_BYTE *)(dword_197F98 + 3753 * *(uint8_t *)(v3 + dword_192864 + 32) + 325) == 3 )
  {
    v12 = 30000;
    v11 = -1;
    if ( *(uint8_t *)(v3 + dword_192864 + 32) == word_1998AC )
      v4 = word_19988E;
    else
      v4 = word_1998AC;
    v13 = v4;
    for ( i = 0; (int16_t)i < word_1998C0; ++i )
    {
      if ( (uint16_t)sub_389E8(*(_WORD *)(dword_192B14 + 26 * a1), 0, i, 0)
        && ((_WORD)i || (uint16_t)sub_3A142(0, i)) )
      {
        v6 = 313 * (int16_t)i;
        v7 = v6 + dword_192864;
        if ( *(uint8_t *)(v6 + dword_192864 + 32) == v13
          && !*(_BYTE *)(v7 + 176)
          && *(_BYTE *)(v7 + 64) != 4
          && !sub_3E563(i)
          && !*(_BYTE *)(v6 + dword_192864 + 36)
          && (_WORD)i != *(_WORD *)(26 * a1 + dword_192B14 + 6) )
        {
          v8 = sub_28836(i, a1);
          if ( v8 < v12 )
          {
            v12 = v8;
            v11 = i;
          }
        }
      }
    }
  }
  if ( v11 == -1 )
  {
    v9 = (int16_t *)(dword_192B14 + 26 * a1);
    if ( byte_17F80F[28 * *v9] != 4 || *(_BYTE *)(dword_192864 + 313 * v9[2] + 36) )
    {
      sub_3BC80(a1);
      goto LABEL_28;
    }
    v10 = v9[2];
  }
  else
  {
    v9 = (int16_t *)(26 * a1 + dword_192B14);
    v10 = v11;
  }
  *((_BYTE *)v9 + 8) = 0;
  v9[3] = v10;
LABEL_28:
  JUMPOUT(0x3C87C);
}
// 3DF88: control flows out of bounds to 3C87C
// 3BC80: using guessed type int __fastcall sub_3BC80(_DWORD);
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 197F98: using guessed type int dword_197F98;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0003DF8D) --------------------------------------------------------
int __fastcall sub_3DF8D( int a1)
{
  int v2; // ebx
  int v3; // edx
  int v4; // eax
  int v5; // eax

  v2 = a1;
  v3 = sub_36266();
  LOWORD(v3) = word_17FE00[11 * (int16_t)sub_5680D(v2)] + v3;
  if ( a1 < 8 )
  {
    v4 = 3753 * v2;
    LOWORD(v4) = *(char *)(dword_197F98 + 3753 * v2 + 2214);
    v3 += v4;
  }
  sub_35EAE(a1);
  return v3 + v5 + 50;
}
// 3DFD5: variable 'v5' is possibly undefined
// 17FE00: using guessed type int16_t word_17FE00[];
// 197F98: using guessed type int dword_197F98;


//----- (0003DFE0) --------------------------------------------------------
int __fastcall sub_3DFE0( int a1, int a2)
{
  int v4; // esi
  int v5; // edx
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v10; // [esp+0h] [ebp-4h]

  v4 = a2;
  v10 = a1;
  v5 = 5 * sub_3CD21(a1, 0, a2);
  v6 = 0;
  if ( byte_17F80F[28 * v10] == 4 )
  {
    sub_35EAE(v4);
    v7 = v6;
    if ( a2 < 8 && v4 != -1 )
    {
      v8 = 3753 * v4;
      LOWORD(v8) = *(char *)(dword_197F98 + 3753 * v4 + 2213);
      v6 = v7 + v8;
    }
  }
  if ( (uint16_t)a1 < 0x12u )
  {
    if ( (uint16_t)a1 < 0xFu )
    {
      if ( a1 == 14 )
        v5 -= 10;
    }
    else if ( (uint16_t)a1 <= 0xFu )
    {
      v5 += 15;
    }
    else if ( (uint16_t)a1 <= 0x10u )
    {
      v5 += 40;
    }
    else
    {
      v5 += 70;
    }
  }
  else if ( (uint16_t)a1 > 0x14u )
  {
    if ( (uint16_t)a1 >= 0x1Eu )
    {
      if ( (uint16_t)a1 >= 0x20u )
        return v5;
      goto LABEL_20;
    }
    if ( (uint16_t)a1 >= 0x1Cu )
LABEL_20:
      v5 += v6;
  }
  return v5;
}
// 3E015: variable 'v6' is possibly undefined
// 197F98: using guessed type int dword_197F98;


//----- (0003E095) --------------------------------------------------------
int __usercall sub_3E095( unsigned int a1, int a2, int a3, int a4)
{
  int16_t v4; // ax
  int16_t v5; // ax
  int16_t v6; // ax
  int v7; // eax
  int16_t v8; // ax

  if ( a1 >= 0x12u )
  {
    if ( a1 <= 0x14u )
      goto LABEL_19;
    if ( a1 < 0x1Eu )
    {
      if ( a1 < 0x1Cu )
        goto LABEL_24;
      if ( a1 <= 0x1Cu )
      {
        sub_5685F(a2);
        v7 = 6 * (*(int16_t *)((char *)&word_17F642 + 15 * v8) + 100);
      }
      else
      {
        sub_5685F(a2);
        v7 = 10 * (*(int16_t *)((char *)&word_17F642 + 15 * v6) + 100);
      }
    }
    else if ( a1 <= 0x1Eu )
    {
      sub_5685F(a2);
      v7 = 8 * (*(int16_t *)((char *)&word_17F642 + 15 * v4) + 100);
    }
    else
    {
      if ( a1 > 0x1Fu )
      {
        if ( a1 != 40 )
          goto LABEL_24;
LABEL_19:
        a3 = 5;
        goto LABEL_24;
      }
      sub_5685F(a2);
      v7 = 4 * (*(int16_t *)((char *)&word_17F642 + 15 * v5) + 100);
    }
    a3 = v7 / 200;
    goto LABEL_24;
  }
  if ( a1 < 0xFu )
  {
    if ( a1 == 14 )
      a3 = 4;
  }
  else if ( a1 <= 0xFu )
  {
    a3 = 8;
  }
  else if ( a1 <= 0x10u )
  {
    a3 = 12;
  }
  else
  {
    a3 = 16;
  }
LABEL_24:
  if ( (a4 & 8) != 0 )
    a3 *= 2;
  return a3;
}
// 3E163: variable 'v6' is possibly undefined
// 3E12D: variable 'v4' is possibly undefined
// 3E148: variable 'v5' is possibly undefined
// 3E17E: variable 'v8' is possibly undefined
// 17F642: using guessed type int16_t word_17F642;


//----- (0003E1A4) --------------------------------------------------------
_BOOL1 __fastcall sub_3E1A4( int a1, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  int16_t v7; // di
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // edx
  int v15; // edx
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  _WORD *v19; // eax
  int v20; // eax
  int16_t i; // dx
  int v22; // ebx
  int16_t v23; // cx
  int16_t v24; // ax
  int v25; // eax
  int v26; // ecx
  _BOOL1 result; // al
  int v28; // eax
  int v29; // eax
  int16_t v30; // [esp-4h] [ebp-22h]
  int v31; // [esp+0h] [ebp-1Eh] BYREF
  int v32; // [esp+4h] [ebp-1Ah]
  int v33; // [esp+8h] [ebp-16h]
  int v34; // [esp+Ch] [ebp-12h]
  int v35; // [esp+10h] [ebp-Eh]
  int v36; // [esp+14h] [ebp-Ah]
  int v37; // [esp+18h] [ebp-6h]
  int v38; // [esp+1Ch] [ebp-2h]
  int v39; // [esp+20h] [ebp+2h]
  int v40; // [esp+24h] [ebp+6h] BYREF
  int v41; // [esp+28h] [ebp+Ah]
  int v42; // [esp+2Ch] [ebp+Eh]
  int v43; // [esp+30h] [ebp+12h]
  __int128 v44; // [esp+34h] [ebp+16h] BYREF
  int v45; // [esp+44h] [ebp+26h]
  int v46; // [esp+48h] [ebp+2Ah]
  int v47; // [esp+4Ch] [ebp+2Eh]
  int v48; // [esp+50h] [ebp+32h]
  int64_t v49; // [esp+54h] [ebp+36h]
  int64_t v50; // [esp+5Ch] [ebp+3Eh]
  int64_t v51; // [esp+64h] [ebp+46h] BYREF
  int v52; // [esp+6Ch] [ebp+4Eh]
  int v53; // [esp+70h] [ebp+52h] BYREF
  int v54; // [esp+74h] [ebp+56h]
  int v55; // [esp+78h] [ebp+5Ah]
  int16_t v56; // [esp+7Ch] [ebp+5Eh] BYREF
  int v57; // [esp+80h] [ebp+62h] BYREF
  int v58; // [esp+84h] [ebp+66h]
  int v59; // [esp+88h] [ebp+6Ah]
  int v60; // [esp+8Ch] [ebp+6Eh]
  int v61; // [esp+90h] [ebp+72h]
  int v62; // [esp+94h] [ebp+76h]
  char v63; // [esp+98h] [ebp+7Ah]

  LODWORD(v51) = a2;
  LODWORD(v49) = a3;
  v61 = a4;
  v6 = 26 * a1;
  v63 = 1;
  LOWORD(a2) = *(_WORD *)(dword_192B14 + v6);
  v7 = *(_WORD *)(dword_192B14 + v6 + 6);
  LODWORD(v50) = a2;
  if ( *(_BYTE *)(dword_192B14 + v6 + 8) )
  {
    v8 = 26 * v7;
    v9 = *(int16_t *)(v8 + dword_192B14 + 9);
    v47 = 20;
    v59 = v9 / 20;
    if ( !sub_3D259(v9 / 20, *(int16_t *)(v8 + dword_192B14 + 11) / 20) )
      sub_49D09(*(int16_t *)(v8 + dword_192B14 + 9) / 20, *(int16_t *)(v8 + dword_192B14 + 11) / 20);
    HIWORD(v10) = HIWORD(dword_192B14);
    v11 = dword_192B14 + 26 * v7;
    LOWORD(v10) = 20 * word_1998F0;
    v12 = *(uint16_t *)(v11 + 9) - v10;
    LOWORD(v10) = 20 * word_1998F2;
    LOWORD(v11) = *(_WORD *)(v11 + 11);
    v55 = v12;
    v54 = v11 - v10;
  }
  else
  {
    v12 = v7;
    v13 = sub_339A7(v7, a2, v7);
    if ( !(_WORD)v13 )
      sub_49D09(*(uint8_t *)(dword_192864 + 313 * v7 + 33), *(uint8_t *)(dword_192864 + 313 * v7 + 34));
    LOWORD(v13) = 20 * word_1998F0;
    v14 = v51 - v13;
    LOWORD(v13) = 20 * word_1998F2;
    v55 = v14;
    v54 = v49 - v13;
  }
  v15 = 26 * a1;
  v16 = v15 + dword_192B14;
  LOWORD(v15) = 20 * word_1998F0;
  LOWORD(v12) = *(_WORD *)(v16 + 9);
  v17 = v12 - v15;
  LOWORD(v15) = 20 * word_1998F2;
  v62 = v17;
  LOWORD(v17) = *(_WORD *)(v16 + 11);
  v18 = (int)(*(int16_t *)(v16 + 15)
            - (__CFSHL__((uint64_t)*(int16_t *)(v16 + 15) >> 32, 2)
             + 4 * ((uint64_t)*(int16_t *)(v16 + 15) >> 32))) >> 2;
  v60 = v17 - v15;
  if ( v18 > 9 )
    v18 = 9;
  v58 = v18;
  if ( (int16_t)v18 <= 0 )
    v58 = 1;
  sub_3BF72(a1, v58, (_WORD *)&v44 + 2, &v40);
  HIDWORD(v49) = v62 - 2;
  v52 = 0;
  HIDWORD(v50) = v60 - 2;
  while ( v63 )
  {
    sub_12C2A0();
    sub_124D41();
    v48 = 26 * a1;
    v19 = (_WORD *)(v48 + dword_192B14);
    *v19 = 0;
    sub_2F4EE(v19);
    v20 = v48 + dword_192B14;
    *(_WORD *)v20 = v50;
    if ( !*(_BYTE *)(v20 + 8) && word_1998FC == *(_WORD *)(v20 + 6) )
    {
      sub_49ED1(word_1998FC, &v53, &v57);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      sub_30062(
        *(_WORD *)(v48 + dword_192B14 + 6),
        350,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51);
      sub_12B65C();
      sub_128BE7();
    }
    for ( i = 0; i < (int16_t)v58; ++i )
    {
      v22 = i;
      *((_WORD *)&v31 + 2 * i) = *((_WORD *)&v44 + i + 2) + WORD2(v49);
      v23 = *((_WORD *)&v40 + i) + WORD2(v50);
      *((_WORD *)&v31 + 2 * v22 + 1) = v23;
    }
    v47 = a1;
    sub_3DBD1(a1, (int16_t)v62, (int16_t)v60, 1);
    v30 = v52;
    v24 = sub_3BB3D(v47);
    sub_A9033((int)&v31, v58, v55, v54, word_199254[v24], v30);
    v63 = v25;
    sub_1077D(v25);
    ++v52;
    sub_12C2C6(1);
  }
  v26 = 26 * a1;
  if ( *(_BYTE *)(v26 + dword_192B14 + 8) )
  {
    sub_A9412(v55, v54, 1, v61);
    return sub_A94A1();
  }
  else
  {
    sub_49ED1(v7, &v53, &v57);
    sub_A93AA((int16_t)(v55 - v53), (int16_t)(v54 - v57), *(_WORD *)(v26 + dword_192B14 + 6), 1, v61, a5);
    while ( 1 )
    {
      result = sub_A929A();
      if ( result )
        break;
      sub_12C2A0();
      v28 = sub_124D41();
      sub_2F4EE(v28);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      if ( v7 == word_1998FC )
      {
        sub_49ED1(v7, (_WORD *)&v51 + 2, &v56);
        sub_30062(
          v7,
          v7,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51);
      }
      sub_A9223();
      sub_1077D(v29);
      sub_12C2C6(1);
      sub_12B65C();
      sub_128BE7();
    }
  }
  return result;
}
// 3E2A5: variable 'v13' is possibly undefined
// 3E446: variable 'v25' is possibly undefined
// 3E53C: variable 'v29' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 199254: using guessed type int16_t word_199254[42];
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (0003E563) --------------------------------------------------------
_BOOL1 __fastcall sub_3E563( int a1)
{
  return *(_BYTE *)(313 * a1 + dword_192864 + 74) != 0xFF;
}
// 192864: using guessed type int dword_192864;


//----- (0003E57C) --------------------------------------------------------
_BOOL1 __fastcall sub_3E57C( int a1)
{
  return *(_BYTE *)(313 * a1 + dword_192864 + 311) != 0xFF;
}
// 192864: using guessed type int dword_192864;


//----- (0003E598) --------------------------------------------------------
int16_t __fastcall sub_3E598( int a1, int a2, int a3)
{
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // edx
  int v9; // edx
  int16_t *v10; // esi
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // eax
  int v16; // [esp+0h] [ebp-2Ch]
  int16_t v17; // [esp+8h] [ebp-24h]
  int v18; // [esp+Ch] [ebp-20h] BYREF
  int v19; // [esp+10h] [ebp-1Ch] BYREF
  int v20; // [esp+14h] [ebp-18h]
  int v21; // [esp+18h] [ebp-14h]
  int v22; // [esp+1Ch] [ebp-10h]
  int v23; // [esp+20h] [ebp-Ch]
  int v24; // [esp+24h] [ebp-8h]
  int v25; // [esp+28h] [ebp-4h]

  v24 = a2;
  v23 = a3;
  v5 = 313 * a1;
  v4 = v5 + dword_192864;
  LOWORD(v5) = *(uint8_t *)(v5 + dword_192864 + 33);
  v22 = v5;
  LOWORD(v5) = *(uint8_t *)(v4 + 34);
  v21 = v5;
  if ( !word_1998E0 )
  {
    if ( !sub_3D259(a2, a3) )
      sub_49D09((int16_t)a2, (int16_t)a3);
    word_1998FC = a1;
    sub_34454(a1, &v18, &v19);
    HIWORD(v6) = HIWORD(v22);
    LOWORD(v6) = v22 - word_1998F0;
    v7 = 20 * v6 + v18;
    HIWORD(v6) = HIWORD(v21);
    LOWORD(v6) = v21 - word_1998F2;
    v22 = v7;
    v8 = 20 * v6 + v19;
    HIWORD(v6) = HIWORD(v24);
    LOWORD(v6) = v24 - word_1998F0;
    v21 = v8;
    v9 = 20 * v6 + v18;
    HIWORD(v6) = HIWORD(v23);
    LOWORD(v6) = v23 - word_1998F2;
    v24 = v9;
    v23 = 20 * v6 + v19;
    sub_1112EC(dword_192ED4, v23);
    v10 = (int16_t *)sub_110D3C(dword_192ED4, 9604);
    v11 = sub_124D41();
    sub_2C6BA(v11);
    if ( word_19987E == 1 || word_1998CE )
      v20 = 2;
    else
      v20 = 1;
    v12 = -2500 * (*(uint8_t *)(313 * a1 + dword_192864 + 37) - 2);
    v25 = 0;
    v16 = sub_147D7(55);
    sub_112CD9(v16, v12);
    while ( (int16_t)v25 < 10 )
    {
      sub_2F4EE(v13);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      sub_32B26(a1, 0, 0, 0);
      v17 = 10 * v25;
      sub_12E550(v10, (int16_t *)dword_19283C, 10 * v25);
      sub_12A478(v22, v21, (int)v10);
      sub_32B26(a1, 0, 0, 0);
      sub_12E550(v10, (int16_t *)dword_19283C, 100 - v17);
      sub_12A478(v24, v23, (int)v10);
      sub_12B65C();
      LOWORD(v14) = sub_128BE7();
      sub_1077D(v14);
      v13 = v20;
      v25 += v20;
    }
    sub_12B65C();
    sub_1113CC(dword_192ED4, 10);
    LOWORD(v5) = sub_112C96(v16, 10);
  }
  return v5;
}
// 3E6DF: variable 'v13' is possibly undefined
// 3E772: variable 'v14' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 19283C: using guessed type int dword_19283C;
// 192864: using guessed type int dword_192864;
// 192ED4: using guessed type int dword_192ED4;
// 19987E: using guessed type int16_t word_19987E;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (0003E7A9) --------------------------------------------------------
int __fastcall sub_3E7A9( int a1, _WORD *a2)
{
  int v3; // edi
  int *v4; // edx
  int v5; // eax
  int16_t v6; // ax
  int16_t v7; // di
  int v8; // eax
  int v9; // edx
  int v10; // edx
  int16_t i; // dx
  int v12; // eax
  _WORD v15[900]; // [esp+4h] [ebp-850h]
  _BYTE v16[300]; // [esp+70Ch] [ebp-148h] BYREF
  int v17; // [esp+838h] [ebp-1Ch]
  int v18; // [esp+83Ch] [ebp-18h] BYREF
  int v19; // [esp+840h] [ebp-14h] BYREF
  int v20; // [esp+844h] [ebp-10h]
  int v21; // [esp+848h] [ebp-Ch]
  int16_t v22; // [esp+84Ch] [ebp-8h]
  char v23; // [esp+850h] [ebp-4h]

  v3 = 313 * a1;
  sub_127776(v16, 0x12Cu);
  v4 = &v19;
  v23 = *(_BYTE *)(v3 + dword_192864 + 35);
  sub_49ED1(a1, &v19, &v18);
  HIWORD(v5) = HIWORD(dword_192864);
  LOWORD(v4) = *(uint8_t *)(v3 + dword_192864 + 33);
  v19 += 20 * (_DWORD)v4;
  LOWORD(v5) = *(uint8_t *)(v3 + dword_192864 + 34);
  v18 += 20 * v5;
  v6 = v23 - *a2;
  v20 = 0;
  if ( v6 >= 0 )
  {
    if ( v6 > 8 )
      goto LABEL_3;
LABEL_5:
    v22 = -1;
    goto LABEL_6;
  }
  if ( abs16(v6) > 8u )
    goto LABEL_5;
LABEL_3:
  v22 = 1;
LABEL_6:
  while ( v23 != *a2 && !(_WORD)v20 )
  {
    v23 += v22;
    v23 += v23 < 0 ? 0x10 : 0;
    v7 = 0;
    v23 %= 16;
    do
    {
      v8 = 26 * v7 + dword_192B14;
      if ( *(int16_t *)v8 > 0 && *(_WORD *)(v8 + 6) == a1 && *(_WORD *)(v8 + 4) != a1 )
      {
        v9 = 313 * a1 + dword_192864;
        if ( *(_WORD *)(v9 + 59) )
          v21 = 5 * *(uint8_t *)(v8 + 22) / *(int16_t *)(v9 + 59);
        else
          v21 = 5;
        if ( (int16_t)v21 < 2 )
          v21 = 2;
        if ( !v16[v7] )
        {
          v10 = dword_192B14 + 26 * v7;
          v15[v7] = *(_WORD *)(v10 + 9);
          v15[v7 + 600] = *(_WORD *)(v10 + 11);
          LOWORD(v10) = *(_WORD *)(v10 + 19);
          v16[v7] = 1;
          v15[v7 + 300] = v10;
        }
        v17 = v7;
        if ( sub_3CEB7(v7, v19, (int16_t)v18, v21)
          && sub_2AED2(a1, v17)
          && *(_BYTE *)(26 * v17 + dword_192B14 + 25) == 1 )
        {
          v20 = 1;
        }
      }
      ++v7;
    }
    while ( v7 < 300 );
  }
  if ( (_WORD)v20 )
  {
    v23 -= v22;
    v23 += v23 < 0 ? 0x10 : 0;
    v23 %= 16;
    *a2 = v23;
  }
  for ( i = 0; i < 300; ++i )
  {
    if ( v16[i] == 1 )
    {
      v12 = dword_192B14 + 26 * i;
      *(_WORD *)(v12 + 9) = v15[i];
      *(_WORD *)(v12 + 11) = v15[i + 600];
      *(_WORD *)(v12 + 19) = v15[i + 300];
    }
  }
  return v20;
}
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;


//----- (0003EA09) --------------------------------------------------------
bool __fastcall sub_3EA09( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v7; // dx
  int16_t v8; // cx
  int16_t v9; // cx
  int16_t v10; // dx
  int v11; // eax

  if ( a2 <= a4 )
  {
    v8 = a2;
    v7 = a2 % 20;
  }
  else
  {
    v7 = a2 % 20;
    v8 = a2 + 20;
  }
  v9 = v8 - v7;
  v10 = a3 % 20;
  if ( a3 > a5 )
    a3 += 20;
  v11 = 2 * ((int16_t)(a3 - v10) / 20) + 136 * (v9 / 20);
  return *(int16_t *)((char *)&word_18C9A8 + v11) == 2000 || a1 == *(int16_t *)((char *)&word_18C9A8 + v11);
}
// 18C9A8: using guessed type int16_t word_18C9A8;


//----- (0003EAA5) --------------------------------------------------------
int __fastcall sub_3EAA5( int a1, _WORD *a2, _WORD *a3, _WORD *a4)
{
  int v6; // eax
  int v7; // ecx
  int *v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // ebx
  int16_t v17; // bx
  int v18; // edx
  _WORD v20[900]; // [esp+0h] [ebp-880h]
  _BYTE v21[300]; // [esp+708h] [ebp-178h] BYREF
  _WORD *v22; // [esp+834h] [ebp-4Ch]
  int v23; // [esp+838h] [ebp-48h]
  _WORD *v24; // [esp+83Ch] [ebp-44h]
  int v25; // [esp+840h] [ebp-40h] BYREF
  int v26; // [esp+844h] [ebp-3Ch]
  int v27; // [esp+848h] [ebp-38h] BYREF
  int v28; // [esp+84Ch] [ebp-34h] BYREF
  int v29; // [esp+850h] [ebp-30h]
  int v30; // [esp+854h] [ebp-2Ch]
  int v31; // [esp+858h] [ebp-28h]
  int v32; // [esp+85Ch] [ebp-24h]
  int v33; // [esp+860h] [ebp-20h]
  int v34; // [esp+864h] [ebp-1Ch]
  int v35; // [esp+868h] [ebp-18h]
  int v36; // [esp+86Ch] [ebp-14h]
  int v37; // [esp+870h] [ebp-10h]
  int v38; // [esp+874h] [ebp-Ch]
  int v39; // [esp+878h] [ebp-8h] BYREF
  int v40; // [esp+87Ch] [ebp-4h] BYREF

  v24 = a2;
  v22 = a4;
  sub_127776(v21, 0x12Cu);
  HIWORD(v6) = HIWORD(v24);
  LOWORD(v6) = *v24;
  v33 = v6;
  LOWORD(v6) = *a3;
  v34 = v6;
  v7 = 313 * a1;
  v8 = &v27;
  sub_49ED1(a1, &v27, &v25);
  HIWORD(v9) = HIWORD(dword_192864);
  LOWORD(v8) = *(uint8_t *)(v7 + dword_192864 + 33);
  LOWORD(v9) = *(uint8_t *)(v7 + dword_192864 + 34);
  v32 = 0;
  v38 = 0;
  v31 = 20 * (_DWORD)v8;
  v29 = 20 * v9;
  if ( word_19987E == 1 || word_1998CE )
    v26 = 12;
  else
    v26 = 2;
  v40 = v31;
  v39 = v29;
  v28 = sub_3F5F1(v31, v29, v33, v34);
  if ( (_WORD)v28 != *(uint8_t *)(dword_192864 + 313 * a1 + 35) )
  {
    v32 = sub_3E7A9(a1, &v28);
    v38 = v32;
  }
  *v22 = v28;
  v35 = v40;
  v36 = v39;
  while ( !(_WORD)v32 && ((_WORD)v40 != (_WORD)v33 || (_WORD)v39 != (_WORD)v34) )
  {
    if ( sub_3EA09(word_1998F8, v40, v39, v33, v34) )
    {
      v35 = v40;
      v36 = v39;
    }
    v37 = 0;
    sub_1344B0((int16_t *)&v40, (int16_t *)&v39, v31, v29, v33, v34, v26);
    do
    {
      v10 = dword_192B14 + 26 * (int16_t)v37;
      if ( *(int16_t *)v10 > 0 && a1 == *(_WORD *)(v10 + 6) && a1 != *(_WORD *)(v10 + 4) )
      {
        v11 = dword_192864 + 313 * a1;
        if ( *(_WORD *)(v11 + 59) )
          v30 = *(uint8_t *)(v10 + 22) * (int16_t)v26 / *(int16_t *)(v11 + 59);
        else
          v30 = 5;
        if ( (int16_t)v30 < 2 )
          v30 = 2;
        v12 = (int16_t)v37;
        if ( !v21[(int16_t)v37] )
        {
          v13 = dword_192B14 + 26 * (int16_t)v37;
          v20[(int16_t)v37 + 300] = *(_WORD *)(v13 + 9);
          v20[v12] = *(_WORD *)(v13 + 11);
          LOWORD(v13) = *(_WORD *)(v13 + 19);
          v21[v12] = 1;
          v20[v12 + 600] = v13;
        }
        v23 = (int16_t)v37;
        if ( sub_3CEB7(v37, v27 + v40, (int16_t)(v25 + v39), v30)
          && sub_2AED2(a1, v23)
          && *(_BYTE *)(26 * v23 + dword_192B14 + 25) == 1 )
        {
          v32 = 1;
        }
      }
      ++v37;
    }
    while ( (int16_t)v37 < 300 );
  }
  if ( (_WORD)v32 )
  {
    if ( (_WORD)v35 == (_WORD)v31 && (_WORD)v36 == (_WORD)v29 )
    {
      v40 = v35;
      v14 = v36;
    }
    else
    {
      if ( (int16_t)v35 <= (int16_t)v33 )
      {
        v16 = (int16_t)v35;
        v15 = (int16_t)v35 % 20;
      }
      else
      {
        v15 = (int16_t)v35 % 20;
        v16 = (int16_t)v35 + 20;
      }
      v40 = v16 - v15;
      if ( (int16_t)v36 <= (int16_t)v34 )
      {
        v39 = (int16_t)v36 - (int16_t)v36 % 20;
        goto LABEL_41;
      }
      v14 = (int16_t)v36 + 20 - (int16_t)v36 % 20;
    }
    v39 = v14;
  }
LABEL_41:
  *v24 = v40;
  v17 = 0;
  *a3 = v39;
  do
  {
    if ( v21[v17] == 1 )
    {
      v18 = 26 * v17 + dword_192B14;
      *(_WORD *)(v18 + 9) = v20[v17 + 300];
      *(_WORD *)(v18 + 11) = v20[v17];
      *(_WORD *)(v18 + 19) = v20[v17 + 600];
    }
    ++v17;
  }
  while ( v17 < 300 );
  return v38;
}
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 19987E: using guessed type int16_t word_19987E;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (0003EE0F) --------------------------------------------------------
unsigned int __fastcall sub_3EE0F( int a1, int a2, int a3)
{
  int16_t v5; // di
  char v6; // al
  char v7; // cl
  int v8; // eax
  _BOOL1 v9; // al
  int16_t i; // dx
  int v11; // eax
  int v12; // eax
  int v14; // edx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int16_t v19; // cx
  unsigned int v20; // eax
  int v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // eax
  int j; // ecx
  _BYTE *v26; // eax
  int16_t *v27; // eax
  int16_t k; // cx
  int v29; // eax
  int v30; // ebx
  int16_t m; // cx
  int v32; // esi
  int v33; // eax
  int16_t v34; // ax
  int v36[13]; // [esp+0h] [ebp-2D4h]
  __int128 v37; // [esp+34h] [ebp-2A0h]
  int v38; // [esp+44h] [ebp-290h]
  int v39; // [esp+48h] [ebp-28Ch]
  int v40; // [esp+4Ch] [ebp-288h]
  int v41; // [esp+50h] [ebp-284h]
  int64_t v42; // [esp+54h] [ebp-280h]
  int64_t v43; // [esp+5Ch] [ebp-278h]
  int64_t v44; // [esp+64h] [ebp-270h]
  _WORD v45[10]; // [esp+258h] [ebp-7Ch]
  int v46; // [esp+26Ch] [ebp-68h]
  int v47; // [esp+270h] [ebp-64h]
  int v48; // [esp+274h] [ebp-60h]
  int v49; // [esp+278h] [ebp-5Ch]
  int v50; // [esp+27Ch] [ebp-58h]
  int v51; // [esp+280h] [ebp-54h]
  int v52; // [esp+284h] [ebp-50h] BYREF
  int v53; // [esp+288h] [ebp-4Ch] BYREF
  int v54; // [esp+28Ch] [ebp-48h] BYREF
  int v55; // [esp+290h] [ebp-44h]
  int v56; // [esp+294h] [ebp-40h]
  int v57; // [esp+298h] [ebp-3Ch]
  int v58; // [esp+29Ch] [ebp-38h]
  int v59; // [esp+2A0h] [ebp-34h] BYREF
  int v60; // [esp+2A4h] [ebp-30h]
  int v61; // [esp+2A8h] [ebp-2Ch]
  unsigned int v62; // [esp+2ACh] [ebp-28h]
  int v63; // [esp+2B0h] [ebp-24h]
  int v64; // [esp+2B4h] [ebp-20h]
  int v65; // [esp+2B8h] [ebp-1Ch]
  int v66; // [esp+2BCh] [ebp-18h] BYREF
  int v67; // [esp+2C0h] [ebp-14h]
  int v68; // [esp+2C4h] [ebp-10h] BYREF
  int v69; // [esp+2C8h] [ebp-Ch]
  int v70; // [esp+2CCh] [ebp-8h]
  int v71; // [esp+2D0h] [ebp-4h] BYREF

  v63 = a2;
  v70 = a3;
  v5 = 0;
  sub_38876();
  v60 = 0;
  v62 = 0;
  v61 = 0;
  v7 = v6;
  LOWORD(v8) = word_1998DA > 0;
  v56 = v8;
  LOWORD(v8) = word_1998CC;
  v57 = v8;
  v53 = 20 * a2;
  v54 = 20 * v70;
  v9 = sub_4B0D3(a1, 33) || sub_4B0D3(a1, 22);
  if ( !v9 || v7 )
  {
    sub_49ED1(a1, &v66, &v68);
    v5 = 0;
    if ( *(_BYTE *)(dword_192864 + 313 * a1 + 66) != 0xFF )
    {
      v5 = 1;
      v45[0] = a1;
    }
    for ( i = 0; i < word_1998C0; ++i )
    {
      v11 = dword_192864 + 313 * i;
      if ( *(uint8_t *)(v11 + 66) == a1 && !*(_BYTE *)(v11 + 36) )
      {
        v12 = v5++;
        v45[v12] = i;
      }
    }
    word_1998CC = 0;
    if ( word_18C9A8[68 * (int16_t)v63 + (int16_t)v70] != 2000 )
      return 0;
    HIWORD(v14) = HIWORD(dword_192864);
    v15 = dword_192864 + 313 * a1;
    LOWORD(v14) = *(uint8_t *)(v15 + 33);
    LOWORD(v15) = *(uint8_t *)(v15 + 34);
    v65 = 20 * v14;
    v55 = 20 * v15;
    if ( word_1998CE )
    {
      v69 = 6;
    }
    else if ( word_19987E == 1 || word_1998CE )
    {
      v69 = 12;
    }
    else
    {
      v69 = 2;
    }
    v59 = v65;
    word_1998FC = a1;
    v52 = v55;
    if ( !word_1998E0 )
    {
      sub_ADCFF();
      v16 = sub_124D41();
      sub_2C6BA(v16);
      if ( word_1998D6 )
        sub_2E98D();
      else
        sub_2E2CD();
      sub_128EDE(401, 362, 489, 374, 0, 199);
      sub_128EDE(401, 379, 488, 467, 0, 199);
      sub_3459E(401, 379);
      word_1998F4 = 666;
      word_199904 = 0;
      sub_2F4EE(v17);
      word_199904 = 1;
      sub_11E718();
      sub_124DEC();
    }
    sub_1172D4();
    v46 = a1;
    HIWORD(v18) = HIWORD(dword_192864);
    LOWORD(v18) = *(uint8_t *)(313 * a1 + dword_192864 + 35);
    v71 = v18;
    if ( word_1998C4 == 1 && !word_1998C2 && word_1998DA != 2 )
    {
      v60 = sub_3EAA5(v46, &v53, &v54, &v71);
      if ( (_WORD)v60 == 1 || (int16_t)v53 != 20 * (int16_t)v63 || (int16_t)v54 != 20 * (int16_t)v70 )
        word_1998DA = 1;
    }
    if ( (_WORD)v60 )
    {
      v19 = 2;
      if ( sub_4B0D3(a1, 18) )
      {
        v19 = 1;
      }
      else if ( sub_4B0D3(a1, 17) )
      {
        v19 = 0;
      }
      v20 = ((int16_t)v71 + 16 - *(uint8_t *)(dword_192864 + 313 * a1 + 35)) % 16 * v19;
    }
    else
    {
      v20 = sub_3F95F(a1, (int16_t)v53 / 20, (int16_t)v54 / 20);
    }
    v62 = v20;
    if ( (int16_t)v20 > 0 )
    {
      v71 = sub_3F5F1(
              *(uint8_t *)(dword_192864 + 313 * a1 + 33),
              *(uint8_t *)(dword_192864 + 313 * a1 + 34),
              (int16_t)v53 / 20,
              (int16_t)v54 / 20);
      if ( (_WORD)v56 )
        word_1998DA = 0;
    }
    v51 = a1;
    if ( *(uint8_t *)(313 * a1 + dword_192864 + 35) != (_WORD)v71 )
      sub_3F628(v51, (int16_t)v71, (int16_t)(v59 - 20 * word_1998F0), (int16_t)(v52 - 20 * word_1998F2));
    if ( !*(_BYTE *)(dword_192864 + 313 * a1 + 36)
      && !(_WORD)v60
      && ((_WORD)v65 != (_WORD)v53 || (_WORD)v55 != (_WORD)v54) )
    {
      v59 = v65;
      v52 = v55;
      while ( ((_WORD)v59 != (_WORD)v53 || (_WORD)v52 != (_WORD)v54) && !(uint16_t)sub_3897A(a1) )
      {
        v67 = 0;
        v64 = 0;
        sub_1344B0((int16_t *)&v59, (int16_t *)&v52, v65, v55, v53, v54, v69);
        v71 = 0;
        v71 = sub_3F5F1(v59, v52, v53, v54);
        do
        {
          v21 = dword_192B14 + 26 * (int16_t)v64;
          if ( *(int16_t *)v21 > 0 && a1 == *(_WORD *)(v21 + 6) )
          {
            v22 = 313 * a1;
            if ( *(_WORD *)(v22 + dword_192864 + 59) )
              v23 = *(uint8_t *)(v21 + 22) * (int16_t)v69 / *(int16_t *)(v22 + dword_192864 + 59);
            else
              LOWORD(v23) = 5;
            if ( (int16_t)v23 < 2 )
              LOWORD(v23) = 2;
            if ( sub_3CEB7(v64, v66 + v59, (int16_t)(v68 + v52), v23) )
            {
              v24 = (int16_t)v67++;
              *((_WORD *)v36 + v24) = v64;
            }
          }
          ++v64;
        }
        while ( (int16_t)v64 < 300 );
        if ( !word_1998E0 )
        {
          j = 350;
          sub_128AB6(0, 0, 639, 350);
          sub_12B634();
          v26 = (_BYTE *)sub_124D41();
          if ( v5 > 0 )
          {
            for ( j = 0; (int16_t)j < v5; ++j )
            {
              v47 = (int16_t)v59;
              v26 = sub_ACE08(v45[(int16_t)j], (int16_t)v59, (int16_t)v52);
            }
            sub_2F4EE(v26);
          }
          v58 = 0;
          sub_30062(
            a1,
            j,
            v36[0],
            v36[1],
            v36[2],
            v36[3],
            v36[4],
            v36[5],
            v36[6],
            v36[7],
            v36[8],
            v36[9],
            v36[10],
            v36[11],
            v36[12],
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44);
          do
          {
            v48 = (int16_t)v58;
            v27 = (int16_t *)(dword_192B14 + 26 * (int16_t)v58);
            if ( *v27 > 0 && a1 == v27[3] )
              sub_3C2DC(
                v48,
                (int16_t)(*(int16_t *)((char *)v27 + 9) - 20 * word_1998F0),
                (int16_t)(*(int16_t *)((char *)v27 + 11) - 20 * word_1998F2),
                0);
            ++v58;
          }
          while ( (int16_t)v58 < 300 );
          sub_1077D(v27);
          if ( ++word_19987A == 32000 )
            word_19987A = 0;
          sub_128BE7();
          sub_12B65C();
        }
        for ( k = 0; k < (int16_t)v67; ++k )
        {
          if ( !*(_BYTE *)(313 * a1 + dword_192864 + 36) )
          {
            v29 = *((int16_t *)v36 + k);
            if ( a1 == *(_WORD *)(26 * v29 + dword_192B14 + 6) )
              sub_3D2DF(v29, (int16_t)(v66 + v59), (int16_t)(v68 + v52));
          }
        }
        v50 = a1;
        if ( !(uint16_t)sub_3897A(a1) && *(_BYTE *)(dword_192864 + 313 * v50 + 64) != 4 && !((int16_t)v61 % 3) )
          sub_36ED1(v50, v59, v52, v53, v54);
        ++v61;
      }
    }
    if ( !word_1998E0 )
      sub_ADD24();
  }
  else if ( (int16_t)sub_286E8(a1, 20 * v63, 20 * v70) <= 20 )
  {
    sub_3888C();
    sub_3E598(a1, (int16_t)v63, (int16_t)v70);
  }
  v30 = dword_192864 + 313 * a1;
  *(_BYTE *)(v30 + 33) = (int16_t)v53 / 20;
  word_1998FC = -1;
  *(_BYTE *)(v30 + 34) = (int16_t)v54 / 20;
  word_1998F8 = a1;
  word_1998CC = v57;
  if ( v5 > 0 )
  {
    for ( m = 0; m < v5; ++m )
    {
      v32 = (int16_t)v45[m];
      v49 = 313 * v32;
      v33 = 313 * v32 + dword_192864;
      if ( !*(_BYTE *)(v33 + 36) )
      {
        sub_2885A(v32, *(uint8_t *)(v33 + 66));
        if ( v34 > 4 )
          *(_BYTE *)(dword_192864 + 313 * (int16_t)v45[m] + 66) = -1;
      }
    }
  }
  sub_1172FC();
  return v62;
}
// 3EE32: variable 'v6' is possibly undefined
// 3EE43: variable 'v8' is possibly undefined
// 3F065: variable 'v17' is possibly undefined
// 3F462: variable 'v27' is possibly undefined
// 3F5C5: variable 'v34' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 18C9A8: using guessed type int16_t word_18C9A8[4979];
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 19987A: using guessed type int16_t word_19987A;
// 19987E: using guessed type int16_t word_19987E;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998C2: using guessed type int16_t word_1998C2;
// 1998C4: using guessed type int16_t word_1998C4;
// 1998CC: using guessed type int16_t word_1998CC;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998D6: using guessed type int16_t word_1998D6;
// 1998DA: using guessed type int16_t word_1998DA;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F4: using guessed type int16_t word_1998F4;
// 1998F8: using guessed type int16_t word_1998F8;
// 1998FC: using guessed type int16_t word_1998FC;
// 199904: using guessed type int16_t word_199904;


//----- (0003F5F1) --------------------------------------------------------
int __fastcall sub_3F5F1( int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // edx

  v4 = -sub_1384B9((int16_t)(a3 - a1), (int16_t)(a4 - a2));
  LOWORD(v4) = v4 + ((v4 & 0x8000u) != 0 ? 0x168 : 0);
  HIWORD(v5) = (unsigned int)(((int16_t)(4 * v4) + 45) % 90) >> 16;
  LOWORD(v5) = (int16_t)(((int16_t)(4 * v4) + 45) / 90) % 16;
  return v5;
}


//----- (0003F628) --------------------------------------------------------
int __fastcall sub_3F628( int a1, int a2, int a3, int a4)
{
  int v5; // ecx
  int *v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int16_t v10; // di
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // eax
  int16_t v15; // ax
  _DWORD *v16; // eax
  int16_t i; // dx
  int16_t v18; // di
  int16_t *v19; // eax
  int16_t j; // cx
  int result; // eax
  int v22[13]; // [esp+0h] [ebp-280h]
  __int128 v23; // [esp+34h] [ebp-24Ch]
  int v24; // [esp+44h] [ebp-23Ch]
  int v25; // [esp+48h] [ebp-238h]
  int v26; // [esp+4Ch] [ebp-234h]
  int v27; // [esp+50h] [ebp-230h]
  int64_t v28; // [esp+54h] [ebp-22Ch]
  int64_t v29; // [esp+5Ch] [ebp-224h]
  int64_t v30; // [esp+64h] [ebp-21Ch]
  int v31; // [esp+258h] [ebp-28h]
  int v32; // [esp+25Ch] [ebp-24h]
  int v33; // [esp+260h] [ebp-20h]
  int v34; // [esp+264h] [ebp-1Ch]
  int v35; // [esp+268h] [ebp-18h] BYREF
  int v36; // [esp+26Ch] [ebp-14h]
  int v37; // [esp+270h] [ebp-10h]
  int16_t v38; // [esp+274h] [ebp-Ch]
  int v39; // [esp+278h] [ebp-8h] BYREF
  char v40; // [esp+27Ch] [ebp-4h]

  v32 = a2;
  v33 = a3;
  v36 = a4;
  v5 = 313 * a1;
  v6 = &v35;
  v40 = *(_BYTE *)(v5 + dword_192864 + 35);
  sub_49ED1(a1, &v35, &v39);
  HIWORD(v7) = HIWORD(dword_192864);
  LOWORD(v6) = *(uint8_t *)(v5 + dword_192864 + 33);
  v35 += 20 * (_DWORD)v6;
  LOWORD(v7) = *(uint8_t *)(v5 + dword_192864 + 34);
  v7 *= 20;
  v39 += v7;
  LOWORD(v7) = v40;
  v8 = v7 - v32;
  if ( (v8 & 0x8000u) == 0 )
  {
    if ( (int16_t)v8 > 8 )
      goto LABEL_3;
LABEL_5:
    v38 = -1;
    goto LABEL_6;
  }
  v8 = abs16(v8);
  if ( v8 > 8 )
    goto LABEL_5;
LABEL_3:
  v38 = 1;
LABEL_6:
  LOWORD(v8) = word_1998FC;
  v34 = v8;
  word_1998FC = a1;
  while ( 1 )
  {
    v9 = dword_192864 + 313 * a1;
    if ( *(uint8_t *)(v9 + 35) == (_WORD)v32 || *(_BYTE *)(v9 + 36) )
      break;
    sub_12C2A0();
    v40 += v38;
    v40 += v40 < 0 ? 0x10 : 0;
    v40 %= 16;
    v37 = 0;
    v10 = 0;
    *(_BYTE *)(313 * a1 + dword_192864 + 35) = v40;
    do
    {
      v11 = dword_192B14 + 26 * v10;
      if ( *(int16_t *)v11 > 0 && a1 == *(_WORD *)(v11 + 6) )
      {
        v12 = 313 * a1 + dword_192864;
        if ( *(_WORD *)(v12 + 59) )
          v13 = 5 * *(uint8_t *)(v11 + 22) / *(int16_t *)(v12 + 59);
        else
          LOWORD(v13) = 5;
        if ( (int16_t)v13 < 2 )
          LOWORD(v13) = 2;
        if ( sub_3CEB7(v10, v35, (int16_t)v39, v13) )
        {
          v14 = (int16_t)v37++;
          *((_WORD *)v22 + v14) = v10;
        }
      }
      ++v10;
    }
    while ( v10 < 300 );
    if ( !word_1998E0 )
    {
      sub_33B19(a1);
      if ( v15 )
      {
        v16 = (_DWORD *)sub_124D41();
        for ( i = 0; i < word_1998C0; ++i )
        {
          v16 = (_DWORD *)(dword_192864 + 313 * i);
          if ( !*((_BYTE *)v16 + 36) && *((_BYTE *)v16 + 66) != 0xFF )
            v16 = sub_ACCDB(i);
        }
        sub_2F4EE(v16);
        sub_128AB6(0, 0, 639, 350);
        sub_12B634();
        v18 = 0;
        sub_30062(
          a1,
          350,
          v22[0],
          v22[1],
          v22[2],
          v22[3],
          v22[4],
          v22[5],
          v22[6],
          v22[7],
          v22[8],
          v22[9],
          v22[10],
          v22[11],
          v22[12],
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30);
        sub_12B65C();
        sub_128BE7();
        do
        {
          v31 = v18;
          v19 = (int16_t *)(26 * v18 + dword_192B14);
          if ( *v19 > 0 && a1 == v19[3] )
            sub_3C2DC(
              v31,
              (int16_t)(*(int16_t *)((char *)v19 + 9) - 20 * word_1998F0),
              (int16_t)(*(int16_t *)((char *)v19 + 11) - 20 * word_1998F2),
              0);
          ++v18;
        }
        while ( v18 < 300 );
        sub_1077D(v19);
        sub_12C2C6(1);
      }
    }
    for ( j = 0; j < (int16_t)v37; ++j )
    {
      if ( !*(_BYTE *)(313 * a1 + dword_192864 + 36) && a1 == *(_WORD *)(26 * *((int16_t *)v22 + j) + dword_192B14 + 6) )
        sub_3D2DF(*((int16_t *)v22 + j), (int16_t)v35, (int16_t)v39);
    }
    if ( !(uint16_t)sub_3897A(a1) )
      sub_36ED1(a1, v33 + 20 * word_1998F0, v36 + 20 * word_1998F2, v33 + 20 * word_1998F0, v36 + 20 * word_1998F2);
  }
  result = v34;
  word_1998FC = v34;
  return result;
}
// 3F7BA: variable 'v15' is possibly undefined
// 3F880: variable 'v19' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (0003F923) --------------------------------------------------------
int __fastcall sub_3F923( int a1)
{
  int v2; // ebx

  v2 = 2;
  if ( sub_4B0D3(a1, 18) )
    return 1;
  if ( sub_4B0D3(a1, 17) )
    return 0;
  return v2;
}


//----- (0003F95F) --------------------------------------------------------
unsigned int __fastcall sub_3F95F( int a1, int a2, int a3)
{
  int16_t v4; // cx
  uint8_t *v5; // eax
  int16_t v7; // cx
  _BOOL1 v8; // zf
  int i; // esi
  unsigned int v10; // eax
  int v11; // ecx
  int16_t v13; // [esp+8h] [ebp-10h]
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  int16_t v15; // [esp+10h] [ebp-8h]
  int16_t v16; // [esp+14h] [ebp-4h]

  v5 = (uint8_t *)(313 * a1 + dword_192864);
  v13 = v5[35];
  v4 = v5[33];
  v16 = v4;
  LOWORD(v5) = v5[34];
  if ( a2 == v4 && (_WORD)v5 == (_WORD)a3 )
    return 0;
  v7 = (a2 - v4) * (a2 - v4);
  i = (a3 - (_DWORD)v5) * (a3 - (_DWORD)v5);
  v8 = v7 + (_WORD)i == 0;
  LOWORD(i) = v7 + i;
  v15 = i;
  if ( !v8 )
  {
    for ( i = 1; (int16_t)i < 81 && v15 >= (int16_t)i * (int16_t)i + 1; ++i )
      ;
  }
  v10 = abs32((int16_t)sub_3F5F1(v16, (int16_t)v5, a2, a3) - v13);
  v14 = v10;
  if ( (int16_t)v10 > 8 )
    v14 = abs32((int16_t)v10 - 16);
  v11 = 2;
  if ( sub_4B0D3(a1, 18) )
  {
    v11 = 1;
  }
  else if ( sub_4B0D3(a1, 17) )
  {
    v11 = 0;
  }
  return v14 * v11 + i;
}
// 192864: using guessed type int dword_192864;


//----- (0003FA61) --------------------------------------------------------
void __fastcall sub_3FA61( int a1, int a2, int a3)
{
  int16_t v6; // cx
  int16_t v7; // si
  int16_t v8; // ax
  int16_t v9; // cx
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // [esp+0h] [ebp-14h]
  int16_t v15; // [esp+Ch] [ebp-8h]
  int16_t v16; // [esp+10h] [ebp-4h]

  if ( !*(_WORD *)(313 * a1 + dword_192864 + 61) )
    return;
  v6 = 2;
  if ( sub_4B0D3(a1, 18) )
  {
    v6 = 1;
  }
  else if ( sub_4B0D3(a1, 17) )
  {
    v6 = 0;
  }
  v14 = 313 * a1;
  v15 = v6;
  v7 = sub_3F5F1(*(uint8_t *)(v14 + dword_192864 + 33), *(uint8_t *)(v14 + dword_192864 + 34), a2, a3);
  v8 = *(uint8_t *)(v14 + dword_192864 + 35) - v7;
  v9 = v8;
  if ( v8 >= 0 )
  {
    if ( v8 > 8 )
      goto LABEL_8;
LABEL_10:
    v16 = -1;
    goto LABEL_11;
  }
  if ( abs16(v8) > 8u )
    goto LABEL_10;
LABEL_8:
  v16 = 1;
LABEL_11:
  if ( v8 < 0 )
    v9 = v8 + 16;
  if ( v9 > 8 )
    v9 = 16 - v9;
  v10 = dword_192864 + 313 * a1;
  v11 = *(int16_t *)(v10 + 61);
  if ( v11 >= v15 * v9 )
  {
    *(_WORD *)(v10 + 61) -= v15 * v9;
  }
  else
  {
    v12 = *(uint8_t *)(v10 + 35) + v16 * ((v15 + v11 - 1) / v15);
    v7 = (int16_t)(v12 + ((v12 & 0x8000u) != 0 ? 0x10 : 0)) % 16;
    *(_WORD *)(313 * a1 + dword_192864 + 61) = 0;
  }
  sub_3F628(
    a1,
    v7,
    (int16_t)(20 * (*(uint8_t *)(dword_192864 + 313 * a1 + 33) - word_1998F0)),
    (int16_t)(20 * (*(uint8_t *)(dword_192864 + 313 * a1 + 34) - word_1998F2)));
  sub_46CC8(a1, v7);
  sub_2C601(v13, v7);
}
// 3FBF4: variable 'v13' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;


//----- (0003FBFE) --------------------------------------------------------
int __fastcall sub_3FBFE(int a1)
{
  int16_t v1; // si
  char *v2; // ebx
  int v3; // edx
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  char v8[80]; // [esp+0h] [ebp-54h] BYREF
  int v9; // [esp+50h] [ebp-4h] BYREF

  v1 = a1;
  LOWORD(a1) = word_1998AC;
  if ( word_1998AC == word_19999C )
    LOWORD(a1) = word_19988E;
  v9 = a1;
  v2 = (char *)&v9;
  v3 = 1004;
  result = sub_F6816(*(int16_t *)(dword_197F98 + 3753 * (int16_t)a1 + 43), 1004, (int)&v9, 2u);
  while ( !byte_199F16 )
  {
    if ( v1 )
    {
      sub_12C2A0();
      v5 = sub_124D41();
      sub_2F4EE(v5);
      sub_120BB5(3, (int)&unk_17D879);
      sub_58F1E(55, v8, 80);
      v2 = v8;
      v3 = 8;
      v6 = sub_1212B3(20, 8, (int)v8);
      sub_1077D(v6);
      v7 = sub_12C2C6(1);
    }
    else
    {
      v7 = sub_FE8BE(result);
    }
    result = sub_1171AB(v7, v3, (int)v2, 2);
  }
  --byte_199F16;
  return result;
}
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 197F98: using guessed type int dword_197F98;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 19999C: using guessed type int16_t word_19999C;
// 199F16: using guessed type char byte_199F16;


//----- (0003FCD8) --------------------------------------------------------
int16_t __fastcall sub_3FCD8(int a1, int a2, int a3, _BYTE *a4)
{
  int16_t result; // ax

  result = a2;
  if ( (uint16_t)a2 >= 0x3E8u && (uint16_t)a2 < 0x7D0u )
  {
    result = a2 - 1000;
    switch ( a2 )
    {
      case 1000:
        sub_12779E(&word_190460, a4, 0x10u);
        result = word_190468;
        word_1999AC = word_190468;
        break;
      case 1002:
        result = *(_WORD *)a4;
        word_192B10[*(int16_t *)a4] = 0;
        if ( *(uint8_t *)(313 * word_1998F8 + dword_192864 + 32) == word_1998AC )
        {
          if ( !result )
            word_199900 = 0;
        }
        else if ( result == 1 )
        {
          word_199900 = 0;
        }
        break;
      case 1003:
        word_1998D0 = word_1998C4;
        result = *(_WORD *)a4;
        word_1998C4 = *(_WORD *)a4;
        break;
      case 1004:
        ++byte_199F16;
        break;
      case 1005:
        if ( *(_WORD *)a4 == 1 )
        {
          result = *(_WORD *)a4;
          word_17D853 = *(_WORD *)a4;
        }
        break;
      default:
        result = a2 - 1000;
        break;
    }
  }
  return result;
}
// 17D853: using guessed type int16_t word_17D853;
// 190460: using guessed type int16_t word_190460;
// 190468: using guessed type int16_t word_190468;
// 192864: using guessed type int dword_192864;
// 192B10: using guessed type int16_t word_192B10[];
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C4: using guessed type int16_t word_1998C4;
// 1998D0: using guessed type int16_t word_1998D0;
// 1998F8: using guessed type int16_t word_1998F8;
// 199900: using guessed type int16_t word_199900;
// 1999AC: using guessed type int16_t word_1999AC;
// 199F16: using guessed type char byte_199F16;


//----- (0003FDAA) --------------------------------------------------------
int16_t __fastcall sub_3FDAA(int a1, int a2)
{
  return sub_A5EBF(a1, a2, 0);
}


//----- (0003FDB4) --------------------------------------------------------
int __fastcall sub_3FDB4( int a1, int a2)
{
  int v3; // ebx
  int16_t v4; // ax
  int16_t v5; // ax
  int16_t v6; // ax
  int16_t v7; // ax
  int v8; // ebx
  int v9; // eax
  int result; // eax
  int16_t v11; // bx
  int16_t v12; // [esp+4h] [ebp-18h]
  int16_t v13; // [esp+8h] [ebp-14h]
  int16_t v14; // [esp+Ch] [ebp-10h]
  int16_t v15; // [esp+10h] [ebp-Ch]
  int16_t v16; // [esp+14h] [ebp-8h]
  int16_t v17; // [esp+18h] [ebp-4h]

  v3 = 33 * a1;
  sub_56B26(8);
  v15 = v4;
  sub_568EB(8);
  v12 = v5;
  v13 = sub_56CA2(8);
  v16 = sub_5679E(8);
  v14 = sub_5EB39(8);
  sub_5685F(8);
  v17 = *(int16_t *)((char *)&word_17F642 + 15 * v6);
  v7 = sub_56D3A(8, a2);
  v8 = dword_192844 + v3;
  *(_WORD *)(v8 + 17) = v7;
  *(_WORD *)(v8 + 9) = v16;
  *(_WORD *)(v8 + 2) = -1;
  *(_BYTE *)(v8 + 6) = 0;
  *(_WORD *)(v8 + 4) = -1;
  *(_BYTE *)(v8 + 1) = a2;
  *(_BYTE *)v8 = 8;
  *(_WORD *)(v8 + 11) = v15;
  *(_WORD *)(v8 + 13) = v12;
  *(_WORD *)(v8 + 15) = v13;
  if ( *(_BYTE *)v8 > 9u )
    LOWORD(v9) = word_180038[18 * a2];
  else
    v9 = word_180038[18 * a2] * (v17 + 100) / 100;
  *(_WORD *)(v8 + 29) = v9;
  result = dword_192844 + 33 * a1;
  *(_WORD *)(result + 19) = 0;
  v11 = word_180036[18 * a2];
  *(_WORD *)(result + 27) = 0;
  *(_WORD *)(result + 25) = 105;
  *(_WORD *)(result + 7) = -1;
  *(_WORD *)(result + 21) = v11 + 95;
  *(_WORD *)(result + 31) = 0;
  *(_WORD *)(result + 23) = v14 + 45;
  return result;
}
// 3FDD0: variable 'v4' is possibly undefined
// 3FDDD: variable 'v5' is possibly undefined
// 3FE12: variable 'v6' is possibly undefined
// 17F642: using guessed type int16_t word_17F642;
// 180036: using guessed type int16_t word_180036[];
// 180038: using guessed type int16_t word_180038[];
// 192844: using guessed type int dword_192844;


//----- (0003FEF2) --------------------------------------------------------
int sub_3FEF2()
{
  int16_t i; // bx
  int16_t j; // cx
  int v2; // edx
  int v3; // eax
  int16_t v4; // ax
  int v5; // ebx
  int16_t v6; // ax
  int v7; // eax
  int result; // eax
  int v9; // edx

  if ( word_199182 < 1 )
    word_199182 = 1;
  for ( i = 0; i < 5; ++i )
  {
    for ( j = 0; j < word_19917A[i]; ++j )
    {
      sub_3FDB4(word_1998C0, i);
      ++word_1998C0;
      ++word_1998BE;
    }
  }
  v2 = 33 * word_1998C0;
  v3 = dword_192844;
  *(_BYTE *)(v2 + dword_192844) = 8;
  *(_WORD *)(v2 + v3 + 2) = -1;
  *(_BYTE *)(v2 + v3 + 1) = 8;
  *(_BYTE *)(v2 + v3 + 6) = 0;
  *(_WORD *)(v2 + v3 + 4) = -1;
  sub_56B26(8);
  *(_WORD *)(dword_192844 + 33 * word_1998C0 + 11) = v4;
  sub_568EB(8);
  v5 = 33 * word_1998C0 + dword_192844;
  *(_WORD *)(v5 + 13) = v6;
  v7 = 1000 * word_180158 / 100;
  *(_WORD *)(v5 + 15) = 0;
  *(_WORD *)(v5 + 17) = 0;
  *(_WORD *)(v5 + 29) = v7;
  LOWORD(v7) = word_180156;
  *(_WORD *)(v5 + 9) = 7;
  *(_WORD *)(v5 + 21) = v7 + 45;
  *(_WORD *)(v5 + 19) = 0;
  LOWORD(v5) = sub_5EB39(8);
  result = 33 * word_1998C0;
  v9 = dword_192844;
  *(_WORD *)(dword_192844 + result + 27) = 0;
  ++word_1998BE;
  *(_WORD *)(v9 + result + 25) = 105;
  *(_WORD *)(v9 + result + 31) = 0;
  ++word_1998C0;
  *(_WORD *)(v9 + result + 23) = v5 + 45;
  return result;
}
// 3FF84: variable 'v4' is possibly undefined
// 3FFA5: variable 'v6' is possibly undefined
// 180156: using guessed type int16_t word_180156;
// 180158: using guessed type int16_t word_180158;
// 192844: using guessed type int dword_192844;
// 19917A: using guessed type int16_t word_19917A[4];
// 199182: using guessed type int16_t word_199182;
// 1998BE: using guessed type int16_t word_1998BE;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00040034) --------------------------------------------------------
int __fastcall sub_40034(int result, int a2, int16_t *a3, int16_t *a4, int16_t *a5, int16_t *a6, int16_t *a7)
{
  int v7; // esi
  int16_t i; // dx
  int16_t v9; // ax
  int16_t v10; // ax
  int16_t v11; // ax
  int16_t v12; // ax

  v7 = result;
  for ( i = 0; i < a2; ++i )
  {
    result = *(int16_t *)(dword_197F9C + 129 * *(int16_t *)(v7 + 2 * i) + 116);
    if ( result != -1 )
    {
      result *= 59;
      if ( !*(_BYTE *)(result + dword_1930DC + 55) )
      {
        sub_3677D(*(_WORD *)(dword_197F9C + 129 * *(int16_t *)(v7 + 2 * i) + 116));
        if ( v9 > *a3 )
          *a3 = v9;
        sub_35F4D(*(_WORD *)(129 * *(int16_t *)(v7 + 2 * i) + dword_197F9C + 116));
        if ( v10 > *a4 )
          *a4 = v10;
        sub_3607A(*(_WORD *)(129 * *(int16_t *)(v7 + 2 * i) + dword_197F9C + 116));
        if ( v11 > *a5 )
          *a5 = v11;
        sub_367AE(*(_WORD *)(dword_197F9C + 129 * *(int16_t *)(v7 + 2 * i) + 116));
        if ( v12 > *a6 )
          *a6 = v12;
        sub_367DF(*(_WORD *)(dword_197F9C + 129 * *(int16_t *)(v7 + 2 * i) + 116));
        if ( (int16_t)result > *a7 )
          *a7 = result;
      }
    }
  }
  return result;
}
// 4008B: variable 'v9' is possibly undefined
// 400B4: variable 'v10' is possibly undefined
// 400E0: variable 'v11' is possibly undefined
// 40109: variable 'v12' is possibly undefined
// 40132: variable 'result' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;


//----- (00040148) --------------------------------------------------------
int __fastcall sub_40148(int16_t *a1, int a2, int16_t *a3, int a4, int a5, int a6, char *a7, _DWORD *a8)
{
  int v10; // eax
  int v11; // edx
  int16_t v12; // ax
  int16_t i; // dx
  int v14; // esi
  int16_t j; // dx
  char v16; // al
  char *v17; // eax
  int16_t k; // bx
  int16_t v19; // cx
  int16_t v20; // cx
  int16_t m; // bx
  int n; // ebx
  int v23; // eax
  uint8_t v24; // al
  uint16_t v25; // dx
  uint8_t *v26; // eax
  int v27; // edx
  int v28; // eax
  int v29; // edx
  int v30; // eax
  int v31; // eax
  int16_t *v32; // ecx
  int v33; // eax
  int v34; // edx
  uint8_t *v35; // eax
  uint8_t *v36; // eax
  int v37; // edx
  int v38; // edx
  int16_t v39; // ax
  uint8_t *v40; // eax
  int v41; // edx
  int v42; // ebx
  int16_t v43; // bx
  int v44; // ecx
  int v45; // edx
  int16_t v46; // ax
  int16_t kk; // dx
  _BYTE *v48; // eax
  int v49; // eax
  int v50; // eax
  int16_t v51; // ax
  int16_t mm; // dx
  int16_t v53; // bx
  _WORD v55[28]; // [esp+0h] [ebp-3Eh] BYREF
  int v56; // [esp+38h] [ebp-6h]
  int v57; // [esp+3Ch] [ebp-2h]
  int v58; // [esp+40h] [ebp+2h] BYREF
  int v59; // [esp+44h] [ebp+6h]
  int v60; // [esp+48h] [ebp+Ah]
  int v61; // [esp+4Ch] [ebp+Eh]
  int v62; // [esp+50h] [ebp+12h]
  int v63; // [esp+54h] [ebp+16h]
  int v64; // [esp+58h] [ebp+1Ah]
  int v65; // [esp+5Ch] [ebp+1Eh] BYREF
  int v66; // [esp+60h] [ebp+22h]
  int v67; // [esp+64h] [ebp+26h]
  int v68; // [esp+68h] [ebp+2Ah] BYREF
  char *v69; // [esp+6Ch] [ebp+2Eh]
  int v70; // [esp+70h] [ebp+32h]
  int jj; // [esp+74h] [ebp+36h]
  int v72; // [esp+78h] [ebp+3Ah]
  int v73; // [esp+7Ch] [ebp+3Eh] BYREF
  int v74; // [esp+80h] [ebp+42h] BYREF
  int v75; // [esp+84h] [ebp+46h]
  int ii; // [esp+88h] [ebp+4Ah]
  int v77; // [esp+8Ch] [ebp+4Eh] BYREF
  int v78; // [esp+90h] [ebp+52h] BYREF
  int v79; // [esp+94h] [ebp+56h]
  int v80; // [esp+98h] [ebp+5Ah] BYREF
  int v81; // [esp+9Ch] [ebp+5Eh]
  int v82; // [esp+A0h] [ebp+62h] BYREF
  char v83; // [esp+A4h] [ebp+66h]
  char v84; // [esp+A8h] [ebp+6Ah]
  char v85; // [esp+ACh] [ebp+6Eh]

  v67 = a2;
  v75 = a4;
  v66 = 0;
  v70 = 0;
  v79 = 0;
  v84 = 0;
  v69 = 0;
  v10 = 0;
  do
  {
    v11 = (int16_t)v10++;
    v55[v11] = 0;
  }
  while ( (int16_t)v10 < 20 );
  sub_107AF(&v58);
  sub_1191CA((int)sub_84E9D, 1);
  word_199878 = a6;
  word_199890 = 0;
  dword_192844 = (int)sub_110CEE(dword_192ED4, 16501);
  sub_127776((_BYTE *)dword_192844, 0x4095u);
  word_1998AC = *(char *)(dword_197F9C + 129 * *a1 + 99);
  if ( a5 == word_19999A )
  {
    word_19988E = 8;
  }
  else
  {
    if ( (_WORD)v75 )
      v12 = *(char *)(dword_197F9C + 129 * *a3 + 99);
    else
      v12 = *(char *)(dword_192B18 + 361 * word_199878);
    word_19988E = v12;
  }
  if ( word_1998AC == 9 && word_19988E >= 8 )
  {
    for ( i = 0; i < (int16_t)v75; ++i )
      sub_A163A(a3[i], (int)a3);
    return 1;
  }
  if ( word_19988E == 9 && word_1998AC >= 8 )
  {
    for ( j = 0; j < (int16_t)v67; ++j )
      sub_A163A(a1[j], (int)a3);
    return -1;
  }
  word_1998C0 = 1;
  byte_199EF6 = 0;
  v65 = 0;
  v80 = 0;
  v78 = 0;
  v61 = (int16_t)v67;
  v82 = 0;
  sub_40034((int)a1, v67, (int16_t *)&v65, (int16_t *)&v80, &v55[word_1998AC], (int16_t *)&v78, (int16_t *)&v82);
  sub_416CF(a1, v61, v65, v80, v78, (int16_t)v82);
  word_1998A2 = word_1998C0 - 1;
  if ( word_19988E < 8 && a5 < word_19999A )
  {
    if ( (uint8_t)sub_79CF9(dword_197F98 + 3753 * word_19988E, dword_19306C + 113 * a5) )
    {
      sub_3868F(1);
      v84 = v16;
      if ( v16 )
        v79 = -1;
    }
  }
  if ( !v84 )
  {
    if ( a5 == word_19999A )
    {
      v17 = (char *)sub_3FEF2();
    }
    else
    {
      v77 = 0;
      v74 = 0;
      v68 = 0;
      v61 = (int16_t)v75;
      v73 = 0;
      sub_40034((int)a3, v75, (int16_t *)&v77, (int16_t *)&v74, &v55[word_19988E], (int16_t *)&v68, (int16_t *)&v73);
      v17 = sub_416CF(a3, v61, v77, v74, v68, (int16_t)v73);
    }
    word_1998BE = word_1998C0 - word_1998A2;
    if ( !byte_199EF6 )
      --word_1998BE;
    LOWORD(v17) = (uint8_t)byte_199EF6;
    v69 = v17;
    while ( word_1998A2 > 0 && word_1998BE > 0 && word_199890 < 50 )
    {
      ++word_199890;
      for ( k = 0; k < word_1998C0; ++k )
      {
        if ( *(_BYTE *)(dword_192844 + 33 * k + 6) != 2 )
        {
          v19 = sub_41E88(k);
          if ( v19 != -1 )
          {
            if ( !k && (byte_199EF6 & 4) != 0 )
            {
              v20 = 0;
              v81 = sub_41F20(0);
              do
              {
                ++v20;
                sub_40C2A(v81, word_17FC41);
              }
              while ( v20 < 4 );
              v19 = sub_41E88(0);
            }
            if ( v19 != -1 && (word_199890 < 4 || *(_BYTE *)(dword_192844 + 33 * k + 1) > 5u || !k) )
            {
              v59 = k;
              if ( *(_BYTE *)(dword_192844 + 33 * k) == 8 )
                sub_4221F(v59, v19);
              else
                sub_41F80(v59, v19);
            }
            if ( v19 != -1 && (word_199890 > 2 || !k) )
              sub_4215C(k, v19);
            if ( v19 != -1 && (word_199890 > 2 || !k) )
              sub_4221F(k, v19);
            if ( word_199890 > 3 )
            {
              v60 = k;
              if ( *(uint8_t *)(33 * k + dword_192844) == word_1998AC
                && !*(_BYTE *)(dword_192844 + 6)
                && word_199878 != -1 )
              {
                sub_420C0(v60);
              }
            }
          }
        }
      }
      sub_423F6((int)a3);
      for ( m = 0; m < word_1998C0; ++m )
      {
        v17 = (char *)(33 * m + dword_192844);
        if ( v17[6] == 1 )
        {
          v17[6] = 2;
          if ( (uint8_t)*v17 == word_1998AC )
            --word_1998A2;
          else
            --word_1998BE;
        }
      }
    }
    if ( word_199890 >= 50 )
    {
      if ( word_1998BE <= 0 )
        v79 = 0;
      else
        v79 = -1;
    }
    else
    {
      LOWORD(v17) = word_1998A2 - word_1998BE;
      v79 = (int)v17;
    }
  }
  for ( n = 0; (int16_t)n < word_1998C0; ++n )
  {
    v23 = 33 * (int16_t)n + dword_192844;
    if ( *(_BYTE *)(v23 + 6) && *(_BYTE *)(v23 + 1) > 4u && a5 != word_19999A )
    {
      v24 = *(_BYTE *)(v23 + 1);
      if ( v24 < 7u )
      {
        if ( v24 != 6 )
          goto LABEL_91;
        v25 = 40;
        goto LABEL_90;
      }
      if ( v24 <= 7u )
      {
        v25 = 8;
LABEL_90:
        sub_145EA(word_199878, v25, (int)a3);
        goto LABEL_91;
      }
      if ( v24 == 8 )
      {
        v25 = 41;
        goto LABEL_90;
      }
    }
LABEL_91:
    v26 = (uint8_t *)(dword_192844 + 33 * (int16_t)n);
    if ( *((int16_t *)v26 + 1) != -1 )
    {
      v27 = *v26;
      if ( (int16_t)v55[v27] > 0
        || *v26 < 8u && ((v28 = dword_197F98 + 3753 * v27, *(_BYTE *)(v28 + 283) == 3) || *(_BYTE *)(v28 + 2224)) )
      {
        v29 = 33 * (int16_t)n;
        v30 = dword_192844;
        *(_WORD *)(v29 + dword_192844 + 31) = 0;
        *(_WORD *)(129 * *(int16_t *)(v29 + v30 + 2) + dword_197F9C + 125) = 0;
      }
      else if ( byte_199CB4 == 1 )
      {
        v31 = dword_192844 + 33 * (int16_t)n;
        v61 = 129 * *(int16_t *)(v31 + 2);
        *(_WORD *)(v61 + dword_197F9C + 125) = *(_WORD *)(v31 + 31);
      }
      else
      {
        v32 = (int16_t *)(33 * (int16_t)n + dword_192844);
        v61 = 33 * (int16_t)n;
        v33 = 100 * *(int16_t *)((char *)v32 + 31);
        v62 = *(int16_t *)((char *)v32 + 29);
        v34 = v33 / v62;
        v72 = v34 * (int16_t)sub_58387(v32[1], v33 / v62, n, (int)v32) / 100;
        *(_WORD *)(dword_197F9C + 129 * *(int16_t *)(v61 + dword_192844 + 2) + 125) = v72;
      }
    }
    v35 = (uint8_t *)(33 * (int16_t)n + dword_192844);
    if ( v35[6] && *((int16_t *)v35 + 1) != -1 )
    {
      if ( *v35 != word_1998AC )
      {
        LOWORD(v35) = v35[1];
        v70 += (int)(v35 + 1);
      }
      v63 = 33 * (int16_t)n;
      v36 = (uint8_t *)(v63 + dword_192844);
      v37 = *(int16_t *)(v63 + dword_192844 + 7);
      v64 = v37;
      if ( v37 > -1 )
      {
        if ( *(char *)(dword_1930DC + 59 * v37 + 55) <= 0 )
        {
          if ( *(_BYTE *)(dword_197F98 + 3753 * *v36 + 458) == 3 )
          {
            v38 = (int16_t)v66;
            v39 = *(_WORD *)(v36 + 7);
            ++v66;
            v55[v38 + 20] = v39;
          }
          else
          {
            sub_941C6(v64, (int)a3);
          }
        }
        else
        {
          sub_944A3(v64, (int)a3);
          *(_WORD *)(dword_197F9C + 129 * *(int16_t *)(v63 + dword_192844 + 2) + 116) = -1;
        }
      }
    }
  }
  if ( word_1998AC < 8 && word_19988E < 8 )
  {
    if ( word_199878 != -1 )
      sub_F975C(-10000, word_1998AC, word_19988E, 10, a5, 1);
    sub_F975C(-15 * v70, word_1998AC, word_19988E, 11, a5, 0);
  }
  if ( (_WORD)v66 )
  {
    for ( ii = 0; (int16_t)ii < (int16_t)v66; ++ii )
    {
      v83 = 0;
      v85 = 0;
      for ( jj = 1; (int16_t)jj < word_1998C0 && !v83; ++jj )
      {
        v40 = (uint8_t *)(33 * (int16_t)jj + dword_192844);
        if ( !v40[6] )
        {
          v56 = *((int16_t *)v40 + 1);
          if ( v56 != -1 )
          {
            v41 = (int16_t)ii;
            v42 = 59 * (int16_t)v55[v41 + 20];
            v57 = dword_1930DC;
            if ( *(char *)(dword_1930DC + v42 + 58) == *v40 )
            {
              if ( *(int16_t *)(v40 + 7) == -1 )
              {
                v61 = dword_197F9C;
                v43 = v55[(int16_t)ii + 20];
                *(_WORD *)(dword_197F9C + 129 * v56 + 116) = v43;
                v44 = v57 + 59 * v43;
                *(_WORD *)(v40 + 7) = v43;
                *(_WORD *)(v61 + 129 * *(int16_t *)(v44 + 53) + 116) = -1;
                v45 = 59 * (int16_t)v55[v41 + 20];
                v46 = *((_WORD *)v40 + 1);
                v83 = 1;
                *(_WORD *)(v57 + v45 + 53) = v46;
              }
              v85 = 1;
            }
          }
        }
      }
      if ( !v83 )
      {
        if ( v85 )
          sub_944A3(v55[(int16_t)ii + 20], (int)a3);
        else
          sub_941C6(v55[(int16_t)ii + 20], (int)a3);
      }
    }
  }
  for ( kk = 0; kk < word_1998C0; ++kk )
  {
    if ( a5 == word_19999A && (v48 = (_BYTE *)(33 * kk + dword_192844), *v48 == 8) && v48[6] && v48[1] <= 5u )
    {
      sub_646F9((uint8_t)v48[1]);
    }
    else
    {
      v49 = dword_192844 + 33 * kk;
      if ( *(_BYTE *)(v49 + 6) && *(int16_t *)(v49 + 2) != -1 )
      {
        if ( *(_BYTE *)v49 == 8 )
          sub_6474B(*(uint8_t *)(v49 + 1));
        v50 = *(int16_t *)(dword_197F9C + 129 * *(int16_t *)(33 * kk + dword_192844 + 2) + 116);
        if ( v50 > -1 )
          sub_944A3(v50, (int)a3);
        sub_A163A(*(_WORD *)(33 * kk + dword_192844 + 2), (int)a3);
      }
    }
  }
  if ( (int16_t)v79 >= 1 && word_1998AC < 8 && word_19988E >= 10 && *(_BYTE *)(dword_197F9C + 129 * *a3 + 19) )
  {
    v79 = 1;
    sub_F9711(word_19988E, -1, word_1998AC);
  }
  if ( (int16_t)v79 <= -1 && word_19988E < 8 && word_1998AC >= 10 && *(_BYTE *)(dword_197F9C + 129 * *a1 + 19) )
  {
    v79 = -1;
    sub_F9711(word_1998AC, -1, word_19988E);
  }
  sub_40D40(a7, a8, a5, (int16_t)v69, v79);
  if ( word_199878 != -1 && !*(_BYTE *)(dword_192B18 + 361 * word_199878 + 10) )
  {
    v51 = 0;
    for ( mm = 0; mm < 49 && !v51; ++mm )
    {
      v53 = *(uint8_t *)(361 * word_199878 + dword_192B18 + mm + 310);
      v51 = v53;
    }
    if ( !v51 )
      sub_DCDAC((char *)(dword_192B18 + 361 * word_199878), 1);
  }
  v14 = v79;
  sub_107BA(&v58);
  return v14;
}
// 4037D: variable 'v16' is possibly undefined
// 40629: variable 'v17' is possibly undefined
// 17FC41: using guessed type int16_t word_17FC41;
// 192844: using guessed type int dword_192844;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;
// 199890: using guessed type int16_t word_199890;
// 1998A2: using guessed type int16_t word_1998A2;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998BE: using guessed type int16_t word_1998BE;
// 1998C0: using guessed type int16_t word_1998C0;
// 19999A: using guessed type int16_t word_19999A;
// 199CB4: using guessed type char byte_199CB4;
// 199EF6: using guessed type char byte_199EF6;


//----- (00040C2A) --------------------------------------------------------
int __fastcall sub_40C2A( int a1, int a2)
{
  int v3; // ecx
  int16_t v4; // dx
  int v5; // eax
  int result; // eax

  v3 = 33 * a1;
  if ( *(_WORD *)(v3 + dword_192844 + 9) == 7 )
    v4 = (int16_t)(a2 - (__CFSHL__(a2 >> 15, 2) + 4 * (a2 >> 15))) >> 2;
  else
    v4 = a2 - *(int16_t *)((char *)&word_17F6C1 + 59 * *(int16_t *)(v3 + dword_192844 + 9));
  if ( v4 < 0 )
    v4 = 0;
  v5 = dword_192844 + 33 * a1;
  *(_WORD *)(v5 + 31) += v4;
  if ( *(int16_t *)(v5 + 31) > 30000 )
    *(_WORD *)(v5 + 31) = 30000;
  result = dword_192844 + 33 * a1;
  if ( *(_WORD *)(result + 31) >= *(_WORD *)(result + 29) )
    *(_BYTE *)(result + 6) = 1;
  return result;
}
// 17F6C1: using guessed type int16_t word_17F6C1;
// 192844: using guessed type int dword_192844;


//----- (00040CC3) --------------------------------------------------------
char __fastcall sub_40CC3( int a1, char *a2)
{
  char *v2; // esi
  char result; // al
  char *v4; // esi
  char *v5; // esi
  _DWORD v6[5]; // [esp+0h] [ebp-14h] BYREF

  switch ( a1 )
  {
    case 8:
      v2 = aAntaran;
      goto LABEL_3;
    case 9:
      strcpy((char *)v6, "Guardian");
      break;
    case 10:
      v4 = aAmoeba;
      goto LABEL_7;
    case 11:
      v2 = aCrystal;
LABEL_3:
      v6[0] = *(_DWORD *)v2;
      v6[1] = *((_DWORD *)v2 + 1);
      break;
    case 12:
      v4 = aDragon;
LABEL_7:
      v6[0] = *(_DWORD *)v4;
      v5 = v4 + 4;
      LOWORD(v6[1]) = *(_WORD *)v5;
      BYTE2(v6[1]) = v5[2];
      break;
    case 13:
      strcpy((char *)v6, "Eel");
      break;
    case 14:
      strcpy((char *)v6, "Hydra");
      break;
    default:
      break;
  }
  strcpy(a2, (char *)v6);
  return result;
}


//----- (00040D40) --------------------------------------------------------
char __fastcall sub_40D40(char *a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v7; // edx
  int v8; // eax
  int16_t i; // dx
  int v10; // ebx
  uint8_t *v11; // eax
  int v12; // edx
  int v13; // eax
  int16_t v14; // cx
  char *v15; // esi
  char *v16; // edi
  _DWORD *v17; // edi
  char *v18; // edi
  char *v19; // edi
  char *v20; // edi
  char *v21; // edi
  char *v22; // edi
  char *v23; // edi
  char *v24; // edi
  char *v25; // edi
  char *v26; // edi
  char *v27; // edi
  char *v28; // edi
  int v29; // ecx
  char *v30; // edi
  char *v31; // edi
  char *v32; // esi
  char *v33; // edi
  char *v34; // edi
  char *v35; // esi
  char *v36; // edi
  char *v37; // edi
  char *v38; // edi
  char *v39; // edi
  char *v40; // esi
  char *v41; // edi
  char *v42; // edi
  char *v43; // esi
  char *v44; // edi
  char *v45; // edi
  int v46; // edx
  char *v47; // edi
  char *v48; // edi
  char *v49; // edi
  char *v50; // edi
  char *v51; // edi
  char *v52; // esi
  char *v53; // edi
  char *v54; // edi
  char *v55; // edi
  char *v56; // edi
  char *v57; // edi
  char *v58; // edi
  char *v59; // edi
  char *v60; // esi
  char *v61; // edi
  char *v62; // edi
  char *v63; // edi
  char *v64; // edi
  char *v65; // edi
  char *v66; // edi
  char *v67; // edi
  char *v68; // esi
  char *v69; // edi
  char *v70; // edi
  char *v71; // edi
  char *v72; // edi
  char *v73; // edi
  char *v74; // edi
  char *v75; // edi
  char *v76; // esi
  char *v77; // edi
  char *v78; // edi
  char *v79; // edi
  char *v80; // edi
  char *v81; // edi
  char *v82; // edi
  char *v83; // edi
  char *v84; // esi
  char *v85; // edi
  char *v86; // edi
  char *v87; // edi
  char *v88; // edi
  _DWORD *v89; // edi
  int v90; // eax
  char *v91; // edi
  char *v92; // edi
  char *v93; // edi
  char *v94; // edi
  char *v95; // edi
  char result; // al
  _DWORD *v97; // [esp-4h] [ebp-4Ah]
  _DWORD *v98; // [esp-4h] [ebp-4Ah]
  _DWORD *v99; // [esp-4h] [ebp-4Ah]
  _DWORD *v100; // [esp-4h] [ebp-4Ah]
  _DWORD *v101; // [esp-4h] [ebp-4Ah]
  _DWORD *v102; // [esp-4h] [ebp-4Ah]
  _DWORD *v103; // [esp-4h] [ebp-4Ah]
  _DWORD *v104; // [esp-4h] [ebp-4Ah]
  _DWORD *v105; // [esp-4h] [ebp-4Ah]
  _DWORD *v106; // [esp-4h] [ebp-4Ah]
  _DWORD *v107; // [esp-4h] [ebp-4Ah]
  _DWORD *v108; // [esp-4h] [ebp-4Ah]
  _DWORD *v109; // [esp-4h] [ebp-4Ah]
  char v110[80]; // [esp+0h] [ebp-46h] BYREF
  char v111[20]; // [esp+50h] [ebp+Ah] BYREF
  char v112[68]; // [esp+64h] [ebp+1Eh] BYREF
  _BYTE v113[12]; // [esp+A8h] [ebp+62h] BYREF
  _DWORD *v114; // [esp+B4h] [ebp+6Eh]
  int v115; // [esp+B8h] [ebp+72h]
  int v116; // [esp+BCh] [ebp+76h]
  int16_t v117; // [esp+C0h] [ebp+7Ah]

  v114 = a2;
  v117 = a4;
  v115 = -1;
  v116 = 1;
  v7 = 0;
  do
  {
    v8 = (int16_t)v7++;
    *(_WORD *)&v112[2 * v8 + 56] = 0;
    *(_WORD *)&v112[2 * v8 + 32] = 0;
    *(_WORD *)&v112[2 * v8 + 44] = 0;
    *(_WORD *)&v112[2 * v8 + 20] = 0;
  }
  while ( (int16_t)v7 <= 5 );
  for ( i = 1; i < word_1998C0; ++i )
  {
    HIWORD(v10) = HIWORD(dword_192844);
    v11 = (uint8_t *)(dword_192844 + 33 * i);
    if ( v11[1] > 5u )
    {
      LOWORD(v10) = v11[1];
      v115 = v10;
      LOWORD(v11) = v11[6] == 0;
      v116 = (int)v11;
    }
    else if ( *v11 == word_1998AC )
    {
      if ( v11[6] )
        ++*(_WORD *)&v112[2 * v11[1] + 32];
      else
        ++*(_WORD *)&v112[2 * v11[1] + 56];
    }
    else if ( v11[6] )
    {
      ++*(_WORD *)&v112[2 * v11[1] + 20];
    }
    else
    {
      ++*(_WORD *)&v112[2 * v11[1] + 44];
    }
  }
  v12 = 0;
  do
  {
    v13 = (int16_t)v12;
    *(_WORD *)&v112[2 * (int16_t)v12 + 56] += *(_WORD *)&v112[2 * (int16_t)v12 + 32];
    v14 = *(_WORD *)&v112[2 * (int16_t)v12++ + 20];
    *(_WORD *)&v112[2 * v13 + 44] += v14;
  }
  while ( (int16_t)v12 <= 5 );
  sub_58F1E(98, a1, 80);
  if ( a3 == word_19999A )
  {
    v15 = aAntares;
  }
  else if ( word_199878 == -1 )
  {
    v15 = (char *)(113 * a3 + dword_19306C);
  }
  else
  {
    v15 = (char *)sub_77B28(*(_WORD *)(dword_192B18 + 361 * word_199878 + 2));
  }
  v16 = a1 - 1;
  do
    ++v16;
  while ( *v16 );
  strcpy(v16, v15);
  if ( word_1998AC >= 8 )
    sub_40CC3(word_1998AC, v112);
  else
    strcpy(v112, (char *)(dword_197F98 + 3753 * word_1998AC + 21));
  if ( word_19988E >= 8 )
    sub_40CC3(word_19988E, v111);
  else
    strcpy(v111, (char *)(3753 * word_19988E + dword_197F98 + 21));
  v17 = v114;
  *v114 = *(_DWORD *)aX35;
  *((_WORD *)v17 + 2) = *(_WORD *)&aX35[4];
  v97 = v114;
  v18 = (char *)v114 - 1;
  do
    ++v18;
  while ( *v18 );
  strcpy(v18, v112);
  v19 = (char *)v97 - 1;
  do
    ++v19;
  while ( *v19 );
  strcpy(v19, aX255);
  v20 = (char *)v97 - 1;
  do
    ++v20;
  while ( *v20 );
  strcpy(v20, v111);
  v21 = (char *)v97 - 1;
  do
    ++v21;
  while ( *v21 );
  strcpy(v21, asc_178DD6);
  sub_58F1E(99, v110, 80);
  v22 = (char *)v97 - 1;
  do
    ++v22;
  while ( *v22 );
  strcpy(v22, v110);
  v23 = (char *)v97 - 1;
  do
    ++v23;
  while ( *v23 );
  strcpy(v23, aX25);
  sub_58F1E(100, v110, 80);
  v24 = (char *)v97 - 1;
  do
    ++v24;
  while ( *v24 );
  strcpy(v24, v110);
  v25 = (char *)v97 - 1;
  do
    ++v25;
  while ( *v25 );
  strcpy(v25, aX227);
  sub_58F1E(99, v110, 80);
  v26 = (char *)v97 - 1;
  do
    ++v26;
  while ( *v26 );
  strcpy(v26, v110);
  v27 = (char *)v97 - 1;
  do
    ++v27;
  while ( *v27 );
  strcpy(v27, aX21);
  sub_58F1E(100, v110, 80);
  v28 = (char *)v97 - 1;
  do
    ++v28;
  while ( *v28 );
  strcpy(v28, v110);
  v29 = 0;
  v30 = (char *)v97 - 1;
  do
    ++v30;
  while ( *v30 );
  strcpy(v30, asc_178DD6);
  do
  {
    if ( *(int16_t *)&v112[2 * (int16_t)v29 + 44] + *(int16_t *)&v112[2 * (int16_t)v29 + 56] > 0 )
    {
      v98 = v114;
      v31 = (char *)v114 - 1;
      do
        ++v31;
      while ( *v31 );
      strcpy(v31, aX18);
      if ( *(_WORD *)&v112[2 * (int16_t)v29 + 56] )
      {
        v32 = v113;
        itoa(*(int16_t *)&v112[2 * (int16_t)v29 + 56], v113, 10, v29);
      }
      else
      {
        v32 = asc_178DF3;
      }
      v33 = (char *)v98 - 1;
      do
        ++v33;
      while ( *v33 );
      strcpy(v33, v32);
      v99 = v114;
      v34 = (char *)v114 - 1;
      do
        ++v34;
      while ( *v34 );
      strcpy(v34, aX80);
      if ( *(_WORD *)&v112[2 * (int16_t)v29 + 32] )
      {
        v35 = v113;
        itoa(*(int16_t *)&v112[2 * (int16_t)v29 + 32], v113, 10, v29);
      }
      else
      {
        v35 = asc_178DF3;
      }
      v36 = (char *)v99 - 1;
      do
        ++v36;
      while ( *v36 );
      strcpy(v36, v35);
      v100 = v114;
      v37 = (char *)v114 - 1;
      do
        ++v37;
      while ( *v37 );
      strcpy(v37, aX120);
      v38 = (char *)v100 - 1;
      do
        ++v38;
      while ( *v38 );
      strcpy(v38, (char *)*(&off_18003E + 9 * (int16_t)v29));
      v39 = (char *)v100 - 1;
      do
        ++v39;
      while ( *v39 );
      strcpy(v39, aX250);
      if ( *(_WORD *)&v112[2 * (int16_t)v29 + 44] )
      {
        v40 = v113;
        itoa(*(int16_t *)&v112[2 * (int16_t)v29 + 44], v113, 10, v29);
      }
      else
      {
        v40 = asc_178DF3;
      }
      v41 = (char *)v100 - 1;
      do
        ++v41;
      while ( *v41 );
      strcpy(v41, v40);
      v101 = v114;
      v42 = (char *)v114 - 1;
      do
        ++v42;
      while ( *v42 );
      strcpy(v42, aX312);
      if ( *(_WORD *)&v112[2 * (int16_t)v29 + 20] )
      {
        v43 = v113;
        itoa(*(int16_t *)&v112[2 * (int16_t)v29 + 20], v113, 10, v29);
      }
      else
      {
        v43 = asc_178DF3;
      }
      v44 = (char *)v101 - 1;
      do
        ++v44;
      while ( *v44 );
      strcpy(v44, v43);
      v45 = (char *)v114 - 1;
      do
        ++v45;
      while ( *v45 );
      strcpy(v45, asc_178DD6);
    }
    ++v29;
  }
  while ( (int16_t)v29 <= 5 );
  v46 = (int16_t)v115;
  if ( (int16_t)v115 > -1 )
  {
    v102 = v114;
    v47 = (char *)v114 - 1;
    do
      ++v47;
    while ( *v47 );
    strcpy(v47, aX120);
    v48 = (char *)v102 - 1;
    do
      ++v48;
    while ( *v48 );
    strcpy(v48, (char *)*(&off_18003A + 9 * v46));
    v49 = (char *)v102 - 1;
    do
      ++v49;
    while ( *v49 );
    strcpy(v49, aX250);
    v50 = (char *)v102 - 1;
    do
      ++v50;
    while ( *v50 );
    strcpy(v50, a1_0);
    v51 = (char *)v102 - 1;
    do
      ++v51;
    while ( *v51 );
    strcpy(v51, aX312);
    if ( (_WORD)v116 )
      v52 = asc_178DF3;
    else
      v52 = a1_0;
    v53 = (char *)v102 - 1;
    do
      ++v53;
    while ( *v53 );
    strcpy(v53, v52);
    v54 = (char *)v114 - 1;
    do
      ++v54;
    while ( *v54 );
    strcpy(v54, asc_178DD6);
  }
  if ( (v117 & 1) != 0 )
  {
    v103 = v114;
    v55 = (char *)v114 - 1;
    do
      ++v55;
    while ( *v55 );
    strcpy(v55, aX120);
    v56 = (char *)v103 - 1;
    do
      ++v56;
    while ( *v56 );
    strcpy(v56, (char *)off_17ED2B);
    v57 = (char *)v103 - 1;
    do
      ++v57;
    while ( *v57 );
    strcpy(v57, aX250);
    v58 = (char *)v103 - 1;
    do
      ++v58;
    while ( *v58 );
    strcpy(v58, a1_0);
    v59 = (char *)v103 - 1;
    do
      ++v59;
    while ( *v59 );
    strcpy(v59, aX312);
    if ( (byte_199EF6 & 1) != 0 )
      v60 = asc_178DF3;
    else
      v60 = a1_0;
    v61 = (char *)v103 - 1;
    do
      ++v61;
    while ( *v61 );
    strcpy(v61, v60);
    v62 = (char *)v114 - 1;
    do
      ++v62;
    while ( *v62 );
    strcpy(v62, asc_178DD6);
  }
  if ( (v117 & 2) != 0 )
  {
    v104 = v114;
    v63 = (char *)v114 - 1;
    do
      ++v63;
    while ( *v63 );
    strcpy(v63, aX120);
    v64 = (char *)v104 - 1;
    do
      ++v64;
    while ( *v64 );
    strcpy(v64, (char *)off_17ED3E);
    v65 = (char *)v104 - 1;
    do
      ++v65;
    while ( *v65 );
    strcpy(v65, aX250);
    v66 = (char *)v104 - 1;
    do
      ++v66;
    while ( *v66 );
    strcpy(v66, a1_0);
    v67 = (char *)v104 - 1;
    do
      ++v67;
    while ( *v67 );
    strcpy(v67, aX312);
    if ( (byte_199EF6 & 2) != 0 )
      v68 = asc_178DF3;
    else
      v68 = a1_0;
    v69 = (char *)v104 - 1;
    do
      ++v69;
    while ( *v69 );
    strcpy(v69, v68);
    v70 = (char *)v114 - 1;
    do
      ++v70;
    while ( *v70 );
    strcpy(v70, asc_178DD6);
  }
  if ( (v117 & 8) != 0 )
  {
    v105 = v114;
    v71 = (char *)v114 - 1;
    do
      ++v71;
    while ( *v71 );
    strcpy(v71, aX120);
    v72 = (char *)v105 - 1;
    do
      ++v72;
    while ( *v72 );
    strcpy(v72, (char *)off_17EEBA);
    v73 = (char *)v105 - 1;
    do
      ++v73;
    while ( *v73 );
    strcpy(v73, aX250);
    v74 = (char *)v105 - 1;
    do
      ++v74;
    while ( *v74 );
    strcpy(v74, a1_0);
    v75 = (char *)v105 - 1;
    do
      ++v75;
    while ( *v75 );
    strcpy(v75, aX312);
    if ( (byte_199EF6 & 8) != 0 )
      v76 = asc_178DF3;
    else
      v76 = a1_0;
    v77 = (char *)v105 - 1;
    do
      ++v77;
    while ( *v77 );
    strcpy(v77, v76);
    v78 = (char *)v114 - 1;
    do
      ++v78;
    while ( *v78 );
    strcpy(v78, asc_178DD6);
  }
  if ( (v117 & 4) != 0 )
  {
    v106 = v114;
    v79 = (char *)v114 - 1;
    do
      ++v79;
    while ( *v79 );
    strcpy(v79, aX120);
    v80 = (char *)v106 - 1;
    do
      ++v80;
    while ( *v80 );
    strcpy(v80, (char *)off_17EE5B);
    v81 = (char *)v106 - 1;
    do
      ++v81;
    while ( *v81 );
    strcpy(v81, aX250);
    v82 = (char *)v106 - 1;
    do
      ++v82;
    while ( *v82 );
    strcpy(v82, a1_0);
    v83 = (char *)v106 - 1;
    do
      ++v83;
    while ( *v83 );
    strcpy(v83, aX312);
    if ( (byte_199EF6 & 4) != 0 )
      v84 = asc_178DF3;
    else
      v84 = a1_0;
    v85 = (char *)v106 - 1;
    do
      ++v85;
    while ( *v85 );
    strcpy(v85, v84);
    v86 = (char *)v114 - 1;
    do
      ++v86;
    while ( *v86 );
    strcpy(v86, asc_178DD6);
  }
  if ( a5 <= 0 )
  {
    if ( a5 >= 0 )
    {
      v109 = v114;
      v93 = (char *)v114 - 1;
      do
        ++v93;
      while ( *v93 );
      strcpy(v93, asc_178E12);
      v94 = (char *)v109 - 1;
      do
        ++v94;
      while ( *v94 );
      strcpy(v94, byte_178E15);
      v89 = v109;
      v90 = 103;
    }
    else
    {
      v108 = v114;
      v91 = (char *)v114 - 1;
      do
        ++v91;
      while ( *v91 );
      strcpy(v91, asc_178E12);
      v92 = (char *)v108 - 1;
      do
        ++v92;
      while ( *v92 );
      strcpy(v92, byte_178E15);
      v89 = v108;
      v90 = 102;
    }
  }
  else
  {
    v107 = v114;
    v87 = (char *)v114 - 1;
    do
      ++v87;
    while ( *v87 );
    strcpy(v87, asc_178E12);
    v88 = (char *)v107 - 1;
    do
      ++v88;
    while ( *v88 );
    strcpy(v88, byte_178E15);
    v89 = v107;
    v90 = 101;
  }
  sub_58F1E(v90, v110, 80);
  v95 = (char *)v89 - 1;
  do
    ++v95;
  while ( *v95 );
  strcpy(v95, v110);
  return result;
}
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 17ED2B: using guessed type _UNKNOWN *off_17ED2B;
// 17ED3E: using guessed type _UNKNOWN *off_17ED3E;
// 17EE5B: using guessed type _UNKNOWN *off_17EE5B;
// 17EEBA: using guessed type _UNKNOWN *off_17EEBA;
// 18003A: using guessed type _UNKNOWN *off_18003A;
// 18003E: using guessed type _UNKNOWN *off_18003E;
// 192844: using guessed type int dword_192844;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;
// 19999A: using guessed type int16_t word_19999A;
// 199EF6: using guessed type char byte_199EF6;


//----- (000416CF) --------------------------------------------------------
char *__fastcall sub_416CF(int16_t *a1, int a2, int a3, int a4, int a5, int a6)
{
  int16_t v6; // di
  int16_t v7; // cx
  int16_t v8; // ax
  int16_t v9; // ax
  int16_t v10; // si
  char *v11; // eax
  int16_t v12; // ax
  int16_t v13; // bx
  int v14; // ebx
  char v15; // al
  int v16; // eax
  int v17; // eax
  int16_t v18; // bx
  int16_t i; // bx
  int v20; // eax
  int v21; // eax
  int v22; // ebx
  int16_t v23; // di
  int v24; // eax
  int v25; // ebx
  int v26; // edx
  int16_t v27; // ax
  _WORD *v28; // ebx
  int v29; // eax
  int v30; // edx
  int16_t v31; // ax
  int v32; // ebx
  int16_t v33; // ax
  int v34; // ebx
  int16_t v35; // ax
  int v36; // edx
  int v37; // eax
  int v38; // ebx
  char *result; // eax
  int16_t v40; // cx
  int v41; // ebx
  char v42; // al
  int v43; // eax
  int16_t v44; // ax
  char v45; // al
  int v46; // eax
  char v47; // al
  int v48; // eax
  int v52; // [esp+10h] [ebp-48h]
  int v53; // [esp+14h] [ebp-44h]
  int16_t v54; // [esp+20h] [ebp-38h]
  int v55; // [esp+24h] [ebp-34h]
  char *v56; // [esp+28h] [ebp-30h]
  int16_t v57; // [esp+2Ch] [ebp-2Ch]
  int16_t v58; // [esp+30h] [ebp-28h]
  int16_t v59; // [esp+34h] [ebp-24h]
  int16_t v60; // [esp+38h] [ebp-20h]
  int16_t v61; // [esp+3Ch] [ebp-1Ch]
  int16_t v62; // [esp+40h] [ebp-18h]
  int16_t v63; // [esp+44h] [ebp-14h]
  int16_t v64; // [esp+48h] [ebp-10h]
  int16_t v65; // [esp+4Ch] [ebp-Ch]
  int16_t v66; // [esp+50h] [ebp-8h]
  int16_t v67; // [esp+54h] [ebp-4h]

  v60 = 0;
  v67 = 0;
  v64 = 0;
  v66 = 0;
  v6 = 0;
  if ( a2 )
    v7 = *(char *)(dword_197F9C + 129 * *a1 + 99);
  else
    v7 = *(char *)(361 * word_199878 + dword_192B18);
  sub_56B26(v7);
  v59 = v8;
  sub_568EB(v7);
  v10 = v9;
  v57 = sub_56CA2(v7);
  v58 = sub_5679E(v7);
  LOWORD(v11) = sub_5EB39(v7);
  v56 = v11;
  v55 = 10 * (sub_56726(v7) - 1);
  if ( v7 < 8 )
    LOWORD(v55) = *(char *)(dword_197F98 + 3753 * v7 + 2213) + (_WORD)v55;
  sub_5685F(v7);
  v63 = 0;
  v62 = *(int16_t *)((char *)&word_17F642 + 15 * v12);
  while ( v63 < a2 )
  {
    v13 = a1[v63];
    v61 = v13;
    v53 = 129 * v13;
    if ( !*(_BYTE *)(v53 + dword_197F9C + 17) )
    {
      v65 = *(uint8_t *)(v53 + dword_197F9C + 16);
      v54 = sub_56D3A(v7, v65);
      sub_5794B(v13);
      v14 = dword_192844 + 33 * word_1998C0;
      v15 = *(_BYTE *)(v53 + dword_197F9C + 99);
      *(_BYTE *)(v14 + 6) = 0;
      *(_WORD *)(v14 + 4) = -1;
      *(_BYTE *)v14 = v15;
      *(_WORD *)(v14 + 13) = v10;
      *(_WORD *)(v14 + 2) = v61;
      *(_BYTE *)(v14 + 1) = v65;
      *(_WORD *)(v14 + 11) = v59;
      *(_WORD *)(v14 + 15) = v57;
      *(_WORD *)(v14 + 17) = v54;
      *(_WORD *)(v14 + 9) = v58;
      if ( *(_BYTE *)v14 > 9u )
        LOWORD(v16) = word_180038[18 * v65];
      else
        v16 = word_180038[18 * v65] * (v62 + 100) / 100;
      *(_WORD *)(v14 + 29) = v16;
      v17 = 33 * word_1998C0 + dword_192844;
      *(_WORD *)(v17 + 19) = 0;
      v18 = word_180036[18 * v65];
      *(_WORD *)(v17 + 27) = 0;
      *(_WORD *)(v17 + 25) = 0;
      *(_WORD *)(v17 + 23) = (_WORD)v56;
      *(_WORD *)(v17 + 21) = v55 + v18;
      for ( i = 0; i < 39; ++i )
      {
        v52 = 129 * v61;
        if ( (uint16_t)sub_1276F0(v52 + dword_197F9C + 23, i)
          && !(uint16_t)sub_1276F0(v52 + dword_197F9C + 118, i) )
        {
          v20 = 47 * i;
          switch ( byte_17EF0C[v20] )
          {
            case 1:
              if ( *(int16_t *)((char *)&word_17EF0D + 47 * i) > v60 )
                v60 = *(int16_t *)((char *)&word_17EF0D + 47 * i);
              continue;
            case 2:
              goto LABEL_51;
            case 3:
              if ( *(int16_t *)((char *)&word_17EF0D + 47 * i) > v66 )
                v66 = *(int16_t *)((char *)&word_17EF0D + 47 * i);
              continue;
            case 4:
              goto LABEL_44;
            case 5:
              if ( *(int16_t *)((char *)&word_17EF0D + 47 * i) > v64 )
                v64 = *(int16_t *)((char *)&word_17EF0D + 47 * i);
              continue;
            case 6:
              if ( *(int16_t *)((char *)&word_17EF0D + 47 * i) > v66 )
                v66 = *(int16_t *)((char *)&word_17EF0D + 47 * i);
              v20 = 47 * i;
LABEL_44:
              if ( v6 < *(int16_t *)((char *)&word_17EF0D + v20) )
                v6 = *(int16_t *)((char *)&word_17EF0D + v20);
              break;
            case 7:
              if ( *(int16_t *)((char *)&word_17EF0D + 47 * i) > v64 )
                v64 = *(int16_t *)((char *)&word_17EF0D + 47 * i);
              v20 = 47 * i;
LABEL_51:
              if ( *(int16_t *)((char *)&word_17EF0D + v20) > v67 )
                v67 = *(int16_t *)((char *)&word_17EF0D + v20);
              break;
            default:
              continue;
          }
        }
      }
      v21 = 33 * word_1998C0 + dword_192844;
      *(_WORD *)(v21 + 21) += a3 + v66;
      *(_WORD *)(v21 + 27) += a4 + v64;
      *(_WORD *)(v21 + 23) += a5 + v60;
      *(_WORD *)(v21 + 25) += a4 + v67;
      v22 = 129 * v61 + dword_197F9C;
      *(_WORD *)(v21 + 19) += v6;
      *(_WORD *)(v21 + 7) = *(_WORD *)(v22 + 116);
      LOWORD(v22) = *(_WORD *)(v22 + 125);
      ++word_1998C0;
      *(_WORD *)(v21 + 31) = v22;
    }
    ++v63;
  }
  v23 = sub_56D3A(v7, 5);
  v24 = dword_192844;
  *(_BYTE *)(dword_192844 + 1) = 4;
  *(_WORD *)(v24 + 2) = -1;
  *(_WORD *)(v24 + 4) = -1;
  *(_WORD *)(v24 + 31) = 0;
  *(_WORD *)(v24 + 29) = 0;
  *(_WORD *)(v24 + 11) = 0;
  *(_WORD *)(v24 + 13) = 0;
  *(_WORD *)(v24 + 15) = 0;
  *(_WORD *)(v24 + 17) = 0;
  *(_WORD *)(v24 + 19) = 0;
  v25 = word_199878;
  *(_WORD *)(v24 + 21) = 0;
  if ( v25 == -1 || v7 != word_19988E )
  {
    result = (char *)dword_192844;
    *(_BYTE *)(dword_192844 + 6) = 2;
  }
  else
  {
    v26 = dword_192B18;
    LOBYTE(v26) = *(_BYTE *)(dword_192B18 + 361 * v25);
    *(_BYTE *)v24 = v26;
    v27 = sub_42371(v24, v26);
    v28 = (_WORD *)dword_192844;
    *(_WORD *)(dword_192844 + 29) = v27;
    v29 = 361 * word_199878;
    v30 = dword_192B18;
    v28[1] = -1;
    if ( *(_BYTE *)(v30 + v29 + 338) )
    {
      v31 = 10 * *(_WORD *)((char *)v28 + 21);
      *(_WORD *)((char *)v28 + 19) += 10;
      *(_WORD *)((char *)v28 + 21) = v31;
    }
    if ( *(_BYTE *)(361 * word_199878 + dword_192B18 + 333) )
    {
      v32 = dword_192844;
      v33 = 30 * *(_WORD *)(dword_192844 + 21);
      *(_WORD *)(dword_192844 + 19) += 30;
      *(_WORD *)(v32 + 21) = v33;
    }
    if ( *(_BYTE *)(dword_192B18 + 361 * word_199878 + 334) )
    {
      v34 = dword_192844;
      v35 = 20 * *(_WORD *)(dword_192844 + 21);
      *(_WORD *)(dword_192844 + 19) += 20;
      *(_WORD *)(v34 + 21) = v35;
    }
    v36 = 361 * word_199878;
    v37 = dword_192844;
    v38 = dword_192B18;
    *(_WORD *)(dword_192844 + 11) = 0;
    if ( *(_BYTE *)(v36 + v38 + 336) )
    {
      ++byte_199EF6;
      *(_WORD *)(v37 + 11) = v59;
    }
    if ( *(_BYTE *)(dword_192B18 + 361 * word_199878 + 357) )
    {
      byte_199EF6 += 8;
      *(_WORD *)(dword_192844 + 17) = v23;
    }
    if ( *(_BYTE *)(dword_192B18 + 361 * word_199878 + 337) )
    {
      byte_199EF6 += 2;
      *(_WORD *)(dword_192844 + 13) = v10;
    }
    if ( *(_BYTE *)(dword_192B18 + 361 * word_199878 + 352) )
      byte_199EF6 += 4;
    if ( byte_199EF6 )
      *(_BYTE *)(dword_192844 + 6) = 0;
    else
      *(_BYTE *)(dword_192844 + 6) = 2;
    result = (char *)(dword_192B18 + 361 * word_199878);
    v40 = word_1998C0 + 1;
    if ( result[350] )
    {
      v41 = dword_192844 + 33 * word_1998C0;
      v42 = *result;
      *(_WORD *)(v41 + 2) = -1;
      *(_BYTE *)(v41 + 1) = 6;
      *(_BYTE *)(v41 + 6) = 0;
      *(_WORD *)(v41 + 4) = -1;
      *(_BYTE *)v41 = v42;
      *(_WORD *)(v41 + 13) = v10;
      *(_WORD *)(v41 + 17) = v23;
      *(_WORD *)(v41 + 11) = v59;
      *(_WORD *)(v41 + 15) = v57;
      *(_WORD *)(v41 + 9) = v58;
      v43 = word_180110 * (v62 + 100) / 100;
      *(_WORD *)(v41 + 19) = 0;
      *(_WORD *)(v41 + 29) = v43;
      v44 = word_18010E;
LABEL_56:
      *(_WORD *)(v41 + 31) = 0;
      *(_WORD *)(v41 + 21) = v44;
      result = v56;
      word_1998C0 = v40;
      *(_WORD *)(v41 + 23) = (_WORD)v56;
      return result;
    }
    if ( result[318] )
    {
      v41 = dword_192844 + 33 * word_1998C0;
      v45 = *result;
      *(_WORD *)(v41 + 2) = -1;
      *(_BYTE *)(v41 + 1) = 7;
      *(_BYTE *)(v41 + 6) = 0;
      *(_WORD *)(v41 + 4) = -1;
      *(_BYTE *)v41 = v45;
      *(_WORD *)(v41 + 13) = v10;
      *(_WORD *)(v41 + 17) = v23;
      *(_WORD *)(v41 + 11) = v59;
      *(_WORD *)(v41 + 15) = v57;
      *(_WORD *)(v41 + 9) = v58;
      v46 = word_180134 * (v62 + 100) / 100;
      *(_WORD *)(v41 + 19) = 0;
      *(_WORD *)(v41 + 29) = v46;
      v44 = word_180132;
      goto LABEL_56;
    }
    if ( result[351] )
    {
      v41 = dword_192844 + 33 * word_1998C0;
      v47 = *result;
      *(_WORD *)(v41 + 2) = -1;
      *(_BYTE *)(v41 + 1) = 8;
      *(_BYTE *)(v41 + 6) = 0;
      *(_WORD *)(v41 + 4) = -1;
      *(_BYTE *)v41 = v47;
      *(_WORD *)(v41 + 13) = v10;
      *(_WORD *)(v41 + 17) = v23;
      *(_WORD *)(v41 + 11) = v59;
      *(_WORD *)(v41 + 15) = v57;
      *(_WORD *)(v41 + 9) = v58;
      v48 = word_180158 * (v62 + 100) / 100;
      *(_WORD *)(v41 + 19) = 0;
      *(_WORD *)(v41 + 29) = v48;
      v44 = word_180156;
      goto LABEL_56;
    }
  }
  return result;
}
// 41734: variable 'v8' is possibly undefined
// 4173E: variable 'v9' is possibly undefined
// 4175B: variable 'v11' is possibly undefined
// 41793: variable 'v12' is possibly undefined
// 17EF0D: using guessed type int16_t word_17EF0D;
// 17F642: using guessed type int16_t word_17F642;
// 180036: using guessed type int16_t word_180036[];
// 180038: using guessed type int16_t word_180038[];
// 18010E: using guessed type int16_t word_18010E;
// 180110: using guessed type int16_t word_180110;
// 180132: using guessed type int16_t word_180132;
// 180134: using guessed type int16_t word_180134;
// 180156: using guessed type int16_t word_180156;
// 180158: using guessed type int16_t word_180158;
// 192844: using guessed type int dword_192844;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;
// 1998C0: using guessed type int16_t word_1998C0;
// 199EF6: using guessed type char byte_199EF6;


//----- (00041E22) --------------------------------------------------------
void sub_41E22()
{
  int16_t v0; // bx
  int16_t v1; // di
  int16_t v2; // [esp+0h] [ebp-8h]

  v0 = 1;
  v1 = 0;
  while ( 1 )
  {
    if ( *(_BYTE *)(*(int16_t *)((char *)&word_17F63E + 15 * v0) + dword_197F98 + 3753 * v2 + 279) == 3
      && (uint8_t)byte_17F646[15 * v0] > v1 )
    {
      v1 = (uint8_t)byte_17F646[15 * v0];
    }
    v0 += 2;
    if ( v0 >= 7 )
      JUMPOUT(0x41E82);
  }
}
// 41E81: control flows out of bounds to 41E82
// 41E4E: variable 'v2' is possibly undefined
// 17F63E: using guessed type int16_t word_17F63E;
// 197F98: using guessed type int dword_197F98;


//----- (00041E88) --------------------------------------------------------
int16_t __fastcall sub_41E88( int a1)
{
  int16_t v1; // bx
  int16_t v2; // si
  int16_t i; // dx
  uint8_t *v4; // eax
  int v5; // eax
  _WORD v7[503]; // [esp+0h] [ebp-3EEh]

  v1 = 0;
  v2 = *(uint8_t *)(dword_192844 + 33 * a1);
  for ( i = 1; i < word_1998C0; ++i )
  {
    v4 = (uint8_t *)(33 * i + dword_192844);
    if ( *v4 != v2 && !v4[6] )
    {
      v5 = v1++;
      v7[v5 + 1] = i;
    }
  }
  if ( v1 )
    return v7[sub_1247A0(v1)];
  if ( v2 != word_1998AC || word_199878 == -1 || *(_BYTE *)(dword_192844 + 6) )
    return -1;
  return 0;
}
// 192844: using guessed type int dword_192844;
// 199878: using guessed type int16_t word_199878;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00041F20) --------------------------------------------------------
int __fastcall sub_41F20( int a1)
{
  int v1; // ecx
  int v2; // edx
  int16_t v3; // si
  int16_t v4; // di
  uint8_t *v5; // eax

  v1 = -1;
  v2 = 1;
  v3 = 0;
  v4 = *(uint8_t *)(dword_192844 + 33 * a1);
  while ( (int16_t)v2 < word_1998C0 )
  {
    v5 = (uint8_t *)(33 * (int16_t)v2 + dword_192844);
    if ( *v5 != v4 && !v5[6] && (int16_t)(*(_WORD *)(v5 + 29) - *(_WORD *)(v5 + 31)) > v3 )
    {
      v1 = v2;
      v3 = *(_WORD *)(v5 + 29) - *(_WORD *)(v5 + 31);
    }
    ++v2;
  }
  return v1;
}
// 192844: using guessed type int dword_192844;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00041F80) --------------------------------------------------------
void __fastcall sub_41F80( int a1, int a2)
{
  int16_t v3; // cx
  int v4; // ebx
  int v5; // edx
  int16_t v6; // bx
  int16_t v7; // di
  int v8; // eax
  int v9; // edi
  _BYTE *v10; // eax
  int v11; // eax
  int v12; // [esp+4h] [ebp-10h]
  int v13; // [esp+Ch] [ebp-8h]
  int16_t v14; // [esp+10h] [ebp-4h]

  v3 = a2;
  v4 = 33 * a2;
  v5 = 33 * a1;
  v6 = *(_WORD *)(v4 + dword_192844 + 19);
  v7 = *(_WORD *)(v5 + dword_192844 + 11);
  LOWORD(v8) = sub_57651(*(uint8_t *)(v5 + dword_192844 + 1));
  v13 = v8;
  if ( v7 > 0 && (int16_t)v8 > 0 )
  {
    LOWORD(v9) = word_17F819[14 * v7];
    if ( *(int16_t *)(v5 + dword_192844 + 27) > 0 )
      v9 = (int16_t)v9 * (*(int16_t *)(v5 + dword_192844 + 27) + 100) / 100;
    v12 = 33 * a1;
    if ( *(_BYTE *)(v12 + dword_192844) >= 8u )
    {
      v6 -= 70;
    }
    else
    {
      v10 = (_BYTE *)(dword_197F98 + 3753 * *(uint8_t *)(v12 + dword_192844));
      if ( v10[439] == 3 )
      {
        v6 -= 70;
      }
      else if ( v10[395] == 3 )
      {
        v6 -= 40;
      }
      else if ( v10[460] == 3 )
      {
        v6 -= 20;
      }
    }
    do
    {
      v14 = sub_1247A0(0x64u);
      if ( v14 > 95 )
        v14 = 1000;
      if ( v6 <= v14 )
      {
        sub_40C2A(v3, v9);
        v11 = dword_192844 + 33 * v3;
        if ( *(_WORD *)(v11 + 31) >= *(_WORD *)(v11 + 29) )
        {
          *(_BYTE *)(v11 + 6) = 1;
          v3 = sub_41E88(a1);
        }
      }
      --v13;
    }
    while ( (int16_t)v13 > 0 && v3 != -1 );
  }
  JUMPOUT(0x3FEEC);
}
// 420BB: control flows out of bounds to 3FEEC
// 41FB1: variable 'v8' is possibly undefined
// 17F819: using guessed type int16_t word_17F819[];
// 192844: using guessed type int dword_192844;
// 197F98: using guessed type int dword_197F98;


//----- (000420C0) --------------------------------------------------------
int __fastcall sub_420C0( int a1)
{
  int result; // eax
  int16_t v2; // dx
  int v3; // ebx
  int v4; // eax
  int16_t v5; // cx
  int16_t v6; // si
  int16_t v7; // ax

  result = dword_192844 + 33 * a1;
  v3 = 36 * *(uint8_t *)(result + 1);
  v2 = *(_WORD *)(result + 15);
  LOWORD(v3) = *(int16_t *)((char *)word_180034 + v3);
  if ( v2 > 0 && (int16_t)v3 > 0 )
  {
    v4 = 14 * v2;
    v5 = word_17F817[v4];
    v6 = word_17F819[v4];
    do
    {
      v7 = sub_1247A0(v6 - v5 + 1);
      sub_40C2A(0, v5 + v7 - 1);
      result = dword_192844;
      if ( *(_WORD *)(dword_192844 + 31) >= *(_WORD *)(dword_192844 + 29) )
        *(_BYTE *)(dword_192844 + 6) = 1;
      --v3;
    }
    while ( (int16_t)v3 > 0 );
  }
  return result;
}
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 180034: using guessed type int16_t word_180034[];
// 192844: using guessed type int dword_192844;


//----- (0004213B) --------------------------------------------------------
int __fastcall sub_4213B( int a1)
{
  int16_t i; // bx
  int result; // eax

  for ( i = 0; i < 4; ++i )
    result = sub_40C2A(a1, word_17FC41);
  return result;
}
// 17FC41: using guessed type int16_t word_17FC41;


//----- (0004215C) --------------------------------------------------------
void __fastcall sub_4215C( int a1, int a2)
{
  int v4; // edx
  int16_t v5; // cx
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int16_t v10; // ax
  int v11; // [esp+0h] [ebp-8h]

  v4 = 33 * a1;
  v5 = *(_WORD *)(v4 + dword_192844 + 17);
  LOWORD(v6) = sub_5765D(*(uint8_t *)(v4 + dword_192844 + 1));
  v7 = v6;
  if ( v5 == 37 )
  {
    v8 = ((int16_t)v6 + 1) / 2;
  }
  else
  {
    if ( v5 != 38 )
    {
LABEL_6:
      if ( v5 > 0 && (int16_t)v7 > 0 )
      {
        do
        {
          v9 = 14 * v5;
          v11 = word_17F817[v9];
          v10 = sub_1247A0(word_17F819[v9] - v11 + 1);
          sub_40C2A(a2, v11 + v10 - 1);
          if ( *(_BYTE *)(33 * a2 + dword_192844 + 6) == 1 )
            a2 = sub_41E88(a1);
          --v7;
        }
        while ( (int16_t)v7 > 0 && a2 != -1 );
      }
      JUMPOUT(0x3FEEC);
    }
    v8 = ((int16_t)v6 + 3 - (__CFSHL__(((int16_t)v6 + 3) >> 31, 2) + 4 * (((int16_t)v6 + 3) >> 31))) >> 2;
  }
  v7 = v8;
  goto LABEL_6;
}
// 4221A: control flows out of bounds to 3FEEC
// 42180: variable 'v6' is possibly undefined
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 192844: using guessed type int dword_192844;


//----- (0004221F) --------------------------------------------------------
void __fastcall sub_4221F( int a1, int a2)
{
  int16_t v3; // bx
  int v4; // eax
  int16_t v5; // dx
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int16_t v10; // ax
  int v11; // [esp+8h] [ebp-Ch]
  int v12; // [esp+8h] [ebp-Ch]
  int v13; // [esp+Ch] [ebp-8h]
  int16_t v14; // [esp+10h] [ebp-4h]

  v3 = a2;
  v4 = dword_192844 + 33 * a1;
  v6 = 36 * *(uint8_t *)(v4 + 1);
  v11 = 33 * a2;
  v5 = *(_WORD *)(v4 + 13);
  v14 = 40 - (*(_WORD *)(v4 + 23) - *(_WORD *)(v11 + dword_192844 + 21));
  LOWORD(v6) = *(int16_t *)((char *)word_18002E + v6);
  if ( v14 > 95 )
    v14 = 95;
  if ( v5 > 0 && (int16_t)v6 > 0 )
  {
    v7 = 14 * v5;
    v8 = word_17F817[v7];
    v13 = word_17F819[v7];
    v9 = dword_192844 + 33 * a1;
    if ( *(int16_t *)(v9 + 25) > 0 )
    {
      v12 = *(int16_t *)(v9 + 25) + 100;
      v8 = v8 * v12 / 100;
      v13 = v12 * v13 / 100;
    }
    do
    {
      if ( (int16_t)sub_1247A0(0x64u) >= v14 )
      {
        v10 = sub_1247A0(v13 - v8 + 1);
        sub_40C2A(v3, v8 + v10 - 1);
        if ( *(_BYTE *)(33 * v3 + dword_192844 + 6) == 1 )
          v3 = sub_41E88(a1);
      }
      --v6;
    }
    while ( (int16_t)v6 > 0 && v3 != -1 );
  }
  JUMPOUT(0x3FEEC);
}
// 42347: control flows out of bounds to 3FEEC
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 18002E: using guessed type int16_t word_18002E[];
// 192844: using guessed type int dword_192844;


//----- (00042371) --------------------------------------------------------
int __fastcall sub_42371(int a1, int a2)
{
  int16_t i; // ax
  _BOOL2 v3; // bx

  LOWORD(a2) = *(_WORD *)(dword_192B18 + 361 * word_199878 + 306)
             + *(_WORD *)(dword_192B18 + 361 * word_199878 + 304)
             + *(uint8_t *)(dword_192B18 + 361 * word_199878 + 10);
  for ( i = 0; i < 49; ++i )
  {
    if ( *(_BYTE *)(361 * word_199878 + dword_192B18 + i + 310) )
    {
      v3 = (_BYTE)i == 8;
      if ( (_BYTE)i == 40 )
        v3 = 1;
      if ( (_BYTE)i == 41 )
        v3 = 1;
      if ( !v3 )
        ++a2;
    }
  }
  return 40 * a2;
}
// 192B18: using guessed type int dword_192B18;
// 199878: using guessed type int16_t word_199878;


//----- (000423F6) --------------------------------------------------------
void __usercall sub_423F6(int a1)
{
  int v1; // eax
  int v2; // ebx
  _BYTE v3[76]; // [esp+0h] [ebp-4Ch] BYREF

  sub_127776(v3, 0x49u);
  if ( *(_BYTE *)(dword_192844 + 6) <= 1u && *(int16_t *)(dword_192844 + 31) / 40 > 0 && word_199878 != -1 )
  {
    v3[1] = word_199878;
    v3[0] = word_1998AC;
    if ( *(int16_t *)(dword_192844 + 31) / 40 > 0 && (byte_199EF6 & 4) != 0 )
    {
      byte_199EF6 ^= 4u;
      sub_145EA(word_199878, 0x2Au, a1);
      *(_WORD *)(dword_192844 + 31) -= 40;
    }
    if ( *(int16_t *)(dword_192844 + 31) / 40 > 0 && (byte_199EF6 & 1) != 0 )
    {
      byte_199EF6 ^= 1u;
      sub_145EA(word_199878, 0x1Au, a1);
      *(_WORD *)(dword_192844 + 31) -= 40;
    }
    if ( *(int16_t *)(dword_192844 + 31) / 40 > 0 && (byte_199EF6 & 2) != 0 )
    {
      byte_199EF6 ^= 2u;
      sub_145EA(word_199878, 0x1Bu, a1);
      v1 = dword_192844;
      *(_WORD *)(dword_192844 + 19) -= 10;
      *(_WORD *)(v1 + 31) -= 40;
    }
    if ( *(int16_t *)(dword_192844 + 31) / 40 > 0 && (byte_199EF6 & 8) != 0 )
    {
      byte_199EF6 ^= 8u;
      sub_145EA(word_199878, 0x2Fu, a1);
      *(_WORD *)(dword_192844 + 31) -= 40;
    }
    v2 = dword_192844;
    *(int16_t *)(dword_192844 + 31) %= 40;
    if ( !byte_199EF6 && !*(_BYTE *)(v2 + 6) )
      *(_BYTE *)(v2 + 6) = 1;
  }
  JUMPOUT(0x41F1A);
}
// 42579: control flows out of bounds to 41F1A
// 192844: using guessed type int dword_192844;
// 199878: using guessed type int16_t word_199878;
// 1998AC: using guessed type int16_t word_1998AC;
// 199EF6: using guessed type char byte_199EF6;


//----- (0004257E) --------------------------------------------------------
int __fastcall sub_4257E(int16_t *a1, int a2, int a3)
{
  int16_t i; // cx
  int16_t j; // bx

  word_199878 = a3;
  dword_192844 = (int)sub_110CEE(dword_192ED4, 16501);
  word_1998AC = *(char *)(dword_197F9C + 129 * *a1 + 99);
  word_1998BE = 0;
  word_1998C0 = 1;
  word_1998A2 = a2;
  word_19988E = *(char *)(dword_192B18 + 361 * word_199878);
  byte_199EF6 = 0;
  sub_416CF(a1, a2, 0, 0, 0, 0);
  sub_416CF(a1, 0, 0, 0, 0, 0);
  for ( i = 0; i < 3; ++i )
  {
    for ( j = 1; j < word_1998C0; ++j )
    {
      sub_41F80(j, 0);
      sub_4221F(j, 0);
      sub_420C0(j);
      if ( *(int16_t *)(dword_192844 + 31) > 30000 )
      {
        i = 6;
        break;
      }
    }
  }
  return *(int16_t *)(dword_192844 + 31) / 40;
}
// 192844: using guessed type int dword_192844;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 197F9C: using guessed type int dword_197F9C;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;
// 1998A2: using guessed type int16_t word_1998A2;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998BE: using guessed type int16_t word_1998BE;
// 1998C0: using guessed type int16_t word_1998C0;
// 199EF6: using guessed type char byte_199EF6;


//----- (0004267B) --------------------------------------------------------
void __fastcall sub_4267B(int a1)
{
  int16_t v2; // si
  int16_t v3; // dx
  int16_t v4; // bx
  _BYTE *v5; // eax
  int v6; // eax
  int16_t v7; // ax
  int16_t v8[500]; // [esp+0h] [ebp-3ECh] BYREF
  int v9; // [esp+3E8h] [ebp-4h]

  sub_127776(byte_199B5A, 0x49u);
  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * *(uint8_t *)(a1 + 1) + 2) + 2);
    v9 = 129 * v2;
    v5 = (_BYTE *)(v9 + dword_197F9C);
    if ( v4 == *(_WORD *)(v9 + dword_197F9C + 101) && !v5[17] && !v5[100] && v5[99] == *(_BYTE *)a1 )
    {
      v6 = v3++;
      v8[v6] = v2;
    }
    if ( ++v2 >= 500 )
    {
      if ( byte_199CB4 == 1 )
      {
        v7 = sub_4257E(v8, v3, *(uint8_t *)(a1 + 1));
        *(_BYTE *)(a1 + 2) = 1;
        *(_BYTE *)(a1 + 5) = 0;
        *(_WORD *)(a1 + 6) = 0;
        *(_WORD *)(a1 + 3) = v7;
      }
      else
      {
        sub_42781(v8, v3, a1);
      }
      JUMPOUT(0x41F1A);
    }
  }
}
// 4272A: control flows out of bounds to 41F1A
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;
// 199B5A: using guessed type _BYTE byte_199B5A[2];
// 199CB4: using guessed type char byte_199CB4;


//----- (00042744) --------------------------------------------------------
int __fastcall sub_42744(int16_t *a1, int16_t *a2)
{
  int v3; // eax
  uint8_t v4; // bl

  v3 = dword_197F9C + 129 * *a2;
  v4 = *(_BYTE *)(dword_197F9C + 129 * *a1 + 16);
  if ( v4 == *(_BYTE *)(v3 + 16) )
    return 0;
  if ( v4 >= *(_BYTE *)(v3 + 16) )
    return -1;
  return 1;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (00042781) --------------------------------------------------------
_DWORD *__fastcall sub_42781(int16_t *a1, int a2, int a3)
{
  int16_t v5; // ax
  int16_t i; // bx
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int16_t v10; // di
  int16_t v11; // bx
  int v12; // ecx
  int16_t v13; // ax
  int16_t v14; // ax
  int16_t v15; // ax
  int16_t j; // bx
  int16_t k; // dx
  int v18; // eax
  char v19; // cl
  int16_t m; // di
  int v21; // eax
  int v22; // edx
  int v24; // [esp+0h] [ebp-8h]

  word_1998F6 = 0;
  v5 = *(uint8_t *)(a3 + 1);
  word_1998C0 = 1;
  word_199878 = v5;
  sub_1112EC(dword_192ED4, 65730);
  dword_192864 = (int)sub_110D3C(dword_192ED4, 65730);
  sub_127776((_BYTE *)dword_192864, 0x100C2u);
  dword_192B14 = (int)sub_110D3C(dword_192ED4, 7800);
  sub_127776((_BYTE *)dword_192B14, 0x1E78u);
  word_1998AC = *(char *)(dword_197F9C + 129 * *a1 + 99);
  word_19988E = *(char *)(dword_192B18 + 361 * word_199878);
  qsort(a1, a2, 2);
  for ( i = 0; i < a2; ++i )
  {
    if ( !*(_BYTE *)(dword_197F9C + 129 * a1[i] + 17) )
    {
      sub_4954A(a1[i], word_1998C0);
      v7 = 313 * word_1998C0;
      v8 = dword_192864;
      *(_BYTE *)(v7 + dword_192864 + 33) = 0;
      ++word_1998C0;
      *(_BYTE *)(v7 + v8 + 34) = 0;
    }
  }
  sub_4AA36(word_199878, 0);
  sub_35F0A();
  v9 = dword_192864;
  *(_BYTE *)(dword_192864 + 33) = 0;
  v10 = 0;
  *(_BYTE *)(v9 + 34) = 0;
  while ( v10 < word_1998C0 )
  {
    v11 = v10;
    v12 = 313 * v10;
    sub_366DD(v10);
    *(_WORD *)(v12 + dword_192864 + 52) = v13;
    sub_35D0D(v10, 0);
    *(_WORD *)(v12 + dword_192864 + 54) = v14;
    sub_35D0D(v10++, 1);
    *(_WORD *)(dword_192864 + v12 + 56) = v15;
    sub_4C9F6(v11);
  }
  v24 = 0;
  do
  {
    for ( j = 0; j < word_1998C0; ++j )
    {
      for ( k = 0; k < 8; ++k )
      {
        v18 = 313 * j + dword_192864 + 11 * k;
        v19 = *(_BYTE *)(v18 + 84);
        *(_BYTE *)(v18 + 90) = 1;
        *(_BYTE *)(v18 + 91) = v19;
        if ( *(int16_t *)(v18 + 82) > 0 && byte_17F80F[28 * *(int16_t *)(v18 + 82)] != 1 && *(int16_t *)(v18 + 88) > 0 )
          --*(_WORD *)(v18 + 88);
      }
    }
    for ( m = 1; m < word_1998C0; ++m )
    {
      v21 = m;
      sub_38B5E(v21, 0, 0, 0, 0, 0, 0);
    }
    ++v24;
  }
  while ( (int16_t)v24 < 10 );
  v22 = *(int16_t *)(dword_192864 + 170) % 100;
  *(_WORD *)(a3 + 3) = *(int16_t *)(dword_192864 + 170) / 100;
  *(_BYTE *)(a3 + 2) = byte_199B5C;
  *(_BYTE *)(a3 + 5) = byte_199B5F;
  *(_WORD *)(a3 + 6) = word_199B60;
  return sub_1113CC(dword_192ED4, v22);
}
// 428D4: variable 'v13' is possibly undefined
// 428E9: variable 'v14' is possibly undefined
// 42903: variable 'v15' is possibly undefined
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 197F9C: using guessed type int dword_197F9C;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998F6: using guessed type int16_t word_1998F6;
// 199B5C: using guessed type char byte_199B5C;
// 199B5F: using guessed type char byte_199B5F;
// 199B60: using guessed type int16_t word_199B60;


//----- (000429EE) --------------------------------------------------------
int __fastcall sub_429EE( int a1)
{
  int16_t v2; // dx
  int result; // eax

  v2 = 1;
  result = 0;
  while ( v2 < word_1998C0 )
  {
    if ( *(uint8_t *)(dword_192864 + 313 * v2 + 74) == a1 )
      ++result;
    ++v2;
  }
  return result;
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00042A27) --------------------------------------------------------
bool __fastcall sub_42A27( int a1)
{
  int v2; // eax
  int v3; // edx

  v2 = 313 * a1 + dword_192864;
  v3 = 0;
  if ( !*(_BYTE *)(v2 + 36) && !*(_BYTE *)(v2 + 176) )
    return !sub_3E563(a1);
  return v3;
}
// 192864: using guessed type int dword_192864;


//----- (00042A61) --------------------------------------------------------
void sub_42A61()
{
  int16_t i; // bx

  for ( i = 0; i < word_1998C0; ++i )
    sub_4B0D3(i, 37);
  JUMPOUT(0x42DE2);
}
// 42ABA: control flows out of bounds to 42DE2
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00042ABF) --------------------------------------------------------
int __fastcall sub_42ABF( int a1)
{
  int16_t v1; // ax
  int v2; // edx

  v1 = *(uint8_t *)(dword_192864 + 313 * a1 + 32);
  v2 = 0;
  if ( (v1 >= 8 || *(_BYTE *)(3753 * v1 + dword_197F98 + 40) != 100 || word_199900 == 1) && !word_1998C6 )
    return 1;
  return v2;
}
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int dword_197F98;
// 1998C6: using guessed type int16_t word_1998C6;
// 199900: using guessed type int16_t word_199900;


//----- (00042B0F) --------------------------------------------------------
int __fastcall sub_42B0F( int a1, int a2, int a3, int a4, int a5)
{
  _WORD v7[2]; // [esp+0h] [ebp-10h] BYREF
  int v8; // [esp+4h] [ebp-Ch]
  int16_t v9; // [esp+8h] [ebp-8h]
  int16_t v10; // [esp+Ah] [ebp-6h]
  int16_t v11; // [esp+Ch] [ebp-4h]
  int16_t v12; // [esp+Eh] [ebp-2h]

  v7[0] = word_1998F0;
  v7[1] = word_1998F2;
  v8 = sub_12484C();
  v12 = a5;
  v9 = a2;
  v10 = a3;
  v11 = a4;
  return sub_F6816(*(int16_t *)(dword_197F98 + 3753 * a1 + 43), 1000, (int)v7, 0x10u);
}
// 197F98: using guessed type int dword_197F98;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;


//----- (00042B70) --------------------------------------------------------
int __fastcall sub_42B70( int a1)
{
  int v2; // esi
  int16_t v3; // ax
  int v4; // eax
  int result; // eax
  int v6; // ecx
  int v7; // edx
  int16_t v8; // ax
  int16_t v9; // cx
  int16_t v10; // di
  int16_t v11; // ax
  int16_t v12; // cx
  int v13; // eax
  int v14; // eax
  int16_t v15; // cx
  int v16; // eax
  char v17; // dl
  int v18; // eax
  int v19; // eax
  int v20; // eax
  char v21; // [esp+0h] [ebp-4h]

  v2 = 313 * a1;
  sub_388CE();
  v21 = v3;
  *(_BYTE *)(dword_192864 + v2 + 72) = 0;
  if ( v3 )
    sub_388E7();
  v4 = dword_192864 + 313 * a1;
  *(_BYTE *)(v4 + 73) = 0;
  if ( *(_BYTE *)(v4 + 75) != 1 )
  {
    if ( *(_BYTE *)(v4 + 176) == 1 )
    {
      *(_WORD *)(v4 + 61) = 0;
      *(_BYTE *)(v4 + 64) = 2;
      v6 = 0;
      do
      {
        result = 313 * a1 + dword_192864;
        v7 = 11 * (int16_t)v6;
        *(_BYTE *)(v7 + result + 91) = 0;
        ++v6;
        *(_BYTE *)(v7 + result + 92) = 0;
      }
      while ( (int16_t)v6 < 8 );
      return result;
    }
    v8 = 1;
    v9 = 0;
    while ( v8 < word_1998C0 )
    {
      if ( *(uint8_t *)(dword_192864 + 313 * v8 + 74) == a1 )
        ++v9;
      ++v8;
    }
    v10 = v9;
    sub_4528F(a1);
    v12 = v11;
    v13 = dword_192864 + 313 * a1;
    *(_WORD *)(v13 + 59) = v12;
    *(_WORD *)(v13 + 61) = v12;
    if ( *(_BYTE *)(v13 + 64) == 2 )
      *(_BYTE *)(v13 + 64) = 3;
    v14 = dword_192864 + 313 * a1;
    if ( *(_BYTE *)(v14 + 64) == 6 )
      *(_BYTE *)(v14 + 64) = 7;
    v15 = 0;
    while ( 1 )
    {
      v16 = 11 * v15 + dword_192864 + 313 * a1;
      if ( *(_WORD *)(v16 + 82) != 32 )
        break;
      if ( *(uint8_t *)(v16 + 84) >= v10 )
      {
        v17 = *(_BYTE *)(v16 + 84) - v21;
LABEL_27:
        *(_BYTE *)(v16 + 91) = v17;
        goto LABEL_28;
      }
      *(_BYTE *)(v16 + 91) = 0;
      v10 -= *(uint8_t *)(v16 + 84);
LABEL_28:
      v18 = 11 * v15 + 313 * a1 + dword_192864;
      if ( *(char *)(v18 + 90) != -1 )
        *(_BYTE *)(v18 + 90) = 1;
      if ( sub_4B0D3(a1, 16) )
      {
        v19 = 11 * v15 + dword_192864 + 313 * a1;
        if ( !byte_17F80F[28 * *(int16_t *)(v19 + 82)] && *(_BYTE *)(v19 + 92) != 1 )
          *(_BYTE *)(v19 + 92) = 2;
      }
      if ( sub_4B0D3(a1, 12) )
      {
        v20 = 11 * v15 + 313 * a1 + dword_192864;
        if ( byte_17F80F[28 * *(int16_t *)(v20 + 82)] == 1 && *(_BYTE *)(v20 + 92) != 1 )
          *(_BYTE *)(v20 + 92) = 2;
      }
      result = dword_192864 + 313 * a1 + 11 * v15;
      if ( *(int16_t *)(result + 82) > 0
        && byte_17F80F[28 * *(int16_t *)(result + 82)] == 2
        && *(int16_t *)(result + 88) > 0 )
      {
        --*(_WORD *)(result + 88);
      }
      if ( ++v15 >= 8 )
        return result;
    }
    v17 = *(_BYTE *)(v16 + 84);
    goto LABEL_27;
  }
  if ( word_1998CE )
  {
    if ( word_17D853 )
      sub_3FBFE(1);
  }
  return sub_45964(a1);
}
// 42B91: variable 'v3' is possibly undefined
// 42C6A: variable 'v11' is possibly undefined
// 17D853: using guessed type int16_t word_17D853;
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998CE: using guessed type int16_t word_1998CE;


//----- (00042DE8) --------------------------------------------------------
void sub_42DE8()
{
  int16_t i; // cx
  int v1; // esi
  int16_t v2; // ax
  int16_t v3; // ax
  int16_t v4; // ax

  for ( i = 0; i < word_1998C0; ++i )
  {
    if ( i || word_199878 != -1 )
    {
      v1 = 313 * i;
      if ( !*(_BYTE *)(v1 + dword_192864 + 36) )
      {
        sub_366DD(i);
        *(_WORD *)(v1 + dword_192864 + 52) = v2;
        sub_35D0D(i, 0);
        *(_WORD *)(v1 + dword_192864 + 54) = v3;
        sub_35D0D(i, 1);
        *(_WORD *)(v1 + dword_192864 + 56) = v4;
      }
    }
  }
}
// 42E26: variable 'v2' is possibly undefined
// 42E3B: variable 'v3' is possibly undefined
// 42E52: variable 'v4' is possibly undefined
// 192864: using guessed type int dword_192864;
// 199878: using guessed type int16_t word_199878;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00042E66) --------------------------------------------------------
int __fastcall sub_42E66( int a1)
{
  int v1; // ebx

  v1 = -5;
  if ( a1 != -1 )
    return *(int16_t *)(313 * a1 + dword_192864 + 52) / 10 + *(int16_t *)(313 * a1 + dword_192864 + 59);
  return v1;
}
// 192864: using guessed type int dword_192864;


//----- (00042E9C) --------------------------------------------------------
int __fastcall sub_42E9C(int16_t *a1, int16_t *a2)
{
  int v3; // eax
  int16_t v4; // si
  int v6; // eax
  int16_t v7; // cx

  v3 = *a1;
  v4 = -5;
  if ( v3 != -1 )
    v4 = *(int16_t *)(dword_192864 + 313 * v3 + 52) / 10 + *(_WORD *)(dword_192864 + 313 * v3 + 59);
  if ( v4 == (uint16_t)sub_42E66(*a2) )
    return 0;
  v6 = *a1;
  v7 = -5;
  if ( v6 != -1 )
    v7 = *(int16_t *)(dword_192864 + 313 * v6 + 52) / 10 + *(_WORD *)(dword_192864 + 313 * v6 + 59);
  if ( v7 <= (int16_t)sub_42E66(*a2) )
    return 1;
  else
    return -1;
}
// 192864: using guessed type int dword_192864;


//----- (00042F7F) --------------------------------------------------------
void __usercall sub_42F7F(int a1, int a2, int a3)
{
  int v4; // eax
  char v5; // al
  int v6; // eax
  int v7; // edx
  int16_t i; // cx
  int j; // ecx
  int v10; // edx
  int v11; // eax
  int16_t v12; // bx
  int v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int16_t v17; // dx
  int v18; // eax
  int v19; // eax
  int v20; // ebx
  int v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int16_t v29; // si
  int v30; // eax
  int16_t v31; // bx
  int16_t v32; // ax
  int16_t v33; // si
  int v34; // edx
  int v35; // eax
  int16_t v36; // ax
  int v37; // edx
  unsigned int v38; // ebx
  int v39; // eax
  unsigned int v40; // edx
  int v41; // eax
  int16_t v42; // ax
  int v43; // eax
  int v44; // eax
  int16_t v45; // ax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int16_t v50; // si
  int v51; // eax
  int16_t v52; // si
  int v53; // ebx
  int v54; // eax
  int v55; // eax
  int16_t v56; // bx
  int v57; // eax
  int v58; // eax
  unsigned int v59; // edx
  int16_t ii; // si
  int v61; // eax
  int16_t v62; // ax
  int16_t v63; // ax
  int v64; // eax
  int16_t v65; // dx
  int v66; // eax
  int16_t v67; // bx
  int v68; // eax
  int16_t v69; // dx
  int v70; // eax
  int v71; // eax
  int16_t v72; // ax
  int v73; // eax
  int v74; // eax
  int v75; // eax
  int16_t v76; // ax
  int v77; // eax
  int v78; // eax
  int v79; // eax
  int16_t v80; // ax
  int v81; // eax
  int v82; // eax
  int v83; // eax
  int v84; // eax
  int v85; // eax
  int16_t v86; // si
  int v87; // edx
  int16_t v88; // dx
  int v89; // ebx
  int v90; // ebx
  int16_t v91; // ax
  int16_t v92; // si
  int16_t v93; // ax
  int v94; // eax
  int16_t v95; // ax
  int v96; // eax
  int v97; // eax
  int v98; // eax
  int v99; // eax
  int v100; // eax
  unsigned int v101; // edx
  int v102; // eax
  int v103; // eax
  int v104; // eax
  int v105; // eax
  int v106; // eax
  int v107; // eax
  int16_t k; // cx
  _BOOL2 v109; // si
  int16_t m; // cx
  int v111; // eax
  _BOOL2 v112; // si
  int16_t n; // bx
  int v114; // eax
  int v115; // esi
  int v116; // esi
  int v117; // eax
  int v119; // esi
  int16_t v120; // dx
  int16_t *v121; // eax
  char v122; // al
  int16_t v123; // [esp-Ch] [ebp-2Ah]
  int16_t v124; // [esp-Ch] [ebp-2Ah]
  int16_t v125; // [esp-Ch] [ebp-2Ah]
  int16_t v126; // [esp-8h] [ebp-26h]
  int16_t v127; // [esp-8h] [ebp-26h]
  int16_t v128; // [esp-8h] [ebp-26h]
  int16_t v129; // [esp-4h] [ebp-22h]
  int v130; // [esp+0h] [ebp-1Eh] BYREF
  int v131; // [esp+4h] [ebp-1Ah]
  int v132; // [esp+8h] [ebp-16h]
  int v133; // [esp+Ch] [ebp-12h]
  int v134; // [esp+10h] [ebp-Eh]
  int v135; // [esp+14h] [ebp-Ah]
  int v136; // [esp+18h] [ebp-6h]
  int v137; // [esp+1Ch] [ebp-2h]
  int v138; // [esp+20h] [ebp+2h]
  int v139; // [esp+24h] [ebp+6h]
  int v140; // [esp+28h] [ebp+Ah]
  int v141; // [esp+2Ch] [ebp+Eh]
  __int128 v142; // [esp+30h] [ebp+12h]
  int v143; // [esp+40h] [ebp+22h]
  __int128 v144; // [esp+44h] [ebp+26h]
  int64_t v145; // [esp+54h] [ebp+36h]
  int64_t v146; // [esp+5Ch] [ebp+3Eh]
  _BYTE v147[12]; // [esp+64h] [ebp+46h]
  int v148; // [esp+70h] [ebp+52h]
  int v149; // [esp+74h] [ebp+56h]
  int v150; // [esp+78h] [ebp+5Ah]
  int v151; // [esp+7Ch] [ebp+5Eh]
  int16_t v152; // [esp+80h] [ebp+62h]
  int v153; // [esp+84h] [ebp+66h]
  int v154; // [esp+88h] [ebp+6Ah]
  int v155; // [esp+8Ch] [ebp+6Eh]
  int v156; // [esp+90h] [ebp+72h]
  bool v157; // [esp+94h] [ebp+76h]
  int v158; // [esp+98h] [ebp+7Ah]
  int16_t v159; // [esp+9Ch] [ebp+7Eh] BYREF

  v148 = a2;
  sub_2C43A(word_1998AC, a2);
  byte_199B4B[word_1998AC] = v4;
  sub_2C43A(word_19988E, v4);
  byte_199B4B[word_19988E] = v5;
  v6 = 0;
  do
  {
    v7 = (int16_t)v6++;
    word_199206[v7] = 0;
  }
  while ( (int16_t)v6 < 15 );
  for ( i = 0; i < word_1998C0; ++i )
  {
    v6 = dword_192864 + 313 * i;
    v157 = 0;
    if ( !*(_BYTE *)(v6 + 36) && !*(_BYTE *)(v6 + 176) )
    {
      LOBYTE(v6) = sub_3E563(i);
      v157 = (_BYTE)v6 == 0;
    }
    if ( v157 )
    {
      if ( !(_WORD)v148 || (v6 = sub_4B0D3(i, 34), (_WORD)v6) )
      {
        if ( word_17D853
          || (v6 = 313 * i, LOWORD(v6) = *(uint8_t *)(dword_192864 + v6 + 32), (_WORD)v6 == (_WORD)a1) )
        {
          v6 = sub_42B70(i);
        }
      }
    }
  }
  sub_FE8BE(v6);
  v153 = 0;
  v155 = 0;
  for ( j = 0; (int16_t)j < word_1998C0; ++j )
  {
    if ( !*(_BYTE *)(dword_192864 + 313 * (int16_t)j + 36)
      && !sub_3E563(j)
      && (!(_WORD)v148 || sub_4B0D3(j, 34))
      && (word_17D853 || *(uint8_t *)(dword_192864 + 313 * (int16_t)j + 32) == (_WORD)a1) )
    {
      if ( *(_BYTE *)(dword_192864 + 313 * (int16_t)j + 176) )
      {
        ++v155;
        word_19296C[(int16_t)v153] = -1;
      }
      else
      {
        word_19296C[(int16_t)v153] = j;
      }
      ++v153;
    }
  }
  v10 = (int16_t)v153 - (int16_t)v155;
  if ( (int16_t)v153 != (int16_t)v155 )
  {
    if ( word_17D853 )
    {
      v10 = (int16_t)v153;
      j = (int)sub_42E9C;
      qsort(word_19296C, (int16_t)v153, 2, sub_42E9C);
    }
    v11 = (int16_t)v153;
    v12 = v153 + 1;
    word_19296C[(int16_t)v153] = -10;
    while ( v12 < 210 )
    {
      v11 = v12++;
      word_19296C[v11] = -1;
    }
    sub_FE8BE(v11);
    word_1998D8 = -1;
    word_19B578 = 1;
    sub_455A4((int16_t)a1, v10);
    *(_DWORD *)&v147[4] = v13;
    if ( (_WORD)v13 != 1 )
    {
      v151 = 1;
      v14 = sub_1191CA((int)sub_2F4EE, 2);
      word_1998D4 = 0;
      word_1998E8 = 0;
      sub_FE8BE(v14);
      while ( (int16_t)v151 < word_1998C0 )
      {
        HIDWORD(v144) = (int16_t)v151;
        v15 = 313 * (int16_t)v151;
        if ( !*(_BYTE *)(v15 + dword_192864 + 49) && !*(_BYTE *)(v15 + dword_192864 + 36) && !sub_3E563(SWORD6(v144)) )
        {
          v16 = v15 + dword_192864;
          j = (int16_t)(20 * (*(uint8_t *)(v15 + dword_192864 + 34) - word_1998F2));
          v17 = 20 * (*(uint8_t *)(v15 + dword_192864 + 33) - word_1998F0);
          v18 = *(uint8_t *)(v16 + 35);
          LODWORD(v146) = 16;
          sub_3F628(SWORD6(v144), (v18 + 2) % 16, v17, j);
        }
        ++v151;
      }
      word_19B578 = 0;
      while ( 1 )
      {
        if ( word_19296C[word_1998D8] < 0 || *(_WORD *)&v147[4] )
        {
          for ( k = 0; k < word_1998C0; ++k )
          {
            LODWORD(v145) = 313 * k;
            v109 = 0;
            if ( !*(_BYTE *)(v145 + dword_192864 + 36) && !*(_BYTE *)(v145 + dword_192864 + 176) )
              v109 = !sub_3E563(k);
            if ( v109 && (word_17D853 || *(uint8_t *)(dword_192864 + 313 * k + 32) == (_WORD)a1) )
              *(_WORD *)(313 * k + dword_192864 + 69) = 0;
          }
          if ( !(_WORD)v148 )
            sub_44EA4(a1);
          for ( m = 0; m < word_1998C0; ++m )
          {
            v111 = dword_192864 + 313 * m;
            v112 = 0;
            if ( !*(_BYTE *)(v111 + 36) && !*(_BYTE *)(v111 + 176) )
              v112 = !sub_3E563(m);
            if ( v112 )
            {
              for ( n = 0; n < 8; ++n )
              {
                v114 = 11 * n + dword_192864 + 313 * m;
                if ( *(_BYTE *)(v114 + 92) == 2 )
                  *(_BYTE *)(v114 + 92) = 1;
              }
              v115 = 313 * m;
              if ( *(_BYTE *)(dword_192864 + v115 + 64) == 3 )
              {
                sub_ACB4A(m, 1u);
                *(_BYTE *)(v115 + dword_192864 + 64) = 1;
              }
              v116 = 313 * m;
              v117 = v116 + dword_192864;
              if ( *(_BYTE *)(v116 + dword_192864 + 64) == 4 && (*(_BYTE *)(v117 + 65))-- == 1 )
              {
                sub_ACB4A(m, 5u);
                sub_ACB4A(m, 1u);
                *(_BYTE *)(v116 + dword_192864 + 64) = 1;
              }
              v119 = 313 * m;
              if ( *(_BYTE *)(dword_192864 + v119 + 64) == 7 )
              {
                sub_ACB4A(m, 4u);
                v120 = 0;
                *(_BYTE *)(v119 + dword_192864 + 64) = 4;
                do
                {
                  v121 = (int16_t *)(dword_192B14 + 26 * v120);
                  if ( *v121 > 0 && m == v121[3] && m != v121[2] )
                    sub_3DDD8(v120);
                  ++v120;
                }
                while ( v120 < 300 );
              }
              sub_37173(m);
              *(_BYTE *)(dword_192864 + 313 * m + 177) = v122;
            }
          }
          if ( word_1998CE && (_WORD)a1 != word_19999C )
            word_1998C4 = word_1998D0;
          if ( word_1998CE )
            sub_3FBFE(1);
          return;
        }
        sub_12C2A0();
        v19 = 313 * word_1998F8;
        v20 = dword_192864;
        LOWORD(v19) = *(_WORD *)(dword_192864 + v19 + 61);
        v156 = v19;
        v21 = 313 * word_1998F8;
        word_19994C = 0;
        LOWORD(v21) = *(uint8_t *)(dword_192864 + v21 + 32);
        v22 = 0;
        if ( (int16_t)v21 >= 8
          || (v20 = 3753 * (int16_t)v21, v21 = dword_197F98, *(_BYTE *)(v20 + dword_197F98 + 40) != 100)
          || word_199900 == 1 )
        {
          if ( !word_1998C6 )
            v22 = 1;
        }
        if ( (_WORD)v22 )
        {
          if ( !word_1998CE
            || (v21 = 313 * word_1998F8,
                v22 = dword_192864,
                LOWORD(v21) = *(uint8_t *)(dword_192864 + v21 + 32),
                (_WORD)v21 == word_19999C) )
          {
            if ( word_1998CE )
            {
              LOWORD(v21) = word_199908;
              if ( word_199908 != word_19999C )
              {
                v22 = 10001;
                j = 0;
                v20 = 0;
                v21 = sub_42B0F(word_199908, 10001, 0, 0, 0);
              }
            }
            sub_29837(v21, v22, v20, j);
            if ( word_19994C )
            {
              sub_465D0();
              sub_46CC8(word_1998F8, v22);
              sub_2C601(v23, v22);
            }
            word_19296C[word_1998D8] = -1;
            sub_455A4((int16_t)a1, v22);
            *(_DWORD *)&v147[4] = v24;
            if ( word_1998CE )
              sub_3FBFE(1);
            goto LABEL_353;
          }
        }
        word_1998F8 = word_19296C[word_1998D8];
        if ( sub_3E563(word_1998F8) )
        {
          word_19296C[word_1998D8] = -1;
          sub_455A4((int16_t)a1, v22);
          *(_DWORD *)&v147[4] = v103;
          goto LABEL_341;
        }
        if ( !word_17D853 )
        {
          v22 = dword_192864;
          if ( *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32) != (_WORD)a1 )
            goto LABEL_341;
        }
        if ( word_1998CE )
        {
          v22 = dword_192864;
          if ( *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32) != word_19999C )
          {
            *(_DWORD *)&v147[8] = 0;
            do
            {
              if ( word_1999AC )
              {
                LOWORD(v20) = word_190460;
                v20 += 16;
                v159 = 0;
                sub_49D09((int16_t)v20, (int16_t)(word_190462 + 9));
                LOWORD(j) = word_19046A;
                v29 = word_19046E;
                v159 = word_19046C;
                LOWORD(v20) = word_190468;
                sub_124820(dword_190464);
                v22 = sub_127776(&word_190460, 0x10u);
                *(_DWORD *)&v147[8] = 1;
                switch ( (int16_t)v20 )
                {
                  case 10000:
                    *(_WORD *)(313 * word_1998F8 + dword_192864 + 256) = 0;
                    v152 = *(uint8_t *)(313 * word_1998F8 + dword_192864 + 49);
                    *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 49) = 1;
                    v45 = sub_3897A(word_1998F8);
                    j = v45;
                    v20 = (int16_t)(20 * *(uint8_t *)(313 * word_1998F8 + dword_192864 + 34));
                    sub_39E15(word_1998F8, 20 * *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 33), v20, v45);
                    v22 = 313 * word_1998F8;
                    v46 = v22 + dword_192864;
                    LOBYTE(v22) = v152;
                    *(_BYTE *)(v46 + 49) = v152;
                    word_19296C[word_1998D8] = -1;
                    v47 = (int16_t)a1;
                    word_1999AC = 10000;
                    goto LABEL_109;
                  case 10001:
                    sub_29837((uint16_t)(v20 - 10000), v22, v20, j);
                    goto LABEL_107;
                  case 10004:
                    goto LABEL_107;
                  case 10005:
                    v30 = 313 * word_1998F8;
                    LOWORD(v30) = *(uint8_t *)(dword_192864 + v30 + 32);
                    *(_DWORD *)v147 = v30;
                    v31 = sub_3F95F(word_1998F8, j, v159);
                    if ( *(int16_t *)(313 * word_1998F8 + dword_192864 + 61) < 0 )
                      *(_WORD *)(dword_192864 + 313 * word_1998F8 + 61) = 0;
                    sub_38876();
                    v33 = v32;
                    v34 = (int16_t)j;
                    LODWORD(v146) = v159;
                    j = v31;
                    v20 = v159;
                    v22 = sub_3EE0F(word_1998F8, v34, v159);
                    sub_38876();
                    if ( v33 == (_WORD)v35 )
                    {
                      v35 = 313 * word_1998F8;
                      v20 = dword_192864;
                      *(_WORD *)(dword_192864 + v35 + 61) -= v22;
                    }
                    sub_2C601(v35, v22);
                    sub_4590D();
                    if ( v36 )
                      goto LABEL_107;
                    v22 = 313 * word_1998F8;
                    if ( *(uint8_t *)(v22 + dword_192864 + 32) != *(_WORD *)v147 )
                      goto LABEL_107;
                    goto LABEL_133;
                  case 10006:
                    if ( v159 )
                    {
                      v129 = v159;
                      v126 = *(_WORD *)(dword_192B14 + 26 * (int16_t)j + 11);
                      v123 = *(_WORD *)(dword_192B14 + 26 * (int16_t)j + 9);
                      v37 = dword_192864;
                      v38 = (int16_t)(20 * *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 34));
                      v39 = 313 * word_1998F8;
                    }
                    else
                    {
                      v129 = 0;
                      v126 = 20 * *(uint8_t *)(313 * (int16_t)j + dword_192864 + 34);
                      v123 = 20 * *(uint8_t *)(dword_192864 + 313 * (int16_t)j + 33);
                      v37 = 313 * word_1998F8;
                      v38 = (int16_t)(20 * *(uint8_t *)(dword_192864 + v37 + 34));
                      v39 = dword_192864;
                    }
                    j = (int16_t)j;
                    v40 = (int16_t)(20 * *(uint8_t *)(v37 + v39 + 33));
                    sub_38B5E(word_1998F8, v40, v38, j, v123, v126, v129);
                    sub_465D0();
                    sub_46CC8(word_1998F8, v40);
                    v22 = 0;
                    do
                    {
                      v20 = 313 * word_1998F8 + dword_192864;
                      v41 = v20 + 11 * (int16_t)v22;
                      if ( !*(_BYTE *)(v41 + 90) )
                        *(_BYTE *)(v41 + 90) = 1;
                      ++v22;
                    }
                    while ( (int16_t)v22 < 8 );
                    goto LABEL_133;
                  case 10007:
                    v20 = 3;
                    v22 = (word_1998DA + 1) % 3;
                    word_1998DA = v22;
                    sub_465D0();
                    sub_46CC8(word_1998F8, v22);
                    goto LABEL_133;
                  case 10008:
                    sub_11C2F0();
                    j = 479;
                    v20 = 639;
                    word_199898 = sub_11438B(0, 0, 639, 479, &unk_178E18, 0);
                    v22 = 313 * word_1998F8;
                    if ( *(uint8_t *)(v22 + dword_192864 + 32) == word_1998AC )
                    {
                      v42 = 1 - word_192B10[0];
                      word_192B10[0] = 1 - word_192B10[0];
                    }
                    else
                    {
                      v42 = 1 - word_192B12;
                      word_192B12 = 1 - word_192B12;
                    }
                    word_199900 = v42;
                    goto LABEL_133;
                  case 10009:
                    goto LABEL_108;
                  case 10010:
                    v43 = 11 * (int16_t)j + dword_192864 + 313 * word_1998F8;
                    if ( (char)--*(_BYTE *)(v43 + 90) < -1 )
                      *(_BYTE *)(v43 + 90) = 1;
                    v22 = dword_192864 + 313 * word_1998F8;
                    v44 = v22 + 11 * (int16_t)j;
                    if ( *(_BYTE *)(v44 + 90) != 1 && *(_WORD *)(v44 + 82) == 39 )
                      *(_BYTE *)(v22 + 66) = -1;
                    goto LABEL_133;
                  case 10011:
                    v22 = 313 * word_1998F8;
                    *(_BYTE *)(v22 + dword_192864 + 75) = 1;
LABEL_107:
                    word_19296C[word_1998D8] = -1;
                    goto LABEL_108;
                  case 10012:
                    v20 = v159;
                    v22 = (int16_t)j;
                    sub_3FA61(word_1998F8, j, v159);
                    goto LABEL_133;
                  case 10013:
                    sub_3AFB3(j);
                    goto LABEL_133;
                  case 10014:
                    if ( !word_17D853 )
                      sub_45507(j, j, v29);
                    goto LABEL_133;
                  case 10015:
                    if ( v29 == 1 )
                    {
                      v49 = dword_192864 + 313 * word_1998F8;
                      if ( *(_BYTE *)(v49 + 64) == 1 )
                      {
                        if ( word_1998F6 == 1 && !word_1998E0 )
                          sub_ACB4A(word_1998F8, 2u);
                        *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 64) = 2;
                      }
                      else if ( *(_BYTE *)(v49 + 64) == 4 )
                      {
                        if ( word_1998F6 == 1 && !word_1998E0 )
                          sub_ACB4A(word_1998F8, 5u);
                        *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 64) = 6;
                      }
                      sub_388B8();
                      v50 = word_1998F8;
                      v20 = (int)&v159;
                      *(_BYTE *)(313 * word_1998F8 + dword_192864 + 175) -= v159;
                      sub_37308(
                        v50,
                        v130,
                        v131,
                        v132,
                        v133,
                        v134,
                        v135,
                        v136,
                        v137,
                        v138,
                        v139,
                        v140,
                        v141,
                        v142,
                        v143,
                        v144,
                        v145,
                        v146,
                        *(int *)v147,
                        *(int64_t *)&v147[4]);
                      v22 = dword_192864 + 313 * word_1998F8;
                      *(_BYTE *)(v22 + 175) += v159;
                    }
                    else
                    {
                      v51 = 313 * word_1998F8 + dword_192864;
                      if ( *(_BYTE *)(v51 + 64) == 1 )
                      {
                        if ( word_1998F6 == 1 && !word_1998E0 )
                          sub_ACB4A(word_1998F8, 2u);
                        *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 64) = 2;
                      }
                      else if ( *(_BYTE *)(v51 + 64) == 4 )
                      {
                        if ( word_1998F6 == 1 && !word_1998E0 )
                          sub_ACB4A(word_1998F8, 5u);
                        *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 64) = 6;
                      }
                      sub_388B8();
                      v52 = word_1998F8;
                      v53 = dword_192864;
                      *(_BYTE *)(313 * word_1998F8 + dword_192864 + 175) -= v159;
                      v22 = (int16_t)j;
                      v54 = v53 + 313 * (int16_t)j;
                      j = (int16_t)(20 * *(uint8_t *)(v54 + 33));
                      v20 = v159;
                      sub_37DA8(
                        v52,
                        (int16_t)(20 * *(uint8_t *)(v54 + 34)),
                        v130,
                        v131,
                        v132,
                        v133,
                        v134,
                        v135,
                        v136,
                        v137,
                        v138,
                        v139,
                        v140,
                        v141,
                        v142,
                        SDWORD1(v142),
                        SDWORD2(v142),
                        SHIDWORD(v142),
                        v143,
                        v144,
                        v145,
                        v146,
                        *(int64_t *)v147,
                        *(int *)&v147[8],
                        v148,
                        v149,
                        v150);
                    }
                    goto LABEL_133;
                  case 10016:
                    if ( word_17D853 )
                    {
                      v22 = dword_192864;
                      word_199206[*(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32)] = 1;
LABEL_108:
                      v47 = (int16_t)a1;
LABEL_109:
                      sub_455A4(v47, v22);
                      *(_DWORD *)&v147[4] = v48;
                    }
                    else
                    {
                      *(_DWORD *)&v147[4] = 1;
                    }
LABEL_133:
                    word_1999AC = 0;
                    sub_3FBFE(1);
                    break;
                  default:
                    goto LABEL_133;
                }
              }
              else
              {
                sub_12C2A0();
                if ( word_1998CE && (uint16_t)sub_1171AB(v25, v22, v20, j) == word_199898 )
                  sub_29616();
                v26 = sub_124D41();
                v27 = sub_2F4EE(v26);
                v28 = sub_1077D(v27);
                sub_1171AB(v28, v22, v20, j);
                sub_12C2C6(1);
              }
            }
            while ( !*(_WORD *)&v147[8] );
            goto LABEL_135;
          }
        }
        v55 = sub_3897A(word_1998F8);
        a3 = (_WORD)v55 ? word_19989A : sub_1171AB(v55, v22, v20, j);
        HIDWORD(v146) = 0;
        do
        {
          v56 = WORD2(v146);
          if ( a3 == word_18F510[SWORD2(v146)] )
          {
            HIWORD(v22) = HIWORD(dword_192864);
            LOWORD(v22) = *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32);
            if ( sub_3BB3D(SWORD2(v146)) != (_WORD)v22 )
            {
              if ( word_1998CE && word_199908 != word_19999C )
                sub_42B0F(word_199908, 10006, v56, 1, 0);
              j = SWORD2(v146);
              v57 = 26 * SWORD2(v146) + dword_192B14;
              v127 = *(_WORD *)(v57 + 11);
              v124 = *(_WORD *)(v57 + 9);
              v58 = dword_192864 + 313 * word_1998F8;
              v59 = (int16_t)(20 * *(uint8_t *)(v58 + 33));
              sub_38B5E(word_1998F8, v59, (int16_t)(20 * *(uint8_t *)(v58 + 34)), SWORD2(v146), v124, v127, 1);
              sub_465D0();
              sub_46CC8(word_1998F8, v59);
              for ( ii = 0; ii < 8; ++ii )
              {
                v22 = 313 * word_1998F8 + dword_192864;
                v61 = v22 + 11 * ii;
                if ( !*(_BYTE *)(v61 + 90) )
                  *(_BYTE *)(v61 + 90) = 1;
              }
              if ( word_1998CE )
                sub_3FBFE(1);
              a3 = 0;
            }
          }
          ++HIDWORD(v146);
        }
        while ( SWORD2(v146) < 300 );
        if ( a3 == word_1998B6 )
        {
          word_1998C4 = 1 - word_1998C4;
          word_199906 = word_1998C4;
          if ( word_1998CE )
          {
            j = 2;
            v22 = 1003;
            sub_F6816(*(int16_t *)(dword_197F98 + 3753 * word_199908 + 43), 1003, (int)&word_1998C4, 2u);
          }
          a3 = 0;
        }
        if ( a3 == word_1998A6 )
        {
          a3 = 0;
          word_19987E = 1 - word_19987E;
        }
        if ( a3 == word_1998A4 )
        {
          a3 = 0;
          word_1998E4 = 1 - word_1998E4;
          sub_2C601((uint16_t)word_1998E4, v22);
        }
        if ( a3 == word_1998B2 )
        {
          a3 = 0;
          word_1998EE = 1 - word_1998EE;
          sub_2C601((uint16_t)word_1998EE, v22);
        }
        if ( a3 == word_1998A8 )
        {
          a3 = 0;
          word_1998CC = 1 - word_1998CC;
        }
        if ( a3 == word_1998DE )
        {
          v22 = dword_192864;
          v62 = *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32);
          word_1998E0 = 1;
          if ( v62 == word_1998AC )
          {
            v63 = 1 - word_192B10[0];
            word_192B10[0] = 1 - word_192B10[0];
          }
          else
          {
            v63 = 1 - word_192B12;
            word_192B12 = 1 - word_192B12;
          }
          word_199900 = v63;
          sub_2C555();
        }
        if ( a3 == word_1998AE )
          break;
LABEL_181:
        if ( a3 == word_1998B0 )
        {
          if ( word_1998CE && word_199908 != word_19999C )
          {
            j = 0;
            sub_42B0F(word_199908, 10007, 0, 0, 0);
          }
          v22 = (word_1998DA + 1) % 3;
          word_1998DA = v22;
          if ( word_1998CE )
            sub_3FBFE(1);
          sub_465D0();
          sub_46CC8(word_1998F8, v22);
          a3 = 0;
        }
        if ( a3 == word_199898 )
        {
          if ( word_1998CE && word_199908 != word_19999C )
            sub_42B0F(word_199908, 10008, 0, 0, 0);
          if ( *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32) == word_1998AC )
          {
            v72 = 1 - word_192B10[0];
            word_192B10[0] = 1 - word_192B10[0];
          }
          else
          {
            v72 = 1 - word_192B12;
            word_192B12 = 1 - word_192B12;
          }
          word_199900 = v72;
          if ( !v72 )
            word_1998E0 = 0;
          sub_11C2F0();
          j = 479;
          v22 = 0;
          a3 = 0;
          word_199898 = sub_11438B(0, 0, 639, 479, &unk_178E18, 0);
          if ( word_1998CE )
            sub_3FBFE(1);
        }
        if ( a3 == word_1998B8 )
        {
          word_1998F4 = -1;
          sub_4602A();
        }
        if ( a3 == word_19989C )
        {
          word_1998F4 = -1;
          sub_4602A();
        }
        if ( a3 == word_1998A0 )
        {
          if ( word_1998CE && word_199908 != word_19999C )
          {
            v22 = 10009;
            j = 0;
            sub_42B0F(word_199908, 10009, 0, 0, 0);
          }
          sub_455A4((int16_t)a1, v22);
          a3 = 0;
          *(_DWORD *)&v147[4] = v73;
          if ( word_1998CE )
            sub_3FBFE(1);
        }
        v150 = 0;
        do
        {
          if ( a3 == word_18F500[(int16_t)v150] )
          {
            if ( !word_1998D6 )
            {
              if ( word_1998CE && word_199908 != word_19999C )
              {
                j = 0;
                sub_42B0F(word_199908, 10010, v150, 0, 0);
              }
              v74 = dword_192864 + 313 * word_1998F8 + 11 * (int16_t)v150;
              if ( (char)--*(_BYTE *)(v74 + 90) < -1 )
                *(_BYTE *)(v74 + 90) = 1;
              v22 = 313 * word_1998F8 + dword_192864;
              v75 = v22 + 11 * (int16_t)v150;
              if ( *(_BYTE *)(v75 + 90) != 1 && *(_WORD *)(v75 + 82) == 39 )
                *(_BYTE *)(v22 + 66) = -1;
              if ( word_1998CE )
                sub_3FBFE(1);
              word_1998F4 = -1;
            }
            a3 = 0;
          }
          ++v150;
        }
        while ( (int16_t)v150 < 8 );
        if ( a3 == word_1998BC )
        {
          a3 = 0;
          word_199876 = 1 - word_199876;
          sub_34C42((uint16_t)word_199876, v22);
        }
        if ( a3 == word_1998E6 )
        {
          word_1998E8 = 0;
          sub_46CC8(word_1998F8, v22);
          a3 = 0;
        }
        if ( a3 == word_199896 )
        {
          v22 = 0;
          if ( !*(_BYTE *)(313 * word_1998F8 + dword_192864 + 75) )
          {
            sub_42A61();
            if ( v76 )
            {
              v77 = 58;
              goto LABEL_237;
            }
            v78 = dword_192864 + 313 * word_1998F8;
            if ( !*(_BYTE *)(v78 + 49) )
            {
              v77 = 59;
              goto LABEL_237;
            }
            if ( *(int16_t *)(v78 + 59) <= 0 )
            {
              v77 = 79;
LABEL_237:
              sub_58F1E(v77, (char *)&v130, 80);
              sub_131F7B();
              v22 = 1;
              LOWORD(v78) = sub_77423((int)&v130);
            }
            if ( (_WORD)v22 )
            {
              sub_2C601(v78, v22);
            }
            else
            {
              if ( word_1998CE && word_199908 != word_19999C )
              {
                j = 0;
                sub_42B0F(word_199908, 10011, 0, 0, 0);
              }
              v22 = dword_192864;
              *(_BYTE *)(dword_192864 + 313 * word_1998F8 + 75) = 1;
              word_19296C[word_1998D8] = -1;
              sub_455A4((int16_t)a1, v22);
              *(_DWORD *)&v147[4] = v79;
              if ( word_1998CE )
                sub_3FBFE(1);
            }
          }
          a3 = 0;
        }
        if ( a3 == word_1998EC )
        {
          word_1998D4 = 0;
          sub_388A2();
          if ( v80 )
          {
            v22 = (int)&v130;
            sub_58F1E(60, (char *)&v130, 80);
            sub_131F7B();
            LOWORD(v81) = sub_77423((int)&v130);
            sub_2C601(v81, (int)&v130);
            word_1998E8 = 0;
          }
          else
          {
            sub_465D0();
            sub_46CC8(word_1998F8, v22);
          }
          a3 = 0;
        }
        if ( a3 == word_1998B4 )
        {
          j = 3;
          v22 = (int16_t)(2 * word_199894 / 3);
          a3 = 0;
          sub_49D09((int16_t)(2 * word_199892 / 3), v22);
        }
        if ( sub_123ABA() < 5 && word_1998F0 > 0
          || sub_123ABA() > 635 && word_1998F0 < 49
          || sub_123AE7() < 5 && word_1998F2 > 0
          || sub_123AE7() > 475 && word_1998F2 < 50 )
        {
          sub_49A41(v22, a1);
        }
        if ( a3 == word_199888 )
          sub_49D09(
            *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 33),
            *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 34));
        v22 = -word_1998BA;
        if ( a3 == v22 )
        {
          if ( word_1998CE && word_199908 != word_19999C )
          {
            j = (int16_t)(word_1998F2 + word_19989E / 2);
            sub_42B0F(word_199908, 10012, word_1998F0 + word_1998AA / 2, j, 0);
          }
          v22 = (int16_t)(word_1998F0 + word_1998AA / 2);
          sub_3FA61(word_1998F8, v22, word_1998F2 + word_19989E / 2);
          if ( word_1998CE )
            sub_3FBFE(1);
          a3 = 0;
        }
        if ( a3 == dword_19B574 )
        {
          if ( word_1998CE && word_199908 != word_19999C )
          {
            v22 = 10016;
            j = word_1998F2;
            sub_42B0F(word_199908, 10016, word_1998F0, word_1998F2, 0);
          }
          if ( word_17D853 )
          {
            v22 = dword_192864;
            word_199206[*(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32)] = 1;
            sub_455A4((int16_t)a1, v22);
            *(_DWORD *)&v147[4] = v82;
          }
          else
          {
            *(_DWORD *)&v147[4] = 1;
          }
          a3 = 0;
          if ( word_1998CE )
            sub_3FBFE(1);
        }
        if ( a3 != word_1998BA )
          goto LABEL_341;
        if ( sub_124039() >= 4 && sub_124039() <= 11 && (v83 = dword_192864 + 313 * word_1998F8, *(_BYTE *)(v83 + 37)) )
        {
          if ( *(_BYTE *)(v83 + 37) <= 2u )
          {
            v149 = word_1998F0 + (word_1998AA + 1) / 2 - 1;
            v84 = word_19989E + 1;
          }
          else
          {
            v149 = word_1998F0 + word_1998AA / 2 - 1;
            v84 = word_19989E;
          }
          v85 = word_1998F2 + v84 / 2 - 1;
        }
        else
        {
          v149 = word_1998F0 + word_1998AA / 2;
          v85 = word_1998F2 + word_19989E / 2;
        }
        v154 = v85;
        v86 = word_18C9A8[68 * (int16_t)v149 + (int16_t)v85];
        LODWORD(v146) = word_1998D4;
        v22 = word_1998D4 + word_1998E8;
        if ( v22 <= 0 )
        {
          if ( v86 == 2000 )
          {
            v87 = 313 * word_1998F8;
            LOWORD(v87) = *(uint8_t *)(dword_192864 + v87 + 32);
            v158 = v87;
            if ( word_1998CE && word_199908 != word_19999C )
              sub_42B0F(word_199908, 10005, v149, v85, 0);
            v88 = sub_3F95F(word_1998F8, v149, (int16_t)v154);
            v89 = 313 * word_1998F8;
            if ( *(int16_t *)(v89 + dword_192864 + 61) < 0 )
              *(_WORD *)(v89 + dword_192864 + 61) = 0;
            v90 = (int16_t)v154;
            sub_38876();
            j = v88;
            v92 = v91;
            v22 = sub_3EE0F(word_1998F8, (int16_t)v149, v90);
            sub_38876();
            if ( v92 == v93 )
              *(_WORD *)(dword_192864 + 313 * word_1998F8 + 61) -= v22;
            sub_46CC8(word_1998F8, v22);
            sub_2C601(v94, v22);
            sub_4590D();
            if ( v95 || (v22 = dword_192864, *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32) != (_WORD)v158) )
            {
              word_19296C[word_1998D8] = -1;
              sub_455A4((int16_t)a1, v22);
              *(_DWORD *)&v147[4] = v96;
            }
LABEL_311:
            if ( word_1998CE )
              sub_3FBFE(1);
            goto LABEL_135;
          }
          HIDWORD(v145) = v86;
          if ( v86 > -1 && v86 < word_1998C0 )
          {
            v22 = dword_192864;
            v97 = dword_192864 + 313 * v86;
            if ( !*(_BYTE *)(v97 + 36) )
            {
              j = 313 * word_1998F8;
              v22 = j + dword_192864;
              if ( *(_BYTE *)(v97 + 32) == *(_BYTE *)(j + dword_192864 + 32) )
              {
                if ( !word_17D853 )
                {
                  if ( word_1998CE && word_199908 != word_19999C )
                  {
                    v22 = 10014;
                    j = 0;
                    sub_42B0F(word_199908, 10014, SWORD2(v145), 0, 0);
                  }
                  sub_45507(v86, j, v86);
                  goto LABEL_311;
                }
              }
              else
              {
                if ( sub_3E563(SWORD2(v145)) )
                {
                  sub_58F1E(61, (char *)&v130, 80);
                  j = 0;
                  v22 = 32;
                  sub_1319E4(144, 32, 0, 0, 0, 0, 0, 0);
                  sub_131F7B();
                  sub_77658((int)&v130);
                  if ( (_WORD)v98 )
                  {
                    if ( word_1998CE && word_199908 != word_19999C )
                    {
                      v22 = 10013;
                      j = 0;
                      sub_42B0F(word_199908, 10013, SWORD2(v145), 0, 0);
                    }
                    v98 = sub_3AFB3(v86);
                    if ( word_1998CE )
                      v98 = sub_3FBFE(1);
                  }
                }
                else
                {
                  if ( *(_BYTE *)(313 * v86 + dword_192864 + 64) != 4 )
                  {
                    if ( word_1998CE && word_199908 != word_19999C )
                      sub_42B0F(word_199908, 10006, SWORD2(v145), 0, 0);
                    j = v86;
                    v99 = 313 * v86;
                    v128 = 20 * *(uint8_t *)(dword_192864 + v99 + 34);
                    v125 = 20 * *(uint8_t *)(dword_192864 + v99 + 33);
                    v100 = dword_192864 + 313 * word_1998F8;
                    v101 = (int16_t)(20 * *(uint8_t *)(v100 + 33));
                    sub_38B5E(word_1998F8, v101, (int16_t)(20 * *(uint8_t *)(v100 + 34)), v86, v125, v128, 0);
                    sub_465D0();
                    sub_46CC8(word_1998F8, v101);
                    v22 = 0;
                    do
                    {
                      v102 = 313 * word_1998F8 + dword_192864 + 11 * (int16_t)v22;
                      if ( !*(_BYTE *)(v102 + 90) )
                        *(_BYTE *)(v102 + 90) = 1;
                      ++v22;
                    }
                    while ( (int16_t)v22 < 8 );
                    goto LABEL_311;
                  }
                  v22 = (int)&v130;
                  sub_58F1E(80, (char *)&v130, 80);
                  sub_131F7B();
                  LOWORD(v98) = sub_77423((int)&v130);
                }
                sub_2C601(v98, v22);
              }
            }
          }
        }
        else if ( !word_1998D4
               || v86 <= -1
               || v86 >= word_1998C0
               || (v22 = 313 * v86, *(_BYTE *)(v22 + dword_192864 + 36)) )
        {
          if ( word_1998E8 )
          {
            v22 = v86;
            if ( v86 > -1 && v86 < word_1998C0 && !*(_BYTE *)(dword_192864 + 313 * v86 + 36) )
              sub_459E7(word_1998F8);
          }
        }
        else
        {
          sub_33C05(v86);
        }
LABEL_135:
        a3 = 0;
LABEL_341:
        if ( a3 == word_19989A )
        {
          if ( word_1998CE && word_199908 != word_19999C )
          {
            v22 = 10004;
            j = 0;
            sub_42B0F(word_199908, 10004, 0, 0, 0);
          }
          sub_38858(word_1998F8);
          word_19296C[word_1998D8] = -1;
          sub_455A4((int16_t)a1, v22);
          *(_DWORD *)&v147[4] = v104;
          if ( word_1998CE )
            sub_3FBFE(1);
          sub_117174(3);
          a3 = 0;
        }
        if ( !*(_WORD *)&v147[4] )
        {
          if ( !word_19994C && (v22 = v156, (_WORD)v156 == *(_WORD *)(dword_192864 + 313 * word_1998F8 + 61)) )
          {
            v106 = sub_124D41();
            v107 = sub_2F4EE(v106);
            sub_1077D(v107);
          }
          else
          {
            sub_465D0();
            sub_46CC8(word_1998F8, v22);
            sub_2C601(v105, v22);
          }
        }
LABEL_353:
        sub_12C2C6(1);
      }
      if ( word_1998F8 )
      {
        v22 = (int)&v130;
        sub_58F1E(57, (char *)&v130, 80);
        sub_131F7B();
        sub_77658((int)&v130);
        if ( (_WORD)v64 )
        {
          word_199876 = 1 - word_199876;
          sub_34C42((uint16_t)word_199876, (int)&v130);
          if ( word_1998CE && word_199908 != word_19999C )
            sub_42B0F(word_199908, 10000, 0, 0, 0);
          v65 = word_1998F8;
          v66 = dword_192864 + 313 * word_1998F8;
          *(_WORD *)(v66 + 256) = 0;
          v67 = *(uint8_t *)(v66 + 49);
          *(_BYTE *)(v66 + 49) = 1;
          j = (int16_t)sub_3897A(v65);
          v68 = 313 * word_1998F8 + dword_192864;
          v69 = 20 * *(uint8_t *)(v68 + 34);
          LOWORD(v68) = *(uint8_t *)(v68 + 33);
          v152 = v67;
          sub_39E15(word_1998F8, 20 * v68, v69, j);
          v22 = 313 * word_1998F8;
          v70 = v22 + dword_192864;
          LOBYTE(v22) = v152;
          *(_BYTE *)(v70 + 49) = v152;
          word_19296C[word_1998D8] = -1;
          sub_455A4((int16_t)a1, v22);
          *(_DWORD *)&v147[4] = v71;
          if ( word_1998CE )
            sub_3FBFE(1);
          goto LABEL_180;
        }
      }
      else
      {
        v22 = (int)&v130;
        sub_58F1E(56, (char *)&v130, 80);
        sub_131F7B();
        LOWORD(v64) = sub_77423((int)&v130);
      }
      sub_2C601(v64, (int)&v130);
LABEL_180:
      a3 = 0;
      goto LABEL_181;
    }
  }
}
// 42FA7: variable 'v4' is possibly undefined
// 42FC2: variable 'v5' is possibly undefined
// 43078: variable 'v6' is possibly undefined
// 431BB: variable 'v13' is possibly undefined
// 43396: variable 'v23' is possibly undefined
// 433B4: variable 'v24' is possibly undefined
// 43477: variable 'v25' is possibly undefined
// 435E6: variable 'v32' is possibly undefined
// 43614: variable 'v35' is possibly undefined
// 4363B: variable 'v36' is possibly undefined
// 439ED: variable 'v48' is possibly undefined
// 43ECF: variable 'v64' is possibly undefined
// 43FAF: variable 'v71' is possibly undefined
// 4417E: variable 'v73' is possibly undefined
// 442E8: variable 'v76' is possibly undefined
// 443B2: variable 'v79' is possibly undefined
// 443CB: variable 'v78' is possibly undefined
// 443F3: variable 'v80' is possibly undefined
// 44414: variable 'v81' is possibly undefined
// 4462C: variable 'v82' is possibly undefined
// 4487A: variable 'v91' is possibly undefined
// 44899: variable 'v93' is possibly undefined
// 448BF: variable 'v94' is possibly undefined
// 448CC: variable 'v95' is possibly undefined
// 44906: variable 'v96' is possibly undefined
// 44A05: variable 'v98' is possibly undefined
// 44B70: variable 'v103' is possibly undefined
// 44BCF: variable 'v104' is possibly undefined
// 44C32: variable 'v105' is possibly undefined
// 44E50: variable 'v122' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 459E7: using guessed type int __fastcall sub_459E7(_DWORD);
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 133EF4: using guessed type int __fastcall qsort(_DWORD, _DWORD, _DWORD, _DWORD);
// 17D853: using guessed type int16_t word_17D853;
// 18C9A8: using guessed type int16_t word_18C9A8[4979];
// 18F500: using guessed type int16_t word_18F500[];
// 18F510: using guessed type int16_t word_18F510[300];
// 190460: using guessed type int16_t word_190460;
// 190462: using guessed type int16_t word_190462;
// 190464: using guessed type int dword_190464;
// 190468: using guessed type int16_t word_190468;
// 19046A: using guessed type int16_t word_19046A;
// 19046C: using guessed type int16_t word_19046C;
// 19046E: using guessed type int16_t word_19046E;
// 192864: using guessed type int dword_192864;
// 19296C: using guessed type int16_t word_19296C[];
// 192B10: using guessed type int16_t word_192B10[];
// 192B12: using guessed type int16_t word_192B12;
// 192B14: using guessed type int dword_192B14;
// 197F98: using guessed type int dword_197F98;
// 199206: using guessed type int16_t word_199206[15];
// 199876: using guessed type int16_t word_199876;
// 19987E: using guessed type int16_t word_19987E;
// 199888: using guessed type int16_t word_199888;
// 19988E: using guessed type int16_t word_19988E;
// 199892: using guessed type int16_t word_199892;
// 199894: using guessed type int16_t word_199894;
// 199896: using guessed type int16_t word_199896;
// 199898: using guessed type int16_t word_199898;
// 19989A: using guessed type int16_t word_19989A;
// 19989C: using guessed type int16_t word_19989C;
// 19989E: using guessed type int16_t word_19989E;
// 1998A0: using guessed type int16_t word_1998A0;
// 1998A4: using guessed type int16_t word_1998A4;
// 1998A6: using guessed type int16_t word_1998A6;
// 1998A8: using guessed type int16_t word_1998A8;
// 1998AA: using guessed type int16_t word_1998AA;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998AE: using guessed type int16_t word_1998AE;
// 1998B0: using guessed type int16_t word_1998B0;
// 1998B2: using guessed type int16_t word_1998B2;
// 1998B4: using guessed type int16_t word_1998B4;
// 1998B6: using guessed type int16_t word_1998B6;
// 1998B8: using guessed type int16_t word_1998B8;
// 1998BA: using guessed type int16_t word_1998BA;
// 1998BC: using guessed type int16_t word_1998BC;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998C4: using guessed type int16_t word_1998C4;
// 1998C6: using guessed type int16_t word_1998C6;
// 1998CC: using guessed type int16_t word_1998CC;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998D0: using guessed type int16_t word_1998D0;
// 1998D4: using guessed type int16_t word_1998D4;
// 1998D6: using guessed type int16_t word_1998D6;
// 1998D8: using guessed type int16_t word_1998D8;
// 1998DA: using guessed type int16_t word_1998DA;
// 1998DE: using guessed type int16_t word_1998DE;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998E4: using guessed type int16_t word_1998E4;
// 1998E6: using guessed type int16_t word_1998E6;
// 1998E8: using guessed type int16_t word_1998E8;
// 1998EC: using guessed type int16_t word_1998EC;
// 1998EE: using guessed type int16_t word_1998EE;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F4: using guessed type int16_t word_1998F4;
// 1998F6: using guessed type int16_t word_1998F6;
// 1998F8: using guessed type int16_t word_1998F8;
// 199900: using guessed type int16_t word_199900;
// 199906: using guessed type int16_t word_199906;
// 199908: using guessed type int16_t word_199908;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 1999AC: using guessed type int16_t word_1999AC;
// 19B574: using guessed type int dword_19B574;
// 19B578: using guessed type int16_t word_19B578;


//----- (00044EA4) --------------------------------------------------------
void __fastcall sub_44EA4( int a1)
{
  int16_t i; // si
  int v3; // eax
  int16_t v4; // dx
  int v5; // eax
  int16_t v6; // cx
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int16_t v11; // bx
  int v12; // edx
  int16_t *v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // eax
  int16_t j; // cx
  int v19; // eax
  int v20; // edx
  int v21; // edx
  int16_t v22; // si
  int v23; // eax
  int16_t v24; // ax
  int v25; // esi
  int *v26; // edx
  int v27; // eax
  int16_t v28; // si
  int v29; // edx
  int16_t *v30; // eax
  int16_t v31; // dx
  int v32; // eax
  _WORD v33[600]; // [esp+0h] [ebp-4D4h]
  int v34; // [esp+4B0h] [ebp-24h]
  int v35; // [esp+4B4h] [ebp-20h]
  int v36; // [esp+4B8h] [ebp-1Ch]
  _DWORD v37[2]; // [esp+4BCh] [ebp-18h] BYREF
  int v38; // [esp+4C4h] [ebp-10h]
  int v39; // [esp+4C8h] [ebp-Ch]
  int v40; // [esp+4CCh] [ebp-8h]
  int v41; // [esp+4D0h] [ebp-4h] BYREF

  v40 = 0;
  while ( !(_WORD)v40 )
  {
    v40 = 1;
    v38 = 0;
    v36 = 0;
    for ( i = 0; i < 300; ++i )
    {
      v3 = dword_192B14 + 26 * i;
      v4 = *(_WORD *)(v3 + 6);
      if ( *(int16_t *)v3 > 0 && *(int16_t *)(v3 + 19) > 0 && !*(_BYTE *)(v3 + 8) )
      {
        if ( word_17D853 && *(_BYTE *)(v3 + 23) != 0xFF
          || !word_17D853
          && (*(uint8_t *)(dword_192864 + 313 * v4 + 32) == a1
           || a1 == word_19988E
           && (v5 = dword_192B14 + 26 * i, v6 = *(_WORD *)(v5 + 4), v6 == *(_WORD *)(v5 + 6))
           && *(uint8_t *)(dword_192864 + 313 * v6 + 32) != a1) )
        {
          if ( *(_BYTE *)(dword_192B14 + 26 * i + 8) )
          {
            v9 = 26 * v4;
            v10 = dword_192B14 + v9;
            LOWORD(v9) = *(_WORD *)(dword_192B14 + v9 + 9);
            v41 = v9;
            LOWORD(v9) = *(_WORD *)(v10 + 11);
            v37[0] = v9;
          }
          else
          {
            sub_49ED1(v4, &v41, v37);
            HIWORD(v7) = HIWORD(dword_192864);
            v8 = dword_192864 + 313 * v4;
            LOWORD(v7) = *(uint8_t *)(v8 + 33);
            v41 += 20 * v7;
            LOWORD(v8) = *(uint8_t *)(v8 + 34);
            v37[0] += 20 * v8;
          }
          v34 = i;
          v11 = (uint8_t)sub_3CEB7(i, v41, SLOWORD(v37[0]), *(uint8_t *)(dword_192B14 + 26 * i + 22));
          if ( sub_3CE4F(v34) )
            v36 = 1;
          v12 = dword_192B14 + 26 * i;
          if ( (_WORD)v41 != *(_WORD *)(v12 + 9) || LOWORD(v37[0]) != *(_WORD *)(v12 + 11) )
            v40 = 0;
          if ( v11 == 1 )
          {
            v13 = (int16_t *)(dword_192B14 + 26 * i);
            if ( byte_17F80F[28 * *v13] != 4 || *((_BYTE *)v13 + 25) == 1 )
            {
              v14 = (int16_t)v38;
              v15 = dword_192B14;
              v33[(int16_t)v38] = i;
              LOWORD(v15) = *(_WORD *)(v15 + 26 * i + 6);
              ++v38;
              v33[v14 + 300] = v15;
            }
          }
        }
      }
    }
    if ( (_WORD)v36 )
    {
      v16 = sub_124D41();
      v17 = sub_2F4EE(v16);
      sub_1077D(v17);
    }
    for ( j = 0; j < (int16_t)v38; ++j )
    {
      v21 = j;
      v35 = (int16_t)v33[v21];
      v22 = *(_WORD *)(26 * v35 + dword_192B14 + 6);
      if ( v22 == v33[v21 + 300] )
      {
        v23 = dword_192864 + 313 * v22;
        if ( *(_BYTE *)(v23 + 36)
          || (LOWORD(v23) = *(uint8_t *)(v23 + 32), v37[1] = v23, sub_3BB3D(v35) == (_WORD)v23)
          && v22 != *(_WORD *)(dword_192B14 + 26 * (int16_t)v33[j] + 4) )
        {
          sub_3BC80(v33[j]);
        }
        else
        {
          if ( *(_BYTE *)(dword_192B14 + 26 * j + 8) )
          {
            v19 = 26 * v22;
            v20 = v19 + dword_192B14;
            LOWORD(v19) = *(_WORD *)(v19 + dword_192B14 + 9);
            v41 = v19;
            LOWORD(v19) = *(_WORD *)(v20 + 11);
            v37[0] = v19;
          }
          else
          {
            v24 = v22;
            v25 = 313 * v22;
            v26 = &v41;
            sub_49ED1(v24, &v41, v37);
            HIWORD(v27) = HIWORD(dword_192864);
            LOWORD(v26) = *(uint8_t *)(v25 + dword_192864 + 33);
            v41 += 20 * (_DWORD)v26;
            LOWORD(v27) = *(uint8_t *)(v25 + dword_192864 + 34);
            v37[0] += 20 * v27;
          }
          sub_3D2DF((int16_t)v33[j], (int16_t)v41, SLOWORD(v37[0]));
        }
      }
    }
  }
  v28 = 0;
  while ( 1 )
  {
    HIWORD(v29) = HIWORD(dword_192B14);
    v30 = (int16_t *)(dword_192B14 + 26 * v28);
    LOWORD(v29) = v30[3];
    v39 = v29;
    if ( *v30 <= 0 || byte_17F80F[28 * *v30] == 4 || *((_BYTE *)v30 + 23) == 0xFF || *((_BYTE *)v30 + 8) )
    {
      v32 = dword_192B14 + 26 * v28;
      if ( *(_BYTE *)(v32 + 23) == 0xFF )
        *(_BYTE *)(v32 + 23) = 0;
    }
    else if ( word_17D853
           || *(uint8_t *)(dword_192864 + 313 * (int16_t)v39 + 32) == a1
           || a1 == word_19988E
           && (v31 = v30[2], v31 == (_WORD)v39)
           && *(uint8_t *)(dword_192864 + 313 * v31 + 32) != a1 )
    {
      ++*(_BYTE *)(dword_192B14 + 26 * v28 + 23);
    }
    if ( ++v28 >= 300 )
      JUMPOUT(0x42DE1);
  }
}
// 4528A: control flows out of bounds to 42DE1
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 17D853: using guessed type int16_t word_17D853;
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 19988E: using guessed type int16_t word_19988E;


//----- (0004528F) --------------------------------------------------------
void __fastcall sub_4528F( int a1)
{
  int v2; // ecx
  int v3; // ebx
  int16_t v4; // bx
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int16_t i; // cx
  int16_t j; // dx
  int v10; // eax
  int v11; // edi
  int16_t v12; // [esp+0h] [ebp-4h]

  v2 = 313 * a1;
  if ( !*(_BYTE *)(v2 + dword_192864 + 49) || sub_3E57C(a1) )
  {
LABEL_3:
    LOWORD(v3) = 0;
    goto LABEL_28;
  }
  v4 = *(uint8_t *)(v2 + dword_192864 + 58);
  if ( (uint16_t)sub_1276F0(v2 + dword_192864 + 76, 2u) == 1
    && !(uint16_t)sub_1276F0(v2 + dword_192864 + 178, 2u) )
  {
    v4 += 5;
  }
  v5 = dword_192864 + 313 * a1;
  if ( *(_BYTE *)(v5 + 32) > 9u )
    v6 = *(int16_t *)(v5 + 256) * v4 / *(int16_t *)(v5 + 202);
  else
    v6 = v4
       * (*(int16_t *)(v5 + 256) - *(int16_t *)(v5 + 202) / 2)
       / (*(int16_t *)(v5 + 202) - *(int16_t *)(v5 + 202) / 2);
  LOWORD(v3) = v6;
  if ( (v6 & 0x8000u) != 0 )
    LOWORD(v3) = 0;
  v7 = dword_192864 + 313 * a1;
  if ( *(_BYTE *)(v7 + 32) < 8u && *(_BYTE *)(dword_197F98 + 3753 * *(uint8_t *)(v7 + 32) + 2236) )
    LOWORD(v3) = v3 + 4;
  if ( (int16_t)v3 > 0 )
  {
    v12 = 0;
    for ( i = 0; i < word_1998C0; ++i )
    {
      if ( *(uint8_t *)(dword_192864 + 313 * i + 66) == a1 && sub_42A27(i) )
      {
        for ( j = 0; j < 8; ++j )
        {
          v10 = 11 * j + dword_192864 + 313 * i;
          if ( *(_WORD *)(v10 + 82) == 39 )
            v12 += *(uint8_t *)(v10 + 84);
        }
      }
    }
    v11 = *(uint8_t *)(dword_192864 + 313 * a1 + 37) + 1;
    if ( v12 >= v11 )
      goto LABEL_3;
    v3 = (int16_t)v3 - (int16_t)v3 * v12 / v11;
    if ( (int16_t)v3 < 1 )
      LOWORD(v3) = 1;
  }
LABEL_28:
  if ( (int16_t)v3 <= 0 )
    *(_BYTE *)(dword_192864 + 313 * a1 + 75) = 0;
  JUMPOUT(0x42DE1);
}
// 45456: control flows out of bounds to 42DE1
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int dword_197F98;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0004545B) --------------------------------------------------------
void __usercall sub_4545B(int a1, int a2)
{
  int16_t v2; // di
  int16_t v3; // bx
  int16_t i; // si
  uint8_t *v5; // eax

  v2 = 0;
  v3 = 0;
  if ( *(_BYTE *)(dword_192864 + 36) != 5 )
    v3 = (uint16_t)sub_3A142(a1, a2) != 0;
  for ( i = 1; i < word_1998C0; ++i )
  {
    v5 = (uint8_t *)(dword_192864 + 313 * i);
    if ( v5[36] != 5 && !v5[176] )
    {
      if ( v5[32] == word_1998AC )
        ++v2;
      else
        ++v3;
    }
  }
  JUMPOUT(0x42DE2);
}
// 45502: control flows out of bounds to 42DE2
// 192864: using guessed type int dword_192864;
// 199890: using guessed type int16_t word_199890;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (00045507) --------------------------------------------------------
void __usercall sub_45507( int a1, int a2, int a3)
{
  int v4; // edx
  int i; // ecx
  int v6; // eax
  int j; // ecx

  if ( a1 || (int16_t)sub_3A142(a2, a3) > 0 )
  {
    v4 = -1;
    for ( i = 0; (int16_t)i < word_1998C0 && word_19296C[(int16_t)i] != -10; ++i )
    {
      if ( a1 == word_19296C[(int16_t)i] )
        v4 = i;
    }
    v6 = (int16_t)v4;
    if ( (int16_t)v4 == -1 )
    {
      v4 = -1;
      for ( j = 0; (int16_t)j < word_1998C0; ++j )
      {
        v6 = (int16_t)v4;
        if ( (int16_t)v4 != -1 )
          break;
        v6 = 2 * (int16_t)j;
        if ( *(int16_t *)((char *)word_19296C + v6) == -1 )
        {
          v4 = j;
          word_19296C[(int16_t)j] = a1;
        }
      }
    }
    word_1998D8 = v4;
    word_1998F8 = a1;
    sub_2C601(v6, v4);
  }
}
// 19296C: using guessed type int16_t word_19296C[];
// 1998C0: using guessed type int16_t word_1998C0;
// 1998D8: using guessed type int16_t word_1998D8;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (000455A4) --------------------------------------------------------
void __fastcall sub_455A4(int a1, int a2)
{
  int16_t v2; // bx
  int v3; // ecx
  int16_t v4; // ax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int16_t v8; // ax
  int16_t v9; // ax
  int16_t v10; // [esp+0h] [ebp-4h]

  v2 = word_1998D8;
  v3 = 0;
  v10 = word_1998F8;
  sub_4545B(0, word_1998D8);
  if ( !v4 )
  {
    while ( 1 )
    {
      if ( word_19296C[++word_1998D8] == -10 )
      {
        if ( (uint16_t)word_1998D8 > 1u )
          word_1998D8 = 0;
        else
          word_1998D8 = v2;
      }
      if ( !word_19296C[word_1998D8] && (uint16_t)sub_3A142(v3, v2) )
        v3 = 1;
      if ( v2 == word_1998D8 )
        break;
      if ( word_19296C[word_1998D8] || (_WORD)v3 )
      {
        v5 = word_19296C[word_1998D8];
        if ( v5 != -1 )
        {
          a2 = *(uint8_t *)(dword_192864 + 313 * v5 + 32);
          if ( !word_199206[a2] && sub_42A27(v5) )
            break;
        }
      }
    }
    if ( word_1998D8 >= 0 )
      word_1998F8 = word_19296C[word_1998D8];
    else
      word_1998F8 = -1;
    if ( word_1998F8 < 0 )
    {
      word_1998D8 = v2;
      word_1998F8 = v10;
    }
    else
    {
      if ( word_17D853 || !(uint16_t)sub_339A7(word_1998F8, a2, v2) && word_19B578 )
      {
        v6 = dword_192864 + 313 * word_1998F8;
        a2 = *(uint8_t *)(v6 + 34);
        sub_49D09(*(uint8_t *)(v6 + 33), a2);
      }
      sub_465D0();
      sub_46CC8(word_1998F8, a2);
      sub_2C601(v7, a2);
      if ( *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32) == word_1998AC )
        v8 = word_192B10[0];
      else
        v8 = word_192B12;
      word_199900 = v8;
      if ( word_1998CE )
      {
        if ( *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32) == word_1998AC )
          v9 = word_19988E;
        else
          v9 = word_1998AC;
        word_199908 = v9;
        if ( *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32) == word_19999C )
        {
          word_1998C4 = word_199906;
          sub_F6816(*(int16_t *)(3753 * word_199908 + dword_197F98 + 43), 1003, (int)&word_1998C4, 2u);
        }
        sub_3FBFE(1);
      }
    }
    word_1998DA = 0;
    if ( word_1998E0 )
      sub_2C555();
  }
  JUMPOUT(0x42DE1);
}
// 455D0: control flows out of bounds to 42DE1
// 455C9: variable 'v4' is possibly undefined
// 45732: variable 'v7' is possibly undefined
// 17D853: using guessed type int16_t word_17D853;
// 192864: using guessed type int dword_192864;
// 19296C: using guessed type int16_t word_19296C[];
// 192B10: using guessed type int16_t word_192B10[];
// 192B12: using guessed type int16_t word_192B12;
// 197F98: using guessed type int dword_197F98;
// 199206: using guessed type int16_t word_199206[15];
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C4: using guessed type int16_t word_1998C4;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998D8: using guessed type int16_t word_1998D8;
// 1998DA: using guessed type int16_t word_1998DA;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F8: using guessed type int16_t word_1998F8;
// 199900: using guessed type int16_t word_199900;
// 199906: using guessed type int16_t word_199906;
// 199908: using guessed type int16_t word_199908;
// 19999C: using guessed type int16_t word_19999C;
// 19B578: using guessed type int16_t word_19B578;


//----- (0004584C) --------------------------------------------------------
_BOOL1 __fastcall sub_4584C( int a1, int a2)
{
  return *(_BYTE *)(313 * a1 + dword_192864 + 11 * a2 + 90) == 1;
}
// 192864: using guessed type int dword_192864;


//----- (0004586C) --------------------------------------------------------
_BOOL1 __fastcall sub_4586C( int a1, int a2)
{
  return *(_BYTE *)(313 * a1 + dword_192864 + 11 * a2 + 90) != 1;
}
// 192864: using guessed type int dword_192864;


//----- (0004588C) --------------------------------------------------------
int __fastcall sub_4588C(int result)
{
  int16_t v1; // bx
  int16_t i; // dx
  int v3; // eax

  v1 = result;
  for ( i = 0; i < word_1998C0; ++i )
  {
    if ( *(uint8_t *)(313 * i + dword_192864 + 74) == v1 )
      sub_3AFB3(i);
    v3 = 313 * i + dword_192864;
    if ( *(uint8_t *)(v3 + 311) == v1 )
    {
      *(_BYTE *)(v3 + 310) = 0;
      *(_BYTE *)(v3 + 311) = -1;
    }
    result = 313 * i + dword_192864;
    if ( *(uint8_t *)(result + 66) == v1 )
      *(_BYTE *)(result + 66) = -1;
  }
  return result;
}
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0004590D) --------------------------------------------------------
void sub_4590D()
{
  int16_t i; // ax

  for ( i = 0; i < 8; ++i )
    ;
  JUMPOUT(0x42A5B);
}
// 4595F: control flows out of bounds to 42A5B
// 192864: using guessed type int dword_192864;


//----- (00045964) --------------------------------------------------------
int __fastcall sub_45964( int a1)
{
  int v2; // edx
  int16_t v3; // ax
  int result; // eax
  int v5; // ecx
  int v6; // eax

  if ( word_1998F6 == 1 && !word_1998E0 )
  {
    v2 = a1;
    sub_33B19(a1);
    if ( !v3 )
      sub_49D09(*(uint8_t *)(dword_192864 + 313 * v2 + 33), *(uint8_t *)(dword_192864 + 313 * v2 + 34));
    sub_32D94(a1);
  }
  result = sub_3897A(a1);
  if ( !(_WORD)result )
  {
    v5 = 313 * a1;
    v6 = dword_192864;
    *(_BYTE *)(v5 + dword_192864 + 36) = 5;
    *(_BYTE *)(v5 + v6 + 75) = 2;
    sub_3891E(a1);
    return sub_4588C(a1);
  }
  return result;
}
// 4598A: variable 'v3' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F6: using guessed type int16_t word_1998F6;


//----- (000459E7) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=294)) - nutno dohledat rucne v IDA @ 0x45E7F */
int __fastcall sub_459E7(_DWORD)
{
  DECOMP_TODO("call analysis failed (funcsize=294)");
}


//----- (00045EA7) --------------------------------------------------------
void sub_45EA7()
{
  int16_t v0; // si
  int16_t *v1; // ebx
  int16_t v2; // bx
  int16_t v3; // ax
  _WORD *v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // [esp+4h] [ebp-18h]
  int16_t v8; // [esp+8h] [ebp-14h]
  int16_t v9; // [esp+14h] [ebp-8h]

  word_1998FA = 0;
  sub_128AB6(0, 0, 639, 350);
  sub_12B634();
  v0 = 0;
  while ( 1 )
  {
    v1 = (int16_t *)(26 * v0 + dword_192B14);
    v7 = 26 * v0;
    if ( *v1 > 0 && sub_3D259((*(int16_t *)((char *)v1 + 9) - 8) / 20, (*(int16_t *)((char *)v1 + 11) - 8) / 20) )
    {
      v2 = *(_WORD *)(v7 + dword_192B14 + 9) - 20 * word_1998F0;
      v3 = *(_WORD *)(v7 + dword_192B14 + 11);
      v8 = v3 - 20 * word_1998F2 - 8;
      v9 = v3 - 20 * word_1998F2 - 16;
      word_18F510[v0] = sub_114A00(v2 - 16, v9, v2 - 8, v8, &unk_178E18, 0);
      v4 = (_WORD *)(12 * (v0 + 577) + dword_19287C);
      v4[1] = 0;
      *v4 = 12;
      v4[2] = v2 - 16;
      v4[4] = v2 - 8;
      v4[3] = v9;
      ++word_1998FA;
      v4[5] = v8;
    }
    else
    {
      v5 = v0 + 577;
      word_18F08E[v5] = -1000;
      v5 *= 12;
      v6 = dword_19287C;
      *(_WORD *)(v5 + dword_19287C + 4) = 0;
      *(_WORD *)(v5 + v6 + 8) = 0;
      *(_WORD *)(v5 + v6 + 6) = 0;
      *(_WORD *)(v5 + v6 + 10) = 0;
      *(_WORD *)(v5 + v6 + 2) = 0;
      *(_WORD *)(v5 + v6) = 0;
    }
    if ( ++v0 >= 300 )
    {
      sub_12B65C();
      sub_128BE7();
      JUMPOUT(0x42DE1);
    }
  }
}
// 46025: control flows out of bounds to 42DE1
// 18F08E: using guessed type int16_t word_18F08E[529];
// 18F510: using guessed type int16_t word_18F510[300];
// 19287C: using guessed type int dword_19287C;
// 192B14: using guessed type int dword_192B14;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998FA: using guessed type int16_t word_1998FA;


//----- (0004602A) --------------------------------------------------------
void sub_4602A()
{
  int16_t v0; // bx
  int v1; // eax
  int16_t v2; // bx
  int v3; // eax
  int v4; // eax
  int16_t v5; // bx
  int16_t k; // si
  int16_t v7; // dx
  int16_t v8; // cx
  int16_t i; // si
  int v10; // eax
  int16_t j; // dx
  int v12; // eax
  int v13; // eax
  int16_t v14; // bx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax

  if ( word_199876 == 1 )
  {
    word_192C80[0] = 617;
    word_192C82[0] = 292;
    word_192C84[0] = 446;
    word_192C86[0] = 374;
    word_192C88[0] = 472;
    word_192C8A = 623;
    word_192C8C = 271;
    word_192C8E = 362;
    word_192C90 = 330;
    word_192C92 = 386;
    word_192C94 = 624;
    word_192C96 = 332;
    word_192C98 = 362;
    word_192C9A = 394;
    word_192C9C = 386;
    word_192C9E = 625;
    word_192CA0 = 271;
    word_192CA2 = 389;
    word_192CA4 = 330;
    word_192CA6 = 414;
    word_192CA8 = 626;
    word_192CAA = 333;
    word_192CAC = 389;
    word_192CAE = 394;
    word_192CB0 = 414;
    word_192CB2 = 627;
    word_192CB4 = 271;
    word_192CB6 = 418;
    word_192CB8 = 330;
    word_192CBA = 441;
    word_192CBC = 628;
    word_192CBE = 333;
    word_192CC0 = 418;
    word_192CC2 = 394;
    word_192CC4 = 441;
    v0 = 7;
  }
  else
  {
    word_192C80[0] = 695;
    word_192C82[0] = 282;
    word_192C84[0] = 350;
    word_192C86[0] = 384;
    word_192C88[0] = 371;
    word_192C8A = 696;
    word_192C8C = 264;
    word_192C8E = 383;
    word_192C90 = 407;
    word_192C92 = 396;
    word_192C94 = 697;
    word_192C96 = 264;
    word_192C98 = 399;
    word_192C9A = 407;
    word_192C9C = 412;
    word_192C9E = 698;
    word_192CA0 = 264;
    word_192CA2 = 415;
    word_192CA4 = 407;
    word_192CA6 = 428;
    word_192CA8 = 699;
    word_192CAA = 264;
    word_192CAC = 431;
    word_192CAE = 407;
    word_192CB0 = 444;
    word_192CB2 = 700;
    word_192CB4 = 264;
    word_192CB6 = 447;
    word_192CB8 = 407;
    word_192CBA = 460;
    v0 = 6;
  }
  v1 = 5 * v0;
  word_192C80[v1] = 618;
  word_192C82[v1] = 10;
  word_192C84[v1] = 360;
  word_192C86[v1] = 106;
  v2 = v0 + 1;
  word_192C88[v1] = 471;
  v3 = 5 * v2;
  word_192C82[v3] = 502;
  word_192C84[v3] = 360;
  word_192C86[v3] = 626;
  word_192C88[v3] = 471;
  ++v2;
  word_192C80[v3] = (word_1998DA == 1) + 620;
  v4 = 5 * v2;
  word_192C80[v4] = 622;
  word_192C82[v4] = 399;
  word_192C84[v4] = 360;
  word_192C86[v4] = 495;
  v5 = v2 + 1;
  word_192C88[v4] = 471;
  if ( word_1998D6 )
  {
    v8 = 0;
    for ( i = 0; i < 39; ++i )
    {
      if ( (uint16_t)sub_1276F0(dword_192864 + 313 * word_1998F8 + 76, i) == 1 )
      {
        v10 = 5 * (v8++ + v5);
        word_192C80[v10] = *(int16_t *)((char *)&word_17EEE6 + 47 * i);
      }
    }
    for ( j = v5 + v8; j < v5 + v8 + 8; ++j )
    {
      v12 = 5 * j;
      word_192C80[v12] = -1;
    }
  }
  else
  {
    for ( k = v5; k < v5 + 8; ++k )
    {
      v7 = word_17F80D[14 * *(int16_t *)(11 * (k - v5) + dword_192864 + 313 * word_1998F8 + 82)];
      word_192C80[5 * k] = v7;
      if ( !v7 )
        word_192C80[5 * k] = -1;
    }
  }
  v13 = 5 * v5;
  word_192C82[v13] = 114;
  word_192C84[v13] = 379;
  word_192C86[v13] = 264;
  v14 = v5 + 1;
  word_192C88[v13] = 389;
  v15 = 5 * v14;
  word_192C82[v15] = 114;
  word_192C84[v15] = 390;
  word_192C86[v15] = 264;
  ++v14;
  word_192C88[v15] = 400;
  v16 = 5 * v14;
  word_192C82[v16] = 114;
  word_192C84[v16] = 401;
  word_192C86[v16] = 264;
  ++v14;
  word_192C88[v16] = 411;
  v17 = 5 * v14;
  word_192C82[v17] = 114;
  word_192C84[v17] = 412;
  word_192C86[v17] = 264;
  ++v14;
  word_192C88[v17] = 422;
  v18 = 5 * v14;
  word_192C82[v18] = 114;
  word_192C84[v18] = 423;
  word_192C86[v18] = 264;
  ++v14;
  word_192C88[v18] = 433;
  v19 = 5 * v14;
  word_192C82[v19] = 114;
  word_192C84[v19] = 434;
  word_192C86[v19] = 264;
  ++v14;
  word_192C88[v19] = 444;
  v20 = 5 * v14;
  word_192C82[v20] = 114;
  word_192C84[v20] = 445;
  word_192C86[v20] = 264;
  ++v14;
  word_192C88[v20] = 455;
  v21 = 5 * v14;
  word_192C82[v21] = 114;
  word_192C84[v21] = 456;
  word_192C86[v21] = 264;
  word_192C88[v21] = 467;
  v22 = 5 * (int16_t)(v14 + 1);
  word_192C80[v22] = 629;
  word_192C82[v22] = 113;
  word_192C84[v22] = 360;
  word_192C86[v22] = 265;
  word_192C88[v22] = 471;
  sub_1196B8((int)word_192C80, (int16_t)(v14 + 2));
  JUMPOUT(0x42DE1);
}
// 465CB: control flows out of bounds to 42DE1
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17F80D: using guessed type int16_t word_17F80D[];
// 192864: using guessed type int dword_192864;
// 192C80: using guessed type int16_t word_192C80[];
// 192C82: using guessed type int16_t word_192C82[];
// 192C84: using guessed type int16_t word_192C84[];
// 192C86: using guessed type int16_t word_192C86[];
// 192C88: using guessed type int16_t word_192C88[];
// 192C8A: using guessed type int16_t word_192C8A;
// 192C8C: using guessed type int16_t word_192C8C;
// 192C8E: using guessed type int16_t word_192C8E;
// 192C90: using guessed type int16_t word_192C90;
// 192C92: using guessed type int16_t word_192C92;
// 192C94: using guessed type int16_t word_192C94;
// 192C96: using guessed type int16_t word_192C96;
// 192C98: using guessed type int16_t word_192C98;
// 192C9A: using guessed type int16_t word_192C9A;
// 192C9C: using guessed type int16_t word_192C9C;
// 192C9E: using guessed type int16_t word_192C9E;
// 192CA0: using guessed type int16_t word_192CA0;
// 192CA2: using guessed type int16_t word_192CA2;
// 192CA4: using guessed type int16_t word_192CA4;
// 192CA6: using guessed type int16_t word_192CA6;
// 192CA8: using guessed type int16_t word_192CA8;
// 192CAA: using guessed type int16_t word_192CAA;
// 192CAC: using guessed type int16_t word_192CAC;
// 192CAE: using guessed type int16_t word_192CAE;
// 192CB0: using guessed type int16_t word_192CB0;
// 192CB2: using guessed type int16_t word_192CB2;
// 192CB4: using guessed type int16_t word_192CB4;
// 192CB6: using guessed type int16_t word_192CB6;
// 192CB8: using guessed type int16_t word_192CB8;
// 192CBA: using guessed type int16_t word_192CBA;
// 192CBC: using guessed type int16_t word_192CBC;
// 192CBE: using guessed type int16_t word_192CBE;
// 192CC0: using guessed type int16_t word_192CC0;
// 192CC2: using guessed type int16_t word_192CC2;
// 192CC4: using guessed type int16_t word_192CC4;
// 199876: using guessed type int16_t word_199876;
// 1998D6: using guessed type int16_t word_1998D6;
// 1998DA: using guessed type int16_t word_1998DA;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (000465D0) --------------------------------------------------------
void sub_465D0()
{
  int v0; // edx
  int v1; // eax
  int v2; // edx
  int v3; // eax
  int v4; // edx
  int16_t v5; // ax
  int16_t v6; // ax
  int16_t v7; // ax
  int v8; // edx
  uint16_t v9; // ax
  int v10; // eax
  int v11; // edx
  int16_t v12; // ax
  uint16_t v13; // ax
  int16_t v14; // di
  int v15; // esi
  int16_t v16; // dx
  int16_t v17; // ax
  int v18; // edx
  int64_t v19; // [esp-Ch] [ebp-10h]
  int64_t v20; // [esp-Ch] [ebp-10h]
  int64_t v21; // [esp-Ch] [ebp-10h]
  int v22; // [esp+0h] [ebp-4h]

  LOWORD(v0) = word_1998F8 > -1 && *(uint8_t *)(313 * word_1998F8 + dword_192864 + 32) != word_1998AC;
  v0 = (int16_t)v0;
  sub_4602A();
  if ( word_192B10[(int16_t)v0] != 1
    && (byte_199F3A == 1
     || (v0 = word_1998F8, word_1998F8 <= -1)
     || (v0 = 313 * word_1998F8, *(uint8_t *)(dword_192864 + v0 + 32) == word_19999C)
     || word_1998C6) )
  {
    sub_11C2F0();
    if ( word_199876 == 1 )
    {
      sub_45EA7();
      HIDWORD(v19) = &word_19989E;
      LODWORD(v19) = &word_1998AA;
      word_1998DC = sub_114C72(byte_178E19, v0);
      word_1998BA = sub_114DCA(0, 0, 10, 10, 64, 36, v19, 0);
      if ( word_1998DA == 1 )
      {
        v5 = sub_11438B(505, 370, 622, 464, &unk_178E18, 0);
        word_1998B4 = -1000;
        word_1998B0 = v5;
      }
      else
      {
        HIDWORD(v20) = &word_199894;
        LODWORD(v20) = &word_199892;
        v6 = sub_114DCA(500, 364, 1, 1, 121, 102, v20, 0);
        word_1998B0 = -1000;
        word_1998B4 = v6;
      }
      word_1998B8 = sub_115383(114, 361, (int)&unk_178E18, (_WORD *)dword_192818, (int)&word_1998D6, 0, &unk_178E18, 41);
      word_19989C = sub_115383(187, 361, (int)&unk_178E18, (_WORD *)dword_192848, (int)&word_1998D6, 1, &unk_178E18, 41);
      word_199898 = sub_11523B(273, 364, (int)&unk_178E18, (_WORD *)dword_19286C, (int)&word_199902, byte_178E1B, 40);
      word_1998E6 = sub_11523B(337, 364, (int)&unk_178E18, (_WORD *)dword_192874, (int)&word_1998D4, byte_178E1D, 40);
      word_1998EC = sub_11523B(273, 392, (int)&unk_178E18, (_WORD *)dword_192860, (int)&word_1998E8, byte_178E1F, 40);
      word_199896 = (uint16_t)sub_1151B0(337, 392, (int)&unk_178E18, (_WORD *)dword_192870, byte_178E21, 40);
      word_1998A0 = (uint16_t)sub_1151B0(273, 420, (int)&unk_178E18, (_WORD *)dword_192838, byte_178E23, 40);
      word_19989A = (uint16_t)sub_1151B0(337, 420, (int)&unk_178E18, (_WORD *)dword_192830, byte_178E25, 40);
      v7 = sub_114C72(byte_178E27, 420);
      word_1998B2 = -100;
      word_1998B6 = -100;
      word_1998A6 = -100;
      word_1998A8 = -100;
      word_1998A4 = -100;
      v8 = v7;
      word_1998AE = -100;
      dword_19B574 = v7;
      if ( word_1998AC < 8
        && (v8 = 3753 * word_1998AC, *(_BYTE *)(dword_197F98 + v8 + 40) == 100)
        && word_19988E < 8
        && (v8 = 3753 * word_19988E, *(_BYTE *)(dword_197F98 + v8 + 40) == 100)
        || word_1998AC < 8
        && (v8 = *(_BYTE *)(dword_197F98 + 3753 * word_1998AC + 40) != 100,
            *(_BYTE *)(dword_197F98 + 3753 * word_1998AC + 40) == 100)
        && word_19988E < 8
        && (v8 = *(_BYTE *)(dword_197F98 + 3753 * word_19988E + 40) != 100,
            *(_BYTE *)(dword_197F98 + 3753 * word_19988E + 40) == 100) )
      {
        word_1998DE = -1000;
      }
      else
      {
        word_1998DE = sub_114C72(byte_178E29, v8);
      }
      v9 = (uint16_t)sub_1151B0(298, 448, (int)&unk_178E18, (_WORD *)dword_192828, &off_178E2B, 40);
    }
    else
    {
      v10 = 0;
      do
      {
        v11 = (int16_t)v10++;
        word_18F510[v11] = -1000;
      }
      while ( (int16_t)v10 < 300 );
      HIDWORD(v21) = &word_199894;
      LODWORD(v21) = &word_199892;
      word_1998DC = -100;
      word_1998BA = -100;
      v12 = sub_114DCA(500, 364, 1, 1, 121, 102, v21, 0);
      word_1998B0 = -100;
      word_1998B8 = -100;
      word_1998B4 = v12;
      word_19989C = -100;
      word_1998B6 = sub_11438B(264, 383, 407, 396, &unk_178E18, 41);
      word_1998A6 = sub_11438B(264, 399, 407, 412, &unk_178E18, 41);
      word_1998B2 = sub_11438B(264, 415, 407, 428, &unk_178E18, 41);
      word_1998A8 = sub_11438B(264, 431, 407, 444, &unk_178E18, 41);
      word_1998A4 = sub_11438B(264, 447, 407, 460, &unk_178E18, 41);
      v13 = (uint16_t)sub_1151B0(283, 348, (int)&unk_178E18, (_WORD *)dword_19281C, &unk_178E18, 40);
      word_199898 = -100;
      word_1998E6 = -100;
      word_1998EC = -100;
      word_199896 = -100;
      word_1998A0 = -100;
      word_19989A = -100;
      dword_19B574 = -100;
      word_1998AE = v13;
      word_1998DE = -1000;
      v9 = (uint16_t)sub_1151B0(298, 301, (int)&unk_178E18, (_WORD *)dword_192828, (_BYTE *)&off_178E2B + 2, 40);
    }
    word_1998BC = v9;
    v22 = 379;
    v14 = 389;
    v15 = 0;
    do
    {
      v16 = v22;
      v22 += 11;
      v17 = sub_11438B(120, v16, 255, v14, &unk_178E18, 41);
      v14 += 11;
      v18 = (int16_t)v15++;
      word_18F500[v18] = v17;
    }
    while ( (int16_t)v15 < 8 );
    word_199888 = sub_11438B(15, 379, 100, 460, byte_178E2F, 41);
  }
  else
  {
    v1 = 0;
    do
    {
      v2 = (int16_t)v1++;
      word_18F510[v2] = -1000;
    }
    while ( (int16_t)v1 < 300 );
    word_1998DC = -1000;
    word_1998BA = -1000;
    word_1998B4 = -1000;
    word_1998B0 = -1000;
    word_1998A6 = -100;
    word_1998B2 = -100;
    word_1998B6 = -100;
    word_1998AE = -100;
    word_1998A8 = -100;
    word_1998A4 = -100;
    word_1998E6 = -100;
    word_1998EC = -100;
    word_199896 = -100;
    word_1998A0 = -100;
    word_19989A = -100;
    dword_19B574 = -100;
    v3 = 0;
    do
    {
      v4 = (int16_t)v3++;
      word_18F500[v4] = -1000;
    }
    while ( (int16_t)v3 < 8 );
    word_199888 = -1000;
    word_1998B8 = -1000;
    word_19989C = -1000;
    word_1998BC = -1000;
    word_1998DE = -1000;
  }
  JUMPOUT(0x42DE1);
}
// 46750: control flows out of bounds to 42DE1
// 178E19: using guessed type _BYTE byte_178E19[2];
// 178E1B: using guessed type _BYTE byte_178E1B[2];
// 178E1D: using guessed type _BYTE byte_178E1D[2];
// 178E1F: using guessed type _BYTE byte_178E1F[2];
// 178E21: using guessed type _BYTE byte_178E21[2];
// 178E23: using guessed type _BYTE byte_178E23[2];
// 178E25: using guessed type _BYTE byte_178E25[2];
// 178E27: using guessed type _BYTE byte_178E27[2];
// 178E29: using guessed type _BYTE byte_178E29[2];
// 178E2B: using guessed type _UNKNOWN *off_178E2B;
// 178E2F: using guessed type _BYTE byte_178E2F[5];
// 18F500: using guessed type int16_t word_18F500[];
// 18F510: using guessed type int16_t word_18F510[300];
// 192818: using guessed type int dword_192818;
// 19281C: using guessed type int dword_19281C;
// 192828: using guessed type int dword_192828;
// 192830: using guessed type int dword_192830;
// 192838: using guessed type int dword_192838;
// 192848: using guessed type int dword_192848;
// 192860: using guessed type int dword_192860;
// 192864: using guessed type int dword_192864;
// 19286C: using guessed type int dword_19286C;
// 192870: using guessed type int dword_192870;
// 192874: using guessed type int dword_192874;
// 192B10: using guessed type int16_t word_192B10[];
// 197F98: using guessed type int dword_197F98;
// 199876: using guessed type int16_t word_199876;
// 199888: using guessed type int16_t word_199888;
// 19988E: using guessed type int16_t word_19988E;
// 199892: using guessed type int16_t word_199892;
// 199894: using guessed type int16_t word_199894;
// 199896: using guessed type int16_t word_199896;
// 199898: using guessed type int16_t word_199898;
// 19989A: using guessed type int16_t word_19989A;
// 19989C: using guessed type int16_t word_19989C;
// 19989E: using guessed type int16_t word_19989E;
// 1998A0: using guessed type int16_t word_1998A0;
// 1998A4: using guessed type int16_t word_1998A4;
// 1998A6: using guessed type int16_t word_1998A6;
// 1998A8: using guessed type int16_t word_1998A8;
// 1998AA: using guessed type int16_t word_1998AA;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998AE: using guessed type int16_t word_1998AE;
// 1998B0: using guessed type int16_t word_1998B0;
// 1998B2: using guessed type int16_t word_1998B2;
// 1998B4: using guessed type int16_t word_1998B4;
// 1998B6: using guessed type int16_t word_1998B6;
// 1998B8: using guessed type int16_t word_1998B8;
// 1998BA: using guessed type int16_t word_1998BA;
// 1998BC: using guessed type int16_t word_1998BC;
// 1998C6: using guessed type int16_t word_1998C6;
// 1998D4: using guessed type int16_t word_1998D4;
// 1998D6: using guessed type int16_t word_1998D6;
// 1998DA: using guessed type int16_t word_1998DA;
// 1998DC: using guessed type int16_t word_1998DC;
// 1998DE: using guessed type int16_t word_1998DE;
// 1998E6: using guessed type int16_t word_1998E6;
// 1998E8: using guessed type int16_t word_1998E8;
// 1998EC: using guessed type int16_t word_1998EC;
// 1998F8: using guessed type int16_t word_1998F8;
// 199902: using guessed type int16_t word_199902;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;
// 19B574: using guessed type int dword_19B574;


//----- (00046CC8) --------------------------------------------------------
void __fastcall sub_46CC8( int a1, int a2)
{
  int16_t i; // bx
  int v3; // eax
  int v4; // ecx
  int16_t j; // bx
  uint8_t *v6; // eax
  int16_t n; // si
  int v8; // eax
  int16_t ii; // cx
  int v10; // kr04_4
  int16_t k; // si
  int v12; // ecx
  int v13; // eax
  int16_t m; // cx
  int v15; // esi
  int v16; // eax

  for ( i = 0; i < 81; ++i )
  {
    v3 = 0;
    do
    {
      v4 = (int16_t)v3++;
      word_18C9A8[68 * i + v4] = -1;
    }
    while ( (int16_t)v3 < 68 );
  }
  if ( word_199876 == 1 )
  {
    for ( j = 0; j < word_1998C0; ++j )
    {
      v6 = (uint8_t *)(dword_192864 + 313 * j);
      if ( !v6[36] )
      {
        word_18C9A8[68 * v6[33] + v6[34]] = j;
        if ( j != a1 || word_1998D4 == 1 || word_1998E8 == 1 )
        {
          if ( j )
          {
            v10 = *(uint8_t *)(dword_192864 + 313 * j + 37) + 1;
            a2 = v10 / 2;
            if ( (uint16_t)(v10 / 2) )
            {
              if ( (uint16_t)(v10 / 2) <= 1u )
              {
                for ( k = 0; k < 2; ++k )
                {
                  v12 = 0;
                  do
                  {
                    v13 = 136 * (k + *(uint8_t *)(dword_192864 + 313 * j + 33))
                        + 2 * ((int16_t)v12++ + *(uint8_t *)(dword_192864 + 313 * j + 34));
                    *(int16_t *)((char *)word_18C9A8 + v13) = j;
                  }
                  while ( (int16_t)v12 < 2 );
                }
              }
              else if ( (uint16_t)(v10 / 2) <= 3u )
              {
                for ( m = 0; m < 3; ++m )
                {
                  v15 = 0;
                  do
                  {
                    v16 = 136 * (m + *(uint8_t *)(313 * j + dword_192864 + 33))
                        + 2 * (*(uint8_t *)(313 * j + dword_192864 + 34) + (int16_t)v15++);
                    *(int16_t *)((char *)word_18C9A8 + v16) = j;
                  }
                  while ( (int16_t)v15 < 3 );
                }
              }
            }
          }
          else
          {
            if ( word_199878 != -1 )
            {
              switch ( *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * word_199878 + 2) + 5) )
              {
                case 0:
                  LOWORD(a2) = 3;
                  goto LABEL_19;
                case 1:
                  LOWORD(a2) = 4;
                  goto LABEL_19;
                case 2:
                  break;
                case 3:
                  LOWORD(a2) = 7;
                  goto LABEL_19;
                case 4:
                  LOWORD(a2) = 8;
                  goto LABEL_19;
                default:
                  goto LABEL_19;
              }
            }
            LOWORD(a2) = 6;
LABEL_19:
            for ( n = 0; n < (int16_t)a2; ++n )
            {
              for ( ii = 0; ii < (int16_t)a2; ++ii )
              {
                v8 = *(uint8_t *)(dword_192864 + 34) + ii;
                word_18C9A8[68 * n + 68 * *(uint8_t *)(dword_192864 + 33) + v8] = 0;
              }
            }
          }
        }
      }
    }
  }
  if ( a1 == word_1998F8 )
  {
    sub_4752F(a1, *(_WORD *)(313 * a1 + dword_192864 + 61), 1);
    sub_46F42();
  }
  JUMPOUT(0x42DE1);
}
// 46F3D: control flows out of bounds to 42DE1
// 18C9A8: using guessed type int16_t word_18C9A8[4979];
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199876: using guessed type int16_t word_199876;
// 199878: using guessed type int16_t word_199878;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998D4: using guessed type int16_t word_1998D4;
// 1998E8: using guessed type int16_t word_1998E8;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (00046F42) --------------------------------------------------------
void sub_46F42()
{
  int16_t v0; // dx
  int16_t *v1; // eax
  int16_t v2; // bx
  int16_t i; // dx
  int16_t v4; // di
  int16_t v5; // si
  _WORD *v6; // eax
  int16_t v7; // cx
  int v8; // eax
  int16_t v9; // si
  int16_t v10; // di
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // eax
  int16_t v16; // dx
  int v17; // ebx
  int v18; // eax
  int v19; // eax
  _WORD *v20; // eax
  int16_t v21; // dx
  _WORD *v22; // eax
  int16_t v23; // di
  int16_t v24; // dx
  _WORD *v25; // eax
  int16_t *v26; // eax
  int v27; // ebx
  int v28; // eax
  int16_t *v29; // eax
  int v30; // eax
  int v31; // ebx
  int16_t *v32; // eax
  int v33; // ebx
  int v34; // eax
  _WORD *v35; // eax
  int16_t v36; // [esp+28h] [ebp-34h]
  int16_t v37; // [esp+2Ch] [ebp-30h]
  int16_t v38; // [esp+38h] [ebp-24h]
  int16_t v39; // [esp+44h] [ebp-18h]
  int16_t v40; // [esp+48h] [ebp-14h]
  int16_t v41; // [esp+4Ch] [ebp-10h]
  int16_t v42; // [esp+50h] [ebp-Ch]
  int16_t v43; // [esp+54h] [ebp-8h]

  if ( byte_199F3A != 1 && *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 32) != word_19999C )
  {
    v0 = 1;
    word_17CF82 = word_19987C;
    v1 = &word_17CF82;
    goto LABEL_69;
  }
  if ( word_199876 != 1 )
  {
    v0 = 1;
    v1 = (int16_t *)&unk_17CF00;
    goto LABEL_69;
  }
  v41 = 1;
  v2 = 19;
  for ( i = 0; i < 32; ++i )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = (_WORD *)(12 * v41 + dword_19287C);
      v6[2] = 20 * i;
      v6[3] = v5;
      v6[4] = v2;
      if ( v4 == 17 )
        v7 = v5 + 22;
      else
        v7 = v5 + 19;
      v6[5] = v7;
      ++v41;
      ++v4;
      v5 += 20;
    }
    while ( v4 < 18 );
    v2 += 20;
  }
  v8 = dword_192864 + 313 * word_1998F8;
  if ( *(_BYTE *)(v8 + 37) )
  {
    if ( *(_BYTE *)(v8 + 37) <= 2u )
      v40 = 10;
    else
      v40 = 20;
  }
  else
  {
    v40 = 0;
  }
  v9 = 31;
LABEL_18:
  v10 = 17;
  while ( 1 )
  {
    if ( word_1998D4 == 1 )
    {
      v11 = 2 * (v10 + word_1998F2) + 136 * (v9 + word_1998F0);
      if ( *(int16_t *)((char *)word_18C9A8 + v11) < 0 || *(int16_t *)((char *)word_18C9A8 + v11) >= word_1998C0 )
      {
        v12 = 12 * (18 * v9 + v10 + 1);
        v13 = dword_19287C;
        *(_WORD *)(dword_19287C + v12) = 14;
      }
      else
      {
        v12 = 12 * (18 * v9 + v10 + 1);
        v13 = dword_19287C;
        *(_WORD *)(dword_19287C + v12) = 13;
      }
      goto LABEL_31;
    }
    if ( word_1998E8 == 1 )
    {
      v14 = 136 * (v9 + word_1998F0) + 2 * (v10 + word_1998F2);
      if ( *(int16_t *)((char *)word_18C9A8 + v14) < 0
        || *(_BYTE *)(313 * word_1998F8 + dword_192864 + 32) == *(_BYTE *)(dword_192864
                                                                         + 313 * *(int16_t *)((char *)word_18C9A8 + v14)
                                                                         + 32)
        || *(int16_t *)((char *)word_18C9A8 + v14) >= word_1998C0 )
      {
        v13 = 12 * (v10 + 18 * v9 + 1);
LABEL_30:
        v12 = dword_19287C;
        *(_WORD *)(v13 + dword_19287C) = 2;
        goto LABEL_31;
      }
      v13 = 12 * (v10 + 18 * v9 + 1);
      v12 = dword_19287C;
      *(_WORD *)(v13 + dword_19287C) = 3;
    }
    else
    {
      v15 = 136 * (v9 + word_1998F0) + 2 * (v10 + word_1998F2);
      if ( *(int16_t *)((char *)word_18C9A8 + v15) < 0
        || (v16 = *(int16_t *)((char *)word_18C9A8 + v15), v16 >= word_1998C0) )
      {
        v19 = 136 * (v9 + word_1998F0) + 2 * (v10 + word_1998F2);
        if ( *(int16_t *)((char *)word_18C9A8 + v19) >= 0 )
        {
          if ( *(int16_t *)((char *)word_18C9A8 + v19) == 2000 )
          {
            v21 = (int16_t)sub_3F5F1(
                             *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 33),
                             *(uint8_t *)(dword_192864 + 313 * word_1998F8 + 34),
                             v9 + word_1998F0,
                             v10 + word_1998F2)
                / 2;
            v22 = (_WORD *)(12 * (18 * v9 + v10 + 1) + dword_19287C);
            v22[1] = 12;
            *v22 = v21 + 4;
          }
        }
        else
        {
          v20 = (_WORD *)(12 * (18 * v9 + v10 + 1) + dword_19287C);
          *v20 = 2;
          v20[1] = 12;
        }
        goto LABEL_43;
      }
      v17 = dword_192864 + 313 * v16;
      v13 = 12 * (18 * v9 + v10 + 1);
      if ( *(_BYTE *)(v17 + 32) == *(_BYTE *)(313 * word_1998F8 + dword_192864 + 32) )
      {
        if ( *(int16_t *)((char *)word_18C9A8 + v15) != word_1998F8 )
          goto LABEL_36;
        goto LABEL_30;
      }
      if ( sub_3E563(*(int16_t *)((char *)word_18C9A8 + v15)) )
      {
LABEL_36:
        v18 = dword_19287C;
        *(_WORD *)(v13 + dword_19287C) = 1;
        *(_WORD *)(v13 + v18 + 2) = 0;
        goto LABEL_43;
      }
      v12 = dword_19287C;
      *(_WORD *)(v13 + dword_19287C) = 12;
    }
LABEL_31:
    *(_WORD *)(v13 + v12 + 2) = 12;
LABEL_43:
    if ( --v10 < 0 )
    {
      if ( --v9 < 0 )
      {
        if ( v40 > 0 )
        {
          v43 = v40 + 639;
          v37 = v40 + 620;
          v39 = 31;
          v42 = 558;
          do
          {
            v23 = 17;
            v36 = v40 + 359;
            v24 = v42 + 18;
            v38 = v40 + 340;
            do
            {
              v25 = (_WORD *)(dword_19287C + 12 * v24);
              if ( (int16_t)*v25 >= 4 && (int16_t)*v25 <= 11 )
              {
                if ( v40 == 20 && v39 < 31 && v23 < 17 )
                {
                  *(_WORD *)(dword_19287C + 12 * (v24 + 19)) = *v25;
                }
                else if ( v40 == 10 )
                {
                  v26 = (int16_t *)(12 * (v24 + 19) + dword_19287C);
                  if ( *v26 < 4 || *v26 > 11 )
                  {
                    v27 = 12 * (v24 + 19);
                    v28 = dword_19287C;
                    *(_WORD *)(v27 + dword_19287C + 4) = 0;
                    *(_WORD *)(v27 + v28 + 8) = 0;
                    *(_WORD *)(v27 + v28 + 6) = 0;
                    *(_WORD *)(v27 + v28 + 10) = 0;
                  }
                  v29 = (int16_t *)(12 * (v24 + 1) + dword_19287C);
                  if ( *v29 < 4 || *v29 > 11 )
                  {
                    v30 = 12 * (v24 + 1);
                    v31 = dword_19287C;
                    *(_WORD *)(dword_19287C + v30 + 4) = 0;
                    *(_WORD *)(v31 + v30 + 8) = 0;
                    *(_WORD *)(v31 + v30 + 6) = 0;
                    *(_WORD *)(v31 + v30 + 10) = 0;
                  }
                  v32 = (int16_t *)(dword_19287C + 12 * (v24 + 18));
                  if ( *v32 < 4 || *v32 > 11 )
                  {
                    v33 = 12 * (v24 + 18);
                    v34 = dword_19287C;
                    *(_WORD *)(v33 + dword_19287C + 4) = 0;
                    *(_WORD *)(v33 + v34 + 8) = 0;
                    *(_WORD *)(v33 + v34 + 6) = 0;
                    *(_WORD *)(v33 + v34 + 10) = 0;
                  }
                }
                v35 = (_WORD *)(12 * v24 + dword_19287C);
                v35[2] = v37;
                v35[4] = v43;
                v35[3] = v38;
                v35[5] = v36;
              }
              v36 -= 20;
              v38 -= 20;
              --v23;
              --v24;
            }
            while ( v23 >= 0 );
            v42 -= 18;
            v43 -= 20;
            --v39;
            v37 -= 20;
          }
          while ( v39 >= 0 );
        }
        v0 = 878;
        v1 = (int16_t *)dword_19287C;
LABEL_69:
        sub_123E6C((int)v1, v0);
        JUMPOUT(0x42DE1);
      }
      goto LABEL_18;
    }
  }
}
// 4752A: control flows out of bounds to 42DE1
// 17CF82: using guessed type int16_t word_17CF82;
// 18C9A8: using guessed type int16_t word_18C9A8[4979];
// 192864: using guessed type int dword_192864;
// 19287C: using guessed type int dword_19287C;
// 199876: using guessed type int16_t word_199876;
// 19987C: using guessed type int16_t word_19987C;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998D4: using guessed type int16_t word_1998D4;
// 1998E8: using guessed type int16_t word_1998E8;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F8: using guessed type int16_t word_1998F8;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;


//----- (0004752F) --------------------------------------------------------
void __fastcall sub_4752F( int a1, int a2, int a3)
{
  int16_t v5; // ax
  int v6; // eax
  int16_t v7; // si
  int v8; // eax
  int16_t v9; // cx
  int v10; // ebx
  int16_t i; // bx
  int v12; // eax
  int v13; // eax
  int16_t m; // bx
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int16_t v18; // ax
  int v19; // [esp+8h] [ebp-4Ch]
  int v20; // [esp+18h] [ebp-3Ch]
  int v21; // [esp+1Ch] [ebp-38h]
  int v22; // [esp+28h] [ebp-2Ch]
  int16_t v23; // [esp+2Ch] [ebp-28h]
  int16_t v24; // [esp+30h] [ebp-24h]
  int16_t v25; // [esp+38h] [ebp-1Ch]
  int16_t v26; // [esp+3Ch] [ebp-18h]
  uint16_t v27; // [esp+40h] [ebp-14h]
  int16_t j; // [esp+44h] [ebp-10h]
  int16_t k; // [esp+48h] [ebp-Ch]
  int16_t v31; // [esp+50h] [ebp-4h]

  v26 = a2;
  if ( sub_4B0D3(a1, 33) || sub_4B0D3(a1, 22) )
  {
    sub_38876();
    if ( !v5 && a2 < 20 )
      v26 = 20;
  }
  v6 = (*(uint8_t *)(313 * a1 + dword_192864 + 37) + 1) / 2;
  if ( v6 >= 2 )
    LOWORD(v6) = 2;
  v27 = v6;
  v7 = 0;
  v8 = dword_192864 + 313 * a1;
  v31 = 0;
  v25 = *(uint8_t *)(v8 + 33);
  v23 = *(uint8_t *)(v8 + 34);
  do
  {
    v9 = 0;
    v24 = 0;
    do
    {
      v10 = 136 * v7 + 2 * v9;
      if ( *(int16_t *)((char *)word_18C9A8 + v10) == -1 && (int)abs32(v25 - v7) <= v26 && (int)abs32(v23 - v9) <= v26 )
      {
        *(int16_t *)((char *)word_18C9A8 + v10) = 2000;
        if ( v27 )
        {
          if ( v27 <= 1u )
          {
            for ( i = 0; i < 2; ++i )
            {
              for ( j = 0; j < 2; ++j )
              {
                v19 = i + v7;
                if ( v19 < 81 )
                {
                  v12 = j + v9;
                  if ( v12 < 68 )
                  {
                    v13 = 136 * v19 + 2 * v12;
                    if ( *(int16_t *)((char *)word_18C9A8 + v13) == -1
                      || *(int16_t *)((char *)word_18C9A8 + v13) == 2000
                      || a1 == *(int16_t *)((char *)word_18C9A8 + v13) )
                    {
                      continue;
                    }
                  }
                }
                word_18C9A8[68 * v7 + v9] = -1;
              }
            }
          }
          else if ( v27 == 2 )
          {
            for ( k = 0; k <= 2; ++k )
            {
              for ( m = 0; m <= 2; ++m )
              {
                v22 = v7 + k;
                if ( v22 < 81 )
                {
                  v15 = m + v9;
                  if ( v15 < 68 )
                  {
                    v16 = 136 * v22 + 2 * v15;
                    if ( *(int16_t *)((char *)word_18C9A8 + v16) == -1
                      || *(int16_t *)((char *)word_18C9A8 + v16) == 2000
                      || a1 == *(int16_t *)((char *)word_18C9A8 + v16) )
                    {
                      continue;
                    }
                  }
                }
                word_18C9A8[68 * v7 + v9] = -1;
              }
            }
          }
        }
        if ( 81 - (int16_t)v27 < v7 || v9 > 68 - (int16_t)v27 )
          word_18C9A8[68 * v7 + v9] = -1;
        v21 = 136 * v7 + 2 * v9;
        if ( *(int16_t *)((char *)word_18C9A8 + v21) == 2000 && a3 == 1 )
        {
          v17 = 313 * a1 + dword_192864;
          if ( (int16_t)sub_3F95F(a1, v7, v9) > *(int16_t *)(v17 + 61) )
            *(int16_t *)((char *)word_18C9A8 + v21) = -1;
          if ( sub_4B0D3(a1, 33) )
          {
            v20 = 2 * v9 + 136 * v7;
            if ( *(int16_t *)((char *)word_18C9A8 + v20) == -1 )
            {
              sub_38876();
              if ( !v18 && sub_3B004(a1, 33) == 1 && (int16_t)sub_286E8(a1, v31, v24) <= 20 )
                *(int16_t *)((char *)word_18C9A8 + v20) = 2000;
            }
          }
        }
      }
      ++v9;
      v24 += 20;
    }
    while ( v9 < 68 );
    ++v7;
    v31 += 20;
  }
  while ( v7 < 81 );
}
// 4756E: variable 'v5' is possibly undefined
// 4783E: variable 'v18' is possibly undefined
// 18C9A8: using guessed type int16_t word_18C9A8[4979];
// 192864: using guessed type int dword_192864;


//----- (000478A3) --------------------------------------------------------
char __fastcall sub_478A3( int a1)
{
  _BYTE *v1; // eax
  char v2; // dl

  v1 = (_BYTE *)(dword_192B18 + 361 * a1);
  v2 = 0;
  if ( v1[350] || v1[357] || v1[318] || v1[351] || v1[336] || v1[337] || v1[352] )
    return 1;
  return v2;
}
// 192B18: using guessed type int dword_192B18;


//----- (000478FC) --------------------------------------------------------
int __fastcall sub_478FC(int16_t *a1, int16_t *a2)
{
  int v3; // eax
  uint8_t v4; // bl

  v3 = dword_197F9C + 129 * *a2;
  v4 = *(_BYTE *)(dword_197F9C + 129 * *a1 + 16);
  if ( v4 == *(_BYTE *)(v3 + 16) )
    return 0;
  if ( v4 >= *(_BYTE *)(v3 + 16) )
    return -1;
  return 1;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (00047939) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge sub_47939(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int64_t a7,
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
        int a31)
{
  int v31; // esi
  int16_t v32; // di
  int16_t v33; // ax
  char *v34; // eax
  int16_t v35; // dx
  int16_t i; // bx
  int v37; // ecx
  int v38; // eax
  int16_t j; // dx
  uint16_t v40; // ax
  _BOOL1 v41; // zf
  char v42; // al
  int v43; // eax
  int16_t k; // ax
  int v45; // eax
  _BYTE *v46; // eax
  int16_t v47; // cx
  _DWORD *v48; // eax
  int16_t v49; // cx
  _DWORD *v50; // eax
  int v51; // edx
  int v52; // eax
  int v53; // eax
  int v54; // eax
  int v55; // eax
  int16_t v56; // cx
  _DWORD *v57; // edx
  int v58; // eax
  _WORD *v59; // eax
  int16_t v60; // bx
  int v61; // edx
  int v62; // eax
  int16_t v63; // cx
  int (__fastcall *v64)(int16_t *, int16_t *); // ecx
  int16_t v65; // ax
  int16_t v66; // bx
  int16_t v67; // ax
  int16_t v68; // dx
  int16_t v69; // ax
  int16_t v70; // bx
  int16_t v71; // ax
  int16_t v72; // dx
  _BYTE *v73; // eax
  int16_t v74; // bx
  int v75; // eax
  int16_t v76; // dx
  uint16_t v77; // ax
  _BOOL1 v78; // zf
  int v79; // eax
  int v80; // eax
  int v81; // eax
  int16_t v82; // si
  int16_t v83; // ax
  int v84; // edx
  int v85; // eax
  int v86; // eax
  int16_t v87; // si
  _BYTE *v88; // eax
  int v89; // eax
  int v90; // eax
  int16_t v91; // ax
  char v92; // cl
  char v93; // bl
  char v94; // dl
  int v95; // esi
  int v96; // edx
  int16_t v97; // ax
  int v98; // ecx
  char v99; // bl
  char v100; // dl
  _BYTE *v101; // eax
  char v102; // bl
  char v103; // dl
  int16_t v104; // ax
  int v105; // eax
  int v106; // eax
  int16_t v107; // ax
  char v108; // cl
  char v109; // bl
  char v110; // dl
  int v111; // eax
  int v112; // eax
  int16_t v113; // ax
  char v114; // bl
  char v115; // dl
  int v116; // eax
  int v117; // edi
  int v118; // eax
  int16_t v119; // ax
  char v120; // cl
  char v121; // bl
  char v122; // dl
  int v123; // eax
  int v124; // eax
  int v125; // eax
  int v126; // eax
  int16_t v127; // dx
  _BYTE *v128; // eax
  int v129; // eax
  int v130; // eax
  int v131; // eax
  int16_t v132; // di
  int16_t v133; // ax
  int v134; // eax
  int m; // ecx
  int16_t v136; // ax
  int16_t v137; // ax
  int16_t v138; // ax
  int16_t v139; // ax
  int16_t v140; // dx
  int16_t n; // dx
  int v142; // eax
  int v143; // eax
  int16_t v144; // ax
  int16_t v145; // ax
  int16_t v146; // ax
  int v147; // eax
  char v149; // [esp-4h] [ebp-D4h]
  char v150; // [esp-4h] [ebp-D4h]
  char v151; // [esp-4h] [ebp-D4h]
  char v152; // [esp-4h] [ebp-D4h]
  char v153; // [esp-4h] [ebp-D4h]
  char v154; // [esp-4h] [ebp-D4h]
  char v155; // [esp-4h] [ebp-D4h]
  int16_t v156; // [esp+66h] [ebp-6Ah]
  int16_t *v157; // [esp+6Ah] [ebp-66h]
  int16_t v158; // [esp+6Eh] [ebp-62h]
  int16_t *v159; // [esp+72h] [ebp-5Eh]
  char v160[80]; // [esp+76h] [ebp-5Ah] BYREF
  _DWORD varA[4]; // [esp+C6h] [ebp-Ah] BYREF
  _BYTE *vars6; // [esp+D6h] [ebp+6h]
  _BYTE varsA[2]; // [esp+DAh] [ebp+Ah] BYREF
  _UNKNOWN *retaddr; // [esp+DCh] [ebp+Ch] OVERLAPPED
  char v165; // [esp+E2h] [ebp+12h]
  int16_t v166; // [esp+E6h] [ebp+16h]
  int16_t v167; // [esp+EAh] [ebp+1Ah]
  _BOOL2 v168; // [esp+EEh] [ebp+1Eh]
  int16_t v169; // [esp+F2h] [ebp+22h]
  int16_t v170; // [esp+F6h] [ebp+26h]
  int16_t v171; // [esp+FEh] [ebp+2Eh]
  int16_t v172; // [esp+106h] [ebp+36h]
  int16_t v173; // [esp+10Ah] [ebp+3Ah]
  int v174; // [esp+10Eh] [ebp+3Eh]
  char v175; // [esp+112h] [ebp+42h]
  int16_t v176; // [esp+116h] [ebp+46h]
  int16_t v177; // [esp+11Ah] [ebp+4Ah]
  int16_t v178; // [esp+11Eh] [ebp+4Eh]
  int16_t v179; // [esp+122h] [ebp+52h]
  int16_t v180; // [esp+126h] [ebp+56h]
  int16_t v181; // [esp+12Ah] [ebp+5Ah]
  char v182; // [esp+12Eh] [ebp+5Eh]
  char v183; // [esp+132h] [ebp+62h]
  char v184; // [esp+136h] [ebp+66h]
  char v185; // [esp+13Ah] [ebp+6Ah]
  char v186; // [esp+142h] [ebp+72h]

  v177 = 0;
  v186 = 0;
  v168 = 1;
  varA[0] = 0;
  varA[1] = 0;
  varA[2] = 31392383;
  v31 = 0;
  v32 = 0;
  v167 = 0;
  v166 = 0;
  v165 = 0;
  if ( HIWORD(a29) == word_19999A )
  {
    sub_C657B();
    v168 = 0;
  }
  word_199890 = 0;
  word_19987C = 15;
  word_1998E2 = 0;
  word_1998F4 = -2;
  word_1998F0 = 0;
  word_1998F2 = 0;
  word_1998D6 = 0;
  word_1998FC = -1;
  word_199904 = 1;
  word_199876 = 1;
  word_1998E0 = 0;
  byte_19B57C = 0;
  word_1998C6 = 0;
  word_1998F6 = 1;
  word_1998DA = 0;
  word_19987A = 0;
  word_199880 = 0;
  word_1998C8 = HIWORD(a31);
  word_199886 = 0;
  word_1998CC = (uint8_t)byte_199C93;
  word_19988C = 0;
  word_19987E = (uint8_t)byte_199C90;
  word_199882 = 0;
  word_1998C4 = (uint8_t)byte_199C92;
  word_199906 = (uint8_t)byte_199C92;
  word_199884 = 0;
  word_1998EE = (uint8_t)byte_199C91;
  word_19988A = 0;
  word_1998E4 = (uint8_t)byte_199C94;
  word_1998CE = 0;
  word_17D853 = (uint8_t)byte_199BE9;
  word_199878 = HIWORD(a30);
  word_1998C0 = 1;
  dword_192864 = (int)sub_110CEE(dword_192ED4, 65730);
  sub_127776((_BYTE *)dword_192864, 0x100C2u);
  word_1998AC = *(char *)(dword_197F9C + 129 * *v159 + 99);
  if ( HIWORD(a29) == word_19999A )
  {
    word_19988E = 8;
    v178 = 0;
  }
  else
  {
    if ( word_199878 == -1 )
    {
      v33 = *(char *)(dword_197F9C + 129 * *v157 + 99);
      v178 = 0;
    }
    else
    {
      v34 = (char *)(dword_192B18 + 361 * word_199878);
      v35 = (uint8_t)v34[10];
      v33 = *v34;
      v178 = v35;
    }
    word_19988E = v33;
  }
  v171 = 0;
  word_1998CA = HIWORD(a29) != word_19999A
             && sub_EBA3A(
                  *(_WORD *)(113 * SHIWORD(a29) + dword_19306C + 15),
                  *(_WORD *)(113 * SHIWORD(a29) + dword_19306C + 17));
  qsort(v159, v158, 2);
  for ( i = 0; i < v158; ++i )
  {
    v37 = v159[i];
    v38 = dword_197F9C + 129 * v37;
    if ( *(_BYTE *)(v38 + 17) )
      goto LABEL_36;
    if ( ++v171 >= 100 )
      goto LABEL_36;
    sub_4954A(v37, word_1998C0);
    for ( j = 0; j < 8; ++j )
    {
      v40 = *(_WORD *)(313 * word_1998C0 + dword_192864 + 11 * j + 82);
      if ( v40 < 0x25u )
      {
        if ( v40 <= 0x20u )
          continue;
        v41 = v40 == 35;
      }
      else
      {
        if ( v40 <= 0x25u )
        {
          v167 = 1;
          continue;
        }
        if ( v40 < 0x27u )
        {
          v32 = 1;
          continue;
        }
        if ( v40 <= 0x27u )
        {
          v177 = 1;
          continue;
        }
        v41 = v40 == 45;
      }
      if ( v41 )
        v166 = 1;
    }
    if ( sub_4B0D3(word_1998C0, 23) || (byte_19B57C = 1, (uint16_t)sub_4B0D3(word_1998C0, 6)) )
      v31 = 1;
    sub_4B0D3(word_1998C0, 10);
    v38 = sub_4B0D3(word_1998C0, 26);
    if ( (_WORD)v38 )
      v165 = 1;
    ++word_1998C0;
LABEL_36:
    sub_FE8BE(v38);
  }
  if ( word_19988E < 8
    && SHIWORD(a29) < word_19999A
    && (uint8_t)sub_79CF9(dword_197F98 + 3753 * word_19988E, 113 * SHIWORD(a29) + dword_19306C) )
  {
    sub_3868F(0);
    v186 = v42;
    if ( v42 )
      v43 = 82;
    else
      v43 = 83;
    sub_58F1E(v43, v160, 80);
    sub_131F7B();
    sub_77423((int)v160);
    *(_DWORD *)((char *)&a7 + 2) = -1;
  }
  for ( k = 0; k < v156 && v168; ++k )
    v168 = *(_BYTE *)(129 * v157[k] + dword_197F9C + 17) != 0;
  if ( v168 && !v186 && HIWORD(a29) != word_19999A && (SHIWORD(a30) == -1 || !sub_478A3(SHIWORD(a30))) )
  {
    v186 = 1;
    *(_DWORD *)((char *)&a7 + 2) = 1;
  }
  if ( v186 )
    goto LABEL_181;
  sub_107AF(varsA);
  sub_128BE7();
  v45 = sub_2496C();
  sub_FE8BE(v45);
  sub_11C2F0();
  sub_119281();
  sub_123E6C((int)varA, 1);
  sub_8A159();
  sub_C5BB9();
  sub_1205E6(3, 0, 255);
  sub_C5B94(0);
  v46 = sub_110D3C(dword_192ED4, 7800);
  dword_192B14 = (int)v46;
  sub_127776(v46, 0x1E78u);
  sub_FE8BE(v46);
  dword_1928A8 = (int)sub_126B42((int)aCombatLbx_2, 42, dword_192ED4);
  sub_FE8BE(dword_1928A8);
  dword_192874 = (int)sub_126B42((int)aCombatLbx_2, 1, dword_192ED4);
  sub_FE8BE(dword_192874);
  dword_192860 = (int)sub_126B42((int)aCombatLbx_2, 51, dword_192ED4);
  sub_FE8BE(dword_192860);
  dword_19286C = (int)sub_126B42((int)aCombatLbx_2, 50, dword_192ED4);
  sub_FE8BE(dword_19286C);
  dword_192870 = (int)sub_126B42((int)aCombatLbx_2, 53, dword_192ED4);
  sub_FE8BE(dword_192870);
  dword_192830 = (int)sub_126B42((int)aCombatLbx_2, 54, dword_192ED4);
  sub_FE8BE(dword_192830);
  dword_192838 = (int)sub_126B42((int)aCombatLbx_2, 52, dword_192ED4);
  sub_FE8BE(dword_192838);
  dword_192828 = (int)sub_126B42((int)aCombatLbx_2, 10, dword_192ED4);
  sub_FE8BE(dword_192828);
  dword_19282C = (int)sub_126B42((int)aCombatLbx_2, 2, dword_192ED4);
  sub_FE8BE(dword_19282C);
  dword_19281C = (int)sub_126B42((int)aCombatLbx_2, 3, dword_192ED4);
  sub_FE8BE(dword_19281C);
  v47 = 0;
  dword_192818 = (int)sub_126B42((int)aCombatLbx_2, 7, dword_192ED4);
  sub_FE8BE(dword_192818);
  do
  {
    *(_UNKNOWN **)((char *)&retaddr + 2) = (_UNKNOWN *)v47;
    v48 = sub_126B42((int)aCmbtmislLbx, v47++, dword_192ED4);
    dword_18F768[*(_DWORD *)((char *)&retaddr + 2)] = (int)v48;
    sub_FE8BE(*(_UNKNOWN **)((char *)&retaddr + 2));
  }
  while ( v47 < 112 );
  dword_19287C = (int)sub_110D3C(dword_192ED4, 10536);
  dword_192848 = (int)sub_126B42((int)aCombatLbx_2, 8, dword_192ED4);
  dword_192884 = (int)sub_126B42((int)aCombatLbx_2, 4, dword_192ED4);
  sub_FE8BE(dword_192884);
  v172 = 32;
  dword_192850 = (int)sub_126B42((int)aCombatLbx_2, 37, dword_192ED4);
  v49 = 0;
  dword_192854 = (int)sub_126B42((int)aCombatLbx_2, 38, dword_192ED4);
  sub_FE8BE(dword_192854);
  do
  {
    v50 = sub_126B42((int)aCombatLbx_2, v172++, dword_192ED4);
    v51 = (int)v50;
    v52 = v49++;
    dword_19291C[v52] = v51;
    sub_FE8BE(v52);
  }
  while ( v49 < 3 );
  v53 = sub_12DAA4(98, 98);
  dword_192840 = (int)sub_110D3C(dword_192ED4, v53);
  v54 = sub_12DAA4(98, 98);
  dword_19283C = (int)sub_110D3C(dword_192ED4, v54);
  v55 = sub_12DAA4(98, 98);
  dword_192824 = (int)sub_110D3C(dword_192ED4, v55);
  sub_FE8BE(dword_192824);
  dword_18F4B0[0] = (int)sub_126B42((int)aCombatLbx_2, 14, dword_192ED4);
  dword_18F4B4 = (int)sub_126B42((int)aCombatLbx_2, 15, dword_192ED4);
  sub_FE8BE(dword_18F4B4);
  v56 = 0;
  dword_18F4B8 = (int)sub_126B42((int)aCombatLbx_2, 12, dword_192ED4);
  v173 = 0;
  dword_18F4BC = (int)sub_126B42((int)aCombatLbx_2, 13, dword_192ED4);
  sub_FE8BE(dword_18F4BC);
  do
  {
    v169 = 0;
    v180 = v173 + 16;
    do
    {
      v57 = sub_126B42((int)aCombatLbx_2, v180, dword_192ED4);
      v58 = 16 * v56 + 4 * v169;
      ++v180;
      ++v169;
      *(int *)((char *)dword_18F4C0 + v58) = (int)v57;
    }
    while ( v169 < 4 );
    sub_FE8BE(v58);
    ++v56;
    v173 += 4;
  }
  while ( v56 < 4 );
  v59 = (_WORD *)dword_19287C;
  *(_WORD *)(dword_19287C + 4) = 0;
  v59[4] = 639;
  v59[3] = 0;
  v179 = 1;
  v59[5] = 350;
  v181 = 19;
  v59[1] = 12;
  v60 = 0;
  *v59 = 2;
  do
  {
    v170 = 0;
    v174 = 19;
    do
    {
      v61 = 12 * v179;
      v62 = dword_19287C;
      *(_WORD *)(v61 + dword_19287C + 4) = 20 * v60;
      *(_WORD *)(v61 + v62 + 8) = v181;
      v63 = 20 * v170;
      *(_WORD *)(v61 + v62 + 2) = 0;
      ++v179;
      *(_WORD *)(v61 + v62) = 0;
      ++v170;
      *(_WORD *)(v61 + v62 + 6) = v63;
      v64 = (int (__fastcall *)(int16_t *, int16_t *))v174;
      v174 += 20;
      *(_WORD *)(v61 + v62 + 10) = (_WORD)v64;
    }
    while ( v170 < 18 );
    ++v60;
    v181 += 20;
  }
  while ( v60 < 32 );
  *(_WORD *)(v62 + 10528) = 0;
  *(_WORD *)(v62 + 10532) = 639;
  *(_WORD *)(v62 + 10530) = 351;
  *(_WORD *)(v62 + 10534) = 479;
  *(_WORD *)(v62 + 10526) = 0;
  *(_WORD *)(v62 + 10524) = 1;
  if ( (uint8_t)byte_199F3A >= 2u )
  {
    LOWORD(v62) = word_1998AC;
    if ( word_1998AC < word_199998 )
    {
      v62 = 3753 * word_1998AC;
      if ( *(_BYTE *)(dword_197F98 + v62 + 40) == 100 )
      {
        LOWORD(v62) = word_19988E;
        if ( word_19988E < word_199998 )
        {
          v62 = 3753 * word_19988E;
          if ( *(_BYTE *)(dword_197F98 + v62 + 40) == 100 )
            word_1998CE = 1;
        }
      }
    }
  }
  if ( word_1998AC <= 8 )
  {
    sub_5699C(word_1998AC);
    v66 = v65;
    v67 = word_1998AC;
    word_199254[word_1998AC] = v66;
    v68 = sub_56CA2(v67);
    v62 = word_1998AC;
    word_199242[word_1998AC] = v68;
  }
  if ( word_19988E <= 8 )
  {
    sub_5699C(word_19988E);
    v70 = v69;
    v71 = word_19988E;
    word_199254[word_19988E] = v70;
    v72 = sub_56CA2(v71);
    v62 = word_19988E;
    word_199242[word_19988E] = v72;
  }
  sub_FE8BE(v62);
  vars6 = sub_132065(dword_192ED4);
  v73 = sub_13209C(vars6);
  sub_FE8BE(v73);
  if ( HIWORD(a29) == word_19999A )
  {
    sub_4D141();
    sub_4A8D3();
    v167 = 1;
    v165 = 1;
    goto LABEL_107;
  }
  v64 = sub_478FC;
  v176 = 0;
  qsort(v157, v156, 2);
  v74 = 0;
LABEL_105:
  if ( v74 < v156 )
  {
    v75 = v157[v74];
    v64 = (int (__fastcall *)(int16_t *, int16_t *))dword_197F9C;
    if ( *(_BYTE *)(dword_197F9C + 129 * v75 + 17) )
      goto LABEL_104;
    if ( ++v176 >= 100 )
      goto LABEL_104;
    sub_4954A(v75, word_1998C0);
    v76 = 0;
    while ( 1 )
    {
      v64 = (int (__fastcall *)(int16_t *, int16_t *))(dword_192864 + 313 * word_1998C0);
      v77 = *(_WORD *)((char *)v64 + 11 * v76 + 82);
      if ( v77 < 0x25u )
      {
        if ( v77 > 0x20u )
        {
          v78 = v77 == 35;
LABEL_89:
          if ( v78 )
            v166 = 1;
        }
      }
      else if ( v77 <= 0x25u )
      {
        v167 = 1;
      }
      else if ( v77 < 0x27u )
      {
        v32 = 1;
      }
      else
      {
        if ( v77 > 0x27u )
        {
          v78 = v77 == 45;
          goto LABEL_89;
        }
        v177 = 1;
      }
      if ( ++v76 >= 8 )
      {
        if ( sub_4B0D3(word_1998C0, 6) || sub_4B0D3(word_1998C0, 23) )
          v31 = 1;
        sub_4B0D3(word_1998C0, 10);
        v75 = sub_4B0D3(word_1998C0, 26);
        if ( (_WORD)v75 )
          v165 = 1;
        ++word_1998C0;
LABEL_104:
        sub_FE8BE(v75);
        ++v74;
        goto LABEL_105;
      }
    }
  }
  sub_4A9E9(SHIWORD(a30), v32);
LABEL_107:
  v79 = sub_3A142((int)v64, v31);
  if ( (v79 & 4) != 0 )
    v32 = 1;
  sub_FE8BE(v79);
  sub_49F99();
  sub_FE8BE(v80);
  sub_49F99();
  sub_FE8BE(v81);
  if ( (_WORD)v31 )
  {
    dword_192820 = (int)sub_126B42((int)aCombatLbx_2, 49, dword_192ED4);
    sub_FE8BE(dword_192820);
    sub_34286();
  }
  v82 = 1;
  sub_A7518(v165);
  v175 = 23;
  dword_192950 = (int)sub_132065(dword_192ED4);
  sub_FE8BE(dword_192950);
  do
  {
    v83 = v82;
    v84 = 2 * v82;
    varA[3] = v84 + 13;
    ++v82;
    v149 = v175;
    v175 += 3;
    LOBYTE(v85) = sub_131ACB(v83, v84 + 13, v84 + 30, 63, v149);
  }
  while ( v82 < 16 );
  sub_FE8BE(v85);
  sub_1319E4(144, 32, 0, 0, 0, 0, 0, 0);
  v86 = sub_1318D4(0, 255);
  sub_FE8BE(v86);
  sub_133237();
  v87 = 1;
  v88 = sub_13209C((_BYTE *)dword_192950);
  sub_FE8BE(v88);
  dword_192928 = (int)sub_132065(dword_192ED4);
  v182 = 53;
  v89 = sub_127C27((int)aCmbtsfxLbx_1, 52, dword_193174);
  v90 = sub_12B79D(v89);
  sub_FE8BE(v90);
  do
  {
    v150 = v182;
    v91 = v87;
    v182 += 3;
    v92 = byte_1BB59B[4 * v87];
    v93 = byte_1BB59A[4 * v87];
    v94 = byte_1BB599[4 * v87++];
    sub_131ACB(v91, v94, v93, v92, v150);
  }
  while ( v87 < 16 );
  sub_1318D4(0, 255);
  sub_133237();
  sub_13209C((_BYTE *)dword_192928);
  dword_1928C4 = (int)sub_132065(dword_192ED4);
  v95 = 1;
  v96 = sub_127C27((int)aSphersfxLbx_0, 0, dword_193174);
  sub_FE8BE(v96);
  v183 = 53;
  sub_12B79D(v96);
  do
  {
    v151 = v183;
    v97 = v95;
    v183 += 3;
    v98 = (uint8_t)byte_1BB59B[4 * (int16_t)v95];
    v99 = byte_1BB59A[4 * (int16_t)v95];
    v100 = byte_1BB599[4 * (int16_t)v95++];
    sub_131ACB(v97, v100, v99, v98, v151);
  }
  while ( (int16_t)v95 < 16 );
  sub_1318D4(0, 255);
  sub_133237();
  v101 = sub_13209C((_BYTE *)dword_1928C4);
  sub_FE8BE(v101);
  if ( v177 )
  {
    v95 = 1;
    dword_192948 = (int)sub_126B42((int)aCmbtsfxLbx_1, 2, dword_192ED4);
    sub_FE8BE(dword_192948);
    v184 = 23;
    dword_192944 = (int)sub_132065(dword_192ED4);
    do
    {
      v152 = v184;
      HIWORD(retaddr) = v95;
      v184 += 3;
      v98 = (uint8_t)byte_1BB49B[4 * ((int16_t)v95 / 2)];
      v102 = byte_1BB49A[4 * ((int16_t)v95 / 2)];
      v103 = byte_1BB499[4 * ((int16_t)v95 / 2)];
      v104 = v95++;
      sub_131ACB(v104, v103, v102, v98, v152);
    }
    while ( (int16_t)v95 < 16 );
    v105 = sub_1318D4(0, 255);
    sub_FE8BE(v105);
    sub_133237();
    sub_13209C((_BYTE *)dword_192944);
  }
  dword_19294C = dword_192950;
  if ( v167 )
  {
    v185 = 60;
    dword_1928DC = (int)sub_132065(dword_192ED4);
    v95 = 0;
    v106 = sub_127C27((int)aCmbtsfxLbx_1, 46, dword_193174);
    sub_12B79D(v106);
    do
    {
      v153 = v185;
      v107 = v95;
      v185 += 2;
      v108 = byte_1BB59B[4 * (int16_t)v95];
      v109 = byte_1BB59A[4 * (int16_t)v95];
      v110 = byte_1BB599[4 * (int16_t)v95++];
      sub_131ACB(v107, v110, v109, v108, v153);
    }
    while ( (int16_t)v95 < 16 );
    v98 = 0;
    sub_1319E4(144, 32, 0, 0, 0, 0, 0, 0);
    v111 = sub_1318D4(0, 255);
    sub_FE8BE(v111);
    sub_133237();
    sub_13209C((_BYTE *)dword_1928DC);
  }
  if ( v166 )
  {
    v95 = 1;
    dword_192954 = (int)sub_132065(dword_192ED4);
    do
    {
      v112 = 6 * (int16_t)v95 + 30;
      if ( v112 > 100 )
        LOBYTE(v112) = 100;
      v154 = v112;
      v113 = v95;
      v98 = (uint8_t)byte_1BB61B[4 * (int16_t)v95];
      v114 = byte_1BB61A[4 * (int16_t)v95];
      v115 = byte_1BB619[4 * (int16_t)v95++];
      LOBYTE(v116) = sub_131ACB(v113, v115, v114, v98, v154);
    }
    while ( (int16_t)v95 < 16 );
    sub_FE8BE(v116);
    sub_1318D4(0, 255);
    sub_133237();
    sub_13209C((_BYTE *)dword_192954);
  }
  if ( v32 )
  {
    v95 = 1;
    dword_1928AC = (int)sub_132065(dword_192ED4);
    sub_FE8BE(dword_1928AC);
    v117 = 53;
    v118 = sub_127C27((int)aCmbtsfxLbx_1, 40, dword_193174);
    sub_12B79D(v118);
    do
    {
      v155 = v117;
      v119 = v95;
      v117 += 3;
      v120 = byte_1BB59B[8 * (int16_t)v95];
      v121 = byte_1BB59A[8 * (int16_t)v95];
      v122 = byte_1BB599[8 * (int16_t)v95++];
      sub_131ACB(v119, v122, v121, v120, v155);
    }
    while ( (int16_t)v95 < 16 );
    v123 = sub_1318D4(0, 255);
    sub_FE8BE(v123);
    sub_133237();
    sub_13209C((_BYTE *)dword_1928AC);
    v98 = 0;
    sub_1319E4(144, 32, 0, 0, 0, 0, 0, 0);
  }
  v124 = sub_35F0A();
  sub_FE8BE(v124);
  sub_4A12A();
  sub_FE8BE(v125);
  sub_4A12A();
  sub_FE8BE(v126);
  v127 = 0;
  sub_1320E9((_BYTE *)dword_192950);
  while ( v127 < word_1998C0 )
    sub_4C9F6(v127++);
  v128 = sub_49043();
  sub_FE8BE(v128);
  word_192B10[0] = 0;
  word_192B12 = 0;
  word_1998D4 = 0;
  sub_465D0();
  sub_FE8BE(v129);
  sub_4545B(v98, v95);
  *(_DWORD *)((char *)&a7 + 2) = v130;
  sub_1191CA((int)sub_2F4EE, 1);
  LOWORD(v131) = sub_123E6C((int)&unk_17CF00, 1);
  if ( word_19988E == 8 )
  {
    LOWORD(v95) = 8;
    v132 = word_1998AC;
  }
  else
  {
    LOWORD(v95) = word_1998AC;
    v132 = word_19988E;
  }
  if ( word_1998CE )
  {
    sub_127776(&word_190460, 0x10u);
    if ( word_19999C == word_1998AC )
      v133 = word_19988E;
    else
      v133 = word_1998AC;
    sub_F6816(*(int16_t *)(dword_197F98 + 3753 * v133 + 43), 1005, (int)&word_17D853, 2u);
    v131 = sub_3FBFE(0);
  }
  v134 = sub_FE8BE(v131);
  while ( !WORD1(a7) )
  {
    for ( m = 0; (int16_t)m < word_1998C0; ++m )
    {
      if ( !(_WORD)m )
      {
        v134 = word_199878;
        if ( word_199878 == -1 )
          continue;
      }
      sub_4528F(m);
      *(_UNKNOWN **)((char *)&retaddr + 2) = (_UNKNOWN *)(313 * (int16_t)m);
      *(_WORD *)(*(char **)((char *)&retaddr + 2) + dword_192864 + 59) = v136;
      sub_366DD(m);
      *(_WORD *)(*(char **)((char *)&retaddr + 2) + dword_192864 + 52) = v137;
      sub_35D0D(m, 0);
      *(_WORD *)(*(char **)((char *)&retaddr + 2) + dword_192864 + 54) = v138;
      sub_35D0D(m, 1);
      v140 = v139;
      v134 = *(int *)((char *)&retaddr + 2) + dword_192864;
      *(_WORD *)(*(char **)((char *)&retaddr + 2) + dword_192864 + 56) = v140;
    }
    sub_FE8BE(v134);
    for ( n = 0; n < 300; ++n )
    {
      v142 = 26 * n + dword_192B14;
      if ( *(int16_t *)v142 > 0 )
      {
        if ( !*(_WORD *)(v142 + 19) )
          *(_WORD *)(v142 + 19) = 20 * *(uint8_t *)(v142 + 22);
        v142 = dword_192B14;
        *(_BYTE *)(26 * n + dword_192B14 + 25) = 1;
      }
    }
    sub_FE8BE(v142);
    word_19B540 = -1;
    if ( word_17D853 )
    {
      sub_42F7F(0, 0, v95);
      sub_1694B9(v95);
      sub_1694B9(v132);
      sub_42F7F(0, 1, v95);
      sub_4545B(m, v95);
      *(_DWORD *)((char *)&a7 + 2) = v143;
      if ( word_1998E0 )
        sub_2C555();
    }
    else
    {
      sub_42F7F((int16_t)v95, 0, v95);
      sub_4545B(m, v95);
      sub_4A5CE();
      if ( word_1998E0 )
        sub_2C555();
      sub_4545B(m, v95);
      if ( !v144 )
      {
        word_19B540 = -1;
        sub_42F7F(v132, 0, v95);
        sub_4545B(m, v95);
      }
      sub_4A5CE();
      if ( word_1998E0 )
        sub_2C555();
      sub_4545B(m, v95);
      if ( !v145 )
      {
        word_19B540 = -1;
        sub_42F7F((int16_t)v95, 1, v95);
        sub_4A4E4(v95);
      }
      if ( word_1998E0 )
        sub_2C555();
      sub_4545B(m, v95);
      if ( !v146 )
      {
        word_19B540 = -1;
        sub_42F7F(v132, 1, v95);
        sub_4A4E4(v132);
      }
      if ( word_1998E0 )
        sub_2C555();
      sub_4545B(m, v95);
      *(_DWORD *)((char *)&a7 + 2) = v147;
    }
    ++word_199890;
    v134 = sub_4A575();
  }
  if ( word_199878 != -1 )
    v178 -= *(uint8_t *)(dword_192B18 + 361 * word_199878 + 10);
LABEL_181:
  sub_4B184(SHIWORD(a29), v178, SWORD1(a7));
  if ( (WORD1(a7) == 1 || WORD1(a7) == 666)
    && word_1998AC < 8
    && word_19988E >= 10
    && *(_BYTE *)(dword_197F9C + 129 * *v157 + 19) )
  {
    sub_F9711(word_19988E, -1, word_1998AC);
  }
  if ( (SWORD1(a7) == -1 || WORD1(a7) == 666)
    && word_19988E < 8
    && word_1998AC >= 10
    && *(_BYTE *)(129 * *v159 + dword_197F9C + 19) )
  {
    sub_F9711(word_1998AC, -1, word_19988E);
  }
  if ( !v186 )
  {
    sub_11C2F0();
    sub_119281();
    sub_1196F7();
    sub_123E6C((int)varA, 1);
    sub_C5BB9();
    sub_1319E4(160, 95, 0, 0, 0, 0, 0, 0);
    sub_107BA((int *)varsA);
    sub_112C96(-1, 30);
    sub_2484F();
    sub_8A4C4();
    sub_1320E9(vars6);
    sub_8F1C4((void (__fastcall *)(int, int))sub_84E9D, &byte_199F28, 0);
  }
  sub_82348();
  byte_199C93 = word_1998CC;
  byte_199C90 = word_19987E;
  byte_199C92 = word_1998C4;
  byte_199C91 = word_1998EE;
  byte_199C94 = word_1998E4;
  if ( WORD1(a7) == 666 )
    *(_DWORD *)((char *)&a7 + 2) = 0;
  word_19994C = word_1998CE;
  return *(_DWORD *)((char *)&a7 + 2);
}
// 47939: variables would overlap: ^EC.4(retaddr) and ^EE.4
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 17D853: using guessed type int16_t word_17D853;
// 18F4B0: using guessed type int dword_18F4B0[];
// 18F4B4: using guessed type int dword_18F4B4;
// 18F4B8: using guessed type int dword_18F4B8;
// 18F4BC: using guessed type int dword_18F4BC;
// 18F4C0: using guessed type int dword_18F4C0[];
// 18F768: using guessed type int dword_18F768[112];
// 190460: using guessed type int16_t word_190460;
// 192818: using guessed type int dword_192818;
// 19281C: using guessed type int dword_19281C;
// 192820: using guessed type int dword_192820;
// 192824: using guessed type int dword_192824;
// 192828: using guessed type int dword_192828;
// 19282C: using guessed type int dword_19282C;
// 192830: using guessed type int dword_192830;
// 192838: using guessed type int dword_192838;
// 19283C: using guessed type int dword_19283C;
// 192840: using guessed type int dword_192840;
// 192848: using guessed type int dword_192848;
// 192850: using guessed type int dword_192850;
// 192854: using guessed type int dword_192854;
// 192860: using guessed type int dword_192860;
// 192864: using guessed type int dword_192864;
// 19286C: using guessed type int dword_19286C;
// 192870: using guessed type int dword_192870;
// 192874: using guessed type int dword_192874;
// 19287C: using guessed type int dword_19287C;
// 192884: using guessed type int dword_192884;
// 1928A8: using guessed type int dword_1928A8;
// 1928AC: using guessed type int dword_1928AC;
// 1928C4: using guessed type int dword_1928C4;
// 1928DC: using guessed type int dword_1928DC;
// 19291C: using guessed type int dword_19291C[];
// 192928: using guessed type int dword_192928;
// 192944: using guessed type int dword_192944;
// 192948: using guessed type int dword_192948;
// 19294C: using guessed type int dword_19294C;
// 192950: using guessed type int dword_192950;
// 192954: using guessed type int dword_192954;
// 192B10: using guessed type int16_t word_192B10[];
// 192B12: using guessed type int16_t word_192B12;
// 192B14: using guessed type int dword_192B14;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199242: using guessed type int16_t word_199242[9];
// 199254: using guessed type int16_t word_199254[42];
// 199876: using guessed type int16_t word_199876;
// 199878: using guessed type int16_t word_199878;
// 19987A: using guessed type int16_t word_19987A;
// 19987C: using guessed type int16_t word_19987C;
// 19987E: using guessed type int16_t word_19987E;
// 199880: using guessed type int16_t word_199880;
// 199882: using guessed type int16_t word_199882;
// 199884: using guessed type int16_t word_199884;
// 199886: using guessed type int16_t word_199886;
// 19988A: using guessed type int16_t word_19988A;
// 19988C: using guessed type int16_t word_19988C;
// 19988E: using guessed type int16_t word_19988E;
// 199890: using guessed type int16_t word_199890;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998C4: using guessed type int16_t word_1998C4;
// 1998C6: using guessed type int16_t word_1998C6;
// 1998C8: using guessed type int16_t word_1998C8;
// 1998CA: using guessed type int16_t word_1998CA;
// 1998CC: using guessed type int16_t word_1998CC;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998D4: using guessed type int16_t word_1998D4;
// 1998D6: using guessed type int16_t word_1998D6;
// 1998DA: using guessed type int16_t word_1998DA;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998E2: using guessed type int16_t word_1998E2;
// 1998E4: using guessed type int16_t word_1998E4;
// 1998EE: using guessed type int16_t word_1998EE;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F4: using guessed type int16_t word_1998F4;
// 1998F6: using guessed type int16_t word_1998F6;
// 1998FC: using guessed type int16_t word_1998FC;
// 199904: using guessed type int16_t word_199904;
// 199906: using guessed type int16_t word_199906;
// 19994C: using guessed type int16_t word_19994C;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 199BE9: using guessed type char byte_199BE9;
// 199C90: using guessed type char byte_199C90;
// 199C91: using guessed type char byte_199C91;
// 199C92: using guessed type char byte_199C92;
// 199C93: using guessed type char byte_199C93;
// 199C94: using guessed type char byte_199C94;
// 199F28: using guessed type char byte_199F28;
// 199F3A: using guessed type char byte_199F3A;
// 19B540: using guessed type int16_t word_19B540;
// 19B57C: using guessed type char byte_19B57C;


//----- (00048EDF) --------------------------------------------------------
int __fastcall sub_48EDF(int a1, int a2)
{
  uint8_t v2; // bl

  v2 = *(_BYTE *)(a1 + 37);
  if ( v2 == *(_BYTE *)(a2 + 37) )
    return 0;
  if ( v2 >= *(_BYTE *)(a2 + 37) )
    return -1;
  return 1;
}


//----- (00048F49) --------------------------------------------------------
char __fastcall sub_48F49( int a1, int a2, int a3, int a4)
{
  char v6; // dl
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // ebx
  int v12; // [esp+4h] [ebp-Ch]

  v6 = 1;
  if ( word_199878 != -1 )
  {
    switch ( *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * word_199878 + 2) + 5) )
    {
      case 0:
        a4 = 3;
        break;
      case 1:
        a4 = 4;
        break;
      case 2:
        a4 = 6;
        break;
      case 3:
        a4 = 7;
        break;
      case 4:
        a4 = 8;
        break;
      default:
        break;
    }
    v12 = *(uint8_t *)(dword_192864 + 33);
    if ( a1 + 2 >= v12 && a1 <= a4 + v12 )
    {
      v7 = *(uint8_t *)(dword_192864 + 34);
      if ( a2 <= v7 + a4 && a2 + 2 >= v7 )
        v6 = 0;
    }
    if ( a3 > -1 )
    {
      v8 = dword_192864 + 313 * a3;
      v9 = *(uint8_t *)(v8 + 33);
      if ( v9 <= a1 + 2 && a1 <= v9 + 3 )
      {
        v10 = *(uint8_t *)(v8 + 34);
        if ( a2 <= v10 + 3 && a2 + 2 >= v10 )
          return 0;
      }
    }
  }
  return v6;
}
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199878: using guessed type int16_t word_199878;


//----- (00049043) --------------------------------------------------------
_BYTE *sub_49043()
{
  int16_t v0; // di
  char v1; // si
  int v2; // eax
  char v3; // dl
  int v4; // eax
  int16_t v5; // cx
  int v6; // eax
  _BYTE *result; // eax
  int16_t v8; // cx
  int16_t i; // cx
  uint8_t *v10; // eax
  uint8_t v11; // dl
  int16_t v12; // dx
  uint16_t v13; // ax
  int16_t v14; // dx
  uint16_t v15; // ax
  int16_t v16; // dx
  int v17; // eax
  char v18; // dl
  uint16_t v19; // dx
  int16_t v20; // ax
  uint16_t v21; // dx
  int16_t v22; // ax
  int v23; // eax
  int16_t v24; // [esp+0h] [ebp-28h]
  int16_t v25; // [esp+4h] [ebp-24h]
  char v26; // [esp+8h] [ebp-20h]
  int16_t v27; // [esp+Ch] [ebp-1Ch]
  char v28; // [esp+10h] [ebp-18h]
  int16_t v29; // [esp+14h] [ebp-14h]
  int16_t v30; // [esp+18h] [ebp-10h]
  char v31; // [esp+1Ch] [ebp-Ch]
  int16_t v32; // [esp+20h] [ebp-8h]
  char v33; // [esp+24h] [ebp-4h]

  v33 = 0;
  v0 = -1;
  v1 = 0;
  if ( word_1998AC == word_19999C || word_1998CE == 1 )
  {
    v24 = 25;
    v30 = 55;
    v28 = 0;
    v2 = dword_192864;
    v3 = 65;
    v26 = 8;
  }
  else
  {
    v24 = 55;
    v30 = 25;
    v28 = 8;
    v2 = dword_192864;
    v3 = 10;
    v26 = 0;
  }
  *(_BYTE *)(v2 + 33) = v3;
  v32 = 34;
  v25 = 34;
  v29 = 34;
  v4 = dword_192864;
  v27 = 34;
  *(_BYTE *)(dword_192864 + 37) = 100;
  v5 = 1;
  *(_BYTE *)(v4 + 34) = 34;
  while ( v5 < word_1998C0 )
  {
    v6 = dword_192864 + 313 * v5;
    if ( !*(_BYTE *)(v6 + 49) )
    {
      v31 = *(_BYTE *)(v6 + 37);
      *(_BYTE *)(v6 + 37) = 99;
    }
    ++v5;
  }
  qsort(dword_192864, word_1998C0, 313, sub_48EDF);
  result = (_BYTE *)dword_192864;
  v8 = 1;
  *(_BYTE *)(dword_192864 + 37) = 3;
  while ( v8 < word_1998C0 )
  {
    result = (_BYTE *)(dword_192864 + 313 * v8);
    if ( !result[49] )
      result[37] = v31;
    ++v8;
  }
  for ( i = 1; i < word_1998C0; ++i )
  {
    v10 = (uint8_t *)(dword_192864 + 313 * i);
    if ( v10[49] )
    {
      v12 = v10[32];
      if ( v12 == word_1998AC )
      {
        if ( (v33 & 1) != 0 )
        {
          if ( v25 < 4 )
          {
            if ( v12 == word_19999C || word_1998CE )
              v24 -= 3;
            else
              v24 += 3;
            v25 = 34;
            v32 = 34;
          }
          v15 = *(uint8_t *)(dword_192864 + 313 * i + 37);
          v16 = 0;
          if ( *(_BYTE *)(dword_192864 + 313 * i + 37) )
          {
            if ( v15 <= 2u )
            {
              v16 = 2;
            }
            else if ( v15 <= 5u )
            {
              v16 = 3;
            }
          }
          else
          {
            v16 = 1;
          }
          v25 -= v16 + 1;
          v17 = dword_192864 + 313 * i;
          *(_BYTE *)(v17 + 33) = v24;
          *(_BYTE *)(v17 + 34) = v25;
        }
        else
        {
          v10[33] = v24;
          v10[34] = v32;
          v13 = v10[37];
          v14 = 0;
          if ( v13 )
          {
            if ( v13 <= 2u )
            {
              v14 = 2;
            }
            else if ( v13 <= 5u )
            {
              v14 = 3;
            }
          }
          else
          {
            v14 = 1;
          }
          v32 += v14 + 1;
          if ( v32 > 64 )
          {
            if ( word_1998AC == word_19999C || word_1998CE )
              v24 -= 3;
            else
              v24 += 3;
            v25 = 34;
            v32 = 34;
          }
        }
        result = (_BYTE *)(dword_192864 + 313 * i);
        v18 = v28;
        ++v33;
      }
      else
      {
        if ( (v1 & 1) != 0 )
        {
          do
          {
            if ( v27 < 4 )
            {
              if ( word_1998AC == word_19999C || word_1998CE )
                v30 += 3;
              else
                v30 -= 3;
              v27 = 34;
              v29 = 34;
            }
            v21 = *(uint8_t *)(313 * i + dword_192864 + 37);
            v22 = 0;
            if ( *(_BYTE *)(313 * i + dword_192864 + 37) )
            {
              if ( v21 <= 2u )
              {
                v22 = 2;
              }
              else if ( v21 <= 5u )
              {
                v22 = 3;
              }
            }
            else
            {
              v22 = 1;
            }
            v27 -= v22 + 1;
          }
          while ( !sub_48F49(v30, v29, v0, i) );
          v23 = dword_192864 + 313 * i;
          *(_BYTE *)(v23 + 33) = v30;
          *(_BYTE *)(v23 + 34) = v27;
        }
        else
        {
          v10[33] = v30;
          v10[34] = v29;
          do
          {
            v19 = *(uint8_t *)(313 * i + dword_192864 + 37);
            v20 = 0;
            if ( *(_BYTE *)(313 * i + dword_192864 + 37) )
            {
              if ( v19 <= 2u )
              {
                v20 = 2;
              }
              else if ( v19 <= 5u )
              {
                v20 = 3;
              }
            }
            else
            {
              v20 = 1;
            }
            v29 += v20 + 1;
            if ( v29 > 64 )
            {
              if ( word_1998AC == word_19999C || word_1998CE )
                v30 += 3;
              else
                v30 -= 3;
              v27 = 34;
              v29 = 34;
            }
          }
          while ( !sub_48F49(v30, v29, v0, i) );
        }
        result = (_BYTE *)(313 * i + dword_192864);
        v18 = v26;
        ++v1;
      }
      result[35] = v18;
    }
    else
    {
      if ( v30 >= 40 )
        v11 = *(_BYTE *)(dword_192864 + 33) - 4;
      else
        v11 = *(_BYTE *)(dword_192864 + 33) + 11;
      v10[33] = v11;
      result = (_BYTE *)dword_192864;
      v0 = i;
      *(_BYTE *)(313 * i + dword_192864 + 34) = *(_BYTE *)(dword_192864 + 34) + 1;
    }
  }
  return result;
}
// 4915C: variable 'v31' is possibly undefined
// 133EF4: using guessed type int __fastcall qsort(_DWORD, _DWORD, _DWORD, _DWORD);
// 192864: using guessed type int dword_192864;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998CE: using guessed type int16_t word_1998CE;
// 19999C: using guessed type int16_t word_19999C;


//----- (000494A8) --------------------------------------------------------
int __usercall sub_494A8( int a1, int a2)
{
  int v3; // eax
  int v4; // ebx
  int v5; // ebx
  int v6; // eax

  v3 = dword_192864 + 313 * a1;
  v4 = 0;
  LOWORD(a2) = *(uint8_t *)(v3 + 37);
  if ( *(_BYTE *)(v3 + 38) )
  {
    if ( *(_BYTE *)(v3 + 37) >= 5u )
      v5 = a2 + 2;
    else
      v5 = a2 + 1;
    v6 = 59 * *(uint8_t *)(v3 + 38);
    LOWORD(v6) = 5 * *(int16_t *)((char *)&word_17F6C1 + v6);
    v4 = v6 * v5;
    if ( word_1998CA && !sub_4B0D3(a1, 13) )
      v4 = 0;
    if ( sub_4B0D3(a1, 20) )
      return 3 * (int16_t)v4 / 2;
  }
  return v4;
}
// 17F6C1: using guessed type int16_t word_17F6C1;
// 192864: using guessed type int dword_192864;
// 1998CA: using guessed type int16_t word_1998CA;


//----- (0004954A) --------------------------------------------------------
int __fastcall sub_4954A( int a1, int a2)
{
  int v3; // ecx
  _BYTE *v4; // ecx
  int v5; // eax
  char v6; // dl
  int v7; // ecx
  _BYTE *v8; // eax
  char v9; // dl
  int v10; // esi
  int v11; // eax
  int v12; // ecx
  int16_t i; // si
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // ecx
  int v22; // esi
  int v23; // eax
  int v24; // esi
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // edi
  int v29; // edx
  int v30; // esi
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // eax
  uint8_t *v35; // esi
  int16_t *v36; // ecx
  int v37; // ecx
  int v38; // eax
  int v39; // esi
  int16_t v41; // [esp+0h] [ebp-10h]
  int v42; // [esp+8h] [ebp-8h]
  int v43; // [esp+Ch] [ebp-4h]

  v3 = 129 * a1;
  v43 = 313 * (int16_t)a2;
  strcpy((char *)(v43 + dword_192864), (char *)(v3 + dword_197F9C));
  v4 = (_BYTE *)(dword_197F9C + v3);
  v5 = v43 + dword_192864;
  *(_BYTE *)(v5 + 32) = v4[99];
  *(_BYTE *)(v5 + 312) = v4[93];
  *(_WORD *)(v5 + 30) = v41;
  *(_BYTE *)(v5 + 38) = v4[18];
  *(_BYTE *)(v5 + 50) = v4[21];
  if ( *(_BYTE *)(v5 + 32) < 8u )
  {
    v6 = v4[19];
  }
  else
  {
    v6 = sub_56726(*(uint8_t *)(v5 + 32));
    v5 = v43 + dword_192864;
  }
  *(_BYTE *)(v5 + 49) = v6;
  v7 = 129 * v41 + dword_197F9C;
  v8 = (_BYTE *)(dword_192864 + 313 * (int16_t)a2);
  v8[58] = *(_BYTE *)(v7 + 96);
  v9 = *(_BYTE *)(v7 + 16);
  v8[36] = 0;
  v10 = 0;
  v8[37] = v9;
  do
  {
    v11 = (int16_t)v10 + 129 * v41 + dword_197F9C;
    v12 = dword_192864 + 313 * (int16_t)a2 + (int16_t)v10;
    *(_BYTE *)(v12 + 76) = *(_BYTE *)(v11 + 23);
    ++v10;
    *(_BYTE *)(v12 + 178) = *(_BYTE *)(v11 + 118);
  }
  while ( (int16_t)v10 < 5 );
  for ( i = 0; i < 8; ++i )
  {
    v14 = 129 * v41 + dword_197F9C + 8 * i;
    v15 = dword_192864 + 313 * (int16_t)a2 + 11 * i;
    *(_WORD *)(v15 + 82) = *(_WORD *)(v14 + 28);
    *(_BYTE *)(v15 + 84) = *(_BYTE *)(v14 + 31);
    *(_BYTE *)(v15 + 85) = *(_BYTE *)(v14 + 32);
    *(_WORD *)(v15 + 86) = *(_WORD *)(v14 + 33);
    *(_WORD *)(v15 + 88) = *(uint8_t *)(v14 + 35);
    if ( *(_BYTE *)(v15 + 85) == 16 )
      *(_BYTE *)(v15 + 85) = 15;
    v16 = 313 * (int16_t)a2 + dword_192864 + 11 * i;
    v17 = 28 * *(int16_t *)(v16 + 82);
    *(_BYTE *)(v16 + 90) = 1;
    *(_BYTE *)(v16 + 91) = *(_BYTE *)(v16 + 84);
    if ( byte_17F80F[v17] == 2 )
    {
      *(_WORD *)(v16 + 88) = 0;
    }
    else if ( byte_17F80F[v17] != 1 )
    {
      *(_WORD *)(v16 + 88) = (uint8_t)byte_17F810[v17];
    }
    v18 = 313 * (int16_t)a2 + dword_192864 + 11 * i;
    if ( *(_WORD *)(v18 + 82) == 33 )
      *(_WORD *)(v18 + 88) *= *(uint8_t *)(v18 + 84);
    v19 = 11 * i;
    *(_BYTE *)(dword_192864 + 313 * (int16_t)a2 + v19 + 92) = 0;
  }
  v20 = 0;
  do
  {
    v21 = dword_192864 + 313 * (int16_t)a2;
    v22 = (int16_t)v20++;
    *(_BYTE *)(v21 + v22 + 184) = 1;
  }
  while ( (int16_t)v20 < 8 );
  v23 = 129 * v41 + dword_197F9C;
  *(_BYTE *)(v21 + 172) = *(_BYTE *)(v23 + 113);
  v24 = *(int16_t *)(v23 + 116);
  if ( v24 <= -1 || *(_BYTE *)(59 * v24 + dword_1930DC + 55) )
    *(_WORD *)(dword_192864 + 313 * (int16_t)a2 + 173) = -1;
  else
    *(_WORD *)(v21 + 173) = *(_WORD *)(v23 + 116);
  v25 = dword_197F9C + 129 * v41;
  if ( *(_BYTE *)(v25 + 17) || *(char *)(v25 + 99) > 8 )
  {
    *(_BYTE *)(dword_192864 + 313 * (int16_t)a2 + 175) = -1;
  }
  else
  {
    v26 = 313 * (int16_t)a2;
    v27 = v26 + dword_192864 + 76;
    *(_BYTE *)(v27 + 99) = byte_180022[36 * *(uint8_t *)(v26 + dword_192864 + 37)];
    if ( (uint16_t)sub_1276F0(v27, 0x24u) == 1 && !(uint16_t)sub_1276F0(v26 + dword_192864 + 178, 0x24u) )
      *(_BYTE *)(v26 + dword_192864 + 175) *= 2;
  }
  v28 = 313 * (int16_t)a2;
  v29 = 129 * v41;
  *(_WORD *)(v28 + dword_192864 + 170) = sub_58387(v41, v29, a2, v41);
  v30 = dword_197F9C;
  LOWORD(v30) = sub_58425(v41) - *(_WORD *)(v29 + v30 + 123);
  v31 = v28 + dword_192864;
  v32 = v29 + dword_197F9C;
  *(_WORD *)(v31 + 194) = v30;
  *(_BYTE *)(v31 + 51) = *(_BYTE *)(v32 + 22);
  LOWORD(v29) = *(_WORD *)(v32 + 125);
  *(_WORD *)(v31 + 192) = v29;
  if ( (int16_t)v29 > *(int16_t *)(v31 + 170) )
    *(_WORD *)(v31 + 192) = *(_WORD *)(v31 + 170) - 1;
  v33 = dword_192864 + 313 * (int16_t)a2;
  if ( *(_BYTE *)(v33 + 37) == 5 && *(_BYTE *)(v33 + 32) < 8u )
    *(_WORD *)(v33 + 196) = 43;
  else
    *(_WORD *)(313 * (int16_t)a2 + dword_192864 + 196) = *(char *)(129 * v41 + dword_197F9C + 92);
  v42 = 313 * (int16_t)a2;
  v34 = v42 + dword_192864;
  *(_BYTE *)(v34 + 75) = 0;
  sub_36470(v34);
  v35 = (uint8_t *)(129 * v41 + dword_197F9C);
  v36 = (int16_t *)(v42 + dword_192864);
  v36[154] = *(int16_t *)(v42 + dword_192864 + 254) * (100 - v35[110]) / 100;
  v36[128] = v36[101] * (100 - v35[111]) / 100;
  v36[129] = v36[102] - v35[112];
  *(_WORD *)(v42 + dword_192864 + 39) = sub_494A8(a2, (int)v35);
  v37 = 0;
  do
  {
    v38 = dword_192864 + 313 * (int16_t)a2;
    v39 = (int16_t)v37++;
    *(_WORD *)(v38 + 2 * v39 + 41) = *(_WORD *)(v38 + 39);
  }
  while ( (int16_t)v37 < 4 );
  if ( *(_BYTE *)(v38 + 32) > 8u && !*(_BYTE *)(v38 + 49) )
  {
    switch ( *(_BYTE *)(v38 + 32) )
    {
      case 9:
      case 0xB:
        *(_BYTE *)(v38 + 49) = 4;
        break;
      case 0xA:
      case 0xE:
        *(_BYTE *)(v38 + 49) = 2;
        break;
      case 0xC:
      case 0xD:
        *(_BYTE *)(v38 + 49) = 6;
        break;
      default:
        return sub_4C9F6(a2);
    }
  }
  return sub_4C9F6(a2);
}
// 495A5: variable 'v41' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;


//----- (00049A41) --------------------------------------------------------
void __usercall sub_49A41(int a1, int a2)
{
  int16_t v2; // si
  int16_t v3; // bx
  int v4; // ecx
  int16_t v5; // si
  int16_t v6; // ax
  int16_t v7; // si
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int16_t v13; // [esp+0h] [ebp-4h]

  v13 = 0;
  while ( sub_123ABA() < 5 || sub_123ABA() > 635 || sub_123AE7() < 5 || sub_123AE7() > 475 )
  {
    a1 = 1;
    v2 = word_1998F0;
    LOWORD(a2) = word_1998F2;
    v3 = word_1998F0;
    ++v13;
    v4 = a2;
    if ( v13 > 2 )
      a1 = 2;
    if ( v13 > 4 )
      a1 = 3;
    if ( sub_123ABA() < 5 )
      v3 = word_1998F0 - a1;
    if ( sub_123ABA() > 635 )
      v3 = a1 + word_1998F0;
    if ( sub_123AE7() < 5 )
    {
      LOWORD(v4) = word_1998F2;
      v4 -= a1;
    }
    if ( sub_123AE7() > 475 )
    {
      LOWORD(v4) = word_1998F2;
      v4 += a1;
    }
    if ( v3 < 0 )
      v3 = 0;
    if ( v3 > 49 )
      v3 = 49;
    if ( (v4 & 0x8000u) != 0 )
      v4 = 0;
    if ( (int16_t)v4 > 50 )
      v4 = 50;
    v5 = v2 - v3;
    a2 -= v4;
    if ( v5 >= 0 )
    {
      if ( v5 <= 0 )
        v6 = 0;
      else
        v6 = -1;
    }
    else
    {
      v6 = 1;
    }
    if ( (a2 & 0x8000u) == 0 )
    {
      if ( (int16_t)a2 <= 0 )
        v7 = 0;
      else
        v7 = -1;
    }
    else
    {
      v7 = 1;
    }
    if ( v3 != word_1998F0 )
    {
      word_19988C -= 80 * v6;
      word_199886 -= 40 * v6;
      v8 = 20 * v6 / 2;
      a1 = word_199880 - v8;
      word_199880 -= v8;
    }
    if ( (_WORD)v4 != word_1998F2 )
    {
      word_19988A -= 80 * v7;
      word_199884 -= 40 * v7;
      v9 = 20 * v7 / 2;
      a1 = word_199882 - v9;
      word_199882 -= v9;
    }
    word_19988C += word_19988C < 0 ? 0x280 : 0;
    word_19988A += word_19988A < 0 ? 0x1E0 : 0;
    word_199886 += word_199886 < 0 ? 0x280 : 0;
    word_199884 += word_199884 < 0 ? 0x1E0 : 0;
    word_199880 += word_199880 < 0 ? 0x280 : 0;
    word_199882 += word_199882 < 0 ? 0x1E0 : 0;
    word_19988C %= 640;
    word_19988A %= 480;
    word_199886 %= 640;
    word_199884 %= 480;
    word_199880 %= 640;
    LOWORD(a1) = word_199882 % 480;
    word_1998F0 = v3;
    word_1998F2 = v4;
    word_199882 %= 480;
    v10 = sub_124D41();
    v11 = sub_33543(v10);
    sub_1077D(v11);
  }
  sub_46CC8(word_1998F8, a1);
  sub_465D0();
  sub_2C601(v12, a1);
  word_1998F4 = -1;
  JUMPOUT(0x494A1);
}
// 49D04: control flows out of bounds to 494A1
// 49CF6: variable 'v12' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 33543: using guessed type int __fastcall sub_33543(_DWORD);
// 199880: using guessed type int16_t word_199880;
// 199882: using guessed type int16_t word_199882;
// 199884: using guessed type int16_t word_199884;
// 199886: using guessed type int16_t word_199886;
// 19988A: using guessed type int16_t word_19988A;
// 19988C: using guessed type int16_t word_19988C;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F4: using guessed type int16_t word_1998F4;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (00049D09) --------------------------------------------------------
void __fastcall sub_49D09(int a1, int a2)
{
  int16_t v2; // bx
  int v3; // ecx
  int16_t v4; // bx
  int v5; // edx
  int16_t v6; // si
  int v7; // edx
  int v8; // eax

  v2 = a2;
  LOWORD(a2) = word_1998F0;
  v3 = a1 - 16;
  v4 = v2 - 9;
  if ( (int16_t)(a1 - 16) < 0 )
    v3 = 0;
  if ( (int16_t)v3 > 49 )
    v3 = 49;
  if ( v4 < 0 )
    v4 = 0;
  if ( v4 > 50 )
    v4 = 50;
  v5 = a2 - v3;
  word_19988C -= 160 * v5;
  word_19988A -= 160 * (word_1998F2 - v4);
  v6 = 80 * v5;
  v7 = 20 * v5;
  word_199886 -= v6;
  word_199880 -= v7;
  word_199884 -= 80 * (word_1998F2 - v4);
  word_199882 -= 20 * (word_1998F2 - v4);
  while ( word_19988C < 0 )
    word_19988C += 640;
  while ( word_19988A < 0 )
    word_19988A += 480;
  while ( word_199886 < 0 )
    word_199886 += 640;
  while ( word_199884 < 0 )
    word_199884 += 480;
  while ( word_199880 < 0 )
    word_199880 += 640;
  while ( word_199882 < 0 )
    word_199882 += 480;
  word_19988C %= 640;
  word_19988A %= 480;
  word_199886 %= 640;
  word_199884 %= 480;
  word_199880 %= 640;
  word_1998F0 = v3;
  word_1998F2 = v4;
  word_199882 %= 480;
  LOWORD(v7) = word_199882;
  sub_465D0();
  sub_46CC8(word_1998F8, v7);
  sub_2C601(v8, v7);
}
// 49EB4: variable 'v8' is possibly undefined
// 199880: using guessed type int16_t word_199880;
// 199882: using guessed type int16_t word_199882;
// 199884: using guessed type int16_t word_199884;
// 199886: using guessed type int16_t word_199886;
// 19988A: using guessed type int16_t word_19988A;
// 19988C: using guessed type int16_t word_19988C;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (00049ED1) --------------------------------------------------------
int __fastcall sub_49ED1( int a1, _WORD *a2, _WORD *a3)
{
  int64_t v5; // rax
  uint8_t v6; // cl

  v5 = 0;
  if ( a1 )
  {
    v6 = *(_BYTE *)(dword_192864 + 313 * a1 + 37);
    if ( !v6 )
    {
      LODWORD(v5) = 10;
      goto LABEL_4;
    }
    if ( v6 <= 2u )
    {
      LODWORD(v5) = 20;
      goto LABEL_4;
    }
    if ( v6 <= 5u )
    {
      LODWORD(v5) = 30;
      WORD2(v5) = 30;
    }
  }
  else
  {
    if ( word_199878 == -1 )
    {
LABEL_3:
      LODWORD(v5) = 60;
LABEL_4:
      WORD2(v5) = v5;
      goto LABEL_17;
    }
    switch ( *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(361 * word_199878 + dword_192B18 + 2) + 5) )
    {
      case 0:
        LODWORD(v5) = 30;
        goto LABEL_4;
      case 1:
        LODWORD(v5) = 40;
        goto LABEL_4;
      case 2:
        goto LABEL_3;
      case 3:
        LODWORD(v5) = 70;
        goto LABEL_4;
      case 4:
        LODWORD(v5) = 80;
        goto LABEL_4;
      default:
        break;
    }
  }
LABEL_17:
  *a2 = v5;
  *a3 = WORD2(v5);
  return v5;
}
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199878: using guessed type int16_t word_199878;


//----- (00049F99) --------------------------------------------------------
void sub_49F99()
{
  int v0; // eax
  char v1; // cl
  char v2; // ch
  int v3; // ebx
  int v4; // edx
  int v5; // esi
  int v6; // eax
  int16_t v7; // cx
  int16_t v8; // dx
  int v9; // edx
  int v10; // eax
  int16_t v11; // [esp+0h] [ebp-54h]
  _BYTE v12[32]; // [esp+4h] [ebp-50h]
  _BYTE v13[32]; // [esp+24h] [ebp-30h] BYREF
  char v14[16]; // [esp+44h] [ebp-10h] BYREF

  v0 = 0;
  v1 = 96;
  v2 = 32;
  do
  {
    v12[(int16_t)v0] = v2;
    v13[(int16_t)v0++] = v1++;
    ++v2;
  }
  while ( (int16_t)v0 < 32 );
  if ( v11 >= 8 )
  {
    v3 = dword_193174;
    v4 = v11 + 5;
    strcpy(v14, "monster.lbx");
  }
  else
  {
    strcpy(v14, "cmbtshp.lbx");
    v3 = dword_193174;
    v4 = 45 * *(uint8_t *)(dword_197F98 + 3753 * v11 + 38) + 44;
  }
  v5 = sub_127C27((int)v14, v4, v3);
  if ( v11 == word_19988E && v11 <= 8 )
  {
    v6 = word_199878;
    if ( word_199878 > -1 || v11 == 8 )
    {
      if ( v11 == 8 )
      {
        v7 = 2;
        v8 = 2;
      }
      else
      {
        v8 = *(uint8_t *)(dword_197F98 + 3753 * v11 + 38);
        v6 = 17 * *(int16_t *)(361 * word_199878 + dword_192B18 + 2);
        v7 = *(uint8_t *)(dword_1930D4 + v6 + 5);
      }
      if ( v7 > 0 )
      {
        v6 = (int)sub_126B42((int)aCombatLbx_2, (int16_t)(v7 + 4 * v8 + 55 - 1), dword_192ED4);
        dword_1928A4 = v6;
      }
      sub_FE8BE(v6);
      if ( v7 > 0 )
      {
        sub_1381B5(v5, 96);
        sub_12B79D(v5);
        sub_137D86(dword_1928A4, (int)v13, 80, 16);
      }
    }
  }
  if ( word_1998AC == v11 )
    v9 = 32;
  else
    v9 = 96;
  sub_1381B5(v5, v9);
  v10 = sub_12B79D(v5);
  sub_FE8BE(v10);
  JUMPOUT(0x494A1);
}
// 4A125: control flows out of bounds to 494A1
// 49FCA: variable 'v11' is possibly undefined
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 1928A4: using guessed type int dword_1928A4;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;


//----- (0004A12A) --------------------------------------------------------
void sub_4A12A()
{
  char v0; // dh
  char v1; // dl
  int v2; // eax
  int v3; // eax
  int v4; // ecx
  _DWORD *v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int16_t v11; // cx
  _DWORD *v12; // edx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int16_t v19; // bx
  int v20; // eax
  int v21; // ecx
  _DWORD *v22; // edx
  int v23; // eax
  int v24; // eax
  int v25; // [esp+0h] [ebp-10Ch]
  _DWORD v26[45]; // [esp+4h] [ebp-108h]
  _BYTE v27[32]; // [esp+B8h] [ebp-54h] BYREF
  _BYTE v28[32]; // [esp+D8h] [ebp-34h] BYREF
  char v29[16]; // [esp+F8h] [ebp-14h] BYREF
  int v30; // [esp+108h] [ebp-4h]

  LOWORD(v30) = 0;
  v0 = 96;
  v1 = 32;
  do
  {
    v2 = (int16_t)v30;
    v27[(int16_t)v30] = v1;
    v28[v2] = v0++;
    LOWORD(v30) = v30 + 1;
    ++v1;
  }
  while ( (int16_t)v30 < 32 );
  LOWORD(v30) = 0;
  do
  {
    v3 = (int16_t)v30;
    LOWORD(v30) = v30 + 1;
    v26[v3] = 0;
  }
  while ( (int16_t)v30 < 45 );
  if ( (int16_t)v25 >= 8 )
  {
    if ( (_WORD)v25 == 8 )
    {
      LOWORD(v30) = 0;
      v11 = 64;
      do
      {
        v12 = sub_126B42((int)aCmbtfgtrLbx, v11++, dword_192ED4);
        v13 = (int16_t)v30;
        LOWORD(v30) = v30 + 1;
        dword_18B2A8[v13 + 512] = (int)v12;
        sub_FE8BE(v13);
      }
      while ( (int16_t)v30 < 16 );
      if ( word_1998AC == 8 )
      {
        LOWORD(v30) = 0;
        do
        {
          v14 = dword_18B2A8[(int16_t)v30 + 512];
          LOWORD(v30) = v30 + 1;
          v15 = sub_137D86(v14, (int)v27, 80, 16);
          sub_FE8BE(v15);
        }
        while ( (int16_t)v30 < 16 );
      }
      else
      {
        LOWORD(v30) = 0;
        do
        {
          v16 = dword_18B2A8[(int16_t)v30 + 512];
          LOWORD(v30) = v30 + 1;
          v17 = sub_137D86(v16, (int)v28, 80, 16);
          sub_FE8BE(v17);
        }
        while ( (int16_t)v30 < 16 );
      }
    }
  }
  else
  {
    LOWORD(v30) = 0;
    do
    {
      v4 = (int16_t)v30;
      v5 = sub_126B42((int)aCmbtfgtrLbx, (int16_t)v30, dword_192ED4);
      v6 = (int16_t)v25 << 8;
      LOWORD(v30) = v30 + 1;
      *(int *)((char *)&dword_18B2A8[v4] + v6) = (int)v5;
      sub_FE8BE(v6);
    }
    while ( (int16_t)v30 < 64 );
    if ( (_WORD)v25 == word_1998AC )
    {
      LOWORD(v30) = 0;
      do
      {
        v7 = dword_18B2A8[64 * (int16_t)v25 + (int16_t)v30];
        LOWORD(v30) = v30 + 1;
        v8 = sub_137D86(v7, (int)v27, 80, 16);
        sub_FE8BE(v8);
      }
      while ( (int16_t)v30 < 64 );
    }
    else
    {
      LOWORD(v30) = 0;
      do
      {
        v9 = dword_18B2A8[64 * (int16_t)v25 + (int16_t)v30];
        LOWORD(v30) = v30 + 1;
        v10 = sub_137D86(v9, (int)v28, 80, 16);
        sub_FE8BE(v10);
      }
      while ( (int16_t)v30 < 64 );
    }
  }
  LOWORD(v30) = 1;
  while ( (int16_t)v30 < word_1998C0 )
  {
    v18 = 313 * (int16_t)v30 + dword_192864;
    if ( *(uint8_t *)(v18 + 32) == (_WORD)v25 )
    {
      if ( *(uint8_t *)(v18 + 312) >= 8u || *(_WORD *)(v18 + 196) == 44 )
      {
        v20 = 313 * (int16_t)v30 + dword_192864;
        strcpy(v29, "monster.lbx");
        if ( *(_WORD *)(v20 + 196) == 44 )
          v19 = 25;
        else
          v19 = *(_WORD *)(v20 + 196);
      }
      else
      {
        strcpy(v29, "cmbtshp.lbx");
        v19 = *(_WORD *)(v18 + 196) + 45 * *(uint8_t *)(dword_197F98 + 3753 * (int16_t)v25 + 38);
      }
      v21 = 313 * (int16_t)v30;
      if ( v26[*(int16_t *)(v21 + dword_192864 + 196)] )
      {
        *(_DWORD *)(v21 + dword_192864 + 198) = v26[*(int16_t *)(v21 + dword_192864 + 196)];
      }
      else if ( sub_111499(dword_192ED4) <= (unsigned int)&loc_30D40 )
      {
        *(_DWORD *)(v21 + dword_192864 + 198) = 0;
      }
      else
      {
        v22 = sub_126B42((int)v29, v19, dword_192ED4);
        v23 = *(int16_t *)(v21 + dword_192864 + 196);
        v26[v23] = v22;
        sub_FE8BE(v23);
        v24 = v25;
        if ( (_WORD)v25 == word_19988E )
          v24 = sub_137D86(v26[*(int16_t *)(v21 + dword_192864 + 196)], (int)v28, 32, 32);
        sub_FE8BE(v24);
        *(_DWORD *)(dword_192864 + 313 * (int16_t)v30 + 198) = v26[*(int16_t *)(dword_192864 + 313 * (int16_t)v30 + 196)];
      }
    }
    LOWORD(v30) = v30 + 1;
  }
  JUMPOUT(0x494A1);
}
// 4A4DF: control flows out of bounds to 494A1
// 4A189: variable 'v25' is possibly undefined
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 18B2A8: using guessed type int dword_18B2A8[960];
// 192864: using guessed type int dword_192864;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0004A4E4) --------------------------------------------------------
void __fastcall sub_4A4E4( int a1)
{
  int16_t i; // di
  int v2; // edx
  uint8_t *v3; // eax

  for ( i = 1; i < word_1998C0; ++i )
  {
    v2 = 313 * i;
    if ( !*(_BYTE *)(v2 + dword_192864 + 36)
      && *(uint8_t *)(v2 + dword_192864 + 32) == a1
      && !sub_3E563(i)
      && sub_3E57C(i) )
    {
      v3 = (uint8_t *)(v2 + dword_192864);
      if ( ++v3[310] == 3 )
        sub_39E15(i, 20 * v3[33], 20 * v3[34], 1);
    }
  }
  JUMPOUT(0x494A1);
}
// 4A570: control flows out of bounds to 494A1
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0004A575) --------------------------------------------------------
int sub_4A575()
{
  int result; // eax
  int16_t i; // dx

  sub_4A790();
  sub_4CFE7();
  result = dword_192864;
  if ( !*(_BYTE *)(dword_192864 + 36) )
  {
    result = word_199890 / 10;
    if ( !(word_199890 % 10) )
    {
      for ( i = 0; i < 8; ++i )
      {
        result = 11 * i + dword_192864;
        if ( byte_17F80F[28 * *(int16_t *)(result + 82)] == 4 )
          *(_WORD *)(result + 88) = 1;
      }
    }
  }
  return result;
}
// 192864: using guessed type int dword_192864;
// 199890: using guessed type int16_t word_199890;


//----- (0004A5CE) --------------------------------------------------------
void sub_4A5CE()
{
  int16_t i; // si
  int v1; // eax
  int v2; // eax
  int v3; // ebx
  int16_t v4; // ax
  int v5; // eax
  int16_t v6; // [esp+0h] [ebp-1Ch]
  int v7; // [esp+8h] [ebp-14h] BYREF
  int v8; // [esp+Ch] [ebp-10h]
  int v9; // [esp+10h] [ebp-Ch]
  int v10; // [esp+14h] [ebp-8h] BYREF
  int v11; // [esp+18h] [ebp-4h]

  v7 = 0;
  v10 = 0;
  for ( i = 0; i < word_1998C0; ++i )
  {
    v1 = 313 * i + dword_192864;
    if ( !*(_BYTE *)(v1 + 36) && *(int16_t *)(v1 + 67) > 0 && *(uint8_t *)(v1 + 32) == v6 && !sub_3E563(i) )
    {
      v9 = 0;
      v11 = 0;
      v8 = 0;
      do
      {
        v2 = 313 * i + dword_192864;
        LOWORD(v2) = *(_WORD *)(v2 + 67);
        v7 = v2;
        sub_39985(i, (int16_t *)&v7, (int16_t *)&v10, (int16_t)v8, 0, 0, 0, 0, 0);
        v9 += v7;
        ++v8;
        v11 += v10;
      }
      while ( (int16_t)v8 < 4 );
      if ( word_1998F6 == 1 && !word_1998E0 )
      {
        if ( !(uint16_t)sub_339A7(i, (int)&v7, (int)&v10) )
          sub_49D09(
            *(uint8_t *)(313 * i + dword_192864 + 33),
            *(uint8_t *)(313 * i + dword_192864 + 34));
        sub_A93AA(
          (int16_t)(20 * (*(uint8_t *)(dword_192864 + 313 * i + 33) - word_1998F0)),
          (int16_t)(20 * (*(uint8_t *)(dword_192864 + 313 * i + 34) - word_1998F2)),
          i,
          1,
          v9,
          v11);
        sub_A94A1();
      }
      v3 = 313 * i;
      v4 = sub_3897A(i);
      if ( v4 )
      {
        sub_39E15(
          i,
          20 * *(uint8_t *)(v3 + dword_192864 + 33),
          20 * *(uint8_t *)(v3 + dword_192864 + 34),
          v4);
      }
      else
      {
        v5 = *(int16_t *)(v3 + dword_192864 + 67) - 5;
        if ( v5 < 0 )
          LOWORD(v5) = 0;
        *(_WORD *)(dword_192864 + 313 * i + 67) = v5;
      }
    }
  }
  JUMPOUT(0x494A1);
}
// 4A78B: control flows out of bounds to 494A1
// 4A61B: variable 'v6' is possibly undefined
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F6: using guessed type int16_t word_1998F6;


//----- (0004A790) --------------------------------------------------------
void sub_4A790()
{
  int16_t i; // cx
  int v1; // edx
  int v2; // ebx
  int v3; // ebx
  int16_t j; // si
  int v5; // edx
  int v6; // eax
  int16_t v7; // [esp+0h] [ebp-4h]

  for ( i = 1; i < word_1998C0; ++i )
  {
    v1 = 313 * i;
    if ( *(_BYTE *)(v1 + dword_192864 + 38) && !sub_3E563(i) && *(int16_t *)(v1 + dword_192864 + 308) > 0 )
    {
      v2 = 3;
      if ( sub_4B0D3(i, 30) )
        v2 = 10;
      v7 = 1;
      v3 = v2 * *(int16_t *)(dword_192864 + 313 * i + 39) / 10;
      while ( v3 > 0 && v7 )
      {
        v7 = 0;
        for ( j = 0; j < 4; ++j )
        {
          v5 = 313 * i + dword_192864;
          v6 = v5 + 2 * j;
          if ( *(_WORD *)(v6 + 41) < *(_WORD *)(v5 + 39) && v3 > 0 )
          {
            v7 = 1;
            --v3;
            ++*(_WORD *)(v6 + 41);
          }
        }
      }
    }
  }
  JUMPOUT(0x494A1);
}
// 4A87F: control flows out of bounds to 494A1
// 192864: using guessed type int dword_192864;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0004A884) --------------------------------------------------------
int __fastcall sub_4A884( int a1)
{
  _BYTE *v1; // eax
  int v2; // edx

  v1 = (_BYTE *)(dword_192B18 + 361 * a1);
  v2 = -1;
  if ( v1[350] )
    return 6;
  if ( v1[318] )
    return 7;
  if ( v1[351] )
    return 8;
  return v2;
}
// 192B18: using guessed type int dword_192B18;


//----- (0004A8D3) --------------------------------------------------------
int sub_4A8D3()
{
  int v0; // eax
  int v1; // edi
  int v2; // edx
  int v3; // eax
  int v4; // ebx
  int v5; // edx
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // eax

  sub_127776((_BYTE *)dword_192864, 0x139u);
  v0 = dword_192864;
  v1 = dword_192864;
  *(_DWORD *)dword_192864 = *(_DWORD *)aAntares_0;
  *(_DWORD *)(v1 + 4) = *(_DWORD *)&aAntares_0[4];
  *(_WORD *)(v0 + 30) = -1;
  *(_WORD *)(v0 + 173) = -1;
  *(_BYTE *)(v0 + 37) = 5;
  *(_BYTE *)(v0 + 36) = 0;
  *(_BYTE *)(v0 + 32) = 8;
  *(_BYTE *)(v0 + 312) = 8;
  *(_BYTE *)(v0 + 49) = 0;
  *(_BYTE *)(v0 + 75) = 0;
  *(_BYTE *)(v0 + 38) = 0;
  v2 = 0;
  *(_WORD *)(v0 + 39) = 0;
  do
  {
    v3 = dword_192864;
    v4 = 2 * (int16_t)v2++;
    *(_WORD *)(v4 + dword_192864 + 41) = 0;
  }
  while ( (int16_t)v2 < 4 );
  *(_BYTE *)(v3 + 50) = 5;
  *(_BYTE *)(v3 + 51) = 6;
  v5 = 0;
  do
  {
    v6 = dword_192864;
    v7 = (int16_t)v5;
    *(_BYTE *)(dword_192864 + (int16_t)v5++ + 76) = 0;
    *(_BYTE *)(v6 + v7 + 178) = 0;
  }
  while ( (int16_t)v5 < 5 );
  sub_36470(v6);
  v8 = dword_192864;
  *(_WORD *)(dword_192864 + 254) = 0;
  v9 = dword_193174;
  *(_WORD *)(v8 + 308) = 0;
  v10 = sub_127C27((int)aCmbtplntLbx, 62, v9);
  sub_12B79D(v10);
  sub_131F7B();
  dword_19285C = (int)sub_126B42((int)aCmbtplntLbx, 60, dword_192ED4);
  sub_FE8BE(dword_19285C);
  dword_19288C = (int)sub_126B42((int)aCmbtplntLbx, 61, dword_192ED4);
  return sub_FE8BE(dword_19288C);
}
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 19285C: using guessed type int dword_19285C;
// 192864: using guessed type int dword_192864;
// 19288C: using guessed type int dword_19288C;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;


//----- (0004A9E9) --------------------------------------------------------
void __usercall sub_4A9E9( int a1, int a2)
{
  int16_t v2; // ax
  int v3; // eax

  if ( a1 <= -1 )
  {
    v3 = dword_192864;
    *(_BYTE *)(dword_192864 + 32) = 8;
    *(_BYTE *)(v3 + 312) = 8;
    *(_WORD *)(v3 + 30) = -1;
    *(_BYTE *)(v3 + 36) = 5;
  }
  else
  {
    sub_4AA36(a1, 1);
    v2 = sub_4A884(word_199878);
    if ( v2 != -1 )
    {
      sub_4BBD5(v2, a2);
      ++word_1998C0;
    }
  }
}
// 192864: using guessed type int dword_192864;
// 199878: using guessed type int16_t word_199878;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0004AA36) --------------------------------------------------------
void __fastcall sub_4AA36( int a1, int a2)
{
  int v2; // edx
  char *v3; // eax
  char *v4; // edx
  int v5; // eax
  int16_t v6; // bx
  int v7; // eax
  int v8; // edx
  int v9; // edx
  char v10; // al
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // edx
  int v17; // edx
  int16_t v18; // si
  int16_t v19; // ax
  int16_t v20; // di
  int16_t v21; // ax
  char v22; // dl
  int v23; // eax
  int16_t v24; // ax
  int16_t v25; // di
  int16_t v26; // ax
  int v27; // edx
  int v28; // eax
  int v29; // eax
  int v30; // edx
  char *v31; // eax
  int v32; // eax
  int16_t v33; // bx
  char v34; // dl
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int16_t v38; // ax
  int16_t v39; // di
  int16_t v40; // ax
  int v41; // eax
  char v42; // bl
  int v43; // eax
  int v44; // edx
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int16_t v50; // [esp+8h] [ebp-14h]
  char v51; // [esp+Ch] [ebp-10h]
  int16_t v52; // [esp+10h] [ebp-Ch]
  int16_t v53; // [esp+10h] [ebp-Ch]
  int16_t v54; // [esp+10h] [ebp-Ch]
  int16_t v55; // [esp+10h] [ebp-Ch]
  int16_t v56; // [esp+14h] [ebp-8h]
  int16_t v57; // [esp+18h] [ebp-4h]

  v2 = 361 * a1;
  sub_77B42();
  strcpy((char *)dword_192864, v3);
  v4 = (char *)(dword_192B18 + v2);
  v51 = *v4;
  v5 = dword_192864;
  *(_WORD *)(dword_192864 + 30) = -1;
  *(_BYTE *)(v5 + 49) = 0;
  *(_WORD *)(v5 + 173) = -1;
  *(_BYTE *)(v5 + 75) = 0;
  *(_BYTE *)(v5 + 32) = v51;
  *(_BYTE *)(v5 + 312) = v51;
  v6 = 0;
  if ( v4[338] )
  {
    v6 = 5;
    *(_BYTE *)(v5 + 38) = 28;
  }
  else if ( v4[333] )
  {
    v6 = 20;
    *(_BYTE *)(v5 + 38) = 23;
  }
  else if ( v4[334] )
  {
    v6 = 10;
    *(_BYTE *)(v5 + 38) = 24;
  }
  else
  {
    *(_BYTE *)(v5 + 38) = 0;
  }
  *(_WORD *)(dword_192864 + 39) = v6;
  v7 = 0;
  do
  {
    v8 = (int16_t)v7++;
    *(_WORD *)(dword_192864 + 2 * v8 + 41) = v6;
  }
  while ( (int16_t)v7 < 4 );
  *(_WORD *)(dword_192864 + 41) += *(int16_t *)((char *)&word_17F6C1 + 59 * (int16_t)sub_5679E(word_19988E));
  v9 = 361 * a1;
  *(_BYTE *)(dword_192864 + 50) = sub_5680D(*(char *)(v9 + dword_192B18));
  sub_5685F(*(char *)(v9 + dword_192B18));
  LOBYTE(v9) = v10;
  v11 = dword_192864;
  *(_BYTE *)(dword_192864 + 37) = 5;
  *(_BYTE *)(v11 + 36) = 0;
  *(_BYTE *)(v11 + 51) = v9;
  v12 = 0;
  do
  {
    v13 = dword_192864;
    v14 = (int16_t)v12;
    *(_BYTE *)((int16_t)v12++ + dword_192864 + 76) = 0;
    *(_BYTE *)(v14 + v13 + 178) = 0;
  }
  while ( (int16_t)v12 < 5 );
  v15 = 0;
  do
  {
    v16 = 11 * (int16_t)v15++;
    *(_WORD *)(v16 + dword_192864 + 82) = 0;
  }
  while ( (int16_t)v15 < 8 );
  v17 = 361 * a1;
  v18 = 0;
  if ( *(_BYTE *)(v17 + dword_192B18 + 337) )
  {
    sub_568EB(*(char *)(v17 + dword_192B18));
    v20 = v19;
    sub_6D048(word_19988E, word_17F80D[14 * v19]);
    v52 = 2;
    if ( v21 >= (uint8_t)byte_17FD41 )
      v52 = 10;
    if ( v21 >= (uint8_t)byte_17FD50 )
      LOBYTE(v52) = v52 | 0x10;
    if ( v21 >= (uint8_t)byte_17FD6E )
      LOBYTE(v52) = v52 | 0x40;
    if ( v21 >= (uint8_t)byte_17FD5F )
      LOBYTE(v52) = v52 | 0x20;
    v53 = word_17F81D[14 * v20] & v52;
    v22 = 225 / sub_6EE8E(word_19988E, v20, 1, 1, 1u, v53);
    v23 = dword_192864;
    *(_BYTE *)(dword_192864 + 85) = 15;
    *(_WORD *)(v23 + 88) = -1;
    *(_BYTE *)(v23 + 90) = 1;
    *(_BYTE *)(v23 + 92) = 0;
    *(_WORD *)(v23 + 82) = v20;
    *(_BYTE *)(v23 + 84) = v22;
    *(_BYTE *)(v23 + 91) = v22;
    *(_WORD *)(v23 + 86) = v53;
    sub_56A78(*(char *)(361 * a1 + dword_192B18));
    v25 = v24;
    v54 = 4;
    sub_6D048(word_19988E, word_17F80D[14 * v24]);
    if ( v26 >= (uint8_t)byte_17FD50 )
      v54 = 20;
    if ( v26 >= (uint8_t)byte_17FD6E )
      LOBYTE(v54) = v54 | 0x40;
    v55 = word_17F81D[14 * v25] & v54;
    v27 = 75 / sub_6EE8E(word_19988E, v25, 1, 1, 1u, v55);
    v28 = dword_192864 + 11;
    *(_BYTE *)(dword_192864 + 96) = 15;
    *(_WORD *)(v28 + 88) = -1;
    *(_BYTE *)(v28 + 90) = 1;
    *(_BYTE *)(v28 + 92) = 0;
    *(_WORD *)(v28 + 82) = v25;
    *(_BYTE *)(v28 + 84) = v27;
    *(_BYTE *)(v28 + 91) = v27;
    v18 = 2;
    *(_WORD *)(v28 + 86) = v55;
  }
  if ( *(_BYTE *)(dword_192B18 + 361 * a1 + 352) )
  {
    v29 = 11 * v18;
    v30 = dword_192864;
    *(_WORD *)(dword_192864 + v29 + 82) = 38;
    *(_BYTE *)(v30 + v29 + 84) = 1;
    *(_BYTE *)(v30 + v29 + 85) = 15;
    *(_WORD *)(v30 + v29 + 86) = 0;
    *(_WORD *)(v30 + v29 + 88) = -1;
    *(_BYTE *)(v30 + v29 + 90) = 1;
    *(_BYTE *)(v30 + v29 + 92) = 0;
    ++v18;
    *(_BYTE *)(v30 + v29 + 91) = 1;
  }
  v31 = (char *)(dword_192B18 + 361 * a1);
  if ( v31[357] )
  {
    v32 = dword_197F98 + 3753 * *v31;
    v33 = 31;
    v34 = 5;
    if ( *(_BYTE *)(v32 + 362) == 3 )
    {
      v33 = 29;
      v34 = 2;
    }
    else if ( *(_BYTE *)(v32 + 310) == 3 )
    {
      v33 = 30;
      v34 = 3;
    }
    v35 = 0;
    do
    {
      v36 = dword_192864 + 11 * v18;
      *(_BYTE *)(v36 + 85) = 15;
      *(_WORD *)(v36 + 86) = 0;
      *(_BYTE *)(v36 + 92) = 0;
      *(_WORD *)(v36 + 88) = 1;
      *(_BYTE *)(v36 + 90) = 1;
      ++v35;
      *(_WORD *)(v36 + 82) = v33;
      *(_BYTE *)(v36 + 84) = v34;
      ++v18;
      *(_BYTE *)(v36 + 91) = v34;
    }
    while ( (int16_t)v35 < 2 );
  }
  v37 = 361 * a1;
  if ( *(_BYTE *)(v37 + dword_192B18 + 336) )
  {
    sub_56BFA(*(char *)(v37 + dword_192B18));
    v39 = v38;
    v57 = 0;
    sub_6D048(word_19988E, word_17F80D[14 * v38]);
    if ( v40 >= (uint8_t)byte_17FDC8 )
      v57 = 4096;
    if ( v40 >= (uint8_t)byte_17FDB9 )
      HIBYTE(v57) |= 8u;
    v41 = 300 / sub_6EE8E(word_19988E, v39, 1, 16, 5u, v57);
    v42 = v41;
    if ( (int16_t)v41 > 10 )
    {
      v56 = 2;
      v42 = (int16_t)v41 / 2;
    }
    else
    {
      v56 = 1;
    }
    HIBYTE(v57) |= 4u;
    v50 = 0;
    while ( v50 < v56 )
    {
      v43 = dword_192864 + 11 * v18;
      *(_WORD *)(v43 + 86) = v57;
      *(_BYTE *)(v43 + 85) = 15;
      *(_BYTE *)(v43 + 92) = 0;
      *(_WORD *)(v43 + 82) = v39;
      *(_BYTE *)(v43 + 84) = v42;
      if ( byte_17F80F[28 * v39] == 1 )
        *(_WORD *)(v43 + 88) = 125;
      else
        *(_WORD *)(v43 + 88) = 0;
      v44 = 11 * v18;
      v45 = dword_192864;
      ++v50;
      *(_BYTE *)(v44 + dword_192864 + 90) = 1;
      ++v18;
      *(_BYTE *)(v44 + v45 + 91) = v42;
    }
  }
  if ( v18 > 0 && *(_BYTE *)(3753 * word_19988E + dword_197F98 + 305) == 3 )
    sub_127712(dword_192864 + 76, 5u);
  v46 = dword_192864;
  *(_WORD *)(dword_192864 + 170) = 0;
  *(_BYTE *)(v46 + 172) = 1;
  *(_WORD *)(v46 + 173) = -1;
  *(_BYTE *)(v46 + 175) = 0;
  *(_WORD *)(v46 + 192) = 0;
  *(_WORD *)(v46 + 59) = 0;
  sub_36470(v46);
  v47 = dword_192864;
  *(_WORD *)(dword_192864 + 254) = 0;
  *(_WORD *)(v47 + 308) = 0;
  if ( a2 )
    sub_4B01A(a1);
  JUMPOUT(0x49A3B);
}
// 4B015: control flows out of bounds to 49A3B
// 4AA67: variable 'v3' is possibly undefined
// 4AB60: variable 'v10' is possibly undefined
// 4ABD4: variable 'v19' is possibly undefined
// 4ABFE: variable 'v21' is possibly undefined
// 4ACB9: variable 'v24' is possibly undefined
// 4ACE6: variable 'v26' is possibly undefined
// 4AE7E: variable 'v38' is possibly undefined
// 4AEAA: variable 'v40' is possibly undefined
// 17F6C1: using guessed type int16_t word_17F6C1;
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F81D: using guessed type int16_t word_17F81D[];
// 17FD41: using guessed type char byte_17FD41;
// 17FD50: using guessed type char byte_17FD50;
// 17FD5F: using guessed type char byte_17FD5F;
// 17FD6E: using guessed type char byte_17FD6E;
// 17FDB9: using guessed type char byte_17FDB9;
// 17FDC8: using guessed type char byte_17FDC8;
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 19988E: using guessed type int16_t word_19988E;


//----- (0004B01A) --------------------------------------------------------
int __fastcall sub_4B01A( int a1)
{
  int v1; // ecx
  int16_t v2; // si
  int v3; // eax
  int v4; // eax
  int result; // eax

  v1 = 17 * *(int16_t *)(361 * a1 + dword_192B18 + 2);
  v2 = 6 * *(uint8_t *)(v1 + dword_1930D4 + 8) + *(uint8_t *)(v1 + dword_1930D4 + 5);
  v3 = sub_127C27((int)aCmbtplntLbx, 6 * *(uint8_t *)(v1 + dword_1930D4 + 8) + 5, dword_193174);
  v4 = sub_12B79D(v3);
  sub_FE8BE(v4);
  dword_19285C = (int)sub_126B42((int)aCmbtplntLbx, v2, dword_192ED4);
  sub_FE8BE(dword_19285C);
  if ( *(_BYTE *)(v1 + dword_1930D4 + 5) )
  {
    dword_19288C = (int)sub_126B42(
                          (int)aCmbtplntLbx,
                          (int16_t)(6 * *(uint8_t *)(v1 + dword_1930D4 + 8)),
                          dword_192ED4);
    return sub_FE8BE(dword_19288C);
  }
  else
  {
    result = dword_19285C;
    dword_19288C = dword_19285C;
  }
  return result;
}
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 19285C: using guessed type int dword_19285C;
// 19288C: using guessed type int dword_19288C;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;


//----- (0004B0D3) --------------------------------------------------------
bool __fastcall sub_4B0D3( int a1, int a2)
{
  int v2; // esi
  int v3; // ecx

  v2 = 313 * a1;
  v3 = 0;
  if ( (uint16_t)sub_1276F0(v2 + dword_192864 + 76, a2) == 1 )
    return (uint16_t)sub_1276F0(v2 + dword_192864 + 178, a2) == 0;
  return v3;
}
// 192864: using guessed type int dword_192864;


//----- (0004B11E) --------------------------------------------------------
char __fastcall sub_4B11E( int a1, int a2, int a3)
{
  int16_t v3; // di
  int16_t i; // si
  int16_t v5; // ax

  v3 = a1;
  if ( a1 < 8 )
  {
    for ( i = 0; i < word_199998; ++i )
    {
      LOBYTE(a1) = dword_197F98;
      if ( *(_BYTE *)(3753 * i + dword_197F98 + 40) != 100 && i != v3 )
      {
        v5 = sub_1247A0(0xAu);
        LOBYTE(a1) = sub_F975C(-v5, v3, i, 6, a2, a3);
      }
    }
  }
  return a1;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0004B184) --------------------------------------------------------
void __fastcall sub_4B184( int a1, int a2, int a3)
{
  int v3; // edi
  int16_t v4; // si
  int16_t i; // bx
  uint8_t *v6; // eax
  int v7; // eax
  uint16_t v8; // dx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  uint8_t v14; // cl
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // ecx
  int v32; // eax
  int v33; // edx
  int v34; // edx
  int16_t v35; // bx
  int v36; // edx
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int16_t n; // bx
  _BYTE *v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // edx
  int v47; // eax
  int16_t v48; // si
  int16_t ii; // dx
  int16_t v50; // ax
  _WORD v53[8]; // [esp+8h] [ebp-54h]
  int v54; // [esp+18h] [ebp-44h]
  int v55; // [esp+1Ch] [ebp-40h]
  int v56; // [esp+20h] [ebp-3Ch]
  int v57; // [esp+24h] [ebp-38h]
  int v58; // [esp+28h] [ebp-34h]
  int v59; // [esp+2Ch] [ebp-30h]
  int v60; // [esp+30h] [ebp-2Ch]
  int v61; // [esp+34h] [ebp-28h]
  int v62; // [esp+38h] [ebp-24h]
  int v63; // [esp+3Ch] [ebp-20h]
  int v64; // [esp+40h] [ebp-1Ch]
  int k; // [esp+44h] [ebp-18h]
  int m; // [esp+48h] [ebp-14h]
  int v67; // [esp+4Ch] [ebp-10h]
  int j; // [esp+50h] [ebp-Ch]
  int v69; // [esp+54h] [ebp-8h]
  int v70; // [esp+58h] [ebp-4h]

  v64 = 0;
  v55 = 0;
  v3 = 0;
  v54 = 0;
  v63 = 0;
  if ( a3 >= 0 )
  {
    if ( a3 == 666 )
      v4 = -1;
    else
      v4 = word_1998AC;
  }
  else
  {
    v4 = word_19988E;
  }
  for ( i = 1; i < word_1998C0; ++i )
  {
    sub_4C9F6(i);
    v6 = (uint8_t *)(313 * i + dword_192864);
    if ( v6[49] || v6[36] != 5 && v6[32] == word_19988E )
    {
      v9 = dword_192864 + 313 * i;
      if ( (*(_BYTE *)(v9 + 36) != 5 || *(_BYTE *)(v9 + 75) == 2)
        && ((v10 = 313 * i, !*(_BYTE *)(v10 + dword_192864 + 176)) || *(uint8_t *)(v10 + dword_192864 + 32) == v4)
        && ((v11 = 313 * i + dword_192864, *(_BYTE *)(v11 + 32) < 8u) || *(_BYTE *)(v11 + 32) == *(_BYTE *)(v11 + 312)) )
      {
        if ( sub_4B0D3(i, 3)
          || (v18 = 313 * i, (int16_t)sub_35E0C(*(uint8_t *)(v18 + dword_192864 + 32)) > 0)
          || *(_BYTE *)(v18 + dword_192864 + 32) < 8u
          && ((v19 = 3753 * *(uint8_t *)(v18 + dword_192864 + 32) + dword_197F98, *(_BYTE *)(v19 + 283) == 3)
           || *(_BYTE *)(v19 + 2224)) )
        {
          v67 = 0;
          sub_35C3A(dword_192864 + 313 * i);
          do
          {
            v59 = 313 * i;
            v20 = v59 + dword_192864;
            v21 = (int16_t)v67++;
            *(_BYTE *)(v21 + v59 + dword_192864 + 178) = 0;
          }
          while ( (int16_t)v67 < 5 );
          *(_WORD *)(v20 + 192) = 0;
          v22 = *(int16_t *)(v20 + 30);
          if ( v22 != -1 )
            *(_WORD *)(v59 + dword_192864 + 194) = sub_58425(v22);
        }
        sub_4B9E1(i);
      }
      else
      {
        v13 = 313 * i;
        v12 = v13 + dword_192864;
        LOWORD(v13) = *(uint8_t *)(v13 + dword_192864 + 32);
        *(_BYTE *)(v12 + 36) = 5;
        if ( (_WORD)v13 == word_1998AC )
        {
          v14 = *(_BYTE *)(v12 + 37);
          LOWORD(v13) = v14;
          v63 += v13 + 1;
          v55 += 1 << (v14 + 1);
        }
        else
        {
          LOWORD(v13) = *(uint8_t *)(v12 + 37);
          v3 += v13 + 1;
          v54 += 1 << (*(_BYTE *)(v12 + 37) + 1);
        }
        v15 = 313 * i + dword_192864;
        if ( *(int16_t *)(v15 + 30) != -1 )
        {
          v16 = *(int16_t *)(v15 + 173);
          v58 = v16;
          if ( v16 > -1 )
          {
            if ( *(char *)(dword_1930DC + 59 * v16 + 55) <= 0 )
            {
              if ( *(_BYTE *)(dword_197F98 + 3753 * *(uint8_t *)(v15 + 32) + 458) == 3 )
              {
                v53[(int16_t)v64] = *(_WORD *)(v15 + 173);
                v17 = 129 * *(int16_t *)(v15 + 30);
                ++v64;
                *(_WORD *)(dword_197F9C + v17 + 116) = -1;
              }
              else
              {
                sub_941C6(v58, v3);
              }
            }
            else
            {
              sub_944A3(v58, v3);
            }
          }
        }
      }
    }
    else
    {
      if ( a1 == word_19999A )
        continue;
      v56 = 361 * word_199878;
      v7 = v56 + dword_192B18;
      if ( *(_BYTE *)(v56 + dword_192B18 + 350) )
      {
        v8 = 40;
LABEL_13:
        sub_145EA(word_199878, v8, v3);
        continue;
      }
      if ( *(_BYTE *)(v7 + 318) )
      {
        v8 = 8;
        goto LABEL_13;
      }
      if ( *(_BYTE *)(v7 + 351) )
      {
        v8 = 41;
        goto LABEL_13;
      }
    }
  }
  if ( word_1998AC < 8 )
  {
    if ( word_1998E2 )
      sub_4B11E(word_1998AC, a1, a2);
    if ( word_19988E < 8 )
    {
      v60 = word_1998AC;
      v23 = 3753 * word_19988E;
      v24 = dword_197F98;
      v25 = 2 * word_19988E + dword_197F98 + 3753 * word_1998AC;
      *(_WORD *)(v25 + 1775) += v55;
      *(_WORD *)(2 * v60 + v24 + v23 + 1775) += v54;
      if ( (int16_t)v3 <= 0 )
        v3 = 1;
      if ( a2 > 0 && byte_19B57C )
        sub_F975C(-10000, word_1998AC, word_19988E, 10, a1, a2);
      if ( byte_19B57C )
        sub_F975C(-15 * v3, word_1998AC, word_19988E, 11, a1, 0);
    }
  }
  for ( j = 1; (int16_t)j < word_1998C0; ++j )
  {
    v26 = 313 * (int16_t)j + dword_192864;
    if ( !*(_BYTE *)(v26 + 36) || *(_BYTE *)(v26 + 75) == 2 )
    {
      v27 = dword_192864 + 313 * (int16_t)j;
      if ( *(int16_t *)(v27 + 173) != -1 && *(uint8_t *)(v27 + 32) == v4 && *(int16_t *)(v27 + 30) != -1 )
      {
        if ( v4 == word_1998AC )
          v28 = (int16_t)v3;
        else
          v28 = (int16_t)v63;
        v29 = v28 / 2;
        if ( (int16_t)v29 < 1 )
          LOWORD(v29) = 1;
        sub_97C64(v4, *(_WORD *)(dword_192864 + 313 * (int16_t)j + 173), v29);
      }
    }
  }
  if ( (_WORD)v64 )
  {
    for ( k = 0; (int16_t)k < (int16_t)v64; ++k )
    {
      v70 = 0;
      v69 = 0;
      for ( m = 1; (int16_t)m < word_1998C0 && !(_WORD)v70; ++m )
      {
        v30 = dword_192864 + 313 * (int16_t)m;
        if ( *(_BYTE *)(v30 + 36) != 5 || *(_BYTE *)(v30 + 75) == 2 )
        {
          v31 = 313 * (int16_t)m + dword_192864;
          v61 = *(int16_t *)(v31 + 30);
          if ( v61 != -1 )
          {
            v32 = (int16_t)k;
            v33 = 59 * (int16_t)v53[v32];
            v62 = dword_1930DC;
            if ( *(char *)(dword_1930DC + v33 + 58) == *(uint8_t *)(v31 + 32) )
            {
              v34 = dword_197F9C + 129 * v61;
              v57 = dword_197F9C;
              if ( *(int16_t *)(v34 + 116) == -1 )
              {
                v35 = v53[(int16_t)k];
                *(_WORD *)(v34 + 116) = v35;
                v36 = v62 + 59 * v35;
                *(_WORD *)(v31 + 173) = v35;
                *(_WORD *)(v57 + 129 * *(int16_t *)(v36 + 53) + 116) = -1;
                v37 = 59 * (int16_t)v53[v32];
                LOWORD(v36) = *(_WORD *)(v31 + 30);
                v70 = 1;
                *(_WORD *)(v62 + v37 + 53) = v36;
              }
              v69 = 1;
            }
          }
        }
      }
      if ( ((_WORD)v70 || (_WORD)v69) && *(char *)(59 * (int16_t)v53[(int16_t)k] + dword_1930DC + 58) == v4 )
      {
        if ( v4 == word_1998AC )
          v38 = (int16_t)v3;
        else
          v38 = (int16_t)v63;
        v39 = v38 / 2;
        if ( (int16_t)v39 < 1 )
          LOWORD(v39) = 1;
        sub_97C64(v4, v53[(int16_t)k], v39);
      }
      if ( !(_WORD)v70 )
      {
        if ( (_WORD)v69 == 1 )
          sub_944A3(v53[(int16_t)k], v3);
        else
          sub_941C6(v53[(int16_t)k], v3);
      }
    }
  }
  for ( n = 1; n < word_1998C0; ++n )
  {
    if ( a1 == word_19999A && (v41 = (_BYTE *)(dword_192864 + 313 * n), v41[32] == 8) && v41[36] == 5 && v41[49] )
    {
      sub_646F9((uint8_t)v41[37]);
    }
    else
    {
      v42 = dword_192864 + 313 * n;
      if ( *(_BYTE *)(v42 + 36) != 5 || *(int16_t *)(v42 + 30) == -1 || *(_BYTE *)(v42 + 75) == 2 )
      {
        v44 = dword_192864 + 313 * n;
        if ( *(uint8_t *)(v44 + 32) == v4 && *(int16_t *)(v44 + 30) != -1 )
        {
          if ( v4 == word_1998AC )
            v45 = (int16_t)v3;
          else
            v45 = (int16_t)v63;
          v46 = v45 / 2;
          if ( (int16_t)(v45 / 2) < 1 )
            LOWORD(v46) = 1;
          v60 = 313 * n;
          v60 = 129 * *(int16_t *)(v60 + dword_192864 + 30);
          *(_WORD *)(v60 + dword_197F9C + 114) += v46;
        }
      }
      else
      {
        if ( *(_BYTE *)(v42 + 32) == 8 )
          sub_6474B(*(uint8_t *)(v42 + 37));
        v43 = *(int16_t *)(129 * *(int16_t *)(313 * n + dword_192864 + 30) + dword_197F9C + 116);
        if ( v43 > -1 )
          sub_944A3(v43, v3);
        sub_A163A(*(_WORD *)(313 * n + dword_192864 + 30), v3);
      }
    }
  }
  if ( word_199878 != -1 )
  {
    v47 = dword_192B18 + 361 * word_199878;
    if ( !*(_BYTE *)(v47 + 6) && !*(_BYTE *)(v47 + 10) )
    {
      v48 = 0;
      for ( ii = 0; ii < 49 && !v48; ++ii )
      {
        v50 = *(uint8_t *)(361 * word_199878 + dword_192B18 + ii + 310);
        v48 = v50;
      }
      if ( !v48 )
        sub_DCDAC((char *)(dword_192B18 + 361 * word_199878), 1);
    }
  }
}
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int dword_192B18;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199878: using guessed type int16_t word_199878;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998E2: using guessed type int16_t word_1998E2;
// 19999A: using guessed type int16_t word_19999A;
// 19B57C: using guessed type char byte_19B57C;


//----- (0004B9E1) --------------------------------------------------------
void __fastcall sub_4B9E1( int a1)
{
  int16_t v2; // si
  int v3; // edi
  int v4; // eax
  int16_t v5; // ax
  int v6; // eax
  int v7; // ebx
  char v8; // dl
  int v9; // ebx
  int v10; // eax
  char v11; // dl
  int v12; // edi
  int16_t v13; // ax
  int v14; // ebx
  int v15; // eax
  int v16; // eax
  int v17; // [esp+8h] [ebp-10h]
  int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]

  v2 = *(_WORD *)(313 * a1 + dword_192864 + 30);
  if ( v2 != -1 )
  {
    while ( 1 )
    {
      v3 = 313 * a1;
      v4 = v3 + dword_192864;
      if ( *(int16_t *)(v3 + dword_192864 + 59) >= 1 )
        break;
      ++*(_WORD *)(v4 + 256);
      sub_4528F(a1);
      *(_WORD *)(v3 + dword_192864 + 59) = v5;
    }
    if ( *(_WORD *)(v4 + 256) > *(_WORD *)(v4 + 202) )
      *(_WORD *)(v4 + 256) = *(_WORD *)(v4 + 202);
    *(_BYTE *)(dword_197F9C + 129 * v2 + 99) = *(_BYTE *)(313 * a1 + dword_192864 + 32);
    v6 = 0;
    do
    {
      v7 = 129 * v2 + dword_197F9C + 8 * (int16_t)v6;
      v8 = *(_BYTE *)(313 * a1 + dword_192864 + 11 * (int16_t)v6++ + 84);
      *(_BYTE *)(v7 + 31) = v8;
    }
    while ( (int16_t)v6 < 8 );
    v19 = 0;
    do
    {
      v17 = 313 * a1;
      v9 = v17 + dword_192864;
      v18 = 129 * v2;
      v10 = v18 + dword_197F9C;
      v11 = *(_BYTE *)((int16_t)v19 + v17 + dword_192864 + 178);
      v12 = v18 + dword_197F9C + (int16_t)v19++;
      *(_BYTE *)(v12 + 118) = v11;
    }
    while ( (int16_t)v19 < 5 );
    *(_WORD *)(v10 + 125) = *(_WORD *)(v9 + 192);
    v13 = sub_58425(v2) - *(_WORD *)(v9 + 194);
    v14 = v18 + dword_197F9C;
    *(_WORD *)(v14 + 123) = v13;
    v15 = v17 + dword_192864;
    *(_BYTE *)(v14 + 112) = 0;
    if ( *(int16_t *)(v15 + 254) > 0 )
      *(_BYTE *)(v14 + 110) = 100 - 100 * *(int16_t *)(v15 + 308) / *(int16_t *)(v15 + 254);
    v16 = dword_192864 + 313 * a1;
    if ( *(int16_t *)(v16 + 202) > 0 )
      *(_BYTE *)(dword_197F9C + 129 * v2 + 111) = 100 - 100 * *(int16_t *)(v16 + 256) / *(int16_t *)(v16 + 202);
  }
  JUMPOUT(0x494A1);
}
// 4BBD0: control flows out of bounds to 494A1
// 4BA37: variable 'v5' is possibly undefined
// 192864: using guessed type int dword_192864;
// 197F9C: using guessed type int dword_197F9C;


//----- (0004BBD5) --------------------------------------------------------
void __usercall sub_4BBD5( unsigned int a1, int a2)
{
  uint8_t v2; // al
  uint8_t v3; // dl
  char *v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // eax
  int v10; // edx
  int v11; // ebx
  int v12; // eax
  int v13; // edx
  int v14; // eax
  char v15; // dl
  int16_t v16; // si
  char v17; // dl
  int v18; // eax
  int v19; // ebx
  int v20; // ebx
  int v21; // edx
  int v22; // eax
  int16_t v23; // bx
  int v24; // eax
  unsigned int v25; // edx
  int16_t v26; // cx
  int16_t i; // bx
  _BYTE *v28; // eax
  int v29; // ebx
  int16_t v30; // ax
  int v31; // eax
  int v32; // esi
  int v33; // ebx
  int16_t v34; // ax
  int16_t v35; // bx
  int v36; // edx
  int v37; // eax
  int v38; // ebx
  int16_t v39; // ax
  int v40; // eax
  int v41; // eax
  int v42; // esi
  int v43; // ebx
  int16_t v44; // ax
  int v45; // eax
  int v46; // ebx
  int16_t v47; // ax
  int v48; // ecx
  int v49; // eax
  int v50; // eax
  int16_t v51; // ax
  int16_t v52; // di
  int v53; // esi
  int16_t v54; // ax
  int v55; // eax
  int v56; // ebx
  int v57; // eax
  int v58; // ebx
  int v59; // eax
  int v60; // eax
  int v61; // ebx
  int v62; // eax
  char v63; // al
  char v64; // al
  int v65; // ebx
  int v66; // eax
  int v67; // ecx
  char v68; // dl
  int v69; // edx
  int v70; // ebx
  int v71; // eax
  int v72; // ecx
  int16_t v74; // [esp+0h] [ebp-18h]
  int16_t v75; // [esp+8h] [ebp-10h]
  int16_t v76; // [esp+8h] [ebp-10h]
  int16_t v77; // [esp+8h] [ebp-10h]
  int16_t v78; // [esp+8h] [ebp-10h]
  int16_t v79; // [esp+Ch] [ebp-Ch]
  int16_t v80; // [esp+10h] [ebp-8h]
  int16_t v81; // [esp+14h] [ebp-4h]

  *(_BYTE *)(dword_192864 + 313 * word_1998C0 + 50) = sub_5680D(word_19988E);
  sub_5685F(word_19988E);
  v3 = v2;
  v4 = (char *)(dword_192864 + 313 * word_1998C0);
  v4[51] = v3;
  v79 = *(int16_t *)((char *)&word_17F642 + 15 * v3);
  if ( a1 < 7u )
  {
    if ( a1 == 6 )
    {
      strcpy(v4, (char *)off_180112);
      v5 = 313 * word_1998C0 + dword_192864;
      *(_WORD *)(v5 + 170) = word_1800FE;
      *(_WORD *)(v5 + 194) = word_1800FC
                           + word_1800FC * *(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v5 + 51)) / 100;
      LOWORD(v5) = word_1800F8;
      if ( *(_BYTE *)(dword_197F98 + 3753 * word_19988E + 368) == 3 )
        v5 = (5 * word_1800F8 - (__CFSHL__((5 * word_1800F8) >> 31, 2) + 4 * ((5 * word_1800F8) >> 31))) >> 2;
      a2 = (int16_t)v5 / 2;
      v6 = 313 * word_1998C0;
      v7 = dword_192864;
      *(_BYTE *)(dword_192864 + v6 + 37) = 2;
      v80 = v5 - (int16_t)v5 / 2;
      *(_WORD *)(v7 + v6 + 196) = 40;
    }
  }
  else if ( a1 <= 7u )
  {
    strcpy(v4, (char *)off_180136);
    v8 = 313 * word_1998C0 + dword_192864;
    *(_WORD *)(v8 + 170) = word_180122;
    *(_WORD *)(v8 + 194) = word_180120
                         + word_180120 * *(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v8 + 51)) / 100;
    LOWORD(v8) = word_18011C;
    if ( *(_BYTE *)(dword_197F98 + 3753 * word_19988E + 368) == 3 )
      v8 = (5 * word_18011C - (__CFSHL__((5 * word_18011C) >> 31, 2) + 4 * ((5 * word_18011C) >> 31))) >> 2;
    a2 = (int16_t)v8 / 2;
    v9 = 313 * word_1998C0;
    v10 = dword_192864;
    *(_BYTE *)(dword_192864 + v9 + 37) = 3;
    v80 = v8 - (int16_t)v8 / 2;
    *(_WORD *)(v10 + v9 + 196) = 41;
  }
  else if ( a1 == 8 )
  {
    strcpy(v4, (char *)off_18015A);
    v11 = 313 * word_1998C0 + dword_192864;
    *(_WORD *)(v11 + 170) = word_180146;
    *(_WORD *)(v11 + 194) = word_180144
                          + word_180144 * *(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v11 + 51)) / 100;
    LOWORD(v11) = word_180140;
    if ( *(_BYTE *)(dword_197F98 + 3753 * word_19988E + 368) == 3 )
      v11 = (5 * word_180140 - (__CFSHL__((5 * word_180140) >> 31, 2) + 4 * ((5 * word_180140) >> 31))) >> 2;
    a2 = (int16_t)v11 / 2;
    v12 = 313 * word_1998C0;
    v13 = dword_192864;
    *(_BYTE *)(dword_192864 + v12 + 37) = 4;
    v80 = v11 - (int16_t)v11 / 2;
    *(_WORD *)(v13 + v12 + 196) = 42;
  }
  v14 = dword_192864 + 313 * word_1998C0;
  *(_WORD *)(v14 + 30) = -1;
  v15 = word_19988E;
  *(_BYTE *)(v14 + 49) = 0;
  *(_BYTE *)(v14 + 32) = v15;
  v16 = word_19988E;
  *(_BYTE *)(v14 + 312) = v15;
  v17 = sub_5679E(v16);
  v18 = 313 * word_1998C0;
  v19 = dword_192864;
  *(_BYTE *)(dword_192864 + v18 + 36) = 0;
  *(_BYTE *)(v19 + v18 + 38) = v17;
  v20 = 0;
  do
  {
    v21 = 313 * word_1998C0 + dword_192864;
    v22 = (int16_t)v20;
    *(_BYTE *)(v21 + (int16_t)v20++ + 76) = 0;
    *(_BYTE *)(v21 + v22 + 178) = 0;
  }
  while ( (int16_t)v20 < 5 );
  v23 = 0;
  if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 361) == 3 )
  {
    sub_127712(v21 + 76, 0xEu);
    v23 = 1;
    *(_WORD *)(dword_192864 + 313 * word_1998C0 + 194) *= 3;
  }
  if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 335) == 3 )
  {
    ++v23;
    sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0x1Bu);
  }
  if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 440) == 3 && v23 < 8 )
  {
    ++v23;
    sub_127712(313 * word_1998C0 + dword_192864 + 76, 0x1Eu);
  }
  if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 360) == 3 && v23 < 8 )
  {
    ++v23;
    sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0xDu);
  }
  if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 391) == 3 && v23 < 8 )
  {
    ++v23;
    sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0x14u);
  }
  if ( *(_BYTE *)(3753 * v16 + dword_197F98 + 478) == 3 && v23 < 8 )
  {
    v24 = 313 * word_1998C0 + dword_192864;
    v25 = 38;
  }
  else if ( *(_BYTE *)(3753 * v16 + dword_197F98 + 390) == 3 && v23 < 8 )
  {
    v24 = dword_192864 + 313 * word_1998C0;
    v25 = 21;
  }
  else
  {
    if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 336) != 3 || v23 >= 8 )
    {
LABEL_40:
      if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 475) == 3 && v23 < 8 )
      {
        ++v23;
        sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0x25u);
      }
      if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 438) == 3 && v23 < 8 )
      {
        ++v23;
        sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0x1Du);
      }
      if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 305) == 3 && v23 < 8 )
      {
        ++v23;
        sub_127712(dword_192864 + 313 * word_1998C0 + 76, 5u);
      }
      if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 364) == 3 && v23 < 8 )
      {
        ++v23;
        sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0xFu);
      }
      if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 454) == 3 && v23 < 8 )
      {
        ++v23;
        sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0x20u);
      }
      if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 280) == 3 && v23 < 8 )
      {
        ++v23;
        sub_127712(313 * word_1998C0 + dword_192864 + 76, 1u);
      }
      if ( *(_BYTE *)(dword_197F98 + 3753 * v16 + 430) == 3 && v23 < 8 )
      {
        ++v23;
        sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0x19u);
      }
      if ( *(_BYTE *)(3753 * v16 + dword_197F98 + 469) == 3 && v23 < 8 )
        sub_127712(313 * word_1998C0 + dword_192864 + 76, 0x23u);
      v26 = word_1998C0;
      *(_WORD *)(dword_192864 + 313 * word_1998C0 + 170) += *(int16_t *)(dword_192864 + 313 * word_1998C0 + 170)
                                                          * v79
                                                          / 100;
      if ( sub_4B0D3(v26, 27) )
        *(_WORD *)(313 * word_1998C0 + dword_192864 + 170) *= 3;
      for ( i = 0; i < 8; ++i )
      {
        v28 = (_BYTE *)(11 * i + 313 * word_1998C0 + dword_192864 + 82);
        sub_127776(v28, 0xBu);
      }
      sub_568EB(word_19988E);
      v29 = dword_192864 + 313 * word_1998C0;
      *(_WORD *)(v29 + 82) = v30;
      *(_BYTE *)(v29 + 90) = 1;
      *(_WORD *)(v29 + 88) = -1;
      *(_BYTE *)(v29 + 85) = 15;
      *(_WORD *)(v29 + 86) = 2;
      v75 = a2 / 2 / sub_6EE8E(word_19988E, *(_WORD *)(v29 + 82), 1, 15, 0, 2);
      if ( v75 < 1 )
        v75 = 1;
      if ( v75 > 99 )
        LOBYTE(v75) = 99;
      v31 = dword_192864 + 313 * word_1998C0;
      *(_BYTE *)(v31 + 84) = v75;
      *(_BYTE *)(v31 + 91) = v75;
      sub_568EB(word_19988E);
      v32 = 1;
      v33 = dword_192864 + 313 * word_1998C0 + 11;
      *(_WORD *)(v33 + 82) = v34;
      *(_BYTE *)(v33 + 90) = 1;
      *(_WORD *)(v33 + 88) = -1;
      *(_BYTE *)(v33 + 85) = 15;
      *(_WORD *)(v33 + 86) = 0;
      v76 = ((int)(a2 - (__CFSHL__((uint64_t)a2 >> 32, 2) + 4 * ((uint64_t)a2 >> 32))) >> 2)
          / sub_6EE8E(word_19988E, *(_WORD *)(v33 + 82), 1, 15, 0, 0);
      if ( v76 < 1 )
        v76 = 1;
      if ( v76 > 198 )
        v76 = 198;
      while ( 1 )
      {
        v35 = v32 + 1;
        if ( v76 <= 99 )
          break;
        v36 = 313 * word_1998C0 + dword_192864;
        v37 = 11 * (int16_t)v32++;
        v38 = 11 * v35;
        *(_BYTE *)(v36 + v37 + 84) = 99;
        *(_BYTE *)(v36 + v37 + 91) = 99;
        sub_568EB(word_19988E);
        LOWORD(v36) = v39;
        v40 = dword_192864 + 313 * word_1998C0;
        *(_BYTE *)(v38 + v40 + 90) = 1;
        *(_WORD *)(v38 + v40 + 88) = -1;
        *(_BYTE *)(v38 + v40 + 85) = 15;
        v76 -= 99;
        *(_WORD *)(v38 + v40 + 86) = 0;
        *(_WORD *)(v38 + v40 + 82) = v36;
      }
      v41 = dword_192864 + 313 * word_1998C0 + 11 * (int16_t)v32;
      *(_BYTE *)(v41 + 84) = v76;
      *(_BYTE *)(v41 + 91) = v76;
      sub_56A78(word_19988E);
      v42 = v32 + 1;
      v43 = dword_192864 + 313 * word_1998C0 + 11 * v35;
      *(_WORD *)(v43 + 82) = v44;
      *(_BYTE *)(v43 + 90) = 1;
      *(_WORD *)(v43 + 88) = -1;
      *(_BYTE *)(v43 + 85) = 15;
      *(_WORD *)(v43 + 86) = 4;
      v77 = ((int)(a2 - (__CFSHL__((uint64_t)a2 >> 32, 2) + 4 * ((uint64_t)a2 >> 32))) >> 2)
          / sub_6EE8E(word_19988E, *(_WORD *)(v43 + 82), 1, 15, 0, 4);
      if ( v77 < 1 )
        v77 = 1;
      if ( v77 > 198 )
        v77 = 198;
      while ( v77 > 99 )
      {
        v45 = dword_192864 + 313 * word_1998C0;
        v46 = 11 * (int16_t)v42;
        *(_BYTE *)(v46 + v45 + 84) = 99;
        *(_BYTE *)(v46 + v45 + 91) = 99;
        sub_56A78(word_19988E);
        LOWORD(v46) = v47;
        v48 = 313 * word_1998C0 + dword_192864;
        v49 = 11 * (int16_t)(v42 + 1);
        *(_BYTE *)(v48 + v49 + 90) = 1;
        *(_WORD *)(v48 + v49 + 88) = -1;
        *(_BYTE *)(v48 + v49 + 85) = 15;
        v77 -= 99;
        *(_WORD *)(v48 + v49 + 86) = 4;
        ++v42;
        *(_WORD *)(v48 + v49 + 82) = v46;
      }
      v50 = 313 * word_1998C0 + dword_192864 + 11 * (int16_t)v42;
      *(_BYTE *)(v50 + 84) = v77;
      *(_BYTE *)(v50 + 91) = v77;
      sub_56BFA(word_19988E);
      v52 = v51;
      v53 = v42 + 1;
      v81 = 0;
      sub_6D048(word_19988E, word_17F80D[14 * v51]);
      if ( v54 >= (uint8_t)byte_17FDC8 )
        v81 = 4096;
      if ( v54 >= (uint8_t)byte_17FDB9 )
        HIBYTE(v81) |= 8u;
      v55 = 11 * (int16_t)v53 + dword_192864 + 313 * word_1998C0;
      *(_WORD *)(v55 + 82) = v52;
      v56 = 28 * *(int16_t *)(v55 + 82);
      *(_BYTE *)(v55 + 90) = 1;
      HIBYTE(v81) |= 4u;
      if ( byte_17F80F[v56] == 1 )
        *(_WORD *)(v55 + 88) = 20;
      else
        *(_WORD *)(v55 + 88) = 0;
      v57 = 313 * word_1998C0 + dword_192864 + 11 * (int16_t)v53;
      *(_BYTE *)(v57 + 85) = 15;
      *(_WORD *)(v57 + 86) = v81;
      v78 = v80 / sub_6EE8E(word_19988E, *(_WORD *)(v57 + 82), 1, 15, 0x14u, 0);
      if ( v78 < 1 )
        v78 = 1;
      if ( v78 > 90 )
        v78 = 90;
      while ( v78 > 30 && (int16_t)v53 < 8 )
      {
        v58 = 313 * word_1998C0 + dword_192864;
        v59 = 11 * (int16_t)v53;
        *(_BYTE *)(v58 + v59 + 84) = 30;
        ++v53;
        *(_BYTE *)(v58 + v59 + 91) = 30;
        v60 = v58 + 11 * (int16_t)v53;
        *(_WORD *)(v60 + 82) = v52;
        v61 = 28 * *(int16_t *)(v60 + 82);
        *(_BYTE *)(v60 + 90) = 1;
        v78 -= 30;
        if ( byte_17F80F[v61] == 1 )
          *(_WORD *)(v60 + 88) = 20;
        else
          *(_WORD *)(v60 + 88) = 0;
        v62 = dword_192864 + 313 * word_1998C0 + 11 * (int16_t)v53;
        *(_BYTE *)(v62 + 85) = 15;
        *(_WORD *)(v62 + 86) = v81;
      }
      if ( v78 >= 30 )
        v63 = 30;
      else
        v63 = v78;
      *(_BYTE *)(dword_192864 + 313 * word_1998C0 + 11 * (int16_t)v53 + 84) = v63;
      if ( v78 >= 30 )
        v64 = 30;
      else
        v64 = v78;
      *(_BYTE *)(313 * word_1998C0 + dword_192864 + 11 * (int16_t)v53 + 91) = v64;
      v65 = 0;
      do
      {
        v66 = dword_192864 + 313 * word_1998C0;
        v67 = (int16_t)v65++;
        *(_BYTE *)(v67 + v66 + 184) = 1;
      }
      while ( (int16_t)v65 < 8 );
      *(_BYTE *)(v66 + 172) = 1;
      *(_WORD *)(v66 + 173) = -1;
      v68 = byte_180022[36 * v74];
      *(_WORD *)(v66 + 59) = 0;
      *(_WORD *)(v66 + 192) = 0;
      *(_BYTE *)(v66 + 75) = 0;
      *(_BYTE *)(v66 + 175) = v68;
      sub_36470(v66);
      v69 = 313 * word_1998C0;
      if ( *(_BYTE *)(v69 + dword_192864 + 38) )
        *(_WORD *)(dword_192864 + 313 * word_1998C0 + 39) = sub_494A8(word_1998C0, v53);
      else
        *(_WORD *)(v69 + dword_192864 + 39) = 0;
      v70 = 0;
      do
      {
        v71 = dword_192864 + 313 * word_1998C0;
        v72 = v71 + 2 * (int16_t)v70++;
        *(_WORD *)(v72 + 41) = *(_WORD *)(v71 + 39);
      }
      while ( (int16_t)v70 < 4 );
      JUMPOUT(0x494A1);
    }
    v24 = dword_192864 + 313 * word_1998C0;
    v25 = 9;
  }
  ++v23;
  sub_127712(v24 + 76, v25);
  goto LABEL_40;
}
// 4C9F1: control flows out of bounds to 494A1
// 4BFAD: conditional instruction was optimized away because bx.2<2u
// 4BC10: variable 'v2' is possibly undefined
// 4C414: variable 'v30' is possibly undefined
// 4C4CB: variable 'v34' is possibly undefined
// 4C579: variable 'v39' is possibly undefined
// 4C60B: variable 'v44' is possibly undefined
// 4C6AF: variable 'v47' is possibly undefined
// 4C724: variable 'v51' is possibly undefined
// 4C752: variable 'v54' is possibly undefined
// 4C7FF: variable 'v80' is possibly undefined
// 4C94A: variable 'v74' is possibly undefined
// 17F642: using guessed type int16_t word_17F642;
// 17F80D: using guessed type int16_t word_17F80D[];
// 17FDB9: using guessed type char byte_17FDB9;
// 17FDC8: using guessed type char byte_17FDC8;
// 1800F8: using guessed type int16_t word_1800F8;
// 1800FC: using guessed type int16_t word_1800FC;
// 1800FE: using guessed type int16_t word_1800FE;
// 180112: using guessed type _UNKNOWN *off_180112;
// 18011C: using guessed type int16_t word_18011C;
// 180120: using guessed type int16_t word_180120;
// 180122: using guessed type int16_t word_180122;
// 180136: using guessed type _UNKNOWN *off_180136;
// 180140: using guessed type int16_t word_180140;
// 180144: using guessed type int16_t word_180144;
// 180146: using guessed type int16_t word_180146;
// 18015A: using guessed type _UNKNOWN *off_18015A;
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int dword_197F98;
// 19988E: using guessed type int16_t word_19988E;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0004C9F6) --------------------------------------------------------
int __fastcall sub_4C9F6( int a1)
{
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int16_t i; // cx
  int v7; // eax
  int result; // eax
  int16_t j; // cx

  v3 = 313 * a1;
  v4 = dword_192864;
  *(_BYTE *)(v3 + dword_192864 + 74) = -1;
  *(_BYTE *)(v3 + v4 + 311) = -1;
  *(_WORD *)(v3 + v4 + 69) = 0;
  *(_BYTE *)(v3 + v4 + 310) = 0;
  *(_BYTE *)(v3 + v4 + 72) = 0;
  *(_BYTE *)(v3 + v4 + 73) = 0;
  *(_WORD *)(v3 + v4 + 67) = 0;
  *(_BYTE *)(v3 + v4 + 66) = -1;
  *(_BYTE *)(v3 + v4 + 65) = 0;
  if ( sub_4B0D3(a1, 6) )
  {
    *(_BYTE *)(v3 + dword_192864 + 64) = 1;
  }
  else if ( sub_4B0D3(a1, 23) )
  {
    v5 = dword_192864;
    *(_BYTE *)(v3 + dword_192864 + 64) = 4;
    *(_BYTE *)(v3 + v5 + 65) = 10;
  }
  else
  {
    *(_BYTE *)(v3 + dword_192864 + 64) = 0;
  }
  if ( sub_4B0D3(a1, 16) )
  {
    for ( i = 0; i < 8; ++i )
    {
      v7 = dword_192864 + 313 * a1 + 11 * i;
      if ( !byte_17F80F[28 * *(int16_t *)(v7 + 82)] )
        *(_BYTE *)(v7 + 92) = 1;
    }
  }
  result = sub_4B0D3(a1, 12);
  if ( (_WORD)result )
  {
    for ( j = 0; j < 8; ++j )
    {
      result = 11 * j + dword_192864 + 313 * a1;
      if ( byte_17F80F[28 * *(int16_t *)(result + 82)] == 1 )
        *(_BYTE *)(result + 92) = 1;
    }
  }
  return result;
}
// 192864: using guessed type int dword_192864;


//----- (0004CB1E) --------------------------------------------------------
void __fastcall sub_4CB1E(int a1, int a2, int a3, int a4)
{
  int v5; // edx
  _BYTE *v6; // eax
  int v7; // esi
  int v8; // edx
  int v9; // eax
  int16_t v10; // si
  int v11; // edx
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // esi
  int v20; // ecx
  uint8_t *v21; // ecx
  int16_t v22; // dx
  int v23; // eax
  int v24; // edx
  int v25; // ecx

  if ( byte_199CB4 == 1 )
    sub_5794B(a1);
  v5 = 129 * (int16_t)a1;
  strcpy(byte_199A12, (char *)(v5 + dword_197F9C));
  v6 = (_BYTE *)(v5 + dword_197F9C);
  byte_199A32 = *(_BYTE *)(v5 + dword_197F9C + 99);
  LOBYTE(v5) = *(_BYTE *)(v5 + dword_197F9C + 93);
  byte_199A36 = 0;
  byte_199B4A = v5;
  LOBYTE(v5) = v6[18];
  word_199A30 = a1;
  byte_199A38 = v5;
  v7 = 0;
  byte_199A44 = v6[21];
  LOBYTE(v5) = v6[19];
  LOBYTE(v6) = v6[16];
  byte_199A43 = v5;
  byte_199A37 = (char)v6;
  do
  {
    v8 = 129 * (int16_t)a1 + dword_197F9C;
    v9 = (int16_t)v7;
    LOBYTE(a4) = *(_BYTE *)(v8 + (int16_t)v7 + 23);
    byte_199A5E[(int16_t)v7] = a4;
    LOBYTE(v8) = *(_BYTE *)(v8 + (int16_t)v7++ + 118);
    byte_199AC4[v9] = v8;
  }
  while ( (int16_t)v7 < 5 );
  v10 = 0;
  while ( 1 )
  {
    v11 = 129 * (int16_t)a1 + dword_197F9C;
    if ( *(_BYTE *)(v11 + 17) )
    {
      *(int16_t *)((char *)&word_199A64 + 11 * v10) = 0;
    }
    else
    {
      v12 = 11 * v10;
      v13 = 8 * v10 + v11;
      *(int16_t *)((char *)&word_199A64 + v12) = *(_WORD *)(v13 + 28);
      byte_199A66[v12] = *(_BYTE *)(v13 + 31);
      byte_199A67[v12] = *(_BYTE *)(v13 + 32);
      a4 = *(_WORD *)(v13 + 33);
      *(int16_t *)((char *)&word_199A68 + v12) = a4;
      *(int16_t *)((char *)&word_199A6A + v12) = *(uint8_t *)(v13 + 35);
      if ( byte_199A67[v12] == 16 )
        byte_199A67[11 * v10] = 15;
      v14 = 11 * v10;
      byte_199A6D[v14] = byte_199A66[v14];
      v15 = 28 * *(int16_t *)((char *)&word_199A64 + v14);
      byte_199A6C[v14] = 1;
      if ( byte_17F80F[v15] == 2 )
      {
        *(int16_t *)((char *)&word_199A6A + 11 * v10) = 0;
      }
      else if ( byte_17F80F[v15] != 1 )
      {
        *(int16_t *)((char *)&word_199A6A + 11 * v10) = (uint8_t)byte_17F810[v15];
      }
      if ( *(int16_t *)((char *)&word_199A64 + 11 * v10) == 33 )
      {
        a4 = (uint8_t)byte_199A66[11 * v10] * *(int16_t *)((char *)&word_199A6A + 11 * v10);
        *(int16_t *)((char *)&word_199A6A + 11 * v10) = a4;
      }
      byte_199A6E[11 * v10] = 0;
    }
    if ( ++v10 >= 8 )
    {
      v16 = 0;
      do
      {
        v17 = (int16_t)v16++;
        byte_199ACA[v17] = 1;
      }
      while ( (int16_t)v16 < 8 );
      v18 = dword_197F9C + 129 * (int16_t)a1;
      byte_199ABE = *(_BYTE *)(v18 + 113);
      word_199ABF = *(_WORD *)(v18 + 116);
      if ( *(_BYTE *)(v18 + 17) || *(char *)(v18 + 99) > 8 )
      {
        byte_199AC1 = -1;
      }
      else
      {
        byte_199AC1 = byte_180022[36 * (uint8_t)byte_199A37];
        if ( (uint16_t)sub_1276F0((int)byte_199A5E, 0x24u) == 1
          && !(uint16_t)sub_1276F0((int)byte_199AC4, 0x24u) )
        {
          byte_199AC1 *= 2;
        }
      }
      v19 = 129 * (int16_t)a1;
      word_199ABC = sub_58387(a1, (int16_t)a1, a1, a4);
      v20 = dword_197F9C;
      word_199AD4 = sub_58425(a1) - *(_WORD *)(v20 + v19 + 123);
      byte_199A45 = *(_BYTE *)(v19 + dword_197F9C + 22);
      word_199AD2 = *(_WORD *)(v19 + dword_197F9C + 125);
      if ( byte_199A37 == 5 )
        word_199AD6 = 43;
      else
        word_199AD6 = *(char *)(v19 + dword_197F9C + 92);
      byte_199A5D = 0;
      sub_36470((int)byte_199A12);
      v21 = (uint8_t *)(129 * (int16_t)a1 + dword_197F9C);
      word_199B46 = word_199B10 * (100 - v21[110]) / 100;
      word_199B12 = word_199ADC * (100 - v21[111]) / 100;
      word_199B14 = word_199ADE - v21[112];
      if ( byte_199A38 )
      {
        if ( (uint8_t)byte_199A37 >= 5u )
          v22 = (uint8_t)byte_199A37 + 1;
        else
          v22 = (uint8_t)byte_199A37;
        word_199A39 = (v22 + 1) * 5 * *(int16_t *)((char *)&word_17F6C1 + 59 * (uint8_t)byte_199A38);
        if ( (uint16_t)sub_1276F0((int)byte_199A5E, 0x14u)
          && !(uint16_t)sub_1276F0((int)byte_199AC4, 0x14u) )
        {
          word_199A39 = 3 * word_199A39 / 2;
        }
        word_199A39 = (word_199B10 + word_199A39 * word_199B46 - 1) / word_199B10;
      }
      else
      {
        word_199A39 = 0;
      }
      v23 = 0;
      do
      {
        v24 = (int16_t)v23++;
        word_199A3B[v24] = word_199A39;
      }
      while ( (int16_t)v23 < 4 );
      v25 = 129 * (int16_t)a1;
      word_199A4D = *(uint8_t *)(v25 + dword_197F9C + 96);
      if ( (uint16_t)sub_1276F0(v25 + dword_197F9C + 23, 2u) == 1
        && !(uint16_t)sub_1276F0(v25 + dword_197F9C + 118, 2u) )
      {
        word_199A4D += 5;
      }
      word_199A4D = (word_199B12 - 2 * word_199ADC / 3) * word_199A4D / (word_199ADC - 2 * word_199ADC / 3);
      if ( word_199A4D < 0 )
        word_199A4D = 0;
      if ( (uint8_t)byte_199A32 < 8u )
      {
        if ( *(_BYTE *)(3753 * (uint8_t)byte_199A32 + dword_197F98 + 2236) )
          word_199A4D += 4;
      }
      JUMPOUT(0x494A2);
    }
  }
}
// 4CFE2: control flows out of bounds to 494A2
// 17F6C1: using guessed type int16_t word_17F6C1;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199A30: using guessed type int16_t word_199A30;
// 199A32: using guessed type char byte_199A32;
// 199A36: using guessed type char byte_199A36;
// 199A37: using guessed type char byte_199A37;
// 199A38: using guessed type char byte_199A38;
// 199A39: using guessed type int16_t word_199A39;
// 199A3B: using guessed type int16_t word_199A3B[4];
// 199A43: using guessed type char byte_199A43;
// 199A44: using guessed type char byte_199A44;
// 199A45: using guessed type char byte_199A45;
// 199A4D: using guessed type int16_t word_199A4D;
// 199A5D: using guessed type char byte_199A5D;
// 199A64: using guessed type int16_t word_199A64;
// 199A68: using guessed type int16_t word_199A68;
// 199A6A: using guessed type int16_t word_199A6A;
// 199ABC: using guessed type int16_t word_199ABC;
// 199ABE: using guessed type char byte_199ABE;
// 199ABF: using guessed type int16_t word_199ABF;
// 199AC1: using guessed type char byte_199AC1;
// 199AD2: using guessed type int16_t word_199AD2;
// 199AD4: using guessed type int16_t word_199AD4;
// 199AD6: using guessed type int16_t word_199AD6;
// 199ADC: using guessed type int16_t word_199ADC;
// 199ADE: using guessed type int16_t word_199ADE;
// 199B10: using guessed type int16_t word_199B10;
// 199B12: using guessed type int16_t word_199B12;
// 199B14: using guessed type int16_t word_199B14;
// 199B46: using guessed type int16_t word_199B46;
// 199B4A: using guessed type char byte_199B4A;
// 199CB4: using guessed type char byte_199CB4;


//----- (0004CFE7) --------------------------------------------------------
void sub_4CFE7()
{
  int v0; // ebx
  int v1; // edi
  int i; // ecx
  int v3; // eax
  int v4; // ebx
  int v5; // ebx
  int v6; // [esp+4h] [ebp-4h]

  v0 = sub_35E0C(word_1998AC);
  v6 = v0;
  v1 = sub_35E0C(word_19988E);
  if ( word_1998AC < 8 && *(_BYTE *)(dword_197F98 + 3753 * word_1998AC + 2224) )
    v6 = v0 + 10;
  if ( word_19988E < 8 && *(_BYTE *)(3753 * word_19988E + dword_197F98 + 2224) )
    v1 += 10;
  for ( i = 0; (int16_t)i < word_1998C0; ++i )
  {
    v3 = 313 * (int16_t)i + dword_192864;
    v4 = 0;
    if ( !*(_BYTE *)(v3 + 36) && !*(_BYTE *)(v3 + 176) && !sub_3E563(i) )
    {
      if ( sub_4B0D3(i, 3) )
        v4 = 20;
      if ( *(uint8_t *)(dword_192864 + 313 * (int16_t)i + 32) == word_1998AC )
        v5 = v6 + v4;
      else
        v5 = v1 + v4;
      if ( (int16_t)v5 > 0 )
        sub_35821(i, v5, v5, i);
    }
  }
  JUMPOUT(0x494A1);
}
// 4D0F5: control flows out of bounds to 494A1
// 192864: using guessed type int dword_192864;
// 197F98: using guessed type int dword_197F98;
// 19988E: using guessed type int16_t word_19988E;
// 1998AC: using guessed type int16_t word_1998AC;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0004D10E) --------------------------------------------------------
void __fastcall sub_4D10E( int a1, int a2)
{
  switch ( a2 )
  {
    case 0:
      sub_55161(a1);
      break;
    case 1:
      sub_5542C(a1);
      break;
    case 2:
      sub_55738(a1);
      break;
    case 3:
      sub_55B12(a1);
      break;
    case 4:
      sub_55F67(a1);
      break;
    default:
      JUMPOUT(0x4CB1D);
  }
}
// 4D11B: control flows out of bounds to 4CB1D


//----- (0004D141) --------------------------------------------------------
void sub_4D141()
{
  int16_t i; // bx
  int16_t j; // cx

  if ( word_199182 < 1 )
    word_199182 = 1;
  for ( i = 0; i < 5; ++i )
  {
    for ( j = 0; j < word_19917A[i]; ++j )
    {
      sub_4D10E(word_1998C0, i);
      ++word_1998C0;
    }
  }
  sub_4D18E();
}
// 19917A: using guessed type int16_t word_19917A[4];
// 199182: using guessed type int16_t word_199182;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0004D18E) --------------------------------------------------------
void sub_4D18E()
{
  char *v0; // edi
  char *v1; // esi
  int v2; // ebx
  int16_t v3; // ax
  int16_t v4; // ax
  int16_t v5; // ax
  int16_t v6; // di
  int v7; // ebx
  int v8; // edx
  int v9; // eax
  int16_t v10; // bx
  _BYTE *v11; // eax
  int v12; // ebx
  int v13; // ebx
  int16_t v14; // si
  int16_t v15; // bx
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int16_t v21; // si
  int v22; // ebx
  int16_t v23; // bx
  int v24; // edx
  int v25; // eax
  int v26; // eax
  int v27; // edx
  int v28; // eax
  int16_t v29; // si
  int v30; // ebx
  int v31; // eax
  int v32; // esi
  int v33; // eax
  int v34; // ebx
  char v35; // dl
  int v36; // eax
  int v37; // edi
  int16_t v38; // [esp+4h] [ebp-4h]
  int16_t v39; // [esp+4h] [ebp-4h]
  int16_t v40; // [esp+4h] [ebp-4h]
  int16_t v41; // [esp+4h] [ebp-4h]

  v0 = (char *)(313 * word_1998C0 + dword_192864);
  v0[50] = 5;
  v1 = (char *)off_18015A;
  v0[51] = 6;
  strcpy(v0, v1);
  v2 = 313 * word_1998C0 + dword_192864;
  v3 = word_180146 + word_180146 * *(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v2 + 51)) / 100;
  *(_WORD *)(v2 + 170) = v3;
  *(_WORD *)(v2 + 170) = 3 * v3;
  v4 = word_180144 + word_180144 * *(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v2 + 51)) / 100;
  *(_WORD *)(v2 + 194) = v4;
  *(_WORD *)(v2 + 194) = 3 * v4;
  v5 = (int16_t)((5 * word_180140 - (__CFSHL__((5 * word_180140) >> 31, 2) + 4 * ((5 * word_180140) >> 31))) >> 2) / 2;
  *(_BYTE *)(v2 + 37) = 4;
  *(_WORD *)(v2 + 196) = 5;
  *(_WORD *)(v2 + 30) = -1;
  *(_BYTE *)(v2 + 49) = 0;
  *(_BYTE *)(v2 + 38) = 0;
  *(_BYTE *)(v2 + 36) = 0;
  v6 = v5;
  LOBYTE(v5) = word_19988E;
  *(_BYTE *)(v2 + 32) = word_19988E;
  *(_BYTE *)(v2 + 312) = v5;
  v7 = 0;
  do
  {
    v8 = 313 * word_1998C0 + dword_192864;
    v9 = (int16_t)v7;
    *(_BYTE *)(v8 + (int16_t)v7++ + 76) = 0;
    *(_BYTE *)(v8 + v9 + 178) = 0;
  }
  while ( (int16_t)v7 < 5 );
  sub_127712(v8 + 76, 5u);
  sub_127712(313 * word_1998C0 + dword_192864 + 76, 7u);
  sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0x18u);
  sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0x1Au);
  sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0xEu);
  sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0x1Bu);
  sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0x1Du);
  v10 = 0;
  sub_127712(dword_192864 + 313 * word_1998C0 + 76, 0x20u);
  do
  {
    v11 = (_BYTE *)(11 * v10++ + dword_192864 + 313 * word_1998C0 + 82);
    sub_127776(v11, 0xBu);
  }
  while ( v10 < 8 );
  v12 = 313 * word_1998C0 + dword_192864;
  *(_WORD *)(v12 + 82) = 11;
  *(_BYTE *)(v12 + 90) = 1;
  *(_WORD *)(v12 + 88) = -1;
  *(_BYTE *)(v12 + 85) = 15;
  *(_WORD *)(v12 + 86) = 2;
  v38 = v6 / 2 / sub_6EE8E(word_19988E, *(_WORD *)(v12 + 82), 1, 1, 0, 2);
  if ( v38 > 99 )
    LOBYTE(v38) = 99;
  v13 = 313 * word_1998C0 + dword_192864;
  *(_BYTE *)(v13 + 84) = v38;
  v14 = 1;
  *(_BYTE *)(v13 + 91) = v38;
  v13 += 11;
  *(_WORD *)(v13 + 82) = 4;
  *(_BYTE *)(v13 + 90) = 1;
  *(_WORD *)(v13 + 88) = -1;
  *(_BYTE *)(v13 + 85) = 15;
  *(_WORD *)(v13 + 86) = 0;
  v39 = ((int)(v6 - (__CFSHL__((uint64_t)v6 >> 32, 2) + 4 * ((uint64_t)v6 >> 32))) >> 2)
      / sub_6EE8E(word_19988E, *(_WORD *)(v13 + 82), 1, 1, 0, 0);
  if ( v39 > 198 )
    v39 = 198;
  while ( 1 )
  {
    v15 = v14 + 1;
    if ( v39 <= 99 )
      break;
    v16 = 313 * word_1998C0 + dword_192864;
    v17 = 11 * v14;
    *(_BYTE *)(v16 + v17 + 84) = 99;
    *(_BYTE *)(v16 + v17 + 91) = 99;
    v18 = 11 * v15;
    *(_WORD *)(v16 + v18 + 82) = 4;
    *(_BYTE *)(v16 + v18 + 90) = 1;
    *(_WORD *)(v16 + v18 + 88) = -1;
    v39 -= 99;
    *(_BYTE *)(v16 + v18 + 85) = 15;
    ++v14;
    *(_WORD *)(v16 + v18 + 86) = 0;
  }
  v19 = 313 * word_1998C0 + dword_192864;
  v20 = 11 * v14;
  v21 = v14 + 1;
  *(_BYTE *)(v19 + v20 + 84) = v39;
  *(_BYTE *)(v19 + v20 + 91) = v39;
  v22 = v19 + 11 * v15;
  *(_WORD *)(v22 + 82) = 4;
  *(_BYTE *)(v22 + 90) = 1;
  *(_WORD *)(v22 + 88) = -1;
  *(_BYTE *)(v22 + 85) = 15;
  *(_WORD *)(v22 + 86) = 4;
  v40 = ((int)(v6 - (__CFSHL__((uint64_t)v6 >> 32, 2) + 4 * ((uint64_t)v6 >> 32))) >> 2)
      / sub_6EE8E(word_19988E, *(_WORD *)(v22 + 82), 1, 1, 0, 4);
  if ( v40 > 198 )
    v40 = 198;
  while ( 1 )
  {
    v23 = v21 + 1;
    if ( v40 <= 99 )
      break;
    v24 = 313 * word_1998C0 + dword_192864;
    v25 = 11 * v21;
    *(_BYTE *)(v24 + v25 + 84) = 99;
    *(_BYTE *)(v24 + v25 + 91) = 99;
    v26 = 11 * v23;
    *(_WORD *)(v24 + v26 + 82) = 4;
    *(_BYTE *)(v24 + v26 + 90) = 1;
    *(_WORD *)(v24 + v26 + 88) = -1;
    v40 -= 99;
    *(_BYTE *)(v24 + v26 + 85) = 15;
    ++v21;
    *(_WORD *)(v24 + v26 + 86) = 4;
  }
  v27 = 313 * word_1998C0 + dword_192864;
  v28 = 11 * v21;
  v29 = v21 + 1;
  *(_BYTE *)(v27 + v28 + 84) = v40;
  *(_BYTE *)(v27 + v28 + 91) = v40;
  v30 = v27 + 11 * v23;
  *(_WORD *)(v30 + 82) = 4;
  *(_BYTE *)(v30 + 90) = 1;
  *(_WORD *)(v30 + 88) = -1;
  *(_BYTE *)(v30 + 85) = 15;
  *(_WORD *)(v30 + 86) = 2;
  v41 = v6 / 2 / sub_6EE8E(word_19988E, *(_WORD *)(v30 + 82), 1, 1, 0, 2);
  if ( v41 > 99 )
    LOBYTE(v41) = 99;
  v31 = 313 * word_1998C0 + dword_192864 + 11 * v29;
  *(_BYTE *)(v31 + 84) = v41;
  v32 = 0;
  *(_BYTE *)(v31 + 91) = v41;
  do
  {
    v33 = dword_192864 + 313 * word_1998C0;
    v34 = (int16_t)v32++;
    *(_BYTE *)(v34 + v33 + 184) = 1;
  }
  while ( (int16_t)v32 < 8 );
  *(_BYTE *)(v33 + 172) = 3;
  *(_WORD *)(v33 + 173) = 66;
  *(_WORD *)(v33 + 59) = 0;
  *(_WORD *)(v33 + 192) = 0;
  v35 = byte_180142;
  *(_BYTE *)(v33 + 75) = 0;
  *(_BYTE *)(v33 + 175) = v35;
  sub_36470(v33);
  *(_WORD *)(dword_192864 + 313 * word_1998C0 + 39) = 0;
  v36 = 0;
  do
  {
    v37 = (int16_t)v36++;
    *(_WORD *)(313 * word_1998C0 + dword_192864 + 2 * v37 + 41) = *(_WORD *)(313 * word_1998C0 + dword_192864 + 39);
  }
  while ( (int16_t)v36 < 4 );
  ++word_1998C0;
  JUMPOUT(0x494A1);
}
// 4D771: control flows out of bounds to 494A1
// 17F642: using guessed type int16_t word_17F642;
// 180140: using guessed type int16_t word_180140;
// 180142: using guessed type char byte_180142;
// 180144: using guessed type int16_t word_180144;
// 180146: using guessed type int16_t word_180146;
// 18015A: using guessed type _UNKNOWN *off_18015A;
// 192864: using guessed type int dword_192864;
// 19988E: using guessed type int16_t word_19988E;
// 1998C0: using guessed type int16_t word_1998C0;


//----- (0004D78E) --------------------------------------------------------
int __usercall sub_4D78E( int a1)
{
  int16_t i; // di
  int v2; // ebx
  char v3; // dl
  int v4; // edx
  int v5; // eax
  int v6; // edx
  int result; // eax
  int16_t v8; // dx
  int v9; // ecx
  int16_t v10; // [esp+14h] [ebp-4h]

  for ( i = 0; i < word_199998; ++i )
  {
    v10 = 0;
    while ( v10 < word_199998 )
    {
      v2 = dword_197F98 + 3753 * i;
      v3 = byte_180ED4[28 * *(uint8_t *)(v2 + 37) + 2 * *(uint8_t *)(3753 * v10 + dword_197F98 + 37)];
      *(_BYTE *)(v2 + v10 + 1575) = 0;
      *(_BYTE *)(v2 + v10 + 1583) = 0;
      *(_BYTE *)(v2 + v10 + 1591) = 0;
      *(_BYTE *)(v2 + v10 + 1559) = v3;
      *(_BYTE *)(v2 + v10 + 1567) = v3;
      v4 = v10;
      *(_BYTE *)(v2 + v10 + 1551) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1631) = 0;
      *(_BYTE *)(v2 + v10 + 1615) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1647) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1663) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1679) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1695) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1711) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1727) = 0;
      *(_BYTE *)(v2 + v10 + 1551) = 0;
      *(_BYTE *)(v2 + v10 + 1743) = 0;
      *(_BYTE *)(v2 + v10 + 1751) = 0;
      *(_BYTE *)(v2 + v10 + 1823) = 0;
      *(_BYTE *)(v2 + v10 + 2030) = 0;
      *(_BYTE *)(v2 + v10 + 2038) = -1;
      *(_BYTE *)(v2 + v10 + 2191) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1996) = 0;
      *(_BYTE *)(v2 + v10 + 2012) = 0;
      *(_BYTE *)(v2 + v10 + 2020) = -1;
      *(_BYTE *)(v2 + v10 + 1839) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1599) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1775) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1791) = 0;
      *(_BYTE *)(v2 + v10 + 1807) = 0;
      *(_BYTE *)(v2 + v10 + 1815) = 0;
      *(_BYTE *)(v2 + v10 + 1831) = 0;
      *(_BYTE *)(v2 + v10 + 1871) = 0;
      *(_BYTE *)(v2 + v10 + 1623) = 0;
      *(_BYTE *)(v2 + v10 + 1879) = 0;
      *(_BYTE *)(v2 + v10 + 1887) = 0;
      *(_BYTE *)(v2 + v10 + 1895) = 0;
      *(_BYTE *)(v2 + v10 + 1903) = 0;
      *(_WORD *)(v2 + 2 * v10 + 1911) = 0;
      *(_BYTE *)(v2 + v10 + 1927) = 0;
      *(_WORD *)(v2 + 2 * v10++ + 2103) = -1;
      *(_BYTE *)(v2 + v4 + 2199) = -1;
      *(_BYTE *)(v2 + 2070) = 0;
      sub_27507(i, v4);
    }
    v5 = 3753 * i;
    v6 = dword_197F98;
    *(_BYTE *)(dword_197F98 + v5 + 3697) = -1;
    *(_BYTE *)(v6 + v5 + 1995) = -1;
    *(_WORD *)(v6 + v5 + 1991) = -1;
    *(_BYTE *)(v6 + v5 + 1993) = 0;
    *(_WORD *)(v6 + v5 + 3699) = 0;
  }
  for ( result = 0; (int16_t)result < word_199998; ++result )
  {
    if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)result + 40) != 100 )
    {
      v8 = result;
      while ( ++v8 < word_199998 )
      {
        if ( *(_BYTE *)(dword_197F98 + 3753 * v8 + 40) == 100 )
        {
          switch ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)result + 39) )
          {
            case 0:
              a1 = -3;
              break;
            case 1:
              a1 = -2;
              break;
            case 2:
            case 3:
              a1 = 0;
              break;
            case 4:
              a1 = 2;
              break;
            case 5:
              a1 = 5;
              break;
            default:
              break;
          }
          v9 = dword_197F98;
          *(_WORD *)(2 * v8 + dword_197F98 + 3753 * (int16_t)result + 2087) = a1;
          *(_WORD *)(3753 * v8 + v9 + 2 * (int16_t)result + 2087) = a1;
        }
      }
    }
  }
  word_19A0E2 = 0;
  word_19A0E0 = -1;
  word_19A0E4 = 25;
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19A0E0: using guessed type int16_t word_19A0E0;
// 19A0E2: using guessed type int16_t word_19A0E2;
// 19A0E4: using guessed type int16_t word_19A0E4;


//----- (0004DAB2) --------------------------------------------------------
void sub_4DAB2()
{
  int16_t i; // dx
  int16_t j; // bx
  int v2; // esi
  int v3; // eax
  char v4; // cl
  int16_t k; // dx
  int v6; // eax
  int16_t m; // dx
  int16_t n; // bx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int16_t ii; // bx
  int v14; // eax
  int16_t jj; // bx
  int16_t kk; // dx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int16_t mm; // si
  int16_t nn; // bx
  int v22; // eax
  int v23; // [esp+0h] [ebp-8h]

  sub_52602();
  sub_277CF();
  sub_1FEF5();
  for ( i = 0; i < word_199998; ++i )
  {
    for ( j = 0; j < word_199998; ++j )
    {
      v2 = 3753 * i + dword_197F98;
      v3 = j;
      v4 = *(_BYTE *)(v2 + j + 1575);
      *(_BYTE *)(v2 + v3 + 1871) = v4;
    }
  }
  for ( k = 0; k < word_199998; ++k )
  {
    v6 = dword_197F98 + 3753 * k;
    if ( *(int16_t *)(v6 + 176) < 0 )
      ++*(_WORD *)(v6 + 2028);
    else
      *(_WORD *)(v6 + 2028) = 0;
  }
  for ( m = 0; m < word_199998; ++m )
  {
    for ( n = 0; n < word_199998; ++n )
    {
      v9 = 3753 * m + dword_197F98 + 2 * n;
      *(_WORD *)(v9 + 1679) += 10;
      *(_WORD *)(v9 + 1695) += 10;
      *(_WORD *)(v9 + 1711) += 10;
      *(_WORD *)(v9 + 1727) += 10;
      if ( *(int16_t *)(v9 + 1679) > 0 )
        *(_WORD *)(v9 + 1679) = 0;
      v10 = 3753 * m + dword_197F98 + 2 * n;
      if ( *(int16_t *)(v10 + 1695) > 0 )
        *(_WORD *)(v10 + 1695) = 0;
      v11 = 3753 * m + dword_197F98 + 2 * n;
      if ( *(int16_t *)(v11 + 1711) > 0 )
        *(_WORD *)(v11 + 1711) = 0;
      v12 = 2 * n + dword_197F98 + 3753 * m;
      if ( *(int16_t *)(v12 + 1727) > 0 )
        *(_WORD *)(v12 + 1727) = 0;
    }
  }
  for ( ii = 0; ii < word_199998; ++ii )
  {
    v14 = 3753 * ii + dword_197F98;
    if ( *(_BYTE *)(v14 + 2070) )
      --*(_BYTE *)(v14 + 2070);
  }
  for ( jj = 0; jj < word_199998; ++jj )
  {
    for ( kk = 0; kk < word_199998; ++kk )
    {
      v17 = dword_197F98 + 3753 * jj;
      if ( *(_BYTE *)(v17 + 40) != 100
        && *(_BYTE *)(3753 * kk + dword_197F98 + 40) == 100
        && *(_BYTE *)(kk + v17 + 1412) )
      {
        v18 = 2 * kk + v17;
        if ( *(int16_t *)(v18 + 2071) < 250 )
          ++*(_WORD *)(v18 + 2071);
        v19 = kk + 3753 * jj + dword_197F98;
        if ( *(_BYTE *)(v19 + 2191) < 0xFAu )
          ++*(_BYTE *)(v19 + 2191);
      }
    }
  }
  for ( mm = 0; mm < word_199998; ++mm )
  {
    for ( nn = 0; nn < word_199998; ++nn )
    {
      v23 = dword_197F98;
      v22 = nn + 3753 * mm + dword_197F98;
      if ( *(_BYTE *)(v22 + 1575) == 3 && 3753 * mm + dword_197F98 == -1839 )
      {
        *(_BYTE *)(v22 + 1575) = 0;
        *(_BYTE *)(mm + v23 + 3753 * nn + 1575) = 0;
        sub_EF81F();
      }
    }
  }
  JUMPOUT(0x4DAAB);
}
// 4DD66: control flows out of bounds to 4DAAB
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0004DD6B) --------------------------------------------------------
void sub_4DD6B()
{
  int i; // edi
  int v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // edx
  int16_t v5; // ax
  int v6; // eax
  int v7; // edx
  int16_t v8; // ax
  int v9; // eax
  int v10; // edx
  int16_t v11; // ax
  int16_t v12; // ax
  int v13; // edx
  int16_t v14; // ax
  int v15; // edx
  int16_t v16; // ax
  int v17; // eax
  int v18; // eax
  int j; // edi
  int v20; // esi
  int v21; // eax
  int v22; // eax
  int v23; // edi
  int v24; // esi
  int v25; // ebx
  signed int v26; // ecx
  int64_t v27; // rax
  int v28; // edx
  int v29; // eax
  int v30; // ecx
  int v31; // edx
  int v32; // eax
  int v33; // eax
  int v34; // edx
  int v35; // eax
  int v36; // edi
  int v37; // eax
  int v38; // esi
  int v39; // edx
  int k; // edi
  int v41; // esi
  int v42; // edx
  int v43; // eax
  int v44; // eax
  int v45; // edi
  int v46; // edx
  int v47; // esi
  int v48; // eax
  int v49; // ebx
  int v50; // [esp+8h] [ebp-34h]
  int v51; // [esp+Ch] [ebp-30h]
  int v52; // [esp+10h] [ebp-2Ch]
  int v53; // [esp+14h] [ebp-28h]
  int v54; // [esp+18h] [ebp-24h] BYREF
  unsigned int v55; // [esp+1Ch] [ebp-20h]
  int v56; // [esp+20h] [ebp-1Ch] BYREF
  int v57; // [esp+24h] [ebp-18h] BYREF
  int v58; // [esp+28h] [ebp-14h]
  int v59; // [esp+2Ch] [ebp-10h]
  int v60; // [esp+30h] [ebp-Ch]
  int v61; // [esp+34h] [ebp-8h]
  int v62; // [esp+38h] [ebp-4h]

  for ( i = 0; i < word_199998; ++i )
  {
    v1 = i + 1;
    v61 = 3753 * i;
    v50 = 2 * (i + 1);
    v62 = 3753 * (i + 1);
    while ( v1 < word_199998 )
    {
      if ( *(_BYTE *)(dword_197F98 + v61 + 40) != 100 || *(_BYTE *)(dword_197F98 + v62 + 40) != 100 )
      {
        if ( sub_1247A0(2u) == 1 )
        {
          v2 = v1 + v61 + dword_197F98;
          if ( *(char *)(v2 + 1559) < -50 && *(char *)(v2 + 1839) > 0 )
            sub_4E3B5(1, i, v1, 0, 0, 0);
        }
        v3 = v1 + v61 + dword_197F98;
        if ( *(_BYTE *)(v3 + 1575) == 1 )
        {
          v4 = 100 - *(char *)(v3 + 1559);
          if ( (int)sub_1247A0(0x64u) <= v4 )
          {
            v5 = sub_1247A0(3u);
            sub_4E3B5(v5, i, v1, 0, 0, 0);
          }
        }
        v6 = v1 + v61 + dword_197F98;
        if ( *(_BYTE *)(v6 + 1583) == 1 )
        {
          v7 = 100 - *(char *)(v6 + 1559);
          if ( (int)sub_1247A0(0x64u) <= v7 )
          {
            v8 = sub_1247A0(3u);
            sub_4E3B5(v8, i, v1, 12, 0, 0);
          }
        }
        v9 = v1 + v61 + dword_197F98;
        if ( *(_BYTE *)(v9 + 1591) == 1 )
        {
          v10 = 100 - *(char *)(v9 + 1559);
          if ( (int)sub_1247A0(0x64u) <= v10 )
          {
            v11 = sub_1247A0(3u);
            sub_4E3B5(v11, i, v1, 13, 0, 0);
          }
        }
        if ( *(_BYTE *)(v1 + v61 + dword_197F98 + 1575) == 2 )
        {
          v12 = sub_1247A0(5u);
          sub_4E3B5(v12, i, v1, 0, 0, 0);
        }
        if ( *(_WORD *)(v61 + dword_197F98 + v50 + 1599) == 1 )
        {
          v13 = 100 - *(char *)(v61 + dword_197F98 + v1 + 1559);
          if ( (int)sub_1247A0(0x64u) <= v13 )
          {
            v14 = sub_1247A0(3u);
            sub_4E3B5(v14, i, v1, 14, 0, 0);
          }
        }
        if ( *(_WORD *)(v61 + dword_197F98 + v50 + 1599) == 2 )
        {
          v15 = 100 - *(char *)(v61 + dword_197F98 + v1 + 1559);
          if ( (int)sub_1247A0(0x64u) <= v15 )
          {
            v16 = sub_1247A0(8u);
            sub_4E3B5(v16, i, v1, 14, 0, 0);
          }
        }
        v17 = v1 + v61 + dword_197F98;
        if ( *(char *)(v17 + 1559) > 100 )
          *(_BYTE *)(v17 + 1559) = 100;
        v18 = i + v62 + dword_197F98;
        if ( *(char *)(v18 + 1559) > 100 )
          *(_BYTE *)(v18 + 1559) = 100;
      }
      v50 += 2;
      v62 += 3753;
      ++v1;
    }
  }
  for ( j = 0; j < word_199998; ++j )
  {
    v20 = 0;
    v51 = 0;
    v58 = 3753 * j;
    while ( v20 < word_199998 )
    {
      if ( *(_BYTE *)(dword_197F98 + v58 + 40) == 100
        && *(_BYTE *)(v51 + dword_197F98 + 40) != 100
        && *(_BYTE *)(v20 + dword_197F98 + v58 + 1575) != 2 )
      {
        v57 = -1;
        sub_DBCC8(j, v20, (int)&v57, &v56, &v54);
        if ( v54 != -1 )
        {
          v21 = *(int16_t *)(17 * v54 + dword_1930D4);
          if ( v21 != -1 )
          {
            v22 = 361 * v21;
            if ( v57 != -1 && *(uint8_t *)(dword_192B18 + v22 + 10) > 4u && v56 > 100 )
              sub_4E3B5(
                (int16_t)-(int16_t)(*(uint8_t *)(dword_192B18 + v22 + 10) - 4 + v56 / 50),
                j,
                v20,
                5,
                v57,
                0);
          }
        }
      }
      v51 += 3753;
      ++v20;
    }
  }
  v23 = 0;
LABEL_72:
  if ( v23 >= word_199998 )
  {
    v36 = 0;
    v37 = 0;
    while ( v36 < word_199998 )
    {
      v38 = 0;
      v39 = 0;
      while ( v38 < word_199998 )
      {
        if ( v36 == v38 )
        {
          *(_BYTE *)(v38 + v37 + dword_197F98 + 1559) = 0;
        }
        else
        {
          v59 = dword_197F98;
          *(_BYTE *)(v38 + v37 + dword_197F98 + 1559) = *(_BYTE *)(v36 + v39 + dword_197F98 + 1559);
        }
        v39 += 3753;
        ++v38;
      }
      v37 += 3753;
      ++v36;
    }
    for ( k = 0; k < word_199998; ++k )
    {
      v41 = 0;
      v42 = 3753 * k;
      while ( v41 < word_199998 )
      {
        v43 = v41 + v42 + dword_197F98;
        if ( *(_BYTE *)(v43 + 2054) )
          --*(_BYTE *)(v43 + 2054);
        v44 = v41 + v42 + dword_197F98;
        if ( *(_BYTE *)(v44 + 2062) )
          --*(_BYTE *)(v44 + 2062);
        ++v41;
      }
    }
    if ( word_19A0E2 == 3 )
    {
      v45 = 0;
      v46 = 0;
      while ( v45 < word_199998 )
      {
        v47 = 0;
        v60 = 0;
        while ( v47 < word_199998 )
        {
          if ( v45 != v47 )
          {
            v48 = dword_197F98 + v46;
            v49 = v60 + dword_197F98;
            *(_BYTE *)(v47 + v48 + 1575) = 6;
            *(_BYTE *)(v45 + v49 + 1575) = 6;
            *(_BYTE *)(v47 + v48 + 1559) = -100;
            *(_BYTE *)(v45 + v49 + 1559) = -100;
          }
          v60 += 3753;
          ++v47;
        }
        v46 += 3753;
        ++v45;
      }
    }
    JUMPOUT(0x4DAAB);
  }
  v24 = 0;
  v52 = 0;
  v53 = 0;
  v25 = 3753 * v23;
  while ( 1 )
  {
    if ( v24 >= word_199998 )
    {
      ++v23;
      goto LABEL_72;
    }
    v26 = sub_1247A0(0x69u);
    v27 = *(char *)(v24 + v25 + dword_197F98 + 1559);
    if ( v26 > (int)((HIDWORD(v27) ^ v27) - HIDWORD(v27)) && sub_1247A0(4u) == 1 )
      v55 = sub_1247A0(2u) - 1;
    else
      v55 = 0;
    if ( v24 != v23 )
    {
      v28 = v25 + dword_197F98;
      if ( !*(_WORD *)(v25 + dword_197F98 + v52 + 1847) )
        break;
    }
LABEL_66:
    v34 = dword_197F98;
    v35 = v24 + dword_197F98 + v25;
    if ( *(char *)(v35 + 1575) >= 4 && *(char *)(v35 + 1559) > -90 )
    {
      *(_BYTE *)(v35 + 1559) = -90;
      *(_BYTE *)(v23 + v34 + v53 + 1559) = -90;
    }
    v52 += 2;
    v53 += 3753;
    ++v24;
  }
  v29 = v28 + v24;
  v30 = *(char *)(v28 + v24 + 1559);
  v31 = *(char *)(v28 + v24 + 1567);
  if ( v31 <= v30 )
  {
    *(_BYTE *)(v29 + 1559) -= v55;
    if ( v31 > *(char *)(v29 + 1559) )
LABEL_61:
      *(_BYTE *)(v29 + 1559) = v31;
  }
  else
  {
    *(_BYTE *)(v29 + 1559) += v55;
    if ( v31 < *(char *)(v29 + 1559) )
      goto LABEL_61;
  }
  v32 = v24 + v25 + dword_197F98;
  if ( *(char *)(v32 + 1559) < -100 )
    *(_BYTE *)(v32 + 1559) = -100;
  v33 = v24 + v25 + dword_197F98;
  if ( *(char *)(v33 + 1559) > 100 )
    *(_BYTE *)(v33 + 1559) = 100;
  goto LABEL_66;
}
// 4E3B0: control flows out of bounds to 4DAAB
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19A0E2: using guessed type int16_t word_19A0E2;


//----- (0004E3B5) --------------------------------------------------------
char __fastcall sub_4E3B5(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v8; // ebx
  int v9; // ebx
  int v10; // ebx
  int16_t v11; // dx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // ebx
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int v24; // ecx
  int v25; // eax
  int v26; // ebx
  int v27; // edx
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int16_t v32; // [esp+0h] [ebp-20h]
  int16_t v33; // [esp+0h] [ebp-20h]
  int v34; // [esp+14h] [ebp-Ch]
  char v35; // [esp+18h] [ebp-8h]
  int16_t v36; // [esp+1Ch] [ebp-4h]

  v35 = a4;
  if ( a2 >= 8 )
    return a1;
  if ( a3 >= 8 )
    return a1;
  if ( a2 > word_199998 )
    return a1;
  if ( a3 > word_199998 )
    return a1;
  if ( a2 == a3 )
    return a1;
  if ( !(_WORD)a1 )
    return a1;
  v34 = a3;
  a1 = dword_197F98 + 3753 * a3;
  if ( *(_BYTE *)(a1 + 40) == 100 )
    return a1;
  v8 = 3753 * a2 + dword_197F98;
  if ( *(_BYTE *)(v8 + 36) == 1 )
    return a1;
  if ( *(_BYTE *)(a1 + 36) == 1 )
    return a1;
  v9 = v34 + v8;
  if ( !*(_BYTE *)(v9 + 1412) || !*(_BYTE *)(a2 + a1 + 1412) || *(_BYTE *)(v9 + 1575) == 6 )
    return a1;
  if ( a4 == 10 )
    sub_4EA03(v32, a2, v34, a5, a6);
  if ( v32 == -10000 )
  {
    a1 = 3753 * a2;
    if ( *(_BYTE *)(dword_197F98 + a1 + 40) == 100 && a4 > 0 )
    {
      v10 = 3753 * a3 + dword_197F98;
      a1 = v10 + 2 * a2;
      *(_WORD *)(a1 + 1631) = 10000;
      *(_BYTE *)(v10 + a2 + 1615) = a4;
      *(_WORD *)(a1 + 1647) = a6;
      *(_WORD *)(a1 + 1663) = a5;
    }
    return a1;
  }
  v11 = 2 * v32;
  if ( v32 <= 0 )
  {
    v14 = a2 + 3753 * a3 + dword_197F98;
    if ( *(char *)(v14 + 1559) > 0 )
    {
LABEL_23:
      v33 = v11;
      goto LABEL_30;
    }
    v13 = *(char *)(v14 + 1559) / -25 + 1;
    if ( !(_WORD)v13 )
      LOWORD(v13) = 1;
  }
  else
  {
    v12 = a2 + dword_197F98 + 3753 * a3;
    if ( *(char *)(v12 + 1559) < 0 )
    {
      v33 = 2 * v32;
      if ( *(char *)(v12 + 1559) + v11 <= 10 )
        goto LABEL_30;
      v11 = 10 - *(char *)(v12 + 1559);
      goto LABEL_23;
    }
    v13 = *(char *)(v12 + 1559) / 25 + 1;
    if ( !(_WORD)v13 )
      LOWORD(v13) = 1;
  }
  v33 = v32 / (int16_t)v13;
LABEL_30:
  if ( *(_BYTE *)(3753 * a3 + dword_197F98 + 39) == 4 && v33 < 0 )
    v33 *= 2;
  if ( !*(_BYTE *)(dword_197F98 + 3753 * a3 + 39) && v33 < 0 )
    v33 = 3 * v33 / 2;
  if ( !*(_BYTE *)(dword_197F98 + 3753 * a3 + 39) && v33 > 0 )
    v33 = (3 * v33 - (__CFSHL__((3 * v33) >> 31, 2) + 4 * ((3 * v33) >> 31))) >> 2;
  v36 = v33;
  if ( *(_BYTE *)(dword_197F98 + 3753 * a2 + 2227) == 1 )
  {
    if ( v33 <= 0 )
      v33 /= 2;
    else
      v33 *= 2;
  }
  v15 = dword_197F98 + 3753 * a3 + a2;
  if ( (*(_BYTE *)(v15 + 1575) == 4 || *(_BYTE *)(v15 + 1575) == 5) && a4 >= 1 && a4 <= 9 && v33 < 0 )
  {
    v16 = 3753 * a3 + dword_197F98 + a2;
    if ( *(_BYTE *)(v16 + 1575) == 4 || *(_BYTE *)(v16 + 1575) == 5 )
    {
      v17 = dword_197F98 + 3753 * a2;
      if ( *(_BYTE *)(v17 + 40) == 100 )
      {
        v18 = dword_197F98 + 3753 * a3 + 2 * a2;
        v19 = (int)(v33 - (__CFSHL__((uint64_t)v33 >> 32, 2) + 4 * ((uint64_t)v33 >> 32))) >> 2;
        *(_WORD *)(v18 + 1727) += v19;
        LOBYTE(a1) = a3;
        *(_WORD *)(v17 + 2 * a3 + 1727) -= v19;
        return a1;
      }
    }
    v33 = 0;
  }
  a1 = dword_197F98 + 3753 * a3;
  if ( *(char *)(a2 + a1 + 1575) < 4 )
  {
    if ( *(_BYTE *)(3753 * a2 + dword_197F98 + 40) != 100
      && *(_BYTE *)(a1 + 40) != 100
      && v33 > 0
      && dword_192FD8 - 35000 > 100 )
    {
      v33 *= 2;
    }
    if ( *(_BYTE *)(dword_197F98 + 3753 * a2 + 40) != 100
      && *(_BYTE *)(dword_197F98 + 3753 * a3 + 40) != 100
      && v33 < 0
      && dword_192FD8 - 35000 > 100 )
    {
      v33 /= (uint8_t)byte_199CB0 / 2 + 1;
    }
    if ( v33 )
    {
      v20 = a2 + dword_197F98 + 3753 * a3;
      *(_BYTE *)(v20 + 1559) += v33;
      if ( *(char *)(v20 + 1559) < -100 )
        *(_BYTE *)(v20 + 1559) = -100;
      v21 = a2 + dword_197F98 + 3753 * a3;
      if ( *(char *)(v21 + 1559) > 100 )
        *(_BYTE *)(v21 + 1559) = 100;
      v22 = dword_197F98;
      v23 = 2 * a2 + dword_197F98 + 3753 * a3;
      *(_WORD *)(v23 + 1679) += v33;
      *(_WORD *)(v23 + 1695) += v33;
      *(_WORD *)(v23 + 1711) += v33;
      v24 = 3753 * a2 + v22 + 2 * a3;
      *(_WORD *)(v24 + 1679) = *(_WORD *)(v23 + 1679);
      *(_WORD *)(v24 + 1695) = *(_WORD *)(v23 + 1695);
      *(_WORD *)(v24 + 1711) = *(_WORD *)(v23 + 1711);
      if ( v36 >= 0 )
      {
        *(_WORD *)(v23 + 1727) += v36;
      }
      else
      {
        v25 = (int)(v36 - (__CFSHL__((uint64_t)v36 >> 32, 2) + 4 * ((uint64_t)v36 >> 32))) >> 2;
        *(_WORD *)(v24 + 1727) -= v25;
        *(_WORD *)(v23 + 1727) += v25;
      }
      v26 = 3753 * a3;
      if ( abs16(*(_WORD *)(2 * a2 + v26 + dword_197F98 + 1631)) < (int)abs16(v33) )
      {
        v27 = v26 + dword_197F98;
        v28 = v26 + dword_197F98 + 2 * a2;
        *(_WORD *)(v28 + 1631) = v33;
        *(_BYTE *)(a2 + v27 + 1615) = v35;
        *(_WORD *)(v28 + 1647) = a6;
        *(_WORD *)(v28 + 1663) = a5;
      }
    }
    v29 = a2 + 3753 * a3 + dword_197F98;
    if ( *(char *)(v29 + 1575) >= 4 && *(char *)(v29 + 1559) > -25 )
      *(_BYTE *)(v29 + 1559) = -25;
    v30 = 3753 * a3 + dword_197F98 + a2;
    if ( *(_BYTE *)(v30 + 1575) != 2 && *(char *)(v30 + 1559) > 65 )
      *(_BYTE *)(v30 + 1559) = 65;
    LOBYTE(a1) = *(_BYTE *)(a2 + dword_197F98 + 3753 * a3 + 1559);
    *(_BYTE *)(a3 + dword_197F98 + 3753 * a2 + 1559) = a1;
  }
  return a1;
}
// 4E47F: variable 'v32' is possibly undefined
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (0004EA03) --------------------------------------------------------
void __fastcall sub_4EA03(int a1, int a2, int a3, int a4, int a5)
{
  int16_t i; // si
  int v6; // eax

  for ( i = 0; i < word_199998; ++i )
  {
    if ( i != a2 && i != a3 )
    {
      v6 = dword_197F98 + 3753 * i + a2;
      if ( *(char *)(v6 + 2020) == a3 )
        ((char __fastcall(*)())(void*)sub_4E3B5)(a4, *(char *)(v6 + 2020));
    }
  }
}
// 4E3B5: using guessed type _DWORD __stdcall sub_4E3B5(_DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0004EB06) --------------------------------------------------------
void sub_4EB06()
{
  int16_t v0; // cx
  int16_t i; // si
  int v2; // ebx
  _BYTE *v3; // eax
  int v4; // edi
  int v5; // ebx
  _BYTE *v6; // eax
  signed int v7; // ebx
  int64_t v8; // rax
  uint8_t v9; // dl
  int16_t v10; // ax
  _BYTE *v11; // eax
  int v12; // eax
  int v13; // edi
  int16_t v14; // ax
  _BYTE *v15; // eax
  int v16; // eax
  int v17; // edx
  char v18; // dl
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // edx

  sub_50AD1();
  v0 = 0;
LABEL_89:
  if ( v0 >= word_199998 )
    JUMPOUT(0x4DAAB);
  for ( i = 0; ; ++i )
  {
    if ( i >= word_199998 )
    {
      ++v0;
      goto LABEL_89;
    }
    v2 = dword_197F98 + 3753 * v0;
    v3 = (_BYTE *)(v2 + i);
    if ( v3[1412] == 1 && !v3[1623] && *(_BYTE *)(v2 + 40) != 100 )
    {
      v4 = 3753 * i + dword_197F98;
      if ( *(_BYTE *)(v4 + 40) == 100
        && !*(_BYTE *)(v4 + 36)
        && !*(_BYTE *)(v2 + 36)
        && (v3[1575] != 6 || v3[1871] != 6) )
      {
        v5 = 3753 * v0 + dword_197F98;
        v6 = (_BYTE *)(v5 + i);
        if ( v6[1412] == 1 )
          break;
      }
    }
LABEL_86:
    ;
  }
  if ( word_19A0E2 == 3 )
  {
    if ( *(_BYTE *)(dword_197F98 + 3753 * v0 + i + 1615) )
    {
      if ( *(_BYTE *)(i + 3753 * v0 + dword_197F98 + 1615) <= 0xBu )
      {
        v7 = sub_1247A0(0x64u);
        v8 = *(int16_t *)(3753 * v0 + dword_197F98 + 2 * i + 1631) / 10;
        if ( v7 <= (int)((HIDWORD(v8) ^ v8) - HIDWORD(v8)) )
          *(_BYTE *)(3753 * v0 + dword_197F98 + i + 1623) = 123;
      }
    }
LABEL_77:
    v20 = i + 3753 * v0 + dword_197F98;
    if ( *(_BYTE *)(v20 + 1623) >= 0x13u && *(_BYTE *)(v20 + 1623) <= 0x38u
      || (v21 = i + 3753 * v0 + dword_197F98, *(_BYTE *)(v21 + 1623) >= 0x56u) && *(_BYTE *)(v21 + 1623) <= 0x6Bu
      || (v22 = i + dword_197F98 + 3753 * v0, *(_BYTE *)(v22 + 1623) >= 0x7Cu) && *(_BYTE *)(v22 + 1623) <= 0x7Du )
    {
      if ( *(_BYTE *)(dword_197F98 + 3753 * v0 + 2226) == 1 || *(_BYTE *)(dword_197F98 + 3753 * i + 2226) == 1 )
      {
        v23 = dword_197F98;
        *(_BYTE *)(i + dword_197F98 + 3753 * v0 + 1623) = 0;
        *(_BYTE *)(v0 + v23 + 3753 * i + 1623) = 0;
      }
    }
    goto LABEL_86;
  }
  v9 = v6[1615];
  if ( v9 >= 0x11u )
  {
    if ( v9 <= 0x11u )
    {
      v18 = *(_BYTE *)(v5 + 39) + 1;
    }
    else
    {
      if ( v9 >= 0x14u )
      {
        if ( v9 <= 0x14u )
        {
          v6[1623] = 108;
        }
        else if ( v9 < 0x16u )
        {
          v6[1623] = 82;
        }
        else if ( v9 <= 0x16u )
        {
          v6[1623] = 80;
        }
        else if ( v9 == 23 )
        {
          v6[1623] = 111;
        }
        goto LABEL_68;
      }
      if ( v9 > 0x12u )
      {
        v6[1623] = 70;
        goto LABEL_68;
      }
      if ( (char)v6[1559] >= 0 || (char)v6[1575] >= 4 )
      {
        *(_BYTE *)(i + dword_197F98 + 3753 * v0 + 1623) = *(_BYTE *)(dword_197F98 + 3753 * v0 + 39) + 13;
        goto LABEL_68;
      }
      v18 = *(_BYTE *)(v5 + 39) + 7;
    }
    v6[1623] = v18;
    goto LABEL_68;
  }
  if ( v9 < 0xAu )
  {
    if ( v9 )
      sub_4F0DC(v0, i);
    goto LABEL_68;
  }
  if ( v9 <= 0xAu )
  {
    if ( (char)v6[1575] >= 4 )
      goto LABEL_68;
    if ( *(_BYTE *)(v5 + 39) == 4 && v6[1831] == 1 )
      v10 = 6;
    else
      v10 = *(uint8_t *)(dword_197F98 + 3753 * v0 + 39);
    if ( v10 == 4
      && ((v11 = (_BYTE *)(i + 3753 * v0 + dword_197F98), v11[1575] == 1) || v11[1575] == 2 || v11[1583] || v11[1591]) )
    {
      v12 = i + dword_197F98 + 3753 * v0;
      v13 = 3753 * i + dword_197F98;
      *(_BYTE *)(v12 + 1831) = 1;
      *(_BYTE *)(v0 + v13 + 1831) = 1;
      *(_BYTE *)(v12 + 1623) = 66;
    }
    else
    {
      *(_BYTE *)(dword_197F98 + 3753 * v0 + i + 1623) = 80;
    }
  }
  else
  {
    if ( v9 > 0xBu )
    {
      sub_4FE25(v0, i);
      goto LABEL_68;
    }
    if ( (char)v6[1575] >= 4 )
    {
LABEL_68:
      v19 = i + 3753 * v0 + dword_197F98;
      if ( !*(_BYTE *)(v19 + 1623) && *(char *)(v19 + 1575) >= 4 )
        sub_4F694(v0, i);
      if ( !*(_BYTE *)(i + dword_197F98 + 3753 * v0 + 1623) )
        sub_4FD30(v0, i);
      if ( !*(_BYTE *)(i + 3753 * v0 + dword_197F98 + 1623) )
        sub_2689D(v0, i);
      if ( !*(_BYTE *)(i + 3753 * v0 + dword_197F98 + 1623) )
        sub_501CA(v0, i);
      goto LABEL_77;
    }
    if ( *(_BYTE *)(v5 + 39) == 4 && v6[1831] == 1 )
      v14 = 6;
    else
      v14 = *(uint8_t *)(dword_197F98 + 3753 * v0 + 39);
    if ( v14 == 4
      && ((v15 = (_BYTE *)(3753 * v0 + dword_197F98 + i), v15[1575] == 1) || v15[1575] == 2 || v15[1583] || v15[1591]) )
    {
      v16 = i + dword_197F98 + 3753 * v0;
      v17 = dword_197F98 + 3753 * i;
      *(_BYTE *)(v16 + 1831) = 1;
      *(_BYTE *)(v17 + v0 + 1831) = 1;
      *(_BYTE *)(v16 + 1623) = 66;
    }
    else
    {
      *(_BYTE *)(3753 * v0 + dword_197F98 + i + 1623) = 81;
    }
  }
  sub_51078(i, v0);
  goto LABEL_68;
}
// 4F0D7: control flows out of bounds to 4DAAB
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19A0E2: using guessed type int16_t word_19A0E2;


//----- (0004F0DC) --------------------------------------------------------
char __fastcall sub_4F0DC(int a1, int a2)
{
  int16_t v2; // si
  int v4; // edx
  int v5; // edx
  int v6; // ecx
  int16_t v7; // bx
  int16_t v8; // ax
  int v9; // edx
  int16_t v10; // bx
  int v11; // eax
  _BYTE *v12; // eax
  int16_t v13; // bx
  int v14; // eax
  _BYTE *v15; // eax
  int v16; // edx
  int v17; // ecx
  int v18; // esi
  int v19; // eax
  int v20; // edx
  char v21; // dl
  int16_t v22; // ax
  int16_t v23; // dx
  int v24; // ebx
  int16_t v26; // [esp+8h] [ebp-10h]

  v2 = a1;
  v26 = a1;
  v4 = 3753 * (int16_t)a1;
  LOBYTE(a1) = a2;
  v5 = dword_197F98 + v4;
  if ( *(_WORD *)(v5 + 2 * a2 + 1631) )
  {
    if ( *(char *)(v5 + a2 + 1575) < 4 )
    {
      if ( *(_BYTE *)(dword_197F98 + 3753 * a2 + 2226) != 1 && *(_BYTE *)(v5 + 2226) != 1
        || (a1 = *(int16_t *)(3753 * v2 + dword_197F98 + 2 * a2 + 1631), a1 == -10000) )
      {
        v6 = 3753 * v2;
        v7 = abs32(2 * *(int16_t *)(v6 + dword_197F98 + 2 * a2 + 1631));
        if ( *(_BYTE *)(v6 + dword_197F98 + 39) == 4 && *(_BYTE *)(a2 + v6 + dword_197F98 + 1831) == 1 )
          v8 = 6;
        else
          v8 = *(uint8_t *)(3753 * v2 + dword_197F98 + 39);
        v9 = 3753 * v2 + dword_197F98;
        v10 = v7 - word_180CCC[v8] - *(char *)(v9 + a2 + 1751) - *(char *)(v9 + a2 + 2030);
        if ( *(_BYTE *)(v9 + a2 + 1615) == 9 && *(char *)(v9 + 1995) == a2 )
        {
          v10 = 100;
          *(_BYTE *)(v9 + 1995) = -1;
        }
        v11 = a2 + 3753 * v2 + dword_197F98;
        if ( *(char *)(v11 + 1559) < 0 )
          v10 -= *(char *)(v11 + 1559);
        if ( (int)sub_1247A0(0x64u) <= v10 )
          ++*(_BYTE *)(a2 + dword_197F98 + 3753 * v2 + 1823);
        if ( (int)sub_1247A0(0x64u) <= v10 / 2 )
          ++*(_BYTE *)(3753 * v2 + dword_197F98 + a2 + 1823);
        if ( (int)sub_1247A0(0x64u) <= (int)(v10
                                           - (__CFSHL__((uint64_t)v10 >> 32, 2)
                                            + 4 * ((uint64_t)v10 >> 32))) >> 2 )
          ++*(_BYTE *)(3753 * v2 + dword_197F98 + a2 + 1823);
        v12 = (_BYTE *)(3753 * v2 + dword_197F98 + a2);
        v13 = 0;
        if ( v12[1575] == 1 || v12[1575] == 2 || v12[1583] || v12[1591] )
          v13 = 1;
        v14 = a2 + 3753 * v2 + dword_197F98;
        if ( *(_BYTE *)(v14 + 1615) && *(_BYTE *)(v14 + 1615) <= 9u )
          *(_BYTE *)(v14 + 1743) = *(_BYTE *)(v14 + 1615);
        if ( *(char *)(a2 + dword_197F98 + 3753 * v2 + 1823) > 0
          && sub_53E96(v2, a2) == 4
          && ((v15 = (_BYTE *)(a2 + 3753 * v2 + dword_197F98), v15[1575] == 1)
           || v15[1575] == 2
           || v15[1583]
           || v15[1591]) )
        {
          v16 = v2;
          v17 = 3753 * v2;
          v18 = dword_197F98;
          *(_BYTE *)(a2 + dword_197F98 + v17 + 1831) = 1;
          *(_BYTE *)(v16 + v18 + 3753 * a2 + 1831) = 1;
          sub_51078(a2, v16);
          LOBYTE(a1) = v17 + dword_197F98;
          *(_BYTE *)(a2 + v17 + dword_197F98 + 1623) = 66;
        }
        else
        {
          v19 = a2 + dword_197F98 + 3753 * v2;
          if ( *(char *)(v19 + 1823) < 3 && (*(char *)(v19 + 1823) < 2 || v13) )
          {
            v20 = dword_197F98 + 3753 * v2;
            a1 = v20 + a2;
            if ( *(_BYTE *)(a1 + 1823) == 1 )
            {
              if ( v13 == 1 )
                v21 = *(_BYTE *)(a1 + 1615) + 38;
              else
                v21 = *(_BYTE *)(a1 + 1615) + 18;
              *(_BYTE *)(a1 + 1623) = v21;
            }
            else if ( *(_BYTE *)(a1 + 1823) == 2 && v13 == 1 )
            {
              if ( *(_BYTE *)(v20 + 39) == 4 && *(_BYTE *)(a1 + 1831) == 1 )
                v22 = 6;
              else
                v22 = *(uint8_t *)(dword_197F98 + 3753 * v2 + 39);
              v23 = word_180D54[v22];
              if ( (int)sub_1247A0(0x64u) <= v23 && (uint16_t)sub_4F93B(v2, a2, 6, 1, 1, 1, 1) == 1 )
              {
                *(_BYTE *)(a2 + 3753 * v2 + dword_197F98 + 1623) = *(_BYTE *)(a2 + 3753 * v2 + dword_197F98 + 1615) + 27;
                LOBYTE(a1) = sub_54CC0(v2, a2);
              }
              else
              {
                sub_5138E(a2, v2);
                sub_5175B(a2, v2);
                sub_519AC(a2, v2);
                v24 = dword_197F98 + 3753 * v2 + a2;
                LOBYTE(a1) = *(_BYTE *)(v24 + 1615) + 47;
                *(_BYTE *)(v24 + 1623) = a1;
              }
            }
          }
          else
          {
            LOBYTE(a1) = sub_4F59B(v2, a2, *(_BYTE *)(a2 + dword_197F98 + 3753 * v2 + 1615));
          }
        }
      }
    }
    else
    {
      LOBYTE(a1) = sub_4F694(v26, a2);
    }
  }
  return a1;
}
// 180CCC: using guessed type int16_t word_180CCC[6];
// 180D54: using guessed type int16_t word_180D54[40];
// 197F98: using guessed type int dword_197F98;


//----- (0004F59B) --------------------------------------------------------
int __fastcall sub_4F59B( int a1, int a2, int a3)
{
  int result; // eax
  int v5; // edi
  int v6; // [esp+4h] [ebp-Ch]
  int16_t v7; // [esp+8h] [ebp-8h]

  v6 = 3753 * a1;
  v7 = *(_WORD *)(dword_197F98 + v6 + 2 * a2 + 2103);
  if ( v7 == -1 || *(int *)(dword_197F98 + v6 + 4 * a2 + 2135) < 200 || sub_53E96(a1, a2) == 4 )
  {
    v5 = 3753 * a1;
    result = 100
           * (*(_DWORD *)(4 * a2 + dword_197F98 + v5 + 1516) + 1)
           / (*(_DWORD *)(dword_197F98 + 3753 * a2 + 4 * a1 + 1516) + 1);
    if ( result > 66 )
    {
      sub_51078(a2, a1);
      result = v5 + dword_197F98;
      *(_BYTE *)(a2 + v5 + dword_197F98 + 1623) = a3 + 56;
    }
  }
  else
  {
    result = v6 + dword_197F98;
    *(_WORD *)(result + 1991) = v7;
    *(_BYTE *)(result + 1993) = a3 + 70;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0004F694) --------------------------------------------------------
signed int __fastcall sub_4F694( int a1, int a2)
{
  int v4; // ecx
  signed int result; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int16_t v9; // ax
  int16_t v10; // ax
  int16_t v11; // cx
  int v12; // ebx
  int v13; // eax
  int v14; // edx
  int16_t v15; // dx
  int v16; // eax
  int v17; // eax
  int v18; // edx
  int v19; // edx
  int v20; // [esp+0h] [ebp-20h]
  int v21; // [esp+0h] [ebp-20h]
  int v22; // [esp+0h] [ebp-20h]
  int v23; // [esp+0h] [ebp-20h]
  int v24; // [esp+0h] [ebp-20h]
  int v25; // [esp+8h] [ebp-18h]
  int v26; // [esp+10h] [ebp-10h]
  int v27; // [esp+1Ch] [ebp-4h]

  v4 = a1;
  v25 = 3753 * a1;
  result = a2 + v25 + dword_197F98;
  if ( *(_BYTE *)(result + 1815) >= 0xAu )
  {
    LOWORD(result) = *(uint8_t *)(result + 1815);
    v27 = result - 9;
    v20 = 5 * (int16_t)sub_50028(v4, a2);
    v21 = v20 - 5 * (int16_t)sub_50028(a2, v4);
    sub_500CF(v4, a2);
    v22 = v6 / 10 + v21;
    sub_DBDB8(v4, a2);
    v23 = 40 * v7 + v22 - 10;
    sub_DBDB8(a2, v4);
    v24 = *(char *)(a2 + v25 + dword_197F98 + 1751) / 2 + *(char *)(a2 + v25 + dword_197F98 + 2030) + v23 - 20 * v8;
    sub_51F0F(v4, a2);
    v26 = v9 / 10 + v24;
    v10 = sub_53E96(v4, a2);
    v11 = 0;
    v12 = v26 - word_180CCC[v10] / 5;
    while ( v11 < word_199998 )
    {
      if ( v11 != a1 && v11 != a2 )
      {
        sub_DBDB8(v11, a2);
        v12 += 20 * v13;
      }
      ++v11;
    }
    v14 = (v12 & 0x8000u) == 0 ? (int16_t)v27 / sub_134C92((int16_t)v12 + 3) : v27 * -v12;
    result = sub_1247A0(0x64u);
    if ( result <= (int16_t)v14 )
    {
      if ( (int16_t)v12 >= -10 )
      {
        if ( (int16_t)v12 <= 10 )
        {
          result = dword_197F98 + 3753 * a1;
          v18 = a2;
          *(_BYTE *)(a2 + result + 1623) = 83;
          goto LABEL_23;
        }
        v19 = 3753 * a1;
        if ( (uint16_t)sub_4F93B(a1, a2, ((int16_t)v12 - 10) / 5 + 2, 1, 1, 1, 1) == 1 )
        {
          *(_BYTE *)(a2 + v19 + dword_197F98 + 1623) = 84;
          sub_54CC0(a1, a2);
          goto LABEL_17;
        }
        v17 = a2 + v19 + dword_197F98;
      }
      else
      {
        v15 = sub_4F93B(a2, a1, (-(int16_t)v12 - 10) / 5 + 2, 1, 1, 1, 1);
        v16 = 3753 * a1;
        if ( v15 == 1 )
        {
          *(_BYTE *)(a2 + dword_197F98 + v16 + 1623) = 85;
          sub_54CC0(a1, a2);
LABEL_17:
          result = 3753 * a1 + dword_197F98;
          v18 = a2;
LABEL_23:
          *(_BYTE *)(v18 + result + 1815) = 0;
          return result;
        }
        v17 = a2 + dword_197F98 + v16;
      }
      *(_BYTE *)(v17 + 1623) = 83;
      goto LABEL_17;
    }
  }
  return result;
}
// 4F709: variable 'v6' is possibly undefined
// 4F71D: variable 'v7' is possibly undefined
// 4F734: variable 'v8' is possibly undefined
// 4F782: variable 'v9' is possibly undefined
// 4F7C5: variable 'v13' is possibly undefined
// 180CCC: using guessed type int16_t word_180CCC[6];
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0004F93B) --------------------------------------------------------
int __fastcall sub_4F93B( int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int16_t v8; // si
  int v9; // ebx
  int v10; // eax
  unsigned int v11; // ebx
  int v12; // edx
  int v13; // ebx
  int v14; // ecx
  int result; // eax
  unsigned int v16; // ebx
  int v17; // ebx
  int v18; // eax
  int v19; // ebx
  int v20; // edx
  int16_t v21; // ax
  int v22[25]; // [esp+0h] [ebp-3CEh] BYREF
  __int128 v23; // [esp+64h] [ebp-36Ah]
  char v24[212]; // [esp+350h] [ebp-7Eh] BYREF
  unsigned int v25; // [esp+424h] [ebp+56h]
  unsigned int v26; // [esp+428h] [ebp+5Ah]
  int v27; // [esp+42Ch] [ebp+5Eh] BYREF
  int v28; // [esp+430h] [ebp+62h]
  int v29; // [esp+434h] [ebp+66h]
  int16_t v30; // [esp+438h] [ebp+6Ah]
  unsigned int v31; // [esp+43Ch] [ebp+6Eh]
  int v32; // [esp+440h] [ebp+72h]

  v32 = a2;
  v8 = a3;
  v29 = a4;
  byte_19B584 = 0;
  byte_19B587 = 0;
  word_19B580 = 0;
  word_19B582 = -1;
  if ( a3 > 10 )
    v8 = 10;
  v27 = 0;
  if ( a5 == 1 )
  {
    v26 = 1;
    v25 = 1;
    sub_27094(a1, v32, 0, 0xC343CB00, v24, v22, (int16_t *)&v27, 1);
    v9 = 0;
    v10 = 0;
    do
    {
      if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + v9 + 279) == 3
        && (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v10)] > v26 )
      {
        v26 = (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v10)];
      }
      if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v32 + v9 + 279) == 3
        && (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v10)] > v25 )
      {
        v25 = (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v10)];
      }
      ++v9;
      v10 += 13;
    }
    while ( v9 < 204 );
    if ( v25 < v26 )
      v31 = 10 * v25 / v26;
    else
      v31 = 10;
    if ( (int16_t)v31 < 1 )
      v31 = 1;
  }
  if ( a6 == 1 )
  {
    v11 = *(_DWORD *)(3753 * a1 + dword_197F98 + 180);
    if ( v11 < 0xA )
      v11 = 10;
    v12 = 3753 * (int16_t)v32;
    if ( *(_DWORD *)(v12 + dword_197F98 + 50) )
      v28 = *(_DWORD *)(v12 + dword_197F98 + 50) / (int)v11 / 10;
    else
      v28 = 0;
    if ( (int16_t)v28 > 10 )
      v28 = 10;
  }
  if ( !v8 )
    return 0;
  if ( v8 > 6 )
    v29 = 0;
  if ( v8 > (int16_t)v31 )
    a5 = 0;
  if ( !(_WORD)v27 )
    a5 = 0;
  if ( v8 > (int16_t)v28 )
    a6 = 0;
  if ( v8 < 6 )
    a7 = 0;
  v13 = a6 + a5 + (int16_t)v29;
  if ( !(v13 + a7) )
    return 0;
  v14 = 0;
  if ( a7 == 1 && (sub_1247A0(3u) == 1 || !v13) )
  {
    v14 = 3;
  }
  else if ( a5 == 1 && (sub_1247A0(3u) == 1 || !(a6 + (int16_t)v29)) )
  {
    v14 = 2;
  }
  else if ( (_WORD)v29 == 1 && (sub_1247A0(2u) == 1 || !a6) )
  {
    v14 = 4;
  }
  else if ( a6 )
  {
    v14 = 1;
  }
  if ( v14 == 4 )
  {
    byte_19B584 = (v8 >= 3) + 1;
    return 1;
  }
  if ( v14 != 1 )
  {
    if ( v14 == 3 )
    {
      v30 = sub_E5BE3(
              v32,
              a1,
              v22[0],
              v22[1],
              v22[2],
              v22[3],
              v22[4],
              v22[5],
              v22[6],
              v22[7],
              v22[8],
              v22[9],
              v22[10],
              v22[11],
              v22[12],
              v22[13],
              v22[14],
              v22[15],
              v22[16],
              v22[17],
              v22[18],
              v22[19],
              v22[20],
              v22[21],
              v22[22],
              v22[23],
              v22[24],
              v23);
      if ( v30 != -1 && sub_E4A09(v30, (int16_t)v32, a1) == 1 )
      {
        word_19B582 = (char)v30;
        return 1;
      }
    }
    if ( v14 == 2 )
    {
      v20 = v8 * (int16_t)v27 / (int16_t)v31;
      v21 = v27 - 1 - (sub_1247A0(3u) + v20 - 2);
      if ( v21 < 0 )
        v21 = 0;
      if ( v21 >= (int16_t)v27 )
        v21 = v27 - 1;
      byte_19B587 = v24[v21];
      return 1;
    }
    return 0;
  }
  v16 = *(_DWORD *)(3753 * a1 + dword_197F98 + 180);
  if ( v16 < 0xA )
    v16 = 10;
  v17 = 10 * v8 * v16;
  v18 = dword_197F98 + 3753 * (int16_t)v32;
  if ( v17 > *(_DWORD *)(v18 + 50) )
    v17 = *(_DWORD *)(v18 + 50);
  v19 = v17 >= 100 ? 100 * (v17 / 100) : 10 * (v17 / 10);
  if ( !v19 )
    return 0;
  if ( v19 > 32000 )
    LOWORD(v19) = 32000;
  result = 1;
  word_19B580 = v19;
  return result;
}
// 17E07F: using guessed type int16_t word_17E07F;
// 197F98: using guessed type int dword_197F98;
// 19B580: using guessed type int16_t word_19B580;
// 19B582: using guessed type int16_t word_19B582;
// 19B584: using guessed type char byte_19B584;
// 19B587: using guessed type char byte_19B587;


//----- (0004FD30) --------------------------------------------------------
unsigned int __fastcall sub_4FD30( int a1, int a2)
{
  unsigned int result; // eax
  int16_t i; // dx
  _BYTE *v6; // eax
  int16_t v7; // [esp+4h] [ebp-4h]

  result = dword_197F98 + 3753 * a1;
  if ( *(_BYTE *)(a2 + result + 1575) == 2 )
  {
    result = sub_1247A0(0xAu);
    if ( result == 1 )
    {
      v7 = -1;
      for ( i = 0; i < word_199998; ++i )
      {
        if ( i != a1 && i != a2 && *(char *)(a1 + dword_197F98 + 3753 * i + 1575) >= 4 )
        {
          v6 = (_BYTE *)(i + dword_197F98 + 3753 * a2);
          if ( v6[1412] == 1 && v6[1429] == 1 && (char)v6[1575] < 4 )
            v7 = i;
        }
      }
      result = v7;
      if ( v7 != -1 )
      {
        result = dword_197F98 + 3753 * a1;
        *(_BYTE *)(a2 + result + 1623) = 86;
        *(_BYTE *)(a2 + result + 1927) = v7;
      }
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0004FE25) --------------------------------------------------------
int __fastcall sub_4FE25( int a1, int a2)
{
  int16_t v2; // si
  int result; // eax
  char v4; // dl
  int v5; // edx
  int v6; // edx
  int v7; // eax
  int16_t v8; // dx
  int v11; // [esp+8h] [ebp-4h]

  v2 = 3;
  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1615) == 15 )
    v2 = 10;
  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1615) == 16 )
    v2 = 20;
  result = sub_1247A0(0x64u);
  if ( result <= v2 )
  {
    v11 = 3753 * a1;
    result = a2 + v11 + dword_197F98;
    v4 = *(_BYTE *)(result + 1615) - 12;
    *(_BYTE *)(result + 1823) = 0;
    switch ( v4 )
    {
      case 0:
        *(_BYTE *)(result + 1623) = 89;
        break;
      case 1:
        *(_BYTE *)(result + 1623) = 90;
        break;
      case 2:
        *(_BYTE *)(result + 1623) = 91;
        break;
      case 3:
        if ( *(char *)(result + 2020) == -1 )
        {
          v5 = *(char *)(result + 1559);
          if ( (int)(v5 + sub_1247A0(0x64u)) < 75 )
          {
            if ( sub_1247A0(3u) == 1 && (uint16_t)sub_4F93B(a2, a1, 4, 0, 1, 1, 0) == 1 )
            {
              v6 = v11 + dword_197F98;
              *(_WORD *)(v6 + 2 * a2 + 1996) = word_19B580;
              v7 = v6 + a2;
              LOBYTE(v6) = byte_19B587;
              *(_BYTE *)(v7 + 1623) = 93;
              *(_BYTE *)(v7 + 2012) = v6;
              v8 = a2;
              goto LABEL_17;
            }
            result = dword_197F98 + 3753 * a1;
            *(_BYTE *)(a2 + result + 1623) = 92;
          }
          else
          {
            result = v11 + dword_197F98;
            *(_BYTE *)(a2 + v11 + dword_197F98 + 1623) = 94;
          }
        }
        else
        {
          *(_BYTE *)(result + 2020) = -1;
          *(_BYTE *)(result + 1623) = 93;
        }
        break;
      case 4:
        if ( sub_1247A0(4u) == 1 && (uint16_t)sub_4F93B(a2, a1, 4, 0, 1, 1, 0) == 1 )
        {
          v8 = a2;
          *(_BYTE *)(a2 + v11 + dword_197F98 + 1623) = 96;
LABEL_17:
          result = sub_54CC0(a1, v8);
        }
        else
        {
          result = a2;
          *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1623) = 95;
        }
        break;
      default:
        return result;
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 19B580: using guessed type int16_t word_19B580;
// 19B587: using guessed type char byte_19B587;


//----- (00050028) --------------------------------------------------------
int __fastcall sub_50028( int a1, int a2)
{
  int v3; // edx
  int16_t i; // ax

  v3 = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    if ( i != a1 && i != a2 && *(char *)(i + dword_197F98 + 3753 * a1 + 1575) >= 4 )
    {
      if ( *(_BYTE *)(dword_197F98 + 3753 * i + 40) == 100 )
        ++v3;
      ++v3;
    }
  }
  return v3;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0005008B) --------------------------------------------------------
int __fastcall sub_5008B( int a1)
{
  int v2; // edx
  int16_t i; // ax

  v2 = 1;
  for ( i = 0; i < word_199998; ++i )
  {
    if ( i != a1 && *(_BYTE *)(i + 3753 * a1 + dword_197F98 + 1412) == 1 )
      ++v2;
  }
  return v2;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000500CF) --------------------------------------------------------
void __fastcall sub_500CF( int a1, int a2)
{
  unsigned int v4; // eax
  unsigned int i; // edx

  v4 = 100
     * (*(_DWORD *)(4 * a2 + dword_197F98 + 3753 * a1 + 1516) + 1)
     / (unsigned int)(*(_DWORD *)(3753 * a2 + dword_197F98 + 4 * a1 + 1516) + 1);
  if ( v4 > 0x320 )
    v4 = 800;
  for ( i = 0; i < word_199998; ++i )
  {
    if ( i != a1 && i != a2 && *(char *)(dword_197F98 + 3753 * a1 + i + 1575) >= 4 )
      v4 >>= 1;
  }
  JUMPOUT(0x4FE0B);
}
// 5015F: control flows out of bounds to 4FE0B
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00050164) --------------------------------------------------------
unsigned int __fastcall sub_50164( int a1, int a2)
{
  return 100
       * *(int16_t *)(dword_197F98 + 3753 * a1 + 1512)
       / (unsigned int)(*(int16_t *)(dword_197F98 + 3753 * a2 + 1512) + 1)
       + 1;
}
// 197F98: using guessed type int dword_197F98;


//----- (0005019E) --------------------------------------------------------
void sub_5019E()
{
  JUMPOUT(0x50196);
}
// 501C8: control flows out of bounds to 50196
// 197F98: using guessed type int dword_197F98;


//----- (000501CA) --------------------------------------------------------
void __fastcall sub_501CA( int a1, int a2)
{
  int v4; // ebx
  int16_t v5; // ax
  int v6; // ecx
  unsigned int v7; // eax
  int v8; // eax
  int v9; // eax
  int16_t v10; // cx
  int16_t v11; // dx
  int16_t v12; // ax
  signed int v13; // eax
  signed int v14; // eax
  int v15; // ecx
  int16_t v16; // dx
  int v17; // ecx
  int16_t v18; // dx
  int16_t i; // dx
  _BYTE *v20; // eax
  int v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // edx
  _BYTE *v25; // eax
  int v26; // edx
  _WORD v27[21]; // [esp+0h] [ebp-7Ah]
  unsigned int v28; // [esp+2Ah] [ebp-50h]
  unsigned int v29; // [esp+2Eh] [ebp-4Ch]
  unsigned int v30; // [esp+32h] [ebp-48h]
  int v31; // [esp+36h] [ebp-44h]
  int v32; // [esp+3Ah] [ebp-40h]
  int v33; // [esp+3Eh] [ebp-3Ch]
  int v34; // [esp+42h] [ebp-38h]
  int v35; // [esp+46h] [ebp-34h]
  int v36; // [esp+4Ah] [ebp-30h]
  int v37; // [esp+4Eh] [ebp-2Ch]
  int v38; // [esp+52h] [ebp-28h]
  int v39; // [esp+56h] [ebp-24h]
  int v40; // [esp+5Ah] [ebp-20h]
  int v41; // [esp+5Eh] [ebp-1Ch]
  int v42; // [esp+62h] [ebp-18h]
  int v43; // [esp+66h] [ebp-14h]
  int v44; // [esp+6Ah] [ebp-10h]
  int v45; // [esp+6Eh] [ebp-Ch]
  int v46; // [esp+72h] [ebp-8h]
  int16_t v47; // [esp+76h] [ebp-4h]

  if ( *(char *)(a2 + dword_197F98 + 3753 * a1 + 1575) >= 4 || (sub_2736E(a1, a2), v4 = 0, !v5) )
LABEL_74:
    JUMPOUT(0x4FE0B);
  v6 = 0;
  do
  {
    v7 = sub_1247A0(0x14u);
    if ( v7 < 0xA )
    {
      if ( v7 )
      {
        if ( v7 > 5 )
        {
          if ( !*(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1575) )
            v4 = 2;
        }
        else
        {
          v4 = 5;
        }
      }
    }
    else if ( v7 <= 0xC )
    {
      v32 = 3753 * a1;
      v8 = a2 + v32 + dword_197F98;
      if ( *(char *)(v8 + 1559) >= 0 && !*(_BYTE *)(v8 + 1583) )
        v4 = 1;
    }
    else if ( v7 < 0x10 )
    {
      v9 = 3753 * a1 + dword_197F98 + a2;
      if ( *(char *)(v9 + 1559) >= 0 && !*(_BYTE *)(v9 + 1591) )
        v4 = 4;
    }
    else if ( v7 <= 0x12 )
    {
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1575) == 1 )
        v4 = 3;
    }
    else if ( v7 <= 0x14 )
    {
      v36 = 3753 * a1;
      if ( *(_BYTE *)(a2 + v36 + dword_197F98 + 1575) != 2
        && sub_1247A0(3u) == 1
        && *(char *)(a2 + v36 + dword_197F98 + 1559) >= 0 )
      {
        v4 = 6;
      }
    }
    ++v6;
  }
  while ( (int16_t)v6 < 3 );
  if ( v4 == 5 && (v10 = a1, v37 = a2, sub_2720F(a1, a2), *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1623)) )
  {
    v11 = v37;
  }
  else if ( v4 == 2
         && (v10 = a1,
             v41 = a2,
             sub_500CF(a1, a2),
             v29 = v13,
             v34 = 3753 * a1,
             v28 = 2 * word_180CCC[*(uint8_t *)(v34 + dword_197F98 + 39)],
             (int)sub_1247A0(v28 + 500 - 50 * (uint8_t)byte_199CB0) >= v13) )
  {
    v11 = v41;
    *(_BYTE *)(v41 + v34 + dword_197F98 + 1623) = 97;
  }
  else
  {
    if ( v4 != 3
      || (v10 = a1,
          v39 = a2,
          sub_500CF(a1, a2),
          v29 = v14,
          v33 = 3753 * a1,
          v28 = 2 * word_180CCC[*(uint8_t *)(v33 + dword_197F98 + 39)],
          (int)sub_1247A0(v28 + 350 - 50 * (uint8_t)byte_199CB0) < v14) )
    {
      if ( v4 != 4 )
        goto LABEL_50;
      v15 = dword_197F98 + 3753 * a1;
      v29 = 100 * *(int16_t *)(v15 + 1512);
      v30 = a2;
      v28 = v29 / (*(int16_t *)(3753 * a2 + dword_197F98 + 1512) + 1) + 1;
      v46 = 2 * (uint16_t)word_180CCC[*(uint8_t *)(v15 + 39)];
      v16 = 50 * (uint8_t)byte_199CB0 + v28 - v46;
      if ( *(_BYTE *)(a2 + v15 + 1575) == 1 )
        v16 -= 25;
      v28 = 3753 * a1;
      if ( *(_BYTE *)(dword_197F98 + v28 + a2 + 1575) == 2 )
        v16 -= 50;
      if ( v16 <= (int)sub_1247A0(0x12Cu) )
      {
        v12 = a1;
        v11 = a2;
        *(_BYTE *)(a2 + 3753 * a1 + dword_197F98 + 1623) = 100;
      }
      else
      {
LABEL_50:
        if ( v4 != 1 )
          goto LABEL_77;
        v17 = dword_197F98 + 3753 * a1;
        v29 = 100 * *(_DWORD *)(v17 + 180);
        v28 = a2;
        v30 = *(_DWORD *)(3753 * a2 + dword_197F98 + 180) + 1;
        v29 = v29 / v30 + 1;
        v18 = v29 + 50 * (uint8_t)byte_199CB0 - 2 * word_180CCC[*(uint8_t *)(v17 + 39)];
        if ( *(_BYTE *)(a2 + v17 + 1575) == 1 )
          v18 -= 25;
        if ( *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1575) == 2 )
          v18 -= 50;
        if ( v18 <= (int)sub_1247A0(0x12Cu) )
        {
          v12 = a1;
          v11 = a2;
          *(_BYTE *)(a2 + 3753 * a1 + dword_197F98 + 1623) = 99;
        }
        else
        {
LABEL_77:
          if ( v4 == 1 )
          {
            v45 = 0;
            for ( i = 0; i < word_199998; ++i )
            {
              if ( i != a1 && i != a2 )
              {
                v31 = a1;
                v38 = dword_197F98;
                v43 = i;
                v20 = (_BYTE *)(i + 3753 * a1 + dword_197F98);
                v40 = 3753 * a1 + dword_197F98;
                if ( v20[1412] == 1 )
                {
                  v21 = v43 + v38 + 3753 * a2;
                  if ( *(_BYTE *)(v21 + 1412) == 1 && *(char *)(v21 + 1575) < 4 && (char)v20[1559] <= -50 )
                  {
                    v35 = 2 * v43 + v40;
                    if ( *(_WORD *)(v35 + 1775) > *(_WORD *)(v38 + 3753 * v43 + 2 * v31 + 1775)
                      && *(_BYTE *)(v40 + 39)
                      && v20[1815] >= 0x14u
                      && *(int16_t *)(v35 + 1775) > 0 )
                    {
                      v22 = (int16_t)v45++;
                      v27[v22 + 1] = i;
                    }
                  }
                }
              }
            }
            if ( (int16_t)v45 > 0 )
            {
              v47 = v27[sub_1247A0((int16_t)v45)];
              v30 = a1;
              v28 = *(int16_t *)(dword_197F98 + 3753 * i + 2 * a1 + 1775);
              v23 = *(int16_t *)(dword_197F98 + 3753 * a1 + 2 * i + 1775) / (int)(v28 + 1);
              if ( (int16_t)v23 > 6 )
                LOWORD(v23) = 6;
              v42 = a1;
              v44 = a2;
              if ( (uint16_t)sub_4F93B(a2, a1, v23, 0, 1, 1, 0) == 1 )
              {
                v24 = dword_197F98 + 3753 * v42;
                v25 = (_BYTE *)(v24 + v44);
                v26 = 2 * v44 + v24;
                v25[1623] = 125;
                *(_WORD *)(v26 + 1996) = word_19B580;
                v25[2012] = byte_19B587;
                v25[2020] = v47;
                sub_27507(v42, v44);
                sub_54CC0(v42, v44);
                goto LABEL_74;
              }
            }
          }
          v11 = a2;
          v12 = a1;
        }
      }
      goto LABEL_73;
    }
    v11 = v39;
    *(_BYTE *)(v39 + v33 + dword_197F98 + 1623) = 98;
  }
  v12 = v10;
LABEL_73:
  sub_27507(v12, v11);
  goto LABEL_74;
}
// 50812: control flows out of bounds to 4FE0B
// 50200: variable 'v5' is possibly undefined
// 503C4: variable 'v13' is possibly undefined
// 50437: variable 'v14' is possibly undefined
// 180CCC: using guessed type int16_t word_180CCC[6];
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;
// 19B580: using guessed type int16_t word_19B580;
// 19B587: using guessed type char byte_19B587;


//----- (00050827) --------------------------------------------------------
void __fastcall sub_50827( int a1, int a2, int a3, int a4)
{
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int16_t v9; // dx
  int v10; // eax
  int v11; // ebx
  int v12; // eax

  v6 = 3753 * a1 + dword_197F98;
  if ( *(_BYTE *)(v6 + 39) != 4
    || (v7 = a2 + v6, *(_BYTE *)(v7 + 1831))
    || *(_BYTE *)(v7 + 1575) != 1 && *(_BYTE *)(v7 + 1575) != 2 )
  {
    sub_50028(a1, a2);
    v8 = dword_197F98 + 3753 * a1;
    v9 = *(_WORD *)(v8 + 2 * a2 + 2103);
    if ( v9 == -1 || *(_BYTE *)(v8 + 39) == 4 && *(_BYTE *)(a2 + v8 + 1831) != 1 )
    {
      v12 = a2 + dword_197F98 + 3753 * a1;
      if ( *(_BYTE *)(v12 + 1429) == 1 )
      {
        *(_BYTE *)(v12 + 1623) = a4;
        sub_51078(a1, a2);
      }
    }
    else
    {
      v10 = 3753 * a1;
      v11 = dword_197F98;
      *(_WORD *)(dword_197F98 + v10 + 1991) = v9;
      *(_BYTE *)(v11 + v10 + 1993) = a3;
    }
  }
}
// 197F98: using guessed type int dword_197F98;


//----- (0005090C) --------------------------------------------------------
void sub_5090C()
{
  int16_t i; // si
  int16_t j; // bx
  int v2; // ecx
  int v3; // edx
  int16_t v4; // di
  int16_t k; // dx
  int16_t v6; // bx
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int16_t m; // dx
  int16_t v12; // bx
  int v13; // eax
  int v14; // eax

  sub_50DAC();
  for ( i = 0; i < word_199998; ++i )
  {
    for ( j = 0; j < word_199998; ++j )
    {
      v2 = dword_197F98 + 3753 * i;
      v3 = j;
      v4 = *(_WORD *)(v2 + 2 * j + 1631);
      *(_WORD *)(v2 + 2 * j + 1631) = 0;
      *(_WORD *)(v2 + 2 * j + 1847) = v4;
      *(_BYTE *)(v2 + j + 1615) = 0;
      *(_BYTE *)(v2 + j + 1879) = 0;
      *(_BYTE *)(v2 + j + 1887) = 0;
      *(_BYTE *)(v2 + j + 1895) = 0;
      *(_BYTE *)(v2 + j + 1903) = 0;
      *(_WORD *)(v2 + 2 * j + 1911) = 0;
      *(_BYTE *)(v2 + v3 + 1623) = 0;
    }
  }
  for ( k = 0; k < word_199998; ++k )
  {
    v6 = k;
    while ( ++v6 < word_199998 )
    {
      v7 = dword_197F98 + 3753 * k + v6;
      if ( *(char *)(v7 + 1839) > 0 )
        --*(_BYTE *)(v7 + 1839);
      v8 = dword_197F98 + 3753 * v6 + k;
      if ( *(char *)(v8 + 1839) > 0 )
        --*(_BYTE *)(v8 + 1839);
      v9 = dword_197F98;
      v10 = v6 + dword_197F98 + 3753 * k;
      if ( !*(_BYTE *)(v10 + 1839) && *(_BYTE *)(v10 + 1575) == 3 )
      {
        *(_BYTE *)(v10 + 1575) = 0;
        *(_BYTE *)(k + v9 + 3753 * v6 + 1575) = 0;
      }
    }
  }
  for ( m = 0; m < word_199998; ++m )
  {
    v12 = m;
    while ( ++v12 < word_199998 )
    {
      v13 = 3753 * m + dword_197F98 + v12;
      if ( *(char *)(v13 + 1575) >= 4 )
      {
        if ( *(_BYTE *)(v13 + 1815) < 0xFAu )
          ++*(_BYTE *)(v13 + 1815);
        v14 = m + dword_197F98 + 3753 * v12;
        if ( *(_BYTE *)(v14 + 1815) < 0xFAu )
          ++*(_BYTE *)(v14 + 1815);
      }
    }
  }
  JUMPOUT(0x4DAAB);
}
// 50ACC: control flows out of bounds to 4DAAB
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00050AD1) --------------------------------------------------------
int sub_50AD1()
{
  int result; // eax
  int16_t i; // bx
  int v2; // edx
  int v3; // edx

  for ( result = 0; (int16_t)result < word_199998; ++result )
  {
    for ( i = 0; i < word_199998; ++i )
    {
      if ( (_WORD)result != i )
      {
        v2 = 3753 * (int16_t)result + dword_197F98 + 2 * i;
        if ( *(int16_t *)(v2 + 1679) > 120 )
          *(_WORD *)(v2 + 1679) = 120;
        v3 = dword_197F98 + 3753 * (int16_t)result + 2 * i;
        if ( *(int16_t *)(v3 + 1679) < -200 )
          *(_WORD *)(v3 + 1679) = -200;
      }
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00050B57) --------------------------------------------------------
void sub_50B57()
{
  int16_t i; // si
  int16_t j; // di
  _BYTE *v2; // ebx
  _BYTE *v3; // eax
  char *v4; // edx
  int16_t v5; // dx
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int16_t v9; // bx
  int v10; // edx
  int v11; // eax
  int v12; // [esp+8h] [ebp-10h]
  int v13; // [esp+14h] [ebp-4h]

  for ( i = 0; i < word_199998; ++i )
  {
    if ( *(_BYTE *)(dword_197F98 + 3753 * i + 40) == 100 )
    {
      for ( j = 0; j < word_199998; ++j )
      {
        v2 = (_BYTE *)(dword_197F98 + 3753 * i);
        v3 = &v2[j];
        if ( v3[1412] == 1 )
        {
          v12 = dword_197F98 + 3753 * j;
          v4 = (char *)(i + v12);
          if ( v3[1551] )
          {
            if ( (((int)(uint8_t)v2[1420] >> j) & 1) != 0 )
            {
              if ( v2[40] == 100 && *(_BYTE *)(v12 + 40) == 100 )
              {
                if ( word_19A0E2 != 3 )
                {
                  if ( v4[1559] < 0 && v4[1575] < 4 )
                    v4[1623] = *(_BYTE *)(v12 + 39) + 7;
                  else
                    *(_BYTE *)(i + 3753 * j + dword_197F98 + 1623) = *(_BYTE *)(3753 * j + dword_197F98 + 39) + 13;
                }
              }
              else
              {
                sub_4E3B5(-10000, i, j, 18, 0, 0);
              }
            }
          }
          else
          {
            v3[1551] = 1;
            v3[1575] = 0;
            v4[1575] = 0;
            if ( v2[39] == 4 && v3[1831] == 1 )
              v5 = 6;
            else
              v5 = *(uint8_t *)(dword_197F98 + 3753 * i + 39);
            v6 = dword_197F98;
            v7 = j + dword_197F98 + 3753 * i;
            *(_BYTE *)(v7 + 1839) += 2 * LOBYTE(word_18105C[v5]);
            v8 = v6 + 3753 * j;
            if ( *(_BYTE *)(v8 + 39) == 4 && *(_BYTE *)(i + v8 + 1831) == 1 )
              v9 = 6;
            else
              v9 = *(uint8_t *)(3753 * j + dword_197F98 + 39);
            v13 = dword_197F98;
            v10 = 3753 * j + dword_197F98;
            v11 = v10 + i;
            *(_BYTE *)(v11 + 1839) += 2 * LOBYTE(word_18105C[v9]);
            if ( *(_BYTE *)(v13 + 3753 * i + 40) == 100 && *(_BYTE *)(v10 + 40) == 100 )
            {
              if ( word_19A0E2 != 3 )
                *(_BYTE *)(v11 + 1623) = *(_BYTE *)(v10 + 39) + 1;
            }
            else
            {
              sub_4E3B5(-10000, i, j, 17, 0, 0);
            }
          }
        }
      }
    }
  }
  JUMPOUT(0x4DAAB);
}
// 50DA7: control flows out of bounds to 4DAAB
// 18105C: using guessed type int16_t word_18105C[10];
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19A0E2: using guessed type int16_t word_19A0E2;


//----- (00050DAC) --------------------------------------------------------
void sub_50DAC()
{
  int16_t i; // bx
  int16_t j; // dx
  int v2; // edi
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx

  for ( i = 0; i < word_199998; ++i )
  {
    for ( j = 0; j < word_199998; ++j )
    {
      v2 = 3753 * i + dword_197F98;
      if ( *(_BYTE *)(v2 + j + 1575) != 6 )
      {
        v3 = v2 + 2 * j;
        if ( *(int16_t *)(v3 + 1679) < 0 )
          *(_WORD *)(v3 + 1679) += sub_1247A0(5u);
        v4 = 3753 * i + dword_197F98 + 2 * j;
        if ( *(int16_t *)(v4 + 1679) < 50 )
          *(_WORD *)(v4 + 1679) += sub_1247A0(5u);
        v5 = 2 * j + 3753 * i + dword_197F98;
        if ( *(int16_t *)(v5 + 1695) < 0 )
          *(_WORD *)(v5 + 1695) += sub_1247A0(5u);
        v6 = 2 * j + 3753 * i + dword_197F98;
        if ( *(int16_t *)(v6 + 1695) < 50 )
          *(_WORD *)(v6 + 1695) += sub_1247A0(5u);
        v7 = 2 * j + dword_197F98 + 3753 * i;
        if ( *(int16_t *)(v7 + 1711) < 0 )
          *(_WORD *)(v7 + 1711) += sub_1247A0(5u);
        v8 = dword_197F98 + 3753 * i + 2 * j;
        if ( *(int16_t *)(v8 + 1711) < 50 )
          *(_WORD *)(v8 + 1711) += sub_1247A0(5u);
        v9 = 2 * j + 3753 * i + dword_197F98;
        if ( *(int16_t *)(v9 + 1727) < 0 )
          *(_WORD *)(v9 + 1727) += sub_1247A0(5u);
        v10 = 3753 * i + dword_197F98 + 2 * j;
        if ( *(int16_t *)(v10 + 1727) < 50 )
          *(_WORD *)(v10 + 1727) += sub_1247A0(5u);
        v11 = 2 * j + 3753 * i + dword_197F98;
        if ( *(int16_t *)(v11 + 1727) < -200 )
          *(_WORD *)(v11 + 1727) = -200;
        v12 = 2 * j + 3753 * i + dword_197F98;
        if ( *(int16_t *)(v12 + 1727) > 200 )
          *(_WORD *)(v12 + 1727) = 200;
      }
    }
  }
  JUMPOUT(0x4DAAC);
}
// 50FDA: control flows out of bounds to 4DAAC
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00050FDF) --------------------------------------------------------
int __fastcall sub_50FDF( int a1, int a2)
{
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // eax

  if ( word_19A0E2 == 3 )
    return 0;
  v6 = 3753 * a1 + dword_197F98;
  v5 = v6 + 2 * a2;
  LOWORD(v6) = *(_WORD *)(v5 + 1679);
  if ( (int16_t)v6 > *(int16_t *)(v5 + 1695) )
    LOWORD(v6) = *(_WORD *)(v5 + 1695);
  v7 = dword_197F98 + 3753 * a1 + 2 * a2;
  if ( (int16_t)v6 > *(int16_t *)(v7 + 1711) )
    LOWORD(v6) = *(_WORD *)(v7 + 1711);
  v8 = 2 * a2 + dword_197F98 + 3753 * a1;
  if ( (int16_t)v6 > *(int16_t *)(v8 + 1727) )
    LOWORD(v6) = *(_WORD *)(v8 + 1727);
  return v6;
}
// 197F98: using guessed type int dword_197F98;
// 19A0E2: using guessed type int16_t word_19A0E2;


//----- (00051078) --------------------------------------------------------
void __fastcall sub_51078( int a1, int a2)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  char *v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // edx
  int v13; // ebx
  int v14; // edx
  int v15; // ecx
  int v16; // edi
  int v17; // esi
  int v18; // ebx
  _BYTE *v19; // ebx
  int v20; // [esp+0h] [ebp-24h]
  int v21; // [esp+4h] [ebp-20h]
  int v22; // [esp+8h] [ebp-1Ch]
  int v23; // [esp+Ch] [ebp-18h]
  int v24; // [esp+Ch] [ebp-18h]
  int v25; // [esp+10h] [ebp-14h]
  int v26; // [esp+18h] [ebp-Ch]
  int v27; // [esp+1Ch] [ebp-8h]
  char v28; // [esp+20h] [ebp-4h]

  v4 = 3753 * a1 + dword_197F98;
  if ( *(_BYTE *)(v4 + 40) == 100 )
  {
    v5 = a2 + v4;
    if ( !*(_BYTE *)(v5 + 1551) )
      *(_BYTE *)(v5 + 1551) = 1;
  }
  v6 = 3753 * a2 + dword_197F98;
  if ( *(_BYTE *)(v6 + 40) == 100 )
  {
    v7 = a1 + v6;
    if ( !*(_BYTE *)(v7 + 1551) )
      *(_BYTE *)(v7 + 1551) = 1;
  }
  if ( a1 < word_199998 && a2 < word_199998 )
  {
    v27 = 3753 * a1;
    v25 = v27 + dword_197F98;
    v8 = (char *)(a2 + v27 + dword_197F98);
    if ( v8[1575] < 4 )
    {
      v26 = 3753 * a2;
      v20 = v26 + dword_197F98;
      v8[1823] = 0;
      v21 = a1 + v20;
      *(_BYTE *)(v21 + 1823) = 0;
      v22 = 2 * a2 + v25;
      *(_WORD *)(v22 + 1775) = 0;
      v23 = 2 * a1 + v20;
      *(_WORD *)(v23 + 1775) = 0;
      *(_WORD *)(v22 + 1791) = 0;
      *(_WORD *)(v23 + 1791) = 0;
      v8[1807] = 0;
      *(_BYTE *)(v21 + 1807) = 0;
      sub_519AC(a1, a2);
      sub_5175B(a1, a2);
      sub_51C02(a1, a2);
      sub_5138E(a1, a2);
      v9 = v26 + dword_197F98;
      *(_BYTE *)(a2 + dword_197F98 + v27 + 1567) -= 10;
      *(_BYTE *)(a1 + v9 + 1567) -= 10;
      v28 = -75 - sub_1247A0(0x19u);
      v24 = dword_197F98;
      v10 = v27 + dword_197F98;
      *(_BYTE *)(a2 + v10 + 1559) = v28;
      *(_BYTE *)(v26 + v24 + a1 + 1559) = *(_BYTE *)(a2 + v10 + 1559);
      if ( *(_BYTE *)(v10 + 40) == 100 || (v11 = dword_197F98, *(_BYTE *)(dword_197F98 + 3753 * a2 + 40) == 100) )
      {
        if ( (uint8_t)byte_199CB0 >= 3u )
        {
          v13 = dword_197F98;
          *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1575) = 6;
          *(_BYTE *)(a1 + 3753 * a2 + v13 + 1575) = 6;
        }
        else
        {
          v12 = dword_197F98;
          *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1575) = 5;
          *(_BYTE *)(a1 + v12 + 3753 * a2 + 1575) = 5;
        }
      }
      else
      {
        *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1575) = 4;
        *(_BYTE *)(a1 + 3753 * a2 + v11 + 1575) = 4;
      }
      v14 = a1;
      v15 = a2;
      v16 = dword_197F98 + 3753 * a1;
      v17 = dword_197F98 + 3753 * a2;
      v18 = v17 + 2 * v14;
      *(_WORD *)(v16 + 2 * v15 + 1679) = -200;
      *(_WORD *)(v18 + 1679) = -200;
      *(_WORD *)(v16 + 2 * v15 + 1695) = -200;
      *(_WORD *)(v18 + 1695) = -200;
      *(_WORD *)(v16 + 2 * v15 + 1711) = -200;
      *(_WORD *)(v18 + 1711) = -200;
      *(_WORD *)(v16 + 2 * v15 + 1727) = -130;
      *(_WORD *)(v18 + 1727) = -130;
      v19 = (_BYTE *)(v16 + v15);
      v19[2020] = -1;
      *(_BYTE *)(v14 + v17 + 2020) = -1;
      v19[1815] = 0;
      *(_BYTE *)(v14 + v17 + 1815) = 0;
      v19[1839] = 0;
      *(_BYTE *)(v14 + v17 + 1839) = 0;
    }
  }
  JUMPOUT(0x4FE0B);
}
// 51389: control flows out of bounds to 4FE0B
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (0005138E) --------------------------------------------------------
void __fastcall sub_5138E( int a1, int a2)
{
  int v2; // edi
  int v4; // esi
  _BYTE *v5; // eax
  char v6; // cl
  int16_t i; // ax
  int v8; // esi
  int v9; // eax
  int v10; // esi
  int v11; // eax
  char v12; // cl
  int v13; // eax
  _BYTE *v14; // eax
  int v15; // esi
  _BYTE *v16; // eax
  int v17; // esi
  int v18; // eax
  int v19; // eax
  int v20; // [esp+0h] [ebp-18h]
  int v21; // [esp+8h] [ebp-10h]
  int16_t v22; // [esp+14h] [ebp-4h]

  v2 = dword_197F98;
  if ( a2 < word_199998 && a1 < word_199998 )
  {
    v4 = a2 + dword_197F98 + 3753 * a1;
    if ( *(_BYTE *)(v4 + 1575) )
    {
      v5 = (_BYTE *)(a1 + dword_197F98 + 3753 * a2);
      if ( (char)v5[1575] < 4 )
      {
        v5[1831] = 1;
        v6 = v5[1575];
        ++v5[1823];
        v5[1759] = v6;
        *(_BYTE *)(v4 + 1839) = 0;
        v5[1839] = 0;
        v22 = 0;
        if ( *(_BYTE *)(v4 + 1575) == 1 )
          v22 = -20;
        if ( *(_BYTE *)(v2 + 3753 * a1 + a2 + 1575) == 2 )
          v22 = -40;
        if ( *(_BYTE *)(v2 + 3753 * a1 + a2 + 1575) == 3 )
          v22 = -40;
        if ( *(_BYTE *)(v2 + 3753 * a1 + 39) == 4 )
          v22 *= 3;
        *(_BYTE *)(v2 + 3753 * a1 + a2 + 1751) -= v22;
        for ( i = 0; i < word_199998; ++i )
        {
          if ( i != a1
            && i != a2
            && !*(_BYTE *)(v2 + 3753 * i + 36)
            && (*(_BYTE *)(i + v2 + 3753 * a1 + 1412) == 1 || *(_BYTE *)(i + v2 + 3753 * a2 + 1412) == 1) )
          {
            v8 = v2 + 3753 * i;
            if ( *(_BYTE *)(v8 + 39) == 4 )
              *(_BYTE *)(a1 + v8 + 2030) -= 20;
            else
              *(_BYTE *)(a1 + v8 + 2030) -= 10;
            v20 = a1 + v2 + 3753 * i;
            *(_BYTE *)(v20 + 2038) = a2;
            *(_BYTE *)(v20 + 2046) = *(_BYTE *)(v2 + 3753 * a1 + a2 + 1575);
          }
        }
        v9 = v2 + 3753 * a2;
        if ( *(_BYTE *)(v9 + 39) == 4 )
          *(_BYTE *)(a1 + v9 + 2030) -= 20;
        else
          *(_BYTE *)(a1 + v9 + 2030) -= 10;
        v10 = a1 + v2 + 3753 * a2;
        v11 = a2 + v2 + 3753 * a1;
        *(_BYTE *)(v10 + 2038) = a2;
        v12 = *(_BYTE *)(v11 + 1575);
        *(_BYTE *)(v10 + 2046) = v12;
        if ( v12 == 2 )
        {
          if ( *(char *)(v11 + 1567) - v22 >= -100 )
            *(_BYTE *)(v11 + 1567) -= v22;
          else
            *(_BYTE *)(v11 + 1567) = -100;
          v13 = v2 + 3753 * a1 + a2;
          if ( *(char *)(v13 + 1567) < -100 )
            *(_BYTE *)(v13 + 1567) = -100;
          *(_BYTE *)(a1 + v2 + 3753 * a2 + 1567) = *(_BYTE *)(a2 + v2 + 3753 * a1 + 1567);
        }
        if ( v22 )
        {
          v14 = (_BYTE *)(a2 + v2 + 3753 * a1);
          v14[1863] = v14[1575];
          v15 = a1 + v2 + 3753 * a2;
          *(_BYTE *)(v15 + 1863) = v14[1575];
          *(_BYTE *)(v15 + 1559) = v14[1559];
        }
        v16 = (_BYTE *)(a2 + v2 + 3753 * a1);
        v17 = a1 + v2 + 3753 * a2;
        v16[1575] = 0;
        *(_BYTE *)(v17 + 1575) = 0;
        v16[2020] = 0;
        *(_BYTE *)(v17 + 2020) = 0;
        if ( (char)v16[1559] < -100 )
          v16[1559] = -100;
        v21 = v2 + 3753 * a1;
        *(_BYTE *)(a1 + v2 + 3753 * a2 + 1559) = *(_BYTE *)(v21 + a2 + 1559);
        v18 = v21 + 2 * a2;
        *(_WORD *)(v18 + 1679) = -200;
        *(_WORD *)(v18 + 1695) = -200;
        *(_WORD *)(v18 + 1711) = -200;
        *(_WORD *)(v18 + 1727) = -200;
        v19 = v2 + 3753 * a2 + 2 * a1;
        *(_WORD *)(v19 + 1679) = -200;
        *(_WORD *)(v19 + 1695) = -200;
        *(_WORD *)(v19 + 1711) = -200;
        *(_WORD *)(v19 + 1727) = -200;
      }
    }
  }
  dword_197F98 = v2;
  JUMPOUT(0x4FE0B);
}
// 51756: control flows out of bounds to 4FE0B
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0005175B) --------------------------------------------------------
void __fastcall sub_5175B( int a1, int a2)
{
  int v4; // edx
  int v5; // eax
  int v6; // edi
  _BYTE *v7; // eax
  _BYTE *v8; // edx
  int16_t v9; // dx
  int16_t v10; // dx
  int v11; // eax
  int v12; // eax
  int16_t v13; // cx
  int v14; // eax
  int v15; // eax
  int16_t i; // ax
  int v17; // [esp+4h] [ebp-14h]
  int16_t v18; // [esp+14h] [ebp-4h]

  if ( a2 < word_199998 && a1 < word_199998 )
  {
    v4 = a1;
    v5 = a2 + dword_197F98 + 3753 * a1;
    if ( *(_BYTE *)(v5 + 1591) )
    {
      *(_BYTE *)(3753 * a2 + dword_197F98 + v4 + 1759) = 8;
      v18 = *(uint8_t *)(v5 + 1591);
      if ( *(char *)(v5 + 1559) < -100 )
        *(_BYTE *)(v5 + 1559) = -100;
      v6 = dword_197F98 + 3753 * a1;
      v7 = (_BYTE *)(v6 + a2);
      v8 = (_BYTE *)(a1 + dword_197F98 + 3753 * a2);
      v8[1559] = v7[1559];
      v7[1591] = 0;
      v8[1591] = 0;
      v7[2020] = 0;
      v8[2020] = 0;
      if ( (char)v8[1575] < 4 && v18 == 1 )
      {
        if ( *(_BYTE *)(v6 + 39) == 4 )
          v7[1751] -= 15;
        else
          v7[1751] -= 5;
        v9 = sub_1247A0(0x14u);
        v10 = sub_1247A0(0x14u) + v9;
        v11 = dword_197F98 + 3753 * a1 + a2;
        if ( *(char *)(v11 + 1559) - v10 >= -100 )
          *(_BYTE *)(v11 + 1559) -= v10;
        else
          *(_BYTE *)(v11 + 1559) = -100;
        v12 = a2 + dword_197F98 + 3753 * a1;
        if ( *(char *)(v12 + 1559) < -100 )
          *(_BYTE *)(v12 + 1559) = -100;
        v17 = 3753 * a1;
        *(_BYTE *)(3753 * a2 + dword_197F98 + a1 + 1559) = *(_BYTE *)(a2 + v17 + dword_197F98 + 1559);
        v13 = sub_1247A0(0x14u);
        v14 = a2 + v17 + dword_197F98;
        if ( *(char *)(v14 + 1567) - v13 >= -100 )
          *(_BYTE *)(v14 + 1567) -= v13;
        else
          *(_BYTE *)(v14 + 1567) = -100;
        v15 = a2 + dword_197F98 + 3753 * a1;
        *(_BYTE *)(a1 + dword_197F98 + 3753 * a2 + 1567) = *(_BYTE *)(v15 + 1567);
        *(_BYTE *)(v15 + 1863) = 8;
        for ( i = 0; i < word_199998; ++i )
        {
          if ( i != a1 && i != a2 )
            *(_BYTE *)(dword_197F98 + 3753 * a1 + i + 1751) -= 5;
        }
      }
    }
  }
  JUMPOUT(0x4FE0B);
}
// 519A7: control flows out of bounds to 4FE0B
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000519AC) --------------------------------------------------------
void __fastcall sub_519AC( int a1, int a2)
{
  int v4; // eax
  int v5; // edi
  _BYTE *v6; // eax
  _BYTE *v7; // edx
  int16_t v8; // dx
  int16_t v9; // dx
  int v10; // eax
  int v11; // eax
  int16_t v12; // cx
  int v13; // eax
  int v14; // eax
  int16_t i; // dx
  int v16; // [esp+14h] [ebp-8h]
  int16_t v17; // [esp+18h] [ebp-4h]

  if ( a2 < word_199998 && a1 < word_199998 )
  {
    v16 = a1;
    v4 = a2 + dword_197F98 + 3753 * a1;
    if ( *(_BYTE *)(v4 + 1583) )
    {
      *(_BYTE *)(v16 + 3753 * a2 + dword_197F98 + 1759) = 7;
      v17 = *(uint8_t *)(v4 + 1583);
      if ( *(char *)(v4 + 1559) < -100 )
        *(_BYTE *)(v4 + 1559) = -100;
      v5 = dword_197F98 + 3753 * a1;
      v6 = (_BYTE *)(v5 + a2);
      v7 = (_BYTE *)(a1 + 3753 * a2 + dword_197F98);
      v7[1559] = v6[1559];
      v6[1583] = 0;
      v7[1583] = 0;
      v6[2020] = 0;
      v7[2020] = 0;
      if ( (char)v7[1575] < 4 && v17 == 1 )
      {
        if ( *(_BYTE *)(v5 + 39) == 4 )
          v6[1751] -= 15;
        else
          v6[1751] -= 5;
        v8 = sub_1247A0(0x14u);
        v9 = sub_1247A0(0x14u) + v8;
        v10 = a2 + 3753 * a1 + dword_197F98;
        if ( *(char *)(v10 + 1559) - v9 >= -100 )
          *(_BYTE *)(v10 + 1559) -= v9;
        else
          *(_BYTE *)(v10 + 1559) = -100;
        v11 = dword_197F98 + 3753 * a1 + a2;
        if ( *(char *)(v11 + 1559) < -100 )
          *(_BYTE *)(v11 + 1559) = -100;
        *(_BYTE *)(a1 + 3753 * a2 + dword_197F98 + 1559) = *(_BYTE *)(dword_197F98 + 3753 * a1 + a2 + 1559);
        v12 = sub_1247A0(0x14u);
        v13 = a2 + 3753 * a1 + dword_197F98;
        if ( *(char *)(v13 + 1567) - v12 >= -100 )
          *(_BYTE *)(v13 + 1567) -= v12;
        else
          *(_BYTE *)(v13 + 1567) = -100;
        v14 = a2 + dword_197F98 + 3753 * a1;
        *(_BYTE *)(a1 + 3753 * a2 + dword_197F98 + 1567) = *(_BYTE *)(v14 + 1567);
        *(_BYTE *)(v14 + 1863) = 7;
        for ( i = 0; i < word_199998; ++i )
        {
          if ( i != a1 && i != a2 )
            *(_BYTE *)(dword_197F98 + 3753 * a1 + i + 1751) -= 5;
        }
      }
    }
  }
  JUMPOUT(0x4FE0B);
}
// 51BFD: control flows out of bounds to 4FE0B
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00051C02) --------------------------------------------------------
void __fastcall sub_51C02( int a1, int a2)
{
  int v4; // edx
  int v5; // eax
  int v6; // edi
  _BYTE *v7; // eax
  _BYTE *v8; // edx
  int16_t v9; // dx
  int16_t v10; // dx
  int v11; // eax
  int v12; // eax
  int v13; // [esp+4h] [ebp-14h]
  int16_t v14; // [esp+14h] [ebp-4h]

  if ( a2 < word_199998 && a1 < word_199998 )
  {
    v4 = dword_197F98 + 3753 * a1;
    if ( v4 != -1599 )
    {
      ++*(_BYTE *)(3753 * a2 + dword_197F98 + a1 + 1823);
      v14 = *(_WORD *)(v4 + 2 * a2 + 1599);
      v5 = v4 + a2;
      if ( *(char *)(v5 + 1559) < -100 )
        *(_BYTE *)(v5 + 1559) = -100;
      v6 = dword_197F98 + 3753 * a1;
      v7 = (_BYTE *)(v6 + a2);
      v8 = (_BYTE *)(a1 + dword_197F98 + 3753 * a2);
      v13 = dword_197F98 + 3753 * a2;
      v8[1559] = v7[1559];
      *(_WORD *)(v6 + 2 * a2 + 1599) = 0;
      *(_WORD *)(2 * a1 + v13 + 1599) = 0;
      v7[2020] = 0;
      v8[2020] = 0;
      if ( (char)v8[1575] < 4 && v14 > 0 )
      {
        if ( *(_BYTE *)(v6 + 39) == 4 )
          v7[1751] -= 20;
        else
          v7[1751] -= 10;
        v9 = sub_1247A0(0x32u);
        v10 = sub_1247A0(0x32u) + v9;
        v11 = a2 + dword_197F98 + 3753 * a1;
        if ( *(char *)(v11 + 1559) - v10 >= -100 )
          *(_BYTE *)(v11 + 1559) -= v10;
        else
          *(_BYTE *)(v11 + 1559) = -100;
        v12 = 3753 * a1 + dword_197F98 + a2;
        if ( *(char *)(v12 + 1559) < -100 )
          *(_BYTE *)(v12 + 1559) = -100;
        *(_BYTE *)(dword_197F98 + 3753 * a2 + a1 + 1559) = *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1559);
      }
    }
  }
  JUMPOUT(0x4FE0B);
}
// 51DC9: control flows out of bounds to 4FE0B
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00051DCE) --------------------------------------------------------
int __fastcall sub_51DCE( int a1, int a2)
{
  int v2; // eax
  int result; // eax

  v2 = 100
     * (*(_DWORD *)(dword_197F98 + 3753 * a1 + 4 * a2 + 1516) + 1)
     / (*(_DWORD *)(dword_197F98 + 3753 * a2 + 4 * a1 + 1516) + 1);
  if ( v2 < 100 )
    result = -100 / (v2 + 1);
  else
    result = v2 + 1;
  if ( result > 300 )
    result = 300;
  if ( result < -300 )
    return -300;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (00051E3B) --------------------------------------------------------
int __fastcall sub_51E3B( int a1, int a2)
{
  int result; // eax
  int v5; // ebx
  int v6; // ebx

  if ( !(uint16_t)sub_DCAEE(a1) )
    return 300;
  v5 = (int16_t)sub_DCAEE(a2);
  v6 = 100 * (v5 - (int16_t)sub_DCAEE(a1));
  result = v6 / (int16_t)sub_DCAEE(a1);
  if ( result > 300 )
    result = 300;
  if ( result < -300 )
    return -300;
  return result;
}


//----- (00051E98) --------------------------------------------------------
int __fastcall sub_51E98( int a1, int a2)
{
  int v2; // eax
  int result; // eax

  v2 = dword_197F98 + 3753 * a1;
  if ( !*(_WORD *)(v2 + 166) )
    return 300;
  result = 100 * (*(int16_t *)(v2 + 166) - *(int16_t *)(dword_197F98 + 3753 * a2 + 166)) / *(int16_t *)(v2 + 166);
  if ( result > 300 )
    result = 300;
  if ( result < -300 )
    result = -300;
  if ( result )
  {
    if ( result >= 0 )
      return sub_1247A0(result);
    else
      return -sub_1247A0(-result);
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (00051F0F) --------------------------------------------------------
void __fastcall sub_51F0F(int a1, int a2)
{
  int v3; // ebx
  int v4; // ecx
  int v5; // eax
  int v6; // edx
  int v7; // [esp+4h] [ebp-8h]

  v3 = 0;
  v4 = 0;
  v5 = 0;
  v7 = 0;
  while ( v4 < word_199998 )
  {
    if ( *(_BYTE *)(v7 + dword_197F98 + 40) != 100 )
    {
      v6 = 3753 * a2;
      if ( *(char *)(v4 + v6 + dword_197F98 + 1575) >= 4 )
        v3 += *(int16_t *)(v6 + dword_197F98 + v5 + 1775);
    }
    v7 += 3753;
    v5 += 2;
    ++v4;
  }
  JUMPOUT(0x4FE0B);
}
// 51FE0: control flows out of bounds to 4FE0B
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00051FE5) --------------------------------------------------------
int __fastcall sub_51FE5( int a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int result; // eax

  v2 = a1;
  v3 = dword_197F98 + 3753 * a1 + 2 * a2;
  if ( !*(_WORD *)(v3 + 1775) )
    return -300;
  result = 100
         * (*(int16_t *)(dword_197F98 + 3753 * a2 + 2 * v2 + 1775) - *(int16_t *)(v3 + 1775))
         / *(int16_t *)(v3 + 1775);
  if ( result > 300 )
    result = 300;
  if ( result < -300 )
    return -300;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (00052049) --------------------------------------------------------
int __fastcall sub_52049( int a1, int a2, int a3)
{
  int v5; // edx
  int v6; // eax
  int16_t v7; // dx
  int v8; // eax
  int v9; // eax
  int16_t v10; // dx
  int result; // eax
  int v12; // [esp+0h] [ebp-Ch]
  int v13; // [esp+4h] [ebp-8h]
  int v14; // [esp+8h] [ebp-4h]

  v12 = a1;
  v13 = dword_197F98;
  v5 = dword_197F98 + 3753 * a1;
  *(_WORD *)(v5 + 2 * a2 + 1599) = a3;
  v6 = v5 + a2;
  *(_BYTE *)(v6 + 1823) = 0;
  *(_BYTE *)(v12 + v13 + 3753 * a2 + 1823) = 0;
  if ( *(_BYTE *)(v5 + 39) == 4 && *(_BYTE *)(v6 + 1831) == 1 )
    v7 = 6;
  else
    v7 = *(uint8_t *)(dword_197F98 + 3753 * a1 + 39);
  v14 = dword_197F98;
  v8 = a2 + dword_197F98 + 3753 * a1;
  *(_BYTE *)(v8 + 1839) += 2 * LOBYTE(word_18105C[v7]);
  v9 = v14 + 3753 * a2;
  if ( *(_BYTE *)(v9 + 39) == 4 && *(_BYTE *)(a1 + v9 + 1831) == 1 )
    v10 = 6;
  else
    v10 = *(uint8_t *)(dword_197F98 + 3753 * a2 + 39);
  result = a1;
  *(_BYTE *)(3753 * a2 + dword_197F98 + a1 + 1839) += 2 * LOBYTE(word_18105C[v10]);
  return result;
}
// 18105C: using guessed type int16_t word_18105C[];
// 197F98: using guessed type int dword_197F98;


//----- (00052150) --------------------------------------------------------
void __fastcall sub_52150( int a1, int a2)
{
  int v4; // eax
  int16_t v5; // cx
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // edi
  int16_t v10; // [esp+8h] [ebp-4h]

  v4 = 3753 * a1 + dword_197F98;
  if ( *(_BYTE *)(v4 + 39) == 4 && *(_BYTE *)(a2 + v4 + 1831) == 1 )
    v5 = 6;
  else
    v5 = *(uint8_t *)(dword_197F98 + 3753 * a1 + 39);
  v6 = dword_197F98;
  v7 = a2 + dword_197F98 + 3753 * a1;
  *(_BYTE *)(v7 + 1839) += LOBYTE(word_18105C[v5]);
  v8 = v6 + 3753 * a2;
  if ( *(_BYTE *)(v8 + 39) == 4 && *(_BYTE *)(a1 + v8 + 1831) == 1 )
    v10 = 6;
  else
    v10 = *(uint8_t *)(dword_197F98 + 3753 * a2 + 39);
  v9 = dword_197F98;
  *(_BYTE *)(a1 + dword_197F98 + 3753 * a2 + 1839) += LOBYTE(word_18105C[v10]);
  sub_101F82(v9 + 3753 * a1, a2);
  JUMPOUT(0x4FE0B);
}
// 5223A: control flows out of bounds to 4FE0B
// 18105C: using guessed type int16_t word_18105C[10];
// 197F98: using guessed type int dword_197F98;


//----- (0005223F) --------------------------------------------------------
void __fastcall sub_5223F( int a1, int a2)
{
  int v4; // eax
  int16_t v5; // cx
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // edi
  int16_t v10; // [esp+8h] [ebp-4h]

  v4 = 3753 * a1 + dword_197F98;
  if ( *(_BYTE *)(v4 + 39) == 4 && *(_BYTE *)(a2 + v4 + 1831) == 1 )
    v5 = 6;
  else
    v5 = *(uint8_t *)(dword_197F98 + 3753 * a1 + 39);
  v6 = dword_197F98;
  v7 = a2 + dword_197F98 + 3753 * a1;
  *(_BYTE *)(v7 + 1839) += LOBYTE(word_18105C[v5]);
  v8 = v6 + 3753 * a2;
  if ( *(_BYTE *)(v8 + 39) == 4 && *(_BYTE *)(a1 + v8 + 1831) == 1 )
    v10 = 6;
  else
    v10 = *(uint8_t *)(dword_197F98 + 3753 * a2 + 39);
  v9 = dword_197F98;
  *(_BYTE *)(a1 + dword_197F98 + 3753 * a2 + 1839) += LOBYTE(word_18105C[v10]);
  sub_101EE3(v9 + 3753 * a1, a2);
  JUMPOUT(0x4FE0B);
}
// 52329: control flows out of bounds to 4FE0B
// 18105C: using guessed type int16_t word_18105C[10];
// 197F98: using guessed type int dword_197F98;


//----- (0005232E) --------------------------------------------------------
int __fastcall sub_5232E( int a1, int a2, int a3)
{
  int v4; // esi
  int v5; // edi
  _BYTE *v6; // eax
  int v7; // esi
  int16_t v8; // si
  int v9; // eax
  int result; // eax
  int16_t v11; // di
  int v12; // kr00_4
  int v13; // ebx
  int v14; // [esp+0h] [ebp-14h]
  int v15; // [esp+4h] [ebp-10h]
  int v16; // [esp+8h] [ebp-Ch]

  v14 = a1;
  v4 = dword_197F98;
  v5 = dword_197F98 + 3753 * a1;
  v6 = (_BYTE *)(v5 + a2);
  v6[1575] = a3;
  v7 = v14 + 3753 * a2 + v4;
  *(_BYTE *)(v7 + 1575) = a3;
  v6[1823] = 0;
  *(_BYTE *)(v7 + 1823) = 0;
  if ( *(_BYTE *)(v5 + 39) == 4 && v6[1831] == 1 )
    v8 = 6;
  else
    v8 = *(uint8_t *)(3753 * a1 + dword_197F98 + 39);
  v9 = dword_197F98 + 3753 * a2;
  if ( *(_BYTE *)(v9 + 39) == 4 && (result = a1 + v9, *(_BYTE *)(result + 1831) == 1) )
  {
    v11 = 6;
  }
  else
  {
    result = dword_197F98;
    v11 = *(uint8_t *)(3753 * a2 + dword_197F98 + 39);
  }
  if ( a3 == 1 )
  {
    v15 = dword_197F98;
    v12 = word_18105C[v8];
    *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1839) += v12 / 2 + v12;
    v13 = a1 + 3753 * a2 + v15;
    result = word_18105C[v11] / 2 + word_18105C[v11] + *(char *)(v13 + 1839);
    *(_BYTE *)(v13 + 1839) = result;
  }
  else if ( a3 == 2 )
  {
    v16 = dword_197F98;
    *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1839) += 2 * LOBYTE(word_18105C[v8]);
    result = a1 + 3753 * a2 + v16;
    *(_BYTE *)(result + 1839) += 2 * LOBYTE(word_18105C[v11]);
  }
  return result;
}
// 18105C: using guessed type int16_t word_18105C[10];
// 197F98: using guessed type int dword_197F98;


//----- (000524C3) --------------------------------------------------------
int __fastcall sub_524C3( int a1, int a2)
{
  int result; // eax

  result = 3753 * a1 + dword_197F98;
  *(_WORD *)(result + 2 * a2 + 1695) -= 10;
  *(_WORD *)(result + 2 * a2 + 1679) -= 10;
  *(_WORD *)(result + 2 * a2 + 1711) -= 10;
  *(_WORD *)(result + 2 * a2 + 1727) -= 10;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (000524FB) --------------------------------------------------------
void __fastcall sub_524FB( int a1, int a2)
{
  int v3; // ecx
  int v4; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  int v9; // edx

  v3 = a1;
  v4 = a2 + dword_197F98 + 3753 * a1;
  v5 = 3753 * a2 + dword_197F98;
  *(_BYTE *)(v4 + 1575) = 3;
  *(_BYTE *)(v3 + v5 + 1575) = 3;
  *(_BYTE *)(v4 + 1559) += 50;
  if ( *(char *)(v4 + 1559) > 0 )
    *(_BYTE *)(v4 + 1559) = 0;
  v6 = dword_197F98;
  *(_BYTE *)(a1 + dword_197F98 + 3753 * a2 + 1559) = *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1559);
  v7 = a2;
  *(_BYTE *)(3753 * a1 + v6 + a2 + 1839) = 30;
  v8 = dword_197F98 + 3753 * a2;
  v9 = dword_197F98 + 3753 * a1;
  *(_BYTE *)(a1 + v8 + 1839) = 30;
  *(_BYTE *)(v9 + v7 + 1823) = 0;
  *(_BYTE *)(a1 + v8 + 1823) = 0;
  *(_WORD *)(v9 + 2 * v7 + 1775) = 0;
  *(_WORD *)(v8 + 2 * a1 + 1775) = 0;
  *(_WORD *)(v9 + 2 * v7 + 1791) = 0;
  *(_WORD *)(v8 + 2 * a1 + 1791) = 0;
  *(_BYTE *)(a1 + v8 + 1807) = 0;
  *(_BYTE *)(v9 + v7 + 1807) = 0;
  JUMPOUT(0x4FE0B);
}
// 525FD: control flows out of bounds to 4FE0B
// 197F98: using guessed type int dword_197F98;


