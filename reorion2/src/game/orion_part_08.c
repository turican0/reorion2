#include "orion_common.h"

/* Adresni rozsah: 0x88B5B - 0x93B7F  (200 funkci) */

//----- (00088B5B) --------------------------------------------------------
char __fastcall sub_88B5B( int a1, char *a2, int16_t **a3)
{
  _BOOL1 v4; // al
  int v5; // edi
  int v6; // edx
  int v7; // eax
  int16_t v8; // cx
  int v9; // eax
  int16_t *v10; // eax
  int v11; // ecx
  int v12; // edx
  _WORD v14[8]; // [esp+0h] [ebp-58h] BYREF
  _BYTE v15[8]; // [esp+10h] [ebp-48h] BYREF
  char v16[8]; // [esp+18h] [ebp-40h] BYREF
  int v17; // [esp+20h] [ebp-38h]
  int v18; // [esp+24h] [ebp-34h]
  char *v19; // [esp+28h] [ebp-30h]
  int v20; // [esp+2Ch] [ebp-2Ch] BYREF
  int16_t v21; // [esp+30h] [ebp-28h] BYREF
  int16_t v22; // [esp+34h] [ebp-24h] BYREF
  int v23; // [esp+38h] [ebp-20h]
  int v24; // [esp+3Ch] [ebp-1Ch]
  int16_t v25; // [esp+40h] [ebp-18h] BYREF
  int v26; // [esp+44h] [ebp-14h]
  int16_t v27; // [esp+48h] [ebp-10h] BYREF
  int v28; // [esp+4Ch] [ebp-Ch]
  int v29; // [esp+50h] [ebp-8h]
  char v30; // [esp+54h] [ebp-4h]

  v19 = a2;
  v30 = 0;
  v23 = 200;
  v29 = 20;
  v4 = sub_79E06(word_19999C);
  v5 = 0;
  v24 = 0;
  v17 = a1;
  v6 = (int)v14;
  sub_799F7(a1, (int)v14, &v25, !v4);
  if ( v25 > 1 )
  {
    v30 = 1;
    v26 = 0;
    v7 = 0;
    do
    {
      LOWORD(v6) = v14[(int16_t)v7++];
      v26 += v6;
    }
    while ( (int16_t)v7 < 8 );
    sub_8F625((int)v15);
    sub_120E8C(1);
    v8 = v29;
    sub_1112EC(dword_192ED4, v6);
    v17 = (int16_t)v23;
    v9 = sub_12DAA4(v23, v8);
    v10 = (int16_t *)sub_110D3C(dword_192ED4, v9);
    *a3 = v10;
    sub_12D8F5(v17, v8, (int)v10);
    v11 = (int)*a3;
    v12 = 0;
    v28 = 0;
    sub_122A6E(0, 0, (int)v19, v11);
    do
    {
      v18 = (int16_t)v28;
      if ( (int16_t)v14[(int16_t)v28] > 0 )
      {
        sub_8F4CA(v14[(int16_t)v28], v26, (int16_t *)&v20, &v22, &v27, &v21, v19);
        sub_79138(v18, HIWORD(dword_1B61E4), v16, 0);
        v12 = (int16_t)v24;
        sub_8FE88((int16_t)v5, v24, (int16_t)(v5 + v20), v21, (int)v15, (int)v16, 8, *a3);
        v5 += v20;
      }
      ++v28;
    }
    while ( (int16_t)v28 < 8 );
    sub_1113CC(dword_192ED4, v12);
  }
  return v30;
}
// 192ED4: using guessed type int dword_192ED4;
// 19999C: using guessed type int16_t word_19999C;
// 1B61E4: using guessed type int dword_1B61E4;


//----- (00088CB7) --------------------------------------------------------
void sub_88CB7()
{
  int16_t v0; // di
  char v1[32]; // [esp+0h] [ebp-2Ch] BYREF
  int16_t *v2; // [esp+20h] [ebp-Ch] BYREF
  int16_t v3; // [esp+24h] [ebp-8h] BYREF
  char v4[4]; // [esp+28h] [ebp-4h] BYREF

  v2 = 0;
  sub_8FD71(&v3);
  v0 = 0;
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  while ( v0 < word_19999A )
  {
    if ( *(_BYTE *)(113 * v0 + dword_19306C + 22) != 6 )
    {
      sub_85C8A(v0, 0, v4, v1, &v2);
      if ( v1[0] )
        sub_87768(v0, v4[0], (int)v1, (int)v2);
    }
    ++v0;
  }
  JUMPOUT(0x83CF6);
}
// 88D34: control flows out of bounds to 83CF6
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (00088D39) --------------------------------------------------------
int16_t __usercall sub_88D39( int a1, int a2, int a3, int16_t *a4)
{
  int v4; // eax
  int16_t result; // ax
  int16_t v6; // ax
  int v7; // eax
  int v8; // eax
  int16_t v9; // dx
  int v10; // ebx
  bool v11; // edx
  int v12; // eax

  if ( a1 )
  {
    sub_C5BB9();
    sub_124D41();
    LOBYTE(v4) = sub_128C32(0, 0, 649, 479, 0);
    sub_1077D(v4, 0, 649, a4);
    sub_124B65();
    sub_124D41();
    sub_84A95(1);
    sub_C5C44();
    sub_124C08();
    result = sub_918D5(2);
    if ( !result )
      return result;
    if ( !sub_780D3() )
      return sub_91A40();
    v6 = sub_77FE9(word_192248[word_1999B8]);
    return sub_71B0E(v6, v6 != word_19999C);
  }
  else
  {
    sub_124D41();
    LOWORD(v7) = sub_84E9D();
    sub_1077D(v7, a2, a3, a4);
    result = sub_918D5(2);
    if ( result )
    {
      if ( !sub_780D3() )
        return sub_91A40();
      v8 = sub_77FE9(word_192248[word_1999B8]);
      v9 = v8;
      v10 = v8;
      sub_124D41();
      v11 = v9 != word_19999C;
      sub_71B0E(v10, v11);
      sub_84555(a4);
      return sub_1077D(v12, v11, v10, a4);
    }
  }
  return result;
}
// 88D63: variable 'v4' is possibly undefined
// 88DE4: variable 'v7' is possibly undefined
// 88E38: variable 'v12' is possibly undefined
// 192248: using guessed type int16_t word_192248[500];
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;


//----- (00088E5A) --------------------------------------------------------
int sub_88E5A()
{
  int16_t v0; // ax
  int result; // eax

  word_192FE4[0] = word_19C0A0[4 * word_19999C];
  if ( word_192FE4[0] <= 21 )
    word_192FE4[0] = 22;
  word_192FE6[0] = word_19C0A2[4 * word_19999C];
  if ( word_192FE6[0] <= 21 )
    word_192FE6[0] = 22;
  v0 = word_19C0E0[4 * word_19999C];
  word_192FDE[0] = word_19C0A4[4 * word_19999C];
  word_19301C = v0;
  if ( v0 <= 21 )
    word_19301C = 22;
  word_19301E = word_19C0E2[4 * word_19999C];
  if ( word_19301E <= 113 )
    word_19301E = 22;
  word_193016 = word_19C0E4[4 * word_19999C];
  if ( sub_918D5(2) )
    sub_78770(word_19999C);
  word_199992 = (uint8_t)byte_19C120[word_19999C];
  if ( !word_199992 )
    word_199992 = word_1999A0;
  result = sub_79917();
  word_19999E = result;
  return result;
}
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 193016: using guessed type int16_t word_193016;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 199992: using guessed type int16_t word_199992;
// 19999C: using guessed type int16_t word_19999C;
// 19999E: using guessed type int16_t word_19999E;
// 1999A0: using guessed type int16_t word_1999A0;
// 19C0A0: using guessed type int16_t word_19C0A0[];
// 19C0A2: using guessed type int16_t word_19C0A2[];
// 19C0A4: using guessed type int16_t word_19C0A4[30];
// 19C0E0: using guessed type int16_t word_19C0E0[];
// 19C0E2: using guessed type int16_t word_19C0E2[];
// 19C0E4: using guessed type int16_t word_19C0E4[];


//----- (00088F5D) --------------------------------------------------------
int sub_88F5D()
{
  int v0; // edx
  int result; // eax

  v0 = word_19999C;
  word_19C0A0[4 * word_19999C] = word_192FE4[0];
  word_19C0A2[4 * v0] = word_192FE6[0];
  word_19C0A4[4 * v0] = word_192FDE[0];
  word_19C0E0[4 * v0] = word_19301C;
  word_19C0E2[4 * v0] = word_19301E;
  word_19C0E4[4 * v0] = word_193016;
  sub_7872E(v0);
  result = word_19999C;
  byte_19C120[word_19999C] = word_199992;
  return result;
}
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 193016: using guessed type int16_t word_193016;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 199992: using guessed type int16_t word_199992;
// 19999C: using guessed type int16_t word_19999C;
// 19C0A0: using guessed type int16_t word_19C0A0[];
// 19C0A2: using guessed type int16_t word_19C0A2[];
// 19C0A4: using guessed type int16_t word_19C0A4[30];
// 19C0E0: using guessed type int16_t word_19C0E0[];
// 19C0E2: using guessed type int16_t word_19C0E2[];
// 19C0E4: using guessed type int16_t word_19C0E4[];


//----- (00088FDD) --------------------------------------------------------
int __fastcall sub_88FDD( int a1, int a2, int16_t *a3, _WORD *a4)
{
  int v4; // esi
  int v5; // edi
  int v6; // eax
  int16_t v7; // dx
  int16_t v8; // ax
  int16_t i; // dx
  int16_t v13; // [esp+8h] [ebp-10h]
  int16_t v14; // [esp+Ch] [ebp-Ch]
  int16_t v15; // [esp+10h] [ebp-8h]
  _BOOL1 v16; // [esp+14h] [ebp-4h]

  v14 = 0;
  v4 = -1;
  v15 = 0;
  v5 = word_1999FC + word_1999FE;
  *a4 = -1;
  v6 = word_199BB8;
  *a3 = -1;
  if ( v6 > v5 )
    LOWORD(v6) = v5;
  v7 = word_1999FC;
  v13 = v6;
  while ( v7 < v13 && !v14 )
  {
    v16 = sub_72651(v7);
    if ( v16 && a2 == *(int16_t *)((char *)&word_197FC1 + 9 * v7) )
    {
      v14 = 1;
      *a4 = v15;
      v4 = 0;
      *a3 = v7;
    }
    else if ( v16 && a2 == -*(int16_t *)((char *)&word_197FC1 + 9 * v7) )
    {
      v4 = 1;
      v14 = 1;
      *a4 = v15;
    }
    ++v15;
    ++v7;
  }
  if ( (int16_t)v4 == -1 )
  {
    v8 = word_199BB8;
    if ( word_199BB8 > word_1999FE + word_1999FC )
      v8 = word_1999FE + word_1999FC;
    for ( i = word_1999FC; i < v8; ++i )
    {
      if ( a1 == *(int16_t *)((char *)&word_197FC1 + 9 * i) )
      {
        v4 = 4;
        *a3 = i;
        return v4;
      }
    }
  }
  return v4;
}
// 197FC1: using guessed type int16_t word_197FC1;
// 1999FC: using guessed type int16_t word_1999FC;
// 1999FE: using guessed type int16_t word_1999FE;
// 199BB8: using guessed type int16_t word_199BB8;


//----- (000890EF) --------------------------------------------------------
int __fastcall sub_890EF( int a1, int a2, int16_t *a3, int16_t *a4)
{
  int result; // eax
  int16_t v6; // dx
  int16_t i; // cx

  result = -1;
  *a3 = -1;
  v6 = 0;
  *a4 = -1;
  while ( v6 < word_19999A )
  {
    if ( a2 == word_190178[v6] )
    {
      result = 0;
      *a4 = v6;
      break;
    }
    ++v6;
  }
  if ( *a4 == -1 )
  {
    for ( i = 0; i < word_19999A; ++i )
    {
      if ( a1 == word_190178[i] && *(_BYTE *)(dword_19306C + 113 * i + 22) != 6 )
      {
        result = 4;
        *a3 = i;
        break;
      }
    }
  }
  if ( (int16_t)result == -1 && a2 == word_19997A )
    return 2;
  return result;
}
// 190178: using guessed type int16_t word_190178[72];
// 19306C: using guessed type int dword_19306C;
// 19997A: using guessed type int16_t word_19997A;
// 19999A: using guessed type int16_t word_19999A;


//----- (00089183) --------------------------------------------------------
void __usercall sub_89183(
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
        int64_t a25,
        int64_t a26,
        int a27)
{
  int v27; // edx
  int v28; // eax
  int v29; // ebx
  int16_t v30; // dx
  int16_t v31; // dx
  int16_t v32; // ax
  int v33; // eax
  int16_t v34; // dx
  int v35; // eax
  unsigned int v36; // eax
  int16_t v37; // ax
  _WORD *v38; // eax
  unsigned int *v39; // edi
  unsigned int *v40; // edx
  char *v41; // esi
  int16_t v42; // bx
  int16_t v43; // ax
  int16_t v44; // dx
  int16_t v45; // cx
  uint16_t v46; // ax
  char *v47; // eax
  int16_t v48; // ax
  int16_t v49; // bx
  int16_t v50; // ax
  int v51; // [esp-14h] [ebp-600h]
  unsigned int *v52; // [esp-14h] [ebp-600h]

  STACK[0xC4A] = 0;
  do
  {
    v27 = SLOWORD(STACK[0xC4A]);
    if ( !sub_918D5(STACK[0xC4A]) )
      goto LABEL_67;
    if ( WORD1(a26) == word_192FEC[14 * v27] && !HIWORD(a26) )
    {
      if ( !LOWORD(STACK[0xC4A]) )
      {
        sub_124D41();
        sub_84555((_DWORD *)a1);
        sub_1077D(v28, v27, *(int *)((char *)&a26 + 2), (int16_t *)a1);
        sub_91ABC();
        goto LABEL_67;
      }
      if ( LOWORD(STACK[0xC4A]) == 2 )
      {
        sub_77BF1();
        sub_702C5();
        byte_199F28 = 1;
LABEL_9:
        sub_91A40();
        goto LABEL_67;
      }
      word_192FDE[14 * v27] = word_1992C0[v27];
      goto LABEL_67;
    }
    if ( !HIWORD(a26) && word_1992E8[0] != LOWORD(STACK[0xC4A]) )
    {
      v29 = SLOWORD(STACK[0xC4A]);
      if ( (uint16_t)sub_90605(STACK[0xC4A], SWORD1(a26)) )
        sub_9128C(word_192FDC[14 * v29]);
    }
    if ( word_192FDC[14 * SLOWORD(STACK[0xC4A])] == 1 )
    {
      v30 = sub_890EF(SHIWORD(a25), SWORD1(a26), (int16_t *)&STACK[0xC52], (int16_t *)&STACK[0xC46]);
      word_199960 = STACK[0xC52];
      if ( (uint16_t)sub_79917() != word_19997C )
      {
        if ( v30 == 2 )
        {
          a1 = 4000 / word_199970;
          v31 = (int16_t)a1 * (word_1999A0 * word_19996A / 10) / 10;
          v32 = (int16_t)(5060 / word_19995A) * (word_1999A0 * word_199968 / 10) / 10;
LABEL_21:
          sub_8238B(v32, v31);
          goto LABEL_22;
        }
        if ( !v30 )
        {
          v33 = dword_19306C + 113 * SLOWORD(STACK[0xC46]);
          v31 = *(_WORD *)(v33 + 17);
          v32 = *(_WORD *)(v33 + 15);
          goto LABEL_21;
        }
      }
    }
LABEL_22:
    if ( sub_918D5(2) && word_192FDC[14 * SLOWORD(STACK[0xC4A])] == 2 )
    {
      if ( WORD1(a26) == word_19994E )
      {
        sub_A01C6(&word_199ED0);
      }
      else if ( WORD1(a26) == word_199950 )
      {
        sub_A015D(&word_199ED0);
      }
      if ( WORD1(a26) == word_199982 )
      {
        if ( byte_199F08 == 1 || (uint16_t)sub_712E1() == word_199BB8 )
        {
          sub_7229E(0, 0);
          sub_77BF1();
          word_19995C = -1;
        }
        else
        {
          sub_7229E(1, 0);
        }
      }
      else
      {
        v34 = sub_88FDD(SHIWORD(a25), SWORD1(a26), (int16_t *)&STACK[0xC4E], &word_19C186);
        v35 = SLOWORD(STACK[0xC4E]);
        word_1999CA = -1;
        if ( v35 > -1 )
        {
          v36 = STACK[0xC4E];
          word_19995C = -1;
          word_1999CA = v36;
        }
        if ( v34 == 1 )
        {
          sub_1196F7();
          v37 = sub_78013(word_1999FC + word_19C186);
          sub_31F25(v37);
          sub_6F280();
          byte_199F28 = 1;
        }
        if ( byte_199BCA && WORD1(a26) == word_1999CE )
        {
          word_19995C = -1;
          v38 = *(_WORD **)((char *)&a25 + 2);
          word_199A08 = 30;
LABEL_40:
          word_199A10 = 0;
          *v38 = 1;
          goto LABEL_67;
        }
        if ( byte_199BCB && WORD1(a26) == word_1999D6 )
        {
          if ( sub_7020A() )
          {
            v38 = *(_WORD **)((char *)&a25 + 2);
            word_199A08 = 34;
            goto LABEL_40;
          }
          v39 = &STACK[0xA52];
          v40 = &STACK[0xA52];
          v41 = sub_7A990(0x20u);
          v42 = 0;
          goto LABEL_66;
        }
        if ( byte_199BCC && WORD1(a26) == word_1999CC )
        {
          v38 = *(_WORD **)((char *)&a25 + 2);
          word_199A08 = 31;
          goto LABEL_40;
        }
        if ( byte_199BC9 && WORD1(a26) == word_1999DA )
        {
          v43 = sub_78B93(word_192248[word_1999B8]);
          if ( v43 > -1 && v43 < word_19999A )
            *(_BYTE *)(dword_19306C + 113 * v43 + 54) &= ~(1 << word_19999C);
        }
        else if ( byte_199BC8 && WORD1(a26) == word_1999D4 && SWORD1(a26) > 0 )
        {
          if ( !sub_72617() )
          {
            v39 = &STACK[0xB1A];
            v42 = 3;
            v41 = sub_7A990(0xE6u);
            v40 = &STACK[0xB1A];
LABEL_66:
            v52 = v39;
            strcpy((char *)v39, v41);
            a1 = (int)v52;
            sub_7A25F(&byte_199F28, (int)v40, v42);
            goto LABEL_67;
          }
          v44 = sub_7802A((int)&a27 + 2, 500);
          v45 = sub_78013(0);
          if ( v44 == 1 )
          {
            v51 = 1;
            v46 = 228;
          }
          else
          {
            v51 = v44;
            v46 = 229;
          }
          v47 = sub_7A990(v46);
          sprintf(&STACK[0xBE2], v47, v51);
          if ( (uint8_t)sub_7A25F(&byte_199F28, (int)&STACK[0xBE2], 1) )
          {
            v48 = sub_A1AFA();
            word_199A06 = -1;
            v49 = v48;
            sub_8A503();
            sub_A0305();
            sub_A07C8();
            sub_7229E(0, 0);
            sub_77BF1();
            if ( v49 == word_199BB8 )
            {
              sub_78B0E(v45);
              word_1999B8 = v50;
              if ( v50 == -1 )
                goto LABEL_9;
            }
          }
        }
      }
    }
LABEL_67:
    ++STACK[0xC4A];
  }
  while ( SLOWORD(STACK[0xC4A]) < 5 );
}
// 891DD: variable 'v28' is possibly undefined
// 89647: variable 'v50' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192248: using guessed type int16_t word_192248[500];
// 192FDC: using guessed type int16_t word_192FDC[];
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FEC: using guessed type int16_t word_192FEC[];
// 19306C: using guessed type int dword_19306C;
// 1992C0: using guessed type int16_t word_1992C0[];
// 1992E8: using guessed type int16_t word_1992E8[5];
// 19994E: using guessed type int16_t word_19994E;
// 199950: using guessed type int16_t word_199950;
// 19995A: using guessed type int16_t word_19995A;
// 19995C: using guessed type int16_t word_19995C;
// 199960: using guessed type int16_t word_199960;
// 199968: using guessed type int16_t word_199968;
// 19996A: using guessed type int16_t word_19996A;
// 199970: using guessed type int16_t word_199970;
// 19997C: using guessed type int16_t word_19997C;
// 199982: using guessed type int16_t word_199982;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1999A0: using guessed type int16_t word_1999A0;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999CA: using guessed type int16_t word_1999CA;
// 1999CC: using guessed type int16_t word_1999CC;
// 1999CE: using guessed type int16_t word_1999CE;
// 1999D4: using guessed type int16_t word_1999D4;
// 1999D6: using guessed type int16_t word_1999D6;
// 1999DA: using guessed type int16_t word_1999DA;
// 1999FC: using guessed type int16_t word_1999FC;
// 199A06: using guessed type int16_t word_199A06;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BC8: using guessed type char byte_199BC8;
// 199BC9: using guessed type char byte_199BC9;
// 199BCA: using guessed type char byte_199BCA;
// 199BCB: using guessed type char byte_199BCB;
// 199BCC: using guessed type char byte_199BCC;
// 199ED0: using guessed type int16_t word_199ED0;
// 199F08: using guessed type char byte_199F08;
// 199F28: using guessed type char byte_199F28;
// 19C186: using guessed type int16_t word_19C186;


//----- (000896A7) --------------------------------------------------------
void __fastcall sub_896A7( int a1, int a2)
{
  int16_t i; // si
  int16_t v3; // ax
  int16_t *v4; // eax
  int16_t *v5; // edi
  int16_t v6; // cx
  int16_t v7; // dx
  _BYTE v10[80]; // [esp+8h] [ebp-58h] BYREF
  int v11; // [esp+58h] [ebp-8h]
  char v12; // [esp+5Ch] [ebp-4h]

  v12 = 0;
  for ( i = 0; i < word_1999F8 && !v12; ++i )
  {
    v3 = sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * word_1906C2[6 * i]));
    v4 = (int16_t *)sub_A0D78(v3, 0);
    v5 = v4;
    if ( word_1844CC == 1 )
    {
      v6 = v4[1];
      v7 = word_1906CA[6 * i];
      v11 = *v4;
      sub_1297C3(word_1906C8[6 * i], v7, v11, v6, 1, 10);
    }
    if ( a1 >= word_1906C8[6 * i]
      && a1 <= *v5 + word_1906C8[6 * i]
      && a2 >= word_1906CA[6 * i]
      && a2 <= word_1906CA[6 * i] + v5[1] )
    {
      if ( byte_19C19A && word_199ECD == -1 || !byte_19C19A )
      {
        byte_199ECF = 0;
        word_199EC9 = i;
        sprintf(v10, "ship icon %d", i);
        word_199ECD = -1;
      }
      v12 = 1;
    }
  }
  JUMPOUT(0x82ABB);
}
// 897C7: control flows out of bounds to 82ABB
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1844CC: using guessed type int16_t word_1844CC;
// 1906C2: using guessed type int16_t word_1906C2[];
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 1975D4: using guessed type int16_t word_1975D4;
// 1999F8: using guessed type int16_t word_1999F8;
// 199EC9: using guessed type int16_t word_199EC9;
// 199ECD: using guessed type int16_t word_199ECD;
// 199ECF: using guessed type char byte_199ECF;
// 19C19A: using guessed type char byte_19C19A;


//----- (000897CC) --------------------------------------------------------
int sub_897CC()
{
  int v0; // ecx
  int16_t v1; // dx
  int16_t v2; // cx
  int16_t v3; // dx
  int v4; // eax
  int v5; // ebx
  int16_t v6; // ax
  int result; // eax
  int16_t v8; // [esp+0h] [ebp-3EEh]
  int16_t v9; // [esp+4h] [ebp-3EAh]
  int16_t v10[500]; // [esp+8h] [ebp-3E6h] BYREF
  _BYTE v11[80]; // [esp+3F0h] [ebp+2h] BYREF
  _DWORD v12[3]; // [esp+440h] [ebp+52h]
  _DWORD v13[2]; // [esp+44Ch] [ebp+5Eh]
  _DWORD v14[2]; // [esp+454h] [ebp+66h] BYREF
  int16_t v15; // [esp+45Ch] [ebp+6Eh] BYREF
  int16_t v16; // [esp+460h] [ebp+72h] BYREF
  int v17; // [esp+464h] [ebp+76h]
  char v18; // [esp+468h] [ebp+7Ah]
  char v19; // [esp+46Ch] [ebp+7Eh]

  v12[0] = 12;
  v12[1] = dword_81C98[1];
  v12[2] = dword_81C98[2];
  v18 = 0;
  byte_19C19A = 0;
  v17 = 0;
  v13[0] = *(_DWORD *)asc_81CA4;
  v13[1] = *(_DWORD *)&asc_81CA4[2];
  while ( 1 )
  {
    result = v17;
    if ( (int16_t)v17 >= word_19999A || v18 )
      break;
    v0 = 113 * (int16_t)v17;
    sub_85B93(v17, &v15, &v16);
    v1 = sub_79917();
    v19 = 0;
    if ( *(_BYTE *)(v0 + dword_19306C + 22) == 6 )
    {
      v2 = *((_WORD *)v13 + v1);
    }
    else
    {
      v3 = *(uint8_t *)(v0 + dword_19306C + 19);
      v2 = word_1931AC[(int16_t)(v3 + sub_79917())];
    }
    v4 = *(uint8_t *)(dword_19306C + 113 * (int16_t)v17 + 19);
    if ( (v16 - v8) * (v16 - v8) + (v15 - v9) * (v15 - v9) <= v12[v4] * v12[v4] && word_199EC9 == -1 )
      v19 = 1;
    if ( v19 )
    {
      v14[0] = loc_81CAC;
      v14[1] = loc_81CB0;
      if ( sub_72617() )
      {
        sub_7802A((int)v10, 500);
        sub_FF799(v10, v17, &byte_1992A8);
        byte_19C19A = 1;
      }
      v5 = 113 * (int16_t)v17;
      word_199EC9 = -1;
      word_199ECD = v17;
      byte_199ECF = 0;
      sub_120BB5(2, (int)v14);
      sub_120E8C(1);
      v6 = sub_12066F(v5 + dword_19306C);
      v18 = 1;
      sprintf(v11, "%s, len = %d", (char *)(dword_19306C + v5), v6);
    }
    if ( word_1844CC == 1 )
      sub_1297C3(v15 - v2 / 2, v16 - v2 / 2, v2, v2, 1, 10);
    ++v17;
  }
  return result;
}
// 89866: variable 'v8' is possibly undefined
// 89856: variable 'v9' is possibly undefined
// 81C98: using guessed type int dword_81C98[3];
// 81CA4: using guessed type wchar_t asc_81CA4[3];
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1844CC: using guessed type int16_t word_1844CC;
// 19306C: using guessed type int dword_19306C;
// 1931AC: using guessed type int16_t word_1931AC[];
// 1992A8: using guessed type char byte_1992A8;
// 19999A: using guessed type int16_t word_19999A;
// 199EC9: using guessed type int16_t word_199EC9;
// 199ECD: using guessed type int16_t word_199ECD;
// 199ECF: using guessed type char byte_199ECF;
// 19C19A: using guessed type char byte_19C19A;


//----- (000899AB) --------------------------------------------------------
int __fastcall sub_899AB( int a1, int a2, int a3, int16_t *a4, int16_t *a5, int16_t *a6, _WORD *a7, int16_t *a8)
{
  int v8; // ebx
  int16_t *v9; // eax
  int16_t v10; // dx
  int16_t v11; // ax
  int16_t v12; // ax
  int v13; // eax
  int v14; // eax
  int16_t v15; // ax
  int v16; // eax
  int v17; // eax
  int16_t v18; // ax
  int v21; // [esp+10h] [ebp-5Ch]
  int16_t v22; // [esp+20h] [ebp-4Ch]
  int16_t j; // [esp+28h] [ebp-44h]
  int16_t v25; // [esp+2Ch] [ebp-40h]
  int16_t v26; // [esp+30h] [ebp-3Ch]
  int16_t k; // [esp+38h] [ebp-34h]
  int16_t i; // [esp+3Ch] [ebp-30h]
  int16_t v29; // [esp+40h] [ebp-2Ch]
  int16_t v30; // [esp+44h] [ebp-28h]
  int16_t v31; // [esp+48h] [ebp-24h]
  int16_t v32; // [esp+4Ch] [ebp-20h]
  int16_t v33; // [esp+50h] [ebp-1Ch]
  int16_t v34; // [esp+54h] [ebp-18h]
  int16_t v36; // [esp+5Ch] [ebp-10h]
  int16_t m; // [esp+60h] [ebp-Ch]
  char v38; // [esp+64h] [ebp-8h]
  char v39; // [esp+68h] [ebp-4h]

  v36 = -1;
  *a5 = -1;
  *a4 = -1;
  v8 = -1;
  *a7 = -1;
  v32 = 0;
  *a6 = -1;
  v25 = 0;
  *a8 = -1;
  while ( v25 < 15 && !v32 )
  {
    if ( dword_1931C4[3 * v25] && a2 == word_1931C0[6 * v25] )
    {
      v32 = 1;
      v8 = 0;
      *a7 = word_1931C2[6 * v25];
    }
    ++v25;
  }
  if ( (int16_t)v8 == -1 )
  {
    v33 = 0;
    for ( i = 0; i < 15 && !v33; ++i )
    {
      if ( dword_1931C4[3 * i] && a1 == word_1931C0[6 * i] )
      {
        v33 = 1;
        v8 = 4;
        *a6 = word_1931C2[6 * i];
      }
    }
  }
  if ( (int16_t)v8 == -1 )
  {
    for ( j = 0; j < 5; ++j )
    {
      v9 = (int16_t *)(a3 + 2 * j);
      v21 = 14 * j;
      if ( a2 == *v9 )
      {
        v8 = 0;
        *a5 = sub_C5AA7(*(_WORD *)(v21 + dword_193184), 113 * word_1999C6 + dword_19306C + 74, 5u);
        break;
      }
      if ( a2 == -*v9 )
      {
        v8 = -1;
        if ( *(_BYTE *)(17 * *(int16_t *)(v21 + dword_193184) + dword_1930D4 + 4) != 2 )
        {
          sub_A453F();
          word_19994C = 1;
        }
        return v8;
      }
      if ( a1 == *v9 )
      {
        v8 = 4;
        *a4 = sub_C5AA7(*(_WORD *)(v21 + dword_193184), 113 * word_1999C6 + dword_19306C + 74, 5u);
      }
    }
  }
  if ( (int16_t)v8 == -1 )
  {
    v26 = word_1999E6 + 171;
    v22 = word_1999E8 + 134;
    v10 = sub_123ABA();
    v11 = sub_123AE7();
    v31 = v11;
    if ( a2 == word_1999B2 )
    {
      v39 = 0;
      v30 = 0;
      sub_EBFCB(v26 - v10, v22 - v11);
      v29 = v12;
      while ( v30 < 5 && v29 > -1 && !v39 )
      {
        v13 = *(int16_t *)(113 * word_1999C6 + dword_19306C + 2 * v30 + 74);
        if ( v13 > -1 )
        {
          v14 = 17 * v13 + dword_1930D4;
          if ( *(uint8_t *)(v14 + 3) == v29 && *(_BYTE *)(v14 + 4) == 1 )
          {
            v39 = 1;
            v8 = 0;
            *a5 = v30;
          }
        }
        ++v30;
      }
    }
    if ( (int16_t)v8 == -1 )
    {
      v38 = 0;
      if ( v10 <= word_1999E6
        || word_1999E6 + word_192FE2[0] <= v10
        || v31 <= word_1999E8
        || v31 >= word_1999E8 + word_192FE0[0] )
      {
        v34 = -1;
      }
      else
      {
        sub_EBFCB(v26 - v10, v22 - v31);
        v34 = v15;
      }
      for ( k = 0; k < 5 && v34 > -1 && !v38; ++k )
      {
        v16 = *(int16_t *)(dword_19306C + 113 * word_1999C6 + 2 * k + 74);
        if ( v16 > -1 )
        {
          v17 = dword_1930D4 + 17 * v16;
          if ( *(uint8_t *)(v17 + 3) == v34 && *(_BYTE *)(v17 + 4) == 1 )
          {
            v8 = 4;
            v38 = 1;
            *a4 = k;
          }
        }
      }
    }
  }
  if ( (int16_t)v8 == -1 )
  {
    for ( m = 0; m < 4; ++m )
    {
      if ( a1 == word_190490[m] )
      {
        v8 = 4;
        v36 = m;
        break;
      }
    }
  }
  *a8 = -1;
  if ( *a4 > -1 )
  {
    v18 = *a4;
LABEL_66:
    *a8 = v18;
    return v8;
  }
  if ( *a6 > -1 )
  {
    v18 = *a6 + 1000;
    goto LABEL_66;
  }
  if ( v36 > -1 )
  {
    v18 = v36 + 2000;
    goto LABEL_66;
  }
  return v8;
}
// 89C1B: variable 'v12' is possibly undefined
// 89CFE: variable 'v15' is possibly undefined
// 190490: using guessed type int16_t word_190490[3];
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 193184: using guessed type int dword_193184;
// 1931C0: using guessed type int16_t word_1931C0[];
// 1931C2: using guessed type int16_t word_1931C2[];
// 1931C4: using guessed type int dword_1931C4[43];
// 19994C: using guessed type int16_t word_19994C;
// 1999B2: using guessed type int16_t word_1999B2;
// 1999C6: using guessed type int16_t word_1999C6;
// 1999E6: using guessed type int16_t word_1999E6;
// 1999E8: using guessed type int16_t word_1999E8;


//----- (00089DF9) --------------------------------------------------------
void __fastcall sub_89DF9( int a1, int a2)
{
  int16_t v3; // ax
  int16_t v4; // si
  int v5; // eax
  int16_t *v6; // edi
  int16_t v7; // ax
  int16_t v8; // ax
  int16_t v9; // ax
  int v10; // eax
  int16_t v11; // ax
  int v12; // eax
  int16_t v13; // [esp+4h] [ebp-10h]
  int16_t v14; // [esp+8h] [ebp-Ch]
  int16_t v15; // [esp+Ch] [ebp-8h]
  int16_t v16; // [esp+10h] [ebp-4h]

  sub_7927F();
  v4 = a1 - v3;
  sub_7927F();
  v6 = (int16_t *)(a2 - v5);
  if ( v4 < 0 )
    v4 = 0;
  sub_7927F();
  if ( v4 > word_199A0C - v7 )
  {
    sub_7927F();
    v4 = word_199A0C - v8;
  }
  if ( (int16_t)v6 < 0 )
    v6 = 0;
  sub_7927F();
  if ( (int16_t)v6 > word_199A0A - v9 )
  {
    sub_7927F();
    LOWORD(v6) = word_199A0A;
    v6 = (int16_t *)((char *)v6 - v10);
  }
  v15 = v4 - word_19998C;
  v16 = (_WORD)v6 - word_199990;
  v11 = sub_134637(word_19998C, word_199990, v4, (int16_t)v6);
  if ( v11 > 50 && (v15 || v16) )
  {
    v13 = 0;
    v14 = v11 / 50;
    sub_124B65();
    while ( v13 < v14 )
    {
      sub_8590A(v4, (int16_t)v6, v14);
      sub_13432D(&word_19998C, &word_199990, v4, (int16_t)v6, 50);
      word_199988 = -1;
      sub_124D41();
      ++v13;
      sub_84A95(0);
      sub_84555(v6);
      sub_1077D(v12, (int)&word_199990, v4, v6);
    }
    word_199988 = -1;
    sub_124D41();
    sub_84A95(1);
    sub_124C08();
  }
  else
  {
    word_199988 = -1;
    byte_199F28 = 1;
    word_19998C = v4;
    word_199990 = (int16_t)v6;
  }
  JUMPOUT(0x82ABB);
}
// 89F62: control flows out of bounds to 82ABB
// 89E0D: variable 'v3' is possibly undefined
// 89E1B: variable 'v5' is possibly undefined
// 89E35: variable 'v7' is possibly undefined
// 89E50: variable 'v8' is possibly undefined
// 89E6A: variable 'v9' is possibly undefined
// 89E85: variable 'v10' is possibly undefined
// 89F37: variable 'v12' is possibly undefined
// 199988: using guessed type int16_t word_199988;
// 19998C: using guessed type int16_t word_19998C;
// 199990: using guessed type int16_t word_199990;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;
// 199F28: using guessed type char byte_199F28;


//----- (00089F8A) --------------------------------------------------------
int sub_89F8A()
{
  int16_t i; // ax
  int v1; // edx
  int v2; // eax
  int v3; // edx
  int result; // eax
  int v5; // edx

  word_19C176 = -1000;
  word_19C178 = -1000;
  word_19C17C = -1000;
  word_19C172 = -1000;
  word_19C188 = -1000;
  word_19C17E = -1000;
  word_19C174 = -1000;
  word_19C17A = -1000;
  word_19C162 = -1000;
  word_1999B2 = -1000;
  for ( i = 0; i < word_19999A; ++i )
  {
    v1 = i;
    word_190208[v1] = -1000;
  }
  v2 = 0;
  do
  {
    v3 = (int16_t)v2++;
    word_1992D4[v3] = -1000;
  }
  while ( (int16_t)v2 < 5 );
  result = 0;
  do
  {
    v5 = 6 * (int16_t)result++;
    word_1931C0[v5] = -1000;
  }
  while ( (int16_t)result < 8 );
  word_1999C8 = -1000;
  word_19C18C = -1000;
  word_19997A = -1000;
  word_199982 = -1000;
  word_1999CE = -1000;
  word_1999CC = -1000;
  word_1999D6 = -1000;
  word_1999DA = -1000;
  word_1999D4 = -1000;
  word_182155 = -1000;
  word_182157 = -1000;
  word_182159 = -1000;
  word_18215B = -1000;
  word_18215D = -1000;
  word_18215F = -1000;
  return result;
}
// 182155: using guessed type int16_t word_182155;
// 182157: using guessed type int16_t word_182157;
// 182159: using guessed type int16_t word_182159;
// 18215B: using guessed type int16_t word_18215B;
// 18215D: using guessed type int16_t word_18215D;
// 18215F: using guessed type int16_t word_18215F;
// 190208: using guessed type int16_t word_190208[72];
// 1931C0: using guessed type int16_t word_1931C0[];
// 1992D4: using guessed type int16_t word_1992D4[10];
// 19997A: using guessed type int16_t word_19997A;
// 199982: using guessed type int16_t word_199982;
// 19999A: using guessed type int16_t word_19999A;
// 1999B2: using guessed type int16_t word_1999B2;
// 1999C8: using guessed type int16_t word_1999C8;
// 1999CC: using guessed type int16_t word_1999CC;
// 1999CE: using guessed type int16_t word_1999CE;
// 1999D4: using guessed type int16_t word_1999D4;
// 1999D6: using guessed type int16_t word_1999D6;
// 1999DA: using guessed type int16_t word_1999DA;
// 19C162: using guessed type int16_t word_19C162;
// 19C172: using guessed type int16_t word_19C172;
// 19C174: using guessed type int16_t word_19C174;
// 19C176: using guessed type int16_t word_19C176;
// 19C178: using guessed type int16_t word_19C178;
// 19C17A: using guessed type int16_t word_19C17A;
// 19C17C: using guessed type int16_t word_19C17C;
// 19C17E: using guessed type int16_t word_19C17E;
// 19C188: using guessed type int16_t word_19C188;
// 19C18C: using guessed type int16_t word_19C18C;


//----- (0008A0B7) --------------------------------------------------------
void __fastcall sub_8A0B7( int a1)
{
  int16_t v2; // dx
  int16_t v3; // si
  int16_t i; // cx
  int v5; // ebx

  v2 = word_199BB8;
  v3 = 0;
  if ( word_199BB8 > word_1999FC + word_1999FE )
    v2 = word_1999FC + word_1999FE;
  for ( i = word_1999FC; i < v2; ++i )
  {
    if ( a1 == *(int16_t *)((char *)&word_197FC1 + 9 * i) )
    {
      v5 = 5 * *(int16_t *)((char *)&word_197FC3 + 9 * saveSlotInfo_199699[1 + v3/37].name[0]);
      if ( sub_7843D(word_19999C, dword_197F9C + 129 * *(int16_t *)((char *)&word_1975D4 + v5)) )
        byte_1975D8[v5] = byte_19C199;
    }
    ++v3;
  }
  JUMPOUT(0x83CFF);
}
// 8A154: control flows out of bounds to 83CFF
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 197FC1: using guessed type int16_t word_197FC1;
// 197FC3: using guessed type int16_t word_197FC3;
// 1996AC: using guessed type int16_t word_1996AC[9];
// 19999C: using guessed type int16_t word_19999C;
// 1999FC: using guessed type int16_t word_1999FC;
// 1999FE: using guessed type int16_t word_1999FE;
// 199BB8: using guessed type int16_t word_199BB8;
// 19C199: using guessed type char byte_19C199;


//----- (0008A159) --------------------------------------------------------
void sub_8A159()
{
  byte_199F1D = 101;
  word_199966 = -1;
}
// 199966: using guessed type int16_t word_199966;
// 199F1D: using guessed type char byte_199F1D;


//----- (0008A16A) --------------------------------------------------------
char __fastcall sub_8A16A( int a1)
{
  return sub_7843D(word_19999C, 129 * a1 + dword_197F9C);
}
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;


//----- (0008A188) --------------------------------------------------------
_BOOL1 __fastcall sub_8A188( int a1)
{
  int16_t v2; // [esp+0h] [ebp-8h] BYREF
  int16_t v3; // [esp+4h] [ebp-4h] BYREF

  sub_85B93(a1, &v3, &v2);
  return v3 > 21 && v3 < 527 && v2 > 21 && v2 < 421;
}


//----- (0008A216) --------------------------------------------------------
int __fastcall sub_8A216( int a1, int a2)
{
  uint16_t v2; // ax
  char *v3; // eax
  _BYTE v5[100]; // [esp+0h] [ebp+1Ah] BYREF
  char v6[32]; // [esp+64h] [ebp+7Eh] BYREF

  switch ( a1 )
  {
    case 0:
      byte_199BDC = byte_199BDC == 0;
      strcpy(v6, sub_7A990(0xA6u));
      a2 = byte_199BDC;
      break;
    case 1:
      byte_199BDD = byte_199BDD == 0;
      strcpy(v6, sub_7A990(0xA7u));
      a2 = byte_199BDD;
      break;
    case 2:
      byte_199BDF = byte_199BDF == 0;
      strcpy(v6, sub_7A990(0xA8u));
      a2 = byte_199BDF;
      break;
    case 4:
      byte_199BE1 = byte_199BE1 == 0;
      strcpy(v6, sub_7A990(0xAAu));
      a2 = byte_199BE1;
      break;
    case 5:
      byte_199BE2 = byte_199BE2 == 0;
      strcpy(v6, sub_7A990(0xABu));
      a2 = byte_199BE2;
      break;
    case 6:
      byte_199BE3 = byte_199BE3 == 0;
      strcpy(v6, sub_7A990(0xACu));
      a2 = byte_199BE3;
      if ( byte_199BE3 )
        sub_78507();
      break;
    case 7:
      byte_199BE4 = byte_199BE4 == 0;
      strcpy(v6, sub_7A990(0xADu));
      a2 = byte_199BE4;
      break;
    default:
      break;
  }
  if ( a2 )
    v2 = 231;
  else
    v2 = 232;
  v3 = sub_7A990(v2);
  sprintf(v5, "%s %s", v6, v3);
  sub_12030();
  return sub_7A25F(&byte_199F28, (int)v5, 0);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 199BDC: using guessed type char byte_199BDC;
// 199BDD: using guessed type char byte_199BDD;
// 199BDF: using guessed type char byte_199BDF;
// 199BE1: using guessed type char byte_199BE1;
// 199BE2: using guessed type char byte_199BE2;
// 199BE3: using guessed type char byte_199BE3;
// 199BE4: using guessed type char byte_199BE4;
// 199F28: using guessed type char byte_199F28;


//----- (0008A3E7) --------------------------------------------------------
int __fastcall sub_8A3E7(int a1, _WORD *a2, _WORD *a3, int16_t *a4)
{
  int16_t v4; // di
  int16_t v5; // dx
  int v6; // eax
  int16_t v7; // ax
  int result; // eax
  char v9[40]; // [esp+0h] [ebp-4Ch] BYREF
  int16_t *v10; // [esp+28h] [ebp-24h] BYREF
  int v11; // [esp+2Ch] [ebp-20h]
  _WORD *v12; // [esp+30h] [ebp-1Ch]
  _WORD *v13; // [esp+34h] [ebp-18h]
  int v14; // [esp+38h] [ebp-14h]
  int16_t v15; // [esp+3Ch] [ebp-10h] BYREF
  int16_t v16; // [esp+40h] [ebp-Ch] BYREF
  int v17; // [esp+44h] [ebp-8h]
  _BYTE v18[4]; // [esp+48h] [ebp-4h] BYREF

  v4 = a1;
  v13 = a2;
  v12 = a3;
  LOWORD(a1) = word_199992;
  v10 = 0;
  v14 = a1;
  word_199992 = word_1999A0;
  sub_79917();
  v11 = 113 * v4;
  v5 = *(uint8_t *)(v11 + dword_19306C + 19);
  v6 = (int16_t)(v5 + sub_79917());
  LOWORD(v6) = word_1931AC[v6];
  v17 = v6;
  sub_7A00A(0, 0, (uint8_t)a3);
  sub_120E8C(1);
  sub_85C8A(v4, 0, v18, v9, &v10);
  sub_85B93(v4, &v15, &v16);
  v7 = sub_12066F((int)v9);
  *a4 = v7;
  *v13 = v15 + 1 - v7 / 2;
  *v12 = v16 + (int16_t)v17 / 2 - *(uint8_t *)(v11 + dword_19306C + 19);
  result = v14;
  word_199992 = v14;
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1931AC: using guessed type int16_t word_1931AC[];
// 199992: using guessed type int16_t word_199992;
// 1999A0: using guessed type int16_t word_1999A0;


//----- (0008A4C4) --------------------------------------------------------
int sub_8A4C4()
{
  int16_t i; // bx
  char v1; // dl
  int v2; // eax

  for ( i = 0; i < word_19999A; ++i )
  {
    v1 = sub_7A1A8(i, word_19999C);
    v2 = 113 * i;
    *(_BYTE *)(dword_19306C + v2 + 20) = v1;
  }
  sub_A0305();
  return sub_A07C8();
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;


//----- (0008A503) --------------------------------------------------------
int sub_8A503()
{
  int16_t i; // bx
  char v1; // dl
  int result; // eax

  for ( i = 0; i < word_19999A; ++i )
  {
    v1 = sub_7A1A8(i, word_19999C);
    result = 113 * i;
    *(_BYTE *)(dword_19306C + result + 20) = v1;
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;


//----- (0008A538) --------------------------------------------------------
int __fastcall sub_8A538( int a1, int a2)
{
  return 400 * a1 / a2;
}


//----- (0008A548) --------------------------------------------------------
void sub_8A548()
{
  JUMPOUT(0x8A540);
}
// 8A550: control flows out of bounds to 8A540


//----- (0008A552) --------------------------------------------------------
int __fastcall sub_8A552( int a1, int a2)
{
  int result; // eax
  int v3; // ebx

  result = 3753 * a1;
  v3 = dword_197F98;
  *(_BYTE *)(dword_197F98 + result + 3689) = 1;
  *(_BYTE *)(v3 + result + 3703) = a2;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0008A571) --------------------------------------------------------
void sub_8A571()
{
  int v0; // ebx
  int v1; // eax
  _BYTE v2[500]; // [esp+0h] [ebp-454h] BYREF
  char v3[500]; // [esp+1F4h] [ebp-260h] BYREF
  char v4[52]; // [esp+3E8h] [ebp-6Ch] BYREF
  int16_t v5[26]; // [esp+41Ch] [ebp-38h] BYREF
  int v6; // [esp+450h] [ebp-4h]

  LOWORD(v6) = 0;
  while ( (int16_t)v6 < word_199998 )
  {
    if ( (_WORD)v6 != word_19999C )
    {
      v0 = 3753 * (int16_t)v6;
      if ( *(_BYTE *)(dword_197F98 + v0 + 3703) )
      {
        if ( (((int)*(uint8_t *)(3753 * word_19999C + dword_197F98 + 3702) >> v6) & 1) == 0 )
        {
          strcpy(v4, (char *)(dword_197F98 + v0 + 1));
          strcpy((char *)v5, (char *)(v0 + dword_197F98 + 21));
          sub_132F5C((int)v4);
          sub_132F5C((int)v5);
          *(_BYTE *)(v0 + dword_197F98 + 3689) = 1;
          sub_8F6DF(0x16u, v3);
          sprintf(v2, v3, v4, v5);
          sub_7A25F(&byte_199F28, (int)v2, 3);
          sub_124D41();
          LOWORD(v1) = sub_84E9D();
          sub_1077D(v1, (int)v2, 3, v5);
          *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 3702) |= 1 << v6;
        }
      }
    }
    LOWORD(v6) = v6 + 1;
  }
  *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 3703) = 0;
  JUMPOUT(0x83CFF);
}
// 8A6BD: control flows out of bounds to 83CFF
// 8A667: variable 'v1' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 199F28: using guessed type char byte_199F28;


//----- (0008A6C2) --------------------------------------------------------
void sub_8A6C2()
{
  int v0; // eax
  char v1; // cl
  int v2; // eax
  int v3; // eax
  int v4; // eax
  unsigned int v5; // eax
  int v6; // eax
  char v7; // cl
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax

  LOWORD(v0) = sub_918D5(0);
  v1 = v0;
  if ( byte_19C18E )
  {
    byte_19C18E = 0;
  }
  else
  {
    sub_FE8BE(v0);
    byte_19C1A0 = 0;
    byte_19C1A2 = 0;
    byte_19C18E = 1;
    sub_1172D4();
    sub_124C08();
    sub_123E6C((int)&unk_17CF4A, 1);
    sub_C5BB9();
    sub_FE8BE(v2);
    v3 = sub_1205E6(0, 0, 255);
    sub_FE8BE(v3);
    v4 = sub_132C80(100);
    sub_FE8BE(v4);
    v5 = sub_81D73();
    v6 = sub_FE8BE(v5);
    if ( v1 )
    {
      v7 = 0;
      if ( byte_199BE0 )
      {
        byte_199BE0 = 0;
        v7 = 1;
      }
      sub_FE8BE(v6);
      sub_83669(word_192FDE[0]);
      if ( v7 )
        byte_199BE0 = 1;
    }
    v8 = sub_124D41();
    v9 = sub_84E9D(v8);
    sub_FE8BE(v9);
    v10 = sub_131922(0, 255);
    sub_1077D(v10);
    sub_123E6C((int)&unk_17CF00, 1);
    if ( byte_199F38 && !sub_918D5(2) )
    {
      sub_C5B94(0);
    }
    else
    {
      sub_C5C44();
      sub_FE8BE(v11);
    }
    byte_199F38 = 0;
    sub_1172FC();
  }
}
// 8A6E2: variable 'v0' is possibly undefined
// 8A71F: variable 'v2' is possibly undefined
// 8A7CA: variable 'v11' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 84E9D: using guessed type int __fastcall sub_84E9D(_DWORD);
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 192FDE: using guessed type int16_t word_192FDE[];
// 199BE0: using guessed type char byte_199BE0;
// 199F38: using guessed type char byte_199F38;
// 19C18E: using guessed type char byte_19C18E;
// 19C1A0: using guessed type char byte_19C1A0;
// 19C1A2: using guessed type char byte_19C1A2;


//----- (0008A7FC) --------------------------------------------------------
int __fastcall sub_8A7FC(int a1)
{
  int v1; // edi
  int result; // eax
  int v3; // kr00_4
  char *v4; // esi

  v1 = a1;
  LOBYTE(a1) = byte_199CAE;
  v3 = a1;
  result = (uint8_t)byte_199CAE;
  switch ( byte_199CAE )
  {
    case 1:
      v4 = aFp;
      break;
    case 2:
      v4 = aPr;
      break;
    case 3:
      v4 = aPi;
      break;
    case 4:
      v4 = aPr;
      break;
    default:
      result = v3;
      v4 = aRp;
      break;
  }
  *(_WORD *)v1 = *(_WORD *)v4;
  *(_BYTE *)(v1 + 2) = v4[2];
  return result;
}
// 199CAE: using guessed type char byte_199CAE;


//----- (0008A84B) --------------------------------------------------------
void __usercall sub_8A84B(char *a1, int16_t *a2)
{
  int16_t v2; // ax
  char v3; // dh
  int16_t v4; // ax

  *a1 = 0;
  sub_8B17B(a1, (int)a1, a2);
  if ( word_199A0E != 1 )
  {
    sub_82348();
    word_199966 = -1;
    word_19995C = -1;
    word_1999F2 = -1;
    word_1999F4 = -1;
    sub_89F8A();
    sub_8A503();
    sub_A0305();
    if ( byte_199F3A != 1 && ((uint8_t)sub_91999(2) || sub_918D5(2)) )
    {
      sub_789D4();
      word_1999B8 = v2;
      if ( v2 == -1 )
      {
        sub_91A40();
        byte_199BD5 = 0;
        word_199BD3 = word_1992C4;
      }
    }
    sub_1172D4();
    sub_1191CA((int)sub_84555, 2);
    sub_91999(0);
    v3 = sub_91999(2);
    sub_9191D();
    if ( v3 || sub_918D5(2) )
      sub_71B1C();
    if ( v3 )
    {
      sub_789D4();
      word_1999B8 = v4;
      if ( v4 == -1 )
      {
        word_193016 = word_1992C4;
      }
      else
      {
        word_193016 = 1;
        sub_8A6C2();
        byte_19C1A2 = 0;
      }
    }
    sub_1172FC();
  }
}
// 8A8CF: variable 'v2' is possibly undefined
// 8A942: variable 'v4' is possibly undefined
// 193016: using guessed type int16_t word_193016;
// 1992C4: using guessed type int16_t word_1992C4;
// 19995C: using guessed type int16_t word_19995C;
// 199966: using guessed type int16_t word_199966;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999F2: using guessed type int16_t word_1999F2;
// 1999F4: using guessed type int16_t word_1999F4;
// 199A0E: using guessed type int16_t word_199A0E;
// 199BD3: using guessed type int16_t word_199BD3;
// 199BD5: using guessed type char byte_199BD5;
// 199F3A: using guessed type char byte_199F3A;
// 19C1A2: using guessed type char byte_19C1A2;


//----- (0008A97A) --------------------------------------------------------
int __usercall sub_8A97A(int16_t *a1)
{
  int v1; // ebx
  int i; // edx
  int v3; // eax
  int16_t *v4; // edi
  int16_t v5; // ax
  int v6; // eax
  int16_t v7; // ax
  int16_t v9; // [esp+0h] [ebp-Ch]
  char v10; // [esp+4h] [ebp-8h]
  char v11; // [esp+8h] [ebp-4h]

  v10 = byte_199BE0;
  v11 = 0;
  sub_78B93(word_192248[word_1999B8]);
  if ( byte_199BE0 )
    byte_199BE0 = 0;
  sub_1191CA((int)sub_84E9D, 1);
  sub_11C2F0();
  sub_91A40();
  sub_1172D4();
  sub_124D41();
  v1 = 639;
  i = 0;
  sub_128C32(0, 0, 639, 479, 0);
  LOWORD(v3) = sub_84E9D();
  sub_1077D(v3, 0, 639, a1);
  sub_1172FC();
  v4 = (int16_t *)sub_C8D49();
  if ( (int16_t)v4 > -1 )
  {
    LOBYTE(v1) = 0;
    for ( i = 0; (int16_t)i < word_199BB8 && !(_BYTE)v1; ++i )
    {
      v5 = sub_78013(i);
      if ( *(_BYTE *)(129 * v5 + dword_197F9C + 17) == 4 )
      {
        LOBYTE(v1) = 1;
        v9 = v5;
      }
    }
    if ( (_BYTE)v1 )
    {
      sub_E607F();
      i = dword_197F9C;
      *(_BYTE *)(dword_197F9C + 129 * v9 + 100) = 5;
      if ( word_199BB8 == 1 )
        v11 = 1;
      word_199A06 = -1;
      --word_1999FE;
    }
  }
  if ( !v11 )
  {
    sub_124D41();
    sub_84A95(1);
    sub_84555(v4);
    sub_1077D(v6, i, v1, v4);
    sub_585E0(word_19999C, i);
    word_193016 = 1;
    sub_A0305();
    word_19995C = -1;
    sub_789D4();
    word_1999B8 = v7;
    if ( v7 == -1 )
      sub_91A40();
  }
  byte_199BE0 = v10;
  word_199A08 = word_199A10;
  sub_11C2F0();
  sub_119281();
  return sub_A20CD();
}
// 8AA25: variable 'v3' is possibly undefined
// 8AA8E: variable 'v9' is possibly undefined
// 8AADB: variable 'v6' is possibly undefined
// 8AB08: variable 'v7' is possibly undefined
// 192248: using guessed type int16_t word_192248[500];
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 193016: using guessed type int16_t word_193016;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 197F9C: using guessed type int dword_197F9C;
// 19995C: using guessed type int16_t word_19995C;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999FE: using guessed type int16_t word_1999FE;
// 199A06: using guessed type int16_t word_199A06;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BE0: using guessed type char byte_199BE0;


//----- (0008AB6D) --------------------------------------------------------
void sub_8AB6D()
{
  int16_t *v0; // edi
  int v1; // ecx
  int v2; // ebx
  int i; // edx
  int16_t v4; // si
  int v5; // eax
  void *v6; // eax
  int v7; // eax
  int v8; // eax
  int16_t v9; // [esp+0h] [ebp-8h]
  int16_t v10; // [esp+4h] [ebp-4h]

  sub_11C2F0();
  sub_89F8A();
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_822AF();
  sub_12B65C();
  sub_128BE7();
  v9 = sub_114C72(asc_1797E0, 22);
  v10 = sub_11438B(22, 22, 506, 400, byte_1797E2, 41);
  v0 = (int16_t *)sub_11438B(0, 0, 639, 479, byte_1797E2, 0);
  sub_1191CA((int)sub_8AF4E, 2);
  word_199836 = -1;
  word_199838 = -1;
  sub_124D41();
  sub_84A95(0);
  sub_1318D4(0, 255);
  sub_133237();
  sub_90006(0, 0, 21, 479);
  sub_90006(0, 0, 639, 21);
  sub_90006(527, 0, 639, 479);
  v1 = 479;
  v2 = 527;
  i = 421;
  v4 = 0;
  sub_90006(21, 421, 527, 479);
  sub_124DEC();
  byte_199F09 = -1;
  while ( !v4 )
  {
    sub_12C2A0();
    v2 = sub_1171AB(v5, i, v2, v1);
    word_1999BC = (uint16_t)sub_114177();
    if ( word_199836 == -1 )
      v6 = &unk_1821CC;
    else
      v6 = &unk_182208;
    sub_123E6C((int)v6, 5);
    v1 = (int16_t)v2;
    for ( i = 0; (int16_t)i < word_19999A; ++i )
    {
      if ( (_WORD)v2 == word_190208[(int16_t)i] )
      {
        word_199836 = i;
      }
      else if ( -word_190208[(int16_t)i] == (int16_t)v2 )
      {
        v4 = 1;
      }
    }
    if ( (_WORD)v2 == (_WORD)v0
      || (i = -(int16_t)v0, (int16_t)v2 == i)
      || (i = -v10, (int16_t)v2 == i)
      || (int16_t)v2 == -1009
      || (_WORD)v2 == v9 )
    {
      v4 = 1;
    }
    if ( !v4 )
    {
      v7 = sub_124D41();
      sub_8AF4E(v7);
      sub_1077D(v8, i, v2, v0);
    }
    sub_12C2C6(1);
  }
  sub_123E6C((int)&unk_17CF00, 1);
  word_199A08 = 0;
  JUMPOUT(0x8AB3C);
}
// 8AD7D: control flows out of bounds to 8AB3C
// 8ACA2: variable 'v5' is possibly undefined
// 8AD51: variable 'v8' is possibly undefined
// 1797E2: using guessed type _BYTE byte_1797E2[2];
// 190208: using guessed type int16_t word_190208[72];
// 199836: using guessed type int16_t word_199836;
// 199838: using guessed type int16_t word_199838;
// 19999A: using guessed type int16_t word_19999A;
// 1999BC: using guessed type int16_t word_1999BC;
// 199A08: using guessed type int16_t word_199A08;
// 199F09: using guessed type char byte_199F09;


//----- (0008AD82) --------------------------------------------------------
void __usercall sub_8AD82(int16_t *a1)
{
  _BOOL1 v1; // dl
  char *v2; // eax
  int v3; // ebx
  int v4; // ecx
  int16_t *v5; // edi
  int v6; // eax
  int v7; // [esp-Ch] [ebp-6Ch]
  int v8; // [esp-8h] [ebp-68h]
  int v9; // [esp-4h] [ebp-64h]
  _BYTE v10[80]; // [esp+0h] [ebp-60h] BYREF
  char v11[8]; // [esp+50h] [ebp-10h] BYREF
  int16_t v12; // [esp+58h] [ebp-8h] BYREF
  char v13[4]; // [esp+5Ch] [ebp-4h] BYREF

  byte_19C1A1 = 1;
  byte_199F09 = 0;
  sub_8A84B(v13, a1);
  byte_19C19D = 39;
  v1 = sub_77EED();
  if ( byte_199BDD || v13[0] || byte_1AB124[word_19999C] || !byte_19C198 || byte_199F3A || v1 )
  {
    byte_19C194 = 0;
    sub_123E6C((int)&unk_17CF00, 1);
    byte_19C198 = 0;
    sub_11C2F0();
  }
  else
  {
    word_199988 = -1;
    byte_19C194 = 1;
    sub_1172D4();
    sub_1191CA((int)sub_84E9D, 1);
    sub_124D41();
    sub_84E9D();
    sub_79138(word_19999C, 3u, v11, 0);
    sub_120BB5(3, (int)v11);
    v9 = dword_192FD8 % 10;
    v8 = dword_192FD8 / 10;
    v7 = 3753 * word_19999C + dword_197F98 + 21;
    v2 = sub_7A990(0xE9u);
    sprintf(v10, v2, v7, v8, v9);
    v3 = (int16_t)(sub_12066F((int)v10) + 8);
    v4 = (int16_t)(sub_122259() + 4);
    sub_1318D4(0, 255);
    sub_133237();
    sub_8F055((506 - v3) / 2 + 21, (400 - v4) / 2 + 21, v3, v4, v11[1]);
    v5 = (int16_t *)((400 - v4) / 2 + 27);
    v6 = sub_1212B3((506 - v3) / 2 + 29, (int16_t)v5, (int)v10);
    sub_1077D(v6, (int16_t)v5, (int)v10, v5);
    sub_1172FC();
    sub_83411(&v12, 1, (int)v10);
  }
  byte_19C1A1 = 0;
  JUMPOUT(0x8AB3C);
}
// 8AF49: control flows out of bounds to 8AB3C
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 199988: using guessed type int16_t word_199988;
// 19999C: using guessed type int16_t word_19999C;
// 199BDD: using guessed type char byte_199BDD;
// 199F09: using guessed type char byte_199F09;
// 199F3A: using guessed type char byte_199F3A;
// 19C194: using guessed type char byte_19C194;
// 19C198: using guessed type char byte_19C198;
// 19C19D: using guessed type char byte_19C19D;
// 19C1A1: using guessed type char byte_19C1A1;


//----- (0008AF4E) --------------------------------------------------------
void __fastcall sub_8AF4E(int a1)
{
  int v1; // ecx
  int v2; // eax
  int v3; // ebx
  char *v4; // eax
  int16_t v5; // ax
  char v6[80]; // [esp+0h] [ebp-7Ch] BYREF
  _BYTE v7[16]; // [esp+50h] [ebp-2Ch] BYREF
  int16_t v8; // [esp+60h] [ebp-1Ch] BYREF
  int16_t v9; // [esp+64h] [ebp-18h] BYREF
  int16_t v10; // [esp+68h] [ebp-14h] BYREF
  int i; // [esp+6Ch] [ebp-10h]
  int v12; // [esp+70h] [ebp-Ch]
  int v13; // [esp+74h] [ebp-8h] BYREF
  char v14; // [esp+78h] [ebp-4h]

  LOWORD(a1) = word_199836;
  v12 = a1;
  qmemcpy(v7, "LPNPPPPPprqrrrrr", sizeof(v7));
  sub_84E9D();
  sub_8440E();
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  byte_199F09 = word_199838;
  if ( (int16_t)v12 > -1 )
  {
    sub_86076(v12);
    v14 = 0;
    for ( i = 0; (int16_t)i < word_19999A && !v14; ++i )
    {
      if ( word_190208[(int16_t)i] == word_1999BC && (_WORD)i != (_WORD)v12 )
      {
        v14 = 1;
        word_199838 = i;
      }
      if ( word_199838 > -1 && (_WORD)v12 != word_199838 && byte_199F09 == word_199838 )
      {
        v1 = (int16_t)v12;
        sub_85B93(v12, &v8, &v9);
        sub_85B93(word_199838, &v13, &v10);
        sub_EBEB7(v1, word_199838);
        v3 = v2;
        if ( (uint16_t)sub_1276F0(113 * v1 + dword_19306C + 31, word_199838) )
        {
          sub_120DED(0, 0);
          sub_120D79(2, (int)v7);
          strcpy(v6, sub_7A990(0xEAu));
          sub_8EBBB(1);
        }
        else
        {
          sub_120DED(0, 0);
          sub_120D79(2, (int)&v7[8]);
          v4 = sub_7A990(0xEBu);
          sprintf(v6, v4, v3);
        }
        v5 = sub_12066F((int)v6);
        if ( (int16_t)v13 + 10 + v5 <= 522 )
          sub_1212B3(v13 + 10, v10, (int)v6);
        else
          sub_1210B7(522, v10, (int)v6);
        sub_A11C0(v8, v9, v13, v10, (int)&unk_182135, word_19995E);
      }
    }
  }
  word_19995E = (word_19995E + 1) % 8;
  sub_12B65C();
  sub_128BE7();
  JUMPOUT(0x8AB3C);
}
// 8B176: control flows out of bounds to 8AB3C
// 8B053: variable 'v2' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 190208: using guessed type int16_t word_190208[72];
// 19306C: using guessed type int dword_19306C;
// 199836: using guessed type int16_t word_199836;
// 199838: using guessed type int16_t word_199838;
// 19995E: using guessed type int16_t word_19995E;
// 19999A: using guessed type int16_t word_19999A;
// 1999BC: using guessed type int16_t word_1999BC;
// 199F09: using guessed type char byte_199F09;


//----- (0008B17B) --------------------------------------------------------
void __usercall sub_8B17B(char *a1, int a2, int16_t *a3)
{
  int v4; // eax
  char v5; // al
  _BOOL1 v6; // dl
  char v7; // dh

  *a1 = sub_FE86B(word_19999C, a3);
  if ( dword_1975B8 && dword_1975B8 != dword_192FD8 )
    byte_19C18E = 0;
  if ( *a1 )
  {
    byte_199F2C = 1;
    byte_199F1D = -1;
    sub_1191CA((int)sub_84E9D, 1);
    if ( dword_1975B8 != dword_192FD8 )
    {
      if ( sub_860C3() )
      {
        sub_124D41();
        LOWORD(v4) = sub_84E9D();
        sub_1077D(v4, 1, a2, a3);
      }
      else
      {
        sub_8A6C2();
      }
      dword_1975B8 = dword_192FD8;
    }
    while ( 1 )
    {
      byte_19C18E = 0;
      sub_A20EC();
      sub_A20CD();
      sub_82348();
      sub_FE785(a3);
      byte_199F17 = v5;
      v6 = v5 == 2 || v5 == 5 || v5 == 6 || v5 == 7 && byte_199BE5;
      if ( word_199A0E == 1 )
        break;
      v7 = sub_FE86B(word_19999C, a3);
      if ( v6 && v7 != 3 )
      {
        byte_19D32C = sub_918D5(0);
        sub_8A6C2();
        byte_19C18E = 1;
      }
      if ( !v7 )
      {
        sub_1191CA((int)sub_84555, 1);
        return;
      }
    }
  }
  else if ( byte_199F39 )
  {
    if ( sub_918D5(2) || sub_918D5(0) )
      byte_19C1A2 = 1;
    byte_199F39 = 0;
  }
}
// 8B1F6: variable 'v4' is possibly undefined
// 8B22C: variable 'v5' is possibly undefined
// 192FD8: using guessed type int dword_192FD8;
// 1975B8: using guessed type int dword_1975B8;
// 19999C: using guessed type int16_t word_19999C;
// 199A0E: using guessed type int16_t word_199A0E;
// 199BE5: using guessed type char byte_199BE5;
// 199F17: using guessed type char byte_199F17;
// 199F1D: using guessed type char byte_199F1D;
// 199F2C: using guessed type char byte_199F2C;
// 199F39: using guessed type char byte_199F39;
// 19C18E: using guessed type char byte_19C18E;
// 19C1A2: using guessed type char byte_19C1A2;
// 19D32C: using guessed type char byte_19D32C;


//----- (0008B2DE) --------------------------------------------------------
void sub_8B2DE()
{
  int16_t *v0; // eax
  int16_t *v1; // edi
  int v2; // ecx
  int v3; // ebx
  int v4; // eax
  int i; // edx
  int16_t v6; // ax
  int16_t v7; // si
  int16_t v8; // ax
  int v9; // eax
  int16_t v10; // ax
  int16_t v11; // [esp+8h] [ebp-Ch]
  char v12; // [esp+Ch] [ebp-8h]
  char v13; // [esp+10h] [ebp-4h]

  v13 = 0;
  LOWORD(v0) = sub_78B93(word_192248[word_1999B8]);
  v1 = v0;
  v12 = 0;
  sub_9222A((int16_t)v0);
  if ( byte_199BE0 )
    byte_199BE0 = 0;
  sub_1191CA((int)sub_84E9D, 1);
  sub_11C2F0();
  sub_91A40();
  sub_1172D4();
  sub_124D41();
  v2 = 479;
  v3 = 639;
  sub_128C32(0, 0, 639, 479, 0);
  LOWORD(v4) = sub_84E9D();
  sub_1077D(v4, 0, 639, v1);
  sub_1172FC();
  i = 1;
  sub_C8DB8((int16_t)v1, 1);
  v7 = v6;
  if ( v6 > -1 )
  {
    LOBYTE(v2) = 0;
    for ( i = 0; (int16_t)i < word_199BB8 && !(_BYTE)v2; ++i )
    {
      v8 = sub_78013(i);
      v3 = 129 * v8 + dword_197F9C;
      if ( *(_BYTE *)(v3 + 17) == 1 )
      {
        LOBYTE(v2) = 1;
        v11 = v8;
      }
    }
    if ( (_BYTE)v2 )
    {
      if ( byte_199BE2 )
        v12 = 1;
      i = word_19999C;
      sub_E6071(v7, word_19999C);
      v3 = dword_197F9C;
      *(_BYTE *)(dword_197F9C + 129 * v11 + 100) = 5;
      if ( word_199BB8 == 1 )
        v13 = 1;
      word_199A06 = -1;
      --word_1999FE;
    }
  }
  if ( v12 )
  {
    i = (int)&byte_199F28;
    word_199830 = (int16_t)v1;
    v3 = 0;
    word_199832 = sub_783ED(v7);
    sub_B9802((int)&byte_199F28, v2, v1);
    sub_8F1C4((void (__fastcall *)(int, int))sub_84E9D, &byte_199F28, 0);
  }
  if ( !v13 )
  {
    sub_124D41();
    sub_84A95(1);
    sub_84555(v1);
    sub_1077D(v9, i, v3, v1);
    sub_585E0(word_19999C, i);
    word_193016 = 1;
    sub_A0305();
    sub_789D4();
    word_1999B8 = v10;
    if ( v10 == -1 )
      sub_91A40();
  }
  JUMPOUT(0x8AB1C);
}
// 8B4C7: control flows out of bounds to 8AB1C
// 8B30C: variable 'v0' is possibly undefined
// 8B392: variable 'v4' is possibly undefined
// 8B3A9: variable 'v6' is possibly undefined
// 8B411: variable 'v11' is possibly undefined
// 8B48F: variable 'v9' is possibly undefined
// 8B4B3: variable 'v10' is possibly undefined
// 192248: using guessed type int16_t word_192248[500];
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 193016: using guessed type int16_t word_193016;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 197F9C: using guessed type int dword_197F9C;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999FE: using guessed type int16_t word_1999FE;
// 199A06: using guessed type int16_t word_199A06;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BE0: using guessed type char byte_199BE0;
// 199BE2: using guessed type char byte_199BE2;
// 199F28: using guessed type char byte_199F28;


//----- (0008B519) --------------------------------------------------------
void sub_8B519()
{
  int16_t v0; // di
  int16_t v1; // si
  int v2; // eax
  char *v3; // eax
  int16_t v4; // dx
  int16_t v5; // cx
  int v6; // eax
  uint16_t v7; // ax
  uint16_t v8; // ax
  char *v9; // eax
  uint16_t v10; // ax
  char *v11; // eax
  int64_t v12; // rax
  int v13; // eax
  int16_t v14; // cx
  int v15; // eax
  int v16; // edi
  int v17; // [esp-10h] [ebp-26Ch]
  char *v18; // [esp-Ch] [ebp-268h]
  char *v19; // [esp-4h] [ebp-260h]
  char *v20; // [esp-4h] [ebp-260h]
  _BYTE v21[200]; // [esp+0h] [ebp-25Ch] BYREF
  _BYTE v22[200]; // [esp+C8h] [ebp-194h] BYREF
  char v23[200]; // [esp+190h] [ebp-CCh] BYREF
  _BOOL1 v24; // [esp+258h] [ebp-4h]

  v24 = sub_918D5(2);
  v0 = 1;
  v1 = sub_FF477(word_19999C);
  if ( v1 > 0 )
  {
    sub_1191CA((int)sub_84E9D, 1);
    sub_6F83B();
    sub_11C2F0();
    word_193016 = 0;
    sub_1172D4();
    sub_124D41();
    sub_128C32(0, 0, 639, 479, 0);
    LOWORD(v2) = sub_84E9D();
    sub_1077D(v2, 0, 639, (int16_t *)1);
    sub_1172FC();
    v3 = sub_7A990(0xEDu);
    v4 = sub_C9EB0(0, v1, (int)v3, 0, (int16_t *)1, 0);
    v5 = v4;
    if ( v4 >= 0 )
    {
      v6 = 3753 * word_19999C + dword_197F98;
      if ( *(int16_t *)(v6 + 54) - v4 <= 0 || *(int16_t *)(v6 + 56) - v4 <= 0 )
      {
        if ( v4 == 1 )
          v7 = 240;
        else
          v7 = 241;
        v19 = sub_7A990(v7);
        if ( *(_WORD *)(dword_197F98 + 3753 * word_19999C + 56) == 1 )
          v8 = 240;
        else
          v8 = 241;
        v18 = sub_7A990(v8);
        v17 = *(int16_t *)(dword_197F98 + 3753 * word_19999C + 56);
        v9 = sub_7A990(0xEEu);
        sprintf(v22, v9, v17, v18, v4, v19);
        v0 = sub_7A25F(&byte_199F28, (int)v22, 1);
      }
    }
    if ( v0 && v5 > 0 )
    {
      if ( v5 == 1 )
        v10 = 240;
      else
        v10 = 241;
      v20 = sub_7A990(v10);
      v11 = sub_7A990(0xEFu);
      v12 = sprintf(v21, v11, v5, v20);
      sub_7A25F(&byte_199F28, SHIDWORD(v12), 0);
      v13 = *(int16_t *)(3753 * word_19999C + dword_197F98 + 54) - v5;
      if ( v13 <= 0 )
        LOWORD(v13) = 0;
      v14 = v13;
      v15 = word_19999C;
      v16 = dword_197F98;
      *(_WORD *)(3753 * word_19999C + dword_197F98 + 54) = v14;
      sub_E2D72(v15, v16);
    }
  }
  else
  {
    strcpy(v23, sub_7A990(0xE6u));
    sub_7A25F(&byte_199F28, (int)v23, 3);
  }
  word_199A08 = word_199A10;
  if ( v24 )
    word_193016 = 1;
  sub_11C2F0();
  sub_119281();
  JUMPOUT(0x8AB3C);
}
// 8B7A0: control flows out of bounds to 8AB3C
// 8B5F0: variable 'v2' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 193016: using guessed type int16_t word_193016;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199F28: using guessed type char byte_199F28;


//----- (0008B7A5) --------------------------------------------------------
int __usercall sub_8B7A5(int16_t *a1)
{
  int16_t v1; // ax
  int16_t v2; // si
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  int16_t v6; // ax
  int16_t v7; // ax
  int v8; // ecx
  int v9; // eax
  int16_t v10; // ax
  int16_t v12[500]; // [esp+0h] [ebp-3F0h] BYREF
  int16_t v13; // [esp+3E8h] [ebp-8h]
  char v14; // [esp+3ECh] [ebp-4h]

  v13 = (uint8_t)byte_199BE0;
  v1 = word_192248[word_1999B8];
  v14 = 0;
  v2 = sub_78B93(v1);
  if ( byte_199BE0 )
    byte_199BE0 = 0;
  sub_1191CA((int)sub_84E9D, 1);
  sub_11C2F0();
  sub_91A40();
  sub_1172D4();
  sub_124D41();
  v3 = 639;
  v4 = 0;
  sub_128C32(0, 0, 639, 479, 0);
  LOWORD(v5) = sub_84E9D();
  sub_1077D(v5, 0, 639, a1);
  sub_1172FC();
  sub_C8D3C(v2);
  if ( v6 > -1 )
  {
    v4 = 17 * v6;
    v7 = *(_WORD *)(v4 + dword_1930D4);
    if ( v7 > -1 )
    {
      v8 = 361 * v7;
      if ( *(char *)(v8 + dword_192B18) == word_19999C )
      {
        v3 = (int16_t)sub_7802A((int)v12, 500);
        v4 = (int)v12;
        if ( (uint16_t)sub_ED6B7((char *)(v8 + dword_192B18), v12, v3) == word_199BB8 )
          v14 = 1;
        word_199A06 = -1;
        --word_1999FE;
      }
    }
  }
  if ( !v14 )
  {
    sub_8A4C4();
    sub_124D41();
    sub_84A95(1);
    sub_84555(a1);
    sub_1077D(v9, v4, v3, a1);
    sub_585E0(word_19999C, v4);
    word_193016 = 1;
    sub_789D4();
    word_1999B8 = v10;
    if ( v10 == -1 )
      sub_91A40();
  }
  byte_199BE0 = v13;
  word_199A08 = word_199A10;
  sub_11C2F0();
  sub_119281();
  return sub_A20CD();
}
// 8B84E: variable 'v5' is possibly undefined
// 8B860: variable 'v6' is possibly undefined
// 8B8FD: variable 'v9' is possibly undefined
// 8B91C: variable 'v10' is possibly undefined
// 192248: using guessed type int16_t word_192248[500];
// 192B18: using guessed type int dword_192B18;
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 193016: using guessed type int16_t word_193016;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 1930D4: using guessed type int dword_1930D4;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999FE: using guessed type int16_t word_1999FE;
// 199A06: using guessed type int16_t word_199A06;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199BB8: using guessed type int16_t word_199BB8;
// 199BE0: using guessed type char byte_199BE0;


//----- (0008B956) --------------------------------------------------------
void __usercall sub_8B956(int16_t *a1)
{
  uint8_t v1; // al
  int16_t v2; // bx
  char v3; // cl

  word_199A08 = 0;
  v1 = sub_FE86B(word_19999C, a1);
  v2 = v1;
  v3 = 0;
  if ( v1 )
    sub_123E6C((int)&unk_17CF00, 1);
  sub_124C08();
  sub_1191CA((int)sub_84E9D, 1);
  if ( !dword_1975B8 )
  {
    if ( v2 == 2 || v2 == 3 || v2 == 5 || v2 == 6 || v2 == 7 && byte_199BE5 )
    {
      v3 = 0;
      goto LABEL_14;
    }
LABEL_13:
    v3 = 1;
    goto LABEL_14;
  }
  if ( byte_199F17 == 3 && v2 != 3 )
    goto LABEL_13;
LABEL_14:
  if ( v2 != 3 || byte_199F19 == 10 )
  {
    if ( byte_199F39 && v2 )
      v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  if ( v3 && !byte_19C18E )
  {
    byte_199F39 = 0;
    sub_82348();
    sub_11C2F0();
    sub_89F8A();
    sub_8A503();
    sub_A0305();
    sub_C5BB9();
    sub_81D73();
    sub_8A6C2();
  }
  sub_8AD82(a1);
  if ( word_199A08 == 1 )
    word_199A10 = 39;
  if ( byte_199F2C )
  {
    byte_19C1A0 = 1;
    sub_A20CD();
  }
  else
  {
    byte_19C1A0 = 0;
  }
  if ( sub_918D5(2) && byte_199F2C )
  {
    byte_19C1A2 = 1;
    byte_199F38 = 1;
  }
  if ( !v2 )
    dword_1975B8 = dword_192FD8;
  sub_119281();
}
// 192FD8: using guessed type int dword_192FD8;
// 1975B8: using guessed type int dword_1975B8;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199BE5: using guessed type char byte_199BE5;
// 199F17: using guessed type char byte_199F17;
// 199F19: using guessed type char byte_199F19;
// 199F2C: using guessed type char byte_199F2C;
// 199F38: using guessed type char byte_199F38;
// 199F39: using guessed type char byte_199F39;
// 19C18E: using guessed type char byte_19C18E;
// 19C1A0: using guessed type char byte_19C1A0;
// 19C1A2: using guessed type char byte_19C1A2;


//----- (0008BAB9) --------------------------------------------------------
int16_t __usercall sub_8BAB9(int16_t *a1)
{
  int v1; // eax
  int16_t result; // ax

  sub_1196F7();
  sub_1191CA((int)sub_84E9D, 1);
  sub_11C2F0();
  sub_11438B(0, 0, 639, 479, asc_1797E0, 41);
  sub_1172D4();
  sub_124D41();
  sub_128C32(0, 0, 639, 479, 0);
  LOWORD(v1) = sub_84E9D();
  sub_1077D(v1, 0, 639, a1);
  sub_1172FC();
  sub_E2644(word_19999C);
  result = word_199A10;
  word_199A08 = word_199A10;
  return result;
}
// 8BB13: variable 'v1' is possibly undefined
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;


//----- (0008BB51) --------------------------------------------------------
void sub_8BB51()
{
  int16_t i; // dx
  char v1; // cl
  int16_t v2; // si
  unsigned int v3; // eax
  int v4; // ebx
  int v5; // eax
  int16_t v6; // [esp+0h] [ebp-4h]

  for ( i = 0; i < word_19999A; ++i )
  {
    if ( *(_BYTE *)(113 * i + dword_19306C + 40) == 8 )
    {
      v6 = -1;
      v1 = 0;
      v2 = 0;
      do
      {
        v3 = sub_1247A0(0x26u) - 1;
        if ( (_WORD)v3 == 65 || *(char *)(dword_1930DC + 59 * (int16_t)v3 + 57) != -1 )
        {
          ++v2;
        }
        else
        {
          v1 = 1;
          v6 = v3;
        }
        if ( v2 == 100 )
          v1 = 1;
      }
      while ( !v1 );
      if ( v6 == -1 )
      {
        *(_BYTE *)(113 * i + dword_19306C + 40) = 0;
      }
      else
      {
        v4 = 59 * (int16_t)v3;
        v5 = dword_1930DC;
        *(_BYTE *)(v4 + dword_1930DC + 57) = 5;
        *(_WORD *)(v4 + v5 + 53) = i;
      }
    }
  }
}
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 19999A: using guessed type int16_t word_19999A;


//----- (0008BC03) --------------------------------------------------------
void sub_8BC03()
{
  int16_t i; // dx
  int v1; // eax
  int v2; // ebx

  for ( i = 0; i < word_19999A; ++i )
  {
    v1 = 0;
    do
    {
      v2 = (int16_t)v1++;
      *(_WORD *)(113 * i + dword_19306C + 2 * v2 + 74) = -1;
    }
    while ( (int16_t)v1 < 5 );
  }
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (0008BC39) --------------------------------------------------------
void __fastcall sub_8BC39(int a1)
{
  int16_t i; // ax
  int v2; // ecx
  int16_t *v3; // eax
  uint8_t v4; // bl
  int v5; // edx
  int16_t v6; // dx
  int16_t j; // bx
  int16_t v8; // ax
  int v9; // eax
  int16_t v10; // [esp+0h] [ebp-54h]
  _BYTE v11[72]; // [esp+4h] [ebp-50h] BYREF
  int v12; // [esp+4Ch] [ebp-8h]
  int v13; // [esp+50h] [ebp-4h]

  LOWORD(a1) = word_1999A2;
  v12 = a1;
  v13 = sub_8BE4D();
  if ( word_1999A2 - (int16_t)v13 >= v10 )
  {
    memset(v11, 0, sizeof(v11));
    for ( i = 0; i < 8; ++i )
    {
      if ( i < word_199998 )
        v11[*(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(3753 * i + dword_197F98 + 41) + 2)] = 1;
    }
    if ( !IsMemPoolReady_110B5C() )
    {
      _wcpp_1_unwind_leave(
        0,
        1,
        "Colony Planets: %d  Max: %d  Planet Count: %d  Removing %d planets",
        word_1999A2 - (int16_t)v13,
        v10,
        word_1999A2,
        word_1999A2 - (int16_t)v13 - v10);
      sub_6497C();
    }
    dword_19C2D0 = (int)sub_110CEE(dword_192ED4, 6120);
    qmemcpy((void *)dword_19C2D0, (void *)dword_1930D4, 0x17E8u);
    qmemcpy(sub_110D3C(dword_192ED4, 8136), (void *)dword_19306C, 0x1FC8u);
    while ( word_1999A2 - (int16_t)v13 >= v10 )
    {
      v2 = (int16_t)(sub_1247A0(word_1999A2) - 1);
      v3 = (int16_t *)(dword_19C2D0 + 17 * v2);
      v4 = *((_BYTE *)v3 + 2);
      if ( *v3 != -2 && !v11[v4] )
      {
        v5 = *(int16_t *)(dword_19306C + 113 * v4 + 2 * v2 + 74);
        if ( v5 > -1 && *(_BYTE *)(17 * v5 + dword_19C2D0 + 4) != 2 )
        {
          --word_1999A2;
          *v3 = -2;
        }
      }
    }
    sub_8BC03();
    v6 = 0;
    for ( j = 0; j < (int16_t)v12; ++j )
    {
      if ( *(int16_t *)(dword_19C2D0 + 17 * j) != -2 )
      {
        v8 = sub_8CEAC(j);
        if ( v8 != -1 )
          *(_WORD *)(dword_197F98 + 3753 * v8 + 41) = v6;
        _wcpp_1_unwind_leave(0, 10, "Moving planet %d to planet %d", j, v6);
        v9 = 17 * v6;
        qmemcpy((void *)(v9 + dword_1930D4), (void *)(dword_19C2D0 + 17 * j), 0x11u);
        *(_WORD *)(113 * *(uint8_t *)(dword_1930D4 + v9 + 2)
                 + dword_19306C
                 + 2 * *(uint8_t *)(dword_1930D4 + v9 + 3)
                 + 74) = v6++;
      }
    }
  }
  JUMPOUT(0x8BBFC);
}
// 8BE48: control flows out of bounds to 8BBFC
// 8BC5E: variable 'v10' is possibly undefined
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 1999A2: using guessed type int16_t word_1999A2;
// 19C2D0: using guessed type int dword_19C2D0;


//----- (0008BE4D) --------------------------------------------------------
int sub_8BE4D()
{
  int v0; // esi
  int16_t i; // bx
  int16_t j; // cx

  v0 = 0;
  for ( i = 0; i < word_19999A; ++i )
  {
    for ( j = 0; j < 5; ++j )
    {
      if ( *(int16_t *)(113 * i + dword_19306C + 2 * j + 74) > -1 && sub_79CD2(i, j) == 2 )
        ++v0;
    }
  }
  return v0;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (0008BEAB) --------------------------------------------------------
void __fastcall sub_8BEAB( int a1)
{
  char v2; // dl
  int v3; // edi
  int16_t v4; // ax
  int v5; // ebx
  int v6; // esi
  char v7; // dh
  int16_t v8; // cx
  char v9; // dh
  _BYTE v10[12]; // [esp+0h] [ebp-14h] BYREF
  int v11; // [esp+Ch] [ebp-8h]
  int16_t v12; // [esp+10h] [ebp-4h]

  v2 = -1;
  v3 = a1;
  v4 = 0;
  while ( byte_199F2F )
  {
    if ( (uint8_t)byte_199F2F <= 1u )
    {
      v5 = v4;
      v11 = 4 * v4;
      v6 = v11 + a1;
      goto LABEL_7;
    }
    if ( byte_199F2F != 2 )
      goto LABEL_11;
    v5 = v4;
    v11 = 4 * v4;
    v7 = byte_17D7CF[v11 + a1];
LABEL_10:
    v10[v5] = v7;
LABEL_11:
    if ( ++v4 >= 10 )
    {
      if ( byte_19C31A )
      {
        v8 = 0;
        v9 = 0;
        v12 = 0;
        do
        {
          if ( v10[v9] && byte_17D81C[v9] )
          {
            ++v8;
            v12 = v9;
          }
          ++v9;
        }
        while ( v9 < 10 );
        if ( v8 == 1 )
          v2 = v12;
      }
      if ( v2 == -1 )
      {
        if ( byte_19C31A )
        {
          while ( !byte_17D81C[(char)sub_FE8DA((int)v10, 10)] )
            ;
        }
        else
        {
          sub_FE8DA((int)v10, 10);
        }
      }
      JUMPOUT(0x8BBFC);
    }
  }
  v5 = v4;
  v6 = v3 + 4 * v4;
LABEL_7:
  v7 = byte_17D7A7[v6];
  goto LABEL_10;
}
// 8BF9E: control flows out of bounds to 8BBFC
// 199F2F: using guessed type char byte_199F2F;
// 19C31A: using guessed type char byte_19C31A;


//----- (0008BFA3) --------------------------------------------------------
char __fastcall sub_8BFA3( int a1, int a2)
{
  int v3; // edx

  v3 = a1;
  if ( sub_792A9(a1) || *(_BYTE *)(113 * v3 + dword_19306C + 40) == 11 )
    return byte_17D81C[*(uint8_t *)(17 * a2 + dword_1930D4 + 8)];
  else
    return 0;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0008BFE0) --------------------------------------------------------
char __fastcall sub_8BFE0( int a1)
{
  int v1; // eax

  v1 = 17 * a1 + dword_1930D4;
  if ( *(uint8_t *)(v1 + 10) >= 5u )
    return 0;
  else
    return byte_17D72A[5 * *(uint8_t *)(v1 + 10) + *(uint8_t *)(v1 + 5)];
}
// 8BFFE: conditional instruction was optimized away because eax.4<100u
// 1930D4: using guessed type int dword_1930D4;


//----- (0008C01E) --------------------------------------------------------
char __fastcall sub_8C01E( int a1, int a2)
{
  int v3; // edx

  v3 = a1;
  if ( sub_792A9(a1) || *(_BYTE *)(113 * v3 + dword_19306C + 40) == 11 )
    return byte_17D7FC[*(uint8_t *)(17 * a2 + dword_1930D4 + 5)];
  else
    return 0;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0008C05B) --------------------------------------------------------
char __fastcall sub_8C05B( int a1)
{
  int16_t v2; // dx
  uint8_t v3; // al
  int16_t v4; // dx

  v2 = sub_1247A0(0xAu);
  v3 = *(_BYTE *)(dword_19306C + 113 * a1 + 22);
  v4 = v2 - 1;
  if ( v3 > 5u )
    return -1;
  else
    return byte_17D6EE[6 * v4 + (char)v3];
}
// 19306C: using guessed type int dword_19306C;


//----- (0008C099) --------------------------------------------------------
void __usercall sub_8C099(int a1, unsigned int a2)
{
  int16_t v2; // si
  int v3; // ecx
  _WORD *v4; // eax
  int v5; // edx
  int v6; // ebx
  int i; // edx
  int16_t v8; // si
  int v9; // ebx
  int v10; // edx
  int v11; // ebx
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // esi
  int16_t v17; // ax
  int v18; // eax
  _WORD *v19; // eax
  int v20; // eax
  _WORD *v21; // eax
  int16_t j; // si
  _WORD *v23; // eax
  _WORD *v24; // eax
  int16_t v25; // ax
  _WORD *v26; // eax
  int16_t k; // si
  int16_t v28; // ax
  int16_t v29; // ax
  _WORD v30[12]; // [esp+0h] [ebp-Eh]
  _WORD v31[12]; // [esp+18h] [ebp+Ah]
  _BYTE v32[12]; // [esp+30h] [ebp+22h] BYREF
  _WORD v33[4]; // [esp+3Ch] [ebp+2Eh]
  char v34[4]; // [esp+44h] [ebp+36h] BYREF
  _DWORD *v35; // [esp+48h] [ebp+3Ah]
  _DWORD *v36; // [esp+4Ch] [ebp+3Eh]
  int v37; // [esp+50h] [ebp+42h]
  int v38; // [esp+54h] [ebp+46h]
  _DWORD *v39; // [esp+58h] [ebp+4Ah]
  unsigned int v40; // [esp+5Ch] [ebp+4Eh]
  int v41; // [esp+60h] [ebp+52h] BYREF
  int v42; // [esp+64h] [ebp+56h]
  int v43; // [esp+68h] [ebp+5Ah]
  int v44; // [esp+6Ch] [ebp+5Eh]
  int v45; // [esp+70h] [ebp+62h]
  int v46; // [esp+74h] [ebp+66h]
  int v47; // [esp+78h] [ebp+6Ah]
  int v48; // [esp+7Ch] [ebp+6Eh]
  int v49; // [esp+80h] [ebp+72h]
  int v50; // [esp+84h] [ebp+76h]
  int v51; // [esp+88h] [ebp+7Ah]
  char v52; // [esp+8Ch] [ebp+7Eh]

  v45 = 20;
  v41 = 0;
  sub_1112EC(dword_192ED4, (int)&loc_1D4BC + 4);
  v43 = 0;
  v39 = sub_110D3C(dword_192ED4, (int)&loc_1D4BC + 4);
  v2 = 6;
  v36 = sub_110D3C(dword_192ED4, 40000);
  v3 = 0;
  v35 = sub_110D3C(dword_192ED4, 20000);
  sub_FE8BE((int)v35, 20000, a1, (int16_t *)a2);
  do
  {
    HIWORD(v6) = HIWORD(dword_192EF0);
    v4 = sub_126AFD((int)aStarbgLbx_0, v2, dword_192EF0);
    v5 = (int16_t)v3;
    LOWORD(v6) = *v4;
    v31[(int16_t)v3] = *v4;
    v2 += 4;
    ++v3;
    v30[v5] = v4[1];
  }
  while ( (int16_t)v3 < 12 );
  for ( i = 0; ; ++i )
  {
    LOWORD(v4) = (uint8_t)byte_199F0D;
    if ( (int16_t)i >= (uint8_t)byte_199F0D )
      break;
    sub_FE8BE((int)v4, i, v6, (int16_t *)a2);
    v6 = 0;
    do
    {
      v8 = sub_1247A0(0xCu) - 1;
      if ( !v32[v8] )
        a2 = 1;
      if ( (int16_t)++v6 > 240 )
        a2 = 1;
    }
    while ( !(_WORD)a2 );
    v33[(int16_t)i] = v8;
    sub_FE8BE((int16_t)i, i, v6, (int16_t *)a2);
  }
  v9 = v45;
  v10 = sub_7926C(165);
  v48 = v10 + v9;
  v11 = v45;
  v12 = sub_7926C(130);
  v49 = v12 + v11;
  v13 = 400 - v12;
  v14 = 506 - v10;
  v47 = v13;
  v51 = 506 - v10;
  while ( 1 )
  {
    ++v43;
    sub_FE8BE(v14, v10, v13, (int16_t *)a2);
    if ( (int16_t)v43 > 100 )
      break;
    memset(v32, 0, sizeof(v32));
    memset(v34, -1, sizeof(v34));
    memset(v39, 0, (char *)&loc_1D4BC + 4);
    memset(v36, 0, 40000);
    v15 = memset(v35, 0, 20000);
    sub_FE8BE(v15, 0, 20000, (int16_t *)a2);
    v40 = sub_1247A0((int16_t)(506 - v31[0]));
    a2 = sub_1247A0((int16_t)(400 - v30[0]));
    v16 = (int16_t)v40;
    *(_BYTE *)(dword_193068 + 4) = v33[0];
    sub_7927F();
    *(_WORD *)dword_193068 = v17;
    v10 = (int16_t)a2;
    sub_7927F();
    v13 = v18;
    v19 = (_WORD *)dword_193068;
    *(_WORD *)(dword_193068 + 2) = v13;
    if ( (uint8_t)byte_199F0D <= 1u )
      goto LABEL_40;
    v37 = ((int16_t)v45 + (int16_t)v48) * ((int16_t)v45 + (int16_t)v48);
    v38 = ((int16_t)v45 + (int16_t)v49) * ((int16_t)v45 + (int16_t)v49) + v37;
    v13 = 10;
    v41 = 0;
    LOWORD(v20) = sub_8E341(v16, (int16_t)a2, 10, 10, v51, v47, v38, (int)v39, (int16_t *)&v41, 30000);
    sub_FE8BE(v20, (int16_t)a2, 10, (int16_t *)a2);
    LOWORD(v14) = (uint8_t)byte_199F0D;
    if ( (uint8_t)byte_199F0D <= (int16_t)v41 )
    {
      v10 = (int)v36;
      v46 = 1;
      v50 = 0;
      *(_WORD *)v36 = v40;
      v21 = v35;
      *(_WORD *)(v10 + 2) = a2;
      v44 = 0;
      *v21 = 1;
      sub_FE8BE((int)v21, v10, 10, (int16_t *)a2);
      while ( (int16_t)v44 < (int16_t)v41 && !(_WORD)v50 )
      {
        v52 = 1;
        for ( j = 0; j < (int16_t)v46 && !(_WORD)v50 && v52; ++j )
        {
          v23 = &v39[(int16_t)v44];
          LOWORD(v10) = *v23;
          LOWORD(a2) = v23[1];
          v24 = &v36[j];
          v42 = v10;
          LOWORD(v10) = *v24;
          v25 = v24[1];
          if ( (_WORD)v10 != (_WORD)v42 || (_WORD)a2 != v25 )
          {
            v13 = (int16_t)v10;
            v10 = (int16_t)a2;
            if ( sub_7B0FB(v42, a2, v13, v25) < v38 )
              v52 = 0;
          }
        }
        if ( v52 )
        {
          a2 = (unsigned int)&v36[(int16_t)v46];
          v26 = (_WORD *)v35 + (int16_t)v46++;
          qmemcpy((void *)a2, &v39[(int16_t)v44], 4u);
          *v26 = 1;
          if ( (int16_t)v46 >= 10000 )
            v50 = 1;
        }
        ++v44;
      }
      sub_FE8BE(v44, v10, v13, (int16_t *)a2);
      LOWORD(v19) = (uint8_t)byte_199F0D;
      if ( (uint8_t)byte_199F0D <= (int16_t)v46 )
      {
        for ( k = 0; ; ++k )
        {
          LOWORD(v19) = (uint8_t)byte_199F0D;
          if ( k >= (uint8_t)byte_199F0D )
            break;
          v13 = 5 * k;
          a2 = (int16_t)sub_FE92D((int)v35, v46);
          *(_BYTE *)(dword_193068 + v13 + 4) = v33[k];
          sub_7927F();
          *(_WORD *)(v13 + dword_193068) = v28;
          sub_7927F();
          v10 = dword_193068;
          *(_WORD *)(dword_193068 + v13 + 2) = v29;
          v19 = (_WORD *)v35 + a2;
          *v19 = 0;
        }
LABEL_40:
        sub_FE8BE((int)v19, v10, v13, (int16_t *)a2);
        sub_1113CC(dword_192ED4, v10);
        sub_8DA07(v10, v13, (int16_t *)a2);
        JUMPOUT(0x8BBFD);
      }
      sub_FE8BE((int)v19, v10, v13, (int16_t *)a2);
      v13 = 20;
      v14 = (int16_t)v43 / 20;
      v10 = (int16_t)v43 % 20;
      if ( v10 )
        continue;
    }
    v45 -= 10;
  }
  byte_199F0D = 1;
  goto LABEL_40;
}
// 8C4BE: control flows out of bounds to 8BBFD
// 8C13E: variable 'v4' is possibly undefined
// 8C25F: variable 'v17' is possibly undefined
// 8C26C: variable 'v18' is possibly undefined
// 8C2D1: variable 'v20' is possibly undefined
// 8C2EB: variable 'v14' is possibly undefined
// 8C452: variable 'v28' is possibly undefined
// 8C465: variable 'v29' is possibly undefined
// 8C485: variable 'v19' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 192EF0: using guessed type int dword_192EF0;
// 193068: using guessed type int dword_193068;
// 199F0D: using guessed type char byte_199F0D;


//----- (0008C4D3) --------------------------------------------------------
char __fastcall sub_8C4D3( int a1)
{
  unsigned int v1; // eax

  byte_199F0D = 0;
  if ( dword_192EF0 )
  {
    switch ( a1 )
    {
      case 0:
        LOBYTE(a1) = sub_1247A0(2u) - 1;
        goto LABEL_6;
      case 1:
        v1 = 2;
        goto LABEL_5;
      case 2:
        v1 = 3;
LABEL_5:
        LOBYTE(a1) = sub_1247A0(v1);
        goto LABEL_6;
      case 3:
        LOBYTE(a1) = sub_1247A0(3u) + 1;
LABEL_6:
        byte_199F0D = a1;
        break;
      default:
        return a1;
    }
  }
  return a1;
}
// 192EF0: using guessed type int dword_192EF0;
// 199F0D: using guessed type char byte_199F0D;


//----- (0008C527) --------------------------------------------------------
char __fastcall sub_8C527( int a1)
{
  int16_t v2; // cx
  int v3; // eax
  char v4; // dl
  int16_t v5; // cx

  v2 = sub_1247A0(0xAu);
  v3 = 113 * a1 + dword_19306C;
  v4 = 0;
  v5 = v2 - 1;
  if ( *(_BYTE *)(v3 + 22) < 6u )
    return byte_17D680[6 * v5 + *(uint8_t *)(v3 + 22)];
  return v4;
}
// 19306C: using guessed type int dword_19306C;


//----- (0008C567) --------------------------------------------------------
void __fastcall sub_8C567( int a1)
{
  int v1; // eax
  int v2; // edx
  int v3; // ebx
  char v4; // bl
  _DWORD v6[3]; // [esp+4h] [ebp-18h]
  int16_t v7; // [esp+10h] [ebp-Ch]
  char v8; // [esp+12h] [ebp-Ah]
  _BYTE v9[8]; // [esp+14h] [ebp-8h] BYREF

  v1 = 0;
  v6[0] = 302650393;
  v6[1] = 336664084;
  v6[2] = *(int *)((char *)&dword_8BB3C[1] + 1);
  v7 = *(_WORD *)((char *)&dword_8BB3C[2] + 1);
  v8 = HIBYTE(dword_8BB3C[2]);
  do
  {
    v2 = (int16_t)v1;
    v3 = 3 * (int16_t)v1++ + (uint8_t)byte_199CB3;
    v9[v2] = *((_BYTE *)v6 + v3);
  }
  while ( (int16_t)v1 < 5 );
  v4 = 0;
  while ( 1 )
  {
    if ( *(int16_t *)(dword_19306C + 113 * a1 + 2 * (int16_t)sub_FE8DA((int)v9, 5) + 74) == -1 )
      v4 = 1;
    if ( v4 )
      JUMPOUT(0x8BBFC);
  }
}
// 8C5D2: control flows out of bounds to 8BBFC
// 8BB3C: using guessed type int[3];
// 19306C: using guessed type int dword_19306C;
// 199CB3: using guessed type char byte_199CB3;


//----- (0008C5D7) --------------------------------------------------------
int __fastcall sub_8C5D7( int a1)
{
  int16_t v1; // cx
  int16_t v2; // bx
  char v3; // al
  int16_t v4; // ax
  char v5; // al
  char v6; // al
  int16_t v7; // dx
  int16_t v9; // [esp+0h] [ebp-4h]

  v1 = a1;
  *(_BYTE *)(17 * word_1999A2 + dword_1930D4 + 2) = a1;
  *(_BYTE *)(dword_1930D4 + 17 * word_1999A2 + 5) = sub_8C7D1();
  v2 = v1;
  v3 = sub_8C05B(v1);
  *(_BYTE *)(dword_1930D4 + 17 * word_1999A2 + 10) = v3;
  sub_8CD02(v3);
  LOBYTE(v1) = sub_8BFE0(word_1999A2);
  v4 = word_1999A2;
  *(_BYTE *)(17 * word_1999A2 + dword_1930D4 + 6) = v1;
  v9 = sub_8CD55(v4);
  *(_BYTE *)(17 * word_1999A2 + dword_1930D4 + 7) = v9;
  sub_8BEAB(v9);
  *(_BYTE *)(dword_1930D4 + 17 * word_1999A2 + 8) = v5;
  v6 = sub_1247A0(3u);
  v7 = word_1999A2;
  *(_BYTE *)(17 * word_1999A2 + dword_1930D4 + 9) = v6 - 1;
  return sub_8C6C0(v2, v7);
}
// 8C690: variable 'v5' is possibly undefined
// 1930D4: using guessed type int dword_1930D4;
// 1999A2: using guessed type int16_t word_1999A2;


//----- (0008C6C0) --------------------------------------------------------
int __fastcall sub_8C6C0( int a1, int a2)
{
  int v2; // esi
  char v4; // dl
  int result; // eax

  v2 = 17 * a2;
  *(_BYTE *)(v2 + dword_1930D4 + 13) = sub_8C01E(a1, a2);
  v4 = sub_8BFA3(a1, a2);
  result = dword_1930D4;
  *(_WORD *)(v2 + dword_1930D4) = -1;
  *(_BYTE *)(v2 + result + 11) = v4;
  return result;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (0008C6FE) --------------------------------------------------------
int16_t __fastcall sub_8C6FE( int a1, unsigned int a2)
{
  char v4; // dl
  _BOOL1 i; // al
  char v6; // bl
  char v7; // al
  int v8; // eax

  v4 = 0;
  for ( i = 0; !i; i = v4 != 2 || a2 )
  {
    v6 = sub_1247A0(0xAu) - 1;
    word_19C2EE = v6;
    v4 = byte_17D6BC[5 * v6 + a2];
    if ( v4 == 4 )
    {
      v7 = sub_1247A0(0x64u);
      if ( v6 != 1 || v7 >= 11 || a2 )
      {
        v4 = 1;
      }
      else
      {
        v8 = 113 * a1 + dword_19306C;
        word_19C2F2 = 1;
        if ( *(_BYTE *)(v8 + 22) )
          v4 = *(_BYTE *)(v8 + 22) + 4;
        else
          v4 = 5;
      }
    }
  }
  if ( !v4 )
  {
    _wcpp_1_unwind_leave(
      0,
      15,
      "Star %d, orbit %d, has a 0 sat type.  Roll: %d  Table: %d",
      a1,
      a2,
      word_19C2EE,
      (uint8_t)byte_17D6BC[5 * word_19C2EE + a2]);
    sub_6497C();
  }
  return v4;
}
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 19C2EE: using guessed type int16_t word_19C2EE;
// 19C2F2: using guessed type int16_t word_19C2F2;


//----- (0008C7D1) --------------------------------------------------------
char sub_8C7D1()
{
  char v0; // bl
  int16_t v1; // cx
  int16_t i; // ax

  v0 = -1;
  v1 = sub_1247A0(0xAu);
  for ( i = 0; i < 5; ++i )
  {
    if ( v1 <= (uint8_t)byte_17D7F7[i] )
      return i;
  }
  return v0;
}


//----- (0008C807) --------------------------------------------------------
int __fastcall sub_8C807( int a1)
{
  int v2; // edx
  int v3; // eax
  char v4; // bl
  _BYTE v6[8]; // [esp+0h] [ebp-8h] BYREF

  v2 = 0;
  do
  {
    v3 = (int16_t)v2;
    v4 = byte_17D83E[3 * (int16_t)v2++ + a1];
    v6[v3] = v4;
  }
  while ( (int16_t)v2 < 7 );
  return sub_FE8DA((int)v6, 7);
}


//----- (0008C840) --------------------------------------------------------
char __fastcall sub_8C840( int a1, _WORD *a2, _BYTE *a3, int a4, int a5)
{
  char v7; // ch
  int v8; // ebx
  int v9; // eax
  _BYTE *v10; // eax
  int v11; // eax
  int v12; // edx
  int16_t i; // ax
  int v14; // eax
  int v15; // edx
  int v16; // ebx
  int v17; // edx
  char v18; // ch
  int v19; // edx
  int v20; // edx
  char v21; // bl
  _WORD v23[12]; // [esp+0h] [ebp-5Ch] BYREF
  _BYTE v24[12]; // [esp+18h] [ebp-44h] BYREF
  _BYTE v25[12]; // [esp+24h] [ebp-38h] BYREF
  _WORD v26[6]; // [esp+30h] [ebp-2Ch] BYREF
  _WORD *v27; // [esp+3Ch] [ebp-20h]
  int v28; // [esp+40h] [ebp-1Ch]
  int v29; // [esp+44h] [ebp-18h]
  int v30; // [esp+48h] [ebp-14h]
  int v31; // [esp+4Ch] [ebp-10h]
  char v32; // [esp+50h] [ebp-Ch]
  char v33; // [esp+54h] [ebp-8h]
  char v34; // [esp+58h] [ebp-4h]

  v27 = a2;
  v34 = a4;
  v30 = 0;
  v31 = 0;
  memset(v26, 0, 10);
  v7 = 0;
  v33 = 0;
  memset(v25, 0, 10);
  v32 = 0;
  memset(v24, 0, 10);
  v8 = dword_1930D4;
  do
  {
    v9 = dword_19306C + 113 * a1;
    LOWORD(v9) = *(_WORD *)(2 * (int16_t)v31 + v9 + 74);
    v29 = v9;
    if ( (int16_t)v9 > -1 )
    {
      v10 = (_BYTE *)(v8 + 17 * (int16_t)v9);
      if ( v10[4] == 3 && !v10[15] )
      {
        v26[(int16_t)v31] = 1;
        if ( v10[8] == 3 || v10[8] == 7 || v10[8] == 4 || v10[8] == 5 || v10[8] == 6 || v10[8] == 8 || v10[8] == 9 )
        {
          v28 = 17 * (int16_t)v29;
          v11 = 2 * (int16_t)v31;
          v12 = v28 + dword_1930D4;
          *(_WORD *)&v24[v11] = 1;
          v32 = 1;
          if ( *(_BYTE *)(v12 + 5) >= 2u )
          {
            v33 = 1;
            *(_WORD *)&v25[v11] = 1;
          }
        }
      }
    }
    ++v31;
  }
  while ( (int16_t)v31 < 5 );
  v23[0] = 0;
  for ( i = 1; i < 12; ++i )
  {
    if ( ((a5 >> i) & 1) != 0
      || i == 8 && (v28 = word_19999E, (uint8_t)byte_182244 > word_19999E + 2)
      || (i == 7 || i == 6) && !v33
      || i == 10 && !v32
      || i == 9 && !byte_19A006 )
    {
      v23[i] = 0;
    }
    else
    {
      v23[i] = (uint8_t)byte_17D832[i];
    }
  }
  do
  {
    LOBYTE(v14) = sub_F4D24((int)v23, 12);
    *a3 = v14;
    if ( (uint8_t)v14 < 6u )
    {
      if ( (uint8_t)v14 < 2u )
      {
        if ( (_BYTE)v14 == 1 )
        {
          if ( v34 )
          {
            LOBYTE(v14) = byte_182245;
            if ( (uint8_t)byte_182245 < 4 * (uint8_t)byte_199CB2 + 4 )
            {
              LOBYTE(v14) = (_BYTE)v27;
              v7 = 1;
              *v27 = 1;
              ++byte_182245;
            }
          }
        }
      }
      else
      {
        if ( (uint8_t)v14 <= 3u )
        {
LABEL_44:
          if ( v34 )
          {
            v14 = 113 * a1 + dword_19306C;
            *(_BYTE *)(v14 + 40) = *a3;
          }
          goto LABEL_56;
        }
        LOWORD(v14) = sub_FE92D((int)v26, 5);
        v15 = (int16_t)v14;
        if ( (int16_t)v14 > -1 )
        {
          if ( v34 )
          {
            v14 = 113 * a1 + dword_19306C;
            v16 = 17 * *(int16_t *)(v14 + 2 * v15 + 74);
            v17 = dword_1930D4;
            goto LABEL_49;
          }
LABEL_56:
          v7 = 1;
        }
      }
    }
    else
    {
      if ( (uint8_t)v14 <= 7u )
      {
        LOWORD(v14) = sub_FE92D((int)v25, 5);
        v19 = (int16_t)v14;
        if ( (int16_t)v14 <= -1 )
          goto LABEL_57;
        if ( !v34 )
          goto LABEL_56;
        v14 = dword_19306C + 113 * a1;
        v17 = 17 * *(int16_t *)(v14 + 2 * v19 + 74);
        v16 = dword_1930D4;
LABEL_49:
        v18 = *a3;
        *(_BYTE *)(v17 + v16 + 15) = *a3;
        *(_BYTE *)(v14 + 40) = v18;
        goto LABEL_56;
      }
      if ( (uint8_t)v14 < 9u )
      {
        ++byte_182244;
        if ( v34 )
          *(_BYTE *)(113 * a1 + dword_19306C + 40) = v14;
        goto LABEL_56;
      }
      if ( (uint8_t)v14 <= 9u )
        goto LABEL_44;
      if ( (_BYTE)v14 == 10 )
      {
        LOWORD(v14) = sub_FE92D((int)v24, 5);
        v20 = (int16_t)v14;
        if ( (int16_t)v14 > -1 )
        {
          if ( v34 )
          {
            v14 = dword_19306C + 113 * a1;
            v21 = *a3;
            *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(v14 + 2 * v20 + 74) + 15) = *a3;
            *(_BYTE *)(v14 + 40) = v21;
          }
          goto LABEL_56;
        }
      }
    }
LABEL_57:
    if ( (int16_t)++v30 > 100 )
    {
      v7 = 1;
      *a3 = 0;
    }
  }
  while ( !v7 );
  return v14;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 182244: using guessed type char byte_182244;
// 182245: using guessed type char byte_182245;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19999E: using guessed type int16_t word_19999E;
// 199CB2: using guessed type char byte_199CB2;
// 19A006: using guessed type char byte_19A006;


//----- (0008CB93) --------------------------------------------------------
int __fastcall sub_8CB93( int a1, _WORD *a2, int a3)
{
  int16_t v4; // dx
  int result; // eax
  _BYTE v6[4]; // [esp+0h] [ebp-4h] BYREF

  v6[0] = 0;
  if ( (int16_t)sub_1247A0(0x64u) > (uint8_t)byte_17D826 )
    sub_F4D39(a1, a2, v6, 1, 0);
  else
    v6[0] = 0;
  if ( (uint8_t)byte_199CB0 < 3u )
    goto LABEL_7;
  if ( (uint8_t)byte_199CB0 <= 3u )
  {
    v4 = 8;
  }
  else
  {
    if ( byte_199CB0 != 4 )
    {
LABEL_7:
      v4 = 5;
      goto LABEL_10;
    }
    v4 = 12;
  }
LABEL_10:
  if ( (int)(sub_1247A0(0x64u) - 1) < v4 )
    ++byte_19C319;
  result = v6[0];
  ++*(_BYTE *)(a3 + v6[0]);
  return result;
}
// 17D826: using guessed type char byte_17D826;
// 199CB0: using guessed type char byte_199CB0;
// 19C319: using guessed type char byte_19C319;


//----- (0008CC15) --------------------------------------------------------
int16_t sub_8CC15()
{
  int16_t i; // ax
  int v1; // edx
  int16_t j; // bx
  int v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // edx
  int16_t result; // ax
  _BYTE v7[72]; // [esp+0h] [ebp-50h] BYREF
  int v8; // [esp+48h] [ebp-8h]
  int v9; // [esp+4Ch] [ebp-4h]

  memset(v7, 0, sizeof(v7));
  for ( i = 0; i < word_199998; ++i )
  {
    v1 = *(uint8_t *)(17 * *(int16_t *)(3753 * i + dword_197F98 + 41) + dword_1930D4 + 2);
    v7[v1] = 1;
  }
  for ( j = 0; ; ++j )
  {
    result = (uint8_t)byte_182245;
    if ( j >= (uint8_t)byte_182245 )
      break;
    v9 = -1;
    v3 = 0;
    do
    {
      v4 = sub_1247A0(word_19999A - 1);
      v5 = v4;
      if ( (_WORD)v4 )
      {
        if ( !v7[(int16_t)v4] )
        {
          v8 = 113 * (int16_t)v4;
          if ( !*(_BYTE *)(v8 + dword_19306C + 40)
            && !sub_79001(v4)
            && *(_BYTE *)(v8 + dword_19306C + 22) != 6
            && *(char *)(v8 + dword_19306C + 41) == -1 )
          {
            v9 = v5;
          }
        }
      }
      ++v3;
    }
    while ( (int16_t)v3 <= 200 && (int16_t)v9 == -1 );
    if ( (int16_t)v9 != -1 )
      sub_8D6D6(v9, (int)v7);
  }
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 182245: using guessed type char byte_182245;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (0008CD02) --------------------------------------------------------
char __fastcall sub_8CD02( int a1)
{
  char v1; // dl

  v1 = 0;
  if ( a1 > -1 && a1 < 5 )
  {
    v1 = byte_17D817[a1];
    if ( v1 > 0 )
      _wcpp_1_unwind_leave(0, 0, "------CLIMATE modifier is %d  Planet: %d  Mineral: %d", v1, word_1999A2, a1);
  }
  return v1;
}
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 1999A2: using guessed type int16_t word_1999A2;


//----- (0008CD55) --------------------------------------------------------
int16_t __fastcall sub_8CD55( int a1)
{
  int v1; // ebx
  int16_t v2; // dx

  v1 = 17 * a1;
  v2 = *(uint8_t *)(v1 + dword_1930D4 + 3);
  if ( word_19C2F2 == 1 )
  {
    v2 -= 2;
    if ( v2 < 0 )
      return 0;
  }
  if ( *(uint8_t *)(dword_19306C + 113 * *(uint8_t *)(v1 + dword_1930D4 + 2) + 22) >= 6u )
    return 0;
  else
    return (uint8_t)byte_17D761[5
                                      * *(uint8_t *)(dword_19306C
                                                           + 113 * *(uint8_t *)(v1 + dword_1930D4 + 2)
                                                           + 22)
                                      + v2];
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 19C2F2: using guessed type int16_t word_19C2F2;


//----- (0008CDA9) --------------------------------------------------------
int16_t __fastcall sub_8CDA9( int a1)
{
  int16_t v2; // dx
  int16_t i; // ax
  int v4; // ebx
  _WORD v6[6]; // [esp+0h] [ebp-Ch] BYREF

  memset(v6, 0, 10);
  v2 = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( *(int16_t *)(dword_19306C + 113 * a1 + 2 * i + 74) != -1 )
    {
      v4 = v2++;
      v6[v4] = i;
    }
  }
  if ( v2 > 0 )
    return v6[(int16_t)(sub_1247A0(v2) - 1)];
  else
    return -1;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;


//----- (0008CE12) --------------------------------------------------------
int __fastcall sub_8CE12( int a1)
{
  int16_t v2; // bx
  int16_t i; // dx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  _WORD v8[6]; // [esp+0h] [ebp-Ch] BYREF

  memset(v8, 0, 10);
  v2 = 0;
  for ( i = 0; i < 5; ++i )
  {
    v4 = *(int16_t *)(113 * a1 + dword_19306C + 2 * i + 74);
    if ( v4 != -1 )
    {
      v5 = 17 * v4 + dword_1930D4;
      if ( *(_BYTE *)(v5 + 4) == 3
        && (*(_BYTE *)(v5 + 8) == 3
         || *(_BYTE *)(v5 + 8) == 7
         || *(_BYTE *)(v5 + 8) == 4
         || *(_BYTE *)(v5 + 8) == 5
         || *(_BYTE *)(v5 + 8) == 6
         || *(_BYTE *)(v5 + 8) == 8
         || *(_BYTE *)(v5 + 8) == 9) )
      {
        v6 = v2++;
        v8[v6] = i;
      }
    }
  }
  if ( v2 > 0 )
    JUMPOUT(0x8CE00);
  return -1;
}
// 8CEA7: control flows out of bounds to 8CE00
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0008CEAC) --------------------------------------------------------
int __fastcall sub_8CEAC( int a1)
{
  int v2; // edx
  int16_t v3; // si
  int i; // eax

  v2 = -1;
  v3 = 0;
  for ( i = 0; (int16_t)i < word_199998 && !v3; ++i )
  {
    if ( a1 == *(_WORD *)(3753 * (int16_t)i + dword_197F98 + 41) )
    {
      v3 = 1;
      v2 = i;
    }
  }
  return v2;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0008CFFF) --------------------------------------------------------
void __fastcall sub_8CFFF( int a1, int a2, int a3, int a4, int a5)
{
  int v5; // ebx
  int v6; // edx
  int16_t *v7; // edi
  int v8; // eax
  int16_t v9; // ax
  int v10; // ebx
  int v11; // eax
  int v12; // ebx
  int v13; // edx
  char v14; // al
  int v15; // eax
  char *v16; // edi
  unsigned int v17; // edi
  unsigned int v18; // edi
  unsigned int v19; // edx
  int v20; // esi
  int16_t v21; // cx
  int16_t v22; // cx
  int v23; // eax
  int16_t v24; // bx
  int16_t v25; // bx
  int16_t v26; // ax
  int16_t v27; // cx
  int v28; // eax
  int16_t v29; // cx
  int v30; // ebx
  int16_t v31; // ax
  int16_t v32; // ax
  int16_t *v33; // [esp-8h] [ebp-78h]
  int16_t v34; // [esp+0h] [ebp-70h]
  char v35; // [esp+3h] [ebp-6Dh] BYREF
  _BYTE v36[32]; // [esp+4h] [ebp-6Ch] BYREF
  _BYTE v37[8]; // [esp+24h] [ebp-4Ch] BYREF
  int16_t v38[4]; // [esp+2Ch] [ebp-44h] BYREF
  int v39; // [esp+34h] [ebp-3Ch]
  int v40; // [esp+38h] [ebp-38h]
  unsigned int v41; // [esp+3Ch] [ebp-34h]
  int v42; // [esp+40h] [ebp-30h]
  int v43; // [esp+44h] [ebp-2Ch]
  int v44; // [esp+48h] [ebp-28h]
  int v45; // [esp+4Ch] [ebp-24h]
  int v46; // [esp+50h] [ebp-20h]
  int v47; // [esp+54h] [ebp-1Ch]
  int v48; // [esp+58h] [ebp-18h]
  int v49; // [esp+5Ch] [ebp-14h]
  int i; // [esp+60h] [ebp-10h]
  char v51; // [esp+64h] [ebp-Ch]
  char v52; // [esp+68h] [ebp-8h]
  uint8_t v53; // [esp+6Ch] [ebp-4h]

  v52 = a4;
  v48 = word_199A0C / a1;
  v49 = word_199A0A / a2;
  v45 = sub_7926C(word_199A0C);
  v47 = sub_7926C(word_199A0A);
  v5 = 124;
  qmemcpy(v38, sub_8E5C5(4u, 119, 121), sizeof(v38));
  v6 = 0;
  qmemcpy(v37, sub_8E5C5(4u, 119, 124), sizeof(v37));
  v7 = (int16_t *)v37;
  sub_7A00A(0, 0, 0x7Cu);
  v8 = sub_79917();
  LOWORD(v8) = word_199992;
  v53 = 0;
  if ( (uint16_t)word_199992 < 0xFu )
  {
    if ( word_199992 != 10 )
    {
LABEL_11:
      for ( i = 0; ; ++i )
      {
        if ( (int16_t)i >= word_19999A )
LABEL_43:
          JUMPOUT(0x8CB8D);
        word_19C2EC = i;
        sub_FE8BE(i, v6, v5, v7);
        if ( dword_19C2CC == 1 )
        {
          sub_120BB5(4, (int)v38);
          v33 = (int16_t *)dword_19C2E4;
          v9 = sub_12066F((int)byte_19C2F4);
          v10 = (int16_t)(2 * word_19999A);
          v11 = sub_8EFE1(4u, &word_19C2F0, v10, v38, (int)v37, (640 - v9) / 2, 215, byte_19C2F4, v33, 0);
          sub_1077D(v11, (int)&word_19C2F0, v10, v7);
        }
        v12 = (int16_t)i;
        v44 = (int16_t)i % v34 * (int16_t)v48;
        v13 = (int16_t)i * (int16_t)v49 % v34;
        v43 = (int16_t)i * (int16_t)v49 / v34;
        if ( v52 )
        {
          v14 = sub_8C807(v40);
          v15 = sub_F4B41(v14, v13, v12);
          LOBYTE(v12) = dword_19306C;
          *(_BYTE *)(dword_19306C + v15 + 22) = v13;
        }
        if ( a5 )
        {
          v12 = 113 * (int16_t)i;
          strcpy(
            (char *)(v12 + dword_19306C),
            (char *)(15 * *(int16_t *)(dword_19C2BC + 2 * (int16_t)i) + dword_19C2C0));
          sub_7A00A(0, 0, v12);
          sprintf(v36, "(%s)", (char *)(v12 + dword_19306C));
          if ( strlen((char *)(v12 + dword_19306C)) < 7 )
          {
            v16 = &v35;
            do
              ++v16;
            while ( *v16 );
            strcpy(v16, aW);
          }
          v7 = (int16_t *)sub_12066F((int)v36);
          if ( (uint8_t)byte_19C318 < 3u )
            goto LABEL_25;
          v17 = sub_1247A0(8u) + 32;
          v18 = sub_1247A0(8u) + v17;
        }
        else
        {
          v19 = sub_1247A0(8u) + 32;
          v18 = sub_1247A0(8u) + v19;
        }
        v7 = (int16_t *)(sub_1247A0(8u) + v18);
LABEL_25:
        sub_7A00A(0, 0, v12);
        sub_79917();
        v20 = 0;
        do
        {
          do
          {
            do
            {
              v21 = v44;
              v22 = (int16_t)(sub_1247A0(2 * (int16_t)v48) + v21) % word_199A0C;
              v23 = sub_7926C(v22);
              v46 = v23;
            }
            while ( (int16_t)v23 < 24 );
          }
          while ( (int16_t)v23 > (int16_t)v45 - word_19996E / 2 );
          *(_WORD *)(113 * (int16_t)i + dword_19306C + 15) = v22;
          do
          {
            do
            {
              v24 = v43;
              v25 = (int16_t)(sub_1247A0(2 * (int16_t)v49) + v24) % word_199A0A;
              v26 = sub_7926C(v25);
            }
            while ( v26 < 22 );
          }
          while ( v26 > (int16_t)v47 - (word_199954 / 2 + v53) );
          v39 = (int16_t)i;
          v27 = v46;
          *(_WORD *)(dword_19306C + 113 * (int16_t)i + 17) = v25;
          v5 = (int16_t)v42;
          v6 = (int16_t)v7;
          LOBYTE(v28) = sub_8D43D(v39, (int16_t)v7, v42, v27);
          LOBYTE(v6) = v28;
          if ( (_BYTE)v28 == 1 && (int16_t)++v20 > 150 )
          {
            v51 = 0;
            v20 = 0;
            do
            {
              sub_FE8BE(v28, v6, v5, v7);
              v29 = sub_1247A0(0x189u) + 20;
              v41 = sub_1247A0(0x155u) + 20;
              sub_7927F();
              v39 = (int16_t)i;
              v30 = 113 * (int16_t)i;
              *(_WORD *)(v30 + dword_19306C + 15) = v31;
              sub_7927F();
              *(_WORD *)(v30 + dword_19306C + 17) = v32;
              v5 = (int16_t)v42;
              v6 = (int16_t)v7;
              LOBYTE(v28) = sub_8D43D(v39, (int16_t)v7, v42, v29);
              if ( (_BYTE)v28 )
              {
                if ( (int16_t)++v20 > 150 )
                  goto LABEL_43;
              }
              else
              {
                v51 = 1;
              }
            }
            while ( !v51 );
            LOBYTE(v6) = 0;
          }
        }
        while ( (_BYTE)v6 == 1 );
      }
    }
  }
  else if ( (uint16_t)word_199992 > 0xFu )
  {
    if ( (uint16_t)word_199992 >= 0x14u )
    {
      if ( (uint16_t)word_199992 <= 0x14u )
      {
        v42 = 36;
        v53 = 6;
      }
      else if ( word_199992 == 30 )
      {
        v53 = 4;
        v42 = v8;
      }
    }
    goto LABEL_11;
  }
  v42 = 50;
  v53 = 8;
  goto LABEL_11;
}
// 8D405: control flows out of bounds to 8CB8D
// 8D16F: variable 'v34' is possibly undefined
// 8D38D: variable 'v28' is possibly undefined
// 8D3CE: variable 'v31' is possibly undefined
// 8D3E3: variable 'v32' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 199954: using guessed type int16_t word_199954;
// 19996E: using guessed type int16_t word_19996E;
// 199992: using guessed type int16_t word_199992;
// 19999A: using guessed type int16_t word_19999A;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;
// 19C2BC: using guessed type int dword_19C2BC;
// 19C2C0: using guessed type int dword_19C2C0;
// 19C2CC: using guessed type int dword_19C2CC;
// 19C2E4: using guessed type int dword_19C2E4;
// 19C2EC: using guessed type int16_t word_19C2EC;
// 19C2F0: using guessed type int16_t word_19C2F0;
// 19C318: using guessed type char byte_19C318;


//----- (0008D43D) --------------------------------------------------------
char __fastcall sub_8D43D( int a1, int a2, int a3, int a4)
{
  int16_t v5; // si
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  _BOOL1 v12; // al
  _BOOL1 v13; // bl
  int v15; // [esp+8h] [ebp-28h]
  int v16; // [esp+Ch] [ebp-24h]
  int16_t v17; // [esp+10h] [ebp-20h]
  int16_t v18; // [esp+14h] [ebp-1Ch]
  char v22; // [esp+28h] [ebp-8h]

  v22 = 0;
  v18 = sub_7926C(word_199A0C);
  v5 = 0;
  sub_7926C(word_199A0A);
  while ( v5 < a1 && !v22 )
  {
    v6 = 113 * v5;
    v7 = (int16_t)sub_7926C(*(_WORD *)(v6 + dword_19306C + 15));
    v15 = 113 * a1;
    v8 = v7 - (int16_t)sub_7926C(*(_WORD *)(v15 + dword_19306C + 15));
    v9 = (int16_t)sub_7926C(*(_WORD *)(v6 + dword_19306C + 17));
    v10 = v9 - (int16_t)sub_7926C(*(_WORD *)(v15 + dword_19306C + 17));
    if ( *(_BYTE *)(v6 + dword_19306C + 22) == 6 || *(_BYTE *)(v15 + dword_19306C + 22) == 6 )
    {
      sub_EBEB7(a1, v5);
      if ( v11 < 5 )
        v22 = 1;
    }
    else
    {
      v17 = sub_7926C(60);
      v16 = v10 * v10 + v8 * v8;
      v12 = (int)abs32(v10) < a3 && (int)abs32(v8) < a2;
      v13 = (int)abs32(v10) < 15 && (int)abs32(v8) < v17;
      if ( v16 <= 800 || v12 || v13 || a4 + 2 * a2 / 3 > v18 )
      {
        word_19C204 += v16 <= 800;
        word_19C206 += v12;
        word_19C208 += v13;
        v22 = 1;
        word_19C20A += a4 + 2 * a2 / 3 > v18;
      }
    }
    ++v5;
  }
  return v22;
}
// 8D513: variable 'v11' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;
// 19C204: using guessed type int16_t word_19C204;
// 19C206: using guessed type int16_t word_19C206;
// 19C208: using guessed type int16_t word_19C208;
// 19C20A: using guessed type int16_t word_19C20A;


//----- (0008D602) --------------------------------------------------------
void __fastcall sub_8D602(int a1)
{
  int v2; // eax
  int v3; // ecx
  int16_t v4; // dx
  int16_t v5; // si
  int16_t v6; // di

  v2 = 0;
  do
  {
    *(_WORD *)(a1 + 2 * (int16_t)v2) = v2;
    ++v2;
  }
  while ( (int16_t)v2 < 829 );
  v3 = 0;
  while ( 1 )
  {
    v4 = sub_1247A0(0x33Du) - 1;
    v5 = sub_1247A0(0x33Du) - 1;
    if ( v4 != v5 )
    {
      v6 = *(_WORD *)(a1 + 2 * v4);
      *(_WORD *)(a1 + 2 * v4) = *(_WORD *)(a1 + 2 * v5);
      *(_WORD *)(a1 + 2 * v5) = v6;
    }
    if ( (int16_t)++v3 >= 829 )
      JUMPOUT(0x8BBFD);
  }
}
// 8D658: control flows out of bounds to 8BBFD


//----- (0008D65D) --------------------------------------------------------
void sub_8D65D()
{
  int16_t i; // dx
  int v1; // eax

  for ( i = 0; i < word_19999A; ++i )
  {
    v1 = 113 * i + dword_19306C;
    if ( *(_BYTE *)(v1 + 22) == 6 )
      *(_BYTE *)(v1 + 51) = -1;
  }
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (0008D687) --------------------------------------------------------
void sub_8D687()
{
  _DWORD *v0; // eax
  void *v1; // edi
  int v2; // [esp+0h] [ebp-8h]
  int v3; // [esp+4h] [ebp-4h]

  v3 = 0;
  do
  {
    v0 = sub_126C37((int)aNdataLbx, 0, dword_192ED4, (int16_t)v3, 1u, 5);
    v1 = (void *)(5 * (int16_t)v3++ + v2);
    qmemcpy(v1, v0, 5u);
  }
  while ( (int16_t)v3 < 12 );
  JUMPOUT(0x8BBFC);
}
// 8D6D1: control flows out of bounds to 8BBFC
// 8D6BF: variable 'v2' is possibly undefined
// 192ED4: using guessed type int dword_192ED4;


//----- (0008D6D6) --------------------------------------------------------
int __fastcall sub_8D6D6( int a1, int a2)
{
  int16_t v2; // cx
  _BOOL2 v3; // di
  int16_t i; // bx
  unsigned int v5; // eax
  _BYTE *v6; // eax
  int v7; // eax
  int16_t v8; // si
  int16_t j; // bx
  _BOOL1 v10; // dl
  int16_t k; // si
  int16_t v12; // dx
  int16_t v13; // ax
  int v14; // edx
  int v15; // eax
  int16_t v16; // di
  int16_t v17; // si
  int16_t m; // bx
  int v19; // eax
  int v20; // edx
  int result; // eax
  _WORD v23[20]; // [esp+8h] [ebp-2Ch] BYREF
  int16_t v24; // [esp+30h] [ebp-4h]

  v24 = -1;
  memset(v23, -1, sizeof(v23));
  v2 = 0;
  v3 = 0;
  for ( i = 0; i < word_19999A && !v3; ++i )
  {
    sub_EBEB7(a1, i);
    if ( v5 > (unsigned int)(uint8_t)byte_199CB2 + 3 && !*(_BYTE *)(i + a2) )
    {
      v6 = (_BYTE *)(dword_19306C + 113 * i);
      if ( (char)v6[41] == -1 && v6[22] != 6 && !v6[40] && i != a1 )
      {
        v7 = v2++;
        v23[v7] = i;
        v3 = v2 == 19;
      }
    }
  }
  if ( v2 > 0 )
  {
    v8 = 0;
    for ( j = 0; j < v2; ++j )
    {
      v10 = *(_BYTE *)(dword_19306C + 113 * (int16_t)v23[j] + 41) <= 0;
      if ( !sub_79BAE(v23[j]) )
        v10 = 0;
      if ( !v10 )
      {
        ++v8;
        v23[j] = -1;
      }
    }
    if ( v8 < v2 )
    {
      for ( k = 0; k < 5 * v2 / 3; ++k )
      {
        v12 = sub_1247A0(v2);
        v13 = sub_1247A0(v2);
        if ( v12 != v13 )
        {
          v14 = v12;
          if ( (int16_t)v23[v14] != -1 )
          {
            v15 = v13;
            if ( (int16_t)v23[v15] != -1 )
            {
              v16 = v23[v14];
              v23[v14] = v23[v15];
              v23[v15] = v16;
            }
          }
        }
      }
      v17 = 1;
      for ( m = 0; m < v2; ++m )
      {
        if ( (int16_t)v23[m] != -1 && sub_1247A0(v17) == 1 )
        {
          ++v17;
          v24 = v23[m];
        }
      }
    }
  }
  if ( v24 <= -1 )
  {
    result = 113 * a1;
    *(_BYTE *)(dword_19306C + result + 41) = 0;
  }
  else
  {
    v19 = 113 * v24;
    v20 = dword_19306C;
    if ( byte_1783D3 )
    {
      *(_BYTE *)(v19 + dword_19306C + 41) = -1;
      result = 113 * a1;
      *(_BYTE *)(result + v20 + 41) = -1;
    }
    else
    {
      *(_BYTE *)(v19 + dword_19306C + 41) = a1;
      result = v20 + 113 * a1;
      *(_BYTE *)(result + 41) = v24;
    }
  }
  return result;
}
// 8D71A: variable 'v5' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1783D3: using guessed type char byte_1783D3;
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 199CB2: using guessed type char byte_199CB2;


//----- (0008D8A1) --------------------------------------------------------
void __fastcall sub_8D8A1( int a1)
{
  int16_t v1; // bx
  int v2; // eax
  int16_t v3; // si
  _BOOL1 v4; // cl
  _BOOL1 v5; // al
  int16_t v6; // si
  char v7; // cl
  int v8; // eax
  int v10; // [esp+8h] [ebp-34h]
  int16_t v11; // [esp+10h] [ebp-2Ch]
  int16_t v12; // [esp+18h] [ebp-24h]
  _BOOL1 v13; // [esp+24h] [ebp-18h]
  _BOOL1 v14; // [esp+28h] [ebp-14h]
  _BOOL1 v15; // [esp+2Ch] [ebp-10h]
  _BOOL1 v16; // [esp+30h] [ebp-Ch]
  _BOOL1 v17; // [esp+34h] [ebp-8h]
  _BOOL1 v18; // [esp+38h] [ebp-4h]

  v10 = *(_DWORD *)&asc_8BB48[2];
  v1 = 0;
  v12 = SHIWORD(v10) / 2;
  while ( v1 < word_19999A )
  {
    v2 = 113 * v1 + dword_19306C;
    if ( *(_BYTE *)(v2 + 22) == 6 )
    {
      v3 = *(_WORD *)(v2 + 15);
      v11 = *(_WORD *)(v2 + 17);
      v18 = sub_EBA3A(v3, v11);
      v16 = sub_EBA3A(HIWORD(v10) + v3, v11);
      v13 = sub_EBA3A(v3, HIWORD(v10) + v11);
      v15 = sub_EBA3A(HIWORD(v10) + v3, HIWORD(v10) + v11);
      v17 = sub_EBA3A(v12 + v3, v11);
      v14 = sub_EBA3A(HIWORD(v10) + v3, v12 + v11);
      v4 = sub_EBA3A(v12 + v3, HIWORD(v10) + v11);
      v5 = sub_EBA3A(v3, v12 + v11);
      if ( v18 || v16 || v13 || v15 || v17 || v14 || v4 || v5 )
      {
        v6 = 0;
        do
        {
          v7 = sub_8C807(a1);
          v8 = dword_19306C + 113 * v1;
          *(_BYTE *)(v8 + 22) = v7;
          if ( v6 > 200 )
            *(_BYTE *)(v8 + 22) = 4;
          ++v6;
        }
        while ( !sub_792A9(v1) );
        sub_8E280(v1);
        *(_BYTE *)(dword_19306C + 113 * v1 + 51) = 0;
      }
    }
    ++v1;
  }
  JUMPOUT(0x8BBFC);
}
// 8DA02: control flows out of bounds to 8BBFC
// 8BB48: using guessed type wchar_t asc_8BB48[3];
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (0008DA07) --------------------------------------------------------
void __usercall sub_8DA07(int a1, int a2, int16_t *a3)
{
  int16_t j; // si
  int v4; // eax
  int16_t v5; // cx
  int v6; // [esp+0h] [ebp-10h]
  int v7; // [esp+4h] [ebp-Ch]
  int16_t i; // [esp+8h] [ebp-8h]
  char v9; // [esp+Ch] [ebp-4h]

  v9 = 1;
  for ( i = 0; ; ++i )
  {
    LOWORD(v4) = (uint8_t)byte_199F0D;
    if ( (uint8_t)byte_199F0D <= i )
      break;
    v7 = 0;
    for ( j = 0; j < 12; ++j )
    {
      sub_FE8BE((uint16_t)v4, a1, a2, a3);
      v5 = 0;
      a3 = (int16_t *)(v7 + 6);
      do
      {
        sub_FE8BE((uint16_t)v4, a1, a2, a3);
        a1 = i;
        a2 = dword_193068;
        LOWORD(v4) = *(char *)(dword_193068 + 5 * i + 4);
        if ( j == (_WORD)v4 )
        {
          v6 = 16 * i;
          a2 = dword_192EF0;
          if ( v9 )
          {
            a1 = (int)sub_126AFD((int)aStarbgLbx_0, (int16_t)a3, dword_192EF0);
            v4 = v6 + 4 * v5;
            v9 = 0;
          }
          else
          {
            a1 = (int)sub_126B42((int)aStarbgLbx_0, (int16_t)a3, dword_192EF0);
            v4 = v6 + 4 * v5;
          }
          *(int *)((char *)dword_190298 + v4) = a1;
        }
        ++v7;
        ++v5;
        a3 = (int16_t *)((char *)a3 + 1);
      }
      while ( v5 < 4 );
    }
  }
  JUMPOUT(0x8BBFC);
}
// 8DAD3: control flows out of bounds to 8BBFC
// 8DA36: variable 'v4' is possibly undefined
// 190298: using guessed type int dword_190298[];
// 192EF0: using guessed type int dword_192EF0;
// 193068: using guessed type int dword_193068;
// 199F0D: using guessed type char byte_199F0D;


//----- (0008DAE8) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __usercall sub_8DAE8(
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
        hr_int128_t a21,
        int64_t a22,
        int64_t a23,
        int a24,
        int a25)
{
  char *v25; // eax
  int16_t *v26; // edi
  int v27; // eax
  int16_t *v28; // edx
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // ebx
  int64_t v35; // rax
  int v36; // ebx
  int v37; // eax
  int v38; // eax
  int v39; // ebx
  int v40; // eax
  int v41; // eax
  int64_t v42; // rax
  int64_t v43; // rax
  int v44; // ebx
  int16_t v45; // ax
  int v46; // ebx
  int v47; // eax
  int16_t i; // si
  int v49; // eax
  int v50; // ecx
  int v51; // edx
  int16_t v52; // ax
  int v53; // ebx
  int v54; // eax
  int v55; // edx
  int16_t v56; // bx
  int v57; // eax
  int v58; // ebx
  int v59; // eax
  int j; // edx
  int v61; // eax
  int v62; // esi
  int v63; // ebx
  unsigned int v64; // ecx
  int result; // eax
  int16_t *v66; // [esp-14h] [ebp-E4h]
  int16_t *v67; // [esp-14h] [ebp-E4h]
  int v68; // [esp-Ch] [ebp-DCh]
  int v69; // [esp-8h] [ebp-D8h]
  int v70; // [esp-4h] [ebp-D4h]
  int16_t v71; // [esp+76h] [ebp-5Ah]
  int16_t v72; // [esp+7Ah] [ebp-56h]
  int16_t v73; // [esp+7Eh] [ebp-52h]
  char var4E[80]; // [esp+82h] [ebp-4Eh] BYREF
  _BYTE vars2[14]; // [esp+D2h] [ebp+2h] BYREF

  v70 = a1;
  v69 = a2;
  v68 = a3;
  qmemcpy((char *)&a19 + 2, sub_8E5C5(4u, 119, 121), 8u);
  v25 = sub_8E5C5(4u, 119, 124);
  BYTE6(a23) = 0;
  qmemcpy((char *)&a17 + 2, v25, 8u);
  v26 = (int16_t *)&a17 + 1;
  sub_FE8BE((int)v25, 119, 124, (int16_t *)&a17 + 1);
  *(_DWORD *)((char *)&a21 + 2) = j___clock(v27, 119, 124);
  byte_199F2B = v73;
  v28 = 0;
  byte_199F2F = v72;
  byte_19C318 = 0;
  v29 = memset(&word_19C204, 0, 8);
  sub_FE8BE(v29, 0, 8, (int16_t *)&a17 + 1);
LABEL_2:
  dword_19C2E8 = (int)byte_17D817;
  byte_19C31A = 0;
  dword_19C2CC = 1;
  ++byte_19C318;
  sub_FE8BE(v30, (int)v28, 6120, v26);
  sub_FE8BE(v31, (int)v28, 6120, v26);
  sub_FE8BE(v32, (int)v28, 6120, v26);
  word_19996E = 37;
  word_199954 = 37;
  word_19C2F2 = 0;
  v33 = memset(dword_1930D4, 0, 6120);
  sub_FE8BE(v33, 0, 6120, v26);
  v34 = dword_192ED4;
  HIDWORD(v35) = 3316;
  dword_19C2C0 = (int)sub_126BDD((int)aStarnameLbx_0, 1, dword_192ED4, 0, 0x33Du, 15);
  sub_FE8BE(dword_19C2C0, 3316, v34, v26);
  dword_19C2BC = (int)sub_110D3C(dword_192ED4, 3316);
  sub_FE8BE(dword_19C2BC, 3316, v34, v26);
  sub_FE8BE(v35, 3316, v34, v26);
  if ( word_1999E0 )
  {
    dword_19C2CC = (uint16_t)word_1999E0;
    v35 = j___clock((uint16_t)word_1999E0, 3316, v34);
    *(_DWORD *)((char *)&a21 + 6) = v35;
  }
  sub_FE8BE(v35, SHIDWORD(v35), v34, v26);
  sub_8D602(dword_19C2BC);
  if ( dword_19C2CC == 1 )
  {
    if ( sub_C5BB0() )
      sub_C5C44();
    LODWORD(v35) = sub_124D7A();
    sub_FE8BE(v35, SHIDWORD(v35), v34, v26);
    v36 = sub_127C27((int)aRaceoptLbx_2, 0, dword_193174);
    v37 = sub_12A478(0, 0, v36);
    sub_FE8BE(v37, 0, v36, v26);
    sub_124E36();
    strcpy(byte_19C2F4, sub_7A990(0xF2u));
    v26 = (int16_t *)byte_19C2F4;
    v38 = sub_12DAA4(325, 30);
    dword_19C2E4 = (int)sub_110D3C(dword_192ED4, v38);
    v39 = dword_19C2E4;
    v40 = sub_12D8F5(325, 30, dword_19C2E4);
    word_19C2F0 = 0;
    sub_FE8BE(v40, (int)&a19 + 2, v39, (int16_t *)byte_19C2F4);
    sub_120DB3(4, (int)&a19 + 2);
    sub_120DED(2, 1);
    LOBYTE(v41) = sub_122A6E(0, 0, (int)byte_19C2F4, dword_19C2E4);
    sub_FE8BE(v41, 0, (int)byte_19C2F4, (int16_t *)byte_19C2F4);
  }
  if ( byte_182246 )
  {
    sub_124820(dword_199CB6);
    byte_182246 = 0;
  }
  switch ( v73 )
  {
    case 0:
      word_19999A = 20;
      *(_DWORD *)((char *)&a22 + 2) = 5;
      *(_DWORD *)((char *)&a23 + 2) = 4;
      break;
    case 1:
      word_19999A = 36;
      *(_DWORD *)((char *)&a22 + 2) = 6;
      goto LABEL_13;
    case 2:
      word_19999A = 54;
      *(_DWORD *)((char *)&a22 + 2) = 9;
LABEL_13:
      *(_DWORD *)((char *)&a23 + 2) = 6;
      break;
    case 3:
      word_19999A = 71;
      *(_DWORD *)((char *)&a22 + 2) = 9;
      *(_DWORD *)((char *)&a23 + 2) = 8;
      break;
    default:
      v42 = sprintf(var4E, "Galaxy size %d is undefined", v73);
      sub_126487(var4E, SHIDWORD(v42));
  }
  v43 = sub_8CF09(v73, v71);
  sub_FE8BE(v43, SHIDWORD(v43), v73, v26);
  sub_FE8BE(v43, SHIDWORD(v43), v73, v26);
  word_1999A2 = 0;
  sub_16933A(v73);
  if ( byte_199F0D )
    sub_8C099(v73, (unsigned int)v26);
  sub_7926C(word_199A0C);
  v26 = 0;
  sub_7926C(word_199A0A);
  while ( 1 )
  {
    result = (int16_t)v26;
    if ( (int16_t)v26 >= dword_19C2CC )
      break;
    if ( dword_19C2CC != 1 )
      dword_199CB6 = sub_12484C();
    BYTE2(a24) = 0;
    byte_19C319 = 0;
    if ( word_1999E0 )
      sub_8C4D3(v73);
    HIDWORD(v43) = 0;
    memset(&unk_19C2D4, 0, 12);
    while ( !BYTE2(a24) )
    {
      word_199996 = 0;
      dword_19C2C4 = 0;
      dword_19C2E0 = 0;
      word_1999A2 = 0;
      byte_182244 = 0;
      byte_182245 = 0;
      memset(dword_1930D4, 0, 6120);
      memset(dword_19306C, 0, 8136);
      memset(vars2, 0, 72);
      v44 = v72;
      HIDWORD(v43) = SWORD1(a23);
      sub_8CFFF(SWORD1(a22), SWORD1(a23), v72, 1, 1);
      if ( (_BYTE)v43 )
      {
        sub_120BB5(4, (int)&a19 + 2);
        v66 = (int16_t *)dword_19C2E4;
        v45 = sub_12066F((int)byte_19C2F4);
        v28 = &word_19C2F0;
        v46 = (int16_t)(2 * word_19999A);
        v47 = sub_8EFE1(
                4u,
                &word_19C2F0,
                v46,
                (int16_t *)&a19 + 1,
                (int)&a17 + 2,
                (640 - v45) / 2,
                215,
                byte_19C2F4,
                v66,
                1);
        v30 = sub_1077D(v47, (int)&word_19C2F0, v46, v26);
        goto LABEL_2;
      }
      for ( i = 0; i < word_19999A; ++i )
      {
        word_19C2EC = i;
        sub_FE8BE(v43, SHIDWORD(v43), v44, v26);
        v49 = 0;
        do
        {
          v50 = 113 * i;
          *(_DWORD *)((char *)&a21 + 10) = v50 + dword_19306C;
          v51 = v50 + dword_19306C + 2 * (int16_t)v49++;
          *(_WORD *)(v51 + 84) = -1;
        }
        while ( (int16_t)v49 < 8 );
        memset(*(_DWORD *)((char *)&a21 + 10) + 66, -1, 8);
        *(_BYTE *)(v50 + dword_19306C + 41) = -1;
        if ( dword_19C2CC == 1 && (int16_t)v26 < 1 )
        {
          sub_120BB5(4, (int)&a19 + 2);
          v67 = (int16_t *)dword_19C2E4;
          v52 = sub_12066F((int)byte_19C2F4);
          v53 = (int16_t)(2 * word_19999A);
          v54 = sub_8EFE1(
                  4u,
                  &word_19C2F0,
                  v53,
                  (int16_t *)&a19 + 1,
                  (int)&a17 + 2,
                  (640 - v52) / 2,
                  215,
                  byte_19C2F4,
                  v67,
                  0);
          sub_1077D(v54, (int)&word_19C2F0, v53, v26);
        }
        v55 = 113 * i;
        *(_BYTE *)(v55 + dword_19306C + 20) = -1;
        v56 = sub_1247A0(0xAu) - 1;
        if ( v56 >= 3 )
        {
          if ( v56 >= 7 )
            *(_BYTE *)(v55 + dword_19306C + 19) = 2;
          else
            *(_BYTE *)(v55 + dword_19306C + 19) = 1;
        }
        else
        {
          *(_BYTE *)(v55 + dword_19306C + 19) = 0;
        }
        *(_BYTE *)(dword_19306C + 113 * i + 21) = sub_1247A0(3u) - 1;
        v57 = 0;
        do
        {
          v58 = 113 * i + dword_19306C + 2 * (int16_t)v57++;
          *(_WORD *)(v58 + 74) = -1;
        }
        while ( (int16_t)v57 < 5 );
        word_19C2F2 = 0;
        if ( sub_792A9(i) )
        {
          LOBYTE(v58) = sub_8C527(i);
          vars2[i] = v58;
          for ( j = 0; ; ++j )
          {
            LOWORD(v59) = (uint8_t)v58;
            if ( (int16_t)j >= (uint8_t)v58 )
              break;
            sub_FE8BE(v59, j, v58, v26);
            sub_8E280(i);
          }
          if ( word_1999E0 )
            ++dword_19C20C[(uint8_t)v58];
        }
        v44 = 113 * i;
        if ( *(_BYTE *)(dword_19306C + v44 + 22) != 6 && vars2[i] && i > 0 )
        {
          v44 = (int)&unk_19C2D4;
          sub_8CB93(i, (_WORD *)&a22 + 3, (int)&unk_19C2D4);
        }
        LODWORD(v43) = 113 * i;
        HIDWORD(v43) = dword_19306C;
        ++dword_19C2E0;
        *(_BYTE *)(dword_19306C + v43 + 41) = -1;
      }
      BYTE2(a24) = 1;
      BYTE2(a25) = 0;
      do
      {
        if ( byte_199F0D )
          sub_8D8A1(v72);
        sub_EB87D();
        sub_EBD80();
        if ( (_BYTE)v43 )
        {
          BYTE2(a25) = 1;
        }
        else
        {
          v44 = v72;
          HIDWORD(v43) = SWORD1(a23);
          sub_8CFFF(SWORD1(a22), SWORD1(a23), v72, 0, 0);
        }
      }
      while ( !BYTE2(a25) );
      if ( word_1999E0 )
      {
        LODWORD(v43) = (uint8_t)byte_199F0D;
        ++dword_19C250[(uint8_t)byte_199F0D];
      }
      if ( word_1999E0 )
      {
        if ( (uint16_t)word_1999E0 < 0x64u
          || (v44 = (uint16_t)word_1999E0 / 100,
              LODWORD(v43) = (int16_t)v26 / v44,
              (HIDWORD(v43) = (int16_t)v26 % v44) == 0) )
        {
          v61 = j___clock(v43, HIDWORD(v43), v44);
          v62 = *(_DWORD *)((char *)&a21 + 2);
          *(_DWORD *)((char *)&a21 + 14) = 100;
          v63 = v61;
          *(_DWORD *)((char *)&a21 + 2) = v61;
          v64 = v61 - *(_DWORD *)((char *)&a21 + 6);
          _wcpp_1_unwind_leave(0, 0, asc_179906, v68, v69, v70);
          HIDWORD(v43) = v64 % 0x64;
          _wcpp_1_unwind_leave(
            0,
            0,
            "Stat %d  (start: %d)  (diff %d)  (total: %d.%d)",
            (int16_t)v26,
            *(_DWORD *)((char *)&a21 + 6),
            v63 - v62,
            v64 / 0x64,
            v64 % *(_DWORD *)((char *)&a21 + 14));
        }
      }
    }
    v26 = (int16_t *)((char *)v26 + 1);
  }
  if ( BYTE6(a23) )
    sub_126487(aMapTestDone, SHIDWORD(v43));
  return result;
}
// 8E204: inconsistent variable size for '^154.16'
// 8E228: inconsistent variable size for '^154.16'
// 8CF09: using guessed type int64_t __fastcall sub_8CF09(_DWORD, _DWORD);
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 182244: using guessed type char byte_182244;
// 182245: using guessed type char byte_182245;
// 182246: using guessed type char byte_182246;
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 199954: using guessed type int16_t word_199954;
// 19996E: using guessed type int16_t word_19996E;
// 199996: using guessed type int16_t word_199996;
// 19999A: using guessed type int16_t word_19999A;
// 1999A2: using guessed type int16_t word_1999A2;
// 1999E0: using guessed type int16_t word_1999E0;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;
// 199CB6: using guessed type int dword_199CB6;
// 199F0D: using guessed type char byte_199F0D;
// 199F2B: using guessed type char byte_199F2B;
// 199F2F: using guessed type char byte_199F2F;
// 19C204: using guessed type int16_t word_19C204;
// 19C20C: using guessed type int dword_19C20C[17];
// 19C250: using guessed type int dword_19C250[27];
// 19C2BC: using guessed type int dword_19C2BC;
// 19C2C0: using guessed type int dword_19C2C0;
// 19C2C4: using guessed type int dword_19C2C4;
// 19C2CC: using guessed type int dword_19C2CC;
// 19C2E0: using guessed type int dword_19C2E0;
// 19C2E4: using guessed type int dword_19C2E4;
// 19C2E8: using guessed type int dword_19C2E8;
// 19C2EC: using guessed type int16_t word_19C2EC;
// 19C2F0: using guessed type int16_t word_19C2F0;
// 19C2F2: using guessed type int16_t word_19C2F2;
// 19C318: using guessed type char byte_19C318;
// 19C319: using guessed type char byte_19C319;
// 19C31A: using guessed type char byte_19C31A;


//----- (0008E280) --------------------------------------------------------
int16_t __fastcall sub_8E280( int a1)
{
  int8_t v3; // al
  int16_t v4; // cx
  int16_t result; // ax
  char v6; // dl
  int16_t v7; // bx
  int v8; // eax
  int v9; // ebx

  sub_8C567(a1);
  v4 = v3;
  result = sub_8C6FE(a1, v3);
  v6 = result;
  if ( result == 3 || result == 1 || result == 2 )
  {
    v7 = word_1999A2;
    *(_WORD *)(2 * v4 + 113 * a1 + dword_19306C + 74) = word_1999A2;
    v8 = 17 * v7;
    v9 = dword_1930D4;
    *(_BYTE *)(dword_1930D4 + v8 + 3) = v4;
    *(_BYTE *)(v9 + v8 + 4) = v6;
    result = sub_8C5D7(a1);
    ++word_1999A2;
    ++dword_19C2C4;
  }
  return result;
}
// 8E290: variable 'v3' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1999A2: using guessed type int16_t word_1999A2;
// 19C2C4: using guessed type int dword_19C2C4;


//----- (0008E304) --------------------------------------------------------
char __fastcall sub_8E304(_WORD *a1, _WORD *a2)
{
  _WORD *v2; // ebx
  int16_t v3; // cx

  v2 = a1;
  *a1 = 0;
  v3 = 0;
  *a2 = 0;
  while ( v3 < word_19999A )
  {
    if ( !sub_79BAE(v3) )
      ++*v2;
    LOBYTE(a1) = sub_79B2D(v3);
    if ( !(_BYTE)a1 )
      ++*a2;
    ++v3;
  }
  return (char)a1;
}
// 19999A: using guessed type int16_t word_19999A;


//----- (0008E341) --------------------------------------------------------
int16_t __fastcall sub_8E341(
        int a1,
        int a2, int a3, int a4, int a5, int a6,
        int a7,
        int a8,
        int16_t *a9, int a10)
{
  int v12; // eax
  int v13; // ebx
  int v14; // edi
  int v15; // ecx
  _WORD v17[640]; // [esp+0h] [ebp-8D8h] BYREF
  _WORD v18[480]; // [esp+500h] [ebp-3D8h] BYREF
  int v19; // [esp+8C0h] [ebp-18h]
  int i; // [esp+8C4h] [ebp-14h]
  int v21; // [esp+8C8h] [ebp-10h]
  int v22; // [esp+8CCh] [ebp-Ch]
  int v23; // [esp+8D0h] [ebp-8h]
  char v24; // [esp+8D4h] [ebp-4h]

  v22 = a1;
  v23 = a2;
  memset(v17, -1, sizeof(v17));
  v24 = 0;
  memset(v18, -1, sizeof(v18));
  while ( a3 < a5 )
  {
    v17[a3] = a3;
    ++a3;
  }
  while ( a4 < a6 )
  {
    v18[a4] = a4;
    ++a4;
  }
  sub_79F26((int)v17, 640, 0);
  v21 = 0;
  LOWORD(v12) = sub_79F26((int)v18, 480, 0);
  while ( (int16_t)v21 < 640 && !v24 )
  {
    for ( i = 0; (int16_t)i < 480 && !v24; ++i )
    {
      v12 = 2 * (int16_t)v21;
      v13 = *(int16_t *)((char *)v17 + v12);
      v19 = v12;
      if ( v13 > -1 )
      {
        v14 = (int16_t)i;
        v15 = (int16_t)v18[v14];
        if ( v15 > -1 )
        {
          v12 = sub_7B0FB(v22, v23, v13, v15);
          if ( v12 >= a7 )
          {
            *(_WORD *)(a8 + 4 * *a9) = *(_WORD *)((char *)v17 + v19);
            *(_WORD *)(4 * (*a9)++ + a8 + 2) = v18[v14];
            LOWORD(v12) = *a9;
            if ( *a9 >= a10 )
              v24 = 1;
          }
        }
      }
    }
    ++v21;
  }
  return v12;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (0008E4E0) --------------------------------------------------------
char *__fastcall sub_8E4E0( int a1, int a2)
{
  char v3; // cl
  int16_t v4; // ax
  int v5; // ebx

  v3 = a2;
  memset(byte_19C31C, 0, 8);
  v4 = 0;
  byte_19C31C[0] = a2;
  do
  {
    v5 = v4++;
    byte_19C31C[v5] = a2++;
  }
  while ( v4 < 8 );
  switch ( a1 )
  {
    case 0:
      byte_19C31D = v3 + 3;
      byte_19C31E = v3 + 3;
      byte_19C31F = v3 + 4;
      byte_19C320 = v3 + 4;
      byte_19C323 = v3;
      byte_19C321 = v3 + 5;
      byte_19C322 = v3 + 5;
      break;
    case 1:
      byte_19C31D = v3 + 1;
      byte_19C31E = v3 + 2;
      byte_19C31F = v3 + 2;
      byte_19C320 = v3 + 3;
      byte_19C321 = v3 + 4;
      goto LABEL_8;
    case 2:
    case 3:
    case 4:
      byte_19C323 = v3 + 6;
      break;
    case 5:
      byte_19C31D = v3;
      byte_19C31E = v3 + 1;
      byte_19C31F = v3 + 1;
      byte_19C320 = v3 + 2;
      byte_19C321 = v3 + 3;
LABEL_8:
      byte_19C322 = v3 + 4;
      byte_19C323 = v3 + 4;
      break;
    default:
      return byte_19C31C;
  }
  return byte_19C31C;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19C31D: using guessed type char byte_19C31D;
// 19C31E: using guessed type char byte_19C31E;
// 19C31F: using guessed type char byte_19C31F;
// 19C320: using guessed type char byte_19C320;
// 19C321: using guessed type char byte_19C321;
// 19C322: using guessed type char byte_19C322;
// 19C323: using guessed type char byte_19C323;


//----- (0008E5C5) --------------------------------------------------------
char *__fastcall sub_8E5C5( unsigned int a1, int a2, int a3)
{
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  char v8; // al
  int v9; // esi
  int v10; // eax

  memset(byte_19C31C, 0, 8);
  if ( a1 < 2u )
  {
    v4 = 1;
    byte_19C31C[0] = a2;
    do
    {
      v5 = (int16_t)v4++;
      byte_19C31C[v5] = a3;
    }
    while ( (int16_t)v4 < 8 );
    goto LABEL_21;
  }
  if ( a1 <= 3u )
  {
    v6 = 1;
    byte_19C31C[0] = a2;
    do
    {
      v7 = (int16_t)v6++;
      byte_19C31C[v7] = a3;
    }
    while ( (int16_t)v6 < 8 );
    if ( !byte_199F34 )
    {
      v8 = a3;
      if ( a3 > a2 + 1 )
        v8 = a2 + 1;
      goto LABEL_13;
    }
LABEL_12:
    v8 = byte_199F34;
LABEL_13:
    byte_19C31E = v8;
    goto LABEL_21;
  }
  if ( a1 <= 4u )
  {
    v9 = 1;
    byte_19C31C[0] = a2;
    do
    {
      v10 = (int16_t)v9++;
      byte_19C31C[v10] = a3;
    }
    while ( (int16_t)v9 < 8 );
    if ( !byte_199F34 )
    {
      byte_19C31E = a3 - 1;
      goto LABEL_21;
    }
    goto LABEL_12;
  }
  if ( a1 == 5 )
  {
    byte_19C321 = a3;
    byte_19C31D = a2;
    byte_19C322 = a3;
    byte_19C323 = a3;
    byte_19C31E = a3 - 1;
    byte_19C31F = a3 - 1;
    byte_19C320 = a3 - 1;
  }
LABEL_21:
  byte_199F34 = 0;
  return byte_19C31C;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 199F34: using guessed type char byte_199F34;
// 19C31D: using guessed type char byte_19C31D;
// 19C31E: using guessed type char byte_19C31E;
// 19C31F: using guessed type char byte_19C31F;
// 19C320: using guessed type char byte_19C320;
// 19C321: using guessed type char byte_19C321;
// 19C322: using guessed type char byte_19C322;
// 19C323: using guessed type char byte_19C323;


//----- (0008E6DE) --------------------------------------------------------
int16_t *sub_8E6DE()
{
  unsigned int v0; // kr04_4
  int v1; // eax
  unsigned int v2; // ebx
  int16_t v3; // di
  int16_t i; // si
  char v5; // al
  unsigned int v6; // kr08_4
  int v8; // [esp+0h] [ebp-50h]
  char v9[32]; // [esp+4h] [ebp-4Ch] BYREF
  char v10[32]; // [esp+24h] [ebp-2Ch] BYREF
  int v11; // [esp+44h] [ebp-Ch]
  unsigned int v12; // [esp+48h] [ebp-8h]
  char v13; // [esp+4Ch] [ebp-4h]

  v11 = 0;
  v13 = 44;
  if ( byte_199CAE == 1 )
    v13 = 32;
  sprintf(v9, "%ld", abs32(v8));
  v0 = strlen(v9) + 1;
  v1 = ((int16_t)(v0 - 1) - 1) / 3;
  LOBYTE(word_18FF78) = 0;
  v2 = v0 - 1;
  v3 = v1;
  v12 = v1 + v0 - 1;
  if ( (_WORD)v1 )
  {
    for ( i = v1 + v0 - 1; i >= 0; --i )
    {
      if ( i == (_WORD)v12 )
      {
        --v2;
        v10[i] = 0;
      }
      else if ( (int16_t)v11 % 4 || (int16_t)v11 <= 1 || v3 <= 0 )
      {
        v5 = v9[(int16_t)v2--];
        v10[i] = v5;
      }
      else
      {
        --v3;
        v10[i] = v13;
      }
      ++v11;
    }
    strcpy((char *)&word_18FF78, v10);
  }
  else
  {
    sprintf(&word_18FF78, v9);
  }
  if ( v8 < 0 )
  {
    v6 = strlen((char *)&word_18FF78) + 1;
    memmove((char *)&word_18FF78 + 1, &word_18FF78, (int16_t)(v6 - 1));
    LOBYTE(word_18FF78) = 45;
    *((_BYTE *)&word_18FF78 + (int16_t)(v6 - 1) + 1) = 0;
  }
  return &word_18FF78;
}
// 8E706: variable 'v8' is possibly undefined
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 18FF78: using guessed type int16_t word_18FF78;
// 199CAE: using guessed type char byte_199CAE;


//----- (0008E822) --------------------------------------------------------
void __fastcall sub_8E822( int a1, int a2, int a3)
{
  memset(byte_19C31C, 0, 8);
  byte_19C31C[0] = a2;
  switch ( a1 )
  {
    case 0:
      byte_19C31D = a2 + a3 + 1;
      byte_19C31E = a2 + a3 + 1;
      byte_19C31F = a2 + a3 + 2;
      byte_19C320 = a2 + a3 + 2;
      byte_19C321 = a2 + a3 + 3;
      byte_19C322 = a2 + a3 + 4;
      goto LABEL_3;
    case 1:
      byte_19C31D = a2 + a3 + 1;
      byte_19C31E = a2 + a3 + 1;
      byte_19C31F = a2 + a3 + 2;
      byte_19C320 = a2;
      byte_19C321 = a2 + a3 + 2;
      byte_19C322 = a2 + a3 + 3;
LABEL_3:
      byte_19C323 = a2;
      break;
    case 2:
      byte_19C31D = a2 + a3 + 1;
      byte_19C31E = a2 + a3 + 1;
      byte_19C31F = a2 + a3 + 2;
      byte_19C320 = a2;
      goto LABEL_6;
    case 3:
      byte_19C31D = a2;
      byte_19C31E = a2;
      byte_19C31F = a2 + a3 + 1;
      byte_19C320 = a2 + a3 + 2;
LABEL_6:
      byte_19C321 = a2 + a3 + 3;
      byte_19C322 = a2 + a3 + 4;
      byte_19C323 = a2 + a3 + 4;
      break;
    case 4:
    case 5:
      byte_19C31E = a2 + a3 + 1;
      byte_19C31F = a2 + a3 + 1;
      byte_19C320 = a2 + a3 + 2;
      byte_19C321 = a2 + a3 + 3;
      byte_19C31D = a2;
      byte_19C322 = a2 + a3 + 4;
      byte_19C323 = a2 + a3 + 4;
      break;
    default:
      break;
  }
  JUMPOUT(0x8E6D5);
}
// 8E86B: control flows out of bounds to 8E6D5
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19C31D: using guessed type char byte_19C31D;
// 19C31E: using guessed type char byte_19C31E;
// 19C31F: using guessed type char byte_19C31F;
// 19C320: using guessed type char byte_19C320;
// 19C321: using guessed type char byte_19C321;
// 19C322: using guessed type char byte_19C322;
// 19C323: using guessed type char byte_19C323;


//----- (0008E94D) --------------------------------------------------------
int __fastcall sub_8E94D(int a1, int a2)
{
  int v4; // edx
  char v5; // ch
  int i; // eax

  v4 = 0;
  v5 = 0;
  for ( i = 0; (int16_t)i < a2 && !v5; ++i )
  {
    if ( ((a1 >> i) & 1) != 0 )
    {
      v5 = 1;
      v4 = i;
    }
  }
  return v4;
}


//----- (0008E98D) --------------------------------------------------------
int16_t __fastcall sub_8E98D( int a1)
{
  int16_t result; // ax
  uint8_t v2; // [esp+0h] [ebp-4h]

  v2 = word_1845D8;
  sub_1297C3(
    SHIWORD(dword_1BBA4A),
    SHIWORD(dword_1BBA4E),
    dword_1BBA4E - HIWORD(dword_1BBA4A) + 1,
    dword_1BBA52 - HIWORD(dword_1BBA4E) + 1,
    1,
    a1);
  sub_12B65C();
  result = v2;
  word_1845D8 = v2;
  return result;
}
// 1845D8: using guessed type int16_t word_1845D8;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (0008E9EB) --------------------------------------------------------
char __fastcall sub_8E9EB( int a1, int a2, int16_t *a3, char *a4, int a5)
{
  if ( (uint16_t)a1 < 0x280u && a1 + *a3 <= 639 && (uint16_t)a2 < 0x1E0u && a2 + a3[1] <= 479 )
    return sub_12A478(a1, a2, (int)a3);
  _wcpp_1_unwind_leave(0, 0, "XY: (%d,%d) [seg len: (%d,%d)]  out of range in %s (#%d)", a1, a2, *a3, a3[1], a4, a5);
  return sub_6497C();
}
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);


//----- (0008EA70) --------------------------------------------------------
char __fastcall sub_8EA70( int a1, int a2, int a3, char *a4, int a5)
{
  int16_t v6; // ax
  int v8; // [esp-Ch] [ebp-14h]

  if ( (uint16_t)a1 < 0x280u
    && a1 + (int16_t)sub_12066F(a3) <= 639
    && (uint16_t)a2 < 0x1E0u
    && a2 + sub_122259() <= 479 )
  {
    return sub_1212B3(a1, a2, a3);
  }
  v8 = sub_122259();
  v6 = sub_12066F(a3);
  _wcpp_1_unwind_leave(0, 0, "XY: (%d,%d) [seg len: (%d,%d)]  out of range in %s (#%d)", a1, a2, v6, v8, a4, a5);
  return sub_6497C();
}
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);


//----- (0008EB08) --------------------------------------------------------
char __fastcall sub_8EB08( unsigned int a1, unsigned int a2, int a3, char *a4, int a5)
{
  int16_t v6; // ax
  int16_t v7; // ax
  int v9; // [esp-Ch] [ebp-5Eh]
  char *v10; // [esp-8h] [ebp-5Ah]
  _BYTE v11[200]; // [esp+0h] [ebp-52h] BYREF
  char *v12; // [esp+C8h] [ebp+76h]
  int v13; // [esp+CCh] [ebp+7Ah]

  v12 = a4;
  itoa(a3, v11, 10, a3);
  if ( a1 < 0x280u )
  {
    v6 = sub_12066F((int)v11);
    v13 = (int16_t)a1;
    if ( (int16_t)a1 + v6 <= 639 && a2 < 0x1E0u && (int16_t)a2 + sub_122259() <= 479 )
      return sub_12102B(v13, (int16_t)a2, a3, a3);
  }
  v10 = v12;
  v9 = sub_122259();
  v7 = sub_12066F((int)v11);
  _wcpp_1_unwind_leave(
    0,
    0,
    "XY: (%d,%d) [seg len: (%d,%d)]  out of range in %s (#%d)",
    (int16_t)a1,
    (int16_t)a2,
    v7,
    v9,
    v10,
    a5);
  return sub_6497C();
}
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (0008EBBB) --------------------------------------------------------
void __fastcall sub_8EBBB( int a1)
{
  int16_t v2; // cx
  int v3; // eax
  char *v4; // ebx
  char v5; // dl
  _BYTE v6[8]; // [esp+0h] [ebp-8h] BYREF

  v2 = word_1B3E86;
  v3 = 0;
  do
  {
    v4 = &v6[(int16_t)v3];
    v5 = byte_1B3E7C[(int16_t)v3++];
    *v4 = v5;
  }
  while ( (int16_t)v3 < 8 );
  sub_120BB5(a1, (int)v6);
  word_1B3E86 = v2;
  JUMPOUT(0x8E803);
}
// 8EBF9: control flows out of bounds to 8E803
// 1B3E86: using guessed type int16_t word_1B3E86;


//----- (0008EBFE) --------------------------------------------------------
int __fastcall sub_8EBFE( int a1)
{
  int v2; // edx
  char *v3; // ebx
  char v4; // al
  int16_t i; // ax
  char v6; // dl
  char v7; // bl
  int v8; // edx
  int v9; // ebx
  int result; // eax
  char v11; // cl
  _BYTE v12[8]; // [esp+0h] [ebp-8h] BYREF

  v2 = 0;
  do
  {
    v3 = &v12[(int16_t)v2];
    v4 = byte_1B3E7C[(int16_t)v2++];
    *v3 = v4;
  }
  while ( (int16_t)v2 < 8 );
  for ( i = 1; i < 8; ++i )
  {
    v6 = v12[i] - a1;
    if ( (uint8_t)v12[i] - a1 <= 0 )
      v6 = 0;
    v7 = v6;
    v8 = i;
    v12[v8] = v7;
  }
  v9 = 0;
  do
  {
    result = (int16_t)v9;
    v11 = v12[(int16_t)v9];
    byte_1B3E88[(int16_t)v9++] = v11;
    byte_1B3E7C[result] = v11;
  }
  while ( (int16_t)v9 < 8 );
  return result;
}


//----- (0008EC70) --------------------------------------------------------
void __fastcall sub_8EC70( int a1, int a2, int a3, int a4,
        int a5, unsigned int a6, unsigned int a7)
{
  int v7; // esi
  int v8; // [esp+0h] [ebp-36h]
  int v9; // [esp+4h] [ebp-32h]
  int16_t v10; // [esp+18h] [ebp-1Eh]
  int16_t v11; // [esp+38h] [ebp+2h]
  int16_t v12; // [esp+40h] [ebp+Ah]
  int v13; // [esp+48h] [ebp+12h]
  int v14; // [esp+4Ch] [ebp+16h]
  int v15; // [esp+50h] [ebp+1Ah]
  int v16; // [esp+54h] [ebp+1Eh]
  int v17; // [esp+58h] [ebp+22h]
  int v18; // [esp+5Ch] [ebp+26h]
  int v19; // [esp+60h] [ebp+2Ah]
  int v20; // [esp+64h] [ebp+2Eh]
  int v21; // [esp+68h] [ebp+32h]
  int v22; // [esp+6Ch] [ebp+36h]
  int v23; // [esp+70h] [ebp+3Ah]
  int v24; // [esp+74h] [ebp+3Eh]
  int16_t v25; // [esp+78h] [ebp+42h]
  int16_t v26; // [esp+7Ch] [ebp+46h]
  int16_t v27; // [esp+80h] [ebp+4Ah]
  int16_t v28; // [esp+84h] [ebp+4Eh]

  v7 = a5;
  sub_128B49();
  v10 = word_1845D8;
  if ( !(_WORD)a5 )
    v7 = 16;
  if ( (int16_t)v7 * (int16_t)(640 / (int16_t)v7) != 640 || (int16_t)v7 * (int16_t)(480 / (int16_t)v7) != 480 )
    v7 = 16;
  sub_128AB6(a1, a2, a3, a4);
  sub_12B634();
  v11 = 480 / (int16_t)v7;
  v12 = 640 / (int16_t)v7;
  v20 = 1;
  v26 = 0;
  v19 = 481;
  v22 = -1;
  v21 = 479;
  while ( v26 < v12 )
  {
    sub_134D2D((int16_t)v22, 0, (int16_t)v21, 480, a7);
    sub_134D2D((int16_t)v20, 0, (int16_t)v19, 480, a7);
    sub_134D2D((int16_t)(v7 * v26), 0, (int16_t)(v7 * v26 + 480), 480, a6);
    v20 += v7;
    v19 += v7;
    v22 += v7;
    ++v26;
    v21 += v7;
  }
  v13 = 481;
  v27 = 0;
  v18 = 479;
  while ( v27 < v11 )
  {
    v8 = (int16_t)(v7 * v27);
    sub_134D2D(-1, v8, (int16_t)v18, 480, a7);
    sub_134D2D(1, v8, (int16_t)v13, 480, a7);
    sub_134D2D(0, v8, (int16_t)(480 - v7 * v27), 480, a6);
    v13 -= v7;
    ++v27;
    v18 -= v7;
  }
  v25 = 0;
  v24 = 1;
  v17 = -1;
  while ( v25 < v11 )
  {
    v9 = (int16_t)(v7 * v25);
    sub_134D2D((int16_t)v17, 0, 1, v9, a7);
    sub_134D2D((int16_t)v24, 0, 1, v9, a7);
    sub_134D2D(v9, 0, 0, v9, a6);
    v24 += v7;
    ++v25;
    v17 += v7;
  }
  v28 = 0;
  v15 = 1;
  v23 = -1;
  v16 = 481;
  v14 = 479;
  while ( v28 < v12 )
  {
    sub_134D2D((int16_t)v23, 480, (int16_t)v14, 0, a7);
    sub_134D2D((int16_t)v15, 480, (int16_t)v16, 0, a7);
    sub_134D2D((int16_t)(v7 * v28), 480, (int16_t)(v7 * v28 + 480), 0, a6);
    v15 += v7;
    v16 += v7;
    v23 += v7;
    ++v28;
    v14 += v7;
  }
  sub_128B98();
  if ( v10 )
    sub_12B634();
  else
    sub_12B65C();
}
// 1845D8: using guessed type int16_t word_1845D8;


//----- (0008EFE1) --------------------------------------------------------
int __fastcall sub_8EFE1( unsigned int a1,
        int16_t *a2, int a3,
        int16_t *a4,
        int a5, int a6, int a7,
        char *a8,
        int16_t *a9, int a10)
{
  int16_t *v10; // eax
  int v11; // ebx
  int v12; // eax
  int result; // eax
  int16_t v14; // [esp+0h] [ebp-10h] BYREF
  int16_t v15; // [esp+4h] [ebp-Ch] BYREF
  int16_t v16; // [esp+8h] [ebp-8h] BYREF
  int16_t v17; // [esp+Ch] [ebp-4h] BYREF

  sub_120BB5(a1, (int)a4);
  v10 = sub_8F399(*a2, a3, &v17, &v16, &v14, &v15, a8, a10);
  sub_FE8BE((int)v10, a3, (int)&v17, a4);
  v11 = v14;
  LOWORD(v12) = sub_8FC82(0, 0, v14, v15, 0, (int)a4, a5, 8u, a9);
  sub_FE8BE(v12, 0, v11, a4);
  result = sub_12A478(a6, a7, (int)a9);
  ++*a2;
  return result;
}
// 8F037: variable 'v12' is possibly undefined


//----- (0008F055) --------------------------------------------------------
int __fastcall sub_8F055( int a1, int a2, int a3, int a4, unsigned int a5)
{
  int16_t v5; // di
  int16_t v7; // [esp+4h] [ebp-8h]
  uint8_t v8[4]; // [esp+8h] [ebp-4h] BYREF

  v8[1] = a5 + 1;
  v8[2] = a5 + 2;
  v5 = a1 + 2;
  v8[0] = a5;
  v8[3] = a5 + 3;
  sub_90006(a1 + 3, a2 + 3, a1 + 2 + v7 - 1, a2 + 2 + a4 - 1);
  return sub_8F0BD(v5, a2 + 2, v7, a4, v8);
}
// 8F086: variable 'v7' is possibly undefined


//----- (0008F0BD) --------------------------------------------------------
int __fastcall sub_8F0BD( int a1, int a2, int a3, int a4, uint8_t *a5)
{
  int v5; // esi
  int v6; // edi
  int v8; // [esp+0h] [ebp-30h]
  int v9; // [esp+4h] [ebp-2Ch]
  int v10; // [esp+8h] [ebp-28h]
  int16_t v11; // [esp+Ch] [ebp-24h]
  int v12; // [esp+14h] [ebp-1Ch]
  int16_t v13; // [esp+1Ch] [ebp-14h]
  uint8_t v15; // [esp+24h] [ebp-Ch]
  uint8_t v16; // [esp+28h] [ebp-8h]
  uint8_t v17; // [esp+2Ch] [ebp-4h]

  v17 = *a5;
  v16 = a5[1];
  v15 = a5[2];
  v13 = a3 + a1;
  v11 = a5[3];
  v9 = (int16_t)(a3 + a1);
  v10 = a1;
  sub_134D2D(a1, a2, (int16_t)(a3 + a1), a2, v11);
  v5 = (int16_t)(a2 + 1);
  sub_134D2D(v9, a2, v9, (int16_t)(a4 + a2), v11);
  v6 = (int16_t)(v13 - 1);
  v12 = (int16_t)(a1 + 1);
  sub_134D2D(v12, v5, v6, v5, v15);
  v8 = (int16_t)(a4 + a2 - 1);
  sub_134D2D(v6, v5, v6, v8, v15);
  sub_134D2D(v10, v5, v10, (int16_t)(a4 + a2), v17);
  sub_134D2D(v10, (int16_t)(a4 + a2), v9, (int16_t)(a4 + a2), v17);
  sub_134D2D(v12, v5, v12, v8, v16);
  return sub_134D2D(v12, v8, v6, v8, v16);
}


//----- (0008F1C4) --------------------------------------------------------
void __fastcall sub_8F1C4(void (__fastcall *a1)(int, int), _BYTE *a2, int a3)
{
  int v3; // eax
  int v4; // eax

  sub_1172D4();
  *a2 = 1;
  sub_131922(0, 255);
  sub_123E6C((int)&unk_17CF4A, 1);
  sub_C5BB9();
  sub_1205E6(a3, 0, 255);
  sub_1318D4(0, 255);
  sub_131F7B();
  sub_132C80(100);
  sub_123E6C((int)&unk_17CF00, 1);
  v3 = sub_124D41();
  a1(v3, 1);
  sub_131922(0, 255);
  if ( byte_199F38 )
  {
    sub_C5B94(0);
    v4 = sub_132C80(0);
  }
  else
  {
    sub_C5C44();
  }
  sub_1077D(v4);
  byte_199F38 = 0;
  sub_1172FC();
}
// 8F25B: variable 'v4' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 199F38: using guessed type char byte_199F38;


//----- (0008F26E) --------------------------------------------------------
int __usercall sub_8F26E(int16_t *a1)
{
  int v1; // eax

  sub_C5BB9();
  sub_124D41();
  LOBYTE(v1) = sub_128C32(0, 0, 639, 479, 0);
  return sub_1077D(v1, 0, 639, a1);
}
// 8F290: variable 'v1' is possibly undefined


//----- (0008F299) --------------------------------------------------------
int __usercall sub_8F299( int a1, int16_t *a2)
{
  int v3; // eax

  sub_124B65();
  sub_C5BB9();
  sub_124D41();
  LOBYTE(v3) = sub_128C32(0, 0, 639, 479, 0);
  sub_1077D(v3, 0, 639, a2);
  return sub_1205E6(a1, 0, 255);
}
// 8F2C3: variable 'v3' is possibly undefined


//----- (0008F2DC) --------------------------------------------------------
int __fastcall sub_8F2DC(int a1, int a2, int a3, int a4, int a5, _WORD *a6)
{
  int result; // eax
  int i; // edx
  int v9; // ebx
  int16_t v10; // [esp+0h] [ebp-Ch]
  int16_t v11; // [esp+8h] [ebp-4h]

  v11 = *a6;
  for ( result = a2; result < a4; ++result )
  {
    for ( i = v10; i < a3; ++i )
    {
      v9 = i + result * v11;
      *((_BYTE *)a6 + v9 + 16) = a5;
    }
  }
  return result;
}
// 8F2FE: variable 'v10' is possibly undefined


//----- (0008F328) --------------------------------------------------------
void __fastcall sub_8F328( int a1, int a2, int a3, int a4, int a5, _WORD *a6)
{
  int i; // edx
  int j; // eax
  int16_t v9; // [esp+8h] [ebp-Ch]
  int16_t v10; // [esp+Ch] [ebp-8h]

  v10 = *a6;
  v9 = a6[1];
  for ( i = 0; i < v9; ++i )
  {
    for ( j = 0; j < v10; ++j )
    {
      if ( j < a1 || j > a3 || i < a2 || i > a4 )
        *((_BYTE *)a6 + j + i * v10 + 16) = a5;
    }
  }
  JUMPOUT(0x8F322);
}
// 8F397: control flows out of bounds to 8F322


//----- (0008F399) --------------------------------------------------------
int16_t *__fastcall sub_8F399( int a1, int a2,
        int16_t *a3,
        _WORD *a4,
        int16_t *a5,
        int16_t *a6,
        char *a7, int a8)
{
  int16_t v8; // dx
  int16_t v9; // di
  int v10; // eax
  int16_t v11; // ax
  int v12; // eax
  int16_t v13; // dx
  int16_t *result; // eax
  int16_t v17; // [esp+8h] [ebp-8h]

  v8 = sub_12066F((int)a7);
  v17 = v8;
  strlen(a7);
  v9 = sub_122259();
  if ( v8 >= a2 )
  {
    if ( a8 )
      a1 = a2 - 1;
    v12 = (10 * v8 / a2 + 9) / 10;
    *a3 = v12 * a1;
    if ( (int16_t)(v12 * a1) > v8 )
      *a3 = v8;
    v13 = v12 + *a3;
    *a5 = v13;
    if ( v13 > v17 )
      goto LABEL_16;
  }
  else
  {
    *a3 = 0;
    *a5 = 0;
    if ( !(a1 % ((10 * a2 / v8 + 9) / 10)) || a8 )
    {
      v10 = 10 * a1 * v8 / a2 / 10;
      *a3 = v10;
      if ( (int16_t)v10 > v8 )
        *a3 = v8;
      v11 = a8 ? v8 : *a3 + 1;
      *a5 = v11;
      if ( *a5 > v8 )
LABEL_16:
        *a5 = v17;
    }
  }
  *a4 = 0;
  result = a6;
  *a6 = v9;
  return result;
}


//----- (0008F4BA) --------------------------------------------------------
int16_t __fastcall sub_8F4BA(_WORD *a1, _WORD *a2, _WORD *a3)
{
  int16_t result; // ax

  *a2 = *a1;
  result = a1[1];
  *a3 = result;
  return result;
}


//----- (0008F4CA) --------------------------------------------------------
int16_t *__fastcall sub_8F4CA( int a1, int a2, int16_t *a3, _WORD *a4, int16_t *a5, int16_t *a6, char *a7)
{
  int16_t v7; // si
  int v8; // edx
  int16_t v9; // cx
  int16_t v10; // ax
  int16_t *result; // eax

  v7 = sub_12066F((int)a7);
  strlen(a7);
  v8 = (10 * v7 / a2 + 9) / 10;
  v9 = sub_122259();
  *a3 = v8 * a1;
  if ( v7 < (int16_t)(v8 * a1) )
    *a3 = v7;
  v10 = v8 + *a3;
  *a5 = v10;
  if ( v10 > v7 )
    *a5 = v7;
  *a4 = 0;
  result = a6;
  *a6 = v9;
  return result;
}


//----- (0008F548) --------------------------------------------------------
void __fastcall sub_8F548(char *a1, char *a2, char *a3, int a4)
{
  int64_t v4; // rax
  int16_t v5; // cx
  int16_t v6; // si
  char *v7; // edi
  unsigned int v8; // eax
  _BYTE v12[44]; // [esp+10h] [ebp-54h] BYREF
  char v13[16]; // [esp+3Ch] [ebp-28h] BYREF
  char v14[16]; // [esp+4Ch] [ebp-18h] BYREF
  unsigned int v15; // [esp+5Ch] [ebp-8h]
  char v16; // [esp+60h] [ebp-4h]

  v4 = sprintf(a1, "%s.%s", a2, a3);
  v16 = 0;
  v15 = -2;
  v5 = 0;
  sprintf(v14, "%s.*", (char *)HIDWORD(v4));
  do
  {
    v6 = 0;
    sprintf(v14, "%s%2d.%s", a2, v5, a3);
    while ( v6 < 16 && v14[v6] )
    {
      if ( v14[v6] == 32 )
        v14[v6] = 48;
      ++v6;
    }
    if ( unknown_libname_1(v14, 0, v12) )
    {
      v7 = a1;
      v16 = 1;
LABEL_12:
      strcpy(v7, v14);
      goto LABEL_13;
    }
    sub_8F76D((int)v14);
    if ( v8 < v15 )
    {
      v7 = v13;
      v15 = v8;
      goto LABEL_12;
    }
LABEL_13:
    ++v5;
  }
  while ( !v16 && v5 < a4 );
  if ( !v16 )
    strcpy(a1, v13);
}
// 8F5E5: variable 'v8' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 139A4C: using guessed type int __fastcall unknown_libname_1(_DWORD, _DWORD, _DWORD);


//----- (0008F625) --------------------------------------------------------
int __fastcall sub_8F625(int a1)
{
  int result; // eax
  char *v3; // ebx
  char v4; // dl

  result = 0;
  do
  {
    v3 = (char *)(a1 + (int16_t)result);
    v4 = byte_1B3E7C[(int16_t)result++];
    *v3 = v4;
  }
  while ( (int16_t)result < 8 );
  return result;
}


//----- (0008F645) --------------------------------------------------------
int16_t sub_8F645()
{
  return word_1B3EA6;
}
// 1B3EA6: using guessed type int16_t word_1B3EA6;


//----- (0008F64C) --------------------------------------------------------
int16_t sub_8F64C()
{
  return HIWORD(dword_1B61E4);
}
// 1B61E4: using guessed type int dword_1B61E4;


//----- (0008F653) --------------------------------------------------------
void __fastcall sub_8F653(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // ebx
  int v11; // eax
  int16_t v12; // dx
  int v13; // ecx
  _DWORD v14[5]; // [esp+0h] [ebp-1Ch]
  int v15; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]

  v6 = (int16_t)a1;
  v15 = a3 - a1 + 1;
  v16 = a4 - a2 + 1;
  v7 = (a5 - (int16_t)a1) * (a5 - (int16_t)a1);
  v14[4] = a6;
  v8 = (int16_t)a2;
  v9 = (a6 - (int16_t)a2) * (a6 - (int16_t)a2);
  v14[0] = v7 + v9;
  v10 = (a5 - ((int16_t)v15 + v6)) * (a5 - ((int16_t)v15 + v6));
  v11 = (a6 - ((int16_t)v16 + v8)) * (a6 - ((int16_t)v16 + v8));
  v14[1] = v10 + v9;
  v12 = 0;
  v14[2] = v11 + v7;
  v14[3] = v11 + v10;
  v13 = -999999;
  while ( 1 )
  {
    if ( v13 < v14[v12] )
      v13 = v14[v12];
    if ( ++v12 >= 4 )
      JUMPOUT(0x8F322);
  }
}
// 8F6DA: control flows out of bounds to 8F322


//----- (0008F6DF) --------------------------------------------------------
char __fastcall sub_8F6DF( unsigned int a1, char *a2)
{
  char result; // al

  strcpy(a2, sub_7A990(a1));
  return result;
}


//----- (0008F6F8) --------------------------------------------------------
char *__fastcall sub_8F6F8( unsigned int a1, int a2, int a3, char *a4)
{
  char *result; // eax

  result = sub_8E5C5(a1, a2, a3);
  qmemcpy(a4, result, 8u);
  return result;
}


//----- (0008F72D) --------------------------------------------------------
int16_t __fastcall sub_8F72D(int a1, _WORD *a2, _WORD *a3, _WORD *a4, _WORD *a5, _WORD *a6, _WORD *a7)
{
  int *v7; // eax
  int16_t result; // ax

  v7 = sub_111660(a1);
  *a4 = *((_WORD *)v7 + 10);
  *a2 = *((_WORD *)v7 + 8);
  *a3 = *((_WORD *)v7 + 6);
  *a5 = *((_WORD *)v7 + 4);
  *a6 = *((_WORD *)v7 + 2);
  result = *(_WORD *)v7;
  *a7 = result;
  return result;
}


//----- (0008F76D) --------------------------------------------------------
void __fastcall sub_8F76D(int a1)
{
  sub_111660(a1);
  JUMPOUT(0x8E803);
}
// 8F7D2: control flows out of bounds to 8E803


//----- (0008F7D7) --------------------------------------------------------
void sub_8F7D7()
{
  JUMPOUT(0x8F276);
}
// 8F7DA: control flows out of bounds to 8F276


//----- (0008F7DF) --------------------------------------------------------
void __fastcall sub_8F7DF( int a1)
{
  int v2; // edx
  char *v3; // ebx
  char v4; // al
  int16_t v5; // ax
  int v6; // edx
  char v7; // bl
  int v8; // edx
  int v9; // ebx
  int v10; // eax
  char v11; // cl
  _BYTE v12[8]; // [esp+0h] [ebp-8h] BYREF

  v2 = 0;
  do
  {
    v3 = &v12[(int16_t)v2];
    v4 = byte_1B3E7C[(int16_t)v2++];
    *v3 = v4;
  }
  while ( (int16_t)v2 < 8 );
  v5 = 1;
  while ( 1 )
  {
    v6 = (uint8_t)v12[v5] + a1;
    if ( v6 >= 255 )
      LOBYTE(v6) = -1;
    v7 = v6;
    v8 = v5++;
    v12[v8] = v7;
    if ( v5 >= 8 )
    {
      v9 = 0;
      do
      {
        v10 = (int16_t)v9;
        v11 = v12[(int16_t)v9];
        byte_1B3E88[(int16_t)v9++] = v11;
        byte_1B3E7C[v10] = v11;
      }
      while ( (int16_t)v9 < 8 );
      JUMPOUT(0x8EC6A);
    }
  }
}
// 8F850: control flows out of bounds to 8EC6A


//----- (0008F855) --------------------------------------------------------
int16_t sub_8F855()
{
  int16_t result; // ax

  if ( (uint8_t)byte_19C324 >= 0x10u )
    byte_19C324 = 0;
  result = sub_123E6C((int)&unk_182248 + 12 * ((int)(uint8_t)byte_19C324 >> 2), 1);
  ++byte_19C324;
  return result;
}
// 19C324: using guessed type char byte_19C324;


//----- (0008F8DC) --------------------------------------------------------
char __fastcall sub_8F8DC( unsigned int a1)
{
  char v1; // ah
  _BOOL1 v2; // zf

  v1 = 0;
  if ( a1 < 0x55u )
  {
    if ( a1 < 0x45u )
    {
      if ( a1 != 65 )
        goto LABEL_20;
      goto LABEL_19;
    }
    if ( a1 > 0x45u )
    {
      if ( a1 < 0x49u )
        goto LABEL_20;
      if ( a1 > 0x49u )
      {
        v2 = a1 == 79;
        goto LABEL_8;
      }
    }
LABEL_19:
    v1 = 1;
    goto LABEL_20;
  }
  if ( a1 <= 0x55u )
    goto LABEL_19;
  if ( a1 < 0x69u )
  {
    if ( a1 < 0x61u )
      goto LABEL_20;
    if ( a1 <= 0x61u )
      goto LABEL_19;
    v2 = a1 == 101;
  }
  else
  {
    if ( a1 <= 0x69u )
      goto LABEL_19;
    if ( a1 < 0x6Fu )
      goto LABEL_20;
    if ( a1 <= 0x6Fu )
      goto LABEL_19;
    v2 = a1 == 117;
  }
LABEL_8:
  if ( v2 )
    goto LABEL_19;
LABEL_20:
  if ( byte_199CAE == 2 )
  {
    if ( a1 < 0x3Du )
    {
      if ( a1 < 0x23u || a1 > 0x24u && a1 != 38 )
        return v1;
      return 1;
    }
    if ( a1 <= 0x3Eu )
      return 1;
    if ( a1 < 0x5Du )
    {
      if ( a1 != 91 )
        return v1;
      return 1;
    }
    if ( a1 <= 0x5Du )
      return 1;
    if ( a1 >= 0x7Bu )
    {
      if ( a1 > 0x7Du )
        return v1;
      return 1;
    }
  }
  return v1;
}
// 199CAE: using guessed type char byte_199CAE;


//----- (0008F950) --------------------------------------------------------
int16_t __fastcall sub_8F950(int a1, unsigned int a2, int a3)
{
  int16_t i; // dx
  _BYTE *v5; // eax
  int v6; // ecx
  int16_t result; // ax

  for ( i = 1; ; ++i )
  {
    result = a2;
    if ( i >= a2 )
      break;
    v5 = (_BYTE *)(a1 + i);
    v6 = (uint8_t)*v5 + a3;
    if ( v6 >= 0 )
    {
      if ( v6 <= 255 )
        *v5 += a3;
      else
        *v5 = -1;
    }
    else
    {
      *v5 = 0;
    }
  }
  return result;
}


//----- (0008F99A) --------------------------------------------------------
void __fastcall sub_8F99A(char *a1, char *a2)
{
  char v3; // al
  char *v4; // edi
  char *v5; // edi
  char v6; // al
  char *v7; // edi
  char *v8; // edi
  char *v9; // [esp-4h] [ebp-44h] BYREF
  char v10[20]; // [esp+0h] [ebp-40h] BYREF
  char v11[20]; // [esp+14h] [ebp-2Ch] BYREF
  char v12[8]; // [esp+28h] [ebp-18h] BYREF
  char v13; // [esp+30h] [ebp-10h] BYREF
  char v14; // [esp+31h] [ebp-Fh]
  char v15; // [esp+32h] [ebp-Eh]
  char *v16; // [esp+38h] [ebp-8h]
  int v17; // [esp+3Ch] [ebp-4h]

  v16 = a2;
  v17 = 0;
  strcpy(v12, ".LOG");
  sub_132F5C((int)a2);
  do
  {
    v9 = v10;
    strcpy(v10, v16);
    itoa((int16_t)v17, &v13, 10, a1);
    if ( (int16_t)v17 < 10 )
    {
      v3 = v13;
      v15 = 0;
      v13 = 48;
      v14 = v3;
    }
    v9 = v10;
    v4 = (char *)&v9 + 3;
    do
      ++v4;
    while ( *v4 );
    strcpy(v4, &v13);
    v9 = v10;
    v5 = (char *)&v9 + 3;
    do
      ++v5;
    while ( *v5 );
    strcpy(v5, v12);
    v9 = v11;
    strcpy(v11, v10);
    FindMoxSetPath_1114D7(v11, v10);
    if ( strcmp(v11, v10) )
      goto LABEL_11;
    ++v17;
  }
  while ( (int16_t)v17 <= 99 );
  v17 = 99;
LABEL_11:
  HIBYTE(v9) = HIBYTE(a1);
  strcpy(a1, v16);
  itoa((int16_t)v17, &v13, 10, a1);
  if ( (int16_t)v17 < 10 )
  {
    v6 = v13;
    v15 = 0;
    v13 = 48;
    v14 = v6;
  }
  v9 = a1;
  v7 = a1 - 1;
  do
    ++v7;
  while ( *v7 );
  strcpy(v7, &v13);
  v8 = v9 - 1;
  do
    ++v8;
  while ( *v8 );
  strcpy(v8, aDat);
  sub_132F5C((int)a1);
  JUMPOUT(0x8E987);
}
// 8FACA: control flows out of bounds to 8E987
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);


//----- (0008FACF) --------------------------------------------------------
int __fastcall sub_8FACF( int a1, int a2)
{
  int v2; // ebx

  v2 = a1 / (int16_t)a2;
  if ( a1 % (int16_t)a2 > 0 )
    ++v2;
  return a2 * v2;
}


//----- (0008FAF6) --------------------------------------------------------
_BOOL1 __fastcall sub_8FAF6( int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  return (a1 >= a5 && a1 <= a7 || a3 >= a5 && a3 <= a7 || a1 <= a5 && a3 >= a5 || a1 <= a7 && a3 >= a7)
      && (a2 >= a6 && a2 <= a8 || a4 >= a6 && a4 <= a8 || a2 <= a6 && a4 >= a6 || a2 <= a8 && a4 >= a8);
}


//----- (0008FB65) --------------------------------------------------------
int __fastcall sub_8FB65( int a1, int a2)
{
  return a1 * a2 / 30;
}


//----- (0008FB79) --------------------------------------------------------
void sub_8FB79()
{
  int v0; // ebx
  char *v1; // edi
  int v2; // edx
  char *v3; // ecx
  int v4; // [esp-10h] [ebp-30h]
  int v5; // [esp-8h] [ebp-28h]
  _DWORD v6[8]; // [esp+0h] [ebp-20h]

  v0 = 1;
  v1 = (char *)sub_126ABD((int)aDisplayLbx, 0);
  v6[0] = v1;
  v2 = 0;
  _wcpp_1_unwind_leave(0, 0, "0> %s", v1);
  while ( 1 )
  {
    while ( v1[(int16_t)v2] )
      ++v2;
    while ( 1 )
    {
      v3 = &v1[(int16_t)v2];
      if ( *v3 )
        break;
      ++v2;
    }
    v5 = (int16_t)v0;
    v4 = (int16_t)v0++;
    v6[v5] = v3;
    _wcpp_1_unwind_leave(0, v4, "%d> %s", v5, &v1[(int16_t)v2]);
    if ( (int16_t)v0 >= 8 )
    {
      sub_6497C();
      JUMPOUT(0x8E803);
    }
  }
}
// 8FBEA: control flows out of bounds to 8E803
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);


//----- (0008FBEF) --------------------------------------------------------
void __fastcall sub_8FBEF(char *a1, char *a2)
{
  unsigned int v3; // kr04_4
  int16_t v4; // si
  unsigned int v5; // kr08_4
  int16_t i; // ax
  _BOOL1 j; // cl
  char *v8; // edi
  int16_t v9; // [esp+8h] [ebp-Ch]

  v3 = strlen(a1) + 1;
  v4 = 0;
  v5 = strlen(a2) + 1;
  for ( i = 0; i < (int16_t)(v3 - 1); ++i )
  {
    v9 = 0;
    for ( j = 0; v9 < (int16_t)(v5 - 1) && !j; j = a1[i] == a2[v9++] )
      ;
    if ( !j )
    {
      v8 = (char *)&a1[v4++];
      *v8 = a1[i];
    }
  }
  a1[v4] = 0;
  JUMPOUT(0x8E987);
}
// 8FC7D: control flows out of bounds to 8E987


//----- (0008FC82) --------------------------------------------------------
int16_t __fastcall sub_8FC82(
        int a1, int a2,
        int a3, int a4, int a5,
        int a6,
        int a7, unsigned int a8,
        int16_t *a9)
{
  int16_t result; // ax
  int16_t v11; // bx
  int16_t i; // dx
  int16_t v13; // [esp+0h] [ebp-1Ch]
  int16_t v14; // [esp+4h] [ebp-18h]
  _WORD *v15; // [esp+Ch] [ebp-10h]
  int16_t v16; // [esp+14h] [ebp-8h]
  char v17; // [esp+18h] [ebp-4h]

  v16 = *a9;
  result = a9[1];
  if ( a5 )
  {
    v14 = 0;
    a4 = a9[1];
    a2 = 0;
    v13 = *a9;
  }
  v11 = a2;
  v15 = a9 + 8;
  while ( v11 < a4 )
  {
    for ( result = v14; result < v13; ++result )
    {
      v17 = *((_BYTE *)v15 + v11 * v16 + result);
      for ( i = 0; i < a8; ++i )
      {
        if ( v17 == *(_BYTE *)(i + a6) )
        {
          v17 = *(_BYTE *)(i + a7);
          *((_BYTE *)v15 + v11 * v16 + result) = v17;
        }
      }
    }
    ++v11;
  }
  return result;
}
// 8FCBE: variable 'v14' is possibly undefined
// 8FD13: variable 'v13' is possibly undefined


//----- (0008FD21) --------------------------------------------------------
char *__fastcall sub_8FD21(char *a1, int a2, int a3)
{
  char *result; // eax
  unsigned int v6; // kr04_4
  int16_t i; // dx

  result = 0;
  v6 = strlen(a1) + 1;
  for ( i = 0; i < (int16_t)(v6 - 1); ++i )
  {
    result = (char *)&a1[i];
    if ( *result == a2 )
      *result = a3;
  }
  return result;
}


//----- (0008FD56) --------------------------------------------------------
void __fastcall sub_8FD56( int a1)
{
  sub_128B98();
  if ( a1 )
    sub_12B634();
  else
    sub_12B65C();
}


//----- (0008FD71) --------------------------------------------------------
int16_t __fastcall sub_8FD71(_WORD *a1)
{
  int16_t result; // ax

  sub_128B49();
  result = word_1845D8;
  *a1 = word_1845D8;
  return result;
}
// 1845D8: using guessed type int16_t word_1845D8;


//----- (0008FD84) --------------------------------------------------------
int __fastcall sub_8FD84( int a1)
{
  return ((int16_t)(10 * a1 / 3) + 5) / 10;
}


//----- (0008FDA1) --------------------------------------------------------
void __fastcall sub_8FDA1(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int16_t v8; // [esp+0h] [ebp-8h]
  char v9; // [esp+4h] [ebp-4h]

  v9 = 0;
  v8 = a4;
  if ( a5 == -1 )
    a5 = 0;
  while ( 1 )
  {
    sub_120BB5(a3, a2);
    sub_120E8C(a4);
    word_1B3E86 = a5;
    if ( (int16_t)sub_12066F(a1) < a6 || (--a4, a4 < 1) && (--a3, a4 = v8, a3 < a7) )
      v9 = 1;
    if ( v9 )
      JUMPOUT(0x8F542);
  }
}
// 8FE05: control flows out of bounds to 8F542
// 1B3E86: using guessed type int16_t word_1B3E86;


//----- (0008FE0A) --------------------------------------------------------
int __fastcall sub_8FE0A(int a1)
{
  int v2; // ebx
  int result; // eax
  char v4; // cl

  v2 = 0;
  do
  {
    result = (int16_t)v2;
    v4 = *(_BYTE *)(a1 + (int16_t)v2);
    byte_1B3E88[(int16_t)v2++] = v4;
    byte_1B3E7C[result] = v4;
  }
  while ( (int16_t)v2 < 8 );
  return result;
}


//----- (0008FE2E) --------------------------------------------------------
int16_t sub_8FE2E()
{
  int16_t result; // ax

  result = word_1B43B8[SHIWORD(dword_1B61E4)];
  word_1B3EA6 = result;
  return result;
}
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1B43B8: using guessed type int16_t word_1B43B8[];
// 1B61E4: using guessed type int dword_1B61E4;


//----- (0008FE44) --------------------------------------------------------
int __fastcall sub_8FE44(int a1, int a2)
{
  if ( a2 <= 0 )
    return 0;
  else
    return (1000 * a1 / a2 + 5) / 10;
}


//----- (0008FE65) --------------------------------------------------------
unsigned int __fastcall sub_8FE65(char *a1)
{
  int v2; // eax

  v2 = ((int (*)(void))strstr)();
  if ( v2 )
    return v2 - (_DWORD)a1;
  else
    return strlen(a1);
}


//----- (0008FE88) --------------------------------------------------------
void __fastcall sub_8FE88(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int16_t *a8)
{
  int16_t i; // bx
  int16_t j; // ax
  int16_t v10; // [esp+4h] [ebp-1Ch]
  int16_t v11; // [esp+8h] [ebp-18h]
  _WORD *v12; // [esp+10h] [ebp-10h]
  int16_t v13; // [esp+14h] [ebp-Ch]
  char v14; // [esp+18h] [ebp-8h]
  char v15; // [esp+1Ch] [ebp-4h]

  v13 = *a8;
  v12 = a8 + 8;
  while ( a2 < a4 )
  {
    for ( i = v11; i < v10; ++i )
    {
      v14 = 0;
      v15 = *((_BYTE *)v12 + v13 * a2 + i);
      for ( j = 0; j < a7 && !v14; ++j )
      {
        if ( v15 == *(_BYTE *)(j + a5) )
        {
          v14 = 1;
          *((_BYTE *)v12 + v13 * a2 + i) = *(_BYTE *)(j + a6);
        }
      }
    }
    ++a2;
  }
  JUMPOUT(0x8F4B4);
}
// 8FF03: control flows out of bounds to 8F4B4
// 8FEA2: variable 'v11' is possibly undefined
// 8FEFA: variable 'v10' is possibly undefined


//----- (0008FF08) --------------------------------------------------------
void __fastcall sub_8FF08( int a1, int a2, int a3, int a4, int a5, int a6, int16_t *a7)
{
  int16_t i; // cx
  _BYTE *v10; // eax
  int16_t v11; // [esp+Ch] [ebp-8h]

  v11 = *a7;
  if ( a5 )
  {
    a4 = a7[1];
    a1 = 0;
    a2 = 0;
    a3 = *a7;
  }
  while ( a2 < a4 )
  {
    for ( i = a1; i < a3; ++i )
    {
      v10 = (char *)a7 + v11 * a2 + i + 16;
      if ( *v10 )
        *v10 += a6;
    }
    ++a2;
  }
  JUMPOUT(0x8F542);
}
// 8FF79: control flows out of bounds to 8F542


//----- (0008FF7E) --------------------------------------------------------
void __fastcall sub_8FF7E( int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7, unsigned int a8,
        int16_t *a9)
{
  int16_t i; // cx
  int16_t j; // bx
  uint8_t *v13; // eax
  uint8_t v14; // dl
  int16_t v15; // [esp+Ch] [ebp-8h]

  v15 = *a9;
  if ( a5 )
  {
    a3 = *a9;
    a4 = a9[1];
    a1 = 0;
    a2 = 0;
  }
  for ( i = a2; i < a4; ++i )
  {
    for ( j = a1; j < a3; ++j )
    {
      v13 = (uint8_t *)a9 + j + i * v15 + 16;
      v14 = *v13;
      if ( *v13 >= a7 && v14 < a8 )
        *v13 = a6 + v14;
    }
  }
  JUMPOUT(0x8FD1B);
}
// 8FFF3: control flows out of bounds to 8FD1B


//----- (00090006) --------------------------------------------------------
char __fastcall sub_90006( int a1, int a2, int a3, int a4)
{
  if ( word_1845D8 == 1 )
  {
    if ( a1 < SHIWORD(dword_1BBA4A) )
      a1 = HIWORD(dword_1BBA4A);
    if ( a2 < SHIWORD(dword_1BBA4E) )
      a2 = HIWORD(dword_1BBA4E);
    if ( a3 > (int16_t)dword_1BBA4E )
      a3 = dword_1BBA4E;
    if ( a4 > (int16_t)dword_1BBA52 )
      a4 = dword_1BBA52;
  }
  return sub_12991D(a1, a2, a3, a4, 0);
}
// 1845D8: using guessed type int16_t word_1845D8;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00090089) --------------------------------------------------------
int __fastcall sub_90089( int a1, int a2, int a3, int a4)
{
  int16_t v5; // ax

  v5 = sub_12066F(a4);
  return sub_900CE((int16_t)(a1 - v5 / 2), a2, a3, a4);
}


//----- (000900CE) --------------------------------------------------------
int __fastcall sub_900CE(int a1, int a2, int a3, int a4)
{
  int16_t v4; // di
  int v5; // edx
  char *v6; // esi
  char v7; // al
  int v8; // eax
  int v9; // edx
  int v10; // esi
  int v11; // eax
  char v12; // bl
  int v13; // esi
  int v14; // eax
  char v15; // bl
  _BYTE v17[8]; // [esp+0h] [ebp-28h] BYREF
  _BYTE v18[8]; // [esp+8h] [ebp-20h] BYREF
  _BYTE *v19; // [esp+10h] [ebp-18h]
  _BYTE *v20; // [esp+14h] [ebp-14h]
  _BYTE *v21; // [esp+18h] [ebp-10h]
  int v22; // [esp+1Ch] [ebp-Ch]
  int v23; // [esp+20h] [ebp-8h]
  int v24; // [esp+24h] [ebp-4h]

  v4 = a1;
  v22 = a2;
  v23 = a1 + 1;
  v24 = a2 + 1;
  v5 = 0;
  v21 = v18;
  do
  {
    v6 = &v21[(int16_t)v5];
    v7 = byte_1B3E7C[(int16_t)v5++];
    *v6 = v7;
  }
  while ( (int16_t)v5 < 8 );
  v17[0] = v18[0];
  v8 = 1;
  do
  {
    v9 = (int16_t)v8++;
    v17[v9] = a3;
  }
  while ( (int16_t)v8 < 8 );
  v19 = v17;
  v10 = 0;
  do
  {
    v11 = (int16_t)v10;
    v12 = v17[(int16_t)v10];
    byte_1B3E88[(int16_t)v10++] = v12;
    byte_1B3E7C[v11] = v12;
  }
  while ( (int16_t)v10 < 8 );
  sub_1212B3(v23, v24, a4);
  v20 = v18;
  v13 = 0;
  do
  {
    v14 = (int16_t)v13;
    v15 = v18[(int16_t)v13];
    byte_1B3E88[(int16_t)v13++] = v15;
    byte_1B3E7C[v14] = v15;
  }
  while ( (int16_t)v13 < 8 );
  return sub_1212B3(v4, v22, a4);
}


//----- (00090184) --------------------------------------------------------
void __fastcall sub_90184( int a1, int a2, int a3, int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
  int16_t v7; // di
  int v8; // edx
  int16_t v9; // ax
  int16_t v10; // [esp+0h] [ebp-10h]
  int16_t v11; // [esp+4h] [ebp-Ch]
  int16_t v12; // [esp+8h] [ebp-8h]
  int16_t i; // [esp+Ch] [ebp-4h]

  v7 = a3;
  v11 = a4;
  if ( word_1845D8 == 1 )
  {
    if ( a1 < SHIWORD(dword_1BBA4A) )
      v10 = HIWORD(dword_1BBA4A);
    if ( a2 < SHIWORD(dword_1BBA4E) )
      a2 = HIWORD(dword_1BBA4E);
    if ( a3 > (int16_t)dword_1BBA4E )
      v7 = dword_1BBA4E;
    if ( a4 > (int16_t)dword_1BBA52 )
      v11 = dword_1BBA52;
  }
  v12 = 0;
  for ( i = a2; i < v11 + 1; ++i )
  {
    v8 = v12 % 3;
    if ( v8 )
    {
      if ( v8 == 1 )
        v9 = a6;
      else
        v9 = a7;
    }
    else
    {
      v9 = a5;
    }
    sub_134D2D(v10, i, v7, i, v9);
    ++v12;
  }
  JUMPOUT(0x8F542);
}
// 90236: control flows out of bounds to 8F542
// 9021A: variable 'v10' is possibly undefined
// 1845D8: using guessed type int16_t word_1845D8;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (0009023B) --------------------------------------------------------
int16_t __fastcall sub_9023B( int a1, int a2, int a3, int a4, int a5, int a6,
        int a7,
        int a8, int a9,
        _WORD *a10,
        int a11,
        _WORD *a12)
{
  int16_t i; // di
  int16_t v13; // ax
  int64_t v15; // [esp-Ch] [ebp-24h]
  int v17; // [esp+10h] [ebp-8h] BYREF
  int v18; // [esp+14h] [ebp-4h] BYREF

  sub_128AB6(a5 + a1, a6 + a2, a5 + a1 + a3, (int16_t)(a6 + a2 + a4));
  if ( word_199A08 == 1 )
    *a10 = -1000;
  for ( i = 0; i < word_19999A; ++i )
  {
    sub_911D5(i, a1, a2, a3, a4, a5, a6, a9, &v18, &v17);
    if ( a9 )
      v13 = sub_11438B(v18 - 3, v17 - 3, v18 + 8, v17 + 9, &unk_179A78, 41);
    else
      v13 = sub_11438B(v18, v17, v18 + 5, v17 + 5, &unk_179A78, 41);
    *(_WORD *)(a11 + 2 * i) = v13;
  }
  if ( word_199A08 == 1 )
  {
    HIDWORD(v15) = &word_19996A;
    LODWORD(v15) = &word_199968;
    *a12 = sub_114DCA(a5 + a1, a6 + a2, 1, 1, a3, a4, v15, 0);
  }
  return sub_128BE7();
}
// 199968: using guessed type int16_t word_199968;
// 19996A: using guessed type int16_t word_19996A;
// 19999A: using guessed type int16_t word_19999A;
// 199A08: using guessed type int16_t word_199A08;


//----- (00090371) --------------------------------------------------------
void __fastcall sub_90371( int a1, int a2, int a3, int a4, int a5, int a6,
        int a7,
        int a8, int a9,
        int a10)
{
  int16_t i; // di
  int16_t v11; // ax
  int v13; // [esp+10h] [ebp-8h] BYREF
  int v14; // [esp+14h] [ebp-4h] BYREF

  for ( i = 0; i < word_19999A; ++i )
  {
    sub_911D5(i, a1, a2, a3, a4, a5, a6, a9, &v13, &v14);
    if ( a9 )
      v11 = sub_11438B(v13 - 3, v14 - 3, v13 + 8, v14 + 9, &unk_179A78, 41);
    else
      v11 = sub_11438B(v13, v14, v13 + 5, v14 + 5, &unk_179A78, 41);
    *(_WORD *)(a10 + 2 * i) = v11;
  }
  JUMPOUT(0x9042A);
}
// 90424: control flows out of bounds to 9042A
// 19999A: using guessed type int16_t word_19999A;


//----- (00090430) --------------------------------------------------------
void sub_90430()
{
  int16_t i; // bx
  int16_t v1; // ax

  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  for ( i = 0; i < 5; ++i )
  {
    sub_9086B(word_1992E8[i]);
    if ( !word_1992E8[i] && word_192FDE[0] > word_1992C0[0] )
      sub_A4F58();
    if ( word_1992E8[i] == 2 && word_193016 > word_1992C4 )
    {
      sub_7836A(word_1999B8);
      if ( v1 == -1 )
        sub_91A40();
      else
        sub_6FF08();
    }
  }
  sub_128BE7();
  sub_12B65C();
}
// 904C4: variable 'v1' is possibly undefined
// 192FDE: using guessed type int16_t word_192FDE[];
// 193016: using guessed type int16_t word_193016;
// 1992C0: using guessed type int16_t word_1992C0[];
// 1992C4: using guessed type int16_t word_1992C4;
// 1992E8: using guessed type int16_t word_1992E8[5];
// 1999B8: using guessed type int16_t word_1999B8;


//----- (000904FD) --------------------------------------------------------
int16_t __fastcall sub_904FD( int a1)
{
  int16_t v1; // di
  int16_t v2; // si
  int16_t result; // ax

  v1 = word_193038;
  v2 = word_19303A;
  if ( a1 )
    word_193040 = (uint16_t)sub_1151B0(
                                      word_193048 + word_193038 + 245,
                                      word_19303A + word_19304A + 234,
                                      (int)&unk_179A78,
                                      (_WORD *)dword_1930BC,
                                      &unk_179A78,
                                      41);
  word_19303E = sub_11438B(v1 + 1, v2 + 1, v1 + word_193044, v2 + word_193046, &unk_179A78, 0);
  word_193042 = -1000;
  result = word_193016 > word_1992C4;
  if ( word_193016 > word_1992C4 )
    return sub_905B8(3);
  return result;
}
// 193016: using guessed type int16_t word_193016;
// 193038: using guessed type int16_t word_193038;
// 19303A: using guessed type int16_t word_19303A;
// 19303E: using guessed type int16_t word_19303E;
// 193040: using guessed type int16_t word_193040;
// 193042: using guessed type int16_t word_193042;
// 193044: using guessed type int16_t word_193044;
// 193046: using guessed type int16_t word_193046;
// 193048: using guessed type int16_t word_193048;
// 19304A: using guessed type int16_t word_19304A;
// 1930BC: using guessed type int dword_1930BC;
// 1992C4: using guessed type int16_t word_1992C4;


//----- (000905B8) --------------------------------------------------------
int __fastcall sub_905B8( int a1)
{
  int v1; // esi
  int16_t v2; // dx
  int result; // eax
  int16_t v4; // [esp+0h] [ebp-10h] BYREF
  int16_t v5; // [esp+4h] [ebp-Ch] BYREF
  int16_t v6; // [esp+8h] [ebp-8h] BYREF
  int16_t v7; // [esp+Ch] [ebp-4h] BYREF

  v1 = a1;
  sub_91776(a1, &v5, &v6, &v7, &v4);
  v2 = sub_11438B(v5, v6, v7, v4, &unk_179A78, 0);
  result = 28 * v1;
  word_192FEE[14 * v1] = v2;
  return result;
}
// 192FEE: using guessed type int16_t word_192FEE[];


//----- (00090605) --------------------------------------------------------
int __fastcall sub_90605( int a1, int a2)
{
  int v3; // eax
  int v4; // ebx

  v3 = 14 * a1;
  v4 = 0;
  if ( a2 == word_192FEA[v3]
    || a2 == word_192FEE[v3]
    || a1 == word_192FF8 && a2 == word_19997A
    || a1 == word_193014 && (a2 == word_199A00 || a2 == word_199982) )
  {
    return 1;
  }
  return v4;
}
// 192FEA: using guessed type int16_t word_192FEA[];
// 192FEE: using guessed type int16_t word_192FEE[];
// 192FF8: using guessed type int16_t word_192FF8;
// 193014: using guessed type int16_t word_193014;
// 19997A: using guessed type int16_t word_19997A;
// 199982: using guessed type int16_t word_199982;
// 199A00: using guessed type int16_t word_199A00;


//----- (00090658) --------------------------------------------------------
int sub_90658()
{
  return sub_1297C3(word_1906C8[6 * word_19990E] + 4, word_1906CA[6 * word_19990E] + 2, 11, 11, 1, 141);
}
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 19990E: using guessed type int16_t word_19990E;


//----- (0009068F) --------------------------------------------------------
int sub_9068F()
{
  return sub_1297C3(
           10 * (1000 * *(int16_t *)(113 * word_199960 + dword_19306C + 15) / word_1999A0) / 1659 + 10,
           10 * (1000 * *(int16_t *)(113 * word_199960 + dword_19306C + 17) / word_1999A0) / 2197 + 47,
           11,
           12,
           1,
           113);
}
// 19306C: using guessed type int dword_19306C;
// 199960: using guessed type int16_t word_199960;
// 1999A0: using guessed type int16_t word_1999A0;


//----- (0009070A) --------------------------------------------------------
int __fastcall sub_9070A( int a1, int a2, int a3, int a4)
{
  int16_t v5; // [esp-4h] [ebp-10h]

  if ( word_19C540 == word_19C53E )
    v5 = (uint8_t)byte_19C548 + 110;
  else
    v5 = 30;
  return sub_1297C3(
           a1 + 306 + 10 * (1000 * *(int16_t *)(113 * word_19C53E + dword_19306C + 15) / word_1999A0) / a3 - 5,
           a2 + 235 + 10 * (1000 * *(int16_t *)(113 * word_19C53E + dword_19306C + 17) / word_1999A0) / a4 - 5,
           11,
           12,
           1,
           v5);
}
// 19306C: using guessed type int dword_19306C;
// 1999A0: using guessed type int16_t word_1999A0;
// 19C53E: using guessed type int16_t word_19C53E;
// 19C540: using guessed type int16_t word_19C540;
// 19C548: using guessed type char byte_19C548;


//----- (000907CE) --------------------------------------------------------
void sub_907CE()
{
  JUMPOUT(0x906EA);
}
// 9082E: control flows out of bounds to 906EA
// 19306C: using guessed type int dword_19306C;
// 1999A0: using guessed type int16_t word_1999A0;


//----- (00090833) --------------------------------------------------------
int __fastcall sub_90833( int a1)
{
  int v2; // ebx
  int16_t v3; // cx
  int i; // eax

  v2 = 255;
  v3 = 0;
  for ( i = 0; (int16_t)i < 5 && !v3; ++i )
  {
    if ( a1 == word_1992E8[(int16_t)i] )
    {
      v3 = 1;
      v2 = i;
    }
  }
  return v2;
}
// 1992E8: using guessed type int16_t word_1992E8[5];


//----- (0009086B) --------------------------------------------------------
int16_t __fastcall sub_9086B( int a1)
{
  int v2; // eax
  int v3; // edx
  int v4; // edx
  int v5; // edx

  v2 = 28 * a1;
  *(int16_t *)((char *)&word_192FEC + v2) = -1000;
  *(int16_t *)((char *)word_192FEA + v2) = -1000;
  *(int16_t *)((char *)word_192FEE + v2) = -1000;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      word_19997A = -1000;
      LOWORD(v2) = 0;
      while ( (int16_t)v2 < word_19999A )
      {
        v4 = (int16_t)v2;
        LOWORD(v2) = v2 + 1;
        word_190178[v4] = -1000;
      }
    }
    else if ( a1 == 2 )
    {
      word_19994E = -1000;
      word_199950 = -1000;
      word_199A00 = -1000;
      word_193024 = -1000;
      word_193022 = -1000;
      LOWORD(v2) = word_193016 > word_1992C4;
      if ( word_193016 > word_1992C4 )
      {
        LOWORD(v2) = 0;
        while ( (int16_t)v2 < word_199BB8 )
        {
          v5 = 9 * (int16_t)v2;
          LOWORD(v2) = v2 + 1;
          *(int16_t *)((char *)&word_197FC1 + v5) = -1000;
        }
      }
    }
  }
  else
  {
    LOWORD(v2) = 0;
    do
    {
      v3 = (int16_t)v2;
      LOWORD(v2) = v2 + 1;
      word_1992D4[v3] = -1000;
    }
    while ( (int16_t)v2 < 5 );
  }
  return v2;
}
// 190178: using guessed type int16_t word_190178[72];
// 192FEA: using guessed type int16_t word_192FEA[];
// 192FEC: using guessed type int16_t word_192FEC;
// 192FEE: using guessed type int16_t word_192FEE[];
// 193016: using guessed type int16_t word_193016;
// 193022: using guessed type int16_t word_193022;
// 193024: using guessed type int16_t word_193024;
// 197FC1: using guessed type int16_t word_197FC1;
// 1992C4: using guessed type int16_t word_1992C4;
// 1992D4: using guessed type int16_t word_1992D4[10];
// 19994E: using guessed type int16_t word_19994E;
// 199950: using guessed type int16_t word_199950;
// 19997A: using guessed type int16_t word_19997A;
// 19999A: using guessed type int16_t word_19999A;
// 199A00: using guessed type int16_t word_199A00;
// 199BB8: using guessed type int16_t word_199BB8;


//----- (00090945) --------------------------------------------------------
void __fastcall sub_90945( int a1, int a2)
{
  int v4; // ebx
  int v5; // ecx
  _BOOL2 v6; // ax
  int v7; // [esp-20h] [ebp-24h]
  int v8; // [esp-8h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-8h]
  int v10; // [esp+0h] [ebp-4h]

  v4 = 0;
  do
  {
    v10 = (int16_t)v4;
    v5 = word_1992E8[(int16_t)v4];
    v9 = word_192FEE[14 * v5];
    v8 = word_192FEC[14 * v5];
    v6 = sub_918D5(word_1992E8[(int16_t)v4]);
    v7 = (int16_t)a2;
    ++v4;
    ++a2;
    _wcpp_1_unwind_leave(
      a1,
      v7,
      "(%d) Order: %d  Flag: %d  Sel: %d  Canc: %d  Whole: %d",
      v10,
      v5,
      word_192FDE[14 * v5],
      v6,
      v8,
      v9);
  }
  while ( (int16_t)v4 < 5 );
  JUMPOUT(0x909A9);
}
// 909A7: control flows out of bounds to 909A9
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FEC: using guessed type int16_t word_192FEC[];
// 192FEE: using guessed type int16_t word_192FEE[];
// 1992E8: using guessed type int16_t word_1992E8[5];


//----- (000909AF) --------------------------------------------------------
int sub_909AF()
{
  int result; // eax

  if ( word_199960 > -1 )
    sub_9068F();
  result = word_19990E;
  if ( word_19990E > -1 )
  {
    result = sub_78ABA(word_19990E);
    if ( (int16_t)result > -1 && (_WORD)result != word_1999D8 )
      return sub_90658();
  }
  return result;
}
// 19990E: using guessed type int16_t word_19990E;
// 199960: using guessed type int16_t word_199960;
// 1999D8: using guessed type int16_t word_1999D8;


//----- (000909FA) --------------------------------------------------------
int __fastcall sub_909FA( int a1, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // eax
  int16_t v6; // ax
  int16_t v7; // bx
  int16_t v8; // dx
  int v9; // eax
  int16_t v10; // si
  int v11; // eax
  uint16_t v12; // ax
  char *v13; // eax
  char *v14; // esi
  int v15; // [esp-Ch] [ebp-58h]
  int v16; // [esp-8h] [ebp-54h]
  int v17; // [esp-4h] [ebp-50h]
  char v21[40]; // [esp+10h] [ebp-3Ch] BYREF
  char v22[8]; // [esp+38h] [ebp-14h] BYREF
  int v23; // [esp+40h] [ebp-Ch]
  int v24; // [esp+44h] [ebp-8h]
  _BOOL1 v25; // [esp+48h] [ebp-4h]

  v25 = sub_941BB();
  result = word_199960;
  if ( word_199960 > -1 )
  {
    v5 = dword_19306C + 113 * word_199960;
    v24 = 466;
    v23 = 418;
    if ( *(char *)(v5 + 20) <= -1 || *(char *)(v5 + 20) >= 8 )
    {
      v7 = 38;
      v8 = 33;
    }
    else
    {
      v6 = (uint8_t)byte_10010[*(uint8_t *)(dword_197F98 + 3753 * *(char *)(v5 + 20) + 38)];
      if ( v6 == 32 )
      {
        v7 = 22;
        v8 = 8;
      }
      else
      {
        v7 = v6 + 5;
        v8 = v6 + 1;
      }
    }
    sub_8F6F8(3u, v8, v7, v22);
    sub_907CE();
    sub_120BB5(3, (int)v22);
    if ( sub_79E32(word_19999C, word_199960) || sub_79E06(word_19999C) || sub_78F4B(word_199960) )
    {
      v9 = dword_19306C + 113 * word_199960;
      v10 = *(char *)(word_19999C + v9 + 66);
      if ( *(char *)(word_19999C + v9 + 66) != -1 && sub_79D1C(word_19999C, word_199960) )
      {
        v11 = dword_1930DC + 59 * v10;
        if ( *(char *)(v11 + 55) <= 0 )
        {
          sprintf(
            v21,
            "%s (%s)",
            (char *)(dword_19306C + 113 * word_199960),
            (char *)(dword_1930DC + 59 * v10));
        }
        else
        {
          v17 = *(char *)(v11 + 55);
          v16 = dword_1930DC + 59 * v10;
          v15 = dword_19306C + 113 * word_199960;
          if ( *(_BYTE *)(v11 + 55) == 1 )
            v12 = 146;
          else
            v12 = 147;
          v13 = sub_7A990(v12);
          sprintf(v21, v13, v15, v16, v17);
        }
        goto LABEL_22;
      }
      v14 = (char *)(113 * word_199960 + dword_19306C);
    }
    else
    {
      v14 = sub_7A990(0x94u);
    }
    strcpy(v21, v14);
LABEL_22:
    sub_8FDA1((int)v21, (int)v22, 3, 2, 0, 203, 1);
    result = sub_1210FD(v24, v23, (int)v21);
  }
  if ( !v25 )
  {
    result = word_19C53E;
    if ( word_19C53E > -1 )
      return sub_9070A(a1, a2, a3, a4);
  }
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199960: using guessed type int16_t word_199960;
// 19999C: using guessed type int16_t word_19999C;
// 19C53E: using guessed type int16_t word_19C53E;


//----- (00090C4F) --------------------------------------------------------
void __userpurge sub_90C4F(
        int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8,
        int a9, int a10, int a11)
{
  int i; // eax
  char v13; // dl
  int16_t v14; // bx
  int16_t v15; // di
  int16_t v16; // ax
  int j; // eax
  int16_t v18; // dx
  char *v19; // eax
  int16_t k; // cx
  int v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // edx
  int v25; // eax
  int v26; // ebx
  int16_t v27; // dx
  int16_t v28; // ax
  int16_t v29; // ax
  int v30; // [esp+0h] [ebp-44h]
  _BYTE v31[8]; // [esp+4h] [ebp-40h] BYREF
  int v32; // [esp+Ch] [ebp-38h]
  int v33; // [esp+10h] [ebp-34h]
  int v34; // [esp+14h] [ebp-30h]
  int v35; // [esp+18h] [ebp-2Ch]
  int v36; // [esp+1Ch] [ebp-28h]
  int v37; // [esp+20h] [ebp-24h]
  int v38; // [esp+24h] [ebp-20h]
  int v39; // [esp+28h] [ebp-1Ch]
  int v40; // [esp+2Ch] [ebp-18h]
  int v41; // [esp+30h] [ebp-14h]
  int v42; // [esp+34h] [ebp-10h]
  int v43; // [esp+38h] [ebp-Ch]
  int v44; // [esp+3Ch] [ebp-8h]
  int v45; // [esp+40h] [ebp-4h]

  v45 = a1;
  v41 = 1000;
  for ( i = 2; i < 8; v31[i - 1] = v13 + 100 )
    v13 = i++;
  v45 += a9;
  v14 = a4;
  v36 = 506 * v41 / a4;
  v15 = a8 + a2;
  v34 = 400 * v41 / a5;
  if ( a11 == 1 )
    goto LABEL_61;
  if ( a11 > -1 )
  {
    if ( byte_182ACE )
    {
      v16 = a5;
    }
    else
    {
      v14 = word_192FFE;
      v16 = word_192FFC;
    }
    if ( a10 != 4 )
    {
      if ( v30 && !byte_182ACE )
      {
        for ( j = 0; j < 8; ++j )
        {
          if ( j )
            v31[j] = j + 100;
          else
            v31[0] = 98;
        }
        if ( !word_199A08 )
        {
          sub_120E8C(2);
          sub_120CCB(3, (int)v31);
          sub_120DED(98, 101);
          v18 = v45;
          v19 = sub_7A990(0xF3u);
          sub_1210FD(v15 + 87, v18 + 13, (int)v19);
          sub_8FE2E();
        }
      }
      else
      {
        v38 = (int16_t)(v45 + v16);
        v39 = (int16_t)(v15 + v14);
        v42 = (int16_t)v45;
        v40 = v15;
        sub_128AB6(v15, v45, v15 + v14, v38);
        sub_12B634();
        if ( word_199A08 != 6 && !byte_182ACE )
          sub_128C32(v40, v42, v39, v38, 0);
        sub_12B65C();
        sub_128BE7();
      }
    }
  }
  v35 = (int16_t)(a7 + v45 + a5);
  sub_128AB6(v15 + a6, a7 + v45, v15 + a6 + a4, v35);
  sub_12B634();
  for ( k = 0; ; ++k )
  {
    if ( k >= word_19999A )
    {
      sub_12B65C();
      sub_128BE7();
      if ( (uint16_t)word_199A08 >= 4u )
      {
        if ( (uint16_t)word_199A08 <= 4u )
        {
          if ( word_199960 > -1 )
            sub_909AF();
        }
        else if ( word_199A08 == 29 )
        {
          sub_909FA(a6, a7, v36, v34);
        }
      }
LABEL_61:
      JUMPOUT(0x9036B);
    }
    v21 = 113 * k + dword_19306C;
    v22 = v41 * *(int16_t *)(v21 + 15);
    v35 = word_1999A0;
    v33 = v22 / word_1999A0;
    v32 = v41 * *(int16_t *)(v21 + 17) / word_1999A0;
    v37 = 10 * v33 / v36 + v15 + a6;
    v35 = a7 + (int16_t)v45;
    v23 = 10 * v32 / v34;
    v24 = v23 + v35;
    LOWORD(v23) = *(char *)(v21 + 20);
    v43 = v24;
    v44 = v23;
    if ( *(_BYTE *)(v21 + 22) == 6 && byte_182ACE )
    {
      a3 = 9;
      goto LABEL_35;
    }
    v25 = dword_19306C + 113 * k;
    if ( *(_BYTE *)(v25 + 22) == 6 )
    {
      a3 = 10;
      goto LABEL_35;
    }
    if ( *(_BYTE *)(v25 + 22) == 5 )
      goto LABEL_34;
    if ( (int16_t)v44 > -1 && (int16_t)v44 < 8 )
    {
      a3 = *(uint8_t *)(dword_197F98 + 3753 * *(char *)(v25 + 20) + 38);
      goto LABEL_35;
    }
    if ( sub_79E32(word_19999C, k) || (unsigned int)(int16_t)v44 >= 0xFFFFFFFE )
LABEL_34:
      a3 = 8;
LABEL_35:
    if ( a10 )
    {
      switch ( a10 )
      {
        case 1:
        case 4:
          sub_12B726(dword_1932E0[a3]);
          v27 = v43 - 2;
          v28 = v37 - 2;
          v26 = dword_1932E0[a3];
          break;
        case 2:
          if ( word_1999BC < 1000 )
            v29 = word_1999BC;
          else
            v29 = word_1999BC - 1000;
          if ( k == v29 )
          {
            sub_12B753(dword_197588[a3], (uint8_t)byte_199F29);
            byte_199F29 = ((uint8_t)byte_199F29 + 1) % *(int16_t *)(dword_197588[a3] + 6);
          }
          else
          {
            sub_12B726(dword_197588[a3]);
          }
          v26 = dword_197588[a3];
          v27 = v43 - 2;
          v28 = v37 - 2;
          break;
        case 3:
          if ( k != word_199960 )
            sub_12B726(dword_190688[a3]);
          v26 = dword_190688[a3];
          v27 = v43 - 1;
          v28 = v37 - 1;
          break;
        default:
          continue;
      }
    }
    else
    {
      v26 = dword_197490[a3];
      v27 = v43 - 1;
      v28 = v37 - 1;
    }
    sub_12A478(v28, v27, v26);
  }
}
// 9106A: control flows out of bounds to 9036B
// 182ACE: using guessed type char byte_182ACE;
// 190688: using guessed type int dword_190688[10];
// 192FFC: using guessed type int16_t word_192FFC;
// 192FFE: using guessed type int16_t word_192FFE;
// 19306C: using guessed type int dword_19306C;
// 1932E0: using guessed type int dword_1932E0[11];
// 197490: using guessed type int dword_197490[62];
// 197588: using guessed type int dword_197588[11];
// 197F98: using guessed type int dword_197F98;
// 199960: using guessed type int16_t word_199960;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1999A0: using guessed type int16_t word_1999A0;
// 1999BC: using guessed type int16_t word_1999BC;
// 199A08: using guessed type int16_t word_199A08;
// 199F29: using guessed type char byte_199F29;


//----- (00091099) --------------------------------------------------------
void __fastcall sub_91099( int a1)
{
  int v1; // ebx
  int v2; // eax
  int16_t v3; // dx

  v1 = a1;
  v2 = 14 * a1;
  if ( word_192FDE[v2] > word_1992C0[v1] )
  {
    if ( byte_19D32F )
    {
      byte_19D32F = 0;
    }
    else
    {
      v3 = word_192FDC[v2];
      if ( v3 )
      {
        if ( (uint16_t)v3 <= 1u )
        {
          sub_90C4F(
            word_192FE6[v2],
            word_192FE4[v2],
            word_192FE4[v2],
            word_19995A,
            word_199970,
            8,
            38,
            word_192FF4[v2],
            word_192FF6[v2],
            0,
            0);
        }
        else if ( v3 == 2 )
        {
          sub_70875();
        }
      }
      else
      {
        sub_A4FBE(v2 * 2, 0, v1);
      }
    }
  }
}
// 192FDC: using guessed type int16_t word_192FDC[];
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 192FF4: using guessed type int16_t word_192FF4[];
// 192FF6: using guessed type int16_t word_192FF6[];
// 1992C0: using guessed type int16_t word_1992C0[];
// 19995A: using guessed type int16_t word_19995A;
// 199970: using guessed type int16_t word_199970;
// 19D32F: using guessed type char byte_19D32F;


//----- (00091151) --------------------------------------------------------
_WORD *__fastcall sub_91151( int a1, int a2, int a3, int a4, int a5, _WORD *a6, _WORD *a7)
{
  int v7; // eax
  int16_t v8; // si
  _WORD *result; // eax
  int v10; // [esp+4h] [ebp-8h]

  v7 = 6 * a1;
  v10 = word_1906CA[v7] - 21;
  v8 = (1000 * a4 / 506 + 1) * (word_1906C8[v7] - 21) / 1000 + a2;
  result = a7;
  *a6 = v8;
  *a7 = (1000 * a5 / 400 + 1) * v10 / 1000 + a3;
  return result;
}
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];


//----- (000911D5) --------------------------------------------------------
int __fastcall sub_911D5( int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8,
        _WORD *a9,
        _WORD *a10)
{
  int v10; // ebx
  int v11; // esi
  int v12; // ecx
  int v13; // ebx
  int v14; // ebx
  int result; // eax
  int v16; // [esp+0h] [ebp-Ch]

  v16 = 506000 / a4 + 1;
  v10 = 113 * a1 + dword_19306C;
  v11 = 1000 * *(int16_t *)(v10 + 15) / word_1999A0;
  v12 = 1000 * *(int16_t *)(v10 + 17) / word_1999A0;
  if ( a8 )
    v13 = 6;
  else
    v13 = 4;
  v14 = v13 / 2;
  *a9 = 10 * v11 / v16 + a2 + a6 - v14;
  result = a7 + a3 + 10 * v12 / ((int)&loc_61A80 / a5 + 1) - v14;
  *a10 = result;
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1999A0: using guessed type int16_t word_1999A0;


//----- (0009128C) --------------------------------------------------------
void __fastcall sub_9128C( int a1)
{
  int16_t v2; // bx
  int16_t i; // ax
  int v4; // edx
  int16_t v5; // ax
  int16_t v6; // bx
  int16_t v7; // cx
  int16_t j; // dx
  int16_t v9; // si
  int v10; // edx
  int v11; // eax
  int16_t v12; // bx
  _WORD v13[6]; // [esp+0h] [ebp-Ch] BYREF

  memset(v13, 0, 10);
  v2 = -1;
  for ( i = 0; ; ++i )
  {
    if ( i >= 5 )
      goto LABEL_6;
    if ( a1 == word_1992E8[i] )
      break;
  }
  v2 = i;
LABEL_6:
  v4 = v2;
  v5 = word_1992E8[v2];
  v6 = 1;
  v13[0] = v5;
  word_1992E8[v4] = -1;
  while ( 1 )
  {
    v7 = 0;
    for ( j = 0; j < 5 && !v7; ++j )
    {
      if ( word_1992E8[j] != -1 )
      {
        v9 = word_1992E8[j];
        word_1992E8[j] = -1;
        v13[v6] = v9;
        v7 = 1;
      }
    }
    if ( ++v6 >= 5 )
    {
      v10 = 0;
      do
      {
        v11 = (int16_t)v10;
        v12 = v13[(int16_t)v10++];
        word_1992E8[v11] = v12;
      }
      while ( (int16_t)v10 < 5 );
      JUMPOUT(0x905FF);
    }
  }
}
// 91344: control flows out of bounds to 905FF
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1992E8: using guessed type int16_t word_1992E8[5];


//----- (00091349) --------------------------------------------------------
int16_t __usercall sub_91349( int a1, int a2, int a3)
{
  int16_t v4; // cx
  int16_t v5; // si
  int16_t v6; // ax
  int v7; // edx
  int v8; // eax
  int16_t v9; // ax
  int v10; // edx
  int16_t v11; // ax
  int v12; // edx
  int16_t v14; // [esp+Ch] [ebp-8h]
  int16_t v15; // [esp+Ch] [ebp-8h]
  int16_t v16; // [esp+10h] [ebp-4h]

  if ( a1 == 2 )
  {
    a3 = 28;
    byte_199BC7 = byte_199F32 == 2;
  }
  else if ( !a1 )
  {
    a3 = 43;
  }
  if ( a1 == 2 )
  {
    v4 = word_199BB2;
    v5 = word_199BB0;
    if ( byte_199BCA )
      byte_199BCA = 2;
  }
  else if ( word_192FDE[14 * a1] <= word_1992C0[a1] )
  {
    v4 = word_192FF0[14 * a1];
    v5 = word_192FF2[14 * a1];
  }
  else
  {
    v4 = word_192FE2[14 * a1];
    v5 = word_192FE0[14 * a1];
  }
  if ( a2 && (sub_113F8C() == word_192FEA[14 * a1] || word_192FE8[14 * a1] == 1) )
  {
    sub_1196F7();
    byte_199F32 = a2;
    sub_1194F6();
    sub_1172D4();
    word_199976 = 1;
    if ( word_199964 == -1 )
    {
      word_199956 = 1;
      word_199964 = a1;
    }
    sub_1172D4();
    v6 = sub_123ABA();
    word_192FF4[14 * a1] = v6 - sub_113F32();
    v14 = sub_123AE7();
    word_192FF6[14 * a1] = v14 - sub_113F5F();
    if ( word_192FF4[14 * a1] + word_192FE4[14 * a1] < 22 )
      word_192FF4[14 * a1] = 22 - word_192FE4[14 * a1];
    if ( word_192FF4[14 * a1] + word_192FE4[14 * a1] > 526 - v4 )
      word_192FF4[14 * a1] = 527 - v4 - word_192FE4[14 * a1];
    if ( word_192FE6[14 * a1] + word_192FF6[14 * a1] < 22 )
      word_192FF6[14 * a1] = 22 - word_192FE6[14 * a1];
    if ( a2 != 2 || a1 )
    {
      v7 = 14 * a1;
      LOWORD(v8) = v5;
      if ( word_192FE6[v7] + word_192FF6[v7] > 420 - v5 )
      {
        LOWORD(v8) = 421 - v5 - word_192FE6[14 * a1];
        goto LABEL_28;
      }
    }
    else
    {
      v7 = 0;
      v8 = word_192FE6[0] + word_192FF6[0] + a3;
      if ( v8 > 420 )
      {
        LOWORD(v8) = 421 - word_192FE6[0] - a3;
LABEL_28:
        word_192FF6[v7] = v8;
      }
    }
    word_192FE8[14 * a1] = 1;
    return v8;
  }
  byte_199F28 = 1;
  sub_1172FC();
  sub_6F280();
  sub_11C2F0();
  sub_9086B(a1);
  word_199976 = 1;
  if ( word_192FE8[14 * a1] == 1 )
  {
    v16 = sub_123ABA();
    word_192FE4[14 * a1] += v16 - sub_113F32();
    v15 = sub_123AE7();
    v9 = sub_113F5F();
    word_199964 = -2;
    word_192FE6[14 * a1] += v15 - v9;
  }
  if ( word_192FE4[14 * a1] < 22 )
    word_192FE4[14 * a1] = 22;
  if ( word_192FE4[14 * a1] > 526 - v4 )
    word_192FE4[14 * a1] = 527 - v4;
  if ( word_192FE6[14 * a1] < 22 )
    word_192FE6[14 * a1] = 22;
  if ( byte_199F32 != 2 || a1 )
  {
    v10 = 14 * a1;
    if ( word_192FE6[v10] > 420 - v5 )
    {
      v11 = 421 - v5;
      goto LABEL_44;
    }
  }
  else
  {
    v10 = 0;
    if ( word_192FE6[0] > 420 - a3 )
    {
      v11 = 421 - a3;
LABEL_44:
      word_192FE6[v10] = v11;
    }
  }
  v12 = 14 * a1;
  word_192FF4[v12] = 0;
  word_192FF6[v12] = 0;
  word_192FE8[v12] = 0;
  sub_9128C(a1);
  if ( a1 == 2 )
  {
    word_199BAC = word_19301C;
    word_199BAE = word_19301E;
  }
  byte_199F28 = 1;
  LOWORD(v8) = sub_6F280();
  return v8;
}
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 192FE8: using guessed type int16_t word_192FE8[];
// 192FEA: using guessed type int16_t word_192FEA[];
// 192FF0: using guessed type int16_t word_192FF0[];
// 192FF2: using guessed type int16_t word_192FF2[];
// 192FF4: using guessed type int16_t word_192FF4[];
// 192FF6: using guessed type int16_t word_192FF6[];
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;
// 1992C0: using guessed type int16_t word_1992C0[];
// 199956: using guessed type int16_t word_199956;
// 199964: using guessed type int16_t word_199964;
// 199976: using guessed type int16_t word_199976;
// 199BAC: using guessed type int16_t word_199BAC;
// 199BAE: using guessed type int16_t word_199BAE;
// 199BB0: using guessed type int16_t word_199BB0;
// 199BB2: using guessed type int16_t word_199BB2;
// 199BC7: using guessed type char byte_199BC7;
// 199BCA: using guessed type char byte_199BCA;
// 199F28: using guessed type char byte_199F28;
// 199F32: using guessed type char byte_199F32;


//----- (00091776) --------------------------------------------------------
int16_t __fastcall sub_91776( int a1, _WORD *a2, _WORD *a3, _WORD *a4, _WORD *a5)
{
  int v6; // eax
  int16_t result; // ax
  int16_t v8; // dx

  v6 = 14 * a1;
  *a2 = word_192FE4[v6];
  *a3 = word_192FE6[v6];
  if ( a1 == 2 )
  {
    *a4 = word_199BB2 + *a2;
    result = word_199BBA + *a3;
    *a5 = result;
  }
  else
  {
    *a4 = word_192FE2[v6] + *a2;
    v8 = word_192FE0[v6] + *a3;
    result = (int16_t)a5;
    *a5 = v8;
  }
  return result;
}
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 199BB2: using guessed type int16_t word_199BB2;
// 199BBA: using guessed type int16_t word_199BBA;


//----- (000917DD) --------------------------------------------------------
int __fastcall sub_917DD( int a1, int a2)
{
  int16_t v2; // di
  int v3; // esi
  int16_t v4; // bx
  int v6; // [esp+0h] [ebp-20h] BYREF
  int v7; // [esp+4h] [ebp-1Ch] BYREF
  int v8; // [esp+8h] [ebp-18h] BYREF
  int v9; // [esp+Ch] [ebp-14h] BYREF
  int v10; // [esp+10h] [ebp-10h] BYREF
  int v11; // [esp+14h] [ebp-Ch] BYREF
  int v12; // [esp+18h] [ebp-8h] BYREF
  int v13; // [esp+1Ch] [ebp-4h] BYREF

  v2 = a2 - 1;
  v3 = 0;
  sub_91776(a1, &v12, &v11, &v10, &v9);
  while ( v2 > -1 )
  {
    v4 = word_1992E8[v2];
    if ( word_192FDE[14 * v4] > word_1992C0[v4] )
    {
      if ( (sub_91776(v4, &v8, &v7, &v13, &v6), (int16_t)v12 >= (int16_t)v8) && (int16_t)v12 <= (int16_t)v13
        || (int16_t)v10 >= (int16_t)v8 && (int16_t)v10 <= (int16_t)v13
        || (int16_t)v8 >= (int16_t)v12 && (int16_t)v8 <= (int16_t)v10
        || (int16_t)v13 >= (int16_t)v12 && (int16_t)v13 <= (int16_t)v10 )
      {
        if ( (int16_t)v11 >= (int16_t)v7 && (int16_t)v11 <= (int16_t)v6
          || (int16_t)v9 >= (int16_t)v7 && (int16_t)v9 <= (int16_t)v6
          || (int16_t)v7 >= (int16_t)v11 && (int16_t)v7 <= (int16_t)v9
          || (int16_t)v6 >= (int16_t)v11 && (int16_t)v6 <= (int16_t)v9 )
        {
          v3 = 1;
        }
      }
    }
    --v2;
  }
  return v3;
}
// 192FDE: using guessed type int16_t word_192FDE[];
// 1992C0: using guessed type int16_t word_1992C0[];
// 1992E8: using guessed type int16_t word_1992E8[5];


//----- (000918D5) --------------------------------------------------------
_BOOL2 __fastcall sub_918D5( int a1)
{
  return word_192FDE[14 * a1] > word_1992C0[a1];
}
// 192FDE: using guessed type int16_t word_192FDE[];
// 1992C0: using guessed type int16_t word_1992C0[];


//----- (000918F4) --------------------------------------------------------
int __fastcall sub_918F4( int a1)
{
  int v2; // ebx
  int16_t i; // dx

  v2 = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( i != a1 && sub_918D5(i) )
      ++v2;
  }
  return v2;
}


//----- (0009191D) --------------------------------------------------------
int sub_9191D()
{
  int16_t i; // dx
  int result; // eax

  for ( i = 0; i < 5; ++i )
  {
    result = 3 * i;
    if ( *(int16_t *)((char *)&word_199BCD + result) != -1000 )
    {
      word_192FDE[14 * i] = *(int16_t *)((char *)&word_199BCD + 3 * i);
      if ( byte_199BCF[3 * i] )
      {
        if ( i )
        {
          if ( i == 2 && !sub_780D3() )
            sub_91A40();
        }
        else
        {
          sub_A3FE6(word_192FDE[0]);
        }
      }
      result = 3 * i;
      byte_199BCF[result] = 0;
      *(int16_t *)((char *)&word_199BCD + result) = -1000;
    }
  }
  return result;
}
// 192FDE: using guessed type int16_t word_192FDE[];
// 199BCD: using guessed type int16_t word_199BCD;


//----- (00091999) --------------------------------------------------------
int __fastcall sub_91999( int a1)
{
  int v1; // eax

  v1 = 3 * a1;
  LOBYTE(v1) = byte_199BCF[v1];
  return nullsub_5(v1);
}
// 919A3: using guessed type int __fastcall nullsub_5(_DWORD);


//----- (000919A4) --------------------------------------------------------
void sub_919A4()
{
  int16_t v0; // dx
  int v1; // eax
  _BOOL2 v2; // si
  int v3; // ebx
  int v4; // eax
  int v5; // ebx

  v0 = 0;
  while ( 1 )
  {
    v1 = 14 * v0;
    v2 = word_192FDE[v1] > word_1992C0[v0];
    v3 = 3 * v0;
    *(int16_t *)((char *)&word_199BCD + v3) = word_192FDE[v1];
    byte_199BCF[v3] = v2;
    if ( v0 || !v2 )
    {
      if ( v0 == 2 && v2 )
        sub_91A40();
    }
    else
    {
      sub_91ABC();
    }
    v4 = 14 * v0;
    v5 = word_192FDC[v4];
    word_199ECB = -1;
    ++v0;
    word_192FDE[v4] = word_1992C0[v5];
    if ( v0 >= 5 )
      JUMPOUT(0x905FF);
  }
}
// 91A3B: control flows out of bounds to 905FF
// 192FDC: using guessed type int16_t word_192FDC[];
// 192FDE: using guessed type int16_t word_192FDE[];
// 1992C0: using guessed type int16_t word_1992C0[];
// 199BCD: using guessed type int16_t word_199BCD;
// 199ECB: using guessed type int16_t word_199ECB;


//----- (00091A40) --------------------------------------------------------
int sub_91A40()
{
  int16_t i; // ax
  int v1; // edx
  int result; // eax

  word_193016 = word_1992C4;
  for ( i = 0; i < word_199BB8; ++i )
  {
    v1 = 9 * i;
    *(int16_t *)((char *)&word_197FC1 + v1) = -1000;
  }
  word_199982 = -1000;
  word_1999CE = -1000;
  word_193022 = -1000;
  word_193024 = -1000;
  word_199EC7 = -1;
  word_19995C = -1;
  word_1999CA = -1;
  sub_702E5();
  result = sub_6F280();
  byte_199F38 = 0;
  return result;
}
// 193016: using guessed type int16_t word_193016;
// 193022: using guessed type int16_t word_193022;
// 193024: using guessed type int16_t word_193024;
// 197FC1: using guessed type int16_t word_197FC1;
// 1992C4: using guessed type int16_t word_1992C4;
// 19995C: using guessed type int16_t word_19995C;
// 199982: using guessed type int16_t word_199982;
// 1999CA: using guessed type int16_t word_1999CA;
// 1999CE: using guessed type int16_t word_1999CE;
// 199BB8: using guessed type int16_t word_199BB8;
// 199EC7: using guessed type int16_t word_199EC7;
// 199F38: using guessed type char byte_199F38;


//----- (00091ABC) --------------------------------------------------------
int sub_91ABC()
{
  int v0; // eax
  int v1; // edx
  int result; // eax
  int v3; // edx

  word_192FDE[0] = word_1992C0[0];
  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    word_1992D4[v1] = -1000;
  }
  while ( (int16_t)v0 < 5 );
  result = 0;
  do
  {
    v3 = 6 * (int16_t)result++;
    word_1931C0[v3] = -1000;
  }
  while ( (int16_t)result < 8 );
  word_192FEA[0] = -1000;
  word_192FEC[0] = -1000;
  return result;
}
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FEA: using guessed type int16_t word_192FEA[];
// 192FEC: using guessed type int16_t word_192FEC;
// 1931C0: using guessed type int16_t word_1931C0[];
// 1992C0: using guessed type int16_t word_1992C0[];
// 1992D4: using guessed type int16_t word_1992D4[10];


//----- (00091B0B) --------------------------------------------------------
char sub_91B0B()
{
  int16_t v0; // si
  int16_t v1; // bx
  char v2; // dl
  int16_t v4; // [esp+8h] [ebp-8h]

  v0 = sub_123ABA();
  v1 = sub_123AE7();
  v2 = 0;
  if ( word_193018 + word_19301E <= 421 )
    v4 = word_193018 + word_19301E;
  else
    v4 = 421;
  if ( v0 >= word_19301C && v0 <= (int16_t)(word_19301C + word_19301A) && v1 >= word_19301E && v1 <= v4 )
    return 1;
  return v2;
}
// 193018: using guessed type int16_t word_193018;
// 19301A: using guessed type int16_t word_19301A;
// 19301C: using guessed type int16_t word_19301C;
// 19301E: using guessed type int16_t word_19301E;


//----- (00091B89) --------------------------------------------------------
void __usercall sub_91B89(int64_t a1, int a2, int16_t *a3)
{
  _DWORD *v3; // eax

  if ( word_19994C )
  {
    v3 = sub_1113CC(dword_192ED4, SHIDWORD(a1));
    a1 = sub_91BD4(v3);
    word_19994C = 0;
  }
  sub_FE8BE(a1, SHIDWORD(a1), a2, a3);
}
// 91BD4: using guessed type int64_t __fastcall sub_91BD4(_DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;


//----- (00091BB4) --------------------------------------------------------
char __fastcall sub_91BB4(char *a1, int a2, int a3, char *a4, int a5, int a6)
{
  return sub_91F14(a1, a2, a3, a4, a5, a6, 1);
}


//----- (00091BD4) --------------------------------------------------------
int __usercall sub_91BD4(int a1, int16_t *a2)
{
  _DWORD *v2; // eax
  int v3; // ebx
  void *v4; // eax
  int v5; // edx
  int16_t v6; // dx
  int16_t v7; // bx
  uint16_t v8; // ax
  int16_t v9; // dx
  int v10; // kr00_4
  int v11; // edx
  int v12; // ebx
  int v13; // edx
  void *v14; // eax
  uint16_t v15; // ax
  uint16_t v16; // ax
  int16_t v18; // [esp+0h] [ebp-Ch]
  int16_t v19; // [esp+4h] [ebp-8h]
  int16_t v20; // [esp+8h] [ebp-4h]

  sub_11C2F0();
  sub_1112EC(dword_192ED4, a1);
  v2 = sub_126B42((int)aInboxLbx, 0, dword_192ED4);
  HIWORD(v5) = 0;
  v3 = dword_192ED4;
  dword_19C334 = (int)v2;
  dword_19C330 = (int)sub_126B42((int)aInboxLbx, 1, dword_192ED4);
  sub_124D41();
  sub_119300();
  v4 = sub_124DEC();
  sub_1077D((int)v4, 1, v3, a2);
  sub_124C08();
  sub_124D41();
  LOWORD(v5) = *(_WORD *)dword_19C334;
  v19 = *(_WORD *)dword_19C334;
  if ( byte_19C386 )
  {
    sub_133C9C(dword_19C334, v5);
    sub_133C9C(dword_19C330, v5);
    sub_12B7E1(word_19C391, word_19C393, (_WORD *)dword_19C334);
    sub_12B726(dword_19C330);
    sub_12B7E1(word_19C389, word_19C38B, (_WORD *)dword_19C330);
  }
  else
  {
    sub_12A478(word_19C391, word_19C393, dword_19C334);
    qmemcpy(&byte_19C340, &unk_19C338, 8u);
  }
  sub_8FDA1((int)&unk_19C348, (int)&unk_19C338, 4, 2, 0, v19 - 54, 1);
  v6 = sub_8F64C();
  v18 = v6;
  v20 = sub_8F645();
  if ( word_199A08 == 13 )
  {
    byte_199F34 = 20;
    v7 = 26;
    v8 = v6;
    v9 = 10;
  }
  else
  {
    byte_199F34 = 19;
    v7 = 24;
    v8 = v6;
    v9 = 12;
  }
  qmemcpy(&byte_19C340, sub_8E5C5(v8, v9, v7), 8u);
  if ( byte_19C386 )
    sub_120940(4, (int)&byte_19C340);
  else
    sub_120BB5(v18, (int)&byte_19C340);
  sub_120E8C(v20);
  v10 = v19 - (int16_t)sub_12066F((int)&unk_19C348);
  v11 = word_19C384;
  v12 = word_19C391 + v10 / 2;
  v13 = (int16_t)(word_19C387 + (v11 - sub_122259()) / 2);
  sub_1212B3(v12, v13, (int)&unk_19C348);
  v14 = sub_124DEC();
  sub_1077D((int)v14, v13, (int)&unk_19C348, (int16_t *)&byte_19C340);
  sub_124D41();
  byte_19C340 = 1;
  if ( byte_19C386 )
    sub_120940(3, (int)&unk_19C338);
  else
    sub_120BB5(3, (int)&unk_19C338);
  if ( byte_19C386 )
    v15 = sub_11438B(
            word_19C389,
            word_19C38B,
            *(_WORD *)dword_19C330 + word_19C389,
            *(_WORD *)(dword_19C330 + 2) + word_19C38B,
            &unk_179AC2,
            40);
  else
    v15 = (uint16_t)sub_1151B0(
                              word_19C389,
                              word_19C38B,
                              (int)&unk_179AC2,
                              (_WORD *)dword_19C330,
                              &unk_179AC2,
                              40);
  word_19C403 = v15;
  v16 = (uint16_t)sub_115BEA(
                            word_19C38D,
                            word_19C38F,
                            word_19C399,
                            word_19C39B,
                            (int)byte_19C39D,
                            word_19C395,
                            0,
                            0,
                            41,
                            0);
  word_1844CA = 1;
  dword_1844C6 = 0;
  word_19C401 = v16;
  HIWORD(dword_1844CE) = v16;
  strcpy(byte_1B071C, byte_19C39D);
  byte_1B3E18 = 1;
  word_19994C = 0;
  return sub_1191CA((int)sub_91B89, 1);
}
// 1844C6: using guessed type int dword_1844C6;
// 1844CA: using guessed type int16_t word_1844CA;
// 1844CE: using guessed type int dword_1844CE;
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 199A08: using guessed type int16_t word_199A08;
// 199F34: using guessed type char byte_199F34;
// 19C330: using guessed type int dword_19C330;
// 19C334: using guessed type int dword_19C334;
// 19C340: using guessed type char byte_19C340;
// 19C384: using guessed type int16_t word_19C384;
// 19C386: using guessed type char byte_19C386;
// 19C387: using guessed type int16_t word_19C387;
// 19C389: using guessed type int16_t word_19C389;
// 19C38B: using guessed type int16_t word_19C38B;
// 19C38D: using guessed type int16_t word_19C38D;
// 19C38F: using guessed type int16_t word_19C38F;
// 19C391: using guessed type int16_t word_19C391;
// 19C393: using guessed type int16_t word_19C393;
// 19C395: using guessed type int16_t word_19C395;
// 19C399: using guessed type int16_t word_19C399;
// 19C39B: using guessed type int16_t word_19C39B;
// 19C401: using guessed type int16_t word_19C401;
// 19C403: using guessed type int16_t word_19C403;
// 1B3E18: using guessed type char byte_1B3E18;


//----- (00091F14) --------------------------------------------------------
char __fastcall sub_91F14(char *a1, int a2, int a3, char *a4, int a5, int a6, int a7)
{
  int16_t v7; // ax
  int v8; // ebx
  int v9; // edx
  char *v10; // edi
  unsigned int v11; // kr0C_4
  int v12; // ecx
  int v13; // eax
  char *v14; // edi
  int v15; // eax
  int v16; // eax
  char *v18; // [esp-4h] [ebp-80h]
  char v21[100]; // [esp+10h] [ebp-6Ch] BYREF
  int v22; // [esp+74h] [ebp-8h]
  int v23; // [esp+78h] [ebp-4h]

  sub_6FCAB();
  sub_119226();
  sub_6FB5E();
  v23 = 0;
  v22 = 1;
  memset(&dword_19C330, 0, 215);
  if ( strlen(a1) < 0x64 )
  {
    strcpy(byte_19C39D, a1);
  }
  else
  {
    strncpy(byte_19C39D, a1, 100);
    byte_19C400 = 0;
  }
  if ( strlen(a4) < 0x3C )
  {
    strcpy(byte_19C348, a4);
  }
  else
  {
    strncpy(byte_19C348, a4, 60);
    byte_19C383 = 0;
  }
  word_19C395 = a2;
  word_19C387 = a6 + 3;
  byte_19C386 = a7;
  word_19C389 = a5 + 96;
  word_19C38B = a6 + 100;
  word_19C38D = a5 + 34;
  word_19C384 = 54;
  word_19C38F = a6 + 54;
  if ( a3 && a3 <= 205 )
    v7 = a3;
  else
    v7 = 205;
  word_19C399 = v7;
  word_19C391 = a5;
  word_19C393 = a6;
  word_19C39B = 26;
  word_19C397 = a3;
  if ( word_199A08 == 13 )
  {
    byte_199F34 = 20;
    v8 = 20;
    v9 = 0;
  }
  else
  {
    byte_199F34 = 16;
    v8 = 24;
    v9 = 12;
  }
  qmemcpy(&unk_19C338, sub_8E5C5(3u, v9, v8), 8u);
  v11 = strlen(byte_19C39D) + 1;
  v10 = &byte_19C39D[v11];
  v12 = v11 - 1;
  if ( v11 - 1 < 0x64 )
  {
    strcpy(v21, byte_19C39D);
    v10 = v21;
  }
  else
  {
    v8 = 100;
    v9 = (int)byte_19C39D;
    strncpy(v21, byte_19C39D, 100);
    v21[99] = 0;
  }
  v13 = sub_91BD4(v9, (int16_t *)v10);
  LOBYTE(v12) = 1;
  v14 = byte_19C39D;
  while ( !(_WORD)v23 )
  {
    v13 = sub_1171AB(v13, v9, v8, v12);
    v9 = v13;
    if ( (_WORD)v13 == word_19C401 )
    {
      if ( (int16_t)v22 > 0 )
        v23 = 1;
      ++v22;
    }
    if ( (v13 & 0x8000u) != 0 )
    {
      v23 = 1;
      v18 = v14;
      strcpy(v14, v21);
      v14 = v18;
      LOBYTE(v12) = 0;
    }
    if ( (_WORD)v9 == word_19C403 )
      v23 = 2;
    if ( !(_WORD)v23 )
    {
      v15 = sub_124D41();
      goto LABEL_29;
    }
    if ( (_WORD)v23 == 2 && a7 )
    {
      sub_124D41();
      sub_12B753(dword_19C330, 1);
      v8 = dword_19C330;
      v9 = word_19C38B;
      v15 = sub_12B7E1(word_19C389, word_19C38B, (_WORD *)dword_19C330);
LABEL_29:
      if ( word_19994C )
      {
        sub_1113CC(dword_192ED4, v9);
        v15 = sub_91BD4(v9, (int16_t *)v14);
        word_19994C = 0;
      }
      sub_FE8BE(v15, v9, v8, (int16_t *)v14);
      v13 = sub_1077D(v16, v9, v8, (int16_t *)v14);
    }
  }
  sub_13303E((int)byte_19C39D);
  strcpy(a1, byte_19C39D);
  sub_1113CC(dword_192ED4, v9);
  sub_11C2F0();
  sub_119281();
  sub_6FCCE();
  sub_11924F();
  word_19994C = 1;
  return v12;
}
// 92112: variable 'v13' is possibly undefined
// 92191: variable 'v16' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 139ACE: using guessed type int __fastcall strncpy(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 199A08: using guessed type int16_t word_199A08;
// 199F34: using guessed type char byte_199F34;
// 19C330: using guessed type int dword_19C330;
// 19C383: using guessed type char byte_19C383;
// 19C384: using guessed type int16_t word_19C384;
// 19C386: using guessed type char byte_19C386;
// 19C387: using guessed type int16_t word_19C387;
// 19C389: using guessed type int16_t word_19C389;
// 19C38B: using guessed type int16_t word_19C38B;
// 19C38D: using guessed type int16_t word_19C38D;
// 19C38F: using guessed type int16_t word_19C38F;
// 19C391: using guessed type int16_t word_19C391;
// 19C393: using guessed type int16_t word_19C393;
// 19C395: using guessed type int16_t word_19C395;
// 19C397: using guessed type int16_t word_19C397;
// 19C399: using guessed type int16_t word_19C399;
// 19C39B: using guessed type int16_t word_19C39B;
// 19C400: using guessed type char byte_19C400;
// 19C401: using guessed type int16_t word_19C401;
// 19C403: using guessed type int16_t word_19C403;


//----- (0009222A) --------------------------------------------------------
char __fastcall sub_9222A( int a1)
{
  char v2; // dl
  int16_t v3; // ax
  char v4; // dh
  int v5; // ebx

  v2 = 1;
  v3 = 0;
  v4 = 0;
  while ( v3 < 5 && !v4 )
  {
    v5 = *(int16_t *)(dword_19306C + 113 * a1 + 2 * v3 + 74);
    if ( v5 > -1 && *(int16_t *)(17 * v5 + dword_1930D4) > -1 )
    {
      v2 = 0;
      v4 = 1;
    }
    ++v3;
  }
  return v2;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (00092281) --------------------------------------------------------
char __fastcall sub_92281( int a1, int a2, int a3, int a4)
{
  char *v5; // eax

  v5 = sub_7A990(0x100u);
  return sub_922C2(a1, a2, a3, a4, v5);
}


//----- (000922A2) --------------------------------------------------------
char __fastcall sub_922A2( int a1, int a2, int a3)
{
  char *v4; // eax

  v4 = sub_7A990(0x101u);
  return sub_922C2(a1, a2, a3, 0, v4);
}


//----- (000922C2) --------------------------------------------------------
char __fastcall sub_922C2( int a1, int a2, int a3, int a4, char *a5)
{
  int16_t v5; // di
  int16_t v6; // si
  int16_t v7; // ax
  int16_t v8; // dx
  int v9; // ebx
  char *v10; // eax
  char *v11; // ecx
  char *v12; // edi
  char *v14; // eax
  char *v15; // eax
  char v16; // bl
  int v17; // eax
  char *v18; // [esp-10h] [ebp-38h]
  int16_t v19; // [esp-Ch] [ebp-34h]
  int16_t v20; // [esp-8h] [ebp-30h]
  char v21; // [esp-4h] [ebp-2Ch]
  char v22; // [esp-4h] [ebp-2Ch]
  char v26[20]; // [esp+Ch] [ebp-1Ch] BYREF
  _BYTE v27[8]; // [esp+20h] [ebp-8h] BYREF

  sub_120BB5(3, (int)v27);
  v5 = sub_12066F(113 * a3 + dword_19306C);
  v6 = sub_12066F((int)aWwwwwww);
  sub_92457(a3);
  v8 = v7;
  if ( v7 < v5 )
    v8 = v5;
  if ( v8 > v6 )
    v8 = v6;
  if ( v8 > 205 )
    v8 = 205;
  v9 = 113 * a3;
  strcpy(v26, (char *)(v9 + dword_19306C));
  if ( a4 )
  {
    v21 = 1;
    v10 = (char *)(v9 + dword_19306C);
    v20 = a2;
    v11 = a5;
    v19 = a1;
  }
  else
  {
    v21 = 0;
    v11 = a5;
    v20 = a2;
    v19 = a1;
    v10 = (char *)(v9 + dword_19306C);
  }
  v18 = v10;
  v14 = (char *)GetGameFlagsTable_F4B81();
  *(v14 - 1) = *(_BYTE *)(*(_DWORD *)(v14 + 109455) + 14);
  v22 = sub_91F14(v18, 15, v8, v11, v19, v20, v21);
  v15 = (char *)GetGameFlagsTable_F4B81();
  v16 = *(v15 - 1);
  v17 = *(_DWORD *)(v15 + 109455);
  *(_BYTE *)(v17 + 14) = v16;
  *(_BYTE *)(v17 + 13) = 0;
  v12 = (char *)(dword_19306C + 113 * a3);
  if ( !*v12 )
    strcpy(v12, v26);
  sub_12066F(dword_19306C + 113 * a3);
  return v22;
}
// 922FF: variable 'v7' is possibly undefined
// 19306C: using guessed type int dword_19306C;


//----- (000923BE) --------------------------------------------------------
int sub_923BE()
{
  return 177;
}


//----- (000923C4) --------------------------------------------------------
int sub_923C4()
{
  return 125;
}


//----- (000923CA) --------------------------------------------------------
int sub_923CA()
{
  return 131;
}


//----- (000923D0) --------------------------------------------------------
int sub_923D0()
{
  return 146;
}


//----- (000923D6) --------------------------------------------------------
int sub_923D6()
{
  dword_193070 = sub_127C27((int)aBuffer0Lbx_7, 73, dword_193174);
  return (*(int16_t *)dword_193070 - 285) / 2 + (int16_t)(320 - *(int16_t *)dword_193070 / 2);
}
// 193070: using guessed type int dword_193070;
// 193174: using guessed type int dword_193174;


//----- (0009241D) --------------------------------------------------------
void sub_9241D()
{
  dword_193070 = sub_127C27((int)aBuffer0Lbx_7, 73, dword_193174);
  JUMPOUT(0x9240D);
}
// 92455: control flows out of bounds to 9240D
// 193070: using guessed type int dword_193070;
// 193174: using guessed type int dword_193174;


//----- (00092457) --------------------------------------------------------
void __fastcall sub_92457( int a1)
{
  int16_t v1; // di
  int v2; // eax
  int v3; // esi
  int16_t v4; // ax
  int16_t v5; // [esp+0h] [ebp-30h]
  int v6; // [esp+4h] [ebp-2Ch] BYREF
  int16_t v7; // [esp+8h] [ebp-28h] BYREF
  int v8; // [esp+Ch] [ebp-24h] BYREF
  int v9; // [esp+10h] [ebp-20h] BYREF
  int v10; // [esp+14h] [ebp-1Ch]
  int v11; // [esp+18h] [ebp-18h] BYREF
  int v12; // [esp+1Ch] [ebp-14h]
  int v13; // [esp+20h] [ebp-10h]
  int v14; // [esp+24h] [ebp-Ch]
  int16_t v15; // [esp+28h] [ebp-8h] BYREF
  unsigned int v16; // [esp+2Ch] [ebp-4h]

  v1 = 999;
  v14 = -1;
  v13 = -1;
  sub_8A3E7(a1, &v11, &v15, (int16_t *)&v9);
  LOWORD(v2) = sub_122259();
  v3 = 0;
  v16 = 999;
  v10 = v2 + 2;
  while ( (int16_t)v3 < word_19999A )
  {
    if ( (_WORD)v3 != v5 )
    {
      sub_8A3E7((int16_t)v3, &v8, &v7, (int16_t *)&v6);
      if ( (int)abs32(v7 - v15) < (int16_t)v10 )
      {
        v4 = v8 - v11;
        if ( (int16_t)(v8 - v11) >= 0 )
        {
          if ( abs16(v4) < v1 )
          {
            v14 = v3;
            v1 = abs16(v4);
          }
        }
        else if ( abs16(v4) < (int16_t)v16 )
        {
          v16 = abs16(v4);
          v13 = v3;
          v12 = v6;
        }
      }
    }
    if ( (int16_t)v13 == -1 )
    {
      v12 = 0;
      v16 = abs32((int16_t)v11 - 21);
    }
    if ( (int16_t)v14 == -1 )
    {
      v1 = abs32((int16_t)v11 - 527);
      if ( v1 < (int16_t)v9 )
        v1 = v9;
    }
    ++v3;
  }
  JUMPOUT(0x91F0D);
}
// 9259D: control flows out of bounds to 91F0D
// 9248F: variable 'v2' is possibly undefined
// 9249B: variable 'v5' is possibly undefined
// 19999A: using guessed type int16_t word_19999A;


//----- (000925AE) --------------------------------------------------------
_DWORD *__fastcall sub_925AE(int a1, int a2, int a3, int a4, unsigned int a5)
{
  int16_t v5; // dx
  int16_t v6; // ax
  int16_t v7; // ax

  v5 = *(uint8_t *)(dword_1930DC + 59 * a2 + 49);
  v6 = 0;
  if ( a5 )
  {
    if ( a5 <= 1u )
    {
      v6 = 210;
    }
    else if ( a5 == 2 )
    {
      v6 = 277;
    }
  }
  else
  {
    v6 = 21;
  }
  v7 = v5 + v6;
  if ( a4 )
    return sub_126AFD((int)off_182278, v7, a3);
  else
    return sub_126B42((int)off_182278, v7, a3);
}
// 182278: using guessed type char *off_182278;
// 1930DC: using guessed type int dword_1930DC;


//----- (00092619) --------------------------------------------------------
_DWORD *__fastcall sub_92619(int a1, int a2, int a3, int a4)
{
  int16_t v4; // ax

  v4 = *(uint8_t *)(dword_1930DC + 59 * a2 + 49) + 143;
  if ( a4 )
    return sub_126AFD((int)off_182278, v4, a3);
  else
    return sub_126B42((int)off_182278, v4, a3);
}
// 182278: using guessed type char *off_182278;
// 1930DC: using guessed type int dword_1930DC;


//----- (0009264E) --------------------------------------------------------
int64_t __fastcall sub_9264E(
        _WORD *a1,
        _WORD *a2,
        _WORD *a3,
        _WORD *a4,
        _WORD *a5,
        int a6,
        int a7,
        uint16_t *a8,
        uint16_t *a9,
        uint16_t *a10,
        _WORD *a11,
        int16_t *a12)
{
  int16_t v13; // ax
  _WORD *v14; // esi
  int16_t v15; // ax
  _WORD *v16; // ecx
  int16_t v17; // si
  int16_t v18; // di
  int16_t v19; // cx
  uint16_t v20; // ax
  _WORD *v21; // ecx
  uint16_t v22; // ax
  int v23; // esi
  _WORD *v24; // ecx
  uint16_t v25; // ax
  _WORD *v26; // ecx
  int v29; // [esp+8h] [ebp-34h]
  int16_t v30; // [esp+Ch] [ebp-30h] BYREF
  int16_t v31; // [esp+10h] [ebp-2Ch] BYREF
  int v32; // [esp+14h] [ebp-28h]
  int v33; // [esp+18h] [ebp-24h]
  int v34; // [esp+1Ch] [ebp-20h]
  int v35; // [esp+20h] [ebp-1Ch]
  int16_t v36; // [esp+24h] [ebp-18h] BYREF
  int v37; // [esp+28h] [ebp-14h]
  int v38; // [esp+2Ch] [ebp-10h]
  char v39; // [esp+30h] [ebp-Ch]
  _BOOL1 v40; // [esp+34h] [ebp-8h]
  _BOOL1 v41; // [esp+38h] [ebp-4h]

  v34 = 612;
  v35 = 45;
  v38 = 10;
  v37 = 121;
  v40 = byte_199F1F == 0;
  v39 = sub_9427B();
  v41 = word_1999A6 > 0;
  if ( byte_19C544 && word_1999A6 > 0 )
    word_19C538 = sub_11438B(463, 441, *(_WORD *)dword_1930FC + 463, *(_WORD *)(dword_1930FC + 2) + 441, aDph, 41);
  else
    word_19C538 = -1000;
  if ( byte_19C544 && v41 )
    word_19C53A = sub_11438B(388, 441, *(_WORD *)dword_193110 + 388, *(_WORD *)(dword_193110 + 2) + 441, &aDph[1], 41);
  else
    word_19C53A = -1000;
  if ( v39 && byte_19C544 )
    *a1 = (uint16_t)sub_1151B0(313, 441, (int)&unk_179AEA, (_WORD *)dword_19312C, &aDph[2], 40);
  else
    *a1 = -1000;
  if ( byte_19C544 || !v39 )
    *a2 = -1000;
  else
    *a2 = (uint16_t)sub_1151B0(460, 439, (int)&unk_179AEA, (_WORD *)dword_1930E0, asc_179AEB, 40);
  v13 = sub_11438B(156, 11, *(_WORD *)dword_193164 + 156, *(_WORD *)(dword_193164 + 2) + 11, aS_10, 41);
  v14 = (_WORD *)dword_19316C;
  *a3 = v13;
  v15 = sub_11438B(9, 11, *v14 + 9, v14[1] + 11, &off_179AEF, 41);
  v16 = (_WORD *)dword_1930F8;
  *a4 = v15;
  v32 = 130;
  v33 = 142;
  v17 = 0;
  *a5 = (uint16_t)sub_1151B0(538, 441, (int)&unk_179AEA, v16, (_BYTE *)&off_179AEF + 2, 40);
  sub_97400();
  do
  {
    if ( v17 >= word_1999A6 )
    {
      *(_WORD *)(a6 + 2 * v17) = -1000;
      *(_WORD *)(a7 + 2 * v17) = -1000;
    }
    else
    {
      v18 = 109 * v17 + 34;
      v29 = 2 * v17;
      v19 = v32;
      *(_WORD *)(v29 + a6) = sub_11438B(92, v18, 296, v33, &unk_179AEA, 41);
      *(_WORD *)(v29 + a7) = sub_11438B(8, v18, 91, v19, &unk_179AEA, 41);
    }
    v32 += 109;
    ++v17;
    v33 += 109;
  }
  while ( v17 < 4 );
  *a8 = -1000;
  *a9 = -1000;
  *a12 = -1000;
  if ( v40 )
  {
    v20 = (uint16_t)sub_1151B0(613, 22, (int)&unk_179AEA, (_WORD *)dword_193160, byte_179AF3, 40);
    v21 = (_WORD *)dword_193120;
    *a8 = v20;
    v22 = (uint16_t)sub_1151B0(613, 170, (int)&unk_179AEA, v21, byte_179AF5, 40);
    LOWORD(v21) = v38;
    *a9 = v22;
    sub_75B80(a12, v34, v35, (int16_t)v21, v37);
    *(_WORD *)(dword_1975C4 + 8) = (uint8_t)byte_199EFC;
  }
  else
  {
    sub_A1C74(word_19C53E, 306, 17, 0, 0, 0, 0, &v31, 0, &v30);
  }
  v23 = dword_1975C4;
  *(_WORD *)(dword_1975C4 + 16) = *a8;
  v24 = (_WORD *)dword_193128;
  *(_WORD *)(v23 + 18) = *a9;
  v25 = (uint16_t)sub_1151B0(568, 205, (int)&unk_179AEA, v24, byte_179AF7, 40);
  v26 = (_WORD *)dword_193158;
  *a10 = v25;
  *a11 = (uint16_t)sub_1151B0(327, 205, (int)&unk_179AEA, v26, ",", 40);
  word_19C18C = sub_11438B(0, 470, 10, 479, &unk_179AEA, 41);
  sub_755D2();
  sub_9023B(306, 235, 318, 169, 0, 0, 0, 0, 1, &v36, (int)word_190178, &word_19997A);
  return sub_11438B(0, 0, 639, 479, &unk_179AEA, 0);
}
// 179AE4: using guessed type wchar_t aDph[3];
// 179AEF: using guessed type _UNKNOWN *off_179AEF;
// 179AF3: using guessed type _BYTE byte_179AF3[2];
// 179AF5: using guessed type _BYTE byte_179AF5[2];
// 179AF7: using guessed type _BYTE byte_179AF7[2];
// 190178: using guessed type int16_t word_190178[72];
// 1930E0: using guessed type int dword_1930E0;
// 1930F8: using guessed type int dword_1930F8;
// 1930FC: using guessed type int dword_1930FC;
// 193110: using guessed type int dword_193110;
// 193120: using guessed type int dword_193120;
// 193128: using guessed type int dword_193128;
// 19312C: using guessed type int dword_19312C;
// 193158: using guessed type int dword_193158;
// 193160: using guessed type int dword_193160;
// 193164: using guessed type int dword_193164;
// 19316C: using guessed type int dword_19316C;
// 1975C4: using guessed type int dword_1975C4;
// 19997A: using guessed type int16_t word_19997A;
// 1999A6: using guessed type int16_t word_1999A6;
// 199EFC: using guessed type char byte_199EFC;
// 199F1F: using guessed type char byte_199F1F;
// 19C18C: using guessed type int16_t word_19C18C;
// 19C538: using guessed type int16_t word_19C538;
// 19C53A: using guessed type int16_t word_19C53A;
// 19C53E: using guessed type int16_t word_19C53E;
// 19C544: using guessed type char byte_19C544;


//----- (00092A92) --------------------------------------------------------
char __fastcall sub_92A92( int a1, int a2, int a3, int a4, int a5)
{
  int v5; // esi
  int16_t v6; // di
  char v7; // al
  _BOOL1 v8; // al
  char v9; // al
  int16_t v10; // dx
  _WORD *v11; // eax
  int16_t v12; // di
  _WORD *v13; // eax
  int16_t v14; // dx
  int v18; // [esp+Ch] [ebp-1Ch]
  int16_t v19; // [esp+10h] [ebp-18h]
  int v20; // [esp+18h] [ebp-10h]
  int16_t v21; // [esp+1Ch] [ebp-Ch]
  int v22; // [esp+20h] [ebp-8h]
  _BOOL1 v23; // [esp+24h] [ebp-4h]

  v21 = *(uint8_t *)(dword_1930DC + 59 * a4 + 35);
  v19 = a1 + 190;
  v20 = a2 - 1;
  v5 = 0;
  v6 = 0;
  v22 = a2 + 15;
  do
  {
    if ( v21 )
    {
      if ( v21 != 1 )
        goto LABEL_13;
      v8 = 0;
      if ( byte_17D21D[18 * v6] == 2 )
      {
        sub_9469E();
        if ( v9 )
          v8 = 1;
      }
    }
    else
    {
      v8 = 0;
      if ( byte_17D21D[18 * v6] == 1 )
      {
        sub_9469E();
        if ( v7 )
          v8 = 1;
      }
    }
    v23 = v8;
LABEL_13:
    if ( v23 )
    {
      v10 = sub_11438B(a1, v20, v19, v22, &unk_179AEA, 41);
      v11 = (_WORD *)(a5 + 2 * (int16_t)v5);
      v20 += 17;
      v22 += 17;
      *v11 = v10;
      ++v5;
      v11[5] = v6;
    }
    ++v6;
  }
  while ( v6 < 54 );
  v12 = 0;
  v18 = a2 + 17 * v5 + 15;
  do
  {
    LOBYTE(v13) = !byte_17D21D[18 * v12] && sub_9467D(word_19999C, a4, v12);
    if ( (_BYTE)v13 )
    {
      v14 = sub_11438B(a1, a2 + 17 * v5, a1 + 190, v18, &unk_179AEA, 41);
      v13 = (_WORD *)(a5 + 2 * (int16_t)v5);
      v18 += 17;
      *v13 = v14;
      LOWORD(v5) = v5 + 1;
      v13[5] = v12;
    }
    ++v12;
  }
  while ( v12 < 54 );
  while ( (int16_t)v5 < 5 )
  {
    v13 = (_WORD *)(a5 + 2 * (int16_t)v5);
    *v13 = -1000;
    LOWORD(v5) = v5 + 1;
    v13[5] = 0;
  }
  return (char)v13;
}
// 92AF9: variable 'v7' is possibly undefined
// 92B2B: variable 'v9' is possibly undefined
// 92B3A: variable 'v23' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;
// 19999C: using guessed type int16_t word_19999C;


//----- (00092C25) --------------------------------------------------------
int __fastcall sub_92C25( int a1, int a2, int a3)
{
  int16_t *v4; // edi
  char *v5; // esi
  char v6; // al
  int16_t *v7; // eax
  int result; // eax
  int16_t v9[100]; // [esp+0h] [ebp-190h] BYREF
  _BYTE v10[200]; // [esp+C8h] [ebp-C8h] BYREF

  v4 = v9;
  v5 = sub_7A990(0x122u);
  do
  {
    v6 = *v5++;
    *(_BYTE *)v4 = v6;
    v4 = (int16_t *)((char *)v4 + 1);
  }
  while ( v6 );
  v7 = sub_97588(a1, 1);
  sprintf(v10, (char *)v9, v7);
  result = sub_94B3A((int)v10, 0, a3, v9, (int16_t)v5);
  byte_199F15 = -1;
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 199F15: using guessed type char byte_199F15;


//----- (00092C87) --------------------------------------------------------
void sub_92C87()
{
  int16_t i; // dx
  int v1; // eax
  int16_t v2; // bx
  _BOOL1 v3; // cl
  int16_t j; // bx
  int v5; // eax

  for ( i = 0; i < word_19999A; ++i )
  {
    v1 = dword_19306C + 113 * i;
    v2 = *(char *)(v1 + 40) - 80;
    if ( *(_BYTE *)(v1 + 40) == 8 || v2 > -1 && v2 < word_199998 )
    {
      v3 = 0;
      for ( j = 0; j < 67 && !v3; ++j )
      {
        v5 = dword_1930DC + 59 * j;
        if ( *(_BYTE *)(v5 + 57) == 5 )
          v3 = i == *(_WORD *)(v5 + 53);
      }
    }
  }
}
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (00092CF8) --------------------------------------------------------
int64_t __fastcall sub_92CF8(int a1, int a2)
{
  int16_t *v3; // edi
  char *v4; // esi
  char v5; // al
  int16_t *v6; // eax
  int64_t result; // rax
  _BYTE v8[256]; // [esp+0h] [ebp-1C8h] BYREF
  int16_t v9[100]; // [esp+100h] [ebp-C8h] BYREF

  v3 = v9;
  v4 = sub_7A990(0x123u);
  do
  {
    v5 = *v4++;
    *(_BYTE *)v3 = v5;
    v3 = (int16_t *)((char *)v3 + 1);
  }
  while ( v5 );
  v6 = sub_97588(a1, 1);
  sprintf(v8, (char *)v9, *(_DWORD *)(dword_197F98 + 3753 * word_19999C + 50), v6, a2);
  result = (unsigned int)sub_94B3A((int)v8, 0, a1, v9, (int16_t)v4);
  byte_199F15 = -1;
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199F15: using guessed type char byte_199F15;


//----- (00092D72) --------------------------------------------------------
void __fastcall sub_92D72( int a1)
{
  uint16_t v2; // ax
  int16_t *v3; // eax
  int64_t v4; // rax
  int v5; // [esp-8h] [ebp-11Eh]
  int v6; // [esp-4h] [ebp-11Ah]
  _BYTE v7[200]; // [esp+0h] [ebp-116h] BYREF
  char v8[200]; // [esp+C8h] [ebp-4Eh] BYREF
  int16_t v9; // [esp+190h] [ebp+7Ah] BYREF
  int16_t v10; // [esp+194h] [ebp+7Eh] BYREF

  sub_93D8E(a1, &v9, &v10);
  sub_1196F7();
  byte_19C543 = 1;
  if ( v10 == 1 )
    v2 = 292;
  else
    v2 = 293;
  strcpy(v8, sub_7A990(v2));
  v6 = v10;
  v5 = v9;
  v3 = sub_97588(a1, 1);
  v4 = sprintf(v7, v8, v3, v5, v6);
  if ( sub_C7AB8(word_19999C, SWORD2(v4), (int)v7) )
  {
    sub_9412B(word_19999C, a1);
    byte_19C544 = -1;
  }
  else if ( !byte_19C544 )
  {
    sub_123E6C((int)&unk_18228C, 1);
    byte_199F15 = -1;
  }
  sub_9872C();
  byte_19C543 = 0;
  sub_1191CA((int)sub_93550, 1);
  byte_199F11 = 1;
  JUMPOUT(0x94801);
}
// 92E6D: control flows out of bounds to 94801
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19999C: using guessed type int16_t word_19999C;
// 199F11: using guessed type char byte_199F11;
// 199F15: using guessed type char byte_199F15;
// 19C543: using guessed type char byte_19C543;
// 19C544: using guessed type char byte_19C544;


//----- (00092E72) --------------------------------------------------------
int16_t sub_92E72()
{
  int16_t v0; // bx
  int v1; // eax
  int v2; // ecx
  int16_t v3; // si
  int16_t i; // dx
  _BOOL1 v6; // [esp+0h] [ebp-10h]
  _BOOL1 v7; // [esp+Ch] [ebp-4h]

  v0 = 0;
  LOWORD(v1) = 0;
  do
  {
    v2 = 2 * (int16_t)v1;
    LOWORD(v1) = v1 + 1;
    *(_WORD *)(v2 + dword_193188) = -1;
  }
  while ( (int16_t)v1 < 67 );
  v3 = 0;
  for ( i = 0; i < 67 && !v3; ++i )
  {
    v1 = dword_1930DC + 59 * i;
    v6 = *(_BYTE *)(v1 + 35) == 0;
    v7 = *(_BYTE *)(v1 + 35) == 1;
    if ( *(char *)(v1 + 57) >= 0 )
    {
      LOWORD(v1) = *(char *)(v1 + 58);
      if ( (_WORD)v1 == word_19999C && (!byte_199F1F && v6 || byte_199F1F && v7) )
      {
        v1 = v0++;
        *(_WORD *)(dword_193188 + 2 * v1) = i;
        if ( v0 >= 4 )
          v3 = 1;
      }
    }
  }
  word_1999A6 = v0;
  return v1;
}
// 1930DC: using guessed type int dword_1930DC;
// 193188: using guessed type int dword_193188;
// 19999C: using guessed type int16_t word_19999C;
// 1999A6: using guessed type int16_t word_1999A6;
// 199F1F: using guessed type char byte_199F1F;


//----- (00092F8A) --------------------------------------------------------
void __usercall sub_92F8A(int a1)
{
  int16_t i; // bx
  int v2; // eax
  int16_t *v3; // edx

  for ( i = 0; i < 67; ++i )
  {
    v2 = 59 * i + dword_1930DC;
    if ( *(_BYTE *)(v2 + 35) == 1 )
    {
      v3 = (int16_t *)(2 * i + dword_1930EC);
      if ( *(_WORD *)(v2 + 53) != *v3 && !*(_BYTE *)(v2 + 57) )
        sub_E2AB1(*v3, word_19999C, a1);
    }
  }
}
// 1930DC: using guessed type int dword_1930DC;
// 1930EC: using guessed type int dword_1930EC;
// 19999C: using guessed type int16_t word_19999C;


//----- (00092FDA) --------------------------------------------------------
int sub_92FDA()
{
  int16_t i; // cx
  int result; // eax
  int16_t v2; // dx

  for ( i = 0; i < 67; ++i )
  {
    result = dword_1930DC + 59 * i;
    v2 = *(char *)(result + 58);
    if ( *(_BYTE *)(result + 57) <= 1u )
    {
      result = *(char *)(result + 58);
      if ( v2 != -1 )
        result = sub_97C64(result, i, 1);
    }
  }
  return result;
}
// 1930DC: using guessed type int dword_1930DC;


//----- (0009301E) --------------------------------------------------------
void __fastcall sub_9301E(int16_t *a1, char *a2, int a3, int a4)
{
  int16_t v5; // si
  int v7; // ebx
  int16_t v8; // ax
  int16_t *v9; // edi
  char *v10; // esi
  char v11; // al
  int16_t *v12; // eax
  void *v13; // eax
  int v14; // eax
  int16_t v15; // dx
  int16_t *v16; // edi
  char *v17; // esi
  char v18; // al
  int16_t *v19; // eax
  _BYTE *v20; // eax
  int v21; // edx
  int v22; // ebx
  int16_t *v23; // edi
  char v24; // al
  int16_t *v25; // eax
  int16_t *v26; // edi
  char v27; // al
  int16_t *v28; // eax
  int16_t v29; // cx
  int v30; // edx
  int v31; // [esp-4h] [ebp-1F0h]
  int16_t v32[100]; // [esp+0h] [ebp-1ECh] BYREF
  _BYTE v33[200]; // [esp+C8h] [ebp-124h] BYREF
  _BYTE v34[80]; // [esp+190h] [ebp-5Ch] BYREF
  int16_t v35; // [esp+1E0h] [ebp-Ch] BYREF
  int16_t v36; // [esp+1E4h] [ebp-8h] BYREF
  _BOOL1 v37; // [esp+1E8h] [ebp-4h]

  v5 = (int16_t)a2;
  v37 = byte_199F1F == 0;
  v7 = (int16_t)a2;
  v8 = sub_96E95(a3, a4, (int16_t)a2, (int16_t)a1, &byte_199F0F, &v36, &v35);
  if ( v8 )
  {
    if ( v8 != 1 || v35 == -1 )
    {
      if ( v8 == 1 )
        sub_97D59(v36, a1, a2);
    }
    else
    {
      v29 = v36;
      v30 = (int16_t)sub_94BB2(word_19999C, v36, v35);
      sub_9636D(v35, v30, v29);
    }
  }
  else
  {
    if ( byte_199F15 == v36 )
    {
LABEL_29:
      byte_199F15 = -1;
      return;
    }
    if ( v36 <= -1 )
      return;
    byte_199F15 = v36;
    if ( !byte_19C544 || byte_19C544 == -1 && *(_BYTE *)(dword_1930DC + 59 * (char)v36 + 57) == 4 )
    {
      sub_98062(byte_199F15);
      byte_199F11 = 1;
      if ( !byte_19C544 )
        return;
      goto LABEL_29;
    }
    if ( byte_19C544 == 2 )
    {
      v9 = v32;
      v10 = sub_7A990(0x126u);
      do
      {
        v11 = *v10++;
        *(_BYTE *)v9 = v11;
        v9 = (int16_t *)((char *)v9 + 1);
      }
      while ( v11 );
      sub_123E6C((int)&unk_17CF00, 1);
      v12 = sub_97588(byte_199F15, 1);
      sprintf(v33, (char *)v32, v12);
      if ( (uint16_t)sub_94B3A((int)v33, 1u, v7, v32, (int16_t)v10) )
      {
        sub_98771(byte_199F15);
        byte_199F15 = -1;
LABEL_16:
        byte_199F11 = 1;
        return;
      }
      v13 = &unk_18228C;
LABEL_15:
      sub_123E6C((int)v13, 1);
      goto LABEL_16;
    }
    if ( byte_19C544 == 1 )
    {
      v14 = 59 * byte_199F15 + dword_1930DC;
      if ( *(_BYTE *)(v14 + 57) && *(_BYTE *)(v14 + 57) != 2 )
      {
        sub_943A0(byte_199F15);
        goto LABEL_16;
      }
      byte_199F15 = -1;
      v13 = &unk_17CF00;
      byte_19C544 = -1;
      goto LABEL_15;
    }
    if ( v37 )
    {
      if ( word_19991A <= -1 )
        return;
      v15 = *(_WORD *)(13 * word_19991A + dword_192B24 + 11);
      if ( sub_94254(byte_199F15) )
      {
        sub_987FB(byte_199F15, v15, v5);
        v21 = 13 * word_19991A;
        byte_199F11 = 1;
        word_19991A = -1;
        *(_BYTE *)(v21 + dword_192B24 + 4) = 0;
        goto LABEL_29;
      }
      v16 = v32;
      v17 = sub_7A990(0x127u);
      do
      {
        v18 = *v17++;
        *(_BYTE *)v16 = v18;
        v16 = (int16_t *)((char *)v16 + 1);
      }
      while ( v18 );
      v19 = sub_97588(byte_199F15, 0);
      sprintf(v33, (char *)v32, v19);
      v20 = v33;
      goto LABEL_28;
    }
    if ( word_19C540 > -1 && sub_79D1C(word_19999C, word_19C540) )
    {
      if ( sub_94254(byte_199F15) )
      {
        v22 = 59 * byte_199F15;
        if ( *(_WORD *)(dword_1930DC + v22 + 53) != word_19C540 )
        {
          sub_987FB(byte_199F15, word_19C540, v22);
          byte_199F11 = 1;
        }
        goto LABEL_29;
      }
      if ( *(_BYTE *)(59 * byte_199F15 + dword_1930DC + 57) == 4 )
      {
        v23 = v32;
        v17 = sub_7A990(0x127u);
        do
        {
          v24 = *v17++;
          *(_BYTE *)v23 = v24;
          v23 = (int16_t *)((char *)v23 + 1);
        }
        while ( v24 );
        v25 = sub_97588(byte_199F15, 0);
        sprintf(v34, (char *)v32, v25);
      }
      else
      {
        v26 = v32;
        v17 = sub_7A990(0x128u);
        do
        {
          v27 = *v17++;
          *(_BYTE *)v26 = v27;
          v26 = (int16_t *)((char *)v26 + 1);
        }
        while ( v27 );
        v31 = dword_19306C + 113 * word_19C540;
        v28 = sub_97588(byte_199F15, 0);
        sprintf(v34, (char *)v32, v28, v31);
      }
      v20 = v34;
LABEL_28:
      sub_94B3A((int)v20, 0, v7, v32, (int16_t)v17);
      goto LABEL_29;
    }
  }
}
// 932F1: conditional instruction was optimized away because al.1==0
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192B24: using guessed type int dword_192B24;
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 19991A: using guessed type int16_t word_19991A;
// 19999C: using guessed type int16_t word_19999C;
// 199F0F: using guessed type char byte_199F0F;
// 199F11: using guessed type char byte_199F11;
// 199F15: using guessed type char byte_199F15;
// 199F1F: using guessed type char byte_199F1F;
// 19C540: using guessed type int16_t word_19C540;
// 19C544: using guessed type char byte_19C544;


//----- (000933F2) --------------------------------------------------------
int __fastcall sub_933F2( int a1)
{
  int v2; // esi
  int16_t v3; // cx
  int v4; // eax
  int16_t v5; // bx
  int v6; // eax
  int16_t v7; // ax
  int v8; // ebx
  int v9; // ebx
  int result; // eax
  int v11; // ebx

  v2 = 59 * a1;
  v3 = *(char *)(v2 + dword_1930DC + 58);
  sub_979A0(a1);
  v4 = v2 + dword_1930DC;
  if ( *(_BYTE *)(v2 + dword_1930DC + 35) == 1 )
  {
    v5 = *(_WORD *)(v4 + 53);
    if ( v5 != -1 )
    {
      if ( *(_BYTE *)(v4 + 57) == 5 )
        *(_BYTE *)(dword_19306C + 113 * v5 + 40) = 0;
      if ( v3 != -1 )
      {
        v6 = 113 * v5 + dword_19306C + v3;
        if ( *(char *)(v6 + 66) == a1 )
          *(_BYTE *)(v6 + 66) = -1;
      }
    }
  }
  else if ( !*(_BYTE *)(v4 + 35) && v3 != -1 )
  {
    v7 = *(_WORD *)(v4 + 53);
    v8 = v7;
    if ( v7 != -1 && sub_77FF5(v7) == v3 )
    {
      v9 = 129 * v8;
      if ( a1 == *(_WORD *)(v9 + dword_197F9C + 116) )
        *(_WORD *)(v9 + dword_197F9C + 116) = -1;
    }
  }
  result = 59 * a1;
  v11 = dword_1930DC;
  *(_BYTE *)(dword_1930DC + result + 55) = 0;
  *(_BYTE *)(v11 + result + 57) = -1;
  *(_WORD *)(v11 + result + 53) = -1;
  *(_BYTE *)(v11 + result + 58) = -1;
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;


//----- (000934CF) --------------------------------------------------------
void __usercall sub_934CF(int a1)
{
  int16_t i; // bx
  int v2; // eax

  for ( i = 0; i < 67; ++i )
  {
    v2 = 59 * i + dword_1930DC;
    if ( *(_BYTE *)(v2 + 57) == 4 )
    {
      if ( (char)++*(_BYTE *)(v2 + 55) >= 30 )
        sub_933F2(i);
    }
    else if ( *(_BYTE *)(v2 + 57) == 1
           && *(char *)(v2 + 55) > 0
           && (*(_BYTE *)(v2 + 55))-- == 1
           && *(_BYTE *)(v2 + 35) == 1 )
    {
      sub_E2AB1(*(_WORD *)(v2 + 53), *(char *)(v2 + 58), a1);
    }
  }
}
// 1930DC: using guessed type int dword_1930DC;


//----- (00093550) --------------------------------------------------------
void __usercall sub_93550( int a1)
{
  int16_t i; // bx
  int16_t *v2; // eax
  int v3; // ebx
  int v4; // ebx
  char *v5; // eax
  char *v6; // eax
  char *v7; // esi
  int16_t v8; // di
  int v9; // eax
  int v10; // eax
  uint16_t v11; // ax
  char *v12; // eax
  int16_t v13; // ax
  int v14; // ebx
  int v15; // edx
  int v16; // eax
  int v17; // [esp-8h] [ebp-4Eh]
  int v18; // [esp-8h] [ebp-4Eh]
  int v19; // [esp-4h] [ebp-4Ah]
  int v20; // [esp-4h] [ebp-4Ah]
  int v21; // [esp-4h] [ebp-4Ah]
  char v22[100]; // [esp+0h] [ebp-46h] BYREF
  _BYTE v23[80]; // [esp+64h] [ebp+1Eh] BYREF
  int16_t v24; // [esp+B4h] [ebp+6Eh] BYREF
  int v25; // [esp+B8h] [ebp+72h]
  int16_t v26; // [esp+BCh] [ebp+76h] BYREF
  int v27; // [esp+C0h] [ebp+7Ah]
  _BOOL1 v28; // [esp+C4h] [ebp+7Eh]

  v28 = byte_199F1F == 0;
  if ( byte_199F11 || word_19994C || byte_19C543 )
    sub_93A1E();
  sub_128BE7();
  sub_12B65C();
  if ( v28 )
  {
    if ( byte_19C545 )
    {
      byte_19C545 = 0;
    }
    else
    {
      if ( sub_A0226((int16_t *)dword_1975C4, (void (__cdecl *)(_DWORD))sub_73873) )
        word_19991C = -1;
      if ( word_1999D8 > -1 )
        sub_732D6(29, (int)sub_73873, a1);
    }
  }
  else
  {
    sub_974A6(word_19C53E);
  }
  sub_90C4F(235, 306, a1, 318, 169, 0, 0, 0, 0, 1, 0);
  sub_734F1(29);
  sub_737A2();
  if ( word_19990E > -1 )
    sub_957E3(word_19990E);
  if ( word_1999D8 > -1 && v28 )
    sub_72F19();
  if ( word_19991C > -1 && v28 )
    sub_964BB();
  for ( i = 0; i < word_1999A6; ++i )
  {
    v2 = (int16_t *)(2 * i + dword_193188);
    if ( *v2 > -1 )
      sub_973CC(i, *v2);
  }
  if ( byte_19C544 == 2 )
  {
    sub_12B753(dword_1930FC, 1);
    v3 = dword_1930FC;
  }
  else
  {
    if ( word_19C538 != -1000 )
      goto LABEL_31;
    v3 = dword_1930E8;
  }
  sub_12A478(463, 441, v3);
LABEL_31:
  if ( byte_19C544 == 1 )
  {
    sub_12B753(dword_193110, 1);
    v4 = dword_193110;
  }
  else
  {
    if ( word_19C53A != -1000 )
      goto LABEL_36;
    v4 = dword_193104;
  }
  sub_12A478(388, 441, v4);
LABEL_36:
  if ( !sub_9427B() )
    sub_12A478(313, 441, dword_193100);
  if ( !byte_19C544 )
  {
    sub_12A478(300, 441, dword_19310C);
    if ( byte_199F0F > -1 )
    {
      sub_93D8E(byte_199F0F, &v24, &v26);
      if ( v26 )
      {
        v20 = v26;
        v17 = v24;
        v6 = sub_7A990(0x121u);
        sprintf(v23, v6, v17, v20);
      }
      else
      {
        v19 = v24;
        v5 = sub_7A990(0x129u);
        sprintf(v23, v5, v19);
      }
      sub_8FDA1((int)v23, (int)&unk_182284, 4, 2, 0, 132, 1);
      sub_1212B3(315, 450, (int)v23);
    }
  }
  if ( !v28 && word_19C53E != -1 )
  {
    v7 = (char *)(113 * word_19C53E + dword_19306C);
    v25 = 466;
    v8 = v7[word_19999C + 66];
    v9 = v7[word_19999C + 66];
    v27 = 210;
    if ( v9 == -1 )
    {
      strcpy(v22, v7);
    }
    else
    {
      v10 = dword_1930DC + 59 * v8;
      if ( *(char *)(v10 + 55) <= 0 )
      {
        sprintf(v22, "%s (%s)", v7, (char *)(dword_1930DC + 59 * v8));
      }
      else
      {
        v21 = *(char *)(v10 + 55);
        v18 = dword_1930DC + 59 * v8;
        if ( *(_BYTE *)(v10 + 55) == 1 )
          v11 = 146;
        else
          v11 = 147;
        v12 = sub_7A990(v11);
        sprintf(v22, v12, v7, v18, v21);
      }
    }
    sub_8FDA1((int)v22, (int)&unk_182284, 3, 2, 0, 203, 1);
    sub_1210FD(v25, v27, (int)v22);
  }
  if ( byte_199F09 == 99 )
  {
    if ( v28 )
    {
      sub_12B753(dword_193164, 1);
      v13 = 156;
      v14 = dword_193164;
    }
    else
    {
      sub_12B753(dword_19316C, 1);
      v13 = 10;
      v14 = dword_19316C;
    }
    sub_12A478(v13, 11, v14);
  }
  if ( byte_199F1F == 1 )
  {
    sub_12B753(dword_193164, 0);
    sub_12A478(160, 10, dword_193164);
    v15 = 1;
    v16 = dword_19316C;
  }
  else
  {
    sub_12B753(dword_193164, 1);
    sub_12A478(160, 10, dword_193164);
    v16 = dword_19316C;
    v15 = 0;
  }
  sub_12B753(v16, v15);
  sub_12A478(7, 10, dword_19316C);
  if ( !((uint8_t)++byte_19C546 % 25) )
  {
    byte_19C546 = 0;
    byte_19C547 = -byte_19C547;
  }
  if ( !((uint8_t)byte_19C546 % 5) )
    byte_19C548 += byte_19C547;
  word_19995E = (word_19995E + 1) % 8;
  JUMPOUT(0x92E66);
}
// 93A19: control flows out of bounds to 92E66
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 1930E8: using guessed type int dword_1930E8;
// 1930FC: using guessed type int dword_1930FC;
// 193100: using guessed type int dword_193100;
// 193104: using guessed type int dword_193104;
// 19310C: using guessed type int dword_19310C;
// 193110: using guessed type int dword_193110;
// 193164: using guessed type int dword_193164;
// 19316C: using guessed type int dword_19316C;
// 193188: using guessed type int dword_193188;
// 1975C4: using guessed type int dword_1975C4;
// 19990E: using guessed type int16_t word_19990E;
// 19991C: using guessed type int16_t word_19991C;
// 19994C: using guessed type int16_t word_19994C;
// 19995E: using guessed type int16_t word_19995E;
// 19999C: using guessed type int16_t word_19999C;
// 1999A6: using guessed type int16_t word_1999A6;
// 1999D8: using guessed type int16_t word_1999D8;
// 199F09: using guessed type char byte_199F09;
// 199F0F: using guessed type char byte_199F0F;
// 199F11: using guessed type char byte_199F11;
// 199F1F: using guessed type char byte_199F1F;
// 19C538: using guessed type int16_t word_19C538;
// 19C53A: using guessed type int16_t word_19C53A;
// 19C53E: using guessed type int16_t word_19C53E;
// 19C543: using guessed type char byte_19C543;
// 19C544: using guessed type char byte_19C544;
// 19C545: using guessed type char byte_19C545;
// 19C546: using guessed type char byte_19C546;
// 19C547: using guessed type char byte_19C547;
// 19C548: using guessed type char byte_19C548;


//----- (00093A1E) --------------------------------------------------------
void sub_93A1E()
{
  int16_t i; // cx
  int16_t *v1; // ebx
  int v2; // edi
  int v3; // esi
  int v4; // eax
  int v5; // ebx
  int v6; // [esp+0h] [ebp-Ch]
  _BOOL1 v7; // [esp+8h] [ebp-4h]

  v7 = byte_199F1F == 0;
  sub_124D7A();
  sub_128BE7();
  sub_12B65C();
  sub_128C32(0, 0, 639, 479, 0);
  for ( i = 0; i < word_1999A6; ++i )
  {
    v6 = *(int16_t *)(dword_193188 + 2 * i);
    if ( v6 > -1 )
    {
      v1 = *(int16_t **)(6 * i + dword_19C458);
      v2 = (75 - *v1) / 2 + 12;
      v3 = (90 - v1[1]) / 2 + 37 + 109 * i;
      v4 = dword_1930DC + 59 * v6;
      if ( *(char *)(v4 + 55) > 0 || *(_BYTE *)(v4 + 57) == 4 )
        v1 = *(int16_t **)(dword_19C458 + 6 * (i + 4));
      sub_12A478(v2, v3, (int)v1);
    }
  }
  sub_12A478(0, 0, dword_193168);
  if ( v7 )
    v5 = dword_193124;
  else
    v5 = dword_193154;
  sub_12A478(300, 12, v5);
  sub_124E36();
  byte_199F11 = 0;
  if ( word_19994C )
    word_19994C = 0;
  sub_124D41();
  JUMPOUT(0x94800);
}
// 93B60: control flows out of bounds to 94800
// 1930DC: using guessed type int dword_1930DC;
// 193124: using guessed type int dword_193124;
// 193154: using guessed type int dword_193154;
// 193168: using guessed type int dword_193168;
// 193188: using guessed type int dword_193188;
// 19994C: using guessed type int16_t word_19994C;
// 1999A6: using guessed type int16_t word_1999A6;
// 199F11: using guessed type char byte_199F11;
// 199F1F: using guessed type char byte_199F1F;
// 19C458: using guessed type int dword_19C458;


//----- (00093B65) --------------------------------------------------------
int sub_93B65()
{
  return sub_12A478(300, 12, dword_193154);
}
// 193154: using guessed type int dword_193154;


//----- (00093B7F) --------------------------------------------------------
void sub_93B7F()
{
  JUMPOUT(0x93B77);
}
// 93B91: control flows out of bounds to 93B77


