#include "orion_common.h"

/* Adresni rozsah: 0x15562C - 0x15EA74  (200 funkci) */

//----- (0015562C) --------------------------------------------------------
void sub_15562C()
{
  int v0; // esi
  _BOOL1 v1; // sf
  _BOOL1 v2; // of

  sub_13F949();
  v0 = 56;
  do
  {
    sub_1404C7(v0);
    v2 = __OFSUB__(v0, 4);
    v1 = v0 - 4 < 0;
    v0 -= 4;
  }
  while ( v1 == v2 );
  sub_13F94E();
}


//----- (00155650) --------------------------------------------------------
void __cdecl sub_155650(int a1)
{
  sub_13F949();
  if ( a1 != -1 && *(int *)((char *)dword_1898AC + a1) == 2 )
    *(int *)((char *)dword_1898AC + a1) = 1;
  sub_13F94E();
}
// 1898AC: using guessed type int dword_1898AC[];


//----- (00155680) --------------------------------------------------------
void sub_155680()
{
  int v0; // esi
  _BOOL1 v1; // sf
  _BOOL1 v2; // of

  sub_13F949();
  v0 = 56;
  do
  {
    sub_140596(v0);
    v2 = __OFSUB__(v0, 4);
    v1 = v0 - 4 < 0;
    v0 -= 4;
  }
  while ( v1 == v2 );
  sub_13F94E();
}


//----- (001556A4) --------------------------------------------------------
void __cdecl sub_1556A4(int a1, int a2)
{
  sub_13F949();
  *(int *)((char *)dword_18992C + a1) = a2;
  *(int *)((char *)dword_1898EC + a1) = 0;
  sub_154F23();
  sub_13F94E();
}
// 1898EC: using guessed type int dword_1898EC[];
// 18992C: using guessed type int dword_18992C[];


//----- (001556D4) --------------------------------------------------------
void __cdecl sub_1556D4(int a1, unsigned int a2)
{
  sub_13F949();
  sub_140287(a1, 1000000u / a2); // vlna 12: "&loc_F4240" = konstanta 1e6 (us/Hz)
  sub_13F94E();
}


//----- (00155704) --------------------------------------------------------
void __cdecl sub_155704(int a1, unsigned int a2)
{
  int v2; // eax

  sub_13F949();
  if ( a2 )
    v2 = 10000 * (uint64_t)a2 / 0x2E9C;
  else
    v2 = 54925;
  sub_140287(a1, v2);
  sub_13F94E();
}


//----- (00155746) --------------------------------------------------------
int sub_155746()
{
  return dword_1899F6;
}
// 1899F6: using guessed type int dword_1899F6;


//----- (00155752) --------------------------------------------------------
bool sub_155752()
{
  sub_15421D((unsigned int)dword_18986C, (unsigned int)&dword_18A41C);
  return sub_15421D((unsigned int)sub_154D80, (unsigned int)sub_155752);
}
// 18986C: using guessed type int dword_18986C[];
// 18A41C: using guessed type int dword_18A41C;


//----- (001557D8) --------------------------------------------------------
bool sub_1557D8()
{
  bool result; // eax

  if ( !dword_18A420 )
  {
    sub_15421D((unsigned int)sub_1557D8, (unsigned int)sub_1560A9);
    sub_1543A1((unsigned int)dword_1C9400, 64);
    sub_1543A1((unsigned int)dword_1C9540, 72);
    sub_1543A1((unsigned int)&byte_1C9440, 256);
    sub_1543A1((unsigned int)&unk_1C9588, 24);
    sub_1543A1((unsigned int)&dword_18A41C, 4);
    result = sub_1543A1((unsigned int)&dword_1C95A0, 4);
    dword_18A420 = 1;
  }
  return result;
}
// 18A41C: using guessed type int dword_18A41C;
// 18A420: using guessed type int dword_18A420;
// 1C9400: using guessed type int dword_1C9400[];
// 1C9440: using guessed type char byte_1C9440;
// 1C9540: using guessed type int dword_1C9540[];
// 1C95A0: using guessed type int dword_1C95A0;


//----- (00155861) --------------------------------------------------------
void __cdecl sub_155861(int a1)
{
  if ( !dword_18A41C )
  {
    dword_18A41C = 1;
    dword_1C95A0 = sub_13FBB5();
    sub_13FBC8(a1, 770, 0, 0);
    sub_13FBBA(dword_1C95A0);
    dword_18A41C = 0;
  }
}
// 18A41C: using guessed type int dword_18A41C;
// 1C95A0: using guessed type int dword_1C95A0;


//----- (001558B0) --------------------------------------------------------
int __cdecl sub_1558B0(int a1, int a2, _DWORD *a3)
{
  unsigned int i; // ecx
  int v4; // edx
  int j; // edx
  int v6; // ebx
  int v8; // [esp+0h] [ebp-10h]
  int v9; // [esp+4h] [ebp-Ch]

  v8 = 0;
  v9 = 1;
  for ( i = 0; i < strlen(a1); ++i )
  {
    v4 = *(uint8_t *)(a1 + i);
    if ( v4 == 45 )
    {
      v9 = -v9;
    }
    else if ( (IsTable[(uint8_t)(v4 + 1)] & 2) == 0 )
    {
      for ( j = 0; j < a2; ++j )
      {
        v6 = (uint8_t)byte_17C278[j];
        if ( toupper(*(uint8_t *)(i + a1), j) == v6 )
        {
          v8 = j + a2 * v8;
          break;
        }
      }
      if ( j == a2 )
        break;
    }
  }
  if ( a3 )
    *a3 = i + a1;
  return v9 * v8;
}
// 13E22A: using guessed type int __fastcall toupper(_DWORD, _DWORD);
// 14432F: using guessed type int __fastcall strlen(_DWORD);


//----- (00155951) --------------------------------------------------------
int __cdecl sub_155951(void *a1, int a2)
{
  unsigned int j; // ecx
  int result; // eax
  int v4; // ebp
  int i; // ecx
  _BYTE *v6; // esi
  _BYTE *v7; // edx
  _BYTE *v8; // edx
  _WORD *v9; // eax
  _WORD v10[140]; // [esp+0h] [ebp-174h] BYREF
  _BYTE v11[92]; // [esp+118h] [ebp-5Ch] BYREF

  memset(v10, 0, sizeof(v10));
  memset(&v10[128], -1, 24);
      // DECOMP_TODO (castecne vyreseno ve vlne 06): chybel mod parametr - v okoli se nenaslo jednoznacne fread/fwrite, takze "aRb" je bezpecny odhad (needela zadnou zapisovou vedlejsi ucinek jako by mohl "wb"), potrebuje overit.
    result = fopen(a2, aRb);
  v4 = result;
  if ( !result )
    return result;
  while ( fgets(v11, 80, v4, j) && (*(_BYTE *)(v4 + 12) & 0x10) == 0 )
  {
    for ( i = strlen(v11) - 1; i >= 0 && (IsTable[(uint8_t)(v11[i] + 1)] & 2) != 0; --i )
      v11[i] = 0;
    for ( j = 0; j < strlen(v11) && (IsTable[(uint8_t)(v11[j] + 1)] & 2) != 0; ++j )
      ;
    v6 = &v11[j];
    while ( j < strlen(v11) && (IsTable[(uint8_t)(v11[j] + 1)] & 2) == 0 )
      ++j;
    v7 = &v11[j];
    while ( j < strlen(v11) && (IsTable[(uint8_t)(v11[j] + 1)] & 2) != 0 )
      ++j;
    if ( j < strlen(v11) )
    {
      *v7 = 0;
      if ( *v6 != 59 )
      {
        if ( !strnicmp(v6, aDriver, 7) )
        {
          v8 = &v11[j];
          v9 = &v10[64];
          goto LABEL_22;
        }
        if ( !strnicmp(v6, aDevice, 7) )
        {
          v8 = &v11[j];
          v9 = v10;
LABEL_22:
          strcpy(v9, v8);
        }
        else if ( !strnicmp(v6, aIoAddr, 8) )
        {
          v10[128] = sub_1558B0((int)&v11[j], 16, 0);
        }
        else if ( !strnicmp(v6, aIrq, 4) )
        {
          v10[129] = sub_1558B0((int)&v11[j], 10, 0);
        }
        else if ( !strnicmp(v6, aDma8Bit, 10) )
        {
          v10[130] = sub_1558B0((int)&v11[j], 10, 0);
        }
        else if ( !strnicmp(v6, aDma16Bit, 11) )
        {
          v10[131] = sub_1558B0((int)&v11[j], 10, 0);
        }
      }
    }
  }
  fclose(v4);
  if ( strlen(&v10[64]) && strlen(v10) )
  {
    qmemcpy(a1, v10, 0x118u);
    return 1;
  }
  else
  {
    strcpy(&byte_1C9440, "Corrupted .INI file\n");
    return 0;
  }
}
// 155AC3: variable 'j' is possibly undefined
// 126911: using guessed type int __fastcall fgets(_DWORD, _DWORD, _DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 14432F: using guessed type int __fastcall strlen(_DWORD);
// 16023E: using guessed type int __fastcall strnicmp(_DWORD, _DWORD, _DWORD);
// 1C9440: using guessed type char byte_1C9440;


//----- (00155C19) --------------------------------------------------------
int __cdecl sub_155C19(int a1, int a2)
{
  int v2; // edx

  v2 = dword_1C9540[a1];
  dword_1C9540[a1] = a2;
  return v2;
}
// 1C9540: using guessed type int dword_1C9540[];


//----- (00155C32) --------------------------------------------------------
int *__cdecl sub_155C32(int a1, int a2)
{
  int *result; // eax
  int *v3; // ebp
  int v4; // eax
  unsigned int i; // ecx
  int v6; // eax
  int v7; // eax

  result = (int *)sub_1540A6(40);
  v3 = result;
  if ( !result )
  {
    strcpy(&byte_1C9440, "Insufficient memory for driver descriptor\n");
    return result;
  }
  if ( !sub_154124((unsigned int)(a2 + 15) >> 4, result + 2, result, result + 1) )
  {
    strcpy(&byte_1C9440, "Insufficient low memory\n");
    sub_1540EC((unsigned int)v3, 40);
    return 0;
  }
  memmove(v3[2], a1, a2);
  v4 = v3[2];
  v3[3] = v4;
  if ( !strnicmp(v4, aAil3dig, 7) )
  {
    v3[4] = 0;
  }
  else
  {
    if ( strnicmp(v3[3], aAil3mdi, 7) )
    {
      strcpy(&byte_1C9440, "Invalid driver type\n");
      sub_1541D2(v3[2], *v3, v3[1]);
LABEL_9:
      sub_1540EC((unsigned int)v3, 40);
      return 0;
    }
    v3[4] = 1;
  }
  for ( i = 0; i < 0x10; ++i )
  {
    if ( !dword_1C9400[i] )
    {
      dword_1C9400[i] = (int)v3;
      *(_WORD *)(v3[3] + 50) = i;
      break;
    }
  }
  if ( i == 16 )
  {
    strcpy(&byte_1C9440, "Out of driver handles\n");
    sub_1541D2(v3[2], *v3, v3[1]);
    goto LABEL_9;
  }
  *(_WORD *)(v3[3] + 48) = 0;
  v3[5] = 0;
  v3[6] = -1;
  sub_13F953(i, 7, 102);
  *(_DWORD *)(v3[3] + 54) = v6;
  sub_13FA3E(102, *v3 + *(uint16_t *)(v3[3] + 52));
  v3[8] = 0;
  v3[9] = 0;
  sub_13FBC8((int)v3, 768, 0, 0);
  if ( *(int16_t *)(v3[3] + 46) > 0 )
  {
    sub_1400A9((int)sub_155861);
    v3[7] = v7;
    if ( v7 == -1 )
    {
      strcpy(&byte_1C9440, "Out of timer handles\n");
      sub_13FA3E(102, *(_DWORD *)(v3[3] + 54));
      sub_1541D2(v3[2], *v3, v3[1]);
      goto LABEL_9;
    }
    sub_140194(v7, (int32_t)v3);
    sub_1402FD(v3[7], *(int16_t *)(v3[3] + 46));
    sub_1404C7(v3[7]);
  }
  else
  {
    v3[7] = -1;
  }
  return v3;
}
// 155D98: variable 'v6' is possibly undefined
// 155DF5: variable 'v7' is possibly undefined
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 16023E: using guessed type int __fastcall strnicmp(_DWORD, _DWORD, _DWORD);
// 1C9400: using guessed type int dword_1C9400[];
// 1C9440: using guessed type char byte_1C9440;


//----- (00155E62) --------------------------------------------------------
int __cdecl sub_155E62(unsigned int a1)
{
  int result; // eax
  int i; // edx

  if ( *(_DWORD *)(a1 + 32) )
    (*(void (__cdecl **)(_DWORD))(a1 + 32))(*(_DWORD *)(a1 + 36));
  if ( *(_DWORD *)(a1 + 28) != -1 )
    sub_140665(*(_DWORD *)(a1 + 28));
  if ( *(_DWORD *)(a1 + 20) )
  {
    if ( *(_DWORD *)(a1 + 24) != -1 )
      sub_13FB41(*(_DWORD *)(a1 + 24));
    sub_13FBC8(a1, 774, 0, 0);
  }
  sub_13FA3E(102, *(_DWORD *)(*(_DWORD *)(a1 + 12) + 54));
  sub_1541D2(*(_DWORD *)(a1 + 8), *(_DWORD *)a1, *(_DWORD *)(a1 + 4));
  result = sub_1540EC(a1, 40);
  for ( i = 0; i < 16; ++i )
  {
    result = 4 * i;
    if ( a1 == dword_1C9400[i] )
      dword_1C9400[i] = 0;
  }
  return result;
}
// 1C9400: using guessed type int dword_1C9400[];


//----- (00155F05) --------------------------------------------------------
void *__cdecl sub_155F05(int a1)
{
  void *result; // eax

  result = (void *)(16 * HIWORD(*(_DWORD *)(*(_DWORD *)(a1 + 12) + 18))
                  + (uint16_t)*(_DWORD *)(*(_DWORD *)(a1 + 12) + 18));
  if ( result )
  {
    result = (void *)getenv();
    if ( result )
    {
      strncpy(*(_DWORD *)(a1 + 12) + 58, result, 128);
      if ( sub_13FBC8(a1, 771, 0, 0) == -1 )
      {
        return 0;
      }
      else
      {
        qmemcpy(&unk_1C95A4, (void *)(*(_DWORD *)(a1 + 12) + 22), 0x18u);
        return &unk_1C95A4;
      }
    }
  }
  return result;
}
// 139ACE: using guessed type int __fastcall strncpy(_DWORD, _DWORD, _DWORD);
// 155777: using guessed type int getenv(void);


//----- (00155F76) --------------------------------------------------------
void __fastcall sub_155F76(int a1, unsigned int a2)
{
  int i; // eax

  sub_1557D8();
  sub_13F84F(0, 200);
  sub_13F84F(1, 1);
  sub_13F84F(2, 0x8000);
  sub_13F84F(3, 100);
  sub_13F84F(4, 16);
  sub_13F84F(5, 100);
  sub_13F84F(6, 655);
  sub_13F84F(7, 0);
  sub_13F84F(8, 0);
  sub_13F84F(9, 1);
  sub_13F84F(10, 120);
  sub_13F84F(11, 8);
  sub_13F84F(12, 127);
  sub_13F84F(13, 1);
  sub_13F84F(14, 0);
  sub_13F84F(15, 2);
  sub_13F84F(16, 1);
  sub_13F84F(17, 1);
  for ( i = 0; i < 16; ++i )
    dword_1C9400[i] = 0;
  BYTE1(i) = 0;
  byte_1C9440 = 0;
  sub_154F88(i, a2);
}
// 1C9400: using guessed type int dword_1C9400[];
// 1C9440: using guessed type char byte_1C9440;


//----- (0015607C) --------------------------------------------------------
int sub_15607C()
{
  int i; // esi

  for ( i = 15; i >= 0; --i )
  {
    if ( dword_1C9400[i] )
      sub_14090C(dword_1C9400[i]);
  }
  sub_1406D2();
  return sub_155076();
}
// 1C9400: using guessed type int dword_1C9400[];


//----- (001560A9) --------------------------------------------------------
bool sub_1560A9()
{
  bool result; // eax

  if ( dword_18A420 )
  {
    sub_1542DF((unsigned int)sub_1557D8, (unsigned int)sub_1560A9);
    sub_1543D5((unsigned int)dword_1C9400, 64);
    sub_1543D5((unsigned int)dword_1C9540, 72);
    sub_1543D5((unsigned int)&byte_1C9440, 256);
    sub_1543D5((unsigned int)&unk_1C9588, 24);
    sub_1543D5((unsigned int)&dword_18A41C, 4);
    result = sub_1543D5((unsigned int)&dword_1C95A0, 4);
    dword_18A420 = 0;
  }
  return result;
}
// 1557D8: using guessed type int sub_1557D8();
// 18A41C: using guessed type int dword_18A41C;
// 18A420: using guessed type int dword_18A420;
// 1C9400: using guessed type int dword_1C9400[];
// 1C9440: using guessed type char byte_1C9440;
// 1C9540: using guessed type int dword_1C9540[];
// 1C95A0: using guessed type int dword_1C95A0;


//----- (001562C0) --------------------------------------------------------
bool sub_1562C0()
{
  bool result; // eax

  if ( !dword_18A4A8 )
  {
    sub_15421D((unsigned int)sub_1562C0, (unsigned int)sub_157BF0);
    sub_1543A1((unsigned int)byte_18A424, 128);
    sub_1543A1((unsigned int)&dword_18A4A4, 4);
    sub_1543A1((unsigned int)&dword_1C95EC, 4);
    sub_1543A1((unsigned int)&unk_1C95D8, 12);
    sub_1543A1((unsigned int)&dword_1C95F4, 4);
    sub_1543A1((unsigned int)&dword_1C95F8, 4);
    sub_1543A1((unsigned int)&dword_1C95E8, 4);
    sub_1543A1((unsigned int)&dword_1C95F0, 4);
    sub_1543A1((unsigned int)&dword_1C95E4, 4);
    result = sub_1622BF();
    dword_18A4A8 = 1;
  }
  return result;
}
// 18A4A4: using guessed type int dword_18A4A4;
// 18A4A8: using guessed type int dword_18A4A8;
// 1C95E4: using guessed type int dword_1C95E4;
// 1C95E8: using guessed type int dword_1C95E8;
// 1C95EC: using guessed type int dword_1C95EC;
// 1C95F0: using guessed type int dword_1C95F0;
// 1C95F4: using guessed type int dword_1C95F4;
// 1C95F8: using guessed type int dword_1C95F8;


//----- (00156380) --------------------------------------------------------
int __cdecl sub_156380(int a1)
{
  int result; // eax
  _WORD v2[8]; // [esp+0h] [ebp-10h] BYREF

  if ( !*(_DWORD *)(a1 + 84) )
  {
    v2[3] = *(_WORD *)(a1 + 24);
    v2[2] = *(_WORD *)(a1 + 20);
    result = sub_13FBC8(*(_DWORD *)a1, 1025, v2, 0);
    *(_DWORD *)(a1 + 84) = 1;
  }
  return result;
}


//----- (00156400) --------------------------------------------------------
int *__cdecl sub_156400(int a1)
{
  int v1; // edx
  int v2; // esi
  int v3; // eax
  int v4; // ecx
  int v5; // edx
  int *result; // eax
  int v7; // edx
  int v8; // esi
  int v9; // ecx
  int v10; // edi
  int v11; // ebx
  int v12; // edi
  int v13; // ebx
  int v14; // edi
  int v15; // ebx
  int v16; // edi
  int v17; // ebx
  int v18; // edx
  int v19; // ebx
  int v20; // edx
  int v21; // ecx
  int v22; // edi
  int v23; // ebx
  int v24; // edx
  int v25; // [esp+8h] [ebp-20h]
  int v26; // [esp+Ch] [ebp-1Ch]

  v1 = *(_DWORD *)(a1 + 64);
  if ( v1 <= 127 )
  {
    if ( v1 < 0 )
      *(_DWORD *)(a1 + 64) = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 64) = 127;
  }
  v2 = *(_DWORD *)(a1 + 68);
  if ( v2 <= 127 )
  {
    if ( v2 < 0 )
      *(_DWORD *)(a1 + 68) = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 68) = 127;
  }
  v3 = *(_DWORD *)(a1 + 64);
  v4 = *(_DWORD *)(a1 + 68);
  v26 = v3;
  if ( v3 )
    v26 = v3 + 1;
  v5 = *(_DWORD *)(*(_DWORD *)a1 + 24);
  if ( v5 == 2 || v5 == 3 )
  {
    result = (int *)(a1 + 72);
    v7 = a1 + 1096;
    v8 = (uint8_t)byte_18A424[127 - v4];
    v9 = (uint8_t)byte_18A424[v4];
    v25 = v26 << 8;
    if ( (*(_BYTE *)(a1 + 56) & 1) != 0 )
    {
      v10 = 0;
      v11 = 0;
      do
      {
        *result = (v8 * (v11 >> 7)) >> 7;
        v7 += 4;
        ++result;
        *(_DWORD *)(v7 - 4) = (v9 * (v11 >> 7)) >> 7;
        v10 += 256;
        v11 += v25;
      }
      while ( v10 < 0x8000 );
      v12 = -32768;
      v13 = -32768 * v26;
      do
      {
        *result = (v8 * (v13 >> 7)) >> 7;
        v7 += 4;
        ++result;
        *(_DWORD *)(v7 - 4) = (v9 * (v13 >> 7)) >> 7;
        v12 += 256;
        v13 += v26 << 8;
      }
      while ( v12 < 0 );
    }
    else
    {
      v14 = -32768;
      v15 = -32768 * v26;
      do
      {
        *result = (v8 * (v15 >> 7)) >> 7;
        v7 += 4;
        ++result;
        *(_DWORD *)(v7 - 4) = (v9 * (v15 >> 7)) >> 7;
        v14 += 256;
        v15 += v25;
      }
      while ( v14 < 0x8000 );
    }
  }
  else
  {
    result = (int *)(a1 + 72);
    if ( (*(_BYTE *)(a1 + 56) & 1) != 0 )
    {
      v16 = 0;
      v17 = 0;
      do
      {
        ++result;
        v16 += 256;
        v18 = v17 >> 7;
        v17 += v26 << 8;
        *(result - 1) = v18;
      }
      while ( v16 < 0x8000 );
      v19 = -32768;
      v20 = -32768 * v26;
      do
      {
        ++result;
        v19 += 256;
        v21 = v20 >> 7;
        v20 += v26 << 8;
        *(result - 1) = v21;
      }
      while ( v19 < 0 );
    }
    else
    {
      v22 = -32768;
      v23 = -32768 * v26;
      do
      {
        ++result;
        v22 += 256;
        v24 = v23 >> 7;
        v23 += v26 << 8;
        *(result - 1) = v24;
      }
      while ( v22 < 0x8000 );
    }
  }
  return result;
}


//----- (00156680) --------------------------------------------------------
void __cdecl sub_156680(int a1)
{
  int v1; // edi
  int v2; // edi
  int v3; // eax
  _DWORD *v4; // eax
  int *v5; // edi
  int v6; // eax
  int v7; // [esp-10h] [ebp-1Ch]
  int v8; // [esp-4h] [ebp-10h]

  if ( !dword_18A4A4 )
  {
    dword_18A4A4 = 1;
    dword_1C95EC = a1;
    v1 = sub_13FBB5();
    dword_1C95F4 = v1;
    if ( *(_DWORD *)(dword_1C95EC + 84) )
    {
      v2 = **(int16_t **)(dword_1C95EC + 52);
      dword_1C95F0 = v2;
      if ( v2 != -1 && v2 != *(_DWORD *)(dword_1C95EC + 56) )
      {
        v8 = dword_1C95EC;
        *(_DWORD *)(dword_1C95EC + 56) = v2;
        sub_162293(v8);
        dword_1C95F8 = 0;
        v3 = *(_DWORD *)(dword_1C95EC + 92);
        dword_1C95E8 = *(_DWORD *)(dword_1C95EC + 96);
        for ( dword_1C95E4 = v3; dword_1C95E8; dword_1C95E4 += 2196 )
        {
          if ( *(_DWORD *)(dword_1C95E4 + 4) == 4 )
          {
            ++dword_1C95F8;
            sub_162000(dword_1C95E4);
          }
          --dword_1C95E8;
        }
        v4 = (_DWORD *)dword_1C95EC;
        *(_DWORD *)(dword_1C95EC + 100) = dword_1C95F8;
        sub_162201(v4, dword_1C95F0 ^ 1);
        if ( (*(_BYTE *)(dword_1C95EC + 28) & 0x10) != 0 )
        {
          v7 = *(_DWORD *)dword_1C95EC;
          word_1C95DC = 0;
          word_1C95DE = dword_1C95F0 ^ 1;
          sub_13FBC8(v7, 1029, word_1C95D8, 0);
        }
        v5 = (int *)dword_1C95EC;
        if ( *(_DWORD *)(dword_1C95EC + 100) )
        {
          *(_DWORD *)(dword_1C95EC + 88) = 0;
        }
        else
        {
          v6 = *(_DWORD *)(dword_1C95EC + 88);
          *(_DWORD *)(dword_1C95EC + 88) = v6 + 1;
          if ( v6 == 2 )
          {
            if ( v5[21] )
            {
              sub_13FBC8(*v5, 1026, 0, 0);
              v5[21] = 0;
            }
          }
        }
      }
      sub_13FBBA(dword_1C95F4);
      dword_18A4A4 = 0;
    }
    else
    {
      sub_13FBBA(v1);
      dword_18A4A4 = 0;
    }
  }
}
// 18A4A4: using guessed type int dword_18A4A4;
// 1C95D8: using guessed type _WORD word_1C95D8[2];
// 1C95DC: using guessed type int16_t word_1C95DC;
// 1C95DE: using guessed type int16_t word_1C95DE;
// 1C95E4: using guessed type int dword_1C95E4;
// 1C95E8: using guessed type int dword_1C95E8;
// 1C95EC: using guessed type int dword_1C95EC;
// 1C95F0: using guessed type int dword_1C95F0;
// 1C95F4: using guessed type int dword_1C95F4;
// 1C95F8: using guessed type int dword_1C95F8;


//----- (00156870) --------------------------------------------------------
int __usercall sub_156870(int a1, int a2)
{
  int v2; // ebx
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // ecx
  uint16_t v9; // ax
  int v10; // ebx
  int v11; // ebp
  int v12; // ebp
  int result; // eax
  signed int v14; // ebx
  int i; // ecx
  int v16; // ebx
  unsigned int v17; // eax
  _DWORD *v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // [esp+0h] [ebp-34h]
  int v24; // [esp+4h] [ebp-30h]
  int v25; // [esp+8h] [ebp-2Ch]
  int v26; // [esp+Ch] [ebp-28h]
  _WORD v27[6]; // [esp+10h] [ebp-24h] BYREF
  int v28; // [esp+1Ch] [ebp-18h]
  int v29; // [esp+20h] [ebp-14h]
  signed int v30; // [esp+24h] [ebp-10h]

  v28 = *(_DWORD *)(a2 + 84);
  if ( v28 )
  {
    v2 = 0;
    if ( *(int *)(a2 + 96) > 0 )
    {
      v3 = 0;
      do
      {
        *(_DWORD *)(*(_DWORD *)(a2 + 92) + v3 + 2192) = *(_DWORD *)(*(_DWORD *)(a2 + 92) + v3 + 4);
        v4 = v3 + *(_DWORD *)(a2 + 92);
        if ( *(_DWORD *)(v4 + 4) == 4 )
          *(_DWORD *)(v4 + 4) = 8;
        ++v2;
        v3 += 2196;
      }
      while ( v2 < *(_DWORD *)(a2 + 96) );
    }
    if ( *(_DWORD *)(a2 + 84) )
    {
      sub_13FBC8(*(_DWORD *)a2, 1026, 0, 0);
      *(_DWORD *)(a2 + 84) = 0;
    }
    sub_162293(a2);
    sub_162201((_DWORD *)a2, 0);
    sub_162201((_DWORD *)a2, 1);
  }
  switch ( dword_1C9560 | (2 * dword_1C955C) )
  {
    case 0:
      v23 = 0;
      v24 = 1;
      v25 = 2;
      v26 = 3;
      break;
    case 1:
      v23 = 1;
      v24 = 0;
      v25 = 3;
      v26 = 2;
      break;
    case 2:
      v23 = 2;
      v24 = 3;
      v25 = 0;
      v26 = 1;
      break;
    case 3:
      v23 = 3;
      v24 = 2;
      v25 = 1;
      v26 = 0;
      break;
    default:
      break;
  }
  v5 = 0;
  while ( 1 )
  {
    v6 = *(int *)((char *)&v23 + v5);
    if ( *(_BYTE *)(*(_DWORD *)(a2 + 4) + v6) )
      break;
    v5 += 4;
    if ( v5 >= 16 )
      goto LABEL_19;
  }
  *(_DWORD *)(a2 + 24) = v6;
LABEL_19:
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(*(_DWORD *)(a2 + 4) + 14 * *(_DWORD *)(a2 + 24) + 26);
  if ( dword_1C9544 )
  {
    if ( (unsigned int)dword_1C9544 <= 1 )
    {
      v7 = *(uint16_t *)(*(_DWORD *)(a2 + 4) + 14 * *(_DWORD *)(a2 + 24) + 18);
    }
    else if ( dword_1C9544 == 2 )
    {
      v7 = *(uint16_t *)(*(_DWORD *)(a2 + 4) + 14 * *(_DWORD *)(a2 + 24) + 20);
    }
    else
    {
      v23 = *(uint16_t *)(14 * *(_DWORD *)(a2 + 24) + *(_DWORD *)(a2 + 4) + 16);
      v24 = *(uint16_t *)(14 * *(_DWORD *)(a2 + 24) + *(_DWORD *)(a2 + 4) + 18);
      v8 = 0;
      v9 = *(_WORD *)(14 * *(_DWORD *)(a2 + 24) + *(_DWORD *)(a2 + 4) + 20);
      v30 = 0x7FFFFFFF;
      v25 = v9;
      v10 = 0;
      do
      {
        if ( (int)abs32(dword_1C9544 - *(int *)((char *)&v23 + v10)) <= v30 )
        {
          v30 = abs32(dword_1C9544 - *(int *)((char *)&v23 + v10));
          a1 = v8;
        }
        ++v8;
        v10 += 4;
      }
      while ( v8 < 3 );
      v7 = *(&v23 + a1);
    }
  }
  else
  {
    v7 = *(uint16_t *)(*(_DWORD *)(a2 + 4) + 14 * *(_DWORD *)(a2 + 24) + 16);
  }
  *(_DWORD *)(a2 + 20) = v7;
  switch ( *(_DWORD *)(a2 + 24) )
  {
    case 0:
      *(_DWORD *)(a2 + 60) = 1;
      *(_DWORD *)(a2 + 64) = 1;
      break;
    case 1:
      *(_DWORD *)(a2 + 60) = 1;
      goto LABEL_35;
    case 2:
      *(_DWORD *)(a2 + 60) = 2;
      *(_DWORD *)(a2 + 64) = 1;
      break;
    case 3:
      *(_DWORD *)(a2 + 60) = 2;
LABEL_35:
      *(_DWORD *)(a2 + 64) = 2;
      break;
    default:
      break;
  }
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(a2 + 60) * dword_1C954C * *(_DWORD *)(a2 + 20) / 1000 * *(_DWORD *)(a2 + 64);
  v11 = 14 * *(_DWORD *)(a2 + 24) + *(_DWORD *)(a2 + 4);
  v29 = *(uint16_t *)(v11 + 22);
  v12 = *(uint16_t *)(v11 + 24);
  if ( !dword_1C9584 )
    goto LABEL_41;
  if ( v12 > 2048 )
    v12 = 2048;
  if ( v29 > 2048 )
  {
    result = 0;
    strcpy(&byte_1C9440, "Minimum DMA buffer size too large for VDM\n");
  }
  else
  {
LABEL_41:
    v14 = 0x7FFFFFFF;
    for ( i = 8; i <= dword_1C9548 / 2; i *= 2 )
    {
      if ( (int)abs32(i - *(_DWORD *)(a2 + 16)) <= v14 )
      {
        a1 = i;
        v14 = abs32(i - *(_DWORD *)(a2 + 16));
      }
    }
    v16 = v29;
    *(_DWORD *)(a2 + 16) = a1;
    if ( a1 < v16 )
      *(_DWORD *)(a2 + 16) = v16;
    if ( v12 < *(_DWORD *)(a2 + 16) )
      *(_DWORD *)(a2 + 16) = v12;
    v17 = *(_DWORD *)(a2 + 32);
    if ( dword_1C9584 )
      v17 = (((v17 >> 12) + 4095) & 0xFF000) << 12;
    **(_DWORD **)(a2 + 8) = v17;
    *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4) = *(_DWORD *)(a2 + 16) + v17;
    v18 = *(_DWORD **)(a2 + 8);
    *(_DWORD *)(a2 + 44) = (uint16_t)*v18 + 16 * HIWORD(*v18);
    v19 = (uint16_t)v18[1] + 16 * HIWORD(v18[1]);
    v20 = v28;
    *(_DWORD *)(a2 + 48) = v19;
    if ( v20 )
    {
      v21 = 0;
      if ( *(int *)(a2 + 96) > 0 )
      {
        v22 = 0;
        do
        {
          *(_DWORD *)(*(_DWORD *)(a2 + 92) + v22 + 4) = *(_DWORD *)(*(_DWORD *)(a2 + 92) + v22 + 2192);
          ++v21;
          v22 += 2196;
        }
        while ( v21 < *(_DWORD *)(a2 + 96) );
      }
      sub_162293(a2);
      sub_162201((_DWORD *)a2, 0);
      sub_162201((_DWORD *)a2, 1);
      if ( !*(_DWORD *)(a2 + 84) )
      {
        v27[3] = *(_WORD *)(a2 + 24);
        v27[2] = *(_WORD *)(a2 + 20);
        sub_13FBC8(*(_DWORD *)a2, 1025, v27, 0);
        *(_DWORD *)(a2 + 84) = 1;
      }
    }
    return 1;
  }
  return result;
}
// 1C9440: using guessed type char byte_1C9440;
// 1C9544: using guessed type int dword_1C9544;
// 1C9548: using guessed type int dword_1C9548;
// 1C954C: using guessed type int dword_1C954C;
// 1C955C: using guessed type int dword_1C955C;
// 1C9560: using guessed type int dword_1C9560;
// 1C9584: using guessed type int dword_1C9584;


//----- (00156CF0) --------------------------------------------------------
int __cdecl sub_156CF0(int *a1, void *a2)
{
  int v2; // eax
  _WORD *v3; // ebx
  unsigned int i; // eax
  int v5; // ebx
  _DWORD v7[6]; // [esp+0h] [ebp-30h] BYREF
  _WORD v8[3]; // [esp+18h] [ebp-18h] BYREF
  int16_t v9; // [esp+1Eh] [ebp-12h]

  qmemcpy(v7, a2, sizeof(v7));
  v2 = *(_DWORD *)(*a1 + 12);
  if ( *(_WORD *)(v2 + 16) )
  {
    v3 = (_WORD *)((uint16_t)*(_DWORD *)(v2 + 12) + 16 * HIWORD(*(_DWORD *)(v2 + 12)));
    if ( SLOWORD(v7[0]) < 0 )
      LOWORD(v7[0]) = *v3;
    if ( v7[0] < 0 )
      HIWORD(v7[0]) = v3[1];
    if ( SLOWORD(v7[1]) < 0 )
      LOWORD(v7[1]) = v3[2];
    if ( v7[1] < 0 )
      HIWORD(v7[1]) = v3[3];
    for ( i = 0; i != 16; i += 4 )
    {
      if ( (int)v7[i / 4 + 2] < 0 )
        v7[i / 4 + 2] = *(_DWORD *)&v3[i / 2 + 4];
    }
  }
  v5 = dword_1C9564;
  qmemcpy((void *)(*(_DWORD *)(*a1 + 12) + 22), v7, 0x18u);
  if ( v5 )
    v9 = 3;
  else
    v9 = 1;
  return sub_13FBC8(*a1, 772, v8, 0);
}
// 1C9564: using guessed type int dword_1C9564;


//----- (00156DF0) --------------------------------------------------------
int __cdecl sub_156DF0(int *a1)
{
  if ( a1[21] )
  {
    sub_13FBC8(*a1, 1026, 0, 0);
    a1[21] = 0;
    sub_162293((int)a1);
    sub_162201(a1, 0);
    sub_162201(a1, 1);
    sub_13FCDE(10);
  }
  sub_140665(a1[3]);
  sub_1541D2(a1[10], a1[8], a1[9]);
  sub_1540EC(a1[23], 2196 * a1[24]);
  sub_1540EC(a1[20], a1[19]);
  return sub_1540EC((unsigned int)a1, 136);
}
// 156DFE: conditional instruction was optimized away because edx.4!=0


//----- (00156EA0) --------------------------------------------------------
int *__cdecl sub_156EA0(int a1, void *a2)
{
  int *result; // eax
  int *v3; // ebp
  int v4; // edx
  void *v5; // eax
  void *v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // edi
  int v10; // ecx
  int v11; // edi
  int v12; // edx
  unsigned int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  _BYTE v19[24]; // [esp+0h] [ebp-50h] BYREF
  _WORD v20[6]; // [esp+18h] [ebp-38h] BYREF
  int v21; // [esp+24h] [ebp-2Ch] BYREF
  unsigned int v22; // [esp+28h] [ebp-28h] BYREF
  int v23; // [esp+2Ch] [ebp-24h] BYREF
  int v24; // [esp+30h] [ebp-20h]
  void *v25; // [esp+34h] [ebp-1Ch]
  void *v26; // [esp+38h] [ebp-18h]
  int v27; // [esp+3Ch] [ebp-14h]
  int v28; // [esp+40h] [ebp-10h]

  sub_1562C0();
  result = (int *)sub_1540A6(136);
  v3 = result;
  if ( result )
  {
    *result = a1;
    if ( *(_DWORD *)(a1 + 16) )
    {
      strcpy(&byte_1C9440, ".DIG driver required\n");
      sub_1540EC((unsigned int)result, 136);
      return 0;
    }
    else
    {
      sub_13FBC8(a1, 769, 0, v20);
      v3[1] = v20[0] + 16 * v20[3];
      v4 = v20[1] + 16 * v20[2];
      v3[2] = v4;
      v3[14] = -1;
      v3[21] = 0;
      v3[22] = 0;
      v3[25] = 0;
      v3[13] = v4 + 8;
      v27 = 0;
      memset(&unk_1C9588, -1, 24);
      if ( a2 )
      {
        qmemcpy(&unk_1C9588, a2, 0x18u);
        if ( sub_156CF0(v3, a2) )
        {
          v27 = 1;
          qmemcpy(v19, a2, sizeof(v19));
        }
      }
      if ( !v27 )
      {
        sub_140734(*v3);
        v26 = v5;
        if ( v5 )
        {
          qmemcpy(&unk_1C9588, v5, 0x18u);
          if ( sub_156CF0(v3, v5) )
          {
            v27 = 1;
            qmemcpy(v19, v26, sizeof(v19));
          }
        }
      }
      if ( !v27 && dword_1C9580 == 1 )
      {
        v28 = v27;
        v24 = v27;
        while ( 1 )
        {
          v7 = *(_DWORD *)(*v3 + 12);
          if ( *(uint16_t *)(v7 + 16) <= v28 )
            break;
          v6 = (void *)(16 * HIWORD(*(_DWORD *)(v7 + 12)) + (uint16_t)*(_DWORD *)(v7 + 12) + v24);
          v25 = v6;
          if ( !v28 )
            qmemcpy(&unk_1C9588, v6, 0x18u);
          if ( sub_156CF0(v3, v25) )
          {
            v27 = 1;
            qmemcpy(v19, v25, sizeof(v19));
            break;
          }
          v24 += 24;
          ++v28;
        }
      }
      if ( v27 )
      {
        qmemcpy(&unk_1C9588, v19, 0x18u);
        if ( dword_1C9584 )
          v8 = 0x2000;
        else
          v8 = dword_1C9548;
        v3[10] = 0;
        v9 = (v8 + 15 - (__CFSHL__((v8 + 15) >> 31, 4) + 16 * ((v8 + 15) >> 31))) >> 4;
        do
        {
          if ( !sub_154124(v9, &v23, &v22, &v21) )
          {
            strcpy(&byte_1C9440, "Could not allocate DMA buffers\n");
            sub_1540EC((unsigned int)v3, 136);
            return 0;
          }
          v10 = v3[10];
          if ( v10 )
            sub_1541D2(v10, v3[8], v3[9]);
          v3[10] = v23;
          v3[8] = v22;
          v3[9] = v21;
        }
        while ( ((v22 >> 12) & 0xF0000) != ((v8 + (v22 >> 12) - 1) & 0xF0000) );
        if ( sub_156870(v9, (int)v3) )
        {
          sub_13FBC8(*v3, 773, 0, 0);
          *(_DWORD *)(*v3 + 20) = 1;
          v11 = v3[16];
          v12 = v3[4];
          v3[18] = v12 / (v11 * v3[15]);
          v3[17] = v12 / v11;
          v3[19] = 4 * (v12 / v11);
          v13 = sub_1540A6(4 * (v12 / v11));
          v3[20] = v13;
          if ( v13 )
          {
            v14 = dword_1C9550;
            v3[24] = dword_1C9550;
            v15 = sub_1540A6(2196 * v14);
            v3[23] = v15;
            if ( v15 )
            {
              v16 = 0;
              if ( v3[24] > 0 )
              {
                v17 = 0;
                do
                {
                  *(_DWORD *)(v3[23] + v17 + 4) = 1;
                  *(_DWORD *)(v3[23] + v17) = v3;
                  ++v16;
                  v17 += 2196;
                }
                while ( v16 < v3[24] );
              }
              sub_1400A9((int)sub_156680);
              v3[3] = v18;
              if ( v18 == -1 )
              {
                strcpy(&byte_1C9440, "Out of timer handles\n");
                if ( *(_DWORD *)(a1 + 24) != -1 )
                  sub_13FB41(*(_DWORD *)(a1 + 24));
                sub_13FBC8(*v3, 774, 0, 0);
                *(_DWORD *)(*v3 + 20) = 0;
                sub_1541D2(v3[10], v3[8], v3[9]);
                sub_1540EC(v3[23], 2196 * v3[24]);
                sub_1540EC(v3[20], v3[19]);
                sub_1540EC((unsigned int)v3, 136);
                return 0;
              }
              else
              {
                sub_140194(v18, (int32_t)v3);
                sub_1402FD(v3[3], dword_1C9540[0]);
                sub_1404C7(v3[3]);
                *(_DWORD *)(*v3 + 32) = sub_156DF0;
                *(_DWORD *)(*v3 + 36) = v3;
                sub_162293((int)v3);
                sub_162201(v3, 0);
                sub_162201(v3, 1);
                return v3;
              }
            }
            else
            {
              strcpy(&byte_1C9440, "Could not allocate SAMPLE structures\n");
              if ( *(_DWORD *)(a1 + 24) != -1 )
                sub_13FB41(*(_DWORD *)(a1 + 24));
              sub_13FBC8(*v3, 774, 0, 0);
              *(_DWORD *)(*v3 + 20) = 0;
              sub_1541D2(v3[10], v3[8], v3[9]);
              sub_1540EC(v3[20], v3[19]);
              sub_1540EC((unsigned int)v3, 136);
              return 0;
            }
          }
          else
          {
            strcpy(&byte_1C9440, "Could not allocate build buffer\n");
            if ( *(_DWORD *)(a1 + 24) != -1 )
              sub_13FB41(*(_DWORD *)(a1 + 24));
            sub_13FBC8(*v3, 774, 0, 0);
            *(_DWORD *)(*v3 + 20) = 0;
            sub_1541D2(v3[10], v3[8], v3[9]);
            sub_1540EC((unsigned int)v3, 136);
            return 0;
          }
        }
        else
        {
          sub_1541D2(v3[10], v3[8], v3[9]);
          sub_1540EC((unsigned int)v3, 136);
          return 0;
        }
      }
      else
      {
        strcpy(&byte_1C9440, "Digital sound hardware not found\n");
        sub_1540EC((unsigned int)v3, 136);
        return 0;
      }
    }
  }
  else
  {
    strcpy(&byte_1C9440, "Could not allocate memory for driver\n");
  }
  return result;
}
// 156FE3: variable 'v5' is possibly undefined
// 1573AB: variable 'v18' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1C9440: using guessed type char byte_1C9440;
// 1C9540: using guessed type int dword_1C9540[];
// 1C9548: using guessed type int dword_1C9548;
// 1C9550: using guessed type int dword_1C9550;
// 1C9580: using guessed type int dword_1C9580;
// 1C9584: using guessed type int dword_1C9584;


//----- (001574B0) --------------------------------------------------------
int __cdecl sub_1574B0(int a1, void *a2)
{
  int result; // eax
  int v3; // esi
  int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edi
  int *v7; // esi

  result = sub_154B18(a1, 0);
  v3 = result;
  if ( result )
  {
    v4 = sub_154A9A(a1);
    sub_140819(v3, v4);
    v6 = v5;
    off_189868(v3);
    if ( v6 )
    {
      v7 = sub_156EA0(v6, a2);
      if ( !v7 )
        sub_14090C(v6);
      return (int)v7;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    strcpy(&byte_1C9440, "Driver file not found\n");
  }
  return result;
}
// 1574F1: variable 'v5' is possibly undefined
// 189868: using guessed type int (__fastcall *off_189868)(_DWORD);
// 1C9440: using guessed type char byte_1C9440;


//----- (00157530) --------------------------------------------------------
void __cdecl sub_157530(int a1, int a2, void *a3)
{
  int v3; // eax
  unsigned int v4; // esi

  sub_140819(a1, a2);
  v4 = v3;
  if ( v3 )
  {
    if ( !sub_156EA0(v3, a3) )
      sub_14090C(v4);
  }
}
// 157541: variable 'v3' is possibly undefined


//----- (00157570) --------------------------------------------------------
void sub_157570()
{
  _BYTE v0[128]; // [esp+0h] [ebp-120h] BYREF
  char v1[128]; // [esp+80h] [ebp-A0h] BYREF
  _BYTE v2[32]; // [esp+100h] [ebp-20h] BYREF

  if ( sub_13FD50((int)v0, &aWdigIni[1]) )
    sub_140A57(v1, v2);
  else
    strcpy(&byte_1C9440, "Unable to open file DIG.INI\n");
}
// 1C9440: using guessed type char byte_1C9440;


//----- (001575D0) --------------------------------------------------------
void __cdecl sub_1575D0(unsigned int *a1)
{
  sub_14090C(*a1);
}


//----- (001575E0) --------------------------------------------------------
int __cdecl sub_1575E0(int a1)
{
  int v1; // ebx
  int v2; // eax
  int v3; // edx

  v1 = 0;
  v2 = 0;
  if ( *(int *)(a1 + 96) > 0 )
  {
    v3 = *(_DWORD *)(a1 + 92);
    do
    {
      if ( *(_DWORD *)(v3 + 4) == 4 )
        ++v1;
      ++v2;
      v3 += 2196;
    }
    while ( v2 < *(_DWORD *)(a1 + 96) );
  }
  return v1;
}


//----- (00157610) --------------------------------------------------------
int *__cdecl sub_157610(int a1)
{
  int v1; // eax
  int v2; // edx
  int *v4; // esi

  sub_13F949();
  v1 = 0;
  if ( *(int *)(a1 + 96) > 0 )
  {
    v2 = *(_DWORD *)(a1 + 92);
    do
    {
      if ( *(_DWORD *)(v2 + 4) == 1 )
        break;
      ++v1;
      v2 += 2196;
    }
    while ( v1 < *(_DWORD *)(a1 + 96) );
  }
  if ( v1 == *(_DWORD *)(a1 + 96) )
  {
    strcpy(&byte_1C9440, "Out of sample handles\n");
    sub_13F94E();
    return 0;
  }
  else
  {
    v4 = (int *)(2196 * v1 + *(_DWORD *)(a1 + 92));
    sub_140DFC(v4);
    sub_13F94E();
    return v4;
  }
}
// 1C9440: using guessed type char byte_1C9440;


//----- (00157680) --------------------------------------------------------
int __cdecl sub_157680(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
    *(_DWORD *)(a1 + 4) = 1;
  return result;
}


//----- (00157690) --------------------------------------------------------
int *__cdecl sub_157690(int *a1)
{
  int *result; // eax
  int v2; // edx

  result = a1;
  if ( a1 )
  {
    a1[1] = 2;
    a1[2] = 0;
    a1[4] = 0;
    a1[6] = 0;
    a1[8] = 0;
    a1[3] = 0;
    a1[5] = 0;
    a1[7] = 0;
    a1[9] = 1;
    a1[10] = 0;
    a1[11] = -2;
    a1[12] = 1;
    a1[13] = 0;
    a1[14] = 0;
    a1[15] = 11025;
    a1[17] = 64;
    a1[530] = 0;
    a1[531] = 0;
    v2 = dword_1C9554;
    a1[532] = 0;
    a1[16] = v2;
    return sub_156400((int)a1);
  }
  return result;
}
// 1C9554: using guessed type int dword_1C9554;


//----- (00157740) --------------------------------------------------------
int __cdecl sub_157740(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
    return *(_DWORD *)(a1 + 4);
  return result;
}


//----- (00157750) --------------------------------------------------------
_DWORD *__cdecl sub_157750(_DWORD *a1, int a2, int a3)
{
  _DWORD *result; // eax

  result = a1;
  if ( a1 )
  {
    a1[3] = 0;
    a1[5] = 0;
    a1[2] = a2;
    a1[4] = a3;
  }
  return result;
}


//----- (00157780) --------------------------------------------------------
int *__cdecl sub_157780(int a1, int a2, int a3)
{
  int *result; // eax

  result = (int *)a1;
  if ( a1 && (a2 != *(_DWORD *)(a1 + 52) || a3 != *(_DWORD *)(a1 + 56)) )
  {
    *(_DWORD *)(a1 + 52) = a2;
    *(_DWORD *)(a1 + 56) = a3;
    return sub_156400(a1);
  }
  return result;
}


//----- (001577B0) --------------------------------------------------------
int __cdecl sub_1577B0(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
    return *(_DWORD *)(a1 + 60);
  return result;
}


//----- (001577C0) --------------------------------------------------------
int __cdecl sub_1577C0(int a1, int a2)
{
  int result; // eax

  result = a1;
  if ( a1 )
    *(_DWORD *)(a1 + 60) = a2;
  return result;
}


//----- (001577D0) --------------------------------------------------------
int __cdecl sub_1577D0(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
    return *(_DWORD *)(a1 + 64);
  return result;
}


//----- (001577E0) --------------------------------------------------------
int *__cdecl sub_1577E0(int a1, int a2)
{
  int *result; // eax

  result = (int *)a1;
  if ( a1 )
  {
    if ( a2 != *(_DWORD *)(a1 + 64) )
    {
      *(_DWORD *)(a1 + 64) = a2;
      return sub_156400(a1);
    }
  }
  return result;
}


//----- (00157800) --------------------------------------------------------
int __cdecl sub_157800(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
    return *(_DWORD *)(a1 + 68);
  return result;
}


//----- (00157810) --------------------------------------------------------
int *__cdecl sub_157810(int a1, int a2)
{
  int *result; // eax

  result = (int *)a1;
  if ( a1 )
  {
    if ( a2 != *(_DWORD *)(a1 + 68) )
    {
      *(_DWORD *)(a1 + 68) = a2;
      return sub_156400(a1);
    }
  }
  return result;
}


//----- (00157830) --------------------------------------------------------
int __cdecl sub_157830(int a1)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 4 * *(_DWORD *)(a1 + 40) + 24);
  else
    return 0;
}


//----- (00157850) --------------------------------------------------------
int __cdecl sub_157850(int a1, int a2)
{
  int result; // eax

  if ( a1 )
  {
    result = a1 + 4 * *(_DWORD *)(a1 + 40);
    *(_DWORD *)(result + 24) = a2;
  }
  return result;
}


//----- (00157870) --------------------------------------------------------
int __cdecl sub_157870(int a1)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 48);
  else
    return -1;
}


//----- (00157890) --------------------------------------------------------
int __cdecl sub_157890(int a1, int a2)
{
  int result; // eax

  result = a1;
  if ( a1 )
    *(_DWORD *)(a1 + 48) = a2;
  return result;
}


//----- (001578A0) --------------------------------------------------------
void __cdecl sub_1578A0(_DWORD *a1)
{
  _DWORD *v1; // eax
  int v2; // esi
  _WORD v3[12]; // [esp+0h] [ebp-18h] BYREF

  if ( a1 )
  {
    if ( a1[1] != 1 )
    {
      v1 = &a1[a1[10]];
      if ( v1[4] )
      {
        if ( v1[2] )
        {
          v1[6] = 0;
          a1[1] = 4;
          v2 = *a1;
          if ( !*(_DWORD *)(*a1 + 84) )
          {
            v3[3] = *(_WORD *)(v2 + 24);
            v3[2] = *(_WORD *)(v2 + 20);
            sub_13FBC8(*(_DWORD *)v2, 1025, v3, 0);
            *(_DWORD *)(v2 + 84) = 1;
          }
        }
      }
    }
  }
}


//----- (00157920) --------------------------------------------------------
int __cdecl sub_157920(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 4) == 4 )
      *(_DWORD *)(a1 + 4) = 8;
  }
  return result;
}


//----- (00157940) --------------------------------------------------------
int __cdecl sub_157940(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 4) == 8 )
      *(_DWORD *)(a1 + 4) = 4;
  }
  return result;
}


//----- (00157960) --------------------------------------------------------
int __cdecl sub_157960(int a1)
{
  int v1; // edx
  int v2; // ecx
  int result; // eax

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 4);
    if ( v1 != 1 && v1 != 2 )
    {
      v2 = *(_DWORD *)(a1 + 2124);
      *(_DWORD *)(a1 + 4) = 2;
      if ( v2 )
        result = (*(int (__cdecl **)(int))(a1 + 2124))(a1);
      if ( *(_DWORD *)(a1 + 2128) )
        return (*(int (__cdecl **)(int))(a1 + 2128))(a1);
    }
  }
  return result;
}


//----- (001579B0) --------------------------------------------------------
int __cdecl sub_1579B0(int a1, int a2)
{
  int result; // eax
  int v3; // edx

  result = a1;
  if ( a1 )
  {
    v3 = *(_DWORD *)(a1 + 2120);
    *(_DWORD *)(a1 + 2120) = a2;
    return v3;
  }
  return result;
}


//----- (001579D0) --------------------------------------------------------
int __cdecl sub_1579D0(int a1, int a2)
{
  int result; // eax
  int v3; // edx

  result = a1;
  if ( a1 )
  {
    v3 = *(_DWORD *)(a1 + 2124);
    *(_DWORD *)(a1 + 2124) = a2;
    return v3;
  }
  return result;
}


//----- (001579F0) --------------------------------------------------------
int __cdecl sub_1579F0(int a1, int a2)
{
  int result; // eax
  int v3; // edx

  result = a1;
  if ( a1 )
  {
    v3 = *(_DWORD *)(a1 + 2128);
    *(_DWORD *)(a1 + 2128) = a2;
    return v3;
  }
  return result;
}


//----- (00157A10) --------------------------------------------------------
int __cdecl sub_157A10(int a1, int a2, int a3)
{
  int result; // eax

  if ( a1 )
  {
    result = a1 + 4 * a2;
    *(_DWORD *)(result + 2132) = a3;
  }
  return result;
}


//----- (00157A30) --------------------------------------------------------
int __cdecl sub_157A30(int a1, int a2)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 4 * a2 + 2132);
  else
    return 0;
}


//----- (00157A60) --------------------------------------------------------
int __usercall sub_157A60(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // ebx
  int v5; // edi
  int v6; // ebx
  int v7; // ebx

  switch ( a4 )
  {
    case 0:
      a1 = 1;
      break;
    case 1:
    case 2:
      a1 = 2;
      break;
    case 3:
      a1 = 4;
      break;
    default:
      break;
  }
  v4 = a3 * (a2[4] * a1 / (a2[16] * a2[15])) / a2[5];
  v5 = a2[5];
  v6 = ((v4 * dword_1C9558 - (__CFSHL__((v4 * dword_1C9558) >> 31, 15) + ((v4 * dword_1C9558) >> 31 << 15))) >> 15) + v4;
  if ( a3 != v5 && 2 * a3 != v5 && 4 * a3 != v5 )
    v6 += 4;
  v7 = v6 + 255;
  LOBYTE(v7) = 0;
  return v7;
}
// 1C9558: using guessed type int dword_1C9558;


//----- (00157B00) --------------------------------------------------------
int __cdecl sub_157B00(int *a1, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // esi
  _WORD v6[8]; // [esp+0h] [ebp-10h] BYREF

  result = (int)a1;
  if ( a1 )
  {
    a1[a2 + 6] = 0;
    a1[a2 + 8] = a4 == 0;
    a1[a2 + 4] = a4;
    a1[a2 + 2] = a3;
    if ( a4 )
    {
      if ( a1[1] != 4 )
      {
        v5 = *a1;
        a1[1] = 4;
        if ( !*(_DWORD *)(v5 + 84) )
        {
          v6[3] = *(_WORD *)(v5 + 24);
          v6[2] = *(_WORD *)(v5 + 20);
          result = sub_13FBC8(*(_DWORD *)v5, 1025, v6, 0);
          *(_DWORD *)(v5 + 84) = 1;
        }
      }
    }
  }
  return result;
}


//----- (00157B90) --------------------------------------------------------
char __cdecl sub_157B90(_DWORD *a1)
{
  unsigned int v2; // edx
  int v3; // ebx

  if ( !a1 )
    return -1;
  v2 = a1[11];
  if ( v2 < 0xFFFFFFFE )
  {
    v3 = a1[10];
    if ( a1[11] == v3 )
    {
      return -1;
    }
    else
    {
      a1[11] = v3;
      return v3 ^ 1;
    }
  }
  else if ( v2 == -1 )
  {
    a1[11] = a1[10];
    return 1;
  }
  else
  {
    a1[9] = 0;
    a1[11] = -1;
    return 0;
  }
}


//----- (00157BF0) --------------------------------------------------------
bool sub_157BF0()
{
  bool result; // eax

  if ( dword_18A4A8 )
  {
    sub_1542DF((unsigned int)sub_1562C0, (unsigned int)sub_157BF0);
    sub_1543D5((unsigned int)byte_18A424, 128);
    sub_1543D5((unsigned int)&dword_18A4A4, 4);
    sub_1543D5((unsigned int)&dword_1C95EC, 4);
    sub_1543D5((unsigned int)&unk_1C95D8, 12);
    sub_1543D5((unsigned int)&dword_1C95F4, 4);
    sub_1543D5((unsigned int)&dword_1C95F8, 4);
    sub_1543D5((unsigned int)&dword_1C95E8, 4);
    sub_1543D5((unsigned int)&dword_1C95F0, 4);
    result = sub_1543D5((unsigned int)&dword_1C95E4, 4);
    dword_18A4A8 = 0;
  }
  return result;
}
// 1562C0: using guessed type int sub_1562C0();
// 18A4A4: using guessed type int dword_18A4A4;
// 18A4A8: using guessed type int dword_18A4A8;
// 1C95E4: using guessed type int dword_1C95E4;
// 1C95E8: using guessed type int dword_1C95E8;
// 1C95EC: using guessed type int dword_1C95EC;
// 1C95F0: using guessed type int dword_1C95F0;
// 1C95F4: using guessed type int dword_1C95F4;
// 1C95F8: using guessed type int dword_1C95F8;


//----- (00157CA8) --------------------------------------------------------
bool sub_157CA8()
{
  bool result; // eax

  if ( !dword_18A4AC )
  {
    result = sub_15421D((unsigned int)sub_157CA8, (unsigned int)sub_1582C2);
    dword_18A4AC = 1;
  }
  return result;
}
// 18A4AC: using guessed type int dword_18A4AC;


//----- (00157CD4) --------------------------------------------------------
int __cdecl sub_157CD4(_DWORD *a1)
{
  return *a1 >> 8;
}


//----- (00157CDE) --------------------------------------------------------
void __cdecl sub_157CDE(int a1)
{
  if ( *(_DWORD *)(a1 + 2164) )
    (*(void (__cdecl **)(int))(a1 + 2164))(a1);
  if ( *(int *)(a1 + 2188) > 0 )
    sub_140D8F(a1);
  *(_DWORD *)(a1 + 2188) = -1;
}


//----- (00157D3C) --------------------------------------------------------
void __cdecl sub_157D3C(_DWORD *a1, int a2)
{
  int v2; // ebp
  int v3; // edi
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  unsigned int v7; // ebp
  uint64_t v8; // rax
  int v9; // eax
  int v10; // eax

  v2 = 0;
  while ( !v2 )
  {
    v3 = a1[542];
    switch ( *(_BYTE *)v3 )
    {
      case 0:
        sub_157CDE((int)a1);
        return;
      case 1:
        if ( !a1[546] )
          goto LABEL_39;
        v4 = sub_157CD4((_DWORD *)a1[542]);
        sub_140F6F(a1, v3 + 6, v4 - 2);
        sub_141227((int)a1, 1000000u / (256 - (unsigned int)*(uint8_t *)(v3 + 4))); // vlna 12: "&loc_F4240" = 1e6
        sub_140FF1((int)a1, 0, 0);
        goto LABEL_8;
      case 4:
        v5 = a1[545];
        if ( v5 != -1 )
          a1[546] = *(int16_t *)(v3 + 4) == v5;
        goto LABEL_39;
      case 6:
        a1[543] = v3;
        a1[544] = *(uint16_t *)(v3 + 4);
        goto LABEL_39;
      case 7:
        v6 = a1[544];
        if ( v6 == 0xFFFF || (a1[544] = v6 - 1, v6) )
          v3 = a1[543];
        goto LABEL_39;
      case 8:
        if ( !a1[546] )
          goto LABEL_39;
        if ( *(_BYTE *)(v3 + 7) )
        {
          sub_140FF1((int)a1, 2, 0);
          v7 = (unsigned int)sub_10000 - *(uint16_t *)(v3 + 4);
          v8 = 128000000;
        }
        else
        {
          sub_140FF1((int)a1, 0, 0);
          v7 = (unsigned int)sub_10000 - *(uint16_t *)(v3 + 4);
          v8 = 256000000;
        }
        sub_141227((int)a1, v8 / v7);
        v3 += sub_157CD4((_DWORD *)v3) + 4;
        v9 = sub_157CD4((_DWORD *)v3);
        sub_140F6F(a1, v3 + 6, v9 - 2);
LABEL_8:
        if ( a2 )
          goto LABEL_37;
        goto LABEL_38;
      case 9:
        if ( !a1[546] )
          goto LABEL_39;
        v10 = sub_157CD4((_DWORD *)a1[542]);
        sub_140F6F(a1, v3 + 16, v10 - 12);
        sub_141227((int)a1, *(_DWORD *)(v3 + 4));
        if ( *(_BYTE *)(v3 + 9) != 1 || *(_WORD *)(v3 + 10) )
        {
          if ( *(_BYTE *)(v3 + 9) != 2 || *(_WORD *)(v3 + 10) )
          {
            if ( *(_BYTE *)(v3 + 9) == 1 && *(_WORD *)(v3 + 10) == 4 )
            {
              sub_140FF1((int)a1, 1, 1);
            }
            else if ( *(_BYTE *)(v3 + 9) == 2 && *(_WORD *)(v3 + 10) == 4 )
            {
              sub_140FF1((int)a1, 3, 1);
            }
          }
          else
          {
            sub_140FF1((int)a1, 2, 0);
          }
        }
        else
        {
          sub_140FF1((int)a1, 0, 0);
        }
        if ( a2 )
LABEL_37:
          sub_141073(a1);
LABEL_38:
        v2 = 1;
LABEL_39:
        a1[542] = v3 + sub_157CD4((_DWORD *)v3) + 4;
        break;
      default:
        goto LABEL_39;
    }
  }
}
// 10000: using guessed type void __noreturn sub_10000();


//----- (00157FA9) --------------------------------------------------------
void __cdecl sub_157FA9(_DWORD *a1)
{
  sub_157D3C(a1, 1);
}


//----- (00157FB9) --------------------------------------------------------
_DWORD *__cdecl sub_157FB9(int a1, _DWORD *a2)
{
  int i; // esi
  int j; // esi

  for ( i = a1 + 12; strnicmp(i, aFmt, 4); i += *(_DWORD *)(i + 4) + 8 + (*(_DWORD *)(i + 4) & 1) )
    ;
  if ( *(_WORD *)(i + 10) == 1 && *(_WORD *)(i + 22) == 8 )
  {
    sub_140FF1((int)a2, 0, 0);
  }
  else if ( *(_WORD *)(i + 10) == 2 && *(_WORD *)(i + 22) == 8 )
  {
    sub_140FF1((int)a2, 2, 0);
  }
  else if ( *(_WORD *)(i + 10) == 1 && *(_WORD *)(i + 22) == 16 )
  {
    sub_140FF1((int)a2, 1, 1);
  }
  else if ( *(_WORD *)(i + 10) == 2 && *(_WORD *)(i + 22) == 16 )
  {
    sub_140FF1((int)a2, 3, 1);
  }
  sub_141227((int)a2, *(_DWORD *)(i + 12));
  for ( j = a1 + 12; strnicmp(j, aData, 4); j += *(_DWORD *)(j + 4) + 8 + (*(_DWORD *)(j + 4) & 1) )
    ;
  return sub_140F6F(a2, j + 8, *(_DWORD *)(j + 4));
}
// 16023E: using guessed type int __fastcall strnicmp(_DWORD, _DWORD, _DWORD);


//----- (001580A3) --------------------------------------------------------
void __cdecl sub_1580A3(int a1, int a2, int a3)
{
  int v3; // ebp
  int *v4; // eax
  int *v5; // esi
  int *v6; // edi

  sub_157CA8();
  if ( !strnicmp(a2, aCreative, 8) )
  {
    v3 = 0;
  }
  else
  {
    if ( strnicmp(a2 + 8, aWave, 4) )
    {
      strcpy(&byte_1C9440, "Unrecognized digital audio file type\n");
      return;
    }
    v3 = 1;
  }
  sub_140BB1(a1);
  v5 = v4;
  v6 = v4;
  if ( v4 )
  {
    sub_140DFC(v4);
    v5[541] = 0;
    if ( v3 )
    {
      v5[547] = 1;
      sub_141F1F((int)v5, (int)sub_157CDE);
      sub_157FB9(a2, v5);
    }
    else
    {
      v5[542] = *(uint16_t *)(a2 + 20) + a2;
      v5[545] = a3;
      v5[546] = a3 == -1;
      v5[547] = 1;
      sub_141F1F((int)v5, (int)sub_157FA9);
      sub_157D3C(v5, 0);
    }
    if ( v6[547] == -1 )
      strcpy(&byte_1C9440, "Invalid or missing data block\n");
  }
}
// 158131: conditional instruction was optimized away because ebp.4==1
// 158108: variable 'v4' is possibly undefined
// 16023E: using guessed type int __fastcall strnicmp(_DWORD, _DWORD, _DWORD);
// 1C9440: using guessed type char byte_1C9440;


//----- (001581CE) --------------------------------------------------------
int __cdecl sub_1581CE(_DWORD *a1, int a2, int a3)
{
  int v3; // eax

  v3 = strnicmp(a2, aCreative, 8);
  if ( v3 )
  {
    if ( strnicmp(a2 + 8, aWave, 4) )
    {
      strcpy(&byte_1C9440, "Unrecognized digital audio file type\n");
      return 0;
    }
    v3 = 1;
  }
  if ( v3 )
  {
    a1[547] = 0;
    sub_157FB9(a2, a1);
  }
  else
  {
    a1[542] = *(uint16_t *)(a2 + 20) + a2;
    a1[545] = a3;
    a1[546] = a3 == -1;
    a1[547] = 0;
    sub_157D3C(a1, 0);
  }
  if ( a1[547] == -1 )
  {
    strcpy(&byte_1C9440, "Invalid or missing data block\n");
    return 0;
  }
  return 1;
}
// 158227: conditional instruction was optimized away because eax.4==1
// 16023E: using guessed type int __fastcall strnicmp(_DWORD, _DWORD, _DWORD);
// 1C9440: using guessed type char byte_1C9440;


//----- (001582A6) --------------------------------------------------------
int __cdecl sub_1582A6(int a1, int a2)
{
  int result; // eax
  int v3; // edx

  result = a1;
  if ( a1 )
  {
    v3 = *(_DWORD *)(a1 + 2164);
    *(_DWORD *)(a1 + 2164) = a2;
    return v3;
  }
  return result;
}


//----- (001582C2) --------------------------------------------------------
bool sub_1582C2()
{
  bool result; // eax

  if ( dword_18A4AC )
  {
    result = sub_1542DF((unsigned int)sub_157CA8, (unsigned int)sub_1582C2);
    dword_18A4AC = 0;
  }
  return result;
}
// 157CA8: using guessed type int sub_157CA8();
// 18A4AC: using guessed type int dword_18A4AC;


//----- (001582F0) --------------------------------------------------------
bool sub_1582F0()
{
  bool result; // eax

  if ( !dword_18A534 )
  {
    sub_15421D((unsigned int)sub_1582F0, (unsigned int)sub_15B520);
    sub_1543A1((unsigned int)aSample, 128);
    sub_1543A1((unsigned int)&dword_18A530, 4);
    sub_1543A1((unsigned int)&dword_1C9604, 4);
    sub_1543A1((unsigned int)&dword_1C9608, 4);
    sub_1543A1((unsigned int)&dword_1C960C, 4);
    sub_1543A1((unsigned int)&dword_1C961C, 4);
    sub_1543A1((unsigned int)&dword_1C9610, 4);
    sub_1543A1((unsigned int)&dword_1C9614, 4);
    sub_1543A1((unsigned int)&dword_1C9600, 4);
    sub_1543A1((unsigned int)&dword_1C9618, 4);
    sub_1543A1((unsigned int)&dword_1C9624, 4);
    sub_1543A1((unsigned int)&dword_1C9620, 4);
    result = sub_1543A1((unsigned int)&dword_1C95FC, 4);
    dword_18A534 = 1;
  }
  return result;
}
// 18A530: using guessed type int dword_18A530;
// 18A534: using guessed type int dword_18A534;
// 1C95FC: using guessed type int dword_1C95FC;
// 1C9600: using guessed type int dword_1C9600;
// 1C9604: using guessed type int dword_1C9604;
// 1C9608: using guessed type int dword_1C9608;
// 1C960C: using guessed type int dword_1C960C;
// 1C9610: using guessed type int dword_1C9610;
// 1C9614: using guessed type int dword_1C9614;
// 1C9618: using guessed type int dword_1C9618;
// 1C961C: using guessed type int dword_1C961C;
// 1C9620: using guessed type int dword_1C9620;
// 1C9624: using guessed type int dword_1C9624;


//----- (00158450) --------------------------------------------------------
int __cdecl sub_158450(int a1)
{
  int result; // eax
  _WORD v2[8]; // [esp+0h] [ebp-10h] BYREF

  if ( *(int *)(a1 + 424) > 0 )
  {
    v2[2] = *(_WORD *)(a1 + 424);
    result = sub_13FBC8(*(_DWORD *)a1, 1282, v2, 0);
    *(_DWORD *)(a1 + 424) = 0;
    *(_DWORD *)(a1 + 428) = 0;
  }
  return result;
}


//----- (001584A0) --------------------------------------------------------
int __cdecl sub_1584A0(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int result; // eax
  int v10; // edx
  int v11; // edx
  _WORD v12[10]; // [esp+0h] [ebp-14h] BYREF

  v4 = a2 & 0xF0;
  if ( v4 < 0xB0 )
  {
    if ( v4 < 0x90 )
    {
      if ( v4 != 128 )
      {
LABEL_16:
        v5 = 0;
        goto LABEL_17;
      }
    }
    else if ( v4 > 0x90 && v4 != 160 )
    {
      goto LABEL_16;
    }
    goto LABEL_14;
  }
  if ( v4 > 0xB0 )
  {
    if ( v4 < 0xD0 )
    {
      if ( v4 != 192 )
        goto LABEL_16;
    }
    else if ( v4 > 0xD0 )
    {
      if ( v4 != 224 )
        goto LABEL_16;
      goto LABEL_14;
    }
    v5 = 2;
    goto LABEL_17;
  }
LABEL_14:
  v5 = 3;
LABEL_17:
  v6 = v5;
  if ( (unsigned int)(*(_DWORD *)(a1 + 428) + v5) > 0x200 && *(int *)(a1 + 424) > 0 )
  {
    v12[2] = *(_WORD *)(a1 + 424);
    sub_13FBC8(*(_DWORD *)a1, 1282, v12, 0);
    *(_DWORD *)(a1 + 424) = 0;
    *(_DWORD *)(a1 + 428) = 0;
  }
  v7 = *(_DWORD *)(a1 + 428);
  v8 = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(a1 + 428) = v7 + 1;
  *(_BYTE *)(v8 + v7 + 256) = a2;
  result = *(_DWORD *)(a1 + 428);
  v10 = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(a1 + 428) = result + 1;
  *(_BYTE *)(v10 + result + 256) = a3;
  if ( v6 == 3 )
  {
    result = *(_DWORD *)(a1 + 428);
    v11 = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(a1 + 428) = result + 1;
    *(_BYTE *)(v11 + result + 256) = a4;
  }
  ++*(_DWORD *)(a1 + 424);
  return result;
}


//----- (001585C0) --------------------------------------------------------
int __cdecl sub_1585C0(int a1, int a2, unsigned int a3)
{
  int v3; // ebx
  int result; // eax
  int v5; // edi
  _WORD v6[6]; // [esp+0h] [ebp-20h] BYREF
  _WORD v7[10]; // [esp+Ch] [ebp-14h] BYREF

  if ( *(int *)(a1 + 424) > 0 )
  {
    v7[2] = *(_WORD *)(a1 + 424);
    sub_13FBC8(*(_DWORD *)a1, 1282, v7, 0);
    *(_DWORD *)(a1 + 424) = 0;
    *(_DWORD *)(a1 + 428) = 0;
  }
  if ( a3 <= 0x200 )
    v3 = a3;
  else
    v3 = 512;
  result = memmove(*(_DWORD *)(a1 + 8) + 256, a2, v3);
  v5 = *(_DWORD *)(a1 + 424) + 1;
  *(_DWORD *)(a1 + 424) = v5;
  if ( v5 > 0 )
  {
    v6[2] = *(_WORD *)(a1 + 424);
    result = sub_13FBC8(*(_DWORD *)a1, 1282, v6, 0);
    *(_DWORD *)(a1 + 424) = 0;
    *(_DWORD *)(a1 + 428) = 0;
  }
  return result;
}
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);


//----- (00158680) --------------------------------------------------------
int __cdecl sub_158680(_DWORD *a1)
{
  int v1; // eax
  int v2; // ecx
  char v3; // bl

  v1 = 4;
  v2 = 0;
  do
  {
    v3 = *(_BYTE *)(*a1)++;
    v2 = v3 & 0x7F | (v2 << 7);
    if ( v3 >= 0 )
      break;
    --v1;
  }
  while ( v1 );
  return v2;
}


//----- (001586F0) --------------------------------------------------------
int __cdecl sub_1586F0(int a1, int a2)
{
  int v3; // esi
  unsigned int v4; // edi
  int result; // eax
  unsigned int v6; // ebp
  unsigned int v7; // ecx

  v3 = a2;
  v4 = 0;
  do
  {
    a1 += v4;
    if ( strncmp(a1, aForm, 4) && strncmp(a1, &aECat[3], 4) )
      return 0;
    v4 = ((*(_DWORD *)(a1 + 4) & 0xFF00) << 8)
       + ((uint8_t)*(_DWORD *)(a1 + 4) << 24)
       + ((*(_DWORD *)(a1 + 4) & 0xFF0000u) >> 8)
       + ((*(_DWORD *)(a1 + 4) & 0xFF000000) >> 24)
       + 8;
  }
  while ( strncmp(a1 + 8, &aAtexmid[3], 4) );
  result = strncmp(a1, aForm, 4);
  if ( result )
  {
    v6 = a1 + v4;
    v7 = a1 + 12;
    if ( v7 >= v6 )
      return 0;
    while ( strncmp(v7 + 8, &aAtexmid[3], 4) || --v3 != -1 )
    {
      v7 += ((uint8_t)*(_DWORD *)(v7 + 4) << 24)
          + ((*(_DWORD *)(v7 + 4) & 0xFF00) << 8)
          + ((*(_DWORD *)(v7 + 4) & 0xFF0000u) >> 8)
          + ((*(_DWORD *)(v7 + 4) & 0xFF000000) >> 24)
          + 8;
      if ( v7 >= v6 )
        return 0;
    }
    return v7;
  }
  else if ( !a2 )
  {
    return a1;
  }
  return result;
}
// 13ACDE: using guessed type int __fastcall strncmp(_DWORD, _DWORD, _DWORD);


//----- (00158810) --------------------------------------------------------
int __cdecl sub_158810(int a1, int a2, unsigned int a3)
{
  int v3; // ebx
  unsigned int v4; // ecx
  _DWORD *v5; // edx

  v3 = a2 & 0xF;
  v4 = a2 & 0xF0;
  v5 = (_DWORD *)(a1 + 4 * v3);
  if ( v4 >= 0xC0 )
  {
    if ( v4 <= 0xC0 )
      return *v5;
    if ( v4 == 224 )
      return v5[16] | (v5[32] << 7);
    return -1;
  }
  if ( v4 != 176 )
    return -1;
  if ( a3 < 0x5B )
  {
    if ( a3 < 7 )
    {
      if ( !a3 )
        return -1;
      if ( a3 <= 1 )
      {
        return *(_DWORD *)(a1 + 4 * v3 + 576);
      }
      else if ( a3 == 6 )
      {
        return *(_DWORD *)(a1 + 4 * v3 + 1024);
      }
      else
      {
        return -1;
      }
    }
    else if ( a3 <= 7 )
    {
      return *(_DWORD *)(a1 + 4 * v3 + 640);
    }
    else if ( a3 < 0xB )
    {
      if ( a3 == 10 )
        return *(_DWORD *)(a1 + 4 * v3 + 704);
      else
        return -1;
    }
    else if ( a3 <= 0xB )
    {
      return *(_DWORD *)(a1 + 4 * v3 + 768);
    }
    else if ( a3 == 64 )
    {
      return v5[208];
    }
    else
    {
      return -1;
    }
  }
  else if ( a3 <= 0x5B )
  {
    return v5[224];
  }
  else if ( a3 < 0x70 )
  {
    if ( a3 < 0x6E )
    {
      if ( a3 == 93 )
        return v5[240];
      else
        return -1;
    }
    else if ( a3 <= 0x6E )
    {
      return v5[48];
    }
    else
    {
      return v5[64];
    }
  }
  else if ( a3 <= 0x70 )
  {
    return v5[80];
  }
  else if ( a3 < 0x73 )
  {
    if ( a3 == 114 )
      return v5[96];
    else
      return -1;
  }
  else if ( a3 <= 0x73 )
  {
    return v5[112];
  }
  else if ( a3 == 119 )
  {
    return v5[128];
  }
  else
  {
    return -1;
  }
}


//----- (00158990) --------------------------------------------------------
unsigned int __cdecl sub_158990(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int result; // eax
  int v5; // ecx
  unsigned int v6; // edi
  _DWORD *v7; // ebx

  result = a3;
  v5 = a2 & 0xF;
  v6 = a2 & 0xF0;
  v7 = (_DWORD *)(a1 + 4 * v5);
  if ( v6 < 0xC0 )
  {
    if ( v6 == 176 )
    {
      if ( a3 < 0x5B )
      {
        if ( a3 < 7 )
        {
          if ( a3 )
          {
            if ( a3 <= 1 )
            {
              result = a4;
              *(_DWORD *)(a1 + 4 * v5 + 576) = a4;
            }
            else if ( a3 == 6 )
            {
              result = a4;
              *(_DWORD *)(a1 + 4 * v5 + 1024) = a4;
            }
          }
        }
        else if ( a3 <= 7 )
        {
          result = a4;
          *(_DWORD *)(a1 + 4 * v5 + 640) = a4;
        }
        else if ( a3 < 0xB )
        {
          if ( a3 == 10 )
          {
            result = a4;
            *(_DWORD *)(a1 + 4 * v5 + 704) = a4;
          }
        }
        else if ( a3 <= 0xB )
        {
          result = a4;
          *(_DWORD *)(a1 + 4 * v5 + 768) = a4;
        }
        else if ( a3 == 64 )
        {
          result = a4;
          v7[208] = a4;
        }
      }
      else if ( a3 <= 0x5B )
      {
        result = a4;
        v7[224] = a4;
      }
      else if ( a3 < 0x70 )
      {
        if ( a3 < 0x6E )
        {
          if ( a3 == 93 )
          {
            result = a4;
            v7[240] = a4;
          }
        }
        else
        {
          result = a4;
          if ( a3 <= 0x6E )
            v7[48] = a4;
          else
            v7[64] = a4;
        }
      }
      else if ( a3 <= 0x70 )
      {
        result = a4;
        v7[80] = a4;
      }
      else if ( a3 < 0x73 )
      {
        if ( a3 == 114 )
        {
          result = a4;
          v7[96] = a4;
        }
      }
      else if ( a3 <= 0x73 )
      {
        result = a4;
        v7[112] = a4;
      }
      else if ( a3 == 119 )
      {
        result = a4;
        v7[128] = a4;
      }
    }
  }
  else if ( v6 <= 0xC0 )
  {
    result = (uint8_t)a3;
    *v7 = (uint8_t)a3;
  }
  else if ( v6 == 224 )
  {
    v7[16] = (uint8_t)a3;
    result = a4;
    v7[32] = a4;
  }
  return result;
}


//----- (00158B50) --------------------------------------------------------
int __cdecl sub_158B50(int a1, int a2, unsigned int a3, int a4, int a5)
{
  int v5; // edi
  int v6; // edx
  int v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  int v11; // ett
  int v12; // eax
  int v13; // ebp
  int v14; // edx
  int i; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // ebp
  int v21; // eax
  int v22; // edi
  int v23; // [esp+0h] [ebp-20h]
  int v24; // [esp+4h] [ebp-1Ch]
  _DWORD *v25; // [esp+Ch] [ebp-14h]
  int v26; // [esp+10h] [ebp-10h]

  v5 = a4;
  v25 = *(_DWORD **)a1;
  v6 = a2 & 0xF0;
  v26 = a2 & 0xF;
  v24 = *(_DWORD *)(a1 + 4 * v26 + 144);
  if ( v6 == 176 || v6 == 192 || v6 == 224 )
    sub_158990(a1 + 208, v26 | v6, a3, a4);
  if ( v6 != 176 )
    goto LABEL_31;
  if ( a5 )
  {
    v7 = a1 + 4 * v26;
    if ( *(_DWORD *)(v7 + 656) != -1 )
    {
      v5 = *(_DWORD *)(v7 + 656);
      *(_DWORD *)(v7 + 656) = -1;
    }
  }
  v23 = a1 + 4 * v26;
  v8 = &v25[v24];
  if ( a3 < 0x6F )
  {
    if ( a3 < 0x6C )
    {
      if ( a3 >= 6 )
      {
        if ( a3 <= 6 )
        {
          sub_158B50(a1, a2 & 0xF | 0xB0, 100, 0, 0);
          sub_158B50(a1, a2 & 0xF | 0xB0, 101, 0, 0);
          sub_158B50(a1, a2 & 0xF | 0xB0, 38, 0, 0);
        }
        else if ( a3 == 7 )
        {
          v11 = v5 * *(_DWORD *)(a1 + 52);
          v5 = v11 / 127;
          if ( v11 / 127 > 127 )
            v5 = 127;
          if ( v5 < 0 )
            v5 = 0;
        }
      }
    }
    else
    {
      if ( a3 > 0x6C )
      {
        if ( a3 <= 0x6D )
        {
          sub_1436BB((_DWORD *)a1, v5);
        }
        else
        {
          v20 = v26 + 1;
          if ( v5 < 64 )
          {
            if ( v8[8] == 1 )
            {
              sub_159070((int *)a1, v26);
              sub_143E9C(v25, v24 + 1);
              sub_143F12((_DWORD *)a1, v20, v20);
            }
          }
          else if ( v8[8] != 1 )
          {
            sub_143DB7(v25);
            v22 = v21;
            if ( v21 )
            {
              sub_143F12((_DWORD *)a1, v20, v21);
              v25[v22 + 23] = a1;
            }
          }
        }
        return;
      }
      if ( *(_DWORD *)(a1 + 28) )
        *(_DWORD *)(v23 + 656) = (*(int (__cdecl **)(int, int, int))(a1 + 28))(a1, v26, v5);
    }
LABEL_31:
    v9 = &v25[v24];
    if ( v9[8] != 1 || a1 == v9[24] )
    {
      v10 = &v25[v24];
      if ( v6 == 144 )
      {
        ++v10[88];
      }
      else if ( v6 == 128 )
      {
        --v10[88];
      }
      v25[v24 + 56] = a1;
      if ( !v25[104] || !((int (__cdecl *)(_DWORD *, int, int, unsigned int, int))v25[104])(v25, a1, v24 | v6, a3, v5) )
        sub_1584A0((int)v25, v24 | v6, a3, v5);
    }
    return;
  }
  if ( a3 <= 0x6F )
  {
    if ( v8[8] != 1 )
    {
      if ( v5 >= 64 )
        v8[8] = 2;
      else
        v8[8] = 0;
    }
    return;
  }
  if ( a3 < 0x75 )
  {
    if ( a3 >= 0x73 )
    {
      if ( a3 > 0x73 )
      {
        v14 = a1;
        for ( i = 0; i < 4; ++i )
        {
          if ( *(_DWORD *)(v14 + 128) == -1 )
            break;
          v14 += 4;
        }
        if ( i != 4 )
        {
          *(_DWORD *)(a1 + 4 * i + 128) = v5;
          *(_DWORD *)(a1 + 4 * i + 112) = *(_DWORD *)(a1 + 20);
        }
        return;
      }
      *(_DWORD *)(v23 + 656) = *(uint8_t *)(v5 + *(_DWORD *)(a1 + 24));
    }
    goto LABEL_31;
  }
  if ( a3 <= 0x75 )
  {
    if ( v5 >= 64 )
    {
      v16 = 3;
      v17 = a1 + 12;
      do
      {
        if ( *(_DWORD *)(v17 + 128) != -1 )
          break;
        --v16;
        v17 -= 4;
      }
      while ( v16 >= 0 );
      if ( v16 != -1 )
      {
        v18 = a1 + 4 * v16;
        v19 = *(_DWORD *)(v18 + 128);
        if ( v19 )
        {
          *(_DWORD *)(v18 + 128) = v19 - 1;
          if ( v19 == 1 )
            *(_DWORD *)(v18 + 128) = -1;
          else
            *(_DWORD *)(a1 + 20) = *(_DWORD *)(v18 + 112);
        }
        else
        {
          *(_DWORD *)(a1 + 20) = *(_DWORD *)(v18 + 112);
        }
      }
    }
  }
  else
  {
    if ( a3 <= 0x76 )
    {
      *(_DWORD *)(a1 + 88) = 0;
      *(_DWORD *)(a1 + 104) = 0;
      v12 = *(_DWORD *)(a1 + 100);
      v13 = *(_DWORD *)(a1 + 104);
      *(_DWORD *)(a1 + 92) = 0;
      *(_DWORD *)(a1 + 104) = v13 - v12;
      return;
    }
    if ( a3 != 119 )
      goto LABEL_31;
    if ( *(_DWORD *)(a1 + 32) )
      (*(void (__cdecl **)(int, int, int))(a1 + 32))(a1, v26, v5);
  }
}
// 158B50: could not find valid save-restore pair for ebx
// 158EBB: variable 'v21' is possibly undefined
// 143E9C: using guessed type _DWORD __cdecl sub_143E9C(_DWORD, _DWORD);


//----- (00158FA0) --------------------------------------------------------
void __cdecl sub_158FA0(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // edi
  int v3; // eax
  int v4; // esi
  _WORD v5[6]; // [esp+0h] [ebp-1Ch] BYREF
  _DWORD *v6; // [esp+Ch] [ebp-10h]

  v1 = a1;
  v2 = 0;
  v6 = a1 + 32;
  do
  {
    v3 = v1[325];
    if ( v3 != -1 )
    {
      ++v2;
      sub_158B50((int)a1, v3 | 0x80, v1[357], 0, 0);
      v1[325] = -1;
    }
    ++v1;
  }
  while ( v1 != v6 );
  v4 = *a1;
  a1[324] = 0;
  if ( *(int *)(v4 + 424) > 0 )
  {
    v5[2] = *(_WORD *)(v4 + 424);
    sub_13FBC8(*(_DWORD *)v4, 1282, v5, 0);
    *(_DWORD *)(v4 + 424) = 0;
    *(_DWORD *)(v4 + 428) = 0;
  }
  if ( v2 )
  {
    if ( !sub_13FD4B() )
      sub_13FCDE(3);
  }
}


//----- (00159070) --------------------------------------------------------
int __cdecl sub_159070(int *a1, int a2)
{
  int *v2; // esi
  int v3; // eax
  int result; // eax
  int v5; // esi
  _WORD v6[12]; // [esp+0h] [ebp-18h] BYREF

  v2 = a1;
  do
  {
    if ( a2 == v2[325] )
    {
      v3 = v2[325];
      LOBYTE(v3) = v3 | 0x80;
      result = sub_158B50(a1, v3, v2[357], 0, 0);
      v2[325] = -1;
    }
    ++v2;
  }
  while ( v2 != a1 + 32 );
  v5 = *a1;
  if ( *(int *)(*a1 + 424) > 0 )
  {
    v6[2] = *(_WORD *)(v5 + 424);
    result = sub_13FBC8(*(_DWORD *)v5, 1282, v6, 0);
    *(_DWORD *)(v5 + 424) = 0;
    *(_DWORD *)(v5 + 428) = 0;
  }
  return result;
}
// 158B50: using guessed type _DWORD __cdecl sub_158B50(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);


//----- (00159120) --------------------------------------------------------
void __cdecl sub_159120(int a1, int a2)
{
  int v2; // edx
  unsigned int v3; // ecx
  int v4; // eax
  int v5; // edx
  int v6; // ebp
  int v7; // ebx
  int v8; // ebp
  int v9; // ebx
  int v10; // ebp
  int v11; // ebx
  int v12; // ebp
  int v13; // ebx
  int v14; // ebp
  int v15; // ebx

  v2 = *(_DWORD *)(a1 + 4 * a2 + 592);
  if ( v2 != -1 )
    sub_158B50(a1, a2 | 0xB0, 0x72u, v2, 0);
  v3 = *(_DWORD *)(a1 + 4 * a2 + 208);
  if ( v3 != -1 )
    sub_158B50(a1, a2 | 0xC0, v3, 0, 0);
  v4 = a1 + 4 * a2;
  v5 = *(_DWORD *)(v4 + 336);
  if ( v5 != -1 )
    sub_158B50(a1, a2 | 0xE0, *(_DWORD *)(v4 + 272), v5, 0);
  v6 = *(_DWORD *)(a1 + 4 * a2 + 464);
  if ( v6 != -1 )
    sub_158B50(a1, a2 | 0xB0, 0x6Fu, v6, 0);
  v7 = *(_DWORD *)(a1 + 4 * a2 + 528);
  if ( v7 != -1 )
    sub_158B50(a1, a2 | 0xB0, 0x70u, v7, 0);
  v8 = *(_DWORD *)(a1 + 4 * a2 + 784);
  if ( v8 != -1 )
    sub_158B50(a1, a2 | 0xB0, 1u, v8, 0);
  v9 = *(_DWORD *)(a1 + 4 * a2 + 848);
  if ( v9 != -1 )
    sub_158B50(a1, a2 | 0xB0, 7u, v9, 0);
  v10 = *(_DWORD *)(a1 + 4 * a2 + 912);
  if ( v10 != -1 )
    sub_158B50(a1, a2 | 0xB0, 0xAu, v10, 0);
  v11 = *(_DWORD *)(a1 + 4 * a2 + 976);
  if ( v11 != -1 )
    sub_158B50(a1, a2 | 0xB0, 0xBu, v11, 0);
  v12 = *(_DWORD *)(a1 + 4 * a2 + 1040);
  if ( v12 != -1 )
    sub_158B50(a1, a2 | 0xB0, 0x40u, v12, 0);
  v13 = *(_DWORD *)(a1 + 4 * a2 + 1104);
  if ( v13 != -1 )
    sub_158B50(a1, a2 | 0xB0, 0x5Bu, v13, 0);
  v14 = *(_DWORD *)(a1 + 4 * a2 + 1168);
  if ( v14 != -1 )
    sub_158B50(a1, a2 | 0xB0, 0x5Du, v14, 0);
  v15 = *(_DWORD *)(a1 + 4 * a2 + 1232);
  if ( v15 != -1 )
    sub_158B50(a1, a2 | 0xB0, 6u, v15, 0);
}


//----- (00159330) --------------------------------------------------------
_DWORD *__cdecl sub_159330(_DWORD *a1)
{
  _DWORD *v1; // edx
  int i; // eax
  _DWORD *v3; // eax
  _DWORD *result; // eax

  v1 = a1;
  for ( i = 0; i < 16; ++i )
  {
    v1[36] = i;
    ++v1;
  }
  memset(a1 + 52, -1, 1088);
  v3 = a1;
  do
  {
    ++v3;
    v3[31] = -1;
  }
  while ( v3 != a1 + 4 );
  result = a1;
  do
  {
    ++result;
    result[324] = -1;
  }
  while ( result != a1 + 32 );
  a1[324] = 0;
  a1[11] = 0;
  a1[22] = 0;
  a1[23] = -1;
  a1[26] = 0;
  a1[25] = 0;
  a1[24] = 4;
  a1[27] = 8000000;
  a1[12] = 0;
  a1[10] = 1;
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (00159400) --------------------------------------------------------
void __cdecl sub_159400(int a1)
{
  int v1; // esi
  int i; // edi
  int v3; // edx

  v1 = a1;
  for ( i = 0; i < 16; ++i )
  {
    v3 = *(_DWORD *)(v1 + 848);
    if ( v3 != -1 )
      sub_158B50(a1, i | 0xB0, 7u, v3, 0);
    v1 += 4;
  }
}


//----- (00159440) --------------------------------------------------------
int __cdecl sub_159440(int *a1)
{
  int result; // eax
  int v2; // eax
  int v3; // ebx
  int v4; // ecx
  int v5; // esi
  int v6; // ecx
  int v7; // ebx
  _DWORD *v8; // eax
  int v9; // ebp
  int v10; // eax
  int v11; // ebp
  int v12; // esi
  uint8_t *v13; // ebx
  uint8_t *v14; // ebx
  _DWORD *v15; // eax
  int v16; // edx
  _DWORD *v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // esi
  int v21; // ebx
  int v22; // eax
  char v23; // cl
  int v24; // eax
  _DWORD *v25; // eax
  int v26; // edi
  int v27; // eax
  int v28; // ebp
  unsigned int v29; // ebx
  int v30; // eax
  unsigned int v31; // esi
  unsigned int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // ebp
  int v36; // eax
  int v37; // esi
  int v38; // eax
  uint8_t *v39; // ebx
  _DWORD *v40; // eax
  int v41; // ebp
  int v42; // edx
  int v43; // esi
  int v44; // edi
  int v45; // ebp
  int v46; // eax
  int v47; // ebx
  int v48; // edi
  int v49; // edx
  int v50; // ebp
  int v51; // ebx
  int v52; // eax
  int v53; // ebx
  int v54; // edx
  int v55; // esi
  int v56; // ecx
  int v57; // ebx
  int v58; // [esp-8h] [ebp-20h]
  _DWORD *v59; // [esp-4h] [ebp-1Ch]
  _WORD v60[12]; // [esp+0h] [ebp-18h] BYREF

  result = (int)a1;
  if ( !a1[5] && !dword_18A530 )
  {
    dword_1C960C = a1[7];
    dword_18A530 = 1;
    dword_1C9604 = a1[6];
    while ( dword_1C960C )
    {
      v2 = dword_1C9604;
      if ( *(_DWORD *)(dword_1C9604 + 4) == 4 )
      {
        v3 = *(_DWORD *)(dword_1C9604 + 68);
        v4 = *(_DWORD *)(dword_1C9604 + 84);
        ++*(_DWORD *)(dword_1C9604 + 48);
        dword_1C961C = 0;
        *(_DWORD *)(v2 + 84) = v3 + v4;
        while ( 1 )
        {
          v5 = *(_DWORD *)(dword_1C9604 + 84);
          if ( v5 < 100 )
            break;
          v6 = *(_DWORD *)(dword_1C9604 + 1296);
          *(_DWORD *)(dword_1C9604 + 84) = v5 - 100;
          if ( v6 > 0 )
          {
            dword_1C9608 = 0;
            do
            {
              v7 = dword_1C9604;
              v8 = (_DWORD *)(dword_1C9604 + 4 * dword_1C9608);
              if ( v8[325] != -1 )
              {
                v9 = v8[389] - 1;
                v8[389] = v9;
                if ( v9 <= 0 )
                {
                  sub_158B50(v7, v8[325] | 0x80, v8[357], 0, 0);
                  v10 = dword_1C9604;
                  *(_DWORD *)(dword_1C9604 + 4 * dword_1C9608 + 1300) = -1;
                  v11 = *(_DWORD *)(v10 + 1296) - 1;
                  *(_DWORD *)(v10 + 1296) = v11;
                  if ( !v11 )
                    break;
                }
              }
              ++dword_1C9608;
            }
            while ( dword_1C9608 < 32 );
          }
          v12 = *(_DWORD *)(dword_1C9604 + 44) - 1;
          *(_DWORD *)(dword_1C9604 + 44) = v12;
          if ( v12 <= 0 )
          {
            while ( 1 )
            {
              while ( 1 )
              {
                v13 = *(uint8_t **)(dword_1C9604 + 20);
                dword_1C9618 = *v13;
                if ( (unsigned int)dword_1C9618 < 0x80 || dword_1C961C )
                {
                  if ( !dword_1C961C )
                  {
                    v38 = dword_1C9604;
                    v39 = *(uint8_t **)(dword_1C9604 + 20);
                    *(_DWORD *)(dword_1C9604 + 20) = v39 + 1;
                    *(_DWORD *)(v38 + 44) = *v39;
                  }
                  goto LABEL_67;
                }
                if ( (unsigned int)dword_1C9618 >= 0xF7 )
                  break;
                if ( dword_1C9618 != 240 )
                  goto LABEL_41;
LABEL_38:
                dword_1C95FC = *(_DWORD *)(dword_1C9604 + 20) + 1;
                v27 = sub_158680(&dword_1C95FC);
                v28 = *(_DWORD *)(dword_1C9604 + 20);
                dword_1C9620 = dword_1C95FC - v28 + v27;
                v29 = dword_1C95FC - v28 + v27;
                sub_158450((int)a1);
                if ( v29 > 0x200 )
                  v29 = 512;
                memmove(a1[2] + 256, v28, v29);
                ++a1[106];
                sub_158450((int)a1);
                *(_DWORD *)(dword_1C9604 + 20) += dword_1C9620;
              }
              if ( (unsigned int)dword_1C9618 <= 0xF7 )
                goto LABEL_38;
              if ( dword_1C9618 == 255 )
              {
                v14 = v13 + 2;
                v59 = (_DWORD *)(dword_1C9604 + 20);
                dword_1C9624 = *(v14 - 1);
                *(_DWORD *)(dword_1C9604 + 20) = v14;
                dword_1C9620 = sub_158680(v59);
                if ( (unsigned int)dword_1C9624 < 0x51 )
                {
                  if ( dword_1C9624 != 47 )
                    goto LABEL_37;
                  dword_1C961C = 1;
                  v15 = (_DWORD *)dword_1C9604;
                  v16 = *(_DWORD *)(dword_1C9604 + 40);
                  if ( v16 && (*(_DWORD *)(dword_1C9604 + 40) = v16 - 1, v16 == 1) )
                  {
                    sub_142837(v15);
                    v19 = dword_1C9604;
                    v20 = *(_DWORD *)(dword_1C9604 + 36);
                    *(_DWORD *)(dword_1C9604 + 4) = 2;
                    if ( !v20 )
                      goto LABEL_37;
                    (*(void (__cdecl **)(int))(v19 + 36))(v19);
                    *(_DWORD *)(dword_1C9604 + 20) += dword_1C9620;
                  }
                  else
                  {
                    v17 = (_DWORD *)dword_1C9604;
                    *(_DWORD *)(dword_1C9604 + 88) = 0;
                    v17[23] = -1;
                    v18 = v17[4];
                    v17[26] = 0;
                    v17[5] = v18 + 8;
                    *(_DWORD *)(dword_1C9604 + 20) += dword_1C9620;
                  }
                }
                else if ( (unsigned int)dword_1C9624 <= 0x51 )
                {
                  dword_1C9614 = *(uint8_t *)(*(_DWORD *)(dword_1C9604 + 20) + 2)
                               + (*(uint8_t *)(*(_DWORD *)(dword_1C9604 + 20) + 1) << 8)
                               + (**(uint8_t **)(dword_1C9604 + 20) << 16);
                  *(_DWORD *)(dword_1C9604 + 108) = 16 * dword_1C9614;
                  *(_DWORD *)(dword_1C9604 + 20) += dword_1C9620;
                }
                else
                {
                  if ( dword_1C9624 == 88 )
                  {
                    v21 = dword_1C9604;
                    *(_DWORD *)(dword_1C9604 + 96) = **(uint8_t **)(dword_1C9604 + 20);
                    dword_1C9614 = *(uint8_t *)(*(_DWORD *)(v21 + 20) + 1) - 2;
                    v22 = 16000000 / dword_1C9568;
                    v23 = dword_1C9614;
                    dword_1C9610 = 16000000 / dword_1C9568;
                    if ( dword_1C9614 >= 0 )
                    {
                      v24 = v22 << dword_1C9614;
                    }
                    else
                    {
                      dword_1C9614 = -dword_1C9614;
                      v24 = v22 >> -v23;
                    }
                    *(_DWORD *)(v21 + 100) = v24;
                    v25 = (_DWORD *)dword_1C9604;
                    *(_DWORD *)(dword_1C9604 + 104) = 0;
                    v25[22] = 0;
                    v26 = v25[26] - v25[25];
                    ++v25[23];
                    v25[26] = v26;
                  }
LABEL_37:
                  *(_DWORD *)(dword_1C9604 + 20) += dword_1C9620;
                }
              }
              else
              {
LABEL_41:
                dword_1C9600 = dword_1C9618 & 0xF;
                v30 = *(_DWORD *)(dword_1C9604 + 20);
                v58 = *(uint8_t *)(v30 + 2);
                v31 = *(uint8_t *)(v30 + 1);
                dword_1C9618 &= 0xF0u;
                sub_158B50(dword_1C9604, *(_BYTE *)v30, v31, v58, 1);
                if ( dword_1C9618 == 144 )
                {
                  v34 = 0;
                  dword_1C9608 = 0;
                  do
                  {
                    if ( *(_DWORD *)(dword_1C9604 + v34 + 1300) == -1 )
                      break;
                    v34 += 4;
                    ++dword_1C9608;
                  }
                  while ( v34 < 128 );
                  v35 = dword_1C9608;
                  if ( dword_1C9608 == 32 )
                  {
                    strcpy(&byte_1C9440, "Internal note queue overflow\n");
                    sub_142837((_DWORD *)dword_1C9604);
                    result = dword_1C9604;
                    dword_18A530 = 0;
                    *(_DWORD *)(dword_1C9604 + 4) = 2;
                    return result;
                  }
                  v36 = dword_1C9604;
                  v37 = dword_1C9600;
                  ++*(_DWORD *)(dword_1C9604 + 1296);
                  *(_DWORD *)(v36 + 4 * v35 + 1300) = v37;
                  *(_DWORD *)(v36 + 4 * v35 + 1428) = *(uint8_t *)(*(_DWORD *)(v36 + 20) + 1);
                  *(_DWORD *)(v36 + 20) += 3;
                  *(_DWORD *)(dword_1C9604 + 4 * dword_1C9608 + 1556) = sub_158680((_DWORD *)(v36 + 20));
                }
                else
                {
                  v32 = **(_BYTE **)(dword_1C9604 + 20) & 0xF0;
                  if ( v32 < 0xB0 )
                  {
                    if ( v32 < 0x90 )
                    {
                      if ( v32 == 128 )
                        goto LABEL_55;
                    }
                    else if ( v32 <= 0x90 || v32 == 160 )
                    {
LABEL_55:
                      v33 = 3;
                      goto LABEL_58;
                    }
                  }
                  else
                  {
                    if ( v32 <= 0xB0 )
                      goto LABEL_55;
                    if ( v32 < 0xD0 )
                    {
                      if ( v32 == 192 )
                      {
LABEL_56:
                        v33 = 2;
                        goto LABEL_58;
                      }
                    }
                    else
                    {
                      if ( v32 <= 0xD0 )
                        goto LABEL_56;
                      if ( v32 == 224 )
                        goto LABEL_55;
                    }
                  }
                  v33 = 0;
LABEL_58:
                  *(_DWORD *)(dword_1C9604 + 20) += v33;
                }
              }
            }
          }
LABEL_67:
          if ( !dword_1C961C )
          {
            v40 = (_DWORD *)dword_1C9604;
            v41 = *(_DWORD *)(dword_1C9604 + 100) + *(_DWORD *)(dword_1C9604 + 104);
            v42 = *(_DWORD *)(dword_1C9604 + 108);
            *(_DWORD *)(dword_1C9604 + 104) = v41;
            if ( v41 >= v42 )
            {
              v43 = v40[22];
              v40[26] = v41 - v42;
              ++v43;
              v44 = v40[24];
              v40[22] = v43;
              if ( v43 >= v44 )
              {
                v45 = v40[23];
                v40[22] = 0;
                v40[23] = v45 + 1;
              }
            }
          }
        }
        if ( !dword_1C961C )
        {
          if ( *(_DWORD *)(dword_1C9604 + 52) != *(_DWORD *)(dword_1C9604 + 56) )
          {
            *(_DWORD *)(dword_1C9604 + 60) += *(_DWORD *)(*(_DWORD *)dword_1C9604 + 16);
            do
            {
              v46 = dword_1C9604;
              v47 = *(_DWORD *)(dword_1C9604 + 60);
              v48 = *(_DWORD *)(dword_1C9604 + 64);
              if ( v47 < v48 )
                break;
              v49 = *(_DWORD *)(dword_1C9604 + 52);
              v50 = v47 - v48;
              v51 = *(_DWORD *)(dword_1C9604 + 56);
              *(_DWORD *)(dword_1C9604 + 60) = v50;
              *(_DWORD *)(v46 + 52) = v51 <= v49 ? v49 - 1 : v49 + 1;
            }
            while ( *(_DWORD *)(dword_1C9604 + 52) != *(_DWORD *)(dword_1C9604 + 56) );
            if ( (*(_BYTE *)(dword_1C9604 + 48) & 7) == 0 )
              sub_159400(dword_1C9604);
          }
          if ( *(_DWORD *)(dword_1C9604 + 68) != *(_DWORD *)(dword_1C9604 + 72) )
          {
            *(_DWORD *)(dword_1C9604 + 76) += *(_DWORD *)(*(_DWORD *)dword_1C9604 + 16);
            do
            {
              v52 = dword_1C9604;
              v53 = *(_DWORD *)(dword_1C9604 + 76);
              v54 = *(_DWORD *)(dword_1C9604 + 80);
              if ( v53 < v54 )
                break;
              v55 = *(_DWORD *)(dword_1C9604 + 68);
              v56 = v53 - v54;
              v57 = *(_DWORD *)(dword_1C9604 + 72);
              *(_DWORD *)(dword_1C9604 + 76) = v56;
              *(_DWORD *)(v52 + 68) = v57 <= v55 ? v55 - 1 : v55 + 1;
            }
            while ( *(_DWORD *)(dword_1C9604 + 68) != *(_DWORD *)(dword_1C9604 + 72) );
          }
        }
      }
      --dword_1C960C;
      dword_1C9604 += 1748;
    }
    result = (int)a1;
    if ( a1[106] > 0 )
    {
      v60[2] = *((_WORD *)a1 + 212);
      sub_13FBC8(*a1, 1282, v60, 0);
      result = (int)a1;
      a1[106] = 0;
      a1[107] = 0;
    }
    dword_18A530 = 0;
  }
  return result;
}
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 18A530: using guessed type int dword_18A530;
// 1C9440: using guessed type char byte_1C9440;
// 1C9568: using guessed type int dword_1C9568;
// 1C95FC: using guessed type int dword_1C95FC;
// 1C9600: using guessed type int dword_1C9600;
// 1C9604: using guessed type int dword_1C9604;
// 1C9608: using guessed type int dword_1C9608;
// 1C960C: using guessed type int dword_1C960C;
// 1C9610: using guessed type int dword_1C9610;
// 1C9614: using guessed type int dword_1C9614;
// 1C9618: using guessed type int dword_1C9618;
// 1C961C: using guessed type int dword_1C961C;
// 1C9620: using guessed type int dword_1C9620;
// 1C9624: using guessed type int dword_1C9624;


//----- (00159B70) --------------------------------------------------------
int __cdecl sub_159B70(int *a1, void *a2)
{
  int v2; // eax
  _WORD *v3; // ebx
  unsigned int i; // eax
  _DWORD v6[9]; // [esp+0h] [ebp-24h] BYREF

  qmemcpy(v6, a2, 0x18u);
  v2 = *(_DWORD *)(*a1 + 12);
  if ( *(_WORD *)(v2 + 16) )
  {
    v3 = (_WORD *)(16 * HIWORD(*(_DWORD *)(v2 + 12)) + (uint16_t)*(_DWORD *)(v2 + 12));
    if ( SLOWORD(v6[0]) < 1 )
      LOWORD(v6[0]) = *v3;
    if ( SHIWORD(v6[0]) < 1 )
      HIWORD(v6[0]) = v3[1];
    if ( SLOWORD(v6[1]) < 1 )
      LOWORD(v6[1]) = v3[2];
    if ( SHIWORD(v6[1]) < 1 )
      HIWORD(v6[1]) = v3[3];
    for ( i = 0; i != 16; i += 4 )
    {
      if ( (int)v6[i / 4 + 2] < 1 )
        v6[i / 4 + 2] = *(_DWORD *)&v3[i / 2 + 4];
    }
  }
  qmemcpy((void *)(*(_DWORD *)(*a1 + 12) + 22), v6, 0x18u);
  return sub_13FBC8(*a1, 772, 0, 0);
}


//----- (00159C40) --------------------------------------------------------
int __cdecl sub_159C40(_DWORD *a1)
{
  int v1; // edi
  int v2; // esi

  v1 = 0;
  if ( (int)a1[7] > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      sub_142911((_DWORD *)(v2 + a1[6]));
      v2 += 1748;
    }
    while ( v1 < a1[7] );
  }
  sub_140665(a1[3]);
  sub_1540EC(a1[6], 1748 * a1[7]);
  return sub_1540EC((unsigned int)a1, 464);
}


//----- (00159CA0) --------------------------------------------------------
int *__cdecl sub_159CA0(int a1, void *a2)
{
  int *result; // eax
  int *v3; // ebp
  _BYTE *v4; // eax
  _BYTE *v5; // eax
  char *v6; // edx
  char *v7; // esi
  char *v8; // edi
  char v9; // al
  char v10; // al
  char *v11; // esi
  char *v12; // edi
  char v13; // al
  char v14; // al
  void *v15; // eax
  void *v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // esi
  int v21; // eax
  int v22; // eax
  int64_t v23; // rtt
  int *v24; // esi
  int v25; // eax
  int v26; // edi
  _BYTE v27[24]; // [esp+0h] [ebp-50h] BYREF
  _WORD v28[6]; // [esp+18h] [ebp-38h] BYREF
  _WORD v29[6]; // [esp+24h] [ebp-2Ch] BYREF
  void *v30; // [esp+30h] [ebp-20h]
  void *v31; // [esp+34h] [ebp-1Ch]
  int v32; // [esp+38h] [ebp-18h]
  int v33; // [esp+3Ch] [ebp-14h]
  int v34; // [esp+40h] [ebp-10h]

  sub_1582F0();
  result = (int *)sub_1540A6(464);
  v3 = result;
  if ( result )
  {
    *result = a1;
    if ( *(_DWORD *)(a1 + 16) == 1 )
    {
      sub_13FBC8(a1, 769, 0, v28);
      v3[1] = v28[0] + 16 * v28[3];
      v3[2] = v28[1] + 16 * v28[2];
      v4 = (_BYTE *)(16 * HIWORD(*(_DWORD *)v3[1]) + (uint16_t)*(_DWORD *)v3[1]);
      if ( v4 )
      {
        if ( *v4 )
        {
          v5 = (_BYTE *)getenv(v4);
          if ( v5 )
          {
            if ( *v5 )
              strncpy(v3[2], v5, 128);
          }
        }
      }
      v6 = (char *)(16 * HIWORD(*(_DWORD *)(v3[1] + 4)) + (uint16_t)*(_DWORD *)(v3[1] + 4));
      if ( v6 && *v6 )
      {
        v7 = aSample;
        v8 = (char *)(v3[2] + 128);
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
        v11 = v6;
        v12 = (char *)(v3[2] + 128 + strlen((char *)(v3[2] + 128)));
        do
        {
          v13 = *v11;
          *v12 = *v11;
          if ( !v13 )
            break;
          v14 = v11[1];
          v11 += 2;
          v12[1] = v14;
          v12 += 2;
        }
        while ( v14 );
      }
      else
      {
        *(_BYTE *)(v3[2] + 128) = 0;
      }
      memset(&unk_1C9588, -1, 24);
      v32 = 0;
      if ( a2 )
      {
        qmemcpy(&unk_1C9588, a2, 0x18u);
        if ( sub_159B70(v3, a2) )
        {
          v32 = 1;
          qmemcpy(v27, a2, sizeof(v27));
        }
      }
      if ( !v32 )
      {
        sub_140734(*v3);
        v31 = v15;
        if ( v15 )
        {
          qmemcpy(&unk_1C9588, v15, 0x18u);
          if ( sub_159B70(v3, v15) )
          {
            v32 = 1;
            qmemcpy(v27, v31, sizeof(v27));
          }
        }
      }
      if ( !v32 && dword_1C9580 == 1 )
      {
        v34 = v32;
        v33 = v32;
        while ( 1 )
        {
          v17 = *(_DWORD *)(*v3 + 12);
          if ( *(uint16_t *)(v17 + 16) <= v34 )
            break;
          v16 = (void *)((uint16_t)*(_DWORD *)(v17 + 12) + 16 * HIWORD(*(_DWORD *)(v17 + 12)) + v33);
          v30 = v16;
          if ( !v34 )
            qmemcpy(&unk_1C9588, v16, 0x18u);
          if ( sub_159B70(v3, v30) )
          {
            v32 = 1;
            qmemcpy(v27, v30, sizeof(v27));
            break;
          }
          v33 += 24;
          ++v34;
        }
      }
      if ( v32 )
      {
        qmemcpy(&unk_1C9588, v27, 0x18u);
        sub_13FBC8(*v3, 773, 0, 0);
        *(_DWORD *)(*v3 + 20) = 1;
        sub_13FBC8(*v3, 1281, 0, v28);
        if ( v28[0] )
        {
          v18 = dword_1C956C;
          v3[7] = dword_1C956C;
          v19 = off_189864(1748 * v18);
          v3[6] = v19;
          if ( v19 )
          {
            v20 = 0;
            if ( v3[7] > 0 )
            {
              v21 = 0;
              do
              {
                *(_DWORD *)(v3[6] + v21 + 4) = 1;
                *(_DWORD *)(v3[6] + v21) = v3;
                ++v20;
                v21 += 1748;
              }
              while ( v20 < v3[7] );
            }
            LODWORD(v23) = 1000000; // vlna 12: "&loc_F4240" = konstanta 1e6
            HIDWORD(v23) = 0;      // (1000000 >> 31 == 0)
            v22 = v23 / dword_1C9568;
            v3[104] = 0;
            v3[105] = 0;
            v3[106] = 0;
            v3[107] = 0;
            v3[5] = 0;
            v24 = v3;
            v3[4] = v22;
            do
            {
              ++v24;
              v24[7] = 0;
              v24[23] = 0;
              v24[39] = 0;
              v24[55] = 0;
              v24[71] = 0;
              v24[87] = 0;
            }
            while ( v24 != v3 + 16 );
            sub_1400A9((int)sub_159440);
            v3[3] = v25;
            if ( v25 == -1 )
            {
              strcpy(&byte_1C9440, "Out of timer handles\n");
              sub_13FBC8(*v3, 774, 0, 0);
              *(_DWORD *)(*v3 + 20) = 0;
              sub_1540EC(v3[6], 1748 * v3[7]);
              sub_1540EC((unsigned int)v3, 464);
              return 0;
            }
            else
            {
              sub_140194(v25, (int32_t)v3);
              *(_DWORD *)(*v3 + 32) = sub_159C40;
              v26 = 0;
              *(_DWORD *)(*v3 + 36) = v3;
              do
              {
                sub_1584A0((int)v3, v26 | 0xB0, 114, 0);
                sub_1584A0((int)v3, v26 | 0xC0, 0, 0);
                sub_1584A0((int)v3, v26 | 0xE0, 0, 64);
                sub_1584A0((int)v3, v26 | 0xB0, 112, 0);
                sub_1584A0((int)v3, v26 | 0xB0, 1, 0);
                sub_1584A0((int)v3, v26 | 0xB0, 7, dword_1C9570);
                sub_1584A0((int)v3, v26 | 0xB0, 10, 64);
                sub_1584A0((int)v3, v26 | 0xB0, 11, 127);
                sub_1584A0((int)v3, v26 | 0xB0, 64, 0);
                sub_1584A0((int)v3, v26 | 0xB0, 91, 40);
                sub_1584A0((int)v3, v26 | 0xB0, 93, 0);
                sub_1584A0((int)v3, v26 | 0xB0, 100, 0);
                sub_1584A0((int)v3, v26 | 0xB0, 101, 0);
                sub_1584A0((int)v3, v26 | 0xB0, 38, 0);
                sub_1584A0((int)v3, v26 | 0xB0, 6, dword_1C957C);
                if ( v3[106] > 0 )
                {
                  v29[2] = *((_WORD *)v3 + 212);
                  sub_13FBC8(*v3, 1282, v29, 0);
                  v3[106] = 0;
                  v3[107] = 0;
                }
                if ( (v26 & 3) == 0 )
                  sub_13FCDE(3);
                ++v26;
              }
              while ( v26 < 16 );
              sub_1402FD(v3[3], dword_1C9568);
              sub_1404C7(v3[3]);
              return v3;
            }
          }
          else
          {
            strcpy(&byte_1C9440, "Could not allocate SEQUENCE structures\n");
            sub_13FBC8(*v3, 774, 0, 0);
            *(_DWORD *)(*v3 + 20) = 0;
            sub_1540EC((unsigned int)v3, 464);
            return 0;
          }
        }
        else
        {
          strcpy(&byte_1C9440, "Could not initialize instrument manager\n");
          sub_13FBC8(*v3, 774, 0, 0);
          *(_DWORD *)(*v3 + 20) = 0;
          sub_1540EC((unsigned int)v3, 464);
          return 0;
        }
      }
      else
      {
        strcpy(&byte_1C9440, "XMIDI sound hardware not found\n");
        sub_1540EC((unsigned int)v3, 464);
        return 0;
      }
    }
    else
    {
      strcpy(&byte_1C9440, ".MDI driver required\n");
      sub_1540EC((unsigned int)result, 464);
      return 0;
    }
  }
  else
  {
    strcpy(&byte_1C9440, "Could not allocate memory for driver\n");
  }
  return result;
}
// 159E7A: variable 'v15' is possibly undefined
// 15A132: variable 'v25' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 139ACE: using guessed type int __fastcall strncpy(_DWORD, _DWORD, _DWORD);
// 155777: using guessed type int __fastcall getenv(_DWORD);
// 189864: using guessed type int (__fastcall *off_189864)(_DWORD);
// 1C9440: using guessed type char byte_1C9440;
// 1C9568: using guessed type int dword_1C9568;
// 1C956C: using guessed type int dword_1C956C;
// 1C9570: using guessed type int dword_1C9570;
// 1C957C: using guessed type int dword_1C957C;
// 1C9580: using guessed type int dword_1C9580;


//----- (0015A340) --------------------------------------------------------
int __cdecl sub_15A340(int a1, void *a2)
{
  int result; // eax
  int v3; // esi
  int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edi
  int *v7; // esi

  result = sub_154B18(a1, 0);
  v3 = result;
  if ( result )
  {
    v4 = sub_154A9A(a1);
    sub_140819(v3, v4);
    v6 = v5;
    off_189868(v3);
    if ( v6 )
    {
      v7 = sub_159CA0(v6, a2);
      if ( !v7 )
        sub_14090C(v6);
      return (int)v7;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    strcpy(&byte_1C9440, "Driver file not found\n");
  }
  return result;
}
// 15A381: variable 'v5' is possibly undefined
// 189868: using guessed type int (__fastcall *off_189868)(_DWORD);
// 1C9440: using guessed type char byte_1C9440;


//----- (0015A3C0) --------------------------------------------------------
void __cdecl sub_15A3C0(int a1, int a2, void *a3)
{
  int v3; // eax
  unsigned int v4; // esi

  sub_140819(a1, a2);
  v4 = v3;
  if ( v3 )
  {
    if ( !sub_159CA0(v3, a3) )
      sub_14090C(v4);
  }
}
// 15A3D1: variable 'v3' is possibly undefined


//----- (0015A400) --------------------------------------------------------
void sub_15A400()
{
  _BYTE v0[128]; // [esp+0h] [ebp-120h] BYREF
  char v1[128]; // [esp+80h] [ebp-A0h] BYREF
  _BYTE v2[32]; // [esp+100h] [ebp-20h] BYREF

  if ( sub_13FD50((int)v0, &aRmdiIni[1]) )
    sub_142425(v1, v2);
  else
    strcpy(&byte_1C9440, "Unable to open file MDI.INI\n");
}
// 1C9440: using guessed type char byte_1C9440;


//----- (0015A460) --------------------------------------------------------
void __cdecl sub_15A460(unsigned int *a1)
{
  sub_14090C(*a1);
}


//----- (0015A470) --------------------------------------------------------
int __cdecl sub_15A470(char *a1)
{
  char *v2; // edi
  char v3; // al
  char v4; // al
  int result; // eax
  unsigned int v6; // kr04_4
  unsigned int v7; // edx
  unsigned int v8; // kr08_4

  v2 = aSample;
  do
  {
    v3 = *a1;
    *v2 = *a1;
    if ( !v3 )
      break;
    v4 = a1[1];
    a1 += 2;
    v2[1] = v4;
    v2 += 2;
  }
  while ( v4 );
  result = 0;
  v6 = strlen(aSample) + 1;
  v7 = v6 - 2;
  if ( v6 != 2 )
  {
    while ( 1 )
    {
      result = (uint8_t)aSample[v7];
      if ( result == 92 )
        break;
      if ( result == 46 )
      {
        BYTE1(result) = 0;
        aSample[v7] = 0;
        return result;
      }
      if ( !--v7 )
        return result;
    }
    result = 0;
    v8 = strlen(aSample) + 1;
    if ( v7 == v8 - 2 )
      aSample[v8 - 2] = 0;
  }
  return result;
}


//----- (0015A4F0) --------------------------------------------------------
_DWORD *__cdecl sub_15A4F0(int a1)
{
  int v1; // eax
  int v2; // edx
  _DWORD *v4; // esi

  sub_13F949();
  v1 = 0;
  if ( *(int *)(a1 + 28) > 0 )
  {
    v2 = *(_DWORD *)(a1 + 24);
    do
    {
      if ( *(_DWORD *)(v2 + 4) == 1 )
        break;
      ++v1;
      v2 += 1748;
    }
    while ( v1 < *(_DWORD *)(a1 + 28) );
  }
  if ( v1 == *(_DWORD *)(a1 + 28) )
  {
    strcpy(&byte_1C9440, "Out of sequence handles\n");
    sub_13F94E();
    return 0;
  }
  else
  {
    v4 = (_DWORD *)(1748 * v1 + *(_DWORD *)(a1 + 24));
    v4[1] = 2;
    sub_159330(v4);
    sub_13F94E();
    return v4;
  }
}
// 1C9440: using guessed type char byte_1C9440;


//----- (0015A570) --------------------------------------------------------
void __cdecl sub_15A570(_DWORD *a1)
{
  if ( a1 )
  {
    sub_142837(a1);
    a1[1] = 1;
  }
}


//----- (0015A590) --------------------------------------------------------
int __cdecl sub_15A590(int **a1, int a2, int a3)
{
  int result; // eax
  unsigned int v4; // edi
  unsigned int v5; // esi
  int *v6; // eax
  int v7; // eax
  int *v8; // ebp
  _WORD *v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // edx
  char *v12; // eax
  int *v13; // esi
  int16_t v14; // [esp+0h] [ebp-24h] BYREF
  int v15; // [esp+2h] [ebp-22h]
  _WORD v16[12]; // [esp+Ch] [ebp-18h] BYREF

  if ( !a1 )
    return 0;
  a1[1] = (int *)2;
  result = sub_1586F0(a2, a3);
  if ( !result )
  {
    strcpy(&byte_1C9440, "Invalid XMIDI sequence\n");
    return result;
  }
  v4 = result
     + ((*(_DWORD *)(result + 4) & 0xFF00) << 8)
     + ((uint8_t)*(_DWORD *)(result + 4) << 24)
     + ((*(_DWORD *)(result + 4) & 0xFF0000u) >> 8)
     + ((*(_DWORD *)(result + 4) & 0xFF000000) >> 24)
     + 8;
  a1[2] = 0;
  a1[3] = 0;
  v5 = result + 12;
  for ( a1[4] = 0;
        v5 < v4;
        v5 += ((*(_DWORD *)(v5 + 4) & 0xFF00) << 8)
            + ((uint8_t)*(_DWORD *)(v5 + 4) << 24)
            + ((*(_DWORD *)(v5 + 4) & 0xFF0000u) >> 8)
            + ((*(_DWORD *)(v5 + 4) & 0xFF000000) >> 24)
            + 8 )
  {
    if ( !strncmp(v5, aTimb, 4) )
      a1[2] = (int *)v5;
    if ( !strncmp(v5, &aAtcrbrn[3], 4) )
      a1[3] = (int *)v5;
    if ( !strncmp(v5, &aNotevnt[3], 4) )
      a1[4] = (int *)v5;
  }
  if ( !a1[4] )
  {
    result = 0;
    strcpy(&byte_1C9440, "Invalid XMIDI sequence\n");
    return result;
  }
  a1[6] = 0;
  a1[7] = 0;
  a1[8] = 0;
  a1[9] = 0;
  a1[10] = (int *)1;
  sub_159330(a1);
  v6 = a1[4];
  a1[16] = 0;
  a1[15] = 0;
  a1[17] = (int *)100;
  a1[18] = (int *)100;
  a1[20] = 0;
  a1[19] = 0;
  a1[21] = 0;
  a1[5] = v6 + 2;
  v7 = dword_1C9570;
  a1[13] = (int *)dword_1C9570;
  v8 = a1[2];
  a1[14] = (int *)v7;
  if ( !v8 )
    return 1;
  memmove(&unk_1C9628, v8, 512);
  if ( (*a1)[105] )
  {
    v9 = &unk_1C9628;
    v10 = 0;
    while ( v10 < *(uint16_t *)&byte_1C962D[3] )
    {
      if ( ((int (__cdecl *)(int *, int, _DWORD))(*a1)[105])(
             *a1,
             (uint16_t)(v9[5] & 0xFF00) >> 8,
             (uint8_t)v9[5]) )
      {
        v11 = v10 + 1;
        v12 = (char *)&unk_1C9628 + 2 * v10 + 2;
        while ( v11 < *(uint16_t *)&byte_1C962D[3] )
        {
          v12 += 2;
          ++v11;
          *((_WORD *)v12 + 3) = *((_WORD *)v12 + 4);
        }
        --*(_WORD *)&byte_1C962D[3];
        if ( byte_1C962D[0] >= 2u )
        {
          byte_1C962D[0] -= 2;
        }
        else
        {
          byte_1C962D[0] -= 2;
          --unk_1C962C;
        }
      }
      else
      {
        ++v9;
        ++v10;
      }
    }
  }
  if ( !*(_WORD *)&byte_1C962D[3] )
    return 1;
  if ( sub_13FD4B() )
  {
    result = -1;
    strcpy(&byte_1C9440, "No timbres loaded\n");
    return result;
  }
  ++(*a1)[5];
  v13 = *a1;
  if ( (*a1)[106] > 0 )
  {
    v16[2] = *((_WORD *)v13 + 212);
    sub_13FBC8(*v13, 1282, v16, 0);
    v13[106] = 0;
    v13[107] = 0;
  }
  memmove((*a1)[2] + 256, &unk_1C9628, 512);
  sub_13FBC8(**a1, 1283, 0, &v14);
  --(*a1)[5];
  if ( v14 )
    return 1;
  sprintf(&byte_1C9440, "Driver could not install timbre bank %u, patch %u\n", (int16_t)v15 >> 8, (uint8_t)v15);
  return -1;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 13ACDE: using guessed type int __fastcall strncmp(_DWORD, _DWORD, _DWORD);
// 1C9440: using guessed type char byte_1C9440;
// 1C9570: using guessed type int dword_1C9570;
// 1C962D: using guessed type uint8_t[515];


//----- (0015A940) --------------------------------------------------------
int __cdecl sub_15A940(_DWORD *a1)
{
  int v1; // eax
  int result; // eax

  if ( a1 )
  {
    if ( a1[1] != 1 )
    {
      sub_142837(a1);
      sub_159330(a1);
      v1 = a1[4];
      a1[1] = 4;
      result = v1 + 8;
      a1[5] = result;
    }
  }
  return result;
}


//----- (0015A980) --------------------------------------------------------
void __cdecl sub_15A980(_DWORD *a1)
{
  _DWORD *v1; // esi
  _DWORD *v2; // ebp
  int v3; // edi

  if ( a1 && a1[1] == 4 )
  {
    v1 = a1;
    a1[1] = 8;
    sub_158FA0(a1);
    v2 = (_DWORD *)*a1;
    do
    {
      v3 = v1[36];
      if ( (int)v1[260] >= 64 )
        sub_1584A0((int)v2, v3 | 0xB0, 64, 0);
      if ( (int)v1[116] >= 64 )
        v2[v3 + 8] = 0;
      if ( (int)v1[132] >= 64 )
        sub_1584A0((int)v2, v3 | 0xB0, 112, 0);
      if ( (int)v1[100] >= 64 )
        sub_143E9C(v2, v3 + 1);
      ++v1;
    }
    while ( v1 != a1 + 16 );
  }
}
// 15A980: could not find valid save-restore pair for ebx


//----- (0015AA50) --------------------------------------------------------
void __cdecl sub_15AA50(_DWORD *a1)
{
  _DWORD *v1; // edi
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int i; // esi
  _DWORD *v6; // [esp+0h] [ebp-10h]

  if ( a1 && a1[1] == 8 )
  {
    v1 = a1;
    v2 = 0;
    v6 = (_DWORD *)*a1;
    do
    {
      if ( (int)v1[100] >= 64 )
      {
        sub_143DB7(v6);
        v4 = v3 - 1;
        if ( v4 == -1 )
          v4 = v2;
        v1[36] = v4;
      }
      ++v2;
      ++v1;
    }
    while ( v2 < 16 );
    for ( i = 0; i < 16; ++i )
      sub_159120((int)a1, i);
    a1[1] = 4;
  }
}
// 15AA92: variable 'v3' is possibly undefined


//----- (0015AAE0) --------------------------------------------------------
void __cdecl sub_15AAE0(_DWORD *a1)
{
  if ( a1 )
  {
    if ( a1[1] != 1 )
    {
      sub_142837(a1);
      a1[1] = 2;
    }
  }
}


//----- (0015AB10) --------------------------------------------------------
int __cdecl sub_15AB10(int a1, int a2)
{
  int result; // eax

  result = a1;
  if ( a1 )
    *(_DWORD *)(a1 + 40) = a2;
  return result;
}


//----- (0015AB20) --------------------------------------------------------
int __cdecl sub_15AB20(_DWORD *a1, int a2, int a3)
{
  int v3; // esi
  signed int v4; // esi
  int result; // eax

  if ( a1 )
  {
    ++*(_DWORD *)(*a1 + 20);
    a1[18] = a2;
    v3 = a1[18];
    if ( a1[17] != v3 )
    {
      if ( a3 )
      {
        v4 = abs32(a1[17] - v3);
        a1[19] = 0;
        a1[20] = 1000 * a3 / v4;
      }
      else
      {
        a1[17] = v3;
      }
    }
    result = *a1;
    --*(_DWORD *)(*a1 + 20);
  }
  return result;
}


//----- (0015AB90) --------------------------------------------------------
int __cdecl sub_15AB90(_DWORD *a1, int a2, int a3)
{
  int v3; // ecx
  int result; // eax
  signed int v5; // ecx

  if ( a1 )
  {
    ++*(_DWORD *)(*a1 + 20);
    a1[14] = a2;
    v3 = a1[14];
    if ( a1[13] == v3 )
    {
      result = *a1;
      --*(_DWORD *)(*a1 + 20);
    }
    else
    {
      if ( a3 )
      {
        v5 = abs32(a1[13] - v3);
        a1[15] = 0;
        a1[16] = 1000 * a3 / v5;
      }
      else
      {
        a1[13] = v3;
      }
      sub_159400((int)a1);
      result = *a1;
      --*(_DWORD *)(*a1 + 20);
    }
  }
  return result;
}


//----- (0015AC10) --------------------------------------------------------
int __cdecl sub_15AC10(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
    return *(_DWORD *)(a1 + 4);
  return result;
}


//----- (0015AC20) --------------------------------------------------------
int __cdecl sub_15AC20(int a1)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 40);
  else
    return -1;
}


//----- (0015AC40) --------------------------------------------------------
int __cdecl sub_15AC40(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
    return *(_DWORD *)(a1 + 68);
  return result;
}


//----- (0015AC50) --------------------------------------------------------
int __cdecl sub_15AC50(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
    return *(_DWORD *)(a1 + 52);
  return result;
}


//----- (0015AC60) --------------------------------------------------------
int __cdecl sub_15AC60(int *a1, int a2, int a3)
{
  _WORD v4[6]; // [esp+0h] [ebp-Ch] BYREF

  v4[2] = (a2 << 8) | a3;
  return sub_13FBC8(*a1, 1284, v4, 0);
}


//----- (0015ACA0) --------------------------------------------------------
int __cdecl sub_15ACA0(int *a1, int a2, int a3)
{
  int v4; // edi
  int v5; // ebp
  _WORD v6[6]; // [esp+0h] [ebp-24h] BYREF
  int16_t v7; // [esp+Ch] [ebp-18h] BYREF
  int v8; // [esp+Eh] [ebp-16h]

  if ( a1[105] && ((int (__cdecl *)(int *, int, int))a1[105])(a1, a2, a3) )
    return 1;
  v4 = a1[5];
  v5 = a1[106];
  byte_18A542 = a3;
  byte_18A543 = a2;
  a1[5] = v4 + 1;
  if ( v5 > 0 )
  {
    v6[2] = *((_WORD *)a1 + 212);
    sub_13FBC8(*a1, 1282, v6, 0);
    a1[106] = 0;
    a1[107] = 0;
  }
  memmove(a1[2] + 256, aTimb_0, 12);
  sub_13FBC8(*a1, 1283, 0, &v7);
  --a1[5];
  if ( !v7 )
    sprintf(&byte_1C9440, "Driver could not install timbre bank %u, patch %u\n", (int16_t)v8 >> 8, (uint8_t)v8);
  return v7;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 18A542: using guessed type char byte_18A542;
// 18A543: using guessed type char byte_18A543;
// 1C9440: using guessed type char byte_1C9440;


//----- (0015ADA0) --------------------------------------------------------
int __cdecl sub_15ADA0(int *a1, int a2, int a3)
{
  _WORD v4[6]; // [esp+0h] [ebp-Ch] BYREF

  v4[2] = (a2 << 8) | a3;
  v4[3] = 1;
  return sub_13FBC8(*a1, 1285, v4, 0);
}


//----- (0015ADE0) --------------------------------------------------------
int __cdecl sub_15ADE0(int *a1, int a2, int a3)
{
  _WORD v4[6]; // [esp+0h] [ebp-Ch] BYREF

  v4[2] = (a2 << 8) | a3;
  v4[3] = 0;
  return sub_13FBC8(*a1, 1285, v4, 0);
}


//----- (0015AE20) --------------------------------------------------------
int __cdecl sub_15AE20(int a1)
{
  int v1; // ebx
  int v2; // eax
  int v3; // edx

  v1 = 0;
  v2 = 0;
  if ( *(int *)(a1 + 28) > 0 )
  {
    v3 = *(_DWORD *)(a1 + 24);
    do
    {
      if ( *(_DWORD *)(v3 + 4) == 4 )
        ++v1;
      ++v2;
      v3 += 1748;
    }
    while ( v2 < *(_DWORD *)(a1 + 28) );
  }
  return v1;
}


//----- (0015AE50) --------------------------------------------------------
int __cdecl sub_15AE50(int a1, int a2, unsigned int a3)
{
  if ( a1 )
    return sub_158810(a1 + 208, (a2 - 1) | 0xB0, a3);
  else
    return -1;
}


//----- (0015AE80) --------------------------------------------------------
int __cdecl sub_15AE80(int a1, int a2)
{
  int v3; // eax
  int v4; // edx

  if ( !a1 )
    return 0;
  v3 = a1;
  v4 = 0;
  do
  {
    if ( a2 - 1 == *(_DWORD *)(v3 + 1300) )
      ++v4;
    v3 += 4;
  }
  while ( v3 != a1 + 64 );
  return v4;
}


//----- (0015AEC0) --------------------------------------------------------
void __cdecl sub_15AEC0(_DWORD *a1, _DWORD *a2, int *a3)
{
  int v3; // edi
  int v4; // ecx
  int v5; // ebx
  int v6; // esi
  int v7; // eax
  int v8; // ebp

  if ( a1 )
  {
    v3 = dword_1C9574;
    ++*(_DWORD *)(*a1 + 20);
    v4 = 0;
    v5 = a1[22];
    v6 = a1[23];
    v7 = a1[26];
    if ( v3 > 0 )
    {
      do
      {
        v8 = a1[27];
        v7 += a1[25];
        if ( v7 >= v8 )
        {
          ++v5;
          v7 -= v8;
          if ( v5 >= a1[24] )
          {
            ++v6;
            v5 = 0;
          }
        }
        ++v4;
      }
      while ( v4 < dword_1C9574 );
    }
    if ( v6 < 0 )
      v6 = 0;
    if ( a3 )
      *a3 = v6;
    if ( a2 )
      *a2 = v5;
    --*(_DWORD *)(*a1 + 20);
  }
}
// 1C9574: using guessed type int dword_1C9574;


//----- (0015AF30) --------------------------------------------------------
void __cdecl sub_15AF30(_DWORD *a1, int a2)
{
  int v2; // edx
  int v3; // ebp
  int v4; // ecx
  int v5; // eax
  uint16_t *v6; // edx
  int v7; // edx
  int v8; // eax
  int v9; // ebx
  _DWORD *v10; // eax

  if ( a1 )
  {
    v2 = a1[3];
    if ( v2 )
    {
      v3 = v2 + 10;
      v4 = *(int16_t *)(v2 + 8);
      v5 = 0;
      if ( v4 > 0 )
      {
        v6 = (uint16_t *)(v2 + 10);
        do
        {
          if ( *v6 == a2 )
            break;
          ++v5;
          v6 += 3;
        }
        while ( v5 < v4 );
      }
      if ( v5 != v4 )
      {
        v7 = *(_DWORD *)(6 * v5 + v3 + 2);
        v8 = a1[4] + 8;
        a1[11] = 0;
        v9 = dword_1C9578;
        a1[5] = v7 + v8;
        if ( !v9 )
        {
          v10 = a1;
          do
          {
            ++v10;
            v10[31] = -1;
          }
          while ( v10 != a1 + 4 );
        }
      }
    }
  }
}
// 1C9578: using guessed type int dword_1C9578;


//----- (0015AFC0) --------------------------------------------------------
int __cdecl sub_15AFC0(int a1, int a2)
{
  int result; // eax
  int v3; // edx

  result = a1;
  if ( a1 )
  {
    v3 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 28) = a2;
    return v3;
  }
  return result;
}


//----- (0015AFE0) --------------------------------------------------------
int __cdecl sub_15AFE0(int a1, int a2)
{
  int result; // eax
  int v3; // edx

  result = a1;
  if ( a1 )
  {
    v3 = *(_DWORD *)(a1 + 32);
    *(_DWORD *)(a1 + 32) = a2;
    return v3;
  }
  return result;
}


//----- (0015B000) --------------------------------------------------------
int __cdecl sub_15B000(int a1, int a2)
{
  int result; // eax
  int v3; // edx

  result = a1;
  if ( a1 )
  {
    v3 = *(_DWORD *)(a1 + 36);
    *(_DWORD *)(a1 + 36) = a2;
    return v3;
  }
  return result;
}


//----- (0015B020) --------------------------------------------------------
int __cdecl sub_15B020(int a1, int a2)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 416);
  *(_DWORD *)(a1 + 416) = a2;
  return result;
}


//----- (0015B040) --------------------------------------------------------
int __cdecl sub_15B040(int a1, int a2)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 420);
  *(_DWORD *)(a1 + 420) = a2;
  return result;
}


//----- (0015B060) --------------------------------------------------------
int __cdecl sub_15B060(int a1, int a2, int a3)
{
  int result; // eax

  if ( a1 )
  {
    result = a1 + 4 * a2;
    *(_DWORD *)(result + 1684) = a3;
  }
  return result;
}


//----- (0015B080) --------------------------------------------------------
int __cdecl sub_15B080(int a1, int a2)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 4 * a2 + 1684);
  else
    return 0;
}


//----- (0015B0A0) --------------------------------------------------------
int __cdecl sub_15B0A0(int a1, int a2)
{
  int result; // eax

  result = a1;
  if ( a1 )
    *(_DWORD *)(a1 + 24) = a2;
  return result;
}


//----- (0015B0B0) --------------------------------------------------------
int __cdecl sub_15B0B0(_DWORD *a1)
{
  int v1; // ebp
  int v2; // edi
  _DWORD *v3; // eax
  int v4; // esi
  int v5; // ebx
  int v6; // esi
  _DWORD *v7; // eax
  int result; // eax
  int v9; // edi
  int v10; // esi
  int v11; // ebx
  int v12; // eax
  _DWORD *v13; // eax
  int v14; // esi
  int v15; // [esp+0h] [ebp-18h]
  int v16; // [esp+4h] [ebp-14h]

  v1 = -1;
  v2 = 0x7FFFFFFF;
  v3 = a1 + 8;
  v4 = 8;
  ++a1[5];
  do
  {
    if ( v4 != 9 )
    {
      v5 = v3[8];
      if ( v5 != 1 && v5 != 2 && v2 > v3[88] )
      {
        v2 = v3[88];
        v1 = v4;
      }
    }
    --v4;
    --v3;
  }
  while ( v4 >= 1 );
  if ( v1 == -1 )
  {
    v6 = 8;
    v7 = a1 + 8;
    do
    {
      if ( v6 != 9 && v7[8] != 1 && v2 > v7[88] )
      {
        v2 = v7[88];
        v1 = v6;
      }
      --v6;
      --v7;
    }
    while ( v6 >= 1 );
  }
  if ( v1 == -1 )
  {
    result = 0;
    --a1[5];
  }
  else
  {
    sub_1584A0((int)a1, v1 | 0xB0, 64, 0);
    v9 = a1[6];
    v16 = a1[7];
    if ( v16 )
    {
      v15 = v9 + 128;
      do
      {
        if ( *(_DWORD *)(v9 + 4) != 1 )
        {
          v10 = v9;
          do
          {
            v11 = *(_DWORD *)(v10 + 1300);
            if ( v11 != -1 && v1 == *(_DWORD *)(v9 + 4 * v11 + 144) )
            {
              v12 = *(_DWORD *)(v10 + 1300);
              LOBYTE(v12) = v11 | 0x80;
              sub_158B50(v9, v12, *(_DWORD *)(v10 + 1428), 0, 0);
              *(_DWORD *)(v10 + 1300) = -1;
            }
            v10 += 4;
          }
          while ( v10 != v15 );
        }
        v9 += 1748;
        --v16;
        v15 += 1748;
      }
      while ( v16 );
    }
    v13 = &a1[v1];
    v13[24] = 0;
    v14 = v13[8];
    v13[8] = 1;
    v13[72] = v14;
    v13[40] = v13[56];
    result = v1 + 1;
    --a1[5];
  }
  return result;
}
// 158B50: using guessed type _DWORD __cdecl sub_158B50(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);


//----- (0015B250) --------------------------------------------------------
_DWORD *__cdecl sub_15B250(_DWORD *a1, int a2)
{
  _DWORD *result; // eax
  int v3; // edi
  int v4; // esi
  int v5; // ecx
  int v6; // esi
  int v7; // [esp+0h] [ebp-18h]
  int v8; // [esp+4h] [ebp-14h]
  int v9; // [esp+8h] [ebp-10h]

  v9 = a2 - 1;
  result = &a1[a2 - 1];
  if ( result[8] == 1 )
  {
    ++a1[5];
    result[8] = result[72];
    result[56] = result[40];
    sub_1584A0((int)a1, v9 | 0xB0, 64, 0);
    v3 = a1[6];
    v8 = a1[7];
    if ( v8 )
    {
      v7 = v3 + 128;
      do
      {
        if ( *(_DWORD *)(v3 + 4) != 1 )
        {
          v4 = v3;
          do
          {
            v5 = *(_DWORD *)(v4 + 1300);
            if ( v5 != -1 && v9 == *(_DWORD *)(v3 + 4 * v5 + 144) )
            {
              sub_158B50(v3, v5 | 0x80, *(_DWORD *)(v4 + 1428), 0, 0);
              *(_DWORD *)(v4 + 1300) = -1;
            }
            v4 += 4;
          }
          while ( v4 != v7 );
        }
        v3 += 1748;
        --v8;
        v7 += 1748;
      }
      while ( v8 );
    }
    v6 = a1[v9 + 40];
    if ( v6 )
    {
      if ( *(_DWORD *)(v6 + 4) != 1 )
        sub_159120(v6, v9);
    }
    result = a1;
    --a1[5];
  }
  return result;
}


//----- (0015B380) --------------------------------------------------------
_DWORD *__cdecl sub_15B380(_DWORD *a1, int a2, int a3)
{
  _DWORD *result; // eax
  int v4; // edx

  result = a1;
  if ( a1 )
  {
    a1[a2 + 35] = a3 - 1;
    v4 = *a1 + 4 * a3;
    if ( *(_DWORD *)(v4 + 28) == 1 && a1 != *(_DWORD **)(v4 + 92) )
      *(_DWORD *)(v4 + 92) = a1;
  }
  return result;
}


//----- (0015B3C0) --------------------------------------------------------
int __cdecl sub_15B3C0(int a1, int a2)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 4 * a2 + 140) + 1;
  else
    return 0;
}


//----- (0015B3E0) --------------------------------------------------------
void __cdecl sub_15B3E0(int a1, int a2, int a3, unsigned int a4, int a5)
{
  _WORD v5[12]; // [esp+0h] [ebp-18h] BYREF

  ++*(_DWORD *)(a1 + 20);
  if ( a2 )
  {
    sub_158B50(a2, a3, a4, a5, 0);
  }
  else if ( !*(_DWORD *)(a1 + 416)
         || !(*(int (__cdecl **)(int, _DWORD, int, unsigned int, int))(a1 + 416))(a1, 0, a3, a4, a5) )
  {
    sub_1584A0(a1, a3, a4, a5);
  }
  if ( *(int *)(a1 + 424) > 0 )
  {
    v5[2] = *(_WORD *)(a1 + 424);
    sub_13FBC8(*(_DWORD *)a1, 1282, v5, 0);
    *(_DWORD *)(a1 + 424) = 0;
    *(_DWORD *)(a1 + 428) = 0;
  }
  --*(_DWORD *)(a1 + 20);
}


//----- (0015B490) --------------------------------------------------------
int __cdecl sub_15B490(_DWORD *a1, int a2)
{
  int v2; // eax
  unsigned int v3; // ebp
  int v4; // ebx
  int result; // eax
  int v6; // [esp+0h] [ebp-14h] BYREF
  int v7; // [esp+4h] [ebp-10h]

  ++a1[5];
  v6 = a2 + 1;
  v2 = sub_158680(&v6);
  v7 = a2;
  v3 = v2 + v6 - a2;
  sub_158450((int)a1);
  if ( v3 <= 0x200 )
    v4 = v3;
  else
    v4 = 512;
  memmove(a1[2] + 256, v7, v4);
  ++a1[106];
  result = sub_158450((int)a1);
  --a1[5];
  return result;
}
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);


//----- (0015B520) --------------------------------------------------------
bool sub_15B520()
{
  bool result; // eax

  if ( dword_18A534 )
  {
    sub_1542DF((unsigned int)sub_1582F0, (unsigned int)sub_15B520);
    sub_1543D5((unsigned int)aSample, 128);
    sub_1543D5((unsigned int)&dword_18A530, 4);
    sub_1543D5((unsigned int)&dword_1C9604, 4);
    sub_1543D5((unsigned int)&dword_1C9608, 4);
    sub_1543D5((unsigned int)&dword_1C960C, 4);
    sub_1543D5((unsigned int)&dword_1C961C, 4);
    sub_1543D5((unsigned int)&dword_1C9610, 4);
    sub_1543D5((unsigned int)&dword_1C9614, 4);
    sub_1543D5((unsigned int)&dword_1C9600, 4);
    sub_1543D5((unsigned int)&dword_1C9618, 4);
    sub_1543D5((unsigned int)&dword_1C9624, 4);
    sub_1543D5((unsigned int)&dword_1C9620, 4);
    result = sub_1543D5((unsigned int)&dword_1C95FC, 4);
    dword_18A534 = 0;
  }
  return result;
}
// 1582F0: using guessed type int sub_1582F0();
// 18A530: using guessed type int dword_18A530;
// 18A534: using guessed type int dword_18A534;
// 1C95FC: using guessed type int dword_1C95FC;
// 1C9600: using guessed type int dword_1C9600;
// 1C9604: using guessed type int dword_1C9604;
// 1C9608: using guessed type int dword_1C9608;
// 1C960C: using guessed type int dword_1C960C;
// 1C9610: using guessed type int dword_1C9610;
// 1C9614: using guessed type int dword_1C9614;
// 1C9618: using guessed type int dword_1C9618;
// 1C961C: using guessed type int dword_1C961C;
// 1C9620: using guessed type int dword_1C9620;
// 1C9624: using guessed type int dword_1C9624;


//----- (0015B814) --------------------------------------------------------
bool sub_15B814()
{
  bool result; // eax

  if ( !dword_18A544 )
  {
    result = sub_15421D((unsigned int)sub_15B814, (unsigned int)sub_15C179);
    dword_18A544 = 1;
  }
  return result;
}
// 18A544: using guessed type int dword_18A544;


//----- (0015B840) --------------------------------------------------------
_DWORD *__cdecl sub_15B840(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // esi
  int v5; // ecx
  _DWORD *result; // eax

  v4 = a2 & 0xF0;
  v5 = a2 & 0xF;
  result = (_DWORD *)(a1 + 4 * v5);
  if ( v4 < 0xC0 )
  {
    if ( v4 == 176 )
    {
      if ( a3 < 0x5B )
      {
        if ( a3 < 7 )
        {
          if ( a3 )
          {
            if ( a3 <= 1 )
            {
              result = (_DWORD *)a4;
              *(_DWORD *)(a1 + 4 * v5 + 576) = a4;
            }
            else if ( a3 == 6 )
            {
              result = (_DWORD *)a4;
              *(_DWORD *)(a1 + 4 * v5 + 1024) = a4;
            }
          }
        }
        else if ( a3 <= 7 )
        {
          result = (_DWORD *)a4;
          *(_DWORD *)(a1 + 4 * v5 + 640) = a4;
        }
        else if ( a3 < 0xB )
        {
          if ( a3 == 10 )
          {
            result = (_DWORD *)a4;
            *(_DWORD *)(a1 + 4 * v5 + 704) = a4;
          }
        }
        else if ( a3 <= 0xB )
        {
          result = (_DWORD *)a4;
          *(_DWORD *)(a1 + 4 * v5 + 768) = a4;
        }
        else if ( a3 == 64 )
        {
          result[208] = a4;
        }
      }
      else if ( a3 <= 0x5B )
      {
        result[224] = a4;
      }
      else if ( a3 < 0x70 )
      {
        if ( a3 < 0x6E )
        {
          if ( a3 == 93 )
            result[240] = a4;
        }
        else if ( a3 <= 0x6E )
        {
          result[48] = a4;
        }
        else
        {
          result[64] = a4;
        }
      }
      else if ( a3 <= 0x70 )
      {
        result[80] = a4;
      }
      else if ( a3 < 0x73 )
      {
        if ( a3 == 114 )
          result[96] = a4;
      }
      else if ( a3 <= 0x73 )
      {
        result[112] = a4;
      }
      else if ( a3 == 119 )
      {
        result[128] = a4;
      }
    }
  }
  else if ( v4 <= 0xC0 )
  {
    *result = (uint8_t)a3;
  }
  else if ( v4 == 224 )
  {
    result[16] = (uint8_t)a3;
    result[32] = a4;
  }
  return result;
}


//----- (0015B9F5) --------------------------------------------------------
_DWORD *__fastcall sub_15B9F5(_DWORD *result, int a2, int a3)
{
  int i; // edx

  for ( i = 0; i < 512 && *result != -1; ++i )
  {
    if ( a2 == *result && a3 == result[1] )
      return result;
    result += 8;
  }
  return 0;
}


//----- (0015BA1E) --------------------------------------------------------
void __fastcall sub_15BA1E(int a1, int a2)
{
  int *v2; // esi
  _DWORD *v3; // edi

  v2 = (int *)(a1 + 4 * a2);
  v3 = (_DWORD *)(a1 + 4 * v2[310]);
  sub_14129D(v2[293], v3[197] * v3[165] / 127 * v2[374] / 127);
  sub_141313(v2[293], v3[181]);
}


//----- (0015BA8A) --------------------------------------------------------
void __fastcall sub_15BA8A(int a1, int a2)
{
  int v4; // ebx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // ebp
  int v12; // eax
  int v13; // edx
  int64_t v14; // rtt
  int v15; // [esp+0h] [ebp-24h]
  int v16; // [esp+8h] [ebp-1Ch]
  int v17; // [esp+Ch] [ebp-18h]

  v17 = *(_DWORD *)(a1 + 4 * a2 + 1240);
  v15 = *(_DWORD *)(a1 + 4 * a2 + 1368);
  v4 = *(_DWORD *)(a1 + 4 * a2 + 1432);
  v16 = *(_DWORD *)(a1 + 4 * a2 + 1304);
  v5 = (*(_DWORD *)(a1 + 4 * v17 + 148) << 7) | *(_DWORD *)(a1 + 4 * v17 + 84);
  if ( v5 <= 0x2000 )
  {
    if ( v5 >= 0x2000 )
    {
      v7 = 0;
      v6 = 0;
    }
    else
    {
      v7 = 0x2000 - v5;
      v6 = -1;
    }
  }
  else
  {
    v6 = 1;
    v7 = v5 - 0x1FFF;
  }
  v8 = v16 + *(_DWORD *)(a1 + 4 * v17 + 1044) * v6;
  if ( v8 < 0 )
    v8 = 0;
  if ( v8 > 127 )
    v8 = 127;
  v9 = dword_15B614[v16];
  v10 = v7 * (dword_15B614[v8] - v9);
  v11 = v9 + ((v10 - (__CFSHL__(v10 >> 31, 13) + (v10 >> 31 << 13))) >> 13);
  if ( v17 == 9 )
  {
    v13 = v11 * v4;
    v12 = v11 * v4;
  }
  else
  {
    v12 = v11 * (v9 * v4 / dword_15B614[v15]);
    v13 = v12;
  }
  LODWORD(v14) = v12;
  HIDWORD(v14) = v13 >> 31;
  sub_141227(*(_DWORD *)(a1 + 4 * a2 + 1172), v14 / v9);
  JUMPOUT(0x15BA84);
}
// 15BB8F: control flows out of bounds to 15BA84
// 15B614: using guessed type int dword_15B614[];


//----- (0015BB94) --------------------------------------------------------
bool __cdecl sub_15BB94(int a1, int a2, int a3)
{
  return sub_15B9F5(*(_DWORD **)(*(_DWORD *)(a1 + 432) + 8), a2, a3) != 0;
}


//----- (0015BBB9) --------------------------------------------------------
int __cdecl sub_15BBB9(int a1, int a2, int a3, unsigned int a4, int a5)
{
  int v5; // edi
  unsigned int v6; // esi
  int v7; // ebp
  int k; // esi
  int v9; // eax
  int v10; // eax
  int j; // esi
  int v12; // eax
  int v13; // eax
  int m; // esi
  int v15; // ebp
  int v16; // eax
  int i; // esi
  int v18; // eax
  int v19; // eax
  int ii; // esi
  int v21; // eax
  unsigned int v22; // edx
  int jj; // eax
  int v24; // ebp
  int v25; // eax
  int n; // esi
  int *v28; // ebp
  int v29; // eax
  int v30; // [esp+0h] [ebp-14h]
  int v31; // [esp+4h] [ebp-10h]

  v5 = *(_DWORD *)(a1 + 432);
  v6 = a3 & 0xF0;
  v31 = a3 & 0xF;
  if ( v6 == 176 || v6 == 192 || v6 == 224 )
    sub_15B840(v5 + 20, a3, a4, a5);
  if ( v6 == 144 && !a5 )
    v6 = 128;
  v7 = v5 + 4 * v31;
  if ( v6 >= 0xB0 )
  {
    if ( v6 > 0xB0 )
    {
      if ( v6 >= 0xC0 )
      {
        if ( v6 <= 0xC0 )
        {
          *(_DWORD *)(v7 + 1108) = sub_15B9F5(*(_DWORD **)(v5 + 8), *(_DWORD *)(v7 + 404), a4);
        }
        else if ( v6 == 224 )
        {
          for ( i = 0; i < *(_DWORD *)(v5 + 1236); ++i )
          {
            v18 = v5 + 4 * i;
            if ( *(_DWORD *)(v18 + 1240) == v31 )
            {
              sub_1413FF(*(_DWORD *)(v18 + 1172));
              if ( v19 == 4 )
                sub_15BA8A(v5, i);
            }
          }
        }
      }
      return 0;
    }
    if ( a4 < 7 )
    {
      if ( a4 == 6 )
      {
        for ( j = 0; j < *(_DWORD *)(v5 + 1236); ++j )
        {
          v12 = v5 + 4 * j;
          if ( *(_DWORD *)(v12 + 1240) == v31 )
          {
            sub_1413FF(*(_DWORD *)(v12 + 1172));
            if ( v13 == 4 )
              sub_15BA8A(v5, j);
          }
        }
      }
      return 0;
    }
    if ( a4 <= 7 )
    {
LABEL_26:
      for ( k = 0; k < *(_DWORD *)(v5 + 1236); ++k )
      {
        v9 = v5 + 4 * k;
        if ( *(_DWORD *)(v9 + 1240) == v31 )
        {
          sub_1413FF(*(_DWORD *)(v9 + 1172));
          if ( v10 == 4 )
            sub_15BA1E(v5, k);
        }
      }
      return 0;
    }
    if ( a4 >= 0xA )
    {
      if ( a4 > 0xB )
      {
        if ( a4 == 123 )
        {
          for ( m = 0; m < *(_DWORD *)(v5 + 1236); ++m )
          {
            v15 = v5 + 4 * m;
            if ( *(_DWORD *)(v15 + 1240) == v31 )
            {
              sub_1413FF(*(_DWORD *)(v15 + 1172));
              if ( v16 == 4 )
                sub_1411BA(*(_DWORD *)(v15 + 1172));
            }
          }
        }
        return 0;
      }
      goto LABEL_26;
    }
    return 0;
  }
  if ( v6 < 0x80 )
    return 0;
  if ( v6 <= 0x80 )
  {
    if ( v31 != 9 )
    {
      for ( n = 0; n < *(_DWORD *)(v5 + 1236); ++n )
      {
        v28 = (int *)(v5 + 4 * n);
        if ( v28[310] == v31 && v28[326] == a4 )
        {
          sub_1413FF(v28[293]);
          if ( v29 == 4 )
          {
            sub_1411BA(v28[293]);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( v6 != 144 )
    return 0;
  if ( v31 == 9 )
    *(_DWORD *)(v7 + 1108) = sub_15B9F5(*(_DWORD **)(v5 + 8), 127, a4);
  if ( !*(_DWORD *)(v5 + 4 * v31 + 1108) )
    return 0;
  for ( ii = 0; ii < *(_DWORD *)(v5 + 1236); ++ii )
  {
    sub_1413FF(*(_DWORD *)(v5 + 4 * ii + 1172));
    if ( v21 == 2 )
      break;
  }
  if ( ii == *(_DWORD *)(v5 + 1236) )
  {
    v22 = -1;
    for ( jj = 0; jj < *(_DWORD *)(v5 + 1236); ++jj )
    {
      v24 = v5 + 4 * jj;
      if ( v22 >= *(_DWORD *)(v24 + 1560) )
      {
        v22 = *(_DWORD *)(v24 + 1560);
        ii = jj;
      }
    }
    sub_1411BA(*(_DWORD *)(v5 + 4 * ii + 1172));
  }
  *(_DWORD *)(v5 + 4 * ii + 1240) = v31;
  *(_DWORD *)(v5 + 4 * ii + 1304) = a4;
  v30 = v5 + 4 * v31;
  *(_DWORD *)(v5 + 4 * ii + 1368) = *(_DWORD *)(*(_DWORD *)(v30 + 1108) + 8);
  *(_DWORD *)(v5 + 4 * ii + 1432) = *(_DWORD *)(*(_DWORD *)(v30 + 1108) + 28);
  *(_DWORD *)(v5 + 4 * ii + 1496) = a5;
  v25 = *(_DWORD *)(v5 + 1624);
  *(_DWORD *)(v5 + 1624) = v25 + 1;
  *(_DWORD *)(v5 + 4 * ii + 1560) = v25;
  sub_140DFC(*(int **)(v5 + 4 * ii + 1172));
  sub_140FF1(
    *(_DWORD *)(v5 + 4 * ii + 1172),
    *(_DWORD *)(*(_DWORD *)(v30 + 1108) + 20),
    *(_DWORD *)(*(_DWORD *)(v30 + 1108) + 24));
  sub_140F6F(
    *(_DWORD **)(v5 + 4 * ii + 1172),
    *(_DWORD *)(*(_DWORD *)(v30 + 1108) + 12) + *(_DWORD *)(v5 + 8),
    *(_DWORD *)(*(_DWORD *)(v30 + 1108) + 16));
  sub_15BA8A(v5, ii);
  sub_15BA1E(v5, ii);
  sub_141073(*(_DWORD **)(v5 + 4 * ii + 1172));
  return 1;
}
// 15BCD4: variable 'v10' is possibly undefined
// 15BD16: variable 'v13' is possibly undefined
// 15BD58: variable 'v16' is possibly undefined
// 15BDBD: variable 'v19' is possibly undefined
// 15BE1F: variable 'v21' is possibly undefined
// 15BF8B: variable 'v29' is possibly undefined


//----- (0015BFAD) --------------------------------------------------------
int *__cdecl sub_15BFAD(int a1, int a2, int a3, int a4)
{
  int *result; // eax
  int *v5; // ebp
  int *v6; // esi
  int v7; // eax
  int v8; // eax
  int i; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int j; // ecx
  int k; // ecx

  sub_15B814();
  result = (int *)sub_1540A6(1628);
  v5 = result;
  v6 = result;
  if ( result )
  {
    result[1] = a1;
    *result = a2;
    result[2] = a3;
    sub_1439F8(a2, (int)sub_15BBB9);
    v5[3] = v7;
    sub_143AE5(a2, (int)sub_15BB94);
    v5[4] = v8;
    *(_DWORD *)(a2 + 432) = v5;
    for ( i = 0; i < 16; ++i )
    {
      v6[i + 5] = 0;
      v6[i + 21] = 0;
      v6[i + 37] = 64;
      v6[i + 101] = 0;
      v6[i + 165] = 127;
      v6[i + 181] = 64;
      v6[i + 197] = 127;
      v6[i + 261] = dword_1C957C;
    }
    for ( v6[309] = 0; ; v6[309] = v11 + 1 )
    {
      v12 = a4 <= 16 ? a4 : 16;
      if ( v12 <= v6[309] )
        break;
      sub_140BB1(v6[1]);
      v6[v6[309] + 293] = v10;
      v11 = v6[309];
      if ( !v6[v11 + 293] )
        break;
    }
    for ( j = 0; j < 16; ++j )
      v6[j + 277] = 0;
    for ( k = 0; k < v6[309]; ++k )
      v6[k + 310] = -1;
    v6[406] = 0;
    return v6;
  }
  else
  {
    strcpy(&byte_1C9440, "Insufficient memory for HWAVE descriptor\n");
  }
  return result;
}
// 15C00C: variable 'v7' is possibly undefined
// 15C021: variable 'v8' is possibly undefined
// 15C0AE: variable 'v10' is possibly undefined
// 1C9440: using guessed type char byte_1C9440;
// 1C957C: using guessed type int dword_1C957C;


//----- (0015C125) --------------------------------------------------------
void __cdecl sub_15C125(int *a1)
{
  int i; // esi

  for ( i = 0; i < a1[309]; ++i )
    sub_140D8F(a1[i + 293]);
  sub_1439F8(*a1, a1[3]);
  sub_143AE5(*a1, a1[4]);
  sub_1540EC((unsigned int)a1, 1628);
  JUMPOUT(0x15BFA6);
}
// 15C174: control flows out of bounds to 15BFA6


//----- (0015C179) --------------------------------------------------------
bool sub_15C179()
{
  bool result; // eax

  if ( dword_18A544 )
  {
    result = sub_1542DF((unsigned int)sub_15B814, (unsigned int)sub_15C179);
    dword_18A544 = 0;
  }
  return result;
}
// 15B814: using guessed type int sub_15B814();
// 18A544: using guessed type int dword_18A544;


//----- (0015C24E) --------------------------------------------------------
int __fastcall sub_15C24E(int a1, int a2)
{
  return *(_DWORD *)a2;
}


//----- (0015C730) --------------------------------------------------------
char sub_15C730()
{
  char result; // al

  if ( !dword_18A5B0 )
  {
    dword_1C9830 = (int)nullsub_21;
    /* __asm: int     2Fh; - Multiplex - MS WINDOWS - GET DEVICE API ENTRY POINT */ DECOMP_TODO("inline asm");
    *(_WORD *)byte_1C9836 = 0;
    *(_WORD *)&byte_1C9836[2] = 0;
    *(_WORD *)&byte_1C9836[4] = 0;
    if ( *(_DWORD *)byte_1C9836 )
    {
      result = 1;
      dword_18A5AC = (int (__fastcall *)(_DWORD))sub_15C7F0;
      dword_18A5B0 = 1;
    }
    else
    {
      dword_18A5AC = (int (__fastcall *)(_DWORD))&off_15C810;
      dword_18A5B0 = -MEMORY[0x46C];
      hr_outbyte(0x43u, 0x34u);
      hr_outbyte(0x40u, 0);
      result = 0;
      hr_outbyte(0x40u, 0);
    }
  }
  return result;
}
// 15C7E0: using guessed type int nullsub_21();
// 15C7F0: using guessed type int sub_15C7F0();
// 15C810: using guessed type _UNKNOWN *off_15C810;
// 18A5AC: using guessed type int (__fastcall *dword_18A5AC)(_DWORD);
// 18A5B0: using guessed type int dword_18A5B0;
// 1C9830: using guessed type int dword_1C9830;


//----- (0015C850) --------------------------------------------------------
int __usercall sub_15C850( int a1, int a2, int a3, int a4)
{
  int result; // eax

  BYTE1(result) = 61;
  LOBYTE(result) = a4;
  /* __asm: int     21h; DOS - 2+ - OPEN DISK FILE WITH HANDLE */ DECOMP_TODO("inline asm");
  if ( a1 )
    LOWORD(result) = -1;
  return (int16_t)result;
}


//----- (0015C8A9) --------------------------------------------------------
int __usercall sub_15C8A9( unsigned int a1, int a2, int a3, int a4, unsigned int a5, _DWORD *a6)
{
  int v6; // edx
  unsigned int v7; // ecx
  int result; // eax

  v6 = a3;
  do
  {
    HIBYTE(a1) = 63;
    v7 = a5;
    if ( a5 > 0xFFFF )
      v7 = 61440;
    /* __asm: int     21h; DOS - 2+ - READ FROM FILE WITH HANDLE */ DECOMP_TODO("inline asm");
    if ( a5 < 0xFFFF )
      break;
    if ( !a1 )
      break;
    v6 += a1;
    if ( a1 < v7 )
      break;
    a5 -= a1;
  }
  while ( a5 );
  result = v6 - a3;
  *a6 = v6 - a3;
  return result;
}


//----- (0015C941) --------------------------------------------------------
uint64_t __cdecl sub_15C941(int a1, unsigned int a2)
{
  unsigned int v2; // ecx
  int v3; // edx

  /* __asm: int     21h; DOS - 2+ - MOVE FILE READ/WRITE POINTER (LSEEK) */ DECOMP_TODO("inline asm");
  v3 = a2 << 16;
  LOWORD(v3) = 16896;
  return __PAIR64__(v2, v3);
}
// 15C95E: variable 'v2' is possibly undefined


//----- (0015C965) --------------------------------------------------------
void sub_15C965()
{
  JUMPOUT(0x15C945);
}
// 15C969: control flows out of bounds to 15C945


//----- (0015C971) --------------------------------------------------------
int64_t sub_15C971()
{
  int64_t result; // rax

  BYTE1(result) = 62;
  /* __asm: int     21h; DOS - 2+ - CLOSE A FILE WITH HANDLE */ DECOMP_TODO("inline asm");
  return result;
}


//----- (0015CA26) --------------------------------------------------------
int __fastcall sub_15CA26(int result, int a2, int a3, int *a4)
{
  int v4; // edx
  uint16_t v5[4]; // [esp+0h] [ebp-2Ch] BYREF
  int v6; // [esp+8h] [ebp-24h]
  int v7; // [esp+Ch] [ebp-20h]
  int *v8; // [esp+10h] [ebp-1Ch]
  int v9; // [esp+14h] [ebp-18h]
  int v10; // [esp+18h] [ebp-14h]
  int v11; // [esp+1Ch] [ebp-10h]
  int v12; // [esp+20h] [ebp-Ch]
  int v13; // [esp+24h] [ebp-8h]
  int v14; // [esp+28h] [ebp-4h]

  v6 = result;
  v9 = a2;
  v7 = a3;
  v8 = a4;
  if ( a2 )
  {
    v14 = sub_1622EE(v7);
    v13 = 0;
    v11 = 0;
    sub_15D2E5();
    sub_15D68B();
    while ( 1 )
    {
      if ( v13 == v9 )
      {
        v10 = 257;
      }
      else
      {
        v10 = *(uint8_t *)(v13 + v6);
        ++v13;
      }
      v12 = sub_15D4E1(v10, v11, v5);
      sub_15CD9C(v14, v5);
      if ( v12 )
      {
        sub_15D4E1(v10, 256, v5);
        sub_15CD9C(v14, v5);
      }
      if ( v10 == 257 )
        break;
      sub_15D3E7(v10, v11);
      v11 = v10;
    }
    sub_15CF06(v14);
    v4 = sub_1623C4(v14);
    *v8 = v4;
    return sub_15D399();
  }
  return result;
}


//----- (0015CB10) --------------------------------------------------------
int __fastcall sub_15CB10(int result, int a2, int a3, _DWORD *a4)
{
  uint16_t v4[4]; // [esp+0h] [ebp-30h] BYREF
  int v5; // [esp+8h] [ebp-28h]
  int v6; // [esp+Ch] [ebp-24h]
  _DWORD *v7; // [esp+10h] [ebp-20h]
  int v8; // [esp+14h] [ebp-1Ch]
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  int v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+24h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h]

  v5 = result;
  v8 = a2;
  v6 = a3;
  v7 = a4;
  if ( a2 )
  {
    v13 = sub_162359(v5);
    v14 = 0;
    v11 = 0;
    sub_15D2E5();
    sub_15CD2E(v13);
    while ( 1 )
    {
      v12 = v11;
      do
      {
        sub_15D5B2(v11, (int)v4);
        v9 = (int16_t)sub_15D8AB((int)v4);
        v10 = sub_15D5F1(v9, v11, v4);
        sub_15CBEE(v13, v4);
        v11 = v10;
      }
      while ( v10 == 256 );
      if ( v10 == 257 )
        break;
      *(_BYTE *)(v14 + v6) = v10;
      ++v14;
      sub_15D3E7(v10, v12);
      v11 = v10;
    }
    sub_16242D(v13);
    *v7 = v14;
    return sub_15D399();
  }
  return result;
}


//----- (0015CBEE) --------------------------------------------------------
int __fastcall sub_15CBEE(int a1, uint16_t *a2)
{
  int result; // eax
  int v4; // [esp+8h] [ebp-4h]

  v4 = (uint16_t)word_1C9C48 - (uint16_t)word_1C9C4A + 1;
  word_1C9C48 = word_1C9C4A + v4 * a2[1] / a2[2] - 1;
  word_1C9C4A += v4 * *a2 / a2[2];
  while ( 1 )
  {
    if ( (word_1C9C48 & 0x8000) == (word_1C9C4A & 0x8000) )
      goto LABEL_7;
    result = word_1C9C4A & 0x4000;
    if ( result != 0x4000 )
      return result;
    result = word_1C9C48 & 0x4000;
    if ( (word_1C9C48 & 0x4000) != 0 )
      return result;
    byte_1C9C4D ^= 0x40u;
    HIBYTE(word_1C9C4A) &= 0x3Fu;
    HIBYTE(word_1C9C48) |= 0x40u;
LABEL_7:
    word_1C9C4A *= 2;
    word_1C9C48 *= 2;
    LOBYTE(word_1C9C48) = word_1C9C48 | 1;
    unk_1C9C4C *= 2;
    unk_1C9C4C += sub_16267C(a1);
  }
}
// 1C9C48: using guessed type int16_t word_1C9C48;
// 1C9C4A: using guessed type int16_t word_1C9C4A;
// 1C9C4D: using guessed type char byte_1C9C4D;


//----- (0015CD2E) --------------------------------------------------------
int __fastcall sub_15CD2E(int result)
{
  int v1; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  v1 = result;
  unk_1C9C4C = 0;
  for ( i = 0; i < 16; ++i )
  {
    unk_1C9C4C *= 2;
    unk_1C9C4C += sub_16267C(v1);
    result = i;
  }
  word_1C9C4A = 0;
  word_1C9C48 = -1;
  return result;
}
// 1C9C48: using guessed type int16_t word_1C9C48;
// 1C9C4A: using guessed type int16_t word_1C9C4A;


//----- (0015CD9C) --------------------------------------------------------
int __fastcall sub_15CD9C(int a1, uint16_t *a2)
{
  int result; // eax
  int v4; // [esp+8h] [ebp-4h]

  v4 = (uint16_t)word_1C9C48 - (uint16_t)word_1C9C4A + 1;
  word_1C9C48 = word_1C9C4A + v4 * a2[1] / a2[2] - 1;
  word_1C9C4A += v4 * *a2 / a2[2];
  while ( (word_1C9C48 & 0x8000) == (word_1C9C4A & 0x8000) )
  {
    sub_162459(a1, word_1C9C48 & 0x8000);
    while ( dword_1C9840 > 0 )
    {
      sub_162459(a1, ~word_1C9C48 & 0x8000);
      --dword_1C9840;
    }
LABEL_11:
    word_1C9C4A *= 2;
    word_1C9C48 *= 2;
    LOBYTE(word_1C9C48) = word_1C9C48 | 1;
  }
  result = word_1C9C4A & 0x4000;
  if ( (word_1C9C4A & 0x4000) != 0 )
  {
    result = word_1C9C48 & 0x4000;
    if ( (word_1C9C48 & 0x4000) == 0 )
    {
      ++dword_1C9840;
      HIBYTE(word_1C9C4A) &= 0x3Fu;
      HIBYTE(word_1C9C48) |= 0x40u;
      goto LABEL_11;
    }
  }
  return result;
}
// 1C9840: using guessed type int dword_1C9840;
// 1C9C48: using guessed type int16_t word_1C9C48;
// 1C9C4A: using guessed type int16_t word_1C9C4A;


//----- (0015CF06) --------------------------------------------------------
int __fastcall sub_15CF06(int a1)
{
  int v1; // eax

  sub_162459(a1, word_1C9C4A & 0x4000);
  ++dword_1C9840;
  while ( 1 )
  {
    v1 = dword_1C9840--;
    if ( v1 <= 0 )
      break;
    sub_162459(a1, ~word_1C9C4A & 0x4000);
  }
  return sub_162559(a1, 0, 16);
}
// 1C9840: using guessed type int dword_1C9840;
// 1C9C4A: using guessed type int16_t word_1C9C4A;


//----- (0015D2E5) --------------------------------------------------------
void sub_15D2E5()
{
  int i; // [esp+0h] [ebp-8h]
  int j; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 257; ++i )
  {
    // DECOMP_TODO (vyreseno ve vlne 06): puvodni "calloc(259)" mela jen
    // JEDEN parametr - stejny druh chyby jako u fopen/fseek (viz PROGRESS.md).
    // Skutecny calloc potrebuje (count, size). Tady je oprava bezpecna a
    // jednoznacna: celkovy pocet pozadovanych bajtu (259) je jasny at uz
    // puvodne slo o calloc(1,259) nebo calloc(259,1) - vysledek je bit-
    // presne stejny (count*size=259 v obou pripadech).
    dword_1C9844[i] = calloc(1, 259);
    if ( !dword_1C9844[i] )
      sub_163233((int)aFailureAllocat, i);
    sub_15D3E7(256, i);
  }
  for ( j = 0; j <= 258; ++j )
    *(_DWORD *)(dword_1C9C44 + 4 * j) = j;
}
// 16321B: using guessed type int __fastcall calloc(_DWORD);
// 1C9844: using guessed type int dword_1C9844[256];
// 1C9C44: using guessed type int dword_1C9C44;


//----- (0015D399) --------------------------------------------------------
int sub_15D399()
{
  int result; // eax
  int i; // [esp+0h] [ebp-8h]

  for ( i = 0; i < 257; ++i )
  {
    nfree(dword_1C9844[i]);
    result = i;
  }
  return result;
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);
// 1C9844: using guessed type int dword_1C9844[256];


//----- (0015D3E7) --------------------------------------------------------
int __fastcall sub_15D3E7(int a1, int a2)
{
  _DWORD *v2; // eax
  int result; // eax
  int *v4; // ebx
  int i; // [esp+8h] [ebp-4h]
  int j; // [esp+8h] [ebp-4h]

  for ( i = a1 + 1; i <= 258; ++i )
  {
    v2 = (_DWORD *)(4 * i + dword_1C9844[a2]);
    ++*v2;
  }
  result = dword_1C9844[a2];
  if ( *(int *)(result + 1032) >= 0x3FFF )
  {
    for ( j = 1; j <= 258; ++j )
    {
      v4 = (int *)(4 * j + dword_1C9844[a2]);
      *v4 /= 2;
    }
    *(_DWORD *)(dword_1C9844[a2] + 1028) = *(_DWORD *)(dword_1C9844[a2] + 1024) + 1;
    result = dword_1C9844[a2];
    *(_DWORD *)(result + 1032) = *(_DWORD *)(result + 1028) + 1;
  }
  return result;
}
// 1C9844: using guessed type int dword_1C9844[256];


//----- (0015D4E1) --------------------------------------------------------
int __fastcall sub_15D4E1(int a1, int a2, _WORD *a3)
{
  a3[2] = *(_WORD *)(dword_1C9844[a2] + 1032);
  *a3 = *(_WORD *)(4 * a1 + dword_1C9844[a2]);
  a3[1] = *(_WORD *)(4 * a1 + dword_1C9844[a2] + 4);
  if ( *a3 < a3[1] )
    return 0;
  *a3 = *(_WORD *)(dword_1C9844[a2] + 1024);
  a3[1] = *(_WORD *)(dword_1C9844[a2] + 1028);
  return 1;
}
// 1C9844: using guessed type int dword_1C9844[256];


//----- (0015D5B2) --------------------------------------------------------
int __fastcall sub_15D5B2(int a1, int a2)
{
  int16_t v2; // dx
  int result; // eax

  v2 = *(_WORD *)(dword_1C9844[a1] + 1032);
  result = a2;
  *(_WORD *)(a2 + 4) = v2;
  return result;
}
// 1C9844: using guessed type int dword_1C9844[256];


//----- (0015D5F1) --------------------------------------------------------
int __fastcall sub_15D5F1(int a1, int a2, _WORD *a3)
{
  int i; // [esp+Ch] [ebp-8h]

  for ( i = 0; a1 >= *(_DWORD *)(4 * i + dword_1C9844[a2] + 4); ++i )
    ;
  a3[1] = *(_WORD *)(4 * i + dword_1C9844[a2] + 4);
  *a3 = *(_WORD *)(4 * i + dword_1C9844[a2]);
  return i;
}
// 1C9844: using guessed type int dword_1C9844[256];


//----- (0015D68B) --------------------------------------------------------
void sub_15D68B()
{
  word_1C9C4A = 0;
  word_1C9C48 = -1;
  dword_1C9840 = 0;
}
// 1C9840: using guessed type int dword_1C9840;
// 1C9C48: using guessed type int16_t word_1C9C48;
// 1C9C4A: using guessed type int16_t word_1C9C4A;


//----- (0015D6C6) --------------------------------------------------------
int __fastcall sub_15D6C6(uint8_t ***a1)
{
  int v1; // eax

  sub_162B06(a1, word_1C9C4A & 0x4000);
  ++dword_1C9840;
  while ( 1 )
  {
    v1 = dword_1C9840--;
    if ( v1 <= 0 )
      break;
    sub_162B06(a1, ~word_1C9C4A & 0x4000);
  }
  return sub_162CA3(a1, 0, 16);
}
// 1C9840: using guessed type int dword_1C9840;
// 1C9C4A: using guessed type int16_t word_1C9C4A;


//----- (0015D741) --------------------------------------------------------
int __fastcall sub_15D741(uint8_t ***a1, uint16_t *a2)
{
  int result; // eax
  int v4; // [esp+8h] [ebp-4h]

  v4 = (uint16_t)word_1C9C48 - (uint16_t)word_1C9C4A + 1;
  word_1C9C48 = word_1C9C4A + v4 * a2[1] / a2[2] - 1;
  word_1C9C4A += v4 * *a2 / a2[2];
  while ( (word_1C9C48 & 0x8000) == (word_1C9C4A & 0x8000) )
  {
    sub_162B06(a1, word_1C9C48 & 0x8000);
    while ( dword_1C9840 > 0 )
    {
      sub_162B06(a1, ~word_1C9C48 & 0x8000);
      --dword_1C9840;
    }
LABEL_11:
    word_1C9C4A *= 2;
    word_1C9C48 *= 2;
    LOBYTE(word_1C9C48) = word_1C9C48 | 1;
  }
  result = word_1C9C4A & 0x4000;
  if ( (word_1C9C4A & 0x4000) != 0 )
  {
    result = word_1C9C48 & 0x4000;
    if ( (word_1C9C48 & 0x4000) == 0 )
    {
      ++dword_1C9840;
      HIBYTE(word_1C9C4A) &= 0x3Fu;
      HIBYTE(word_1C9C48) |= 0x40u;
      goto LABEL_11;
    }
  }
  return result;
}
// 1C9840: using guessed type int dword_1C9840;
// 1C9C48: using guessed type int16_t word_1C9C48;
// 1C9C4A: using guessed type int16_t word_1C9C4A;


//----- (0015D8AB) --------------------------------------------------------
int __fastcall sub_15D8AB(int a1)
{
  return (*(uint16_t *)(a1 + 4) * (unk_1C9C4C - (uint16_t)word_1C9C4A + 1) - 1)
       / ((uint16_t)word_1C9C48 - (uint16_t)word_1C9C4A + 1);
}
// 1C9C48: using guessed type int16_t word_1C9C48;
// 1C9C4A: using guessed type int16_t word_1C9C4A;


//----- (0015D920) --------------------------------------------------------
_DWORD *__fastcall sub_15D920(_DWORD *result, int a2)
{
  _DWORD *v2; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  v2 = result;
  unk_1C9C4C = 0;
  for ( i = 0; i < 16; ++i )
  {
    unk_1C9C4C *= 2;
    unk_1C9C4C += sub_162E63(v2, a2);
    result = (_DWORD *)i;
  }
  word_1C9C4A = 0;
  word_1C9C48 = -1;
  return result;
}
// 1C9C48: using guessed type int16_t word_1C9C48;
// 1C9C4A: using guessed type int16_t word_1C9C4A;


//----- (0015D98E) --------------------------------------------------------
int __fastcall sub_15D98E(_DWORD *a1, uint16_t *a2)
{
  int v2; // edx
  int result; // eax
  int v5; // [esp+8h] [ebp-4h]

  v5 = (uint16_t)word_1C9C48 - (uint16_t)word_1C9C4A + 1;
  word_1C9C48 = word_1C9C4A + v5 * a2[1] / a2[2] - 1;
  word_1C9C4A += v5 * *a2 / a2[2];
  while ( 1 )
  {
    v2 = word_1C9C48 & 0x8000;
    if ( v2 == (word_1C9C4A & 0x8000) )
      goto LABEL_7;
    result = word_1C9C4A & 0x4000;
    if ( result != 0x4000 )
      return result;
    result = word_1C9C48 & 0x4000;
    if ( (word_1C9C48 & 0x4000) != 0 )
      return result;
    byte_1C9C4D ^= 0x40u;
    HIBYTE(word_1C9C4A) &= 0x3Fu;
    HIBYTE(word_1C9C48) |= 0x40u;
LABEL_7:
    word_1C9C4A *= 2;
    word_1C9C48 *= 2;
    LOBYTE(word_1C9C48) = word_1C9C48 | 1;
    unk_1C9C4C *= 2;
    unk_1C9C4C += sub_162E63(a1, v2);
  }
}
// 1C9C48: using guessed type int16_t word_1C9C48;
// 1C9C4A: using guessed type int16_t word_1C9C4A;
// 1C9C4D: using guessed type char byte_1C9C4D;


//----- (0015DBCA) --------------------------------------------------------
int sub_15DBCA()
{
  MEMORY[0x110] = dword_18AC86;
  MEMORY[0x76EC] = dword_18AC8A;
  MEMORY[0x76F0] = dword_18AC8E;
  MEMORY[0x76F4] = word_18AC92;
  word_18AC74 = word_18AC82;
  word_18AC72 = 256;
  word_18AC78 = word_18AC82;
  word_18AC76 = dword_18AC7E + 512;
  /* __asm: int     31h; DPMI Services   ax=func xxxxh */ DECOMP_TODO("inline asm");
  return dword_18AC86;
}
// 18AC72: using guessed type int16_t word_18AC72;
// 18AC74: using guessed type int16_t word_18AC74;
// 18AC76: using guessed type int16_t word_18AC76;
// 18AC78: using guessed type int16_t word_18AC78;
// 18AC7E: using guessed type int dword_18AC7E;
// 18AC82: using guessed type int16_t word_18AC82;
// 18AC86: using guessed type int dword_18AC86;
// 18AC8A: using guessed type int dword_18AC8A;
// 18AC8E: using guessed type int dword_18AC8E;
// 18AC92: using guessed type int16_t word_18AC92;


//----- (0015DCBA) --------------------------------------------------------
int16_t __fastcall sub_15DCBA( int result)
{
  MEMORY[0x10C] = result;
  return result;
}


//----- (0015DCEE) --------------------------------------------------------
void sub_15DCEE()
{
  dword_18AC94 = 276;
  dword_18AC98 = 278;
  dword_18AC9C = 280;
  dword_18ACA0 = 282;
}
// 18AC94: using guessed type int dword_18AC94;
// 18AC98: using guessed type int dword_18AC98;
// 18AC9C: using guessed type int dword_18AC9C;
// 18ACA0: using guessed type int dword_18ACA0;


//----- (0015DD1A) --------------------------------------------------------
void sub_15DD1A()
{
  dword_18ACB4 = 270;
  dword_18ACA4 = 15282;
  dword_18ACA8 = 15284;
  dword_18ACAC = 15286;
  dword_18ACB0 = 15288;
}
// 18ACA4: using guessed type int dword_18ACA4;
// 18ACA8: using guessed type int dword_18ACA8;
// 18ACAC: using guessed type int dword_18ACAC;
// 18ACB0: using guessed type int dword_18ACB0;
// 18ACB4: using guessed type int dword_18ACB4;


//----- (0015DD55) --------------------------------------------------------
void sub_15DD55()
{
  int v0; // eax
  int v1; // ecx
  uint16_t v2; // dx
  unsigned int v3; // esi
  uint8_t *v4; // edi
  unsigned int v5; // ebx
  uint8_t v6; // dh
  int v7; // ecx
  unsigned int v8; // esi
  uint8_t v9; // dl
  uint16_t v10; // cx

  v0 = dword_18ACBC;
  v1 = dword_18ACC0;
  v2 = hr_readgsword(dword_18AC9C);
  v3 = v2 + dword_18ACA0;
  if ( dword_18ACC0 + (unsigned int)v2 >= 0x3A34 )
  {
    hr_writegsword(v3, 0xFFFu);
    v3 = dword_18ACA0;
    hr_writegsword(dword_18AC9C, 0);
  }
  v4 = (uint8_t *)v0;
  hr_writegsdword(v3, dword_18ACC0);
  v5 = v3;
  v6 = 0;
  v7 = v1 - 4;
  v8 = v3 + 4;
  do
  {
    v9 = *v4++;
    v6 += v9;
    hr_writegsbyte(v8++, v9);
    --v7;
  }
  while ( v7 );
  hr_writegsbyte(v5 + 2, v6);
  v10 = dword_18ACC0;
  hr_addgsword(dword_18AC9C, dword_18ACC0);
  hr_addgsword(dword_18AC94, v10);
}
// 18AC94: using guessed type int dword_18AC94;
// 18AC9C: using guessed type int dword_18AC9C;
// 18ACA0: using guessed type int dword_18ACA0;
// 18ACBC: using guessed type int dword_18ACBC;
// 18ACC0: using guessed type int dword_18ACC0;


//----- (0015DDE1) --------------------------------------------------------
bool sub_15DDE1()
{
  return hr_readgsword(dword_18ACA4) == 0;
}
// 18ACA4: using guessed type int dword_18ACA4;


//----- (0015DE09) --------------------------------------------------------
int sub_15DE09()
{
  uint16_t v1; // dx
  unsigned int v2; // esi
  unsigned int v3; // ecx
  uint8_t *v4; // edi
  int v5; // ecx
  unsigned int v6; // eax
  char v7; // dh
  unsigned int v8; // esi
  uint8_t v9; // dl
  _BOOL1 v10; // zf
  uint16_t v11; // [esp-28h] [ebp-28h]

  if ( !hr_readgsword(dword_18ACA4) )
    return 2;
  hr_writegsword(dword_18ACB4, 1u);
  v1 = hr_readgsword(dword_18ACA8);
  if ( v1 >= 0x3A97u )
    goto LABEL_10;
  v2 = v1 + dword_18ACB0;
  v3 = hr_readgsword(v2);
  if ( (uint16_t)v3 == 4095 )
    goto LABEL_7;
  if ( (uint16_t)v3 + (unsigned int)v1 >= 0x3A97 )
  {
LABEL_10:
    _disable();
    hr_writegsword(dword_18ACA4, 0);
    hr_writegsword(dword_18ACA8, 0);
    hr_writegsword(dword_18ACAC, dword_18ACB0);
    _enable();
    hr_writegsword(dword_18ACB4, 0);
    return 0;
  }
  if ( (_WORD)v3 == 4095 )
  {
LABEL_7:
    hr_writegsword(dword_18ACA8, 0);
    v2 = dword_18ACB0;
    v3 = hr_readgsword(dword_18ACB0);
  }
  if ( v3 > 0x1F4 || v3 <= 4 )
    goto LABEL_10;
  v4 = (uint8_t *)dword_18ACBC;
  v11 = v3;
  v5 = v3 - 4;
  dword_18ACC0 = v5;
  v6 = v2;
  v7 = 0;
  v8 = v2 + 4;
  do
  {
    v9 = hr_readgsbyte(v8++);
    v7 += v9;
    *v4++ = v9;
    --v5;
  }
  while ( v5 );
  hr_addgsword(dword_18ACA8, v11);
  hr_writegsword(dword_18ACA4, hr_readgsword(dword_18ACA4) - v11);
  v10 = v7 == (char)hr_readgsbyte(v6 + 2);
  hr_writegsword(dword_18ACB4, 0);
  if ( v10 )
    return 1;
  else
    return 3;
}
// 18ACA4: using guessed type int dword_18ACA4;
// 18ACA8: using guessed type int dword_18ACA8;
// 18ACAC: using guessed type int dword_18ACAC;
// 18ACB0: using guessed type int dword_18ACB0;
// 18ACB4: using guessed type int dword_18ACB4;
// 18ACBC: using guessed type int dword_18ACBC;
// 18ACC0: using guessed type int dword_18ACC0;


//----- (0015E0F0) --------------------------------------------------------
int __fastcall sub_15E0F0(unsigned int a1)
{
  if ( a1 > 0x22 )
    return 0;
  else
    // DECOMP_TODO - KRITICKE (vlna 06): puvodni "calloc(1)" mela jen JEDEN
    // parametr (stejna trida chyby jako fopen/fseek/calloc vyse), a navic
    // vysledek se u sesterske funkce sub_15E124 (o par radku nize) pouziva
    // jako RETEZCOVY BUFFER - volajici do nej zapisuji pres itoa()/strcpy()/
    // rucni konkatenaci desitky bajtu (overeno v orion_part_22.c, napr.
    // "*(_DWORD*)v5 = v4;" hned prvni zapis prekracuje 1 bajt). Puvodni
    // "1" byl temer jiste jen JEDNA ze dvou ztracenych hodnot (count NEBO
    // size), ne skutecny pozadavek na 1 bajt - alokace 1 bajtu by tu
    // zpusobovala poskozeni haldy. Zatim nastaveno na 256 bajtu jako
    // bezpecny (velkorysy, ale nikoliv overeny) zastupny odhad na zaklade
    // pozorovaneho pouziti (kratke prikazove/cestovni retezce) - VYZADUJE
    // dohledani VSECH volajicich mist sub_15E124/sub_15E0F0 a zjisteni
    // skutecne max. delky pred oznacenim za vyresene, viz PROGRESS.md.
    return (int)calloc(1, 256);
}
// 16321B: using guessed type int __fastcall calloc(_DWORD);


//----- (0015E108) --------------------------------------------------------
int __fastcall sub_15E108(unsigned int a1, int a2)
{
  int result; // eax

  result = a2;
  if ( a1 <= 0x22 )
  {
    if ( a2 )
      return nfree(a2);
  }
  return result;
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);


//----- (0015E124) --------------------------------------------------------
int sub_15E124()
{
  // DECOMP_TODO - KRITICKE: viz podrobne vysvetleni u sub_15E0F0 o par
  // radku vyse - stejny bug, stejny docasny odhad (256 bajtu), stejne
  // nutna nasledna verifikace skutecne max. delky pouzivaneho retezce.
  return (int)calloc(1, 256);
}
// 16321B: using guessed type int __fastcall calloc(_DWORD);


//----- (0015E154) --------------------------------------------------------
int __fastcall sub_15E154(unsigned int a1, int a2)
{
  int result; // eax

  result = a2;
  if ( a1 <= 0x22 )
    return nfree(a2);
  return result;
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);


//----- (0015E184) --------------------------------------------------------
int __fastcall sub_15E184(unsigned int a1, int a2)
{
  int result; // eax

  result = a2;
  if ( a1 <= 0x22 )
    return nfree(a2);
  return result;
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);


//----- (0015E1A0) --------------------------------------------------------
int __fastcall sub_15E1A0(int a1, int a2, int a3, int a4)
{
  int v5; // ebx
  int v6; // eax
  int v7; // edx
  int result; // eax

  v5 = sub_15E270(a1, a1, a3, a4);
  v6 = 55 * a1;
  v7 = v5 + 55 * a1;
  while ( 1 )
  {
    result = sub_15E270(v6, v7, 0, a4);
    if ( v7 <= result )
      break;
    v6 = off_18ACD8();
  }
  return result;
}
// 18ACD8: using guessed type int (*off_18ACD8)();


//----- (0015E1D4) --------------------------------------------------------
int __fastcall sub_15E1D4(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int v6; // edx

  result = sub_15E270(a1, a2, a1, a4);
  v6 = result + a2;
  while ( v6 > sub_15E270(result, v6, a1, a4) )
  {
    result = off_18ACD8();
    if ( result < 0 )
      return result;
  }
  return 0;
}
// 18ACD8: using guessed type int (*off_18ACD8)();


//----- (0015E200) --------------------------------------------------------
int __fastcall sub_15E200(int a1, char *a2, int a3)
{
  int v5; // edx

  *(_DWORD *)(a1 + 23) = 0;
  if ( a3 >= -2 && a3 <= 255 )
  {
    (*(void (__fastcall **)(int, char *, unsigned int))(a1 + 87))(a1, a2, strlen(a2));
    if ( *(int *)(a1 + 14) < 0 )
      return *(_DWORD *)(a1 + 14);
    if ( a3 < 0 )
    {
      if ( a3 != -2 )
        return *(_DWORD *)(a1 + 14);
      (*(void (__fastcall **)(int, int))(a1 + 35))(a1, 13);
      v5 = 10;
    }
    else
    {
      v5 = a3;
    }
    (*(void (__fastcall **)(int, int))(a1 + 35))(a1, v5);
    return *(_DWORD *)(a1 + 14);
  }
  *(_DWORD *)(a1 + 14) = -7;
  return *(_DWORD *)(a1 + 14);
}


//----- (0015E270) --------------------------------------------------------
int __fastcall sub_15E270(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+4h] [ebp-18h]
  int v6; // [esp+8h] [ebp-14h] BYREF
  _DWORD v7[4]; // [esp+Ch] [ebp-10h] BYREF

  v7[2] = a4;
  LOWORD(v5) = sub_15EB44();
  do
  {
    sub_15E3A8((int)&v6, 4, v5, 1132, 0x46Cu, v5, 4);
    sub_15E3A8((int)v7, 4, v5, 1132, 0x46Cu, v5, 4);
  }
  while ( v6 != v7[0] );
  if ( v6 < dword_18ACCC )
    dword_18ACD0 += 86517200;
  dword_18ACCC = v6;
  return dword_18ACD0 + 55 * v6;
}
// 15E29B: variable 'v5' is possibly undefined
// 18ACCC: using guessed type int dword_18ACCC;
// 18ACD0: using guessed type int dword_18ACD0;


//----- (0015E2F0) --------------------------------------------------------
int __fastcall sub_15E2F0(int a1, int a2)
{
  bool v2; // eax

  if ( dword_1897CC != 0xFFFF )
  {
    while ( 1 )
    {
      v2 = sub_16356C(a1, a2);
      if ( !v2 )
        break;
      a1 = sub_1634AC(v2, a2);
      if ( a1 == dword_1897CC )
        return -16;
    }
  }
  return 0;
}
// 1897CC: using guessed type int dword_1897CC;


//----- (0015E324) --------------------------------------------------------
int (*__fastcall sub_15E324(int (*result)()))()
{
  off_18ACD4[0] = result;
  return result;
}
// 18ACD4: using guessed type int (*off_18ACD4[2])();


//----- (0015E330) --------------------------------------------------------
int sub_15E330()
{
  sub_15F300();
  sub_15F32C();
  return 0;
}


//----- (0015E340) --------------------------------------------------------
int (*__fastcall sub_15E340(int (*result)()))()
{
  off_18ACD8 = result;
  return result;
}
// 18ACD8: using guessed type int (*off_18ACD8)();


//----- (0015E350) --------------------------------------------------------
int __stdcall sub_15E350(unsigned int a1, int a2, unsigned int a3, int a4)
{
  int result; // eax

  result = a4;
  while ( --result != -1 )
    hr_writegsbyte(a1++, a3);
  return result;
}


//----- (0015E37C) --------------------------------------------------------
void __cdecl sub_15E37C(unsigned int a1, int a2, uint8_t *a3, int a4)
{
  int v6; // ecx

  while ( 1 )
  {
    v6 = a4--;
    if ( v6 <= 0 )
      break;
    hr_writegsbyte(a1++, *a3++);
  }
  JUMPOUT(0x15E375);
}
// 15E390: control flows out of bounds to 15E375


//----- (0015E3A8) --------------------------------------------------------
int __fastcall sub_15E3A8(int result, int a2, int a3, int a4, unsigned int a5, int a6, int a7)
{
  int v8; // ebx
  uint8_t v9; // bl

  while ( 1 )
  {
    v8 = a7--;
    if ( v8 <= 0 )
      break;
    ++result;
    v9 = hr_readgsbyte(a5++);
    *(_BYTE *)(result - 1) = v9;
  }
  return result;
}


//----- (0015E3D8) --------------------------------------------------------
int sub_15E3D8()
{
  return __CS__;
}


//----- (0015E3E4) --------------------------------------------------------
int sub_15E3E4()
{
  return __DS__;
}


//----- (0015E3F0) --------------------------------------------------------
int __fastcall sub_15E3F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // eax
  int v11; // ebp
  int v12; // ecx
  int v13; // ebx
  int v14; // edx
  unsigned int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edx
  int v20; // esi
  int v21; // eax
  uint8_t v22[6]; // [esp+0h] [ebp-68h] BYREF
  int v23; // [esp+6h] [ebp-62h]
  int v24; // [esp+Ah] [ebp-5Eh]
  int16_t v25; // [esp+Eh] [ebp-5Ah]
  int v26; // [esp+10h] [ebp-58h]
  int v27; // [esp+14h] [ebp-54h]
  int16_t v28; // [esp+18h] [ebp-50h]
  int v29; // [esp+1Ah] [ebp-4Eh]
  int v30; // [esp+1Eh] [ebp-4Ah]
  int v31; // [esp+22h] [ebp-46h]
  int v32; // [esp+26h] [ebp-42h]
  int v33; // [esp+2Ah] [ebp-3Eh]
  int v34; // [esp+2Eh] [ebp-3Ah]
  int v35; // [esp+32h] [ebp-36h]
  int v36; // [esp+36h] [ebp-32h]
  int v37; // [esp+3Ah] [ebp-2Eh]
  int v38; // [esp+40h] [ebp-28h]
  int v39; // [esp+44h] [ebp-24h]
  int64_t v40; // [esp+48h] [ebp-20h]
  int v41; // [esp+50h] [ebp-18h]
  int v42; // [esp+54h] [ebp-14h]

  v42 = a1;
  v41 = a2;
  LODWORD(v40) = a3;
  if ( dword_18ACDC )
  {
    sub_15E68C();
    dword_18ACDC = 0;
    v10 = atexit(sub_15E7C8);
    if ( v42 != 27 && v42 != 35 )
      sub_16371C(v10, a2, 0, v42, 0);
  }
  v11 = -1;
  v12 = v42;
  v13 = 0;
  v14 = 0;
  do
  {
    sub_15E3A8(
      (int)v22,
      v14,
      v13,
      v12,
      *(int *)((char *)&dword_1C9C70 + v14),
      *(int *)((char *)&dword_1C9C74 + v14),
      62);
    if ( v31 == v12 )
      return -39;
    if ( !v31 && v11 == -1 )
      v11 = v13;
    ++v13;
    v14 += 6;
  }
  while ( v13 < 10 );
  if ( v11 == -1 )
    return -38;
  v16 = *(int *)((char *)&dword_1C9C70 + 6 * v11);
  v17 = v41;
  sub_15E3A8((int)v22, v16, v41, v12, v16, *(int *)((char *)&dword_1C9C74 + 6 * v11), 62);
  if ( v17 )
  {
    v25 = sub_15E3D8();
  }
  else
  {
    v16 = 0;
    v25 = 0;
  }
  v24 = v41;
  v27 = a5;
  v28 = a6;
  v29 = sub_15EBF0(v41, v16, v17, a6, a5, a6);
  v30 = a7;
  v33 = a8;
  v34 = a9;
  v35 = a10;
  v31 = v42;
  v36 = 0;
  v26 = v40;
  v37 = 0;
  sub_15EC70(v42, (int)v22);
  v18 = *(_DWORD *)((char *)&v40 + 2);
  v23 = sub_15ECC8(v42);
  if ( (_WORD)v18 )
  {
    HIWORD(v40) = HIWORD(dword_1C9CAC);
    WORD2(v40) = *((_WORD *)&off_18B04A + 2 * v11);
    WORD2(v40) -= (uint16_t)&byte_168130;
  }
  else
  {
    HIDWORD(v40) = 0;
  }
  v19 = v41;
  if ( v41 )
  {
    LOWORD(v39) = sub_15E3D8();
    v38 = (int)*(&off_18B018 + v11);
  }
  else
  {
    v38 = 0;
    LOWORD(v39) = 0;
  }
  sub_15ED18(v42, v19, v18, SHIDWORD(v40), v38, v39, SHIDWORD(v40));
  sub_168545();
  if ( a9 )
  {
    v20 = a9 + 1;
LABEL_27:
    v21 = sub_168549(v20);
    v32 = v21 & a10;
    sub_168560(v20, ~a10 & v21);
    goto LABEL_28;
  }
  if ( a8 )
  {
    v20 = a8 + 1;
    goto LABEL_27;
  }
LABEL_28:
  sub_15E37C(*(int *)((char *)&dword_1C9C70 + 6 * v11), *(int *)((char *)&dword_1C9C74 + 6 * v11), v22, 62);
  sub_168541();
  return 0;
}
// 144906: using guessed type int __fastcall atexit(_DWORD);
// 168130: using guessed type char byte_168130;
// 18ACDC: using guessed type int dword_18ACDC;
// 18B018: using guessed type _UNKNOWN *off_18B018;
// 18B04A: using guessed type _UNKNOWN *off_18B04A;
// 1C9C70: using guessed type int dword_1C9C70;
// 1C9C74: using guessed type int dword_1C9C74;
// 1C9CAC: using guessed type int dword_1C9CAC;


//----- (0015E650) --------------------------------------------------------
int __usercall sub_15E650(int a1, int a2)
{
  int16_t v3; // [esp+4h] [ebp-10h]

  v3 = dword_1C9CB6;
  *(_DWORD *)a2 = dword_1C9CB2 + a1 - (_DWORD)&byte_168130;
  *(_WORD *)(a2 + 4) = v3;
  return a2;
}
// 168130: using guessed type char byte_168130;
// 1C9CB2: using guessed type int dword_1C9CB2;
// 1C9CB6: using guessed type int dword_1C9CB6;


//----- (0015E68C) --------------------------------------------------------
int sub_15E68C()
{
  int v0; // eax
  int v1; // edx
  int v2; // ebx
  char *v3; // edx
  char *v4; // edi
  int v5; // ecx
  unsigned int v7; // [esp-10h] [ebp-48h]
  int16_t v8; // [esp-Ch] [ebp-44h]
  int v9; // [esp+0h] [ebp-38h] BYREF
  int v10; // [esp+4h] [ebp-34h]
  int v11; // [esp+8h] [ebp-30h]
  int v12; // [esp+Ch] [ebp-2Ch]
  int v13; // [esp+10h] [ebp-28h] BYREF
  int16_t v14; // [esp+14h] [ebp-24h]
  _UNKNOWN **v15; // [esp+18h] [ebp-20h]
  int v16; // [esp+1Ch] [ebp-1Ch]

  if ( !dword_18ACE0 )
  {
    dword_18ACE0 = 1;
    v0 = sub_15EA74((char *)&dword_16853C - &byte_168130 + 2, (int)&v9);
    dword_1C9CB2 = v9;
    LOWORD(dword_1C9CB6) = v10;
    v1 = (char *)&dword_16853C - &byte_168130 + 1;
    v2 = 0;
    dword_1C9CAC = sub_15EBF0(v0, v1, 0, v10, v9, v10);
    LOWORD(v12) = dword_1C9CB6;
    v8 = dword_1C9CB6;
    v11 = dword_1C9CB2 + byte_168131 - &byte_168130;
    v7 = dword_1C9CB2;
    *(_DWORD *)byte_18B040 = v11;
    *(_WORD *)&byte_18B040[4] = dword_1C9CB6;
    sub_15E37C(v7, v8, (uint8_t *)&byte_168130, v1);
    v3 = byte_168131;
    do
    {
      sub_15E650((int)v3, (int)&v13);
      v4 = (char *)&dword_1C9C70 + v2;
      v2 += 6;
      v3 += 62;
      *(_DWORD *)v4 = v13;
      *((_WORD *)v4 + 2) = v14;
    }
    while ( v2 != 60 );
    LOWORD(v16) = sub_15E3D8();
    v5 = v16;
    sub_15EDB4(
      (char *)dword_168694 - &byte_168540 + 1,
      (int)v3,
      (int)&byte_168540,
      v16,
      (int)&byte_168540,
      v16,
      (char *)dword_168694 - &byte_168540 + 1);
    LOWORD(v16) = sub_15E3E4();
    v15 = &off_18B018;
    sub_15EDB4(
      &unk_18B072 - (_UNKNOWN *)&off_18B018 + 1,
      (int)v3,
      (int)&byte_168540,
      v5,
      (int)&off_18B018,
      v16,
      &unk_18B072 - (_UNKNOWN *)&off_18B018 + 1);
    word_18B074 = sub_15E3E4();
  }
  return 1;
}
// 168130: using guessed type char byte_168130;
// 16853C: using guessed type int dword_16853C;
// 168540: using guessed type char byte_168540;
// 168694: using guessed type int dword_168694[603];
// 18ACE0: using guessed type int dword_18ACE0;
// 18B018: using guessed type _UNKNOWN *off_18B018;
// 18B074: using guessed type int16_t word_18B074;
// 1C9C70: using guessed type int dword_1C9C70;
// 1C9CAC: using guessed type int dword_1C9CAC;
// 1C9CB2: using guessed type int dword_1C9CB2;
// 1C9CB6: using guessed type int dword_1C9CB6;


//----- (0015E7C8) --------------------------------------------------------
int __fastcall sub_15E7C8(int a1, int a2, int a3, int a4)
{
  int i; // edx
  int result; // eax
  _BYTE v6[34]; // [esp+0h] [ebp-50h] BYREF
  int v7; // [esp+22h] [ebp-2Eh]
  int v8; // [esp+48h] [ebp-8h]

  v8 = a4;
  sub_15EF04();
  for ( i = 54; i != -6; i -= 6 )
  {
    result = sub_15E3A8(
               (int)v6,
               i,
               *(int *)((char *)&dword_1C9C74 + i),
               *(int *)((char *)&dword_1C9C70 + i),
               *(int *)((char *)&dword_1C9C70 + i),
               *(int *)((char *)&dword_1C9C74 + i),
               62);
    if ( v7 )
      result = sub_15E814(v7);
  }
  return result;
}
// 1C9C70: using guessed type int dword_1C9C70;
// 1C9C74: using guessed type int dword_1C9C74;


//----- (0015E814) --------------------------------------------------------
int __fastcall sub_15E814(int a1)
{
  int v2; // esi
  int i; // edx
  int v4; // ecx
  int v6; // eax
  int v7; // eax
  unsigned int v8; // [esp-8h] [ebp-68h]
  int v9; // [esp-4h] [ebp-64h]
  int v10; // [esp+8h] [ebp-58h] BYREF
  _BYTE v11[6]; // [esp+Ch] [ebp-54h]
  int v12; // [esp+1Ch] [ebp-44h]
  int v13; // [esp+20h] [ebp-40h]
  void (__stdcall *v14)(int, int); // [esp+26h] [ebp-3Ah]
  int v15; // [esp+2Ah] [ebp-36h]
  int v16; // [esp+2Eh] [ebp-32h]
  int v17; // [esp+32h] [ebp-2Eh]
  int v18; // [esp+36h] [ebp-2Ah]
  int v19; // [esp+3Ah] [ebp-26h]

  v2 = 0;
  for ( i = 0; i < 60; i += 6 )
  {
    v4 = *(int *)((char *)&dword_1C9C74 + i);
    sub_15E3A8((int)&v10, i, a1, v4, *(int *)((char *)&dword_1C9C70 + i), v4, 62);
    if ( a1 == v15 )
      break;
    ++v2;
  }
  if ( v2 == 10 )
    return -38;
  if ( v14 )
  {
    i = v13;
    v4 = v12;
    v14(v12, v13);
  }
  sub_15ED18(a1, i, a1, v4, v10, *(int *)v11, *(int *)&v11[2]);
  if ( v18 )
  {
    v6 = sub_168549(v18 + 1);
    sub_168560(v18 + 1, v16 | ~v19 & v6);
  }
  else if ( v17 )
  {
    v7 = sub_168549(v17 + 1);
    sub_168560(v17 + 1, v16 | ~v19 & v7);
  }
  v9 = *(int *)((char *)&dword_1C9C74 + 6 * v2);
  v8 = *(int *)((char *)&dword_1C9C70 + 6 * v2);
  v15 = 0;
  sub_15E37C(v8, v9, (uint8_t *)&v10, 62);
  return 0;
}
// 1C9C70: using guessed type int dword_1C9C70;
// 1C9C74: using guessed type int dword_1C9C74;


//----- (0015E918) --------------------------------------------------------
int __usercall sub_15E918(int a1, int a2)
{
  int v4; // esi
  char *v5; // esi
  _BYTE v7[34]; // [esp+0h] [ebp-64h] BYREF
  int v8; // [esp+22h] [ebp-42h]
  int16_t v9; // [esp+44h] [ebp-20h]
  int v10; // [esp+48h] [ebp-1Ch]
  int16_t v11; // [esp+4Ch] [ebp-18h]

  v11 = 0;
  v4 = 0;
  v10 = 0;
  while ( 1 )
  {
    sub_15E3A8((int)v7, a1, a2, 0, *(int *)((char *)&dword_1C9C70 + v4), *(int *)((char *)&dword_1C9C74 + v4), 62);
    if ( a1 == v8 )
      break;
    v4 += 6;
    if ( v4 >= 60 )
      goto LABEL_5;
  }
  v5 = (char *)&dword_1C9C70 + v4;
  v10 = *(_DWORD *)v5;
  v11 = *((_WORD *)v5 + 2);
LABEL_5:
  v9 = v11;
  *(_DWORD *)a2 = v10;
  *(_WORD *)(a2 + 4) = v9;
  return a2;
}
// 1C9C70: using guessed type int dword_1C9C70;
// 1C9C74: using guessed type int dword_1C9C74;


//----- (0015E990) --------------------------------------------------------
int16_t __fastcall sub_15E990(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+0h] [ebp-40h] BYREF
  int v6; // [esp+4h] [ebp-3Ch]
  _BYTE *v7; // [esp+14h] [ebp-2Ch]
  int v8; // [esp+18h] [ebp-28h]
  int16_t v9; // [esp+1Ch] [ebp-24h] BYREF
  uint16_t v10; // [esp+1Eh] [ebp-22h]
  int v11; // [esp+22h] [ebp-1Eh]
  _BYTE v12[16]; // [esp+28h] [ebp-18h] BYREF
  int v13; // [esp+38h] [ebp-8h]

  v13 = a4;
  if ( !word_18ACE4 )
  {
    segread(&v9, 10, &v5);
    v5 = 10;
    v6 = v10;
    int386(49, &v5, &v5);
    if ( v8 == 1 )
      return 0;
    word_18ACE4 = v5;
    v6 = (uint16_t)v5;
    v5 = 11;
    segread(&v9, &v5, &v5);
    v9 = v11;
    v7 = v12;
    int386x(49, &v5);
    v5 = 11;
    segread(&v9, &v5, &v5);
    v6 = v10;
    v9 = v11;
    v7 = v12;
    int386x(49, &v5);
  }
  return word_18ACE4;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 144A4A: using guessed type int __fastcall int386x(_DWORD, _DWORD);
// 153EAF: using guessed type int __fastcall segread(_DWORD, _DWORD, _DWORD);
// 18ACE4: using guessed type int16_t word_18ACE4;


//----- (0015EA74) --------------------------------------------------------
int __usercall sub_15EA74(int a1, int a2)
{
  int16_t v4; // bp
  _DWORD v6[3]; // [esp+0h] [ebp-40h] BYREF
  int v7; // [esp+Ch] [ebp-34h]
  int v8; // [esp+18h] [ebp-28h]
  int16_t v9; // [esp+20h] [ebp-20h]
  unsigned int v10; // [esp+24h] [ebp-1Ch]
  int v11; // [esp+28h] [ebp-18h]

  LOWORD(v11) = 0;
  v6[0] = 256;
  v10 = 0;
  v6[1] = (a1 + 15) >> 4;
  int386(49, v6, v6);
  if ( !v8 )
  {
    LOWORD(v11) = v7;
    v4 = v7;
    sub_15EDB4(v10, (int)v6, (int)v6, a2, v10, v7, a1);
    sub_15E350(v10, v4, 0, a1);
  }
  v9 = v11;
  *(_DWORD *)a2 = v10;
  *(_WORD *)(a2 + 4) = v9;
  return a2;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);


