#include "orion_common.h"

/* Adresni rozsah: 0x11A558 - 0x12B3E0  (200 funkci) */

//----- (0011A558) --------------------------------------------------------
int sub_11A558()
{
  int16_t v0; // ax
  int16_t v1; // ax
  int16_t v3; // [esp+0h] [ebp-14h]
  int v4; // [esp+4h] [ebp-10h]
  int16_t v6; // [esp+Ch] [ebp-8h]
  _BOOL1 i; // [esp+10h] [ebp-4h]

  for ( i = 0; !i; i = v6 || v1 )
  {
    LOBYTE(v0) = sub_12C392();
    v6 = v0;
    v1 = sub_124075();
    v3 = v1;
  }
  v4 = sub_12C2E1();
  if ( v3 )
    return -1;
  else
    return v4;
}
// 11A57F: variable 'v0' is possibly undefined
// 11A5B3: variable 'v3' is possibly undefined


//----- (0011A5D0) --------------------------------------------------------
int sub_11A5D0( int a1, int a2)
{
  int v4; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  char v6; // [esp+14h] [ebp-4h]

  v6 = sub_11A6C4(a1, a2, (int16_t *)&dword_1B3E02 + 1, &byte_1B3E1B, &byte_1B3E1D);
  v4 = -1;
  if ( !v6 )
  {
    for ( i = 0; (int16_t)i < word_1B3E0E && !v6; ++i )
    {
      if ( a1 >= *(int16_t *)((char *)off_184480 + 55 * (int16_t)i)
        && a1 <= *(int16_t *)((char *)off_184480 + 55 * (int16_t)i + 4)
        && a2 >= *(int16_t *)((char *)off_184480 + 55 * (int16_t)i + 2)
        && a2 <= *(int16_t *)((char *)off_184480 + 55 * (int16_t)i + 6) )
      {
        v6 = 1;
        v4 = i;
      }
    }
  }
  return v4;
}
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E02: using guessed type int dword_1B3E02;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1B3E1B: using guessed type char byte_1B3E1B;
// 1B3E1D: using guessed type char byte_1B3E1D;


//----- (0011A6C4) --------------------------------------------------------
char sub_11A6C4( int a1, int a2, int16_t *a3, _BYTE *a4, _BYTE *a5)
{
  int16_t i; // [esp+10h] [ebp-Ch]
  char v8; // [esp+14h] [ebp-8h]

  v8 = 0;
  for ( i = 0; (uint8_t)byte_1B3E1C > i && !v8; ++i )
  {
    if ( a1 >= *(int16_t *)(40 * i + dword_1B081C + 4)
      && a1 < *(int16_t *)(40 * i + dword_1B081C + 8)
      && a2 >= *(int16_t *)(40 * i + dword_1B081C + 6)
      && a2 < *(int16_t *)(40 * i + dword_1B081C + 10) )
    {
      *a3 = i;
      *a4 = strlen(*(_DWORD *)(40 * i + dword_1B081C));
      *a5 = i;
      v8 = 1;
    }
  }
  return v8;
}
// 14432F: using guessed type int strlen(_DWORD);
// 1B081C: using guessed type int dword_1B081C;
// 1B3E1C: using guessed type char byte_1B3E1C;


//----- (0011A7B9) --------------------------------------------------------
int sub_11A7B9()
{
  int result; // eax
  int16_t i; // [esp+0h] [ebp-8h]

  for ( i = 0; ; ++i )
  {
    result = (uint8_t)byte_1B3E1C;
    if ( (uint8_t)byte_1B3E1C <= i )
      break;
    if ( byte_1B3E1D == i && *(_BYTE *)(40 * i + dword_1B081C + 38) )
      memcpy(40 * i + dword_1B081C + 13, 40 * i + dword_1B081C + 29, 8);
    else
      memcpy(40 * i + dword_1B081C + 13, 40 * i + dword_1B081C + 21, 8);
  }
  return result;
}
// 13F35A: using guessed type int memcpy(_DWORD, _DWORD, _DWORD);
// 1B081C: using guessed type int dword_1B081C;
// 1B3E1C: using guessed type char byte_1B3E1C;
// 1B3E1D: using guessed type char byte_1B3E1D;


//----- (0011A92E) --------------------------------------------------------
int sub_11A92E(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6, int a7, int a8,
        _BYTE *a9, int a10)
{
  int v10; // eax
  char v12[80]; // [esp+0h] [ebp-68h] BYREF
  int v13; // [esp+50h] [ebp-18h]
  int v14; // [esp+54h] [ebp-14h]
  int v15; // [esp+58h] [ebp-10h]
  int v16; // [esp+5Ch] [ebp-Ch]
  int v17; // [esp+60h] [ebp-8h]

  v13 = a1;
  v14 = a2;
  v15 = a3;
  v16 = a4;
  if ( word_1B3E0E > word_18447E )
  {
    sprintf(v12, "Maximum number of button fields exceeded (%d)", *(int *)((char *)&dword_18447A + 2) >> 16);
    sub_126487(v12, a2);
  }
  v17 = 0;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = v13;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = v14;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 24) = a5;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = v15;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = v16;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 10) = sub_122201();
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 12) = sub_12222E();
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 53) = a10;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 44) = a6;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 36) = sub_12B6D4(a6);
  *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) = *a9;
  if ( *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) > 0x60u
    && *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) < 0x7Bu )
  {
    *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) -= 32;
  }
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 28) = a7;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 32) = a8;
  v10 = 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
  *(_WORD *)((char *)off_184480 + v10 + 8) = 13;
  LOWORD(v10) = ++word_1B3E0E;
  return v10 - 1;
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 18447A: using guessed type int dword_18447A;
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (0011AB8A) --------------------------------------------------------
char sub_11AB8A( int a1)
{
  char v2; // [esp+8h] [ebp-8h]

  v2 = -1;
  switch ( a1 )
  {
    case 4096:
      v2 = 81;
      break;
    case 4352:
      v2 = 87;
      break;
    case 4608:
      v2 = 69;
      break;
    case 4864:
      v2 = 82;
      break;
    case 5120:
      v2 = 84;
      break;
    case 5376:
      v2 = 89;
      break;
    case 5632:
      v2 = 85;
      break;
    case 5888:
      v2 = 73;
      break;
    case 6144:
      v2 = 79;
      break;
    case 6400:
      v2 = 80;
      break;
    case 7680:
      v2 = 65;
      break;
    case 7936:
      v2 = 83;
      break;
    case 8192:
      v2 = 68;
      break;
    case 8448:
      v2 = 70;
      break;
    case 8704:
      v2 = 71;
      break;
    case 8960:
      v2 = 72;
      break;
    case 9216:
      v2 = 74;
      break;
    case 9472:
      v2 = 75;
      break;
    case 9728:
      v2 = 76;
      break;
    case 11264:
      v2 = 90;
      break;
    case 11520:
      v2 = 88;
      break;
    case 11776:
      v2 = 67;
      break;
    case 12032:
      v2 = 86;
      break;
    case 12288:
      v2 = 66;
      break;
    case 12544:
      v2 = 78;
      break;
    case 12800:
      v2 = 77;
      break;
    case 30720:
      v2 = 48;
      break;
    case 30976:
      v2 = 49;
      break;
    case 31232:
      v2 = 50;
      break;
    case 31488:
      v2 = 51;
      break;
    case 31744:
      v2 = 52;
      break;
    case 32000:
      v2 = 53;
      break;
    case 32256:
      v2 = 54;
      break;
    case 32512:
      v2 = 55;
      break;
    default:
      return v2;
  }
  return v2;
}


//----- (0011ADB4) --------------------------------------------------------
int sub_11ADB4(int a1, int a2)
{
  int v2; // eax

  if ( word_1B3E0E >= word_18447E )
    sub_126487(aYouExceededThe, a2);
  memset((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16), 0, 55);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = -1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = -1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = -1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = -1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 8) = 8;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 24) = a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 28) = 0;
  v2 = strlen(a1);
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 32) = v2;
  word_1844DC = 1;
  LOWORD(v2) = ++word_1B3E0E;
  return v2 - 1;
}
// 129C70: using guessed type int memset(_DWORD, _DWORD, _DWORD);
// 14432F: using guessed type int strlen(_DWORD);
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1844DC: using guessed type int16_t word_1844DC;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (0011AEF7) --------------------------------------------------------
int sub_11AEF7()
{
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = i;
    if ( (int16_t)i >= word_1B3E0E )
      break;
    if ( *(int *)((char *)off_184480 + 55 * (int16_t)i + 6) >> 16 == 8 )
      *(_WORD *)((char *)off_184480 + 55 * (int16_t)i + 28) = 0;
  }
  return result;
}
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (0011AF64) --------------------------------------------------------
int sub_11AF64( int a1)
{
  int i; // [esp+8h] [ebp-10h]
  int v3; // [esp+10h] [ebp-8h]

  v3 = -1;
  for ( i = 0; (int16_t)i < word_1B3E0E && (int16_t)v3 == -1; ++i )
  {
    if ( *(int *)((char *)off_184480 + 55 * (int16_t)i + 6) >> 16 == 8
      && *(uint8_t *)(*(int16_t *)((char *)off_184480 + 55 * (int16_t)i + 28)
                            + *(_DWORD *)((char *)off_184480 + 55 * (int16_t)i + 24)) == a1
      && ++*(_WORD *)((char *)off_184480 + 55 * (int16_t)i + 28) == *(_WORD *)((char *)off_184480 + 55 * (int16_t)i + 32) )
    {
      v3 = i;
    }
  }
  return v3;
}
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (0011B05A) --------------------------------------------------------
int16_t sub_11B05A(char *a1, int a2)
{
  char *v2; // eax
  int16_t v3; // ax
  int v4; // edx
  int v5; // ebx
  int16_t v7; // [esp+4h] [ebp-28h]
  int16_t v8; // [esp+8h] [ebp-24h]
  int16_t v9; // [esp+Ch] [ebp-20h]
  int v10; // [esp+18h] [ebp-14h]
  int v11; // [esp+18h] [ebp-14h]

  v9 = (int16_t)a1;
  if ( !(_WORD)dword_1844E6 )
    return (int16_t)a1;
  LOWORD(a1) = *(_WORD *)((char *)off_184480 + 55 * (int16_t)a1 + 8);
  if ( (uint16_t)a1 < 3u )
  {
    if ( !(_WORD)a1 )
      goto LABEL_16;
    if ( (uint16_t)a1 <= 1u )
    {
      if ( !a2 || **(_WORD **)((char *)off_184480 + 55 * v9 + 32) == 1 )
      {
        sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
        sub_12A478(
          *(_WORD *)((char *)off_184480 + 55 * v9),
          HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v9)),
          *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
        a1 = (char *)off_184480 + 55 * v9;
        if ( *((_DWORD *)a1 + 6) )
        {
          a1 = *(char **)((char *)off_184480 + 55 * v9 + 24);
          if ( !*a1 )
            goto LABEL_65;
        }
        return (int16_t)a1;
      }
      if ( *(_WORD *)((char *)off_184480 + 55 * v9 + 36) )
      {
        sub_12B753(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44), 1);
      }
      else
      {
        sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
        sub_12A478(
          *(_WORD *)((char *)off_184480 + 55 * v9),
          HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v9)),
          *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
      }
      sub_12A478(
        *(_WORD *)((char *)off_184480 + 55 * v9),
        HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v9)),
        *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
      a1 = (char *)off_184480 + 55 * v9;
      if ( !*((_DWORD *)a1 + 6) )
        return (int16_t)a1;
      a1 = *(char **)((char *)off_184480 + 55 * v9 + 24);
      if ( *a1 )
        return (int16_t)a1;
    }
    else
    {
      if ( !**(_WORD **)((char *)off_184480 + 55 * v9 + 32) && a2 != 1 )
      {
        sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
        sub_12A478(
          *(_WORD *)((char *)off_184480 + 55 * v9),
          HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v9)),
          *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
        a1 = (char *)off_184480 + 55 * v9;
        if ( *((_DWORD *)a1 + 6) )
        {
          a1 = *(char **)((char *)off_184480 + 55 * v9 + 24);
          if ( !*a1 )
            goto LABEL_65;
        }
        return (int16_t)a1;
      }
      if ( *(_WORD *)((char *)off_184480 + 55 * v9 + 36) )
      {
        sub_12B753(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44), 1);
      }
      else
      {
        sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
        sub_12A478(
          *(_WORD *)((char *)off_184480 + 55 * v9),
          HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v9)),
          *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
      }
      sub_12A478(
        *(_WORD *)((char *)off_184480 + 55 * v9),
        HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v9)),
        *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
      a1 = (char *)off_184480 + 55 * v9;
      if ( !*((_DWORD *)a1 + 6) )
        return (int16_t)a1;
      a1 = *(char **)((char *)off_184480 + 55 * v9 + 24);
      if ( *a1 )
        return (int16_t)a1;
    }
LABEL_72:
    sub_120BB5(*(int *)((char *)off_184480 + 55 * v9 + 8) >> 16, *(_DWORD *)((char *)off_184480 + 55 * v9 + 12));
    v11 = (sub_122259() - 1) / 2;
    LOWORD(a1) = sub_1210FD(
                   *(_WORD *)((char *)off_184480 + 55 * v9)
                 + ((*(int *)((char *)off_184480 + 55 * v9 + 2) >> 16) - *(int16_t *)((char *)off_184480 + 55 * v9)) / 2
                 + dword_184492,
                   HIWORD(dword_184492)
                 + ((*(int *)((char *)off_184480 + 55 * v9 + 4) >> 16) - (*(int *)((char *)off_184480 + 55 * v9) >> 16))
                 / 2
                 + HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v9))
                 - v11,
                   *(_DWORD *)((char *)off_184480 + 55 * v9 + 24));
    return (int16_t)a1;
  }
  if ( (uint16_t)a1 <= 3u )
  {
    if ( a2 )
      **(_WORD **)((char *)off_184480 + 55 * v9 + 32) = *(_WORD *)((char *)off_184480 + 55 * v9 + 28);
    else
      **(_WORD **)((char *)off_184480 + 55 * v9 + 32) = -1000;
    if ( **(_WORD **)((char *)off_184480 + 55 * v9 + 32) != *(_WORD *)((char *)off_184480 + 55 * v9 + 28) )
    {
      sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
      sub_12A478(
        *(_WORD *)((char *)off_184480 + 55 * v9),
        HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v9)),
        *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
      a1 = (char *)off_184480 + 55 * v9;
      if ( *((_DWORD *)a1 + 6) )
      {
        a1 = *(char **)((char *)off_184480 + 55 * v9 + 24);
        if ( !*a1 )
          goto LABEL_65;
      }
      return (int16_t)a1;
    }
    if ( *(_WORD *)((char *)off_184480 + 55 * v9 + 36) )
    {
      sub_12B753(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44), 1);
    }
    else
    {
      sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
      sub_12A478(
        *(_WORD *)((char *)off_184480 + 55 * v9),
        HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v9)),
        *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
    }
    sub_12A478(
      *(_WORD *)((char *)off_184480 + 55 * v9),
      HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v9)),
      *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
    a1 = (char *)off_184480 + 55 * v9;
    if ( !*((_DWORD *)a1 + 6) )
      return (int16_t)a1;
    a1 = *(char **)((char *)off_184480 + 55 * v9 + 24);
    if ( *a1 )
      return (int16_t)a1;
    goto LABEL_72;
  }
  if ( (uint16_t)a1 < 6u )
  {
    if ( (_WORD)a1 == 4 )
    {
      LOWORD(a1) = a2;
      if ( a2 == 1 )
        LOWORD(a1) = sub_1160AE(v9);
    }
    return (int16_t)a1;
  }
  if ( (uint16_t)a1 <= 6u )
  {
    LOWORD(a1) = a2;
    if ( a2 == 1 )
      LOWORD(a1) = sub_1156E2(v9);
    return (int16_t)a1;
  }
  if ( (uint16_t)a1 < 0xCu )
    return (int16_t)a1;
  if ( (uint16_t)a1 <= 0xCu )
  {
    LOWORD(dword_1B3E14) = sub_123FFB();
    LOWORD(a1) = a2;
    if ( a2 == 1 )
    {
      v4 = *(int16_t *)((char *)off_184480 + 55 * v9);
      **(_WORD **)((char *)off_184480 + 55 * v9 + 36) = (sub_123ABA() + (*(int *)((char *)&dword_1B3E10 + 2) >> 16) - v4)
                                                      / (*(int *)((char *)off_184480 + 55 * v9 + 26) >> 16);
      v5 = *(int *)((char *)off_184480 + 55 * v9) >> 16;
      **(_WORD **)((char *)off_184480 + 55 * v9 + 40) = ((*(int *)((char *)&dword_1B3E10 + 2) >> 16) + sub_123AE7() - v5)
                                                      / (*(int *)((char *)off_184480 + 55 * v9 + 30) >> 16);
      if ( **(int16_t **)((char *)off_184480 + 55 * v9 + 36) > ((*(int *)((char *)off_184480 + 55 * v9 + 2) >> 16)
                                                              - *(int16_t *)((char *)off_184480 + 55 * v9))
                                                             / (*(int *)((char *)off_184480 + 55 * v9 + 26) >> 16) )
        **(_WORD **)((char *)off_184480 + 55 * v9 + 36) = ((*(int *)((char *)off_184480 + 55 * v9 + 2) >> 16)
                                                         - *(int16_t *)((char *)off_184480 + 55 * v9))
                                                        / (*(int *)((char *)off_184480 + 55 * v9 + 26) >> 16);
      if ( **(int16_t **)((char *)off_184480 + 55 * v9 + 40) > ((*(int *)((char *)off_184480 + 55 * v9 + 4) >> 16)
                                                              - (*(int *)((char *)off_184480 + 55 * v9) >> 16))
                                                             / (*(int *)((char *)off_184480 + 55 * v9 + 30) >> 16) )
        **(_WORD **)((char *)off_184480 + 55 * v9 + 40) = ((*(int *)((char *)off_184480 + 55 * v9 + 4) >> 16)
                                                         - (*(int *)((char *)off_184480 + 55 * v9) >> 16))
                                                        / (*(int *)((char *)off_184480 + 55 * v9 + 30) >> 16);
      if ( **(int16_t **)((char *)off_184480 + 55 * v9 + 36) < 0 )
        **(_WORD **)((char *)off_184480 + 55 * v9 + 36) = 0;
      a1 = *(char **)((char *)off_184480 + 55 * v9 + 40);
      if ( *(int16_t *)a1 < 0 )
      {
        a1 = *(char **)((char *)off_184480 + 55 * v9 + 40);
        *(_WORD *)a1 = 0;
      }
    }
    return (int16_t)a1;
  }
  if ( (_WORD)a1 != 13 )
    return (int16_t)a1;
LABEL_16:
  v2 = (char *)off_184480 + 55 * v9;
  if ( *(int *)(v2 + 6) >> 16 == 13 )
  {
    v7 = *((_WORD *)v2 + 14);
    v3 = *(_WORD *)((char *)off_184480 + 55 * v9 + 32);
  }
  else
  {
    v7 = *(_WORD *)v2;
    v3 = *(_WORD *)((char *)off_184480 + 55 * v9 + 2);
  }
  v8 = v3;
  if ( !a2 )
  {
    sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
    sub_12A478(v7, v8, *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
    a1 = (char *)off_184480 + 55 * v9;
    if ( !*((_DWORD *)a1 + 6) )
      return (int16_t)a1;
    a1 = *(char **)((char *)off_184480 + 55 * v9 + 24);
    if ( *a1 )
      return (int16_t)a1;
LABEL_65:
    sub_120BB5(*(int *)((char *)off_184480 + 55 * v9 + 8) >> 16, *(_DWORD *)((char *)off_184480 + 55 * v9 + 12));
    v10 = (sub_122259() - 1) / 2;
    LOWORD(a1) = sub_1210FD(
                   ((*(int *)((char *)off_184480 + 55 * v9 + 2) >> 16) - *(int16_t *)((char *)off_184480 + 55 * v9)) / 2
                 + *(_WORD *)((char *)off_184480 + 55 * v9),
                   HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v9))
                 + ((*(int *)((char *)off_184480 + 55 * v9 + 4) >> 16) - (*(int *)((char *)off_184480 + 55 * v9) >> 16))
                 / 2
                 - v10,
                   *(_DWORD *)((char *)off_184480 + 55 * v9 + 24));
    return (int16_t)a1;
  }
  if ( *(_WORD *)((char *)off_184480 + 55 * v9 + 36) )
  {
    sub_12B753(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44), 1);
  }
  else
  {
    sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
    sub_12A478(v7, v8, *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
  }
  sub_12A478(v7, v8, *(_DWORD *)((char *)off_184480 + 55 * v9 + 44));
  a1 = (char *)off_184480 + 55 * v9;
  if ( *((_DWORD *)a1 + 6) )
  {
    a1 = *(char **)((char *)off_184480 + 55 * v9 + 24);
    if ( !*a1 )
      goto LABEL_72;
  }
  return (int16_t)a1;
}
// 184480: using guessed type _UNKNOWN *off_184480;
// 18448E: using guessed type int dword_18448E;
// 184492: using guessed type int dword_184492;
// 1844E6: using guessed type int dword_1844E6;
// 1B3E10: using guessed type int dword_1B3E10;
// 1B3E14: using guessed type int dword_1B3E14;


//----- (0011C2F0) --------------------------------------------------------
int16_t sub_11C2F0()
{
  word_1B3E0E = 1;
  HIWORD(dword_1B3E10) = 0;
  HIWORD(dword_18448E) = -1;
  word_1844A6 = 0;
  word_1844CA = 0;
  HIWORD(dword_1844CE) = -1;
  word_1844DC = 0;
  sub_123C48();
  return sub_123C84();
}
// 18448E: using guessed type int dword_18448E;
// 1844A6: using guessed type int16_t word_1844A6;
// 1844CA: using guessed type int16_t word_1844CA;
// 1844CE: using guessed type int dword_1844CE;
// 1844DC: using guessed type int16_t word_1844DC;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1B3E10: using guessed type int dword_1B3E10;


//----- (0011C358) --------------------------------------------------------
char sub_11C358( int a1, int a2, int a3)
{
  int16_t v4; // [esp+0h] [ebp-Ch]

  v4 = a1;
  if ( a1 >= SHIWORD(dword_1BBA4A) && a1 <= (int16_t)dword_1BBA4E )
  {
    LOBYTE(a1) = a2;
    if ( a2 >= SHIWORD(dword_1BBA4E) )
    {
      LOBYTE(a1) = a2;
      if ( a2 <= (int16_t)dword_1BBA52 )
        LOBYTE(a1) = sub_12972D(v4, a2, a3);
    }
  }
  return a1;
}
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (0011C3C5) --------------------------------------------------------
int sub_11C3C5( int a1, int a2, int a3, int16_t *a4, _BYTE *a5, int a6)
{
  char *v6; // eax
  int16_t v8; // [esp+10h] [ebp-Ch]

  v8 = a2;
  if ( *(int *)((char *)&off_1845D4 + 2) >> 16 == 1 )
  {
    if ( a1 < SHIWORD(dword_1BBA4A) )
      return -1000;
    if ( *a4 + a1 > *(int *)((char *)&dword_1BBA4A + 2) >> 16 )
      return -1000;
    if ( (int16_t)a2 < SHIWORD(dword_1BBA4E) )
      return -1000;
    a2 = a4[1] + (int16_t)a2;
    if ( a2 > *(int *)((char *)&dword_1BBA4E + 2) >> 16 )
      return -1000;
  }
  if ( word_1B3E0E >= word_18447E )
    sub_126487(aTooManyFields, (uint16_t)a2);
  sub_114FBA(a1, v8, a3, a4, a5, a6);
  v6 = (char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
  *((_WORD *)v6 + 4) = 0;
  LOWORD(v6) = ++word_1B3E0E;
  return (int)(v6 - 1);
}
// 11C3C5: could not find valid save-restore pair for ebx
// 18447E: using guessed type int16_t word_18447E;
// 184480: using guessed type _UNKNOWN *off_184480;
// 1845D4: using guessed type char *off_1845D4;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;


//----- (0011C4C1) --------------------------------------------------------
int sub_11C4C1( int a1, int a2, int a3,
        int a4,
        _BYTE *a5,
        int a6,
        int16_t *a7,
        int a8, int a9,
        int64_t a10,
        int a11,
        int a12,
        int a13)
{
  int16_t v13; // ax
  int v14; // eax
  int16_t v15; // ax
  int v18; // [esp+10h] [ebp-4Ch]
  bool v19; // [esp+10h] [ebp-4Ch]
  int v20; // [esp+14h] [ebp-48h]
  int i; // [esp+14h] [ebp-48h]
  int v22; // [esp+18h] [ebp-44h]
  int v23; // [esp+18h] [ebp-44h]
  int v24; // [esp+1Ch] [ebp-40h]
  int v25; // [esp+20h] [ebp-3Ch]
  int16_t v26; // [esp+24h] [ebp-38h]
  int v27; // [esp+2Ch] [ebp-30h]
  int v28; // [esp+30h] [ebp-2Ch]
  int v29; // [esp+30h] [ebp-2Ch]
  int v30; // [esp+38h] [ebp-24h]
  char *v31; // [esp+40h] [ebp-1Ch]
  char *v33; // [esp+48h] [ebp-14h]
  char *v34; // [esp+4Ch] [ebp-10h]
  int16_t v35; // [esp+50h] [ebp-Ch]
  int v36; // [esp+54h] [ebp-8h] BYREF

  byte_184474 = 0;
  LOWORD(off_184496) = 1;
  sub_117174(1);
  sub_11C2F0();
  v25 = sub_122259();
  v24 = sub_122286() + v25;
  v18 = 0;
  v20 = 0;
  v22 = 0;
  v26 = a2;
  v28 = -1;
  while ( !v18 )
  {
    if ( *a5 )
    {
      if ( !v22 && (*(_BYTE *)(v20 + a8) || !a8) )
      {
        v28 = v20;
        v22 = 1;
      }
      v26 += v24;
      if ( a8 )
        sub_11C83D(a1, v26, a3, (int)a5, *(char *)(v20 + a8), (int)a7, v20, a9, a10, a11, a12, &unk_17A59C, a13);
      else
        sub_11C83D(a1, v26, a3, (int)a5, 1, (int)a7, v20, a9, a10, a11, a12, &unk_17A59C, a13);
      ++v20;
    }
    else
    {
      v18 = 1;
    }
    a5 += a6;
  }
  v23 = v20;
  v35 = sub_122201();
  v33 = sub_12222E();
  v34 = sub_1222B3();
  v31 = sub_1222DE();
  sub_120BB5(v35, (int)v33);
  for ( i = 0; i < 8; ++i )
  {
    byte_1B070C[i] = v33[i];
    byte_1B0714[i] = v31[i];
    byte_1B0704[i] = v34[i];
  }
  v36 = 0;
  v13 = (uint16_t)sub_11C83D(a1, a2, a3, a4, 1, (int)&v36, 1, 0, 0, 0, 0, &unk_17A59C, dword_18447A);
  v27 = v13;
  if ( *a7 < 0 || *a7 >= v23 || *a7 < v28 )
  {
    if ( v28 >= 0 && v28 < v23 )
    {
      a2 = *((uint8_t *)off_184480 + 55 * v28 + 83);
      *a7 = a2;
    }
    else
    {
      *a7 = -1;
    }
  }
  while ( 1 )
  {
    sub_12C2A0();
    v15 = sub_1171AB(v14, a2, a3, a4);
    v29 = v15;
    v19 = v15 != 0;
    if ( v15 > 0 && !*(_BYTE *)(v15 + a8 - 1) && a8 || v15 == v27 )
      v19 = 0;
    if ( byte_184474 == 1 )
      v19 = 1;
    if ( v19 )
      break;
    sub_124D41();
    sub_1192D1();
    if ( word_1844A8 )
    {
      v30 = (int16_t)sub_114177();
      if ( v30 != v27 && v30 > 0 )
      {
        a2 = *((uint8_t *)off_184480 + 55 * v30 + 28);
        *a7 = a2;
      }
    }
    sub_124ECB();
    sub_12C2C6((int)off_184496 >> 16);
  }
  sub_11C2F0();
  LOWORD(off_184496) = 0;
  word_1844A8 = 1;
  sub_123C48();
  sub_123C84();
  if ( v29 >= 0 )
    return v29 - 1;
  else
    return -1;
}
// 11C4C1: could not find valid save-restore pair for ebx
// 11C71C: conditional instruction was optimized away because %var_4C.4==0
// 11C727: variable 'v14' is possibly undefined
// 184474: using guessed type char byte_184474;
// 18447A: using guessed type int dword_18447A;
// 184480: using guessed type _UNKNOWN *off_184480;
// 184496: using guessed type _UNKNOWN *off_184496;
// 1844A8: using guessed type int16_t word_1844A8;


//----- (0011C817) --------------------------------------------------------
void sub_11C817()
{
  byte_184474 = 1;
}
// 184474: using guessed type char byte_184474;


//----- (0011C83D) --------------------------------------------------------
char *sub_11C83D( int a1, int a2, int a3,
        int a4, int a5,
        int a6, int a7, int a8,
        int64_t a9,
        int a10,
        int a11,
        _BYTE *a12,
        int a13)
{
  char *v13; // eax

  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16)) = a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 2) = a2 - 1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 10) = sub_122201();
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 12) = byte_1B070C;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 20) = byte_1B0704;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 48) = &byte_1B0714;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 4) = a3 + a1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 6) = a2 + sub_122259() + 1;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 28) = a7;
  *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) = *a12;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 18) = a5;
  if ( *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) > 0x60u
    && *((uint8_t *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) < 0x7Bu )
  {
    *((_BYTE *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 52) -= 32;
  }
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 24) = a4;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 32) = a6;
  *(_WORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 16) = a8;
  *(_QWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 36) = a9;
  *(_DWORD *)((char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16) + 44) = a10;
  v13 = (char *)off_184480 + 55 * (*(int *)((char *)&dword_1B3E0A + 2) >> 16);
  *((_WORD *)v13 + 4) = 10;
  LOWORD(v13) = ++word_1B3E0E;
  return v13 - 1;
}
// 184480: using guessed type _UNKNOWN *off_184480;
// 1B0714: using guessed type char byte_1B0714;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;


//----- (0011CACE) --------------------------------------------------------
int sub_11CACE(int16_t *a1)
{
  int16_t v2; // [esp+0h] [ebp-68h]
  uint8_t v3; // [esp+4h] [ebp-64h]
  int16_t i; // [esp+44h] [ebp-24h]
  int v6; // [esp+50h] [ebp-18h]
  int v7; // [esp+50h] [ebp-18h]
  int v8; // [esp+58h] [ebp-10h]
  int16_t v9; // [esp+5Ch] [ebp-Ch]

  v6 = sub_12C2E1();
  if ( (int16_t)dword_18448E >= word_1B3E0E )
    LOWORD(dword_18448E) = 0;
  v8 = v6;
  v9 = 0;
  switch ( (int16_t)v6 )
  {
    case 496:
      v9 = -1500;
      break;
    case 15104:
      v9 = -1001;
      break;
    case 15360:
      v9 = -1002;
      break;
    case 15616:
      v9 = -1003;
      break;
    case 15872:
      v9 = -1004;
      break;
    case 16128:
      v9 = -1005;
      break;
    case 16384:
      v9 = -1006;
      break;
    case 16640:
      v9 = -1007;
      break;
    case 16896:
      v9 = -1008;
      break;
    case 17152:
      v9 = -1009;
      break;
    case 17408:
      v9 = -1010;
      break;
    case 26624:
      v9 = -1101;
      break;
    case 26880:
      v9 = -1102;
      break;
    case 27136:
      v9 = -1103;
      break;
    case 27392:
      v9 = -1104;
      break;
    case 27648:
      v9 = -1105;
      break;
    case 27904:
      v9 = -1106;
      break;
    case 28160:
      v9 = -1107;
      break;
    case 28416:
      v9 = -1108;
      break;
    case 28672:
      v9 = -1109;
      break;
    case 28928:
      v9 = -1110;
      break;
    default:
      break;
  }
  if ( v9 >= 0 )
  {
    if ( word_1844DC && (v3 = sub_11AB8A(v6), v2 = sub_11AF64(v3), v2 > -1) )
    {
      *a1 = v2;
      return -1;
    }
    else
    {
      v7 = (int16_t)v6 % 256;
      if ( !(_WORD)v7 )
        v7 = v8;
      if ( (int16_t)v7 > 96 && (int16_t)v7 < 123 )
        v7 -= 32;
      *a1 = *a1;
      for ( i = 0; i < word_1B3E0E; ++i )
      {
        if ( dword_1844CE >> 16 == -1 && *((uint8_t *)off_184480 + 55 * i + 52) == (_WORD)v7 )
        {
          *a1 = i;
          break;
        }
      }
      if ( *((uint8_t *)off_184480 + 55 * *a1 + 52) != (_WORD)v7 )
        return v8;
      return v7;
    }
  }
  else
  {
    *a1 = v9;
    return v6;
  }
}
// 184480: using guessed type _UNKNOWN *off_184480;
// 18448E: using guessed type int dword_18448E;
// 1844CE: using guessed type int dword_1844CE;
// 1844DC: using guessed type int16_t word_1844DC;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1B3E14: using guessed type int dword_1B3E14;


//----- (0011CEF5) --------------------------------------------------------
void sub_11CEF5(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int16_t v7; // dx
  int16_t v8; // ax
  uint16_t v9; // ax
  char *v10; // eax
  int v11; // eax
  uint16_t v12; // ax
  char *v13; // eax
  int v14; // eax
  int16_t v15; // ax
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int16_t v19; // ax
  uint16_t v20; // ax
  char *v21; // eax
  int16_t v22; // ax
  uint16_t v23; // ax
  int v24; // eax
  char *v25; // eax
  int v26; // [esp+10h] [ebp-58h]
  int v27; // [esp+14h] [ebp-54h]
  int v28; // [esp+24h] [ebp-44h]
  int v29; // [esp+24h] [ebp-44h]
  int v30; // [esp+24h] [ebp-44h]
  int16_t m; // [esp+24h] [ebp-44h]
  int16_t k; // [esp+24h] [ebp-44h]
  int ii; // [esp+24h] [ebp-44h]
  int16_t i; // [esp+28h] [ebp-40h]
  int16_t j; // [esp+28h] [ebp-40h]
  int16_t jj; // [esp+28h] [ebp-40h]
  int16_t kk; // [esp+28h] [ebp-40h]
  int16_t n; // [esp+2Ch] [ebp-3Ch]
  int16_t v39; // [esp+30h] [ebp-38h]
  int16_t v40; // [esp+30h] [ebp-38h]
  int16_t v41; // [esp+30h] [ebp-38h]
  int16_t v42; // [esp+34h] [ebp-34h]
  int16_t v43; // [esp+34h] [ebp-34h]
  int16_t v44; // [esp+34h] [ebp-34h]
  int16_t v45; // [esp+38h] [ebp-30h]
  int16_t v46; // [esp+38h] [ebp-30h]
  int v47; // [esp+54h] [ebp-14h] BYREF
  int v48; // [esp+58h] [ebp-10h]
  int v49; // [esp+5Ch] [ebp-Ch]
  int v50; // [esp+60h] [ebp-8h]
  char v51; // [esp+64h] [ebp-4h]

  v49 = 0;
  v51 = 0;
  v47 = 0;
  HIWORD(dword_18448E) = -1;
  word_1844A6 = 0;
  v39 = sub_123ABA();
  v42 = sub_123AE7();
  LOWORD(dword_1B3E14) = sub_123FFB();
  LOBYTE(v4) = sub_12C392();
  if ( v4 )
  {
    v48 = sub_11CACE((int16_t *)&v47);
    if ( !(_WORD)v48 || (v47 & 0x8000u) != 0 || (int16_t)v48 == -1 )
    {
      sub_12386C();
      v49 = v47;
      v51 = 1;
      goto LABEL_325;
    }
    if ( (int16_t)v48 == -31488 )
    {
      v5 = IsMemPoolReady_110B5C();
      if ( (int16_t)v5 != 1 )
        sub_1172B0(v5, a2);
    }
    if ( (int16_t)v48 == -31232 )
    {
      LOWORD(v6) = sub_123A30();
      sub_1101F0(v6, a2, a3, a4);
      v7 = sub_123AE7();
      v8 = sub_123ABA();
      sub_123B14(v8, v7);
      sub_123A64();
    }
    if ( (int16_t)v48 == 283 && !word_1844B0 )
    {
      v49 = -1;
      v51 = 1;
      goto LABEL_325;
    }
    if ( (int16_t)v48 == 10592 && !IsMemPoolReady_110B5C() )
      word_1844CC = word_1844CC == 0;
    if ( (int16_t)v48 == 10622 && !IsMemPoolReady_110B5C() )
      LOWORD(dword_1844CE) = (_WORD)dword_1844CE == 0;
    if ( (_WORD)v47 && *((uint8_t *)off_184480 + 55 * (int16_t)v47 + 52) == (_WORD)v48 )
    {
      if ( *(int *)((char *)off_184480 + 55 * (int16_t)v47 + 6) >> 16 == 6 )
      {
        sub_12386C();
        v49 = 0;
        goto LABEL_325;
      }
      sub_118FD4(v47, v39, v42);
      sub_12386C();
      v9 = *(_WORD *)((char *)off_184480 + 55 * (int16_t)v47 + 8);
      if ( v9 < 2u )
      {
        if ( v9 == 1 )
        {
          if ( **(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) )
            **(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) = 0;
          else
            **(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) = 1;
        }
      }
      else if ( v9 <= 2u )
      {
        if ( !**(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) )
          **(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) = 1;
      }
      else if ( v9 == 9 )
      {
        HIWORD(dword_18448E) = -1;
        v10 = (char *)off_184480 + 55 * (int16_t)v47;
        LOWORD(v10) = *((_WORD *)v10 + 12);
        v49 = (int)v10;
        goto LABEL_325;
      }
      if ( *(int *)((char *)off_184480 + 55 * (int16_t)v47 + 6) >> 16 != 7
        && *(int *)((char *)off_184480 + 55 * (int16_t)v47 + 6) >> 16 != 8 )
      {
        sub_119325();
      }
      HIWORD(dword_18448E) = -1;
      v49 = v47;
      goto LABEL_325;
    }
    v11 = (int16_t)v48;
    if ( (int16_t)v48 == 7181 || (v11 = (int16_t)v48, (int16_t)v48 == -8179) )
    {
      if ( word_1844CA )
      {
        LOWORD(v11) = HIWORD(dword_1844CE);
        v28 = v11;
        sub_1203E4();
        if ( !(_WORD)off_1844B2 )
          sub_119325();
        HIWORD(dword_18448E) = -1;
        v49 = v28;
        word_1844CA = 0;
        HIWORD(dword_1844CE) = -1;
        goto LABEL_325;
      }
      v29 = sub_113FB9();
      if ( !(_WORD)v29 )
      {
        v50 = 0;
        return;
      }
      if ( (int16_t)v29 > 0 )
      {
        if ( *(int *)((char *)off_184480 + 55 * (int16_t)v29 + 6) >> 16 == 11 )
        {
          if ( word_1844CA )
          {
            if ( HIWORD(dword_1844CE) == (_WORD)v29 )
            {
              for ( i = 0; byte_1B071C[i] && i < *(int16_t *)((char *)off_184480 + 55 * (int16_t)v29 + 44); ++i )
                ;
              if ( i && byte_1B071B[i] == 95 )
                --i;
              byte_1B071C[i] = 0;
              LOWORD(dword_1844C6) = 0;
              HIWORD(dword_1844CE) = -1;
              strcpy(*(_DWORD *)((char *)off_184480 + 55 * (int16_t)v29 + 24), byte_1B071C);
            }
            else
            {
              sub_1203E4();
              dword_1844C6 = 0;
              HIWORD(dword_1844CE) = v29;
            }
          }
          else
          {
            strcpy(byte_1B071C, *(_DWORD *)((char *)off_184480 + 55 * (int16_t)v29 + 24));
            dword_1844C6 = 0;
            word_1844CA = 1;
            HIWORD(dword_1844CE) = v29;
          }
        }
        else if ( word_1844CA && *(int *)((char *)off_184480 + 55 * (int16_t)v29 + 6) >> 16 != 11 )
        {
          for ( j = 0; byte_1B071C[j] && j < *(int16_t *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 44); ++j )
            ;
          if ( j && byte_1B071B[j] == 95 )
            --j;
          byte_1B071C[j] = 0;
          strcpy(*(_DWORD *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 24), byte_1B071C);
          LOWORD(dword_1844C6) = 0;
          word_1844CA = 0;
          HIWORD(dword_1844CE) = -1;
        }
      }
      if ( *(int *)((char *)off_184480 + 55 * (int16_t)v29 + 6) >> 16 != 6
        && *(int *)((char *)off_184480 + 55 * (int16_t)v29 + 6) >> 16 != 11 )
      {
        sub_118FD4(v29, v39, v42);
      }
      sub_12386C();
      v12 = *(_WORD *)((char *)off_184480 + 55 * (int16_t)v29 + 8);
      if ( v12 < 2u )
      {
        if ( v12 == 1 )
        {
          if ( **(_WORD **)((char *)off_184480 + 55 * (int16_t)v29 + 32) )
            **(_WORD **)((char *)off_184480 + 55 * (int16_t)v29 + 32) = 0;
          else
            **(_WORD **)((char *)off_184480 + 55 * (int16_t)v29 + 32) = 1;
        }
        goto LABEL_100;
      }
      if ( v12 <= 2u )
      {
        if ( !**(_WORD **)((char *)off_184480 + 55 * (int16_t)v29 + 32) )
          **(_WORD **)((char *)off_184480 + 55 * (int16_t)v29 + 32) = 1;
        goto LABEL_100;
      }
      if ( v12 != 9 )
      {
LABEL_100:
        if ( !(_WORD)off_1844B2 )
          sub_119325();
        HIWORD(dword_18448E) = -1;
        v49 = v29;
        goto LABEL_325;
      }
      HIWORD(dword_18448E) = -1;
      v13 = (char *)off_184480 + 55 * (int16_t)v29;
      LOWORD(v13) = *((_WORD *)v13 + 12);
      v49 = (int)v13;
      goto LABEL_325;
    }
    if ( (int16_t)v48 == 3371 || (int16_t)v48 == 3117 )
    {
      v30 = sub_113FB9();
      if ( (_WORD)v30 )
      {
        if ( *(int *)((char *)off_184480 + 55 * (int16_t)v30 + 6) >> 16 == 6 )
        {
          if ( (int16_t)v48 == 3371 )
            sub_115994(v30);
          if ( (int16_t)v48 == 3117 )
            sub_115AC0(v30);
          sub_12386C();
          HIWORD(dword_18448E) = -1;
          v49 = v30;
          goto LABEL_325;
        }
      }
    }
    if ( word_1844CA <= 0 )
      goto LABEL_167;
    switch ( (int16_t)v48 )
    {
      case 283:
        v14 = *(int *)((char *)&dword_1844C6 + 2) >> 16;
        if ( *(int *)((char *)&dword_1844C6 + 2) >> 16 == 1 )
          v14 = strcpy(byte_1B071C, *(_DWORD *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 24));
        word_1844CA = 0;
        LOWORD(v14) = HIWORD(dword_1844CE);
        v49 = -v14;
        HIWORD(dword_1844CE) = -1;
        dword_1844C6 = 0;
        goto LABEL_325;
      case 3711:
        byte_1B071C[0] = 0;
        byte_1B3E18 = 0;
        goto LABEL_167;
      case 3592:
        if ( byte_1B3E18 )
        {
          byte_1B071C[0] = 0;
          byte_1B3E18 = 0;
        }
        else
        {
          for ( k = 0;
                byte_1B071C[k]
             && byte_1B071C[k] != 95
             && k < (*(int *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 42) >> 16) - 1;
                ++k )
          {
            ;
          }
          if ( k > 0 )
          {
            byte_1B071B[k] = 0;
            LOWORD(dword_1844C6) = 0;
          }
        }
        goto LABEL_167;
    }
    v48 = (int16_t)v48 % 256;
    byte_1B3E18 = 0;
    if ( (int16_t)v48 < 32 || (int16_t)v48 > 126 || (int16_t)v48 == 95 )
    {
LABEL_167:
      HIWORD(dword_18448E) = -1;
      sub_12386C();
      v49 = 0;
      goto LABEL_325;
    }
    if ( SHIWORD(dword_1844CE) > -1 && SHIWORD(dword_1844CE) < word_1B3E0E )
    {
      v15 = *(_WORD *)((char *)off_184480 + 55 * SHIWORD(dword_1844CE) + 48);
      if ( v15 < 0 )
      {
        if ( v15 == -1 )
        {
          sub_120CCB(
            HIWORD(*(_DWORD *)((char *)off_184480 + 55 * SHIWORD(dword_1844CE) + 8)),
            *(_DWORD *)((char *)off_184480 + 55 * SHIWORD(dword_1844CE) + 12));
          goto LABEL_135;
        }
      }
      else if ( v15 == 1 )
      {
        sub_120D05(
          HIWORD(*(_DWORD *)((char *)off_184480 + 55 * SHIWORD(dword_1844CE) + 8)),
          *(_DWORD *)((char *)off_184480 + 55 * SHIWORD(dword_1844CE) + 12));
        goto LABEL_135;
      }
      sub_120BB5(
        *(int *)((char *)off_184480 + 55 * SHIWORD(dword_1844CE) + 8) >> 16,
        *(_DWORD *)((char *)off_184480 + 55 * SHIWORD(dword_1844CE) + 12));
    }
LABEL_135:
    for ( m = 0;
          byte_1B071C[m] != 95
       && byte_1B071C[m]
       && m < (*(int *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 42) >> 16) - 1;
          ++m )
    {
      ;
    }
    if ( m < (*(int *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 42) >> 16) - 1
      && (v16 = *(int16_t *)((char *)off_184480 + 55 * (dword_1844CE >> 16)),
          (int16_t)sub_12066F((int)byte_1B071C) + v16 <= *(int *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 2) >> 16) )
    {
      byte_1B071C[m] = v48;
      byte_1B071D[m] = 0;
      for ( n = 0; n < 10; ++n )
      {
        LOBYTE(v17) = sub_12C392();
        if ( v17 == 1
          && sub_12C35B() % 256 >= 65
          && sub_12C35B() % 256 <= 122
          && m + n + 1 < (*(int *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 42) >> 16) - 1 )
        {
          LOWORD(v48) = sub_12C2E1() % 256;
          byte_1B071D[m + n] = v48;
          byte_1B071E[m + n] = 0;
        }
      }
    }
    else
    {
      byte_1B071C[m] = 0;
    }
    dword_1844C6 = 0;
    goto LABEL_167;
  }
  sub_123926();
  if ( !sub_124075() )
  {
    LOWORD(v18) = sub_123C48();
    if ( !v18 )
    {
      word_1844E2 = 0;
      sub_12386C();
      v49 = 0;
      goto LABEL_325;
    }
    v45 = sub_123C1B();
    if ( v45 == 2 )
    {
      if ( word_1844D8 && !sub_119732() )
      {
LABEL_174:
        sub_123C48();
        sub_123C84();
        v49 = 0;
        goto LABEL_325;
      }
      if ( !word_1844B0 )
      {
        sub_123C48();
        sub_123C84();
        v49 = -1;
        if ( word_1844DC )
          sub_11AEF7();
        goto LABEL_325;
      }
    }
    v40 = sub_123BC1();
    v19 = sub_123BEE();
    v43 = v19;
    if ( !word_1844E2 )
    {
      word_1844E2 = 1;
      word_1844DE = v40;
      word_1844E0 = v19;
    }
    v47 = 0;
    LOWORD(v48) = 0;
    sub_123EA7();
    LOWORD(dword_1B3E14) = sub_123FFB();
    for ( ii = 1; (int16_t)ii < word_1B3E0E; ++ii )
    {
      if ( (*(int *)((char *)&dword_1B3E10 + 2) >> 16) + v40 >= *(int16_t *)((char *)off_184480 + 55 * (int16_t)ii)
        && (*(int *)((char *)&dword_1B3E10 + 2) >> 16) + v40 <= *(int16_t *)((char *)off_184480 + 55 * (int16_t)ii + 4)
        && (*(int *)((char *)&dword_1B3E10 + 2) >> 16) + v43 >= *(int16_t *)((char *)off_184480 + 55 * (int16_t)ii + 2)
        && (*(int *)((char *)&dword_1B3E10 + 2) >> 16) + v43 <= *(int16_t *)((char *)off_184480 + 55 * (int16_t)ii + 6) )
      {
        if ( *(int *)((char *)off_184480 + 55 * (int16_t)ii + 6) >> 16 != 14 )
        {
          v47 = ii;
          break;
        }
        v27 = v40 - (*(int *)((char *)off_184480 + 55 * (int16_t)ii + 22) >> 16);
        v26 = v43 - (*(int *)((char *)off_184480 + 55 * (int16_t)ii + 26) >> 16);
        if ( v26 * v26 + v27 * v27 <= *(_DWORD *)((char *)off_184480 + 55 * (int16_t)ii + 32) )
        {
          v47 = ii;
          break;
        }
      }
    }
    if ( (_WORD)v47 && *(int *)((char *)off_184480 + 55 * (int16_t)v47 + 6) >> 16 != 11 )
    {
      word_1844A6 = v47;
      sub_118FD4(v47, v40, v43);
      sub_119325();
    }
    if ( (_WORD)v47 )
    {
      v20 = *(_WORD *)((char *)off_184480 + 55 * (int16_t)v47 + 8);
      if ( v20 < 4u )
      {
        if ( v20 )
        {
          if ( v20 <= 1u )
          {
            if ( **(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) )
              **(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) = 0;
            else
              **(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) = 1;
            goto LABEL_234;
          }
          if ( v20 == 2 )
          {
            if ( !**(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) )
              **(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) = 1;
            goto LABEL_234;
          }
        }
LABEL_224:
        if ( word_1844CA )
        {
          for ( jj = 0; byte_1B071C[jj] && jj < *(int16_t *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 44); ++jj )
            ;
          if ( jj && byte_1B071B[jj] == 95 )
            --jj;
          byte_1B071C[jj] = 0;
          strcpy(*(_DWORD *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 24), byte_1B071C);
          word_1844CA = 0;
          HIWORD(dword_1844CE) = -1;
        }
        goto LABEL_234;
      }
      if ( v20 > 4u )
      {
        if ( v20 >= 9u )
        {
          if ( v20 <= 9u )
          {
            sub_12386C();
            HIWORD(dword_18448E) = -1;
            v21 = (char *)off_184480 + 55 * (int16_t)v47;
            LOWORD(v21) = *((_WORD *)v21 + 12);
            v49 = (int)v21;
            goto LABEL_325;
          }
          if ( v20 == 11 )
          {
            if ( word_1844CA )
            {
              if ( HIWORD(dword_1844CE) != (_WORD)v47 )
              {
                strcpy(byte_1B071C, *(_DWORD *)((char *)off_184480 + 55 * (int16_t)v47 + 24));
                dword_1844C6 = 0;
                HIWORD(dword_1844CE) = v47;
              }
            }
            else
            {
              strcpy(byte_1B071C, *(_DWORD *)((char *)off_184480 + 55 * (int16_t)v47 + 24));
              dword_1844C6 = 0;
              word_1844CA = 1;
              HIWORD(dword_1844CE) = v47;
            }
            goto LABEL_234;
          }
        }
        goto LABEL_224;
      }
      sub_118FD4(v47, v40, v43);
    }
LABEL_234:
    HIWORD(dword_18448E) = -1;
    if ( (_WORD)v47 )
    {
      sub_123C84();
      word_1B3E08 = v40;
      LOWORD(dword_1B3E0A) = v43;
      word_1B3E06 = v45;
    }
    sub_12386C();
    word_1844A6 = 0;
    if ( v45 == 2 )
      v49 = -v47;
    else
      v49 = v47;
    goto LABEL_325;
  }
  v46 = sub_124075();
  if ( v46 == 2 )
  {
    if ( word_1844D8 && !sub_119732() )
      goto LABEL_174;
    if ( !word_1844B0 )
    {
      while ( sub_124075() == 2 )
        sub_119325();
      sub_123C48();
      sub_123C84();
      v49 = -1;
      goto LABEL_325;
    }
  }
  v41 = sub_123ABA();
  v22 = sub_123AE7();
  v44 = v22;
  if ( !word_1844E2 )
  {
    word_1844E2 = 1;
    word_1844DE = v41;
    word_1844E0 = v22;
  }
  while ( sub_124075() )
  {
    v41 = sub_123ABA();
    v44 = sub_123AE7();
    LOWORD(dword_1B3E14) = sub_123FFB();
    v47 = 0;
    LOWORD(v48) = 0;
    if ( word_1844E4 )
    {
      v47 = sub_113FB9();
      HIWORD(dword_18448E) = -1;
    }
    if ( !(_WORD)v47 )
    {
      if ( dword_18448E >> 16 != -1 )
      {
        if ( *(int *)((char *)off_184480 + 55 * (dword_18448E >> 16) + 6) >> 16 == 6 )
          sub_1192D1();
        if ( *(int *)((char *)off_184480 + 55 * (dword_18448E >> 16) + 6) >> 16 != 3
          && *(int *)((char *)off_184480 + 55 * (dword_18448E >> 16) + 6) >> 16 != 10
          && *(int *)((char *)off_184480 + 55 * (dword_18448E >> 16) + 6) >> 16 != 11 )
        {
          sub_123A30();
          sub_11B05A((char *)(dword_18448E >> 16), 0);
          sub_123B14(v41, v44);
          sub_123A64();
        }
        HIWORD(dword_18448E) = -1;
      }
      break;
    }
    if ( (_WORD)v47 != HIWORD(dword_18448E)
      && *(int *)((char *)off_184480 + 55 * (int16_t)v47 + 6) >> 16 != 4
      && *(int *)((char *)off_184480 + 55 * (int16_t)v47 + 6) >> 16 != 11
      && (dword_18448E >> 16 == -1
       || *(int *)((char *)off_184480 + 55 * (int16_t)v47 + 6) >> 16 != 12
       || *(int *)((char *)off_184480 + 55 * (dword_18448E >> 16) + 6) >> 16 != 12) )
    {
      if ( dword_18448E >> 16 != -1 && *(int *)((char *)off_184480 + 55 * (dword_18448E >> 16) + 6) >> 16 == 6 )
        sub_1192D1();
      sub_118FD4(v47, v41, v44);
    }
    if ( *(int *)((char *)off_184480 + 55 * (int16_t)v47 + 6) >> 16 == 11 )
    {
      if ( word_1844CA )
      {
        if ( HIWORD(dword_1844CE) != (_WORD)v47 )
        {
          strcpy(byte_1B071C, *(_DWORD *)((char *)off_184480 + 55 * (int16_t)v47 + 24));
          dword_1844C6 = 0;
          word_1844CA = 1;
          HIWORD(dword_1844CE) = v47;
          byte_1B3E18 = 1;
        }
      }
      else
      {
        strcpy(byte_1B071C, *(_DWORD *)((char *)off_184480 + 55 * (int16_t)v47 + 24));
        dword_1844C6 = 0;
        word_1844CA = 1;
        HIWORD(dword_1844CE) = v47;
        byte_1B3E18 = 1;
      }
    }
    else if ( word_1844CA )
    {
      for ( kk = 0; byte_1B071C[kk] && kk < *(int16_t *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 44); ++kk )
        ;
      if ( kk && byte_1B071B[kk] == 95 )
        --kk;
      byte_1B071C[kk] = 0;
      strcpy(*(_DWORD *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 24), byte_1B071C);
      word_1844CA = 0;
      HIWORD(dword_1844CE) = -1;
    }
    word_1844A6 = v47;
    if ( (_WORD)off_1844B2 )
      break;
    if ( sub_124075() )
      sub_1193A0();
    sub_123C48();
    sub_123C84();
  }
  if ( *(int *)((char *)off_184480 + 55 * ((int)unk_1844A4 >> 16) + 6) >> 16 == 6 )
    sub_1192D1();
  word_1844A6 = 0;
  if ( (_WORD)v47 )
  {
    sub_123C48();
    sub_123C84();
    word_1B3E08 = v41;
    LOWORD(dword_1B3E0A) = v44;
    word_1B3E06 = v46;
    v23 = *(_WORD *)((char *)off_184480 + 55 * (int16_t)v47 + 8);
    if ( v23 < 2u )
    {
      if ( v23 == 1 )
      {
        if ( !**(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) )
        {
          sub_16937A(*(char **)((char *)off_184480 + 55 * (int16_t)v47 + 32));
          return;
        }
        **(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) = 0;
      }
    }
    else if ( v23 <= 2u )
    {
      if ( !**(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) )
        **(_WORD **)((char *)off_184480 + 55 * (int16_t)v47 + 32) = 1;
    }
    else if ( v23 >= 4u )
    {
      if ( v23 <= 4u )
      {
        sub_118FD4(v47, v41, v44);
      }
      else if ( v23 == 9 )
      {
        if ( v46 == 2 )
        {
          sub_12386C();
          HIWORD(dword_18448E) = -1;
          if ( word_1844B0 )
          {
            v24 = (int)off_184480 + 55 * (int16_t)v47;
            LOWORD(v24) = *(_WORD *)(v24 + 24);
            v50 = -v24;
          }
          else
          {
            v50 = -1;
          }
        }
        else
        {
          sub_12386C();
          HIWORD(dword_18448E) = -1;
          v25 = (char *)off_184480 + 55 * (int16_t)v47;
          LOWORD(v25) = *((_WORD *)v25 + 12);
          v50 = (int)v25;
        }
        return;
      }
    }
  }
  sub_12386C();
  HIWORD(dword_18448E) = -1;
  if ( !v46 )
    goto LABEL_322;
  if ( (uint16_t)v46 <= 1u )
  {
    v51 = 1;
    v49 = v47;
    goto LABEL_325;
  }
  if ( v46 != 2 )
  {
LABEL_322:
    v49 = 0;
    goto LABEL_325;
  }
  v51 = 1;
  v49 = -v47;
LABEL_325:
  if ( word_1844DC )
  {
    if ( v51 )
      sub_11AEF7();
  }
}
// 11D0CE: conditional instruction was optimized away because %var_14.2!=0
// 11D491: conditional instruction was optimized away because %var_44.2!=0
// 11CF61: variable 'v4' is possibly undefined
// 11CFCC: variable 'v6' is possibly undefined
// 11D9E8: variable 'v17' is possibly undefined
// 11DB6B: variable 'v18' is possibly undefined
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184480: using guessed type _UNKNOWN *off_184480;
// 18448E: using guessed type int dword_18448E;
// 184496: using guessed type _UNKNOWN *off_184496;
// 1844A6: using guessed type int16_t word_1844A6;
// 1844B0: using guessed type int16_t word_1844B0;
// 1844B2: using guessed type _UNKNOWN *off_1844B2;
// 1844C6: using guessed type int dword_1844C6;
// 1844CA: using guessed type int16_t word_1844CA;
// 1844CC: using guessed type int16_t word_1844CC;
// 1844CE: using guessed type int dword_1844CE;
// 1844D8: using guessed type int16_t word_1844D8;
// 1844DC: using guessed type int16_t word_1844DC;
// 1844DE: using guessed type int16_t word_1844DE;
// 1844E0: using guessed type int16_t word_1844E0;
// 1844E2: using guessed type int16_t word_1844E2;
// 1844E4: using guessed type int16_t word_1844E4;
// 1B3E06: using guessed type int16_t word_1B3E06;
// 1B3E08: using guessed type int16_t word_1B3E08;
// 1B3E0A: using guessed type int dword_1B3E0A;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1B3E10: using guessed type int dword_1B3E10;
// 1B3E14: using guessed type int dword_1B3E14;
// 1B3E18: using guessed type char byte_1B3E18;


//----- (0011E718) --------------------------------------------------------
int sub_11E718()
{
  int v0; // kr04_4
  int16_t v1; // ax
  int16_t v2; // ax
  int v3; // ebx
  int v4; // ebx
  int v5; // ecx
  int16_t v6; // ax
  int16_t v7; // ax
  int v8; // ebx
  int v9; // ecx
  int16_t v10; // ax
  int16_t v12; // [esp+Ch] [ebp-30h]
  int16_t k; // [esp+Ch] [ebp-30h]
  int16_t j; // [esp+10h] [ebp-2Ch]
  int16_t i; // [esp+10h] [ebp-2Ch]
  int16_t v16; // [esp+10h] [ebp-2Ch]
  int v17; // [esp+14h] [ebp-28h]
  int v18; // [esp+14h] [ebp-28h]
  int v19; // [esp+18h] [ebp-24h]
  int16_t v20; // [esp+1Ch] [ebp-20h]
  _BOOL2 v21; // [esp+28h] [ebp-14h]
  int16_t v22; // [esp+2Ch] [ebp-10h]
  int16_t v23; // [esp+38h] [ebp-4h]

  v22 = HIWORD(dword_1BBA4A);
  v0 = dword_1BBA4E;
  v23 = dword_1BBA52;
  sub_128BE7();
  sub_124D41();
  if ( (_WORD)dword_1844E6 )
  {
    v12 = 1;
    while ( v12 < word_1B3E0E )
    {
      if ( HIWORD(dword_18448E) == v12
        && *(int *)((char *)off_184480 + 55 * v12 + 6) >> 16 != 4
        && *(int *)((char *)off_184480 + 55 * v12 + 6) >> 16 != 12
        && *(int *)((char *)off_184480 + 55 * v12 + 6) >> 16 != 10 )
      {
        sub_11B05A((char *)v12, 1);
        goto LABEL_5;
      }
      switch ( *(_WORD *)((char *)off_184480 + 55 * v12 + 8) )
      {
        case 0:
          sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
          sub_12A478(
            *(_WORD *)((char *)off_184480 + 55 * v12),
            HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
            *(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
          if ( *(_DWORD *)((char *)off_184480 + 55 * v12 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v12 + 24) )
            goto LABEL_46;
          goto LABEL_122;
        case 1:
          if ( **(_WORD **)((char *)off_184480 + 55 * v12 + 32) )
          {
            if ( *(_WORD *)((char *)off_184480 + 55 * v12 + 36) )
            {
              sub_12B753(*(_DWORD *)((char *)off_184480 + 55 * v12 + 44), 1);
            }
            else
            {
              sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
              sub_12A478(
                *(_WORD *)((char *)off_184480 + 55 * v12),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            }
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v12),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
              *(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v12 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v12 + 24) )
              goto LABEL_53;
          }
          else
          {
            sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v12),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
              *(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v12 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v12 + 24) )
              goto LABEL_46;
          }
          goto LABEL_122;
        case 2:
          if ( **(_WORD **)((char *)off_184480 + 55 * v12 + 32) )
          {
            if ( *(_WORD *)((char *)off_184480 + 55 * v12 + 36) )
            {
              sub_12B753(*(_DWORD *)((char *)off_184480 + 55 * v12 + 44), 1);
            }
            else
            {
              sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
              sub_12A478(
                *(_WORD *)((char *)off_184480 + 55 * v12),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            }
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v12),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
              *(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v12 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v12 + 24) )
              goto LABEL_53;
          }
          else
          {
            sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v12),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
              *(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v12 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v12 + 24) )
              goto LABEL_46;
          }
          goto LABEL_122;
        case 3:
          if ( **(_WORD **)((char *)off_184480 + 55 * v12 + 32) == *(_WORD *)((char *)off_184480 + 55 * v12 + 28) )
          {
            if ( *(_WORD *)((char *)off_184480 + 55 * v12 + 36) )
            {
              sub_12B753(*(_DWORD *)((char *)off_184480 + 55 * v12 + 44), 1);
            }
            else
            {
              sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
              sub_12A478(
                *(_WORD *)((char *)off_184480 + 55 * v12),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            }
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v12),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
              *(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v12 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v12 + 24) )
            {
LABEL_53:
              sub_120BB5(
                *(int *)((char *)off_184480 + 55 * v12 + 8) >> 16,
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 12));
              v18 = (sub_122259() - 1) / 2;
              sub_1210FD(
                *(_WORD *)((char *)off_184480 + 55 * v12)
              + ((*(int *)((char *)off_184480 + 55 * v12 + 2) >> 16) - *(int16_t *)((char *)off_184480 + 55 * v12)) / 2
              + dword_184492,
                HIWORD(dword_184492)
              + ((*(int *)((char *)off_184480 + 55 * v12 + 4) >> 16) - (*(int *)((char *)off_184480 + 55 * v12) >> 16))
              / 2
              + HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12))
              - v18,
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 24));
            }
          }
          else
          {
            sub_12B726(*(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            sub_12A478(
              *(_WORD *)((char *)off_184480 + 55 * v12),
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
              *(_DWORD *)((char *)off_184480 + 55 * v12 + 44));
            if ( *(_DWORD *)((char *)off_184480 + 55 * v12 + 24) && **(_BYTE **)((char *)off_184480 + 55 * v12 + 24) )
            {
LABEL_46:
              sub_120BB5(
                *(int *)((char *)off_184480 + 55 * v12 + 8) >> 16,
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 12));
              v17 = (sub_122259() - 1) / 2;
              sub_1210FD(
                ((*(int *)((char *)off_184480 + 55 * v12 + 2) >> 16) - *(int16_t *)((char *)off_184480 + 55 * v12)) / 2
              + *(_WORD *)((char *)off_184480 + 55 * v12),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12))
              + ((*(int *)((char *)off_184480 + 55 * v12 + 4) >> 16) - (*(int *)((char *)off_184480 + 55 * v12) >> 16))
              / 2
              - v17,
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 24));
            }
          }
          goto LABEL_122;
        case 4:
          if ( HIWORD(dword_18448E) != v12 )
          {
            sub_120BB5(
              *(int *)((char *)off_184480 + 55 * v12 + 8) >> 16,
              *(_DWORD *)((char *)off_184480 + 55 * v12 + 12));
            sub_120EB9(*(_DWORD *)((char *)off_184480 + 55 * v12 + 20));
            if ( *(_WORD *)((char *)off_184480 + 55 * v12 + 32) )
              sub_128C32(
                (int16_t)(*(_WORD *)((char *)off_184480 + 55 * v12) - 1),
                *(int *)((char *)off_184480 + 55 * v12) >> 16,
                *(int *)((char *)off_184480 + 55 * v12 + 2) >> 16,
                *(int *)((char *)off_184480 + 55 * v12 + 4) >> 16,
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12 + 30)));
            if ( *(_WORD *)((char *)off_184480 + 55 * v12 + 36) )
              sub_1210B7(
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12 + 2)),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 24));
            else
              sub_1212B3(
                *(_WORD *)((char *)off_184480 + 55 * v12),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 24));
          }
          goto LABEL_122;
        case 6:
          v20 = **(_WORD **)((char *)off_184480 + 55 * v12 + 32);
          if ( v20 < *(int16_t *)((char *)off_184480 + 55 * v12 + 24) )
            v20 = *(_WORD *)((char *)off_184480 + 55 * v12 + 24);
          if ( v20 > *(int16_t *)((char *)off_184480 + 55 * v12 + 28) )
            v20 = *(_WORD *)((char *)off_184480 + 55 * v12 + 28);
          **(_WORD **)((char *)off_184480 + 55 * v12 + 32) = v20;
          goto LABEL_122;
        case 0xA:
          sub_120BB5(*(int *)((char *)off_184480 + 55 * v12 + 8) >> 16, *(_DWORD *)((char *)off_184480 + 55 * v12 + 12));
          v19 = sub_122286() / 2;
          if ( !(_WORD)v19 )
            LOWORD(v19) = 1;
          v1 = sub_122259();
          if ( **(_WORD **)((char *)off_184480 + 55 * v12 + 32) == *(_WORD *)((char *)off_184480 + 55 * v12 + 28) )
          {
            if ( *(int *)((char *)off_184480 + 55 * v12 + 14) >> 16 == 17 )
              sub_120BB5(*(int *)((char *)off_184480 + 55 * v12 + 8) >> 16, (int)&byte_1B0704);
            else
              sub_129B84(
                *(_WORD *)((char *)off_184480 + 55 * v12) - 1,
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)) - v19 + 1,
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12 + 2)),
                v1 + HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)) + 1,
                *(int *)((char *)off_184480 + 55 * v12 + 14) >> 16,
                *(uint8_t **)((char *)off_184480 + 55 * v12 + 36),
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 40),
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 44),
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 48));
          }
          else if ( !*(_WORD *)((char *)off_184480 + 55 * v12 + 18) )
          {
            sub_120BB5(*(int *)((char *)off_184480 + 55 * v12 + 8) >> 16, (int)&byte_1B0714);
          }
          sub_1212B3(
            *(_WORD *)((char *)off_184480 + 55 * v12),
            *(_WORD *)((char *)off_184480 + 55 * v12 + 2) + 1,
            *(_DWORD *)((char *)off_184480 + 55 * v12 + 24));
          goto LABEL_122;
        case 0xB:
          if ( HIWORD(dword_1844CE) == v12 )
          {
            v7 = *(_WORD *)((char *)off_184480 + 55 * v12 + 48);
            if ( v7 < 0 )
            {
              if ( v7 == -1 )
              {
                sub_120CCB(
                  HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12 + 8)),
                  *(_DWORD *)((char *)off_184480 + 55 * v12 + 12));
                sub_120EB9(*(_DWORD *)((char *)off_184480 + 55 * v12 + 20));
              }
              else
              {
LABEL_97:
                sub_120BB5(
                  *(int *)((char *)off_184480 + 55 * v12 + 8) >> 16,
                  *(_DWORD *)((char *)off_184480 + 55 * v12 + 12));
                sub_120EB9(*(_DWORD *)((char *)off_184480 + 55 * v12 + 20));
              }
            }
            else
            {
              if ( v7 != 1 )
                goto LABEL_97;
              sub_120D05(
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12 + 8)),
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 12));
              sub_120EB9(*(_DWORD *)((char *)off_184480 + 55 * v12 + 20));
            }
            sub_121B8C();
            if ( *(_WORD *)((char *)off_184480 + 55 * v12 + 32) )
              sub_128C32(
                (int16_t)(*(_WORD *)((char *)off_184480 + 55 * v12) - 1),
                *(int *)((char *)off_184480 + 55 * v12) >> 16,
                *(int *)((char *)off_184480 + 55 * v12 + 2) >> 16,
                *(int *)((char *)off_184480 + 55 * v12 + 4) >> 16,
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12 + 30)));
            v21 = dword_1844C6 >> 16 != (*(int *)((char *)&dword_1844C2 + 2) >> 16) / 2;
            HIWORD(dword_1844C6) = (*(int *)((char *)&dword_1844C2 + 2) >> 16) / 2;
            LOWORD(dword_1844C6) = dword_1844C6 + 1;
            if ( *(int *)((char *)&dword_1844C2 + 2) >> 16 > 3 )
              LOWORD(dword_1844C6) = 0;
            if ( v21 )
            {
              if ( HIWORD(dword_1844C6) )
              {
                for ( i = 0; byte_1B071C[i] && i < (*(int *)((char *)off_184480 + 55 * v12 + 42) >> 16) - 2; ++i )
                  ;
                if ( i < (*(int *)((char *)off_184480 + 55 * v12 + 42) >> 16) - 1 )
                  strcat(byte_1B071C, asc_17A59D);
              }
              else
              {
                for ( j = 0; byte_1B071C[j] != 95 && j < (*(int *)((char *)off_184480 + 55 * v12 + 42) >> 16) - 1; ++j )
                  ;
                byte_1B071C[j] = 0;
              }
            }
            if ( *(_DWORD *)((char *)off_184480 + 55 * v12 + 28) )
              sub_12A478(
                *(_WORD *)((char *)off_184480 + 55 * v12),
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 28));
            v8 = (*(int *)((char *)off_184480 + 55 * v12 + 4) >> 16) - (*(int *)((char *)off_184480 + 55 * v12) >> 16);
            if ( v8 <= sub_122259() )
            {
              sub_1212B3(
                *(_WORD *)((char *)off_184480 + 55 * v12) + 10,
                HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
                (int)byte_1B071C);
            }
            else
            {
              v9 = (*(int *)((char *)off_184480 + 55 * v12) >> 16)
                 + ((*(int *)((char *)off_184480 + 55 * v12 + 4) >> 16) - (*(int *)((char *)off_184480 + 55 * v12) >> 16))
                 / 2;
              v10 = sub_122259();
              sub_1212B3(*(_WORD *)((char *)off_184480 + 55 * v12) + 10, v9 - v10 / 2, (int)byte_1B071C);
            }
            sub_121B40();
            goto LABEL_122;
          }
          v2 = *(_WORD *)((char *)off_184480 + 55 * v12 + 48);
          if ( v2 < 0 )
          {
            if ( v2 != -1 )
            {
LABEL_84:
              sub_120BB5(
                *(int *)((char *)off_184480 + 55 * v12 + 8) >> 16,
                *(_DWORD *)((char *)off_184480 + 55 * v12 + 12));
              goto LABEL_85;
            }
            sub_120CCB(
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12 + 8)),
              *(_DWORD *)((char *)off_184480 + 55 * v12 + 12));
          }
          else
          {
            if ( v2 != 1 )
              goto LABEL_84;
            sub_120D05(
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12 + 8)),
              *(_DWORD *)((char *)off_184480 + 55 * v12 + 12));
          }
LABEL_85:
          if ( *(_WORD *)((char *)off_184480 + 55 * v12 + 32) )
            sub_128C32(
              (int16_t)(*(_WORD *)((char *)off_184480 + 55 * v12) - 1),
              *(int *)((char *)off_184480 + 55 * v12) >> 16,
              *(int *)((char *)off_184480 + 55 * v12 + 2) >> 16,
              *(int *)((char *)off_184480 + 55 * v12 + 4) >> 16,
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12 + 30)));
          v3 = (*(int *)((char *)off_184480 + 55 * v12 + 4) >> 16) - (*(int *)((char *)off_184480 + 55 * v12) >> 16);
          if ( v3 <= sub_122259() )
          {
            sub_1212B3(
              *(_WORD *)((char *)off_184480 + 55 * v12) + 10,
              HIWORD(*(_DWORD *)((char *)off_184480 + 55 * v12)),
              *(_DWORD *)((char *)off_184480 + 55 * v12 + 24));
          }
          else
          {
            v4 = *(_DWORD *)((char *)off_184480 + 55 * v12 + 24);
            v5 = (*(int *)((char *)off_184480 + 55 * v12) >> 16)
               + ((*(int *)((char *)off_184480 + 55 * v12 + 4) >> 16) - (*(int *)((char *)off_184480 + 55 * v12) >> 16))
               / 2;
            v6 = sub_122259();
            sub_1212B3(*(_WORD *)((char *)off_184480 + 55 * v12) + 10, v5 - v6 / 2, v4);
          }
LABEL_122:
          if ( word_1844CC && *(int *)((char *)off_184480 + 55 * v12 + 6) >> 16 != 8 )
          {
            sub_12B634();
            sub_134D2D(
              *(int16_t *)((char *)off_184480 + 55 * v12),
              *(int *)((char *)off_184480 + 55 * v12) >> 16,
              *(int *)((char *)off_184480 + 55 * v12 + 2) >> 16,
              *(int *)((char *)off_184480 + 55 * v12) >> 16,
              SHIWORD(off_1844B2));
            sub_134D2D(
              *(int16_t *)((char *)off_184480 + 55 * v12),
              *(int *)((char *)off_184480 + 55 * v12) >> 16,
              *(int16_t *)((char *)off_184480 + 55 * v12),
              *(int *)((char *)off_184480 + 55 * v12 + 4) >> 16,
              SHIWORD(off_1844B2));
            sub_134D2D(
              *(int16_t *)((char *)off_184480 + 55 * v12),
              *(int *)((char *)off_184480 + 55 * v12 + 4) >> 16,
              *(int *)((char *)off_184480 + 55 * v12 + 2) >> 16,
              *(int *)((char *)off_184480 + 55 * v12 + 4) >> 16,
              SHIWORD(off_1844B2));
            sub_134D2D(
              *(int *)((char *)off_184480 + 55 * v12 + 2) >> 16,
              *(int *)((char *)off_184480 + 55 * v12) >> 16,
              *(int *)((char *)off_184480 + 55 * v12 + 2) >> 16,
              *(int *)((char *)off_184480 + 55 * v12 + 4) >> 16,
              SHIWORD(off_1844B2));
            sub_12B65C();
          }
LABEL_5:
          ++v12;
          break;
        default:
          goto LABEL_122;
      }
    }
  }
  if ( (_WORD)dword_1844CE && word_1844DA )
  {
    for ( k = 0; k < word_1844DA; ++k )
    {
      v16 = 5 * k;
      if ( *(int16_t *)(2 * (int16_t)(5 * k) + dword_1B0838) != -1 )
      {
        sub_12B634();
        sub_134D2D(
          *(int *)(dword_1B0838 + 2 * v16) >> 16,
          *(int *)(2 * v16 + dword_1B0838 + 2) >> 16,
          *(int *)(dword_1B0838 + 2 * v16 + 4) >> 16,
          *(int *)(2 * v16 + dword_1B0838 + 2) >> 16,
          word_1844B6);
        sub_134D2D(
          *(int *)(dword_1B0838 + 2 * v16) >> 16,
          *(int *)(2 * v16 + dword_1B0838 + 2) >> 16,
          *(int *)(2 * v16 + dword_1B0838) >> 16,
          *(int *)(2 * v16 + dword_1B0838 + 6) >> 16,
          word_1844B6);
        sub_134D2D(
          *(int *)(dword_1B0838 + 2 * v16) >> 16,
          *(int *)(2 * v16 + dword_1B0838 + 6) >> 16,
          *(int *)(dword_1B0838 + 2 * v16 + 4) >> 16,
          *(int *)(2 * v16 + dword_1B0838 + 6) >> 16,
          word_1844B6);
        sub_134D2D(
          *(int *)(dword_1B0838 + 2 * v16 + 4) >> 16,
          *(int *)(2 * v16 + dword_1B0838 + 2) >> 16,
          *(int *)(dword_1B0838 + 2 * v16 + 4) >> 16,
          *(int *)(2 * v16 + dword_1B0838 + 6) >> 16,
          word_1844B6);
        sub_12B65C();
      }
    }
  }
  return sub_128AB6(v22, SHIWORD(v0), v0, v23);
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
// 1B0704: using guessed type char byte_1B0704;
// 1B0714: using guessed type char byte_1B0714;
// 1B0838: using guessed type int dword_1B0838;
// 1B3E0E: using guessed type int16_t word_1B3E0E;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (001203E4) --------------------------------------------------------
int sub_1203E4()
{
  int16_t i; // [esp+0h] [ebp-4h]

  for ( i = 0; byte_1B071C[i] && i < *(int16_t *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 44); ++i )
    ;
  if ( i && byte_1B071B[i] == 95 )
    --i;
  byte_1B071C[i] = 0;
  return strcpy(*(_DWORD *)((char *)off_184480 + 55 * (dword_1844CE >> 16) + 24), byte_1B071C);
}
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184480: using guessed type _UNKNOWN *off_184480;
// 1844CE: using guessed type int dword_1844CE;


//----- (00120486) --------------------------------------------------------
int16_t sub_120486(int a1)
{
  int16_t result; // ax
  int v2; // eax
  int v3; // eax
  int v5; // [esp+4h] [ebp-8h]
  _BOOL1 v6; // [esp+8h] [ebp-4h]

  v6 = 0;
  v5 = 0;
  do
    result = sub_124075();
  while ( result );
  if ( a1 )
  {
    while ( !v6 )
    {
      LOBYTE(v3) = sub_12C392();
      v6 = v3 != 0;
      if ( sub_124075() )
        v6 = 1;
      sub_119325();
      result = ++v5;
      if ( v5 == a1 )
        v6 = 1;
    }
  }
  else
  {
    while ( !v6 )
    {
      LOBYTE(v2) = sub_12C392();
      v6 = v2 != 0;
      if ( sub_124075() )
        v6 = 1;
      result = sub_119325();
    }
  }
  return result;
}
// 1204CB: variable 'v2' is possibly undefined
// 1204F5: variable 'v3' is possibly undefined


//----- (00120526) --------------------------------------------------------
int sub_120526(int a1)
{
  _BYTE *v3; // [esp+4h] [ebp-4h]
  _BYTE *v4; // [esp+4h] [ebp-4h]

  if ( dword_184514 )
  {
    nfree(dword_184514);
    dword_184514 = 0;
    v3 = sub_126ABD(a1, 0);
  }
  else
  {
    v3 = sub_126ABD(a1, 0);
    dword_1B3E78 = (int)PoolAlloc_110B89(12644, 0);
  }
  dword_184514 = (int)v3;
  sub_12779E(byte_1BA318, v3, 0x40u);
  v4 = v3 + 64;
  sub_12779E(byte_1B3E7C, v4, 0x235Cu);
  dword_1B3E74 = (int)(v4 + 9052);
  return strcpy(&unk_1B3E20, a1);
}
// 13CAF6: using guessed type int nfree(_DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184514: using guessed type int dword_184514;
// 1B3E74: using guessed type int dword_1B3E74;
// 1B3E78: using guessed type int dword_1B3E78;


//----- (001205E6) --------------------------------------------------------
int sub_1205E6( int a1, int a2, int a3)
{
  _DWORD *v4; // [esp+2Ch] [ebp-10h]

  v4 = sub_126AFD((int)&unk_1B3E20, (int16_t)(a1 + 1), dword_1B3E78);
  sub_12779E(&byte_1BB358[4 * a2], &v4[a2], 4 * (a3 - a2) + 4);
  dword_1BB900 = (int)(v4 + 256);
  return sub_1318D4(a2, a3);
}
// 1B3E78: using guessed type int dword_1B3E78;
// 1BB900: using guessed type int dword_1BB900;


//----- (0012066F) --------------------------------------------------------
int sub_12066F(int a1)
{
  int v1; // eax
  int v3; // [esp+0h] [ebp-18h]
  int16_t v4; // [esp+4h] [ebp-14h]
  int v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+10h] [ebp-8h]

  v3 = a1;
  v4 = 0;
  v5 = 0;
  LOWORD(a1) = word_1B3EA6;
  v6 = a1;
  while ( *(_BYTE *)(v3 + v4) && *(_BYTE *)(v3 + v4) != 21 )
  {
    if ( *(uint8_t *)(v3 + v4) >= 0x20u )
    {
      v1 = (uint8_t)byte_1B3EA8[*(uint8_t *)(v3 + v4)];
      BYTE1(v1) = 0;
      v5 += v6 + v1;
    }
    ++v4;
  }
  return v5;
}
// 1B3EA6: using guessed type int16_t word_1B3EA6;


//----- (00120705) --------------------------------------------------------
int16_t sub_120705(int a1, int a2)
{
  int16_t result; // ax
  int i; // [esp+8h] [ebp-4h]
  int j; // [esp+8h] [ebp-4h]

  HIWORD(dword_1B61E4) = a1;
  LOWORD(dword_1B61E4) = a2;
  for ( i = 0; i < 8; ++i )
  {
    byte_1B3E88[i] = byte_1844EC[2 * a2];
    byte_1B3E7C[i] = byte_1844EC[2 * a2];
  }
  word_1B3EA0 = word_1B43A8[a1];
  word_1B3E86 = 0;
  word_1B3EA4 = word_1B43C8[a1];
  word_1B3EA6 = word_1B43B8[a1];
  HIWORD(dword_1B3E82) = word_1B3EA0;
  result = word_1B3EA4 + word_1B3EA0;
  word_1B3EA2 = word_1B3EA4 + word_1B3EA0;
  for ( j = 0; j < 255; ++j )
  {
    byte_1B3EA8[j] = byte_1B43D8[256 * a1 + j];
    dword_1B3FA8[j] = dword_1B49D8[256 * a1 + j];
    result = j;
  }
  return result;
}
// 1B3E82: using guessed type int dword_1B3E82;
// 1B3E86: using guessed type int16_t word_1B3E86;
// 1B3EA0: using guessed type int16_t word_1B3EA0;
// 1B3EA2: using guessed type int16_t word_1B3EA2;
// 1B3EA4: using guessed type int16_t word_1B3EA4;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1B3FA8: using guessed type int dword_1B3FA8[256];
// 1B43A8: using guessed type int16_t word_1B43A8[8];
// 1B43B8: using guessed type int16_t word_1B43B8[];
// 1B43C8: using guessed type int16_t word_1B43C8[8];
// 1B49D8: using guessed type int dword_1B49D8[406];
// 1B61E4: using guessed type int dword_1B61E4;


//----- (00120940) --------------------------------------------------------
int16_t sub_120940(int a1, int a2)
{
  int16_t result; // ax
  int i; // [esp+8h] [ebp-4h]
  int j; // [esp+8h] [ebp-4h]

  HIWORD(dword_1B61E4) = a1;
  for ( i = 0; i < 8; ++i )
  {
    byte_1B3E88[i] = byte_1BC79C[*(uint8_t *)(i + a2)];
    byte_1B3E7C[i] = byte_1BC79C[*(uint8_t *)(i + a2)];
    byte_1B61D8[i] = byte_1BC79C[*(uint8_t *)(i + a2)];
  }
  word_1B3EA0 = word_1B43A8[a1];
  HIWORD(dword_1B3E82) = word_1B43A8[a1];
  word_1B3E86 = 0;
  word_1B3EA4 = word_1B43C8[a1];
  word_1B3EA6 = word_1B43B8[a1];
  result = word_1B3EA4 + HIWORD(dword_1B3E82);
  word_1B3EA2 = word_1B3EA4 + HIWORD(dword_1B3E82);
  for ( j = 0; j < 255; ++j )
  {
    byte_1B3EA8[j] = byte_1B43D8[256 * a1 + j];
    dword_1B3FA8[j] = dword_1B49D8[256 * a1 + j];
    result = j;
  }
  return result;
}
// 1B3E82: using guessed type int dword_1B3E82;
// 1B3E86: using guessed type int16_t word_1B3E86;
// 1B3EA0: using guessed type int16_t word_1B3EA0;
// 1B3EA2: using guessed type int16_t word_1B3EA2;
// 1B3EA4: using guessed type int16_t word_1B3EA4;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1B3FA8: using guessed type int dword_1B3FA8[256];
// 1B43A8: using guessed type int16_t word_1B43A8[8];
// 1B43B8: using guessed type int16_t word_1B43B8[];
// 1B43C8: using guessed type int16_t word_1B43C8[8];
// 1B49D8: using guessed type int dword_1B49D8[406];
// 1B61E4: using guessed type int dword_1B61E4;


//----- (00120BB5) --------------------------------------------------------
int sub_120BB5(int a1, int a2)
{
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    byte_1B3E88[i] = *(_BYTE *)(i + a2);
    byte_1B3E7C[i] = *(_BYTE *)(i + a2);
    byte_1B61D8[i] = *(_BYTE *)(i + a2);
  }
  HIWORD(dword_1B61E4) = a1;
  word_1B3EA0 = word_1B43A8[a1];
  HIWORD(dword_1B3E82) = word_1B43A8[a1];
  word_1B3E86 = 0;
  word_1B3EA4 = word_1B43C8[a1];
  word_1B3EA6 = word_1B43B8[a1];
  word_1B3EA2 = word_1B3EA4 + HIWORD(dword_1B3E82);
  memcpy(byte_1B3EA8, &byte_1B43D8[256 * a1], 256);
  return memcpy(dword_1B3FA8, &dword_1B49D8[256 * a1], sizeof(dword_1B3FA8));
}
// 13F35A: using guessed type int memcpy(_DWORD, _DWORD, _DWORD);
// 1B3E82: using guessed type int dword_1B3E82;
// 1B3E86: using guessed type int16_t word_1B3E86;
// 1B3EA0: using guessed type int16_t word_1B3EA0;
// 1B3EA2: using guessed type int16_t word_1B3EA2;
// 1B3EA4: using guessed type int16_t word_1B3EA4;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1B3FA8: using guessed type int dword_1B3FA8[256];
// 1B43A8: using guessed type int16_t word_1B43A8[8];
// 1B43B8: using guessed type int16_t word_1B43B8[];
// 1B43C8: using guessed type int16_t word_1B43C8[8];
// 1B49D8: using guessed type int dword_1B49D8[406];
// 1B61E4: using guessed type int dword_1B61E4;


//----- (00120CCB) --------------------------------------------------------
int sub_120CCB( int a1, int a2)
{
  int result; // eax

  result = sub_120BB5(a1, a2);
  word_1B3E86 = 1;
  return result;
}
// 1B3E86: using guessed type int16_t word_1B3E86;


//----- (00120D05) --------------------------------------------------------
int sub_120D05( int a1, int a2)
{
  int result; // eax

  result = sub_120BB5(a1, a2);
  word_1B3E86 = 2;
  return result;
}
// 1B3E86: using guessed type int16_t word_1B3E86;


//----- (00120D79) --------------------------------------------------------
int sub_120D79( int a1, int a2)
{
  int result; // eax

  result = sub_120BB5(a1, a2);
  word_1B3E86 = 4;
  return result;
}
// 1B3E86: using guessed type int16_t word_1B3E86;


//----- (00120DB3) --------------------------------------------------------
int sub_120DB3( int a1, int a2)
{
  int result; // eax

  result = sub_120BB5(a1, a2);
  word_1B3E86 = 5;
  return result;
}
// 1B3E86: using guessed type int16_t word_1B3E86;


//----- (00120DED) --------------------------------------------------------
int sub_120DED( int a1, int a2)
{
  int result; // eax

  word_18450C = a1;
  result = a2;
  word_18450E = a2;
  return result;
}
// 18450C: using guessed type int16_t word_18450C;
// 18450E: using guessed type int16_t word_18450E;


//----- (00120E24) --------------------------------------------------------
int sub_120E24(int a1)
{
  int result; // eax
  int v2; // [esp+0h] [ebp-4h]

  v2 = a1;
  word_1B3EA2 = a1;
  LOWORD(a1) = word_1B3EA0;
  result = v2 + a1;
  HIWORD(dword_1B3E82) = result;
  return result;
}
// 1B3E82: using guessed type int dword_1B3E82;
// 1B3EA0: using guessed type int16_t word_1B3EA0;
// 1B3EA2: using guessed type int16_t word_1B3EA2;


//----- (00120E60) --------------------------------------------------------
char sub_120E60( int result)
{
  byte_1B3EC8 = result;
  return result;
}
// 1B3EC8: using guessed type char byte_1B3EC8;


//----- (00120E8C) --------------------------------------------------------
int16_t sub_120E8C( int result)
{
  word_1B3EA6 = result;
  return result;
}
// 1B3EA6: using guessed type int16_t word_1B3EA6;


//----- (00120EB9) --------------------------------------------------------
int sub_120EB9(int result)
{
  int v1; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  v1 = result;
  for ( i = 0; i < 8; ++i )
  {
    byte_1B3E90[i] = *(_BYTE *)(i + v1);
    result = i;
  }
  return result;
}


//----- (00120F07) --------------------------------------------------------
int sub_120F07(int result)
{
  int v1; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  v1 = result;
  for ( i = 0; i < 8; ++i )
  {
    byte_1B3E98[i] = *(_BYTE *)(i + v1);
    result = i;
  }
  return result;
}


//----- (00120F55) --------------------------------------------------------
char sub_120F55( int result)
{
  byte_1B3E88[0] = result;
  byte_1B3E90[0] = result;
  byte_1B3E98[0] = result;
  byte_1B3E7C[0] = result;
  return result;
}


//----- (0012102B) --------------------------------------------------------
int sub_12102B(int a1, int a2, int a3, int a4)
{
  _BYTE v5[12]; // [esp+0h] [ebp-1Ch] BYREF
  int v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]

  v8 = a1;
  v7 = a2;
  v6 = a3;
  itoa(a3, v5, 10, a4);
  return sub_1212B3(v8, v7, (int)v5);
}
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (001210B7) --------------------------------------------------------
int sub_1210B7( int a1, int a2, int a3)
{
  int16_t v3; // ax

  v3 = sub_12066F(a3);
  return sub_1212B3(a1 - (v3 - 1), a2, a3);
}
// 1210B7: could not find valid save-restore pair for ebx


//----- (001210FD) --------------------------------------------------------
int sub_1210FD( int a1, int a2, int a3)
{
  int16_t v3; // ax

  v3 = sub_12066F(a3);
  return sub_1212B3(a1 - v3 / 2, a2, a3);
}
// 1210FD: could not find valid save-restore pair for ebx


//----- (00121153) --------------------------------------------------------
int sub_121153(int a1, int a2, int a3, int a4)
{
  _BYTE v5[12]; // [esp+0h] [ebp-1Ch] BYREF
  int v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]

  v8 = a1;
  v7 = a2;
  v6 = a3;
  itoa(a3, v5, 10, a4);
  return sub_1210B7(v8, v7, (int)v5);
}
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (00121199) --------------------------------------------------------
int sub_121199(int a1, int a2, int a3, int a4)
{
  _BYTE v5[12]; // [esp+0h] [ebp-1Ch] BYREF
  int v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]

  v8 = a1;
  v7 = a2;
  v6 = a3;
  itoa(a3, v5, 10, a4);
  return sub_1210FD(v8, v7, (int)v5);
}
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (0012126B) --------------------------------------------------------
int sub_12126B( int a1, int a2, int a3, int a4)
{
  int16_t v5; // [esp+4h] [ebp-Ch]

  v5 = a4;
  if ( a4 < 0 )
    v5 = 0;
  return sub_1212EB(a1, a2, a3, v5);
}
// 12126B: could not find valid save-restore pair for ebx


//----- (001212B3) --------------------------------------------------------
int sub_1212B3( int a1, int a2, int a3)
{
  return sub_1212EB(a1, a2, a3, 0);
}


//----- (001212EB) --------------------------------------------------------
int sub_1212EB( int a1, int a2, int a3, int a4)
{
  int result; // eax
  int i; // [esp+0h] [ebp-30h]
  int j; // [esp+0h] [ebp-30h]
  int v7; // [esp+4h] [ebp-2Ch]
  int v8; // [esp+Ch] [ebp-24h]
  int v9; // [esp+10h] [ebp-20h]
  int v10; // [esp+18h] [ebp-18h]
  int v11; // [esp+1Ch] [ebp-14h]
  int v12; // [esp+20h] [ebp-10h]

  v9 = *(int *)((char *)&dword_1B3E82 + 2) >> 16;
  v7 = 0;
  if ( *(int *)((char *)&dword_1B3E82 + 2) >> 16 )
  {
    for ( i = 1; i < 8; ++i )
      byte_1B3E7C[i] = word_18450C;
    byte_1B3E7C[0] = word_18450E;
    LOWORD(dword_184510) = 1;
    if ( v9 == 3 || v9 == 5 )
      v7 = 2;
    else
      v7 = 1;
    if ( v9 != 2 )
    {
      if ( *(int *)((char *)&off_1845D4 + 2) >> 16 == 1 )
      {
        sub_122309(a1 + 1, a2 + 1, a3, 0, a4);
        sub_122309(a1, a2 + 1, a3, 0, a4);
        sub_122309(a1 + 1, a2, a3, 0, a4);
      }
      else
      {
        sub_121814(a1 + 1, a2 + 1, a3, 0, a4);
        sub_121814(a1, a2 + 1, a3, 0, a4);
        sub_121814(a1 + 1, a2, a3, 0, a4);
      }
    }
    if ( v9 != 1 && v9 != 3 )
    {
      if ( *(int *)((char *)&off_1845D4 + 2) >> 16 == 1 )
      {
        sub_122309(a1 - 1, a2, a3, 0, a4);
        sub_122309(a1 - 1, a2 - 1, a3, 0, a4);
        sub_122309(a1, a2 - 1, a3, 0, a4);
      }
      else
      {
        sub_121814(a1 - 1, a2, a3, 0, a4);
        sub_121814(a1 - 1, a2 - 1, a3, 0, a4);
        sub_121814(a1, a2 - 1, a3, 0, a4);
      }
    }
    if ( v9 == 3 || v9 == 5 )
    {
      if ( *(int *)((char *)&off_1845D4 + 2) >> 16 == 1 )
      {
        sub_122309(a1 + 2, a2 + 2, a3, 0, a4);
        sub_122309(a1 + 1, a2 + 2, a3, 0, a4);
        sub_122309(a1 + 2, a2 + 1, a3, 0, a4);
      }
      else
      {
        sub_121814(a1 + 2, a2 + 2, a3, 0, a4);
        sub_121814(a1 + 1, a2 + 2, a3, 0, a4);
        sub_121814(a1 + 2, a2 + 1, a3, 0, a4);
      }
    }
    if ( v9 > 3 )
    {
      if ( *(int *)((char *)&off_1845D4 + 2) >> 16 == 1 )
      {
        sub_122309(a1 + 1, a2 - 1, a3, 0, a4);
        sub_122309(a1 - 1, a2 + 1, a3, 0, a4);
      }
      else
      {
        sub_121814(a1 + 1, a2 - 1, a3, 0, a4);
        sub_121814(a1 - 1, a2 + 1, a3, 0, a4);
      }
    }
    if ( v9 == 5 )
    {
      if ( *(int *)((char *)&off_1845D4 + 2) >> 16 == 1 )
      {
        sub_122309(a1 + 2, a2, a3, 0, a4);
        sub_122309(a1, a2 + 2, a3, 0, a4);
      }
      else
      {
        sub_121814(a1 + 2, a2, a3, 0, a4);
        sub_121814(a1, a2 + 2, a3, 0, a4);
      }
    }
    for ( j = 0; j < 8; ++j )
      byte_1B3E7C[j] = byte_1B3E88[j];
  }
  LOWORD(dword_184510) = 0;
  if ( *(int *)((char *)&off_1845D4 + 2) >> 16 == 1 )
    sub_122309(a1, a2, a3, 1, a4);
  else
    sub_121814(a1, a2, a3, 1, a4);
  v12 = a1 - v7;
  v10 = a2 - v7;
  if ( a4 )
    v8 = a4 + a1 + v7;
  else
    v8 = (int16_t)sub_12066F(a3) + a1 + v7;
  v11 = (dword_1B3E82 >> 16) + a2 + v7;
  if ( v12 < 0 )
    v12 = 0;
  if ( v10 < 0 )
    v10 = 0;
  if ( v8 >= *(int *)((char *)&dword_184532 + 2) )
    v8 = *(int *)((char *)&dword_184532 + 2) - 1;
  result = (dword_1B3E82 >> 16) + a2 + v7;
  if ( v11 >= *(int *)((char *)&dword_184536 + 2) )
  {
    result = *(int *)((char *)&dword_184536 + 2) - 1;
    v11 = *(int *)((char *)&dword_184536 + 2) - 1;
  }
  if ( dword_1BBA28 >= 2 )
    return sub_138CEE(v12, v10, v8, v11);
  return result;
}
// 1212EB: could not find valid save-restore pair for ebx
// 18450C: using guessed type int16_t word_18450C;
// 18450E: using guessed type int16_t word_18450E;
// 184510: using guessed type int dword_184510;
// 184532: using guessed type int dword_184532;
// 184536: using guessed type int dword_184536;
// 1845D4: using guessed type char *;
// 1B3E82: using guessed type int dword_1B3E82;
// 1BBA28: using guessed type int dword_1BBA28;


//----- (00121814) --------------------------------------------------------
unsigned int sub_121814( int a1, int a2, int a3, int a4, int a5)
{
  unsigned int v5; // eax
  unsigned int v7; // [esp+4h] [ebp-38h]
  int v8; // [esp+Ch] [ebp-30h]
  int v9; // [esp+10h] [ebp-2Ch]
  int v10; // [esp+14h] [ebp-28h]
  int v11; // [esp+1Ch] [ebp-20h]
  int v12; // [esp+20h] [ebp-1Ch]
  int v13; // [esp+24h] [ebp-18h]

  v10 = 0;
  LOWORD(dword_1B61E8) = a1;
  HIWORD(dword_1B61E0) = a2;
  if ( (_WORD)a5 )
  {
    v8 = 0;
    v9 = 0;
    v12 = 0;
    v13 = 0;
    while ( *(_BYTE *)(v12 + a3)
         && *(_BYTE *)(v12 + a3) != 13
         && *(_BYTE *)(v12 + a3) != 20
         && *(_BYTE *)(v12 + a3) != 25
         && *(_BYTE *)(v12 + a3) != 21
         && *(_BYTE *)(v12 + a3) != 29 )
    {
      if ( *(_BYTE *)(v12 + a3) == 32 )
        ++v13;
      ++v12;
    }
    if ( !v13 )
      a5 = 0;
    a5 -= sub_12066F(a3);
    if ( (int16_t)a5 > 0 )
    {
      v9 = (int16_t)a5 % v13;
      v11 = (int16_t)a5 / v13;
    }
    else
    {
      LOWORD(a5) = 0;
    }
  }
  while ( 1 )
  {
    v5 = *(uint8_t *)(v10 + a3);
    v7 = v5;
    if ( !*(_BYTE *)(v10 + a3) )
      break;
    if ( v5 >= 8 )
    {
      if ( v5 <= 8 )
        goto LABEL_66;
      if ( v5 < 0x15 )
      {
        if ( v5 >= 0xD && (v5 <= 0xD || v5 == 20) )
        {
          HIWORD(dword_1B61E0) += word_1B3EA2;
          LOWORD(dword_1B61E8) = a1;
          goto LABEL_66;
        }
      }
      else
      {
        if ( v5 <= 0x15 )
        {
          LOWORD(v5) = dword_1B61E8;
          return v5;
        }
        if ( v5 >= 0x19 && (v5 <= 0x19 || v5 == 29) )
        {
          LOWORD(dword_1B61E8) = *(uint8_t *)(v10 + a3 + 1) + a1;
          ++v10;
          goto LABEL_66;
        }
      }
LABEL_57:
      if ( (_WORD)dword_184510 )
        LOWORD(dword_1B61E8) = sub_121E85(*(int *)((char *)&dword_1B61E4 + 2) >> 16, SHIWORD(dword_1B61E0), v5);
      else
        LOWORD(dword_1B61E8) = sub_121DEB(*(int *)((char *)&dword_1B61E4 + 2) >> 16, SHIWORD(dword_1B61E0), v5);
      if ( (_WORD)a5 && v7 == 32 )
      {
        LOWORD(dword_1B61E8) = v11 + dword_1B61E8;
        if ( v8 < v9 )
          LOWORD(dword_1B61E8) = dword_1B61E8 + 1;
        ++v8;
      }
      goto LABEL_66;
    }
    if ( v5 < 2 )
    {
      if ( v5 != 1 )
        goto LABEL_57;
      if ( a4 )
        sub_121B40();
    }
    else if ( v5 <= 2 )
    {
      if ( a4 )
        sub_121B8C();
    }
    else if ( v5 <= 3 )
    {
      if ( a4 )
        sub_121BD8();
    }
    else
    {
      if ( v5 != 4 )
        goto LABEL_57;
      if ( a4 )
        sub_121B8C();
    }
LABEL_66:
    ++v10;
  }
  LOWORD(v5) = dword_1B61E8;
  return v5;
}
// 121AE3: variable 'v11' is possibly undefined
// 121AF0: variable 'v8' is possibly undefined
// 121AF0: variable 'v9' is possibly undefined
// 184510: using guessed type int dword_184510;
// 1B3EA2: using guessed type int16_t word_1B3EA2;
// 1B61E0: using guessed type int dword_1B61E0;
// 1B61E4: using guessed type int dword_1B61E4;
// 1B61E8: using guessed type int dword_1B61E8;


//----- (00121B40) --------------------------------------------------------
int sub_121B40()
{
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    byte_1B3E7C[i] = byte_1B3E88[i];
    result = i;
  }
  return result;
}


//----- (00121B8C) --------------------------------------------------------
int sub_121B8C()
{
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    byte_1B3E7C[i] = byte_1B3E90[i];
    result = i;
  }
  return result;
}


//----- (00121BD8) --------------------------------------------------------
int sub_121BD8()
{
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    byte_1B3E7C[i] = byte_1B3E98[i];
    result = i;
  }
  return result;
}


//----- (00121C24) --------------------------------------------------------
int16_t sub_121C24(int a1, int a2, int a3, int a4)
{
  _BYTE v5[16]; // [esp+0h] [ebp-30h] BYREF
  int v6; // [esp+10h] [ebp-20h]
  int v7; // [esp+14h] [ebp-1Ch]
  int v8; // [esp+18h] [ebp-18h]
  int v9; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  int v11; // [esp+24h] [ebp-Ch]
  int v12; // [esp+28h] [ebp-8h]
  int v13; // [esp+2Ch] [ebp-4h]

  v9 = a1;
  v6 = a2;
  v7 = a3;
  v8 = a4;
  for ( i = 0; *(_BYTE *)(i + v8); ++i )
    ;
  v13 = dword_1B61E4 >> 16;
  v12 = *(int *)((char *)&dword_1B61E0 + 2) >> 16;
  sub_120705(dword_1B61E8 >> 16, 15);
  sub_121F7B(v9, v6, v8);
  v11 = ((int16_t)sub_12066F(v8) + 2) / 10;
  itoa(v7, v5, 10, a4);
  sub_121F7B(v11 + v9 + 1, v6, (int)v5);
  return sub_120705(v13, v12);
}
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 1B61E0: using guessed type int dword_1B61E0;
// 1B61E4: using guessed type int dword_1B61E4;
// 1B61E8: using guessed type int dword_1B61E8;


//----- (00121CE5) --------------------------------------------------------
int16_t sub_121CE5( int a1, int a2, int a3)
{
  return sub_121F7B(a1, a2, a3);
}


//----- (00121D19) --------------------------------------------------------
int16_t sub_121D19(int a1, int a2, int a3, int a4)
{
  _BYTE v5[16]; // [esp+0h] [ebp-1Ch] BYREF
  int v6; // [esp+10h] [ebp-Ch]
  int v7; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]

  v6 = a1;
  v8 = a2;
  v7 = a3;
  itoa(a3, v5, 10, a4);
  return sub_121F7B(v6, v8, (int)v5);
}
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (00121DEB) --------------------------------------------------------
int sub_121DEB(int a1, int a2, unsigned int a3)
{
  int64_t v3; // rax
  int64_t v5; // [esp+0h] [ebp-38h] - dest ptr (low dword) : src glyph ptr (high dword)
  int v6; // [esp+8h] [ebp-30h]
  int v7; // [esp+Ch] [ebp-2Ch]

  // PORT: Hex-Rays dropped the HIDWORD(v5)/v6/v7 setup entirely (it failed to see
  // that sub_1449CC's int64_t a1 is really an EDX:EAX register pair - dest ptr in
  // EAX, source (compressed glyph) ptr in EDX). Reconstructed from
  // Debug/diss/Orion2.exe.asm (sub_121DEB @ 0x121DEB): EAX = dword_1BB904
  // (backbuffer base) + dest offset; EDX = dword_1B3E74 (font glyph-data base) +
  // dword_1B3FA8[a3] (per-glyph offset table); ECX = word_1B3EA0; EBX =
  // &byte_1B3E7C. Without this the source pointer was uninitialized garbage,
  // crashing sub_1449CC's byte-stream read on the very first character drawn.
  LODWORD(v5) = dword_1BB904 + (int16_t)a1 + a2 * *(int *)((char *)&dword_184532 + 2);
  HIDWORD(v5) = dword_1B3E74 + dword_1B3FA8[a3];
  // a2 = EBX = &byte_1B3E7C (color/pattern lookup table, used as [run+a2-1]);
  // a3 = ECX = word_1B3EA0 (glyph row count - drives the x86 `loop` instruction,
  // which Hex-Rays turned into the explicit `--a3; while(a3)` counter). Verified
  // against Debug/diss/Orion2.exe.asm (sub_1449CC @ 0x1449CC): `ebx` feeds the
  // `mov al,[eax+ebx-1]` lookup while `ecx` is consumed only by `loop`.
  v6 = (int)byte_1B3E7C;
  v7 = word_1B3EA0;
  v3 = sub_1449CC(v5, v6, v7);
  WORD2(v3) = word_1B3EA6;
  return a1 + (uint8_t)byte_1B3EA8[a3] + HIDWORD(v3);
}
// 121E54: variable 'v5' is possibly undefined
// 121E54: variable 'v6' is possibly undefined
// 121E54: variable 'v7' is possibly undefined
// 184532: using guessed type int dword_184532;
// 1B3E74: using guessed type int dword_1B3E74;
// 1B3EA0: using guessed type int16_t word_1B3EA0;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1BB904: using guessed type int dword_1BB904;


//----- (00121E85) --------------------------------------------------------
int sub_121E85(int a1, int a2, unsigned int a3)
{
  int64_t v3; // rax
  int64_t v5; // [esp+0h] [ebp-38h] - dest ptr (low dword) : src glyph ptr (high dword)
  int v6; // [esp+8h] [ebp-30h]
  int v7; // [esp+Ch] [ebp-2Ch]

  // PORT: same missing-HIDWORD(v5) bug as sub_121DEB (see comment there);
  // verified identical in Debug/diss/Orion2.exe.asm (sub_121E85 @ 0x121E85).
  LODWORD(v5) = dword_1BB904 + (int16_t)a1 + a2 * *(int *)((char *)&dword_184532 + 2);
  HIDWORD(v5) = dword_1B3E74 + dword_1B3FA8[a3];
  // a2 = &byte_1B3E7C (color table), a3 = word_1B3EA0 (row count) - see sub_121DEB.
  v6 = (int)byte_1B3E7C;
  v7 = word_1B3EA0;
  v3 = sub_144A06(v5, v6, v7);
  WORD2(v3) = word_1B3EA6;
  return a1 + (uint8_t)byte_1B3EA8[a3] + HIDWORD(v3);
}
// 121EEE: variable 'v5' is possibly undefined
// 121EEE: variable 'v6' is possibly undefined
// 121EEE: variable 'v7' is possibly undefined
// 184532: using guessed type int dword_184532;
// 1B3E74: using guessed type int dword_1B3E74;
// 1B3EA0: using guessed type int16_t word_1B3EA0;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1BB904: using guessed type int dword_1BB904;


//----- (00121F7B) --------------------------------------------------------
int16_t sub_121F7B( int a1, int a2, int a3)
{
  int16_t result; // ax
  int v4; // ecx
  int16_t v5; // ax
  int v6; // ecx
  int16_t v7; // ax
  int v8; // [esp-4h] [ebp-34h]
  int16_t v10; // [esp+0h] [ebp-30h]
  int v11; // [esp+4h] [ebp-2Ch]
  int v12; // [esp+Ch] [ebp-24h]
  int v13; // [esp+10h] [ebp-20h]
  int v14; // [esp+18h] [ebp-18h]
  int v15; // [esp+1Ch] [ebp-14h]
  int v16; // [esp+20h] [ebp-10h]
  int v17; // [esp+24h] [ebp-Ch]
  int v18; // [esp+2Ch] [ebp-4h]

  result = IsMemPoolReady_110B5C();
  if ( !result )
  {
    byte_1B922A = 1;
    v18 = dword_1BBA28;
    dword_1BBA28 = 0;
    v10 = (qword_184530 >> 32) / 80 * a1;
    v11 = screenHeight_184538 / 25 * a2;
    v14 = dword_1BBA4A >> 16;
    v15 = dword_1BBA4E >> 16;
    v16 = *(int *)((char *)&dword_1BBA4A + 2) >> 16;
    v17 = *(int *)((char *)&dword_1BBA4E + 2) >> 16;
    sub_128AB6(0, 0, 1000, 1000);
    v13 = dword_1B61E4 >> 16;
    v12 = *(int *)((char *)&dword_1B61E0 + 2) >> 16;
    sub_120705(dword_1B61E8 >> 16, 0);
    sub_124D41();
    v8 = dword_184510 >> 16;
    v4 = (int16_t)(HIWORD(dword_1B3E82) + v11);
    v5 = sub_12066F(a3);
    sub_128C32(v10, (int16_t)v11, (int16_t)(v10 + v5), v4, v8);
    sub_120705(dword_1B61E8 >> 16, 0);
    sub_122119();
    sub_1212B3(v10, v11, a3);
    v6 = (int16_t)(HIWORD(dword_1B3E82) + v11);
    v7 = sub_12066F(a3);
    sub_124E80(v10, (int16_t)v11, (int16_t)(v10 + v7), v6);
    sub_128AB6(v14, v15, v16, (int16_t)v17);
    sub_120705(v13, v12);
    result = v18;
    dword_1BBA28 = v18;
    byte_1B922A = 0;
  }
  return result;
}
// 184510: using guessed type int dword_184510;
// 184530: using guessed type int64_t;
// 1B3E82: using guessed type int dword_1B3E82;
// 1B61E0: using guessed type int dword_1B61E0;
// 1B61E4: using guessed type int dword_1B61E4;
// 1B61E8: using guessed type int dword_1B61E8;
// 1B922A: using guessed type char byte_1B922A;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;


//----- (00122119) --------------------------------------------------------
int sub_122119()
{
  int result; // eax
  int v1; // [esp+0h] [ebp-10h]
  int i; // [esp+8h] [ebp-8h]
  int j; // [esp+8h] [ebp-8h]
  char v4; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v4 = 0;
  for ( i = 0; i < 256; ++i )
  {
    if ( (uint8_t)byte_1BB35B[4 * i] + (uint8_t)byte_1BB35A[4 * i] + (uint8_t)byte_1BB359[4 * i] > v1 )
    {
      v4 = i;
      v1 = (uint8_t)byte_1BB35B[4 * i]
         + (uint8_t)byte_1BB35A[4 * i]
         + (uint8_t)byte_1BB359[4 * i];
    }
    result = i;
  }
  for ( j = 0; j < 8; ++j )
  {
    byte_1B3E7C[j] = v4;
    result = j;
  }
  return result;
}


//----- (00122201) --------------------------------------------------------
int16_t sub_122201()
{
  return HIWORD(dword_1B61E4);
}
// 1B61E4: using guessed type int dword_1B61E4;


//----- (0012222E) --------------------------------------------------------
char *sub_12222E()
{
  return byte_1B61D8;
}


//----- (00122259) --------------------------------------------------------
int16_t sub_122259()
{
  return HIWORD(dword_1B3E82);
}
// 1B3E82: using guessed type int dword_1B3E82;


//----- (00122286) --------------------------------------------------------
int16_t sub_122286()
{
  return word_1B3EA4;
}
// 1B3EA4: using guessed type int16_t word_1B3EA4;


//----- (001222B3) --------------------------------------------------------
char *sub_1222B3()
{
  return byte_1B3E90;
}


//----- (001222DE) --------------------------------------------------------
char *sub_1222DE()
{
  return byte_1B3E98;
}


//----- (00122309) --------------------------------------------------------
int sub_122309( int a1, int a2, int a3, int a4, int a5)
{
  unsigned int v5; // eax
  unsigned int v7; // [esp+4h] [ebp-3Ch]
  int v8; // [esp+Ch] [ebp-34h]
  int v9; // [esp+10h] [ebp-30h]
  int v10; // [esp+14h] [ebp-2Ch]
  int v11; // [esp+20h] [ebp-20h]
  int v12; // [esp+24h] [ebp-1Ch]
  int v13; // [esp+28h] [ebp-18h]

  if ( (int16_t)dword_1BBA52 >= a2 && a2 + (dword_1B3E82 >> 16) >= dword_1BBA4E >> 16 )
  {
    v10 = 0;
    LOWORD(dword_1B61E8) = a1;
    HIWORD(dword_1B61E0) = a2;
    if ( (_WORD)a5 )
    {
      v8 = 0;
      v9 = 0;
      v12 = 0;
      v13 = 0;
      while ( *(_BYTE *)(v12 + a3)
           && *(_BYTE *)(v12 + a3) != 13
           && *(_BYTE *)(v12 + a3) != 20
           && *(_BYTE *)(v12 + a3) != 25
           && *(_BYTE *)(v12 + a3) != 21
           && *(_BYTE *)(v12 + a3) != 29 )
      {
        if ( *(_BYTE *)(v12 + a3) == 32 )
          ++v13;
        ++v12;
      }
      if ( !v13 )
        a5 = 0;
      a5 -= sub_12066F(a3);
      if ( (int16_t)a5 > 0 )
      {
        v9 = (int16_t)a5 % v13;
        v11 = (int16_t)a5 / v13;
      }
      else
      {
        LOWORD(a5) = 0;
      }
    }
    while ( 1 )
    {
      v5 = *(uint8_t *)(v10 + a3);
      v7 = v5;
      if ( !*(_BYTE *)(v10 + a3) )
      {
        LOWORD(v5) = dword_1B61E8;
        return v5;
      }
      if ( v5 >= 8 )
        break;
      if ( v5 < 2 )
      {
        if ( v5 != 1 )
          goto LABEL_60;
        if ( a4 )
          sub_121B40();
      }
      else if ( v5 <= 2 )
      {
        if ( a4 )
          sub_121B8C();
      }
      else if ( v5 <= 3 )
      {
        if ( a4 )
          sub_121BD8();
      }
      else
      {
        if ( v5 != 4 )
          goto LABEL_60;
        if ( a4 )
          sub_121B8C();
      }
LABEL_66:
      ++v10;
    }
    if ( v5 <= 8 )
      goto LABEL_66;
    if ( v5 < 0x15 )
    {
      if ( v5 >= 0xD && (v5 <= 0xD || v5 == 20) )
      {
        HIWORD(dword_1B61E0) += word_1B3EA2;
        LOWORD(dword_1B61E8) = a1;
        goto LABEL_66;
      }
    }
    else
    {
      if ( v5 <= 0x15 )
      {
        LOWORD(v5) = dword_1B61E8;
        return v5;
      }
      if ( v5 >= 0x19 && (v5 <= 0x19 || v5 == 29) )
      {
        LOWORD(dword_1B61E8) = *(uint8_t *)(v10 + a3 + 1) + a1;
        ++v10;
        goto LABEL_66;
      }
    }
LABEL_60:
    LOWORD(dword_1B61E8) = sub_12260F(*(int *)((char *)&dword_1B61E4 + 2) >> 16, SHIWORD(dword_1B61E0), v5);
    if ( (_WORD)a5 && v7 == 32 )
    {
      LOWORD(dword_1B61E8) = v11 + dword_1B61E8;
      if ( v8 < v9 )
        LOWORD(dword_1B61E8) = dword_1B61E8 + 1;
      ++v8;
    }
    goto LABEL_66;
  }
  return 1;
}
// 1225DA: variable 'v11' is possibly undefined
// 1225E7: variable 'v8' is possibly undefined
// 1225E7: variable 'v9' is possibly undefined
// 1B3E82: using guessed type int dword_1B3E82;
// 1B3EA2: using guessed type int16_t word_1B3EA2;
// 1B61E0: using guessed type int dword_1B61E0;
// 1B61E4: using guessed type int dword_1B61E4;
// 1B61E8: using guessed type int dword_1B61E8;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (0012260F) --------------------------------------------------------
int sub_12260F(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp+0h] [ebp-34h]
  int16_t v8; // [esp+4h] [ebp-30h]
  int16_t v9; // [esp+8h] [ebp-2Ch]
  int v10; // [esp+Ch] [ebp-28h]
  int v11; // [esp+14h] [ebp-20h]
  int v12; // [esp+18h] [ebp-1Ch]
  int16_t v14; // [esp+24h] [ebp-10h]
  int v15; // [esp+28h] [ebp-Ch]

  v7 = a1;
  v8 = a2;
  if ( a3 <= 0x80u )
  {
    v3 = (uint8_t)byte_1B3EA8[a3];
    v11 = v3;
    LOWORD(v3) = word_1B3EA6;
    v12 = v3;
    if ( (int16_t)v7 >= SHIWORD(dword_1BBA4A)
      && (int16_t)v11 + (int16_t)v7 <= *(int *)((char *)&dword_1BBA4A + 2) >> 16
      && a2 >= SHIWORD(dword_1BBA4E)
      && SHIWORD(dword_1B3E82) + a2 <= *(int *)((char *)&dword_1BBA4E + 2) >> 16 )
    {
      sub_121DEB((int16_t)v7, a2, a3);
    }
    else
    {
      v15 = v11 + v7 + v3;
      HIWORD(v3) = HIWORD(v7);
      if ( (int16_t)v7 >= SHIWORD(dword_1BBA4A) )
      {
        LOWORD(v10) = 0;
      }
      else
      {
        LOWORD(v3) = HIWORD(dword_1BBA4A);
        v10 = v3 - v7;
        v4 = v3 - v7;
        if ( (int16_t)v4 >= (int16_t)v11 )
          return v11 + v7 + v12;
        LOWORD(v4) = HIWORD(dword_1BBA4A);
        v7 = v4;
        v11 -= v10;
      }
      v5 = *(int *)((char *)&dword_1BBA4A + 2) >> 16;
      if ( (int16_t)v11 + (int16_t)v7 > *(int *)((char *)&dword_1BBA4A + 2) >> 16 )
      {
        LOWORD(v5) = dword_1BBA4E;
        v11 = v5 + 1 - v7;
        if ( (int16_t)v11 < 1 )
          return v15;
      }
      if ( a2 >= SHIWORD(dword_1BBA4E) )
      {
        v9 = 0;
      }
      else
      {
        v9 = HIWORD(dword_1BBA4E) - a2;
        v8 = HIWORD(dword_1BBA4E);
      }
      if ( SHIWORD(dword_1B3E82) + v8 <= *(int *)((char *)&dword_1BBA4E + 2) >> 16 )
        v14 = HIWORD(dword_1B3E82);
      else
        v14 = dword_1BBA52 + 1 - v8;
      sub_1227EC((int16_t)v7, v8, a3, v10, v11, v9, v14);
    }
    return v11 + v7 + v12;
  }
  return a1;
}
// 1B3E82: using guessed type int dword_1B3E82;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (001227EC) --------------------------------------------------------
int sub_1227EC(int a1, int a2, unsigned int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int v9; // [esp+0h] [ebp-40h]
  int i; // [esp+4h] [ebp-3Ch]
  int j; // [esp+4h] [ebp-3Ch]
  int v12; // [esp+14h] [ebp-2Ch]
  int v14; // [esp+28h] [ebp-18h]
  uint8_t k; // [esp+38h] [ebp-8h]
  int16_t v16; // [esp+58h] [ebp+18h]

  v9 = *(int *)((char *)&dword_184532 + 2) * a2 + (int16_t)a1 - a4;
  v7 = 4 * a3;
  LOWORD(v7) = *(_WORD *)((char *)dword_1B3FA8 + v7);
  v14 = v7;
  if ( a7 > word_1B3EA0 )
    a7 = word_1B3EA0;
  for ( i = 0; a6 > i; ++i )
  {
    while ( *(uint8_t *)((int16_t)v14 + dword_1B3E74) != 128 )
      ++v14;
    ++v14;
  }
  v16 = a7 - a6;
  for ( j = 0; v16 > j; ++j )
  {
    v12 = v9;
    for ( k = *(_BYTE *)((int16_t)v14 + dword_1B3E74); k != 128; k = *(_BYTE *)(dword_1B3E74 + (int16_t)v14) )
    {
      if ( k <= 0x80u )
      {
        if ( v12 >= a4 + v9 && v12 < a5 + a4 + v9 )
          *(_BYTE *)(v12 + dword_1BB904) = *((_BYTE *)&dword_1B3E78 + k + 3);
        ++v12;
      }
      else
      {
        v12 += k & 0x7F;
      }
      ++v14;
    }
    ++v14;
    v9 += *(int *)((char *)&dword_184532 + 2);
  }
  return a1 + (uint8_t)byte_1B3EA8[a3];
}
// 184532: using guessed type int dword_184532;
// 1B3E74: using guessed type int dword_1B3E74;
// 1B3E78: using guessed type int dword_1B3E78;
// 1B3EA0: using guessed type int16_t word_1B3EA0;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1B3FA8: using guessed type int dword_1B3FA8[256];
// 1BB904: using guessed type int dword_1BB904;


//----- (0012297B) --------------------------------------------------------
char sub_12297B( int a1, int a2, int a3, int a4)
{
  int16_t v4; // ax

  v4 = sub_12066F(a3);
  return sub_122A6E(a1 - (v4 - 1), a2, a3, a4);
}
// 12297B: could not find valid save-restore pair for ebx


//----- (001229C5) --------------------------------------------------------
char sub_1229C5( int a1, int a2, int a3, int a4)
{
  int16_t v4; // ax

  v4 = sub_12066F(a3);
  return sub_122A6E(a1 - v4 / 2, a2, a3, a4);
}
// 1229C5: could not find valid save-restore pair for ebx


//----- (00122A1F) --------------------------------------------------------
char sub_122A1F( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v6; // [esp+Ch] [ebp-4h]

  v6 = a4;
  if ( a4 < 0 )
    v6 = 0;
  return sub_122AAB(a1, a2, a3, v6, a5);
}
// 122A1F: could not find valid save-restore pair for ebx


//----- (00122A6E) --------------------------------------------------------
char sub_122A6E( int a1, int a2, int a3, int a4)
{
  return sub_122AAB(a1, a2, a3, 0, a4);
}


//----- (00122AAB) --------------------------------------------------------
char sub_122AAB( int a1, int a2, int a3, int a4, int a5)
{
  int i; // [esp+4h] [ebp-2Ch]
  int j; // [esp+4h] [ebp-2Ch]
  int v8; // [esp+10h] [ebp-20h]

  dword_1BC2A8 = a5;
  if ( (*(_BYTE *)(a5 + 11) & 3) != 1 )
    sub_126487(aPrintOnlyWorks, a2);
  v8 = *(int *)((char *)&dword_1B3E82 + 2) >> 16;
  if ( *(int *)((char *)&dword_1B3E82 + 2) >> 16 )
  {
    byte_1B3E7C[0] = word_18450E;
    for ( i = 1; i < 8; ++i )
      byte_1B3E7C[i] = word_18450C;
    LOWORD(dword_184510) = 1;
    if ( v8 != 2 )
    {
      sub_122D8A(a1 + 1, a2 + 1, a3, 0, a4, (int16_t *)a5);
      sub_122D8A(a1, a2 + 1, a3, 0, a4, (int16_t *)a5);
      sub_122D8A(a1 + 1, a2, a3, 0, a4, (int16_t *)a5);
    }
    if ( v8 != 1 && v8 != 3 )
    {
      sub_122D8A(a1 - 1, a2, a3, 0, a4, (int16_t *)a5);
      sub_122D8A(a1 - 1, a2 - 1, a3, 0, a4, (int16_t *)a5);
      sub_122D8A(a1, a2 - 1, a3, 0, a4, (int16_t *)a5);
    }
    if ( v8 == 3 || v8 == 5 )
    {
      sub_122D8A(a1 + 2, a2 + 2, a3, 0, a4, (int16_t *)a5);
      sub_122D8A(a1 + 1, a2 + 2, a3, 0, a4, (int16_t *)a5);
      sub_122D8A(a1 + 2, a2 + 1, a3, 0, a4, (int16_t *)a5);
    }
    if ( v8 > 3 )
    {
      sub_122D8A(a1 + 1, a2 - 1, a3, 0, a4, (int16_t *)a5);
      sub_122D8A(a1 - 1, a2 + 1, a3, 0, a4, (int16_t *)a5);
    }
    if ( v8 == 5 )
    {
      sub_122D8A(a1 + 2, a2, a3, 0, a4, (int16_t *)a5);
      sub_122D8A(a1, a2 + 2, a3, 0, a4, (int16_t *)a5);
    }
    for ( j = 0; j < 8; ++j )
      byte_1B3E7C[j] = byte_1B3E88[j];
  }
  LOWORD(dword_184510) = 0;
  return sub_122D8A(a1, a2, a3, 1, a4, (int16_t *)a5);
}
// 122AAB: could not find valid save-restore pair for ebx
// 18450C: using guessed type int16_t word_18450C;
// 18450E: using guessed type int16_t word_18450E;
// 184510: using guessed type int dword_184510;
// 1B3E82: using guessed type int dword_1B3E82;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (00122D8A) --------------------------------------------------------
char sub_122D8A( int a1, int a2, int a3, int a4, int a5, int16_t *a6)
{
  int v6; // eax
  int v8; // [esp+8h] [ebp-3Ch]
  int v9; // [esp+10h] [ebp-34h]
  int v10; // [esp+14h] [ebp-30h]
  int v11; // [esp+18h] [ebp-2Ch]
  int v12; // [esp+20h] [ebp-24h]
  int v13; // [esp+24h] [ebp-20h]
  int v14; // [esp+28h] [ebp-1Ch]
  int v15; // [esp+2Ch] [ebp-18h]
  uint8_t v17; // [esp+40h] [ebp-4h]

  v11 = 0;
  v8 = dword_1B3E82 >> 16;
  v14 = (int16_t)sub_12066F(a3);
  v9 = 0;
  v10 = 0;
  LOWORD(v15) = 0;
  v12 = 0;
  v13 = 0;
  LOWORD(dword_1B61E8) = a1;
  HIWORD(dword_1B61E0) = a2;
  LOBYTE(v6) = a2;
  if ( a2 <= a6[1] )
  {
    v6 = v8 + a2;
    if ( v6 > 0 )
    {
      LOBYTE(v6) = a1;
      if ( a1 <= *a6 )
      {
        v6 = v14 + a1;
        if ( v6 > 0 )
        {
          if ( (_WORD)a5 )
          {
            while ( *(_BYTE *)(v11 + a3)
                 && *(_BYTE *)(v11 + a3) != 13
                 && *(_BYTE *)(v11 + a3) != 20
                 && *(_BYTE *)(v11 + a3) != 25
                 && *(_BYTE *)(v11 + a3) != 21
                 && *(_BYTE *)(v11 + a3) != 29 )
            {
              if ( *(_BYTE *)(v11 + a3) == 32 )
                ++v12;
              ++v11;
            }
            if ( !v12 )
              a5 = 0;
            a5 -= sub_12066F(a3);
            if ( (int16_t)a5 > 0 )
            {
              v10 = (int16_t)a5 % v12;
              v15 = (int16_t)a5 / v12;
            }
            else
            {
              LOWORD(a5) = 0;
            }
          }
          while ( 1 )
          {
            LOBYTE(v6) = *(_BYTE *)(v13 + a3);
            v17 = v6;
            if ( !(_BYTE)v6 )
              return v6;
            LOBYTE(v6) = *(_BYTE *)(v13 + a3);
            if ( v17 >= 8u )
              break;
            if ( v17 < 2u )
            {
              if ( a4 )
                sub_121B40();
            }
            else if ( v17 <= 2u )
            {
              if ( a4 )
                sub_121B8C();
            }
            else if ( v17 <= 3u )
            {
              if ( a4 )
                sub_121BD8();
            }
            else
            {
              if ( v17 != 4 )
                goto LABEL_56;
              if ( a4 )
                sub_121B8C();
            }
LABEL_62:
            ++v13;
          }
          if ( v17 <= 8u )
            goto LABEL_62;
          if ( v17 < 0x14u )
          {
            if ( v17 == 13 )
              return v6;
          }
          else if ( v17 <= 0x15u || v17 >= 0x19u && (v17 <= 0x19u || v17 == 29) )
          {
            return v6;
          }
LABEL_56:
          sub_123070(*(int *)((char *)&dword_1B61E4 + 2) >> 16, dword_1B61E0 >> 16, v17, a6);
          LOWORD(dword_1B61E8) = word_1B3EA6 + (uint8_t)byte_1B3EA8[v17] + dword_1B61E8;
          if ( (_WORD)a5 && v17 == 32 )
          {
            LOWORD(dword_1B61E8) = v15 + dword_1B61E8;
            if ( v9 < v10 )
              LOWORD(dword_1B61E8) = dword_1B61E8 + 1;
            ++v9;
          }
          goto LABEL_62;
        }
      }
    }
  }
  return v6;
}
// 122FA5: conditional instruction was optimized away because %var_44.1==1
// 1B3E82: using guessed type int dword_1B3E82;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1B61E0: using guessed type int dword_1B61E0;
// 1B61E4: using guessed type int dword_1B61E4;
// 1B61E8: using guessed type int dword_1B61E8;


//----- (00123070) --------------------------------------------------------
int sub_123070(int a1, int a2, unsigned int a3, int16_t *a4)
{
  int result; // eax
  int16_t v6; // [esp+Ch] [ebp-30h]
  int v7; // [esp+14h] [ebp-28h]
  int16_t v8; // [esp+1Ch] [ebp-20h]
  int v9; // [esp+28h] [ebp-14h]
  int16_t v10; // [esp+2Ch] [ebp-10h]

  v6 = a2;
  result = a3;
  if ( a3 <= 0x80u )
  {
    v8 = (uint8_t)byte_1B3EA8[a3];
    if ( (a1 & 0x8000u) == 0 )
    {
      LOWORD(v7) = 0;
    }
    else
    {
      v7 = -a1;
      result = -a1;
      if ( (int16_t)-(int16_t)a1 >= v8 )
        return result;
      LOWORD(a1) = 0;
      v8 -= v7;
    }
    if ( v8 + (int16_t)a1 <= (int16_t)(*a4 - 1) || (v8 = *a4 - a1, result = v8, v8 >= 1) )
    {
      if ( (a2 & 0x8000u) == 0 )
      {
        LOWORD(v9) = 0;
      }
      else
      {
        v9 = -a2;
        v6 = 0;
      }
      if ( SHIWORD(dword_1B3E82) + v6 <= (int16_t)(a4[1] - 1) )
        v10 = HIWORD(dword_1B3E82);
      else
        v10 = a4[1] - v6;
      return sub_1231B1((int16_t)a1, v6, a3, v7, v8, v9, v10, a4);
    }
  }
  return result;
}
// 1B3E82: using guessed type int dword_1B3E82;
// 1B3EA6: using guessed type int16_t word_1B3EA6;


//----- (001231B1) --------------------------------------------------------
int sub_1231B1(
        int a1, int a2, unsigned int a3, int a4, int a5, int a6, int a7,
        int16_t *a8)
{
  int v8; // eax
  int i; // [esp+0h] [ebp-50h]
  int j; // [esp+0h] [ebp-50h]
  int v12; // [esp+10h] [ebp-40h]
  char *v13; // [esp+14h] [ebp-3Ch]
  int v14; // [esp+1Ch] [ebp-34h]
  int16_t v15; // [esp+20h] [ebp-30h]
  int v17; // [esp+38h] [ebp-18h]
  uint8_t k; // [esp+48h] [ebp-8h]
  int16_t v19; // [esp+68h] [ebp+18h]

  dword_1BC2A8 = (int)a8;
  v13 = (char *)a8 + *(_DWORD *)&a8[2 * (*(int *)(a8 + 1) >> 16) + 6];
  v15 = *a8;
  v14 = (int16_t)a1 + *a8 * a2 - a4;
  v8 = 4 * a3;
  LOWORD(v8) = *(_WORD *)((char *)dword_1B3FA8 + v8);
  v17 = v8;
  if ( a7 > word_1B3EA0 )
    a7 = word_1B3EA0;
  for ( i = 0; a6 > i; ++i )
  {
    while ( *(uint8_t *)((int16_t)v17 + dword_1B3E74) != 128 )
      ++v17;
    ++v17;
  }
  v19 = a7 - a6;
  for ( j = 0; v19 > j; ++j )
  {
    v12 = v14;
    for ( k = *(_BYTE *)((int16_t)v17 + dword_1B3E74); k != 128; k = *(_BYTE *)(dword_1B3E74 + (int16_t)v17) )
    {
      if ( k <= 0x80u )
      {
        if ( k && v12 >= a4 + v14 && v12 < a5 + a4 + v14 )
          v13[v12] = *((_BYTE *)&dword_1B3E78 + k + 3);
        ++v12;
      }
      else
      {
        v12 += k & 0x7F;
      }
      ++v17;
    }
    ++v17;
    v14 += v15;
  }
  return a1 + (uint8_t)byte_1B3EA8[a3];
}
// 1B3E74: using guessed type int dword_1B3E74;
// 1B3E78: using guessed type int dword_1B3E78;
// 1B3EA0: using guessed type int16_t word_1B3EA0;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1B3FA8: using guessed type int dword_1B3FA8[256];
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (00123387) --------------------------------------------------------
int16_t sub_123387( int result)
{
  HIWORD(dword_1B61E8) = result;
  return result;
}
// 1B61E8: using guessed type int dword_1B61E8;


//----- (001233B4) --------------------------------------------------------
int sub_1233B4()
{
  int result; // eax

  dword_1BB8E4 = 0;
  dword_1BB8E8 = 0;
  dword_1BB8EC = 0;
  dword_1BB8E0 = 27;
  int386(51, &dword_1BB8E0, &dword_1BB8E0);
  dword_1B91F0 = dword_1BB8E4;
  dword_1B91F8 = dword_1BB8E8;
  result = dword_1BB8EC;
  dword_1B91F4 = dword_1BB8EC;
  return result;
}
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);
// 1B91F0: using guessed type int dword_1B91F0;
// 1B91F4: using guessed type int dword_1B91F4;
// 1B91F8: using guessed type int dword_1B91F8;
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8EC: using guessed type int dword_1BB8EC;


//----- (00123437) --------------------------------------------------------
int sub_123437()
{
  LOWORD(dword_1BB8E0) = 26;
  dword_1BB8E4 = dword_1B91F0;
  dword_1BB8E8 = dword_1B91F8;
  dword_1BB8EC = dword_1B91F4;
  return int386(51, &dword_1BB8E0, &dword_1BB8E0);
}
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);
// 1B91F0: using guessed type int dword_1B91F0;
// 1B91F4: using guessed type int dword_1B91F4;
// 1B91F8: using guessed type int dword_1B91F8;
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8EC: using guessed type int dword_1BB8EC;


//----- (00123491) --------------------------------------------------------
void sub_123491()
{
  LOWORD(dword_18451A) = 1;
  LOWORD(dword_1BBA38) = 0;
  dword_1BBA46 = 0;
  HIWORD(dword_1BBA34) = 0;
  // VLNA 17: unk_1B9E38/unk_1BA0A8 jsou "cursor background" buffery (26x24 =
  // 624 B), do kterych render mysi (sub_144A91/sub_14529D) ZAPISUJE. IDA je
  // ale zdekompilovala jako _UNKNOWN (1 bajt) -> zapis 624 B pretekal a
  // KORUPTOVAL render vtable (dword_1B920C/1B9210...) i sousedni globaly ->
  // pad. Misto zvetsovani statickych globalu (posunulo by BSS layout a
  // rozbilo jine mis-sized buffery) alokujeme 624B buffery na halde -
  // dword_1BB8B0/8B8 stejne drzi jen (int) ukazatel (LAA:NO -> < 2GB).
  dword_1BB8B0 = (int)(intptr_t)nmalloc(624);
  dword_1BB8B8 = (int)(intptr_t)nmalloc(624);
  (void)&unk_1B9E38;
  (void)&unk_1BA0A8;
  LOWORD(dword_1BB8E0) = 0;
  LOWORD(dword_1BB8E4) = 0;
  LOWORD(dword_1BB8E8) = 0;
  LOWORD(dword_1BB8EC) = 0;
  sub_144A46();
  int386(51, &dword_1BB8E0, &dword_1BB8E0);
  if ( !(_WORD)dword_1BB8E0 )
  {
    sub_144A48();
    sub_126487(aMouseDriverReq, (int)&dword_1BB8E0);
  }
  sub_1233B4();
  LOWORD(dword_1BB8E0) = 3;
  LOWORD(dword_1BB8E4) = 0;
  LOWORD(dword_1BB8E8) = 0;
  LOWORD(dword_1BB8EC) = 0;
  int386(51, &dword_1BB8E0, &dword_1BB8E0);
  LOWORD(dword_1BB8E0) = 7;
  LOWORD(dword_1BB8E4) = 0;
  LOWORD(dword_1BB8E8) = 0;
  LOWORD(dword_1BB8EC) = 2 * (WORD2(qword_184530) - 1);
  int386(51, &dword_1BB8E0, &dword_1BB8E0);
  LOWORD(dword_1BB8E0) = 8;
  LOWORD(dword_1BB8E4) = 0;
  LOWORD(dword_1BB8E8) = 0;
  LOWORD(dword_1BB8EC) = screenHeight_184538 - 1;
  int386(51, &dword_1BB8E0, &dword_1BB8E0);
  LOWORD(dword_1BB8E0) = 26;
  LOWORD(dword_1BB8E4) = 100;
  LOWORD(dword_1BB8E8) = 100;
  LOWORD(dword_1BB8EC) = screenHeight_184538 - 1;
  int386(51, &dword_1BB8E0, &dword_1BB8E0);
  sub_124105();
  sub_1237F3();
  sub_144A46();
  word_184518 = 0;
  word_1B9228 = 0;
  word_1B9220 = 0;
  sub_144A48();
  word_18452A = WORD2(qword_184530) - 1;
  word_18452C = screenHeight_184538 - 1;
  sub_123E6C((int)&unk_184522, 1);
  sub_123B14(SHIDWORD(qword_184530) / 2, screenHeight_184538 / 2);
  word_184518 = 1;
  LOWORD(dword_18451A) = 0;
}
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);
// 184518: using guessed type int16_t word_184518;
// 18451A: using guessed type int dword_18451A;
// 18452A: using guessed type int16_t word_18452A;
// 18452C: using guessed type int16_t word_18452C;
// 184530: using guessed type int64_t qword_184530;
// 1B9220: using guessed type int16_t word_1B9220;
// 1B9228: using guessed type int16_t word_1B9228;
// 1BB8B0: using guessed type int dword_1BB8B0;
// 1BB8B8: using guessed type int dword_1BB8B8;
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8EC: using guessed type int dword_1BB8EC;
// 1BBA34: using guessed type int dword_1BBA34;
// 1BBA38: using guessed type int dword_1BBA38;
// 1BBA46: using guessed type int dword_1BBA46;


//----- (001236D1) --------------------------------------------------------
void __noreturn sub_1236D1()
{
  ((void (__noreturn *)(_DWORD))_GETDS)((uint16_t)__DS__);
}
// 1236D1: could not find valid save-restore pair for ebp
// 1236D1: could not find valid save-restore pair for edi
// 1236D1: could not find valid save-restore pair for esi
// 184514: using guessed type int dword_184514;
// 18451A: using guessed type int dword_18451A;
// 18451E: using guessed type int16_t word_18451E;
// 184520: using guessed type int16_t word_184520;
// 1B9208: using guessed type int (*dword_1B9208)(_DWORD, _DWORD, _DWORD, _DWORD);
// 1B920C: using guessed type int (*dword_1B920C)(_DWORD);
// 1B9210: using guessed type int (*dword_1B9210)(_DWORD);
// 1B921A: using guessed type int16_t word_1B921A;
// 1B922A: using guessed type char byte_1B922A;
// 1B9E2B: using guessed type int dword_1B9E2B;
// 1B9E2F: using guessed type int16_t word_1B9E2F;
// 1BBA34: using guessed type int dword_1BBA34;
// 1BBA38: using guessed type int dword_1BBA38;


//----- (001237F3) --------------------------------------------------------
void sub_1237F3()
{
  sub_144A46();
  LOWORD(dword_1BB8E0) = 12;
  LOWORD(dword_1BB8E8) = 1;
  dword_1BB8EC = (int)sub_1236D1;
  word_1BBA1C[0] = __CS__;
  int386x(51, &dword_1BB8E0);
  sub_144A48();
}
// 144A4A: using guessed type int int386x(_DWORD, _DWORD);
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8EC: using guessed type int dword_1BB8EC;
// 1BBA1C: using guessed type int16_t word_1BBA1C;


//----- (0012386C) --------------------------------------------------------
void sub_12386C()
{
  sub_144A46();
  LOWORD(dword_1BB8E0) = 20;
  LOWORD(dword_1BB8E8) = 43;
  dword_1BB8EC = (int)sub_1236D1;
  word_1BBA1C[0] = __CS__;
  int386x(51, &dword_1BB8E0);
  word_184518 = 1;
  LOWORD(dword_1BB8E0) = 3;
  LOWORD(dword_1BB8E4) = 0;
  LOWORD(dword_1BB8E8) = 0;
  LOWORD(dword_1BB8EC) = 0;
  int386(51, &dword_1BB8E0, &dword_1BB8E0);
  sub_144A48();
}
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);
// 144A4A: using guessed type int int386x(_DWORD, _DWORD);
// 184518: using guessed type int16_t word_184518;
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8EC: using guessed type int dword_1BB8EC;
// 1BBA1C: using guessed type int16_t word_1BBA1C;


//----- (00123926) --------------------------------------------------------
void sub_123926()
{
  sub_144A46();
  LOWORD(dword_1BB8E0) = 20;
  LOWORD(dword_1BB8E8) = 1;
  dword_1BB8EC = (int)sub_1236D1;
  word_1BBA1C[0] = __CS__;
  int386x(51, &dword_1BB8E0);
  word_184518 = 1;
  LOWORD(dword_1BB8E0) = 3;
  LOWORD(dword_1BB8E4) = 0;
  LOWORD(dword_1BB8E8) = 0;
  LOWORD(dword_1BB8EC) = 0;
  int386(51, &dword_1BB8E0, &dword_1BB8E0);
  sub_144A48();
}
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);
// 144A4A: using guessed type int int386x(_DWORD, _DWORD);
// 184518: using guessed type int16_t word_184518;
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8EC: using guessed type int dword_1BB8EC;
// 1BBA1C: using guessed type int16_t word_1BBA1C;


//----- (001239E0) --------------------------------------------------------
void sub_1239E0()
{
  word_184518 = 1;
}
// 184518: using guessed type int16_t word_184518;


//----- (00123A08) --------------------------------------------------------
void sub_123A08()
{
  word_184518 = 0;
}
// 184518: using guessed type int16_t word_184518;


//----- (00123A30) --------------------------------------------------------
int16_t sub_123A30()
{
  int16_t result; // ax

  result = word_184518;
  word_1B9226 = word_184518;
  word_184518 = 0;
  return result;
}
// 184518: using guessed type int16_t word_184518;
// 1B9226: using guessed type int16_t word_1B9226;


//----- (00123A64) --------------------------------------------------------
int16_t sub_123A64()
{
  int16_t result; // ax

  result = word_1B9226;
  word_184518 = word_1B9226;
  return result;
}
// 184518: using guessed type int16_t word_184518;
// 1B9226: using guessed type int16_t word_1B9226;


//----- (00123ABA) --------------------------------------------------------
int16_t sub_123ABA()
{
  return dword_1BBA38;
}
// 1BBA38: using guessed type int dword_1BBA38;


//----- (00123AE7) --------------------------------------------------------
int16_t sub_123AE7()
{
  return HIWORD(dword_1BBA34);
}
// 1BBA34: using guessed type int dword_1BBA34;


//----- (00123B14) --------------------------------------------------------
void sub_123B14( int a1, int a2)
{
  LOWORD(dword_1BBA38) = a1;
  HIWORD(dword_1BBA34) = a2;
  sub_123B58(a1, a2);
}
// 1BBA34: using guessed type int dword_1BBA34;
// 1BBA38: using guessed type int dword_1BBA38;


//----- (00123B58) --------------------------------------------------------
void sub_123B58( int a1, int a2)
{
  LOWORD(dword_1BB8E0) = 4;
  LOWORD(dword_1BB8E4) = 0;
  LOWORD(dword_1BB8E8) = 2 * a1;
  LOWORD(dword_1BB8EC) = a2;
  sub_144A46();
  int386(51, &dword_1BB8E0, &dword_1BB8E0);
  sub_144A48();
}
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8EC: using guessed type int dword_1BB8EC;


//----- (00123BC1) --------------------------------------------------------
int16_t sub_123BC1()
{
  return word_1B921C;
}
// 1B921C: using guessed type int16_t word_1B921C;


//----- (00123BEE) --------------------------------------------------------
int16_t sub_123BEE()
{
  return word_1B921E;
}
// 1B921E: using guessed type int16_t word_1B921E;


//----- (00123C1B) --------------------------------------------------------
int16_t sub_123C1B()
{
  return dword_1B9222;
}
// 1B9222: using guessed type int dword_1B9222;


//----- (00123C48) --------------------------------------------------------
int16_t sub_123C48()
{
  int16_t result; // ax

  result = word_1B9228;
  word_1B9228 = 0;
  return result;
}
// 1B9228: using guessed type int16_t word_1B9228;


//----- (00123C84) --------------------------------------------------------
int16_t sub_123C84()
{
  int16_t result; // ax

  result = word_1B9220;
  word_1B9220 = 0;
  return result;
}
// 1B9220: using guessed type int16_t word_1B9220;


//----- (00123D53) --------------------------------------------------------
int16_t sub_123D53()
{
  int16_t result; // ax

  result = word_1B921A & 3;
  if ( (word_1B921A & 3) != 0 )
  {
    LOWORD(dword_1B9222) = word_1B921A & 3;
    if ( dword_18451A >> 16 == 1 )
      LOWORD(dword_1B9222) = word_18451E + word_184520;
    word_1B9228 = 1;
    word_1B9220 = 1;
    word_1B921C = dword_1BBA38;
    result = HIWORD(dword_1BBA34);
    word_1B921E = HIWORD(dword_1BBA34);
  }
  ++dword_1B91EC;
  return result;
}
// 18451A: using guessed type int dword_18451A;
// 18451E: using guessed type int16_t word_18451E;
// 184520: using guessed type int16_t word_184520;
// 1B91EC: using guessed type int dword_1B91EC;
// 1B921A: using guessed type int16_t word_1B921A;
// 1B921C: using guessed type int16_t word_1B921C;
// 1B921E: using guessed type int16_t word_1B921E;
// 1B9220: using guessed type int16_t word_1B9220;
// 1B9222: using guessed type int dword_1B9222;
// 1B9228: using guessed type int16_t word_1B9228;
// 1BBA34: using guessed type int dword_1BBA34;
// 1BBA38: using guessed type int dword_1BBA38;


//----- (00123DD9) --------------------------------------------------------
void sub_123DD9()
{
  sub_124105();
  word_1B9228 = 0;
  word_1B9220 = 0;
  LOWORD(dword_1BBA46) = sub_123ABA();
  HIWORD(dword_1BBA46) = sub_123AE7();
  sub_144A46();
  LOWORD(dword_1BB8E0) = 33;
  LOWORD(dword_1BB8E4) = 0;
  LOWORD(dword_1BB8E8) = 0;
  LOWORD(dword_1BB8EC) = 0;
  int386(51, &dword_1BB8E0, &dword_1BB8E0);
  sub_123437();
  sub_144A48();
}
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);
// 1B9220: using guessed type int16_t word_1B9220;
// 1B9228: using guessed type int16_t word_1B9228;
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8EC: using guessed type int dword_1BB8EC;
// 1BBA46: using guessed type int dword_1BBA46;


//----- (00123E6C) --------------------------------------------------------
int16_t sub_123E6C(int a1, int a2)
{
  dword_1B9204 = a1;
  HIWORD(dword_1B9222) = a2;
  return sub_123EA7();
}
// 1B9204: using guessed type int dword_1B9204;
// 1B9222: using guessed type int dword_1B9222;


//----- (00123EA7) --------------------------------------------------------
int16_t sub_123EA7()
{
  int v0; // eax
  int i; // [esp+0h] [ebp-4h]

  HIWORD(dword_1BBA38) = -1;
  for ( i = 0; dword_1B9222 >> 16 > i; ++i )
  {
    if ( (*(int *)((char *)&dword_1BBA34 + 2) >> 16) + (*(int *)(dword_1B9204 + 12 * i) >> 16) >= *(int *)(dword_1B9204 + 12 * i + 2) >> 16
      && (*(int *)((char *)&dword_1BBA34 + 2) >> 16) + (*(int *)(dword_1B9204 + 12 * i) >> 16) <= *(int *)(dword_1B9204 + 12 * i + 6) >> 16
      && (dword_1BBA34 >> 16) + (*(int *)(dword_1B9204 + 12 * i) >> 16) >= *(int *)(dword_1B9204 + 12 * i + 4) >> 16
      && (dword_1BBA34 >> 16) + (*(int *)(dword_1B9204 + 12 * i) >> 16) <= *(int *)(dword_1B9204 + 12 * i + 8) >> 16 )
    {
      HIWORD(dword_1BBA38) = i;
    }
  }
  v0 = dword_1BBA38 >> 16;
  if ( dword_1BBA38 >> 16 == -1 )
  {
    word_1BBA3C = 0;
  }
  else
  {
    LOWORD(v0) = *(_WORD *)(12 * (dword_1BBA38 >> 16) + dword_1B9204);
    word_1BBA3C = v0;
  }
  return v0;
}
// 1B9204: using guessed type int dword_1B9204;
// 1B9222: using guessed type int dword_1B9222;
// 1BBA34: using guessed type int dword_1BBA34;
// 1BBA38: using guessed type int dword_1BBA38;
// 1BBA3C: using guessed type int16_t word_1BBA3C;


//----- (00123FFB) --------------------------------------------------------
int sub_123FFB()
{
  return *(int *)(12 * (dword_1BBA38 >> 16) + dword_1B9204) >> 16;
}
// 1B9204: using guessed type int dword_1B9204;
// 1BBA38: using guessed type int dword_1BBA38;


//----- (00124039) --------------------------------------------------------
int sub_124039()
{
  return *(int16_t *)(12 * (dword_1BBA38 >> 16) + dword_1B9204);
}
// 1B9204: using guessed type int dword_1B9204;
// 1BBA38: using guessed type int dword_1BBA38;


//----- (00124075) --------------------------------------------------------
int16_t sub_124075()
{
  LOWORD(dword_1BB8E0) = 3;
  LOWORD(dword_1BB8E4) = 0;
  LOWORD(dword_1BB8E8) = 0;
  LOWORD(dword_1BB8EC) = 0;
  sub_144A46();
  int386(51, &dword_1BB8E0, &dword_1BB8E0);
  sub_144A48();
  if ( HIWORD(dword_18451A) )
    return word_18451E + word_184520;
  else
    return dword_1BB8E4 & 3;
}
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);
// 18451A: using guessed type int dword_18451A;
// 18451E: using guessed type int16_t word_18451E;
// 184520: using guessed type int16_t word_184520;
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8EC: using guessed type int dword_1BB8EC;


//----- (00124105) --------------------------------------------------------
int sub_124105()
{
  LOWORD(dword_1BB8E4) = 1;
  while ( (dword_1BB8E4 & 3) != 0 )
  {
    LOWORD(dword_1BB8E0) = 3;
    LOWORD(dword_1BB8E4) = 0;
    LOWORD(dword_1BB8E8) = 0;
    LOWORD(dword_1BB8EC) = 0;
    sub_144A46();
    int386(51, &dword_1BB8E0, &dword_1BB8E0);
    sub_144A48();
  }
  return dword_1BB8E4 & 3;
}
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8EC: using guessed type int dword_1BB8EC;


//----- (0012435C) --------------------------------------------------------
int sub_12435C()
{
  int result = 0; // eax

  if ( word_1BBA3C > 0 )
  {
    result = 576 * ((*(int *)((char *)&dword_1BBA38 + 2) >> 16) - 1);
    dword_1BBA18 = result + dword_1BB900;
    sub_14595F();
  }
  return result;
}
// 1BB900: using guessed type int dword_1BB900;
// 1BBA18: using guessed type int dword_1BBA18;
// 1BBA38: using guessed type int dword_1BBA38;
// 1BBA3C: using guessed type int16_t word_1BBA3C;


//----- (0012439D) --------------------------------------------------------
int sub_12439D()
{
  int result = 0; // eax  // vlna 17: Hex-Rays artefakt neinicializovaneho
                          // navratu (word_1BBA3C <= 0 -> return result). Debug RTC jinak pada.

  if ( word_1BBA3C > 0 )
  {
    result = 576 * ((*(int *)((char *)&dword_1BBA38 + 2) >> 16) - 1);
    dword_1BBA18 = result + dword_1BB900;
    sub_14529D();
  }
  return result;
}
// 1BB900: using guessed type int dword_1BB900;
// 1BBA18: using guessed type int dword_1BBA18;
// 1BBA38: using guessed type int dword_1BBA38;
// 1BBA3C: using guessed type int16_t word_1BBA3C;


//----- (001247A0) --------------------------------------------------------
unsigned int sub_1247A0(unsigned int a1)
{
  do
    dword_1B9E34 = 1103515245 * dword_1B9E34 + 12345;
  while ( a1 * (0xFFFFFFFF / a1) <= dword_1B9E34 );
  return dword_1B9E34 / (0xFFFFFFFF / a1) + 1;
}
// 1247D6: conditional instruction was optimized away because eax.4!=0
// 1B9E34: using guessed type int dword_1B9E34;


//----- (00124820) --------------------------------------------------------
int sub_124820(int result)
{
  dword_1B9E34 = result;
  return result;
}
// 1B9E34: using guessed type int dword_1B9E34;


//----- (0012484C) --------------------------------------------------------
int sub_12484C()
{
  return dword_1B9E34;
}
// 1B9E34: using guessed type int dword_1B9E34;


//----- (00124878) --------------------------------------------------------
int sub_124878()
{
  int v1; // [esp+0h] [ebp-4h]

  v1 = time(0);
  return sub_124820(v1);
}
// 13C905: using guessed type int64_t time(_DWORD);


//----- (001248AB) --------------------------------------------------------
int16_t sub_1248AB( int a1)
{
  int v1; // edx

  dword_1BB880 = (int)byte_1BB358;
  word_1BBA68 = a1;
  switch ( a1 )
  {
    case 0:
      HIDWORD(qword_184530) = 320;
      screenHeight_184538 = 200;
      break;
    case 1:
      HIDWORD(qword_184530) = 320;
      screenHeight_184538 = 200;
      break;
    case 2:
      HIDWORD(qword_184530) = 320;
      screenHeight_184538 = 240;
      break;
    case 3:
      HIDWORD(qword_184530) = 320;
      screenHeight_184538 = 480;
      break;
    case 4:
      HIDWORD(qword_184530) = 640;
      screenHeight_184538 = 480;
      break;
    default:
      break;
  }
  dword_18453C = screenHeight_184538 * HIDWORD(qword_184530);
  v1 = screenHeight_184538;
  PortDebug_Checkpoint("1248AB.before_12537D", dword_18453C);
  sub_12537D(screenHeight_184538 * HIDWORD(qword_184530), screenHeight_184538);
  PortDebug_Checkpoint("1248AB.after_12537D", 0);
  // VLNA 16 - PORT: vzdy VESA linearni cesta (video mod 5). Port renderuje
  // pres SDL do LINEARNIHO 640x480 bufferu (Port::Vga) - to presne odpovida
  // VESA linearnimu modu, ve kterem bezi i original (OVERENO dumpem:
  // HIWORD(dword_1BBA52)==5). Puvodne se VESA cesta brala jen kdyz
  // HIWORD(dword_1BBA64)==4 (SVGA priznak z konfigurace/detekce); v portu
  // zadna hardwarova VESA detekce neni, takze cestu vynutime. Jinak by mod
  // zustal word_1BBA68 (=4), pro ktery render vtable sub_125064 NEMA case
  // -> vsechny funkcni ukazatele (dword_1BB89C/1BB894/1BB88C...) zustanou
  // NULL -> pad pri prvnim vykresleni. Viz PROGRESS.md vlna 16.
  (void)word_1BBA68;
  HIWORD(dword_1BBA52) = sub_1252C2();   // sub_145FD2()==true -> vraci 5
  if ( dword_1BBA52 >> 16 == -1 )
    sub_126487(aYouMustRunVesa, v1);
  HIWORD(dword_1BBA64) = 0;
  // PORT (vlna 21): original zde ukladal adresu VESA okna A000:0000 (vyraz
  // "&loc_9FFFD + 3" = 0xA0000). V portu je loc_9FFFD 1B symbol v BSS - 300KB
  // prezentacni kopie by prepisovaly sousedni globaly ("dword_1BB90C ma spatne
  // hodnoty" byl ve skutecnosti tenhle zapis mimo). Misto toho linearni
  // 640x480 framebuffer portu; bankovani (dword_1BB8A4) je no-op.
  dword_1BB910[0] = (int)PortVga_Framebuffer();
  PortDebug_Checkpoint("1248AB.fb_ptr_as_int", dword_1BB910[0]); // musi byt != 0
  PortDebug_Checkpoint("1248AB.before_12542A", 0);
  word_1BBA62 = sub_12542A();
  LOWORD(dword_1BBA4A) = (int)unk_1BBA60 >> 16 >= (2 * dword_18453C
                                                 - (__CFSHL__((2 * dword_18453C) >> 31, 10)
                                                  + ((2 * dword_18453C) >> 31 << 10))) >> 10;
  word_1BBA56 = sub_1254C0();
  word_1BBA5C = 64 / (uint16_t)word_1BBA56;
  dword_1BB904 = dword_1BB90C;
  PortDebug_Checkpoint("1248AB.videoMode", HIWORD(dword_1BBA52)); // vlna 16: ma byt 5
  sub_125064(dword_1BB90C);
  PortDebug_Checkpoint("1248AB.before_125300", 0);
  sub_125300();
  PortDebug_Checkpoint("1248AB.before_124D41", 0);
  sub_124D41();
  PortDebug_Checkpoint("1248AB.before_125CE1", 0);
  sub_125CE1();
  PortDebug_Checkpoint("1248AB.before_125D18", 0);
  sub_125D18();
  dword_1BBA28 = 0;
  PortDebug_Checkpoint("1248AB.before_128BE7", 0);
  return sub_128BE7();
}
// 184530: using guessed type int64_t qword_184530;
// 18453C: using guessed type int dword_18453C;
// 1BB880: using guessed type int dword_1BB880;
// 1BB904: using guessed type int dword_1BB904;
// 1BB90C: using guessed type int dword_1BB90C;
// 1BB910: using guessed type int dword_1BB910[];
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BBA56: using guessed type int16_t word_1BBA56;
// 1BBA5C: using guessed type int16_t word_1BBA5C;
// 1BBA62: using guessed type int16_t word_1BBA62;
// 1BBA64: using guessed type int dword_1BBA64;
// 1BBA68: using guessed type int16_t word_1BBA68;


//----- (00124AA2) --------------------------------------------------------
char sub_124AA2()
{
  return byte_1BBA6B;
}
// 1BBA6B: using guessed type char byte_1BBA6B;


//----- (00124ACE) --------------------------------------------------------
int sub_124ACE()
{
  int v1[7]; // [esp+0h] [ebp-38h] BYREF
  _BYTE v2[28]; // [esp+1Ch] [ebp-1Ch] BYREF

  v1[0] = 3;
  return int386(16, v1, v2);
}
// 13F253: using guessed type int int386(_DWORD, _DWORD, _DWORD);


//----- (00124B65) --------------------------------------------------------
void sub_124B65()
{
  dword_1BBA28 = 0;
  dword_184540 = 0;
}
// 184540: using guessed type int dword_184540;
// 1BBA28: using guessed type int dword_1BBA28;


//----- (00124B98) --------------------------------------------------------
int16_t sub_124B98()
{
  int16_t result; // ax

  HIWORD(dword_1BBA2C) = dword_1BBA28;
  result = dword_184540;
  LOWORD(dword_1BBA2C) = dword_184540;
  return result;
}
// 184540: using guessed type int dword_184540;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA2C: using guessed type int dword_1BBA2C;


//----- (00124BCF) --------------------------------------------------------
int sub_124BCF()
{
  int result; // eax

  dword_1BBA28 = dword_1BBA2C >> 16;
  result = *(int *)((char *)&dword_1BBA28 + 2) >> 16;
  dword_184540 = *(int *)((char *)&dword_1BBA28 + 2) >> 16;
  return result;
}
// 184540: using guessed type int dword_184540;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA2C: using guessed type int dword_1BBA2C;


//----- (00124C08) --------------------------------------------------------
void sub_124C08()
{
  dword_1BBA28 = 3;
  dword_184540 = 0;
}
// 184540: using guessed type int dword_184540;
// 1BBA28: using guessed type int dword_1BBA28;


//----- (00124C3B) --------------------------------------------------------
int16_t sub_124C3B()
{
  return dword_1BBA28;
}
// 1BBA28: using guessed type int dword_1BBA28;


//----- (00124C9B) --------------------------------------------------------
void sub_124C9B()
{
  dword_1BBA28 = 2;
  dword_184540 = 0;
}
// 184540: using guessed type int dword_184540;
// 1BBA28: using guessed type int dword_1BBA28;


//----- (00124CCE) --------------------------------------------------------
void sub_124CCE()
{
  dword_1BBA28 = 2;
  dword_184540 = 2;
}
// 184540: using guessed type int dword_184540;
// 1BBA28: using guessed type int dword_1BBA28;


//----- (00124D41) --------------------------------------------------------
int sub_124D41()
{
  int result; // eax

  byte_1BBA6B = 1;
  result = dword_1BB90C;
  dword_1BB904 = dword_1BB90C;
  HIWORD(dword_1BBA42) = 0;
  return result;
}
// 1BB904: using guessed type int dword_1BB904;
// 1BB90C: using guessed type int dword_1BB90C;
// 1BBA42: using guessed type int dword_1BBA42;
// 1BBA6B: using guessed type char byte_1BBA6B;


//----- (00124D7A) --------------------------------------------------------
int sub_124D7A()
{
  int result; // eax

  byte_1BBA6B = 2;
  result = dword_1BB8FC;
  dword_1BB904 = dword_1BB8FC;
  HIWORD(dword_1BBA42) = 0;
  return result;
}
// 1BB8FC: using guessed type int dword_1BB8FC;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA42: using guessed type int dword_1BBA42;
// 1BBA6B: using guessed type char byte_1BBA6B;


//----- (00124DEC) --------------------------------------------------------
void *sub_124DEC()
{
  return sub_138CE0(
           (void *)dword_1BB8FC,
           (void *)dword_1BB90C,
           (dword_18453C - (__CFSHL__(dword_18453C >> 31, 10) + (dword_18453C >> 31 << 10))) >> 10);
}
// 18453C: using guessed type int dword_18453C;
// 1BB8FC: using guessed type int dword_1BB8FC;
// 1BB90C: using guessed type int dword_1BB90C;


//----- (00124E36) --------------------------------------------------------
void *sub_124E36()
{
  return sub_138CE0(
           (void *)dword_1BB90C,
           (void *)dword_1BB8FC,
           (dword_18453C - (__CFSHL__(dword_18453C >> 31, 10) + (dword_18453C >> 31 << 10))) >> 10);
}
// 18453C: using guessed type int dword_18453C;
// 1BB8FC: using guessed type int dword_1BB8FC;
// 1BB90C: using guessed type int dword_1BB90C;


//----- (00124E80) --------------------------------------------------------
int sub_124E80(int a1, int a2, int a3, int a4)
{
  int result; // eax

  byte_1B922A = 1;
  result = dword_1BB888((int16_t)a1, (int16_t)a2, (int16_t)a3, (int16_t)a4, a1, a2, a3, a4);
  byte_1B922A = 0;
  return result;
}
// 1B922A: using guessed type char byte_1B922A;
// 1BB888: using guessed type int (*dword_1BB888)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);


//----- (00124ECB) --------------------------------------------------------
int sub_124ECB()
{
  int v0; // eax
  int v1; // eax
  int result; // eax

  byte_1B922A = 1;
  sub_123A08();
  LOWORD(dword_1BBA46) = dword_1BBA38;
  HIWORD(dword_1BBA46) = HIWORD(dword_1BBA34);
  sub_11E718();
  if ( dword_184540 )
  {
    sub_138CEE(
      *(int *)((char *)&dword_1BBA3E + 2) >> 16,
      dword_1BBA3E >> 16,
      (*(int *)((char *)&dword_1BBA3E + 2) >> 16) + 26,
      (dword_1BBA3E >> 16) + 24);
    sub_145719();
    sub_12435C();
    v1 = sub_138CEE(
           *(int *)((char *)&dword_1BBA3E + 2) >> 16,
           dword_1BBA3E >> 16,
           (*(int *)((char *)&dword_1BBA3E + 2) >> 16) + 26,
           (dword_1BBA3E >> 16) + 24);
    if ( dword_184540 == 1 )
      dword_1BB898(v1);
    else
      dword_1BB8A0(v1);
    sub_145850();
  }
  else
  {
    if ( *(int *)((char *)&dword_1BBA46 + 2) >> 16 == 1 )
      HIWORD(dword_1BBA64) = 1 - HIWORD(dword_1BBA64);
    dword_1BB89C();
    if ( *(int *)((char *)&dword_1BBA46 + 2) >> 16 == 1 )
      dword_1BB894();
    if ( dword_1BBA28 == 3 || dword_1BBA28 == 2 )
      dword_184540 = 2;
    if ( dword_1BBA28 == 1 )
      dword_184540 = 1;
    v0 = ((int(*)())(void*)dword_1B920C)();
    dword_1B9210(v0);
  }
  sub_131F7B();
  sub_1239E0();
  if ( dword_1BBA28 == 3 )
  {
    sub_125D4F();
    sub_12779E((_BYTE *)dword_1BB908, (_BYTE *)dword_1BB8C0, 4 * screenHeight_184538);
    sub_125D18();
  }
  else
  {
    sub_125CE1();
  }
  result = sub_124D41();
  byte_1B922A = 0;
  return result;
}
// 11E718: using guessed type int sub_11E718(void);
// 184540: using guessed type int dword_184540;
// 1B920C: using guessed type int (*dword_1B920C)(void);
// 1B9210: using guessed type int (*dword_1B9210)(_DWORD);
// 1B922A: using guessed type char byte_1B922A;
// 1BB894: using guessed type int (*dword_1BB894)(void);
// 1BB898: using guessed type int (*dword_1BB898)(_DWORD);
// 1BB89C: using guessed type int (*dword_1BB89C)(void);
// 1BB8A0: using guessed type int (*dword_1BB8A0)(_DWORD);
// 1BB8C0: using guessed type int dword_1BB8C0;
// 1BB908: using guessed type int dword_1BB908;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA34: using guessed type int dword_1BBA34;
// 1BBA38: using guessed type int dword_1BBA38;
// 1BBA3E: using guessed type int dword_1BBA3E;
// 1BBA46: using guessed type int dword_1BBA46;
// 1BBA64: using guessed type int dword_1BBA64;


//----- (00125064) --------------------------------------------------------
int sub_125064(int a1)
{
  int v1; // kr00_4
  int result; // eax

  LOWORD(a1) = HIWORD(dword_1BBA52);
  v1 = a1;
  result = HIWORD(dword_1BBA52);
  switch ( HIWORD(dword_1BBA52) )
  {
    case 0:
      dword_1BB89C = (int (*)(void))sub_145B56;
      dword_1BB8A0 = (int (*)(_DWORD))sub_145BD2;
      dword_1BB898 = (int (*)(_DWORD))sub_145C4E;
      dword_1BB888 = (int (*)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))sub_145CCA;
      dword_1B920C = (int (*)(_DWORD))sub_145D66;
      dword_1B9208 = (int (*)(_DWORD, _DWORD, _DWORD, _DWORD))sub_145DE2;
      dword_1B9210 = (int (*)(_DWORD))sub_145E5E;
      dword_1BB884 = (int)sub_145EDA;
      dword_1BB890 = (int)sub_145F56;
      break;
    case 1:
      dword_1BB89C = (int (*)(void))sub_145B75;
      dword_1BB8A0 = (int (*)(_DWORD))sub_145BF1;
      dword_1BB898 = (int (*)(_DWORD))sub_145C6D;
      dword_1BB888 = (int (*)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))sub_145CF1;
      dword_1B920C = (int (*)(_DWORD))sub_145D85;
      dword_1B9208 = (int (*)(_DWORD, _DWORD, _DWORD, _DWORD))sub_145E01;
      dword_1B9210 = (int (*)(_DWORD))sub_145E7D;
      dword_1BB884 = (int)sub_145EF9;
      dword_1BB890 = (int)sub_145F75;
      break;
    case 2:
      dword_1BB89C = (int (*)(void))sub_145B94;
      dword_1BB8A0 = (int (*)(_DWORD))sub_145C10;
      dword_1BB898 = (int (*)(_DWORD))sub_145C8C;
      dword_1BB888 = (int (*)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))sub_145D18;
      dword_1B920C = (int (*)(_DWORD))sub_145DA4;
      dword_1B9208 = (int (*)(_DWORD, _DWORD, _DWORD, _DWORD))sub_145E20;
      dword_1B9210 = (int (*)(_DWORD))sub_145E9C;
      dword_1BB884 = (int)sub_145F18;
      dword_1BB890 = (int)sub_145F94;
      break;
    case 3:
      dword_1BB89C = (int (*)(void))sub_145BB3;
      dword_1BB8A0 = (int (*)(_DWORD))sub_145C2F;
      dword_1BB898 = (int (*)(_DWORD))sub_145CAB;
      dword_1BB888 = (int (*)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))sub_145D3F;
      dword_1B920C = (int (*)(_DWORD))sub_145DC3;
      dword_1B9208 = (int (*)(_DWORD, _DWORD, _DWORD, _DWORD))sub_145E3F;
      dword_1B9210 = (int (*)(_DWORD))sub_145EBB;
      dword_1BB884 = (int)sub_145F37;
      dword_1BB890 = (int)sub_145FB3;
      break;
    case 5:
      dword_1BB89C = (int (*)(void))sub_1255DF;
      dword_1BB8A0 = (int (*)(_DWORD))sub_125814;
      dword_1BB898 = (int (*)(_DWORD))sub_12567F;
      dword_1BB888 = (int (*)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))sub_126224;
      dword_1BB8A4 = (int (*)(_DWORD))sub_138C34;
      dword_1BB8A8 = (int (*)(_DWORD))sub_138C58;
      dword_1BB894 = (int (*)(void))sub_138C87;
      dword_1B920C = (int (*)(_DWORD))sub_144A91;
      dword_1B9208 = (int (*)(_DWORD, _DWORD, _DWORD, _DWORD))sub_144EAC;
      dword_1B9210 = (int (*)(_DWORD))sub_12439D;
      dword_1BB884 = (int)sub_1263FF;
      dword_1BB890 = (int)sub_12641A;
      dword_1BB88C = (int (*)(void))sub_138CB0;
      break;
    default:
      result = v1;
      break;
  }
  return result;
}
// 1B9208: using guessed type int (*dword_1B9208)(_DWORD, _DWORD, _DWORD, _DWORD);
// 1B920C: using guessed type int (*dword_1B920C)(_DWORD);
// 1B9210: using guessed type int (*dword_1B9210)(_DWORD);
// 1BB884: using guessed type int dword_1BB884;
// 1BB888: using guessed type int (*dword_1BB888)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 1BB88C: using guessed type int (*dword_1BB88C)(void);
// 1BB890: using guessed type int dword_1BB890;
// 1BB894: using guessed type int (*dword_1BB894)(void);
// 1BB898: using guessed type int (*dword_1BB898)(_DWORD);
// 1BB89C: using guessed type int (*dword_1BB89C)(void);
// 1BB8A0: using guessed type int (*dword_1BB8A0)(_DWORD);
// 1BB8A4: using guessed type int (*dword_1BB8A4)(_DWORD);
// 1BB8A8: using guessed type int (*dword_1BB8A8)(_DWORD);
// 1BBA52: using guessed type int dword_1BBA52;


//----- (001252C2) --------------------------------------------------------
int sub_1252C2()
{
  if ( sub_145FD2() )
    return 5;
  else
    return -1;
}


//----- (00125300) --------------------------------------------------------
void sub_125300()
{
  switch ( HIWORD(dword_1BBA52) )
  {
    case 0:
      sub_145ADA();
      break;
    case 1:
      sub_145AF9();
      break;
    case 2:
      sub_145B18();
      break;
    case 3:
      sub_145B37();
      break;
    case 5:
      sub_146348();
      break;
    default:
      return;
  }
}
// 1BBA52: using guessed type int dword_1BBA52;


//----- (0012537D) --------------------------------------------------------
int sub_12537D(int a1, int a2)
{
  unsigned int v2; // edx
  int result; // eax

  dword_1BB90C = (int)PoolAlloc_110B89(a1 + 46, a2);
  dword_1BB8FC = (int)PoolAlloc_110B89(a1 + 46, a2);
  sub_127678((char *)dword_1BB90C, dword_18453C, 0);
  v2 = sub_127678((char *)dword_1BB8FC, dword_18453C, 0);
  dword_1BB908 = (int)PoolAlloc_110B89(4 * a2, v2);
  dword_1BB8C0 = (int)PoolAlloc_110B89(4 * a2, v2);
  sub_127678((char *)dword_1BB908, 4 * a2, 0);
  result = dword_1BB8C0;
  sub_127678((char *)dword_1BB8C0, 4 * a2, 0);
  return result;
}
// 18453C: using guessed type int dword_18453C;
// 1BB8C0: using guessed type int dword_1BB8C0;
// 1BB8FC: using guessed type int dword_1BB8FC;
// 1BB908: using guessed type int dword_1BB908;
// 1BB90C: using guessed type int dword_1BB90C;


//----- (0012542A) --------------------------------------------------------
int sub_12542A()
{
  int v1; // [esp+4h] [ebp-4h]

  switch ( HIWORD(dword_1BBA52) )
  {
    case 0:
      v1 = 512;
      break;
    case 1:
      v1 = 512;
      break;
    case 2:
      v1 = 512;
      break;
    case 3:
      v1 = 512;
      break;
    case 5:
      v1 = sub_1460C1();
      break;
    default:
      v1 = 512;
      break;
  }
  return v1;
}
// 1BBA52: using guessed type int dword_1BBA52;


//----- (001254C0) --------------------------------------------------------
int sub_1254C0()
{
  int v1; // [esp+4h] [ebp-4h]

  switch ( HIWORD(dword_1BBA52) )
  {
    case 0:
      v1 = 1;
      break;
    case 1:
      v1 = 1;
      break;
    case 2:
      v1 = 1;
      break;
    case 3:
      v1 = 1;
      break;
    case 5:
      v1 = sub_1461F0();
      break;
    default:
      v1 = 1;
      break;
  }
  return v1;
}
// 1BBA52: using guessed type int dword_1BBA52;


//----- (001255DF) --------------------------------------------------------
// PORT (vlna 21): prezentace celeho obrazu (mode 5). Original kopiroval
// backbuffer dword_1BB90C do VESA okna A0000 po 64KiB bankach: 4x64 + 44 KiB
// = 307200 B = presne 640x480 (sub_138CE0 kopiruje "a3 << 10" bajtu!).
// "v2 += (int)sub_10000" byl IDA artefakt - konstanta 0x10000 (krok banky)
// prelozena jako adresa funkce. Na linearnim framebufferu portu je to jedno
// souvisle kopirovani; bankovaci volani dword_1BB8A4 (no-op) vynechana.
void *sub_1255DF()
{
  // DIAG (vlna 21): jednorazove zalogovat cil/zdroj prezentace - hlaseny stav
  // "result=0, src=0xCD..." znamena volani pred initem nebo prepsany globall
  return sub_138CE0((void *)dword_1BB910[0], (void *)dword_1BB90C, 300);
}
// 1BB90C: using guessed type int dword_1BB90C;
// 1BB910: using guessed type int dword_1BB910[];


//----- (0012567F) --------------------------------------------------------
// PORT (vlna 21): prezentace spinavych useku (mode 5). Tabulka dword_1BB8BC
// je posloupnost dvojic [preskocit, zkopirovat] v DWORDech, ukoncena -1.
// Original vedl zvlast offset v okne (wrap po 0x4000 DWORDech = 64 KiB banka,
// s prepnutim banky pres dword_1BB8A4) a zvlast offset ve zdroji; na
// linearnim framebufferu jsou oba offsety totozne a wrap odpada.
_DWORD *sub_12567F()
{
  _DWORD *result; // eax
  int v4; // [esp+14h] [ebp-2Ch] - index v tabulce
  int v7; // [esp+1Ch] [ebp-24h] - linearni offset v DWORDech
  int v10; // [esp+20h] [ebp-20h] - delka useku v DWORDech
  char *v14; // [esp+38h] [ebp-8h]
  int v15; // [esp+3Ch] [ebp-4h]

  v14 = (char *)dword_1BB910[0];
  v15 = dword_1BB90C;
  {
    static int diagOnce;
    if ( !diagOnce ) { diagOnce = 1; PortDebug_Checkpoint("12567F.first_dst", (int)(intptr_t)v14); }
  }
  v7 = 0;
  v4 = 0;
  while ( 1 )
  {
    result = (_DWORD *)(dword_1BB8BC + 4 * v4);
    if ( *result == -1 )
      break;
    v7 += *result;
    v10 = *(_DWORD *)(dword_1BB8BC + 4 * (v4 + 1));
    sub_1276BD(&v14[4 * v7], (void *)(v15 + 4 * v7), v10);
    v7 += v10;
    v4 += 2;
  }
  return result;
}
// 1BB8BC: using guessed type int dword_1BB8BC;
// 1BB90C: using guessed type int dword_1BB90C;
// 1BB910: using guessed type int dword_1BB910[];


//----- (00125814) --------------------------------------------------------
// PORT (vlna 21): radkovy dirty-present (mode 5, 640x480 = 480 radku po
// 160 DWORDech). Tabulka dword_1BB908 ma 1 DWORD na radek: dolni word =
// prvni spinavy sloupec (DWORD index, -1 = cisty radek), horni word =
// posledni. Original delil obraz na 5 VESA bank a radky prechazejici
// hranici banky kopiroval napevno po kusech (offsety 0x10000/0x20000/
// 0x30000/0x40000; IDA je zkomolila na "sub_10000"/"loc_20000"). Na
// linearnim framebufferu staci jednotna smycka pres vsechny radky.
void *sub_125814()
{
  int16_t v0; // ax
  void *result; // eax
  int i; // [esp+10h] [ebp-10h]
  int v6; // [esp+4h] [ebp-1Ch] - zacatek radku v DWORDech
  char *v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-8h]

  v17 = (char *)dword_1BB910[0];
  v18 = dword_1BB90C;
  result = 0;
  v6 = 0;
  for ( i = 0; i < 480; ++i )
  {
    v0 = *(_WORD *)(4 * i + dword_1BB908);
    if ( v0 != -1 )
      result = sub_1694D9(
        &v17[4 * v0 + 4 * v6],
        (void *)(v18 + 4 * (v0 + v6)),
        (*(int *)(4 * i + dword_1BB908) >> 16) - v0 + 1);
    v6 += 160;
  }
  return result;
}
// 1BB908: using guessed type int dword_1BB908;
// 1BB90C: using guessed type int dword_1BB90C;
// 1BB910: using guessed type int dword_1BB910[];


//----- (00125CE1) --------------------------------------------------------
int sub_125CE1()
{
  int result; // eax

  result = dword_1BB908;
  sub_127678((char *)dword_1BB908, 4 * screenHeight_184538, -1);
  return result;
}
// 1BB908: using guessed type int dword_1BB908;


//----- (00125D18) --------------------------------------------------------
int sub_125D18()
{
  int result; // eax

  result = dword_1BB8C0;
  sub_127678((char *)dword_1BB8C0, 4 * screenHeight_184538, -1);
  return result;
}
// 1BB8C0: using guessed type int dword_1BB8C0;


//----- (00125D4F) --------------------------------------------------------
// Dirty-rectangle flush (dword_1BBA28 == 3 path): for every row copies the
// dirty span [min..max column] from the secondary back buffer dword_1BB8FC into
// the primary back buffer dword_1BB90C (which the mode-5 present sub_1255DF then
// blits to the screen). The per-row spans come from the table dword_1BB8C0
// (low word = first dirty column, high word = last, -1 = clean).
// PORT: the source (var_8) and destination base (var_4) are set from
// dword_1BB8FC / dword_1BB90C at the top of the original (Orion2.exe.asm,
// symbols shifted -0x8000: dword_1B38FC/dword_1B390C). Hex-Rays surfaced the
// source as v7 but dropped the [ebp-4] destination-base local, so sub_1694B7
// read it back as garbage *(ebp-4). Both are now explicit.
int sub_125D4F()
{
  int result; // eax
  int v1; // ebx
  void *v2; // eax
  int v3; // [esp+4h] [ebp-20h]
  int i; // [esp+10h] [ebp-14h]
  int v5; // [esp+14h] [ebp-10h]
  int v6; // [esp+18h] [ebp-Ch]
  int v7; // [esp+1Ch] [ebp-8h]
  int destBase = dword_1BB90C; // [ebp-4] in the original

  v7 = dword_1BB8FC;
  v5 = (HIDWORD(qword_184530) - (__CFSHL__(SHIDWORD(qword_184530) >> 31, 2) + 4 * (SHIDWORD(qword_184530) >> 31))) >> 2;
  v3 = 0;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= screenHeight_184538 )
      break;
    v6 = *(int16_t *)(dword_1BB8C0 + 4 * i);
    if ( v6 != -1 )
    {
      v1 = (*(int *)(4 * i + dword_1BB8C0) >> 16) - v6 + 1;
      v2 = (void *)sub_1694B7(v6 + v3, v1, destBase);
      sub_1276BD(v2, (void *)(v7 + 4 * (v6 + v3)), v1);
    }
    v3 += v5;
  }
  return result;
}
// 184530: using guessed type int64_t qword_184530;
// 1BB8C0: using guessed type int dword_1BB8C0;
// 1BB8FC: using guessed type int dword_1BB8FC;
// 1BB90C: using guessed type int dword_1BB90C;
// 1BB904: using guessed type int dword_1BB904;


//----- (00125E13) --------------------------------------------------------
int sub_125E13(int a1, int a2)
{
  int16_t v2; // ax
  int result; // eax
  int16_t v4; // ax
  int16_t v5; // ax
  int v6; // [esp+0h] [ebp-18h]

  v6 = a1 >> 2;
  if ( dword_1BBA28 == 2 )
  {
    v2 = *(_WORD *)(4 * a2 + dword_1BB908);
    if ( v2 == -1 )
    {
      *(_WORD *)(dword_1BB908 + 4 * a2) = v6;
      result = v6;
      *(_WORD *)(4 * a2 + dword_1BB908 + 2) = v6;
    }
    else if ( v2 <= v6 )
    {
      result = *(int *)(4 * a2 + dword_1BB908) >> 16;
      if ( result < v6 )
      {
        result = v6;
        *(_WORD *)(dword_1BB908 + 4 * a2 + 2) = v6;
      }
    }
    else
    {
      result = v6;
      *(_WORD *)(dword_1BB908 + 4 * a2) = v6;
    }
  }
  else
  {
    v4 = *(_WORD *)(4 * a2 + dword_1BB908);
    if ( v4 == -1 )
    {
      *(_WORD *)(dword_1BB908 + 4 * a2) = v6;
      *(_WORD *)(4 * a2 + dword_1BB908 + 2) = v6;
    }
    else if ( v4 <= v6 )
    {
      if ( *(int *)(4 * a2 + dword_1BB908) >> 16 < v6 )
        *(_WORD *)(dword_1BB908 + 4 * a2 + 2) = v6;
    }
    else
    {
      *(_WORD *)(dword_1BB908 + 4 * a2) = v6;
    }
    v5 = *(_WORD *)(4 * a2 + dword_1BB8C0);
    if ( v5 == -1 )
    {
      *(_WORD *)(dword_1BB8C0 + 4 * a2) = v6;
      result = v6;
      *(_WORD *)(4 * a2 + dword_1BB8C0 + 2) = v6;
    }
    else if ( v5 <= v6 )
    {
      result = *(int *)(4 * a2 + dword_1BB8C0) >> 16;
      if ( result < v6 )
      {
        result = v6;
        *(_WORD *)(dword_1BB8C0 + 4 * a2 + 2) = v6;
      }
    }
    else
    {
      result = v6;
      *(_WORD *)(dword_1BB8C0 + 4 * a2) = v6;
    }
  }
  return result;
}
// 1BB8C0: using guessed type int dword_1BB8C0;
// 1BB908: using guessed type int dword_1BB908;
// 1BBA28: using guessed type int dword_1BBA28;


//----- (00125FFB) --------------------------------------------------------
int sub_125FFB(int a1, int a2, int a3)
{
  int16_t v3; // ax
  int result; // eax
  int16_t v5; // ax
  int16_t v6; // ax
  int v7; // [esp+0h] [ebp-18h]
  int v8; // [esp+0h] [ebp-18h]
  int v9; // [esp+4h] [ebp-14h]
  int v10; // [esp+8h] [ebp-10h]
  int v11; // [esp+8h] [ebp-10h]

  v7 = a1;
  v9 = a2;
  v10 = a3;
  if ( a1 < 0 )
    v7 = 0;
  if ( a2 < 0 )
    v9 = 0;
  if ( a3 >= *(int *)((char *)&dword_184532 + 2) )
    v10 = *(int *)((char *)&dword_184532 + 2) - 1;
  if ( v9 >= *(int *)((char *)&dword_184536 + 2) )
    v9 = *(int *)((char *)&dword_184536 + 2) - 1;
  v8 = v7 >> 2;
  v11 = v10 >> 2;
  if ( dword_1BBA28 == 2 )
  {
    v3 = *(_WORD *)(4 * v9 + dword_1BB908);
    if ( v3 == -1 )
    {
      *(_WORD *)(dword_1BB908 + 4 * v9) = v8;
      result = v11;
      *(_WORD *)(4 * v9 + dword_1BB908 + 2) = v11;
    }
    else
    {
      if ( v3 > v8 )
        *(_WORD *)(dword_1BB908 + 4 * v9) = v8;
      result = *(int *)(4 * v9 + dword_1BB908) >> 16;
      if ( result < v11 )
      {
        result = v11;
        *(_WORD *)(dword_1BB908 + 4 * v9 + 2) = v11;
      }
    }
  }
  else
  {
    v5 = *(_WORD *)(4 * v9 + dword_1BB908);
    if ( v5 == -1 )
    {
      *(_WORD *)(dword_1BB908 + 4 * v9) = v8;
      *(_WORD *)(4 * v9 + dword_1BB908 + 2) = v11;
    }
    else
    {
      if ( v5 > v8 )
        *(_WORD *)(dword_1BB908 + 4 * v9) = v8;
      if ( *(int *)(4 * v9 + dword_1BB908) >> 16 < v11 )
        *(_WORD *)(dword_1BB908 + 4 * v9 + 2) = v11;
    }
    v6 = *(_WORD *)(4 * v9 + dword_1BB8C0);
    if ( v6 == -1 )
    {
      *(_WORD *)(dword_1BB8C0 + 4 * v9) = v8;
      result = v11;
      *(_WORD *)(4 * v9 + dword_1BB8C0 + 2) = v11;
    }
    else
    {
      if ( v6 > v8 )
        *(_WORD *)(dword_1BB8C0 + 4 * v9) = v8;
      result = *(int *)(4 * v9 + dword_1BB8C0) >> 16;
      if ( result < v11 )
      {
        result = v11;
        *(_WORD *)(dword_1BB8C0 + 4 * v9 + 2) = v11;
      }
    }
  }
  return result;
}
// 184532: using guessed type int dword_184532;
// 184536: using guessed type int dword_184536;
// 1BB8C0: using guessed type int dword_1BB8C0;
// 1BB908: using guessed type int dword_1BB908;
// 1BBA28: using guessed type int dword_1BBA28;


//----- (00126224) --------------------------------------------------------
int sub_126224( int a1, int a2, int a3, int a4)
{
  int result; // eax
  int j; // [esp+2Ch] [ebp-38h]
  int v6; // [esp+30h] [ebp-34h]
  int v7; // [esp+34h] [ebp-30h]
  int v8; // [esp+3Ch] [ebp-28h]
  int v9; // [esp+40h] [ebp-24h]
  int v10; // [esp+44h] [ebp-20h]
  int v11; // [esp+48h] [ebp-1Ch]
  int v12; // [esp+4Ch] [ebp-18h]
  int i; // [esp+50h] [ebp-14h]
  int16_t v14; // [esp+54h] [ebp-10h]
  int16_t v15; // [esp+58h] [ebp-Ch]
  int16_t v16; // [esp+5Ch] [ebp-8h]
  int v17; // [esp+5Ch] [ebp-8h]
  int16_t v18; // [esp+60h] [ebp-4h]
  int v19; // [esp+60h] [ebp-4h]

  v18 = a1;
  v15 = a2;
  v16 = a3;
  v14 = a4;
  v11 = dword_1BB910;
  v9 = dword_1BB90C;
  v10 = 5 * (dword_1BBA64 >> 16);
  if ( a1 < 0 )
    v18 = 0;
  if ( a2 < 0 )
    v15 = 0;
  if ( a3 >= *(int *)((char *)&dword_184532 + 2) )
    v16 = HIWORD(dword_184532) - 1;
  if ( a4 >= *(int *)((char *)&dword_184536 + 2) )
    v14 = HIWORD(dword_184536) - 1;
  v19 = v18 >> 2;
  v17 = v16 >> 2;
  v7 = ((*(int *)((char *)&dword_184532 + 2)
       - (__CFSHL__(*(int *)((char *)&dword_184532 + 2) >> 31, 2)
        + 4 * (*(int *)((char *)&dword_184532 + 2) >> 31))) >> 2)
     - ((int16_t)v17
      - (int16_t)v19
      + 1);
  v8 = (int16_t)v19
     + ((*(int *)((char *)&dword_184532 + 2) * v15
       - (__CFSHL__((*(int *)((char *)&dword_184532 + 2) * v15) >> 31, 2)
        + 4 * ((*(int *)((char *)&dword_184532 + 2) * v15) >> 31))) >> 2);
  v12 = v8 % 0x4000;
  v6 = (v8 - (__CFSHL__(v8 >> 31, 14) + (v8 >> 31 << 14))) >> 14;
  dword_1BB8A4(v6 + v10);
  for ( i = v15; ; ++i )
  {
    result = v14;
    if ( v14 < i )
      break;
    for ( j = (int16_t)v19; (int16_t)v17 >= j; ++j )
    {
      *(_DWORD *)(v11 + 4 * v12++) = *(_DWORD *)(v9 + 4 * v8++);
      if ( v12 >= 0x4000 )
      {
        dword_1BB8A4(++v6 + v10);
        v12 -= 0x4000;
      }
    }
    v12 += v7;
    v8 += v7;
    if ( v12 >= 0x4000 )
    {
      dword_1BB8A4(++v6 + v10);
      v12 -= 0x4000;
    }
  }
  return result;
}
// 184532: using guessed type int dword_184532;
// 184536: using guessed type int dword_184536;
// 1BB8A4: using guessed type int (*dword_1BB8A4)(_DWORD);
// 1BB90C: using guessed type int dword_1BB90C;
// 1BB910: using guessed type int dword_1BB910;
// 1BBA64: using guessed type int dword_1BBA64;


//----- (001263FF) --------------------------------------------------------
int sub_1263FF()
{
  return dword_1BB88C();
}
// 1BB88C: using guessed type int (*dword_1BB88C)(void);


//----- (0012641A) --------------------------------------------------------
int sub_12641A()
{
  return dword_1BB8A4(*(int *)((char *)&dword_1BBA2C + 2) >> 16);
}
// 1BB8A4: using guessed type int (*dword_1BB8A4)(_DWORD);
// 1BBA2C: using guessed type int dword_1BBA2C;


//----- (0012643D) --------------------------------------------------------
void __noreturn sub_12643D(int a1, int a2)
{
  unsigned int v2; // eax
  int v3; // [esp-4h] [ebp-Ch]

  sub_113DBD();
  v3 = sub_111090();
  v2 = sub_110F89();
  printf("Linear Free = %dk   Dos Free = %dk\n", v2, v3);
  exit(1, a2);
}
// 13F2D1: using guessed type _DWORD printf(char *, ...);


//----- (00126487) --------------------------------------------------------
void __noreturn sub_126487(char *a1, int a2)
{
  sub_113DBD();
  printf("%s\n", a1);
  exit(1, a2);
}
// 113DBD: using guessed type int sub_113DBD(void);
// 13F2D1: using guessed type _DWORD printf(char *, ...);


//----- (00126ABD) --------------------------------------------------------
_DWORD *sub_126ABD(int a1, int a2)
{
  return sub_126CEB(a1, a2, 0, 0);
}


//----- (00126AFD) --------------------------------------------------------
_DWORD *sub_126AFD(int a1, int a2, int a3)
{
  return sub_126CEB(a1, a2, a3, 1);
}


//----- (00126B42) --------------------------------------------------------
_DWORD *sub_126B42(int a1, int a2, int a3)
{
  return sub_126CEB(a1, a2, a3, 2);
}


//----- (00126BDD) --------------------------------------------------------
_DWORD *sub_126BDD(int a1, int a2, int a3, unsigned int a4, unsigned int a5, int a6)
{
  return sub_126F3B(a1, a2, a3, 1, a4, a5, a6);
}


//----- (00126C37) --------------------------------------------------------
_DWORD *sub_126C37(int a1, int a2, int a3, unsigned int a4, unsigned int a5, int a6)
{
  return sub_126F3B(a1, a2, a3, 2, a4, a5, a6);
}


//----- (00126C91) --------------------------------------------------------
_DWORD *sub_126C91(int a1, int a2, int a3, unsigned int a4, unsigned int a5, int a6)
{
  return sub_126F3B(a1, a2, a3, 3, a4, a5, a6);
}


//----- (00126CEB) --------------------------------------------------------
_DWORD *sub_126CEB(int a1, int a2, int a3, int a4)
{
  int v4; // edx
  _BYTE v6[60]; // [esp+0h] [ebp-80h] BYREF
  int v7; // [esp+3Ch] [ebp-44h]
  int v8; // [esp+40h] [ebp-40h]
  int v9; // [esp+44h] [ebp-3Ch]
  int v10; // [esp+50h] [ebp-30h]
  int v11; // [esp+68h] [ebp-18h]
  int v12; // [esp+6Ch] [ebp-14h]
  int v13; // [esp+70h] [ebp-10h]
  _DWORD *v14; // [esp+78h] [ebp-8h]

  v7 = a1;
  v10 = a2;
  v8 = a3;
  v9 = a4;
  if ( a2 < 0 )
    sub_1273DC(v7, 4u, v10, a4);
  if ( !dword_184576 || stricmp(v7, &unk_1BC270) )
  {
    if ( dword_184576 )
      fclose(dword_1BC26C);
    strcpy(&unk_1BC270, v7);
    dword_1BC26C = fopen(v7, aRb_3);
    if ( !dword_1BC26C )
    {
      if ( !byte_184544[0] )
        sub_1273DC(v7, 1u, v10, a4);
      strcpy(v6, byte_184544);
      strcat(v6, &unk_1BC270);
      dword_1BC26C = fopen(v6, aRb_3);
      if ( !dword_1BC26C )
        sub_1273DC(v7, 1u, v10, a4);
    }
    a4 = dword_1BC26C;
    fread(&unk_1BBA6C, 2048, 1, dword_1BC26C);
    if ( (uint16_t)word_1BBA6E != 65197 )
      sub_1273DC(v7, 7u, v10, a4);
    dword_184576 = 1;
  }
  if ( (int)unk_1BBA6A >> 16 <= v10 )
    sub_1273DC(v7, 8u, v10, a4);
  v11 = dword_1BBA74[v10];
  v12 = dword_1BBA78[v10];
  v13 = v12 - v11;
  v4 = v11;
    // DECOMP_TODO (vyreseno ve vlne 07): fseek() melo 0 parametru - stejny
    // Hex-Rays artefakt jako jinde. Vzor je jasny (LBX archiv format):
    // prave precteny 2048bajtovy header obsahuje tabulku start/end offsetu
    // zaznamu (dword_1BBA74[]/dword_1BBA78[]), prave spocitany zacatecni
    // offset zaznamu se seekuje na stejnem handle, ktery cetl header.
  fseek(dword_1BC26C, v11, SEEK_SET);
  switch ( v9 )
  {
    case 0:
      v14 = sub_111131(v13, v4);
      if ( !v14 )
        sub_1273DC(v7, 3u, v10, a4);
      goto LABEL_28;
    case 1:
      v14 = sub_111188(v8, v13);
      if ( !v14 )
        sub_1273DC(v7, 5u, v10, a4);
      goto LABEL_28;
    case 2:
      v14 = sub_1111D6(v8, v13);
      if ( !v14 )
        sub_1273DC(v7, 5u, v10, a4);
      goto LABEL_28;
    case 4:
      return 0;
    default:
LABEL_28:
      fread(v14, v13, 1, dword_1BC26C);
      return v14;
  }
}
// 12685D: using guessed type int fopen(_DWORD, _DWORD);
// 12697A: using guessed type int fclose(_DWORD);
// 1288DB: using guessed type int fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 13C896: using guessed type int stricmp(_DWORD, _DWORD);
// 13F220: using guessed type int strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184576: using guessed type int dword_184576;
// 1BBA6E: using guessed type int16_t word_1BBA6E;
// 1BBA74: using guessed type int dword_1BBA74[];
// 1BBA78: using guessed type int dword_1BBA78[509];
// 1BC26C: using guessed type int dword_1BC26C;


//----- (00126F3B) --------------------------------------------------------
_DWORD *sub_126F3B(int a1, int a2, int a3, int a4, unsigned int a5, unsigned int a6, int a7)
{
  int v7; // ecx
  _DWORD *result; // eax
  _BYTE v9[60]; // [esp+0h] [ebp-88h] BYREF
  int v10; // [esp+3Ch] [ebp-4Ch]
  _DWORD *v11; // [esp+40h] [ebp-48h]
  int v12; // [esp+44h] [ebp-44h]
  int v13; // [esp+4Ch] [ebp-3Ch]
  int v14; // [esp+50h] [ebp-38h]
  int v15; // [esp+64h] [ebp-24h]
  int v16; // [esp+6Ch] [ebp-1Ch]
  _DWORD *v17; // [esp+7Ch] [ebp-Ch]
  int v18; // [esp+80h] [ebp-8h] BYREF
  int v19; // [esp+84h] [ebp-4h] BYREF

  v12 = a1;
  v10 = a2;
  v11 = (_DWORD *)a3;
  v14 = a4;
  if ( a2 < 0 )
    sub_1273DC(v12, 4u, v10, a4);
  if ( !dword_184576 || stricmp(v12, &unk_1BC270) )
  {
    if ( dword_184576 )
      fclose(dword_1BC26C);
    strcpy(&unk_1BC270, v12);
    dword_1BC26C = fopen(v12, aRb_3);
    if ( !dword_1BC26C )
    {
      if ( !byte_184544[0] )
        sub_1273DC(v12, 1u, v10, a4);
      strcpy(v9, byte_184544);
      strcat(v9, &unk_1BC270);
      dword_1BC26C = fopen(v9, aRb_3);
      if ( !dword_1BC26C )
        sub_1273DC(v12, 1u, v10, a4);
    }
    a4 = dword_1BC26C;
    fread(&unk_1BBA6C, 2048, 1, dword_1BC26C);
    if ( (uint16_t)word_1BBA6E != 65197 )
      sub_1273DC(v12, 7u, v10, a4);
    dword_184576 = 1;
  }
  if ( (int)unk_1BBA6A >> 16 <= v10 )
    sub_1273DC(v12, 8u, v10, a4);
  v16 = dword_1BBA74[v10];
  v13 = dword_1BBA78[v10];
  v15 = v13 - v16;
    // DECOMP_TODO (vyreseno ve vlne 07): fseek() melo 0 parametru - stejny
    // Hex-Rays artefakt jako jinde. Vzor je jasny (LBX archiv format):
    // prave precteny 2048bajtovy header obsahuje tabulku start/end offsetu
    // zaznamu (dword_1BBA74[]/dword_1BBA78[]), prave spocitany zacatecni
    // offset zaznamu se seekuje na stejnem handle, ktery cetl header.
  fseek(dword_1BC26C, v16, SEEK_SET);
  fread(&v18, 2, 1, dword_1BC26C);
  v7 = dword_1BC26C;
  fread(&v19, 2, 1, dword_1BC26C);
  if ( a6 == -1 )
    a6 = v18 - a5;
  if ( (uint16_t)v18 <= a5 )
    sub_1273DC(v12, 0xAu, v10, v7);
  if ( (_WORD)v19 != a7 )
    sub_1273DC(v12, 9u, v10, v7);
  // DECOMP_TODO - NIZKA JISTOTA (vlna 07): fseek() melo 0 parametru. Na
  // rozdil od 4 ostatnich fseek v teto funkci tu neni primy "table[idx]"
  // vzor. Nejlepsi dostupna hypoteza: soubor je prave na pozici "v16 + 4"
  // (zacatek zaznamu + 2x 2bajtove pole v18/v19 prave precteny), a dalsi
  // krok pravdepodobne preskakuje na konkretni snimek "a5" (pocatecni
  // index) o velikosti "v19" kazdy - proto "v16 + 4 + a5 * v19". POTREBUJE
  // OVERENI - spatny odhad by zpusobil tiche cteni spatnych dat, ne pad.
  fseek(dword_1BC26C, v16 + 4 + a5 * (uint16_t)v19, SEEK_SET);
  v15 = a6 * (uint16_t)v19;
  switch ( v14 )
  {
    case 0:
      v17 = sub_111131(v15, a6 * (uint16_t)v19);
      if ( !v17 )
        sub_1273DC(v12, 3u, v10, v7);
      return result;
    case 1:
      v17 = sub_111188((int)v11, v15);
      if ( !v17 )
        sub_1273DC(v12, 5u, v10, v7);
      return result;
    case 2:
      v17 = sub_1111D6((int)v11, v15);
      if ( !v17 )
        sub_1273DC(v12, 5u, v10, v7);
      return result;
    case 3:
      v17 = v11;
      break;
    default:
      break;
  }
  fread(v17, v15, 1, dword_1BC26C);
  return v17;
}
// 12685D: using guessed type int fopen(_DWORD, _DWORD);
// 12697A: using guessed type int fclose(_DWORD);
// 1288DB: using guessed type int fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 13C896: using guessed type int stricmp(_DWORD, _DWORD);
// 13F220: using guessed type int strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184576: using guessed type int dword_184576;
// 1BBA6E: using guessed type int16_t word_1BBA6E;
// 1BBA74: using guessed type int dword_1BBA74[];
// 1BBA78: using guessed type int dword_1BBA78[509];
// 1BC26C: using guessed type int dword_1BC26C;


//----- (00127233) --------------------------------------------------------
int sub_127233(int a1, int a2, int a3, int a4)
{
  _BYTE v5[60]; // [esp+0h] [ebp-80h] BYREF
  int v6; // [esp+3Ch] [ebp-44h]
  int v7; // [esp+50h] [ebp-30h]
  int v8; // [esp+68h] [ebp-18h]
  int v9; // [esp+6Ch] [ebp-14h]
  int v10; // [esp+70h] [ebp-10h]
  int v11; // [esp+74h] [ebp-Ch] BYREF

  v6 = a1;
  v7 = a2;
  if ( a2 < 0 )
    sub_1273DC(v6, 4u, v7, a4);
  if ( !dword_184576 || stricmp(v6, &unk_1BC270) )
  {
    if ( dword_184576 )
      fclose(dword_1BC26C);
    strcpy(&unk_1BC270, v6);
        // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    dword_1BC26C = fopen(v6, aRb);
    if ( !dword_1BC26C )
    {
      if ( !byte_184544[0] )
        sub_1273DC(v6, 1u, v7, a4);
      strcpy(v5, byte_184544);
      strcat(v5, &unk_1BC270);
          // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    dword_1BC26C = fopen(v5, aRb);
      if ( !dword_1BC26C )
        sub_1273DC(v6, 1u, v7, a4);
    }
    a4 = dword_1BC26C;
    fread(&unk_1BBA6C, 2048, 1, dword_1BC26C);
    if ( (uint16_t)word_1BBA6E != 65197 )
      sub_1273DC(v6, 7u, v7, a4);
    dword_184576 = 1;
  }
  if ( (int)unk_1BBA6A >> 16 <= v7 )
    sub_1273DC(v6, 8u, v7, a4);
  v8 = dword_1BBA74[v7];
  v9 = dword_1BBA78[v7];
  v10 = v9 - v8;
    // DECOMP_TODO (vyreseno ve vlne 07): fseek() melo 0 parametru - stejny
    // Hex-Rays artefakt jako jinde. Vzor je jasny (LBX archiv format):
    // prave precteny 2048bajtovy header obsahuje tabulku start/end offsetu
    // zaznamu (dword_1BBA74[]/dword_1BBA78[]), prave spocitany zacatecni
    // offset zaznamu se seekuje na stejnem handle, ktery cetl header.
  fseek(dword_1BC26C, v8, SEEK_SET);
  fread(&v11, 2, 1, dword_1BC26C);
  return v11;
}
// 12697A: using guessed type int fclose(_DWORD);
// 1288DB: using guessed type int fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 13C896: using guessed type int stricmp(_DWORD, _DWORD);
// 13F220: using guessed type int strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184576: using guessed type int dword_184576;
// 1BBA6E: using guessed type int16_t word_1BBA6E;
// 1BBA74: using guessed type int dword_1BBA74[];
// 1BBA78: using guessed type int dword_1BBA78[509];
// 1BC26C: using guessed type int dword_1BC26C;


//----- (001273DC) --------------------------------------------------------
void __noreturn sub_1273DC(int a1, unsigned int a2, int a3, int a4)
{
  char *v4; // edx
  char v5[120]; // [esp+0h] [ebp-98h] BYREF
  _BYTE v6[20]; // [esp+78h] [ebp-20h] BYREF
  int v7; // [esp+8Ch] [ebp-Ch]
  unsigned int v8; // [esp+90h] [ebp-8h]
  int v9 = 0; // [esp+94h] [ebp-4h]

  v7 = a1;
  v8 = a2;
  strcpy(v5, a1);
  strcat(v5, aEntry);
  itoa(v9, v6, 10, a4);
  strcat(v5, v6);
  v4 = asc_17A680;
  strcat(v5, asc_17A680);
  if ( v8 < 5 )
  {
    if ( v8 < 2 )
    {
      if ( v8 == 1 )
      {
        v4 = aCouldNotBeFoun;
        strcat(v5, aCouldNotBeFoun);
      }
    }
    else if ( v8 <= 2 )
    {
      v4 = aHasBeenCorrupt;
      strcat(v5, aHasBeenCorrupt);
    }
    else if ( v8 <= 3 )
    {
      strcpy(v5, "Insufficient memory. You need at least 575K free. Try removing all TSR's.");
    }
    else
    {
      v4 = aHasAnImproperE;
      strcat(v5, aHasAnImproperE);
    }
  }
  else if ( v8 <= 5 )
  {
    v4 = aFailedToReload;
    strcat(v5, aFailedToReload);
  }
  else if ( v8 < 9 )
  {
    if ( v8 >= 7 )
    {
      if ( v8 <= 7 )
      {
        v4 = aIsNotAnLbxFile;
        strcat(v5, aIsNotAnLbxFile);
      }
      else
      {
        v4 = aExceedsNumberO;
        strcat(v5, aExceedsNumberO);
      }
    }
  }
  else if ( v8 <= 9 )
  {
    v4 = aHasAnIncorrect;
    strcat(v5, aHasAnIncorrect);
  }
  else if ( v8 <= 0xA )
  {
    v4 = aExceedsNumberO_0;
    strcat(v5, aExceedsNumberO_0);
  }
  else if ( v8 == 16 )
  {
    v4 = aVgaFileAnimati;
    strcat(v5, aVgaFileAnimati);
  }
  sub_126487(v5, (int)v4);
}
// 1288C0: using guessed type int itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 13F220: using guessed type int strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);


//----- (00127593) --------------------------------------------------------
int sub_127593(int a1)
{
  int result; // eax
  int i; // [esp+4h] [ebp-8h]

  strcpy(byte_184544, a1);
  for ( i = 0; i < 100 && byte_184544[i]; ++i )
    ;
  result = *((uint8_t *)&dword_184540 + i + 3);
  if ( result != 92 )
    return strcat(byte_184544, asc_17A7E7);
  return result;
}
// 13F220: using guessed type int strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184540: using guessed type int dword_184540;


//----- (0012760B) --------------------------------------------------------
int sub_12760B(char *a1)
{
  int v1; // edx
  char v2; // cl
  int v3; // ebx
  int v4; // ebx

  while ( 1 )
  {
    v1 = IsTable[(uint8_t)(*a1 + 1)] & 2;
    if ( (IsTable[(uint8_t)(*a1 + 1)] & 2) == 0 )
      break;
    ++a1;
  }
  v2 = *a1;
  LOBYTE(v1) = *a1;
  if ( v1 == 43 || v1 == 45 )
    ++a1;
  v3 = 0;
  while ( (IsTable[(uint8_t)(*a1 + 1)] & 0x20) != 0 )
  {
    v4 = (uint8_t)*a1++ + 10 * v3;
    v3 = v4 - 48;
  }
  if ( v2 == 45 )
    return -v3;
  return v3;
}


//----- (00127678) --------------------------------------------------------
unsigned int sub_127678(char *a1, unsigned int result, int a3)
{
  char *v3; // edi
  int16_t v4; // cx
  int v5; // ebx
  char *v6; // edi

  if ( result )
  {
    v3 = a1;
    a3 = (uint8_t)a3;
    BYTE1(a3) = a3;
    v4 = a3;
    v5 = a3 << 16;
    LOWORD(v5) = v4;
    if ( ((uint8_t)a1 & 1) != 0 )
    {
      *a1 = v4;
      v3 = a1 + 1;
      --result;
    }
    memset32(v3, v5, result >> 2);
    v6 = &v3[4 * (result >> 2)];
    if ( (result & 3) != 0 )
      memset(v6, v4, result & 3);
  }
  return result;
}


//----- (001276AE) --------------------------------------------------------
void *sub_1276AE(void *result, void *a2, unsigned int a3)
{
  qmemcpy(result, a2, 4 * (a3 >> 2));
  return result;
}


//----- (001276BD) --------------------------------------------------------
void *sub_1276BD(void *result, void *a2, int a3)
{
  qmemcpy(result, a2, 4 * a3);
  return result;
}


//----- (001276F0) --------------------------------------------------------
// Bit test: returns bit number a2 of the bit-array at base a1 (0 or 1).
// Original asm used pusha/popa around the computation, so it stashed the
// result in a global (dword_1276EC) and reloaded it into eax after popa
// restored the registers. That global was purely a register-preservation
// artifact of the pusha/popa trick and is read nowhere else, so in C we
// simply return the bit directly. Hex-Rays had mis-modeled this as
// "dword_1276EC = bit; return 0;" — i.e. every caller's bit test was
// silently reading 0. Verified against Orion2.exe.asm (sub_1276F0).
int sub_1276F0(int a1, unsigned int a2)
{
  return (*(uint8_t *)(a1 + (a2 >> 3)) >> (a2 & 7)) & 1;
}


//----- (00127712) --------------------------------------------------------
int sub_127712(int result, unsigned int a2)
{
  *(_BYTE *)(result + (a2 >> 3)) |= 1 << (a2 & 7);
  return result;
}


//----- (0012772A) --------------------------------------------------------
int sub_12772A(int result, unsigned int a2)
{
  *(_BYTE *)(result + (a2 >> 3)) &= ~(uint8_t)(1 << (a2 & 7));
  return result;
}


//----- (00127776) --------------------------------------------------------
unsigned int sub_127776(_BYTE *a1, unsigned int result)
{
  void *v2; // edi

  if ( result )
  {
    v2 = a1;
    if ( ((uint8_t)a1 & 1) != 0 )
    {
      *a1 = 0;
      v2 = a1 + 1;
      --result;
    }
    memset(v2, 0, result);
  }
  return result;
}


//----- (0012779E) --------------------------------------------------------
_BYTE *sub_12779E(_BYTE *result, _BYTE *a2, unsigned int a3)
{
  if ( ((uint8_t)a2 & 1) != 0 && ((uint8_t)result & 1) != 0 )
  {
    *result = *a2;
    qmemcpy(result + 1, a2 + 1, a3 - 1);
  }
  else
  {
    qmemcpy(result, a2, a3);
  }
  return result;
}


//----- (001277DE) --------------------------------------------------------
int64_t sub_1277DE(int64_t a1, unsigned int a2)
{
  int64_t v2; // rdi
  unsigned int v3; // ecx
  char v4; // al
  char v5; // ah
  unsigned int j; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  char v11; // al
  char v12; // ah
  unsigned int v14; // ebx
  unsigned int i; // ecx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  char v19; // al
  char v20; // ah
  int64_t v21; // [esp-20h] [ebp-20h]

  v21 = a1;
  v2 = a1;
  if ( (a1 & 0x100000000LL) != 0 )
  {
    if ( (a1 & 1) != 0 )
    {
      HIDWORD(v2) = HIDWORD(a1) + 1;
      BYTE1(a1) = *(_BYTE *)a1;
      *(_BYTE *)v2 = *(_BYTE *)HIDWORD(a1);
      LODWORD(v2) = v2 + 1;
      *(_BYTE *)HIDWORD(a1) = BYTE1(a1);
      v14 = a2 - 1;
      for ( i = v14 >> 2; i; --i )
      {
        v16 = *(_DWORD *)HIDWORD(v2);
        HIDWORD(v2) += 4;
        v17 = *(_DWORD *)v2;
        *(_DWORD *)v2 = v16;
        LODWORD(v2) = v2 + 4;
        *(_DWORD *)(HIDWORD(v2) - 4) = v17;
      }
      v18 = v14 & 3;
      if ( (v14 & 3) != 0 )
      {
        do
        {
          v19 = *(_BYTE *)HIDWORD(v2);
          ++HIDWORD(v2);
          v20 = *(_BYTE *)v2;
          *(_BYTE *)v2 = v19;
          LODWORD(v2) = v2 + 1;
          *(_BYTE *)(HIDWORD(v2) - 1) = v20;
          --v18;
        }
        while ( v18 );
      }
      return v21;
    }
    goto LABEL_5;
  }
  if ( (a1 & 1) != 0 )
  {
LABEL_5:
    v3 = a2;
    do
    {
      v4 = *(_BYTE *)HIDWORD(v2);
      ++HIDWORD(v2);
      v5 = *(_BYTE *)v2;
      *(_BYTE *)v2 = v4;
      LODWORD(v2) = v2 + 1;
      *(_BYTE *)(HIDWORD(v2) - 1) = v5;
      --v3;
    }
    while ( v3 );
    return v21;
  }
  for ( j = a2 >> 2; j; --j )
  {
    v8 = *(_DWORD *)HIDWORD(v2);
    HIDWORD(v2) += 4;
    v9 = *(_DWORD *)v2;
    *(_DWORD *)v2 = v8;
    LODWORD(v2) = v2 + 4;
    *(_DWORD *)(HIDWORD(v2) - 4) = v9;
  }
  v10 = a2 & 3;
  if ( (a2 & 3) == 0 )
    return v21;
  do
  {
    v11 = *(_BYTE *)HIDWORD(v2);
    ++HIDWORD(v2);
    v12 = *(_BYTE *)v2;
    *(_BYTE *)v2 = v11;
    LODWORD(v2) = v2 + 1;
    *(_BYTE *)(HIDWORD(v2) - 1) = v12;
    --v10;
  }
  while ( v10 );
  return v21;
}
// 1277DE: could not find valid save-restore pair for edi
// 1277DE: could not find valid save-restore pair for esi


//----- (00127880) --------------------------------------------------------
int sub_127880()
{
  /* __asm: int     2Fh; - Multiplex - MS WINDOWS - MS Windows 3.1 - IDENTIFY WINDOWS VERSION AND TYPE */ DECOMP_TODO("inline asm");
  return 0;
}


//----- (001278A3) --------------------------------------------------------
int sub_1278A3()
{
  int i; // [esp+4h] [ebp-Ch]
  int j; // [esp+8h] [ebp-8h]

  for ( i = 0; i < 50; ++i )
  {
    for ( j = 0; j < 410; ++j )
      *(_DWORD *)(11 * j + 4530 * i + dword_1BC28C + 19) = 0;
  }
  dword_184580 = 0;
  return 1;
}
// 184580: using guessed type int dword_184580;
// 1BC28C: using guessed type int dword_1BC28C;


//----- (00127969) --------------------------------------------------------
int sub_127969()
{
  int result; // eax

  if ( dword_1BC280 )
  {
    nfree(dword_1BC280);
    result = nfree(dword_1BC28C);
    dword_1BC280 = 0;
  }
  return result;
}
// 13CAF6: using guessed type int nfree(_DWORD);
// 1BC280: using guessed type int dword_1BC280;
// 1BC28C: using guessed type int dword_1BC28C;


//----- (001279AF) --------------------------------------------------------
_DWORD *sub_1279AF(int a1, int a2)
{
  int v3; // [esp+0h] [ebp-1Ch]
  _DWORD *v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  int j; // [esp+14h] [ebp-8h]

  if ( a1 - 226488 <= 0 )
    sub_126487(aNotEnoughSpace, a2);
  v3 = a1 - 226500;
  v5 = a1 - 226500;
  if ( ((a1 - 226500) & 3) != 0 )
    v5 = 4 * (v3 >> 2) + 4;
  v4 = (_DWORD *)sub_110DFE(v5 + 12);
  if ( !v4 )
    sub_110EC3(v3, a2);
  *v4 = 0;
  v4[1] = v3;
  v4[2] = 0;
  dword_1BC28C = sub_110DFE(226500);
  if ( !dword_1BC28C )
    sub_110EC3(226500, (int)v4);
  word_1BC290 = 0;
  for ( i = 0; i < 50; ++i )
  {
    for ( j = 0; j < 410; ++j )
    {
      *(_BYTE *)(11 * j + 4530 * i + dword_1BC28C + 16) = 0;
      *(_DWORD *)(11 * j + dword_1BC28C + 4530 * i + 19) = 0;
      *(_WORD *)(4530 * i + dword_1BC28C + 11 * j + 17) = 0;
    }
    *(_DWORD *)(dword_1BC28C + 4530 * i + 4526) = 0;
  }
  dword_1BC280 = (int)v4;
  dword_1BC288 = (int)(v4 + 3);
  dword_1BC284 = v3;
  return v4 + 3;
}
// 1BC280: using guessed type int dword_1BC280;
// 1BC284: using guessed type int dword_1BC284;
// 1BC288: using guessed type int dword_1BC288;
// 1BC28C: using guessed type int dword_1BC28C;
// 1BC290: using guessed type int16_t word_1BC290;


//----- (00127C27) --------------------------------------------------------
int sub_127C27(int a1, int a2, int a3)
{
  int v3; // edx
  int v6; // [esp+4h] [ebp-1Ch]
  int i; // [esp+Ch] [ebp-14h]
  int j; // [esp+Ch] [ebp-14h]
  uint8_t v10; // [esp+18h] [ebp-8h]
  char v11; // [esp+1Ch] [ebp-4h]

  v6 = a2;
  if ( a3 != dword_1BC288 )
    sub_126487(aErrorCacheCorr, a2);
  if ( *(_DWORD *)(a3 - 12 + 4) != dword_1BC284 )
    sub_126487(aErrorCacheCorr, a2);
  v11 = 0;
  for ( i = 0; *(int *)((char *)&dword_1BC28C + 2) >> 16 > i; ++i )
  {
    a2 = 4530 * i + dword_1BC28C;
    if ( !stricmp(a1, a2) )
    {
      v11 = 1;
      v10 = i;
      break;
    }
  }
  if ( v11 == 1 )
  {
    for ( j = 0; j < *(_DWORD *)(4530 * v10 + dword_1BC28C + 4526); ++j )
    {
      if ( *(int *)(4530 * v10 + dword_1BC28C + 11 * j + 15) >> 16 == v6 )
      {
        if ( *(_BYTE *)(4530 * v10 + dword_1BC28C + 11 * j + 16) == 1 )
        {
          *(_DWORD *)(dword_1BC28C + 4530 * v10 + 11 * j + 19) = ++dword_184580;
        }
        else
        {
          *(_DWORD *)(11 * j + 4530 * v10 + dword_1BC28C + 19) = ++dword_184580;
          *(_DWORD *)(11 * j + 4530 * v10 + dword_1BC28C + 23) = sub_12816C(a1, v6, a3, (int *)2);
          *(_BYTE *)(4530 * v10 + dword_1BC28C + 11 * j + 16) = 1;
        }
        return *(_DWORD *)(4530 * v10 + dword_1BC28C + 11 * j + 23);
      }
    }
    v3 = 4530 * v10;
    if ( *(_DWORD *)(v3 + dword_1BC28C + 4526) + 1 >= 410 )
      sub_126487(aMaxBufferSegsW, v3);
    ++dword_184580;
    *(_WORD *)(4530 * v10 + dword_1BC28C + 11 * *(_DWORD *)(4530 * v10 + dword_1BC28C + 4526) + 17) = v6;
    *(_DWORD *)(11 * *(_DWORD *)(dword_1BC28C + 4530 * v10 + 4526) + dword_1BC28C + 4530 * v10 + 19) = dword_184580;
    *(_DWORD *)(4530 * v10 + dword_1BC28C + 11 * *(_DWORD *)(dword_1BC28C + 4530 * v10 + 4526) + 23) = sub_12816C(a1, v6, a3, (int *)2);
    *(_BYTE *)(11 * *(_DWORD *)(4530 * v10 + dword_1BC28C + 4526) + dword_1BC28C + 4530 * v10 + 16) = 1;
    return *(_DWORD *)(11 * (*(_DWORD *)(dword_1BC28C + 4530 * v10 + 4526))++ + dword_1BC28C + 4530 * v10 + 23);
  }
  else
  {
    if ( (*(int *)((char *)&dword_1BC28C + 2) >> 16) + 1 >= 50 )
      sub_126487(aMaxFileBufferC, a2);
    ++dword_184580;
    strcpy(4530 * (*(int *)((char *)&dword_1BC28C + 2) >> 16) + dword_1BC28C, a1);
    *(_DWORD *)(dword_1BC28C + 4530 * (*(int *)((char *)&dword_1BC28C + 2) >> 16) + 4526) = 0;
    *(_WORD *)(4530 * (*(int *)((char *)&dword_1BC28C + 2) >> 16)
             + dword_1BC28C
             + 11 * *(_DWORD *)(dword_1BC28C + 4530 * (*(int *)((char *)&dword_1BC28C + 2) >> 16) + 4526)
             + 17) = v6;
    *(_DWORD *)(4530 * (*(int *)((char *)&dword_1BC28C + 2) >> 16)
              + dword_1BC28C
              + 11 * *(_DWORD *)(dword_1BC28C + 4530 * (*(int *)((char *)&dword_1BC28C + 2) >> 16) + 4526)
              + 19) = dword_184580;
    *(_DWORD *)(11 * *(_DWORD *)(dword_1BC28C + 4530 * (*(int *)((char *)&dword_1BC28C + 2) >> 16) + 4526)
              + 4530 * (*(int *)((char *)&dword_1BC28C + 2) >> 16)
              + dword_1BC28C
              + 23) = sub_12816C(a1, v6, a3, (int *)2);
    *(_BYTE *)(11 * (*(_DWORD *)(dword_1BC28C + 4530 * (*(int *)((char *)&dword_1BC28C + 2) >> 16) + 4526))++
             + dword_1BC28C
             + 4530 * (*(int *)((char *)&dword_1BC28C + 2) >> 16)
             + 16) = 1;
    ++word_1BC290;
    return *(_DWORD *)(11
                     * (*(_DWORD *)(4530 * ((*(int *)((char *)&dword_1BC28C + 2) >> 16) - 1) + dword_1BC28C + 4526) - 1)
                     + dword_1BC28C
                     + 4530 * ((*(int *)((char *)&dword_1BC28C + 2) >> 16) - 1)
                     + 23);
  }
}
// 127CDE: variable 'v10' is possibly undefined
// 13C896: using guessed type int stricmp(_DWORD, _DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184580: using guessed type int dword_184580;
// 1BC284: using guessed type int dword_1BC284;
// 1BC288: using guessed type int dword_1BC288;
// 1BC28C: using guessed type int dword_1BC28C;
// 1BC290: using guessed type int16_t word_1BC290;


//----- (0012816C) --------------------------------------------------------
_DWORD *sub_12816C(int a1, int a2, int a3, int *a4)
{
  _BYTE v5[60]; // [esp+0h] [ebp-8Ch] BYREF
  int v6; // [esp+3Ch] [ebp-50h]
  int v7; // [esp+40h] [ebp-4Ch]
  int *v8; // [esp+44h] [ebp-48h]
  int v9; // [esp+48h] [ebp-44h]
  int v10; // [esp+4Ch] [ebp-40h]
  int v11; // [esp+50h] [ebp-3Ch]
  int v12; // [esp+54h] [ebp-38h]
  _DWORD *v13; // [esp+58h] [ebp-34h]
  int v14; // [esp+5Ch] [ebp-30h]
  int v15; // [esp+60h] [ebp-2Ch] BYREF
  int v16; // [esp+64h] [ebp-28h] BYREF
  int v17; // [esp+68h] [ebp-24h] BYREF
  int v18; // [esp+6Ch] [ebp-20h] BYREF
  int v19; // [esp+70h] [ebp-1Ch]
  unsigned int v20; // [esp+74h] [ebp-18h]
  int i; // [esp+78h] [ebp-14h]
  int j; // [esp+7Ch] [ebp-10h]
  int v23; // [esp+80h] [ebp-Ch]
  int *v24; // [esp+84h] [ebp-8h]

  v6 = a1;
  v12 = a2;
  v7 = a3;
  v8 = a4;
  if ( a2 < 0 )
    sub_1273DC(v6, 4u, v12, (int)a4);
  if ( !dword_184576 || stricmp(v6, &unk_1BC270) )
  {
    if ( dword_184576 )
      fclose(dword_1BC26C);
    strcpy(&unk_1BC270, v6);
    dword_1BC26C = fopen(v6, aRb_4);
    if ( !dword_1BC26C )
    {
      if ( !byte_184544[0] )
        sub_1273DC(v6, 1u, v12, (int)a4);
      strcpy(v5, byte_184544);
      strcat(v5, &unk_1BC270);
      dword_1BC26C = fopen(v5, aRb_4);
      if ( !dword_1BC26C )
        sub_1273DC(v6, 1u, v12, (int)a4);
    }
    a4 = (int *)dword_1BC26C;
    fread(&unk_1BBA6C, 2048, 1, dword_1BC26C);
    if ( (uint16_t)word_1BBA6E != 65197 )
      sub_1273DC(v6, 7u, v12, (int)a4);
    dword_184576 = 1;
  }
  if ( (int)unk_1BBA6A >> 16 <= v12 )
    sub_1273DC(v6, 8u, v12, (int)a4);
  v9 = dword_1BBA74[v12];
  v10 = dword_1BBA78[v12];
  v11 = v10 - v9;
    // DECOMP_TODO (vyreseno ve vlne 07): fseek() melo 0 parametru - stejny
    // Hex-Rays artefakt jako jinde. Vzor je jasny (LBX archiv format):
    // prave precteny 2048bajtovy header obsahuje tabulku start/end offsetu
    // zaznamu (dword_1BBA74[]/dword_1BBA78[]), prave spocitany zacatecni
    // offset zaznamu se seekuje na stejnem handle, ktery cetl header.
  fseek(dword_1BC26C, v9, SEEK_SET);
  v13 = 0;
  v14 = 0;
  v24 = (int *)(v7 - 12);
  v13 = sub_1111D6(v7, v11);
  while ( !v13 && *v24 > 0 )
  {
    v13 = sub_1111D6(v7, v11);
    if ( !v13 )
    {
      ++v14;
      sub_1286BB(&v15, &v16);
      a4 = &v18;
      sub_12857C(v15, v16, &v17, &v18, v7);
      v24 = (int *)(v7 - 12);
      v23 = v7;
      v23 = *(_DWORD *)(v7 - 12) + v7;
      if ( v17 == 1000 )
        v19 = v23 - *(_DWORD *)(11 * v16 + dword_1BC28C + 4530 * v15 + 23);
      else
        v19 = *(_DWORD *)(4530 * v17 + dword_1BC28C + 11 * v18 + 23)
            - *(_DWORD *)(dword_1BC28C + 4530 * v15 + 11 * v16 + 23);
      if ( v17 == 1000 )
        v20 = 0;
      else
        v20 = v23 - *(_DWORD *)(11 * v18 + dword_1BC28C + 4530 * v17 + 23);
      if ( v17 != 1000 )
      {
        a4 = (int *)(dword_1BC28C + 4530 * v15);
        sub_12779E(*(_BYTE **)((char *)a4 + 11 * v16 + 23), *(_BYTE **)(4530 * v17 + dword_1BC28C + 11 * v18 + 23), v20);
        for ( i = 0; *(int *)((char *)&dword_1BC28C + 2) >> 16 > i; ++i )
        {
          for ( j = 0; j < *(_DWORD *)(dword_1BC28C + 4530 * i + 4526); ++j )
          {
            if ( *(_BYTE *)(4530 * i + dword_1BC28C + 11 * j + 16) == 1
              && *(_DWORD *)(dword_1BC28C + 4530 * v15 + 11 * v16 + 23) < *(_DWORD *)(dword_1BC28C
                                                                                    + 4530 * i
                                                                                    + 11 * j
                                                                                    + 23) )
            {
              *(_DWORD *)(11 * j + dword_1BC28C + 4530 * i + 23) -= v19;
            }
          }
        }
      }
      *(_BYTE *)(4530 * v15 + dword_1BC28C + 11 * v16 + 16) = 0;
      *v24 -= v19;
    }
  }
  if ( !v13 )
    sub_1273DC(v6, 5u, v12, (int)a4);
  fread(v13, v11, 1, dword_1BC26C);
  return v13;
}
// 12685D: using guessed type int fopen(_DWORD, _DWORD);
// 12697A: using guessed type int fclose(_DWORD);
// 1288DB: using guessed type int fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 13C896: using guessed type int stricmp(_DWORD, _DWORD);
// 13F220: using guessed type int strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int strcpy(_DWORD, _DWORD);
// 184576: using guessed type int dword_184576;
// 1BBA6E: using guessed type int16_t word_1BBA6E;
// 1BBA74: using guessed type int dword_1BBA74[];
// 1BBA78: using guessed type int dword_1BBA78[509];
// 1BC26C: using guessed type int dword_1BC26C;
// 1BC28C: using guessed type int dword_1BC28C;


//----- (0012857C) --------------------------------------------------------
int sub_12857C(int a1, int a2, int *a3, _DWORD *a4, int a5)
{
  int result; // eax
  int i; // [esp+10h] [ebp-10h]
  int j; // [esp+14h] [ebp-Ch]
  int v9; // [esp+18h] [ebp-8h]

  v9 = *(_DWORD *)(a5 - 12) + a5;
  *a3 = 1000;
  for ( i = 0; ; ++i )
  {
    result = *(int *)((char *)&dword_1BC28C + 2) >> 16;
    if ( *(int *)((char *)&dword_1BC28C + 2) >> 16 <= i )
      break;
    for ( j = 0; j < *(_DWORD *)(dword_1BC28C + 4530 * i + 4526); ++j )
    {
      if ( *(_BYTE *)(4530 * i + dword_1BC28C + 11 * j + 16) == 1
        && *(_DWORD *)(dword_1BC28C + 4530 * a1 + 11 * a2 + 23) < *(_DWORD *)(dword_1BC28C + 4530 * i + 11 * j + 23)
        && *(_DWORD *)(11 * j + 4530 * i + dword_1BC28C + 23) < v9 )
      {
        v9 = *(_DWORD *)(4530 * i + dword_1BC28C + 11 * j + 23);
        *a3 = i;
        *a4 = j;
      }
    }
  }
  return result;
}
// 1BC28C: using guessed type int dword_1BC28C;


//----- (001286BB) --------------------------------------------------------
int sub_1286BB(int *a1, _DWORD *a2)
{
  int result; // eax
  int i; // [esp+8h] [ebp-10h]
  int j; // [esp+Ch] [ebp-Ch]
  unsigned int v6; // [esp+10h] [ebp-8h]

  v6 = -1;
  for ( i = 0; ; ++i )
  {
    result = *(int *)((char *)&dword_1BC28C + 2) >> 16;
    if ( *(int *)((char *)&dword_1BC28C + 2) >> 16 <= i )
      break;
    for ( j = 0; j < *(_DWORD *)(dword_1BC28C + 4530 * i + 4526); ++j )
    {
      if ( v6 >= *(_DWORD *)(11 * j + dword_1BC28C + 4530 * i + 19)
        && *(_BYTE *)(4530 * i + dword_1BC28C + 11 * j + 16) == 1 )
      {
        *a1 = i;
        *a2 = j;
        v6 = *(_DWORD *)(4530 * i + dword_1BC28C + 11 * j + 19);
      }
    }
  }
  return result;
}
// 1BC28C: using guessed type int dword_1BC28C;


//----- (00128AB6) --------------------------------------------------------
int sub_128AB6( int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int result; // eax
  int16_t v6; // [esp+0h] [ebp-10h]
  int16_t v7; // [esp+4h] [ebp-Ch]
  int16_t v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v6 = a1;
  v7 = a2;
  v8 = a3;
  v9 = a4;
  if ( a1 < 0 )
    v6 = 0;
  if ( a2 < 0 )
    v7 = 0;
  if ( a3 >= *(int *)((char *)&dword_184532 + 2) )
    v8 = HIWORD(dword_184532) - 1;
  v4 = (int16_t)a4;
  if ( (int16_t)a4 >= *(int *)((char *)&dword_184536 + 2) )
  {
    LOWORD(v4) = HIWORD(dword_184536);
    v9 = v4 - 1;
  }
  HIWORD(dword_1BBA4A) = v6;
  HIWORD(dword_1BBA4E) = v7;
  LOWORD(dword_1BBA4E) = v8;
  result = v9;
  LOWORD(dword_1BBA52) = v9;
  return result;
}
// 184532: using guessed type int dword_184532;
// 184536: using guessed type int dword_184536;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00128B49) --------------------------------------------------------
int16_t sub_128B49()
{
  int16_t result; // ax

  word_1BC294 = HIWORD(dword_1BBA4A);
  dword_1BC296 = dword_1BBA4E;
  result = dword_1BBA52;
  word_1BC29A = dword_1BBA52;
  return result;
}
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BC294: using guessed type int16_t word_1BC294;
// 1BC296: using guessed type int dword_1BC296;
// 1BC29A: using guessed type int16_t word_1BC29A;


//----- (00128B98) --------------------------------------------------------
int16_t sub_128B98()
{
  int16_t result; // ax

  HIWORD(dword_1BBA4A) = word_1BC294;
  dword_1BBA4E = dword_1BC296;
  result = word_1BC29A;
  LOWORD(dword_1BBA52) = word_1BC29A;
  return result;
}
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BC294: using guessed type int16_t word_1BC294;
// 1BC296: using guessed type int dword_1BC296;
// 1BC29A: using guessed type int16_t word_1BC29A;


//----- (00128BE7) --------------------------------------------------------
int16_t sub_128BE7()
{
  int16_t result; // ax

  HIWORD(dword_1BBA4A) = 0;
  dword_1BBA4E = (uint16_t)(HIWORD(dword_184532) - 1);
  result = HIWORD(dword_184536) - 1;
  LOWORD(dword_1BBA52) = HIWORD(dword_184536) - 1;
  return result;
}
// 184532: using guessed type int dword_184532;
// 184536: using guessed type int dword_184536;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00128C32) --------------------------------------------------------
char sub_128C32(int a1, int a2, int a3, int a4, int a5)
{
  char result; // al
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp+24h] [ebp-3Ch]
  int v11; // [esp+28h] [ebp-38h]
  unsigned int v12; // [esp+34h] [ebp-2Ch]
  int v13; // [esp+38h] [ebp-28h]
  unsigned int v14; // [esp+3Ch] [ebp-24h]
  int v15; // [esp+40h] [ebp-20h]
  int v16; // [esp+4Ch] [ebp-14h]
  int v17; // [esp+50h] [ebp-10h] BYREF
  int v18; // [esp+54h] [ebp-Ch] BYREF
  int v19; // [esp+58h] [ebp-8h] BYREF
  int v20; // [esp+5Ch] [ebp-4h] BYREF

  v18 = a1;
  v17 = a2;
  v20 = a3;
  v19 = a4;
  if ( (int16_t)a1 > (int16_t)a3 )
    sub_133111((int16_t *)&v18, (int16_t *)&v20);
  if ( (int16_t)v17 > (int16_t)v19 )
    sub_133111((int16_t *)&v17, (int16_t *)&v19);
  if ( word_1845D8 == 1 )
  {
    result = v18;
    if ( (int16_t)v18 >= (int16_t)dword_1BBA4E )
      return result;
    result = v20;
    if ( (int16_t)v20 <= SHIWORD(dword_1BBA4A) )
      return result;
    result = v17;
    if ( (int16_t)v17 >= (int16_t)dword_1BBA52 )
      return result;
    result = v19;
    if ( (int16_t)v19 <= SHIWORD(dword_1BBA4E) )
      return result;
    HIWORD(v6) = HIWORD(v18);
    if ( (int16_t)v18 < SHIWORD(dword_1BBA4A) )
    {
      LOWORD(v6) = HIWORD(dword_1BBA4A);
      v18 = v6;
    }
    HIWORD(v7) = HIWORD(v17);
    if ( (int16_t)v17 < SHIWORD(dword_1BBA4E) )
    {
      LOWORD(v7) = HIWORD(dword_1BBA4E);
      v17 = v7;
    }
    HIWORD(v8) = HIWORD(v20);
    if ( (int16_t)v20 > (int16_t)dword_1BBA4E )
    {
      LOWORD(v8) = dword_1BBA4E;
      v20 = v8;
    }
    HIWORD(v9) = HIWORD(v19);
    if ( (int16_t)v19 > (int16_t)dword_1BBA52 )
    {
      LOWORD(v9) = dword_1BBA52;
      v19 = v9;
    }
  }
  if ( dword_1BBA28 >= 2 )
    sub_138CEE((int16_t)v18, (int16_t)v17, (int16_t)v20, (int16_t)v19);
  v10 = (int)((int16_t)v18
            - (__CFSHL__((uint64_t)(int16_t)v18 >> 32, 2)
             + 4 * ((uint64_t)(int16_t)v18 >> 32))) >> 2;
  v11 = (int)((int16_t)v20
            - (__CFSHL__((uint64_t)(int16_t)v20 >> 32, 2)
             + 4 * ((uint64_t)(int16_t)v20 >> 32))) >> 2;
  if ( v10 == v11 )
    return sub_14759C(
             a5,
             (char *)((int16_t)v18 + (int16_t)v17 * *(int *)((char *)&dword_184532 + 2) + dword_1BB904),
             (int16_t)v20 - (int16_t)v18 + 1,
             (int16_t)v19 - (int16_t)v17 + 1);
  v12 = 4 - (v18 & 3);
  v13 = v11 - v10 - 1;
  v14 = (v20 & 3) + 1;
  if ( v12 == 4 )
  {
    v12 = 0;
    v13 = v11 - v10;
  }
  if ( (v20 & 3) == 3 )
  {
    v14 = 0;
    ++v13;
  }
  v15 = (int16_t)v17 * *(int *)((char *)&dword_184532 + 2);
  result = v17;
  v16 = (int16_t)v19 - (int16_t)v17 + 1;
  if ( v12 )
  {
    sub_14759C(a5, (char *)(v15 + (int16_t)v18 + dword_1BB904), v12, v16);
    result = sub_1475BB(a5, (char *)(v15 + 4 * v10 + 4 + dword_1BB904), v13, v16);
  }
  else if ( v13 )
  {
    result = sub_1475BB(a5, (char *)(dword_1BB904 + v15 + 4 * v10), v13, v16);
  }
  if ( v14 )
    return sub_14759C(a5, (char *)(dword_1BB904 + v15 + 4 * v11), v14, v16);
  return result;
}
// 184532: using guessed type int dword_184532;
// 1845D8: using guessed type int16_t word_1845D8;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00128EDE) --------------------------------------------------------
char sub_128EDE( int a1, int a2, int a3, int a4, int a5, int a6)
{
  char result; // al
  int v7; // [esp+28h] [ebp-3Ch]
  int v8; // [esp+2Ch] [ebp-38h]
  int v9; // [esp+30h] [ebp-34h]
  unsigned int v10; // [esp+34h] [ebp-30h]
  int v11; // [esp+38h] [ebp-2Ch]
  unsigned int v12; // [esp+3Ch] [ebp-28h]
  int v13; // [esp+40h] [ebp-24h]
  int v14; // [esp+48h] [ebp-1Ch]
  int16_t v15; // [esp+54h] [ebp-10h]
  int16_t v16; // [esp+58h] [ebp-Ch]
  int16_t v17; // [esp+5Ch] [ebp-8h]
  int16_t v18; // [esp+60h] [ebp-4h]

  v18 = a1;
  v17 = a2;
  v15 = a3;
  v16 = a4;
  v9 = (a6 << 8) + a5;
  if ( word_1845D8 == 1 )
  {
    if ( a1 < SHIWORD(dword_1BBA4A) )
      v18 = HIWORD(dword_1BBA4A);
    if ( a2 < SHIWORD(dword_1BBA4E) )
      v17 = HIWORD(dword_1BBA4E);
    if ( a3 > (int16_t)dword_1BBA4E )
      v15 = dword_1BBA4E;
    if ( a4 > (int16_t)dword_1BBA52 )
      v16 = dword_1BBA52;
  }
  result = v18;
  if ( v18 <= v15 )
  {
    result = v17;
    if ( v17 <= v16 )
    {
      if ( dword_1BBA28 >= 2 )
        sub_138CEE(v18, v17, v15, v16);
      v7 = (int)(v18 - (__CFSHL__((uint64_t)v18 >> 32, 2) + 4 * ((uint64_t)v18 >> 32))) >> 2;
      v8 = (int)(v15 - (__CFSHL__((uint64_t)v15 >> 32, 2) + 4 * ((uint64_t)v15 >> 32))) >> 2;
      if ( v7 == v8 )
      {
        return sub_1475EB(v9, (char *)(v18 + v17 * HIDWORD(qword_184530) + dword_1BB904), v15 - v18 + 1, v16 - v17 + 1);
      }
      else
      {
        v10 = 4 - (v18 & 3);
        v11 = v8 - v7 - 1;
        v12 = (v15 & 3) + 1;
        if ( v10 == 4 )
        {
          v10 = 0;
          v11 = v8 - v7;
        }
        if ( (v15 & 3) == 3 )
        {
          v12 = 0;
          ++v11;
        }
        v13 = v17 * HIDWORD(qword_184530);
        result = v17;
        v14 = v16 - v17 + 1;
        if ( v10 )
        {
          sub_1475EB(v9, (char *)(v13 + v18 + dword_1BB904), v10, v14);
          result = sub_14760C(v9, (char *)(v13 + 4 * v7 + 4 + dword_1BB904), v11, v14);
        }
        else if ( v11 )
        {
          result = sub_14760C(v9, (char *)(dword_1BB904 + v13 + 4 * v7), v11, v14);
        }
        if ( v12 )
          return sub_1475EB(v9, (char *)(dword_1BB904 + v13 + 4 * v8), v12, v14);
      }
    }
  }
  return result;
}
// 184530: using guessed type int64_t qword_184530;
// 1845D8: using guessed type int16_t word_1845D8;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00129130) --------------------------------------------------------
int sub_129130(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int result; // eax
  int v12; // [esp+0h] [ebp-64h]
  int v13; // [esp+2Ch] [ebp-38h]
  int v14; // [esp+30h] [ebp-34h]
  unsigned int v15; // [esp+38h] [ebp-2Ch]
  int v16; // [esp+3Ch] [ebp-28h]
  unsigned int v17; // [esp+40h] [ebp-24h]
  int v18; // [esp+48h] [ebp-1Ch]
  int v19; // [esp+50h] [ebp-14h]
  int v20; // [esp+54h] [ebp-10h] BYREF
  int v21; // [esp+58h] [ebp-Ch] BYREF
  int v22; // [esp+5Ch] [ebp-8h] BYREF
  int v23; // [esp+60h] [ebp-4h] BYREF

  v23 = a1;
  v22 = a2;
  v20 = a3;
  v21 = a4;
  v14 = (a7 << 16) + (a6 << 8) + a5;
  if ( (int16_t)a1 > (int16_t)a3 )
    sub_133111((int16_t *)&v23, (int16_t *)&v20);
  if ( (int16_t)v22 > (int16_t)v21 )
    sub_133111((int16_t *)&v22, (int16_t *)&v21);
  if ( word_1845D8 == 1 )
  {
    HIWORD(v7) = HIWORD(v23);
    if ( (int16_t)v23 < SHIWORD(dword_1BBA4A) )
    {
      LOWORD(v7) = HIWORD(dword_1BBA4A);
      v23 = v7;
    }
    HIWORD(v8) = HIWORD(v22);
    if ( (int16_t)v22 < SHIWORD(dword_1BBA4E) )
    {
      LOWORD(v8) = HIWORD(dword_1BBA4E);
      v22 = v8;
    }
    HIWORD(v9) = HIWORD(v20);
    if ( (int16_t)v20 > (int16_t)dword_1BBA4E )
    {
      LOWORD(v9) = dword_1BBA4E;
      v20 = v9;
    }
    HIWORD(v10) = HIWORD(v21);
    if ( (int16_t)v21 > (int16_t)dword_1BBA52 )
    {
      LOWORD(v10) = dword_1BBA52;
      v21 = v10;
    }
  }
  if ( dword_1BBA28 >= 2 )
    sub_138CEE((int16_t)v23, (int16_t)v22, (int16_t)v20, (int16_t)v21);
  v13 = (int)((int16_t)v23
            - (__CFSHL__((uint64_t)(int16_t)v23 >> 32, 2)
             + 4 * ((uint64_t)(int16_t)v23 >> 32))) >> 2;
  v12 = (int)((int16_t)v20
            - (__CFSHL__((uint64_t)(int16_t)v20 >> 32, 2)
             + 4 * ((uint64_t)(int16_t)v20 >> 32))) >> 2;
  if ( v13 == v12 )
    return sub_14765E(
             v14,
             (char *)((int16_t)v23 + (int16_t)v22 * HIDWORD(qword_184530) + dword_1BB904),
             (int16_t)v20 - (int16_t)v23 + 1,
             (int16_t)v21 - (int16_t)v22 + 1);
  v15 = 4 - (v23 & 3);
  v16 = v12 - v13 - 1;
  v17 = (v20 & 3) + 1;
  if ( v15 == 4 )
  {
    v15 = 0;
    v16 = v12 - v13;
  }
  if ( (v20 & 3) == 3 )
  {
    v17 = 0;
    ++v16;
  }
  v19 = (int16_t)v22 * HIDWORD(qword_184530);
  result = (int16_t)v22;
  v18 = (int16_t)v21 - (int16_t)v22 + 1;
  if ( v15 )
  {
    sub_14765E(v14, (char *)(v19 + (int16_t)v23 + dword_1BB904), v15, v18);
    result = sub_147698(v14, (char *)(v19 + 4 * v13 + 4 + dword_1BB904), v16, v18);
  }
  else if ( v16 )
  {
    result = sub_147698(v14, (char *)(dword_1BB904 + v19 + 4 * v13), v16, v18);
  }
  if ( v17 )
    return sub_14765E(v14, (char *)(dword_1BB904 + v19 + 4 * v12), v17, v18);
  return result;
}
// 184530: using guessed type int64_t qword_184530;
// 1845D8: using guessed type int16_t word_1845D8;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00129399) --------------------------------------------------------
char sub_129399(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int i; // [esp+8h] [ebp-5Ch]
  int v13; // [esp+20h] [ebp-44h]
  int v14; // [esp+54h] [ebp-10h] BYREF
  int v15; // [esp+58h] [ebp-Ch] BYREF
  int v16; // [esp+5Ch] [ebp-8h] BYREF
  int v17; // [esp+60h] [ebp-4h] BYREF

  v17 = a1;
  v16 = a2;
  v14 = a3;
  v15 = a4;
  if ( (int16_t)a1 > (int16_t)a3 )
    sub_133111((int16_t *)&v17, (int16_t *)&v14);
  if ( (int16_t)v16 > (int16_t)v15 )
    sub_133111((int16_t *)&v16, (int16_t *)&v15);
  if ( word_1845D8 == 1 )
  {
    HIWORD(v7) = HIWORD(v17);
    if ( (int16_t)v17 < SHIWORD(dword_1BBA4A) )
    {
      LOWORD(v7) = HIWORD(dword_1BBA4A);
      v17 = v7;
    }
    HIWORD(v8) = HIWORD(v16);
    if ( (int16_t)v16 < SHIWORD(dword_1BBA4E) )
    {
      LOWORD(v8) = HIWORD(dword_1BBA4E);
      v16 = v8;
    }
    HIWORD(v9) = HIWORD(v14);
    if ( (int16_t)v14 > (int16_t)dword_1BBA4E )
    {
      LOWORD(v9) = dword_1BBA4E;
      v14 = v9;
    }
    HIWORD(v10) = HIWORD(v15);
    if ( (int16_t)v15 > (int16_t)dword_1BBA52 )
    {
      LOWORD(v10) = dword_1BBA52;
      v15 = v10;
    }
  }
  if ( dword_1BBA28 >= 2 )
    sub_138CEE((int16_t)v17, (int16_t)v16, (int16_t)v14, (int16_t)v15);
  dword_1BD09C = (int)&byte_1BC89C;
  sub_1380E0(a6, a7);
  v13 = HIDWORD(qword_184530) - ((int16_t)v14 - (int16_t)v17 + 1);
  for ( i = 0; i < 256; ++i )
    *(_BYTE *)(i + dword_1BD09C) = *(_BYTE *)(a5 + *(uint8_t *)(i + dword_1BD09C));
  return sub_147E61(
           (char *)(dword_1BB904 + HIDWORD(qword_184530) * (int16_t)v16 + (int16_t)v17),
           dword_1BD09C,
           v13,
           (int16_t)v14 - (int16_t)v17 + 1,
           (int16_t)v15 - (int16_t)v16 + 1);
}
// 129399: could not find valid save-restore pair for ebx
// 184530: using guessed type int64_t qword_184530;
// 1845D8: using guessed type int16_t word_1845D8;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BC89C: using guessed type char byte_1BC89C;
// 1BD09C: using guessed type int dword_1BD09C;


//----- (0012972D) --------------------------------------------------------
char sub_12972D( int a1, int a2, int a3)
{
  int16_t v4; // [esp+0h] [ebp-Ch]

  v4 = a1;
  if ( word_1845D8 != 1
    || a1 >= SHIWORD(dword_1BBA4A)
    && (LOBYTE(a1) = a2, a2 >= SHIWORD(dword_1BBA4E))
    && (LOBYTE(a1) = v4, v4 <= (int16_t)dword_1BBA4E)
    && (LOBYTE(a1) = a2, a2 <= (int16_t)dword_1BBA52) )
  {
    if ( dword_1BBA28 >= 2 )
      sub_125E13(v4, a2);
    LOBYTE(a1) = a3;
    *(_BYTE *)(dword_1BB904 + v4 + HIDWORD(qword_184530) * a2) = a3;
  }
  return a1;
}
// 184530: using guessed type int64_t qword_184530;
// 1845D8: using guessed type int16_t word_1845D8;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (001297C3) --------------------------------------------------------
int sub_1297C3( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax
  int i; // [esp+0h] [ebp-14h]

  for ( i = 0; ; ++i )
  {
    result = a5;
    if ( a5 <= i )
      break;
    sub_134D2D((int16_t)(i + a1), (int16_t)(i + a2), (int16_t)(a3 + a1 - 1 - i), (int16_t)(i + a2), a6);
    sub_134D2D((int16_t)(i + a1), (int16_t)(i + a2), (int16_t)(i + a1), (int16_t)(a4 + a2 - 1 - i), a6);
    sub_134D2D(
      (int16_t)(a3 + a1 - 1 - i),
      (int16_t)(i + a2),
      (int16_t)(a3 + a1 - 1 - i),
      (int16_t)(a4 + a2 - 1 - i),
      a6);
    sub_134D2D(
      (int16_t)(i + a1),
      (int16_t)(a4 + a2 - 1 - i),
      (int16_t)(a3 + a1 - 1 - i),
      (int16_t)(a4 + a2 - 1 - i),
      a6);
  }
  return result;
}


//----- (001298DE) --------------------------------------------------------
char sub_1298DE( int a1, int a2, int a3, int a4)
{
  return sub_12991D(a1, a2, a3, a4, 0);
}


//----- (0012991D) --------------------------------------------------------
char sub_12991D(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char result; // al
  int v10; // [esp+24h] [ebp-3Ch]
  int v11; // [esp+28h] [ebp-38h]
  int v12; // [esp+34h] [ebp-2Ch]
  int v13; // [esp+3Ch] [ebp-24h]
  int v14; // [esp+40h] [ebp-20h]
  int v15; // [esp+4Ch] [ebp-14h]
  int v16; // [esp+50h] [ebp-10h] BYREF
  int v17; // [esp+54h] [ebp-Ch] BYREF
  int v18; // [esp+58h] [ebp-8h] BYREF
  int v19; // [esp+5Ch] [ebp-4h] BYREF

  v17 = a1;
  v16 = a2;
  v19 = a3;
  v18 = a4;
  if ( (int16_t)a1 > (int16_t)a3 )
    sub_133111((int16_t *)&v17, (int16_t *)&v19);
  if ( (int16_t)v16 > (int16_t)v18 )
    sub_133111((int16_t *)&v16, (int16_t *)&v18);
  if ( word_1845D8 == 1 )
  {
    HIWORD(v5) = HIWORD(v17);
    if ( (int16_t)v17 < SHIWORD(dword_1BBA4A) )
    {
      LOWORD(v5) = HIWORD(dword_1BBA4A);
      v17 = v5;
    }
    HIWORD(v6) = HIWORD(v16);
    if ( (int16_t)v16 < SHIWORD(dword_1BBA4E) )
    {
      LOWORD(v6) = HIWORD(dword_1BBA4E);
      v16 = v6;
    }
    HIWORD(v7) = HIWORD(v19);
    if ( (int16_t)v19 > (int16_t)dword_1BBA4E )
    {
      LOWORD(v7) = dword_1BBA4E;
      v19 = v7;
    }
    HIWORD(v8) = HIWORD(v18);
    if ( (int16_t)v18 > (int16_t)dword_1BBA52 )
    {
      LOWORD(v8) = dword_1BBA52;
      v18 = v8;
    }
  }
  if ( dword_1BBA28 >= 2 )
    sub_138CEE((int16_t)v17, (int16_t)v16, (int16_t)v19, (int16_t)v18);
  v10 = (int)((int16_t)v17
            - (__CFSHL__((uint64_t)(int16_t)v17 >> 32, 2)
             + 4 * ((uint64_t)(int16_t)v17 >> 32))) >> 2;
  v11 = (int)((int16_t)v19
            - (__CFSHL__((uint64_t)(int16_t)v19 >> 32, 2)
             + 4 * ((uint64_t)(int16_t)v19 >> 32))) >> 2;
  if ( v10 == v11 )
    return sub_147723(
             (int)&byte_1BA358[256 * a5],
             (_BYTE *)((int16_t)v17 + HIDWORD(qword_184530) * (int16_t)v16 + dword_1BB904),
             (int16_t)v19 - (int16_t)v17 + 1,
             (int16_t)v18 - (int16_t)v16 + 1);
  v12 = 4 - (v17 & 3);
  v13 = v19 & 3;
  v14 = (int16_t)v16 * HIDWORD(qword_184530);
  result = v16;
  v15 = (int16_t)v18 - (int16_t)v16 + 1;
  if ( v12 == 4 )
  {
    if ( v11 - v10 != 1 )
      result = sub_147760((int)byte_1BA358, (_BYTE *)(v14 + 4 * v10 + dword_1BB904), v11 - v10, v15);
  }
  else
  {
    sub_147723((int)byte_1BA358, (_BYTE *)(dword_1BB904 + v14 + (int16_t)v17), v12, v15);
    result = sub_147760((int)byte_1BA358, (_BYTE *)(v14 + 4 * v10 + 4 + dword_1BB904), v11 - v10 - 1, v15);
  }
  if ( v13 )
    return sub_147723((int)byte_1BA358, (_BYTE *)(v14 + 4 * v11 + dword_1BB904), v13, v15);
  return result;
}
// 184530: using guessed type int64_t qword_184530;
// 1845D8: using guessed type int16_t word_1845D8;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00129B84) --------------------------------------------------------
char sub_129B84( int a1, int a2, int a3, int a4,
        unsigned int a5,
        uint8_t *a6, int a7,
        int a8,
        int a9)
{
  if ( a5 < 3 )
  {
    if ( a5 == 1 )
      LOBYTE(a1) = sub_128C32(a1, a2, a3, a4, *a6);
  }
  else if ( a5 <= 3 )
  {
    LOBYTE(a1) = sub_12991D(a1, a2, a3, a4, 0);
  }
  else if ( a5 >= 0xF )
  {
    if ( a5 <= 0xF )
    {
      LOBYTE(a1) = sub_12991D(a1, a2, a3, a4, *a6);
    }
    else if ( a5 == 16 )
    {
      LOBYTE(a1) = sub_129399(a1, a2, a3, a4, (int)a6, a7, 0);
    }
  }
  return a1;
}


//----- (00129C88) --------------------------------------------------------
void *sub_129C88()
{
  return &unk_1BC29C;
}


//----- (00129C8E) --------------------------------------------------------
void *sub_129C8E()
{
  return &unk_1BC2A0;
}


//----- (00129FF9) --------------------------------------------------------
int sub_129FF9( int a1, int a2, int a3)
{
  int v3; // edx
  int result; // eax
  int64_t v5; // [esp+0h] [ebp-38h]
  char *v6; // [esp+8h] [ebp-30h]
  int v7; // [esp+14h] [ebp-24h]
  int *v8; // [esp+20h] [ebp-18h]
  int16_t v11; // [esp+30h] [ebp-8h]
  int16_t v12; // [esp+34h] [ebp-4h]

  v7 = 0;
  dword_1BC2A8 = a3;
  v12 = *(_WORD *)a3 + a1 - 1;
  v11 = *(_WORD *)(a3 + 2) + a2 - 1;
  if ( (*(_BYTE *)(a3 + 11) & 0x10) != 0 )
    sub_12AE00();
  v3 = dword_1BC2A8;
  v8 = (int *)(dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16)));
  if ( word_1845D8 )
  {
    if ( a1 > (int16_t)dword_1BBA4E
      || a2 > (int16_t)dword_1BBA52
      || v12 < SHIWORD(dword_1BBA4A)
      || v11 < SHIWORD(dword_1BBA4E) )
    {
      goto LABEL_54;
    }
    if ( a1 < SHIWORD(dword_1BBA4A)
      || a2 < SHIWORD(dword_1BBA4E)
      || v12 > (int16_t)dword_1BBA4E
      || v11 > (int16_t)dword_1BBA52 )
    {
      v7 = 1;
    }
  }
  if ( v7 )
  {
    if ( word_1845DA )
    {
      if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 3) == 0 )
        sub_148F57(a1, a2, (int)v8);
    }
    else
    {
      if ( dword_1BBA28 >= 2 )
      {
        v3 = a2;
        sub_138CEE(a1, a2, v12, v11);
      }
      switch ( *(_BYTE *)(dword_1BC2A8 + 11) & 3 )
      {
        case 0:
          if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 8) != 0 )
            sub_148C33(a1, a2, v8);
          else
            sub_1489F4(a1, a2, v8);
          break;
        case 1:
          if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 8) != 0 )
            sub_1487E0(a1, a2, v8);
          else
            sub_14861D(a1, a2, (char *)v8);
          break;
        case 2:
          sub_126487(aScreenBackgrou, v3);
        case 3:
          sub_126487(aRefreshMaskCan, v3);
        default:
          break;
      }
    }
  }
  else
  {
    if ( dword_1BBA28 >= 2 )
    {
      v3 = a2;
      sub_138CEE(a1, a2, *(int16_t *)dword_1BC2A8 + a1 - 1, a2 + (*(int *)dword_1BC2A8 >> 16) - 1);
    }
    if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 8) != 0 )
    {
      switch ( *(_BYTE *)(dword_1BC2A8 + 11) & 3 )
      {
        case 0:
          sub_12AAA1(a1, a2, (int)v8);
          break;
        case 1:
          sub_12ABCC(a1, a2, (int)v8);
          break;
        case 2:
          if ( dword_1BBA42 >> 16 == 1 )
            sub_12B501((int)v8);
          else
            sub_12B3E0((int)v8);
          if ( dword_1BBA28 >= 2 )
            sub_138CEE(0, 0, 639, 479);
          break;
        case 3:
          sub_126487(aRefreshMaskCan, v3);
        default:
          break;
      }
    }
    else
    {
      LOBYTE(v6) = *(_BYTE *)(dword_1BC2A8 + 11) & 3;
      switch ( (char)v6 )
      {
        case 0:
          sub_14852C((int16_t)a1, (int16_t)a2, (int)(intptr_t)v8); // wave 20: args from original asm
          break;
        case 1:
          sub_1485B3((int16_t)a1, (int16_t)a2, (char *)v8); // wave 20
          break;
        case 2:
          if ( dword_1BBA42 >> 16 == 1 )
            sub_12B2D9((int)v8);
          else
            sub_12AFCC((int)v8);
          if ( dword_1BBA28 >= 2 )
            sub_138CEE(0, 0, 639, 479);
          break;
        case 3:
          sub_126487(aRefreshMaskCan, v3);
        default:
          break;
      }
    }
  }
LABEL_54:
  ++*(_WORD *)(dword_1BC2A8 + 4);
  if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 0x20) != 0 )
  {
    result = dword_1BC2A8;
    if ( *(uint8_t *)(dword_1BC2A8 + 8) < *(int16_t *)(dword_1BC2A8 + 4) )
    {
      if ( *(int *)(dword_1BC2A8 + 2) >> 16 == *(uint8_t *)(dword_1BC2A8 + 8) + 1 )
      {
        result = dword_1BC2A8;
        *(_WORD *)(dword_1BC2A8 + 4) = 0;
      }
      else
      {
        result = dword_1BC2A8;
        if ( *(_WORD *)(dword_1BC2A8 + 4) >= *(_WORD *)(dword_1BC2A8 + 6) )
        {
          result = dword_1BC2A8;
          *(_WORD *)(dword_1BC2A8 + 4) = *(_WORD *)(dword_1BC2A8 + 6) - 1;
        }
      }
    }
  }
  else
  {
    result = dword_1BC2A8;
    if ( *(_WORD *)(dword_1BC2A8 + 4) >= *(_WORD *)(dword_1BC2A8 + 6) )
    {
      result = dword_1BC2A8;
      *(_WORD *)(dword_1BC2A8 + 4) = *(uint8_t *)(dword_1BC2A8 + 8);
    }
  }
  return result;
}
// 12A252: variable 'v5' is possibly undefined
// 12A252: variable 'v6' is possibly undefined
// 1845D8: using guessed type int16_t word_1845D8;
// 1845DA: using guessed type int16_t word_1845DA;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA42: using guessed type int dword_1BBA42;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012A478) --------------------------------------------------------
int sub_12A478( int a1, int a2, int a3)
{
  int v3; // edx
  int result; // eax
  int64_t v5; // [esp+0h] [ebp-38h]
  char *v6; // [esp+8h] [ebp-30h]
  int v7; // [esp+14h] [ebp-24h]
  int *v8; // [esp+20h] [ebp-18h]
  int16_t v11; // [esp+30h] [ebp-8h]
  int16_t v12; // [esp+34h] [ebp-4h]

  v7 = 0;
  dword_1BC2A8 = a3;
  v12 = *(_WORD *)a3 + a1 - 1;
  v11 = *(_WORD *)(a3 + 2) + a2 - 1;
  if ( (*(_BYTE *)(a3 + 11) & 0x10) != 0 )
    sub_12AE00();
  v3 = dword_1BC2A8;
  v8 = (int *)(dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16)));
  if ( word_1845D8 )
  {
    if ( a1 > (int16_t)dword_1BBA4E
      || a2 > (int16_t)dword_1BBA52
      || v12 < SHIWORD(dword_1BBA4A)
      || v11 < SHIWORD(dword_1BBA4E) )
    {
      goto LABEL_57;
    }
    if ( a1 < SHIWORD(dword_1BBA4A)
      || a2 < SHIWORD(dword_1BBA4E)
      || v12 > (int16_t)dword_1BBA4E
      || v11 > (int16_t)dword_1BBA52 )
    {
      v7 = 1;
    }
  }
  if ( v7 )
  {
    if ( word_1845DA )
    {
      if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 3) == 0 )
        sub_148F57(a1, a2, (int)v8);
    }
    else
    {
      if ( dword_1BBA28 >= 2 )
      {
        v3 = a2;
        sub_138CEE(a1, a2, v12, v11);
      }
      switch ( *(_BYTE *)(dword_1BC2A8 + 11) & 3 )
      {
        case 0:
          if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 8) != 0 )
            sub_148C33(a1, a2, v8);
          else
            sub_1489F4(a1, a2, v8);
          break;
        case 1:
          if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 8) != 0 )
            sub_1487E0(a1, a2, v8);
          else
            sub_14861D(a1, a2, (char *)v8);
          break;
        case 2:
          sub_126487(aScreenBackgrou_0, v3);
        case 3:
          sub_126487(aRefreshMaskCan, v3);
        default:
          break;
      }
    }
  }
  else
  {
    if ( dword_1BBA28 >= 2 )
    {
      result = dword_1BC2A8;
      if ( !*(_WORD *)dword_1BC2A8 )
        return result;
      result = dword_1BC2A8;
      if ( !*(_WORD *)(dword_1BC2A8 + 2) )
        return result;
      v3 = a2;
      sub_138CEE(a1, a2, *(int16_t *)dword_1BC2A8 + a1 - 1, a2 + (*(int *)dword_1BC2A8 >> 16) - 1);
    }
    if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 8) != 0 )
    {
      switch ( *(_BYTE *)(dword_1BC2A8 + 11) & 3 )
      {
        case 0:
          sub_12ACA4(a1, a2, (int)v8);
          break;
        case 1:
          sub_12AEC0(a1, a2, (int)v8);
          break;
        case 2:
          if ( dword_1BBA42 >> 16 == 1 )
            sub_12B501((int)v8);
          else
            sub_12B3E0((int)v8);
          if ( dword_1BBA28 >= 2 )
            sub_138CEE(0, 0, 639, 479);
          break;
        case 3:
          sub_126487(aRefreshMaskCan, v3);
        default:
          break;
      }
    }
    else
    {
      LOBYTE(v6) = *(_BYTE *)(dword_1BC2A8 + 11) & 3;
      switch ( (char)v6 )
      {
        case 0:
          sub_14852C((int16_t)a1, (int16_t)a2, (int)(intptr_t)v8); // wave 20: args from original asm
          break;
        case 1:
          sub_1485B3((int16_t)a1, (int16_t)a2, (char *)v8); // wave 20
          break;
        case 2:
          if ( dword_1BBA42 >> 16 == 1 )
            sub_12B2D9((int)v8);
          else
            sub_12AFCC((int)v8);
          if ( dword_1BBA28 >= 2 )
            sub_138CEE(0, 0, 639, 479);
          break;
        case 3:
          sub_126487(aRefreshMaskCan, v3);
        default:
          break;
      }
    }
  }
LABEL_57:
  ++*(_WORD *)(dword_1BC2A8 + 4);
  if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 0x20) != 0 )
  {
    result = dword_1BC2A8;
    if ( *(uint8_t *)(dword_1BC2A8 + 8) < *(int16_t *)(dword_1BC2A8 + 4) )
    {
      if ( *(int *)(dword_1BC2A8 + 2) >> 16 == *(uint8_t *)(dword_1BC2A8 + 8) + 1 )
      {
        result = dword_1BC2A8;
        *(_WORD *)(dword_1BC2A8 + 4) = 0;
      }
      else
      {
        result = dword_1BC2A8;
        if ( *(_WORD *)(dword_1BC2A8 + 4) >= *(_WORD *)(dword_1BC2A8 + 6) )
        {
          result = dword_1BC2A8;
          *(_WORD *)(dword_1BC2A8 + 4) = *(_WORD *)(dword_1BC2A8 + 6) - 1;
        }
      }
    }
  }
  else
  {
    result = dword_1BC2A8;
    if ( *(_WORD *)(dword_1BC2A8 + 4) >= *(_WORD *)(dword_1BC2A8 + 6) )
    {
      result = dword_1BC2A8;
      *(_WORD *)(dword_1BC2A8 + 4) = *(uint8_t *)(dword_1BC2A8 + 8);
    }
  }
  return result;
}
// 12A6EE: variable 'v5' is possibly undefined
// 12A6EE: variable 'v6' is possibly undefined
// 1845D8: using guessed type int16_t word_1845D8;
// 1845DA: using guessed type int16_t word_1845DA;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA42: using guessed type int dword_1BBA42;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012A914) --------------------------------------------------------
int sub_12A914( int a1, int a2, int a3)
{
  int result; // eax
  int16_t v4; // ax
  int v5; // ebx
  int v6; // [esp+0h] [ebp-60h]
  int v8; // [esp+14h] [ebp-4Ch]
  int v9; // [esp+1Ch] [ebp-44h]
  int v10; // [esp+20h] [ebp-40h]
  int v11; // [esp+24h] [ebp-3Ch]
  int v12; // [esp+28h] [ebp-38h]
  int v13; // [esp+2Ch] [ebp-34h]
  int v15; // [esp+40h] [ebp-20h]
  int16_t v17; // [esp+50h] [ebp-10h]
  int16_t v18; // [esp+54h] [ebp-Ch]

  v17 = *(_WORD *)(dword_1BC2A8 + 2);
  v9 = *(uint16_t *)(a3 + 2);
  v11 = a1 + (v9 + a2) * HIDWORD(qword_184530);
  v8 = v11;
  v13 = 2;
  v15 = a1;
  v10 = a2 + v9;
  while ( 1 )
  {
    result = v17;
    if ( v17 <= v9 )
      break;
    v18 = *(_WORD *)(a3 + 2 * v13);
    v4 = *(_WORD *)(a3 + 2 * v13 + 2);
    v13 += 2;
    if ( v18 )
    {
      v15 += v4;
      v8 += v4;
      v12 = 2 * v13;
      v6 = v18 + v8;
      sub_138CEE(v15, v10, v15 + v18, v10);
      while ( v8 < v6 )
      {
        memcpy(v8 + dword_1BB8FC, v12 + a3, v6 - v8);
        v5 = v6 - v8;
        memcpy(v8 + dword_1BB904, v12 + a3, v6 - v8);
        v12 += v6 - v8;
        v8 = v6;
        v15 += v5;
      }
      v13 += (v18 + 1) / 2;
    }
    else
    {
      v10 += v4;
      v9 += v4;
      v11 += 640 * v4;
      v8 = v11;
      v15 = a1;
    }
  }
  return result;
}
// 13F35A: using guessed type int memcpy(_DWORD, _DWORD, _DWORD);
// 184530: using guessed type int64_t qword_184530;
// 1BB8FC: using guessed type int dword_1BB8FC;
// 1BB904: using guessed type int dword_1BB904;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012AAA1) --------------------------------------------------------
int sub_12AAA1( int a1, int a2, int a3)
{
  int result; // eax
  int16_t v4; // ax
  int v5; // [esp+0h] [ebp-58h]
  int v6; // [esp+4h] [ebp-54h]
  int v7; // [esp+14h] [ebp-44h]
  int v8; // [esp+1Ch] [ebp-3Ch]
  int v9; // [esp+24h] [ebp-34h]
  int v10; // [esp+28h] [ebp-30h]
  int16_t v11; // [esp+38h] [ebp-20h]
  int16_t v12; // [esp+4Ch] [ebp-Ch]
  uint8_t v13; // [esp+50h] [ebp-8h]

  v12 = *(_WORD *)(dword_1BC2A8 + 2);
  v8 = *(uint16_t *)(a3 + 2);
  v9 = a1 + (v8 + a2) * *(int *)((char *)&dword_184532 + 2);
  v7 = v9;
  v5 = 2;
  while ( 1 )
  {
    result = v12;
    if ( v12 <= v8 )
      break;
    v11 = *(_WORD *)(a3 + 2 * v5);
    v4 = *(_WORD *)(a3 + 2 * v5 + 2);
    v5 += 2;
    if ( v11 )
    {
      v7 += v4;
      v10 = 2 * v5;
      v6 = v11 + v7;
      while ( v7 < v6 )
      {
        v13 = *(_BYTE *)(v10 + a3);
        if ( v13 < 0xF0u )
          *(_BYTE *)(v7 + dword_1BB904) = v13;
        ++v10;
        ++v7;
      }
      v5 += (v11 + 1) / 2;
    }
    else
    {
      v8 += v4;
      v9 += 640 * v4;
      v7 = v9;
    }
  }
  return result;
}
// 184532: using guessed type int dword_184532;
// 1BB904: using guessed type int dword_1BB904;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012ABCC) --------------------------------------------------------
int sub_12ABCC( int a1, int a2, int a3)
{
  int result; // eax
  int j; // [esp+0h] [ebp-38h]
  int i; // [esp+4h] [ebp-34h]
  int v6; // [esp+10h] [ebp-28h]
  int v7; // [esp+14h] [ebp-24h]
  int v8; // [esp+18h] [ebp-20h]
  int16_t v9; // [esp+28h] [ebp-10h]
  int16_t v10; // [esp+2Ch] [ebp-Ch]
  uint8_t v11; // [esp+30h] [ebp-8h]

  v10 = *(_WORD *)dword_1BC2A8;
  v9 = *(_WORD *)(dword_1BC2A8 + 2);
  v6 = 0;
  v7 = a1 + a2 * *(int *)((char *)&dword_184532 + 2);
  v8 = *(int *)((char *)&dword_184532 + 2) - *(int16_t *)dword_1BC2A8;
  for ( i = 0; ; ++i )
  {
    result = v9;
    if ( v9 <= i )
      break;
    for ( j = 0; v10 > j; ++j )
    {
      v11 = *(_BYTE *)(v6 + a3);
      if ( v11 )
      {
        if ( v11 < 0xF0u )
          *(_BYTE *)(v7 + dword_1BB904) = v11;
      }
      ++v6;
      ++v7;
    }
    v7 += v8;
  }
  return result;
}
// 184532: using guessed type int dword_184532;
// 1BB904: using guessed type int dword_1BB904;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012ACA4) --------------------------------------------------------
int sub_12ACA4( int a1, int a2, int a3)
{
  int result; // eax
  int16_t v4; // ax
  int v5; // [esp+0h] [ebp-58h]
  int v6; // [esp+4h] [ebp-54h]
  int v7; // [esp+14h] [ebp-44h]
  int v8; // [esp+1Ch] [ebp-3Ch]
  int v9; // [esp+24h] [ebp-34h]
  int v10; // [esp+28h] [ebp-30h]
  int16_t v11; // [esp+38h] [ebp-20h]
  int16_t v12; // [esp+4Ch] [ebp-Ch]
  uint8_t v13; // [esp+50h] [ebp-8h]

  v12 = *(_WORD *)(dword_1BC2A8 + 2);
  v8 = *(uint16_t *)(a3 + 2);
  v9 = a1 + (v8 + a2) * *(int *)((char *)&dword_184532 + 2);
  v7 = v9;
  v5 = 2;
  while ( 1 )
  {
    result = v12;
    if ( v12 <= v8 )
      break;
    v11 = *(_WORD *)(a3 + 2 * v5);
    v4 = *(_WORD *)(a3 + 2 * v5 + 2);
    v5 += 2;
    if ( v11 )
    {
      v7 += v4;
      v10 = 2 * v5;
      v6 = v11 + v7;
      while ( v7 < v6 )
      {
        v13 = *(_BYTE *)(v10 + a3);
        if ( v13 < 0xF0u )
          *(_BYTE *)(v7 + dword_1BB904) = v13;
        else
          *(_BYTE *)(v7 + dword_1BB904) = byte_1AB358[256 * v13 + *(uint8_t *)(v7 + dword_1BB904)];
        ++v10;
        ++v7;
      }
      v5 += (v11 + 1) / 2;
    }
    else
    {
      v8 += v4;
      v9 += 640 * v4;
      v7 = v9;
    }
  }
  return result;
}
// 184532: using guessed type int dword_184532;
// 1BB904: using guessed type int dword_1BB904;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012AE00) --------------------------------------------------------
int sub_12AE00()
{
  int result; // eax
  int i; // [esp+0h] [ebp-18h]
  int v2; // [esp+4h] [ebp-14h]
  int v3; // [esp+8h] [ebp-10h]
  int v4; // [esp+14h] [ebp-4h]

  dword_1BC2A4 = 4 * (*(int *)(dword_1BC2A8 + 4) >> 16) + dword_1BC2A8 + 16;
  v2 = *(int16_t *)dword_1BC2A4;
  v3 = *(int *)dword_1BC2A4 >> 16;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= v3 )
      break;
    v4 = *(_DWORD *)(dword_1BC2A4 + 4 * i + 4);
    if ( *(_DWORD *)&byte_1BB358[4 * v2 + 4 * i] != v4 )
    {
      *(_DWORD *)&byte_1BB358[4 * v2 + 4 * i] = v4 + 1;
      byte_1BB358[4 * v2 + 4 * i] = 1;
    }
  }
  return result;
}
// 1BC2A4: using guessed type int dword_1BC2A4;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012AEC0) --------------------------------------------------------
int sub_12AEC0( int a1, int a2, int a3)
{
  int result; // eax
  int j; // [esp+0h] [ebp-38h]
  int i; // [esp+4h] [ebp-34h]
  int v6; // [esp+10h] [ebp-28h]
  int v7; // [esp+14h] [ebp-24h]
  int v8; // [esp+18h] [ebp-20h]
  int16_t v9; // [esp+28h] [ebp-10h]
  int16_t v10; // [esp+2Ch] [ebp-Ch]
  uint8_t v11; // [esp+30h] [ebp-8h]

  v10 = *(_WORD *)dword_1BC2A8;
  v9 = *(_WORD *)(dword_1BC2A8 + 2);
  v6 = 0;
  v7 = a1 + a2 * *(int *)((char *)&dword_184532 + 2);
  v8 = *(int *)((char *)&dword_184532 + 2) - *(int16_t *)dword_1BC2A8;
  for ( i = 0; ; ++i )
  {
    result = v9;
    if ( v9 <= i )
      break;
    for ( j = 0; v10 > j; ++j )
    {
      v11 = *(_BYTE *)(v6 + a3);
      if ( v11 )
      {
        if ( v11 < 0xF0u )
          *(_BYTE *)(v7 + dword_1BB904) = v11;
        else
          *(_BYTE *)(v7 + dword_1BB904) = byte_1AB358[256 * v11 + *(uint8_t *)(v7 + dword_1BB904)];
      }
      ++v6;
      ++v7;
    }
    v7 += v8;
  }
  return result;
}
// 184532: using guessed type int dword_184532;
// 1BB904: using guessed type int dword_1BB904;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012AFCC) --------------------------------------------------------
int sub_12AFCC(int a1)
{
  int result; // eax
  int i; // [esp+4h] [ebp-24h]
  int v4; // [esp+8h] [ebp-20h]
  int v5; // [esp+Ch] [ebp-1Ch]
  int v6; // [esp+14h] [ebp-14h]
  int v7; // [esp+1Ch] [ebp-Ch]
  int v8; // [esp+20h] [ebp-8h]
  int v9; // [esp+24h] [ebp-4h]

  v4 = 0;
  result = dword_1BB904;
  v9 = dword_1BB904;
  for ( i = 0; i < 5; ++i )
  {
    v7 = *(_DWORD *)(a1 + 4 * v4);
    v8 = *(_DWORD *)(a1 + 4 * v4 + 4);
    v5 = i << 14;
    v4 += 2;
    while ( v8 || v7 )
    {
      v5 += v7;
      v6 = v8 + v4;
      while ( v4 < v6 && v5 < (int)&loc_12C00 )
        *(_DWORD *)(v9 + 4 * v5++) = *(_DWORD *)(a1 + 4 * v4++);
      v7 = *(_DWORD *)(a1 + 4 * v4);
      v8 = *(_DWORD *)(a1 + 4 * v4 + 4);
      v4 += 2;
    }
    result = i;
  }
  return result;
}
// 1BB904: using guessed type int dword_1BB904;


//----- (0012B0B7) --------------------------------------------------------
int sub_12B0B7( int a1, int a2, int a3)
{
  int result; // eax
  int16_t v4; // ax
  int v5; // [esp+0h] [ebp-6Ch]
  int v6; // [esp+Ch] [ebp-60h]
  int v7; // [esp+10h] [ebp-5Ch]
  int v8; // [esp+1Ch] [ebp-50h]
  int v9; // [esp+1Ch] [ebp-50h]
  int v10; // [esp+24h] [ebp-48h]
  int v11; // [esp+2Ch] [ebp-40h]
  int v12; // [esp+44h] [ebp-28h]
  int v13; // [esp+48h] [ebp-24h]
  int v14; // [esp+48h] [ebp-24h]
  int16_t v15; // [esp+58h] [ebp-14h]
  int16_t v16; // [esp+5Ch] [ebp-10h]

  v7 = 0;
  dword_1BB8A4(5 * (dword_1BBA64 >> 16));
  v15 = *(_WORD *)(dword_1BC2A8 + 2);
  v10 = *(uint16_t *)(a3 + 2);
  v11 = a1 + (v10 + a2) * HIDWORD(qword_184530);
  v8 = v11;
  v5 = 2;
  v13 = a1;
  v12 = a2 + v10;
  while ( 1 )
  {
    result = v15;
    if ( v15 <= v10 )
      break;
    v16 = *(_WORD *)(a3 + 2 * v5);
    v4 = *(_WORD *)(a3 + 2 * v5 + 2);
    v5 += 2;
    if ( v16 )
    {
      v14 = v4 + v13;
      v9 = v4 + v8;
      sub_138CEE(v14, v12, v14 + v16, v12);
      v6 = v9 % (int)sub_10000;
      if ( (v9 - (__CFSHL__(v9 >> 31, 16) + (v9 >> 31 << 16))) >> 16 != v7 )
      {
        v7 = (v9 - (__CFSHL__(v9 >> 31, 16) + (v9 >> 31 << 16))) >> 16;
        v6 = v9 % (int)sub_10000;
        dword_1BB8A4(v7 + 5 * (dword_1BBA64 >> 16));
      }
      memcpy(v6 + dword_1BB910[0], 2 * v5 + a3, v16);
      v8 = v16 + v9;
      v13 = v16 + v14;
      v5 += (v16 + 1) / 2;
    }
    else
    {
      v12 += v4;
      v10 += v4;
      v11 += 640 * v4;
      v8 = v11;
      v13 = a1;
    }
  }
  return result;
}
// 10000: using guessed type void __noreturn sub_10000();
// 13F35A: using guessed type int memcpy(_DWORD, _DWORD, _DWORD);
// 184530: using guessed type int64_t qword_184530;
// 1BB8A4: using guessed type int (*dword_1BB8A4)(_DWORD);
// 1BB910: using guessed type int dword_1BB910[];
// 1BBA64: using guessed type int dword_1BBA64;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012B2D9) --------------------------------------------------------
int sub_12B2D9(int a1)
{
  int result; // eax
  int i; // [esp+4h] [ebp-24h]
  int v4; // [esp+8h] [ebp-20h]
  int v5; // [esp+Ch] [ebp-1Ch]
  int v6; // [esp+14h] [ebp-14h]
  int v7; // [esp+1Ch] [ebp-Ch]
  int v8; // [esp+20h] [ebp-8h]
  int v9; // [esp+24h] [ebp-4h]

  v4 = 0;
  result = dword_1BB910;
  v9 = dword_1BB910;
  for ( i = 0; i < 5; ++i )
  {
    v7 = *(_DWORD *)(a1 + 4 * v4);
    v8 = *(_DWORD *)(a1 + 4 * v4 + 4);
    v5 = 0;
    v4 += 2;
    while ( v8 || v7 )
    {
      dword_1BB8A4(i + 5 * (dword_1BBA64 >> 16));
      while ( v8 || v7 )
      {
        v5 += v7;
        v6 = v8 + v4;
        while ( v4 < v6 )
          *(_DWORD *)(v9 + 4 * v5++) = *(_DWORD *)(a1 + 4 * v4++);
        v7 = *(_DWORD *)(a1 + 4 * v4);
        v8 = *(_DWORD *)(a1 + 4 * v4 + 4);
        v4 += 2;
      }
    }
    result = i;
  }
  return result;
}
// 1BB8A4: using guessed type int (*dword_1BB8A4)(_DWORD);
// 1BB910: using guessed type int dword_1BB910;
// 1BBA64: using guessed type int dword_1BBA64;


//----- (0012B3E0) --------------------------------------------------------
int sub_12B3E0(int result)
{
  int v1; // [esp+0h] [ebp-2Ch]
  int i; // [esp+4h] [ebp-28h]
  int v3; // [esp+8h] [ebp-24h]
  int v4; // [esp+Ch] [ebp-20h]
  int v5; // [esp+14h] [ebp-18h]
  int v6; // [esp+1Ch] [ebp-10h]
  int v7; // [esp+20h] [ebp-Ch]
  uint8_t v8; // [esp+28h] [ebp-4h]

  v1 = result;
  v3 = 0;
  for ( i = 0; i < 5; ++i )
  {
    v6 = *(uint8_t *)(v3 + v1);
    v7 = *(uint8_t *)(v3 + v1 + 1);
    v4 = i << 16;
    v3 += 2;
    if ( v7 )
    {
      while ( v7 )
      {
        v4 += v6;
        v5 = 4 * v7 + v3;
        while ( v3 < v5 )
        {
          v8 = *(_BYTE *)(v3 + v1);
          if ( v8 < 0xF0u )
            *(_BYTE *)(v4 + dword_1BB904) = v8;
          else
            *(_BYTE *)(v4 + dword_1BB904) = byte_1AB358[256 * v8 + *(uint8_t *)(v4 + dword_1BB904)];
          ++v4;
          ++v3;
        }
        v6 = *(uint8_t *)(v3 + v1);
        v7 = *(uint8_t *)(v3 + v1 + 1);
        v3 += 2;
      }
    }
    result = i;
  }
  return result;
}
// 1BB904: using guessed type int dword_1BB904;


