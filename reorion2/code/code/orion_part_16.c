#include "orion_common.h"

/* Adresni rozsah: 0xF53D7 - 0x102776  (200 funkci) */

//----- (000F53D7) --------------------------------------------------------
int __fastcall sub_F53D7( int a1)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  int v6; // ebx
  int16_t *v7; // eax
  int v8; // ebx
  int16_t v9; // cx

  LOBYTE(word_18FF78) = 0;
  dword_192680 = (int)&unk_1AACB4;
  memset(&unk_1AACB4, 0, 491);
  v2 = dword_192680;
  v3 = dword_192680;
  v4 = dword_193174;
  *(_DWORD *)dword_192680 = *(_DWORD *)aEvanAxelrad;
  strcpy((char *)(v3 + 4), " Axelrad");
  *(_WORD *)(v2 + 241) = a1;
  v5 = sub_127C27((int)aMultigmLbx, 0, v4);
  v6 = dword_193174;
  *(_DWORD *)(dword_192680 + 15) = v5;
  v7 = (int16_t *)sub_127C27((int)aMultigmLbx, a1, v6);
  v8 = dword_192680;
  *(_DWORD *)(dword_192680 + 47) = v7;
  v9 = v7[1];
  *(_WORD *)(v8 + 243) = (640 - *v7) / 2;
  *(_BYTE *)(v8 + 270) = 4;
  *(_BYTE *)(v8 + 480) = 1;
  *(_WORD *)(v8 + 268) = v9;
  *(_WORD *)(v8 + 245) = (480 - v9) / 2;
  JUMPOUT(0xF5204);
}
// F549B: control flows out of bounds to F5204
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 18FF78: using guessed type int16_t word_18FF78;
// 192680: using guessed type int dword_192680;
// 193174: using guessed type int dword_193174;


//----- (000F54A0) --------------------------------------------------------
int sub_F54A0()
{
  int result; // eax

  byte_1AAE9F = 0;
  sub_F53D7(31);
  result = dword_192680;
  *(_BYTE *)(dword_192680 + 271) = 1;
  return result;
}
// 192680: using guessed type int dword_192680;
// 1AAE9F: using guessed type char byte_1AAE9F;


//----- (000F54BE) --------------------------------------------------------
void sub_F54BE()
{
  byte_1AAE9F = 0;
  sub_F53D7(25);
}
// 1AAE9F: using guessed type char byte_1AAE9F;


//----- (000F54CF) --------------------------------------------------------
void sub_F54CF()
{
  JUMPOUT(0xF53D0);
}
// F54D4: control flows out of bounds to F53D0


//----- (000F54D9) --------------------------------------------------------
void sub_F54D9()
{
  _BYTE v0[4]; // [esp+0h] [ebp-4h] BYREF

  v0[0] = 0;
  byte_1AAE9F = 0;
  sub_11C2F0();
  sub_F53D7(26);
  *(_BYTE *)(dword_192680 + 271) = 0;
  sub_8F1C4((void (__fastcall *)(int, int))sub_F19C7, v0, 11);
}
// 192680: using guessed type int dword_192680;
// 1AAE9F: using guessed type char byte_1AAE9F;


//----- (000F551B) --------------------------------------------------------
void sub_F551B()
{
  sub_11C2F0();
  JUMPOUT(0xF53D0);
}
// F5525: control flows out of bounds to F53D0


//----- (000F552A) --------------------------------------------------------
int sub_F552A()
{
  int v0; // ebx
  _DWORD *v1; // edx
  int result; // eax

  sub_11C2F0();
  byte_1AAE9F = 1;
  sub_F53D7(15);
  v0 = dword_192ED4;
  *(_BYTE *)(dword_192680 + 270) = 4;
  v1 = sub_126AFD((int)aMultigmLbx, 16, v0);
  result = dword_192680;
  *(_DWORD *)(dword_192680 + 143) = v1;
  return result;
}
// 192680: using guessed type int dword_192680;
// 192ED4: using guessed type int dword_192ED4;
// 1AAE9F: using guessed type char byte_1AAE9F;


//----- (000F5573) --------------------------------------------------------
int sub_F5573()
{
  int result; // eax
  int16_t i; // dx

  result = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    if ( *(int16_t *)(dword_197F98 + 3753 * i + 43) != -1 )
      ++result;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000F55A4) --------------------------------------------------------
int __fastcall sub_F55A4(int a1, int a2, int a3, int a4)
{
  int v4; // edx
  int16_t v5; // bx
  int16_t v6; // ax
  int v7; // eax
  int v8; // eax

  v4 = sub_1171AB(a1, a2, a3, a4);
  if ( !*(_WORD *)(dword_192680 + 268) )
  {
    word_1844CA = 1;
    dword_1844C6 = 0;
    byte_1B071C[0] = 0;
    byte_1B3E18 = 1;
    v5 = *(_WORD *)(dword_192680 + 187);
    byte_1AAC54 = 0;
    HIWORD(dword_1844CE) = v5;
    *(_WORD *)(dword_192680 + 268) = 1;
  }
  if ( (_WORD)v4 == *(_WORD *)(dword_192680 + 187) || (_WORD)v4 == *(_WORD *)(dword_192680 + 189) )
  {
    if ( byte_1AAC54 )
    {
      sub_DD3B8(&byte_1AAC54);
      dword_1844C6 = 0;
      byte_1B071C[0] = 0;
      byte_1AAC54 = 0;
    }
    byte_1B3E18 = 1;
    v6 = *(_WORD *)(dword_192680 + 187);
    word_1844CA = 1;
    HIWORD(dword_1844CE) = v6;
  }
  v7 = sub_124D41();
  sub_F1075(v7, v4);
  return sub_1077D(v8);
}
// F5679: variable 'v8' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 1844C6: using guessed type int dword_1844C6;
// 1844CA: using guessed type int16_t word_1844CA;
// 1844CE: using guessed type int dword_1844CE;
// 192680: using guessed type int dword_192680;
// 1AAC54: using guessed type char byte_1AAC54;
// 1B3E18: using guessed type char byte_1B3E18;


//----- (000F5691) --------------------------------------------------------
int sub_F5691()
{
  int result; // eax

  switch ( byte_199BF2 )
  {
    case 2:
      result = dword_192680;
      *(_WORD *)(dword_192680 + 247) = 0;
      *(_WORD *)(result + 249) = 1;
      byte_199F3A = 3;
      *(_WORD *)(result + 251) = 0;
      byte_1AAF58 = 1;
      goto LABEL_6;
    case 3:
      result = dword_192680;
      *(_WORD *)(dword_192680 + 247) = 0;
      *(_WORD *)(result + 249) = 0;
      byte_199F3A = 3;
      *(_WORD *)(result + 251) = 1;
      byte_1AAF58 = 2;
      goto LABEL_6;
    case 4:
      result = dword_192680;
      *(_WORD *)(dword_192680 + 247) = 0;
      *(_WORD *)(result + 249) = 0;
      *(_WORD *)(result + 251) = 0;
      byte_199F3A = 1;
      *(_WORD *)(result + 253) = 1;
      return result;
    default:
      result = dword_192680;
      *(_WORD *)(dword_192680 + 247) = 1;
      *(_WORD *)(result + 249) = 0;
      byte_199F3A = 2;
      *(_WORD *)(result + 251) = 0;
      byte_1AAF58 = 0;
LABEL_6:
      *(_WORD *)(result + 253) = 0;
      return result;
  }
}
// 192680: using guessed type int dword_192680;
// 199BF2: using guessed type char byte_199BF2;
// 199F3A: using guessed type char byte_199F3A;
// 1AAF58: using guessed type char byte_1AAF58;


//----- (000F5777) --------------------------------------------------------
void __usercall sub_F5777(int16_t *a1)
{
  int v1; // eax
  int v2; // ebx
  void *v3; // eax
  int16_t v4; // ax
  char v5; // cl
  int16_t v6; // bx
  char v7; // ch
  char *v8; // edx
  char *v9; // eax
  int16_t v10; // [esp-4h] [ebp-148h]
  char v11[200]; // [esp+0h] [ebp-144h] BYREF
  _BYTE v12[120]; // [esp+C8h] [ebp-7Ch] BYREF
  int v13; // [esp+140h] [ebp-4h]

  if ( sub_139659() >= 10 )
    v1 = 10;
  else
    v1 = sub_139659();
  v13 = v1;
  do
  {
    sub_124D7A();
    sub_128C32(0, 0, 639, 479, 0);
    v2 = *(_DWORD *)(dword_192680 + 15);
    sub_12A478(0, 0, v2);
    v3 = sub_124E36();
    sub_1077D((int)v3, 0, v2, a1);
    sub_1191CA((int)nullsub_15, 1);
    strcpy(v11, sub_7A990(0xFEu));
    a1 = (int16_t *)v11;
    v10 = sub_923C4();
    v4 = sub_923BE();
    sub_91BB4(&byte_199BF3, 8, 0, v11, v4, v10);
    v5 = 0;
    v6 = 0;
    v7 = 1;
    while ( v6 < (int16_t)v13 && !v5 )
    {
      v8 = sub_13968A(v6);
      if ( !strcmp(&byte_199BF3, v8) )
      {
        v9 = sub_7A990(0xFFu);
        v5 = 1;
        sprintf(v12, v9, &byte_199BF3);
        v7 = 0;
        sub_77433(v12);
      }
      ++v6;
    }
  }
  while ( !v7 );
  sub_12030();
}
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// FE8D4: using guessed type int __fastcall nullsub_15(_DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 192680: using guessed type int dword_192680;
// 199BF3: using guessed type char byte_199BF3;


//----- (000F5883) --------------------------------------------------------
unsigned int __fastcall sub_F5883(char *a1)
{
  dword_1AAEA4 = (int)a1;
  dword_1AAEAC = (int)&a1[strlen(a1) + 1];
  dword_1AAEA8 = strlen((char *)dword_1AAEAC) + 1 + dword_1AAEAC;
  dword_1AAEB8 = strlen((char *)dword_1AAEA8) + 1 + dword_1AAEA8;
  dword_1AAEC0 = strlen((char *)dword_1AAEB8) + 1 + dword_1AAEB8;
  dword_1AAEB4 = strlen((char *)dword_1AAEC0) + 1 + dword_1AAEC0;
  dword_1AAEB0 = strlen((char *)dword_1AAEB4) + 1 + dword_1AAEB4;
  dword_1AAEBC = strlen((char *)dword_1AAEB0) + 1 + dword_1AAEB0;
  return dword_1AAEBC + strlen((char *)dword_1AAEBC) + 1;
}
// 1AAEA4: using guessed type int dword_1AAEA4;
// 1AAEA8: using guessed type int dword_1AAEA8;
// 1AAEAC: using guessed type int dword_1AAEAC;
// 1AAEB0: using guessed type int dword_1AAEB0;
// 1AAEB4: using guessed type int dword_1AAEB4;
// 1AAEB8: using guessed type int dword_1AAEB8;
// 1AAEBC: using guessed type int dword_1AAEBC;
// 1AAEC0: using guessed type int dword_1AAEC0;


//----- (000F5A9F) --------------------------------------------------------
void __fastcall sub_F5A9F(int a1, int a2, unsigned int a3, unsigned int a4, char *a5)
{
  int v7; // ecx
  int *v8; // edi
  _BOOL1 v9; // zf
  int v10; // esi
  char *v11; // ecx
  int v12; // esi
  int i; // eax
  unsigned int v14; // ecx
  int v15; // ebx
  int v16; // ecx
  int v17; // esi
  int v18; // edi
  int v19; // eax
  int v20; // edx
  int v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // edi
  int v28; // esi
  char *v29; // ecx
  char v30; // bl
  int v31; // edx
  int v32; // eax
  char v33; // cl
  int v34; // esi
  int v35; // ecx
  char *v36; // eax
  char v37; // bl
  char v38; // al
  char v39; // al
  char v40; // al
  int v41; // edx
  int v42; // esi
  char *v43; // ecx
  int j; // edi
  int v45; // edx
  char v46; // al
  int v47; // edx
  char v48; // al
  int v49; // eax
  int16_t v50; // [esp+0h] [ebp-52h]
  int v51; // [esp+4h] [ebp-4Eh]
  char v52[100]; // [esp+8h] [ebp-4Ah] BYREF
  char v53[100]; // [esp+6Ch] [ebp+1Ah] BYREF
  _BYTE v54[52]; // [esp+D0h] [ebp+7Eh] BYREF
  _BYTE v55[52]; // [esp+104h] [ebp+B2h] BYREF

  if ( a3 <= 0x64u )
  {
    v7 = 68;
    v8 = dword_F594C;
    do
    {
      if ( !v7 )
        break;
      v9 = *(_BYTE *)v8 == (uint8_t)a3;
      v8 = (int *)((char *)v8 + 1);
      --v7;
    }
    while ( !v9 );
    v10 = 3753 * v51;
    switch ( v7 )
    {
      case 0:
        return;
      case 1:
        word_199998 = (uint8_t)a5[40];
        byte_199BDE = a5[38];
        byte_199CB0 = a5[39];
        byte_199CB1 = a5[40];
        byte_199CB2 = a5[41];
        byte_199CB3 = a5[42];
        byte_199CB4 = a5[43];
        byte_199CB5 = a5[44];
        byte_199CAF = a5[45];
        sprintf(v55, "%s", aMay222006);
        if ( strcmp(a5 + 46, v55) )
        {
          sprintf(v53, (char *)dword_1AAEA8, a5 + 46, v55);
          sub_126487(v53, (int)v55);
        }
        word_19999C = -1;
        v11 = a5;
        word_1AAF68 = *(_WORD *)a5;
        v12 = 0;
        byte_1AAF5D = a5[4];
        for ( i = 0; i < word_199998; ++i )
        {
          *(_WORD *)(dword_197F98 + v12 + 43) = *((_WORD *)v11 + 3);
          if ( word_1AAF5E == *(_DWORD *)(v11 + 6) )
            word_19999C = i;
          v12 += 3753;
          v11 += 4;
        }
        if ( word_19999C == -1 )
          byte_1AB03F = 45;
        else
          byte_1AB03F = 6;
        return;
      case 2:
        v14 = a4;
        v15 = 3753 * v51;
        byte_1AAF60[v51] = 1;
        qmemcpy((void *)(dword_197F98 + 3753 * v51), a5, v14);
        v16 = word_199998;
        v17 = 3753 * word_199998;
        while ( v16 > 0 )
        {
          --v16;
          v17 -= 3753;
          if ( v16 != v51 && *(_BYTE *)(dword_197F98 + v17 + 38) == *(_BYTE *)(v15 + dword_197F98 + 38) )
            *(_BYTE *)(v15 + dword_197F98 + 38) = 8;
        }
        return;
      case 3:
        qmemcpy(&word_1AAF70, a5, sizeof(word_1AAF70));
        word_1AAF6E = 0;
        dword_1AAF6A = 0;
        sub_1112EC(dword_192ED4, (int)&loc_E1000);
        dword_1AAF72 = (int)sub_110D3C(dword_192ED4, (int)&loc_E1000);
        word_1AB09C = v50;
        sub_FC6A5();
        return;
      case 4:
      case 49:
        v18 = 30720 * word_1AAF6E;
        v19 = dword_1AAF72;
        goto LABEL_25;
      case 5:
        byte_1AAF76[v51] = *a5;
        byte_1AAF7E[v51] = a5[4];
        if ( byte_1AAF76[word_19999C] == -1 || byte_1AAF76[v51] < byte_1AAF76[word_19999C] )
          byte_1AAF76[word_19999C] = byte_1AAF76[v51];
        return;
      case 6:
        v20 = *a5;
        byte_1AAF96[12 * v51] = v20;
        byte_1AAF8B[12 * v51] = 38;
        sub_FA1A3(v20);
        if ( v21 == -1 )
        {
          byte_1AB050 |= 1 << v51;
        }
        else
        {
          byte_1AB051 |= 1 << v51;
          byte_1AAF96[12 * v51] = v20;
          v22 = 12 * v51;
LABEL_32:
          byte_1AAF8B[v22] = 40;
        }
        return;
      case 7:
        if ( byte_1AB03F == 37 || byte_1AB03F == 38 )
          byte_1AB03F = 40;
        return;
      case 8:
        if ( byte_1AB03F == 37 )
          byte_1AB03F = 38;
        return;
      case 9:
        if ( byte_1AAF8B[12 * v51] != 38 )
        {
          v23 = byte_1AAF96[12 * v51];
          byte_1AB051 &= ~(1 << v51);
          sub_FA1A3(v23);
          if ( v24 != -1 )
          {
            byte_1AB051 |= 1 << v24;
            byte_1AAF8B[12 * v24] = 40;
          }
        }
        v25 = 12 * v51;
        byte_1AAF96[v25] = -1;
        byte_1AAF8B[v25] = 4;
        byte_1AB052 |= 1 << v51;
        return;
      case 10:
        byte_1AB04A = -1;
        byte_1AB03F = 4;
        return;
      case 11:
        v26 = byte_1AAF96[12 * v51];
        qmemcpy((void *)(3753 * v26 + dword_197F98), a5 + 4, 0xEA9u);
        qmemcpy((void *)(dword_197F98 + 3753 * v51), a5 + 3833, 0xEA9u);
        v27 = word_19999A;
        v28 = 113 * word_19999A;
        v29 = &a5[word_19999A];
        while ( v28 > 0 )
        {
          v28 -= 113;
          v30 = v29[3756];
          --v29;
          --v27;
          *(_BYTE *)(v28 + dword_19306C + v26 + 103) = v30;
        }
        v31 = 12 * v51;
        byte_1AAF96[v31] = -1;
        byte_1AAF8B[v31] = 4;
        byte_1AB055[v26] = -1;
        byte_1AB05D[v26] = v51;
        sub_FA1A3(v26);
        v33 = v32;
        if ( v32 == -1 )
          return;
        v22 = 12 * v32;
        byte_1AB051 |= 1 << v33;
        goto LABEL_32;
      case 12:
        byte_1AB072[v51] = 1;
        return;
      case 13:
        byte_1AB03F = 13;
        return;
      case 14:
        qmemcpy(&word_1AAF70, a5, sizeof(word_1AAF70));
        goto LABEL_51;
      case 15:
        qmemcpy((void *)(dword_1AAF72 + 30720 * word_1AAF6E++), a5, a4);
        dword_1AAF6A += a4;
        if ( word_1AAF6E == word_1AAF70 )
        {
          if ( (uint8_t)++byte_1AAF89 == word_199998 )
            byte_1AB03F = 11;
          else
            byte_1AB03F = 9;
        }
        return;
      case 16:
        memset(byte_1AAF8B, 0, 180);
        goto LABEL_57;
      case 17:
        byte_1AB03F = 16;
        sub_F8C8E(a5);
        return;
      case 18:
        qmemcpy(&byte_1AAF8B[12 * v51 + 2], a5, 6u);
        byte_1AAF8B[12 * v51] = 17;
        return;
      case 19:
        sub_F93E3(a5);
        return;
      case 20:
        goto LABEL_61;
      case 21:
        if ( byte_199CB4 )
        {
          byte_1AB03F = 24;
        }
        else if ( word_1AB045 < 8 && *(_BYTE *)(dword_197F98 + 3753 * word_1AB045 + 40) == 100 )
        {
LABEL_61:
          byte_1AB03F = 20;
        }
        else
        {
          byte_1AB03F = 22;
        }
        return;
      case 22:
        sub_F9C58(a5);
        return;
      case 23:
        qmemcpy((void *)dword_1AB04C, a5, 0x6CEu);
        byte_1AB03F = 25;
        return;
      case 24:
        byte_1AAF8B[12 * v51] = 14;
        byte_1AAF94[12 * v51] = -1;
        byte_1AB04B = 0;
        return;
      case 25:
        qmemcpy((void *)dword_1AB04C, a5, 0x6CEu);
        byte_1AB03F = 26;
        return;
      case 26:
LABEL_57:
        byte_1AB03F = 14;
        return;
      case 27:
        byte_1AB03F = 7;
        return;
      case 28:
        if ( byte_1AAF7E[word_19999C] )
          return;
        qmemcpy((void *)(dword_197F98 + 3753 * v51), a5, 0xEA9u);
        v34 = word_19999A;
        v35 = 113 * word_19999A;
        v36 = &a5[word_19999A];
        while ( v35 > 0 )
        {
          v35 -= 113;
          v37 = v36[3752];
          --v36;
          --v34;
          *(_BYTE *)(v51 + v35 + dword_19306C + 103) = v37;
        }
        if ( byte_1AB03F == 41 && byte_1AB04A == v51 )
        {
          byte_1AB0CB = v51;
          v38 = ~(1 << v51);
          byte_1AB054 &= v38;
          byte_1AB069 &= v38;
          byte_1AB03F = 46;
          byte_1AB066 = byte_1AB04A > word_19999C;
          return;
        }
        v39 = 1 << v51;
        if ( (((int)*(uint8_t *)(3753 * word_19999C + dword_197F98 + 3680) >> v51) & 1) != 0 )
          goto LABEL_80;
        goto LABEL_81;
      case 29:
        qmemcpy((void *)(dword_197F98 + 3753 * v51), a5, 0xEA9u);
        if ( byte_1AB03F == 41 && byte_1AB04A == v51 )
        {
          byte_1AB0CB = v51;
          byte_1AB054 &= ~(1 << v51);
          byte_1AB03F = 46;
          v40 = ~(1 << v51);
          byte_1AB066 = 1;
LABEL_85:
          byte_1AB069 &= v40;
        }
        else
        {
          v39 = 1 << v51;
          if ( (((int)*(uint8_t *)(dword_197F98 + 3753 * word_19999C + 3680) >> v51) & 1) != 0 )
          {
LABEL_80:
            byte_1AB053 |= v39;
          }
          else
          {
LABEL_81:
            byte_1AB054 |= v39;
            byte_1AB069 |= v39;
          }
        }
        break;
      case 30:
        byte_1AB03F = 42;
        return;
      case 31:
        byte_1AB054 &= ~(1 << v51);
        byte_1AB069 &= ~(1 << v51);
        if ( byte_1AB03F == 43 && byte_1AB04A == v51 )
        {
          byte_1AB03F = 4;
          byte_1AB04A = -1;
          byte_1AB0CC = 0;
        }
        if ( byte_1AB03F == 46 && byte_1AB04A == v51 )
        {
          if ( byte_1AB0CC )
            byte_1AB03F = 4;
          else
            byte_1AB03F = 41;
          byte_1AB0CC = 0;
          byte_1AB0CB = -1;
        }
        return;
      case 32:
        byte_1AB03F = 44;
        word_1AAF68 = v50;
        qmemcpy(&word_199998, a5, sizeof(word_199998));
        qmemcpy((void *)dword_197F98, a5 + 2, 3753 * word_199998);
        return;
      case 33:
        *(_WORD *)(dword_197F98 + 3753 * *(_DWORD *)a5 + 43) = v50;
        dword_1AAF59 = -1;
        return;
      case 34:
        v41 = dword_197F98;
        qmemcpy((void *)(dword_197F98 + 3753 * *(_DWORD *)a5), a5 + 4, 0xEA9u);
        qmemcpy((void *)(v41 + 3753 * *(_DWORD *)(a5 + 3829)), a5 + 3833, 0xEA9u);
        v42 = word_19999A;
        v43 = &a5[word_19999A];
        for ( j = 113 * word_19999A; j > 0; v43[3757] = *(_BYTE *)(*(_DWORD *)a5 + j + dword_19306C + 103) )
        {
          j -= 113;
          --v43;
          --v42;
        }
        return;
      case 35:
        v45 = 17 * *(int16_t *)(dword_192B18 + 361 * *(_DWORD *)a5 + 2);
        word_1AB043 = *(_WORD *)(dword_192B18 + 361 * *(_DWORD *)a5 + 2);
        v46 = *(_BYTE *)(v45 + dword_1930D4 + 2);
        byte_1AB03F = 28;
        byte_1AB040 = v46;
        return;
      case 36:
        byte_1AAF8B[12 * v51] = 29;
        return;
      case 37:
        v47 = *(_DWORD *)a5;
        byte_1AAF8B[12 * v51] = 30;
        byte_1AB0CD = v47;
        return;
      case 38:
        if ( byte_1AB03F == 41 && byte_1AB04A == v51 )
          byte_1AB067 = 1;
        return;
      case 39:
        if ( !dword_1AA250 )
          return;
        v48 = v51;
        goto LABEL_111;
      case 40:
        sprintf(v54, "%s", aMay222006);
        if ( strcmp(a5 + 46, v54) )
        {
          sprintf(v52, (char *)dword_1AAEA8, a5 + 46, v54);
          sub_126487(v52, (int)v54);
        }
        do
        {
          --a5[40];
          *(_WORD *)(3753 * (uint8_t)a5[40] + dword_197F98 + 43) = *(_WORD *)&a5[4 * (uint8_t)a5[40] + 6];
        }
        while ( a5[40] );
        return;
      case 41:
        byte_19B814[(uint8_t)*a5] = 1;
        *(_BYTE *)(3753 * (uint8_t)a5[1] + dword_197F98 + 38) = *a5;
        return;
      case 42:
        if ( !byte_19B814[(uint8_t)*a5] )
        {
          byte_19B814[(uint8_t)*a5] = 1;
          *(_BYTE *)(dword_197F98 + 3753 * v51 + 38) = *a5;
          byte_1AB08B[v51] = 1;
        }
        return;
      case 43:
        if ( !dword_1AA250 )
          return;
        v48 = 8;
LABEL_111:
        sub_DD351(v48, a5);
        return;
      case 44:
        qmemcpy(&word_1AAF70, a5, sizeof(word_1AAF70));
        byte_1AB03F = 15;
        goto LABEL_51;
      case 45:
      case 51:
        v19 = 30720 * word_1AAF6E;
        v18 = dword_1AAF72;
LABEL_25:
        qmemcpy((void *)(v19 + v18), a5, a4);
        ++word_1AAF6E;
        dword_1AAF6A += a4;
        return;
      case 46:
        byte_1AAF8B[12 * v51] = 31;
        return;
      case 47:
        byte_1AB03F = 32;
        return;
      case 48:
        qmemcpy(&word_1AAF70, a5, sizeof(word_1AAF70));
        byte_1AB03F = 34;
        goto LABEL_51;
      case 50:
        qmemcpy(&word_1AAF70, a5, sizeof(word_1AAF70));
        byte_1AB03F = 18;
LABEL_51:
        word_1AAF6E = 0;
        dword_1AAF6A = 0;
        sub_1112EC(dword_192ED4, (int)&loc_E1000);
        dword_1AAF72 = (int)sub_110D3C(dword_192ED4, (int)&loc_E1000);
        return;
      case 52:
        byte_1AB094[v51] = 1;
        return;
      case 53:
      case 54:
        sub_FA8A2(v51, a5);
        return;
      case 55:
        if ( word_1AAF68 == word_1AAF5E )
          sub_126487((char *)dword_1AAEB8, (int)a5);
        byte_19B848[(uint8_t)*a5] = 1;
        *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)a5[1] + 37) = *a5;
        return;
      case 56:
        v49 = (uint8_t)*a5;
        if ( !byte_19B848[v49] )
        {
          byte_19B848[v49] = 1;
          *(_BYTE *)(v10 + dword_197F98 + 37) = *a5;
          byte_1AB0A7[v51] = 1;
        }
        return;
      case 57:
        *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 36) = 1;
        return;
      case 58:
        sub_2332C(*(int16_t *)a5, *((_WORD *)a5 + 2), *((_WORD *)a5 + 4));
        return;
      case 59:
        byte_19B848[(uint8_t)*a5] = 0;
        return;
      case 60:
        byte_19B848[(uint8_t)*a5] = 0;
        byte_1AB0AF[v51] = 1;
        return;
      case 61:
        byte_1AB0BF = 0;
        return;
      case 62:
        byte_1AB0C0 = 1;
        return;
      case 63:
        byte_1AB0C0 = 2;
        return;
      case 64:
        if ( !*(_DWORD *)a5 )
          byte_1AB0C1 = 0;
        return;
      case 65:
        sub_4E3B5(
          *(int16_t *)a5,
          *((_WORD *)a5 + 1),
          *((_WORD *)a5 + 2),
          *((_WORD *)a5 + 3),
          *((_WORD *)a5 + 4),
          *((_WORD *)a5 + 5));
        return;
      case 66:
        qmemcpy((void *)(v10 + dword_197F98), a5, 0xEA9u);
        if ( byte_1AB03F != 46 || byte_1AB04A != v51 )
          return;
        v40 = ~(1 << v51);
        byte_1AB03F = 43;
        byte_1AB054 &= v40;
        goto LABEL_85;
      case 67:
        sub_51078(v51, *(_WORD *)a5);
        return;
    }
  }
}
// F5ACD: variable 'v51' is possibly undefined
// F5CA0: variable 'v50' is possibly undefined
// F5D5F: variable 'v21' is possibly undefined
// F5E06: variable 'v24' is possibly undefined
// F5EE5: variable 'v32' is possibly undefined
// F594C: using guessed type int dword_F594C[16];
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 199BDE: using guessed type char byte_199BDE;
// 199CAF: using guessed type char byte_199CAF;
// 199CB0: using guessed type char byte_199CB0;
// 199CB1: using guessed type char byte_199CB1;
// 199CB2: using guessed type char byte_199CB2;
// 199CB3: using guessed type char byte_199CB3;
// 199CB4: using guessed type char byte_199CB4;
// 199CB5: using guessed type char byte_199CB5;
// 1AA250: using guessed type int dword_1AA250;
// 1AAEA8: using guessed type int dword_1AAEA8;
// 1AAEB8: using guessed type int dword_1AAEB8;
// 1AAF59: using guessed type int dword_1AAF59;
// 1AAF5D: using guessed type char byte_1AAF5D;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF68: using guessed type int16_t word_1AAF68;
// 1AAF6A: using guessed type int dword_1AAF6A;
// 1AAF6E: using guessed type int16_t word_1AAF6E;
// 1AAF70: using guessed type int16_t word_1AAF70;
// 1AAF72: using guessed type int dword_1AAF72;
// 1AAF89: using guessed type char byte_1AAF89;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB040: using guessed type char byte_1AB040;
// 1AB043: using guessed type int16_t word_1AB043;
// 1AB045: using guessed type int16_t word_1AB045;
// 1AB04A: using guessed type char byte_1AB04A;
// 1AB04B: using guessed type char byte_1AB04B;
// 1AB04C: using guessed type int dword_1AB04C;
// 1AB050: using guessed type char byte_1AB050;
// 1AB051: using guessed type char byte_1AB051;
// 1AB052: using guessed type char byte_1AB052;
// 1AB053: using guessed type char byte_1AB053;
// 1AB054: using guessed type char byte_1AB054;
// 1AB066: using guessed type char byte_1AB066;
// 1AB067: using guessed type char byte_1AB067;
// 1AB069: using guessed type char byte_1AB069;
// 1AB09C: using guessed type int16_t word_1AB09C;
// 1AB0BF: using guessed type char byte_1AB0BF;
// 1AB0C0: using guessed type char byte_1AB0C0;
// 1AB0C1: using guessed type char byte_1AB0C1;
// 1AB0CB: using guessed type char byte_1AB0CB;
// 1AB0CC: using guessed type char byte_1AB0CC;
// 1AB0CD: using guessed type char byte_1AB0CD;


//----- (000F67C1) --------------------------------------------------------
void __fastcall sub_F67C1( unsigned int a1, unsigned int a2, unsigned int a3, char *a4)
{
  int v4; // esi
  int v5; // eax

  v4 = a1;
  v5 = sub_FA16C(a1);
  byte_1AB0DF = 1;
  if ( a2 < 0x7D0u )
  {
    if ( a2 < 0x3E8u )
      sub_F5A9F(v5, v4, a2, a3, a4);
    else
      sub_3FCD8(v4, a2, a3, a4);
  }
  else
  {
    sub_1F230(v4, a2, a3, (int)a4);
  }
  byte_1AB0DF = 0;
}
// 1AB0DF: using guessed type char byte_1AB0DF;


//----- (000F6816) --------------------------------------------------------
int __fastcall sub_F6816(int a1, int a2, int a3, unsigned int a4)
{
  char *v4; // edi
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  unsigned int v9; // esi
  int v10; // ecx
  int v11; // eax
  unsigned int v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v18; // [esp+4h] [ebp-14h]
  int v19; // [esp+Ch] [ebp-Ch]
  uint16_t v20; // [esp+10h] [ebp-8h]
  char v21; // [esp+14h] [ebp-4h] BYREF

  v18 = a1;
  v4 = (char *)a3;
  v20 = a4;
  v5 = 1;
  byte_183608 = 1;
  if ( !a4 )
  {
    v20 = 1;
    v4 = &v21;
  }
  sub_1131F0(a1, 1);
  if ( !byte_1AB0DF )
    sub_1390BB(v6, 1, a3);
  v7 = word_1AAF5E;
  if ( word_1AAF5E == v18 )
  {
    sub_F67C1(v18, a2, v20, v4);
    v5 = 1;
  }
  else
  {
    LOBYTE(a3) = 0;
    do
    {
      sub_1131F0(v7, 1);
      if ( !byte_1AB0DF )
        sub_1390BB(v8, 1, a3);
      v7 = sub_139127();
    }
    while ( v7 );
    if ( v18 == 32766 )
    {
      v19 = -1;
      v9 = 3753 * word_199998 + dword_197F98;
      while ( v9 > dword_197F98 )
      {
        v10 = *(int16_t *)(v9 - 3710);
        v9 -= 3753;
        if ( v10 != -1 && *(_WORD *)(v9 + 43) != word_1AAF5E )
        {
          ++v7;
          v19 = v10;
        }
      }
      if ( v7 )
      {
        if ( v7 == 1 )
        {
          v7 = v19;
          v18 = v19;
        }
      }
      else
      {
        LOBYTE(a3) = 1;
      }
    }
    if ( !(_BYTE)a3 )
    {
      if ( byte_1AAF58 || v18 != 32766 )
      {
        sub_1131F0(v7, 1);
        if ( !byte_1AB0DF )
          sub_1390BB(v14, 1, a3);
        v5 = sub_139153(v18, a2, (int)v4, v20);
        sub_1131F0(v5, v5);
        if ( !byte_1AB0DF )
          sub_1390BB(v15, v5, (int)v4);
      }
      else
      {
        v11 = 3753 * word_199998;
        v12 = v11 + dword_197F98;
        while ( v12 > dword_197F98 )
        {
          v12 -= 3753;
          if ( *(int16_t *)(v12 + 43) > 0 )
          {
            LOWORD(v11) = *(_WORD *)(v12 + 43);
            if ( (_WORD)v11 != word_1AAF5E )
            {
              sub_1131F0(v11, v5);
              if ( !byte_1AB0DF )
                sub_1390BB(v13, v5, a3);
              a3 = (int)v4;
              v5 = sub_139153(*(int16_t *)(v12 + 43), a2, (int)v4, v20);
              sub_1131F0(v5, v5);
              if ( !byte_1AB0DF )
                sub_1390BB(v11, v5, (int)v4);
              if ( !v5 )
                sub_126487((char *)dword_1AAEC0, 0);
            }
          }
        }
      }
    }
    if ( !v5 )
      sub_126487((char *)dword_1AAEC0, 0);
  }
  byte_183608 = 0;
  return v5;
}
// F684C: variable 'v6' is possibly undefined
// F688A: variable 'v8' is possibly undefined
// F6956: variable 'v11' is possibly undefined
// F6964: variable 'v13' is possibly undefined
// F69B7: variable 'v14' is possibly undefined
// F69DE: variable 'v15' is possibly undefined
// 183608: using guessed type char byte_183608;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 1AAEC0: using guessed type int dword_1AAEC0;
// 1AAF58: using guessed type char byte_1AAF58;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AB0DF: using guessed type char byte_1AB0DF;


//----- (000F69FE) --------------------------------------------------------
void __usercall sub_F69FE(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  void *v11; // esi
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // [esp+0h] [ebp-1DDCh] BYREF
  _BYTE v25[3825]; // [esp+4h] [ebp-1DD8h] BYREF
  int v26; // [esp+EF5h] [ebp-EE7h]
  _BYTE v27[3753]; // [esp+EF9h] [ebp-EE3h] BYREF
  int16_t v28; // [esp+1DA2h] [ebp-3Ah] BYREF
  int v29; // [esp+1DA4h] [ebp-38h] BYREF
  char v30; // [esp+1DA8h] [ebp-34h]
  int v31; // [esp+1DACh] [ebp-30h]
  int v32; // [esp+1DB0h] [ebp-2Ch]
  int v33; // [esp+1DB4h] [ebp-28h]
  int v34; // [esp+1DB8h] [ebp-24h]
  _BYTE v35[4]; // [esp+1DBCh] [ebp-20h] BYREF
  _BYTE v36[4]; // [esp+1DC0h] [ebp-1Ch] BYREF
  char v37; // [esp+1DC4h] [ebp-18h]
  char v38[4]; // [esp+1DC8h] [ebp-14h] BYREF
  char v39[4]; // [esp+1DCCh] [ebp-10h] BYREF
  uint8_t v40; // [esp+1DD0h] [ebp-Ch]
  char v41[4]; // [esp+1DD4h] [ebp-8h] BYREF
  char v42[4]; // [esp+1DD8h] [ebp-4h] BYREF

  if ( (byte_199F3A == 2 || byte_199F3A == 3) && !byte_183609 && !byte_1AB0DF )
  {
    byte_183609 = 1;
    sub_1390BB(a1, a2, a3);
    if ( byte_1AB09E )
    {
      if ( word_199998 )
      {
        v4 = (uint8_t)byte_18360A / word_199998;
        v5 = (uint8_t)byte_18360A % word_199998;
      }
      else
      {
        v5 = -1;
      }
      sub_FE8BE(v4);
      ++byte_18360A;
      v31 = v5;
      if ( v5 != -1 && !sub_139127() )
      {
        v40 = 0;
        if ( byte_1AB03F == 4 || byte_1AB03F == 8 )
        {
          v6 = v31;
          if ( !byte_1AB09F[v31] )
          {
            v5 = 3753 * v31;
            byte_1AB09F[v31] = 1;
            v7 = *(int16_t *)(3753 * v6 + dword_197F98 + 43);
            if ( v7 != -1 )
            {
              v5 = 54;
              v40 = 1;
              sub_F6816(v7, 54, 0, 0);
            }
          }
        }
        if ( !v40 && (((int)(uint8_t)byte_1AB050 >> v31) & 1) != 0 )
        {
          v38[0] = byte_1AAF96[12 * v31];
          byte_1AB050 &= ~(1 << v31);
          v8 = *(int16_t *)(dword_197F98 + 3753 * v31 + 43);
          v5 = 7;
          v40 = 1;
          sub_F6816(v8, 7, (int)v38, 1u);
        }
        v33 = word_199998;
        v37 = 1 << v31;
        v32 = 3753 * v31;
        v34 = 3753 * word_199998;
        while ( v33 > 0 )
        {
          v9 = (int)(uint8_t)byte_1AB055[--v33] >> v31;
          v34 -= 3753;
          if ( (v9 & 1) != 0 )
          {
            v24 = v33;
            v10 = (uint8_t)byte_1AB05D[v33];
            qmemcpy(v25, (void *)(dword_197F98 + v34), 0xEA9u);
            v26 = v10;
            v11 = (void *)(dword_197F98 + 3753 * v10);
            v12 = word_19999A;
            qmemcpy(v27, v11, sizeof(v27));
            a4 = &v28;
            v13 = 113 * word_19999A;
            while ( v12 > 0 )
            {
              v13 -= 113;
              v25[--v12 + 3753] = *(_BYTE *)(v33 + v13 + dword_19306C + 103);
            }
            if ( word_19999C != v31
              && (uint8_t)byte_1AB05D[v33] != v31
              && *(_BYTE *)(v32 + dword_197F98 + 40) == 100
              && !v40
              && byte_1AB094[v31] )
            {
              v14 = *(int16_t *)(v32 + dword_197F98 + 43);
              v40 = 1;
              sub_F6816(v14, 34, (int)&v24, 0x1DA2u);
            }
            v5 = v33;
            byte_1AB055[v33] &= ~v37;
          }
        }
        if ( !v40 && (((int)(uint8_t)byte_1AB051 >> v31) & 1) != 0 )
        {
          v42[0] = byte_1AAF96[12 * v31];
          if ( (((int)(uint8_t)byte_1AB055[v42[0]] >> v31) & 1) == 0 )
          {
            byte_1AB051 &= ~(1 << v31);
            v15 = *(int16_t *)(dword_197F98 + 3753 * v31 + 43);
            v5 = 6;
            v40 = 1;
            sub_F6816(v15, 6, (int)v42, 1u);
          }
        }
        if ( !v40 && (((int)(uint8_t)byte_1AB052 >> v31) & 1) != 0 )
        {
          v39[0] = byte_1AAF96[12 * v31];
          byte_1AB052 &= ~(1 << v31);
          v16 = *(int16_t *)(dword_197F98 + 3753 * v31 + 43);
          v5 = 9;
          v40 = 1;
          sub_F6816(v16, 9, (int)v39, 1u);
        }
        if ( !v40 && (((int)(uint8_t)byte_1AB053 >> v31) & 1) != 0 )
        {
          byte_1AB053 &= ~(1 << v31);
          v17 = *(int16_t *)(3753 * v31 + dword_197F98 + 43);
          v5 = 29;
          v40 = 1;
          sub_F6816(v17, 29, 0, 0);
        }
        if ( !v40 )
        {
          v5 = word_19999C;
          if ( word_19999C != v31 )
          {
            v18 = dword_197F98 + 3753 * v31;
            if ( *(_BYTE *)(v18 + 40) == 100 && byte_1AB07A[v31] != byte_1AAF76[word_19999C] )
            {
              v29 = byte_1AAF76[word_19999C];
              v30 = byte_1AAF7E[word_19999C];
              byte_1AB07A[v31] = v29;
              v5 = 4;
              v19 = *(int16_t *)(v18 + 43);
              v40 = 1;
              sub_F6816(v19, 4, (int)&v29, 5u);
            }
          }
        }
        if ( !v40
          && word_1AAF86 == word_1AAF5E
          && (uint8_t)byte_1AB03F >= 0xEu
          && (uint8_t)byte_1AB03F < 0x23u )
        {
          sub_EAAA1(v40, v5, (int)a4);
        }
        if ( !v40 && byte_1AB08B[v31] )
        {
          v35[0] = *(_BYTE *)(dword_197F98 + 3753 * v31 + 38);
          v35[1] = v31;
          byte_1AB08B[v31] = 0;
          v40 = 1;
          sub_F6816(32766, 43, (int)v35, 2u);
        }
        if ( !v40 && byte_1AB0A7[v31] )
        {
          v36[0] = *(_BYTE *)(dword_197F98 + 3753 * v31 + 37);
          v36[1] = v31;
          byte_1AB0A7[v31] = 0;
          v40 = 1;
          sub_F6816(32766, 57, (int)v36, 2u);
        }
        if ( !v40 && byte_1AB0AF[v31] )
        {
          v41[0] = *(_BYTE *)(dword_197F98 + 3753 * v31 + 37);
          v20 = v31;
          byte_1AB0AF[v31] = 0;
          byte_1AB0B7[v20] = 1;
          v40 = 1;
          sub_F6816(32766, 61, (int)v41, 1u);
        }
        if ( !v40 )
        {
          v21 = v31;
          if ( byte_1AB0B7[v31] )
          {
            byte_1AB0B7[v31] = 0;
            v22 = *(int16_t *)(3753 * v21 + dword_197F98 + 43);
            v40 = 1;
            sub_F6816(v22, 63, 0, 0);
          }
        }
        if ( !v40 && byte_1AB0CB != -1 )
        {
          v23 = *(int16_t *)(3753 * byte_1AB04A + dword_197F98 + 43);
          byte_1AB0CB = -1;
          sub_F6816(v23, 68, dword_197F98 + 3753 * word_19999C, 0xEA9u);
        }
      }
    }
    byte_183609 = 0;
  }
  JUMPOUT(0xFA388);
}
// F6F8B: control flows out of bounds to FA388
// F6A72: variable 'v4' is possibly undefined
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 183609: using guessed type char byte_183609;
// 18360A: using guessed type char byte_18360A;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF86: using guessed type int16_t word_1AAF86;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB04A: using guessed type char byte_1AB04A;
// 1AB050: using guessed type char byte_1AB050;
// 1AB051: using guessed type char byte_1AB051;
// 1AB052: using guessed type char byte_1AB052;
// 1AB053: using guessed type char byte_1AB053;
// 1AB09E: using guessed type char byte_1AB09E;
// 1AB0CB: using guessed type char byte_1AB0CB;
// 1AB0DF: using guessed type char byte_1AB0DF;


//----- (000F6F90) --------------------------------------------------------
int __fastcall sub_F6F90(int a1, int a2, int a3)
{
  if ( *(_BYTE *)a1 )
  {
    if ( *(_BYTE *)a1 <= 1u )
      return fseek();
    if ( *(_BYTE *)a1 != 2 )
      return 0;
    if ( !a3 )
    {
      *(_DWORD *)(a1 + 9) = a2 + *(_DWORD *)(a1 + 5);
      return 0;
    }
    if ( a3 != 1 )
      return 0;
    *(_DWORD *)(a1 + 9) += a2;
  }
  return 0;
}


//----- (000F6FD9) --------------------------------------------------------
int __fastcall sub_F6FD9(int a1)
{
  int v1; // edx
  uint8_t *v3; // ebx

  v1 = 0;
  if ( *(_BYTE *)a1 )
  {
    if ( *(_BYTE *)a1 <= 1u )
      return fgetc(*(_DWORD *)(a1 + 1), 0);
    if ( *(_BYTE *)a1 != 2 )
      return 0;
    if ( *(_DWORD *)(a1 + 13) + *(_DWORD *)(a1 + 5) == *(_DWORD *)(a1 + 9) )
      return -1;
    v3 = *(uint8_t **)(a1 + 9);
    v1 = *v3;
    *(_DWORD *)(a1 + 9) = v3 + 1;
  }
  return v1;
}
// 13C992: using guessed type int __fastcall fgetc(_DWORD, _DWORD);


//----- (000F7023) --------------------------------------------------------
int __fastcall sub_F7023(void *a1, int a2, int a3, char *a4)
{
  uint8_t v5; // dl

  v5 = *a4;
  if ( !*a4 )
    return 0;
  if ( v5 <= 1u )
    return fread(a1, a2, a3, *(_DWORD *)(a4 + 1));
  if ( v5 != 2 )
    return 0;
  qmemcpy(a1, *(void **)(a4 + 9), a3 * a2);
  *(_DWORD *)(a4 + 9) += a3 * a2;
  if ( (unsigned int)(*(_DWORD *)(a4 + 13) + *(_DWORD *)(a4 + 5)) >= *(_DWORD *)(a4 + 9) )
    return a3;
  else
    return 0;
}
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (000F707D) --------------------------------------------------------
int __fastcall sub_F707D(void *a1, int a2, int a3, char *a4)
{
  uint8_t v5; // dl

  v5 = *a4;
  if ( !*a4 )
    return 0;
  if ( v5 <= 1u )
    return fwrite(a1, a2, a3, *(_DWORD *)(a4 + 1));
  if ( v5 != 2 )
    return 0;
  qmemcpy(*(void **)(a4 + 9), a1, a3 * a2);
  *(_DWORD *)(a4 + 9) += a3 * a2;
  if ( (unsigned int)(*(_DWORD *)(a4 + 13) + *(_DWORD *)(a4 + 5)) >= *(_DWORD *)(a4 + 9) )
    return a3;
  else
    return 0;
}
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (000F70EB) --------------------------------------------------------
_BYTE *__fastcall sub_F70EB(int a1, uint8_t *a2, int16_t *a3, char *a4, int a5)
{
  int16_t *v6; // edi
  int v7; // edx
  int v8; // esi
  int16_t *v9; // kr04_4
  int v10; // kr10_4
  char *v11; // eax
  int v12; // edx
  unsigned int v13; // ecx
  int v15; // [esp+0h] [ebp-2Ch]
  int v16; // [esp+8h] [ebp-24h]
  uint8_t *v17; // [esp+Ch] [ebp-20h]
  unsigned int v18; // [esp+10h] [ebp-1Ch]
  uint8_t *v19; // [esp+14h] [ebp-18h]
  char *v20; // [esp+18h] [ebp-14h]
  char *v21; // [esp+1Ch] [ebp-10h]
  uint8_t *v22; // [esp+20h] [ebp-Ch]
  uint8_t *v23; // [esp+24h] [ebp-8h]
  uint8_t v24; // [esp+28h] [ebp-4h]

  v6 = a3;
  v21 = a4;
  v18 = 0;
  v23 = a2;
  v7 = 0;
  v20 = &a4[a5];
  v24 = 0;
  if ( sub_F6F90(v15, 0, 0) )
    sub_126487((char *)dword_1AAEA4, 0);
  v19 = (uint8_t *)a3 + (_DWORD)a2;
  v22 = v23 - 8;
  v16 = v23 - a2;
  do
  {
    v8 = sub_F6FD9(v15);
    if ( v8 == -1 && v23 != v19 )
      sub_126487((char *)dword_1AAEA4, v7);
    v9 = v6;
    v10 = v7;
    v17 = &v23[-v18];
    v11 = a4 + 1;
    v12 = v24;
    v6 = (int16_t *)(v18 + 1);
    switch ( v24 )
    {
      case 0u:
        if ( v8 == -1 )
          goto LABEL_9;
        if ( v8 != *v23 )
          goto LABEL_12;
        v24 = 1;
        goto LABEL_13;
      case 1u:
        v12 = *v23;
        if ( v8 == v12 )
        {
          ++v18;
          if ( v6 == (int16_t *)244 )
          {
            v24 = 0;
            *a4++ = -12;
          }
        }
        else
        {
          LOBYTE(v12) = v18;
          *a4++ = v18;
          if ( v8 == -1 )
          {
LABEL_9:
            v24 = 4;
          }
          else
          {
LABEL_12:
            v24 = 2;
LABEL_13:
            v18 = 1;
          }
        }
        break;
      case 2u:
        if ( v8 == -1 )
          goto LABEL_20;
        ++v18;
        if ( v6 == (int16_t *)9 )
          goto LABEL_22;
        if ( v8 == *v23 )
          v24 = 3;
        break;
      case 3u:
        if ( v8 == -1 )
        {
LABEL_20:
          LOBYTE(v12) = v18 - 11;
          *a4 = v18 - 11;
          v24 = 4;
          qmemcpy(v11, v17, v18);
          v6 = (int16_t *)(a4 + 1);
          a4 += v18 + 1;
        }
        else
        {
          v12 = *v23;
          if ( v8 == v12 )
          {
            *a4 = v18 - 12;
            v24 = 1;
            v12 = v18 - 1;
            v13 = v18 - 1;
            v18 = 2;
            qmemcpy(v11, v17, v13);
            v6 = (int16_t *)v11;
            a4 = &v11[v12];
          }
          else
          {
            ++v18;
            if ( v6 == (int16_t *)9 )
            {
LABEL_22:
              *a4 = -2;
              v24 = 0;
              qmemcpy(v11, v22, (unsigned int)v6);
              v6 = (int16_t *)(a4 + 1);
              a4 += 10;
            }
            else
            {
              v24 = 2;
            }
          }
        }
        break;
      default:
        v12 = v10;
        v6 = v9;
        break;
    }
    if ( a4 >= v20 )
      sub_126487((char *)dword_1AAEAC, v12);
    v7 = ++v16 % 256;
    ++v22;
    ++v23;
    if ( !(v16 % 256) )
      sub_FE8BE(v16 / 256, 0, 256, v6);
  }
  while ( v24 != 4 );
  *a4 = -1;
  return (_BYTE *)(a4 + 1 - v21);
}
// F7116: variable 'v15' is possibly undefined
// 1AAEA4: using guessed type int dword_1AAEA4;
// 1AAEAC: using guessed type int dword_1AAEAC;


//----- (000F72D1) --------------------------------------------------------
void __fastcall sub_F72D1(char *a1, char *a2, int a3, _BYTE *a4, int a5)
{
  int v5; // edx
  char *v6; // eax
  void *v7; // esi
  int v8; // edi
  void *v9; // edi
  unsigned int v12; // [esp+Ch] [ebp-10h]
  int v13; // [esp+10h] [ebp-Ch]
  char *v14; // [esp+14h] [ebp-8h]
  _BYTE *v15; // [esp+18h] [ebp-4h]

  v14 = a2;
  v5 = 0;
  v12 = (unsigned int)&a4[a5];
  v15 = a4;
  if ( sub_F6F90((int)a1, 0, 0) )
  {
    v6 = aFseekModemFile;
    goto LABEL_3;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        if ( (unsigned int)v15 >= v12 )
          JUMPOUT(0xF72CB);
        v7 = v15 + 1;
        if ( *v15 >= 0xF5u )
          break;
        v8 = (uint8_t)*v15;
        v5 = v8;
        if ( sub_F7023(v14, v8, 1, a1) != 1 )
        {
          v6 = aFreadModemFile;
          goto LABEL_3;
        }
        sub_FE8BE(1, v8, 1, (int16_t *)v8);
        v14 += v8;
        ++v15;
      }
      if ( *v15 == 0xFF )
        break;
      v13 = (uint8_t)*v15 - 245;
      v5 = v13;
      if ( sub_F6F90((int)a1, v13, 1) )
      {
        v6 = aFseekAheadMode;
        goto LABEL_3;
      }
      v9 = v14;
      v14 += v13;
      qmemcpy(v9, v7, v13);
      v15 += v13 + 1;
      sub_FE8BE(v13 + 1, v13, 1, (int16_t *)v9);
    }
    ++v15;
    if ( (unsigned int)v7 > v12 || &a2[a3] < v14 )
    {
      v6 = aPLimitPDiff;
LABEL_3:
      sub_126487(v6, v5);
    }
  }
}
// F73BD: control flows out of bounds to F72CB


//----- (000F73C2) --------------------------------------------------------
char *__usercall sub_F73C2(int a1, int a2, int16_t *a3)
{
  int v4; // eax

  sub_FE8BE(a1, a2, a1, a3);
  if ( byte_1AB0CE == 2 && a2 && a2 != dword_1AB0DB )
  {
    nfree(dword_1AB0D3);
    byte_1AB0CE = 0;
  }
  if ( !byte_1AB0CE )
  {
    v4 = nmalloc(a2);
    dword_1AB0D3 = v4;
    if ( v4 )
    {
      byte_1AB0CE = 2;
      dword_1AB0DB = a2;
      dword_1AB0D7 = v4;
    }
    else
    {
      dword_1AB0CF = fopen(aModemTmp);
      if ( !dword_1AB0CF )
        sub_126487((char *)dword_1AAEA4, a1);
      byte_1AB0CE = 1;
    }
  }
  return &byte_1AB0CE;
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);
// 13CB78: using guessed type int __fastcall nmalloc(_DWORD);
// 1AAEA4: using guessed type int dword_1AAEA4;
// 1AB0CE: using guessed type char byte_1AB0CE;
// 1AB0CF: using guessed type int dword_1AB0CF;
// 1AB0D3: using guessed type int dword_1AB0D3;
// 1AB0D7: using guessed type int dword_1AB0D7;
// 1AB0DB: using guessed type int dword_1AB0DB;


//----- (000F747B) --------------------------------------------------------
void __fastcall sub_F747B(char *a1, void *a2, int16_t *a3)
{
  sub_FE8BE((int)a1, (int)a2, (int)a3, a3);
  if ( sub_F6F90((int)a1, 0, 0) )
    sub_126487((char *)dword_1AAEA4, 0);
  sub_FE8BE(0, 0, 0, a3);
  if ( sub_F707D(a2, (int)a3, 1, a1) != 1 )
    sub_126487((char *)dword_1AAEA4, (int)a3);
  sub_FE8BE(1, (int)a3, 1, a3);
}
// 1AAEA4: using guessed type int dword_1AAEA4;


//----- (000F74CD) --------------------------------------------------------
void __fastcall sub_F74CD( int a1, int a2, int a3)
{
  int v3; // eax
  int v4; // eax
  int16_t *v5; // edi
  char *v6; // ebx
  int16_t *v7; // ebx
  char *v8; // eax
  int v9; // edx
  char *v10; // esi
  int v11; // eax
  int16_t *v12; // edi
  char *v13; // esi
  int v14; // edx
  char *v15; // edi
  int v16; // eax
  char *v17; // eax
  int v18; // eax
  int v19; // edx
  unsigned int v20; // esi
  int v21; // ebx
  int64_t v22; // rax
  int16_t *v23; // [esp-4h] [ebp-24h]
  int v24; // [esp+0h] [ebp-20h] BYREF
  _BYTE *v25; // [esp+4h] [ebp-1Ch]
  int v26; // [esp+8h] [ebp-18h]
  char *v27; // [esp+Ch] [ebp-14h]
  int16_t *v28; // [esp+10h] [ebp-10h]
  char *v29; // [esp+14h] [ebp-Ch]
  int v30; // [esp+18h] [ebp-8h] BYREF
  char v31; // [esp+1Ch] [ebp-4h]

  v31 = a1;
  sub_1112EC(dword_192ED4, (int)&loc_E1000);
  v28 = (int16_t *)sub_110D3C(dword_192ED4, (int)&loc_E1000);
  v25 = v28;
  qmemcpy(v28, &word_1AAF68, sizeof(int16_t));
  qmemcpy(v28 + 1, &dword_192FD8, 4u);
  qmemcpy(v28 + 3, &byte_199BDE, 1u);
  qmemcpy((char *)v28 + 7, &byte_199CB0, sizeof(char));
  qmemcpy(v28 + 4, &byte_199CB1, 1u);
  qmemcpy((char *)v28 + 9, &byte_199CB2, sizeof(char));
  qmemcpy(v28 + 5, &byte_199CB3, 1u);
  qmemcpy((char *)v28 + 11, &byte_199CB4, sizeof(char));
  qmemcpy(v28 + 6, &byte_199CB5, 1u);
  qmemcpy((char *)v28 + 13, &byte_199CAF, sizeof(char));
  sub_FE8BE((int)(v28 + 1), (int)&loc_E1000, a3, (int16_t *)((char *)v28 + 13));
  v29 = (char *)(v28 + 7);
  v24 = sub_12484C();
  qmemcpy(v28 + 7, &v24, 4u);
  v29 += 4;
  qmemcpy(v29, &word_199998, 2u);
  v29 += 2;
  qmemcpy(v29, (void *)dword_197F98, 3753 * word_199998);
  v29 += 3753 * word_199998;
  qmemcpy(v29, &word_19999A, 2u);
  v29 += 2;
  qmemcpy(v29, (void *)dword_19306C, 113 * (word_19999A + 1));
  v29 += 113 * word_19999A + 113;
  qmemcpy(v29, &word_1999A2, 2u);
  v29 += 2;
  qmemcpy(v29, (void *)dword_1930D4, 17 * word_1999A2);
  v3 = 17 * word_1999A2;
  v29 += v3;
  qmemcpy(v29, &word_199996, 2u);
  v29 += 2;
  qmemcpy(v29, (void *)dword_192B18, 0x1608Au);
  v29 += 90250;
  qmemcpy(v29, &word_199994, 2u);
  v29 += 2;
  v23 = (int16_t *)v29;
  qmemcpy(v29, (void *)dword_197F9C, 0xFBF4u);
  sub_FE8BE(v3, (int)&loc_E1000, a3, v23);
  v29 += 64500;
  qmemcpy(v29, (void *)dword_1930DC, 0xF71u);
  v29 += 3953;
  qmemcpy(v29, &word_1AB502, 2u);
  v29 += 2;
  qmemcpy(v29, byte_1AB14C, 0x3B6u);
  v29 += 950;
  qmemcpy(v29, byte_19ABA4, 0x144u);
  v29 += 324;
  qmemcpy(v29, byte_1AA40C, word_199998);
  v29 += word_199998;
  qmemcpy(v29, byte_1AAB24, word_199998);
  v29 += word_199998;
  qmemcpy(v29, byte_1AAB1C, word_199998);
  v29 += word_199998;
  qmemcpy(v29, &unk_1AA414, 0x708u);
  v29 += 1800;
  qmemcpy(v29, &word_19A0E2, 2u);
  v29 += 2;
  qmemcpy(v29, &word_19A0E4, 2u);
  v29 += 2;
  qmemcpy(v29, &word_199174, 0x42u);
  v29 += 66;
  qmemcpy(v29++, &byte_199F0D, sizeof(char));
  qmemcpy(v29, (void *)dword_193068, 5 * (uint8_t)byte_199F0D);
  v4 = 5 * (uint8_t)byte_199F0D;
  v29 += v4;
  qmemcpy(v29, &dword_19ACE8, 4u);
  v29 += 4;
  qmemcpy(v29, &word_19ACEC, 2u);
  v29 += 2;
  v5 = (int16_t *)v29;
  v29 += 12;
  qmemcpy(v5, &word_17D634, 0xCu);
  v6 = v29;
  sub_FE8BE(v4, (int)&loc_E1000, (int)v29, v5);
  v7 = (int16_t *)(v6 - (char *)v28);
  if ( v31 )
  {
    v8 = sub_F73C2((int)aWb_3, (int)v7, v5);
    v9 = (int)v28;
    v10 = v8;
    sub_F747B(v8, v28, v7);
    v11 = (int)v28;
    v12 = (int16_t *)v29;
    v27 = (char *)v28;
  }
  else
  {
    v27 = v29;
    v13 = sub_F73C2((int)aRb_1, 0, v5);
    v14 = (int)v28;
    v15 = v29;
    v16 = (int)sub_F70EB((int)v13, (uint8_t *)v28, v7, v29, &loc_E1000 - (_UNKNOWN *)v7);
    v12 = (int16_t *)&v15[v16];
    sub_FE8BE(v16, v14, (int)v13, v12);
    if ( *v13 == 1 )
    {
      if ( fclose(*(_DWORD *)(v13 + 1)) )
        sub_126487((char *)dword_1AAEA4, v14);
      *v13 = 0;
      *(_DWORD *)(v13 + 1) = 0;
    }
    v7 = (int16_t *)(v29 - (char *)(v25));
    v17 = sub_F73C2((int)aWb_3, v29 - (char *)(v25), v12);
    v9 = (int)v25;
    v10 = v17;
    sub_F747B(v17, v25, v7);
  }
  sub_FE8BE(v11, v9, (int)v7, v12);
  sub_FE8BE(v18, v9, (int)v7, v12);
  if ( *v10 == 1 )
  {
    if ( fclose(*(_DWORD *)(v10 + 1)) )
      sub_126487((char *)dword_1AAEA4, v9);
    *v10 = 0;
    *(_DWORD *)(v10 + 1) = 0;
  }
  v26 = 0;
  v30 = ((char *)v12 - v27 + 30719) / 30720;
  v19 = 2;
  v20 = (unsigned int)v27;
  sub_F6816(32766, 2, (int)&v30, 2u);
  while ( v20 < (unsigned int)v12 )
  {
    v21 = (int)v12 - v20;
    if ( (int)((int)v12 - v20) > 30720 )
      v21 = 30720;
    v22 = sprintf(&word_18FF78, (char *)dword_1AAEB0, v26 + 1, (int16_t)v30);
    do
    {
      sub_124D41();
      LODWORD(v22) = sub_1192D1();
      LODWORD(v22) = sub_1077D(v22, SHIDWORD(v22), v21, v12);
      sub_FE8BE(v22, SHIDWORD(v22), v21, v12);
    }
    while ( sub_139127() );
    v19 = 3;
    ++v26;
    sub_F6816(32766, 3, v20, v21);
    v20 += 30720;
  }
  sub_1113CC(dword_192ED4, v19);
  JUMPOUT(0xFA388);
}
// F79F1: control flows out of bounds to FA388
// F7915: variable 'v11' is possibly undefined
// F791A: variable 'v18' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 17D634: using guessed type int16_t word_17D634;
// 18FF78: using guessed type int16_t word_18FF78;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 192FD8: using guessed type int dword_192FD8;
// 193068: using guessed type int dword_193068;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199174: using guessed type int16_t word_199174;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 1999A2: using guessed type int16_t word_1999A2;
// 199BDE: using guessed type char byte_199BDE;
// 199CAF: using guessed type char byte_199CAF;
// 199CB0: using guessed type char byte_199CB0;
// 199CB1: using guessed type char byte_199CB1;
// 199CB2: using guessed type char byte_199CB2;
// 199CB3: using guessed type char byte_199CB3;
// 199CB4: using guessed type char byte_199CB4;
// 199CB5: using guessed type char byte_199CB5;
// 199F0D: using guessed type char byte_199F0D;
// 19A0E2: using guessed type int16_t word_19A0E2;
// 19A0E4: using guessed type int16_t word_19A0E4;
// 19ACE8: using guessed type int dword_19ACE8;
// 19ACEC: using guessed type int16_t word_19ACEC;
// 1AAEA4: using guessed type int dword_1AAEA4;
// 1AAEB0: using guessed type int dword_1AAEB0;
// 1AAF68: using guessed type int16_t word_1AAF68;
// 1AB502: using guessed type int16_t word_1AB502;


//----- (000F79F6) --------------------------------------------------------
char __fastcall sub_F79F6(char *a1, int16_t *a2, int a3)
{
  int16_t *v3; // edi
  char *v4; // ebx
  char *v5; // edx
  char *v6; // esi
  int16_t *v7; // eax
  char *v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  char *v12; // esi
  unsigned int v13; // ecx
  int v14; // eax
  char *v15; // esi
  char *v16; // esi
  char *v17; // esi
  int v18; // eax
  char *v20; // [esp+0h] [ebp-10h]
  int v21; // [esp+4h] [ebp-Ch] BYREF
  char *v22; // [esp+8h] [ebp-8h]
  char *v23; // [esp+Ch] [ebp-4h]

  v3 = a2;
  v22 = a1;
  if ( !a3 )
  {
    v23 = &a1[(_DWORD)a2];
    v4 = (char *)(&loc_E1000 - (_UNKNOWN *)a2);
    v5 = v23;
    v6 = sub_F73C2((int)aRb_1, 0, v3);
    sub_F72D1(v6, v23, &loc_E1000 - (_UNKNOWN *)v3, v20, (int)v3);
    v3 = v7;
    sub_FE8BE((int)v7, (int)v23, (int)v4, v7);
    if ( *v6 == 1 )
    {
      if ( fclose(*(_DWORD *)(v6 + 1)) )
        sub_126487((char *)dword_1AAEA4, (int)v23);
      *v6 = 0;
      *(_DWORD *)(v6 + 1) = 0;
    }
    if ( !v3 )
      sub_126487(aErrorDecodingB, (int)v5);
    v20 = v23;
    v22 = v23;
  }
  v8 = sub_F73C2((int)aWb_3, (int)v3, v3);
  sub_F747B(v8, v20, v3);
  sub_FE8BE(v9, (int)v20, (int)v3, v3);
  if ( *v8 == 1 )
  {
    v10 = fclose(*(_DWORD *)(v8 + 1));
    if ( v10 )
      sub_126487((char *)dword_1AAEA4, (int)v20);
    *v8 = 0;
    *(_DWORD *)(v8 + 1) = 0;
  }
  sub_FE8BE(v10, (int)v20, (int)v3, &word_1AAF68);
  qmemcpy(&word_1AAF68, v22, sizeof(word_1AAF68));
  v22 += 2;
  qmemcpy(&dword_192FD8, v22, sizeof(dword_192FD8));
  v22 += 4;
  qmemcpy(&byte_199BDE, v22++, sizeof(byte_199BDE));
  qmemcpy(&byte_199CB0, v22++, sizeof(byte_199CB0));
  qmemcpy(&byte_199CB1, v22++, sizeof(byte_199CB1));
  qmemcpy(&byte_199CB2, v22++, sizeof(byte_199CB2));
  qmemcpy(&byte_199CB3, v22++, sizeof(byte_199CB3));
  qmemcpy(&byte_199CB4, v22++, sizeof(byte_199CB4));
  qmemcpy(&byte_199CB5, v22++, sizeof(byte_199CB5));
  qmemcpy(&byte_199CAF, v22++, sizeof(byte_199CAF));
  qmemcpy(&v21, v22, sizeof(v21));
  v22 += 4;
  v11 = sub_124820(v21);
  v12 = v22;
  sub_FE8BE(v11, (int)v20, (int)v3, &word_199998);
  qmemcpy(&word_199998, v12, sizeof(word_199998));
  v22 += 2;
  qmemcpy((void *)dword_197F98, v22, 3753 * word_199998);
  v22 += 3753 * word_199998;
  byte_1AAF5D = 0;
  v13 = 3753 * word_199998 + dword_197F98;
  while ( v13 > dword_197F98 )
  {
    v13 -= 3753;
    if ( *(_BYTE *)(v13 + 36) )
    {
      *(_WORD *)(v13 + 43) = -1;
      *(_BYTE *)(v13 + 40) = 0;
    }
    else if ( *(_BYTE *)(v13 + 40) == 100 )
    {
      ++byte_1AAF5D;
    }
  }
  qmemcpy(&word_19999A, v22, sizeof(word_19999A));
  v22 += 2;
  qmemcpy((void *)dword_19306C, v22, 113 * (word_19999A + 1));
  v14 = 113 * (word_19999A + 1);
  v22 += v14;
  v15 = v22;
  sub_FE8BE(v14, (int)v20, (int)v3, &word_1999A2);
  qmemcpy(&word_1999A2, v15, sizeof(word_1999A2));
  v22 += 2;
  qmemcpy((void *)dword_1930D4, v22, 17 * word_1999A2);
  v22 += 17 * word_1999A2;
  qmemcpy(&word_199996, v22, sizeof(word_199996));
  v22 += 2;
  qmemcpy((void *)dword_192B18, v22, 0x1608Au);
  v22 += 90250;
  qmemcpy(&word_199994, v22, sizeof(word_199994));
  v22 += 2;
  qmemcpy((void *)dword_197F9C, v22, 0xFBF4u);
  v22 += 64500;
  qmemcpy((void *)dword_1930DC, v22, 0xF71u);
  v22 += 3953;
  qmemcpy(&word_1AB502, v22, sizeof(word_1AB502));
  v22 += 2;
  qmemcpy(byte_1AB14C, v22, 0x3B6u);
  v22 += 950;
  v16 = v22;
  sub_FD7EA();
  qmemcpy(byte_19ABA4, v16, 0x144u);
  v22 += 324;
  qmemcpy(byte_1AA40C, v22, word_199998);
  v22 += word_199998;
  qmemcpy(byte_1AAB24, v22, word_199998);
  v22 += word_199998;
  qmemcpy(byte_1AAB1C, v22, word_199998);
  v22 += word_199998;
  qmemcpy(&unk_1AA414, v22, 0x708u);
  v22 += 1800;
  v17 = v22;
  sub_FE8BE(word_199998, (int)v20, (int)v3, &word_19A0E2);
  qmemcpy(&word_19A0E2, v17, sizeof(word_19A0E2));
  v22 += 2;
  qmemcpy(&word_19A0E4, v22, sizeof(word_19A0E4));
  v22 += 2;
  qmemcpy(&word_199174, v22, 0x42u);
  v22 += 66;
  qmemcpy(&byte_199F0D, v22++, sizeof(byte_199F0D));
  qmemcpy((void *)dword_193068, v22, 5 * (uint8_t)byte_199F0D);
  v18 = 5 * (uint8_t)byte_199F0D;
  v22 += v18;
  qmemcpy(&dword_19ACE8, v22, sizeof(dword_19ACE8));
  v22 += 4;
  qmemcpy(&word_19ACEC, v22, sizeof(word_19ACEC));
  v22 += 2;
  qmemcpy(&word_17D634, v22, 0xCu);
  sub_FE8BE(v18, (int)v20, (int)v3, &word_17D634);
  return 1;
}
// F7A2C: variable 'v20' is possibly undefined
// F7A31: variable 'v7' is possibly undefined
// F7A95: variable 'v9' is possibly undefined
// F7ACE: variable 'v10' is possibly undefined
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 17D634: using guessed type int16_t word_17D634;
// 192B18: using guessed type int dword_192B18;
// 192FD8: using guessed type int dword_192FD8;
// 193068: using guessed type int dword_193068;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199174: using guessed type int16_t word_199174;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 1999A2: using guessed type int16_t word_1999A2;
// 199BDE: using guessed type char byte_199BDE;
// 199CAF: using guessed type char byte_199CAF;
// 199CB0: using guessed type char byte_199CB0;
// 199CB1: using guessed type char byte_199CB1;
// 199CB2: using guessed type char byte_199CB2;
// 199CB3: using guessed type char byte_199CB3;
// 199CB4: using guessed type char byte_199CB4;
// 199CB5: using guessed type char byte_199CB5;
// 199F0D: using guessed type char byte_199F0D;
// 19A0E2: using guessed type int16_t word_19A0E2;
// 19A0E4: using guessed type int16_t word_19A0E4;
// 19ACE8: using guessed type int dword_19ACE8;
// 19ACEC: using guessed type int16_t word_19ACEC;
// 1AAEA4: using guessed type int dword_1AAEA4;
// 1AAF5D: using guessed type char byte_1AAF5D;
// 1AAF68: using guessed type int16_t word_1AAF68;
// 1AB502: using guessed type int16_t word_1AB502;


//----- (000F7E95) --------------------------------------------------------
void sub_F7E95()
{
  int v0; // eax
  int v1; // edx
  int i; // ebx
  int v3; // esi
  char v4; // al
  char v5; // cl
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // edi
  int v15; // eax
  int v16; // eax
  int16_t *v17; // edi
  int v18; // eax
  int16_t *v19; // edx
  int v20; // eax
  int v21; // eax
  int16_t *v22; // edx
  int v23; // eax
  int16_t *v24; // edx
  int v25; // ecx
  char *v26; // esi
  int *v27; // ebx
  int16_t *v28; // edi
  int v29; // eax
  int v30; // ebx
  int64_t v31; // rax
  char v32; // [esp-5h] [ebp-6E9h]
  char *v33; // [esp-4h] [ebp-6E8h]
  _BYTE v34[1728]; // [esp+0h] [ebp-6E4h] BYREF
  int v35; // [esp+6C0h] [ebp-24h]
  char *v36; // [esp+6C4h] [ebp-20h]
  int v37; // [esp+6C8h] [ebp-1Ch]
  int16_t *v38; // [esp+6CCh] [ebp-18h]
  int v39; // [esp+6D0h] [ebp-14h] BYREF
  int v40; // [esp+6D4h] [ebp-10h] BYREF
  int v41; // [esp+6D8h] [ebp-Ch] BYREF
  int v42; // [esp+6DCh] [ebp-8h] BYREF
  char v43[4]; // [esp+6E0h] [ebp-4h] BYREF
  _DWORD savedregs[6]; // [esp+6E4h] [ebp+0h] BYREF

  sub_1112EC(dword_192ED4, 350000);
  v36 = (char *)sub_110D3C(dword_192ED4, 350000);
  qmemcpy(v36, &dword_192FD8, 4u);
  v43[0] = word_19999C;
  qmemcpy(v36 + 4, v43, sizeof(char));
  v0 = 3753 * word_19999C;
  v38 = (int16_t *)(v36 + 5);
  v33 = v36 + 5;
  qmemcpy(v36 + 5, (void *)(v0 + dword_197F98), 0xEA9u);
  sub_FE8BE(v0, 0, 1728, (int16_t *)(v36 + 5));
  memset(v34, 0, sizeof(v34));
  v37 = word_19999A;
  v1 = 6 * word_19999A;
  v38 = (int16_t *)((char *)v38 + 3753);
  for ( i = 113 * word_19999A; i > 0; v34[v1 * 4 + 23] = *(_BYTE *)(word_19999C + i + dword_19306C + 103) )
  {
    i -= 113;
    v3 = i + dword_19306C;
    v35 = *(uint8_t *)(i + dword_19306C + 53);
    v4 = word_19999C;
    v5 = v35 >> word_19999C;
    LOBYTE(savedregs[v1 - 447]) &= ~1u;
    savedregs[v1 - 447] |= v5 & 1;
    v35 = *(uint8_t *)(v3 + 54);
    v6 = (v35 >> v4) & 1;
    LOBYTE(savedregs[v1 - 447]) &= ~2u;
    savedregs[v1 - 447] |= 2 * v6;
    v35 = *(uint8_t *)(v3 + 56);
    v7 = (v35 >> v4) & 1;
    LOBYTE(savedregs[v1 - 447]) &= ~4u;
    savedregs[v1 - 447] |= 4 * v7;
    v35 = *(uint8_t *)(v3 + 57);
    v8 = (v35 >> v4) & 1;
    LOBYTE(savedregs[v1 - 447]) &= ~8u;
    savedregs[v1 - 447] |= 8 * v8;
    v35 = *(uint8_t *)(v3 + 59);
    v9 = (v35 >> v4) & 1;
    LOBYTE(savedregs[v1 - 447]) &= ~0x10u;
    savedregs[v1 - 447] |= 16 * v9;
    v35 = *(uint8_t *)(v3 + 60);
    v10 = (v35 >> v4) & 1;
    LOBYTE(savedregs[v1 - 447]) &= ~0x20u;
    savedregs[v1 - 447] |= 32 * v10;
    v35 = *(uint8_t *)(v3 + 61);
    v11 = (v35 >> v4) & 1;
    LOBYTE(savedregs[v1 - 447]) &= ~0x40u;
    savedregs[v1 - 447] |= v11 << 6;
    v35 = *(uint8_t *)(v3 + 62);
    v12 = (v35 >> v4) & 1;
    LOBYTE(savedregs[v1 - 447]) &= ~0x80u;
    savedregs[v1 - 447] |= v12 << 7;
    v35 = *(uint8_t *)(v3 + 63);
    v13 = (v35 >> v4) & 1;
    BYTE1(savedregs[v1 - 447]) &= ~1u;
    savedregs[v1 - 447] |= v13 << 8;
    v14 = ((int)*(uint8_t *)(v3 + 64) >> v4) & 1;
    BYTE1(savedregs[v1 - 447]) &= ~2u;
    v15 = word_19999C;
    savedregs[v1 - 447] |= v14 << 9;
    *(_DWORD *)(&v32 + v1 * 4) = *(char *)(v3 + v15 + 66);
    --v37;
    v1 -= 6;
    if ( *(char *)(v3 + 55) == word_19999C )
    {
      v33 = &v34[v1 * 4 + 4];
      strcpy(v33, (char *)v3);
    }
  }
  qmemcpy(v38, v34, 24 * word_19999A);
  v16 = 24 * word_19999A;
  v38 = (int16_t *)((char *)v38 + v16);
  v17 = v38;
  sub_FE8BE(v16, v1 * 4, i, v38);
  v33 = (char *)v17;
  qmemcpy(v17, &word_199996, sizeof(int16_t));
  LOWORD(v18) = word_199996;
  ++v38;
  v42 = v18;
  while ( 1 )
  {
    v19 = v38 + 1;
    if ( (int16_t)v42 <= 0 )
      break;
    v18 = 361 * (int16_t)--v42;
    i = dword_192B18;
    LOWORD(v18) = *(char *)(dword_192B18 + v18);
    if ( (_WORD)v18 == word_19999C )
    {
      qmemcpy(v38, &v42, sizeof(int16_t));
      v18 = 361 * (int16_t)v42;
      v38 = (int16_t *)((char *)v19 + 361);
      v33 = (char *)v19;
      qmemcpy(v19, (void *)(v18 + dword_192B18), 0x169u);
    }
  }
  v42 = -1;
  qmemcpy(v38, &v42, sizeof(int16_t));
  sub_FE8BE(v18, (int)v19, i, v19);
  v33 = (char *)v19;
  qmemcpy(v19, &word_199994, sizeof(int16_t));
  v40 = 0;
  v38 = v19 + 1;
  while ( 1 )
  {
    v21 = v40;
    v22 = v38 + 1;
    if ( (int16_t)v40 >= word_199994 )
      break;
    HIWORD(i) = HIWORD(dword_197F9C);
    v20 = dword_197F9C + 129 * (int16_t)v40;
    LOWORD(i) = *(char *)(v20 + 99);
    if ( (_WORD)i == word_19999C && *(_BYTE *)(v20 + 100) != 5 )
    {
      qmemcpy(v38, &v40, sizeof(int16_t));
      v38 = (int16_t *)((char *)v22 + 129);
      v33 = (char *)v22;
      qmemcpy(v22, (void *)(dword_197F9C + 129 * (int16_t)v40), 0x81u);
    }
    ++v40;
  }
  v40 = -1;
  v33 = (char *)v38;
  qmemcpy(v38, &v40, sizeof(int16_t));
  sub_FE8BE(v21, (int)v22, i, (int16_t *)v33);
  v41 = 0;
  v38 = v22;
  while ( 1 )
  {
    v24 = v38 + 1;
    if ( (int16_t)v41 >= 67 )
      break;
    i = 59 * (int16_t)v41;
    HIWORD(v23) = HIWORD(dword_1930DC);
    LOWORD(v23) = *(char *)(i + dword_1930DC + 58);
    if ( (_WORD)v23 == word_19999C )
    {
      qmemcpy(v38, &v41, sizeof(int16_t));
      v23 = 59 * (int16_t)v41;
      v38 = (int16_t *)((char *)v24 + 59);
      v33 = (char *)v24;
      qmemcpy(v24, (void *)(v23 + dword_1930DC), 0x3Bu);
    }
    ++v41;
  }
  v41 = -1;
  v33 = (char *)v38;
  qmemcpy(v38, &v41, sizeof(int16_t));
  sub_FE8BE(v23, (int)v24, i, (int16_t *)v33);
  v38 = v24;
  v25 = 2;
  v26 = v36;
  v27 = &v39;
  v39 = ((char *)v24 - v36 + 30719) / 30720;
  v28 = 0;
  v29 = sub_F6816(word_1AAF86, 13, (int)&v39, 2u);
  while ( v26 < (char *)v38 )
  {
    sub_FE8BE(v29, (char *)v38 - v26, (int)v27, v28);
    v30 = (int)v28 + 1;
    if ( (int16_t *)((char *)v28 + 1) == (int16_t *)(int16_t)v39 )
    {
      byte_1AB03F = 14;
      byte_1AB048 = -1;
    }
    v28 = (int16_t *)((char *)v28 + 1);
    v31 = sprintf(&word_18FF78, (char *)dword_1AAEB0, v28, (int16_t)v39);
    do
    {
      sub_F55A4(v31, SHIDWORD(v31), v30, v25);
      LODWORD(v31) = sub_139127();
    }
    while ( (_DWORD)v31 );
    v25 = WORD2(v31);
    v27 = (int *)v26;
    v29 = sub_F6816(word_1AAF86, 14, (int)v26, WORD2(v31));
    v26 += 30720;
  }
  JUMPOUT(0xF79E7);
}
// F83B2: control flows out of bounds to F79E7
// F8158: variable 'v18' is possibly undefined
// F82F9: variable 'v23' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 18FF78: using guessed type int16_t word_18FF78;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 192FD8: using guessed type int dword_192FD8;
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1AAEB0: using guessed type int dword_1AAEB0;
// 1AAF86: using guessed type int16_t word_1AAF86;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB048: using guessed type char byte_1AB048;


//----- (000F83D8) --------------------------------------------------------
void __fastcall sub_F83D8(char *a1, int a2, int a3)
{
  char *v3; // edx
  int v4; // eax
  char *v5; // edx
  int v6; // ebx
  int v7; // eax
  char v8; // cl
  char v9; // cl
  char v10; // cl
  char v11; // cl
  char v12; // cl
  char v13; // cl
  char v14; // cl
  char v15; // cl
  char v16; // cl
  char v17; // cl
  char *v18; // edi
  char *v19; // edx
  int16_t *v20; // edi
  int v21; // eax
  int v22; // ebx
  int v23; // edx
  int v24; // edi
  int v25; // eax
  int v26; // eax
  void *v27; // esi
  int v28; // edi
  int v29; // eax
  int v30; // eax
  int16_t *v31; // edi
  int v32; // edi
  int v33; // ebx
  void *v34; // esi
  int i; // ebx
  int16_t *v36; // [esp-4h] [ebp-6E8h]
  _BYTE v37[1728]; // [esp+0h] [ebp-6E4h] BYREF
  _BYTE v38[4]; // [esp+6C0h] [ebp-24h] BYREF
  int v39; // [esp+6C4h] [ebp-20h]
  int v40; // [esp+6C8h] [ebp-1Ch]
  int16_t v41; // [esp+6CCh] [ebp-18h] BYREF
  int v42; // [esp+6D0h] [ebp-14h] BYREF
  int v43; // [esp+6D4h] [ebp-10h] BYREF
  int v44; // [esp+6D8h] [ebp-Ch] BYREF
  int16_t v45; // [esp+6DCh] [ebp-8h] BYREF
  char v46[4]; // [esp+6E0h] [ebp-4h] BYREF

  qmemcpy(v38, a1, sizeof(v38));
  v3 = a1 + 4;
  qmemcpy(v46, a1 + 4, 1u);
  v4 = 3753 * (uint8_t)v46[0];
  ++v3;
  v36 = (int16_t *)(v4 + dword_197F98);
  qmemcpy((void *)(v4 + dword_197F98), v3, 0xEA9u);
  sub_FE8BE(v4, (int)v3, a3, v36);
  v3 += 3753;
  v36 = (int16_t *)v37;
  qmemcpy(v37, v3, 24 * word_19999A);
  v5 = &v3[24 * word_19999A];
  v40 = word_19999A;
  v6 = 24 * word_19999A;
  v7 = 113 * word_19999A;
  v39 = v7;
  while ( v6 > 0 )
  {
    v39 -= 113;
    v6 -= 24;
    --v40;
    v8 = 1 << v46[0];
    if ( (v37[v6] & 1) != 0 )
      *(_BYTE *)(v39 + dword_19306C + 53) |= v8;
    else
      *(_BYTE *)(v39 + dword_19306C + 53) &= ~v8;
    v9 = 1 << v46[0];
    if ( (v37[v6] & 2) != 0 )
      *(_BYTE *)(v39 + dword_19306C + 54) |= v9;
    else
      *(_BYTE *)(v39 + dword_19306C + 54) &= ~v9;
    v10 = 1 << v46[0];
    if ( (v37[v6] & 4) != 0 )
      *(_BYTE *)(v39 + dword_19306C + 56) |= v10;
    else
      *(_BYTE *)(v39 + dword_19306C + 56) &= ~v10;
    v11 = 1 << v46[0];
    if ( (v37[v6] & 8) != 0 )
      *(_BYTE *)(v39 + dword_19306C + 57) |= v11;
    else
      *(_BYTE *)(v39 + dword_19306C + 57) &= ~v11;
    v12 = 1 << v46[0];
    if ( (v37[v6] & 0x10) != 0 )
      *(_BYTE *)(v39 + dword_19306C + 59) |= v12;
    else
      *(_BYTE *)(v39 + dword_19306C + 59) &= ~v12;
    v13 = 1 << v46[0];
    if ( (v37[v6] & 0x20) != 0 )
      *(_BYTE *)(v39 + dword_19306C + 60) |= v13;
    else
      *(_BYTE *)(v39 + dword_19306C + 60) &= ~v13;
    v14 = 1 << v46[0];
    if ( (v37[v6] & 0x40) != 0 )
      *(_BYTE *)(v39 + dword_19306C + 61) |= v14;
    else
      *(_BYTE *)(v39 + dword_19306C + 61) &= ~v14;
    v15 = 1 << v46[0];
    if ( (char)v37[v6] >= 0 )
      *(_BYTE *)(v39 + dword_19306C + 62) &= ~v15;
    else
      *(_BYTE *)(v39 + dword_19306C + 62) |= v15;
    v16 = 1 << v46[0];
    if ( (v37[v6 + 1] & 1) != 0 )
      *(_BYTE *)(v39 + dword_19306C + 63) |= v16;
    else
      *(_BYTE *)(v39 + dword_19306C + 63) &= ~v16;
    v17 = 1 << v46[0];
    if ( (v37[v6 + 1] & 2) != 0 )
      *(_BYTE *)(v39 + dword_19306C + 64) |= v17;
    else
      *(_BYTE *)(v39 + dword_19306C + 64) &= ~v17;
    v18 = (char *)(v39 + dword_19306C);
    v18[(uint8_t)v46[0] + 66] = v37[v6 + 19];
    if ( v18[55] == (uint8_t)v46[0] )
    {
      v36 = (int16_t *)v18;
      strcpy(v18, &v37[v6 + 4]);
    }
    v7 = (uint8_t)v46[0] + v39 + dword_19306C;
    *(_BYTE *)(v7 + 103) = v37[v6 + 23];
  }
  sub_FE8BE(v7, (int)v5, v6, (int16_t *)&v44);
  v36 = (int16_t *)&v44;
  qmemcpy(&v44, v5, 2u);
  v19 = v5 + 2;
  if ( word_199996 < (int16_t)v44 )
    word_199996 = v44;
  do
  {
    v36 = (int16_t *)&v43;
    qmemcpy(&v43, v19, 2u);
    v19 += 2;
    if ( (int16_t)v43 != -1 )
    {
      v36 = (int16_t *)(361 * (int16_t)v43 + dword_192B18);
      qmemcpy(v36, v19, 0x169u);
      v20 = v36;
      HIWORD(v21) = HIWORD(dword_1930D4);
      v6 = dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * (int16_t)v43 + 2);
      LOWORD(v21) = *(_WORD *)v6;
      v19 += 361;
      if ( *(_WORD *)v6 != (_WORD)v43 )
      {
        v21 = v43;
        *(_WORD *)v6 = v43;
      }
      sub_FE8BE(v21, (int)v19, v6, v20);
    }
  }
  while ( (int16_t)v43 != -1 );
  sub_FE8BE(-1, (int)v19, v6, (int16_t *)&v42);
  v36 = (int16_t *)&v42;
  qmemcpy(&v42, v19, 2u);
  v22 = 0;
  v23 = (int)(v19 + 2);
  if ( word_199994 < (int16_t)v42 )
    word_199994 = v42;
  do
  {
    v36 = &v45;
    qmemcpy(&v45, (void *)v23, sizeof(v45));
    v23 += 2;
    if ( v45 != -1 )
    {
      v24 = 129 * v22;
      while ( v22 < v45 )
      {
        v25 = v24 + dword_197F9C;
        if ( *(char *)(v24 + dword_197F9C + 99) == (uint8_t)v46[0] && *(_BYTE *)(v25 + 100) != 5 )
        {
          *(_WORD *)(v25 + 116) = -1;
          sub_A163A(v22, v24);
        }
        v24 += 129;
        ++v22;
      }
      v26 = 129 * v45;
      v27 = (void *)v23;
      ++v22;
      v23 += 129;
      v36 = (int16_t *)(v26 + dword_197F9C);
      qmemcpy((void *)(v26 + dword_197F9C), v27, 0x81u);
      sub_FE8BE(v26, v23, v22, v36);
    }
  }
  while ( v45 != -1 );
  v28 = 129 * v22;
  while ( v22 < word_199994 )
  {
    v29 = v28 + dword_197F9C;
    if ( *(char *)(v28 + dword_197F9C + 99) == (uint8_t)v46[0] && *(_BYTE *)(v29 + 100) != 5 )
    {
      *(_WORD *)(v29 + 116) = -1;
      sub_A163A(v22, v28);
    }
    v28 += 129;
    ++v22;
  }
  sub_FE8BE(word_199994, v23, v22, (int16_t *)v28);
  v30 = 0;
  do
  {
    v36 = &v41;
    qmemcpy(&v41, (void *)v23, sizeof(v41));
    v31 = &v41;
    v23 += 2;
    if ( v41 != -1 )
    {
      v32 = 59 * v30;
      while ( v30 < v41 )
      {
        v33 = v32 + dword_1930DC;
        if ( *(char *)(v32 + dword_1930DC + 58) == (uint8_t)v46[0] )
        {
          *(_BYTE *)(v33 + 55) = 0;
          *(_BYTE *)(v33 + 57) = -1;
          *(_WORD *)(v33 + 53) = -1;
          *(_BYTE *)(v33 + 58) = -1;
        }
        v32 += 59;
        ++v30;
      }
      v34 = (void *)v23;
      ++v30;
      v23 += 59;
      v36 = (int16_t *)(59 * v41 + dword_1930DC);
      qmemcpy(v36, v34, 0x3Bu);
      v31 = v36;
    }
  }
  while ( v41 != -1 );
  for ( i = 59 * v30; i < 3953; i += 59 )
  {
    v23 = i + dword_1930DC;
    if ( *(char *)(i + dword_1930DC + 58) == (uint8_t)v46[0] )
    {
      *(_BYTE *)(v23 + 55) = 0;
      *(_BYTE *)(v23 + 57) = -1;
      *(_WORD *)(v23 + 53) = -1;
      *(_BYTE *)(v23 + 58) = -1;
    }
    ++v30;
  }
  sub_FE8BE(v30, v23, i, v31);
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 19999A: using guessed type int16_t word_19999A;


//----- (000F88D8) --------------------------------------------------------
_DWORD *__fastcall sub_F88D8(int a1, int a2, void *a3)
{
  int v3; // ebx
  int v4; // edx
  int v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int *v19; // ebx
  int v20; // eax
  char *i; // esi
  int v22; // edx
  int v23; // eax
  int v24; // eax
  int v27; // [esp+4h] [ebp-20h] BYREF
  int v28; // [esp+8h] [ebp-1Ch]
  char *v29; // [esp+Ch] [ebp-18h] BYREF
  int v30; // [esp+10h] [ebp-14h]
  char *v31; // [esp+14h] [ebp-10h]
  int v32; // [esp+18h] [ebp-Ch] BYREF
  int v33; // [esp+1Ch] [ebp-8h] BYREF
  int v34; // [esp+20h] [ebp-4h] BYREF

  v28 = a1;
  v27 = a2;
  v3 = 113 * (int16_t)a2 + dword_19306C;
  sub_1112EC(dword_192ED4, a2);
  if ( (_WORD)v28 == word_19999C )
    v4 = 20;
  else
    v4 = 30720;
  v31 = (char *)sub_110D3C(dword_192ED4, v4);
  v29 = v31;
  v5 = 3753 * (int16_t)v28;
  qmemcpy(v31, &v27, 2u);
  v29 += 2;
  qmemcpy(v29, a3, 0x2Cu);
  v6 = v5 + dword_197F98;
  v29 += 44;
  if ( word_1AAF86 != *(_WORD *)(v5 + dword_197F98 + 43) )
  {
    sub_E691A((void **)&v29, v27);
    v7 = word_199998;
    v8 = 3753 * word_199998;
    while ( v8 > 0 )
    {
      v8 -= 3753;
      --v7;
      qmemcpy(v29, (void *)(v8 + dword_197F98 + 279), 0xD4u);
      v29 += 212;
    }
    v9 = sub_FE8BE(v8);
    v32 = 67;
    while ( (int16_t)v32 > 0 )
    {
      --v32;
      qmemcpy(v29, &v32, 2u);
      v10 = 59 * (int16_t)v32;
      v29 += 2;
      qmemcpy(v29, (void *)(v10 + dword_1930DC), 0x3Bu);
      v29 += 59;
      v9 = sub_FE8BE(v10);
    }
    v32 = -1;
    qmemcpy(v29, &v32, 2u);
    v29 += 2;
    LOWORD(v9) = word_199998;
    while ( (int16_t)v9 > 0 )
      qmemcpy(v29++, (void *)(v3 + 66 + (int16_t)--v9), sizeof(char));
    sub_FE8BE(v9);
    qmemcpy(v29, &word_199996, 2u);
    v11 = v3 + 10;
    v29 += 2;
    v30 = v3;
    do
    {
      v12 = *(int16_t *)(v11 + 72);
      v11 -= 2;
      if ( v12 != -1 )
      {
        v13 = 17 * v12;
        qmemcpy(v29, (void *)(v13 + dword_1930D4), 2u);
        v29 += 2;
        qmemcpy(v29++, (void *)(v13 + dword_1930D4 + 4), sizeof(char));
        qmemcpy(v29++, (void *)(v13 + dword_1930D4 + 8), sizeof(char));
        qmemcpy(v29, (void *)(v13 + dword_1930D4), 2u);
        v29 += 2;
        v14 = *(int16_t *)(v13 + dword_1930D4);
        if ( v14 != -1 )
        {
          qmemcpy(v29, (void *)(361 * v14 + dword_192B18), 0x169u);
          v29 += 361;
        }
      }
    }
    while ( v11 != v30 );
    sub_FE8BE(v11);
    qmemcpy(v29, &word_199994, 2u);
    v33 = 0;
    v29 += 2;
    while ( 1 )
    {
      v6 = v33;
      if ( (int16_t)v33 >= word_199994 )
        break;
      v15 = 129 * (int16_t)v33 + dword_197F9C;
      if ( *(_WORD *)(v15 + 101) == (_WORD)v27 && *(_BYTE *)(v15 + 100) != 5 )
      {
        qmemcpy(v29, &v33, 2u);
        v16 = 129 * (int16_t)v33;
        v29 += 2;
        qmemcpy(v29, (void *)(v16 + dword_197F9C), 0x81u);
        v29 += 129;
        sub_FE8BE(v16);
      }
      ++v33;
    }
    v33 = -1;
    qmemcpy(v29, &v33, 2u);
    v29 += 2;
  }
  sub_FE8BE(v6);
  if ( v29 - v31 > 0x8000 )
  {
    v34 = (v29 - v31 + 30719) / 30720;
    v18 = 2;
    v19 = &v34;
    v20 = *(int16_t *)(dword_197F98 + 3753 * (int16_t)v28 + 43);
    v17 = 46;
    for ( i = v31; ; i += 30720 )
    {
      v24 = sub_F6816(v20, v17, (int)v19, v18);
      if ( i >= v29 )
        break;
      v22 = v29 - i;
      v23 = sub_FE8BE(v24);
      if ( v22 > 30720 )
        v22 = 30720;
      do
      {
        sub_F55A4(v23, v22, (int)v19, v18);
        v23 = sub_139127();
      }
      while ( v23 );
      v18 = (uint16_t)v22;
      v19 = (int *)i;
      v20 = *(int16_t *)(3753 * (int16_t)v28 + dword_197F98 + 43);
      v17 = 47;
    }
  }
  else
  {
    v17 = 16;
    sub_F6816(*(int16_t *)(3753 * (int16_t)v28 + dword_197F98 + 43), 16, (int)v31, (_WORD)v29 - (_WORD)v31);
  }
  return sub_1113CC(dword_192ED4, v17);
}
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 1AAF86: using guessed type int16_t word_1AAF86;


//----- (000F8C8E) --------------------------------------------------------
void __fastcall sub_F8C8E(char *a1)
{
  int v1; // ebx
  void *v2; // eax
  int16_t v3; // ax
  int v4; // eax
  int16_t v5; // dx
  int v6; // eax
  int v7; // eax
  int16_t v8; // dx
  int v9; // ebx
  int16_t *v10; // eax
  int v11; // esi
  int v12; // edi
  int v13; // eax
  int v14; // eax
  _BYTE v15[44]; // [esp+0h] [ebp-40h] BYREF
  char *v16; // [esp+2Ch] [ebp-14h] BYREF
  int v17; // [esp+30h] [ebp-10h]
  int i; // [esp+34h] [ebp-Ch] BYREF
  int16_t v19; // [esp+38h] [ebp-8h] BYREF
  int j; // [esp+3Ch] [ebp-4h] BYREF

  qmemcpy(&v19, a1, sizeof(v19));
  v1 = 113 * v19 + dword_19306C;
  byte_1AB040 = v19;
  byte_1AB048 = word_19999C;
  qmemcpy(v15, a1 + 2, sizeof(v15));
  v16 = a1 + 46;
  v2 = sub_E6903(v15);
  sub_FE8BE(v2);
  v17 = v1;
  if ( word_1AAF86 != word_1AAF5E )
  {
    sub_E6979((void **)&v16, -1);
    v3 = word_199998;
    while ( v3 > 0 )
    {
      qmemcpy((void *)(dword_197F98 + 3753 * --v3 + 279), v16, 0xD4u);
      v16 += 212;
    }
    for ( i = 67; (int16_t)i > 0; *(_BYTE *)(dword_1930DC + 59 * (int16_t)i + 58) = -1 )
      --i;
    do
    {
      qmemcpy(&i, v16, 2u);
      v16 += 2;
      if ( (int16_t)i != -1 )
      {
        v4 = 59 * (int16_t)i;
        qmemcpy((void *)(v4 + dword_1930DC), v16, 0x3Bu);
        v16 += 59;
        sub_FE8BE(v4);
      }
    }
    while ( (int16_t)i != -1 );
    sub_FE8BE(-1);
    v5 = word_199998;
    v6 = v17 + 66;
    while ( v5 > 0 )
      qmemcpy((void *)(v6 + --v5), v16++, 1u);
    v7 = sub_FE8BE(v6);
    v8 = 5;
    qmemcpy(&word_199996, v16, sizeof(word_199996));
    v16 += 2;
    do
    {
      v9 = *(int16_t *)(v17 + 2 * --v8 + 74);
      if ( v9 != -1 )
      {
        qmemcpy((void *)(17 * v9 + dword_1930D4), v16, 2u);
        v16 += 2;
        qmemcpy((void *)(17 * v9 + dword_1930D4 + 4), v16++, 1u);
        qmemcpy((void *)(17 * v9 + dword_1930D4 + 8), v16, 1u);
        v10 = (int16_t *)(dword_1930D4 + 17 * v9);
        ++v16;
        v11 = *v10;
        if ( v11 != -1 )
        {
          v12 = dword_192B18;
          *(_BYTE *)(dword_192B18 + 361 * v11) = -1;
          *(_WORD *)(v12 + 361 * *v10 + 2) = -1;
        }
        qmemcpy((void *)(17 * v9 + dword_1930D4), v16, 2u);
        v16 += 2;
        v7 = *(int16_t *)(dword_1930D4 + 17 * v9);
        if ( v7 != -1 )
        {
          v7 *= 361;
          qmemcpy((void *)(v7 + dword_192B18), v16, 0x169u);
          v16 += 361;
        }
      }
    }
    while ( v8 > 0 );
    v13 = sub_FE8BE(v7);
    qmemcpy(&word_199994, v16, sizeof(word_199994));
    LOWORD(v13) = word_199994;
    v16 += 2;
    for ( j = v13; (int16_t)j > 0; *(_BYTE *)(dword_197F9C + 129 * (int16_t)j + 100) = 5 )
      --j;
    do
    {
      qmemcpy(&j, v16, 2u);
      v16 += 2;
      if ( (int16_t)j != -1 )
      {
        v14 = 129 * (int16_t)j;
        qmemcpy((void *)(v14 + dword_197F9C), v16, 0x81u);
        v16 += 129;
        sub_FE8BE(v14);
      }
    }
    while ( (int16_t)j != -1 );
  }
  sub_8A4C4();
  byte_1AAF8B[12 * word_19999C] = 16;
  byte_1AB03F = 16;
  JUMPOUT(0xF88D2);
}
// F8F93: control flows out of bounds to F88D2
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF86: using guessed type int16_t word_1AAF86;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB040: using guessed type char byte_1AB040;
// 1AB048: using guessed type char byte_1AB048;


//----- (000F8F98) --------------------------------------------------------
void __fastcall sub_F8F98(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // ebx
  int v6; // edx
  int v7; // edx
  void **v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int16_t v14; // ax
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  int *v18; // ebx
  int v19; // eax
  char *i; // esi
  int v21; // edx
  int v22; // eax
  int v23; // eax
  int v24; // [esp+0h] [ebp-28h] BYREF
  int v25; // [esp+4h] [ebp-24h] BYREF
  int v26; // [esp+8h] [ebp-20h] BYREF
  int v27; // [esp+Ch] [ebp-1Ch]
  char *v28; // [esp+10h] [ebp-18h] BYREF
  char *v29; // [esp+14h] [ebp-14h]
  int v30; // [esp+18h] [ebp-10h] BYREF
  int v31; // [esp+1Ch] [ebp-Ch] BYREF
  int v32; // [esp+20h] [ebp-8h] BYREF
  int v33; // [esp+24h] [ebp-4h] BYREF

  v27 = a1;
  v26 = a2;
  v25 = a3;
  v24 = a4;
  v5 = 113 * a5 + dword_19306C;
  sub_1112EC(dword_192ED4, a2);
  if ( (_WORD)v27 == word_19999C )
    v6 = 30;
  else
    v6 = 30720;
  v29 = (char *)sub_110D3C(dword_192ED4, v6);
  v7 = 3753 * (int16_t)v27;
  qmemcpy(v29, &a5, 2u);
  v28 = v29 + 2;
  qmemcpy(v29 + 2, &v26, 2u);
  v28 += 2;
  qmemcpy(v28, &v25, 2u);
  v28 += 2;
  qmemcpy(v28, &v24, 2u);
  v28 += 2;
  if ( word_1AAF86 != *(_WORD *)(v7 + dword_197F98 + 43) )
  {
    v8 = sub_E691A((void **)&v28, a5);
    v9 = sub_FE8BE(v8);
    if ( (int16_t)v26 < 8 )
    {
      v9 = dword_197F98 + 3753 * (int16_t)v26;
      qmemcpy(v28, (void *)(v9 + 279), 0xD4u);
      v28 += 212;
    }
    if ( (int16_t)v27 < 8 )
    {
      v9 = 3753 * (int16_t)v27 + dword_197F98;
      qmemcpy(v28, (void *)(v9 + 279), 0xD4u);
      v28 += 212;
    }
    v10 = sub_FE8BE(v9);
    v31 = 67;
    while ( (int16_t)v31 > 0 )
    {
      v10 = 59 * (int16_t)--v31;
      LOWORD(v10) = *(char *)(dword_1930DC + v10 + 58);
      if ( (_WORD)v10 == (_WORD)v26 || (_WORD)v10 == (_WORD)v27 )
      {
        qmemcpy(v28, &v31, 2u);
        v28 += 2;
        v10 = dword_1930DC;
        qmemcpy(v28, (void *)(dword_1930DC + 59 * (int16_t)v31), 0x3Bu);
        v28 += 59;
      }
    }
    v31 = -1;
    qmemcpy(v28, &v31, 2u);
    v28 += 2;
    if ( (int16_t)v26 < 8 )
    {
      v10 = v5 + 66;
      qmemcpy(v28++, (void *)(v5 + 66 + (int16_t)v26), sizeof(char));
    }
    if ( (int16_t)v27 < 8 )
      qmemcpy(v28++, (void *)(v5 + 66 + (int16_t)v27), sizeof(char));
    sub_FE8BE(v10);
    v11 = (int16_t)v24;
    if ( (int16_t)v24 != -1 )
    {
      HIWORD(v12) = HIWORD(dword_192B18);
      LOWORD(v12) = *(_WORD *)(361 * (int16_t)v24 + dword_192B18 + 2);
      v33 = v12;
      qmemcpy(v28, &word_199996, 2u);
      v28 += 2;
      qmemcpy(v28, &v33, 2u);
      v28 += 2;
      qmemcpy(v28, (void *)(17 * (int16_t)v33 + dword_1930D4), 2u);
      v28 += 2;
      qmemcpy(v28++, (void *)(dword_1930D4 + 17 * (int16_t)v33 + 4), sizeof(char));
      qmemcpy(v28, (void *)(17 * (int16_t)v33 + dword_1930D4 + 8), sizeof(char));
      v11 = 361 * (int16_t)v24;
      qmemcpy(++v28, (void *)(v11 + dword_192B18), 0x169u);
      v28 += 361;
    }
    sub_FE8BE(v11);
    qmemcpy(v28, &word_199994, 2u);
    v30 = 0;
    v28 += 2;
    while ( 1 )
    {
      v15 = v30;
      if ( (int16_t)v30 >= word_199994 )
        break;
      v13 = 129 * (int16_t)v30 + dword_197F9C;
      if ( *(_WORD *)(v13 + 101) == a5 && *(_BYTE *)(v13 + 100) != 5 )
      {
        v14 = *(char *)(v13 + 99);
        if ( v14 == (_WORD)v26 || v14 == (_WORD)v27 )
        {
          qmemcpy(v28, &v30, 2u);
          v28 += 2;
          qmemcpy(v28, (void *)(129 * (int16_t)v30 + dword_197F9C), 0x81u);
          v28 += 129;
        }
      }
      ++v30;
    }
    v30 = -1;
    qmemcpy(v28, &v30, 2u);
    v28 += 2;
    sub_FE8BE(v15);
  }
  if ( v28 - v29 > 0x8000 )
  {
    v32 = (v28 - v29 + 30719) / 30720;
    v17 = 2;
    v18 = &v32;
    v19 = *(int16_t *)(3753 * (int16_t)v27 + dword_197F98 + 43);
    v16 = 52;
    for ( i = v29; ; i += 30720 )
    {
      v23 = sub_F6816(v19, v16, (int)v18, v17);
      if ( i >= v28 )
        break;
      v21 = v28 - i;
      v22 = sub_FE8BE(v23);
      if ( v21 > 30720 )
        v21 = 30720;
      do
      {
        sub_F55A4(v22, v21, (int)v18, v17);
        v22 = sub_139127();
      }
      while ( v22 );
      v17 = (uint16_t)v21;
      v18 = (int *)i;
      v19 = *(int16_t *)(3753 * (int16_t)v27 + dword_197F98 + 43);
      v16 = 53;
    }
  }
  else
  {
    v16 = 18;
    sub_F6816(*(int16_t *)(3753 * (int16_t)v27 + dword_197F98 + 43), 18, (int)v29, (_WORD)v28 - (_WORD)v29);
  }
  sub_1113CC(dword_192ED4, v16);
  JUMPOUT(0xF72CB);
}
// F93DE: control flows out of bounds to F72CB
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 19999C: using guessed type int16_t word_19999C;
// 1AAF86: using guessed type int16_t word_1AAF86;


//----- (000F93E3) --------------------------------------------------------
void __fastcall sub_F93E3(char *a1)
{
  int16_t v1; // bx
  int16_t v2; // ax
  int v3; // eax
  int16_t v4; // ax
  char *v5; // [esp+0h] [ebp-24h] BYREF
  int v6; // [esp+4h] [ebp-20h]
  int i; // [esp+8h] [ebp-1Ch] BYREF
  int v8; // [esp+Ch] [ebp-18h] BYREF
  int16_t v9; // [esp+10h] [ebp-14h] BYREF
  int16_t v10; // [esp+14h] [ebp-10h] BYREF
  int16_t v11; // [esp+18h] [ebp-Ch] BYREF
  int16_t v12; // [esp+1Ch] [ebp-8h] BYREF
  int v13; // [esp+20h] [ebp-4h] BYREF

  v1 = word_19999C;
  qmemcpy(&v11, a1, sizeof(v11));
  v6 = 113 * v11 + dword_19306C;
  byte_1AB040 = v11;
  qmemcpy(&v12, a1 + 2, sizeof(v12));
  byte_1AB048 = v12;
  qmemcpy(&v13, a1 + 4, 2u);
  word_1AB041 = v13;
  qmemcpy(&v10, a1 + 6, sizeof(v10));
  v5 = a1 + 8;
  word_1AB045 = word_19999C;
  if ( word_1AAF86 != word_1AAF5E )
  {
    sub_E6979((void **)&v5, -1);
    if ( v12 < 8 )
    {
      qmemcpy((void *)(3753 * v12 + dword_197F98 + 279), v5, 0xD4u);
      v5 += 212;
    }
    if ( v1 < 8 )
    {
      qmemcpy((void *)(3753 * v1 + dword_197F98 + 279), v5, 0xD4u);
      v5 += 212;
    }
    v8 = 67;
    while ( (int16_t)v8 > 0 )
    {
      v2 = *(char *)(59 * (int16_t)--v8 + dword_1930DC + 58);
      if ( v2 == v12 || v2 == v1 )
        *(_BYTE *)(dword_1930DC + 59 * (int16_t)v8 + 58) = -1;
    }
    do
    {
      qmemcpy(&v8, v5, 2u);
      v5 += 2;
      if ( (int16_t)v8 != -1 )
      {
        qmemcpy((void *)(59 * (int16_t)v8 + dword_1930DC), v5, 0x3Bu);
        v5 += 59;
      }
    }
    while ( (int16_t)v8 != -1 );
    if ( v12 < 8 )
      qmemcpy((void *)(v12 + v6 + 66), v5++, 1u);
    if ( v1 < 8 )
      qmemcpy((void *)(v6 + 66 + v1), v5++, 1u);
    v3 = v10;
    if ( v10 != -1 )
    {
      qmemcpy(&word_199996, v5, sizeof(word_199996));
      v5 += 2;
      qmemcpy(&v9, v5, sizeof(v9));
      v5 += 2;
      qmemcpy((void *)(17 * v9 + dword_1930D4), v5, 2u);
      v5 += 2;
      qmemcpy((void *)(17 * v9 + dword_1930D4 + 4), v5++, 1u);
      qmemcpy((void *)(17 * v9 + dword_1930D4 + 8), v5, 1u);
      v3 = 361 * v10;
      qmemcpy((void *)(v3 + dword_192B18), ++v5, 0x169u);
      v5 += 361;
    }
    qmemcpy(&word_199994, v5, sizeof(word_199994));
    LOWORD(v3) = word_199994;
    v5 += 2;
    for ( i = v3; (int16_t)i > 0; *(_BYTE *)(dword_197F9C + 129 * (int16_t)i + 100) = 5 )
      --i;
    do
    {
      qmemcpy(&i, v5, 2u);
      v5 += 2;
      if ( (int16_t)i != -1 )
      {
        qmemcpy((void *)(129 * (int16_t)i + dword_197F9C), v5, 0x81u);
        v5 += 129;
      }
    }
    while ( (int16_t)i != -1 );
  }
  v4 = sub_E69DE(v10);
  byte_1AB03F = 19;
  word_1AB043 = v4;
  JUMPOUT(0xF88D2);
}
// F970C: control flows out of bounds to F88D2
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 19999C: using guessed type int16_t word_19999C;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF86: using guessed type int16_t word_1AAF86;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB040: using guessed type char byte_1AB040;
// 1AB041: using guessed type int16_t word_1AB041;
// 1AB043: using guessed type int16_t word_1AB043;
// 1AB045: using guessed type int16_t word_1AB045;
// 1AB048: using guessed type char byte_1AB048;


//----- (000F9711) --------------------------------------------------------
int __fastcall sub_F9711(int a1, int a2, int a3)
{
  _DWORD v4[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( byte_199F3A != 2 && byte_199F3A != 3 )
    return sub_2332C((int16_t)a1, a2, a3);
  v4[0] = a1;
  v4[1] = a2;
  v4[2] = a3;
  return sub_F6816(word_1AAF86, 60, (int)v4, 0xCu);
}
// 199F3A: using guessed type char byte_199F3A;
// 1AAF86: using guessed type int16_t word_1AAF86;


//----- (000F975C) --------------------------------------------------------
char __fastcall sub_F975C( int a1, int a2, int a3, int a4, int a5, int a6)
{
  _WORD v7[6]; // [esp+0h] [ebp-Ch] BYREF

  if ( byte_199F3A != 2 && byte_199F3A != 3 )
    return sub_4E3B5(a1, a2, a3, a4, a5, a6);
  v7[0] = a1;
  v7[1] = a2;
  v7[2] = a3;
  v7[3] = a4;
  v7[4] = a5;
  v7[5] = a6;
  return sub_F6816(word_1AAF86, 67, (int)v7, 0xCu);
}
// 199F3A: using guessed type char byte_199F3A;
// 1AAF86: using guessed type int16_t word_1AAF86;


//----- (000F97CD) --------------------------------------------------------
_DWORD *__fastcall sub_F97CD(int a1, int a2, int a3, int a4, int a5, int a6)
{
  char *v6; // eax
  int16_t *v7; // edi
  int v8; // edx
  void **v9; // eax
  int16_t *v10; // edi
  int v11; // eax
  int v12; // eax
  int16_t *v13; // edi
  int v14; // eax
  int v15; // eax
  void *v16; // esi
  int16_t v17; // ax
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  int *v22; // ebx
  unsigned int v23; // esi
  int v24; // eax
  int v25; // edx
  int v26; // eax
  int16_t *v28; // [esp-4h] [ebp-30h]
  int16_t *v29; // [esp-4h] [ebp-30h]
  int16_t *v30; // [esp-4h] [ebp-30h]
  int16_t *v31; // [esp-4h] [ebp-30h]
  int16_t *v32; // [esp-4h] [ebp-30h]
  int16_t *v33; // [esp-4h] [ebp-30h]
  int16_t *v34; // [esp-4h] [ebp-30h]
  int16_t *v35; // [esp-4h] [ebp-30h]
  int v36; // [esp+0h] [ebp-2Ch] BYREF
  int v37; // [esp+4h] [ebp-28h] BYREF
  int v38; // [esp+8h] [ebp-24h] BYREF
  int v39; // [esp+Ch] [ebp-20h] BYREF
  char *v40; // [esp+10h] [ebp-1Ch] BYREF
  unsigned int v41; // [esp+14h] [ebp-18h]
  int v42; // [esp+18h] [ebp-14h] BYREF
  int v43; // [esp+1Ch] [ebp-10h] BYREF
  int v44; // [esp+20h] [ebp-Ch] BYREF
  int v45; // [esp+24h] [ebp-8h] BYREF
  int v46; // [esp+28h] [ebp-4h] BYREF

  v39 = a1;
  v38 = a2;
  v37 = a3;
  v36 = a4;
  LOWORD(a1) = word_19999C;
  v46 = a1;
  sub_1112EC(dword_192ED4, 30720);
  v6 = (char *)sub_110D3C(dword_192ED4, 30720);
  qmemcpy(v6, &v46, 2u);
  v40 = v6 + 2;
  qmemcpy(v6 + 2, &v38, 2u);
  v40 += 2;
  qmemcpy(v40, &v37, 2u);
  v40 += 2;
  v41 = (unsigned int)v6;
  v28 = (int16_t *)v40;
  qmemcpy(v40, &a6, 2u);
  v7 = v28;
  v40 += 2;
  if ( word_1AAF86 != word_1AAF5E
    && ((_WORD)v46 != (_WORD)v37 || (int16_t)v38 >= 8 || *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v38 + 40) != 100) )
  {
    v8 = -1;
    qmemcpy(v40, &v39, 2u);
    v40 += 2;
    v9 = sub_E691A((void **)&v40, -1);
    qmemcpy(v40, &v36, 2u);
    v40 += 2;
    v29 = (int16_t *)v40;
    qmemcpy(v40, &a5, 2u);
    v10 = v29;
    v40 += 2;
    sub_FE8BE((int)v9, -1, a3, v29);
    if ( (int16_t)v38 < 8 )
    {
      qmemcpy(v40, (void *)(dword_197F98 + 3753 * (int16_t)v38 + 279), 0xD4u);
      v40 += 212;
      v8 = dword_19306C;
      v11 = dword_19306C + 113 * (int16_t)v39 + 66;
      v30 = (int16_t *)v40;
      qmemcpy(v40, (void *)(v11 + (int16_t)v38), sizeof(char));
      v10 = v30;
      ++v40;
    }
    if ( (int16_t)v37 < 8 )
    {
      qmemcpy(v40, (void *)(dword_197F98 + 3753 * (int16_t)v37 + 279), 0xD4u);
      v40 += 212;
      v8 = dword_19306C;
      v11 = dword_19306C + 113 * (int16_t)v39 + 66;
      v31 = (int16_t *)v40;
      qmemcpy(v40, (void *)(v11 + (int16_t)v37), sizeof(char));
      v10 = v31;
      ++v40;
    }
    sub_FE8BE(v11, v8, a3, v10);
    v43 = 67;
    while ( (int16_t)v43 > 0 )
    {
      v12 = 59 * (int16_t)--v43;
      v8 = dword_1930DC;
      LOWORD(v12) = *(char *)(dword_1930DC + v12 + 58);
      if ( (_WORD)v12 == (_WORD)v38 || (_WORD)v12 == (_WORD)v37 )
      {
        qmemcpy(v40, &v43, 2u);
        v12 = 59 * (int16_t)v43;
        v40 += 2;
        qmemcpy(v40, (void *)(v12 + dword_1930DC), 0x3Bu);
        v40 += 59;
      }
    }
    v43 = -1;
    v32 = (int16_t *)v40;
    qmemcpy(v40, &v43, 2u);
    v13 = v32;
    v40 += 2;
    sub_FE8BE(v12, v8, a3, v32);
    v14 = a5;
    if ( a5 != -1 )
    {
      v15 = 17 * a5;
      v16 = (void *)(v15 + dword_1930D4);
      LOWORD(v15) = *(_WORD *)(v15 + dword_1930D4);
      v42 = v15;
      qmemcpy(v40, v16, 2u);
      v40 += 2;
      qmemcpy(v40, (void *)(17 * a5 + dword_1930D4 + 4), sizeof(char));
      v8 = 17 * a5;
      qmemcpy(++v40, (void *)(v8 + dword_1930D4 + 8), sizeof(char));
      v33 = (int16_t *)++v40;
      qmemcpy(v40, &v42, 2u);
      v13 = v33;
      v14 = (int16_t)v42;
      v40 += 2;
      if ( (int16_t)v42 != -1 )
      {
        v14 = 361 * (int16_t)v42;
        v34 = (int16_t *)v40;
        qmemcpy(v40, (void *)(v14 + dword_192B18), 0x169u);
        v13 = v34;
        v40 += 361;
      }
    }
    sub_FE8BE(v14, v8, a3, v13);
    qmemcpy(v40, &word_199994, 2u);
    v45 = 0;
    v40 += 2;
    while ( 1 )
    {
      v18 = v45;
      if ( (int16_t)v45 >= word_199994 )
        break;
      v8 = 129 * (int16_t)v45 + dword_197F9C;
      if ( *(_WORD *)(v8 + 101) == (_WORD)v39 && *(_BYTE *)(v8 + 100) != 5 )
      {
        v17 = *(char *)(v8 + 99);
        if ( v17 == (_WORD)v38 || v17 == (_WORD)v37 )
        {
          qmemcpy(v40, &v45, 2u);
          v40 += 2;
          qmemcpy(v40, (void *)(129 * (int16_t)v45 + dword_197F9C), 0x81u);
          v40 += 129;
        }
      }
      ++v45;
    }
    v45 = -1;
    v35 = (int16_t *)v40;
    qmemcpy(v40, &v45, 2u);
    v7 = v35;
    v40 += 2;
    sub_FE8BE(v18, v8, a3, v35);
  }
  if ( (int)&v40[-v41] > 0x8000 )
  {
    v44 = (int)&v40[-v41 + 30719] / 30720;
    byte_1AB03F = 31;
    v20 = sub_F6816(word_1AAF86, 48, 0, 0);
    while ( byte_1AB03F != 32 )
      sub_FE8BE(v20, 48, 0, v7);
    byte_1AB03F = 14;
    v21 = 2;
    v22 = &v44;
    v19 = 50;
    v23 = v41;
    v24 = sub_F6816(word_1AAF86, 50, (int)&v44, 2u);
    while ( v23 < (unsigned int)v40 )
    {
      v25 = (int)&v40[-v23];
      sub_FE8BE(v24, (int)&v40[-v23], (int)v22, v7);
      if ( v25 > 30720 )
        v25 = 30720;
      do
      {
        sub_F55A4(v26, v25, (int)v22, v21);
        v26 = sub_139127();
      }
      while ( v26 );
      v21 = (uint16_t)v25;
      v22 = (int *)v23;
      v19 = 51;
      v24 = sub_F6816(word_1AAF86, 51, v23, v21);
      v23 += 30720;
    }
  }
  else
  {
    v19 = 21;
    sub_F6816(word_1AAF86, 21, v41, (_WORD)v40 - v41);
  }
  return sub_1113CC(dword_192ED4, v19);
}
// F9985: variable 'v11' is possibly undefined
// F9A08: variable 'v12' is possibly undefined
// F9BD6: variable 'v20' is possibly undefined
// F9C19: variable 'v26' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999C: using guessed type int16_t word_19999C;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF86: using guessed type int16_t word_1AAF86;
// 1AB03F: using guessed type char byte_1AB03F;


//----- (000F9C58) --------------------------------------------------------
void __fastcall sub_F9C58(char *a1)
{
  void **v1; // eax
  int v2; // eax
  int16_t *v3; // edi
  int v4; // edx
  int v5; // edx
  int v6; // eax
  int16_t v7; // ax
  int v8; // ebx
  int16_t v9; // ax
  int v10; // ebx
  char *v11; // [esp+0h] [ebp-2Ch] BYREF
  int16_t v12; // [esp+4h] [ebp-28h] BYREF
  int16_t v13; // [esp+8h] [ebp-24h] BYREF
  _BYTE v14[2]; // [esp+Ch] [ebp-20h] BYREF
  _BYTE v15[2]; // [esp+10h] [ebp-1Ch] BYREF
  int16_t v16; // [esp+14h] [ebp-18h] BYREF
  int16_t v17; // [esp+18h] [ebp-14h] BYREF
  int v18; // [esp+1Ch] [ebp-10h] BYREF
  int16_t v19; // [esp+20h] [ebp-Ch] BYREF
  int16_t v20; // [esp+24h] [ebp-8h] BYREF
  int16_t v21; // [esp+28h] [ebp-4h] BYREF

  qmemcpy(&v18, a1, 2u);
  qmemcpy(&v21, a1 + 2, sizeof(v21));
  qmemcpy(&v20, a1 + 4, sizeof(v20));
  v11 = a1 + 6;
  qmemcpy(v15, a1 + 6, sizeof(v15));
  LOBYTE(a1) = v15[0];
  byte_1AAF95[12 * v21] = v15[0];
  v11 += 2;
  byte_1AAF95[12 * v20] = (char)a1;
  sub_FE8BE(a1);
  if ( (_WORD)v18 != word_19999C && ((_WORD)v18 != v20 || v21 >= 8 || *(_BYTE *)(3753 * v21 + dword_197F98 + 40) != 100) )
  {
    qmemcpy(&v16, v11, sizeof(v16));
    v11 += 2;
    v1 = sub_E6979((void **)&v11, v16);
    qmemcpy(v14, v11, sizeof(v14));
    v11 += 2;
    qmemcpy(&v17, v11, sizeof(v17));
    v11 += 2;
    sub_FE8BE(v1);
    if ( v21 < 8 )
    {
      qmemcpy((void *)(dword_197F98 + 3753 * v21 + 279), v11, 0xD4u);
      v11 += 212;
      qmemcpy((void *)(dword_19306C + 113 * v16 + 66 + v21), v11++, 1u);
    }
    if ( v20 < 8 )
    {
      qmemcpy((void *)(dword_197F98 + 3753 * v20 + 279), v11, 0xD4u);
      v11 += 212;
      qmemcpy((void *)(v20 + 113 * v16 + dword_19306C + 66), v11++, 1u);
    }
    do
    {
      qmemcpy(&v13, v11, sizeof(v13));
      v11 += 2;
      if ( v13 != -1 )
      {
        qmemcpy((void *)(59 * v13 + dword_1930DC), v11, 0x3Bu);
        v11 += 59;
      }
    }
    while ( v13 != -1 );
    sub_FE8BE(-1);
    v2 = v17;
    if ( v17 != -1 )
    {
      v3 = (int16_t *)(17 * v17 + dword_1930D4);
      v4 = *v3;
      qmemcpy(v3, v11, sizeof(int16_t));
      v11 += 2;
      qmemcpy((void *)(dword_1930D4 + 17 * v17 + 4), v11++, 1u);
      qmemcpy((void *)(17 * v17 + dword_1930D4 + 8), v11++, 1u);
      qmemcpy(&v19, v11, sizeof(v19));
      v2 = v19;
      v11 += 2;
      if ( v19 == -1 )
      {
        if ( v4 != -1 )
          sub_DCDAC((char *)(dword_192B18 + 361 * v4), 1);
      }
      else
      {
        qmemcpy((void *)(361 * v19 + dword_192B18), v11, 0x169u);
        v11 += 361;
        sub_E5296((_BYTE *)(113 * v16 + dword_19306C));
      }
    }
    sub_FE8BE(v2);
    qmemcpy(&word_199994, v11, sizeof(word_199994));
    v5 = 0;
    v11 += 2;
    do
    {
      qmemcpy(&v12, v11, sizeof(v12));
      v6 = v12;
      v11 += 2;
      if ( v12 != -1 )
      {
        while ( (int16_t)v5 < v12 )
        {
          v7 = *(char *)(dword_197F9C + 129 * (int16_t)v5 + 99);
          if ( v7 == v21 || v7 == v20 )
          {
            v8 = dword_197F9C + 129 * (int16_t)v5;
            if ( *(_BYTE *)(v8 + 100) != 5 && *(_WORD *)(v8 + 101) == v16 )
            {
              *(_WORD *)(v8 + 116) = -1;
              sub_A163A(v5, (int16_t)v5);
            }
          }
          ++v5;
        }
        v6 = dword_197F9C;
        ++v5;
        qmemcpy((void *)(dword_197F9C + 129 * v12), v11, 0x81u);
        v11 += 129;
      }
      sub_FE8BE(v6);
    }
    while ( v12 != -1 );
    while ( (int16_t)v5 < word_199994 )
    {
      v9 = *(char *)(129 * (int16_t)v5 + dword_197F9C + 99);
      if ( v9 == v21 || v9 == v20 )
      {
        v10 = 129 * (int16_t)v5 + dword_197F9C;
        if ( *(_BYTE *)(v10 + 100) != 5 && *(_WORD *)(v10 + 101) == v16 )
        {
          *(_WORD *)(v10 + 116) = -1;
          sub_A163A(v5, (int16_t)v5);
        }
      }
      LOWORD(v5) = v5 + 1;
    }
  }
  sub_8A4C4();
  byte_1AAF8B[12 * (int16_t)v18] = 27;
  JUMPOUT(0xF88D2);
}
// FA058: control flows out of bounds to F88D2
// F9F21: variable 'v2' is possibly undefined
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999C: using guessed type int16_t word_19999C;


//----- (000FA05D) --------------------------------------------------------
void __fastcall sub_FA05D(int a1)
{
  _DWORD *v1; // eax

  sub_1112EC(dword_192ED4, 30026);
  v1 = sub_110D3C(dword_192ED4, 30026);
  qmemcpy(v1, &word_199998, 2u);
  qmemcpy((char *)v1 + 2, (void *)dword_197F98, 3753 * word_199998);
  sub_F6816(a1, 32, (int)v1, 3753 * word_199998 + 2);
  JUMPOUT(0xF79E7);
}
// FA0CE: control flows out of bounds to F79E7
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000FA0D3) --------------------------------------------------------
int __fastcall sub_FA0D3(int result)
{
  qmemcpy(&word_199998, (void *)result, sizeof(word_199998));
  qmemcpy((void *)dword_197F98, (void *)(result + 2), 3753 * word_199998);
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000FA104) --------------------------------------------------------
int __fastcall sub_FA104(int a1)
{
  int v2; // [esp+0h] [ebp-4h] BYREF

  v2 = a1;
  return sub_F6816(*(int16_t *)(3753 * *(char *)(dword_192B18 + 361 * a1) + dword_197F98 + 43), 35, (int)&v2, 4u);
}
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;


//----- (000FA16C) --------------------------------------------------------
int __fastcall sub_FA16C(int a1)
{
  int result; // eax
  int v3; // edx

  result = word_199998;
  v3 = 3753 * word_199998;
  while ( v3 > 0 )
  {
    v3 -= 3753;
    --result;
    if ( *(int16_t *)(v3 + dword_197F98 + 43) == a1 )
      return result;
  }
  return -1;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000FA1A3) --------------------------------------------------------
void __fastcall sub_FA1A3(int a1)
{
  int v1; // eax
  int v2; // edx
  uint8_t v3; // cl
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  int v7; // [esp+0h] [ebp-10h]
  _BYTE v8[8]; // [esp+4h] [ebp-Ch] BYREF
  char v9; // [esp+Ch] [ebp-4h]

  v7 = a1;
  memset(v8, 0, sizeof(v8));
  v1 = word_199998;
  v2 = 12 * word_199998;
  v3 = 0;
  v9 = 0;
  v4 = 3753 * word_199998;
  while ( v1 > 0 )
  {
    v4 -= 3753;
    v5 = byte_1AAF8A[v2];
    v2 -= 12;
    --v1;
    if ( v5 == v7 )
    {
      if ( byte_1AAF8B[v2] == 40 )
      {
        v9 = 1;
      }
      else
      {
        if ( *(_BYTE *)(v4 + dword_197F98 + 2227) )
        {
          v8[v1] = 3;
        }
        else if ( *(_BYTE *)(v4 + dword_197F98 + 2226) )
        {
          v8[v1] = 1;
        }
        else
        {
          v8[v1] = 2;
        }
        if ( v3 < v8[v1] )
          v3 = v8[v1];
      }
    }
  }
  if ( !v9 )
  {
    v6 = word_199998;
    while ( v6 > 0 )
    {
      if ( v3 > v8[--v6] )
        v8[v6] = 0;
    }
    sub_FE8DA((int)v8, word_199998);
  }
  JUMPOUT(0xFA388);
}
// FA26B: control flows out of bounds to FA388
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000FA270) --------------------------------------------------------
int __fastcall sub_FA270( int a1)
{
  int result; // eax
  char v2[4]; // [esp+0h] [ebp-4h] BYREF

  v2[0] = a1;
  byte_1AB04A = a1;
  result = word_1AB09C;
  byte_1AB03F = 37;
  if ( word_1AB09C != -1 )
    return sub_F6816(word_1AB09C, 5, (int)v2, 1u);
  return result;
}
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB04A: using guessed type char byte_1AB04A;
// 1AB09C: using guessed type int16_t word_1AB09C;


//----- (000FA2A9) --------------------------------------------------------
char sub_FA2A9()
{
  char result; // al

  if ( (uint8_t)byte_1AB03F >= 0x25u )
  {
    if ( (uint8_t)byte_1AB03F <= 0x26u )
    {
      return 0;
    }
    else if ( byte_1AB03F == 40 )
    {
      return 1;
    }
  }
  return result;
}
// 1AB03F: using guessed type char byte_1AB03F;


//----- (000FA2C5) --------------------------------------------------------
char sub_FA2C5()
{
  char result; // al
  int v1; // eax
  int v2; // ebx
  int v3; // [esp+0h] [ebp-1DA4h] BYREF
  _BYTE v4[3825]; // [esp+4h] [ebp-1DA0h] BYREF
  int v5; // [esp+EF5h] [ebp-EAFh]
  _BYTE v6[3753]; // [esp+EF9h] [ebp-EABh] BYREF

  result = byte_199F3A;
  if ( (uint8_t)byte_199F3A >= 2u && (uint8_t)byte_199F3A <= 3u )
  {
    v3 = byte_1AB04A;
    qmemcpy(v4, (void *)(dword_197F98 + 3753 * byte_1AB04A), 0xEA9u);
    v5 = word_19999C;
    v1 = word_19999A;
    qmemcpy(v6, (void *)(dword_197F98 + 3753 * word_19999C), sizeof(v6));
    v2 = 113 * word_19999A;
    while ( v1 > 0 )
    {
      v2 -= 113;
      v4[--v1 + 3753] = *(_BYTE *)(v3 + v2 + dword_19306C + 103);
    }
    byte_1AB04A = -1;
    result = word_1AB09C;
    byte_1AB03F = 4;
    if ( word_1AB09C != -1 )
      return sub_F6816(word_1AB09C, 10, (int)&v3, 0x1DA2u);
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB04A: using guessed type char byte_1AB04A;
// 1AB09C: using guessed type int16_t word_1AB09C;


//----- (000FA38F) --------------------------------------------------------
char sub_FA38F()
{
  char result; // al

  result = byte_199F3A;
  if ( (uint8_t)byte_199F3A >= 2u && (uint8_t)byte_199F3A <= 3u )
  {
    byte_1AB04A = -1;
    result = word_1AB09C;
    byte_1AB03F = 39;
    if ( word_1AB09C != -1 )
      return sub_F6816(word_1AB09C, 8, (int)&byte_1AB04A, 1u);
  }
  return result;
}
// 199F3A: using guessed type char byte_199F3A;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB04A: using guessed type char byte_1AB04A;
// 1AB09C: using guessed type int16_t word_1AB09C;


//----- (000FA3D1) --------------------------------------------------------
_BOOL1 sub_FA3D1()
{
  return byte_1AB03F == 4;
}
// 1AB03F: using guessed type char byte_1AB03F;


//----- (000FA3DC) --------------------------------------------------------
char sub_FA3DC()
{
  char result; // al

  result = 0;
  if ( word_1AB09C == -1 )
  {
    result = 1;
    byte_1AB03F = 4;
  }
  return result;
}
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB09C: using guessed type int16_t word_1AB09C;


//----- (000FA3F6) --------------------------------------------------------
void __fastcall sub_FA3F6( int a1)
{
  char v1; // dl
  int v2; // ecx
  int v3; // edx
  _BYTE v4[3828]; // [esp+0h] [ebp-EF4h] BYREF

  byte_1AB04A = a1;
  if ( (((int)(uint8_t)byte_1AB054 >> a1) & 1) != 0 )
  {
    byte_1AB03F = 46;
    byte_1AB0CC = 1;
    byte_1AB0CB = a1;
  }
  else
  {
    byte_1AB03F = 41;
    byte_1AB0CC = 0;
  }
  if ( (((int)(uint8_t)byte_1AB054 >> a1) & 1) != 0 )
  {
    v1 = ~(1 << a1);
    byte_1AB054 &= v1;
    byte_1AB069 &= v1;
    byte_1AB066 = 0;
  }
  else
  {
    if ( byte_1AAF7E[a1] )
      JUMPOUT(0xFA388);
    qmemcpy(v4, (void *)(dword_197F98 + 3753 * word_19999C), 0xEA9u);
    v2 = word_19999A;
    v3 = 113 * word_19999A;
    while ( v2 > 0 )
    {
      v3 -= 113;
      v4[--v2 + 3753] = *(_BYTE *)(dword_19306C + v3 + word_19999C + 103);
    }
  }
  JUMPOUT(0xFA383);
}
// FA492: control flows out of bounds to FA383
// FA4A2: control flows out of bounds to FA388
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB04A: using guessed type char byte_1AB04A;
// 1AB054: using guessed type char byte_1AB054;
// 1AB066: using guessed type char byte_1AB066;
// 1AB069: using guessed type char byte_1AB069;
// 1AB0CB: using guessed type char byte_1AB0CB;
// 1AB0CC: using guessed type char byte_1AB0CC;


//----- (000FA521) --------------------------------------------------------
char __usercall sub_FA521( int a1)
{
  if ( (uint8_t)byte_1AB03F < 0x29u )
  {
    if ( byte_1AB03F != 4 )
      return a1;
    return 0;
  }
  if ( (uint8_t)byte_1AB03F <= 0x2Au )
    return 0;
  if ( (uint8_t)byte_1AB03F <= 0x2Bu )
    return 1;
  if ( (uint8_t)byte_1AB03F >= 0x2Eu )
  {
    if ( (uint8_t)byte_1AB03F > 0x2Fu )
      return a1;
    return 0;
  }
  return a1;
}
// 1AB03F: using guessed type char byte_1AB03F;


//----- (000FA54B) --------------------------------------------------------
_BOOL1 sub_FA54B()
{
  return byte_1AB03F == 41;
}
// 1AB03F: using guessed type char byte_1AB03F;


//----- (000FA556) --------------------------------------------------------
char sub_FA556()
{
  int v0; // eax

  LOBYTE(v0) = byte_199F3A;
  if ( (uint8_t)byte_199F3A >= 2u && (uint8_t)byte_199F3A <= 3u )
  {
    byte_1AB03F = 4;
    v0 = *(int16_t *)(dword_197F98 + 3753 * byte_1AB04A + 43);
    byte_1AB04A = -1;
    if ( v0 != -1 )
      LOBYTE(v0) = sub_F6816(v0, 31, 0, 0);
  }
  return v0;
}
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB04A: using guessed type char byte_1AB04A;


//----- (000FA5A3) --------------------------------------------------------
char __fastcall sub_FA5A3(int a1)
{
  return byte_1AAF7E[a1];
}


//----- (000FA5AA) --------------------------------------------------------
void sub_FA5AA()
{
  byte_1AB04A = -1;
  byte_1AB03F = 4;
}
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB04A: using guessed type char byte_1AB04A;


//----- (000FA5B9) --------------------------------------------------------
char sub_FA5B9()
{
  char result; // al

  result = byte_1AB067;
  byte_1AB067 = 0;
  return result;
}
// 1AB067: using guessed type char byte_1AB067;


//----- (000FA5C6) --------------------------------------------------------
int sub_FA5C6()
{
  return byte_1AB04A;
}
// 1AB04A: using guessed type char byte_1AB04A;


//----- (000FA5CE) --------------------------------------------------------
int sub_FA5CE()
{
  int v0; // ebx
  int v1; // edx
  int v2; // esi

  v0 = -1;
  if ( byte_1AB069 )
  {
    v1 = word_199998;
    v2 = 0;
    while ( v1 > 0 )
    {
      if ( (((int)(uint8_t)byte_1AB069 >> --v1) & 1) != 0 && sub_1247A0(++v2) == 1 )
        v0 = v1;
    }
    byte_1AB069 &= ~(1 << v0);
  }
  return v0;
}
// 199998: using guessed type int16_t word_199998;
// 1AB069: using guessed type char byte_1AB069;


//----- (000FA623) --------------------------------------------------------
void __usercall sub_FA623(int a1, int16_t *a2)
{
  char v2; // cl
  char v3; // al
  int v4; // ebx
  int v5; // eax
  int v6; // eax
  char v8; // [esp+4h] [ebp-4h]

  v2 = a1;
  if ( (((int)(uint8_t)byte_1AB054 >> a1) & 1) == 0 )
  {
    sub_77423(dword_1AAEBC);
    return;
  }
  byte_1AB03F = 46;
  byte_1AB0CC = 1;
  byte_1AB04A = a1;
  v3 = ~(1 << a1);
  byte_1AB0CB = v2;
  byte_1AB054 &= v3;
  byte_1AB069 &= v3;
  v4 = dword_197F98 + 3753 * word_19999C;
  v5 = *(int16_t *)(3753 * a1 + dword_197F98 + 43);
  byte_1AB066 = 0;
  v6 = sub_F6816(v5, 28, v4, 0xEA9u);
  while ( byte_1AB03F == 41 || byte_1AB03F == 46 )
    sub_FE8BE(v6, 28, v4, a2);
  if ( (uint8_t)byte_1AB03F < 0x29u )
  {
    if ( byte_1AB03F != 4 )
      goto LABEL_15;
    goto LABEL_13;
  }
  if ( (uint8_t)byte_1AB03F <= 0x2Au )
  {
LABEL_13:
    v8 = 0;
    goto LABEL_15;
  }
  if ( (uint8_t)byte_1AB03F > 0x2Bu )
  {
    if ( (uint8_t)byte_1AB03F < 0x2Eu || (uint8_t)byte_1AB03F > 0x2Fu )
      goto LABEL_15;
    goto LABEL_13;
  }
  v8 = 1;
LABEL_15:
  if ( v8 )
  {
    sub_16C4E(a1, a2);
    byte_1AB04A = -1;
    byte_1AB03F = 4;
  }
  else
  {
    sub_77423(dword_1AAEBC);
    sub_FA556();
  }
}
// FA6B3: variable 'v6' is possibly undefined
// FA6E7: variable 'v8' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 1AAEBC: using guessed type int dword_1AAEBC;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB04A: using guessed type char byte_1AB04A;
// 1AB054: using guessed type char byte_1AB054;
// 1AB066: using guessed type char byte_1AB066;
// 1AB069: using guessed type char byte_1AB069;
// 1AB0CB: using guessed type char byte_1AB0CB;
// 1AB0CC: using guessed type char byte_1AB0CC;


//----- (000FA728) --------------------------------------------------------
void __fastcall sub_FA728( int a1)
{
  char v1; // al

  *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 3680) |= 1 << a1;
  v1 = ~(1 << a1);
  byte_1AB054 &= v1;
  byte_1AB069 &= v1;
  JUMPOUT(0xFA598);
}
// FA76F: control flows out of bounds to FA598
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 1AB054: using guessed type char byte_1AB054;
// 1AB069: using guessed type char byte_1AB069;


//----- (000FA774) --------------------------------------------------------
void sub_FA774()
{
  JUMPOUT(0xFA59A);
}
// FA790: control flows out of bounds to FA59A
// 197F98: using guessed type int dword_197F98;


//----- (000FA795) --------------------------------------------------------
char sub_FA795()
{
  return byte_1AB054;
}
// 1AB054: using guessed type char byte_1AB054;


//----- (000FA79B) --------------------------------------------------------
char sub_FA79B()
{
  char result; // al

  result = 0;
  if ( byte_1AB03F == 42 )
  {
    byte_1AB03F = 4;
    return 1;
  }
  return result;
}
// 1AB03F: using guessed type char byte_1AB03F;


//----- (000FA7B0) --------------------------------------------------------
void __usercall sub_FA7B0(int a1, int a2, int a3)
{
  int v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int16_t *v8; // edi
  int v9; // eax
  int v10; // edx
  int v11; // eax
  _BYTE v12[3828]; // [esp+0h] [ebp-F04h] BYREF
  _BYTE v13[8]; // [esp+EF4h] [ebp-10h] BYREF
  int v14; // [esp+EFCh] [ebp-8h]
  char v15; // [esp+F00h] [ebp-4h]

  v14 = a2;
  v4 = 3753 * a1;
  *(_WORD *)(3753 * a1 + dword_197F98 + 43) = -1;
  sub_FEC20(a1, a3);
  v5 = word_19999A;
  qmemcpy(v12, (void *)(v4 + dword_197F98), 0xEA9u);
  v6 = 113 * word_19999A;
  while ( v5 > 0 )
  {
    v6 -= 113;
    v12[--v5 + 3753] = *(_BYTE *)(v6 + dword_19306C + a1 + 103);
  }
  memset(v13, 1, word_199998);
  v13[word_19999C] = 0;
LABEL_5:
  v7 = word_199998;
  v15 = 0;
  v8 = (int16_t *)(3753 * word_199998);
  while ( 1 )
  {
    while ( 1 )
    {
      do
      {
        if ( v7 <= 0 )
        {
          if ( !v15 )
            JUMPOUT(0xF88D2);
          goto LABEL_5;
        }
        --v7;
        v8 = (int16_t *)((char *)v8 - 3753);
      }
      while ( !v13[v7] );
      v9 = *(int16_t *)((char *)v8 + dword_197F98 + 43);
      v15 = 1;
      if ( v9 != -1 )
        break;
LABEL_11:
      v13[v7] = 0;
    }
    if ( byte_1AB094[v7] )
    {
      v10 = (uint16_t)v14;
      v11 = sub_F6816(v9, v14, (int)v12, 0xEF1u);
      do
      {
        sub_FE8BE(v11, v10, (int)v12, v8);
        v11 = sub_139127();
      }
      while ( v11 );
      goto LABEL_11;
    }
  }
}
// FA89D: control flows out of bounds to F88D2
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;


//----- (000FA8A2) --------------------------------------------------------
void __fastcall sub_FA8A2(int a1, char *a2)
{
  int v3; // edx
  int v4; // esi
  char *v5; // eax
  char v6; // cl

  if ( word_1AB09C == *(_WORD *)(3753 * a1 + dword_197F98 + 43) )
    word_1AB09C = -1;
  sub_FEC20(a1, 3753 * a1);
  v3 = word_19999A;
  qmemcpy((void *)(dword_197F98 + 3753 * a1), a2, 0xEA9u);
  v4 = 113 * v3;
  v5 = &a2[v3];
  while ( v4 > 0 )
  {
    v4 -= 113;
    v6 = v5[3752];
    --v5;
    --v3;
    *(_BYTE *)(v4 + dword_19306C + a1 + 103) = v6;
  }
  --byte_1AAF5D;
  byte_1AAF7E[a1] = 1;
  if ( word_1AAF86 == word_1AAF5E )
  {
    if ( byte_1AAF88 == a1 )
      byte_1AAF88[0] = -1;
    byte_1AB072[a1] = 0;
    if ( (uint8_t)++byte_1AAF89 == word_199998 )
      byte_1AB03F = 11;
  }
  JUMPOUT(0xF88D2);
}
// FA977: control flows out of bounds to F88D2
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 1AAF5D: using guessed type char byte_1AAF5D;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF86: using guessed type int16_t word_1AAF86;
// 1AAF88: using guessed type char byte_1AAF88;
// 1AAF89: using guessed type char byte_1AAF89;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB09C: using guessed type int16_t word_1AB09C;


//----- (000FA97C) --------------------------------------------------------
void __usercall sub_FA97C(int a1, int a2)
{
  sub_FA7B0(a1, 55, a2);
}


//----- (000FA989) --------------------------------------------------------
void sub_FA989()
{
  JUMPOUT(0xFA982);
}
// FA98F: control flows out of bounds to FA982


//----- (000FA991) --------------------------------------------------------
unsigned int __fastcall sub_FA991(char *a1)
{
  dword_1AB0E4 = (int)a1;
  dword_1AB0E8 = (int)&a1[strlen(a1) + 1];
  dword_1AB0EC = strlen((char *)dword_1AB0E8) + 1 + dword_1AB0E8;
  dword_1AB100 = strlen((char *)dword_1AB0EC) + 1 + dword_1AB0EC;
  dword_1AB0E0 = strlen((char *)dword_1AB100) + 1 + dword_1AB100;
  dword_1AB0F4 = strlen((char *)dword_1AB0E0) + 1 + dword_1AB0E0;
  dword_1AB0FC = strlen((char *)dword_1AB0F4) + 1 + dword_1AB0F4;
  dword_1AB0F0 = strlen((char *)dword_1AB0FC) + 1 + dword_1AB0FC;
  dword_1AB0F8 = strlen((char *)dword_1AB0F0) + 1 + dword_1AB0F0;
  return dword_1AB0F8 + strlen((char *)dword_1AB0F8) + 1;
}
// 1AB0E0: using guessed type int dword_1AB0E0;
// 1AB0E4: using guessed type int dword_1AB0E4;
// 1AB0E8: using guessed type int dword_1AB0E8;
// 1AB0EC: using guessed type int dword_1AB0EC;
// 1AB0F0: using guessed type int dword_1AB0F0;
// 1AB0F4: using guessed type int dword_1AB0F4;
// 1AB0F8: using guessed type int dword_1AB0F8;
// 1AB0FC: using guessed type int dword_1AB0FC;
// 1AB100: using guessed type int dword_1AB100;


//----- (000FAA71) --------------------------------------------------------
int __userpurge sub_FAA71(int a1, int a2, int a3, int a4, int16_t *a5, int a6)
{
  int v7; // edx

  sub_FE8BE(a1, a2, a4, a5);
  v7 = sub_13982D(a1, a2, a4, a3, a6);
  sub_FE8BE(v7, v7, a4, a5);
  return v7;
}


//----- (000FAA94) --------------------------------------------------------
unsigned int sub_FAA94()
{
  unsigned int result; // eax

  sub_139062();
  for ( result = dword_197F98 + 30024; result > dword_197F98; result -= 3753 )
    *(_WORD *)(result - 3710) = -1;
  byte_1AB09E = 0;
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 1AB09E: using guessed type char byte_1AB09E;


//----- (000FAAC3) --------------------------------------------------------
int sub_FAAC3()
{
  int result; // eax
  _BYTE v1[20]; // [esp+0h] [ebp-14h] BYREF

  for ( result = sub_139294(v1); result; --result )
    ;
  return result;
}


//----- (000FAAD8) --------------------------------------------------------
char __usercall sub_FAAD8(int16_t *a1)
{
  int v1; // eax
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  int64_t v5; // rax
  _DWORD *v6; // eax
  int v7; // eax
  _BYTE v9[4]; // [esp+0h] [ebp-4h] BYREF

  sub_5C510(a1);
  *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 40) = 100;
  sub_F53CB();
  sub_8F1C4((void (__fastcall *)(int, int))sub_F19C7, v9, 11);
  v1 = sub_F19C7();
  sub_1077D(v1, (int)v9, 11, a1);
  word_1AAF70 = 0;
  v2 = 3753 * word_19999C + dword_197F98;
  byte_1AB03F = 7;
  v3 = sub_F6816(word_1AAF68, 1, v2, 0xEA9u);
  while ( !word_1AAF70 )
  {
    sub_1171AB(v3, 1, v2, 3753);
    v4 = sub_F19C7();
    v3 = sub_1077D(v4, 1, v2, a1);
  }
  sub_F54A0();
  HIDWORD(v5) = 2;
  strcpy((char *)&word_18FF78, (char *)dword_1AB108);
  sub_124D41();
  sub_F2C8B();
  for ( LODWORD(v5) = sub_1191CA((int)sub_F2C8B, 2); ; LODWORD(v5) = sub_1171AB(v5, SHIDWORD(v5), v2, 3753) )
  {
    sub_1077D(v5, SHIDWORD(v5), v2, &word_18FF78);
    if ( word_1AAF6E >= word_1AAF70 )
      break;
    v5 = sprintf(&word_18FF78, (char *)dword_1AB100, word_1AAF6E + 1, word_1AAF70);
    LODWORD(v5) = sub_F2C8B();
  }
  sub_F79F6((char *)dword_1AAF72, (int16_t *)dword_1AAF6A, 1);
  memset(byte_1AB09F, 0, sizeof(byte_1AB09F));
  dword_1AAF72 = 0;
  v6 = sub_1113CC(dword_192ED4, 0);
  word_1AAF70 = 0;
  byte_1AB03F = 4;
  sub_1279A(v6);
  sub_11C2F0();
  sub_119281();
  sub_8CF09((uint8_t)byte_199CB2, 0);
  sub_7962C();
  sub_1279F(v7);
  byte_19C1A0 = 1;
  sub_8A4C4();
  return 1;
}
// FAC6B: variable 'v7' is possibly undefined
// 1279A: using guessed type int __fastcall sub_1279A(_DWORD);
// 8CF09: using guessed type int64_t __fastcall sub_8CF09(_DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 18FF78: using guessed type int16_t word_18FF78;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199CB2: using guessed type char byte_199CB2;
// 19C1A0: using guessed type char byte_19C1A0;
// 1AAF68: using guessed type int16_t word_1AAF68;
// 1AAF6A: using guessed type int dword_1AAF6A;
// 1AAF6E: using guessed type int16_t word_1AAF6E;
// 1AAF70: using guessed type int16_t word_1AAF70;
// 1AAF72: using guessed type int dword_1AAF72;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB100: using guessed type int dword_1AB100;
// 1AB108: using guessed type int dword_1AB108;


//----- (000FAC85) --------------------------------------------------------
void __usercall sub_FAC85(int16_t *a1)
{
  int v1; // edx
  int v2; // eax
  int v3; // eax
  int16_t *v4; // edi
  int16_t *v5; // eax
  int64_t v6; // rax
  int v7; // edx
  int16_t v8; // ax
  int16_t *v9; // [esp-4h] [ebp-14h]
  _BYTE v10[8]; // [esp+0h] [ebp-10h] BYREF
  int v11; // [esp+8h] [ebp-8h] BYREF
  int16_t v12; // [esp+Ch] [ebp-4h]

  v11 = word_199998;
  v1 = 3753 * word_199998;
  while ( v11 > 0 )
  {
    --v11;
    v2 = *(int16_t *)(v1 + dword_197F98 - 3710);
    v1 -= 3753;
    v10[v11] = v2 != -1;
  }
  if ( (int16_t)sub_F0E17(v10, 1, 0, a1) == -1 )
  {
    v11 = -1;
    sub_F6816(word_1AAF68, 33, (int)&v11, 4u);
    JUMPOUT(0xFAC7E);
  }
  sub_11C2F0();
  sub_11438B(0, 0, 639, 479, &unk_17A174, 0);
  v11 = v12;
  byte_1AB03F = 7;
  sub_F6816(word_1AAF68, 33, (int)&v11, 4u);
  sub_1191CA((int)sub_F2C8B, 2);
  v3 = sub_F54A0();
  v9 = &word_18FF78;
  strcpy((char *)&word_18FF78, (char *)dword_1AB108);
  v4 = v9;
  while ( !word_1AAF70 )
  {
    sub_1171AB(v3, 2, (int)&v11, 4);
    sub_124D41();
    v5 = sub_F2C8B();
    v3 = sub_1077D((int)v5, 2, (int)&v11, v4);
  }
  while ( word_1AAF6E < word_1AAF70 )
  {
    v6 = sprintf(&word_18FF78, (char *)dword_1AB100, word_1AAF6E + 1, word_1AAF70);
    sub_1171AB(v6, SHIDWORD(v6), (int)&v11, 4);
    LODWORD(v6) = sub_F2C8B();
    sub_1077D(v6, SHIDWORD(v6), (int)&v11, v4);
  }
  sub_F79F6((char *)dword_1AAF72, (int16_t *)dword_1AAF6A, 1);
  memset(byte_1AB09F, 0, sizeof(byte_1AB09F));
  dword_1AAF72 = 0;
  sub_1113CC(dword_192ED4, 0);
  word_1AAF70 = 0;
  LOBYTE(word_18FF78) = 0;
  byte_1AAF5D = 0;
  word_19999C = -1;
  v11 = word_199998;
  v7 = 3753 * word_199998;
  while ( v11 > 0 )
  {
    v7 -= 3753;
    --v11;
    if ( *(_BYTE *)(v7 + dword_197F98 + 40) == 100 )
    {
      v8 = *(_WORD *)(v7 + dword_197F98 + 43);
      ++byte_1AAF5D;
      if ( v8 == word_1AAF5E )
        word_19999C = v11;
    }
  }
  JUMPOUT(0xFAC44);
}
// FACFF: control flows out of bounds to FAC7E
// FAE7B: control flows out of bounds to FAC44
// FAD7D: variable 'v3' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 18FF78: using guessed type int16_t word_18FF78;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 1AAF5D: using guessed type char byte_1AAF5D;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF68: using guessed type int16_t word_1AAF68;
// 1AAF6A: using guessed type int dword_1AAF6A;
// 1AAF6E: using guessed type int16_t word_1AAF6E;
// 1AAF70: using guessed type int16_t word_1AAF70;
// 1AAF72: using guessed type int dword_1AAF72;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB100: using guessed type int dword_1AB100;
// 1AB108: using guessed type int dword_1AB108;


//----- (000FAE80) --------------------------------------------------------
int __usercall sub_FAE80(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // ebx
  int64_t v5; // rax

  v5 = j___clock(a1, a2, a3);
  v4 = v5;
  sub_13D0F1(byte_1AAED5);
  LODWORD(v5) = sub_13CDA5();
  BYTE4(v5) = v5;
  if ( (_BYTE)v5 )
  {
    while ( !sub_13CFDD() )
    {
      v5 = j___clock(0, HIDWORD(v5), v4);
      LODWORD(v5) = v5 - v4;
      if ( (unsigned int)v5 >= 0x2328 )
        break;
      sub_FE8BE(v5, SHIDWORD(v5), v4, a4);
    }
    LODWORD(v5) = sub_13CFDD();
    BYTE4(v5) = v5;
  }
  if ( !BYTE4(v5) )
  {
    sub_77423(dword_1AB0E0);
    LODWORD(v5) = sub_139062();
  }
  LOBYTE(v5) = BYTE4(v5);
  return v5;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 1AB0E0: using guessed type int dword_1AB0E0;


//----- (000FAEDB) --------------------------------------------------------
char __usercall sub_FAEDB(int16_t *a1)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int v5; // edx
  int v6; // eax
  char result; // al
  unsigned int k; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int j; // eax
  char v13; // al
  unsigned int i; // eax
  _BYTE v15[4]; // [esp+0h] [ebp-8h] BYREF
  char v16; // [esp+4h] [ebp-4h]

  byte_1AB03F = 5;
  sub_FC6A5();
  sub_F54BE();
  sub_1191CA((int)sub_F19C7, 1);
  v16 = 0;
  sub_8F1C4((void (__fastcall *)(int, int))sub_F19C7, v15, 11);
  v1 = sub_F19C7();
  v2 = sub_1077D(v1, (int)v15, 11, a1);
  if ( byte_1AAF58 || (v2 = sub_127880()) == 0 )
  {
    sub_FE8BE(v2, (int)v15, 11, a1);
  }
  else
  {
    v16 = 0;
    LOWORD(v3) = sub_77423(dword_1AB0E4);
    byte_1AB03F = 0;
    word_199A08 = 15;
  }
  v4 = (uint8_t)byte_1AAF58;
  sub_FE8BE(v3, 23, (int)sub_F67C1, a1);
  v5 = sub_138F3B(v4, 23, (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))sub_F67C1, (int)&dword_1AAEC4);
  sub_FE8BE(v5, v5, (int)sub_F67C1, a1);
  if ( !v5 )
  {
    sub_FE8BE(v6, 0, (int)sub_F67C1, a1);
    v16 = 0;
    sub_77423(dword_1AB0E8);
    byte_1AB03F = 0;
    word_199A08 = 15;
    return v16;
  }
  if ( byte_1AAF58 )
  {
    sub_139358();
    if ( byte_1AAF58 == 1 )
    {
      result = sub_FAE80(v9, v5, (int)sub_F67C1, a1);
      if ( !result )
      {
        word_199A08 = 15;
        byte_1AB03F = 0;
        return result;
      }
    }
    goto LABEL_19;
  }
  sub_F0C8E(a1);
  if ( !LOBYTE(byte_1AB082[0]) )
  {
    byte_1AB03F = 0;
    word_199A08 = 15;
    return 0;
  }
  if ( sub_13974F((int)byte_1AB082) )
  {
LABEL_19:
    byte_1AB09E = 1;
    word_1AAF5E = sub_139447();
    sub_F54CF();
    sub_11C2F0();
    sub_11438B(0, 0, 639, 479, &unk_17A174, 0);
    sub_1191CA((int)sub_F19C7, 2);
    memset(byte_19B814, 0, sizeof(byte_19B814));
    v10 = memset(byte_19B848, 0, sizeof(byte_19B848));
    while ( byte_1AB03F == 5 )
    {
      sub_1171AB(v10, 0, 14, 479);
      v11 = sub_F19C7();
      v10 = sub_1077D(v11, 0, 14, a1);
    }
    if ( byte_1AB03F != 45 )
    {
      if ( byte_1AB03F == 6 )
      {
        sub_F6816(word_1AAF68, 66, (int)&dword_192EF0, 4u);
        return sub_FAAD8(a1);
      }
      else if ( byte_1AB03F == 44 )
      {
        sub_F6816(word_1AAF68, 66, (int)&dword_192EF0, 4u);
        sub_FAC85(a1);
        v16 = v13;
        if ( !v13 )
        {
          word_199A08 = 15;
          byte_1AB03F = 0;
          sub_139062();
          for ( i = dword_197F98 + 30024; i > dword_197F98; i -= 3753 )
            *(_WORD *)(i - 3710) = -1;
          byte_1AB09E = 0;
        }
      }
      return v16;
    }
    byte_1AB03F = 0;
    word_199A08 = 15;
    sub_139062();
    for ( j = dword_197F98 + 30024; j > dword_197F98; j -= 3753 )
      *(_WORD *)(j - 3710) = -1;
    byte_1AB09E = 0;
    sub_77423(dword_1AB0F4);
    return 0;
  }
  sub_77423(dword_1AB0EC);
  byte_1AB03F = 0;
  word_199A08 = 15;
  sub_139062();
  for ( k = dword_197F98 + 30024; k > dword_197F98; k -= 3753 )
    *(_WORD *)(k - 3710) = -1;
  byte_1AB09E = 0;
  return 0;
}
// FAF70: variable 'v3' is possibly undefined
// FAF87: variable 'v6' is possibly undefined
// FB05C: variable 'v9' is possibly undefined
// FB1A6: variable 'v13' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192EF0: using guessed type int dword_192EF0;
// 197F98: using guessed type int dword_197F98;
// 199A08: using guessed type int16_t word_199A08;
// 1AAEC4: using guessed type int dword_1AAEC4;
// 1AAF58: using guessed type char byte_1AAF58;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF68: using guessed type int16_t word_1AAF68;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB082: using guessed type int16_t byte_1AB082[2];
// 1AB09E: using guessed type char byte_1AB09E;
// 1AB0E4: using guessed type int dword_1AB0E4;
// 1AB0E8: using guessed type int dword_1AB0E8;
// 1AB0EC: using guessed type int dword_1AB0EC;
// 1AB0F4: using guessed type int dword_1AB0F4;


//----- (000FB1F2) --------------------------------------------------------
char __fastcall sub_FB1F2(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  int64_t v5; // rax
  unsigned int v6; // kr04_4
  char v8[80]; // [esp+0h] [ebp-50h] BYREF

  v5 = j___clock(a1, a1, a3);
  v4 = v5;
  BYTE4(v5) = sub_13CE01(SHIDWORD(v5), SHIDWORD(v5), v5, a4);
  if ( BYTE4(v5) )
  {
    sub_13CED8(v8, SHIDWORD(v5), v4);
    v6 = strlen(v8) + 1;
    if ( v6 - 1 > 1 )
    {
      sub_77423((int)v8);
      sub_139062();
      return 0;
    }
    while ( !sub_13CFDD() )
    {
      v5 = j___clock(0, HIDWORD(v5), v4);
      LODWORD(v5) = v5 - v4;
      if ( (unsigned int)v5 >= 0x2328 )
        break;
      sub_FE8BE(v5, SHIDWORD(v5), v4, (int16_t *)&v8[v6]);
    }
    BYTE4(v5) = sub_13CFDD();
  }
  if ( !BYTE4(v5) )
  {
    sub_77423(dword_1AB0FC);
    sub_139062();
  }
  return BYTE4(v5);
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 1AB0FC: using guessed type int dword_1AB0FC;


//----- (000FB27B) --------------------------------------------------------
void __usercall sub_FB27B(int16_t *a1)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int *v4; // ecx
  int v5; // ebx
  int v6; // esi
  int16_t *v7; // edx
  unsigned int i; // eax
  int v9; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ebx
  int v21; // edx
  int v22; // eax
  int j; // ebx
  unsigned int k; // eax
  int v25; // eax
  int v26; // ebx
  int m; // eax
  int v28; // ebx
  int v29; // eax
  int v30; // edx
  int v31; // eax
  _BYTE v33[256]; // [esp+0h] [ebp-174h] BYREF
  _BYTE v34[46]; // [esp+100h] [ebp-74h] BYREF
  char v35[50]; // [esp+12Eh] [ebp-46h] BYREF
  _BYTE v36[8]; // [esp+160h] [ebp-14h] BYREF
  int v37; // [esp+168h] [ebp-Ch]
  char v38[4]; // [esp+16Ch] [ebp-8h] BYREF
  char v39; // [esp+170h] [ebp-4h]

  byte_1AB03F = 36;
  sub_FC6A5();
  sub_F54BE();
  sub_1191CA((int)sub_F19C7, 1);
  sub_8F1C4((void (__fastcall *)(int, int))sub_F19C7, v38, 11);
  v1 = sub_F19C7();
  v2 = sub_1077D(v1, (int)v38, 11, a1);
  if ( !byte_1AAF58 )
  {
    v2 = sub_127880();
    if ( v2 )
    {
      v3 = dword_1AB0E4;
LABEL_4:
      sub_77423(v3);
      byte_1AB03F = 0;
      word_199A08 = 15;
      goto LABEL_66;
    }
  }
  v4 = &dword_1AAEC4;
  v5 = (int)sub_F67C1;
  v6 = (uint8_t)byte_1AAF58;
  sub_FE8BE(v2, 23, (int)sub_F67C1, a1);
  v7 = (int16_t *)sub_138F3B(v6, 23, (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))sub_F67C1, (int)&dword_1AAEC4);
  sub_FE8BE((int)v7, (int)v7, (int)sub_F67C1, a1);
  if ( !v7 )
  {
    v3 = dword_1AB0E8;
    goto LABEL_4;
  }
  if ( !byte_1AAF58 )
  {
    v4 = (int *)&unk_17A174;
    v5 = 8;
    v7 = byte_1AB082;
    if ( !sub_FAA71(23, (int)byte_1AB082, (int)&unk_17A174, 8, a1, (int)aMyname) )
    {
      sub_77423(dword_1AB0E8);
      byte_1AB03F = 0;
      word_199A08 = 15;
      sub_139062();
      for ( i = dword_197F98 + 30024; i > dword_197F98; i -= 3753 )
        *(_WORD *)(i - 3710) = -1;
      byte_1AB09E = 0;
      goto LABEL_66;
    }
  }
  if ( byte_1AAF58 == 2 || byte_1AAF58 == 1 )
  {
    sub_139387();
    if ( byte_1AAF58 == 1 && !sub_FB1F2((int)byte_1AAED5, (int)v7, v5, (int)v4) )
    {
      word_199A08 = 15;
      byte_1AB03F = 0;
      goto LABEL_66;
    }
  }
  sub_11C2F0();
  sub_11438B(0, 0, 639, 479, &unk_17A174, 0);
  sub_1191CA((int)nullsub_15, 2);
  byte_1AB09E = 1;
  word_1AAF5E = sub_139447();
  word_1AAF68 = word_1AAF5E;
  byte_1AB0C1 = dword_192EF0 != 0;
  memset(v36, 0, sizeof(v36));
  v9 = (int16_t)sub_F0E17(v36, 1, 0, a1);
  sub_11C2F0();
  sub_11438B(0, 0, 639, 479, &unk_17A174, 0);
  if ( v9 == -1 )
  {
    byte_1AB03F = 0;
    word_199A08 = 15;
    goto LABEL_66;
  }
  v10 = (int16_t)v37;
  v36[(int16_t)v37] = 1;
  v11 = 1;
  *(_WORD *)(dword_197F98 + 3753 * v10 + 43) = word_1AAF5E;
  v39 = 0;
  v12 = 2;
  word_19999C = v37;
  dword_1AAF59 = -1;
  sub_1191CA((int)sub_F2DE5, 2);
  sub_F552A();
  sub_11C2F0();
  sub_F0801();
  byte_1AAF5D = 0;
  v13 = word_199998;
  v14 = 3753 * word_199998;
  while ( v14 > 0 )
  {
    v14 -= 3753;
    --v13;
    if ( *(_BYTE *)(dword_197F98 + v14 + 40) == 100 )
      ++byte_1AAF5D;
  }
  while ( 1 )
  {
    if ( v39 )
    {
      if ( !byte_1AAF58 || byte_1AAF58 == 3 )
        sub_13998F(v14, v12);
      sub_1191CA((int)nullsub_15, 2);
      v20 = word_199998;
      byte_1AAF5D = 0;
      v21 = 3753 * word_199998;
      while ( v20 > 0 )
      {
        v21 -= 3753;
        v22 = v21 + dword_197F98;
        --v20;
        if ( *(int16_t *)(v21 + dword_197F98 + 43) == -1 )
        {
          if ( *(_BYTE *)(v22 + 40) == 100 )
            sub_FEC20(v20, (int)a1);
        }
        else
        {
          *(_BYTE *)(v22 + 40) = 100;
          ++byte_1AAF5D;
        }
      }
      for ( j = word_199998; j > 0; sub_E2D72((int16_t)j, (int)a1) )
        --j;
      if ( !byte_1AB0C1 )
      {
        byte_199F0D = 0;
        for ( k = dword_19306C + 113 * word_19999A; k > dword_19306C; k -= 113 )
          *(_BYTE *)(k - 2) = 0;
      }
      LOBYTE(word_18FF78) = 0;
      sub_F54D9();
      sub_124D41();
      sub_F2C8B();
      v25 = sub_1191CA((int)sub_F2C8B, 2);
      sub_1077D(v25, 2, j, a1);
      v26 = word_199998;
      for ( m = 12 * word_199998; m > 0; m -= 12 )
      {
        byte_1AAF7F[m] = 4;
        --v26;
        byte_1AAF8A[m] = -1;
      }
      v28 = word_199998;
      v34[40] = word_199998;
      v29 = 4 * word_199998;
      v30 = 3753 * word_199998;
      while ( v29 > 0 )
      {
        v30 -= 3753;
        v29 -= 4;
        --v28;
        *(_DWORD *)&v34[v29 + 6] = *(int16_t *)(dword_197F98 + v30 + 43);
      }
      sprintf(v35, "%s", aMay222006_0);
      sub_F6816(32766, 42, (int)v34, 0x60u);
      dword_1849E2 = (uint8_t)byte_1AAF5D;
      word_1AB09C = word_1AAF5E;
      sub_F74CD(1, 42, 8);
      byte_1AB094[word_19999C] = 1;
      memset(byte_1AB09F, 0, sizeof(byte_1AB09F));
      byte_1AB03F = 4;
      sub_11C2F0();
      sub_119281();
      sub_8CF09((uint8_t)byte_199CB2, 0);
      sub_7962C();
      byte_19C1A0 = 1;
      sub_1279F(v31);
      sub_8A4C4();
LABEL_66:
      JUMPOUT(0xFB1EC);
    }
    if ( dword_1AAF59 == -1 )
    {
      v13 = sub_139294(v33);
      while ( v13 > 0 && dword_1AAF59 == -1 )
      {
        v15 = (uint8_t)v33[--v13];
        if ( sub_FA16C(v15) == -1 )
        {
          v16 = (uint8_t)v33[v13];
          ++v11;
          dword_1AAF59 = v16;
          sub_FA05D(v16);
        }
      }
    }
    v17 = sub_F2DE5();
    v18 = sub_1077D(v17, v12, v13, a1);
    if ( dword_1AAF59 == -1 )
    {
      v18 = (uint8_t)byte_1AAF5D;
      if ( v11 == (uint8_t)byte_1AAF5D || v11 == 2 && (byte_1AAF58 == 1 || byte_1AAF58 == 2) )
        goto LABEL_41;
      v18 = sub_139294(0);
      if ( v11 == v18 )
      {
        v12 = dword_192680;
        v18 = sub_1171AB(v18, dword_192680, v13, v11);
        if ( (_WORD)v18 == *(_WORD *)(v12 + 237) )
          break;
      }
    }
LABEL_42:
    sub_FE8BE(v18, v12, v13, a1);
    v19 = sub_F2DE5();
    v14 = sub_1077D(v19, v12, v13, a1);
  }
  v18 = (uint8_t)byte_1AAF5D;
  if ( v11 < (uint8_t)byte_1AAF5D )
  {
    sub_77658(dword_1AB0F0);
    v39 = v18;
    goto LABEL_42;
  }
LABEL_41:
  v39 = 1;
  goto LABEL_42;
}
// FB3D8: control flows out of bounds to FB1EC
// FB5E2: variable 'v18' is possibly undefined
// FB7D4: variable 'v31' is possibly undefined
// 8CF09: using guessed type int64_t __fastcall sub_8CF09(_DWORD, _DWORD);
// FE8D4: using guessed type int __fastcall nullsub_15(_DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1849E2: using guessed type int dword_1849E2;
// 18FF78: using guessed type int16_t word_18FF78;
// 192680: using guessed type int dword_192680;
// 192EF0: using guessed type int dword_192EF0;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199CB2: using guessed type char byte_199CB2;
// 199F0D: using guessed type char byte_199F0D;
// 19C1A0: using guessed type char byte_19C1A0;
// 1AAEC4: using guessed type int dword_1AAEC4;
// 1AAF58: using guessed type char byte_1AAF58;
// 1AAF59: using guessed type int dword_1AAF59;
// 1AAF5D: using guessed type char byte_1AAF5D;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF68: using guessed type int16_t word_1AAF68;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB082: using guessed type int16_t byte_1AB082[2];
// 1AB09C: using guessed type int16_t word_1AB09C;
// 1AB09E: using guessed type char byte_1AB09E;
// 1AB0C1: using guessed type char byte_1AB0C1;
// 1AB0E4: using guessed type int dword_1AB0E4;
// 1AB0E8: using guessed type int dword_1AB0E8;
// 1AB0F0: using guessed type int dword_1AB0F0;


//----- (000FB7E5) --------------------------------------------------------
void __usercall sub_FB7E5(int16_t *a1)
{
  int v1; // eax
  int v2; // eax
  int *v3; // ecx
  int v4; // ebx
  int v5; // esi
  int16_t *v6; // edx
  unsigned int ii; // eax
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int i; // eax
  int v13; // esi
  int v14; // eax
  int v15; // ebx
  int16_t v16; // dx
  int16_t j; // dx
  int16_t v18; // dx
  int k; // eax
  int v20; // esi
  int m; // eax
  int v22; // eax
  int v23; // edx
  int v24; // ebx
  int v25; // eax
  int v26; // esi
  int v27; // eax
  int v28; // esi
  int v29; // eax
  int v30; // ebx
  int v31; // esi
  int v32; // edi
  int v33; // esi
  int16_t *v34; // edi
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  int v38; // esi
  int n; // eax
  int v40; // eax
  _BYTE v42[256]; // [esp+0h] [ebp-112h] BYREF
  int v43; // [esp+100h] [ebp-12h] BYREF
  int16_t v44; // [esp+104h] [ebp-Eh]
  _DWORD v45[8]; // [esp+106h] [ebp-Ch] BYREF
  char v46; // [esp+126h] [ebp+14h]
  char v47; // [esp+127h] [ebp+15h]
  char v48; // [esp+128h] [ebp+16h]
  char v49; // [esp+129h] [ebp+17h]
  char v50; // [esp+12Ah] [ebp+18h]
  char v51; // [esp+12Bh] [ebp+19h]
  char v52; // [esp+12Ch] [ebp+1Ah]
  char v53; // [esp+12Dh] [ebp+1Bh]
  _BYTE v54[50]; // [esp+12Eh] [ebp+1Ch] BYREF
  _BYTE v55[20]; // [esp+160h] [ebp+4Eh] BYREF
  _BYTE v56[20]; // [esp+174h] [ebp+62h] BYREF
  _BYTE v57[8]; // [esp+188h] [ebp+76h] BYREF
  _BYTE v58[4]; // [esp+190h] [ebp+7Eh] BYREF

  byte_1AB03F = 1;
  sub_FC6A5();
  sub_F54BE();
  sub_1191CA((int)sub_F19C7, 1);
  sub_8F1C4((void (__fastcall *)(int, int))sub_F19C7, v58, 11);
  v1 = sub_F19C7();
  v2 = sub_1077D(v1, (int)v58, 11, a1);
  if ( byte_1AAF58 || (v2 = sub_127880()) == 0 )
  {
    v3 = &dword_1AAEC4;
    v4 = (int)sub_F67C1;
    v5 = (uint8_t)byte_1AAF58;
    sub_FE8BE(v2, 23, (int)sub_F67C1, a1);
    v6 = (int16_t *)sub_138F3B(
                      v5,
                      23,
                      (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))sub_F67C1,
                      (int)&dword_1AAEC4);
    sub_FE8BE((int)v6, (int)v6, (int)sub_F67C1, a1);
    if ( v6 )
    {
      if ( byte_1AAF58
        || (v3 = (int *)&unk_17A174,
            v4 = 8,
            v6 = byte_1AB082,
            sub_FAA71(23, (int)byte_1AB082, (int)&unk_17A174, 8, a1, (int)aMyname)) )
      {
        if ( (byte_1AAF58 == 2 || byte_1AAF58 == 1)
          && (sub_139387(), byte_1AAF58 == 1)
          && !sub_FB1F2((int)byte_1AAED5, (int)v6, v4, (int)v3) )
        {
          word_199A08 = 15;
          byte_1AB03F = 0;
        }
        else
        {
          byte_1AB09E = 1;
          word_1AAF5E = sub_139447();
          word_1AAF68 = word_1AAF5E;
          byte_1AB0C1 = dword_192EF0 != 0;
          if ( !byte_1AAF58 || byte_1AAF58 == 3 )
          {
            sub_F552A();
            sub_11C2F0();
            sub_F0801();
            v8 = 2;
            sub_1191CA((int)sub_F2DE5, 2);
            v9 = sub_F2DE5();
            v10 = sub_1077D(v9, 2, v4, a1);
            do
            {
              v8 = (int16_t)sub_1171AB(v10, v8, v4, (int)v3);
              v11 = sub_F2DE5();
              v10 = sub_1077D(v11, v8, v4, a1);
              if ( v8 )
              {
                v10 = sub_139294(0);
                if ( v10 == 1 )
                {
                  sub_77658(dword_1AB0F8);
                  v8 = (int16_t)v10;
                }
              }
              if ( v8 )
                break;
              v8 = (uint8_t)byte_199CB1;
              v10 = sub_139294(0);
            }
            while ( v10 < v8 );
            sub_13998F(v10, v8);
          }
          byte_1AAF5D = sub_139294(v42);
          if ( (uint8_t)byte_1AAF5D > (uint8_t)byte_199CB1 )
            byte_1AAF5D = byte_199CB1;
          for ( i = sub_139294(v56); i; --i )
            ;
          byte_1AB03F = 2;
          memset(v45, 0, sizeof(v45));
          v13 = (uint8_t)byte_1AAF5D;
          word_19999C = -1;
          v14 = (uint8_t)byte_1AAF5D;
          v15 = 3753 * (uint8_t)byte_1AAF5D;
          while ( v13 > 0 )
          {
            *(_WORD *)(dword_197F98 + v15 - 3710) = (uint8_t)v42[v13 - 1];
            --v14;
            v15 -= 3753;
            v45[v14] = (uint8_t)v42[v13 - 1];
            v16 = (uint8_t)v42[--v13];
            if ( v16 == word_1AAF5E )
              word_19999C = v13;
            for ( j = 0; j < v13; ++j )
              ;
          }
          if ( word_19999C == -1 )
          {
            v18 = word_1AAF5E;
            *(_WORD *)(dword_197F98 + 43) = word_1AAF5E;
            word_19999C = 0;
            v45[0] = v18;
          }
          for ( k = sub_139294(v55); k; --k )
            ;
          word_199998 = (uint8_t)byte_199CB1;
          v44 = (uint8_t)byte_1AAF5D;
          v43 = word_1AAF5E;
          v46 = byte_199BDE;
          v47 = byte_199CB0;
          v48 = byte_199CB1;
          v49 = byte_199CB2;
          v50 = byte_199CB3;
          v51 = byte_199CB4;
          v52 = byte_199CB5;
          v53 = byte_199CAF;
          sprintf(v54, "%s", aMay222006_0);
          memset(byte_1AAF60, 0, 8);
          memset(byte_19B814, 0, sizeof(byte_19B814));
          memset(byte_19B848, 0, sizeof(byte_19B848));
          memset(byte_1AB08B, 0, sizeof(byte_1AB08B));
          v20 = word_199998;
          byte_1AB03F = 3;
          for ( m = 3753 * word_199998; m > 0; *(_BYTE *)(dword_197F98 + m + 38) = 8 )
          {
            m -= 3753;
            --v20;
          }
          sub_5C510(a1);
          v22 = word_19999C;
          byte_1AB08B[word_19999C] = 1;
          v22 *= 3753;
          v23 = dword_197F98;
          *(_BYTE *)(dword_197F98 + v22 + 40) = 100;
          sub_FE8BE(v22, v23, (int)&v43, a1);
          sub_F6816(32766, 0, (int)&v43, 0x60u);
          sub_F551B();
          sub_8F1C4((void (__fastcall *)(int, int))sub_F19C7, v58, 11);
          v24 = 0;
          byte_1AAF60[word_19999C] = 1;
          while ( v24 < (uint8_t)byte_1AAF5D )
          {
            sub_F2F4E();
            v26 = word_199998;
            v24 = 0;
            while ( v26 > 0 )
            {
              if ( byte_1AAF60[--v26] )
                ++v24;
            }
            v27 = sub_1171AB(v25, (int)v58, v24, 96);
            sub_1077D(v27, (int)v58, v24, a1);
          }
          sub_11C2F0();
          sub_119281();
          sub_12479((uint8_t)byte_199CB4, (uint8_t)byte_199CB5);
          v28 = (uint8_t)byte_1AAF5D;
          v29 = 3753 * (uint8_t)byte_1AAF5D;
          while ( v28 < word_199998 )
          {
            v29 += 3753;
            ++v28;
            *(_WORD *)(dword_197F98 + v29 - 3710) = -1;
          }
          v30 = 8;
          memset(v57, 0, sizeof(v57));
          v31 = 0;
          v32 = 0;
          while ( v31 < word_199998 )
          {
            if ( *(_BYTE *)(v32 + dword_197F98 + 38) != 8 )
              v57[*(uint8_t *)(v32 + dword_197F98 + 38)] = 1;
            v32 += 3753;
            ++v31;
          }
          v33 = 0;
          v34 = 0;
          while ( v33 < word_199998 )
          {
            if ( *((_BYTE *)v34 + dword_197F98 + 38) == 8 )
            {
              v35 = -1;
              v30 = 8;
              v36 = 0;
              do
              {
                if ( !v57[--v30] && sub_1247A0(++v36) == 1 )
                  v35 = v30;
              }
              while ( v30 > 0 );
              *((_BYTE *)v34 + dword_197F98 + 38) = v35;
              v57[v35] = 1;
            }
            v34 = (int16_t *)((char *)v34 + 3753);
            ++v33;
          }
          sub_F54D9();
          sub_124D41();
          sub_F2C8B();
          v37 = sub_1191CA((int)sub_F2C8B, 2);
          sub_1077D(v37, 2, v30, v34);
          if ( !byte_1AB0C1 )
            byte_199F0D = 0;
          v38 = word_199998;
          for ( n = 12 * word_199998; n > 0; n -= 12 )
          {
            byte_1AAF7F[n] = 4;
            --v38;
            byte_1AAF8A[n] = -1;
          }
          dword_1849E2 = (uint8_t)byte_1AAF5D;
          word_1AB09C = word_1AAF5E;
          sub_F74CD(1, 2, 8);
          byte_1AB094[word_19999C] = 1;
          memset(byte_1AB09F, 0, sizeof(byte_1AB09F));
          byte_1AB03F = 4;
          sub_11C2F0();
          sub_119281();
          sub_8CF09((uint8_t)byte_199CB2, 0);
          sub_7962C();
          sub_1279F(v40);
          byte_19C1A0 = 1;
          sub_8A4C4();
        }
      }
      else
      {
        sub_77423(dword_1AB0E8);
        byte_1AB03F = 0;
        word_199A08 = 15;
        sub_139062();
        for ( ii = dword_197F98 + 30024; ii > dword_197F98; ii -= 3753 )
          *(_WORD *)(ii - 3710) = -1;
        byte_1AB09E = 0;
      }
LABEL_78:
      JUMPOUT(0xFAC7F);
    }
    byte_1AB03F = 0;
    sub_77423(dword_1AB0E8);
  }
  else
  {
    sub_77423(dword_1AB0E4);
    byte_1AB03F = 0;
  }
  word_199A08 = 15;
  goto LABEL_78;
}
// FBE70: control flows out of bounds to FAC7F
// FB9EF: variable 'v10' is possibly undefined
// FBC8D: variable 'v25' is possibly undefined
// FBE52: variable 'v40' is possibly undefined
// 12479: using guessed type _DWORD __stdcall sub_12479(_DWORD, _DWORD);
// 8CF09: using guessed type int64_t __fastcall sub_8CF09(_DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1849E2: using guessed type int dword_1849E2;
// 192EF0: using guessed type int dword_192EF0;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199BDE: using guessed type char byte_199BDE;
// 199CAF: using guessed type char byte_199CAF;
// 199CB0: using guessed type char byte_199CB0;
// 199CB1: using guessed type char byte_199CB1;
// 199CB2: using guessed type char byte_199CB2;
// 199CB3: using guessed type char byte_199CB3;
// 199CB4: using guessed type char byte_199CB4;
// 199CB5: using guessed type char byte_199CB5;
// 199F0D: using guessed type char byte_199F0D;
// 19C1A0: using guessed type char byte_19C1A0;
// 1AAEC4: using guessed type int dword_1AAEC4;
// 1AAF58: using guessed type char byte_1AAF58;
// 1AAF5D: using guessed type char byte_1AAF5D;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF68: using guessed type int16_t word_1AAF68;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB082: using guessed type int16_t byte_1AB082[2];
// 1AB09C: using guessed type int16_t word_1AB09C;
// 1AB09E: using guessed type char byte_1AB09E;
// 1AB0C1: using guessed type char byte_1AB0C1;
// 1AB0E4: using guessed type int dword_1AB0E4;
// 1AB0E8: using guessed type int dword_1AB0E8;
// 1AB0F8: using guessed type int dword_1AB0F8;


//----- (000FBE75) --------------------------------------------------------
_BOOL1 __usercall sub_FBE75( unsigned int a1, int16_t *a2)
{
  _BYTE v3[4]; // [esp+0h] [ebp-4h] BYREF

  v3[0] = a1;
  if ( byte_19B814[a1] )
    return 0;
  sub_F6816(word_1AAF68, 44, (int)v3, 1u);
  while ( !byte_19B814[v3[0]] )
    sub_FE8BE(v3[0], 44, (int)v3, a2);
  return *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 38) == v3[0];
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 1AAF68: using guessed type int16_t word_1AAF68;


//----- (000FBEE1) --------------------------------------------------------
_BOOL1 __usercall sub_FBEE1( int a1, int a2, int a3, int16_t *a4)
{
  _BYTE v5[4]; // [esp+0h] [ebp-4h] BYREF

  v5[0] = a1;
  while ( byte_1AB0BF )
    sub_FE8BE(a1, a2, a3, a4);
  *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 37) = 14;
  if ( byte_19B848[v5[0]] )
    return 0;
  sub_F6816(word_1AAF68, 58, (int)v5, 1u);
  while ( !byte_19B848[v5[0]] )
    sub_FE8BE(v5[0], 58, (int)v5, a4);
  return *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 37) == v5[0];
}
// FBEF4: variable 'a1' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 1AAF68: using guessed type int16_t word_1AAF68;
// 1AB0BF: using guessed type char byte_1AB0BF;


//----- (000FBF76) --------------------------------------------------------
int __fastcall sub_FBF76( unsigned int a1)
{
  _BYTE v2[4]; // [esp+0h] [ebp-4h] BYREF

  v2[0] = a1;
  byte_19B848[a1] = 0;
  byte_1AB0BF = 1;
  return sub_F6816(word_1AAF68, 62, (int)v2, 1u);
}
// 1AAF68: using guessed type int16_t word_1AAF68;
// 1AB0BF: using guessed type char byte_1AB0BF;


//----- (000FBFAF) --------------------------------------------------------
unsigned int __fastcall sub_FBFAF(char *a1)
{
  dword_1AB108 = (int)a1;
  dword_1AB104 = (int)&a1[strlen(a1) + 1];
  return dword_1AB104 + strlen((char *)dword_1AB104) + 1;
}
// 1AB104: using guessed type int dword_1AB104;
// 1AB108: using guessed type int dword_1AB108;


//----- (000FBFE2) --------------------------------------------------------
int __fastcall sub_FBFE2(int a1, int a2, int a3, int a4)
{
  int v4; // ebp
  int v5; // eax
  int v6; // esi
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ebx
  int v12; // edx
  int16_t *v13; // edi
  int i; // eax
  int v15; // esi
  int v16; // edi
  int v17; // eax
  int result; // eax
  int v19; // esi
  int j; // eax
  int v21; // [esp+0h] [ebp-4h]

  v5 = word_199998;
  byte_1AAF89 = 0;
  v6 = 3753 * word_199998;
  while ( v5 > 0 )
  {
    v6 -= 3753;
    --v5;
    a2 = *(_BYTE *)(v6 + dword_197F98 + 40) != 100;
    if ( *(_BYTE *)(v6 + dword_197F98 + 40) == 100 )
    {
      a2 = word_19999C;
      if ( v5 != word_19999C && !*(_BYTE *)(v6 + dword_197F98 + 36) )
        continue;
    }
    ++byte_1AAF89;
    byte_1AB06A[v5] = 1;
  }
  LOWORD(v5) = (uint8_t)byte_1AAF89;
  if ( (uint8_t)byte_1AAF89 >= word_199998 )
    byte_1AB03F = 11;
  else
    byte_1AB03F = 9;
  while ( byte_1AB03F != 11 )
  {
    v7 = 0;
    do
    {
      sub_F55A4(v5, a2, v7, a4);
      if ( byte_1AAF7E[v7] && byte_1AB072[v7] )
      {
        byte_1AB072[v7] = 0;
        byte_1AAF88[0] = v7;
      }
      ++v7;
      if ( byte_1AAF88[0] != -1 )
        break;
      v5 = word_199998;
    }
    while ( v7 < word_199998 );
    v5 = byte_1AAF88[0];
    if ( byte_1AAF88[0] != -1 )
    {
      a4 = 0;
      v8 = *(int16_t *)(dword_197F98 + 3753 * byte_1AAF88[0] + 43);
      byte_1AB03F = 10;
      v9 = sub_F6816(v8, 12, 0, 0);
      while ( byte_1AB03F == 10 )
        v9 = sub_F55A4(v9, 12, 0, 0);
      a2 = dword_1AAF6A;
      sub_F83D8((char *)dword_1AAF72, dword_1AAF6A, 0);
      dword_1AAF72 = 0;
      sub_1113CC(dword_192ED4, a2);
      v5 = byte_1AAF88[0];
      word_1AAF70 = 0;
      byte_1AB06A[byte_1AAF88[0]] = 1;
      byte_1AAF88[0] = -1;
    }
  }
  v10 = sub_8A4C4();
  nullsub_12(v10);
  v11 = 180;
  v12 = 0;
  byte_1AB04B = 0;
  memset(byte_1AAF8B, 0, 180);
  v13 = (int16_t *)word_199998;
  for ( i = 12 * word_199998; i > 0; i -= 12 )
  {
    byte_1AAF88[i] = -1;
    v13 = (int16_t *)((char *)v13 - 1);
    byte_1AAF7F[i] = 14;
  }
  byte_1AB03F = 14;
  sub_13870(i, 0, a4, 180, v4, v13, v6);
  word_1AB09C = word_1AAF5E;
  sub_FC6A5();
  v15 = word_199998;
  byte_1AB068 = 0;
  v16 = 3753 * word_199998;
  while ( v15 > 0 )
  {
    --v15;
    v16 -= 3753;
    if ( v15 != word_19999C )
    {
      v12 = *(int16_t *)(v16 + dword_197F98 + 43);
      v21 = v12;
      if ( v12 != -1 )
      {
        if ( *(_BYTE *)(v16 + dword_197F98 + 36) )
        {
          v12 = 59;
          v11 = 0;
          sub_F6816(v21, 59, 0, 0);
          v17 = dword_197F98;
          *(_BYTE *)(v16 + dword_197F98 + 40) = 0;
          *(_WORD *)(v16 + v17 + 43) = -1;
          --byte_1AAF5D;
          sub_FE8BE(v17, 59, 0, (int16_t *)v16);
        }
      }
    }
  }
  sub_F74CD(0, v12, v11);
  result = word_19999C;
  if ( !*(_BYTE *)(3753 * word_19999C + dword_197F98 + 36) )
  {
    byte_1AB094[word_19999C] = 1;
    memset(byte_1AB09F, 0, sizeof(byte_1AB09F));
    v19 = word_199998;
    byte_1AB03F = 4;
    for ( j = 12 * word_199998; j > 0; j -= 12 )
    {
      byte_1AAF7F[j] = 4;
      --v19;
      byte_1AAF8A[j] = -1;
    }
    result = sub_8A4C4();
    if ( byte_1AAF5D == 1 )
    {
      sub_FAA94();
      result = word_19999C;
      byte_199F3A = 0;
      byte_1AB124[word_19999C] = 1;
    }
  }
  return result;
}
// FC180: variable 'v4' is possibly undefined
// E5407: using guessed type int __fastcall nullsub_12(_DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;
// 1AAF5D: using guessed type char byte_1AAF5D;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF6A: using guessed type int dword_1AAF6A;
// 1AAF70: using guessed type int16_t word_1AAF70;
// 1AAF72: using guessed type int dword_1AAF72;
// 1AAF89: using guessed type char byte_1AAF89;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB04B: using guessed type char byte_1AB04B;
// 1AB068: using guessed type char byte_1AB068;
// 1AB09C: using guessed type int16_t word_1AB09C;


//----- (000FC299) --------------------------------------------------------
char sub_FC299()
{
  int v0; // eax
  int v1; // edx

  v0 = word_199998;
  while ( v0 > 0 )
  {
    v1 = word_199998;
    --v0;
    while ( v1 > 0 )
    {
      if ( (((int)(uint8_t)byte_1AB055[v0] >> --v1) & 1) != 0 )
        return 1;
    }
  }
  return 0;
}
// 199998: using guessed type int16_t word_199998;


//----- (000FC2D2) --------------------------------------------------------
void __usercall sub_FC2D2(int16_t *a1)
{
  int v1; // eax
  char *v2; // eax
  int v3; // eax
  int64_t v4; // rax
  int v5; // edx
  char v6; // [esp+0h] [ebp-60h] BYREF
  int v7; // [esp+58h] [ebp-8h]
  char v8; // [esp+5Ch] [ebp-4h] BYREF

  v7 = 0;
  v1 = sub_F6816(word_1AAF86, 11, 0, 0);
  do
    v1 = sub_F55A4(v1, 11, 0, 0);
  while ( byte_1AB03F == 8 );
  dword_1AA3E0 = (int)&v6;
  v2 = &v8;
  dword_1AA3E4 = (int)&v8;
  while ( 1 )
  {
    LOBYTE(v2) = sub_FC299();
    if ( !(_BYTE)v2 )
      break;
    v2 = (char *)sub_F55A4((int)v2, 11, 0, 0);
  }
  sub_F7E95();
  sub_EA2F1(0, a1);
  dword_1AA3E0 = 0;
  dword_1AA3E4 = 0;
  strcpy((char *)&word_18FF78, (char *)dword_1AB108);
  while ( !word_1AAF70 )
  {
    v3 = 3753 * word_19999C;
    if ( *(_BYTE *)(dword_197F98 + v3 + 36) )
      break;
    sub_F55A4(v3, dword_197F98, 0, 0);
  }
  if ( !*(_BYTE *)(dword_197F98 + 3753 * word_19999C + 36) )
  {
    while ( word_1AAF6E < word_1AAF70 )
    {
      v4 = sprintf(&word_18FF78, (char *)dword_1AB104, word_1AAF6E, word_1AAF70);
      sub_F55A4(v4, SHIDWORD(v4), 0, 0);
    }
    v5 = dword_1AAF6A;
    LOBYTE(v5) = sub_F79F6((char *)dword_1AAF72, (int16_t *)dword_1AAF6A, v7 > 0);
    if ( !(_BYTE)v5 )
      sub_126487(aCraziness, v5);
    memset(byte_1AB09F, 0, sizeof(byte_1AB09F));
    dword_1AAF72 = 0;
    sub_1113CC(dword_192ED4, 0);
    word_1AAF70 = 0;
    byte_1AB03F = 4;
    sub_8A4C4();
    if ( byte_1AAF5D == 1 )
    {
      sub_FAA94();
      byte_199F3A = 0;
    }
  }
  dword_1AA3E0 = 0;
  dword_1AA3E4 = 0;
  JUMPOUT(0xFC292);
}
// FC46B: control flows out of bounds to FC292
// FC31E: variable 'v2' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 18FF78: using guessed type int16_t word_18FF78;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;
// 1AA3E0: using guessed type int dword_1AA3E0;
// 1AA3E4: using guessed type int dword_1AA3E4;
// 1AAF5D: using guessed type char byte_1AAF5D;
// 1AAF6A: using guessed type int dword_1AAF6A;
// 1AAF6E: using guessed type int16_t word_1AAF6E;
// 1AAF70: using guessed type int16_t word_1AAF70;
// 1AAF72: using guessed type int dword_1AAF72;
// 1AAF86: using guessed type int16_t word_1AAF86;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB104: using guessed type int dword_1AB104;
// 1AB108: using guessed type int dword_1AB108;


//----- (000FC470) --------------------------------------------------------
void __fastcall sub_FC470(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // esi
  int v9; // edi
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // esi
  int v15; // eax
  int v16; // edx
  int v17; // eax
  _BYTE v18[1152]; // [esp+0h] [ebp-488h] BYREF
  int v19; // [esp+480h] [ebp-8h] BYREF
  char v20; // [esp+484h] [ebp-4h]

  if ( *(char *)(dword_197F98 + 3753 * word_19999C + 3698) == -1 )
  {
    byte_1AB069 = 0;
    v4 = 1152;
    byte_1AB054 = 0;
    memset(v18, 0, sizeof(v18));
    dword_1AA250 = (int)v18;
    sub_F3E42(0);
    v5 = sub_1191CA((int)sub_F1075, 1);
    sub_EFCEA(v5, 1);
    v6 = word_19999C;
    byte_1AB03F = 8;
    v7 = byte_1AAF76[word_19999C];
    byte_1AAF7E[word_19999C] = 1;
    if ( v7 == -1 )
      byte_1AAF76[v6] = word_19999C;
    v8 = word_199998;
    v20 = 1;
    v9 = 3753 * word_199998;
    while ( v8 > 0 )
    {
      v9 -= 3753;
      v10 = v9 + dword_197F98;
      --v8;
      if ( *(_BYTE *)(v9 + dword_197F98 + 40) == 100 )
      {
        v6 = word_19999C;
        if ( v8 != word_19999C )
        {
          a4 = 5;
          v19 = byte_1AAF76[word_19999C];
          v4 = (int)&v19;
          v11 = *(int16_t *)(v10 + 43);
          v10 = 4;
          v6 = sub_F6816(v11, 4, (int)&v19, 5u);
        }
      }
      v6 = sub_F55A4(v6, v10, v4, a4);
    }
    do
    {
      v12 = word_199998;
      v13 = -1;
      v14 = 3753 * word_199998;
      do
      {
        while ( 1 )
        {
          do
          {
            if ( v12 <= 0 )
              goto LABEL_13;
            v9 = dword_197F98;
            v14 -= 3753;
            --v12;
          }
          while ( *(_BYTE *)(dword_197F98 + v14 + 40) != 100 );
          v9 = byte_1AAF76[v12];
          if ( v9 == -1 )
          {
            v13 = -1;
            goto LABEL_13;
          }
          if ( v13 != -1 )
            break;
          v13 = byte_1AAF76[v12];
        }
      }
      while ( v13 == v9 );
      v13 = -1;
LABEL_13:
      if ( v13 != -1 )
      {
        v12 = 3753 * v13;
        v13 = dword_197F98;
        LOWORD(v12) = *(_WORD *)(dword_197F98 + v12 + 43);
        word_1AAF86 = v12;
      }
      sub_F55A4(v12, v13, v4, a4);
      v15 = word_1AAF86;
    }
    while ( word_1AAF86 == -1 );
    LOWORD(v15) = word_1AAF86;
    if ( word_1AAF86 == word_1AAF5E )
      sub_FBFE2(v15, v13, v4, a4);
    else
      sub_FC2D2((int16_t *)v9);
    byte_1AB054 = 0;
    v16 = dword_197F98;
    byte_1AB069 = 0;
    dword_1AA250 = 0;
    if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 36) )
    {
      sub_C6762();
      while ( 1 )
      {
        v17 = sub_139127();
        if ( !v17 )
          break;
        sub_FE8BE(v17, v16, v4, (int16_t *)v9);
      }
      sub_FAA94();
      byte_199F3A = 0;
      word_199A08 = 10;
    }
    else
    {
      sub_147D7(51);
      word_199A08 = 39;
    }
    byte_199F19 = 37;
  }
  else
  {
    sub_FA989();
    sub_FAA94();
    word_199A08 = 10;
    word_199A10 = 10;
    byte_199F19 = 10;
  }
  JUMPOUT(0xFC292);
}
// FC4BE: control flows out of bounds to FC292
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199F19: using guessed type char byte_199F19;
// 199F3A: using guessed type char byte_199F3A;
// 1AA250: using guessed type int dword_1AA250;
// 1AAF5E: using guessed type int16_t word_1AAF5E;
// 1AAF86: using guessed type int16_t word_1AAF86;
// 1AB03F: using guessed type char byte_1AB03F;
// 1AB054: using guessed type char byte_1AB054;
// 1AB069: using guessed type char byte_1AB069;


//----- (000FC6A5) --------------------------------------------------------
int sub_FC6A5()
{
  memset(&byte_1AAF76, -1, 8);
  memset(&byte_1AB07A, -1, 8);
  memset(byte_1AAF7E, 0, 8);
  word_1AAF86 = -1;
  byte_1AAF88[0] = -1;
  byte_1AAF8A[0] = 0;
  byte_1AB0CB = -1;
  memset(&byte_1AB06A, 0, 8);
  memset(&byte_1AB072, 0, 8);
  return memset(&byte_1AB094, 0, 8);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1AAF76: using guessed type char byte_1AAF76;
// 1AAF86: using guessed type int16_t word_1AAF86;
// 1AAF88: using guessed type char byte_1AAF88;
// 1AAF8A: using guessed type char byte_1AAF8A;
// 1AB06A: using guessed type char byte_1AB06A;
// 1AB072: using guessed type char byte_1AB072;
// 1AB07A: using guessed type char byte_1AB07A;
// 1AB094: using guessed type char byte_1AB094;
// 1AB0CB: using guessed type char byte_1AB0CB;


//----- (000FC734) --------------------------------------------------------
int sub_FC734()
{
  unsigned int v0; // edx
  int result; // eax

  v0 = sub_1247A0(0x14u);
  result = -1;
  if ( v0 < 0xC )
  {
    if ( v0 < 2 )
    {
      if ( v0 == 1 )
        return 204;
    }
    else if ( v0 <= 6 )
    {
      return 205;
    }
    else
    {
      return 206;
    }
  }
  else if ( v0 <= 0xD )
  {
    return 207;
  }
  else if ( v0 < 0x12 )
  {
    return 208;
  }
  else if ( v0 <= 0x12 )
  {
    return 209;
  }
  else if ( v0 <= 0x13 )
  {
    return 210;
  }
  else if ( v0 == 20 )
  {
    return 211;
  }
  return result;
}


//----- (000FC7AC) --------------------------------------------------------
unsigned int __fastcall sub_FC7AC( int a1, int a2)
{
  unsigned int v3; // ebx
  int v4; // ecx
  int v5; // eax

  v3 = 0;
  v4 = 0;
  v5 = 0;
  do
  {
    if ( (uint8_t)byte_17E082[v5] == a2
      && *(_BYTE *)(v4 + 3753 * a1 + dword_197F98 + 279) == 3
      && (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v5)] > v3 )
    {
      v3 = (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v5)];
    }
    ++v4;
    v5 += 13;
  }
  while ( v4 < 75 );
  return v3;
}
// 17E07F: using guessed type int16_t word_17E07F;
// 197F98: using guessed type int dword_197F98;


//----- (000FC845) --------------------------------------------------------
void __fastcall sub_FC845( int a1, unsigned int a2)
{
  int v3; // ecx
  int v4; // edi
  unsigned int v5; // ebx
  int v6; // ecx
  int v7; // edi
  _BOOL1 v8; // zf
  _BOOL1 v9; // zf
  uint8_t v10; // al
  _BOOL1 v11; // zf
  int v12; // eax
  _BOOL1 v13; // sf
  _BOOL1 v14; // cc
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  unsigned int v18; // ecx
  uint8_t v19; // al
  int v20; // eax
  _BOOL1 v21; // zf
  int i; // eax
  unsigned int v23; // [esp+0h] [ebp-34h]
  int v24; // [esp+4h] [ebp-30h]
  int v25; // [esp+8h] [ebp-2Ch]
  int v26; // [esp+14h] [ebp-20h]
  int v27; // [esp+1Ch] [ebp-18h]
  int v28; // [esp+20h] [ebp-14h]
  bool v29; // [esp+24h] [ebp-10h]
  int v30; // [esp+28h] [ebp-Ch]
  unsigned int v31; // [esp+2Ch] [ebp-8h]

  v3 = 3753 * a1;
  if ( !sub_E412B(v3 + dword_197F98, (int16_t)a2)
    || *(_BYTE *)((int16_t)a2 + v3 + dword_197F98 + 279) == 3
    || *(_BYTE *)(v3 + dword_197F98 + 40) != 100 && a2 == 52 )
  {
    goto LABEL_226;
  }
  v4 = 13 * (int16_t)a2;
  v5 = (uint8_t)byte_17E082[v4];
  v6 = (uint8_t)byte_17D196[2 * v5];
  v31 = (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v4)];
  if ( v31 > 0x16 )
    v31 = 22;
  v7 = dword_18360C[v31];
  switch ( *(_BYTE *)(3753 * a1 + dword_197F98 + 517) )
  {
    case 0:
      if ( v5 == 26 || v5 == 27 )
        goto LABEL_25;
      v8 = v5 == 25;
      goto LABEL_18;
    case 1:
      switch ( v5 )
      {
        case 0x1Au:
          goto LABEL_10;
        case 0x13u:
        case 0x1Eu:
          goto LABEL_25;
        case 0x19u:
          v6 = 20;
          break;
      }
      break;
    case 2:
      if ( v5 == 21 || v5 == 29 )
        goto LABEL_25;
      v8 = v5 == 24;
LABEL_18:
      if ( v8 )
        goto LABEL_25;
      break;
    case 3:
      if ( v5 == 36 )
      {
LABEL_10:
        v6 = 50;
      }
      else if ( v5 == 38 )
      {
LABEL_25:
        v6 = 100;
      }
      break;
    default:
      break;
  }
  switch ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 518) )
  {
    case 0:
      if ( v5 == 18 || v5 == 23 )
        goto LABEL_28;
      goto LABEL_38;
    case 1:
      if ( v5 == 15 || v5 == 16 )
        goto LABEL_32;
      if ( v5 == 32 )
      {
LABEL_28:
        v6 = 50;
      }
      else
      {
        v9 = v5 == 35;
LABEL_36:
        if ( v9 )
LABEL_37:
          v6 = 100;
      }
LABEL_38:
      v10 = *(_BYTE *)(dword_197F98 + 3753 * a1 + 40);
      if ( v10 < 3u )
      {
        if ( v10 )
        {
          if ( v10 <= 1u )
          {
            if ( v5 == 17 )
              goto LABEL_72;
            v11 = v5 == 33;
          }
          else
          {
            if ( v5 == 39 )
            {
              v6 = 50;
              goto LABEL_73;
            }
            if ( v5 == 9 )
              goto LABEL_72;
            v11 = v5 == 10;
          }
        }
        else
        {
          if ( v5 == 12 || v5 == 3 )
            goto LABEL_72;
          v11 = v5 == 11;
        }
      }
      else if ( v10 <= 3u )
      {
        v11 = v5 == 2;
      }
      else
      {
        if ( v10 >= 5u )
        {
          if ( v10 > 5u || v5 && v5 != 4 )
          {
LABEL_73:
            if ( v5 < 0xC )
            {
              if ( v5 >= 2 )
              {
                if ( v5 <= 2 )
                {
                  if ( *(char *)(dword_197F98 + 3753 * a1 + 2211) >= 0 )
                  {
                    v14 = *(_BYTE *)(3753 * a1 + dword_197F98 + 2211) <= 0;
LABEL_117:
                    if ( v14 )
                      goto LABEL_137;
                  }
                }
                else if ( v5 < 4 )
                {
                  if ( *(char *)(dword_197F98 + 3753 * a1 + 2212) >= 0 )
                  {
                    if ( *(char *)(dword_197F98 + 3753 * a1 + 2212) <= 0 )
                      goto LABEL_137;
                    goto LABEL_108;
                  }
                }
                else
                {
                  if ( v5 <= 4 )
                  {
                    if ( *(char *)(dword_197F98 + 3753 * a1 + 2210) > 0 )
                      v6 = 100;
                    if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 2230) )
                      goto LABEL_136;
                    goto LABEL_137;
                  }
                  if ( v5 != 6 )
                    goto LABEL_137;
                  if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 2220) )
                    v6 = 20;
                  v26 = 3753 * a1;
                  if ( *(char *)(v26 + dword_197F98 + 2208) >= 0 )
                  {
                    if ( *(char *)(v26 + dword_197F98 + 2208) > 0 )
                      v6 = 5;
                    goto LABEL_137;
                  }
                }
LABEL_118:
                v6 = 100;
                goto LABEL_137;
              }
              if ( v5 )
              {
                v13 = *(char *)(dword_197F98 + 3753 * a1 + 2210) < 0;
LABEL_109:
                if ( !v13 )
                  goto LABEL_137;
                goto LABEL_118;
              }
              if ( *(char *)(dword_197F98 + 3753 * a1 + 2209) >= 0 )
              {
                if ( *(char *)(dword_197F98 + 3753 * a1 + 2209) > 0 )
                  v6 = 10;
              }
              else
              {
                v6 = 100;
              }
              v12 = dword_197F98 + 3753 * a1;
              if ( *(_BYTE *)(v12 + 2225) )
                goto LABEL_136;
              if ( !*(_BYTE *)(v12 + 2224) )
                goto LABEL_137;
            }
            else
            {
              if ( v5 <= 0xC )
              {
                if ( *(_BYTE *)(3753 * a1 + dword_197F98 + 2216) )
                  v6 = 50;
                if ( *(char *)(dword_197F98 + 3753 * a1 + 2207) / 2 != 2 )
                  goto LABEL_137;
                goto LABEL_123;
              }
              if ( v5 >= 0x1B )
              {
                if ( v5 <= 0x1B )
                {
                  v14 = *(_BYTE *)(dword_197F98 + 3753 * a1 + 2214) <= 0;
                }
                else
                {
                  if ( v5 >= 0x25 )
                  {
                    if ( v5 <= 0x25 )
                    {
                      if ( !*(_BYTE *)(dword_197F98 + 3753 * a1 + 2235) )
                        goto LABEL_137;
                      goto LABEL_136;
                    }
                    if ( v5 == 40 && *(char *)(dword_197F98 + 3753 * a1 + 2207) / 2 == 3 )
LABEL_136:
                      v6 = 1;
LABEL_137:
                    if ( a2 < 5u )
                      goto LABEL_145;
                    if ( a2 <= 5u )
                    {
                      if ( !*(_BYTE *)(3753 * a1 + dword_197F98 + 2232) )
                        goto LABEL_145;
                    }
                    else
                    {
                      if ( a2 != 131 )
                        goto LABEL_145;
                      v15 = dword_197F98 + 3753 * a1;
                      if ( !*(_BYTE *)(v15 + 2218) )
                      {
                        if ( *(_BYTE *)(v15 + 2217) )
                          v6 = 50;
LABEL_145:
                        if ( *(_BYTE *)(3753 * a1 + dword_197F98 + 40) == 100 )
                        {
                          v6 = 25 * (uint8_t)byte_199CB0 * (uint8_t)byte_199CB0 + 50;
                          if ( v5 == 26 || v5 == 27 || v5 == 29 || v5 == 30 || v5 == 33 || v5 == 21 )
                            v6 *= 4;
                        }
                        if ( byte_17D197[2 * v5] )
                        {
                          v18 = v7 * v6;
                          goto LABEL_172;
                        }
                        v28 = 0;
                        v30 = 0;
                        v25 = 0;
                        do
                        {
                          if ( v5 == (uint8_t)byte_17E082[v25]
                            && *(_BYTE *)(v30 + 3753 * a1 + dword_197F98 + 279) == 3 )
                          {
                            v28 = (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v25)];
                          }
                          ++v30;
                          v25 += 13;
                        }
                        while ( v30 < 204 );
                        v16 = v7 * v6;
                        if ( v28 + 3 > (int)v31 )
                        {
                          if ( v5 == 14 || v5 == 16 || v5 == 18 || v5 == 24 || v5 == 25 || v5 == 32 || v5 == 39 )
                          {
                            v18 = 0;
                            goto LABEL_172;
                          }
                          v17 = 2 * v16 / (int)(v28 + 3 - v31);
                        }
                        else
                        {
                          v17 = (int)(v16 * (v31 - v28)) / 3;
                        }
                        v18 = v17;
LABEL_172:
                        if ( v5 == 25 && v7 < word_1AB10E )
                          v18 *= word_1AB10E - v7;
                        if ( v5 == 18 && v7 < word_1AB10C )
                          v18 *= word_1AB10C - v7;
                        if ( v5 == 19 && v7 < word_1AB110 )
                          v18 *= word_1AB110 - v7;
                        if ( v5 == 10 && v7 < word_1AB112 )
                          v18 *= word_1AB112 - v7;
                        if ( v5 == 12 && v7 < word_1AB114 )
                          v18 *= word_1AB114 - v7;
                        if ( v5 == 15 && v7 < word_1AB118 )
                          v18 *= word_1AB118 - v7;
                        if ( v5 == 8 )
                        {
                          v23 = sub_FC7AC(a1, 15);
                          if ( v23 + sub_FC7AC(a1, 16) < 2 * word_1AB118 )
                            v18 *= 2;
                        }
                        if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 517) == 2 && v5 == 24 && v7 < word_1AB11A )
                          v18 *= word_1AB11A - v7;
                        v19 = *(_BYTE *)(3753 * a1 + dword_197F98 + 517);
                        if ( v19 )
                        {
                          if ( v19 > 1u )
                          {
                            if ( v19 != 2 )
                              goto LABEL_212;
                            if ( v5 != 21 )
                              goto LABEL_212;
                            v20 = word_1AB122;
                            if ( v7 >= word_1AB122 )
                              goto LABEL_212;
                            goto LABEL_211;
                          }
                          if ( v5 == 26 && v7 < word_1AB122 )
                            v18 *= word_1AB122 - v7;
                          v21 = v5 == 19;
                        }
                        else
                        {
                          v21 = v5 == 26;
                        }
                        if ( !v21 )
                          goto LABEL_212;
                        v20 = word_1AB122;
                        if ( v7 >= word_1AB122 )
                          goto LABEL_212;
LABEL_211:
                        v18 *= v20 - v7;
LABEL_212:
                        if ( dword_192FD8 - 35000 < 150 && v5 == 18 )
                          v18 *= 2;
                        if ( *(_BYTE *)(*(int16_t *)((char *)&word_17E07F + 13 * (int16_t)a2)
                                      + 3753 * a1
                                      + dword_197F98
                                      + 196) == 3 )
                          v18 = (5 * v18) >> 2;
                        if ( !v18 )
                        {
                          v27 = *(int16_t *)((char *)&word_17E07F + 13 * (int16_t)a2);
                          if ( *(_BYTE *)(v27 + 3753 * a1 + dword_197F98 + 196) == 2 )
                          {
                            v29 = 0;
                            v24 = 0;
                            for ( i = 0; i < 204 && !v29; ++i )
                            {
                              if ( i != (int16_t)a2 && *(int16_t *)((char *)&word_17E07F + v24) == v27 )
                                v29 = *(_BYTE *)(3753 * a1 + dword_197F98 + i + 279) != 3;
                              v24 += 13;
                            }
                          }
                        }
LABEL_226:
                        JUMPOUT(0xFC813);
                      }
                    }
                    v6 = 1;
                    goto LABEL_145;
                  }
                  if ( v5 != 28 )
                    goto LABEL_137;
                  v14 = *(_BYTE *)(dword_197F98 + 3753 * a1 + 2213) <= 0;
                }
                goto LABEL_117;
              }
              if ( v5 >= 0x12 )
              {
                if ( v5 > 0x12 )
                {
                  if ( v5 != 25 )
                    goto LABEL_137;
                  v13 = *(char *)(dword_197F98 + 3753 * a1 + 2214) < 0;
                  goto LABEL_109;
                }
                if ( *(char *)(dword_197F98 + 3753 * a1 + 2213) >= 0 )
                  goto LABEL_137;
LABEL_123:
                v6 = 50;
                goto LABEL_137;
              }
              if ( v5 != 16 || *(char *)(3753 * a1 + dword_197F98 + 2215) >= 0 )
                goto LABEL_137;
            }
LABEL_108:
            v6 = 20;
            goto LABEL_137;
          }
LABEL_72:
          v6 = 100;
          goto LABEL_73;
        }
        if ( v5 == 1 )
          goto LABEL_72;
        v11 = v5 == 4;
      }
      if ( !v11 )
        goto LABEL_73;
      goto LABEL_72;
    case 2:
      if ( v5 == 18 )
        goto LABEL_28;
      v9 = v5 == 20;
      goto LABEL_36;
    case 3:
      if ( v5 == 28 )
        goto LABEL_37;
      if ( v5 == 26 )
LABEL_32:
        v6 = 20;
      goto LABEL_38;
    case 4:
      v9 = v5 == 37;
      goto LABEL_36;
    case 5:
      if ( v5 == 32 )
        goto LABEL_37;
      v9 = v5 == 31;
      goto LABEL_36;
    case 6:
      if ( v5 == 33 )
        goto LABEL_37;
      v9 = v5 == 34;
      goto LABEL_36;
    default:
      goto LABEL_38;
  }
}
// FD194: control flows out of bounds to FC813
// 17E07F: using guessed type int16_t word_17E07F;
// 18360C: using guessed type int dword_18360C[30];
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;
// 1AB10C: using guessed type int16_t word_1AB10C;
// 1AB10E: using guessed type int16_t word_1AB10E;
// 1AB110: using guessed type int16_t word_1AB110;
// 1AB112: using guessed type int16_t word_1AB112;
// 1AB114: using guessed type int16_t word_1AB114;
// 1AB118: using guessed type int16_t word_1AB118;
// 1AB11A: using guessed type int16_t word_1AB11A;
// 1AB122: using guessed type int16_t word_1AB122;


//----- (000FD199) --------------------------------------------------------
void __fastcall sub_FD199( int a1, int a2)
{
  int v2; // edx
  uint16_t v3; // bx
  int v4; // esi
  int v5; // eax
  int v8; // [esp+8h] [ebp-8h]

  v2 = 0;
  v3 = 0;
  v8 = 0;
  while ( v2 < word_199998 )
  {
    if ( v2 != a2 )
    {
      v4 = 0;
      v5 = 0;
      do
      {
        if ( (uint8_t)byte_17E082[v5] == a1
          && *(_BYTE *)(v8 + dword_197F98 + v4 + 279) == 3
          && (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v5)] > v3 )
        {
          v3 = (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v5)];
        }
        ++v4;
        v5 += 13;
      }
      while ( v4 < 75 );
    }
    v8 += 3753;
    ++v2;
  }
  JUMPOUT(0xFC811);
}
// FD214: control flows out of bounds to FC811
// 17E07F: using guessed type int16_t word_17E07F;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000FD219) --------------------------------------------------------
void __fastcall sub_FD219( int a1)
{
  int16_t v2; // ax
  int16_t v3; // ax
  int16_t v4; // ax
  int16_t v5; // ax
  int16_t v6; // ax
  int16_t v7; // ax
  int16_t v8; // ax
  int16_t v9; // ax
  int16_t v10; // ax
  int16_t v11; // ax
  int16_t v12; // ax
  int16_t v13; // ax

  sub_FD199(25, a1);
  word_1AB10C = v2;
  sub_FD199(18, a1);
  word_1AB10E = v3;
  sub_FD199(10, a1);
  word_1AB110 = v4;
  sub_FD199(19, a1);
  word_1AB112 = v5;
  sub_FD199(12, a1);
  word_1AB114 = v6;
  sub_FD199(16, a1);
  word_1AB116 = v7;
  sub_FD199(15, a1);
  word_1AB118 = v8;
  sub_FD199(28, a1);
  word_1AB11A = v9;
  sub_FD199(24, a1);
  word_1AB11C = v10;
  sub_FD199(26, a1);
  word_1AB11E = v11;
  sub_FD199(21, a1);
  word_1AB120 = v12;
  sub_FD199(33, a1);
  word_1AB122 = v13;
}
// FD22A: variable 'v2' is possibly undefined
// FD23C: variable 'v3' is possibly undefined
// FD24E: variable 'v4' is possibly undefined
// FD260: variable 'v5' is possibly undefined
// FD272: variable 'v6' is possibly undefined
// FD284: variable 'v7' is possibly undefined
// FD296: variable 'v8' is possibly undefined
// FD2A8: variable 'v9' is possibly undefined
// FD2BA: variable 'v10' is possibly undefined
// FD2CC: variable 'v11' is possibly undefined
// FD2DE: variable 'v12' is possibly undefined
// FD2F0: variable 'v13' is possibly undefined
// 1AB10C: using guessed type int16_t word_1AB10C;
// 1AB10E: using guessed type int16_t word_1AB10E;
// 1AB110: using guessed type int16_t word_1AB110;
// 1AB112: using guessed type int16_t word_1AB112;
// 1AB114: using guessed type int16_t word_1AB114;
// 1AB116: using guessed type int16_t word_1AB116;
// 1AB118: using guessed type int16_t word_1AB118;
// 1AB11A: using guessed type int16_t word_1AB11A;
// 1AB11C: using guessed type int16_t word_1AB11C;
// 1AB11E: using guessed type int16_t word_1AB11E;
// 1AB120: using guessed type int16_t word_1AB120;
// 1AB122: using guessed type int16_t word_1AB122;


//----- (000FD2F9) --------------------------------------------------------
_BOOL1 __fastcall sub_FD2F9(_BYTE *a1)
{
  return a1[251] == 3 && a1[219] == 3 && a1[253] == 3 && a1[225] == 3 && a1[218] == 3 && a1[224] == 3;
}


//----- (000FD335) --------------------------------------------------------
int __fastcall sub_FD335( int a1)
{
  int v2; // edi
  int v3; // ecx
  unsigned int v4; // esi
  unsigned int v5; // ebx
  int v6; // eax
  int v7; // ecx
  int i; // ebx
  unsigned int v9; // edi
  unsigned int v10; // eax
  int v11; // eax
  uint8_t v12; // bl
  _BOOL1 v13; // zf
  unsigned int v14; // edx
  int16_t v17; // [esp+0h] [ebp-6C4h]
  _BYTE v18[848]; // [esp+4h] [ebp-6C0h] BYREF
  _BYTE v19[848]; // [esp+354h] [ebp-370h] BYREF
  int v20; // [esp+6A4h] [ebp-20h]
  unsigned int v21; // [esp+6A8h] [ebp-1Ch]
  _BYTE *v22; // [esp+6ACh] [ebp-18h]
  _BYTE *v23; // [esp+6B0h] [ebp-14h]
  int v24; // [esp+6B4h] [ebp-10h]
  char v25; // [esp+6B8h] [ebp-Ch]
  _BOOL1 v26; // [esp+6BCh] [ebp-8h]
  char v27; // [esp+6C0h] [ebp-4h]

  v25 = 0;
  v23 = (_BYTE *)(3753 * a1 + dword_197F98);
  v26 = sub_FD2F9(v23);
  sub_FD219(a1);
  v2 = 1;
  memset(v18, 0, sizeof(v18));
  v3 = 13;
  memset(v19, 0, sizeof(v19));
  v24 = 4;
  v4 = 0;
  v22 = v23 + 1;
  do
  {
    if ( v22[279] == 1 && (!byte_199CB4 || byte_17E084[v3]) )
    {
      v5 = *(int16_t *)((char *)&word_17E07F + v3);
      if ( (int)v5 < 75 && v23[v5 + 196] == 2 )
      {
        sub_FC845(v17, v2);
        if ( v26 )
        {
          if ( v5 == 4 )
            v6 *= 2;
          if ( v2 == 114 )
            v6 *= 2;
          if ( v2 == 51 )
            v6 *= 5;
          if ( v5 == 73 )
            v6 *= 2;
          if ( !v6 )
            v6 = 1;
          goto LABEL_28;
        }
        if ( v5 < 0x1C )
        {
          if ( v5 < 0x16 || v5 > 0x17 )
            goto LABEL_27;
        }
        else if ( v5 > 0x1D && (v5 < 0x37 || v5 > 0x37 && v5 != 57) )
        {
LABEL_27:
          v6 = 0;
          goto LABEL_28;
        }
        ++v6;
LABEL_28:
        v25 = 1;
        *(_DWORD *)&v18[v24] = v6;
      }
    }
    ++v22;
    v24 += 4;
    ++v2;
    v3 += 13;
  }
  while ( v2 < 212 );
  if ( v25 )
  {
    v7 = 15;
    v21 = *(int16_t *)(dword_197F98 + 172);
    if ( !v21 )
      v21 = 1;
    v27 = 0;
    v4 = 0;
    while ( !v27 )
    {
      v27 = 0;
      v20 = 13;
      for ( i = 4; i != 848; i += 4 )
      {
        if ( !*(_DWORD *)&v18[i] )
          goto LABEL_43;
        v9 = *(int *)((char *)&dword_17D916 + 23 * *(int16_t *)((char *)&word_17E07F + v20)) / v21;
        if ( !v9 )
          v9 = 1;
        if ( (int)v9 <= v7 )
        {
          v10 = v7 * *(_DWORD *)&v18[i] / v9;
          if ( v4 < v10 )
            v4 = v7 * *(_DWORD *)&v18[i] / v9;
          v27 = 1;
          *(_DWORD *)&v19[i] = v10;
        }
        else
        {
LABEL_43:
          *(_DWORD *)&v19[i] = 0;
        }
        v20 += 13;
      }
      v7 = 3 * v7 / 2;
    }
  }
  if ( byte_199CB0 && v4 )
  {
    v11 = 4;
    while ( 1 )
    {
      v12 = *(_BYTE *)(3753 * v17 + dword_197F98 + 40);
      if ( !v12 )
        break;
      if ( v12 <= 2u )
      {
        v14 = 6 * *(_DWORD *)&v19[v11];
        goto LABEL_57;
      }
      if ( v12 > 4u )
      {
        v13 = v12 == 5;
        goto LABEL_53;
      }
      if ( 5 * *(_DWORD *)&v19[v11] < 4 * v4 )
LABEL_61:
        *(_DWORD *)&v19[v11] = 0;
LABEL_62:
      v11 += 4;
      if ( v11 == 848 )
        goto LABEL_63;
    }
    v13 = 1;
LABEL_53:
    if ( !v13 )
      goto LABEL_62;
    v14 = 2 * *(_DWORD *)&v19[v11];
LABEL_57:
    if ( v14 < v4 )
      goto LABEL_61;
    goto LABEL_62;
  }
LABEL_63:
  if ( v4 )
    return (int16_t)sub_FE96F((int)v19, 212);
  else
    return sub_FC734();
}
// FD3F8: variable 'v17' is possibly undefined
// FD408: variable 'v6' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17D916: using guessed type int dword_17D916;
// 17E07F: using guessed type int16_t word_17E07F;
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;
// 199CB4: using guessed type char byte_199CB4;


//----- (000FD5EE) --------------------------------------------------------
unsigned int __fastcall sub_FD5EE(char *a1)
{
  dword_1AB12C = (int)a1;
  dword_1AB144 = (int)&a1[strlen(a1) + 1];
  dword_1AB148 = strlen((char *)dword_1AB144) + 1 + dword_1AB144;
  dword_1AB13C = strlen((char *)dword_1AB148) + 1 + dword_1AB148;
  dword_1AB130 = strlen((char *)dword_1AB13C) + 1 + dword_1AB13C;
  dword_1AB134 = strlen((char *)dword_1AB130) + 1 + dword_1AB130;
  dword_1AB138 = strlen((char *)dword_1AB134) + 1 + dword_1AB134;
  dword_1AB140 = strlen((char *)dword_1AB138) + 1 + dword_1AB138;
  return dword_1AB140 + strlen((char *)dword_1AB140) + 1;
}
// 1AB12C: using guessed type int dword_1AB12C;
// 1AB130: using guessed type int dword_1AB130;
// 1AB134: using guessed type int dword_1AB134;
// 1AB138: using guessed type int dword_1AB138;
// 1AB13C: using guessed type int dword_1AB13C;
// 1AB140: using guessed type int dword_1AB140;
// 1AB144: using guessed type int dword_1AB144;
// 1AB148: using guessed type int dword_1AB148;


//----- (000FD69F) --------------------------------------------------------
char __fastcall sub_FD69F(int64_t a1)
{
  int v1; // ebx
  char v2; // al

  v1 = a1;
  LOBYTE(a1) = *(_BYTE *)HIDWORD(a1);
  if ( !*(_BYTE *)HIDWORD(a1) )
    return a1;
  if ( *(_BYTE *)HIDWORD(a1) > 1u )
  {
    if ( (_BYTE)a1 == 2 )
    {
      LOBYTE(a1) = *(_BYTE *)(HIDWORD(a1) + 3);
      if ( (_BYTE)a1 )
      {
        if ( (_BYTE)a1 == 1 )
        {
          LODWORD(a1) = sub_77B28(*(uint8_t *)(HIDWORD(a1) + 6));
          LOBYTE(a1) = sprintf(
                         v1,
                         (char *)dword_1AB130,
                         dword_197F98 + 3753 * *(int16_t *)(HIDWORD(a1) + 4) + 21,
                         *(_UNKNOWN **)((char *)&off_17EB3D + 19 * *(uint8_t *)(HIDWORD(a1) + 7)),
                         (_DWORD)a1);
        }
      }
      else
      {
        LOBYTE(a1) = sprintf(
                       v1,
                       (char *)dword_1AB13C,
                       dword_197F98 + 3753 * *(int16_t *)(HIDWORD(a1) + 4) + 21,
                       *(_UNKNOWN **)((char *)&off_17E079 + 13 * *(int16_t *)(HIDWORD(a1) + 6)));
      }
    }
    return a1;
  }
  v2 = *(_BYTE *)(HIDWORD(a1) + 3);
  if ( !v2 )
  {
    a1 = sprintf(
           v1,
           (char *)dword_1AB12C,
           *(_UNKNOWN **)((char *)&off_17E079 + 13 * *(int16_t *)(HIDWORD(a1) + 6)),
           3753 * (unsigned int)*(uint8_t *)(HIDWORD(a1) + 5) + dword_197F98 + 21);
LABEL_10:
    v1 += a1;
    goto LABEL_11;
  }
  if ( v2 == 1 )
  {
    LODWORD(a1) = sub_77B28(*(uint8_t *)(HIDWORD(a1) + 6));
    a1 = sprintf(
           v1,
           (char *)dword_1AB144,
           dword_197F98 + 3753 * (unsigned int)*(uint8_t *)(HIDWORD(a1) + 5) + 21,
           *(_UNKNOWN **)((char *)&off_17EB3D + 19 * *(uint8_t *)(HIDWORD(a1) + 7)),
           (_DWORD)a1);
    goto LABEL_10;
  }
LABEL_11:
  LODWORD(a1) = *(char *)(HIDWORD(a1) + 4);
  if ( (_DWORD)a1 != -1 )
    LOBYTE(a1) = sprintf(v1, (char *)dword_1AB148, 3753 * (int)a1 + dword_197F98 + 21);
  return a1;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 197F98: using guessed type int dword_197F98;
// 1AB12C: using guessed type int dword_1AB12C;
// 1AB130: using guessed type int dword_1AB130;
// 1AB13C: using guessed type int dword_1AB13C;
// 1AB144: using guessed type int dword_1AB144;
// 1AB148: using guessed type int dword_1AB148;


//----- (000FD7EA) --------------------------------------------------------
int sub_FD7EA()
{
  int result; // eax

  result = memset(&unk_1AB504, 0, 9);
  byte_1AB50D = 0;
  byte_1AB50F = 0;
  byte_1AB50E = 0;
  byte_1991B5 = 0;
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1991B5: using guessed type char byte_1991B5;
// 1AB50D: using guessed type char byte_1AB50D;
// 1AB50E: using guessed type char byte_1AB50E;
// 1AB50F: using guessed type char byte_1AB50F;


//----- (000FD81C) --------------------------------------------------------
void sub_FD81C()
{
  memset(&byte_1AB124, 0, 8);
  word_1AB502 = 0;
  JUMPOUT(0xFD7F8);
}
// FD844: control flows out of bounds to FD7F8
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1AB124: using guessed type char byte_1AB124;
// 1AB502: using guessed type int16_t word_1AB502;


//----- (000FD846) --------------------------------------------------------
int __fastcall sub_FD846(int result)
{
  char *v1; // edi

  if ( word_1AB502 < 50 )
  {
    v1 = &byte_1AB14C[19 * word_1AB502++];
    *(_DWORD *)v1 = *(_DWORD *)result;
    v1 += 4;
    *(_DWORD *)v1 = *(_DWORD *)(result + 4);
    v1 += 4;
    *(_DWORD *)v1 = *(_DWORD *)(result + 8);
    v1 += 4;
    *(_DWORD *)v1 = *(_DWORD *)(result + 12);
    v1 += 4;
    *(_WORD *)v1 = *(_WORD *)(result + 16);
    v1[2] = *(_BYTE *)(result + 18);
  }
  return result;
}
// 1AB502: using guessed type int16_t word_1AB502;


//----- (000FD875) --------------------------------------------------------
char __fastcall sub_FD875(int a1, int a2)
{
  char v2; // bl
  char result; // al

  v2 = *(_BYTE *)(a1 + 40);
  result = 0;
  if ( v2 < 50 )
  {
    if ( (uint8_t)v2 < 4u )
    {
      if ( v2 )
        return result;
    }
    else if ( (uint8_t)v2 > 6u && ((uint8_t)v2 < 0xAu || (uint8_t)v2 > 0xBu) )
    {
      return result;
    }
    return v2;
  }
  if ( v2 < 90 )
  {
    if ( v2 < 80 )
    {
      if ( v2 < 70 )
      {
        if ( v2 < 60 )
          result = 2;
        else
          result = 3;
      }
      else
      {
        result = 7;
      }
    }
    else
    {
      result = 8;
    }
  }
  else
  {
    result = 10;
  }
  if ( v2 % 10 != a2 && result != 10 )
    return 0;
  return result;
}


//----- (000FD8ED) --------------------------------------------------------
void sub_FD8ED()
{
  JUMPOUT(0xFD8E7);
}
// FD90F: control flows out of bounds to FD8E7


//----- (000FD911) --------------------------------------------------------
char __usercall sub_FD911( int a1, int a2, int16_t *a3)
{
  char v4; // dl
  int v5; // eax
  int v6; // ebx

  v4 = 0;
  if ( dword_192FD8 > 35000 )
  {
    v5 = dword_197F98 + 3753 * a1;
    v6 = *(uint8_t *)(v5 + 801);
    if ( *(_BYTE *)(v6 + v5 + 196) == 3 && !*(_BYTE *)(v5 + 801) )
    {
      if ( a2 )
        sub_10DB69(v6, a3);
      return 2;
    }
  }
  return v4;
}
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;


//----- (000FD95A) --------------------------------------------------------
void __fastcall sub_FD95A(int a1, int a2)
{
  unsigned int v2; // ebx
  char v3; // al
  _BOOL1 v4; // ch
  int v5; // eax
  char v6; // al
  int16_t v7; // [esp+0h] [ebp-Ch]

  v2 = 113 * word_19999A + dword_19306C;
  do
  {
    if ( v2 <= dword_19306C )
      goto LABEL_13;
    v3 = *(_BYTE *)(v2 - 73);
    v2 -= 113;
    v4 = 0;
    if ( v3 >= 50 )
      v4 = (int16_t)(v3 % 10) == v7;
  }
  while ( (((int)*(uint8_t *)(v2 + 52) >> v7) & 1) == 0 && !v4 );
  v5 = 3753 * v7;
  if ( !*(_BYTE *)(dword_197F98 + v5 + 2234) || v4 )
  {
    if ( a2 )
    {
      nullsub_5(v5);
      v6 = sub_FD875(v2, v7);
      sub_C8556((int)(v2 - dword_19306C) / 113, v6);
      *(_BYTE *)(v2 + 52) &= ~(1 << v7);
      if ( v4 )
        *(_BYTE *)(v2 + 40) = 0;
    }
  }
  else
  {
    *(_BYTE *)(v2 + 52) &= ~(1 << v7);
  }
LABEL_13:
  JUMPOUT(0xFE2E2);
}
// FD98B: control flows out of bounds to FE2E2
// FD97B: variable 'v7' is possibly undefined
// 919A3: using guessed type int __fastcall nullsub_5(_DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;


//----- (000FDA3F) --------------------------------------------------------
char *__fastcall sub_FDA3F( int a1, int a2)
{
  int16_t v4; // dx
  int v5; // eax
  int v6; // eax
  char *result; // eax

  v4 = 5;
  while ( v4 > 0 )
  {
    v5 = *(int16_t *)(113 * a2 + dword_19306C + 2 * --v4 + 74);
    if ( v5 != -1 )
    {
      v6 = *(int16_t *)(dword_1930D4 + 17 * v5);
      if ( v6 != -1 )
      {
        result = (char *)(361 * v6 + dword_192B18);
        if ( *result == a1 )
        {
          if ( result[321] )
            return result;
        }
      }
    }
  }
  return 0;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000FDAA7) --------------------------------------------------------
unsigned int __fastcall sub_FDAA7( int a1, int a2, int a3, int a4)
{
  unsigned int result; // eax
  int16_t v6; // di

  result = dword_197F9C + 129 * word_199994;
  while ( result > dword_197F9C )
  {
    v6 = *(uint8_t *)(result - 112);
    result -= 129;
    if ( a2 == v6
      && a1 == *(char *)(result + 99)
      && a3 == *(_WORD *)(result + 101)
      && *(char *)(result + 100) < 5
      && (a4 || !*(_BYTE *)(result + 128)) )
    {
      return result;
    }
  }
  return 0;
}
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000FDB01) --------------------------------------------------------
char __usercall sub_FDB01( int a1, int a2)
{
  char *v2; // esi
  int v3; // eax
  _BOOL1 v4; // al
  int v5; // eax
  int v6; // eax
  int16_t *v7; // eax
  char v8; // al
  int16_t v9; // dx
  int16_t v10; // ax
  int v11; // ebx
  char v12; // al
  int v13; // eax
  int16_t *v14; // eax
  char v15; // al
  int16_t v16; // dx
  int16_t v17; // ax
  int v18; // eax
  int16_t v19; // dx
  int16_t v21; // [esp+0h] [ebp-19Ah]
  _BYTE v22[200]; // [esp+4h] [ebp-196h] BYREF
  _BYTE v23[200]; // [esp+CCh] [ebp-CEh] BYREF
  _BYTE v24[100]; // [esp+194h] [ebp-6h] BYREF
  int v25; // [esp+1F8h] [ebp+5Eh]
  unsigned int v26; // [esp+1FCh] [ebp+62h]
  unsigned int v27; // [esp+200h] [ebp+66h]
  int v28; // [esp+204h] [ebp+6Ah]
  unsigned int v29; // [esp+208h] [ebp+6Eh]
  int v30; // [esp+20Ch] [ebp+72h]
  char v31; // [esp+210h] [ebp+76h]
  char v32; // [esp+214h] [ebp+7Ah]
  char v33; // [esp+218h] [ebp+7Eh]

  v32 = a1;
  LOWORD(a2) = word_19999A;
  while ( 1 )
  {
    do
    {
      if ( (int16_t)a2 <= 0 )
        return 0;
      v29 = (int16_t)--a2;
    }
    while ( *(char *)(113 * (int16_t)a2 + dword_19306C + 55) != v21
         || (uint16_t)sub_1276F0((int)&unk_1AB504, v29) );
    v25 = v21;
    v2 = sub_FDA3F(v21, v29);
    v27 = sub_FDAA7(v21, 1, v29, 0);
    v26 = v27;
    v3 = sub_FDAA7(v21, 4, v29, 0);
    v28 = v3;
    v4 = v27 || v3;
    if ( v2 )
      break;
    if ( v4 )
    {
      v3 = (int)*(uint8_t *)(113 * (int16_t)a2 + dword_19306C + 53) >> v21;
      if ( (v3 & 1) == 0 )
        break;
    }
    sub_127712((int)&unk_1AB504, (int16_t)a2);
  }
  if ( !v32 )
    return 1;
  LOBYTE(v3) = 1 << v21;
  v33 = 1 << v21;
  while ( 1 )
  {
    nullsub_5(v3);
    v31 = 0;
    if ( v2 || v26 && !v28 )
    {
      v31 = 1;
      if ( !v2 && sub_9952D(v26) != -1 )
      {
        LOWORD(v6) = sub_9952D(v26);
        v30 = v6;
        if ( *(int16_t *)(dword_1930D4 + 17 * (int16_t)v6) == -1 )
        {
          v7 = sub_77B28(v6);
          sprintf(v23, (char *)dword_1AB138, v7);
          sub_77658((int)v23);
          if ( v8 )
          {
            if ( sub_9222A(a2) && !byte_199BE2 )
            {
              v9 = sub_923C4();
              v10 = sub_923BE();
              sub_92281(v10, v9, a2, 0);
            }
          }
          else
          {
            v30 = -1;
          }
          goto LABEL_25;
        }
      }
LABEL_18:
      sub_C8DB8(a2, v2 == 0);
      v30 = v5;
LABEL_25:
      while ( v2 && (v30 & 0x8000u) != 0 )
      {
        v11 = dword_17EC16 / 2;
        sprintf(v24, (char *)dword_1AB134, dword_17EC16 / 2);
        sub_77658((int)v24);
        if ( !v12 )
          goto LABEL_18;
        while ( v2 )
        {
          v27 = 3753 * v21;
          *(_DWORD *)(v27 + dword_197F98 + 50) += v11;
          v2[321] = 0;
          v2 = sub_FDA3F(v21, a2);
        }
      }
    }
    else
    {
      LOWORD(v13) = sub_9952D(v28);
      v30 = v13;
      if ( (int16_t)v13 == -1 || *(int16_t *)(dword_1930D4 + 17 * (int16_t)v13) != -1 )
      {
        v30 = sub_C8D49();
      }
      else
      {
        v14 = sub_77B28(v13);
        sprintf(v22, (char *)dword_1AB140, v14);
        sub_77658((int)v22);
        if ( v15 )
        {
          if ( sub_9222A(a2) && !byte_199BE2 )
          {
            v16 = sub_923C4();
            v17 = sub_923BE();
            sub_92281(v17, v16, a2, 0);
          }
        }
        else
        {
          v30 = -1;
        }
      }
    }
    if ( v26 )
      sub_A1BF4(v26);
    if ( v28 )
      sub_A1BF4(v28);
    if ( (v30 & 0x8000u) == 0 )
      break;
    sub_127712((int)&unk_1AB504, (int16_t)a2);
    v3 = dword_19306C;
    *(_BYTE *)(113 * (int16_t)a2 + dword_19306C + 53) |= v33;
LABEL_57:
    if ( !v2 )
      return 1;
  }
  if ( !v31 )
  {
    sub_E607F();
    sub_A163A((v28 - dword_197F9C) / 129, a2);
    v3 = sub_8A4C4();
    goto LABEL_57;
  }
  sub_E6071(v30, v21);
  if ( v2 )
  {
    sub_145EA((int)&v2[-dword_192B18] / 361, 0xBu, a2);
    v2 = sub_FDA3F(v21, a2);
  }
  else
  {
    sub_A163A((int)(v26 - dword_197F9C) / 129, a2);
    sub_8A4C4();
  }
  if ( !(uint16_t)sub_E60C8(dword_19306C + 113 * (int16_t)a2, v21) )
  {
    sub_127712((int)&unk_1AB504, (int16_t)a2);
    while ( v2 )
    {
      *(_DWORD *)(dword_197F98 + 3753 * v21 + 50) += dword_17EC16 / 2;
      v2[321] = 0;
      v2 = sub_FDA3F(v21, a2);
    }
  }
  if ( byte_199BE2 )
  {
    word_199A08 = 33;
    v18 = 17 * (int16_t)v30 + dword_1930D4;
    word_199A10 = 39;
    word_199A0E = 1;
    v19 = *(uint8_t *)(v18 + 2);
    LOWORD(v18) = *(uint8_t *)(v18 + 3);
    word_199830 = v19;
    word_199832 = v18;
    return 3;
  }
  return 1;
}
// FDB3B: variable 'v21' is possibly undefined
// FDC33: variable 'v5' is possibly undefined
// FDC46: variable 'v6' is possibly undefined
// FDC85: variable 'v8' is possibly undefined
// FDCFF: variable 'v12' is possibly undefined
// FDD4B: variable 'v13' is possibly undefined
// FDD9E: variable 'v15' is possibly undefined
// 919A3: using guessed type int __fastcall nullsub_5(_DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17EC16: using guessed type int dword_17EC16;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 19999A: using guessed type int16_t word_19999A;
// 199A08: using guessed type int16_t word_199A08;
// 199A0E: using guessed type int16_t word_199A0E;
// 199A10: using guessed type int16_t word_199A10;
// 199BE2: using guessed type char byte_199BE2;
// 1AB134: using guessed type int dword_1AB134;
// 1AB138: using guessed type int dword_1AB138;
// 1AB140: using guessed type int dword_1AB140;


//----- (000FDF93) --------------------------------------------------------
char __fastcall sub_FDF93( int a1, int a2)
{
  int16_t v2; // bx
  char *v3; // edx
  int v5; // edx
  int16_t v6; // bx

  v2 = a1;
  LOBYTE(a1) = a2;
  v3 = (char *)(361 * word_199996 + dword_192B18);
  do
  {
    if ( (unsigned int)v3 <= dword_192B18 )
      return 0;
    v3 -= 361;
  }
  while ( *v3 != v2 || v3[6] || *(int16_t *)(v3 + 277) != -1 );
  if ( (_BYTE)a1 )
  {
    nullsub_5(a1);
    v5 = 17 * *((int16_t *)v3 + 1);
    word_199A08 = 1;
    word_199A10 = 39;
    word_199A0E = 1;
    v6 = *(uint8_t *)(dword_1930D4 + v5 + 2);
    LOWORD(v5) = *(uint8_t *)(dword_1930D4 + v5 + 3);
    word_199830 = v6;
    word_199832 = v5;
  }
  return 3;
}
// 919A3: using guessed type int __fastcall nullsub_5(_DWORD);
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 199996: using guessed type int16_t word_199996;
// 199A08: using guessed type int16_t word_199A08;
// 199A0E: using guessed type int16_t word_199A0E;
// 199A10: using guessed type int16_t word_199A10;


//----- (000FE02C) --------------------------------------------------------
char __usercall sub_FE02C( int a1, int a2, int16_t *a3)
{
  char *v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // eax
  int v9; // edx
  int16_t v10; // ax
  int16_t v11; // ax

  v5 = (char *)(dword_192B18 + 361 * word_199996);
  v6 = (unsigned int)(v5 + 12);
  while ( (unsigned int)v5 > dword_192B18 )
  {
    v5 -= 361;
    v6 -= 361;
    if ( *v5 == a1 && v5[303] == 4 )
    {
      v7 = v6 + 4 * (uint8_t)v5[10];
      while ( v7 > v6 )
      {
        v7 -= 4;
        if ( (*(_BYTE *)(v7 + 1) & 4) != 0 )
        {
          if ( a2 )
          {
            nullsub_5(v7);
            v9 = 17 * *((int16_t *)v5 + 1) + dword_1930D4;
            v10 = *(uint8_t *)(v9 + 2);
            word_199A08 = 1;
            word_199830 = v10;
            v11 = *(uint8_t *)(v9 + 3);
            word_199A10 = 39;
            word_199832 = v11;
            sub_C058A(v6, a3);
          }
          return 1;
        }
      }
    }
  }
  return 0;
}
// 919A3: using guessed type int __fastcall nullsub_5(_DWORD);
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 199996: using guessed type int16_t word_199996;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;


//----- (000FE0EA) --------------------------------------------------------
void __fastcall sub_FE0EA( int a1, int a2)
{
  int v3; // esi
  _BOOL1 v4; // dh
  uint8_t *v5; // eax
  uint8_t v6; // dl
  char v7; // dl

  if ( (((int)(uint8_t)byte_1AB50F >> a1) & 1) != 0 || sub_EEC02(a1) <= 0 || !byte_199BDC )
    goto LABEL_36;
  v3 = sub_EEC02(a1);
  v4 = 0;
  v5 = (uint8_t *)&unk_1AA414 + 18 * v3 + 18 * sub_EEBF8(a1);
  while ( 1 )
  {
    v5 -= 18;
    v6 = *v5;
    --v3;
    if ( *v5 >= 8u )
      break;
    if ( v6 >= 4u )
    {
      if ( v6 <= 5u || v6 == 7 )
        goto LABEL_23;
LABEL_30:
      v4 = byte_199BE8 == 0;
      goto LABEL_31;
    }
    if ( v6 )
      goto LABEL_30;
    v7 = v5[3];
    if ( (uint8_t)v7 < 6u )
    {
      if ( v7 == 4 )
        goto LABEL_23;
    }
    else
    {
      if ( (uint8_t)v7 <= 8u )
        goto LABEL_31;
      if ( v7 == 9 )
        goto LABEL_23;
    }
    v4 = byte_199BE8 == 0;
LABEL_31:
    if ( !v3 || v4 )
    {
      if ( v4 )
      {
        if ( a2 )
        {
          word_199A08 = 40;
          word_199A10 = 39;
          word_199A0E = 1;
          byte_1AB50F |= 1 << a1;
        }
      }
LABEL_36:
      JUMPOUT(0xFE2E2);
    }
  }
  if ( *v5 <= 8u )
    goto LABEL_31;
  if ( v6 < 0x10u )
  {
    if ( v6 == 9 )
    {
      if ( *((int16_t *)v5 + 1) == -1 || !v5[7] )
        goto LABEL_31;
LABEL_23:
      v4 = 1;
      goto LABEL_31;
    }
  }
  else
  {
    if ( v6 <= 0x10u )
      goto LABEL_31;
    if ( v6 == 17 )
    {
      if ( v5[3] != word_19999C )
        v4 = byte_199BE8 == 0;
      goto LABEL_31;
    }
  }
  goto LABEL_30;
}
// FE24C: control flows out of bounds to FE2E2
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199A0E: using guessed type int16_t word_199A0E;
// 199A10: using guessed type int16_t word_199A10;
// 199BDC: using guessed type char byte_199BDC;
// 199BE8: using guessed type char byte_199BE8;
// 1AB50F: using guessed type char byte_1AB50F;


//----- (000FE251) --------------------------------------------------------
char __fastcall sub_FE251(int a1, int a2)
{
  int v3; // ecx
  int v4; // esi
  char v5; // bl
  int v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+4h] [ebp-Ch]
  char v9; // [esp+8h] [ebp-8h]

  v3 = (int16_t)a1;
  v8 = 3753 * (int16_t)a1;
  v4 = *(char *)(v8 + dword_197F98 + 1441);
  v9 = 0;
  if ( v4 != -1 )
  {
    v9 = 1;
    if ( a2 )
    {
      v5 = sub_C7ADA((int16_t)a1);
      v7 = (int16_t)sub_97A29(v3, v4);
      sub_9718F(v4, v3, v5, a1);
      if ( v5 )
      {
        *(_DWORD *)(v8 + dword_197F98 + 50) -= v7;
        sub_E2D72(v3, a1);
      }
      *(_BYTE *)(3753 * (int16_t)a1 + dword_197F98 + 1441) = -1;
    }
  }
  return v9;
}
// 197F98: using guessed type int dword_197F98;


//----- (000FE2E8) --------------------------------------------------------
char __usercall sub_FE2E8( int a1, int a2, int16_t *a3)
{
  int v3; // ebx
  char result; // al

  v3 = 3753 * a1;
  result = 0;
  if ( *(_BYTE *)(dword_197F98 + v3 + 48) )
  {
    result = 1;
    if ( a2 )
    {
      sub_10DB69(v3, a3);
      result = 2;
      *(_BYTE *)(dword_197F98 + v3 + 48) = 0;
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (000FE31F) --------------------------------------------------------
char __fastcall sub_FE31F( int a1, int a2)
{
  int v4; // eax
  char v5; // bl

  v4 = 3753 * a1 + dword_197F98;
  v5 = 0;
  if ( *(_BYTE *)(v4 + 341) == 3 && !*(_BYTE *)(v4 + 2269) )
  {
    v5 = 1;
    if ( a2 )
      sub_5B0AA(a1);
  }
  return v5;
}
// 197F98: using guessed type int dword_197F98;


//----- (000FE359) --------------------------------------------------------
void __fastcall sub_FE359( int a1, int a2)
{
  int16_t i; // bx
  int16_t v4; // ax
  int64_t v5[25]; // [esp+0h] [ebp-C8h] BYREF

  for ( i = 0; i < word_1AB502; ++i )
  {
    if ( a1 == *(int16_t *)((char *)&word_1AB14D + 19 * i) && a2 )
    {
      LOBYTE(v4) = 0;
      if ( byte_1AB14C[19 * i] == 1 )
      {
        HIBYTE(v4) = byte_1AB14F[19 * i];
        if ( !HIBYTE(v4) )
        {
          nullsub_5(v4);
          sub_10D041(a1);
          LOBYTE(v4) = 1;
        }
      }
      if ( !(_BYTE)v4 )
      {
        sub_FD69F(v5[0]);
        sub_77423((int)v5);
      }
      *(int16_t *)((char *)&word_1AB14D + 19 * i) = -1;
    }
  }
  JUMPOUT(0xFE2E2);
}
// FE403: control flows out of bounds to FE2E2
// 919A3: using guessed type int __fastcall nullsub_5(_DWORD);
// 1AB14D: using guessed type int16_t word_1AB14D;
// 1AB502: using guessed type int16_t word_1AB502;


//----- (000FE408) --------------------------------------------------------
void __fastcall sub_FE408(int16_t *a1, int a2)
{
  int v3; // ebx
  int v4; // esi
  int v5; // edx
  int v6; // eax

  v3 = 0;
  v4 = 0;
  while ( v3 < word_199998 )
  {
    if ( v3 != (int16_t)a1
      && (((int)*(uint8_t *)(dword_197F98 + 3753 * (int16_t)a1 + 3680) >> v3) & 1) == 0
      && *(_BYTE *)((int16_t)a1 + v4 + dword_197F98 + 1623)
      && a2 )
    {
      if ( (byte_199F3A == 2 || byte_199F3A == 3)
        && (v5 = dword_197F98 + v4, sub_20162(*(uint8_t *)(dword_197F98 + v4 + (int16_t)a1 + 1623))) )
      {
        sub_FA270(v3);
        while ( 1 )
        {
          LOBYTE(v6) = sub_FA2A9();
          if ( (_BYTE)v6 )
            break;
          sub_FE8BE(v6, v5, v3, a1);
        }
        sub_1AFA6(v3, 0, a1, v4);
        *(_BYTE *)(dword_197F98 + v4 + (int16_t)a1 + 1623) = 0;
        sub_FA2C5();
      }
      else
      {
        sub_1AFA6(v3, 0, a1, v4);
        *(_BYTE *)(dword_197F98 + v4 + (int16_t)a1 + 1623) = 0;
      }
    }
    v4 += 3753;
    ++v3;
  }
  JUMPOUT(0xFE2DF);
}
// FE50F: control flows out of bounds to FE2DF
// FE4B1: variable 'v6' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199F3A: using guessed type char byte_199F3A;


//----- (000FE514) --------------------------------------------------------
char __usercall sub_FE514( int a1, int a2, int a3)
{
  char v5; // dl

  v5 = 0;
  if ( (((int)(uint8_t)byte_1AB50E >> a1) & 1) == 0 )
  {
    if ( (uint16_t)sub_2023F() )
    {
      v5 = 7;
      if ( a2 )
      {
        sub_2027E(a3);
        byte_1AB50E |= 1 << a1;
      }
    }
  }
  return v5;
}
// 1AB50E: using guessed type char byte_1AB50E;


//----- (000FE552) --------------------------------------------------------
char __usercall sub_FE552( int a1, int16_t *a2)
{
  char v3; // dl
  int v4; // ecx
  int v5; // esi
  unsigned int v6; // eax

  v3 = 0;
  if ( dword_192FD8 - 1 == dword_1991B1 && (((int)(uint8_t)byte_1991B5 >> word_19999C) & 1) == 0 )
  {
    v3 = 6;
    if ( a1 )
    {
      v4 = -1;
      v5 = 0;
      v6 = dword_197F9C + 129 * word_199994;
      while ( v6 > dword_197F9C )
      {
        v6 -= 129;
        if ( *(_BYTE *)(v6 + 99) == 8 && *(_BYTE *)(v6 + 100) == 1 && v5 < *(uint8_t *)(v6 + 109) )
        {
          v5 = *(uint8_t *)(v6 + 109);
          v4 = *(int16_t *)(v6 + 101) - 500;
        }
      }
      if ( v4 == -1
        || (((int)*(uint8_t *)(113 * v4 + dword_19306C + 56) >> word_19999C) & 1) == 0
        || (int)sub_1247A0(0xAu) > 4 )
      {
        sub_C65E3();
        v3 = 1;
      }
      else
      {
        sub_14AAC(dword_1991B1 < 35000, a2);
      }
      byte_1991B5 |= 1 << word_19999C;
    }
  }
  return v3;
}
// 192FD8: using guessed type int dword_192FD8;
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 1991B1: using guessed type int dword_1991B1;
// 1991B5: using guessed type char byte_1991B5;
// 199994: using guessed type int16_t word_199994;
// 19999C: using guessed type int16_t word_19999C;


//----- (000FE63E) --------------------------------------------------------
void __usercall sub_FE63E( int a1, int16_t *a2)
{
  char v2; // al
  char v3; // bh
  int16_t v4; // [esp+0h] [ebp-8h]

  if ( (((int)(uint8_t)byte_1AB50D >> v4) & 1) == 0 && dword_192FD8 != 35000 )
  {
    v2 = sub_FE552(a1, a2);
    if ( !v2 )
    {
      v3 = 0;
      if ( (((int)(uint8_t)byte_1AB50E >> v4) & 1) == 0 )
      {
        if ( (uint16_t)sub_2023F() )
        {
          v3 = 7;
          if ( a1 )
          {
            sub_2027E((int)a2);
            byte_1AB50E |= 1 << v4;
          }
        }
      }
      v2 = v3;
      if ( !v3 )
      {
        v2 = sub_FD911(v4, a1, a2);
        if ( !v2 )
        {
          v2 = sub_FE2E8(v4, a1, a2);
          if ( !v2 )
          {
            v2 = sub_FE31F(v4, a1);
            if ( !v2 )
            {
              v2 = sub_FE251(v4, a1);
              if ( !v2 )
              {
                v2 = sub_FDB01(a1, (int)a2);
                if ( !v2 )
                {
                  sub_FD95A(v4, a1);
                  if ( !v2 )
                  {
                    v2 = sub_949A7(v4, a1);
                    if ( !v2 )
                    {
                      sub_FE359(v4, a1);
                      if ( !v2 )
                      {
                        sub_FE408((int16_t *)v4, a1);
                        if ( !v2 )
                        {
                          sub_FE0EA(v4, a1);
                          if ( !v2 )
                          {
                            v2 = sub_FDF93(v4, a1);
                            if ( !v2 )
                              v2 = sub_FE02C(v4, a1, a2);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( !v2 )
      byte_1AB50D |= 1 << v4;
  }
}
// FE658: variable 'v4' is possibly undefined
// FE724: variable 'v2' is possibly undefined
// 192FD8: using guessed type int dword_192FD8;
// 1AB50D: using guessed type char byte_1AB50D;
// 1AB50E: using guessed type char byte_1AB50E;


//----- (000FE785) --------------------------------------------------------
void __usercall sub_FE785(int16_t *a1)
{
  sub_FE63E(1, a1);
}


//----- (000FE793) --------------------------------------------------------
char __fastcall sub_FE793(int a1)
{
  int v2; // eax
  unsigned int v3; // ecx
  int16_t v4; // bx
  int16_t v5; // si
  _BYTE v7[16]; // [esp+0h] [ebp-18h] BYREF
  int16_t v8[2]; // [esp+10h] [ebp-8h] BYREF
  char v9; // [esp+14h] [ebp-4h]

  v2 = 129 * word_199994;
  v9 = 0;
  v3 = v2 + dword_197F9C;
  while ( v3 > dword_197F9C )
  {
    LOWORD(v2) = *(char *)(v3 - 30);
    v3 -= 129;
    if ( (_WORD)v2 == (_WORD)a1 )
    {
      if ( *(_BYTE *)(v3 + 128) )
      {
        *(_BYTE *)(v3 + 128) = 0;
        v9 = 1;
        if ( !*(_BYTE *)(v3 + 100) )
        {
          v4 = *(_WORD *)(v3 + 101);
          LOBYTE(v2) = sub_78C94(v4, a1);
          if ( (_BYTE)v2 )
          {
            v5 = sub_784F0(v4, a1);
            v8[0] = (int)(v3 - dword_197F9C) / 129;
            v8[1] = -1;
            LOBYTE(v2) = sub_FF799(v8, v5, v7);
            if ( v7[5] )
              LOBYTE(v2) = sub_FFD08(v8, v5, v7);
          }
        }
      }
    }
  }
  if ( v9 )
    LOBYTE(v2) = sub_E2D72((int16_t)a1, a1);
  return v2;
}
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000FE86B) --------------------------------------------------------
char __usercall sub_FE86B(int a1, int16_t *a2)
{
  int v3; // ebx
  int v4; // eax
  int v5; // edx
  uint8_t v6; // al
  int v7; // eax

  v3 = (int16_t)a1;
  v4 = 3753 * (int16_t)a1;
  v5 = dword_197F98;
  if ( *(_BYTE *)(dword_197F98 + v4 + 40) == 100 )
  {
    sub_FE63E(0, a2);
    v5 = v6;
  }
  else
  {
    LOBYTE(v5) = 0;
  }
  if ( !(_BYTE)v5 )
  {
    sub_FE793((int16_t)a1);
    LOBYTE(v7) = byte_199F3A;
    if ( (uint8_t)byte_199F3A >= 2u && (uint8_t)byte_199F3A <= 3u )
      sub_13822(v7, v5, v3, a1);
  }
  return v5;
}
// FE893: variable 'v6' is possibly undefined
// FE8B2: variable 'v7' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;


//----- (000FE8BE) --------------------------------------------------------
int __usercall sub_FE8BE(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // eax

  sub_1131F0(a1, a2);
  sub_F69FE(v4, a2, a3, a4);
}
// FE8C3: variable 'v4' is possibly undefined


//----- (000FE8C8) --------------------------------------------------------
int __fastcall sub_FE8C8(int a1, int a2)
{
  _DWORD *v2; // eax

  v2 = sub_110CEE(a1, 1);
  return nullsub_15(v2, a2);
}
// FE8D4: using guessed type int __fastcall nullsub_15(_DWORD, _DWORD);


//----- (000FE8DA) --------------------------------------------------------
int __fastcall sub_FE8DA(int a1, int a2)
{
  unsigned int v4; // eax
  int16_t i; // dx
  int v6; // ebx
  uint16_t v8; // bx
  int j; // edx
  uint8_t *v10; // eax

  v4 = 0;
  for ( i = 0; i < a2; ++i )
  {
    v6 = *(uint8_t *)(a1 + i);
    v4 += v6;
  }
  if ( !v4 )
    return -1;
  v8 = sub_1247A0(v4);
  for ( j = 0; ; ++j )
  {
    v10 = (uint8_t *)(a1 + (int16_t)j);
    if ( *v10 >= (int)v8 )
      break;
    v8 -= *v10;
  }
  return j;
}


//----- (000FE92D) --------------------------------------------------------
int __fastcall sub_FE92D(int a1, int a2)
{
  unsigned int v4; // eax
  int16_t i; // dx
  int v6; // ebx
  unsigned int v8; // edx
  int16_t j; // ax
  unsigned int v10; // ebx

  v4 = 0;
  for ( i = 0; i < a2; ++i )
  {
    v6 = *(uint16_t *)(a1 + 2 * i);
    v4 += v6;
  }
  if ( v4 )
  {
    v8 = sub_1247A0(v4);
    for ( j = 0; ; ++j )
    {
      v10 = *(uint16_t *)(a1 + 2 * j);
      if ( v10 >= v8 )
        break;
      v8 -= v10;
    }
    JUMPOUT(0xFE929);
  }
  return -1;
}
// FE968: control flows out of bounds to FE929


//----- (000FE96F) --------------------------------------------------------
int __fastcall sub_FE96F(int a1, int a2)
{
  unsigned int v4; // eax
  int16_t i; // dx
  int v6; // ebx
  unsigned int v8; // ebx
  int j; // edx
  unsigned int *v10; // eax

  v4 = 0;
  for ( i = 0; i < a2; ++i )
  {
    v6 = i;
    v4 += *(_DWORD *)(a1 + 4 * v6);
  }
  if ( !v4 )
    return -1;
  v8 = sub_1247A0(v4);
  for ( j = 0; ; ++j )
  {
    v10 = (unsigned int *)(a1 + 4 * (int16_t)j);
    if ( v8 <= *v10 )
      break;
    v8 -= *v10;
  }
  return j;
}


//----- (000FE9B5) --------------------------------------------------------
_BYTE *__fastcall sub_FE9B5(_BYTE *result, int a2)
{
  _BYTE *v2; // esi
  int i; // ebx
  char v4; // ch
  unsigned int v5; // [esp+0h] [ebp-4h]

  v2 = result;
  for ( i = 0; (int16_t)i < a2; ++i )
  {
    v5 = i + sub_1247A0(a2 - (int16_t)i) - 1;
    result = &v2[(int16_t)i];
    v4 = *result;
    *result = v2[(int16_t)v5];
    v2[(int16_t)v5] = v4;
  }
  return result;
}


//----- (000FE9F5) --------------------------------------------------------
void __fastcall sub_FE9F5(int a1, int a2)
{
  int i; // ebx
  int16_t v5; // dx
  unsigned int v6; // [esp+4h] [ebp-4h]

  for ( i = 0; (int16_t)i < a2; ++i )
  {
    v6 = i + sub_1247A0(a2 - (int16_t)i) - 1;
    v5 = *(_WORD *)(a1 + 2 * (int16_t)i);
    *(_WORD *)(a1 + 2 * (int16_t)i) = *(_WORD *)(a1 + 2 * (int16_t)v6);
    *(_WORD *)(a1 + 2 * (int16_t)v6) = v5;
  }
  JUMPOUT(0xFE9EF);
}
// FEA3A: control flows out of bounds to FE9EF


//----- (000FEA3C) --------------------------------------------------------
void __fastcall sub_FEA3C(int a1, int a2)
{
  int i; // ebx
  int v4; // [esp+0h] [ebp-8h]
  unsigned int v5; // [esp+4h] [ebp-4h]

  for ( i = 0; (int16_t)i < a2; ++i )
  {
    v5 = i + sub_1247A0(a2 - (int16_t)i) - 1;
    v4 = *(_DWORD *)(a1 + 4 * (int16_t)i);
    *(_DWORD *)(a1 + 4 * (int16_t)i) = *(_DWORD *)(a1 + 4 * (int16_t)v5);
    *(_DWORD *)(a1 + 4 * (int16_t)v5) = v4;
  }
  JUMPOUT(0xFE9EF);
}
// FEA7D: control flows out of bounds to FE9EF


//----- (000FEA82) --------------------------------------------------------
void __fastcall sub_FEA82(_BYTE *a1, unsigned int a2, int a3)
{
  int i; // ebx
  void *v4; // esi
  int16_t v5; // [esp+82h] [ebp-12h]
  int v6; // [esp+86h] [ebp-Eh]
  _BYTE v7[10]; // [esp+8Ah] [ebp-Ah] BYREF
  unsigned int v8; // [esp+112h] [ebp+7Eh]

  if ( a2 < 2u )
  {
    if ( a2 == 1 )
    {
      sub_FE9B5(a1, a3);
      return;
    }
  }
  else
  {
    if ( a2 <= 2u )
    {
      sub_FE9F5((int)a1, a3);
      return;
    }
    if ( a2 == 4 )
    {
      sub_FEA3C((int)a1, a3);
      return;
    }
  }
  for ( i = 0; (int16_t)i < v5; ++i )
  {
    v8 = i + sub_1247A0(v5 - (int16_t)i) - 1;
    if ( (_WORD)i != (_WORD)v8 )
    {
      qmemcpy(v7, (void *)((int16_t)a2 * (int16_t)i + v6), (int16_t)a2);
      v4 = (void *)((int16_t)a2 * (int16_t)v8 + v6);
      qmemcpy((void *)((int16_t)a2 * (int16_t)i + v6), v4, (int16_t)a2);
      qmemcpy(v4, v7, (int16_t)a2);
    }
  }
}
// FEACF: variable 'v5' is possibly undefined
// FEAFE: variable 'v6' is possibly undefined


//----- (000FEB40) --------------------------------------------------------
int __fastcall sub_FEB40( int a1)
{
  return a1 % 5 + 1;
}


//----- (000FEB51) --------------------------------------------------------
char *__fastcall sub_FEB51(int a1)
{
  if ( a1 >= word_19999A )
    return aAntares_1;
  else
    return (char *)(113 * a1 + dword_19306C);
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (000FEB70) --------------------------------------------------------
int __fastcall sub_FEB70(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v6; // ecx
  int v7; // edx
  int v9; // [esp+0h] [ebp-10h]

  v6 = 2;
  do
  {
    if ( !a1 )
    {
      v6 = -(a3 != 0);
      continue;
    }
    if ( a3 )
    {
      if ( a1 >= a2 )
      {
        if ( a4 <= a3 )
        {
          if ( a3 / a4 > a1 / a2 )
            goto LABEL_8;
          if ( a3 / a4 >= a1 / a2 )
          {
            a1 %= a2;
            v7 = a3 % a4;
            goto LABEL_11;
          }
        }
      }
      else
      {
        if ( a3 >= a4 || a2 / a1 > a4 / a3 )
        {
LABEL_8:
          v6 = -1;
          continue;
        }
        if ( a2 / a1 >= a4 / a3 )
        {
          v9 = a4 % a3;
          v7 = a2 % a1;
          a4 = a1;
          a2 = a3;
          a1 = v9;
LABEL_11:
          a3 = v7;
          continue;
        }
      }
    }
    v6 = 1;
  }
  while ( v6 == 2 );
  return v6;
}


//----- (000FEC20) --------------------------------------------------------
int __usercall sub_FEC20(int a1, int a2)
{
  char *v3; // ebx

  *(_BYTE *)(dword_197F98 + 3753 * a1 + 40) = sub_1247A0(5u);
  sub_57112(a1);
  v3 = (char *)(361 * word_199996 + dword_192B18);
  while ( (unsigned int)v3 > dword_192B18 )
  {
    v3 -= 361;
    if ( *v3 == a1 )
      sub_B20A1((int)&v3[-dword_192B18] / 361);
  }
  return sub_E2D72((int16_t)a1, a2);
}
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;


//----- (000FEC99) --------------------------------------------------------
int16_t __usercall sub_FEC99(int a1)
{
  int16_t result; // ax

  if ( byte_199F3A )
    return sub_77423((int)aThisIsnTASingl);
  result = word_19999C;
  byte_1ACE74 = 1;
  if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 40) == 100 )
    return sub_FEC20(word_19999C, a1);
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;
// 1ACE74: using guessed type char byte_1ACE74;


//----- (000FECDA) --------------------------------------------------------
unsigned int sub_FECDA()
{
  char *v0; // eax
  char *v1; // eax
  char *v2; // eax
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  _BYTE v7[20]; // [esp+0h] [ebp-14h] BYREF

  sprintf(v7, "rstring%d.lbx", (uint8_t)byte_199CAE);
  sub_126C91((int)v7, 0, (int)byte_1AB510, 0, 1u, 6500);
  v0 = (char *)sub_DD4FD(byte_1AB510);
  v1 = (char *)sub_E6828(v0);
  v2 = (char *)sub_EE4A1(v1);
  v3 = (char *)sub_F5883(v2);
  v4 = (char *)sub_FA991(v3);
  v5 = (char *)sub_FBFAF(v4);
  return sub_FD5EE(v5);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 199CAE: using guessed type char byte_199CAE;


//----- (000FED3F) --------------------------------------------------------
void __fastcall sub_FED3F(int a1, int a2, int a3)
{
  sub_EBEB7(a2, a3);
}


//----- (000FED77) --------------------------------------------------------
_BOOL1 __fastcall sub_FED77(char *a1, int a2, int a3)
{
  int v4; // esi
  char *v5; // ebx
  int v6; // edi
  int v7; // ebx
  int v9; // [esp+0h] [ebp-14h]
  int v10; // [esp+4h] [ebp-10h]
  int v11; // [esp+Ch] [ebp-8h]

  v11 = 3753 * *a1 + dword_197F98;
  v4 = 0;
  v10 = (int16_t)sub_E0C1D(a1, a2);
  v5 = &a1[4 * (uint8_t)a1[10] + 12];
  while ( a1 + 12 < v5 )
  {
    v5 -= 4;
    if ( (int16_t)sub_E0C1D(a1, *(_WORD *)v5 & 0xF) <= v10 )
      ++v4;
  }
  if ( a3 )
  {
    v6 = *(int16_t *)(v11 + 64);
    v7 = v11 + 4 * v6;
    while ( v6 > 0 )
    {
      v9 = *(int16_t *)(17 * (*(_DWORD *)(v7 + 62) << 16 >> 24) + dword_1930D4);
      v7 -= 4;
      --v6;
      if ( (int)&a1[-dword_192B18] / 361 == v9
        && (int16_t)sub_E0C1D(a1, (uint16_t)(*(_DWORD *)(v7 + 66) >> 4) >> 12) <= v10 )
      {
        ++v4;
      }
    }
  }
  return v4 < v10;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000FEE4C) --------------------------------------------------------
void __fastcall sub_FEE4C(char *a1, int a2, int a3, _BYTE *a4)
{
  char v5; // al
  int v6; // [esp+0h] [ebp-14h]
  int16_t v7; // [esp+Ch] [ebp-8h]
  int16_t v8; // [esp+10h] [ebp-4h]

  v6 = 3753 * *a1 + dword_197F98;
  v7 = *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 2);
  v8 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(a3 + 2) + 2);
  memset(a4, 0, 15);
  if ( *a1 == *(_BYTE *)a3 )
  {
    if ( (((int)*(uint8_t *)(dword_19306C + 113 * v7 + 42) >> *a1) & 1) != 0 )
    {
      a4[2] = 1;
    }
    else if ( sub_2341E((int)&a1[-dword_192B18] / 361) )
    {
      a4[3] = 1;
    }
    else if ( sub_234B8((int)&a1[-dword_192B18] / 361) )
    {
      a4[8] = 1;
    }
    else if ( *(_BYTE *)(a3 + 6) )
    {
      a4[4] = 1;
    }
    else if ( a1[10] == 1 )
    {
      a4[5] = 1;
    }
    else if ( (a1[4 * a2 + 13] & 4) != 0 )
    {
      a4[14] = 1;
    }
    else if ( a1 == (char *)a3 )
    {
      *a4 = 1;
    }
    else if ( v7 == v8 || *(int16_t *)(v6 + 54) >= 5 * (*(int16_t *)(v6 + 64) + 1) )
    {
      if ( v7 == v8 || *(_WORD *)(v6 + 64) != 25 )
      {
        if ( !sub_FED77((char *)a3, *(_WORD *)&a1[4 * a2 + 12] & 0xF, 1) )
          a4[9] = 1;
        if ( (((int)*(uint8_t *)(113 * v8 + dword_19306C + 42) >> *(_BYTE *)a3) & 1) != 0 )
          a4[11] = 1;
        if ( sub_2341E((a3 - dword_192B18) / 361) )
          a4[12] = 1;
        sub_FED3F(v6, v7, v8);
        *a4 = 1;
        a4[13] = v5;
      }
      else
      {
        a4[7] = 1;
      }
    }
    else
    {
      a4[6] = 1;
    }
  }
  else
  {
    a4[1] = 1;
  }
}
// FF00E: variable 'v5' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000FF015) --------------------------------------------------------
_BOOL1 __fastcall sub_FF015(unsigned int a1, int a2)
{
  unsigned int v2; // esi
  int v4; // ebx
  _DWORD *v5; // eax
  _DWORD *v6; // edx
  _BYTE *v7; // eax
  unsigned int v9; // [esp+0h] [ebp-8h]
  char v10; // [esp+4h] [ebp-4h]

  v2 = a1;
  v10 = 0;
  if ( sub_FED77((char *)a2, (uint16_t)(a1 >> 4) >> 12, 0) )
  {
    if ( (v2 & 0x3000000) == 0 )
    {
      v4 = 0;
      v5 = 0;
      v9 = a2 + 12;
      v6 = (_DWORD *)(a2 + 12 + 4 * *(uint8_t *)(a2 + 10));
      while ( (unsigned int)v6 > v9 )
      {
        if ( (*(_WORD *)--v6 & 0x180) == 0 )
        {
          ++v4;
          if ( !v5 && (*v6 & 0xFu) < 8 )
            v5 = v6;
        }
      }
      if ( *(uint8_t *)(a2 + 224) <= v4 )
      {
        if ( (v2 & 0xF0000) >= (unsigned int)&loc_80000 )
        {
          if ( v5 )
          {
            *(_WORD *)v5 &= 0xFE7Fu;
            *((_BYTE *)v5 + 1) |= 1u;
          }
        }
        else
        {
          v2 = v2 & 0xFCFFFFFF | 0x2000000;
        }
      }
    }
  }
  else
  {
    v10 = 1;
  }
  if ( !v10 )
  {
    v7 = (_BYTE *)(a2 + 12 + 4 * *(uint8_t *)(a2 + 10));
    *v7 &= 0xF0u;
    *(_DWORD *)v7 |= (uint8_t)(v2 << 12 >> 24) >> 4;
    *v7 &= 0x8Fu;
    *(_DWORD *)v7 |= 16 * ((v2 << 12 >> 28) & 7);
    *(_WORD *)v7 &= 0xFE7Fu;
    *(_DWORD *)v7 |= (uint8_t)(v2 << 6 >> 24) >> 6 << 7;
    v7[1] |= 2u;
    v7[1] &= ~4u;
    ++*(_BYTE *)(a2 + 10);
  }
  return v10 == 0;
}


//----- (000FF116) --------------------------------------------------------
char *__fastcall sub_FF116(char *result, int a2, int a3, int a4)
{
  char *v4; // esi
  int v5; // edi
  int16_t v6; // ax
  unsigned int v7; // ecx
  char v8; // al
  unsigned int v9; // ecx
  int v10; // ecx
  int16_t v11; // [esp+Ch] [ebp-4h]

  v4 = result;
  if ( result != (char *)a3 )
  {
    v5 = dword_197F98 + 3753 * *result;
    v11 = *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)result + 1) + 2);
    v6 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(a3 + 2) + 2);
    v7 = ((uint8_t)(*(_DWORD *)&v4[4 * a2 + 12] << 23 >> 24) >> 6 << 24)
       | ((*(_DWORD *)&v4[4 * a2 + 12] & 0xF) << 16) & 0xFCFFFFFF
       | a4 & 0xFCF0FFFF;
    if ( v6 == v11 )
    {
      sub_FF015(v7, a3);
    }
    else
    {
      sub_FED3F(v5, v11, v6);
      v9 = ((v8 & 0xF) << 20) | v7 & 0xFF0FFFFF;
      LOBYTE(v9) = 0;
      v10 = (uint8_t)((int)&v4[-dword_192B18] / 361) | v9;
      BYTE1(v10) = 0;
      *(_DWORD *)(v5 + 4 * (int16_t)(*(_WORD *)(v5 + 64))++ + 66) = ((uint8_t)*(_WORD *)(a3 + 2) << 8) | v10;
    }
    result = *(char **)&v4[4 * (uint8_t)--v4[10] + 12];
    *(_DWORD *)&v4[4 * a2 + 12] = result;
  }
  return result;
}
// FF1B7: variable 'v8' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000FF212) --------------------------------------------------------
int sub_FF212()
{
  int v0; // edi
  unsigned int v1; // esi
  int v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  char *v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  _BYTE v9[360]; // [esp+0h] [ebp-310h] BYREF
  _BYTE v10[360]; // [esp+168h] [ebp-1A8h] BYREF
  int v11; // [esp+2D0h] [ebp-40h] BYREF
  int v12; // [esp+2D4h] [ebp-3Ch]
  int v13; // [esp+2D8h] [ebp-38h]
  int v14; // [esp+2DCh] [ebp-34h]
  int16_t v15; // [esp+2E0h] [ebp-30h]
  int v16; // [esp+2E4h] [ebp-2Ch]
  unsigned int v17; // [esp+2E8h] [ebp-28h]
  unsigned int v18; // [esp+2ECh] [ebp-24h]
  int v19; // [esp+2F0h] [ebp-20h]
  int v20; // [esp+2F4h] [ebp-1Ch]
  int v21; // [esp+2F8h] [ebp-18h]
  int v22; // [esp+2FCh] [ebp-14h]
  unsigned int v23; // [esp+300h] [ebp-10h]
  unsigned int v24; // [esp+304h] [ebp-Ch]
  int v25; // [esp+308h] [ebp-8h]
  char v26; // [esp+30Ch] [ebp-4h]

  v18 = 3753 * word_199998 + dword_197F98;
  v24 = v18 + 66;
  while ( 1 )
  {
    result = dword_197F98;
    if ( dword_197F98 >= v18 )
      break;
    v24 -= 3753;
    v18 -= 3753;
    memset(v9, 0, sizeof(v9));
    v26 = 0;
    memset(v10, 0, sizeof(v10));
    v0 = 0;
    v17 = v24;
    v1 = v18;
    v23 = v24 + 4;
    while ( v0 < *(int16_t *)(v18 + 64) )
    {
      v2 = ((*(_DWORD *)(v1 + 66) << 8 >> 28) - 1) & 0xF;
      *(_BYTE *)(v1 + 68) &= 0xFu;
      *(_DWORD *)(v1 + 66) |= v2 << 20;
      *(_BYTE *)(v1 + 66) = 0;
      *(_BYTE *)(v1 + 66) |= 0xFAu;
      if ( (*(_BYTE *)(v1 + 68) & 0xF0) != 0 )
      {
        v17 += 4;
        v23 += 4;
        v1 += 4;
        ++v0;
      }
      else
      {
        v3 = *(_DWORD *)(v1 + 66) << 16 >> 24;
        v20 = 17 * v3;
        v4 = 17 * v3 + dword_1930D4;
        ++v9[v3];
        v22 = *(uint8_t *)(v4 + 2);
        v19 = *(uint8_t *)(113 * v22 + dword_19306C + 42);
        v26 = 1;
        if ( ((v19 >> ((int)(v18 - dword_197F98) / 3753)) & 1) == 0 && !sub_242CF(v22) )
        {
          v5 = *(int16_t *)(v20 + dword_1930D4);
          if ( v5 != -1 )
          {
            v6 = (char *)(361 * v5 + dword_192B18);
            if ( !v6[6] )
            {
              v19 = *v6;
              v21 = 3753;
              if ( (int)(v18 - dword_197F98) / 3753 == v19 && !sub_FF015(*(_DWORD *)(v1 + 66), (int)v6) )
                ++v10[v3];
            }
          }
        }
        v7 = v18;
        --*(_WORD *)(v18 + 64);
        memmove(v17, v23, 4 * (*(int16_t *)(v7 + 64) - v0));
      }
    }
    if ( v26 )
    {
      v25 = 360;
      v16 = 6120;
      do
      {
        --v25;
        v16 -= 17;
        if ( v9[v25] )
        {
          memset(&v11, 0, 18);
          BYTE2(v11) = v25;
          LOBYTE(v12) = v9[v25];
          BYTE1(v12) = v10[v25];
          LOBYTE(v11) = 0;
          HIBYTE(v11) = 5;
          BYTE2(v12) = ((int)*(uint8_t *)(113 * *(uint8_t *)(v16 + dword_1930D4 + 2) + dword_19306C + 42) >> ((int)(v18 - dword_197F98) / 3753))
                     & 1;
          sub_EF629(v11, v12, v13, v14, v15, (int)(v18 - dword_197F98) / 3753);
        }
      }
      while ( v25 > 0 );
    }
  }
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000FF477) --------------------------------------------------------
int __fastcall sub_FF477( int a1)
{
  return *(int16_t *)(dword_197F98 + 3753 * a1 + 54) - 5 * *(int16_t *)(dword_197F98 + 3753 * a1 + 64);
}
// 197F98: using guessed type int dword_197F98;


//----- (000FF496) --------------------------------------------------------
int __fastcall sub_FF496(int a1)
{
  int v2; // ebx

  if ( *(char *)(a1 + 99) >= 8 )
    return 255;
  v2 = 3753 * *(char *)(a1 + 99);
  LOWORD(v2) = *(_WORD *)(dword_197F98 + v2 + 804);
  if ( (uint16_t)sub_1276F0(a1 + 23, 0xBu) )
    return (3 * (int16_t)v2 + 1) / 2;
  return v2;
}
// 197F98: using guessed type int dword_197F98;


//----- (000FF4E9) --------------------------------------------------------
char __fastcall sub_FF4E9(int a1, int a2, int a3)
{
  int v4; // edx
  char v5; // ch
  unsigned int v6; // ebx
  int v7; // edi
  int v8; // edx
  int v10; // [esp+0h] [ebp-14h]
  int v11; // [esp+8h] [ebp-Ch]
  int v12; // [esp+Ch] [ebp-8h]

  v12 = (a1 - dword_19306C) / 113;
  v4 = a3 * 900 * a3;
  v5 = 0;
  v6 = 113 * word_19999A + dword_19306C;
  v11 = v4;
  v7 = v6 + 31;
  while ( v6 > dword_19306C )
  {
    v7 -= 113;
    v8 = (int)*(uint8_t *)(v6 - 57) >> a2;
    v6 -= 113;
    if ( (v8 & 1) != 0 && !(uint16_t)sub_1276F0(v7, (int16_t)v12) )
    {
      v10 = *(int16_t *)(a1 + 15) - *(int16_t *)(v6 + 15);
      if ( v10 * v10 + (*(int16_t *)(a1 + 17) - *(int16_t *)(v6 + 17)) * (*(int16_t *)(a1 + 17) - *(int16_t *)(v6 + 17)) <= v11 )
        return 1;
    }
  }
  return v5;
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (000FF593) --------------------------------------------------------
void __fastcall sub_FF593(int a1, int a2, int a3)
{
  int v4; // eax
  int v5; // eax

  if ( (((int)*(uint8_t *)(a1 + 56) >> a2) & 1) != 0
    || sub_FF4E9(a1, a2, a3)
    || (v4 = *(char *)(a1 + 41), v4 != -1)
    && (v5 = dword_19306C + 113 * v4, (((int)*(uint8_t *)(v5 + 51) >> a2) & 1) != 0)
    && sub_FF4E9(v5, a2, a3) )
  {
    JUMPOUT(0xFF58A);
  }
  JUMPOUT(0xFF58C);
}
// FF5F6: control flows out of bounds to FF58A
// FF5D0: control flows out of bounds to FF58C
// 19306C: using guessed type int dword_19306C;


//----- (000FF5F8) --------------------------------------------------------
char __fastcall sub_FF5F8(int a1, int a2, int a3)
{
  char v4; // al
  int v5; // ecx
  char v6; // al
  char v8; // [esp+4h] [ebp-4h]

  v8 = 0;
  sub_FF593(a1, a2, a3);
  if ( v4 )
    return 1;
  v5 = word_199998;
  while ( v5 > 0 )
  {
    if ( --v5 != a2 && *(_BYTE *)(v5 + dword_197F98 + 3753 * a2 + 1575) == 2 )
    {
      sub_FF593(a1, v5, a3);
      if ( v6 )
        return 1;
    }
  }
  return v8;
}
// FF617: variable 'v4' is possibly undefined
// FF658: variable 'v6' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000FF666) --------------------------------------------------------
char __fastcall sub_FF666(int a1, int a2)
{
  return sub_FF5F8(a1, a2, *(_WORD *)(3753 * a2 + dword_197F98 + 804));
}
// 197F98: using guessed type int dword_197F98;


//----- (000FF68A) --------------------------------------------------------
char __fastcall sub_FF68A(int a1, int a2)
{
  return sub_FF5F8(a1, a2, 3 * *(int16_t *)(dword_197F98 + 3753 * a2 + 804) / 2);
}
// 197F98: using guessed type int dword_197F98;


//----- (000FF6BE) --------------------------------------------------------
char __fastcall sub_FF6BE(int a1)
{
  uint8_t v2; // al
  _BYTE *v3; // edi
  unsigned int v4; // edi
  int16_t v5; // dx
  int16_t v6; // ax
  int v7; // eax
  uint8_t v9; // [esp+0h] [ebp-8h]
  char v10; // [esp+4h] [ebp-4h]

  v10 = 0;
  if ( *(char *)(a1 + 99) < word_199998 )
  {
    v2 = *(_BYTE *)(a1 + 100);
    if ( !v2 )
      return 1;
    if ( v2 <= 1u )
    {
      v3 = (_BYTE *)(3753 * *(char *)(a1 + 99) + dword_197F98);
      if ( v3[370] == 3 )
        return 1;
      if ( v3[459] == 3 || v3[455] == 3 )
      {
        v9 = 1 << *(_BYTE *)(a1 + 99);
        v4 = 113 * word_19999A + dword_19306C;
        while ( v4 > dword_19306C )
        {
          v5 = *(_WORD *)(v4 - 96);
          v6 = *(_WORD *)(v4 - 98);
          v4 -= 113;
          sub_EBE79(v6, v5, *(_WORD *)(a1 + 103), *(_WORD *)(a1 + 105));
          if ( v7 <= 5 && ((v9 & *(_BYTE *)(v4 + 60)) != 0 || v7 <= 2 && (v9 & *(_BYTE *)(v4 + 59)) != 0) )
            return 1;
        }
      }
    }
    else if ( v2 == 2 )
    {
      return 1;
    }
  }
  return v10;
}
// FF768: variable 'v7' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (000FF799) --------------------------------------------------------
char __fastcall sub_FF799(int16_t *a1, int a2, _BYTE *a3)
{
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v9; // eax
  int v10; // eax
  int16_t *v11; // ebx
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // eax
  int16_t v16; // ax
  int v17; // eax
  int16_t v18; // ax
  char v19; // al
  int v20; // eax
  char *v21; // eax
  int16_t *v25; // [esp+8h] [ebp-54h]
  int v26; // [esp+Ch] [ebp-50h]
  int16_t v27; // [esp+10h] [ebp-4Ch]
  int v28; // [esp+14h] [ebp-48h]
  int v29; // [esp+18h] [ebp-44h]
  int v30; // [esp+1Ch] [ebp-40h]
  int v31; // [esp+20h] [ebp-3Ch]
  char v32; // [esp+24h] [ebp-38h]
  int v33; // [esp+28h] [ebp-34h]
  int v34; // [esp+2Ch] [ebp-30h]
  int v35; // [esp+30h] [ebp-2Ch]
  int v36; // [esp+34h] [ebp-28h]
  int v37; // [esp+38h] [ebp-24h]
  int v38; // [esp+3Ch] [ebp-20h]
  int v39; // [esp+40h] [ebp-1Ch] BYREF
  int v40; // [esp+44h] [ebp-18h]
  int v41; // [esp+48h] [ebp-14h]
  int v42; // [esp+4Ch] [ebp-10h] BYREF
  char v43; // [esp+50h] [ebp-Ch]
  char v44; // [esp+54h] [ebp-8h] BYREF
  _BYTE v45[4]; // [esp+58h] [ebp-4h] BYREF

  v4 = 113 * a2 + dword_19306C;
  v5 = 129 * *a1;
  v28 = 0;
  v29 = 0;
  v43 = 0;
  v36 = 0;
  v6 = *(char *)(dword_197F9C + v5 + 99);
  v26 = 30000;
  v35 = v6;
  if ( v6 >= 8 )
    v7 = 1;
  else
    v7 = *(uint8_t *)(dword_197F98 + 3753 * v6 + 1440);
  v33 = v7;
  LOBYTE(v27) = -1;
  memset(a3, 0, 14);
  v37 = 0;
  if ( a2 != word_19999A && v35 < 8 && !*(_BYTE *)(dword_197F98 + 3753 * v35 + 2236) )
  {
    LOWORD(v9) = sub_233FA();
    if ( (_WORD)v9 )
    {
      a3[13] = 1;
      return v9;
    }
  }
  v25 = a1;
  do
  {
    ++v36;
    v10 = *v25++;
    v34 = v10;
    if ( v10 == -1 )
      continue;
    v11 = (int16_t *)(129 * v10 + dword_197F9C);
    v12 = sub_FF496((int)v11);
    v13 = v11[58];
    v40 = v12;
    if ( v13 != -1 )
    {
      v14 = dword_1930DC + 59 * v13;
      if ( !*(_BYTE *)(v14 + 55) )
      {
        v41 = 0;
        if ( (*(_BYTE *)(v14 + 43) & 2) != 0 )
        {
          v15 = (int16_t)sub_94951(v13) / 3;
        }
        else
        {
          if ( (*(_BYTE *)(v14 + 43) & 1) == 0 )
            goto LABEL_21;
          v16 = sub_94951(v13);
          v15 = (int)(v16 - (__CFSHL__((uint64_t)v16 >> 32, 2) + 4 * ((uint64_t)v16 >> 32))) >> 2;
        }
        v41 = v15 + 1;
LABEL_21:
        if ( (int16_t)v41 > v37 )
          v37 = (int16_t)v41;
      }
    }
    if ( !v43 )
    {
      v28 = *(int16_t *)((char *)v11 + 103);
      v17 = *(int16_t *)((char *)v11 + 105);
      v43 = 1;
      v29 = v17;
    }
    if ( (int16_t)v40 < v26 )
      v26 = (int16_t)v40;
  }
  while ( v34 != -1 );
  v38 = (int16_t)sub_7A3E3(v28, v29);
  if ( a2 == word_19999A && v38 != -1 )
  {
    v9 = (int)*(uint8_t *)(dword_19306C + 113 * v38 + 64) >> *(_BYTE *)(dword_197F9C + 129 * *a1 + 99);
    if ( (v9 & 1) != 0 )
    {
      a3[4] = 1;
      goto LABEL_32;
    }
  }
  if ( v35 < 8 && !sub_FF5F8(v4, *(char *)(dword_197F9C + 129 * *a1 + 99), v26) )
  {
    v18 = sub_E6BCD(a2, (int)a3);
    if ( v18 != -1 )
    {
      sub_EBEB7(v18, a2);
      a3[9] = v19;
    }
    a3[6] = 1;
  }
  if ( v35 < 8 )
  {
    if ( v38 < 0 )
    {
      if ( sub_EB7FD(v28, v29, *(int16_t *)(v4 + 15), *(int16_t *)(v4 + 17)) )
        goto LABEL_55;
    }
    else
    {
      v20 = dword_19306C + 113 * v38;
      if ( *(char *)(v20 + 41) == a2 )
        a3[10] = 1;
      if ( (((int)*(uint8_t *)(v20 + 61) >> v35) & 1) != 0
        && (((int)*(uint8_t *)(v4 + 61) >> v35) & 1) != 0 )
      {
        a3[12] = 1;
      }
      if ( (((int)*(uint8_t *)(v20 + 62) >> v35) & 1) != 0
        && (((int)*(uint8_t *)(v4 + 62) >> v35) & 1) != 0 )
      {
        a3[11] = 1;
      }
      if ( (uint16_t)sub_1276F0(v20 + 31, a2) && !v37 && !a3[10] && !a3[12] && !a3[11] )
LABEL_55:
        *a3 = 1;
    }
  }
  if ( a3[12] || a3[10] )
  {
    a3[4] = a2 != v38;
  }
  else if ( v33 <= 0 )
  {
    a3[2] = 1;
  }
  else
  {
    v30 = *(int16_t *)(v4 + 15);
    v31 = *(int16_t *)(v4 + 17);
    v39 = v28;
    v42 = v29;
    v32 = 0;
    v27 = v37 + v33;
    if ( a3[11] )
      v27 += 3;
    while ( (int16_t)v39 != v30 || (int16_t)v42 != v31 )
    {
      if ( v37 )
        v21 = 0;
      else
        v21 = &v44;
      ++v32;
      sub_EBB0C(v35, v39, v42, a2, v27, (int16_t *)&v39, (int16_t *)&v42, v21, v45);
    }
    a3[4] = v32;
  }
  LOBYTE(v9) = v37 > 0;
  a3[7] = v37 > 0;
  if ( (!*a3 || a3[11] || a3[12] || v37 > 0)
    && !a3[6]
    && (v33 || (v9 = *(int16_t *)(v4 + 15), v9 == v28) && (v9 = *(int16_t *)(v4 + 17), v9 == v29)) )
  {
    if ( a3[12] || a3[10] )
    {
LABEL_32:
      a3[8] = -1;
      a3[5] = 1;
    }
    else
    {
      LOBYTE(v9) = v27;
      a3[5] = 1;
      a3[8] = v27;
    }
  }
  else
  {
    a3[4] = -1;
    a3[5] = 0;
  }
  return v9;
}
// FF9F8: variable 'v19' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 19999A: using guessed type int16_t word_19999A;


//----- (000FFBD6) --------------------------------------------------------
int __fastcall sub_FFBD6( int a1, int a2, int a3)
{
  int v4; // ebx
  int v5; // esi
  int v6; // esi
  int v7; // eax
  char v8; // ch
  int v9; // eax
  int v12; // [esp+8h] [ebp-1Ch] BYREF
  int v13; // [esp+Ch] [ebp-18h]
  int v14; // [esp+10h] [ebp-14h]
  int v15; // [esp+14h] [ebp-10h]
  int v16; // [esp+18h] [ebp-Ch] BYREF
  _BYTE v17[4]; // [esp+1Ch] [ebp-8h] BYREF
  _BYTE v18[4]; // [esp+20h] [ebp-4h] BYREF

  v4 = dword_19306C + 113 * a2;
  v5 = 113 * a3 + dword_19306C;
  if ( a2 == a3 )
    return 0;
  if ( (((int)*(uint8_t *)(v4 + 61) >> a1) & 1) != 0 && (((int)*(uint8_t *)(v5 + 61) >> a1) & 1) != 0
    || *(char *)(v4 + 41) == a3 )
  {
    return 1;
  }
  v7 = 3753 * a1;
  LOWORD(v7) = *(uint8_t *)(dword_197F98 + v7 + 1440);
  v13 = v7;
  v8 = 0;
  v9 = a1;
  if ( (((int)*(uint8_t *)(v4 + 62) >> a1) & 1) != 0 )
  {
    v9 = (int)*(uint8_t *)(v5 + 62) >> a1;
    if ( (v9 & 1) != 0 )
    {
      v8 = 1;
      v13 += 3;
    }
  }
  if ( !v8 )
  {
    v9 = sub_1276F0(v4 + 31, a3);
    if ( (_WORD)v9 )
      return -1;
  }
  if ( !(_WORD)v13 )
    return -1;
  LOWORD(v9) = *(_WORD *)(v4 + 15);
  v12 = v9;
  LOWORD(v9) = *(_WORD *)(v4 + 17);
  v16 = v9;
  LOWORD(v9) = *(_WORD *)(v5 + 15);
  v15 = v9;
  LOWORD(v9) = *(_WORD *)(v5 + 17);
  v14 = v9;
  v6 = 0;
  while ( (_WORD)v12 != (_WORD)v15 || (_WORD)v16 != (_WORD)v14 )
  {
    ++v6;
    sub_EBB0C(a1, v12, v16, a3, v13, (int16_t *)&v12, (int16_t *)&v16, v18, v17);
  }
  return v6;
}
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;


//----- (000FFD08) --------------------------------------------------------
int __fastcall sub_FFD08(int16_t *a1, int a2, _BYTE *a3)
{
  int16_t v4; // si
  int v5; // eax
  int16_t v6; // si
  int16_t v7; // si
  int16_t v8; // ax
  int v9; // eax
  int result; // eax
  int16_t v11; // [esp+0h] [ebp-Ch]
  int16_t v12; // [esp+4h] [ebp-8h]
  char v13; // [esp+8h] [ebp-4h]

  v12 = 0;
  v13 = 0;
  if ( a3[4] )
  {
    v5 = 129 * *a1 + dword_197F9C;
    if ( *(int16_t *)(v5 + 101) >= 72 && *(int16_t *)(v5 + 101) < 1000 )
    {
      v7 = a2;
      LOBYTE(a2) = 1;
      v4 = v7 + 500;
    }
    else
    {
      v6 = a2;
      LOBYTE(a2) = 2;
      v4 = v6 + 1000;
    }
  }
  else
  {
    v4 = a2;
    LOBYTE(a2) = 0;
  }
  do
  {
    v8 = a1[v12];
    v11 = v8;
    if ( v8 != -1 )
    {
      v9 = dword_197F9C + 129 * v8;
      if ( !v13 && (*(_BYTE *)(v9 + 17) == 1 || *(_BYTE *)(v9 + 17) == 4) )
        v13 = 1;
      *(_WORD *)(v9 + 101) = v4;
      *(_BYTE *)(v9 + 109) = a3[4];
      *(_BYTE *)(v9 + 107) = a3[7];
      HIBYTE(a2) = a3[8];
      sub_16915C(v9, a2);
    }
    result = v11;
    ++v12;
  }
  while ( v11 != -1 );
  if ( v13 )
    return sub_A1C0D((int)a1);
  return result;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (000FFDDA) --------------------------------------------------------
int __fastcall sub_FFDDA(int a1, int a2)
{
  int v3; // ecx
  int result; // eax
  int v5; // esi
  int v6; // eax
  int v7; // esi

  *(_BYTE *)(a1 + 100) = 0;
  *(_WORD *)(a1 + 101) = a2;
  v3 = dword_19306C;
  result = dword_19306C + 113 * a2;
  *(_WORD *)(a1 + 103) = *(_WORD *)(result + 15);
  *(_WORD *)(a1 + 105) = *(_WORD *)(result + 17);
  v5 = 113 * *(int16_t *)(a1 + 101);
  *(_BYTE *)(a1 + 127) = 0;
  *(_BYTE *)(v3 + v5 + 54) = 0;
  if ( *(char *)(a1 + 99) >= 8 )
  {
    if ( *(_BYTE *)(a1 + 99) == 13 )
      *(_WORD *)(a1 + 97) = 0;
  }
  else
  {
    if ( *(_BYTE *)(result + 40) == 11 && !*(_BYTE *)(result + 51) )
      sub_233B8(*(_BYTE *)(a1 + 99));
    if ( *(_BYTE *)(a1 + 17) == 1 || *(_BYTE *)(a1 + 17) == 4 )
    {
      v6 = 113 * *(int16_t *)(a1 + 101) + dword_19306C;
      *(_BYTE *)(v6 + 53) &= ~(1 << *(_BYTE *)(a1 + 99));
    }
    v7 = dword_19306C;
    result = dword_19306C + 113 * *(int16_t *)(a1 + 101);
    if ( (((int)*(uint8_t *)(result + 51) >> *(_BYTE *)(a1 + 99)) & 1) == 0 )
    {
      *(_BYTE *)(result + 51) |= 1 << *(_BYTE *)(a1 + 99);
      result = 113 * *(int16_t *)(a1 + 101);
      *(_BYTE *)(v7 + result + 52) |= 1 << *(_BYTE *)(a1 + 99);
    }
  }
  if ( *(char *)(a1 + 99) < 8 )
  {
    byte_1AB124[*(char *)(a1 + 99)] = 1;
    result = 3753 * *(char *)(a1 + 99);
    if ( *(_BYTE *)(dword_197F98 + result + 40) == 100 )
    {
      result = 113 * a2;
      *(_BYTE *)(dword_19306C + 113 * a2 + 102) = 0;
    }
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;


//----- (000FFEEA) --------------------------------------------------------
void sub_FFEEA()
{
  unsigned int i; // eax
  int16_t j; // di
  int v2; // esi
  uint8_t v3; // al
  int v5; // eax
  uint16_t v6; // dx
  uint16_t v7; // ax
  char *v8; // eax
  uint16_t v9; // ax
  uint16_t v10; // [esp+4h] [ebp-10h]
  int16_t v11; // [esp+8h] [ebp-Ch]
  char v12; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v13[4]; // [esp+10h] [ebp-4h] BYREF

  if ( (uint8_t)byte_199F3A >= 2u && (uint8_t)byte_199F3A <= 3u )
  {
    for ( i = dword_19306C + 113 * word_19999A; i > dword_19306C; i -= 113 )
      *(_BYTE *)(i - 61) = 0;
  }
  for ( j = 0; j < word_199994; ++j )
  {
    v2 = 129 * j + dword_197F9C;
    v3 = *(_BYTE *)(v2 + 100);
    if ( v3 && v3 <= 2u )
    {
      if ( *(int16_t *)(v2 + 101) >= 1000 )
        *(_WORD *)(v2 + 101) -= 500;
      v11 = *(_WORD *)(v2 + 101) - 500;
      v5 = 113 * v11 + dword_19306C;
      v6 = *(_WORD *)(v5 + 15);
      v7 = *(_WORD *)(v5 + 17);
      v10 = v7;
      if ( *(_BYTE *)(v2 + 108) == 0xFF )
      {
        *(_WORD *)(v2 + 103) = v6;
        *(_WORD *)(v2 + 105) = v7;
      }
      else
      {
        if ( *(_BYTE *)(v2 + 107) )
          v8 = 0;
        else
          v8 = &v12;
        sub_EBB0C(
          *(_BYTE *)(v2 + 99),
          *(_WORD *)(v2 + 103),
          *(_WORD *)(v2 + 105),
          v11,
          *(uint8_t *)(v2 + 108),
          (int16_t *)(v2 + 103),
          (int16_t *)(v2 + 105),
          v8,
          v13);
      }
      v9 = *(_WORD *)(v2 + 103);
      --*(_BYTE *)(v2 + 109);
      if ( __PAIR32__(*(_WORD *)(v2 + 105), v9) == __PAIR32__(v10, v6) )
        sub_FFDDA(v2, v11);
      else
        *(_BYTE *)(v2 + 100) = 1;
    }
    else
    {
      *(_BYTE *)(v2 + 127) = 0;
    }
  }
  sub_8A4C4();
  JUMPOUT(0xFF792);
}
// 10000B: control flows out of bounds to FF792
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999A: using guessed type int16_t word_19999A;
// 199F3A: using guessed type char byte_199F3A;


//----- (00100010) --------------------------------------------------------
int __fastcall sub_100010(int a1, void *a2, int a3, int a4)
{
  int v4; // eax
  int v5; // ecx
  int v6; // esi
  int v7; // eax
  int16_t v8; // cx
  int v9; // eax
  char v11; // [esp+0h] [ebp-10h]
  int16_t i; // [esp+8h] [ebp-8h]

  for ( i = 0; i < 500; ++i )
  {
    v4 = 129 * i + dword_197F9C;
    if ( *(_BYTE *)(v4 + 99) == 8 && (*(_BYTE *)(v4 + 100) == 5 || word_199994 <= i) )
      break;
  }
  if ( i == 500 )
  {
    return -1;
  }
  else
  {
    if ( word_199994 <= i )
      word_199994 = i + 1;
    v5 = 129 * i;
    memset(v5 + dword_197F9C, 0, 129);
    if ( a2 )
      qmemcpy((void *)(v5 + dword_197F9C), a2, 0x63u);
    v6 = 129 * i;
    v7 = dword_197F9C;
    *(_BYTE *)(v6 + dword_197F9C + 100) = 0;
    *(_BYTE *)(v6 + v7 + 99) = v11;
    *(_BYTE *)(v6 + v7 + 93) = v11;
    v8 = sub_7A3E3(a3, a4);
    v9 = dword_197F9C;
    *(_WORD *)(v6 + dword_197F9C + 116) = -1;
    *(_WORD *)(v6 + v9 + 101) = v8;
    *(_WORD *)(v6 + v9 + 103) = a3;
    *(_WORD *)(v6 + v9 + 105) = a4;
    *(_WORD *)(v6 + v9 + 97) = dword_192FD8;
  }
  return i;
}
// 1000CF: variable 'v11' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192FD8: using guessed type int dword_192FD8;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (0010011B) --------------------------------------------------------
void sub_10011B()
{
  int v0; // eax
  int v1; // ecx
  int v2; // esi
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  int v6; // edx
  int v7; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // ecx
  int v11; // ebx
  int v12; // eax
  int v13; // ecx
  _BYTE v14[2000]; // [esp+0h] [ebp-838h]
  _DWORD v15[8]; // [esp+7D0h] [ebp-68h] BYREF
  _DWORD v16[8]; // [esp+7F0h] [ebp-48h] BYREF
  int v17; // [esp+810h] [ebp-28h]
  int v18; // [esp+814h] [ebp-24h]
  int v19; // [esp+818h] [ebp-20h]
  int v20; // [esp+81Ch] [ebp-1Ch]
  int v21; // [esp+820h] [ebp-18h]
  int v22; // [esp+824h] [ebp-14h]
  int v23; // [esp+828h] [ebp-10h]
  int v24; // [esp+82Ch] [ebp-Ch]
  int v25; // [esp+830h] [ebp-8h]
  int v26; // [esp+834h] [ebp-4h]

  v0 = 9;
  v1 = 0;
  v2 = 0;
  v21 = 0;
  v26 = 0;
  v17 = 0;
  do
  {
    v3 = word_19918A[v0--];
    v1 += v3;
  }
  while ( v0 * 2 );
  if ( v1 <= 20 )
    v4 = v1 + 2;
  else
    v4 = 20;
  v23 = 0;
  memset(v16, 0, sizeof(v16));
  v5 = 0;
  while ( word_199996 > v23 )
  {
    if ( *(char *)(v5 + dword_192B18) != -1 && !*(_BYTE *)(v5 + dword_192B18 + 6) )
    {
      v19 = 14;
      v20 = v5;
      do
      {
        v19 -= 2;
        if ( *(int16_t *)(v19 + v20 + dword_192B18 + 277) > -100 )
          ++v16[*(char *)(v20 + dword_192B18)];
      }
      while ( v19 );
    }
    ++v23;
    v5 += 361;
  }
  if ( !byte_199F3A )
  {
    v26 = v16[word_19999C];
    if ( v26 > 20 )
      v26 = 20;
  }
  v6 = 0;
  v7 = 0;
  v24 = 0;
  while ( 1 )
  {
    if ( word_199994 <= v6 || *(_BYTE *)(dword_197F9C + v7 + 100) == 5 )
    {
      if ( v4 <= v21 )
      {
        if ( v17 >= v26 )
        {
          v8 = v24;
          ++v2;
          v24 += 4;
          *(_DWORD *)&v14[v8] = v6;
        }
        else
        {
          ++v17;
          *(_BYTE *)(dword_197F9C + v7 + 99) = word_19999C;
        }
      }
      else
      {
        ++v21;
        *(_BYTE *)(dword_197F9C + v7 + 99) = 8;
      }
    }
    ++v6;
    v7 += 129;
    if ( v6 >= 500 )
    {
      memset(v15, 0, sizeof(v15));
      v15[word_19999C] = v17;
      v9 = dword_192FD8 % word_199998;
      v10 = 0;
      v11 = 0;
      v25 = 0;
      v22 = 4 * v2;
      while ( v10 < v22 && word_199998 > v25 )
      {
        if ( v15[v9] >= v16[v9] )
        {
          ++v25;
        }
        else
        {
          v18 = 129 * *(_DWORD *)&v14[v10];
          v25 = 0;
          v10 += 4;
          ++v11;
          *(_BYTE *)(v18 + dword_197F9C + 99) = v9;
          ++v15[v9];
        }
        if ( ++v9 == word_199998 )
          v9 ^= word_199998;
      }
      v12 = 4 * v11;
      while ( v12 < 4 * v2 )
      {
        if ( !*(_BYTE *)(dword_197F98 + 3753 * v9 + 36) )
        {
          v13 = dword_197F9C + 129 * *(_DWORD *)&v14[v12];
          v12 += 4;
          ++v11;
          *(_BYTE *)(v13 + 99) = v9;
          ++v15[v9];
        }
        if ( ++v9 == word_199998 )
          v9 ^= word_199998;
      }
      JUMPOUT(0xFF792);
    }
  }
}
// 100305: control flows out of bounds to FF792
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 19918A: using guessed type int16_t word_19918A[];
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;


//----- (0010034D) --------------------------------------------------------
int16_t __fastcall sub_10034D(int a1)
{
  int v2; // eax
  int v3; // ebx

  v2 = 60;
  while ( v2 > 10 )
  {
    v3 = *(int16_t *)((char *)&word_17FFDE + v2);
    v2 -= 10;
    if ( *(_BYTE *)(a1 + v3 + 279) == 3 )
    {
      LOWORD(v2) = *(int16_t *)((char *)word_17FFEA + v2);
      *(_WORD *)(a1 + 804) = v2;
      return v2;
    }
  }
  *(_WORD *)(a1 + 804) = 0;
  return v2;
}
// 17FFDE: using guessed type int16_t word_17FFDE;
// 17FFEA: using guessed type int16_t word_17FFEA[];


//----- (0010038C) --------------------------------------------------------
int16_t sub_10038C()
{
  int v0; // eax
  unsigned int i; // ebx

  v0 = 3753 * word_199998;
  for ( i = v0 + dword_197F98; i > dword_197F98; *(_BYTE *)(i + 1440) = v0 )
  {
    i -= 3753;
    sub_10034D(i);
    *(_BYTE *)(i + 1439) = sub_56726((int)(i - dword_197F98) / 3753);
    LOWORD(v0) = sub_57597((int)(i - dword_197F98) / 3753);
  }
  return v0;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (001003F2) --------------------------------------------------------
int __fastcall sub_1003F2(int a1, int a2)
{
  uint8_t v2; // al

  LOWORD(a2) = *(_WORD *)(a1 + 101);
  v2 = *(_BYTE *)(a1 + 100);
  if ( v2 )
  {
    if ( v2 <= 1u )
      return a2 - 500;
    if ( v2 != 2 )
      return a2;
    a2 -= 1000;
  }
  return a2;
}


//----- (0010041C) --------------------------------------------------------
void __fastcall sub_10041C( int a1)
{
  unsigned int v1; // esi
  uint8_t v2; // dl
  int16_t v3; // ax
  int v4; // edi
  int v5; // eax
  int v6; // edx
  int v7; // eax
  char *v8; // eax
  char v9; // al
  int16_t v10; // [esp-14h] [ebp-34h]
  char *v11; // [esp-8h] [ebp-28h]
  int v13; // [esp+8h] [ebp-18h]
  int v14; // [esp+Ch] [ebp-14h] BYREF
  int i; // [esp+10h] [ebp-10h] BYREF
  int16_t v16; // [esp+14h] [ebp-Ch]
  _BYTE v17[4]; // [esp+18h] [ebp-8h] BYREF
  char v18; // [esp+1Ch] [ebp-4h] BYREF

  v1 = 129 * word_199994 + dword_197F9C;
  while ( v1 > dword_197F9C )
  {
    v1 -= 129;
    if ( (*(_BYTE *)(v1 + 100) == 2 || *(_BYTE *)(v1 + 100) == 1) && *(char *)(v1 + 99) != a1 )
    {
      v2 = *(_BYTE *)(v1 + 100);
      v3 = *(_WORD *)(v1 + 101);
      if ( v2 )
      {
        if ( v2 <= 1u )
        {
          v3 -= 500;
        }
        else if ( v2 == 2 )
        {
          v3 -= 1000;
        }
      }
      v4 = v3;
      v5 = dword_19306C + 113 * v3;
      v6 = *(int16_t *)(v5 + 15);
      v7 = *(int16_t *)(v5 + 17);
      v13 = v7;
      LOWORD(v7) = *(_WORD *)(v1 + 103);
      v14 = v7;
      v16 = 0;
      LOWORD(v7) = *(_WORD *)(v1 + 105);
      for ( i = v7;
            (int16_t)v14 != v6 || (int16_t)i != v13;
            sub_EBB0C(v9, v14, i, v4, v10, (int16_t *)&v14, (int16_t *)&i, v11, v17) )
      {
        if ( *(_BYTE *)(v1 + 107) )
          v8 = 0;
        else
          v8 = &v18;
        v11 = v8;
        v10 = *(uint8_t *)(v1 + 108);
        v9 = *(_BYTE *)(v1 + 99);
        ++v16;
      }
      *(_BYTE *)(v1 + 109) = v16;
    }
  }
  JUMPOUT(0xFF792);
}
// 100514: control flows out of bounds to FF792
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (00100519) --------------------------------------------------------
void __fastcall sub_100519(int a1, int a2)
{
  unsigned int v2; // esi
  int v3; // edi
  unsigned int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  unsigned int v8; // ebx
  int v9; // eax
  int v11; // [esp+4h] [ebp-Ch]
  int v12; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]

  memset(a2, 0, 9);
  v2 = 0;
  v3 = 0;
  v4 = 129 * word_199994 + dword_197F9C;
  while ( v4 > dword_197F9C )
  {
    v5 = *(char *)(v4 - 30);
    v4 -= 129;
    if ( v5 == a1 && *(_BYTE *)(v4 + 100) == 1 && *(_BYTE *)(v4 + 109) != 1 && sub_1247A0(++v3) == 1 )
      v2 = v4;
  }
  if ( v2 )
  {
    v13 = *(int16_t *)(v2 + 101);
    v11 = *(int16_t *)(v2 + 103);
    v12 = *(int16_t *)(v2 + 105);
    v6 = 129 * word_199994;
    *(_BYTE *)a2 = 1;
    v7 = dword_197F9C;
    *(_DWORD *)(a2 + 5) = v13 - 500;
    v8 = v6 + v7;
    while ( v8 > dword_197F9C )
    {
      v9 = *(char *)(v8 - 30);
      v8 -= 129;
      if ( v9 == a1
        && *(_BYTE *)(v8 + 100) == 1
        && *(int16_t *)(v8 + 103) == v11
        && *(int16_t *)(v8 + 105) == v12
        && *(int16_t *)(v8 + 101) == v13
        && *(_BYTE *)(v8 + 108) == *(_BYTE *)(v2 + 108) )
      {
        sub_FFDDA(v8, v13 - 500);
        ++*(_DWORD *)(a2 + 1);
      }
    }
  }
  sub_8A4C4();
  JUMPOUT(0xFFEE4);
}
// 100613: control flows out of bounds to FFEE4
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (00100618) --------------------------------------------------------
void __usercall sub_100618(int a1, int a2)
{
  unsigned int v2; // ebx
  int v3; // ecx
  unsigned int v4; // edx
  int v5; // eax
  unsigned int v6; // edx
  char v7; // cl
  unsigned int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int i; // edx
  int v13; // [esp+0h] [ebp-28h]
  int v14; // [esp+4h] [ebp-24h]
  int v15; // [esp+8h] [ebp-20h]
  int v16; // [esp+Ch] [ebp-1Ch]
  int v17; // [esp+10h] [ebp-18h]
  int16_t v18; // [esp+14h] [ebp-14h]
  int v19; // [esp+24h] [ebp-4h]

  LOBYTE(v14) = 9;
  v2 = 0;
  if ( a1 != -1 )
  {
    v3 = 0;
    v4 = 129 * word_199994 + dword_197F9C;
    while ( v4 > dword_197F9C )
    {
      v5 = *(char *)(v4 - 30);
      v4 -= 129;
      if ( v5 == v13 && *(_BYTE *)(v4 + 100) == 1 && sub_1247A0(++v3) == 1 )
        v2 = v4;
    }
  }
  if ( !v2 )
  {
    HIWORD(v14) = -1;
LABEL_36:
    for ( i = word_199998; i > 0; sub_EF629(v14, v15, v16, v17, v18, i) )
      HIBYTE(v15) = --i == v13;
    JUMPOUT(0xFF792);
  }
  v19 = *(int16_t *)(v2 + 116);
  HIWORD(v14) = (int)(v2 - dword_197F9C) / 129;
  LOBYTE(v15) = *(_BYTE *)(v2 + 101) + 12;
  BYTE1(v15) = *(_WORD *)(v2 + 116);
  if ( v19 == -1 )
  {
LABEL_35:
    sub_8A4C4();
    *(_BYTE *)(v2 + 100) = 8;
    goto LABEL_36;
  }
  sub_944A3(v19, a2);
  if ( *(char *)(dword_1930DC + 59 * v19 + 55) > 0 )
    goto LABEL_12;
  if ( *(_BYTE *)(dword_197F98 + 3753 * *(char *)(v2 + 99) + 458) == 3 )
  {
    a2 = dword_197F9C;
    v6 = 0;
    v7 = 0;
    v8 = dword_197F9C + 129 * word_199994;
    while ( v8 > dword_197F9C )
    {
      a2 = *(char *)(v8 - 30);
      v8 -= 129;
      if ( a2 == v13 && *(_BYTE *)(v8 + 100) == *(_BYTE *)(v2 + 100) )
      {
        a2 = *(int16_t *)(v8 + 103);
        if ( a2 == *(int16_t *)(v2 + 103) )
        {
          a2 = *(int16_t *)(v8 + 105);
          if ( a2 == *(int16_t *)(v2 + 105) && v8 != v2 )
          {
            a2 = *(int16_t *)(v8 + 101);
            if ( a2 == *(int16_t *)(v2 + 101) && *(_BYTE *)(v8 + 108) == *(_BYTE *)(v2 + 108) )
            {
              a2 = *(int16_t *)(v8 + 116);
              v7 = 1;
              if ( a2 == -1 && (!v6 || *(_BYTE *)(v6 + 16) < *(_BYTE *)(v8 + 16)) && !*(_BYTE *)(v8 + 17) )
                v6 = v8;
            }
          }
        }
      }
    }
    if ( v6 )
    {
      *(_WORD *)(v6 + 116) = v19;
      v9 = (int)(v6 - dword_197F9C) / 129;
      v10 = 59 * v19;
      v11 = dword_1930DC;
      *(_BYTE *)(dword_1930DC + v10 + 57) = 1;
      BYTE2(v15) = 2;
      *(_WORD *)(v11 + v10 + 53) = v9;
    }
    else
    {
      if ( v7 )
      {
LABEL_12:
        BYTE2(v15) = 1;
        goto LABEL_33;
      }
      BYTE2(v15) = 0;
    }
  }
  else
  {
    BYTE2(v15) = 0;
  }
LABEL_33:
  if ( !BYTE2(v15) )
    sub_941C6(v19, a2);
  goto LABEL_35;
}
// 100823: control flows out of bounds to FF792
// 100653: variable 'v13' is possibly undefined
// 10081A: variable 'v14' is possibly undefined
// 10081A: variable 'v15' is possibly undefined
// 10081A: variable 'v16' is possibly undefined
// 10081A: variable 'v17' is possibly undefined
// 10081A: variable 'v18' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199998: using guessed type int16_t word_199998;


//----- (00100828) --------------------------------------------------------
unsigned int sub_100828()
{
  unsigned int result; // eax

  result = dword_197F9C + 129 * word_199994;
  while ( result > dword_197F9C )
  {
    result -= 129;
    if ( *(char *)(result + 99) < 8 && *(_BYTE *)(dword_197F98 + 3753 * *(char *)(result + 99) + 40) != 100 )
      *(_BYTE *)(result + 128) = 0;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (0010087D) --------------------------------------------------------
void sub_10087D()
{
  int v0; // esi
  int v1; // ebx
  int v2; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // eax
  int v6; // edx
  int v7; // ebx
  int v8; // esi
  int v9; // edx
  _WORD v10[72]; // [esp+0h] [ebp-1Eh] BYREF
  int v11; // [esp+90h] [ebp+72h]
  int v12; // [esp+94h] [ebp+76h]
  int v13; // [esp+98h] [ebp+7Ah]
  int v14; // [esp+9Ch] [ebp+7Eh]

  memset(v10, 0, sizeof(v10));
  v0 = word_199994;
  v1 = 129 * word_199994;
  while ( v1 > 0 )
  {
    v1 -= 129;
    v2 = v1 + dword_197F9C;
    --v0;
    if ( *(char *)(v1 + dword_197F9C + 99) != -1 && !*(_BYTE *)(v2 + 100) )
      v10[*(int16_t *)(v2 + 101)] |= 1 << *(_BYTE *)(v2 + 99);
  }
  v3 = word_199996;
  v4 = 361 * word_199996;
  while ( v4 > 0 )
  {
    v4 -= 361;
    v5 = v4 + dword_192B18;
    --v3;
    if ( *(char *)(v4 + dword_192B18) != -1 )
    {
      v6 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v5 + 2) + 2);
      v10[v6] |= 1 << *(_BYTE *)v5;
    }
  }
  v7 = word_19999A;
  v11 = 113 * word_19999A;
  v8 = 2 * word_19999A;
  while ( v8 > 0 )
  {
    v11 -= 113;
    v8 -= 2;
    --v7;
    if ( *(_BYTE *)(v11 + dword_19306C + 54) )
    {
      v9 = word_199998;
      v14 = v8;
      v12 = v11;
      while ( v9 > 0 )
      {
        v13 = *(uint8_t *)(v12 + dword_19306C + 54);
        if ( ((v13 >> --v9) & 1) != 0 )
        {
          v13 = *(uint16_t *)((char *)v10 + v14);
          if ( (~(1 << v9) & v13) == 0 )
            *(_BYTE *)(v12 + dword_19306C + 54) &= ~(1 << v9);
        }
      }
    }
  }
  JUMPOUT(0xFF793);
}
// 1009BE: control flows out of bounds to FF793
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (001009C3) --------------------------------------------------------
char __fastcall sub_1009C3(int a1, int a2)
{
  unsigned int v3; // eax
  int v5; // edx

  v3 = dword_197F9C + 129 * word_199994;
  do
  {
    if ( v3 <= dword_197F9C )
      return 0;
    v5 = *(char *)(v3 - 30);
    v3 -= 129;
  }
  while ( v5 != a1
       || *(_BYTE *)(v3 + 100)
       || (((int)*(uint8_t *)(dword_19306C + 113 * *(int16_t *)(v3 + 101) + 56) >> a2) & 1) == 0
       || (((int)*(uint8_t *)(dword_19306C + 113 * *(int16_t *)(v3 + 101) + 56) >> a1) & 1) != 0 );
  return 1;
}
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (00100A3E) --------------------------------------------------------
int __fastcall sub_100A3E(_BYTE *a1)
{
  int v1; // edx

  v1 = 0;
  if ( a1[322] == 3 )
    v1 = 10;
  if ( a1[393] == 3 )
    v1 += 10;
  if ( a1[426] == 3 )
    v1 += 10;
  if ( a1[452] == 3 )
    v1 += 10;
  if ( a1[461] == 3 )
    v1 += 5;
  return v1;
}


//----- (00100A83) --------------------------------------------------------
_BYTE *__fastcall sub_100A83(_BYTE *a1, _WORD *a2, _WORD *a3)
{
  int v4; // ebx
  int v5; // edi
  _BYTE *v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // eax
  _BYTE *result; // eax
  int v13; // [esp+0h] [ebp-18h]
  int v14; // [esp+4h] [ebp-14h]
  int v16; // [esp+Ch] [ebp-Ch]
  int v17; // [esp+10h] [ebp-8h]

  v4 = 10 * (char)a1[2232];
  v5 = (char)a1[2216];
  v14 = 0;
  v17 = 0;
  v13 = v4 + v5 + (int16_t)sub_100A3E(a1);
  v6 = (_BYTE *)(dword_1930DC + 3953);
  while ( (unsigned int)v6 > dword_1930DC )
  {
    v7 = (char)*(v6 - 1);
    v6 -= 59;
    if ( v7 == (int)&a1[-dword_197F98] / 3753 && v6[57] < 3u && !sub_E1F9E((int)v6) )
    {
      v8 = (int)&v6[-dword_1930DC] / 59;
      v9 = 0;
      v16 = 0;
      if ( (char)v6[39] >= 0 )
      {
        if ( (v6[39] & 0x40) != 0 )
          v9 = 2 * (int16_t)sub_94951(v8) + 2;
      }
      else
      {
        v9 = 3 * ((int16_t)sub_94951(v8) + 1);
      }
      if ( v9 > v14 )
        v14 = v9;
      v10 = (int)&v6[-dword_1930DC] / 59;
      if ( (v6[40] & 2) != 0 )
      {
        v11 = 3 * (int16_t)sub_94951(v10);
LABEL_15:
        v16 = v11;
        goto LABEL_16;
      }
      if ( (v6[40] & 1) != 0 )
      {
        v11 = 2 * (int16_t)sub_94951(v10);
        goto LABEL_15;
      }
LABEL_16:
      if ( v17 < v16 )
        v17 = v16;
    }
  }
  *a2 = v14 + v13;
  LOWORD(v6) = byte_100A36[(char)a1[2207]];
  result = &v6[v17 + v13];
  *a3 = (_WORD)result;
  return result;
}
// 100A83: could not find valid save-restore pair for ebx
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (00100BC5) --------------------------------------------------------
_BOOL1 __fastcall sub_100BC5( int a1, int a2, _WORD *a3, int a4)
{
  int v5; // ebx
  int v6; // edx
  int v7; // edx
  unsigned int v8; // eax
  int16_t v9; // ax
  _BYTE v13[8]; // [esp+8h] [ebp-1Ch] BYREF
  char v14; // [esp+10h] [ebp-14h] BYREF
  char v15; // [esp+11h] [ebp-13h]
  char v16; // [esp+12h] [ebp-12h]
  char v17; // [esp+13h] [ebp-11h]
  char v18; // [esp+14h] [ebp-10h]
  char v19; // [esp+15h] [ebp-Fh]
  char v20; // [esp+16h] [ebp-Eh]
  int v21; // [esp+18h] [ebp-Ch]
  int v22; // [esp+1Ch] [ebp-8h]
  int v23; // [esp+20h] [ebp-4h]

  memset(v13, 0, 7);
  memset(&v14, -1, 7);
  v5 = word_199998;
  v23 = 0;
  v22 = 3753 * word_199998;
  while ( v5 > 0 )
  {
    --v5;
    v22 -= 3753;
    if ( v5 != a1 )
    {
      v21 = a2;
      if ( v5 != a2 )
      {
        v6 = v22 + dword_197F98;
        if ( *(_BYTE *)(v22 + dword_197F98 + a1 + 1412) )
        {
          if ( *(_BYTE *)(v6 + v21 + 1412) && (a4 == -1 || *(_BYTE *)(v6 + a4 + 279) != 3) )
          {
            v7 = *(uint8_t *)(3753 * a1 + dword_197F98 + v5 + 1575);
            v8 = (uint8_t)++v13[v7];
            ++v23;
            if ( sub_1247A0(v8) == 1 )
              *(&v14 + v7) = v5;
          }
        }
      }
    }
  }
  if ( v20 != -1 )
  {
    v9 = v20;
LABEL_25:
    *a3 = v9;
    return v23 > 0;
  }
  if ( v19 != -1 )
  {
    v9 = v19;
    goto LABEL_25;
  }
  if ( v18 != -1 )
  {
    v9 = v18;
    goto LABEL_25;
  }
  if ( v14 != -1 )
  {
    v9 = v14;
    goto LABEL_25;
  }
  if ( v15 != -1 )
  {
    v9 = v15;
    goto LABEL_25;
  }
  if ( v17 != -1 )
  {
    v9 = v17;
    goto LABEL_25;
  }
  if ( v16 != -1 )
  {
    v9 = v16;
    goto LABEL_25;
  }
  return v23 > 0;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00100D19) --------------------------------------------------------
void __fastcall sub_100D19(_BYTE *a1)
{
  int v2; // esi
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  unsigned int v9; // ebx
  int v10; // eax
  int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // ebx
  unsigned int v14; // edx
  int v15; // ecx
  int v16; // eax
  char v17; // bl
  int16_t v18; // dx
  int16_t v19; // ax
  _DWORD v20[8]; // [esp+0h] [ebp-64h] BYREF
  int v21; // [esp+20h] [ebp-44h]
  int v22; // [esp+24h] [ebp-40h]
  unsigned int v23; // [esp+28h] [ebp-3Ch]
  int v24; // [esp+2Ch] [ebp-38h]
  int v25; // [esp+30h] [ebp-34h]
  unsigned int v26; // [esp+34h] [ebp-30h]
  int v27; // [esp+38h] [ebp-2Ch]
  int v28; // [esp+3Ch] [ebp-28h]
  int v29; // [esp+40h] [ebp-24h]
  int v30; // [esp+44h] [ebp-20h]
  int v31; // [esp+48h] [ebp-1Ch]
  int v32; // [esp+4Ch] [ebp-18h]
  int v33; // [esp+50h] [ebp-14h]
  int v34; // [esp+54h] [ebp-10h]
  int v35; // [esp+58h] [ebp-Ch]
  int v36; // [esp+5Ch] [ebp-8h]
  int v37; // [esp+60h] [ebp-4h]

  if ( a1[36] || !byte_199CB0 )
    return;
  v33 = (int)&a1[-dword_197F98] / 3753;
  v28 = word_199998;
  v2 = 0;
  v25 = 0;
  v30 = 0;
  v27 = 3753 * word_199998;
  while ( v28 > 0 )
  {
    v22 = (int16_t)--v28;
    LOWORD(v3) = sub_1026CF(v28, v33);
    v32 = v3;
    v2 += sub_1026CF(v33, v28);
    v27 -= 3753;
    sub_10278D(v33, v28, 0);
    if ( (int16_t)v32 > 0 && (int16_t)v33 != v28 )
    {
      if ( *(_BYTE *)(v27 + dword_197F98 + 40) == 100 )
      {
        if ( (int16_t)v32 > v30 )
          v30 = (int16_t)v32;
      }
      else if ( (int16_t)v32 > v25 )
      {
        v25 = (int16_t)v32;
      }
    }
  }
  if ( v2 || *(int16_t *)(dword_1AA204 + 58 * ((int)&a1[-dword_197F98] / 3753) + 10) <= 0 || dword_192FD8 <= 35030 )
    goto LABEL_33;
  if ( byte_199CB0 == 4 )
  {
    if ( a1[40] )
      sub_1247A0(8u);
    if ( (char)a1[2216] > 0 )
      sub_1247A0(5u);
  }
  else if ( byte_199CB0 == 3 )
  {
    if ( (a1[40] || sub_1247A0(7u) != 1) && sub_1247A0(0x19u) != 1 && ((char)a1[2216] <= 0 || sub_1247A0(6u) != 1) )
      goto LABEL_33;
  }
  else if ( byte_199CB0 != 2 || (a1[40] || sub_1247A0(0xDu) != 1) && ((char)a1[2216] <= 0 || sub_1247A0(0xDu) != 1) )
  {
    goto LABEL_33;
  }
  v2 = 1;
LABEL_33:
  if ( v2 <= 0 )
    return;
  if ( word_1ACE78[2 * (int16_t)v33] < 0 )
    goto LABEL_41;
  if ( (uint8_t)byte_199CB0 <= 2u )
  {
    v5 = v30;
    if ( v30 <= v25 )
      v5 = v25;
    v4 = v5;
    if ( v2 >= v5 )
      goto LABEL_42;
    goto LABEL_41;
  }
  v4 = v30;
  if ( v2 < v30 )
LABEL_41:
    v4 = v2;
LABEL_42:
  if ( v4 > 63 )
    v4 = 63;
  sub_10278D(v33, v33, v4);
  if ( v4 < v2 )
  {
    v26 = 0;
    v6 = memset(v20, 0, sizeof(v20));
    LOWORD(v6) = word_199998;
    v7 = v2 - v4;
    v34 = v6;
    while ( (int16_t)v34 > 0 )
    {
      if ( (_WORD)--v34 != (_WORD)v33 )
      {
        v8 = (int16_t)v34 + dword_197F98 + 3753 * (int16_t)v33;
        if ( *(_BYTE *)(v8 + 1412) )
        {
          if ( !*(_BYTE *)(v8 + 2054) )
          {
            v31 = 0;
            v9 = 0;
            v29 = sub_1026CF(v34, v34);
            do
            {
              v10 = (int16_t)v31 + dword_197F98 + 3753 * (int16_t)v34;
              v24 = (int16_t)v31;
              if ( *(_BYTE *)(v10 + 279) == 3 )
              {
                if ( sub_E412B((int)a1, (int16_t)v31) )
                {
                  v10 = 13 * v24;
                  LOWORD(v10) = *(int16_t *)((char *)&word_17E07F + 13 * v24);
                  if ( (_WORD)v10 )
                  {
                    v10 = *(int *)((char *)&dword_17D916 + 23 * (int16_t)v10);
                    v9 += v10;
                  }
                }
              }
              ++v31;
            }
            while ( (int16_t)v31 < 204 );
            if ( v9 )
            {
              if ( v29 > 0 )
              {
                LOWORD(v10) = word_199998;
                v36 = 0;
                v37 = v10;
                while ( (int16_t)v37 > 0 )
                {
                  if ( (_WORD)--v37 != (_WORD)v34 )
                  {
                    LOWORD(v11) = sub_1026CF(v37, v34);
                    v36 += v11;
                  }
                }
                if ( (int16_t)v36 > 0 )
                  v9 = v9 * (v7 + (int16_t)v36) / v7;
                v23 = 4 * (int16_t)v34;
                v21 = word_1ACE7A[v23 / 2];
                v12 = v9 * (100 - v21) / 0x64;
                if ( word_1ACE7A[v23 / 2] >= 25 )
                  v12 = v12 * (125 - v21) / 0x64;
                v9 = v12 / v29;
              }
              if ( v7 > v29 )
                v9 *= v7 - v29;
              v13 = v9 + 1;
              v14 = v26;
              v20[(int16_t)v34] = v13;
              if ( v14 < v13 )
                v26 = v13;
            }
          }
        }
      }
    }
    v15 = (int16_t)v33;
    do
    {
      v16 = sub_FE96F((int)v20, word_199998);
      v35 = v16;
      if ( (int16_t)v16 == -1 )
      {
        if ( v4 + v7 >= 63 )
          v17 = 63;
        else
          v17 = v4 + v7;
        sub_10278D(v33, v33, v17);
        v7 = 0;
      }
      else
      {
        if ( v7 > 63 )
        {
          sub_10278D(v33, v16, 63);
          v7 -= 63;
        }
        else
        {
          sub_10278D(v33, v16, v7);
          v7 = 0;
        }
        if ( *(_BYTE *)(dword_197F98 + 3753 * v15 + 39) == 3 && sub_1247A0(8u) == 1 )
        {
          v18 = v35;
          v19 = v15;
        }
        else
        {
          v18 = v35;
          v19 = v33;
        }
        sub_1027B5(v19, v18);
      }
    }
    while ( v7 > 0 );
  }
}
// 100D81: variable 'v3' is possibly undefined
// 101028: variable 'v10' is possibly undefined
// 101043: variable 'v11' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17D916: using guessed type int dword_17D916;
// 17E07F: using guessed type int16_t word_17E07F;
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;
// 1AA204: using guessed type int dword_1AA204;
// 1ACE78: using guessed type int16_t word_1ACE78[];
// 1ACE7A: using guessed type int16_t word_1ACE7A[];


//----- (0010119C) --------------------------------------------------------
char __fastcall sub_10119C(int a1, int a2, int a3)
{
  int v4; // edi
  int v5; // esi
  signed int v6; // eax
  int v7; // edx
  int16_t v8; // dx
  int16_t v9; // cx
  int v10; // eax
  char v11; // al
  char v13; // [esp+0h] [ebp-38h] BYREF
  int16_t v14; // [esp+1h] [ebp-37h]
  char v15; // [esp+3h] [ebp-35h]
  int16_t v16; // [esp+4h] [ebp-34h]
  int16_t v17; // [esp+6h] [ebp-32h]
  int v18; // [esp+14h] [ebp-24h]
  signed int v19; // [esp+18h] [ebp-20h]
  int v20; // [esp+1Ch] [ebp-1Ch]
  int v21; // [esp+20h] [ebp-18h]
  unsigned int v22; // [esp+24h] [ebp-14h]
  unsigned int v23; // [esp+28h] [ebp-10h]
  int v24; // [esp+2Ch] [ebp-Ch] BYREF
  int v25; // [esp+30h] [ebp-8h]
  char v26; // [esp+34h] [ebp-4h]

  v18 = a2;
  v26 = a3;
  v4 = (a1 - dword_197F98) / 3753;
  v22 = 0;
  v5 = -1;
  v25 = 0;
  v20 = (a2 - dword_197F98) / 3753;
  do
  {
    LOBYTE(v6) = v18;
    if ( *(_BYTE *)((int16_t)v25 + v18 + 279) == 3 )
    {
      LOBYTE(v6) = sub_E412B(a1, (int16_t)v25);
      if ( (_BYTE)v6 )
      {
        v6 = *(int16_t *)((char *)&word_17E07F + 13 * (int16_t)v25);
        v19 = v6;
        if ( v6 )
        {
          v6 = *(uint8_t *)(a1 + 801);
          if ( v6 != v19 )
          {
            v7 = *(int *)((char *)&dword_17D916 + 23 * v19);
            if ( v7 > 0 )
            {
              v22 += v7;
              v6 = sub_1247A0(v22);
              if ( v6 <= v7 )
                v5 = (int16_t)v25;
            }
          }
        }
      }
    }
    ++v25;
  }
  while ( (int16_t)v25 < 204 );
  if ( v5 >= 0 )
  {
    v24 = v4;
    sub_E4204(a1, v5, v4);
    if ( v26 )
      sub_100BC5(v4, v20, &v24, v5);
    v8 = v24;
    v9 = ((int16_t)v24 != v4) + 1;
    v21 = (int16_t)v20;
    v23 = -sub_1247A0(0xFu);
    v10 = (int16_t)(v23 - sub_1247A0(5u));
    sub_4E3B5(v10, v8, v20, v9, 0, v5);
    v13 = 1;
    HIBYTE(v16) = v20;
    v11 = v24;
    v14 = v4;
    if ( (int16_t)v24 == v4 )
      v11 = -1;
    v15 = 0;
    LOBYTE(v16) = v11;
    v17 = v5;
    sub_FD846((int)&v13);
    v13 = 2;
    v14 = v20;
    v15 = 0;
    v16 = v24;
    v17 = v5;
    LOBYTE(v6) = sub_FD846((int)&v13);
  }
  return v6;
}
// 17D916: using guessed type int dword_17D916;
// 17E07F: using guessed type int16_t word_17E07F;
// 197F98: using guessed type int dword_197F98;


//----- (0010130A) --------------------------------------------------------
int __fastcall sub_10130A( int a1, int a2, int a3)
{
  int v4; // edi
  int v5; // ebx
  int v6; // ecx
  int v7; // edx
  signed int v8; // eax
  int result; // eax
  char v10; // al
  int v11; // edi
  int16_t v12; // [esp-8h] [ebp-44h]
  char v15; // [esp+8h] [ebp-34h] BYREF
  int16_t v16; // [esp+9h] [ebp-33h]
  char v17; // [esp+Bh] [ebp-31h]
  int16_t v18; // [esp+Ch] [ebp-30h]
  char v19; // [esp+Eh] [ebp-2Eh]
  char v20; // [esp+Fh] [ebp-2Dh]
  signed int v21; // [esp+1Ch] [ebp-20h]
  unsigned int v22; // [esp+20h] [ebp-1Ch]
  int v23; // [esp+24h] [ebp-18h]
  int v24; // [esp+28h] [ebp-14h]
  int v25; // [esp+2Ch] [ebp-10h]
  int v26; // [esp+30h] [ebp-Ch]
  unsigned int v27; // [esp+34h] [ebp-8h]
  unsigned int v28; // [esp+38h] [ebp-4h]

  v4 = -1;
  v22 = 0;
  v24 = 0;
  v26 = 0;
  v23 = -1;
  while ( 1 )
  {
    result = word_199996;
    if ( word_199996 <= v24 )
      break;
    v5 = v26 + dword_192B18;
    if ( *(char *)(v26 + dword_192B18) == a2 )
    {
      v6 = 0;
      v7 = 0;
      do
      {
        if ( v6 != 9 )
        {
          if ( *(_BYTE *)(v5 + 310) )
          {
            v8 = *(int *)((char *)&dword_17EB45 + v7);
            v22 += v8;
            v21 = v8;
            if ( (int)sub_1247A0(v22) <= v8 )
            {
              v4 = v24;
              v23 = v6;
            }
          }
        }
        ++v5;
        ++v6;
        v7 += 19;
      }
      while ( v6 < 49 );
    }
    v26 += 361;
    ++v24;
  }
  if ( v4 >= 0 )
  {
    sub_145EA(v4, v23, v4);
    v12 = *(_WORD *)(361 * v4 + dword_192B18 + 2);
    v25 = a1;
    v28 = -sub_1247A0(0xFu);
    v27 = sub_1247A0(5u);
    sub_4E3B5((int16_t)(v28 - v27), a3, a2, (a3 != a1) + 3, v12, v23);
    v16 = a1;
    v15 = 1;
    HIBYTE(v18) = a2;
    if ( a3 == a1 )
      v10 = -1;
    else
      v10 = a3;
    v11 = 361 * v4;
    LOBYTE(v18) = v10;
    v17 = 1;
    v19 = *(_BYTE *)(v11 + dword_192B18 + 2);
    v20 = v23;
    sub_FD846((int)&v15);
    v15 = 2;
    v16 = a2;
    v17 = 1;
    v18 = a3;
    v19 = *(_BYTE *)(v11 + dword_192B18 + 2);
    v20 = v23;
    return sub_FD846((int)&v15);
  }
  return result;
}
// 17EB45: using guessed type int dword_17EB45;
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (00101483) --------------------------------------------------------
int __fastcall sub_101483(int a1)
{
  if ( a1 <= 5 )
    return 2 * a1;
  if ( a1 > 10 )
    return (a1 - 10) / 2 + 15;
  return a1 + 5;
}


//----- (001014A4) --------------------------------------------------------
void __fastcall sub_1014A4(int a1)
{
  int v1; // esi
  int v2; // edi
  int v3; // esi
  int v4; // ebx
  unsigned int v5; // ecx
  unsigned int v6; // ebx
  int v7; // ebx
  uint16_t v8; // ax
  char v9; // al
  unsigned int v10; // esi
  unsigned int v11; // edx
  unsigned int v12; // ecx
  int v13; // ebx
  int16_t v14; // cx
  int v15; // esi
  int16_t v16; // cx
  int v17; // esi
  int v18; // [esp+0h] [ebp-5Ch]
  int v19[4]; // [esp+4h] [ebp-58h] BYREF
  int16_t v20; // [esp+14h] [ebp-48h]
  int v21[4]; // [esp+18h] [ebp-44h] BYREF
  int16_t v22; // [esp+28h] [ebp-34h]
  int v23; // [esp+2Ch] [ebp-30h]
  int v24; // [esp+30h] [ebp-2Ch]
  unsigned int v25; // [esp+34h] [ebp-28h]
  int v26; // [esp+38h] [ebp-24h]
  int v27; // [esp+3Ch] [ebp-20h]
  unsigned int v28; // [esp+40h] [ebp-1Ch]
  int v29; // [esp+44h] [ebp-18h]
  int v30; // [esp+48h] [ebp-14h]
  int v31; // [esp+4Ch] [ebp-10h]
  int v32; // [esp+50h] [ebp-Ch]
  unsigned int v33; // [esp+54h] [ebp-8h]
  int v34; // [esp+58h] [ebp-4h] BYREF

  v27 = (a1 - dword_197F98) / 3753;
  v30 = sub_1026CF(v27, v27);
  v24 = sub_101483(v30);
  v29 = word_199998;
  v28 = 4 * v27;
  v32 = 3753 * word_199998;
  v31 = 0;
  v33 = 4 * word_199998;
  while ( v29 > 0 )
  {
    --v29;
    v32 -= 3753;
    v33 -= 4;
    if ( v29 != v27 )
    {
      v1 = dword_197F98;
      v2 = sub_1026CF(v29, v27);
      v3 = v32 + v1;
      v4 = sub_101483(v2);
      v23 = v4;
      if ( v2 )
      {
        v5 = sub_1247A0(0x64u);
        v25 = sub_1247A0(0x64u);
        v26 = word_1ACE78[v33 / 2];
        v6 = v26 + v5 + v4;
        v26 = word_1ACE7A[v28 / 2];
        v7 = v6 - (v24 + v26 + v25);
        if ( *(_BYTE *)(v3 + 40) != 100 && *(_BYTE *)(v18 + 40) == 100 )
          v7 += (uint8_t)byte_199CB0 - 2;
        v8 = sub_1026F1(v29, v27);
        if ( v8 )
        {
          if ( v8 <= 1u && (v7 >= 70 || v5 == 100) )
          {
            v34 = v29;
            if ( v7 >= 90 || v5 == 100 )
              sub_100BC5(v29, v27, &v34, -1);
            sub_10130A(v29, v27, (int16_t)v34);
          }
        }
        else if ( (v7 >= 60 || v5 == 100) && (v7 >= 80 || v5 == 100) )
        {
          v9 = 0;
          if ( v7 >= 90 || v5 == 100 )
            v9 = 1;
          sub_10119C(v3, v18, v9);
        }
        v10 = sub_1247A0(0x64u);
        v11 = v33;
        v12 = sub_1247A0(0x64u);
        v13 = v23 + *(int16_t *)((char *)word_1ACE78 + v11) + v10 - (v24 + word_1ACE7A[v28 / 2] + v12 + 20);
        if ( (uint16_t)sub_1026F1(v29, v27) == 2 )
          v13 += 20;
        if ( v13 >= 80 || v10 == 100 )
          ++v31;
        if ( v13 <= -80 || v12 == 100 )
        {
          v14 = v29;
          sub_10278D(v29, v27, v2 - 1);
          memset(v21, 0, 18);
          LOBYTE(v21[0]) = 10;
          HIWORD(v21[0]) = v27;
          sub_EF629(v21[0], v21[1], v21[2], v21[3], v22, v14);
        }
      }
    }
  }
  if ( v31 > 0 )
  {
    v15 = v30 - v31;
    if ( v30 - v31 < 0 )
      v15 = 0;
    v16 = v27;
    sub_10278D(v27, v27, v15);
    v17 = v30 - v15;
    if ( v17 > 0 )
    {
      memset(v19, 0, 18);
      HIWORD(v19[0]) = v17;
      LOBYTE(v19[0]) = 11;
      sub_EF629(v19[0], v19[1], v19[2], v19[3], v20, v16);
    }
  }
  JUMPOUT(0x101195);
}
// 101763: control flows out of bounds to 101195
// 1015A5: variable 'v18' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;
// 1ACE78: using guessed type int16_t word_1ACE78[];
// 1ACE7A: using guessed type int16_t word_1ACE7A[];


//----- (00101768) --------------------------------------------------------
void __fastcall sub_101768(int a1)
{
  int v1; // esi
  int v2; // ebx
  unsigned int v3; // edi
  int16_t v4; // ax
  int16_t v5; // ax
  char v6; // al
  int v7; // [esp+0h] [ebp-28h]
  int v8; // [esp+4h] [ebp-24h]
  int v9; // [esp+8h] [ebp-20h]
  int v10; // [esp+Ch] [ebp-1Ch]
  int v11; // [esp+10h] [ebp-18h]
  int16_t v12; // [esp+14h] [ebp-14h]
  int16_t v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+1Ch] [ebp-Ch]
  unsigned int v15; // [esp+20h] [ebp-8h]
  int v16; // [esp+24h] [ebp-4h]

  v1 = word_199998;
  v2 = *(char *)(a1 + 58);
  v16 = -1;
  v3 = 0;
  v13 = -1;
  v15 = 0;
  v14 = 3753 * word_199998;
  while ( v1 > 0 )
  {
    --v1;
    v14 -= 3753;
    if ( v1 != v2 && !*(_BYTE *)(v14 + dword_197F98 + 36) )
    {
      v4 = sub_1026CF(v1, v2);
      if ( v4 > 0 )
      {
        v3 += v4;
        if ( (int)sub_1247A0(v3) <= v4 )
        {
          v16 = v1;
          v13 = v2;
        }
      }
      if ( !v3 && sub_1026CF(v2, v1) > 0 )
      {
        v5 = sub_1026CF(v1, v1);
        if ( v5 > 0 )
        {
          v15 += v5;
          if ( (int)sub_1247A0(v15) <= v5 )
          {
            v16 = v1;
            v13 = v1;
          }
        }
      }
    }
  }
  if ( v16 != -1 )
  {
    BYTE2(v8) = v16;
    HIBYTE(v8) = v13;
    LOBYTE(v9) = (v7 - dword_1930DC) / 59;
    LOBYTE(v8) = 15;
    BYTE1(v9) = v2;
    sub_EF629(v8, v9, v10, v11, v12, v2);
    sub_EF629(v8, v9, v10, v11, v12, v16);
    v6 = sub_1026CF(v16, v13);
    sub_10278D(v16, v13, v6 - 1);
  }
  JUMPOUT(0x101195);
}
// 10189E: control flows out of bounds to 101195
// 10183D: variable 'v7' is possibly undefined
// 10186B: variable 'v8' is possibly undefined
// 10186B: variable 'v9' is possibly undefined
// 10186B: variable 'v10' is possibly undefined
// 10186B: variable 'v11' is possibly undefined
// 10186B: variable 'v12' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (001018A3) --------------------------------------------------------
void sub_1018A3()
{
  unsigned int v0; // ebx
  int v1; // eax
  int v2; // ecx

  v0 = dword_1930DC + 3953;
  while ( v0 > dword_1930DC )
  {
    v1 = *(char *)(v0 - 1);
    v0 -= 59;
    if ( v1 != -1 && *(_BYTE *)(v0 + 57) <= 1u )
    {
      v2 = 0;
      if ( (*(_BYTE *)(v0 + 38) & 2) != 0 )
        v2 = 3 * ((int16_t)sub_94951((int)(v0 - dword_1930DC) / 59) + 1);
      if ( v2 )
      {
        if ( (int)sub_1247A0(0x64u) <= v2 )
          sub_101768(v0);
      }
    }
  }
}
// 1930DC: using guessed type int dword_1930DC;


//----- (0010192B) --------------------------------------------------------
void sub_10192B()
{
  int16_t v0; // cx
  _BYTE *v1; // eax
  int16_t v2; // cx
  _BYTE *v3; // eax
  int16_t v4; // cx
  _BYTE v5[8]; // [esp+0h] [ebp-Ch] BYREF
  uint8_t v6; // [esp+8h] [ebp-4h]

  sub_1018A3();
  v6 = 0;
  v0 = word_199998;
  while ( v0 > 0 )
  {
    v1 = (_BYTE *)(dword_197F98 + 3753 * --v0);
    if ( !v1[36] )
    {
      v5[v6++] = v0;
      sub_100A83(v1, &word_1ACE78[2 * v0], &word_1ACE78[2 * v0 + 1]);
    }
  }
  v2 = v6;
  sub_FE9B5(v5, v6);
  while ( v2 > 0 )
  {
    v3 = (_BYTE *)(3753 * (uint8_t)v5[--v2] + dword_197F98);
    if ( v3[40] != 100 )
      sub_100D19(v3);
  }
  v4 = v6;
  sub_FE9B5(v5, v6);
  while ( v4 > 0 )
    sub_1014A4(3753 * (uint8_t)v5[--v4] + dword_197F98);
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 1ACE78: using guessed type int16_t word_1ACE78[];


//----- (001019F0) --------------------------------------------------------
int16_t __fastcall sub_1019F0( int a1, int a2)
{
  int16_t result; // ax
  int v5; // ebx

  result = sub_1026CF(a1, a2);
  if ( result )
  {
    v5 = sub_1026CF(a1, a1) + result;
    if ( v5 > 63 )
      LOBYTE(v5) = 63;
    sub_10278D(a1, a1, v5);
    return sub_10278D(a1, a2, 0);
  }
  return result;
}


//----- (00101A42) --------------------------------------------------------
char *sub_101A42()
{
  unsigned int i; // eax
  char *result; // eax
  char *v2; // ebx
  int16_t v3; // si
  int v4; // ecx
  char *v5; // edx
  int v6; // edi
  unsigned int v7; // [esp+4h] [ebp-8h]

  for ( i = dword_197F98 + 3753 * word_199998; i > dword_197F98; i -= 3753 )
  {
    *(_WORD *)(i - 2311) = 0;
    *(_WORD *)(i - 2277) = 0;
  }
  result = (char *)(dword_192B18 + 361 * word_199996);
  v2 = result + 12;
  while ( (unsigned int)result > dword_192B18 )
  {
    result -= 361;
    v2 -= 361;
    if ( *result != -1 )
    {
      v3 = 0;
      v4 = 0;
      v5 = &v2[4 * (uint8_t)result[10]];
      while ( v5 > v2 )
      {
        v5 -= 4;
        v7 = *(_DWORD *)v5 & 0xF;
        if ( v7 >= 8 )
        {
          if ( (*(_DWORD *)v5 & 0x180) == 0x100 && v7 == 8 )
            ++v4;
        }
        else
        {
          ++v3;
          ++v4;
        }
      }
      v6 = dword_197F98;
      *(_WORD *)(3753 * *result + dword_197F98 + 1442) += v3;
      *(_WORD *)(3753 * *result + v6 + 1476) += v4;
    }
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;


//----- (00101B3C) --------------------------------------------------------
int __fastcall sub_101B3C(int a1, int a2)
{
  int v3; // ebx
  int v4; // eax
  int v5; // ebx

  v3 = *(int16_t *)(a1 + 1442);
  v4 = *(int16_t *)(3753 * a2 + dword_197F98 + 1442);
  if ( v3 < v4 )
    v4 = v3;
  v5 = v4 / 2;
  if ( sub_2346E((a1 - dword_197F98) / 3753) || sub_2346E(a2) )
    v5 /= 2;
  return v5;
}
// 197F98: using guessed type int dword_197F98;


//----- (00101BA4) --------------------------------------------------------
void __fastcall sub_101BA4(int a1, int a2)
{
  unsigned int v3; // ebx
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // [esp+0h] [ebp-Ch]
  int16_t v8; // [esp+8h] [ebp-4h]

  sub_101B3C(a1, a2);
  v8 = 0;
  v3 = dword_1930DC + 3953;
  while ( 1 )
  {
    do
    {
      if ( v3 <= dword_1930DC )
        JUMPOUT(0x101F7C);
      v4 = *(char *)(v3 - 1);
      v3 -= 59;
    }
    while ( (a1 - dword_197F98) / 3753 != v4 || *(_BYTE *)(v3 + 57) >= 3u );
    v5 = (int)(v3 - dword_1930DC) / 59;
    v7 = 0;
    if ( (*(_BYTE *)(v3 + 40) & 8) != 0 )
      break;
    if ( (*(_BYTE *)(v3 + 40) & 4) != 0 )
    {
      v6 = 10 * ((int16_t)sub_94951(v5) + 1);
      goto LABEL_8;
    }
LABEL_9:
    if ( v8 < v7 )
      v8 = v7;
  }
  v6 = 15 * ((int16_t)sub_94951(v5) + 1);
LABEL_8:
  v7 = v6;
  goto LABEL_9;
}
// 101C8E: control flows out of bounds to 101F7C
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (00101C93) --------------------------------------------------------
int16_t __fastcall sub_101C93(int a1, int a2)
{
  int16_t v3; // dx
  int16_t v4; // ax

  v3 = *(_WORD *)(a1 + 1476);
  v4 = *(_WORD *)(dword_197F98 + 3753 * a2 + 1476);
  if ( v3 < v4 )
    v4 = v3;
  return v4 / 2;
}
// 197F98: using guessed type int dword_197F98;


//----- (00101CC5) --------------------------------------------------------
int __fastcall sub_101CC5(int a1, int a2)
{
  int v3; // ecx
  int v4; // eax
  int16_t v5; // cx
  int v6; // edx
  uint8_t v7; // al
  int v9; // eax

  v3 = 3753 * (int16_t)a2;
  HIWORD(v4) = HIWORD(dword_197F98);
  LOWORD(a2) = *(_WORD *)(a1 + 1476);
  LOWORD(v4) = *(_WORD *)(v3 + dword_197F98 + 1476);
  if ( (int16_t)a2 < (int16_t)v4 )
    v4 = a2;
  LOWORD(v4) = (int16_t)v4 / 2;
  v5 = v4;
  v6 = v4;
  v7 = *(_BYTE *)(a1 + 2207);
  if ( !v7 )
  {
    v9 = v5;
    return v9 / 2;
  }
  if ( v7 <= 1u )
    return (3 * v5 - (__CFSHL__((3 * v5) >> 31, 2) + 4 * ((3 * v5) >> 31))) >> 2;
  if ( v7 >= 4u )
  {
    if ( v7 > 4u )
    {
      if ( v7 != 5 )
        return v6;
      return (7 * v5 - (__CFSHL__((7 * v5) >> 31, 2) + 4 * ((7 * v5) >> 31))) >> 2;
    }
    v9 = 3 * v5;
    return v9 / 2;
  }
  return v6;
}
// 197F98: using guessed type int dword_197F98;


//----- (00101D53) --------------------------------------------------------
void __fastcall sub_101D53(int a1, int a2)
{
  int16_t v4; // ax
  int16_t v5; // di
  int16_t v6; // cx
  int v7; // edx
  bool v8; // [esp+0h] [ebp-8h]

  sub_101BA4(a1, a2);
  v5 = *(_WORD *)(a1 + 2 * a2 + 1444);
  v6 = v4;
  if ( v5 >= v4 )
  {
    LOWORD(v7) = v4;
  }
  else
  {
    if ( v4 % 5 )
      v8 = v4 % 5 >= (int)sub_1247A0(5u);
    else
      v8 = 0;
    v7 = v8 + v5 + v6 / 5;
    if ( v6 < (int16_t)v7 )
      LOWORD(v7) = v6;
  }
  *(_WORD *)(a1 + 2 * a2 + 1460) = v6;
  *(_WORD *)(a1 + 2 * a2 + 1444) = v7;
  JUMPOUT(0x101F7C);
}
// 101DE0: control flows out of bounds to 101F7C
// 101D71: variable 'v4' is possibly undefined


//----- (00101DE5) --------------------------------------------------------
void __fastcall sub_101DE5(int a1, int a2)
{
  int16_t v4; // ax
  int16_t v5; // di
  int16_t v6; // cx
  int v7; // edx
  bool v8; // [esp+0h] [ebp-8h]

  v4 = sub_101CC5(a1, a2);
  v5 = *(_WORD *)(a1 + 2 * a2 + 1478);
  v6 = v4;
  if ( v5 >= v4 )
  {
    LOWORD(v7) = v4;
  }
  else
  {
    if ( v4 % 5 )
      v8 = v4 % 5 >= (int)sub_1247A0(5u);
    else
      v8 = 0;
    v7 = v8 + v5 + v6 / 5;
    if ( v6 < (int16_t)v7 )
      LOWORD(v7) = v6;
  }
  *(_WORD *)(a1 + 2 * a2 + 1494) = v6;
  *(_WORD *)(a1 + 2 * a2 + 1478) = v7;
  JUMPOUT(0x101F7C);
}
// 101E72: control flows out of bounds to 101F7C


//----- (00101E77) --------------------------------------------------------
char *sub_101E77()
{
  unsigned int v0; // ebx
  int16_t v1; // cx

  v0 = 3753 * word_199998 + dword_197F98;
  while ( v0 > dword_197F98 )
  {
    v1 = word_199998;
    v0 -= 3753;
    while ( v1 > 0 )
    {
      if ( *(_BYTE *)(--v1 + v0 + 1583) )
        sub_101D53(v0, v1);
      if ( *(_BYTE *)(v1 + v0 + 1591) )
        sub_101DE5(v0, v1);
    }
  }
  return sub_101A42();
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00101EE3) --------------------------------------------------------
void __fastcall sub_101EE3(int a1, int a2)
{
  int v3; // eax
  int v4; // edi
  int16_t v5; // ax
  int16_t v6; // ax
  int v7; // [esp+0h] [ebp-8h]
  int v8; // [esp+4h] [ebp-4h]

  v3 = sub_101B3C(a1, a2);
  v8 = (a1 - dword_197F98) / 3753;
  *(_BYTE *)(a2 + a1 + 1583) = 1;
  v7 = -v3;
  v4 = 3753 * a2 + dword_197F98;
  *(_WORD *)(a1 + 2 * a2 + 1444) = -(int16_t)v3;
  sub_101BA4(a1, a2);
  *(_WORD *)(a1 + 2 * a2 + 1460) = v5;
  *(_BYTE *)((int16_t)v8 + v4 + 1583) = 1;
  *(_WORD *)(v4 + 2 * (int16_t)v8 + 1444) = v7;
  sub_101BA4(v4, v8);
  *(_WORD *)(v4 + 2 * (int16_t)v8 + 1460) = v6;
  sub_E2710(a1);
  sub_E2710(v4);
}
// 101F42: variable 'v5' is possibly undefined
// 101F66: variable 'v6' is possibly undefined
// 197F98: using guessed type int dword_197F98;


//----- (00101F82) --------------------------------------------------------
void __fastcall sub_101F82(int a1, int a2)
{
  int16_t v3; // cx
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // edi
  int v8; // esi
  int v9; // ecx
  int v10; // [esp+0h] [ebp-4h]

  v3 = a2;
  LOWORD(a2) = *(_WORD *)(a1 + 1476);
  HIWORD(v4) = HIWORD(dword_197F98);
  LOWORD(v4) = *(_WORD *)(3753 * v3 + dword_197F98 + 1476);
  if ( (int16_t)a2 < (int16_t)v4 )
    v4 = a2;
  LOWORD(v4) = (int16_t)v4 / 2;
  v10 = (a1 - dword_197F98) / 3753;
  v5 = v4;
  v6 = dword_197F98;
  v7 = -v5;
  *(_BYTE *)(v3 + a1 + 1591) = 1;
  v8 = v3;
  v9 = v6 + 3753 * v3;
  *(_WORD *)(a1 + 2 * v8 + 1478) = v7;
  *(_WORD *)(a1 + 2 * v8 + 1494) = sub_101CC5(a1, v8);
  *(_BYTE *)(v9 + (int16_t)v10 + 1591) = 1;
  *(_WORD *)(v9 + 2 * (int16_t)v10 + 1478) = v7;
  *(_WORD *)(v9 + 2 * (int16_t)v10 + 1494) = sub_101CC5(v9, (int16_t)v10);
  sub_E2710(a1);
  JUMPOUT(0x101F77);
}
// 102032: control flows out of bounds to 101F77
// 197F98: using guessed type int dword_197F98;


//----- (00102037) --------------------------------------------------------
void sub_102037()
{
  word_17D634 = 2;
  word_17D638 = 1;
  word_17D63A = 1;
  word_17D63C = 1;
  word_17D63E = 1;
  word_17D636 = 0;
}
// 17D634: using guessed type int16_t word_17D634;
// 17D636: using guessed type int16_t word_17D636;
// 17D638: using guessed type int16_t word_17D638;
// 17D63A: using guessed type int16_t word_17D63A;
// 17D63C: using guessed type int16_t word_17D63C;
// 17D63E: using guessed type int16_t word_17D63E;


//----- (0010206E) --------------------------------------------------------
unsigned int sub_10206E()
{
  uint16_t i; // dx
  unsigned int v1; // eax
  unsigned int result; // eax

  if ( (uint8_t)byte_199CB0 < 2u )
    sub_10A036(4);
  memset(&word_1838F7, 0, 22);
  memset(&word_1ACF18, 0, 94);
  for ( i = 0; i < 0x10u; ++i )
  {
    v1 = i;
    result = sub_104B6B(v1);
  }
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1838F7: using guessed type int16_t word_1838F7;
// 199CB0: using guessed type char byte_199CB0;
// 1ACF18: using guessed type int16_t word_1ACF18;


//----- (0010208A) --------------------------------------------------------
int sub_10208A()
{
  int v0; // eax
  uint16_t v1; // si
  uint16_t v2; // di
  int16_t i; // dx
  _BYTE *v4; // eax
  int16_t j; // cx
  int v6; // ebx
  int16_t k; // cx
  int v8; // ebx
  unsigned int v9; // eax
  int16_t m; // cx
  uint8_t *v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  _BYTE *v16; // eax
  char v17; // dl
  int result; // eax
  _DWORD v19[350]; // [esp+0h] [ebp-1610h]
  _DWORD v20[1050]; // [esp+578h] [ebp-1098h] BYREF
  _DWORD v21[8]; // [esp+15E0h] [ebp-30h] BYREF
  int v22; // [esp+1600h] [ebp-10h]
  int v23; // [esp+1604h] [ebp-Ch]
  int v24; // [esp+1608h] [ebp-8h]
  int v25; // [esp+160Ch] [ebp-4h]

  sub_E2671((int)v21);
  if ( !word_17D638 )
    word_17D638 = 1;
  if ( !word_17D63A )
    word_17D63A = 1;
  if ( !word_17D63C )
    word_17D63C = 1;
  if ( !word_17D63E )
    word_17D63E = 1;
  LOWORD(v0) = word_17D638;
  v1 = word_17D63A;
  v23 = v0;
  LOWORD(v0) = word_17D63E;
  v25 = v0;
  v2 = word_17D63C;
  memset(v20, 0, 1400);
  for ( i = 0; i < word_199994; ++i )
  {
    v4 = (_BYTE *)(129 * i + dword_197F9C);
    if ( (char)v4[100] <= 1 )
      v20[(char)v4[99]] += 10 * (1 << (v4[16] + 1));
  }
  for ( j = 0; j < word_199998; ++j )
  {
    v6 = dword_197F98 + 3753 * j;
    v20[j + 700] = *(int16_t *)(v6 + 166);
    v20[j + 350] = v21[j];
    v19[j] = *(_DWORD *)(v6 + 548);
    while ( v20[j + 700] / (unsigned int)(uint16_t)v23 > 0xFA )
      ++v23;
    while ( v20[j + 350] / (unsigned int)v1 > 0xFA )
      ++v1;
    while ( v19[j] / (unsigned int)(uint16_t)v25 > 0xFA )
      ++v25;
    while ( v20[j] / (unsigned int)v2 > 0xFA )
      ++v2;
  }
  for ( k = 0; k < word_199998; ++k )
  {
    v8 = k;
    v22 = (uint16_t)v23;
    v20[k + 700] /= (unsigned int)(uint16_t)v23;
    v22 = v1;
    v20[k + 350] /= (unsigned int)v1;
    v22 = (uint16_t)v25;
    v19[k] /= (unsigned int)(uint16_t)v25;
    v22 = v2;
    v9 = v20[k] / (unsigned int)v2;
    v20[v8] = v9;
  }
  for ( m = 0; m < word_199998; ++m )
  {
    if ( (_WORD)v23 != word_17D638 || v1 != word_17D63A || v2 != word_17D63C || (_WORD)v25 != word_17D63E )
    {
      v24 = 0;
      do
      {
        v11 = (uint8_t *)(3753 * m + dword_197F98 + (int16_t)v24);
        v22 = v11[2971];
        v12 = v22 * (uint16_t)word_17D638;
        v22 = (uint16_t)v23;
        v11[2971] = v12 / (uint16_t)v23;
        v22 = v11[3321];
        v13 = v22 * (uint16_t)word_17D63A;
        v22 = v1;
        v11[3321] = v13 / v1;
        v22 = v11[2621];
        v14 = v22 * (uint16_t)word_17D63E;
        v22 = (uint16_t)v25;
        v11[2621] = v14 / (uint16_t)v25;
        v22 = v11[2271];
        v15 = v22 * (uint16_t)word_17D63C;
        v22 = v2;
        ++v24;
        v11[2271] = v15 / v2;
      }
      while ( (int16_t)v24 < 350 );
    }
    v22 = 3753 * m;
    v16 = (_BYTE *)((uint16_t)word_17D636 + v22 + dword_197F98);
    v16[2971] = v20[m + 700];
    v16[3321] = v20[m + 350];
    v16[2621] = v19[m];
    v17 = v20[m];
    v16[2271] = v17;
  }
  ++word_17D636;
  word_17D63A = v1;
  word_17D638 = v23;
  result = v25;
  word_17D63C = v2;
  word_17D63E = v25;
  if ( (uint16_t)word_17D636 >= 0x15Eu )
    word_17D636 = 0;
  return result;
}
// 1020F9: variable 'v0' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17D636: using guessed type int16_t word_17D636;
// 17D638: using guessed type int16_t word_17D638;
// 17D63A: using guessed type int16_t word_17D63A;
// 17D63C: using guessed type int16_t word_17D63C;
// 17D63E: using guessed type int16_t word_17D63E;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199998: using guessed type int16_t word_199998;


//----- (00102428) --------------------------------------------------------
int __fastcall sub_102428( int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(dword_197F98);
  LOWORD(v2) = *(uint8_t *)(3753 * a1 + dword_197F98 + 3680);
  return (1 << a2) & v2;
}
// 197F98: using guessed type int dword_197F98;


//----- (0010244D) --------------------------------------------------------
int __fastcall sub_10244D( int a1, int a2)
{
  int v2; // ebx
  int result; // eax

  v2 = 3753 * a1;
  result = dword_197F98;
  *(_BYTE *)(v2 + dword_197F98 + 3680) &= ~(1 << a2);
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0010248B) --------------------------------------------------------
int __fastcall sub_10248B(int a1, int a2)
{
  int result; // eax
  int v4; // esi
  int v5; // edx

  for ( result = 0; (int16_t)result < word_199998; ++result )
  {
    if ( (_WORD)result != word_19999C
      && !*(_BYTE *)(3753 * (int16_t)result + dword_197F98 + 36)
      && *(_BYTE *)((int16_t)result + 3753 * word_19999C + dword_197F98 + 1412) )
    {
      byte_199BA2[++a1] = result;
    }
  }
  if ( a2 )
  {
    v4 = dword_197F98;
    for ( result = 0; (int16_t)result < word_199998; ++result )
    {
      if ( (_WORD)result != word_19999C && !*(_BYTE *)(3753 * (int16_t)result + v4 + 36) )
      {
        v5 = (int16_t)result + v4 + 3753 * word_19999C;
        if ( !*(_BYTE *)(v5 + 1412) )
        {
          if ( *(_BYTE *)(v5 + 1421) )
            byte_199BA2[++a1] = result;
        }
      }
    }
  }
  word_199934 = a1;
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199934: using guessed type int16_t word_199934;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;


//----- (00102547) --------------------------------------------------------
int __fastcall sub_102547(int a1, int a2)
{
  int result; // eax
  int16_t v3; // bx

  sub_10248B(a1, a2);
  for ( result = 0; (int16_t)result < word_199998; ++result )
  {
    if ( (_WORD)result != word_19999C )
    {
      if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)result + 36) )
      {
        v3 = word_199934 + 1;
        byte_199BA3[word_199934] = result;
        word_199934 = v3;
      }
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199934: using guessed type int16_t word_199934;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;


//----- (00102597) --------------------------------------------------------
int __fastcall sub_102597(int a1, int a2)
{
  int result; // eax
  int16_t i; // dx
  _BOOL2 v4; // cx
  int16_t v5; // bx

  result = sub_10248B(a1, a2);
  for ( i = 0; i < word_199998; ++i )
  {
    if ( i != word_19999C )
    {
      if ( sub_79E06(word_19999C) || (result = 3753 * i, *(_BYTE *)(dword_197F98 + result + 36)) )
      {
        v4 = 0;
        for ( result = 0; (int16_t)result < word_199934 && !v4; ++result )
          v4 = i == (uint8_t)byte_199BA3[(int16_t)result];
        if ( !v4 )
        {
          result = word_199934;
          v5 = word_199934 + 1;
          byte_199BA3[word_199934] = i;
          word_199934 = v5;
        }
      }
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199934: using guessed type int16_t word_199934;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;


//----- (00102633) --------------------------------------------------------
int __fastcall sub_102633(int a1, int a2)
{
  int result; // eax
  int16_t i; // dx
  _BOOL2 v4; // cx
  int16_t v5; // bx

  result = sub_10248B(a1, a2);
  for ( i = 0; i < word_199998; ++i )
  {
    if ( i != word_19999C )
    {
      result = word_19999C;
      LOBYTE(result) = sub_79E06(word_19999C);
      if ( (_BYTE)result == 1 )
      {
        result = 3753 * i;
        if ( !*(_BYTE *)(dword_197F98 + result + 36) )
        {
          v4 = 0;
          for ( result = 0; (int16_t)result < word_199934 && !v4; ++result )
            v4 = i == (uint8_t)byte_199BA3[(int16_t)result];
          if ( !v4 )
          {
            result = word_199934;
            v5 = word_199934 + 1;
            byte_199BA3[word_199934] = i;
            word_199934 = v5;
          }
        }
      }
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199934: using guessed type int16_t word_199934;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;


//----- (001026CF) --------------------------------------------------------
int16_t __fastcall sub_1026CF( int a1, int a2)
{
  return *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 3671) & 0x3F;
}
// 197F98: using guessed type int dword_197F98;


//----- (001026F1) --------------------------------------------------------
int __fastcall sub_1026F1( int a1, int a2)
{
  return (int)*(uint8_t *)(3753 * a1 + dword_197F98 + a2 + 3671) >> 6;
}
// 197F98: using guessed type int dword_197F98;


//----- (00102711) --------------------------------------------------------
int16_t __fastcall sub_102711( int a1)
{
  return *(_BYTE *)(dword_197F98 + 3753 * word_19999C + a1 + 3671) & 0x3F;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (00102739) --------------------------------------------------------
int __fastcall sub_102739( int a1)
{
  return (int)*(uint8_t *)(dword_197F98 + 3753 * word_19999C + a1 + 3671) >> 6;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (0010275F) --------------------------------------------------------
void sub_10275F()
{
  JUMPOUT(0x102727);
}
// 102774: control flows out of bounds to 102727
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (00102776) --------------------------------------------------------
void sub_102776()
{
  JUMPOUT(0x10274F);
}
// 10278B: control flows out of bounds to 10274F
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


