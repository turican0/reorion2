#include "orion_common.h"

/* Adresni rozsah: 0x9F540 - 0xB0499  (200 funkci) */

//----- (0009F540) --------------------------------------------------------
void sub_9F540()
{
  int v0; // eax
  int v1; // ecx
  int16_t v2; // dx
  int16_t v3; // ax
  int v4; // ebx
  int16_t v5; // dx
  int16_t i; // dx
  char *v7; // ebx
  int16_t v8; // cx
  char *v9; // ecx
  int16_t v10; // dx
  int16_t v11; // ax
  int v12; // ebx
  int v13; // ecx
  int v14; // ebx
  char *v15; // esi
  _WORD v16[14]; // [esp+0h] [ebp-40h]
  char v17[20]; // [esp+1Ch] [ebp-24h] BYREF
  int v18; // [esp+30h] [ebp-10h]
  int v19; // [esp+34h] [ebp-Ch]
  int v20; // [esp+38h] [ebp-8h]
  int v21; // [esp+3Ch] [ebp-4h]

  v18 = fopen(aHofM2, aWb_2);
  v19 = 10;
  memset(&word_19C5FC, 0, 452);
  word_19C5FC = 130;
  v0 = 0;
  do
  {
    v16[(int16_t)v0] = v0;
    ++v0;
  }
  while ( (int16_t)v0 < 13 );
  v1 = 0;
  while ( 1 )
  {
    v2 = sub_1247A0(0xBu) + 1;
    v3 = sub_1247A0(0xBu) + 1;
    if ( v2 != v3 )
    {
      v4 = v2;
      v5 = v16[v2];
      v16[v4] = v16[v3];
      v16[v3] = v5;
    }
    if ( (int16_t)++v1 >= 10 )
    {
      for ( i = 2; i < 10; ++i )
      {
        v7 = &aMoise[20 * (int16_t)(sub_1247A0(8u) + 1)];
        v8 = sub_1247A0(8u) + 1;
        strcpy(v17, v7);
        v9 = &aMoise[20 * v8];
        strcpy(v7, v9);
        strcpy(v9, v17);
      }
      v21 = 0;
      v20 = 125 * v19 + 250;
      do
      {
        v10 = 15 * (sub_1247A0((int16_t)v19 + 1) - 1);
        v11 = sub_1247A0(5u);
        v12 = (int16_t)v21;
        word_19C6C6[(int16_t)v21] = v20 + v10 + 10 * v11;
        v13 = v12;
        byte_19C6EE[v12] = v12 % 5;
        v14 = 20 * v12;
        strcpy(&byte_19C5FE[v14], &aMoise[v14]);
        if ( (int16_t)v21 >= 2 )
          v15 = (char *)dword_192630[(int16_t)v16[v13]];
        else
          v15 = (char *)dword_192644[0];
        strcpy(&byte_19C6F8[v14], v15);
        v20 -= 125;
        ++v21;
        --v19;
      }
      while ( (int16_t)v21 < 10 );
      if ( v18 )
      {
        fwrite(&word_19C5FC, 452, 1, v18);
        fclose(v18);
      }
      JUMPOUT(0x9D945);
    }
  }
}
// 9F70D: control flows out of bounds to 9D945
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);
// 192630: using guessed type int dword_192630[];
// 192644: using guessed type int dword_192644[];
// 19C5FC: using guessed type int16_t word_19C5FC;
// 19C6C6: using guessed type int16_t word_19C6C6[];


//----- (0009F712) --------------------------------------------------------
void __usercall sub_9F712(int a1, int16_t *a2)
{
  int v2; // ecx
  int v3; // ebx
  int v4; // eax
  int16_t v5; // si
  int16_t v6; // dx
  int64_t v7; // rax
  int v8; // edx
  char *v9; // eax
  char *v10; // eax
  int v11; // edx
  int16_t v12; // si
  char *v13; // edi
  char *v14; // esi
  int v15; // ecx
  char *v16; // edi
  int v17; // [esp-4h] [ebp-31Eh]
  char v18[500]; // [esp+0h] [ebp-31Ah] BYREF
  _BYTE v19[200]; // [esp+1F4h] [ebp-126h] BYREF
  _BYTE v20[200]; // [esp+2BCh] [ebp-5Eh] BYREF
  int v21; // [esp+384h] [ebp+6Ah]
  int v22; // [esp+388h] [ebp+6Eh]
  int v23; // [esp+38Ch] [ebp+72h]
  int v24; // [esp+390h] [ebp+76h]
  int v25; // [esp+394h] [ebp+7Ah]
  char v26; // [esp+398h] [ebp+7Eh]

  v2 = a1;
  v3 = -1;
  LOWORD(v4) = sub_9EA3B(a1, a2);
  v25 = v4;
  v26 = 0;
  sub_1191CA((int)nullsub_15, 1);
  v5 = 0;
  dword_19C7C0 = (int)sub_110CEE(dword_192ED4, 293);
  v6 = 0;
  while ( 1 )
  {
    if ( v5 < word_19C6C6[v6] )
      v5 = word_19C6C6[v6];
    if ( ++v6 >= 10 )
    {
      HIDWORD(v7) = 0;
      sub_9FBE9(dword_19C7C0 + 253);
      while ( 1 )
      {
        v23 = 4 * SWORD2(v7);
        if ( (int16_t)v25 >= *(int16_t *)(v23 + dword_19C7C0 + 253) )
          LOWORD(v3) = *(_WORD *)(v23 + dword_19C7C0 + 255);
        ++HIDWORD(v7);
        if ( SWORD2(v7) >= 10 )
        {
          if ( (int16_t)v3 > -1 )
          {
            v8 = 3753 * (int16_t)v2;
            if ( *(_BYTE *)(v8 + dword_197F98 + 3689) )
            {
              v3 = -1;
              sub_8F6DF(0x17u, v18);
              HIDWORD(v7) = 1;
              sub_77433(v18);
              v26 = 1;
              sub_123E6C((int)&unk_17CF00, 1);
            }
            else
            {
              v17 = v8 + dword_197F98 + 1;
              if ( v5 > (int16_t)v25 )
              {
                v10 = sub_7A990(0x28u);
                v7 = sprintf(v20, v10, v17);
                LODWORD(v7) = v20;
              }
              else
              {
                v9 = sub_7A990(0x27u);
                v7 = sprintf(v19, v9, v17);
                LODWORD(v7) = v19;
              }
              sub_77433(v7);
            }
            if ( !v26 )
            {
              v24 = 0;
              while ( (int16_t)v3 > (int16_t)v24 )
              {
                v11 = (int16_t)v24;
                v21 = 20 * ((int16_t)v24 + 1);
                v22 = 20 * (int16_t)v24;
                strcpy(&byte_19C5FE[v22], &byte_19C5FE[v21]);
                v12 = word_19C6C8[v11];
                ++v24;
                word_19C6C6[v11] = v12;
                v13 = &byte_19C6F8[v22];
                word_19C6DA[v11] = word_19C6DC[v11];
                v14 = &byte_19C6F8[v21];
                byte_19C6EE[v11] = byte_19C6EF[v11];
                strcpy(v13, v14);
              }
              v15 = 3753 * (int16_t)v2;
              HIDWORD(v7) = (int16_t)v3;
              v22 = 20 * (int16_t)v3;
              strcpy(&byte_19C5FE[v22], (char *)(v15 + dword_197F98 + 1));
              word_19C6C6[(int16_t)v3] = v25;
              v2 = dword_197F98 + v15;
              LOBYTE(v7) = byte_199CB0;
              v16 = &byte_19C6F8[v22];
              word_19C6DA[(int16_t)v3] = *(uint8_t *)(v2 + 37);
              byte_19C6EE[(int16_t)v3] = v7;
              strcpy(v16, (char *)(v2 + 21));
            }
          }
          if ( (int16_t)v3 > -1 && !v26 )
            sub_9F505();
          sub_9F286(v3, SHIDWORD(v7), v3, v2);
          word_199A08 = 10;
          byte_199F19 = 14;
          JUMPOUT(0x9DEEB);
        }
      }
    }
  }
}
// 9F97C: control flows out of bounds to 9DEEB
// 9F733: variable 'v4' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// FE8D4: using guessed type int __fastcall nullsub_15(_DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 199A08: using guessed type int16_t word_199A08;
// 199CB0: using guessed type char byte_199CB0;
// 199F19: using guessed type char byte_199F19;
// 19C6C6: using guessed type int16_t word_19C6C6[];
// 19C6C8: using guessed type int16_t word_19C6C8[9];
// 19C6DA: using guessed type int16_t word_19C6DA[];
// 19C6DC: using guessed type int16_t word_19C6DC[9];
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009F981) --------------------------------------------------------
void sub_9F981()
{
  int v0; // eax
  int v1; // edx
  int v2; // eax
  int v3; // ecx
  int16_t v4; // bx
  int16_t v5; // di
  int v6; // esi
  int16_t v7; // dx
  int16_t v8; // ax
  int16_t v9; // dx
  int v10; // eax
  int16_t v11; // ax
  char *v12; // eax
  int16_t *v13; // edi
  int v14; // eax
  int v15; // eax
  void *v16; // eax
  int v17; // [esp-4h] [ebp-8h]
  int v18; // [esp+0h] [ebp-4h]

  sub_11C2F0();
  v0 = dword_19C7C0;
  *(_BYTE *)(dword_19C7C0 + 187) = -2;
  v1 = 0;
  *(_BYTE *)(v0 + 107) = 1;
  do
  {
    v2 = (int16_t)v1;
    v3 = dword_19C7C0;
    v4 = word_19C6C6[(int16_t)v1];
    *(_WORD *)(dword_19C7C0 + 4 * (int16_t)v1 + 255) = v1;
    ++v1;
    *(_WORD *)(v3 + 4 * v2 + 253) = v4;
  }
  while ( (int16_t)v1 < 10 );
  v5 = 153;
  v18 = 131;
  v6 = 0;
  qsort(v3 + 253, 10, 4);
  do
  {
    v7 = v18;
    v18 += 29;
    v8 = sub_11438B(139, v7, 155, v5, &unk_179BDA, 0);
    v5 += 29;
    v9 = v8;
    v10 = (int16_t)v6++;
    *(_WORD *)(dword_19C7C0 + 2 * v10 + 84) = v9;
  }
  while ( (int16_t)v6 < 10 );
  v11 = sub_11438B(0, 0, 639, 479, asc_179BAA, 41);
  byte_199F34 = -16;
  *(_WORD *)(dword_19C7C0 + 76) = v11;
  v12 = sub_8E5C5(4u, 239, 244);
  v17 = dword_19C7C0 + 110;
  qmemcpy((void *)(dword_19C7C0 + 110), v12, 8u);
  v13 = (int16_t *)v17;
  v14 = dword_19C7C0;
  *(_BYTE *)(dword_19C7C0 + 184) = 3;
  *(_BYTE *)(v14 + 185) = 1;
  *(_BYTE *)(v14 + 186) = 0;
  *(_WORD *)(dword_19C7C0 + 80) = sub_11ADB4((int)aC_3, 239);
  sub_1172D4();
  sub_123E6C((int)&unk_17CF4A, 1);
  sub_C5BB9();
  sub_124D41();
  LOBYTE(v15) = sub_128C32(0, 0, 639, 479, 0);
  sub_1077D(v15, 0, 639, v13);
  sub_1205E6(12, 0, 255);
  sub_1318D4(0, 255);
  sub_131F7B();
  sub_132C80(100);
  strcpy(byte_19C7C6, (char *)sub_CDF5C(545));
  strcpy(byte_19C7D5, (char *)sub_CDF5C(280));
  strcpy(byte_19C7E4, (char *)sub_CDF5C(190));
  strcpy(byte_19C7F3, (char *)sub_CDF5C(318));
  strcpy((char *)word_19C802, (char *)sub_CDF5C(328));
  sub_124D41();
  sub_9EE43();
  sub_131922(0, 255);
  sub_C5C44();
  v16 = sub_124DEC();
  sub_1077D((int)v16, 255, 255, word_19C802);
  sub_1172FC();
  sub_12B79D(*(_DWORD *)(dword_19C7C0 + 72));
  JUMPOUT(0x9D945);
}
// 9FBD1: control flows out of bounds to 9D945
// 9FAE2: variable 'v15' is possibly undefined
// 199F34: using guessed type char byte_199F34;
// 19C6C6: using guessed type int16_t word_19C6C6[];
// 19C7C0: using guessed type int dword_19C7C0;
// 19C802: using guessed type int16_t word_19C802[8];


//----- (0009FBE9) --------------------------------------------------------
int __fastcall sub_9FBE9(int a1)
{
  int v2; // edx
  int v3; // eax
  int16_t v4; // bx

  v2 = 0;
  do
  {
    v3 = (int16_t)v2;
    v4 = word_19C6C6[(int16_t)v2];
    *(_WORD *)(a1 + 4 * (int16_t)v2 + 2) = v2;
    ++v2;
    *(_WORD *)(a1 + 4 * v3) = v4;
  }
  while ( (int16_t)v2 < 10 );
  return qsort(a1, 10, 4);
}
// 19C6C6: using guessed type int16_t word_19C6C6[];


//----- (0009FC27) --------------------------------------------------------
char sub_9FC27()
{
  int v0; // edx
  int v1; // ecx
  int v2; // eax
  char *v3; // edi
  char *v4; // esi
  char result; // al
  int v6; // [esp+0h] [ebp-152h]
  _WORD v7[226]; // [esp+4h] [ebp-14Eh] BYREF
  int v8; // [esp+1C8h] [ebp+76h]
  int v9; // [esp+1CCh] [ebp+7Ah]
  int v10; // [esp+1D0h] [ebp+7Eh]

  v10 = 0;
  v7[0] = word_19C5FC;
  do
  {
    v0 = (int16_t)v10;
    v1 = *(int16_t *)(v6 + 4 * (int16_t)v10 + 2);
    v8 = 20 * v1;
    v2 = 20 * (int16_t)v10++;
    v9 = v2;
    strcpy((char *)&v7[1] + v2, &byte_19C5FE[20 * v1]);
    LOWORD(v2) = word_19C6DA[v1];
    v7[v0 + 101] = word_19C6C6[v1];
    v3 = (char *)&v7[126] + v9;
    v7[v0 + 111] = v2;
    v4 = (char *)&unk_19C6F8 + v8;
    *((_BYTE *)&v7[121] + v0) = byte_19C6EE[v1];
    strcpy(v3, v4);
  }
  while ( (int16_t)v10 < 10 );
  qmemcpy(&word_19C5FC, v7, 0x1C4u);
  return result;
}
// 9FC53: variable 'v6' is possibly undefined
// 19C5FC: using guessed type int16_t word_19C5FC;
// 19C6C6: using guessed type int16_t word_19C6C6[];
// 19C6DA: using guessed type int16_t word_19C6DA[];


//----- (0009FCF0) --------------------------------------------------------
void __fastcall sub_9FCF0( int a1)
{
  int v3; // esi
  int16_t i; // bx
  int v5; // eax
  int16_t v6; // di
  int v7; // ebx
  int16_t v8; // si
  int v9; // edx
  uint16_t v10; // dx
  char *v11; // eax
  int v12; // eax
  int16_t k; // bx
  unsigned int v14; // edi
  int16_t v15; // dx
  int16_t v16; // cx
  char *v17; // eax
  int16_t v18; // si
  int v19; // edi
  int v20; // eax
  _WORD *v21; // ecx
  _WORD v22[14]; // [esp+0h] [ebp-38h] BYREF
  int v23; // [esp+1Ch] [ebp-1Ch]
  char v24; // [esp+20h] [ebp-18h]
  int v25; // [esp+24h] [ebp-14h]
  _DWORD *v26; // [esp+28h] [ebp-10h]
  int v27; // [esp+2Ch] [ebp-Ch]
  int16_t j; // [esp+30h] [ebp-8h]
  char v29; // [esp+34h] [ebp-4h]

  v29 = 0;
  v3 = 0;
  for ( i = 0; i < word_199996; ++i )
  {
    v25 = 361 * i;
    v5 = v25 + dword_192B18;
    if ( a1 == *(char *)(v25 + dword_192B18) )
    {
      LOWORD(v5) = *(uint8_t *)(v5 + 10);
      v3 += v5;
    }
  }
  v27 = v3;
  memset(v22, 0, sizeof(v22));
  v6 = 0;
  sub_1112EC(dword_192ED4, 0);
  v7 = 5 * (int16_t)v3;
  v8 = 0;
  v9 = 0;
  v26 = sub_110D3C(dword_192ED4, v7);
  memset(v26, 0, v7);
  while ( v8 < word_199996 && !v29 )
  {
    v9 = dword_192B18;
    if ( *(char *)(dword_192B18 + 361 * v8) == a1 )
    {
      for ( j = 0; ; ++j )
      {
        v9 = 361 * v8;
        v12 = v9 + dword_192B18;
        LOWORD(v9) = *(uint8_t *)(v9 + dword_192B18 + 10);
        if ( (int16_t)v9 <= j || v29 )
          break;
        v10 = *(uint8_t *)(3753 * (*(_DWORD *)(v12 + 4 * j + 12) & 0xF) + dword_197F98 + 37);
        if ( v10 < 0xEu )
        {
          if ( v6 == (_WORD)v27 )
          {
            v29 = 1;
          }
          else
          {
            ++v22[(int16_t)v10];
            v11 = (char *)v26 + 5 * v6;
            *(_WORD *)v11 = v8;
            ++v6;
            v11[2] = v10;
            v11[3] = j;
          }
        }
      }
    }
    ++v8;
  }
  for ( k = 0; k < (int16_t)v27; ++k )
  {
    v14 = (int16_t)v27;
    v15 = sub_1247A0((int16_t)v27) - 1;
    v16 = sub_1247A0(v14) - 1;
    v17 = (char *)v26 + 5 * v15;
    v23 = *(_DWORD *)v17;
    v24 = v17[4];
    v9 = (int)v26 + 5 * v16;
    *(_DWORD *)v17 = *(_DWORD *)v9;
    v17[4] = *(_BYTE *)(v9 + 4);
    *(_DWORD *)v9 = v23;
    *(_BYTE *)(v9 + 4) = v24;
  }
  v18 = 0;
  while ( 1 )
  {
    if ( (int16_t)v22[v18] > 0 )
    {
      v19 = (160 * (int16_t)v22[v18] / (int16_t)v27 + 5) / 10;
      v20 = *(int16_t *)(dword_19C7C0 + 158);
      v9 = v20 + v19;
      if ( v20 + v19 > 16 && v19 > 1 )
        v19 = 16 - v20;
      j = 0;
      while ( j < v19 && *(int16_t *)(dword_19C7C0 + 158) < 16 )
      {
        v21 = (_WORD *)(dword_19C7C0 + 189 + 4 * *(int16_t *)(dword_19C7C0 + 158));
        v9 = v18;
        sub_9FF36((int)v26, v18, v27, v21, v21 + 1);
        ++j;
        ++*(_WORD *)(dword_19C7C0 + 158);
      }
    }
    if ( ++v18 >= 14 )
    {
      sub_1113CC(dword_192ED4, v9);
      JUMPOUT(0x9D945);
    }
  }
}
// 9FF31: control flows out of bounds to 9D945
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 19C7C0: using guessed type int dword_19C7C0;


//----- (0009FF36) --------------------------------------------------------
int16_t __fastcall sub_9FF36(int a1, int a2, int a3, _WORD *a4, int16_t *a5)
{
  int v5; // esi
  int16_t v6; // dx
  char v7; // bl
  int16_t v10; // [esp+4h] [ebp-14h]
  int16_t v11; // [esp+8h] [ebp-10h]
  int16_t v13; // [esp+10h] [ebp-8h]
  char v14; // [esp+14h] [ebp-4h]

  v5 = a1;
  v14 = 0;
  v13 = -1;
  v10 = -1;
  v6 = 0;
  v7 = 0;
  v11 = 0;
  while ( !v7 )
  {
    a1 = v5 + 5 * v6;
    if ( *(uint8_t *)(a1 + 2) == a2 )
    {
      if ( v13 == -1 )
      {
        v13 = *(_WORD *)a1;
        v10 = *(uint8_t *)(a1 + 3);
      }
      a1 = v5 + 5 * v6;
      if ( !*(_BYTE *)(a1 + 4) )
      {
        v14 = 1;
        v7 = 1;
        *a4 = *(_WORD *)a1;
        LOWORD(a1) = *(uint8_t *)(a1 + 3);
        v11 = v6;
        *a5 = a1;
      }
    }
    if ( ++v6 == a3 )
      v7 = 1;
  }
  if ( v14 )
  {
    a1 = 5 * v11;
    *(_BYTE *)(v5 + a1 + 4) = 1;
  }
  else if ( a4 == (_WORD *)-1 )
  {
    *(_WORD *)0xFFFFFFFF = v13;
    LOWORD(a1) = v10;
    *a5 = v10;
  }
  return a1;
}


//----- (0009FFEC) --------------------------------------------------------
int __fastcall sub_9FFEC(uint8_t *a1, uint8_t *a2)
{
  return *a1 - *a2;
}


//----- (0009FFF5) --------------------------------------------------------
int __fastcall sub_9FFF5(int a1)
{
  int16_t *v1; // ebx
  int result; // eax

  v1 = (int16_t *)a1;
  *(_WORD *)(a1 + 27) = *(_WORD *)a1;
  if ( *(_WORD *)(a1 + 8) >= *(_WORD *)(a1 + 10) )
    a1 = (*(int16_t *)(a1 + 10) * *(int16_t *)(a1 + 14) + *(int16_t *)(a1 + 10) - 1) / *(int16_t *)(a1 + 8);
  else
    LOWORD(a1) = *(_WORD *)(a1 + 14);
  v1[3] = a1;
  sub_A0125(v1);
  result = sub_A0040((int)v1);
  v1[6] = result;
  return result;
}


//----- (000A0040) --------------------------------------------------------
int __fastcall sub_A0040(int a1)
{
  int v1; // esi
  int v3; // [esp+4h] [ebp-4h]

  v1 = 0;
  if ( *(int16_t *)(a1 + 8) > 0 )
  {
    v3 = *(int16_t *)(a1 + 14);
    v1 = 10
       * (v3 - (int16_t)(*(_WORD *)a1 + *(int16_t *)(a1 + 6) / 2))
       / (int16_t)(10 * v3 * *(uint8_t *)(a1 + 26) / *(int16_t *)(a1 + 8));
    if ( (int16_t)v1 + *(int16_t *)(a1 + 10) > *(int16_t *)(a1 + 8)
      || *(_WORD *)(a1 + 8) > *(_WORD *)(a1 + 10)
      && (int16_t)(*(_WORD *)(dword_1975C4 + 14) - (*(int16_t *)(dword_1975C4 + 6) / 2 + *(_WORD *)dword_1975C4))
       + *(int16_t *)(a1 + 6) >= v3 )
    {
      LOWORD(v1) = *(_WORD *)(a1 + 8) - *(_WORD *)(a1 + 10);
    }
    if ( (int16_t)v1 <= 0 )
      return 0;
    else
      return (int16_t)v1;
  }
  return v1;
}
// 1975C4: using guessed type int dword_1975C4;


//----- (000A00F1) --------------------------------------------------------
int16_t __fastcall sub_A00F1(_WORD *a1)
{
  *(_WORD *)((char *)a1 + 27) = *a1;
  if ( a1[4] >= a1[5] )
    return ((int16_t)a1[5] * (int16_t)a1[7] + (int16_t)a1[5] - 1) / (int16_t)a1[4];
  else
    LOWORD(a1) = a1[7];
  return (int16_t)a1;
}


//----- (000A0125) --------------------------------------------------------
void __fastcall sub_A0125(int16_t *a1)
{
  int v2; // eax
  int v3; // esi
  int v4; // edx

  v2 = a1[3] / 2;
  v3 = *a1;
  v4 = a1[7];
  if ( v3 + v2 <= v4 )
  {
    if ( v3 - v2 < 0 )
      *a1 = v2;
  }
  else
  {
    *a1 = v4 - v2;
  }
  JUMPOUT(0xA00EB);
}
// A015B: control flows out of bounds to A00EB


//----- (000A015D) --------------------------------------------------------
int16_t __fastcall sub_A015D(int16_t *a1)
{
  int16_t result; // ax
  int v3; // ecx

  result = a1[4];
  if ( result > a1[5] )
  {
    v3 = a1[4];
    a1[6] += *((uint8_t *)a1 + 26);
    if ( a1[6] <= v3 - a1[5] )
    {
      *a1 -= *((uint8_t *)a1 + 26) * (uint16_t)(a1[7] / v3);
    }
    else
    {
      a1[6] = a1[4] - a1[5];
      *a1 = a1[3] / 2;
    }
    result = *a1;
    a1[1] = *a1;
    a1[2] = result;
  }
  return result;
}


//----- (000A01C6) --------------------------------------------------------
int16_t __fastcall sub_A01C6(int16_t *a1)
{
  int16_t result; // ax
  int v3; // kr00_4
  int16_t v4; // dx

  result = a1[4];
  if ( result > a1[5] )
  {
    a1[6] -= *((uint8_t *)a1 + 26);
    if ( a1[6] > 0 )
    {
      *a1 += a1[7] / a1[4] * *((uint8_t *)a1 + 26);
    }
    else
    {
      v3 = a1[3];
      v4 = a1[7];
      a1[6] = 0;
      *a1 = v4 + v3 / 2;
    }
    result = *a1;
    a1[1] = *a1;
    a1[2] = result;
  }
  return result;
}


//----- (000A0226) --------------------------------------------------------
_BOOL1 __fastcall sub_A0226(int16_t *a1, void (__cdecl *a2)(_DWORD))
{
  int16_t v3; // ax
  int16_t v4; // di
  int16_t v5; // si
  int v6; // eax
  int64_t v7; // rax
  int16_t v8; // ax
  char v9; // al
  int16_t v10; // ax

  v3 = sub_124075();
  *((_BYTE *)a1 + 25) = 0;
  v4 = v3;
  *(int16_t *)((char *)a1 + 27) = *a1;
  v5 = a1[6];
  if ( a1[4] >= a1[5] )
    v6 = (a1[5] * a1[7] + a1[5] - 1) / a1[4];
  else
    LOWORD(v6) = a1[7];
  a1[3] = v6;
  if ( a1[1] == -1 )
    goto LABEL_8;
  if ( a1[1] != *a1 )
  {
    v7 = *a1 - a1[2];
    if ( (int)((HIDWORD(v7) ^ v7) - HIDWORD(v7)) > a1[3] / 2 )
    {
      a1[3] = sub_A00F1(a1);
      sub_A0125(a1);
      a1[6] = sub_A0040((int)a1);
LABEL_8:
      v8 = *a1;
      a1[1] = *a1;
      a1[2] = v8;
    }
  }
  sub_A0125(a1);
  if ( v9 )
  {
    a1[6] = sub_A0040((int)a1);
    v10 = *a1;
    a1[1] = *a1;
    a1[2] = v10;
  }
  a2(a2);
  if ( v4 == 1 )
    ++*((_BYTE *)a1 + 25);
  return v5 != a1[6];
}
// A02D4: variable 'v9' is possibly undefined


//----- (000A0305) --------------------------------------------------------
int sub_A0305()
{
  _DWORD *v0; // ecx
  int16_t v1; // bx
  int16_t v2; // di
  int v3; // edx
  int16_t v4; // di
  int16_t v5; // ax
  int v6; // edx
  char *v7; // edx
  int16_t v8; // ax
  uint8_t *v9; // edx
  int v10; // edx
  char *v11; // esi
  int16_t v12; // dx
  int v13; // edx
  int v14; // esi
  char *v15; // edx
  int16_t v16; // dx
  int v17; // edx
  int v18; // edx
  int16_t v19; // si
  int v20; // esi
  char *v21; // edx
  int result; // eax
  char v23; // [esp+0h] [ebp-3Ch]
  _DWORD *v24; // [esp+8h] [ebp-34h]
  int16_t v25; // [esp+Ch] [ebp-30h]
  int16_t v26; // [esp+18h] [ebp-24h]
  int v27; // [esp+1Ch] [ebp-20h]
  int16_t v28; // [esp+20h] [ebp-1Ch]
  int16_t v29; // [esp+24h] [ebp-18h]
  int16_t v30; // [esp+28h] [ebp-14h]
  int16_t v31; // [esp+30h] [ebp-Ch]
  int16_t i; // [esp+34h] [ebp-8h]
  char v33; // [esp+38h] [ebp-4h]

  sub_5D41E();
  sub_11127C(dword_192EE8);
  v24 = sub_110D3C(dword_192EE8, 360);
  v0 = sub_110D3C(dword_192EE8, 288);
  sub_1112B4(dword_192EE8);
  memset(v0, 2, 288);
  v33 = 0;
  memset(&word_1906C0, -1, 6864);
  v27 = 0;
  memset(v24, -1, 360);
  word_1999F8 = 0;
  while ( 1 )
  {
    result = v27;
    if ( (int16_t)v27 >= word_199A02 )
      break;
    v1 = word_192248[(int16_t)v27];
    v31 = sub_78BB2(v1);
    v2 = sub_78BCF(v1);
    v26 = sub_77FE9(v1);
    v3 = 129 * *(int16_t *)((char *)&word_1975D4 + 5 * v1);
    v4 = sub_7A3E3(v31, v2);
    v5 = sub_78B93(v1);
    v29 = v5;
    v28 = word_1999F8 + 1;
    if ( *(_BYTE *)(v3 + dword_197F9C + 100) == 1 )
    {
      v6 = 6 * word_1999F8;
      word_1906C6[v6] = 5;
      v33 = 1;
LABEL_4:
      word_1906C4[v6] = v5;
      word_1906C2[v6] = v1;
      word_1999F8 = v28;
      goto LABEL_43;
    }
    if ( v5 > -1 && v5 < 500 )
    {
      v7 = (char *)v24 + 5 * v5;
      if ( *v7 == -1 )
      {
        *(_WORD *)(v7 + 1) = v1;
        *v7 = v26;
        v8 = word_1999F8;
        *(_WORD *)(v7 + 3) = word_1999F8;
        v6 = 6 * v8;
        v5 = v29;
        word_1906C6[v6] = 0;
        goto LABEL_4;
      }
      if ( *v7 != word_19999C && v26 == word_19999C )
      {
        v30 = *(_WORD *)(v7 + 3);
        v9 = (uint8_t *)v0 + v5;
        word_1906C6[6 * v30] = *v9;
        v10 = *v9 + 1;
        if ( v10 >= 3 )
          v23 = 3;
        else
          v23 = v10;
        v11 = (char *)v24 + 5 * v5;
        *((_BYTE *)v0 + v5) = v23;
        *v11 = word_19999C;
        v12 = word_1999F8;
        *(_WORD *)(v11 + 3) = word_1999F8;
        v13 = 6 * v12;
        *(_WORD *)(v11 + 1) = v1;
        word_1906C6[v13] = 0;
        goto LABEL_42;
      }
      v14 = v5;
      v15 = (char *)v24 + 5 * v5;
      if ( *v15 == -1
        || (v16 = *v15, v16 == v26)
        || v26 != *(char *)(dword_19306C + 113 * v5 + 20)
        || v16 != word_19999C
        || v26 == v16 )
      {
        v17 = 6 * word_1999F8;
        word_1906C2[v17] = v1;
        v14 = v5;
      }
      else
      {
        v17 = 6 * word_1999F8;
        word_1906C2[v17] = v1;
      }
      word_1906C4[v17] = v5;
LABEL_22:
      word_1906C6[v17] = *((uint8_t *)v0 + v14);
      v18 = *((uint8_t *)v0 + v14) + 1;
      if ( v18 >= 3 )
        LOBYTE(v18) = 3;
      ++word_1999F8;
      *((_BYTE *)v0 + v5) = v18;
      goto LABEL_43;
    }
    if ( v4 != v5 - 1000 )
    {
      if ( v5 >= 1000 && v4 > -1 )
      {
        v13 = 6 * word_1999F8;
        word_1906C6[v13] = 1;
LABEL_42:
        word_1906C2[v13] = v1;
        ++word_1999F8;
        word_1906C4[v13] = v5;
        goto LABEL_43;
      }
      if ( v5 != v4 )
      {
        v13 = 6 * word_1999F8;
        word_1906C6[v13] = 5;
        v33 = 1;
        goto LABEL_42;
      }
      v17 = 6 * word_1999F8;
      word_1906C2[v17] = v1;
      v14 = v4;
      word_1906C4[v17] = v4;
      goto LABEL_22;
    }
    v19 = 0;
    v25 = -1;
    for ( i = 0; i < word_1999F8 && !v19; ++i )
    {
      if ( word_1906C6[6 * i] == 1 && v1 == word_1906C2[6 * i] && v5 == word_1906C4[6 * i] )
      {
        v19 = 1;
        v25 = i;
      }
    }
    v20 = 6 * v25;
    v21 = (char *)v24 + 5 * v5;
    *v21 = v26;
    *(_WORD *)(v21 + 1) = word_1906C2[v20];
    word_1906C6[v20] = 0;
LABEL_43:
    ++v27;
  }
  if ( word_1999F8 > 0 )
  {
    if ( v33 )
      return qsort(&word_1906C0, word_1999F8, 12, sub_A162D);
  }
  return result;
}
// A162D: using guessed type int sub_A162D();
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 133EF4: using guessed type int __fastcall qsort(_DWORD, _DWORD, _DWORD, _DWORD);
// 1906C0: using guessed type int16_t word_1906C0;
// 1906C2: using guessed type int16_t word_1906C2[];
// 1906C4: using guessed type int16_t word_1906C4[];
// 1906C6: using guessed type int16_t word_1906C6[];
// 192248: using guessed type int16_t word_192248[500];
// 192EE8: using guessed type int dword_192EE8;
// 19306C: using guessed type int dword_19306C;
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 1999F8: using guessed type int16_t word_1999F8;
// 199A02: using guessed type int16_t word_199A02;


//----- (000A070F) --------------------------------------------------------
void __fastcall sub_A070F( int a1)
{
  int16_t v1; // ax
  int v2; // eax
  int16_t v3; // si
  int16_t v4; // ax
  int v5; // edx
  int v6; // ebx
  int v7; // [esp+0h] [ebp-10h] BYREF
  int v8; // [esp+4h] [ebp-Ch] BYREF
  int v9; // [esp+8h] [ebp-8h]
  char v10; // [esp+Ch] [ebp-4h]

  v10 = a1;
  v9 = -1;
  if ( sub_918D5(2) )
  {
    sub_7836A(word_1999B8);
    sub_78800(v1);
    v9 = v2;
  }
  v3 = word_1999F8;
  while ( --v3 > -1 )
  {
    sub_A0A5C(v3, &v8, (int16_t *)&v7);
    v4 = sub_78879(v3);
    v5 = 6 * v3;
    v6 = sub_A0D78(v4, 0);
    word_1906C8[v5] = v8;
    word_1906CA[v5] = v7;
    if ( v3 != (_WORD)v9 && v3 != word_19C180 || v10 )
    {
      sub_12B726(v6);
      sub_12A478(v8, v7, v6);
    }
  }
  JUMPOUT(0xA0708);
}
// A07C3: control flows out of bounds to A0708
// A073E: variable 'v1' is possibly undefined
// A0743: variable 'v2' is possibly undefined
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 1999B8: using guessed type int16_t word_1999B8;
// 1999F8: using guessed type int16_t word_1999F8;
// 19C180: using guessed type int16_t word_19C180;


//----- (000A07C8) --------------------------------------------------------
int sub_A07C8()
{
  int16_t i; // si
  int v1; // edx
  int result; // eax
  int v3; // [esp+0h] [ebp-8h] BYREF
  int v4; // [esp+4h] [ebp-4h] BYREF

  for ( i = word_1999F8 - 1; i > -1; --i )
  {
    sub_A0A5C(i, &v4, (int16_t *)&v3);
    v1 = 6 * i;
    word_1906C8[v1] = v4;
    result = v3;
    word_1906CA[v1] = v3;
  }
  return result;
}
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 1999F8: using guessed type int16_t word_1999F8;


//----- (000A080D) --------------------------------------------------------
void sub_A080D()
{
  int16_t v0; // si
  int v1; // edx
  int16_t v2; // di
  int16_t v3; // ax
  _BOOL1 v4; // ch
  _BOOL1 v5; // al
  _BOOL1 v6; // al
  _BOOL1 v7; // cl
  int16_t v8; // ax
  _BOOL1 v9; // al
  int v10; // edx
  int v11; // eax
  int16_t v12; // ax
  int v13; // eax
  int16_t v14; // bx
  int16_t v15; // ax
  int16_t v16; // [esp+0h] [ebp-18h] BYREF
  int16_t v17; // [esp+4h] [ebp-14h] BYREF
  int16_t v18; // [esp+8h] [ebp-10h] BYREF
  int v19; // [esp+Ch] [ebp-Ch]
  int16_t v20; // [esp+10h] [ebp-8h] BYREF
  _BOOL1 v21; // [esp+14h] [ebp-4h]

  v0 = word_1999F8;
  while ( --v0 > -1 )
  {
    v1 = 12 * v0;
    v2 = sub_78889(v0);
    LOWORD(v1) = *(int16_t *)((char *)word_1906C2 + v1);
    v3 = sub_77FF5(v2);
    v19 = v1;
    v4 = v3 != word_19999C;
    v5 = sub_77FF5(v2) == word_19999C
      && (uint16_t)sub_78E07(*(int16_t *)(dword_197F9C + 129 * v2 + 101)) != word_19999A;
    v21 = v5;
    v6 = v4 && *(_BYTE *)(dword_197F9C + 129 * v2 + 100) && sub_A1341(word_1906C2[6 * v0]);
    v7 = v6;
    v9 = 0;
    if ( sub_918D5(2) )
    {
      sub_7836A(word_1999B8);
      if ( v8 == (_WORD)v19 )
        v9 = 1;
    }
    if ( v21 || v7 || v9 )
    {
      v10 = 129 * v2;
      v11 = v10 + dword_197F9C;
      if ( *(int16_t *)(v10 + dword_197F9C + 101) >= 500
        && *(int16_t *)(v11 + 101) < 1500
        && (uint16_t)sub_78E07(*(int16_t *)(v11 + 101)) != word_19999A )
      {
        v12 = sub_78E07(*(int16_t *)(v10 + dword_197F9C + 101));
        sub_85B93(v12, &v17, &v20);
        sub_A0A5C(v0, &v16, &v18);
        if ( v7 || v4 )
          sub_A1299(v17, v20, v16, v18, (int)&unk_18213D);
        else
          sub_A1299(v17, v20, v16, v18, (int)&unk_182135);
        v13 = 129 * v2 + dword_197F9C;
        if ( *(int16_t *)(v13 + 101) >= 500 && *(int16_t *)(v13 + 101) < 1000 )
        {
          v14 = v16;
          v15 = sub_79917();
          sub_A13B0(word_1906C2[6 * v0], v15, v14);
        }
      }
    }
  }
  JUMPOUT(0xA0708);
}
// A09D3: control flows out of bounds to A0708
// A08DA: variable 'v8' is possibly undefined
// 1906C2: using guessed type int16_t word_1906C2[];
// 197F9C: using guessed type int dword_197F9C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1999B8: using guessed type int16_t word_1999B8;
// 1999F8: using guessed type int16_t word_1999F8;


//----- (000A09D8) --------------------------------------------------------
void sub_A09D8()
{
  int16_t i; // di
  int v1; // esi
  int16_t v2; // ax
  _WORD *v3; // eax
  int v4; // [esp+0h] [ebp-8h] BYREF
  int v5; // [esp+4h] [ebp-4h] BYREF

  for ( i = 0; i < word_1999F8; ++i )
  {
    sub_A0A5C(i, &v4, (int16_t *)&v5);
    v1 = 6 * i;
    v2 = sub_78879(i);
    v3 = (_WORD *)sub_A0D78(v2, 0);
    word_1906C0[v1] = sub_114A00(v4, v5, *v3 + v4, v3[1] + v5, &unk_179BE0, 0);
  }
  JUMPOUT(0xA0708);
}
// A0A3F: control flows out of bounds to A0708
// 1906C0: using guessed type int16_t word_1906C0[];
// 1999F8: using guessed type int16_t word_1999F8;


//----- (000A0A5C) --------------------------------------------------------
int16_t __fastcall sub_A0A5C( int a1, _WORD *a2, int16_t *a3)
{
  _WORD *v3; // esi
  int v4; // ecx
  int16_t v5; // ax
  int16_t result; // ax
  int v7; // eax
  _WORD v9[4]; // [esp+4h] [ebp-2Ch] BYREF
  _WORD v10[4]; // [esp+Ch] [ebp-24h] BYREF
  unsigned int v11; // [esp+14h] [ebp-1Ch]
  int v12; // [esp+18h] [ebp-18h]
  int v13; // [esp+1Ch] [ebp-14h] BYREF
  _WORD *v14; // [esp+20h] [ebp-10h]
  int v15; // [esp+24h] [ebp-Ch] BYREF
  int v16; // [esp+28h] [ebp-8h] BYREF
  int v17; // [esp+2Ch] [ebp-4h] BYREF

  v3 = a2;
  v4 = a1;
  sub_788AE();
  v11 = 12 * v4;
  v12 = 129 * *(int16_t *)((char *)&word_1975D4 + 5 * word_1906C2[6 * v4]);
  LOWORD(a2) = *(char *)(v12 + dword_197F9C + 99);
  v14 = a2;
  v5 = sub_7A3E3(*(_WORD *)(v12 + dword_197F9C + 103), *(_WORD *)(v12 + dword_197F9C + 105));
  if ( *(_BYTE *)(v12 + dword_197F9C + 100) == 1 )
    return sub_A0CD5(v4, v3, a3);
  sub_A0BB0(v5, *(char *)(v12 + dword_197F9C + 99), &v16, &v13, &v17, &v15, v10, v9);
  result = word_1906C6[v11 / 2];
  switch ( result )
  {
    case 0:
      *v3 = v16;
      result = v13;
      goto LABEL_5;
    case 1:
      *v3 = v17;
      result = v15;
      *a3 = v15;
      if ( (int16_t)v14 > 9 && (word_199992 == 10 || word_199992 == 15) )
        *v3 -= 2;
      return result;
    case 2:
    case 3:
    case 4:
      v7 = word_1906C6[6 * a1] - 2;
      if ( v7 >= 2 )
        LOWORD(v7) = 2;
      *v3 = v10[(int16_t)v7];
      result = v9[(int16_t)v7];
      goto LABEL_5;
    case 5:
      *v3 = sub_7926C(*(_WORD *)(v12 + dword_197F9C + 103));
      result = sub_7926C(*(_WORD *)(v12 + dword_197F9C + 105));
LABEL_5:
      *a3 = result;
      break;
    default:
      return result;
  }
  return result;
}
// 1906C2: using guessed type int16_t word_1906C2[];
// 1906C6: using guessed type int16_t word_1906C6[];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 199992: using guessed type int16_t word_199992;


//----- (000A0BB0) --------------------------------------------------------
_WORD *__fastcall sub_A0BB0(int a1, int a2, _WORD *a3, _WORD *a4, _WORD *a5, _WORD *a6, _WORD *a7, _WORD *a8)
{
  int v8; // ebx
  int v9; // edx
  _WORD *result; // eax
  int v11; // [esp+0h] [ebp-2Ch]
  int16_t v12; // [esp+4h] [ebp-28h]
  int16_t v13; // [esp+4h] [ebp-28h]
  int v15; // [esp+14h] [ebp-18h] BYREF
  int v16; // [esp+18h] [ebp-14h]
  int v17; // [esp+1Ch] [ebp-10h] BYREF
  int v18; // [esp+20h] [ebp-Ch]
  int v19; // [esp+24h] [ebp-8h]
  char v20; // [esp+28h] [ebp-4h]

  v19 = a1;
  v11 = *(int16_t *)sub_A0D78(a2, 0);
  v18 = sub_79917();
  v20 = 1 - v18;
  v12 = v19;
  sub_85B93(v19, &v17, &v15);
  v8 = sub_85B71(v12);
  v17 = (int16_t)v17 - v8 / 2;
  v15 = (int16_t)v15 - v8 / 2;
  v16 = 1 - v18 + 10;
  v13 = v20;
  HIWORD(v9) = (unsigned int)((int16_t)v17 + v8 - v11 / 2 + v20) >> 16;
  *a3 = v17 + v8 - v11 / 2 + v20;
  LOWORD(v9) = v20;
  v18 = v9;
  *a4 = v20 + (_WORD)v15 - 1;
  *a5 = v17 - v11 / 2 - v13 + 2;
  *a6 = v18 + v15 - 2;
  *a7 = *a5 - 1;
  *a8 = v16 + *a6;
  a7[1] = *a5 - 1;
  a8[1] = 2 * v16 + *a6;
  a7[2] = *a5 - 1;
  result = a8;
  a8[2] = 3 * v16 + *a6;
  return result;
}
// A0BB0: could not find valid save-restore pair for ebx


//----- (000A0CD5) --------------------------------------------------------
int __fastcall sub_A0CD5( int a1, _WORD *a2, _WORD *a3)
{
  int16_t v4; // ax
  int v5; // ecx
  int16_t v6; // dx
  int v7; // ecx
  int result; // eax
  int v9; // [esp+0h] [ebp-8h]
  int16_t v10; // [esp+4h] [ebp-4h]

  v10 = sub_78889(a1);
  v4 = sub_79917();
  v5 = v4;
  sub_A1BC9(v4, &byte_192E80[v4], &byte_192ECC[v4]);
  v6 = (uint8_t)byte_192E80[v5] / 2;
  v9 = 129 * v10;
  *a2 = sub_7926C(*(_WORD *)(v9 + dword_197F9C + 103) - word_19998C) + 21 - v6;
  v7 = (uint8_t)byte_192ECC[v5] / 2;
  result = (int16_t)sub_7926C(*(_WORD *)(v9 + dword_197F9C + 105) - word_199990) + 21 - v7;
  *a3 = result;
  return result;
}
// 197F9C: using guessed type int dword_197F9C;
// 19998C: using guessed type int16_t word_19998C;
// 199990: using guessed type int16_t word_199990;


//----- (000A0D78) --------------------------------------------------------
int __fastcall sub_A0D78( int a1, int a2)
{
  int16_t v3; // dx
  int16_t v4; // cx
  int16_t v5; // di
  int result; // eax
  int16_t v7; // cx
  int v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int16_t v12; // ax
  int v13; // esi
  int v14; // ecx

  v3 = 1;
  v4 = sub_79917();
  v5 = v4;
  result = 0;
  if ( v4 == 3 )
  {
    v3 = 0;
  }
  else if ( v4 != 2 )
  {
    if ( v4 == 1 )
    {
      v3 = 2;
    }
    else if ( !v4 )
    {
      v3 = 3;
    }
  }
  if ( a1 < 8 )
  {
    v7 = *(uint8_t *)(dword_197F98 + 3753 * a1 + 38);
    sub_79917();
    v8 = v7;
    v9 = 4 * v7;
    v10 = v3;
    v11 = sub_127C27((int)aBuffer0Lbx_3, v3 + v9 + 205, dword_193174);
    if ( a2 )
      dword_1905F8[4 * v8 + v10] = v11;
    else
      dword_18FEF8[4 * v8 + v10] = v11;
    return v11;
  }
  if ( a1 != 8 )
  {
    if ( a1 > 14 )
      return result;
    v12 = a1 - 9;
    if ( a2 )
    {
      v13 = 4 * v12;
      v11 = sub_127C27((int)aBuffer0Lbx_3, v4 + 4 * v12 + 241, dword_193174);
      dword_190518[v4 + v13] = v11;
    }
    else
    {
      v14 = 4 * v12;
      v11 = sub_127C27((int)aBuffer0Lbx_3, v5 + 4 * v12 + 241, dword_193174);
      dword_190598[v5 + v14] = v11;
    }
    return v11;
  }
  result = sub_127C27((int)aBuffer0Lbx_3, v3 + 237, dword_193174);
  if ( a2 )
    dword_1906B0[v3] = result;
  else
    dword_190678[v3] = result;
  return result;
}
// A0EA7: conditional instruction was optimized away because bx.2>=9
// 18FEF8: using guessed type int dword_18FEF8[32];
// 190518: using guessed type int dword_190518[32];
// 190598: using guessed type int dword_190598[24];
// 1905F8: using guessed type int dword_1905F8[32];
// 190678: using guessed type int dword_190678[4];
// 1906B0: using guessed type int dword_1906B0[];
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;


//----- (000A0F2A) --------------------------------------------------------
int16_t __fastcall sub_A0F2A(int16_t *a1, int a2, int16_t *a3)
{
  int16_t v3; // si
  int16_t i; // cx
  int v5; // edx
  int16_t v8; // [esp+4h] [ebp-4h]

  v3 = (int16_t)a1;
  *a3 = 0;
  for ( i = 0; i < word_199A02; ++i )
  {
    v8 = word_192248[i];
    a1 = (int16_t *)(dword_197F9C + 129 * *(int16_t *)((char *)&word_1975D4 + 5 * v8));
    v5 = dword_19306C + 113 * v3;
    if ( *(int16_t *)((char *)a1 + 103) == *(_WORD *)(v5 + 15) )
    {
      LOWORD(a1) = *(int16_t *)((char *)a1 + 105);
      if ( (_WORD)a1 == *(_WORD *)(v5 + 17) )
      {
        a1 = (int16_t *)(a2 + 2 * *a3);
        *a1 = v8;
        ++*a3;
      }
    }
  }
  return (int16_t)a1;
}
// 192248: using guessed type int16_t word_192248[500];
// 19306C: using guessed type int dword_19306C;
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 199A02: using guessed type int16_t word_199A02;


//----- (000A0FA8) --------------------------------------------------------
int __fastcall sub_A0FA8(int16_t *a1, int a2, int a3)
{
  int64_t v4; // rax
  int64_t v5; // rax
  int v6; // eax
  int16_t v7; // dx
  int16_t v8; // di
  int16_t i; // bx
  int64_t v10; // rax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // esi
  int16_t v15; // dx
  int64_t v17; // [esp+0h] [ebp-78h] BYREF
  unsigned int v18; // [esp+8h] [ebp-70h]
  int v19; // [esp+64h] [ebp-14h]
  int v20; // [esp+68h] [ebp-10h]
  int v21; // [esp+6Ch] [ebp-Ch]
  int v22; // [esp+70h] [ebp-8h]
  int v23; // [esp+74h] [ebp-4h]

  v19 = a2;
  v21 = a3;
  v4 = word_1999F2 - word_1906C8[6 * *a1];
  if ( (int)((HIDWORD(v4) ^ v4) - HIDWORD(v4)) <= (int16_t)v19
    && (v5 = word_1999F4 - word_1906CA[6 * *a1], (int)((HIDWORD(v5) ^ v5) - HIDWORD(v5)) <= (int16_t)a3) )
  {
    v22 = 0;
    v20 = 0;
    sub_127678((char *)&v17, 0x64u, 0);
    v8 = 0;
    sub_788AE();
    for ( i = 0; i < word_1999F8 && !(_WORD)v20; ++i )
    {
      v10 = word_1906C8[6 * i] - word_1906C8[6 * *a1];
      if ( (int)((HIDWORD(v10) ^ v10) - HIDWORD(v10)) < (int16_t)v19
        && (int)abs32(word_1906CA[6 * i] - word_1906CA[6 * *a1]) < (int16_t)v21 )
      {
        v11 = v8++;
        *((_WORD *)&v17 + v11) = i;
        if ( v8 >= 50 )
          v20 = 1;
      }
    }
    if ( v8 > 0 )
    {
      v23 = 0;
      while ( (int16_t)v23 < v8 - 1 )
      {
        v12 = 2 * (int16_t)v23;
        sub_1277DE(v17, v18);
        v13 = *(int16_t *)((char *)&v17 + v12 + 2);
        v14 = *(int16_t *)((char *)&v17 + v12);
        v15 = word_192248[v13];
        word_192248[v13] = word_192248[v14];
        ++v23;
        word_192248[v14] = v15;
      }
      v22 = 1;
      *a1 = v17;
    }
  }
  else
  {
    v6 = 12 * *a1;
    v22 = 0;
    v7 = *(int16_t *)((char *)word_1906C8 + v6);
    LOWORD(v6) = *(int16_t *)((char *)word_1906CA + v6);
    word_1999F2 = v7;
    word_1999F4 = v6;
  }
  return v22;
}
// 1906C8: using guessed type int16_t word_1906C8[];
// 1906CA: using guessed type int16_t word_1906CA[3427];
// 192248: using guessed type int16_t word_192248[500];
// 1999F2: using guessed type int16_t word_1999F2;
// 1999F4: using guessed type int16_t word_1999F4;
// 1999F8: using guessed type int16_t word_1999F8;


//----- (000A1157) --------------------------------------------------------
void __fastcall sub_A1157(int a1, int a2)
{
  int v4; // edx
  int v5; // ebx
  int16_t v6; // [esp+0h] [ebp-4h]

  memset(a1, -1, 1000);
  v4 = 0;
  sub_77FE9(a2);
  v6 = 0;
  while ( !v6 )
  {
    v5 = (int16_t)v4++;
    *(_WORD *)(a1 + 2 * v5) = *(int16_t *)((char *)&word_1975D4 + 5 * a2);
    if ( (int16_t)v4 < 500 )
    {
      a2 = *(int16_t *)((char *)&word_1975D6 + 5 * a2);
      if ( a2 != -1 )
        continue;
    }
    v6 = 1;
  }
  JUMPOUT(0xA0F24);
}
// A1184: control flows out of bounds to A0F24
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;


//----- (000A11C0) --------------------------------------------------------
int __fastcall sub_A11C0( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int16_t v7; // dx
  char v9; // dl
  int v10; // edi
  char v11; // dl
  int v12; // edi
  _BYTE v13[8]; // [esp+0h] [ebp-20h] BYREF
  int v14; // [esp+8h] [ebp-18h]
  int v15; // [esp+Ch] [ebp-14h]
  int v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-8h]
  int v19; // [esp+1Ch] [ebp-4h]

  v7 = 7 - a6;
  if ( 7 - (int16_t)a6 <= 0 )
    v7 = 0;
  v18 = a6;
  if ( a3 <= a1 )
  {
    if ( a4 > a2 )
      return sub_135870(a1, a2, a3, a4, a5, v7);
    v17 = 7;
    v16 = 0;
    do
    {
      v14 = (int16_t)v17;
      v11 = *(_BYTE *)(a5 + (int16_t)v16);
      v12 = (int16_t)v17--;
      ++v16;
      v13[v12] = v11;
    }
    while ( (int16_t)v16 < 8 );
  }
  else
  {
    if ( a4 >= a2 )
      return sub_135870(a1, a2, a3, a4, a5, v7);
    v19 = 7;
    v15 = 0;
    do
    {
      v14 = (int16_t)v19;
      v9 = *(_BYTE *)(a5 + (int16_t)v15);
      v10 = (int16_t)v19--;
      ++v15;
      v13[v10] = v9;
    }
    while ( (int16_t)v15 < 8 );
  }
  return sub_135870(a1, a2, a3, a4, (int)v13, (int16_t)v18);
}


//----- (000A1299) --------------------------------------------------------
int __fastcall sub_A1299( int a1, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  int v7; // ecx
  int v8; // edi
  int v9; // esi

  v6 = 3 - (int16_t)sub_79917();
  if ( v6 <= 0 )
    LOWORD(v6) = 0;
  if ( !word_199A08 || word_199A08 == 39 || word_199A08 == 12 )
  {
    v7 = (int16_t)v6;
    sub_A1BC9(v6, &byte_192E80[(int16_t)v6], &byte_192ECC[(int16_t)v6]);
    v8 = a3 + (uint8_t)byte_192E80[v7] / 2;
    v9 = a4 + (uint8_t)byte_192ECC[v7] / 2;
  }
  else
  {
    LOWORD(v8) = a3 + 4;
    LOWORD(v9) = a4 + 4;
  }
  return sub_A11C0(v8, v9, a1, a2, a5, word_19995E);
}
// 19995E: using guessed type int16_t word_19995E;
// 199A08: using guessed type int16_t word_199A08;


//----- (000A1341) --------------------------------------------------------
char __fastcall sub_A1341( int a1)
{
  int v1; // ebx
  char v2; // cl
  int v3; // eax
  int16_t v4; // bx

  v1 = *(int16_t *)((char *)&word_1975D4 + 5 * a1);
  v2 = 0;
  if ( sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * a1)) != word_19999C )
  {
    v3 = dword_197F9C + 129 * v1;
    if ( *(_BYTE *)(v3 + 100) )
    {
      v4 = sub_78E07(*(int16_t *)(v3 + 101));
      if ( sub_79D1C(word_19999C, v4) || sub_79D86(word_19999C, v4) )
        return 1;
    }
  }
  return v2;
}
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;


//----- (000A13B0) --------------------------------------------------------
int __fastcall sub_A13B0( int a1, int a2, int a3)
{
  int16_t v3; // di
  int16_t v5; // bx
  uint16_t *v6; // eax
  uint16_t v7; // dx
  char *v8; // eax
  int16_t v9; // si
  int64_t v10; // rax
  int v12; // [esp-4h] [ebp-68h]
  _BYTE v13[80]; // [esp+0h] [ebp-64h] BYREF
  _BYTE v14[8]; // [esp+50h] [ebp-14h] BYREF
  int v15; // [esp+58h] [ebp-Ch]
  uint16_t *v16; // [esp+5Ch] [ebp-8h]
  int v17; // [esp+60h] [ebp-4h]

  v3 = a2;
  LOWORD(a2) = *(int16_t *)((char *)&word_1975D4 + 5 * a1);
  v5 = sub_77FE9(a1);
  v17 = a2;
  v6 = (uint16_t *)sub_A0D78(v5, 0);
  v7 = *v6;
  LOWORD(v6) = v6[1];
  v15 = v7;
  v16 = v6;
  sub_7A00A(v5, 0, v5);
  sub_8F625((int)v14);
  sub_120BB5(v3 <= 1, (int)v14);
  v12 = *(uint8_t *)(129 * (int16_t)v17 + dword_197F9C + 109);
  v8 = sub_7A990(0x133u);
  v9 = v15 + a3;
  v10 = sprintf(v13, v8, v12);
  return sub_1210B7(v9, SWORD2(v10), (int)v13);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;


//----- (000A1455) --------------------------------------------------------
void sub_A1455()
{
  int16_t v0; // ax
  int v1; // edx
  int16_t v2; // ax
  char v3; // dl
  int16_t v4; // ax
  int16_t v5; // di
  int16_t v6; // ax
  int16_t m; // cx
  int16_t n; // si
  int v9; // eax
  int16_t i; // cx
  char v11; // al
  int16_t j; // si
  int16_t k; // cx
  int v14; // edx
  int v15; // eax
  int16_t v16; // [esp+Ch] [ebp-8h]
  int16_t v17; // [esp+10h] [ebp-4h]

  sub_7836A(word_1999B8);
  v1 = v0;
  sub_78800(v0);
  v2 = *(int16_t *)((char *)&word_1975D4 + 5 * v1);
  v3 = 0;
  v4 = sub_77FF5(v2);
  v5 = v4;
  if ( v4 < 8 )
    v5 = *(uint8_t *)(dword_197F98 + 3753 * v4 + 38);
  v6 = sub_79917();
  v17 = v6;
  switch ( v6 )
  {
    case 3:
      v16 = 0;
      break;
    case 2:
      v16 = 1;
      break;
    case 1:
      v16 = 2;
      break;
    case 0:
      v16 = 3;
      break;
  }
  if ( v5 >= 8 )
  {
    if ( v5 == 8 )
    {
      for ( i = 0; i < 4; ++i )
      {
        if ( i == v17 )
        {
          dword_193414 = sub_127C27((int)aBuffer0Lbx_3, i + 237, dword_193174);
          dword_1906B0[i] = dword_193414;
        }
      }
    }
    else
    {
      v11 = 0;
      for ( j = 0; j < 6 && !v11; ++j )
      {
        for ( k = 0; k < 4 && !v11; ++k )
        {
          v14 = v5 - 9;
          if ( v14 == j && k == v17 )
          {
            v15 = sub_127C27((int)aBuffer0Lbx_3, 4 * v14 + 241 + k, dword_193174);
            dword_190518[4 * j + k] = v15;
            dword_193414 = v15;
            v11 = 1;
          }
        }
      }
    }
  }
  else
  {
    for ( m = 0; m < 8 && !v3; ++m )
    {
      for ( n = 0; n < 4 && !v3; ++n )
      {
        if ( m == v5 && n == v16 )
        {
          v9 = sub_127C27((int)aBuffer0Lbx_3, n + 4 * v5 + 205, dword_193174);
          dword_1905F8[4 * v5 + n] = v9;
          v3 = 1;
          dword_193414 = v9;
        }
      }
    }
  }
  JUMPOUT(0xA0708);
}
// A1565: control flows out of bounds to A0708
// A146A: variable 'v0' is possibly undefined
// A14FD: variable 'v16' is possibly undefined
// 190518: using guessed type int dword_190518[32];
// 1905F8: using guessed type int dword_1905F8[32];
// 1906B0: using guessed type int dword_1906B0[];
// 193174: using guessed type int dword_193174;
// 193414: using guessed type int dword_193414;
// 1975D4: using guessed type int16_t word_1975D4;
// 197F98: using guessed type int dword_197F98;
// 1999B8: using guessed type int16_t word_1999B8;


//----- (000A163A) --------------------------------------------------------
void __usercall sub_A163A( int a1, int a2)
{
  char v3; // cl
  int16_t i; // dx
  int v5; // eax
  int v6; // eax
  int v7; // esi

  sub_77FF5(a1);
  v3 = 0;
  for ( i = 0; i < 67 && !v3; ++i )
  {
    v5 = 59 * i + dword_1930DC;
    if ( !*(_BYTE *)(v5 + 35) && a1 == *(_WORD *)(v5 + 53) && *(char *)(v5 + 55) > 0 )
    {
      v3 = 1;
      sub_944A3(i, a2);
    }
  }
  v6 = 129 * a1;
  v7 = dword_197F9C;
  *(_WORD *)(dword_197F9C + v6 + 101) = -1;
  *(_BYTE *)(v7 + v6 + 100) = 5;
  JUMPOUT(0xA0807);
}
// A16A2: control flows out of bounds to A0807
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;


//----- (000A16BF) --------------------------------------------------------
int __fastcall sub_A16BF( int a1, int a2, unsigned int a3)
{
  int16_t v5; // dx
  int16_t v6; // si
  int v7; // eax
  int v8; // ecx
  int result; // eax
  _BYTE v10[100]; // [esp+0h] [ebp-64h] BYREF

  switch ( a1 )
  {
    case 9:
      sub_57F2C((int)v10);
      goto LABEL_8;
    case 10:
      sub_57C0B((int)v10, a3);
      goto LABEL_8;
    case 11:
      sub_57E1B((int)v10, a3);
      goto LABEL_8;
    case 12:
      sub_57A02((int)v10, a3);
      goto LABEL_8;
    case 13:
      sub_57D14((int)v10, a3);
      goto LABEL_8;
    case 14:
      sub_57B1C((int)v10, a3);
LABEL_8:
      v5 = a1;
      v6 = a2;
      v7 = sub_A1762(a2, v5, v10, a3);
      v8 = v7;
      if ( (int16_t)v7 > -1 )
        sub_A1A23(v6, v7, a3);
      result = v8;
      break;
    default:
      result = -1;
      break;
  }
  return result;
}


//----- (000A1762) --------------------------------------------------------
int __fastcall sub_A1762( int a1, int a2, void *a3, int a4)
{
  int16_t v5; // si
  int v6; // ebx
  int v7; // ecx
  int16_t v8; // ax
  int16_t v9; // cx
  int16_t v10; // bx
  int16_t v11; // di
  int16_t v12; // bx
  int v13; // esi
  int16_t v14; // ax
  int16_t v15; // ax
  int v18; // [esp+Ch] [ebp-3Ch]
  int v19; // [esp+20h] [ebp-28h]
  int v20; // [esp+28h] [ebp-20h]
  int16_t v21; // [esp+30h] [ebp-18h]
  unsigned int v22; // [esp+34h] [ebp-14h]
  int v23; // [esp+38h] [ebp-10h]
  _BOOL1 v25; // [esp+40h] [ebp-8h]
  _BOOL1 v26; // [esp+44h] [ebp-4h]

  v23 = sub_7926C(30);
  v22 = sub_1247A0(5u) + 1;
  v18 = 113 * a1;
  v21 = sub_7926C(*(_WORD *)(v18 + dword_19306C + 15));
  v5 = sub_7926C(*(_WORD *)(v18 + dword_19306C + 17));
  v6 = 0;
  v7 = 0;
  v8 = v22 * v23 + 10;
  if ( !a4 )
  {
    v9 = *(_WORD *)(v18 + dword_19306C + 15);
    v10 = *(_WORD *)(v18 + dword_19306C + 17);
    return sub_100010(a2, a3, v9, v10);
  }
  v25 = v8 + v5 < 420;
  v26 = v5 - v8 > 21;
  if ( v8 + v21 < 526 && v21 - v8 > 21 )
  {
    if ( sub_1247A0(2u) != 1 )
    {
LABEL_6:
      v6 = 1;
      goto LABEL_12;
    }
    goto LABEL_11;
  }
  if ( v8 + v21 < 526 && v21 - v8 <= 21 )
    goto LABEL_6;
  if ( v21 - v8 > 21 && v8 + v21 >= 526 )
LABEL_11:
    v6 = -1;
LABEL_12:
  if ( v25 && v26 )
  {
    if ( sub_1247A0(2u) != 1 )
    {
LABEL_15:
      v7 = 1;
      goto LABEL_21;
    }
  }
  else
  {
    if ( v25 && !v26 )
      goto LABEL_15;
    if ( !v26 || v25 )
      goto LABEL_21;
  }
  v7 = -1;
LABEL_21:
  v20 = v6 * v23;
  v11 = 1;
  v19 = v7 * v23;
  while ( v11 < (int16_t)v22 )
  {
    ++v11;
    v20 += v6 * sub_1247A0((int16_t)v23);
    v19 += v7 * sub_1247A0((int16_t)v23);
  }
  v12 = v5 + v19;
  v13 = (int16_t)(v20 + v21);
  if ( v13 >= word_19996E / 2 + 22 && v13 > (int16_t)sub_7926C(word_199A0C) - word_19996E / 2 )
    sub_7926C(word_199A0C);
  if ( v12 >= word_199954 / 2 + 22 && v12 > (int16_t)sub_7926C(word_199A0A) - word_199954 )
    sub_7926C(word_199A0A);
  sub_7927F();
  v9 = v14;
  sub_7927F();
  v10 = v15;
  return sub_100010(a2, a3, v9, v10);
}
// A19FD: variable 'v14' is possibly undefined
// A1A07: variable 'v15' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 199954: using guessed type int16_t word_199954;
// 19996E: using guessed type int16_t word_19996E;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;


//----- (000A1A23) --------------------------------------------------------
void __fastcall sub_A1A23( int a1, int a2, int a3)
{
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // edx
  _BYTE v9[16]; // [esp+0h] [ebp-14h] BYREF
  int16_t v10[2]; // [esp+10h] [ebp-4h] BYREF

  v10[1] = -1;
  v10[0] = a2;
  if ( a3 )
  {
    v5 = a1;
    sub_FF799(v10, a1, v9);
    if ( v9[5] )
    {
      sub_FFD08(v10, v5, v9);
    }
    else
    {
      _wcpp_1_unwind_leave(
        0,
        1,
        "Monster (ship id: %d) cannot move to %s (%d)!",
        a2,
        (char *)(113 * v5 + dword_19306C),
        v5);
      sub_6497C();
    }
    v6 = dword_197F9C + 129 * a2;
    *(_BYTE *)(v6 + 100) = 1;
    *(_WORD *)(v6 + 101) = a1 + 500;
  }
  else
  {
    v7 = 129 * a2;
    v8 = dword_197F9C;
    *(_BYTE *)(dword_197F9C + v7 + 100) = 0;
    *(_WORD *)(v8 + v7 + 101) = a1;
  }
  sub_EBE79(
    *(_WORD *)(dword_19306C + 113 * a1 + 15),
    *(_WORD *)(dword_19306C + 113 * a1 + 17),
    *(_WORD *)(129 * a2 + dword_197F9C + 103),
    *(_WORD *)(129 * a2 + dword_197F9C + 105));
}
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;


//----- (000A1AFA) --------------------------------------------------------
int sub_A1AFA()
{
  int v0; // ecx
  int16_t i; // dx
  int v2; // eax
  int16_t v4[500]; // [esp+0h] [ebp-3F8h] BYREF
  _BYTE v5[16]; // [esp+3E8h] [ebp-10h] BYREF

  memset(v4, -1, sizeof(v4));
  v0 = 0;
  for ( i = word_192248[word_1999B8]; i != -1; i = *(int16_t *)((char *)&word_1975D6 + 5 * i) )
  {
    if ( byte_1975D8[5 * i] )
    {
      v2 = (int16_t)v0++;
      v4[v2] = *(int16_t *)((char *)&word_1975D4 + 5 * i);
    }
  }
  sub_FF799(v4, word_19999A, v5);
  sub_FFD08(v4, word_19999A, v5);
  return v0;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 19999A: using guessed type int16_t word_19999A;
// 1999B8: using guessed type int16_t word_1999B8;


//----- (000A1B8E) --------------------------------------------------------
int __fastcall sub_A1B8E( int a1, int a2, int a3)
{
  int16_t i; // dx
  int result; // eax

  for ( i = 0; i < 500; ++i )
  {
    result = dword_197F9C + 129 * i;
    if ( a1 == *(_WORD *)(result + 103) && a2 == *(_WORD *)(result + 105) && *(_BYTE *)(result + 100) == 10 )
      *(_BYTE *)(result + 100) = a3;
  }
  return result;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (000A1BC9) --------------------------------------------------------
char __fastcall sub_A1BC9( int a1, _BYTE *a2, _BYTE *a3)
{
  _BYTE *v3; // eax
  char result; // al

  v3 = (_BYTE *)sub_127C27((int)aBuffer0Lbx_3, a1 + 205, dword_193174);
  *a2 = *v3;
  result = v3[2];
  *a3 = result;
  return result;
}
// 193174: using guessed type int dword_193174;


//----- (000A1BF4) --------------------------------------------------------
int __fastcall sub_A1BF4(int result)
{
  if ( *(_BYTE *)(result + 17) == 1 || *(_BYTE *)(result + 17) == 4 )
  {
    *(_WORD *)(result + 28) = -1;
    *(_WORD *)(result + 36) = 0;
  }
  return result;
}


//----- (000A1C0D) --------------------------------------------------------
int __fastcall sub_A1C0D(int a1)
{
  int16_t i; // bx
  int result; // eax
  int v4; // eax

  for ( i = 0; ; ++i )
  {
    result = *(int16_t *)(a1 + 2 * i);
    if ( result == -1 )
      break;
    v4 = 129 * result + dword_197F9C;
    if ( *(_BYTE *)(v4 + 17) == 1 || *(_BYTE *)(v4 + 17) == 4 )
    {
      *(_WORD *)(v4 + 28) = -1;
      *(_WORD *)(v4 + 36) = 0;
    }
  }
  return result;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (000A1C74) --------------------------------------------------------
unsigned int __fastcall sub_A1C74(
        unsigned int result, int a2, int a3, int a4, int a5, int a6, int a7,
        _WORD *a8,
        _WORD *a9,
        _WORD *a10)
{
  int16_t i; // si
  int16_t v11; // dx
  int v12; // eax
  int16_t v13; // di
  int16_t v14; // bx
  int v15; // kr00_4
  int v16; // edx
  int16_t j; // di
  int16_t v18; // cx
  int16_t v19; // dx
  _WORD *v20; // eax
  int16_t v21; // dx
  int16_t v22; // bx
  int v23; // eax
  int v24; // esi
  int16_t v25; // si
  int16_t v26; // di
  int16_t v27; // dx
  int16_t v28; // di
  int16_t v29; // si
  int16_t v30; // cx
  int16_t v31; // dx
  int16_t v32; // ax
  int64_t v33; // [esp-Ch] [ebp-2Ch]
  int16_t v37; // [esp+Ch] [ebp-14h]
  int v38; // [esp+10h] [ebp-10h] BYREF
  int v39; // [esp+14h] [ebp-Ch] BYREF
  int v40; // [esp+18h] [ebp-8h] BYREF
  int v41; // [esp+1Ch] [ebp-4h]

  v37 = result;
  result = (int16_t)result;
  if ( (int16_t)result > -1 && (int16_t)result < word_19999A && !byte_19D32F )
  {
    sub_A200E();
    if ( a9 )
    {
      *a9 = sub_11C3C5(
              a4 + a2 + 263,
              (int16_t)(a5 + a3 + 236),
              (int)&unk_179C1E,
              (int16_t *)dword_193080,
              asc_179C1C,
              40);
      *a8 = sub_11438B(a4 + a2, a5 + a3, a4 + a2 + word_192FE2[0], a5 + a3 + 47, &unk_179C1E, 0);
    }
    else
    {
      *a8 = -1000;
    }
    for ( i = 4; i > -1; --i )
    {
      v11 = *(_WORD *)(dword_193184 + 14 * i);
      if ( v11 <= -1 || (v12 = dword_1930D4 + 17 * v11, *(_BYTE *)(v12 + 4) == 1) )
      {
        word_1992D4[i] = -1000;
      }
      else
      {
        v13 = *(uint8_t *)(v12 + 5);
        if ( *(_BYTE *)(v12 + 4) == 2 )
          v13 = 4;
        sub_EBEEB(v37, *(uint8_t *)(17 * v11 + dword_1930D4 + 3), &v39, &v38, &v40);
        v14 = (uint8_t)byte_199EC2[v13];
        v15 = (uint8_t)byte_199EC2[v13];
        v41 = a3;
        v16 = a2 + a4 + a6 + 161 + v39 - v15 / 2;
        word_1992D4[i] = sub_11438B(
                           v16,
                           v38 + a5 + a3 + a7 + 90 - v15 / 2,
                           v16 + v14,
                           v14 + v38 + a5 + a3 + a7 + 90 - v15 / 2,
                           &unk_179C1E,
                           41);
      }
    }
    for ( j = 0; j < 15; ++j )
    {
      if ( word_1931C2[6 * j] > -1 )
      {
        v18 = word_1931BC[6 * j];
        v19 = word_1931BE[6 * j];
        v20 = (_WORD *)sub_A5844(j);
        dword_1931C4[3 * j] = (int)v20;
        v21 = a5 + a3 + v19;
        v22 = v21 + v20[1];
        LOWORD(v20) = *v20;
        v41 = v22;
        word_1931C0[6 * j] = sub_11438B(a4 + a2 + v18, v21, a4 + a2 + v18 + (_WORD)v20, v22, &unk_179C1E, 41);
      }
    }
    v23 = 0;
    do
    {
      v24 = (int16_t)v23++;
      word_190490[v24] = -1000;
    }
    while ( (int16_t)v23 < 4 );
    v25 = a4 + a2 + 233;
    v26 = a5 + a3 + 243;
    if ( word_199A08 == 29 )
    {
      v25 = a4 + a2 + 293;
      v26 = a5 + a3 + 167;
    }
    if ( sub_79D48(113 * v37 + dword_19306C) )
    {
      v27 = v25 + 3;
      v25 -= 12;
      word_190496 = sub_11438B(v25, v26, v27, v26 + 15, &unk_179C1E, 0);
    }
    if ( sub_79D40(113 * v37 + dword_19306C) )
      word_190490[0] = sub_11438B(v25 - 12, v26, v25 + 3, v26 + 15, &unk_179C1E, 0);
    v28 = a4 + a2;
    v29 = a5 + a3;
    if ( word_199A08 == 29 )
    {
      v30 = v29 + 180;
      v31 = a5 + a3;
      v32 = v28 + 318;
    }
    else
    {
      HIDWORD(v33) = &unk_1999B0;
      LODWORD(v33) = &unk_1999AE;
      word_1999B2 = sub_114DCA(v28 + 13, v29 + 47, 1, 1, 320, 183, v33, 0);
      v30 = v29 + word_192FE0[0];
      v31 = a5 + a3;
      v32 = v28 + word_192FE2[0];
    }
    result = sub_11438B(v28, v31, v32, v30, &unk_179C1E, 0);
    *a10 = result;
  }
  return result;
}
// 190490: using guessed type int16_t word_190490[3];
// 190496: using guessed type int16_t word_190496;
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 19306C: using guessed type int dword_19306C;
// 193080: using guessed type int dword_193080;
// 1930D4: using guessed type int dword_1930D4;
// 193184: using guessed type int dword_193184;
// 1931BC: using guessed type int16_t word_1931BC[];
// 1931BE: using guessed type int16_t word_1931BE[];
// 1931C0: using guessed type int16_t word_1931C0[];
// 1931C2: using guessed type int16_t word_1931C2[];
// 1931C4: using guessed type int dword_1931C4[43];
// 1992D4: using guessed type int16_t word_1992D4[10];
// 19999A: using guessed type int16_t word_19999A;
// 1999B2: using guessed type int16_t word_1999B2;
// 199A08: using guessed type int16_t word_199A08;
// 19D32F: using guessed type char byte_19D32F;


//----- (000A200E) --------------------------------------------------------
void sub_A200E()
{
  int v0; // edi
  int16_t v1; // si
  int16_t v2; // bx
  int v3; // eax
  int16_t v4; // dx
  int v5; // eax
  int16_t v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-4h] BYREF

  v7 = 0;
  sub_A20EC();
  v0 = 0;
  v1 = 0;
  byte_199F26 = 0;
  while ( v1 < word_1999F8 )
  {
    v2 = word_1906C2[6 * v1];
    v3 = 129 * *(int16_t *)((char *)&word_1975D4 + 5 * v2) + dword_197F9C;
    if ( *(_WORD *)(v3 + 101) == v6 && *(char *)(v3 + 100) < 3 )
    {
      v4 = *(char *)(v3 + 99);
      word_1931C2[6 * *(char *)(v3 + 99)] = v2;
      if ( v4 == word_19999C )
        byte_199F26 = 1;
      v5 = (int16_t)v0++;
      sub_A3E3D(v5, v4, &word_1931BC[6 * v4], &word_1931BC[6 * v4 + 1], &v7);
    }
    ++v1;
  }
}
// A2071: variable 'v6' is possibly undefined
// 1906C2: using guessed type int16_t word_1906C2[];
// 1931BC: using guessed type int16_t word_1931BC[];
// 1931C2: using guessed type int16_t word_1931C2[];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F9C: using guessed type int dword_197F9C;
// 19999C: using guessed type int16_t word_19999C;
// 1999F8: using guessed type int16_t word_1999F8;
// 199F26: using guessed type char byte_199F26;


//----- (000A20CD) --------------------------------------------------------
int sub_A20CD()
{
  int result; // eax

  if ( dword_193274 )
    return memset(dword_193274, 0, 20);
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 193274: using guessed type int dword_193274;


//----- (000A20EC) --------------------------------------------------------
int sub_A20EC()
{
  int v0; // edx
  int result; // eax

  memset(&word_1931BC, 0, 180);
  v0 = 0;
  do
  {
    result = 6 * (int16_t)v0;
    word_1931C0[result] = -1000;
    ++v0;
    word_1931C2[result] = -1;
  }
  while ( (int16_t)v0 < 15 );
  return result * 2;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1931BC: using guessed type int16_t word_1931BC;
// 1931C0: using guessed type int16_t word_1931C0[];
// 1931C2: using guessed type int16_t word_1931C2[];


//----- (000A2123) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge sub_A2123(
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
        __int128 a14,
        int64_t a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        __int128 a24,
        int a25)
{
  _BOOL1 v25; // al
  int16_t v26; // cx
  int16_t v27; // bx
  int16_t v28; // dx
  int16_t v29; // ax
  char *v30; // ebx
  int16_t *v31; // edx
  int16_t v32; // ax
  char v33; // al
  char *v34; // eax
  int64_t v35; // rax
  char *v36; // edi
  char *v37; // esi
  char *v38; // edi
  int16_t *v39; // edx
  int16_t v40; // ax
  int64_t v41; // rax
  int16_t *v42; // edx
  int16_t v43; // ax
  int16_t v44; // ax
  char *v45; // eax
  int64_t v46; // rax
  char *v47; // eax
  int v48; // eax
  int16_t *v49; // edx
  int v50; // eax
  int16_t *v51; // edx
  int16_t v52; // ax
  int v53; // eax
  int v54; // eax
  int result; // eax
  int v56; // [esp-18h] [ebp-D0h]
  int v57; // [esp-14h] [ebp-CCh]
  int v58; // [esp+5Ah] [ebp-5Eh]
  int v59; // [esp+5Eh] [ebp-5Ah]
  int v60; // [esp+62h] [ebp-56h]
  int v61; // [esp+66h] [ebp-52h]
  char var4E[79]; // [esp+6Ah] [ebp-4Eh] BYREF
  char _B9; // [esp+B9h] [ebp+1h] BYREF
  char vars2[10]; // [esp+BAh] [ebp+2h] BYREF

  *(_DWORD *)((char *)&a14 + 6) = 2;
  *(_DWORD *)((char *)&a14 + 2) = 1;
  *(_DWORD *)((char *)&a15 + 2) = 0;
  if ( byte_199F26
    || sub_79D1C(word_19999C, *(uint8_t *)(17 * SHIWORD(a23) + dword_1930D4 + 2))
    || (v25 = sub_79E06(word_19999C)) )
  {
    v25 = 1;
  }
  BYTE2(a18) = v25;
  **(_WORD **)((char *)&a24 + 10) = 0;
  **(_WORD **)((char *)&a24 + 14) = 12;
  dword_193070 = sub_127C27((int)aBuffer0Lbx_4, 73, dword_193174);
  qmemcpy((char *)&a12 + 2, sub_8E5C5(WORD3(a14), 60, 67), 8u);
  v26 = *(_WORD *)(dword_1930D4 + 17 * SHIWORD(a23));
  if ( v26 <= -1 )
    v27 = -1;
  else
    v27 = *(char *)(361 * v26 + dword_192B18);
  sub_120BB5(SWORD3(a14), (int)&a12 + 2);
  sub_120E8C(SWORD1(a14));
  BYTE2(a17) = sub_122259() + 1;
  *(_DWORD *)((char *)&a14 + 14) = *(_DWORD *)((char *)&a24 + 2) + v59 + v61 + 6;
  *(_DWORD *)((char *)&a14 + 10) = *(_DWORD *)((char *)&a24 + 6) + v58 + v60 + 7;
  BYTE2(a16) = *(_BYTE *)(dword_1930D4 + 17 * SHIWORD(a23) + 4) == 2;
  if ( BYTE2(a16) )
  {
    strcpy(vars2, sub_7A990(0x15Fu));
    if ( BYTE2(a25) )
    {
LABEL_10:
      v28 = WORD5(a14);
      v29 = HIWORD(a14);
      v30 = vars2;
LABEL_11:
      sub_1212B3(v29, v28, (int)v30);
      goto LABEL_62;
    }
    goto LABEL_12;
  }
  if ( *(_BYTE *)(dword_1930D4 + 17 * SHIWORD(a23) + 4) == 1 )
  {
    strcpy(vars2, sub_7A990(0x160u));
    if ( BYTE2(a25) )
      goto LABEL_10;
LABEL_12:
    v31 = *(int16_t **)((char *)&a24 + 10);
    v32 = sub_12066F((int)vars2);
    if ( v32 <= *v31 )
      goto LABEL_62;
    goto LABEL_61;
  }
  if ( v26 <= -1 )
    v33 = *(_BYTE *)(17 * SHIWORD(a23) + dword_1930D4 + 8);
  else
    v33 = *(_BYTE *)(361 * v26 + dword_192B18 + 226);
  BYTE6(a15) = v33;
  sub_77B42();
  if ( (int)((uint64_t)sprintf(vars2, "%s ", v34) >> 32) > -1 )
  {
    v35 = sprintf(var4E, "(%s", (char *)(dword_197F98 + 3753 * v27 + 21));
    v36 = &_B9;
    do
      ++v36;
    while ( *v36 );
    strcpy(v36, var4E);
    if ( *(_BYTE *)(HIDWORD(v35) + dword_192B18 + 6) )
      v37 = sub_7A990(0x161u);
    else
      v37 = asc_179C33;
    v38 = &_B9;
    do
      ++v38;
    while ( *v38 );
    strcpy(v38, v37);
  }
  if ( BYTE2(a25) )
  {
    sub_1212B3(SHIWORD(a14), SWORD5(a14), (int)vars2);
    sub_120BB5(SWORD3(a14), (int)&a12 + 2);
    sub_120E8C(SWORD1(a14));
  }
  else
  {
    v39 = *(int16_t **)((char *)&a24 + 10);
    v40 = sub_12066F((int)vars2);
    if ( v40 > *v39 )
      *v39 = v40;
  }
  v41 = sprintf(
          var4E,
          "%s, %s",
          (char *)dword_192BE0[*(uint8_t *)(dword_1930D4 + 17 * SHIWORD(a23) + 5)],
          (char *)dword_18F990[BYTE6(a15)]);
  if ( BYTE2(a25) )
  {
    LOWORD(v41) = BYTE2(a17);
    *(_DWORD *)((char *)&a14 + 10) += v41;
    sub_1212B3(SHIWORD(a14), SWORD5(a14), (int)var4E);
  }
  else
  {
    **(_WORD **)((char *)&a24 + 14) += BYTE2(a17);
    v42 = *(int16_t **)((char *)&a24 + 10);
    v43 = sub_12066F((int)var4E);
    if ( v43 > *v42 )
      *v42 = v43;
  }
  sub_E0B4F((int16_t *)(17 * SHIWORD(a23) + dword_1930D4), word_19999C);
  v57 = v44;
  if ( v26 <= -1 )
  {
    v47 = sub_7A990(0x162u);
    v46 = sprintf(var4E, v47, v57);
  }
  else
  {
    v56 = *(uint8_t *)(dword_192B18 + 361 * v26 + 10);
    v45 = sub_7A990(0x181u);
    v46 = sprintf(var4E, v45, v56, v57);
  }
  if ( BYTE2(a25) )
  {
    LOWORD(v46) = BYTE2(a17);
    *(_DWORD *)((char *)&a14 + 10) += v46;
    v48 = sub_1212B3(SHIWORD(a14), SWORD5(a14), (int)var4E);
  }
  else
  {
    **(_WORD **)((char *)&a24 + 14) += BYTE2(a17);
    v49 = *(int16_t **)((char *)&a24 + 10);
    v48 = sub_12066F((int)var4E);
    if ( (int16_t)v48 > *v49 )
      *v49 = v48;
  }
  LOWORD(v48) = BYTE2(a17);
  *(_DWORD *)((char *)&a14 + 10) += v48;
  **(_WORD **)((char *)&a24 + 14) += BYTE2(a17);
  v50 = dword_1930D4 + 17 * SHIWORD(a23);
  if ( *(_BYTE *)(v50 + 6) == 1 )
    sprintf(var4E, "%s", (char *)dword_192BF4[*(uint8_t *)(v50 + 10)]);
  else
    sprintf(
      var4E,
      "%s, %s",
      (char *)dword_192BF4[*(uint8_t *)(v50 + 10)],
      (char *)dword_192C74[*(uint8_t *)(v50 + 6)]);
  if ( BYTE2(a25) )
  {
    sub_1212B3(SHIWORD(a14), SWORD5(a14), (int)var4E);
  }
  else
  {
    v51 = *(int16_t **)((char *)&a24 + 10);
    v52 = sub_12066F((int)var4E);
    if ( v52 > *v51 )
      *v51 = v52;
  }
  if ( v26 > -1 && BYTE2(a18) )
  {
    sub_A58CE(
      v26,
      SHIWORD(a14),
      (int16_t *)&a14 + 5,
      *(int16_t **)((char *)&a24 + 10),
      *(_WORD **)((char *)&a24 + 14),
      BYTE2(a17),
      SBYTE2(a25));
    *(_DWORD *)((char *)&a15 + 2) = v53;
  }
  v54 = 17 * SHIWORD(a23) + dword_1930D4;
  if ( *(_BYTE *)(v54 + 15) && *(_BYTE *)(v54 + 15) != 11 )
  {
    if ( !WORD1(a15) )
    {
      HIWORD(v54) = a25;
      *(_DWORD *)((char *)&a14 + 10) += 4;
      **(_WORD **)((char *)&a24 + 14) += 4;
    }
    LOWORD(v54) = BYTE2(a17);
    *(_DWORD *)((char *)&a14 + 10) += v54;
    **(_WORD **)((char *)&a24 + 14) += BYTE2(a17);
    if ( BYTE2(a25) )
    {
      v28 = WORD5(a14);
      v30 = (char *)dword_18F9B8[*(char *)(17 * SHIWORD(a23) + dword_1930D4 + 15)];
      v29 = HIWORD(a14);
      goto LABEL_11;
    }
    v31 = *(int16_t **)((char *)&a24 + 10);
    v32 = sub_12066F(dword_18F9B8[*(char *)(17 * SHIWORD(a23) + dword_1930D4 + 15)]);
    if ( v32 <= *v31 )
      goto LABEL_62;
LABEL_61:
    *v31 = v32;
  }
LABEL_62:
  result = *(_DWORD *)((char *)&a24 + 14);
  **(_WORD **)((char *)&a24 + 14) += 2;
  return result;
}
// A2240: inconsistent variable size for '^11C.16'
// A2627: inconsistent variable size for '^154.16'
// A21A3: inconsistent variable size for '^154.16'
// A2477: inconsistent variable size for '^154.16'
// A2540: inconsistent variable size for '^154.16'
// A2567: inconsistent variable size for '^154.16'
// A2662: inconsistent variable size for '^154.16'
// A2674: inconsistent variable size for '^154.16'
// A26D0: inconsistent variable size for '^154.16'
// A26D6: inconsistent variable size for '^154.16'
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 18F990: using guessed type int dword_18F990[];
// 18F9B8: using guessed type int dword_18F9B8[];
// 192B18: using guessed type int dword_192B18;
// 192BE0: using guessed type int dword_192BE0[];
// 192BF4: using guessed type int dword_192BF4[];
// 192C74: using guessed type int dword_192C74[];
// 193070: using guessed type int dword_193070;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199F26: using guessed type char byte_199F26;


//----- (000A26E3) --------------------------------------------------------
int16_t __fastcall sub_A26E3(int a1, int a2, int a3, int a4, int a5, int16_t *a6, int16_t *a7, int a8)
{
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // edx
  int16_t result; // ax
  int16_t v14; // ax
  int v15; // ebx
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // eax
  int16_t v20; // si
  int16_t i; // ax
  char *v22; // eax
  int64_t v23; // rax
  int16_t v24; // ax
  int16_t v25; // cx
  int16_t v26; // di
  char *v27; // eax
  int64_t v28; // rax
  int16_t v29; // ax
  int16_t v30; // ax
  char *v31; // eax
  int64_t v32; // rax
  char *v33; // eax
  int16_t v34; // ax
  int16_t v35; // ax
  uint16_t v36; // ax
  char *v37; // eax
  int64_t v38; // rax
  int16_t v39; // ax
  int16_t v40; // ax
  uint16_t v41; // ax
  char *v42; // eax
  int64_t v43; // rax
  int16_t v44; // ax
  int16_t v45; // ax
  int v46; // [esp-4h] [ebp-F2h]
  int v47; // [esp-4h] [ebp-F2h]
  int v48; // [esp-4h] [ebp-F2h]
  _BYTE v49[200]; // [esp+0h] [ebp-EEh] BYREF
  _BYTE v50[80]; // [esp+C8h] [ebp-26h] BYREF
  _WORD v51[6]; // [esp+118h] [ebp+2Ah] BYREF
  _BYTE v52[8]; // [esp+124h] [ebp+36h] BYREF
  int v53; // [esp+12Ch] [ebp+3Eh]
  int16_t v54; // [esp+130h] [ebp+42h] BYREF
  int16_t v55; // [esp+134h] [ebp+46h] BYREF
  int16_t v56; // [esp+138h] [ebp+4Ah] BYREF
  int v57; // [esp+13Ch] [ebp+4Eh]
  int v58; // [esp+140h] [ebp+52h]
  int16_t v59; // [esp+144h] [ebp+56h] BYREF
  int v60; // [esp+148h] [ebp+5Ah]
  int v61; // [esp+14Ch] [ebp+5Eh]
  int v62; // [esp+150h] [ebp+62h]
  int v63; // [esp+154h] [ebp+66h]
  int v64; // [esp+158h] [ebp+6Ah]
  uint8_t v65; // [esp+15Ch] [ebp+6Eh]

  v61 = 2;
  v50[0] = 0;
  v63 = 1;
  *a6 = 0;
  v8 = a4 + a2;
  v9 = a3 + a1;
  *a7 = 4;
  if ( word_199A08 == 29 )
  {
    v10 = v9 + 8;
    v11 = v8 + 10;
  }
  else
  {
    v10 = v9 + 18;
    v11 = v8 + 54;
  }
  v60 = v10;
  v62 = v11;
  if ( a5 < 5000 )
  {
    v12 = *(int16_t *)((char *)&word_1975D4 + 5 * a5);
    if ( sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * a5)) >= 8 )
      sprintf(v50, (char *)(129 * v12 + dword_197F9C));
  }
  else
  {
    sprintf(v50, (char *)(dword_197F9C + 129 * *(int16_t *)((char *)&word_1975D4 + 5 * (int16_t)(a5 - 5000))));
  }
  if ( v50[0] )
  {
    qmemcpy(v52, sub_8E5C5(1u, 110, 115), sizeof(v52));
    sub_120BB5((int16_t)v61, (int)v52);
    sub_120E8C(v63);
    sub_122259();
    if ( a8 )
    {
      return sub_1212B3(v60, v62, (int)v50);
    }
    else
    {
      v14 = sub_12066F((int)v50);
      if ( v14 > *a6 )
        *a6 = v14;
      result = sub_122259();
      *a7 = result;
    }
  }
  else
  {
    dword_193070 = sub_127C27((int)aBuffer0Lbx_4, 73, dword_193174);
    v15 = 129 * *(int16_t *)((char *)&word_1975D4 + 5 * a5);
    LOWORD(v16) = sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * a5));
    v64 = v16;
    v53 = (int16_t)v16;
    v17 = 3753 * (int16_t)v16 + dword_197F98;
    v18 = v15 + dword_197F9C;
    LOWORD(v15) = *(_WORD *)(v15 + dword_197F9C + 103);
    LOWORD(v18) = *(_WORD *)(v18 + 105);
    v57 = v18;
    v19 = *(uint8_t *)(v17 + 38);
    LOWORD(v17) = (uint8_t)byte_10010[v19];
    v58 = v15;
    qmemcpy(v52, sub_8E5C5(1u, (uint8_t)byte_10010[v19], v17 + 5), sizeof(v52));
    sub_120BB5((int16_t)v61, (int)v52);
    sub_120E8C(v63);
    v65 = sub_122259() + 1;
    sub_A432F(v58, v57, v53, &v56, &v55, &v54, &v59, (int)v51);
    v20 = (v55 > 0) + (v54 > 0) + (v59 > 0);
    for ( i = 0; i < 6; ++i )
    {
      if ( (int16_t)v51[i] > 0 )
        ++v20;
    }
    v46 = dword_197F98 + 3753 * (int16_t)v64 + 21;
    v22 = sub_7A990(0x163u);
    v23 = sprintf(v49, v22, v46);
    sub_120BB5((int16_t)v61, SHIDWORD(v23));
    sub_120E8C(v63);
    if ( a8 )
    {
      sub_1212B3(v60, v62, (int)v49);
    }
    else
    {
      v24 = sub_12066F((int)v49);
      if ( v24 > *a6 )
        *a6 = v24;
    }
    v25 = 0;
    v26 = v61 + v60 + 1;
    do
    {
      if ( (int16_t)v51[v25] > 0 )
      {
        if ( v51[v25] == 1 )
          v27 = (char *)*(&off_18003A + 9 * v25);
        else
          v27 = (char *)*(&off_18003E + 9 * v25);
        v28 = sprintf(v49, "%2d %s", (int16_t)v51[v25], v27);
        LOWORD(v28) = v65;
        v62 += v28;
        if ( a8 )
        {
          sub_1212B3(v26, v62, (int)v49);
        }
        else
        {
          v29 = sub_12066F((int)v49);
          v30 = v61 + v29 + 1;
          if ( v30 > *a6 )
            *a6 = v30;
        }
      }
      ++v25;
    }
    while ( v25 < 6 );
    if ( v55 > 0 )
    {
      if ( v55 == 1 )
      {
        v31 = sub_7A990(0x164u);
        v32 = sprintf(v49, v31, 1);
      }
      else
      {
        v33 = sub_7A990(0x165u);
        v32 = sprintf(v49, v33);
      }
      LOWORD(v32) = v65;
      v62 += v32;
      if ( a8 )
      {
        sub_1212B3(v61 + v60 + 1, v62, (int)v49);
      }
      else
      {
        v34 = sub_12066F((int)v49);
        v35 = v61 + v34 + 1;
        if ( v35 > *a6 )
          *a6 = v35;
      }
    }
    if ( v54 > 0 )
    {
      if ( v54 == 1 )
      {
        v47 = 1;
        v36 = 358;
      }
      else
      {
        v47 = v54;
        v36 = 359;
      }
      v37 = sub_7A990(v36);
      v38 = sprintf(v49, v37, v47);
      LOWORD(v38) = v65;
      v62 += v38;
      if ( a8 )
      {
        sub_1212B3(v61 + v60 + 1, v62, (int)v49);
      }
      else
      {
        v39 = sub_12066F((int)v49);
        v40 = v61 + v39 + 1;
        if ( v40 > *a6 )
          *a6 = v40;
      }
    }
    if ( v59 > 0 )
    {
      if ( v59 == 1 )
      {
        v48 = 1;
        v41 = 360;
      }
      else
      {
        v48 = v59;
        v41 = 361;
      }
      v42 = sub_7A990(v41);
      v43 = sprintf(v49, v42, v48);
      LOWORD(v43) = v65;
      v62 += v43;
      if ( a8 )
      {
        sub_1212B3(v61 + v60 + 1, v62, (int)v49);
      }
      else
      {
        v44 = sub_12066F((int)v49);
        v45 = v61 + v44 + 1;
        if ( v45 > *a6 )
          *a6 = v45;
      }
    }
    result = (int16_t)a7;
    *a7 = v65 * (v20 + 1);
  }
  return result;
}
// A2866: variable 'v16' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 18003A: using guessed type _UNKNOWN *off_18003A;
// 18003E: using guessed type _UNKNOWN *off_18003E;
// 193070: using guessed type int dword_193070;
// 193174: using guessed type int dword_193174;
// 1975D4: using guessed type int16_t word_1975D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199A08: using guessed type int16_t word_199A08;


//----- (000A2C11) --------------------------------------------------------
int __fastcall sub_A2C11( int a1, int a2, int a3)
{
  int v5; // edx
  int16_t v6; // di
  _WORD *v7; // ebx

  v5 = 3753 * a3;
  v6 = *(uint8_t *)(v5 + dword_197F98 + 38);
  v7 = (_WORD *)sub_127C27((int)aBuffer0Lbx_4, *(uint8_t *)(v5 + dword_197F98 + 38) + 35, dword_193174);
  dword_1904F8[v6] = (int)v7;
  return sub_12A478(a1 - *v7 + 2, a2, (int)v7);
}
// 1904F8: using guessed type int dword_1904F8[8];
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;


//----- (000A2C66) --------------------------------------------------------
char __fastcall sub_A2C66( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int16_t v7; // cx
  int16_t v8; // si
  char result; // al

  v7 = a2 + a4 + 233;
  v8 = a5 + a3 + 243;
  if ( word_199A08 == 29 )
  {
    v7 += 60;
    v8 = a5 + a3 + 167;
  }
  if ( sub_79D48(113 * a1 + dword_19306C) )
  {
    v7 -= 12;
    dword_1904D0 = sub_127C27((int)aBuffer0Lbx_4, 33, dword_193174);
    sub_12A478(v7, v8, dword_1904D0);
  }
  result = sub_79D40(113 * a1 + dword_19306C);
  if ( result )
  {
    dword_1904A0 = sub_127C27((int)aBuffer0Lbx_4, 21, dword_193174);
    return sub_12A478(v7 - 12, v8 + 1, dword_1904A0);
  }
  return result;
}
// 1904A0: using guessed type int dword_1904A0;
// 1904D0: using guessed type int dword_1904D0;
// 19306C: using guessed type int dword_19306C;
// 193174: using guessed type int dword_193174;
// 199A08: using guessed type int16_t word_199A08;


//----- (000A2D2D) --------------------------------------------------------
void __fastcall sub_A2D2D(int a1, int a2, int a3)
{
  int v3; // edx
  int16_t v4; // di

  v3 = 3753 * a3;
  v4 = *(uint8_t *)(v3 + dword_197F98 + 38);
  dword_1904D8[v4] = sub_127C27((int)aBuffer0Lbx_4, *(uint8_t *)(v3 + dword_197F98 + 38) + 43, dword_193174);
  JUMPOUT(0xA2C5D);
}
// A2D77: control flows out of bounds to A2C5D
// 1904D8: using guessed type int dword_1904D8[8];
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;


//----- (000A2D7C) --------------------------------------------------------
_DWORD *__fastcall sub_A2D7C( int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // esi
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int16_t *v13; // esi
  int16_t v14; // cx
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  int v18; // edi
  int v19; // eax
  int16_t v21; // [esp+8h] [ebp-34h]
  int16_t v22; // [esp+Ch] [ebp-30h]
  int v23; // [esp+14h] [ebp-28h]
  int16_t v24; // [esp+18h] [ebp-24h]
  int16_t v25; // [esp+1Ch] [ebp-20h]
  int16_t v26; // [esp+28h] [ebp-14h]
  int16_t v28; // [esp+34h] [ebp-8h]
  int16_t v29; // [esp+38h] [ebp-4h]

  v8 = 17 * a1;
  v9 = 14 * a2 + dword_193184;
  v28 = *(uint8_t *)(v9 + 7);
  v21 = *(_WORD *)(v9 + 2);
  HIWORD(v10) = HIWORD(dword_1930D4);
  v22 = *(_WORD *)(v9 + 4);
  v24 = *(uint8_t *)(v9 + 6);
  LOWORD(v10) = *(uint8_t *)(dword_1930D4 + v8 + 4);
  sub_1112EC(dword_192ED4, v10);
  if ( (_WORD)v10 == 3 )
    v26 = *(uint8_t *)(v8 + dword_1930D4 + 5);
  else
    v26 = 4;
  v11 = sub_12DAA4(288, 154);
  dword_19D21C = (int)sub_110D3C(dword_192ED4, v11 + 10);
  v12 = sub_12DAA4(34, 34);
  v13 = (int16_t *)sub_110D3C(dword_192ED4, v12 + 10);
  v25 = a5 + a3 + a8;
  v14 = a7 + a6 + a4;
  v15 = sub_127C27((int)aBuffer0Lbx_4, v28 + 77, dword_193174);
  v16 = dword_193174;
  dword_193194[v28] = v15;
  v17 = sub_127C27((int)aBuffer0Lbx_4, v28 + 77, v16);
  sub_12F578(dword_19D21C, v17);
  v18 = v26;
  dword_1933F8[v18] = sub_127C27((int)aBuffer0Lbx_4, v26 + 143, dword_193174);
  sub_12B753(dword_1933F8[v18], v24);
  v23 = 14 * a2;
  v29 = v22 + v14 + 90 - 2;
  sub_A3D84((int *)(v23 + dword_193184 + 10), *(_WORD *)(v23 + dword_193184));
  sub_133C9C(*(_DWORD *)(v23 + dword_193184 + 10), 35);
  sub_12D8F5(35, 35, (int)v13);
  sub_12F7E6(2, 2, *(int16_t **)(v23 + dword_193184 + 10), v13);
  sub_12E64F(v13, v13, 31, 0);
  sub_12E64F(v13, v13, 30, 0);
  sub_12EFBD((int16_t)(v21 + 141), (int16_t)(v22 + 74), (_WORD *)dword_19D21C, (int *)v13, 0);
  sub_12A478(v25 + 16, v14 + 12, dword_19D21C);
  v19 = sub_127C27((int)aBuffer0Lbx_4, v26 + 143, dword_193174);
  dword_1933F8[v18] = v19;
  sub_12B753(v19, v24);
  sub_A3D84((int *)(v23 + dword_193184 + 10), *(_WORD *)(v23 + dword_193184));
  sub_12B753(*(_DWORD *)(v23 + dword_193184 + 10), word_19987A % *(int16_t *)(*(_DWORD *)(v23 + dword_193184 + 10) + 6));
  sub_A512E(v21 + v25 + 161 - 2, v29, *(int16_t **)(v23 + dword_193184 + 10), dword_1933F8[v18]);
  return sub_1113CC(dword_192ED4, v29);
}
// 192ED4: using guessed type int dword_192ED4;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 193184: using guessed type int dword_193184;
// 193194: using guessed type int dword_193194[6];
// 1933F8: using guessed type int dword_1933F8[];
// 19987A: using guessed type int16_t word_19987A;
// 19D21C: using guessed type int dword_19D21C;


//----- (000A3025) --------------------------------------------------------
int __fastcall sub_A3025( int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  _WORD *v9; // ebx
  int16_t v10; // dx
  int16_t v11; // ax

  v9 = (_WORD *)sub_127C27((int)aBuffer0Lbx_4, *(uint8_t *)(dword_19306C + 113 * a1 + 22) + 83, dword_193174);
  dword_19D218 = (int)v9;
  if ( word_199A08 == 29 )
  {
    v10 = 92;
    v11 = 448;
  }
  else
  {
    v10 = a5 + a3 + (int16_t)(word_192FE0[0] - *v9) / 2;
    v11 = a2 + a4 + (int16_t)(word_192FE2[0] - v9[1]) / 2;
  }
  return sub_12A478(v11, v10, (int)v9);
}
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 19306C: using guessed type int dword_19306C;
// 193174: using guessed type int dword_193174;
// 199A08: using guessed type int16_t word_199A08;
// 19D218: using guessed type int dword_19D218;


//----- (000A30C5) --------------------------------------------------------
void __stdcall sub_A30C5(int a1, int a2, int a3)
{
  dword_193070 = sub_127C27((int)aBuffer0Lbx_4, 73, dword_193174);
  JUMPOUT(0xA30BA);
}
// A30FB: control flows out of bounds to A30BA
// 193070: using guessed type int dword_193070;
// 193174: using guessed type int dword_193174;


//----- (000A30FD) --------------------------------------------------------
void __fastcall sub_A30FD( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int16_t v7; // si
  int16_t *v8; // eax
  int16_t v9; // dx
  int16_t v10; // cx
  int16_t v11; // ax
  int16_t v12; // [esp+0h] [ebp-18h]
  int16_t v14; // [esp+8h] [ebp-10h]

  v12 = a5 + a4 + a2 + 12;
  v7 = 0;
  v14 = a6 + a1 + a3 + 16;
  while ( 1 )
  {
    v8 = (int16_t *)(14 * v7 + dword_193184);
    v9 = *v8;
    v10 = *((uint8_t *)v8 + 7);
    if ( *v8 > -1 )
    {
      v11 = *(uint8_t *)(17 * v9 + dword_1930D4 + 4);
      if ( v11 == 3 || v11 == 2 )
      {
        sub_A2D7C(v9, v7, a1, a2, a3, a4, a5, a6);
      }
      else
      {
        dword_193410 = sub_127C27((int)aBuffer0Lbx_4, 91, dword_193174);
        sub_12B753(dword_193410, v10);
        sub_12A478(v14, v12, dword_193410);
      }
    }
    if ( ++v7 >= 5 )
      JUMPOUT(0xA2D27);
  }
}
// A31D5: control flows out of bounds to A2D27
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 193184: using guessed type int dword_193184;
// 193410: using guessed type int dword_193410;


//----- (000A31DA) --------------------------------------------------------
void __fastcall sub_A31DA(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int16_t v9; // di
  char *v10; // eax
  int16_t v11; // di
  char *v12; // eax
  int16_t v13; // bx
  int v14; // ecx
  int16_t v15; // dx
  int v16; // eax
  int16_t v17; // cx
  int16_t v18; // bx
  int16_t v19; // ax
  int v20; // esi
  int v21; // esi
  char *v22; // eax
  char *v23; // esi
  int16_t v24; // cx
  int16_t v25; // dx
  int v26; // eax
  int16_t v27; // di
  int v28; // eax
  int16_t v29; // si
  int16_t v30; // bx
  int16_t *v31; // eax
  int16_t v32; // si
  int v33; // edx
  int16_t v34; // bx
  int16_t v35; // ax
  char *v36; // eax
  int16_t v37; // si
  int16_t v38; // di
  int v39; // eax
  int16_t v40; // dx
  int v41; // eax
  int v42; // ebx
  int16_t v43; // bx
  int v44; // eax
  int v45; // edi
  int v46; // [esp-4h] [ebp-DAh]
  int v47; // [esp-4h] [ebp-DAh]
  char *v48; // [esp-4h] [ebp-DAh]
  int v49; // [esp-4h] [ebp-DAh]
  int v50; // [esp+0h] [ebp-D6h]
  int v51; // [esp+0h] [ebp-D6h]
  int v52; // [esp+4h] [ebp-D2h] BYREF
  int v53; // [esp+8h] [ebp-CEh]
  int v54; // [esp+Ch] [ebp-CAh]
  int v55; // [esp+10h] [ebp-C6h]
  int v56; // [esp+14h] [ebp-C2h]
  int v57; // [esp+18h] [ebp-BEh]
  __int128 v58; // [esp+1Ch] [ebp-BAh]
  int64_t v59; // [esp+2Ch] [ebp-AAh]
  int v60; // [esp+34h] [ebp-A2h]
  int v61; // [esp+38h] [ebp-9Eh]
  int v62; // [esp+3Ch] [ebp-9Ah]
  int v63; // [esp+40h] [ebp-96h]
  int v64; // [esp+44h] [ebp-92h]
  int v65; // [esp+48h] [ebp-8Eh]
  int v66; // [esp+4Ch] [ebp-8Ah]
  int v67; // [esp+50h] [ebp-86h]
  __int128 v68; // [esp+54h] [ebp-82h]
  int v69; // [esp+64h] [ebp-72h]
  char v70[80]; // [esp+68h] [ebp-6Eh] BYREF
  _BYTE v71[8]; // [esp+B8h] [ebp-1Eh] BYREF
  int v72; // [esp+C0h] [ebp-16h]
  int v73; // [esp+C4h] [ebp-12h]
  int v74; // [esp+C8h] [ebp-Eh]
  int v75; // [esp+CCh] [ebp-Ah]
  int v76; // [esp+D0h] [ebp-6h]
  int v77; // [esp+D4h] [ebp-2h]
  int v78; // [esp+D8h] [ebp+2h]
  int v79; // [esp+DCh] [ebp+6h]
  int v80; // [esp+E0h] [ebp+Ah]
  int v81; // [esp+E4h] [ebp+Eh]
  int v82; // [esp+E8h] [ebp+12h]
  int v83; // [esp+ECh] [ebp+16h]
  int v84; // [esp+F0h] [ebp+1Ah]
  int v85; // [esp+F4h] [ebp+1Eh]
  int v86; // [esp+F8h] [ebp+22h]
  int v87; // [esp+FCh] [ebp+26h]
  int v88; // [esp+100h] [ebp+2Ah]
  int v89; // [esp+104h] [ebp+2Eh]
  int v90; // [esp+108h] [ebp+32h]
  int v91; // [esp+10Ch] [ebp+36h]
  int v92; // [esp+110h] [ebp+3Ah]
  int v93; // [esp+114h] [ebp+3Eh]
  int v94; // [esp+118h] [ebp+42h]
  int v95; // [esp+11Ch] [ebp+46h] BYREF
  int v96; // [esp+120h] [ebp+4Ah] BYREF
  int v97; // [esp+124h] [ebp+4Eh]
  int v98; // [esp+128h] [ebp+52h]
  _BYTE v99[4]; // [esp+12Ch] [ebp+56h] BYREF
  _BYTE v100[4]; // [esp+130h] [ebp+5Ah] BYREF
  int v101; // [esp+134h] [ebp+5Eh]
  int v102; // [esp+138h] [ebp+62h]
  int v103; // [esp+13Ch] [ebp+66h]
  char v104; // [esp+140h] [ebp+6Ah]

  v104 = a2;
  v79 = a3;
  v102 = a4;
  v89 = 0;
  word_19987A = (word_19987A + 1) % 32000;
  if ( !word_199A08 )
  {
    sub_128AB6(22, 22, 527, 421);
    sub_12B634();
  }
  word_1999E6 = v102;
  word_1999E8 = a5;
  if ( !byte_199F18 )
  {
    v80 = (int16_t)v50;
    if ( !sub_A44FC(v50, word_19999C) )
    {
      if ( sub_79E4D(word_19999C, v80) )
      {
        v86 = (int16_t)a9;
        v76 = (int16_t)a8;
        v75 = (int16_t)a7;
        v74 = (int16_t)a6;
        sub_A3F21((int16_t)v102, (int16_t)a5, (int16_t)a6, (int16_t)a7, (int16_t)a8, (int16_t)a9, 1);
        if ( v104 )
          sub_A30C5(v76, v86, 0);
        v9 = a6 + v102;
        v87 = a7 + a5 + a9;
        if ( word_199A08 == 29 )
        {
          sub_128B49();
          sub_128AB6(0, 0, 639, 479);
          sub_12B634();
          sub_C6FF3(v9 - 5, v87 + 40, 9, v50);
          sub_128B98();
          sub_12B65C();
        }
        else
        {
          sub_C6FF3(v9 + 5, v89 + a7 + a5 + a9, 9, v50);
          v46 = 113 * (int16_t)v50 + dword_19306C;
          v10 = sub_7A990(0x16Au);
          sprintf(&v52, v10, v46);
          sub_A4C41(v102, a5, a6, a7, (int)&v52);
        }
      }
      else
      {
        v72 = (int16_t)a9;
        v11 = v102;
        v84 = (int16_t)a8;
        v82 = (int16_t)a6;
        v81 = (int16_t)a5;
        sub_A3F21((int16_t)v102, (int16_t)a5, (int16_t)a6, (int16_t)a7, (int16_t)a8, (int16_t)a9, 0);
        if ( v104 )
        {
          sub_A30C5(v84, v72, 1);
          if ( sub_78F4B(v80) )
          {
            v47 = dword_19306C + 113 * v80;
            v12 = sub_7A990(0x16Au);
            v13 = v82;
            sprintf(&v52, v12, v47);
            v14 = (int16_t)a7;
            v15 = v81;
            sub_A4C41(v11, v81, v13, a7, (int)&v52);
          }
          else
          {
            v13 = v82;
            v15 = v81;
            v48 = sub_7A990(0x16Bu);
            v14 = (int16_t)a7;
            sub_A4C41(v102, v81, v82, a7, (int)v48);
          }
          sub_A573B((int16_t)v50, v15, v14, v13, v11, a7);
        }
      }
      return;
    }
  }
  if ( v104 )
    sub_A30C5((int16_t)a8, (int16_t)a9, 1);
  word_1999D0 = v50;
  v16 = 113 * (int16_t)v50 + dword_19306C;
  if ( *(char *)(v16 + 41) > -1 )
  {
    LOWORD(v16) = *(char *)(v16 + 41);
    v92 = v16;
    qmemcpy(v71, sub_8E5C5(1u, 110, 115), sizeof(v71));
    sub_120BB5(1, (int)v71);
    if ( word_199A08 == 29 )
    {
      v17 = 624;
      v18 = 187;
    }
    else
    {
      v19 = sub_122259();
      v17 = a6 + v102 + 329;
      v18 = a7 + a5 + 230 - v19 - 2;
    }
    v20 = 113 * (int16_t)v50;
    v70[0] = 0;
    if ( *(char *)(v20 + dword_19306C + 41) <= -1 )
    {
      if ( !sub_79E32(word_19999C, v50) )
        goto LABEL_29;
      v23 = (char *)dword_18F9B8[*(char *)(v20 + dword_19306C + 40)];
    }
    else
    {
      v21 = (int16_t)v92;
      if ( sub_79E32(word_19999C, v92) )
      {
        v49 = 113 * v21 + dword_19306C;
        v22 = sub_7A990(0x16Cu);
        sprintf(v70, v22, v49);
        goto LABEL_29;
      }
      v23 = sub_7A990(0x16Du);
    }
    strcpy(v70, v23);
LABEL_29:
    if ( v70[0] )
      sub_1210B7(v17, v18, (int)v70);
  }
  if ( byte_19D32D )
    sub_A3025(v50, v102, a5, a6, a7, (int16_t)a9, (int16_t)a8);
  if ( byte_19D32C )
  {
    byte_19D32C = 0;
  }
  else
  {
    sub_A30FD(v102, a5, a6, a7, a9, a8);
    word_1845D8 = 1;
  }
  if ( !byte_19D32D )
    sub_A3025(v50, v102, a5, a6, a7, (int16_t)a9, (int16_t)a8);
  v101 = a8 + a6 + v102 + 161;
  v24 = 0;
  v103 = a9 + a7 + a5 + 90;
  do
  {
    v25 = *(_WORD *)(14 * v24 + dword_193184);
    if ( v25 > -1 )
    {
      v26 = 17 * v25;
      v27 = *(uint8_t *)(dword_1930D4 + v26 + 5);
      if ( *(_BYTE *)(dword_1930D4 + v26 + 4) == 2 )
        v27 = 4;
      v28 = dword_193184 + 14 * v24;
      v29 = *(_WORD *)(v28 + 2) + v101;
      v30 = *(_WORD *)(v28 + 4) + v103;
      v31 = (int16_t *)(17 * v25 + dword_1930D4);
      v32 = v29 - 2;
      v33 = *v31;
      v34 = v30 - 2;
      if ( v33 > -1 )
      {
        LOWORD(v33) = *v31;
        v91 = v33;
        if ( *((_BYTE *)v31 + 4) == 1 )
        {
          v35 = (uint8_t)byte_199EC2[v27] / 2;
          v32 += v35;
          v34 += v35;
        }
        v36 = (char *)(dword_192B18 + 361 * (int16_t)v91);
        if ( v36[6] )
          sub_A2D2D(v32, v34, *v36);
        else
          sub_A2C11(v32, v34, *v36);
      }
    }
    ++v24;
  }
  while ( v24 < 5 );
  v88 = a9 + a5 + a7;
  v98 = a8 + a6 + v102 + 161;
  v37 = 0;
  v97 = a8 + v102 + a6;
  v93 = a9 + a7 + a5 + 90;
  do
  {
    v38 = *(_WORD *)(14 * v37 + dword_193184);
    if ( v38 > -1 )
    {
      v39 = dword_1930D4 + 17 * v38;
      v40 = *(uint8_t *)(v39 + 5);
      if ( *(_BYTE *)(v39 + 4) == 2 )
        v40 = 4;
      v41 = dword_193184 + 14 * v37;
      HIWORD(v42) = HIWORD(v98);
      LOWORD(v42) = *(_WORD *)(v41 + 2) + v98;
      v90 = v42 - 2;
      v43 = *(_WORD *)(v41 + 4) + v93 - 2;
      if ( *(uint8_t *)(v41 + 7) == word_1999C0 )
      {
        v44 = v40;
        LOWORD(v44) = (uint8_t)byte_199EC2[v40];
        v94 = v44;
        if ( *(_BYTE *)(dword_1930D4 + 17 * v38 + 4) != 1 )
          sub_A3A15(v38, v94, v94, v90, v43);
        sub_A2123(
          v38,
          0,
          0,
          (int)&v95,
          (int)&v96,
          0,
          v50,
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
        sub_8F055(v97, v88, (int16_t)(v95 + 9), v96 + 4, 0x3Fu);
        sub_A2123(
          v38,
          (int16_t)a8,
          (int16_t)a9,
          (int)v100,
          (int)v99,
          1,
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
      }
    }
    ++v37;
  }
  while ( v37 < 5 );
  v77 = (int16_t)a8;
  v45 = (int16_t)v102;
  v83 = (int16_t)a9;
  v85 = (int16_t)a7;
  v78 = (int16_t)a6;
  sub_A3BC4((int16_t)v102, (int16_t)a5, (int16_t)a6, (int16_t)a7, (int16_t)a9, a8);
  v73 = (int16_t)v50;
  sub_A2C66(v50, v45, a5, v78, v85, v77);
  if ( word_1999C0 >= 2000 && word_1999C0 < 2004 )
    sub_A4989(v73, (int16_t)(word_1999C0 - 2000), v45, (int16_t)a5, v78, v85, v77, v83);
  if ( word_199A08 != 29 )
    sub_A4C41(v102, a5, a6, a7, v79);
}
// A325D: variable 'v50' is possibly undefined
// A393B: variable 'v51' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1845D8: using guessed type int16_t word_1845D8;
// 18F9B8: using guessed type int dword_18F9B8[];
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 193184: using guessed type int dword_193184;
// 19987A: using guessed type int16_t word_19987A;
// 19999C: using guessed type int16_t word_19999C;
// 1999C0: using guessed type int16_t word_1999C0;
// 1999D0: using guessed type int16_t word_1999D0;
// 1999E6: using guessed type int16_t word_1999E6;
// 1999E8: using guessed type int16_t word_1999E8;
// 199A08: using guessed type int16_t word_199A08;
// 199F18: using guessed type char byte_199F18;
// 19D32C: using guessed type char byte_19D32C;
// 19D32D: using guessed type char byte_19D32D;


//----- (000A3A15) --------------------------------------------------------
int __fastcall sub_A3A15( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v6; // cx
  int v7; // edx
  int16_t v8; // si
  int16_t k; // cx
  int16_t v10; // dx
  char v11; // bl
  int result; // eax
  int v13; // edi
  int16_t m; // cx
  char v15; // bl
  int16_t v16; // dx
  int16_t v17; // si
  int16_t i; // cx
  int16_t v19; // si
  int16_t j; // cx
  int16_t v23; // [esp+8h] [ebp-10h]
  int v24; // [esp+Ch] [ebp-Ch]
  int16_t v25; // [esp+10h] [ebp-8h]
  char v26; // [esp+14h] [ebp-4h]

  v6 = *(_WORD *)(dword_1930D4 + 17 * a1);
  v26 = 0;
  dword_193190 = sub_127C27((int)aBuffer0Lbx_4, 75, dword_193174);
  v25 = *(_WORD *)dword_193190;
  v23 = *(_WORD *)(dword_193190 + 2);
  if ( v6 <= -1 )
  {
    v17 = 73;
    for ( i = 6; i != 15; ++i )
      sub_13719F(dword_193190, v17++, i);
    v19 = 73;
    sub_12A478(a4 - (v25 - a2) / 2, a5 - (v23 - a3) / 2, dword_193190);
    for ( j = 6; j != 15; ++j )
      result = sub_13719F(dword_193190, j, v19++);
  }
  else
  {
    v7 = 3753 * *(char *)(361 * v6 + dword_192B18);
    v8 = *(uint8_t *)(v7 + dword_197F98 + 38);
    if ( *(_BYTE *)(v7 + dword_197F98 + 38) )
    {
      v24 = 73;
      for ( k = 0; k < 9; ++k )
      {
        v10 = v24++;
        v11 = k + byte_10010[v8];
        sub_13719F(dword_193190, v10, v11);
      }
      v26 = 1;
    }
    result = sub_12A478(a4 - (v25 - a2) / 2, a5 - (v23 - a3) / 2, dword_193190);
    if ( v26 )
    {
      v13 = 73;
      for ( m = 0; m < 9; ++m )
      {
        v15 = v13++;
        v16 = m + (uint8_t)byte_10010[v8];
        result = sub_13719F(dword_193190, v16, v15);
      }
    }
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 193190: using guessed type int dword_193190;
// 197F98: using guessed type int dword_197F98;


//----- (000A3BC4) --------------------------------------------------------
void __fastcall sub_A3BC4(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int16_t v6; // di
  int v7; // eax
  int v8; // edx
  int16_t v9; // dx
  int v10; // ebx
  int16_t v11; // ax
  int v12; // eax
  int16_t v13; // [esp+4h] [ebp-4Ch]
  int16_t v14; // [esp+8h] [ebp-48h]
  int16_t v15; // [esp+Ch] [ebp-44h]
  int16_t v16; // [esp+10h] [ebp-40h]
  int16_t v17; // [esp+28h] [ebp-28h]
  int v18; // [esp+2Ch] [ebp-24h]
  int16_t v19; // [esp+30h] [ebp-20h] BYREF
  int16_t v20; // [esp+34h] [ebp-1Ch] BYREF
  int v21; // [esp+38h] [ebp-18h] BYREF
  int v22; // [esp+3Ch] [ebp-14h]
  int v23; // [esp+40h] [ebp-10h]
  int v24; // [esp+44h] [ebp-Ch]
  int v25; // [esp+48h] [ebp-8h]
  int v26; // [esp+4Ch] [ebp-4h] BYREF

  v15 = a1;
  v14 = a2;
  v13 = a3;
  v23 = a5 + a2 + a4;
  v18 = a3 + a1;
  v6 = 0;
  v17 = a6 + a1 + a3;
  v22 = a4 + a2;
  while ( 1 )
  {
    v7 = word_1931C2[6 * v6];
    if ( v7 > -1 )
    {
      HIWORD(v8) = HIWORD(v18);
      LOWORD(v8) = word_1931BC[6 * v6] + v18;
      v24 = v8;
      HIWORD(v8) = HIWORD(v22);
      LOWORD(v8) = word_1931BE[6 * v6] + v22;
      v25 = v8;
      if ( word_1999C0 > 999 && word_1999C0 - 1000 == v7 )
      {
        v16 = word_1931C2[6 * v6];
        sub_A26E3(v15, v14, v13, (int16_t)a4, v16, (int16_t *)&v26, (int16_t *)&v21, 0);
        sub_8F055(v17, v23, (int16_t)(v26 + 9), v21 + 4, 0x3Fu);
        sub_A26E3(v15, v14, v13, (int16_t)a4, v16, &v20, &v19, 1);
        v9 = v25;
        v10 = sub_A5844(v6);
        dword_1931C4[3 * v6] = v10;
        v11 = v24;
      }
      else
      {
        v9 = v25;
        v12 = sub_A5844(v6);
        dword_1931C4[3 * v6] = v12;
        sub_12B726(v12);
        v11 = v24;
        v10 = dword_1931C4[3 * v6];
      }
      sub_12A478(v11, v9, v10);
    }
    if ( ++v6 >= 15 )
      JUMPOUT(0xA2D27);
  }
}
// A3D25: control flows out of bounds to A2D27
// 1931BC: using guessed type int16_t word_1931BC[];
// 1931BE: using guessed type int16_t word_1931BE[];
// 1931C2: using guessed type int16_t word_1931C2[];
// 1931C4: using guessed type int dword_1931C4[43];
// 1999C0: using guessed type int16_t word_1999C0;


//----- (000A3D2A) --------------------------------------------------------
_WORD *__fastcall sub_A3D2A( int a1, int a2, int a3, int a4, int a5, _WORD *a6, _WORD *a7)
{
  _WORD *result; // eax

  result = a6;
  *a6 = a1 + a3 + 233;
  *a7 = a2 + a4 + 243;
  if ( word_199A08 == 29 )
  {
    *a6 += 60;
    *a7 -= 70;
  }
  return result;
}
// 199A08: using guessed type int16_t word_199A08;


//----- (000A3D84) --------------------------------------------------------
int __fastcall sub_A3D84(int *a1, int a2)
{
  int v3; // eax
  int16_t v4; // bx
  int16_t v5; // cx
  int16_t v6; // ax
  int16_t v7; // di
  int v8; // eax
  int16_t v9; // ax
  int result; // eax
  int v11; // [esp+0h] [ebp-8h]
  _BOOL1 v12; // [esp+4h] [ebp-4h]

  v3 = dword_1930D4 + 17 * a2;
  v4 = *(uint8_t *)(v3 + 8);
  v5 = *(_WORD *)v3;
  v12 = *(_BYTE *)(v3 + 4) == 2;
  v11 = 17 * a2;
  if ( *(_BYTE *)(v11 + dword_1930D4 + 5) >= 4u )
    v6 = 4;
  else
    v6 = *(uint8_t *)(v11 + dword_1930D4 + 5);
  v7 = v6;
  if ( v5 > -1 && v5 < word_199996 && !v12 )
  {
    v8 = 361 * v5 + dword_192B18;
    if ( !*(_BYTE *)(v8 + 6) )
      v4 = *(uint8_t *)(v8 + 226);
  }
  if ( *(_BYTE *)(dword_1930D4 + 17 * a2 + 4) == 2 )
    v9 = 50;
  else
    v9 = v7 + 5 * v4;
  result = sub_127C27((int)aBuffer0Lbx_4, v9 + 92, dword_193174);
  *a1 = result;
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 199996: using guessed type int16_t word_199996;


//----- (000A3E3D) --------------------------------------------------------
void __fastcall sub_A3E3D(int a1, int a2, _WORD *a3, _WORD *a4, _WORD *a5)
{
  _WORD *v6; // eax
  int v7; // ebx
  int v8; // eax
  int16_t v9; // dx

  dword_193070 = sub_127C27((int)aBuffer0Lbx_4, 73, dword_193174);
  if ( word_199A08 == 29 )
  {
    dword_1931C4[3 * a2] = sub_A5844(a2);
    *a3 = *a5 + 5;
    *a4 = 180 - *(_WORD *)(dword_1931C4[3 * a2] + 2) - 3;
    v6 = (_WORD *)dword_1931C4[3 * a2];
  }
  else
  {
    v7 = 3 * a2;
    v8 = sub_A5844(a2);
    dword_1931C4[v7] = v8;
    v9 = *(_WORD *)(v8 + 2);
    *a3 = *a5 + 18;
    *a4 = (25 - v9) / 2 + 236;
    v6 = (_WORD *)dword_1931C4[v7];
  }
  *a5 += *v6 + 3;
  JUMPOUT(0xA3BBE);
}
// A3EF7: control flows out of bounds to A3BBE
// 193070: using guessed type int dword_193070;
// 193174: using guessed type int dword_193174;
// 1931C4: using guessed type int dword_1931C4[43];
// 199A08: using guessed type int16_t word_199A08;


//----- (000A3EFC) --------------------------------------------------------
int16_t __fastcall sub_A3EFC( int a1, int a2, int a3, int a4, int a5, int16_t *a6, int16_t *a7)
{
  return sub_A26E3(a1, a2, a3, a4, a5, a6, a7, 0);
}


//----- (000A3F21) --------------------------------------------------------
void __fastcall sub_A3F21(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int16_t v8; // ax
  _BYTE v9[8]; // [esp+0h] [ebp-18h] BYREF
  int v10; // [esp+8h] [ebp-10h]
  int v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]

  if ( word_199A08 == 29 )
  {
    v10 = 306;
    v12 = 17;
    v11 = 624;
    v13 = 197;
  }
  else
  {
    v7 = a5 + a3 + a1;
    v10 = v7 - 1;
    v11 = v7 + 319;
    v12 = a6 + a4 + a2 - 1;
    v13 = a6 + a4 + a2 + 182;
  }
  qmemcpy(v9, sub_8E5C5(4u, 110, 115), sizeof(v9));
  if ( a7 )
  {
    v8 = dword_1BBA52;
    if ( (int16_t)dword_1BBA52 > (int16_t)v13 )
      v8 = v13;
    sub_8EC70(v10, v12, v11 - 5, v8, 16, 0x3Du, 0x3Bu);
    sub_120BB5(4, (int)v9);
  }
  JUMPOUT(0xA30BF);
}
// A3FE1: control flows out of bounds to A30BF
// 199A08: using guessed type int16_t word_199A08;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (000A3FE6) --------------------------------------------------------
void __fastcall sub_A3FE6( int a1)
{
  if ( sub_A4426(a1) )
  {
    word_1999C6 = a1;
    sub_A4E1B(a1);
    byte_19D32C = 1;
    if ( word_192FDE[0] < word_1992C0[0] )
      byte_19D32F = 1;
    sub_A404E(a1);
    word_1999C0 = -1;
    if ( sub_79E4D(word_19999C, a1) )
      sub_C6F26();
  }
}
// 192FDE: using guessed type int16_t word_192FDE[];
// 1992C0: using guessed type int16_t word_1992C0[];
// 19999C: using guessed type int16_t word_19999C;
// 1999C0: using guessed type int16_t word_1999C0;
// 1999C6: using guessed type int16_t word_1999C6;
// 19D32C: using guessed type char byte_19D32C;
// 19D32F: using guessed type char byte_19D32F;


//----- (000A404E) --------------------------------------------------------
void __fastcall sub_A404E( int a1)
{
  int v2; // edi
  int v3; // eax
  int16_t *v4; // eax
  int16_t v5; // dx
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  char v10; // cl
  int16_t v11; // di
  int v12; // edx
  int v13; // eax
  int v14; // kr00_4
  int v15; // eax
  int v16; // edx
  int v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // edx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // [esp+0h] [ebp-1Ch] BYREF
  int v25; // [esp+4h] [ebp-18h] BYREF
  int v26; // [esp+8h] [ebp-14h] BYREF
  int v27; // [esp+Ch] [ebp-10h]
  int v28; // [esp+10h] [ebp-Ch]
  int16_t v29; // [esp+14h] [ebp-8h]
  int v30; // [esp+18h] [ebp-4h]

  v2 = 113 * a1;
  sub_1318D4(0, 255);
  sub_13AAC1();
  sub_FE8BE(v3);
  dword_193184 = (int)sub_110D3C(dword_19D214, 70);
  v4 = (int16_t *)sub_127C27((int)aBuffer0Lbx_4, 73, dword_193174);
  v5 = *v4;
  word_192FE0[0] = v4[1];
  v6 = *(uint8_t *)(v2 + dword_19306C + 22);
  word_192FE2[0] = v5;
  v7 = sub_127C27((int)aBuffer0Lbx_4, v6 + 83, dword_193174);
  v8 = dword_19306C;
  dword_190470[*(uint8_t *)(v2 + dword_19306C + 22)] = v7;
  v9 = *(uint8_t *)(v2 + v8 + 22);
  v29 = 0;
  v10 = 0;
  dword_19D218 = dword_190470[v9];
  sub_FE8BE(dword_19D218);
  byte_19D32D = 1;
  while ( 1 )
  {
    v11 = *(_WORD *)(113 * a1 + dword_19306C + 2 * v29 + 74);
    if ( v11 <= -1 )
    {
      v19 = 14 * v29;
      v20 = dword_193184;
      *(_WORD *)(dword_193184 + v19) = -1;
      *(_WORD *)(v20 + v19 + 2) = 999;
      *(_WORD *)(v20 + v19 + 4) = 999;
    }
    else
    {
      HIWORD(v12) = HIWORD(dword_1930D4);
      v13 = dword_1930D4 + 17 * v11;
      LOWORD(v12) = *(uint8_t *)(v13 + 5);
      v30 = v12;
      if ( *(_BYTE *)(v13 + 4) == 2 )
        v30 = 4;
      sub_EBEEB(a1, *(uint8_t *)(17 * v11 + dword_1930D4 + 3), &v26, &v25, &v24);
      v14 = (uint8_t)byte_199EC2[(int16_t)v30];
      v15 = v25 - v14 / 2;
      if ( !v29 && ((unsigned int)v24 <= 2 || v24 >= 12 && v24 <= 15) )
        byte_19D32D = 0;
      v27 = v29;
      v28 = 14 * v29;
      v16 = v28 + dword_193184;
      *(_WORD *)(v16 + 2) = v26 - v14 / 2;
      *(_WORD *)(v16 + 4) = v15;
      *(_WORD *)v16 = v11;
      *(_BYTE *)(v16 + 7) = v29;
      *(_BYTE *)(v16 + 6) = v24;
      sub_111499(dword_19D214);
      sub_A3D84((int *)(v28 + dword_193184 + 10), v11);
      v17 = 5 * v27 % *(int16_t *)(*(_DWORD *)(v28 + dword_193184 + 10) + 6);
      v10 = 1;
      v18 = *(_DWORD *)(v28 + dword_193184 + 10);
      *(_WORD *)(v28 + dword_193184 + 8) = v17;
      v19 = sub_13AAE9(v18, v17);
    }
    if ( ++v29 >= 5 )
    {
      sub_FE8BE(v19);
      if ( v10 )
      {
        sub_13AC01(192, 64);
        sub_133237();
        sub_A5050();
        if ( !word_199A08 && !byte_19D32C && sub_918D5(2) )
        {
          sub_91A40();
          sub_1172D4();
          v21 = sub_124D41();
          v22 = sub_84E9D(v21);
          sub_1077D(v22);
          sub_1172FC();
        }
      }
      v23 = sub_111499(dword_19D214);
      byte_199F1D = 0;
      sub_FE8BE(v23);
      qsort(dword_193184, 5, 14, sub_A5045);
      if ( !byte_199F18 && !sub_A44FC(a1, word_19999C) )
        sub_8F6DF(*(uint8_t *)(113 * a1 + dword_19306C + 22) + 15, byte_19D228);
      JUMPOUT(0xA20C6);
    }
  }
}
// A432A: control flows out of bounds to A20C6
// A4070: variable 'v3' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 84E9D: using guessed type int __fastcall sub_84E9D(_DWORD);
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 133EF4: using guessed type int __fastcall qsort(_DWORD, _DWORD, _DWORD, _DWORD);
// 190470: using guessed type int dword_190470[6];
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 193184: using guessed type int dword_193184;
// 19999C: using guessed type int16_t word_19999C;
// 199A08: using guessed type int16_t word_199A08;
// 199F18: using guessed type char byte_199F18;
// 199F1D: using guessed type char byte_199F1D;
// 19D214: using guessed type int dword_19D214;
// 19D218: using guessed type int dword_19D218;
// 19D32C: using guessed type char byte_19D32C;
// 19D32D: using guessed type char byte_19D32D;


//----- (000A432F) --------------------------------------------------------
void __fastcall sub_A432F( int a1, int a2, int a3, _WORD *a4, _WORD *a5, _WORD *a6, _WORD *a7, int a8)
{
  int16_t i; // dx
  int v9; // eax
  uint8_t v10; // al
  _WORD *v11; // eax
  int16_t v14; // [esp+Ch] [ebp-4h]

  *a4 = 0;
  *a5 = 0;
  *a6 = 0;
  *a7 = 0;
  memset(a8, 0, 12);
  for ( i = 0; ; ++i )
  {
    if ( i >= word_199994 )
      JUMPOUT(0xA301F);
    if ( sub_77FF5(i) == a3 )
    {
      v9 = 129 * i + dword_197F9C;
      if ( *(char *)(v9 + 100) < 3 && *(_WORD *)(v9 + 103) == a1 && *(_WORD *)(v9 + 105) == a2 )
        break;
    }
LABEL_19:
    ;
  }
  v14 = *(uint8_t *)(v9 + 16);
  if ( (uint16_t)v14 > 5u )
    v14 = 5;
  v10 = *(_BYTE *)(dword_197F9C + 129 * i + 17);
  if ( v10 )
  {
    if ( v10 <= 1u )
    {
      ++*a5;
    }
    else
    {
      if ( v10 > 2u )
      {
        if ( v10 != 4 )
          goto LABEL_18;
        v11 = a6;
        goto LABEL_17;
      }
      ++*a7;
    }
LABEL_18:
    ++*a4;
    goto LABEL_19;
  }
  v11 = (_WORD *)(a8 + 2 * v14);
LABEL_17:
  ++*v11;
  goto LABEL_18;
}
// A4421: control flows out of bounds to A301F
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000A4426) --------------------------------------------------------
_BOOL1 __fastcall sub_A4426( int a1)
{
  unsigned int v1; // kr08_4
  char v3[120]; // [esp+0h] [ebp-78h] BYREF

  sprintf(v3, "%d> %s", a1, (char *)(dword_19306C + 113 * a1));
  if ( strlen(v3) >= 0x14 )
    v3[20] = 0;
  v1 = strlen(v3) + 1;
  return !dword_193274 || strncmp(v3, dword_193274, (int16_t)(v1 - 1));
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 13ACDE: using guessed type int __fastcall strncmp(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 193274: using guessed type int dword_193274;


//----- (000A449A) --------------------------------------------------------
void __fastcall sub_A449A( int a1)
{
  char v1[120]; // [esp+0h] [ebp-78h] BYREF

  sprintf(v1, "%d> %s", a1, (char *)(dword_19306C + 113 * a1));
  if ( strlen(v1) >= 0x14 )
    v1[20] = 0;
  strncmp(v1, dword_193274, (int16_t)strlen(v1));
  JUMPOUT(0xA4494);
}
// A44FA: control flows out of bounds to A4494
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 13ACDE: using guessed type int __fastcall strncmp(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 193274: using guessed type int dword_193274;


//----- (000A44FC) --------------------------------------------------------
_BOOL1 __fastcall sub_A44FC( int a1, int a2)
{
  int v2; // ecx
  char v4; // dl
  _BOOL1 v5; // ah
  _BOOL1 result; // al

  v2 = a1;
  v4 = sub_79E32(a2, a1);
  v5 = sub_79E06(a2);
  result = *(_BYTE *)(dword_19306C + 113 * v2 + 22) == 6;
  if ( *(_BYTE *)(dword_19306C + 113 * v2 + 22) == 6 )
    return 0;
  if ( v4 || v5 )
    return 1;
  return result;
}
// 19306C: using guessed type int dword_19306C;


//----- (000A453F) --------------------------------------------------------
void sub_A453F()
{
  int v0; // ecx
  char *v1; // eax
  char *v2; // edi
  char *v3; // edi
  int16_t v4; // ax
  char *v5; // eax
  char *v6; // eax
  char *v7; // edi
  char *v8; // eax
  char *v9; // edi
  char *v10; // eax
  char *v11; // edi
  char *v12; // edi
  char *v13; // eax
  char *v14; // edi
  char *v15; // eax
  uint16_t v16; // ax
  char *v17; // eax
  char *v18; // edi
  char *v19; // edi
  char *v20; // edi
  char *v21; // eax
  char *v22; // edi
  char *v23; // eax
  uint16_t v24; // ax
  char *v25; // eax
  char *v26; // edi
  char *v27; // edi
  int v28; // eax
  int v29; // [esp-4h] [ebp-536h]
  int v30; // [esp-4h] [ebp-536h]
  int v31; // [esp-4h] [ebp-536h]
  int16_t v32; // [esp+0h] [ebp-532h]
  char v33; // [esp+3h] [ebp-52Fh] BYREF
  char v34[999]; // [esp+4h] [ebp-52Eh] BYREF
  char v35; // [esp+3EBh] [ebp-147h] BYREF
  char v36[199]; // [esp+3ECh] [ebp-146h] BYREF
  char v37; // [esp+4B3h] [ebp-7Fh] BYREF
  char v38[100]; // [esp+4B4h] [ebp-7Eh] BYREF
  _BYTE v39[80]; // [esp+518h] [ebp-1Ah] BYREF
  char v40[32]; // [esp+568h] [ebp+36h] BYREF
  char v41[32]; // [esp+588h] [ebp+56h] BYREF
  int16_t v42; // [esp+5A8h] [ebp+76h] BYREF
  int16_t v43; // [esp+5AAh] [ebp+78h]
  int16_t v44; // [esp+5AEh] [ebp+7Ch]
  int16_t v45; // [esp+5B0h] [ebp+7Eh]
  int16_t v46; // [esp+5B2h] [ebp+80h]
  int16_t v47; // [esp+5B4h] [ebp+82h]
  char v48[12]; // [esp+5B8h] [ebp+86h] BYREF
  char v49[12]; // [esp+5C4h] [ebp+92h] BYREF

  v0 = 17 * v32;
  strcpy(v40, sub_7A990(0x16Eu));
  strcpy(v41, sub_7A990(0x16Fu));
  sub_E5430((_BYTE *)(dword_197F98 + 3753 * word_19999C), (_BYTE *)(v0 + dword_1930D4), &v42);
  v1 = sub_7A990(0x170u);
  sprintf(v36, aM2530, v1);
  v2 = &v35;
  do
    ++v2;
  while ( *v2 );
  strcpy(v2, byte_179C5A);
  v3 = &v35;
  do
    ++v3;
  while ( *v3 );
  strcpy(v3, (char *)&off_179C5D);
  sub_E0B4F((int16_t *)(v0 + dword_1930D4), word_19999C);
  sprintf(v34, v36, v4);
  if ( v45 )
  {
    v29 = v45 / 2;
    v6 = sub_7A990(0x171u);
    sprintf(v38, byte_179C6A, v6, v29);
  }
  else
  {
    v5 = sub_7A990(0x171u);
    sprintf(v38, byte_179C61, v5);
  }
  v7 = &v33;
  do
    ++v7;
  while ( *v7 );
  strcpy(v7, v38);
  v30 = v46;
  v8 = sub_7A990(0x172u);
  sprintf(v38, byte_179C6A, v8, v30);
  v9 = &v33;
  do
    ++v9;
  while ( *v9 );
  strcpy(v9, v38);
  v31 = v47;
  v10 = sub_7A990(0x173u);
  sprintf(v38, byte_179C6A, v10, v31);
  v11 = &v33;
  do
    ++v11;
  while ( *v11 );
  strcpy(v11, v38);
  if ( v43 )
  {
    v14 = &v33;
    do
      ++v14;
    while ( *v14 );
    strcpy(v14, aM2517);
    v15 = sub_7A990(0x175u);
    sprintf(v38, byte_179C90, v15);
    if ( v43 <= 0 )
      v16 = 393;
    else
      v16 = 394;
    v17 = sub_7A990(v16);
    sprintf(v38, byte_179C95, v17);
    sprintf(v49, "%d%%\n", abs16(v43));
    v18 = &v37;
    do
      ++v18;
    while ( *v18 );
    strcpy(v18, v49);
  }
  else
  {
    v12 = &v33;
    do
      ++v12;
    while ( *v12 );
    strcpy(v12, aM2527);
    v13 = sub_7A990(0x174u);
    sprintf(v38, byte_179C7D, v13);
  }
  strlen(v34);
  v19 = &v33;
  do
    ++v19;
  while ( *v19 );
  strcpy(v19, v38);
  if ( v44 )
  {
    v22 = &v33;
    do
      ++v22;
    while ( *v22 );
    strcpy(v22, aM2517);
    v23 = sub_7A990(0x177u);
    sprintf(v38, byte_179C90, v23);
    if ( v44 <= 0 )
      v24 = 396;
    else
      v24 = 395;
    v25 = sub_7A990(v24);
    sprintf(v38, byte_179C95, v25);
    sprintf(v48, "%d%%\n", abs16(v44));
    v26 = &v37;
    do
      ++v26;
    while ( *v26 );
    strcpy(v26, v48);
  }
  else
  {
    v20 = &v33;
    do
      ++v20;
    while ( *v20 );
    strcpy(v20, aM2527);
    v21 = sub_7A990(0x176u);
    sprintf(v38, byte_179C7D, v21);
  }
  strlen(v34);
  v27 = &v33;
  do
    ++v27;
  while ( *v27 );
  strcpy(v27, v38);
  strcpy(v36, sub_7A990(0x178u));
  sub_77B42();
  sprintf(v39, v36, v28);
  sub_A5EB2((int)v39, (int)v34);
  JUMPOUT(0xA20C7);
}
// A4974: control flows out of bounds to A20C7
// A4556: variable 'v32' is possibly undefined
// A461B: variable 'v4' is possibly undefined
// A4957: variable 'v28' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 179C5D: using guessed type _UNKNOWN *off_179C5D;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (000A4989) --------------------------------------------------------
void __fastcall sub_A4989(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // eax
  uint16_t v9; // ax
  int16_t v10; // bx
  int v11; // ecx
  char *v12; // edi
  char *v13; // edi
  int16_t v14; // bx
  char v15; // al
  char *v16; // edi
  char *v17; // edi
  char *v18; // edi
  int16_t v19; // si
  int16_t v20; // di
  int16_t v21; // ax
  int16_t v22; // dx
  int16_t v23; // bx
  int16_t v24; // [esp+0h] [ebp-72h]
  int16_t v25; // [esp+4h] [ebp-6Eh]
  char v26; // [esp+6h] [ebp-6Ch]
  char v27; // [esp+7h] [ebp-6Bh] BYREF
  char v28[200]; // [esp+8h] [ebp-6Ah] BYREF
  _BYTE v29[8]; // [esp+D0h] [ebp+5Eh] BYREF
  int v30; // [esp+D8h] [ebp+66h]
  int v31; // [esp+DCh] [ebp+6Ah]
  int v32; // [esp+E0h] [ebp+6Eh]

  v32 = a5 + a3 + a7;
  v31 = a6 + a4 + a8;
  v8 = *(uint8_t *)(dword_197F98 + 3753 * word_19999C + 38);
  qmemcpy(v29, sub_8E5C5(1u, (uint8_t)byte_10010[v8], (uint8_t)byte_10010[v8] + 6), sizeof(v29));
  v28[0] = 0;
  sub_120BB5(1, (int)v29);
  switch ( v24 )
  {
    case 0:
      strcpy(v28, sub_7A990(0x17Cu));
      v14 = 0;
      v30 = sub_12066F((int)v28);
      while ( v14 < word_199998 )
      {
        sub_79D50();
        if ( v15 )
        {
          v16 = &v27;
          do
            ++v16;
          while ( *v16 );
          strcpy(v16, (char *)(3753 * v14 + dword_197F98 + 1));
          v17 = &v27;
          do
            ++v17;
          while ( *v17 );
          strcpy(v17, asc_179CA2);
        }
        ++v14;
      }
      goto LABEL_24;
    case 1:
      v9 = 378;
      goto LABEL_3;
    case 2:
      v9 = 377;
LABEL_3:
      strcpy(v28, sub_7A990(v9));
      v30 = sub_12066F((int)v28);
      break;
    case 3:
      strcpy(v28, sub_7A990(0x17Bu));
      v10 = 0;
      v30 = sub_12066F((int)v28);
      while ( v10 < word_199998 )
      {
        v11 = 3753 * v10;
        if ( (uint8_t)sub_79CF9(v11 + dword_197F98, 113 * v25 + dword_19306C) )
        {
          v12 = &v27;
          do
            ++v12;
          while ( *v12 );
          strcpy(v12, (char *)(v11 + dword_197F98 + 21));
          v13 = &v27;
          do
            ++v13;
          while ( *v13 );
          strcpy(v13, asc_179CA2);
        }
        ++v10;
      }
LABEL_24:
      *(&v26 + (int16_t)strlen(v28)) = 0;
      v18 = &v27;
      do
        ++v18;
      while ( *v18 );
      strcpy(v18, asc_179C33);
      break;
    default:
      break;
  }
  v19 = v30 + 2;
  v20 = sub_103CD6(v30 + 2, (int)v28, 0);
  v21 = sub_103CAF(v19, (int)v28);
  v22 = v31;
  v23 = v21;
  sub_122259();
  sub_8F055(v32, v22, (int16_t)(v20 + 12), v23 + 5, 0x3Fu);
  sub_103915(0);
  JUMPOUT(0xA2C08);
}
// A4C0A: control flows out of bounds to A2C08
// A4A1B: variable 'v24' is possibly undefined
// A4A7B: variable 'v25' is possibly undefined
// A4B37: variable 'v15' is possibly undefined
// 103915: using guessed type _DWORD __stdcall sub_103915(int16_t);
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;


//----- (000A4C0F) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=21)) - nutno dohledat rucne v IDA @ 0xA4C37 */
_DWORD __stdcall sub_A4C0F( int, int, int)
{
  DECOMP_TODO("call analysis failed (funcsize=21)");
}


//----- (000A4C41) --------------------------------------------------------
void __fastcall sub_A4C41( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v5; // bx
  int16_t v6; // ax
  int16_t v7; // cx
  int v8; // eax
  int16_t v9; // di
  int v10; // eax
  int v11; // eax
  _BYTE v15[8]; // [esp+10h] [ebp-24h] BYREF
  int v16; // [esp+18h] [ebp-1Ch]
  int v17; // [esp+1Ch] [ebp-18h]
  int v18; // [esp+20h] [ebp-14h]
  int v19; // [esp+24h] [ebp-10h]
  int v20; // [esp+28h] [ebp-Ch]
  int v21; // [esp+2Ch] [ebp-8h]
  int v22; // [esp+30h] [ebp-4h]

  qmemcpy(v15, sub_8E5C5(4u, 60, 65), sizeof(v15));
  sub_120BB5(4, (int)v15);
  v17 = 305;
  v5 = sub_12066F(a5);
  if ( v5 > 265 )
    sub_120BB5(3, (int)v15);
  if ( v5 >= 60 )
    v6 = 2;
  else
    v6 = 4;
  sub_120E8C(v6);
  v7 = sub_8F645();
  LOWORD(v8) = HIWORD(dword_1B61E4);
  v18 = v8;
  v9 = sub_122259();
  dword_193070 = sub_127C27((int)aBuffer0Lbx_4, 73, dword_193174);
  v21 = a1 + a3 + *(int16_t *)dword_193070 / 2;
  v19 = a2 + a4 + 17 + (20 - (int16_t)(v9 + 1)) / 2;
  sub_8FDA1(a5, (int)v15, v18, v7, 0, v17, 1);
  LOWORD(v10) = sub_8F64C();
  v20 = v10;
  LOWORD(v11) = sub_8F645();
  v22 = v11;
  v16 = (int16_t)v20;
  qmemcpy(v15, sub_8E5C5(v20, 60, 65), sizeof(v15));
  sub_120BB5(v16, (int)v15);
  sub_120E8C(v22);
  if ( (int16_t)v20 < 3 )
    v19 += 3 - v20;
  sub_90089(v21, v19, 61, a5);
  JUMPOUT(0xA3BBE);
}
// A4DAC: control flows out of bounds to A3BBE
// A4CC7: variable 'v8' is possibly undefined
// A4D4F: variable 'v10' is possibly undefined
// A4D57: variable 'v11' is possibly undefined
// 193070: using guessed type int dword_193070;
// 193174: using guessed type int dword_193174;
// 1B61E4: using guessed type int dword_1B61E4;


//----- (000A4DB1) --------------------------------------------------------
int16_t __fastcall sub_A4DB1( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v6; // [esp+0h] [ebp-8h] BYREF
  int16_t v7; // [esp+4h] [ebp-4h] BYREF

  return sub_A26E3(a1, a2, a3, a4, a5, &v6, &v7, 1);
}


//----- (000A4DD9) --------------------------------------------------------
int sub_A4DD9()
{
  int v0; // ebx
  int result; // eax
  int v2; // edx

  v0 = 0;
  do
  {
    result = (int16_t)v0;
    v2 = dword_19D220;
    byte_1BB658[4 * (int16_t)v0] = 1;
    byte_1BB659[4 * (int16_t)v0] = *(_BYTE *)(v2 + 4 * (int16_t)v0 + 1);
    byte_1BB65A[4 * (int16_t)v0] = *(_BYTE *)(v2 + 4 * (int16_t)v0 + 2);
    LOBYTE(v2) = *(_BYTE *)(v2 + 4 * (int16_t)v0++ + 3);
    byte_1BB65B[4 * result] = v2;
  }
  while ( (int16_t)v0 < 64 );
  return result;
}
// 19D220: using guessed type int dword_19D220;


//----- (000A4E1B) --------------------------------------------------------
void __fastcall sub_A4E1B( int a1)
{
  char v2[120]; // [esp+0h] [ebp-78h] BYREF

  dword_193274 = (int)sub_110CEE(dword_19D214, 20);
  memset(dword_193274, 0, 20);
  sprintf(v2, "%d> %s", a1, (char *)(dword_19306C + 113 * a1));
  if ( strlen(v2) >= 0x14 )
    v2[20] = 0;
  sprintf(dword_193274, v2);
  JUMPOUT(0xA4494);
}
// A4E8E: control flows out of bounds to A4494
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 193274: using guessed type int dword_193274;
// 19D214: using guessed type int dword_19D214;


//----- (000A4E93) --------------------------------------------------------
int64_t __fastcall sub_A4E93( int a1, int a2, int a3, _BYTE *a4)
{
  int16_t v4; // dx
  char *v5; // eax
  int v7; // [esp-Ch] [ebp-48h]
  char v8[28]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v9[12]; // [esp+20h] [ebp-1Ch] BYREF
  int v10; // [esp+2Ch] [ebp-10h] BYREF
  int v11; // [esp+30h] [ebp-Ch] BYREF
  int v12; // [esp+34h] [ebp-8h] BYREF
  int v13; // [esp+38h] [ebp-4h] BYREF

  *a4 = 0;
  sub_A432F(a1, a2, a3, &v10, &v12, &v13, &v11, (int)v9);
  v4 = v10 - (v13 + v11 + v12);
  strcpy(v8, (char *)sub_78477(a3));
  v7 = (int16_t)v10;
  v5 = sub_7A990(0x17Du);
  return sprintf(a4, v5, v7, v8, v4);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);


//----- (000A4F1F) --------------------------------------------------------
unsigned int __fastcall sub_A4F1F( int a1, int a2, int a3, int a4, int a5, _WORD *a6)
{
  unsigned int v6; // esi
  int16_t v8; // [esp+0h] [ebp-8h] BYREF
  int16_t v9; // [esp+4h] [ebp-4h] BYREF

  v6 = a1;
  sub_A3FE6(a1);
  return sub_A1C74(v6, a2, a3, 0, 0, a4, a5, &v9, a6, &v8);
}


//----- (000A4F58) --------------------------------------------------------
void sub_A4F58()
{
  int16_t v0; // dx
  int16_t v1; // di
  unsigned int v2; // esi
  int16_t v3; // cx
  int16_t v4; // bx

  v0 = word_192FE6[0];
  v1 = word_192FE4[0];
  v2 = word_192FDE[0];
  v3 = word_192FF4;
  v4 = word_192FF6;
  sub_A3FE6(word_192FDE[0]);
  sub_A1C74(v2, v1, v0, v3, v4, 13, 47, word_192FEA, &word_192FEC, word_192FEE);
  JUMPOUT(0xA20C6);
}
// A4FB9: control flows out of bounds to A20C6
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 192FEA: using guessed type int16_t word_192FEA[];
// 192FEC: using guessed type int16_t word_192FEC;
// 192FEE: using guessed type int16_t word_192FEE[];
// 192FF4: using guessed type int16_t word_192FF4;
// 192FF6: using guessed type int16_t word_192FF6;


//----- (000A4FBE) --------------------------------------------------------
void __fastcall sub_A4FBE(int a1, int a2, int a3)
{
  int v3; // esi
  int16_t v4; // cx
  char *v5; // eax
  int64_t v6; // rax
  int v7; // [esp-4h] [ebp-5Ch]
  _BYTE v8[80]; // [esp+0h] [ebp-58h] BYREF
  int v9; // [esp+50h] [ebp-8h]
  int v10; // [esp+54h] [ebp-4h]

  v3 = word_192FDE[0];
  LOWORD(a3) = word_192FF6;
  LOWORD(a2) = word_192FE4[0];
  v10 = a3;
  v4 = word_192FF4;
  v9 = a2;
  v7 = dword_19306C + 113 * word_192FDE[0];
  v5 = sub_7A990(0x16Au);
  v6 = sprintf(v8, v5, v7);
  sub_A3FE6(v3);
  sub_A31DA(v3, 1, (int)v8, (int16_t)v9, SWORD2(v6), v4, (int16_t)v10, 13, 47);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192FDE: using guessed type int16_t word_192FDE[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 192FF4: using guessed type int16_t word_192FF4;
// 192FF6: using guessed type int16_t word_192FF6;
// 19306C: using guessed type int dword_19306C;


//----- (000A5045) --------------------------------------------------------
int __fastcall sub_A5045(int a1, int a2)
{
  return *(int16_t *)(a1 + 4) - *(int16_t *)(a2 + 4);
}


//----- (000A5050) --------------------------------------------------------
void sub_A5050()
{
  int v0; // esi
  int v1; // edi
  int j; // ecx
  int v3; // eax
  int v4; // [esp+0h] [ebp-10h]
  int i; // [esp+8h] [ebp-8h]
  uint8_t v6; // [esp+Ch] [ebp-4h]

  v0 = 0;
  sub_13372A();
  for ( i = 0; ; i += 256 )
  {
    v1 = i;
    for ( j = 0; j != 1024; j += 4 )
    {
      v3 = 100 - (uint8_t)byte_1823E0[v0];
      ++v1;
      v4 = v3 * (uint8_t)byte_1BB35B[j] / 100;
      v6 = v3 * (uint8_t)byte_1BB35A[j] / 100;
      LOBYTE(v3) = v3 * (uint8_t)byte_1BB359[j] / 100;
      byte_19C813[v1] = sub_1338C9(v3, v6, v4);
    }
    if ( ++v0 >= 10 )
      JUMPOUT(0xA20C6);
  }
}
// A5109: control flows out of bounds to A20C6


//----- (000A512E) --------------------------------------------------------
void __fastcall sub_A512E( int a1, int a2, int16_t *a3, int a4)
{
  int16_t v7; // bx
  int16_t v8; // dx
  char *v9; // edx
  int v10; // edx
  int v11; // eax
  char *v12; // eax
  int16_t v13; // dx
  int16_t v14; // dx
  int v15; // [esp+10h] [ebp-14h]
  int v16; // [esp+14h] [ebp-10h]
  int16_t v17; // [esp+18h] [ebp-Ch]
  int16_t v18; // [esp+1Ch] [ebp-8h]
  int16_t v19; // [esp+20h] [ebp-4h]

  v18 = 0;
  if ( word_1845D8 == 1 )
  {
    if ( a1 > (int16_t)dword_1BBA4E )
      return;
    if ( a2 > (int16_t)dword_1BBA52 )
      return;
    v7 = a1 + *(_WORD *)dword_1BC2A8 - 1;
    v19 = v7;
    if ( v7 < SHIWORD(dword_1BBA4A) )
      return;
    v8 = a2 + *(_WORD *)(dword_1BC2A8 + 2) - 1;
    v17 = v8;
    if ( v8 < SHIWORD(dword_1BBA4E) )
      return;
    if ( a1 < SHIWORD(dword_1BBA4A)
      || a2 < SHIWORD(dword_1BBA4E)
      || v7 > (int16_t)dword_1BBA4E
      || v8 > (int16_t)dword_1BBA52 )
    {
      v18 = 1;
    }
  }
  dword_1BC2A8 = (int)a3;
  v9 = (char *)a3 + *(_DWORD *)&a3[2 * a3[2] + 6];
  dword_19D224 = a4;
  v16 = (int)v9;
  v10 = a4 + *(_DWORD *)(a4 + 12 + 4 * *(int16_t *)(a4 + 4));
  v15 = v10;
  if ( !v18 )
  {
    if ( dword_1BBA28 >= 2 )
    {
      sub_138CEE(a1, a2, a1 + *a3 - 1, a2 + a3[1] - 1);
      v10 = a2 + 100;
      sub_138CEE(a1 + 100, v10, a1 + 100 + *(int16_t *)dword_1BC2A8 - 1, v10 + *(int16_t *)(dword_1BC2A8 + 2) - 1);
    }
    switch ( *(_BYTE *)(dword_1BC2A8 + 11) & 3 )
    {
      case 0:
        sub_A53DC(a1, a2, v16, v15);
        goto LABEL_16;
      case 1:
        v12 = aRemapDrawNotSu;
        goto LABEL_23;
      case 2:
        v12 = aRemapDrawNotSu_0;
        goto LABEL_23;
      case 3:
        goto LABEL_22;
      default:
        goto LABEL_16;
    }
  }
  if ( !word_1845DA )
  {
    if ( dword_1BBA28 >= 2 )
    {
      v10 = a2;
      sub_138CEE(a1, a2, v19, v17);
    }
    switch ( *(_BYTE *)(dword_1BC2A8 + 11) & 3 )
    {
      case 0:
        sub_A54F2(a1, a2, v16, v15);
        return;
      case 1:
        sub_126487(aRemapDrawNotSu_2, v10);
      case 2:
        sub_126487(aRemapDrawNotSu_3, v10);
      case 3:
LABEL_22:
        v12 = aRemapDrawNotSu_1;
LABEL_23:
        sub_126487(v12, v10);
      default:
        break;
    }
  }
LABEL_16:
  v11 = dword_1BC2A8;
  ++*(_WORD *)(dword_19D224 + 4);
  ++*(_WORD *)(v11 + 4);
  if ( (*(_BYTE *)(v11 + 11) & 0x20) == 0 )
  {
    if ( *(_WORD *)(v11 + 4) < *(_WORD *)(v11 + 6) )
      goto LABEL_36;
    v13 = *(uint8_t *)(v11 + 8);
    goto LABEL_35;
  }
  if ( *(uint8_t *)(v11 + 8) < *(int16_t *)(v11 + 4) )
  {
    if ( *(int16_t *)(v11 + 4) == *(uint8_t *)(v11 + 8) + 1 )
    {
      *(_WORD *)(v11 + 4) = 0;
      goto LABEL_36;
    }
    if ( *(_WORD *)(v11 + 4) < *(_WORD *)(v11 + 6) )
      goto LABEL_36;
    v13 = *(_WORD *)(v11 + 6) - 1;
LABEL_35:
    *(_WORD *)(v11 + 4) = v13;
  }
LABEL_36:
  if ( (*(_BYTE *)(dword_19D224 + 11) & 0x20) == 0 )
  {
    if ( *(_WORD *)(dword_19D224 + 4) < *(_WORD *)(dword_19D224 + 6) )
      return;
    v14 = *(uint8_t *)(dword_19D224 + 8);
    goto LABEL_44;
  }
  if ( *(uint8_t *)(dword_19D224 + 8) >= *(int16_t *)(dword_19D224 + 4) )
    return;
  if ( *(int16_t *)(dword_19D224 + 4) == *(uint8_t *)(dword_19D224 + 8) + 1 )
  {
    *(_WORD *)(dword_19D224 + 4) = 0;
    return;
  }
  if ( *(_WORD *)(dword_19D224 + 4) >= *(_WORD *)(dword_19D224 + 6) )
  {
    v14 = *(_WORD *)(dword_19D224 + 6) - 1;
LABEL_44:
    *(_WORD *)(dword_19D224 + 4) = v14;
  }
}
// A530C: variable 'v19' is possibly undefined
// A5308: variable 'v17' is possibly undefined
// 1845D8: using guessed type int16_t word_1845D8;
// 1845DA: using guessed type int16_t word_1845DA;
// 19D224: using guessed type int dword_19D224;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (000A53DC) --------------------------------------------------------
void __fastcall sub_A53DC( int a1, int a2, int a3, int a4)
{
  int v5; // ecx
  int v6; // ebx
  int16_t *v7; // eax
  int16_t v8; // dx
  int16_t v9; // ax
  uint8_t *v10; // eax
  char v11; // dl
  int v13; // [esp+Ch] [ebp-28h]
  int v14; // [esp+10h] [ebp-24h]
  int v15; // [esp+14h] [ebp-20h]
  int v16; // [esp+18h] [ebp-1Ch]
  int v17; // [esp+1Ch] [ebp-18h]
  int16_t v18; // [esp+20h] [ebp-14h]
  int16_t v19; // [esp+24h] [ebp-10h]
  int16_t v20; // [esp+28h] [ebp-Ch]
  int16_t v21; // [esp+2Ch] [ebp-8h]
  uint8_t v22; // [esp+30h] [ebp-4h]

  v18 = *(_WORD *)dword_1BC2A8;
  v20 = *(_WORD *)(dword_1BC2A8 + 2);
  v15 = *(uint16_t *)(a3 + 2);
  v5 = 2;
  v6 = a1 + (v15 + a2) * *(int *)((char *)&dword_184532 + 2);
  v17 = v6;
  while ( v20 > v15 )
  {
    v7 = (int16_t *)(a3 + 2 * v5);
    v5 += 2;
    v8 = *v7;
    v9 = v7[1];
    v19 = v8;
    v21 = v9;
    if ( v8 )
    {
      v6 += v9;
      v13 = 2 * v5;
      v16 = 0;
      v14 = v6 + v8;
      v10 = (uint8_t *)(a3 + 2 * v5);
      while ( v6 < v14 )
      {
        v22 = *(_BYTE *)(a4 + v16 + v18 * v15 + v21);
        if ( v22 )
          v11 = byte_19C714[256 * v22 + (uint8_t)byte_1BC79C[*v10]];
        else
          v11 = byte_1BC79C[*v10];
        *(_BYTE *)(v6 + dword_1BB904) = v11;
        ++v13;
        ++v16;
        ++v10;
        ++v6;
      }
      v5 += (v19 + 1) / 2;
    }
    else
    {
      v15 += v9;
      v17 += 640 * v9;
      v6 = v17;
    }
  }
  JUMPOUT(0xA53D8);
}
// A5428: control flows out of bounds to A53D8
// 184532: using guessed type int dword_184532;
// 1BB904: using guessed type int dword_1BB904;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (000A54F2) --------------------------------------------------------
void __fastcall sub_A54F2( int a1, int a2, int a3, int a4)
{
  int16_t v5; // bx
  int16_t v6; // ax
  int16_t v7; // cx
  int16_t v8; // dx
  int v9; // ecx
  int v10; // esi
  int v11; // edi
  int v12; // ebx
  int16_t *v13; // eax
  int v14; // edi
  int v15; // eax
  int16_t *v16; // eax
  int16_t v17; // dx
  int16_t v18; // ax
  int16_t v19; // ax
  int16_t v20; // ax
  char v21; // al
  int v23; // [esp+4h] [ebp-4Ch]
  int v24; // [esp+8h] [ebp-48h]
  uint8_t *v25; // [esp+Ch] [ebp-44h]
  int v26; // [esp+10h] [ebp-40h]
  int v27; // [esp+10h] [ebp-40h]
  int v29; // [esp+24h] [ebp-2Ch]
  int v30; // [esp+28h] [ebp-28h]
  int16_t v31; // [esp+2Ch] [ebp-24h]
  int16_t v32; // [esp+30h] [ebp-20h]
  int16_t v33; // [esp+34h] [ebp-1Ch]
  int16_t v34; // [esp+38h] [ebp-18h]
  int16_t v35; // [esp+40h] [ebp-10h]
  int16_t v36; // [esp+48h] [ebp-8h]
  uint8_t v37; // [esp+4Ch] [ebp-4h]

  v32 = *(_WORD *)dword_1BC2A8;
  if ( a1 < SHIWORD(dword_1BBA4A) )
  {
    v5 = HIWORD(dword_1BBA4A);
    v36 = HIWORD(dword_1BBA4A) - a1;
  }
  else
  {
    v36 = 0;
    v5 = a1;
  }
  if ( a2 < SHIWORD(dword_1BBA4E) )
  {
    v35 = HIWORD(dword_1BBA4E) - a2;
    v6 = HIWORD(dword_1BBA4E);
  }
  else
  {
    v35 = 0;
    v6 = a2;
  }
  v7 = a1 + v32 - 1;
  v8 = *(_WORD *)(dword_1BC2A8 + 2) + a2 - 1;
  if ( v7 >= (int16_t)dword_1BBA4E )
    v7 = dword_1BBA4E;
  v34 = v7 - v5 + 1;
  if ( v8 >= (int16_t)dword_1BBA52 )
    v8 = dword_1BBA52;
  v31 = v8 - v6 + 1;
  v9 = 2;
  v10 = *(int *)((char *)&dword_184532 + 2) * v6 + a1;
  v11 = *(uint16_t *)(a3 + 2);
  v12 = v10;
  while ( v11 < v35 )
  {
    v13 = (int16_t *)(a3 + 2 * v9);
    if ( *v13 )
      v9 += (*v13 + 1) / 2;
    else
      v11 += (uint16_t)v13[1];
    v9 += 2;
  }
  if ( v11 > v35 )
  {
    v10 += *(int *)((char *)&dword_184532 + 2) * (v11 - v35);
    v12 = v10;
  }
  v14 = v11 - v35;
  v15 = v36;
  while ( 1 )
  {
    v23 = v10 + v15;
    v24 = v10 + v34 + v15;
    while ( 1 )
    {
      if ( v14 >= v31 )
        JUMPOUT(0xA53D8);
      v16 = (int16_t *)(a3 + 2 * v9);
      v9 += 2;
      v17 = *v16;
      v18 = v16[1];
      v33 = v18;
      if ( !v17 )
        break;
      v12 += v18;
      v29 = 2 * v9;
      v30 = 0;
      v26 = v12 + v17;
      if ( v12 < v24 )
      {
        if ( v12 < v23 )
        {
          v19 = v23 - v12;
          if ( (int16_t)(v23 - v12) > v17 )
            v19 = v17;
          v29 += v19;
          v30 = v19;
          v12 += v19;
        }
        v20 = v24 - v12;
        if ( v12 + (int16_t)(v24 - v12) >= v26 )
          v20 = v26 - v12;
        v27 = v12 + v20;
        v25 = (uint8_t *)(a3 + v29);
        while ( v12 < v27 )
        {
          v37 = *(_BYTE *)(a4 + v30 + v33 + v14 * v32);
          if ( v37 )
            v21 = byte_19C714[256 * v37 + (uint8_t)byte_1BC79C[*v25]];
          else
            v21 = byte_1BC79C[*v25];
          *(_BYTE *)(v12 + dword_1BB904) = v21;
          ++v25;
          ++v29;
          ++v30;
          ++v12;
        }
      }
      v9 += (v17 + 1) / 2;
    }
    v14 += v18;
    v10 += 640 * v18;
    v15 = v36;
    v12 = v10;
  }
}
// A561D: control flows out of bounds to A53D8
// 184532: using guessed type int dword_184532;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (000A573B) --------------------------------------------------------
void __usercall sub_A573B(
        int a1, int a2,
        int a3, int a4, int a5, int a6)
{
  int v6; // eax
  int16_t v7; // ax
  int16_t v8; // [esp+4h] [ebp-10h] BYREF
  int v9; // [esp+8h] [ebp-Ch]
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  if ( word_199A08 )
  {
    if ( word_199A08 == 29 )
    {
      a6 = 318;
      a5 = 293;
      v11 = 180;
      a2 = 306;
      v10 = 17;
      a4 = 0;
      a3 = 0;
    }
  }
  else
  {
    a4 = 13;
    a3 = 47;
    LOWORD(a1) = word_192FE0[0];
    a6 = word_192FE2[0] - 26;
    v6 = a1 - 91;
    a2 = word_192FF4 + word_192FE4[0];
    v11 = v6;
    LOWORD(v6) = word_192FF6 + word_192FE6[0];
    a5 = word_192FE2[0] - 51;
    v10 = v6;
  }
  v9 = a3 + v10;
  sub_8FD71(&v8);
  sub_128AB6(22, 22, 527, 421);
  sub_12B634();
  sub_8EBBB(3);
  v7 = sub_103971(a5, byte_19D228, 3);
  sub_C5ED3((int16_t)(a4 + a2) + (a6 - v7) / 2, (int16_t)v9, a5, (uint16_t)v11, (int)byte_19D228, 3);
  sub_8FD56(v8);
  JUMPOUT(0xA20C6);
}
// A583F: control flows out of bounds to A20C6
// 103971: using guessed type int __fastcall sub_103971(_DWORD, _DWORD, _DWORD);
// 192FE0: using guessed type int16_t word_192FE0[];
// 192FE2: using guessed type int16_t word_192FE2[];
// 192FE4: using guessed type int16_t word_192FE4[];
// 192FE6: using guessed type int16_t word_192FE6[];
// 192FF4: using guessed type int16_t word_192FF4;
// 192FF6: using guessed type int16_t word_192FF6;
// 199A08: using guessed type int16_t word_199A08;


//----- (000A5844) --------------------------------------------------------
int __fastcall sub_A5844( int a1)
{
  int16_t v1; // ax
  int v2; // ebx
  int v3; // edx

  v1 = sub_77FF5(*(int16_t *)((char *)&word_1975D4 + 5 * word_1931C2[6 * a1]));
  if ( v1 < 8 )
  {
    v2 = dword_193174;
    v3 = *(uint8_t *)(3753 * v1 + dword_197F98 + 38) + 273;
    return sub_127C27((int)aBuffer0Lbx_4, v3, v2);
  }
  if ( v1 == 8 )
  {
    v3 = 281;
    v2 = dword_193174;
    return sub_127C27((int)aBuffer0Lbx_4, v3, v2);
  }
  if ( v1 < 15 )
  {
    v2 = dword_193174;
    v3 = (int16_t)(v1 - 9) + 282;
    return sub_127C27((int)aBuffer0Lbx_4, v3, v2);
  }
  return 0;
}
// A58A8: conditional instruction was optimized away because ax.2>=9
// 193174: using guessed type int dword_193174;
// 1931C2: using guessed type int16_t word_1931C2[];
// 1975D4: using guessed type int16_t word_1975D4;
// 197F98: using guessed type int dword_197F98;


//----- (000A58CE) --------------------------------------------------------
void __fastcall sub_A58CE( int a1, int a2, int16_t *a3, int16_t *a4, _WORD *a5, int a6, int a7)
{
  int16_t v7; // si
  int16_t v8; // dx
  int16_t v9; // ax
  _DWORD v12[3]; // [esp+10h] [ebp-14h]
  int16_t v13; // [esp+1Ch] [ebp-8h]
  int v14; // [esp+20h] [ebp-4h]

  v12[0] = 2621481;
  v12[1] = 1703944;
  v12[2] = *(int *)((char *)&dword_A1C68[1] + 2);
  v13 = HIWORD(dword_A1C68[2]);
  v14 = 0;
  v7 = 0;
  while ( 1 )
  {
    v8 = *((_WORD *)v12 + v7);
    if ( *(_BYTE *)(v8 + dword_192B18 + 361 * a1 + 310) )
    {
      if ( !(_WORD)v14 )
      {
        *a3 += sub_8F64C() + 3;
        *a5 += sub_8F64C() + 3;
      }
      *a3 += a6;
      if ( a7 )
      {
        sub_1212B3(a2, *a3, *(int *)((char *)&off_17EB3D + 19 * v8));
      }
      else
      {
        *a5 += a6;
        v9 = sub_12066F(*(int *)((char *)&off_17EB3D + 19 * v8));
        if ( v9 > *a4 )
          *a4 = v9;
      }
      ++v14;
    }
    if ( ++v7 >= 7 )
      JUMPOUT(0xA30BF);
  }
}
// A599C: control flows out of bounds to A30BF
// A1C68: using guessed type int[3];
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 192B18: using guessed type int dword_192B18;


//----- (000A59A1) --------------------------------------------------------
int16_t sub_A59A1()
{
  int v0; // edx
  _DWORD *v1; // eax
  int v2; // ebx
  _BOOL1 v3; // al
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  _DWORD *v7; // eax
  int v8; // edi
  _DWORD *v9; // eax
  int v10; // ecx
  int v11; // esi
  int v12; // eax
  int v13; // edx
  _DWORD *v14; // eax
  int v15; // edx
  int16_t v16; // ax
  int v17; // eax
  int v18; // eax
  int v19; // edi
  int v20; // ebx
  int v21; // edi
  int v22; // esi
  int v23; // ebx
  int v24; // esi
  int v25; // edi
  int v26; // edx
  int v27; // eax
  int16_t result; // ax
  int16_t v29; // [esp+0h] [ebp-2C46h]
  _BYTE v30[11256]; // [esp+4h] [ebp-2C42h] BYREF
  char v31[100]; // [esp+2BFCh] [ebp-4Ah] BYREF
  _BYTE v32[24]; // [esp+2C60h] [ebp+1Ah] BYREF
  _BYTE v33[8]; // [esp+2C78h] [ebp+32h] BYREF
  int v34; // [esp+2C80h] [ebp+3Ah]
  int v35; // [esp+2C84h] [ebp+3Eh]
  _WORD *v36; // [esp+2C88h] [ebp+42h]
  int16_t *v37; // [esp+2C8Ch] [ebp+46h]
  int v38; // [esp+2C90h] [ebp+4Ah]
  int v39; // [esp+2C94h] [ebp+4Eh]
  int v40; // [esp+2C98h] [ebp+52h] BYREF
  _DWORD *v41; // [esp+2C9Ch] [ebp+56h]
  int v42; // [esp+2CA0h] [ebp+5Ah] BYREF
  int v43; // [esp+2CA4h] [ebp+5Eh] BYREF
  int v44; // [esp+2CA8h] [ebp+62h]
  int v45; // [esp+2CACh] [ebp+66h] BYREF
  int v46; // [esp+2CB0h] [ebp+6Ah]
  int v47; // [esp+2CB4h] [ebp+6Eh] BYREF
  int v48; // [esp+2CB8h] [ebp+72h]
  int v49; // [esp+2CBCh] [ebp+76h] BYREF
  _BYTE v50[4]; // [esp+2CC0h] [ebp+7Ah] BYREF
  _BYTE v51[4]; // [esp+2CC4h] [ebp+7Eh] BYREF

  v51[0] = 0;
  v50[0] = 0;
  word_19D35E = 0;
  word_19D360 = 0;
  sub_A62E0(72500);
  sub_A64AB(0, v50, v51);
  qmemcpy(v33, sub_8E5C5(4u, v50[0], v51[0]), sizeof(v33));
  qmemcpy(v32, sub_8E5C5(2u, v50[0], v51[0]), 8u);
  sub_120940(4, (int)v33);
  sub_122259();
  sub_120940(2, (int)v32);
  v0 = 4172;
  sub_1112EC(dword_19D354, 4172);
  v37 = (int16_t *)sub_110D3C(dword_19D354, 4172);
  v39 = 0;
  v38 = v29;
  v48 = 0;
  sub_A6547(v31);
  do
  {
    sub_1112EC(dword_19D354, v0);
    v1 = sub_126C37((int)v31, 0, dword_19D354, (int16_t)v38, 1u, 1403);
    v34 = (uint16_t)v48;
    v2 = 1403 * (uint16_t)v48;
    qmemcpy(&v30[v2], v1, 0x57Bu);
    sub_103CAF(339, (int)&v30[v2 + 103]);
    v0 = v34;
    sub_1113CC(dword_19D354, v34);
    v3 = v30[v2 + 80] != 0;
    v32[v0 + 8] = v3;
    if ( v3 )
    {
      sub_13AD33(v37, (int)&v30[v2 + 80]);
      v0 = (uint16_t)*(_DWORD *)&v30[v2 + 94];
      v4 = sub_13AFD2((int)v37, v0);
      v39 += v4;
      v39 += 1024;
      sub_13AE74((int)v37);
    }
    if ( *(_DWORD *)&v30[1403 * (uint16_t)v48 + 99] == -1 )
      ++v38;
    else
      v38 = *(_DWORD *)&v30[1403 * (uint16_t)v48 + 99];
    ++v48;
  }
  while ( v38 && (uint16_t)v48 <= 8u );
  sub_1113CC(dword_19D354, v0);
  v5 = sub_111499(dword_19D354);
  if ( v5 < v39 )
  {
    v6 = v39 + 72500;
    sub_13B9BD(dword_19D354, v39 + 72500);
    v7 = sub_110CEE(dword_192ED4, v6);
    byte_19D36A = 1;
    dword_19D354 = (int)v7;
  }
  v8 = 11;
  v36 = sub_126B42((int)aTextboxLbx, 3, dword_19D354);
  v46 = 0;
  v9 = sub_110D3C(dword_19D354, 12500);
  dword_19D36B = (int)v9;
  do
  {
    v10 = (uint16_t)v46;
    v11 = 2 * (uint16_t)v46;
    v45 = 0;
    *(_WORD *)&v31[v11 + 36] = 339;
    *(_WORD *)&v31[v11 + 68] = v8;
    if ( v32[v10 + 8] )
    {
      LOWORD(v9) = *(_WORD *)&v30[1403 * v10 + 94];
      v41 = v9;
      v12 = *(_DWORD *)&v30[1403 * v10 + 94] & 0xFF0000;
      v35 = (int16_t)v41;
      v32[v10 + 16] = BYTE2(v12);
      v13 = v35;
      v35 = (int)&v30[1403 * v10 + 80];
      v14 = sub_126B42(v35, v13, dword_19D354);
      v15 = (uint8_t)v32[v10 + 16];
      *(_DWORD *)&v30[4 * v10 + 11224] = v14;
      sub_12B753((int)v14, v15);
      sub_12F578(dword_19D36B, *(_DWORD *)&v30[4 * v10 + 11224]);
      sub_131528((_WORD *)dword_19D36B, (int16_t *)&v40, (int16_t *)&v42, &v43, &v45);
      v16 = *(_WORD *)&v31[v11 + 68] - v42;
      *(_WORD *)&v31[v11 + 84] = 354 - (v40 + v43);
      *(_WORD *)&v31[v11 + 20] = v16;
      *(_WORD *)&v31[v11 + 36] = 339 - (v43 + 6);
    }
    sub_120BB5(4, (int)v33);
    v17 = 1403 * (uint16_t)v46;
    if ( v30[v17] == 20 )
      v18 = 0;
    else
      v18 = sub_103CAF(*(_WORD *)&v31[2 * (uint16_t)v46 + 36], (int)&v30[v17]);
    if ( (int16_t)v45 > 0 && (int16_t)v18 < (int16_t)v45 )
      v18 = v45;
    v19 = v18 + 4 + v8;
    if ( !(_WORD)v46 && (int16_t)v19 < 42 )
      v19 = 42;
    v20 = (uint16_t)v46;
    *(_WORD *)&v31[2 * (uint16_t)v46 + 52] = v19;
    sub_120BB5(2, (int)v32);
    ++v46;
    v21 = sub_103CAF(339, (int)&v30[1403 * v20 + 103]) + v19;
    HIWORD(v9) = HIWORD(v46);
    v8 = v21 + 8;
  }
  while ( (uint16_t)v46 < (uint16_t)v48 );
  v44 = 0;
  sub_A6166((int16_t *)&v49, &v47, (uint16_t)(v8 - 42));
  do
  {
    v22 = (uint16_t)v44;
    v23 = 1403 * (uint16_t)v44;
    if ( v30[v23] != 20 )
    {
      sub_120940(4, (int)v33);
      sub_103BC4(v49 + 20, *(_WORD *)&v31[2 * v22 + 68] + v47, *(_WORD *)&v31[2 * v22 + 36], (int)&v30[v23], 0);
      sub_120940(2, (int)v32);
    }
    v24 = (uint16_t)v44;
    v25 = 2 * (uint16_t)v44;
    sub_103BC4(v49 + 20, *(_WORD *)&v31[v25 + 52] + v47, 339, (int)&v30[1403 * (uint16_t)v44 + 103], 0);
    if ( v32[v24 + 8] )
    {
      sub_12B753(*(_DWORD *)&v30[4 * v24 + 11224], (uint8_t)v32[v24 + 16]);
      sub_12A478(*(_WORD *)&v31[v25 + 84] + v49, *(_WORD *)&v31[v25 + 20] + v47, *(_DWORD *)&v30[4 * v24 + 11224]);
    }
    ++v44;
  }
  while ( (uint16_t)v44 < (uint16_t)v48 );
  sub_124DEC();
  sub_11438B(0, 0, 639, 479, asc_179D48, 41);
  sub_A644D(0, 1);
  sub_12B753((int)v36, 1);
  v26 = (int16_t)(word_19D35C - 27);
  v27 = sub_12B7E1((int16_t)(v49 + 158), v26, v36);
  result = sub_A63DD(v27, v26);
  word_19994C = 1;
  return result;
}
// A5A6B: variable 'v29' is possibly undefined
// A644D: using guessed type int __fastcall sub_A644D(_DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 19D354: using guessed type int dword_19D354;
// 19D35C: using guessed type int16_t word_19D35C;
// 19D35E: using guessed type int16_t word_19D35E;
// 19D360: using guessed type int16_t word_19D360;
// 19D36A: using guessed type char byte_19D36A;
// 19D36B: using guessed type int dword_19D36B;


//----- (000A5EB2) --------------------------------------------------------
int16_t __fastcall sub_A5EB2(int a1, int a2)
{
  return sub_A5EBF(a1, a2, 0);
}


//----- (000A5EBF) --------------------------------------------------------
int16_t __fastcall sub_A5EBF(int a1, int a2, int a3)
{
  int v3; // eax
  int16_t v4; // bx
  int v5; // eax
  int16_t v6; // dx
  int16_t v7; // bx
  int16_t v8; // bx
  int v9; // esi
  int v10; // edi
  int v11; // edx
  int v12; // eax
  int16_t result; // ax
  _BYTE v17[8]; // [esp+Ch] [ebp-44h] BYREF
  _BYTE v18[8]; // [esp+14h] [ebp-3Ch] BYREF
  int v19; // [esp+1Ch] [ebp-34h]
  _WORD *v20; // [esp+20h] [ebp-30h]
  int v21; // [esp+24h] [ebp-2Ch]
  int v22; // [esp+28h] [ebp-28h] BYREF
  int16_t v23; // [esp+2Ch] [ebp-24h] BYREF
  int v24; // [esp+30h] [ebp-20h]
  int v25; // [esp+34h] [ebp-1Ch]
  int v26; // [esp+38h] [ebp-18h]
  int v27; // [esp+3Ch] [ebp-14h] BYREF
  int v28; // [esp+40h] [ebp-10h]
  _BYTE v29[4]; // [esp+44h] [ebp-Ch] BYREF
  _BOOL1 v30; // [esp+48h] [ebp-8h]
  _BYTE v31[4]; // [esp+4Ch] [ebp-4h] BYREF

  v27 = 0;
  v22 = 0;
  v29[0] = 0;
  v30 = a1 != 0;
  v31[0] = 0;
  sub_A64AB(0, v31, v29);
  sub_A62E0(60000);
  qmemcpy(v17, sub_8E5C5(5u, v31[0], v29[0]), sizeof(v17));
  qmemcpy(v18, sub_8E5C5(3u, v31[0], v29[0]), sizeof(v18));
  sub_120BB5(3, (int)v17);
  v21 = sub_103CAF(339, a2);
  if ( sub_103D0C() >= 339 )
    v3 = 339;
  else
    v3 = sub_103D0C();
  v26 = v3;
  sub_A6166((int16_t *)&v27, &v22, (uint16_t)v21);
  v20 = sub_126B42((int)aTextboxLbx, 3, dword_19D354);
  if ( v30 )
  {
    sub_120940(5, (int)v17);
    v25 = v27 + 190;
    v28 = v22 + 11;
    sub_12066F(a1);
    sub_8FDA1(a1, (int)v17, 5, 2, -1, 380, 3);
    v4 = sub_8F64C();
    LOWORD(v5) = sub_8F645();
    v24 = v5;
    v19 = v4;
    qmemcpy(v17, sub_8E5C5(v4, v31[0], v29[0]), sizeof(v17));
    sub_120940(v19, (int)v17);
    v6 = v28;
    sub_120E8C(v24);
    sub_1210FD(v25, v6, a1);
  }
  v7 = v21;
  sub_120940(3, (int)v18);
  v8 = v7 + 43;
  LOWORD(v9) = v27 + 20;
  LOWORD(v10) = v22 + 42;
  if ( !v30 )
  {
    v9 = (int16_t)v27 + 8 + (362 - (uint16_t)v26) / 2;
    v10 = (int16_t)v22 + 12 + (v8 - (uint16_t)v21) / 2;
  }
  sub_8FD71(&v23);
  sub_128AB6(v27 + 20, v22 + 42, v27 + 359, (int16_t)(v22 + 418));
  sub_12B634();
  sub_103BC4(v9, v10, v26, a2, 0);
  sub_8FD56(v23);
  sub_124DEC();
  sub_11438B(0, 0, 639, 479, asc_179D48, 41);
  sub_A644D(a3, 1, 639, 479);
  sub_12B753((int)v20, 1);
  v11 = (int16_t)(word_19D35C - 27);
  v12 = sub_12B7E1((int16_t)(v27 + 158), v11, v20);
  result = sub_A63DD(v12, v11);
  word_19994C = 1;
  return result;
}
// A5EBF: could not find valid save-restore pair for ebx
// A6007: variable 'v5' is possibly undefined
// 19994C: using guessed type int16_t word_19994C;
// 19D354: using guessed type int dword_19D354;
// 19D35C: using guessed type int16_t word_19D35C;


//----- (000A6166) --------------------------------------------------------
int __fastcall sub_A6166(int16_t *a1, _WORD *a2, int a3)
{
  int16_t v4; // cx
  int v5; // eax
  int v6; // edi
  _WORD *v7; // ebx
  int result; // eax
  _WORD *v9; // [esp+0h] [ebp-20h]
  _WORD *v10; // [esp+0h] [ebp-20h]
  int v11; // [esp+4h] [ebp-1Ch]
  int16_t v12; // [esp+8h] [ebp-18h] BYREF
  int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  int v16; // [esp+18h] [ebp-8h]
  int v17; // [esp+1Ch] [ebp-4h]

  v17 = 42;
  v14 = 43;
  v13 = a3;
  v4 = a3 + 85;
  if ( word_199A08 )
  {
    *a1 = 130;
    v5 = (480 - v4) / 2;
  }
  else
  {
    *a1 = 84;
    v5 = (400 - v4) / 2 + 21;
    if ( v5 <= 5 )
      v5 = 5;
  }
  *a2 = v5;
  LOWORD(v5) = *a2;
  v16 = v5;
  v9 = (_WORD *)sub_127C27((int)aTextboxLbx, 0, dword_193174);
  sub_133C9C((int)v9, 0);
  sub_129130(
    (int16_t)(*a1 + 5),
    (int16_t)(*a2 + 5),
    (int16_t)(*a1 + 375),
    (int16_t)(*a2 + v4 - 5),
    (uint8_t)byte_1BC79E,
    (uint8_t)byte_1BC79F,
    (uint8_t)byte_1BC7A0);
  sub_12B7E1(*a1, (int16_t)v16, v9);
  v16 += v17;
  v10 = (_WORD *)sub_127C27((int)aTextboxLbx, 1, dword_193174);
  sub_8FD71(&v12);
  v15 = v13 + v16;
  v6 = (int16_t)v16;
  v11 = (int16_t)(v13 + v16);
  sub_128AB6(*a1, v16, *a1 + 380, v11);
  sub_12B634();
  sub_12B7E1(*a1, v6, v10);
  sub_8FD56(v12);
  v7 = (_WORD *)sub_127C27((int)aTextboxLbx, 2, dword_193174);
  sub_12B7E1(*a1, v11, v7);
  result = v14 + v15;
  word_19D35C = v14 + v15;
  return result;
}
// 193174: using guessed type int dword_193174;
// 199A08: using guessed type int16_t word_199A08;
// 19D35C: using guessed type int16_t word_19D35C;
// 1BC79E: using guessed type char byte_1BC79E;
// 1BC79F: using guessed type char byte_1BC79F;
// 1BC7A0: using guessed type char byte_1BC7A0;


//----- (000A62E0) --------------------------------------------------------
int __fastcall sub_A62E0(int a1)
{
  _DWORD *v2; // eax
  int v3; // eax

  sub_7A795();
  sub_123E6C((int)&unk_17CF00, 1);
  word_19D364 = word_1844D8;
  word_1844D8 = 0;
  sub_107AF(&dword_19D358);
  sub_119281();
  sub_124C08();
  sub_107C2(&dword_19D358);
  word_19D366 = dword_1844E6;
  sub_1172FC();
  sub_11E718();
  sub_1172D4();
  sub_10FE41((int)&unk_19D330 + 18 * (uint16_t)word_182433);
  ++word_182433;
  if ( a1 <= sub_111499(dword_192ED4) - 512 )
  {
    sub_1112EC(dword_192ED4, 1);
    byte_19D36A = 0;
    v2 = sub_110D3C(dword_192ED4, a1 + 384);
  }
  else
  {
    sub_13B9BD(dword_192ED4, a1 + 512);
    v2 = sub_110CEE(dword_192ED4, a1 + 384);
    byte_19D36A = 1;
  }
  dword_19D354 = (int)v2;
  v3 = sub_127C27((int)aTextboxLbx, 0, dword_193174);
  return sub_133C9C(v3, 0);
}
// 182433: using guessed type int16_t word_182433;
// 1844D8: using guessed type int16_t word_1844D8;
// 1844E6: using guessed type int dword_1844E6;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 19D354: using guessed type int dword_19D354;
// 19D358: using guessed type int (*dword_19D358)(void);
// 19D364: using guessed type int16_t word_19D364;
// 19D366: using guessed type int16_t word_19D366;
// 19D36A: using guessed type char byte_19D36A;


//----- (000A63DD) --------------------------------------------------------
int16_t __fastcall sub_A63DD(int a1, int a2)
{
  sub_1077D();
  --word_182433;
  sub_10FEC1((int)&unk_19D330);
  sub_1172FC();
  if ( byte_19D36A )
    sub_13BA86();
  else
    sub_1113CC(dword_192ED4, a2);
  sub_107BA((int *)&dword_19D358);
  sub_1192A9();
  sub_119441();
  sub_117174(3);
  word_1844D8 = word_19D364;
  LOWORD(dword_1844E6) = word_19D366;
  return sub_7A7CF();
}
// 1077D: using guessed type int sub_1077D(void);
// 182433: using guessed type int16_t word_182433;
// 1844D8: using guessed type int16_t word_1844D8;
// 1844E6: using guessed type int dword_1844E6;
// 192ED4: using guessed type int dword_192ED4;
// 19D358: using guessed type int (*dword_19D358)(void);
// 19D364: using guessed type int16_t word_19D364;
// 19D366: using guessed type int16_t word_19D366;
// 19D36A: using guessed type char byte_19D36A;


//----- (000A644D) --------------------------------------------------------
int16_t __fastcall sub_A644D( int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int16_t result; // ax

  if ( a1 )
  {
    sub_120486(a1);
    sub_119441();
    return sub_117174(3);
  }
  else
  {
    while ( sub_124075() )
    {
      sub_12C2A0();
      sub_1077D();
      sub_12C2C6(1);
    }
    sub_119441();
    do
    {
      sub_12C2A0();
      sub_1077D();
      v4 = sub_12C2C6(1);
      result = sub_1171AB(v4, a2, a3, a4);
    }
    while ( !result );
  }
  return result;
}
// 1077D: using guessed type int sub_1077D(void);


//----- (000A64AB) --------------------------------------------------------
char __fastcall sub_A64AB( unsigned int a1, _BYTE *a2, _BYTE *a3)
{
  char v3; // cl
  _BOOL1 v4; // zf
  char v5; // al
  char v6; // cl
  char result; // al

  if ( !a1 )
    goto LABEL_4;
  if ( a1 <= 1u )
  {
    v3 = byte_182436;
  }
  else
  {
    if ( a1 != 2 )
    {
LABEL_4:
      v3 = byte_182435;
      goto LABEL_7;
    }
    v3 = byte_182437;
  }
LABEL_7:
  if ( (uint16_t)word_199A08 < 0xAu )
  {
    if ( !word_199A08 )
    {
LABEL_22:
      v5 = 0;
      goto LABEL_23;
    }
    if ( (uint16_t)word_199A08 <= 1u )
      goto LABEL_20;
    if ( word_199A08 != 9 )
      goto LABEL_22;
    v5 = 3;
  }
  else
  {
    if ( (uint16_t)word_199A08 > 0xAu )
    {
      if ( (uint16_t)word_199A08 < 0x19u )
      {
        v4 = word_199A08 == 20;
      }
      else
      {
        if ( (uint16_t)word_199A08 <= 0x19u )
        {
LABEL_20:
          v5 = 2;
          goto LABEL_23;
        }
        v4 = word_199A08 == 33;
      }
      if ( !v4 )
        goto LABEL_22;
      goto LABEL_20;
    }
    v5 = 1;
  }
LABEL_23:
  v6 = 3 * v5 + v3;
  *a2 = v6;
  result = v6 + 2;
  *a3 = v6 + 2;
  return result;
}
// 182435: using guessed type char byte_182435;
// 182436: using guessed type char byte_182436;
// 182437: using guessed type char byte_182437;
// 199A08: using guessed type int16_t word_199A08;


//----- (000A6547) --------------------------------------------------------
char *__fastcall sub_A6547(char *a1)
{
  char *v1; // edi
  char *result; // eax
  char *v3; // kr00_4
  char *v4; // esi
  char *v5; // edi
  char *v6; // esi

  v1 = a1;
  LOBYTE(a1) = byte_199CAE;
  v3 = a1;
  result = (char *)(uint8_t)byte_199CAE;
  switch ( byte_199CAE )
  {
    case 1:
      v4 = aGerHelpLbx;
      goto LABEL_6;
    case 2:
      v4 = aFreHelpLbx;
      goto LABEL_6;
    case 3:
      v4 = aSpaHelpLbx;
      goto LABEL_6;
    case 4:
      v4 = aItaHelpLbx;
LABEL_6:
      *(_DWORD *)v1 = *(_DWORD *)v4;
      v6 = v4 + 4;
      v5 = v1 + 4;
      *(_DWORD *)v5 = *(_DWORD *)v6;
      v6 += 4;
      v5 += 4;
      *(_DWORD *)v5 = *(_DWORD *)v6;
      v5[4] = v6[4];
      break;
    default:
      result = v3;
      strcpy(v1, "HELP.LBX");
      break;
  }
  return result;
}
// 199CAE: using guessed type char byte_199CAE;


//----- (000A6A2E) --------------------------------------------------------
int __fastcall sub_A6A2E(int16_t *a1, int16_t *a2, int a3, int a4, int a5)
{
  int v7; // edx
  int result; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // ebx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // [esp+4h] [ebp-10h]
  int v18; // [esp+8h] [ebp-Ch]
  int v19; // [esp+Ch] [ebp-8h]
  int v20; // [esp+10h] [ebp-4h]

  v7 = a3 - *a1;
  v17 = 0;
  v18 = 0;
  result = a4 - *a2;
  v19 = v7;
  v20 = result;
  if ( (int16_t)a5 >= 1 )
  {
    if ( v7 >= 0 )
      v9 = v7;
    else
      v9 = -v7;
    if ( v20 >= 0 )
      v10 = a4 - *a2;
    else
      v10 = *a2 - a4;
    if ( v9 >= v10 )
    {
      if ( v19 >= 0 )
      {
        result = v19;
        goto LABEL_16;
      }
      v11 = v19;
    }
    else
    {
      if ( v20 >= 0 )
      {
        result = a4 - *a2;
        goto LABEL_16;
      }
      v11 = a4 - *a2;
    }
    result = -v11;
LABEL_16:
    if ( result <= (int16_t)a5 )
    {
      *a1 = a3;
      *a2 = a4;
      return result;
    }
    if ( !v19 )
    {
      result = a5;
      if ( v20 <= 0 )
        *a2 -= a5;
      else
        *a2 += a5;
      return result;
    }
    if ( !v20 )
    {
      result = a5;
      if ( v19 <= 0 )
        *a1 -= a5;
      else
        *a1 += a5;
      return result;
    }
    v12 = v19 >> 1;
    v13 = v20 >> 1;
    while ( 1 )
    {
      if ( v12 >= 0 )
        v14 = v12;
      else
        v14 = -v12;
      if ( v13 >= 0 )
        v15 = v13;
      else
        v15 = -v13;
      if ( v14 >= v15 )
      {
        if ( v12 < 0 )
        {
          v16 = v12;
          goto LABEL_36;
        }
        result = v12;
      }
      else
      {
        if ( v13 < 0 )
        {
          v16 = v13;
LABEL_36:
          result = -v16;
          goto LABEL_41;
        }
        result = v13;
      }
LABEL_41:
      if ( result == (int16_t)a5 )
      {
        *a1 += v12;
        *a2 += v13;
        return result;
      }
      if ( result <= (int16_t)a5 )
      {
        v17 = v12;
        v12 += (v19 - v12) / 2;
        v18 = v13;
        v13 += (v20 - v13) / 2;
      }
      else
      {
        v19 = v12;
        v12 -= (v12 - v17) / 2;
        v20 = v13;
        v13 -= (v13 - v18) / 2;
      }
    }
  }
  return result;
}


//----- (000A6B95) --------------------------------------------------------
int16_t sub_A6B95()
{
  return word_182473;
}
// 182473: using guessed type int16_t word_182473;


//----- (000A6B9C) --------------------------------------------------------
char __fastcall sub_A6B9C(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5, int a6, int a7, int a8, int a9, int a10,
        int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25,
        int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33,
        _DWORD *a34)
{
  int16_t v34; // ax
  int v35; // eax
  int v36; // edi
  int16_t v37; // ax
  int v38; // eax
  unsigned int v39; // ebx
  unsigned int v40; // edx
  unsigned int v41; // eax
  unsigned int v42; // edx
  unsigned int v43; // eax
  int v44; // eax
  unsigned int v45; // eax
  int v46; // edx
  unsigned int v47; // eax
  int v48; // eax
  uint16_t v49; // ax
  int v50; // eax
  int v51; // eax
  int v52; // edx
  int v53; // ebx
  int16_t v54; // ax
  int v55; // ebx
  int v56; // ebx
  int16_t v57; // ax
  int16_t v58; // ax
  int v59; // ebx
  int v60; // ebx
  int16_t v61; // dx
  int16_t v62; // cx
  int16_t v63; // bx
  int16_t v65; // [esp-10h] [ebp-40h]
  int16_t v66; // [esp-Ch] [ebp-3Ch]
  int16_t v67; // [esp-8h] [ebp-38h]
  int16_t v68; // [esp-4h] [ebp-34h]
  int v69; // [esp+4h] [ebp-2Ch] BYREF
  int v70; // [esp+8h] [ebp-28h] BYREF
  int v71; // [esp+Ch] [ebp-24h] BYREF
  int v72; // [esp+10h] [ebp-20h] BYREF
  int v73; // [esp+14h] [ebp-1Ch]
  int v74; // [esp+18h] [ebp-18h]
  int v75; // [esp+1Ch] [ebp-14h]
  int v76; // [esp+20h] [ebp-10h]
  int v77; // [esp+24h] [ebp-Ch]
  int v78; // [esp+28h] [ebp-8h]
  int v79; // [esp+2Ch] [ebp-4h]

  v75 = a1;
  v76 = a2;
  v78 = a3;
  v77 = a4;
  v34 = sub_1384B9((int16_t)a1 - (int16_t)a3, (int16_t)a4 - (int16_t)a2);
  HIWORD(v35) = (unsigned int)((v34 / 22 + 8) / 16) >> 16;
  byte_18243F[0] = 0;
  byte_182440 = 0;
  v73 = (v34 / 22 + 8) % 16;
  LOWORD(v35) = a8 != 144;
  v74 = v35;
  v36 = sub_A7342((int16_t)v75, (int16_t)a2, (int16_t)a3, (int16_t)a4);
  if ( a33 == -1 )
  {
    v37 = a7;
    a21 = 0;
    if ( (unsigned int)a7 > 0x14 )
      v37 = 20;
    a11 = 5;
    a31 = 1;
    a7 = v37;
  }
  v38 = a33;
  LOWORD(v39) = (a33 != -1) + 2;
  if ( a34 )
  {
    a7 = *((_WORD *)a34 + 16);
    LOWORD(v38) = *((_WORD *)a34 + 18);
    a11 = v38;
  }
  if ( (unsigned int)a7 >= 0x3C )
    v40 = a7;
  else
    v40 = 60;
  v41 = (int16_t)v36;
  if ( v40 <= (int16_t)v36 )
  {
    v41 = a7;
    if ( (unsigned int)a7 < 0x3C )
      v41 = 60;
  }
  v42 = ((int16_t)v36 + v41) / (int16_t)a11;
  LOWORD(v41) = (a33 != -1) + 2;
  if ( (int16_t)v39 < v42 )
  {
    v43 = a7;
    if ( (unsigned int)a7 < 0x3C )
      v43 = 60;
    if ( v43 <= (int16_t)v36 )
    {
      v44 = a7;
      if ( (unsigned int)a7 < 0x3C )
        v44 = 60;
    }
    else
    {
      v44 = (int16_t)v36;
    }
    v41 = ((int16_t)v36 + v44) / (unsigned int)(int16_t)a11;
  }
  word_182473 = v41;
  if ( (int16_t)v41 > 6 )
    a11 *= 2;
  v45 = a7;
  if ( (unsigned int)a7 < 0x3C )
    v45 = 60;
  v46 = (int16_t)v36;
  if ( v45 <= (int16_t)v36 )
  {
    v46 = a7;
    if ( (unsigned int)a7 < 0x3C )
      v46 = 60;
  }
  if ( (int16_t)v39 < (v46 + (int16_t)v36) / (unsigned int)(int16_t)a11 )
  {
    v47 = a7;
    if ( (unsigned int)a7 < 0x3C )
      v47 = 60;
    if ( v47 <= (int16_t)v36 )
    {
      v48 = a7;
      if ( (unsigned int)a7 < 0x3C )
        v48 = 60;
    }
    else
    {
      v48 = (int16_t)v36;
    }
    v39 = ((int16_t)v36 + v48) / (unsigned int)(int16_t)a11;
  }
  LOBYTE(v49) = a26;
  word_182473 = v39;
  if ( (int16_t)a26 < (int16_t)v39 )
  {
    if ( !(_WORD)a26 && a33 != -1 )
    {
      LOBYTE(v49) = sub_A7364(v75, v76, v73, a31, 0, v74);
      return v49;
    }
    v79 = a11 * a26;
    if ( a34 && a34[7] == 2 )
      v79 = v36;
    if ( (v79 & 0x8000u) != 0 )
      v79 = 0;
    if ( (int16_t)v36 < (int16_t)v79 )
      v79 = v36;
    v71 = v75;
    v69 = v76;
    sub_A6A2E((int16_t *)&v71, (int16_t *)&v69, v78, v77, (int16_t)v79);
    if ( (_WORD)v71 == (_WORD)v78 && (_WORD)v69 == (_WORD)v77 || (int16_t)a26 >= word_182473 - 2 )
    {
      byte_18243F[(int16_t)v74] = 1;
      v71 += sub_1247A0(3u) - 1;
      v69 += sub_1247A0(3u) - 1;
    }
    else
    {
      byte_18243F[(int16_t)v74] = 0;
    }
    v71 = v75;
    v69 = v76;
    if ( !a28 || a29 || byte_182438 || a33 == -1 )
    {
      if ( a32 != 1 || a29 || byte_182438 || a33 == -1 )
      {
        byte_182438 = 1;
        LOWORD(v51) = 0;
LABEL_64:
        v52 = a7 - 1;
        if ( (int16_t)v51 <= v52 )
          v52 = (int16_t)v51;
        v79 = (int16_t)v79 - v52;
        sub_A6A2E((int16_t *)&v71, (int16_t *)&v69, v78, v77, (int16_t)v79);
        v70 = v75;
        LOWORD(v53) = a11 * a26 - a7;
        v72 = v76;
        if ( (v53 & 0x8000u) != 0 )
          LOWORD(v53) = 0;
        if ( (int16_t)v53 > (int16_t)v36 )
          LOWORD(v53) = v36;
        if ( a34 && a34[7] == 2 )
          LOWORD(v53) = 0;
        if ( a32 == 2 )
        {
          if ( a33 >= 0 )
            v54 = a33;
          else
            v54 = 0;
          v53 = (uint8_t)byte_182485[sub_A9AAD(v54)] / 3 + (int16_t)v53;
        }
        if ( (_WORD)v53 )
          sub_A6A2E((int16_t *)&v70, (int16_t *)&v72, v78, v77, (int16_t)v53);
        if ( a19 && !a34 )
        {
          v55 = v70;
          v70 = v71;
          v71 = v55;
          v56 = v72;
          v72 = v69;
          v69 = v56;
        }
        if ( a34 )
        {
          if ( a32 == 2 )
          {
            v75 = v70;
            v76 = v72;
          }
          sub_AB52E(
            (int16_t)v75,
            v76,
            v78,
            v77,
            (int16_t)v70,
            (int16_t)v72,
            (int16_t)v71,
            (int16_t)v69,
            a28 == 0,
            (int16_t)a26,
            a8,
            *a34,
            a34[1],
            a34[2],
            a34[3],
            a34[4],
            a34[5],
            a34[6],
            a34[7],
            a34[8],
            a34[9],
            a34[10]);
          goto LABEL_103;
        }
        if ( (_WORD)v70 == (_WORD)v71 && (_WORD)v72 == (_WORD)v69 )
        {
LABEL_103:
          if ( a19 && !a34 )
          {
            v59 = v70;
            v70 = v71;
            v71 = v59;
            v60 = v72;
            v72 = v69;
            v69 = v60;
          }
          if ( (int16_t)a26 < 3 || (_WORD)v70 == (_WORD)v75 && (_WORD)v72 == (_WORD)v76 )
          {
            if ( a33 != -1 )
              sub_A7364(v75, v76, v73, a31, a26, v74);
            byte_182441[(int16_t)v74] = 1;
          }
          else
          {
            byte_182441[(int16_t)v74] = 0;
          }
          LOBYTE(v49) = v74;
          if ( byte_18243F[(int16_t)v74] )
          {
            LOBYTE(v49) = a33;
            if ( a33 != -1 )
            {
              v61 = (int16_t)a26 >= word_182473 - 1
                  ? 7 - (word_182473 - a26)
                  : ((int16_t)a26 - ((int16_t)v36 + 10) / (int16_t)a11 - 1) % 5;
              v49 = abs16(v61);
              if ( a29 || a28 )
              {
                if ( a30 )
                {
                  v62 = v49;
                  v63 = 0;
                }
                else
                {
                  v63 = a6;
                  v62 = v49;
                }
                LOBYTE(v49) = sub_A73B7(v78, v77, v63, v62, v74);
              }
            }
          }
          byte_18243D = a28 && (LOBYTE(v49) = sub_A96C7(v71, v69, v78, v77, a27), (_BYTE)v49);
          byte_18243E = a32 == 1 && (LOBYTE(v49) = sub_AA55B(v71, v69, v78, v77, a27), (_BYTE)v49);
          return v49;
        }
        switch ( a21 )
        {
          case 1:
            v68 = a25;
            v67 = a24;
            v66 = a23;
            v65 = a22;
LABEL_96:
            sub_13BAFB(
              v70,
              v72,
              v71,
              v69,
              a8,
              word_182475,
              a9,
              a10,
              a12,
              a13,
              a14,
              a15,
              a16,
              a17,
              a18,
              v65,
              v66,
              v67,
              v68);
            break;
          case 2:
            sub_13C22C(
              v70,
              v72,
              v71,
              v69,
              a8,
              word_182475,
              a9,
              a10,
              a12,
              a13,
              a14,
              a15,
              a16,
              a17,
              a18,
              a22,
              a23,
              (a24 + a22) / 2,
              (a23 + a25) / 2,
              a24,
              a25);
            break;
          case 0:
            v57 = a25;
            if ( a25 < a23 )
              v57 = a23;
            v68 = v57;
            v58 = a24;
            if ( a24 < a22 )
              v58 = a22;
            v67 = v58;
            v66 = 0;
            v65 = 0;
            goto LABEL_96;
        }
        if ( a20 && !byte_18243F[(int16_t)v74] )
          sub_C5CFF(v71, v69, (int16_t *)dword_19D5BC);
        goto LABEL_103;
      }
      v50 = (uint8_t)byte_182485[sub_A9AAD(a27)];
    }
    else
    {
      v50 = (uint8_t)byte_182477[sub_A9AAD(a27)];
    }
    v51 = v50 / 3;
    goto LABEL_64;
  }
  return v49;
}
// 182438: using guessed type char byte_182438;
// 18243D: using guessed type char byte_18243D;
// 18243E: using guessed type char byte_18243E;
// 182440: using guessed type char byte_182440;
// 182473: using guessed type int16_t word_182473;
// 182475: using guessed type int16_t word_182475;
// 19D5BC: using guessed type int dword_19D5BC;


//----- (000A7342) --------------------------------------------------------
int __fastcall sub_A7342(int a1, int a2, int a3, int a4)
{
  int v5; // edx
  int result; // eax

  v5 = a3 - a1;
  if ( (int16_t)(a3 - a1) < 0 )
    v5 = a1 - a3;
  result = a4 - a2;
  if ( (int16_t)(a4 - a2) < 0 )
    result = a2 - a4;
  if ( (int16_t)v5 > (int16_t)result )
    return v5;
  return result;
}


//----- (000A7364) --------------------------------------------------------
int __fastcall sub_A7364( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // ebx

  v7 = (a6 << 6) + (a4 << 7) + 4 * a3;
  sub_12B753(*(int *)((char *)&dword_19D410 + v7), a5 % 3);
  return sub_C5CFF(a1, a2, *(int16_t **)((char *)&dword_19D410 + v7));
}
// 19D410: using guessed type int dword_19D410;


//----- (000A73B7) --------------------------------------------------------
int __fastcall sub_A73B7( int a1, int a2, int a3, int a4, int a5)
{
  int v6; // ebx

  v6 = (a5 << 6) + 4 * a3;
  sub_12B753(*(int *)((char *)&dword_19D390 + v6), a4 % (*(int16_t *)(*(int *)((char *)&dword_19D390 + v6) + 6) - 1));
  sub_12B753(*(int *)((char *)&dword_19D390 + v6), a4 % (*(int16_t *)(*(int *)((char *)&dword_19D390 + v6) + 6) - 1));
  return sub_12A478(a1 - 8, a2 - 8, *(int *)((char *)&dword_19D390 + v6));
}
// 19D390: using guessed type int dword_19D390;


//----- (000A742B) --------------------------------------------------------
_DWORD *sub_A742B()
{
  _DWORD *result; // eax

  result = sub_126B42((int)aBeamsLbx, 88, dword_192ED4);
  dword_19D5BC = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 19D5BC: using guessed type int dword_19D5BC;


//----- (000A744A) --------------------------------------------------------
void sub_A744A()
{
  int16_t v0; // cx
  int16_t v1; // di
  int v2; // esi
  _DWORD *v3; // edx
  int v4; // eax
  int16_t i; // [esp+4h] [ebp-4h]

  v0 = 0;
  while ( 1 )
  {
    if ( v0 )
      v1 = 33;
    else
      v1 = 1;
    for ( i = 0; i < 2; ++i )
    {
      v2 = 0;
      do
      {
        v3 = sub_126B42((int)aBeamsLbx, v1++, dword_192ED4);
        v4 = (i << 6) + (v0 << 7) + 4 * (int16_t)v2++;
        *(int *)((char *)&dword_19D410 + v4) = (int)v3;
      }
      while ( (int16_t)v2 < 16 );
    }
    if ( ++v0 >= 2 )
      JUMPOUT(0xA9FC4);
  }
}
// A74C0: control flows out of bounds to A9FC4
// 192ED4: using guessed type int dword_192ED4;
// 19D410: using guessed type int dword_19D410;


//----- (000A74C5) --------------------------------------------------------
void sub_A74C5()
{
  int16_t v0; // di
  int16_t v1; // cx
  int v2; // esi
  _DWORD *v3; // ebx
  int v4; // eax

  v0 = 65;
  v1 = 0;
  while ( 1 )
  {
    v2 = 0;
    do
    {
      v3 = sub_126B42((int)aBeamsLbx, v0, dword_192ED4);
      v4 = 4 * (int16_t)v2++ + (v1 << 6);
      *(int *)((char *)&dword_19D390 + v4) = (int)v3;
    }
    while ( (int16_t)v2 < 16 );
    ++v1;
    ++v0;
    if ( v1 >= 2 )
      JUMPOUT(0xA9FC4);
  }
}
// A7513: control flows out of bounds to A9FC4
// 192ED4: using guessed type int dword_192ED4;
// 19D390: using guessed type int dword_19D390;


//----- (000A7518) --------------------------------------------------------
_DWORD *__fastcall sub_A7518( int a1)
{
  int v2; // eax
  _DWORD *result; // eax

  dword_19D5C0 = (int)sub_126B42((int)aBeamsLbx, 0, dword_192ED4);
  sub_A75B0();
  sub_C6AF9();
  sub_A744A();
  sub_A74C5();
  sub_A9722();
  if ( a1 )
  {
    v2 = sub_AA109(0, 0);
    sub_12B79D(v2);
    sub_131F7B();
  }
  result = sub_126B42((int)aBeamsLbx, 88, dword_192ED4);
  dword_19D5BC = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 19D5BC: using guessed type int dword_19D5BC;
// 19D5C0: using guessed type int dword_19D5C0;


//----- (000A7582) --------------------------------------------------------
_DWORD *sub_A7582()
{
  _DWORD *result; // eax

  result = sub_126B42((int)aBeamsLbx, 0, dword_192ED4);
  word_182439 = -1;
  word_18243B = -1;
  dword_19D5C0 = (int)result;
  return result;
}
// 182439: using guessed type int16_t word_182439;
// 18243B: using guessed type int16_t word_18243B;
// 192ED4: using guessed type int dword_192ED4;
// 19D5C0: using guessed type int dword_19D5C0;


//----- (000A75B0) --------------------------------------------------------
void sub_A75B0()
{
  word_182439 = -1;
  word_18243B = -1;
}
// 182439: using guessed type int16_t word_182439;
// 18243B: using guessed type int16_t word_18243B;


//----- (000A75C3) --------------------------------------------------------
char __fastcall sub_A75C3( int a1, int a2, int a3)
{
  int16_t v3; // ax
  int16_t v4; // si
  int16_t v5; // ax
  int16_t v7; // [esp+Ch] [ebp-10h]
  _BYTE v8[4]; // [esp+10h] [ebp-Ch] BYREF
  _BYTE v9[4]; // [esp+14h] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+18h] [ebp-4h] BYREF

  v3 = 16 * a1;
  v4 = 0;
  v7 = v3;
  while ( v4 < a3 )
  {
    sub_133BAE(dword_19D5C0, v4 + v7, v8, v10, v9);
    v5 = a2 + v4++;
    LOBYTE(v3) = sub_132F27(v5, v8[0], v10[0], v9[0]);
  }
  return v3;
}
// 19D5C0: using guessed type int dword_19D5C0;


//----- (000A761C) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (function frame is wrong (funcsize=0)) - nutno dohledat rucne v IDA @ 0xA761C */
int __fastcall sub_A761C(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD)
{
  DECOMP_TODO("function frame is wrong (funcsize=0)");
}


//----- (000A8197) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge sub_A8197(
        int a1,
        int a2,
        int a3,
        int a4,
        __int128 a5,
        int64_t a6,
        int64_t a7,
        int64_t a8,
        int64_t a9,
        int64_t a10,
        int64_t a11,
        int64_t a12,
        int64_t a13,
        __int128 a14,
        int a15,
        int a16,
        int a17,
        int a18,
        __int128 a19)
{
  int v19; // ecx
  int v20; // ebx
  int v21; // eax
  int result; // eax
  int v23; // eax
  int v24; // eax
  int v25; // ebx
  int v26; // edx
  int v27; // eax
  _WORD *v28; // eax
  int v29; // edx
  int v30; // eax
  int16_t v31; // ax
  int v32; // eax
  int v33; // kr00_4
  int v34; // eax
  unsigned int v35; // edi
  int16_t v36; // ax
  int v37; // eax
  int v38; // esi
  unsigned int v39; // edi
  int16_t v40; // dx
  int16_t v41; // ax
  unsigned int v42; // eax
  unsigned int v43; // esi
  int v44; // eax
  int16_t v45; // dx
  int16_t v46; // ax
  int v47; // eax
  int16_t i; // si
  int16_t *v49; // eax
  int v50; // eax
  int v51; // esi
  int v52; // edi
  int v53; // eax
  int16_t v54; // dx
  bool v55; // eax
  char v56; // bl
  _BOOL1 v57; // cl
  _BOOL1 v58; // bl
  int16_t v59; // si
  int16_t v60; // cx
  int16_t v61; // ax
  int16_t v62; // si
  int16_t v63; // si
  int16_t v64; // cx
  int16_t v65; // bx
  int16_t v66; // ax
  int16_t v67; // dx
  int16_t v68; // si
  int v69; // esi
  int v70; // eax
  int16_t j; // si
  int v72; // edx
  int v73; // eax
  int v74; // edx
  int v75; // eax
  int v76; // eax
  int v77; // eax
  int v78; // eax
  int v79; // eax
  int v80; // edx
  int v81; // eax
  int v82; // [esp-24h] [ebp-194h]
  int16_t v83; // [esp-18h] [ebp-188h]
  int16_t v84; // [esp-18h] [ebp-188h]
  int16_t v85; // [esp-14h] [ebp-184h]
  int16_t v86; // [esp-14h] [ebp-184h]
  int16_t v87; // [esp-14h] [ebp-184h]
  int v88; // [esp-10h] [ebp-180h]
  int v89; // [esp-Ch] [ebp-17Ch]
  int v90; // [esp-8h] [ebp-178h]
  int v91; // [esp-4h] [ebp-174h]
  int v92; // [esp+0h] [ebp-170h]
  int v93; // [esp+4h] [ebp-16Ch]
  int v94; // [esp+8h] [ebp-168h]
  int v95; // [esp+Ch] [ebp-164h]
  int v96; // [esp+10h] [ebp-160h]
  int v97; // [esp+14h] [ebp-15Ch]
  int v98; // [esp+18h] [ebp-158h]
  int v99; // [esp+1Ch] [ebp-154h]
  int v100; // [esp+20h] [ebp-150h]
  __int128 v101; // [esp+24h] [ebp-14Ch]
  int v102; // [esp+34h] [ebp-13Ch]
  int v103; // [esp+38h] [ebp-138h]
  int v104; // [esp+3Ch] [ebp-134h]
  int v105; // [esp+40h] [ebp-130h]
  int64_t v106; // [esp+44h] [ebp-12Ch]
  int64_t v107; // [esp+4Ch] [ebp-124h]
  int64_t v108; // [esp+54h] [ebp-11Ch]
  int16_t v109; // [esp+62h] [ebp-10Eh]
  int v110; // [esp+66h] [ebp-10Ah]
  int v111; // [esp+6Ah] [ebp-106h]
  int16_t v112; // [esp+6Eh] [ebp-102h]
  _BYTE v113[15]; // [esp+72h] [ebp-FEh] BYREF
  int16_t v114; // [esp+81h] [ebp-EFh]
  char v115; // [esp+8Fh] [ebp-E1h]
  int v116; // [esp+162h] [ebp-Eh]
  int v117; // [esp+166h] [ebp-Ah]
  int v118; // [esp+16Ah] [ebp-6h]
  int var2; // [esp+16Eh] [ebp-2h]
  int vars2; // [esp+172h] [ebp+2h]
  int vars6; // [esp+176h] [ebp+6h]
  int16_t _17A; // [esp+17Ah] [ebp+Ah] OVERLAPPED
  _UNKNOWN *retaddr; // [esp+17Ch] [ebp+Ch]

  v91 = a1;
  v90 = a2;
  v89 = a4;
  v88 = a3;
  *(_DWORD *)((char *)&a13 + 2) = 0;
  *(_DWORD *)((char *)&a10 + 6) = 0;
  vars6 = -65536;
  *(_DWORD *)((char *)&a6 + 6) = 0;
  vars2 = 0;
  v19 = SWORD3(a19);
  var2 = 0;
  v20 = SWORD1(a19);
  v118 = 0;
  v117 = sub_12484C();
  v116 = 0;
  *(_DWORD *)((char *)&a11 + 2) = 0;
  v21 = sub_A7342((int16_t)v111, (int16_t)v110, v20, v19);
  byte_182438 = 0;
  *(_DWORD *)((char *)&a5 + 6) = v21;
  sub_1320E9((_BYTE *)dword_192950);
  BYTE14(a14) = 0;
  sub_A97F7(0, 0, 1, 0);
  word_182439 = -1;
  word_18243B = -1;
  if ( **(_WORD **)((char *)&a19 + 10) == 46
    || (result = 28 * (int16_t)**(_WORD **)((char *)&a19 + 10), !byte_17F80F[result]) )
  {
    HIWORD(a13) = *(uint8_t *)(dword_192864 + 313 * v112 + 35);
    v23 = 313 * v109;
    LOWORD(v23) = *(uint8_t *)(dword_192864 + v23 + 35);
    *(_DWORD *)((char *)&a5 + 10) = v23;
    sub_49ED1(v112, (_WORD *)&a14 + 3, (_WORD *)&a8 + 1);
    *(_DWORD *)((char *)&a14 + 6) += v111;
    *(_DWORD *)((char *)&a8 + 2) += v110;
    if ( HIWORD(a19) )
    {
      *(_DWORD *)((char *)&a5 + 2) = *(_DWORD *)((char *)&a19 + 2);
      *(_DWORD *)((char *)&a14 + 2) = *(_DWORD *)((char *)&a19 + 6);
    }
    else
    {
      sub_49ED1(v109, (_WORD *)&a5 + 1, (_WORD *)&a14 + 1);
      *(_DWORD *)((char *)&a5 + 2) += *(_DWORD *)((char *)&a19 + 2);
      *(_DWORD *)((char *)&a14 + 2) += *(_DWORD *)((char *)&a19 + 6);
    }
    memset(&dword_182443, 0, 40);
    if ( *(char *)(*(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + SWORD1(a13)) + 12) < 0 )
      *((_WORD *)&v116 + SWORD1(a13)) = 3;
    while ( 1 )
    {
      if ( BYTE14(a14) )
      {
        v80 = 0;
        do
        {
          v81 = (int16_t)v80++;
          byte_182441[v81] = 0;
          byte_18243F[v81] = 0;
        }
        while ( (int16_t)v80 < 2 );
        dword_18246B = 0;
        memset(&dword_182443, 0, 40);
        word_182483 = 0;
        word_182489 = 0;
        sub_12B65C();
        return sub_124820(v117);
      }
      sub_12C2A0();
      v24 = sub_124D41();
      sub_2F4EE(v24);
      v25 = 639;
      HIWORD(v26) = 0;
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      *(_DWORD *)((char *)&a6 + 2) = 0;
      if ( word_1998FC == v109 && !HIWORD(a19) )
      {
        v25 = SWORD3(a19);
        v26 = SWORD1(a19);
        sub_30062(
          word_1998FC,
          350,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108);
      }
      if ( word_1998FC == v112 )
      {
        v25 = (int16_t)v110;
        v26 = (int16_t)v111;
        sub_30062(
          word_1998FC,
          350,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108);
      }
      *(_DWORD *)((char *)&a7 + 6) = 0;
      do
      {
        v27 = *((int16_t *)&vars6 + SHIWORD(a7));
        if ( v27 <= -1 )
          goto LABEL_51;
        v28 = (_WORD *)(*(_DWORD *)((char *)&a19 + 10) + 15 * v27);
        LOWORD(v26) = *v28;
        LOWORD(v28) = v28[1];
        *(_DWORD *)((char *)&a5 + 14) = v28;
        *(_DWORD *)((char *)&a12 + 6) = v26;
        HIWORD(v29) = HIWORD(dword_192864);
        v30 = dword_192864 + 313 * v112;
        LOWORD(v29) = *(_WORD *)(v30 + 196);
        LOWORD(v30) = *(uint8_t *)(v30 + 32);
        *(_DWORD *)((char *)&a9 + 6) = v29;
        *(_DWORD *)((char *)&a10 + 2) = v30;
        if ( HIWORD(a19) )
        {
          v25 = SWORD3(a19);
          v26 = SWORD1(a19);
          v31 = sub_329A4(v112, SWORD1(a19), SWORD3(a19));
        }
        else
        {
          v26 = v109;
          v31 = sub_32A20(v112, v109);
        }
        HIWORD(retaddr) = sub_39DE0(v31);
        if ( v112 <= 0 || SWORD1(a10) >= 8 || word_18248B == 2 )
        {
          *(_DWORD *)((char *)&a9 + 2) = 1;
        }
        else
        {
          v26 = SHIWORD(a5);
          *(_DWORD *)((char *)&a9 + 2) = sub_C6B6B(SHIWORD(a12), SHIWORD(a5), v25);
        }
        if ( !*((_WORD *)&vars2 + SHIWORD(a7)) )
        {
          v32 = *(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + SHIWORD(a7));
          if ( !*(_WORD *)(v32 + 4) && !*(_WORD *)(v32 + 6) && !*(_BYTE *)(v32 + 14) && v109 && !HIWORD(a19) )
          {
            v33 = (uint8_t)byte_182477[sub_A9AAD(*(uint8_t *)(313 * v109 + dword_192864 + 37))];
            v34 = SWORD3(a5) / 2;
            if ( (int16_t)(v33 / 2) <= v34 )
              LOWORD(v34) = v33 / 2;
            v35 = (int16_t)v34;
            v25 = (int16_t)v34 / 2;
            v26 = SHIWORD(a7);
            *((_WORD *)&var2 + v26) = sub_1247A0((int16_t)v34) - v25;
            v36 = sub_1247A0(v35) - v25;
            goto LABEL_39;
          }
          if ( !v109 && !*(_WORD *)(*(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + SHIWORD(a7)) + 8) )
          {
            v37 = SWORD3(a5) / 2;
            if ( v37 >= 30 )
              LOWORD(v37) = 30;
            v25 = (int16_t)v37;
            v38 = (int16_t)v37 / 2;
            v39 = (int)((int16_t)v37
                      - (__CFSHL__((uint64_t)(int16_t)v37 >> 32, 2)
                       + 4 * ((uint64_t)(int16_t)v37 >> 32))) >> 2;
            v40 = v38 + sub_1247A0(v39);
            v41 = v40 * (sub_1247A0(2u) - 1);
            v26 = SHIWORD(a7);
            *((_WORD *)&var2 + SHIWORD(a7)) = v41;
            v42 = v39;
LABEL_38:
            v43 = sub_1247A0(v42) + v38;
            v36 = v43 * (sub_1247A0(2u) - 1);
LABEL_39:
            *((_WORD *)&v118 + v26) = v36;
            goto LABEL_46;
          }
          if ( HIWORD(a19) && !*(_WORD *)(*(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + SHIWORD(a7)) + 8) )
          {
            v44 = SWORD3(a5) / 2;
            if ( (uint8_t)byte_182477[0] / 2 <= v44 )
              LOWORD(v44) = (uint8_t)byte_182477[0] / 2;
            v38 = (int16_t)v44 / 2;
            v25 = ((int)((int16_t)v44
                       - (__CFSHL__((uint64_t)(int16_t)v44 >> 32, 2)
                        + 4 * ((uint64_t)(int16_t)v44 >> 32))) >> 2)
                + 1;
            v45 = v38 + sub_1247A0(v25);
            v46 = v45 * (sub_1247A0(2u) - 1);
            v26 = SHIWORD(a7);
            *((_WORD *)&var2 + SHIWORD(a7)) = v46;
            v42 = v25;
            goto LABEL_38;
          }
          v47 = SHIWORD(a7);
          *((_WORD *)&var2 + SHIWORD(a7)) = 0;
          *((_WORD *)&v118 + v47) = 0;
        }
LABEL_46:
        for ( i = 0; i < SWORD1(a9); ++i )
        {
          if ( v112 > 0 )
            sub_C6BD0(
              (_WORD *)&a10 + 3,
              (_WORD *)&a6 + 3,
              SHIWORD(a12),
              SHIWORD(a5),
              SWORD1(a10),
              v112,
              SHIWORD(a9),
              BYTE6(a13),
              BYTE2(retaddr),
              i);
          v49 = (int16_t *)(*(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + SHIWORD(a7)));
          v82 = i;
          v25 = (int16_t)(*((_WORD *)&var2 + SHIWORD(a7)) + WORD1(a5));
          v26 = (int16_t)(HIWORD(a6) + WORD1(a8));
          sub_A761C(
            (int16_t)(HIWORD(a10) + WORD3(a14)),
            v26,
            v25,
            (int16_t)(*((_WORD *)&v118 + SHIWORD(a7)) + WORD1(a14)),
            SHIWORD(a13),
            SWORD5(a5),
            *v49,
            *((int16_t *)&vars2 + SHIWORD(a7)),
            SHIWORD(a7),
            *(uint8_t *)(dword_192864 + 313 * v109 + 37),
            v49[2],
            v49[3],
            SHIWORD(a19),
            v82,
            word_18248B,
            *(uint8_t *)(dword_192864 + 313 * v112 + 37),
            v49[6],
            1);
        }
LABEL_51:
        if ( *((int16_t *)&vars6 + SHIWORD(a7)) >= 16
          || (*((int16_t *)&vars6 + SHIWORD(a7)) > -1
           || *((int16_t *)&vars6 + (HIWORD(a7) == 0)) == -1
           || *((int16_t *)&vars6 + (HIWORD(a7) == 0)) >= 16
           || *(int16_t *)(*(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + (HIWORD(a7) == 0))) > 0
           && *((int16_t *)&vars2 + (HIWORD(a7) == 0)) < 9)
          && ((v26 = 2 * SHIWORD(a7), *(int16_t *)((char *)&vars6 + v26) <= -1)
           || sub_A6B95() > *(int16_t *)((char *)&vars2 + v26)) )
        {
          v55 = !word_19987E && !word_1998CE;
          if ( v55 || (v26 = 2 * SHIWORD(a7), v25 = *(int16_t *)((char *)&vars2 + v26) + 2, v25 >= sub_A6B95()) )
            ++*((_WORD *)&vars2 + SHIWORD(a7));
          else
            *(_WORD *)((char *)&vars2 + v26) += 2;
        }
        else
        {
          v50 = 2 * SHIWORD(a7);
          --*(_WORD *)((char *)&v116 + v50);
          *(_WORD *)((char *)&vars2 + v50) = 0;
          if ( *(int16_t *)((char *)&v116 + v50) <= 0 )
          {
            v25 = SWORD1(a11) + 1;
            v26 = *(_DWORD *)((char *)&a19 + 10) + 15 * v25;
            *(_WORD *)((char *)&v116 + v50) = 0;
            if ( *(int16_t *)v26 <= 0 || v25 >= 16 )
            {
              *((_WORD *)&vars6 + SHIWORD(a7)) = -1;
            }
            else if ( *(_BYTE *)(v26 + 14) )
            {
              v26 = *((int16_t *)&vars6 + (HIWORD(a7) == 0));
              if ( v26 == -1000
                && ((v26 = HIWORD(a7) == 0, byte_18243F[v26]) || *(int16_t *)((char *)&vars6 + v50) <= -1) )
              {
                byte_18243D = 0;
                word_182483 = 0;
                memset(v113, 0, 240);
                v51 = 15 * (SWORD1(a11) + 1);
                ++*(_DWORD *)((char *)&a11 + 2);
                qmemcpy(v113, (void *)(*(_DWORD *)((char *)&a19 + 10) + v51), sizeof(v113));
                v115 = 0;
                v114 = 0;
                word_18248B = 2;
                v52 = SWORD1(a19);
                *(_DWORD *)&_17A = SWORD3(a19);
                byte_18248D = 1;
                ((int __userpurge(*)())(void*)sub_A8197)(v109, SWORD1(a19), *(_DWORD *)&_17A, v112, (int16_t)v111, (int16_t)v110, v113, 0);
                byte_18248D = 0;
                word_182489 = 0;
                v25 = 639;
                HIWORD(v26) = 0;
                *((_WORD *)&vars6 + (HIWORD(a7) == 0)) = -1000;
                sub_12C2A0();
                v53 = sub_124D41();
                sub_2F4EE(v53);
                sub_128AB6(0, 0, 639, 350);
                sub_12B634();
                *(_DWORD *)((char *)&a6 + 2) = 1;
                if ( word_1998FC == v109 && !HIWORD(a19) )
                {
                  v25 = *(_DWORD *)&_17A;
                  HIWORD(v26) = HIWORD(v52);
                  sub_30062(
                    v109,
                    350,
                    v88,
                    v89,
                    v90,
                    v91,
                    v92,
                    v93,
                    v94,
                    v95,
                    v96,
                    v97,
                    v98,
                    v99,
                    v100,
                    v101,
                    v102,
                    v103,
                    v104,
                    v105,
                    v106,
                    v107,
                    v108);
                }
                if ( word_1998FC == v112 )
                {
                  v25 = (int16_t)v110;
                  v26 = (int16_t)v111;
                  sub_30062(
                    word_1998FC,
                    350,
                    v88,
                    v89,
                    v90,
                    v91,
                    v92,
                    v93,
                    v94,
                    v95,
                    v96,
                    v97,
                    v98,
                    v99,
                    v100,
                    v101,
                    v102,
                    v103,
                    v104,
                    v105,
                    v106,
                    v107,
                    v108);
                }
              }
              else
              {
                *((_WORD *)&vars6 + SHIWORD(a7)) = -1000;
                if ( *(_BYTE *)(*(_DWORD *)((char *)&a19 + 10) + 15 * (SWORD1(a11) + 1) + 14) )
                {
                  word_18248B = 1;
                  word_182489 = 1;
                }
              }
            }
            else
            {
              ++*(_DWORD *)((char *)&a11 + 2);
              v54 = WORD1(a11);
              *(_WORD *)((char *)&vars6 + v50) = WORD1(a11);
              if ( *(_BYTE *)(*(_DWORD *)((char *)&a19 + 10) + 15 * (v54 + 1) + 14) )
              {
                word_18248B = 1;
                word_182489 = 1;
              }
              v26 = *(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + SHIWORD(a7));
              if ( *(char *)(v26 + 12) < 0 )
                *((_WORD *)&v116 + SHIWORD(a7)) = 3;
            }
          }
        }
        if ( (int16_t)vars6 <= -1 && SHIWORD(vars6) <= -1 )
        {
          byte_18243D = 0;
          byte_18243E = 0;
        }
        ++*(_DWORD *)((char *)&a7 + 6);
      }
      while ( SHIWORD(a7) < 2 );
      if ( (int16_t)vars6 <= -1 && SHIWORD(vars6) <= -1 && !word_182483 && !word_182489 && sub_A929A() && !WORD1(a6) )
      {
        BYTE14(a14) = 1;
        word_18248B = 0;
      }
      if ( HIWORD(a19) )
      {
        word_182483 = 0;
        word_182489 = 0;
      }
      else
      {
        sub_A9618(&word_18247F);
        v56 = 0;
        if ( (int16_t)vars6 > -1 )
          v56 = *(_BYTE *)(*(_DWORD *)((char *)&a19 + 10) + 15 * (int16_t)vars6 + 6);
        if ( SHIWORD(vars6) > -1 )
          v56 += *(_BYTE *)(*(_DWORD *)((char *)&a19 + 10) + 15 * ((_WORD)vars6 == 0) + 6);
        if ( byte_182438 )
          v56 = 1;
        v57 = v56 != 0;
        v58 = v56 != 0;
        if ( v109 )
        {
          v59 = (uint8_t)byte_182477[sub_A9AAD(*(uint8_t *)(dword_192864 + 313 * v109 + 37))];
          if ( (int16_t)vars6 <= -1 )
            v60 = 0;
          else
            v60 = *(_WORD *)(*(_DWORD *)((char *)&a19 + 10) + 15 * (int16_t)vars6 + 12) & 0x100;
          v85 = word_18247F;
          v83 = sub_A956C(v112, v109);
          sub_A9AED(WORD1(a5) - v59 / 2, WORD1(a14) - v59 / 2, v109, v58, v60, v83, v85);
        }
        else
        {
          sub_A9AC8();
          v62 = (uint8_t)byte_182477[v61];
          v86 = word_18247F;
          v84 = sub_A956C(v112, 0);
          sub_A9AED(WORD1(a5) - v62 / 2, WORD1(a14) - v62 / 2, 0, v57, 0, v84, v86);
        }
        if ( word_182489 )
        {
          if ( word_18248B == 2 )
          {
            sub_A9FFC(&word_182481);
            sub_49ED1(v112, (_WORD *)&a12 + 1, (_WORD *)&a11 + 3);
            *(_DWORD *)((char *)&a12 + 2) += v111;
            *(_DWORD *)((char *)&a11 + 6) += v110;
            v63 = (uint8_t)byte_182485[sub_A9AAD(*(uint8_t *)(313 * v112 + dword_192864 + 37))];
            v87 = word_182481;
            v64 = sub_A956C(v109, v112);
            v65 = *(uint8_t *)(313 * v112 + dword_192864 + 37);
            v66 = v63 / 2;
            v67 = HIWORD(a11);
            v68 = WORD1(a12);
            goto LABEL_113;
          }
          if ( word_18248B == 1 )
          {
            v69 = 313 * v109;
            sub_A9FFC(&word_182481);
            v70 = sub_A9AAD(*(uint8_t *)(v69 + dword_192864 + 37));
            LOWORD(v70) = (uint8_t)byte_182485[(int16_t)v70];
            *(_DWORD *)((char *)&a14 + 10) = v70;
            sub_49ED1(v109, (_WORD *)&a8 + 3, (_WORD *)&a7 + 1);
            *(_DWORD *)((char *)&a8 + 6) += *(_DWORD *)((char *)&a19 + 2);
            *(_DWORD *)((char *)&a7 + 2) += *(_DWORD *)((char *)&a19 + 6);
            v87 = word_182481;
            v64 = sub_A956C(v112, v109);
            v65 = *(uint8_t *)(v69 + dword_192864 + 37);
            v66 = SWORD5(a14) / 2;
            v67 = WORD1(a7);
            v68 = HIWORD(a8);
LABEL_113:
            sub_AA38D(v68 - v66, (int16_t)(v67 - v66), v65, v64, v87);
          }
        }
      }
      for ( j = 0; j < 2; ++j )
      {
        if ( HIWORD(a19) )
        {
          v76 = *((int16_t *)&vars6 + j);
          if ( v76 > -1 )
          {
            v77 = *(_DWORD *)((char *)&a19 + 10) + 15 * v76;
            if ( *(int16_t *)(v77 + 8) > 0 || *(int16_t *)(v77 + 10) > 0 )
            {
              if ( byte_18243F[j] )
              {
                sub_A9412(
                  SWORD1(a5),
                  SWORD1(a14),
                  1,
                  *(_WORD *)(*(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + j) + 8));
                v78 = dword_192B14 + 26 * v109;
                *(_WORD *)(v78 + 15) -= *(_WORD *)(*(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + j) + 8);
                if ( *(int16_t *)(v78 + 15) <= 0 )
                  sub_3BC80(v109);
                if ( *(_WORD *)(*(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + j) + 8) )
                  sub_147D7(28);
                *(_WORD *)(*(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + j) + 8) = -1;
              }
            }
          }
        }
        else
        {
          v72 = *((int16_t *)&vars6 + j);
          if ( v72 > -1 )
          {
            if ( byte_18243F[j] )
            {
              v73 = *(_DWORD *)((char *)&a19 + 10) + 15 * v72;
              if ( *(int16_t *)(v73 + 8) > 0 || *(int16_t *)(v73 + 10) > 0 )
              {
                v74 = ((int16_t)sub_A956C(v109, v112) + 4) % 16;
                v75 = *(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + j);
                sub_A93AA(SWORD1(a19), SWORD3(a19), v109, v74 < 8, *(_WORD *)(v75 + 8), *(_WORD *)(v75 + 10));
                sub_147D7(29);
                *(_WORD *)(*(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + j) + 8) = -1;
                *(_WORD *)(*(_DWORD *)((char *)&a19 + 10) + 15 * *((int16_t *)&vars6 + j) + 10) = -1;
              }
            }
          }
        }
      }
      sub_A9223();
      v79 = sub_12C2C6(1);
      sub_1077D(v79);
      sub_12B65C();
      sub_128BE7();
    }
  }
  return result;
}
// A8197: variables would overlap: ^1C2.2 and ^1C2.4
// A83E3: inconsistent variable size for '^1C8.16'
// A81BF: inconsistent variable size for '^1D8.8'
// A83B3: inconsistent variable size for '^1E0.8'
// A8AC8: inconsistent variable size for '^1E0.8'
// A8DAA: inconsistent variable size for '^1E8.8'
// A8403: inconsistent variable size for '^1F0.8'
// A81B0: inconsistent variable size for '^1F8.8'
// A8CF5: inconsistent variable size for '^200.8'
// A83EC: inconsistent variable size for '^208.8'
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// A761C: using guessed type int __fastcall sub_A761C(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 182438: using guessed type char byte_182438;
// 182439: using guessed type int16_t word_182439;
// 18243B: using guessed type int16_t word_18243B;
// 18243D: using guessed type char byte_18243D;
// 18243E: using guessed type char byte_18243E;
// 182443: using guessed type int dword_182443;
// 18246B: using guessed type int dword_18246B;
// 18247F: using guessed type int16_t word_18247F;
// 182481: using guessed type int16_t word_182481;
// 182483: using guessed type int16_t word_182483;
// 182489: using guessed type int16_t word_182489;
// 18248B: using guessed type int16_t word_18248B;
// 18248D: using guessed type char byte_18248D;
// 192864: using guessed type int dword_192864;
// 192950: using guessed type int dword_192950;
// 192B14: using guessed type int dword_192B14;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199878: using guessed type int16_t word_199878;
// 19987E: using guessed type int16_t word_19987E;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (000A9033) --------------------------------------------------------
void __fastcall sub_A9033(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // edi
  int16_t *v7; // eax
  int v8; // esi
  int v10; // [esp+14h] [ebp-14h]
  int v11; // [esp+18h] [ebp-10h]
  int v12; // [esp+1Ch] [ebp-Ch]
  int16_t v13; // [esp+20h] [ebp-8h]
  int v14; // [esp+24h] [ebp-4h]

  v6 = sub_12484C();
  v13 = 0;
  sub_128AB6(0, 0, 639, 350);
  sub_12B634();
  while ( v13 < a2 )
  {
    v10 = v13;
    v7 = (int16_t *)(a1 + 4 * v13);
    v8 = v7[1];
    v11 = *v7;
    v14 = ((int16_t)sub_1384B9(v11 - a3, a4 - v8) / 22 + 8) % 16;
    v12 = ((int16_t)sub_1384B9(a3 - v11, v8 - a4) / 22 + 8) % 16;
    if ( word_182473 < a6 )
      goto LABEL_6;
    ++v13;
    sub_A761C(v11, v8, a3, a4, (int16_t)v14, (int16_t)v12, a5, a6, 0, 0, 0, 0, 1, 0, 0, -1, 0, v10 % 3 == 0);
  }
  sub_12B65C();
  sub_124820(v6);
LABEL_6:
  JUMPOUT(0xA73B1);
}
// A90EB: control flows out of bounds to A73B1
// A761C: using guessed type int __fastcall sub_A761C(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 182473: using guessed type int16_t word_182473;


//----- (000A916F) --------------------------------------------------------
void sub_A916F()
{
  word_18248E = 0;
}
// 18248E: using guessed type int16_t word_18248E;


//----- (000A9179) --------------------------------------------------------
int __fastcall sub_A9179(int result, int a2, int a3, int a4, int a5, int a6)
{
  int16_t v6; // si

  v6 = result;
  if ( word_18248E < 35 && (a3 > 0 || a4 > 0 || a5 > 0) )
  {
    result = 13 * word_18248E;
    *(int16_t *)((char *)&word_19D5DE + result) = 0;
    *(int16_t *)((char *)&word_19D5D4 + result) = v6;
    *(int16_t *)((char *)&word_19D5D6 + result) = a2;
    *(int16_t *)((char *)&word_19D5D8 + result) = a3;
    *(int16_t *)((char *)&word_19D5DA + result) = a4;
    *(int16_t *)((char *)&word_19D5DC + result) = a5;
    ++word_18248E;
    byte_19D5E0[result] = a6;
  }
  return result;
}
// 18248E: using guessed type int16_t word_18248E;
// 19D5D4: using guessed type int16_t word_19D5D4;
// 19D5D6: using guessed type int16_t word_19D5D6;
// 19D5D8: using guessed type int16_t word_19D5D8;
// 19D5DA: using guessed type int16_t word_19D5DA;
// 19D5DC: using guessed type int16_t word_19D5DC;
// 19D5DE: using guessed type int16_t word_19D5DE;


//----- (000A91E8) --------------------------------------------------------
int __fastcall sub_A91E8(int result)
{
  char *v1; // esi
  char *v2; // edi

  while ( (int16_t)result < 34 )
  {
    v1 = (char *)&word_19D5D4 + 13 * (int16_t)result + 13;
    v2 = (char *)&word_19D5D4 + 13 * (int16_t)result++;
    qmemcpy(v2, v1, 0xDu);
  }
  --word_18248E;
  return result;
}
// 18248E: using guessed type int16_t word_18248E;
// 19D5D4: using guessed type int16_t word_19D5D4;


//----- (000A9223) --------------------------------------------------------
void sub_A9223()
{
  int16_t i; // di
  int v1; // esi

  for ( i = 0; i < word_18248E; ++i )
  {
    v1 = 13 * i;
    sub_A92A6(
      *(int16_t *)((char *)&word_19D5D4 + v1),
      *(int16_t *)((char *)&word_19D5D6 + v1),
      *(int16_t *)((char *)&word_19D5D8 + v1),
      *(int16_t *)((char *)&word_19D5DA + v1),
      *(int16_t *)((char *)&word_19D5DC + v1),
      byte_19D5E0[v1],
      *(int16_t *)((char *)&word_19D5DE + v1));
    if ( ++*(int16_t *)((char *)&word_19D5DE + v1) >= 9 )
      sub_A91E8(i);
  }
  JUMPOUT(0xA9FC4);
}
// A9295: control flows out of bounds to A9FC4
// 18248E: using guessed type int16_t word_18248E;
// 19D5D4: using guessed type int16_t word_19D5D4;
// 19D5D6: using guessed type int16_t word_19D5D6;
// 19D5D8: using guessed type int16_t word_19D5D8;
// 19D5DA: using guessed type int16_t word_19D5DA;
// 19D5DC: using guessed type int16_t word_19D5DC;
// 19D5DE: using guessed type int16_t word_19D5DE;


//----- (000A929A) --------------------------------------------------------
_BOOL1 sub_A929A()
{
  return word_18248E == 0;
}
// 18248E: using guessed type int16_t word_18248E;


//----- (000A92A6) --------------------------------------------------------
void __fastcall sub_A92A6( int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int16_t v7; // di
  int16_t v8; // si
  int16_t v9; // [esp+4h] [ebp-58h]
  _BYTE v10[27]; // [esp+8h] [ebp-54h] BYREF
  _BYTE v11[27]; // [esp+24h] [ebp-38h] BYREF
  _BYTE v12[27]; // [esp+40h] [ebp-1Ch] BYREF

  qmemcpy(v11, &byte_A659F, sizeof(v11));
  qmemcpy(v10, &word_A65BA, sizeof(v10));
  qmemcpy(v12, byte_A65D5, sizeof(v12));
  v7 = a2 - a7;
  if ( a6 == 1 )
    v8 = a1 + a7;
  else
    v8 = a1 - a7;
  if ( a7 < 9 )
  {
    sub_128AB6(0, 0, 639, 350);
    sub_12B634();
    if ( v9 > 0 )
    {
      sub_120CCB(1, (int)&v11[3 * a7]);
      sub_12102B(v8, v7, v9, 350);
    }
    if ( a5 > 0 )
    {
      sub_120CCB(1, (int)&v12[3 * a7]);
      sub_12102B((int16_t)(v8 - 10), v7, a5, 350);
    }
    if ( a4 > 0 )
    {
      sub_120CCB(1, (int)&v10[3 * a7]);
      sub_12102B((int16_t)(v8 - 20), v7, a4, 350);
    }
    sub_12B65C();
  }
}
// A931A: variable 'v9' is possibly undefined
// A659F: using guessed type char byte_A659F;
// A65BA: using guessed type int16_t word_A65BA;


//----- (000A93AA) --------------------------------------------------------
void __fastcall sub_A93AA(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // ecx
  int v8; // [esp+0h] [ebp-Ch] BYREF
  int v9; // [esp+4h] [ebp-8h] BYREF
  char v10; // [esp+8h] [ebp-4h]

  v10 = a4;
  LOWORD(a4) = *(uint8_t *)(313 * a3 + dword_192864 + 37);
  v7 = 8 * a4;
  sub_49ED1(a3, &v9, &v8);
  v9 += a1;
  v8 += a2;
  if ( v10 )
    v9 += v7;
  else
    v9 -= v7;
  v8 -= v7;
  sub_A9179((int16_t)v9, v8, a5, a6, 0, v10);
  JUMPOUT(0xA73B1);
}
// A940D: control flows out of bounds to A73B1
// 192864: using guessed type int dword_192864;


//----- (000A9412) --------------------------------------------------------
int __fastcall sub_A9412( int a1, int a2, int a3, int a4)
{
  int16_t v4; // ax

  if ( a3 )
    v4 = a1 + 8;
  else
    v4 = a1 - 8;
  return sub_A9179(v4, a2 - 8, a4, 0, 0, a3);
}


//----- (000A943A) --------------------------------------------------------
void sub_A943A()
{
  JUMPOUT(0xA9433);
}
// A945E: control flows out of bounds to A9433


//----- (000A947F) --------------------------------------------------------
_BOOL1 __fastcall sub_A947F( int a1, int a2)
{
  return ((int16_t)sub_A956C(a2, a1) + 4) % 16 < 8;
}


//----- (000A94A1) --------------------------------------------------------
_BOOL1 sub_A94A1()
{
  int v0; // eax
  int v1; // eax
  _BOOL1 result; // al

  do
  {
    sub_12C2A0();
    v0 = sub_124D41();
    sub_2F4EE(v0);
    sub_128AB6(0, 0, 639, 350);
    sub_12B634();
    sub_A9223();
    v1 = sub_12C2C6(1);
    sub_1077D(v1);
    sub_12B65C();
    sub_128BE7();
    result = word_18248E == 0;
  }
  while ( word_18248E );
  return result;
}
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 18248E: using guessed type int16_t word_18248E;


//----- (000A94FC) --------------------------------------------------------
int __fastcall sub_A94FC( int a1, int a2, int a3)
{
  int v5; // [esp+0h] [ebp-8h] BYREF
  int v6; // [esp+4h] [ebp-4h] BYREF

  sub_49ED1(a3, &v6, &v5);
  return (int16_t)sub_1384B9(
                    a1 - (int16_t)(20 * *(uint8_t *)(dword_192864 + 313 * a3 + 33) + v6),
                    (int16_t)(v5 + 20 * *(uint8_t *)(dword_192864 + 313 * a3 + 34)) - a2)
       / 22
       % 16;
}
// 192864: using guessed type int dword_192864;


//----- (000A956C) --------------------------------------------------------
int __fastcall sub_A956C( int a1, int a2)
{
  int v2; // ecx
  int v4; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+4h] [ebp-Ch] BYREF
  int v6; // [esp+8h] [ebp-8h] BYREF
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = a1;
  sub_49ED1(a1, &v4, &v7);
  sub_49ED1(a2, &v5, &v6);
  return (int16_t)sub_1384B9(
                    (int16_t)(20 * *(uint8_t *)(dword_192864 + 313 * v2 + 33) + v4)
                  - (int16_t)(v5 + 20 * *(uint8_t *)(dword_192864 + 313 * a2 + 33)),
                    (int16_t)(v6 + 20 * *(uint8_t *)(dword_192864 + 313 * a2 + 34))
                  - (int16_t)(20 * *(uint8_t *)(dword_192864 + 313 * v2 + 34) + v7))
       / 22
       % 16;
}
// 192864: using guessed type int dword_192864;


//----- (000A9618) --------------------------------------------------------
int __fastcall sub_A9618(int16_t *a1)
{
  int v2; // eax
  int16_t v3; // dx
  int result; // eax
  int v5; // kr00_4

  v2 = sub_A97F7(0, 0, 0, 0);
  v3 = *(_WORD *)(v2 + 6);
  LOWORD(v2) = word_182483;
  v5 = v2;
  result = (uint16_t)word_182483;
  switch ( word_182483 )
  {
    case 0:
      if ( byte_18243D )
      {
        word_182483 = 1;
        *a1 = 0;
      }
      break;
    case 1:
      if ( ++*a1 >= 4 )
        word_182483 = 2;
      break;
    case 2:
      ++*a1;
      if ( byte_18243D )
      {
        if ( *a1 >= 7 )
          *a1 = 4;
      }
      else if ( *a1 >= 7 )
      {
        word_182483 = 3;
      }
      break;
    case 3:
      if ( v3 <= ++*a1 )
        word_182483 = 0;
      break;
    default:
      result = v5;
      break;
  }
  return result;
}
// 18243D: using guessed type char byte_18243D;
// 182483: using guessed type int16_t word_182483;


//----- (000A96C7) --------------------------------------------------------
_BOOL1 __fastcall sub_A96C7( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v5; // bx
  int16_t v6; // cx
  int16_t v7; // dx
  int v8; // eax
  int v9; // eax
  _BOOL1 result; // al

  v5 = a1 - a3;
  v6 = a2 - a4;
  v7 = (uint8_t)byte_182477[sub_A9AAD(a5)] / 2;
  if ( v5 >= 0 )
    v8 = v5;
  else
    v8 = -v5;
  result = 0;
  if ( v8 <= v7 )
  {
    v9 = v6 >= 0 ? v6 : -v6;
    if ( v9 <= v7 )
      return 1;
  }
  return result;
}


//----- (000A9722) --------------------------------------------------------
void sub_A9722()
{
  int16_t v0; // cx
  int16_t i; // si
  int v2; // edi
  _DWORD *v3; // eax
  int v4; // ecx
  char v5; // dl
  int v6; // eax
  _BYTE v7[16]; // [esp+0h] [ebp-14h] BYREF
  unsigned int v8; // [esp+10h] [ebp-4h]

  v0 = 67;
  for ( i = 0; i < 4; ++i )
  {
    v2 = 0;
    do
    {
      v3 = sub_126B42((int)aBeamsLbx, v0, dword_192ED4);
      v8 = 32 * (int16_t)v2;
      ++v0;
      ++v2;
      dword_19D510[2 * i + v8 / 4] = (int)v3;
    }
    while ( (int16_t)v2 < 5 );
  }
  v4 = 0;
  v5 = 30;
  do
  {
    v6 = (int16_t)v4++;
    v7[v6] = v5;
    v5 += 4;
  }
  while ( (int16_t)v4 < 16 );
  sub_12E9A1(dword_192ED4, (int)v7, 16);
  JUMPOUT(0xA9FC4);
}
// A979D: control flows out of bounds to A9FC4
// 192ED4: using guessed type int dword_192ED4;
// 19D510: using guessed type int dword_19D510[43];


//----- (000A97A2) --------------------------------------------------------
void sub_A97A2()
{
  int16_t *v0; // edi
  int16_t i; // si
  int v2; // ebx
  int v3; // eax
  int v4; // [esp+0h] [ebp-4h]

  v0 = 0;
  while ( 1 )
  {
    for ( i = 0; i < 4; ++i )
    {
      v4 = 0;
      do
      {
        v2 = sub_A97F7(i, (int16_t)v0, 0, 0);
        ++v4;
        v3 = sub_12A478(0, 0, v2);
        sub_1077D(v3, 0, v2, v0);
      }
      while ( (int16_t)v4 < 10 );
      sub_6497C();
    }
    v0 = (int16_t *)((char *)v0 + 1);
    if ( (int16_t)v0 >= 8 )
      JUMPOUT(0xA9FC4);
  }
}
// A97F2: control flows out of bounds to A9FC4


//----- (000A97F7) --------------------------------------------------------
int __fastcall sub_A97F7( int a1, int a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  int v8; // ecx

  if ( a2 >= 4 )
  {
    v4 = 5 * (a2 - 4);
    v5 = a1;
    v6 = v4 + 133;
    return sub_127C27((int)aBeamsLbx, v6 + v5, dword_193174);
  }
  if ( a4 )
    return sub_127C27((int)aBeamsLbx, a2 + 129, dword_193174);
  if ( a3 )
  {
    v8 = 5 * a2;
    v5 = a1;
    v6 = v8 + 109;
    return sub_127C27((int)aBeamsLbx, v6 + v5, dword_193174);
  }
  return dword_19D510[8 * a1 + 2 * a2];
}
// A9843: conditional instruction was optimized away because dx.2<4
// 193174: using guessed type int dword_193174;
// 19D510: using guessed type int dword_19D510[43];


//----- (000A9867) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=87)) - nutno dohledat rucne v IDA @ 0xA9930 */
int __fastcall sub_A9867(_DWORD, _DWORD, _DWORD, _DWORD)
{
  DECOMP_TODO("call analysis failed (funcsize=87)");
}


//----- (000A999F) --------------------------------------------------------
void __fastcall sub_A999F(int a1, int a2, int a3, int a4, int a5)
{
  int16_t v6; // dx
  int16_t v7; // cx
  int16_t v8; // bx
  int v9; // kr00_4
  int v10; // edi
  int v11; // eax
  int16_t v12; // [esp+0h] [ebp-14h]
  int v13; // [esp+0h] [ebp-14h]
  int v14; // [esp+8h] [ebp-Ch] BYREF
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v15 = a4;
  v6 = *(uint8_t *)(313 * a3 + dword_192864 + 37);
  v7 = sub_A9AAD(v6);
  v8 = sub_A9F9E(v15);
  v14 = 0;
  v9 = (uint8_t)byte_182477[sub_A9AAD(v6)];
  v10 = a2 - v9 / 2;
  v13 = v12 - v9 / 2;
  v11 = sub_A97F7(v8, v7, 0, 0);
  LOWORD(v11) = *(_WORD *)(v11 + 4);
  v14 = v11 - 1;
  sub_A97F7(v8, v7, 0, 0);
  if ( a5 )
  {
    byte_18243D = 1;
    v14 = 0;
  }
  else
  {
    byte_18243D = 0;
  }
  sub_128AB6(0, 0, 639, 350);
  sub_12B634();
  sub_A9618((int16_t *)&v14);
  sub_A9AED(v13, v10, v16, 0, 0, v15, v14);
  sub_12B65C();
  sub_128BE7();
  JUMPOUT(0xA9AA7);
}
// A9AA4: control flows out of bounds to A9AA7
// A99F7: variable 'v12' is possibly undefined
// 18243D: using guessed type char byte_18243D;
// 192864: using guessed type int dword_192864;


//----- (000A9AAD) --------------------------------------------------------
int16_t __fastcall sub_A9AAD( int a1)
{
  _DWORD v2[3]; // [esp+0h] [ebp-Ch]

  v2[0] = sub_10000;
  v2[1] = 131073;
  v2[2] = dword_A65F4[1];
  return *((_WORD *)v2 + a1);
}
// 10000: using guessed type int sub_10000();
// A65F4: using guessed type int[2];


//----- (000A9AC8) --------------------------------------------------------
void sub_A9AC8()
{
  JUMPOUT(0xA9ABF);
}
// A9ADB: control flows out of bounds to A9ABF


//----- (000A9AED) --------------------------------------------------------
void __fastcall sub_A9AED( int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // edi
  int16_t *v13; // esi
  int16_t *v14; // edi
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // edx
  int16_t v22; // ax
  int v23; // eax
  int16_t v24; // dx
  int16_t v25; // ax
  int v26; // ebx
  int16_t *v27; // edx
  int v28; // eax
  int16_t v29; // bx
  int v30; // edx
  int16_t v31; // ax
  int v32; // eax
  _DWORD *v33; // eax
  int v38; // [esp+20h] [ebp-40h]
  int16_t v39; // [esp+24h] [ebp-3Ch] BYREF
  int v40; // [esp+28h] [ebp-38h]
  int v41; // [esp+2Ch] [ebp-34h]
  int v42; // [esp+30h] [ebp-30h]
  int16_t v43; // [esp+34h] [ebp-2Ch] BYREF
  int v44; // [esp+38h] [ebp-28h]
  int v45; // [esp+3Ch] [ebp-24h]
  int v46; // [esp+40h] [ebp-20h]
  int16_t v47; // [esp+44h] [ebp-1Ch] BYREF
  int16_t v48; // [esp+48h] [ebp-18h] BYREF
  int v49; // [esp+4Ch] [ebp-14h] BYREF
  int v50; // [esp+50h] [ebp-10h]
  int v51; // [esp+54h] [ebp-Ch]
  int v52; // [esp+58h] [ebp-8h]
  int v53; // [esp+5Ch] [ebp-4h] BYREF

  LOWORD(v7) = sub_A9F9E(a6);
  v50 = v7;
  sub_A9FCB();
  v42 = v8;
  if ( word_182483 )
  {
    if ( a3 )
    {
      HIWORD(v9) = HIWORD(dword_192864);
      LOWORD(v9) = *(uint8_t *)(dword_192864 + 313 * a3 + 37);
      v41 = v9;
      LOWORD(v10) = sub_A9AAD(v9);
    }
    else
    {
      v9 = dword_192864;
      v41 = *(uint8_t *)(dword_192864 + 37) + 6;
      sub_A9AC8();
    }
    v46 = v10;
    v11 = (int16_t)v10;
    v12 = (uint8_t)byte_182477[(int16_t)v10] * (uint8_t)byte_182477[(int16_t)v10] + 32;
    sub_1112EC(dword_192ED4, v9);
    v13 = (int16_t *)sub_110D3C(dword_192ED4, v12);
    sub_12D8F5((uint8_t)byte_182477[v11], (uint8_t)byte_182477[v11], (int)v13);
    v14 = (int16_t *)sub_110D3C(dword_192ED4, v12);
    sub_12D8F5((uint8_t)byte_182477[v11], (uint8_t)byte_182477[v11], (int)v14);
    if ( a7 || dword_18246B )
    {
      if ( a7 >= *(int16_t *)(sub_A97F7(v50, v46, a4, a5) + 6) - 1 || dword_18246B && !word_182483 )
      {
        sub_112C96(dword_18246B, 10);
        dword_18246B = 0;
      }
    }
    else
    {
      if ( word_18248B )
        v15 = 42;
      else
        v15 = 38;
      dword_18246B = sub_147D7(v15);
      if ( a3 )
        v16 = -2500 * (int16_t)v41;
      else
        v16 = -15000;
      sub_112CD9(dword_18246B, v16);
    }
    v38 = a7 % *(_WORD *)(sub_A97F7(v50, v46, a4, a5) + 6);
    v17 = sub_A97F7(v50, v46, a4, a5);
    sub_12B753(v17, v38);
    v18 = sub_A97F7(v50, v46, a4, a5);
    sub_12F578((int)v13, v18);
    switch ( (int16_t)v42 )
    {
      case 0:
        sub_12DAFC((int)v13);
        goto LABEL_20;
      case 1:
        v27 = v13;
        v28 = (int)v14;
        v29 = 0;
        goto LABEL_25;
      case 2:
        sub_12DFB2((int)v14, v13, 3);
        sub_12DFB2((int)v13, v14, 0);
LABEL_20:
        v19 = (int)v13;
        v20 = (int)v14;
        goto LABEL_21;
      case 3:
        v29 = 3;
        v27 = v13;
        v28 = (int)v14;
LABEL_25:
        sub_12DFB2(v28, v27, v29);
        v19 = (int)v14;
        v20 = (int)v13;
LABEL_21:
        sub_12F578(v20, v19);
        break;
      default:
        break;
    }
    if ( a3 )
    {
      sub_32B26(a3, 0, 0, 0);
      HIWORD(v21) = HIWORD(dword_192864);
      v22 = sub_A9AAD(*(uint8_t *)(dword_192864 + 313 * a3 + 37));
      LOWORD(v21) = (uint8_t)byte_182477[v22];
      v23 = (uint8_t)byte_182477[v22];
      v40 = v21;
      v23 /= 2;
      v45 = v23 + a1;
      v44 = v23 + a2;
      sub_49ED1(a3, &v49, &v53);
      v45 -= v49;
      v44 -= v53;
      sub_34454(a3, &v49, &v53);
      v45 += v49;
      v44 += v53;
      sub_131528((_WORD *)dword_19283C, &v39, &v48, &v43, &v47);
      sub_12EB23(v43 / 2 - (int16_t)v40 / 2, v47 / 2 - (int16_t)v40 / 2, (_WORD *)dword_19283C, (int *)v13, 0xF0u);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      v24 = v44;
      v25 = v45;
      v26 = dword_19283C;
    }
    else
    {
      HIWORD(v30) = HIWORD(dword_1930D4);
      sub_A9AC8();
      LOWORD(v30) = (uint8_t)byte_182477[v31];
      v32 = (uint8_t)byte_182477[v31];
      v40 = v30;
      v52 = v32 / 2 + a1;
      v51 = v32 / 2 + a2;
      sub_49ED1(0, &v49, &v53);
      v52 -= v49;
      v51 -= v53;
      sub_34454(0, &v49, &v53);
      v52 += v49;
      v51 += v53;
      sub_12F578((int)v14, dword_19285C);
      sub_131528(v14, &v39, &v48, &v43, &v47);
      sub_12EB23(v43 / 2 - (int16_t)v40 / 2, v47 / 2 - (int16_t)v40 / 2, v14, (int *)v13, 0xF0u);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      v24 = v51;
      v25 = v52;
      v26 = (int)v14;
    }
    sub_12A478(v25, v24, v26);
    sub_12DAFC((int)v13);
    sub_12A478(a1, a2, (int)v13);
    v33 = sub_1113CC(dword_192ED4, a2);
    sub_1171AB((int)v33, a2, (int)v13, 350);
  }
  JUMPOUT(0xA93A4);
}
// A9F99: control flows out of bounds to A93A4
// A9B02: variable 'v7' is possibly undefined
// A9B0C: variable 'v8' is possibly undefined
// A9B8F: variable 'v10' is possibly undefined
// A9E93: variable 'v31' is possibly undefined
// 18246B: using guessed type int dword_18246B;
// 182483: using guessed type int16_t word_182483;
// 18248B: using guessed type int16_t word_18248B;
// 19283C: using guessed type int dword_19283C;
// 19285C: using guessed type int dword_19285C;
// 192864: using guessed type int dword_192864;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 1930D4: using guessed type int dword_1930D4;
// 199878: using guessed type int16_t word_199878;


//----- (000A9F9E) --------------------------------------------------------
int16_t __fastcall sub_A9F9E( int a1)
{
  _WORD v2[16]; // [esp+0h] [ebp-20h] BYREF

  qmemcpy(v2, &off_A6606, sizeof(v2));
  return v2[a1 % 16];
}
// A6606: using guessed type void (__noreturn *off_A6606)();


//----- (000A9FCB) --------------------------------------------------------
void sub_A9FCB()
{
  JUMPOUT(0xA9FBD);
}
// A9FEA: control flows out of bounds to A9FBD


//----- (000A9FFC) --------------------------------------------------------
int __fastcall sub_A9FFC(int16_t *a1)
{
  int result; // eax
  int16_t v3; // bx
  int v4; // kr00_4

  result = sub_127C27((int)aBeamsLbx, 89, dword_193174);
  v3 = *(_WORD *)(result + 6);
  if ( word_18248B || !word_182489 )
  {
    LOWORD(result) = word_182489;
    v4 = result;
    result = (uint16_t)word_182489;
    switch ( word_182489 )
    {
      case 0:
        if ( byte_18243E || word_18248B >= 1 )
        {
          word_182489 = 1;
          *a1 = 0;
        }
        break;
      case 1:
        if ( ++*a1 >= 4 )
          word_182489 = 2;
        break;
      case 2:
        ++*a1;
        if ( byte_18243E )
        {
          if ( *a1 >= 7 )
            *a1 = 4;
        }
        else if ( *a1 >= 7 )
        {
          word_182489 = 3;
        }
        break;
      case 3:
        if ( v3 <= ++*a1 )
        {
          word_182489 = 0;
          word_18248B = 0;
        }
        break;
      default:
        result = v4;
        break;
    }
  }
  else
  {
    word_182489 = 0;
  }
  return result;
}
// 18243E: using guessed type char byte_18243E;
// 182489: using guessed type int16_t word_182489;
// 18248B: using guessed type int16_t word_18248B;
// 193174: using guessed type int dword_193174;


//----- (000AA0E1) --------------------------------------------------------
int __fastcall sub_AA0E1(int result)
{
  int v1; // eax

  if ( (_BYTE)result )
  {
    v1 = sub_127C27((int)aBeamsLbx, 89, dword_193174);
    sub_12B79D(v1);
    return sub_131F7B();
  }
  return result;
}
// 193174: using guessed type int dword_193174;


//----- (000AA109) --------------------------------------------------------
int __fastcall sub_AA109( int a1, int a2)
{
  return sub_127C27((int)aBeamsLbx, (int16_t)(5 * a2 + 89 + a1), dword_193174);
}
// 193174: using guessed type int dword_193174;


//----- (000AA127) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=92)) - nutno dohledat rucne v IDA @ 0xAA1FF */
_DWORD sub_AA127(void)
{
  DECOMP_TODO("call analysis failed (funcsize=92)");
}


//----- (000AA281) --------------------------------------------------------
void __fastcall sub_AA281( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v6; // cx
  int16_t v7; // bx
  int v8; // kr00_4
  int v9; // esi
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int16_t v13; // cx
  int16_t v14; // bx
  int16_t v15; // [esp+0h] [ebp-14h]
  _DWORD v16[2]; // [esp+4h] [ebp-10h] BYREF
  int v17; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]

  v18 = a3;
  v17 = a4;
  v6 = a3;
  v7 = sub_A9AAD(a3);
  v15 = sub_A9F9E(v17);
  v16[0] = 0;
  v8 = (uint8_t)byte_182485[sub_A9AAD(v6)];
  v9 = a1 - v8 / 2;
  v10 = (int16_t)(v15 + 5 * v7 + 89);
  v11 = sub_127C27((int)aBeamsLbx, v10, dword_193174);
  LOWORD(v11) = *(_WORD *)(v11 + 4);
  v16[0] = v11 - 1;
  v12 = sub_127C27((int)aBeamsLbx, v10, dword_193174);
  LOWORD(v12) = *(_WORD *)(v12 + 6);
  v16[1] = v12;
  if ( a5 )
  {
    byte_18243E = 1;
    v16[0] = 0;
  }
  else
  {
    byte_18243E = 0;
  }
  sub_128AB6(0, 0, 639, 350);
  sub_12B634();
  v13 = v17;
  v14 = v18;
  sub_A9FFC((int16_t *)v16);
  sub_AA38D(v9, (int16_t)(a2 - v8 / 2), v14, v13, v16[0]);
  sub_12B65C();
  sub_128BE7();
  JUMPOUT(0xA9AA1);
}
// AA378: control flows out of bounds to A9AA1
// 18243E: using guessed type char byte_18243E;
// 193174: using guessed type int dword_193174;


//----- (000AA38D) --------------------------------------------------------
_DWORD *__fastcall sub_AA38D( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v5; // di
  int16_t v6; // ax
  int v7; // esi
  int16_t *v8; // ecx
  int v9; // edx
  int16_t *v10; // esi
  int v11; // eax
  int v12; // edi
  int v13; // eax
  int16_t *v14; // edx
  int v15; // eax
  int16_t v16; // bx
  int v17; // ebx
  int16_t v19; // [esp+0h] [ebp-10h]
  int16_t v21; // [esp+8h] [ebp-8h]
  int16_t v22; // [esp+Ch] [ebp-4h]
  int v23; // [esp+20h] [ebp+10h]

  v19 = a2;
  v5 = sub_A9F9E(a4);
  sub_A9FCB();
  v22 = v6;
  v21 = sub_A9AAD(a3);
  v7 = (uint8_t)byte_182477[v21] * (uint8_t)byte_182477[v21] + 32;
  sub_1112EC(dword_192ED4, a2);
  v8 = (int16_t *)sub_110D3C(dword_192ED4, v7);
  v9 = v7;
  v10 = (int16_t *)sub_110D3C(dword_192ED4, v7);
  if ( word_182489 )
  {
    if ( a5 || dword_18246F )
    {
      if ( a5 >= *(int16_t *)(sub_127C27((int)aBeamsLbx, (int16_t)(v5 + 5 * v21 + 89), dword_193174) + 6) - 1 )
      {
        sub_112C96(dword_18246F, 10);
        dword_18246F = 0;
      }
    }
    else
    {
      if ( word_18248B )
        v11 = 42;
      else
        v11 = 38;
      dword_18246F = sub_147D7(v11);
      sub_112CD9(dword_18246F, -2500 * a3);
    }
    v12 = (int16_t)(v5 + 5 * v21 + 89);
    v23 = a5 % *(int16_t *)(sub_127C27((int)aBeamsLbx, v12, dword_193174) + 6);
    v13 = sub_127C27((int)aBeamsLbx, v12, dword_193174);
    sub_12B753(v13, (int16_t)v23);
    v9 = sub_127C27((int)aBeamsLbx, v12, dword_193174);
    sub_12F578((int)v8, v9);
    switch ( v22 )
    {
      case 0:
        goto LABEL_15;
      case 1:
        v14 = v8;
        v15 = (int)v10;
        v16 = 0;
        goto LABEL_12;
      case 2:
        sub_12DFB2((int)v10, v8, 3);
        sub_12DFB2((int)v8, v10, 0);
LABEL_15:
        v9 = v19;
        sub_12DAFC((int)v8);
        v17 = (int)v8;
        goto LABEL_16;
      case 3:
        v16 = 3;
        v14 = v8;
        v15 = (int)v10;
LABEL_12:
        sub_12DFB2(v15, v14, v16);
        v9 = v19;
        sub_12DAFC((int)v10);
        v17 = (int)v10;
LABEL_16:
        sub_12A478(a1, v9, v17);
        break;
      default:
        return sub_1113CC(dword_192ED4, v9);
    }
  }
  return sub_1113CC(dword_192ED4, v9);
}
// AA3A8: variable 'v6' is possibly undefined
// 18246F: using guessed type int dword_18246F;
// 182489: using guessed type int16_t word_182489;
// 18248B: using guessed type int16_t word_18248B;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;


//----- (000AA55B) --------------------------------------------------------
_BOOL1 __fastcall sub_AA55B( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v5; // bx
  int16_t v6; // cx
  int16_t v7; // dx
  int v8; // eax
  int v9; // eax
  _BOOL1 result; // al

  v5 = a1 - a3;
  v6 = a2 - a4;
  v7 = (uint8_t)byte_182485[sub_A9AAD(a5)] / 2;
  if ( v5 >= 0 )
    v8 = v5;
  else
    v8 = -v5;
  result = 0;
  if ( v8 <= v7 )
  {
    v9 = v6 >= 0 ? v6 : -v6;
    if ( v9 <= v7 )
      return 1;
  }
  return result;
}


//----- (000AA5B6) --------------------------------------------------------
int __fastcall sub_AA5B6(
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
        unsigned int a13,
        signed int a14,
        int a15,
        int a16)
{
  int v17; // ecx
  signed int v18; // ebx
  signed int v19; // eax
  signed int v20; // eax
  int v21; // eax
  int v22; // ebx

  v17 = a15;
  if ( a13 > 1 )
  {
    if ( a16 == 1 || !a5 )
      return 9;
    else
      return 7;
  }
  else
  {
    v18 = abs32(a3 - a1);
    v19 = abs32(a4 - a2);
    if ( v18 <= v19 )
      v18 = v19;
    if ( v18 / a15 > 6 )
      v17 = 2 * a15;
    if ( v18 < a14 )
      v20 = v18;
    else
      v20 = v18 + v17 / 2;
    v21 = v20 / v17;
    if ( v21 < 3 )
      v21 = 3;
    v22 = v21 + 9;
    if ( a16 != 1 && a5 )
      return v21 + 7;
  }
  return v22;
}


//----- (000AA657) --------------------------------------------------------
int __fastcall sub_AA657(
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
        unsigned int a14,
        unsigned int a15,
        int a16,
        int a17, int a18)
{
  int v18; // ecx
  int v19; // esi
  int v20; // eax
  int result; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // edi
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // edx
  int v31; // edx
  int v32; // ecx
  int16_t v33; // cx
  int16_t v34; // ax
  int v35; // ecx
  int16_t v36; // bx
  int16_t v37; // [esp-10h] [ebp-60h]
  int16_t v38; // [esp-10h] [ebp-60h]
  int16_t v39; // [esp-Ch] [ebp-5Ch]
  int16_t v40; // [esp-8h] [ebp-58h]
  int v44; // [esp+10h] [ebp-40h] BYREF
  int v45; // [esp+14h] [ebp-3Ch] BYREF
  int v46; // [esp+18h] [ebp-38h] BYREF
  int v47[3]; // [esp+1Ch] [ebp-34h] BYREF
  int v48; // [esp+28h] [ebp-28h]
  int v49; // [esp+2Ch] [ebp-24h]
  int v50; // [esp+30h] [ebp-20h]
  int v51; // [esp+34h] [ebp-1Ch]
  int v52; // [esp+38h] [ebp-18h]
  int v53; // [esp+3Ch] [ebp-14h]
  int v54; // [esp+40h] [ebp-10h]
  int v55; // [esp+44h] [ebp-Ch]
  int v56; // [esp+48h] [ebp-8h]
  int v57; // [esp+4Ch] [ebp-4h]

  v18 = a3 - a1;
  v19 = a4 - a2;
  if ( (int)abs32(a3 - a1) <= (int)abs32(a4 - a2) )
  {
    v20 = a4 - a2;
    v50 = 1;
  }
  else
  {
    v20 = a3 - a1;
    v50 = 0;
  }
  result = abs32(v20);
  v56 = result;
  if ( result )
  {
    if ( v56 / a17 > 6 )
      a17 *= 2;
    if ( a1 >= a3 )
    {
      v53 = a3;
      v22 = a1;
    }
    else
    {
      v53 = a1;
      v22 = a3;
    }
    v52 = v22;
    if ( a2 >= a4 )
    {
      v54 = a4;
      v23 = a2;
    }
    else
    {
      v54 = a2;
      v23 = a4;
    }
    v55 = v23;
    if ( a15 > 1 )
    {
      v25 = 1;
    }
    else
    {
      if ( a16 - a17 / 3 > v56 )
        v24 = v56;
      else
        v24 = v56 + 2 * a17 / 3;
      v25 = v24 / a17;
      if ( v24 / a17 < 3 )
        v25 = 3;
      v51 = a6 + 1;
    }
    if ( !a15 )
    {
      v57 = 3;
      v47[2] = a6 * v19;
      v47[1] = a6 * v18;
      v49 = a6 * a6 * v19;
      v48 = a6 * a6 * v18;
      if ( a16 - a17 / 3 > v56 )
      {
        if ( 2 * a6 * a6 * a6 > v56 )
        {
          v47[0] = a3;
          v45 = a4;
        }
        else
        {
          v47[0] = 2 * a6 * a6 * a6 * v18 / v56 + a1;
          v45 = 2 * a6 * v49 / v56 + a2;
        }
        if ( a6 >= v25 )
          goto LABEL_30;
        goto LABEL_31;
      }
      v26 = a16 / a17;
      if ( a6 > a16 / a17 )
      {
        if ( a6 > v25 + v26 )
        {
          v47[0] = a3;
          v45 = a4;
LABEL_29:
          if ( a6 >= v25 )
          {
LABEL_30:
            v46 = a3;
            v44 = a4;
            goto LABEL_63;
          }
LABEL_31:
          v46 = v18 * v51 / v25 + a1;
          v44 = v19 * v51 / v25 + a2;
          goto LABEL_63;
        }
        v57 = a6 - v26;
        v47[0] = v18 * (a6 - v26) / v25 + a1;
        v27 = v19 * (a6 - v26) / v25;
      }
      else
      {
        v47[0] = 2 * v48 / v56 + a1;
        v27 = 2 * v49 / v56;
      }
      v45 = v27 + a2;
      goto LABEL_29;
    }
    if ( a15 != 1 )
      goto LABEL_63;
    if ( a6 < v25 )
    {
      v57 = a6 + 1;
      v46 = v18 * (a6 + 1) / v25 + a1;
      v44 = v19 * (a6 + 1) / v25 + a2;
    }
    else
    {
      v46 = a3;
      v44 = a4;
    }
    if ( a6 >= v25 + a16 / a17 )
    {
      v47[0] = a3;
      v45 = a4;
      goto LABEL_63;
    }
    if ( a6 >= v25 )
    {
      v31 = a16 / a17;
      if ( a16 / a17 < 1 )
        v31 = 1;
      v29 = a17 * (v31 + v25 - a6 - 1);
      if ( !v50 )
      {
        v57 = v18 * v29;
        v28 = v18 * v29 / (int)abs32(v18);
        goto LABEL_45;
      }
    }
    else
    {
      if ( !v50 )
      {
        v57 = abs32(v18);
        v28 = v18 * a16 / v57;
LABEL_45:
        v47[0] = v46 - v28;
        if ( v18 > 0 && v46 - v28 < a1 || v18 < 0 && v47[0] > a1 )
          v47[0] = a1;
        v45 = v19 * (v47[0] - v46) / v18 + v44;
        goto LABEL_63;
      }
      v29 = a16;
    }
    v57 = v19 * v29;
    v30 = v44 - v19 * v29 / (int)abs32(v19);
    v45 = v30;
    if ( v19 > 0 && v30 < a2 || v19 < 0 && v45 > a2 )
      v45 = a2;
    v47[0] = v18 * (v45 - v44) / v19 + v46;
LABEL_63:
    if ( v47[0] < v53 || v45 < v54 )
    {
      v47[0] = v53;
      v45 = v54;
    }
    if ( v47[0] > v52 || v45 > v55 )
    {
      v47[0] = v52;
      v45 = v55;
    }
    if ( v46 < v53 || v44 < v54 )
    {
      v46 = v53;
      v44 = v54;
    }
    if ( v46 > v52 || v44 > v55 )
    {
      v46 = v52;
      v44 = v55;
    }
    if ( v47[0] == v46 && v45 == v44 )
      goto LABEL_85;
    v32 = a6 % 2;
    switch ( a15 )
    {
      case 0u:
        if ( a6 )
        {
          if ( a6 != 1 )
          {
            v33 = 3;
            v34 = 12;
            goto LABEL_84;
          }
          v33 = 6;
        }
        else
        {
          sub_1330D2(v47, &v46);
          sub_1330D2(&v45, &v44);
          v33 = 3;
        }
        v34 = 10;
LABEL_84:
        sub_13BAFB(v47[0], v45, v46, v44, a7, 12, 30, 3, a6, 0, 0, 1, 1, 0, 0, v34, v33, 4, 0);
LABEL_85:
        sub_AAC37(a7, a8, a9, a10, a11, a12, a13, a14);
        return sub_131F7B();
      case 1u:
        sub_13C22C(v47[0], v45, v46, v44, a7, 12, 50, 3, a6, 0, 1, a16 >= 10, 1, 0, 0, 12, 3, 2 * a18 + 7, 1, 2, 0);
        goto LABEL_85;
      case 2u:
        v35 = a6 % 2 + 1;
        v40 = 4 / v35;
        v39 = 8 / v35;
        v37 = 12 / v35;
        LOWORD(v35) = a4 + sub_1247A0(5u) - 3;
        v36 = a3 + sub_1247A0(5u) - 3;
        sub_13BAFB(a1, a2, v36, v35, a7, 12, 100, 4, 4 * a6, 0, 0, 0, 0, 1, 0, v37, v39, v40, 0);
        goto LABEL_85;
      case 3u:
        v38 = 5 / (2 * v32 + 1) + 1;
        sub_13C22C(
          a1,
          a2,
          a3,
          a4,
          a7,
          16,
          100,
          3,
          2 * a6,
          1,
          0,
          0,
          0,
          1,
          0,
          21 / (v32 + 2),
          21 / (v32 + 2),
          v38,
          v38,
          2 / (a6 % 2 + 1),
          2 / (a6 % 2 + 1));
        goto LABEL_85;
      default:
        goto LABEL_85;
    }
  }
  return result;
}


//----- (000AAC37) --------------------------------------------------------
void __fastcall sub_AAC37(int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned int a8)
{
  int v9; // ecx
  int i; // ebx
  int v11; // eax
  int v12; // esi
  int v13; // ebx
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // ebx
  int v23; // ecx
  int v24; // eax
  int j; // ebx
  int v26; // eax
  int v27; // ebx
  int v28; // eax
  char v29; // cl
  int v30; // [esp+0h] [ebp-E2h]
  _DWORD v31[81]; // [esp+4h] [ebp-DEh]
  int v32; // [esp+148h] [ebp+66h]
  int v33; // [esp+14Ch] [ebp+6Ah]
  int v34; // [esp+150h] [ebp+6Eh]

  v33 = a4;
  v9 = 0;
  for ( i = 0; i != 7; ++i )
  {
    v31[v9 + 4] = dword_182490[i] * v30 / 100;
    v31[v9 + 2] = a3 * dword_182490[i] / 100;
    v11 = dword_182490[i] * v33 / 100;
    v9 += 3;
    v31[v9] = v11;
  }
  v12 = 115;
  v13 = 24;
  v31[23] = a3;
  v31[25] = v30;
  v14 = 0;
  v31[24] = v33;
  while ( 1 )
  {
    if ( a8 )
    {
      if ( a8 <= 1 )
      {
        v18 = v12 * dword_1825D0[v14] * v30;
        v34 = 100;
        v32 = 100 - dword_1825D0[v14];
        v34 = 100;
        v31[v13 + 4] = (v32 * a5 + v18 / 100) / 100;
        v19 = v12 * a3 * dword_1825D0[v14];
        v34 = 100;
        v31[v13 + 2] = (v32 * a6 + v19 / 100) / 100;
        v17 = dword_1825D0[v14] * v33;
      }
      else
      {
        if ( a8 != 2 )
          goto LABEL_12;
        v20 = v12 * dword_1826C0[v14] * v30;
        v34 = 100;
        v32 = 100 - dword_1826C0[v14];
        v34 = 100;
        v31[v13 + 4] = (v32 * a5 + v20 / 100) / 100;
        v21 = v12 * a3 * dword_1826C0[v14];
        v34 = 100;
        v31[v13 + 2] = (v32 * a6 + v21 / 100) / 100;
        v17 = dword_1826C0[v14] * v33;
      }
    }
    else
    {
      v15 = v12 * dword_1824E0[v14] * v30;
      v34 = 100;
      v32 = 100 - dword_1824E0[v14];
      v34 = 100;
      v31[v13 + 4] = (v32 * a5 + v15 / 100) / 100;
      v16 = v12 * a3 * dword_1824E0[v14];
      v34 = 100;
      v31[v13 + 2] = (v32 * a6 + v16 / 100) / 100;
      v17 = dword_1824E0[v14] * v33;
    }
    v34 = 100;
    v31[v13 + 3] = (v32 * a7 + v12 * v17 / 100) / 100;
LABEL_12:
    if ( (int)v31[v13 + 4] > 255 )
      v31[v13 + 4] = 255;
    if ( (int)v31[v13 + 2] > 255 )
      v31[v13 + 2] = 255;
    if ( (int)v31[v13 + 3] > 255 )
      v31[v13 + 3] = 255;
    v12 += 15;
    ++v14;
    v13 += 3;
    if ( v14 == 4 )
    {
      v31[40] = a5;
      v22 = 39;
      v31[38] = a6;
      v23 = 0;
      v31[39] = a7;
      while ( a8 )
      {
        if ( a8 <= 1 )
        {
          v31[v22 + 4] = dword_182620[v23] * a5 / 100;
          v31[v22 + 2] = dword_182620[v23] * a6 / 100;
          v24 = dword_182620[v23] * a7;
          goto LABEL_27;
        }
        if ( a8 == 2 )
        {
          v31[v22 + 4] = dword_182710[v23] * a5 / 100;
          v31[v22 + 2] = dword_182710[v23] * a6 / 100;
          v24 = dword_182710[v23] * a7;
          goto LABEL_27;
        }
LABEL_28:
        if ( (int)v31[v22 + 4] > 255 )
          v31[v22 + 4] = 255;
        if ( (int)v31[v22 + 2] > 255 )
          v31[v22 + 2] = 255;
        if ( (int)v31[v22 + 3] > 255 )
          v31[v22 + 3] = 255;
        ++v23;
        v22 += 3;
        if ( v23 == 3 )
        {
          for ( j = 0; j != 48; v31[j] = v26 )
          {
            v31[j + 4] = (v31[j + 4] - (__CFSHL__((int)v31[j + 4] >> 31, 2) + 4 * ((int)v31[j + 4] >> 31))) >> 2;
            v31[j + 2] = (v31[j + 2] - (__CFSHL__((int)v31[j + 2] >> 31, 2) + 4 * ((int)v31[j + 2] >> 31))) >> 2;
            v26 = (v31[j + 3] - (__CFSHL__((int)v31[j + 3] >> 31, 2) + 4 * ((int)v31[j + 3] >> 31))) >> 2;
            j += 3;
          }
          v27 = 0;
          v28 = 4 * v31[0];
          do
          {
            v28 += 4;
            byte_1BB354[v28] = 1;
            byte_1BB355[v28] = v31[v27 + 4];
            byte_1BB356[v28] = v31[v27 + 2];
            v29 = v31[v27 + 3];
            v27 += 3;
            byte_1BB357[v28] = v29;
          }
          while ( v27 != 48 );
          JUMPOUT(0xA902A);
        }
      }
      v31[v22 + 4] = dword_182530[v23] * a5 / 100;
      v31[v22 + 2] = dword_182530[v23] * a6 / 100;
      v24 = dword_182530[v23] * a7;
LABEL_27:
      v31[v22 + 3] = v24 / 100;
      goto LABEL_28;
    }
  }
}
// AB117: control flows out of bounds to A902A
// AAC56: variable 'v30' is possibly undefined
// 182490: using guessed type int dword_182490[];
// 1824E0: using guessed type int dword_1824E0[];
// 182530: using guessed type int dword_182530[];
// 1825D0: using guessed type int dword_1825D0[];
// 182620: using guessed type int dword_182620[];
// 1826C0: using guessed type int dword_1826C0[];
// 182710: using guessed type int dword_182710[];


//----- (000AB11C) --------------------------------------------------------
int __fastcall sub_AB11C( unsigned int a1, int a2, void *a3)
{
  int result; // eax
  _BOOL1 v5; // zf
  _BYTE *v6; // esi
  void *v7; // edi
  _BYTE v8[44]; // [esp+0h] [ebp-31Eh] BYREF
  _BYTE v9[44]; // [esp+2Ch] [ebp-2F2h] BYREF
  _BYTE v10[44]; // [esp+58h] [ebp-2C6h] BYREF
  _BYTE v11[44]; // [esp+84h] [ebp-29Ah] BYREF
  _BYTE v12[44]; // [esp+B0h] [ebp-26Eh] BYREF
  _BYTE v13[44]; // [esp+DCh] [ebp-242h] BYREF
  _BYTE v14[44]; // [esp+108h] [ebp-216h] BYREF
  _BYTE v15[44]; // [esp+134h] [ebp-1EAh] BYREF
  _BYTE v16[44]; // [esp+160h] [ebp-1BEh] BYREF
  _BYTE v17[44]; // [esp+18Ch] [ebp-192h] BYREF
  _BYTE v18[44]; // [esp+1B8h] [ebp-166h] BYREF
  _BYTE v19[44]; // [esp+1E4h] [ebp-13Ah] BYREF
  _BYTE v20[44]; // [esp+210h] [ebp-10Eh] BYREF
  _BYTE v21[44]; // [esp+23Ch] [ebp-E2h] BYREF
  _BYTE v22[44]; // [esp+268h] [ebp-B6h] BYREF
  _BYTE v23[44]; // [esp+294h] [ebp-8Ah] BYREF
  _BYTE v24[44]; // [esp+2C0h] [ebp-5Eh] BYREF
  _BYTE v25[44]; // [esp+2ECh] [ebp-32h] BYREF
  _BYTE v26[44]; // [esp+318h] [ebp-6h] BYREF
  _BYTE v27[44]; // [esp+344h] [ebp+26h] BYREF
  _BYTE v28[44]; // [esp+370h] [ebp+52h] BYREF
  _BYTE v29[44]; // [esp+39Ch] [ebp+7Eh] BYREF

  result = (int)a3;
  if ( a1 >= 9u )
  {
    if ( a1 <= 9u )
      goto LABEL_54;
    if ( a1 >= 0x28u )
    {
      if ( a1 <= 0x28u )
        return memset(a3, 0, 44);
      if ( a1 >= 0x2Au )
      {
        if ( a1 > 0x2Au )
        {
          if ( a1 <= 0x2Bu )
            return memset(a3, 0, 44);
          v5 = a1 == 46;
          goto LABEL_9;
        }
        goto LABEL_58;
      }
LABEL_54:
      if ( (a2 & 0x10) != 0 )
      {
        qmemcpy(v22, &word_A6906, sizeof(v22));
        v6 = v22;
      }
      else
      {
        qmemcpy(v29, &word_A6932, sizeof(v29));
        v6 = v29;
      }
      goto LABEL_33;
    }
    if ( a1 < 0xBu )
    {
      qmemcpy(v24, &word_A695E, sizeof(v24));
      v6 = v24;
    }
    else
    {
      if ( a1 <= 0xBu )
      {
LABEL_58:
        qmemcpy(v19, &word_A698A, sizeof(v19));
        v6 = v19;
LABEL_33:
        v7 = a3;
        goto LABEL_30;
      }
      if ( a1 > 0xCu )
      {
        v5 = a1 == 27;
LABEL_9:
        if ( !v5 )
          return result;
        return memset(a3, 0, 44);
      }
      if ( (a2 & 0x10) != 0 )
      {
        qmemcpy(v20, &word_A69B6, sizeof(v20));
        v6 = v20;
      }
      else
      {
        qmemcpy(v21, &word_A69E2, sizeof(v21));
        v6 = v21;
      }
    }
LABEL_29:
    v7 = a3;
LABEL_30:
    qmemcpy(v7, v6, 0x2Cu);
    return result;
  }
  if ( a1 >= 4u )
  {
    if ( a1 <= 4u )
    {
      if ( (a2 & 0x10) != 0 )
      {
        qmemcpy(v26, &word_A67FE, sizeof(v26));
        v6 = v26;
      }
      else
      {
        qmemcpy(v25, &word_A682A, sizeof(v25));
        v6 = v25;
      }
    }
    else if ( a1 < 6u )
    {
      if ( (a2 & 0x10) == 0 || (a2 & 0x100) == 0 )
      {
        if ( (a2 & 0x10) != 0 )
        {
          qmemcpy(v13, &word_A6672, sizeof(v13));
          v6 = v13;
        }
        else if ( (a2 & 0x100) != 0 )
        {
          qmemcpy(v14, &word_A669E, sizeof(v14));
          v6 = v14;
        }
        else
        {
          qmemcpy(v15, &word_A66CA, sizeof(v15));
          v6 = v15;
        }
        goto LABEL_33;
      }
      qmemcpy(v8, &word_A6646, sizeof(v8));
      v6 = v8;
    }
    else if ( a1 <= 6u )
    {
      if ( (a2 & 0x10) != 0 )
      {
        qmemcpy(v16, &word_A66F6, sizeof(v16));
        v6 = v16;
      }
      else
      {
        qmemcpy(v17, &word_A6722, sizeof(v17));
        v6 = v17;
      }
    }
    else if ( a1 <= 7u )
    {
      if ( (a2 & 0x10) != 0 )
      {
        qmemcpy(v9, &word_A6856, sizeof(v9));
        v6 = v9;
      }
      else
      {
        qmemcpy(v10, &word_A6882, sizeof(v10));
        v6 = v10;
      }
    }
    else if ( (a2 & 0x10) != 0 )
    {
      qmemcpy(v11, &word_A68AE, sizeof(v11));
      v6 = v11;
    }
    else
    {
      qmemcpy(v12, &word_A68DA, sizeof(v12));
      v6 = v12;
    }
    goto LABEL_29;
  }
  if ( a1 >= 2u )
  {
    if ( a1 <= 2u )
    {
      qmemcpy(v23, &word_A677A, sizeof(v23));
      v6 = v23;
    }
    else if ( (a2 & 0x10) != 0 )
    {
      qmemcpy(v28, &word_A67A6, sizeof(v28));
      v6 = v28;
    }
    else
    {
      qmemcpy(v27, &word_A67D2, sizeof(v27));
      v6 = v27;
    }
    goto LABEL_29;
  }
  if ( a1 == 1 )
  {
    qmemcpy(v18, &word_A674E, sizeof(v18));
    v6 = v18;
    goto LABEL_29;
  }
  return result;
}
// A6646: using guessed type int16_t word_A6646;
// A6672: using guessed type int16_t word_A6672;
// A669E: using guessed type int16_t word_A669E;
// A66CA: using guessed type int16_t word_A66CA;
// A66F6: using guessed type int16_t word_A66F6;
// A6722: using guessed type int16_t word_A6722;
// A674E: using guessed type int16_t word_A674E;
// A677A: using guessed type int16_t word_A677A;
// A67A6: using guessed type int16_t word_A67A6;
// A67D2: using guessed type int16_t word_A67D2;
// A67FE: using guessed type int16_t word_A67FE;
// A682A: using guessed type int16_t word_A682A;
// A6856: using guessed type int16_t word_A6856;
// A6882: using guessed type int16_t word_A6882;
// A68AE: using guessed type int16_t word_A68AE;
// A68DA: using guessed type int16_t word_A68DA;
// A6906: using guessed type int16_t word_A6906;
// A6932: using guessed type int16_t word_A6932;
// A695E: using guessed type int16_t word_A695E;
// A698A: using guessed type int16_t word_A698A;
// A69B6: using guessed type int16_t word_A69B6;
// A69E2: using guessed type int16_t word_A69E2;
// A69EC: using guessed type int[10];
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (000AB52E) --------------------------------------------------------
int __fastcall sub_AB52E(
        int a1, int a2, int a3, int a4,
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
        unsigned int a18,
        int a19,
        int a20,
        int a21, int a22)
{
  int v23; // ebx
  int v24; // ecx
  int16_t v25; // cx
  int16_t v26; // ax
  int v28; // ecx
  int16_t v29; // bx
  int16_t v30; // [esp-3Ch] [ebp-48h]
  int16_t v31; // [esp-2Ch] [ebp-38h]
  int16_t v32; // [esp-10h] [ebp-1Ch]
  int16_t v33; // [esp-10h] [ebp-1Ch]
  int16_t v34; // [esp-Ch] [ebp-18h]
  int16_t v35; // [esp-8h] [ebp-14h]
  int16_t v36; // [esp+0h] [ebp-Ch]

  v23 = a10;
  if ( a5 != a7 || a6 != a8 )
  {
    v24 = a10 % 2;
    switch ( a10 / 2 )
    {
      case 0:
        if ( !a10 )
        {
          sub_1330D2(&a5, &a7);
          sub_1330D2(&a6, &a8);
        }
        if ( !v23 )
        {
          v25 = 3;
LABEL_8:
          v26 = 10;
          goto LABEL_12;
        }
        if ( v23 == 1 )
        {
          v25 = 6;
          goto LABEL_8;
        }
        v25 = 3;
        v26 = 12;
LABEL_12:
        sub_13BAFB(a5, a6, a7, a8, a11, 12, 30, 3, v23, 0, 0, 1, 1, 0, 0, v26, v25, 4, 0);
        break;
      case 1:
        sub_13C22C(a5, a6, a7, a8, a11, 12, 50, 3, a10, 0, 1, a20 >= 10, 1, 0, 0, 12, 3, 2 * a22 + 7, 1, 2, 0);
        break;
      case 2:
        v28 = a10 % 2 + 1;
        v35 = 4 / v28;
        v34 = 8 / v28;
        v32 = 12 / v28;
        v31 = 4 * a10;
        v30 = a11;
        LOWORD(v28) = a4 + sub_1247A0(5u) - 3;
        v29 = a3 + sub_1247A0(5u) - 3;
        sub_13BAFB(v36, a2, v29, v28, v30, 12, 100, 4, v31, 0, 0, 0, 0, 1, 0, v32, v34, v35, 0);
        break;
      case 3:
        v33 = 5 / (2 * v24 + 1) + 1;
        sub_13C22C(
          v36,
          a2,
          a3,
          a4,
          a11,
          16,
          100,
          3,
          2 * a10,
          1,
          0,
          0,
          0,
          1,
          0,
          21 / (v24 + 2),
          21 / (v24 + 2),
          v33,
          v33,
          2 / (a10 % 2 + 1),
          2 / (a10 % 2 + 1));
        break;
      default:
        break;
    }
  }
  sub_AAC37(a11, a12, a13, a14, a15, a16, a17, a18);
  return sub_131F7B();
}
// AB6ED: variable 'v36' is possibly undefined


//----- (000AB850) --------------------------------------------------------
void __fastcall sub_AB850( int a1, int a2)
{
  int16_t v2; // si
  int v3; // eax
  int16_t v4; // [esp+0h] [ebp-8h]

  v2 = a1 + 1;
  v3 = (int16_t)(a1 - 1);
  v4 = v3;
  sub_128C32(v3, (int16_t)(a2 - 1), v2, (int16_t)(a2 + 1), 25);
  sub_11C358(v4, a2 - 1, 16);
  sub_11C358(v4, a2 + 1, 16);
  sub_11C358(v2, a2 - 1, 16);
  sub_11C358(v2, a2 + 1, 16);
  JUMPOUT(0xABFED);
}
// AB8BA: control flows out of bounds to ABFED


//----- (000AB8BF) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=89)) - nutno dohledat rucne v IDA @ 0xAB9C1 */
int __fastcall sub_AB8BF(_DWORD, _DWORD, _DWORD, _DWORD)
{
  DECOMP_TODO("call analysis failed (funcsize=89)");
}


//----- (000ABA09) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=160)) - nutno dohledat rucne v IDA @ 0xABBFD */
_DWORD __stdcall sub_ABA09( int, int)
{
  DECOMP_TODO("call analysis failed (funcsize=160)");
}


//----- (000ABC5D) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=226)) - nutno dohledat rucne v IDA @ 0xABE1B */
_DWORD sub_ABC5D(void)
{
  DECOMP_TODO("call analysis failed (funcsize=226)");
}


//----- (000ABFF3) --------------------------------------------------------
void __fastcall sub_ABFF3( int a1, int a2)
{
  int16_t v4; // si
  unsigned int v5; // edx
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // eax
  int16_t v9; // cx
  int v10; // esi
  int *v11; // edx
  int v12; // eax
  int v13; // eax
  char v14; // [esp+0h] [ebp-24h]
  int16_t v15; // [esp+4h] [ebp-20h]
  int v16; // [esp+Ch] [ebp-18h] BYREF
  int v17; // [esp+10h] [ebp-14h] BYREF
  int v18; // [esp+14h] [ebp-10h]
  int v19; // [esp+18h] [ebp-Ch]
  int v20; // [esp+1Ch] [ebp-8h]
  char v21; // [esp+20h] [ebp-4h]

  v19 = a2;
  v21 = 0;
  v18 = 1000;
  sub_46CC8(a1, 6);
  v4 = 0;
  sub_4752F(a1, 6, 0);
  while ( 1 )
  {
    ++v4;
    do
    {
      v5 = sub_1247A0(0xDu) - 7;
      v6 = sub_1247A0(0xDu) - 7;
    }
    while ( !(_WORD)v5 && !(_WORD)v6 );
    HIWORD(v7) = HIWORD(dword_192864);
    v8 = dword_192864 + 313 * (int16_t)v19;
    LOWORD(v7) = *(uint8_t *)(v8 + 33);
    v15 = v6 + *(uint8_t *)(v8 + 34);
    v20 = v5 + v7;
    if ( word_18C9A8[68 * (int16_t)(v5 + v7) + v15] == 2000 )
      v21 = 1;
    if ( v21 || v4 >= 1000 )
    {
      if ( v4 <= (int16_t)v18 )
      {
        v9 = v19;
        v10 = 313 * (int16_t)v19;
        v11 = &v17;
        sub_49ED1(v19, &v17, &v16);
        HIWORD(v12) = HIWORD(dword_192864);
        LOWORD(v11) = *(uint8_t *)(v10 + dword_192864 + 33) - word_1998F0;
        v17 += 20 * (_DWORD)v11;
        LOWORD(v12) = *(uint8_t *)(v10 + dword_192864 + 34) - word_1998F2;
        v16 += 20 * v12;
        sub_AD7F5(a1, (int16_t)v17, (int16_t)v16);
        v14 = v20;
        sub_3E598(v9, (int16_t)v20, v15);
        v13 = dword_192864;
        *(_BYTE *)(v10 + dword_192864 + 33) = v14;
        word_1998FC = -1;
        *(_BYTE *)(v10 + v13 + 34) = v15;
      }
      JUMPOUT(0xABFED);
    }
  }
}
// AC131: control flows out of bounds to ABFED
// AD7F5: using guessed type int __fastcall sub_AD7F5(_DWORD, _DWORD, _DWORD);
// 18C9A8: using guessed type int16_t word_18C9A8[4979];
// 192864: using guessed type int dword_192864;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (000AC136) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=212)) - nutno dohledat rucne v IDA @ 0xAC203 */
int __fastcall sub_AC136(_DWORD, _DWORD, _DWORD)
{
  DECOMP_TODO("call analysis failed (funcsize=212)");
}


//----- (000AC472) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=124)) - nutno dohledat rucne v IDA @ 0xAC5B8 */
int __fastcall sub_AC472(_DWORD, _DWORD, _DWORD, _DWORD)
{
  DECOMP_TODO("call analysis failed (funcsize=124)");
}


//----- (000AC619) --------------------------------------------------------
_DWORD *__fastcall sub_AC619( int a1, int a2, int a3, int a4)
{
  int v5; // esi
  int *v6; // edx
  int v7; // ebx
  int v8; // eax
  int16_t *v9; // edi
  int16_t *v10; // esi
  int v11; // eax
  uint8_t v12; // dl
  int v13; // ebx
  int v14; // edx
  int v15; // eax
  int v16; // eax
  int16_t *v17; // edx
  int v18; // eax
  int16_t v19; // bx
  int v20; // ecx
  int16_t v21; // dx
  int v22; // ebx
  int16_t v26; // [esp+8h] [ebp-18h] BYREF
  int v27; // [esp+Ch] [ebp-14h] BYREF
  int16_t v28; // [esp+10h] [ebp-10h] BYREF
  int16_t v29; // [esp+14h] [ebp-Ch] BYREF
  int v30; // [esp+18h] [ebp-8h] BYREF
  int16_t v31; // [esp+1Ch] [ebp-4h] BYREF

  v5 = a1;
  v6 = &v27;
  sub_49ED1(a1, &v27, &v30);
  v7 = 313 * v5;
  HIWORD(v8) = HIWORD(dword_192864);
  LOWORD(v6) = *(uint8_t *)(313 * v5 + dword_192864 + 33) - word_1998F0;
  v27 += a3 + 20 * (_DWORD)v6;
  LOWORD(v8) = *(uint8_t *)(313 * v5 + dword_192864 + 34) - word_1998F2;
  v30 += a4 + 20 * v8;
  sub_1112EC(dword_192ED4, 22500);
  v9 = (int16_t *)sub_110D3C(dword_192ED4, 22500);
  v10 = (int16_t *)sub_110D3C(dword_192ED4, 22500);
  LOWORD(v11) = *(uint8_t *)(v7 + dword_192864 + 35);
  if ( (uint16_t)v11 > 4u && *(uint8_t *)(v7 + dword_192864 + 35) < 9u )
  {
    v11 = *(uint8_t *)(v7 + dword_192864 + 35) - 8;
LABEL_10:
    LOWORD(v11) = abs32(v11);
    goto LABEL_11;
  }
  if ( *(uint8_t *)(v7 + dword_192864 + 35) > 8u && *(uint8_t *)(v7 + dword_192864 + 35) < 0xDu )
  {
    v11 = (*(uint8_t *)(v7 + dword_192864 + 35) + 8) % 16;
    goto LABEL_11;
  }
  if ( *(uint8_t *)(v7 + dword_192864 + 35) > 0xCu && *(uint8_t *)(v7 + dword_192864 + 35) < 0x10u )
  {
    v11 = *(uint8_t *)(v7 + dword_192864 + 35) - 16;
    goto LABEL_10;
  }
LABEL_11:
  v12 = *(_BYTE *)(dword_192864 + 313 * a1 + 37);
  if ( v12 )
  {
    if ( v12 <= 2u )
    {
      v13 = dword_193174;
      v14 = (int16_t)v11 + 58;
    }
    else if ( v12 <= 3u )
    {
      v13 = dword_193174;
      v14 = (int16_t)v11 + 63;
    }
    else
    {
      if ( v12 > 5u )
        goto LABEL_21;
      v13 = dword_193174;
      v14 = (int16_t)v11 + 9;
    }
  }
  else
  {
    v13 = dword_193174;
    v14 = (int16_t)v11 + 53;
  }
  v15 = sub_CDF5C(224);
  v16 = sub_127C27(v15, v14, v13);
  sub_12F578((int)v10, v16);
LABEL_21:
  if ( *(uint8_t *)(dword_192864 + 313 * a1 + 35) > 4u
    && *(uint8_t *)(dword_192864 + 313 * a1 + 35) < 9u )
  {
    v17 = v10;
    v18 = (int)v9;
    v19 = 0;
LABEL_24:
    sub_12DFB2(v18, v17, v19);
    goto LABEL_31;
  }
  if ( (*(uint8_t *)(dword_192864 + 313 * a1 + 35) <= 8u
     || *(uint8_t *)(dword_192864 + 313 * a1 + 35) >= 0xDu)
    && *(uint8_t *)(dword_192864 + 313 * a1 + 35) > 0xCu
    && *(uint8_t *)(dword_192864 + 313 * a1 + 35) < 0x10u )
  {
    v19 = 3;
    v17 = v10;
    v18 = (int)v9;
    goto LABEL_24;
  }
  sub_12F578((int)v9, (int)v10);
LABEL_31:
  if ( a2 == 100 )
  {
    sub_12DAFC((int)v9);
    sub_131528(v9, &v29, &v31, &v26, &v28);
    v20 = (int16_t)(v30 - v28 / 2);
    v21 = v27 - v26 / 2;
    v22 = (int)v9;
  }
  else
  {
    sub_12E374(v10, v9, a2, a2);
    sub_12DAFC((int)v10);
    sub_131528(v10, &v29, &v31, &v26, &v28);
    v20 = (int16_t)(v30 - v28 / 2);
    v21 = v27 - v26 / 2;
    v22 = (int)v10;
  }
  sub_12A478(v21, v20, v22);
  return sub_1113CC(dword_192ED4, v20);
}
// 192864: using guessed type int dword_192864;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;


//----- (000AC87A) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=169)) - nutno dohledat rucne v IDA @ 0xACA74 */
int __fastcall sub_AC87A(_DWORD, _DWORD)
{
  DECOMP_TODO("call analysis failed (funcsize=169)");
}


//----- (000ACB4A) --------------------------------------------------------
void __fastcall sub_ACB4A( int a1, unsigned int a2)
{
  int v4; // edx
  int16_t v5; // ax
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int16_t v10; // [esp+8h] [ebp-24h] BYREF
  int16_t v11; // [esp+Ch] [ebp-20h] BYREF
  int v12; // [esp+10h] [ebp-1Ch] BYREF
  int v13; // [esp+14h] [ebp-18h]
  int v14; // [esp+18h] [ebp-14h]
  int v15; // [esp+1Ch] [ebp-10h]
  int v16; // [esp+20h] [ebp-Ch]
  int v17; // [esp+24h] [ebp-8h]
  int v18; // [esp+28h] [ebp-4h] BYREF

  v4 = a1;
  sub_33B19(a1);
  if ( !v5 )
    JUMPOUT(0xABFED);
  sub_34454(*(uint8_t *)(dword_192864 + 313 * v4 + 37), &v11, &v10);
  if ( a2 < 2u )
  {
    if ( a2 != 1 )
      goto LABEL_12;
  }
  else if ( a2 > 2u )
  {
    if ( a2 >= 4u )
    {
      if ( a2 <= 4u )
      {
        v17 = 60;
      }
      else if ( a2 == 5 )
      {
        v17 = 36;
      }
    }
LABEL_12:
    HIWORD(v6) = HIWORD(dword_192864);
    v7 = dword_192864 + 313 * a1;
    LOWORD(v6) = *(uint8_t *)(v7 + 33) - word_1998F0;
    LOWORD(v7) = *(uint8_t *)(v7 + 34) - word_1998F2;
    word_1998FC = a1;
    v14 = 20 * v6;
    v13 = 20 * v7;
    if ( word_19987E == 1 || word_1998CE )
      v15 = 2;
    else
      v15 = 1;
    v16 = 0;
    sub_147D7(10);
    while ( (int16_t)v16 < (int16_t)v17 )
    {
      sub_12C2A0();
      v8 = sub_124D41();
      sub_2F4EE(v8);
      sub_32B26(a1, 0, (int16_t)a2, v16);
      sub_34454(a1, &v18, &v12);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      sub_12A478(v18 + v14, v12 + v13, dword_19283C);
      sub_12B65C();
      LOWORD(v9) = sub_128BE7();
      sub_1077D(v9);
      sub_12C2C6(1);
      v16 += v15;
    }
    word_1998FC = -1;
    JUMPOUT(0xABFE8);
  }
  v17 = 24;
  goto LABEL_12;
}
// ACCD6: control flows out of bounds to ABFE8
// ACB63: control flows out of bounds to ABFED
// ACB63: variable 'v5' is possibly undefined
// ACCA3: variable 'v9' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 19283C: using guessed type int dword_19283C;
// 192864: using guessed type int dword_192864;
// 19987E: using guessed type int16_t word_19987E;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (000ACCDB) --------------------------------------------------------
_DWORD *__fastcall sub_ACCDB( int a1)
{
  int v1; // ecx
  int16_t v2; // si
  int *v3; // edx
  int v4; // eax
  int v5; // esi
  int *v6; // edx
  int v7; // eax
  int v8; // eax
  _DWORD *v9; // esi
  int v10; // edx
  int v12; // [esp+0h] [ebp-10h] BYREF
  int v13; // [esp+4h] [ebp-Ch] BYREF
  int v14; // [esp+8h] [ebp-8h] BYREF
  int v15; // [esp+Ch] [ebp-4h] BYREF

  v1 = 313 * a1;
  v2 = *(uint8_t *)(v1 + dword_192864 + 66);
  v3 = &v15;
  sub_49ED1(a1, &v15, &v12);
  HIWORD(v4) = HIWORD(dword_192864);
  LOWORD(v3) = *(uint8_t *)(v1 + dword_192864 + 33) - word_1998F0;
  v15 += 20 * (_DWORD)v3;
  LOWORD(v4) = *(uint8_t *)(v1 + dword_192864 + 34) - word_1998F2;
  v12 += 20 * v4;
  LOWORD(v4) = v2;
  v5 = 313 * v2;
  v6 = &v13;
  sub_49ED1(v4, &v13, &v14);
  HIWORD(v7) = HIWORD(dword_192864);
  LOWORD(v6) = *(uint8_t *)(v5 + dword_192864 + 33) - word_1998F0;
  v13 += 20 * (_DWORD)v6;
  LOWORD(v7) = *(uint8_t *)(v5 + dword_192864 + 34) - word_1998F2;
  v14 += 20 * v7;
  sub_12B753(dword_192948, 6);
  sub_1320E9((_BYTE *)dword_192944);
  sub_1112EC(dword_192ED4, 6);
  v8 = sub_111499(dword_192ED4);
  v9 = sub_110D3C(dword_192ED4, v8 - 100);
  sub_12F578((int)v9, dword_192948);
  sub_12DAFC((int)v9);
  sub_128AB6(0, 0, 639, 350);
  sub_12B634();
  v10 = (int16_t)v12;
  sub_130098((int16_t)v15, (int16_t)v12, (int16_t)v13, (int16_t)v14, (int)v9);
  sub_12B65C();
  sub_1320E9((_BYTE *)dword_192950);
  return sub_1113CC(dword_192ED4, v10);
}
// 192864: using guessed type int dword_192864;
// 192944: using guessed type int dword_192944;
// 192948: using guessed type int dword_192948;
// 192950: using guessed type int dword_192950;
// 192ED4: using guessed type int dword_192ED4;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;


//----- (000ACE08) --------------------------------------------------------
_BYTE *__fastcall sub_ACE08( int a1, int a2, int a3)
{
  int v5; // edx
  int *v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int *v11; // edx
  int v12; // eax
  int v13; // esi
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  _DWORD *v18; // ebx
  int v19; // edx
  int v21; // [esp+0h] [ebp-18h]
  int v22; // [esp+4h] [ebp-14h] BYREF
  int v23; // [esp+8h] [ebp-10h] BYREF
  int v24; // [esp+Ch] [ebp-Ch] BYREF
  int v25; // [esp+10h] [ebp-8h] BYREF
  int v26; // [esp+14h] [ebp-4h]

  v5 = 313 * a1;
  v21 = v5;
  LOWORD(v5) = *(uint8_t *)(v5 + dword_192864 + 66);
  v26 = v5;
  v6 = &v25;
  v7 = sub_49ED1(a1, &v25, &v24);
  if ( a1 == word_1998F8 )
  {
    LOWORD(v7) = 20 * word_1998F0;
    v8 = a2 - v7;
    LOWORD(v7) = 20 * word_1998F2;
    v25 += v8;
    v24 += a3 - v7;
  }
  else
  {
    v9 = v21 + dword_192864;
    LOWORD(v6) = *(uint8_t *)(v21 + dword_192864 + 33) - word_1998F0;
    v25 += 20 * (_DWORD)v6;
    LOWORD(v9) = *(uint8_t *)(v21 + dword_192864 + 34) - word_1998F2;
    v24 += 20 * v9;
  }
  v10 = (int16_t)v26;
  v11 = &v23;
  sub_49ED1(v26, &v23, &v22);
  HIWORD(v12) = HIWORD(v26);
  if ( (_WORD)v26 == word_1998F8 )
  {
    LOWORD(v12) = 20 * word_1998F0;
    v13 = a2 - v12;
    LOWORD(v12) = 20 * word_1998F2;
    v23 += v13;
    v22 += a3 - v12;
  }
  else
  {
    v14 = 313 * v10;
    HIWORD(v15) = HIWORD(dword_192864);
    LOWORD(v11) = *(uint8_t *)(v14 + dword_192864 + 33) - word_1998F0;
    v23 += 20 * (_DWORD)v11;
    LOWORD(v15) = *(uint8_t *)(v14 + dword_192864 + 34) - word_1998F2;
    v22 += 20 * v15;
  }
  v16 = word_19987A % 3 + 4;
  sub_12B753(dword_192948, v16);
  sub_1320E9((_BYTE *)dword_192944);
  sub_1112EC(dword_192ED4, v16);
  v17 = sub_111499(dword_192ED4);
  v18 = sub_110D3C(dword_192ED4, v17 - 100);
  sub_12F578((int)v18, dword_192948);
  sub_12DAFC((int)v18);
  v19 = (int16_t)v24;
  sub_130098((int16_t)v25, (int16_t)v24, (int16_t)v23, (int16_t)v22, (int)v18);
  sub_1113CC(dword_192ED4, v19);
  return sub_1320E9((_BYTE *)dword_192950);
}
// 192864: using guessed type int dword_192864;
// 192944: using guessed type int dword_192944;
// 192948: using guessed type int dword_192948;
// 192950: using guessed type int dword_192950;
// 192ED4: using guessed type int dword_192ED4;
// 19987A: using guessed type int16_t word_19987A;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F8: using guessed type int16_t word_1998F8;


//----- (000ACF83) --------------------------------------------------------
int __fastcall sub_ACF83( int a1, int a2, int a3)
{
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int16_t *v7; // esi
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // eax
  uint8_t v19; // al
  int v20; // edx
  int v21; // eax
  int v22; // esi
  int v23; // ebx
  int v24; // ecx
  int v25; // eax
  int16_t v26; // bx
  int16_t v27; // si
  int result; // eax
  int16_t v29; // [esp+0h] [ebp-4Ch]
  int v30; // [esp+4h] [ebp-48h]
  int v31; // [esp+8h] [ebp-44h]
  int v32; // [esp+10h] [ebp-3Ch]
  int16_t v33; // [esp+14h] [ebp-38h]
  int v34; // [esp+18h] [ebp-34h] BYREF
  int v35; // [esp+1Ch] [ebp-30h]
  int v36; // [esp+20h] [ebp-2Ch]
  int v37; // [esp+24h] [ebp-28h]
  int v38; // [esp+28h] [ebp-24h]
  int v39; // [esp+2Ch] [ebp-20h] BYREF
  int v40; // [esp+30h] [ebp-1Ch] BYREF
  int v41; // [esp+34h] [ebp-18h]
  int v42; // [esp+38h] [ebp-14h]
  int v43; // [esp+3Ch] [ebp-10h] BYREF
  int v44; // [esp+40h] [ebp-Ch]
  int v45; // [esp+44h] [ebp-8h]
  int v46; // [esp+48h] [ebp-4h]

  v5 = 313 * a1 + dword_192864;
  v4 = v5 + 11 * a3;
  LOWORD(v32) = 0;
  v46 = 0;
  LOWORD(v5) = *(uint8_t *)(v4 + 91);
  LOWORD(v4) = *(_WORD *)(v4 + 82);
  v35 = v5;
  v33 = v4;
  if ( word_1998F6 == 1 && !word_1998E0 )
  {
    if ( !(uint16_t)sub_339A7(a2, v5, a2) )
      sub_49D09(*(uint8_t *)(dword_192864 + 313 * a2 + 33), *(uint8_t *)(dword_192864 + 313 * a2 + 34));
    v6 = sub_127C27((int)aCmbtsfxLbx_0, 14, dword_193174);
    v7 = (int16_t *)v6;
    LOWORD(v6) = *(_WORD *)(v6 + 6);
    v37 = v6;
    sub_49ED1(v29, &v40, &v43);
    HIWORD(v8) = HIWORD(dword_192864);
    v9 = dword_192864 + 313 * v29;
    v40 -= 20;
    v43 -= 20;
    LOWORD(v8) = *(uint8_t *)(v9 + 33) - word_1998F0;
    v40 += 20 * v8;
    LOWORD(v9) = *(uint8_t *)(v9 + 34) - word_1998F2;
    v43 += 20 * v9;
    v44 = v40;
    v36 = v43;
    sub_49ED1(a2, &v39, &v34);
    HIWORD(v8) = HIWORD(dword_192864);
    v10 = dword_192864 + 313 * a2;
    v39 -= 20;
    v34 -= 20;
    LOWORD(v8) = *(uint8_t *)(v10 + 33) - word_1998F0;
    v39 += 20 * v8;
    LOWORD(v10) = *(uint8_t *)(v10 + 34) - word_1998F2;
    v34 += 20 * v10;
    if ( word_199900 )
      v41 = 24;
    else
      v41 = 6;
    v31 = sub_147D7(27);
    while ( (_WORD)v40 != (_WORD)v39 || (_WORD)v43 != (_WORD)v34 )
    {
      v11 = sub_124D41();
      sub_2F4EE(v11);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      v12 = (int16_t)v46;
      v7 = (int16_t *)sub_127C27((int)aCmbtsfxLbx_0, 14, dword_193174);
      sub_12B753((int)v7, v12);
      sub_12A478(v40, v43, (int)v7);
      sub_12B65C();
      v13 = (v12 + 1) % (int16_t)v37;
      LOWORD(v14) = sub_128BE7();
      sub_1077D(v14);
      v46 = v13;
      sub_1344B0((int16_t *)&v40, (int16_t *)&v43, v44, v36, v39, v34, v41);
    }
    sub_112C96(v31, 10);
    v15 = 313 * a2;
    LOBYTE(v15) = *(_BYTE *)(dword_192864 + v15 + 37);
    if ( (_BYTE)v15 )
    {
      if ( (uint8_t)v15 <= 2u )
      {
        v16 = 37;
      }
      else if ( (uint8_t)v15 <= 3u )
      {
        v16 = 38;
      }
      else
      {
        if ( (uint8_t)v15 > 5u )
          goto LABEL_22;
        v16 = 39;
      }
    }
    else
    {
      v16 = 36;
    }
    v15 = sub_127C27((int)aCmbtsfxLbx_0, v16, dword_193174);
    v7 = (int16_t *)v15;
LABEL_22:
    LOWORD(v15) = v7[3];
    v45 = v15;
    v40 = (int16_t)v40 + 20 - *v7 / 2;
    v17 = v7[1] / 2;
    v43 = (int16_t)v43 + 20 - v17;
    LOWORD(v17) = word_199900 != 0;
    v38 = v17 + 1;
    v42 = 0;
    v30 = sub_147D7(68);
    while ( 1 )
    {
      if ( (int16_t)v42 >= (int16_t)v45 )
      {
        sub_112C96(v30, 10);
        goto LABEL_36;
      }
      v18 = sub_124D41();
      sub_2F4EE(v18);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      sub_1320E9((_BYTE *)dword_192954);
      v19 = *(_BYTE *)(313 * a2 + dword_192864 + 37);
      if ( !v19 )
        break;
      if ( v19 <= 2u )
      {
        v20 = 37;
        goto LABEL_32;
      }
      if ( v19 <= 3u )
      {
        v20 = 38;
        goto LABEL_32;
      }
      if ( v19 <= 5u )
      {
        v20 = 39;
        goto LABEL_32;
      }
LABEL_33:
      sub_12B753((int)v7, (int16_t)v42);
      sub_12A478(v40, v43, (int)v7);
      sub_1320E9((_BYTE *)dword_192950);
      sub_12B65C();
      LOWORD(v21) = sub_128BE7();
      sub_1077D(v21);
      v42 += v38;
    }
    v20 = 36;
LABEL_32:
    v7 = (int16_t *)sub_127C27((int)aCmbtsfxLbx_0, v20, dword_193174);
    goto LABEL_33;
  }
LABEL_36:
  v22 = 14 * v33;
  v23 = word_199224[*(uint8_t *)(dword_192864 + 313 * v29 + 32)];
  v24 = v23 * word_17F817[v22] / 100;
  v25 = v23 * word_17F819[v22] / 100;
  v26 = 0;
  v27 = v25 - v24;
  while ( v26 < (int16_t)v35 )
  {
    ++v26;
    v32 = v27 * (int16_t)sub_1247A0(0x64u) / 100 + (int16_t)v24 + (int16_t)v32;
  }
  result = dword_192864 + 313 * a2;
  *(_WORD *)(result + 67) += v32;
  return result;
}
// AD031: variable 'v29' is possibly undefined
// AD16A: variable 'v14' is possibly undefined
// AD305: variable 'v21' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 17F817: using guessed type int16_t word_17F817[];
// 17F819: using guessed type int16_t word_17F819[];
// 192864: using guessed type int dword_192864;
// 192950: using guessed type int dword_192950;
// 192954: using guessed type int dword_192954;
// 193174: using guessed type int dword_193174;
// 199224: using guessed type int16_t word_199224[15];
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F6: using guessed type int16_t word_1998F6;
// 199900: using guessed type int16_t word_199900;


//----- (000AD3CA) --------------------------------------------------------
void __fastcall sub_AD3CA( int a1, int a2)
{
  _DWORD *v2; // esi
  int v3; // ecx
  int *v4; // edx
  int v5; // eax
  int v6; // ecx
  int *v7; // edx
  int v8; // eax
  int16_t v9; // di
  int v10; // edx
  _BYTE *v11; // eax
  int v12; // eax
  int v13; // eax
  int v16; // [esp+8h] [ebp-10h] BYREF
  int v17; // [esp+Ch] [ebp-Ch] BYREF
  int v18; // [esp+10h] [ebp-8h] BYREF
  int v19; // [esp+14h] [ebp-4h] BYREF

  if ( word_1998F6 == 1 && !word_1998E0 )
  {
    sub_1112EC(dword_192ED4, 50000);
    v2 = sub_110D3C(dword_192ED4, 50000);
    v3 = 313 * a1;
    v4 = &v19;
    sub_49ED1(a1, &v19, &v17);
    HIWORD(v5) = HIWORD(dword_192864);
    LOWORD(v4) = *(uint8_t *)(v3 + dword_192864 + 33) - word_1998F0;
    v19 += 20 * (_DWORD)v4;
    LOWORD(v5) = *(uint8_t *)(v3 + dword_192864 + 34) - word_1998F2;
    v17 += 20 * v5;
    v6 = 313 * a2;
    v7 = &v18;
    sub_49ED1(a2, &v18, &v16);
    HIWORD(v8) = HIWORD(dword_192864);
    LOWORD(v7) = *(uint8_t *)(v6 + dword_192864 + 33) - word_1998F0;
    v18 += 20 * (_DWORD)v7;
    LOWORD(v8) = *(uint8_t *)(v6 + dword_192864 + 34) - word_1998F2;
    v9 = 0;
    v16 += 20 * v8;
    do
    {
      sub_12C2A0();
      sub_124D41();
      sub_12B753(dword_192948, v9);
      sub_12F578((int)v2, dword_192948);
      sub_12DAFC((int)v2);
      sub_1320E9((_BYTE *)dword_192944);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      v10 = (int16_t)v17;
      sub_130098((int16_t)v19, (int16_t)v17, (int16_t)v18, (int16_t)v16, (int)v2);
      sub_128BE7();
      sub_12B65C();
      v11 = sub_1320E9((_BYTE *)dword_192950);
      v12 = sub_2F4EE(v11);
      sub_1077D(v12);
      ++v9;
      sub_12C2C6(1);
    }
    while ( v9 < 8 );
    sub_1113CC(dword_192ED4, v10);
  }
  *(_BYTE *)(313 * a1 + dword_192864 + 66) = a2;
  sub_4528F(a2);
  *(_WORD *)(dword_192864 + 313 * a2 + 59) = v13;
  sub_2C601(313 * a2, v13);
  JUMPOUT(0xABFED);
}
// AD56B: control flows out of bounds to ABFED
// AD561: variable 'v13' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 192864: using guessed type int dword_192864;
// 192944: using guessed type int dword_192944;
// 192948: using guessed type int dword_192948;
// 192950: using guessed type int dword_192950;
// 192ED4: using guessed type int dword_192ED4;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F6: using guessed type int16_t word_1998F6;


//----- (000AD580) --------------------------------------------------------
void __fastcall sub_AD580( int a1, int a2)
{
  int v3; // eax
  int16_t *v4; // ecx
  int v5; // esi
  int16_t v6; // bx
  int v7; // eax
  uint8_t v8; // dl
  int v9; // esi
  int v10; // ebx
  int v11; // edx
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int16_t *v18; // edx
  int v19; // eax
  int16_t v20; // bx
  int v21; // [esp+0h] [ebp-10h] BYREF
  int v22; // [esp+4h] [ebp-Ch] BYREF
  int v23; // [esp+8h] [ebp-8h]
  int v24; // [esp+Ch] [ebp-4h]

  v23 = a2;
  sub_1112EC(dword_192ED4, 80);
  v3 = sub_12DAA4(80, 80);
  v4 = (int16_t *)sub_110D3C(dword_192ED4, v3);
  sub_49ED1(a1, &v22, &v21);
  v22 += v23;
  v21 += v24;
  v5 = dword_192864 + 313 * a1;
  v6 = *(uint8_t *)(v5 + 35) % 4;
  if ( *(_BYTE *)(v5 + 35) == 4 || *(_BYTE *)(v5 + 35) == 12 )
    v6 = 4;
  v7 = dword_192864 + 313 * a1;
  v8 = *(_BYTE *)(v7 + 37);
  if ( v8 )
  {
    if ( v8 <= 2u )
    {
      if ( (((int)*(uint8_t *)(v7 + 35) >> 2) & 1) != 0 )
      {
        v12 = 4 - v6;
        v10 = dword_193174;
        v9 = v12 + 26;
        goto LABEL_22;
      }
      v11 = dword_193174;
      v9 = v6 + 26;
    }
    else
    {
      if ( v8 > 3u )
      {
        if ( v8 > 5u )
        {
LABEL_23:
          v17 = (int)*(uint8_t *)(313 * a1 + dword_192864 + 35) >> 2;
          if ( v17 )
          {
            switch ( v17 )
            {
              case 1:
                v18 = v4;
                v19 = (int)v4;
                v20 = 0;
                goto LABEL_26;
              case 3:
                v20 = 3;
                v18 = v4;
                v19 = (int)v4;
LABEL_26:
                sub_12DFB2(v19, v18, v20);
                break;
              default:
                break;
            }
          }
          sub_1320E9((_BYTE *)dword_192954);
          v22 = (int16_t)v22 - *v4 / 2;
          v21 = (int16_t)v21 - v4[1] / 2;
          sub_12DAFC((int)v4);
          sub_12A478(v22, v21, (int)v4);
          JUMPOUT(0xACF6A);
        }
        if ( (((int)*(uint8_t *)(v7 + 35) >> 2) & 1) != 0 )
        {
          v14 = 4 - v6;
          v10 = dword_193174;
          v9 = v14 + 16;
        }
        else
        {
          v9 = v6 + 21;
          v10 = dword_193174;
        }
LABEL_22:
        v15 = sub_CDF5C(224);
        v16 = sub_127C27(v15, v9, v10);
        sub_12B753(v16, word_19987A % *(int16_t *)(v16 + 6));
        sub_12F578((int)v4, v16);
        goto LABEL_23;
      }
      if ( (((int)*(uint8_t *)(v7 + 35) >> 2) & 1) != 0 )
      {
        v13 = 4 - v6;
        v10 = dword_193174;
        v9 = v13 + 21;
        goto LABEL_22;
      }
      v11 = dword_193174;
      v9 = v6 + 21;
    }
  }
  else
  {
    if ( (((int)*(uint8_t *)(v7 + 35) >> 2) & 1) != 0 )
    {
      v9 = 4 - v6 + 31;
      v10 = dword_193174;
      goto LABEL_22;
    }
    v11 = dword_193174;
    v9 = v6 + 31;
  }
  v10 = v11;
  goto LABEL_22;
}
// AD7E5: control flows out of bounds to ACF6A
// 192864: using guessed type int dword_192864;
// 192954: using guessed type int dword_192954;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 19987A: using guessed type int16_t word_19987A;


//----- (000AD7F5) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=97)) - nutno dohledat rucne v IDA @ 0xAD93E */
int __fastcall sub_AD7F5(_DWORD, _DWORD, _DWORD)
{
  DECOMP_TODO("call analysis failed (funcsize=97)");
}


//----- (000AD98A) --------------------------------------------------------
_BOOL1 __fastcall sub_AD98A( int a1, int a2, int a3)
{
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  int v7; // esi
  int *v8; // edx
  int v9; // eax
  int16_t v10; // si
  int v11; // eax
  int v12; // ecx
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // esi
  _BOOL2 v17; // ax
  _BOOL1 result; // al
  _BOOL2 v19; // [esp-8h] [ebp-4Ch]
  _DWORD *v20; // [esp+0h] [ebp-44h]
  int v21; // [esp+4h] [ebp-40h]
  int v22; // [esp+Ch] [ebp-38h] BYREF
  int v23; // [esp+10h] [ebp-34h] BYREF
  int v24; // [esp+14h] [ebp-30h] BYREF
  int v25; // [esp+18h] [ebp-2Ch] BYREF
  int v26; // [esp+1Ch] [ebp-28h] BYREF
  int v27; // [esp+20h] [ebp-24h] BYREF
  int v28; // [esp+24h] [ebp-20h]
  int v29; // [esp+28h] [ebp-1Ch]
  int v30; // [esp+2Ch] [ebp-18h]
  int v31; // [esp+30h] [ebp-14h]
  int v32; // [esp+34h] [ebp-10h]
  int v33; // [esp+38h] [ebp-Ch]
  int v34; // [esp+3Ch] [ebp-8h]
  int v35; // [esp+40h] [ebp-4h]

  v33 = a2;
  v28 = a3;
  if ( word_1998F6 == 1 && !word_1998E0 )
  {
    if ( !(uint16_t)sub_339A7(a2, a2, (int16_t)a2) )
      sub_49D09(
        *(uint8_t *)(dword_192864 + 313 * (int16_t)a2 + 33),
        *(uint8_t *)(dword_192864 + 313 * (int16_t)a2 + 34));
    sub_127C27((int)aCmbtsfxLbx_0, 41, dword_193174);
    v4 = sub_127C27((int)aCmbtsfxLbx_0, 40, dword_193174);
    sub_12B79D(v4);
    sub_131F7B();
    sub_1112EC(dword_192ED4, 50000);
    v20 = sub_110D3C(dword_192ED4, 50000);
    sub_49ED1(a1, &v24, &v27);
    HIWORD(v5) = HIWORD(dword_192864);
    v6 = dword_192864 + 313 * a1;
    LOWORD(v5) = *(uint8_t *)(v6 + 33) - word_1998F0;
    v24 += 20 * v5;
    LOWORD(v6) = *(uint8_t *)(v6 + 34) - word_1998F2;
    v27 += 20 * v6;
    v7 = 313 * (int16_t)v33;
    v8 = &v22;
    sub_49ED1(v33, &v22, &v26);
    HIWORD(v9) = HIWORD(dword_192864);
    LOWORD(v8) = *(uint8_t *)(v7 + dword_192864 + 33) - word_1998F0;
    v22 += 20 * (_DWORD)v8;
    LOWORD(v9) = *(uint8_t *)(v7 + dword_192864 + 34) - word_1998F2;
    v9 *= 20;
    v26 += v9;
    LOWORD(v9) = *(_WORD *)(v4 + 6);
    v29 = v9;
    if ( word_19987E == 1 || word_1998CE )
      v31 = 2;
    else
      v31 = 1;
    v10 = 0;
    v21 = sub_147D7(20);
    while ( v10 < (int16_t)v29 )
    {
      sub_12C2A0();
      v11 = sub_124D41();
      sub_2F4EE(v11);
      v12 = sub_127C27((int)aCmbtsfxLbx_0, 40, dword_193174);
      sub_12B753(v12, v10);
      sub_12F578((int)v20, v12);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      sub_130098((int16_t)v24, (int16_t)v27, (int16_t)v22, (int16_t)v26, (int)v20);
      if ( v10 > 8 )
      {
        v13 = sub_127C27((int)aCmbtsfxLbx_0, 41, dword_193174);
        sub_12B753(v13, v10 - 9);
        sub_1320E9((_BYTE *)dword_1928AC);
        sub_12A478(v22 - 60, v26 - 60, v13);
      }
      sub_128BE7();
      sub_12B65C();
      sub_1077D(v14);
      sub_12C2C6(2);
      v10 += v31;
    }
    sub_112C96(v21, 10);
    sub_1113CC(dword_192ED4, 10);
  }
  v15 = (int16_t)v28 * word_17FC41 * word_199224[*(uint8_t *)(dword_192864 + 313 * a1 + 32)] / 100;
  v32 = 0;
  v34 = 0;
  v35 = 0;
  v16 = (int16_t)v33;
  v30 = v15;
  do
  {
    v25 = v30;
    v23 = 0;
    v19 = sub_4B0D3(a1, 1);
    v17 = sub_4B0D3(a1, 32);
    sub_39985(v16, (int16_t *)&v25, (int16_t *)&v23, (int16_t)v35, 0, 0, v17, v19, 0);
    v32 += v25;
    result = v23;
    ++v35;
    v34 += v23;
  }
  while ( (int16_t)v35 < 4 );
  if ( word_1998F6 == 1 && !word_1998E0 )
  {
    sub_1320E9((_BYTE *)dword_192950);
    sub_A93AA(
      (int16_t)(20 * (*(uint8_t *)(dword_192864 + 313 * v16 + 33) - word_1998F0)),
      (int16_t)(20 * (*(uint8_t *)(dword_192864 + 313 * v16 + 34) - word_1998F2)),
      v16,
      1,
      v32,
      v34);
    return sub_A94A1();
  }
  return result;
}
// ADBB4: variable 'v14' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 17FC41: using guessed type int16_t word_17FC41;
// 192864: using guessed type int dword_192864;
// 1928AC: using guessed type int dword_1928AC;
// 192950: using guessed type int dword_192950;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 199224: using guessed type int16_t word_199224[15];
// 19987E: using guessed type int16_t word_19987E;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F6: using guessed type int16_t word_1998F6;


//----- (000ADCFF) --------------------------------------------------------
void sub_ADCFF()
{
  if ( !dword_182760 )
  {
    dword_182760 = sub_147D7(31);
    sub_112C29(dword_182760, -1);
  }
}
// 182760: using guessed type int dword_182760;


//----- (000ADD24) --------------------------------------------------------
int sub_ADD24()
{
  int result; // eax

  result = sub_112C96(dword_182760, 10);
  dword_182760 = 0;
  return result;
}
// 182760: using guessed type int dword_182760;


//----- (000ADD40) --------------------------------------------------------
void __fastcall sub_ADD40( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v6; // si
  _WORD v7[4]; // [esp+4h] [ebp-10h] BYREF
  int v8; // [esp+Ch] [ebp-8h]
  int16_t v9; // [esp+10h] [ebp-4h] BYREF

  v8 = a2;
  v6 = a4;
  if ( a4 >= 100 )
    v6 = 99;
  if ( v6 > 1 )
  {
    sub_12D8F5(98, 98, dword_192824);
    sub_12D8F5(98, 98, dword_19283C);
    *(_BYTE *)(313 * a1 + dword_192864 + 35) += a5;
    sub_32B26(a1, 0, 0, 0);
    *(_BYTE *)(313 * a1 + dword_192864 + 35) -= a5;
    sub_12E374((int16_t *)dword_192824, (int16_t *)dword_19283C, v6, v6);
    sub_49ED1(a1, v7, &v9);
    sub_C5CFF(v8 + v7[0], v7[2] + v9, (int16_t *)dword_192824);
  }
  else
  {
    *(_BYTE *)(313 * a1 + dword_192864 + 36) = 5;
  }
  JUMPOUT(0xAEBED);
}
// ADD74: control flows out of bounds to AEBED
// 192824: using guessed type int dword_192824;
// 19283C: using guessed type int dword_19283C;
// 192864: using guessed type int dword_192864;


//----- (000ADE18) --------------------------------------------------------
void __fastcall sub_ADE18(int a1, int a2, int a3, int a4, int a5)
{
  int16_t v5; // di
  int v6; // ebx
  int *v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // edx
  char *v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // edx
  int16_t v15; // si
  int v16; // edx
  int16_t v17; // bx
  int16_t v18; // dx
  int v19; // ebx
  int v20; // edx
  int v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // ebx
  int v25; // eax
  int16_t i; // si
  int16_t v27; // bx
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // edx
  int16_t v32; // ax
  int v33; // edx
  char *v34; // eax
  int v35; // ebx
  int16_t v36; // dx
  int v37; // eax
  int v38; // ecx
  int v39; // edx
  int16_t *v40; // eax
  int v41; // eax
  int v42; // edx
  int v43; // eax
  int v44; // ebx
  int v45; // eax
  int16_t v46; // si
  int16_t j; // bx
  int v48; // edx
  int v49; // eax
  int16_t v50; // si
  int16_t k; // bx
  int16_t m; // bx
  int v53; // esi
  int16_t v54; // bx
  int16_t v55; // ax
  int v56; // eax
  int16_t v57; // bx
  signed int v58; // edx
  int16_t n; // si
  int16_t v60; // bx
  int16_t ii; // cx
  int v62; // eax
  int v63; // edx
  int v64; // eax
  int v65; // edx
  int v66; // eax
  int16_t v67; // bx
  int16_t jj; // cx
  int16_t v69; // bx
  int16_t kk; // cx
  int v71; // eax
  unsigned int v72; // ebx
  unsigned int v73; // edx
  int v74; // ecx
  int v75; // eax
  int16_t v76; // ax
  int16_t v77; // ax
  int v78; // ebx
  int v79; // eax
  int16_t mm; // si
  int v81; // eax
  int16_t v82; // ax
  int v83; // ecx
  int v84; // eax
  _DWORD *v85; // eax
  int v86; // [esp+0h] [ebp-304h]
  int v87; // [esp+4h] [ebp-300h]
  int v88; // [esp+8h] [ebp-2FCh]
  int v89; // [esp+Ch] [ebp-2F8h]
  int v90[163]; // [esp+10h] [ebp-2F4h] BYREF
  _BYTE *v91; // [esp+29Ch] [ebp-68h]
  int v92; // [esp+2A0h] [ebp-64h]
  int v93; // [esp+2A4h] [ebp-60h]
  int16_t *v94; // [esp+2A8h] [ebp-5Ch]
  int v95; // [esp+2ACh] [ebp-58h]
  int v96; // [esp+2B0h] [ebp-54h]
  int v97; // [esp+2B4h] [ebp-50h]
  int v98; // [esp+2B8h] [ebp-4Ch]
  int v99; // [esp+2BCh] [ebp-48h] BYREF
  int v100; // [esp+2C0h] [ebp-44h]
  _DWORD v101[2]; // [esp+2C4h] [ebp-40h] BYREF
  unsigned int v102; // [esp+2CCh] [ebp-38h]
  int v103; // [esp+2D0h] [ebp-34h] BYREF
  int v104; // [esp+2D4h] [ebp-30h] BYREF
  int v105; // [esp+2D8h] [ebp-2Ch] BYREF
  int v106; // [esp+2DCh] [ebp-28h] BYREF
  int v107; // [esp+2E0h] [ebp-24h]
  int v108; // [esp+2E4h] [ebp-20h]
  int v109; // [esp+2E8h] [ebp-1Ch]
  int v110; // [esp+2ECh] [ebp-18h] BYREF
  int v111; // [esp+2F0h] [ebp-14h] BYREF
  int v112; // [esp+2F4h] [ebp-10h]
  int v113; // [esp+2F8h] [ebp-Ch]
  int v114; // [esp+2FCh] [ebp-8h]
  char v115; // [esp+300h] [ebp-4h]

  v89 = a1;
  v88 = a2;
  v87 = a3;
  v86 = a4;
  qmemcpy(v90, &word_AB756, 0xFAu);
  v115 = 1;
  v5 = 0;
  if ( word_1998F6 == 1 && !word_1998E0 )
  {
    v6 = (int16_t)a1;
    if ( !(uint16_t)sub_339A7(a1, a2, (int16_t)a1) )
      sub_49D09(*(uint8_t *)(dword_192864 + 313 * v6 + 33), *(uint8_t *)(dword_192864 + 313 * v6 + 34));
  }
  v7 = &v99;
  sub_49ED1(v89, &v99, &v103);
  LOWORD(v7) = 20 * word_1998F0;
  v99 = v99 + v88 - (_DWORD)v7;
  HIWORD(v8) = HIWORD(v99);
  LOWORD(v8) = 20 * word_1998F2;
  v103 = v103 + v87 - v8;
  sub_1112EC(dword_192ED4, v103);
  sub_BB7DB();
  if ( (uint16_t)a4 < 2u )
  {
    v91 = (_BYTE *)dword_192928;
    goto LABEL_11;
  }
  if ( (uint16_t)a4 <= 2u )
  {
LABEL_11:
    v9 = 20;
    v115 = 1;
LABEL_15:
    sub_147D7(v9);
    goto LABEL_16;
  }
  if ( (uint16_t)a4 <= 3u )
  {
    v91 = (_BYTE *)dword_1928C4;
    sub_147D7(47);
    sub_147D7(8);
    v115 = 0;
    if ( sub_1247A0(0xAu) != 1 )
      goto LABEL_16;
    v9 = 33;
    goto LABEL_15;
  }
  if ( (_WORD)a4 == 4 )
  {
    v91 = (_BYTE *)dword_1928C4;
    sub_147D7(25);
    v9 = 8;
    v115 = 0;
    goto LABEL_15;
  }
LABEL_16:
  if ( (uint16_t)a4 < 2u )
  {
    v10 = 52;
LABEL_22:
    v11 = aCmbtsfxLbx_0;
    v12 = dword_193174;
LABEL_26:
    v94 = (int16_t *)sub_127C27((int)v11, v10, v12);
    goto LABEL_27;
  }
  if ( (uint16_t)a4 <= 2u )
  {
    v10 = 6;
    goto LABEL_22;
  }
  if ( (uint16_t)a4 <= 3u )
  {
    v11 = aSphersfxLbx;
    v12 = dword_193174;
    v10 = 0;
    goto LABEL_26;
  }
  if ( (_WORD)a4 == 4 )
  {
    v10 = 1;
    v11 = aSphersfxLbx;
    v12 = dword_193174;
    goto LABEL_26;
  }
LABEL_27:
  v13 = *v94 / 2 * (*v94 / 2);
  HIWORD(v14) = HIWORD(v94);
  LOWORD(v14) = v94[3];
  v15 = 1;
  v98 = v14;
  v93 = v13;
  while ( v15 < word_1998C0 )
  {
    v16 = 313 * v15;
    if ( !*(_BYTE *)(v16 + dword_192864 + 36)
      && !sub_3E563(v15)
      && v15 != (_WORD)v89
      && *(_BYTE *)(v16 + dword_192864 + 36) != 5 )
    {
      sub_34543(v15, &v110, &v104);
      v17 = abs32((int16_t)v110 - (int16_t)v99);
      v18 = abs32((int16_t)v104 - (int16_t)v103);
      v19 = v18 * v18 + v17 * v17;
      if ( v19 <= v93 )
      {
        if ( (int)abs32((int16_t)v99 - (int16_t)v110) >= (int)abs32((int16_t)v103 - (int16_t)v104) )
        {
          v20 = (int16_t)v99;
          v21 = (int16_t)v110;
        }
        else
        {
          v20 = (int16_t)v103;
          v21 = (int16_t)v104;
        }
        v22 = (int)abs32(v20 - v21) / 20;
        v23 = v5++;
        *((_WORD *)&v90[138] + v23) = v22;
        *((_WORD *)&v90[113] + v23) = v15;
        v90[v23 + 63] = v19;
      }
    }
    ++v15;
  }
  v24 = (int)&v111;
  sub_49ED1(v89, &v105, &v111);
  if ( word_1998F6 == 1 && !word_1998E0 )
  {
    word_1998FC = v89;
    v25 = sub_124D7A();
    sub_2F4EE(v25);
    sub_124E36();
    if ( word_1998CE || word_19987E == 1 || word_1998CE )
      v109 = 2;
    else
      v109 = 1;
    for ( i = 0; ; i += v109 )
    {
      if ( i > (int16_t)v98 )
      {
        word_1998FC = -1;
        goto LABEL_103;
      }
      sub_128BE7();
      sub_12C2A0();
      sub_124D41();
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      if ( !v115 && *(_BYTE *)(dword_192864 + 313 * (int16_t)v89 + 36) != 5 )
      {
        if ( (uint16_t)v86 > 1u )
        {
          v27 = v103 - v111;
          v100 = v99 - v105;
          if ( (_WORD)v86 == 3 )
          {
            sub_ADD40(v89, (int16_t)v100, v27, 100 - 10 * i, i);
          }
          else if ( (_WORD)v86 == 4 )
          {
            sub_ADD40(v89, (int16_t)v100, v27, 100 - 8 * (i - 4), i);
          }
        }
        else
        {
          sub_30062(
            v89,
            350,
            v86,
            v87,
            v88,
            v89,
            v90[0],
            v90[1],
            v90[2],
            v90[3],
            v90[4],
            v90[5],
            v90[6],
            v90[7],
            v90[8],
            *(__int128 *)&v90[9],
            v90[13],
            v90[14],
            v90[15],
            v90[16],
            *(int64_t *)&v90[17],
            *(int64_t *)&v90[19],
            *(int64_t *)&v90[21]);
        }
      }
      v28 = *((int16_t *)v90 + 25 * (int16_t)v86 + i);
      v92 = v28 * v28;
      v29 = 0;
      v95 = v28 * v28 - 625;
      while ( (int16_t)v29 < v5 )
      {
        if ( (uint16_t)v86 <= 2u
          && (i < 5 && *((_WORD *)&v90[138] + (int16_t)v29) == 1
           || i > 0 && i < 7 && *((_WORD *)&v90[138] + (int16_t)v29) == 2
           || i > 4 && i < 13 && *((_WORD *)&v90[138] + (int16_t)v29) == 3
           || i > 8 && *((_WORD *)&v90[138] + (int16_t)v29) == 4)
          || (uint16_t)v86 >= 2u
          && (25 * *(uint8_t *)(dword_192864 + 313 * *((int16_t *)&v90[113] + (int16_t)v29) + 37) + v92 >= v90[(int16_t)v29 + 63]
           && *((int16_t *)v90 + 25 * (int16_t)v86 + i) <= 84
           || v90[(int16_t)v29 + 63] <= 25
                                      * *(uint8_t *)(dword_192864
                                                           + 313 * *((int16_t *)&v90[113] + (int16_t)v29)
                                                           + 37)
                                      + v92
           && (v96 = 50 * (int16_t)v86, *(int16_t *)((char *)v90 + 2 * i + v96) > 84)
           && v90[(int16_t)v29 + 63] <= v95) )
        {
          v30 = dword_192864 + 313 * *((int16_t *)&v90[113] + (int16_t)v29);
          LOWORD(v30) = *(uint8_t *)(v30 + 33) - word_1998F0;
          v101[1] = 20 * v30;
          v102 = 20 * v30 + sub_1247A0(5u) - 3;
          sub_1247A0(5u);
        }
        else
        {
          HIWORD(v31) = HIWORD(dword_192864);
          LOWORD(v31) = *(uint8_t *)(dword_192864 + 313 * *((int16_t *)&v90[113] + (int16_t)v29) + 33)
                      - word_1998F0;
          v102 = 20 * v31;
        }
        v32 = *((_WORD *)&v90[113] + (int16_t)v29++);
        sub_30062(
          v32,
          v29,
          v86,
          v87,
          v88,
          v89,
          v90[0],
          v90[1],
          v90[2],
          v90[3],
          v90[4],
          v90[5],
          v90[6],
          v90[7],
          v90[8],
          *(__int128 *)&v90[9],
          v90[13],
          v90[14],
          v90[15],
          v90[16],
          *(int64_t *)&v90[17],
          *(int64_t *)&v90[19],
          *(int64_t *)&v90[21]);
      }
      if ( (_WORD)v86 != 2 )
        sub_1320E9(v91);
      if ( (uint16_t)v86 < 2u )
        break;
      if ( (uint16_t)v86 <= 2u )
      {
        v33 = 6;
        goto LABEL_85;
      }
      if ( (uint16_t)v86 <= 3u )
      {
        v34 = aSphersfxLbx;
        v35 = dword_193174;
        v33 = 0;
        goto LABEL_89;
      }
      if ( (_WORD)v86 == 4 )
      {
        v33 = 1;
        v34 = aSphersfxLbx;
        v35 = dword_193174;
        goto LABEL_89;
      }
LABEL_90:
      v24 = (int)v94;
      sub_12B753((int)v94, i);
      sub_C5CFF(v99, v103, (int16_t *)v24);
      if ( (_WORD)v86 != 2 )
        sub_1320E9((_BYTE *)dword_192950);
      if ( v115 )
      {
        v24 = 313 * (int16_t)v89;
        if ( *(_BYTE *)(dword_192864 + v24 + 36) != 5 )
        {
          if ( (uint16_t)v86 > 2u )
          {
            v107 = v99 - v105;
            v36 = v103 - v111;
            if ( (_WORD)v86 == 3 )
            {
              v24 = v36;
              sub_ADD40(v89, (int16_t)v107, v36, 100 - 10 * i, i);
            }
            else if ( (_WORD)v86 == 4 )
            {
              v96 = v36;
              v24 = v36;
              sub_ADD40(v89, (int16_t)v107, v36, 100 - 10 * (i - 4), i);
            }
          }
          else
          {
            v24 = (int16_t)(v103 - v111);
            sub_30062(
              v89,
              v29,
              v86,
              v87,
              v88,
              v89,
              v90[0],
              v90[1],
              v90[2],
              v90[3],
              v90[4],
              v90[5],
              v90[6],
              v90[7],
              v90[8],
              *(__int128 *)&v90[9],
              v90[13],
              v90[14],
              v90[15],
              v90[16],
              *(int64_t *)&v90[17],
              *(int64_t *)&v90[19],
              *(int64_t *)&v90[21]);
          }
        }
      }
      sub_12B65C();
      LOWORD(v37) = sub_128BE7();
      sub_1077D(v37);
      sub_12C2C6(1);
    }
    v33 = 52;
LABEL_85:
    v34 = aCmbtsfxLbx_0;
    v35 = dword_193174;
LABEL_89:
    v94 = (int16_t *)sub_127C27((int)v34, v33, v35);
    goto LABEL_90;
  }
LABEL_103:
  v38 = 0;
  do
  {
    v39 = dword_192B14;
    v40 = (int16_t *)(dword_192B14 + 26 * (int16_t)v38);
    if ( *v40 <= 0 )
      goto LABEL_133;
    v41 = 28 * *v40;
    if ( byte_17F80F[v41] == 2 || byte_17F80F[v41] == 4 && sub_1247A0(2u) == 1 )
      goto LABEL_133;
    v42 = 26 * (int16_t)v38;
    v43 = v42 + dword_192B14;
    LOWORD(v42) = 20 * word_1998F0;
    LOWORD(v24) = *(_WORD *)(v43 + 9);
    v44 = v24 - v42;
    LOWORD(v42) = 20 * word_1998F2;
    v110 = v44;
    LOWORD(v43) = *(_WORD *)(v43 + 11);
    v104 = v43 - v42;
    v24 = abs32((int16_t)v44 - (int16_t)v99);
    LOWORD(v43) = abs32((int16_t)(v43 - 20 * word_1998F2) - (int16_t)v103);
    v39 = (int16_t)v24 * (int16_t)v24;
    v45 = v39 + (int16_t)v43 * (int16_t)v43;
    if ( v45 > v93 )
      goto LABEL_133;
    switch ( (_WORD)v86 )
    {
      case 0:
        v46 = 0;
        for ( j = 0; j < a5; ++j )
        {
          v96 = word_17FCE9;
          v46 += word_17FCE7 + sub_1247A0(word_17FCE9 - word_17FCE7 + 1) - 1;
        }
LABEL_113:
        v48 = 313 * (int16_t)v89;
        v49 = dword_192864;
LABEL_114:
        v50 = v46 * word_199224[*(uint8_t *)(v48 + v49 + 32)] / 100;
        LOWORD(v49) = 0;
        goto LABEL_126;
      case 1:
        v46 = 0;
        for ( k = 0; k < a5; ++k )
        {
          v96 = word_17FC09;
          v46 += word_17FC07 + sub_1247A0(word_17FC09 - word_17FC07 + 1) - 1;
        }
        v49 = 313 * (int16_t)v89;
        v48 = dword_192864;
        goto LABEL_114;
      case 2:
        v46 = 0;
        for ( m = 0; m < a5; ++m )
        {
          v96 = word_17F985;
          v46 += word_17F983 + sub_1247A0(word_17F985 - word_17F983 + 1) - 1;
        }
        goto LABEL_113;
    }
    v50 = a5;
    v49 = 100 * v45 / v93;
LABEL_126:
    v53 = (100 - (int16_t)v49) * v50 / 100;
    v96 = 26 * (int16_t)v38;
    v54 = *(_WORD *)(v96 + dword_192B14 + 17);
    v55 = sub_3BB3D(v38);
    v114 = 25 * (int16_t)v53 / (int16_t)sub_3E095(*(_WORD *)(v96 + dword_192B14), v55, v38, SHIBYTE(v54));
    v56 = v96 + dword_192B14;
    LOWORD(v56) = *(_WORD *)(v96 + dword_192B14 + 15);
    v57 = 0;
    v108 = v56;
    while ( v57 < (int16_t)v108 )
    {
      v58 = (int16_t)v114;
      if ( (int)sub_1247A0(0x64u) <= v58 )
        --*(_WORD *)(26 * (int16_t)v38 + dword_192B14 + 15);
      ++v57;
    }
    v24 = 26 * (int16_t)v38;
    v39 = dword_192B14;
    if ( !*(_WORD *)(dword_192B14 + v24 + 15) )
      sub_3BC80(v38);
LABEL_133:
    ++v38;
  }
  while ( (int16_t)v38 < 300 );
  for ( n = 0; n < v5; ++n )
  {
    switch ( (_WORD)v86 )
    {
      case 0:
        v60 = 0;
        for ( ii = 0; ii < a5; ++ii )
        {
          v96 = word_17FCE9;
          v60 += word_17FCE7 + sub_1247A0(word_17FCE9 - word_17FCE7 + 1) - 1;
        }
        v62 = 313 * (int16_t)v89;
        v63 = dword_192864;
LABEL_140:
        v64 = *(uint8_t *)(v63 + v62 + 32);
        v65 = v60;
        v66 = word_199224[v64];
LABEL_141:
        v67 = v65 * v66 / 100;
        LOWORD(v66) = 0;
        goto LABEL_153;
      case 1:
        v60 = 0;
        for ( jj = 0; jj < a5; ++jj )
        {
          v97 = word_17FC09;
          v60 += word_17FC07 + sub_1247A0(word_17FC09 - word_17FC07 + 1) - 1;
        }
        v63 = 313 * (int16_t)v89;
        v62 = dword_192864;
        goto LABEL_140;
      case 2:
        v69 = 0;
        for ( kk = 0; kk < a5; ++kk )
        {
          v96 = word_17F985;
          v69 += word_17F983 + sub_1247A0(word_17F985 - word_17F983 + 1) - 1;
        }
        v65 = word_199224[*(uint8_t *)(313 * (int16_t)v89 + dword_192864 + 32)];
        v66 = v69;
        goto LABEL_141;
    }
    v67 = a5;
    v66 = 100 * v90[n + 63] / v93;
LABEL_153:
    v71 = (100 - (int16_t)v66) * v67 / 100;
    if ( v71 <= 1 )
      v71 = 1;
    v101[0] = 0;
    v106 = 0;
    v113 = 0;
    v112 = v71;
    while ( 1 )
    {
      v74 = *((int16_t *)&v90[113] + n);
      v75 = dword_192864 + 313 * v74;
      v96 = *(uint8_t *)(v75 + 37);
      v97 = (int16_t)v113;
      if ( (int16_t)v113 >= ++v96 )
        break;
      v72 = (int16_t)v112;
      if ( (int)sub_1247A0((int16_t)v112) <= 1 )
        v73 = 1;
      else
        v73 = sub_1247A0(v72);
      ++v113;
      v101[0] = v73 + SLOWORD(v101[0]);
    }
    if ( (_WORD)v86 == 2 )
    {
      v39 = v112;
      *(_WORD *)(v75 + 192) += v112;
      v106 = 0;
      v101[0] = v39;
    }
    else
    {
      v76 = sub_32A20(v74, v89);
      v77 = sub_39DE0(v76);
      v39 = (int)v101;
      sub_39985(*((_WORD *)&v90[113] + n), (int16_t *)v101, (int16_t *)&v106, v77, 0, 0, 0, 0, 0);
    }
    if ( word_1998F6 == 1 && !word_1998E0 )
    {
      v78 = *((int16_t *)&v90[113] + n);
      v79 = 313 * v78 + dword_192864;
      v39 = (int16_t)(20 * (*(uint8_t *)(v79 + 34) - word_1998F2));
      sub_A93AA((int16_t)(20 * (*(uint8_t *)(v79 + 33) - word_1998F0)), (int16_t)v39, v78, 1, v101[0], v106);
    }
  }
  if ( word_1998F6 == 1 && !word_1998E0 )
    sub_A94A1();
  for ( mm = 0; mm < v5; ++mm )
  {
    v81 = *((int16_t *)&v90[113] + mm);
    v39 = dword_192864;
    if ( !*(_BYTE *)(dword_192864 + 313 * v81 + 36) )
    {
      v82 = sub_3897A(v81);
      if ( v82 )
      {
        v83 = v82;
        v97 = *((int16_t *)&v90[113] + mm);
        v84 = dword_192864 + 313 * v97;
        v39 = (int16_t)(20 * *(uint8_t *)(v84 + 33));
        sub_39E15(v97, v39, (int16_t)(20 * *(uint8_t *)(v84 + 34)), v83);
      }
    }
  }
  v85 = sub_1113CC(dword_192ED4, v39);
  if ( word_1998F6 == 1 && !word_1998E0 )
    sub_2C601((int)v85, v39);
}
// AE182: variable 'v89' is possibly undefined
// AE1A8: variable 'v86' is possibly undefined
// AE1CD: variable 'v87' is possibly undefined
// AE1CD: variable 'v88' is possibly undefined
// AE5F9: variable 'v37' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 39E15: using guessed type int __fastcall sub_39E15(_DWORD, _DWORD, _DWORD, _DWORD);
// AB756: using guessed type int16_t word_AB756;
// 17F983: using guessed type int16_t word_17F983;
// 17F985: using guessed type int16_t word_17F985;
// 17FC07: using guessed type int16_t word_17FC07;
// 17FC09: using guessed type int16_t word_17FC09;
// 17FCE7: using guessed type int16_t word_17FCE7;
// 17FCE9: using guessed type int16_t word_17FCE9;
// 192864: using guessed type int dword_192864;
// 1928C4: using guessed type int dword_1928C4;
// 192928: using guessed type int dword_192928;
// 192950: using guessed type int dword_192950;
// 192B14: using guessed type int dword_192B14;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 199224: using guessed type int16_t word_199224[15];
// 19987E: using guessed type int16_t word_19987E;
// 1998C0: using guessed type int16_t word_1998C0;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998E0: using guessed type int16_t word_1998E0;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F6: using guessed type int16_t word_1998F6;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (000AEC0B) --------------------------------------------------------
int __fastcall sub_AEC0B( int a1)
{
  int v1; // eax

  switch ( (uint16_t)sub_1247A0(3u) - 1 + a1 )
  {
    case 0:
      v1 = 29;
      break;
    case 1:
    case 2:
    case 3:
    case 4:
      v1 = 24;
      break;
    case 5:
      sub_147D7(30);
      v1 = 43;
      break;
    default:
      v1 = 24;
      break;
  }
  return sub_147D7(v1);
}


//----- (000AEC7B) --------------------------------------------------------
void __usercall sub_AEC7B( int a1, int a2, int a3, int a4, int a5)
{
  int64_t *v6; // edx
  int v7; // eax
  uint8_t v8; // al
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // edx
  int16_t v15; // ax
  int v16; // eax
  int v17; // edx
  uint8_t v18; // al
  int v19; // edx
  int v20; // eax
  int16_t v21; // ax
  int v22; // eax
  int v23; // eax
  int v24; // edx
  int v25; // edx
  int v26; // eax
  int v27; // eax
  char v28; // al
  int v29; // eax
  int v30; // eax
  int v31; // edx
  int v32; // ebx
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // edx
  int v37; // ebx
  int v38; // eax
  int v39; // edx
  int v40; // ebx
  int v41; // eax
  int v42; // edx
  int v43; // ebx
  int v44; // eax
  int v45; // edx
  int v46; // ebx
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int v53; // edx
  int16_t v54; // bx
  int v55[8]; // [esp+0h] [ebp-64h] BYREF
  int v56; // [esp+20h] [ebp-44h]
  int v57; // [esp+24h] [ebp-40h]
  int v58; // [esp+28h] [ebp-3Ch]
  int64_t *v59; // [esp+2Ch] [ebp-38h]
  int v60; // [esp+30h] [ebp-34h]
  __int128 v61; // [esp+34h] [ebp-30h]
  int v62; // [esp+44h] [ebp-20h]
  int v63; // [esp+48h] [ebp-1Ch]
  int v64; // [esp+4Ch] [ebp-18h]
  int v65; // [esp+50h] [ebp-14h]
  int64_t v66; // [esp+54h] [ebp-10h] BYREF
  int64_t v67; // [esp+5Ch] [ebp-8h] BYREF
  _DWORD savedregs[3]; // [esp+64h] [ebp+0h]

  v63 = a2;
  HIDWORD(v61) = a4;
  LODWORD(v66) = 0;
  LODWORD(v67) = 0;
  if ( !(uint16_t)sub_339A7(a1, a2, a4) )
  {
    sub_12C2A0();
    v58 = 20;
    sub_49D09((int16_t)v63 / 20, (int16_t)a4 / 20);
    sub_12C2C6(7);
  }
  v6 = &v66;
  v57 = a1;
  sub_49ED1(a1, &v66, &v67);
  v56 = 313 * a1;
  v7 = v56 + dword_192864;
  if ( *(_BYTE *)(v56 + dword_192864 + 312) > 9u )
  {
    LOWORD(v7) = *(uint8_t *)(v7 + 35);
    HIDWORD(v67) = v7;
    sub_34454(v57, &v66, &v67);
    LOWORD(v22) = 20 * word_1998F0;
    v23 = v63 - v22;
    v24 = v23 + v66;
    LOWORD(v23) = 20 * word_1998F2;
    DWORD2(v61) = v24;
    v25 = HIDWORD(v61) - v23 + v67;
    v26 = v56 + dword_192864;
    *(_WORD *)(v26 + 67) = 0;
    LODWORD(v61) = v25;
    *(_BYTE *)(v26 + 36) = 5;
    v27 = sub_124D7A();
    sub_2C6BA(v27);
    if ( word_19987E == 1 || word_1998CE )
      DWORD1(v61) = 2;
    else
      DWORD1(v61) = 1;
    LOWORD(v65) = 0;
    v28 = 96;
    do
    {
      v14 = (int16_t)v65;
      LOWORD(v65) = v65 + 1;
      *((_BYTE *)v55 + v14) = v28++;
    }
    while ( (int16_t)v65 < 32 );
    LOWORD(v65) = 0;
    while ( (int16_t)v65 < 16 )
    {
      sub_12C2A0();
      v29 = sub_124D41();
      sub_2F4EE(v29);
      sub_128AB6(0, 0, 639, 350);
      sub_12B634();
      v30 = dword_192864 + 313 * a1;
      switch ( *(_BYTE *)(v30 + 312) )
      {
        case 0xA:
          if ( *(_BYTE *)(v30 + 37) == 2 )
            v31 = 72;
          else
            v31 = 71;
          v32 = dword_193174;
          v33 = sub_CDF5C(224);
          a5 = sub_127C27(v33, v31, v32);
          if ( !(_WORD)v65 )
          {
            v34 = 63;
            goto LABEL_54;
          }
          break;
        case 0xB:
          if ( *(_BYTE *)(v30 + 37) == 2 )
            v36 = 74;
          else
            v36 = 73;
          v37 = dword_193174;
          v38 = sub_CDF5C(224);
          a5 = sub_127C27(v38, v36, v37);
          if ( !(_WORD)v65 )
          {
            v34 = 66;
            goto LABEL_54;
          }
          break;
        case 0xC:
          if ( *(_BYTE *)(v30 + 37) == 2 )
            v45 = 70;
          else
            v45 = 69;
          v46 = dword_193174;
          v47 = sub_CDF5C(224);
          a5 = sub_127C27(v47, v45, v46);
          if ( !(_WORD)v65 )
          {
            v34 = 65;
            goto LABEL_54;
          }
          break;
        case 0xD:
          if ( *(_BYTE *)(v30 + 37) == 2 )
            v39 = 76;
          else
            v39 = 75;
          v40 = dword_193174;
          v41 = sub_CDF5C(224);
          a5 = sub_127C27(v41, v39, v40);
          if ( !(_WORD)v65 )
          {
            v34 = 64;
            goto LABEL_54;
          }
          break;
        case 0xE:
          if ( *(_BYTE *)(v30 + 37) == 2 )
            v42 = 78;
          else
            v42 = 77;
          v43 = dword_193174;
          v44 = sub_CDF5C(224);
          a5 = sub_127C27(v44, v42, v43);
          if ( !(_WORD)v65 )
          {
            v34 = 62;
LABEL_54:
            sub_147D7(v34);
          }
          break;
        default:
          break;
      }
      v35 = (SWORD2(v67) - 1 - (__CFSHL__((SWORD2(v67) - 1) >> 31, 2) + 4 * ((SWORD2(v67) - 1) >> 31))) >> 2;
      if ( v35 <= 0 )
        v35 = 0;
      switch ( v35 )
      {
        case 0:
          sub_12B753(a5, 16 * SWORD2(v67) + (int16_t)v65);
          sub_12F578(dword_19283C, a5);
          break;
        case 1:
          sub_12B753(a5, 16 * (8 - SWORD2(v67)) + (int16_t)v65);
          v52 = dword_192840;
          v53 = a5;
          v54 = 0;
          goto LABEL_86;
        case 2:
          sub_12B753(a5, 16 * SWORD2(v67) - 128 + (int16_t)v65);
          sub_12F578(dword_19283C, a5);
          sub_12DFB2(dword_192840, (int16_t *)dword_19283C, 0);
          v54 = 3;
          goto LABEL_87;
        case 3:
          sub_12B753(a5, 16 * (16 - SWORD2(v67)) + (int16_t)v65);
          v52 = dword_192840;
          v53 = a5;
          v54 = 3;
LABEL_86:
          sub_12F578(v52, v53);
LABEL_87:
          sub_12DFB2(dword_19283C, (int16_t *)dword_192840, v54);
          break;
        default:
          break;
      }
      if ( *(uint8_t *)(dword_192864 + 313 * a1 + 32) == word_19988E )
        sub_137D86(dword_19283C, (int)v55, 32, 32);
      v14 = (int16_t)v61;
      sub_12A478(SWORD4(v61), v61, dword_19283C);
      sub_12B65C();
      LOWORD(v48) = sub_128BE7();
      sub_1077D(v48);
      sub_12C2C6(1);
      LOWORD(v65) = WORD2(v61) + v65;
    }
    v49 = sub_124D41();
    v50 = sub_2F4EE(v49);
    sub_1077D(v50);
LABEL_84:
    sub_46CC8(word_1998F8, v14);
    sub_2C601(v51, v14);
  }
  else
  {
    if ( a3 == 1 )
    {
      LOWORD(v6) = word_1998FC;
      v8 = *(_BYTE *)(v7 + 37);
      v59 = v6;
      if ( v8 )
      {
        if ( v8 <= 2u )
        {
          LODWORD(v66) = v66 - 23;
          LODWORD(v67) = v67 - 20;
        }
        else if ( v8 <= 5u )
        {
          LODWORD(v66) = v66 - 47;
          LODWORD(v67) = v67 - 44;
        }
      }
      else
      {
        LODWORD(v66) = v66 - 12;
        LODWORD(v67) = v67 - 9;
      }
      v9 = 313 * a1;
      LOBYTE(v9) = *(_BYTE *)(dword_192864 + v9 + 37);
      if ( (_BYTE)v9 )
      {
        if ( (uint8_t)v9 <= 2u )
        {
          v10 = 4;
        }
        else
        {
          if ( (uint8_t)v9 > 5u )
          {
LABEL_20:
            LOWORD(v9) = *(_WORD *)(a5 + 6);
            v64 = v9;
            LOWORD(v9) = 20 * word_1998F0;
            v11 = v63 - v9;
            v12 = v11 + v66;
            LOWORD(v11) = 20 * word_1998F2;
            v62 = v12;
            v60 = HIDWORD(v61) - v11 + v67;
            word_1998FC = a1;
            *(_WORD *)(dword_192864 + 313 * a1 + 67) = 0;
            v13 = sub_124D7A();
            sub_2C6BA(v13);
            sub_124E36();
            if ( word_19987E == 1 || word_1998CE )
              HIDWORD(v66) = 2;
            else
              HIDWORD(v66) = 1;
            v14 = dword_192864;
            v15 = *(uint8_t *)(dword_192864 + 313 * a1 + 37);
            LOWORD(v65) = 0;
            sub_AEC0B(v15);
            while ( 1 )
            {
              if ( (int16_t)v65 >= (int16_t)v64 )
              {
                word_1998FC = (int16_t)v59;
                goto LABEL_84;
              }
              sub_12C2A0();
              if ( (int16_t)v65 >= (int16_t)v64 / 2 )
                *(_BYTE *)(dword_192864 + 313 * a1 + 36) = 5;
              v16 = sub_124D41();
              sub_2F4EE(v16);
              sub_128AB6(0, 0, 639, 350);
              sub_12B634();
              v17 = 313 * a1;
              if ( !*(_BYTE *)(v17 + dword_192864 + 36) )
              {
                LOWORD(v17) = 20 * word_1998F0;
                sub_30062(
                  a1,
                  v63 - v17,
                  v55[0],
                  v55[1],
                  v55[2],
                  v55[3],
                  v55[4],
                  v55[5],
                  v55[6],
                  v55[7],
                  v56,
                  v57,
                  v58,
                  (int)v59,
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  v67,
                  *(int64_t *)savedregs);
              }
              v18 = *(_BYTE *)(dword_192864 + 313 * a1 + 37);
              if ( !v18 )
                break;
              if ( v18 <= 2u )
              {
                v19 = 4;
                goto LABEL_36;
              }
              if ( v18 <= 5u )
              {
                v19 = 5;
                goto LABEL_36;
              }
LABEL_37:
              sub_12B753(a5, (int16_t)v65);
              v14 = (int16_t)v60;
              sub_12A478(v62, v60, a5);
              sub_12B65C();
              LOWORD(v20) = sub_128BE7();
              sub_1077D(v20);
              sub_12C2C6(1);
              LOWORD(v65) = WORD2(v66) + v65;
            }
            v19 = 3;
LABEL_36:
            a5 = sub_127C27((int)aCmbtsfxLbx_0, v19, dword_193174);
            goto LABEL_37;
          }
          v10 = 5;
        }
      }
      else
      {
        v10 = 3;
      }
      v9 = sub_127C27((int)aCmbtsfxLbx_0, v10, dword_193174);
      a5 = v9;
      goto LABEL_20;
    }
    v21 = sub_38656(v57);
    sub_ADE18(v57, (int16_t)v63, SWORD6(v61), a3, v21);
    *(_BYTE *)(v56 + dword_192864 + 36) = 5;
  }
}
// AEF33: variable 'v20' is possibly undefined
// AEFB4: variable 'v22' is possibly undefined
// AF271: variable 'v48' is possibly undefined
// AF2AD: variable 'v51' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 19283C: using guessed type int dword_19283C;
// 192840: using guessed type int dword_192840;
// 192864: using guessed type int dword_192864;
// 193174: using guessed type int dword_193174;
// 19987E: using guessed type int16_t word_19987E;
// 19988E: using guessed type int16_t word_19988E;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998F0: using guessed type int16_t word_1998F0;
// 1998F2: using guessed type int16_t word_1998F2;
// 1998F8: using guessed type int16_t word_1998F8;
// 1998FC: using guessed type int16_t word_1998FC;


//----- (000AF37E) --------------------------------------------------------
void __fastcall sub_AF37E( int a1, int a2, int a3, int a4)
{
  int16_t v5; // cx
  _WORD *v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int16_t i; // di
  int v11; // eax
  int v12; // eax
  int16_t v13; // ax
  int16_t v15; // [esp+4h] [ebp-18h]
  int16_t v16; // [esp+8h] [ebp-14h]
  int16_t v18; // [esp+14h] [ebp-8h]

  v15 = 8;
  v18 = *(_WORD *)(dword_192B14 + 26 * a1 + 6);
  v5 = 0;
  if ( word_19987E == 1 || word_1998CE )
    v16 = 9;
  else
    v16 = 3;
  v6 = (_WORD *)(26 * a1 + dword_192B14);
  if ( *v6 == 19 || *v6 == 40 )
  {
    v15 = 10000;
    *(_WORD *)(26 * a1 + dword_192B14 + 19) = 10000;
  }
  if ( !word_1998E0 )
  {
    switch ( *(_WORD *)(dword_192B14 + 26 * a1) )
    {
      case 0xE:
        v7 = 500;
        goto LABEL_11;
      case 0xF:
        v9 = 32;
        goto LABEL_19;
      case 0x10:
        v7 = -1500;
        goto LABEL_11;
      case 0x11:
        v7 = -2500;
LABEL_11:
        v8 = sub_147D7(32);
        sub_112CD9(v8, v7);
        break;
      case 0x12:
        v9 = 61;
        goto LABEL_19;
      case 0x13:
        v9 = 60;
        goto LABEL_19;
      case 0x14:
        v9 = 59;
        goto LABEL_19;
      default:
        v9 = 32;
LABEL_19:
        sub_147D7(v9);
        break;
    }
  }
  for ( i = 0; i < v15 && !v5; i += v16 )
  {
    v5 = (uint8_t)sub_3CEB7(a1, a2, a3, 4 * v16);
    if ( !word_1998E0 )
    {
      v11 = sub_124D41();
      v12 = sub_2F4EE(v11);
      sub_1077D(v12);
    }
    if ( a4 == 1 )
    {
      if ( *(int16_t *)(dword_192B14 + 26 * v18 + 15) > 0 )
        goto LABEL_29;
      v13 = a1;
    }
    else
    {
      if ( !*(_BYTE *)(dword_192864 + 313 * *(int16_t *)(dword_192B14 + 26 * a1 + 6) + 36) )
        goto LABEL_29;
      v13 = a1;
    }
    sub_3DDD8(v13);
    v5 = 0;
LABEL_29:
    if ( v5 )
      sub_3D2DF(a1, a2, a3);
  }
}
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 2F4EE: using guessed type int __fastcall sub_2F4EE(_DWORD);
// 192864: using guessed type int dword_192864;
// 192B14: using guessed type int dword_192B14;
// 19987E: using guessed type int16_t word_19987E;
// 1998CE: using guessed type int16_t word_1998CE;
// 1998E0: using guessed type int16_t word_1998E0;


//----- (000AF542) --------------------------------------------------------
int sub_AF542()
{
  int v0; // ebx
  _DWORD *v1; // eax
  int result; // eax
  int v3; // edx

  v0 = 0;
  do
  {
    if ( (_WORD)v0 )
      v1 = sub_110D3C(dword_192F08, 11264);
    else
      v1 = sub_110CEE(dword_192F08, 11264);
    dword_19D88C[(int16_t)v0] = (int)v1;
    result = j___clock((int16_t)v0, v1, v0);
    v3 = (int16_t)v0++;
    word_19D79C[v3] = -1;
    word_19D7EC[v3] = -1;
    word_19D83C[v3] = -1;
    dword_19D92C[v3] = result;
  }
  while ( (int16_t)v0 < 40 );
  return result;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 192F08: using guessed type int dword_192F08;
// 19D79C: using guessed type int16_t word_19D79C[40];
// 19D7EC: using guessed type int16_t word_19D7EC[40];
// 19D83C: using guessed type int16_t word_19D83C[40];
// 19D88C: using guessed type int dword_19D88C[40];
// 19D92C: using guessed type int dword_19D92C[40];


//----- (000AF5AE) --------------------------------------------------------
int sub_AF5AE()
{
  int v0; // ebx
  int64_t v1; // rax

  v0 = 0;
  do
  {
    dword_19D88C[(int16_t)v0] = 0;
    word_19D79C[(int16_t)v0] = -1;
    word_19D7EC[(int16_t)v0] = -1;
    word_19D83C[(int16_t)v0] = -1;
    v1 = j___clock();
    ++v0;
    dword_19D92C[HIDWORD(v1)] = v1;
  }
  while ( (int16_t)v0 < 40 );
  return v1;
}
// 129FE4: using guessed type int64_t j___clock(void);
// 19D79C: using guessed type int16_t word_19D79C[40];
// 19D7EC: using guessed type int16_t word_19D7EC[40];
// 19D83C: using guessed type int16_t word_19D83C[40];
// 19D88C: using guessed type int dword_19D88C[40];
// 19D92C: using guessed type int dword_19D92C[40];


//----- (000AF5F6) --------------------------------------------------------
int __fastcall sub_AF5F6( int a1, int a2, int a3)
{
  int16_t i; // dx

  for ( i = 0; i < 40; ++i )
  {
    if ( a3 == word_19D79C[i] && a1 == word_19D7EC[i] && word_19D83C[i] == a2 )
    {
      dword_19D92C[i] = j___clock();
      return dword_19D9CC[i];
    }
  }
  return 0;
}
// 129FE4: using guessed type int j___clock(void);
// 19D79C: using guessed type int16_t word_19D79C[40];
// 19D7EC: using guessed type int16_t word_19D7EC[40];
// 19D83C: using guessed type int16_t word_19D83C[40];
// 19D92C: using guessed type int dword_19D92C[40];
// 19D9CC: using guessed type int dword_19D9CC[40];


//----- (000AF64E) --------------------------------------------------------
char sub_AF64E()
{
  int16_t v0; // dx
  int16_t i; // ax

  v0 = 0;
  for ( i = 0; i < 40; ++i )
  {
    if ( dword_19D92C[i] < (unsigned int)dword_19D92C[v0] )
      v0 = i;
  }
  return v0;
}
// 19D92C: using guessed type int dword_19D92C[40];


//----- (000AF67A) --------------------------------------------------------
int __fastcall sub_AF67A(int a1, int a2)
{
  int16_t v2; // bx
  int v3; // edx
  int result; // eax

  v2 = a1;
  v3 = j___clock(a1, a2, a1);
  result = v2;
  dword_19D92C[v2] = v3;
  return result;
}
// 129FE4: using guessed type int __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 19D92C: using guessed type int dword_19D92C[40];


//----- (000AF692) --------------------------------------------------------
int __fastcall sub_AF692( int a1, int a2, int a3)
{
  int v4; // edx
  int result; // eax

  v4 = 0;
  do
  {
    result = 2 * (int16_t)v4;
    if ( a3 == *(int16_t *)((char *)word_19D79C + result)
      && word_19D7EC[(int16_t)v4] == a1
      && a2 == word_19D83C[(int16_t)v4] )
    {
      result = j___clock(result, v4, (int16_t)v4);
      dword_19D92C[(int16_t)v4] = result;
    }
    ++v4;
  }
  while ( (int16_t)v4 < 40 );
  return result;
}
// 129FE4: using guessed type int __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 19D79C: using guessed type int16_t word_19D79C[40];
// 19D7EC: using guessed type int16_t word_19D7EC[40];
// 19D83C: using guessed type int16_t word_19D83C[40];
// 19D92C: using guessed type int dword_19D92C[40];


//----- (000AF6DC) --------------------------------------------------------
int __fastcall sub_AF6DC( int a1, int a2, int a3)
{
  int v5; // ebx
  char *v6; // eax
  int v7; // ecx
  int v8; // edx
  _BYTE v10[28]; // [esp+0h] [ebp-20h] BYREF
  int v11; // [esp+1Ch] [ebp-4h]

  v5 = a3 - 1;
  v6 = (char *)sub_CDF5C(201);
  sprintf(v10, v6, v5 / 10);
  v11 = 10;
  v7 = dword_193174;
  v8 = 36 * (v5 % 10) + (int16_t)sub_BC8A6(a1, a2);
  return sub_127C27((int)v10, v8, v7);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 193174: using guessed type int dword_193174;


//----- (000AF74F) --------------------------------------------------------
_DWORD *sub_AF74F()
{
  _DWORD *result; // eax

  word_1828BA = -1;
  result = sub_110D3C(dword_192ED4, 2806);
  dword_19DE8C = (int)result;
  return result;
}
// 1828BA: using guessed type int16_t word_1828BA;
// 192ED4: using guessed type int dword_192ED4;
// 19DE8C: using guessed type int dword_19DE8C;


//----- (000AF76F) --------------------------------------------------------
int __fastcall sub_AF76F( int a1)
{
  int result; // eax

  result = sub_AF7B4(*(char *)(dword_192B18 + 361 * dword_19F7A8), a1, dword_19F7A8);
  if ( (int16_t)result != -1 )
    *(_BYTE *)(dword_197F9C + 129 * (int16_t)result + 100) = 6;
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 197F9C: using guessed type int dword_197F9C;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000AF7B4) --------------------------------------------------------
int __fastcall sub_AF7B4(int a1, int a2, int a3)
{
  int v3; // eax
  int16_t v4; // cx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  char *v10; // eax
  char *v11; // eax
  int v12; // edx
  int v14; // [esp-8h] [ebp-208h]
  int v15; // [esp-8h] [ebp-208h]
  int v16; // [esp-4h] [ebp-204h]
  int v17; // [esp-4h] [ebp-204h]
  int16_t v18; // [esp+0h] [ebp-200h]
  char v19[500]; // [esp+4h] [ebp-1FCh] BYREF
  int v20; // [esp+1F8h] [ebp-8h]
  int v21; // [esp+1FCh] [ebp-4h]

  v3 = 17 * *(int16_t *)(361 * a3 + dword_192B18 + 2);
  v21 = 0;
  v4 = *(uint8_t *)(dword_1930D4 + v3 + 2);
  while ( (int16_t)v21 < 500 )
  {
    v5 = 129 * (int16_t)v21 + dword_197F9C;
    if ( *(char *)(v5 + 99) == v18 && (*(_BYTE *)(v5 + 100) == 5 || word_199994 <= (int16_t)v21) )
      break;
    ++v21;
  }
  if ( (int16_t)v21 >= 500 )
    return -1;
  if ( word_199994 <= (int16_t)v21 )
    word_199994 = v21 + 1;
  v6 = 129 * (int16_t)v21;
  memset(v6 + dword_197F9C, 0, 129);
  v20 = 3753 * v18;
  sub_12779E((_BYTE *)(v6 + dword_197F9C), (_BYTE *)(v20 + dword_197F98 + 806 + 99 * a2), 0x63u);
  v7 = v6 + dword_197F9C;
  *(_BYTE *)(v7 + 99) = v18;
  *(_BYTE *)(v7 + 93) = v18;
  v8 = 113 * v4;
  *(_WORD *)(v7 + 101) = v4;
  v9 = dword_19306C;
  *(_BYTE *)(v7 + 100) = 0;
  *(_WORD *)(v7 + 103) = *(_WORD *)(v9 + v8 + 15);
  LOWORD(v8) = *(_WORD *)(v9 + v8 + 17);
  *(_WORD *)(v7 + 116) = -1;
  *(_WORD *)(v7 + 105) = v8;
  if ( byte_199CB4 )
  {
    v16 = *(int16_t *)(2 * *(uint8_t *)(v7 + 16) + v20 + dword_197F98 + 1400);
    v14 = v7;
    v10 = (char *)sub_CDF5C(42);
    sprintf(v19, v10, v14, v16);
    if ( strlen(v19) >= 0xF )
    {
      v17 = *(int16_t *)(v20 + dword_197F98 + 2 * *(uint8_t *)(v6 + dword_197F9C + 16) + 1400);
      v15 = v6 + dword_197F9C;
      v11 = (char *)sub_CDF5C(72);
      sprintf(v19, v11, v15, v17);
      if ( strlen(v19) >= 0xF )
        strcpy(v19, (char *)(dword_197F9C + v6));
    }
    v12 = 129 * (int16_t)v21;
    strcpy((char *)(v12 + dword_197F9C), v19);
    ++*(_WORD *)(dword_197F98 + 3753 * v18 + 2 * *(uint8_t *)(v12 + dword_197F9C + 16) + 1400);
  }
  return v21;
}
// AF806: variable 'v18' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199CB4: using guessed type char byte_199CB4;


//----- (000AFA36) --------------------------------------------------------
char __fastcall sub_AFA36( int a1)
{
  int16_t i; // ax

  for ( i = 0; i < 7; ++i )
  {
    if ( a1 == word_1828AC[i] )
      return 1;
  }
  return 0;
}
// 1828AC: using guessed type int16_t word_1828AC[];


//----- (000AFA5C) --------------------------------------------------------
int __fastcall sub_AFA5C(int a1, int a2, int a3, int a4)
{
  sub_120CCB(3, (int)&unk_1827AD);
  sub_120E8C(1);
  sub_120E60(2);
  sub_AFAB9((int)byte_19DA6C, a4);
  sub_103915(3);
  return sub_120CCB(3, (int)&unk_1827AD);
}
// 103915: using guessed type _DWORD __stdcall sub_103915(int16_t);


//----- (000AFAB9) --------------------------------------------------------
void __fastcall sub_AFAB9(int a1, int a2)
{
  int v2; // ebx
  int v3; // eax

  if ( a2 != word_1828BC )
  {
    word_1828BA = -1;
    v2 = dword_19DE8C;
    word_1828BC = a2;
    v3 = sub_CDF5C(368);
    strcpy(byte_19DA6C, (char *)sub_126BDD(v3, a2, v2, 0, 1u, 600));
  }
}
// 1828BA: using guessed type int16_t word_1828BA;
// 1828BC: using guessed type int16_t word_1828BC;
// 19DE8C: using guessed type int dword_19DE8C;


//----- (000AFB0D) --------------------------------------------------------
int __cdecl sub_AFB0D(
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
        int a27,
        int a28)
{
  int16_t v28; // cx

  sub_A6547((char *)&STACK[0xAFA]);
  sub_120CCB(3, (int)&unk_1827AD);
  sub_120E8C(1);
  sub_120E60(2);
  if ( v28 != word_1828BA )
  {
    word_1828BA = v28;
    dword_19DD94 = (int)sub_126BDD((int)&STACK[0xAFA], 0, dword_19DE8C, v28, 1u, 1403);
  }
  strcpy((char *)&a28 + 2, (char *)(dword_19DD94 + 103));
  sub_103915(3);
  return sub_120CCB(3, (int)&unk_1827AD);
}
// AFB51: variable 'v28' is possibly undefined
// 103915: using guessed type _DWORD __stdcall sub_103915(int16_t);
// 1828BA: using guessed type int16_t word_1828BA;
// 19DD94: using guessed type int dword_19DD94;
// 19DE8C: using guessed type int dword_19DE8C;


//----- (000AFBC1) --------------------------------------------------------
void sub_AFBC1()
{
  word_1828BA = -1;
}
// 1828BA: using guessed type int16_t word_1828BA;


//----- (000AFBCB) --------------------------------------------------------
char __fastcall sub_AFBCB(char *a1, int a2)
{
  char result; // al
  char v4[20]; // [esp+0h] [ebp-14h] BYREF

  sub_A6547(v4);
  if ( a2 != word_1828BA )
  {
    word_1828BA = a2;
    dword_19DD94 = (int)sub_126BDD((int)v4, 0, dword_19DE8C, a2, 1u, 1403);
  }
  strcpy(a1, (char *)(dword_19DD94 + 103));
  return result;
}
// 1828BA: using guessed type int16_t word_1828BA;
// 19DD94: using guessed type int dword_19DD94;
// 19DE8C: using guessed type int dword_19DE8C;


//----- (000AFC6D) --------------------------------------------------------
int __fastcall sub_AFC6D( int a1)
{
  int16_t v1; // ax
  int result; // eax

  switch ( a1 )
  {
    case -17:
      v1 = 405;
      goto LABEL_3;
    case -16:
      v1 = 271;
      goto LABEL_3;
    case -15:
      v1 = 301;
      goto LABEL_3;
    case -13:
      v1 = 250;
      goto LABEL_3;
    case -12:
      v1 = 230;
      goto LABEL_3;
    case -11:
      v1 = 542;
      goto LABEL_3;
    case -10:
      v1 = 136;
      goto LABEL_3;
    case -9:
    case -1:
    case 0:
      v1 = 12;
      goto LABEL_3;
    case -8:
      v1 = 445;
      goto LABEL_3;
    case -7:
      v1 = 492;
      goto LABEL_3;
    case -6:
      v1 = 177;
      goto LABEL_3;
    case -5:
      v1 = 178;
      goto LABEL_3;
    case -4:
      v1 = 176;
      goto LABEL_3;
    case -3:
      v1 = 322;
      goto LABEL_3;
    case -2:
      v1 = 541;
LABEL_3:
      result = sub_CDF5C(v1);
      break;
    default:
      if ( a1 <= -100 || a1 > -50 )
        result = -1;
      else
        result = 3753 * *(char *)(361 * dword_19F7A8 + dword_192B18) + dword_197F98 + 806 - 99 * (a1 + 50);
      break;
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000AFD42) --------------------------------------------------------
void sub_AFD42()
{
  int v0; // ebx
  int64_t v1; // rax
  char *v2; // eax
  int v3; // [esp-Ch] [ebp-208h]
  int v4; // [esp-8h] [ebp-204h]
  int v5; // [esp-8h] [ebp-204h]
  bool v6; // [esp-4h] [ebp-200h]
  int16_t v7; // [esp+0h] [ebp-1FCh]
  char v8[500]; // [esp+4h] [ebp-1F8h] BYREF
  int v9; // [esp+1F8h] [ebp-4h]

  v0 = 0;
  WORD2(v1) = 0;
  while ( 1 )
  {
    v9 = 3753 * v7 + dword_197F98;
    LODWORD(v1) = SWORD2(v1) + v9;
    if ( *(_BYTE *)(v1 + 279) == 3 )
    {
      v6 = *(_BYTE *)(v9 + *(int16_t *)((char *)&word_17EB43 + 19 * SWORD2(v1)) + 279) == 3;
      v4 = *(int *)((char *)&off_17E079 + 13 * SWORD2(v1));
      v3 = *(uint8_t *)(v1 + 279);
      v2 = (char *)sub_CDF5C(15);
      v1 = sprintf(v8, v2, v3, v4, v6);
      v5 = (int16_t)v0++;
      _wcpp_1_unwind_leave(0, v5, v8);
    }
    ++WORD2(v1);
    if ( SWORD2(v1) >= 212 )
    {
      sub_6497C();
      JUMPOUT(0xAFDE2);
    }
  }
}
// AFDDD: control flows out of bounds to AFDE2
// AFD50: variable 'v7' is possibly undefined
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 17EB43: using guessed type int16_t word_17EB43;
// 197F98: using guessed type int dword_197F98;


//----- (000AFDE9) --------------------------------------------------------
void __fastcall sub_AFDE9( int a1)
{
  int v2; // edx
  int16_t v3; // ax

  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    if ( a1 == word_1828AC[v3] )
      ++v2;
    if ( ++v3 >= 7 )
      JUMPOUT(0xAF7AE);
  }
}
// AFE07: control flows out of bounds to AF7AE
// 1828AC: using guessed type int16_t word_1828AC[];


//----- (000AFE0C) --------------------------------------------------------
int __fastcall sub_AFE0C( int a1, int a2)
{
  int v4; // edx
  int16_t i; // ax

  v4 = 0;
  for ( i = 0; i < 7; ++i )
  {
    if ( a2 == *(_WORD *)(2 * i + dword_192B18 + 361 * a1 + 277) )
      ++v4;
  }
  return v4;
}
// 192B18: using guessed type int dword_192B18;


//----- (000AFE48) --------------------------------------------------------
int __fastcall sub_AFE48(int a1, int a2)
{
  int v4; // edx
  int16_t i; // ax

  v4 = 0;
  for ( i = 0; i < 7; ++i )
  {
    if ( a2 == *(_WORD *)(a1 + 2 * i + 277) )
      ++v4;
  }
  return v4;
}


//----- (000AFE6E) --------------------------------------------------------
int __fastcall sub_AFE6E( int a1)
{
  int result; // eax
  int16_t i; // dx
  int16_t v4; // di
  int v5; // ebx

  result = 0;
  for ( i = 0; i < 5; ++i )
  {
    v4 = *(_WORD *)(113 * a1 + dword_19306C + 2 * i + 74);
    if ( v4 != -1 )
    {
      v5 = *(int16_t *)(dword_1930D4 + 17 * v4);
      if ( (v5 == -1 || *(_BYTE *)(dword_192B18 + 361 * v5 + 6)) && *(_BYTE *)(dword_1930D4 + 17 * v4 + 4) == 3 )
        ++result;
    }
  }
  return result;
}
// AFEAA: conditional instruction was optimized away because ebx.4 is in (<8000u|FFFF8000..FFFFFFFE)
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000AFEE0) --------------------------------------------------------
int __fastcall sub_AFEE0(int16_t *a1, int16_t *a2)
{
  int v3; // edx
  int v4; // eax

  v3 = sub_BB40D(*a2);
  v4 = sub_BB40D(*a1);
  return strcmp(v4, v3);
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);


//----- (000AFEFC) --------------------------------------------------------
int __fastcall sub_AFEFC(int a1, int a2, int a3)
{
  char v3; // al
  int v4; // eax

  word_1827CE[0] = -2;
  word_1827D0 = -3;
  sub_16948F();
  word_18283A = 2;
  do
  {
    sub_E11BC((char *)(361 * dword_19F7A8 + dword_192B18), a3);
    if ( (word_18283A <= 54 && v3 == 1 || byte_182ACB) && a3 != 11 )
    {
      v4 = word_18283A++;
      word_1827CE[v4] = a3;
    }
    ++a3;
  }
  while ( a3 < 49 );
  return qsort(&unk_1827D2, word_18283A - 2, 2);
}
// AFF38: variable 'v3' is possibly undefined
// 1827CE: using guessed type int16_t word_1827CE[];
// 1827D0: using guessed type int16_t word_1827D0;
// 18283A: using guessed type int16_t word_18283A;
// 182ACB: using guessed type char byte_182ACB;
// 192B18: using guessed type int dword_192B18;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000AFF9E) --------------------------------------------------------
void sub_AFF9E()
{
  int16_t v0; // ax
  int16_t v1; // dx
  int16_t v2; // ax
  char v3; // al
  int v4; // eax
  char v5; // al
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  char *v10; // eax
  int v11; // eax
  int v12; // eax
  int16_t v13; // bx
  int16_t i; // cx
  _BYTE *v15; // edx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  char v20; // al
  int v21; // eax
  char v22; // al
  int v23; // eax
  char v24; // al
  int v25; // eax
  char v26; // al
  int v27; // eax

  v0 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * dword_19F7A8 + 2) + 2);
  word_1828A8 = 0;
  v1 = sub_AFE6E(v0);
  sub_AFDE9(11);
  if ( v1 > v2 )
  {
    sub_E11BC((char *)(dword_192B18 + 361 * dword_19F7A8), 11);
    if ( v3 )
    {
      v4 = word_1828A8++;
      word_18283C[v4] = 11;
    }
  }
  if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 348) == 3 )
  {
    sub_E11BC((char *)(dword_192B18 + 361 * dword_19F7A8), -15);
    if ( v5 )
    {
      v6 = word_1828A8++;
      word_18283C[v6] = -15;
    }
  }
  v7 = dword_197F98 + 3753 * *(char *)(dword_192B18 + 361 * dword_19F7A8);
  if ( *(int16_t *)(v7 + 804) > 0 && *(_BYTE *)(v7 + 1440) )
  {
    if ( *(_BYTE *)(v7 + 320) == 3 )
    {
      v8 = word_1828A8++;
      word_18283C[v8] = -12;
    }
    if ( *(_BYTE *)(3753 * *(char *)(dword_192B18 + 361 * dword_19F7A8) + dword_197F98 + 388) == 3 )
    {
      v9 = word_1828A8++;
      word_18283C[v9] = -17;
    }
    v10 = (char *)(361 * dword_19F7A8 + dword_192B18);
    if ( *(_BYTE *)(3753 * *v10 + dword_197F98 + 468) == 3 && v10[332] )
    {
      v11 = word_1828A8++;
      word_18283C[v11] = -11;
    }
    if ( word_1828A8 )
    {
      v12 = word_1828A8++;
      word_18283C[v12] = -9;
    }
    v13 = -50;
    for ( i = 0; i < 5; ++i )
    {
      v15 = sub_B2FFA(v13);
      v16 = sub_CDF5C(12);
      if ( strcmp(v16, v15)
        && (!byte_199CB4
         || *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 99 * i + 822) != 4
         || *(_BYTE *)(dword_197F98 + 3753 * *(char *)(361 * dword_19F7A8 + dword_192B18) + 465) == 3) )
      {
        v17 = word_1828A8++;
        word_18283C[v17] = v13;
      }
      --v13;
    }
    if ( *(_BYTE *)(dword_197F98 + 3753 * *(char *)(361 * dword_19F7A8 + dword_192B18) + 334) == 3 && byte_199CB4 )
    {
      v18 = word_1828A8++;
      word_18283C[v18] = -16;
    }
  }
  if ( word_1828A8 )
  {
    v19 = word_1828A8++;
    word_18283C[v19] = -9;
  }
  sub_E11BC((char *)(dword_192B18 + 361 * dword_19F7A8), -4);
  if ( v20 )
  {
    v21 = word_1828A8++;
    word_18283C[v21] = -4;
  }
  sub_E11BC((char *)(dword_192B18 + 361 * dword_19F7A8), -5);
  if ( v22 )
  {
    v23 = word_1828A8++;
    word_18283C[v23] = -5;
  }
  sub_E11BC((char *)(dword_192B18 + 361 * dword_19F7A8), -6);
  if ( v24 )
  {
    v25 = word_1828A8++;
    word_18283C[v25] = -6;
  }
  sub_E11BC((char *)(361 * dword_19F7A8 + dword_192B18), -7);
  if ( v26 )
  {
    v27 = word_1828A8++;
    word_18283C[v27] = -7;
  }
}
// AFFE2: variable 'v2' is possibly undefined
// B0002: variable 'v3' is possibly undefined
// B0057: variable 'v5' is possibly undefined
// B02A7: variable 'v20' is possibly undefined
// B02DF: variable 'v22' is possibly undefined
// B0317: variable 'v24' is possibly undefined
// B034E: variable 'v26' is possibly undefined
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 18283C: using guessed type int16_t word_18283C[54];
// 1828A8: using guessed type int16_t word_1828A8;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199CB4: using guessed type char byte_199CB4;
// 19F7A8: using guessed type int dword_19F7A8;


//----- (000B0397) --------------------------------------------------------
int __fastcall sub_B0397(int result)
{
  int16_t *v1; // ecx
  int16_t v2; // si
  int v3; // edx
  int16_t j; // ax
  char v5; // al
  int16_t v6; // ax
  void *v7; // edx
  int16_t i; // ax
  char v9; // al
  _BYTE *v10; // eax
  int16_t v11; // dx

  v1 = (int16_t *)result;
  v2 = 0;
LABEL_28:
  if ( v2 < word_18283A )
  {
    while ( 1 )
    {
      v3 = word_1827CE[v2];
      if ( v3 == -3 || v3 == -2 || v3 == -10 )
      {
        for ( i = 0; i < 7; ++i )
        {
          if ( word_1827CE[v2] == word_1828AC[i] )
          {
            v9 = 1;
            goto LABEL_20;
          }
        }
        v9 = 0;
LABEL_20:
        if ( !v9 )
        {
          v6 = 4 - *v1;
          v7 = &unk_1827B5;
          goto LABEL_22;
        }
      }
      else
      {
        for ( j = 0; j < 7; ++j )
        {
          if ( word_1827CE[v2] == word_1828AC[j] )
          {
            v5 = 1;
            goto LABEL_11;
          }
        }
        v5 = 0;
LABEL_11:
        if ( !v5 )
        {
          v6 = 4 - *v1;
          v7 = &unk_1827B5;
          goto LABEL_22;
        }
      }
      v6 = 4 - *v1;
      v7 = &unk_1827AD;
LABEL_22:
      sub_120CCB(v6, (int)v7);
      v10 = sub_B2FFA(word_1827CE[v2]);
      result = sub_103971(640, v10, 0);
      v11 = result;
      if ( (int16_t)result > 171 )
        ++*v1;
      if ( *v1 > 2 )
        v11 = 0;
      if ( v11 <= 171 )
      {
        ++v2;
        goto LABEL_28;
      }
    }
  }
  return result;
}
// 103971: using guessed type int __fastcall sub_103971(_DWORD, _DWORD, _DWORD);
// 1827CE: using guessed type int16_t word_1827CE[];
// 18283A: using guessed type int16_t word_18283A;
// 1828AC: using guessed type int16_t word_1828AC[];


//----- (000B0499) --------------------------------------------------------
int __fastcall sub_B0499(int result)
{
  int16_t *v1; // ecx
  int16_t i; // si
  _BYTE *v3; // eax
  int16_t v4; // dx

  v1 = (int16_t *)result;
  for ( i = 0; i < word_1828A8; ++i )
  {
    do
    {
      sub_120CCB(4 - *v1, (int)&unk_1827AD);
      v3 = sub_B2FFA(word_18283C[i]);
      result = sub_103971(640, v3, 0);
      v4 = result;
      if ( (int16_t)result > 138 )
        ++*v1;
      if ( *v1 > 2 )
        v4 = 0;
    }
    while ( v4 > 138 );
  }
  return result;
}
// 103971: using guessed type int __fastcall sub_103971(_DWORD, _DWORD, _DWORD);
// 18283C: using guessed type int16_t word_18283C[54];
// 1828A8: using guessed type int16_t word_1828A8;


