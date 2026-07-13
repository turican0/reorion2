#include "orion_common.h"

/* Adresni rozsah: 0x15EB04 - 0x164200  (200 funkci) */

//----- (0015EB04) --------------------------------------------------------
int __stdcall sub_15EB04(int a1, unsigned int a2)
{
  _DWORD v3[9]; // [esp+0h] [ebp-24h] BYREF

  v3[0] = 257;
  v3[3] = a2;
  int386(49, v3, v3);
  if ( v3[6] )
    return -33;
  else
    return 0;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);


//----- (0015EB44) --------------------------------------------------------
int16_t sub_15EB44()
{
  int v1; // [esp+0h] [ebp-30h] BYREF
  int v2; // [esp+4h] [ebp-2Ch]
  int v3; // [esp+8h] [ebp-28h]
  int v4; // [esp+Ch] [ebp-24h]

  if ( !word_18ACE6 )
  {
    v1 = 0;
    v3 = 1;
    int386(49, &v1, &v1);
    word_18ACE6 = v1;
    v3 = 0;
    v4 = 0;
    v2 = (uint16_t)v1;
    v1 = 7;
    int386(49, &v1, &v1);
    v4 = 0xFFFF;
    v2 = (uint16_t)word_18ACE6;
    v3 = 15;
    v1 = 8;
    int386(49, &v1, &v1);
  }
  return word_18ACE6;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 18ACE6: using guessed type int16_t word_18ACE6;


//----- (0015EBF0) --------------------------------------------------------
int __fastcall sub_15EBF0(int a1, int a2, int a3, int a4, int a5, unsigned int a6)
{
  int v6; // eax
  _DWORD v8[2]; // [esp+0h] [ebp-2Ch] BYREF
  int v9; // [esp+8h] [ebp-24h]
  int v10; // [esp+Ch] [ebp-20h]
  int v11; // [esp+18h] [ebp-14h]
  int v12; // [esp+1Ch] [ebp-10h]
  int v13; // [esp+24h] [ebp-8h]

  v13 = a4;
  v12 = 0;
  v8[1] = a6;
  v8[0] = 6;
  int386(49, v8, v8);
  if ( !v11 )
  {
    v6 = a5 + (uint16_t)v10 + ((uint16_t)v9 << 16);
    if ( v6 < (int)&loc_100000 )
    {
      HIWORD(v12) = (a5 + (uint16_t)v10 + ((uint16_t)v9 << 16)) >> 4;
      LOWORD(v12) = v6 & 0xF;
    }
  }
  return v12;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);


//----- (0015EC70) --------------------------------------------------------
int __usercall sub_15EC70(int a1, int a2)
{
  char v2; // dl
  _BYTE v4[4]; // [esp+0h] [ebp-44h] BYREF
  int v5; // [esp+4h] [ebp-40h]
  _DWORD v6[3]; // [esp+1Ch] [ebp-28h] BYREF
  int16_t v7; // [esp+2Ch] [ebp-18h]

  v2 = a1;
  segread(v6, a1, v4);
  v4[0] = v2;
  v4[1] = 53;
  int386x(33, v4);
  v7 = v6[0];
  *(_DWORD *)a2 = v5;
  *(_WORD *)(a2 + 4) = v7;
  return a2;
}
// 144A4A: using guessed type int __fastcall int386x(_DWORD, _DWORD);
// 153EAF: using guessed type int __fastcall segread(_DWORD, _DWORD, _DWORD);


//----- (0015ECC8) --------------------------------------------------------
int __fastcall sub_15ECC8( int a1)
{
  int v2; // [esp+0h] [ebp-28h] BYREF
  char v3; // [esp+4h] [ebp-24h]
  int v4; // [esp+8h] [ebp-20h]
  int v5; // [esp+Ch] [ebp-1Ch]
  int v6; // [esp+18h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-Ch]

  v3 = a1;
  v2 = 512;
  int386(49, &v2, &v2);
  if ( v6 )
    return 0;
  HIWORD(v7) = v4;
  LOWORD(v7) = v5;
  return v7;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);


//----- (0015ED18) --------------------------------------------------------
int __fastcall sub_15ED18(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // [esp+0h] [ebp-38h] BYREF
  char v9; // [esp+4h] [ebp-34h]
  int v10; // [esp+8h] [ebp-30h]
  int v11; // [esp+Ch] [ebp-2Ch]
  int v12; // [esp+18h] [ebp-20h]
  _BYTE v13[6]; // [esp+1Ch] [ebp-1Ch] BYREF
  int16_t v14; // [esp+22h] [ebp-16h]
  int v15; // [esp+28h] [ebp-10h]
  int v16; // [esp+30h] [ebp-8h]

  v16 = a4;
  v15 = a1;
  if ( (_WORD)a6 )
  {
    segread(v13, a6, a3);
    BYTE1(v8) = 37;
    v14 = a6;
    LOBYTE(v8) = v15;
    v11 = a5;
    int386x(33, &v8);
  }
  if ( HIWORD(a7) && (v9 = v15, v8 = 513, v10 = HIWORD(a7), v11 = (uint16_t)a7, int386(49, &v8, &v8), v12) )
    return -33;
  else
    return 0;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 144A4A: using guessed type int __fastcall int386x(_DWORD, _DWORD);
// 153EAF: using guessed type int __fastcall segread(_DWORD, _DWORD, _DWORD);


//----- (0015EDB4) --------------------------------------------------------
int __fastcall sub_15EDB4(int a1, int a2, int a3, int a4, int a5, unsigned int a6, int a7)
{
  int v8; // edx
  int v9; // [esp+0h] [ebp-2Ch] BYREF
  int v10; // [esp+4h] [ebp-28h]
  int v11; // [esp+8h] [ebp-24h]
  int v12; // [esp+Ch] [ebp-20h]
  int v13; // [esp+10h] [ebp-1Ch]
  int v14; // [esp+14h] [ebp-18h]
  int v15; // [esp+18h] [ebp-14h]
  int v16; // [esp+24h] [ebp-8h]

  v16 = a4;
  v9 = 6;
  v10 = a6;
  int386(49, &v9, &v9);
  if ( v15 )
    return -33;
  v8 = a5 + (uint16_t)v12 + (v11 << 16);
  v11 = (uint16_t)(a5 + v12);
  v13 = HIWORD(a7);
  v10 = HIWORD(v8);
  v14 = (uint16_t)a7;
  v9 = 1536;
  int386(49, &v9, &v9);
  if ( v15 )
    return -33;
  else
    return 0;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);


//----- (0015EE80) --------------------------------------------------------
int __fastcall sub_15EE80(int a1)
{
  *(_DWORD *)(a1 + 14) = -24;
  return *(_DWORD *)(a1 + 14);
}


//----- (0015EE8C) --------------------------------------------------------
int __fastcall sub_15EE8C(int a1, int a2, int a3, int a4, int a5)
{
  *(_DWORD *)(a1 + 14) = -24;
  return *(_DWORD *)(a1 + 14);
}


//----- (0015EE9C) --------------------------------------------------------
int __fastcall sub_15EE9C(int a1, void (__fastcall *a2)(_DWORD))
{
  ((void (__fastcall *)(char *, void (__fastcall *)(_DWORD), int))a2)(aPortDumpNotSup, a2, a1);
  a2(&unk_17C8CC);
  *(_DWORD *)(a1 + 14) = -24;
  return *(_DWORD *)(a1 + 14);
}


//----- (0015EEC4) --------------------------------------------------------
int __fastcall sub_15EEC4(int a1)
{
  int v2; // eax
  int *i; // ebx

  v2 = dword_18ACE8;
  for ( i = &dword_18ACE8; v2; v2 = *(_DWORD *)(v2 + 6) )
  {
    if ( v2 == a1 )
      break;
    i = (int *)(v2 + 6);
  }
  if ( v2 )
    *i = *(_DWORD *)(v2 + 6);
  j__nfree(a1);
  return 0;
}
// 15E134: using guessed type int __fastcall j__nfree(_DWORD);
// 18ACE8: using guessed type int dword_18ACE8;


//----- (0015EF04) --------------------------------------------------------
int sub_15EF04()
{
  int result; // eax

  for ( ; dword_18ACE8; result = (*(int (__fastcall **)(int))(dword_18ACE8 + 39))(dword_18ACE8) )
    ;
  return result;
}
// 18ACE8: using guessed type int dword_18ACE8;


//----- (0015EF24) --------------------------------------------------------
int __fastcall sub_15EF24(int a1)
{
  int result; // eax

  if ( !dword_18ACEC )
  {
    atexit(sub_15EF04);
    dword_18ACEC = 1;
  }
  *(_DWORD *)(a1 + 19) = 0;
  *(_WORD *)(a1 + 127) = 0;
  *(_DWORD *)(a1 + 123) = 0;
  *(_DWORD *)(a1 + 27) = sub_15EE80;
  *(_DWORD *)(a1 + 31) = sub_15EE80;
  *(_DWORD *)(a1 + 35) = sub_15EE80;
  *(_DWORD *)(a1 + 39) = sub_15EEC4;
  *(_DWORD *)(a1 + 43) = sub_15EE8C;
  *(_DWORD *)(a1 + 47) = sub_15EE80;
  *(_DWORD *)(a1 + 55) = sub_15EE80;
  *(_DWORD *)(a1 + 51) = sub_15EE80;
  *(_DWORD *)(a1 + 59) = sub_15EE80;
  *(_DWORD *)(a1 + 63) = sub_15EE80;
  *(_DWORD *)(a1 + 67) = sub_15EE80;
  *(_DWORD *)(a1 + 71) = sub_15EE80;
  *(_DWORD *)(a1 + 75) = sub_15EE80;
  *(_DWORD *)(a1 + 79) = sub_15EE80;
  *(_DWORD *)(a1 + 83) = sub_15EE80;
  *(_DWORD *)(a1 + 87) = sub_15EE80;
  *(_DWORD *)(a1 + 91) = sub_15EE80;
  *(_DWORD *)(a1 + 95) = sub_15EE9C;
  *(_DWORD *)(a1 + 99) = sub_15EE80;
  *(_DWORD *)(a1 + 107) = sub_15EE80;
  *(_DWORD *)(a1 + 103) = sub_15EE80;
  *(_DWORD *)(a1 + 111) = sub_15EE80;
  *(_DWORD *)(a1 + 115) = sub_15EE80;
  result = dword_18ACE8;
  *(_DWORD *)(a1 + 119) = &off_15EEFC;
  dword_18ACE8 = a1;
  *(_DWORD *)(a1 + 6) = result;
  return result;
}
// 144906: using guessed type int __fastcall atexit(_DWORD);
// 15EEFC: using guessed type _UNKNOWN *off_15EEFC;
// 18ACE8: using guessed type int dword_18ACE8;
// 18ACEC: using guessed type int dword_18ACEC;


//----- (0015F014) --------------------------------------------------------
int __fastcall sub_15F014(int a1)
{
  int v2; // eax
  int *i; // ebx

  v2 = dword_18ACE8;
  for ( i = &dword_18ACE8; v2; v2 = *(_DWORD *)(v2 + 6) )
  {
    if ( v2 == a1 )
      break;
    i = (int *)(v2 + 6);
  }
  if ( v2 )
    *i = *(_DWORD *)(v2 + 6);
  return j__nfree(a1);
}
// 15E134: using guessed type int __fastcall j__nfree(_DWORD);
// 18ACE8: using guessed type int dword_18ACE8;


//----- (0015F048) --------------------------------------------------------
int *sub_15F048()
{
  int *result; // eax

  sub_15EF24((int)&dword_1C9CC0);
  dword_1C9CCA = -1;
  dword_1C9CC0 = 0;
  dword_1C9CCE = -5;
  byte_1C9CD2 = -1;
  result = &dword_1C9CC0;
  word_1C9CC4 = 0;
  return result;
}
// 1C9CC0: using guessed type int dword_1C9CC0;
// 1C9CC4: using guessed type int16_t word_1C9CC4;
// 1C9CCA: using guessed type int dword_1C9CCA;
// 1C9CCE: using guessed type int dword_1C9CCE;
// 1C9CD2: using guessed type char byte_1C9CD2;


//----- (0015F090) --------------------------------------------------------
int sub_15F090()
{
  _DWORD v1[4]; // [esp+0h] [ebp-9Ch] BYREF
  int v2; // [esp+10h] [ebp-8Ch]
  int v3; // [esp+14h] [ebp-88h]
  int v4; // [esp+18h] [ebp-84h]
  int v5; // [esp+1Ch] [ebp-80h]
  int16_t v6; // [esp+20h] [ebp-7Ch]
  uint16_t v7; // [esp+22h] [ebp-7Ah]
  int16_t v8; // [esp+24h] [ebp-78h]
  int16_t v9; // [esp+26h] [ebp-76h]
  int16_t v10; // [esp+28h] [ebp-74h]
  int16_t v11; // [esp+2Ah] [ebp-72h]
  int16_t v12; // [esp+2Ch] [ebp-70h]
  int16_t v13; // [esp+2Eh] [ebp-6Eh]
  int16_t v14; // [esp+30h] [ebp-6Ch]
  int v15; // [esp+34h] [ebp-68h] BYREF
  char v16; // [esp+38h] [ebp-64h]
  char v17; // [esp+39h] [ebp-63h]
  int v18; // [esp+3Ch] [ebp-60h]
  _DWORD *v19; // [esp+48h] [ebp-54h]
  _DWORD v20[7]; // [esp+50h] [ebp-4Ch] BYREF
  _WORD v21[6]; // [esp+6Ch] [ebp-30h] BYREF
  int v22; // [esp+78h] [ebp-24h]
  int v23; // [esp+7Ch] [ebp-20h]
  _BYTE v24[28]; // [esp+80h] [ebp-1Ch] BYREF

  if ( dword_18ACF0 == -1 )
  {
    dword_18ACF0 = 0;
    segread(v21, 0xFFFF, 0);
    memset(v1, 0, sizeof(v1));
    v2 = 0;
    v3 = 0;
    v4 = 0;
    v5 = 49152;
    v6 = -1;
    v15 = 768;
    v7 = v21[0];
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v14 = 0;
    v8 = v21[3];
    v13 = 0;
    v12 = v21[1];
    v17 = 0;
    v16 = 21;
    v21[0] = v21[2];
    v19 = v1;
    v18 = 0;
    int386x(49, &v15);
    v20[1] = v7;
    v20[0] = 2;
    int386(49, v20, v20);
    LOWORD(v23) = v20[0];
    v22 = v2 + 5;
    sub_15E3A8((int)v24, v2 + 5, (int)v20, (int)v21, v2 + 5, v20[0], 1);
    dword_18ACF0 = (v24[0] & 2) != 0;
  }
  return dword_18ACF0;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 144A4A: using guessed type int __fastcall int386x(_DWORD, _DWORD);
// 153EAF: using guessed type int __fastcall segread(_DWORD, _DWORD, _DWORD);
// 18ACF0: using guessed type int dword_18ACF0;


//----- (0015F1E0) --------------------------------------------------------
int sub_15F1E0()
{
  uint8_t v1[40]; // [esp+0h] [ebp-28h] BYREF

  if ( dword_18ACF4 >= 0 )
    return dword_18ACF4;
  *(_DWORD *)v1 = 5632;
  int386(47, v1, v1);
  dword_18ACF4 = v1[0] && v1[0] != 128 && v1[0] != 1 && v1[0] != 255;
  return dword_18ACF4;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 18ACF4: using guessed type int dword_18ACF4;


//----- (0015F248) --------------------------------------------------------
int sub_15F248()
{
  uint16_t v1[4]; // [esp+0h] [ebp-30h] BYREF
  char v2; // [esp+8h] [ebp-28h]
  char v3; // [esp+9h] [ebp-27h]
  char v4; // [esp+Ch] [ebp-24h]
  char v5; // [esp+Dh] [ebp-23h]

  if ( dword_18ACFC == -1 )
  {
    v1[0] = 12289;
    int386(33, v1, v1);
    dword_18ACFC = LOBYTE(v1[0]) == 20;
  }
  if ( dword_18ACFC )
    return 0;
  if ( dword_18ACF8 == -1 )
  {
    v3 = 68;
    v5 = 83;
    *(_DWORD *)v1 = 11009;
    v2 = 69;
    v4 = 81;
    int386(33, v1, v1);
    dword_18ACF8 = v1[0] == 11009;
  }
  return dword_18ACF8;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 18ACF8: using guessed type int dword_18ACF8;
// 18ACFC: using guessed type int dword_18ACFC;


//----- (0015F300) --------------------------------------------------------
int sub_15F300()
{
  int result; // eax
  _DWORD v1[9]; // [esp+0h] [ebp-24h] BYREF

  result = sub_15F1E0();
  if ( result )
  {
    v1[0] = 5760;
    return int386(47, v1, v1);
  }
  return result;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);


//----- (0015F32C) --------------------------------------------------------
int sub_15F32C()
{
  int result; // eax
  _DWORD v1[9]; // [esp+0h] [ebp-24h] BYREF

  result = sub_15F248();
  if ( result )
  {
    v1[0] = 4096;
    return int386(21, v1, v1);
  }
  return result;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);


//----- (0015F360) --------------------------------------------------------
int __fastcall sub_15F360(int a1, int a2, int (__fastcall *a3)(_BYTE *, _DWORD))
{
  int v3; // edi
  char v4; // bl
  int v5; // esi
  int64_t v6; // rax
  _BYTE v8[84]; // [esp+0h] [ebp-5Ch] BYREF
  int (__fastcall *v9)(_BYTE *, _DWORD); // [esp+54h] [ebp-8h]
  int v10; // [esp+58h] [ebp-4h]

  v10 = a1;
  v9 = a3;
  v3 = sub_168549(*(_DWORD *)(a2 + 14) + 3);
  v4 = sub_168549(*(_DWORD *)(a2 + 14) + 4);
  v5 = sub_163800(*(_DWORD *)(a2 + 14), 8);
  if ( !v5 )
    v5 = 115201;
  v6 = sprintf(
         v8,
         "COM%02d: %6ld,%c,%1d,%1d  DTR: %c  RTS: %c  OUT1: %c  OUT2: %c  LOOP: %c",
         v10 + 1,
         115200 / v5,
         (uint8_t)byte_17C8D0[(v3 >> 3) & 7],
         (v3 & 3u) + 5,
         ((v3 >> 2) & 1u) + 1,
         (unsigned int)((v4 & 1) != 0) + 48,
         (unsigned int)((v4 & 2) != 0) + 48,
         (unsigned int)((v4 & 4) != 0) + 48,
         (unsigned int)((v4 & 8) != 0) + 48,
         (unsigned int)((v4 & 0x10) != 0) + 48);
  return v9(v8, HIDWORD(v6));
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);


//----- (0015F448) --------------------------------------------------------
int __fastcall sub_15F448(int a1, int (__fastcall *a2)(_BYTE *))
{
  int v2; // edx
  int v3; // edx
  int v4; // ecx
  int v5; // ebx
  int v6; // ebx
  int v8; // [esp-8h] [ebp-60h]
  _BYTE v9[84]; // [esp+0h] [ebp-58h] BYREF
  int (__fastcall *v10)(_BYTE *); // [esp+54h] [ebp-4h]

  v10 = a2;
  v2 = *(_DWORD *)(a1 + 26);
  if ( v2 < 8 || v2 >= 16 )
  {
    v4 = *(_DWORD *)(a1 + 26);
    if ( v4 < 112 || v4 >= 120 )
      v3 = -1;
    else
      v3 = v4 - 104;
  }
  else
  {
    v3 = v2 - 8;
  }
  if ( *(_DWORD *)(a1 + 50) )
    v5 = 89;
  else
    v5 = 78;
  v8 = v5;
  if ( *(_DWORD *)(a1 + 46) )
    v6 = 89;
  else
    v6 = 78;
  sprintf(
    v9,
    "Uart at: %04x  IRQ%-2d  Int. no.: %-2d  Is16550: %c  UseTXFifo: %c  Trigger Level: %2d",
    *(_DWORD *)(a1 + 14),
    v3,
    *(_DWORD *)(a1 + 26),
    v6,
    v8,
    *(_DWORD *)(a1 + 54));
  return v10(v9);
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);


//----- (0015F4D4) --------------------------------------------------------
int __fastcall sub_15F4D4(int a1, int a2, int (__fastcall *a3)(_BYTE *, _DWORD))
{
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  int64_t v9; // rax
  _BYTE v11[84]; // [esp+0h] [ebp-70h] BYREF
  int v12; // [esp+54h] [ebp-1Ch]
  int v13; // [esp+58h] [ebp-18h]
  int (__fastcall *v14)(_BYTE *, _DWORD); // [esp+5Ch] [ebp-14h]
  _BYTE v15[16]; // [esp+60h] [ebp-10h] BYREF

  v14 = a3;
  v12 = *(_DWORD *)a1;
  LOWORD(v13) = *(_WORD *)(a1 + 4);
  v4 = *(_DWORD *)(a2 + 22);
  v12 += 58;
  v5 = v12 + v4;
  sub_15E3A8((int)v15, a2, v12, a1, v12 + v4, v13, 1);
  v6 = *(_DWORD *)(a2 + 18) - *(_DWORD *)(a2 + 22);
  v12 = v5;
  v7 = v6 + (v6 < 0 ? 0x400 : 0);
  if ( v7 )
    v8 = v15[0];
  else
    v8 = -8;
  v9 = sprintf(
         v11,
         "Buffer at: %04x:%08x  Head: %4d  Tail: %4d  Count: %4d  Peek: %3d",
         *(uint16_t *)(a1 + 4),
         *(_DWORD *)a1 + 58,
         *(_DWORD *)(a2 + 18),
         *(_DWORD *)(a2 + 22),
         v7,
         v8);
  return v14(v11, HIDWORD(v9));
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);


//----- (0015F568) --------------------------------------------------------
int __fastcall sub_15F568(int a1, int (__fastcall *a2)(_BYTE *))
{
  int v2; // ebx
  int v3; // edx
  _BYTE v5[84]; // [esp+0h] [ebp-58h] BYREF
  int (__fastcall *v6)(_BYTE *); // [esp+54h] [ebp-4h]

  v2 = a1;
  v6 = a2;
  v3 = (*(int (**)(void))(a1 + 103))();
  LOBYTE(v2) = (*(int (__fastcall **)(int, int))(v2 + 107))(v2, v3);
  sprintf(
    v5,
    "DSR: %c  CTS: %c  CD: %c  RI: %c  PE: %c  FE: %c  BREAK: %c OE: %c",
    ((v3 & 0x20) != 0) + 48,
    ((v3 & 0x10) != 0) + 48,
    ((v3 & 0x80u) != 0) + 48,
    ((v3 & 0x40) != 0) + 48,
    ((v2 & 4) != 0) + 48,
    ((v2 & 8) != 0) + 48,
    ((v2 & 0x10) != 0) + 48,
    ((v2 & 2) != 0) + 48);
  return v6(v5);
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);


//----- (0015F614) --------------------------------------------------------
int __fastcall sub_15F614(int a1, int (__fastcall *a2)(_BYTE *))
{
  int v2; // edx
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // eax
  int v8; // [esp-Ch] [ebp-64h]
  int v9; // [esp-8h] [ebp-60h]
  int v10; // [esp-4h] [ebp-5Ch]
  _BYTE v11[84]; // [esp+0h] [ebp-58h] BYREF
  int (__fastcall *v12)(_BYTE *); // [esp+54h] [ebp-4h]

  v12 = a2;
  if ( *(_DWORD *)(a1 + 42) )
    v2 = 89;
  else
    v2 = 78;
  v10 = v2;
  if ( (*(_BYTE *)(a1 + 38) & 0x20) != 0 )
    v3 = 89;
  else
    v3 = 78;
  v9 = v3;
  if ( (*(_BYTE *)(a1 + 34) & 1) != 0 )
    v4 = 89;
  else
    v4 = 78;
  v8 = v4;
  if ( (*(_BYTE *)(a1 + 38) & 0x10) != 0 )
    v5 = 89;
  else
    v5 = 78;
  if ( (*(_BYTE *)(a1 + 34) & 2) != 0 )
    v6 = 89;
  else
    v6 = 78;
  sprintf(v11, "Handshaking:  RTS: %c  CTS: %c  DTR: %c  DSR: %c  Blocking: %c", v6, v5, v8, v9, v10);
  return v12(v11);
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);


//----- (0015F6A0) --------------------------------------------------------
int __fastcall sub_15F6A0(int a1, int a2, int (__fastcall *a3)(_BYTE *))
{
  _BYTE v4[84]; // [esp+0h] [ebp-60h] BYREF
  int (__fastcall *v5)(_BYTE *); // [esp+54h] [ebp-Ch]

  v5 = a3;
  sprintf(
    v4,
    "Fast port: %04x:%04x  Fast id: %04x  Next port: %04x:%04x  Next real: %04x:%04x",
    *(uint16_t *)(a1 + 4),
    *(_DWORD *)a1,
    *(_DWORD *)(a2 + 10),
    *(uint16_t *)(a2 + 4),
    *(_DWORD *)a2,
    *(uint16_t *)(a2 + 8),
    *(uint16_t *)(a2 + 6));
  return v5(v4);
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);


//----- (0015F6F4) --------------------------------------------------------
int __fastcall sub_15F6F4(int a1, int (__fastcall *a2)(_BYTE *))
{
  int v3; // eax
  int v5; // [esp-Ch] [ebp-68h]
  int v6; // [esp-8h] [ebp-64h]
  int v7; // [esp-4h] [ebp-60h]
  _BYTE v8[84]; // [esp+0h] [ebp-5Ch] BYREF
  int (__fastcall *v9)(_BYTE *); // [esp+54h] [ebp-8h]

  v9 = a2;
  v7 = (*(int (**)(void))(a1 + 75))();
  v6 = (*(int (__fastcall **)(int))(a1 + 79))(a1);
  v5 = (*(int (__fastcall **)(int))(a1 + 67))(a1);
  v3 = (*(int (__fastcall **)(int))(a1 + 71))(a1);
  sprintf(
    v8,
    "Status: %6d  TXUsed: %5ld  TXFree: %5ld  RXUsed: %5ld  RXFree: %5ld  ",
    *(_DWORD *)(a1 + 14),
    v3,
    v5,
    v6,
    v7);
  return v9(v8);
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);


//----- (0015F738) --------------------------------------------------------
int __fastcall sub_15F738(int a1, void (__fastcall *a2)(_BYTE *, _DWORD), int a3, int a4)
{
  int64_t v4; // rax
  int64_t v5; // rax
  int64_t v6; // rax
  int64_t v7; // rax
  _BYTE v9[84]; // [esp+0h] [ebp-B4h] BYREF
  int v10; // [esp+54h] [ebp-60h] BYREF
  uint16_t v11; // [esp+58h] [ebp-5Ch]
  uint16_t v12; // [esp+5Ah] [ebp-5Ah]
  uint16_t v13; // [esp+5Ch] [ebp-58h]
  int v14; // [esp+5Eh] [ebp-56h]
  uint16_t v15; // [esp+62h] [ebp-52h]
  uint16_t v16; // [esp+64h] [ebp-50h]
  uint16_t v17; // [esp+66h] [ebp-4Eh]
  int v18; // [esp+68h] [ebp-4Ch]
  uint16_t v19; // [esp+6Ch] [ebp-48h]
  uint16_t v20; // [esp+6Eh] [ebp-46h]
  uint16_t v21; // [esp+70h] [ebp-44h]
  int v22; // [esp+7Ah] [ebp-3Ah]
  int v23; // [esp+7Eh] [ebp-36h]
  int v24; // [esp+82h] [ebp-32h]
  int v25; // [esp+8Ah] [ebp-2Ah]
  int v26; // [esp+8Eh] [ebp-26h]
  unsigned int v27; // [esp+94h] [ebp-20h] BYREF
  int v28; // [esp+98h] [ebp-1Ch]
  void (__fastcall *v29)(_BYTE *, _DWORD); // [esp+9Ch] [ebp-18h]

  v29 = a2;
  sub_15E918(*(_DWORD *)(a1 + 26), (int)&v27);
  sub_15E3A8((int)&v10, v28, v27, a4, v27, v28, 62);
  v4 = sprintf(
         v9,
         "8259: %02x  Sec 8259: %02x  8259 bit: %04x Int count: %04x  Real count: %04x",
         v23,
         v24,
         v22,
         v25,
         v26);
  v29(v9, HIDWORD(v4));
  v5 = sprintf(v9, "Saved vector: %04x:%08x  Handler: %04x:%08x  Data: %04x:%08x", v10, v11, v15, v14, v19, v18);
  v29(v9, HIDWORD(v5));
  v6 = sprintf(
         v9,
         "Saved real vector: %04x:%04x  Real handler: %04x:%04x  Real data: %04x:%04x",
         v13,
         v12,
         v17,
         v16,
         v21,
         v20);
  v29(v9, HIDWORD(v6));
  v7 = sprintf(v9, "Interrupt 1B count: %08x  Interrupt 23 count: %08x", dword_18AD70, dword_18AD6C);
  return ((int (__fastcall *)(_BYTE *, _DWORD))v29)(v9, HIDWORD(v7));
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 18AD6C: using guessed type int dword_18AD6C;
// 18AD70: using guessed type int dword_18AD70;


//----- (0015F884) --------------------------------------------------------
int __fastcall sub_15F884(int *a1, int (__fastcall *a2)(_BYTE *), int a3, int a4)
{
  int (__fastcall *v5)(_BYTE *); // ebx
  int (__fastcall *v6)(_BYTE *); // ebx
  int (__fastcall *v7)(_BYTE *); // ebx
  _BYTE v9[60]; // [esp+0h] [ebp-4Ch] BYREF
  int (__fastcall *v10)(_BYTE *); // [esp+3Ch] [ebp-10h]

  v10 = a2;
  sub_168545();
  sub_15E3A8((int)v9, a1[1], *a1, a4, *a1, a1[1], 58);
  sub_168541();
  v5 = v10;
  v10(&aD_15[1]);
  ((void (__fastcall *)(char *, _BYTE *, int (__fastcall *)(_BYTE *)))v10)(&aVecportTypeGre[3], v9, v5);
  sub_15F360(*(int *)((char *)a1 + 10), (int)v9, (int (__fastcall *)(_BYTE *, _DWORD))v5);
  v6 = v10;
  sub_15F448((int)v9, v10);
  sub_15F4D4((int)a1, (int)v9, (int (__fastcall *)(_BYTE *, _DWORD))v6);
  sub_15F568((int)a1, v10);
  sub_15F614((int)v9, v10);
  v7 = v10;
  sub_15F6F4((int)a1, v10);
  sub_15F6A0((int)a1, (int)v9, v7);
  sub_15F738((int)v9, (void (__fastcall *)(_BYTE *, _DWORD))v10, (int)v7, a4);
  return 0;
}


//----- (001606F8) --------------------------------------------------------
int __usercall sub_1606F8(int a1, _BYTE *a2, int *a3)
{
  int v3; // eax
  int result; // eax

  do
  {
    v3 = *a3++;
    result = v3 ^ 0x8000;
    *a2++ = BYTE1(result);
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160709) --------------------------------------------------------
int __usercall sub_160709(int a1, _BYTE *a2, int *a3)
{
  int result; // eax

  do
  {
    result = *a3++;
    *a2++ = BYTE1(result);
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160715) --------------------------------------------------------
int __usercall sub_160715(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int result; // eax

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    result = v3 ^ 0x8000;
    BYTE1(v4) ^= 0x80u;
    LOBYTE(v4) = BYTE1(result);
    *a2++ = v4;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160734) --------------------------------------------------------
int __usercall sub_160734(int a1, _WORD *a2, int *a3)
{
  int result; // eax
  int v4; // edx

  do
  {
    result = *a3;
    v4 = a3[1];
    a3 += 2;
    LOBYTE(v4) = BYTE1(result);
    *a2++ = v4;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160748) --------------------------------------------------------
char __usercall sub_160748(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int16_t v5; // ax

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    HIBYTE(v5) = BYTE1(v3) ^ 0x80;
    LOBYTE(v5) = (uint16_t)(v4 ^ 0x8000) >> 8;
    *a2++ = v5;
    --a1;
  }
  while ( a1 );
  return v5;
}


//----- (00160767) --------------------------------------------------------
char __usercall sub_160767(int a1, _WORD *a2, int *a3)
{
  int v3; // edx
  int v4; // eax

  do
  {
    v4 = *a3;
    v3 = a3[1];
    a3 += 2;
    LOBYTE(v4) = BYTE1(v3);
    *a2++ = v4;
    --a1;
  }
  while ( a1 );
  return v4;
}


//----- (0016077B) --------------------------------------------------------
int __usercall sub_16077B(int a1, _BYTE *a2, _BYTE *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int result; // eax

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    result = v4 ^ 0x8000;
    *a3 = BYTE1(result);
    *a2 = (uint16_t)(v5 ^ 0x8000) >> 8;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160798) --------------------------------------------------------
int __usercall sub_160798(int a1, _BYTE *a2, _BYTE *a3, int *a4)
{
  int result; // eax
  int v5; // edx

  do
  {
    result = *a4;
    v5 = a4[1];
    a4 += 2;
    *a3 = BYTE1(result);
    *a2 = BYTE1(v5);
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001607AA) --------------------------------------------------------
int __usercall sub_1607AA(int a1, _BYTE *a2, _BYTE *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int result; // eax

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    result = v4 ^ 0x8000;
    *a3 = (uint16_t)(v5 ^ 0x8000) >> 8;
    *a2 = BYTE1(result);
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001607C7) --------------------------------------------------------
int __usercall sub_1607C7(int a1, _BYTE *a2, _BYTE *a3, int *a4)
{
  int result; // eax
  int v5; // edx

  do
  {
    result = *a4;
    v5 = a4[1];
    a4 += 2;
    *a3 = BYTE1(v5);
    *a2 = BYTE1(result);
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001607D9) --------------------------------------------------------
int __usercall sub_1607D9(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int result; // eax

  do
  {
    v3 = *a3++;
    result = v3 ^ 0x8000;
    *a2++ = result;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001607ED) --------------------------------------------------------
int __usercall sub_1607ED(int a1, _WORD *a2, int *a3)
{
  int result; // eax

  do
  {
    result = *a3++;
    *a2++ = result;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001607FC) --------------------------------------------------------
int16_t __usercall sub_1607FC(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int16_t result; // ax
  char v5; // t0

  do
  {
    v3 = *a3++;
    LOWORD(v3) = v3 ^ 0x8000;
    v5 = v3;
    LOBYTE(result) = BYTE1(v3);
    HIBYTE(result) = v5;
    *a2++ = result;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160812) --------------------------------------------------------
int16_t __usercall sub_160812(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int16_t result; // ax
  char v5; // t0

  do
  {
    v3 = *a3++;
    v5 = v3;
    LOBYTE(result) = BYTE1(v3);
    HIBYTE(result) = v5;
    *a2++ = result;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160823) --------------------------------------------------------
int __usercall sub_160823(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int result; // eax

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    result = v3 ^ 0x8000;
    *a2 = result;
    a2[1] = v4 ^ 0x8000;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160844) --------------------------------------------------------
int __usercall sub_160844(int a1, _WORD *a2, int *a3)
{
  int result; // eax
  int v4; // edx

  do
  {
    result = *a3;
    v4 = a3[1];
    a3 += 2;
    *a2 = result;
    a2[1] = v4;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (0016085A) --------------------------------------------------------
int __usercall sub_16085A(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int result; // eax

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    result = v3 ^ 0x8000;
    *a2 = v4 ^ 0x8000;
    a2[1] = result;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (0016087B) --------------------------------------------------------
int __usercall sub_16087B(int a1, _WORD *a2, int *a3)
{
  int result; // eax
  int v4; // edx

  do
  {
    result = *a3;
    v4 = a3[1];
    a3 += 2;
    *a2 = v4;
    a2[1] = result;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160891) --------------------------------------------------------
int __usercall sub_160891(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int result; // eax
  char v6; // t0
  char v7; // t1

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    result = v3 ^ 0x8000;
    LOWORD(v4) = v4 ^ 0x8000;
    v6 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v6;
    v7 = v4;
    LOBYTE(v4) = BYTE1(v4);
    BYTE1(v4) = v7;
    *a2 = result;
    a2[1] = v4;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001608B6) --------------------------------------------------------
int __usercall sub_1608B6(int a1, _WORD *a2, int *a3)
{
  int v3; // edx
  int result; // eax
  char v5; // t0
  char v6; // t1

  do
  {
    result = *a3;
    v3 = a3[1];
    a3 += 2;
    v5 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v5;
    v6 = v3;
    LOBYTE(v3) = BYTE1(v3);
    BYTE1(v3) = v6;
    *a2 = result;
    a2[1] = v3;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001608D0) --------------------------------------------------------
int __usercall sub_1608D0(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int result; // eax
  char v6; // t0
  char v7; // t1

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    result = v3 ^ 0x8000;
    LOWORD(v4) = v4 ^ 0x8000;
    v6 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v6;
    v7 = v4;
    LOBYTE(v4) = BYTE1(v4);
    BYTE1(v4) = v7;
    *a2 = v4;
    a2[1] = result;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001608F5) --------------------------------------------------------
int __usercall sub_1608F5(int a1, _WORD *a2, int *a3)
{
  int v3; // edx
  int result; // eax
  char v5; // t0
  char v6; // t1

  do
  {
    result = *a3;
    v3 = a3[1];
    a3 += 2;
    v5 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v5;
    v6 = v3;
    LOBYTE(v3) = BYTE1(v3);
    BYTE1(v3) = v6;
    *a2 = v3;
    a2[1] = result;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (0016090F) --------------------------------------------------------
int __usercall sub_16090F(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int result; // eax

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    result = v4 ^ 0x8000;
    *a3 = result;
    *a2 = v5 ^ 0x8000;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160932) --------------------------------------------------------
int __usercall sub_160932(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int result; // eax
  int v5; // edx

  do
  {
    result = *a4;
    v5 = a4[1];
    a4 += 2;
    *a3 = result;
    *a2 = v5;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (0016094A) --------------------------------------------------------
int __usercall sub_16094A(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int result; // eax

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    result = v4 ^ 0x8000;
    *a3 = v5 ^ 0x8000;
    *a2 = result;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (0016096D) --------------------------------------------------------
int __usercall sub_16096D(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int result; // eax
  int v5; // edx

  do
  {
    result = *a4;
    v5 = a4[1];
    a4 += 2;
    *a3 = v5;
    *a2 = result;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160985) --------------------------------------------------------
int __usercall sub_160985(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int result; // eax
  char v7; // t0
  char v8; // t1

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    result = v4 ^ 0x8000;
    LOWORD(v5) = v5 ^ 0x8000;
    v7 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v7;
    v8 = v5;
    LOBYTE(v5) = BYTE1(v5);
    BYTE1(v5) = v8;
    *a3 = result;
    *a2 = v5;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001609AC) --------------------------------------------------------
int __usercall sub_1609AC(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // edx
  int result; // eax
  char v6; // t0
  char v7; // t1

  do
  {
    result = *a4;
    v4 = a4[1];
    a4 += 2;
    v6 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v6;
    v7 = v4;
    LOBYTE(v4) = BYTE1(v4);
    BYTE1(v4) = v7;
    *a3 = result;
    *a2 = v4;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001609C8) --------------------------------------------------------
int __usercall sub_1609C8(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int result; // eax
  char v7; // t0
  char v8; // t1

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    result = v4 ^ 0x8000;
    LOWORD(v5) = v5 ^ 0x8000;
    v7 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v7;
    v8 = v5;
    LOBYTE(v5) = BYTE1(v5);
    BYTE1(v5) = v8;
    *a3 = v5;
    *a2 = result;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001609EF) --------------------------------------------------------
int __usercall sub_1609EF(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // edx
  int result; // eax
  char v6; // t0
  char v7; // t1

  do
  {
    result = *a4;
    v4 = a4[1];
    a4 += 2;
    v6 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v6;
    v7 = v4;
    LOBYTE(v4) = BYTE1(v4);
    BYTE1(v4) = v7;
    *a3 = v4;
    *a2 = result;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160A0B) --------------------------------------------------------
int __usercall sub_160A0B(int a1, _BYTE *a2, int *a3)
{
  int v3; // eax
  int result; // eax

  do
  {
    v3 = *a3++;
    if ( v3 > 0x7FFF )
    {
      v3 = 0x7FFF;
    }
    else if ( v3 < -32768 )
    {
      v3 = -32768;
    }
    result = v3 ^ 0x8000;
    *a2++ = BYTE1(result);
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160A38) --------------------------------------------------------
int __usercall sub_160A38(int a1, _BYTE *a2, int *a3)
{
  int result; // eax

  do
  {
    result = *a3++;
    if ( result > 0x7FFF )
    {
      result = 0x7FFF;
    }
    else if ( result < -32768 )
    {
      result = -32768;
    }
    *a2++ = BYTE1(result);
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160A60) --------------------------------------------------------
int __usercall sub_160A60(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int result; // eax
  int16_t v6; // dx

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( v3 > 0x7FFF )
    {
      v3 = 0x7FFF;
    }
    else if ( v3 < -32768 )
    {
      v3 = -32768;
    }
    if ( v4 > 0x7FFF )
    {
      BYTE1(v4) = 127;
    }
    else if ( v4 < -32768 )
    {
      BYTE1(v4) = 0x80;
    }
    result = v3 ^ 0x8000;
    HIBYTE(v6) = BYTE1(v4) ^ 0x80;
    LOBYTE(v6) = BYTE1(result);
    *a2++ = v6;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160AB9) --------------------------------------------------------
int __usercall sub_160AB9(int a1, _WORD *a2, int *a3)
{
  int result; // eax
  int v4; // edx

  do
  {
    result = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( result > 0x7FFF )
    {
      result = 0x7FFF;
    }
    else if ( result < -32768 )
    {
      result = -32768;
    }
    if ( v4 > 0x7FFF )
    {
      BYTE1(v4) = 127;
    }
    else if ( v4 < -32768 )
    {
      BYTE1(v4) = 0x80;
    }
    LOBYTE(v4) = BYTE1(result);
    *a2++ = v4;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160B07) --------------------------------------------------------
char __usercall sub_160B07(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int16_t v5; // ax

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( v3 > 0x7FFF )
    {
      BYTE1(v3) = 127;
    }
    else if ( v3 < -32768 )
    {
      BYTE1(v3) = 0x80;
    }
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    HIBYTE(v5) = BYTE1(v3) ^ 0x80;
    LOBYTE(v5) = (uint16_t)(v4 ^ 0x8000) >> 8;
    *a2++ = v5;
    --a1;
  }
  while ( a1 );
  return v5;
}


//----- (00160B60) --------------------------------------------------------
char __usercall sub_160B60(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( v3 > 0x7FFF )
    {
      BYTE1(v3) = 127;
    }
    else if ( v3 < -32768 )
    {
      BYTE1(v3) = 0x80;
    }
    if ( v4 > 0x7FFF )
    {
      BYTE1(v4) = 127;
    }
    else if ( v4 < -32768 )
    {
      BYTE1(v4) = 0x80;
    }
    LOBYTE(v3) = BYTE1(v4);
    *a2++ = v3;
    --a1;
  }
  while ( a1 );
  return v3;
}


//----- (00160BAE) --------------------------------------------------------
int __usercall sub_160BAE(int a1, _BYTE *a2, _BYTE *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int result; // eax

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( v4 > 0x7FFF )
    {
      v4 = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      v4 = -32768;
    }
    if ( v5 > 0x7FFF )
    {
      LOWORD(v5) = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      LOWORD(v5) = 0x8000;
    }
    result = v4 ^ 0x8000;
    *a3 = BYTE1(result);
    *a2 = (uint16_t)(v5 ^ 0x8000) >> 8;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160C05) --------------------------------------------------------
int __usercall sub_160C05(int a1, _BYTE *a2, _BYTE *a3, int *a4)
{
  int result; // eax
  int v5; // edx

  do
  {
    result = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( result > 0x7FFF )
    {
      result = 0x7FFF;
    }
    else if ( result < -32768 )
    {
      result = -32768;
    }
    if ( v5 > 0x7FFF )
    {
      BYTE1(v5) = 127;
    }
    else if ( v5 < -32768 )
    {
      BYTE1(v5) = 0x80;
    }
    *a3 = BYTE1(result);
    *a2 = BYTE1(v5);
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160C51) --------------------------------------------------------
int __usercall sub_160C51(int a1, _BYTE *a2, _BYTE *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int result; // eax

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( v4 > 0x7FFF )
    {
      v4 = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      v4 = -32768;
    }
    if ( v5 > 0x7FFF )
    {
      LOWORD(v5) = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      LOWORD(v5) = 0x8000;
    }
    result = v4 ^ 0x8000;
    *a3 = (uint16_t)(v5 ^ 0x8000) >> 8;
    *a2 = BYTE1(result);
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160CA8) --------------------------------------------------------
int __usercall sub_160CA8(int a1, _BYTE *a2, _BYTE *a3, int *a4)
{
  int result; // eax
  int v5; // edx

  do
  {
    result = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( result > 0x7FFF )
    {
      result = 0x7FFF;
    }
    else if ( result < -32768 )
    {
      result = -32768;
    }
    if ( v5 > 0x7FFF )
    {
      BYTE1(v5) = 127;
    }
    else if ( v5 < -32768 )
    {
      BYTE1(v5) = 0x80;
    }
    *a3 = BYTE1(v5);
    *a2 = BYTE1(result);
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160CF4) --------------------------------------------------------
int __usercall sub_160CF4(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int result; // eax

  do
  {
    v3 = *a3++;
    if ( v3 > 0x7FFF )
    {
      v3 = 0x7FFF;
    }
    else if ( v3 < -32768 )
    {
      v3 = -32768;
    }
    result = v3 ^ 0x8000;
    *a2++ = result;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160D24) --------------------------------------------------------
int __usercall sub_160D24(int a1, _WORD *a2, int *a3)
{
  int result; // eax

  do
  {
    result = *a3++;
    if ( result > 0x7FFF )
    {
      result = 0x7FFF;
    }
    else if ( result < -32768 )
    {
      result = -32768;
    }
    *a2++ = result;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160D4F) --------------------------------------------------------
int16_t __usercall sub_160D4F(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int16_t v4; // ax
  int16_t result; // ax
  char v6; // t0

  do
  {
    v3 = *a3++;
    if ( v3 > 0x7FFF )
    {
      LOWORD(v3) = 0x7FFF;
    }
    else if ( v3 < -32768 )
    {
      LOWORD(v3) = 0x8000;
    }
    v4 = v3 ^ 0x8000;
    v6 = v4;
    LOBYTE(result) = HIBYTE(v4);
    HIBYTE(result) = v6;
    *a2++ = result;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160D81) --------------------------------------------------------
int16_t __usercall sub_160D81(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int16_t result; // ax
  char v5; // t0

  do
  {
    v3 = *a3++;
    if ( v3 > 0x7FFF )
    {
      LOWORD(v3) = 0x7FFF;
    }
    else if ( v3 < -32768 )
    {
      LOWORD(v3) = 0x8000;
    }
    v5 = v3;
    LOBYTE(result) = BYTE1(v3);
    HIBYTE(result) = v5;
    *a2++ = result;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160DAE) --------------------------------------------------------
int __usercall sub_160DAE(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int result; // eax

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( v3 > 0x7FFF )
    {
      v3 = 0x7FFF;
    }
    else if ( v3 < -32768 )
    {
      v3 = -32768;
    }
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    result = v3 ^ 0x8000;
    *a2 = result;
    a2[1] = v4 ^ 0x8000;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160E09) --------------------------------------------------------
int __usercall sub_160E09(int a1, _WORD *a2, int *a3)
{
  int result; // eax
  int v4; // edx

  do
  {
    result = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( result > 0x7FFF )
    {
      result = 0x7FFF;
    }
    else if ( result < -32768 )
    {
      result = -32768;
    }
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    *a2 = result;
    a2[1] = v4;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160E59) --------------------------------------------------------
int __usercall sub_160E59(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int result; // eax

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( v3 > 0x7FFF )
    {
      v3 = 0x7FFF;
    }
    else if ( v3 < -32768 )
    {
      v3 = -32768;
    }
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    result = v3 ^ 0x8000;
    *a2 = v4 ^ 0x8000;
    a2[1] = result;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160EB4) --------------------------------------------------------
int __usercall sub_160EB4(int a1, _WORD *a2, int *a3)
{
  int result; // eax
  int v4; // edx

  do
  {
    result = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( result > 0x7FFF )
    {
      result = 0x7FFF;
    }
    else if ( result < -32768 )
    {
      result = -32768;
    }
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    *a2 = v4;
    a2[1] = result;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160F04) --------------------------------------------------------
int __usercall sub_160F04(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int16_t v5; // dx
  int result; // eax
  char v7; // t0
  char v8; // t1

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( v3 > 0x7FFF )
    {
      v3 = 0x7FFF;
    }
    else if ( v3 < -32768 )
    {
      v3 = -32768;
    }
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    result = v3 ^ 0x8000;
    v5 = v4 ^ 0x8000;
    v7 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v7;
    v8 = v5;
    LOBYTE(v5) = HIBYTE(v5);
    HIBYTE(v5) = v8;
    *a2 = result;
    a2[1] = v5;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160F63) --------------------------------------------------------
int16_t __usercall sub_160F63(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int16_t result; // ax
  char v6; // t0
  int16_t v7; // dx
  char v8; // t1

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( v3 > 0x7FFF )
    {
      LOWORD(v3) = 0x7FFF;
    }
    else if ( v3 < -32768 )
    {
      LOWORD(v3) = 0x8000;
    }
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    v6 = v3;
    LOBYTE(result) = BYTE1(v3);
    HIBYTE(result) = v6;
    v8 = v4;
    LOBYTE(v7) = BYTE1(v4);
    HIBYTE(v7) = v8;
    *a2 = result;
    a2[1] = v7;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00160FB7) --------------------------------------------------------
int __usercall sub_160FB7(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int16_t v5; // dx
  int result; // eax
  char v7; // t0
  char v8; // t1

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( v3 > 0x7FFF )
    {
      v3 = 0x7FFF;
    }
    else if ( v3 < -32768 )
    {
      v3 = -32768;
    }
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    result = v3 ^ 0x8000;
    v5 = v4 ^ 0x8000;
    v7 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v7;
    v8 = v5;
    LOBYTE(v5) = HIBYTE(v5);
    HIBYTE(v5) = v8;
    *a2 = v5;
    a2[1] = result;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00161016) --------------------------------------------------------
int16_t __usercall sub_161016(int a1, _WORD *a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int16_t result; // ax
  char v6; // t0
  int16_t v7; // dx
  char v8; // t1

  do
  {
    v3 = *a3;
    v4 = a3[1];
    a3 += 2;
    if ( v3 > 0x7FFF )
    {
      LOWORD(v3) = 0x7FFF;
    }
    else if ( v3 < -32768 )
    {
      LOWORD(v3) = 0x8000;
    }
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    v6 = v3;
    LOBYTE(result) = BYTE1(v3);
    HIBYTE(result) = v6;
    v8 = v4;
    LOBYTE(v7) = BYTE1(v4);
    HIBYTE(v7) = v8;
    *a2 = v7;
    a2[1] = result;
    a2 += 2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (0016106A) --------------------------------------------------------
int __usercall sub_16106A(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int result; // eax

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( v4 > 0x7FFF )
    {
      v4 = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      v4 = -32768;
    }
    if ( v5 > 0x7FFF )
    {
      LOWORD(v5) = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      LOWORD(v5) = 0x8000;
    }
    result = v4 ^ 0x8000;
    *a3 = result;
    *a2 = v5 ^ 0x8000;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001610C7) --------------------------------------------------------
int __usercall sub_1610C7(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int result; // eax
  int v5; // edx

  do
  {
    result = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( result > 0x7FFF )
    {
      result = 0x7FFF;
    }
    else if ( result < -32768 )
    {
      result = -32768;
    }
    if ( v5 > 0x7FFF )
    {
      LOWORD(v5) = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      LOWORD(v5) = 0x8000;
    }
    *a3 = result;
    *a2 = v5;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00161119) --------------------------------------------------------
int __usercall sub_161119(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int result; // eax

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( v4 > 0x7FFF )
    {
      v4 = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      v4 = -32768;
    }
    if ( v5 > 0x7FFF )
    {
      LOWORD(v5) = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      LOWORD(v5) = 0x8000;
    }
    result = v4 ^ 0x8000;
    *a3 = v5 ^ 0x8000;
    *a2 = result;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00161176) --------------------------------------------------------
int __usercall sub_161176(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int result; // eax
  int v5; // edx

  do
  {
    result = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( result > 0x7FFF )
    {
      result = 0x7FFF;
    }
    else if ( result < -32768 )
    {
      result = -32768;
    }
    if ( v5 > 0x7FFF )
    {
      LOWORD(v5) = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      LOWORD(v5) = 0x8000;
    }
    *a3 = v5;
    *a2 = result;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001611C8) --------------------------------------------------------
int __usercall sub_1611C8(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int16_t v6; // dx
  int result; // eax
  char v8; // t0
  char v9; // t1

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( v4 > 0x7FFF )
    {
      v4 = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      v4 = -32768;
    }
    if ( v5 > 0x7FFF )
    {
      LOWORD(v5) = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      LOWORD(v5) = 0x8000;
    }
    result = v4 ^ 0x8000;
    v6 = v5 ^ 0x8000;
    v8 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v8;
    v9 = v6;
    LOBYTE(v6) = HIBYTE(v6);
    HIBYTE(v6) = v9;
    *a3 = result;
    *a2 = v6;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00161229) --------------------------------------------------------
int16_t __usercall sub_161229(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int16_t result; // ax
  char v7; // t0
  int16_t v8; // dx
  char v9; // t1

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    if ( v5 > 0x7FFF )
    {
      LOWORD(v5) = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      LOWORD(v5) = 0x8000;
    }
    v7 = v4;
    LOBYTE(result) = BYTE1(v4);
    HIBYTE(result) = v7;
    v9 = v5;
    LOBYTE(v8) = BYTE1(v5);
    HIBYTE(v8) = v9;
    *a3 = result;
    *a2 = v8;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (0016127F) --------------------------------------------------------
int __usercall sub_16127F(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int16_t v6; // dx
  int result; // eax
  char v8; // t0
  char v9; // t1

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( v4 > 0x7FFF )
    {
      v4 = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      v4 = -32768;
    }
    if ( v5 > 0x7FFF )
    {
      LOWORD(v5) = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      LOWORD(v5) = 0x8000;
    }
    result = v4 ^ 0x8000;
    v6 = v5 ^ 0x8000;
    v8 = result;
    LOBYTE(result) = BYTE1(result);
    BYTE1(result) = v8;
    v9 = v6;
    LOBYTE(v6) = HIBYTE(v6);
    HIBYTE(v6) = v9;
    *a3 = v6;
    *a2 = result;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (001612E0) --------------------------------------------------------
int16_t __usercall sub_1612E0(int a1, _WORD *a2, _WORD *a3, int *a4)
{
  int v4; // eax
  int v5; // edx
  int16_t result; // ax
  char v7; // t0
  int16_t v8; // dx
  char v9; // t1

  do
  {
    v4 = *a4;
    v5 = a4[1];
    a4 += 2;
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    if ( v5 > 0x7FFF )
    {
      LOWORD(v5) = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      LOWORD(v5) = 0x8000;
    }
    v7 = v4;
    LOBYTE(result) = BYTE1(v4);
    HIBYTE(result) = v7;
    v9 = v5;
    LOBYTE(v8) = BYTE1(v5);
    HIBYTE(v8) = v9;
    *a3 = v8;
    *a2 = result;
    ++a3;
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}


//----- (00161336) --------------------------------------------------------
int __usercall sub_161336(int result, _DWORD *a2, _BYTE *a3)
{
  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    BYTE1(result) = *a3;
    result ^= 0x8000u;
    ++a3;
    *a2++ += (int16_t)result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161357) --------------------------------------------------------
int __usercall sub_161357(int result, _DWORD *a2, _BYTE *a3)
{
  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    BYTE1(result) = *a3;
    result ^= 0x8000u;
    ++a3;
    *a2 += (int16_t)result;
    a2[1] += (int16_t)result;
    a2 += 2;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (0016137B) --------------------------------------------------------
int __usercall sub_16137B(int result, _DWORD *a2, _BYTE *a3)
{
  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    BYTE1(result) = *a3;
    result ^= 0x8000u;
    a3 += 2;
    *a2++ += (int16_t)result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (001613A7) --------------------------------------------------------
int __usercall sub_1613A7(int result, int a2, _DWORD *a3, _BYTE *a4)
{
  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    BYTE1(result) = *a4;
    HIBYTE(a2) = a4[1];
    result ^= 0x8000u;
    a2 ^= 0x8000u;
    a4 += 2;
    *a3 += (int16_t)result;
    a3[1] += a2;
    a3 += 2;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (001613D9) --------------------------------------------------------
int __usercall sub_1613D9(int result, _DWORD *a2, unsigned int a3)
{
  do
  {
    if ( a3 >= dword_18AD30 )
      break;
    BYTE1(result) = *(_BYTE *)(a3 + 1);
    result ^= 0x8000u;
    a3 += 2;
    *a2++ += (int16_t)result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161405) --------------------------------------------------------
int __usercall sub_161405(int result, int a2, _DWORD *a3, _BYTE *a4)
{
  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    HIBYTE(a2) = *a4;
    BYTE1(result) = a4[1];
    result ^= 0x8000u;
    a2 ^= 0x8000u;
    a4 += 2;
    *a3 += (int16_t)result;
    a3[1] += a2;
    a3 += 2;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161437) --------------------------------------------------------
int16_t __usercall sub_161437(_DWORD *a1, _WORD *a2)
{
  int16_t result; // ax

  do
  {
    if ( (unsigned int)a2 >= dword_18AD30 )
      break;
    result = *a2++ ^ 0x8000;
    *a1++ += result;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (0016145B) --------------------------------------------------------
int16_t __usercall sub_16145B(_DWORD *a1, _WORD *a2)
{
  int16_t result; // ax

  do
  {
    if ( (unsigned int)a2 >= dword_18AD30 )
      break;
    result = *a2++ ^ 0x8000;
    *a1 += result;
    a1[1] += result;
    a1 += 2;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161482) --------------------------------------------------------
int16_t __usercall sub_161482(_DWORD *a1, _WORD *a2)
{
  int16_t result; // ax

  do
  {
    if ( (unsigned int)a2 >= dword_18AD30 )
      break;
    result = *a2 ^ 0x8000;
    a2 += 2;
    *a1++ += result;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (001614B0) --------------------------------------------------------
int16_t __usercall sub_1614B0(_DWORD *a1, _WORD *a2)
{
  int16_t result; // ax
  int16_t v3; // bx

  do
  {
    if ( (unsigned int)a2 >= dword_18AD30 )
      break;
    result = *a2 ^ 0x8000;
    v3 = a2[1] ^ 0x8000;
    a2 += 2;
    *a1 += result;
    a1[1] += v3;
    a1 += 2;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (001614E4) --------------------------------------------------------
int16_t __usercall sub_1614E4(_DWORD *a1, unsigned int a2)
{
  int16_t result; // ax

  do
  {
    if ( a2 >= dword_18AD30 )
      break;
    result = *(_WORD *)(a2 + 2) ^ 0x8000;
    a2 += 4;
    *a1++ += result;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161512) --------------------------------------------------------
int16_t __usercall sub_161512(_DWORD *a1, _WORD *a2)
{
  int16_t result; // ax
  int16_t v3; // bx

  do
  {
    if ( (unsigned int)a2 >= dword_18AD30 )
      break;
    result = a2[1] ^ 0x8000;
    v3 = *a2 ^ 0x8000;
    a2 += 2;
    *a1 += result;
    a1[1] += v3;
    a1 += 2;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161546) --------------------------------------------------------
int16_t __usercall sub_161546( int result, _DWORD *a2, _BYTE *a3)
{
  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    HIBYTE(result) = *a3++;
    *a2++ += result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161562) --------------------------------------------------------
int16_t __usercall sub_161562( int result, _DWORD *a2, _BYTE *a3)
{
  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    HIBYTE(result) = *a3++;
    *a2 += result;
    a2[1] += result;
    a2 += 2;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161581) --------------------------------------------------------
int16_t __usercall sub_161581( int result, _DWORD *a2, _BYTE *a3)
{
  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    HIBYTE(result) = *a3;
    a3 += 2;
    *a2++ += result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (001615A2) --------------------------------------------------------
int16_t __usercall sub_1615A2( int result, int a2, _DWORD *a3, _BYTE *a4)
{
  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    HIBYTE(result) = *a4;
    HIBYTE(a2) = a4[1];
    a4 += 2;
    *a3 += result;
    a3[1] += a2;
    a3 += 2;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (001615C9) --------------------------------------------------------
int16_t __usercall sub_1615C9( int result, _DWORD *a2, unsigned int a3)
{
  do
  {
    if ( a3 >= dword_18AD30 )
      break;
    HIBYTE(result) = *(_BYTE *)(a3 + 1);
    a3 += 2;
    *a2++ += result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (001615EA) --------------------------------------------------------
int16_t __usercall sub_1615EA( int result, int a2, _DWORD *a3, _BYTE *a4)
{
  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    HIBYTE(a2) = *a4;
    HIBYTE(result) = a4[1];
    a4 += 2;
    *a3 += result;
    a3[1] += a2;
    a3 += 2;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161611) --------------------------------------------------------
int16_t __usercall sub_161611(_DWORD *a1, int16_t *a2)
{
  int16_t result; // ax

  do
  {
    if ( (unsigned int)a2 >= dword_18AD30 )
      break;
    result = *a2++;
    *a1++ += result;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161630) --------------------------------------------------------
int16_t __usercall sub_161630(_DWORD *a1, int16_t *a2)
{
  int16_t result; // ax

  do
  {
    if ( (unsigned int)a2 >= dword_18AD30 )
      break;
    result = *a2++;
    *a1 += result;
    a1[1] += result;
    a1 += 2;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161652) --------------------------------------------------------
int16_t __usercall sub_161652(_DWORD *a1, int16_t *a2)
{
  int16_t result; // ax

  do
  {
    if ( (unsigned int)a2 >= dword_18AD30 )
      break;
    result = *a2;
    a2 += 2;
    *a1++ += result;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161675) --------------------------------------------------------
int16_t __usercall sub_161675(_DWORD *a1, int16_t *a2)
{
  int16_t result; // ax
  int16_t v3; // bx

  do
  {
    if ( (unsigned int)a2 >= dword_18AD30 )
      break;
    result = *a2;
    v3 = a2[1];
    a2 += 2;
    *a1 += result;
    a1[1] += v3;
    a1 += 2;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (0016169E) --------------------------------------------------------
int16_t __usercall sub_16169E(_DWORD *a1, unsigned int a2)
{
  int16_t result; // ax

  do
  {
    if ( a2 >= dword_18AD30 )
      break;
    result = *(_WORD *)(a2 + 2);
    a2 += 4;
    *a1++ += result;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (001616C1) --------------------------------------------------------
int16_t __usercall sub_1616C1(_DWORD *a1, int16_t *a2)
{
  int16_t v2; // bx
  int16_t result; // ax

  do
  {
    if ( (unsigned int)a2 >= dword_18AD30 )
      break;
    v2 = *a2;
    result = a2[1];
    a2 += 2;
    *a1 += result;
    a1[1] += v2;
    a1 += 2;
  }
  while ( (unsigned int)a1 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (001616EA) --------------------------------------------------------
int __usercall sub_1616EA(int result, unsigned int a2, _DWORD *a3, _BYTE *a4)
{
  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    BYTE1(result) = *a4;
    result ^= 0x8000u;
    a4 = (_BYTE *)((qword_18AD3C + __PAIR64__((unsigned int)a4, a2)) >> 32);
    a2 += qword_18AD3C;
    *a3++ += (int16_t)result;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161716) --------------------------------------------------------
int __usercall sub_161716(int result, unsigned int a2, _DWORD *a3, _BYTE *a4)
{
  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    BYTE1(result) = *a4;
    result ^= 0x8000u;
    a4 = (_BYTE *)((qword_18AD3C + __PAIR64__((unsigned int)a4, a2)) >> 32);
    a2 += qword_18AD3C;
    *a3 += (int16_t)result;
    a3[1] += (int16_t)result;
    a3 += 2;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161745) --------------------------------------------------------
int __usercall sub_161745(int result, unsigned int a2, _DWORD *a3, _BYTE *a4)
{
  int v4; // ebp

  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    BYTE1(result) = *a4;
    result ^= 0x8000u;
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a2) >> 32;
    a2 += qword_18AD3C;
    a4 += *((_DWORD *)&qword_18AD3C + v4 + 1);
    *a3++ += (int16_t)result;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (0016177F) --------------------------------------------------------
int __usercall sub_16177F(
        int result,
        unsigned int a2, int a3,
        _DWORD *a4,
        _BYTE *a5)
{
  int v5; // ebp

  do
  {
    if ( (unsigned int)a5 >= dword_18AD30 )
      break;
    BYTE1(result) = *a5;
    HIBYTE(a3) = a5[1];
    result ^= 0x8000u;
    a3 ^= 0x8000u;
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a2) >> 32;
    a2 += qword_18AD3C;
    a5 += *((_DWORD *)&qword_18AD3C + v5 + 1);
    *a4 += (int16_t)result;
    a4[1] += a3;
    a4 += 2;
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (001617BF) --------------------------------------------------------
int __usercall sub_1617BF(int result, unsigned int a2, _DWORD *a3, unsigned int a4)
{
  int v4; // ebp

  do
  {
    if ( a4 >= dword_18AD30 )
      break;
    BYTE1(result) = *(_BYTE *)(a4 + 1);
    result ^= 0x8000u;
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a2) >> 32;
    a2 += qword_18AD3C;
    a4 += *((_DWORD *)&qword_18AD3C + v4 + 1);
    *a3++ += (int16_t)result;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (001617F9) --------------------------------------------------------
int __usercall sub_1617F9(
        int result,
        unsigned int a2, int a3,
        _DWORD *a4,
        _BYTE *a5)
{
  int v5; // ebp

  do
  {
    if ( (unsigned int)a5 >= dword_18AD30 )
      break;
    HIBYTE(a3) = *a5;
    BYTE1(result) = a5[1];
    result ^= 0x8000u;
    a3 ^= 0x8000u;
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a2) >> 32;
    a2 += qword_18AD3C;
    a5 += *((_DWORD *)&qword_18AD3C + v5 + 1);
    *a4 += (int16_t)result;
    a4[1] += a3;
    a4 += 2;
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161839) --------------------------------------------------------
int16_t __usercall sub_161839(unsigned int a1, _DWORD *a2, _WORD *a3)
{
  int16_t result; // ax
  int v4; // ebp

  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    result = *a3 ^ 0x8000;
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 = (_WORD *)((char *)a3 + *((_DWORD *)&qword_18AD3C + v4 + 1));
    *a2++ += result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (0016186B) --------------------------------------------------------
int16_t __usercall sub_16186B(unsigned int a1, _DWORD *a2, _WORD *a3)
{
  int16_t result; // ax
  int v4; // ebp

  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    result = *a3 ^ 0x8000;
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 = (_WORD *)((char *)a3 + *((_DWORD *)&qword_18AD3C + v4 + 1));
    *a2 += result;
    a2[1] += result;
    a2 += 2;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (001618A0) --------------------------------------------------------
int16_t __usercall sub_1618A0(unsigned int a1, _DWORD *a2, _WORD *a3)
{
  int16_t result; // ax
  int v4; // ebp

  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    result = *a3 ^ 0x8000;
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 = (_WORD *)((char *)a3 + *((_DWORD *)&qword_18AD3C + v4 + 1));
    *a2++ += result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (001618DC) --------------------------------------------------------
int16_t __usercall sub_1618DC(unsigned int a1, _DWORD *a2, _WORD *a3)
{
  int16_t result; // ax
  int16_t v4; // bx
  int v5; // ebp

  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    result = *a3 ^ 0x8000;
    v4 = a3[1] ^ 0x8000;
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 = (_WORD *)((char *)a3 + *((_DWORD *)&qword_18AD3C + v5 + 1));
    *a2 += result;
    a2[1] += v4;
    a2 += 2;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (0016191E) --------------------------------------------------------
int16_t __usercall sub_16191E(unsigned int a1, _DWORD *a2, unsigned int a3)
{
  int16_t result; // ax
  int v4; // ebp

  do
  {
    if ( a3 >= dword_18AD30 )
      break;
    result = *(_WORD *)(a3 + 2) ^ 0x8000;
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 += *((_DWORD *)&qword_18AD3C + v4 + 1);
    *a2++ += result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (0016195A) --------------------------------------------------------
int16_t __usercall sub_16195A(unsigned int a1, _DWORD *a2, _WORD *a3)
{
  int16_t result; // ax
  int16_t v4; // bx
  int v5; // ebp

  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    result = a3[1] ^ 0x8000;
    v4 = *a3 ^ 0x8000;
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 = (_WORD *)((char *)a3 + *((_DWORD *)&qword_18AD3C + v5 + 1));
    *a2 += result;
    a2[1] += v4;
    a2 += 2;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (0016199C) --------------------------------------------------------
int16_t __usercall sub_16199C( int result, unsigned int a2, _DWORD *a3, _BYTE *a4)
{
  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    HIBYTE(result) = *a4;
    a4 = (_BYTE *)((qword_18AD3C + __PAIR64__((unsigned int)a4, a2)) >> 32);
    a2 += qword_18AD3C;
    *a3++ += result;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (001619C3) --------------------------------------------------------
int16_t __usercall sub_1619C3( int result, unsigned int a2, _DWORD *a3, _BYTE *a4)
{
  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    HIBYTE(result) = *a4;
    a4 = (_BYTE *)((qword_18AD3C + __PAIR64__((unsigned int)a4, a2)) >> 32);
    a2 += qword_18AD3C;
    *a3 += result;
    a3[1] += result;
    a3 += 2;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (001619ED) --------------------------------------------------------
int16_t __usercall sub_1619ED( int result, unsigned int a2, _DWORD *a3, _BYTE *a4)
{
  int v4; // ebp

  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    HIBYTE(result) = *a4;
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a2) >> 32;
    a2 += qword_18AD3C;
    a4 += *((_DWORD *)&qword_18AD3C + v4 + 1);
    *a3++ += result;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161A1C) --------------------------------------------------------
int16_t __usercall sub_161A1C( int result,
        unsigned int a2, int a3,
        _DWORD *a4,
        _BYTE *a5)
{
  int v5; // ebp

  do
  {
    if ( (unsigned int)a5 >= dword_18AD30 )
      break;
    HIBYTE(result) = *a5;
    HIBYTE(a3) = a5[1];
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a2) >> 32;
    a2 += qword_18AD3C;
    a5 += *((_DWORD *)&qword_18AD3C + v5 + 1);
    *a4 += result;
    a4[1] += a3;
    a4 += 2;
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161A51) --------------------------------------------------------
int16_t __usercall sub_161A51( int result, unsigned int a2, _DWORD *a3, unsigned int a4)
{
  int v4; // ebp

  do
  {
    if ( a4 >= dword_18AD30 )
      break;
    HIBYTE(result) = *(_BYTE *)(a4 + 1);
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a2) >> 32;
    a2 += qword_18AD3C;
    a4 += *((_DWORD *)&qword_18AD3C + v4 + 1);
    *a3++ += result;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161A80) --------------------------------------------------------
int16_t __usercall sub_161A80( int result,
        unsigned int a2, int a3,
        _DWORD *a4,
        _BYTE *a5)
{
  int v5; // ebp

  do
  {
    if ( (unsigned int)a5 >= dword_18AD30 )
      break;
    HIBYTE(a3) = *a5;
    HIBYTE(result) = a5[1];
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a2) >> 32;
    a2 += qword_18AD3C;
    a5 += *((_DWORD *)&qword_18AD3C + v5 + 1);
    *a4 += result;
    a4[1] += a3;
    a4 += 2;
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161AB5) --------------------------------------------------------
int16_t __usercall sub_161AB5(unsigned int a1, _DWORD *a2, int16_t *a3)
{
  int16_t result; // ax
  int v4; // ebp

  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    result = *a3;
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 = (int16_t *)((char *)a3 + *((_DWORD *)&qword_18AD3C + v4 + 1));
    *a2++ += result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161AE2) --------------------------------------------------------
int16_t __usercall sub_161AE2(unsigned int a1, _DWORD *a2, int16_t *a3)
{
  int16_t result; // ax
  int v4; // ebp

  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    result = *a3;
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 = (int16_t *)((char *)a3 + *((_DWORD *)&qword_18AD3C + v4 + 1));
    *a2 += result;
    a2[1] += result;
    a2 += 2;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161B12) --------------------------------------------------------
int16_t __usercall sub_161B12(unsigned int a1, _DWORD *a2, int16_t *a3)
{
  int16_t result; // ax
  int v4; // ebp

  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    result = *a3;
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 = (int16_t *)((char *)a3 + *((_DWORD *)&qword_18AD3C + v4 + 1));
    *a2++ += result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161B43) --------------------------------------------------------
int16_t __usercall sub_161B43(unsigned int a1, _DWORD *a2, int16_t *a3)
{
  int16_t result; // ax
  int16_t v4; // bx
  int v5; // ebp

  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    result = *a3;
    v4 = a3[1];
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 = (int16_t *)((char *)a3 + *((_DWORD *)&qword_18AD3C + v5 + 1));
    *a2 += result;
    a2[1] += v4;
    a2 += 2;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161B7A) --------------------------------------------------------
int16_t __usercall sub_161B7A(unsigned int a1, _DWORD *a2, unsigned int a3)
{
  int16_t result; // ax
  int v4; // ebp

  do
  {
    if ( a3 >= dword_18AD30 )
      break;
    result = *(_WORD *)(a3 + 2);
    v4 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 += *((_DWORD *)&qword_18AD3C + v4 + 1);
    *a2++ += result;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161BAB) --------------------------------------------------------
int16_t __usercall sub_161BAB(unsigned int a1, _DWORD *a2, int16_t *a3)
{
  int16_t v3; // bx
  int16_t result; // ax
  int v5; // ebp

  do
  {
    if ( (unsigned int)a3 >= dword_18AD30 )
      break;
    v3 = *a3;
    result = a3[1];
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a1) >> 32;
    a1 += qword_18AD3C;
    a3 = (int16_t *)((char *)a3 + *((_DWORD *)&qword_18AD3C + v5 + 1));
    *a2 += result;
    a2[1] += v3;
    a2 += 2;
  }
  while ( (unsigned int)a2 < dword_18AD38 );
  return result;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161BE2) --------------------------------------------------------
char __usercall sub_161BE2(int a1, int a2, _DWORD *a3, _BYTE *a4)
{
  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *a4++;
    *a3++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161BFE) --------------------------------------------------------
char __usercall sub_161BFE(int a1, int a2, _DWORD *a3, _BYTE *a4)
{
  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *a4++;
    *a3 += *(_DWORD *)(a2 + 4 * a1);
    a3[1] += *(_DWORD *)(a2 + 4 * a1 + 1024);
    a3 += 2;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161C24) --------------------------------------------------------
char __usercall sub_161C24(int a1, int a2, _DWORD *a3, _BYTE *a4)
{
  do
  {
    if ( (unsigned int)a4 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *a4;
    a4 += 2;
    *a3++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161C45) --------------------------------------------------------
char __usercall sub_161C45(int a1, int a2, int a3, _DWORD *a4, _BYTE *a5)
{
  do
  {
    if ( (unsigned int)a5 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *a5;
    LOBYTE(a3) = a5[1];
    a5 += 2;
    *a4 += *(_DWORD *)(a2 + 4 * a1);
    a4[1] += *(_DWORD *)(a2 + 4 * a3 + 1024);
    a4 += 2;
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161C70) --------------------------------------------------------
char __usercall sub_161C70(int a1, int a2, _DWORD *a3, unsigned int a4)
{
  do
  {
    if ( a4 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a4 + 1);
    a4 += 2;
    *a3++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161C91) --------------------------------------------------------
char __usercall sub_161C91(int a1, int a2, int a3, _DWORD *a4, _BYTE *a5)
{
  do
  {
    if ( (unsigned int)a5 >= dword_18AD30 )
      break;
    LOBYTE(a3) = *a5;
    LOBYTE(a1) = a5[1];
    a5 += 2;
    *a4 += *(_DWORD *)(a2 + 4 * a1);
    a4[1] += *(_DWORD *)(a2 + 4 * a3 + 1024);
    a4 += 2;
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161CBC) --------------------------------------------------------
char __usercall sub_161CBC(int a1, int a2, _DWORD *a3, unsigned int a4)
{
  do
  {
    if ( a4 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a4 + 1);
    a4 += 2;
    *a3++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161CDB) --------------------------------------------------------
char __usercall sub_161CDB(int a1, int a2, _DWORD *a3, unsigned int a4)
{
  do
  {
    if ( a4 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a4 + 1);
    a4 += 2;
    *a3 += *(_DWORD *)(a2 + 4 * a1);
    a3[1] += *(_DWORD *)(a2 + 4 * a1 + 1024);
    a3 += 2;
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161D04) --------------------------------------------------------
char __usercall sub_161D04(int a1, int a2, _DWORD *a3, unsigned int a4)
{
  do
  {
    if ( a4 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a4 + 1);
    a4 += 4;
    *a3++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161D26) --------------------------------------------------------
char __usercall sub_161D26(int a1, int a2, int a3, _DWORD *a4, unsigned int a5)
{
  do
  {
    if ( a5 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a5 + 1);
    LOBYTE(a3) = *(_BYTE *)(a5 + 3);
    a5 += 4;
    *a4 += *(_DWORD *)(a2 + 4 * a1);
    a4[1] += *(_DWORD *)(a2 + 4 * a3 + 1024);
    a4 += 2;
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161D52) --------------------------------------------------------
char __usercall sub_161D52(int a1, int a2, _DWORD *a3, unsigned int a4)
{
  do
  {
    if ( a4 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a4 + 3);
    a4 += 4;
    *a3++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a3 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161D74) --------------------------------------------------------
char __usercall sub_161D74(int a1, int a2, int a3, _DWORD *a4, unsigned int a5)
{
  do
  {
    if ( a5 >= dword_18AD30 )
      break;
    LOBYTE(a3) = *(_BYTE *)(a5 + 1);
    LOBYTE(a1) = *(_BYTE *)(a5 + 3);
    a5 += 4;
    *a4 += *(_DWORD *)(a2 + 4 * a1);
    a4[1] += *(_DWORD *)(a2 + 4 * a3 + 1024);
    a4 += 2;
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;


//----- (00161DA0) --------------------------------------------------------
char __usercall sub_161DA0(int a1, int a2, unsigned int a3, _DWORD *a4, _BYTE *a5)
{
  do
  {
    if ( (unsigned int)a5 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *a5;
    a5 = (_BYTE *)((qword_18AD3C + __PAIR64__((unsigned int)a5, a3)) >> 32);
    a3 += qword_18AD3C;
    *a4++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161DC7) --------------------------------------------------------
char __usercall sub_161DC7(int a1, int a2, unsigned int a3, _DWORD *a4, _BYTE *a5)
{
  do
  {
    if ( (unsigned int)a5 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *a5;
    a5 = (_BYTE *)((qword_18AD3C + __PAIR64__((unsigned int)a5, a3)) >> 32);
    a3 += qword_18AD3C;
    *a4 += *(_DWORD *)(a2 + 4 * a1);
    a4[1] += *(_DWORD *)(a2 + 4 * a1 + 1024);
    a4 += 2;
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161DF8) --------------------------------------------------------
char __usercall sub_161DF8(int a1, int a2, unsigned int a3, _DWORD *a4, _BYTE *a5)
{
  int v5; // ebp

  do
  {
    if ( (unsigned int)a5 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *a5;
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a3) >> 32;
    a3 += qword_18AD3C;
    a5 += *((_DWORD *)&qword_18AD3C + v5 + 1);
    *a4++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161E27) --------------------------------------------------------
char __usercall sub_161E27(
        int a1,
        int a2,
        unsigned int a3,
        int a4,
        _DWORD *a5,
        _BYTE *a6)
{
  int v6; // ebp

  do
  {
    if ( (unsigned int)a6 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *a6;
    LOBYTE(a4) = a6[1];
    v6 = ((unsigned int)qword_18AD3C + (uint64_t)a3) >> 32;
    a3 += qword_18AD3C;
    a6 += *((_DWORD *)&qword_18AD3C + v6 + 1);
    *a5 += *(_DWORD *)(a2 + 4 * a1);
    a5[1] += *(_DWORD *)(a2 + 4 * a4 + 1024);
    a5 += 2;
  }
  while ( (unsigned int)a5 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161E60) --------------------------------------------------------
char __usercall sub_161E60(
        int a1,
        int a2,
        unsigned int a3,
        _DWORD *a4,
        unsigned int a5)
{
  int v5; // ebp

  do
  {
    if ( a5 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a5 + 1);
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a3) >> 32;
    a3 += qword_18AD3C;
    a5 += *((_DWORD *)&qword_18AD3C + v5 + 1);
    *a4++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161E8F) --------------------------------------------------------
char __usercall sub_161E8F(
        int a1,
        int a2,
        unsigned int a3,
        int a4,
        _DWORD *a5,
        _BYTE *a6)
{
  int v6; // ebp

  do
  {
    if ( (unsigned int)a6 >= dword_18AD30 )
      break;
    LOBYTE(a4) = *a6;
    LOBYTE(a1) = a6[1];
    v6 = ((unsigned int)qword_18AD3C + (uint64_t)a3) >> 32;
    a3 += qword_18AD3C;
    a6 += *((_DWORD *)&qword_18AD3C + v6 + 1);
    *a5 += *(_DWORD *)(a2 + 4 * a1);
    a5[1] += *(_DWORD *)(a2 + 4 * a4 + 1024);
    a5 += 2;
  }
  while ( (unsigned int)a5 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161EC8) --------------------------------------------------------
char __usercall sub_161EC8(
        int a1,
        int a2,
        unsigned int a3,
        _DWORD *a4,
        unsigned int a5)
{
  int v5; // ebp

  do
  {
    if ( a5 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a5 + 1);
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a3) >> 32;
    a3 += qword_18AD3C;
    a5 += *((_DWORD *)&qword_18AD3C + v5 + 1);
    *a4++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161EF5) --------------------------------------------------------
char __usercall sub_161EF5(
        int a1,
        int a2,
        unsigned int a3,
        _DWORD *a4,
        unsigned int a5)
{
  int v5; // ebp

  do
  {
    if ( a5 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a5 + 1);
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a3) >> 32;
    a3 += qword_18AD3C;
    a5 += *((_DWORD *)&qword_18AD3C + v5 + 1);
    *a4 += *(_DWORD *)(a2 + 4 * a1);
    a4[1] += *(_DWORD *)(a2 + 4 * a1 + 1024);
    a4 += 2;
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161F2C) --------------------------------------------------------
char __usercall sub_161F2C(
        int a1,
        int a2,
        unsigned int a3,
        _DWORD *a4,
        unsigned int a5)
{
  int v5; // ebp

  do
  {
    if ( a5 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a5 + 1);
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a3) >> 32;
    a3 += qword_18AD3C;
    a5 += *((_DWORD *)&qword_18AD3C + v5 + 1);
    *a4++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161F5C) --------------------------------------------------------
char __usercall sub_161F5C(
        int a1,
        int a2,
        unsigned int a3,
        int a4,
        _DWORD *a5,
        unsigned int a6)
{
  int v6; // ebp

  do
  {
    if ( a6 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a6 + 1);
    LOBYTE(a4) = *(_BYTE *)(a6 + 3);
    v6 = ((unsigned int)qword_18AD3C + (uint64_t)a3) >> 32;
    a3 += qword_18AD3C;
    a6 += *((_DWORD *)&qword_18AD3C + v6 + 1);
    *a5 += *(_DWORD *)(a2 + 4 * a1);
    a5[1] += *(_DWORD *)(a2 + 4 * a4 + 1024);
    a5 += 2;
  }
  while ( (unsigned int)a5 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161F96) --------------------------------------------------------
char __usercall sub_161F96(
        int a1,
        int a2,
        unsigned int a3,
        _DWORD *a4,
        unsigned int a5)
{
  int v5; // ebp

  do
  {
    if ( a5 >= dword_18AD30 )
      break;
    LOBYTE(a1) = *(_BYTE *)(a5 + 3);
    v5 = ((unsigned int)qword_18AD3C + (uint64_t)a3) >> 32;
    a3 += qword_18AD3C;
    a5 += *((_DWORD *)&qword_18AD3C + v5 + 1);
    *a4++ += *(_DWORD *)(a2 + 4 * a1);
  }
  while ( (unsigned int)a4 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00161FC6) --------------------------------------------------------
char __usercall sub_161FC6(
        int a1,
        int a2,
        unsigned int a3,
        int a4,
        _DWORD *a5,
        unsigned int a6)
{
  int v6; // ebp

  do
  {
    if ( a6 >= dword_18AD30 )
      break;
    LOBYTE(a4) = *(_BYTE *)(a6 + 1);
    LOBYTE(a1) = *(_BYTE *)(a6 + 3);
    v6 = ((unsigned int)qword_18AD3C + (uint64_t)a3) >> 32;
    a3 += qword_18AD3C;
    a6 += *((_DWORD *)&qword_18AD3C + v6 + 1);
    *a5 += *(_DWORD *)(a2 + 4 * a1);
    a5[1] += *(_DWORD *)(a2 + 4 * a4 + 1024);
    a5 += 2;
  }
  while ( (unsigned int)a5 < dword_18AD38 );
  return a1;
}
// 18AD30: using guessed type int dword_18AD30;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;


//----- (00162000) --------------------------------------------------------
int __cdecl sub_162000(int a1)
{
  int v1; // ecx
  _DWORD *v2; // edi
  int v3; // eax
  uint64_t v4; // rax
  int v5; // eax
  char *v6; // edx
  unsigned int v7; // eax
  int v8; // ebx
  _DWORD *v9; // edi
  int v10; // ebx
  unsigned int v11; // esi
  int v12; // ebx
  int result; // eax
  int v14; // ebx

  v1 = a1;
  v2 = *(_DWORD **)a1;
  v3 = 0;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 24) == 2 || v2[6] == 3 )
    v3 = 1;
  if ( *(_DWORD *)(a1 + 52) == 2 || *(_DWORD *)(a1 + 52) == 3 )
  {
    v3 |= 2u;
    if ( (*(_DWORD *)(a1 + 56) & 2) != 0 )
      v3 |= 4u;
  }
  if ( *(_DWORD *)(a1 + 52) == 1 || *(_DWORD *)(a1 + 52) == 3 )
    v3 |= 8u;
  if ( *(_DWORD *)(a1 + 64) == 127 && *(_DWORD *)(a1 + 68) == 64 )
  {
    if ( (*(_DWORD *)(a1 + 56) & 1) != 0 )
      v3 |= 0x10u;
  }
  else
  {
    v3 |= 0x40u;
  }
  dword_18AD28 = v3;
  LODWORD(v4) = 0;
  HIDWORD(v4) = *(_DWORD *)(a1 + 60);
  if ( SHIDWORD(v4) <= 0 )
    HIDWORD(v4) = 1;
  v5 = v4 / (unsigned int)(v2[5] << 16);
  v6 = (char *)(v5 - (_DWORD)sub_10000);
  if ( v5 <= (int)sub_10000 )
    v6 = (char *)sub_10000 - v5;
  if ( (unsigned int)v6 > dword_1C9558 )
  {
    LODWORD(qword_18AD3C) = v5 << 16;
    v7 = HIWORD(v5);
    v8 = v7 + 1;
    if ( (dword_18AD28 & 2) != 0 )
    {
      v7 *= 2;
      v8 *= 2;
    }
    if ( (dword_18AD28 & 8) != 0 )
    {
      v7 *= 2;
      v8 *= 2;
    }
    HIDWORD(qword_18AD3C) = v7;
    dword_18AD44 = v8;
    dword_18AD28 |= 0x20u;
  }
  dword_18AD34 = v2[20];
  dword_18AD38 = v2[19] + dword_18AD34;
  v9 = (_DWORD *)dword_18AD34;
  do
  {
    v10 = *(_DWORD *)(v1 + 40);
    dword_18AD2C = *(_DWORD *)(v1 + 4 * v10 + 24) + *(_DWORD *)(v1 + 4 * v10 + 8);
    dword_18AD30 = *(_DWORD *)(v1 + 4 * v10 + 16) + *(_DWORD *)(v1 + 4 * v10 + 8);
    if ( *(_DWORD *)(v1 + 2120) )
      (*(void (__stdcall **)(int))(v1 + 2120))(v1);
    v11 = dword_18AD2C;
    ((void (__usercall *)(int, _DWORD *, _BYTE *))funcs_16213C[dword_18AD28])(
      0,
      v9,
      (_BYTE *)dword_18AD2C);
    v1 = a1;
    v12 = *(_DWORD *)(a1 + 40);
    result = v11 - *(_DWORD *)(a1 + 4 * v12 + 8);
    *(_DWORD *)(a1 + 4 * v12 + 24) = result;
    if ( v11 < dword_18AD30 )
      break;
    if ( *(_DWORD *)(a1 + 2124) )
      result = (*(int (__stdcall **)(int))(a1 + 2124))(a1);
    if ( *(_DWORD *)(a1 + 48) )
    {
      if ( *(_DWORD *)(a1 + 48) == 1 )
      {
        v14 = *(_DWORD *)(a1 + 40) ^ 1;
        if ( *(_DWORD *)(a1 + 4 * v14 + 32) )
        {
          *(_DWORD *)(a1 + 4) = 2;
          if ( *(_DWORD *)(a1 + 2128) )
            return (*(int (__stdcall **)(int))(a1 + 2128))(a1);
          return result;
        }
        if ( !*(_DWORD *)(a1 + 4 * v14 + 16) || *(_DWORD *)(a1 + 4 * v14 + 24) )
          return result;
        *(_DWORD *)(a1 + 40) = v14;
      }
      else
      {
        --*(_DWORD *)(a1 + 48);
      }
    }
    *(_DWORD *)(a1 + 4 * *(_DWORD *)(a1 + 40) + 24) = 0;
  }
  while ( (unsigned int)v9 < dword_18AD38 );
  return result;
}
// 10000: using guessed type void __noreturn sub_10000();
// 1604F8: using guessed type int (*funcs_16213C[4])();
// 18AD28: using guessed type int dword_18AD28;
// 18AD2C: using guessed type int dword_18AD2C;
// 18AD30: using guessed type int dword_18AD30;
// 18AD34: using guessed type int dword_18AD34;
// 18AD38: using guessed type int dword_18AD38;
// 18AD3C: using guessed type int64_t qword_18AD3C;
// 18AD44: using guessed type int dword_18AD44;
// 1C9558: using guessed type int dword_1C9558;


//----- (00162201) --------------------------------------------------------
int __cdecl sub_162201(_DWORD *a1, int a2)
{
  int v2; // eax
  int *v3; // esi
  int v4; // ecx
  _BYTE *v5; // edi

  v2 = a1[7] & 0xF;
  if ( a1[6] == 2 || a1[6] == 3 )
    v2 |= 0x10u;
  if ( a1[6] == 1 || a1[6] == 3 )
    v2 |= 0x20u;
  if ( a1[25] )
    v2 |= 0x40u;
  dword_18AD28 = v2;
  v3 = (int *)a1[20];
  v4 = a1[18];
  if ( (a1[7] & 0x20) != 0 )
  {
    dword_18AD28 |= 8u;
    v5 = (_BYTE *)(a2 * (a1[4] >> 1) + a1[11]);
  }
  else
  {
    v5 = (_BYTE *)a1[a2 + 11];
  }
  return ((int (__usercall *)(int, _BYTE *, int *))off_1602F8[dword_18AD28])(v4, v5, v3);
}
// 1602F8: using guessed type int (*off_1602F8[2])();
// 18AD28: using guessed type int dword_18AD28;


//----- (00162293) --------------------------------------------------------
int __cdecl sub_162293(int a1)
{
  char *v1; // edi
  int result; // eax
  unsigned int v3; // [esp-Ch] [ebp-18h]

  v1 = *(char **)(a1 + 80);
  result = 0;
  v3 = *(_DWORD *)(a1 + 76);
  memset(v1, 0, v3 & 3);
  memset(&v1[v3 & 3], 0, 4 * (v3 >> 2));
  return result;
}


//----- (001622BF) --------------------------------------------------------
bool sub_1622BF()
{
  sub_15421D((unsigned int)&dword_18AD28, (unsigned int)&off_18AD48);
  return sub_15421D((unsigned int)off_1602F8, (unsigned int)sub_1622BF);
}
// 1602F8: using guessed type int (*off_1602F8[2])();
// 18AD28: using guessed type int dword_18AD28;
// 18AD48: using guessed type void (__noreturn *off_18AD48)();


//----- (001622EE) --------------------------------------------------------
int __fastcall sub_1622EE(int a1)
{
  int v3; // [esp+4h] [ebp-8h]

  v3 = nmalloc(13);
  if ( !v3 )
    return 0;
  *(_DWORD *)v3 = a1;
  *(_DWORD *)(v3 + 5) = 0;
  *(_BYTE *)(v3 + 4) = 0x80;
  *(_DWORD *)(v3 + 9) = 0;
  return v3;
}
// 13CB78: using guessed type int __fastcall nmalloc(_DWORD);


//----- (00162359) --------------------------------------------------------
int __fastcall sub_162359(int a1)
{
  int v3; // [esp+4h] [ebp-8h]

  v3 = nmalloc(13);
  if ( !v3 )
    return 0;
  *(_DWORD *)v3 = a1;
  *(_DWORD *)(v3 + 5) = 0;
  *(_BYTE *)(v3 + 4) = 0x80;
  *(_DWORD *)(v3 + 9) = 0;
  return v3;
}
// 13CB78: using guessed type int __fastcall nmalloc(_DWORD);


//----- (001623C4) --------------------------------------------------------
int __fastcall sub_1623C4(int a1)
{
  int v2; // [esp+4h] [ebp-8h]

  if ( *(uint8_t *)(a1 + 4) != 128 )
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 9) + *(_DWORD *)a1) = *(_BYTE *)(a1 + 5);
    ++*(_DWORD *)(a1 + 9);
  }
  v2 = *(_DWORD *)(a1 + 9);
  nfree(a1);
  return v2;
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);


//----- (0016242D) --------------------------------------------------------
int __fastcall sub_16242D(int a1)
{
  return nfree(a1);
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);


//----- (00162459) --------------------------------------------------------
int __fastcall sub_162459(int result, int a2)
{
  _BYTE *v2; // eax
  int v3; // [esp+8h] [ebp-8h]

  v3 = result;
  if ( a2 )
    *(_DWORD *)(result + 5) |= *(uint8_t *)(result + 4);
  *(_BYTE *)(result + 4) >>= 1;
  if ( !*(_BYTE *)(result + 4) )
  {
    *(_BYTE *)(*(_DWORD *)(result + 9) + *(_DWORD *)result) = *(_BYTE *)(result + 5);
    ++*(_DWORD *)(result + 9);
    if ( (*(_WORD *)(result + 9) & 0x7FF) == 0 )
    {
      if ( (byte_188DCB & 4) != 0 || (unsigned int)(dword_188DD2 - dword_188DC2) <= 1 )
      {
        fputc(46, &dword_188DBE);
      }
      else
      {
        v2 = (_BYTE *)dword_188DBE;
        *(_BYTE *)dword_188DBE = 46;
        if ( *v2 == 10 )
        {
          fputc(10, &dword_188DBE);
        }
        else
        {
          byte_188DCB |= 0x10u;
          ++dword_188DC2;
          ++dword_188DBE;
        }
      }
    }
    *(_DWORD *)(v3 + 5) = 0;
    result = v3;
    *(_BYTE *)(v3 + 4) = 0x80;
  }
  return result;
}
// 148337: using guessed type int __fastcall fputc(_DWORD, _DWORD);
// 188DBE: using guessed type int dword_188DBE;
// 188DC2: using guessed type int dword_188DC2;
// 188DCB: using guessed type char byte_188DCB;
// 188DD2: using guessed type int dword_188DD2;


//----- (00162559) --------------------------------------------------------
int __fastcall sub_162559(int a1, int a2, int a3)
{
  int result; // eax
  _BYTE *v4; // eax
  unsigned int i; // [esp+14h] [ebp-4h]

  result = 1 << (a3 - 1);
  for ( i = result; i; i >>= 1 )
  {
    if ( (i & a2) != 0 )
      *(_DWORD *)(a1 + 5) |= *(uint8_t *)(a1 + 4);
    *(_BYTE *)(a1 + 4) >>= 1;
    result = a1;
    if ( !*(_BYTE *)(a1 + 4) )
    {
      *(_BYTE *)(*(_DWORD *)(a1 + 9) + *(_DWORD *)a1) = *(_BYTE *)(a1 + 5);
      ++*(_DWORD *)(a1 + 9);
      if ( (*(_WORD *)(a1 + 9) & 0x7FF) == 0 )
      {
        if ( (byte_188DCB & 4) != 0 || (unsigned int)(dword_188DD2 - dword_188DC2) <= 1 )
        {
          fputc(46, &dword_188DBE);
        }
        else
        {
          v4 = (_BYTE *)dword_188DBE;
          *(_BYTE *)dword_188DBE = 46;
          if ( *v4 == 10 )
          {
            fputc(10, &dword_188DBE);
          }
          else
          {
            byte_188DCB |= 0x10u;
            ++dword_188DC2;
            ++dword_188DBE;
          }
        }
      }
      *(_DWORD *)(a1 + 5) = 0;
      result = a1;
      *(_BYTE *)(a1 + 4) = 0x80;
    }
  }
  return result;
}
// 148337: using guessed type int __fastcall fputc(_DWORD, _DWORD);
// 188DBE: using guessed type int dword_188DBE;
// 188DC2: using guessed type int dword_188DC2;
// 188DCB: using guessed type char byte_188DCB;
// 188DD2: using guessed type int dword_188DD2;


//----- (0016267C) --------------------------------------------------------
bool __fastcall sub_16267C(int a1)
{
  _BYTE *v1; // eax
  int v4; // [esp+10h] [ebp-8h]

  if ( *(uint8_t *)(a1 + 4) == 128 )
  {
    *(_DWORD *)(a1 + 5) = *(uint8_t *)(*(_DWORD *)a1 + (*(_DWORD *)(a1 + 9))++);
    if ( (*(_WORD *)(a1 + 9) & 0x7FF) == 0 )
    {
      if ( (byte_188DCB & 4) != 0 || (unsigned int)(dword_188DD2 - dword_188DC2) <= 1 )
      {
        fputc(46, &dword_188DBE);
      }
      else
      {
        v1 = (_BYTE *)dword_188DBE;
        *(_BYTE *)dword_188DBE = 46;
        if ( *v1 == 10 )
        {
          fputc(10, &dword_188DBE);
        }
        else
        {
          byte_188DCB |= 0x10u;
          ++dword_188DC2;
          ++dword_188DBE;
        }
      }
    }
  }
  v4 = *(uint8_t *)(a1 + 4) & *(_DWORD *)(a1 + 5);
  *(_BYTE *)(a1 + 4) >>= 1;
  if ( !*(_BYTE *)(a1 + 4) )
    *(_BYTE *)(a1 + 4) = 0x80;
  return v4 != 0;
}
// 148337: using guessed type int __fastcall fputc(_DWORD, _DWORD);
// 188DBE: using guessed type int dword_188DBE;
// 188DC2: using guessed type int dword_188DC2;
// 188DCB: using guessed type char byte_188DCB;
// 188DD2: using guessed type int dword_188DD2;


//----- (00162B06) --------------------------------------------------------
uint8_t ***__fastcall sub_162B06(uint8_t ***result, int a2)
{
  uint8_t *v2; // eax
  uint8_t *v3; // edx
  int v4; // edx
  _BYTE *v5; // eax
  char v6; // [esp+0h] [ebp-18h]
  int v7; // [esp+8h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-Ch]
  uint8_t ***v9; // [esp+10h] [ebp-8h]

  v9 = result;
  if ( a2 )
    *(uint8_t ***)((char *)result + 5) = (uint8_t **)(*((uint8_t *)result + 4)
                                                                    | *(unsigned int *)((char *)result + 5));
  *((_BYTE *)result + 4) >>= 1;
  if ( !*((_BYTE *)result + 4) )
  {
    if ( (*((_BYTE *)*result + 13) & 4) != 0 || (unsigned int)((*result)[5] - (*result)[1]) <= 1 )
    {
      v7 = fputc(*(uint8_t ***)((char *)result + 5), *result);
    }
    else
    {
      v2 = **result;
      *v2 = *((_BYTE *)v9 + 5);
      if ( *v2 == 10 )
      {
        v8 = fputc(10, *v9);
      }
      else
      {
        *((_BYTE *)*v9 + 13) |= 0x10u;
        ++(*v9)[1];
        v3 = **v9;
        **v9 = v3 + 1;
        v8 = *v3;
      }
      v7 = v8;
    }
    if ( (uint8_t **)v7 != *(uint8_t ***)((char *)v9 + 5) )
      sub_163233((int)aFatalErrorInOu, v6);
    v4 = *(int *)((char *)v9 + 9);
    *(uint8_t ***)((char *)v9 + 9) = (uint8_t **)(v4 + 1);
    if ( (v4 & 0x7FF) == 0 )
    {
      if ( (byte_188DCB & 4) != 0 || (unsigned int)(dword_188DD2 - dword_188DC2) <= 1 )
      {
        fputc(46, &dword_188DBE);
      }
      else
      {
        v5 = (_BYTE *)dword_188DBE;
        *(_BYTE *)dword_188DBE = 46;
        if ( *v5 == 10 )
        {
          fputc(10, &dword_188DBE);
        }
        else
        {
          byte_188DCB |= 0x10u;
          ++dword_188DC2;
          ++dword_188DBE;
        }
      }
    }
    *(uint8_t ***)((char *)v9 + 5) = 0;
    result = v9;
    *((_BYTE *)v9 + 4) = 0x80;
  }
  return result;
}
// 162BEB: variable 'v6' is possibly undefined
// 148337: using guessed type int __fastcall fputc(_DWORD, _DWORD);
// 188DBE: using guessed type int dword_188DBE;
// 188DC2: using guessed type int dword_188DC2;
// 188DCB: using guessed type char byte_188DCB;
// 188DD2: using guessed type int dword_188DD2;


//----- (00162CA3) --------------------------------------------------------
int __fastcall sub_162CA3(uint8_t ***a1, int a2, int a3)
{
  int result; // eax
  uint8_t *v4; // eax
  uint8_t *v5; // edx
  int v6; // edx
  _BYTE *v7; // eax
  char *v8; // edx
  char v9; // [esp+0h] [ebp-20h]
  int v10; // [esp+8h] [ebp-18h]
  int v11; // [esp+Ch] [ebp-14h]
  unsigned int i; // [esp+1Ch] [ebp-4h]

  result = 1 << (a3 - 1);
  for ( i = result; i; i >>= 1 )
  {
    if ( (i & a2) != 0 )
      *(uint8_t ***)((char *)a1 + 5) = (uint8_t **)(*((uint8_t *)a1 + 4)
                                                                  | *(unsigned int *)((char *)a1 + 5));
    *((_BYTE *)a1 + 4) >>= 1;
    result = (int)a1;
    if ( !*((_BYTE *)a1 + 4) )
    {
      if ( (*((_BYTE *)*a1 + 13) & 4) != 0 || (unsigned int)((*a1)[5] - (*a1)[1]) <= 1 )
      {
        v10 = fputc(*(uint8_t ***)((char *)a1 + 5), *a1);
      }
      else
      {
        v4 = **a1;
        *v4 = *((_BYTE *)a1 + 5);
        if ( *v4 == 10 )
        {
          v11 = fputc(10, *a1);
        }
        else
        {
          *((_BYTE *)*a1 + 13) |= 0x10u;
          ++(*a1)[1];
          v5 = **a1;
          **a1 = v5 + 1;
          v11 = *v5;
        }
        v10 = v11;
      }
      if ( (uint8_t **)v10 != *(uint8_t ***)((char *)a1 + 5) )
        sub_163233((int)aFatalErrorInOu, v9);
      v6 = *(int *)((char *)a1 + 9);
      *(uint8_t ***)((char *)a1 + 9) = (uint8_t **)(v6 + 1);
      if ( (v6 & 0x7FF) == 0 )
      {
        if ( (byte_188DCB & 4) != 0 || (unsigned int)(dword_188DD2 - dword_188DC2) <= 1 )
        {
          fputc(46, &dword_188DBE);
        }
        else
        {
          v7 = (_BYTE *)dword_188DBE;
          *(_BYTE *)dword_188DBE = 46;
          if ( *v7 == 10 )
          {
            v9 = fputc(10, &dword_188DBE);
          }
          else
          {
            byte_188DCB |= 0x10u;
            ++dword_188DC2;
            v8 = (char *)dword_188DBE++;
            v9 = *v8;
          }
        }
      }
      *(uint8_t ***)((char *)a1 + 5) = 0;
      result = (int)a1;
      *((_BYTE *)a1 + 4) = 0x80;
    }
  }
  return result;
}
// 162DA4: variable 'v9' is possibly undefined
// 148337: using guessed type int __fastcall fputc(_DWORD, _DWORD);
// 188DBE: using guessed type int dword_188DBE;
// 188DC2: using guessed type int dword_188DC2;
// 188DCB: using guessed type char byte_188DCB;
// 188DD2: using guessed type int dword_188DD2;


//----- (00162E63) --------------------------------------------------------
bool __fastcall sub_162E63(_DWORD *a1, int a2)
{
  uint8_t *v2; // edx
  int v3; // edx
  _BYTE *v4; // eax
  char v6; // [esp+0h] [ebp-1Ch]
  int v7; // [esp+Ch] [ebp-10h]
  int v9; // [esp+14h] [ebp-8h]

  if ( *((uint8_t *)a1 + 4) == 128 )
  {
    if ( *(int *)(*a1 + 4) <= 0 || (*(_BYTE *)(*a1 + 12) & 4) != 0 || **(_BYTE **)*a1 == 13 || **(_BYTE **)*a1 == 26 )
    {
      v7 = fgetc(*a1, a2);
    }
    else
    {
      --*(_DWORD *)(*a1 + 4);
      v2 = *(uint8_t **)*a1;
      *(_DWORD *)*a1 = v2 + 1;
      v7 = *v2;
    }
    *(_DWORD *)((char *)a1 + 5) = v7;
    if ( *(_DWORD *)((char *)a1 + 5) == -1 )
      sub_163233((int)aFatalErrorInIn, v6);
    v3 = *(_DWORD *)((char *)a1 + 9);
    *(_DWORD *)((char *)a1 + 9) = v3 + 1;
    if ( (v3 & 0x7FF) == 0 )
    {
      if ( (byte_188DCB & 4) != 0 || (unsigned int)(dword_188DD2 - dword_188DC2) <= 1 )
      {
        fputc(46, &dword_188DBE);
      }
      else
      {
        v4 = (_BYTE *)dword_188DBE;
        *(_BYTE *)dword_188DBE = 46;
        if ( *v4 == 10 )
        {
          fputc(10, &dword_188DBE);
        }
        else
        {
          byte_188DCB |= 0x10u;
          ++dword_188DC2;
          ++dword_188DBE;
        }
      }
    }
  }
  v9 = (uint8_t)a1[1] & *(_DWORD *)((char *)a1 + 5);
  *((_BYTE *)a1 + 4) >>= 1;
  if ( !*((_BYTE *)a1 + 4) )
    *((_BYTE *)a1 + 4) = 0x80;
  return v9 != 0;
}
// 162F18: variable 'v6' is possibly undefined
// 13C992: using guessed type int __fastcall fgetc(_DWORD, _DWORD);
// 148337: using guessed type int __fastcall fputc(_DWORD, _DWORD);
// 188DBE: using guessed type int dword_188DBE;
// 188DC2: using guessed type int dword_188DC2;
// 188DCB: using guessed type char byte_188DCB;
// 188DD2: using guessed type int dword_188DD2;


//----- (00163233) --------------------------------------------------------
void __cdecl __noreturn sub_163233(int a1, int a2)
{
  char v2[40]; // [esp+0h] [ebp-2Ch] BYREF
  char *v3; // [esp+28h] [ebp-4h] BYREF

  v3 = &a2;
  sprintf(v2, aFatalError);
  vsprintf(v2, a1, &v3);
  v3 = 0;
  sub_126487(v2, a1);
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 13C8F0: using guessed type int __fastcall vsprintf(_DWORD, _DWORD, _DWORD);


//----- (001632B0) --------------------------------------------------------
int __stdcall sub_1632B0(int a1, int a2)
{
  int result; // eax
  _DWORD v3[3]; // [esp+0h] [ebp-24h] BYREF
  char v4; // [esp+Ch] [ebp-18h]

  if ( dword_18AD68 != -1 )
  {
    v3[0] = 13057;
    v4 = dword_18AD68;
    return int386(33, v3, v3);
  }
  return result;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 18AD68: using guessed type int dword_18AD68;


//----- (001632E8) --------------------------------------------------------
int __fastcall sub_1632E8(int a1, int a2, int a3, int a4)
{
  int result; // eax
  _DWORD v5[3]; // [esp+0h] [ebp-3Ch] BYREF
  uint8_t v6; // [esp+Ch] [ebp-30h]
  int *v7; // [esp+1Ch] [ebp-20h]
  int v8; // [esp+20h] [ebp-1Ch]
  int v9; // [esp+24h] [ebp-18h]
  int v10; // [esp+34h] [ebp-8h]

  v10 = a4;
  if ( !dword_18AD64 )
  {
    LOWORD(v8) = sub_15E3E4();
    v9 = 0;
    sub_15E3F0(&dword_18AD70, v8, sub_1632B0, 0, 0, 0);
    v7 = &dword_18AD6C;
    sub_15E3F0(&dword_18AD6C, v8, sub_1632B0, 0, 0, 0);
    dword_18AD64 = 1;
    dword_18AD5C = 0;
    v5[0] = 13056;
    int386(33, v5, v5);
    dword_18AD68 = v6;
    v6 = 0;
    v5[0] = 13057;
    return int386(33, v5, v5);
  }
  return result;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 15E3F0: using guessed type _DWORD __stdcall sub_15E3F0(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 18AD5C: using guessed type int dword_18AD5C;
// 18AD64: using guessed type int dword_18AD64;
// 18AD68: using guessed type int dword_18AD68;
// 18AD6C: using guessed type int dword_18AD6C;
// 18AD70: using guessed type int dword_18AD70;


//----- (001633C4) --------------------------------------------------------
bool __fastcall sub_1633C4(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+4h] [ebp-8h]
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  LOWORD(v5) = sub_15EB44();
  sub_15E3A8((int)v6, 1174, v5, a4, 0x496u, v5, 1);
  return (v6[0] & 0x10) != 0;
}
// 1633C4: could not find valid save-restore pair for ebx
// 1633E2: variable 'v5' is possibly undefined


//----- (00163400) --------------------------------------------------------
bool __fastcall sub_163400(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  bool result; // eax
  int16_t v6; // [esp+4h] [ebp-18h]
  _BYTE v7[12]; // [esp+8h] [ebp-14h] BYREF
  int v8; // [esp+14h] [ebp-8h]

  v8 = a4;
  v4 = dword_18AD60;
  dword_18AD4C = 1;
  if ( dword_18AD60 )
  {
    v6 = sub_15EB44();
    sub_15E3A8((int)v7, 1, v4, 1174, 0x496u, v6, 1);
    result = (v7[0] & 0x10) != 0;
    if ( (v7[0] & 0x10) != 0 )
    {
      LOBYTE(dword_18AD50) = dword_18AD50 | 0x10;
      byte_18AD58 |= 0x10u;
      byte_18AD54 |= 0x10u;
    }
  }
  return result;
}
// 18AD4C: using guessed type int dword_18AD4C;
// 18AD50: using guessed type int dword_18AD50;
// 18AD54: using guessed type char byte_18AD54;
// 18AD58: using guessed type char byte_18AD58;
// 18AD60: using guessed type int dword_18AD60;


//----- (00163484) --------------------------------------------------------
int sub_163484()
{
  int result; // eax
  _BYTE v1[36]; // [esp+0h] [ebp-24h] BYREF

  if ( dword_18AD5C )
  {
    v1[1] = 11;
    return int386(33, v1, v1);
  }
  return result;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 18AD5C: using guessed type int dword_18AD5C;


//----- (001634AC) --------------------------------------------------------
int __fastcall sub_1634AC(int a1, int a2)
{
  _DWORD v3[7]; // [esp+0h] [ebp-38h] BYREF
  _BYTE v4[28]; // [esp+1Ch] [ebp-1Ch] BYREF

  if ( !dword_18AD4C )
  {
    dword_18AD4C = 1;
    if ( dword_18AD60 )
    {
      if ( sub_1633C4(a1, a2, 1, dword_18AD60) )
      {
        byte_18AD54 |= 0x10u;
        LOBYTE(dword_18AD50) = dword_18AD50 | 0x10;
        byte_18AD58 |= 0x10u;
      }
    }
  }
  BYTE1(v3[0]) = byte_18AD58;
  int386(22, v3, v3);
  if ( !LOWORD(v3[0]) )
    return 0;
  if ( LOBYTE(v3[0]) == 0xE0 )
    LOBYTE(v3[0]) = 0;
  if ( LOBYTE(v3[0]) )
    BYTE1(v3[0]) = 0;
  if ( dword_18AD5C )
  {
    v4[1] = 11;
    int386(33, v4, v4);
  }
  return LOWORD(v3[0]);
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 18AD4C: using guessed type int dword_18AD4C;
// 18AD50: using guessed type int dword_18AD50;
// 18AD54: using guessed type char byte_18AD54;
// 18AD58: using guessed type char byte_18AD58;
// 18AD5C: using guessed type int dword_18AD5C;
// 18AD60: using guessed type int dword_18AD60;


//----- (0016356C) --------------------------------------------------------
bool __fastcall sub_16356C(int a1, int a2)
{
  char v2; // zf
  bool v3; // eax
  bool v4; // ecx
  _BYTE v6[36]; // [esp+0h] [ebp-24h] BYREF

  v2 = dword_18AD4C == 0;
  if ( !dword_18AD4C )
  {
    dword_18AD4C = 1;
    v2 = dword_18AD60 == 0;
    if ( dword_18AD60 )
    {
      v3 = sub_1633C4(a1, a2, 1, dword_18AD60);
      v2 = !v3;
      if ( v3 )
      {
        byte_18AD54 |= 0x10u;
        v2 = 0;
        LOBYTE(dword_18AD50) = dword_18AD50 | 0x10;
        byte_18AD58 |= 0x10u;
      }
    }
  }
  v4 = sub_163B3C(v2);
  if ( dword_18AD50 == 1 && dword_18AD5C )
  {
    v6[1] = 11;
    int386(33, v6, v6);
  }
  return v4;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 18AD4C: using guessed type int dword_18AD4C;
// 18AD50: using guessed type int dword_18AD50;
// 18AD54: using guessed type char byte_18AD54;
// 18AD58: using guessed type char byte_18AD58;
// 18AD5C: using guessed type int dword_18AD5C;
// 18AD60: using guessed type int dword_18AD60;


//----- (00163608) --------------------------------------------------------
int __fastcall sub_163608(int a1, int a2)
{
  _DWORD v3[7]; // [esp+0h] [ebp-38h] BYREF
  _BYTE v4[28]; // [esp+1Ch] [ebp-1Ch] BYREF

  if ( !dword_18AD4C )
  {
    dword_18AD4C = 1;
    if ( dword_18AD60 )
    {
      if ( sub_1633C4(a1, a2, 1, dword_18AD60) )
      {
        byte_18AD54 |= 0x10u;
        LOBYTE(dword_18AD50) = dword_18AD50 | 0x10;
        byte_18AD58 |= 0x10u;
      }
    }
  }
  BYTE1(v3[0]) = byte_18AD58;
  int386(22, v3, v3);
  if ( dword_18AD5C )
  {
    v4[1] = 11;
    int386(33, v4, v4);
  }
  return v3[0];
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 18AD4C: using guessed type int dword_18AD4C;
// 18AD50: using guessed type int dword_18AD50;
// 18AD54: using guessed type char byte_18AD54;
// 18AD58: using guessed type char byte_18AD58;
// 18AD5C: using guessed type int dword_18AD5C;
// 18AD60: using guessed type int dword_18AD60;


//----- (001636A0) --------------------------------------------------------
int __fastcall sub_1636A0(int a1, int a2)
{
  _WORD v3[14]; // [esp+0h] [ebp-1Ch] BYREF

  if ( !dword_18AD4C )
  {
    dword_18AD4C = 1;
    if ( dword_18AD60 )
    {
      if ( sub_1633C4(a1, a2, 1, dword_18AD60) )
      {
        byte_18AD54 |= 0x10u;
        LOBYTE(dword_18AD50) = dword_18AD50 | 0x10;
        byte_18AD58 |= 0x10u;
      }
    }
  }
  HIBYTE(v3[0]) = byte_18AD54;
  int386(22, v3, v3);
  return v3[0];
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 18AD4C: using guessed type int dword_18AD4C;
// 18AD50: using guessed type int dword_18AD50;
// 18AD54: using guessed type char byte_18AD54;
// 18AD58: using guessed type char byte_18AD58;
// 18AD60: using guessed type int dword_18AD60;


//----- (0016371C) --------------------------------------------------------
int __fastcall sub_16371C(int a1, int a2, int a3, int a4, unsigned int a5)
{
  _DWORD v6[3]; // [esp+0h] [ebp-24h] BYREF
  uint8_t v7; // [esp+Ch] [ebp-18h]

  if ( !dword_18AD4C )
  {
    a3 = 1;
    a4 = dword_18AD60;
    dword_18AD4C = 1;
    if ( dword_18AD60 )
    {
      a1 = sub_1633C4(a1, a2, 1, dword_18AD60);
      if ( a1 )
      {
        LOBYTE(a2) = byte_18AD54 | 0x10;
        byte_18AD54 |= 0x10u;
        BYTE1(a1) = dword_18AD50 | 0x10;
        BYTE1(a2) = byte_18AD58 | 0x10;
        LOBYTE(dword_18AD50) = dword_18AD50 | 0x10;
        byte_18AD58 |= 0x10u;
      }
    }
  }
  if ( !a5 )
  {
    sub_1632E8(a1, a2, a3, a4);
    return 0;
  }
  if ( a5 <= 1 )
  {
    if ( dword_18AD64 )
    {
      sub_15E814(27);
      sub_15E814(35);
      dword_18AD64 = 0;
      dword_18AD5C = 1;
    }
    return 0;
  }
  if ( a5 != 2 )
    return -7;
  v6[0] = 13056;
  int386(33, v6, v6);
  return v7;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 18AD4C: using guessed type int dword_18AD4C;
// 18AD50: using guessed type int dword_18AD50;
// 18AD54: using guessed type char byte_18AD54;
// 18AD58: using guessed type char byte_18AD58;
// 18AD5C: using guessed type int dword_18AD5C;
// 18AD60: using guessed type int dword_18AD60;
// 18AD64: using guessed type int dword_18AD64;


//----- (00163800) --------------------------------------------------------
int __fastcall sub_163800(int a1, int a2)
{
  int v4; // edi
  int v5; // eax
  int v6; // ebp
  int v7; // esi
  int v8; // [esp+0h] [ebp-18h]

  if ( sub_15F1E0() && (sub_168549(a1 + 1) & 0xF) != 0 && (a2 & sub_168549(a1 + 4)) != 0 )
    return -115200;
  v4 = a1 + 3;
  sub_168545();
  v5 = sub_168549(a1 + 3);
  v6 = v5;
  LOBYTE(v5) = v5 | 0x80;
  sub_168560(a1 + 3, v5);
  v8 = sub_168549(a1);
  v7 = sub_168549(a1 + 1);
  sub_168560(v4, v6);
  sub_168541();
  return v8 | (v7 << 8);
}


//----- (00163B3C) --------------------------------------------------------
bool __usercall sub_163B3C( int a1)
{
  /* __asm: int     16h; KEYBOARD - */ DECOMP_TODO("inline asm");
  return !a1;
}


//----- (00163B59) --------------------------------------------------------
void __cdecl sub_163B59(int a1, int a2)
{
  *MK_FP(a2, a1) = *MK_FP(a2, a1) + 1;
}


//----- (00163B9E) --------------------------------------------------------
void sub_163B9E()
{
  if ( !word_18ADA8 && byte_18AFD0 )
  {
    if ( byte_184A22 )
    {
      if ( byte_184A22 == 1 )
      {
        _DOS4G_hook_init();
      }
      else if ( byte_184A22 == 9 )
      {
        _Intel_hook_init();
      }
      else
      {
        _Phar_hook_init();
      }
    }
    else
    {
      _Ergo_hook_init();
    }
    sub_163C58();
  }
}
// 163EB8: using guessed type int _Phar_hook_init(void);
// 163FA8: using guessed type int _DOS4G_hook_init(void);
// 163FEE: using guessed type int _Ergo_hook_init(void);
// 164046: using guessed type int _Intel_hook_init(void);
// 184A22: using guessed type char byte_184A22;
// 18ADA8: using guessed type int16_t word_18ADA8;
// 18AFD0: using guessed type char byte_18AFD0;


//----- (00163BFB) --------------------------------------------------------
void sub_163BFB()
{
  if ( word_18ADA8 )
  {
    if ( byte_184A22 )
    {
      if ( byte_184A22 == 1 )
      {
        _DOS4G_hook_fini();
      }
      else if ( byte_184A22 == 9 )
      {
        _Intel_hook_fini();
      }
      else
      {
        _Phar_hook_fini();
      }
    }
    else
    {
      _Ergo_hook_fini();
    }
  }
}
// 163F7B: using guessed type int _Phar_hook_fini(void);
// 163FD5: using guessed type int _DOS4G_hook_fini(void);
// 16402C: using guessed type int _Ergo_hook_fini(void);
// 16409E: using guessed type int _Intel_hook_fini(void);
// 184A22: using guessed type char byte_184A22;
// 18ADA8: using guessed type int16_t word_18ADA8;


//----- (00163C58) --------------------------------------------------------
void sub_163C58()
{
  ;
}


//----- (00163C6D) --------------------------------------------------------
void __noreturn sub_163C6D()
{
  __outbyte(0x20u, 0x20u);
  __outbyte(0xA0u, 0x20u);
  __outbyte(0xF0u, 0);
  sub_163C7A();
}
// 163C6D: using guessed type void __noreturn sub_163C6D();
// 163C7A: using guessed type void __noreturn sub_163C7A(void);


//----- (00163C7A) --------------------------------------------------------
void __noreturn sub_163C7A()
{
  _DWORD v1[16]; // [esp-24h] [ebp-40h] BYREF

  v1[8] = (uint16_t)__DS__;
  v1[7] = (uint16_t)__ES__;
  _EBP = v1;
  /* __asm: fnstenv byte ptr [ebp+0] */ DECOMP_TODO("inline asm");
  /* __asm: fclex fdisi */ DECOMP_TODO("inline asm");
  _enable();
  ((void (__noreturn *)(void))_GETDS)();
}


//----- (00163D80) --------------------------------------------------------
void __usercall sub_163D80( int a1, double *a2, double a3)
{
  _BOOL1 v3; // zf

  if ( a1 != -9734 && a1 != -9743 )
  {
    v3 = a1 == -9736;
    if ( a1 != -9736 )
      v3 = a1 == -9739;
    if ( !v3 && (a1 & 0x310) != 0x310 && (a1 & 0x110) == 0x110 )
    {
      /* __asm: fstp    st fldz */ DECOMP_TODO("inline asm");
      if ( (a1 & 0xC0) != 0xC0 )
        sub_163EAA(a1, a2, a3);
      if ( (a1 & 8) != 0 )
        /* __asm: fstp    st */ DECOMP_TODO("inline asm");
    }
  }
}
// 163DC7: inconsistent fpu stack


//----- (00163E0D) --------------------------------------------------------
void __usercall sub_163E0D( int a1, int a2, double *a3, int a4, double a5)
{
  double v5; // st7

  if ( a1 != -9731 )
  {
    if ( (a1 & 0x110) == 0x110 )
    {
      v5 = sub_163E5F(SHIBYTE(a1), a2, a4, a5);
      if ( (a1 & 0xC0) != 0xC0 )
        sub_163EAA(a1, a3, v5);
      if ( (a1 & 8) != 0 )
        /* __asm: fstp    st */ DECOMP_TODO("inline asm");
    }
    else if ( (a1 & 0xC0) == 0xC0 )
    {
      sub_163E85(a1 & 0x1C0, a1, (int)&unk_18ADB4);
    }
    else
    {
      sub_163E5F(SHIBYTE(a1), a2, a4, a5);
    }
  }
}
// 163E25: inconsistent fpu stack


//----- (00163E5F) --------------------------------------------------------
double __usercall sub_163E5F( int a1, int a2, int a3, double a4)
{
  _BOOL1 v4; // c0
  char v5; // c2
  _BOOL1 v6; // c3
  double result; // st7

  v4 = a4 < 0.0;
  v5 = 0;
  v6 = a4 == 0.0;
  *(_WORD *)(a2 + 20) = a3;
  if ( (a1 & 4) != 0 )
    result = dbl_18ADBE;
  else
    result = flt_18ADC6;
  if ( (*(_WORD *)(a2 + 20) & 0x100) != 0 )
    return -result;
  return result;
}
// 18ADBE: using guessed type double dbl_18ADBE;
// 18ADC6: using guessed type float flt_18ADC6;


//----- (00163E85) --------------------------------------------------------
int64_t __usercall sub_163E85(int a1, int a2, int _ESI)
{
  _BOOL1 v3; // cc
  int64_t result; // rax
  int v5; // [esp-4h] [ebp-4h]

  if ( (a2 & 0x400) != 0 )
    LOBYTE(a1) = a2 & 7;
  else
    LOBYTE(a1) = 0;
  v5 = a1;
  while ( 1 )
  {
    v3 = (char)a1 < 1;
    LOBYTE(a1) = a1 - 1;
    if ( v3 )
      break;
    /* __asm: fincstp */ DECOMP_TODO("inline asm");
  }
  /* __asm: fstp    st fld     tbyte ptr [esi] */ DECOMP_TODO("inline asm");
  HIDWORD(result) = v5;
  while ( 1 )
  {
    v3 = BYTE4(result)-- < 1;
    if ( v3 )
      break;
    /* __asm: fdecstp */ DECOMP_TODO("inline asm");
  }
  return result;
}
// 163E98: inconsistent fpu stack


//----- (00163EAA) --------------------------------------------------------
double __usercall sub_163EAA( int a1, double *a2, double result)
{
  if ( (a1 & 4) != 0 )
    *a2 = result;
  else
    *(float *)a2 = result;
  return result;
}


//----- (00164200) --------------------------------------------------------
void __usercall sub_164200(unsigned int a1, unsigned int *a2, unsigned int *a3)
{
  unsigned int v3; // eax
  char v4; // cf
  char v5; // bl
  char v6; // cl
  char v7; // al
  unsigned int v8; // ebp

  v3 = 0x80000000;
  while ( 1 )
  {
    if ( !--byte_18A6C0 )
    {
      a1 = *a3++;
      byte_18A6C0 = 32;
    }
    v4 = a1 & 1;
    a1 >>= 1;
    if ( v4 )
    {
      ++a2;
    }
    else
    {
      if ( (uint8_t)byte_18A6C0 < 9u )
      {
        v6 = byte_18A6C0;
        byte_18A6C0 += 24;
        v7 = a1;
        --v6;
        v8 = *a3;
        LOBYTE(v3) = (*a3++ << v6) | v7;
        a1 = v8 >> ~(v6 - 9);
      }
      else
      {
        v5 = a1;
        byte_18A6C0 -= 8;
        a1 >>= 8;
        LOBYTE(v3) = v5;
      }
      *a2++ = v3;
    }
  }
}
// 164226: conditional instruction was optimized away because %0x4.4==FFFFFFFE
// 16423B: conditional instruction was optimized away because %0x4.4==FFFFFFFE
// 164286: conditional instruction was optimized away because %0x4.4==FFFFFFFE
// 18A6C0: using guessed type char byte_18A6C0;


