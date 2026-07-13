#include "orion_common.h"

/* Adresni rozsah: 0x52602 - 0x63FF0  (200 funkci) */

//----- (00052602) --------------------------------------------------------
void sub_52602()
{
  int16_t i; // dx
  int16_t j; // bx
  int v2; // esi
  _BYTE *v3; // eax

  for ( i = 0; i < word_199998; ++i )
  {
    for ( j = 0; j < word_199998; ++j )
    {
      v2 = dword_197F98 + 3753 * i;
      v3 = (_BYTE *)(v2 + j);
      if ( !v3[1412] )
      {
        *(_WORD *)(v2 + 2 * j + 1695) = 0;
        v3[1583] = 0;
        v3[1591] = 0;
      }
    }
  }
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0005265E) --------------------------------------------------------
int __fastcall sub_5265E( int a1, int a2, unsigned int a3)
{
  char *v3; // eax
  _BOOL1 v4; // zf

  v3 = (char *)(a2 + 3753 * a1 + dword_197F98);
  if ( v3[1575] == a3 )
    return 0;
  if ( a3 < 3u )
  {
    if ( !a3 )
      return 1;
    if ( a3 > 1u )
      return v3[1575] == 1;
    if ( v3[1575] < 4 )
    {
      v4 = v3[1575] == 2;
      return !v4;
    }
    return 0;
  }
  if ( a3 <= 3u )
    return v3[1575] >= 4;
  if ( a3 < 7u )
    return 1;
  if ( a3 > 7u )
  {
    if ( a3 != 8 )
      return 1;
    if ( v3[1575] < 4 )
    {
      v4 = v3[1591] == 1;
      return !v4;
    }
    return 0;
  }
  if ( v3[1575] >= 4 )
    return 0;
  v4 = v3[1583] == 1;
  return !v4;
}
// 197F98: using guessed type int dword_197F98;


//----- (0005272D) --------------------------------------------------------
int __fastcall sub_5272D(
        int a1, int a2, unsigned int a3,
        _WORD *a4,
        _WORD *a5,
        _WORD *a6,
        _WORD *a7,
        _WORD *a8,
        _WORD *a9)
{
  int v11; // eax
  int v12; // eax
  int16_t v13; // ax
  int v14; // eax
  int v15; // eax
  int v16; // edx
  int v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // edx
  int v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // eax
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int v28; // ebx
  int v29; // eax
  int v30; // ebx
  int16_t v31; // ax
  int16_t v32; // ax
  int16_t v33; // ax
  int v34; // eax
  int16_t v36; // [esp+0h] [ebp-40h]
  int v37; // [esp+18h] [ebp-28h]
  int v38; // [esp+24h] [ebp-1Ch]
  int16_t v39; // [esp+38h] [ebp-8h]
  int v40; // [esp+3Ch] [ebp-4h]

  v40 = 0;
  v39 = 4;
  *a5 = 0;
  if ( a3 < 3u )
  {
    if ( !a3 )
      return v40;
    if ( a3 > 1u )
    {
      v40 = sub_53146(v36, a2, (int16_t)(*(char *)(a2 + dword_197F98 + 3753 * v36 + 1751) + 125), 0);
      if ( *(char *)(3753 * v36 + dword_197F98 + a2 + 1559) < 50 )
        v40 = 0;
      switch ( (int16_t)v40 )
      {
        case 0:
          if ( sub_1247A0(4u) == 1 && *(_BYTE *)(3753 * v36 + dword_197F98 + a2 + 1759) )
            goto LABEL_12;
          if ( sub_1247A0(4u) == 1 )
          {
            v14 = 3753 * v36 + dword_197F98;
            if ( *(_BYTE *)(v14 + 39) == 4 )
            {
              if ( *(_BYTE *)(a2 + v14 + 1831) )
                goto LABEL_16;
            }
          }
          if ( sub_1247A0(4u) != 1 )
            goto LABEL_55;
          v15 = 3753 * v36;
          v16 = dword_197F98;
LABEL_53:
          v17 = v15 + v16;
          v18 = a2;
          goto LABEL_54;
        case 1:
          goto LABEL_60;
        case 2:
          v39 = 8;
LABEL_60:
          if ( sub_1247A0(4u) != 1 || (uint16_t)sub_4F93B(v36, a2, v39, 0, 1, 1, 0) != 1 )
            goto LABEL_35;
          if ( !byte_19B584 )
            goto LABEL_29;
          *a5 = 3;
          *a9 = byte_19B584;
          v13 = v36;
          break;
        case 3:
          if ( sub_1247A0(4u) == 1 && *(_BYTE *)(3753 * a2 + dword_197F98 + v36 + 1767) )
            goto LABEL_41;
          *a4 = 132;
          return v40;
        default:
          return v40;
      }
    }
    else
    {
      v40 = sub_53146(v36, a2, 75, 0);
      switch ( (int16_t)v40 )
      {
        case 0:
          if ( sub_1247A0(4u) == 1 && *(_BYTE *)(a2 + dword_197F98 + 3753 * v36 + 1759) )
            goto LABEL_12;
          if ( sub_1247A0(4u) == 1 )
          {
            v11 = 3753 * v36 + dword_197F98;
            if ( *(_BYTE *)(v11 + 39) == 4 )
            {
              if ( *(_BYTE *)(a2 + v11 + 1831) )
                goto LABEL_16;
            }
          }
          if ( sub_1247A0(4u) == 1 && *(_BYTE *)(3753 * v36 + dword_197F98 + a2 + 2030) )
            goto LABEL_19;
          if ( sub_1247A0(4u) == 1 )
          {
            v12 = dword_197F98 + 3753 * v36 + a2;
            if ( *(_BYTE *)(v12 + 1743) )
              goto LABEL_22;
          }
          goto LABEL_58;
        case 1:
          goto LABEL_24;
        case 2:
          v39 = 8;
LABEL_24:
          if ( sub_1247A0(2u) != 1 || (uint16_t)sub_4F93B(v36, a2, v39, 0, 1, 1, 0) != 1 )
            goto LABEL_35;
          if ( !byte_19B584 )
            goto LABEL_29;
          *a5 = 3;
          *a9 = byte_19B584;
          v13 = v36;
          break;
        case 3:
          if ( sub_1247A0(3u) == 1 && *(_BYTE *)(3753 * v36 + dword_197F98 + a2 + 1575) == 2 )
            goto LABEL_38;
          if ( sub_1247A0(4u) == 1 && *(_BYTE *)(v36 + dword_197F98 + 3753 * a2 + 1767) )
            goto LABEL_41;
          *a4 = 131;
          return v40;
        default:
          return v40;
      }
    }
    goto LABEL_28;
  }
  if ( a3 <= 3u )
  {
    v37 = a2;
    v27 = 100 - 25 * (int16_t)sub_50028(v36, a2);
    v28 = (int16_t)sub_50028(a2, v36);
    sub_500CF(v36, a2);
    v30 = (v29 - 100) / 2 + v27 + 25 * v28;
    sub_DBDB8(v36, a2);
    LOWORD(v30) = 100 * v31 + v30;
    sub_DBDB8(a2, v36);
    v38 = 3753 * v36;
    LOWORD(v30) = v30
                - 50 * v32
                - *(char *)(v37 + v38 + dword_197F98 + 2030)
                - *(char *)(v37 + v38 + dword_197F98 + 1751);
    sub_51F0F(v36, a2);
    v40 = sub_53146(
            v36,
            v37,
            (int16_t)(*(char *)(v37 + v38 + dword_197F98 + 1559)
                    + v30
                    - v33
                    - (*(uint8_t *)(v37 + v38 + dword_197F98 + 1815)
                     - 9)),
            0);
    if ( *(_BYTE *)(a2 + v38 + dword_197F98 + 1815) < 0xAu )
      v40 = 0;
    switch ( (int16_t)v40 )
    {
      case 0:
        if ( sub_1247A0(4u) == 1 && *(_BYTE *)(3753 * v36 + dword_197F98 + a2 + 1759) )
          goto LABEL_12;
        if ( sub_1247A0(4u) == 1 )
        {
          v34 = dword_197F98 + 3753 * v36;
          if ( *(_BYTE *)(v34 + 39) == 4 )
          {
            if ( *(_BYTE *)(a2 + v34 + 1831) )
              goto LABEL_16;
          }
        }
        if ( sub_1247A0(4u) != 1 )
          goto LABEL_55;
        v16 = 3753 * v36;
        v15 = dword_197F98;
        goto LABEL_53;
      case 1:
        goto LABEL_113;
      case 2:
        v39 = 8;
LABEL_113:
        if ( (uint16_t)sub_4F93B(v36, a2, v39, 1, 1, 1, 1) != 1 )
          goto LABEL_35;
        if ( !byte_19B584 )
          goto LABEL_29;
        *a5 = 3;
        *a9 = byte_19B584;
        v13 = v36;
        break;
      case 3:
        if ( sub_1247A0(4u) == 1 && *(_BYTE *)(3753 * a2 + dword_197F98 + v36 + 1767) )
          goto LABEL_41;
        *a4 = 135;
        return v40;
      default:
        return v40;
    }
LABEL_28:
    *a4 = 170;
    sub_54CC0(v13, a2);
LABEL_29:
    if ( word_19B580 )
    {
      *a5 = 1;
      *a7 = word_19B580;
      *a4 = 170;
      sub_54CC0(v36, a2);
    }
    if ( word_19B582 != -1 )
    {
      *a5 = 2;
      *a8 = word_19B582;
      *a4 = 170;
      sub_54CC0(v36, a2);
    }
    if ( byte_19B587 )
    {
      *a5 = 4;
      *a6 = (uint8_t)byte_19B587;
      *a4 = 170;
      sub_54CC0(v36, a2);
    }
    return v40;
  }
  if ( a3 < 7u )
    return v40;
  if ( a3 > 7u )
  {
    if ( a3 != 8 )
      return v40;
    v24 = sub_53146(v36, a2, 40, 0);
    v25 = 3753 * v36;
    v40 = v24;
    if ( (_WORD)v24 )
    {
      if ( (uint16_t)v24 > 2u )
      {
        if ( (_WORD)v24 != 3 )
          return v40;
        if ( sub_1247A0(3u) != 1 || *(_BYTE *)(a2 + v25 + dword_197F98 + 1575) != 2 )
        {
          if ( sub_1247A0(4u) != 1 || !*(_BYTE *)(v36 + 3753 * a2 + dword_197F98 + 1767) )
          {
            *a4 = 134;
            return v40;
          }
LABEL_41:
          *a4 = 137;
          return v40;
        }
LABEL_38:
        *a4 = 136;
        return v40;
      }
LABEL_35:
      v40 = 0;
LABEL_58:
      *a4 = 138;
      return v40;
    }
    if ( sub_1247A0(4u) != 1 || !*(_BYTE *)(a2 + v25 + dword_197F98 + 1759) )
    {
      if ( sub_1247A0(4u) != 1
        || (v26 = 3753 * v36 + dword_197F98, *(_BYTE *)(v26 + 39) != 4)
        || !*(_BYTE *)(a2 + v26 + 1831) )
      {
        if ( sub_1247A0(4u) != 1 )
          goto LABEL_55;
        v18 = dword_197F98 + 3753 * v36;
        v17 = a2;
LABEL_54:
        if ( !*(_BYTE *)(v17 + v18 + 2030) )
        {
LABEL_55:
          if ( sub_1247A0(4u) != 1 )
            goto LABEL_58;
          v19 = 3753 * v36;
          v20 = dword_197F98;
          goto LABEL_57;
        }
LABEL_19:
        *a4 = 141;
        return v40;
      }
LABEL_16:
      *a4 = 140;
      return v40;
    }
LABEL_12:
    *a4 = 139;
    return v40;
  }
  v21 = sub_53146(v36, a2, 60, 0);
  v22 = 3753 * v36;
  v40 = v21;
  if ( (_WORD)v21 )
  {
    if ( (uint16_t)v21 <= 2u )
      return 0;
    if ( (_WORD)v21 != 3 )
      return v40;
    if ( sub_1247A0(3u) != 1 || *(_BYTE *)(a2 + v22 + dword_197F98 + 1575) != 2 )
    {
      if ( sub_1247A0(4u) != 1 || !*(_BYTE *)(3753 * a2 + dword_197F98 + v36 + 1767) )
      {
        *a4 = 133;
        return v40;
      }
      goto LABEL_41;
    }
    goto LABEL_38;
  }
  if ( sub_1247A0(4u) == 1 && *(_BYTE *)(a2 + v22 + dword_197F98 + 1759) )
    goto LABEL_12;
  if ( sub_1247A0(4u) == 1 )
  {
    v23 = dword_197F98 + 3753 * v36;
    if ( *(_BYTE *)(v23 + 39) == 4 )
    {
      if ( *(_BYTE *)(a2 + v23 + 1831) )
        goto LABEL_16;
    }
  }
  if ( sub_1247A0(4u) == 1 && *(_BYTE *)(3753 * v36 + dword_197F98 + a2 + 2030) )
    goto LABEL_19;
  if ( sub_1247A0(4u) != 1 )
    goto LABEL_58;
  v20 = 3753 * v36;
  v19 = dword_197F98;
LABEL_57:
  v12 = v19 + v20 + a2;
  if ( !*(_BYTE *)(v12 + 1743) )
    goto LABEL_58;
LABEL_22:
  *a4 = *(uint8_t *)(v12 + 1743) + 141;
  return v40;
}
// 5279B: variable 'v36' is possibly undefined
// 52F27: variable 'v29' is possibly undefined
// 52F3D: variable 'v31' is possibly undefined
// 52F4D: variable 'v32' is possibly undefined
// 52F8F: variable 'v33' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 19B580: using guessed type int16_t word_19B580;
// 19B582: using guessed type int16_t word_19B582;
// 19B584: using guessed type char byte_19B584;
// 19B587: using guessed type char byte_19B587;


//----- (00053146) --------------------------------------------------------
int __fastcall sub_53146( int a1, int a2, int a3, int a4)
{
  int v6; // edx
  int v7; // eax
  int v8; // eax
  char *v9; // ebx
  int v10; // eax
  int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // eax
  int16_t v17; // ax
  int16_t v18; // bx
  int v20; // [esp+0h] [ebp-18h]
  char *v21; // [esp+Ch] [ebp-Ch]
  int v22; // [esp+10h] [ebp-8h]

  v6 = 3753 * a1 + dword_197F98;
  v7 = v6 + a2;
  v20 = v6;
  LOWORD(v6) = *(char *)(v7 + 1751);
  v22 = v6;
  LOWORD(v6) = *(char *)(v7 + 1559);
  LOWORD(v7) = *(char *)(v7 + 2030);
  v21 = (char *)(v7 + v6 + v22);
  if ( *(_BYTE *)(v20 + 39) == 4 )
    v21 += v7;
  v8 = dword_197F98 + 3753 * a1;
  if ( *(_BYTE *)(v8 + 39) == 4 && *(_BYTE *)(a2 + v8 + 1831) == 1 )
    LOWORD(a3) = a3 - word_180CD8;
  else
    LOWORD(a3) = a3 - word_180CCC[*(uint8_t *)(dword_197F98 + 3753 * a1 + 39)];
  v9 = &v21[sub_1247A0(0x64u) - a3];
  switch ( a4 )
  {
    case 0:
      LOWORD(v9) = *(_WORD *)(dword_197F98 + 3753 * a1 + 2 * a2 + 1679) + (_WORD)v9;
      break;
    case 1:
      LOWORD(v9) = *(_WORD *)(dword_197F98 + 3753 * a1 + 2 * a2 + 1695) + (_WORD)v9;
      break;
    case 2:
      LOWORD(v9) = *(_WORD *)(2 * a2 + 3753 * a1 + dword_197F98 + 1711) + (_WORD)v9;
      break;
    case 3:
      LOWORD(v9) = *(_WORD *)(2 * a2 + dword_197F98 + 3753 * a1 + 1727) + (_WORD)v9;
      break;
    default:
      break;
  }
  sub_524C3(a1, a2);
  v10 = 2 * a2;
  v11 = 3753 * a1;
  switch ( a4 )
  {
    case 0:
      v12 = v10 + dword_197F98 + v11;
      *(_WORD *)(v12 + 1679) -= sub_1247A0(0x1Eu) + 20;
      break;
    case 1:
      v13 = v10 + dword_197F98 + v11;
      *(_WORD *)(v13 + 1695) -= sub_1247A0(0x1Eu) + 20;
      break;
    case 2:
      v14 = v10 + dword_197F98 + v11;
      *(_WORD *)(v14 + 1711) -= sub_1247A0(0x32u) + 20;
      break;
    case 3:
      v15 = v10 + dword_197F98 + v11;
      *(_WORD *)(v15 + 1727) -= sub_1247A0(0x32u) + 50;
      break;
    default:
      break;
  }
  v16 = dword_197F98 + 3753 * a2;
  if ( *(_BYTE *)(v16 + 2227) )
  {
    LOWORD(v9) = (_WORD)v9 + 50;
  }
  else if ( *(_BYTE *)(v16 + 2226) )
  {
    LOWORD(v9) = (_WORD)v9 - 50;
  }
  if ( *(_BYTE *)(dword_197F98 + 3753 * a2 + 2232) )
    LOWORD(v9) = (_WORD)v9 + 25;
  if ( *(_BYTE *)(dword_197F98 + 3753 * a2 + 479) == 3 )
    LOWORD(v9) = (_WORD)v9 + 30;
  sub_E5E09(a2);
  v18 = v17 + (_WORD)v9;
  if ( v18 < -75 )
    return 0;
  if ( v18 < -50 )
    return 2;
  if ( v18 >= 0 )
    return 3;
  return 1;
}
// 533BF: variable 'v17' is possibly undefined
// 180CCC: using guessed type int16_t word_180CCC[6];
// 180CD8: using guessed type int16_t word_180CD8;
// 197F98: using guessed type int dword_197F98;


//----- (000533F4) --------------------------------------------------------
int __fastcall sub_533F4( int a1, int a2, _WORD *a3)
{
  int v5; // ecx
  unsigned int v6; // edx
  int v7; // ebx
  int result; // eax
  signed int v10; // [esp+4h] [ebp-8h]
  int v11; // [esp+8h] [ebp-4h]
  unsigned int v12; // [esp+8h] [ebp-4h]

  v5 = a2;
  v11 = sub_51DCE(a2, a1);
  v12 = sub_1247A0(0xC8u) - v11;
  v6 = v12 - 50 * sub_50028(a2, a1);
  v10 = word_180DB8[*(uint8_t *)(3753 * v5 + dword_197F98 + 39)];
  if ( (int)sub_1247A0(0x64u) <= v10 && (int16_t)v6 > 100 )
  {
    sub_51078(a1, v5);
    *a3 = 155;
  }
  *a3 = (*(_BYTE *)(dword_197F98 + 3753 * a2 + 39) == 4) + 153;
  v7 = dword_197F98;
  result = dword_197F98 + 3753 * a1;
  *(_BYTE *)(a2 + result + 1831) = 1;
  *(_BYTE *)(a1 + 3753 * a2 + v7 + 1831) = 1;
  return result;
}
// 180DB8: using guessed type int16_t word_180DB8[10];
// 197F98: using guessed type int dword_197F98;


//----- (000534C9) --------------------------------------------------------
void __fastcall sub_534C9( int a1, int a2, _WORD *a3)
{
  int v4; // ecx
  int v5; // esi
  unsigned int v6; // edx
  int v7; // eax
  signed int v9; // [esp+4h] [ebp-8h]
  int v10; // [esp+8h] [ebp-4h]
  unsigned int v11; // [esp+8h] [ebp-4h]

  v4 = a1;
  v10 = sub_51DCE(a2, a1);
  v11 = sub_1247A0(0xC8u) - v10;
  v5 = 3753 * a2;
  v6 = v11 - 50 * sub_50028(a2, v4);
  v9 = word_180DB8[*(uint8_t *)(v5 + dword_197F98 + 39)];
  if ( (int)sub_1247A0(0x64u) <= v9 && (int16_t)v6 > 100 )
  {
    v7 = v4 + v5 + dword_197F98;
    if ( *(_BYTE *)(v7 + 1575) == 1 || *(_BYTE *)(v7 + 1575) == 2 )
    {
      sub_5138E(a1, a2);
      *a3 = 159;
    }
  }
  *a3 = 158;
}
// 180DB8: using guessed type int16_t word_180DB8[10];
// 197F98: using guessed type int dword_197F98;


//----- (0005356C) --------------------------------------------------------
void __fastcall sub_5356C( int a1, int a2, _WORD *a3)
{
  int v4; // ecx
  int v5; // esi
  unsigned int v6; // edx
  int v7; // eax
  signed int v9; // [esp+4h] [ebp-8h]
  int v10; // [esp+8h] [ebp-4h]
  unsigned int v11; // [esp+8h] [ebp-4h]

  v4 = a1;
  v10 = sub_51DCE(a2, a1);
  v11 = sub_1247A0(0xC8u) - v10;
  v5 = 3753 * a2;
  v6 = v11 - 50 * sub_50028(a2, v4);
  v9 = word_180DB8[*(uint8_t *)(v5 + dword_197F98 + 39)];
  if ( (int)sub_1247A0(0x64u) <= v9 && (int16_t)v6 > 100 )
  {
    v7 = v4 + v5 + dword_197F98;
    if ( *(_BYTE *)(v7 + 1575) == 1 || *(_BYTE *)(v7 + 1575) == 2 )
    {
      sub_5138E(a1, a2);
      *a3 = 157;
    }
  }
  *a3 = 156;
}
// 180DB8: using guessed type int16_t word_180DB8[10];
// 197F98: using guessed type int dword_197F98;


//----- (0005360F) --------------------------------------------------------
int __fastcall sub_5360F( int a1, int a2, _WORD *a3)
{
  int v6; // ebx
  int v7; // edx
  unsigned int v8; // edx
  int v9; // eax
  int result; // eax
  signed int v11; // [esp+0h] [ebp-8h]
  unsigned int v12; // [esp+4h] [ebp-4h]

  v6 = a2;
  v7 = sub_51DCE(a2, a1);
  v12 = sub_1247A0(0xC8u) - v7;
  v8 = v12 - 50 * sub_50028(v6, a1);
  v11 = word_180DB8[*(uint8_t *)(3753 * v6 + dword_197F98 + 39)];
  if ( (int)sub_1247A0(0x96u) <= v11 && (int16_t)v8 > 75 )
  {
    sub_51078(a1, v6);
    *a3 = 173;
  }
  v9 = 3753 * a2;
  LOWORD(v9) = *(_BYTE *)(dword_197F98 + v9 + 39) == 4;
  result = v9 + 171;
  *a3 = result;
  return result;
}
// 180DB8: using guessed type int16_t word_180DB8[10];
// 197F98: using guessed type int dword_197F98;


//----- (000536BC) --------------------------------------------------------
int __fastcall sub_536BC( int a1, int a2, _WORD *a3)
{
  int result; // eax

  result = dword_197F98 + 3753 * a2;
  if ( *(_BYTE *)(result + 39) == 4
    && !*(_BYTE *)(a2 + 3753 * a1 + dword_197F98 + 1831)
    && ((result += a1, *(_BYTE *)(result + 1575) == 1) || *(_BYTE *)(result + 1575) == 2) )
  {
    *a3 = 66;
  }
  else
  {
    *a3 = 160;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (00053723) --------------------------------------------------------
void __fastcall sub_53723( int a1, int a2, int a3, int a4, _WORD *a5)
{
  int v7; // ebx
  int v8; // ebx
  int v9; // eax
  int16_t v10; // ax
  int v11; // ecx
  int v12; // ecx
  unsigned int v13; // edx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // [esp+0h] [ebp-20h]
  int v21; // [esp+4h] [ebp-1Ch]
  int v22; // [esp+Ch] [ebp-14h]
  int v23; // [esp+14h] [ebp-Ch]

  v20 = dword_197F98;
  *(_BYTE *)(dword_197F98 + 3753 * a2 + a1 + 1767) = a3;
  v7 = 0;
  switch ( a3 )
  {
    case 1:
      *a5 = 163;
      v8 = *(_DWORD *)(v20 + 3753 * a1 + 180);
      if ( v8 < 10 )
        v8 = 10;
      v7 = a4 / v8 / 10;
      if ( v7 > 8 )
        v7 = 8;
      break;
    case 2:
      v7 = 2;
      *a5 = 162;
      break;
    case 3:
      v23 = 1;
      v21 = 0;
      *a5 = 161;
      v9 = 0;
      do
      {
        if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + v21 + 279) == 3
          && (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v9)] > v23 )
        {
          v23 = (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + v9)];
        }
        ++v21;
        v9 += 13;
      }
      while ( v21 < 204 );
      v7 = 5 * (uint8_t)byte_17D91A[23 * *(int16_t *)((char *)&word_17E07F + 13 * a4)] / v23;
      break;
    case 4:
      *a5 = 164;
      sub_E5B69(a1, a4);
      v7 = v10 / 2 + 1;
      break;
    default:
      break;
  }
  if ( v7 )
  {
    v22 = dword_197F98;
    v11 = 2 * a2 + dword_197F98 + 3753 * a1;
    *(int16_t *)(v11 + 2071) /= (int16_t)v7;
    v12 = 2 * a1 + v22 + 3753 * a2;
    *(int16_t *)(v12 + 2071) /= (int16_t)v7;
  }
  v13 = (sub_1247A0(4u) + 4) * v7;
  v14 = a2 + dword_197F98 + 3753 * a1;
  if ( (int)(v13 + *(char *)(v14 + 1559)) <= 100 )
    *(_BYTE *)(v14 + 1559) += v13;
  else
    *(_BYTE *)(v14 + 1559) = 100;
  v15 = a2 + dword_197F98 + 3753 * a1;
  if ( *(char *)(v15 + 1559) > 100 )
    *(_BYTE *)(v15 + 1559) = 100;
  v16 = a2 + dword_197F98 + 3753 * a1;
  if ( v7 + *(char *)(v16 + 1567) <= 100 )
    *(_BYTE *)(v16 + 1567) += v7;
  else
    *(_BYTE *)(v16 + 1567) = 100;
  v17 = 3753 * a1 + dword_197F98 + a2;
  if ( *(char *)(v17 + 1567) > 100 )
    *(_BYTE *)(v17 + 1567) = 100;
  v18 = a2 + dword_197F98 + 3753 * a1;
  v19 = a1 + 3753 * a2 + dword_197F98;
  *(_BYTE *)(v19 + 1567) = *(_BYTE *)(v18 + 1567);
  *(_BYTE *)(v19 + 1559) = *(_BYTE *)(v18 + 1559);
  JUMPOUT(0x4EB00);
}
// 539B0: control flows out of bounds to 4EB00
// 53852: variable 'v10' is possibly undefined
// 17E07F: using guessed type int16_t word_17E07F;
// 197F98: using guessed type int dword_197F98;


//----- (000539D9) --------------------------------------------------------
void __fastcall sub_539D9( int a1, int a2, int a3, int a4, _WORD *a5, _WORD *a6)
{
  int v6; // edi
  int v7; // ebx
  int v8; // ebx
  int v9; // edx
  unsigned int v10; // ebx
  int v11; // ebx
  int16_t v12; // ax
  int v13; // eax
  int16_t v14; // bx
  int v15; // ebx
  int16_t v16; // ax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int16_t v20; // ax
  int v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // edx
  int v26; // ebx
  int v27; // eax
  int v28; // eax
  int v29; // edi
  char v30; // dl
  int v31; // [esp+0h] [ebp-38h]
  int v32; // [esp+14h] [ebp-24h]
  int v33; // [esp+18h] [ebp-20h]

  v6 = a2;
  v33 = a1;
  v7 = (int16_t)sub_51DCE(a1, a2);
  v8 = sub_51E98(v33, a2) + v7;
  v9 = (v8 + (int16_t)sub_51E3B(v33, a2)) / 3;
  v10 = v9 + sub_1247A0(0xC8u);
  v11 = sub_50FDF(v33, v6) + v10;
  if ( *(_BYTE *)(dword_197F98 + 3753 * v6 + 39) == 4 && *(_BYTE *)(3753 * v33 + dword_197F98 + v6 + 1831) == 1 )
    v12 = word_180CD8;
  else
    v12 = word_180CCC[*(uint8_t *)(dword_197F98 + 3753 * a2 + 39)];
  LOWORD(v11) = 2 * v12 + v11;
  switch ( a3 )
  {
    case 0:
      v13 = a4 + 3753 * a2 + dword_197F98;
      if ( *(_BYTE *)(v13 + 1575) == 1 )
      {
        v14 = v11 - 75;
      }
      else if ( *(_BYTE *)(v13 + 1575) == 2 )
      {
        v14 = v11 - 150;
      }
      else
      {
        v14 = v11 - 25;
      }
      v15 = v14 - *(char *)(a4 + dword_197F98 + 3753 * a2 + 1559) / 2;
      v16 = sub_51DCE(a2, a4);
      v11 = (int16_t)v15
          - ((int)(v16 - (__CFSHL__((uint64_t)v16 >> 32, 2) + 4 * ((uint64_t)v16 >> 32))) >> 2);
      if ( *(_BYTE *)(3753 * a4 + dword_197F98 + 40) != 100 )
        LOWORD(v11) = v11 - 25;
      break;
    case 1:
      v17 = 3753 * a4;
      LOWORD(v11) = v11 - (word_180CCC[*(uint8_t *)(dword_197F98 + v17 + 39)] + 80);
      if ( *(_BYTE *)(dword_197F98 + v17 + 40) == 100 )
        LOWORD(v11) = 0;
      break;
    case 2:
      LOWORD(v18) = 2 * *(char *)(dword_197F98 + 3753 * a2 + a4 + 1559);
      goto LABEL_16;
    case 3:
    case 5:
    case 8:
      LOWORD(v11) = v11 - 50;
      break;
    case 4:
      LOWORD(v11) = v11 - 150;
      break;
    case 6:
      sub_FC845(a1, a4);
      v18 = 100 * v19 / (int16_t)sub_DCAEE(a1);
      goto LABEL_16;
    case 7:
      v31 = *(int16_t *)(dword_197F98 + 3753 * a2 + 166);
      sub_E5B69(a2, a4);
      v18 = 1000 * v20 / v31;
      if ( (int16_t)v18 > 300 )
        LOWORD(v18) = 300;
LABEL_16:
      LOWORD(v11) = v11 - v18;
      break;
    default:
      break;
  }
  sub_524C3(a1, a2);
  sub_524C3(a1, a2);
  sub_524C3(a1, a2);
  sub_524C3(a1, a2);
  sub_524C3(a1, a2);
  v21 = a2 + 3753 * a1 + dword_197F98;
  if ( *(_BYTE *)(v21 + 1575) == 1 || *(_BYTE *)(v21 + 1575) == 2 )
  {
    if ( (int16_t)v11 < -100 || sub_53E96(a2, a1) == 6 )
    {
LABEL_26:
      *a6 = 165;
      sub_51078(a1, a2);
LABEL_36:
      *a5 = 0;
      goto LABEL_46;
    }
    v32 = 3753 * a2;
    v22 = 3753 * a1;
    if ( (int16_t)v11 < -50 )
    {
      v23 = dword_197F98;
      ++*(_BYTE *)(a2 + dword_197F98 + v22 + 1823);
      ++*(_BYTE *)(a1 + v23 + v32 + 1823);
      *a6 = 166;
      sub_5138E(a1, a2);
      sub_5175B(a1, a2);
      sub_519AC(a1, a2);
      goto LABEL_36;
    }
    if ( (int16_t)v11 < -25 )
    {
      v24 = a2 + dword_197F98 + v22;
      v25 = v32 + dword_197F98;
      ++*(_BYTE *)(v24 + 1823);
      ++*(_BYTE *)(v25 + a1 + 1823);
      *(_BYTE *)(v24 + 1567) -= 10;
      if ( *(char *)(v24 + 1567) < -100 )
        *(_BYTE *)(v24 + 1567) = -100;
      v26 = a2 + dword_197F98 + 3753 * a1;
      v27 = a1 + dword_197F98 + 3753 * a2;
LABEL_33:
      *(_BYTE *)(v27 + 1567) = *(_BYTE *)(v26 + 1567);
      *a6 = 167;
      goto LABEL_36;
    }
    if ( (v11 & 0x8000u) != 0 )
      goto LABEL_35;
  }
  else
  {
    if ( (int16_t)v11 < -150 || sub_53E96(a2, a1) == 6 )
      goto LABEL_26;
    if ( (int16_t)v11 < -75 )
    {
      v28 = a2 + dword_197F98 + 3753 * a1;
      v29 = a1 + dword_197F98 + 3753 * a2;
      ++*(_BYTE *)(v28 + 1823);
      ++*(_BYTE *)(v29 + 1823);
      *(_BYTE *)(v28 + 1567) -= 10;
      if ( *(char *)(v28 + 1567) < -100 )
        *(_BYTE *)(v28 + 1567) = -100;
      v26 = a2 + dword_197F98 + 3753 * a1;
      v27 = 3753 * a2 + dword_197F98 + a1;
      goto LABEL_33;
    }
    if ( (v11 & 0x8000u) != 0 )
    {
LABEL_35:
      *a6 = 168;
      goto LABEL_36;
    }
    if ( (int16_t)v11 <= 0 )
    {
LABEL_46:
      if ( *a5 == 1 && a3 == 5 )
      {
        v30 = sub_1247A0(0x32u) + 10;
        *(_BYTE *)(3753 * a2 + dword_197F98 + a4 + 2054) = sub_1247A0(0x32u) + v30;
      }
      JUMPOUT(0x4E9FD);
    }
  }
  *a6 = 169;
  *a5 = 1;
  goto LABEL_46;
}
// 53E91: control flows out of bounds to 4E9FD
// 53BBD: variable 'v19' is possibly undefined
// 53BFA: variable 'v20' is possibly undefined
// 180CCC: using guessed type int16_t word_180CCC[6];
// 180CD8: using guessed type int16_t word_180CD8;
// 197F98: using guessed type int dword_197F98;


//----- (00053E96) --------------------------------------------------------
int16_t __fastcall sub_53E96( int a1, int a2)
{
  int v3; // eax

  v3 = dword_197F98 + 3753 * a1;
  if ( *(_BYTE *)(v3 + 39) == 4 && *(_BYTE *)(a2 + v3 + 1831) == 1 )
    return 6;
  else
    return *(uint8_t *)(3753 * a1 + dword_197F98 + 39);
}
// 197F98: using guessed type int dword_197F98;


//----- (00053EDB) --------------------------------------------------------
void sub_53EDB()
{
  int16_t i; // si
  int v1; // eax
  int16_t v2; // dx
  int v3; // edx
  int v4; // edx
  int v5; // ebx
  int v6; // eax
  int v7; // edx
  _BYTE *v8; // eax
  int v9; // edi
  int16_t v10; // ax
  int v11; // edi
  int v12; // ebx
  signed int v13; // edx
  int v14; // ebx
  int v15; // edx
  int v16; // edi
  int v17; // eax
  int v18; // edx
  int16_t k; // bx
  signed int v20; // edx
  int16_t j; // bx
  int v22; // ebx
  unsigned int v23; // edx
  int v24; // eax
  int v25; // edi
  char v26; // cl
  int v27; // eax
  int16_t v28; // dx
  int16_t v29; // ax
  int v30; // eax
  int v31; // edi
  int v32; // ecx
  int v33; // edi
  int v34; // edi
  _WORD v35[32]; // [esp+0h] [ebp-6Ch] BYREF
  int v36; // [esp+40h] [ebp-2Ch]
  int v37; // [esp+44h] [ebp-28h]
  int v38; // [esp+48h] [ebp-24h]
  int v39; // [esp+4Ch] [ebp-20h]
  int v40; // [esp+50h] [ebp-1Ch]
  int v41; // [esp+54h] [ebp-18h]
  int v42; // [esp+58h] [ebp-14h]
  int v43; // [esp+5Ch] [ebp-10h]
  int v44; // [esp+60h] [ebp-Ch]
  int v45; // [esp+64h] [ebp-8h]
  int v46; // [esp+68h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    if ( i >= word_199998 )
      JUMPOUT(0x4DAAB);
    v1 = 3753 * i + dword_197F98;
    if ( *(_BYTE *)(v1 + 40) != 100 && !*(_BYTE *)(v1 + 36) )
    {
      v2 = 0;
      v46 = 0;
      LOWORD(v45) = 0;
      while ( (int16_t)v45 < word_199998 )
      {
        if ( *(char *)((int16_t)v45 + dword_197F98 + 3753 * i + 1575) >= 4 )
        {
          if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v45 + 40) == 100 )
            ++v2;
          else
            ++v46;
        }
        LOWORD(v45) = v45 + 1;
      }
      if ( *(int16_t *)(dword_197F98 + 3753 * i + 1991) == -1 && v2 <= 0 )
      {
        LOWORD(v45) = 0;
        while ( (int16_t)v45 < word_199998 )
        {
          v4 = (int16_t)v45;
          v5 = 3753 * i + dword_197F98;
          v6 = v5 + 2 * (int16_t)v45;
          if ( *(int16_t *)(v6 + 2103) == -1 )
          {
            *(_WORD *)(v6 + 2119) = 0;
            *(_DWORD *)(v5 + 4 * v4 + 2135) = 0;
          }
          LOWORD(v45) = v45 + 1;
        }
        LOWORD(v45) = 0;
        while ( (int16_t)v45 < word_199998 )
        {
          v41 = (int16_t)v45;
          v7 = dword_197F98 + 3753 * (int16_t)v45;
          if ( *(_BYTE *)(v7 + 40) != 100
            || (v42 = i, v8 = (_BYTE *)(v41 + 3753 * i + dword_197F98), (char)v8[1575] >= 4)
            || v8[1429] != 1
            || v8[1412] != 1
            || *(_BYTE *)(v7 + 36)
            || v8[1871] == 1
            || v8[1871] == 2
            || v8[1871] == 3 )
          {
            v35[(int16_t)v45] = 0;
          }
          else
          {
            v9 = v41;
            sub_544A1(v42, v41, &v35[v41 + 24], &v35[v41 + 8], (int)&v35[v41 + 16]);
            v35[v9] = v10;
          }
          LOWORD(v45) = v45 + 1;
        }
        LOWORD(v45) = 0;
LABEL_68:
        if ( (int16_t)v45 >= word_199998 )
          continue;
        v11 = 3753 * i;
        v12 = (int16_t)v45;
        if ( *(_BYTE *)(v11 + dword_197F98 + (int16_t)v45 + 1839) )
        {
          v13 = word_181070[sub_53E96(i, v45)];
          if ( (int)sub_1247A0(0x64u) > v13 )
          {
            if ( v35[v12] )
            {
              *(_BYTE *)(v11 + dword_197F98 + 2070) = sub_1247A0(0x14u) + 20;
LABEL_67:
              LOWORD(v45) = v45 + 1;
              goto LABEL_68;
            }
          }
        }
        v44 = (int16_t)v45;
        v14 = (int16_t)v45;
        if ( v35[v14] == 2 )
        {
          v39 = i;
          if ( sub_53E96(i, v44) != 4 )
          {
            v15 = v44;
            v16 = dword_197F98;
            v43 = 3753 * v39;
            v17 = dword_197F98 + 3753 * v39;
            *(_BYTE *)(v44 + v17 + 2191) = 0;
            *(_BYTE *)(v39 + v16 + 3753 * v15 + 2191) = 0;
            v18 = v17 + v14 * 2;
            if ( *(int16_t *)(v17 + v14 * 2 + 2103) == -1
              || (v40 = (int16_t)v35[v14 + 24], *(_DWORD *)(v17 + 4 * v44 + 2135) <= v40) )
            {
              *(_BYTE *)(3753 * i + dword_197F98 + 2070) = sub_1247A0(0x14u) + 20;
              if ( (int16_t)v46 > 0 )
              {
                v20 = (uint8_t)byte_199CB0;
                if ( (int)sub_1247A0(4u) < v20 )
                {
                  for ( j = 0; j < word_199998; ++j )
                  {
                    if ( *(_BYTE *)(dword_197F98 + 3753 * j + 40) != 100
                      && *(char *)(j + 3753 * i + dword_197F98 + 1575) >= 4 )
                    {
                      sub_524FB(i, j);
                    }
                  }
                }
              }
            }
            else if ( *(int16_t *)(v18 + 2119) > 0 )
            {
              *(_WORD *)(v17 + 1991) = *(_WORD *)(v18 + 2103);
              *(_BYTE *)(v17 + 1993) = v35[v14 + 8];
              *(_BYTE *)(v43 + dword_197F98 + 2070) = sub_1247A0(0x14u) + 20;
              if ( (int16_t)v46 > 0 )
              {
                for ( k = 0; k < word_199998; ++k )
                {
                  if ( *(_BYTE *)(dword_197F98 + 3753 * k + 40) != 100
                    && *(char *)(k + dword_197F98 + 3753 * i + 1575) >= 4 )
                  {
                    sub_524FB(i, k);
                  }
                }
              }
            }
            goto LABEL_67;
          }
        }
        v22 = (int16_t)v45;
        v23 = 2 * (int16_t)v45;
        v37 = 3753 * (int16_t)v45;
        if ( v35[v23 / 2] == 1 )
        {
          v38 = i;
          v40 = 3753 * i;
          v24 = dword_197F98 + v40;
          v25 = i + v37 + dword_197F98;
          *(_BYTE *)((int16_t)v45 + v24 + 2191) = 0;
          *(_BYTE *)(v25 + 2191) = 0;
          *(_BYTE *)(v22 + v24 + 2183) = v35[v23 / 2 + 8];
          v26 = sub_1247A0(0x14u);
          v27 = v40 + dword_197F98;
          *(_BYTE *)(v27 + 2070) = v26 + 20;
          *(_WORD *)(v23 + v27 + 1631) = 10000;
          *(_BYTE *)(v22 + v27 + 1615) = 0;
          v28 = v22;
          *(_BYTE *)(v22 + v27 + 1623) = 106;
          v29 = v38;
        }
        else if ( v35[(int16_t)v45] == 3 )
        {
          v38 = i;
          v36 = 3753 * i;
          v30 = dword_197F98 + v36;
          v31 = i + v37 + dword_197F98;
          *(_BYTE *)((int16_t)v45 + v30 + 2191) = 0;
          *(_BYTE *)(v31 + 2191) = 0;
          *(_WORD *)(v30 + v23 + 1631) = 10000;
          *(_BYTE *)(v22 + v30 + 1615) = 0;
          *(_BYTE *)(v22 + v30 + 1623) = 105;
          *(_BYTE *)(v36 + dword_197F98 + 2070) = sub_1247A0(0x14u) + 10;
          v29 = v38;
          v28 = v22;
        }
        else
        {
          if ( v35[(int16_t)v45] != 4 )
            goto LABEL_67;
          v36 = i;
          v40 = 3753 * i;
          v38 = dword_197F98 + v40;
          v32 = dword_197F98 + v40;
          v33 = v37 + dword_197F98;
          *(_BYTE *)(v32 + 1995) = v45;
          v34 = v36 + v33;
          *(_BYTE *)(v22 + v32 + 2191) = 0;
          *(_BYTE *)(v34 + 2191) = 0;
          *(_WORD *)(v32 + v23 + 1631) = 10000;
          *(_BYTE *)(v22 + v32 + 1615) = 0;
          *(_BYTE *)(v22 + v32 + 1623) = 124;
          *(_BYTE *)(v40 + dword_197F98 + 2070) = sub_1247A0(0x14u) + 20;
          v29 = v36;
          v28 = v22;
        }
        sub_54CC0(v29, v28);
        goto LABEL_67;
      }
      v3 = 3753 * i;
      if ( !*(_BYTE *)(v3 + dword_197F98 + 2070) )
        *(_WORD *)(v3 + dword_197F98 + 1991) = -1;
    }
  }
}
// 5449C: control flows out of bounds to 4DAAB
// 54097: variable 'v10' is possibly undefined
// 181070: using guessed type int16_t word_181070[];
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (000544A1) --------------------------------------------------------
void __fastcall sub_544A1( int a1, int a2, int16_t *a3, int16_t *a4, int a5)
{
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // edx
  signed int v15; // edx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  signed int v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // ebx
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int16_t i; // dx
  int v28; // eax
  int16_t v29; // ax
  int16_t v30; // dx
  int v31; // eax
  int v32; // eax
  int16_t v33; // ax
  int v34; // eax
  int v35; // ebx
  int v36; // ebx
  int v37; // edx
  int v38; // edx
  int v39; // eax
  int v40; // eax
  int v41; // edx
  int16_t j; // ax
  int16_t *v43; // edx
  int16_t v44; // ax
  signed int v45; // edx
  int v46; // [esp+0h] [ebp-50h]
  int v47; // [esp+8h] [ebp-48h]
  int v48; // [esp+10h] [ebp-40h]
  int v49; // [esp+14h] [ebp-3Ch]
  int16_t v52; // [esp+20h] [ebp-30h]
  int v53; // [esp+24h] [ebp-2Ch]
  int16_t v54; // [esp+28h] [ebp-28h]
  int16_t v55; // [esp+2Ch] [ebp-24h]
  int v56; // [esp+30h] [ebp-20h]
  int16_t v57; // [esp+34h] [ebp-1Ch]
  unsigned int v58; // [esp+3Ch] [ebp-14h]
  int16_t v59; // [esp+40h] [ebp-10h]
  int16_t v60; // [esp+44h] [ebp-Ch]
  int16_t v61; // [esp+48h] [ebp-8h]

  v7 = dword_197F98 + 3753 * a1 + a2;
  if ( *(char *)(v7 + 1559) > 49 )
  {
    v8 = *(char *)(v7 + 1559);
    v9 = 5;
  }
  else
  {
    v8 = *(char *)(v7 + 1559);
    v9 = 10;
  }
  v53 = v8 / v9;
  v10 = v8 / v9;
  v47 = 3753 * a1;
  v11 = a2 + v47 + dword_197F98;
  v54 = 67;
  v61 = 200;
  if ( *(char *)(v11 + 1823) > 0 && *(_BYTE *)(v11 + 1743) )
  {
    v49 = -10 * *(char *)(v11 + 1823);
    v46 = word_180CF0[sub_53E96(a1, a2)];
    if ( (int16_t)(v49 / v46) < (int16_t)v10 )
    {
      v53 = v49 / v46;
      v54 = *(uint8_t *)(v47 + dword_197F98 + a2 + 1743) + 70;
    }
    v10 += v49 / v46;
  }
  v12 = 3753 * a1 + dword_197F98;
  if ( *(_BYTE *)(v12 + 1550) == 1 )
  {
    if ( *(_BYTE *)(v12 + 40) == 2 || (v13 = *(int16_t *)(v12 + 166), v13 > (int16_t)sub_E5B17(a2) / 2) )
    {
      LOWORD(v53) = -150;
      v10 = -150;
      v54 = 114;
    }
  }
  if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 39) == 3 )
  {
    v14 = (uint8_t)byte_199CB0 + 1;
    if ( (int)sub_1247A0(0xC8u) <= v14 )
    {
      LOWORD(v53) = -150;
      v10 = -150;
      v54 = 109;
      v61 = 100;
    }
  }
  v15 = *(int16_t *)(dword_197F98 + 3753 * a1 + 2028);
  if ( (int)sub_1247A0(0x64u) < v15 )
  {
    LOWORD(v53) = -150;
    v10 = -150;
    v54 = 119;
  }
  v48 = 3753 * a1;
  if ( *(_BYTE *)(v48 + dword_197F98 + 39) == 1 )
  {
    sub_500CF(a1, a2);
    if ( v16 >= 100 )
    {
      v17 = dword_197F98 + v48 + 4 * a2;
      if ( *(int *)(v17 + 2135) >= 200 && *(int16_t *)(dword_197F98 + v48 + 2 * a2 + 2103) != -1 )
      {
        v18 = -*(_DWORD *)(v17 + 2135) / 20;
        if ( (int16_t)v18 < (int16_t)v53 )
        {
          v54 = 115;
          LOWORD(v53) = v18;
        }
        v10 += v18;
      }
    }
  }
  if ( !*(_BYTE *)(3753 * a1 + dword_197F98 + 39) )
  {
    v19 = (int16_t)sub_DCB47(a1, a2);
    if ( (int)sub_1247A0(0x190u) <= v19 )
    {
      LOWORD(v53) = -150;
      v10 = -150;
      v54 = 121;
    }
  }
  v20 = 3753 * a1 + dword_197F98 + a2;
  v21 = 3 * *(char *)(v20 + 2030) / 5;
  if ( (int16_t)v21 < (int16_t)v53 && *(char *)(v20 + 2038) != -1 )
  {
    LOWORD(v53) = 3 * *(char *)(v20 + 2030) / 5;
    if ( *(char *)(v20 + 2038) == a1 )
      v54 = 177;
    else
      v54 = 176;
  }
  v22 = v21 + v10;
  sub_500CF(a1, a2);
  if ( v23 >= 300 || (v24 = *(int16_t *)(dword_197F98 + 3753 * a1 + 166), 2 * v24 >= 3 * v24) )
  {
    if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 39) != 5 )
    {
      sub_500CF(a1, a2);
      v26 = -v25 / 40;
      if ( (int16_t)v26 < (int16_t)v53 )
      {
        v54 = 112;
        LOWORD(v53) = v26;
      }
      v61 = 150;
      v22 += v26;
    }
  }
  v60 = 0;
  v52 = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    v28 = 3753 * i + dword_197F98;
    if ( *(_BYTE *)(v28 + 40) != 100 && !*(_BYTE *)(v28 + 36) )
    {
      ++v60;
      if ( i != a1 && v52 < *(int16_t *)(v28 + 166) )
        v52 = *(_WORD *)(v28 + 166);
    }
  }
  if ( v60 < 3 && *(int16_t *)(dword_197F98 + 3753 * a1 + 166) > v52 || v60 == 1 )
  {
    if ( (int16_t)v53 > -10 )
    {
      v54 = 178;
      LOWORD(v53) = -10;
    }
    v61 = 150;
    v22 -= 10;
  }
  v29 = dword_192FD8 + 30535;
  if ( (int16_t)(dword_192FD8 + 30535) >= 100 )
  {
    v59 = v29 < 350 ? dword_192FD8 + 30495 : 309;
    v57 = *(uint8_t *)(dword_197F98 + 3753 * a1 + v29 + 2971)
        - *(uint8_t *)(v59 + dword_197F98 + 3753 * a1 + 2971);
    v30 = *(uint8_t *)(v29 + 3753 * a2 + dword_197F98 + 2971)
        - *(uint8_t *)(v59 + 3753 * a2 + dword_197F98 + 2971);
    if ( v30 > v57 )
    {
      v31 = (v57 - v30) / 2;
      if ( (int16_t)v31 < (int16_t)v53 )
      {
        v54 = 117;
        LOWORD(v53) = (v57 - v30) / 2;
      }
      v22 += v31;
    }
  }
  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1575) == 1 )
    v22 += 10;
  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1575) == 2 )
    v22 += 20;
  v32 = 3753 * a1 + dword_197F98;
  if ( *(_BYTE *)(v32 + 39) == 4 && *(_BYTE *)(a2 + v32 + 1831) == 1 )
    v33 = 6;
  else
    v33 = *(uint8_t *)(dword_197F98 + 3753 * a1 + 39);
  LOWORD(v22) = word_181080[v33] + v22;
  if ( *(_BYTE *)(dword_197F98 + 3753 * a2 + 479) == 3 )
    v22 += 5;
  if ( *(_BYTE *)(3753 * a2 + dword_197F98 + 2227) == 1 )
    v22 += 10;
  sub_E5E09(a2);
  v35 = v34 + v22;
  LOWORD(v34) = (uint8_t)byte_199CB0;
  v36 = v35 + 15 - v34;
  if ( (v36 & 0x8000u) != 0 )
  {
    v38 = 3753 * a1 + dword_197F98;
    LOWORD(v38) = *(uint8_t *)(a2 + v38 + 2191);
    v56 = -v36 * v38;
  }
  else
  {
    v37 = *(uint8_t *)(a2 + dword_197F98 + 3753 * a1 + 2191);
    v56 = v37 / sub_134C92((int16_t)v36 * (int16_t)v36 * (int16_t)v36 + 5);
  }
  v39 = a2 + 3753 * a1 + dword_197F98;
  if ( (*(_BYTE *)(v39 + 1575) == 1 || *(_BYTE *)(v39 + 1575) == 2) && sub_53E96(a1, a2) == 4 )
    LOWORD(v56) = 0;
  sub_500CF(a1, a2);
  v58 = v40 / 40 + sub_1247A0(3u) - 1;
  if ( (int16_t)v58 < 1 )
    LOWORD(v58) = 1;
  if ( !(uint16_t)sub_4F93B(a1, a2, v58, 1, 1, 1, 1) )
    LOWORD(v58) = 0;
  if ( (int)sub_1247A0(0x64u) <= (int16_t)v56 && *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 2191) >= 0xAu )
  {
    v41 = (uint8_t)byte_199CB0;
    if ( (int)(v41 + sub_1247A0(0x10u)) >= 16 || (int16_t)v58 <= 0 || (int16_t)v53 == -150 )
    {
      *a3 = v61;
      v43 = a4;
      v44 = v54;
      goto LABEL_106;
    }
    v55 = 1;
    for ( j = 0; j < word_199998; ++j )
    {
      if ( *(_WORD *)(3753 * a1 + dword_197F98 + 166) < *(_WORD *)(3753 * j + dword_197F98 + 166) && j != a1 )
        v55 = 0;
    }
    if ( (int)sub_1247A0(4u) <= 3 && v55 == 1 && word_19A0E2 == 1 && (int16_t)v58 > 3 )
    {
      *a3 = v61;
      v43 = a4;
      v44 = v54;
LABEL_106:
      *v43 = v44;
      goto LABEL_107;
    }
    if ( !*(_BYTE *)(dword_197F98 + 3753 * a1 + 2226) && !*(_BYTE *)(dword_197F98 + 3753 * a2 + 2226) )
    {
      v45 = sub_1247A0(4u);
      if ( v45 <= sub_134C92((int16_t)v58 + 4) )
      {
        *a3 = v61;
        v43 = a4;
        v44 = v54;
      }
      else
      {
        *a3 = v61;
        v43 = a4;
        v44 = v54;
      }
      goto LABEL_106;
    }
  }
LABEL_107:
  JUMPOUT(0x4EB00);
}
// 54CBB: control flows out of bounds to 4EB00
// 54673: variable 'v16' is possibly undefined
// 5477C: variable 'v23' is possibly undefined
// 547BB: variable 'v25' is possibly undefined
// 54A18: variable 'v34' is possibly undefined
// 54ADC: variable 'v40' is possibly undefined
// 180CF0: using guessed type int16_t word_180CF0[50];
// 181080: using guessed type int16_t word_181080[8];
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;
// 19A0E2: using guessed type int16_t word_19A0E2;


//----- (00054CC0) --------------------------------------------------------
int __fastcall sub_54CC0( int a1, int a2)
{
  int v2; // ebx
  int v3; // edi
  int v4; // esi
  char v5; // cl
  int v6; // eax
  int v7; // edi
  char v8; // dl
  int result; // eax
  int16_t v10; // dx

  v2 = a1;
  v3 = dword_197F98;
  v4 = dword_197F98 + 3753 * a1;
  *(_BYTE *)(a2 + v4 + 1887) = byte_19B584;
  v5 = byte_19B587;
  *(_BYTE *)(a2 + v4 + 1895) = byte_19B587;
  v6 = v4 + 2 * a2;
  *(_WORD *)(v6 + 1911) = word_19B580;
  LOWORD(v4) = word_19B582;
  v7 = 3753 * a2 + v3;
  *(_WORD *)(v6 + 1975) = word_19B582;
  v8 = byte_19B584;
  *(_BYTE *)(v7 + v2 + 1895) = v5;
  result = v2;
  *(_BYTE *)(v7 + v2 + 1887) = v8;
  v10 = word_19B580;
  *(_WORD *)(v7 + 2 * v2 + 1975) = v4;
  *(_WORD *)(v7 + 2 * v2 + 1911) = v10;
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 19B580: using guessed type int16_t word_19B580;
// 19B582: using guessed type int16_t word_19B582;
// 19B584: using guessed type char byte_19B584;
// 19B587: using guessed type char byte_19B587;


//----- (00054D4D) --------------------------------------------------------
int __fastcall sub_54D4D( int a1, int a2)
{
  int v3; // ecx
  int v4; // edx
  int result; // eax

  v3 = a1;
  v4 = dword_197F98;
  *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 2191) = 0;
  result = v4 + 3753 * a2;
  *(_BYTE *)(v3 + result + 2191) = 0;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (00054D80) --------------------------------------------------------
int16_t *__stdcall sub_54D80(
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
        int a24, unsigned int a25,
        int16_t *a26,
        _WORD *a27,
        int16_t *a28)
{
  int16_t v28; // si
  int16_t v29; // bx
  int16_t v30; // cx
  int16_t v31; // cx
  int16_t *result; // eax

  v28 = word_17FE00[11 * BYTE1(a6)];
  v29 = 0;
  if ( (uint16_t)sub_1276F0((int)&a6 + 3, 5u) )
    v28 += 50;
  v30 = a25;
  if ( (uint16_t)sub_1276F0((int)&a6 + 3, 2u) )
    v30 += 5;
  v31 = 5 * v30;
  if ( (uint16_t)sub_1276F0((int)&a6 + 3, 9u) )
    v29 = 70;
  if ( (uint16_t)sub_1276F0((int)&a6 + 3, 0x11u) )
  {
    v31 += 100;
    v29 += 50;
  }
  if ( (uint16_t)sub_1276F0((int)&a6 + 3, 0x12u) )
  {
    v31 += 50;
    v29 += 25;
  }
  if ( (uint16_t)sub_1276F0((int)&a6 + 3, 0x15u) )
    v29 += 100;
  if ( (uint16_t)sub_1276F0((int)&a6 + 3, 0x26u) )
    v29 += 130;
  *a27 = v31;
  *a28 = v29;
  result = a26;
  *a26 = v28;
  return result;
}
// 17FE00: using guessed type int16_t word_17FE00[];


//----- (00054E5B) --------------------------------------------------------
int __fastcall sub_54E5B(int a1, _WORD *a2, _WORD *a3, _WORD *a4)
{
  int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  int result; // eax
  int v12[28]; // [esp-70h] [ebp-8Ch] BYREF
  _WORD *v13; // [esp+0h] [ebp-1Ch]
  _WORD *v14; // [esp+4h] [ebp-18h]
  _WORD *v15; // [esp+8h] [ebp-14h]
  int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch] BYREF
  int v18; // [esp+14h] [ebp-8h] BYREF
  int v19; // [esp+18h] [ebp-4h] BYREF

  v16 = a1;
  v15 = a2;
  v14 = a3;
  v13 = a4;
  v4 = 129 * (int16_t)a1;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  qmemcpy(v12, (void *)(v4 + dword_197F9C), 0x63u);
  sub_54D80(
    v12[0],
    v12[1],
    v12[2],
    v12[3],
    v12[4],
    v12[5],
    v12[6],
    v12[7],
    v12[8],
    v12[9],
    v12[10],
    v12[11],
    v12[12],
    v12[13],
    v12[14],
    v12[15],
    v12[16],
    v12[17],
    v12[18],
    v12[19],
    v12[20],
    v12[21],
    v12[22],
    v12[23],
    v12[24],
    (int16_t *)&v19,
    &v17,
    (int16_t *)&v18);
  v5 = *(int16_t *)(v4 + dword_197F9C + 116);
  if ( v5 > -1 )
  {
    sub_3677D(v5);
    v17 += v6;
    v18 = (int16_t)v6 / 2 + (int16_t)v18;
    sub_367AE(*(_WORD *)(v4 + dword_197F9C + 116));
    v19 += v7;
  }
  v8 = 129 * (int16_t)v16 + dword_197F9C;
  v17 += (uint16_t)word_17D172[4 * *(uint8_t *)(v8 + 113)];
  v18 = word_17D172[4 * *(uint8_t *)(v8 + 113)] / 2 + (int16_t)v18;
  v19 += (uint16_t)word_17D170[4 * *(uint8_t *)(v8 + 113)];
  if ( *(char *)(v8 + 99) < 8 )
  {
    v9 = 3753 * *(char *)(v8 + 99);
    LOWORD(v9) = *(char *)(dword_197F98 + v9 + 2213);
    v17 += v9;
    v18 = *(char *)(dword_197F98 + 3753 * *(char *)(v8 + 99) + 2213) / 2 + (int16_t)v18;
    v10 = 3753 * *(char *)(v8 + 99);
    LOWORD(v10) = *(char *)(dword_197F98 + v10 + 2214);
    v19 += v10;
    if ( *(_BYTE *)(dword_197F98 + 3753 * *(char *)(v8 + 99) + 2236) )
      v17 += 20;
  }
  *v15 = v17;
  *v14 = v18;
  result = v19;
  *v13 = v19;
  return result;
}
// 54E5B: could not find valid save-restore pair for ebx
// 54EBC: variable 'v6' is possibly undefined
// 54EDF: variable 'v7' is possibly undefined
// 17D170: using guessed type int16_t word_17D170[];
// 17D172: using guessed type int16_t word_17D172[];
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;


//----- (00054FBF) --------------------------------------------------------
void __fastcall sub_54FBF( int a1)
{
  bool v2; // ecx
  int16_t i; // cx
  int v4; // ebx
  int16_t v5; // dx
  int16_t v6; // di
  int16_t v7; // bx
  int v8; // edx
  int v9; // [esp+4h] [ebp-Ch]
  int v10; // [esp+8h] [ebp-8h]
  int v11; // [esp+Ch] [ebp-4h]

  v2 = byte_199CB5 != 2 && *(_BYTE *)(dword_197F98 + 3753 * a1 + 40) == 100;
  if ( byte_199CB4 == 1 )
  {
    for ( i = 0; i < 6; ++i )
    {
      v4 = 99 * i;
      v9 = 3753 * a1;
      sub_127776((_BYTE *)(v4 + v9 + dword_197F98 + 806), 0x63u);
      v5 = i;
      sub_57871(a1, v5, v9 + dword_197F98 + 806 + v4);
    }
  }
  else
  {
    word_1998F0 = -1000;
    v6 = 1;
    v11 = 1 - v2;
    sub_616A5(a1, 3753 * a1 + dword_197F98 + 806, 0);
    word_1998F0 = 0;
    do
    {
      v10 = 3753 * a1;
      v7 = v11++;
      v8 = 99 * v6++ + dword_197F98 + v10 + 806;
      sub_616A5(a1, v8, v7);
    }
    while ( v6 < 5 );
    if ( *(_BYTE *)(v10 + dword_197F98 + 40) == 100 )
    {
      sub_127776((_BYTE *)(v10 + dword_197F98 + 1301), 0x63u);
    }
    else
    {
      sub_616A5(a1, v10 + dword_197F98 + 1301, 5);
      sub_6C897(
        *(uint8_t *)(v10 + dword_197F98 + 37),
        *(uint8_t *)(v10 + dword_197F98 + 1317),
        *(char *)(v10 + dword_197F98 + 1393) % 8,
        (char *)(v10 + dword_197F98 + 1301));
    }
  }
  JUMPOUT(0x56A34);
}
// 550EB: control flows out of bounds to 56A34
// 197F98: using guessed type int dword_197F98;
// 1998F0: using guessed type int16_t word_1998F0;
// 199CB4: using guessed type char byte_199CB4;
// 199CB5: using guessed type char byte_199CB5;


//----- (0005514C) --------------------------------------------------------
char __fastcall sub_5514C(int a1, int a2)
{
  int v2; // ebx
  int v3; // ecx
  unsigned int v4; // edx
  int v5; // ebx
  unsigned int v6; // edx
  int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // edx

  switch ( a2 )
  {
    case 0:
      v2 = a1;
      sub_127776((_BYTE *)a1, 0x63u);
      strcpy((char *)a1, "Raider");
      *(_BYTE *)(a1 + 17) = 0;
      *(_BYTE *)(a1 + 18) = 0;
      *(_BYTE *)(a1 + 21) = 5;
      *(_BYTE *)(a1 + 16) = 0;
      *(_BYTE *)(a1 + 22) = 6;
      *(_BYTE *)(a1 + 20) = 1;
      *(_BYTE *)(a1 + 19) = 5;
      *(_WORD *)(a1 + 28) = 4;
      *(_BYTE *)(a1 + 32) = 1;
      *(_WORD *)(a1 + 33) = 0;
      *(_BYTE *)(a1 + 35) = 0;
      *(_BYTE *)(a1 + 30) = 2;
      *(_BYTE *)(a1 + 31) = 2;
      *(_WORD *)(a1 + 36) = 24;
      *(_BYTE *)(a1 + 40) = 15;
      *(_WORD *)(a1 + 41) = 0;
      *(_BYTE *)(a1 + 43) = 0;
      *(_BYTE *)(a1 + 38) = 1;
      *(_BYTE *)(a1 + 39) = 1;
      sub_127712(a1 + 23, 7u);
      sub_127712(v2 + 23, 0x18u);
      if ( (uint8_t)byte_199CB0 > 2u )
        sub_127712(v2 + 23, 9u);
      a1 = 46 * *(uint8_t *)(v2 + 19);
      *(_BYTE *)(v2 + 92) = 0;
      goto LABEL_5;
    case 1:
      v2 = a1;
      sub_127776((_BYTE *)a1, 0x63u);
      strcpy((char *)a1, "Marauder");
      *(_BYTE *)(a1 + 17) = 0;
      *(_BYTE *)(a1 + 18) = 0;
      *(_BYTE *)(a1 + 21) = 5;
      *(_BYTE *)(a1 + 16) = 1;
      *(_BYTE *)(a1 + 22) = 6;
      *(_BYTE *)(a1 + 20) = 1;
      *(_BYTE *)(a1 + 19) = 5;
      *(_WORD *)(a1 + 28) = 4;
      *(_BYTE *)(a1 + 32) = 1;
      *(_WORD *)(a1 + 33) = 0;
      *(_BYTE *)(a1 + 35) = 0;
      *(_BYTE *)(a1 + 30) = 3;
      *(_BYTE *)(a1 + 31) = 3;
      *(_WORD *)(a1 + 36) = 4;
      *(_BYTE *)(a1 + 40) = 1;
      *(_WORD *)(a1 + 41) = 2;
      *(_BYTE *)(a1 + 43) = 0;
      *(_BYTE *)(a1 + 38) = 1;
      *(_BYTE *)(a1 + 39) = 1;
      *(_WORD *)(a1 + 44) = 24;
      *(_BYTE *)(a1 + 48) = 15;
      *(_WORD *)(a1 + 49) = 0;
      *(_BYTE *)(a1 + 51) = 10;
      *(_BYTE *)(a1 + 46) = 1;
      *(_BYTE *)(a1 + 47) = 1;
      sub_127712(a1 + 23, 7u);
      sub_127712(v2 + 23, 0x18u);
      if ( (uint8_t)byte_199CB0 <= 3u )
      {
        if ( (uint8_t)byte_199CB0 <= 2u )
          goto LABEL_11;
        v4 = 9;
      }
      else
      {
        v4 = 21;
      }
      sub_127712(v2 + 23, v4);
LABEL_11:
      a1 = 46 * *(uint8_t *)(v2 + 19);
      *(_BYTE *)(v2 + 92) = 1;
LABEL_5:
      v3 = *(uint8_t *)(v2 + 16);
      *(_BYTE *)(v2 + 93) = 8;
      LOBYTE(v3) = byte_17FE90[v3 + a1];
      *(_WORD *)(v2 + 94) = 500;
      *(_BYTE *)(v2 + 96) = v3;
      return a1;
    case 2:
      v5 = a1;
      sub_127776((_BYTE *)a1, 0x63u);
      strcpy((char *)a1, "Intruder");
      *(_BYTE *)(a1 + 17) = 0;
      *(_BYTE *)(a1 + 18) = 0;
      *(_BYTE *)(a1 + 21) = 5;
      *(_BYTE *)(a1 + 16) = 2;
      *(_BYTE *)(a1 + 22) = 6;
      *(_BYTE *)(a1 + 20) = 1;
      *(_BYTE *)(a1 + 19) = 5;
      *(_WORD *)(a1 + 28) = 4;
      *(_BYTE *)(a1 + 32) = 1;
      *(_WORD *)(a1 + 33) = 0;
      *(_BYTE *)(a1 + 35) = 0;
      *(_BYTE *)(a1 + 30) = 4;
      *(_BYTE *)(a1 + 31) = 4;
      *(_WORD *)(a1 + 36) = 4;
      *(_BYTE *)(a1 + 40) = 1;
      *(_WORD *)(a1 + 41) = 2;
      *(_BYTE *)(a1 + 43) = 0;
      *(_BYTE *)(a1 + 38) = 2;
      *(_BYTE *)(a1 + 39) = 2;
      *(_WORD *)(a1 + 44) = 24;
      *(_BYTE *)(a1 + 48) = 15;
      *(_WORD *)(a1 + 49) = 0;
      *(_BYTE *)(a1 + 51) = 10;
      *(_BYTE *)(a1 + 46) = 5;
      *(_BYTE *)(a1 + 47) = 5;
      *(_WORD *)(a1 + 52) = 13;
      *(_BYTE *)(a1 + 56) = 15;
      *(_WORD *)(a1 + 57) = 0;
      *(_BYTE *)(a1 + 59) = 0;
      *(_BYTE *)(a1 + 54) = 2;
      *(_BYTE *)(a1 + 55) = 2;
      *(_WORD *)(a1 + 60) = 31;
      *(_BYTE *)(a1 + 64) = 15;
      *(_WORD *)(a1 + 65) = 0;
      *(_BYTE *)(a1 + 67) = 0;
      *(_BYTE *)(a1 + 62) = 3;
      *(_BYTE *)(a1 + 63) = 3;
      sub_127712(a1 + 23, 7u);
      sub_127712(v5 + 23, 0x18u);
      if ( (uint8_t)byte_199CB0 < 2u )
        goto LABEL_21;
      if ( (uint8_t)byte_199CB0 <= 2u )
      {
        v6 = 9;
      }
      else if ( (uint8_t)byte_199CB0 <= 3u )
      {
        v6 = 21;
      }
      else
      {
        if ( byte_199CB0 != 4 )
          goto LABEL_21;
        v6 = 38;
      }
      sub_127712(v5 + 23, v6);
LABEL_21:
      a1 = 46 * *(uint8_t *)(v5 + 19);
      *(_BYTE *)(v5 + 92) = 2;
      goto LABEL_22;
    case 3:
      v5 = a1;
      sub_127776((_BYTE *)a1, 0x63u);
      strcpy((char *)a1, "Interdictor");
      *(_BYTE *)(a1 + 17) = 0;
      *(_BYTE *)(a1 + 18) = 0;
      *(_BYTE *)(a1 + 21) = 5;
      *(_BYTE *)(a1 + 16) = 3;
      *(_BYTE *)(a1 + 22) = 6;
      *(_BYTE *)(a1 + 20) = 1;
      *(_BYTE *)(a1 + 19) = 5;
      *(_WORD *)(a1 + 28) = 4;
      *(_BYTE *)(a1 + 32) = 1;
      *(_WORD *)(a1 + 33) = 0;
      *(_BYTE *)(a1 + 35) = 0;
      *(_BYTE *)(a1 + 30) = 10;
      *(_BYTE *)(a1 + 31) = 10;
      *(_WORD *)(a1 + 36) = 4;
      *(_BYTE *)(a1 + 40) = 1;
      *(_WORD *)(a1 + 41) = 2;
      *(_BYTE *)(a1 + 43) = 0;
      *(_BYTE *)(a1 + 38) = 4;
      *(_BYTE *)(a1 + 39) = 4;
      *(_WORD *)(a1 + 44) = 24;
      *(_BYTE *)(a1 + 48) = 1;
      *(_WORD *)(a1 + 49) = 0;
      *(_BYTE *)(a1 + 51) = 10;
      *(_BYTE *)(a1 + 46) = 15;
      *(_BYTE *)(a1 + 47) = 15;
      *(_WORD *)(a1 + 52) = 13;
      *(_BYTE *)(a1 + 56) = 15;
      *(_WORD *)(a1 + 57) = 0;
      *(_BYTE *)(a1 + 59) = 0;
      *(_BYTE *)(a1 + 54) = 2;
      *(_BYTE *)(a1 + 55) = 2;
      *(_WORD *)(a1 + 60) = 4;
      *(_BYTE *)(a1 + 64) = 1;
      *(_WORD *)(a1 + 65) = 4;
      *(_BYTE *)(a1 + 67) = 0;
      *(_BYTE *)(a1 + 62) = 10;
      *(_BYTE *)(a1 + 63) = 10;
      *(_WORD *)(a1 + 68) = 11;
      *(_BYTE *)(a1 + 72) = 1;
      *(_WORD *)(a1 + 73) = 0;
      *(_BYTE *)(a1 + 75) = 0;
      *(_BYTE *)(a1 + 70) = 4;
      *(_BYTE *)(a1 + 71) = 4;
      sub_127712(a1 + 23, 7u);
      sub_127712(v5 + 23, 0x18u);
      sub_127712(v5 + 23, 0x21u);
      sub_127712(v5 + 23, 0x1Au);
      if ( !byte_199CB0 )
        goto LABEL_32;
      if ( (uint8_t)byte_199CB0 <= 1u )
      {
        v8 = 9;
      }
      else if ( (uint8_t)byte_199CB0 <= 2u )
      {
        v8 = 21;
      }
      else
      {
        if ( (uint8_t)byte_199CB0 > 4u )
          goto LABEL_32;
        v8 = 38;
      }
      sub_127712(v5 + 23, v8);
LABEL_32:
      a1 = 46 * *(uint8_t *)(v5 + 19);
      *(_BYTE *)(v5 + 92) = 3;
      goto LABEL_22;
    case 4:
      v5 = a1;
      sub_127776((_BYTE *)a1, 0x63u);
      strcpy((char *)a1, "Harbinger");
      *(_BYTE *)(a1 + 17) = 0;
      *(_BYTE *)(a1 + 18) = 0;
      *(_BYTE *)(a1 + 21) = 5;
      *(_BYTE *)(a1 + 16) = 4;
      *(_BYTE *)(a1 + 22) = 6;
      *(_BYTE *)(a1 + 20) = 1;
      *(_BYTE *)(a1 + 19) = 5;
      *(_WORD *)(a1 + 28) = 4;
      *(_BYTE *)(a1 + 32) = 1;
      *(_WORD *)(a1 + 33) = 0;
      *(_BYTE *)(a1 + 35) = 0;
      *(_BYTE *)(a1 + 30) = 20;
      *(_BYTE *)(a1 + 31) = 20;
      *(_WORD *)(a1 + 36) = 4;
      *(_BYTE *)(a1 + 40) = 1;
      *(_WORD *)(a1 + 41) = 2;
      *(_BYTE *)(a1 + 43) = 0;
      *(_BYTE *)(a1 + 38) = 5;
      *(_BYTE *)(a1 + 39) = 5;
      *(_WORD *)(a1 + 44) = 24;
      *(_BYTE *)(a1 + 48) = 1;
      *(_WORD *)(a1 + 49) = 0;
      *(_BYTE *)(a1 + 51) = 10;
      *(_BYTE *)(a1 + 46) = 30;
      *(_BYTE *)(a1 + 47) = 30;
      *(_WORD *)(a1 + 52) = 13;
      *(_BYTE *)(a1 + 56) = 15;
      *(_WORD *)(a1 + 57) = 0;
      *(_BYTE *)(a1 + 59) = 0;
      *(_BYTE *)(a1 + 54) = 3;
      *(_BYTE *)(a1 + 55) = 3;
      *(_WORD *)(a1 + 60) = 4;
      *(_BYTE *)(a1 + 64) = 1;
      *(_WORD *)(a1 + 65) = 4;
      *(_BYTE *)(a1 + 67) = 0;
      *(_BYTE *)(a1 + 62) = 20;
      *(_BYTE *)(a1 + 63) = 20;
      *(_WORD *)(a1 + 68) = 11;
      *(_BYTE *)(a1 + 72) = 1;
      *(_WORD *)(a1 + 73) = 2;
      *(_BYTE *)(a1 + 75) = 0;
      *(_BYTE *)(a1 + 70) = 5;
      *(_BYTE *)(a1 + 71) = 5;
      *(_WORD *)(a1 + 76) = 37;
      *(_BYTE *)(a1 + 80) = 15;
      *(_WORD *)(a1 + 81) = 0;
      *(_BYTE *)(a1 + 83) = 0;
      *(_BYTE *)(a1 + 78) = 1;
      *(_BYTE *)(a1 + 79) = 1;
      *(_WORD *)(a1 + 84) = 37;
      *(_BYTE *)(a1 + 88) = 15;
      *(_WORD *)(a1 + 89) = 0;
      *(_BYTE *)(a1 + 91) = 0;
      *(_BYTE *)(a1 + 86) = 12;
      *(_BYTE *)(a1 + 87) = 12;
      sub_127712(a1 + 23, 7u);
      sub_127712(v5 + 23, 0x18u);
      sub_127712(v5 + 23, 0x21u);
      sub_127712(v5 + 23, 0x1Au);
      if ( byte_199CB0 )
      {
        if ( (uint8_t)byte_199CB0 <= 1u )
        {
          v9 = 21;
        }
        else
        {
          if ( (uint8_t)byte_199CB0 > 4u )
            goto LABEL_41;
          v9 = 38;
        }
      }
      else
      {
        v9 = 9;
      }
      sub_127712(v5 + 23, v9);
LABEL_41:
      a1 = 46 * *(uint8_t *)(v5 + 19);
      *(_BYTE *)(v5 + 92) = 4;
LABEL_22:
      v7 = *(uint8_t *)(v5 + 16);
      *(_BYTE *)(v5 + 93) = 8;
      LOBYTE(a1) = byte_17FE90[v7 + a1];
      *(_WORD *)(v5 + 94) = 500;
      *(_BYTE *)(v5 + 96) = a1;
      return a1;
    default:
      return a1;
  }
}
// 199CB0: using guessed type char byte_199CB0;


//----- (00055161) --------------------------------------------------------
void __fastcall sub_55161( int a1)
{
  int v2; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // eax
  int16_t v6; // bx
  int v7; // esi
  _BYTE *v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  int v12; // eax

  v2 = dword_192864 + 313 * a1;
  strcpy((char *)v2, "Raider");
  *(_BYTE *)(v2 + 32) = 8;
  *(_BYTE *)(v2 + 312) = 8;
  *(_WORD *)(v2 + 30) = -1;
  *(_BYTE *)(v2 + 38) = 0;
  *(_BYTE *)(v2 + 50) = 5;
  *(_BYTE *)(v2 + 49) = 5;
  *(_BYTE *)(v2 + 37) = 0;
  *(_BYTE *)(v2 + 36) = 0;
  v3 = 0;
  do
  {
    v4 = (int16_t)v3;
    v5 = dword_192864 + 313 * a1;
    *(_BYTE *)((int16_t)v3++ + v5 + 76) = 0;
    *(_BYTE *)(v4 + v5 + 178) = 0;
  }
  while ( (int16_t)v3 < 5 );
  *(_WORD *)(v5 + 82) = 4;
  *(_BYTE *)(v5 + 84) = 2;
  *(_BYTE *)(v5 + 85) = 1;
  *(_WORD *)(v5 + 86) = 0;
  *(_WORD *)(v5 + 88) = -1;
  *(_BYTE *)(v5 + 90) = 1;
  *(_BYTE *)(v5 + 91) = 2;
  *(_BYTE *)(v5 + 92) = 0;
  *(_WORD *)(v5 + 93) = 24;
  *(_BYTE *)(v5 + 95) = 1;
  *(_BYTE *)(v5 + 96) = 15;
  *(_WORD *)(v5 + 97) = 0;
  *(_WORD *)(v5 + 99) = -1;
  *(_BYTE *)(v5 + 101) = 1;
  *(_BYTE *)(v5 + 102) = 1;
  v6 = 1;
  *(_BYTE *)(v5 + 103) = 0;
  do
  {
    v7 = 313 * a1;
    v8 = (_BYTE *)(11 * v6++ + v7 + dword_192864 + 82);
    sub_127776(v8, 0xBu);
  }
  while ( v6 < 8 );
  sub_127712(v7 + dword_192864 + 76, 7u);
  sub_127712(v7 + dword_192864 + 76, 0x18u);
  if ( (uint8_t)byte_199CB0 > 2u )
    sub_127712(v7 + dword_192864 + 76, 9u);
  v9 = 313 * a1 + dword_192864;
  v10 = 36 * *(uint8_t *)(v9 + 37);
  *(_BYTE *)(v9 + 172) = 3;
  *(_WORD *)(v9 + 173) = -1;
  LOBYTE(v10) = byte_180022[v10];
  *(_BYTE *)(v9 + 51) = 6;
  *(_BYTE *)(v9 + 175) = v10;
  *(_WORD *)(v9 + 170) = (*(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v9 + 51)) + 100)
                       * word_180026[18 * *(uint8_t *)(v9 + 37)]
                       / 100;
  *(_WORD *)(v9 + 194) = word_180024[18 * *(uint8_t *)(v9 + 37)]
                       * (*(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v9 + 51)) + 100)
                       / 100;
  v11 = 46 * *(uint8_t *)(v9 + 49);
  v12 = *(uint8_t *)(v9 + 37);
  *(_WORD *)(v9 + 192) = 0;
  LOBYTE(v12) = byte_17FE90[v11 + v12];
  *(_WORD *)(v9 + 196) = 0;
  *(_BYTE *)(v9 + 58) = v12;
  *(_BYTE *)(v9 + 75) = 0;
  sub_36470(v9);
  JUMPOUT(0x55B0C);
}
// 5535F: control flows out of bounds to 55B0C
// 17F642: using guessed type int16_t word_17F642;
// 180024: using guessed type int16_t word_180024[];
// 180026: using guessed type int16_t word_180026[];
// 192864: using guessed type int dword_192864;
// 199CB0: using guessed type char byte_199CB0;


//----- (0005542C) --------------------------------------------------------
void __fastcall sub_5542C( int a1)
{
  int v2; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // eax
  int16_t v6; // si
  int v7; // ebx
  _BYTE *v8; // eax
  int v9; // eax
  unsigned int v10; // edx
  int v11; // ebx
  int v12; // eax

  v2 = dword_192864 + 313 * a1;
  strcpy((char *)v2, "Marauder");
  *(_BYTE *)(v2 + 32) = 8;
  *(_BYTE *)(v2 + 312) = 8;
  *(_WORD *)(v2 + 30) = -1;
  *(_BYTE *)(v2 + 38) = 0;
  *(_BYTE *)(v2 + 50) = 5;
  *(_BYTE *)(v2 + 49) = 5;
  *(_BYTE *)(v2 + 37) = 1;
  *(_BYTE *)(v2 + 36) = 0;
  v3 = 0;
  do
  {
    v4 = (int16_t)v3;
    v5 = dword_192864 + 313 * a1;
    *(_BYTE *)((int16_t)v3++ + v5 + 76) = 0;
    *(_BYTE *)(v4 + v5 + 178) = 0;
  }
  while ( (int16_t)v3 < 5 );
  *(_WORD *)(v5 + 82) = 4;
  *(_BYTE *)(v5 + 84) = 3;
  *(_BYTE *)(v5 + 85) = 1;
  *(_WORD *)(v5 + 86) = 0;
  *(_WORD *)(v5 + 88) = -1;
  *(_BYTE *)(v5 + 90) = 1;
  *(_BYTE *)(v5 + 91) = 3;
  *(_BYTE *)(v5 + 92) = 0;
  *(_WORD *)(v5 + 93) = 4;
  *(_BYTE *)(v5 + 95) = 1;
  *(_BYTE *)(v5 + 96) = 1;
  *(_WORD *)(v5 + 97) = 2;
  *(_WORD *)(v5 + 99) = -1;
  *(_BYTE *)(v5 + 101) = 1;
  *(_BYTE *)(v5 + 102) = 1;
  *(_BYTE *)(v5 + 103) = 0;
  *(_WORD *)(v5 + 104) = 24;
  *(_BYTE *)(v5 + 106) = 1;
  *(_BYTE *)(v5 + 107) = 15;
  *(_WORD *)(v5 + 108) = 0;
  *(_WORD *)(v5 + 110) = 10;
  *(_BYTE *)(v5 + 112) = 1;
  *(_BYTE *)(v5 + 113) = 1;
  v6 = 3;
  *(_BYTE *)(v5 + 114) = 0;
  do
  {
    v7 = 313 * a1;
    v8 = (_BYTE *)(dword_192864 + v7 + 82 + 11 * v6++);
    sub_127776(v8, 0xBu);
  }
  while ( v6 < 8 );
  sub_127712(v7 + dword_192864 + 76, 7u);
  sub_127712(v7 + dword_192864 + 76, 0x18u);
  if ( (uint8_t)byte_199CB0 <= 3u )
  {
    if ( (uint8_t)byte_199CB0 <= 2u )
    {
LABEL_10:
      v11 = dword_192864 + 313 * a1;
      v12 = 36 * *(uint8_t *)(v11 + 37);
      *(_BYTE *)(v11 + 172) = 3;
      *(_WORD *)(v11 + 173) = -1;
      LOBYTE(v12) = byte_180022[v12];
      *(_BYTE *)(v11 + 51) = 6;
      *(_BYTE *)(v11 + 175) = v12;
      *(_WORD *)(v11 + 170) = (*(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v11 + 51)) + 100)
                            * word_180026[18 * *(uint8_t *)(v11 + 37)]
                            / 100;
      *(_WORD *)(v11 + 194) = word_180024[18 * *(uint8_t *)(v11 + 37)]
                            * (*(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v11 + 51)) + 100)
                            / 100;
      *(_WORD *)(v11 + 192) = 0;
      *(_WORD *)(v11 + 196) = 1;
      JUMPOUT(0x55351);
    }
    v9 = v7 + dword_192864;
    v10 = 9;
  }
  else
  {
    v9 = v7 + dword_192864;
    v10 = 21;
  }
  sub_127712(v9 + 76, v10);
  goto LABEL_10;
}
// 55658: control flows out of bounds to 55351
// 17F642: using guessed type int16_t word_17F642;
// 180024: using guessed type int16_t word_180024[];
// 180026: using guessed type int16_t word_180026[];
// 192864: using guessed type int dword_192864;
// 199CB0: using guessed type char byte_199CB0;


//----- (00055738) --------------------------------------------------------
void __fastcall sub_55738( int a1)
{
  int v2; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // eax
  int16_t v6; // si
  int v7; // ebx
  _BYTE *v8; // eax
  int v9; // eax
  unsigned int v10; // edx
  int v11; // ebx
  int v12; // eax

  v2 = dword_192864 + 313 * a1;
  strcpy((char *)v2, "Intruder");
  *(_BYTE *)(v2 + 32) = 8;
  *(_BYTE *)(v2 + 312) = 8;
  *(_WORD *)(v2 + 30) = -1;
  *(_BYTE *)(v2 + 38) = 0;
  *(_BYTE *)(v2 + 50) = 5;
  *(_BYTE *)(v2 + 49) = 5;
  *(_BYTE *)(v2 + 37) = 2;
  *(_BYTE *)(v2 + 36) = 0;
  v3 = 0;
  do
  {
    v4 = (int16_t)v3;
    v5 = dword_192864 + 313 * a1;
    *(_BYTE *)((int16_t)v3++ + v5 + 76) = 0;
    *(_BYTE *)(v4 + v5 + 178) = 0;
  }
  while ( (int16_t)v3 < 5 );
  *(_WORD *)(v5 + 82) = 4;
  *(_BYTE *)(v5 + 84) = 4;
  *(_BYTE *)(v5 + 85) = 1;
  *(_WORD *)(v5 + 86) = 0;
  *(_WORD *)(v5 + 88) = -1;
  *(_BYTE *)(v5 + 90) = 1;
  *(_BYTE *)(v5 + 91) = 4;
  *(_BYTE *)(v5 + 92) = 0;
  *(_WORD *)(v5 + 93) = 4;
  *(_BYTE *)(v5 + 95) = 2;
  *(_BYTE *)(v5 + 96) = 1;
  *(_WORD *)(v5 + 97) = 2;
  *(_WORD *)(v5 + 99) = -1;
  *(_BYTE *)(v5 + 101) = 1;
  *(_BYTE *)(v5 + 102) = 2;
  *(_BYTE *)(v5 + 103) = 0;
  *(_WORD *)(v5 + 104) = 24;
  *(_BYTE *)(v5 + 106) = 5;
  *(_BYTE *)(v5 + 107) = 15;
  *(_WORD *)(v5 + 108) = 0;
  *(_WORD *)(v5 + 110) = 10;
  *(_BYTE *)(v5 + 112) = 1;
  *(_BYTE *)(v5 + 113) = 5;
  *(_BYTE *)(v5 + 114) = 0;
  *(_WORD *)(v5 + 115) = 13;
  *(_BYTE *)(v5 + 117) = 2;
  *(_BYTE *)(v5 + 118) = 15;
  *(_WORD *)(v5 + 119) = 0;
  *(_WORD *)(v5 + 121) = -1;
  *(_BYTE *)(v5 + 123) = 1;
  *(_BYTE *)(v5 + 124) = 2;
  *(_BYTE *)(v5 + 125) = 0;
  *(_WORD *)(v5 + 126) = 31;
  *(_BYTE *)(v5 + 128) = 3;
  *(_BYTE *)(v5 + 129) = 15;
  *(_WORD *)(v5 + 130) = 0;
  *(_WORD *)(v5 + 132) = -1;
  *(_BYTE *)(v5 + 134) = 1;
  *(_BYTE *)(v5 + 135) = 3;
  v6 = 4;
  *(_BYTE *)(v5 + 136) = 0;
  do
  {
    v7 = 313 * a1;
    v8 = (_BYTE *)(dword_192864 + v7 + 82 + 11 * v6++);
    sub_127776(v8, 0xBu);
  }
  while ( v6 < 8 );
  sub_127712(v7 + dword_192864 + 76, 7u);
  sub_127712(v7 + dword_192864 + 76, 0x18u);
  if ( (uint8_t)byte_199CB0 >= 2u )
  {
    if ( (uint8_t)byte_199CB0 <= 2u )
    {
      v9 = v7 + dword_192864;
      v10 = 9;
    }
    else if ( (uint8_t)byte_199CB0 <= 3u )
    {
      v9 = v7 + dword_192864;
      v10 = 21;
    }
    else
    {
      if ( byte_199CB0 != 4 )
        goto LABEL_14;
      v9 = v7 + dword_192864;
      v10 = 38;
    }
    sub_127712(v9 + 76, v10);
  }
LABEL_14:
  v11 = 313 * a1 + dword_192864;
  v12 = 36 * *(uint8_t *)(v11 + 37);
  *(_BYTE *)(v11 + 172) = 3;
  *(_WORD *)(v11 + 173) = -1;
  LOBYTE(v12) = byte_180022[v12];
  *(_BYTE *)(v11 + 51) = 6;
  *(_BYTE *)(v11 + 175) = v12;
  *(_WORD *)(v11 + 170) = word_180026[18 * *(uint8_t *)(v11 + 37)]
                        * (*(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v11 + 51)) + 100)
                        / 100;
  *(_WORD *)(v11 + 194) = word_180024[18 * *(uint8_t *)(v11 + 37)]
                        * (*(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v11 + 51)) + 100)
                        / 100;
  *(_WORD *)(v11 + 192) = 0;
  *(_WORD *)(v11 + 196) = 2;
  JUMPOUT(0x55351);
}
// 559D7: control flows out of bounds to 55351
// 17F642: using guessed type int16_t word_17F642;
// 180024: using guessed type int16_t word_180024[];
// 180026: using guessed type int16_t word_180026[];
// 192864: using guessed type int dword_192864;
// 199CB0: using guessed type char byte_199CB0;


//----- (00055B12) --------------------------------------------------------
void __fastcall sub_55B12( int a1)
{
  int v2; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // eax
  int16_t v6; // si
  int v7; // ebx
  _BYTE *v8; // eax
  int v9; // eax
  unsigned int v10; // edx
  int v11; // ebx
  int v12; // eax

  v2 = dword_192864 + 313 * a1;
  strcpy((char *)v2, "Interdictor");
  *(_BYTE *)(v2 + 32) = 8;
  *(_BYTE *)(v2 + 312) = 8;
  *(_WORD *)(v2 + 30) = -1;
  *(_BYTE *)(v2 + 38) = 0;
  *(_BYTE *)(v2 + 50) = 5;
  *(_BYTE *)(v2 + 49) = 5;
  *(_BYTE *)(v2 + 37) = 3;
  *(_BYTE *)(v2 + 36) = 0;
  v3 = 0;
  do
  {
    v4 = (int16_t)v3;
    v5 = dword_192864 + 313 * a1;
    *(_BYTE *)((int16_t)v3++ + v5 + 76) = 0;
    *(_BYTE *)(v4 + v5 + 178) = 0;
  }
  while ( (int16_t)v3 < 5 );
  *(_WORD *)(v5 + 82) = 4;
  *(_BYTE *)(v5 + 84) = 6;
  *(_BYTE *)(v5 + 85) = 1;
  *(_WORD *)(v5 + 86) = 0;
  *(_WORD *)(v5 + 88) = -1;
  *(_BYTE *)(v5 + 90) = 1;
  *(_BYTE *)(v5 + 91) = 6;
  *(_BYTE *)(v5 + 92) = 0;
  *(_WORD *)(v5 + 93) = 4;
  *(_BYTE *)(v5 + 95) = 2;
  *(_BYTE *)(v5 + 96) = 1;
  *(_WORD *)(v5 + 97) = 2;
  *(_WORD *)(v5 + 99) = -1;
  *(_BYTE *)(v5 + 101) = 1;
  *(_BYTE *)(v5 + 102) = 2;
  *(_BYTE *)(v5 + 103) = 0;
  *(_WORD *)(v5 + 104) = 24;
  *(_BYTE *)(v5 + 106) = 15;
  *(_BYTE *)(v5 + 107) = 15;
  *(_WORD *)(v5 + 108) = 0;
  *(_WORD *)(v5 + 110) = 10;
  *(_BYTE *)(v5 + 112) = 1;
  *(_BYTE *)(v5 + 113) = 15;
  *(_BYTE *)(v5 + 114) = 0;
  *(_WORD *)(v5 + 115) = 13;
  *(_BYTE *)(v5 + 117) = 2;
  *(_BYTE *)(v5 + 118) = 15;
  *(_WORD *)(v5 + 119) = 0;
  *(_WORD *)(v5 + 121) = -1;
  *(_BYTE *)(v5 + 123) = 1;
  *(_BYTE *)(v5 + 124) = 2;
  *(_BYTE *)(v5 + 125) = 0;
  *(_WORD *)(v5 + 126) = 4;
  *(_BYTE *)(v5 + 128) = 8;
  *(_BYTE *)(v5 + 129) = 1;
  *(_WORD *)(v5 + 130) = 4;
  *(_WORD *)(v5 + 132) = -1;
  *(_BYTE *)(v5 + 134) = 1;
  *(_BYTE *)(v5 + 135) = 8;
  *(_BYTE *)(v5 + 136) = 0;
  *(_WORD *)(v5 + 137) = 11;
  *(_BYTE *)(v5 + 139) = 2;
  *(_BYTE *)(v5 + 140) = 1;
  *(_WORD *)(v5 + 141) = 0;
  *(_WORD *)(v5 + 143) = -1;
  *(_BYTE *)(v5 + 145) = 1;
  *(_BYTE *)(v5 + 146) = 2;
  v6 = 6;
  *(_BYTE *)(v5 + 147) = 0;
  do
  {
    v7 = 313 * a1;
    v8 = (_BYTE *)(dword_192864 + v7 + 82 + 11 * v6++);
    sub_127776(v8, 0xBu);
  }
  while ( v6 < 8 );
  sub_127712(v7 + dword_192864 + 76, 7u);
  sub_127712(v7 + dword_192864 + 76, 0x18u);
  sub_127712(v7 + dword_192864 + 76, 0x21u);
  sub_127712(v7 + dword_192864 + 76, 0x1Au);
  if ( byte_199CB0 )
  {
    if ( (uint8_t)byte_199CB0 <= 1u )
    {
      v9 = v7 + dword_192864;
      v10 = 9;
    }
    else if ( (uint8_t)byte_199CB0 <= 2u )
    {
      v9 = v7 + dword_192864;
      v10 = 21;
    }
    else
    {
      if ( (uint8_t)byte_199CB0 > 4u )
        goto LABEL_14;
      v9 = v7 + dword_192864;
      v10 = 38;
    }
    sub_127712(v9 + 76, v10);
  }
LABEL_14:
  v11 = 313 * a1 + dword_192864;
  v12 = 36 * *(uint8_t *)(v11 + 37);
  *(_BYTE *)(v11 + 172) = 3;
  *(_WORD *)(v11 + 173) = -1;
  LOBYTE(v12) = byte_180022[v12];
  *(_BYTE *)(v11 + 51) = 6;
  *(_BYTE *)(v11 + 175) = v12;
  *(_WORD *)(v11 + 170) = word_180026[18 * *(uint8_t *)(v11 + 37)]
                        * (*(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v11 + 51)) + 100)
                        / 100;
  *(_WORD *)(v11 + 194) = (*(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v11 + 51)) + 100)
                        * word_180024[18 * *(uint8_t *)(v11 + 37)]
                        / 100;
  *(_WORD *)(v11 + 192) = 0;
  *(_WORD *)(v11 + 196) = 3;
  JUMPOUT(0x55351);
}
// 55E11: control flows out of bounds to 55351
// 17F642: using guessed type int16_t word_17F642;
// 180024: using guessed type int16_t word_180024[];
// 180026: using guessed type int16_t word_180026[];
// 192864: using guessed type int dword_192864;
// 199CB0: using guessed type char byte_199CB0;


//----- (00055F67) --------------------------------------------------------
void __fastcall sub_55F67( int a1)
{
  int v1; // eax
  int v2; // esi
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  int v6; // eax
  unsigned int v7; // edx
  int v8; // ebx
  int v9; // eax
  int v10; // edx
  int v11; // eax

  v1 = dword_192864 + 313 * a1;
  strcpy((char *)v1, "Harbinger");
  *(_BYTE *)(v1 + 32) = 8;
  *(_BYTE *)(v1 + 312) = 8;
  *(_WORD *)(v1 + 30) = -1;
  *(_BYTE *)(v1 + 38) = 0;
  *(_BYTE *)(v1 + 50) = 5;
  *(_BYTE *)(v1 + 49) = 5;
  *(_BYTE *)(v1 + 37) = 4;
  *(_BYTE *)(v1 + 36) = 0;
  v2 = 0;
  do
  {
    v3 = 313 * a1;
    v4 = (int16_t)v2;
    v5 = v3 + dword_192864;
    *(_BYTE *)((int16_t)v2++ + v5 + 76) = 0;
    *(_BYTE *)(v4 + v5 + 178) = 0;
  }
  while ( (int16_t)v2 < 5 );
  *(_WORD *)(v5 + 82) = 4;
  *(_BYTE *)(v5 + 84) = 10;
  *(_BYTE *)(v5 + 85) = 1;
  *(_WORD *)(v5 + 86) = 0;
  *(_WORD *)(v5 + 88) = -1;
  *(_BYTE *)(v5 + 90) = 1;
  *(_BYTE *)(v5 + 91) = 10;
  *(_BYTE *)(v5 + 92) = 0;
  *(_WORD *)(v5 + 93) = 4;
  *(_BYTE *)(v5 + 95) = 2;
  *(_BYTE *)(v5 + 96) = 1;
  *(_WORD *)(v5 + 97) = 2;
  *(_WORD *)(v5 + 99) = -1;
  *(_BYTE *)(v5 + 101) = 1;
  *(_BYTE *)(v5 + 102) = 2;
  *(_BYTE *)(v5 + 103) = 0;
  *(_WORD *)(v5 + 104) = 24;
  *(_BYTE *)(v5 + 106) = 20;
  *(_BYTE *)(v5 + 107) = 15;
  *(_WORD *)(v5 + 108) = 0;
  *(_WORD *)(v5 + 110) = 10;
  *(_BYTE *)(v5 + 112) = 1;
  *(_BYTE *)(v5 + 113) = 20;
  *(_BYTE *)(v5 + 114) = 0;
  *(_WORD *)(v5 + 115) = 13;
  *(_BYTE *)(v5 + 117) = 3;
  *(_BYTE *)(v5 + 118) = 15;
  *(_WORD *)(v5 + 119) = 0;
  *(_WORD *)(v5 + 121) = -1;
  *(_BYTE *)(v5 + 123) = 1;
  *(_BYTE *)(v5 + 124) = 3;
  *(_BYTE *)(v5 + 125) = 0;
  *(_WORD *)(v5 + 126) = 4;
  *(_BYTE *)(v5 + 128) = 15;
  *(_BYTE *)(v5 + 129) = 1;
  *(_WORD *)(v5 + 130) = 4;
  *(_WORD *)(v5 + 132) = -1;
  *(_BYTE *)(v5 + 134) = 1;
  *(_BYTE *)(v5 + 135) = 15;
  *(_BYTE *)(v5 + 136) = 0;
  *(_WORD *)(v5 + 137) = 11;
  *(_BYTE *)(v5 + 139) = 2;
  *(_BYTE *)(v5 + 140) = 1;
  *(_WORD *)(v5 + 141) = 2;
  *(_WORD *)(v5 + 143) = -1;
  *(_BYTE *)(v5 + 145) = 1;
  *(_BYTE *)(v5 + 146) = 2;
  *(_BYTE *)(v5 + 147) = 0;
  *(_WORD *)(v5 + 148) = 37;
  *(_BYTE *)(v5 + 150) = 1;
  *(_BYTE *)(v5 + 151) = 15;
  *(_WORD *)(v5 + 152) = 0;
  *(_WORD *)(v5 + 154) = -1;
  *(_BYTE *)(v5 + 156) = 1;
  *(_BYTE *)(v5 + 157) = 1;
  *(_BYTE *)(v5 + 158) = 0;
  *(_WORD *)(v5 + 159) = 31;
  *(_BYTE *)(v5 + 161) = 6;
  *(_BYTE *)(v5 + 162) = 15;
  *(_WORD *)(v5 + 163) = 0;
  *(_WORD *)(v5 + 165) = -1;
  *(_BYTE *)(v5 + 167) = 1;
  *(_BYTE *)(v5 + 168) = 6;
  *(_BYTE *)(v5 + 169) = 0;
  sub_127776((_BYTE *)(v5 + 159), 0xBu);
  sub_127712(v3 + dword_192864 + 76, 7u);
  sub_127712(v3 + dword_192864 + 76, 0x18u);
  sub_127712(v3 + dword_192864 + 76, 0x21u);
  sub_127712(v3 + dword_192864 + 76, 0x1Au);
  if ( byte_199CB0 )
  {
    if ( (uint8_t)byte_199CB0 <= 1u )
    {
      v6 = v3 + dword_192864;
      v7 = 21;
    }
    else
    {
      if ( (uint8_t)byte_199CB0 > 4u )
        goto LABEL_11;
      v6 = v3 + dword_192864;
      v7 = 38;
    }
  }
  else
  {
    v6 = v3 + dword_192864;
    v7 = 9;
  }
  sub_127712(v6 + 76, v7);
LABEL_11:
  v8 = 313 * a1 + dword_192864;
  v9 = 36 * *(uint8_t *)(v8 + 37);
  *(_BYTE *)(v8 + 172) = 3;
  *(_WORD *)(v8 + 173) = -1;
  LOBYTE(v9) = byte_180022[v9];
  *(_BYTE *)(v8 + 51) = 6;
  *(_BYTE *)(v8 + 175) = v9;
  *(_WORD *)(v8 + 170) = (*(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v8 + 51)) + 100)
                       * word_180026[18 * *(uint8_t *)(v8 + 37)]
                       / 100;
  *(_WORD *)(v8 + 194) = (*(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v8 + 51)) + 100)
                       * word_180024[18 * *(uint8_t *)(v8 + 37)]
                       / 100;
  v10 = 46 * *(uint8_t *)(v8 + 49);
  v11 = *(uint8_t *)(v8 + 37);
  *(_WORD *)(v8 + 192) = 0;
  LOBYTE(v11) = byte_17FE90[v10 + v11];
  *(_WORD *)(v8 + 196) = 4;
  *(_BYTE *)(v8 + 58) = v11;
  *(_BYTE *)(v8 + 75) = 0;
  sub_36470(v8);
  JUMPOUT(0x56A34);
}
// 562D1: control flows out of bounds to 56A34
// 17F642: using guessed type int16_t word_17F642;
// 180024: using guessed type int16_t word_180024[];
// 180026: using guessed type int16_t word_180026[];
// 192864: using guessed type int dword_192864;
// 199CB0: using guessed type char byte_199CB0;


//----- (00056460) --------------------------------------------------------
char __fastcall sub_56460( int a1, char *a2)
{
  char result; // al

  sub_616A5(a1, (int)a2, 5);
  strcpy(a2, (char *)off_1800EE);
  return result;
}
// 1800EE: using guessed type _UNKNOWN *off_1800EE;


//----- (00056484) --------------------------------------------------------
void sub_56484()
{
  int i; // edx

  for ( i = 0; i != 64500; i += 129 )
  {
    if ( *(_BYTE *)(i + dword_197F9C + 17) )
      strcpy(
        (char *)(i + dword_197F9C),
        &aCombatShips[96 * *(uint8_t *)(i + dword_197F9C + 17) + 16 * (uint8_t)byte_199CAE]);
  }
}
// 197F9C: using guessed type int dword_197F9C;
// 199CAE: using guessed type char byte_199CAE;


//----- (000564CD) --------------------------------------------------------
char __fastcall sub_564CD( int a1, int a2)
{
  int16_t v4; // ax
  char v5; // dl
  int v6; // edx
  char result; // al

  sub_127776((_BYTE *)a2, 0x63u);
  strcpy((char *)a2, &aColonyShip[16 * (uint8_t)byte_199CAE]);
  *(_BYTE *)(a2 + 16) = 0;
  *(_BYTE *)(a2 + 17) = 1;
  *(_BYTE *)(a2 + 18) = 0;
  *(_BYTE *)(a2 + 19) = sub_56726(a1);
  *(_BYTE *)(a2 + 21) = 0;
  sub_5685F(a1);
  v5 = v4;
  if ( v4 > 1 )
    v5 = v4 - 1;
  *(_BYTE *)(a2 + 22) = v5;
  sub_127712(a2 + 23, 0xBu);
  v6 = 23 * *(uint8_t *)(a2 + 19);
  *(_BYTE *)(a2 + 92) = 45;
  *(_BYTE *)(a2 + 20) = word_17FE9C[v6];
  *(_WORD *)(a2 + 94) = sub_E0D98(1u, a1);
  result = byte_17FE90[46 * *(uint8_t *)(a2 + 19) + *(uint8_t *)(a2 + 16)];
  *(_BYTE *)(a2 + 96) = result;
  return result;
}
// 5652D: variable 'v4' is possibly undefined
// 17FE9C: using guessed type int16_t word_17FE9C[];
// 199CAE: using guessed type char byte_199CAE;


//----- (00056586) --------------------------------------------------------
void __fastcall sub_56586( int a1, int a2)
{
  int16_t v4; // ax
  char v5; // dl
  int v6; // edx

  sub_127776((_BYTE *)a2, 0x63u);
  strcpy((char *)a2, &aOutpostShip[16 * (uint8_t)byte_199CAE]);
  *(_BYTE *)(a2 + 16) = 0;
  *(_BYTE *)(a2 + 17) = 4;
  *(_BYTE *)(a2 + 18) = 0;
  *(_BYTE *)(a2 + 19) = sub_56726(a1);
  *(_BYTE *)(a2 + 21) = 0;
  sub_5685F(a1);
  v5 = v4;
  if ( v4 > 1 )
    v5 = v4 - 1;
  *(_BYTE *)(a2 + 22) = v5;
  sub_127712(a2 + 23, 0xBu);
  v6 = 23 * *(uint8_t *)(a2 + 19);
  *(_BYTE *)(a2 + 92) = 46;
  *(_BYTE *)(a2 + 20) = word_17FE9C[v6];
  *(_BYTE *)(a2 + 96) = byte_17FE90[46 * *(uint8_t *)(a2 + 19) + *(uint8_t *)(a2 + 16)];
  *(_WORD *)(a2 + 94) = sub_E0D98(4u, a1);
  JUMPOUT(0x56580);
}
// 56639: control flows out of bounds to 56580
// 565E6: variable 'v4' is possibly undefined
// 17FE9C: using guessed type int16_t word_17FE9C[];
// 199CAE: using guessed type char byte_199CAE;


//----- (0005663E) --------------------------------------------------------
int __fastcall sub_5663E( int a1, int a2)
{
  int16_t v3; // ax
  char v4; // dl
  int v5; // eax
  int v6; // edx
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int result; // eax

  sub_127776((_BYTE *)a2, 0x63u);
  strcpy((char *)a2, &aTransport[16 * (uint8_t)byte_199CAE]);
  *(_BYTE *)(a2 + 16) = 0;
  *(_BYTE *)(a2 + 17) = 2;
  *(_BYTE *)(a2 + 18) = 0;
  *(_BYTE *)(a2 + 19) = sub_56726(a1);
  *(_BYTE *)(a2 + 21) = 0;
  sub_5685F(a1);
  v4 = v3;
  if ( v3 > 1 )
    v4 = v3 - 1;
  v5 = 0;
  *(_BYTE *)(a2 + 22) = v4;
  do
  {
    v6 = (int16_t)v5++;
    *(_BYTE *)(v6 + a2 + 23) = 0;
  }
  while ( (int16_t)v5 < 5 );
  v7 = 0;
  do
  {
    v8 = (int16_t)v7;
    *(_WORD *)(a2 + 8 * (int16_t)v7++ + 28) = 0;
    *(_BYTE *)(a2 + 8 * v8 + 30) = 0;
  }
  while ( (int16_t)v7 < 8 );
  v9 = 23 * *(uint8_t *)(a2 + 19);
  *(_BYTE *)(a2 + 92) = 47;
  *(_BYTE *)(a2 + 20) = word_17FE9C[v9];
  *(_BYTE *)(a2 + 96) = byte_17FE90[46 * *(uint8_t *)(a2 + 19) + *(uint8_t *)(a2 + 16)];
  result = sub_E0D98(2u, a1);
  *(_WORD *)(a2 + 94) = result;
  return result;
}
// 56695: variable 'v3' is possibly undefined
// 17FE9C: using guessed type int16_t word_17FE9C[];
// 199CAE: using guessed type char byte_199CAE;


//----- (00056726) --------------------------------------------------------
int __fastcall sub_56726( int a1)
{
  int result; // eax
  int v3; // edx

  result = 0;
  if ( a1 >= 8 )
  {
    switch ( a1 )
    {
      case 8:
      case 12:
      case 13:
        result = 6;
        break;
      case 9:
      case 11:
        result = 4;
        break;
      case 10:
      case 14:
        result = 2;
        break;
      default:
        return result;
    }
  }
  else
  {
    v3 = 1;
    do
    {
      if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + word_17FE76[23 * (int16_t)v3] + 279) == 3 )
        result = v3;
      ++v3;
    }
    while ( (int16_t)v3 < 7 );
  }
  return result;
}
// 17FE76: using guessed type int16_t word_17FE76[];
// 197F98: using guessed type int dword_197F98;


//----- (0005679E) --------------------------------------------------------
int __fastcall sub_5679E( int a1)
{
  int result; // eax
  int v3; // ebx

  result = 0;
  if ( a1 >= 8 )
  {
    if ( (uint16_t)a1 <= 8u )
    {
      return 7;
    }
    else if ( a1 == 9 )
    {
      return 3;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v3 = 1;
    do
    {
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + *(int16_t *)((char *)&word_17F6A7 + 59 * (int16_t)v3) + 279) == 3 )
        result = v3;
      ++v3;
    }
    while ( (int16_t)v3 < 6 );
  }
  return result;
}
// 567ED: conditional instruction was optimized away because dx.2>=8
// 17F6A7: using guessed type int16_t word_17F6A7;
// 197F98: using guessed type int dword_197F98;


//----- (0005680D) --------------------------------------------------------
int __fastcall sub_5680D( int a1)
{
  int v2; // edx
  int v3; // eax

  v2 = 0;
  if ( a1 >= 8 )
    return 5;
  v3 = 1;
  do
  {
    if ( *(_BYTE *)(3753 * a1 + dword_197F98 + word_17FDF2[11 * (int16_t)v3] + 279) == 3 )
      v2 = v3;
    ++v3;
  }
  while ( (int16_t)v3 < 6 );
  return v2;
}
// 17FDF2: using guessed type int16_t word_17FDF2[];
// 197F98: using guessed type int dword_197F98;


//----- (0005685F) --------------------------------------------------------
void __fastcall sub_5685F( int a1)
{
  int16_t i; // dx

  if ( a1 < 8 )
  {
    for ( i = 2; i < 7; ++i )
      ;
  }
  JUMPOUT(0x56807);
}
// 568CA: control flows out of bounds to 56807
// 568AF: conditional instruction was optimized away because ax.2>=8
// 197F98: using guessed type int dword_197F98;


//----- (000568EB) --------------------------------------------------------
void __fastcall sub_568EB( int a1)
{
  int16_t i; // bx
  int16_t v2; // [esp+4h] [ebp-4h]

  v2 = 0;
  if ( a1 < 8 )
  {
    for ( i = 0; i < 40; ++i )
    {
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + word_17F80D[14 * i] + 279) == 3
        && !byte_17F80F[28 * i]
        && word_17F819[14 * i] > v2 )
      {
        v2 = word_17F819[14 * i];
      }
    }
  }
  JUMPOUT(0x56D18);
}
// 56997: control flows out of bounds to 56D18
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F819: using guessed type int16_t word_17F819[];
// 197F98: using guessed type int dword_197F98;


//----- (0005699C) --------------------------------------------------------
void __fastcall sub_5699C( int a1)
{
  int16_t i; // cx
  int v2; // edx
  int16_t v3; // ax
  int16_t v4; // [esp+0h] [ebp-Ch]
  int16_t v5; // [esp+4h] [ebp-8h]
  int16_t v6; // [esp+8h] [ebp-4h]

  v6 = 0;
  if ( a1 < 8 )
  {
    for ( i = 0; i < 40; ++i )
    {
      v2 = word_17F80D[14 * i];
      if ( *(_BYTE *)(v2 + dword_197F98 + 3753 * v4 + 279) == 3
        && (word_17F81D[14 * i] & 4) != 0
        && !byte_17F80F[28 * i] )
      {
        v5 = (uint8_t)byte_17FD32;
        sub_6D048(v4, v2);
        if ( v3 >= v5 && word_17F819[14 * i] > v6 )
          v6 = word_17F819[14 * i];
      }
    }
  }
  JUMPOUT(0x55B0C);
}
// 56A35: control flows out of bounds to 55B0C
// 569BC: variable 'v4' is possibly undefined
// 56A10: variable 'v3' is possibly undefined
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F819: using guessed type int16_t word_17F819[];
// 17F81D: using guessed type int16_t word_17F81D[];
// 17FD32: using guessed type char byte_17FD32;
// 197F98: using guessed type int dword_197F98;


//----- (00056A3A) --------------------------------------------------------
int __fastcall sub_56A3A( int a1, int a2)
{
  int v2; // esi
  int v3; // edi

  v2 = 14 * a1;
  v3 = 100 * word_17F819[v2];
  return word_17F819[v2] + v3 / sub_6EE8E(a2, a1, 1, 1, 1u, 4);
}
// 17F819: using guessed type int16_t word_17F819[];


//----- (00056A78) --------------------------------------------------------
void __fastcall sub_56A78( int a1)
{
  int16_t v1; // bx
  int v2; // edx
  int16_t v3; // di
  int16_t v4; // ax
  int16_t v5; // ax
  int16_t v6; // [esp+0h] [ebp-Ch]
  int16_t v7; // [esp+8h] [ebp-4h]

  v7 = 0;
  if ( a1 < 8 )
  {
    v1 = 0;
    while ( 1 )
    {
      v2 = word_17F80D[14 * v1];
      if ( *(_BYTE *)(v2 + dword_197F98 + 3753 * v6 + 279) == 3
        && (word_17F81D[14 * v1] & 4) != 0
        && !byte_17F80F[28 * v1] )
      {
        v3 = (uint8_t)byte_17FD32;
        sub_6D048(v6, v2);
        if ( v4 >= v3 )
        {
          v5 = sub_56A3A(v1, v6);
          if ( v5 >= v7 )
            v7 = v5;
        }
      }
      if ( ++v1 >= 40 )
        JUMPOUT(0x56A32);
    }
  }
  JUMPOUT(0x56A2D);
}
// 56A92: control flows out of bounds to 56A2D
// 56B02: control flows out of bounds to 56A32
// 56A94: variable 'v6' is possibly undefined
// 56AE6: variable 'v4' is possibly undefined
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F81D: using guessed type int16_t word_17F81D[];
// 17FD32: using guessed type char byte_17FD32;
// 197F98: using guessed type int dword_197F98;


//----- (00056B26) --------------------------------------------------------
void __fastcall sub_56B26( int a1)
{
  int16_t i; // bx
  int16_t v2; // [esp+4h] [ebp-4h]

  v2 = 0;
  if ( a1 < 8 )
  {
    for ( i = 0; i < 40; ++i )
    {
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + word_17F80D[14 * i] + 279) == 3
        && (byte_17F80F[28 * i] == 1 || byte_17F80F[28 * i] == 2)
        && word_17F819[14 * i] > v2 )
      {
        v2 = word_17F819[14 * i];
      }
    }
  }
  JUMPOUT(0x56D18);
}
// 56BB8: control flows out of bounds to 56D18
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F819: using guessed type int16_t word_17F819[];
// 197F98: using guessed type int dword_197F98;


//----- (00056BFA) --------------------------------------------------------
void __fastcall sub_56BFA( int a1)
{
  int16_t i; // bx
  int16_t v2; // [esp+4h] [ebp-4h]

  v2 = 0;
  if ( a1 < 8 )
  {
    for ( i = 0; i < 40; ++i )
    {
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + word_17F80D[14 * i] + 279) == 3
        && byte_17F80F[28 * i] == 1
        && word_17F819[14 * i] > v2 )
      {
        v2 = word_17F819[14 * i];
      }
    }
  }
  JUMPOUT(0x56995);
}
// 56C7C: control flows out of bounds to 56995
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F819: using guessed type int16_t word_17F819[];
// 197F98: using guessed type int dword_197F98;


//----- (00056CA2) --------------------------------------------------------
int __fastcall sub_56CA2( int a1)
{
  int v1; // ebx
  int v2; // edx
  int16_t v4; // [esp+4h] [ebp-4h]

  v1 = 21;
  v4 = 0;
  if ( a1 >= 8 )
    return 24;
  v2 = 0;
  do
  {
    if ( *(_BYTE *)(3753 * a1 + dword_197F98 + word_17F80D[14 * (int16_t)v2] + 279) == 3
      && byte_17F80F[28 * (int16_t)v2] == 3
      && word_17F819[14 * (int16_t)v2] > v4 )
    {
      v1 = v2;
      v4 = word_17F819[14 * (int16_t)v2];
    }
    ++v2;
  }
  while ( (int16_t)v2 < 40 );
  return v1;
}
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F819: using guessed type int16_t word_17F819[];
// 197F98: using guessed type int dword_197F98;


//----- (00056D3A) --------------------------------------------------------
int __fastcall sub_56D3A( int a1, int a2)
{
  int v2; // ebx
  int v3; // edx
  int16_t v5; // [esp+4h] [ebp-8h]

  v2 = 0;
  v5 = 0;
  if ( a1 >= 8 )
  {
    switch ( a1 )
    {
      case 8:
        v2 = 37;
        break;
      case 9:
      case 11:
      case 12:
      case 14:
        v2 = 0;
        break;
      case 10:
        v2 = 45;
        break;
      case 13:
        v2 = 44;
        break;
      default:
        return v2;
    }
  }
  else
  {
    v3 = 0;
    do
    {
      if ( ((_WORD)v3 != 37 || a2 >= 4)
        && ((_WORD)v3 != 38 || a2 >= 5)
        && *(_BYTE *)(3753 * a1 + dword_197F98 + word_17F80D[14 * (int16_t)v3] + 279) == 3
        && (byte_17F80F[28 * (int16_t)v3] == 5 || byte_17F80F[28 * (int16_t)v3] == 4)
        && (uint8_t)byte_17F81C[28 * (int16_t)v3] > v5 )
      {
        v2 = v3;
        v5 = (uint8_t)byte_17F81C[28 * (int16_t)v3];
      }
      ++v3;
    }
    while ( (int16_t)v3 < 40 );
  }
  return v2;
}
// 17F80D: using guessed type int16_t word_17F80D[];
// 197F98: using guessed type int dword_197F98;


//----- (00056E04) --------------------------------------------------------
void __fastcall sub_56E04( int a1)
{
  int16_t i; // dx
  int16_t v2; // [esp+4h] [ebp-4h]

  v2 = 0;
  if ( a1 < 8 )
  {
    for ( i = 0; i < 39; ++i )
    {
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + *(int16_t *)((char *)&word_17EEE6 + 47 * i) + 279) == 3
        && byte_17EF0C[47 * i] == 1
        && *(int16_t *)((char *)&word_17EF0D + 47 * i) > v2 )
      {
        v2 = *(int16_t *)((char *)&word_17EF0D + 47 * i);
      }
    }
  }
  JUMPOUT(0x56D16);
}
// 56E6D: control flows out of bounds to 56D16
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EF0D: using guessed type int16_t word_17EF0D;
// 197F98: using guessed type int dword_197F98;


//----- (00056E72) --------------------------------------------------------
void __fastcall sub_56E72( int a1)
{
  int16_t i; // dx
  int16_t v2; // [esp+4h] [ebp-4h]

  v2 = 0;
  if ( a1 < 8 )
  {
    for ( i = 0; i < 39; ++i )
    {
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + *(int16_t *)((char *)&word_17EEE6 + 47 * i) + 279) == 3
        && (byte_17EF0C[47 * i] == 2 || byte_17EF0C[47 * i] == 7)
        && *(int16_t *)((char *)&word_17EF0D + 47 * i) > v2 )
      {
        v2 = *(int16_t *)((char *)&word_17EF0D + 47 * i);
      }
    }
  }
  JUMPOUT(0x56D16);
}
// 56EEB: control flows out of bounds to 56D16
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EF0D: using guessed type int16_t word_17EF0D;
// 197F98: using guessed type int dword_197F98;


//----- (00056EF0) --------------------------------------------------------
void __fastcall sub_56EF0( int a1)
{
  int16_t i; // dx
  int16_t v2; // [esp+4h] [ebp-4h]

  v2 = 0;
  if ( a1 < 8 )
  {
    for ( i = 0; i < 39; ++i )
    {
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + *(int16_t *)((char *)&word_17EEE6 + 47 * i) + 279) == 3
        && (byte_17EF0C[47 * i] == 3 || byte_17EF0C[47 * i] == 6)
        && *(int16_t *)((char *)&word_17EF0D + 47 * i) > v2 )
      {
        v2 = *(int16_t *)((char *)&word_17EF0D + 47 * i);
      }
    }
  }
  JUMPOUT(0x56D16);
}
// 56F69: control flows out of bounds to 56D16
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EF0D: using guessed type int16_t word_17EF0D;
// 197F98: using guessed type int dword_197F98;


//----- (00056F6E) --------------------------------------------------------
void __fastcall sub_56F6E( int a1)
{
  int16_t i; // dx
  int16_t v2; // [esp+4h] [ebp-4h]

  v2 = 0;
  if ( a1 < 8 )
  {
    for ( i = 0; i < 39; ++i )
    {
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + *(int16_t *)((char *)&word_17EEE6 + 47 * i) + 279) == 3
        && (byte_17EF0C[47 * i] == 4 || byte_17EF0C[47 * i] == 6)
        && *(int16_t *)((char *)&word_17EF0D + 47 * i) > v2 )
      {
        v2 = *(int16_t *)((char *)&word_17EF0D + 47 * i);
      }
    }
  }
  JUMPOUT(0x56D16);
}
// 56FE7: control flows out of bounds to 56D16
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EF0D: using guessed type int16_t word_17EF0D;
// 197F98: using guessed type int dword_197F98;


//----- (00056FEC) --------------------------------------------------------
void __fastcall sub_56FEC( int a1)
{
  int16_t i; // bx
  int16_t v2; // [esp+4h] [ebp-4h]

  v2 = 0;
  if ( a1 < 8 )
  {
    for ( i = 0; i < 39; ++i )
    {
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + *(int16_t *)((char *)&word_17EEE6 + 47 * i) + 279) == 3
        && (byte_17EF0C[47 * i] == 5 || byte_17EF0C[47 * i] == 7)
        && *(int16_t *)((char *)&word_17EF0D + 47 * i) > v2 )
      {
        v2 = *(int16_t *)((char *)&word_17EF0D + 47 * i);
      }
    }
  }
  JUMPOUT(0x56995);
}
// 5706D: control flows out of bounds to 56995
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EF0D: using guessed type int16_t word_17EF0D;
// 197F98: using guessed type int dword_197F98;


//----- (00057072) --------------------------------------------------------
int __fastcall sub_57072( int a1)
{
  int result; // eax

  result = 0;
  if ( a1 < 8 && *(_BYTE *)(3753 * a1 + dword_197F98 + 360) == 3 )
    return 13;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0005709F) --------------------------------------------------------
void __fastcall sub_5709F( int a1)
{
  int16_t i; // dx
  int16_t v2; // [esp+4h] [ebp-4h]

  v2 = word_17FFEA[0];
  if ( a1 < 8 )
  {
    for ( i = 0; i < 6; ++i )
    {
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + word_17FFE8[5 * i] + 279) == 3 && word_17FFEA[5 * i] > v2 )
        v2 = word_17FFEA[5 * i];
    }
  }
  JUMPOUT(0x56D16);
}
// 5710D: control flows out of bounds to 56D16
// 17FFE8: using guessed type int16_t word_17FFE8[];
// 17FFEA: using guessed type int16_t word_17FFEA[];
// 197F98: using guessed type int dword_197F98;


//----- (00057112) --------------------------------------------------------
void __fastcall sub_57112( int a1)
{
  int16_t i; // cx
  int16_t v4; // bx
  int v5; // edi

  if ( byte_199CB4 == 1 )
  {
    sub_574A1();
  }
  else if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 40) == 100 )
  {
    sub_572AB(a1);
    sub_57197(a1);
  }
  else
  {
    sub_57197(a1);
    for ( i = 0; i <= 4; ++i )
    {
      v4 = i;
      v5 = 99 * i;
      sub_616A5(a1, v5 + 3753 * a1 + dword_197F98 + 806, v4);
    }
  }
  JUMPOUT(0x56A34);
}
// 5712C: control flows out of bounds to 56A34
// 197F98: using guessed type int dword_197F98;
// 199CB4: using guessed type char byte_199CB4;


//----- (00057197) --------------------------------------------------------
void __fastcall sub_57197( int a1)
{
  char v3; // al
  int16_t v4; // bx
  int v5; // eax
  int v6; // esi
  uint8_t *v7; // eax
  char v8; // di
  uint8_t *v9; // eax
  char v10; // [esp+8h] [ebp-Ch]
  int16_t v11; // [esp+Ch] [ebp-8h]
  uint8_t v12; // [esp+10h] [ebp-4h]

  if ( !*(_BYTE *)(3753 * a1 + dword_197F98 + 36) )
  {
    sub_5685F(a1);
    v10 = v3;
    v4 = 0;
    v11 = sub_56726(a1);
    while ( v4 < word_199994 )
    {
      v5 = dword_197F9C + 129 * v4;
      if ( *(char *)(v5 + 99) == a1 && (*(_BYTE *)(v5 + 100) == 4 || *(_BYTE *)(v5 + 100) == 6) )
      {
        v6 = 129 * v4;
        v7 = (uint8_t *)(v6 + dword_197F9C);
        if ( *(uint8_t *)(v6 + dword_197F9C + 19) != v11 )
        {
          v8 = v7[96] - byte_17FE90[46 * v7[19] + v7[16]];
          v7[19] = v11;
          v12 = sub_575D6(a1, v11);
          v9 = (uint8_t *)(v6 + dword_197F9C);
          v9[20] = v12;
          v9[96] = byte_17FE90[46 * v9[19] + v9[16]] + v8;
        }
        *(_BYTE *)(129 * v4 + dword_197F9C + 22) = v10;
      }
      ++v4;
    }
  }
  JUMPOUT(0x56A34);
}
// 572A6: control flows out of bounds to 56A34
// 571C2: variable 'v3' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000572AB) --------------------------------------------------------
void __fastcall sub_572AB( int a1)
{
  uint8_t v3; // al
  int16_t v4; // bx
  uint8_t *v5; // eax
  char v6; // di
  uint8_t *v7; // eax
  int v8; // esi
  int v9; // esi
  int v10; // [esp+4h] [ebp-18h]
  uint8_t v11; // [esp+10h] [ebp-Ch]
  uint8_t v12; // [esp+14h] [ebp-8h]
  int16_t v13; // [esp+18h] [ebp-4h]

  sub_5685F(a1);
  v12 = v3;
  v4 = 0;
  v13 = sub_56726(a1);
  while ( 1 )
  {
    v10 = 3753 * a1;
    v5 = (uint8_t *)(99 * v4 + v10 + dword_197F98);
    v5[828] = v12;
    if ( v5[825] != v13 )
    {
      v6 = v5[902] - byte_17FE90[46 * v5[825] + v5[822]];
      v5[825] = v13;
      v11 = sub_575D6(a1, v13);
      v7 = (uint8_t *)(99 * v4 + v10 + dword_197F98);
      v8 = 46 * v7[825];
      v7[826] = v11;
      v7[902] = byte_17FE90[v7[822] + v8] + v6;
    }
    v9 = 99 * v4++;
    *(_WORD *)(dword_197F98 + 3753 * a1 + v9 + 900) = sub_6B577(a1, v9 + 3753 * a1 + dword_197F98 + 806);
    if ( v4 >= 6 )
      JUMPOUT(0x56A34);
  }
}
// 573C2: control flows out of bounds to 56A34
// 572C0: variable 'v3' is possibly undefined
// 197F98: using guessed type int dword_197F98;


//----- (000573C7) --------------------------------------------------------
void sub_573C7()
{
  int16_t i; // si
  int16_t j; // cx
  int v2; // ebx
  int v3; // eax
  int16_t v4; // [esp+Ch] [ebp-4h]
  int16_t v5; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < word_199998; ++i )
  {
    for ( j = 0; j < 6; ++j )
    {
      v2 = 99 * j;
      v4 = *(char *)(v2 + dword_197F98 + 3753 * i + 898);
      sub_127776((_BYTE *)(v2 + dword_197F98 + 3753 * i + 806), 0x63u);
      sub_57871(i, j, 3753 * i + dword_197F98 + 806 + v2);
      if ( j == 5 )
      {
        LOBYTE(v5) = 43;
      }
      else
      {
        v5 = v4 + 1;
        if ( v5 == 8 * j + 8 )
          LOBYTE(v5) = 8 * j;
      }
      v3 = 3753 * i + dword_197F98 + 99 * j;
      *(_BYTE *)(v3 + 898) = v5;
    }
  }
  JUMPOUT(0x56A34);
}
// 5749C: control flows out of bounds to 56A34
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000574A1) --------------------------------------------------------
void sub_574A1()
{
  int16_t v0; // cx
  int v1; // ebx
  int v2; // eax
  int16_t v3; // [esp+0h] [ebp-10h]
  int16_t v4; // [esp+Ch] [ebp-4h]
  int16_t v5; // [esp+Ch] [ebp-4h]

  v0 = 0;
  while ( 1 )
  {
    v1 = 99 * v0;
    v4 = *(char *)(v1 + dword_197F98 + 3753 * v3 + 898);
    sub_127776((_BYTE *)(v1 + dword_197F98 + 3753 * v3 + 806), 0x63u);
    sub_57871(v3, v0, 3753 * v3 + dword_197F98 + 806 + v1);
    if ( v0 == 5 )
    {
      LOBYTE(v5) = 43;
    }
    else
    {
      v5 = v4 + 1;
      if ( v5 == 8 * v0 + 8 )
        LOBYTE(v5) = 8 * v0;
    }
    v2 = dword_197F98 + 3753 * v3 + 99 * v0++;
    *(_BYTE *)(v2 + 898) = v5;
    if ( v0 >= 6 )
      JUMPOUT(0x56A34);
  }
}
// 57561: control flows out of bounds to 56A34
// 574AB: variable 'v3' is possibly undefined
// 197F98: using guessed type int dword_197F98;


//----- (00057566) --------------------------------------------------------
int __fastcall sub_57566( int a1, int a2)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = 3 * word_18001E[18 * *(uint8_t *)(a2 + 16)] / 2;
  sub_6E1A0(a1, &v3);
  return v3;
}
// 18001E: using guessed type int16_t word_18001E[];


//----- (00057597) --------------------------------------------------------
int16_t __fastcall sub_57597( int a1)
{
  int16_t result; // ax

  result = 1;
  if ( a1 < 8 )
  {
    result = word_17FE9C[23 * (int16_t)sub_56726(a1)];
    if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 2236) )
      result += 2;
  }
  return result;
}
// 17FE9C: using guessed type int16_t word_17FE9C[];
// 197F98: using guessed type int dword_197F98;


//----- (000575D6) --------------------------------------------------------
int16_t __fastcall sub_575D6( int a1, int a2)
{
  int16_t result; // ax

  if ( a1 >= 8 )
    return a2 > 0;
  result = word_17FE9C[23 * a2];
  if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 2236) )
    result += 2;
  return result;
}
// 17FE9C: using guessed type int16_t word_17FE9C[];
// 197F98: using guessed type int dword_197F98;


//----- (00057617) --------------------------------------------------------
int16_t __fastcall sub_57617( int a1, int a2)
{
  int v3; // eax

  LOWORD(v3) = word_18002E[18 * a2];
  if ( a1 < 8 && *(_BYTE *)(dword_197F98 + 3753 * a1 + 368) == 3 )
    return 3 * (int16_t)v3 / 2;
  return v3;
}
// 18002E: using guessed type int16_t word_18002E[];
// 197F98: using guessed type int dword_197F98;


//----- (00057651) --------------------------------------------------------
int16_t __fastcall sub_57651( int a1)
{
  return word_180030[18 * a1];
}
// 180030: using guessed type int16_t word_180030[];


//----- (0005765D) --------------------------------------------------------
int16_t __fastcall sub_5765D( int a1)
{
  return word_180032[18 * a1];
}
// 180032: using guessed type int16_t word_180032[];


//----- (00057675) --------------------------------------------------------
void __fastcall sub_57675(int a1, int a2, int a3)
{
  int16_t v7; // ax
  int16_t v8; // bx
  int16_t v9; // ax
  int16_t v10; // ax
  int v11; // eax
  int v12; // eax
  int16_t v13; // dx
  int16_t v14; // ax
  int16_t v15; // ax
  int16_t v16; // ax
  int16_t v17; // ax
  int16_t v18; // ax
  int16_t v19; // ax
  int16_t v21; // [esp+4h] [ebp-10h]
  int16_t v22; // [esp+8h] [ebp-Ch]
  int16_t v23; // [esp+8h] [ebp-Ch]
  int16_t v24; // [esp+8h] [ebp-Ch]
  int16_t v25; // [esp+Ch] [ebp-8h]
  int16_t v26; // [esp+10h] [ebp-4h]

  sub_568EB(a2);
  v26 = v7;
  v8 = 0;
  v9 = sub_57617(a2, a3);
  if ( v26 > 0 && v9 > 0 )
  {
    *(_BYTE *)(a1 + 32) = 16;
    *(_BYTE *)(a1 + 35) = 5;
    *(_WORD *)(a1 + 33) = 0;
    *(_WORD *)(a1 + 28) = v26;
    *(_BYTE *)(a1 + 30) = v9;
    v8 = 1;
    *(_BYTE *)(a1 + 31) = v9;
  }
  sub_56B26(a2);
  v25 = v10;
  v22 = word_180030[18 * a3];
  if ( v10 > 0 && word_180030[18 * a3] > 0 )
  {
    v11 = v8;
    *(_BYTE *)(a1 + 8 * v8 + 32) = 16;
    *(_WORD *)(a1 + 8 * v8 + 33) = 0;
    *(_BYTE *)(a1 + 8 * v8 + 35) = 5;
    *(_WORD *)(a1 + 8 * v8 + 28) = v25;
    *(_BYTE *)(a1 + 8 * v8++ + 30) = v22;
    *(_BYTE *)(a1 + 8 * v11 + 31) = v22;
  }
  v21 = sub_56D3A(a2, a3);
  v23 = word_180032[18 * a3];
  if ( v21 > 0 && word_180032[18 * a3] > 0 )
  {
    v12 = v8;
    *(_BYTE *)(a1 + 8 * v8 + 32) = 16;
    *(_WORD *)(a1 + 8 * v8 + 33) = 0;
    *(_BYTE *)(a1 + 8 * v8 + 35) = 5;
    *(_WORD *)(a1 + 8 * v8 + 28) = v21;
    *(_BYTE *)(a1 + 8 * v8++ + 30) = v23;
    *(_BYTE *)(a1 + 8 * v12 + 31) = v23;
  }
  v13 = sub_56CA2(a2);
  v24 = word_180034[18 * a3];
  if ( v13 > 0 && word_180034[18 * a3] > 0 )
  {
    *(_BYTE *)(a1 + 8 * v8 + 32) = 16;
    *(_WORD *)(a1 + 8 * v8 + 33) = 0;
    *(_BYTE *)(a1 + 8 * v8 + 35) = 10;
    *(_WORD *)(a1 + 8 * v8 + 28) = v13;
    *(_BYTE *)(a1 + 8 * v8 + 30) = v24;
    *(_BYTE *)(a1 + 8 * v8 + 31) = v24;
  }
  sub_56E04(a2);
  if ( v14 > 0 )
    sub_127712(a1 + 23, v14);
  sub_56E72(a2);
  if ( v15 > 0 )
    sub_127712(a1 + 23, v15);
  sub_56FEC(a2);
  if ( v16 > 0 )
    sub_127712(a1 + 23, v16);
  v17 = 0;
  if ( a2 < 8 && *(_BYTE *)(3753 * a2 + dword_197F98 + 360) == 3 )
    v17 = 13;
  if ( v17 > 0 )
    sub_127712(a1 + 23, v17);
  sub_56EF0(a2);
  if ( v18 > 0 )
    sub_127712(a1 + 23, v18);
  sub_56F6E(a2);
  if ( v19 > 0 )
    sub_127712(a1 + 23, v19);
}
// 57690: variable 'v7' is possibly undefined
// 576D6: variable 'v10' is possibly undefined
// 577C9: variable 'v14' is possibly undefined
// 577E1: variable 'v15' is possibly undefined
// 577F9: variable 'v16' is possibly undefined
// 57847: variable 'v18' is possibly undefined
// 5785F: variable 'v19' is possibly undefined
// 180030: using guessed type int16_t word_180030[];
// 180032: using guessed type int16_t word_180032[];
// 180034: using guessed type int16_t word_180034[];
// 197F98: using guessed type int dword_197F98;


//----- (00057871) --------------------------------------------------------
int16_t __fastcall sub_57871( int a1, int a2, int a3)
{
  char v3; // al
  int16_t v4; // dx
  int16_t result; // ax
  int v7; // [esp+8h] [ebp-4h] BYREF

  strcpy((char *)a3, (char *)*(&off_18003A + 9 * a2));
  *(_BYTE *)(a3 + 16) = a2;
  *(_BYTE *)(a3 + 19) = sub_56726(a1);
  *(_BYTE *)(a3 + 18) = sub_5679E(a1);
  *(_BYTE *)(a3 + 21) = sub_5680D(a1);
  sub_5685F(a1);
  *(_BYTE *)(a3 + 22) = v3;
  v7 = 3 * word_18001E[18 * *(uint8_t *)(99 * a2 + dword_197F98 + 3753 * a1 + 806 + 16)] / 2;
  sub_6E1A0(a1, &v7);
  *(_WORD *)(a3 + 94) = v7;
  sub_57675(a3, a1, a2);
  if ( a2 == 5 )
    *(_BYTE *)(a3 + 92) = 43;
  else
    *(_BYTE *)(a3 + 92) = 8 * a2;
  v4 = *(uint8_t *)(a3 + 19);
  *(_BYTE *)(a3 + 93) = a1;
  *(_BYTE *)(a3 + 20) = sub_575D6(a1, v4);
  result = dword_192FD8;
  *(_WORD *)(a3 + 97) = dword_192FD8;
  return result;
}
// 578C3: variable 'v3' is possibly undefined
// 18001E: using guessed type int16_t word_18001E[];
// 18003A: using guessed type _UNKNOWN *off_18003A;
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;


//----- (0005794B) --------------------------------------------------------
void __fastcall sub_5794B( int a1)
{
  int v1; // ebx
  int16_t v2; // cx
  uint8_t v3; // al
  char v4; // al
  char v5; // dl
  int v6; // eax
  int16_t v7; // bx

  v1 = 129 * a1;
  if ( *(char *)(v1 + dword_197F9C + 99) < 8 )
  {
    if ( byte_199CB4 )
    {
      v2 = *(char *)(v1 + dword_197F9C + 99);
      v3 = sub_56726(v2);
      *(_BYTE *)(v1 + dword_197F9C + 19) = v3;
      *(_BYTE *)(v1 + dword_197F9C + 20) = sub_575D6(v2, v3);
      *(_BYTE *)(v1 + dword_197F9C + 18) = sub_5679E(v2);
      *(_BYTE *)(v1 + dword_197F9C + 21) = sub_5680D(v2);
      sub_5685F(v2);
      v5 = v4;
      v6 = v1 + dword_197F9C;
      v7 = *(uint8_t *)(v1 + dword_197F9C + 16);
      *(_BYTE *)(v6 + 22) = v5;
      sub_57675(v6, v2, v7);
    }
  }
}
// 579E6: variable 'v4' is possibly undefined
// 197F9C: using guessed type int dword_197F9C;
// 199CB4: using guessed type char byte_199CB4;


//----- (00057A02) --------------------------------------------------------
int __fastcall sub_57A02(int a1, int a2)
{
  int result; // eax
  char v5; // dl

  sub_127776((_BYTE *)a1, 0x63u);
  strcpy((char *)a1, (char *)dword_192674);
  *(_BYTE *)(a1 + 17) = 0;
  *(_BYTE *)(a1 + 18) = 0;
  *(_BYTE *)(a1 + 21) = 5;
  if ( a2 )
  {
    *(_BYTE *)(a1 + 16) = 4;
    *(_BYTE *)(a1 + 22) = 0;
    *(_BYTE *)(a1 + 20) = 1;
    result = sub_56726(12);
    *(_WORD *)(a1 + 28) = 41;
    *(_BYTE *)(a1 + 32) = 15;
    *(_WORD *)(a1 + 33) = 4;
    *(_BYTE *)(a1 + 35) = 0;
    *(_BYTE *)(a1 + 30) = 20;
    *(_BYTE *)(a1 + 31) = 20;
    *(_BYTE *)(a1 + 19) = result;
    *(_WORD *)(a1 + 36) = 40;
    *(_BYTE *)(a1 + 40) = 15;
    *(_WORD *)(a1 + 41) = 0x4000;
    *(_BYTE *)(a1 + 43) = 0;
    *(_BYTE *)(a1 + 38) = 1;
    *(_BYTE *)(a1 + 39) = 1;
    v5 = byte_17FE90[46 * *(uint8_t *)(a1 + 19) + *(uint8_t *)(a1 + 16)] + 4;
    *(_BYTE *)(a1 + 92) = 10;
  }
  else
  {
    *(_BYTE *)(a1 + 16) = 2;
    *(_BYTE *)(a1 + 22) = 0;
    *(_BYTE *)(a1 + 20) = 0;
    *(_WORD *)(a1 + 28) = 41;
    *(_BYTE *)(a1 + 32) = 15;
    *(_WORD *)(a1 + 33) = 4;
    *(_BYTE *)(a1 + 35) = 0;
    *(_BYTE *)(a1 + 30) = 8;
    *(_BYTE *)(a1 + 31) = 8;
    *(_WORD *)(a1 + 36) = 40;
    *(_BYTE *)(a1 + 40) = 15;
    *(_BYTE *)(a1 + 43) = 0;
    *(_BYTE *)(a1 + 39) = 1;
    *(_BYTE *)(a1 + 38) = 1;
    *(_WORD *)(a1 + 41) = 0;
    result = sub_56726(12);
    v5 = byte_17FE90[46 * (int16_t)result + *(uint8_t *)(a1 + 16)] + 4;
    *(_BYTE *)(a1 + 92) = 22;
  }
  *(_BYTE *)(a1 + 96) = v5;
  *(_BYTE *)(a1 + 93) = 12;
  *(_WORD *)(a1 + 94) = 0;
  return result;
}
// 192674: using guessed type int dword_192674;


//----- (00057B1C) --------------------------------------------------------
int __fastcall sub_57B1C(int a1, int a2)
{
  int v4; // esi
  int v5; // eax
  char v6; // al
  char v7; // al
  int result; // eax

  sub_127776((_BYTE *)a1, 0x63u);
  strcpy((char *)a1, (char *)dword_19267C);
  *(_BYTE *)(a1 + 17) = 0;
  *(_BYTE *)(a1 + 18) = 0;
  *(_BYTE *)(a1 + 21) = 2;
  if ( a2 )
  {
    *(_BYTE *)(a1 + 16) = 4;
    *(_BYTE *)(a1 + 22) = 0;
    *(_BYTE *)(a1 + 19) = sub_56726(14);
    v4 = 46 * *(uint8_t *)(a1 + 19);
    *(_BYTE *)(a1 + 20) = 1;
    *(_WORD *)(a1 + 28) = 43;
    *(_BYTE *)(a1 + 32) = 15;
    *(_WORD *)(a1 + 33) = 2;
    *(_BYTE *)(a1 + 35) = 0;
    *(_BYTE *)(a1 + 30) = 5;
    v5 = *(uint8_t *)(a1 + 16);
    *(_BYTE *)(a1 + 31) = 5;
    v6 = byte_17FE90[v4 + v5];
    *(_BYTE *)(a1 + 92) = 12;
  }
  else
  {
    *(_BYTE *)(a1 + 16) = 2;
    sub_5685F(14);
    *(_BYTE *)(a1 + 20) = 0;
    *(_WORD *)(a1 + 28) = 43;
    *(_BYTE *)(a1 + 32) = 15;
    *(_BYTE *)(a1 + 35) = 0;
    *(_BYTE *)(a1 + 30) = 3;
    *(_BYTE *)(a1 + 31) = 3;
    *(_BYTE *)(a1 + 22) = v7;
    *(_WORD *)(a1 + 33) = 0;
    v6 = byte_17FE90[46 * (int16_t)sub_56726(14) + *(uint8_t *)(a1 + 16)];
    *(_BYTE *)(a1 + 92) = 24;
  }
  *(_BYTE *)(a1 + 96) = v6;
  result = sub_127712(a1 + 23, 0xAu);
  *(_WORD *)(a1 + 94) = 0;
  *(_BYTE *)(a1 + 93) = 14;
  return result;
}
// 57BC6: variable 'v7' is possibly undefined
// 19267C: using guessed type int dword_19267C;


//----- (00057C0B) --------------------------------------------------------
int __fastcall sub_57C0B(int a1, int a2)
{
  int v4; // esi
  int v5; // eax
  int result; // eax

  sub_127776((_BYTE *)a1, 0x63u);
  strcpy((char *)a1, (char *)dword_19266C);
  if ( a2 )
  {
    *(_BYTE *)(a1 + 16) = 3;
    *(_BYTE *)(a1 + 17) = 0;
    *(_BYTE *)(a1 + 18) = 0;
    *(_BYTE *)(a1 + 19) = sub_56726(10);
    v4 = 46 * *(uint8_t *)(a1 + 19);
    *(_BYTE *)(a1 + 21) = 2;
    *(_BYTE *)(a1 + 22) = 0;
    *(_BYTE *)(a1 + 20) = 1;
    *(_WORD *)(a1 + 28) = 45;
    *(_BYTE *)(a1 + 32) = 15;
    *(_WORD *)(a1 + 33) = 0;
    *(_BYTE *)(a1 + 35) = 0;
    *(_BYTE *)(a1 + 30) = 2;
    *(_BYTE *)(a1 + 31) = 2;
    *(_WORD *)(a1 + 36) = 23;
    *(_BYTE *)(a1 + 40) = 15;
    *(_WORD *)(a1 + 41) = 0;
    *(_BYTE *)(a1 + 43) = 10;
    *(_BYTE *)(a1 + 38) = 5;
    *(_BYTE *)(a1 + 39) = 5;
    v5 = *(uint8_t *)(a1 + 16);
    *(_BYTE *)(a1 + 92) = 8;
  }
  else
  {
    *(_BYTE *)(a1 + 16) = 2;
    *(_BYTE *)(a1 + 17) = 0;
    *(_BYTE *)(a1 + 18) = 0;
    *(_BYTE *)(a1 + 21) = 2;
    *(_BYTE *)(a1 + 22) = 0;
    *(_BYTE *)(a1 + 19) = 0;
    *(_BYTE *)(a1 + 20) = 0;
    *(_WORD *)(a1 + 28) = 45;
    *(_BYTE *)(a1 + 32) = 15;
    *(_BYTE *)(a1 + 35) = 0;
    *(_BYTE *)(a1 + 30) = 1;
    *(_BYTE *)(a1 + 31) = 1;
    *(_BYTE *)(a1 + 92) = 20;
    *(_WORD *)(a1 + 33) = 0;
    v5 = 46 * (int16_t)sub_56726(10);
    v4 = *(uint8_t *)(a1 + 16);
  }
  *(_BYTE *)(a1 + 96) = byte_17FE90[v4 + v5];
  result = sub_127712(a1 + 23, 0x27u);
  *(_WORD *)(a1 + 94) = 0;
  *(_BYTE *)(a1 + 93) = 10;
  return result;
}
// 19266C: using guessed type int dword_19266C;


//----- (00057D14) --------------------------------------------------------
void __fastcall sub_57D14(int a1, int a2)
{
  char v3; // al
  int v4; // esi
  int v5; // ecx
  char v6; // cl

  sub_127776((_BYTE *)a1, 0x63u);
  strcpy((char *)a1, (char *)dword_192678);
  *(_BYTE *)(a1 + 17) = 0;
  *(_BYTE *)(a1 + 18) = 0;
  *(_BYTE *)(a1 + 21) = 4;
  if ( a2 )
  {
    *(_BYTE *)(a1 + 16) = 3;
    v3 = sub_56726(13);
    *(_BYTE *)(a1 + 22) = 0;
    *(_BYTE *)(a1 + 19) = v3;
    *(_BYTE *)(a1 + 20) = 1;
    sub_127712(a1 + 23, 0x13u);
    v4 = 46 * *(uint8_t *)(a1 + 19);
    *(_WORD *)(a1 + 28) = 44;
    *(_BYTE *)(a1 + 32) = 15;
    *(_WORD *)(a1 + 33) = 0;
    *(_BYTE *)(a1 + 35) = 0;
    *(_BYTE *)(a1 + 30) = 2;
    v5 = *(uint8_t *)(a1 + 16);
    *(_BYTE *)(a1 + 31) = 2;
    v6 = byte_17FE90[v5 + v4] + 8;
    *(_BYTE *)(a1 + 92) = 11;
  }
  else
  {
    *(_BYTE *)(a1 + 16) = 2;
    *(_BYTE *)(a1 + 22) = 0;
    *(_BYTE *)(a1 + 19) = 0;
    *(_BYTE *)(a1 + 20) = 0;
    sub_127712(a1 + 23, 0x13u);
    *(_WORD *)(a1 + 28) = 44;
    *(_BYTE *)(a1 + 32) = 15;
    *(_WORD *)(a1 + 33) = 0;
    *(_BYTE *)(a1 + 35) = 0;
    *(_BYTE *)(a1 + 30) = 1;
    *(_BYTE *)(a1 + 31) = 1;
    v6 = byte_17FE90[46 * (int16_t)sub_56726(13) + *(uint8_t *)(a1 + 16)] + 8;
    *(_BYTE *)(a1 + 92) = 23;
  }
  *(_BYTE *)(a1 + 96) = v6;
  *(_WORD *)(a1 + 94) = 0;
  *(_BYTE *)(a1 + 93) = 13;
  JUMPOUT(0x56580);
}
// 57E16: control flows out of bounds to 56580
// 192678: using guessed type int dword_192678;


//----- (00057E1B) --------------------------------------------------------
char __fastcall sub_57E1B(int a1, int a2)
{
  int v4; // esi
  int v5; // eax
  char result; // al

  sub_127776((_BYTE *)a1, 0x63u);
  strcpy((char *)a1, (char *)dword_192670);
  *(_BYTE *)(a1 + 17) = 0;
  *(_BYTE *)(a1 + 18) = 0;
  *(_BYTE *)(a1 + 21) = 5;
  if ( a2 )
  {
    *(_BYTE *)(a1 + 16) = 4;
    *(_BYTE *)(a1 + 22) = 0;
    *(_BYTE *)(a1 + 19) = sub_56726(11);
    v4 = 46 * *(uint8_t *)(a1 + 19);
    *(_BYTE *)(a1 + 20) = 1;
    *(_WORD *)(a1 + 28) = 42;
    *(_BYTE *)(a1 + 32) = 15;
    *(_WORD *)(a1 + 33) = 2;
    *(_BYTE *)(a1 + 35) = 0;
    *(_BYTE *)(a1 + 30) = 1;
    *(_BYTE *)(a1 + 31) = 1;
    *(_WORD *)(a1 + 36) = 26;
    *(_BYTE *)(a1 + 40) = 15;
    *(_WORD *)(a1 + 41) = 0;
    *(_BYTE *)(a1 + 43) = 10;
    *(_BYTE *)(a1 + 38) = 5;
    v5 = *(uint8_t *)(a1 + 16);
    *(_BYTE *)(a1 + 39) = 5;
    result = byte_17FE90[v4 + v5];
    *(_BYTE *)(a1 + 92) = 9;
  }
  else
  {
    *(_BYTE *)(a1 + 16) = 2;
    *(_BYTE *)(a1 + 22) = 0;
    *(_BYTE *)(a1 + 19) = 0;
    *(_BYTE *)(a1 + 20) = 0;
    *(_WORD *)(a1 + 28) = 42;
    *(_BYTE *)(a1 + 32) = 15;
    *(_BYTE *)(a1 + 35) = 0;
    *(_BYTE *)(a1 + 30) = 1;
    *(_BYTE *)(a1 + 31) = 1;
    *(_WORD *)(a1 + 36) = 25;
    *(_BYTE *)(a1 + 40) = 15;
    *(_BYTE *)(a1 + 43) = 10;
    *(_BYTE *)(a1 + 38) = 5;
    *(_BYTE *)(a1 + 39) = 5;
    *(_WORD *)(a1 + 33) = 0;
    *(_WORD *)(a1 + 41) = 0;
    result = byte_17FE90[46 * (int16_t)sub_56726(11) + *(uint8_t *)(a1 + 16)];
    *(_BYTE *)(a1 + 92) = 21;
  }
  *(_BYTE *)(a1 + 96) = result;
  *(_WORD *)(a1 + 94) = 0;
  *(_BYTE *)(a1 + 93) = 11;
  return result;
}
// 192670: using guessed type int dword_192670;


//----- (00057F2C) --------------------------------------------------------
void __fastcall sub_57F2C(int a1)
{
  sub_127776((_BYTE *)a1, 0x63u);
  strcpy((char *)a1, (char *)dword_192668);
  *(_BYTE *)(a1 + 17) = 0;
  *(_BYTE *)(a1 + 18) = 3;
  *(_BYTE *)(a1 + 21) = 5;
  *(_BYTE *)(a1 + 16) = 4;
  *(_BYTE *)(a1 + 22) = 6;
  *(_BYTE *)(a1 + 19) = 0;
  *(_BYTE *)(a1 + 20) = 0;
  *(_WORD *)(a1 + 28) = 11;
  *(_BYTE *)(a1 + 32) = 15;
  *(_WORD *)(a1 + 33) = 2;
  *(_BYTE *)(a1 + 35) = 0;
  *(_BYTE *)(a1 + 30) = 2;
  *(_BYTE *)(a1 + 31) = 2;
  *(_WORD *)(a1 + 36) = 4;
  *(_BYTE *)(a1 + 40) = 15;
  *(_WORD *)(a1 + 41) = 4;
  *(_BYTE *)(a1 + 43) = 0;
  *(_BYTE *)(a1 + 38) = 10;
  *(_BYTE *)(a1 + 39) = 10;
  *(_WORD *)(a1 + 44) = 20;
  *(_BYTE *)(a1 + 48) = 15;
  *(_WORD *)(a1 + 49) = 17664;
  *(_BYTE *)(a1 + 51) = 0;
  *(_BYTE *)(a1 + 46) = 1;
  *(_BYTE *)(a1 + 47) = 1;
  *(_WORD *)(a1 + 52) = 20;
  *(_BYTE *)(a1 + 56) = 15;
  *(_WORD *)(a1 + 57) = 17664;
  *(_BYTE *)(a1 + 59) = 0;
  *(_BYTE *)(a1 + 54) = 1;
  *(_BYTE *)(a1 + 55) = 1;
  *(_WORD *)(a1 + 60) = 13;
  *(_BYTE *)(a1 + 64) = 15;
  *(_WORD *)(a1 + 65) = 0;
  *(_BYTE *)(a1 + 67) = 0;
  *(_BYTE *)(a1 + 62) = 2;
  *(_BYTE *)(a1 + 63) = 2;
  sub_127712(a1 + 23, 3u);
  sub_127712(a1 + 23, 0xDu);
  sub_127712(a1 + 23, 1u);
  sub_127712(a1 + 23, 5u);
  sub_127712(a1 + 23, 0x19u);
  sub_127712(a1 + 23, 0x13u);
  sub_127712(a1 + 23, 0x15u);
  sub_127712(a1 + 23, 0x12u);
  sub_56726(9);
  *(_BYTE *)(a1 + 92) = 7;
  *(_WORD *)(a1 + 94) = 0;
  *(_BYTE *)(a1 + 93) = 9;
  JUMPOUT(0x55B09);
}
// 58083: control flows out of bounds to 55B09
// 192668: using guessed type int dword_192668;


//----- (00058088) --------------------------------------------------------
void __fastcall sub_58088( int a1)
{
  int v1; // ecx
  int16_t v2; // di
  int16_t v3; // dx
  int16_t v4; // ax
  int16_t v5; // si

  v1 = 129 * a1;
  v2 = *(char *)(v1 + dword_197F9C + 99);
  v3 = *(uint8_t *)(v1 + dword_197F9C + 22);
  sub_5685F(v2);
  if ( v3 == v4 )
  {
    v5 = *(uint8_t *)(v1 + dword_197F9C + 21);
    if ( v5 == (uint16_t)sub_5680D(v2) )
      sub_5679E(v2);
  }
  JUMPOUT(0x55B0C);
}
// 580F0: control flows out of bounds to 55B0C
// 580B6: variable 'v4' is possibly undefined
// 197F9C: using guessed type int dword_197F9C;


//----- (000580F5) --------------------------------------------------------
void sub_580F5()
{
  int16_t i; // dx
  int v1; // ecx
  int16_t v2; // ax
  int16_t j; // bx
  _BYTE *v4; // eax
  uint8_t v5; // dl
  int16_t v6; // cx
  int16_t v7; // si
  int16_t v8; // si
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // edx
  _WORD v13[10]; // [esp+0h] [ebp-14h]

  for ( i = 0; i < 8; ++i )
  {
    v1 = i;
    v2 = sub_56726(i);
    v13[v1] = v2;
  }
  for ( j = 0; j < word_199994; ++j )
  {
    v4 = (_BYTE *)(129 * j + dword_197F9C);
    if ( (char)v4[99] < 8 && !v4[100] && (uint8_t)v4[19] != v13[(char)v4[99]] )
    {
      v5 = v13[(char)v4[99]];
      v6 = byte_17FE90[46 * (uint8_t)v4[19] + (uint8_t)v4[16]];
      v7 = (uint8_t)v4[96];
      v4[19] = v5;
      v8 = v7 - v6;
      v9 = 46 * v5;
      v10 = (uint8_t)v4[16];
      v13[8] = v8;
      v4[96] = byte_17FE90[v9 + v10] + v8;
    }
    v11 = dword_197F9C + 129 * j;
    if ( *(char *)(v11 + 99) <= 8 )
    {
      if ( *(int16_t *)(v11 + 101) >= 72 )
        continue;
      if ( *(_BYTE *)(v11 + 100) )
        continue;
      v12 = *(int16_t *)(v11 + 101);
      if ( v12 <= -1
        || *(_BYTE *)(v11 + 17)
        || !(uint16_t)sub_1276F0(113 * v12 + dword_19306C + 56, *(char *)(v11 + 99)) )
      {
        continue;
      }
    }
    sub_581F3(j);
  }
  JUMPOUT(0x56807);
}
// 581EE: control flows out of bounds to 56807
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000581F3) --------------------------------------------------------
int __fastcall sub_581F3( int a1)
{
  int v2; // eax
  int v3; // ebx
  int v4; // ebx
  int v5; // eax
  int result; // eax
  int v7; // ebx

  v2 = 129 * a1;
  v3 = dword_197F9C;
  *(_WORD *)(dword_197F9C + v2 + 125) = 0;
  *(_BYTE *)(v3 + v2 + 111) = 0;
  *(_BYTE *)(v3 + v2 + 110) = 0;
  *(_BYTE *)(v3 + v2 + 112) = 0;
  *(_WORD *)(v3 + v2 + 123) = 0;
  v4 = 0;
  do
  {
    v5 = 8 * (int16_t)v4++ + dword_197F9C + 129 * a1;
    *(_BYTE *)(v5 + 31) = *(_BYTE *)(v5 + 30);
  }
  while ( (int16_t)v4 < 8 );
  result = 0;
  do
  {
    v7 = (int16_t)result++;
    *(_BYTE *)(129 * a1 + dword_197F9C + v7 + 118) = 0;
  }
  while ( (int16_t)result < 5 );
  return result;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (00058270) --------------------------------------------------------
void __fastcall sub_58270( int a1, int a2)
{
  _BOOL2 v4; // dx
  int16_t i; // ax

  v4 = 0;
  for ( i = 0; i < 8 && !v4; ++i )
    v4 = a2 == *(_WORD *)(dword_197F9C + 129 * a1 + 8 * i + 28);
  JUMPOUT(0x56580);
}
// 582BA: control flows out of bounds to 56580
// 197F9C: using guessed type int dword_197F9C;


//----- (000582BF) --------------------------------------------------------
int16_t __stdcall sub_582BF(
        int a1,
        int a2,
        int a3,
        int a4, unsigned int a5,
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
        int a25)
{
  int16_t v25; // cx
  int v26; // eax
  int v27; // ebx

  v25 = sub_1276F0((int)&a6 + 3, 0x1Bu);
  if ( byte_199CB4 )
  {
    LOWORD(v26) = word_180038[18 * a5];
  }
  else
  {
    v27 = word_180026[18 * a5];
    v26 = v27 + v27 * *(int16_t *)((char *)&word_17F642 + 15 * BYTE2(a6)) / 100;
    if ( v25 )
      LOWORD(v26) = 3 * v26;
  }
  return v26;
}
// 17F642: using guessed type int16_t word_17F642;
// 180026: using guessed type int16_t word_180026[];
// 180038: using guessed type int16_t word_180038[];
// 199CB4: using guessed type char byte_199CB4;


//----- (00058330) --------------------------------------------------------
int __fastcall sub_58330( int a1, int a2, int a3)
{
  int16_t v4; // ax
  int v5; // ebx
  int result; // eax

  sub_5685F(a3);
  v5 = word_180026[18 * a1];
  result = v5 + v5 * *(int16_t *)((char *)&word_17F642 + 15 * v4) / 100;
  if ( a2 )
    result *= 3;
  return result;
}
// 5833E: variable 'v4' is possibly undefined
// 17F642: using guessed type int16_t word_17F642;
// 180026: using guessed type int16_t word_180026[];


//----- (00058387) --------------------------------------------------------
int __fastcall sub_58387( int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // esi
  int v5; // eax
  _BYTE v7[100]; // [esp-64h] [ebp-70h] BYREF

  v4 = (_BYTE *)(129 * a1 + dword_197F9C);
  if ( (char)v4[99] <= 9 )
  {
    qmemcpy(v7, v4, 0x63u);
    LOWORD(v5) = sub_582BF(
                   *(int *)v7,
                   *(int *)&v7[4],
                   *(int *)&v7[8],
                   *(int *)&v7[12],
                   v7[16],
                   *(int *)&v7[20],
                   *(int *)&v7[24],
                   *(int *)&v7[28],
                   *(int *)&v7[32],
                   *(int *)&v7[36],
                   *(int *)&v7[40],
                   *(int *)&v7[44],
                   *(int *)&v7[48],
                   *(int *)&v7[52],
                   *(int *)&v7[56],
                   *(int *)&v7[60],
                   *(int *)&v7[64],
                   *(int *)&v7[68],
                   *(int *)&v7[72],
                   *(int *)&v7[76],
                   *(int *)&v7[80],
                   *(int *)&v7[84],
                   *(int *)&v7[88],
                   *(int *)&v7[92],
                   *(int *)&v7[96]);
    return v5;
  }
  else
  {
    switch ( v4[99] )
    {
      case 0xA:
        if ( v4[19] )
          return 750;
        else
          return 400;
      case 0xB:
        if ( v4[19] )
          goto LABEL_4;
        goto LABEL_5;
      case 0xC:
        if ( !v4[19] )
          goto LABEL_5;
LABEL_4:
        a4 = 2500;
        break;
      case 0xD:
        if ( v4[19] )
          return 1000;
        else
          return 300;
      case 0xE:
        if ( v4[19] )
          a4 = 1500;
        else
LABEL_5:
          a4 = 500;
        break;
      default:
        return a4;
    }
  }
  return a4;
}
// 5841D: variable 'v5' is possibly undefined
// 197F9C: using guessed type int dword_197F9C;


//----- (00058425) --------------------------------------------------------
int __fastcall sub_58425( int a1)
{
  int v1; // ebx
  int16_t v2; // si
  int16_t v3; // cx
  int v4; // ebx
  int result; // eax

  v1 = 129 * a1;
  v2 = *(int16_t *)((char *)&word_17F642 + 15 * *(uint8_t *)(v1 + dword_197F9C + 22));
  v3 = sub_1276F0(v1 + dword_197F9C + 23, 0xEu);
  v4 = word_180024[18 * *(uint8_t *)(v1 + dword_197F9C + 16)];
  result = v4 + v4 * v2 / 100;
  if ( v3 )
    result *= 3;
  return result;
}
// 17F642: using guessed type int16_t word_17F642;
// 180024: using guessed type int16_t word_180024[];
// 197F9C: using guessed type int dword_197F9C;


//----- (00058487) --------------------------------------------------------
void __fastcall sub_58487(int a1)
{
  sub_127776((_BYTE *)a1, 0x63u);
  strcpy((char *)a1, "Avenger");
  *(_BYTE *)(a1 + 17) = 0;
  *(_BYTE *)(a1 + 18) = 0;
  *(_BYTE *)(a1 + 21) = 5;
  *(_BYTE *)(a1 + 16) = 3;
  *(_BYTE *)(a1 + 22) = 6;
  *(_BYTE *)(a1 + 20) = 8;
  *(_BYTE *)(a1 + 19) = 6;
  *(_WORD *)(a1 + 28) = 4;
  *(_BYTE *)(a1 + 32) = 1;
  *(_WORD *)(a1 + 33) = 2;
  *(_BYTE *)(a1 + 35) = 0;
  *(_BYTE *)(a1 + 30) = 4;
  *(_BYTE *)(a1 + 31) = 4;
  *(_WORD *)(a1 + 36) = 11;
  *(_BYTE *)(a1 + 40) = 1;
  *(_WORD *)(a1 + 41) = 2;
  *(_BYTE *)(a1 + 43) = 0;
  *(_BYTE *)(a1 + 38) = 2;
  *(_BYTE *)(a1 + 39) = 2;
  *(_WORD *)(a1 + 44) = 4;
  *(_BYTE *)(a1 + 48) = 1;
  *(_WORD *)(a1 + 49) = 0;
  *(_BYTE *)(a1 + 51) = 0;
  *(_BYTE *)(a1 + 46) = 10;
  *(_BYTE *)(a1 + 47) = 10;
  *(_WORD *)(a1 + 52) = 13;
  *(_BYTE *)(a1 + 56) = 15;
  *(_WORD *)(a1 + 57) = 0;
  *(_BYTE *)(a1 + 59) = 0;
  *(_BYTE *)(a1 + 54) = 2;
  *(_BYTE *)(a1 + 55) = 2;
  *(_WORD *)(a1 + 60) = 4;
  *(_BYTE *)(a1 + 64) = 1;
  *(_WORD *)(a1 + 65) = 4;
  *(_BYTE *)(a1 + 67) = 0;
  *(_BYTE *)(a1 + 62) = 10;
  *(_BYTE *)(a1 + 63) = 10;
  *(_WORD *)(a1 + 68) = 24;
  *(_BYTE *)(a1 + 72) = 1;
  *(_WORD *)(a1 + 73) = 0;
  *(_BYTE *)(a1 + 75) = 10;
  *(_BYTE *)(a1 + 70) = 15;
  *(_BYTE *)(a1 + 71) = 15;
  sub_127712(a1 + 23, 7u);
  sub_127712(a1 + 23, 0x18u);
  sub_127712(a1 + 23, 0x21u);
  *(_BYTE *)(a1 + 92) = 44;
  *(_BYTE *)(a1 + 93) = 8;
  *(_WORD *)(a1 + 94) = 500;
  JUMPOUT(0x55B09);
}
// 585BF: control flows out of bounds to 55B09


//----- (000585E0) --------------------------------------------------------
int __fastcall sub_585E0( int a1, int a2)
{
  int v2; // edx
  int v3; // ebx
  int result; // eax

  if ( a1 >= 8 )
  {
    switch ( a1 )
    {
      case 8:
        v2 = 413;
        goto LABEL_5;
      case 9:
        v2 = 419;
        goto LABEL_5;
      case 10:
        v2 = 417;
        goto LABEL_5;
      case 11:
        v2 = 416;
        goto LABEL_5;
      case 12:
        v2 = 414;
        goto LABEL_5;
      case 13:
        v2 = 415;
        goto LABEL_5;
      case 14:
        v2 = 418;
LABEL_5:
        v3 = dword_193174;
        goto LABEL_6;
      default:
        goto LABEL_7;
    }
  }
  v2 = 50 * *(uint8_t *)(dword_197F98 + 3753 * a1 + 38) + 49;
  v3 = dword_193174;
LABEL_6:
  a2 = sub_127C27((int)aShipsLbx, v2, v3);
LABEL_7:
  sub_12B79D(a2);
  result = sub_131F7B();
  byte_199F38 = 1;
  return result;
}
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;
// 199F38: using guessed type char byte_199F38;


//----- (00058678) --------------------------------------------------------
int __fastcall sub_58678( int a1)
{
  return sub_5869B(*(char *)(dword_197F9C + 129 * a1 + 93), *(char *)(dword_197F9C + 129 * a1 + 92));
}
// 197F9C: using guessed type int dword_197F9C;


//----- (00058697) --------------------------------------------------------
int __fastcall sub_58697( int a1, int a2)
{
  return sub_5869B(a1, a2);
}
// 5869B: using guessed type int __fastcall sub_5869B(_DWORD, _DWORD);


//----- (0005869B) --------------------------------------------------------
int __fastcall sub_5869B( int a1, int a2)
{
  uint8_t v2; // al
  int v3; // eax

  if ( a1 < 8 )
    v2 = *(_BYTE *)(dword_197F98 + 3753 * a1 + 38);
  else
    v2 = 8;
  v3 = sub_127C27((int)aShipsLbx, 50 * v2 + a2, dword_193174);
  return nullsub_3(v3);
}
// 586D3: using guessed type int __fastcall nullsub_3(_DWORD);
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;


//----- (000586D4) --------------------------------------------------------
int __fastcall sub_586D4(uint16_t *a1, int a2)
{
  uint16_t *v3; // ebx
  unsigned int v4; // eax
  int i; // edi
  _WORD *v6; // ebx
  int j; // edi
  int result; // eax
  signed int v9; // ebx

LABEL_1:
  v3 = a1;
  v4 = 0;
  for ( i = 0; i < a2; ++i )
  {
    v4 += *v3;
    if ( v4 >= 0x200 )
    {
      v6 = a1;
      for ( j = 0; j < a2; ++j )
      {
        *v6 = (uint16_t)*v6 / 2;
        ++v6;
      }
      goto LABEL_1;
    }
    ++v3;
  }
  if ( !v4 )
    return 0;
  v9 = sub_1247A0(v4) - *a1;
  for ( result = 0; v9 > 0 && result < a2 - 1; ++result )
    v9 -= *++a1;
  return result;
}


//----- (0005874B) --------------------------------------------------------
int __fastcall sub_5874B(_DWORD *a1, int a2)
{
  _DWORD *v4; // ebx
  signed int v5; // eax
  int i; // edx
  int *v7; // ebx
  int j; // edi
  signed int v10; // ebx
  int k; // eax

LABEL_1:
  v4 = a1;
  v5 = 0;
  for ( i = 0; i < a2; ++i )
  {
    v5 += *v4;
    if ( v5 >= 512 )
    {
      v7 = a1;
      for ( j = 0; j < a2; ++j )
        *v7++ /= 2;
      goto LABEL_1;
    }
    ++v4;
  }
  if ( v5 )
  {
    v10 = sub_1247A0(v5);
    for ( k = 0; ; ++k )
    {
      v10 -= *a1;
      if ( v10 <= 0 || k >= a2 - 1 )
        break;
      ++a1;
    }
    JUMPOUT(0x58746);
  }
  return 0;
}
// 587A3: control flows out of bounds to 58746


//----- (000587B3) --------------------------------------------------------
int __fastcall sub_587B3(uint16_t *a1, int a2, int a3)
{
  _WORD *v6; // edx
  int i; // ebx
  int v8; // edx
  uint16_t *v9; // eax
  int v10; // edi
  int v11; // ebx

  v6 = a1;
  for ( i = 0; i < a2; ++i )
  {
    if ( *v6 )
      *v6 += sub_1247A0(a3);
    ++v6;
  }
  v8 = 1;
  v9 = a1 + 1;
  v10 = *a1;
  v11 = 0;
  while ( v8 < a2 )
  {
    if ( *v9 > v10 )
    {
      v11 = v8;
      v10 = *v9;
    }
    ++v9;
    ++v8;
  }
  return v11;
}


//----- (00058807) --------------------------------------------------------
void __fastcall sub_58807(_DWORD *a1, int a2, int a3)
{
  _DWORD *v6; // edx
  int i; // ebx
  int v8; // edx
  int *v9; // eax
  int v10; // edi

  v6 = a1;
  for ( i = 0; i < a2; ++i )
  {
    if ( *v6 )
      *v6 += sub_1247A0(a3);
    ++v6;
  }
  v8 = 1;
  v9 = a1 + 1;
  v10 = *a1;
  while ( v8 < a2 )
  {
    if ( v10 < *v9 )
      v10 = *v9;
    ++v9;
    ++v8;
  }
  JUMPOUT(0x58801);
}
// 58851: control flows out of bounds to 58801


//----- (00058853) --------------------------------------------------------
_WORD *__fastcall sub_58853( int a1, int a2, int16_t *a3)
{
  int16_t v3; // si
  int16_t i; // dx
  int16_t v5; // ax
  int16_t v6; // ax
  int16_t j; // dx
  int16_t v8; // ax
  _WORD *result; // eax
  int v12; // [esp+8h] [ebp-14h]
  int16_t v13; // [esp+Ch] [ebp-10h]
  int16_t v14; // [esp+10h] [ebp-Ch]
  int16_t v15; // [esp+14h] [ebp-8h]
  int16_t v16; // [esp+18h] [ebp-4h]

  v16 = 0;
  v3 = 3;
  *a3 = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    v5 = sub_5679E(i);
    if ( v5 > v16 )
      v16 = v5;
    sub_568EB(i);
    if ( word_17F819[14 * v6] > word_17F819[14 * v3] )
      v3 = v6;
  }
  v15 = *(int16_t *)((char *)&word_17F6A7 + 59 * v16);
  if ( *(int16_t *)((char *)&word_17E07F + 13 * word_17F80D[14 * v3]) == 74 )
    v3 = 10;
  v14 = 200;
  for ( j = 1; j < 40; ++j )
  {
    if ( !byte_17F80F[28 * j] )
    {
      v12 = word_17F80D[14 * j];
      if ( *(int16_t *)((char *)&word_17E07F + 13 * v12) != 74 )
      {
        v8 = word_17F819[14 * j] - word_17F819[14 * v3];
        if ( v8 >= 0 && v8 <= v14 && v8 <= 50 && *(_BYTE *)(v12 + dword_197F98 + 3753 * a1 + 279) != 3 )
        {
          v13 = j;
          if ( j == v3 )
            v14 = 1;
          else
            v14 = word_17F819[14 * j] - word_17F819[14 * v3];
        }
      }
    }
  }
  if ( v14 < 200 )
    *(_WORD *)(a2 + 2 * (*a3)++) = word_17F80D[14 * v13];
  result = (_WORD *)v15;
  if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + v15 + 279) != 3 )
  {
    result = (_WORD *)(a2 + 2 * *a3);
    *result = v15;
    ++*a3;
  }
  return result;
}
// 5888C: variable 'v6' is possibly undefined
// 58985: variable 'v13' is possibly undefined
// 17E07F: using guessed type int16_t word_17E07F;
// 17F6A7: using guessed type int16_t word_17F6A7;
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F819: using guessed type int16_t word_17F819[];
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000589D6) --------------------------------------------------------
int sub_589D6()
{
  int v0; // edi
  int i; // ebx
  signed int v2; // eax
  int v3; // ecx
  int v4; // eax
  signed int v5; // esi
  int j; // eax
  int k; // ecx
  int v8; // eax
  unsigned int v9; // eax
  char v10; // cl
  int v11; // eax
  int m; // esi
  int v13; // eax
  signed int v14; // esi
  int n; // eax
  int ii; // ecx
  int v17; // eax
  unsigned int v18; // eax
  char v19; // cl
  int v20; // eax
  int jj; // esi
  signed int v22; // esi
  int kk; // eax
  int mm; // ecx
  int v25; // eax
  unsigned int v26; // eax
  char v27; // cl
  int v28; // eax
  int nn; // esi
  int result; // eax
  int v31; // [esp+0h] [ebp-68h]
  _DWORD v32[9]; // [esp+4h] [ebp-64h]
  int v33; // [esp+28h] [ebp-40h]
  int v34; // [esp+2Ch] [ebp-3Ch]
  int v35; // [esp+30h] [ebp-38h]
  int v36; // [esp+34h] [ebp-34h]
  int v37; // [esp+38h] [ebp-30h]
  int v38; // [esp+3Ch] [ebp-2Ch]
  int v39; // [esp+40h] [ebp-28h]
  _BYTE v40[4]; // [esp+4Ch] [ebp-1Ch]
  int v41; // [esp+50h] [ebp-18h]
  int v42; // [esp+54h] [ebp-14h]
  int v43; // [esp+58h] [ebp-10h]
  int v44; // [esp+5Ch] [ebp-Ch]
  int v45; // [esp+60h] [ebp-8h]
  int v46; // [esp+64h] [ebp-4h]
  _DWORD savedregs[6]; // [esp+68h] [ebp+0h] BYREF

  v0 = 0;
  for ( i = 0; ; *(_BYTE *)(i + dword_197F98 - 3235) = v27 )
  {
    result = word_199998;
    if ( v0 >= word_199998 )
      break;
    v2 = sub_1247A0(0xAu) + 1 - (uint8_t)byte_199CB0;
    v3 = v2;
    if ( v2 >= 0 )
    {
      if ( v2 > 9 )
        v3 = 9;
    }
    else
    {
      v3 = 0;
    }
    v4 = dword_197F98;
    *(_BYTE *)(i + dword_197F98 + 39) = byte_181090[10 * *(uint8_t *)(i + dword_197F98 + 37) + v3];
    v41 = 1;
    v42 = 2;
    v43 = 1;
    v44 = 2;
    v45 = 2;
    v46 = 1;
    v32[0] = 1;
    v31 = 2;
    v32[1] = 2;
    v32[2] = 1;
    v33 = 2;
    v34 = 2;
    v35 = 1;
    v36 = 2;
    v37 = 1;
    v38 = 2;
    v39 = 3;
    if ( *(_BYTE *)(i + v4 + 2208) == 50 )
    {
      v46 = 11;
      v43 = 11;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2208) == 100 )
    {
      v46 += 100;
      v43 += 100;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2209) == 1 )
    {
      v46 += 3;
      v45 += 3;
      v44 += 3;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2209) == 2 )
    {
      v46 += 100;
      v45 += 100;
      v44 += 100;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2210) == 1 )
    {
      v46 += 3;
      v45 += 3;
      v44 += 3;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2210) == 2 )
    {
      v46 += 10;
      v45 += 10;
      v44 += 10;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2211) == 1 )
    {
      v45 += 3;
      v44 += 10;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2211) == 2 )
    {
      v45 += 10;
      v44 += 100;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2213) == 20 )
    {
      v42 += 10;
      v36 += 100;
      v32[0] += 10;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2213) == 40 )
    {
      v42 += 100;
      v36 += 1000;
      v32[0] += 100;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2214) == 25 )
    {
      v42 += 10;
      v37 += 3;
      v31 += 100;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2214) == 50 )
    {
      v42 += 100;
      v37 += 10;
      v31 += 1000;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2215) == 10 )
    {
      v43 += 10;
      v34 += 100;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2215) == 20 )
    {
      v43 += 100;
      v34 += 1000;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2216) == 10 )
      v41 += 3;
    if ( *(_BYTE *)(i + dword_197F98 + 2216) == 20 )
      v41 += 10;
    if ( *(_BYTE *)(i + dword_197F98 + 2217) == 1 )
    {
      v45 += 10;
      v46 += 3;
      v44 += 3;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2218) == 1 )
    {
      v43 += 10;
      v34 += 1000;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2219) == 1 )
    {
      v45 += 3;
      v46 += 3;
      v44 += 3;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2220) == 1 )
    {
      v45 += 10;
      v46 += 3;
      v44 += 3;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2221) == 1 )
    {
      v45 += 3;
      v46 += 10;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2222) == 1 )
      v45 += 10;
    if ( *(_BYTE *)(i + dword_197F98 + 2224) == 1 )
    {
      v45 += 3;
      v38 += 1000;
      v31 += 10;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2225) == 1 )
    {
      v45 += 3;
      v43 += 10;
      v44 += 3;
    }
    if ( *(_BYTE *)(i + dword_197F98 + 2227) == 1 )
      v41 += 100;
    if ( *(_BYTE *)(i + dword_197F98 + 2229) == 1 )
      v44 += 1000;
    if ( *(_BYTE *)(i + dword_197F98 + 2230) == 1 )
      v45 += 100;
    if ( *(_BYTE *)(i + dword_197F98 + 2231) == 1 )
      v41 += 100;
    if ( *(_BYTE *)(i + dword_197F98 + 2235) == 1 )
      v42 += 100;
    if ( *(_BYTE *)(i + dword_197F98 + 2237) == 1 )
      v43 += 10;
    if ( *(_BYTE *)(i + dword_197F98 + 2236) == 1 )
    {
      v43 += 10;
      v42 += 13;
      v36 += 100;
    }
    if ( byte_199CB0 == 3 )
    {
      v45 += 3;
      v43 += 3;
      v44 += 3;
    }
    if ( byte_199CB0 == 4 )
    {
      v45 += 10;
      v43 += 10;
      v44 += 10;
    }
    if ( !*(_BYTE *)(i + dword_197F98 + 39) )
      v35 += 3;
    v5 = 0;
    for ( j = 0; j != 24; v5 += *(_DWORD *)&v40[j] )
      j += 4;
    while ( v5 > 1000 )
    {
      v5 = 0;
      for ( k = 0; k < 24; *(_DWORD *)&v40[k] = v8 )
      {
        v8 = *(int *)((char *)&v41 + k) / 2;
        k += 4;
        v5 += v8;
      }
    }
    v9 = sub_1247A0(v5);
    v10 = 0;
    v11 = v9 - v41;
    for ( m = 0; v11 > 0 && m < 24; m += 4 )
    {
      ++v10;
      v11 -= *(int *)((char *)&v42 + m);
    }
    v13 = i + dword_197F98;
    if ( *(_BYTE *)(i + dword_197F98 + 40) == 100 )
      *(_BYTE *)(v13 + 40) = 100;
    else
      *(_BYTE *)(v13 + 40) = v10;
    v14 = 0;
    for ( n = 0; n != 4; v14 += savedregs[n - 27] )
      ++n;
    while ( v14 > 1000 )
    {
      v14 = 0;
      for ( ii = 0; ii < 4; savedregs[ii - 27] = v17 )
      {
        v17 = v32[ii++ - 1] / 2;
        v14 += v17;
      }
    }
    v18 = sub_1247A0(v14);
    v19 = 0;
    v20 = v18 - v31;
    for ( jj = 0; v20 > 0 && jj < 4; ++jj )
    {
      ++v19;
      v20 -= v32[jj];
    }
    v22 = 0;
    *(_BYTE *)(i + dword_197F98 + 517) = v19;
    for ( kk = 0; kk != 7; v22 += v32[kk + 8] )
      ++kk;
    while ( v22 > 1000 )
    {
      v22 = 0;
      for ( mm = 0; mm < 7; v32[mm + 8] = v25 )
      {
        v25 = *(int *)((char *)&v33 + mm * 4) / 2;
        ++mm;
        v22 += v25;
      }
    }
    v26 = sub_1247A0(v22);
    v27 = 0;
    v28 = v26 - v33;
    for ( nn = 0; v28 > 0 && nn < 28; nn += 4 )
    {
      ++v27;
      v28 -= *(int *)((char *)&v34 + nn);
    }
    i += 3753;
    ++v0;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (00058F1E) --------------------------------------------------------
char __fastcall sub_58F1E(int a1, char *a2, int a3)
{
  int v3; // ecx
  int v5; // edx
  char *v6; // eax

  v3 = a3;
  if ( a1 < 80 )
  {
    v5 = (int16_t)a1;
    v6 = aKentextLbx;
  }
  else
  {
    v5 = (int16_t)(a1 - 80);
    v6 = aKentext1Lbx;
  }
  return sub_249F9(v6, v5, a2, v3);
}


//----- (00058F4A) --------------------------------------------------------
int __fastcall sub_58F4A( int a1)
{
  int v1; // ebx
  int v2; // eax
  int v3; // ecx

  v1 = 3753 * a1;
  dword_19B710 = (int)sub_126B42((int)aRacestufLbx_2, 6, dword_192ED4);
  sub_5B4CD((char *)(v1 + dword_197F98 + 2207));
  sub_59053(v2, 6, v1);
  v3 = 100;
  if ( *(_BYTE *)(v1 + dword_197F98 + 341) == 3 )
    word_19B766 += 4;
  if ( word_19B766 > 0 )
    return 10 * word_19B766 + 100;
  return v3;
}
// 58F84: variable 'v2' is possibly undefined
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 19B710: using guessed type int dword_19B710;
// 19B766: using guessed type int16_t word_19B766;


//----- (00058FC3) --------------------------------------------------------
int __usercall sub_58FC3(int16_t *a1)
{
  int v1; // ebx
  int v2; // ebx
  int v3; // ebx
  int v4; // ebx

  sub_1112EC(dword_192ED4, 1);
  v1 = dword_192ED4;
  dword_19B70C = (int)sub_126B42((int)aRaceoptLbx_0, 1, dword_192ED4);
  sub_FE8BE(dword_19B70C, 2, v1, a1);
  v2 = dword_192ED4;
  dword_19B690 = (int)sub_126B42((int)aRaceoptLbx_0, 2, dword_192ED4);
  sub_FE8BE(dword_19B690, 3, v2, a1);
  v3 = dword_192ED4;
  dword_19B6D4 = (int)sub_126B42((int)aRaceoptLbx_0, 3, dword_192ED4);
  sub_FE8BE(dword_19B6D4, 5, v3, a1);
  v4 = dword_192ED4;
  dword_19B6D8 = (int)sub_126B42((int)aRaceoptLbx_0, 5, dword_192ED4);
  sub_FE8BE(dword_19B6D8, 5, v4, a1);
  return sub_5AEF4();
}
// 192ED4: using guessed type int dword_192ED4;
// 19B690: using guessed type int dword_19B690;
// 19B6D4: using guessed type int dword_19B6D4;
// 19B6D8: using guessed type int dword_19B6D8;
// 19B70C: using guessed type int dword_19B70C;


//----- (00059053) --------------------------------------------------------
void __fastcall sub_59053(int a1, int a2, int a3)
{
  int16_t v3; // si
  int16_t v4; // dx
  int v5; // eax
  int16_t v6; // di
  int v7; // ecx
  int16_t v8; // dx
  int16_t v9; // bx
  int16_t v10; // dx
  int16_t v11; // di

  sub_F4D53();
  v3 = 0;
  v4 = 0;
  while ( 1 )
  {
    if ( word_19B694[v4] )
    {
      v5 = word_19B694[v4] + 3 * v4;
      v6 = *(char *)(dword_19B710 + v5 - 1);
      a3 -= v6;
      if ( *(char *)(dword_19B710 + v5 - 1) < 0 )
        v3 += v6;
    }
    if ( ++v4 >= 9 )
    {
      v7 = word_19B694[v4];
      v8 = *(char *)(v7 + dword_19B710 + 27);
      v9 = a3 - v8;
      if ( *(char *)(v7 + dword_19B710 + 27) < 0 )
        v3 += v8;
      v10 = 0;
      while ( 1 )
      {
        if ( word_19B6DC[v10] == 1 )
        {
          v11 = *(char *)(v10 + dword_19B710 + 31);
          v9 -= v11;
          if ( *(char *)(v10 + dword_19B710 + 31) < 0 )
            v3 += v11;
        }
        if ( ++v10 >= 22 )
        {
          word_19B76C = v3;
          word_19B766 = v9;
          JUMPOUT(0x5969F);
        }
      }
    }
  }
}
// 59100: control flows out of bounds to 5969F
// 19B694: using guessed type int16_t word_19B694[];
// 19B6DC: using guessed type int16_t word_19B6DC[];
// 19B710: using guessed type int dword_19B710;
// 19B766: using guessed type int16_t word_19B766;
// 19B76C: using guessed type int16_t word_19B76C;


//----- (00059105) --------------------------------------------------------
int sub_59105()
{
  int v0; // ecx
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // ecx
  int v5; // ebx
  int16_t v6; // dx
  int16_t v7; // ax
  char *v8; // edi
  int v9; // edi
  int v10; // esi
  int v11; // edx
  int16_t v12; // ax
  int v13; // eax
  int v14; // esi
  int16_t v15; // di
  int16_t v16; // ax
  int16_t v17; // dx
  int16_t v18; // ax
  int v19; // ebx
  int16_t v20; // dx
  int16_t v21; // ax
  int v22; // ecx
  int16_t v23; // dx
  int v24; // edx
  int16_t v25; // di
  int16_t v26; // di
  int16_t v27; // ax
  int v28; // edi
  int v29; // esi
  int16_t v30; // dx
  int16_t v31; // ax
  int v32; // ebx
  int16_t v33; // ax
  int v34; // ecx
  int v35; // edx
  int16_t v36; // si
  int16_t v37; // si
  int16_t v38; // di
  int16_t v39; // di
  int v40; // esi
  int16_t v41; // dx
  int v42; // ebx
  int16_t v43; // ax
  char *v45; // [esp-4h] [ebp-3Ah] BYREF
  char v46[80]; // [esp+0h] [ebp-36h] BYREF
  int v47; // [esp+50h] [ebp+1Ah]
  int16_t v48; // [esp+54h] [ebp+1Eh]
  int16_t v49; // [esp+56h] [ebp+20h]
  int16_t v50; // [esp+58h] [ebp+22h]
  char v51[12]; // [esp+5Ch] [ebp+26h] BYREF
  _BYTE v52[8]; // [esp+68h] [ebp+32h]
  int16_t v53; // [esp+70h] [ebp+3Ah]
  _WORD v54[3]; // [esp+72h] [ebp+3Ch]
  _BYTE v55[8]; // [esp+78h] [ebp+42h] BYREF
  int v56; // [esp+80h] [ebp+4Ah]
  int v57; // [esp+84h] [ebp+4Eh]
  int v58; // [esp+88h] [ebp+52h]
  int v59; // [esp+8Ch] [ebp+56h]
  int v60; // [esp+90h] [ebp+5Ah]
  int i; // [esp+94h] [ebp+5Eh]
  int v62; // [esp+98h] [ebp+62h]
  int v63; // [esp+9Ch] [ebp+66h]
  int v64; // [esp+A0h] [ebp+6Ah]
  int v65; // [esp+A4h] [ebp+6Eh]
  int v66; // [esp+A8h] [ebp+72h]
  int v67; // [esp+ACh] [ebp+76h]
  int v68; // [esp+B0h] [ebp+7Ah]
  int v69; // [esp+B4h] [ebp+7Eh]

  v53 = 80;
  v54[0] = 254;
  v54[1] = 442;
  v54[2] = 643;
  v47 = 9633864;
  v48 = 222;
  v49 = 297;
  v50 = 372;
  v58 = 22;
  v52[0] = -119;
  v55[0] = -111;
  v0 = 1;
  do
  {
    v1 = (int16_t)v0++;
    v52[v1] = -111;
    v55[v1] = -107;
  }
  while ( (int16_t)v0 < 8 );
  v2 = sub_127C27((int)aRaceoptLbx_0, 4, dword_193174);
  v69 = 0;
  sub_12A478(0, 0, v2);
  v68 = 0;
  v3 = sub_127C27((int)aPatch13Lbx_0, 0, dword_193174);
  v4 = 0;
  sub_12A478(131, 0, v3);
  while ( (int16_t)v4 < 36 )
  {
    sub_120CCB(4, (int)&byte_19B688);
    sub_120DED(119, 0);
    v5 = dword_19B588[(int16_t)v4];
    v6 = *((_WORD *)&v47 + (int16_t)v68) - 22;
    v7 = v54[(int16_t)v69 - 1] - 22;
    v66 = 0;
    ++v4;
    sub_1212B3(v7, v6, v5);
    do
    {
      if ( word_19B714[(int16_t)v4] > 0 )
      {
        sub_12B753(dword_19B70C, 0);
        sub_12A478(v54[(int16_t)v69 - 1] - 20, v66 + *((_WORD *)&v47 + (int16_t)v68), dword_19B70C);
      }
      sub_120CCB(2, (int)v55);
      v46[0] = byte_178F21;
      v56 = (int16_t)v4;
      itoa(
        *(char *)(dword_19B710
                + (int16_t)v4
                - (((int16_t)v4 + 3 - (__CFSHL__(((int16_t)v4 + 3) >> 31, 2) + 4 * (((int16_t)v4 + 3) >> 31))) >> 2)),
        v51,
        10,
        v4);
      v45 = v46;
      v8 = (char *)&v45 + 3;
      do
        ++v8;
      while ( *v8 );
      strcpy(v8, v51);
      v9 = v56;
      v10 = (int16_t)v69;
      v11 = (int16_t)(v66 + *((_WORD *)&v47 + (int16_t)v68));
      sub_1212B3(v54[(int16_t)v69 - 1], v11, dword_19B588[v56]);
      v12 = sub_12066F(dword_19B588[v9]);
      LOWORD(v11) = v54[v10];
      LOWORD(v9) = v54[v10 - 1] + v12;
      v13 = sub_12066F((int)v46);
      v14 = (int16_t)v68;
      v15 = v9 - 1;
      v60 = v11 - 50 - v13;
      for ( i = v66; ; sub_1212B3(v16, i + *((_WORD *)&v47 + v14), (int)asc_178F22) )
      {
        v16 = v15;
        if ( v15 >= (int16_t)v60 - 4 )
          break;
        v15 += 4;
      }
      v17 = i + *((_WORD *)&v47 + (int16_t)v68);
      v18 = v54[(int16_t)v69] - 50;
      v66 += 13;
      ++v4;
      sub_1210B7(v18, v17, (int)v46);
    }
    while ( (_WORD)v66 != 39 );
    if ( (int16_t)++v68 >= 5 )
    {
      v68 = 0;
      ++v69;
    }
  }
  sub_120CCB(4, (int)&byte_19B688);
  sub_120DED(119, 0);
  v19 = dword_19B588[(int16_t)v4];
  v20 = *((_WORD *)&v47 + (int16_t)v68) - 22;
  v21 = v54[(int16_t)v69 - 1] - 22;
  v65 = 0;
  v22 = v4 + 1;
  sub_1212B3(v21, v20, v19);
  do
  {
    sub_12B753(dword_19B70C, 0);
    v23 = v65 + *((_WORD *)&v47 + (int16_t)v68);
    v56 = 2 * (int16_t)v69;
    sub_12A478(*(_WORD *)((char *)&v54[-1] + v56) - 20, v23, dword_19B70C);
    sub_120CCB(2, (int)v55);
    v57 = (int16_t)v22;
    itoa(
      *(char *)(dword_19B710
              + (int16_t)v22
              - (((int16_t)v22 + 3 - (__CFSHL__(((int16_t)v22 + 3) >> 31, 2) + 4 * (((int16_t)v22 + 3) >> 31))) >> 2)),
      v51,
      10,
      v22);
    v45 = v46;
    strcpy(v46, v51);
    v24 = v56;
    v25 = *(_WORD *)((char *)&v54[-1] + v24) + sub_12066F(dword_19B588[v57]);
    LOWORD(v24) = *(_WORD *)((char *)v54 + v24);
    v26 = v25 - 1;
    v59 = v24 - 50 - sub_12066F((int)v46);
    v62 = v65;
    while ( v26 < (int16_t)v59 - 4 )
    {
      v27 = v26;
      v26 += 4;
      sub_1212B3(v27, v62 + *((_WORD *)&v47 + (int16_t)v68), (int)asc_178F22);
    }
    v28 = (int16_t)v68;
    v29 = (int16_t)v69;
    sub_1212B3(v54[(int16_t)v69 - 1], v62 + *((_WORD *)&v47 + (int16_t)v68), dword_19B588[(int16_t)v22]);
    v30 = v62 + *((_WORD *)&v47 + v28);
    v31 = v54[v29];
    v65 += 13;
    ++v22;
    sub_1210B7(v31 - 50, v30, (int)v46);
  }
  while ( (_WORD)v65 != 52 );
  sub_120CCB(4, (int)&byte_19B688);
  sub_120DED(119, 0);
  v32 = dword_19B588[(int16_t)v22];
  v33 = v54[(int16_t)++v69 - 1] - 22;
  v63 = 0;
  sub_1212B3(v33, v47 - 22, v32);
  v34 = v22 + 1;
  v67 = v47;
  while ( (int16_t)v34 < 64 )
  {
    v64 = 0;
    while ( (int16_t)v64 < *((int16_t *)&v58 + (int16_t)v63) )
    {
      sub_12B753(dword_19B70C, 0);
      v57 = 2 * (int16_t)v69;
      sub_12A478(*(_WORD *)((char *)&v54[-1] + v57) - 20, v67, dword_19B70C);
      sub_120CCB(2, (int)v55);
      v56 = (int16_t)v34;
      itoa(*(char *)((int16_t)v34 + dword_19B710 - 11), v51, 10, v34);
      v45 = v46;
      strcpy(v46, v51);
      v35 = v57;
      v36 = *(_WORD *)((char *)&v54[-1] + v35) + sub_12066F(dword_19B588[v56]);
      LOWORD(v35) = *(_WORD *)((char *)v54 + v35);
      v37 = v36 - 1;
      v38 = v35 - 50 - sub_12066F((int)v46);
      while ( v37 < v38 - 4 )
      {
        sub_1212B3(v37, v67, (int)asc_178F22);
        v37 += 4;
      }
      v39 = v67;
      v40 = (int16_t)v69;
      ++v64;
      v41 = v67;
      v42 = dword_19B588[(int16_t)v34];
      v43 = v54[(int16_t)v69 - 1];
      v67 += 16;
      sub_1212B3(v43, v41, v42);
      ++v34;
      sub_1210B7(v54[v40] - 50, v39, (int)v46);
    }
    v67 += 9;
    ++v63;
  }
  return sub_120CCB(4, (int)&byte_19B688);
}
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 178F21: using guessed type char byte_178F21;
// 193174: using guessed type int dword_193174;
// 19B588: using guessed type int dword_19B588[64];
// 19B688: using guessed type char byte_19B688;
// 19B70C: using guessed type int dword_19B70C;
// 19B710: using guessed type int dword_19B710;
// 19B714: using guessed type int16_t word_19B714[41];


//----- (000596A5) --------------------------------------------------------
void sub_596A5()
{
  int v0; // ecx
  int v1; // eax
  int16_t v2; // ax
  char *v3; // ebx
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int16_t v8; // di
  int16_t v9; // dx
  int16_t v10; // ax
  char *v11; // edx
  char *v12; // edi
  int v13; // edi
  int v14; // esi
  int v15; // edx
  int16_t v16; // ax
  int16_t v17; // di
  int16_t v18; // ax
  int v19; // ecx
  int v20; // eax
  char *v21; // ebx
  int16_t v22; // dx
  int16_t v23; // ax
  int v24; // ebx
  char *v25; // edx
  char *v26; // edx
  int v27; // esi
  int16_t v28; // ax
  int16_t v29; // di
  int v30; // eax
  int v31; // esi
  int16_t v32; // di
  int16_t v33; // ax
  int v34; // esi
  int v35; // edi
  int v36; // ecx
  int v37; // esi
  int16_t v38; // dx
  int16_t v39; // ax
  int v40; // ebx
  char *v41; // eax
  char *v42; // edx
  int v43; // esi
  int16_t v44; // ax
  int16_t v45; // dx
  int16_t v46; // di
  int16_t v47; // si
  int16_t v48; // di
  int v49; // esi
  char *v50; // [esp-4h] [ebp-46h] BYREF
  char v51[80]; // [esp+0h] [ebp-42h] BYREF
  char v52[12]; // [esp+50h] [ebp+Eh] BYREF
  int v53; // [esp+5Ch] [ebp+1Ah]
  int16_t v54; // [esp+60h] [ebp+1Eh]
  int16_t v55; // [esp+62h] [ebp+20h]
  int16_t v56; // [esp+64h] [ebp+22h]
  _BYTE v57[8]; // [esp+68h] [ebp+26h] BYREF
  int16_t v58; // [esp+70h] [ebp+2Eh]
  _WORD v59[3]; // [esp+72h] [ebp+30h]
  _BYTE v60[8]; // [esp+78h] [ebp+36h]
  int v61; // [esp+80h] [ebp+3Eh]
  char *v62; // [esp+84h] [ebp+42h]
  int v63; // [esp+88h] [ebp+46h]
  int v64; // [esp+8Ch] [ebp+4Ah]
  int v65; // [esp+90h] [ebp+4Eh]
  char *v66; // [esp+94h] [ebp+52h]
  int v67; // [esp+98h] [ebp+56h]
  int v68; // [esp+9Ch] [ebp+5Ah]
  int v69; // [esp+A0h] [ebp+5Eh]
  int v70; // [esp+A4h] [ebp+62h]
  int v71; // [esp+A8h] [ebp+66h]
  int v72; // [esp+ACh] [ebp+6Ah]
  int v73; // [esp+B0h] [ebp+6Eh]
  int v74; // [esp+B4h] [ebp+72h]
  int v75; // [esp+B8h] [ebp+76h]
  int v76; // [esp+BCh] [ebp+7Ah]
  int i; // [esp+C0h] [ebp+7Eh]

  v58 = 80;
  v59[0] = 254;
  v59[1] = 442;
  v59[2] = 643;
  v53 = 9633864;
  v54 = 222;
  v55 = 297;
  v56 = 372;
  v76 = 22;
  v57[0] = -119;
  v60[0] = -111;
  v0 = 1;
  do
  {
    v1 = (int16_t)v0++;
    v57[v1] = -111;
    v60[v1] = -107;
  }
  while ( (int16_t)v0 < 8 );
  sub_120CCB(3, (int)&byte_19B688);
  sub_120DED(119, 0);
  sub_121153(303, 449, word_19B766, v0);
  v2 = 10 * word_19B766 + 100;
  if ( v2 < 0 )
    v2 = 0;
  v73 = 0;
  v72 = 0;
  sub_121153(439, 449, v2, v0);
  v3 = asc_178F24;
  v4 = 0;
  sub_1210B7(453, 449, (int)asc_178F24);
LABEL_43:
  if ( (int16_t)v4 >= 36 )
  {
    v70 = 0;
    v67 = 0;
    v19 = v4 + 1;
    while ( 1 )
    {
      LOWORD(v3) = *(char *)(dword_19B710
                           + (int16_t)v19
                           - (((int16_t)v19
                             + 3
                             - (__CFSHL__(((int16_t)v19 + 3) >> 31, 2)
                              + 4 * (((int16_t)v19 + 3) >> 31))) >> 2));
      v20 = word_19B6A6;
      LOWORD(v20) = *(char *)(dword_19B710 + word_19B6A6 + 27);
      v21 = &v3[-v20];
      v66 = v21;
      if ( word_19B714[(int16_t)v19] >= 0
        && (word_19B766 - (int16_t)v21 >= 0 || word_19B6A6 == (_WORD)v70)
        && (word_19B76C
          + *(char *)(dword_19B710
                    + (int16_t)v19
                    - (((int16_t)v19 + 3 - (__CFSHL__(((int16_t)v19 + 3) >> 31, 2) + 4 * (((int16_t)v19 + 3) >> 31))) >> 2)) >= -10
         || word_19B6A6 == (_WORD)v70) )
      {
        if ( word_19B6A6 != (_WORD)v70 )
          goto LABEL_54;
        sub_12B753(dword_19B70C, 1);
        v22 = v67 + *((_WORD *)&v53 + (int16_t)v72);
        v23 = v59[(int16_t)v73 - 1] - 20;
        v24 = dword_19B70C;
      }
      else
      {
        v22 = v67 + *((_WORD *)&v53 + (int16_t)v72);
        v23 = v59[(int16_t)v73 - 1] - 20;
        v24 = dword_19B6D8;
      }
      sub_12A478(v23, v22, v24);
LABEL_54:
      if ( word_19B6A6 == (_WORD)v70
        || (v3 = (char *)((int16_t)v19
                        - (((int16_t)v19 + 3 - (__CFSHL__(((int16_t)v19 + 3) >> 31, 2) + 4 * (((int16_t)v19 + 3) >> 31))) >> 2)),
            word_19B76C + v3[dword_19B710] < -10)
        || word_19B766 - (int16_t)v66 < 0 )
      {
        if ( word_19B6A6 == (_WORD)v70 )
          v25 = &byte_19B688;
        else
          v25 = v57;
        sub_120CCB(2, (int)v25);
        v61 = (int16_t)v19;
        v26 = v52;
        itoa(
          *(char *)(dword_19B710
                  + (int16_t)v19
                  - (((int16_t)v19 + 3 - (__CFSHL__(((int16_t)v19 + 3) >> 31, 2) + 4 * (((int16_t)v19 + 3) >> 31))) >> 2)),
          v52,
          10,
          v19);
        v50 = v51;
        strcpy(v51, v52);
        v27 = (int16_t)v73;
        v28 = sub_12066F(dword_19B588[v61]);
        LOWORD(v26) = v59[v27];
        v29 = v59[v27 - 1] + v28;
        v30 = sub_12066F((int)v51);
        v31 = (int16_t)v72;
        v32 = v29 - 1;
        v62 = &v26[-v30 - 50];
        for ( i = v67; ; sub_1212B3(v33, i + *((_WORD *)&v53 + v31), (int)asc_178F22) )
        {
          v33 = v32;
          if ( v32 >= (int16_t)v62 - 4 )
            break;
          v32 += 4;
        }
        v34 = (int16_t)v72;
        v35 = (int16_t)v73;
        sub_1212B3(v59[(int16_t)v73 - 1], i + *((_WORD *)&v53 + (int16_t)v72), dword_19B588[(int16_t)v19]);
        v3 = v51;
        sub_1210B7(v59[v35] - 50, i + *((_WORD *)&v53 + v34), (int)v51);
      }
      v67 += 13;
      ++v70;
      ++v19;
      if ( (int16_t)v70 >= 4 )
      {
        v64 = 0;
        v75 = 0;
        ++v73;
        v36 = v19 + 1;
        v69 = v53;
        while ( 1 )
        {
          if ( (int16_t)v36 >= 64 )
            JUMPOUT(0x59689);
          v65 = 0;
          while ( (int16_t)v65 < *((int16_t *)&v76 + (int16_t)v64) )
          {
            v37 = (int16_t)v75;
            if ( word_19B6DC[v37] == 1 )
            {
              sub_12B753(dword_19B70C, 1);
              v38 = v69;
              v39 = v59[(int16_t)v73 - 1] - 20;
              v40 = dword_19B70C;
LABEL_73:
              sub_12A478(v39, v38, v40);
              goto LABEL_74;
            }
            LOWORD(v41) = sub_5AF69((int16_t)v65);
            v66 = v41;
            if ( word_19B6A8[v37] < 0
              || word_19B766 - (int16_t)v41 < 0
              || word_19B76C + *(char *)(dword_19B710 + (int16_t)v36 - 11) < -10 )
            {
              v38 = v69;
              v39 = v59[(int16_t)v73 - 1] - 20;
              v40 = dword_19B6D8;
              goto LABEL_73;
            }
LABEL_74:
            if ( word_19B6DC[(int16_t)v75] == 1
              || word_19B76C + *(char *)((int16_t)v36 + dword_19B710 - 11) < -10
              || word_19B766 - (int16_t)v66 < 0
              || word_19B6A8[(int16_t)v75] < 0 )
            {
              if ( word_19B6DC[(int16_t)v75] == 1 )
                v42 = &byte_19B688;
              else
                v42 = v57;
              sub_120CCB(2, (int)v42);
              v61 = (int16_t)v36;
              itoa(*(char *)((int16_t)v36 + dword_19B710 - 11), v52, 10, v36);
              v50 = v51;
              strcpy(v51, v52);
              v43 = (int16_t)v73;
              v44 = sub_12066F(dword_19B588[v61]);
              v45 = v59[v43];
              v46 = v59[v43 - 1] + v44 - 1;
              v47 = v45 - 50 - sub_12066F((int)v51);
              while ( v46 < v47 - 4 )
              {
                sub_1212B3(v46, v69, (int)asc_178F22);
                v46 += 4;
              }
              v48 = v69;
              v49 = (int16_t)v73;
              sub_1212B3(v59[(int16_t)v73 - 1], v69, dword_19B588[(int16_t)v36]);
              sub_1210B7(v59[v49] - 50, v48, (int)v51);
            }
            v69 += 16;
            ++v75;
            ++v65;
            ++v36;
          }
          v69 += 9;
          ++v64;
        }
      }
    }
  }
  v71 = 0;
  v68 = 0;
  ++v4;
  while ( 1 )
  {
    v5 = (int)((int16_t)v4
             - (__CFSHL__((uint64_t)(int16_t)v4 >> 32, 2)
              + 4 * ((uint64_t)(int16_t)v4 >> 32))) >> 2;
    v6 = v5;
    v7 = 3 * v5;
    if ( word_19B694[v6] )
      v8 = *(char *)(dword_19B710 + v7 + (int16_t)v71) - *(char *)(dword_19B710 + v7 + word_19B694[v6] - 1);
    else
      v8 = *(char *)(dword_19B710 + v7 + (int16_t)v71);
    if ( (word_19B714[(int16_t)v4] > 0
       || word_19B694[(int)((int16_t)v4
                          - (__CFSHL__((uint64_t)(int16_t)v4 >> 32, 2)
                           + 4 * ((uint64_t)(int16_t)v4 >> 32))) >> 2]
        - 1 == (int16_t)v71)
      && (word_19B766 - v8 >= 0
       || word_19B694[(int)((int16_t)v4
                          - (__CFSHL__((uint64_t)(int16_t)v4 >> 32, 2)
                           + 4 * ((uint64_t)(int16_t)v4 >> 32))) >> 2]
        - 1 == (int16_t)v71)
      && (word_19B76C
        + *(char *)((int16_t)v4
                  - (((int16_t)v4 + 3 - (__CFSHL__(((int16_t)v4 + 3) >> 31, 2) + 4 * (((int16_t)v4 + 3) >> 31))) >> 2)
                  + dword_19B710) >= -10
       || word_19B694[(int)((int16_t)v4
                          - (__CFSHL__((uint64_t)(int16_t)v4 >> 32, 2)
                           + 4 * ((uint64_t)(int16_t)v4 >> 32))) >> 2]
        - 1 == (int16_t)v71) )
    {
      if ( word_19B694[(int)((int16_t)v4
                           - (__CFSHL__((uint64_t)(int16_t)v4 >> 32, 2)
                            + 4 * ((uint64_t)(int16_t)v4 >> 32))) >> 2]
         - 1 != (int16_t)v71 )
        goto LABEL_20;
      sub_12B753(dword_19B70C, 1);
      v9 = v68 + *((_WORD *)&v53 + (int16_t)v72);
      v10 = v59[(int16_t)v73 - 1] - 20;
      v3 = (char *)dword_19B70C;
    }
    else
    {
      v9 = v68 + *((_WORD *)&v53 + (int16_t)v72);
      v10 = v59[(int16_t)v73 - 1] - 20;
      v3 = (char *)dword_19B6D8;
    }
    sub_12A478(v10, v9, (int)v3);
LABEL_20:
    if ( (int16_t)v4 >= 4 && (int16_t)v4 < 8 && word_19B6EE == 1 )
    {
      HIWORD(v3) = HIWORD(dword_19B6D8);
      sub_12A478(v59[(int16_t)v73 - 1] - 20, v68 + *((_WORD *)&v53 + (int16_t)v72), dword_19B6D8);
    }
    if ( word_19B694[(int)((int16_t)v4
                         - (__CFSHL__((uint64_t)(int16_t)v4 >> 32, 2)
                          + 4 * ((uint64_t)(int16_t)v4 >> 32))) >> 2]
       - 1 == (int16_t)v71
      || *(char *)(dword_19B710
                 + (int16_t)v4
                 - (((int16_t)v4 + 3 - (__CFSHL__(((int16_t)v4 + 3) >> 31, 2) + 4 * (((int16_t)v4 + 3) >> 31))) >> 2))
       + word_19B76C < -10
      || word_19B766 - v8 < 0
      || (int16_t)v4 >= 4 && (int16_t)v4 < 8 && word_19B6EE == 1
      || word_19B714[(int16_t)v4] == -1000 )
    {
      if ( word_19B694[(int)((int16_t)v4
                           - (__CFSHL__((uint64_t)(int16_t)v4 >> 32, 2)
                            + 4 * ((uint64_t)(int16_t)v4 >> 32))) >> 2]
         - 1 == (int16_t)v71 )
        v11 = &byte_19B688;
      else
        v11 = v57;
      sub_120CCB(2, (int)v11);
      v51[0] = byte_178F21;
      v61 = (int16_t)v4;
      itoa(
        *(char *)(dword_19B710
                + (int16_t)v4
                - (((int16_t)v4 + 3 - (__CFSHL__(((int16_t)v4 + 3) >> 31, 2) + 4 * (((int16_t)v4 + 3) >> 31))) >> 2)),
        v52,
        10,
        v4);
      v50 = v51;
      v12 = (char *)&v50 + 3;
      do
        ++v12;
      while ( *v12 );
      strcpy(v12, v52);
      v13 = v61;
      v14 = (int16_t)v73;
      v15 = (int16_t)(v68 + *((_WORD *)&v53 + (int16_t)v72));
      sub_1212B3(v59[(int16_t)v73 - 1], v15, dword_19B588[v61]);
      v16 = sub_12066F(dword_19B588[v13]);
      LOWORD(v15) = v59[v14];
      v17 = v59[v14 - 1] + v16 - 1;
      v63 = v15 - 50 - sub_12066F((int)v51);
      v74 = v68;
      while ( v17 < (int16_t)v63 - 4 )
      {
        v18 = v17;
        v17 += 4;
        sub_1212B3(v18, v74 + *((_WORD *)&v53 + (int16_t)v72), (int)asc_178F22);
      }
      v3 = v51;
      sub_1210B7(v59[(int16_t)v73] - 50, v74 + *((_WORD *)&v53 + (int16_t)v72), (int)v51);
    }
    v68 += 13;
    ++v71;
    ++v4;
    if ( (int16_t)v71 >= 3 )
    {
      if ( (int16_t)++v72 >= 5 )
      {
        v72 = 0;
        ++v73;
      }
      goto LABEL_43;
    }
  }
}
// 59F9C: control flows out of bounds to 59689
// 59DFE: variable 'v41' is possibly undefined
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 178F21: using guessed type char byte_178F21;
// 19B588: using guessed type int dword_19B588[64];
// 19B688: using guessed type char byte_19B688;
// 19B694: using guessed type int16_t word_19B694[];
// 19B6A6: using guessed type int16_t word_19B6A6;
// 19B6A8: using guessed type int16_t word_19B6A8[16];
// 19B6D8: using guessed type int dword_19B6D8;
// 19B6DC: using guessed type int16_t word_19B6DC[];
// 19B6EE: using guessed type int16_t word_19B6EE;
// 19B70C: using guessed type int dword_19B70C;
// 19B710: using guessed type int dword_19B710;
// 19B714: using guessed type int16_t word_19B714[41];
// 19B766: using guessed type int16_t word_19B766;
// 19B76C: using guessed type int16_t word_19B76C;


//----- (00059FA1) --------------------------------------------------------
int sub_59FA1()
{
  int v0; // ecx
  int v1; // ebx
  int v2; // edx
  int v3; // eax

  word_192C80[0] = 443;
  word_192C82[0] = 54;
  word_192C84[0] = 49;
  word_192C86[0] = 209;
  word_192C88[0] = 111;
  word_192C8A = 444;
  word_192C8C = 54;
  word_192C8E = 123;
  word_192C90 = 209;
  word_192C92 = 185;
  word_192C94 = 445;
  word_192C96 = 54;
  word_192C98 = 197;
  word_192C9A = 208;
  word_192C9C = 259;
  word_192C9E = 446;
  word_192CA0 = 54;
  word_192CA2 = 271;
  word_192CA4 = 208;
  word_192CA6 = 333;
  word_192CA8 = 447;
  word_192CAA = 54;
  word_192CAC = 345;
  word_192CAE = 208;
  word_192CB0 = 411;
  word_192CB2 = 448;
  word_192CB4 = 229;
  word_192CB6 = 49;
  word_192CB8 = 395;
  word_192CBA = 112;
  word_192CBC = 449;
  word_192CBE = 229;
  word_192CC0 = 123;
  word_192CC2 = 395;
  word_192CC4 = 186;
  word_192CC6 = 450;
  word_192CC8 = 229;
  word_192CCA = 197;
  word_192CCC = 395;
  word_192CCE = 260;
  word_192CD0 = 451;
  word_192CD2 = 229;
  word_192CD4 = 271;
  word_192CD6 = 395;
  word_192CD8 = 334;
  word_192CDA = 452;
  word_192CE4 = 453;
  word_192CEE = 454;
  word_192CF8 = 455;
  word_192D02 = 456;
  word_192D0C = 457;
  word_192D16 = 458;
  word_192D20 = 459;
  word_192D2A = 460;
  word_192D34 = 461;
  word_192D3E = 462;
  word_192D48 = 463;
  word_192D52 = 464;
  word_192D5C = 465;
  word_192D66 = 466;
  word_192D70 = 467;
  word_192D7A = 468;
  word_192D84 = 469;
  word_192D8E = 470;
  word_192D98 = 471;
  word_192DA2 = 472;
  word_192DAC = 473;
  v0 = 81;
  v1 = 72;
  v2 = 0;
  do
  {
    v3 = 5 * ((int16_t)v2 + 9);
    word_192C82[v3] = 422;
    word_192C86[v3] = 594;
    word_192C84[v3] = v1;
    ++v2;
    word_192C88[v3] = v0;
    v0 += 16;
    v1 += 16;
  }
  while ( (int16_t)v2 < 22 );
  word_192DB6 = 479;
  word_192DB8 = 190;
  word_192DBA = 442;
  word_192DBC = 309;
  word_192DBE = 464;
  word_192DC0 = 480;
  word_192DC2 = 326;
  word_192DC4 = 442;
  word_192DC6 = 457;
  word_192DC8 = 465;
  word_192DCA = 478;
  word_192DCC = 73;
  word_192DCE = 446;
  word_192DD0 = 146;
  word_192DD2 = 471;
  word_192DD4 = 481;
  word_192DD6 = 504;
  word_192DD8 = 447;
  word_192DDA = 574;
  word_192DDC = 470;
  word_192DDE = 474;
  word_192DE0 = 227;
  word_192DE2 = 371;
  word_192DE4 = 398;
  word_192DE6 = 382;
  word_192DE8 = 475;
  word_192DEA = 227;
  word_192DEC = 384;
  word_192DEE = 398;
  word_192DF0 = 395;
  word_192DF2 = 476;
  word_192DF4 = 227;
  word_192DF6 = 397;
  word_192DF8 = 398;
  word_192DFA = 408;
  word_192DFC = 477;
  word_192DFE = 227;
  word_192E00 = 410;
  word_192E02 = 398;
  word_192E04 = 421;
  return sub_1196B8((int)word_192C80, 39);
}
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
// 192CC6: using guessed type int16_t word_192CC6;
// 192CC8: using guessed type int16_t word_192CC8;
// 192CCA: using guessed type int16_t word_192CCA;
// 192CCC: using guessed type int16_t word_192CCC;
// 192CCE: using guessed type int16_t word_192CCE;
// 192CD0: using guessed type int16_t word_192CD0;
// 192CD2: using guessed type int16_t word_192CD2;
// 192CD4: using guessed type int16_t word_192CD4;
// 192CD6: using guessed type int16_t word_192CD6;
// 192CD8: using guessed type int16_t word_192CD8;
// 192CDA: using guessed type int16_t word_192CDA;
// 192CE4: using guessed type int16_t word_192CE4;
// 192CEE: using guessed type int16_t word_192CEE;
// 192CF8: using guessed type int16_t word_192CF8;
// 192D02: using guessed type int16_t word_192D02;
// 192D0C: using guessed type int16_t word_192D0C;
// 192D16: using guessed type int16_t word_192D16;
// 192D20: using guessed type int16_t word_192D20;
// 192D2A: using guessed type int16_t word_192D2A;
// 192D34: using guessed type int16_t word_192D34;
// 192D3E: using guessed type int16_t word_192D3E;
// 192D48: using guessed type int16_t word_192D48;
// 192D52: using guessed type int16_t word_192D52;
// 192D5C: using guessed type int16_t word_192D5C;
// 192D66: using guessed type int16_t word_192D66;
// 192D70: using guessed type int16_t word_192D70;
// 192D7A: using guessed type int16_t word_192D7A;
// 192D84: using guessed type int16_t word_192D84;
// 192D8E: using guessed type int16_t word_192D8E;
// 192D98: using guessed type int16_t word_192D98;
// 192DA2: using guessed type int16_t word_192DA2;
// 192DAC: using guessed type int16_t word_192DAC;
// 192DB6: using guessed type int16_t word_192DB6;
// 192DB8: using guessed type int16_t word_192DB8;
// 192DBA: using guessed type int16_t word_192DBA;
// 192DBC: using guessed type int16_t word_192DBC;
// 192DBE: using guessed type int16_t word_192DBE;
// 192DC0: using guessed type int16_t word_192DC0;
// 192DC2: using guessed type int16_t word_192DC2;
// 192DC4: using guessed type int16_t word_192DC4;
// 192DC6: using guessed type int16_t word_192DC6;
// 192DC8: using guessed type int16_t word_192DC8;
// 192DCA: using guessed type int16_t word_192DCA;
// 192DCC: using guessed type int16_t word_192DCC;
// 192DCE: using guessed type int16_t word_192DCE;
// 192DD0: using guessed type int16_t word_192DD0;
// 192DD2: using guessed type int16_t word_192DD2;
// 192DD4: using guessed type int16_t word_192DD4;
// 192DD6: using guessed type int16_t word_192DD6;
// 192DD8: using guessed type int16_t word_192DD8;
// 192DDA: using guessed type int16_t word_192DDA;
// 192DDC: using guessed type int16_t word_192DDC;
// 192DDE: using guessed type int16_t word_192DDE;
// 192DE0: using guessed type int16_t word_192DE0;
// 192DE2: using guessed type int16_t word_192DE2;
// 192DE4: using guessed type int16_t word_192DE4;
// 192DE6: using guessed type int16_t word_192DE6;
// 192DE8: using guessed type int16_t word_192DE8;
// 192DEA: using guessed type int16_t word_192DEA;
// 192DEC: using guessed type int16_t word_192DEC;
// 192DEE: using guessed type int16_t word_192DEE;
// 192DF0: using guessed type int16_t word_192DF0;
// 192DF2: using guessed type int16_t word_192DF2;
// 192DF4: using guessed type int16_t word_192DF4;
// 192DF6: using guessed type int16_t word_192DF6;
// 192DF8: using guessed type int16_t word_192DF8;
// 192DFA: using guessed type int16_t word_192DFA;
// 192DFC: using guessed type int16_t word_192DFC;
// 192DFE: using guessed type int16_t word_192DFE;
// 192E00: using guessed type int16_t word_192E00;
// 192E02: using guessed type int16_t word_192E02;
// 192E04: using guessed type int16_t word_192E04;


//----- (0005A3BC) --------------------------------------------------------
void __fastcall sub_5A3BC(int a1, int a2, int a3, int a4)
{
  char *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  char *v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int16_t *v13; // eax
  int16_t *v14; // edi
  int16_t v15; // si
  int v16; // eax
  int v17; // eax
  int16_t v18; // bx
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // esi
  int16_t v23; // bx
  int v24; // eax
  int16_t i; // si
  _BOOL1 v26; // zf
  int v27; // eax
  int v28; // eax
  int v29; // esi
  int v30; // eax
  int v31; // eax
  int v32; // ebx
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int16_t v36; // si
  int v37; // eax
  int v38; // ebx
  void *v39; // eax
  int16_t v40; // ax
  int v41; // eax
  char *v42; // edi
  int v43; // eax
  int v44; // eax
  int v45; // [esp+0h] [ebp-Eh]
  int16_t *v46; // [esp+0h] [ebp-Eh]
  char v47[98]; // [esp+4h] [ebp-Ah] BYREF
  _BYTE v48[6]; // [esp+66h] [ebp+58h]
  char *v49; // [esp+6Ch] [ebp+5Eh]
  int v50; // [esp+70h] [ebp+62h]
  int v51; // [esp+74h] [ebp+66h]
  char *v52; // [esp+78h] [ebp+6Ah]
  void *v53; // [esp+7Ch] [ebp+6Eh]
  void *v54; // [esp+80h] [ebp+72h]
  int v55; // [esp+84h] [ebp+76h]
  char *v56; // [esp+88h] [ebp+7Ah]
  int v57; // [esp+8Ch] [ebp+7Eh]

  word_19B770 = 0;
  sub_59FA1();
  sub_11C2F0();
  sub_5AD97(v45);
  v4 = (char *)(v45 + 21);
  v5 = sub_58FC3(word_19B772);
  v46 = word_19B772;
  strcpy((char *)word_19B772, v4);
  sub_59053(v5, 1, a3);
  sub_1191CA((int)sub_596A5, 1);
  byte_19B688[0] = -114;
  byte_19B689 = -99;
  byte_19B68A = -100;
  v6 = 3;
  do
  {
    v7 = (int16_t)v6++;
    byte_19B688[v7] = -99;
  }
  while ( (int16_t)v6 < 8 );
  sub_FE8BE(v6, 1, v7, word_19B772);
  v8 = byte_19B688;
  sub_120BB5(4, (int)byte_19B688);
  sub_5AAD4();
  v9 = 0;
  do
  {
    v10 = (int16_t)v9;
    LOWORD(v8) = word_19B694[(int16_t)v9++];
    *(_WORD *)&v47[2 * v10 + 80] = (_WORD)v8;
  }
  while ( (int16_t)v9 < 10 );
  sub_FE8BE(v10, (int)v8, v9, word_19B772);
  sub_5AAD4();
  sub_FE8BE(v11, (int)v8, v9, word_19B772);
  sub_124D7A();
  sub_59105();
  sub_124E36();
  sub_124D41();
  sub_596A5();
  sub_1077D(v12, (int)v8, v9, word_19B772);
  v54 = &unk_19C011;
  v53 = (char *)&word_19B772[18] + 1;
  v49 = (char *)&word_19B772[10] + 1;
  *(_DWORD *)&v48[2] = &word_19B772[19];
  v13 = (int16_t *)((char *)word_19B772 + 1);
  v57 = 0;
  v56 = (char *)word_19B772 + 1;
  while ( 1 )
  {
    if ( (_WORD)v57 )
    {
      sub_1196F7();
      sub_119281();
      sub_1113CC(dword_192ED4, (int)v8);
LABEL_81:
      JUMPOUT(0x59698);
    }
    word_19994C = 0;
    v13 = (int16_t *)sub_1171AB((int)v13, (int)v8, v9, a4);
    v14 = v13;
    if ( (_WORD)v13 )
      break;
LABEL_76:
    if ( word_19994C )
    {
      sub_124D7A();
      sub_59105();
      v13 = (int16_t *)sub_124E36();
    }
    if ( !(_WORD)v57 )
    {
      sub_5AAD4();
      sub_124D41();
      sub_596A5();
      v13 = (int16_t *)sub_1077D(v44, (int)v8, v9, v14);
    }
  }
  v15 = 0;
  while ( 1 )
  {
    v16 = v15;
    if ( (_WORD)v14 == word_19B714[v15] )
    {
      if ( (int)(v15 - (__CFSHL__((uint64_t)v15 >> 32, 2) + 4 * ((uint64_t)v15 >> 32))) >> 2 == 1
        && word_19B6EE == 1 )
      {
        v8 = v47;
        sub_58F1E(73, v47, 120);
        sub_77433(v47);
        sub_124D7A();
        sub_59105();
        sub_124E36();
        sub_124D41();
        sub_596A5();
        sub_1077D(v17, (int)v47, 120, v14);
        v16 = 1;
        word_19B696 = 0;
      }
      else
      {
        v18 = v15;
        v19 = (int)(v15 - (__CFSHL__((uint64_t)v15 >> 32, 2) + 4 * ((uint64_t)v15 >> 32))) >> 2;
        v50 = *(int16_t *)&v47[v19 * 2 + 80];
        v51 = 4;
        v8 = (char *)(v15 % 4);
        v20 = v50;
        v52 = v8;
        if ( (char *)v50 == v8 )
        {
          word_19B694[v19] = 0;
        }
        else
        {
          v8 = (char *)word_19B76C;
          if ( word_19B76C
             + *(char *)(v15 - ((v15 + 3 - (__CFSHL__((v15 + 3) >> 31, 2) + 4 * ((v15 + 3) >> 31))) >> 2) + dword_19B710) >= -10 )
          {
            v16 = (int)v52;
            word_19B694[v19] = (int16_t)v52;
            goto LABEL_19;
          }
          v18 = 80;
          v8 = v47;
          sub_58F1E(74, v47, 80);
          sub_77433(v47);
          sub_124D7A();
          sub_59105();
          sub_124E36();
          sub_124D41();
          sub_596A5();
          v20 = sub_1077D(v21, (int)v47, 80, v14);
          LOWORD(v20) = *(_WORD *)&v47[v19 * 2 + 80];
          word_19B694[v19] = v20;
        }
        sub_59053(v20, (int)v8, v18);
      }
    }
LABEL_19:
    if ( ++v15 >= 36 )
    {
      v22 = 37;
      do
      {
        v23 = v22;
        if ( (_WORD)v14 == word_19B714[(int16_t)v22] )
        {
          sub_59053(v16, (int)v8, v22);
          v8 = (char *)word_19B6A6;
          if ( word_19B6A6 == (int16_t)v22 - 37
            || (v8 = (char *)word_19B76C, word_19B76C + *(char *)((int16_t)v22 + dword_19B710 - 10) >= -10) )
          {
            v16 = v22 - 37;
            word_19B6A6 = v22 - 37;
          }
          else
          {
            v23 = 80;
            v8 = v47;
            sub_58F1E(74, v47, 80);
            sub_77433(v47);
            sub_124D7A();
            sub_59105();
            sub_124E36();
            sub_124D41();
            sub_596A5();
            sub_1077D(v24, (int)v47, 80, v14);
            word_19B6A6 = *(_WORD *)v48;
            sub_59053(*(int *)v48, (int)v47, 80);
          }
        }
        ++v22;
      }
      while ( (int16_t)v22 < 41 );
      for ( i = 0; i < 22; ++i )
      {
        a4 = 2 * i;
        if ( (_WORD)v14 == *(int16_t *)((char *)word_19B6A8 + a4) )
        {
          v27 = (uint16_t)(1 - word_19B6DC[i]);
          v26 = word_19B6DC[i] == 1;
          word_19B6DC[i] = v27;
          if ( v26 )
          {
            sub_59053(v27, (int)v8, v23);
          }
          else
          {
            sub_59053(v27, (int)v8, v23);
            if ( word_19B76C < -10 )
            {
              v23 = 80;
              v8 = v47;
              sub_58F1E(74, v47, 80);
              sub_77433(v47);
              sub_124D7A();
              sub_59105();
              sub_124E36();
              sub_124D41();
              sub_596A5();
              sub_1077D(v28, (int)v47, 80, v14);
              word_19B6DC[i] = 0;
            }
            if ( i == 5 )
            {
              word_19B6E8 = 0;
            }
            else if ( i == 6 )
            {
              word_19B6E6 = 0;
            }
            else if ( i )
            {
              switch ( i )
              {
                case 1:
                  word_19B6DC[0] = 0;
                  break;
                case 9:
                  word_19B6EC = 0;
                  word_19B696 = 0;
                  break;
                case 8:
                  word_19B6EE = 0;
                  break;
                case 10:
                  word_19B6F2 = 0;
                  break;
                case 11:
                  word_19B6F0 = 0;
                  break;
                case 12:
                  word_19B6F6 = 0;
                  break;
                case 13:
                  word_19B6F4 = 0;
                  break;
              }
            }
            else
            {
              word_19B6DE = 0;
            }
          }
        }
      }
      if ( (_WORD)v14 == word_19B768 )
      {
        v29 = 0;
        do
        {
          v30 = (int16_t)v29++;
          word_19B694[v30] = 0;
        }
        while ( (int16_t)v29 < 9 );
        word_19B6A6 = 1;
        v31 = 0;
        do
        {
          v32 = (int16_t)v31++;
          word_19B6DC[v32] = 0;
        }
        while ( (int16_t)v31 < 22 );
      }
      if ( (_WORD)v14 == word_19B76A )
      {
        sub_11C2F0();
        sub_119281();
        sub_1113CC(dword_192ED4, (int)v8);
        goto LABEL_81;
      }
      if ( (_WORD)v14 == word_19B76E )
      {
        if ( word_19B766 >= 0 )
        {
          sub_5AE38((int)v46);
          sub_1191CA((int)nullsub_15, 2);
          sub_124D7A();
          v34 = sub_127C27((int)aRaceoptLbx_0, 4, dword_193174);
          sub_12A478(0, 0, v34);
          v35 = sub_127C27((int)aRaceoptLbx_0, 6, dword_193174);
          sub_12A478(0, 430, v35);
          sub_124D41();
          do
          {
            sub_1196F7();
            a4 = sub_5D2BB(v56, *((uint8_t *)v46 + 37), v14);
            v36 = a4;
            sub_124D7A();
            v37 = sub_127C27((int)aRaceoptLbx_0, 4, dword_193174);
            sub_12A478(0, 0, v37);
            v38 = sub_127C27((int)aRaceoptLbx_0, 6, dword_193174);
            sub_12A478(0, 430, v38);
            v39 = sub_124E36();
            sub_1077D((int)v39, 430, v38, v14);
            if ( (_WORD)a4 == 1 )
            {
              sub_5D03C(*(int16_t **)&v48[2], 430, v38);
              v36 = v40 + 1;
            }
          }
          while ( v36 == 1 );
          if ( v36 == 2 )
          {
            v8 = aWb_1;
            v41 = fopen(aLastraceRac_0);
            v55 = v41;
            if ( v41 )
            {
              fwrite(v54, 31, 1, v41);
              v42 = v49;
              fwrite(v53, 1, 1, v55);
              v46 = (int16_t *)v42;
              strcpy(v42, (char *)word_19B772);
              v14 = v46;
              a4 = v55;
              HIWORD(v8) = 0;
              fwrite(v46, 15, 1, v55);
              fclose(v55);
            }
            v57 = 1;
            word_199A08 = word_199A10;
            sub_C5BB9();
          }
          else
          {
            sub_59FA1();
            HIWORD(v8) = 0;
            word_19B770 = 0;
            sub_1191CA((int)sub_596A5, 2);
          }
        }
        else
        {
          v8 = v47;
          sub_58F1E(75, v47, 80);
          sub_77433(v47);
          sub_124D7A();
          sub_59105();
          sub_124E36();
          sub_124D41();
          sub_596A5();
          sub_1077D(v33, (int)v47, 80, v14);
        }
      }
      v9 = 0;
      do
      {
        v43 = (int16_t)v9;
        LOWORD(v8) = word_19B694[(int16_t)v9++];
        *(_WORD *)&v47[2 * v43 + 80] = (_WORD)v8;
      }
      while ( (int16_t)v9 < 10 );
      sub_59053(v43, (int)v8, v9);
      goto LABEL_76;
    }
  }
}
// 5A873: control flows out of bounds to 59698
// 5A3EF: variable 'v45' is possibly undefined
// 5A406: variable 'v5' is possibly undefined
// 5A47C: variable 'v11' is possibly undefined
// 5A49A: variable 'v12' is possibly undefined
// 5A4E7: variable 'v13' is possibly undefined
// 5A557: variable 'v17' is possibly undefined
// 5A605: variable 'v21' is possibly undefined
// 5A643: variable 'v16' is possibly undefined
// 5A6A1: variable 'v24' is possibly undefined
// 5A743: variable 'v28' is possibly undefined
// 5A8C2: variable 'v33' is possibly undefined
// 5A9A8: variable 'v40' is possibly undefined
// 5AAAC: variable 'v44' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// FE8D4: using guessed type int __fastcall nullsub_15(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 19994C: using guessed type int16_t word_19994C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 19B689: using guessed type char byte_19B689;
// 19B68A: using guessed type char byte_19B68A;
// 19B694: using guessed type int16_t word_19B694[];
// 19B696: using guessed type int16_t word_19B696;
// 19B6A6: using guessed type int16_t word_19B6A6;
// 19B6A8: using guessed type int16_t word_19B6A8[16];
// 19B6DC: using guessed type int16_t word_19B6DC[];
// 19B6DE: using guessed type int16_t word_19B6DE;
// 19B6E6: using guessed type int16_t word_19B6E6;
// 19B6E8: using guessed type int16_t word_19B6E8;
// 19B6EC: using guessed type int16_t word_19B6EC;
// 19B6EE: using guessed type int16_t word_19B6EE;
// 19B6F0: using guessed type int16_t word_19B6F0;
// 19B6F2: using guessed type int16_t word_19B6F2;
// 19B6F4: using guessed type int16_t word_19B6F4;
// 19B6F6: using guessed type int16_t word_19B6F6;
// 19B710: using guessed type int dword_19B710;
// 19B714: using guessed type int16_t word_19B714[41];
// 19B766: using guessed type int16_t word_19B766;
// 19B768: using guessed type int16_t word_19B768;
// 19B76A: using guessed type int16_t word_19B76A;
// 19B76C: using guessed type int16_t word_19B76C;
// 19B76E: using guessed type int16_t word_19B76E;
// 19B770: using guessed type int16_t word_19B770;
// 19B772: using guessed type int16_t word_19B772[25];


//----- (0005AAD4) --------------------------------------------------------
void sub_5AAD4()
{
  int16_t v0; // di
  int v1; // esi
  int v2; // ebx
  int16_t v3; // cx
  int16_t v4; // ax
  int v5; // eax
  int16_t v6; // si
  int16_t v7; // dx
  int16_t v8; // cx
  int16_t v9; // dx
  int16_t v10; // bx
  int16_t v11; // ax
  int16_t v12; // dx
  int v13; // eax
  int16_t v14; // di
  int16_t v15; // si
  int16_t v16; // cx
  int16_t v17; // dx
  int16_t v18; // bx
  int16_t v19; // dx
  int16_t v20; // ax
  int16_t v21; // dx
  int v22; // eax
  int v23; // [esp+0h] [ebp-40h]
  int16_t v24; // [esp+4h] [ebp-3Ch]
  int16_t v25; // [esp+6h] [ebp-3Ah]
  int16_t v26; // [esp+8h] [ebp-38h]
  int16_t v27; // [esp+Ch] [ebp-34h]
  _WORD v28[3]; // [esp+Eh] [ebp-32h]
  int v29; // [esp+14h] [ebp-2Ch]
  int v30; // [esp+18h] [ebp-28h]
  int v31; // [esp+1Ch] [ebp-24h]
  int v32; // [esp+20h] [ebp-20h]
  int v33; // [esp+24h] [ebp-1Ch]
  int v34; // [esp+28h] [ebp-18h]
  int v35; // [esp+2Ch] [ebp-14h]
  int v36; // [esp+30h] [ebp-10h]
  int v37; // [esp+34h] [ebp-Ch]
  int v38; // [esp+38h] [ebp-8h]
  int v39; // [esp+3Ch] [ebp-4h]

  v27 = 80;
  v28[0] = 254;
  v28[1] = 442;
  v28[2] = 643;
  v23 = 9633864;
  v24 = 222;
  v25 = 297;
  v26 = 372;
  v31 = 22;
  if ( word_19B770 <= 0 )
  {
    sub_11C2F0();
    sub_120BB5(4, (int)byte_19B688);
    word_19B770 = (uint16_t)sub_115BEA(248, 15, 150, 14, (int)&unk_19B772, 15, 0, 0, 0, 0);
  }
  else
  {
    sub_119400(word_19B770);
  }
  v0 = 0;
  word_19B76A = sub_114C72(asc_178F36, 448);
  v1 = 0;
  word_19B76E = (uint16_t)sub_1151B0(506, 448, (int)&byte_178F21, (_WORD *)dword_19B6D4, aA, 40);
  v38 = 0;
  word_19B768 = (uint16_t)sub_1151B0(76, 448, (int)&byte_178F21, (_WORD *)dword_19B690, aC, 40);
  while ( (int16_t)v1 < 36 )
  {
    v2 = (int16_t)v1;
    v30 = 4;
    if ( !((int16_t)v1 % 4) )
    {
      ++v1;
      word_19B714[v2] = -1000;
    }
    v37 = 0;
    do
    {
      v29 = (int16_t)v1;
      v3 = v37 + *((_WORD *)&v23 + (int16_t)v38) + 9;
      v30 = (int16_t)(v37 + *((_WORD *)&v23 + (int16_t)v38));
      v4 = sub_11438B(v28[v0 - 1] - 20, v30, v28[v0] - 50, v3, &byte_178F21, 41);
      ++v1;
      v37 += 13;
      word_19B714[v29] = v4;
    }
    while ( (_WORD)v37 != 39 );
    if ( (int16_t)++v38 >= 5 )
    {
      v38 = 0;
      ++v0;
    }
  }
  v36 = 0;
  v5 = (int16_t)v1;
  v6 = v1 + 1;
  word_19B714[v5] = -1000;
  do
  {
    v7 = *((_WORD *)&v23 + (int16_t)v38);
    v30 = (int16_t)(v36 + v7 + 9);
    v29 = (int16_t)(v36 + v7);
    v8 = v36 + v7 + 9;
    v9 = v36 + v7;
    v10 = v28[v0] - 50;
    v11 = v28[v0 - 1] - 20;
    v36 += 13;
    v12 = sub_11438B(v11, v9, v10, v8, &byte_178F21, 41);
    v13 = v6++;
    word_19B714[v13] = v12;
  }
  while ( (_WORD)v36 != 52 );
  v34 = 0;
  v32 = 0;
  v14 = v0 + 1;
  v15 = v6 + 1;
  v39 = v23;
  while ( v15 < 64 )
  {
    v35 = 0;
    v33 = v39 + 9;
    while ( (int16_t)v35 < *((int16_t *)&v31 + (int16_t)v34) )
    {
      v16 = v33;
      ++v35;
      ++v15;
      v17 = v28[v14 - 1];
      v33 += 16;
      v18 = v17 + 152;
      v19 = v39;
      v20 = v28[v14 - 1] - 20;
      v39 += 16;
      v21 = sub_11438B(v20, v19, v18, v16, &byte_178F21, 41);
      v22 = (int16_t)v32++;
      word_19B6A8[v22] = v21;
    }
    v39 += 9;
    ++v34;
  }
  JUMPOUT(0x590FF);
}
// 5AD92: control flows out of bounds to 590FF
// 178F21: using guessed type char byte_178F21;
// 19B690: using guessed type int dword_19B690;
// 19B6A8: using guessed type int16_t word_19B6A8[16];
// 19B6D4: using guessed type int dword_19B6D4;
// 19B714: using guessed type int16_t word_19B714[41];
// 19B768: using guessed type int16_t word_19B768;
// 19B76A: using guessed type int16_t word_19B76A;
// 19B76E: using guessed type int16_t word_19B76E;
// 19B770: using guessed type int16_t word_19B770;


//----- (0005AD97) --------------------------------------------------------
void __fastcall sub_5AD97(int a1)
{
  int v1; // ebx
  int16_t v2; // si
  int16_t i; // dx
  int v4; // eax
  int16_t v5; // [esp+0h] [ebp-4h]

  v1 = a1 + 2207;
  v2 = 0;
  word_19B6A6 = *(char *)(a1 + 2207) / 2;
  for ( i = 0; i < 9; ++i )
  {
    v5 = *(char *)(i + v1 + 1);
    v4 = i;
    word_19B694[v4] = v5;
  }
  while ( ++i < 31 )
  {
    word_19B6C8[i + v2] = *(char *)(i + v1);
    if ( i == 15 )
    {
      if ( word_19B6E6 == -1 )
      {
        word_19B6C8[i] = 0;
        word_19B6CA[i] = 1;
      }
      else
      {
        word_19B6CA[i] = 0;
      }
      v2 = 1;
    }
  }
  JUMPOUT(0x590FF);
}
// 5AE33: control flows out of bounds to 590FF
// 19B694: using guessed type int16_t word_19B694[];
// 19B6A6: using guessed type int16_t word_19B6A6;
// 19B6C8: using guessed type int16_t word_19B6C8[];
// 19B6CA: using guessed type int16_t word_19B6CA[5];
// 19B6E6: using guessed type int16_t word_19B6E6;


//----- (0005AE38) --------------------------------------------------------
int __fastcall sub_5AE38(int a1)
{
  int v1; // esi
  int result; // eax
  _BYTE *v3; // edx
  _BYTE *v4; // edx
  int16_t v5; // [esp+4h] [ebp-4h]

  v5 = 0;
  v1 = a1 + 2207;
  *(_BYTE *)(a1 + 2207) = 2 * word_19B6A6;
  result = 1;
  do
  {
    v3 = (_BYTE *)(v1 + (int16_t)result);
    if ( *((_WORD *)&dword_19B690 + (int16_t)result + 1) )
      *v3 = byte_17D1F9[3 * (int16_t)result + *((int16_t *)&dword_19B690 + (int16_t)result + 1)];
    else
      *v3 = 0;
    ++result;
  }
  while ( (int16_t)result < 10 );
  while ( (int16_t)result < 32 )
  {
    if ( (_WORD)result == 15 )
    {
      v4 = (_BYTE *)(v1 + 15);
      if ( word_19B6E6 == 1 )
      {
        *v4 = 1;
      }
      else if ( word_19B6E8 == 1 )
      {
        *v4 = -1;
      }
      else
      {
        *v4 = 0;
      }
      v5 = 1;
      ++result;
    }
    else
    {
      *(_BYTE *)((int16_t)result - v5 + v1) = word_19B6C8[(int16_t)result];
    }
    ++result;
  }
  return result;
}
// 19B690: using guessed type int dword_19B690;
// 19B6A6: using guessed type int16_t word_19B6A6;
// 19B6C8: using guessed type int16_t word_19B6C8[];
// 19B6E6: using guessed type int16_t word_19B6E6;
// 19B6E8: using guessed type int16_t word_19B6E8;


//----- (0005AEF4) --------------------------------------------------------
int sub_5AEF4()
{
  _DWORD *v0; // esi
  int v1; // ebx
  int result; // eax
  _BYTE *v3; // edx
  int v4; // ecx

  v0 = sub_126B42((int)aRacestufLbx_2, (uint8_t)byte_199CAE, dword_192ED4);
  v1 = 1;
  dword_19B710 = (int)sub_126B42((int)aRacestufLbx_2, 6, dword_192ED4);
  dword_19B588[0] = (int)v0;
  result = 0;
  do
  {
    while ( *((_BYTE *)v0 + (int16_t)result) )
      ++result;
    while ( 1 )
    {
      v3 = (char *)v0 + (int16_t)result;
      if ( *v3 )
        break;
      ++result;
    }
    v4 = (int16_t)v1++;
    dword_19B588[v4] = (int)v3;
  }
  while ( (int16_t)v1 < 64 );
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 199CAE: using guessed type char byte_199CAE;
// 19B588: using guessed type int dword_19B588[64];
// 19B710: using guessed type int dword_19B710;


//----- (0005AF69) --------------------------------------------------------
int16_t __fastcall sub_5AF69(int a1)
{
  int16_t v1; // dx
  int v2; // ecx
  int v3; // eax
  int16_t v4; // cx
  int16_t v5; // cx
  int16_t v6; // cx
  int16_t v7; // dx

  v1 = a1;
  v2 = (int16_t)a1;
  v3 = a1 + 31;
  LOWORD(v3) = *(char *)((int16_t)v3 + dword_19B710);
  if ( word_19B6DC[v2] == 1 )
    v3 = -v3;
  if ( v1 == 5 && word_19B6E8 == 1 )
    LOWORD(v3) = v3 - *(char *)(dword_19B710 + 37);
  if ( v1 == 6 && word_19B6E6 == 1 )
    LOWORD(v3) = v3 - *(char *)(dword_19B710 + 36);
  if ( !v1 && word_19B6DE == 1 )
  {
    v4 = *(char *)(dword_19B710 + 32);
LABEL_15:
    LOWORD(v3) = v3 - v4;
    goto LABEL_16;
  }
  if ( v1 == 1 && word_19B6DC[0] == 1 )
  {
    v4 = *(char *)(dword_19B710 + 31);
    goto LABEL_15;
  }
LABEL_16:
  if ( v1 == 9 )
  {
    if ( word_19B6EC == 1 )
      LOWORD(v3) = v3 - *(char *)(dword_19B710 + 39);
    if ( word_19B696 )
    {
      v5 = *(char *)(dword_19B710 + word_19B696 + 2);
LABEL_24:
      LOWORD(v3) = v3 - v5;
    }
  }
  else if ( v1 == 8 && word_19B6EE == 1 )
  {
    v5 = *(char *)(dword_19B710 + 40);
    goto LABEL_24;
  }
  if ( v1 == 10 && word_19B6F2 == 1 )
  {
    v6 = *(char *)(dword_19B710 + 42);
LABEL_31:
    LOWORD(v3) = v3 - v6;
    goto LABEL_32;
  }
  if ( v1 == 11 && word_19B6F0 == 1 )
  {
    v6 = *(char *)(dword_19B710 + 41);
    goto LABEL_31;
  }
LABEL_32:
  if ( v1 == 13 && word_19B6F4 == 1 )
  {
    v7 = *(char *)(dword_19B710 + 43);
LABEL_38:
    LOWORD(v3) = v3 - v7;
    return v3;
  }
  if ( v1 == 12 && word_19B6F6 == 1 )
  {
    v7 = *(char *)(dword_19B710 + 44);
    goto LABEL_38;
  }
  return v3;
}
// 19B696: using guessed type int16_t word_19B696;
// 19B6DC: using guessed type int16_t word_19B6DC[];
// 19B6DE: using guessed type int16_t word_19B6DE;
// 19B6E6: using guessed type int16_t word_19B6E6;
// 19B6E8: using guessed type int16_t word_19B6E8;
// 19B6EC: using guessed type int16_t word_19B6EC;
// 19B6EE: using guessed type int16_t word_19B6EE;
// 19B6F0: using guessed type int16_t word_19B6F0;
// 19B6F2: using guessed type int16_t word_19B6F2;
// 19B6F4: using guessed type int16_t word_19B6F4;
// 19B6F6: using guessed type int16_t word_19B6F6;
// 19B710: using guessed type int dword_19B710;


//----- (0005B0AA) --------------------------------------------------------
void __fastcall sub_5B0AA( int a1)
{
  char v2; // [esp+4h] [ebp-8h]
  int v3; // [esp+8h] [ebp-4h]

  v3 = 3753 * a1;
  v2 = *(_BYTE *)(v3 + dword_197F98 + 2207);
  if ( *(_BYTE *)(v3 + dword_197F98 + 40) == 100 )
  {
    sub_12779E((_BYTE *)(v3 + dword_197F98 + 2239), (_BYTE *)(v3 + dword_197F98 + 2208), 0x1Eu);
    *(_BYTE *)(v3 + dword_197F98 + 2238) = v2 & 0xE;
    sub_5B649();
    *(_BYTE *)(v3 + dword_197F98 + 2207) = v2;
  }
  else
  {
    sub_12779E((_BYTE *)(v3 + dword_197F98 + 2208), (_BYTE *)(v3 + dword_197F98 + 2239), 0x1Eu);
  }
  *(_BYTE *)(3753 * a1 + dword_197F98 + 2269) = 1;
  JUMPOUT(0x590FF);
}
// 5B145: control flows out of bounds to 590FF
// 197F98: using guessed type int dword_197F98;


//----- (0005B14A) --------------------------------------------------------
int __fastcall sub_5B14A(int a1, int a2)
{
  int16_t v2; // di
  int v3; // esi
  uint16_t v4; // ax
  int v5; // ebx
  int v6; // edx
  int v7; // eax
  int v8; // edx
  int16_t v9; // bx
  int v10; // edx
  int v11; // eax
  int16_t v12; // dx
  int v13; // eax
  int v14; // edx
  int16_t v15; // si
  int v16; // eax
  int result; // eax
  int16_t v18; // si
  int16_t v19; // di
  int16_t v20; // ax
  int v23; // [esp+8h] [ebp-4Ch]
  int16_t v24; // [esp+Ch] [ebp-48h]
  int16_t v25; // [esp+Eh] [ebp-46h]
  int16_t v26; // [esp+10h] [ebp-44h]
  int16_t v27; // [esp+14h] [ebp-40h]
  _WORD v28[3]; // [esp+16h] [ebp-3Eh]
  int v29; // [esp+1Ch] [ebp-38h]
  int v30; // [esp+20h] [ebp-34h]
  int v31; // [esp+24h] [ebp-30h]
  int v32; // [esp+28h] [ebp-2Ch]
  int v33; // [esp+2Ch] [ebp-28h]
  int v34; // [esp+30h] [ebp-24h]
  int v35; // [esp+34h] [ebp-20h]
  int v36; // [esp+38h] [ebp-1Ch]
  int v37; // [esp+3Ch] [ebp-18h]
  int v38; // [esp+40h] [ebp-14h]
  int v39; // [esp+44h] [ebp-10h]
  int v40; // [esp+48h] [ebp-Ch]
  int v41; // [esp+4Ch] [ebp-8h]
  int v42; // [esp+50h] [ebp-4h]

  v27 = 80;
  v28[0] = 254;
  v28[1] = 442;
  v28[2] = 643;
  v23 = 9633864;
  v24 = 222;
  v25 = 297;
  v26 = 372;
  v32 = 22;
  v40 = 0;
  sub_11C2F0();
  v2 = 0;
  v3 = 0;
  word_19B76A = -1000;
  v4 = (uint16_t)sub_1151B0(506, 448, (int)&byte_178F21, (_WORD *)dword_19B6D4, &byte_178F21, 40);
  word_19B768 = -1000;
  word_19B76E = v4;
  while ( (int16_t)v3 < 36 )
  {
    v5 = (int16_t)v3;
    v31 = 4;
    if ( !((int16_t)v3 % 4) )
    {
      ++v3;
      word_19B714[v5] = -1000;
    }
    v39 = 0;
    v38 = 0;
    do
    {
      v6 = (int)((int16_t)v3
               - (__CFSHL__((uint64_t)(int16_t)v3 >> 32, 2)
                + 4 * ((uint64_t)(int16_t)v3 >> 32))) >> 2;
      if ( *(_BYTE *)(v6 + a1 + 1) )
      {
        v7 = 3 * v6 + *(char *)(v6 + a1);
        LOWORD(v7) = *(char *)(dword_19B710 + v7 - 1);
        v34 = v7;
      }
      else
      {
        v34 = 0;
      }
      v8 = (int)((int16_t)v3
               - (__CFSHL__((uint64_t)(int16_t)v3 >> 32, 2)
                + 4 * ((uint64_t)(int16_t)v3 >> 32))) >> 2;
      v9 = *(char *)(dword_19B710 + (int16_t)v39 + 3 * v8);
      if ( (v9 < 0 && *(_BYTE *)(v8 + a1 + 1) == 1
         || v9 > 0
         && ((v10 = (int)((int16_t)v3
                        - (__CFSHL__((uint64_t)(int16_t)v3 >> 32, 2)
                         + 4 * ((uint64_t)(int16_t)v3 >> 32))) >> 2,
              v11 = v10 + a1,
              v30 = *(char *)(v10 + a1 + 1),
              v31 = (int16_t)v39 + 1,
              v30 <= v31)
          || (LOWORD(v11) = *(char *)(v11 + 1), v42 = v11, word_19B694[v10] > (int16_t)v11)))
        && v9 - (int16_t)v34 <= a2 )
      {
        v12 = v38 + *((_WORD *)&v23 + v2);
        v30 = (int16_t)(v38 + *((_WORD *)&v23 + v2) + 9);
        word_19B714[(int16_t)v3] = sub_11438B(
                                     v28[(int16_t)v40 - 1] - 20,
                                     v12,
                                     v28[(int16_t)v40] - 50,
                                     v30,
                                     &byte_178F21,
                                     41);
      }
      else
      {
        word_19B714[(int16_t)v3] = -1000;
      }
      v38 += 13;
      ++v39;
      ++v3;
    }
    while ( (int16_t)v39 < 3 );
    if ( ++v2 >= 5 )
    {
      ++v40;
      v2 = 0;
    }
  }
  v13 = (int16_t)v3;
  v14 = 0;
  v15 = v3 + 1;
  word_19B714[v13] = -1000;
  do
  {
    v16 = v15;
    ++v14;
    ++v15;
    word_19B714[v16] = -1000;
  }
  while ( (int16_t)v14 < 4 );
  result = v23;
  v36 = 0;
  ++v40;
  v18 = v15 + 1;
  v19 = 0;
  v41 = v23;
  while ( v18 < 64 )
  {
    v35 = 0;
    v37 = 0;
    v33 = v41 + 9;
    while ( 1 )
    {
      result = (int16_t)v36;
      if ( (int16_t)v37 >= *((int16_t *)&v32 + (int16_t)v36) )
        break;
      if ( v19 == 4
        || v19 == 5
        || v19 == 6
        || v19 == 7
        || *(char *)(v19 + dword_19B710 + 31) < 0 && !*(_BYTE *)(a1 + v19 + (int16_t)v35 + 10)
        || *(char *)(v19 + dword_19B710 + 31) > 0 && *(_BYTE *)(a1 + v19 + (int16_t)v35 + 10) == 1
        || (v29 = v19, *(char *)(v19 + dword_19B710 + 31) > a2) )
      {
        word_19B6A8[v19] = -1000;
      }
      else
      {
        v20 = sub_11438B(v28[(int16_t)v40 - 1] - 20, v41, v28[(int16_t)v40 - 1] + 152, v33, &byte_178F21, 41);
        word_19B6A8[v29] = v20;
      }
      if ( (_WORD)v37 == 6 )
        v35 = -1;
      v33 += 16;
      v41 += 16;
      ++v37;
      ++v19;
      ++v18;
    }
    v41 += 9;
    ++v36;
  }
  return result;
}
// 178F21: using guessed type char byte_178F21;
// 19B694: using guessed type int16_t word_19B694[];
// 19B6A8: using guessed type int16_t word_19B6A8[16];
// 19B6D4: using guessed type int dword_19B6D4;
// 19B710: using guessed type int dword_19B710;
// 19B714: using guessed type int16_t word_19B714[41];
// 19B768: using guessed type int16_t word_19B768;
// 19B76A: using guessed type int16_t word_19B76A;
// 19B76E: using guessed type int16_t word_19B76E;


//----- (0005B4CD) --------------------------------------------------------
void __fastcall sub_5B4CD(char *a1)
{
  int16_t i; // dx
  int v2; // esi
  char v3; // cl
  int16_t v4; // [esp+0h] [ebp-4h]

  v4 = 0;
  word_19B6A6 = *a1 / 2;
  for ( i = 0; i < 9; ++i )
  {
    v2 = 3 * (i + 1);
    v3 = a1[i + 1];
    if ( v3 == byte_17D1FA[v2] )
    {
      word_19B694[i] = 1;
    }
    else if ( v3 == byte_17D1FB[v2] )
    {
      word_19B694[i] = 2;
    }
    else if ( v3 == byte_17D1FC[v2] )
    {
      word_19B694[i] = 3;
    }
    else
    {
      word_19B694[i] = 0;
    }
  }
  while ( ++i < 31 )
  {
    word_19B6C8[i + v4] = a1[i];
    if ( i == 15 )
    {
      if ( word_19B6E6 == -1 )
      {
        word_19B6E6 = 0;
        word_19B6E8 = 1;
      }
      else
      {
        word_19B6E8 = 0;
      }
      v4 = 1;
    }
  }
  JUMPOUT(0x590FF);
}
// 5B5A0: control flows out of bounds to 590FF
// 19B694: using guessed type int16_t word_19B694[];
// 19B6A6: using guessed type int16_t word_19B6A6;
// 19B6C8: using guessed type int16_t word_19B6C8[];
// 19B6E6: using guessed type int16_t word_19B6E6;
// 19B6E8: using guessed type int16_t word_19B6E8;


//----- (0005B5A5) --------------------------------------------------------
void __fastcall sub_5B5A5(int a1)
{
  int v2; // eax
  _BYTE *v3; // ebx
  _BYTE *v4; // edx
  int16_t v5; // [esp+0h] [ebp-4h]

  v5 = 0;
  v2 = 1;
  do
  {
    v3 = (_BYTE *)(a1 + (int16_t)v2);
    if ( *((_WORD *)&dword_19B690 + (int16_t)v2 + 1) )
      *v3 = byte_17D1F9[3 * (int16_t)v2 + *((int16_t *)&dword_19B690 + (int16_t)v2 + 1)];
    else
      *v3 = 0;
    ++v2;
  }
  while ( (int16_t)v2 < 10 );
  while ( (int16_t)v2 < 32 )
  {
    if ( (_WORD)v2 == 15 )
    {
      v4 = (_BYTE *)(a1 + 15);
      if ( word_19B6E6 == 1 )
      {
        *v4 = 1;
      }
      else if ( word_19B6E8 == 1 )
      {
        *v4 = -1;
      }
      else
      {
        *v4 = 0;
      }
      v5 = 1;
      ++v2;
    }
    else
    {
      *(_BYTE *)(a1 + (int16_t)v2 - v5) = word_19B6C8[(int16_t)v2];
    }
    ++v2;
  }
  JUMPOUT(0x5AEEE);
}
// 5B644: control flows out of bounds to 5AEEE
// 19B690: using guessed type int dword_19B690;
// 19B6C8: using guessed type int16_t word_19B6C8[];
// 19B6E6: using guessed type int16_t word_19B6E6;
// 19B6E8: using guessed type int16_t word_19B6E8;


//----- (0005B649) --------------------------------------------------------
void sub_5B649()
{
  int16_t v0; // bx
  int v1; // edx
  unsigned int v2; // ecx
  int16_t *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int16_t v10; // bx
  int v11; // eax
  int v12; // ebx
  int v13; // edx
  char *v14; // edi
  int16_t *v15; // edi
  int v16; // eax
  int v17; // eax
  int16_t v18; // si
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  int v22; // eax
  int v23; // eax
  int16_t i; // si
  _BOOL1 v25; // zf
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // esi
  char *v31; // [esp+0h] [ebp-F6h] BYREF
  int16_t v32[100]; // [esp+4h] [ebp-F2h] BYREF
  char v33[100]; // [esp+CCh] [ebp-2Ah] BYREF
  _BYTE v34[52]; // [esp+130h] [ebp+3Ah] BYREF
  int v35; // [esp+164h] [ebp+6Eh] BYREF
  int v36; // [esp+168h] [ebp+72h]
  int v37; // [esp+16Ch] [ebp+76h]
  int v38; // [esp+170h] [ebp+7Ah]
  int v39; // [esp+174h] [ebp+7Eh]

  sub_107AF(&v35);
  sub_C5BB9();
  sub_1205E6(9, 0, 255);
  sub_5B4CD(v31);
  sub_12779E(v34, v31, 0x1Fu);
  v0 = 1;
  while ( 1 )
  {
    v1 = 2;
    LOBYTE(v2) = 3;
    do
    {
      BYTE1(v2) = v34[v0];
      v3 = (int16_t *)(3 * v0 + (int16_t)v1);
      if ( BYTE1(v2) == byte_17D1FA[(_DWORD)v3] )
        v34[v0] = v2;
      --v1;
      LOBYTE(v2) = v2 - 1;
    }
    while ( (v1 & 0x8000u) == 0 );
    if ( ++v0 >= 10 )
    {
      sub_59FA1();
      sub_11C2F0();
      sub_5AEF4();
      v4 = sub_58FC3(v3);
      sub_59053(v4, v1, v0);
      word_19B766 += 4;
      LOWORD(v5) = word_19B766;
      v37 = v5;
      sub_1191CA((int)sub_596A5, 1);
      byte_19B688[0] = -114;
      byte_19B689 = -99;
      byte_19B68A = -100;
      v6 = 3;
      do
      {
        v7 = (int16_t)v6++;
        byte_19B688[v7] = -99;
      }
      while ( (int16_t)v6 < 8 );
      sub_120BB5(4, (int)byte_19B688);
      sub_5B14A((int)v34, v37);
      v8 = 0;
      do
      {
        v9 = (int16_t)v8;
        v10 = word_19B694[(int16_t)v8++];
        *(_WORD *)&v34[2 * v9 + 32] = v10;
      }
      while ( (int16_t)v8 < 10 );
      sub_124D7A();
      sub_59105();
      sub_124E36();
      sub_124D41();
      sub_596A5();
      sub_132C80(100);
      v11 = sub_131922(0, 255);
      sub_1077D(v11, 255, 100, v3);
      sub_C5C44();
      sub_58F1E(77, v33, 100);
      strcpy((char *)v32, v33);
      v12 = 100;
      v13 = (int)v33;
      sub_58F1E(78, v33, 100);
      v14 = (char *)&v31 + 3;
      do
        ++v14;
      while ( *v14 );
      strcpy(v14, v33);
      v15 = v32;
      v38 = 0;
      sub_77423((int)v32);
      sub_124D7A();
      sub_59105();
      sub_124E36();
      sub_124D41();
      sub_596A5();
      v17 = sub_1077D(v16, (int)v33, 100, v32);
      while ( !(_WORD)v38 )
      {
        word_19994C = 0;
        v18 = 0;
        v39 = sub_1171AB(v17, v13, v12, (uint16_t)v2);
        do
        {
          if ( (_WORD)v39 == word_19B714[v18] )
          {
            if ( (int)(v18 - (__CFSHL__((uint64_t)v18 >> 32, 2) + 4 * ((uint64_t)v18 >> 32))) >> 2 == 1
              && word_19B6EE == 1 )
            {
              sub_58F1E(73, (char *)v32, 120);
              sub_77433(v32);
              sub_124D7A();
              sub_59105();
              sub_124E36();
              sub_124D41();
              sub_596A5();
              sub_1077D(v19, (int)v32, 120, v15);
              word_19B696 = 0;
            }
            else
            {
              v20 = (int)(v18 - (__CFSHL__((uint64_t)v18 >> 32, 2) + 4 * ((uint64_t)v18 >> 32))) >> 2;
              v36 = *(int16_t *)&v34[v20 * 2 + 32];
              v21 = v18 % 4;
              HIWORD(v15) = HIWORD(v21);
              if ( v21 == v36 )
              {
                word_19B694[v20] = 0;
                sub_59053(v18 / 4, v21, v18);
                word_19B766 += 4;
              }
              else if ( word_19B76C
                      + *(char *)(dword_19B710
                                + v18
                                - ((v18 + 3 - (__CFSHL__((v18 + 3) >> 31, 2) + 4 * ((v18 + 3) >> 31))) >> 2)) >= -10 )
              {
                word_19B694[v20] = v21;
              }
              else
              {
                sub_58F1E(74, (char *)v32, 80);
                sub_77433(v32);
                sub_124D7A();
                sub_59105();
                sub_124E36();
                sub_124D41();
                sub_596A5();
                sub_1077D(v22, (int)v32, 80, (int16_t *)v21);
                word_19B694[v20] = *(_WORD *)&v34[v20 * 2 + 32];
              }
            }
            v23 = (int)(v18 - (__CFSHL__((uint64_t)v18 >> 32, 2) + 4 * ((uint64_t)v18 >> 32))) >> 2;
            v12 = 2 * v23;
            LOWORD(v15) = (char)v34[v23 + 1];
            if ( (int16_t)v15 > word_19B694[v23]
              && *(char *)(dword_19B710
                         + v18
                         - ((v18 + 3 - (__CFSHL__((v18 + 3) >> 31, 2) + 4 * ((v18 + 3) >> 31))) >> 2)) >= 0 )
            {
              word_19B694[v23] = (int16_t)v15;
            }
          }
          ++v18;
        }
        while ( v18 < 36 );
        for ( i = 0; i < 22; ++i )
        {
          v2 = 2 * i;
          v13 = v39;
          if ( (_WORD)v39 == word_19B6A8[v2 / 2] )
          {
            v13 = (uint16_t)(1 - word_19B6DC[i]);
            v25 = word_19B6DC[i] == 1;
            word_19B6DC[i] = v13;
            if ( v25 )
            {
              v13 = dword_19B710;
              if ( *(char *)(dword_19B710 + i + 31) < 0 )
                word_19B6DC[i] = 1;
              sub_59053(i, v13, v12);
              word_19B766 += 4;
            }
            else
            {
              sub_59053(i, v13, v12);
              word_19B766 += 4;
              if ( word_19B76C < -10 )
              {
                v12 = 80;
                v13 = (int)v32;
                sub_58F1E(74, (char *)v32, 80);
                sub_77433(v32);
                sub_124D7A();
                sub_59105();
                sub_124E36();
                sub_124D41();
                sub_596A5();
                sub_1077D(v26, (int)v32, 80, v15);
                word_19B6DC[i] = 0;
              }
              if ( i )
              {
                switch ( i )
                {
                  case 1:
                    word_19B6DC[0] = 0;
                    break;
                  case 9:
                    word_19B6EC = 0;
                    word_19B696 = 0;
                    break;
                  case 8:
                    word_19B6EE = 0;
                    break;
                  case 10:
                    word_19B6F2 = 0;
                    break;
                  case 11:
                    word_19B6F0 = 0;
                    break;
                  case 12:
                    word_19B6F6 = 0;
                    break;
                  case 13:
                    word_19B6F4 = 0;
                    break;
                }
              }
              else
              {
                word_19B6DE = 0;
              }
            }
          }
        }
        v27 = v39;
        if ( (_WORD)v39 == word_19B76E )
        {
          if ( word_19B766 >= 0 )
          {
            v38 = 1;
          }
          else
          {
            v12 = 80;
            v13 = (int)v32;
            sub_58F1E(75, (char *)v32, 80);
            sub_77433(v32);
            sub_124D7A();
            sub_59105();
            sub_124E36();
            sub_124D41();
            sub_596A5();
            v27 = sub_1077D(v28, (int)v32, 80, v15);
          }
        }
        sub_59053(v27, v13, v12);
        word_19B766 += 4;
        if ( word_19994C )
        {
          sub_124D7A();
          sub_59105();
          v17 = (int)sub_124E36();
        }
        if ( !(_WORD)v38 )
        {
          v13 = (int16_t)v37;
          sub_5B14A((int)v34, v37);
          sub_124D41();
          sub_596A5();
          sub_1077D(v29, v13, v12, v15);
          v30 = 0;
          do
          {
            v17 = (int16_t)v30;
            LOWORD(v13) = word_19B694[(int16_t)v30++];
            *(_WORD *)&v34[2 * v17 + 32] = v13;
          }
          while ( (int16_t)v30 < 10 );
        }
      }
      sub_5B5A5((int)v31);
      sub_1196F7();
      sub_119281();
      sub_107BA(&v35);
      sub_11C2F0();
      sub_1113CC(dword_192ED4, (int)&byte_199F28);
      sub_8F1C4((void (__fastcall *)(int, int))sub_84E9D, &byte_199F28, 0);
      JUMPOUT(0x59698);
    }
  }
}
// 5BC1F: control flows out of bounds to 59698
// 5B6F9: variable 'v5' is possibly undefined
// 5B81A: variable 'v16' is possibly undefined
// 5B833: variable 'v17' is possibly undefined
// 5B8A4: variable 'v19' is possibly undefined
// 5B960: variable 'v22' is possibly undefined
// 5BA6F: variable 'v26' is possibly undefined
// 5BB69: variable 'v28' is possibly undefined
// 5BBBE: variable 'v29' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 199F28: using guessed type char byte_199F28;
// 19B689: using guessed type char byte_19B689;
// 19B68A: using guessed type char byte_19B68A;
// 19B694: using guessed type int16_t word_19B694[];
// 19B696: using guessed type int16_t word_19B696;
// 19B6A8: using guessed type int16_t word_19B6A8[16];
// 19B6DC: using guessed type int16_t word_19B6DC[];
// 19B6DE: using guessed type int16_t word_19B6DE;
// 19B6EC: using guessed type int16_t word_19B6EC;
// 19B6EE: using guessed type int16_t word_19B6EE;
// 19B6F0: using guessed type int16_t word_19B6F0;
// 19B6F2: using guessed type int16_t word_19B6F2;
// 19B6F4: using guessed type int16_t word_19B6F4;
// 19B6F6: using guessed type int16_t word_19B6F6;
// 19B710: using guessed type int dword_19B710;
// 19B714: using guessed type int16_t word_19B714[41];
// 19B766: using guessed type int16_t word_19B766;
// 19B76C: using guessed type int16_t word_19B76C;
// 19B76E: using guessed type int16_t word_19B76E;


//----- (0005BC24) --------------------------------------------------------
int __fastcall sub_5BC24(int a1)
{
  int16_t i; // bx
  int result; // eax
  int v4; // edx
  char v5; // cl

  for ( i = 0; i < 9; ++i )
  {
    result = a1 + i;
    v4 = 3 * (i + 1);
    v5 = *(_BYTE *)(result + 1);
    if ( v5 == byte_17D1FA[v4] )
    {
      *(_BYTE *)(result + 1) = 1;
    }
    else if ( v5 == byte_17D1FB[v4] )
    {
      *(_BYTE *)(result + 1) = 2;
    }
    else if ( v5 == byte_17D1FC[v4] )
    {
      *(_BYTE *)(result + 1) = 3;
    }
    else
    {
      *(_BYTE *)(result + 1) = 0;
    }
  }
  return result;
}


//----- (0005BC74) --------------------------------------------------------
_DWORD *__fastcall sub_5BC74(int a1, int a2)
{
  int16_t i; // si
  int16_t *v3; // edi
  int v4; // ebx
  _DWORD *v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int16_t *v9; // edi
  int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *result; // eax
  _BYTE v13[4]; // [esp+0h] [ebp-4h] BYREF

  sub_1112EC(dword_192ED4, a2);
  for ( i = 0; i < 13; ++i )
  {
    v3 = (int16_t *)i;
    v4 = dword_192ED4;
    v5 = sub_126C37((int)aRacestufLbx_1, 7, dword_192ED4, i, 1u, 31);
    dword_19B7DC[(_DWORD)v3] = (int)v5;
    sub_FE8BE((int)v5, 7, v4, v3);
  }
  v6 = fopen(aLastraceRac);
  if ( v6 )
  {
    dword_19B810 = (int)sub_126C37((int)aRacestufLbx_1, 7, dword_192ED4, 0xCu, 1u, 31);
    fread(dword_19B810, 31, 1, v6);
    v7 = sub_5BC24(dword_19B810);
    sub_FE8BE(v7, 31, 1, v3);
    fread(v13, 1, 1, v6);
    v8 = fread(&unk_19B85C, 15, 1, v6);
    sub_FE8BE(v8, 15, 1, v3);
    fclose(v6);
  }
  v9 = 0;
  do
  {
    v10 = dword_192ED4;
    v11 = sub_126B42((int)aRaceselLbx, (int16_t)((_WORD)v9 + 1), dword_192ED4);
    dword_19B7A4[(int16_t)v9] = (int)v11;
    sub_FE8BE((int16_t)v9, (int)v11, v10, v9);
    v9 = (int16_t *)((char *)v9 + 1);
  }
  while ( (int16_t)v9 < 14 );
  result = sub_126B42((int)aPatch13Lbx, 1, dword_192ED4);
  dword_19B840 = (int)result;
  return result;
}
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 19B7A4: using guessed type int dword_19B7A4[13];
// 19B7DC: using guessed type int dword_19B7DC[13];
// 19B810: using guessed type int dword_19B810;
// 19B840: using guessed type int dword_19B840;


//----- (0005BD97) --------------------------------------------------------
void sub_5BD97()
{
  int v0; // eax
  int v1; // edx
  int16_t v2; // dx
  int v3; // ebx
  int16_t v4; // ax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int16_t v8; // cx
  int v9; // ecx
  _BYTE *v10; // eax
  int v11; // edx
  char *v12; // esi
  char *v13; // edi
  int v14; // eax
  int v15; // eax
  char *v16; // edi
  char *v17; // edi
  char *v18; // esi
  char *v19; // edi
  char *v20; // esi
  char *v21; // edi
  int v22; // eax
  _BYTE *v23; // [esp-4h] [ebp-CAh] BYREF
  _BYTE v24[200]; // [esp+0h] [ebp-C6h] BYREF
  char v25[100]; // [esp+C8h] [ebp+2h] BYREF
  _BYTE v26[8]; // [esp+12Ch] [ebp+66h] BYREF
  char v27[8]; // [esp+134h] [ebp+6Eh] BYREF
  int v28; // [esp+13Ch] [ebp+76h]
  int v29; // [esp+140h] [ebp+7Ah] BYREF
  int v30; // [esp+144h] [ebp+7Eh]

  v26[0] = 120;
  v0 = 1;
  do
  {
    v1 = (int16_t)v0++;
    v26[v1] = 124;
  }
  while ( (int16_t)v0 < 8 );
  v24[0] = 0;
  if ( word_19B856 )
  {
    v2 = 48;
    v3 = sub_127C27((int)aRaceselLbx, 29, dword_193174);
    v4 = 367;
  }
  else
  {
    v2 = 52;
    v3 = sub_127C27((int)aRaceselLbx, 33, dword_193174);
    v4 = 366;
  }
  sub_12A478(v4, v2, v3);
  if ( word_19B858 == word_19B85A )
  {
    if ( byte_19B848[word_19B858] )
    {
      sub_120CCB(4, (int)v26);
      sub_58F1E(72, v25, 100);
      HIBYTE(v3) = 0;
      sub_103915(2);
    }
    else
    {
      v3 = sub_127C27((int)aRaceselLbx, word_19B858 + 15, dword_193174);
      sub_12A478(54, 63, v3);
    }
  }
  else
  {
    word_19B820[word_19B858] = 0;
    v5 = word_19B85A;
    word_19B820[word_19B85A] = 1;
    if ( !byte_19B848[v5] )
    {
      HIBYTE(v3) = HIBYTE(dword_193174);
      v6 = sub_127C27((int)aRaceselLbx, v5 + 15, dword_193174);
      sub_12B79D(v6);
    }
  }
  HIBYTE(v23) = HIBYTE(v3);
  word_19B858 = word_19B85A;
  if ( (word_19B85A < 13 || !dword_19B810) && (word_19B85A == 13 || byte_19B848[word_19B85A])
    || (word_19B856 || word_19B85A == 13) && (word_19B856 != 1 || word_19B85A != 13) )
  {
LABEL_61:
    v22 = sub_127C27((int)aRaceselLbx, 0, dword_193174);
    sub_12A478(48, 58, v22);
    JUMPOUT(0x5C202);
  }
  v7 = 0;
  v8 = 1;
  v29 = 0;
  do
  {
    if ( *(_BYTE *)(dword_19B7DC[word_19B85A] + v8) )
      ++v7;
    ++v8;
  }
  while ( v8 < 10 );
  while ( v8 < 31 )
  {
    if ( *(_BYTE *)(dword_19B7DC[word_19B85A] + v8) )
      ++v7;
    ++v8;
  }
  v9 = 1;
  v30 = v7 + 1;
  while ( 1 )
  {
    v10 = (_BYTE *)((int16_t)v9 + dword_19B7DC[word_19B85A]);
    v28 = (int16_t)v9;
    if ( *v10 )
      break;
LABEL_49:
    if ( (int16_t)++v9 >= 10 )
    {
      while ( (int16_t)v9 < 31 )
      {
        if ( *(_BYTE *)((int16_t)v9 + dword_19B7DC[word_19B85A]) == 1 )
        {
          sub_5C20E((int16_t *)&v29, v30, (int)v24);
          v18 = (char *)dword_192190[(int16_t)v9];
          v23 = v24;
          v19 = (char *)&v23 + 3;
          do
            ++v19;
          while ( *v19 );
          strcpy(v19, v18);
        }
        LOWORD(v9) = v9 + 1;
      }
      sub_5C20E((int16_t *)&v29, v30, (int)v24);
      v20 = (char *)dword_192228[*(char *)dword_19B7DC[word_19B85A]];
      v23 = v24;
      v21 = (char *)&v23 + 3;
      do
        ++v21;
      while ( *v21 );
      strcpy(v21, v20);
      sub_120CCB(2, (int)v26);
      sub_120DED(0, 0);
      sub_103915(0);
      if ( word_19B85A == 13 )
      {
        sub_120CCB(4, (int)v26);
        sub_120DED(0, 0);
        sub_1210FD(197, 42, (int)&unk_19B85C);
      }
      goto LABEL_61;
    }
  }
  sub_5C20E((int16_t *)&v29, v30, (int)v24);
  v11 = 3 * v28;
  v12 = (char *)dword_192190[v28];
  v23 = v24;
  v13 = (char *)&v23 + 3;
  do
    ++v13;
  while ( *v13 );
  strcpy(v13, v12);
  if ( (_WORD)v9 == 5 )
  {
    if ( byte_17D1F9[v11 + *(char *)(v28 + dword_19B7DC[word_19B85A])] != 1 )
    {
      *(_WORD *)v27 = word_178F75;
      goto LABEL_42;
    }
LABEL_35:
    *(_DWORD *)v27 = dword_178F71;
LABEL_42:
    if ( byte_17D1F9[3 * (int16_t)v9 + *(char *)((int16_t)v9 + dword_19B7DC[word_19B85A])] > 0 )
    {
      v23 = v24;
      v16 = (char *)&v23 + 3;
      do
        ++v16;
      while ( *v16 );
      strcpy(v16, "+");
    }
    v23 = v24;
    v17 = (char *)&v23 + 3;
    do
      ++v17;
    while ( *v17 );
    strcpy(v17, v27);
    goto LABEL_49;
  }
  if ( (_WORD)v9 == 2 )
  {
    v14 = v11 + *(char *)(v28 + dword_19B7DC[word_19B85A]);
    if ( byte_17D1F9[v14] == 1 )
      goto LABEL_35;
    v15 = byte_17D1F9[v14] / 2;
  }
  else
  {
    v15 = byte_17D1F9[v11 + *(char *)(v28 + dword_19B7DC[word_19B85A])];
  }
  itoa(v15, v27, 10, v9);
  goto LABEL_42;
}
// 5C1FD: control flows out of bounds to 5C202
// 103915: using guessed type _DWORD __stdcall sub_103915(int16_t);
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 178F71: using guessed type int dword_178F71;
// 178F75: using guessed type int16_t word_178F75;
// 192190: using guessed type int dword_192190[31];
// 192228: using guessed type int dword_192228[];
// 193174: using guessed type int dword_193174;
// 19B7DC: using guessed type int dword_19B7DC[13];
// 19B810: using guessed type int dword_19B810;
// 19B820: using guessed type int16_t word_19B820[3];
// 19B856: using guessed type int16_t word_19B856;
// 19B858: using guessed type int16_t word_19B858;
// 19B85A: using guessed type int16_t word_19B85A;


//----- (0005C20E) --------------------------------------------------------
char __fastcall sub_5C20E(int16_t *a1, int a2, int a3)
{
  char *v3; // esi
  char *v4; // edi
  char v6[80]; // [esp+0h] [ebp-50h] BYREF

  if ( a2 == ++*a1 )
  {
    if ( a2 <= 1 )
      return (char)a1;
    v3 = v6;
    sub_58F1E(104, v6, 100);
  }
  else
  {
    if ( *a1 <= 1 )
      return (char)a1;
    v3 = (char *)&unk_178F79;
  }
  v4 = (char *)(a3 - 1);
  do
    ++v4;
  while ( *v4 );
  strcpy(v4, v3);
  return (char)a1;
}
// 5C257: variable 'a1' is possibly undefined


//----- (0005C25B) --------------------------------------------------------
int sub_5C25B()
{
  word_192C80[0] = 630;
  word_192C82[0] = 351;
  word_192C84[0] = 90;
  word_192C86[0] = 473;
  word_192C88[0] = 134;
  word_192C8A = 631;
  word_192C8C = 351;
  word_192C8E = 138;
  word_192C90 = 473;
  word_192C92 = 182;
  word_192C94 = 632;
  word_192C96 = 351;
  word_192C98 = 186;
  word_192C9A = 473;
  word_192C9C = 230;
  word_192C9E = 633;
  word_192CA0 = 351;
  word_192CA2 = 234;
  word_192CA4 = 473;
  word_192CA6 = 278;
  word_192CA8 = 634;
  word_192CAA = 351;
  word_192CAC = 282;
  word_192CAE = 473;
  word_192CB0 = 326;
  word_192CB2 = 635;
  word_192CB4 = 351;
  word_192CB6 = 330;
  word_192CB8 = 473;
  word_192CBA = 374;
  word_192CBC = 636;
  word_192CBE = 351;
  word_192CC0 = 378;
  word_192CC2 = 473;
  word_192CC4 = 422;
  word_192CC6 = 637;
  word_192CC8 = 477;
  word_192CCA = 90;
  word_192CCC = 599;
  word_192CCE = 134;
  word_192CD0 = 638;
  word_192CD2 = 477;
  word_192CD4 = 138;
  word_192CD6 = 599;
  word_192CD8 = 182;
  word_192CDA = 639;
  word_192CDC = 477;
  word_192CDE = 186;
  word_192CE0 = 599;
  word_192CE2 = 230;
  word_192CE4 = 640;
  word_192CE6 = 477;
  word_192CE8 = 234;
  word_192CEA = 599;
  word_192CEC = 278;
  word_192CEE = 641;
  word_192CF0 = 477;
  word_192CF2 = 282;
  word_192CF4 = 599;
  word_192CF6 = 326;
  word_192CF8 = 642;
  word_192CFA = 477;
  word_192CFC = 330;
  word_192CFE = 599;
  word_192D00 = 374;
  word_192D02 = 643;
  word_192D04 = 477;
  word_192D06 = 378;
  word_192D08 = 599;
  word_192D0A = 422;
  word_192D0C = 644;
  word_192D0E = 0;
  word_192D10 = 0;
  word_192D12 = 639;
  word_192D14 = 479;
  return sub_1196B8((int)word_192C80, 15);
}
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
// 192CC6: using guessed type int16_t word_192CC6;
// 192CC8: using guessed type int16_t word_192CC8;
// 192CCA: using guessed type int16_t word_192CCA;
// 192CCC: using guessed type int16_t word_192CCC;
// 192CCE: using guessed type int16_t word_192CCE;
// 192CD0: using guessed type int16_t word_192CD0;
// 192CD2: using guessed type int16_t word_192CD2;
// 192CD4: using guessed type int16_t word_192CD4;
// 192CD6: using guessed type int16_t word_192CD6;
// 192CD8: using guessed type int16_t word_192CD8;
// 192CDA: using guessed type int16_t word_192CDA;
// 192CDC: using guessed type int16_t word_192CDC;
// 192CDE: using guessed type int16_t word_192CDE;
// 192CE0: using guessed type int16_t word_192CE0;
// 192CE2: using guessed type int16_t word_192CE2;
// 192CE4: using guessed type int16_t word_192CE4;
// 192CE6: using guessed type int16_t word_192CE6;
// 192CE8: using guessed type int16_t word_192CE8;
// 192CEA: using guessed type int16_t word_192CEA;
// 192CEC: using guessed type int16_t word_192CEC;
// 192CEE: using guessed type int16_t word_192CEE;
// 192CF0: using guessed type int16_t word_192CF0;
// 192CF2: using guessed type int16_t word_192CF2;
// 192CF4: using guessed type int16_t word_192CF4;
// 192CF6: using guessed type int16_t word_192CF6;
// 192CF8: using guessed type int16_t word_192CF8;
// 192CFA: using guessed type int16_t word_192CFA;
// 192CFC: using guessed type int16_t word_192CFC;
// 192CFE: using guessed type int16_t word_192CFE;
// 192D00: using guessed type int16_t word_192D00;
// 192D02: using guessed type int16_t word_192D02;
// 192D04: using guessed type int16_t word_192D04;
// 192D06: using guessed type int16_t word_192D06;
// 192D08: using guessed type int16_t word_192D08;
// 192D0A: using guessed type int16_t word_192D0A;
// 192D0C: using guessed type int16_t word_192D0C;
// 192D0E: using guessed type int16_t word_192D0E;
// 192D10: using guessed type int16_t word_192D10;
// 192D12: using guessed type int16_t word_192D12;
// 192D14: using guessed type int16_t word_192D14;


//----- (0005C510) --------------------------------------------------------
void __usercall sub_5C510(int16_t *a1)
{
  int v1; // eax
  int v2; // ebx
  int v3; // ebx
  void *v4; // eax
  int16_t *v5; // edi
  int v6; // ecx
  int v7; // ebx
  int16_t v8; // dx
  int16_t v9; // ax
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v14; // esi
  int v15; // eax
  int16_t v16; // si
  int v17; // ebx
  void *v18; // eax
  int v19; // eax
  _BYTE *v20; // esi
  _BYTE *v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // edx
  int16_t v26; // ax
  int v27; // eax
  int v29; // eax
  _DWORD *v30; // eax
  int v31; // eax
  _WORD *v32; // ecx
  int16_t v33; // dx
  int16_t v34; // ax
  int v35; // esi
  int16_t v36; // ax
  int16_t v38; // ax
  _DWORD *v39; // eax
  int v40; // eax
  _WORD *v41; // ecx
  int16_t v42; // dx
  int16_t v43; // ax
  int v44; // eax
  int16_t *v45; // [esp-4h] [ebp-4Eh]
  char *v46; // [esp-4h] [ebp-4Eh]
  int v47; // [esp+0h] [ebp-4Ah]
  char v48[100]; // [esp+4h] [ebp-46h] BYREF
  _BYTE v49[32]; // [esp+68h] [ebp+1Eh] BYREF
  _WORD v50[12]; // [esp+88h] [ebp+3Eh]
  int16_t v51; // [esp+A0h] [ebp+56h]
  int16_t v52; // [esp+A2h] [ebp+58h]
  int16_t *v53; // [esp+A4h] [ebp+5Ah]
  _BYTE *v54; // [esp+A8h] [ebp+5Eh]
  char *v55; // [esp+ACh] [ebp+62h]
  int v56; // [esp+B0h] [ebp+66h]
  char *v57; // [esp+B4h] [ebp+6Ah]
  int v58; // [esp+B8h] [ebp+6Eh]
  unsigned int v59; // [esp+BCh] [ebp+72h]
  int v60; // [esp+C0h] [ebp+76h]
  int v61; // [esp+C4h] [ebp+7Ah]
  uint8_t v62[4]; // [esp+C8h] [ebp+7Eh] BYREF

  sub_113E92();
  sub_1196F7();
  sub_11C2F0();
  sub_C5BB9();
  sub_1205E6(9, 0, 255);
  word_19B856 = 0;
  word_19B85A = 3;
  v1 = 0;
  do
  {
    v2 = (int16_t)v1++;
    word_19B820[v2] = 0;
  }
  while ( (int16_t)v1 < 14 );
  word_19B826 = 1;
  sub_5BC74(v1, 0);
  sub_5C25B();
  sub_124D7A();
  v3 = sub_127C27((int)aRaceoptLbx, 0, dword_193174);
  sub_FE8BE(v3, 0, v3, a1);
  sub_12A478(0, 0, v3);
  v4 = sub_124E36();
  if ( (uint8_t)byte_199F3A > 1u )
  {
    v59 = -1000;
  }
  else
  {
    v4 = (void *)sub_114C72(asc_178F88, 0);
    v59 = (unsigned int)v4;
  }
  sub_FE8BE((int)v4, 0, v3, a1);
  LOWORD(v60) = 0;
  do
  {
    v5 = (int16_t *)(2 * (int16_t)v60);
    v56 = (int16_t)(48 * ((int16_t)v60 % 7) + 90);
    v6 = dword_19B7A4[(int16_t)v60];
    v7 = (int)&unk_178F8A;
    v8 = 48 * ((int16_t)v60 % 7) + 90;
    v9 = 126 * ((int16_t)v60 / 7) + 351;
    LOWORD(v60) = v60 + 1;
    *(_WORD *)((char *)v50 + (_DWORD)v5) = sub_11523B(
                                             v9,
                                             v8,
                                             (int)&unk_178F8A,
                                             (_WORD *)v6,
                                             (int)word_19B820 + (_DWORD)v5,
                                             &unk_178F8A,
                                             40);
  }
  while ( (int16_t)v60 < 14 );
  sub_1191CA((int)sub_5BD97, 2);
  word_19B858 = 0;
  sub_124D41();
  sub_5BD97();
  v10 = 255;
  sub_132C80(100);
  v11 = sub_131922(0, 255);
  sub_1077D(v11, 255, (int)&unk_178F8A, v5);
  sub_C5C44();
  v57 = (char *)(v47 + 21);
  v54 = (_BYTE *)(v47 + 2207);
  v53 = (int16_t *)(v47 + 38);
  v12 = v47 + 1;
  v58 = 0;
  v55 = (char *)(v47 + 1);
  while ( 1 )
  {
    if ( (_WORD)v58 )
    {
      sub_11C2F0();
      sub_119281();
      sub_1113CC(dword_192ED4, 1);
      sub_C5BB9();
LABEL_95:
      JUMPOUT(0x5BD91);
    }
    v61 = sub_1171AB(v12, v10, v7, v6);
    word_19B85A = (uint16_t)sub_114177() - v50[0];
    if ( (uint16_t)word_19B85A >= 0xEu )
      word_19B85A = word_19B858;
    LOWORD(v60) = 0;
    while ( (int16_t)v60 < 13 )
    {
      v10 = v61;
      if ( (_WORD)v61 == v50[(int16_t)v60] && !byte_19B848[(int16_t)v60] )
      {
        if ( word_19B856 )
        {
          if ( (uint8_t)byte_199F3A > 1u && !sub_FBEE1(v60, v61, v7, v5) )
          {
LABEL_58:
            sub_58F1E(72, v48, 100);
            sub_77423((int)v48);
            sub_124D7A();
            v7 = sub_127C27((int)aRaceoptLbx, 0, dword_193174);
            v10 = 0;
            sub_12A478(0, 0, v7);
            sub_124E36();
            goto LABEL_59;
          }
          v6 = (int16_t)v60;
          v7 = 31;
          sub_12779E(v54, (_BYTE *)dword_19B7DC[(int16_t)v60], 0x1Fu);
          v10 = v47;
          *(_BYTE *)(v47 + 37) = v60;
          v46 = v57;
          strcpy(v57, (char *)dword_192630[v6]);
          v5 = (int16_t *)v46;
          sub_119281();
          sub_11C2F0();
          sub_5A3BC(v47, v47, 31, v6);
          if ( (_WORD)v29 == 1 )
          {
            v58 = v29;
            byte_19B848[v6] = 1;
          }
          else
          {
            if ( (uint8_t)byte_199F3A < 2u )
              byte_19B848[(int16_t)v60] = 0;
            else
              sub_FBF76(v60);
            v30 = sub_1113CC(dword_192ED4, v47);
            sub_5BC74((int)v30, v47);
            sub_124D7A();
            v31 = sub_127C27((int)aRaceoptLbx, 0, dword_193174);
            sub_12A478(0, 0, v31);
            sub_124E36();
            if ( (uint8_t)byte_199F3A > 1u )
              v59 = -1000;
            else
              v59 = sub_114C72(asc_178F88, 0);
            LOWORD(v60) = 0;
            do
            {
              v5 = (int16_t *)(2 * (int16_t)v60);
              v56 = (int16_t)(48 * ((int16_t)v60 % 7) + 90);
              v32 = (_WORD *)dword_19B7A4[(int16_t)v60];
              v33 = 48 * ((int16_t)v60 % 7) + 90;
              v34 = 126 * ((int16_t)v60 / 7) + 351;
              LOWORD(v60) = v60 + 1;
              *(_WORD *)((char *)v50 + (_DWORD)v5) = sub_11523B(
                                                       v34,
                                                       v33,
                                                       (int)&unk_178F8A,
                                                       v32,
                                                       (int)word_19B820 + (_DWORD)v5,
                                                       &unk_178F8A,
                                                       40);
            }
            while ( (int16_t)v60 < 13 );
            v7 = (int)&unk_178F8A;
            v6 = dword_19B7D8;
            v10 = 2;
            v52 = sub_11523B(
                    477,
                    378,
                    (int)&unk_178F8A,
                    (_WORD *)dword_19B7D8,
                    (int)&word_19B820[(int16_t)v60],
                    &unk_178F8A,
                    40);
            sub_1191CA((int)sub_5BD97, 2);
            sub_5C25B();
            word_19B856 = 0;
          }
        }
        else
        {
          if ( (uint8_t)byte_199F3A > 1u && !sub_FBEE1(v60, v61, v7, v5) )
            goto LABEL_58;
          sub_12C2A0();
          v14 = (int16_t)v60;
          sub_12C2C6(5);
          sub_11C2F0();
          sub_12779E(v54, (_BYTE *)dword_19B7DC[v14], 0x1Fu);
          *(_BYTE *)(v47 + 37) = v60;
          v45 = (int16_t *)v57;
          strcpy(v57, (char *)dword_192630[v14]);
          v5 = v45;
          sub_1196F7();
          do
          {
            v15 = sub_5D2BB(v55, (int16_t)v60, v45);
            v16 = v15;
            v6 = v15;
            sub_124D7A();
            v17 = sub_127C27((int)aRaceoptLbx, 0, dword_193174);
            sub_12A478(0, 0, v17);
            v18 = sub_124E36();
            sub_1077D((int)v18, 0, v17, v45);
            word_19B858 = v60;
            if ( v16 == 1 )
            {
              sub_5D03C(v53, 0, v17);
              v6 += v19;
              if ( (_WORD)v6 != 2 )
                sub_5BC74(v19, 0);
            }
          }
          while ( (_WORD)v6 == 1 );
          if ( (_WORD)v6 == 2 )
          {
            v20 = v54;
            v10 = 1;
            do
            {
              v7 = (int16_t)v10;
              v21 = &v20[(int16_t)v10];
              if ( *v21 )
              {
                v7 = 3 * (int16_t)v10;
                v6 = (char)*v21;
                LOBYTE(v7) = byte_17D1F9[v6 + v7];
                *v21 = v7;
              }
              else
              {
                *v21 = 0;
              }
              ++v10;
            }
            while ( (int16_t)v10 < 10 );
            v58 = 1;
            byte_19B848[(int16_t)v60] = 1;
          }
          else
          {
            if ( (uint8_t)byte_199F3A < 2u )
              byte_19B848[(int16_t)v60] = 0;
            else
              sub_FBF76(v60);
            sub_5C25B();
            sub_124D7A();
            v22 = sub_127C27((int)aRaceoptLbx, 0, dword_193174);
            sub_12A478(0, 0, v22);
            sub_124E36();
            word_19B858 = 0;
            v23 = 0;
            do
            {
              v24 = (int16_t)v23++;
              word_19B820[v24] = 0;
            }
            while ( (int16_t)v23 < 14 );
            word_19B820[word_19B85A] = 1;
            if ( (uint8_t)byte_199F3A > 1u )
              v59 = -1000;
            else
              v59 = sub_114C72(asc_178F88, v23);
            LOWORD(v60) = 0;
            do
            {
              v5 = (int16_t *)(2 * (int16_t)v60);
              v56 = (int16_t)(48 * ((int16_t)v60 % 7) + 90);
              v6 = dword_19B7A4[(int16_t)v60];
              v7 = (int)&unk_178F8A;
              v25 = v56;
              v26 = 126 * ((int16_t)v60 / 7) + 351;
              LOWORD(v60) = v60 + 1;
              *(_WORD *)((char *)v50 + (_DWORD)v5) = sub_11523B(
                                                       v26,
                                                       v56,
                                                       (int)&unk_178F8A,
                                                       (_WORD *)v6,
                                                       (int)word_19B820 + (_DWORD)v5,
                                                       &unk_178F8A,
                                                       40);
            }
            while ( (int16_t)v60 < 14 );
            sub_124D41();
            sub_5BD97();
            sub_1077D(v27, v25, (int)&unk_178F8A, v5);
            v10 = 2;
            sub_1191CA((int)sub_5BD97, 2);
          }
        }
      }
LABEL_59:
      LOWORD(v60) = v60 + 1;
    }
    if ( (_WORD)v61 == (_WORD)v59 )
    {
      if ( word_19B856 != 1 )
      {
        sub_11C2F0();
        sub_119281();
        sub_1113CC(dword_192ED4, v10);
        goto LABEL_95;
      }
      word_19B856 = 0;
      sub_119400(v51);
      v7 = (int)&unk_178F8A;
      v10 = 378;
      v6 = dword_19B7D8;
      v52 = sub_11523B(477, 378, (int)&unk_178F8A, (_WORD *)dword_19B7D8, (int)&unk_19B83A, &unk_178F8A, 40);
    }
    v12 = v61;
    if ( (_WORD)v61 == v52 )
    {
      v10 = (int)aRb_0;
      v12 = fopen(aLastraceRac);
      v35 = v12;
      v5 = (int16_t *)v12;
      if ( word_19B856 )
      {
        if ( v12 )
        {
          fread(v49, 31, 1, v12);
          sub_12779E(v54, (_BYTE *)dword_19B810, 0x1Fu);
          v6 = v35;
          fread(v62, 1, 1, v35);
          *(_BYTE *)(v47 + 37) = v62[0];
          if ( (uint8_t)byte_199F3A <= 1u || sub_FBEE1(v60, v47, 1, v5) )
          {
            v7 = 1;
            v10 = 15;
            v6 = (int)v5;
            fread(v57, 15, 1, v5);
            sub_119281();
            sub_11C2F0();
            word_19B858 = v62[0];
            fclose(v5);
            sub_5A3BC(v47, 15, 1, (int)v5);
            if ( v38 == 1 )
            {
              v12 = v62[0];
              v58 = 1;
              byte_19B848[v62[0]] = 1;
            }
            else
            {
              if ( (uint8_t)byte_199F3A < 2u )
                byte_19B848[v62[0]] = 0;
              else
                sub_FBF76(v62[0]);
              v39 = sub_1113CC(dword_192ED4, 15);
              sub_5BC74((int)v39, 15);
              sub_124D7A();
              v40 = sub_127C27((int)aRaceoptLbx, 0, dword_193174);
              sub_12A478(0, 0, v40);
              sub_124E36();
              if ( (uint8_t)byte_199F3A > 1u )
                v59 = -1000;
              else
                v59 = sub_114C72(asc_178F88, 0);
              LOWORD(v60) = 0;
              do
              {
                v5 = (int16_t *)(2 * (int16_t)v60);
                v56 = (int16_t)(48 * ((int16_t)v60 % 7) + 90);
                v41 = (_WORD *)dword_19B7A4[(int16_t)v60];
                v42 = 48 * ((int16_t)v60 % 7) + 90;
                v43 = 126 * ((int16_t)v60 / 7) + 351;
                LOWORD(v60) = v60 + 1;
                *(_WORD *)((char *)v50 + (_DWORD)v5) = sub_11523B(
                                                         v43,
                                                         v42,
                                                         (int)&unk_178F8A,
                                                         v41,
                                                         (int)word_19B820 + (_DWORD)v5,
                                                         &unk_178F8A,
                                                         40);
              }
              while ( (int16_t)v60 < 13 );
              v7 = (int)&unk_178F8A;
              v6 = dword_19B7D8;
              v10 = 2;
              v52 = sub_11523B(477, 378, (int)&unk_178F8A, (_WORD *)dword_19B7D8, (int)&unk_19B83A, &unk_178F8A, 40);
              sub_1191CA((int)sub_5BD97, 2);
              v12 = sub_5C25B();
              word_19B856 = 0;
            }
          }
          else
          {
            fclose(v5);
            sub_58F1E(72, v48, 100);
            sub_77423((int)v48);
            sub_124D7A();
            v7 = sub_127C27((int)aRaceoptLbx, 0, dword_193174);
            v10 = 0;
            sub_12A478(0, 0, v7);
            v12 = (int)sub_124E36();
          }
        }
      }
      else
      {
        word_19B856 = 1;
        LOWORD(v12) = sub_119400(v51);
        if ( v35 )
        {
          v10 = 378;
          v36 = 477;
          v6 = dword_19B840;
          v7 = (int)&word_199A08;
          if ( (char)word_199A08 < 15 )
          {
            v7 = (int)&unk_178F8A;
            v36 = sub_11523B(477, 378, (int)&unk_178F8A, (_WORD *)dword_19B840, (int)&unk_19B83A, &unk_178F8A, 40);
          }
          v52 = v36;
          v12 = fclose(v35);
        }
        else
        {
          v52 = -1000;
        }
      }
    }
    if ( !(_WORD)v58 )
    {
      if ( word_19994C )
      {
        sub_124D7A();
        v6 = 479;
        sub_128C32(0, 0, 639, 479, 0);
        v7 = sub_127C27((int)aRaceoptLbx, 0, dword_193174);
        v10 = 0;
        sub_12A478(0, 0, v7);
        sub_124E36();
        word_19994C = 0;
      }
      sub_124D41();
      sub_5BD97();
      v12 = sub_1077D(v44, v10, v7, v5);
    }
  }
}
// 5C209: control flows out of bounds to 5BD91
// 5C683: variable 'v47' is possibly undefined
// 5C6B3: variable 'v12' is possibly undefined
// 5C7E0: variable 'v19' is possibly undefined
// 5C956: variable 'v27' is possibly undefined
// 5C9E0: variable 'v29' is possibly undefined
// 5CD12: variable 'v38' is possibly undefined
// 5CF08: variable 'v44' is possibly undefined
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 192630: using guessed type int dword_192630[];
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 19994C: using guessed type int16_t word_19994C;
// 199A08: using guessed type int16_t word_199A08;
// 199F3A: using guessed type char byte_199F3A;
// 19B7A4: using guessed type int dword_19B7A4[13];
// 19B7D8: using guessed type int dword_19B7D8;
// 19B7DC: using guessed type int dword_19B7DC[13];
// 19B810: using guessed type int dword_19B810;
// 19B820: using guessed type int16_t word_19B820[3];
// 19B826: using guessed type int16_t word_19B826;
// 19B840: using guessed type int dword_19B840;
// 19B856: using guessed type int16_t word_19B856;
// 19B858: using guessed type int16_t word_19B858;
// 19B85A: using guessed type int16_t word_19B85A;


//----- (0005CF37) --------------------------------------------------------
void sub_5CF37()
{
  int v0; // eax
  int16_t v1; // cx
  int v2; // eax
  int16_t v3; // [esp+0h] [ebp-4h]

  v0 = sub_127C27((int)aRaceselLbx_0, 32, dword_193174);
  v1 = 0;
  sub_12A478(55, 67, v0);
  while ( 1 )
  {
    if ( !byte_19B814[v1] )
    {
      if ( v1 == 3 || v1 == 7 )
        v3 = -1;
      else
        v3 = 0;
      v2 = sub_127C27((int)aRaceselLbx_0, 8 * word_19B858 + v1 + 34, dword_193174);
      sub_12A478(
        124 * (v1 % 4) + v3 + 96,
        136 * ((int)(v1 - (__CFSHL__((uint64_t)v1 >> 32, 2) + 4 * ((uint64_t)v1 >> 32))) >> 2) + 145,
        v2);
    }
    if ( ++v1 >= 8 )
      JUMPOUT(0x5BD90);
  }
}
// 5CFFA: control flows out of bounds to 5BD90
// 193174: using guessed type int dword_193174;
// 19B858: using guessed type int16_t word_19B858;


//----- (0005D03C) --------------------------------------------------------
void __fastcall sub_5D03C(int16_t *a1, int a2, int a3)
{
  int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // esi
  int16_t v10; // ax
  int16_t v11; // dx
  unsigned int v12; // eax
  int16_t v13; // si
  int16_t v14; // cx
  int v16; // eax
  int v17; // eax
  char v18[96]; // [esp+0h] [ebp-74h] BYREF
  int v19; // [esp+60h] [ebp-14h]
  int v20; // [esp+64h] [ebp-10h]
  int v21; // [esp+68h] [ebp-Ch]
  int16_t i; // [esp+6Ch] [ebp-8h]
  int v23; // [esp+70h] [ebp-4h]

  sub_1077D((int)a1, a2, a3, a1);
  v4 = dword_193174;
  v5 = sub_127C27((int)aRaceselLbx_0, 32, dword_193174);
  v6 = sub_12B79D(v5);
  sub_1077D(v6, 32, v4, a1);
  v23 = 0;
  sub_1191CA((int)sub_5CF37, 2);
  word_192C80[0] = 676;
  word_192C82[0] = 0;
  word_192C84[0] = 0;
  word_192C86[0] = 639;
  v7 = 1;
  word_192C88[0] = 479;
  sub_1196B8((int)word_192C80, 1);
  while ( !(_WORD)v23 )
  {
    sub_11C2F0();
    for ( i = 0; i < 8; ++i )
    {
      if ( i == 3 || i == 7 )
        v8 = -1;
      else
        v8 = 0;
      v4 = i;
      if ( byte_19B814[i] )
      {
        *(_WORD *)&v18[2 * i + 80] = -1000;
      }
      else
      {
        v20 = 136 * ((int)(i - (__CFSHL__((uint64_t)i >> 32, 2) + 4 * ((uint64_t)i >> 32))) >> 2);
        v19 = (int16_t)(v20 + 242);
        v10 = v8;
        v21 = 124 * (i % 4);
        v11 = v8 + 179;
        v8 = v19;
        v4 = (int16_t)(v21 + v11);
        v7 = (int16_t)(v20 + 144);
        v9 = 2 * i;
        *(_WORD *)&v18[v9 + 80] = sub_11438B(v21 + v10 + 96, v7, v4, v19, &unk_178F8A, 41);
      }
    }
    i = 0;
    v12 = sub_114C72(asc_178F88, v7);
    v13 = v12;
    v14 = sub_1171AB(v12, v7, v4, v8);
    do
    {
      if ( v14 == *(_WORD *)&v18[2 * i + 80] )
      {
        if ( (uint8_t)byte_199F3A <= 1u || sub_FBE75(i, a1) )
        {
          *(_BYTE *)a1 = i;
          v23 = 1;
          byte_19B814[i] = 1;
        }
        else
        {
          v4 = 80;
          v7 = (int)v18;
          sub_58F1E(105, v18, 80);
          sub_77423((int)v18);
        }
      }
      ++i;
    }
    while ( i < 8 );
    if ( v14 == v13 )
    {
      sub_11C2F0();
      sub_119281();
      word_1999AA = 0;
      goto LABEL_26;
    }
    if ( !(_WORD)v23 )
    {
      sub_124D41();
      sub_5CF37();
      sub_1077D(v16, v7, v4, a1);
    }
  }
  sub_11C2F0();
  sub_119281();
  word_17CF82 = 7;
  sub_123E6C((int)&word_17CF82, 1);
  sub_124D41();
  sub_5CF37();
  sub_1077D(v17, 1, v4, a1);
LABEL_26:
  JUMPOUT(0x5BD90);
}
// 5D214: control flows out of bounds to 5BD90
// 5D22E: variable 'v16' is possibly undefined
// 5D264: variable 'v17' is possibly undefined
// 17CF82: using guessed type int16_t word_17CF82;
// 192C80: using guessed type int16_t word_192C80[];
// 192C82: using guessed type int16_t word_192C82[];
// 192C84: using guessed type int16_t word_192C84[];
// 192C86: using guessed type int16_t word_192C86[];
// 192C88: using guessed type int16_t word_192C88[];
// 193174: using guessed type int dword_193174;
// 1999AA: using guessed type int16_t word_1999AA;
// 199F3A: using guessed type char byte_199F3A;


//----- (0005D273) --------------------------------------------------------
int sub_5D273()
{
  int v0; // eax
  int result; // eax

  if ( word_19994C )
  {
    sub_124D41();
    sub_128C32(0, 0, 639, 479, 0);
    v0 = sub_127C27((int)aRaceoptLbx, 0, dword_193174);
    return sub_12A478(0, 0, v0);
  }
  return result;
}
// 193174: using guessed type int dword_193174;
// 19994C: using guessed type int16_t word_19994C;


//----- (0005D2BB) --------------------------------------------------------
int __usercall sub_5D2BB(char *a1, int a2, int16_t *a3)
{
  int v3; // eax
  int16_t v4; // ax
  int16_t v5; // ax
  uint8_t v6; // al
  char *v7; // esi
  int v8; // edx
  int16_t v10; // [esp-4h] [ebp-6Ch]
  char v12[80]; // [esp+4h] [ebp-64h] BYREF
  char v13[20]; // [esp+54h] [ebp-14h] BYREF

  LOWORD(v3) = sub_11C2F0();
  sub_1077D(v3, a2, a2, a3);
  sub_1191CA((int)sub_5D273, 1);
  sub_1112EC(dword_192ED4, 1);
  v4 = sub_1247A0(8u);
  dword_19B81C = (int)sub_126C37((int)aRacenameLbx_0, 0, dword_192ED4, (int16_t)(8 * a2 + v4 - 1), 1u, 20);
  strcpy(v13, (char *)dword_19B81C);
  sub_58F1E(106, v12, 80);
  v10 = sub_923C4();
  v5 = sub_923BE();
  HIWORD(v8) = 0;
  v6 = sub_91BB4((char *)dword_19B81C, 20, 102, v12, v5, v10);
  v7 = (char *)dword_19B81C;
  LOWORD(v8) = v6;
  if ( !*(_BYTE *)dword_19B81C )
    v7 = v13;
  strcpy(a1, v7);
  sub_1113CC(dword_192ED4, v8);
  sub_11C2F0();
  return v8;
}
// 5D2CB: variable 'v3' is possibly undefined
// 192ED4: using guessed type int dword_192ED4;
// 19B81C: using guessed type int dword_19B81C;


//----- (0005D393) --------------------------------------------------------
bool __fastcall sub_5D393( int a1, int a2)
{
  int v2; // esi
  int v3; // ecx

  v2 = 129 * a1;
  v3 = 0;
  if ( (uint16_t)sub_1276F0(v2 + dword_197F9C + 23, a2) )
    return (uint16_t)sub_1276F0(v2 + dword_197F9C + 118, a2) == 0;
  return v3;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (0005D3DB) --------------------------------------------------------
char __fastcall sub_5D3DB( int a1)
{
  char v2; // cl

  v2 = 0;
  if ( sub_5D393(a1, 31) || sub_5D393(a1, 6) || sub_5D393(a1, 23) )
    return 1;
  return v2;
}


//----- (0005D41E) --------------------------------------------------------
void sub_5D41E()
{
  int16_t v0; // bx
  _BYTE *v1; // eax
  int16_t i; // bx
  int16_t j; // bx
  int16_t k; // di
  int v5; // edx
  int v6; // eax
  int16_t m; // ax
  int16_t v8; // dx
  int v9; // eax
  int16_t v10; // dx
  int v11; // eax
  int16_t n; // dx
  _DWORD *v13; // [esp+0h] [ebp-10h]
  int16_t v14; // [esp+8h] [ebp-8h]
  char v15; // [esp+Ch] [ebp-4h]

  v0 = 0;
  v13 = sub_110CEE(dword_192EE8, 500);
  while ( v0 < word_199994 )
  {
    v1 = (char *)v13 + v0++;
    *v1 = 0;
  }
  word_199A02 = 0;
  word_1999F6 = 0;
  for ( i = 0; i < word_199994; ++i )
  {
    if ( *(char *)(dword_197F9C + 129 * i + 100) >= 3 )
      *((_BYTE *)v13 + i) = 1;
  }
  for ( j = 0; j < word_199994; ++j )
  {
    if ( *((_BYTE *)v13 + j) != 1 )
    {
      v15 = 0;
      for ( k = 0; k < word_199A02 && !v15; ++k )
      {
        v5 = dword_197F9C + 129 * j;
        v6 = 129 * *(int16_t *)((char *)&word_1975D4 + 5 * word_192248[k]) + dword_197F9C;
        if ( *(_WORD *)(v5 + 101) == *(_WORD *)(v6 + 101)
          && *(_WORD *)(v5 + 103) == *(_WORD *)(v6 + 103)
          && *(_WORD *)(v5 + 105) == *(_WORD *)(v6 + 105)
          && *(_BYTE *)(v5 + 99) == *(_BYTE *)(v6 + 99) )
        {
          for ( m = word_192248[k]; m != -1; m = *(int16_t *)((char *)&word_1975D6 + 5 * m) )
            v14 = m;
          v8 = word_1999F6;
          *(int16_t *)((char *)&word_1975D6 + 5 * v14) = word_1999F6;
          v9 = 5 * v8;
          *(int16_t *)((char *)&word_1975D6 + v9) = -1;
          v15 = 1;
          byte_1975D8[v9] = 0;
          ++word_1999F6;
          *(int16_t *)((char *)&word_1975D4 + v9) = j;
        }
      }
      if ( !v15 )
      {
        v10 = word_1999F6;
        word_192248[word_199A02] = word_1999F6;
        v11 = 5 * v10;
        *(int16_t *)((char *)&word_1975D6 + v11) = -1;
        ++word_1999F6;
        byte_1975D8[v11] = 0;
        ++word_199A02;
        *(int16_t *)((char *)&word_1975D4 + v11) = j;
      }
    }
  }
  if ( !*(_BYTE *)(dword_197F98 + 3753 * word_19999C + 2234) )
    sub_5D953();
  for ( n = 0; n < word_199A02; ++n )
    sub_5DDE0(word_192248[n]);
}
// 5D52B: variable 'v14' is possibly undefined
// 192248: using guessed type int16_t word_192248[500];
// 192EE8: using guessed type int dword_192EE8;
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999C: using guessed type int16_t word_19999C;
// 1999F6: using guessed type int16_t word_1999F6;
// 199A02: using guessed type int16_t word_199A02;


//----- (0005D618) --------------------------------------------------------
void sub_5D618()
{
  int16_t i; // si
  int16_t j; // cx
  int v2; // edx
  int16_t v3; // ax
  int16_t v4; // di
  int v5; // ecx

  for ( i = 0; i < word_199A02; ++i )
  {
    for ( j = 0; j < 15; ++j )
    {
      v2 = j;
      sub_121CE5(15 * i, v2, (int)asc_178FA4);
    }
    v3 = word_192248[i];
    v4 = 0;
    do
    {
      v5 = 5 * v3;
      sub_121D19(15 * i, v4, *(int16_t *)((char *)&word_1975D4 + v5), v5);
      v3 = *(int16_t *)((char *)&word_1975D6 + v5);
      ++v4;
    }
    while ( v3 != -1 && v4 < 20 );
  }
  sub_6497C();
  JUMPOUT(0x5D612);
}
// 5D687: control flows out of bounds to 5D612
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 199A02: using guessed type int16_t word_199A02;


//----- (0005D689) --------------------------------------------------------
int16_t __fastcall sub_5D689( int a1, int a2, int a3)
{
  int16_t v3; // si
  int16_t i; // dx
  int v5; // eax
  int16_t v6; // ax
  int v7; // ebx
  int16_t v8; // dx
  int16_t v9; // di
  int16_t v10; // si
  int v11; // ebx
  int v12; // ecx
  int v13; // ebx
  int v14; // ecx
  int16_t v19; // [esp+Ch] [ebp-8h]
  int16_t v20; // [esp+10h] [ebp-4h]

  v3 = -1;
  for ( i = 0; i < a3; ++i )
  {
    v19 = 1;
    v5 = a1;
    v20 = -1;
LABEL_3:
    v6 = word_192248[v5];
    while ( v6 != -1 && v19 == 1 )
    {
      if ( v6 == *(_WORD *)(a2 + 2 * i) )
      {
        v19 = 0;
        if ( v6 == word_192248[a1] )
          word_192248[a1] = *(int16_t *)((char *)&word_1975D6 + 5 * v6);
        else
          *(int16_t *)((char *)&word_1975D6 + 5 * v20) = *(int16_t *)((char *)&word_1975D6 + 5 * v6);
        if ( v3 == -1 )
        {
          v3 = v6;
          word_192248[word_199A02] = v6;
        }
        else
        {
          v7 = 5 * v3;
          v3 = v6;
          *(int16_t *)((char *)&word_1975D6 + v7) = v6;
        }
        *(int16_t *)((char *)&word_1975D6 + 5 * v6) = -1;
        if ( v20 == -1 )
        {
          v5 = a1;
          goto LABEL_3;
        }
        v6 = *(int16_t *)((char *)&word_1975D6 + 5 * v20);
      }
      else
      {
        v20 = v6;
        v6 = *(int16_t *)((char *)&word_1975D6 + 5 * v6);
      }
    }
  }
  if ( v3 == -1 )
    return -1;
  v8 = word_192248[word_199A02];
  v9 = -1;
  v10 = v8;
  while ( v8 != -1 )
  {
    v9 = v8;
    v10 = -1;
    v8 = *(int16_t *)((char *)&word_1975D6 + 5 * v8);
  }
  while ( v8 != -1 )
  {
    v11 = word_199A02;
    if ( v10 == word_192248[v11] )
    {
      v12 = 5 * v9;
      *(int16_t *)((char *)&word_1975D6 + v12) = *(int16_t *)((char *)&word_1975D6 + 5 * v8);
      *(int16_t *)((char *)&word_1975D6 + 5 * v8) = word_192248[v11];
      word_192248[v11] = v8;
      v10 = v8;
      v8 = *(int16_t *)((char *)&word_1975D6 + v12);
    }
    else
    {
      v13 = 5 * v9;
      *(int16_t *)((char *)&word_1975D6 + v13) = *(int16_t *)((char *)&word_1975D6 + 5 * v8);
      v14 = 5 * v10;
      *(int16_t *)((char *)&word_1975D6 + 5 * v8) = *(int16_t *)((char *)&word_1975D6 + v14);
      *(int16_t *)((char *)&word_1975D6 + v14) = v8;
      v10 = v8;
      v8 = *(int16_t *)((char *)&word_1975D6 + v13);
    }
  }
  return word_199A02++;
}
// 192248: using guessed type int16_t word_192248[500];
// 1975D6: using guessed type int16_t word_1975D6;
// 199A02: using guessed type int16_t word_199A02;


//----- (0005D87C) --------------------------------------------------------
void __fastcall sub_5D87C( int a1, int a2)
{
  int16_t i; // ax
  int v3; // eax

  for ( i = word_192248[a1]; i != -1; i = *(int16_t *)((char *)&word_1975D6 + v3) )
  {
    v3 = 5 * i;
    *(_WORD *)(dword_197F9C + 129 * *(int16_t *)((char *)&word_1975D4 + v3) + 101) = a2;
  }
  JUMPOUT(0x5D615);
}
// 5D88D: control flows out of bounds to 5D615
// 192248: using guessed type int16_t word_192248[500];
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;


//----- (0005D953) --------------------------------------------------------
void sub_5D953()
{
  int i; // esi
  int16_t v1; // di
  int v2; // eax
  int v3; // ebx
  int16_t v4; // ax
  int16_t v5; // ax
  int v6; // eax
  int v7; // eax
  int16_t v8; // bx
  int16_t m; // cx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // ebx
  int v14; // ebx
  int16_t v15; // bx
  _BYTE *v16; // ebx
  int v17; // [esp+Ch] [ebp-20h]
  int16_t v18; // [esp+10h] [ebp-1Ch]
  int16_t k; // [esp+14h] [ebp-18h]
  int16_t v20; // [esp+18h] [ebp-14h]
  int16_t j; // [esp+1Ch] [ebp-10h]
  int16_t v22; // [esp+20h] [ebp-Ch]
  int16_t v23; // [esp+28h] [ebp-4h]

  v20 = 2;
  if ( *(_BYTE *)(3753 * word_19999C + dword_197F98 + 460) == 3 )
    v20 = 4;
  if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 395) == 3 )
    v20 = 6;
  if ( *(_BYTE *)(3753 * word_19999C + dword_197F98 + 439) == 3 )
    v20 = 9;
  for ( i = 0; ; ++i )
  {
    if ( (int16_t)i >= word_199A02 )
      JUMPOUT(0x5D611);
    v23 = *(int16_t *)((char *)&word_1975D4 + 5 * word_192248[(int16_t)i]);
    if ( *(char *)(dword_197F9C + 129 * v23 + 99) != word_19999C )
      break;
LABEL_61:
    ;
  }
  v1 = -300;
  for ( j = 0; j < word_199996; ++j )
  {
    v17 = 361 * j;
    if ( *(char *)(v17 + dword_192B18) == word_19999C )
    {
      v2 = 113 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v17 + dword_192B18 + 2) + 2);
      v3 = ((int16_t)sub_134637(
                       *(_WORD *)(dword_197F9C + 129 * v23 + 103),
                       *(_WORD *)(dword_197F9C + 129 * v23 + 105),
                       *(_WORD *)(dword_19306C + v2 + 15),
                       *(_WORD *)(dword_19306C + v2 + 17))
          + 29)
         / 30;
      if ( (_WORD)v3 )
      {
        v4 = v20;
        if ( *(_BYTE *)(v17 + dword_192B18 + 350) )
          v4 = v20 + 2;
        if ( *(_BYTE *)(dword_192B18 + 361 * j + 318) )
          v4 += 4;
        if ( *(_BYTE *)(dword_192B18 + 361 * j + 351) )
          v4 += 6;
        v5 = v4 - v3;
        if ( v5 > v1 )
          v1 = v5;
      }
      else
      {
        v1 = 1000;
      }
    }
  }
  for ( k = 0; k < word_199994; ++k )
  {
    v6 = dword_197F9C + 129 * k;
    if ( *(char *)(v6 + 99) == word_19999C && *(char *)(v6 + 100) < 3 )
    {
      v7 = ((int16_t)sub_134637(
                       *(_WORD *)(dword_197F9C + 129 * v23 + 103),
                       *(_WORD *)(dword_197F9C + 129 * v23 + 105),
                       *(_WORD *)(v6 + 103),
                       *(_WORD *)(v6 + 105))
          + 29)
         / 30;
      if ( (_WORD)v7 )
      {
        v8 = v20 - v7;
        if ( sub_5D393(k, 5) )
          v8 += 2;
        if ( v8 > v1 )
          v1 = v8;
      }
      else
      {
        v1 = 1000;
      }
    }
  }
  v22 = -1;
  for ( m = word_192248[(int16_t)i]; ; m = *(int16_t *)((char *)&word_1975D6 + v11) )
  {
    if ( m == -1 )
    {
      if ( word_192248[(int16_t)i] == -1 )
      {
        sub_1331D2(i--, (int)word_192248, 2, word_199A02);
        --word_199A02;
      }
      goto LABEL_61;
    }
    v18 = *(int16_t *)((char *)&word_1975D4 + 5 * m);
    v10 = 129 * v18 + dword_197F9C;
    if ( *(char *)(v10 + 99) > 8 && !*(_BYTE *)(v10 + 20) )
      break;
    v12 = 129 * v18;
    if ( *(_BYTE *)(v12 + dword_197F9C + 99) == 8 )
    {
      LOWORD(v13) = -5;
    }
    else if ( *(char *)(v12 + dword_197F9C + 99) < 8
           && (*(_BYTE *)(3753 * *(char *)(v12 + dword_197F9C + 99) + dword_197F98 + 2235) == 1
            || (v16 = (_BYTE *)(dword_197F9C + 129 * v18), (char)v16[26] < 0)
            || (v16[23] & 0x40) != 0
            || (char)v16[25] < 0) )
    {
      LOWORD(v13) = 500;
    }
    else
    {
      v14 = dword_197F9C + 129 * v18;
      if ( *(_BYTE *)(v14 + 100) == 1 )
      {
        LOWORD(v14) = *(uint8_t *)(v14 + 16);
        v13 = -v14;
      }
      else
      {
        LOWORD(v13) = 0;
      }
    }
    if ( (uint16_t)sub_1276F0(dword_197F9C + 129 * v18 + 118, 0x1Fu) )
      LOWORD(v13) = v13 + 500;
    if ( (uint16_t)sub_1276F0(dword_197F9C + 129 * v18 + 118, 6u) )
      LOWORD(v13) = v13 + 500;
    if ( (uint16_t)sub_1276F0(dword_197F9C + 129 * v18 + 118, 0x17u) )
      LOWORD(v13) = v13 + 500;
    if ( (int16_t)v13 <= v1 )
    {
      v22 = m;
LABEL_40:
      v11 = 5 * m;
      continue;
    }
    v15 = m;
    v11 = 5 * m;
    sub_5DDA9(i, v22, v15);
  }
  if ( !sub_79E32(word_19999C, *(_WORD *)(v10 + 101)) )
    sub_5DDA9(i, v22, m);
  goto LABEL_40;
}
// 5DD7F: control flows out of bounds to 5D611
// 192248: using guessed type int16_t word_192248[500];
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 19999C: using guessed type int16_t word_19999C;
// 199A02: using guessed type int16_t word_199A02;


//----- (0005DD84) --------------------------------------------------------
_BYTE *__fastcall sub_5DD84( int a1)
{
  _BYTE *result; // eax

  result = sub_1331D2(a1, (int)word_192248, 2, word_199A02);
  --word_199A02;
  return result;
}
// 192248: using guessed type int16_t word_192248[500];
// 199A02: using guessed type int16_t word_199A02;


//----- (0005DDA9) --------------------------------------------------------
int16_t __fastcall sub_5DDA9( int result, int a2, int a3)
{
  if ( a2 == -1 )
  {
    word_192248[result] = *(int16_t *)((char *)&word_1975D6 + 5 * a3);
  }
  else
  {
    result = *(int16_t *)((char *)&word_1975D6 + 5 * a3);
    *(int16_t *)((char *)&word_1975D6 + 5 * a2) = result;
  }
  return result;
}
// 192248: using guessed type int16_t word_192248[500];
// 1975D6: using guessed type int16_t word_1975D6;


//----- (0005DDE0) --------------------------------------------------------
int __fastcall sub_5DDE0( int a1)
{
  int16_t v1; // si
  int result; // eax
  int16_t i; // dx
  int v4; // ebx
  _WORD v5[1000]; // [esp+0h] [ebp-7D4h] BYREF
  int16_t v6; // [esp+7D0h] [ebp-4h] BYREF

  v1 = a1;
  result = sub_5DE49(a1, (int)v5, &v6);
  if ( v6 > 1 )
  {
    result = qsort(v5, v6, 4, sub_5DEFD);
    for ( i = 0; i < v6; ++i )
    {
      v4 = i;
      result = 5 * v1;
      v1 = *(int16_t *)((char *)&word_1975D6 + result);
      *(int16_t *)((char *)&word_1975D4 + result) = v5[2 * v4];
    }
  }
  return result;
}
// 133EF4: using guessed type int __fastcall qsort(_DWORD, _DWORD, _DWORD, _DWORD);
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;


//----- (0005DE49) --------------------------------------------------------
int __fastcall sub_5DE49( int a1, int a2, int16_t *a3)
{
  int result; // eax
  int16_t v5; // cx
  uint8_t v6; // cl
  int16_t v7; // di
  int16_t v8; // cx

  *a3 = 0;
  do
  {
    result = 5 * a1;
    v5 = *(int16_t *)((char *)&word_1975D4 + result);
    if ( v5 > -1 )
    {
      *(_WORD *)(a2 + 4 * *a3) = v5;
      result = dword_197F9C + 129 * v5;
      v6 = *(_BYTE *)(result + 17);
      if ( v6 )
      {
        if ( v6 <= 1u )
        {
          result = *a3;
          *(_WORD *)(a2 + 4 * result + 2) = -1;
        }
        else if ( v6 <= 2u )
        {
          result = *a3;
          *(_WORD *)(a2 + 4 * result + 2) = -2;
        }
        else if ( v6 == 4 )
        {
          result = *a3;
          *(_WORD *)(a2 + 4 * result + 2) = -3;
        }
      }
      else
      {
        v7 = *(uint8_t *)(result + 16);
        v8 = *(char *)(result + 92);
        result = *a3;
        *(_WORD *)(a2 + 4 * result + 2) = 50 * v7 + v8;
      }
      ++*a3;
    }
    a1 = *(int16_t *)((char *)&word_1975D6 + 5 * a1);
  }
  while ( a1 > 0 && a1 < 500 );
  return result;
}
// 1975D4: using guessed type int16_t word_1975D4;
// 1975D6: using guessed type int16_t word_1975D6;
// 197F9C: using guessed type int dword_197F9C;


//----- (0005DEFD) --------------------------------------------------------
int __fastcall sub_5DEFD(int a1, int a2)
{
  return *(int16_t *)(a2 + 2) - *(int16_t *)(a1 + 2);
}


//----- (0005DF0A) --------------------------------------------------------
int __usercall sub_5DF0A(int a1, int a2, int16_t *a3)
{
  int v3; // eax
  int v4; // esi
  _DWORD *v5; // ebx
  int v6; // edx
  _BYTE *v7; // eax
  int i; // esi
  _BYTE *v9; // eax
  int j; // eax
  _BYTE *v11; // esi
  int k; // eax
  char *v13; // esi
  int m; // esi
  _BYTE *v15; // eax
  int n; // esi
  char *v17; // eax
  int ii; // esi
  _BYTE *v19; // eax
  int jj; // esi
  _BYTE *v21; // eax
  int kk; // eax
  _BYTE *v23; // esi
  int mm; // eax
  _BYTE *v25; // esi
  int nn; // esi
  char *v27; // eax
  int i1; // esi
  _BYTE *v29; // eax
  int i2; // eax
  _BYTE *v31; // esi
  int i3; // esi
  _BYTE *v33; // eax
  int i4; // eax
  char *v35; // esi
  int result; // eax
  _BYTE *v37; // esi

  v3 = sub_13652();
  sub_FE8BE(v3, a1, a2, a3);
  v4 = 23;
  v5 = sub_126AFD((int)aTechnameLbx, (uint8_t)byte_199CAE, dword_193178);
  sub_FE8BE((int)v5, (int)v5, (int)v5, a3);
  off_17D904 = v5;
  v6 = 0;
  do
  {
    while ( 1 )
    {
      v7 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v7 )
    {
      ++v7;
      ++v6;
    }
    v4 += 23;
    *(int *)((char *)&dword_17D8ED + v4) = (int)v7;
  }
  while ( v4 != 1909 );
  sub_FE8BE((int)v7, v6, (int)v5, a3);
  for ( i = 0; i != 2756; *(int *)((char *)&dword_17E06C + i) = (int)v9 )
  {
    while ( 1 )
    {
      v9 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v9 )
    {
      ++v9;
      ++v6;
    }
    i += 13;
  }
  sub_FE8BE((int)v9, v6, (int)v5, a3);
  for ( j = 0; j != 931; *(int *)((char *)&dword_17EB2A + j) = (int)v11 )
  {
    while ( 1 )
    {
      v11 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v11 )
    {
      ++v11;
      ++v6;
    }
    j += 19;
  }
  sub_FE8BE(931, v6, (int)v5, a3);
  for ( k = 0; k != 1880; *(_UNKNOWN **)((char *)&off_17EEB1 + k) = v13 )
  {
    while ( 1 )
    {
      v13 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v13 )
    {
      ++v13;
      ++v6;
    }
    k += 47;
  }
  sub_FE8BE(1880, v6, (int)v5, a3);
  for ( m = 0; m != 105; *(int *)((char *)&dword_17F629 + m) = (int)v15 )
  {
    while ( 1 )
    {
      v15 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v15 )
    {
      ++v15;
      ++v6;
    }
    m += 15;
  }
  sub_FE8BE((int)v15, v6, (int)v5, a3);
  for ( n = 0; n != 354; *(_UNKNOWN **)((char *)&off_17F665 + n + 1) = v17 )
  {
    while ( 1 )
    {
      v17 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v17 )
    {
      ++v17;
      ++v6;
    }
    n += 59;
  }
  sub_FE8BE((int)v17, v6, (int)v5, a3);
  for ( ii = 0; ii != 322; dword_17F7E7[ii] = (int)v19 )
  {
    while ( 1 )
    {
      v19 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v19 )
    {
      ++v19;
      ++v6;
    }
    ii += 7;
  }
  sub_FE8BE((int)v19, v6, (int)v5, a3);
  for ( jj = 0; jj != 132; *(int *)((char *)&dword_17FDD6 + jj) = (int)v21 )
  {
    while ( 1 )
    {
      v21 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v21 )
    {
      ++v21;
      ++v6;
    }
    jj += 22;
  }
  for ( kk = 0; kk != 322; *(_DWORD *)((char *)&unk_17FE42 + kk) = v23 )
  {
    while ( 1 )
    {
      v23 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v23 )
    {
      ++v23;
      ++v6;
    }
    kk += 46;
  }
  for ( mm = 0; mm != 12; dword_17FFA6[mm] = (int)v25 )
  {
    while ( 1 )
    {
      v25 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v25 )
    {
      ++v25;
      ++v6;
    }
    mm += 3;
  }
  sub_FE8BE(48, v6, (int)v5, a3);
  for ( nn = 0; nn != 60; *(_UNKNOWN **)((char *)&off_17FFD6 + nn + 2) = v27 )
  {
    while ( 1 )
    {
      v27 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v27 )
    {
      ++v27;
      ++v6;
    }
    nn += 10;
  }
  for ( i1 = 0; i1 != 225; *(int *)((char *)&dword_17FCFC + i1) = (int)v29 )
  {
    while ( 1 )
    {
      v29 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v29 )
    {
      ++v29;
      ++v6;
    }
    i1 += 15;
  }
  sub_FE8BE((int)v29, v6, (int)v5, a3);
  for ( i2 = 0; i2 != 225; *(int *)((char *)&dword_17FD00 + i2) = (int)v31 )
  {
    while ( 1 )
    {
      v31 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v31 )
    {
      ++v31;
      ++v6;
    }
    i2 += 15;
  }
  sub_FE8BE(225, v6, (int)v5, a3);
  for ( i3 = 0; i3 != 322; dword_17F7EB[i3] = (int)v33 )
  {
    while ( 1 )
    {
      v33 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v33 )
    {
      ++v33;
      ++v6;
    }
    i3 += 7;
  }
  sub_FE8BE((int)v33, v6, (int)v5, a3);
  for ( i4 = 0; i4 != 324; *(_UNKNOWN **)((char *)&off_180014 + i4 + 2) = v35 )
  {
    while ( 1 )
    {
      v35 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v35 )
    {
      ++v35;
      ++v6;
    }
    i4 += 36;
  }
  sub_FE8BE(324, v6, (int)v5, a3);
  for ( result = 0; result != 81; dword_18001A[result] = (int)v37 )
  {
    while ( 1 )
    {
      v37 = (char *)v5 + v6;
      if ( !*((_BYTE *)v5 + v6) )
        break;
      ++v6;
    }
    while ( !*v37 )
    {
      ++v37;
      ++v6;
    }
    result += 9;
  }
  return result * 4;
}
// 17D8ED: using guessed type int dword_17D8ED;
// 17D904: using guessed type _UNKNOWN *off_17D904;
// 17E06C: using guessed type int dword_17E06C;
// 17EB2A: using guessed type int dword_17EB2A;
// 17EEB1: using guessed type _UNKNOWN *off_17EEB1;
// 17F629: using guessed type int dword_17F629;
// 17F665: using guessed type _UNKNOWN *;
// 17F7E7: using guessed type int dword_17F7E7[];
// 17F7EB: using guessed type int dword_17F7EB[];
// 17FCFC: using guessed type int dword_17FCFC;
// 17FD00: using guessed type int dword_17FD00;
// 17FDD6: using guessed type int dword_17FDD6;
// 17FFA6: using guessed type int dword_17FFA6[];
// 17FFD6: using guessed type _UNKNOWN *;
// 180014: using guessed type _UNKNOWN *;
// 18001A: using guessed type int dword_18001A[];
// 193178: using guessed type int dword_193178;
// 199CAE: using guessed type char byte_199CAE;


//----- (0005E1E3) --------------------------------------------------------
void __usercall sub_5E1E3(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // edx
  int v21; // ecx
  int v22; // eax
  int16_t v23; // si
  int16_t i; // dx
  char *v25; // edi
  int v26; // eax
  int v27; // eax
  char *v28; // [esp-4h] [ebp-30h] BYREF
  char v29[40]; // [esp+0h] [ebp-2Ch] BYREF
  int v30; // [esp+28h] [ebp-4h]

  sub_FE8BE(a1, a2, a3, a4);
  sub_FE8BE(v4, a2, a3, a4);
  v5 = 1;
  do
  {
    v6 = 13 * *(int16_t *)((char *)&word_17EB43 + 19 * (int16_t)v5++);
    byte_17E085[v6] = 1;
  }
  while ( (int16_t)v5 < 49 );
  sub_FE8BE(v5, v6, a3, a4);
  v7 = 1;
  do
  {
    v8 = 13 * *(int16_t *)((char *)&word_17EEE6 + 47 * (int16_t)v7++);
    byte_17E085[v8] = 9;
  }
  while ( (int16_t)v7 < 40 );
  sub_FE8BE(v7, v8, a3, a4);
  v9 = 1;
  do
  {
    v10 = 13 * *(int16_t *)((char *)&word_17F63E + 15 * (int16_t)v9++);
    byte_17E085[v10] = 7;
  }
  while ( (int16_t)v9 < 7 );
  sub_FE8BE(v9, v10, a3, a4);
  v11 = 1;
  do
  {
    v12 = 13 * *(int16_t *)((char *)&word_17F6A7 + 59 * (int16_t)v11++);
    byte_17E085[v12] = 2;
  }
  while ( (int16_t)v11 < 6 );
  sub_FE8BE(v11, v12, a3, a4);
  v13 = 1;
  do
  {
    v14 = 13 * word_17F80D[14 * (int16_t)v13++];
    byte_17E085[v14] = 3;
  }
  while ( (int16_t)v13 < 46 );
  sub_FE8BE(v13, v14, a3, a4);
  v15 = 1;
  do
  {
    v16 = 13 * word_17FDF2[11 * (int16_t)v15++];
    byte_17E085[v16] = 8;
  }
  while ( (int16_t)v15 < 6 );
  v17 = 1;
  do
  {
    v18 = 13 * word_17FE76[23 * (int16_t)v17++];
    byte_17E085[v18] = 5;
  }
  while ( (int16_t)v17 < 7 );
  v19 = 1;
  do
  {
    v20 = 13 * word_17FFE8[5 * (int16_t)v19++];
    byte_17E085[v20] = 4;
  }
  while ( (int16_t)v19 < 6 );
  sub_FE8BE(v19, v20, a3, a4);
  v21 = 0;
  do
  {
    v22 = 13 * (int16_t)v21;
    LOWORD(v22) = *(int16_t *)((char *)&word_17E07F + v22);
    if ( (_WORD)v22 )
    {
      v20 = (int16_t)v22;
      if ( (int16_t)v22 != -1 && (_WORD)v22 != 74 )
      {
        v23 = -1;
        for ( i = 0; i < 4 && v23 == -1; ++i )
        {
          v30 = 23 * (int16_t)v22;
          if ( !*(int16_t *)((char *)&word_17D90E[i] + v30) )
            v23 = i;
        }
        v20 = v23;
        if ( v23 == -1 )
        {
          itoa((int16_t)v21, v29, 10, v21);
          v28 = v29;
          v25 = (char *)&v28 + 3;
          do
            ++v25;
          while ( *v25 );
          strcpy(v25, aTechHasTooMany);
          sub_126487(v29, (int)v29);
        }
        a3 = 23 * (int16_t)v22;
        v22 = v23;
        *(int16_t *)((char *)&word_17D90E[v23] + a3) = v21;
      }
    }
    ++v21;
    sub_FE8BE(v22, v20, a3, a4);
  }
  while ( (int16_t)v21 < 212 );
  sub_FE8BE(v26, v20, a3, a4);
  v27 = sub_5DF0A(v20, a3, a4);
  sub_FE8BE(v27, v20, a3, a4);
}
// 5E1F1: variable 'v4' is possibly undefined
// 5E3E9: variable 'v26' is possibly undefined
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 17D90E: using guessed type int16_t word_17D90E[4];
// 17E07F: using guessed type int16_t word_17E07F;
// 17EB43: using guessed type int16_t word_17EB43;
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17F63E: using guessed type int16_t word_17F63E;
// 17F6A7: using guessed type int16_t word_17F6A7;
// 17F80D: using guessed type int16_t word_17F80D[];
// 17FDF2: using guessed type int16_t word_17FDF2[];
// 17FE76: using guessed type int16_t word_17FE76[];
// 17FFE8: using guessed type int16_t word_17FFE8[];


//----- (0005E3FF) --------------------------------------------------------
int __fastcall sub_5E3FF( int a1, int a2, int a3)
{
  int result; // eax
  int16_t v5; // dx
  _BOOL2 v6; // [esp+0h] [ebp-4h]

  v6 = 0;
  for ( result = 0; (int16_t)result < a3 && !v6; ++result )
    v6 = *(_BYTE *)(3753 * a1 + dword_197F98 + *(int16_t *)(a2 + 2 * (int16_t)result) + 279) != 0;
  if ( !v6 )
  {
    v5 = *(_WORD *)(a2 + 2 * sub_1247A0(a3) - 2);
    result = dword_197F98 + 3753 * a1;
    *(_BYTE *)(v5 + result + 279) = 1;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0005E481) --------------------------------------------------------
int __fastcall sub_5E481( int a1, int a2)
{
  int v3; // ecx
  int result; // eax

  v3 = 3753 * a1;
  LOWORD(result) = 1;
  if ( *(_BYTE *)(v3 + dword_197F98 + 2207) == 6 && (a2 == 86 || a2 == 195 || a2 == 141) )
    LOWORD(result) = 0;
  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + 2230) && (a2 == 142 || a2 == 19 || a2 == 50 || a2 == 113) )
    LOWORD(result) = 0;
  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + 2225)
    && (a2 == 6 || a2 == 29 || a2 == 68 || a2 == 87 || a2 == 162 || a2 == 178) )
  {
    LOWORD(result) = 0;
  }
  if ( byte_199CB4 == 1 && !byte_17E084[13 * a2] )
    LOWORD(result) = 0;
  if ( a2 == 52 && !byte_199CAF )
    LOWORD(result) = 0;
  return (int16_t)result;
}
// 197F98: using guessed type int dword_197F98;
// 199CAF: using guessed type char byte_199CAF;
// 199CB4: using guessed type char byte_199CB4;


//----- (0005E55F) --------------------------------------------------------
void __fastcall sub_5E55F( int a1)
{
  int v2; // edx
  int v3; // eax
  int16_t v4; // cx
  int v5; // edx
  int16_t i; // ax
  int v7; // edx
  _BYTE *v8; // eax
  uint8_t v9; // cl
  int16_t v10; // cx
  int v11; // eax
  int16_t v12; // si
  int16_t j; // ax
  int v14; // edx
  int16_t v15; // ax
  int v16; // edi
  int16_t v17; // si
  int v18; // eax
  int v19; // edx
  int16_t k; // si
  int v21; // edx
  int16_t v22; // di
  int v23; // ecx
  int v24; // edi
  int v25; // eax
  int16_t m; // di
  int v27; // ecx
  int v28; // edx
  int16_t v29; // [esp+Ch] [ebp-1Ch]
  int16_t v30; // [esp+10h] [ebp-18h]
  int16_t v31; // [esp+18h] [ebp-10h]
  int16_t v32; // [esp+1Ch] [ebp-Ch]
  int16_t v33; // [esp+20h] [ebp-8h]
  int16_t v34; // [esp+24h] [ebp-4h]

  v2 = 3753 * a1;
  v3 = dword_197F98;
  *(_BYTE *)(v2 + dword_197F98 + 214) = 2;
  *(_BYTE *)(v2 + v3 + 251) = 2;
  *(_BYTE *)(v2 + v3 + 253) = 2;
  *(_BYTE *)(v2 + v3 + 225) = 2;
  *(_BYTE *)(v2 + v3 + 203) = 2;
  *(_BYTE *)(v2 + v3 + 218) = 2;
  *(_BYTE *)(v2 + v3 + 224) = 2;
  *(_BYTE *)(v2 + v3 + 206) = 2;
  v34 = 0;
  if ( byte_199CB5 )
  {
    if ( (uint8_t)byte_199CB5 <= 1u )
    {
      v30 = 6;
    }
    else if ( byte_199CB5 == 2 )
    {
      v30 = 25;
    }
  }
  else
  {
    v30 = 1;
  }
  v4 = 1;
  *(_BYTE *)(dword_197F98 + 3753 * a1 + 196) = 3;
  while ( 1 )
  {
    if ( *(int16_t *)((char *)&word_17E07F + 13 * v4) != 6 )
    {
      if ( *(int16_t *)((char *)&word_17E07F + 13 * v4) )
      {
        if ( (!*(_BYTE *)(3753 * a1 + dword_197F98 + 2228)
           || (v5 = *(int16_t *)((char *)&word_17E07F + 13 * v4), v5 == -1)
           || *(int *)((char *)&dword_17D916 + 23 * v5) == 50
           || *(int16_t *)((char *)&word_17E07F + 13 * v4) == 23)
          && sub_5E481(a1, v4) )
        {
          *(_BYTE *)(v4 + dword_197F98 + 3753 * a1 + 279) = 1;
        }
        else
        {
          *(_BYTE *)(3753 * a1 + dword_197F98 + v4 + 279) = 0;
        }
      }
      else
      {
        *(_BYTE *)(v4 + dword_197F98 + 3753 * a1 + 279) = 3;
      }
      if ( v4 == 52 && !byte_199CAF )
        *(_BYTE *)(3753 * a1 + dword_197F98 + 331) = 0;
    }
    if ( ++v4 >= 212 )
    {
      for ( i = 0; i < 4 && word_17D998[i] > 0; ++i )
      {
        v7 = word_17D998[i];
        *(_BYTE *)(v7 + 3753 * a1 + dword_197F98 + 279) = 0;
      }
      v8 = (_BYTE *)(dword_197F98 + 3753 * a1);
      v9 = v8[2207];
      if ( v9 < 2u )
      {
        if ( !v9 )
          v8[321] = 1;
      }
      else if ( v9 <= 2u )
      {
        v8[371] = 1;
      }
      else if ( v9 >= 4u )
      {
        if ( v9 <= 4u )
        {
          v8[344] = 1;
        }
        else if ( v9 == 6 )
        {
          v8[356] = 1;
          v8[365] = 0;
          v8[420] = 0;
          v8[474] = 0;
        }
      }
      v10 = 1;
      *(_BYTE *)(dword_197F98 + 3753 * a1 + 279) = 0;
      while ( 1 )
      {
        v11 = 3753 * a1 + dword_197F98 + v10;
        if ( !*(_BYTE *)(v11 + 196) )
          *(_BYTE *)(v11 + 196) = 1;
        v29 = 0;
        v33 = 0;
        v12 = 1;
        for ( j = 0; j < 4 && v12; ++j )
        {
          v12 = *(int16_t *)((char *)word_17D90E + 23 * v10 + 2 * j);
          if ( *(_BYTE *)(v12 + dword_197F98 + 3753 * a1 + 279) )
          {
            v33 = 1;
          }
          else if ( v12 )
          {
            ++v29;
          }
        }
        if ( !v33 )
        {
          do
          {
            v14 = 23 * v10;
            v15 = sub_1247A0(v29) - 1;
            v16 = *(int16_t *)((char *)&word_17D90E[v15] + v14);
          }
          while ( !sub_5E481(a1, *(int16_t *)((char *)&word_17D90E[v15] + v14)) );
          *(_BYTE *)(v16 + 3753 * a1 + dword_197F98 + 279) = 1;
        }
        if ( ++v10 >= 74 )
        {
          v17 = 75;
          *(_BYTE *)(dword_197F98 + 3753 * a1 + 270) = 0;
          while ( 1 )
          {
            v18 = dword_197F98 + 3753 * a1 + v17;
            if ( !*(_BYTE *)(v18 + 196) )
              *(_BYTE *)(v18 + 196) = 1;
            if ( ++v17 >= 83 )
            {
              v19 = 3753 * a1;
              if ( *(_BYTE *)(v19 + dword_197F98 + 40) == 100 )
              {
                v34 = 1;
                *(_BYTE *)(v19 + dword_197F98 + 40) = 1;
              }
              for ( k = 0; k < v30; ++k )
              {
                if ( k >= 6 )
                {
                  v24 = (int16_t)sub_FD335(a1);
                  v31 = *(int16_t *)((char *)&word_17E07F + 13 * v24);
                  v25 = dword_197F98 + 3753 * a1;
                  *(_BYTE *)(v31 + v25 + 196) = 3;
                  *(_BYTE *)(*(int16_t *)((char *)&word_17D90C + 23 * v31) + v25 + 196) = 2;
                  if ( *(_BYTE *)(v25 + 2229) )
                  {
                    for ( m = 0; m < 4; ++m )
                    {
                      v27 = 2 * m + 23 * v31;
                      if ( !*(int16_t *)((char *)word_17D90E + v27) )
                        break;
                      if ( sub_5E481(a1, *(int16_t *)((char *)word_17D90E + v27)) )
                        *(_BYTE *)(*(int16_t *)((char *)word_17D90E + v27) + dword_197F98 + 3753 * a1 + 279) = 3;
                    }
                  }
                  else
                  {
                    *(_BYTE *)(v24 + v25 + 279) = 3;
                  }
                  if ( v31 == 6 )
                    ++*(_BYTE *)(dword_197F98 + 3753 * a1 + 2207);
                }
                else
                {
                  v32 = word_18111C[k];
                  v21 = 3753 * a1 + dword_197F98;
                  *(_BYTE *)(v21 + v32 + 196) = 3;
                  v22 = 0;
                  *(_BYTE *)(v21 + *(int16_t *)((char *)&word_17D90C + 23 * v32) + 196) = 2;
                  while ( v22 < 4 )
                  {
                    v23 = 2 * v22 + 23 * v32;
                    if ( !*(int16_t *)((char *)word_17D90E + v23) )
                      break;
                    if ( sub_5E481(a1, *(int16_t *)((char *)word_17D90E + v23)) )
                      *(_BYTE *)(3753 * a1 + dword_197F98 + *(int16_t *)((char *)word_17D90E + v23) + 279) = 3;
                    ++v22;
                  }
                }
              }
              if ( v34 )
                *(_BYTE *)(dword_197F98 + 3753 * a1 + 40) = 100;
              v28 = 3753 * a1;
              *(_BYTE *)(v28 + dword_197F98 + 1439) = sub_56726(a1);
              *(_BYTE *)(v28 + dword_197F98 + 1440) = sub_57597(a1);
              JUMPOUT(0x5E3F8);
            }
          }
        }
      }
    }
  }
}
// 5EADC: control flows out of bounds to 5E3F8
// 5EA83: variable 'v30' is possibly undefined
// 17D90C: using guessed type int16_t word_17D90C;
// 17D90E: using guessed type int16_t word_17D90E[];
// 17D916: using guessed type int dword_17D916;
// 17D998: using guessed type int16_t word_17D998[];
// 17E07F: using guessed type int16_t word_17E07F;
// 18111C: using guessed type int16_t word_18111C[6];
// 197F98: using guessed type int dword_197F98;
// 199CAF: using guessed type char byte_199CAF;
// 199CB5: using guessed type char byte_199CB5;


//----- (0005EAE9) --------------------------------------------------------
int __fastcall sub_5EAE9(int a1)
{
  int v1; // ebx
  int v2; // ecx
  int v3; // eax
  int result; // eax

  v1 = a1;
  v2 = (int16_t)a1;
  v3 = sub_56726(a1);
  LOWORD(v3) = byte_17FE92[46 * (int16_t)v3];
  result = 5 * v3;
  if ( (int16_t)v1 < 8 )
  {
    LOWORD(v1) = *(char *)(dword_197F98 + 3753 * v2 + 2213);
    result += v1;
    if ( *(_BYTE *)(dword_197F98 + 3753 * v2 + 2236) )
      result += 20;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0005EB39) --------------------------------------------------------
int16_t __fastcall sub_5EB39( int a1)
{
  int v2; // ebx
  int16_t result; // ax

  v2 = a1;
  result = word_17FE00[11 * (int16_t)sub_5680D(a1)];
  if ( a1 < 8 )
    result += *(char *)(3753 * v2 + dword_197F98 + 2214);
  return result;
}
// 17FE00: using guessed type int16_t word_17FE00[];
// 197F98: using guessed type int dword_197F98;


//----- (0005EB72) --------------------------------------------------------
int __fastcall sub_5EB72( int a1, int a2)
{
  unsigned int v2; // esi
  int16_t v3; // ax
  int v4; // edi
  int16_t v5; // ax
  int16_t v6; // cx
  int16_t v7; // ax
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // ebx
  int64_t v12; // rax
  int16_t v13; // bx
  int v14; // eax
  int v15; // esi
  int v16; // eax
  int v17; // esi
  int v18; // eax
  int16_t v19; // bx
  int16_t v20; // ax
  unsigned int v21; // eax
  int16_t v23; // [esp+0h] [ebp-30h]
  int16_t v24; // [esp+4h] [ebp-2Ch]
  int v25; // [esp+14h] [ebp-1Ch]
  int16_t v26; // [esp+18h] [ebp-18h]
  int v27; // [esp+1Ch] [ebp-14h]
  int16_t v28; // [esp+20h] [ebp-10h]
  int16_t v29; // [esp+24h] [ebp-Ch]
  int16_t v30; // [esp+28h] [ebp-8h]
  int v31; // [esp+2Ch] [ebp-4h]

  v2 = 0;
  if ( a1 != -1 )
  {
    v3 = word_17FE00[11 * (int16_t)sub_5680D(a2)];
    if ( a2 < 8 )
      v3 += *(char *)(dword_197F98 + 3753 * a2 + 2214);
    v30 = v3 + 100 - sub_5EAE9(v23);
    if ( v30 < 10 )
      v30 = 10;
    if ( v30 > 100 )
      v30 = 100;
    v4 = a2;
    sub_568EB(a2);
    v6 = v5;
    v28 = v5;
    sub_56BFA(a2);
    v29 = v7;
    v26 = v7;
    if ( byte_199CB4 )
    {
      v8 = 18 * (v24 + 5);
      LOWORD(v31) = 0;
      LOWORD(v9) = word_18002E[v8];
      LOWORD(v10) = word_180030[v8];
      LOWORD(v27) = v9;
    }
    else
    {
      v11 = 18 * (v24 + 5);
      v12 = word_180020[v11];
      WORD2(v12) = word_180020[v11];
      v25 = HIDWORD(v12) - SWORD2(v12) / 2;
      v27 = ((int)(SWORD2(v12) / 2
                 - (__CFSHL__((uint64_t)(SWORD2(v12) / 2) >> 32, 2)
                  + 4 * ((uint64_t)(SWORD2(v12) / 2) >> 32))) >> 2)
          / sub_6EE8E(v4, v6, 1, 15, 0, 0);
      v31 = SWORD2(v12) / 2 / 2 / sub_6EE8E(v4, v6, 1, 15, 0, 2);
      LODWORD(v12) = sub_6EE8E(v4, v29, 1, 15, 0x14u, 0);
      v9 = (int16_t)v25 % (int)v12;
      v10 = (int16_t)v25 / (int)v12;
    }
    v13 = sub_5F871(v23, (uint16_t)v9);
    v14 = word_17F819[14 * v28] - v13;
    if ( v14 < 0 )
      v14 = 0;
    v15 = v14 * (int16_t)v27 * v30 / 100;
    v16 = 3 * word_17F819[14 * v28] / 2 - v13;
    if ( v16 < 0 )
      v16 = 0;
    v17 = v30 * (int16_t)v31 * v16 / 100 + v15;
    v18 = word_17F819[14 * v26] - v13;
    if ( v18 < 0 )
      v18 = 0;
    v2 = (int16_t)v10 * v18 + v17;
    if ( !byte_199CB4 )
    {
      v19 = word_180026[18 * v24 + 90];
      if ( v19 > 100 )
        v20 = ((v19 - 100 - (__CFSHL__((v19 - 100) >> 31, 2) + 4 * ((v19 - 100) >> 31))) >> 2) + 100;
      else
        v20 = v19 + (100 - v19) / 10;
      if ( v2 * v20 / 0x64 <= 1 )
        v21 = 1;
      else
        v21 = v2 * (int16_t)sub_5EED4(v19) / 0x64;
      v2 = 75 * v21 / 0x64;
    }
    if ( v2 > 0xFA00 )
      return 64000;
  }
  return v2;
}
// 5EBBB: variable 'v23' is possibly undefined
// 5EBF1: variable 'v5' is possibly undefined
// 5EBFD: variable 'v7' is possibly undefined
// 5EC0C: variable 'v24' is possibly undefined
// 17F819: using guessed type int16_t word_17F819[];
// 17FE00: using guessed type int16_t word_17FE00[];
// 180020: using guessed type int16_t word_180020[];
// 180026: using guessed type int16_t word_180026[];
// 18002E: using guessed type int16_t word_18002E[];
// 180030: using guessed type int16_t word_180030[];
// 197F98: using guessed type int dword_197F98;
// 199CB4: using guessed type char byte_199CB4;


//----- (0005EE27) --------------------------------------------------------
unsigned int __fastcall sub_5EE27( unsigned int a1, int a2)
{
  int16_t v3; // ax
  unsigned int result; // eax

  v3 = 100;
  if ( (a2 & 2) != 0 )
    v3 = word_17FD26 + 100;
  if ( (a2 & 4) != 0 )
    v3 += word_17FD35;
  if ( (a2 & 0x20) != 0 )
    v3 += word_17FD62;
  if ( (a2 & 0x80u) != 0 )
    v3 += word_17FD80;
  if ( (a2 & 0x100) != 0 )
    v3 += word_17FD8F;
  if ( (a2 & 0x200) != 0 )
    v3 += word_17FD9E;
  if ( (a2 & 0x400) != 0 )
    v3 += word_17FDAD;
  if ( (a2 & 0x800) != 0 )
    v3 += word_17FDBC;
  if ( (a2 & 0x1000) != 0 )
    v3 += word_17FDCB;
  if ( (a2 & 0x2000) != 0 )
    v3 += word_17FDDA;
  if ( (a2 & 0x4000) != 0 )
    v3 += word_17FDE9;
  result = a1 * v3 / 100;
  if ( result > 0xFA00 )
    return 64000;
  return result;
}
// 17FD26: using guessed type int16_t word_17FD26;
// 17FD35: using guessed type int16_t word_17FD35;
// 17FD62: using guessed type int16_t word_17FD62;
// 17FD80: using guessed type int16_t word_17FD80;
// 17FD8F: using guessed type int16_t word_17FD8F;
// 17FD9E: using guessed type int16_t word_17FD9E;
// 17FDAD: using guessed type int16_t word_17FDAD;
// 17FDBC: using guessed type int16_t word_17FDBC;
// 17FDCB: using guessed type int16_t word_17FDCB;
// 17FDDA: using guessed type int16_t word_17FDDA;
// 17FDE9: using guessed type int16_t word_17FDE9;


//----- (0005EED4) --------------------------------------------------------
int __fastcall sub_5EED4( int a1)
{
  if ( a1 > 100 )
    return ((a1 - 100 - (__CFSHL__((a1 - 100) >> 31, 2) + 4 * ((a1 - 100) >> 31))) >> 2) + 100;
  else
    return a1 + (100 - a1) / 10;
}


//----- (0005EF09) --------------------------------------------------------
void __fastcall sub_5EF09( int a1, int a2)
{
  sub_5EF4B(a1, a2, 0);
}


//----- (0005EF17) --------------------------------------------------------
void __fastcall sub_5EF17( int a1, int a2)
{
  int16_t v3; // ax

  v3 = sub_5F871(a2, a2);
  sub_5EF4B(a1, a2, v3);
}


//----- (0005EF4B) --------------------------------------------------------
void __fastcall sub_5EF4B( int a1, int a2, int a3)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  int16_t v6; // bx
  int v7; // eax
  int16_t v8; // di
  int v9; // eax
  int16_t v10; // bx
  int v11; // ecx
  int v12; // eax
  int16_t v13; // ax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // ecx
  int16_t v18; // ax
  int16_t v19; // bx
  int16_t v20; // ax
  int16_t v21; // dx
  unsigned int v22; // eax
  unsigned int v23; // edx
  unsigned int v24; // esi
  int v25; // ecx
  int v26; // ebx
  int16_t v27; // ax
  int16_t v29; // [esp+4h] [ebp-30h]
  int v31; // [esp+14h] [ebp-20h]
  int16_t v32; // [esp+1Ch] [ebp-18h] BYREF
  int v33; // [esp+20h] [ebp-14h] BYREF
  int16_t v34; // [esp+24h] [ebp-10h] BYREF
  int v35; // [esp+28h] [ebp-Ch]
  int v36; // [esp+2Ch] [ebp-8h]
  int v37; // [esp+30h] [ebp-4h]

  v29 = a2;
  v3 = a1;
  HIWORD(a2) = HIWORD(dword_197F9C);
  v4 = dword_197F9C + 129 * a1;
  v5 = 0;
  v31 = v4;
  v6 = *(char *)(v4 + 99);
  if ( byte_199CB4 )
  {
    LOWORD(a2) = word_17FE00[11 * (int16_t)sub_5680D(*(char *)(v4 + 99))];
    if ( v6 < 8 )
    {
      HIWORD(v7) = HIWORD(dword_197F98);
      LOWORD(v7) = *(char *)(3753 * v6 + dword_197F98 + 2214);
      a2 += v7;
    }
    v33 = a2;
    sub_5794B(a1);
  }
  else
  {
    sub_54E5B(v3, &v32, &v34, &v33);
  }
  v8 = 0;
  v36 = sub_5EAE9(v29);
  while ( 1 )
  {
    v9 = v31 + 8 * v8;
    v10 = *(_WORD *)(v9 + 28);
    if ( v10 <= 0 )
      goto LABEL_43;
    LOWORD(v11) = *(uint8_t *)(v9 + 31);
    if ( (*(_BYTE *)(v9 + 33) & 0x40) == 0 && v10 != 34 && v10 != 13 )
      break;
    v11 = *(uint8_t *)(v9 + 31);
    v12 = word_17F819[14 * v10];
LABEL_30:
    v17 = v12 * v11;
    if ( v17 )
    {
      switch ( byte_17F80F[28 * v10] )
      {
        case 0:
          v18 = v33 + 50 - v36;
          if ( 16 * *(int16_t *)(v31 + 8 * v8 + 33) )
            v18 += 25;
          if ( v18 < 10 )
            v18 = 10;
          if ( v18 > 100 )
            v18 = 100;
          v17 = v17 * v18 / 0x64;
          break;
        case 1:
          if ( *(_BYTE *)(v31 + 8 * v8 + 35) == 2 )
            goto LABEL_33;
          break;
        case 2:
LABEL_33:
          v17 = (3 * v17) >> 2;
          break;
        case 3:
          LOWORD(v17) = 0;
          break;
        default:
          break;
      }
    }
    v5 += (uint16_t)sub_5EE27(v17, *(_WORD *)(v31 + 8 * v8 + 33));
LABEL_43:
    if ( ++v8 >= 8 )
    {
      v19 = sub_5679E(*(char *)(129 * a1 + dword_197F9C + 99)) - *(uint8_t *)(129 * a1 + dword_197F9C + 18);
      v20 = 100;
      if ( v19 < 0 )
        v20 = 100 - 10 * abs16(v19);
      if ( v20 <= 10 )
        v21 = 10;
      else
        v21 = v20;
      v22 = v5 * v21 / 0x64u;
      v23 = v5 * v21 % 0x64u;
      v24 = v22;
      if ( !byte_199CB4 )
      {
        v25 = 129 * a1;
        v26 = sub_5F2F6(a1, v23, 100, v25);
        LOWORD(v26) = v26 - *(_WORD *)(v25 + dword_197F9C + 125);
        if ( !byte_199CB4 )
          LOWORD(v26) = v26 - *(_WORD *)(v25 + dword_197F9C + 123);
        v37 = v26;
        if ( (int16_t)v26 > 100 )
          v27 = (((int16_t)v26 - 100 - (__CFSHL__(((int16_t)v26 - 100) >> 31, 2) + 4 * (((int16_t)v26 - 100) >> 31))) >> 2)
              + 100;
        else
          v27 = v26 + (100 - (int16_t)v26) / 10;
        if ( (v24 != 0) < v24 * v27 / 0x64 )
          sub_5EED4(v37);
        JUMPOUT(0x5EE11);
      }
      JUMPOUT(0x5EE13);
    }
  }
  if ( v10 == 31 )
  {
    LOWORD(v11) = 3 * v11;
    sub_5699C(*(char *)(dword_197F9C + 129 * a1 + 99));
  }
  else
  {
    if ( v10 != 30 && v10 != 29 )
    {
      if ( v10 == 28 )
      {
        v10 = 27;
        LOWORD(v11) = 3 * v11;
      }
      else if ( v10 == 36 )
      {
        LOWORD(v11) = 3 * v11;
      }
LABEL_22:
      v14 = 28 * v10;
      LOWORD(v14) = *(int16_t *)((char *)word_17F819 + v14);
      v35 = v14;
      v15 = v31 + 8 * v8;
      if ( (*(_BYTE *)(v15 + 33) & 2) != 0 )
      {
        v16 = (int16_t)v35 + (50 * (int16_t)v35 + 50) / 100;
      }
      else
      {
        if ( (*(_BYTE *)(v15 + 33) & 4) == 0 )
        {
LABEL_27:
          v12 = (int16_t)v35 - a3;
          if ( v12 < 0 )
            v12 = 0;
          v11 = (int16_t)v11;
          goto LABEL_30;
        }
        v16 = (50 * (int16_t)v35 + 50) / 100;
      }
      v35 = v16;
      goto LABEL_27;
    }
    LOWORD(v11) = 3 * v11;
    v13 = sub_56CA2(*(char *)(dword_197F9C + 129 * a1 + 99));
  }
  v10 = v13;
  goto LABEL_22;
}
// 5F2B7: control flows out of bounds to 5EE11
// 5F22B: control flows out of bounds to 5EE13
// 5F07F: conditional instruction was optimized away because bx.2 is in (1..C|E..1B|20..21|>=23)
// 5F085: conditional instruction was optimized away because bx.2 is in (1..C|E..1B|20..21|>=23)
// 5F03D: variable 'v13' is possibly undefined
// 17F819: using guessed type int16_t word_17F819[];
// 17FE00: using guessed type int16_t word_17FE00[];
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199CB4: using guessed type char byte_199CB4;


//----- (0005F2C3) --------------------------------------------------------
int __fastcall sub_5F2C3( int a1, int a2, int a3, int a4)
{
  int v4; // edx
  int v5; // ebx
  int v6; // eax
  int v7; // edx

  v4 = 129 * a1;
  v5 = sub_5F2F6(a1, v4, a3, a4);
  v6 = v4 + dword_197F9C;
  HIWORD(v7) = HIWORD(v5);
  LOWORD(v7) = v5 - *(_WORD *)(v6 + 125);
  if ( !byte_199CB4 )
    LOWORD(v7) = v7 - *(_WORD *)(v6 + 123);
  return v7;
}
// 197F9C: using guessed type int dword_197F9C;
// 199CB4: using guessed type char byte_199CB4;


//----- (0005F2F6) --------------------------------------------------------
int __fastcall sub_5F2F6( int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  int v5; // edx
  int16_t v6; // ax
  int16_t v7; // ax
  int v9; // ebx

  if ( byte_199CB4 )
  {
    v4 = 129 * a1;
    v5 = 36 * *(uint8_t *)(v4 + dword_197F9C + 16);
    LOWORD(v5) = *(int16_t *)((char *)word_180038 + v5);
    sub_5685F(*(char *)(v4 + dword_197F9C + 99));
    if ( v6 > 0 )
    {
      sub_5685F(*(char *)(v4 + dword_197F9C + 99));
      return (int16_t)v5 + (int16_t)v5 * *(int16_t *)((char *)&word_17F642 + 15 * v7) / 100;
    }
  }
  else
  {
    v9 = sub_58387(a1, a1, a3, a4);
    return sub_58425(a1) + v9;
  }
  return v5;
}
// 5F32C: variable 'v6' is possibly undefined
// 5F33D: variable 'v7' is possibly undefined
// 17F642: using guessed type int16_t word_17F642;
// 180038: using guessed type int16_t word_180038[];
// 197F9C: using guessed type int dword_197F9C;
// 199CB4: using guessed type char byte_199CB4;


//----- (0005F379) --------------------------------------------------------
_WORD *__fastcall sub_5F379(int a1, int a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // edi
  int v6; // ebx
  unsigned int v7; // edx
  int v8; // eax
  int16_t i; // bx
  int v10; // eax
  unsigned int v11; // eax
  int16_t v12; // si
  int16_t j; // dx
  int v14; // eax
  int16_t k; // si
  int v16; // ebx
  unsigned int v17; // edi
  _WORD *result; // eax
  _DWORD v19[4]; // [esp+0h] [ebp-2Ch]
  _DWORD v20[2]; // [esp+10h] [ebp-1Ch]
  int v21; // [esp+18h] [ebp-14h]
  unsigned int v22; // [esp+1Ch] [ebp-10h]
  int v23; // [esp+20h] [ebp-Ch]
  int v24; // [esp+24h] [ebp-8h]
  int v25; // [esp+28h] [ebp-4h]

  v23 = a2;
  v3 = 0;
  v20[0] = &loc_70002;
  v20[1] = close;
  do
  {
    v4 = (int16_t)v3++;
    v19[v4] = 0;
  }
  while ( (int16_t)v3 < 4 );
  if ( byte_199CB4 == 1 )
  {
    v5 = 10
       * *(uint8_t *)(129 * (int16_t)a1 + dword_197F9C + 16)
       * *(uint8_t *)(129 * (int16_t)a1 + dword_197F9C + 16);
    v6 = 1;
    v19[0] = v5;
    do
    {
      v7 = (v5 + (int16_t)v6 - 1) / (unsigned int)(int16_t)v6;
      v8 = (int16_t)v6++;
      v19[v8] = v7;
    }
    while ( (int16_t)v6 < 4 );
  }
  else
  {
    for ( i = 0; i < 8; ++i )
    {
      v10 = 8 * i + dword_197F9C + 129 * (int16_t)a1;
      if ( *(int16_t *)(v10 + 28) > 0 )
      {
        v11 = 28 * *(int16_t *)(v10 + 28);
        if ( byte_17F80F[v11] && byte_17F80F[v11] != 2 )
          v12 = word_17F819[v11 / 2];
        else
          v12 = word_17F819[14 * *(int16_t *)(129 * (int16_t)a1 + dword_197F9C + 8 * i + 28)] / 2;
        for ( j = 0; j < 4; ++j )
        {
          v24 = *(uint8_t *)(129 * (int16_t)a1 + dword_197F9C + 8 * i + 31);
          if ( v24 * (v12 - *((int16_t *)v20 + j)) <= 0 )
            v25 = 0;
          else
            v25 = v24 * (v12 - *((int16_t *)v20 + j));
          v14 = j;
          v19[v14] += v25;
        }
      }
    }
  }
  for ( k = 0; k < 4; ++k )
  {
    v21 = k;
    v16 = k;
    v17 = (int16_t)sub_5F2C3(a1, (int16_t)a1, v16 * 4, a1) * v19[v16];
    v22 = (int16_t)sub_5F2F6(a1, (int16_t)a1, v16 * 4, a1);
    v19[v16] = v17 / v22;
    result = (_WORD *)(v23 + 2 * v21);
    if ( v19[v16] <= 0xFA00u )
      *result = v19[k];
    else
      *result = -1536;
  }
  return result;
}
// 16000C: using guessed type int __fastcall close(_DWORD);
// 17F819: using guessed type int16_t word_17F819[];
// 197F9C: using guessed type int dword_197F9C;
// 199CB4: using guessed type char byte_199CB4;


//----- (0005F524) --------------------------------------------------------
void __fastcall sub_5F524( int a1, int a2)
{
  int v2; // esi
  int16_t v3; // ax
  int v4; // edx

  if ( byte_199CB4 != 1 )
  {
    v2 = a1;
    sub_56BFA(a1);
    v4 = 300 / sub_6EE8E(v2, v3, 1, 16, 5u, 0);
    sub_5F871(a2, v4);
  }
  JUMPOUT(0x5F51E);
}
// 5F53A: control flows out of bounds to 5F51E
// 5F55B: variable 'v3' is possibly undefined
// 199CB4: using guessed type char byte_199CB4;


//----- (0005F5A3) --------------------------------------------------------
void __fastcall sub_5F5A3( int a1, int a2)
{
  int v2; // edi
  int16_t v3; // ax
  int v4; // eax

  if ( byte_199CB4 != 1 )
  {
    v2 = a1;
    sub_568EB(a1);
    v4 = sub_6EE8E(v2, v3, 1, 1, 1u, 2);
    sub_5F871(a2, 225 % v4);
  }
  JUMPOUT(0x5F51E);
}
// 5F647: control flows out of bounds to 5F51E
// 5F5E1: variable 'v3' is possibly undefined
// 199CB4: using guessed type char byte_199CB4;


//----- (0005F64C) --------------------------------------------------------
void __fastcall sub_5F64C( int a1, int a2)
{
  int v3; // edx

  v3 = a1;
  sub_5699C(a1);
  sub_56CA2(v3);
  sub_5F871(a2, v3);
  JUMPOUT(0x5F51E);
}
// 5F742: control flows out of bounds to 5F51E
// 197F98: using guessed type int dword_197F98;
// 199CB4: using guessed type char byte_199CB4;


//----- (0005F747) --------------------------------------------------------
int __fastcall sub_5F747( int a1, int a2)
{
  char *v3; // eax
  int v4; // ebx
  int v5; // eax
  char *v6; // eax
  int v7; // eax
  char *v8; // eax
  int v9; // eax

  v3 = (char *)(dword_192B18 + 361 * a1);
  v4 = 0;
  if ( v3[336] )
  {
    sub_5F524(*v3, a2);
    v4 = v5;
  }
  v6 = (char *)(361 * a1 + dword_192B18);
  if ( v6[337] )
  {
    sub_5F5A3(*v6, a2);
    v4 += v7;
  }
  if ( *(_BYTE *)(dword_192B18 + 361 * a1 + 352) )
  {
    if ( byte_199CB4 == 1 )
      v4 += 200;
    else
      v4 += 500;
  }
  v8 = (char *)(dword_192B18 + 361 * a1);
  if ( v8[357] )
  {
    sub_5F64C(*v8, a2);
    v4 += v9;
  }
  if ( (uint16_t)v4 > 0xFA00u )
    return 64000;
  return v4;
}
// 5F773: variable 'v5' is possibly undefined
// 5F799: variable 'v7' is possibly undefined
// 5F7F0: variable 'v9' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 199CB4: using guessed type char byte_199CB4;


//----- (0005F804) --------------------------------------------------------
int __fastcall sub_5F804( int a1)
{
  _BYTE *v2; // eax
  int16_t v3; // dx

  v2 = (_BYTE *)(361 * a1 + dword_192B18);
  v3 = -1;
  if ( v2[350] )
  {
    v3 = 1;
  }
  else if ( v2[318] )
  {
    v3 = 2;
  }
  else if ( v2[351] )
  {
    v3 = 3;
  }
  return sub_5EB72(v3, *(char *)(361 * a1 + dword_192B18));
}
// 192B18: using guessed type int dword_192B18;


//----- (0005F871) --------------------------------------------------------
int __fastcall sub_5F871( int a1, int a2)
{
  int v2; // edx

  if ( a1 >= 8 )
  {
    if ( (uint16_t)a1 < 9u )
    {
      return 6;
    }
    else if ( (uint16_t)a1 <= 9u )
    {
      return 8;
    }
    else if ( (uint16_t)a1 <= 0xEu )
    {
      return 0;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    v2 = 59 * (int16_t)sub_5679E(a1);
    LOWORD(v2) = *(int16_t *)((char *)&word_17F6C1 + v2);
    return v2;
  }
}
// 5F8A5: conditional instruction was optimized away because ax.2==8
// 17F6C1: using guessed type int16_t word_17F6C1;


//----- (0005F8D1) --------------------------------------------------------
int __fastcall sub_5F8D1(int a1, int a2)
{
  int v3; // edx
  int16_t i; // bx
  int v5; // eax

  v3 = 0;
  for ( i = 0; i < 212; ++i )
  {
    if ( a2 == (uint8_t)byte_17E082[13 * i] && *(_BYTE *)(dword_197F98 + i + 279) == 3 )
    {
      v5 = 23 * *(int16_t *)((char *)&word_17E07F + 13 * i);
      LOWORD(v5) = (uint8_t)byte_17D91A[v5];
      if ( (int16_t)v5 > (int16_t)v3 )
        v3 = v5;
    }
  }
  return v3;
}
// 17E07F: using guessed type int16_t word_17E07F;
// 197F98: using guessed type int dword_197F98;


//----- (0005F927) --------------------------------------------------------
_BOOL1 sub_5F927()
{
  int16_t i; // dx
  uint16_t v1; // cx

  for ( i = 0; *(_BYTE *)(3753 * i + dword_197F98 + 36); ++i )
    ;
  v1 = sub_5F8D1(i, 26);
  return v1 >= (uint16_t)sub_5F8D1(i, 21);
}
// 197F98: using guessed type int dword_197F98;


//----- (0005F968) --------------------------------------------------------
int __fastcall sub_5F968( int a1)
{
  _BYTE *v1; // eax
  int v2; // edx

  v1 = (_BYTE *)(dword_197F98 + 3753 * a1);
  v2 = 0;
  if ( v1[345] == 3 || v1[310] == 3 || v1[362] == 3 )
    return 1;
  return v2;
}
// 197F98: using guessed type int dword_197F98;


//----- (0005F9A0) --------------------------------------------------------
int __fastcall sub_5F9A0( int a1)
{
  _BYTE *v1; // eax
  int v2; // edx

  v1 = (_BYTE *)(dword_197F98 + 3753 * a1);
  v2 = 0;
  if ( v1[359] == 3 || v1[339] == 3 || v1[309] == 3 || v1[453] == 3 || v1[419] == 3 )
    return 1;
  return v2;
}
// 197F98: using guessed type int dword_197F98;


//----- (0005F9EA) --------------------------------------------------------
int __fastcall sub_5F9EA( int a1)
{
  int v1; // edx
  int16_t i; // bx

  v1 = 0;
  for ( i = 0; i < 12 && !(_WORD)v1; ++i )
  {
    if ( word_1811DE[2 * i] )
    {
      if ( *(_BYTE *)(word_17F80D[14 * word_1811DC[2 * i]] + dword_197F98 + 3753 * a1 + 279) != 3 )
        continue;
    }
    else if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + *(int16_t *)((char *)&word_17EEE6 + 47 * word_1811DC[2 * i]) + 279) != 3 )
    {
      continue;
    }
    v1 = 1;
  }
  return v1;
}
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17F80D: using guessed type int16_t word_17F80D[];
// 1811DC: using guessed type int16_t word_1811DC[];
// 1811DE: using guessed type int16_t word_1811DE[];
// 197F98: using guessed type int dword_197F98;


//----- (0005FA87) --------------------------------------------------------
void __fastcall sub_5FA87( int a1)
{
  int v1; // esi
  uint8_t v2; // al

  v1 = a1;
  sub_5F968(a1);
  sub_5F9A0(v1);
  sub_5F9EA(v1);
  if ( word_1998F0 == -1000 )
    goto LABEL_9;
  v2 = *(_BYTE *)(3753 * v1 + dword_197F98 + 517);
  if ( v2 >= 2u )
  {
    if ( v2 > 2u )
    {
      if ( v2 <= 3u || v2 == 100 )
        goto LABEL_8;
LABEL_9:
      JUMPOUT(0x5FA7E);
    }
    sub_1247A0(0x14u);
  }
LABEL_8:
  sub_1247A0(0x14u);
  goto LABEL_9;
}
// 5FAC9: control flows out of bounds to 5FA7E
// 197F98: using guessed type int dword_197F98;
// 1998F0: using guessed type int16_t word_1998F0;


//----- (0005FD8C) --------------------------------------------------------
int __fastcall sub_5FD8C(int a1, int a2)
{
  int v3; // esi
  int16_t v4; // bx
  int v6; // [esp+0h] [ebp-Ch]
  int16_t i; // [esp+8h] [ebp-4h]

  v3 = 1;
  v4 = 0;
  v6 = a1 + 23;
  while ( (_WORD)v3 == 1 && v4 < 39 )
  {
    if ( (uint16_t)sub_1276F0(v6, v4) )
    {
      for ( i = 0; i < 6; ++i )
      {
        if ( a2 == *(int16_t *)((char *)&word_17EF00 + 47 * v4 + 2 * i) )
          v3 = 0;
      }
    }
    ++v4;
  }
  if ( !*(_BYTE *)(a1 + 18) && (a2 == 13 || a2 == 20 || a2 == 30) )
    return 0;
  return v3;
}
// 17EF00: using guessed type int16_t word_17EF00;


//----- (0005FE14) --------------------------------------------------------
int __fastcall sub_5FE14(int a1, int a2, int a3, int a4, int a5, int16_t *a6)
{
  int16_t *v7; // eax
  int16_t v8; // ax
  int16_t v9; // bx
  int16_t i; // ax
  int v11; // eax
  int v12; // edx
  int16_t v13; // bx
  int v14; // edx
  unsigned int v15; // ecx
  int16_t v16; // ax
  int v17; // ebx
  char v19; // [esp+8h] [ebp-2Ch]
  int v20; // [esp+Ch] [ebp-28h]
  int v22; // [esp+14h] [ebp-20h]
  int16_t v23; // [esp+18h] [ebp-1Ch]
  int16_t v24; // [esp+1Ch] [ebp-18h]
  int v26; // [esp+24h] [ebp-10h]
  int16_t v27; // [esp+28h] [ebp-Ch]
  int16_t v28; // [esp+2Ch] [ebp-8h]

  v22 = 0;
  v23 = 0;
  v28 = 0;
  v20 = a4 + 23;
  while ( v28 < a2 )
  {
    v7 = (int16_t *)(a1 + 4 * v28);
    if ( v7[1] )
    {
      v8 = *v7;
      v26 = 0;
      v27 = v8;
      if ( *a6 < 8 )
      {
        v9 = word_17F80D[14 * v8];
        if ( v8 == 33 )
        {
          for ( i = 0; i < *a6; ++i )
          {
            if ( *(_WORD *)(a4 + 8 * i + 28) == 33 )
              v23 = 1;
          }
        }
        if ( *(_BYTE *)(3753 * a3 + dword_197F98 + v9 + 279) == 3 && !v23 )
        {
          v11 = (int16_t)a5 / sub_6EE8E(a3, v27, 1, 16, 1u, 0);
          if ( v27 == 33 && (int16_t)v11 > 10 * *(uint8_t *)(a4 + 16) )
          {
            LOWORD(v11) = *(uint8_t *)(a4 + 16);
            v11 *= 10;
          }
          if ( (int16_t)v11 > 0 )
          {
            *(_WORD *)(a4 + 8 * *a6 + 28) = v27;
            *(_BYTE *)(a4 + 8 * *a6 + 32) = 16;
            *(_WORD *)(a4 + 8 * *a6 + 33) = 0;
            v12 = *a6;
LABEL_17:
            *(_BYTE *)(a4 + 8 * v12 + 35) = 1;
            while ( (int16_t)v11 > 99 && *a6 < 8 )
            {
              *(_BYTE *)(a4 + 8 * *a6 + 30) = 99;
              *(_BYTE *)(a4 + 8 * *a6 + 31) = 99;
              v26 += 99;
              ++*a6;
              v11 -= 99;
              if ( *a6 < 8 )
              {
                *(_WORD *)(a4 + 8 * *a6 + 28) = v27;
                *(_BYTE *)(a4 + 8 * *a6 + 32) = 16;
                *(_WORD *)(a4 + 8 * *a6 + 33) = 0;
                v12 = *a6;
                goto LABEL_17;
              }
            }
            if ( *a6 < 8 )
            {
              *(_BYTE *)(a4 + 8 * *a6 + 30) = v11;
              v26 += v11;
              *(_BYTE *)(a4 + 8 * *a6 + 31) = v11;
            }
            ++*a6;
          }
          v22 += v26 * sub_6EE8E(a3, v27, 1, 16, 1u, 0);
          a5 -= v26 * sub_6EE8E(a3, v27, 1, 16, 1u, 0);
        }
      }
    }
    else
    {
      v13 = *v7;
      v14 = *v7;
      v24 = *(int16_t *)((char *)&word_17EEE6 + 47 * v14);
      if ( *(_BYTE *)(dword_197F98 + 3753 * a3 + v24 + 279) == 3
        && (uint16_t)sub_5FD8C(a4, v14)
        && (!*(_BYTE *)(3753 * a3 + dword_197F98 + 2235) || v13 != 31) )
      {
        v19 = sub_6F11C(v24);
        v15 = v13;
        sub_6E70A(a3, v24);
        v17 = sub_6E60E(*(int16_t *)((char *)&word_17EEE8 + 47 * v13 + 2 * *(uint8_t *)(a4 + 16)), v16, v19);
        if ( (int16_t)v17 < (int16_t)a5 )
        {
          sub_127712(v20, v15);
          v22 += v17;
          a5 -= v17;
        }
      }
    }
    ++v28;
  }
  return v22;
}
// 60089: variable 'v16' is possibly undefined
// 17EEE6: using guessed type int16_t word_17EEE6;
// 17EEE8: using guessed type int16_t word_17EEE8;
// 17F80D: using guessed type int16_t word_17F80D[];
// 197F98: using guessed type int dword_197F98;


//----- (000600BF) --------------------------------------------------------
int __fastcall sub_600BF(int a1, int a2, int a3, int16_t *a4)
{
  uint8_t v5; // cl
  int result; // eax
  void *v7; // eax
  int v8; // edi
  void *v9; // eax
  int16_t *v10; // [esp-4h] [ebp-Ch]
  int16_t v11; // [esp+0h] [ebp-8h]

  v5 = *(_BYTE *)(3753 * v11 + dword_197F98 + 518);
  result = 0;
  if ( v5 >= 3u )
  {
    if ( v5 <= 3u )
      return sub_5FE14((int)&unk_18116C, 8, v11, a2, a3, a4);
    if ( v5 < 5u )
    {
      v10 = a4;
      v8 = a3;
      v9 = &unk_181150;
    }
    else if ( v5 <= 5u )
    {
      v10 = a4;
      v8 = a3;
      v9 = &unk_18118C;
    }
    else
    {
      if ( v5 > 6u )
      {
        if ( v5 != 100 )
          return result;
        return sub_5FE14((int)&unk_18116C, 8, v11, a2, a3, a4);
      }
      v10 = a4;
      v8 = a3;
      v9 = &unk_181198;
    }
    return sub_5FE14((int)v9, 3, v11, a2, v8, v10);
  }
  if ( !v5 )
    return sub_5FE14((int)&unk_18115C, 4, v11, a2, a3, a4);
  if ( v5 <= 1u )
    v7 = &unk_18113C;
  else
    v7 = &unk_181128;
  return sub_5FE14((int)v7, 5, v11, a2, a3, a4);
}
// 600CA: variable 'v11' is possibly undefined
// 197F98: using guessed type int dword_197F98;


//----- (000601AC) --------------------------------------------------------
int __fastcall sub_601AC( int a1, int a2, int16_t *a3, int a4)
{
  int v5; // eax
  int v6; // edx
  int16_t v8; // [esp+0h] [ebp-1Ch]
  int v9; // [esp+Ch] [ebp-10h]
  int v10; // [esp+10h] [ebp-Ch]
  int16_t v11; // [esp+14h] [ebp-8h]

  v9 = 0;
  v10 = 0;
  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + 362) == 3 && a4 / sub_6EE8E(a1, 29, 1, 16, 1u, 0) > 0 )
  {
    v11 = 29;
  }
  else if ( *(_BYTE *)(dword_197F98 + 3753 * v8 + 310) == 3 && a4 / sub_6EE8E(v8, 30, 1, 16, 1u, 0) > 0 )
  {
    v11 = 30;
  }
  else
  {
    v11 = 31;
  }
  v5 = a4 / sub_6EE8E(v8, v11, 1, 16, 1u, 0);
  if ( (int16_t)v5 > 0 && *a3 < 8 )
  {
    *(_WORD *)(a2 + 8 * *a3 + 28) = v11;
    *(_BYTE *)(a2 + 8 * *a3 + 32) = 16;
    *(_WORD *)(a2 + 8 * *a3 + 33) = 0;
    v6 = *a3;
LABEL_11:
    *(_BYTE *)(a2 + 8 * v6 + 35) = 1;
    while ( (int16_t)v5 > 20 && *a3 < 8 )
    {
      *(_BYTE *)(a2 + 8 * *a3 + 30) = 20;
      *(_BYTE *)(a2 + 8 * *a3 + 31) = 20;
      v9 += 20;
      ++*a3;
      v5 -= 20;
      if ( *a3 < 8 )
      {
        *(_WORD *)(a2 + 8 * *a3 + 28) = v11;
        *(_BYTE *)(a2 + 8 * *a3 + 32) = 16;
        *(_WORD *)(a2 + 8 * *a3 + 33) = 0;
        v6 = *a3;
        goto LABEL_11;
      }
    }
    if ( *a3 < 8 )
    {
      *(_BYTE *)(a2 + 8 * *a3 + 30) = v5;
      v9 += v5;
      *(_BYTE *)(a2 + 8 * *a3 + 31) = v5;
    }
    ++*a3;
    return sub_6EE8E(v8, 31, 1, 16, 1u, 0) * v9;
  }
  return v10;
}
// 60299: conditional instruction was optimized away because %var_8.2 is in (1D..1F)
// 60211: variable 'v8' is possibly undefined
// 197F98: using guessed type int dword_197F98;


//----- (00060362) --------------------------------------------------------
int16_t __fastcall sub_60362(int a1, int16_t *a2, int a3, int a4, int a5, uint16_t *a6)
{
  int16_t i; // bx
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int16_t v12; // dx
  int16_t j; // bx
  int v14; // eax
  int16_t v15; // cx
  int16_t v16; // dx
  int16_t v17; // dx
  int16_t k; // ax
  int v19; // ebx
  int16_t m; // bx
  int v21; // edx
  int16_t v22; // ax
  int16_t v23; // dx
  int v24; // ecx
  int v25; // edx
  int16_t v26; // ax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // edx
  int v31; // edx
  int v32; // edx
  int16_t v34; // [esp+0h] [ebp-32h]
  _DWORD v35[20]; // [esp+4h] [ebp-2Eh]
  _WORD v36[20]; // [esp+54h] [ebp+22h]
  int v37; // [esp+7Ch] [ebp+4Ah]
  int v38; // [esp+80h] [ebp+4Eh]
  int v39; // [esp+84h] [ebp+52h]
  int v40; // [esp+88h] [ebp+56h]
  unsigned int v41; // [esp+8Ch] [ebp+5Ah]
  int v42; // [esp+90h] [ebp+5Eh]
  int v43; // [esp+94h] [ebp+62h]
  int v44; // [esp+98h] [ebp+66h]
  int v45; // [esp+9Ch] [ebp+6Ah]
  int v46; // [esp+A0h] [ebp+6Eh]
  int v47; // [esp+A4h] [ebp+72h]
  int v48; // [esp+A8h] [ebp+76h]

  v45 = a4;
  v43 = 0;
  for ( i = 1; i < 40; ++i )
  {
    v9 = 28 * i;
    if ( byte_17F80F[v9] == 1 || byte_17F80F[28 * i] == 2 )
    {
      v10 = 28 * i;
      LOWORD(v10) = *(int16_t *)((char *)word_17F80D + v10);
      v47 = v10;
      v9 = dword_197F98 + 3753 * v34;
      if ( *(_BYTE *)((int16_t)v47 + v9 + 279) == 3 )
      {
        v11 = 23 * *(int16_t *)((char *)&word_17E07F + 13 * (int16_t)v47);
        v9 = (int16_t)v43++;
        *((_WORD *)v35 + v9) = 0;
        LOWORD(v11) = (uint8_t)byte_17D91A[v11];
        v36[v9] = i;
        *((_WORD *)&v35[10] + v9) = v11;
      }
    }
  }
  if ( (_WORD)v43 )
  {
    v12 = 1;
    while ( v12 == 1 )
    {
      v12 = 0;
      for ( j = 0; ; ++j )
      {
        v37 = (int16_t)v43;
        if ( j >= (int16_t)v43 - 1 )
          break;
        v14 = 2 * j;
        v15 = *(_WORD *)((char *)&v35[10] + v14 + 2);
        if ( v15 < *(int16_t *)((char *)&v35[10] + v14) )
        {
          v16 = *((_WORD *)&v35[10] + j);
          *((_WORD *)&v35[10] + j) = v15;
          *((_WORD *)&v35[10] + j + 1) = v16;
          v17 = v36[j];
          v36[j] = v36[j + 1];
          v36[j + 1] = v17;
          v12 = 1;
        }
      }
    }
    for ( k = 0; ; ++k )
    {
      v19 = k;
      if ( !*(_BYTE *)(dword_197F98 + 3753 * k + 36) )
        break;
    }
    v46 = sub_5F871(k, 28);
    v42 = sub_5F8D1(v19, 28);
    for ( m = 0; m < (int16_t)v43; ++m )
    {
      v21 = 14 * (int16_t)v36[m];
      v37 = word_17F819[v21];
      v38 = (int16_t)v46 + 4;
      if ( v37 >= v38 )
      {
        sub_6D048(v34, word_17F80D[v21]);
        v23 = v22;
        if ( v22 > 5 )
          v23 = 5;
        if ( (int16_t)v42 > 0 && v23 >= 1 )
          *((_BYTE *)v35 + 2 * m + 1) += 4;
        if ( v23 >= 1 )
          *((_WORD *)v35 + m) += 22560;
        if ( v23 >= 2 )
          *((_BYTE *)v35 + 2 * m + 1) += 3;
        HIWORD(v24) = HIWORD(dword_197F98);
        if ( *(_BYTE *)(dword_197F98 + 3753 * v34 + 338) == 3 && v23 >= 2 )
          *((_BYTE *)v35 + 2 * m + 1) += 32;
        v25 = 28 * (int16_t)v36[m];
        LOWORD(v24) = *((_WORD *)v35 + m);
        v44 = v24;
        LOWORD(v25) = *(int16_t *)((char *)word_17F81D + v25);
        v44 = v25 & v24;
        *((_WORD *)v35 + m) = v25 & v24;
      }
      else
      {
        v36[m] = 0;
        *((_WORD *)&v35[10] + m) = 0;
        *(_WORD *)(a3 + 2 * m) = 0;
      }
    }
    if ( (uint8_t)byte_199CB0 >= 2u )
    {
      if ( (_WORD)v43 == 1 )
      {
        *a2 = v36[0];
        v26 = v35[0];
      }
      else
      {
        v39 = 0;
        v48 = 0;
        v40 = 0;
        v41 = 0;
        while ( (int16_t)v43 > v40 )
        {
          if ( v36[v41 / 2] )
          {
            v27 = sub_6EE8E(v34, v36[v41 / 2], 1, 1, 5u, 0);
            v28 = 10 * (word_17F819[14 * (int16_t)v36[v41 / 2]] - (int16_t)v46) / v27;
            if ( v28 > v39 )
            {
              v39 = v28;
              v48 = v40;
            }
          }
          v41 += 2;
          ++v40;
        }
        v29 = (int16_t)v48;
        *a2 = v36[(int16_t)v48];
        v26 = *((_WORD *)v35 + v29) & 0x7FF9;
      }
      *(_WORD *)a3 = v26;
      v30 = a5 / sub_6EE8E(v34, *a2, 1, 1, *a6, *(_WORD *)a3);
      LOWORD(v9) = v45;
      if ( (int16_t)v30 < word_1812A4[(int16_t)v45] )
      {
        if ( (int16_t)*a6 > 5 )
          *a6 = 5;
        v31 = a5 / sub_6EE8E(v34, *a2, 1, 1, *a6, *(_WORD *)a3);
        LOWORD(v9) = v45;
        if ( (int16_t)v31 < word_1812A4[(int16_t)v45] )
        {
          if ( (*(_BYTE *)(a3 + 1) & 8) != 0 )
            *(_BYTE *)(a3 + 1) ^= 8u;
          v32 = a5 / sub_6EE8E(v34, *a2, 1, 1, *a6, *(_WORD *)a3);
          LOWORD(v9) = v45;
          if ( (int16_t)v32 < word_1812A4[(int16_t)v45] )
          {
            if ( (*(_BYTE *)(a3 + 1) & 0x10) != 0 )
              *(_BYTE *)(a3 + 1) ^= 0x10u;
            LOWORD(v9) = sub_6EE8E(v34, *a2, 1, 1, *a6, *(_WORD *)a3);
          }
        }
      }
    }
    else
    {
      LOWORD(v9) = *((_WORD *)&v35[19] + (int16_t)v43 + 1);
      *a2 = v9;
      *(_WORD *)a3 = 0;
    }
  }
  else
  {
    *a2 = 0;
  }
  return v9;
}
// 603A7: variable 'v34' is possibly undefined
// 604F6: variable 'v22' is possibly undefined
// 17E07F: using guessed type int16_t word_17E07F;
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F819: using guessed type int16_t word_17F819[];
// 17F81D: using guessed type int16_t word_17F81D[];
// 1812A4: using guessed type int16_t word_1812A4[6];
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (00060779) --------------------------------------------------------
int __fastcall sub_60779(int a1, int a2, int16_t *a3, int a4, unsigned int a5)
{
  int16_t v6; // ax
  int v7; // edx
  int16_t v9; // [esp+0h] [ebp-18h]
  int v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h] BYREF
  int v12; // [esp+14h] [ebp-4h] BYREF

  v10 = 0;
  v6 = *(uint8_t *)(a2 + 16);
  v12 = 0;
  v11 = 0;
  sub_60362(v9, (int16_t *)&v12, (int)&v11, v6, a4, &a5);
  if ( !(_WORD)v12 )
    return 0;
  v7 = a4 / sub_6EE8E(v9, v12, 1, 1, a5, v11);
  if ( (int16_t)v7 <= 0 || *a3 >= 8 )
    return 0;
  *(_WORD *)(a2 + 8 * *a3 + 28) = v12;
LABEL_5:
  *(_BYTE *)(a2 + 8 * *a3 + 32) = 16;
  *(_WORD *)(a2 + 8 * *a3 + 33) = v11;
  *(_BYTE *)(a2 + 8 * *a3 + 35) = a5;
  while ( (int16_t)v7 > 20 && *a3 < 8 )
  {
    *(_BYTE *)(a2 + 8 * *a3 + 30) = 20;
    *(_BYTE *)(a2 + 8 * *a3 + 31) = 20;
    v10 += 20;
    ++*a3;
    v7 -= 20;
    if ( *a3 < 8 )
    {
      *(_WORD *)(a2 + 8 * *a3 + 28) = v12;
      goto LABEL_5;
    }
  }
  if ( *a3 < 8 )
  {
    *(_BYTE *)(a2 + 8 * *a3 + 30) = v7;
    v10 += v7;
    *(_BYTE *)(a2 + 8 * *a3 + 31) = v7;
  }
  ++*a3;
  return v10 * sub_6EE8E(v9, v12, 1, 1, a5, v11);
}
// 607AF: variable 'v9' is possibly undefined


//----- (000608AF) --------------------------------------------------------
int16_t __fastcall sub_608AF(int a1, _WORD *a2)
{
  int16_t v3; // si
  int16_t v4; // cx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  int16_t v8; // si
  int16_t i; // dx
  int v10; // eax
  int16_t v11; // di
  int16_t v12; // si
  int16_t v13; // si
  int16_t j; // di
  int v15; // esi
  int v16; // edi
  uint16_t v17; // ax
  int16_t v18; // si
  int16_t v19; // ax
  int16_t v20; // dx
  int16_t v22; // [esp+0h] [ebp-2h]
  _WORD v23[61]; // [esp+2h] [ebp+0h]
  int v24; // [esp+7Ch] [ebp+7Ah]
  int v25; // [esp+80h] [ebp+7Eh]

  v3 = 1;
  v4 = 0;
  do
  {
    v5 = 28 * v3;
    if ( byte_17F80F[v5] == 3 && SLOBYTE(word_17F815[14 * v3]) >= 0 )
    {
      v6 = word_17F80D[14 * v3];
      v5 = 3753 * v22 + dword_197F98;
      if ( *(_BYTE *)((int16_t)v6 + v5 + 279) == 3 )
      {
        v7 = 23 * *(int16_t *)((char *)&word_17E07F + 13 * v6);
        v5 = v4++;
        v23[v5 + 21] = 0;
        LOWORD(v7) = (uint8_t)byte_17D91A[v7];
        v23[v5 + 1] = v3;
        v23[v5 + 41] = v7;
      }
    }
    ++v3;
  }
  while ( v3 < 40 );
  if ( v4 )
  {
    v8 = 1;
    while ( v8 == 1 )
    {
      v8 = 0;
      for ( i = 0; ; ++i )
      {
        v24 = v4;
        if ( i >= v4 - 1 )
          break;
        v10 = i;
        v11 = v23[v10 + 42];
        if ( v11 < (int16_t)v23[v10 + 41] )
        {
          v12 = v23[i + 41];
          v23[i + 41] = v11;
          v23[i + 42] = v12;
          v13 = v23[i + 1];
          v23[i + 1] = v23[i + 2];
          v23[i + 2] = v13;
          v8 = 1;
        }
      }
    }
    for ( j = 0; ; ++j )
    {
      v15 = j;
      if ( !*(_BYTE *)(dword_197F98 + 3753 * j + 36) )
        break;
    }
    v16 = (2 * (uint16_t)sub_5F8D1(j, 33) + 2) / 3;
    v17 = sub_5F8D1(v15, 10);
    v18 = 0;
    v25 = v16 + v17;
    while ( v18 < v4 )
    {
      sub_6D048(v22, word_17F80D[14 * (int16_t)v23[v18 + 1]]);
      v20 = v19;
      if ( v19 > 5 )
        v20 = 5;
      v24 = (int16_t)v23[v18 + 41];
      if ( v20 + v24 >= (int16_t)v25 )
        break;
      ++v18;
    }
    if ( v18 == v4 )
      LOWORD(v5) = v23[v4];
    else
      LOWORD(v5) = v23[v18 + 1];
    *a2 = v5;
  }
  else
  {
    *a2 = 0;
  }
  return v5;
}
// 608DF: variable 'v22' is possibly undefined
// 60A0C: variable 'v19' is possibly undefined
// 17E07F: using guessed type int16_t word_17E07F;
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F815: using guessed type int16_t word_17F815[];
// 197F98: using guessed type int dword_197F98;


//----- (00060A5D) --------------------------------------------------------
int __fastcall sub_60A5D( int a1, int a2, int16_t *a3, int a4)
{
  int v6; // eax
  int v7; // edx
  char v8; // bl
  int v9; // eax
  int16_t v11; // [esp+0h] [ebp-18h]
  int v12; // [esp+4h] [ebp-14h]
  int v13; // [esp+8h] [ebp-10h] BYREF
  int v14; // [esp+Ch] [ebp-Ch]
  int16_t v15; // [esp+10h] [ebp-8h]
  int v16; // [esp+14h] [ebp-4h]

  v14 = a4;
  v13 = 0;
  v12 = a1;
  sub_608AF(a1, &v13);
  v6 = sub_6EE8E(v12, v13, 1, 1, 0, 0);
  v16 = 0;
  v15 = 99;
  v7 = (int16_t)v14 / v6;
  if ( (int16_t)v7 > 0 && *a3 < 8 && (_WORD)v13 )
  {
LABEL_4:
    *(_WORD *)(a2 + 8 * *a3 + 28) = v13;
    *(_BYTE *)(a2 + 8 * *a3 + 32) = 16;
    *(_WORD *)(a2 + 8 * *a3 + 33) = 0;
    *(_BYTE *)(a2 + 8 * *a3 + 35) = 10;
    while ( (int16_t)v7 > 99 && *a3 < 8 )
    {
      v8 = v15;
      *(_BYTE *)(a2 + 8 * *a3 + 30) = v15;
      *(_BYTE *)(a2 + 8 * *a3 + 31) = v8;
      v16 += 99;
      ++*a3;
      v7 -= 99;
      if ( *a3 < 8 )
        goto LABEL_4;
    }
    if ( *a3 < 8 )
    {
      *(_BYTE *)(a2 + 8 * *a3 + 30) = v7;
      v9 = *a3;
      v16 += v7;
      *(_BYTE *)(a2 + 8 * v9 + 31) = v7;
    }
    ++*a3;
  }
  return v16 * sub_6EE8E(v11, v13, 1, 1, 0, 0);
}
// 60B46: variable 'v11' is possibly undefined


//----- (00060B59) --------------------------------------------------------
signed int __fastcall sub_60B59(
        int a1,
        int a2,
        _WORD *a3,
        int16_t *a4,
        _WORD *a5,
        _WORD *a6,
        int16_t *a7,
        _WORD *a8,
        _WORD *a9,
        int16_t *a10,
        _WORD *a11)
{
  int16_t i; // dx
  int v13; // esi
  int v14; // esi
  int v15; // eax
  signed int result; // eax
  int16_t j; // si
  int16_t v18; // dx
  int16_t v19; // dx
  int16_t k; // si
  int v21; // edx
  int v22; // esi
  int v23; // eax
  int v24; // ecx
  int v25; // esi
  int v26; // eax
  int v27; // eax
  int v28; // edx
  int v29; // eax
  int16_t v30; // si
  int v31; // eax
  int16_t v32; // dx
  unsigned int v33; // eax
  int v34; // edx
  unsigned int v35; // eax
  int v36; // edx
  int v37; // esi
  int n; // eax
  int v39; // edx
  int v40; // edx
  int ii; // eax
  _WORD *v42; // eax
  int16_t v43; // ax
  int16_t v44; // ax
  int v45; // esi
  int m; // eax
  int16_t v47; // ax
  int v48; // esi
  int v49; // ebx
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int v53; // esi
  int v54; // ebx
  int v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // esi
  int16_t v59; // ax
  int16_t v60; // si
  int16_t v61; // ax
  int16_t v62; // cx
  int16_t v63; // ax
  int16_t v64; // bx
  int v65; // edi
  int16_t v66; // [esp+0h] [ebp-A6h]
  int16_t v67; // [esp+4h] [ebp-A2h]
  _DWORD v68[10]; // [esp+8h] [ebp-9Eh]
  _WORD v69[20]; // [esp+30h] [ebp-76h]
  _DWORD v70[20]; // [esp+58h] [ebp-4Eh]
  _DWORD v71[10]; // [esp+A8h] [ebp+2h]
  signed int v72; // [esp+D0h] [ebp+2Ah]
  int v73; // [esp+D4h] [ebp+2Eh]
  int v74; // [esp+D8h] [ebp+32h]
  int v75; // [esp+DCh] [ebp+36h]
  int v76; // [esp+E0h] [ebp+3Ah]
  int v77; // [esp+E4h] [ebp+3Eh]
  int v78; // [esp+E8h] [ebp+42h]
  int v79; // [esp+ECh] [ebp+46h]
  int v80; // [esp+F0h] [ebp+4Ah]
  int v81; // [esp+F4h] [ebp+4Eh]
  int v82; // [esp+F8h] [ebp+52h]
  int v83; // [esp+FCh] [ebp+56h]
  int v84; // [esp+100h] [ebp+5Ah]
  int v85; // [esp+104h] [ebp+5Eh]
  int v86; // [esp+108h] [ebp+62h]

  v79 = 0;
  for ( i = 1; i < 40; ++i )
  {
    if ( !byte_17F80F[28 * i] )
    {
      v13 = word_17F80D[14 * i];
      if ( *(_BYTE *)(v13 + dword_197F98 + 3753 * v67 + 279) == 3 )
      {
        v14 = 23 * *(int16_t *)((char *)&word_17E07F + 13 * v13);
        v15 = (int16_t)v79++;
        *((_WORD *)v70 + v15) = 0;
        *((_WORD *)v68 + v15) = 0;
        *((_WORD *)v71 + v15) = 0;
        LOWORD(v14) = (uint8_t)byte_17D91A[v14];
        v69[v15] = i;
        *((_WORD *)&v70[10] + v15) = v14;
      }
    }
  }
  if ( !(_WORD)v79 )
  {
    *a9 = 0;
    result = (signed int)a6;
    *a6 = 0;
    *a3 = 0;
    return result;
  }
  v77 = 1;
  while ( (_WORD)v77 == 1 )
  {
    v77 = 0;
    for ( j = 0; j < (int16_t)v79 - 1; ++j )
    {
      if ( *((_WORD *)&v70[10] + j + 1) < *((_WORD *)&v70[10] + j) )
      {
        v18 = *((_WORD *)&v70[10] + j);
        *((_WORD *)&v70[10] + j) = *((_WORD *)&v70[10] + j + 1);
        *((_WORD *)&v70[10] + j + 1) = v18;
        v19 = v69[j];
        v69[j] = v69[j + 1];
        v77 = 1;
        v69[j + 1] = v19;
      }
    }
  }
  for ( k = 0; ; ++k )
  {
    v21 = k;
    v76 = 3753 * k;
    if ( !*(_BYTE *)(v76 + dword_197F98 + 36) )
      break;
  }
  v24 = 3753 * v67;
  v22 = 22 * (int16_t)sub_5680D(v67);
  v23 = v24 + dword_197F98;
  LOWORD(v24) = *(char *)(v24 + dword_197F98 + 2214);
  LOWORD(v22) = *(int16_t *)((char *)word_17FE00 + v22);
  v25 = v24 + v22;
  if ( *(_BYTE *)(v23 + 40) == 100 )
  {
    LOWORD(v23) = byte_17FEEE;
    v82 = 1;
    v26 = v23 + 20;
  }
  else
  {
    v82 = sub_5F871(v21, v21);
    v27 = 46 * (int16_t)sub_56726(v21);
    LOWORD(v27) = byte_17FE92[v27];
    v28 = v76 + dword_197F98;
    LOWORD(v28) = *(char *)(v76 + dword_197F98 + 2213);
    v26 = v28 + 5 * v27;
  }
  v80 = v25 - v26;
  v29 = v25 - v26 + 25;
  v30 = 0;
  v86 = v29;
  while ( v30 < (int16_t)v79 )
  {
    sub_6D048(v67, word_17F80D[14 * (int16_t)v69[v30]]);
    v78 = v31;
    if ( (int16_t)v31 > 5 )
      v78 = 5;
    v32 = v80;
    if ( (uint8_t)byte_17FD50 <= (int16_t)v78 )
    {
      *((_WORD *)v71 + v30) += 16;
      if ( v32 < 50 )
      {
        v32 = v86;
        *((_WORD *)v70 + v30) += 16;
        *((_WORD *)v68 + v30) += 16;
      }
    }
    if ( v32 > 0 && (uint8_t)byte_17FD5F <= (int16_t)v78 )
    {
      *((_WORD *)v70 + v30) += 32;
      *((_WORD *)v68 + v30) += 32;
    }
    if ( v32 >= 0 && (uint8_t)byte_17FD7D <= (int16_t)v78 )
    {
      if ( v32 > 30 )
        *((_WORD *)v71 + v30) += 128;
      *((_WORD *)v70 + v30) += 128;
      *((_WORD *)v68 + v30) += 128;
    }
    v33 = 2 * v30;
    v34 = 28 * (int16_t)v69[v33 / 2];
    *(_WORD *)((char *)v71 + v33) += 4;
    LOWORD(v24) = *(_WORD *)((char *)v71 + v33);
    v81 = v24;
    LOWORD(v34) = *(int16_t *)((char *)word_17F81D + v34);
    v81 = v34 & v24;
    *(_WORD *)((char *)v71 + v33) = v34 & v24;
    if ( (*((_BYTE *)v71 + v33) & 4) == 0 )
      *((_WORD *)v71 + v30) = 0;
    if ( (uint8_t)byte_17FD41 <= (int16_t)v78 )
    {
      *((_WORD *)v70 + v30) += 8;
      *((_WORD *)v68 + v30) += 8;
    }
    if ( (uint8_t)byte_17FD6E <= (int16_t)v78 )
    {
      *((_WORD *)v70 + v30) += 64;
      *((_WORD *)v68 + v30) += 64;
    }
    if ( (uint8_t)byte_17FD8C <= (int16_t)v78 )
    {
      ++*((_BYTE *)v70 + 2 * v30 + 1);
      ++*((_BYTE *)v68 + 2 * v30 + 1);
    }
    v35 = 2 * v30;
    v36 = 28 * (int16_t)v69[v35 / 2];
    LOWORD(v24) = *(_WORD *)((char *)v70 + v35);
    v81 = v24;
    LOWORD(v24) = *(int16_t *)((char *)word_17F81D + v36);
    v81 &= v24;
    v24 = v81;
    *(_WORD *)((char *)v68 + v35) += 2;
    *(_WORD *)((char *)v70 + v35) = v24;
    LOWORD(v24) = *(_WORD *)((char *)v68 + v35);
    LOWORD(v36) = *(int16_t *)((char *)word_17F81D + v36);
    v81 = v36 & v24;
    *(_WORD *)((char *)v68 + v35) = v36 & v24;
    if ( (*((_BYTE *)v68 + v35) & 2) == 0 )
      *((_WORD *)v68 + v30) = 0;
    ++v30;
  }
  if ( (uint8_t)byte_199CB0 >= 2u )
  {
    if ( (_WORD)v79 == 1 )
    {
      if ( (word_17F81D[14 * v69[0]] & 4) != 0 )
      {
        *a3 = v69[0];
        *a4 = v71[0] & 0x7FFD;
      }
      else
      {
        *a3 = 0;
      }
      *a6 = v69[0];
      *a7 = v70[0] & 0x7FF9;
      if ( (word_17F81D[14 * v69[0]] & 2) == 0 )
      {
        v42 = a9;
        goto LABEL_62;
      }
      *a9 = v69[0];
      v43 = v68[0];
    }
    else
    {
      v74 = 0;
      sub_56A78(v67);
      v45 = v44;
      for ( m = 0; (int16_t)v79 > v74 && (int16_t)v69[m] != v45; ++m )
        ++v74;
      v47 = v74;
      if ( (int16_t)v74 < (int16_t)v79 )
      {
        *a3 = v69[(int16_t)v74];
        *a4 = *((_WORD *)v71 + v47) & 0x7FFD;
      }
      else
      {
        *a3 = 0;
      }
      if ( (int16_t)(v79 - 1) >= 0 )
      {
        if ( (_WORD)v79 == 1 )
        {
          v85 = v79 - 1;
        }
        else
        {
          v75 = 0;
          v85 = 0;
          v74 = 0;
          v48 = 0;
          while ( (int16_t)v79 > v74 )
          {
            if ( v69[v48] )
            {
              v49 = sub_6EE8E(v67, v69[v48], 1, 1, 1u, 0);
              if ( (word_17F815[14 * (int16_t)v69[v48]] & 0x100) != 0 )
                v50 = word_17F819[14 * (int16_t)v69[v48]];
              else
                v50 = word_17F819[14 * (int16_t)v69[v48]] - (int16_t)v82;
              v51 = 10 * v50 / v49;
              if ( (word_17F815[14 * (int16_t)v69[v48]] & 0x20) != 0 )
                v51 = 3 * v51 / 2;
              if ( (word_17F815[14 * (int16_t)v69[v48]] & 4) != 0 )
                v51 = (5 * v51 - (__CFSHL__((5 * v51) >> 31, 2) + 4 * ((5 * v51) >> 31))) >> 2;
              if ( (word_17F815[14 * (int16_t)v69[v48]] & 0x400) != 0 )
                v51 = (5 * v51 - (__CFSHL__((5 * v51) >> 31, 2) + 4 * ((5 * v51) >> 31))) >> 2;
              if ( (word_17F815[14 * (int16_t)v69[v48]] & 0x200) != 0 )
                v51 *= 2;
              if ( (word_17F815[14 * (int16_t)v69[v48]] & 0x10) != 0 && *(_BYTE *)(dword_197F98 + 3753 * v67 + 518) == 1 )
                v51 *= 2;
              if ( v51 > v75 )
              {
                v75 = v51;
                v85 = v74;
              }
            }
            ++v74;
            ++v48;
          }
        }
        v52 = (int16_t)v85;
        *a6 = v69[(int16_t)v85];
        *a7 = *((_WORD *)v70 + v52) & 0x7FF9;
      }
      else
      {
        *a6 = 0;
      }
      if ( (int16_t)(v79 - 1) < 0 )
      {
        v42 = a6;
        goto LABEL_62;
      }
      if ( (_WORD)v79 == 1 )
      {
        v84 = v79 - 1;
      }
      else
      {
        v73 = 0;
        v84 = 0;
        v74 = 0;
        v53 = 0;
        while ( (int16_t)v79 > v74 )
        {
          if ( v69[v53] )
          {
            v54 = sub_6EE8E(v67, v69[v53], 1, 1, 1u, 2);
            if ( (word_17F815[14 * (int16_t)v69[v53]] & 0x100) != 0 )
              v55 = 3 * word_17F819[14 * (int16_t)v69[v53]] / 2;
            else
              v55 = 3 * word_17F819[14 * (int16_t)v69[v53]] / 2 - (int16_t)v82;
            v56 = 10 * v55 / v54;
            if ( (word_17F815[14 * (int16_t)v69[v53]] & 0x20) != 0 )
              v56 = 3 * v56 / 2;
            if ( (word_17F815[14 * (int16_t)v69[v53]] & 4) != 0 )
              v56 = (5 * v56 - (__CFSHL__((5 * v56) >> 31, 2) + 4 * ((5 * v56) >> 31))) >> 2;
            if ( (word_17F815[14 * (int16_t)v69[v53]] & 0x400) != 0 )
              v56 = (5 * v56 - (__CFSHL__((5 * v56) >> 31, 2) + 4 * ((5 * v56) >> 31))) >> 2;
            if ( (word_17F815[14 * (int16_t)v69[v53]] & 0x200) != 0 )
              v56 *= 2;
            if ( v56 > v73 )
            {
              v73 = v56;
              v84 = v74;
            }
          }
          ++v74;
          ++v53;
        }
      }
      v57 = (int16_t)v84;
      *a9 = v69[(int16_t)v84];
      v43 = *((_WORD *)v68 + v57);
    }
    *a10 = v43 & 0x7FFB;
  }
  else
  {
    v37 = (int16_t)v79 - 1;
    for ( n = v37; (word_17F81D[14 * (int16_t)v69[n]] & 4) == 0 && n >= 0; --n )
      --v37;
    if ( v37 >= 0 )
    {
      *a3 = v69[v37];
      *a4 = 4;
    }
    else
    {
      *a3 = 0;
      *a4 = 0;
    }
    v39 = (int16_t)v79;
    *a6 = *((_WORD *)&v68[9] + (int16_t)v79 + 1);
    v40 = v39 - 1;
    *a7 = 0;
    for ( ii = v40; (word_17F81D[14 * (int16_t)v69[ii]] & 2) == 0 && ii >= 0; --ii )
      --v40;
    if ( v40 < 0 )
    {
      *a9 = 0;
      v42 = a10;
LABEL_62:
      *v42 = 0;
      goto LABEL_126;
    }
    *a9 = v69[v40];
    *a10 = 2;
  }
LABEL_126:
  *a8 = 1;
  *a11 = 1;
  *a5 = 1;
  v83 = 0;
  v58 = 20 - sub_5F8D1(v67, 18);
  v59 = 8;
  v60 = v66 * v58;
  while ( v59 < 512 )
  {
    if ( (v59 & *a4) != 0 )
      ++v83;
    v59 *= 2;
  }
  v61 = 8;
  v62 = 0;
  while ( v61 < 512 )
  {
    if ( (v61 & *a7) != 0 )
      ++v62;
    v61 *= 2;
  }
  v63 = 8;
  v64 = 0;
  while ( v63 < 512 )
  {
    v72 = *a10;
    if ( (v63 & v72) != 0 )
      ++v64;
    v63 *= 2;
  }
  v65 = 20 * (int16_t)v83;
  v72 = v60 + v65;
  if ( (int)sub_1247A0(0x64u) < v72 )
  {
    if ( (int)sub_1247A0(0x64u) >= v60 / 2 + v65 )
      *a5 = 2;
    else
      *a5 = 16;
  }
  if ( (int)sub_1247A0(0x64u) < v60 / 2 + 20 * v62 )
    *a8 = 2;
  result = sub_1247A0(0x64u);
  if ( result < ((int)(v60 - (__CFSHL__((uint64_t)v60 >> 32, 2) + 4 * ((uint64_t)v60 >> 32))) >> 2)
              + 20 * v64 )
  {
    result = (signed int)a11;
    *a11 = 2;
  }
  return result;
}
// 60B88: variable 'v67' is possibly undefined
// 60D4A: variable 'v31' is possibly undefined
// 61039: variable 'v44' is possibly undefined
// 61375: variable 'v66' is possibly undefined
// 17E07F: using guessed type int16_t word_17E07F;
// 17F80D: using guessed type int16_t word_17F80D[];
// 17F815: using guessed type int16_t word_17F815[];
// 17F819: using guessed type int16_t word_17F819[];
// 17F81D: using guessed type int16_t word_17F81D[];
// 17FD41: using guessed type char byte_17FD41;
// 17FD50: using guessed type char byte_17FD50;
// 17FD5F: using guessed type char byte_17FD5F;
// 17FD6E: using guessed type char byte_17FD6E;
// 17FD7D: using guessed type char byte_17FD7D;
// 17FD8C: using guessed type char byte_17FD8C;
// 17FE00: using guessed type int16_t word_17FE00[];
// 17FEEE: using guessed type char byte_17FEEE;
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (0006147F) --------------------------------------------------------
void __fastcall sub_6147F( int a1, int a2, int16_t *a3, int a4, int a5)
{
  int16_t v5; // dx
  int v6; // edi
  int v7; // eax
  char v8; // dl
  int v11; // [esp+10h] [ebp-20h] BYREF
  int16_t v12; // [esp+14h] [ebp-1Ch] BYREF
  int v13; // [esp+18h] [ebp-18h] BYREF
  int16_t v14; // [esp+1Ch] [ebp-14h] BYREF
  int v15; // [esp+20h] [ebp-10h] BYREF
  int16_t v16; // [esp+24h] [ebp-Ch] BYREF
  int v17; // [esp+28h] [ebp-8h]
  int v18; // [esp+2Ch] [ebp-4h]

  v5 = *(uint8_t *)(a2 + 16);
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v15 = 0;
  v16 = 0;
  v6 = a1;
  sub_60B59(
    a1,
    v5,
    &v13,
    (int16_t *)&v11,
    &v15,
    (_WORD *)&v13 + 1,
    (int16_t *)&v11 + 1,
    (_WORD *)&v15 + 1,
    &v14,
    &v12,
    &v16);
  LOBYTE(v11) = v11 | 4;
  LOBYTE(v12) = v12 | 2;
  v7 = sub_6EE8E(v6, *((_WORD *)&v13 + a5), 1, *((_WORD *)&v15 + a5), 0, *((_WORD *)&v11 + a5));
  v17 = 0;
  LOWORD(v18) = a4 / v7;
  if ( (int16_t)v18 > 0 && *a3 < 8 && *((_WORD *)&v13 + a5) )
  {
    *(_WORD *)(a2 + 8 * *a3 + 28) = *((_WORD *)&v13 + a5);
    *(_BYTE *)(a2 + 8 * *a3 + 32) = *((_BYTE *)&v15 + 2 * a5);
    for ( *(_WORD *)(a2 + 8 * *a3 + 33) = *((_WORD *)&v11 + a5); ; *(_WORD *)(a2 + 8 * *a3 + 33) = *((_WORD *)&v11 + a5) )
    {
      *(_BYTE *)(a2 + 8 * *a3 + 35) = 0;
      do
      {
        if ( (int16_t)v18 <= 99 || *a3 >= 8 )
        {
          if ( *a3 < 8 )
          {
            v8 = v18;
            *(_BYTE *)(a2 + 8 * *a3 + 30) = v18;
            *(_BYTE *)(a2 + 8 * *a3 + 31) = v8;
            v17 += v18;
          }
          ++*a3;
          sub_6EE8E(a1, *((_WORD *)&v13 + a5), 1, *((_WORD *)&v15 + a5), 0, *((_WORD *)&v11 + a5));
          JUMPOUT(0x608A9);
        }
        *(_BYTE *)(a2 + 8 * *a3 + 30) = 99;
        *(_BYTE *)(a2 + 8 * *a3 + 31) = 99;
        LOWORD(v18) = v18 - 99;
        ++*a3;
        v17 += 99;
      }
      while ( *a3 >= 8 );
      *(_WORD *)(8 * *a3 + a2 + 28) = *((_WORD *)&v13 + a5);
      *(_BYTE *)(8 * *a3 + a2 + 32) = *((_BYTE *)&v15 + 2 * a5);
    }
  }
  JUMPOUT(0x608A7);
}
// 61680: control flows out of bounds to 608A9
// 61528: control flows out of bounds to 608A7


//----- (000616A5) --------------------------------------------------------
int16_t __fastcall sub_616A5( int a1, int a2, int a3)
{
  int v3; // edx
  int v4; // eax
  uint8_t v5; // al
  char v6; // al
  int v7; // edi
  int16_t v8; // si
  int16_t v9; // ax
  int16_t v10; // di
  char v11; // bl
  int16_t v12; // ax
  int v13; // eax
  int v14; // eax
  int v15; // esi
  int v16; // ebx
  uint16_t v17; // cx
  int16_t v18; // ax
  int v19; // eax
  int v20; // esi
  int v21; // eax
  int v22; // esi
  int v23; // eax
  int v24; // esi
  int16_t v25; // ax
  int v26; // eax
  int v27; // esi
  int16_t v28; // ax
  int v29; // eax
  int16_t result; // ax
  int v31; // eax
  int v32; // eax
  int v33; // esi
  int16_t j; // dx
  uint16_t v35; // cx
  int16_t v36; // ax
  int v37; // eax
  int v38; // esi
  int v39; // eax
  int v40; // esi
  int16_t v41; // ax
  int v42; // eax
  int v43; // esi
  int16_t v44; // ax
  int v45; // eax
  int v46; // eax
  int v47; // esi
  int16_t i; // dx
  uint16_t v49; // cx
  int16_t v50; // ax
  int v51; // eax
  int v52; // esi
  int v53; // eax
  int v54; // esi
  int16_t v55; // ax
  int v56; // eax
  int v57; // esi
  int16_t v58; // ax
  int v59; // eax
  int v60; // eax
  int v61; // esi
  int16_t m; // dx
  uint16_t v63; // cx
  int16_t v64; // ax
  int v65; // eax
  int v66; // esi
  int v67; // eax
  int v68; // esi
  int16_t v69; // ax
  int v70; // eax
  int v71; // esi
  int16_t v72; // ax
  int v73; // eax
  int v74; // eax
  int v75; // esi
  int16_t ii; // dx
  uint16_t v77; // cx
  int16_t v78; // ax
  int v79; // eax
  int v80; // esi
  int v81; // eax
  int v82; // esi
  int16_t v83; // ax
  int v84; // eax
  int v85; // esi
  int16_t v86; // ax
  int v87; // eax
  int v88; // esi
  int16_t v89; // ax
  int v90; // eax
  int v91; // eax
  int v92; // esi
  int v93; // eax
  int v94; // esi
  int16_t n; // dx
  uint16_t v96; // cx
  int16_t v97; // ax
  int v98; // eax
  int v99; // esi
  int16_t v100; // ax
  int v101; // eax
  int v102; // esi
  int16_t v103; // ax
  int v104; // eax
  int v105; // eax
  int v106; // esi
  int16_t k; // ax
  int v108; // ebx
  uint16_t v109; // cx
  int16_t v110; // ax
  int v111; // eax
  int v112; // esi
  int v113; // eax
  int v114; // esi
  int v115; // eax
  int v116; // esi
  int16_t v117; // ax
  int v118; // eax
  int v119; // esi
  int16_t v120; // ax
  char v124[16]; // [esp+Ch] [ebp-20h] BYREF
  int v125; // [esp+1Ch] [ebp-10h]
  int v126; // [esp+20h] [ebp-Ch]
  int v127; // [esp+24h] [ebp-8h]
  int v128; // [esp+28h] [ebp-4h] BYREF

  v3 = a1;
  sub_5FA87(a1);
  v127 = v4;
  if ( a3 == 5 && *(_BYTE *)(3753 * v3 + dword_197F98 + 453) == 3 && (int)sub_1247A0(4u) < 4 )
    v127 = 6;
  if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 309) == 3 && a3 > 3 && (int)sub_1247A0(4u) < 4 )
    v127 = 6;
  sub_127776((_BYTE *)a2, 0x63u);
  if ( a3 == 5 )
    *(_BYTE *)(a2 + 92) = 43;
  else
    *(_BYTE *)(a2 + 92) = 8 * a3 + sub_1247A0(8u) - 1;
  if ( a3 == 5 )
    strcpy((char *)a2, (char *)off_1800EE);
  else
    sub_6C897(*(uint8_t *)(dword_197F98 + 3753 * a1 + 37), a3, *(char *)(a2 + 92) % 8, (char *)a2);
  if ( (_WORD)v127 == 7 )
  {
    sub_58F1E(84, v124, 15);
    strcpy((char *)a2, v124);
  }
  *(_WORD *)(a2 + 16) = (uint8_t)a3;
  *(_BYTE *)(a2 + 18) = sub_5679E(a1);
  v5 = sub_56726(a1);
  *(_BYTE *)(a2 + 19) = v5;
  *(_BYTE *)(a2 + 20) = sub_575D6(a1, v5);
  *(_BYTE *)(a2 + 21) = sub_5680D(a1);
  sub_5685F(a1);
  *(_BYTE *)(a2 + 22) = v6;
  LOWORD(v7) = word_180020[18 * a3];
  if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 304) == 3 )
  {
    v7 = (int16_t)v7 + (int16_t)v7 / 2;
    sub_127712(a2 + 23, 4u);
  }
  v125 = a1;
  v8 = 0;
  v9 = sub_6E38E(*(uint8_t *)(a2 + 18), *(uint8_t *)(a2 + 16), a1);
  v128 = 0;
  v10 = v7 - v9;
  switch ( (int16_t)v127 )
  {
    case 0:
      goto LABEL_22;
    case 1:
      v45 = word_181340[12 * a3];
      if ( v45 != -1 )
        v8 = v10 * v45 / 100 - sub_600BF(v125, a2, v10 * v45 / 100, (int16_t *)&v128);
      v46 = word_181346[12 * a3];
      if ( v46 != -1 )
      {
        v47 = v10 * v46 / 100 + v8;
        for ( i = 0; *(_BYTE *)(dword_197F98 + 3753 * i + 36); ++i )
          ;
        v49 = sub_5F8D1(i, 26);
        if ( v49 < (uint16_t)sub_5F8D1(i, 21) )
          v50 = sub_5FE14((int)&unk_18120C, 19, a1, a2, (int16_t)v47, (int16_t *)&v128);
        else
          v50 = sub_5FE14((int)&unk_181258, 19, a1, a2, (int16_t)v47, (int16_t *)&v128);
        v8 = v47 - v50;
      }
      v51 = word_18134C[12 * a3];
      if ( v51 != -1 )
      {
        v52 = v10 * v51 / 100 + v8;
        v8 = v52 - sub_601AC(a1, a2, (int16_t *)&v128, v52);
      }
      v53 = word_181350[12 * a3];
      if ( v53 != -1 )
      {
        v54 = v10 * v53 / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v54, 2);
        v8 = v54 - v55;
      }
      v56 = word_181352[12 * a3];
      if ( v56 != -1 )
      {
        v57 = (v10 * v56 + 50) / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v57, 1);
        v8 = v57 - v58;
      }
      v29 = word_181356[12 * a3];
      goto LABEL_41;
    case 2:
      v31 = word_1813D0[12 * a3];
      if ( v31 != -1 )
        v8 = v10 * v31 / 100 - sub_600BF(v125, a2, v10 * v31 / 100, (int16_t *)&v128);
      v32 = word_1813D6[12 * a3];
      if ( v32 != -1 )
      {
        v33 = v10 * v32 / 100 + v8;
        for ( j = 0; *(_BYTE *)(dword_197F98 + 3753 * j + 36); ++j )
          ;
        v35 = sub_5F8D1(j, 26);
        if ( v35 < (uint16_t)sub_5F8D1(j, 21) )
          v36 = sub_5FE14((int)&unk_18120C, 19, a1, a2, (int16_t)v33, (int16_t *)&v128);
        else
          v36 = sub_5FE14((int)&unk_181258, 19, a1, a2, (int16_t)v33, (int16_t *)&v128);
        v8 = v33 - v36;
      }
      v37 = word_1813DE[12 * a3];
      if ( v37 != -1 )
      {
        v38 = v10 * v37 / 100 + v8;
        v8 = v38 - sub_60779(a1, a2, (int16_t *)&v128, v38, 5u);
      }
      v39 = word_1813E0[12 * a3];
      if ( v39 != -1 )
      {
        v40 = v10 * v39 / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v40, 2);
        v8 = v40 - v41;
      }
      v42 = word_1813E2[12 * a3];
      if ( v42 != -1 )
      {
        v43 = (v10 * v42 + 50) / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v43, 1);
        v8 = v43 - v44;
      }
      v29 = word_1813E6[12 * a3];
      goto LABEL_41;
    case 3:
      v104 = word_181460[12 * a3];
      if ( v104 != -1 )
        v8 = v10 * v104 / 100 - sub_600BF(v125, a2, v10 * v104 / 100, (int16_t *)&v128);
      v105 = word_181466[12 * a3];
      if ( v105 != -1 )
      {
        v106 = v10 * v105 / 100 + v8;
        for ( k = 0; ; ++k )
        {
          v108 = k;
          if ( !*(_BYTE *)(dword_197F98 + 3753 * k + 36) )
            break;
        }
        v109 = sub_5F8D1(k, 26);
        if ( v109 < (uint16_t)sub_5F8D1(v108, 21) )
          v110 = sub_5FE14((int)&unk_18120C, 19, a1, a2, (int16_t)v106, (int16_t *)&v128);
        else
          v110 = sub_5FE14((int)&unk_181258, 19, a1, a2, (int16_t)v106, (int16_t *)&v128);
        v8 = v106 - v110;
      }
      v111 = word_181464[12 * a3];
      if ( v111 != -1 )
      {
        v112 = v10 * v111 / 100 + v8;
        v8 = v112 - sub_5FE14((int)&unk_1811C0, 2, a1, a2, (int16_t)v112, (int16_t *)&v128);
      }
      v113 = word_18146E[12 * a3];
      if ( v113 != -1 )
      {
        v114 = v10 * v113 / 100 + v8;
        v8 = v114 - sub_60779(a1, a2, (int16_t *)&v128, v114, 0xAu);
      }
      v115 = word_181472[12 * a3];
      if ( v115 != -1 )
      {
        v116 = (v10 * v115 + 50) / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v116, 1);
        v8 = v116 - v117;
      }
      v118 = word_181474[12 * a3];
      if ( v118 != -1 )
      {
        v119 = (v10 * v118 + 50) / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v119, 0);
        v8 = v119 - v120;
      }
      v29 = word_181476[12 * a3];
      goto LABEL_41;
    case 4:
      v59 = word_1814F0[12 * a3];
      if ( v59 != -1 )
        v8 = v10 * v59 / 100 - sub_600BF(v125, a2, v10 * v59 / 100, (int16_t *)&v128);
      v60 = word_1814F6[12 * a3];
      if ( v60 != -1 )
      {
        v61 = v10 * v60 / 100 + v8;
        for ( m = 0; *(_BYTE *)(dword_197F98 + 3753 * m + 36); ++m )
          ;
        v63 = sub_5F8D1(m, 26);
        if ( v63 < (uint16_t)sub_5F8D1(m, 21) )
          v64 = sub_5FE14((int)&unk_18120C, 19, a1, a2, (int16_t)v61, (int16_t *)&v128);
        else
          v64 = sub_5FE14((int)&unk_181258, 19, a1, a2, (int16_t)v61, (int16_t *)&v128);
        v8 = v61 - v64;
      }
      v65 = word_1814FC[12 * a3];
      if ( v65 != -1 )
      {
        v66 = v10 * v65 / 100 + v8;
        v8 = v66 - sub_601AC(a1, a2, (int16_t *)&v128, v66);
      }
      v67 = word_181502[12 * a3];
      if ( v67 != -1 )
      {
        v68 = (v10 * v67 + 50) / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v68, 1);
        v8 = v68 - v69;
      }
      v70 = word_181504[12 * a3];
      if ( v70 != -1 )
      {
        v71 = (v10 * v70 + 50) / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v71, 0);
        v8 = v71 - v72;
      }
      v29 = word_181506[12 * a3];
      goto LABEL_41;
    case 5:
      v90 = word_181580[12 * a3];
      if ( v90 != -1 )
        v8 = v10 * v90 / 100 - sub_600BF(v125, a2, v10 * v90 / 100, (int16_t *)&v128);
      v91 = word_18158A[12 * a3];
      if ( v91 != -1 )
      {
        v92 = v10 * v91 / 100 + v8;
        v8 = v92 - sub_5FE14((int)word_1811DC, 12, a1, a2, (int16_t)v92, (int16_t *)&v128);
      }
      v93 = word_181586[12 * a3];
      if ( v93 != -1 )
      {
        v94 = v10 * v93 / 100 + v8;
        for ( n = 0; *(_BYTE *)(dword_197F98 + 3753 * n + 36); ++n )
          ;
        v96 = sub_5F8D1(n, 26);
        if ( v96 < (uint16_t)sub_5F8D1(n, 21) )
          v97 = sub_5FE14((int)&unk_18120C, 19, a1, a2, (int16_t)v94, (int16_t *)&v128);
        else
          v97 = sub_5FE14((int)&unk_181258, 19, a1, a2, (int16_t)v94, (int16_t *)&v128);
        v8 = v94 - v97;
      }
      v98 = word_181590[12 * a3];
      if ( v98 != -1 )
      {
        v99 = v10 * v98 / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v99, 2);
        v8 = v99 - v100;
      }
      v101 = word_181592[12 * a3];
      if ( v101 != -1 )
      {
        v102 = (v10 * v101 + 50) / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v102, 1);
        v8 = v102 - v103;
      }
      v29 = word_181596[12 * a3];
      goto LABEL_41;
    case 6:
      v73 = word_181610[12 * a3];
      if ( v73 != -1 )
        v8 = v10 * v73 / 100 - sub_600BF(v125, a2, v10 * v73 / 100, (int16_t *)&v128);
      v74 = word_181616[12 * a3];
      if ( v74 != -1 )
      {
        v75 = v10 * v74 / 100 + v8;
        for ( ii = 0; *(_BYTE *)(dword_197F98 + 3753 * ii + 36); ++ii )
          ;
        v77 = sub_5F8D1(ii, 26);
        if ( v77 < (uint16_t)sub_5F8D1(ii, 21) )
          v78 = sub_5FE14((int)&unk_18120C, 19, a1, a2, (int16_t)v75, (int16_t *)&v128);
        else
          v78 = sub_5FE14((int)&unk_181258, 19, a1, a2, (int16_t)v75, (int16_t *)&v128);
        v8 = v75 - v78;
      }
      v79 = word_181618[12 * a3];
      if ( v79 != -1 )
      {
        v80 = v10 * v79 / 100 + v8;
        v8 = v80 - sub_5FE14((int)&off_1811C8, 5, a1, a2, (int16_t)v80, (int16_t *)&v128);
      }
      v81 = word_181622[12 * a3];
      if ( v81 != -1 )
      {
        v82 = (v10 * v81 + 50) / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v82, 1);
        v8 = v82 - v83;
      }
      v84 = word_181620[12 * a3];
      if ( v84 != -1 )
      {
        v85 = v10 * v84 / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v85, 2);
        v8 = v85 - v86;
      }
      v87 = word_181624[12 * a3];
      if ( v87 != -1 )
      {
        v88 = (v10 * v87 + 50) / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v88, 0);
        v8 = v88 - v89;
      }
      v29 = word_181626[12 * a3];
      goto LABEL_41;
    case 7:
      if ( *(_BYTE *)(dword_197F98 + 3753 * v125 + 342) == 3 )
      {
        sub_127712(a2 + 23, 0xBu);
        v11 = sub_6F11C(63);
        sub_6D048(v125, 63);
        v10 -= sub_6E60E(word_17F0ED, v12, v11);
      }
LABEL_22:
      v13 = word_1812B0[12 * a3];
      if ( v13 != -1 )
        v8 = v10 * v13 / 100 - sub_600BF(a1, a2, v10 * v13 / 100, (int16_t *)&v128);
      v14 = word_1812B6[12 * a3];
      if ( v14 != -1 )
      {
        v126 = 0;
        v15 = v10 * v14 / 100 + v8;
        while ( 1 )
        {
          v16 = (int16_t)v126;
          if ( !*(_BYTE *)(dword_197F98 + 3753 * (int16_t)v126 + 36) )
            break;
          ++v126;
        }
        v17 = sub_5F8D1((int16_t)v126, 26);
        if ( v17 < (uint16_t)sub_5F8D1(v16, 21) )
          v18 = sub_5FE14((int)&unk_18120C, 19, a1, a2, (int16_t)v15, (int16_t *)&v128);
        else
          v18 = sub_5FE14((int)&unk_181258, 19, a1, a2, (int16_t)v15, (int16_t *)&v128);
        v8 = v15 - v18;
      }
      v19 = word_1812B2[12 * a3];
      if ( v19 != -1 )
      {
        v20 = v10 * v19 / 100 + v8;
        v8 = v20 - sub_5FE14((int)&unk_1811A4, 7, a1, a2, (int16_t)v20, (int16_t *)&v128);
      }
      v21 = word_1812BE[12 * a3];
      if ( v21 != -1 )
      {
        v22 = v10 * v21 / 100 + v8;
        v8 = v22 - sub_60779(a1, a2, (int16_t *)&v128, v22, 2u);
      }
      v23 = word_1812C0[12 * a3];
      if ( v23 != -1 )
      {
        v24 = v10 * v23 / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v24, 2);
        v8 = v24 - v25;
      }
      v26 = word_1812C2[12 * a3];
      if ( v26 != -1 )
      {
        v27 = (v10 * v26 + 50) / 100 + v8;
        sub_6147F(a1, a2, (int16_t *)&v128, v27, 1);
        v8 = v27 - v28;
      }
      v29 = word_1812C6[12 * a3];
LABEL_41:
      if ( v29 != -1 )
        sub_60A5D(a1, a2, (int16_t *)&v128, (int16_t)(v10 * v29 / 100 + v8));
      break;
    default:
      break;
  }
  *(_BYTE *)(a2 + 96) = byte_17FE90[46 * *(uint8_t *)(a2 + 19) + *(uint8_t *)(a2 + 16)];
  *(_BYTE *)(a2 + 93) = a1;
  *(_WORD *)(a2 + 94) = sub_6B577(a1, a2);
  result = dword_192FD8;
  *(_WORD *)(a2 + 97) = dword_192FD8;
  return result;
}
// 616B9: variable 'v4' is possibly undefined
// 61820: variable 'v6' is possibly undefined
// 618E8: variable 'v12' is possibly undefined
// 61A91: variable 'v25' is possibly undefined
// 61AD0: variable 'v28' is possibly undefined
// 61CA2: variable 'v41' is possibly undefined
// 61CE1: variable 'v44' is possibly undefined
// 61E45: variable 'v55' is possibly undefined
// 61E84: variable 'v58' is possibly undefined
// 61FEB: variable 'v69' is possibly undefined
// 6202A: variable 'v72' is possibly undefined
// 6219D: variable 'v83' is possibly undefined
// 621D9: variable 'v86' is possibly undefined
// 62218: variable 'v89' is possibly undefined
// 62388: variable 'v100' is possibly undefined
// 623C7: variable 'v103' is possibly undefined
// 62576: variable 'v117' is possibly undefined
// 625B5: variable 'v120' is possibly undefined
// 17F0ED: using guessed type int16_t word_17F0ED;
// 180020: using guessed type int16_t word_180020[];
// 1800EE: using guessed type _UNKNOWN *off_1800EE;
// 1811C8: using guessed type _UNKNOWN *off_1811C8;
// 1811DC: using guessed type int16_t word_1811DC[];
// 1812B0: using guessed type int16_t word_1812B0[];
// 1812B2: using guessed type int16_t word_1812B2[];
// 1812B6: using guessed type int16_t word_1812B6[];
// 1812BE: using guessed type int16_t word_1812BE[];
// 1812C0: using guessed type int16_t word_1812C0[];
// 1812C2: using guessed type int16_t word_1812C2[];
// 1812C6: using guessed type int16_t word_1812C6[61];
// 181340: using guessed type int16_t word_181340[];
// 181346: using guessed type int16_t word_181346[];
// 18134C: using guessed type int16_t word_18134C[];
// 181350: using guessed type int16_t word_181350[];
// 181352: using guessed type int16_t word_181352[];
// 181356: using guessed type int16_t word_181356[61];
// 1813D0: using guessed type int16_t word_1813D0[];
// 1813D6: using guessed type int16_t word_1813D6[];
// 1813DE: using guessed type int16_t word_1813DE[];
// 1813E0: using guessed type int16_t word_1813E0[];
// 1813E2: using guessed type int16_t word_1813E2[];
// 1813E6: using guessed type int16_t word_1813E6[61];
// 181460: using guessed type int16_t word_181460[];
// 181464: using guessed type int16_t word_181464[];
// 181466: using guessed type int16_t word_181466[];
// 18146E: using guessed type int16_t word_18146E[];
// 181472: using guessed type int16_t word_181472[];
// 181474: using guessed type int16_t word_181474[];
// 181476: using guessed type int16_t word_181476[61];
// 1814F0: using guessed type int16_t word_1814F0[];
// 1814F6: using guessed type int16_t word_1814F6[];
// 1814FC: using guessed type int16_t word_1814FC[];
// 181502: using guessed type int16_t word_181502[];
// 181504: using guessed type int16_t word_181504[];
// 181506: using guessed type int16_t word_181506[61];
// 181580: using guessed type int16_t word_181580[];
// 181586: using guessed type int16_t word_181586[];
// 18158A: using guessed type int16_t word_18158A[];
// 181590: using guessed type int16_t word_181590[];
// 181592: using guessed type int16_t word_181592[];
// 181596: using guessed type int16_t word_181596[61];
// 181610: using guessed type int16_t word_181610[];
// 181616: using guessed type int16_t word_181616[];
// 181618: using guessed type int16_t word_181618[];
// 181620: using guessed type int16_t word_181620[];
// 181622: using guessed type int16_t word_181622[];
// 181624: using guessed type int16_t word_181624[];
// 181626: using guessed type int16_t word_181626[135];
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;


//----- (000625CA) --------------------------------------------------------
_DWORD *sub_625CA()
{
  _DWORD *result; // eax

  dword_19B87C = (int)sub_126AFD((int)off_17CF22, 0, dword_192ED4);
  dword_19B874 = (int)sub_126B42((int)off_17CF22, 11, dword_192ED4);
  dword_19B878 = (int)sub_126B42((int)off_17CF22, 12, dword_192ED4);
  dword_19B86C = (int)sub_126B42((int)off_17CF22, 13, dword_192ED4);
  result = sub_126B42((int)off_17CF22, 14, dword_192ED4);
  dword_19B870 = (int)result;
  return result;
}
// 17CF22: using guessed type char *off_17CF22;
// 192ED4: using guessed type int dword_192ED4;
// 19B86C: using guessed type int dword_19B86C;
// 19B870: using guessed type int dword_19B870;
// 19B874: using guessed type int dword_19B874;
// 19B878: using guessed type int dword_19B878;
// 19B87C: using guessed type int dword_19B87C;


//----- (0006264E) --------------------------------------------------------
void *__usercall sub_6264E(int16_t *a1)
{
  int v1; // ebx
  int v2; // eax

  sub_C5BB9();
  sub_1205E6(11, 0, 255);
  sub_1318D4(0, 255);
  sub_131F7B();
  sub_132C80(100);
  sub_123E6C((int)&unk_17CF00, 1);
  sub_124D41();
  v1 = dword_19B87C;
  sub_12A478(0, 0, dword_19B87C);
  v2 = sub_131922(0, 255);
  sub_1077D(v2, 255, v1, a1);
  sub_C5C44();
  sub_124D7A();
  sub_12A478(0, 0, dword_19B87C);
  return sub_124E36();
}
// 19B87C: using guessed type int dword_19B87C;


//----- (000626D6) --------------------------------------------------------
int16_t sub_626D6()
{
  int v0; // eax
  int v1; // ebx
  int v2; // edi
  int v3; // esi
  int v4; // ecx
  int v5; // edi
  int i; // esi
  _BYTE *v7; // edx
  int16_t result; // ax
  _BYTE v9[8]; // [esp+0h] [ebp-28h]
  _BYTE v10[8]; // [esp+8h] [ebp-20h] BYREF
  _BYTE v11[8]; // [esp+10h] [ebp-18h] BYREF
  int v12; // [esp+18h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-Ch]
  int v14; // [esp+20h] [ebp-8h]
  int v15; // [esp+24h] [ebp-4h]

  v14 = (640 - *(int16_t *)dword_19B874) / 2;
  v13 = (480 - *(int16_t *)(dword_19B874 + 2)) / 2;
  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    v9[v1] = -89;
  }
  while ( (int16_t)v0 < 8 );
  sub_12A478(v14, v13, dword_19B874);
  qmemcpy(v11, sub_8E5C5(1u, 154, 156), sizeof(v11));
  qmemcpy(v10, sub_8E5C5(1u, 154, 159), sizeof(v10));
  v2 = v14;
  v3 = v13;
  sub_120CCB(1, (int)v10);
  v4 = 0;
  v5 = v2 + 14;
  for ( i = v3 + 70; ; i += 9 )
  {
    result = (uint8_t)byte_199CB1;
    if ( (int16_t)v4 >= (uint8_t)byte_199CB1 )
      break;
    v15 = v5;
    v12 = i;
    if ( (int16_t)v4 >= word_19B880 )
      v7 = v11;
    else
      v7 = v10;
    sub_120CCB(1, (int)v7);
    sub_12102B((int16_t)v15, (int16_t)v12, (int16_t)v4 + 1, v4);
    ++v4;
  }
  return result;
}
// 199CB1: using guessed type char byte_199CB1;
// 19B874: using guessed type int dword_19B874;
// 19B880: using guessed type int16_t word_19B880;


//----- (000627DD) --------------------------------------------------------
int __fastcall sub_627DD(_WORD *a1, int16_t *a2, _WORD *a3)
{
  int v4; // eax
  int v6; // [esp+4h] [ebp-8h]
  int16_t v7; // [esp+8h] [ebp-4h]

  sub_625CA();
  if ( word_19B880 > 0 )
    sub_6264E(a2);
  sub_11C2F0();
  v6 = (640 - *(int16_t *)dword_19B874) / 2;
  v4 = (480 - *(int16_t *)(dword_19B874 + 2)) / 2;
  v7 = v4;
  if ( word_19B880 >= 8 )
    *a1 = -1000;
  else
    *a1 = (uint16_t)sub_1151B0(v6 + 125, v4 + 99, (int)&unk_178FD8, (_WORD *)dword_19B878, &unk_178FD8, 40);
  *a2 = (uint16_t)sub_1151B0(v6 + 125, v7 + 136, (int)&unk_178FD8, (_WORD *)dword_19B86C, &unk_178FD8, 40);
  *a3 = (uint16_t)sub_1151B0(v6 + 140, v7 + 200, (int)&unk_178FD8, (_WORD *)dword_19B870, asc_178FD9, 40);
  return sub_1191CA((int)sub_626D6, 2);
}
// 19B86C: using guessed type int dword_19B86C;
// 19B870: using guessed type int dword_19B870;
// 19B874: using guessed type int dword_19B874;
// 19B878: using guessed type int dword_19B878;
// 19B880: using guessed type int16_t word_19B880;


//----- (000628E2) --------------------------------------------------------
void __usercall sub_628E2(int16_t *a1)
{
  int16_t *v1; // ebx
  int v2; // eax
  int v3; // ecx
  int64_t v4; // rax
  char *v5; // eax
  int16_t v6; // ax
  uint16_t v7; // ax
  char *v8; // eax
  int16_t v9; // ax
  int16_t v10; // bx
  int v11; // esi
  int v12; // [esp-10h] [ebp-120h]
  int v13; // [esp-8h] [ebp-118h]
  _BYTE v14[200]; // [esp+0h] [ebp-110h] BYREF
  char v15[20]; // [esp+C8h] [ebp-48h] BYREF
  char v16[20]; // [esp+DCh] [ebp-34h] BYREF
  _BYTE *v17; // [esp+F0h] [ebp-20h]
  int v18; // [esp+F4h] [ebp-1Ch] BYREF
  int16_t v19; // [esp+F8h] [ebp-18h] BYREF
  int v20; // [esp+FCh] [ebp-14h]
  int v21; // [esp+100h] [ebp-10h]
  int v22; // [esp+104h] [ebp-Ch]
  int16_t v23; // [esp+108h] [ebp-8h] BYREF
  int v24; // [esp+10Ch] [ebp-4h]

  word_1999AA = 3;
  sub_627DD(&v18, &v23, &v19);
  v1 = (int16_t *)dword_19B874;
  v20 = (640 - *(int16_t *)dword_19B874) / 2;
  v2 = (480 - *(int16_t *)(dword_19B874 + 2)) / 2;
  v21 = 0;
  word_19B880 = 0;
  v24 = v2;
  sub_1112EC(dword_192EE8, 3753);
  v3 = 0;
  LODWORD(v4) = sub_110D3C(dword_192EE8, 3753);
  v17 = (_BYTE *)v4;
  HIDWORD(v4) = sub_127776((_BYTE *)v4, 0xEA9u);
  while ( 1 )
  {
    if ( (_WORD)v3 )
    {
      sub_11C2F0();
      sub_1113CC(dword_192EE8, SHIDWORD(v4));
      sub_119281();
      if ( (_WORD)v3 == 2 )
      {
        sub_12479((uint8_t)byte_199CB4, (uint8_t)byte_199CB5);
        word_199A08 = 17;
      }
      JUMPOUT(0x627D6);
    }
    v22 = sub_1171AB(v4, SHIDWORD(v4), (int)v1, v3);
    if ( !word_19B880 )
      v22 = v18;
    if ( (_WORD)v22 == v19 )
    {
      word_199A08 = 15;
      v3 = 1;
    }
    if ( (_WORD)v22 == v23 )
    {
      if ( word_19B880 == 1 )
      {
        v5 = sub_7A990(0xA2u);
        sub_77658((int)v5);
        if ( v6 )
        {
          byte_199F3A = 0;
LABEL_11:
          v3 = 2;
          goto LABEL_17;
        }
      }
      else
      {
        strcpy(v15, sub_7A990(0xA5u));
        if ( (uint8_t)byte_199CB1 - word_19B880 == 1 )
          v7 = 164;
        else
          v7 = 165;
        strcpy(v16, sub_7A990(v7));
        a1 = (int16_t *)v16;
        v13 = (uint8_t)byte_199CB1 - word_19B880;
        v12 = word_19B880;
        v8 = sub_7A990(0xA3u);
        v4 = sprintf(v14, v8, v12, v15, v13, v16);
        sub_77658((int)v14);
        if ( (_WORD)v4 )
          goto LABEL_11;
      }
      sub_124D7A();
      v1 = (int16_t *)dword_19B87C;
      HIDWORD(v4) = 0;
      sub_12A478(0, 0, dword_19B87C);
      sub_124E36();
    }
LABEL_17:
    LODWORD(v4) = v22;
    if ( (_WORD)v22 == (_WORD)v18 )
    {
      word_19999C = v21;
      sub_5C510(a1);
      v10 = v9;
      sub_6FB88();
      if ( v10 )
      {
        v11 = 3753 * (int16_t)v21;
        sub_12779E((_BYTE *)(v11 + dword_197F98), v17, 0xEA9u);
        ++v21;
        ++word_19B880;
        *(_BYTE *)(v11 + dword_197F98 + 40) = 100;
      }
      else if ( !word_19B880 )
      {
        v3 = 1;
        word_199A08 = 15;
      }
      v1 = &v19;
      v4 = __PAIR64__(&v23, sub_627DD(&v18, &v23, &v19));
      LOWORD(v4) = (uint8_t)byte_199CB1;
      if ( (uint8_t)byte_199CB1 == word_19B880 )
        v3 = 2;
    }
    if ( !(_WORD)v3 )
    {
      sub_124D41();
      LOWORD(v4) = sub_626D6();
      LODWORD(v4) = sub_1077D(v4, SHIDWORD(v4), (int)v1, a1);
    }
  }
}
// 62BB2: control flows out of bounds to 627D6
// 62AFF: conditional instruction was optimized away because bx.2==0
// 629CA: variable 'v6' is possibly undefined
// 62A7A: variable 'v4' is possibly undefined
// 62ABB: variable 'v9' is possibly undefined
// 12479: using guessed type _DWORD __stdcall sub_12479(_DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 192EE8: using guessed type int dword_192EE8;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 1999AA: using guessed type int16_t word_1999AA;
// 199A08: using guessed type int16_t word_199A08;
// 199CB0: using guessed type char byte_199CB0;
// 199CB1: using guessed type char byte_199CB1;
// 199CB2: using guessed type char byte_199CB2;
// 199CB3: using guessed type char byte_199CB3;
// 199CB4: using guessed type char byte_199CB4;
// 199CB5: using guessed type char byte_199CB5;
// 199F3A: using guessed type char byte_199F3A;
// 19B874: using guessed type int dword_19B874;
// 19B87C: using guessed type int dword_19B87C;
// 19B880: using guessed type int16_t word_19B880;


//----- (00062BB7) --------------------------------------------------------
int sub_62BB7()
{
  return (10 * (word_19999A / 2) / word_199998 + 9) / 10 - 1;
}
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;


//----- (00062BEA) --------------------------------------------------------
int __fastcall sub_62BEA(int a1)
{
  int16_t i; // cx
  int result; // eax
  int16_t j; // bx
  int v5; // eax
  int v6; // edx

  for ( i = 0; i < 72; ++i )
  {
    result = memset(a1 + 288 * i, -1, 288);
    if ( i < word_19999A )
    {
      for ( j = 0; j < word_19999A; ++j )
      {
        if ( i == j )
        {
          result = a1 + 288 * j;
          *(_DWORD *)(result + 4 * j) = 0;
        }
        else
        {
          sub_EBEB7(i, j);
          v6 = v5;
          result = a1 + 288 * i;
          *(_DWORD *)(result + 4 * j) = v6;
        }
      }
    }
  }
  return result;
}
// 62C4A: variable 'v5' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19999A: using guessed type int16_t word_19999A;


//----- (00062C70) --------------------------------------------------------
void __usercall sub_62C70(int a1, int16_t *a2)
{
  int v2; // ebx
  int v3; // eax
  int i; // edx
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // ebx
  int v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int j; // ebx
  int16_t *v17; // [esp+0h] [ebp-4h]

  sub_124820(dword_199CB6);
  sub_12484C();
  sub_1112EC(dword_192ED4, 34048);
  dword_19B888 = (int)sub_110D3C(dword_192ED4, 34048);
  dword_19B884 = (int)sub_110D3C(dword_192ED4, 20736);
  dword_19B894 = (int)sub_110D3C(dword_192ED4, 360);
  dword_19B890 = (int)sub_110D3C(dword_192ED4, 72);
  dword_19B88C = (int)sub_110D3C(dword_192ED4, 968);
  memset(dword_19B888, 0, 34048);
  memset(dword_19B884, 0, 20736);
  memset(dword_19B894, -1, 360);
  memset(dword_19B890, -1, 72);
  v2 = 968;
  v3 = memset(dword_19B88C, -1, 968);
  for ( i = 0; (int16_t)i < word_199998; ++i )
  {
    a1 = 3753 * (int16_t)i;
    LOWORD(a1) = *(_WORD *)(a1 + dword_197F98 + 41);
    v5 = 17 * (int16_t)a1;
    LOWORD(v5) = *(uint8_t *)(dword_1930D4 + v5 + 2);
    v17 = (int16_t *)v5;
    v6 = 0;
    do
    {
      v7 = 10 * (int16_t)v6++;
      *(_WORD *)(v7 + dword_19B888 + 4256 * (int16_t)i + 663) = -1;
    }
    while ( (int16_t)v6 < 360 );
    v8 = 0;
    do
    {
      v9 = 4256 * (int16_t)i + dword_19B888;
      v10 = (int16_t)v8;
      *(_WORD *)(v9 + 4 * (int16_t)v8++ + 370) = 9999;
      *(_WORD *)(v9 + 4 * v10 + 368) = -1;
    }
    while ( (int16_t)v8 < 72 );
    v2 = (int16_t)v17;
    a2 = v17;
    *(_WORD *)(v9 + 4 * (int16_t)v17 + 368) = (_WORD)v17;
    *(_BYTE *)((int16_t)v17 + dword_19B890) = i;
    v3 = 10 * (int16_t)a1;
    *(_BYTE *)(v9 + v3 + 656) = 1;
    *(_BYTE *)(v9 + v3 + 665) = 1;
    *(_DWORD *)(v9 + v3 + 659) = -32766;
    *(_WORD *)(v9 + v3 + 663) = a1;
  }
  sub_FE8BE(v3, i, v2, a2);
  v11 = sub_62BEA(dword_19B884);
  sub_FE8BE(v11, i, v2, a2);
  sub_63577(v12, i, v2, a1);
  sub_FE8BE(v13, i, v2, a2);
  sub_638A9();
  sub_FE8BE(v14, i, v2, a2);
  for ( j = 0; (int16_t)j < word_1999A2; ++j )
  {
    LOWORD(i) = *(char *)((int16_t)j + dword_19B894);
    v15 = *(char *)((int16_t)j + dword_19B894);
    if ( v15 != -1 )
    {
      i = *(char *)((int16_t)j + dword_19B894);
      sub_13FB8();
    }
  }
  sub_FE8BE(v15, i, j, a2);
  sub_1113CC(dword_192ED4, i);
  JUMPOUT(0x62C69);
}
// 62E93: control flows out of bounds to 62C69
// 62E42: variable 'v12' is possibly undefined
// 62E47: variable 'v13' is possibly undefined
// 62E51: variable 'v14' is possibly undefined
// 62E84: variable 'v15' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 1999A2: using guessed type int16_t word_1999A2;
// 199CB6: using guessed type int dword_199CB6;
// 19B884: using guessed type int dword_19B884;
// 19B888: using guessed type int dword_19B888;
// 19B88C: using guessed type int dword_19B88C;
// 19B890: using guessed type int dword_19B890;
// 19B894: using guessed type int dword_19B894;


//----- (00062E98) --------------------------------------------------------
void sub_62E98()
{
  int16_t v0; // si
  int16_t i; // bx
  int16_t j; // cx
  int16_t *v3; // eax
  int16_t v4; // cx
  int16_t k; // dx
  int16_t v6; // ax
  int16_t v7; // di
  int v8; // eax

  v0 = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    *(_WORD *)(4256 * i + dword_19B888) = 0;
    for ( j = 1; j < 72; ++j )
    {
      v3 = (int16_t *)(4 * j
                     + 288 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_197F98 + 3753 * i + 41) + 2)
                     + dword_19B884);
      if ( v0 < *(_DWORD *)v3 )
        v0 = *v3;
    }
    v4 = 1;
    *(_WORD *)(dword_19B888 + 4256 * i + 6) = v0;
    do
    {
      if ( v4 < word_19999A && *(_BYTE *)(113 * v4 + dword_19306C + 40) != 9 && sub_633FE(i, v4) )
      {
        for ( k = 1; k < word_19999A; ++k )
        {
          v6 = *(_WORD *)(4 * k + dword_19B884 + 288 * v4);
          if ( v6 <= 9 && *(_BYTE *)(dword_19306C + 113 * k + 40) != 9 )
          {
            v7 = *(_WORD *)(4 * k + 4256 * i + dword_19B888 + 370);
            if ( v7 > v6 )
              v7 = *(_WORD *)(4 * k + dword_19B884 + 288 * v4);
            v8 = 4 * k + 4256 * i + dword_19B888;
            *(_WORD *)(v8 + 370) = v7;
            *(_WORD *)(v8 + 368) = k;
          }
        }
      }
      ++v4;
    }
    while ( v4 < 72 );
  }
  sub_63035();
  sub_63156();
  JUMPOUT(0x62C69);
}
// 63030: control flows out of bounds to 62C69
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19B884: using guessed type int dword_19B884;
// 19B888: using guessed type int dword_19B888;


//----- (00063035) --------------------------------------------------------
void sub_63035()
{
  int16_t i; // cx
  int16_t j; // si
  _WORD *v2; // eax
  _WORD *v3; // edx
  int16_t v4; // ax
  int v5; // edx
  int16_t *v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // [esp+4h] [ebp-14h]
  int16_t v10; // [esp+Ch] [ebp-Ch]
  int16_t v11; // [esp+10h] [ebp-8h]
  int16_t v12; // [esp+14h] [ebp-4h]

  for ( i = 0; i < word_199998; ++i )
  {
    for ( j = 0; j < 72; ++j )
    {
      v2 = (_WORD *)(4256 * i + dword_19B888);
      v3 = &v2[2 * j];
      if ( (int16_t)v3[185] <= 9 )
      {
        v11 = v3[184];
        if ( v11 > 0 )
        {
          v12 = 0;
          ++*v2;
          do
          {
            v4 = *(_WORD *)(113 * v11 + dword_19306C + 2 * v12 + 74);
            v10 = v4;
            v5 = 4256 * i + dword_19B888;
            v9 = 4256 * i;
            if ( v4 > -1 )
            {
              v6 = (int16_t *)(dword_1930D4 + 17 * v4);
              if ( *((_BYTE *)v6 + 4) == 3 && !*(_BYTE *)(v5 + v10 + 8) && *v6 == -1 )
              {
                v7 = 10 * *(int16_t *)(v5 + 2);
                memset(v7 + v5 + 656, 0, 10);
                v8 = v9 + dword_19B888;
                *(_WORD *)(v9 + dword_19B888 + v7 + 663) = v10;
                ++*(_WORD *)(v8 + 2);
                *(_BYTE *)(v10 + v8 + 8) = 1;
              }
            }
            ++v12;
          }
          while ( v12 < 5 );
        }
      }
    }
  }
  JUMPOUT(0x62C69);
}
// 63151: control flows out of bounds to 62C69
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 199998: using guessed type int16_t word_199998;
// 19B888: using guessed type int dword_19B888;


//----- (00063156) --------------------------------------------------------
void sub_63156()
{
  int16_t i; // si
  int v1; // eax
  int16_t v2; // di
  int16_t v3; // dx
  int v4; // edx
  int v5; // eax
  int v6; // [esp+0h] [ebp-10h] BYREF
  int v7; // [esp+4h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-8h] BYREF
  _BYTE v9[4]; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    v1 = 4256 * i;
    LOWORD(v1) = *(_WORD *)(dword_19B888 + v1 + 2);
    v2 = 0;
    v7 = v1;
    while ( v2 < (int16_t)v7 )
    {
      v3 = *(_WORD *)(10 * v2 + 4256 * i + dword_19B888 + 663);
      v6 = 0;
      v9[0] = 0;
      v8 = 0;
      if ( *(char *)(v3 + dword_19B894) == -1 )
        sub_63259(i, v3, &v6, v9, (int16_t *)&v8);
      v4 = 4256 * i + dword_19B888 + 10 * v2;
      *(_DWORD *)(v4 + 659) = v6;
      *(_BYTE *)(v4 + 656) = v9[0];
      ++v2;
      *(_WORD *)(v4 + 657) = v8;
    }
    v5 = dword_19B888 + 4256 * i + 656;
    qsort(v5, 360, 10);
  }
  JUMPOUT(0x62C69);
}
// 63254: control flows out of bounds to 62C69
// 199998: using guessed type int16_t word_199998;
// 19B888: using guessed type int dword_19B888;
// 19B894: using guessed type int dword_19B894;


//----- (00063259) --------------------------------------------------------
int __fastcall sub_63259(int result, int a2, int *a3, _BYTE *a4, int16_t *a5)
{
  int v5; // eax
  int16_t v6; // ax
  int v7; // edi
  int16_t v8; // [esp+8h] [ebp-8h]
  int16_t v9; // [esp+Ch] [ebp-4h]

  v9 = result;
  *a5 = 0;
  *a3 = 0;
  *a4 = 0;
  if ( a2 <= -1 )
  {
    *a3 = -1;
  }
  else
  {
    v5 = 17 * a2 + dword_1930D4;
    v8 = *(uint8_t *)(v5 + 2);
    *a3 = (uint16_t)sub_D27A7(v5, (_BYTE *)(3753 * v9 + dword_197F98));
    v6 = sub_63312(v9, a2);
    v7 = dword_19B890;
    *a5 = *a3 * v6 / 100;
    if ( *(char *)(v7 + v8) == v9 )
    {
      *a3 = 67 * *a3 / 100;
      *a4 = 1;
    }
    result = *a5;
    *a3 += result;
  }
  return result;
}
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19B890: using guessed type int dword_19B890;


//----- (00063312) --------------------------------------------------------
int __fastcall sub_63312( int a1, int a2)
{
  int16_t v3; // bx
  int result; // eax
  int16_t v5; // si
  int v6; // edx
  int16_t v7; // [esp+0h] [ebp-8h]

  v3 = 0;
  v7 = *(uint8_t *)(dword_1930D4 + 17 * a2 + 2);
  result = 0;
  while ( v3 < word_19999A )
  {
    v5 = *(_WORD *)(4256 * a1 + dword_19B888 + 4 * v3 + 368);
    if ( *(char *)(dword_19B890 + v5) == a1 )
    {
      v6 = v7;
      LOWORD(v6) = *(_WORD *)(dword_19B884 + 288 * v5 + 4 * v7);
      if ( (int16_t)v6 <= 9 )
      {
        if ( (uint16_t)v6 < 3u )
        {
          if ( (_WORD)v6 )
            result += 20;
        }
        else if ( (uint16_t)v6 <= 4u )
        {
          result += 10;
        }
        else if ( (_WORD)v6 == 5 )
        {
          result += v6;
        }
      }
    }
    ++v3;
  }
  return result;
}
// 1930D4: using guessed type int dword_1930D4;
// 19999A: using guessed type int16_t word_19999A;
// 19B884: using guessed type int dword_19B884;
// 19B888: using guessed type int dword_19B888;
// 19B890: using guessed type int dword_19B890;


//----- (000633D5) --------------------------------------------------------
_BOOL1 __fastcall sub_633D5( int a1, int a2)
{
  char *v3; // eax
  char v4; // dl

  v3 = (char *)(dword_19B890 + a2);
  v4 = 0;
  if ( *v3 > -1 )
    return *v3 != a1;
  return v4;
}
// 19B890: using guessed type int dword_19B890;


//----- (000633FE) --------------------------------------------------------
_BOOL1 __fastcall sub_633FE( int a1, int a2)
{
  return *(char *)(a2 + dword_19B890) == a1;
}
// 19B890: using guessed type int dword_19B890;


//----- (0006341C) --------------------------------------------------------
void __fastcall sub_6341C( int a1, int a2)
{
  _WORD *v3; // eax
  int16_t v4; // bx
  int v5; // eax
  int16_t i; // dx
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int16_t v11; // [esp+4h] [ebp-18h]
  int16_t v12; // [esp+8h] [ebp-14h]
  int16_t v13; // [esp+14h] [ebp-8h]
  _BOOL1 v14; // [esp+18h] [ebp-4h]

  v13 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(3753 * a1 + dword_197F98 + 41) + 2);
  v3 = (_WORD *)(dword_19B888 + 4256 * a1);
  v4 = -1;
  if ( (int16_t)((10 * (word_19999A / 2) / word_199998 + 9) / 10 - 1) > (int16_t)v3[2] )
  {
    v12 = v3[1];
    v5 = 4 * (int16_t)v3[3] / 10;
    if ( (uint8_t)byte_199CB2 + 9 >= v5 )
      LOWORD(v5) = (uint8_t)byte_199CB2 + 9;
    v11 = v5;
    for ( i = 0; i < v12 && v4 == -1; ++i )
    {
      v7 = *(int16_t *)(4256 * a1 + dword_19B888 + 10 * i + 663);
      if ( v7 > -1 && *(char *)(a2 + v7) == -1 )
      {
        v8 = 17 * v7 + dword_1930D4;
        v9 = *(uint8_t *)(v8 + 2);
        v14 = 0;
        if ( *(char *)(dword_19B890 + v9) > -1 )
          v14 = *(char *)(dword_19B890 + *(uint8_t *)(v8 + 2)) != a1;
        if ( !v14 && *(int16_t *)(288 * v13 + dword_19B884 + 4 * v9) <= v11 )
          v4 = i;
      }
    }
  }
  JUMPOUT(0x633CF);
}
// 63572: control flows out of bounds to 633CF
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 199CB2: using guessed type char byte_199CB2;
// 19B884: using guessed type int dword_19B884;
// 19B888: using guessed type int dword_19B888;
// 19B890: using guessed type int dword_19B890;


//----- (00063577) --------------------------------------------------------
void __fastcall sub_63577(int a1, int a2, int a3, int a4)
{
  int16_t i; // ax
  int16_t v5; // si
  int v6; // eax
  int16_t v7; // ax
  int v8; // ebx
  int16_t v9; // ax
  int16_t v10; // dx
  int16_t v11; // bx
  int16_t v12; // bx
  int16_t j; // dx
  int16_t k; // dx
  int v15; // esi
  int v16; // eax
  char *v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // esi
  int v21; // ebx
  int v22; // esi
  int16_t m; // dx
  int16_t v24; // ax
  int16_t n; // ax
  _WORD v26[8]; // [esp+0h] [ebp-3Ch] BYREF
  _WORD v27[8]; // [esp+10h] [ebp-2Ch] BYREF
  int v28; // [esp+20h] [ebp-1Ch]
  int v29; // [esp+24h] [ebp-18h]
  int v30; // [esp+28h] [ebp-14h]
  int v31; // [esp+2Ch] [ebp-10h]
  int v32; // [esp+30h] [ebp-Ch]
  int v33; // [esp+34h] [ebp-8h]
  int16_t v34; // [esp+38h] [ebp-4h]

  v31 = (10 * (word_19999A / 2) / word_199998 + 9) / 10 - 1;
  LOWORD(a4) = word_199998;
  memset(v27, -1, sizeof(v27));
  for ( i = 0; i < word_199998; ++i )
    v27[i] = i;
  while ( 1 )
  {
    memset(v26, -1, sizeof(v26));
    sub_62E98();
    v5 = 0;
    sub_79F26((int)v27, 8, 0);
    do
    {
      v6 = 2 * v5;
      if ( *(int16_t *)((char *)v27 + v6) != -1 )
      {
        v7 = v27[v5];
        v8 = v7;
        v34 = v7;
        sub_6341C(v7, dword_19B894);
        v10 = v9;
        v29 = v9;
        v6 = 2 * v8;
        if ( v29 == -1 )
        {
          --a4;
          v27[v8] = -1;
        }
        else
        {
          v28 = *(int16_t *)(10 * v29 + dword_19B888 + 4256 * v8 + 663);
          v11 = *(uint8_t *)(dword_1930D4 + 17 * v28 + 2);
          *(_WORD *)((char *)v26 + v6) = v10;
          *(_BYTE *)(v28 + dword_19B894) = v34;
          v6 = dword_19B890 + v11;
          *(_BYTE *)v6 = v34;
        }
      }
      ++v5;
    }
    while ( v5 < 8 );
    v12 = 0;
    for ( j = 0; j < word_199998; ++j )
    {
      v6 = (int16_t)v26[j];
      if ( v6 != -1 )
        ++v12;
    }
    if ( v12 == word_199998 )
    {
      for ( k = 0; k < word_199998; ++k )
      {
        LOWORD(v6) = v26[k];
        v33 = v6;
        if ( (int16_t)v6 != -1 )
        {
          v15 = 10 * (int16_t)v6;
          v28 = 4256 * k;
          v16 = v28 + dword_19B888;
          LOWORD(v15) = *(_WORD *)(v15 + v28 + dword_19B888 + 663);
          LOWORD(v16) = *(_WORD *)(v28 + dword_19B888 + 2);
          v32 = v16;
          v17 = (char *)(121 * k + dword_19B88C);
          v30 = v15;
          if ( *v17 < 0 )
            *v17 = 0;
          v18 = 121 * k + dword_19B88C + 6 * *v17;
          v28 = 121 * k + dword_19B88C;
          *(_WORD *)(v18 + 1) = v30;
          *(_DWORD *)(v28 + 6 * (*v17)++ + 3) = *(_DWORD *)(dword_19B888 + 4256 * k + 10 * (int16_t)v33 + 659);
          if ( *v17 >= 20 )
            *v17 = 19;
          v19 = dword_19B888 + 4256 * k;
          v20 = v19 + 10 * (int16_t)v33;
          ++*(_WORD *)(v19 + 4);
          *(_BYTE *)(v20 + 665) = 1;
          *(_DWORD *)(v20 + 659) = -32766;
          if ( (int16_t)v32 > 1 )
          {
            v21 = 10 * ((int16_t)v32 - 1);
            *(_DWORD *)(v20 + 656) = *(_DWORD *)(v21 + v19 + 656);
            *(_DWORD *)(v20 + 660) = *(_DWORD *)(v21 + v19 + 660);
            *(_WORD *)(v20 + 664) = *(_WORD *)(v21 + v19 + 664);
          }
          v6 = 4256 * k;
          v22 = dword_19B888;
          --*(_WORD *)(dword_19B888 + v6 + 2);
          if ( *(int16_t *)(v22 + v6 + 4) >= (int16_t)v31 )
          {
            --a4;
            v27[k] = -1;
          }
        }
      }
    }
    else
    {
      for ( m = 0; m < word_199998; ++m )
      {
        v24 = v26[m];
        if ( v24 > -1 && v24 < 360 )
          *(_BYTE *)(v24 + dword_19B894) = -1;
      }
      a4 = 0;
    }
    for ( n = 0; n < word_199998; ++n )
      ;
    if ( (int16_t)a4 <= 0 )
      JUMPOUT(0x62C69);
  }
}
// 63843: control flows out of bounds to 62C69
// 6362B: variable 'v9' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1930D4: using guessed type int dword_1930D4;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19B888: using guessed type int dword_19B888;
// 19B88C: using guessed type int dword_19B88C;
// 19B890: using guessed type int dword_19B890;
// 19B894: using guessed type int dword_19B894;


//----- (00063848) --------------------------------------------------------
int sub_63848()
{
  int16_t i; // dx
  int result; // eax

  for ( i = 0; i < word_199998; ++i )
    result = nullsub_2(i);
  return result;
}
// 13FB7: using guessed type int __fastcall nullsub_2(_DWORD);
// 199998: using guessed type int16_t word_199998;


//----- (00063861) --------------------------------------------------------
void __fastcall sub_63861( int a1, int a2)
{
  int v4; // edx
  int16_t i; // bx
  int v6; // eax

  v4 = 0;
  for ( i = 0; i < 20 && !v4; ++i )
  {
    v6 = dword_19B88C + 121 * a1 + 6 * i;
    if ( a2 == *(_WORD *)(v6 + 1) )
      v4 = *(_DWORD *)(v6 + 3);
  }
  JUMPOUT(0x633CF);
}
// 638A4: control flows out of bounds to 633CF
// 19B88C: using guessed type int dword_19B88C;


//----- (000638A9) --------------------------------------------------------
void sub_638A9()
{
  int v0; // edi
  int v1; // ebx
  int v2; // eax
  int16_t i; // di
  int16_t j; // dx
  int16_t v5; // ax
  int16_t k; // di
  int16_t m; // si
  int v8; // eax
  int v9; // edx
  char v10; // al
  uint8_t *v11; // eax
  int v12; // eax
  int v13; // edx
  int16_t v14; // ax
  int16_t n; // cx
  int16_t v16; // ax
  _WORD v17[8]; // [esp+0h] [ebp-38h] BYREF
  int v18; // [esp+10h] [ebp-28h]
  int v19; // [esp+14h] [ebp-24h]
  _BYTE v20[4]; // [esp+18h] [ebp-20h] BYREF
  int v21; // [esp+1Ch] [ebp-1Ch]
  int v22; // [esp+20h] [ebp-18h]
  int16_t v23; // [esp+24h] [ebp-14h] BYREF
  int v24; // [esp+28h] [ebp-10h]
  char v25[4]; // [esp+2Ch] [ebp-Ch] BYREF
  char v26; // [esp+30h] [ebp-8h]
  char v27; // [esp+34h] [ebp-4h]

  v21 = 0;
  v24 = 0;
  memset(v17, 0, sizeof(v17));
  v0 = 0;
  byte_182247 = 0;
  while ( (int16_t)v0 < word_199998 )
  {
    v1 = (int16_t)v21;
    sub_63CA0(v0);
    if ( v2 > v1 )
    {
      v21 = v2;
      v24 = v0;
    }
    ++v0;
  }
  for ( i = 0; i < word_199998; ++i )
  {
    for ( j = 0; j < word_1999A2; ++j )
    {
      if ( *(char *)(j + dword_19B894) == i )
      {
        v5 = *(char *)(dword_1930D4 + 17 * j + 15);
        if ( v5 == 5 || v5 == 4 || v5 == 10 )
          ++v17[i];
      }
    }
  }
  for ( k = 0; k < word_199998; ++k )
  {
    if ( k != (_WORD)v24 )
    {
      v27 = 0;
      for ( m = 0; m < word_1999A2 && !v27; ++m )
      {
        if ( *(char *)(m + dword_19B894) == k )
        {
          v8 = 17 * m + dword_1930D4;
          v20[0] = 4 - *(_BYTE *)(v8 + 5);
          v9 = 8 - *(uint8_t *)(v8 + 8);
          v26 = 0;
          v10 = v9;
          if ( v9 <= 0 )
            v10 = 0;
          v20[1] = v10;
          v11 = (uint8_t *)(17 * m + dword_1930D4);
          v20[2] = 4 - v11[10];
          v18 = k;
          if ( v17[k] < v17[(int16_t)v24] && !v11[15] && !*(_BYTE *)(113 * v11[2] + dword_19306C + 40) )
          {
            v12 = 3753 * v18 + dword_197F98;
            v22 = 0;
            if ( m == *(_WORD *)(v12 + 41) && *(_BYTE *)(v12 + 2223) )
            {
              v25[0] = 0;
            }
            else
            {
              do
              {
                sub_8C840(*(uint8_t *)(17 * m + dword_1930D4 + 2), &v23, v25, 0, 0);
                if ( v25[0] == 5 || v25[0] == 4 || v25[0] == 10 )
                  v22 = 100;
                else
                  v25[0] = 0;
                ++v22;
              }
              while ( (int16_t)v22 < 100 );
            }
            if ( v25[0] > 0 )
            {
              v13 = dword_1930D4 + 17 * m;
              *(_BYTE *)(v13 + 15) = v25[0];
              ++v17[k];
              *(_BYTE *)(113 * *(uint8_t *)(v13 + 2) + dword_19306C + 40) = v25[0];
            }
            sub_63CA0(k);
            if ( v14 >= 90 * (int16_t)v21 / 100 )
              v27 = 1;
          }
          for ( n = 0; n < 6 && !v27 && !v26; ++n )
          {
            v26 = sub_63B8F(m, (int)v20);
            sub_8C6C0(*(uint8_t *)(dword_1930D4 + 17 * m + 2), m);
            sub_63CA0(k);
            v19 = 100;
            if ( v16 >= 90 * (int16_t)v21 / 100 )
              v27 = 1;
          }
        }
      }
    }
  }
  JUMPOUT(0x62C69);
}
// 63B55: control flows out of bounds to 62C69
// 638EA: variable 'v2' is possibly undefined
// 63AC4: variable 'v14' is possibly undefined
// 63B15: variable 'v16' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 182247: using guessed type char byte_182247;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 1999A2: using guessed type int16_t word_1999A2;
// 19B894: using guessed type int dword_19B894;


//----- (00063B5A) --------------------------------------------------------
void sub_63B5A()
{
  int16_t i; // bx

  for ( i = 0; i < word_1999A2; ++i )
  {
    if ( *(char *)(i + dword_19B894) != -1 )
      sub_13FB8();
  }
}
// 1999A2: using guessed type int16_t word_1999A2;
// 19B894: using guessed type int dword_19B894;


//----- (00063B8F) --------------------------------------------------------
char __fastcall sub_63B8F( int a1, int a2)
{
  uint16_t v3; // ax
  int v5; // esi
  int v6; // esi
  char v7; // [esp+0h] [ebp-10h]
  char v8; // [esp+4h] [ebp-Ch]
  char v9; // [esp+8h] [ebp-8h]

  v3 = sub_FE8DA(a2, 3);
  if ( (int16_t)v3 == -1 )
    return 1;
  if ( v3 )
  {
    if ( v3 <= 1u )
    {
      if ( *(uint8_t *)(dword_1930D4 + 17 * a1 + 8) + 1 <= 9 )
        v8 = *(_BYTE *)(dword_1930D4 + 17 * a1 + 8) + 1;
      else
        v8 = 9;
      *(_BYTE *)(dword_1930D4 + 17 * a1 + 8) = v8;
    }
    else
    {
      if ( v3 != 2 )
        return 0;
      v6 = 17 * a1;
      if ( *(uint8_t *)(v6 + dword_1930D4 + 10) + 1 <= 4 )
        v9 = *(_BYTE *)(v6 + dword_1930D4 + 10) + 1;
      else
        v9 = 4;
      *(_BYTE *)(dword_1930D4 + 17 * a1 + 10) = v9;
    }
  }
  else
  {
    v5 = 17 * a1;
    if ( *(uint8_t *)(v5 + dword_1930D4 + 5) + 1 <= 4 )
      v7 = *(_BYTE *)(v5 + dword_1930D4 + 5) + 1;
    else
      v7 = 4;
    *(_BYTE *)(dword_1930D4 + 17 * a1 + 5) = v7;
  }
  --*(_BYTE *)(a2 + (int16_t)v3);
  return 0;
}
// 1930D4: using guessed type int dword_1930D4;


//----- (00063CA0) --------------------------------------------------------
void __fastcall sub_63CA0( int a1)
{
  int16_t i; // si
  int v3; // [esp+0h] [ebp-10h] BYREF
  int v4; // [esp+4h] [ebp-Ch]
  int16_t v5; // [esp+8h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  for ( i = 0; i < word_1999A2; ++i )
  {
    if ( *(char *)(i + dword_19B894) == a1 )
    {
      sub_63259(a1, i, &v3, v6, &v5);
      v4 += v3;
    }
  }
  JUMPOUT(0x62C69);
}
// 63D05: control flows out of bounds to 62C69
// 1999A2: using guessed type int16_t word_1999A2;
// 19B888: using guessed type int dword_19B888;
// 19B894: using guessed type int dword_19B894;


//----- (00063D0A) --------------------------------------------------------
int __fastcall sub_63D0A(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // edx
  char v7[7]; // [esp+0h] [ebp-34h] BYREF
  char v8[7]; // [esp+14h] [ebp-20h] BYREF
  int v9; // [esp+28h] [ebp-Ch] BYREF
  int16_t v10; // [esp+2Ch] [ebp-8h] BYREF
  _BYTE v11[4]; // [esp+30h] [ebp-4h] BYREF

  if ( a4 )
  {
    sub_63861(a2, a3);
    v9 = v4;
  }
  else
  {
    sub_63259(a2, a3, &v9, v11, &v10);
  }
  v5 = 17 * a3;
  strcpy(v8, (char *)dword_18F990[*(uint8_t *)(v5 + dword_1930D4 + 8)]);
  strcpy(v7, (char *)dword_192BF4[*(uint8_t *)(v5 + dword_1930D4 + 10)]);
  return v9;
}
// 63D25: variable 'v4' is possibly undefined
// 18F990: using guessed type int dword_18F990[];
// 192BF4: using guessed type int dword_192BF4[];
// 1930D4: using guessed type int dword_1930D4;


//----- (00063D92) --------------------------------------------------------
void __usercall sub_63D92( int a1)
{
  char v1; // al
  char v2; // al

  if ( dword_192FD8 == 35000 )
    byte_19B89A = 0;
  sub_645EC();
  sub_63FCB();
  sub_63F9C();
  sub_63EDD();
  if ( v1 )
  {
    word_199174 = 0;
    sub_643A0(a1);
    if ( v2 )
      dword_1991B1 = dword_192FD8;
  }
}
// 63DBB: variable 'v1' is possibly undefined
// 63DCD: variable 'v2' is possibly undefined
// 192FD8: using guessed type int dword_192FD8;
// 199174: using guessed type int16_t word_199174;
// 1991B1: using guessed type int dword_1991B1;
// 19B89A: using guessed type char byte_19B89A;


//----- (00063DDA) --------------------------------------------------------
int sub_63DDA()
{
  int v0; // ebx
  int v1; // edx
  int v2; // eax

  v0 = 0;
  v1 = 0;
  do
  {
    v2 = (int16_t)v1;
    LOWORD(v2) = word_19917A[(int16_t)v1] * (uint8_t)byte_181734[(int16_t)v1];
    ++v1;
    v0 += v2;
  }
  while ( (int16_t)v1 < 9 );
  return v0;
}
// 19917A: using guessed type int16_t word_19917A[4];


//----- (00063E4C) --------------------------------------------------------
int sub_63E4C()
{
  int result; // eax

  result = 0;
  if ( !byte_199CB5 )
    return 200;
  if ( (uint8_t)byte_199CB5 <= 1u )
    return 100;
  return result;
}
// 199CB5: using guessed type char byte_199CB5;


//----- (00063E73) --------------------------------------------------------
void sub_63E73()
{
  int v0; // ebx
  int v1; // edx
  int v2; // eax

  v0 = 0;
  v1 = 0;
  do
  {
    v2 = (int16_t)v1;
    LOWORD(v2) = word_19918C[(int16_t)v1] * (uint8_t)byte_181734[(int16_t)v1];
    ++v1;
    v0 += v2;
  }
  while ( (int16_t)v1 < 9 );
  JUMPOUT(0x63E00);
}
// 63E99: control flows out of bounds to 63E00
// 19918C: using guessed type int16_t word_19918C[9];


//----- (00063E9E) --------------------------------------------------------
int16_t sub_63E9E()
{
  int16_t v0; // cx
  int v1; // eax
  int16_t v2; // dx
  int16_t v3; // ax

  v0 = 0;
  v1 = 0;
  do
  {
    v2 = word_19917A[(int16_t)v1] * (uint8_t)byte_181734[(int16_t)v1];
    ++v1;
    v0 += v2;
  }
  while ( (int16_t)v1 < 9 );
  sub_63E73();
  return word_199178 + word_199176 + v0 + v3;
}
// 63EC9: variable 'v3' is possibly undefined
// 199176: using guessed type int16_t word_199176;
// 199178: using guessed type int16_t word_199178;
// 19917A: using guessed type int16_t word_19917A[4];


//----- (00063EDD) --------------------------------------------------------
void sub_63EDD()
{
  int16_t v0; // dx
  _BOOL1 v1; // bl
  int16_t v2; // si
  int16_t v3; // ax
  int16_t v4; // di
  int v5; // edx
  int16_t v6; // di
  int16_t v7; // ax
  int16_t i; // dx

  v0 = sub_63DDA();
  sub_63E73();
  v1 = 0;
  v2 = 0;
  v4 = word_199176 + v0 + v3;
  v5 = 0;
  v6 = word_199178 + v4;
  do
  {
    v7 = word_19918C[(int16_t)v5] * (uint8_t)byte_181734[(int16_t)v5];
    ++v5;
    v2 += v7;
  }
  while ( (int16_t)v5 < 9 );
  if ( 4 * v2 >= v6 )
  {
    for ( i = 0; i < 9 && !v1; ++i )
      v1 = word_19918C[i] - word_19919E[i] > 0;
    if ( v1 )
      ++word_199174;
    if ( word_199174 > 0 )
      sub_1247A0(0xC8u);
  }
  JUMPOUT(0x63FC5);
}
// 63F36: control flows out of bounds to 63FC5
// 63EF4: variable 'v3' is possibly undefined
// 199174: using guessed type int16_t word_199174;
// 199176: using guessed type int16_t word_199176;
// 199178: using guessed type int16_t word_199178;
// 19918C: using guessed type int16_t word_19918C[9];
// 19919E: using guessed type int16_t word_19919E[9];


//----- (00063F9C) --------------------------------------------------------
int16_t sub_63F9C()
{
  strcpy((char *)&word_18FF78, "defensive");
  return sub_63FF0(&word_199178, (int)word_19917A, (int)byte_181746, 0);
}
// 18FF78: using guessed type int16_t word_18FF78;
// 199178: using guessed type int16_t word_199178;
// 19917A: using guessed type int16_t word_19917A[4];


//----- (00063FCB) --------------------------------------------------------
void sub_63FCB()
{
  JUMPOUT(0x63FBC);
}
// 63FEE: control flows out of bounds to 63FBC


//----- (00063FF0) --------------------------------------------------------
int16_t __fastcall sub_63FF0(int16_t *a1, int a2, int a3, int a4)
{
  char v5; // cl
  int64_t v6; // rax
  int16_t v7; // si
  int16_t v8; // bx
  _BOOL1 v9; // al
  char *v10; // eax
  int16_t *v11; // edi
  int64_t v12; // rax
  char *v13; // edi
  int16_t *v14; // edi
  int64_t v15; // rax
  char *v16; // edi
  int64_t v17; // rax
  int16_t *v18; // edi
  char *v19; // edi
  int64_t v20; // rax
  _WORD *v21; // eax
  int v22; // esi
  int v23; // ebx
  int16_t *v25; // [esp-4h] [ebp-58h]
  int16_t *v26; // [esp-4h] [ebp-58h]
  int16_t *v27; // [esp-4h] [ebp-58h]
  char v31[20]; // [esp+Ch] [ebp-48h] BYREF
  char v32[20]; // [esp+20h] [ebp-34h] BYREF
  char v33[20]; // [esp+34h] [ebp-20h] BYREF
  int v34; // [esp+48h] [ebp-Ch]
  int v35; // [esp+4Ch] [ebp-8h]
  char v36; // [esp+50h] [ebp-4h]

  HIDWORD(v6) = dword_192FD8;
  v5 = 0;
  v34 = HIDWORD(v6) - 35000 - (int16_t)sub_63E4C();
  HIWORD(v6) = HIWORD(a1);
  LOWORD(v6) = (uint8_t)byte_181734[0];
  v36 = 0;
  if ( (uint8_t)byte_181734[0] > *a1 )
LABEL_2:
    v5 = 1;
  while ( !v5 )
  {
    v7 = -1;
    v8 = byte_199CB5 == 2;
    do
    {
      v9 = (v8 || (int16_t)sub_647D7() >= v34) && (v8 != 1 || (int16_t)sub_6481B() >= v34);
      if ( v9
        && byte_181734[v8]
        && (WORD2(v6) = (uint8_t)byte_181734[v8], v35 = HIDWORD(v6),
                                                          HIWORD(v6) = HIWORD(a1),
                                                          *a1 >= (int16_t)v35)
        && (HIDWORD(v6) = a2 + 2 * v8, *(uint8_t *)(a3 + v8) > (int16_t)*(_WORD *)HIDWORD(v6)) )
      {
        if ( !v36 )
        {
          v36 = 1;
          if ( a4 )
            v10 = aOffensive_0;
          else
            v10 = aDefensive_0;
          sprintf(&word_18FF78, "\n(%4d.%d) Building Antaran %s ships:", dword_192FD8 / 10, dword_192FD8 % 10, v10);
          if ( a4 )
          {
            v14 = &word_18FF78;
            v15 = sprintf(&word_18FF78, aCurrentOffShip);
            do
            {
              HIDWORD(v15) = ((uint64_t)sprintf(v31, "%2d ", word_19918C[SWORD2(v15)]) >> 32) + 1;
              v26 = v14;
              v16 = (char *)v14 - 1;
              do
                ++v16;
              while ( *v16 );
              strcpy(v16, v31);
              v14 = v26;
            }
            while ( SWORD2(v15) < 9 );
            v17 = sprintf(v26, aOffShipsDeploy);
            v18 = &word_18FF78;
            do
            {
              HIDWORD(v17) = ((uint64_t)sprintf(v32, "%2d ", word_19919E[SWORD2(v17)]) >> 32) + 1;
              v27 = v18;
              v19 = (char *)v18 - 1;
              do
                ++v19;
              while ( *v19 );
              strcpy(v19, v32);
              v18 = v27;
            }
            while ( SWORD2(v17) < 9 );
          }
          else
          {
            v11 = &word_18FF78;
            v12 = sprintf(&word_18FF78, aCurrentDefShip);
            do
            {
              HIDWORD(v12) = ((uint64_t)sprintf(v33, "%2d ", word_19917A[SWORD2(v12)]) >> 32) + 1;
              v25 = v11;
              v13 = (char *)v11 - 1;
              do
                ++v13;
              while ( *v13 );
              strcpy(v13, v33);
              v11 = v25;
            }
            while ( SWORD2(v12) < 9 );
          }
        }
        v20 = sprintf(
                &word_18FF78,
                "-------- building size %d, resources = %d, n_ships[%d] = %d",
                v8,
                *a1,
                v8,
                *(int16_t *)(a2 + 2 * v8));
        v7 = v8;
        v6 = sprintf(
               &word_18FF78,
               "-------- n_max_ships[%d] = %d, cost = %d",
               HIDWORD(v20),
               *(uint8_t *)(HIDWORD(v20) + a3),
               (uint8_t)byte_181734[HIDWORD(v20)]);
      }
      else
      {
        ++v8;
      }
      LOWORD(v6) = v7;
    }
    while ( v7 == -1 && v8 < 9 );
    HIDWORD(v6) = v7;
    if ( v7 == -1 )
      goto LABEL_2;
    v21 = (_WORD *)(a2 + 2 * v7);
    ++*v21;
    if ( v7 <= 2 && (uint8_t)byte_18173D[v7] == *v21 )
      byte_18173D[v7] = 0;
    *a1 -= (uint8_t)byte_181734[v7];
    v6 = sprintf(
           &word_18FF78,
           "-------- after build: resources = %3d, n_ships[%d] = %2d",
           *a1,
           v7,
           *(int16_t *)(a2 + 2 * v7));
    if ( v7 == 4 && !byte_19B89A && (uint8_t)byte_199CB0 > 2u )
    {
      byte_19B89A = 1;
      v22 = 0;
      do
      {
        v23 = (int16_t)v22;
        LODWORD(v6) = 90 * (uint8_t)byte_181734[(int16_t)v22] / 100;
        HIDWORD(v6) = 90 * (uint8_t)byte_181734[(int16_t)v22++] % 100;
        byte_181734[v23] = v6;
      }
      while ( (int16_t)v22 < 9 );
    }
  }
  return v6;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 18FF78: using guessed type int16_t word_18FF78;
// 192FD8: using guessed type int dword_192FD8;
// 19917A: using guessed type int16_t word_19917A[4];
// 19918C: using guessed type int16_t word_19918C[9];
// 19919E: using guessed type int16_t word_19919E[9];
// 199CB0: using guessed type char byte_199CB0;
// 199CB5: using guessed type char byte_199CB5;
// 19B89A: using guessed type char byte_19B89A;


