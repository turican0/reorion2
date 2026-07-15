#include "orion_common.h"

/* Adresni rozsah: 0xC5F5C - 0xD6125  (200 funkci) */

//----- (000C5F5C) --------------------------------------------------------
int __fastcall sub_C5F5C( int a1)
{
  int v2; // ebx
  int v3; // ecx
  int i; // edx

  v2 = -1;
  v3 = 0;
  for ( i = 0; (int16_t)i < word_199996; ++i )
  {
    if ( *(char *)(361 * (int16_t)i + dword_192B18) == a1 && sub_1247A0((int16_t)++v3) == 1 )
      v2 = i;
  }
  return v2;
}
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (000C5FB0) --------------------------------------------------------
int __fastcall sub_C5FB0( int a1)
{
  int i; // edx
  int v2; // ecx

  for ( i = 0; (int16_t)i < word_199996; ++i )
  {
    v2 = 361 * (int16_t)i;
    if ( *(_BYTE *)(v2 + dword_192B18 + 319) && *(char *)(v2 + dword_192B18) == a1 )
      return i;
  }
  return sub_C5F5C(a1);
}
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (000C5FF7) --------------------------------------------------------
int sub_C5FF7()
{
  int v0; // ebx
  int v1; // esi
  int i; // edx

  v0 = -1;
  v1 = 0;
  for ( i = 0; (int16_t)i < word_199998; ++i )
  {
    if ( !*(_BYTE *)(dword_197F98 + 3753 * (int16_t)i + 36) && sub_1247A0((int16_t)++v1) == 1 )
      v0 = i;
  }
  return v0;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000C603D) --------------------------------------------------------
char *__fastcall sub_C603D( int a1)
{
  if ( a1 < 0 )
    return a2_0;
  else
    return (char *)sub_CDF5C(12);
}


//----- (000C6052) --------------------------------------------------------
char __fastcall sub_C6052( int a1, int a2, int a3)
{
  int16_t i; // cx
  int v5; // eax
  int v6; // eax

  for ( i = 0; i < 67; ++i )
  {
    v5 = dword_1930DC + 59 * i;
    if ( *(char *)(v5 + 58) == a1 && *(_BYTE *)(v5 + 57) == 1 && !*(_BYTE *)(v5 + 55) )
    {
      if ( !*(_BYTE *)(v5 + 35) && a3 == *(_WORD *)(129 * *(int16_t *)(v5 + 53) + dword_197F9C + 101)
        || (v6 = dword_1930DC + 59 * i, *(_BYTE *)(v6 + 35) == 1) && a3 == *(_WORD *)(v6 + 53) )
      {
        if ( sub_9467D(a1, i, a2) )
          return 1;
      }
    }
  }
  return 0;
}
// 1930DC: using guessed type int dword_1930DC;
// 197F9C: using guessed type int dword_197F9C;


//----- (000C60E9) --------------------------------------------------------
char __fastcall sub_C60E9( int a1, int a2, int a3)
{
  int16_t i; // dx
  int v6; // eax

  for ( i = 0; i < 500; ++i )
  {
    v6 = dword_197F9C + 129 * i;
    if ( a3 == *(_WORD *)(v6 + 101)
      && !*(_BYTE *)(v6 + 100)
      && a1 == *(char *)(v6 + 99)
      && *(uint8_t *)(v6 + 16) >= a2 )
    {
      return 1;
    }
  }
  return 0;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (000C613B) --------------------------------------------------------
char __fastcall sub_C613B( int a1, int a2)
{
  int16_t v2; // ax
  int v3; // eax
  int v5; // ecx

  if ( !*(_BYTE *)(3753 * a1 + dword_197F98 + 2232) )
  {
    v2 = 563;
LABEL_3:
    v3 = sub_CDF5C(v2);
    sub_77423(v3);
    return 0;
  }
  v5 = 361 * a2;
  if ( !sub_C60E9(a1, 2, *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v5 + dword_192B18 + 2) + 2)) )
  {
    v2 = 588;
    goto LABEL_3;
  }
  if ( sub_C6052(
         *(char *)(v5 + dword_192B18),
         0,
         *(uint8_t *)(17 * *(int16_t *)(v5 + dword_192B18 + 2) + dword_1930D4 + 2))
    || sub_C6052(
         *(char *)(v5 + dword_192B18),
         0,
         *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v5 + dword_192B18 + 2) + 2)) )
  {
    v2 = 512;
    goto LABEL_3;
  }
  if ( *(_BYTE *)(dword_197F98 + 3753 * *(char *)(v5 + dword_192B18) + 2232) )
  {
    v2 = 513;
    goto LABEL_3;
  }
  return 1;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000C622A) --------------------------------------------------------
_BOOL1 __fastcall sub_C622A( int a1, int a2)
{
  int v2; // ecx
  bool v3; // eax
  _BOOL1 result; // al

  result = 0;
  if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 2232) )
  {
    v2 = 361 * a2;
    if ( sub_C60E9(a1, 2, *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v2 + dword_192B18 + 2) + 2)) )
    {
      v3 = !sub_C6052(
              *(char *)(v2 + dword_192B18),
              0,
              *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v2 + dword_192B18 + 2) + 2))
        && !sub_C6052(
              *(char *)(v2 + dword_192B18),
              0,
              *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v2 + dword_192B18 + 2) + 2));
      if ( v3 && !*(_BYTE *)(dword_197F98 + 3753 * *(char *)(361 * a2 + dword_192B18) + 2232) )
        return 1;
    }
  }
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;


//----- (000C6313) --------------------------------------------------------
int sub_C6313()
{
  int v0; // esi
  int v1; // kr04_4
  _DWORD *v2; // eax

  sub_124D41();
  v0 = (640 - *(int16_t *)sub_126B42((int)aMainpupsLbx, 83, dword_192ED4)) / 2;
  v1 = 480 - *((int16_t *)sub_126B42((int)aMainpupsLbx, 83, dword_192ED4) + 1);
  word_19994C = 1;
  byte_199F37 = 1;
  sub_84E9D();
  v2 = sub_126B42((int)aMainpupsLbx, 83, dword_192ED4);
  sub_12A478(v0 + 3, v1 / 2 + 1, (int)v2);
  return sub_131922(0, 255);
}
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 199F37: using guessed type char byte_199F37;


//----- (000C63BB) --------------------------------------------------------
void *sub_C63BB()
{
  char v0; // al

  sub_107AF(&dword_1A08F4);
  sub_119281();
  if ( byte_199BED || byte_199BEF )
  {
    word_18319F = (uint8_t)byte_199BEE;
    v0 = byte_199BF0;
    word_1831A1 = (uint8_t)byte_199BF0;
    if ( (uint8_t)byte_199BF0 < (uint8_t)byte_199BEE )
      v0 = byte_199BEE;
    byte_199BF0 = v0;
  }
  else
  {
    word_18319F = 0;
    word_1831A1 = 0;
  }
  sub_123E6C((int)&unk_17CF4A, 1);
  sub_C6313();
  sub_1191CA((int)sub_C6313, 1);
  sub_1112EC(dword_192ED4, 1);
  return sub_124DEC();
}
// 18319F: using guessed type int16_t word_18319F;
// 1831A1: using guessed type int16_t word_1831A1;
// 192ED4: using guessed type int dword_192ED4;
// 199BED: using guessed type char byte_199BED;
// 199BEE: using guessed type char byte_199BEE;
// 199BEF: using guessed type char byte_199BEF;
// 199BF0: using guessed type char byte_199BF0;
// 1A08F4: using guessed type _DWORD dword_1A08F4;


//----- (000C64AB) --------------------------------------------------------
uint8_t sub_C64AB()
{
  uint8_t result; // al

  sub_C63BB();
  sub_14DF7((int)aAmebafinLbx, 0, 0);
  sub_123E6C((int)&unk_17CF00, 1);
  sub_119281();
  sub_107BA(&dword_1A08F4);
  result = (uint8_t)sub_1113CC(dword_192ED4, 1);
  if ( word_18319F || word_1831A1 )
  {
    byte_199BEE = word_18319F;
    result = word_1831A1;
    byte_199BF0 = word_1831A1;
  }
  return result;
}
// 18319F: using guessed type int16_t word_18319F;
// 1831A1: using guessed type int16_t word_1831A1;
// 192ED4: using guessed type int dword_192ED4;
// 199BEE: using guessed type char byte_199BEE;
// 199BF0: using guessed type char byte_199BF0;
// 1A08F4: using guessed type _DWORD dword_1A08F4;


//----- (000C6513) --------------------------------------------------------
uint8_t sub_C6513()
{
  uint8_t result; // al

  sub_C63BB();
  sub_14DF7((int)aPlntdfinLbx, 0, 0);
  sub_123E6C((int)&unk_17CF00, 1);
  sub_119281();
  sub_107BA(&dword_1A08F4);
  result = (uint8_t)sub_1113CC(dword_192ED4, 1);
  if ( word_18319F || word_1831A1 )
  {
    byte_199BEE = word_18319F;
    result = word_1831A1;
    byte_199BF0 = word_1831A1;
  }
  return result;
}
// 18319F: using guessed type int16_t word_18319F;
// 1831A1: using guessed type int16_t word_1831A1;
// 192ED4: using guessed type int dword_192ED4;
// 199BEE: using guessed type char byte_199BEE;
// 199BF0: using guessed type char byte_199BF0;
// 1A08F4: using guessed type _DWORD dword_1A08F4;


//----- (000C657B) --------------------------------------------------------
uint8_t sub_C657B()
{
  uint8_t result; // al

  sub_C63BB();
  sub_14DF7((int)aDimtvfinLbx, 0, 0);
  sub_123E6C((int)&unk_17CF00, 1);
  sub_119281();
  sub_107BA(&dword_1A08F4);
  result = (uint8_t)sub_1113CC(dword_192ED4, 1);
  if ( word_18319F || word_1831A1 )
  {
    byte_199BEE = word_18319F;
    result = word_1831A1;
    byte_199BF0 = word_1831A1;
  }
  return result;
}
// 18319F: using guessed type int16_t word_18319F;
// 1831A1: using guessed type int16_t word_1831A1;
// 192ED4: using guessed type int dword_192ED4;
// 199BEE: using guessed type char byte_199BEE;
// 199BF0: using guessed type char byte_199BF0;
// 1A08F4: using guessed type _DWORD dword_1A08F4;


//----- (000C65E3) --------------------------------------------------------
uint8_t sub_C65E3()
{
  int v0; // eax
  uint8_t result; // al

  sub_C63BB();
  v0 = sub_CDF5C(174);
  sub_14DF7(v0, 0, 0);
  sub_123E6C((int)&unk_17CF00, 1);
  sub_119281();
  sub_107BA(&dword_1A08F4);
  result = (uint8_t)sub_1113CC(dword_192ED4, 1);
  if ( word_18319F || word_1831A1 )
  {
    byte_199BEE = word_18319F;
    result = word_1831A1;
    byte_199BF0 = word_1831A1;
  }
  return result;
}
// 18319F: using guessed type int16_t word_18319F;
// 1831A1: using guessed type int16_t word_1831A1;
// 192ED4: using guessed type int dword_192ED4;
// 199BEE: using guessed type char byte_199BEE;
// 199BF0: using guessed type char byte_199BF0;
// 1A08F4: using guessed type _DWORD dword_1A08F4;


//----- (000C6650) --------------------------------------------------------
uint8_t sub_C6650()
{
  int v0; // eax
  uint8_t result; // al

  sub_C63BB();
  v0 = sub_CDF5C(404);
  sub_14DF7(v0, 0, 0);
  sub_123E6C((int)&unk_17CF00, 1);
  sub_119281();
  sub_107BA(&dword_1A08F4);
  result = (uint8_t)sub_1113CC(dword_192ED4, 1);
  if ( word_18319F || word_1831A1 )
  {
    byte_199BEE = word_18319F;
    result = word_1831A1;
    byte_199BF0 = word_1831A1;
  }
  return result;
}
// 18319F: using guessed type int16_t word_18319F;
// 1831A1: using guessed type int16_t word_1831A1;
// 192ED4: using guessed type int dword_192ED4;
// 199BEE: using guessed type char byte_199BEE;
// 199BF0: using guessed type char byte_199BF0;
// 1A08F4: using guessed type _DWORD dword_1A08F4;


//----- (000C66BD) --------------------------------------------------------
int16_t sub_C66BD()
{
  int v0; // eax
  int v1; // eax

  sub_123E6C((int)&unk_17CF4A, 1);
  v0 = sub_CDF5C(556);
  sub_14DF7(v0, 0, 1);
  sub_123E6C((int)&unk_17CF4A, 1);
  v1 = sub_CDF5C(310);
  sub_14DF7(v1, 0, 1);
  return sub_123E6C((int)&unk_17CF00, 1);
}


//----- (000C671B) --------------------------------------------------------
void sub_C671B()
{
  sub_123E6C((int)&unk_17CF4A, 1);
  JUMPOUT(0xC66FF);
}
// C673B: control flows out of bounds to C66FF


//----- (000C673D) --------------------------------------------------------
void sub_C673D()
{
  sub_123E6C((int)&unk_17CF4A, 1);
  JUMPOUT(0xC66DA);
}
// C675D: control flows out of bounds to C66DA


//----- (000C6762) --------------------------------------------------------
void sub_C6762()
{
  sub_123E6C((int)&unk_17CF4A, 1);
  JUMPOUT(0xC66FD);
}
// C677D: control flows out of bounds to C66FD


//----- (000C6782) --------------------------------------------------------
int16_t sub_C6782()
{
  int16_t v0; // di
  int16_t i; // cx
  int16_t v2; // ax
  int v3; // ebx
  int16_t v4; // dx
  int v5; // eax
  int16_t result; // ax

  v0 = sub_113F8C();
  for ( i = 0; ; ++i )
  {
    result = (uint8_t)byte_1831A4;
    if ( i >= (uint8_t)byte_1831A4 )
      break;
    if ( v0 == word_1A0908[5 * i] )
    {
      v5 = *(int *)((char *)&dword_1A090A + 10 * i);
      if ( *(int16_t *)(v5 + 6) <= 0 )
        continue;
      sub_12B753(v5, 1);
      v4 = word_1A0906[5 * i];
      v3 = *(int *)((char *)&dword_1A090A + 10 * i);
      v2 = word_1A0904[5 * i];
    }
    else
    {
      sub_12B726(*(int *)((char *)&dword_1A090A + 10 * i));
      v2 = word_1A0904[5 * i];
      v3 = *(int *)((char *)&dword_1A090A + 10 * i);
      v4 = word_1A0906[5 * i];
    }
    sub_12A478(v2, v4, v3);
  }
  return result;
}
// 1831A4: using guessed type char byte_1831A4;
// 1A0904: using guessed type int16_t word_1A0904[];
// 1A0906: using guessed type int16_t word_1A0906[];
// 1A0908: using guessed type int16_t word_1A0908[];
// 1A090A: using guessed type int dword_1A090A;


//----- (000C683E) --------------------------------------------------------
int sub_C683E()
{
  int result; // eax

  result = memset(&word_1A0904, 0, 250);
  byte_1831A4 = 0;
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1831A4: using guessed type char byte_1831A4;
// 1A0904: using guessed type int16_t word_1A0904;


//----- (000C685B) --------------------------------------------------------
unsigned int __fastcall sub_C685B( int a1, int a2, int a3, _WORD *a4, _BYTE *a5, int a6)
{
  unsigned int v7; // edx
  int v8; // eax

  v7 = sub_11438B(a1, a2, a1 + *a4, a4[1] + a2, a5, a6);
  v8 = 5 * (uint8_t)byte_1831A4;
  word_1A0904[v8] = a1;
  word_1A0906[v8] = a2;
  *(int *)((char *)&dword_1A090A + v8 * 2) = (int)a4;
  ++byte_1831A4;
  word_1A0908[v8] = v7;
  return v7;
}
// C685B: could not find valid save-restore pair for ebx
// 1831A4: using guessed type char byte_1831A4;
// 1A0904: using guessed type int16_t word_1A0904[];
// 1A0906: using guessed type int16_t word_1A0906[];
// 1A0908: using guessed type int16_t word_1A0908[];
// 1A090A: using guessed type int dword_1A090A;


//----- (000C68C4) --------------------------------------------------------
void sub_C68C4()
{
  int16_t i; // di
  int v1; // edx
  int16_t *v2; // eax
  int v3; // [esp-18h] [ebp-1Ch]
  int v4; // [esp-18h] [ebp-1Ch]

  for ( i = 0; ; ++i )
  {
    if ( i >= (uint8_t)byte_1831A5 )
      JUMPOUT(0xC6808);
    if ( byte_1A0A14[23 * i] )
      sub_1297C3(
        *(int16_t *)((char *)&word_1A09FE + 23 * i),
        *(int16_t *)((char *)&word_1A0A00 + 23 * i),
        *(int16_t *)((char *)&word_1A0A02 + 23 * i) - *(int16_t *)((char *)&word_1A09FE + 23 * i),
        *(int16_t *)((char *)&word_1A0A04 + 23 * i) - *(int16_t *)((char *)&word_1A0A00 + 23 * i),
        1,
        (uint8_t)byte_1A0A14[23 * i]);
    sub_128AB6(
      *(int16_t *)((char *)&word_1A09FE + 23 * i),
      *(int16_t *)((char *)&word_1A0A00 + 23 * i),
      *(int16_t *)((char *)&word_1A0A02 + 23 * i),
      *(int16_t *)((char *)&word_1A0A04 + 23 * i));
    sub_12B634();
    v1 = *(int *)((char *)&dword_1A0A0A + 23 * i);
    v3 = *(int *)((char *)&dword_1A0A10 + 23 * i);
    if ( (v3 & 0xFFF) == 0x360 )
    {
      v2 = *(int16_t **)((char *)&dword_1A0A10 + 23 * i);
      if ( *(_BYTE *)(v3 - 167554) != 1 )
        goto LABEL_11;
      v4 = v3 - 167500;
    }
    else
    {
      if ( (v3 & 0xFFF) != 0x35E )
      {
        v2 = *(int16_t **)((char *)&dword_1A0A10 + 23 * i);
LABEL_11:
        v4 = *(_DWORD *)(v1 + 4 * *v2);
        goto LABEL_5;
      }
      v2 = *(int16_t **)((char *)&dword_1A0A10 + 23 * i);
      if ( *(_BYTE *)(v3 - 29765) != 10 )
        *(_BYTE *)(v3 - 167551) = 0;
      if ( *(_BYTE *)(v3 - 167551) != 1 )
        goto LABEL_11;
      v4 = v3 - 167550;
    }
LABEL_5:
    sub_1031C6(v4, 2);
    sub_12B65C();
  }
}
// C69B1: control flows out of bounds to C6808
// 1831A5: using guessed type char byte_1831A5;
// 1A09FE: using guessed type int16_t word_1A09FE;
// 1A0A00: using guessed type int16_t word_1A0A00;
// 1A0A02: using guessed type int16_t word_1A0A02;
// 1A0A04: using guessed type int16_t word_1A0A04;
// 1A0A0A: using guessed type int dword_1A0A0A;
// 1A0A10: using guessed type int dword_1A0A10;


//----- (000C69B6) --------------------------------------------------------
int __fastcall sub_C69B6( int a1, int a2, int a3, int a4, int a5,
        int a6, int a7,
        int a8, int a9, int a10)
{
  int result; // eax

  result = 23 * (uint8_t)byte_1831A5;
  *(int16_t *)((char *)&word_1A09FE + result) = a1;
  *(int16_t *)((char *)&word_1A0A00 + result) = a2;
  *(int16_t *)((char *)&word_1A0A02 + result) = a3;
  *(int16_t *)((char *)&word_1A0A04 + result) = a4;
  *(int16_t *)((char *)&word_1A0A06 + result) = a5;
  *(int *)((char *)&dword_1A0A0A + result) = a6;
  *(int16_t *)((char *)&word_1A0A0E + result) = a7;
  *(int *)((char *)&dword_1A0A10 + result) = a8;
  byte_1A0A14[result] = a9;
  ++byte_1831A5;
  *(int16_t *)((char *)&word_1A0A08 + result) = a10;
  return result;
}
// 1831A5: using guessed type char byte_1831A5;
// 1A09FE: using guessed type int16_t word_1A09FE;
// 1A0A00: using guessed type int16_t word_1A0A00;
// 1A0A02: using guessed type int16_t word_1A0A02;
// 1A0A04: using guessed type int16_t word_1A0A04;
// 1A0A06: using guessed type int16_t word_1A0A06;
// 1A0A08: using guessed type int16_t word_1A0A08;
// 1A0A0A: using guessed type int dword_1A0A0A;
// 1A0A0E: using guessed type int16_t word_1A0A0E;
// 1A0A10: using guessed type int dword_1A0A10;


//----- (000C6A26) --------------------------------------------------------
int sub_C6A26()
{
  int result; // eax

  result = memset(&word_1A09FE, 0, 575);
  byte_1831A5 = 0;
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1831A5: using guessed type char byte_1831A5;
// 1A09FE: using guessed type int16_t word_1A09FE;


//----- (000C6A43) --------------------------------------------------------
unsigned int __fastcall sub_C6A43( int a1, int a2, int a3, int a4,
        int a5, int a6,
        int a7, int a8,
        _BYTE *a9, int a10, int a11)
{
  unsigned int v13; // [esp+8h] [ebp-4h]

  v13 = sub_11438B(a1, a2, a3, a4, a9, a10);
  sub_C69B6(a1, a2, a3, a4, v13, a5, a6, a7, a8, a11);
  return v13;
}


//----- (000C6AA4) --------------------------------------------------------
void __fastcall sub_C6AA4( int a1)
{
  int16_t i; // cx
  int v3; // eax
  int16_t *v4; // ebx
  int v5; // edx
  int v6; // edi
  int16_t v7; // bx
  _WORD *v8; // ebx
  _BOOL1 v9; // zf
  int v10; // [esp-14h] [ebp-18h]

  for ( i = 0; i < (uint8_t)byte_1831A5; ++i )
  {
    if ( a1 == *(int16_t *)((char *)&word_1A0A06 + 23 * i) || a1 == *(int16_t *)((char *)&word_1A0A08 + 23 * i) )
    {
      v3 = 23 * i;
      v4 = *(int16_t **)((char *)&dword_1A0A10 + v3);
      v5 = *v4;
      v6 = *(int16_t *)((char *)&word_1A0A0E + v3);
      v10 = *(int *)((char *)&dword_1A0A10 + 23 * i);
      v7 = (uint16_t)v4 & 0xFFF;
      if ( v7 == 864 )
      {
        v8 = *(_WORD **)((char *)&dword_1A0A10 + 23 * i);
        if ( (_BYTE)v5 == 1 )
        {
          v9 = *(_BYTE *)(v10 - 167554) == 1;
          *(_BYTE *)(v10 - 167554) ^= 1u;
          if ( !v9 )
            --v5;
        }
      }
      else if ( v7 == 862 )
      {
        v8 = *(_WORD **)((char *)&dword_1A0A10 + 23 * i);
        if ( *(_BYTE *)(v10 - 29765) == 10 && (_BYTE)v5 == 2 )
        {
          v9 = *(_BYTE *)(v10 - 167551) == 1;
          *(_BYTE *)(v10 - 167551) ^= 1u;
          if ( !v9 )
            --v5;
        }
      }
      else
      {
        v8 = *(_WORD **)((char *)&dword_1A0A10 + 23 * i);
      }
      *v8 = (v5 + 1) % v6;
    }
  }
  JUMPOUT(0xC6808);
}
// C6AF4: control flows out of bounds to C6808
// 1831A5: using guessed type char byte_1831A5;
// 1A0A06: using guessed type int16_t word_1A0A06;
// 1A0A08: using guessed type int16_t word_1A0A08;
// 1A0A0E: using guessed type int16_t word_1A0A0E;
// 1A0A10: using guessed type int dword_1A0A10;


//----- (000C6AF9) --------------------------------------------------------
_DWORD *sub_C6AF9()
{
  int16_t v0; // si
  int v1; // edi
  _DWORD *result; // eax

  v0 = 0;
  dword_1A0C60 = (int)sub_110D3C(dword_192ED4, 7056);
  do
  {
    if ( v0 )
    {
      v1 = v0;
      result = sub_126C37((int)aFireptsLbx, 0, dword_1A0C60, v0, 1u, 784);
    }
    else
    {
      v1 = 0;
      result = sub_126BDD((int)aFireptsLbx, 0, dword_1A0C60, 0, 1u, 784);
    }
    dword_1A0C40[v1] = (int)result;
    ++v0;
  }
  while ( v0 < 8 );
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 1A0C40: using guessed type int dword_1A0C40[];
// 1A0C60: using guessed type int dword_1A0C60;


//----- (000C6B6B) --------------------------------------------------------
int __fastcall sub_C6B6B( int a1, int a2, int a3)
{
  if ( a2 <= 10 || byte_18248D )
  {
    a3 = 1;
  }
  else if ( a2 >= 30 )
  {
    if ( a2 >= 60 )
    {
      if ( a2 > 98 )
      {
        if ( a2 == 99 )
          a3 = 5;
      }
      else
      {
        a3 = 4;
      }
    }
    else
    {
      a3 = 3;
    }
  }
  else
  {
    a3 = 2;
  }
  if ( a1 == 27 )
  {
    if ( (int16_t)a3 < 2 )
      return 2;
    return (int16_t)a3;
  }
  return a3;
}
// 18248D: using guessed type char byte_18248D;


//----- (000C6BD0) --------------------------------------------------------
int __fastcall sub_C6BD0(
        _WORD *a1,
        _WORD *a2,
        int a3, int a4, int a5,
        int a6, int a7, unsigned int a8, unsigned int a9, int a10)
{
  int v11; // ebx
  int result; // eax
  int16_t v13; // ax
  int v14; // ebx
  int v15; // eax
  int16_t v16; // cx
  int v17; // [esp+0h] [ebp-8h] BYREF
  int v18; // [esp+4h] [ebp-4h] BYREF

  v11 = (int16_t)sub_C6B6B(a3, a4, a3);
  if ( v11 % 2 == 1 && (result = a10, a10 == v11 - 1) )
  {
    *a1 = 0;
    *a2 = 0;
  }
  else
  {
    if ( a5 < 8 )
      v13 = *(uint8_t *)(dword_197F98 + 3753 * a5 + 38);
    else
      v13 = 0;
    v14 = dword_1A0C40[v13] + 16 * a7;
    v15 = (a9 + a10) % 4;
    v16 = *(_WORD *)(v14 + 4 * v15);
    LOWORD(v14) = *(_WORD *)(v14 + 4 * v15 + 2);
    v18 = v16 - 26;
    v17 = (int16_t)v14 - 24;
    sub_1387B2(-(int16_t)((360 * a8 - (__CFSHL__((360 * a8) >> 31, 4) + 16 * ((360 * a8) >> 31))) >> 4), &v18, &v17);
    *a1 = v18;
    result = v17;
    *a2 = v17;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 1A0C40: using guessed type int dword_1A0C40[];


//----- (000C6CA4) --------------------------------------------------------
void sub_C6CA4()
{
  word_1831A8 = 0;
}
// 1831A8: using guessed type int16_t word_1831A8;


//----- (000C6CAE) --------------------------------------------------------
unsigned int __fastcall sub_C6CAE(unsigned int result, int a2, int a3, int a4, int a5)
{
  int16_t v5; // si

  v5 = result;
  if ( word_1831A8 < 100 )
  {
    result = 12 * word_1831A8;
    word_1A0C64[result / 2] = v5;
    word_1A0C66[result / 2] = a2;
    dword_1A0C6A[result / 4] = a3;
    byte_1A0C6E[result] = a4;
    ++word_1831A8;
    byte_1A0C6F[result] = a5;
  }
  return result;
}
// 1831A8: using guessed type int16_t word_1831A8;
// 1A0C64: using guessed type int16_t word_1A0C64[];
// 1A0C66: using guessed type int16_t word_1A0C66[];
// 1A0C6A: using guessed type int dword_1A0C6A[];


//----- (000C6CF7) --------------------------------------------------------
int16_t sub_C6CF7()
{
  int16_t i; // dx
  int16_t result; // ax

  for ( i = 0; i < word_1831A8; ++i )
    result = sub_C6D10(i);
  return result;
}
// 1831A8: using guessed type int16_t word_1831A8;


//----- (000C6D10) --------------------------------------------------------
int16_t __fastcall sub_C6D10( int a1)
{
  unsigned int v2; // esi
  int v3; // eax
  char v4; // dl

  v2 = 12 * a1;
  sub_12B753(dword_1A0C6A[v2 / 4], word_1A0C68[v2 / 2]);
  if ( byte_1A0C6F[v2] )
  {
    sub_128AB6(0, 0, 639, 479);
    sub_12B634();
    sub_12A478(word_1A0C64[v2 / 2], word_1A0C66[v2 / 2], dword_1A0C6A[v2 / 4]);
    sub_12B65C();
  }
  else
  {
    sub_12A478(word_1A0C64[v2 / 2], word_1A0C66[v2 / 2], dword_1A0C6A[v2 / 4]);
  }
  v3 = 12 * a1;
  v4 = byte_1A0C6E[v3];
  ++*(int16_t *)((char *)word_1A0C68 + v3);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      LOWORD(v3) = word_1A0C68[6 * a1];
      if ( (int16_t)v3 >= *(int16_t *)(dword_1A0C6A[3 * a1] + 6) )
      {
        LOWORD(v3) = (uint16_t)sub_1331D2(a1, (int)word_1A0C64, 12, 100);
        --word_1831A8;
      }
    }
  }
  else if ( word_1A0C68[6 * a1] >= *(int16_t *)(dword_1A0C6A[3 * a1] + 6) )
  {
    word_1A0C68[6 * a1] = 0;
  }
  return v3;
}
// 1831A8: using guessed type int16_t word_1831A8;
// 1A0C64: using guessed type int16_t word_1A0C64[];
// 1A0C66: using guessed type int16_t word_1A0C66[];
// 1A0C68: using guessed type int16_t word_1A0C68[];
// 1A0C6A: using guessed type int dword_1A0C6A[];


//----- (000C6DFB) --------------------------------------------------------
_BYTE *__fastcall sub_C6DFB( int a1)
{
  _BYTE *result; // eax

  result = sub_1331D2(a1, (int)word_1A0C64, 12, 100);
  --word_1831A8;
  return result;
}
// 1831A8: using guessed type int16_t word_1831A8;
// 1A0C64: using guessed type int16_t word_1A0C64[];


//----- (000C6E7E) --------------------------------------------------------
int16_t sub_C6E7E()
{
  int16_t result; // ax

  result = sub_10FE41((int)&unk_1A11F8 + 18 * word_1831C2);
  ++word_1831C2;
  return result;
}
// 1831C2: using guessed type int16_t word_1831C2;


//----- (000C6EBF) --------------------------------------------------------
char __fastcall sub_C6EBF( int a1, int a2)
{
  int16_t i; // ax
  int v5; // edx
  int v6; // edx

  for ( i = 0; i < 5; ++i )
  {
    v5 = *(int16_t *)(dword_19306C + 113 * a2 + 2 * i + 74);
    if ( v5 != -1 )
    {
      v6 = *(int16_t *)(17 * v5 + dword_1930D4);
      if ( v6 != -1 && *(char *)(dword_192B18 + 361 * v6) == a1 )
        return 1;
    }
  }
  return 0;
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (000C6F26) --------------------------------------------------------
void sub_C6F26()
{
  dword_1A1130 = 0;
  dword_1A1114 = 0;
  dword_1831B2 = 0;
}
// 1831B2: using guessed type int dword_1831B2;
// 1A1114: using guessed type int dword_1A1114;
// 1A1130: using guessed type int dword_1A1130;


//----- (000C6F51) --------------------------------------------------------
int __fastcall sub_C6F51( int a1, int a2)
{
  int16_t v2; // ax

  if ( !dword_1A1130 )
  {
    if ( a2 == 9 )
      v2 = sub_FEB40(a1) + 15;
    else
      v2 = a2 + 4;
    dword_1A1130 = (int)sub_126B42((int)aMainpupsLbx, v2, dword_192ED4);
  }
  if ( !dword_1A1114 )
    dword_1A1114 = (int)sub_126B42((int)aMainpupsLbx, 0, dword_192ED4);
  return dword_1A1130;
}
// 192ED4: using guessed type int dword_192ED4;
// 1A1114: using guessed type int dword_1A1114;
// 1A1130: using guessed type int dword_1A1130;


//----- (000C6FB8) --------------------------------------------------------
int __fastcall sub_C6FB8( int a1)
{
  int v1; // ebx
  int v2; // edx
  int v3; // eax

  if ( !dword_1831B2 )
  {
    v1 = dword_192ED4;
    v2 = a1;
    v3 = sub_CDF5C(368);
    dword_1831B2 = (int)sub_126C37(v3, v2, v1, 0, 1u, 600);
  }
  return dword_1831B2;
}
// 1831B2: using guessed type int dword_1831B2;
// 192ED4: using guessed type int dword_192ED4;


//----- (000C6FF3) --------------------------------------------------------
int __fastcall sub_C6FF3( int a1, int a2, int a3, int a4)
{
  int v6; // ecx
  int v7; // ebx
  int v9; // [esp-4h] [ebp-8h]

  v9 = sub_C6FB8(a3);
  v6 = dword_18F9B8[a3];
  v7 = sub_C6F51(a4, a3);
  return sub_C7318(a1, a2, v7, v6, v9);
}
// 18F9B8: using guessed type int dword_18F9B8[];


//----- (000C702E) --------------------------------------------------------
void __fastcall sub_C702E( int a1, int16_t *a2)
{
  int v3; // eax
  int v4; // ebx
  bool v5; // eax
  int16_t v6; // [esp+0h] [ebp-8h] BYREF
  int16_t v7; // [esp+4h] [ebp-4h] BYREF

  if ( word_199A08 )
    byte_1831C4 = 0;
  word_1A123E = sub_124C3B();
  sub_124C08();
  v3 = a2[1];
  word_1A123A = 320 - *a2 / 2;
  word_1A123C = 240 - v3 / 2;
  if ( a1 == -1 )
  {
    v4 = dword_197F98 + 3753 * word_19999C;
    if ( *(int16_t *)(v4 + 41) <= 0 )
      a1 = 0;
    else
      a1 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v4 + 41) + 2);
  }
  word_1831AC = a1;
  dword_19F82C = a1;
  sub_119441();
  sub_117174(3);
  sub_123E6C((int)&unk_17CF00, 1);
  sub_128BE7();
  sub_12B65C();
  sub_124DEC();
  sub_124D41();
  if ( byte_1831C4 && sub_8A188(a1) )
    sub_8238B(*(_WORD *)(dword_19306C + 113 * a1 + 15), *(_WORD *)(dword_19306C + 113 * a1 + 17));
  if ( !word_1831C0 )
  {
    sub_107AF(&dword_1A11C0);
    sub_107C2((int (**)(void))&dword_1A11C0);
    v5 = !byte_1831C4 || !sub_8A188(a1);
    if ( v5 && !byte_1831B6 )
    {
      sub_1077D(v5);
      byte_182ACA = 1;
      sub_107C2((int (**)(void))&dword_1A11C0);
    }
    goto LABEL_20;
  }
  if ( word_1831C0 == 1 )
  {
    sub_107AF(&dword_1A11BC);
    byte_182ACA = 1;
    sub_107C2((int (**)(void))&dword_1A11C0);
    byte_182ACA = 1;
    sub_107C2(&dword_1A11BC);
LABEL_20:
    ++word_1831C0;
  }
  if ( byte_1831C4 )
  {
    sub_85B93(a1, &v7, &v6);
    sub_11E718();
    if ( byte_199BE0 )
    {
      if ( word_1831C2 < 1 )
      {
        if ( word_199992 != word_1999A0 && !sub_8A188(a1) )
        {
          sub_8238B(*(_WORD *)(dword_19306C + 113 * a1 + 15), *(_WORD *)(dword_19306C + 113 * a1 + 17));
          sub_85B93(a1, &v7, &v6);
        }
        sub_83EFD(v7, v6, word_1A123A, word_1A123C, *a2, a2[1], -1);
      }
    }
  }
  if ( byte_1831B6 )
    byte_1831B6 = 0;
  byte_182ACA = 1;
}
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 182ACA: using guessed type char byte_182ACA;
// 1831AC: using guessed type int16_t word_1831AC;
// 1831B6: using guessed type char byte_1831B6;
// 1831C0: using guessed type int16_t word_1831C0;
// 1831C2: using guessed type int16_t word_1831C2;
// 1831C4: using guessed type char byte_1831C4;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199992: using guessed type int16_t word_199992;
// 19999C: using guessed type int16_t word_19999C;
// 1999A0: using guessed type int16_t word_1999A0;
// 199A08: using guessed type int16_t word_199A08;
// 199BE0: using guessed type char byte_199BE0;
// 19F82C: using guessed type int dword_19F82C;
// 1A11BC: using guessed type int (*dword_1A11BC)(void);
// 1A11C0: using guessed type int dword_1A11C0;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;
// 1A123E: using guessed type int16_t word_1A123E;


//----- (000C7283) --------------------------------------------------------
void __fastcall sub_C7283(int a1, int a2)
{
  int *v2; // eax

  if ( word_1831C2 > 0 )
    sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
  sub_119281();
  if ( word_1831C0 == 1 )
  {
    v2 = &dword_1A11C0;
LABEL_7:
    sub_107BA(v2);
    --word_1831C0;
    goto LABEL_8;
  }
  if ( word_1831C0 == 2 )
  {
    v2 = (int *)&dword_1A11BC;
    goto LABEL_7;
  }
LABEL_8:
  sub_124E36();
  word_19994C = 1;
  sub_1113CC(dword_192ED4, a2);
  sub_C5B64(word_1A123E);
  byte_199F21 = 0;
  byte_1831C4 = 1;
  sub_1196F7();
  byte_199F35 = 1;
}
// 1831C0: using guessed type int16_t word_1831C0;
// 1831C2: using guessed type int16_t word_1831C2;
// 1831C4: using guessed type char byte_1831C4;
// 192ED4: using guessed type int dword_192ED4;
// 19994C: using guessed type int16_t word_19994C;
// 199F21: using guessed type char byte_199F21;
// 199F35: using guessed type char byte_199F35;
// 1A11BC: using guessed type int (*dword_1A11BC)(void);
// 1A11C0: using guessed type int dword_1A11C0;
// 1A123E: using guessed type int16_t word_1A123E;


//----- (000C7318) --------------------------------------------------------
int __fastcall sub_C7318( int a1, int a2, int a3, int a4, int a5)
{
  _DWORD v7[2]; // [esp+10h] [ebp-8h] BYREF

  v7[0] = 7565678;
  v7[1] = 0;
  sub_128C32(
    (int16_t)(a1 + 3),
    (int16_t)(a2 + 3),
    (int16_t)(*(_WORD *)dword_1A1114 + a1 - 3),
    (int16_t)(*(_WORD *)(dword_1A1114 + 2) + a2 - 3),
    0);
  sub_12A478(a1, a2, dword_1A1114);
  sub_12A478(a1 + 4, a2 + 4, a3);
  sub_120BB5(1, (int)v7);
  sub_1210FD(a1 + 222, a2 + 10, a4);
  return sub_103915(2);
}
// 103915: using guessed type _DWORD __stdcall sub_103915(int16_t);
// 1A1114: using guessed type int dword_1A1114;


//----- (000C754A) --------------------------------------------------------
char sub_C754A()
{
  _WORD *v0; // ecx
  int v1; // eax
  _WORD *v2; // ecx
  int v3; // eax
  _WORD *v4; // ecx
  int v5; // eax
  uint16_t v6; // ax
  _BYTE *v7; // eax
  _WORD *v9; // ecx
  int v10; // eax
  _WORD *v11; // ecx
  int v12; // eax
  uint16_t v13; // ax
  _BYTE *v14; // [esp-14h] [ebp-18h]
  _BYTE *v15; // [esp-14h] [ebp-18h]
  _BYTE *v16; // [esp-14h] [ebp-18h]
  _BYTE *v17; // [esp-14h] [ebp-18h]
  _BYTE *v18; // [esp-14h] [ebp-18h]

  sub_119441();
  sub_117174(3);
  if ( word_1A1238 )
  {
    if ( word_1A1238 == 3 )
    {
      v14 = (_BYTE *)sub_CDF5C(384);
      v0 = (_WORD *)dword_1A1144;
      v1 = sub_CDF5C(12);
      word_1A11D4 = (uint16_t)sub_1151B0(word_1A123A + 44, word_1A123C + 226, v1, v0, v14, 40);
      v15 = (_BYTE *)sub_CDF5C(561);
      v2 = (_WORD *)dword_1A1148;
      v3 = sub_CDF5C(12);
      word_1A11D2 = (uint16_t)sub_1151B0(word_1A123A + 175, word_1A123C + 226, v3, v2, v15, 40);
    }
    else
    {
      v16 = (_BYTE *)sub_CDF5C(384);
      v4 = (_WORD *)dword_1A1144;
      v5 = sub_CDF5C(12);
      v6 = (uint16_t)sub_1151B0(word_1A123A + 44, word_1A123C + 226, v5, v4, v16, 40);
      word_1A11D2 = -1000;
      word_1A11D4 = v6;
    }
    v7 = (_BYTE *)sub_CDF5C(12);
    word_1A11C4 = sub_11438B(0, 0, 639, 479, v7, 0);
  }
  else
  {
    v17 = (_BYTE *)sub_CDF5C(436);
    v9 = (_WORD *)dword_1A1144;
    v10 = sub_CDF5C(12);
    word_1A11D4 = (uint16_t)sub_1151B0(word_1A123A + 44, word_1A123C + 226, v10, v9, v17, 40);
    v18 = (_BYTE *)sub_CDF5C(316);
    v11 = (_WORD *)dword_1A1148;
    v12 = sub_CDF5C(12);
    v13 = (uint16_t)sub_1151B0(word_1A123A + 175, word_1A123C + 226, v12, v11, v18, 40);
    word_1A11C4 = -1000;
    word_1A11D2 = v13;
  }
  return sub_97529(word_1A123A, word_1A123C + 53, word_1831C6);
}
// 1831C6: using guessed type int16_t word_1831C6;
// 1A1144: using guessed type int dword_1A1144;
// 1A1148: using guessed type int dword_1A1148;
// 1A11C4: using guessed type int16_t word_1A11C4;
// 1A11D2: using guessed type int16_t word_1A11D2;
// 1A11D4: using guessed type int16_t word_1A11D4;
// 1A1238: using guessed type int16_t word_1A1238;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C760E) --------------------------------------------------------
int16_t __fastcall sub_C760E(int64_t a1, int a2)
{
  int v2; // esi
  int16_t i; // cx
  int v4; // eax
  int v5; // ebx
  char *v6; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // eax
  char *v11; // [esp-4h] [ebp-10h]
  int v12; // [esp-4h] [ebp-10h]
  int v13; // [esp-4h] [ebp-10h]
  int16_t v14; // [esp+0h] [ebp-Ch]
  int16_t v15; // [esp+8h] [ebp-4h]

  v2 = a2;
  for ( i = 0; i < 3; ++i )
  {
    LOWORD(a1) = *(uint8_t *)(dword_1930DC + 59 * SWORD2(a1) + i + 46);
    v15 = a1;
    if ( *(_BYTE *)(dword_1930DC + 59 * SWORD2(a1) + i + 46) )
    {
      if ( i )
      {
        v4 = sprintf(a2, asc_179E1C);
      }
      else
      {
        v11 = (char *)sub_CDF5C(208);
        v4 = sprintf(a2, v11);
      }
      v5 = v4 + a2;
      v12 = *(int *)((char *)&off_17E079 + 13 * v15);
      v6 = (char *)sub_CDF5C(7);
      a1 = sprintf(v5, v6, v12);
      a2 = a1 + v5;
    }
  }
  if ( WORD2(a1) == 47 )
  {
    v7 = 3753 * v14 + dword_197F98;
    LOWORD(a1) = *(char *)(v7 + 2207) / 2;
    if ( !(*(char *)(v7 + 2207) % 2) )
    {
      v13 = dword_192228[(int16_t)(*(char *)(v7 + 2207) + 1)];
      v8 = (char *)sub_CDF5C(207);
      LODWORD(a1) = sprintf(a2, v8, v13);
      a2 += a1;
    }
  }
  if ( a2 == v2 )
  {
    v9 = (char *)sub_CDF5C(12);
    LOWORD(a1) = sprintf(v2, v9);
  }
  return a1;
}
// C7691: variable 'v14' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 192228: using guessed type int dword_192228[];
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;


//----- (000C76FA) --------------------------------------------------------
void sub_C76FA()
{
  char *v0; // eax
  int16_t v1; // ax
  char *v2; // eax
  int16_t *v3; // eax
  int16_t *v4; // [esp-10h] [ebp-186h]
  int v5; // [esp-Ch] [ebp-182h]
  int v6; // [esp-8h] [ebp-17Eh]
  int16_t *v7; // [esp-8h] [ebp-17Eh]
  int v8; // [esp-4h] [ebp-17Ah]
  int64_t v9; // [esp+0h] [ebp-176h] BYREF
  int v10; // [esp+8h] [ebp-16Eh]
  _BYTE v11[500]; // [esp+1F4h] [ebp+7Eh] BYREF

  if ( byte_182ACA || word_19994C )
  {
    byte_199F28 = 1;
    sub_C7F84();
    sub_12A478(word_1A123A, word_1A123C, dword_1A113C);
    sub_972EE(word_1A123A, word_1A123C + 53, word_1831C6);
    sub_12A478(word_1A123A + 13, word_1A123C + 55, dword_1A1140);
    if ( byte_1831C5 )
    {
      sub_C5F14(word_1A123A + 14, word_1A123C + 149, 281, 62, dword_1A11B8);
LABEL_15:
      v3 = sub_97588(word_1831C6, 1);
      sub_C5F14(word_1A123A + 11, word_1A123C + 12, 285, 33, (int)v3);
      sub_124DEC();
      return;
    }
    switch ( word_1A1238 )
    {
      case 0:
        sub_C760E(v9, v10);
        v6 = (int16_t)sub_94A9D(word_1831B0, word_1831C6);
        v5 = (int16_t)sub_97A29(word_1831B0, word_1831C6);
        v4 = sub_97588(word_1831C6, 0);
        v0 = (char *)sub_CDF5C(2);
        sprintf(v11, v0, v4, v5, v6, &v9);
LABEL_14:
        sub_1031C6((int)v11, 2);
        goto LABEL_15;
      case 1:
        v8 = (int16_t)sub_97A29(word_1831B0, word_1831C6);
        v7 = sub_97588(word_1831C6, 0);
        v1 = 6;
        break;
      case 2:
        v8 = (int16_t)sub_97A29(word_1831B0, word_1831C6);
        v7 = sub_97588(word_1831C6, 0);
        v1 = 5;
        break;
      case 3:
        v8 = (int16_t)sub_97A29(word_1831B0, word_1831C6);
        v7 = sub_97588(word_1831C6, 0);
        v1 = 4;
        break;
      default:
        goto LABEL_14;
    }
    v2 = (char *)sub_CDF5C(v1);
    sprintf(v11, v2, v7, v8);
    goto LABEL_14;
  }
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 1831B0: using guessed type int16_t word_1831B0;
// 1831C5: using guessed type char byte_1831C5;
// 1831C6: using guessed type int16_t word_1831C6;
// 19994C: using guessed type int16_t word_19994C;
// 199F28: using guessed type char byte_199F28;
// 1A113C: using guessed type int dword_1A113C;
// 1A1140: using guessed type int dword_1A1140;
// 1A11B8: using guessed type int dword_1A11B8;
// 1A1238: using guessed type int16_t word_1A1238;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C7965) --------------------------------------------------------
void sub_C7965()
{
  sub_1112EC(dword_192ED4, 48);
  dword_1A113C = (int)sub_126B42((int)aMainpupsLbx, 48, dword_192ED4);
  dword_1A1144 = (int)sub_126B42((int)aMainpupsLbx, 49, dword_192ED4);
  dword_1A1148 = (int)sub_126B42((int)aMainpupsLbx, 50, dword_192ED4);
  dword_1A1140 = (int)sub_925AE(word_1831B0, word_1831C6, dword_192ED4, 0, 0);
  sub_96CE5(dword_192ED4);
}
// 1831B0: using guessed type int16_t word_1831B0;
// 1831C6: using guessed type int16_t word_1831C6;
// 192ED4: using guessed type int dword_192ED4;
// 1A113C: using guessed type int dword_1A113C;
// 1A1140: using guessed type int dword_1A1140;
// 1A1144: using guessed type int dword_1A1144;
// 1A1148: using guessed type int dword_1A1148;


//----- (000C79F0) --------------------------------------------------------
void sub_C79F0()
{
  sub_1112EC(dword_192ED4, 57);
  dword_1A113C = (int)sub_126B42((int)aMainpupsLbx, 57, dword_192ED4);
  dword_1A1144 = (int)sub_126B42((int)aMainpupsLbx, 58, dword_192ED4);
  dword_1A1148 = (int)sub_126B42((int)aMainpupsLbx, 59, dword_192ED4);
  dword_1A1140 = (int)sub_925AE(word_1831B0, word_1831C6, dword_192ED4, 0, 0);
  if ( !byte_1831C5 )
    sub_96CE5(dword_192ED4);
}
// 1831B0: using guessed type int16_t word_1831B0;
// 1831C5: using guessed type char byte_1831C5;
// 1831C6: using guessed type int16_t word_1831C6;
// 192ED4: using guessed type int dword_192ED4;
// 1A113C: using guessed type int dword_1A113C;
// 1A1140: using guessed type int dword_1A1140;
// 1A1144: using guessed type int dword_1A1144;
// 1A1148: using guessed type int dword_1A1148;


//----- (000C7A84) --------------------------------------------------------
int __fastcall sub_C7A84(int16_t *a1)
{
  int16_t v1; // dx
  int v2; // eax
  int result; // eax

  v1 = 320 - *a1 / 2;
  v2 = a1[1];
  word_1A123A = v1;
  result = v2 / 2;
  word_1A123C = 240 - result;
  return result;
}
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C7AB8) --------------------------------------------------------
char __fastcall sub_C7AB8( int a1, int a2, int a3)
{
  char result; // al

  byte_1831C5 = 1;
  dword_1A11B8 = a3;
  word_1831C6 = a2;
  result = sub_C7ADA(a1);
  byte_1831C5 = 0;
  return result;
}
// 1831C5: using guessed type char byte_1831C5;
// 1831C6: using guessed type int16_t word_1831C6;
// 1A11B8: using guessed type int dword_1A11B8;


//----- (000C7ADA) --------------------------------------------------------
char __fastcall sub_C7ADA(int a1)
{
  int v1; // ebx
  int v2; // edx
  int v3; // eax
  int v4; // ecx
  int16_t *v5; // edi
  int v6; // esi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // esi
  char *v12; // eax
  int16_t v13; // ax
  int v14; // eax
  char *v15; // eax
  int v16; // eax
  int v18; // [esp-Ch] [ebp-210h]
  int v19; // [esp-Ch] [ebp-210h]
  int v20; // [esp-8h] [ebp-20Ch]
  int v21; // [esp-8h] [ebp-20Ch]
  int v22; // [esp-4h] [ebp-208h]
  int v23; // [esp-4h] [ebp-208h]
  _BYTE v24[500]; // [esp+0h] [ebp-204h] BYREF
  _DWORD v25[2]; // [esp+1F4h] [ebp-10h] BYREF
  int v26; // [esp+1FCh] [ebp-8h] BYREF
  int v27; // [esp+200h] [ebp-4h]

  v1 = a1;
  v2 = (int16_t)a1;
  v3 = 17 * (int16_t)sub_C5FB0(a1);
  v27 = 0;
  v4 = 0;
  LOWORD(v3) = *(uint8_t *)(dword_1930D4 + v3 + 2);
  word_1831B0 = v1;
  v26 = v3;
  v25[0] = -1566465889;
  v25[1] = 0;
  v5 = (int16_t *)&v26;
  if ( byte_1831C5 )
  {
    LOWORD(v5) = word_1831C6;
  }
  else
  {
    LOWORD(v5) = *(char *)(dword_197F98 + 3753 * v2 + 1441);
    word_1831C6 = (int16_t)v5;
  }
  v6 = 3753 * (int16_t)v1 + dword_197F98;
  if ( (int16_t)sub_97A29(v1, word_1831C6) <= *(_DWORD *)(v6 + 50) )
    word_1A1238 = 0;
  else
    word_1A1238 = 2;
  if ( (int16_t)v26 == -1 )
  {
    v7 = 17 * *(int16_t *)(dword_192B18 + 361 * (int16_t)sub_C5F5C(v1) + 2);
    LOWORD(v7) = *(uint8_t *)(dword_1930D4 + v7 + 2);
    v26 = v7;
  }
  dword_19F82C = (int16_t)v26;
  sub_120CCB(1, (int)v25);
  dword_1A113C = 0;
  dword_1831B2 = 0;
  if ( byte_1831C5 )
    sub_C79F0();
  else
    sub_C7965();
  sub_C702E(v26, (int16_t *)dword_1A113C);
  sub_119281();
  v8 = 1;
  sub_1191CA((int)sub_C76FA, 1);
  sub_C6E7E();
  sub_C754A();
  word_1A1240 = word_1A11C6;
  sub_124C08();
  sub_124D41();
  sub_C76FA();
  v10 = sub_1077D(v9, 1, v1, v5);
  do
  {
    v1 = sub_1171AB(v10, v8, v1, v4);
    sub_114177();
    v8 = (int16_t)v5;
    sub_9733E(v1, (int16_t)v5);
    if ( word_1A1238 )
    {
      if ( (int16_t)v1 > 0 )
        v27 = 1;
    }
    else
    {
      if ( (_WORD)v1 == word_1A11D2 )
      {
        v8 = word_1831C6;
        v11 = dword_197F98 + 3753 * word_1831B0;
        if ( (int16_t)sub_97A29(word_19999C, word_1831C6) <= *(_DWORD *)(v11 + 50) )
        {
          word_1A1238 = 3;
          v4 = 1;
          if ( word_1831C2 > 0 )
LABEL_19:
            sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
        }
        else
        {
          word_1A1238 = 2;
          v4 = 0;
          if ( word_1831C2 > 0 )
            goto LABEL_19;
        }
        sub_C6E7E();
        sub_C754A();
        if ( (uint8_t)byte_199CB0 > 1u || byte_1831C5 == 1 )
          goto LABEL_22;
        goto LABEL_24;
      }
      if ( (_WORD)v1 == word_1A11D4 )
      {
        word_1A1238 = 1;
        v4 = 0;
        if ( word_1831C2 > 0 )
          sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
        sub_C6E7E();
        sub_C754A();
        if ( (uint8_t)byte_199CB0 > 1u || byte_1831C5 == 1 )
        {
          word_1A1238 = 0;
LABEL_22:
          v27 = 1;
LABEL_23:
          sub_119441();
          sub_117174(3);
          goto LABEL_40;
        }
LABEL_24:
        byte_182ACA = 1;
        goto LABEL_23;
      }
      if ( (int16_t)v1 == -word_1A11D4 )
      {
        v22 = (int16_t)sub_97A29(word_1831B0, word_1831C6);
        v20 = 59 * word_1831C6 + dword_1930DC;
        v18 = dword_190430[*(uint8_t *)(v20 + 52)];
        v12 = (char *)sub_CDF5C(507);
        sprintf(v24, v12, v18, v20, v22);
        v13 = 447;
      }
      else
      {
        if ( (int16_t)v1 != -word_1A11D2 )
          goto LABEL_40;
        v23 = (int16_t)sub_97A29(word_1831B0, word_1831C6);
        v21 = 59 * word_1831C6 + dword_1930DC;
        v19 = dword_190430[*(uint8_t *)(v21 + 52)];
        v15 = (char *)sub_CDF5C(506);
        sprintf(v24, v15, v19, v21, v23);
        v13 = 321;
      }
      v14 = sub_CDF5C(v13);
      sub_A5EB2(v14, (int)v24);
      sub_119281();
      v8 = 1;
      sub_1191CA((int)sub_C76FA, 1);
      if ( word_1831C2 > 0 )
        sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
      sub_C6E7E();
      sub_C754A();
      byte_182ACA = 1;
    }
LABEL_40:
    sub_C76FA();
    v10 = sub_1077D(v16, v8, v1, v5);
  }
  while ( !(_WORD)v27 );
  word_1831B0 = -1;
  sub_C7283(v10, v8);
  return v4;
}
// C7C3D: variable 'v9' is possibly undefined
// C7EDD: variable 'v16' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 1831B0: using guessed type int16_t word_1831B0;
// 1831B2: using guessed type int dword_1831B2;
// 1831C2: using guessed type int16_t word_1831C2;
// 1831C5: using guessed type char byte_1831C5;
// 1831C6: using guessed type int16_t word_1831C6;
// 190430: using guessed type int dword_190430[];
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199CB0: using guessed type char byte_199CB0;
// 19F82C: using guessed type int dword_19F82C;
// 1A113C: using guessed type int dword_1A113C;
// 1A11C6: using guessed type int16_t word_1A11C6;
// 1A11D2: using guessed type int16_t word_1A11D2;
// 1A11D4: using guessed type int16_t word_1A11D4;
// 1A1238: using guessed type int16_t word_1A1238;
// 1A1240: using guessed type int16_t word_1A1240;


//----- (000C7F2F) --------------------------------------------------------
void sub_C7F2F()
{
  JUMPOUT(0xC839B);
}
// C7F32: control flows out of bounds to C839B


//----- (000C7F37) --------------------------------------------------------
void sub_C7F37()
{
  _BYTE *v0; // eax

  sub_10FE41((int)&unk_1A11F8 + 18 * word_1831C2);
  ++word_1831C2;
  v0 = (_BYTE *)sub_CDF5C(12);
  word_1A11C4 = sub_11438B(0, 0, 639, 479, v0, 0);
  sub_CDC2D();
}
// 1831C2: using guessed type int16_t word_1831C2;
// 1A11C4: using guessed type int16_t word_1A11C4;


//----- (000C7F84) --------------------------------------------------------
int (**sub_C7F84())(void)
{
  int (**result)(void); // eax

  if ( word_1831C0 == 1 )
  {
    word_19994C = 1;
    byte_182ACA = 1;
    byte_199F37 = 1;
    result = sub_107C2((int (**)(void))&dword_1A11C0);
  }
  else if ( word_1831C0 == 2 )
  {
    word_1831C0 = 0;
    word_19994C = 1;
    byte_182ACA = 1;
    byte_199F37 = 1;
    sub_107C2((int (**)(void))&dword_1A11C0);
    word_19994C = 1;
    byte_182ACA = 1;
    byte_199F37 = 1;
    result = sub_107C2(&dword_1A11BC);
    word_1831C0 = 2;
  }
  word_19994C = 0;
  byte_199F37 = 0;
  return result;
}
// 182ACA: using guessed type char byte_182ACA;
// 1831C0: using guessed type int16_t word_1831C0;
// 19994C: using guessed type int16_t word_19994C;
// 199F37: using guessed type char byte_199F37;
// 1A11BC: using guessed type int (*dword_1A11BC)(void);
// 1A11C0: using guessed type int dword_1A11C0;


//----- (000C8020) --------------------------------------------------------
void sub_C8020()
{
  int v0; // eax
  int16_t v1; // ax
  char *v2; // eax
  int16_t *v3; // eax
  int16_t *v4; // [esp-4h] [ebp-1F8h]
  _BYTE v5[500]; // [esp+0h] [ebp-1F4h] BYREF

  if ( byte_182ACA || word_19994C )
  {
    word_19994C = 1;
    byte_182ACA = 1;
    byte_199F37 = 1;
    sub_C7F84();
    v0 = *(int16_t *)(dword_1A113C + 2);
    word_1A123A = 320 - *(int16_t *)dword_1A113C / 2;
    word_1A123C = 240 - v0 / 2;
    sub_12A478(word_1A123A, word_1A123C, dword_1A113C);
    sub_972EE(word_1A123A, word_1A123C + 53, word_1831C6);
    sub_12A478(word_1A123A + 13, word_1A123C + 55, dword_1A1140);
    if ( word_1831C8 )
    {
      if ( (uint16_t)word_1831C8 <= 1u )
      {
        v4 = sub_97588(word_1831C6, 0);
        v1 = 584;
      }
      else
      {
        if ( word_1831C8 != 2 )
          goto LABEL_11;
        v4 = sub_97588(word_1831C6, 0);
        v1 = 585;
      }
    }
    else
    {
      v4 = sub_97588(word_1831C6, 0);
      v1 = 1;
    }
    v2 = (char *)sub_CDF5C(v1);
    sprintf(v5, v2, v4);
LABEL_11:
    sub_C5F14(word_1A123A + 14, word_1A123C + 149, 281, 62, (int)v5);
    v3 = sub_97588(word_1831C6, 1);
    sub_C5F14(word_1A123A + 11, word_1A123C + 12, 285, 33, (int)v3);
    sub_124DEC();
    byte_182ACA = 0;
  }
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 1831C6: using guessed type int16_t word_1831C6;
// 1831C8: using guessed type int16_t word_1831C8;
// 19994C: using guessed type int16_t word_19994C;
// 199F37: using guessed type char byte_199F37;
// 1A113C: using guessed type int dword_1A113C;
// 1A1140: using guessed type int dword_1A1140;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C81C5) --------------------------------------------------------
void sub_C81C5()
{
  sub_1112EC(dword_192ED4, 51);
  dword_1A113C = (int)sub_126B42((int)aMainpupsLbx, 51, dword_192ED4);
  JUMPOUT(0xC79D8);
}
// C8204: control flows out of bounds to C79D8
// 1831C6: using guessed type int16_t word_1831C6;
// 192ED4: using guessed type int dword_192ED4;
// 19999C: using guessed type int16_t word_19999C;
// 1A113C: using guessed type int dword_1A113C;


//----- (000C8209) --------------------------------------------------------
void __fastcall sub_C8209( int a1, int a2)
{
  _DWORD *v3; // eax
  int v4; // ebx
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  _DWORD v9[2]; // [esp+0h] [ebp-8h] BYREF
  _DWORD savedregs[5]; // [esp+8h] [ebp+0h] BYREF

  v9[0] = -1566465889;
  v9[1] = 0;
  dword_19F82C = a1;
  sub_120CCB(1, (int)v9);
  dword_1A113C = 0;
  dword_1831B2 = 0;
  word_1831C6 = a2;
  sub_1112EC(dword_192ED4, 51);
  v3 = sub_126B42((int)aMainpupsLbx, 51, dword_192ED4);
  v4 = dword_192ED4;
  dword_1A113C = (int)v3;
  dword_1A1140 = (int)sub_925AE(word_19999C, word_1831C6, dword_192ED4, 0, 0);
  sub_96CE5(dword_192ED4);
  sub_C702E(a1, (int16_t *)dword_1A113C);
  sub_119281();
  v5 = 1;
  sub_1191CA((int)sub_C8020, 1);
  sub_C6E7E();
  sub_C7F2F();
  sub_CDC2D();
  word_1A1240 = word_1A11C6;
  sub_124D41();
  sub_C8020();
  v7 = sub_1077D(v6, 1, v4, (int16_t *)savedregs);
  do
  {
    v5 = sub_1171AB(v7, v5, v4, 0);
    sub_114177();
    sub_C8020();
    v7 = sub_1077D(v8, v5, v4, (int16_t *)savedregs);
  }
  while ( !(_WORD)v5 );
  sub_C7283(v7, v5);
  JUMPOUT(0xC97B9);
}
// C8309: control flows out of bounds to C97B9
// C82E4: variable 'v6' is possibly undefined
// C82FA: variable 'v8' is possibly undefined
// 1831B2: using guessed type int dword_1831B2;
// 1831C6: using guessed type int16_t word_1831C6;
// 192ED4: using guessed type int dword_192ED4;
// 19999C: using guessed type int16_t word_19999C;
// 19F82C: using guessed type int dword_19F82C;
// 1A113C: using guessed type int dword_1A113C;
// 1A1140: using guessed type int dword_1A1140;
// 1A11C6: using guessed type int16_t word_1A11C6;
// 1A1240: using guessed type int16_t word_1A1240;


//----- (000C830E) --------------------------------------------------------
_DWORD *__fastcall sub_C830E(int a1, int a2)
{
  _DWORD *result; // eax

  sub_1112EC(dword_192ED4, a2);
  dword_1A1114 = (int)sub_126B42((int)aMainpupsLbx, 0, dword_192ED4);
  result = sub_126B42((int)aMainpupsLbx, 1, dword_192ED4);
  dword_1A1118 = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 1A1114: using guessed type int dword_1A1114;
// 1A1118: using guessed type int dword_1A1118;


//----- (000C836E) --------------------------------------------------------
unsigned int sub_C836E()
{
  _BYTE *v0; // eax
  unsigned int result; // eax

  byte_199F21 = 1;
  sub_A4F1F(dword_19F82C, word_1A123A, word_1A123C, 13, 47, 0);
  v0 = (_BYTE *)sub_CDF5C(12);
  result = sub_11438B(0, 0, 639, 479, v0, 0);
  word_1A11C4 = result;
  return result;
}
// 199F21: using guessed type char byte_199F21;
// 19F82C: using guessed type int dword_19F82C;
// 1A11C4: using guessed type int16_t word_1A11C4;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C83C5) --------------------------------------------------------
void sub_C83C5()
{
  char *v0; // eax
  int64_t v1; // rax
  int16_t v2; // si
  int16_t v3; // bx
  int16_t v4; // dx
  int16_t v5; // di
  int v6; // ecx
  int v7; // eax
  int v8; // [esp-4h] [ebp-1F8h]
  int v9; // [esp-4h] [ebp-1F8h]
  _BYTE v10[500]; // [esp+0h] [ebp-1F4h] BYREF

  sub_124D41();
  if ( byte_182ACA || word_19994C )
  {
    sub_C7F84();
    sub_124DEC();
    byte_182ACA = 0;
    word_19994C = 0;
  }
  v8 = dword_19306C + 113 * dword_19F82C;
  v0 = (char *)sub_CDF5C(456);
  v1 = sprintf(v10, v0, v8);
  LODWORD(v1) = sub_127C27((int)aBuffer0Lbx_6, SHIDWORD(v1), dword_193174);
  WORD2(v1) = 320 - *(int16_t *)v1 / 2;
  LODWORD(v1) = *(int16_t *)(v1 + 2);
  word_1A123A = WORD2(v1);
  word_1A123C = 240 - (int)v1 / 2;
  sub_A31DA((int16_t)dword_19F82C, 1, (int)v10, SWORD2(v1), word_1A123C, 0, 0, 13, 47);
  if ( byte_1831AE )
  {
    if ( byte_1831AE != 8 )
    {
      v2 = word_1A123A;
      v3 = word_1A123C;
      v4 = byte_1831AE;
      v5 = word_1831AC;
      v9 = sub_C6FB8(byte_1831AE);
      v6 = dword_18F9B8[v4];
      v7 = sub_C6F51(v5, v4);
      sub_C7318(v2 + 6, v3 + 76, v7, v6, v9);
    }
  }
  JUMPOUT(0xC7EFD);
}
// C8503: control flows out of bounds to C7EFD
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 1831AC: using guessed type int16_t word_1831AC;
// 1831AE: using guessed type char byte_1831AE;
// 18F9B8: using guessed type int dword_18F9B8[];
// 19306C: using guessed type int dword_19306C;
// 193174: using guessed type int dword_193174;
// 19994C: using guessed type int16_t word_19994C;
// 19F82C: using guessed type int dword_19F82C;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C8508) --------------------------------------------------------
int __fastcall sub_C8508(int16_t *a1, int16_t *a2)
{
  int result; // eax
  int16_t v3; // [esp+0h] [ebp-14h] BYREF
  int v4; // [esp+4h] [ebp-10h] BYREF
  int16_t v5; // [esp+8h] [ebp-Ch] BYREF
  int v6; // [esp+Ch] [ebp-8h] BYREF
  int16_t v7; // [esp+10h] [ebp-4h] BYREF

  sub_899AB(*a2, *a1, (int)word_1992D4, &v5, &v3, (int16_t *)&v4, &v7, (int16_t *)&v6);
  word_1999DC = v4;
  result = (int16_t)v6;
  if ( (int16_t)v6 > -1 )
  {
    result = v6;
    word_1999C0 = v6;
  }
  return result;
}
// 1992D4: using guessed type int16_t word_1992D4[10];
// 1999C0: using guessed type int16_t word_1999C0;
// 1999DC: using guessed type int16_t word_1999DC;


//----- (000C8556) --------------------------------------------------------
void __fastcall sub_C8556( int a1, int a2)
{
  int16_t *v3; // edi
  _DWORD *v4; // eax
  int v5; // ebx
  int16_t *v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int16_t v10; // si
  int16_t v11; // dx
  int16_t v12; // ax
  int v13; // eax
  _DWORD v15[2]; // [esp+8h] [ebp-14h] BYREF
  int v16; // [esp+10h] [ebp-Ch] BYREF
  int16_t v17; // [esp+14h] [ebp-8h] BYREF
  char *v18; // [esp+18h] [ebp-4h] BYREF

  v16 = 0;
  dword_19F82C = a1;
  v15[0] = -1566465889;
  v15[1] = 0;
  v3 = (int16_t *)&v16;
  sub_120CCB(1, (int)v15);
  sub_1112EC(dword_192ED4, (int)v15);
  dword_1A1114 = (int)sub_126B42((int)aMainpupsLbx, 0, dword_192ED4);
  v4 = sub_126B42((int)aMainpupsLbx, 1, dword_192ED4);
  dword_1A1130 = 0;
  dword_1A1114 = 0;
  dword_1A1118 = (int)v4;
  v5 = dword_193174;
  byte_1831AE = a2;
  dword_1831B2 = 0;
  v6 = (int16_t *)sub_127C27((int)aBuffer0Lbx_6, 73, dword_193174);
  sub_C702E(a1, v6);
  sub_124DEC();
  sub_119281();
  v7 = 1;
  sub_1191CA((int)sub_C83C5, 1);
  sub_1196F7();
  sub_C6E7E();
  sub_BF500();
  sub_C836E();
  word_1A1240 = word_1A11C6;
  sub_C83C5();
  sub_1077D(v8, 1, v5, (int16_t *)&v16);
  while ( 1 )
  {
    sub_12C2C6(2);
    sub_12C2A0();
    v16 = sub_1171AB(v9, v7, v5, a1);
    v18 = sub_114177();
    if ( byte_1831AE )
    {
      if ( byte_1831AE == 8 )
      {
        byte_1831AE = 0;
        LOWORD(v3) = word_1A123A;
        v5 = word_19999C;
        v10 = word_1A123C;
        if ( sub_97F8D(&v17, word_19999C, (int)v3) )
        {
          v11 = v17;
          v12 = a1;
          word_1831C8 = 1;
        }
        else
        {
          v11 = v17;
          v12 = a1;
          word_1831C8 = 2;
        }
        sub_C8209(v12, v11);
        word_1831C8 = 0;
        v16 = 0;
        byte_182ACA = 1;
        v7 = 1;
        word_1A123A = (int16_t)v3;
        word_1A123C = v10;
        sub_119281();
        sub_1191CA((int)sub_C83C5, 1);
      }
      else if ( (_WORD)v16 )
      {
        byte_1831AE = 0;
        v16 = 0;
        byte_182ACA = 1;
      }
      if ( word_19994C )
        byte_182ACA = 1;
    }
    else
    {
      v7 = (int)&v18;
      sub_C8508((int16_t *)&v16, (int16_t *)&v18);
    }
    sub_C83C5();
    sub_1077D(v13, v7, v5, v3);
    if ( (int16_t)v16 >= 1 && !byte_1831AE )
      JUMPOUT(0xC8304);
  }
}
// C876C: control flows out of bounds to C8304
// C8648: variable 'v8' is possibly undefined
// C865C: variable 'v9' is possibly undefined
// C874F: variable 'v13' is possibly undefined
// 182ACA: using guessed type char byte_182ACA;
// 1831AE: using guessed type char byte_1831AE;
// 1831B2: using guessed type int dword_1831B2;
// 1831C8: using guessed type int16_t word_1831C8;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 19F82C: using guessed type int dword_19F82C;
// 1A1114: using guessed type int dword_1A1114;
// 1A1118: using guessed type int dword_1A1118;
// 1A1130: using guessed type int dword_1A1130;
// 1A11C6: using guessed type int16_t word_1A11C6;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;
// 1A1240: using guessed type int16_t word_1A1240;


//----- (000C8771) --------------------------------------------------------
_DWORD *__fastcall sub_C8771(int a1, int a2)
{
  _DWORD *result; // eax

  sub_1112EC(dword_192ED4, a2);
  result = sub_126B42((int)aMainpupsLbx, 0, dword_192ED4);
  dword_1A1114 = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 1A1114: using guessed type int dword_1A1114;


//----- (000C87C1) --------------------------------------------------------
void sub_C87C1()
{
  JUMPOUT(0xC8373);
}
// C87C9: control flows out of bounds to C8373


//----- (000C87DE) --------------------------------------------------------
void sub_C87DE()
{
  int16_t v0; // ax
  char *v1; // eax
  int16_t v2; // si
  int16_t v3; // bx
  int16_t v4; // dx
  int16_t v5; // di
  int v6; // ecx
  int v7; // eax
  int v8; // [esp-4h] [ebp+7Ah]
  int v9; // [esp-4h] [ebp+7Ah]
  _BYTE v10[500]; // [esp+0h] [ebp+7Eh] BYREF

  sub_120BB5(4, (int)&unk_1831B7);
  if ( byte_182ACA || word_19994C )
  {
    sub_C7F84();
    sub_124DEC();
    byte_182ACA = 0;
  }
  switch ( byte_1831CA )
  {
    case 0:
      v8 = dword_19306C + 113 * word_1831AC;
      if ( byte_1831CB )
        v0 = 462;
      else
        v0 = 461;
      goto LABEL_7;
    case 1:
      v8 = dword_19306C + 113 * word_1831AC;
      v0 = 459;
      goto LABEL_7;
    case 2:
      v8 = dword_19306C + 113 * word_1831AC;
      v0 = 463;
      goto LABEL_7;
    case 3:
      v8 = dword_19306C + 113 * word_1831AC;
      v0 = 460;
LABEL_7:
      v1 = (char *)sub_CDF5C(v0);
      sprintf(v10, v1, v8);
      sub_A31DA((int16_t)dword_19F82C, 1, (int)v10, word_1A123A, word_1A123C, 0, 0, 13, 47);
      break;
    default:
      break;
  }
  sub_120BB5(1, (int)&unk_1831B7);
  if ( byte_1831AE )
  {
    if ( byte_1831AE != 8 )
    {
      v2 = word_1A123A;
      v3 = word_1A123C;
      v4 = byte_1831AE;
      v5 = word_1831AC;
      v9 = sub_C6FB8(byte_1831AE);
      v6 = dword_18F9B8[v4];
      v7 = sub_C6F51(v5, v4);
      sub_C7318(v2, v3 + 50, v7, v6, v9);
    }
  }
  JUMPOUT(0xC7EFE);
}
// C897C: control flows out of bounds to C7EFE
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 1831AC: using guessed type int16_t word_1831AC;
// 1831AE: using guessed type char byte_1831AE;
// 1831CA: using guessed type char byte_1831CA;
// 1831CB: using guessed type char byte_1831CB;
// 18F9B8: using guessed type int dword_18F9B8[];
// 19306C: using guessed type int dword_19306C;
// 19994C: using guessed type int16_t word_19994C;
// 19F82C: using guessed type int dword_19F82C;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C8981) --------------------------------------------------------
int __fastcall sub_C8981(int16_t *a1, int16_t *a2, _WORD *a3)
{
  int16_t v3; // dx
  int v4; // eax
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int16_t v9; // ax
  int v10; // eax
  int v11; // eax
  char *v12; // eax
  int result; // eax
  int v14; // eax
  char v15; // al
  int v16; // [esp+0h] [ebp-14h] BYREF
  int16_t v17; // [esp+4h] [ebp-10h] BYREF
  int16_t v18; // [esp+8h] [ebp-Ch] BYREF
  int16_t v19; // [esp+Ch] [ebp-8h] BYREF
  int v20; // [esp+10h] [ebp-4h] BYREF

  v3 = sub_899AB(*a2, *a1, (int)word_1992D4, &v17, &v19, (int16_t *)&v20, &v18, (int16_t *)&v16);
  word_1999DC = v20;
  if ( (int16_t)v16 > -1 )
    word_1999C0 = v16;
  if ( v3 || v19 <= -1 )
    return -1;
  LOWORD(v4) = sub_78CDB(dword_19F82C, v19);
  v5 = v4;
  if ( !byte_1831CA
    && ((v6 = 17 * (int16_t)v4, *(_BYTE *)(v6 + dword_1930D4 + 4) != 3)
     || (v7 = *(int16_t *)(v6 + dword_1930D4), v7 != -1) && !*(_BYTE *)(dword_192B18 + 361 * v7 + 6))
    || byte_1831CA == 1 && *(int16_t *)(dword_1930D4 + 17 * (int16_t)v5) != -1
    || byte_1831CA == 1
    && (v8 = *(int16_t *)(dword_1930D4 + 17 * (int16_t)v5), v8 != -1)
    && !*(_BYTE *)(dword_192B18 + 361 * v8 + 6) )
  {
    v9 = 566;
LABEL_15:
    v10 = sub_CDF5C(v9);
    sub_C5B5F(v10);
    byte_182ACA = 1;
    if ( word_1831C2 > 0 )
      sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
    sub_C6E7E();
    sub_BF500();
    sub_C87C1();
    sub_CDC18();
    sub_124E36();
    sub_C87DE();
    sub_1191CA((int)sub_C87DE, 1);
    goto LABEL_29;
  }
  if ( byte_1831CA == 2 )
  {
    v11 = *(int16_t *)(dword_1930D4 + 17 * (int16_t)v5);
    if ( v11 == -1 || (v12 = (char *)(dword_192B18 + 361 * v11), v12[6]) || *v12 != word_19999C )
    {
      v9 = 571;
      goto LABEL_15;
    }
  }
  if ( byte_1831CA == 3 )
  {
    if ( *(_BYTE *)(dword_1930D4 + 17 * (int16_t)v5 + 4) != 3 )
    {
LABEL_25:
      result = v5;
      *a3 = 1;
      return result;
    }
    v14 = sub_CDF5C(565);
    sub_C5B5F(v14);
  }
  else
  {
    if ( byte_1831CA )
      goto LABEL_25;
    sub_C9FC4(v5);
    if ( v15 )
      goto LABEL_25;
  }
LABEL_29:
  if ( word_1831C2 > 0 )
    sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
  sub_C6E7E();
  sub_BF500();
  sub_C87C1();
  sub_CDC18();
  sub_124E36();
  sub_C87DE();
  sub_1191CA((int)sub_C87DE, 1);
  return -1;
}
// C89EE: variable 'v4' is possibly undefined
// C8B82: variable 'v15' is possibly undefined
// 182ACA: using guessed type char byte_182ACA;
// 1831C2: using guessed type int16_t word_1831C2;
// 1831CA: using guessed type char byte_1831CA;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 1992D4: using guessed type int16_t word_1992D4[10];
// 19999C: using guessed type int16_t word_19999C;
// 1999C0: using guessed type int16_t word_1999C0;
// 1999DC: using guessed type int16_t word_1999DC;
// 19F82C: using guessed type int dword_19F82C;


//----- (000C8BE0) --------------------------------------------------------
int __fastcall sub_C8BE0(int16_t *a1, int16_t *a2, _WORD *a3)
{
  int v3; // ecx
  int16_t v4; // si
  int16_t v5; // di
  int16_t v6; // dx
  int16_t v7; // ax
  int v8; // eax
  int16_t v10; // [esp+0h] [ebp-4h] BYREF

  v3 = 0;
  if ( byte_1831AE )
  {
    if ( byte_1831AE == 8 )
    {
      byte_1831AE = 0;
      v4 = word_1A123A;
      v5 = word_1A123C;
      if ( sub_97F8D(&v10, word_19999C, word_1A123C) )
      {
        v6 = v10;
        v7 = word_1831AC;
        word_1831C8 = 1;
      }
      else
      {
        v6 = v10;
        v7 = word_1831AC;
        word_1831C8 = 2;
      }
      sub_C8209(v7, v6);
      word_1831C8 = 0;
      byte_182ACA = 1;
      word_1A123A = v4;
      word_1A123C = v5;
      if ( word_1831C2 > 0 )
        sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
      sub_C6E7E();
      sub_BF500();
      sub_C87C1();
      sub_CDC18();
      sub_124E36();
      sub_C87DE();
      v8 = sub_1191CA((int)sub_C87DE, 1);
      nullsub_11(v8);
    }
    else if ( *a1 )
    {
      byte_1831AE = 0;
      byte_182ACA = 1;
    }
  }
  else if ( *a1 == word_1A11C8 )
  {
    v3 = -1;
    *a3 = 1;
  }
  else
  {
    v3 = sub_C8981(a1, a2, a3);
  }
  if ( word_19994C )
    byte_182ACA = 1;
  return v3;
}
// CDBC3: using guessed type int __fastcall nullsub_11(_DWORD);
// 182ACA: using guessed type char byte_182ACA;
// 1831AC: using guessed type int16_t word_1831AC;
// 1831AE: using guessed type char byte_1831AE;
// 1831C2: using guessed type int16_t word_1831C2;
// 1831C8: using guessed type int16_t word_1831C8;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 1A11C8: using guessed type int16_t word_1A11C8;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C8D3C) --------------------------------------------------------
void __fastcall sub_C8D3C( int a1)
{
  byte_1831CA = 2;
  sub_C8DB8(a1, 0);
  byte_1831CA = 0;
}
// 1831CA: using guessed type char byte_1831CA;


//----- (000C8D49) --------------------------------------------------------
int sub_C8D49()
{
  int result; // eax

  byte_1831CA = 1;
  result = sub_C8DB8();
  byte_1831CA = 0;
  return result;
}
// C8DB8: using guessed type int sub_C8DB8(void);
// 1831CA: using guessed type char byte_1831CA;


//----- (000C8D56) --------------------------------------------------------
int __fastcall sub_C8D56( int a1)
{
  int v1; // ebx
  int result; // eax

  v1 = 113 * a1;
  result = v1 + dword_19306C;
  if ( (((int)*(uint8_t *)(v1 + dword_19306C + 52) >> word_19999C) & 1) != 0 )
  {
    byte_1831AE = sub_FD875(result, word_19999C);
    result = v1 + dword_19306C;
    *(_BYTE *)(result + 52) &= ~(1 << word_19999C);
    if ( *(char *)(result + 40) >= 50 )
      *(_BYTE *)(result + 40) = 0;
  }
  else
  {
    byte_1831AE = 0;
  }
  return result;
}
// 1831AE: using guessed type char byte_1831AE;
// 19306C: using guessed type int dword_19306C;
// 19999C: using guessed type int16_t word_19999C;


//----- (000C8DB8) --------------------------------------------------------
int __fastcall sub_C8DB8( int a1, int a2)
{
  int v2; // ecx
  int v3; // ebx
  int16_t *v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int16_t v10; // ax
  int16_t v11; // [esp+0h] [ebp-18h]
  _DWORD v12[2]; // [esp+4h] [ebp-14h] BYREF
  int v13; // [esp+Ch] [ebp-Ch] BYREF
  int v14; // [esp+10h] [ebp-8h] BYREF
  char *v15; // [esp+14h] [ebp-4h] BYREF

  v14 = 0;
  v13 = 0;
  word_1A1240 = -1;
  v2 = a1;
  byte_1831CB = a2;
  dword_19F82C = a1;
  v12[0] = -1566465889;
  v12[1] = 0;
  sub_120CCB(1, (int)v12);
  sub_1112EC(dword_192ED4, (int)v12);
  dword_1A1114 = (int)sub_126B42((int)aMainpupsLbx, 0, dword_192ED4);
  sub_C8D56(v2);
  dword_1A1130 = 0;
  dword_1A1114 = 0;
  v3 = dword_193174;
  dword_1831B2 = 0;
  v4 = (int16_t *)sub_127C27((int)aBuffer0Lbx_6, 73, dword_193174);
  sub_C702E(v2, v4);
  sub_1196F7();
  sub_119281();
  sub_1191CA((int)sub_C87DE, 1);
  sub_C6E7E();
  sub_BF500();
  sub_C87C1();
  sub_CDC18();
  sub_C87DE();
  sub_1077D(v5, 1, v3, (int16_t *)&v13);
  do
  {
    v6 = (int)&v15;
    sub_12C2C6(2);
    sub_12C2A0();
    v14 = sub_1171AB(v7, (int)&v15, (int)&v13, v2);
    v15 = sub_114177();
    v2 = sub_C8BE0((int16_t *)&v14, (int16_t *)&v15, &v13);
    sub_C87DE();
    sub_1077D(v8, (int)&v15, (int)&v13, (int16_t *)&v13);
  }
  while ( !(_WORD)v13 );
  LOBYTE(v9) = sub_9222A(v11);
  if ( (_BYTE)v9 )
  {
    if ( !byte_199BE2 )
    {
      v9 = (int16_t)v2;
      if ( (int16_t)v2 != -1 )
      {
        v6 = (int16_t)sub_923C4();
        v10 = sub_923BE();
        LOBYTE(v9) = sub_92281(v10, v6, v11, 0);
      }
    }
  }
  sub_C7283(v9, v6);
  JUMPOUT(0xC97B9);
}
// C8F17: control flows out of bounds to C97B9
// C8E94: variable 'v5' is possibly undefined
// C8EAE: variable 'v7' is possibly undefined
// C8ECF: variable 'v8' is possibly undefined
// C8EE1: variable 'v11' is possibly undefined
// C8F10: variable 'v9' is possibly undefined
// C6E40: using guessed type int dword_C6E40[3];
// 1831B2: using guessed type int dword_1831B2;
// 1831CB: using guessed type char byte_1831CB;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 199BE2: using guessed type char byte_199BE2;
// 19F82C: using guessed type int dword_19F82C;
// 1A1114: using guessed type int dword_1A1114;
// 1A1130: using guessed type int dword_1A1130;
// 1A1240: using guessed type int16_t word_1A1240;


//----- (000C8F1C) --------------------------------------------------------
void sub_C8F1C()
{
  sub_1112EC(dword_192ED4, 2);
  dword_1A1120 = (int)sub_126B42((int)aMainpupsLbx, 2, dword_192ED4);
  dword_1A112C = (int)sub_126B42((int)aMainpupsLbx, 46, dword_192ED4);
  sub_A3FE6(dword_19F82C);
}
// 192ED4: using guessed type int dword_192ED4;
// 19F82C: using guessed type int dword_19F82C;
// 1A1120: using guessed type int dword_1A1120;
// 1A112C: using guessed type int dword_1A112C;


//----- (000C8F6B) --------------------------------------------------------
void sub_C8F6B()
{
  sub_10FE41((int)&unk_1A11F8 + 18 * word_1831C2);
  ++word_1831C2;
  sub_BF500();
  JUMPOUT(0xC8FA7);
}
// C8F98: control flows out of bounds to C8FA7
// 1831C2: using guessed type int16_t word_1831C2;


//----- (000C8F9A) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (positive sp value has been found (funcsize=4)) - nutno dohledat rucne v IDA @ 0xC8F9D */
int __fastcall sub_C8F9A(_DWORD _p0)
{
  DECOMP_TODO("positive sp value has been found (funcsize=4)");
}


//----- (000C8FC7) --------------------------------------------------------
void sub_C8FC7()
{
  char *v0; // eax
  int v1; // [esp-4h] [ebp-1F8h]
  _BYTE v2[500]; // [esp+0h] [ebp-1F4h] BYREF

  if ( byte_182ACA || word_19994C )
  {
    sub_C7F84();
    sub_124DEC();
    byte_182ACA = 0;
  }
  v1 = dword_197F98 + 3753 * word_1831B0 + 21;
  v0 = (char *)sub_CDF5C(3);
  sprintf(v2, v0, v1);
  JUMPOUT(0xC9025);
}
// C9022: control flows out of bounds to C9025
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 1831B0: using guessed type int16_t word_1831B0;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;


//----- (000C9058) --------------------------------------------------------
int16_t __fastcall sub_C9058(int16_t *a1, int16_t *a2, _WORD *a3)
{
  int16_t v3; // ax
  _BYTE *v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v9; // eax
  int v10; // [esp+0h] [ebp-14h] BYREF
  int v11; // [esp+4h] [ebp-10h] BYREF
  int16_t v12; // [esp+8h] [ebp-Ch] BYREF
  int16_t v13; // [esp+Ch] [ebp-8h] BYREF
  int16_t v14; // [esp+10h] [ebp-4h] BYREF

  v3 = sub_899AB(*a2, *a1, (int)word_1992D4, &v13, &v14, (int16_t *)&v10, &v12, (int16_t *)&v11);
  word_1999DC = v10;
  if ( (int16_t)v11 > -1 )
    word_1999C0 = v11;
  if ( v3 || v14 <= -1 )
    return -1;
  v4 = (_BYTE *)(17 * sub_78CDB(dword_19F82C, v14) + dword_1930D4);
  v5 = *(int16_t *)v4;
  if ( v5 != -1 && v4[4] == 3 )
  {
    if ( *(char *)(dword_192B18 + 361 * v5) != word_1831B0 )
    {
      *a3 = 1;
      return *(_WORD *)v4;
    }
    v7 = sub_CDF5C(593);
    sub_C5B5F(v7);
    byte_182ACA = 1;
    if ( word_1831C2 <= 0 )
      goto LABEL_13;
    goto LABEL_11;
  }
  v6 = sub_CDF5C(510);
  sub_C5B5F(v6);
  byte_182ACA = 1;
  if ( word_1831C2 > 0 )
LABEL_11:
    sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
LABEL_13:
  sub_C6E7E();
  v9 = sub_BF500();
  sub_C8F9A(v9);
  sub_124E36();
  sub_C8FC7();
  sub_1191CA((int)sub_C8FC7, 1);
  return -1;
}
// C8F9A: using guessed type int __fastcall sub_C8F9A(_DWORD);
// 182ACA: using guessed type char byte_182ACA;
// 1831B0: using guessed type int16_t word_1831B0;
// 1831C2: using guessed type int16_t word_1831C2;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 1992D4: using guessed type int16_t word_1992D4[10];
// 1999C0: using guessed type int16_t word_1999C0;
// 1999DC: using guessed type int16_t word_1999DC;
// 19F82C: using guessed type int dword_19F82C;


//----- (000C91B8) --------------------------------------------------------
void __fastcall sub_C91B8( int a1, int a2)
{
  int v2; // ecx
  int *v3; // ebx
  int16_t *v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD v12[2]; // [esp+0h] [ebp-14h] BYREF
  int v13; // [esp+8h] [ebp-Ch] BYREF
  int v14; // [esp+Ch] [ebp-8h] BYREF
  char *v15; // [esp+10h] [ebp-4h] BYREF

  v13 = 0;
  v14 = 0;
  word_1A1240 = -1;
  v2 = a1;
  word_1831B0 = a2;
  dword_19F82C = a1;
  v12[0] = -1566465889;
  v12[1] = *(int *)((char *)&dword_C6E40[2] + 2);
  sub_120CCB(1, (int)v12);
  sub_C8F1C();
  v3 = (int *)dword_193174;
  v4 = (int16_t *)sub_127C27((int)aBuffer0Lbx_6, 73, dword_193174);
  sub_C702E(v2, v4);
  sub_119281();
  v5 = 1;
  sub_1191CA((int)sub_C8FC7, 1);
  sub_C6E7E();
  v6 = sub_BF500();
  sub_C8F9A(v6);
  word_1A1240 = word_1A11C6;
  sub_C8FC7();
  sub_1077D(v7, 1, (int)v3, (int16_t *)&v13);
  while ( 1 )
  {
    sub_12C2C6(2);
    sub_12C2A0();
    v13 = sub_1171AB(v8, v5, (int)v3, v2);
    v15 = sub_114177();
    if ( (_WORD)v13 == word_1A11CE )
    {
      v14 = 1;
      v2 = -1;
    }
    else
    {
      v3 = &v14;
      v5 = (int)&v15;
      LOWORD(v9) = sub_C9058((int16_t *)&v13, (int16_t *)&v15, &v14);
      v2 = v9;
    }
    sub_C8FC7();
    v11 = sub_1077D(v10, v5, (int)v3, (int16_t *)&v13);
    if ( (_WORD)v14 )
    {
      sub_C7283(v11, v5);
      JUMPOUT(0xC97B9);
    }
  }
}
// C92BB: control flows out of bounds to C97B9
// C9255: variable 'v7' is possibly undefined
// C9269: variable 'v8' is possibly undefined
// C92A1: variable 'v9' is possibly undefined
// C92A8: variable 'v10' is possibly undefined
// C6E40: using guessed type int dword_C6E40[3];
// C8F9A: using guessed type int __fastcall sub_C8F9A(_DWORD);
// 1831B0: using guessed type int16_t word_1831B0;
// 193174: using guessed type int dword_193174;
// 19F82C: using guessed type int dword_19F82C;
// 1A11C6: using guessed type int16_t word_1A11C6;
// 1A11CE: using guessed type int16_t word_1A11CE;
// 1A1240: using guessed type int16_t word_1A1240;


//----- (000C92C0) --------------------------------------------------------
_DWORD *sub_C92C0()
{
  _DWORD *result; // eax

  sub_1112EC(dword_192ED4, 2);
  dword_1A1134 = (int)sub_126B42((int)aMainpupsLbx, 2, dword_192ED4);
  result = sub_126B42((int)aMainpupsLbx, 47, dword_192ED4);
  dword_1A1138 = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 1A1134: using guessed type int dword_1A1134;
// 1A1138: using guessed type int dword_1A1138;


//----- (000C9303) --------------------------------------------------------
void sub_C9303()
{
  sub_10FE41((int)&unk_1A11F8 + 18 * word_1831C2);
  ++word_1831C2;
  sub_BF500();
  JUMPOUT(0xC8FA7);
}
// C9330: control flows out of bounds to C8FA7
// 1831C2: using guessed type int16_t word_1831C2;


//----- (000C9335) --------------------------------------------------------
unsigned int sub_C9335()
{
  return sub_A4F1F(dword_19F82C, word_1A123A, word_1A123C, 13, 47, &word_1A11D0);
}
// 19F82C: using guessed type int dword_19F82C;
// 1A11D0: using guessed type int16_t word_1A11D0;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C9342) --------------------------------------------------------
void sub_C9342()
{
  char *v0; // eax
  int v1; // [esp-8h] [ebp-1FCh]
  int v2; // [esp-4h] [ebp-1F8h]
  _BYTE v3[500]; // [esp+0h] [ebp-1F4h] BYREF

  if ( byte_182ACA || word_19994C )
  {
    sub_C7F84();
    sub_124DEC();
    byte_182ACA = 0;
  }
  v2 = dword_19306C + 113 * dword_19F82C;
  v1 = dword_197F98 + 3753 * word_1831B0 + 21;
  v0 = (char *)sub_CDF5C(69);
  sprintf(v3, v0, v1, v2);
  sub_A31DA((int16_t)dword_19F82C, 1, (int)v3, word_1A123A, word_1A123C, 0, 0, 13, 47);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 1831B0: using guessed type int16_t word_1831B0;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19F82C: using guessed type int dword_19F82C;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C93B5) --------------------------------------------------------
int __fastcall sub_C93B5(int16_t *a1, int16_t *a2, _WORD *a3)
{
  int v4; // ebx
  int16_t *v5; // eax
  int v6; // edx
  int16_t v7; // ax
  int v8; // eax
  int v9; // eax
  int result; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // [esp+0h] [ebp-14h] BYREF
  int16_t v15; // [esp+4h] [ebp-10h] BYREF
  int v16; // [esp+8h] [ebp-Ch] BYREF
  int16_t v17; // [esp+Ch] [ebp-8h] BYREF
  int16_t v18; // [esp+10h] [ebp-4h] BYREF

  v4 = sub_899AB(*a2, *a1, (int)word_1992D4, &v17, &v15, (int16_t *)&v16, &v18, (int16_t *)&v14);
  word_1999DC = v16;
  if ( word_19994C )
  {
    byte_182ACA = 1;
    if ( word_1831C2 > 0 )
      sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
    sub_C6E7E();
    sub_BF500();
    sub_C9335();
    sub_124E36();
    sub_C9342();
    sub_1191CA((int)sub_C9342, 1);
  }
  if ( (int16_t)v14 > -1 )
    word_1999C0 = v14;
  if ( !(_WORD)v4 && v15 > -1 )
  {
    v5 = (int16_t *)(dword_1930D4 + 17 * sub_78CDB(dword_19F82C, v15));
    v6 = *v5;
    if ( v6 == -1 )
    {
      if ( *((_BYTE *)v5 + 4) == 3 )
        v7 = 592;
      else
        v7 = 591;
      v8 = sub_CDF5C(v7);
      sub_C5B5F(v8);
      byte_182ACA = 1;
      if ( word_1831C2 <= 0 )
        goto LABEL_19;
    }
    else
    {
      if ( *(char *)(dword_192B18 + 361 * v6) != word_1831B0 )
      {
        *a3 = 1;
        LOWORD(v5) = *v5;
        return (int)v5 + 15;
      }
      v9 = sub_CDF5C(594);
      sub_C5B5F(v9);
      byte_182ACA = 1;
      if ( word_1831C2 <= 0 )
        goto LABEL_19;
    }
    sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
LABEL_19:
    sub_C6E7E();
    sub_BF500();
    sub_C9335();
    sub_124E36();
    sub_C9342();
    sub_1191CA((int)sub_C9342, 1);
  }
  if ( (_WORD)v4 || v18 <= -1 )
    return -1;
  v11 = 129 * sub_788A2(v18);
  LOWORD(v4) = *(char *)(dword_197F9C + v11 + 99);
  if ( (_WORD)v4 != word_1831B0 )
  {
    if ( !sub_C6EBF(*(char *)(dword_197F9C + v11 + 99), dword_19F82C) )
    {
      result = v4;
      *a3 = 1;
      return result;
    }
    v12 = sub_CDF5C(590);
    sub_C5B5F(v12);
    byte_182ACA = 1;
    if ( word_1831C2 <= 0 )
      goto LABEL_29;
    goto LABEL_28;
  }
  v13 = sub_CDF5C(595);
  sub_C5B5F(v13);
  byte_182ACA = 1;
  if ( word_1831C2 > 0 )
LABEL_28:
    sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
LABEL_29:
  sub_C6E7E();
  sub_BF500();
  sub_C9335();
  sub_124E36();
  sub_C9342();
  sub_1191CA((int)sub_C9342, 1);
  return -1;
}
// 182ACA: using guessed type char byte_182ACA;
// 1831B0: using guessed type int16_t word_1831B0;
// 1831C2: using guessed type int16_t word_1831C2;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;
// 1992D4: using guessed type int16_t word_1992D4[10];
// 19994C: using guessed type int16_t word_19994C;
// 1999C0: using guessed type int16_t word_1999C0;
// 1999DC: using guessed type int16_t word_1999DC;
// 19F82C: using guessed type int dword_19F82C;


//----- (000C9676) --------------------------------------------------------
int __fastcall sub_C9676( int a1, int a2)
{
  int v2; // ecx
  _DWORD *v3; // eax
  int *v4; // ebx
  int16_t *v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  _DWORD v12[2]; // [esp+0h] [ebp-14h] BYREF
  int v13; // [esp+8h] [ebp-Ch] BYREF
  char *v14; // [esp+Ch] [ebp-8h] BYREF
  int v15; // [esp+10h] [ebp-4h] BYREF

  v15 = 0;
  v13 = 0;
  word_1A1240 = -1;
  word_19999C = a2;
  v2 = a1;
  word_1831B0 = a2;
  dword_19F82C = a1;
  v12[0] = -1566465889;
  v12[1] = 0;
  sub_120CCB(1, (int)v12);
  sub_1112EC(dword_192ED4, 2);
  dword_1A1134 = (int)sub_126B42((int)aMainpupsLbx, 2, dword_192ED4);
  v3 = sub_126B42((int)aMainpupsLbx, 47, dword_192ED4);
  v4 = (int *)dword_193174;
  dword_1A1138 = (int)v3;
  v5 = (int16_t *)sub_127C27((int)aBuffer0Lbx_6, 73, dword_193174);
  sub_C702E(v2, v5);
  sub_119281();
  v6 = 1;
  sub_1191CA((int)sub_C9342, 1);
  sub_C6E7E();
  sub_BF500();
  sub_C9335();
  word_1A1240 = word_1A11C6;
  sub_C9342();
  sub_1077D(v7, 1, (int)v4, (int16_t *)&v13);
  do
  {
    sub_12C2C6(2);
    sub_12C2A0();
    v15 = sub_1171AB(v8, v6, (int)v4, v2);
    v14 = sub_114177();
    if ( (_WORD)v15 == word_1A11D0 )
    {
      v13 = 1;
      v6 = -1;
    }
    else
    {
      v4 = &v13;
      v6 = sub_C93B5((int16_t *)&v15, (int16_t *)&v14, &v13);
    }
    sub_C9342();
    v10 = sub_1077D(v9, v6, (int)v4, (int16_t *)&v13);
  }
  while ( !(_WORD)v13 );
  sub_C7283(v10, v6);
  return v6;
}
// C9753: variable 'v7' is possibly undefined
// C9767: variable 'v8' is possibly undefined
// C97A6: variable 'v9' is possibly undefined
// 1831B0: using guessed type int16_t word_1831B0;
// 192ED4: using guessed type int dword_192ED4;
// 193174: using guessed type int dword_193174;
// 19999C: using guessed type int16_t word_19999C;
// 19F82C: using guessed type int dword_19F82C;
// 1A1134: using guessed type int dword_1A1134;
// 1A1138: using guessed type int dword_1A1138;
// 1A11C6: using guessed type int16_t word_1A11C6;
// 1A11D0: using guessed type int16_t word_1A11D0;
// 1A1240: using guessed type int16_t word_1A1240;


//----- (000C97DB) --------------------------------------------------------
int __fastcall sub_C97DB(int a1, int a2, int a3, int a4)
{
  int16_t *v4; // esi
  int v5; // eax
  int16_t v6; // ax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v11; // [esp-10h] [ebp-18Ah]
  char *v12; // [esp-8h] [ebp-182h]
  int v13; // [esp-4h] [ebp-17Eh]
  int v14; // [esp-4h] [ebp-17Eh]
  int16_t v15; // [esp+0h] [ebp-17Ah]
  _BYTE v16[500]; // [esp+4h] [ebp-176h] BYREF
  _BYTE v17[500]; // [esp+1F8h] [ebp+7Eh] BYREF
  char v18[500]; // [esp+3ECh] [ebp+272h] BYREF
  _BYTE v19[500]; // [esp+5E0h] [ebp+466h] BYREF

  sub_107AF(&dword_1A11C0);
  if ( a4 == -1 )
    v4 = (int16_t *)(113 * a3 + dword_19306C);
  else
    v4 = sub_77B28(*(_WORD *)(dword_192B18 + 361 * a4 + 2));
  strcpy(v18, (char *)v4);
  if ( (unsigned int)v15 >= 8 )
  {
    switch ( v15 )
    {
      case 8:
        v6 = 511;
        break;
      case 9:
        v6 = 514;
        break;
      case 10:
        v6 = 159;
        break;
      case 11:
        v6 = 160;
        break;
      case 12:
        v6 = 161;
        break;
      case 13:
        v6 = 162;
        break;
      case 14:
        v6 = 163;
        break;
      default:
        v6 = 164;
        break;
    }
    v7 = (char *)sub_CDF5C(v6);
    sprintf(v17, v7);
  }
  else
  {
    v5 = 3753 * v15;
    if ( byte_199CAE == 4 )
    {
      sprintf(v17, "%s", dword_197F98 + v5 + 21);
    }
    else
    {
      v13 = dword_197F98 + v5 + 21;
      v12 = (char *)sub_CDF5C(58);
      sprintf(v17, v12, v13);
    }
  }
  if ( (unsigned int)a2 >= 8 )
  {
    v9 = (char *)sub_CDF5C(165);
    sprintf(v16, v9);
  }
  else
  {
    v14 = 3753 * a2 + dword_197F98 + 21;
    v8 = (char *)sub_CDF5C(70);
    sprintf(v16, v8, v14);
  }
  if ( byte_199CAE == 4 )
  {
    sprintf(v19, "SI COMBATTE NEL SISTEMA %s\n\n  Attaccante: %s\n  Difensore: %s", v18, v17, v16);
  }
  else
  {
    if ( a4 == -1 )
      v11 = (char *)sub_CDF5C(49);
    else
      v11 = (char *)sub_CDF5C(48);
    sprintf(v19, v11, v17, v16, v18);
  }
  sub_CDBC4();
  sub_7743A((int)v19);
  sub_1196F7();
  sub_119281();
  return sub_107BA(&dword_1A11C0);
}
// C9838: variable 'v15' is possibly undefined
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199CAE: using guessed type char byte_199CAE;
// 1A11C0: using guessed type int dword_1A11C0;


//----- (000C99DB) --------------------------------------------------------
_DWORD *sub_C99DB()
{
  _DWORD *result; // eax

  sub_1112EC(dword_192ED4, 52);
  dword_1A114C = (int)sub_126B42((int)aMainpupsLbx, 52, dword_192ED4);
  dword_1A119C = (int)sub_126B42((int)aMainpupsLbx, 74, dword_192ED4);
  dword_1A1198 = (int)sub_126B42((int)aMainpupsLbx, 75, dword_192ED4);
  dword_1A11A0 = (int)sub_126B42((int)aMainpupsLbx, 76, dword_192ED4);
  result = sub_126B42((int)aMainpupsLbx, 77, dword_192ED4);
  dword_1A1124 = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 1A1124: using guessed type int dword_1A1124;
// 1A114C: using guessed type int dword_1A114C;
// 1A1198: using guessed type int dword_1A1198;
// 1A119C: using guessed type int dword_1A119C;
// 1A11A0: using guessed type int dword_1A11A0;


//----- (000C9A6C) --------------------------------------------------------
int sub_C9A6C()
{
  sub_10FE41((int)&unk_1A11F8 + 18 * word_1831C2);
  ++word_1831C2;
  return sub_C9AA4(word_1A1236, word_1A1232, (int)&word_1A1234);
}
// 1831C2: using guessed type int16_t word_1831C2;
// 1A1232: using guessed type int16_t word_1A1232;
// 1A1234: using guessed type int16_t word_1A1234;
// 1A1236: using guessed type int16_t word_1A1236;


//----- (000C9AA4) --------------------------------------------------------
int64_t __fastcall sub_C9AA4( int a1, int a2, int a3)
{
  _BYTE *v4; // eax
  _WORD *v5; // ecx
  int v6; // eax
  _WORD *v7; // ecx
  int v8; // eax
  _WORD *v9; // ecx
  int v10; // eax
  _WORD *v11; // ecx
  int v12; // eax
  _BYTE *v13; // eax
  int64_t result; // rax
  _BYTE *v15; // [esp-8h] [ebp-10h]
  _BYTE *v16; // [esp-8h] [ebp-10h]
  _BYTE *v17; // [esp-8h] [ebp-10h]
  _BYTE *v18; // [esp-8h] [ebp-10h]

  v4 = (_BYTE *)sub_CDF5C(12);
  word_1A11DA = sub_115478(word_1A123A + 37, word_1A123C + 149, a1, a2 + 1, a1, a2, 207, 13, a3, v4, 0);
  v15 = (_BYTE *)sub_CDF5C(137);
  v5 = (_WORD *)dword_1A119C;
  v6 = sub_CDF5C(12);
  word_1A11D8 = (uint16_t)sub_1151B0(word_1A123A + 15, word_1A123C + 154, v6, v5, v15, 40);
  v16 = (_BYTE *)sub_CDF5C(11);
  v7 = (_WORD *)dword_1A1198;
  v8 = sub_CDF5C(12);
  word_1A11D6 = (uint16_t)sub_1151B0(word_1A123A + 256, word_1A123C + 154, v8, v7, v16, 40);
  v17 = (_BYTE *)sub_CDF5C(135);
  v9 = (_WORD *)dword_1A11A0;
  v10 = sub_CDF5C(12);
  word_1A11C8 = (uint16_t)sub_1151B0(word_1A123A + 15, word_1A123C + 174, v10, v9, v17, 40);
  v18 = (_BYTE *)sub_CDF5C(12);
  v11 = (_WORD *)dword_1A1124;
  v12 = sub_CDF5C(12);
  word_1A11CA = (uint16_t)sub_1151B0(word_1A123A + 208, word_1A123C + 174, v12, v11, v18, 40);
  v13 = (_BYTE *)sub_CDF5C(12);
  result = sub_11438B(0, 0, 639, 479, v13, 0);
  word_1A11C4 = result;
  return result;
}
// 1A1124: using guessed type int dword_1A1124;
// 1A1198: using guessed type int dword_1A1198;
// 1A119C: using guessed type int dword_1A119C;
// 1A11A0: using guessed type int dword_1A11A0;
// 1A11C4: using guessed type int16_t word_1A11C4;
// 1A11C8: using guessed type int16_t word_1A11C8;
// 1A11CA: using guessed type int16_t word_1A11CA;
// 1A11D6: using guessed type int16_t word_1A11D6;
// 1A11D8: using guessed type int16_t word_1A11D8;
// 1A11DA: using guessed type int16_t word_1A11DA;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C9C3D) --------------------------------------------------------
void __fastcall sub_C9C3D(int a1, int a2, int a3, int a4)
{
  int v4; // esi
  _DWORD v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[0] = 7565678;
  v5[1] = 0;
  sub_120940(2, (int)v5);
  if ( byte_182ACA || word_19994C )
  {
    sub_C7F84();
    sub_12B7E1(word_1A123A, word_1A123C, (_WORD *)dword_1A114C);
    a4 = 92;
    sub_10323B(dword_1A11B4, 2);
    sub_124DEC();
    byte_182ACA = 0;
  }
  sub_121199((int16_t)(word_1A123A + 32), (int16_t)(word_1A123C + 132), word_1A1236, a4);
  sub_121199((int16_t)(word_1A123A + 145), (int16_t)(word_1A123C + 130), word_1A1234, a4);
  sub_121199((int16_t)(word_1A123A + 257), (int16_t)(word_1A123C + 132), word_1A1232, a4);
  v4 = 207 * (word_1A1234 - word_1A1236) / (word_1A1232 - word_1A1236) + 37;
  sub_134D2D(
    (int16_t)(v4 + word_1A123A),
    (int16_t)(word_1A123C + 153),
    (int16_t)(v4 + word_1A123A),
    (int16_t)(word_1A123C + 164),
    32);
  LOWORD(v4) = v4 + 1;
  sub_134D2D(
    (int16_t)(v4 + word_1A123A),
    (int16_t)(word_1A123C + 153),
    (int16_t)(v4 + word_1A123A),
    (int16_t)(word_1A123C + 164),
    36);
  LOWORD(v4) = v4 + 1;
  sub_134D2D(
    (int16_t)(v4 + word_1A123A),
    (int16_t)(word_1A123C + 153),
    (int16_t)(v4 + word_1A123A),
    (int16_t)(word_1A123C + 164),
    40);
  LOWORD(v4) = v4 + 1;
  sub_134D2D(
    (int16_t)(v4 + word_1A123A),
    (int16_t)(word_1A123C + 153),
    (int16_t)(v4 + word_1A123A),
    (int16_t)(word_1A123C + 164),
    36);
  sub_134D2D(
    (int16_t)(word_1A123A + v4 + 1),
    (int16_t)(word_1A123C + 153),
    (int16_t)(word_1A123A + v4 + 1),
    (int16_t)(word_1A123C + 164),
    32);
  JUMPOUT(0xC7EFD);
}
// C9E59: control flows out of bounds to C7EFD
// 182ACA: using guessed type char byte_182ACA;
// 19994C: using guessed type int16_t word_19994C;
// 1A114C: using guessed type int dword_1A114C;
// 1A11B4: using guessed type int dword_1A11B4;
// 1A1232: using guessed type int16_t word_1A1232;
// 1A1234: using guessed type int16_t word_1A1234;
// 1A1236: using guessed type int16_t word_1A1236;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000C9EB0) --------------------------------------------------------
int16_t __userpurge sub_C9EB0( int a1, int a2,
        int a3, int a4,
        int16_t *a5, int a6)
{
  int16_t *v6; // ebx
  int64_t v7; // rax
  int v9; // [esp+0h] [ebp-8h] BYREF
  int v10; // [esp+4h] [ebp-4h] BYREF

  v10 = 0;
  v9 = 0;
  word_1A1240 = -1;
  word_1A1236 = a1;
  word_1A1232 = a2;
  word_1A1234 = a4;
  dword_1A11B4 = a3;
  sub_C99DB();
  sub_C702E(a6, (int16_t *)dword_1A114C);
  sub_133C9C(dword_1A114C, 1);
  sub_119281();
  v6 = &word_1A1234;
  sub_1191CA((int)sub_C9C3D, 1);
  sub_C6E7E();
  v7 = sub_C9AA4(word_1A1236, word_1A1232, (int)&word_1A1234);
  sub_C9C3D(v7, SHIDWORD(v7), (int)&word_1A1234, a3);
  LODWORD(v7) = sub_1077D(v7, SHIDWORD(v7), (int)&word_1A1234, a5);
  do
  {
    v7 = __PAIR64__(&v10, sub_1171AB(v7, SHIDWORD(v7), (int)v6, a3));
    v10 = v7;
    LODWORD(v7) = sub_114177();
    sub_C9C3D(v7, (int)&v10, (int)v6, a3);
    sub_1077D(v7, (int)&v10, (int)v6, a5);
    WORD1(v7) = HIWORD(v10);
    v6 = (int16_t *)&v9;
    if ( (_WORD)v10 == word_1A11CA )
      v9 = 1;
    if ( (_WORD)v10 == word_1A11C8 )
    {
      LOWORD(v9) = 1;
      word_1A1234 = -1;
    }
    if ( (_WORD)v10 == word_1A11D6 )
      ++word_1A1234;
    LOWORD(v7) = v10;
    if ( (_WORD)v10 == word_1A11D8 )
      --word_1A1234;
  }
  while ( !(_WORD)v9 );
  sub_C7283(v7, (int)&v10);
  return word_1A1234;
}
// C9F39: variable 'v7' is possibly undefined
// 1A114C: using guessed type int dword_1A114C;
// 1A11B4: using guessed type int dword_1A11B4;
// 1A11C8: using guessed type int16_t word_1A11C8;
// 1A11CA: using guessed type int16_t word_1A11CA;
// 1A11D6: using guessed type int16_t word_1A11D6;
// 1A11D8: using guessed type int16_t word_1A11D8;
// 1A1232: using guessed type int16_t word_1A1232;
// 1A1234: using guessed type int16_t word_1A1234;
// 1A1236: using guessed type int16_t word_1A1236;
// 1A1240: using guessed type int16_t word_1A1240;


//----- (000C9FC4) --------------------------------------------------------
void __fastcall sub_C9FC4( int a1)
{
  int v2; // ecx
  char *v3; // eax
  _BYTE *v4; // ebx
  char *v5; // eax
  int v6; // eax
  char *v7; // eax
  _BYTE *v8; // ebx
  char *v9; // eax
  _BYTE *v10; // ebx
  char *v11; // eax
  _BYTE *v12; // ebx
  char *v13; // eax
  _BYTE *v14; // ebx
  char *v15; // eax
  _BYTE *v16; // ebx
  int16_t v17; // ax
  char *v18; // eax
  int v19; // [esp-8h] [ebp-7E8h]
  int16_t *v20; // [esp-4h] [ebp-7E4h]
  int v21; // [esp-4h] [ebp-7E4h]
  int v22; // [esp-4h] [ebp-7E4h]
  int v23; // [esp-4h] [ebp-7E4h]
  int v24; // [esp-4h] [ebp-7E4h]
  int v25; // [esp-4h] [ebp-7E4h]
  int v26; // [esp-4h] [ebp-7E4h]
  int v27; // [esp-4h] [ebp-7E4h]
  _BYTE v28[2000]; // [esp+0h] [ebp-7E0h] BYREF
  _WORD v29[4]; // [esp+7D0h] [ebp-10h] BYREF
  int16_t v30; // [esp+7D8h] [ebp-8h]
  int16_t v31; // [esp+7DAh] [ebp-6h]
  int16_t v32; // [esp+7DCh] [ebp-4h]

  v2 = a1;
  sub_CDBD9();
  sub_E5430((_BYTE *)(dword_197F98 + 3753 * word_19999C), (_BYTE *)(17 * v2 + dword_1930D4), v29);
  v20 = sub_77B28(v2);
  v3 = (char *)sub_CDF5C(209);
  v4 = &v28[sprintf(v28, v3, v20)];
  if ( v30 % 2 )
  {
    v22 = v30 % 2;
    v19 = v30 / 2;
    v7 = (char *)sub_CDF5C(100);
    v6 = sprintf(v4, v7, &unk_179E6E, &unk_179E6B, v19, v22);
  }
  else
  {
    v21 = v30 / 2;
    v5 = (char *)sub_CDF5C(101);
    v6 = sprintf(v4, v5, &unk_179E6E, &unk_179E6B, v21);
  }
  v8 = &v4[v6];
  v23 = v31;
  v9 = (char *)sub_CDF5C(107);
  v10 = &v8[sprintf(v8, v9, &unk_179E6E, &unk_179E6B, v23)];
  v24 = v32;
  v11 = (char *)sub_CDF5C(115);
  v12 = &v10[sprintf(v10, v11, &unk_179E6E, &unk_179E6B, v24)];
  v25 = v29[1];
  v13 = (char *)sub_CDF5C(108);
  v14 = &v12[sprintf(v12, v13, &unk_179E6E, &unk_179E6B, v25)];
  v26 = v29[3];
  v15 = (char *)sub_CDF5C(120);
  v16 = &v14[sprintf(v14, v15, &unk_179E6E, &unk_179E6B, v26)];
  sub_E0B4F((int16_t *)(17 * a1 + dword_1930D4), word_19999C);
  v27 = v17;
  v18 = (char *)sub_CDF5C(110);
  sprintf(v16, v18, &unk_179E6E, &unk_179E6B, v27);
  sub_77658((int)v28);
  sub_1196F7();
  JUMPOUT(0xC7EFD);
}
// CA168: control flows out of bounds to C7EFD
// CA135: variable 'v17' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;


//----- (000CA16D) --------------------------------------------------------
void __fastcall sub_CA16D( int a1, int a2)
{
  int v2; // edi
  int v4; // ecx
  char *v5; // eax
  int v6; // ebx
  char *v7; // eax
  int v8; // ebx
  char *v9; // eax
  int v10; // ebx
  char *v11; // eax
  int v12; // ebx
  char *v13; // eax
  int v14; // eax
  char *v15; // eax
  int v16; // ebx
  char *v17; // eax
  int v18; // ebx
  char *v19; // eax
  int v20; // ebx
  char *v21; // eax
  int v22; // ebx
  char *v23; // eax
  int v24; // ebx
  int16_t v25; // ax
  char *v26; // eax
  int v27; // eax
  char *v28; // eax
  int v29; // edi
  char *v30; // eax
  int v31; // edx
  int v32; // eax
  char *v33; // eax
  int v34; // ebx
  char *v35; // eax
  int v36; // ebx
  char *v37; // eax
  int v38; // ebx
  char *v39; // eax
  int v40; // ebx
  char *v41; // eax
  int v42; // ebx
  char *v43; // eax
  int v44; // ebx
  char *v45; // eax
  char *v46; // eax
  int v47; // ecx
  int16_t v48; // ax
  char *v49; // eax
  int v50; // ebx
  int v51; // edx
  char *v52; // eax
  int v53; // [esp-8h] [ebp-28h]
  int v54; // [esp-8h] [ebp-28h]
  int16_t *v55; // [esp-8h] [ebp-28h]
  int v56; // [esp-8h] [ebp-28h]
  int v57; // [esp-8h] [ebp-28h]
  int16_t *v58; // [esp-4h] [ebp-24h]
  int v59; // [esp-4h] [ebp-24h]
  int v60; // [esp-4h] [ebp-24h]
  int v61; // [esp-4h] [ebp-24h]
  int v62; // [esp-4h] [ebp-24h]
  int v63; // [esp-4h] [ebp-24h]
  int v64; // [esp-4h] [ebp-24h]
  int v65; // [esp-4h] [ebp-24h]
  int v66; // [esp-4h] [ebp-24h]
  int v67; // [esp-4h] [ebp-24h]
  int v68; // [esp-4h] [ebp-24h]
  int16_t *v69; // [esp-4h] [ebp-24h]
  int v70; // [esp-4h] [ebp-24h]
  int v71; // [esp-4h] [ebp-24h]
  int v72; // [esp-4h] [ebp-24h]
  int v73; // [esp-4h] [ebp-24h]
  int v74; // [esp-4h] [ebp-24h]
  int v75; // [esp-4h] [ebp-24h]
  int v76; // [esp-4h] [ebp-24h]
  int v77; // [esp-4h] [ebp-24h]
  int v78; // [esp-4h] [ebp-24h]
  int v79; // [esp-4h] [ebp-24h]
  int16_t v80; // [esp+0h] [ebp-20h]
  _WORD v81[4]; // [esp+4h] [ebp-1Ch] BYREF
  int16_t v82; // [esp+Ch] [ebp-14h]
  int16_t v83; // [esp+Eh] [ebp-12h]
  int16_t v84; // [esp+10h] [ebp-10h]
  _BYTE *v85; // [esp+14h] [ebp-Ch]
  int v86; // [esp+18h] [ebp-8h]
  int v87; // [esp+1Ch] [ebp-4h]

  v2 = a2;
  v4 = 17 * a1;
  LOWORD(a2) = *(_WORD *)(v4 + dword_1930D4);
  v87 = a2;
  if ( (int16_t)a2 == -1 )
  {
    if ( *(_BYTE *)(v4 + dword_1930D4 + 4) != 3 )
    {
      v69 = sub_77B28(a1);
      v28 = (char *)sub_CDF5C(86);
      v29 = sprintf(v2, v28, v69) + v2;
      v30 = (char *)sub_CDF5C(307);
      sprintf(v29, v30);
      goto LABEL_13;
    }
    v85 = (_BYTE *)(3753 * word_19999C + dword_197F98);
    sub_E5430(v85, (_BYTE *)(v4 + dword_1930D4), v81);
    v58 = sub_77B28(a1);
    v5 = (char *)sub_CDF5C(82);
    v6 = v2 + sprintf(v2, v5, &unk_179E6E, v58);
    v59 = dword_18F990[*(uint8_t *)(v4 + dword_1930D4 + 8)];
    v53 = dword_192BE0[*(uint8_t *)(v4 + dword_1930D4 + 5)];
    v7 = (char *)sub_CDF5C(77);
    v8 = sprintf(v6, v7, &unk_179E6E, v53, v59) + v6;
    v60 = dword_192BF4[*(uint8_t *)(v4 + dword_1930D4 + 10)];
    v9 = (char *)sub_CDF5C(111);
    v10 = sprintf(v8, v9, &unk_179E6E, v60) + v8;
    v61 = dword_192C74[*(uint8_t *)(v4 + dword_1930D4 + 6)];
    v11 = (char *)sub_CDF5C(83);
    v12 = sprintf(v10, v11, &unk_179E6E, v61) + v10;
    if ( v82 % 2 )
    {
      v63 = v82 % 2;
      v54 = v82 / 2;
      v15 = (char *)sub_CDF5C(100);
      v14 = sprintf(v12, v15, &unk_179E6E, &unk_179E6B, v54, v63);
    }
    else
    {
      v62 = v82 / 2;
      v13 = (char *)sub_CDF5C(101);
      v14 = sprintf(v12, v13, &unk_179E6E, &unk_179E6B, v62);
    }
    v16 = v14 + v12;
    v64 = v83;
    v17 = (char *)sub_CDF5C(107);
    v18 = sprintf(v16, v17, &unk_179E6E, &unk_179E6B, v64) + v16;
    v65 = v84;
    v19 = (char *)sub_CDF5C(116);
    v20 = sprintf(v18, v19, &unk_179E6E, &unk_179E6B, v65) + v18;
    v66 = v81[1];
    v21 = (char *)sub_CDF5C(108);
    v22 = sprintf(v20, v21, &unk_179E6E, &unk_179E6B, v66) + v20;
    v67 = v81[3];
    v23 = (char *)sub_CDF5C(121);
    v24 = sprintf(v22, v23, &unk_179E6E, &unk_179E6B, v67) + v22;
    sub_E0B4F((int16_t *)(17 * v80 + dword_1930D4), word_19999C);
    v68 = v25;
    v26 = (char *)sub_CDF5C(109);
    v27 = sprintf(v24, v26, &unk_179E6E, &unk_179E6B, v68);
  }
  else
  {
    v31 = 361 * (int16_t)a2;
    v32 = 3753 * *(char *)(v31 + dword_192B18);
    v86 = v31;
    v70 = dword_197F98 + v32 + 21;
    v55 = sub_77B28(a1);
    v33 = (char *)sub_CDF5C(73);
    v34 = v2 + sprintf(v2, v33, &unk_179E6E, v55, v70);
    v71 = dword_18F990[*(uint8_t *)(v86 + dword_192B18 + 226)];
    v56 = dword_192BE0[*(uint8_t *)(v4 + dword_1930D4 + 5)];
    v35 = (char *)sub_CDF5C(77);
    v36 = sprintf(v34, v35, &unk_179E6E, v56, v71) + v34;
    v72 = dword_192BF4[*(uint8_t *)(v4 + dword_1930D4 + 10)];
    v37 = (char *)sub_CDF5C(111);
    v38 = sprintf(v36, v37, &unk_179E6E, v72) + v36;
    v73 = dword_192C74[*(uint8_t *)(v4 + dword_1930D4 + 6)];
    v39 = (char *)sub_CDF5C(83);
    v40 = sprintf(v38, v39, &unk_179E6E, v73) + v38;
    v74 = *(uint8_t *)(v86 + dword_192B18 + 221) / 2;
    v41 = (char *)sub_CDF5C(94);
    v42 = sprintf(v40, v41, &unk_179E6E, &unk_179E6B, v74) + v40;
    v75 = *(uint8_t *)(v86 + dword_192B18 + 222);
    v43 = (char *)sub_CDF5C(95);
    v44 = sprintf(v42, v43, &unk_179E6E, &unk_179E6B, v75) + v42;
    v76 = *(uint8_t *)(v86 + dword_192B18 + 223);
    v45 = (char *)sub_CDF5C(96);
    v24 = sprintf(v44, v45, &unk_179E6E, &unk_179E6B, v76) + v44;
    if ( *(char *)(dword_192B18 + v86) == word_19999C )
    {
      v77 = 5 * *(char *)(dword_192B18 + 361 * *(int16_t *)(v4 + dword_1930D4) + 7);
      v46 = (char *)sub_CDF5C(112);
      v24 += sprintf(v24, v46, &unk_179E6E, &unk_179E6B, v77);
    }
    v47 = 361 * (int16_t)v87;
    sub_E0B4F((int16_t *)(dword_1930D4 + 17 * v80), *(char *)(v47 + dword_192B18));
    v78 = v48;
    v57 = *(uint8_t *)(v47 + dword_192B18 + 10);
    v49 = (char *)sub_CDF5C(113);
    v27 = sprintf(v24, v49, &unk_179E6E, &unk_179E6B, v57, v78);
  }
  v50 = v27 + v24;
  v51 = 17 * v80;
  if ( *(_BYTE *)(v51 + dword_1930D4 + 15) )
  {
    v79 = dword_18F9B8[*(char *)(v51 + dword_1930D4 + 15)];
    v52 = (char *)sub_CDF5C(80);
    sprintf(v50, v52, &unk_179E6E, v79);
  }
LABEL_13:
  JUMPOUT(0xC97B9);
}
// CA3DD: control flows out of bounds to C97B9
// CA369: variable 'v80' is possibly undefined
// CA387: variable 'v25' is possibly undefined
// CA5D1: variable 'v48' is possibly undefined
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


//----- (000CA63E) --------------------------------------------------------
int __fastcall sub_CA63E( int a1)
{
  int v2; // ebx
  int result; // eax

  v2 = 361 * a1;
  result = -1;
  if ( *(_BYTE *)(dword_192B18 + v2 + 338) )
    result = 28;
  if ( *(_BYTE *)(dword_192B18 + 361 * a1 + 334) )
    result = 24;
  if ( *(_BYTE *)(361 * a1 + dword_192B18 + 333) )
    return 23;
  return result;
}
// 192B18: using guessed type int dword_192B18;


//----- (000CA6A6) --------------------------------------------------------
void __fastcall sub_CA6A6(_BYTE *a1, _BYTE *a2, int *a3, int a4, int a5, int a6)
{
  int (**v7)(void); // eax
  _BYTE v8[48]; // [esp+0h] [ebp-30h] BYREF

  dword_1A11AC = (int)v8;
  sub_107AF(&dword_1A11B0);
  v7 = sub_107C2(&dword_1A11B0);
  sub_1077D(v7);
  sub_CA6FB((int16_t *)dword_1A11AC, a1, a2, (int)a3, a4, a5, a6);
  sub_CBAD0((int)v8, 0, (int)a2, a3);
}
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 1A11AC: using guessed type int dword_1A11AC;
// 1A11B0: using guessed type int (*dword_1A11B0)(void);


//----- (000CA6FB) --------------------------------------------------------
int __fastcall sub_CA6FB(int16_t *a1, _BYTE *a2, _BYTE *a3, int a4, int a5, int a6, int a7)
{
  int v8; // eax
  int result; // eax
  int v10; // [esp+0h] [ebp-4h]

  *(_DWORD *)((char *)a1 + 31) = a2;
  *(_DWORD *)((char *)a1 + 35) = a3;
  *(_DWORD *)((char *)a1 + 39) = a4;
  *(int16_t *)((char *)a1 + 43) = a6;
  *a1 = a5;
  *((_BYTE *)a1 + 11) = a7;
  *((_BYTE *)a1 + 2) = *a2;
  v10 = 0;
  *((_BYTE *)a1 + 12) = *a3;
  do
  {
    v8 = (int16_t)v10;
    *(int16_t *)((char *)&a1[v8 + 1] + 1) = *(_WORD *)&a2[v8 * 2 + 10];
    ++v10;
    *(int16_t *)((char *)&a1[v8 + 6] + 1) = *(_WORD *)&a3[v8 * 2 + 10];
  }
  while ( (int16_t)v10 < 4 );
  *(int16_t *)((char *)a1 + 21) = *(uint8_t *)(dword_192B18 + 361 * *a1 + 10);
  *(int16_t *)((char *)a1 + 23) = sub_BA96D(a5);
  result = sub_CA63E(a5);
  *(int16_t *)((char *)a1 + 25) = result;
  return result;
}
// 192B18: using guessed type int dword_192B18;


//----- (000CA78F) --------------------------------------------------------
void __fastcall sub_CA78F(_BYTE *a1, _BYTE *a2, int a3, int a4, int a5, int a6)
{
  int16_t v6[24]; // [esp+0h] [ebp-30h] BYREF

  dword_1A11AC = (int)v6;
  sub_CA6FB(v6, a1, a2, a3, a4, a5, a6);
  byte_1831C4 = 0;
  JUMPOUT(0xCA6F1);
}
// CA7CA: control flows out of bounds to CA6F1
// 1831C4: using guessed type char byte_1831C4;
// 1A11AC: using guessed type int dword_1A11AC;


//----- (000CA7CF) --------------------------------------------------------
int16_t __fastcall sub_CA7CF(int a1, int a2, _BYTE *a3, _BYTE *a4, int a5, int a6, int a7, int a8)
{
  int v9; // eax
  int16_t result; // ax

  *(_DWORD *)(a1 + 27) = a2;
  sub_CA6FB((int16_t *)dword_1A11AC, a3, a4, a5, a6, a7, a8);
  v9 = dword_1A11AC;
  *(_WORD *)(a1 + 15) -= *(_WORD *)(*(_DWORD *)(dword_1A11AC + 27) + 8);
  result = *(_WORD *)(*(_DWORD *)(v9 + 27) + 10);
  *(_WORD *)(a1 + 13) -= result;
  return result;
}
// 1A11AC: using guessed type int dword_1A11AC;


//----- (000CA85C) --------------------------------------------------------
int __fastcall sub_CA85C(int a1, _WORD *a2, int16_t *a3, int16_t *a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // ebx
  int v13; // ecx
  int16_t v14; // ax
  int v15; // eax
  int v16; // ebx
  int v17; // edx
  int v18; // esi
  int v19; // edx
  int16_t v20; // ax
  int v21; // esi
  int16_t v22; // ax
  int v23; // eax
  int v26; // [esp+8h] [ebp-20h]
  int16_t v27; // [esp+Ch] [ebp-1Ch]
  int16_t v28; // [esp+Ch] [ebp-1Ch]
  char *v29; // [esp+10h] [ebp-18h]
  int16_t v31; // [esp+1Ch] [ebp-Ch]
  char v32; // [esp+24h] [ebp-4h]

  v29 = (char *)(361 * *(uint8_t *)(a1 + 1) + dword_192B18);
  result = *a2 != 1 && *a2 != 3;
  if ( result )
  {
    result = word_1828CC / 5;
    if ( !(word_1828CC % 5) )
    {
      do
      {
        if ( *a3 + *a4 <= 0 )
        {
          if ( *a2 == 2 )
          {
            *a4 = 0;
            *(_WORD *)(dword_1A11AC + 43) = 0;
          }
          *a2 = 3;
        }
        else
        {
          if ( *a4 )
          {
            sub_DD13E(v29, (char *)a1);
            v15 = dword_1A11AC;
            --*a4;
            v16 = dword_1A1120;
            --*(_WORD *)(v15 + 43);
            v17 = (*(int16_t *)(v16 + 2) + 2 * word_1A123C - 30) / 2;
            v18 = dword_1A117C;
            v28 = v17 + sub_1247A0(0x28u) - 20;
            v19 = (2 * word_1A123A + *(int16_t *)dword_1A1120 - 30) / 2;
            v20 = sub_1247A0(0x28u);
            sub_C6CAE((int16_t)(v19 + v20 - 20), v28, v18, 1, 0);
            sub_147D7(32);
          }
          else
          {
            v6 = sub_DCEBD(v29, (char *)a1, *a3);
            v7 = v6;
            if ( v6 )
            {
              v8 = *a3;
              if ( v6 == v8 )
              {
                v9 = dword_1A11AC;
                *a3 = 0;
                v7 = 1;
                *(_WORD *)(v9 + 43) -= v8;
              }
              else
              {
                *a3 -= v6;
                *(_WORD *)(dword_1A11AC + 43) -= v6;
              }
              if ( v7 >= 5 )
                v7 = 5;
              while ( 1 )
              {
                v10 = v7--;
                if ( v10 <= 0 )
                  break;
                v26 = dword_1A1178;
                v11 = (*(int16_t *)(dword_1A1120 + 2) + 2 * word_1A123C - 30) / 2;
                v12 = *(int16_t *)dword_19285C / 2 - *(int16_t *)dword_1A1178;
                v27 = sub_1247A0(2 * abs32(v12)) + v11 - abs32(v12);
                v13 = (2 * word_1A123A + *(int16_t *)dword_1A1120 - 30) / 2;
                v14 = sub_1247A0(2 * abs32(v12));
                sub_C6CAE((int16_t)(v14 + v13 - abs32(v12)), v27, v26, 1, 0);
                sub_147D7(24);
              }
            }
            else
            {
              *a3 = 0;
            }
          }
          v21 = dword_1A11AC;
          v31 = *(_WORD *)dword_1A11AC;
          v22 = *(_WORD *)(dword_1A11AC + 43);
          v32 = *(_BYTE *)(dword_1A11AC + 11);
          *(_DWORD *)(dword_1A11AC + 27) = *(_DWORD *)(dword_1A11AC + 27);
          sub_CA6FB((int16_t *)v21, *(_BYTE **)(v21 + 31), *(_BYTE **)(v21 + 35), *(_DWORD *)(v21 + 39), v31, v22, v32);
          v23 = dword_1A11AC;
          *(_WORD *)(v21 + 15) -= *(_WORD *)(*(_DWORD *)(dword_1A11AC + 27) + 8);
          LOWORD(v23) = *(_WORD *)(*(_DWORD *)(v23 + 27) + 10);
          byte_182ACA = 1;
          *(_WORD *)(v21 + 13) -= v23;
        }
        result = (int)a2;
      }
      while ( *a2 == 2 );
    }
  }
  return result;
}
// 1828CC: using guessed type int16_t word_1828CC;
// 182ACA: using guessed type char byte_182ACA;
// 19285C: using guessed type int dword_19285C;
// 192B18: using guessed type int dword_192B18;
// 1A1120: using guessed type int dword_1A1120;
// 1A1178: using guessed type int dword_1A1178;
// 1A117C: using guessed type int dword_1A117C;
// 1A11AC: using guessed type int dword_1A11AC;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000CAB21) --------------------------------------------------------
void __fastcall sub_CAB21(int a1, _BYTE *a2, _BYTE *a3, int *a4, int a5, int a6, int a7)
{
  int16_t v7[6]; // [esp+0h] [ebp-30h] BYREF
  int16_t v8; // [esp+Dh] [ebp-23h]
  int16_t v9; // [esp+Fh] [ebp-21h]
  int v10; // [esp+1Bh] [ebp-15h]

  dword_1A11AC = (int)v7;
  v10 = a1;
  sub_CA6FB(v7, a2, a3, (int)a4, a5, a6, a7);
  v9 -= *(_WORD *)(*(_DWORD *)(dword_1A11AC + 27) + 8);
  v8 -= *(_WORD *)(*(_DWORD *)(dword_1A11AC + 27) + 10);
  byte_1831C4 = 0;
  sub_CBAD0((int)v7, 1, (int)a3, a4);
}
// 1831C4: using guessed type char byte_1831C4;
// 1A11AC: using guessed type int dword_1A11AC;


//----- (000CAB7F) --------------------------------------------------------
char __fastcall sub_CAB7F( int a1)
{
  int v1; // ecx
  int v2; // edx
  int v3; // ebx
  int v4; // eax
  int v5; // edx
  int v6; // ebx
  int v7; // eax

  v1 = 17 * *(int16_t *)(361 * a1 + dword_192B18 + 2);
  v2 = (int16_t)(6 * *(uint8_t *)(v1 + dword_1930D4 + 8) + *(uint8_t *)(v1 + dword_1930D4 + 5));
  v3 = dword_192ED4;
  v4 = sub_CDF5C(223);
  dword_19285C = (int)sub_126B42(v4, v2, v3);
  v5 = (int16_t)(6 * (*(uint8_t *)(v1 + dword_1930D4 + 8) + 1) - 1);
  v6 = dword_192ED4;
  v7 = sub_CDF5C(223);
  dword_19288C = (int)sub_126B42(v7, v5, v6);
  sub_12B79D(dword_19288C);
  sub_131F7B();
  sub_1318D4(0, 255);
  return sub_133237();
}
// 19285C: using guessed type int dword_19285C;
// 19288C: using guessed type int dword_19288C;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 1930D4: using guessed type int dword_1930D4;


//----- (000CAC18) --------------------------------------------------------
char sub_CAC18()
{
  sub_1112EC(dword_192ED4, 53);
  dword_1A1158 = (int)sub_126B42((int)aMainpupsLbx, 53, dword_192ED4);
  dword_1A1150 = (int)sub_126B42((int)aMainpupsLbx, 54, dword_192ED4);
  dword_1A1154 = (int)sub_126B42((int)aMainpupsLbx, 55, dword_192ED4);
  dword_1A115C = (int)sub_126B42((int)aMainpupsLbx, 60, dword_192ED4);
  dword_1A1120 = (int)sub_126B42((int)aMainpupsLbx, 78, dword_192ED4);
  dword_1A1160 = (int)sub_126B42((int)aMainpupsLbx, 79, dword_192ED4);
  dword_1A1164 = (int)sub_126B42((int)aMainpupsLbx, 80, dword_192ED4);
  dword_1A1168 = (int)sub_126B42((int)aMainpupsLbx, 81, dword_192ED4);
  dword_1A1138 = (int)sub_126B42((int)aMainpupsLbx, 82, dword_192ED4);
  dword_1A116C = (int)sub_126B42((int)aColony2Lbx, 46, dword_192ED4);
  dword_1A1170 = (int)sub_126B42((int)aColony2Lbx, 47, dword_192ED4);
  dword_1A1174 = (int)sub_126B42((int)aColony2Lbx, 48, dword_192ED4);
  dword_1A1178 = (int)sub_126B42((int)aMainpupsLbx, 61, dword_192ED4);
  dword_1A117C = (int)sub_126B42((int)aMainpupsLbx, 73, dword_192ED4);
  return sub_CAB7F(*(_WORD *)dword_1A11AC);
}
// 192ED4: using guessed type int dword_192ED4;
// 1A1120: using guessed type int dword_1A1120;
// 1A1138: using guessed type int dword_1A1138;
// 1A1150: using guessed type int dword_1A1150;
// 1A1154: using guessed type int dword_1A1154;
// 1A1158: using guessed type int dword_1A1158;
// 1A115C: using guessed type int dword_1A115C;
// 1A1160: using guessed type int dword_1A1160;
// 1A1164: using guessed type int dword_1A1164;
// 1A1168: using guessed type int dword_1A1168;
// 1A116C: using guessed type int dword_1A116C;
// 1A1170: using guessed type int dword_1A1170;
// 1A1174: using guessed type int dword_1A1174;
// 1A1178: using guessed type int dword_1A1178;
// 1A117C: using guessed type int dword_1A117C;
// 1A11AC: using guessed type int dword_1A11AC;


//----- (000CADA0) --------------------------------------------------------
void __fastcall sub_CADA0( int a1, _WORD *a2)
{
  sub_10FE41((int)&unk_1A11F8 + 18 * word_1831C2);
  ++word_1831C2;
  sub_CADC8(a1, a2);
}
// 1831C2: using guessed type int16_t word_1831C2;


//----- (000CADC8) --------------------------------------------------------
void __fastcall sub_CADC8( int a1, _WORD *a2)
{
  _WORD *v3; // ecx
  int v4; // eax
  int16_t v5; // di
  _WORD *v6; // ecx
  int v7; // eax
  _WORD *v8; // ecx
  int v9; // eax
  int16_t v10; // dx
  _WORD *v11; // ecx
  int v12; // eax
  int16_t v13; // dx
  int16_t v14; // dx
  _WORD *v15; // ecx
  int v16; // eax
  _WORD *v17; // ecx
  int v18; // eax
  int16_t v19; // dx
  int v20; // eax
  _WORD *v21; // ecx
  int v22; // eax
  int16_t v23; // dx
  _WORD *v24; // ecx
  int v25; // eax
  _BYTE *v26; // eax
  _BYTE *v27; // [esp-8h] [ebp-Ch]
  _BYTE *v28; // [esp-8h] [ebp-Ch]
  _BYTE *v29; // [esp-8h] [ebp-Ch]
  _BYTE *v30; // [esp-8h] [ebp-Ch]
  _BYTE *v31; // [esp-8h] [ebp-Ch]
  _BYTE *v32; // [esp-8h] [ebp-Ch]
  _BYTE *v33; // [esp-8h] [ebp-Ch]
  _BYTE *v34; // [esp-8h] [ebp-Ch]

  v27 = (_BYTE *)sub_CDF5C(135);
  v3 = (_WORD *)dword_1A1138;
  v4 = sub_CDF5C(12);
  v5 = 1;
  word_1A11D0 = (uint16_t)sub_1151B0(
                                    word_1A123A + 221,
                                    *(_WORD *)(dword_1A1120 + 2) + word_1A123C - 39,
                                    v4,
                                    v3,
                                    v27,
                                    40);
  if ( a1 == 1 )
  {
    if ( *(int16_t *)(dword_1A11AC + 43) < 0 || !*a2 || *a2 == 3 || *(int16_t *)(dword_1A11AC + 21) <= 0 || *a2 == 2 )
    {
      word_1A11E8 = -1000;
    }
    else
    {
      v28 = (_BYTE *)sub_CDF5C(193);
      v6 = (_WORD *)dword_1A1154;
      v7 = sub_CDF5C(12);
      v5 = 2;
      word_1A11E8 = (uint16_t)sub_1151B0(
                                        word_1A123A + 221,
                                        *(_WORD *)(dword_1A1120 + 2) + word_1A123C - 64,
                                        v7,
                                        v6,
                                        v28,
                                        40);
    }
    if ( *(int16_t *)(dword_1A11AC + 43) <= 0
      || *a2 == 1
      || *a2 == 3
      || *(int16_t *)(dword_1A11AC + 21) <= 0
      || *a2 == 2 )
    {
      word_1A11E6 = -1000;
    }
    else
    {
      v29 = (_BYTE *)sub_CDF5C(316);
      v8 = (_WORD *)dword_1A115C;
      v9 = sub_CDF5C(12);
      v10 = *(_WORD *)(dword_1A1120 + 2) + word_1A123C - 39 - 25 * v5++;
      word_1A11E6 = (uint16_t)sub_1151B0(word_1A123A + 221, v10, v9, v8, v29, 40);
    }
    if ( *(int16_t *)(dword_1A11AC + 43) <= 0 || *a2 == 2 || *a2 == 3 || *(int16_t *)(dword_1A11AC + 21) <= 0 )
    {
      word_1A11E4 = -1000;
    }
    else
    {
      v30 = (_BYTE *)sub_CDF5C(166);
      v11 = (_WORD *)dword_1A1160;
      v12 = sub_CDF5C(12);
      v13 = *(_WORD *)(dword_1A1120 + 2) + word_1A123C - 39 - 25 * v5++;
      word_1A11E4 = (uint16_t)sub_1151B0(word_1A123A + 221, v13, v12, v11, v30, 40);
    }
  }
  if ( *(int16_t *)(dword_1A11AC + 43) < 0 || a1 == 1 || a1 == 2 || *(int16_t *)(dword_1A11AC + 21) <= 0 )
  {
    if ( word_1A11DE != -1000 )
    {
      sub_119441();
      sub_117174(3);
    }
    word_1A11DE = -1000;
  }
  else
  {
    v14 = 25 * v5;
    v31 = (_BYTE *)sub_CDF5C(193);
    v15 = (_WORD *)dword_1A1154;
    v16 = sub_CDF5C(12);
    ++v5;
    word_1A11DE = (uint16_t)sub_1151B0(
                                      word_1A123A + 221,
                                      *(_WORD *)(dword_1A1120 + 2) + word_1A123C - 39 - v14,
                                      v16,
                                      v15,
                                      v31,
                                      40);
  }
  if ( *(int16_t *)(dword_1A11AC + 5) <= 0
    || *(int16_t *)(dword_1A11AC + 21) <= 0
    || a1 == 2
    || *(int16_t *)(dword_1A11AC + 21) <= 0 )
  {
    word_1A11DC = -1000;
  }
  else
  {
    v32 = (_BYTE *)sub_CDF5C(327);
    v17 = (_WORD *)dword_1A1150;
    v18 = sub_CDF5C(12);
    v19 = *(_WORD *)(dword_1A1120 + 2) + word_1A123C - 39 - 25 * v5++;
    word_1A11DC = (uint16_t)sub_1151B0(word_1A123A + 221, v19, v18, v17, v32, 40);
  }
  v20 = *(char *)(dword_1A11AC + 2);
  if ( !*(_BYTE *)(dword_197F98 + 3753 * v20 + 2232) || a1 == 2 || *(int16_t *)(dword_1A11AC + 21) <= 0 )
  {
    word_1A11E2 = -1000;
  }
  else
  {
    if ( sub_C622A(v20, *(_WORD *)dword_1A11AC) )
      v21 = (_WORD *)dword_1A1164;
    else
      v21 = (_WORD *)dword_1A1168;
    v33 = (_BYTE *)sub_CDF5C(365);
    v22 = sub_CDF5C(12);
    v23 = *(_WORD *)(dword_1A1120 + 2) + word_1A123C - 39 - 25 * v5++;
    word_1A11E2 = (uint16_t)sub_1151B0(word_1A123A + 221, v23, v22, v21, v33, 40);
  }
  if ( !*(_BYTE *)(dword_1A11AC + 11) || a1 == 2 || *(int16_t *)(dword_1A11AC + 21) <= 0 )
  {
    word_1A11E0 = -1000;
  }
  else
  {
    v34 = (_BYTE *)sub_CDF5C(251);
    v24 = (_WORD *)dword_1A1158;
    v25 = sub_CDF5C(12);
    word_1A11E0 = (uint16_t)sub_1151B0(
                                      word_1A123A + 221,
                                      *(_WORD *)(dword_1A1120 + 2) + word_1A123C - 39 - 25 * v5,
                                      v25,
                                      v24,
                                      v34,
                                      40);
  }
  v26 = (_BYTE *)sub_CDF5C(12);
  word_1A11C4 = sub_11438B(0, 0, 639, 479, v26, 0);
  JUMPOUT(0xC97B9);
}
// CB237: control flows out of bounds to C97B9
// 197F98: using guessed type int dword_197F98;
// 1A1120: using guessed type int dword_1A1120;
// 1A1138: using guessed type int dword_1A1138;
// 1A1150: using guessed type int dword_1A1150;
// 1A1154: using guessed type int dword_1A1154;
// 1A1158: using guessed type int dword_1A1158;
// 1A115C: using guessed type int dword_1A115C;
// 1A1160: using guessed type int dword_1A1160;
// 1A1164: using guessed type int dword_1A1164;
// 1A1168: using guessed type int dword_1A1168;
// 1A11AC: using guessed type int dword_1A11AC;
// 1A11C4: using guessed type int16_t word_1A11C4;
// 1A11D0: using guessed type int16_t word_1A11D0;
// 1A11DC: using guessed type int16_t word_1A11DC;
// 1A11DE: using guessed type int16_t word_1A11DE;
// 1A11E0: using guessed type int16_t word_1A11E0;
// 1A11E2: using guessed type int16_t word_1A11E2;
// 1A11E4: using guessed type int16_t word_1A11E4;
// 1A11E6: using guessed type int16_t word_1A11E6;
// 1A11E8: using guessed type int16_t word_1A11E8;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000CB23C) --------------------------------------------------------
void sub_CB23C()
{
  int v0; // eax
  int16_t v1; // ax
  char *v2; // eax
  int v3; // ecx
  char *v4; // eax
  int16_t v5; // si
  char *v6; // eax
  int16_t v7; // di
  _WORD *v8; // eax
  char *v9; // eax
  int16_t v10; // di
  _WORD *v11; // eax
  int16_t v12; // dx
  int16_t v13; // cx
  _WORD *v14; // eax
  char *v15; // eax
  int16_t v16; // ax
  char *v17; // eax
  char *v18; // [esp-Ch] [ebp-214h]
  int v19; // [esp-8h] [ebp-210h]
  int v20; // [esp-8h] [ebp-210h]
  int v21; // [esp-8h] [ebp-210h]
  int16_t *v22; // [esp-4h] [ebp-20Ch]
  int v23; // [esp-4h] [ebp-20Ch]
  int v24; // [esp-4h] [ebp-20Ch]
  int v25; // [esp-4h] [ebp-20Ch]
  int v26; // [esp-4h] [ebp-20Ch]
  int v27; // [esp-4h] [ebp-20Ch]
  int v28; // [esp-4h] [ebp-20Ch]
  int v29; // [esp-4h] [ebp-20Ch]
  _BYTE v30[500]; // [esp+0h] [ebp-208h] BYREF
  _DWORD v31[2]; // [esp+1F4h] [ebp-14h] BYREF
  int v32; // [esp+1FCh] [ebp-Ch]
  int v33; // [esp+200h] [ebp-8h]
  int v34; // [esp+204h] [ebp-4h]

  v31[0] = (char *)&loc_1310FD + 3;
  v31[1] = 0;
  sub_12C2C6(1);
  sub_12C2A0();
  if ( !byte_182ACA && !word_19994C )
  {
LABEL_10:
    sub_120BB5(1, (int)v31);
    v3 = 0;
    if ( *(int16_t *)(dword_1A11AC + 23) > 0 )
    {
      sub_12B7E1((int16_t)(word_1A123A + 20), (int16_t)(word_1A123C + 50), (_WORD *)dword_1A1170);
      v23 = *(int16_t *)(dword_1A11AC + 23);
      v4 = (char *)sub_CDF5C(19);
      sprintf(v30, v4, v23);
      v3 = 1;
      sub_1212B3(word_1A123A + 55, word_1A123C + 50, (int)v30);
    }
    if ( *(int16_t *)(dword_1A11AC + 25) != -1 )
    {
      v5 = 30 * v3;
      sub_12B7E1((int16_t)(word_1A123A + 20), (int16_t)(30 * v3 + word_1A123C + 50), (_WORD *)dword_1A1174);
      v24 = sub_BB3DB(*(_WORD *)(dword_1A11AC + 25));
      v6 = (char *)sub_CDF5C(70);
      sprintf(v30, v6, v24);
      ++v3;
      sub_1212B3(word_1A123A + 55, v5 + word_1A123C + 50, (int)v30);
    }
    if ( *(int16_t *)(dword_1A11AC + 21) > 0 )
    {
      v7 = 30 * v3;
      v8 = (_WORD *)sub_BB54D(
                      (uint16_t)(*(_WORD *)(361 * *(int16_t *)dword_1A11AC + dword_192B18 + 12) << 7) >> 14,
                      2u,
                      *(uint8_t *)(3753 * *(char *)(dword_1A11AC + 12) + dword_197F98 + 37));
      sub_12B7E1((int16_t)(word_1A123A + 20), (int16_t)(30 * v3 + word_1A123C + 50), v8);
      v25 = *(int16_t *)(dword_1A11AC + 21);
      v9 = (char *)sub_CDF5C(20);
      sprintf(v30, v9, v25);
      ++v3;
      sub_1212B3(word_1A123A + 55, word_1A123C + 50 + v7, (int)v30);
    }
    v10 = 3;
    v34 = 30 * v3;
    while ( 1 )
    {
      if ( v10 < 2 )
      {
        v32 = 2 * v10;
        if ( *(int16_t *)(v32 + dword_1A11AC + 13) > 0 )
        {
          v33 = *(char *)(dword_1A11AC + 12);
          v11 = (_WORD *)sub_BB723(v33, v10, *(uint8_t *)(3753 * v33 + dword_197F98 + 37));
          v33 = (int16_t)(word_1A123A + 20);
          sub_12B7E1(v33, (int16_t)(v34 + word_1A123C + 50), v11);
          if ( byte_199CAE == 4 )
          {
            v26 = *(int16_t *)(v32 + dword_1A11AC + 13);
            v19 = sub_BB695(*(char *)(dword_1A11AC + 12), v10);
            sprintf(v30, "%s: %d", v19, v26);
          }
          else
          {
            v33 = *(char *)(dword_1A11AC + 12);
            v27 = sub_BB695(v33, v10);
            v20 = *(int16_t *)(v32 + dword_1A11AC + 13);
            v18 = (char *)sub_CDF5C(14);
            sprintf(v30, v18, v20, v27);
          }
          v12 = v34 + word_1A123C + 50;
          ++v3;
          v34 += 30;
          sub_1212B3(word_1A123A + 55, v12, (int)v30);
        }
      }
      if ( --v10 < 0 )
      {
        v13 = 0;
        if ( *(int16_t *)(dword_1A11AC + 5) > 0 )
        {
          v14 = (_WORD *)sub_BB723(
                           *(char *)(dword_1A11AC + 2),
                           1,
                           *(uint8_t *)(3753 * *(char *)(dword_1A11AC + 2) + dword_197F98 + 37));
          sub_12B7E1((int16_t)(*(_WORD *)dword_1A1120 + word_1A123A - 40), (int16_t)(word_1A123C + 50), v14);
          v28 = sub_BB695(*(char *)(dword_1A11AC + 2), 1);
          v21 = *(int16_t *)(dword_1A11AC + 5);
          v15 = (char *)sub_CDF5C(14);
          sprintf(v30, v15, v21, v28);
          v13 = 1;
          sub_1210B7(*(_WORD *)dword_1A1120 + word_1A123A - 45, word_1A123C + 50, (int)v30);
        }
        if ( *(int16_t *)(dword_1A11AC + 43) >= 0 )
        {
          sub_12B7E1(
            (int16_t)(*(_WORD *)dword_1A1120 + word_1A123A - 40),
            (int16_t)(30 * v13 + word_1A123C + 50),
            (_WORD *)dword_1A116C);
          if ( word_1A1230 && word_1A1230 != 2 )
          {
            v29 = *(int16_t *)(dword_1A11AC + 43);
            v16 = 18;
          }
          else
          {
            v29 = *(int16_t *)(dword_1A11AC + 43);
            v16 = 21;
          }
          v17 = (char *)sub_CDF5C(v16);
          sprintf(v30, v17, v29);
          sub_1210B7(*(_WORD *)dword_1A1120 + word_1A123A - 45, 30 * v13 + word_1A123C + 50, (int)v30);
        }
        sub_C6CF7();
        JUMPOUT(0xC7EFD);
      }
    }
  }
  sub_C7F84();
  sub_128C32(
    (int16_t)(word_1A123A + 5),
    (int16_t)(word_1A123C + 5),
    (int16_t)(*(_WORD *)dword_1A1120 - 10),
    (int16_t)(*(_WORD *)(dword_1A1120 + 2) - 10),
    0);
  sub_12A478(word_1A123A, word_1A123C, dword_1A1120);
  sub_C5CFF(
    (2 * word_1A123A + *(int16_t *)dword_1A1120) / 2,
    (*(int16_t *)(dword_1A1120 + 2) + 2 * word_1A123C) / 2,
    (int16_t *)dword_19285C);
  v0 = sub_BBA8E(13);
  sub_133C9C(v0, (int)v31);
  sub_120BB5(3, (int)v31);
  if ( (uint16_t)word_1A1230 < 2u )
  {
    v22 = sub_77B28(*(_WORD *)(dword_192B18 + 361 * *(int16_t *)dword_1A11AC + 2));
    v1 = 458;
  }
  else
  {
    if ( word_1A1230 != 2 )
      goto LABEL_9;
    v22 = sub_77B28(*(_WORD *)(dword_192B18 + 361 * *(int16_t *)dword_1A11AC + 2));
    v1 = 337;
  }
  v2 = (char *)sub_CDF5C(v1);
  sprintf(v30, v2, v22);
LABEL_9:
  sub_1210FD((2 * word_1A123A + *(int16_t *)dword_1A1120) / 2, word_1A123C + 20, (int)v30);
  sub_124DEC();
  byte_182ACA = 0;
  goto LABEL_10;
}
// CB887: control flows out of bounds to C7EFD
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 19285C: using guessed type int dword_19285C;
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 199CAE: using guessed type char byte_199CAE;
// 1A1120: using guessed type int dword_1A1120;
// 1A116C: using guessed type int dword_1A116C;
// 1A1170: using guessed type int dword_1A1170;
// 1A1174: using guessed type int dword_1A1174;
// 1A11AC: using guessed type int dword_1A11AC;
// 1A1230: using guessed type int16_t word_1A1230;
// 1A123A: using guessed type int16_t word_1A123A;
// 1A123C: using guessed type int16_t word_1A123C;


//----- (000CB88C) --------------------------------------------------------
int __fastcall sub_CB88C(int16_t *a1, int a2, _WORD *a3, _WORD *a4)
{
  int16_t v5; // cx
  int result; // eax
  int v7; // edx
  int16_t v8; // ax
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // eax

  v5 = *a1;
  if ( *a1 == word_1A11D0 )
  {
    result = -1;
LABEL_3:
    *a3 = 1;
    return result;
  }
  if ( v5 == -word_1A11D0 )
  {
    v7 = sub_CDF5C(608);
    v8 = 386;
    goto LABEL_24;
  }
  if ( *a1 == word_1A11DC )
  {
    result = 3;
    goto LABEL_3;
  }
  if ( v5 == -word_1A11DC )
  {
    v7 = sub_CDF5C(609);
    v8 = 336;
    goto LABEL_24;
  }
  if ( *a1 == word_1A11DE )
  {
    byte_1831B6 = 1;
    result = 2;
    goto LABEL_3;
  }
  if ( v5 == -word_1A11DE )
  {
    v7 = sub_CDF5C(610);
    v8 = 205;
    goto LABEL_24;
  }
  if ( *a1 == word_1A11E0 )
  {
    result = 1;
    goto LABEL_3;
  }
  if ( v5 == -word_1A11E0 )
  {
    v7 = sub_CDF5C(611);
    v8 = 264;
    goto LABEL_24;
  }
  if ( *a1 == word_1A11E2 )
  {
    if ( sub_C613B(*(char *)(dword_1A11AC + 2), *(_WORD *)dword_1A11AC) )
    {
      result = 4;
      goto LABEL_3;
    }
    goto LABEL_38;
  }
  if ( v5 == -word_1A11E2 )
  {
    if ( !sub_C622A(*(char *)(dword_1A11AC + 2), *(_WORD *)dword_1A11AC) )
    {
      sub_C613B(*(char *)(dword_1A11AC + 2), *(_WORD *)dword_1A11AC);
      goto LABEL_38;
    }
    v7 = sub_CDF5C(612);
    v8 = 373;
LABEL_24:
    v9 = sub_CDF5C(v8);
    sub_A5EB2(v9, v7);
LABEL_38:
    byte_182ACA = 1;
    goto LABEL_39;
  }
  if ( *a1 == word_1A11E4 )
  {
    byte_182ACA = 1;
    *a4 = 2;
  }
  else
  {
    if ( v5 == -word_1A11E4 )
    {
      v7 = sub_CDF5C(613);
      v8 = 276;
      goto LABEL_24;
    }
    if ( *a1 == word_1A11E6 )
    {
      byte_182ACA = 1;
      *a4 = 1;
    }
    else
    {
      v10 = -word_1A11E6;
      if ( v5 == v10 )
      {
        v7 = sub_CDF5C(614);
        v8 = 217;
        goto LABEL_24;
      }
      if ( *a1 == word_1A11E8 )
      {
        *a4 = 0;
        sub_119441();
        sub_117174(1);
        sub_12C2A0();
        goto LABEL_38;
      }
      if ( v5 == v10 )
      {
        v11 = sub_CDF5C(615);
        v12 = sub_CDF5C(199);
        sub_A5EB2(v12, v11);
        goto LABEL_38;
      }
    }
  }
LABEL_39:
  *a3 = 0;
  return 0;
}
// 182ACA: using guessed type char byte_182ACA;
// 1831B6: using guessed type char byte_1831B6;
// 1A11AC: using guessed type int dword_1A11AC;
// 1A11D0: using guessed type int16_t word_1A11D0;
// 1A11DC: using guessed type int16_t word_1A11DC;
// 1A11DE: using guessed type int16_t word_1A11DE;
// 1A11E0: using guessed type int16_t word_1A11E0;
// 1A11E2: using guessed type int16_t word_1A11E2;
// 1A11E4: using guessed type int16_t word_1A11E4;
// 1A11E6: using guessed type int16_t word_1A11E6;
// 1A11E8: using guessed type int16_t word_1A11E8;


//----- (000CBAD0) --------------------------------------------------------
void __fastcall sub_CBAD0(int a1, int a2, int a3, int *a4)
{
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int64_t v10; // rax
  int16_t *v12; // eax
  int16_t v13; // ax
  char *v14; // eax
  int16_t v15; // [esp-Ch] [ebp-22Ch]
  int16_t v16; // [esp-8h] [ebp-228h]
  int16_t *v17; // [esp-8h] [ebp-228h]
  char v18; // [esp-4h] [ebp-224h]
  int v19; // [esp-4h] [ebp-224h]
  _BYTE v21[500]; // [esp+4h] [ebp-21Ch] BYREF
  _DWORD v22[2]; // [esp+1F8h] [ebp-28h] BYREF
  int v23; // [esp+200h] [ebp-20h] BYREF
  char *v24; // [esp+204h] [ebp-1Ch] BYREF
  int v25; // [esp+208h] [ebp-18h] BYREF
  int v26; // [esp+20Ch] [ebp-14h] BYREF
  int v27; // [esp+210h] [ebp-10h] BYREF
  int v28; // [esp+214h] [ebp-Ch] BYREF
  char v29; // [esp+218h] [ebp-8h]
  char v30; // [esp+21Ch] [ebp-4h]

  v26 = 0;
  v28 = 0;
  v25 = 0;
  word_1828CC = 0;
  word_1A1240 = -1;
  v22[0] = -1566465889;
  v22[1] = 0;
  sub_1205E6(0, 0, 255);
  sub_131922(0, 255);
  sub_120CCB(1, (int)v22);
  sub_CAC18();
  sub_C6CA4();
  v4 = sub_BBA8E(13);
  sub_133C9C(v4, (int)v22);
  v5 = dword_1930D4;
  sub_C702E(
    *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * *(int16_t *)dword_1A11AC + 2) + 2),
    (int16_t *)dword_1A1120);
  sub_119281();
  v29 = 0;
  sub_1191CA((int)sub_CB23C, 1);
  sub_C6E7E();
  v30 = 0;
  sub_CADC8(a2, &v25);
  sub_CB23C();
  sub_1077D(v6);
  sub_124C08();
  if ( a2 == 2 )
  {
    v29 = 1;
  }
  else if ( a2 == 1 )
  {
    a4 = *(int **)(dword_1A11AC + 27);
    LOWORD(v7) = *(_WORD *)((char *)a4 + 3);
    v23 = v7;
    LOWORD(v7) = *((_WORD *)a4 + 3);
    v27 = v7;
    v5 = 49;
    *((_WORD *)a4 + 4) = 0;
    *((_WORD *)a4 + 5) = 0;
    *((_WORD *)a4 + 6) = 0;
    memset((char *)a4 + 14, 0, 49);
    *(_WORD *)((char *)a4 + 63) = 0;
    *((_BYTE *)a4 + 65) = 0;
    *((_BYTE *)a4 + 66) = 0;
  }
  sub_124820(*(_DWORD *)(dword_1A11AC + 39));
  word_1A1230 = a2;
  while ( 1 )
  {
    byte_182ACA = 1;
    if ( word_1831C2 > 0 )
      sub_10FEC1((int)&unk_1A11F8 + 18 * --word_1831C2);
    sub_C6E7E();
    sub_CADC8(a2, &v25);
    v26 = sub_1171AB(v8, (int)&v25, v5, (int)a4);
    v24 = sub_114177();
    if ( a2 == 2 )
    {
      if ( *(int16_t *)(dword_1A11AC + 21) <= 0 )
        v30 = 1;
      do
      {
        if ( *(_BYTE *)(*(_DWORD *)(dword_1A11AC + 31) + 22) < 4u
          && *(_BYTE *)(*(_DWORD *)(dword_1A11AC + 35) + 22) < 4u
          && v29 )
        {
          if ( !(word_1828CC % 10) || v30 )
          {
            sub_EC4FE(*(uint8_t **)(dword_1A11AC + 31), *(uint8_t **)(dword_1A11AC + 35));
            v18 = *(_BYTE *)(dword_1A11AC + 11);
            v16 = *(_WORD *)(dword_1A11AC + 43);
            v15 = *(_WORD *)dword_1A11AC;
            v9 = sub_12484C();
            sub_CA6FB(
              (int16_t *)dword_1A11AC,
              *(_BYTE **)(dword_1A11AC + 31),
              *(_BYTE **)(dword_1A11AC + 35),
              v9,
              v15,
              v16,
              v18);
            byte_182ACA = 1;
          }
        }
        else
        {
          if ( !v29 )
            v29 = 1;
          if ( (_WORD)v26 && !v30 )
          {
            v30 = 1;
            v26 = 0;
          }
        }
      }
      while ( v30
           && *(_BYTE *)(*(_DWORD *)(dword_1A11AC + 31) + 22) < 4u
           && *(_BYTE *)(*(_DWORD *)(dword_1A11AC + 35) + 22) < 4u );
    }
    else if ( a2 == 1 )
    {
      sub_CA85C(*(_DWORD *)(dword_1A11AC + 27), &v25, (int16_t *)&v23, (int16_t *)&v27);
    }
    a4 = &v25;
    v5 = (int)&v28;
    HIDWORD(v10) = sub_CB88C((int16_t *)&v26, (int)&v24, &v28, &v25);
    sub_CB23C();
    sub_1077D(v10);
    if ( a2 == 2 )
    {
      a4 = *(int **)(dword_1A11AC + 31);
      if ( *((_BYTE *)a4 + 22) >= 4u || *(_BYTE *)(*(_DWORD *)(dword_1A11AC + 35) + 22) >= 4u )
      {
        a4 = (int *)dword_1A11AC;
        v12 = *(int16_t **)(dword_1A11AC + 31);
        v19 = 3753 * *v12 + dword_197F98 + 21;
        if ( *((_BYTE *)v12 + 22) >= 4u )
        {
          v5 = 361 * *(int16_t *)dword_1A11AC;
          v17 = sub_77B28(*(_WORD *)(v5 + dword_192B18 + 2));
          v13 = 60;
        }
        else
        {
          v5 = dword_192B18;
          v17 = sub_77B28(*(_WORD *)(dword_192B18 + 361 * *(int16_t *)dword_1A11AC + 2));
          v13 = 63;
        }
        v14 = (char *)sub_CDF5C(v13);
        v10 = sprintf(v21, v14, v17, v19);
        sub_C5B5F((int)v21);
        byte_182ACA = 1;
        v28 = 1;
      }
    }
    ++word_1828CC;
    LODWORD(v10) = sub_12C2C6(1);
    if ( (_WORD)v28 )
    {
      sub_C7283(v10, SHIDWORD(v10));
      sub_C6CA4();
      sub_112816();
      if ( WORD2(v10) == 3 )
        sub_C5BB9();
      JUMPOUT(0xC97B7);
    }
  }
}
// CBEB6: control flows out of bounds to C97B7
// CBBB1: variable 'v6' is possibly undefined
// CBBE2: variable 'v7' is possibly undefined
// CBC74: variable 'v8' is possibly undefined
// CBD9C: variable 'v10' is possibly undefined
// 1077D: using guessed type int __fastcall sub_1077D(_DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1828CC: using guessed type int16_t word_1828CC;
// 182ACA: using guessed type char byte_182ACA;
// 1831C2: using guessed type int16_t word_1831C2;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 1A1120: using guessed type int dword_1A1120;
// 1A11AC: using guessed type int dword_1A11AC;
// 1A1230: using guessed type int16_t word_1A1230;
// 1A1240: using guessed type int16_t word_1A1240;


//----- (000CBEBB) --------------------------------------------------------
_DWORD *sub_CBEBB()
{
  _DWORD *result; // eax

  sub_1112EC(dword_192ED4, 62);
  dword_1A1180 = (int)sub_126B42((int)aMainpupsLbx, 62, dword_192ED4);
  dword_1A1184 = (int)sub_126B42((int)aMainpupsLbx, 63, dword_192ED4);
  dword_1A1188 = (int)sub_126B42((int)aMainpupsLbx, 64, dword_192ED4);
  dword_1A118C = (int)sub_126B42((int)aMainpupsLbx, 65, dword_192ED4);
  dword_1A1190 = (int)sub_126B42((int)aMainpupsLbx, 66, dword_192ED4);
  dword_1A1194 = (int)sub_126B42((int)aMainpupsLbx, 67, dword_192ED4);
  dword_1A11A0 = (int)sub_126B42((int)aMainpupsLbx, 68, dword_192ED4);
  result = sub_126B42((int)aMainpupsLbx, 69, dword_192ED4);
  dword_1A11A4 = (int)result;
  return result;
}
// 192ED4: using guessed type int dword_192ED4;
// 1A1180: using guessed type int dword_1A1180;
// 1A1184: using guessed type int dword_1A1184;
// 1A1188: using guessed type int dword_1A1188;
// 1A118C: using guessed type int dword_1A118C;
// 1A1190: using guessed type int dword_1A1190;
// 1A1194: using guessed type int dword_1A1194;
// 1A11A0: using guessed type int dword_1A11A0;
// 1A11A4: using guessed type int dword_1A11A4;


//----- (000CBFB5) --------------------------------------------------------
int sub_CBFB5()
{
  _WORD *v0; // ecx
  int v1; // eax
  _WORD *v2; // ecx
  int v3; // eax
  _WORD *v4; // ecx
  int v5; // eax
  _WORD *v6; // ecx
  int v7; // eax
  _WORD *v8; // ecx
  int v9; // eax
  _WORD *v10; // ecx
  int v11; // eax
  _WORD *v12; // ecx
  int v13; // eax
  int result; // eax
  _BYTE *v15; // [esp-10h] [ebp-14h]
  _BYTE *v16; // [esp-10h] [ebp-14h]
  _BYTE *v17; // [esp-10h] [ebp-14h]
  _BYTE *v18; // [esp-10h] [ebp-14h]
  _BYTE *v19; // [esp-10h] [ebp-14h]
  _BYTE *v20; // [esp-10h] [ebp-14h]
  _BYTE *v21; // [esp-10h] [ebp-14h]

  v15 = (_BYTE *)sub_CDF5C(135);
  v0 = (_WORD *)dword_1A11A0;
  v1 = sub_CDF5C(12);
  word_1A11F6 = (uint16_t)sub_1151B0(237, 254, v1, v0, v15, 40);
  v16 = (_BYTE *)sub_CDF5C(142);
  v2 = (_WORD *)dword_1A1180;
  v3 = sub_CDF5C(12);
  word_1A11EA = sub_115383(147, 198, v3, v2, (int)&word_1A122E, 0, v16, 41);
  v17 = (_BYTE *)sub_CDF5C(147);
  v4 = (_WORD *)dword_1A1184;
  v5 = sub_CDF5C(12);
  word_1A11EC = sub_115383(193, 198, v5, v4, (int)&word_1A122E, 10, v17, 41);
  v18 = (_BYTE *)sub_CDF5C(149);
  v6 = (_WORD *)dword_1A1188;
  v7 = sub_CDF5C(12);
  word_1A11EE = sub_115383(234, 198, v7, v6, (int)&word_1A122E, 20, v18, 41);
  v19 = (_BYTE *)sub_CDF5C(151);
  v8 = (_WORD *)dword_1A118C;
  v9 = sub_CDF5C(12);
  word_1A11F0 = sub_115383(275, 198, v9, v8, (int)&word_1A122E, 30, v19, 41);
  v20 = (_BYTE *)sub_CDF5C(153);
  v10 = (_WORD *)dword_1A1190;
  v11 = sub_CDF5C(12);
  word_1A11F2 = sub_115383(316, 198, v11, v10, (int)&word_1A122E, 40, v20, 41);
  v21 = (_BYTE *)sub_CDF5C(155);
  v12 = (_WORD *)dword_1A1194;
  v13 = sub_CDF5C(12);
  result = sub_115383(357, 198, v13, v12, (int)&word_1A122E, 50, v21, 41);
  word_1A11F4 = result;
  return result;
}
// 1A1180: using guessed type int dword_1A1180;
// 1A1184: using guessed type int dword_1A1184;
// 1A1188: using guessed type int dword_1A1188;
// 1A118C: using guessed type int dword_1A118C;
// 1A1190: using guessed type int dword_1A1190;
// 1A1194: using guessed type int dword_1A1194;
// 1A11A0: using guessed type int dword_1A11A0;
// 1A11EA: using guessed type int16_t word_1A11EA;
// 1A11EC: using guessed type int16_t word_1A11EC;
// 1A11EE: using guessed type int16_t word_1A11EE;
// 1A11F0: using guessed type int16_t word_1A11F0;
// 1A11F2: using guessed type int16_t word_1A11F2;
// 1A11F4: using guessed type int16_t word_1A11F4;
// 1A11F6: using guessed type int16_t word_1A11F6;
// 1A122E: using guessed type int16_t word_1A122E;


//----- (000CC152) --------------------------------------------------------
void *sub_CC152()
{
  void *result; // eax

  if ( byte_182ACA || word_19994C )
  {
    byte_199F28 = 1;
    sub_C7F84();
    byte_182ACA = 1;
    sub_12A478(0, 0, dword_1A11A4);
    result = sub_124DEC();
    byte_182ACA = 0;
  }
  return result;
}
// 182ACA: using guessed type char byte_182ACA;
// 19994C: using guessed type int16_t word_19994C;
// 199F28: using guessed type char byte_199F28;
// 1A11A4: using guessed type int dword_1A11A4;


//----- (000CC198) --------------------------------------------------------
int __usercall sub_CC198(int result, _WORD *a2, int a3)
{
  int v3; // eax
  int v4; // ebx

  if ( *(_WORD *)result == word_1A11F6 )
  {
    v3 = 3753 * word_19999C;
    *a2 = 1;
    result = dword_197F98 + v3;
    *(_BYTE *)(result + 49) = word_1A122E;
  }
  else if ( *(_WORD *)result )
  {
    v4 = word_19999C;
    *(_BYTE *)(3753 * word_19999C + dword_197F98 + 49) = word_1A122E;
    result = sub_E2D72(v4, a3);
    byte_182ACA = 1;
  }
  if ( word_19994C )
    byte_182ACA = 1;
  return result;
}
// 182ACA: using guessed type char byte_182ACA;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 1A11F6: using guessed type int16_t word_1A11F6;
// 1A122E: using guessed type int16_t word_1A122E;


//----- (000CC20B) --------------------------------------------------------
void __fastcall sub_CC20B(int a1, int a2, int *a3, int a4)
{
  int v4; // edx
  void *v5; // eax
  int v6; // eax
  int v7; // eax
  void *v8; // eax
  _DWORD v9[2]; // [esp+0h] [ebp-14h] BYREF
  char *v10; // [esp+8h] [ebp-Ch] BYREF
  int v11; // [esp+Ch] [ebp-8h] BYREF
  int v12; // [esp+10h] [ebp-4h] BYREF

  v12 = 0;
  v11 = 0;
  v9[0] = -1566465889;
  v9[1] = 0;
  word_1A122E = *(uint8_t *)(dword_197F98 + 3753 * word_19999C + 49);
  word_1A1240 = -1;
  sub_120CCB(1, (int)v9);
  sub_CBEBB();
  sub_C702E(-1, (int16_t *)dword_1A11A4);
  sub_CDBEE();
  sub_119281();
  v4 = 1;
  sub_1191CA((int)sub_CC152, 1);
  sub_C6E7E();
  v5 = (void *)sub_CBFB5();
  if ( byte_182ACA || word_19994C )
  {
    byte_199F28 = 1;
    sub_C7F84();
    v4 = 0;
    a3 = (int *)dword_1A11A4;
    byte_182ACA = 1;
    sub_12A478(0, 0, dword_1A11A4);
    v5 = sub_124DEC();
    byte_182ACA = 0;
  }
  sub_1077D((int)v5, v4, (int)a3, (int16_t *)&v10);
  sub_124C9B();
  do
  {
    v7 = sub_1171AB(v6, v4, (int)a3, a4);
    a3 = &v11;
    v4 = (int)&v10;
    v12 = v7;
    v10 = sub_114177();
    v8 = (void *)sub_CC198((int)&v12, &v11, (int)&v10);
    if ( byte_182ACA || word_19994C )
    {
      byte_199F28 = 1;
      sub_C7F84();
      v4 = 0;
      a3 = (int *)dword_1A11A4;
      byte_182ACA = 1;
      sub_12A478(0, 0, dword_1A11A4);
      v8 = sub_124DEC();
      byte_182ACA = 0;
    }
    v6 = sub_1077D((int)v8, v4, (int)a3, (int16_t *)&v10);
  }
  while ( !(_WORD)v11 );
  sub_C7283(v6, v4);
}
// CC2E3: variable 'v6' is possibly undefined
// 182ACA: using guessed type char byte_182ACA;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 199F28: using guessed type char byte_199F28;
// 1A11A4: using guessed type int dword_1A11A4;
// 1A122E: using guessed type int16_t word_1A122E;
// 1A1240: using guessed type int16_t word_1A1240;


//----- (000CC359) --------------------------------------------------------
int sub_CC359()
{
  sub_1112EC(dword_192ED4, 70);
  dword_1A1124 = (int)sub_126B42((int)aMainpupsLbx, 70, dword_192ED4);
  dword_1A11A0 = (int)sub_126B42((int)aMainpupsLbx, 71, dword_192ED4);
  dword_1A11A8 = (int)sub_126B42((int)aMainpupsLbx, 72, dword_192ED4);
  return sub_BB91D();
}
// 192ED4: using guessed type int dword_192ED4;
// 1A1124: using guessed type int dword_1A1124;
// 1A11A0: using guessed type int dword_1A11A0;
// 1A11A8: using guessed type int dword_1A11A8;


//----- (000CC3DB) --------------------------------------------------------
int16_t sub_CC3DB()
{
  _WORD *v0; // ecx
  int v1; // eax
  _WORD *v2; // ecx
  int v3; // eax
  _BYTE *v5; // [esp-10h] [ebp-14h]
  _BYTE *v6; // [esp-10h] [ebp-14h]

  v5 = (_BYTE *)sub_CDF5C(135);
  v0 = (_WORD *)dword_1A1124;
  v1 = sub_CDF5C(12);
  word_1A11C8 = (uint16_t)sub_1151B0(186, 313, v1, v0, v5, 40);
  if ( word_1831CC )
  {
    word_1A11F6 = -1000;
  }
  else
  {
    v6 = (_BYTE *)sub_CDF5C(561);
    v2 = (_WORD *)dword_1A11A0;
    v3 = sub_CDF5C(12);
    word_1A11F6 = (uint16_t)sub_1151B0(381, 313, v3, v2, v6, 40);
  }
  return sub_9023B(302, 156, 148, 94, 0, 0, 0, 0, 0, word_19F9EA, (int)word_190178, &word_19997A);
}
// 1831CC: using guessed type int16_t word_1831CC;
// 190178: using guessed type int16_t word_190178[72];
// 19997A: using guessed type int16_t word_19997A;
// 19F9EA: using guessed type int16_t word_19F9EA[2];
// 1A1124: using guessed type int dword_1A1124;
// 1A11A0: using guessed type int dword_1A11A0;
// 1A11C8: using guessed type int16_t word_1A11C8;
// 1A11F6: using guessed type int16_t word_1A11F6;


//----- (000CC491) --------------------------------------------------------
int __usercall sub_CC491( int a1)
{
  char *v1; // eax
  int16_t v2; // ax
  char *v3; // eax
  int result; // eax
  int v5; // [esp-8h] [ebp-134h]
  int v6; // [esp-4h] [ebp-130h]
  int v7; // [esp-4h] [ebp-130h]
  _BYTE v8[300]; // [esp+0h] [ebp-12Ch] BYREF

  if ( word_1831D0 != word_1831CE )
  {
    byte_182ACA = 1;
    word_1831D0 = word_1831CE;
  }
  if ( byte_182ACA || word_19994C )
  {
    byte_199F28 = 1;
    sub_C7F84();
    byte_182ACA = 1;
    sub_12A478(0, 0, dword_1A11A8);
    sub_BBA8E(12);
    sub_BBA8E(11);
    sub_90C4F(156, 302, a1, 148, 94, 0, 0, 0, 0, 0, 0);
    if ( word_1831CC == 1 )
    {
      v6 = 3753 * word_1831B0 + dword_197F98 + 1;
      v1 = (char *)sub_CDF5C(464);
      sprintf(v8, v1, v6);
    }
    else
    {
      v7 = dword_19306C + 113 * word_1831AC;
      v5 = dword_197F98 + 3753 * word_1831B0 + 1;
      if ( word_1831CC == 2 )
        v2 = 583;
      else
        v2 = 555;
      v3 = (char *)sub_CDF5C(v2);
      sprintf(v8, v3, 500, v5, v7);
    }
    sub_10323B((int)v8, 2);
    sub_124DEC();
    byte_182ACA = 0;
  }
  result = word_1831CE;
  if ( word_1831CE != -1 )
    return sub_1210FD(376, 254, 113 * word_1831CE + dword_19306C);
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 182ACA: using guessed type char byte_182ACA;
// 1831AC: using guessed type int16_t word_1831AC;
// 1831B0: using guessed type int16_t word_1831B0;
// 1831CC: using guessed type int16_t word_1831CC;
// 1831CE: using guessed type int16_t word_1831CE;
// 1831D0: using guessed type int16_t word_1831D0;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 199F28: using guessed type char byte_199F28;
// 1A11A8: using guessed type int dword_1A11A8;


//----- (000CC64B) --------------------------------------------------------
int __fastcall sub_CC64B(int16_t *a1, int16_t *a2, _WORD *a3, int a4)
{
  int16_t v5; // bx
  int result; // eax
  int16_t v7; // ax
  int v8; // eax
  int v9; // [esp+0h] [ebp-Ch] BYREF
  int v10; // [esp+4h] [ebp-8h] BYREF
  int v11; // [esp+8h] [ebp-4h]

  v11 = a4;
  v5 = *a1;
  word_1831CE = -1;
  if ( v5 == word_1A11C8 )
  {
    result = -1;
    *a3 = 1;
    return result;
  }
  if ( v5 == word_1A11F6 )
  {
    if ( *(int *)(3753 * word_1831B0 + dword_197F98 + 50) < 500 )
      word_1831CC = 2;
    else
      word_1831CC = 1;
    byte_182ACA = 1;
  }
  else
  {
    if ( word_1831CC == 1 )
    {
      v7 = sub_890EF(*a2, v5, (int16_t *)&v9, (int16_t *)&v10);
      if ( v7 == 4 )
      {
        word_1831CE = v9;
      }
      else if ( !v7 )
      {
        if ( (_WORD)v10 != (_WORD)v11 )
        {
          *a3 = 1;
          return v10;
        }
        v8 = sub_CDF5C(576);
        sub_C5B5F(v8);
        byte_182ACA = 1;
      }
    }
    if ( word_19994C )
      byte_182ACA = 1;
  }
  return 0;
}
// 182ACA: using guessed type char byte_182ACA;
// 1831B0: using guessed type int16_t word_1831B0;
// 1831CC: using guessed type int16_t word_1831CC;
// 1831CE: using guessed type int16_t word_1831CE;
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 1A11C8: using guessed type int16_t word_1A11C8;
// 1A11F6: using guessed type int16_t word_1A11F6;


//----- (000CC735) --------------------------------------------------------
void __fastcall sub_CC735( int a1, int a2, int *a3, int a4)
{
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  _DWORD v10[2]; // [esp+4h] [ebp-14h] BYREF
  int v11; // [esp+Ch] [ebp-Ch] BYREF
  char *v12; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h] BYREF

  v13 = 0;
  v11 = 0;
  word_1831CC = 0;
  word_1A1240 = -1;
  word_1831B0 = a1;
  v10[0] = -1566465889;
  v10[1] = 0;
  sub_120CCB(1, (int)v10);
  sub_CC359();
  sub_C702E(a2, (int16_t *)dword_1A11A8);
  sub_119281();
  v4 = 1;
  sub_1191CA((int)sub_CC491, 1);
  sub_CDC03();
  sub_C6E7E();
  sub_BF52F();
  sub_CC3DB();
  v5 = sub_CC491((int16_t)sub_C6E7E);
  sub_1077D(v5, 1, (int)a3, (int16_t *)&v11);
  sub_124C9B();
  do
  {
    v7 = sub_1171AB(v6, v4, (int)a3, a4);
    a4 = a2;
    a3 = &v11;
    v13 = v7;
    v12 = sub_114177();
    v4 = sub_CC64B((int16_t *)&v13, (int16_t *)&v12, &v11, a2);
    v8 = sub_CC491((int16_t)sub_C6E7E);
    v6 = sub_1077D(v8, v4, (int)&v11, (int16_t *)&v11);
  }
  while ( !(_WORD)v11 );
  sub_C7283(v6, v4);
  sub_1196F7();
  word_1831B0 = -1;
  word_1831AC = -1;
  JUMPOUT(0xC97B7);
}
// CC817: control flows out of bounds to C97B7
// CC7C6: variable 'v6' is possibly undefined
// 1831AC: using guessed type int16_t word_1831AC;
// 1831B0: using guessed type int16_t word_1831B0;
// 1831CC: using guessed type int16_t word_1831CC;
// 1A11A8: using guessed type int dword_1A11A8;
// 1A1240: using guessed type int16_t word_1A1240;


//----- (000CC81C) --------------------------------------------------------
int sub_CC81C()
{
  int64_t v0; // rax
  int16_t v1; // dx
  int v2; // ebx
  int64_t v3; // rax
  char *v4; // eax
  int result; // eax

  dword_1A12EC = sub_CDF5C(545);
  dword_1A12F0 = sub_CDF5C(280);
  dword_1A12F4 = sub_CDF5C(190);
  dword_1A12F8 = sub_CDF5C(318);
  dword_1A12FC[0] = sub_CDF5C(328);
  WORD2(v0) = 0;
  dword_1A124C[0] = sub_CDF5C(480);
  if ( byte_199CAE == 4 )
  {
    v0 = sprintf(&unk_1A12A8, aPiccola);
    dword_1A124C[0] = (int)&unk_1A12A8;
  }
  v1 = WORD2(v0) + 1;
  v2 = sub_CDF5C(371);
  LODWORD(v3) = v1;
  WORD2(v3) = v1 + 1;
  dword_1A124C[(_DWORD)v3] = v2;
  if ( byte_199CAE == 2 )
  {
    v4 = (char *)sub_CDF5C(371);
    v3 = sprintf(&unk_1A12A8, "%sen", v4);
    LODWORD(v3) = SWORD2(v3);
LABEL_7:
    dword_1A124C[(_DWORD)v3] = (int)&unk_1A12A8;
    goto LABEL_8;
  }
  if ( byte_199CAE == 4 )
  {
    v3 = sprintf(&unk_1A12A8, aMedia);
    LODWORD(v3) = SWORD2(v3);
    goto LABEL_7;
  }
LABEL_8:
  dword_1A124C[SWORD2(v3)] = sub_CDF5C(360);
  dword_1A124C[(int16_t)(WORD2(v3) + 1)] = sub_CDF5C(323);
  dword_1A1274 = sub_CDF5C(377);
  dword_1A1278 = sub_CDF5C(190);
  dword_1A127C = sub_CDF5C(402);
  dword_1A1244 = sub_CDF5C(503);
  dword_1A1248 = sub_CDF5C(496);
  dword_1A128C = sub_CDF5C(148);
  dword_1A1290 = sub_CDF5C(150);
  dword_1A1294 = sub_CDF5C(152);
  dword_1A1298 = sub_CDF5C(154);
  dword_1A129C = sub_CDF5C(156);
  dword_1A12A0 = sub_CDF5C(157);
  dword_1A12A4 = sub_CDF5C(158);
  dword_1A1280 = sub_CDF5C(429);
  dword_1A1284 = sub_CDF5C(190);
  result = sub_CDF5C(169);
  dword_1A1288 = result;
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 199CAE: using guessed type char byte_199CAE;
// 1A1244: using guessed type int dword_1A1244;
// 1A1248: using guessed type int dword_1A1248;
// 1A124C: using guessed type int dword_1A124C[4];
// 1A1274: using guessed type int dword_1A1274;
// 1A1278: using guessed type int dword_1A1278;
// 1A127C: using guessed type int dword_1A127C;
// 1A1280: using guessed type int dword_1A1280;
// 1A1284: using guessed type int dword_1A1284;
// 1A1288: using guessed type int dword_1A1288;
// 1A128C: using guessed type int dword_1A128C;
// 1A1290: using guessed type int dword_1A1290;
// 1A1294: using guessed type int dword_1A1294;
// 1A1298: using guessed type int dword_1A1298;
// 1A129C: using guessed type int dword_1A129C;
// 1A12A0: using guessed type int dword_1A12A0;
// 1A12A4: using guessed type int dword_1A12A4;
// 1A12EC: using guessed type int dword_1A12EC;
// 1A12F0: using guessed type int dword_1A12F0;
// 1A12F4: using guessed type int dword_1A12F4;
// 1A12F8: using guessed type int dword_1A12F8;
// 1A12FC: using guessed type int dword_1A12FC;


//----- (000CCA1C) --------------------------------------------------------
int sub_CCA1C()
{
  int v0; // ebx
  int v1; // ecx
  int v2; // edi
  int v3; // ebx
  int v4; // edx
  _DWORD *v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // edi
  int v9; // edx
  int v10; // ebx
  _DWORD *v11; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // edi
  int v15; // edx
  int v16; // ebx
  _DWORD *v17; // eax
  int v18; // esi
  int v19; // ecx
  int v20; // edi
  int v21; // edx
  int v22; // ebx
  _DWORD *v23; // eax
  int v24; // esi
  int v25; // ecx
  int v26; // edi
  int v27; // edx
  int v28; // ebx
  _DWORD *v29; // eax
  int16_t v30; // si
  _DWORD *v31; // eax
  int v32; // ebx
  int v33; // edx
  int v35; // [esp+0h] [ebp-10h]
  int v36; // [esp+4h] [ebp-Ch]
  int v37; // [esp+8h] [ebp-8h]
  int v38; // [esp+Ch] [ebp-4h]

  v0 = dword_192ED4;
  v1 = 0;
  v2 = 0;
  dword_1A1354 = (int)sub_126AFD((int)aRaceoptLbx_3, 0, dword_192ED4);
  sub_FE8BE(dword_1A1354, 0, v0, 0);
  do
  {
    v3 = dword_192ED4;
    ++v2;
    v4 = (int16_t)++v1;
    v5 = sub_126B42((int)aNewgameLbx, (int16_t)v1, dword_192ED4);
    dword_1A132C[v2] = (int)v5;
  }
  while ( v1 < 3 );
  v6 = v1 + 1;
  v7 = 0;
  sub_FE8BE((int)v5, v4, v3, (int16_t *)(v2 * 4));
  v8 = 0;
  v38 = v6;
  do
  {
    v9 = (int16_t)v38;
    v10 = dword_192ED4;
    v11 = sub_126B42((int)aNewgameLbx, (int16_t)v38, dword_192ED4);
    ++v8;
    ++v7;
    ++v38;
    dword_1A12D4[v8] = (int)v11;
  }
  while ( v7 < 5 );
  v12 = v7 + v6;
  v13 = 0;
  sub_FE8BE((int)v11, v9, v10, (int16_t *)(v8 * 4));
  v14 = 0;
  v37 = v12;
  do
  {
    v15 = (int16_t)v37;
    v16 = dword_192ED4;
    v17 = sub_126B42((int)aNewgameLbx, (int16_t)v37, dword_192ED4);
    ++v14;
    ++v13;
    ++v37;
    dword_1A1260[v14] = (int)v17;
  }
  while ( v13 < 4 );
  v18 = v13 + v12;
  v19 = 0;
  sub_FE8BE((int)v17, v15, v16, (int16_t *)(v14 * 4));
  v20 = 0;
  v36 = v18;
  do
  {
    v21 = (int16_t)v36;
    v22 = dword_192ED4;
    v23 = sub_126B42((int)aNewgameLbx, (int16_t)v36, dword_192ED4);
    ++v20;
    ++v19;
    ++v36;
    dword_1A1310[v20] = (int)v23;
  }
  while ( v19 < 7 );
  v24 = v19 + v18;
  v25 = 0;
  sub_FE8BE((int)v23, v21, v22, (int16_t *)(v20 * 4));
  v26 = 0;
  v35 = v24;
  do
  {
    v27 = (int16_t)v35;
    v28 = dword_192ED4;
    v29 = sub_126B42((int)aNewgameLbx, (int16_t)v35, dword_192ED4);
    ++v26;
    ++v25;
    ++v35;
    dword_1A12FC[v26] = (int)v29;
  }
  while ( v25 < 3 );
  sub_FE8BE((int)v29, v27, v28, (int16_t *)(v26 * 4));
  v30 = v25 + v24;
  dword_1A12C0 = (int)sub_126B42((int)aNewgameLbx, v30, dword_192ED4);
  dword_1A12BC = (int)sub_126B42((int)aNewgameLbx, (int16_t)(v30 + 1), dword_192ED4);
  dword_1A12C4 = (int)sub_126B42((int)aNewgameLbx, (int16_t)(v30 + 2), dword_192ED4);
  dword_1A12C8 = (int)sub_126B42((int)aNewgameLbx, (int16_t)(v30 + 3), dword_192ED4);
  dword_1A12CC = (int)sub_126B42((int)aNewgameLbx, (int16_t)(v30 + 4), dword_192ED4);
  v31 = sub_126B42((int)aNewgameLbx, (int16_t)(v30 + 5), dword_192ED4);
  v32 = dword_192ED4;
  dword_1A12D4[0] = (int)v31;
  v33 = (int16_t)(v30 + 6);
  dword_1A12D0 = (int)sub_126B42((int)aNewgameLbx, v33, dword_192ED4);
  sub_FE8BE(dword_1A12D0, v33, v32, (int16_t *)(v26 * 4));
  return sub_CC81C();
}
// 192ED4: using guessed type int dword_192ED4;
// 1A1260: using guessed type int dword_1A1260[];
// 1A12BC: using guessed type int dword_1A12BC;
// 1A12C0: using guessed type int dword_1A12C0;
// 1A12C4: using guessed type int dword_1A12C4;
// 1A12C8: using guessed type int dword_1A12C8;
// 1A12CC: using guessed type int dword_1A12CC;
// 1A12D0: using guessed type int dword_1A12D0;
// 1A12D4: using guessed type int dword_1A12D4[];
// 1A12FC: using guessed type int dword_1A12FC[];
// 1A1310: using guessed type int dword_1A1310[];
// 1A132C: using guessed type int dword_1A132C[];
// 1A1354: using guessed type int dword_1A1354;


//----- (000CCC3D) --------------------------------------------------------
void __usercall sub_CCC3D(int a1)
{
  int16_t v1; // cx
  int16_t v2; // si
  int16_t i; // [esp+4h] [ebp-8h]
  int16_t v4; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( i = 0; ; i += 155 )
  {
    v2 = 0;
    v4 = 0;
    do
    {
      if ( v2 != 1 || v1 <= 1 )
      {
        if ( v1 || v2 )
        {
          if ( v1 != 1 || v2 )
          {
            if ( v1 != 2 || v2 )
            {
              if ( v1 || v2 != 1 )
              {
                if ( v1 == 1 && v2 == 1 )
                  a1 = dword_1A1300[word_1A1360];
              }
              else
              {
                a1 = dword_1A1314[word_1A1366];
              }
            }
            else
            {
              a1 = dword_1A1330[word_1A1358];
            }
          }
          else
          {
            a1 = dword_1A1264[word_1A135E];
          }
        }
        else
        {
          a1 = dword_1A12D8[word_1A1362];
        }
        sub_12A478(i + word_1831D4 + 121, v4 + word_1831D6 + 119, a1);
      }
      ++v2;
      v4 += 140;
    }
    while ( v2 < 2 );
    if ( ++v1 >= 3 )
      JUMPOUT(0xCCC36);
  }
}
// CCD37: control flows out of bounds to CCC36
// 1831D4: using guessed type int16_t word_1831D4;
// 1831D6: using guessed type int16_t word_1831D6;
// 1A1264: using guessed type int dword_1A1264[4];
// 1A12D8: using guessed type int dword_1A12D8[5];
// 1A1300: using guessed type int dword_1A1300[];
// 1A1314: using guessed type int dword_1A1314[6];
// 1A1330: using guessed type int dword_1A1330[3];
// 1A1358: using guessed type int16_t word_1A1358;
// 1A135E: using guessed type int16_t word_1A135E;
// 1A1360: using guessed type int16_t word_1A1360;
// 1A1362: using guessed type int16_t word_1A1362;
// 1A1366: using guessed type int16_t word_1A1366;


//----- (000CCD3C) --------------------------------------------------------
char __usercall sub_CCD3C(int a1)
{
  sub_120CCB(4, (int)&byte_1A125C);
  sub_120DED(0, 64);
  sub_12A478(word_1831D4, word_1831D6, dword_1A12D4[0]);
  sub_120BB5(2, (int)&byte_1A125C);
  sub_124D41();
  if ( byte_182ACA )
  {
    sub_128C32(0, 0, 639, 479, 0);
    sub_12A478(0, 0, dword_1A1354);
    sub_120BB5(3, (int)&byte_1A125C);
    sub_124DEC();
    byte_182ACA = 0;
  }
  sub_C68C4();
  sub_CCC3D(a1);
  if ( byte_199F3A == 2 )
    sub_12A478(word_1831D4 + 217, word_1831D6 + 377, dword_1A12D0);
  sub_120BB5(3, (int)&byte_1A125C);
  return sub_120F55(154);
}
// 182ACA: using guessed type char byte_182ACA;
// 1831D4: using guessed type int16_t word_1831D4;
// 1831D6: using guessed type int16_t word_1831D6;
// 199F3A: using guessed type char byte_199F3A;
// 1A125C: using guessed type char byte_1A125C;
// 1A12D0: using guessed type int dword_1A12D0;
// 1A12D4: using guessed type int dword_1A12D4[];
// 1A1354: using guessed type int dword_1A1354;


//----- (000CCE2E) --------------------------------------------------------
void sub_CCE2E()
{
  _BYTE *v0; // eax
  _BYTE *v1; // eax
  _BYTE *v2; // eax
  _BYTE *v3; // eax
  _BYTE *v4; // eax
  _BYTE *v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  _BYTE *v8; // eax
  _BYTE *v9; // eax
  _WORD *v10; // ecx
  int v11; // eax
  _WORD *v12; // ecx
  int v13; // eax
  _WORD *v14; // ecx
  int v15; // eax
  _WORD *v16; // ecx
  int v17; // eax
  _WORD *v18; // ecx
  int v19; // eax
  int v20; // edx
  _BYTE *v21; // eax
  _BYTE *v22; // [esp-18h] [ebp-1Ch]
  _BYTE *v23; // [esp-18h] [ebp-1Ch]
  _BYTE *v24; // [esp-18h] [ebp-1Ch]
  _BYTE *v25; // [esp-18h] [ebp-1Ch]
  _BYTE *v26; // [esp-18h] [ebp-1Ch]
  int16_t v27; // [esp-14h] [ebp-18h]
  int16_t v28; // [esp-14h] [ebp-18h]
  int16_t v29; // [esp-14h] [ebp-18h]
  int16_t v30; // [esp-14h] [ebp-18h]
  int16_t v31; // [esp-14h] [ebp-18h]

  sub_120BB5(3, (int)&byte_1A125C);
  v0 = (_BYTE *)sub_CDF5C(12);
  v27 = sub_11438B(word_1831D4 + 121, word_1831D6 + 119, word_1831D4 + 188, word_1831D6 + 184, v0, 0);
  v1 = (_BYTE *)sub_CDF5C(12);
  word_1A133C = sub_C6A43(
                  word_1831D4 + 105,
                  word_1831D6 + 204,
                  word_1831D4 + 205,
                  word_1831D6 + 224,
                  (int)&dword_1A12EC,
                  5,
                  (int)&word_1A1362,
                  0,
                  v1,
                  0,
                  v27);
  v2 = (_BYTE *)sub_CDF5C(12);
  v28 = sub_11438B(word_1831D4 + 276, word_1831D6 + 119, word_1831D4 + 343, word_1831D6 + 184, v2, 0);
  v3 = (_BYTE *)sub_CDF5C(12);
  word_1A133E = sub_C6A43(
                  word_1831D4 + 261,
                  word_1831D6 + 204,
                  word_1831D4 + 361,
                  word_1831D6 + 224,
                  (int)dword_1A124C,
                  4,
                  (int)&word_1A135E,
                  0,
                  v3,
                  0,
                  v28);
  v4 = (_BYTE *)sub_CDF5C(12);
  v29 = sub_11438B(word_1831D4 + 431, word_1831D6 + 119, word_1831D4 + 498, word_1831D6 + 184, v4, 0);
  v5 = (_BYTE *)sub_CDF5C(12);
  word_1A1340 = sub_C6A43(
                  word_1831D4 + 417,
                  word_1831D6 + 204,
                  word_1831D4 + 517,
                  word_1831D6 + 224,
                  (int)&dword_1A1274,
                  3,
                  (int)&word_1A1358,
                  0,
                  v5,
                  0,
                  v29);
  v6 = (_BYTE *)sub_CDF5C(12);
  v30 = sub_11438B(word_1831D4 + 121, word_1831D6 + 259, word_1831D4 + 188, word_1831D6 + 324, v6, 0);
  v7 = (_BYTE *)sub_CDF5C(12);
  word_1A1342 = sub_C6A43(
                  word_1831D4 + 105,
                  word_1831D6 + 349,
                  word_1831D4 + 205,
                  word_1831D6 + 369,
                  (int)&dword_1A128C,
                  7,
                  (int)&word_1A1366,
                  0,
                  v7,
                  0,
                  v30);
  v8 = (_BYTE *)sub_CDF5C(12);
  v31 = sub_11438B(word_1831D4 + 276, word_1831D6 + 259, word_1831D4 + 343, word_1831D6 + 324, v8, 0);
  v9 = (_BYTE *)sub_CDF5C(12);
  word_1A1346 = sub_C6A43(
                  word_1831D4 + 261,
                  word_1831D6 + 349,
                  word_1831D4 + 361,
                  word_1831D6 + 369,
                  (int)&dword_1A1280,
                  3,
                  (int)&word_1A1360,
                  0,
                  v9,
                  0,
                  v31);
  v22 = (_BYTE *)sub_CDF5C(12);
  v10 = (_WORD *)dword_1A12BC;
  v11 = sub_CDF5C(12);
  sub_11523B(word_1831D4 + 380, word_1831D6 + 295, v11, v10, (int)&word_1A1364, v22, 41);
  v23 = (_BYTE *)sub_CDF5C(12);
  v12 = (_WORD *)dword_1A12C4;
  v13 = sub_CDF5C(12);
  sub_11523B(word_1831D4 + 380, word_1831D6 + 330, v13, v12, (int)&word_1A135A, v23, 41);
  v24 = (_BYTE *)sub_CDF5C(12);
  v14 = (_WORD *)dword_1A12C0;
  v15 = sub_CDF5C(12);
  sub_11523B(word_1831D4 + 380, word_1831D6 + 259, v15, v14, (int)&word_1A135C, v24, 41);
  if ( byte_199F3A == 2 )
  {
    strcpy(&byte_1AB082, &byte_199BF3);
    sub_115BEA(word_1831D4 + 225, word_1831D6 + 394, 168, 18, (int)&byte_1AB082, 8, 0, 0, 0, 0);
  }
  v25 = (_BYTE *)sub_CDF5C(12);
  v16 = (_WORD *)dword_1A12C8;
  v17 = sub_CDF5C(12);
  word_1A1348 = (uint16_t)sub_1151B0(word_1831D4 + 100, word_1831D6 + 386, v17, v16, v25, 40);
  v26 = (_BYTE *)sub_CDF5C(12);
  v18 = (_WORD *)dword_1A12CC;
  v19 = sub_CDF5C(12);
  v20 = (int16_t)(word_1831D6 + 387);
  word_1A134C = (uint16_t)sub_1151B0(word_1831D4 + 418, v20, v19, v18, v26, 40);
  v21 = (_BYTE *)sub_CDF5C(135);
  word_1A134A = sub_114C72(v21, v20);
  JUMPOUT(0xCCC37);
}
// CD35C: control flows out of bounds to CCC37
// 1831D4: using guessed type int16_t word_1831D4;
// 1831D6: using guessed type int16_t word_1831D6;
// 199BF3: using guessed type char byte_199BF3;
// 199F3A: using guessed type char byte_199F3A;
// 1A124C: using guessed type int dword_1A124C[4];
// 1A125C: using guessed type char byte_1A125C;
// 1A1274: using guessed type int dword_1A1274;
// 1A1280: using guessed type int dword_1A1280;
// 1A128C: using guessed type int dword_1A128C;
// 1A12BC: using guessed type int dword_1A12BC;
// 1A12C0: using guessed type int dword_1A12C0;
// 1A12C4: using guessed type int dword_1A12C4;
// 1A12C8: using guessed type int dword_1A12C8;
// 1A12CC: using guessed type int dword_1A12CC;
// 1A12EC: using guessed type int dword_1A12EC;
// 1A133C: using guessed type int16_t word_1A133C;
// 1A133E: using guessed type int16_t word_1A133E;
// 1A1340: using guessed type int16_t word_1A1340;
// 1A1342: using guessed type int16_t word_1A1342;
// 1A1346: using guessed type int16_t word_1A1346;
// 1A1348: using guessed type int16_t word_1A1348;
// 1A134A: using guessed type int16_t word_1A134A;
// 1A134C: using guessed type int16_t word_1A134C;
// 1A1358: using guessed type int16_t word_1A1358;
// 1A135A: using guessed type int16_t word_1A135A;
// 1A135C: using guessed type int16_t word_1A135C;
// 1A135E: using guessed type int16_t word_1A135E;
// 1A1360: using guessed type int16_t word_1A1360;
// 1A1362: using guessed type int16_t word_1A1362;
// 1A1364: using guessed type int16_t word_1A1364;
// 1A1366: using guessed type int16_t word_1A1366;
// 1AB082: using guessed type char byte_1AB082;


//----- (000CD435) --------------------------------------------------------
void __usercall sub_CD435(int16_t *a1)
{
  int v1; // eax
  int v2; // edx
  int v3; // ebx
  int v4; // eax
  int v5; // ecx
  char v6; // dl
  int i; // eax
  int v8; // edx
  int16_t v9; // si
  int v10; // eax
  int v11; // eax
  int v12; // eax
  _DWORD v13[3]; // [esp-4h] [ebp-Ch]

  byte_1A125C[0] = 121;
  byte_1A125D = 123;
  byte_1A125E = 122;
  v1 = 3;
  LOWORD(a1) = word_1A1360;
  do
  {
    v2 = (int16_t)v1++;
    byte_1A125C[v2] = 124;
  }
  while ( (int16_t)v1 < 8 );
  sub_127776((_BYTE *)dword_19306C, 0x1FC8u);
  sub_127776((_BYTE *)dword_1930D4, 0x17E8u);
  sub_127776((_BYTE *)dword_192B18, 0x1608Au);
  sub_127776((_BYTE *)dword_197F9C, 0xFBF4u);
  sub_127776((_BYTE *)dword_197F98, 0x7548u);
  sub_127776((_BYTE *)dword_1930DC, 0xF71u);
  v3 = 255;
  sub_123E6C((int)&unk_1828C0, 1);
  sub_C5BB9();
  sub_1205E6(9, 0, 255);
  v4 = 0;
  v5 = 0;
  v6 = 0;
  do
  {
    *((_BYTE *)&v13[1] + v4++) = v6 - 89;
    v6 += 2;
  }
  while ( v4 < 3 );
  for ( i = 3; i < 8; *((_BYTE *)v13 + i + 3) = 0 )
    ++i;
  if ( (uint8_t)byte_199F3A <= 1u )
  {
    memset(byte_19B814, 0, sizeof(byte_19B814));
    v3 = 14;
    memset(byte_19B848, 0, sizeof(byte_19B848));
  }
  sub_CCA1C();
  word_1A1362 = (uint8_t)byte_199CB0;
  word_1A135E = (uint8_t)byte_199CB2;
  word_1A1358 = (uint8_t)byte_199CB3;
  word_1A1366 = (uint8_t)byte_199CB1 - 2;
  word_1A135C = byte_199CB4 == 0;
  word_1A1360 = (uint8_t)byte_199CB5;
  word_1A1364 = (uint8_t)byte_199BDE;
  word_1A135A = (uint8_t)byte_199CAF;
  sub_C6A26();
  sub_11C2F0();
  sub_CCE2E();
  byte_182ACA = 1;
  sub_124C08();
  sub_CDB72(word_1A1360);
  sub_1191CA((int)sub_CCD3C, 2);
  sub_124D41();
  sub_CCD3C((uint16_t)a1);
  sub_132C80(100);
  sub_131922(0, 255);
  sub_C5C44();
  v8 = 1;
  v9 = 0;
  LOWORD(v10) = sub_123E6C((int)&unk_17CF00, 1);
  while ( !v9 )
  {
    v8 = sub_1171AB(v10, v8, v3, v5);
    v3 = v8;
    sub_C6AA4(v8);
    if ( (_WORD)v8 == word_1A1348 || (_WORD)v8 == word_1A134A )
    {
      LOWORD(v10) = word_199A10;
      v9 = 1;
      word_199A08 = word_199A10;
    }
    if ( (_WORD)v8 == word_1A134C )
    {
      byte_199CB0 = word_1A1362;
      byte_199CB2 = word_1A135E;
      byte_199CB3 = word_1A1358;
      byte_199CB1 = word_1A1366 + 2;
      byte_199CB4 = word_1A135C == 0;
      byte_199CB5 = word_1A1360;
      byte_199BDE = word_1A1364;
      LOBYTE(v10) = word_1A135A;
      byte_199CAF = word_1A135A;
      if ( byte_199F3A == 1 || byte_199F3A == 2 || byte_199F3A == 3 )
      {
        if ( byte_199F3A == 1 )
          word_199A08 = 16;
        else
          word_199A08 = 21;
        v5 = 1;
        v9 = 1;
      }
      else
      {
        sub_5C510(a1);
        v5 = v11;
        if ( (_WORD)v11 == 1 )
        {
          v10 = dword_197F98;
          v9 = v5;
          *(_BYTE *)(dword_197F98 + 40) = 100;
        }
        else
        {
          sub_CCA1C();
          sub_124C08();
          word_1A1362 = (uint8_t)byte_199CB0;
          word_1A135E = (uint8_t)byte_199CB2;
          word_1A1358 = (uint8_t)byte_199CB3;
          byte_182ACA = 1;
          word_1A1366 = (uint8_t)byte_199CB1 - 2;
          word_1A135C = byte_199CB4 == 0;
          word_1A1360 = (uint8_t)byte_199CB5;
          word_1A1364 = (uint8_t)byte_199BDE;
          v8 = 2;
          word_1A135A = (uint8_t)byte_199CAF;
          sub_C6A26();
          sub_11C2F0();
          sub_CCE2E();
          sub_1191CA((int)sub_CCD3C, 2);
          v10 = sub_CDB72(word_1A1360);
        }
      }
    }
    if ( (_WORD)a1 != word_1A1360 )
    {
      LOWORD(a1) = word_1A1360;
      v10 = sub_CDB72(word_1A1360);
    }
    if ( !v9 )
    {
      sub_120BB5(3, (int)byte_1A125C);
      sub_CCD3C((uint16_t)a1);
      v8 = (int)byte_1A125C;
      v12 = sub_120BB5(3, (int)byte_1A125C);
      v10 = sub_1077D(v12, (int)byte_1A125C, v3, a1);
    }
  }
  if ( (_WORD)v5 == 1 )
  {
    byte_199CB0 = word_1A1362;
    byte_199CB2 = word_1A135E;
    byte_199CB3 = word_1A1358;
    byte_199CB1 = word_1A1366 + 2;
    byte_199CB4 = word_1A135C == 0;
    byte_199CB5 = word_1A1360;
    byte_199BDE = word_1A1364;
    byte_199CAF = word_1A135A;
  }
  sub_11C2F0();
  sub_C6A26();
  sub_1196F7();
  sub_119281();
  if ( byte_199F3A == 2 || byte_199F3A == 3 )
  {
    v13[0] = &byte_199BF3;
    strcpy(&byte_199BF3, &byte_1AB082);
  }
  JUMPOUT(0xCCC36);
}
// CD8DC: control flows out of bounds to CCC36
// CD640: variable 'v10' is possibly undefined
// CD727: variable 'v11' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 182ACA: using guessed type char byte_182ACA;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199BDE: using guessed type char byte_199BDE;
// 199BF3: using guessed type char byte_199BF3;
// 199CAF: using guessed type char byte_199CAF;
// 199CB0: using guessed type char byte_199CB0;
// 199CB1: using guessed type char byte_199CB1;
// 199CB2: using guessed type char byte_199CB2;
// 199CB3: using guessed type char byte_199CB3;
// 199CB4: using guessed type char byte_199CB4;
// 199CB5: using guessed type char byte_199CB5;
// 199F3A: using guessed type char byte_199F3A;
// 1A125D: using guessed type char byte_1A125D;
// 1A125E: using guessed type char byte_1A125E;
// 1A1348: using guessed type int16_t word_1A1348;
// 1A134A: using guessed type int16_t word_1A134A;
// 1A134C: using guessed type int16_t word_1A134C;
// 1A1358: using guessed type int16_t word_1A1358;
// 1A135A: using guessed type int16_t word_1A135A;
// 1A135C: using guessed type int16_t word_1A135C;
// 1A135E: using guessed type int16_t word_1A135E;
// 1A1360: using guessed type int16_t word_1A1360;
// 1A1362: using guessed type int16_t word_1A1362;
// 1A1364: using guessed type int16_t word_1A1364;
// 1A1366: using guessed type int16_t word_1A1366;
// 1AB082: using guessed type char byte_1AB082;


//----- (000CD8E5) --------------------------------------------------------
_DWORD *sub_CD8E5()
{
  _DWORD *result; // eax

  dword_1831DC = (int)sub_126B42((int)aColpupsLbx, 0, dword_192ED4);
  dword_1831E0 = (int)sub_126B42((int)aColpupsLbx, 12, dword_192ED4);
  dword_1831E4 = (int)sub_126B42((int)aColpupsLbx, 13, dword_192ED4);
  dword_1831E8 = (int)sub_126B42((int)aColpupsLbx, 14, dword_192ED4);
  result = sub_126B42((int)aColpupsLbx, 15, dword_192ED4);
  dword_1831EC = (int)result;
  return result;
}
// 1831DC: using guessed type int dword_1831DC;
// 1831E0: using guessed type int dword_1831E0;
// 1831E4: using guessed type int dword_1831E4;
// 1831E8: using guessed type int dword_1831E8;
// 1831EC: using guessed type int dword_1831EC;
// 192ED4: using guessed type int dword_192ED4;


//----- (000CD969) --------------------------------------------------------
void *sub_CD969()
{
  bool v0; // eax
  int v1; // eax
  int16_t v2; // ax
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = -1566465889;
  word_1A136C = *(uint8_t *)(dword_192B18
                                   + 361 * *(int16_t *)(dword_1930D4 + 17 * sub_79C54(word_199830, word_199832))
                                   + 303);
  sub_120CCB(1, (int)&v4);
  sub_124DEC();
  sub_CDB60();
  sub_107AF(&dword_1A1368);
  sub_119281();
  v0 = *(_BYTE *)(dword_197F98
                + 3753
                * *(char *)(dword_192B18 + 361 * *(int16_t *)(dword_1930D4 + 17 * sub_79C54(word_199830, word_199832)))
                + 2207) != 4
    && *(_BYTE *)(dword_197F98
                + 3753
                * *(char *)(dword_192B18 + 361 * *(int16_t *)(17 * sub_79C54(word_199830, word_199832) + dword_1930D4))
                + 2207) != 5;
  if ( v0 && (v1 = sub_CDF5C(180), sub_77658(v1), v2) )
    word_1A136C = 0;
  else
    word_1A136C = 3;
  *(_BYTE *)(dword_192B18 + 361 * *(int16_t *)(17 * sub_79C54(word_199830, word_199832) + dword_1930D4) + 303) = word_1A136C;
  sub_1196F7();
  sub_107BA(&dword_1A1368);
  return sub_124E36();
}
// CDA84: variable 'v2' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 1A1368: using guessed type int dword_1A1368;
// 1A136C: using guessed type int16_t word_1A136C;


//----- (000CDAED) --------------------------------------------------------
int __fastcall sub_CDAED(int a1, int a2)
{
  sub_1196F7();
  return sub_1196B8(a1, a2);
}


//----- (000CDB01) --------------------------------------------------------
int sub_CDB01()
{
  sub_1196F7();
  return sub_1196B8((int)&unk_1831F0, 17);
}


//----- (000CDB18) --------------------------------------------------------
void sub_CDB18()
{
  sub_1196F7();
  JUMPOUT(0xCDB11);
}
// CDB28: control flows out of bounds to CDB11


//----- (000CDB2A) --------------------------------------------------------
void sub_CDB2A()
{
  sub_1196F7();
  JUMPOUT(0xCDB11);
}
// CDB3A: control flows out of bounds to CDB11


//----- (000CDB3C) --------------------------------------------------------
void sub_CDB3C()
{
  sub_1196F7();
  JUMPOUT(0xCDB11);
}
// CDB4C: control flows out of bounds to CDB11


//----- (000CDB4E) --------------------------------------------------------
void sub_CDB4E()
{
  sub_1196F7();
  JUMPOUT(0xCDB11);
}
// CDB5E: control flows out of bounds to CDB11


//----- (000CDB60) --------------------------------------------------------
void sub_CDB60()
{
  sub_1196F7();
  JUMPOUT(0xCDB11);
}
// CDB70: control flows out of bounds to CDB11


//----- (000CDB72) --------------------------------------------------------
int __fastcall sub_CDB72( unsigned int a1)
{
  int result; // eax

  sub_1196F7();
  result = sub_1196B8((int)&word_18348E, 11);
  if ( a1 )
  {
    if ( a1 <= 1u )
    {
      word_18348E = 549;
    }
    else if ( a1 == 2 )
    {
      word_18348E = 548;
      return nullsub_11(result);
    }
  }
  else
  {
    word_18348E = 550;
  }
  return result;
}
// CDBC3: using guessed type int __fastcall nullsub_11(_DWORD);
// 18348E: using guessed type int16_t word_18348E;


//----- (000CDBC4) --------------------------------------------------------
void sub_CDBC4()
{
  sub_1196F7();
  JUMPOUT(0xCDB11);
}
// CDBD4: control flows out of bounds to CDB11


//----- (000CDBD9) --------------------------------------------------------
void sub_CDBD9()
{
  sub_1196F7();
  JUMPOUT(0xCDB11);
}
// CDBE9: control flows out of bounds to CDB11


//----- (000CDBEE) --------------------------------------------------------
void sub_CDBEE()
{
  sub_1196F7();
  JUMPOUT(0xCDB11);
}
// CDBFE: control flows out of bounds to CDB11


//----- (000CDC03) --------------------------------------------------------
void sub_CDC03()
{
  sub_1196F7();
  JUMPOUT(0xCDB11);
}
// CDC13: control flows out of bounds to CDB11


//----- (000CDC18) --------------------------------------------------------
void sub_CDC18()
{
  sub_1196F7();
  JUMPOUT(0xCDB11);
}
// CDC28: control flows out of bounds to CDB11


//----- (000CDC2D) --------------------------------------------------------
void sub_CDC2D()
{
  sub_1196F7();
  JUMPOUT(0xCDB11);
}
// CDC3D: control flows out of bounds to CDB11


//----- (000CDC57) --------------------------------------------------------
int __fastcall sub_CDC57(int16_t *a1)
{
  sub_CDC74(a1);
  return a1[6] - a1[5] / 2;
}


//----- (000CDC74) --------------------------------------------------------
int __fastcall sub_CDC74(int16_t *a1)
{
  int v2; // edx
  int v3; // eax
  int result; // eax

  v2 = a1[5] / 2 + a1[4];
  v3 = a1[6];
  if ( v3 > v2 )
    LOWORD(v3) = v2;
  a1[6] = v3;
  result = a1[5] / 2;
  if ( a1[6] >= result )
    result = a1[6];
  a1[6] = result;
  return result;
}


//----- (000CDCAF) --------------------------------------------------------
char __fastcall sub_CDCAF(int16_t *a1)
{
  int16_t v2; // dx
  int v3; // edi
  int16_t v4; // di
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]

  sub_CDC74(a1);
  sub_CDC74(a1);
  v2 = a1[6] - a1[5] / 2;
  if ( a1[5] >= a1[4] )
  {
    v4 = a1[3];
    LOWORD(v8) = a1[1];
  }
  else
  {
    v3 = a1[1];
    v6 = a1[3] - v3;
    v7 = a1[4];
    v8 = v3 + v2 * v6 / v7;
    v4 = v6 * (v2 + a1[5]) / v7 + v3;
  }
  sub_128AB6(0, 0, 639, 479);
  sub_12B634();
  sub_128C32(*a1, (int16_t)v8, a1[2], v4, 229);
  sub_134D2D(*a1, (int16_t)v8, a1[2], (int16_t)v8, 230);
  sub_134D2D(*a1, (int16_t)v8, *a1, v4, 230);
  sub_134D2D(a1[2], (int16_t)v8, a1[2], v4, 228);
  sub_134D2D(*a1, v4, a1[2], v4, 228);
  sub_12972D(*a1, a1[1], 80);
  sub_12972D(a1[2], a1[1], 80);
  sub_12972D(*a1, a1[3], 80);
  return sub_12972D(a1[2], a1[3], 80);
}


//----- (000CDDF7) --------------------------------------------------------
int16_t __fastcall sub_CDDF7(int16_t *a1)
{
  int16_t result; // ax
  int v3; // ebx

  result = a1[4];
  if ( result > a1[5] )
  {
    v3 = a1[4] - a1[5];
    result = sub_CDC57(a1);
    if ( result < v3 )
    {
      ++a1[9];
      return sub_CDC74(a1);
    }
  }
  return result;
}


//----- (000CDE51) --------------------------------------------------------
unsigned int __fastcall sub_CDE51( int a1, int a2, int a3, int a4, int a5, int a6,
        int16_t *a7, int a8, int a9)
{
  unsigned int result; // eax
  int64_t v10; // [esp-Ch] [ebp-10h]

  *a7 = a1;
  a7[4] = a5;
  a7[5] = a6;
  a7[1] = a2;
  a7[2] = a3;
  a7[6] = a6 / 2;
  a7[7] = a6 / 2;
  a7[10] = a8;
  a7[11] = a9;
  a7[3] = a4;
  HIDWORD(v10) = a7 + 6;
  LODWORD(v10) = a7 + 8;
  a7[8] = 0;
  result = sub_114DCA(a1, a2, a3 - a1, a4 - a2, 1, a6 + a5, v10, 40);
  a7[9] = result;
  return result;
}


//----- (000CDED3) --------------------------------------------------------
int16_t __fastcall sub_CDED3(int16_t *a1, int16_t *a2)
{
  int16_t v3; // ax
  int v4; // ecx
  int16_t result; // ax

  if ( *a1 == a2[9] )
  {
    sub_CDC74(a2);
    byte_182ACA = 1;
  }
  if ( *a1 == a2[10] )
  {
    v3 = a2[4];
    if ( v3 > a2[5] )
    {
      v4 = v3 - a2[5];
      if ( (int16_t)sub_CDC57(a2) < v4 )
      {
        ++a2[9];
        sub_CDC74(a2);
      }
    }
    byte_182ACA = 1;
  }
  result = *a1;
  if ( *a1 == a2[11] )
  {
    result = a2[4];
    if ( result > a2[5] )
    {
      result = sub_CDC57(a2);
      if ( result > 0 )
      {
        --a2[9];
        result = sub_CDC74(a2);
      }
    }
    byte_182ACA = 1;
  }
  return result;
}
// 182ACA: using guessed type char byte_182ACA;


//----- (000CDF5C) --------------------------------------------------------
int __fastcall sub_CDF5C( int a1)
{
  return dword_1A6578[a1];
}
// 1A6578: using guessed type int dword_1A6578[368];


//----- (000CDF65) --------------------------------------------------------
int __fastcall sub_CDF65(int a1, int a2, char *a3)
{
  char *v3; // eax
  int i; // edx
  int result; // eax
  _DWORD *v6; // edi
  char *v7; // esi
  _DWORD *v8; // edi
  char *v9; // esi

  switch ( byte_199CAE )
  {
    case 0:
      v3 = (char *)sub_126C91((int)aEstringsLbx, 0, (int)&unk_1A1370, 0, 1u, 21000);
LABEL_13:
      a3 = v3;
      break;
    case 1:
      v3 = (char *)sub_126C91((int)aEstrgermLbx, 0, (int)&unk_1A1370, 0, 1u, 21000);
      goto LABEL_13;
    case 2:
      v3 = (char *)sub_126C91((int)aEstrfrenLbx, 0, (int)&unk_1A1370, 0, 1u, 21000);
      goto LABEL_13;
    case 3:
      v3 = (char *)sub_126C91((int)aEstrspanLbx, 0, (int)&unk_1A1370, 0, 1u, 21000);
      goto LABEL_13;
    case 4:
      v3 = (char *)sub_126C91((int)aEstritalLbx, 0, (int)&unk_1A1370, 0, 1u, 21000);
      goto LABEL_13;
    case 5:
      v3 = (char *)sub_126C91((int)aEstrpoliLbx, 0, (int)&unk_1A1370, 0, 1u, 21000);
      goto LABEL_13;
  }
  for ( i = 0; (unsigned int)(int16_t)i < 0x32C; ++i )
  {
    dword_1A6578[(int16_t)i] = (int)a3;
    a3 += strlen(a3) + 1;
  }
  if ( a3 > (char *)dword_1A6578 )
    sub_126487(aYouBlewTheArra, i);
  result = sub_CE0E5();
  if ( byte_199CAE == 1 )
  {
    v6 = (_DWORD *)dword_1A6B38;
    v7 = aMaingermLbx;
  }
  else if ( byte_199CAE )
  {
    switch ( byte_199CAE )
    {
      case 2:
        v6 = (_DWORD *)dword_1A6B38;
        v7 = aMainfrenLbx;
        break;
      case 3:
        v6 = (_DWORD *)dword_1A6B38;
        v7 = aMainspanLbx;
        break;
      case 4:
        v6 = (_DWORD *)dword_1A6B38;
        v7 = aMainitalLbx;
        break;
      case 5:
        v6 = (_DWORD *)dword_1A6B38;
        v7 = aMainpoliLbx;
        break;
      default:
        return result;
    }
  }
  else
  {
    v6 = (_DWORD *)dword_1A6B38;
    v7 = aMaintextLbx;
  }
  *v6 = *(_DWORD *)v7;
  v9 = v7 + 4;
  v8 = v6 + 1;
  *v8 = *(_DWORD *)v9;
  v9 += 4;
  *++v8 = *(_DWORD *)v9;
  *((_BYTE *)v8 + 4) = v9[4];
  return result;
}
// 199CAE: using guessed type char byte_199CAE;
// 1A6578: using guessed type int dword_1A6578[368];
// 1A6B38: using guessed type int dword_1A6B38;


//----- (000CE0E5) --------------------------------------------------------
int sub_CE0E5()
{
  int result; // eax

  dword_197FA0[0] = sub_CDF5C(616);
  dword_197FA4 = sub_CDF5C(617);
  dword_197FA8 = sub_CDF5C(618);
  dword_197FAC = sub_CDF5C(619);
  dword_197FB0 = sub_CDF5C(620);
  dword_197FB4 = sub_CDF5C(621);
  dword_197FB8 = sub_CDF5C(622);
  dword_192210[0] = sub_CDF5C(623);
  dword_192214 = sub_CDF5C(624);
  dword_192218 = sub_CDF5C(625);
  dword_19221C = sub_CDF5C(626);
  dword_192220 = sub_CDF5C(627);
  dword_192224 = sub_CDF5C(628);
  dword_199150[0] = sub_CDF5C(629);
  dword_199154 = sub_CDF5C(630);
  dword_199158 = sub_CDF5C(631);
  dword_19915C = sub_CDF5C(632);
  dword_199160 = sub_CDF5C(633);
  dword_199164 = sub_CDF5C(634);
  dword_199168 = sub_CDF5C(635);
  dword_192228[0] = sub_CDF5C(636);
  dword_19222C = sub_CDF5C(637);
  dword_192230 = sub_CDF5C(638);
  dword_192234 = sub_CDF5C(639);
  dword_192238 = sub_CDF5C(640);
  dword_19223C = sub_CDF5C(641);
  dword_192240 = sub_CDF5C(642);
  dword_192244 = sub_CDF5C(643);
  dword_192630[0] = sub_CDF5C(645);
  dword_192634 = sub_CDF5C(646);
  dword_192638 = sub_CDF5C(647);
  dword_19263C = sub_CDF5C(648);
  dword_192640 = sub_CDF5C(649);
  dword_192644[0] = sub_CDF5C(650);
  dword_192648 = sub_CDF5C(651);
  dword_19264C = sub_CDF5C(652);
  dword_192650 = sub_CDF5C(653);
  dword_192654 = sub_CDF5C(654);
  dword_192658 = sub_CDF5C(655);
  dword_19265C = sub_CDF5C(656);
  dword_192660 = sub_CDF5C(657);
  dword_192664 = sub_CDF5C(658);
  dword_192668 = sub_CDF5C(659);
  dword_19266C = sub_CDF5C(173);
  dword_192670 = sub_CDF5C(246);
  dword_192674 = sub_CDF5C(272);
  dword_192678 = sub_CDF5C(281);
  dword_19267C = sub_CDF5C(324);
  dword_192C08[0] = sub_CDF5C(142);
  dword_192C0C = sub_CDF5C(660);
  dword_192C10 = sub_CDF5C(661);
  dword_192C14 = sub_CDF5C(662);
  dword_192C18 = sub_CDF5C(663);
  dword_192C1C = sub_CDF5C(664);
  dword_192C20 = sub_CDF5C(665);
  dword_192C24 = sub_CDF5C(666);
  dword_192C28 = sub_CDF5C(667);
  dword_192C2C = sub_CDF5C(668);
  dword_192C30 = sub_CDF5C(669);
  dword_192C34 = sub_CDF5C(670);
  dword_192C38 = sub_CDF5C(671);
  dword_192C3C = sub_CDF5C(672);
  dword_192C40 = sub_CDF5C(673);
  dword_192C44 = sub_CDF5C(674);
  dword_192C48 = sub_CDF5C(675);
  dword_192C58 = sub_CDF5C(676);
  dword_192C5C = sub_CDF5C(677);
  dword_192C60 = sub_CDF5C(678);
  dword_192C64 = sub_CDF5C(679);
  dword_192C68 = sub_CDF5C(680);
  dword_192C6C = sub_CDF5C(681);
  dword_192C70 = sub_CDF5C(682);
  dword_192BE0[0] = sub_CDF5C(683);
  dword_192BE4 = sub_CDF5C(480);
  dword_192BE8 = sub_CDF5C(371);
  dword_192BEC = sub_CDF5C(360);
  dword_192BF0 = sub_CDF5C(323);
  dword_192BF4[0] = sub_CDF5C(684);
  dword_192BF8 = sub_CDF5C(423);
  dword_192BFC = sub_CDF5C(685);
  dword_192C00 = sub_CDF5C(450);
  dword_192C04 = sub_CDF5C(686);
  dword_192C74[0] = sub_CDF5C(687);
  dword_192C78 = sub_CDF5C(688);
  dword_192C7C = sub_CDF5C(689);
  dword_192C4C = sub_CDF5C(690);
  dword_192C50 = sub_CDF5C(691);
  dword_192C54 = sub_CDF5C(692);
  dword_18F9E8 = sub_CDF5C(693);
  dword_18F9EC = sub_CDF5C(694);
  dword_18F9F0 = sub_CDF5C(695);
  dword_18F9F4 = sub_CDF5C(696);
  dword_18F9B8[0] = sub_CDF5C(697);
  dword_18F9BC = sub_CDF5C(698);
  dword_18F9C0 = sub_CDF5C(699);
  dword_18F9C4 = sub_CDF5C(700);
  dword_18F9C8 = sub_CDF5C(701);
  dword_18F9CC = sub_CDF5C(702);
  dword_18F9D0 = sub_CDF5C(703);
  dword_18F9D4 = sub_CDF5C(704);
  dword_18F9D8 = sub_CDF5C(705);
  dword_18F9DC = sub_CDF5C(706);
  dword_18F9E0 = sub_CDF5C(707);
  dword_18F9E4 = sub_CDF5C(708);
  dword_18F968 = sub_CDF5C(709);
  dword_18F96C = sub_CDF5C(710);
  dword_18F970 = sub_CDF5C(711);
  dword_18F974 = sub_CDF5C(712);
  dword_18F978 = sub_CDF5C(713);
  dword_18F97C = sub_CDF5C(714);
  dword_18F980 = sub_CDF5C(715);
  dword_18F984 = sub_CDF5C(716);
  dword_18F988 = sub_CDF5C(717);
  dword_18F98C = sub_CDF5C(718);
  dword_18F990[0] = sub_CDF5C(539);
  dword_18F994 = sub_CDF5C(719);
  dword_18F998 = sub_CDF5C(720);
  dword_18F99C = sub_CDF5C(721);
  dword_18F9A0 = sub_CDF5C(722);
  dword_18F9A4 = sub_CDF5C(399);
  dword_18F9A8 = sub_CDF5C(501);
  dword_18F9AC = sub_CDF5C(184);
  dword_18F9B0 = sub_CDF5C(723);
  dword_18F9B4 = sub_CDF5C(303);
  dword_17D222 = sub_CDF5C(724);
  dword_17D234 = sub_CDF5C(725);
  dword_17D246 = sub_CDF5C(726);
  dword_17D258 = sub_CDF5C(727);
  dword_17D26A = sub_CDF5C(623);
  dword_17D27C = sub_CDF5C(728);
  dword_17D28E = sub_CDF5C(729);
  dword_17D2A0 = sub_CDF5C(730);
  dword_17D2B2 = sub_CDF5C(731);
  dword_17D2C4 = sub_CDF5C(732);
  dword_17D2D6 = sub_CDF5C(733);
  dword_17D2E8 = sub_CDF5C(734);
  dword_17D2FA = sub_CDF5C(735);
  dword_17D30C = sub_CDF5C(736);
  dword_17D31E = sub_CDF5C(737);
  dword_17D330 = sub_CDF5C(738);
  dword_17D342 = sub_CDF5C(739);
  dword_17D354 = sub_CDF5C(740);
  dword_17D366 = sub_CDF5C(741);
  dword_17D378 = sub_CDF5C(742);
  dword_17D38A = sub_CDF5C(743);
  dword_17D39C = sub_CDF5C(744);
  dword_17D3AE = sub_CDF5C(745);
  dword_17D3C0 = sub_CDF5C(746);
  dword_17D3D2 = sub_CDF5C(747);
  dword_17D3E4 = sub_CDF5C(748);
  dword_17D3F6 = sub_CDF5C(749);
  dword_17D408 = sub_CDF5C(750);
  dword_17D41A = sub_CDF5C(751);
  dword_17D42C = sub_CDF5C(752);
  dword_17D43E = sub_CDF5C(753);
  dword_17D450 = sub_CDF5C(754);
  dword_17D462 = sub_CDF5C(755);
  dword_17D474 = sub_CDF5C(756);
  dword_17D486 = sub_CDF5C(757);
  dword_17D498 = sub_CDF5C(758);
  dword_17D4AA = sub_CDF5C(759);
  dword_17D4BC = sub_CDF5C(760);
  dword_17D4CE = sub_CDF5C(761);
  dword_17D4E0 = sub_CDF5C(762);
  dword_17D4F2 = sub_CDF5C(672);
  dword_17D504 = sub_CDF5C(763);
  dword_17D516 = sub_CDF5C(764);
  dword_17D528 = sub_CDF5C(765);
  dword_17D53A = sub_CDF5C(766);
  dword_17D54C = sub_CDF5C(767);
  dword_17D55E = sub_CDF5C(768);
  dword_17D570 = sub_CDF5C(769);
  dword_17D582 = sub_CDF5C(770);
  dword_17D594 = sub_CDF5C(771);
  dword_17D5A6 = sub_CDF5C(772);
  dword_17D5B8 = sub_CDF5C(773);
  dword_17D5CA = sub_CDF5C(774);
  dword_17D5DC = sub_CDF5C(775);
  dword_193130 = sub_CDF5C(731);
  dword_193134 = sub_CDF5C(735);
  dword_193138 = sub_CDF5C(739);
  dword_19313C = sub_CDF5C(745);
  dword_193140 = sub_CDF5C(747);
  dword_193144 = sub_CDF5C(749);
  dword_193148 = sub_CDF5C(761);
  dword_19314C = sub_CDF5C(764);
  dword_193150 = sub_CDF5C(768);
  dword_190430[0] = sub_CDF5C(776);
  dword_190434 = sub_CDF5C(777);
  dword_190438 = sub_CDF5C(778);
  dword_19043C = sub_CDF5C(779);
  dword_190440 = sub_CDF5C(780);
  dword_190444 = sub_CDF5C(781);
  dword_190448[0] = sub_CDF5C(782);
  dword_19044C = sub_CDF5C(783);
  dword_190450 = sub_CDF5C(784);
  dword_190454 = sub_CDF5C(785);
  dword_190458 = sub_CDF5C(786);
  dword_19045C = sub_CDF5C(787);
  result = dword_1A6F88;
  dword_199170 = dword_1A6F88;
  return result;
}
// 17D222: using guessed type int dword_17D222;
// 17D234: using guessed type int dword_17D234;
// 17D246: using guessed type int dword_17D246;
// 17D258: using guessed type int dword_17D258;
// 17D26A: using guessed type int dword_17D26A;
// 17D27C: using guessed type int dword_17D27C;
// 17D28E: using guessed type int dword_17D28E;
// 17D2A0: using guessed type int dword_17D2A0;
// 17D2B2: using guessed type int dword_17D2B2;
// 17D2C4: using guessed type int dword_17D2C4;
// 17D2D6: using guessed type int dword_17D2D6;
// 17D2E8: using guessed type int dword_17D2E8;
// 17D2FA: using guessed type int dword_17D2FA;
// 17D30C: using guessed type int dword_17D30C;
// 17D31E: using guessed type int dword_17D31E;
// 17D330: using guessed type int dword_17D330;
// 17D342: using guessed type int dword_17D342;
// 17D354: using guessed type int dword_17D354;
// 17D366: using guessed type int dword_17D366;
// 17D378: using guessed type int dword_17D378;
// 17D38A: using guessed type int dword_17D38A;
// 17D39C: using guessed type int dword_17D39C;
// 17D3AE: using guessed type int dword_17D3AE;
// 17D3C0: using guessed type int dword_17D3C0;
// 17D3D2: using guessed type int dword_17D3D2;
// 17D3E4: using guessed type int dword_17D3E4;
// 17D3F6: using guessed type int dword_17D3F6;
// 17D408: using guessed type int dword_17D408;
// 17D41A: using guessed type int dword_17D41A;
// 17D42C: using guessed type int dword_17D42C;
// 17D43E: using guessed type int dword_17D43E;
// 17D450: using guessed type int dword_17D450;
// 17D462: using guessed type int dword_17D462;
// 17D474: using guessed type int dword_17D474;
// 17D486: using guessed type int dword_17D486;
// 17D498: using guessed type int dword_17D498;
// 17D4AA: using guessed type int dword_17D4AA;
// 17D4BC: using guessed type int dword_17D4BC;
// 17D4CE: using guessed type int dword_17D4CE;
// 17D4E0: using guessed type int dword_17D4E0;
// 17D4F2: using guessed type int dword_17D4F2;
// 17D504: using guessed type int dword_17D504;
// 17D516: using guessed type int dword_17D516;
// 17D528: using guessed type int dword_17D528;
// 17D53A: using guessed type int dword_17D53A;
// 17D54C: using guessed type int dword_17D54C;
// 17D55E: using guessed type int dword_17D55E;
// 17D570: using guessed type int dword_17D570;
// 17D582: using guessed type int dword_17D582;
// 17D594: using guessed type int dword_17D594;
// 17D5A6: using guessed type int dword_17D5A6;
// 17D5B8: using guessed type int dword_17D5B8;
// 17D5CA: using guessed type int dword_17D5CA;
// 17D5DC: using guessed type int dword_17D5DC;
// 18F968: using guessed type int dword_18F968;
// 18F96C: using guessed type int dword_18F96C;
// 18F970: using guessed type int dword_18F970;
// 18F974: using guessed type int dword_18F974;
// 18F978: using guessed type int dword_18F978;
// 18F97C: using guessed type int dword_18F97C;
// 18F980: using guessed type int dword_18F980;
// 18F984: using guessed type int dword_18F984;
// 18F988: using guessed type int dword_18F988;
// 18F98C: using guessed type int dword_18F98C;
// 18F990: using guessed type int dword_18F990[];
// 18F994: using guessed type int dword_18F994;
// 18F998: using guessed type int dword_18F998;
// 18F99C: using guessed type int dword_18F99C;
// 18F9A0: using guessed type int dword_18F9A0;
// 18F9A4: using guessed type int dword_18F9A4;
// 18F9A8: using guessed type int dword_18F9A8;
// 18F9AC: using guessed type int dword_18F9AC;
// 18F9B0: using guessed type int dword_18F9B0;
// 18F9B4: using guessed type int dword_18F9B4;
// 18F9B8: using guessed type int dword_18F9B8[];
// 18F9BC: using guessed type int dword_18F9BC;
// 18F9C0: using guessed type int dword_18F9C0;
// 18F9C4: using guessed type int dword_18F9C4;
// 18F9C8: using guessed type int dword_18F9C8;
// 18F9CC: using guessed type int dword_18F9CC;
// 18F9D0: using guessed type int dword_18F9D0;
// 18F9D4: using guessed type int dword_18F9D4;
// 18F9D8: using guessed type int dword_18F9D8;
// 18F9DC: using guessed type int dword_18F9DC;
// 18F9E0: using guessed type int dword_18F9E0;
// 18F9E4: using guessed type int dword_18F9E4;
// 18F9E8: using guessed type int dword_18F9E8;
// 18F9EC: using guessed type int dword_18F9EC;
// 18F9F0: using guessed type int dword_18F9F0;
// 18F9F4: using guessed type int dword_18F9F4;
// 190430: using guessed type int dword_190430[];
// 190434: using guessed type int dword_190434;
// 190438: using guessed type int dword_190438;
// 19043C: using guessed type int dword_19043C;
// 190440: using guessed type int dword_190440;
// 190444: using guessed type int dword_190444;
// 190448: using guessed type int dword_190448[];
// 19044C: using guessed type int dword_19044C;
// 190450: using guessed type int dword_190450;
// 190454: using guessed type int dword_190454;
// 190458: using guessed type int dword_190458;
// 19045C: using guessed type int dword_19045C;
// 192210: using guessed type int dword_192210;
// 192214: using guessed type int dword_192214;
// 192218: using guessed type int dword_192218;
// 19221C: using guessed type int dword_19221C;
// 192220: using guessed type int dword_192220;
// 192224: using guessed type int dword_192224;
// 192228: using guessed type int dword_192228[];
// 19222C: using guessed type int dword_19222C;
// 192230: using guessed type int dword_192230;
// 192234: using guessed type int dword_192234;
// 192238: using guessed type int dword_192238;
// 19223C: using guessed type int dword_19223C;
// 192240: using guessed type int dword_192240;
// 192244: using guessed type int dword_192244;
// 192630: using guessed type int dword_192630[];
// 192634: using guessed type int dword_192634;
// 192638: using guessed type int dword_192638;
// 19263C: using guessed type int dword_19263C;
// 192640: using guessed type int dword_192640;
// 192644: using guessed type int dword_192644[];
// 192648: using guessed type int dword_192648;
// 19264C: using guessed type int dword_19264C;
// 192650: using guessed type int dword_192650;
// 192654: using guessed type int dword_192654;
// 192658: using guessed type int dword_192658;
// 19265C: using guessed type int dword_19265C;
// 192660: using guessed type int dword_192660;
// 192664: using guessed type int dword_192664;
// 192668: using guessed type int dword_192668;
// 19266C: using guessed type int dword_19266C;
// 192670: using guessed type int dword_192670;
// 192674: using guessed type int dword_192674;
// 192678: using guessed type int dword_192678;
// 19267C: using guessed type int dword_19267C;
// 192BE0: using guessed type int dword_192BE0[];
// 192BE4: using guessed type int dword_192BE4;
// 192BE8: using guessed type int dword_192BE8;
// 192BEC: using guessed type int dword_192BEC;
// 192BF0: using guessed type int dword_192BF0;
// 192BF4: using guessed type int dword_192BF4[];
// 192BF8: using guessed type int dword_192BF8;
// 192BFC: using guessed type int dword_192BFC;
// 192C00: using guessed type int dword_192C00;
// 192C04: using guessed type int dword_192C04;
// 192C08: using guessed type int dword_192C08;
// 192C0C: using guessed type int dword_192C0C;
// 192C10: using guessed type int dword_192C10;
// 192C14: using guessed type int dword_192C14;
// 192C18: using guessed type int dword_192C18;
// 192C1C: using guessed type int dword_192C1C;
// 192C20: using guessed type int dword_192C20;
// 192C24: using guessed type int dword_192C24;
// 192C28: using guessed type int dword_192C28;
// 192C2C: using guessed type int dword_192C2C;
// 192C30: using guessed type int dword_192C30;
// 192C34: using guessed type int dword_192C34;
// 192C38: using guessed type int dword_192C38;
// 192C3C: using guessed type int dword_192C3C;
// 192C40: using guessed type int dword_192C40;
// 192C44: using guessed type int dword_192C44;
// 192C48: using guessed type int dword_192C48;
// 192C4C: using guessed type int dword_192C4C;
// 192C50: using guessed type int dword_192C50;
// 192C54: using guessed type int dword_192C54;
// 192C58: using guessed type int dword_192C58;
// 192C5C: using guessed type int dword_192C5C;
// 192C60: using guessed type int dword_192C60;
// 192C64: using guessed type int dword_192C64;
// 192C68: using guessed type int dword_192C68;
// 192C6C: using guessed type int dword_192C6C;
// 192C70: using guessed type int dword_192C70;
// 192C74: using guessed type int dword_192C74[];
// 192C78: using guessed type int dword_192C78;
// 192C7C: using guessed type int dword_192C7C;
// 193130: using guessed type int dword_193130;
// 193134: using guessed type int dword_193134;
// 193138: using guessed type int dword_193138;
// 19313C: using guessed type int dword_19313C;
// 193140: using guessed type int dword_193140;
// 193144: using guessed type int dword_193144;
// 193148: using guessed type int dword_193148;
// 19314C: using guessed type int dword_19314C;
// 193150: using guessed type int dword_193150;
// 197FA0: using guessed type int dword_197FA0;
// 197FA4: using guessed type int dword_197FA4;
// 197FA8: using guessed type int dword_197FA8;
// 197FAC: using guessed type int dword_197FAC;
// 197FB0: using guessed type int dword_197FB0;
// 197FB4: using guessed type int dword_197FB4;
// 197FB8: using guessed type int dword_197FB8;
// 199150: using guessed type int dword_199150[];
// 199154: using guessed type int dword_199154;
// 199158: using guessed type int dword_199158;
// 19915C: using guessed type int dword_19915C;
// 199160: using guessed type int dword_199160;
// 199164: using guessed type int dword_199164;
// 199168: using guessed type int dword_199168;
// 199170: using guessed type int dword_199170;
// 1A6F88: using guessed type int dword_1A6F88;


//----- (000CEC99) --------------------------------------------------------
int __fastcall sub_CEC99(int a1, int a2, _WORD *a3)
{
  int16_t v3; // cx
  char *v4; // eax
  _WORD *v5; // eax
  int result; // eax
  _BYTE v8[500]; // [esp+0h] [ebp-1F4h] BYREF

  v3 = 11 * *a3;
  v4 = (char *)sub_CDF5C(75);
  sprintf(v8, v4, &unk_179F43, a1, &unk_179F40, a2);
  sub_BB04E(2u);
  v5 = (_WORD *)sub_127C27((int)aColgcbtLbx, 21, dword_193174);
  result = sub_103BC4(0xBu, v3 + 339, *v5 - 18, (int)v8, 0);
  ++*a3;
  return result;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 193174: using guessed type int dword_193174;


//----- (000CED16) --------------------------------------------------------
int __fastcall sub_CED16(int result, _WORD *a2)
{
  uint8_t *v2; // esi

  v2 = (uint8_t *)result;
  if ( *(_BYTE *)(result + 36) )
    result = sub_CEC99((int)off_17E0EE, *(uint8_t *)(result + 36), a2);
  if ( v2[41] )
    result = sub_CEC99(*(int *)((char *)&off_17E079 + 13 * v2[41]), v2[42], a2);
  if ( v2[43] )
    result = sub_CEC99(*(int *)((char *)&off_17E079 + 13 * v2[43]), v2[44], a2);
  if ( v2[45] )
    return sub_CEC99(*(int *)((char *)&off_17E079 + 13 * v2[45]), v2[46], a2);
  return result;
}
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 17E0EE: using guessed type _UNKNOWN *off_17E0EE;


//----- (000CED9B) --------------------------------------------------------
int16_t __fastcall sub_CED9B(int16_t *a1, _WORD *a2)
{
  int16_t *v2; // esi
  int16_t v4; // dx
  int v5; // eax
  int16_t v6; // dx
  int v7; // eax
  int16_t v8; // dx
  int v9; // eax
  int16_t v10; // dx
  int v11; // eax
  char v13[52]; // [esp+0h] [ebp-34h] BYREF

  v2 = a1;
  if ( *((_BYTE *)a1 + 47) )
  {
    v4 = *((char *)a1 + 47);
    v5 = sub_CDF5C(437);
    LOWORD(a1) = sub_CEC99(v5, v4, a2);
  }
  if ( *((_BYTE *)v2 + 49) )
  {
    v6 = *((char *)v2 + 49);
    v7 = sub_CDF5C(364);
    LOWORD(a1) = sub_CEC99(v7, v6, a2);
  }
  if ( *((_BYTE *)v2 + 50) )
  {
    v8 = *((uint8_t *)v2 + 50);
    v9 = sub_CDF5C(497);
    LOWORD(a1) = sub_CEC99(v9, v8, a2);
  }
  if ( *((char *)v2 + 51) > 0 )
  {
    LOWORD(a1) = IsMemPoolReady_110B5C();
    if ( (_WORD)a1 )
    {
      v10 = *((char *)v2 + 51);
      v11 = sub_CDF5C(123);
      LOWORD(a1) = sub_CEC99(v11, v10, a2);
    }
  }
  if ( *((char *)v2 + 54) > 0 )
  {
    sub_97565(v13, *v2, *((char *)v2 + 54));
    LOWORD(a1) = sub_CEC99((int)v13, v2[26], a2);
  }
  return (int16_t)a1;
}


//----- (000CEE50) --------------------------------------------------------
int64_t __fastcall sub_CEE50(int a1, int a2, int16_t *a3)
{
  int v3; // eax
  int v4; // esi
  char *v5; // eax
  int64_t v6; // rax
  int16_t v7; // ax
  char *v8; // eax
  int64_t v9; // rax
  int16_t *v10; // esi
  int v11; // eax
  char *v12; // eax
  int64_t result; // rax
  int v14; // [esp-8h] [ebp-22Ch]
  int v15; // [esp-4h] [ebp-228h]
  int v16; // [esp-4h] [ebp-228h]
  int v17; // [esp-4h] [ebp-228h]
  int v18; // [esp-4h] [ebp-228h]
  int16_t v19; // [esp+0h] [ebp-224h]
  _BYTE v20[500]; // [esp+4h] [ebp-220h] BYREF
  int v21; // [esp+1F8h] [ebp-2Ch]
  int v22; // [esp+1FCh] [ebp-28h]
  int v23; // [esp+200h] [ebp-24h]
  int v24; // [esp+204h] [ebp-20h]
  int v25; // [esp+208h] [ebp-1Ch]
  int v26; // [esp+20Ch] [ebp-18h]
  int v27; // [esp+210h] [ebp-14h]
  int v28; // [esp+214h] [ebp-10h]
  int v29; // [esp+218h] [ebp-Ch]
  int v30; // [esp+21Ch] [ebp-8h]
  int v31; // [esp+220h] [ebp-4h]

  v30 = 0;
  v31 = 0;
  v3 = 0;
  do
  {
    ++v3;
    ++v31;
  }
  while ( (int16_t)v3 < 3 );
  v29 = 0;
  do
  {
    v4 = (int16_t)v29;
    v26 = sub_BB723(*a3, v29, *(uint8_t *)(dword_197F98 + 3753 * *a3 + 37));
    sub_BAF3C(1u, *(_BYTE *)a3);
    v15 = a3[v4 + 1] - *((char *)a3 + 51);
    v5 = (char *)sub_CDF5C(13);
    v6 = sprintf(v20, v5, v15);
    LODWORD(v6) = *(int16_t *)sub_127C27((int)aColgcbtLbx, SHIDWORD(v6), dword_193174);
    v28 = (int16_t)v31 + 1;
    v22 = (int16_t)v30 + 1;
    v27 = v19;
    sub_1210FD(v19 + (v30 + 1) * ((int)v6 / v28), 465, (int)v20);
    v16 = *((uint8_t *)a3 + v4 + 18);
    if ( *((_BYTE *)a3 + v4 + 18) <= 1u )
      v7 = 22;
    else
      v7 = 23;
    v8 = (char *)sub_CDF5C(v7);
    v9 = sprintf(v20, v8, v16);
    LODWORD(v9) = sub_127C27((int)aColgcbtLbx, SHIDWORD(v9), dword_193174);
    sub_1210FD(v27 + v22 * (*(int16_t *)v9 / v28), 456, (int)v20);
    v23 = *a3;
    v10 = &a3[(int16_t)v29];
    v17 = sub_BB695(v23, v29);
    v14 = v10[5];
    LODWORD(v9) = sub_CDF5C(14);
    sprintf(v20, (char *)v9, v14, v17);
    v25 = 447;
    v11 = *(int16_t *)sub_127C27((int)aColgcbtLbx, 21, dword_193174);
    v23 = (int16_t)v31 + 1;
    v21 = (int16_t)v30 + 1;
    v24 = v19;
    sub_1210FD(v19 + (v30 + 1) * (v11 / v23), v25, (int)v20);
    sub_127C27((int)aColgcbtLbx, 21, dword_193174);
    sub_C5D55();
    v18 = v10[5];
    v12 = (char *)sub_CDF5C(124);
    ++v30;
    ++v29;
    result = sprintf(v20, v12, v18);
  }
  while ( (int16_t)v29 < 3 );
  return result;
}
// CEF10: variable 'v19' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 193174: using guessed type int dword_193174;
// 197F98: using guessed type int dword_197F98;


//----- (000CF0AC) --------------------------------------------------------
unsigned int sub_CF0AC()
{
  sub_C5560(word_19999C);
  return sub_11438B(0, 0, 639, 479, byte_179F46, 0);
}
// 179F46: using guessed type _BYTE byte_179F46[2];
// 19999C: using guessed type int16_t word_19999C;


//----- (000CF0D9) --------------------------------------------------------
void *sub_CF0D9()
{
  void *result; // eax
  _WORD *v1; // eax
  int16_t v2; // ax
  int16_t v3[28]; // [esp+0h] [ebp-3Ch] BYREF
  int v4; // [esp+38h] [ebp-4h] BYREF

  result = (void *)sub_BAEFE();
  if ( byte_182ACA )
  {
    byte_182ACA = 1;
    sub_107C2(dword_1A722C);
    v1 = (_WORD *)sub_127C27((int)aColgcbtLbx, 21, dword_193174);
    sub_1298DE(3, 330, *v1 + 1, 473);
    dword_183550 = sub_127C27((int)aColgcbtLbx, 21, dword_193174);
    sub_12A478(2, 329, dword_183550);
    v4 = 0;
    v2 = sub_79C54(word_199830, word_199832);
    sub_ED713((char *)(361 * *(int16_t *)(17 * v2 + dword_1930D4) + dword_192B18), (int)v3);
    sub_CED16((int)v3, &v4);
    sub_CED9B(v3, &v4);
    sub_CEE50(2, (int16_t)(11 * ++v4 + 339), v3);
    ++v4;
    result = sub_124DEC();
    byte_182ACA = 0;
  }
  return result;
}
// 182ACA: using guessed type char byte_182ACA;
// 183550: using guessed type int dword_183550;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 193174: using guessed type int dword_193174;
// 199830: using guessed type int16_t word_199830;
// 199832: using guessed type int16_t word_199832;
// 1A722C: using guessed type int (*dword_1A722C[2])(void);


//----- (000CF1E0) --------------------------------------------------------
int __usercall sub_CF1E0(int a1, int a2, int16_t *a3)
{
  int v3; // edx
  unsigned int v4; // eax
  int v5; // eax
  unsigned int v6; // eax

  byte_182ACA = 1;
  sub_120CCB(1, (int)&unk_182C2E);
  v3 = 1;
  sub_107AF(dword_1A722C);
  sub_119281();
  sub_1191CA((int)sub_CF0D9, 1);
  sub_CDB4E();
  sub_CF0D9();
  sub_124C08();
  sub_11C2F0();
  v4 = sub_CF0AC();
  v5 = sub_1077D(v4, 1, a2, a3);
  do
  {
    v3 = sub_1171AB(v5, v3, a2, a1);
    sub_CF0D9();
    sub_11C2F0();
    v6 = sub_CF0AC();
    v5 = sub_1077D(v6, v3, a2, a3);
  }
  while ( !(_WORD)v3 );
  sub_11C2F0();
  sub_1196F7();
  sub_119281();
  return sub_107BA((int *)dword_1A722C);
}
// 182ACA: using guessed type char byte_182ACA;
// 1A722C: using guessed type int (*dword_1A722C[2])(void);


//----- (000CF26E) --------------------------------------------------------
_BOOL1 __fastcall sub_CF26E( int a1, int16_t *a2, int a3, char *a4)
{
  int v5; // eax
  uint8_t *v6; // edi
  uint8_t *v7; // esi
  int16_t v8; // bx
  uint8_t v10[56]; // [esp+0h] [ebp-66h] BYREF
  _BYTE v11[56]; // [esp+38h] [ebp-2Eh] BYREF
  _BYTE v12[55]; // [esp+70h] [ebp+Ah] BYREF
  int16_t v13[28]; // [esp+A8h] [ebp+42h] BYREF
  int v14; // [esp+E0h] [ebp+7Ah]
  char v15; // [esp+E4h] [ebp+7Eh]

  sub_EC831(a2, a3, a4, v13, (int)v10);
  v5 = 11 * a1 + dword_1AA3E0;
  v15 = 0;
  if ( *(int16_t *)(v5 + 8) > 0 )
  {
    v13[6] += 4 * *(_WORD *)(v5 + 8);
    LOBYTE(v13[11]) = 1;
    v13[6] -= 2;
  }
  if ( v13[6] > 0 )
  {
    qmemcpy(v12, v13, sizeof(v12));
    v6 = v11;
    v7 = v10;
    v14 = 10;
    v8 = 0;
    while ( 1 )
    {
      qmemcpy(v6, v7, 0x37u);
      if ( (int16_t)v14 <= 0 || v8 >= 7 || v8 + (int16_t)v14 < 7 )
        break;
      --v14;
      sub_EC601((uint8_t *)v13, v10);
      if ( LOBYTE(v13[11]) < 4u )
        ++v8;
      qmemcpy(v13, v12, 0x37u);
      v6 = v10;
      v7 = v11;
    }
    return v8 >= 7;
  }
  return v15;
}
// 1AA3E0: using guessed type int dword_1AA3E0;


//----- (000CF34C) --------------------------------------------------------
char __fastcall sub_CF34C(int a1, int16_t *a2, int a3, int a4)
{
  _BYTE v5[56]; // [esp+0h] [ebp-74h] BYREF
  int16_t v6[28]; // [esp+38h] [ebp-3Ch] BYREF
  char v7; // [esp+70h] [ebp-4h]

  v7 = 0;
  sub_EC831(a2, a3, (char *)(361 * a4 + dword_192B18), v6, (int)v5);
  if ( v6[6] )
    return 1;
  return v7;
}
// 192B18: using guessed type int dword_192B18;


//----- (000CF398) --------------------------------------------------------
char *__fastcall sub_CF398( int a1)
{
  if ( a1 == -37 )
    return aAiTradeGoods;
  else
    return sub_B2FFA(a1);
}


//----- (000CF3BD) --------------------------------------------------------
int __fastcall sub_CF3BD( int a1)
{
  int v1; // ebx
  int v2; // edx
  int v3; // eax
  int v4; // edx
  int result; // eax

  v1 = a1;
  v2 = dword_197F98 + 3753 * a1;
  v3 = 3 * a1;
  LOWORD(v2) = *(_WORD *)(v2 + 56);
  LOWORD(v3) = (uint8_t)byte_1A7236[v3];
  v4 = v2 - v3;
  byte_1A724C[v1] = 0;
  result = v4;
  if ( (v4 & 0x8000u) != 0 )
  {
    result = (4 - (int16_t)v4) / 5;
    byte_1A724C[v1] = result;
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (000CF40D) --------------------------------------------------------
int __fastcall sub_CF40D( int a1)
{
  int v2; // ecx
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // edx
  int v7; // eax
  int16_t *v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // edx
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int64_t v16; // rax
  int v17; // eax
  int v18; // edi
  int v19; // eax
  int v20; // eax
  int v21; // edx
  signed int v22; // esi
  int v23; // eax
  _BOOL1 v24; // cl
  int v26; // [esp+0h] [ebp-54h]
  int v27; // [esp+4h] [ebp-50h]
  int v28; // [esp+14h] [ebp-40h]
  int v29; // [esp+18h] [ebp-3Ch]
  int v30; // [esp+1Ch] [ebp-38h]
  int v31; // [esp+20h] [ebp-34h]
  int v32; // [esp+24h] [ebp-30h]
  int v33; // [esp+28h] [ebp-2Ch]
  int v34; // [esp+2Ch] [ebp-28h]
  int v35; // [esp+30h] [ebp-24h]
  int v36; // [esp+34h] [ebp-20h]
  int v37; // [esp+38h] [ebp-1Ch]
  int v38; // [esp+3Ch] [ebp-18h]
  int v39; // [esp+40h] [ebp-14h]
  int v40; // [esp+44h] [ebp-10h]
  int v41; // [esp+48h] [ebp-Ch]
  _BOOL1 v42; // [esp+4Ch] [ebp-8h]

  v2 = word_199998;
  v42 = *(_BYTE *)(dword_197F98 + 3753 * a1 + 40) == 1;
  v28 = 3753 * word_199998;
  v3 = 3 * word_199998;
  v41 = 0;
  v34 = 0;
  v27 = 0;
  v38 = 0;
  v33 = 0;
  v29 = 0;
  v40 = 0;
  v37 = 0;
  v35 = word_199998;
  v31 = 0;
  v36 = 2 * word_199998;
  v4 = 14 * word_199998;
  while ( v2 > 0 )
  {
    v28 -= 3753;
    --v35;
    v36 -= 2;
    v3 -= 3;
    --v2;
    v4 -= 14;
    if ( v2 != a1
      && (!*(_WORD *)(58 * a1 + dword_1AA204 + 12) && *(_BYTE *)(v28 + dword_197F98 + 40) == 100
       || *(_BYTE *)(v2 + dword_1AA204 + 58 * a1 + 14)) )
    {
      v32 = (uint8_t)byte_1A7274[v36];
      v27 += v32;
      ++v41;
      if ( v34 < v32 )
        v34 = (uint8_t)byte_1A7274[v36];
      v33 += dword_1A7454[v3];
      if ( v38 < dword_1A7454[v3] )
        v38 = dword_1A7454[v3];
      if ( v29 < dword_1A7254[v35] )
        v29 = dword_1A7254[v35];
      if ( v40 < (uint8_t)byte_1A7284[v36] )
        v40 = (uint8_t)byte_1A7284[v36];
      if ( v37 < dword_1A72C8[v4] )
        v37 = dword_1A72C8[v4];
      v39 = 9;
      v5 = v4 * 4 + 36;
      do
      {
        v5 -= 4;
        --v39;
        if ( *(int *)((char *)&dword_1A7294 + v5) && v31 < v39 )
          v31 = v39;
      }
      while ( v39 > 0 );
    }
  }
  dword_1A72B8[14 * a1] = v31 + 1;
  if ( v38 < dword_1A7454[3 * a1] || !*(_WORD *)(dword_1AA204 + 58 * a1 + 12) )
    dword_1A72B8[14 * a1] += sub_1247A0(2u) - 1 + v42;
  if ( !v41 )
    v41 = 1;
  v6 = dword_197F98;
  byte_1A7275[2 * a1] = 0;
  if ( *(_BYTE *)(v6 + 3753 * a1 + 468) == 3 && dword_1A72C8[14 * a1] > 1 )
  {
    v30 = (*(int16_t *)(dword_1AA204 + 58 * a1) + 2) / 3;
    v7 = (v34 + v27 / v41 + 1) / 2;
    if ( (uint8_t)byte_1A7274[2 * a1] < v7 )
      byte_1A7275[2 * a1] = v7 - byte_1A7274[2 * a1];
    v8 = (int16_t *)(dword_1AA204 + 58 * a1);
    if ( v8[6] > 0 )
    {
      v9 = v42 + v8[6];
      v10 = sub_134C92(*v8) + v9;
      v11 = (uint8_t)byte_1A7274[2 * a1];
      if ( v11 < v10 )
      {
        v12 = v10 - v11;
        if ( (uint8_t)byte_1A7275[2 * a1] < v12 )
          byte_1A7275[2 * a1] = v12;
      }
    }
    if ( (uint8_t)byte_1A7274[2 * a1] < 0x14u )
    {
      if ( (uint8_t)byte_1A7275[2 * a1] > v30 )
      {
        byte_1A7275[2 * a1] = v30;
        if ( !*(_WORD *)(58 * a1 + dword_1AA204 + 12) )
          byte_1A7275[2 * a1] = (int)(uint8_t)byte_1A7275[2 * a1] >> 2;
      }
    }
    else
    {
      byte_1A7275[2 * a1] = 0;
    }
    if ( (uint8_t)byte_1A7275[2 * a1] > 1u
      && *(_WORD *)(dword_197F98 + 3753 * a1 + 58) < *(_WORD *)(dword_197F98 + 3753 * a1 + 60) )
    {
      byte_1A7275[2 * a1] = 1;
    }
  }
  if ( v42 )
    v13 = v38;
  else
    v13 = (v38 + v33 / v41 + 1) / 2;
  v14 = 3 * a1;
  dword_1A745C[v14] = 0;
  if ( v13 > dword_1A7454[v14] )
  {
    dword_1A745C[3 * a1] = v13 - dword_1A7454[3 * a1];
    if ( !*(_WORD *)(58 * a1 + dword_1AA204 + 12) )
      dword_1A745C[3 * a1] /= 2;
  }
  if ( dword_1A745C[3 * a1] && (v15 = 3753 * a1 + dword_197F98, *(_WORD *)(v15 + 58) <= *(_WORD *)(v15 + 60)) )
  {
    if ( *(int *)(v15 + 50) >= 50 && *(int16_t *)(v15 + 178) >= 50 )
    {
      if ( *(int16_t *)(v15 + 178) < 1024 )
      {
        v16 = dword_1A745C[3 * a1] * sub_134C92(*(int16_t *)(v15 + 178));
        dword_1A745C[3 * a1] = (int)(v16 - (__CFSHL__(HIDWORD(v16), 5) + 32 * HIDWORD(v16))) >> 5;
        if ( !(uint16_t)sub_D1006(a1) )
        {
          v17 = sub_134C92(dword_1A745C[3 * a1]);
          dword_1A745C[3 * a1] = (v17 - (__CFSHL__(v17 >> 31, 4) + 16 * (v17 >> 31))) >> 4;
        }
      }
    }
    else
    {
      dword_1A745C[3 * a1] = 0;
    }
  }
  else if ( *(int16_t *)(dword_1AA204 + 58 * a1 + 12) > 0 && sub_1247A0(10 - v42) == 1 )
  {
    dword_1A745C[3 * a1] += 4 * v42 + 1;
  }
  v18 = dword_197F98 + 3753 * a1;
  if ( *(int16_t *)(v18 + 178) < 1024 )
  {
    if ( v37 < dword_1A72C8[14 * a1] )
    {
      v20 = v37 * dword_1A745C[3 * a1] / dword_1A72C8[14 * a1];
LABEL_68:
      dword_1A745C[3 * a1] = v20;
    }
  }
  else if ( dword_1A745C[3 * a1] < 10 && dword_1A72C4[14 * a1] )
  {
    v19 = dword_1A7458[3 * a1] / dword_1A72C4[14 * a1];
    v26 = *(int16_t *)(v18 + 58);
    if ( dword_1A72C0[14 * a1] >= v26 )
      v20 = *(int16_t *)(v18 + 178) * v19 / 15;
    else
      v20 = (v26 - dword_1A72C0[14 * a1]) * v19;
    goto LABEL_68;
  }
  byte_1A7285[2 * a1] = 0;
  if ( dword_1A7454[3 * a1] > 0 )
  {
    v21 = 63 - sub_1026CF(a1, a1);
    if ( *(int16_t *)(dword_1AA204 + 58 * a1 + 10) > 0 && v21 > 0 )
    {
      if ( (uint8_t)byte_1A7284[2 * a1] < v40 )
        byte_1A7285[2 * a1] = v40 - byte_1A7284[2 * a1];
      if ( (uint8_t)byte_1A7284[2 * a1] < v40 + 2 )
      {
        v22 = *(char *)(dword_197F98 + 3753 * a1 + 2216);
        if ( (int)sub_1247A0(0x64u) <= v22 )
          ++byte_1A7285[2 * a1];
      }
      if ( !*(_BYTE *)(3753 * a1 + dword_197F98 + 40) && sub_1247A0(2u) == 1 )
        ++byte_1A7285[2 * a1];
      if ( byte_1A7285[2 * a1] )
      {
        v23 = 3753 * a1 + dword_197F98;
        if ( *(int16_t *)(58 * a1 + dword_1AA204 + 10) * (2 * (*(_BYTE *)(v23 + 2216) > 0) + 2) < (uint8_t)byte_1A7284[2 * a1] )
        {
          if ( (uint8_t)byte_1A7285[2 * a1] <= 1u )
          {
            v24 = *(char *)(v23 + 2216) > 0 || sub_1247A0(4u) == 1;
            byte_1A7285[2 * a1] = v24;
          }
          else
          {
            byte_1A7285[2 * a1] = sub_134C92((uint8_t)byte_1A7285[2 * a1]);
          }
        }
      }
      if ( v21 < (uint8_t)byte_1A7285[2 * a1] )
        byte_1A7285[2 * a1] = v21;
    }
  }
  if ( !byte_1A7234[3 * a1] )
    byte_1A7235[3 * a1] = 1;
  return sub_CF3BD(a1);
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 1A7254: using guessed type int dword_1A7254[];
// 1A7294: using guessed type int dword_1A7294;
// 1A72B8: using guessed type int dword_1A72B8[];
// 1A72C0: using guessed type int dword_1A72C0[];
// 1A72C4: using guessed type int dword_1A72C4[];
// 1A72C8: using guessed type int dword_1A72C8[99];
// 1A7454: using guessed type int dword_1A7454[];
// 1A7458: using guessed type int dword_1A7458[];
// 1A745C: using guessed type int dword_1A745C[22];
// 1AA204: using guessed type int dword_1AA204;


//----- (000CFAE5) --------------------------------------------------------
void __fastcall sub_CFAE5(int a1)
{
  int v2; // edx
  int v3; // esi
  int v4; // eax
  int v5; // edi
  unsigned int v6; // edx
  int v7; // [esp+0h] [ebp-38h]
  int v8; // [esp+4h] [ebp-34h]
  int v9; // [esp+Ch] [ebp-2Ch]
  int v10; // [esp+10h] [ebp-28h]
  unsigned int v11; // [esp+14h] [ebp-24h]
  int v12; // [esp+18h] [ebp-20h]
  int v13; // [esp+1Ch] [ebp-1Ch]
  int v14; // [esp+20h] [ebp-18h]
  int v15; // [esp+24h] [ebp-14h]
  int v16; // [esp+28h] [ebp-10h]
  unsigned int v17; // [esp+2Ch] [ebp-Ch]
  int v18; // [esp+30h] [ebp-8h]
  int v19; // [esp+34h] [ebp-4h]

  v2 = 16 * ((a1 - dword_197F9C) / 129);
  if ( *(_WORD *)(dword_1AA204 + 58 * *(char *)(a1 + 99) + 12) )
  {
    v4 = word_199998;
    v9 = v2;
    v8 = 0;
    v17 = -1;
    v19 = 0;
    v12 = 0;
    v11 = -1;
    v7 = 3753 * word_199998;
    v18 = 0;
    v14 = 2 * word_199998;
    while ( v4 > 0 )
    {
      v7 -= 3753;
      --v4;
      v5 = *(char *)(a1 + 99);
      v14 -= 2;
      if ( v4 != v5 && !*(_BYTE *)(v7 + dword_197F98 + 36) && *(_BYTE *)(58 * v5 + dword_1AA204 + v4 + 14) )
      {
        v6 = *(uint16_t *)(v14 + v9 + dword_1AA1DC);
        if ( *(_BYTE *)(v7 + dword_197F98 + 40) == 100 )
        {
          v8 += v6;
          if ( v6 < v17 )
            v17 = *(uint16_t *)(v14 + v9 + dword_1AA1DC);
          ++v19;
        }
        else
        {
          v12 += v6;
          if ( v6 < v11 )
            v11 = *(uint16_t *)(v14 + v9 + dword_1AA1DC);
          ++v18;
        }
      }
    }
  }
  else
  {
    v3 = word_199998;
    v10 = 0;
    v15 = 0;
    v13 = 3753 * word_199998;
    v16 = 2 * word_199998;
    while ( v3 > 0 )
    {
      v13 -= 3753;
      --v3;
      v16 -= 2;
      if ( v3 != *(char *)(a1 + 99)
        && !*(_BYTE *)(v13 + dword_197F98 + 36)
        && *(_BYTE *)(v13 + dword_197F98 + 40) == 100 )
      {
        ++v10;
        v15 += *(uint16_t *)(v16 + v2 + dword_1AA1DC);
      }
    }
  }
  JUMPOUT(0xCFADE);
}
// CFCB1: control flows out of bounds to CFADE
// CFC74: conditional instruction was optimized away because %var_4.4!=0
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;
// 1AA1DC: using guessed type int dword_1AA1DC;
// 1AA204: using guessed type int dword_1AA204;


//----- (000CFCB6) --------------------------------------------------------
int __usercall sub_CFCB6(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // edx
  int v5; // eax
  _BYTE *v6; // ebx
  int v7; // edx
  int16_t v8; // ax
  int v9; // edx
  int16_t v10; // ax
  int v11; // ebx
  int v12; // edx
  int v13; // eax
  int16_t v14; // si
  int16_t v15; // cx
  int result; // eax
  int16_t i; // cx

  sub_FE8BE(a1, a2, a3, a4);
  memset(dword_1A7454, 0, 96);
  memset(dword_1A7294, 0, 448);
  memset(dword_1A7254, 0, 32);
  memset(byte_1A7234, 0, 24);
  v4 = 0;
  memset(byte_1A7274, 0, 16);
  v5 = 129 * word_199994;
  v6 = (_BYTE *)(v5 + dword_197F9C);
  while ( (unsigned int)v6 > dword_197F9C )
  {
    v6 -= 129;
    if ( ((char)v6[100] < 5 || v6[100] == 6) && (char)v6[99] < 8 )
    {
      LOBYTE(v5) = v6[17];
      if ( (_BYTE)v5 )
      {
        if ( (uint8_t)v5 <= 1u )
        {
          v5 = 3 * (char)v6[99];
          ++byte_1A7234[v5];
          if ( v6[100] == 2 || v6[100] == 1 )
          {
            v5 = 3 * (char)v6[99];
            ++byte_1A7236[v5];
          }
        }
        else if ( (uint8_t)v5 <= 2u )
        {
          v5 = (char)v6[99];
          ++byte_1A7274[2 * v5];
        }
      }
      else
      {
        v7 = 3 * (char)v6[99];
        sub_CFAE5((int)v6);
        dword_1A7454[v7] += v8;
        if ( v6[100] != 6 )
        {
          v9 = 3 * (char)v6[99];
          sub_CFAE5((int)v6);
          dword_1A7458[v9] += v10;
        }
        ++dword_1A7294[14 * (char)v6[99] + (uint8_t)v6[16]];
        dword_1A72C8[14 * (char)v6[99]] += (uint8_t)byte_CF38F[(uint8_t)v6[16]];
        v4 = (uint8_t)v6[16] + 1;
        dword_1A72C0[14 * (char)v6[99]] += v4;
        v5 = 56 * (char)v6[99];
        ++*(int *)((char *)&dword_1A72BC + v5);
        if ( v6[100] != 6 )
        {
          v5 = 56 * (char)v6[99];
          v4 = (uint8_t)v6[16] + 1;
          *(int *)((char *)dword_1A72C4 + v5) += v4;
        }
      }
    }
  }
  sub_FE8BE(v5, v4, (int)v6, a4);
  v11 = 16;
  v12 = 0;
  v13 = memset(byte_1A7284, 0, 16);
  v14 = word_199998;
  while ( v14 > 0 )
  {
    v15 = word_199998;
    --v14;
    while ( v15 > 0 )
    {
      v12 = --v15;
      v11 = v14;
      LOWORD(v13) = sub_1026CF(v14, v15);
      byte_1A7284[2 * v14] += v13;
    }
  }
  sub_FE8BE(v13, v12, v11, a4);
  for ( i = word_199998; i > 0; result = sub_CF40D(i) )
    --i;
  return result;
}
// CFD7E: variable 'v8' is possibly undefined
// CFD99: variable 'v10' is possibly undefined
// CFE8A: variable 'v13' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199998: using guessed type int16_t word_199998;
// 1A7254: using guessed type int dword_1A7254[];
// 1A7294: using guessed type int dword_1A7294[];
// 1A72BC: using guessed type int dword_1A72BC;
// 1A72C0: using guessed type int dword_1A72C0[];
// 1A72C4: using guessed type int dword_1A72C4[];
// 1A72C8: using guessed type int dword_1A72C8[99];
// 1A7454: using guessed type int dword_1A7454[];
// 1A7458: using guessed type int dword_1A7458[];


//----- (000CFEAB) --------------------------------------------------------
void __fastcall sub_CFEAB(char *a1, int a2)
{
  int16_t i; // bx
  char v4; // al

  for ( i = 1; i < 49; ++i )
  {
    sub_E11BC(a1, i);
    if ( v4 == 1 )
      *(_WORD *)(a2 + 2 * i) = 1;
  }
}
// CFEC6: variable 'v4' is possibly undefined


//----- (000CFEDC) --------------------------------------------------------
int __fastcall sub_CFEDC(int a1)
{
  return *(int16_t *)(a1 + 233) + ((int)*(uint8_t *)(a1 + 10) >> 3) - *(uint8_t *)(a1 + 240);
}


//----- (000CFF02) --------------------------------------------------------
char __fastcall sub_CFF02(char *a1)
{
  char *v1; // edx
  unsigned int v3; // ebx
  int v4; // ebx
  uint8_t v5; // bl

  v1 = &a1[4 * (uint8_t)a1[10] + 12];
  while ( 1 )
  {
    if ( a1 + 12 >= v1 )
      return 0;
    v1 -= 4;
    v3 = *(_DWORD *)v1 & 0xF;
    if ( v3 < 8 && v3 != *a1 )
    {
      v4 = 3753 * v3 + dword_197F98;
      if ( !*(_BYTE *)(v4 + 36) )
      {
        v5 = *(_BYTE *)(*a1 + v4 + 1575);
        if ( v5 >= 4u && v5 <= 6u )
          break;
      }
    }
  }
  return 1;
}
// 197F98: using guessed type int dword_197F98;


//----- (000D0036) --------------------------------------------------------
int __fastcall sub_D0036(char *a1, int a2)
{
  int v3; // edi
  char v4; // al
  int v5; // ebx
  int v6; // eax
  uint8_t *v7; // esi
  _BOOL1 v8; // al
  _BOOL1 v9; // ah
  int v10; // ebx
  int v11; // eax
  _BOOL1 v12; // zf
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  _BOOL1 v16; // zf
  int v17; // ebx
  int v18; // ebx
  int v19; // eax
  int v20; // ebx
  int v21; // eax
  int v22; // eax
  bool v23; // ebx
  int v24; // ebx
  char v25; // al
  int v26; // ecx
  int16_t v27; // ax
  _BOOL1 v28; // zf
  int v29; // ebx
  int v30; // eax
  int v31; // eax
  int v32; // eax
  char v33; // al
  char v34; // cl
  int v36; // [esp+4h] [ebp-40h]
  bool v37; // [esp+8h] [ebp-3Ch]
  int v38; // [esp+Ch] [ebp-38h]
  int v39; // [esp+10h] [ebp-34h]
  bool v40; // [esp+18h] [ebp-2Ch]
  int v41; // [esp+1Ch] [ebp-28h]
  int v42; // [esp+20h] [ebp-24h]
  int v43; // [esp+24h] [ebp-20h]
  bool v44; // [esp+28h] [ebp-1Ch]
  int v45; // [esp+2Ch] [ebp-18h]
  int v46; // [esp+30h] [ebp-14h]
  char v47; // [esp+3Ch] [ebp-8h]
  uint8_t v48; // [esp+40h] [ebp-4h]

  v41 = *a1;
  v46 = (int)&a1[-dword_192B18] / 361;
  v3 = dword_197F98 + 3753 * v41;
  v4 = *(_BYTE *)(v3 + 40);
  v5 = 0;
  v44 = v4 == 5;
  v40 = v4 == 4;
  v43 = v4 == 1;
  v37 = v4 == 3;
  if ( *(int *)(v3 + 50) >= 1500 )
    v6 = sub_134C92((int)(*(int16_t *)(v3 + 178)
                        - (__CFSHL__((uint64_t)*(int16_t *)(v3 + 178) >> 32, 6)
                         + ((uint64_t)*(int16_t *)(v3 + 178) >> 32 << 6))) >> 6);
  else
    v6 = 0;
  v45 = v6;
  v39 = *(uint8_t *)(17 * *((int16_t *)a1 + 1) + dword_1930D4 + 2);
  v38 = 17 * *((int16_t *)a1 + 1) + dword_1930D4;
  v7 = (uint8_t *)(dword_1AA1F8 + 49 * v39 + 1 + 6 * v41);
  v48 = *(_BYTE *)(7 * v46 + dword_1AA1EC + 4) + *(_BYTE *)(7 * v46 + dword_1AA1EC + 3);
  v42 = 7 * v46 + dword_1AA1EC;
  v8 = !a1[317] && *(_BYTE *)(v3 + 301) == 3 && *(_BYTE *)(v38 + 10) <= 2u;
  v47 = 0;
  if ( v45 > 10 )
    v45 = 10;
  if ( (unsigned int)(*(char *)(dword_197F98 + 3753 * v41 + 2207) / 2) <= 1
    && (!a1[332] && *(_BYTE *)(v3 + 382) == 3 || !a1[312] && *(_BYTE *)(v3 + 293) == 3) )
  {
    v47 = 1;
  }
  v9 = v8 || v47;
  v36 = 7 * v46;
  switch ( a2 )
  {
    case 2:
      if ( (uint8_t)a1[10] >= 3u || v45 )
      {
        v5 = v7[1] + 2 * *(uint8_t *)(7 * v46 + dword_1AA1EC + 5) + *v7 + 3 * v7[2] + v7[3];
        if ( v5 )
          v5 += v43;
      }
      if ( !a1[332] && (unsigned int)(*(char *)(3753 * v41 + dword_197F98 + 2207) / 2) <= 1 )
        v5 += 6;
      if ( sub_CFF02(a1) )
        ++v5;
      goto LABEL_87;
    case 3:
      if ( v9 && !*(_BYTE *)(dword_1AA1EC + 7 * v46 + 5) )
        goto LABEL_61;
      if ( (((int)*(uint8_t *)(dword_19306C + 113 * v39 + 57) >> v41) & 1) != 0 )
        goto LABEL_87;
      v20 = v7[1] + *v7 + 10 * *(uint8_t *)(dword_1AA1EC + 7 * v46 + 5);
      v21 = 3 * v7[2];
      goto LABEL_85;
    case 4:
      v5 = 5;
      goto LABEL_61;
    case 5:
    case 32:
      goto LABEL_116;
    case 6:
      if ( !v9 && !*(_BYTE *)(v3 + 1437) )
        v5 = 4 * v37 + 11;
      goto LABEL_61;
    case 7:
      v23 = v40;
      v22 = (uint8_t)a1[10] + 13;
      goto LABEL_107;
    case 8:
      if ( v9 && !*(_BYTE *)(dword_1AA1EC + 7 * v46 + 5) )
        goto LABEL_61;
      v11 = 3 * *v7 + 10 * *(uint8_t *)(dword_1AA1EC + 7 * v46 + 5) + 6 * v7[1];
      v10 = 12 * v7[2];
      goto LABEL_25;
    case 9:
      if ( *(char *)(dword_197F98 + 3753 * v41 + 2207) / 2 != 3 && *(_WORD *)(v3 + 41) == *((_WORD *)a1 + 1) )
        v5 = 100;
      goto LABEL_61;
    case 10:
      if ( v9 )
        goto LABEL_61;
      if ( *(char *)(v3 + 2208) < 0 )
        v5 = v44;
      goto LABEL_87;
    case 12:
      v5 = 4 * v40;
      v22 = (uint8_t)a1[10] + 12;
      goto LABEL_173;
    case 13:
      if ( v9 )
        goto LABEL_61;
LABEL_116:
      if ( !v48 )
        goto LABEL_61;
      if ( *((int16_t *)a1 + 4) <= 5 )
        goto LABEL_61;
      v5 = v44;
      if ( *((int16_t *)a1 + 4) <= 10 )
        goto LABEL_61;
      v22 = sub_134C92(*((int16_t *)a1 + 4));
      goto LABEL_173;
    case 15:
      if ( !v9 )
        v5 = v44 + 18;
      goto LABEL_61;
    case 16:
      if ( *(_BYTE *)(v42 + 2) )
      {
        if ( *(int16_t *)(v3 + 176) >= 0 )
          v24 = 4;
        else
          v24 = 8;
        v5 = v44 + v24;
      }
      goto LABEL_61;
    case 17:
      v5 = v44;
      goto LABEL_60;
    case 19:
      if ( !v9 && !*(_BYTE *)(v3 + 1437) )
        v5 = 11;
      goto LABEL_61;
    case 20:
      if ( *(char *)(3753 * v41 + dword_197F98 + 2207) / 2 != 3
        && ((uint8_t)a1[10] >= 3u || v45 && (uint8_t)a1[10] >= 2u) )
      {
        v5 = 10;
      }
      goto LABEL_61;
    case 21:
      if ( !*(_BYTE *)(v42 + 2) )
        goto LABEL_61;
      v25 = a1[221];
      if ( v25 )
      {
        if ( (uint8_t)v25 <= 1u )
        {
          v5 = 11;
        }
        else if ( v25 == 2 )
        {
          v5 = 10;
        }
        else
        {
          v5 = 6;
        }
      }
      else
      {
        v5 = 12;
      }
      if ( *(int16_t *)(v3 + 176) < 0 )
        v5 -= *(int16_t *)(v3 + 176);
      v22 = 4 * v44;
      goto LABEL_173;
    case 22:
      if ( (uint8_t)a1[10] >= 2u || v45 )
      {
        v5 = 2 * v7[3] + 6 * v7[2] + 3 * v7[1] + *v7 + 5 * *(uint8_t *)(7 * v46 + dword_1AA1EC + 5);
        if ( v5 )
          v5 += v43;
      }
      if ( !a1[312] && (unsigned int)(*(char *)(dword_197F98 + 3753 * v41 + 2207) / 2) <= 1 )
        v5 += 12;
      if ( sub_CFF02(a1) )
        v5 += 3;
      goto LABEL_60;
    case 23:
      if ( v9 && !*(_BYTE *)(7 * v46 + dword_1AA1EC + 5) )
        goto LABEL_61;
      v14 = 12 * v7[2] + 4 * v7[1] + *v7 + 10 * *(uint8_t *)(dword_1AA1EC + 7 * v46 + 5);
      v13 = 2 * v7[3];
      goto LABEL_55;
    case 24:
      if ( v9 && !*(_BYTE *)(7 * v46 + dword_1AA1EC + 5) )
        goto LABEL_61;
      v13 = 4 * v7[1] + 10 * *(uint8_t *)(dword_1AA1EC + 7 * v46 + 5) + *v7 + 12 * v7[2];
      v14 = 2 * v7[3];
      goto LABEL_55;
    case 25:
      v26 = 17 * *((int16_t *)a1 + 1);
      v27 = *(uint8_t *)(v26 + dword_1930D4 + 6);
      if ( *(_BYTE *)(v3 + 2218) )
      {
        if ( *(_BYTE *)(v26 + dword_1930D4 + 6) )
          goto LABEL_61;
        goto LABEL_144;
      }
      if ( *(_BYTE *)(v3 + 2217) )
        v28 = v27 == 1;
      else
        v28 = v27 == 0;
      if ( v28 )
      {
LABEL_144:
        v5 = v44 + 3;
        goto LABEL_61;
      }
      if ( v27 == 2 )
        v5 = v44 + 6;
LABEL_61:
      if ( v5 <= 0 )
        return 0;
      if ( v5 > 1000 )
        return 1000;
      return v5;
    case 26:
      if ( v9 && !*(_BYTE *)(dword_1AA1EC + 7 * v46 + 5) )
        goto LABEL_61;
      v17 = 10 * *(uint8_t *)(dword_1AA1EC + 7 * v46 + 5);
      goto LABEL_78;
    case 27:
    case 42:
      if ( !v9 )
        goto LABEL_77;
      v16 = *(_BYTE *)(dword_1AA1EC + 7 * v46 + 5) == 0;
      goto LABEL_76;
    case 28:
      if ( v9 && !*(_BYTE *)(7 * v46 + dword_1AA1EC + 5) )
        goto LABEL_61;
      v13 = 8 * v7[1] + 4 * *v7 + 10 * *(uint8_t *)(dword_1AA1EC + 7 * v46 + 5) + 12 * v7[2];
      v14 = 4 * v7[3];
LABEL_55:
      v5 = v13 + v14;
      if ( v5 )
        v5 += v43;
      if ( *(_BYTE *)(v38 + 8) != 1 )
        goto LABEL_60;
      v15 = 2 * v44;
      goto LABEL_59;
    case 29:
      if ( v9 || (uint8_t)a1[10] < 5u )
        goto LABEL_61;
      v29 = (uint8_t)a1[10];
      v30 = *(uint8_t *)(v42 + 1);
      goto LABEL_154;
    case 30:
      if ( !v9 && !*(_BYTE *)(v3 + 1437) )
        v5 = 3 * v37 + 8;
      goto LABEL_61;
    case 31:
      if ( *(char *)(dword_197F98 + 3753 * v41 + 2207) / 2 != 3
        && ((uint8_t)a1[10] >= 3u || v45 && (uint8_t)a1[10] >= 2u) )
      {
        v5 = 16;
      }
      goto LABEL_61;
    case 33:
      v5 = (2 * (uint8_t)a1[10] + *(uint8_t *)(v42 + 1)) / 3;
      v32 = v40 + v44 + v48;
      goto LABEL_172;
    case 34:
      v5 = 2 * v40 + 12;
      goto LABEL_61;
    case 35:
      if ( !v9 && !*(_BYTE *)(v3 + 1437) )
        v5 = 2 * v37 + 5;
      goto LABEL_61;
    case 36:
      v23 = v40;
      v22 = (uint8_t)a1[10] + 5;
LABEL_107:
      v5 = 2 * v23;
      goto LABEL_173;
    case 37:
      if ( v9 || !*(_BYTE *)(v42 + 2) || !a1[221] )
        goto LABEL_61;
      if ( *(int16_t *)(v3 + 176) < 0 )
        goto LABEL_169;
      v5 = 3;
      goto LABEL_171;
    case 38:
      if ( v9 || *(int16_t *)(a1 + 233) < 17 && (uint8_t)a1[10] < 5u && !v45 )
        goto LABEL_61;
      v31 = sub_134C92(*(int16_t *)(a1 + 233) - 15);
      goto LABEL_155;
    case 39:
      if ( v9 || (uint8_t)a1[10] < 3u )
        goto LABEL_61;
      v30 = (uint8_t)a1[10];
      v29 = *(uint8_t *)(v42 + 1);
LABEL_154:
      v31 = (v40 + v29 + v30) / 3;
LABEL_155:
      v5 = v31;
      goto LABEL_61;
    case 40:
      if ( v9 && !*(_BYTE *)(dword_1AA1EC + 7 * v46 + 5) )
        goto LABEL_61;
      v10 = 8 * v7[1] + 4 * *v7 + 10 * *(uint8_t *)(dword_1AA1EC + 7 * v46 + 5);
      v11 = 16 * v7[2];
      goto LABEL_25;
    case 41:
      if ( v9 && !*(_BYTE *)(dword_1AA1EC + 7 * v46 + 5) )
        goto LABEL_61;
      v10 = 6 * v7[1] + 3 * *v7 + 10 * *(uint8_t *)(dword_1AA1EC + 7 * v46 + 5);
      v11 = 12 * v7[2];
LABEL_25:
      v5 = 3 * v7[3] + v11 + v10;
      if ( *(_WORD *)(v3 + 58) <= *(_WORD *)(v3 + 60) )
        v5 += *(int16_t *)(v3 + 60) + 1 - *(int16_t *)(v3 + 58);
      v12 = v5 == 0;
      goto LABEL_79;
    case 43:
      if ( v9 || !*(_BYTE *)(v42 + 2) )
        goto LABEL_61;
      v33 = a1[221];
      if ( v33 )
      {
        if ( (uint8_t)v33 <= 1u )
        {
          v5 = 12;
        }
        else if ( v33 == 2 )
        {
          v5 = 10;
        }
        else
        {
          v5 = 7;
        }
      }
      else
      {
        v5 = 13;
      }
      if ( *(int16_t *)(v3 + 176) < 0 )
        v5 -= *(int16_t *)(v3 + 176);
      v22 = 3 * v44;
      goto LABEL_173;
    case 44:
      if ( v9 )
        goto LABEL_61;
      v34 = 1;
      switch ( *(_BYTE *)(v38 + 8) )
      {
        case 2:
          v5 = 2;
          break;
        case 3:
        case 7:
          goto LABEL_198;
        case 4:
          if ( *(_BYTE *)(v3 + 2219) )
LABEL_198:
            v5 = 1;
          break;
        case 5:
          if ( !*(_BYTE *)(v3 + 2219) )
            v5 = 4;
          break;
        case 6:
          if ( !*(_BYTE *)(v3 + 2219) )
            v5 = 6;
          break;
        default:
          v34 = 0;
          break;
      }
      if ( v34 )
      {
        v15 = 3 * v44;
LABEL_59:
        v5 += v15;
      }
      goto LABEL_60;
    case 45:
      if ( v9 && !*(_BYTE *)(v36 + dword_1AA1EC + 5) )
        goto LABEL_61;
      if ( (((int)*(uint8_t *)(dword_19306C + 113 * v39 + 57) >> v41) & 1) == 0 )
      {
        v20 = 3 * v7[1] + 2 * *v7 + 5 * *(uint8_t *)(dword_1AA1EC + 7 * v46 + 5);
        v21 = 4 * v7[2];
LABEL_85:
        v5 = v20 + v21 + v7[3];
        if ( v5 )
          v5 += v43;
      }
LABEL_87:
      v22 = v45 / 2;
      goto LABEL_173;
    case 46:
      if ( v9 || !*(_BYTE *)(v42 + 2) || !a1[221] )
        goto LABEL_61;
      if ( *(int16_t *)(v3 + 176) >= 0 )
LABEL_169:
        v5 = 5;
      else
        v5 = 10;
LABEL_171:
      v32 = v44;
LABEL_172:
      v22 = 2 * v32;
LABEL_173:
      v5 += v22;
      goto LABEL_61;
    case 47:
      if ( !v9 )
        goto LABEL_77;
      v16 = *(_BYTE *)(v36 + dword_1AA1EC + 5) == 0;
LABEL_76:
      if ( !v16 )
      {
LABEL_77:
        v17 = 10 * *(uint8_t *)(dword_1AA1EC + 7 * v46 + 5);
LABEL_78:
        v18 = 16 * v7[2] + 8 * v7[1] + 4 * *v7 + v17;
        v19 = 4 * v7[3];
        v12 = v19 + v18 == 0;
        v5 = v19 + v18;
LABEL_79:
        if ( !v12 )
          v5 += v43;
LABEL_60:
        v5 += v45;
      }
      goto LABEL_61;
    default:
      goto LABEL_61;
  }
}
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 1AA1EC: using guessed type int dword_1AA1EC;
// 1AA1F8: using guessed type int dword_1AA1F8;


//----- (000D0B08) --------------------------------------------------------
void __fastcall sub_D0B08(char *a1)
{
  int16_t v2; // si
  int16_t v3; // bx
  char v4; // al
  int16_t *v5; // ebx
  int v6; // edi
  int16_t v7; // ax
  int16_t *v8; // eax
  int v9; // edi
  int v10; // edx
  int v11; // eax
  int16_t v12; // ax
  int16_t v13; // bx
  int16_t v14[49]; // [esp+0h] [ebp-70h] BYREF
  _WORD v15[2]; // [esp+62h] [ebp-Eh] BYREF
  char v16; // [esp+66h] [ebp-Ah] BYREF
  char *v17; // [esp+68h] [ebp-8h]
  int16_t *v18; // [esp+6Ch] [ebp-4h]

  memset(v14, 0, 102);
  v17 = a1;
  v2 = 0;
  v3 = 1;
  v18 = v14;
  while ( 1 )
  {
    sub_E11BC(v17, v3);
    if ( v4 == 1 )
      v18[v3] = 1;
    if ( ++v3 >= 49 )
    {
      v5 = v15;
      v6 = 98;
      while ( v5 > v14 )
      {
        --v5;
        v6 -= 2;
        if ( *v5 > 0 )
        {
          v7 = sub_D0036(a1, v6 >> 1);
          *v5 = v7;
          if ( v2 < v7 )
            v2 = v7;
        }
      }
      v15[1] = 1;
      if ( v2 < 1 )
        v2 = 1;
      v8 = (int16_t *)&v16;
      while ( v8 > v14 )
      {
        v9 = (uint8_t)byte_199CB0;
        --v8;
        if ( *(_BYTE *)(3753 * *a1 + dword_197F98 + 40) == 100 )
          v9 = 4;
        if ( *v8 * (6 - v9) < v2 )
          *v8 = 0;
      }
      v10 = *(uint8_t *)(7 * ((int)&a1[-dword_192B18] / 361) + dword_1AA1EC + 1);
      v11 = (uint8_t)a1[10];
      if ( 3 * v11 <= v10 )
        v15[0] = sub_134C92(3 * (v10 - v11));
      v12 = sub_FE92D((int)v14, 51);
      v13 = v12;
      if ( v12 >= 49 )
      {
        if ( v12 == 49 )
        {
          *(_WORD *)(a1 + 277) = -3;
        }
        else if ( v12 == 50 )
        {
          *(_WORD *)(a1 + 277) = -2;
        }
      }
      else
      {
        sub_B206F((int)&a1[-dword_192B18] / 361, v12);
        *(_WORD *)(a1 + 277) = v13;
      }
      JUMPOUT(0xCFADE);
    }
  }
}
// D0C52: control flows out of bounds to CFADE
// D0B41: variable 'v4' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;
// 1AA1EC: using guessed type int dword_1AA1EC;


//----- (000D0C7F) --------------------------------------------------------
int __fastcall sub_D0C7F(uint8_t *a1, uint8_t *a2)
{
  return (int16_t)(*(_WORD *)(dword_192B18 + 361 * *a1 + 233)
                 + ((int)*(uint8_t *)(dword_192B18 + 361 * *a1 + 10) >> 3)
                 - *(uint8_t *)(dword_192B18 + 361 * *a1 + 240))
       - (int16_t)(((int)*(uint8_t *)(dword_192B18 + 361 * *a2 + 10) >> 3)
                 + *(_WORD *)(dword_192B18 + 361 * *a2 + 233)
                 - *(uint8_t *)(dword_192B18 + 361 * *a2 + 240));
}
// 192B18: using guessed type int dword_192B18;


//----- (000D0CF2) --------------------------------------------------------
int __fastcall sub_D0CF2(int a1, int a2, _DWORD *a3, int a4)
{
  uint8_t *v5; // eax

  v5 = (uint8_t *)(a2 + a1);
  *(_WORD *)(361 * *v5 + dword_192B18 + 277) = a4;
  return memmove(v5, a1 + a2 + 1, --*a3 - a2);
}
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;


//----- (000D0D2F) --------------------------------------------------------
void __fastcall sub_D0D2F(int16_t *a1)
{
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // ebx
  int16_t *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  _WORD v17[250]; // [esp+0h] [ebp-214h] BYREF
  int v18; // [esp+1F4h] [ebp-20h]
  int v19; // [esp+1F8h] [ebp-1Ch]
  int v20; // [esp+1FCh] [ebp-18h]
  int v21; // [esp+200h] [ebp-14h]
  int v22; // [esp+204h] [ebp-10h]
  int v23; // [esp+208h] [ebp-Ch]
  int v24; // [esp+20Ch] [ebp-8h]
  char v25; // [esp+210h] [ebp-4h]

  HIWORD(v2) = HIWORD(dword_197F98);
  v3 = dword_197F98 + 3753 * (int16_t)a1;
  LOWORD(v2) = *(_WORD *)(v3 + 180);
  v4 = 3 * *(_DWORD *)(v3 + 50);
  v24 = v2;
  v5 = (v4 - (__CFSHL__(v4 >> 31, 2) + 4 * (v4 >> 31))) >> 2;
  v6 = v5;
  if ( v5 <= 1500 )
  {
    if ( v5 < 50 )
      v6 = 50;
  }
  else
  {
    v6 = 1500;
  }
  while ( 1 )
  {
    v25 = 0;
    v23 = 0;
    HIWORD(v7) = 0;
    v22 = 0;
    memset(v17, 0, sizeof(v17));
    LOWORD(v7) = word_199996;
    while ( (int16_t)v7 > 0 )
    {
      v8 = (int16_t *)(dword_192B18 + 361 * (int16_t)--v7);
      if ( *(char *)v8 == (_WORD)a1
        && !v8[150]
        && (((int)*(uint8_t *)(dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * v8[1] + 2) + 42) >> (char)a1)
          & 1) == 0
        && *(uint16_t *)((char *)v8 + 277) < 0xFFFDu )
      {
        sub_E1085(dword_192B18 + 361 * (int16_t)v7);
        v21 = v9;
        v19 = v9;
        if ( v9 > 0 )
        {
          v10 = dword_197F98 + 3753 * (int16_t)a1;
          v20 = (int16_t)v24;
          if ( (int16_t)v24 + v21 < *(_DWORD *)(v10 + 50)
            && (*(_BYTE *)(dword_1AA1EC + 7 * (int16_t)v7 + 5) || v6 <= *(_DWORD *)(v10 + 50) - v21 - v20) )
          {
            v11 = (int16_t)sub_E0FA4(dword_192B18 + 361 * (int16_t)v7);
            if ( (unsigned int)(int16_t)v11 > 0x32 )
              v11 = 50;
            v12 = 1000 * v11 * v11 / (v19 * v19);
            if ( (unsigned int)(v12 + 1) >= 0xFFFF )
              v17[(int16_t)v7] = -1;
            else
              v17[(int16_t)v7] = v12 + 1;
            v13 = 2 * (int16_t)v7;
            if ( *(_BYTE *)(dword_1AA1EC + 7 * (int16_t)v7 + 5) )
            {
              v25 = 1;
              if ( (uint16_t)v23 < v17[(int16_t)v7] )
              {
                LOWORD(v13) = v17[(int16_t)v7];
                v23 = v13;
              }
            }
            else if ( (uint16_t)v22 < v17[(int16_t)v7] )
            {
              LOWORD(v13) = v17[(int16_t)v7];
              v22 = v13;
            }
          }
        }
      }
    }
    if ( (_WORD)v22 || (_WORD)v23 )
    {
      LOWORD(v7) = word_199996;
      v14 = dword_1AA1EC;
      while ( (int16_t)v7 > 0 )
      {
        if ( v17[(int16_t)--v7] )
        {
          if ( v25 )
          {
            if ( !*(_BYTE *)(v14 + 7 * (int16_t)v7 + 5)
              || 4 * (uint16_t)v17[(int16_t)v7] < 3 * (uint16_t)v23 )
            {
              v17[(int16_t)v7] = 0;
            }
          }
          else
          {
            v18 = 4 * (uint16_t)v17[(int16_t)v7];
            if ( 3 * (uint16_t)v22 > v18 )
              v17[(int16_t)v7] = 0;
          }
        }
      }
    }
    v15 = sub_FE92D((int)v17, word_199996);
    v16 = (int16_t)v15;
    if ( (int16_t)v15 != -1 )
      v16 = sub_E109D(v15);
    sub_FE8BE(v16, v15, v7, a1);
    if ( (int16_t)v15 == -1 )
      JUMPOUT(0xCFADE);
  }
}
// D1001: control flows out of bounds to CFADE
// D0E34: variable 'v9' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 1AA1EC: using guessed type int dword_1AA1EC;


//----- (000D1006) --------------------------------------------------------
int __fastcall sub_D1006( int a1)
{
  int16_t v2; // bx
  int result; // eax
  int v4; // edx
  uint8_t v5; // dl

  v2 = word_199998;
  result = 0;
  while ( v2 > 0 )
  {
    if ( a1 != --v2 )
    {
      v4 = v2 + dword_197F98 + 3753 * a1;
      if ( *(_BYTE *)(v4 + 1412) )
      {
        v5 = *(_BYTE *)(v4 + 1575);
        if ( v5 < 5u )
        {
          if ( v5 == 4 && (int16_t)result < 1 )
            result = 1;
        }
        else if ( v5 <= 5u )
        {
          if ( (int16_t)result < 2 )
            result = 2;
        }
        else if ( v5 == 6 && (int16_t)result < 3 )
        {
          result = 3;
        }
      }
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000D108B) --------------------------------------------------------
int __fastcall sub_D108B( int a1, int a2, int a3)
{
  int v3; // ebx
  int v5; // [esp+0h] [ebp-4h] BYREF

  v5 = word_18001E[18 * *(uint8_t *)(a3 + 16)] / 2;
  v3 = 2 * (*(int16_t *)(a3 + 94) - *(int16_t *)(a2 + 94));
  sub_6E1A0(a1, &v5);
  if ( v3 < v5 )
    return v5;
  return v3;
}
// 18001E: using guessed type int16_t word_18001E[];


//----- (000D10EE) --------------------------------------------------------
void __usercall sub_D10EE( int a1, int16_t *a2)
{
  int v2; // edx
  int v3; // ecx
  int v4; // ebx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // ebx
  int v9; // esi
  int v10; // edi
  int v11; // ecx
  bool v12; // eax
  int v13; // eax
  uint16_t v14; // ax
  uint16_t v15; // ax
  _BOOL1 v16; // zf
  int v17; // eax
  bool v18; // eax
  int v19; // eax
  int v20; // ecx
  char v21; // al
  int v22; // edx
  uint8_t *v23; // eax
  int v24; // ebx
  char v25; // al
  int v26; // edx
  uint8_t *v27; // esi
  uint8_t *v28; // edx
  int v29; // eax
  int v30; // esi
  int v31; // esi
  char v32; // al
  int v33; // ebx
  int v34; // ebx
  char v35; // al
  char v36; // al
  int v37; // edx
  int v38; // esi
  uint8_t *v39; // ebx
  uint8_t *v40; // edx
  char v41; // al
  char v42; // al
  char v43; // al
  int v44; // eax
  int v45; // ebx
  int v46; // ecx
  int v47; // edx
  int v48; // ecx
  int v49; // ebx
  int v50; // edx
  int v51; // eax
  uint8_t *v52; // eax
  int v53; // edx
  int v54; // eax
  uint8_t *v55; // eax
  int v56; // ebx
  int v57; // ebx
  _BYTE *v58; // edx
  int v59; // edx
  uint8_t *v60; // eax
  unsigned int v61; // eax
  int v62; // edx
  int v63; // eax
  int v64; // eax
  int16_t v65; // ax
  int (__fastcall *v66)(uint8_t *, uint8_t *); // kr04_4
  int v67; // edx
  int16_t v68; // ax
  int v69; // esi
  int v70; // edx
  unsigned int v71; // eax
  int16_t v72; // ax
  int16_t v73; // ax
  int16_t v74; // ax
  int16_t v75; // ax
  int v76; // eax
  int v77; // ebx
  uint8_t *v78; // eax
  int v79; // eax
  int16_t v80; // ax
  int v81; // eax
  int v82; // esi
  int v83; // edx
  uint8_t *v84; // eax
  int v85; // ebx
  int v86; // ebx
  uint8_t *v87; // eax
  int v88; // eax
  int v89; // edx
  int v90; // ebx
  uint8_t *v91; // eax
  int v92; // ebx
  uint8_t *v93; // eax
  int v94; // ebx
  uint8_t *v95; // eax
  int v96; // edx
  int v97; // eax
  uint8_t v98; // al
  int16_t *v99; // esi
  int v100; // eax
  int16_t v101; // ax
  int v102; // ebx
  int v103; // esi
  uint8_t *v104; // eax
  int v105; // ecx
  int16_t *v106; // eax
  int v107; // esi
  uint8_t *v108; // eax
  int v109; // edx
  int (__fastcall *v110)(uint8_t *, uint8_t *); // ebx
  int v111; // eax
  int v112; // edx
  uint8_t *v113; // eax
  int v114; // ebx
  int (__fastcall *v115)(uint8_t *, uint8_t *); // ebx
  int v116; // ebx
  uint8_t *v117; // eax
  int v118; // edx
  int v119; // [esp+0h] [ebp-1D6h]
  uint8_t v120[252]; // [esp+4h] [ebp-1D2h] BYREF
  _WORD v121[50]; // [esp+100h] [ebp-D6h] BYREF
  int v122; // [esp+164h] [ebp-72h] BYREF
  unsigned int v123; // [esp+168h] [ebp-6Eh]
  int v124; // [esp+16Ch] [ebp-6Ah]
  int v125; // [esp+170h] [ebp-66h]
  unsigned int v126; // [esp+174h] [ebp-62h]
  int v127; // [esp+178h] [ebp-5Eh]
  int16_t v128; // [esp+17Ch] [ebp-5Ah] BYREF
  int16_t v129; // [esp+17Eh] [ebp-58h]
  int16_t v130; // [esp+180h] [ebp-56h]
  int16_t v131; // [esp+182h] [ebp-54h]
  int16_t v132; // [esp+184h] [ebp-52h]
  int16_t v133; // [esp+186h] [ebp-50h]
  int16_t v134; // [esp+188h] [ebp-4Eh]
  int16_t v135; // [esp+18Ah] [ebp-4Ch]
  int16_t v136; // [esp+18Ch] [ebp-4Ah]
  int v137; // [esp+190h] [ebp-46h]
  int v138; // [esp+194h] [ebp-42h]
  int v139; // [esp+198h] [ebp-3Eh]
  int v140; // [esp+19Ch] [ebp-3Ah]
  int16_t *v141; // [esp+1A0h] [ebp-36h]
  int v142; // [esp+1A4h] [ebp-32h]
  int v143; // [esp+1A8h] [ebp-2Eh]
  int v144; // [esp+1ACh] [ebp-2Ah]
  int16_t *v145; // [esp+1B0h] [ebp-26h]
  int v146; // [esp+1B4h] [ebp-22h]
  _BYTE *v147; // [esp+1B8h] [ebp-1Eh]
  int v148; // [esp+1BCh] [ebp-1Ah]
  int v149; // [esp+1C0h] [ebp-16h]
  int v150; // [esp+1C4h] [ebp-12h]
  int v151; // [esp+1C8h] [ebp-Eh]
  unsigned int v152; // [esp+1CCh] [ebp-Ah]
  int v153; // [esp+1D0h] [ebp-6h]
  int v154; // [esp+1D4h] [ebp-2h]
  int v155; // [esp+1D8h] [ebp+2h]
  int v156; // [esp+1DCh] [ebp+6h]
  int v157; // [esp+1E0h] [ebp+Ah]
  int v158; // [esp+1E4h] [ebp+Eh]
  int v159; // [esp+1E8h] [ebp+12h]
  int v160; // [esp+1ECh] [ebp+16h]
  int v161; // [esp+1F0h] [ebp+1Ah]
  int v162; // [esp+1F4h] [ebp+1Eh]
  int v163; // [esp+1F8h] [ebp+22h]
  int16_t *v164; // [esp+1FCh] [ebp+26h]
  int v165; // [esp+200h] [ebp+2Ah]
  int v166; // [esp+204h] [ebp+2Eh]
  int v167; // [esp+208h] [ebp+32h]
  int v168; // [esp+20Ch] [ebp+36h]
  int16_t *v169; // [esp+210h] [ebp+3Ah]
  int v170; // [esp+214h] [ebp+3Eh]
  int v171; // [esp+218h] [ebp+42h]
  int v172; // [esp+21Ch] [ebp+46h]
  int16_t *v173; // [esp+220h] [ebp+4Ah]
  int v174; // [esp+224h] [ebp+4Eh]
  int v175; // [esp+228h] [ebp+52h]
  int v176; // [esp+22Ch] [ebp+56h]
  int v177; // [esp+230h] [ebp+5Ah]
  int v178; // [esp+234h] [ebp+5Eh]
  char v179; // [esp+238h] [ebp+62h]
  char v180; // [esp+23Ch] [ebp+66h]
  char v181; // [esp+240h] [ebp+6Ah]
  char v182; // [esp+244h] [ebp+6Eh]
  char v183; // [esp+248h] [ebp+72h]
  char v184; // [esp+24Ch] [ebp+76h]
  char v185; // [esp+250h] [ebp+7Ah]
  _BOOL1 v186; // [esp+254h] [ebp+7Eh]

  v2 = 3753 * a1;
  v142 = v2 + dword_197F98;
  v4 = 3002 * a1;
  v139 = 0;
  v3 = dword_1AA1C4;
  v140 = (int16_t)sub_D1006(a1);
  v185 = 0;
  v141 = (int16_t *)(v4 + v3);
  LOBYTE(v4) = *(_BYTE *)(v2 + dword_197F98 + 40) == 1;
  v5 = *(int16_t *)(v142 + 178);
  v6 = v5 + *(_DWORD *)(v142 + 50);
  LOBYTE(v6) = v6 < *(_DWORD *)(v142 + 180);
  v184 = v6;
  if ( (_BYTE)v6 || *(int *)(v142 + 50) < 1500 )
  {
    v7 = 0;
  }
  else
  {
    v6 = v5 >> 31 << 6;
    v7 = sub_134C92((v5 - (__CFSHL__(v5 >> 31, 6) + v6)) >> 6);
  }
  v138 = v7;
  if ( v7 > 10 )
    v138 = 10;
  sub_FE8BE(v7, v6, v4, a2);
  if ( *(_BYTE *)(v142 + 2070) && !v140 )
    v140 = (uint8_t)v4 + 1;
  v8 = word_199996;
  v9 = 361 * word_199996;
  v10 = 7 * word_199996;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v8 <= 0 )
      {
        if ( v185 )
          sub_E2D72((int16_t)v119, v10);
        if ( v139 <= 0 )
LABEL_253:
          JUMPOUT(0xCFADF);
        v18 = !*(_WORD *)(v142 + 804) || !*(_BYTE *)(v142 + 1440);
        v186 = v18;
        v144 = 0;
        v176 = sub_D8C79(v119);
        HIWORD(v19) = HIWORD(v142);
        v143 = 0;
        v182 = 0;
        v20 = 0;
        LOWORD(v19) = *(_BYTE *)(v142 + 40) == 2;
        v121[47] = 0;
        v178 = v19;
        while ( v20 < v139 )
        {
          v29 = 361 * v120[v20];
          v8 = v29 + dword_192B18;
          sub_FE8BE(v29, v6, v29 + dword_192B18, (int16_t *)v10);
          if ( v140
            && (v6 = dword_1AA1D8,
                *(_BYTE *)(dword_1AA1D8
                         + 10
                         * *(uint8_t *)(dword_1930D4
                                              + 17 * *(int16_t *)(dword_192B18 + 361 * ((v8 - dword_192B18) / 361) + 2)
                                              + 2)
                         + 9))
            || sub_CFF02((char *)v8) )
          {
            v30 = v139;
            sub_E11BC((char *)v8, 26);
            v31 = v30 - 1;
            if ( v32 )
            {
              v22 = (int16_t)v20;
              v23 = &v120[(int16_t)v20];
              v33 = 361 * *v23;
              v10 = dword_192B18;
              v139 = v31;
              *(_WORD *)(dword_192B18 + v33 + 277) = 26;
              goto LABEL_58;
            }
            sub_E11BC((char *)v8, 27);
            if ( v21 )
            {
              v22 = (int16_t)v20;
              v23 = &v120[(int16_t)v20];
              v24 = 361 * *v23;
              v10 = dword_192B18;
              v139 = v31;
              *(_WORD *)(dword_192B18 + v24 + 277) = 27;
LABEL_58:
              v34 = v31;
              v27 = v120;
              v8 = v34 - v22;
              v28 = (uint8_t *)(v22 + 1);
              goto LABEL_50;
            }
            sub_E11BC((char *)v8, 40);
            if ( v25 )
            {
              v26 = (int16_t)v20;
              v23 = &v120[(int16_t)v20];
              v10 = dword_192B18;
              *(_WORD *)(dword_192B18 + 361 * *v23 + 277) = 40;
              goto LABEL_49;
            }
            sub_E11BC((char *)v8, 8);
            if ( v35 )
            {
              v26 = (int16_t)v20;
              v23 = &v120[(int16_t)v20];
              v165 = 361 * *v23;
              *(_WORD *)(v165 + dword_192B18 + 277) = 8;
              goto LABEL_49;
            }
            sub_E11BC((char *)v8, 41);
            if ( v36 )
            {
              v23 = &v120[(int16_t)v20];
              v37 = 361 * *v23;
              v10 = dword_192B18;
              v139 = v31;
              v38 = v31 - (int16_t)v20;
              v39 = (uint8_t *)((int16_t)v20 + 1);
              *(_WORD *)(dword_192B18 + v37 + 277) = 41;
              v40 = v120;
              goto LABEL_63;
            }
            sub_E11BC((char *)v8, 28);
            if ( v41 )
            {
              v23 = &v120[(int16_t)v20];
              v165 = 361 * *v23;
              v139 = v31;
              v38 = v31 - (int16_t)v20;
              *(_WORD *)(v165 + dword_192B18 + 277) = 28;
              v40 = (uint8_t *)((int16_t)v20 + 1);
              v39 = v120;
LABEL_63:
              v6 = (int)&v40[(_DWORD)v39];
              v8 = v38;
LABEL_51:
              memmove(v23, v6, v8);
              continue;
            }
            sub_E11BC((char *)v8, 24);
            if ( v42 )
            {
              v26 = (int16_t)v20;
              v23 = &v120[(int16_t)v20];
              v10 = dword_192B18;
              *(_WORD *)(dword_192B18 + 361 * *v23 + 277) = 24;
              goto LABEL_49;
            }
            v6 = 23;
            sub_E11BC((char *)v8, 23);
            if ( v43 )
            {
              v26 = (int16_t)v20;
              v23 = &v120[(int16_t)v20];
              v10 = dword_192B18;
              *(_WORD *)(dword_192B18 + 361 * *v23 + 277) = 23;
LABEL_49:
              v139 = v31;
              v8 = v31 - v26;
              v27 = (uint8_t *)(v26 + 1);
              v28 = v120;
LABEL_50:
              v6 = (int)&v28[(_DWORD)v27];
              goto LABEL_51;
            }
          }
          ++v20;
        }
        v44 = (int16_t)v176;
        if ( (int16_t)v176 != -1 )
        {
          if ( (v6 = (int16_t)v119, v8 = dword_1AA204, !*(_WORD *)(dword_1AA204 + 58 * (int16_t)v119 + 10))
            || !v140 && dword_1A7454[3 * (int16_t)v119] > 0
            || (v44 = 12 * (int16_t)v119, *(int *)((char *)dword_1A745C + v44) < 10)
            || v138 > 1 )
          {
            v44 = v142;
            if ( *(_BYTE *)(v142 + 320) == 3 && !v186 )
            {
              v45 = *((uint16_t *)off_183558 + 360 * (int16_t)v119 + (int16_t)v176);
              if ( v140 > 0 )
                v45 = (v45 - __CFSHL__(v45 >> 31, 2)) >> 2;
              v46 = 10 * *(int16_t *)(dword_1AA204 + 58 * (int16_t)v119 + 2);
              if ( v45 / 2 < v46 )
                v46 = v45 / 2;
              v8 = v46 + v45;
              if ( (_WORD)v178 )
                v47 = 100;
              else
                v47 = 200;
              v6 = sub_1247A0(0x2BCu) + v47;
              v44 = v8 * (v138 + 64);
              if ( v6 < v44 )
                v182 = 1;
            }
          }
        }
        sub_FE8BE(v44, v6, v8, (int16_t *)v10);
        v48 = (int)sub_D0C7F;
        v49 = 1;
        v50 = v139;
        qsort(v120, v139, 1);
        v51 = v142;
        if ( *(_BYTE *)(v142 + 319) == 3 )
        {
          v48 = v139;
          while ( v182 )
          {
            v51 = v48--;
            if ( v51 <= 0 )
              break;
            v50 = dword_192B18;
            v51 = sub_DF8C1(dword_192B18 + 361 * v120[v48]);
            if ( !(_BYTE)v51 )
            {
              v10 = dword_192B18;
              v49 = dword_192B18 + 361 * v120[v48];
              v51 = *(uint8_t *)(v49 + 240);
              v50 = ((int)*(uint8_t *)(v49 + 10) >> 3) + *(int16_t *)(v49 + 233) - v51;
              if ( (int16_t)v50 >= 13 )
              {
                v50 = 17 * (int16_t)v176;
                v51 = v50 + dword_1930D4;
                LOBYTE(v50) = *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(v49 + 2) + 2);
                if ( (_BYTE)v50 == *(_BYTE *)(v51 + 2) )
                {
                  if ( *(_BYTE *)(v49 + 321) == 1 )
                  {
                    v182 = 0;
                  }
                  else
                  {
                    v52 = &v120[(int16_t)v48];
                    v53 = 361 * *v52;
                    --v139;
                    *(_WORD *)(v53 + dword_192B18 + 277) = 11;
                    v49 = v139 - (int16_t)v48;
                    v50 = (int)&v120[(int16_t)v48 + 1];
                    v182 = 0;
                    v51 = memmove(v52, v50, v49);
                  }
                }
              }
            }
          }
        }
        sub_FE8BE(v51, v50, v49, (int16_t *)v10);
        if ( v182 )
        {
          v54 = v142;
          if ( *(_BYTE *)(v142 + 320) == 3 )
          {
            v50 = (_WORD)v178 && sub_1247A0(5u) == 1;
            v54 = (uint8_t)byte_1A7234[3 * (int16_t)v119];
            if ( v50 >= v54 )
            {
              v48 = v139;
              v10 = v142 + 1301;
              while ( v182 )
              {
                v54 = v48--;
                if ( v54 <= 0 )
                  break;
                v50 = 361 * v120[v48];
                v54 = sub_DF8C1(v50 + dword_192B18);
                if ( !(_BYTE)v54 )
                {
                  v49 = 361 * v120[v48] + dword_192B18;
                  v54 = *(uint8_t *)(v49 + 240);
                  v50 = ((int)*(uint8_t *)(v49 + 10) >> 3) + *(int16_t *)(v49 + 233) - v54;
                  if ( (int16_t)v50 >= 20 )
                  {
                    v50 = *(int16_t *)(dword_1AA204 + 58 * (int16_t)v119 + 2) + 50;
                    v54 = sub_1247A0(0x64u);
                    if ( v54 > v50 )
                    {
                      sub_564CD(v119, v10);
                      v49 = v120[v48];
                      v54 = sub_AF7B4((int16_t)v119, 5, v49);
                      v50 = (int16_t)v54;
                      if ( (int16_t)v54 == -1 )
                      {
                        v186 = 1;
                      }
                      else
                      {
                        v177 = -(v54 + 100);
                        *(_BYTE *)(dword_197F9C + 129 * (int16_t)v54 + 100) = 6;
                        v55 = &v120[(int16_t)v48];
                        v56 = dword_192B18 + 361 * *v55;
                        --v139;
                        *(_WORD *)(v56 + 277) = v177;
                        v49 = v139 - (int16_t)v48;
                        v165 = (int16_t)v48 + 1;
                        v50 = (int)&v120[v165];
                        v54 = memmove(v55, &v120[v165], v49);
                      }
                      v182 = 0;
                    }
                  }
                }
              }
            }
          }
        }
        sub_FE8BE(v54, v50, v49, (int16_t *)v10);
        v164 = (int16_t *)(v142 + 1301);
        v163 = 2 * v140 + 48;
        v158 = 2 * v140 + 35;
        v157 = 2 * v140 + 33;
        v173 = v141 + 1;
        v153 = v140 + 10;
        v170 = v142 + 806;
        v57 = 350 - 100 * v140;
        v152 = v140 * v140;
        v151 = 100 * v144;
        v162 = v163;
        v161 = 2 * v140 + 55;
        v160 = 2 * v140 + 45;
        v156 = 2 * v140 + 31;
        v171 = v57;
        v155 = v157;
        v154 = 2 * v140 + 30;
        while ( 1 )
        {
LABEL_116:
          if ( v139 <= 0 )
            goto LABEL_253;
          v150 = v139;
          v149 = v139 - 1;
          v148 = v120[v139 - 1];
          v58 = (_BYTE *)(361 * v148 + dword_192B18);
          sub_FE8BE(361 * v148, (int)v58, v57, (int16_t *)v10);
          v147 = v58;
          if ( v139 <= 0
            || *(_DWORD *)(v142 + 50) + *(int16_t *)(v142 + 178) >= *(_DWORD *)(v142 + 180)
            || *(int16_t *)(v142 + 178) >= 0
            || (uint8_t)v147[240] >= *(int16_t *)(v147 + 233) )
          {
            break;
          }
          v59 = (int16_t)v149;
          v60 = &v120[(int16_t)v149];
          *(_WORD *)(361 * *v60 + dword_192B18 + 277) = -37;
          v48 = (int)v120;
          v139 = v149;
          v57 = v149 - v59;
          memmove(v60, &v120[v59 + 1], v149 - v59);
          sub_E2A70(v148, v10);
        }
        v57 = 24;
        memset(&v122, 0, 24);
        if ( dword_1A745C[3 * (int16_t)v119] > 0 )
        {
          if ( *(_WORD *)(v142 + 804) )
          {
            if ( *(_BYTE *)(v142 + 1440) )
            {
              if ( !v186 )
              {
                v57 = dword_1A745C[3 * (int16_t)v119] + dword_1A7454[3 * (int16_t)v119];
                v122 = 1000 * dword_1A745C[3 * (int16_t)v119] / v57;
                if ( v140 > 0 )
                  v122 *= 2;
              }
            }
          }
        }
        if ( !*(_BYTE *)(7 * v148 + dword_1AA1EC + 5) )
        {
          if ( byte_1A724C[(int16_t)v119] )
          {
            if ( v143 <= 1 && *(_BYTE *)(v142 + 348) == 3 )
            {
              v123 = 100 * ((uint8_t)byte_1A724C[(int16_t)v119] + 5) - 200 * v143;
              if ( v140 > 0 )
                v123 /= v152;
            }
          }
        }
        if ( !*(_BYTE *)(dword_1AA1EC + 7 * v148 + 5) )
        {
          if ( byte_1A7285[2 * (int16_t)v119] )
          {
            if ( v144 < 8 )
            {
              v61 = 100 * ((uint8_t)byte_1A7285[2 * (int16_t)v119] + 10) - v151;
              v125 = v61;
              if ( v140 > 0 )
                v125 = v61 / v152;
            }
          }
        }
        v62 = 7 * v148;
        if ( !*(_BYTE *)(7 * v148 + dword_1AA1EC + 5) )
        {
          if ( byte_1A7275[2 * (int16_t)v119] )
          {
            v62 = v142;
            if ( *(_BYTE *)(v142 + 468) == 3 && !v186 )
            {
              v63 = 100 * ((uint8_t)byte_1A7275[2 * (int16_t)v119] + 5);
              v126 = v63;
              if ( v140 > 0 )
                v126 = (unsigned int)(3 * v63) >> 1;
            }
          }
        }
        if ( v140 )
          v127 = v171;
        else
          v127 = 333;
        v146 = 7 * v148;
        v159 = 7 * v149;
        v64 = 361 * v148;
        v168 = 361 * v148;
        while ( 2 )
        {
          sub_FE8BE(v64, v62, v57, (int16_t *)v10);
          v62 = 6;
          v65 = sub_FE96F((int)&v122, 6);
          v66 = (int (__fastcall *)(uint8_t *, uint8_t *))v48;
          v48 = v139 - 1;
          switch ( v65 )
          {
            case -1:
            case 5:
              --v139;
              goto LABEL_249;
            case 0:
              v48 = 6 * (int16_t)v119
                  + dword_1AA1F8
                  + 49 * *(uint8_t *)(17 * *((int16_t *)v147 + 1) + dword_1930D4 + 2)
                  + 1;
              v67 = ((int)(uint8_t)v147[10] >> 3) + *(int16_t *)(v147 + 233);
              v180 = 0;
              v181 = 0;
              v68 = (uint8_t)v147[240];
              v183 = 0;
              v69 = (int16_t)(v67 - v68);
              if ( *(int16_t *)(v142 + 178) > 5 && *(int *)(v142 + 50) > 50 )
              {
                v70 = sub_134C92(*(int16_t *)(v142 + 178));
                v71 = sub_134C92(*(_DWORD *)(v142 + 50));
                v69 += v70 + sub_134C92(v71);
              }
              v57 = 18;
              memset(&v128, 0, 18);
              if ( *(int16_t *)(v142 + 900) <= v69 * v154 )
              {
                v128 = 2;
                if ( *(int16_t *)(v142 + 999) <= v69 * v155 )
                {
                  v129 = 16;
                  v128 = 1;
                  if ( !v147[351] )
                  {
                    if ( *(_BYTE *)(v142 + 448) == 3 )
                    {
                      v57 = v69 * v156;
                      if ( (int16_t)sub_E0DD6((char *)dword_192B18, 41) <= v57 )
                      {
                        v136 = 8 * *(uint8_t *)(v159 + dword_1AA1EC + 5)
                             + 8 * *(uint8_t *)(v48 + 2)
                             + 4 * *(uint8_t *)(v48 + 1)
                             + 2 * *(uint8_t *)v48
                             + 8;
                        v72 = *(_WORD *)(v142 + 58);
                        v183 = 1;
                        if ( v72 < *(int16_t *)(v142 + 60) )
                          v136 += 2 * (*(_WORD *)(v142 + 60) - *(_WORD *)(v142 + 58));
                      }
                    }
                    if ( !v147[318] )
                    {
                      if ( *(_BYTE *)(v142 + 306) == 3 )
                      {
                        v57 = v69 * v157;
                        if ( (int16_t)sub_E0DD6((char *)dword_192B18, 8) <= v57 )
                        {
                          v135 = 10 * *(uint8_t *)(v159 + dword_1AA1EC + 5)
                               + 10 * *(uint8_t *)(v48 + 2)
                               + 3 * *(uint8_t *)v48
                               + 10
                               + 5 * *(uint8_t *)(v48 + 1);
                          v73 = *(_WORD *)(v142 + 58);
                          v181 = 1;
                          if ( v73 < *(int16_t *)(v142 + 60) )
                            v135 += 2 * (*(_WORD *)(v142 + 60) - *(_WORD *)(v142 + 58));
                        }
                      }
                      if ( !v147[350] && *(_BYTE *)(v142 + 447) == 3 )
                      {
                        v57 = v69 * v158;
                        if ( (int16_t)sub_E0DD6((char *)dword_192B18, 40) <= v57 )
                        {
                          v134 = 10 * *(uint8_t *)(v159 + dword_1AA1EC + 5)
                               + 10 * *(uint8_t *)(v48 + 2)
                               + 6 * *(uint8_t *)(v48 + 1)
                               + 4 * *(uint8_t *)v48
                               + 12;
                          v74 = *(_WORD *)(v142 + 58);
                          v180 = 1;
                          if ( v74 < *(int16_t *)(v142 + 60) )
                            v134 += 2 * (*(_WORD *)(v142 + 60) - *(_WORD *)(v142 + 58));
                        }
                      }
                    }
                  }
                }
              }
              if ( sub_E5275(v147) )
              {
                v57 = 56 * (int16_t)v119;
                if ( *(int *)((char *)dword_1A72B8 + v57) >= 2 && v69 * v160 >= *(int16_t *)(v142 + 1098) )
                {
                  v10 = 5;
                  v130 = 32;
                  v129 = (uint16_t)v129 / 5u;
                  if ( dword_1A72B8[14 * (int16_t)v119] >= 3 && v69 * v161 >= *(int16_t *)(v142 + 1197) )
                  {
                    v131 = 64;
                    v130 = 5;
                    if ( *(_BYTE *)(v142 + 465) == 3
                      && dword_1A72B8[14 * (int16_t)v119] >= 4
                      && *(int16_t *)(v142 + 1296) <= v69 * v162 )
                    {
                      v132 = 100;
                    }
                    if ( *(_BYTE *)(v142 + 334) == 3 )
                    {
                      v57 = 56 * (int16_t)v119;
                      if ( *(int *)((char *)dword_1A72B8 + v57) >= 5 )
                      {
                        if ( !v121[47] )
                          sub_56460(v119, (char *)v121);
                        if ( v121[47] <= v163 * v69 )
                          v133 = 150;
                      }
                    }
                  }
                }
              }
              else
              {
                if ( v180 )
                  v134 += 7 * *(uint8_t *)(v146 + dword_1AA1EC + 5) + 2;
                if ( v181 )
                  v135 += 6 * *(uint8_t *)(v146 + dword_1AA1EC + 5) + 2;
                if ( v183 )
                  v136 += 5 * *(uint8_t *)(v146 + dword_1AA1EC + 5) + 2;
              }
              if ( dword_1A7454[3 * (int16_t)v119] && sub_1247A0(5u) == 1 )
                v128 = 0;
              v75 = sub_FE92D((int)&v128, 9);
              v62 = v139 - 1;
              v166 = v139 - 1;
              if ( v75 < 5 )
              {
                if ( v75 < -1 )
                  goto LABEL_249;
                if ( v75 <= -1 )
                  goto LABEL_203;
                v62 = v75;
                v76 = sub_AF7B4((int16_t)v119, v75, v148);
                v10 = (int16_t)v76;
                v57 = v76;
                if ( (int16_t)v76 != -1 )
                {
                  v10 = 129 * (int16_t)v76;
                  *(_BYTE *)(v10 + dword_197F9C + 100) = 6;
                  v177 = -(v76 + 100);
                  v77 = (int16_t)v149;
                  v78 = &v120[(int16_t)v149];
                  *(_WORD *)(361 * *v78 + dword_192B18 + 277) = v177;
                  v139 = v166;
                  v48 = (int)&v120[v77 + 1];
                  v62 = v48;
                  memmove(v78, v48, v166 - v77);
                  v57 = 12 * (int16_t)v119;
                  v79 = v10 + dword_197F9C;
LABEL_206:
                  sub_CFAE5(v79);
                  *(int *)((char *)dword_1A745C + v57) -= v80;
                  goto LABEL_249;
                }
              }
              else
              {
                if ( v75 > 5 )
                {
                  if ( v75 < 7 )
                  {
                    v86 = (int16_t)v149;
                    v87 = &v120[(int16_t)v149];
                    *(_WORD *)(dword_192B18 + 361 * *v87 + 277) = 40;
                    v139 = v166;
                    memmove(v87, &v120[v86 + 1], v166 - v86);
                    v88 = 3 * (int16_t)v119;
                    v57 = *(uint8_t *)(v48 + 1) + *(uint8_t *)v48;
                    v89 = 2 * *(uint8_t *)(v48 + 2);
                  }
                  else if ( v75 <= 7 )
                  {
                    v90 = (int16_t)v149;
                    v91 = &v120[(int16_t)v149];
                    *(_WORD *)(dword_192B18 + 361 * *v91 + 277) = 8;
                    v139 = v166;
                    memmove(v91, &v120[v90 + 1], v166 - v90);
                    v88 = 3 * (int16_t)v119;
                    v57 = 2 * *(uint8_t *)(v48 + 1) + *(uint8_t *)v48;
                    v89 = 3 * *(uint8_t *)(v48 + 2);
                  }
                  else
                  {
                    if ( v75 != 8 )
                    {
LABEL_249:
                      v64 = v139;
                      if ( v139 != v150 )
                        goto LABEL_116;
                      continue;
                    }
                    v92 = (int16_t)v149;
                    v93 = &v120[(int16_t)v149];
                    *(_WORD *)(dword_192B18 + 361 * *v93 + 277) = 41;
                    v139 = v166;
                    memmove(v93, &v120[v92 + 1], v166 - v92);
                    v88 = 3 * (int16_t)v119;
                    v57 = *(uint8_t *)v48 + 4 * *(uint8_t *)(v48 + 1);
                    v89 = 6 * *(uint8_t *)(v48 + 2);
                  }
                  v62 = v57 + v89;
                  dword_1A745C[v88] -= v62;
                  goto LABEL_249;
                }
                v57 = (int16_t)v148;
                v119 = (int)v164;
                qmemcpy(v164, v121, 0x63u);
                v10 = v119;
                v48 = (int16_t)v119;
                v81 = sub_AF7B4((int16_t)v119, 5, v57);
                v62 = v81;
                if ( (int16_t)v81 != -1 )
                {
                  v82 = 129 * (int16_t)v81;
                  v10 = -(v81 + 100);
                  *(_BYTE *)(v82 + dword_197F9C + 100) = 6;
                  v83 = (int16_t)v149;
                  v84 = &v120[(int16_t)v149];
                  v165 = 361 * *v84;
                  *(_WORD *)(v165 + dword_192B18 + 277) = v10;
                  v139 = v166;
                  v85 = v166 - v83;
                  v165 = v83 + 1;
                  v62 = (int)&v120[v83 + 1];
                  memmove(v84, v62, v85);
                  v57 = 12 * (int16_t)v119;
                  v79 = v82 + dword_197F9C;
                  goto LABEL_206;
                }
              }
              v186 = 1;
LABEL_203:
              v122 = 0;
              goto LABEL_249;
            case 1:
              if ( (uint8_t)sub_DF8C1((int)v147) || (int16_t)sub_CFEDC((int)v147) < 12 )
              {
                v123 = 0;
              }
              else
              {
                v94 = (int16_t)v149;
                v95 = &v120[(int16_t)v149];
                v96 = 361 * *v95;
                v139 = v48;
                v48 -= (int16_t)v149;
                *(_WORD *)(v96 + dword_192B18 + 277) = -15;
                v62 = (int)&v120[v94 + 1];
                v57 = v48;
                memmove(v95, v62, v48);
                ++v143;
                --byte_1A724C[(int16_t)v119];
              }
              goto LABEL_249;
            case 2:
              v137 = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(v168 + dword_192B18 + 2) + 2);
              v167 = *v141 - 1;
              v145 = &v141[3 * v167];
              v62 = (int)&v173[3 * v167];
              LOBYTE(v48) = 0;
              v172 = v62;
              v174 = (int)&v173[3 * v167 + 3];
              while ( !(_BYTE)v48 && v167 >= 0 )
              {
                HIWORD(v62) = HIWORD(v145);
                LOWORD(v62) = v145[1];
                v97 = dword_197F9C + 129 * (int16_t)v62;
                v57 = *(int16_t *)(v97 + 101);
                if ( v57 == v137 && (*(_BYTE *)(v97 + 16) < 2u || sub_E5275(v147)) )
                {
                  v169 = (int16_t *)(129 * (int16_t)v62 + dword_197F9C);
                  v98 = *((_BYTE *)v169 + 16);
                  if ( v98 == 5 )
                  {
                    if ( !v121[47] )
                      sub_56460(v119, (char *)v121);
                    v99 = v121;
                  }
                  else
                  {
                    v99 = (int16_t *)(99 * v98 + v170);
                  }
                  v62 = (int)v169;
                  v57 = sub_D108B(v119, (int)v169, (int)v99);
                  v175 = v57;
                  if ( (int16_t)v57 <= v99[47] )
                  {
                    v62 = (int16_t)v57;
                    if ( (int16_t)v57 <= v153
                                       * (int16_t)(((int)(uint8_t)v147[10] >> 3)
                                                 + *(_WORD *)(v147 + 233)
                                                 - (uint8_t)v147[240]) )
                    {
                      v100 = v169[58];
                      if ( v100 != -1 )
                      {
                        sub_944A3(v100, v10);
                        v169[58] = -1;
                      }
                      v101 = v175;
                      v119 = (int)v169;
                      qmemcpy(v169, v99, 0x63u);
                      v10 = v119;
                      *(_WORD *)(v119 + 94) = v101;
                      v102 = (int16_t)v149;
                      v103 = -((v10 - dword_197F9C) / 129 + 100);
                      v104 = &v120[(int16_t)v149];
                      *(_BYTE *)(v10 + 100) = 4;
                      v105 = 361 * *v104;
                      --v139;
                      *(_WORD *)(v105 + dword_192B18 + 277) = v103;
                      v48 = v139 - v102;
                      memmove(v104, &v120[v102 + 1], v139 - v102);
                      v106 = v141;
                      --*v141;
                      v57 = 6 * (*v106 - v167);
                      v62 = v174;
                      LOBYTE(v48) = 1;
                      memmove(v172, v174, v57);
                    }
                  }
                }
                v145 -= 3;
                v172 -= 6;
                v174 -= 6;
                --v167;
              }
              if ( !(_BYTE)v48 )
                v124 = 0;
              goto LABEL_249;
            case 3:
              if ( (uint8_t)sub_DF8C1((int)v147) || (int16_t)sub_CFEDC((int)v147) < 15 )
              {
                v125 = 0;
              }
              else
              {
                v107 = (int16_t)v149;
                v108 = &v120[(int16_t)v149];
                v109 = 361 * *v108;
                v139 = v48;
                *(_WORD *)(v109 + dword_192B18 + 277) = -7;
                v110 = (int (__fastcall *)(uint8_t *, uint8_t *))v48;
                v48 = (int)v120;
                v57 = (int)v110 - v107;
                v62 = (int)&v120[v107 + 1];
                memmove(v108, v62, v57);
                --byte_1A7285[2 * (int16_t)v119];
              }
              goto LABEL_249;
            case 4:
              if ( (uint8_t)sub_DF8C1((int)v147) || (int16_t)sub_CFEDC((int)v147) < 14 )
                goto LABEL_247;
              if ( v147[332] )
              {
                v57 = (int16_t)v148;
                sub_5663E(v119, (int)v164);
                v111 = sub_AF7B4((int16_t)v119, 5, v57);
                v62 = v111;
                if ( (int16_t)v111 == -1 )
                {
                  v186 = 1;
LABEL_247:
                  v126 = 0;
                }
                else
                {
                  *(_BYTE *)(dword_197F9C + 129 * (int16_t)v111 + 100) = 6;
                  v177 = -(v111 + 100);
                  v112 = (int16_t)v149;
                  v113 = &v120[(int16_t)v149];
                  v114 = dword_192B18 + 361 * *v113;
                  v10 = v177;
                  v139 = v48;
                  *(_WORD *)(v114 + 277) = v177;
                  v115 = (int (__fastcall *)(uint8_t *, uint8_t *))v48;
                  v48 = (int)v120;
                  v57 = (int)v115 - v112;
                  v62 = (int)&v120[v112 + 1];
                  memmove(v113, v62, v57);
                  --byte_1A7275[2 * (int16_t)v119];
                }
              }
              else
              {
                v116 = (int16_t)v149;
                v117 = &v120[(int16_t)v149];
                v118 = 361 * *v117;
                v139 = v48;
                v48 -= (int16_t)v149;
                *(_WORD *)(v118 + dword_192B18 + 277) = 22;
                v62 = (int)&v120[v116 + 1];
                v57 = v48;
                memmove(v117, v62, v48);
                --byte_1A7275[2 * (int16_t)v119];
              }
              goto LABEL_249;
            default:
              v48 = (int)v66;
              goto LABEL_249;
          }
        }
      }
      v9 -= 361;
      v11 = dword_192B18 + v9;
      v10 -= 7;
      LOWORD(v6) = *(char *)(dword_192B18 + v9);
      --v8;
      if ( (_WORD)v6 == (_WORD)v119 && !*(_BYTE *)(v11 + 6) )
      {
        if ( *(_BYTE *)(v11 + 10) )
        {
          v165 = 361;
          v6 = v9 % 361;
          v12 = sub_2341E(v9 / 361);
          if ( !v12 )
            break;
        }
      }
    }
    sub_FE8BE(v12, v6, v8, (int16_t *)v10);
    if ( (uint8_t)sub_DF8C1(v11) || *(_BYTE *)(v10 + dword_1AA1EC + 5) || v184 )
      break;
LABEL_28:
    v15 = *(_WORD *)(v11 + 277);
    if ( v15 < 0xFFFEu )
    {
      v16 = v15 == 0xFFFD;
      goto LABEL_31;
    }
    if ( v15 == 0xFFFF )
    {
      v16 = 1;
LABEL_31:
      if ( v16 )
        goto LABEL_35;
    }
    else
    {
      v185 = 1;
LABEL_35:
      v17 = v139;
      *(_WORD *)(v11 + 277) = -38;
      ++v139;
      v120[v17] = v8;
    }
  }
  v13 = *(int16_t *)(v11 + 277);
  v179 = 0;
  if ( v13 > -100 )
  {
    v14 = *(_WORD *)(v11 + 277);
    if ( v14 < 0xFFF9u )
      goto LABEL_26;
    if ( v14 > 0xFFFCu )
    {
      if ( v14 != 0xFFFE )
        goto LABEL_26;
      v185 = 1;
    }
  }
  else
  {
    v6 = dword_197F9C;
    if ( !*(_BYTE *)(dword_197F9C - 129 * (v13 + 100) + 17) )
      goto LABEL_26;
  }
  v179 = 1;
LABEL_26:
  if ( v179 )
  {
    v6 = 0;
    sub_B1E19(v8, 0);
  }
  goto LABEL_28;
}
// D274F: control flows out of bounds to CFADF
// D1368: variable 'v21' is possibly undefined
// D13A5: variable 'v25' is possibly undefined
// D146E: variable 'v32' is possibly undefined
// D14BA: variable 'v35' is possibly undefined
// D14F8: variable 'v36' is possibly undefined
// D1542: variable 'v41' is possibly undefined
// D158B: variable 'v42' is possibly undefined
// D15C5: variable 'v43' is possibly undefined
// D1986: variable 'v54' is possibly undefined
// D216C: variable 'v80' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 183558: using guessed type _UNKNOWN *off_183558;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199996: using guessed type int16_t word_199996;
// 1A72B8: using guessed type int dword_1A72B8[];
// 1A7454: using guessed type int dword_1A7454[];
// 1A745C: using guessed type int dword_1A745C[22];
// 1AA1C4: using guessed type int dword_1AA1C4;
// 1AA1D8: using guessed type int dword_1AA1D8;
// 1AA1EC: using guessed type int dword_1AA1EC;
// 1AA1F8: using guessed type int dword_1AA1F8;
// 1AA204: using guessed type int dword_1AA204;


//----- (000D2754) --------------------------------------------------------
void __fastcall sub_D2754(int a1)
{
  uint16_t v1; // dx

  if ( !*(_BYTE *)(a1 + 6) )
  {
    if ( *(_BYTE *)(a1 + 10) )
    {
      v1 = *(_WORD *)(a1 + 277);
      if ( v1 >= 0xFFDAu && (v1 <= 0xFFDAu || v1 >= 0xFFFDu) )
        sub_D0B08((char *)a1);
    }
  }
}


//----- (000D2783) --------------------------------------------------------
void __usercall sub_D2783(char *a1, int a2)
{
  sub_E2A70((int)&a1[-dword_192B18] / 361, a2);
  sub_D0B08(a1);
}
// 192B18: using guessed type int dword_192B18;


//----- (000D27A7) --------------------------------------------------------
int __fastcall sub_D27A7(int a1, _BYTE *a2)
{
  int v4; // ebx
  int16_t v5; // di
  int16_t v6; // ax
  int16_t v7; // di
  int16_t v8; // ax
  int v9; // eax
  int16_t v10; // di
  _BOOL1 v11; // al
  int16_t v12; // dx
  uint8_t v13; // al
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  uint8_t v17; // al
  int v18; // eax
  int v19; // eax
  uint8_t v20; // al
  int v21; // eax
  int v22; // ebx
  int v23; // ebx
  int v25; // [esp+4h] [ebp-10h]
  int16_t v26; // [esp+8h] [ebp-Ch]
  _BOOL1 v27; // [esp+Ch] [ebp-8h]
  _BOOL1 v28; // [esp+10h] [ebp-4h]

  v4 = 0;
  if ( *(_BYTE *)(a1 + 4) != 3 )
    goto LABEL_58;
  if ( a2[282] == 3 )
    v5 = 5;
  else
    v5 = 0;
  sub_E0B4F((int16_t *)a1, (int)&a2[-dword_197F98] / 3753);
  v7 = v6 + v5;
  if ( a2[2220] )
    v8 = sub_E0A14(*(uint8_t *)(a1 + 5));
  else
    v8 = 0;
  v26 = v7 + v8;
  v9 = *(uint8_t *)(a1 + 10);
  v10 = (uint8_t)byte_DD4B5[v9];
  v25 = v26 * ((uint8_t)byte_DD4B5[v9] + 1) / 3;
  v11 = *(_BYTE *)(a1 + 8) == 5 || *(_BYTE *)(a1 + 8) == 6;
  v28 = v11;
  v12 = *(uint8_t *)(a1 + 11);
  v27 = a2[410] == 3;
  if ( !*(_BYTE *)(a1 + 11) )
    v12 = a2[308] == 3;
  v13 = a2[2208];
  if ( v13 >= 0x32u )
  {
    if ( v13 <= 0x32u )
    {
      v15 = 70 * v10;
      v14 = 3 * (int16_t)v25;
    }
    else
    {
      if ( v13 < 0x64u )
        goto LABEL_27;
      if ( v13 <= 0x64u )
      {
        v15 = 65 * v10;
        v14 = 4 * (int16_t)v25;
      }
      else
      {
        if ( v13 != 0xCE )
          goto LABEL_27;
        v14 = 80 * v10;
        v15 = (int16_t)v25;
      }
    }
LABEL_26:
    v4 = v14 + v15;
    goto LABEL_27;
  }
  if ( !v13 )
  {
    v15 = 75 * v10;
    v14 = 2 * (int16_t)v25;
    goto LABEL_26;
  }
LABEL_27:
  if ( !a2[2225] )
  {
    if ( a2[2224] )
      v16 = 75 * v12;
    else
      v16 = 150 * v12;
    v4 += v16;
  }
  v17 = *(_BYTE *)(a1 + 15);
  if ( v17 < 6u )
  {
    if ( v17 >= 4u )
    {
      if ( v17 > 4u )
        v4 += 2560;
      else
        v4 += 1280;
    }
  }
  else if ( v17 >= 0xAu )
  {
    if ( v17 <= 0xAu )
    {
      v4 += 640;
    }
    else if ( v17 == 11 )
    {
      v4 += 1600;
    }
  }
  v18 = v26 * v4 * ((uint8_t)byte_DD4B5[*(uint8_t *)(a1 + 10)] + 7) / 10;
  v4 = v18;
  if ( !v28 || !a2[2219] )
  {
    v19 = v18 * (100 - ((int)*((uint8_t *)&word_DD4BA + *(uint8_t *)(a1 + 8)) >> 2)) / 100;
    v4 = v19;
    if ( v28 )
      v4 = (3 * v19 - (__CFSHL__((3 * v19) >> 31, 2) + 4 * ((3 * v19) >> 31))) >> 2;
  }
  v20 = *(_BYTE *)(a1 + 6);
  if ( !v20 )
  {
    if ( a2[2217] )
      goto LABEL_58;
LABEL_52:
    v21 = v4 * (v27 + 18);
    v22 = 20;
LABEL_57:
    v4 = v21 / v22;
    goto LABEL_58;
  }
  if ( v20 <= 1u )
  {
    if ( !a2[2217] )
      goto LABEL_58;
    goto LABEL_52;
  }
  if ( v20 == 2 && !a2[2218] )
  {
    v21 = v4 * (v27 + 4);
    v22 = 6;
    goto LABEL_57;
  }
LABEL_58:
  v23 = (v4 - (__CFSHL__(v4 >> 31, 6) + (v4 >> 31 << 6))) >> 6;
  if ( v23 >= 0xFFFF )
    return 0xFFFF;
  return v23;
}
// D27EE: variable 'v6' is possibly undefined
// DD4BA: using guessed type int16_t word_DD4BA;
// 197F98: using guessed type int dword_197F98;


//----- (000D2A08) --------------------------------------------------------
int16_t __fastcall sub_D2A08(uint8_t *a1)
{
  int16_t v2; // di
  int16_t v3; // si
  unsigned int v4; // eax
  int16_t v5; // si
  int16_t v6; // ax
  int v8; // edx
  _BYTE v9[8]; // [esp+0h] [ebp-8h] BYREF

  memset(v9, 0, sizeof(v9));
  v2 = 0;
  v3 = a1[10];
  while ( v3 > 0 )
  {
    v4 = *(_DWORD *)&a1[4 * --v3 + 12] & 0xF;
    if ( v4 < 8 )
    {
      ++v2;
      ++v9[v4];
    }
  }
  v5 = word_199998 - 1;
  v6 = word_199998 - 1;
  while ( v6 > 0 )
  {
    if ( v9[v5] < v9[--v6] )
      v5 = v6;
  }
  if ( v2 < 2 * (uint8_t)v9[v5] )
    return v5;
  v8 = (char)*a1;
  if ( v2 >= 3 * (uint8_t)v9[v8] && v9[v5] && v9[v5] != v9[v8] )
    return v5;
  else
    return (char)*a1;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 199998: using guessed type int16_t word_199998;


//----- (000D2AA9) --------------------------------------------------------
char __fastcall sub_D2AA9( int a1, int a2, int a3)
{
  char v5; // cl
  int v6; // eax
  int v7; // eax
  int v8; // eax

  v5 = 0;
  sub_EBEB7(a2, a1);
  if ( v6 <= a3 )
    return 1;
  v7 = *(char *)(dword_19306C + 113 * a2 + 41);
  if ( v7 != -1 )
  {
    sub_EBEB7(v7, a1);
    if ( v8 <= a3 )
      return 1;
  }
  return v5;
}
// D2AC1: variable 'v6' is possibly undefined
// D2AE0: variable 'v8' is possibly undefined
// 19306C: using guessed type int dword_19306C;


//----- (000D2AEA) --------------------------------------------------------
void __fastcall sub_D2AEA(char *a1, int a2)
{
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  int v6; // edx
  int v7; // [esp+0h] [ebp-2Ch]
  int v8; // [esp+4h] [ebp-28h]
  int v9; // [esp+8h] [ebp-24h]
  int v10; // [esp+14h] [ebp-18h]
  int v11; // [esp+18h] [ebp-14h]
  int v12; // [esp+1Ch] [ebp-10h]
  int v13; // [esp+20h] [ebp-Ch]
  int v14; // [esp+24h] [ebp-8h]
  int v15; // [esp+28h] [ebp-4h]

  LOWORD(v3) = 0;
  if ( byte_199CB0 )
  {
    v4 = *a1;
    v5 = dword_197F98 + 3753 * v4;
    if ( *(_BYTE *)(v5 + 284) != 3 )
    {
      v10 = *(int16_t *)(v5 + 804);
      v7 = *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)a1 + 1) + 2);
      if ( v4 == (a2 - dword_197F98) / 3753 )
      {
        v15 = word_19999A;
        v9 = 113 * word_19999A;
        v11 = 49 * word_19999A;
        while ( v15 > 0 )
        {
          v9 -= 113;
          v11 -= 49;
          --v15;
          if ( *(_BYTE *)(v9 + dword_19306C + 22) != 6 && sub_D2AA9(v15, v7, v10) )
          {
            if ( (~(1 << *a1) & *(uint8_t *)(v9 + dword_19306C + 56)) != 0 )
              v6 = 120;
            else
              v6 = 80;
            v3 = v6 / *(uint8_t *)(dword_1AA1F8 + v11 + 6 * *a1 + 5) + (uint16_t)v3;
          }
        }
      }
      else
      {
        v8 = word_19999A;
        v12 = 113 * word_19999A;
        v13 = 10000;
        v14 = 49 * word_19999A;
        while ( v8 > 0 )
        {
          v12 -= 113;
          --v8;
          v14 -= 49;
          if ( sub_D2AA9(v8, v7, v10) )
          {
            if ( (((int)*(uint8_t *)(v12 + dword_19306C + 56) >> ((a2 - dword_197F98) / 3753)) & 1) != 0 )
            {
              v3 = 100 / *(uint8_t *)(v14 + dword_1AA1F8 + 6 * *a1 + 5) + (uint16_t)v3;
              if ( *(uint8_t *)(v14 + dword_1AA1F8 + 6 * *a1 + 5) < v13 )
                v13 = *(uint8_t *)(v14 + dword_1AA1F8 + 6 * *a1 + 5);
            }
          }
        }
      }
    }
  }
  JUMPOUT(0xD2A02);
}
// D2C99: control flows out of bounds to D2A02
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;
// 199CB0: using guessed type char byte_199CB0;
// 1AA1F8: using guessed type int dword_1AA1F8;


//----- (000D2CAE) --------------------------------------------------------
void __fastcall sub_D2CAE(int a1, int a2)
{
  int16_t *v3; // edi
  int16_t v4; // bx
  int v5; // [esp+24h] [ebp-8h]

  v5 = (a2 - dword_197F98) / 3753;
  v3 = (int16_t *)(dword_1930D4 + 17 * *(int16_t *)(a1 + 2));
  v4 = *(uint8_t *)(7 * ((a1 - dword_192B18) / 361) + dword_1AA1EC);
  sub_E0B4F(v3, v4);
  sub_E0B4F(v3, (a2 - dword_197F98) / 3753);
  if ( *(_BYTE *)(a1 + 6) )
  {
    sub_D2AEA((char *)a1, a2);
    JUMPOUT(0xD2A02);
  }
  sub_DE0C6((char *)a1, v5, v4, 0);
  sub_DED47((char *)a1, v5, v4, 0);
  sub_DFE77((char *)a1, v5, v4, 0);
  if ( (uint8_t)byte_199CB0 >= 2u )
    sub_D2AEA((char *)a1, a2);
  JUMPOUT(0xD29F9);
}
// D2D68: control flows out of bounds to D2A02
// D3029: control flows out of bounds to D29F9
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;
// 1AA1EC: using guessed type int dword_1AA1EC;


//----- (000D302E) --------------------------------------------------------
void sub_D302E()
{
  int v0; // ebx
  int16_t v1; // si
  _WORD *v2; // eax
  int v3; // edx
  int v4; // ecx
  int16_t v5; // dx
  int v6; // eax
  int16_t v7; // ax
  int v8; // [esp+8h] [ebp-4h]

  HIWORD(v0) = 0;
  memset(off_183554, 0, 5760);
  LOWORD(v0) = word_199998;
  while ( (int16_t)v0 > 0 )
  {
    v1 = word_1999A2;
    --v0;
    while ( v1 > 0 )
    {
      v8 = 17 * --v1;
      v2 = (_WORD *)(v8 + dword_1930D4);
      v3 = (int)*(uint8_t *)(dword_1AA200 + *(uint8_t *)(v8 + dword_1930D4 + 2)) >> v0;
      if ( (v3 & 1) != 0 )
      {
        LOWORD(v3) = *v2;
        sub_FE8BE((int)v2, v3, v0, (int16_t *)v1);
        if ( (int16_t)v3 == -1 )
        {
          v4 = 720 * (int16_t)v0;
          v5 = sub_D27A7(v8 + dword_1930D4, (_BYTE *)(3753 * (int16_t)v0 + dword_197F98));
          v6 = (int)off_183554;
        }
        else
        {
          sub_D2CAE(361 * (int16_t)v3 + dword_192B18, dword_197F98 + 3753 * (int16_t)v0);
          v5 = v7;
          v6 = 720 * (int16_t)v0;
          v4 = (int)off_183554;
        }
        *(_WORD *)(2 * v1 + v4 + v6) = v5;
      }
    }
  }
  JUMPOUT(0xD2AA2);
}
// D3120: control flows out of bounds to D2AA2
// D30F9: variable 'v7' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 183554: using guessed type _UNKNOWN *off_183554;
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 1999A2: using guessed type int16_t word_1999A2;
// 1AA200: using guessed type int dword_1AA200;


//----- (000D3125) --------------------------------------------------------
void sub_D3125()
{
  int v0; // ebx
  int16_t *v1; // edi
  int v2; // esi
  int v3; // ecx
  int v4; // edx
  int v5; // edx
  int v6; // eax
  int16_t *v7; // edx
  int v8; // ecx
  _WORD *v9; // ecx
  int16_t v10; // ax
  int v11; // [esp+0h] [ebp-34h]
  int v12; // [esp+4h] [ebp-30h]
  int v13; // [esp+Ch] [ebp-28h]
  int v14; // [esp+10h] [ebp-24h]
  int v15; // [esp+14h] [ebp-20h]
  int v16; // [esp+18h] [ebp-1Ch]
  int v17; // [esp+1Ch] [ebp-18h]
  int v18; // [esp+20h] [ebp-14h]
  int v19; // [esp+28h] [ebp-Ch]

  memset(off_183558, 0, 5760);
  v19 = word_199998;
LABEL_22:
  if ( v19 <= 0 )
    JUMPOUT(0xD2AA2);
  --v19;
  v0 = 720 * v19;
  v1 = (int16_t *)word_1999A2;
  v17 = 17 * word_1999A2;
  v2 = 2 * word_1999A2;
  while ( 1 )
  {
    while ( 1 )
    {
      do
      {
        if ( (int)v1 <= 0 )
          goto LABEL_22;
        v2 -= 2;
        v17 -= 17;
        v1 = (int16_t *)((char *)v1 - 1);
      }
      while ( !*(_WORD *)((char *)off_183554 + v0 + v2) );
      v3 = 113 * *(uint8_t *)(v17 + dword_1930D4 + 2);
      v16 = 0;
      v18 = 0;
      v4 = dword_19306C;
      v12 = *(int16_t *)(v17 + dword_1930D4);
      sub_FE8BE(v12, dword_19306C, v0, v1);
      v5 = v3 + v4;
      v15 = 0;
      *(_WORD *)((char *)off_183558 + v0 + v2) = *(_WORD *)((char *)off_183554 + v0 + v2);
      v6 = v5 + 10;
      v14 = 0;
      v11 = v5;
      while ( v6 != v11 )
      {
        v7 = (int16_t *)*(int16_t *)(v6 + 72);
        v6 -= 2;
        if ( v7 != (int16_t *)-1 && v1 != v7 )
        {
          v8 = *(int16_t *)(dword_1930D4 + 17 * (_DWORD)v7);
          if ( v8 == -1 )
          {
            v16 += *(uint16_t *)((char *)off_183554 + 2 * (_DWORD)v7 + v0);
          }
          else if ( *(char *)(dword_192B18 + 361 * v8) == v19 )
          {
            ++v14;
            v15 += *(uint16_t *)((char *)off_183554 + 2 * (_DWORD)v7 + v0);
          }
          else
          {
            ++v18;
          }
        }
      }
      v13 = (v16 - (__CFSHL__(v16 >> 31, 3) + 8 * (v16 >> 31))) >> 3;
      if ( v12 == -1 )
        break;
      v9 = (_WORD *)((char *)off_183558 + v0 + v2);
      *v9 += v13;
      v10 = ((v15 - (__CFSHL__(v15 >> 31, 2) + 4 * (v15 >> 31))) >> 2) + *v9;
LABEL_20:
      *v9 = v10;
    }
    if ( v14 <= 0 )
      *(_WORD *)((char *)off_183558 + v0 + v2) += v13;
    else
      *(_WORD *)((char *)off_183558 + v0 + v2) = *(uint16_t *)((char *)off_183558 + v0 + v2)
                                               * (*(uint8_t *)(v17 + dword_1930D4 + 5) + 1)
                                               / 10;
    if ( v18 > 0 )
    {
      v9 = (_WORD *)((char *)off_183558 + v0 + v2);
      v10 = *v9 / (uint16_t)(v18 + 2);
      goto LABEL_20;
    }
  }
}
// D3313: control flows out of bounds to D2AA2
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 183554: using guessed type _UNKNOWN *off_183554;
// 183558: using guessed type _UNKNOWN *off_183558;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 199998: using guessed type int16_t word_199998;
// 1999A2: using guessed type int16_t word_1999A2;


//----- (000D3318) --------------------------------------------------------
int __fastcall sub_D3318(int16_t *a1, int16_t *a2)
{
  int v2; // ebx
  int v3; // ecx
  int16_t v4; // di
  int16_t v5; // si
  int16_t v7; // si
  int16_t v8; // bx
  int v9; // eax
  int v10; // edx
  int16_t v11; // cx
  int16_t v12; // bx
  int16_t v13; // ax
  int16_t v14; // dx

  v2 = dword_197F9C + 129 * *a1;
  v3 = 129 * *a2 + dword_197F9C;
  v4 = *(char *)(v2 + 99);
  v5 = *(char *)(v3 + 99);
  if ( v4 < v5 )
    return -1;
  if ( v5 < v4 )
    return 1;
  v7 = *(_WORD *)(v2 + 101);
  v8 = *(_WORD *)(v3 + 101);
  if ( v7 < v8 && v7 < 72 )
    return -1;
  if ( v8 < v7 && v8 < 72 )
    return 1;
  if ( v7 < 72 && v8 < 72 )
    return 0;
  v9 = dword_197F9C + 129 * *a1;
  v10 = dword_197F9C + 129 * *a2;
  v11 = *(_WORD *)(v9 + 103);
  v12 = *(_WORD *)(v10 + 103);
  if ( v11 < v12 )
    return -1;
  if ( v12 < v11 )
    return 1;
  v13 = *(_WORD *)(v9 + 105);
  v14 = *(_WORD *)(v10 + 105);
  if ( v13 < v14 )
    return -1;
  return v14 < v13;
}
// 197F9C: using guessed type int dword_197F9C;


//----- (000D33D1) --------------------------------------------------------
void __fastcall sub_D33D1(int a1)
{
  int16_t v2; // cx
  int v3; // ebx
  uint8_t *v4; // eax
  uint8_t v5; // dl
  int v6; // eax
  uint8_t v7; // dl
  int v8; // eax
  uint8_t v9; // dl
  int16_t v10; // ax
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int16_t v15; // [esp+4h] [ebp-Ch]
  uint8_t v16; // [esp+8h] [ebp-8h]
  uint8_t v17; // [esp+Ch] [ebp-4h]

  v2 = *(char *)(a1 + 99);
  v3 = 0;
  if ( *(char *)(a1 + 93) == v2 )
  {
    v4 = (uint8_t *)(dword_1AA1D0 + 21 * *(char *)(a1 + 99));
    v5 = *(_BYTE *)(a1 + 18);
    if ( v5 < *v4 )
      v3 = 10 * (*v4 - v5);
    v6 = dword_1AA1D0 + 21 * v2;
    v7 = *(_BYTE *)(a1 + 21);
    if ( v7 < *(_BYTE *)(v6 + 4) )
      v3 += 7 * (*(uint8_t *)(v6 + 4) - v7);
    v8 = dword_1AA1D0 + 21 * v2;
    v9 = *(_BYTE *)(a1 + 22);
    if ( v9 < *(_BYTE *)(v8 + 2) )
      v3 += 5 * (*(uint8_t *)(v8 + 2) - v9);
    v16 = 0;
    v17 = 0;
    v15 = 8;
    do
    {
      v10 = *(_WORD *)(a1 + 8 * --v15 + 28);
      if ( v10 )
      {
        v11 = 14 * v10;
        v12 = *(int *)((char *)&dword_17D916 + 23 * *(int16_t *)((char *)&word_17E07F + 13 * word_17F80D[v11])) / 100;
        BYTE1(v12) = byte_17F80F[v11 * 2];
        if ( BYTE1(v12) )
        {
          if ( BYTE1(v12) <= 2u && (uint8_t)v12 > v17 )
            v17 = v12;
        }
        else if ( (uint8_t)v12 > v16 )
        {
          v16 = v12;
        }
      }
    }
    while ( v15 > 0 );
    if ( v16 )
    {
      v13 = dword_1AA1D0 + 21 * v2;
      if ( v16 < *(_BYTE *)(v13 + 12) )
        v3 += 8 * (*(uint8_t *)(v13 + 12) - v16);
    }
    if ( v17 )
    {
      v14 = dword_1AA1D0 + 21 * v2;
      if ( v17 < *(_BYTE *)(v14 + 14) )
        v3 += 6 * (*(uint8_t *)(v14 + 14) - v17);
    }
    if ( v3 )
    {
      if ( *(_BYTE *)(a1 + 16) < 5u )
        memcmp(
          (char *)a1,
          (char *)(dword_197F98 + 3753 * v2 + 806 + 99 * *(uint8_t *)(a1 + 16)),
          99);
    }
  }
  JUMPOUT(0xD2AA2);
}
// D356A: control flows out of bounds to D2AA2
// 17D916: using guessed type int dword_17D916;
// 17E07F: using guessed type int16_t word_17E07F;
// 17F80D: using guessed type int16_t word_17F80D[];
// 197F98: using guessed type int dword_197F98;
// 1AA1D0: using guessed type int dword_1AA1D0;


//----- (000D356F) --------------------------------------------------------
int __fastcall sub_D356F(int a1, int a2)
{
  return *(_DWORD *)(a1 + 2) - *(_DWORD *)(a2 + 2);
}


//----- (000D3576) --------------------------------------------------------
int16_t __fastcall sub_D3576( int a1, int a2, int a3, _WORD *a4, int a5)
{
  int v6; // ecx
  uint8_t *v7; // ebx
  _BYTE *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _BYTE *v12; // edx
  int v13; // edx
  int16_t v14; // ax
  int v19; // [esp+18h] [ebp-20h]
  int v20; // [esp+2Ch] [ebp-Ch]
  int v21; // [esp+30h] [ebp-8h]

  v6 = a3;
  v7 = (uint8_t *)(32 * a3 + dword_1AA1B8 + 2304 * a2 + 4 * a1);
  if ( v7[1] == 0xFF )
  {
    v8 = (_BYTE *)(3753 * a1 + dword_197F98);
    if ( v8[1440] )
    {
      if ( v8[378] != 3
        && v8[449] != 3
        && *(char *)(dword_19306C + 113 * a2 + 41) == -1
        && *(char *)(dword_19306C + 113 * v6 + 41) == -1
        && *(_BYTE *)(a1 + 8 * v6 + 576 * a2 + dword_1AA1E8) != 0xFF )
      {
        sub_EBEB7(a2, v6);
        v10 = (v9 + *(uint8_t *)(3753 * a1 + dword_197F98 + 1440) - 1)
            / *(uint8_t *)(3753 * a1 + dword_197F98 + 1440);
        if ( *(uint8_t *)(a1 + 8 * v6 + 576 * a2 + dword_1AA1E8) <= v10 )
        {
          if ( (((int)*(uint8_t *)(v6 + dword_1AA214) >> a1) & 1) != 0 )
          {
            *v7 = v10;
            v7[1] = a3;
          }
          else
          {
            v7[1] = 72;
          }
          v7[2] = v10;
          v7[3] = a3;
        }
      }
    }
    if ( v7[1] == 0xFF )
    {
      v11 = word_19999A - 1;
      v19 = 113 * v11;
      v21 = 576 * v11;
      v20 = 8 * v11;
      while ( *v7 > 1u && v11 >= 0 )
      {
        if ( (((int)*(uint8_t *)(dword_1AA200 + v11) >> a1) & 1) != 0 )
        {
          v12 = (_BYTE *)(v19 + dword_19306C);
          if ( v11 == a3
            || v12[22] != 6 && v12[40] != 9 && ((((int)(uint8_t)v12[56] >> a1) & 1) != 0 || !v12[56]) )
          {
            v13 = *(uint8_t *)(a1 + v20 + dword_1AA1E8 + 576 * a2)
                + *(uint8_t *)(a1 + v21 + dword_1AA1E8 + 8 * a3);
            if ( (((int)*(uint8_t *)(dword_1AA214 + v11) >> a1) & 1) != 0 && v13 < *v7 )
            {
              *v7 = v13;
              if ( v11 == a2 )
                v7[1] = a3;
              else
                v7[1] = v11;
            }
            if ( v13 < v7[2] )
            {
              v7[2] = v13;
              if ( v11 == a2 )
                v7[3] = a3;
              else
                v7[3] = v11;
            }
          }
        }
        v19 -= 113;
        v21 -= 576;
        v20 -= 8;
        --v11;
      }
    }
    if ( v7[1] == 0xFF )
    {
      v7[1] = 72;
      if ( v7[3] == 0xFF )
        v7[3] = 72;
    }
  }
  if ( a4 )
  {
    if ( a5 && v7[3] < 0x48u )
    {
      v14 = v7[3];
LABEL_40:
      *a4 = v14;
      goto LABEL_45;
    }
    if ( !a5 && v7[1] < 0x48u )
    {
      v14 = v7[1];
      goto LABEL_40;
    }
    *a4 = -1;
  }
LABEL_45:
  if ( a5 )
    return v7[2];
  else
    return *v7;
}
// D3656: variable 'v9' is possibly undefined
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19999A: using guessed type int16_t word_19999A;
// 1AA1B8: using guessed type int dword_1AA1B8;
// 1AA1E8: using guessed type int dword_1AA1E8;
// 1AA200: using guessed type int dword_1AA200;
// 1AA214: using guessed type int dword_1AA214;


//----- (000D383F) --------------------------------------------------------
int16_t __fastcall sub_D383F( int a1, int a2, _WORD *a3)
{
  int v4; // ebx
  uint8_t *v5; // esi
  int v6; // eax
  int v7; // eax
  int16_t v8; // ax
  _BYTE *v9; // eax
  int v10; // eax
  int v13; // [esp+8h] [ebp-1Ch]
  int v14; // [esp+Ch] [ebp-18h]
  int v15; // [esp+14h] [ebp-10h]
  int v16; // [esp+18h] [ebp-Ch]
  int v17; // [esp+1Ch] [ebp-8h]
  char v18; // [esp+20h] [ebp-4h]

  v4 = 129 * a1;
  v5 = (uint8_t *)(dword_1AA1C0 + 144 * a1 + 2 * a2);
  v18 = sub_1276F0(v4 + dword_197F9C + 23, 0xBu);
  if ( v5[1] == 0xFF )
  {
    v6 = v4 + dword_197F9C;
    if ( *(int16_t *)(v4 + dword_197F9C + 101) >= 72 && *(int16_t *)(v6 + 101) < 1000 )
    {
      v13 = *(char *)(v6 + 99);
      v16 = word_19999A - 1;
      v17 = 113 * v16;
      v14 = *(int16_t *)(v6 + 101) - 500;
      v15 = 576 * v16;
      while ( *v5 > 1u && v16 >= 0 )
      {
        if ( (((int)*(uint8_t *)(v16 + dword_1AA214) >> v13) & 1) != 0
          || (((int)*(uint8_t *)(v16 + dword_1AA200) >> v13) & 1) != 0 && v18 )
        {
          v9 = (_BYTE *)(v17 + dword_19306C);
          if ( (a2 == v16
             || v16 == v14
             || v9[22] != 6 && v9[40] != 9 && ((((int)(uint8_t)v9[56] >> v13) & 1) != 0 || !v9[56]))
            && !sub_EB7FD(
                  *(int16_t *)(dword_197F9C + 129 * a1 + 103),
                  *(int16_t *)(dword_197F9C + 129 * a1 + 105),
                  *(int16_t *)(v17 + dword_19306C + 15),
                  *(int16_t *)(v17 + dword_19306C + 17)) )
          {
            v10 = *(uint8_t *)(v13 + dword_1AA1E8 + v15 + 8 * a2)
                + *(uint8_t *)(v16 + dword_1AA1B4 + 72 * a1);
            if ( v10 < *v5 )
            {
              *v5 = v10;
              v5[1] = v16;
            }
          }
        }
        v17 -= 113;
        v15 -= 576;
        --v16;
      }
      if ( v5[1] == 0xFF )
        v5[1] = 72;
    }
    else
    {
      v7 = dword_197F9C + 129 * a1;
      if ( *(int16_t *)(v7 + 101) >= 72 )
        v8 = sub_7A3E3(*(_WORD *)(v7 + 103), *(_WORD *)(v7 + 105));
      else
        v8 = *(_WORD *)(v7 + 101);
      *v5 = sub_D3576(*(char *)(dword_197F9C + 129 * a1 + 99), v8, a2, a3, v18);
      v5[1] = *(_BYTE *)a3;
    }
  }
  if ( a3 )
  {
    if ( v5[1] >= 0x48u )
      *a3 = -1;
    else
      *a3 = v5[1];
  }
  return *v5;
}
// 19306C: using guessed type int dword_19306C;
// 197F9C: using guessed type int dword_197F9C;
// 19999A: using guessed type int16_t word_19999A;
// 1AA1B4: using guessed type int dword_1AA1B4;
// 1AA1C0: using guessed type int dword_1AA1C0;
// 1AA1E8: using guessed type int dword_1AA1E8;
// 1AA200: using guessed type int dword_1AA200;
// 1AA214: using guessed type int dword_1AA214;


//----- (000D3A68) --------------------------------------------------------
char *__fastcall sub_D3A68( int a1, int a2, int a3)
{
  int v5; // edx
  int v6; // eax
  int16_t i; // si
  int v8; // eax
  int v9; // eax
  char *result; // eax
  int v11; // edx
  int v12; // ebx
  int v13; // esi
  int v14; // esi
  int v15; // ebx
  _DWORD v16[16]; // [esp+0h] [ebp-54h]
  int v17; // [esp+40h] [ebp-14h]
  int v18; // [esp+44h] [ebp-10h]
  int v19; // [esp+48h] [ebp-Ch]
  int v20; // [esp+4Ch] [ebp-8h]
  int v21; // [esp+50h] [ebp-4h]

  HIWORD(v5) = HIWORD(dword_19306C);
  v6 = dword_19306C + 113 * a1;
  LOWORD(v5) = *(_WORD *)(v6 + 15);
  LOWORD(v6) = *(_WORD *)(v6 + 17);
  v20 = v5;
  v21 = v6;
  memset(a2, 0, 8);
  memset(a3, 0, 8);
  for ( i = word_199998; i > 0; v16[i + 8] = (9 * v9 - (__CFSHL__((9 * v9) >> 31, 2) + 4 * ((9 * v9) >> 31))) >> 2 )
  {
    v8 = *(int16_t *)(dword_197F98 + 3753 * --i + 804);
    v9 = 900 * v8 * v8;
    v16[i] = v9;
  }
  result = (char *)(dword_192B18 + 361 * word_199996);
  while ( (unsigned int)result > dword_192B18 )
  {
    result -= 361;
    v11 = *result;
    if ( v11 != -1 && !*(_BYTE *)(a2 + v11) )
    {
      v18 = 17 * *((int16_t *)result + 1);
      v18 = 113 * *(uint8_t *)(v18 + dword_1930D4 + 2);
      v19 = *(int16_t *)(v18 + dword_19306C + 15);
      v12 = *(int16_t *)(v18 + dword_19306C + 17);
      v18 = (int16_t)v20;
      v13 = v19;
      v19 = v12;
      v17 = v13 - (int16_t)v20;
      v14 = (v12 - (int16_t)v21) * (v12 - (int16_t)v21) + v17 * v17;
      if ( v14 <= v16[v11 + 8] )
      {
        *(_BYTE *)(v11 + a3) = 1;
        v15 = *result;
        if ( v14 <= v16[v15] )
          *(_BYTE *)(a2 + v15) = 1;
      }
    }
  }
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;


//----- (000D3BA0) --------------------------------------------------------
void sub_D3BA0()
{
  int v0; // esi
  int v1; // edi
  int v2; // ecx
  int v3; // edx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  _BYTE *v8; // eax
  uint8_t v9; // dl
  _BYTE v10[8]; // [esp+0h] [ebp-38h] BYREF
  _BYTE v11[8]; // [esp+8h] [ebp-30h] BYREF
  int v12; // [esp+10h] [ebp-28h]
  int v13; // [esp+14h] [ebp-24h]
  int v14; // [esp+18h] [ebp-20h]
  int v15; // [esp+1Ch] [ebp-1Ch]
  int v16; // [esp+20h] [ebp-18h]
  _BYTE *v17; // [esp+24h] [ebp-14h]
  int v18; // [esp+28h] [ebp-10h]
  int v19; // [esp+2Ch] [ebp-Ch]
  int v20; // [esp+30h] [ebp-8h]
  int v21; // [esp+34h] [ebp-4h]

  v0 = word_19999A;
  v20 = 49 * word_19999A;
  v19 = 113 * word_19999A;
  while ( v0 > 0 )
  {
    v20 -= 49;
    v19 -= 113;
    v1 = word_199996;
    --v0;
    v18 = v20 + dword_1AA1F8 + 1;
    v2 = 361 * word_199996;
    while ( v2 > 0 )
    {
      v2 -= 361;
      v3 = *(char *)(v2 + dword_192B18);
      --v1;
      v12 = v3;
      if ( v3 != -1 )
      {
        v4 = 17 * *(int16_t *)(v2 + dword_192B18 + 2);
        v15 = 3753 * v3;
        v15 = *(int16_t *)(3753 * v3 + dword_197F98 + 804);
        if ( sub_D2AA9(v0, *(uint8_t *)(dword_1930D4 + v4 + 2), v15) )
          ++*(_BYTE *)(v18 + 6 * v12 + 4);
      }
    }
    sub_D3A68(v0, (int)v10, (int)v11);
    v5 = word_199998;
    v14 = v19;
    v13 = 3753 * word_199998;
    v17 = (_BYTE *)(v18 + 6 * word_199998);
    while ( v5 > 0 )
    {
      v13 -= 3753;
      --v5;
      v6 = *(uint8_t *)(v14 + dword_19306C + 56);
      v17 -= 6;
      v7 = v6 >> v5;
      v16 = dword_197F98 + v13;
      if ( (v7 & 1) != 0 )
      {
        LOWORD(v7) = word_199998;
        v21 = v7;
        v8 = v17;
        while ( (int16_t)v21 > 0 )
        {
          if ( (int16_t)--v21 != v5 && !*(_BYTE *)(dword_197F98 + 3753 * (int16_t)v21 + 36) )
          {
            if ( v10[(int16_t)v21] )
            {
              v9 = *(_BYTE *)(v16 + (int16_t)v21 + 1575);
              if ( v9 )
              {
                if ( v9 <= 3u )
                {
                  ++*v8;
                }
                else if ( v9 <= 6u )
                {
                  ++v8[2];
                }
              }
              else
              {
                ++v8[1];
              }
            }
            else if ( v11[(int16_t)v21] )
            {
              ++v8[3];
            }
          }
        }
      }
    }
  }
  JUMPOUT(0xD2AA2);
}
// D3D2F: control flows out of bounds to D2AA2
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 1AA1F8: using guessed type int dword_1AA1F8;


//----- (000D3D34) --------------------------------------------------------
void __usercall sub_D3D34(int a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  uint8_t v8; // dl
  int v9; // esi
  int16_t v10; // ax
  int16_t v11; // dx
  _WORD *v12; // eax
  int16_t v13; // ax
  _WORD *v14; // eax
  int v15; // eax
  int v16; // ecx
  int i; // esi
  int v18; // eax
  int v19; // esi
  int v20; // edx
  int v21; // eax
  int v22; // esi
  int v23; // ecx
  int16_t j; // cx
  int v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // edx
  int v29; // eax
  _BYTE *v30; // ebx
  int v31; // eax
  int v32; // eax
  int16_t v33; // dx
  int v34; // ebx
  int v35; // edx
  int16_t *v36; // edi
  int v37; // eax
  int v38; // esi
  char v39; // cl
  _BYTE *v40; // eax
  char *v41; // ebx
  int v42; // edx
  int v43; // esi
  int v44; // edi
  int v45; // eax
  int v46; // eax
  char v47; // cl
  int v48; // ecx
  int v49; // eax
  uint8_t *v50; // ecx
  uint8_t *v51; // esi
  int v52; // eax
  uint8_t *v53; // ebx
  uint8_t *v54; // eax
  uint8_t v55; // al
  int v56; // edx
  int v57; // eax
  int v58; // ebx
  int v59; // eax
  int v60; // ecx
  int v61; // esi
  int v62; // edx
  int v63; // ebx
  int v64; // esi
  int v65; // edx
  int v66; // eax
  int v67; // eax
  int v68; // eax
  int v69; // ebx
  int v70; // eax
  unsigned int v71; // edx
  int v72; // eax
  int v73; // eax
  int v74; // esi
  int v75; // edx
  char *v76; // eax
  int v77; // esi
  int v78; // ebx
  int v79; // ecx
  int v80; // eax
  int v81; // ebx
  int k; // edx
  int v83; // eax
  int v84; // eax
  int v85; // eax
  int v86; // edx
  int v87; // eax
  unsigned int v88; // ebx
  int v89; // eax
  int v90; // ecx
  _DWORD *v91; // eax
  int v92; // ecx
  int16_t *v93; // edx
  int16_t v94; // si
  int16_t *v95; // eax
  int v96; // edx
  int v97; // eax
  int m; // ebx
  int v99; // eax
  int v100; // ebx
  int v101; // edx
  int n; // eax
  int v103; // ecx
  int v104; // eax
  int v105; // eax
  int16_t v106; // dx
  int16_t v107; // ax
  int v108; // esi
  int v109; // ebx
  int v110; // edx
  int v111; // eax
  int v112; // ecx
  int v113; // edx
  int v114; // ebx
  int16_t *v115; // edi
  int v116; // ecx
  int v117; // eax
  int v118; // edx
  int v119; // eax
  int v120; // edx
  int v121; // esi
  int v122; // edx
  int v123; // eax
  int v124; // ecx
  int v125; // eax
  int16_t *v126; // ecx
  int v127; // esi
  int v128; // ebx
  int v129; // edx
  int v130; // eax
  int v131; // eax
  int16_t v132; // ax
  int v133; // ebx
  int v134; // eax
  int v135; // eax
  int16_t ii; // si
  int v137; // esi
  int v138; // eax
  int v139; // ecx
  int v140; // edx
  int v141; // edi
  int v142; // edi
  unsigned int jj; // ecx
  int v144; // [esp-4h] [ebp-ACEh]
  int16_t v145[576]; // [esp+0h] [ebp-ACAh] BYREF
  int16_t v146[576]; // [esp+480h] [ebp-64Ah] BYREF
  _BYTE v147[128]; // [esp+900h] [ebp-1CAh] BYREF
  char v148[4]; // [esp+980h] [ebp-14Ah] BYREF
  char v149; // [esp+984h] [ebp-146h]
  int v150; // [esp+990h] [ebp-13Ah]
  int v151; // [esp+994h] [ebp-136h]
  int v152; // [esp+998h] [ebp-132h]
  int v153; // [esp+99Ch] [ebp-12Eh]
  int v154; // [esp+9A0h] [ebp-12Ah]
  int v155; // [esp+9A4h] [ebp-126h]
  int v156; // [esp+9A8h] [ebp-122h]
  int v157; // [esp+9ACh] [ebp-11Eh]
  int v158; // [esp+9B0h] [ebp-11Ah]
  int v159; // [esp+9B4h] [ebp-116h]
  int v160; // [esp+9B8h] [ebp-112h]
  int v161; // [esp+9BCh] [ebp-10Eh]
  int v162; // [esp+9C0h] [ebp-10Ah]
  int v163; // [esp+9C4h] [ebp-106h]
  int v164; // [esp+9C8h] [ebp-102h]
  int v165; // [esp+9CCh] [ebp-FEh]
  int v166; // [esp+9D0h] [ebp-FAh]
  int v167; // [esp+9D4h] [ebp-F6h]
  int v168; // [esp+9D8h] [ebp-F2h]
  int v169; // [esp+9DCh] [ebp-EEh]
  _DWORD *v170; // [esp+9E0h] [ebp-EAh]
  int v171; // [esp+9E4h] [ebp-E6h]
  int v172; // [esp+9E8h] [ebp-E2h]
  int v173; // [esp+9ECh] [ebp-DEh]
  int v174; // [esp+9F0h] [ebp-DAh]
  int v175; // [esp+9F4h] [ebp-D6h]
  int v176; // [esp+9F8h] [ebp-D2h]
  int v177; // [esp+9FCh] [ebp-CEh]
  int v178; // [esp+A00h] [ebp-CAh]
  int v179; // [esp+A04h] [ebp-C6h]
  int v180; // [esp+A08h] [ebp-C2h]
  int v181; // [esp+A0Ch] [ebp-BEh]
  int v182; // [esp+A10h] [ebp-BAh]
  int v183; // [esp+A14h] [ebp-B6h]
  unsigned int v184; // [esp+A18h] [ebp-B2h]
  unsigned int v185; // [esp+A1Ch] [ebp-AEh]
  int v186; // [esp+A20h] [ebp-AAh]
  int v187; // [esp+A24h] [ebp-A6h]
  int v188; // [esp+A28h] [ebp-A2h]
  int16_t v189[2]; // [esp+A2Ch] [ebp-9Eh] BYREF
  int v190; // [esp+A30h] [ebp-9Ah]
  int v191; // [esp+A34h] [ebp-96h]
  int v192; // [esp+A38h] [ebp-92h]
  int v193; // [esp+A3Ch] [ebp-8Eh]
  int v194; // [esp+A40h] [ebp-8Ah]
  int v195; // [esp+A44h] [ebp-86h]
  int v196; // [esp+A48h] [ebp-82h]
  int v197; // [esp+A4Ch] [ebp-7Eh]
  int v198; // [esp+A50h] [ebp-7Ah]
  int v199; // [esp+A54h] [ebp-76h]
  int v200; // [esp+A58h] [ebp-72h]
  int v201; // [esp+A5Ch] [ebp-6Eh]
  int v202; // [esp+A60h] [ebp-6Ah]
  int v203; // [esp+A64h] [ebp-66h]
  int v204; // [esp+A68h] [ebp-62h]
  int v205; // [esp+A6Ch] [ebp-5Eh]
  int v206; // [esp+A70h] [ebp-5Ah]
  int v207; // [esp+A74h] [ebp-56h]
  unsigned int v208; // [esp+A78h] [ebp-52h]
  int v209; // [esp+A7Ch] [ebp-4Eh]
  int v210; // [esp+A80h] [ebp-4Ah]
  int v211; // [esp+A84h] [ebp-46h]
  int v212; // [esp+A88h] [ebp-42h]
  int v213; // [esp+A8Ch] [ebp-3Eh]
  int v214; // [esp+A90h] [ebp-3Ah]
  int v215; // [esp+A94h] [ebp-36h]
  int v216; // [esp+A98h] [ebp-32h]
  int v217; // [esp+A9Ch] [ebp-2Eh]
  int v218; // [esp+AA0h] [ebp-2Ah]
  int v219; // [esp+AA4h] [ebp-26h]
  int v220; // [esp+AA8h] [ebp-22h]
  int v221; // [esp+AACh] [ebp-1Eh]
  int v222; // [esp+AB0h] [ebp-1Ah]
  int v223; // [esp+AB4h] [ebp-16h]
  int v224; // [esp+AB8h] [ebp-12h]
  int v225; // [esp+ABCh] [ebp-Eh]
  int v226; // [esp+AC0h] [ebp-Ah]
  int v227; // [esp+AC4h] [ebp-6h]
  int v228; // [esp+AC8h] [ebp-2h]
  int v229; // [esp+ACCh] [ebp+2h]
  int v230; // [esp+AD0h] [ebp+6h]
  int v231; // [esp+AD4h] [ebp+Ah]
  int v232; // [esp+AD8h] [ebp+Eh]
  int v233; // [esp+ADCh] [ebp+12h]
  int v234; // [esp+AE0h] [ebp+16h]
  int v235; // [esp+AE4h] [ebp+1Ah]
  int v236; // [esp+AE8h] [ebp+1Eh]
  int v237; // [esp+AECh] [ebp+22h]
  int v238; // [esp+AF0h] [ebp+26h]
  int v239; // [esp+AF4h] [ebp+2Ah]
  int v240; // [esp+AF8h] [ebp+2Eh]
  int v241; // [esp+AFCh] [ebp+32h]
  int v242; // [esp+B00h] [ebp+36h]
  int v243; // [esp+B04h] [ebp+3Ah]
  int v244; // [esp+B08h] [ebp+3Eh]
  int v245; // [esp+B0Ch] [ebp+42h]
  int v246; // [esp+B10h] [ebp+46h]
  int v247; // [esp+B14h] [ebp+4Ah]
  int v248; // [esp+B18h] [ebp+4Eh]
  int v249; // [esp+B1Ch] [ebp+52h]
  int v250; // [esp+B20h] [ebp+56h]
  int v251; // [esp+B24h] [ebp+5Ah]
  int v252; // [esp+B28h] [ebp+5Eh]
  int v253; // [esp+B2Ch] [ebp+62h]
  int v254; // [esp+B30h] [ebp+66h]
  int v255; // [esp+B34h] [ebp+6Ah]
  int v256; // [esp+B38h] [ebp+6Eh]
  int v257; // [esp+B3Ch] [ebp+72h]
  char v258; // [esp+B40h] [ebp+76h]
  char v259; // [esp+B44h] [ebp+7Ah]
  uint8_t v260; // [esp+B48h] [ebp+7Eh]
  uint8_t v261; // [esp+B4Ch] [ebp+82h]
  char v262; // [esp+B50h] [ebp+86h]
  char v263; // [esp+B54h] [ebp+8Ah]
  char v264; // [esp+B58h] [ebp+8Eh]
  char v265; // [esp+B5Ch] [ebp+92h]
  char v266; // [esp+B60h] [ebp+96h]

  nullsub_14(a1);
  sub_1112EC(dword_192ED4, 8000);
  dword_1AA1DC = (int)sub_110D3C(dword_192ED4, 8000);
  dword_1AA1F4 = (int)sub_110D3C(dword_192ED4, 8000);
  dword_1AA1FC = (int)sub_110D3C(dword_192ED4, 4000);
  dword_1AA1BC = (int)sub_110D3C(dword_192ED4, 5760);
  dword_1AA210 = (int)sub_110D3C(dword_192ED4, 2304);
  dword_1AA1E0 = (int)sub_110D3C(dword_192ED4, 2304);
  dword_1AA1E8 = (int)sub_110D3C(dword_192ED4, 41472);
  dword_1AA1B8 = (int)sub_110D3C(dword_192ED4, (int)&loc_28800);
  dword_1AA1B4 = (int)sub_110D3C(dword_192ED4, 36000);
  dword_1AA1C0 = (int)sub_110D3C(dword_192ED4, 72000);
  dword_1AA208 = (int)sub_110D3C(dword_192ED4, (int)&loc_2D000);
  dword_1AA1EC = (int)sub_110D3C(dword_192ED4, 1750);
  dword_1AA204 = (int)sub_110D3C(dword_192ED4, 464);
  dword_1AA1F8 = (int)sub_110D3C(dword_192ED4, 3528);
  dword_1AA214 = (int)sub_110D3C(dword_192ED4, 72);
  dword_1AA200 = (int)sub_110D3C(dword_192ED4, 72);
  dword_1AA1F0 = (int)sub_110D3C(dword_192ED4, (int)&loc_2D000);
  dword_1AA1E4 = (int)sub_110D3C(dword_192ED4, 5760);
  dword_1AA1D8 = (int)sub_110D3C(dword_192ED4, 720);
  dword_1AA20C = (int)sub_110D3C(dword_192ED4, 576);
  dword_1AA1D4 = (int)sub_110D3C(dword_192ED4, 1000);
  off_183554 = &unk_1A8B34;
  dword_1AA1C8 = (int)sub_110D3C(dword_192ED4, 1168);
  dword_1AA1D0 = (int)sub_110D3C(dword_192ED4, 168);
  dword_1AA1C4 = (int)sub_110D3C(dword_192ED4, 24016);
  dword_1AA1CC = (int)sub_110D3C(dword_192ED4, 2000);
  v2 = memset(dword_1AA204, 0, 464);
  sub_FE8BE(v2, 0, 464, (int16_t *)a2);
  memset(dword_1AA1DC, 0, 8000);
  memset(dword_1AA1F4, 0, 8000);
  memset(dword_1AA1FC, 0, 4000);
  memset(dword_1AA1F0, 0, &loc_2D000);
  memset(dword_1AA1E4, 0, 5760);
  memset(dword_1AA1D8, 0, 720);
  v3 = 576;
  v4 = 0;
  v5 = memset(dword_1AA20C, 0, 576);
  LOWORD(v5) = word_199994;
  v255 = v5;
  while ( (int16_t)v255 > 0 )
  {
    v3 = 129 * (int16_t)--v255 + dword_197F9C;
    if ( *(char *)(v3 + 100) < 3 )
    {
      v6 = -1;
      v7 = *(char *)(v3 + 99);
      v8 = *(_BYTE *)(v3 + 100);
      v9 = -1;
      if ( v8 )
      {
        if ( v8 <= 1u )
        {
          v9 = *(uint8_t *)(v3 + 109);
          v6 = *(int16_t *)(v3 + 101) - 500;
        }
        else if ( v8 == 2 )
        {
          v9 = 0;
          v6 = (int16_t)sub_7A3E3(*(_WORD *)(v3 + 103), *(_WORD *)(v3 + 105));
        }
      }
      else
      {
        v6 = *(int16_t *)(v3 + 101);
        v9 = 0;
      }
      v4 = word_19999A;
      if ( v6 < word_19999A )
      {
        v266 = *(_BYTE *)(dword_19306C + 113 * v6 + 111);
        if ( v7 < 8 && v9 < 10 && *(_BYTE *)(dword_197F98 + 3753 * v7 + 40) == 100 )
          *(_BYTE *)(dword_1AA1D8 + 10 * v6 + v9) = 1;
        v217 = 8 * v6;
        v174 = 3753 * v7;
        v172 = 80 * v6;
        v4 = 10 * v7;
        v167 = 2560 * v6;
        v168 = 320 * v7;
        v169 = 4 * v9;
        a2 = word_199998;
        v166 = 58 * v7;
        v157 = 3753 * word_199998;
        v222 = 4 * word_199998;
        v223 = 40 * word_199998;
        v173 = 10 * v7;
        v158 = 2 * word_199998;
        while ( a2 > 0 )
        {
          v157 -= 3753;
          v222 -= 4;
          v223 -= 40;
          --a2;
          v158 -= 2;
          if ( a2 != v7 && !*(_BYTE *)(v157 + dword_197F98 + 36) )
          {
            if ( !*(_BYTE *)(v3 + 17) )
            {
              v164 = (int16_t)a2;
              v165 = (int16_t)v255;
              sub_5EF17(v255, a2);
              v11 = v10;
              v207 = 16 * (int16_t)v255;
              v12 = (_WORD *)(v158 + v207 + dword_1AA1DC);
              *v12 = v11;
              *(_DWORD *)(v222 + v166 + dword_1AA204 + 26) += (uint16_t)*v12;
              sub_5EF09(v165, v164);
              *(_WORD *)(v158 + v207 + dword_1AA1F4) = v13;
              v4 = dword_1AA1FC + 8 * v165;
              v14 = sub_5F379(v165, v4);
              sub_FE8BE((int)v14, v4, v3, (int16_t *)a2);
              if ( v7 < 8 && v9 < 10 )
              {
                v170 = (_DWORD *)(v223 + v168 + v167 + dword_1AA1F0 + v169);
                if ( v266 )
                  v15 = dword_1AA1F4;
                else
                  v15 = dword_1AA1DC;
                v171 = v15;
                v4 = (int)v170;
                *v170 += *(uint16_t *)(v158 + v15 + 16 * (int16_t)v255);
              }
            }
            if ( v7 < 8 )
            {
              if ( v9 < 10 )
                *(_BYTE *)(v9 + v173 + v172 + dword_1AA1E4) = 1;
              if ( !*(_BYTE *)(v174 + dword_197F98 + 2235) && !*(_BYTE *)(v7 + v217 + dword_1AA20C) )
              {
                v207 = 129;
                v4 = (v3 - dword_197F9C) % 129;
                if ( !sub_5D3DB((v3 - dword_197F9C) / 129) )
                  *(_BYTE *)(v7 + v217 + dword_1AA20C) = 1;
              }
            }
          }
        }
      }
    }
  }
  v16 = word_199998;
  for ( i = 3753 * word_199998; i > 0; memset(i + dword_197F98 + 1516, 0, 32) )
  {
    i -= 3753;
    v3 = 32;
    v4 = 0;
    --v16;
  }
  v176 = word_199994;
  v18 = 129 * word_199994;
  v19 = 16 * word_199994;
  v160 = v18;
  while ( v19 > 0 )
  {
    v160 -= 129;
    --v176;
    v18 = *(char *)(v160 + dword_197F9C + 99);
    v19 -= 16;
    if ( v18 < 8 )
    {
      v4 = word_199998;
      v3 = 2 * word_199998;
      v177 = 3753 * v18;
      v18 = 4 * word_199998;
      v178 = v19;
      v159 = v18;
      while ( v3 > 0 )
      {
        v159 -= 4;
        v3 -= 2;
        v18 = v159 + v177 + dword_197F98;
        --v4;
        *(_DWORD *)(v18 + 1516) += *(uint16_t *)(v178 + dword_1AA1DC + v3);
      }
    }
  }
  sub_FE8BE(v18, v4, v3, (int16_t *)a2);
  v20 = word_19999A;
  v226 = 80 * word_19999A;
  v21 = 2560 * word_19999A;
  v227 = v21;
  v22 = 10 * word_19999A;
  while ( v22 > 0 )
  {
    v226 -= 80;
    v227 -= 2560;
    v22 -= 10;
    --v20;
    v3 = 0;
    v218 = v22;
    v180 = v227;
    v225 = 0;
    v154 = v226;
    do
    {
      v23 = word_199998;
      v182 = v225;
      v162 = 10 * word_199998;
      v224 = 320 * word_199998;
      while ( v224 > 0 )
      {
        v224 -= 320;
        v179 = word_199998;
        v162 -= 10;
        v181 = v224;
        v155 = v162;
        --v23;
        v161 = 40 * word_199998;
        while ( v161 > 0 )
        {
          v161 -= 40;
          *(_DWORD *)(v182 + v161 + v181 + v180 + dword_1AA1F0 + 4) += *(_DWORD *)(v182
                                                                                 + v161
                                                                                 + v181
                                                                                 + v180
                                                                                 + dword_1AA1F0);
          a2 = v3 + v154 + dword_1AA1E4 + v155;
          --v179;
          if ( *(_BYTE *)a2 )
            *(_BYTE *)(a2 + 1) = 1;
        }
      }
      v21 = v3 + v218 + dword_1AA1D8;
      if ( *(_BYTE *)v21 )
        *(_BYTE *)(v21 + 1) = 1;
      ++v3;
      v225 += 4;
    }
    while ( v3 < 9 );
  }
  sub_FE8BE(v21, v20, v3, (int16_t *)a2);
  for ( j = word_199998; j > 0; *(_DWORD *)&v147[4 * j + 96] = v27 / 2 * (v27 / 2) )
  {
    v25 = 30 * *(int16_t *)(dword_197F98 + 3753 * --j + 804);
    v26 = v25 * v25;
    v27 = 90 * *(int16_t *)(dword_197F98 + 3753 * j + 804);
    *(_DWORD *)&v147[4 * j + 64] = v26;
  }
  memset(dword_1AA214, 0, 72);
  v28 = 0;
  memset(dword_1AA200, 0, 72);
  v29 = 361 * word_199996;
  v30 = (_BYTE *)(v29 + dword_192B18);
  while ( (unsigned int)v30 > dword_192B18 )
  {
    v29 = *(int16_t *)(v30 - 359);
    v30 -= 361;
    if ( v29 != -1 )
    {
      HIWORD(v28) = HIWORD(dword_19306C);
      v31 = dword_19306C + 113 * *(uint8_t *)(dword_1930D4 + 17 * v29 + 2);
      LOWORD(v28) = *(_WORD *)(v31 + 15);
      v29 = v31 + 31;
      LOWORD(a2) = word_19999A;
      v257 = v28;
      LOWORD(v28) = *(_WORD *)(v29 - 14);
      v219 = v29;
      v256 = v28;
      while ( (int16_t)a2 > 0 )
      {
        v32 = 113 * (int16_t)--a2 + dword_19306C;
        v33 = v256 - *(_WORD *)(v32 + 17);
        v207 = (int16_t)(v257 - *(_WORD *)(v32 + 15)) * (int16_t)(v257 - *(_WORD *)(v32 + 15));
        v28 = v33 * v33 + v207;
        v29 = (char)*v30;
        v183 = v28;
        if ( v28 <= *(_DWORD *)&v147[4 * v29 + 96] )
        {
          v28 = (int16_t)a2;
          v29 = sub_1276F0(v219, (int16_t)a2);
          if ( !(_WORD)v29 )
          {
            *(_BYTE *)((int16_t)a2 + dword_1AA200) |= 1 << *v30;
            v29 = (char)*v30;
            v28 = v183;
            if ( v183 <= *(_DWORD *)&v147[4 * v29 + 64] )
            {
              v28 = (int16_t)a2;
              v29 = sub_1276F0(v219, (int16_t)a2);
              if ( !(_WORD)v29 )
              {
                v29 = dword_1AA214;
                LOBYTE(v29) = 1 << *v30;
                *(_BYTE *)(dword_1AA214 + (int16_t)a2) |= v29;
              }
            }
          }
        }
      }
    }
  }
  sub_FE8BE(v29, v28, (int)v30, (int16_t *)a2);
  memset(dword_1AA1E8, 255, 41472);
  v34 = (int)&loc_28800;
  v35 = 255;
  memset(dword_1AA1B8, 255, &loc_28800);
  v36 = (int16_t *)word_19999A;
  v37 = 576 * word_19999A;
  v229 = v37;
  while ( (int)v36 > 0 )
  {
    v229 -= 576;
    v186 = word_199998;
    v37 = v229;
    v36 = (int16_t *)((char *)v36 - 1);
    v187 = v229;
    while ( v186 > 0 )
    {
      v37 = (int)*((uint8_t *)v36 + dword_1AA200) >> --v186;
      if ( (v37 & 1) != 0 )
      {
        v38 = word_19999A;
        v37 = 8 * word_19999A;
        v39 = v186;
        v228 = v37;
        while ( v38 > 0 )
        {
          v37 = (int)*(uint8_t *)(--v38 + dword_1AA200) >> v39;
          v228 -= 8;
          if ( (v37 & 1) != 0 )
          {
            v34 = (int16_t)v38;
            v35 = sub_FFBD6(v186, (int16_t)v36, v38);
            v40 = (_BYTE *)(v186 + v228 + v187 + dword_1AA1E8);
            *v40 = v35;
            sub_FE8BE((int)v40, v35, (int16_t)v38, v36);
          }
        }
      }
    }
  }
  sub_FE8BE(v37, v35, v34, v36);
  memset(dword_1AA1B4, 255, 36000);
  v41 = (_BYTE *)(&loc_1193F + 1);
  v42 = 255;
  memset(dword_1AA1C0, 255, 72000);
  v43 = word_199994;
  v44 = 129 * word_199994;
  v45 = 72 * word_199994;
  v230 = v45;
  while ( v43 > 0 )
  {
    v44 -= 129;
    v45 = v44 + dword_197F9C;
    v230 -= 72;
    --v43;
    if ( *(char *)(v44 + dword_197F9C + 100) < 5 && *(_BYTE *)(v45 + 100) == 1 )
    {
      v188 = (int16_t)sub_1003F2(v45, v42);
      v46 = v44 + dword_197F9C;
      v42 = v188 + v230 + dword_1AA1B4;
      LOBYTE(v41) = *(_BYTE *)(v44 + dword_197F9C + 109);
      *(_BYTE *)v42 = (_BYTE)v41;
      LOBYTE(v45) = sub_FF6BE(v46);
      if ( (_BYTE)v45 )
      {
        v47 = *(_BYTE *)(dword_197F9C + v44 + 99);
        v189[1] = -1;
        v189[0] = v43;
        v260 = 1 << v47;
        v45 = v230;
        v48 = word_19999A;
        v190 = v230;
        while ( v48 > 0 )
        {
          v42 = *(uint8_t *)(--v48 + dword_1AA200);
          v45 = v260;
          if ( (v260 & (uint8_t)v42) != 0 && v48 != v188 )
          {
            v41 = v148;
            sub_FF799(v189, v48, v148);
            v49 = v190 + dword_1AA1B4;
            v42 = v190 + dword_1AA1B4 + v48;
            LOBYTE(v49) = v149;
            *(_BYTE *)v42 = v149;
            sub_FE8BE(v49, v42, (int)v148, (int16_t *)v44);
          }
        }
      }
    }
  }
  sub_FE8BE(v45, v42, (int)v41, (int16_t *)v44);
  memset(dword_1AA1EC, 0, 1750);
  v50 = (uint8_t *)(dword_192B18 + 361 * word_199996);
  v51 = v50 + 12;
  while ( (unsigned int)v50 > dword_192B18 )
  {
    v50 -= 361;
    v51 -= 361;
    if ( (char)*v50 != -1 )
    {
      v52 = 7 * ((int)&v50[-dword_192B18] / 361);
      v53 = (uint8_t *)(v52 + dword_1AA1EC);
      sub_FE8BE(v52, (int)&v50[-dword_192B18] % 361, v52 + dword_1AA1EC, (int16_t *)v44);
      v53[6] = 0;
      v54 = &v51[4 * v50[10]];
      while ( v51 < v54 )
      {
        v54 -= 4;
        if ( (v54[1] & 4) != 0 )
          ++v53[6];
      }
      v55 = sub_D2A08(v50);
      *v53 = v55;
      v53[1] = sub_E0C1D((char *)v50, v55);
      v44 = dword_197F98 + 3753 * *v53;
      if ( !*(_BYTE *)(v44 + 2225) || !*(_BYTE *)(dword_197F98 + 3753 * (char)*v50 + 2225) )
        v53[2] = 1;
      if ( !*(_BYTE *)(v44 + 2230) )
        v53[4] = 1;
    }
  }
  v56 = word_199996;
  v57 = 361 * word_199996;
  v231 = v57;
  v58 = 7 * word_199996;
  while ( v58 > 0 )
  {
    v231 -= 361;
    v57 = v231 + dword_192B18;
    v58 -= 7;
    --v56;
    v191 = *(char *)(v231 + dword_192B18);
    if ( v191 != -1 )
    {
      v59 = 17 * *(int16_t *)(v57 + 2);
      v60 = 80 * *(uint8_t *)(dword_1930D4 + v59 + 2);
      v265 = 0;
      v175 = v58;
      sub_FE8BE(v59, v56, v58, (int16_t *)v44);
      v57 = word_199998;
      v192 = v60;
      v61 = 10 * word_199998;
      do
      {
        --v57;
        v61 -= 10;
        if ( v57 != v191 && *(_BYTE *)(v192 + dword_1AA1E4 + v61 + 9) )
        {
          v44 = v175 + dword_1AA1EC;
          v265 = 1;
          *(_BYTE *)(v175 + dword_1AA1EC + 5) = 1;
        }
      }
      while ( v57 > 0 && !v265 );
    }
  }
  sub_FE8BE(v57, v56, v58, (int16_t *)v44);
  v62 = 0;
  memset(dword_1AA1F8, 0, 3528);
  v63 = word_19999A;
  v235 = 113 * word_19999A;
  v236 = 80 * word_19999A;
  v64 = 49 * word_19999A;
  while ( v63 > 0 )
  {
    v235 -= 113;
    v236 -= 80;
    v65 = 10;
    v64 -= 49;
    --v63;
    v193 = v235;
    do
    {
      v66 = *(int16_t *)(v65 + v193 + dword_19306C + 72);
      v65 -= 2;
      if ( v66 != -1 )
        ++*(_BYTE *)(v64 + dword_1AA1F8);
    }
    while ( v65 );
    v67 = word_199998;
    v194 = v236;
    v233 = 3753 * word_199998;
    v62 = 6 * word_199998;
    v195 = v64;
    v234 = v62;
LABEL_122:
    while ( v67 > 0 )
    {
      v233 -= 3753;
      v234 -= 6;
      --v67;
      v62 = *(_BYTE *)(v233 + dword_197F98 + 40) != 100;
      if ( *(_BYTE *)(v233 + dword_197F98 + 40) != 100 && !*(_BYTE *)(v233 + dword_197F98 + 36) )
      {
        v62 = (int)*(uint8_t *)(dword_1AA200 + v63) >> v67;
        if ( (v62 & 1) != 0 )
        {
          v62 = word_199998;
          v232 = 10 * word_199998;
          while ( 1 )
          {
            --v62;
            v232 -= 10;
            if ( v62 != v67 )
            {
              v44 = v232;
              if ( *(_BYTE *)(v194 + dword_1AA1E4 + v232 + 9) )
                break;
            }
            if ( v62 <= 0 )
              goto LABEL_122;
          }
          v62 = v234 + v195 + dword_1AA1F8;
          *(_BYTE *)(v62 + 6) = 1;
        }
      }
    }
  }
  sub_D3BA0();
  sub_FE8BE(v68, v62, v63, (int16_t *)v44);
  v69 = word_199998;
  v70 = 3753 * word_199998;
  v238 = v70;
  while ( v69 > 0 )
  {
    sub_FE8BE(v70, v62, v69--, (int16_t *)v44);
    v44 = 58 * v69;
    v238 -= 3753;
    v71 = 113 * word_19999A + dword_19306C;
    while ( v71 > dword_19306C )
    {
      v72 = (int)*(uint8_t *)(v71 - 57) >> v69;
      v71 -= 113;
      if ( (v72 & 1) != 0 )
      {
        v73 = v44 + dword_1AA204;
        ++*(_WORD *)(v44 + dword_1AA204 + 6);
        if ( (((int)*(uint8_t *)(v71 + 42) >> v69) & 1) != 0 )
          ++*(_WORD *)(v73 + 8);
      }
    }
    v74 = 58 * v69;
    v262 = 1 << v69;
    v70 = v238;
    v62 = word_199998;
    v196 = v238;
    while ( v62 > 0 )
    {
      if ( --v62 != v69 )
      {
        v264 = 0;
        if ( *(_BYTE *)(v62 + v196 + dword_197F98 + 1412) )
        {
          v70 = dword_1AA204;
          v264 = 1;
          ++*(_WORD *)(v74 + dword_1AA204 + 10);
        }
        else
        {
          v261 = (1 << v62) | v262;
          v70 = word_19999A;
          v237 = 49 * word_19999A;
          while ( 1 )
          {
            if ( v70 <= 0 )
              goto LABEL_136;
            v237 -= 49;
            v44 = v237 + dword_1AA1F8;
            --v70;
            if ( *(_BYTE *)(v237 + dword_1AA1F8) )
            {
              v207 = *(uint8_t *)(dword_1AA200 + v70);
              v44 = (uint8_t)(v261 & v207);
              if ( v261 == v44 )
                break;
            }
          }
          v264 = 1;
        }
LABEL_136:
        if ( v264 )
        {
          v70 = v74 + dword_1AA204;
          ++*(_WORD *)(v70 + 12);
          *(_BYTE *)(v62 + v70 + 14) = 1;
        }
      }
    }
  }
  sub_FE8BE(v70, v62, v69, (int16_t *)v44);
  v75 = dword_192B18;
  v76 = (char *)(dword_192B18 + 361 * word_199996);
  while ( (unsigned int)v76 > dword_192B18 )
  {
    v76 -= 361;
    v75 = *v76;
    if ( v75 != -1 )
    {
      v77 = dword_1AA204;
      ++*(_WORD *)(58 * v75 + dword_1AA204);
      v69 = dword_19306C;
      v75 = (int)*(uint8_t *)(113 * *(uint8_t *)(17 * *((int16_t *)v76 + 1) + dword_1930D4 + 2)
                                    + dword_19306C
                                    + 42) >> *v76;
      if ( (v75 & 1) != 0 )
      {
        v75 = 58 * *v76;
        ++*(_WORD *)(v75 + v77 + 4);
      }
    }
  }
  sub_FE8BE((int)v76, v75, v69, (int16_t *)v44);
  v78 = word_199998;
  v79 = 0;
  v80 = 58 * word_199998;
  while ( v80 > 0 )
  {
    v80 -= 58;
    --v78;
    if ( v79 < *(int16_t *)(dword_1AA204 + v80) )
      v79 = *(int16_t *)(dword_1AA204 + v80);
  }
  v81 = word_199998;
  for ( k = 58 * word_199998; k > 0; *(_WORD *)(k + dword_1AA204 + 2) = v79 - *(_WORD *)(k + dword_1AA204) )
  {
    v80 = dword_1AA204;
    k -= 58;
    --v81;
  }
  sub_FE8BE(v80, k, v81, (int16_t *)v44);
  sub_D302E();
  sub_FE8BE(v83, k, v81, (int16_t *)v44);
  sub_D3125();
  sub_FE8BE(v84, k, v81, (int16_t *)v44);
  v85 = sub_DC47C(dword_1AA1D0);
  sub_FE8BE(v85, k, 24016, (int16_t *)v44);
  word_1AA218 = 0;
  memset(dword_1AA1C4, 0, 24016);
  v86 = 0;
  memset(dword_1AA1CC, 0, 2000);
  v87 = 129 * word_199994;
  v88 = v87 + dword_197F9C;
  while ( v88 > dword_197F9C )
  {
    v88 -= 129;
    if ( !*(_BYTE *)(v88 + 17) )
    {
      LOWORD(v87) = *(char *)(v88 + 99);
      if ( (int16_t)v87 < word_199998 && *(char *)(v88 + 100) < 3 && *(_BYTE *)(v88 + 127) != 4 )
      {
        v87 = dword_1AA1D4;
        v86 = 2 * word_1AA218;
        *(_WORD *)(v86 + dword_1AA1D4) = (int)(v88 - dword_197F9C) / 129;
        ++word_1AA218;
        if ( !*(_BYTE *)(v88 + 100) )
        {
          sub_FE8BE(v87, v86, v88, (int16_t *)v44);
          sub_D33D1(v88);
          v90 = v89;
          v44 = (int)(v88 - dword_197F9C) / 129;
          v91 = (_DWORD *)(dword_1AA1CC + 4 * v44);
          *v91 = v90;
          v92 = dword_1AA1C4;
          v93 = (int16_t *)(dword_1AA1C4 + 3002 * *(char *)(v88 + 99));
          *(_DWORD *)&v93[3 * *v93 + 2] = *v91;
          v87 = v92 + 3002 * *(char *)(v88 + 99);
          v86 = v87 + 6 * *(int16_t *)v87;
          if ( *(_DWORD *)(v86 + 4) )
          {
            *(_WORD *)(v86 + 2) = v44;
            v87 = 3002 * *(char *)(v88 + 99);
            ++*(_WORD *)(v92 + v87);
          }
        }
      }
    }
  }
  v94 = word_199998;
  while ( v94 > 0 )
  {
    --v94;
    sub_FE8BE(v87, v86, v88, (int16_t *)v44);
    v95 = (int16_t *)(3002 * v94 + dword_1AA1C4);
    v88 = 6;
    v86 = *v95;
    v87 = qsort(v95 + 1, v86, 6);
  }
  sub_FE8BE(v87, v86, v88, (int16_t *)v44);
  memset(dword_1AA1C8, -1, 1168);
  v96 = word_1AA218;
  v97 = qsort(dword_1AA1D4, word_1AA218, 2);
  for ( m = 0; ; ++m )
  {
    if ( (int16_t)m >= word_1AA218 )
    {
      sub_FE8BE(v97, v96, m, (int16_t *)v44);
      v100 = (int)&loc_2D000;
      v101 = 0;
      memset(dword_1AA208, 0, &loc_2D000);
      v198 = word_1AA218;
      n = 2 * word_1AA218;
      v242 = n;
      while ( v242 > 0 )
      {
        v242 -= 2;
        v103 = *(int16_t *)(v242 + dword_1AA1D4);
        v100 = 129 * v103;
        v258 = sub_1276F0(129 * v103 + dword_197F9C + 23, 0xBu);
        v44 = *(int16_t *)(129 * v103 + dword_197F9C + 101);
        v104 = *(char *)(129 * v103 + dword_197F9C + 99);
        v199 = v104;
        sub_FE8BE(v104, 11, 129 * v103, (int16_t *)v44);
        v105 = 129 * v103 + dword_197F9C;
        --v198;
        if ( *(_BYTE *)(v105 + 100) == 10 || v44 < word_19999A )
        {
          v200 = 0;
        }
        else if ( v44 < 1000 )
        {
          v44 -= 500;
          v200 = *(uint8_t *)(v105 + 109);
        }
        else
        {
          v106 = *(_WORD *)(v105 + 105);
          v107 = *(_WORD *)(v105 + 103);
          v200 = 0;
          v44 = (int16_t)sub_7A3E3(v107, v106);
        }
        v101 = dword_19306C;
        v259 = *(_BYTE *)(dword_19306C + 113 * v44 + 111);
        v201 = word_199998;
        v151 = 320 * v199;
        v240 = 40 * word_199998;
        n = 2 * word_199998;
        v203 = 16 * v103;
        v241 = n;
        while ( v201 > 0 )
        {
          v240 -= 40;
          --v201;
          n = v199;
          v241 -= 2;
          if ( v199 != v201 )
          {
            v204 = v241;
            v108 = word_19999A;
            v202 = v240;
            n = 2560 * word_19999A;
            v239 = n;
            while ( v108 > 0 )
            {
              n = (int)*(uint8_t *)(--v108 + dword_1AA200) >> v201;
              v239 -= 2560;
              if ( (n & 1) != 0 || v108 == v44 )
              {
                v100 = (int16_t)v108;
                v101 = sub_D3576(v199, v44, v108, 0, v258) + v200;
                v112 = v239;
                v150 = v101;
                for ( n = 4 * v101; n < 40; n += 4 )
                {
                  v100 = v202 + v151 + v112 + dword_1AA208 + n;
                  if ( v259 )
                    v113 = dword_1AA1F4;
                  else
                    v113 = dword_1AA1DC;
                  ++v150;
                  v101 = *(uint16_t *)(v204 + v203 + v113);
                  *(_DWORD *)v100 += v101;
                }
              }
            }
          }
        }
      }
      sub_FE8BE(n, v101, v100, (int16_t *)v44);
      v109 = 5760;
      v110 = 0;
      v111 = memset(dword_1AA1BC, 0, 5760);
      LOWORD(v111) = word_1999A2;
      while ( (int16_t)v111 > 0 )
      {
        --v111;
        v109 = dword_1930D4;
        v110 = *(int16_t *)(17 * (int16_t)v111 + dword_1930D4);
        if ( v110 != -1 )
        {
          v109 = *(char *)(361 * v110 + dword_192B18);
          v110 = (int)off_183554 + 720 * v109 + 2 * (int16_t)v111;
          LOWORD(v110) = *(_WORD *)v110;
          *(_WORD *)(dword_1AA1BC + 16 * (int16_t)v111 + 2 * v109) = v110;
        }
      }
      sub_FE8BE(v111, v110, v109, (int16_t *)v44);
      memset(dword_1AA1E0, 0, 2304);
      memset(dword_1AA210, 0, 2304);
      memset(v146, -1, sizeof(v146));
      memset(v145, 0, sizeof(v145));
      v114 = 64;
      memset(v147, 0, 64);
      v115 = (int16_t *)word_199998;
      v244 = 3753 * word_199998;
      v116 = 4 * word_199998;
      while ( (int)v115 > 0 )
      {
        v244 -= 3753;
        v117 = word_199998;
        v205 = v244;
        v263 = 0;
        v116 -= 4;
        v115 = (int16_t *)((char *)v115 - 1);
        v156 = v116 * 2;
        v243 = 3753 * word_199998;
        v118 = word_199998 + v116 * 2;
        while ( v117 > 0 )
        {
          v243 -= 3753;
          --v118;
          --v117;
          if ( *(_BYTE *)(v243 + dword_197F98 + 40) == 100 )
            v147[v118] = 1;
          v114 = v205 + dword_197F98;
          LOBYTE(v114) = *(_BYTE *)(v205 + dword_197F98 + v117 + 1575);
          if ( (uint8_t)v114 >= 4u && (uint8_t)v114 <= 6u )
            v263 = 1;
        }
        if ( !v263 )
        {
          v114 = 8;
          memset(&v147[v156], 1, 8);
        }
        v147[(_DWORD)&v115[v116]] = 0;
      }
      LOWORD(v115) = word_19999A;
      while ( (int16_t)v115 > 0 )
      {
        v115 = (int16_t *)((char *)v115 - 1);
        v119 = 113 * (int16_t)v115;
        v120 = v119 + dword_19306C;
        if ( *(_BYTE *)(v119 + dword_19306C + 56) )
        {
          v121 = v120 + 10;
          sub_FE8BE(v119, v120, v114, v115);
          v245 = v120;
          do
          {
            v122 = *(int16_t *)(v121 + 72);
            v121 -= 2;
            if ( v122 != -1 )
            {
              v114 = dword_1930D4;
              v123 = *(int16_t *)(dword_1930D4 + 17 * v122);
              if ( v123 != -1 )
              {
                v124 = 2 * *(char *)(dword_192B18 + 361 * v123);
                v125 = v124 + 16 * (int16_t)v115;
                v207 = *(int16_t *)((char *)v145 + v125);
                v206 = 16 * v122;
                v126 = (int16_t *)(16 * v122 + dword_1AA1BC + v124);
                v164 = (uint16_t)*v126;
                v114 = v207;
                if ( v207 < v164 )
                {
                  *(int16_t *)((char *)v146 + v125) = v122;
                  *(int16_t *)((char *)v145 + v125) = *v126;
                }
              }
            }
          }
          while ( v121 != v245 );
          v127 = word_199998;
          v250 = 8 * word_199998;
          v251 = 58 * word_199998;
          v211 = 40 * word_199998;
          v252 = 2 * word_199998;
          v197 = 4 * word_199998;
          while ( v127 > 0 )
          {
            v250 -= 8;
            v252 -= 2;
            v251 -= 58;
            v211 -= 40;
            v197 -= 4;
            --v127;
            if ( v146[8 * (int16_t)v115 + v252 / 2u] != -1 )
            {
              v209 = v146[8 * (int16_t)v115 + v252 / 2u];
              v210 = word_199998;
              v153 = v211;
              v213 = v251;
              v246 = v250 + word_199998;
              v247 = 58 * word_199998;
              v184 = 0;
              v208 = 0;
              v220 = 320 * word_199998;
              while ( v210 > 0 )
              {
                --v246;
                v247 -= 58;
                v220 -= 320;
                --v210;
                if ( v147[v246] )
                {
                  v128 = dword_1AA204 + v247;
                  v129 = 5 * *(int16_t *)(dword_1AA204 + v247 + 6);
                  v130 = *(int16_t *)(dword_1AA204 + v213 + 6);
                  v212 = 8;
                  if ( v129 < v130 )
                  {
                    if ( *(_WORD *)(v128 + 6) == 1 )
                      v212 = 1;
                    else
                      v212 = 4;
                  }
                  sub_FE8BE(v130, v129, v128, v115);
                  LOWORD(v131) = word_19999A;
                  v254 = v131;
                  v215 = v220;
                  while ( (int16_t)v254 > 0 )
                  {
                    v214 = (int16_t)--v254;
                    v185 = *(_DWORD *)(v153 + v215 + dword_1AA208 + 2560 * (int16_t)v254);
                    if ( v185 )
                    {
                      v132 = sub_D3576(v210, v214, (int16_t)v115, 0, 1);
                      if ( v132 < v212 )
                        v184 += v185 / (v132 + 1);
                    }
                  }
                }
              }
              v152 = word_1999A2;
              v221 = v252;
              v248 = 17 * word_1999A2;
              v249 = 16 * word_1999A2;
              while ( v152 > 0 )
              {
                --v152;
                v248 -= 17;
                v249 -= 16;
                if ( v152 != v209 )
                {
                  v144 = 0;
                  v133 = *(uint8_t *)(v248 + dword_1930D4 + 2);
                  LOWORD(v134) = sub_D3576(v127, (int16_t)v115, v133, 0, v144);
                  if ( (int16_t)v134 <= 2 )
                  {
                    sub_FE8BE(v134, (int16_t)v115, v133, v115);
                    v208 += *(uint16_t *)(v221 + v249 + dword_1AA1BC);
                  }
                }
              }
              v135 = *(int16_t *)((char *)&v145[8 * (int16_t)v115] + v221) + (v208 >> 4);
              v114 = 32 * (int16_t)v115;
              *(_DWORD *)(v197 + v114 + dword_1AA210) = v135;
              v184 = (v184 + 7) >> 3;
              *(_DWORD *)(v197 + v114 + dword_1AA1E0) = ((unsigned int)(v135 + 7) >> 3) * v184;
            }
          }
        }
      }
      for ( ii = word_199998; ii > 0; sub_DBE84(ii) )
        --ii;
      v137 = word_199998;
      v138 = 3753 * word_199998;
      v253 = v138;
      while ( v137 > 0 )
      {
        v253 -= 3753;
        v139 = word_19999A;
        v216 = v253;
        v138 = 113 * word_19999A;
        --v137;
        v163 = v138;
        while ( v139 > 0 )
        {
          v163 -= 113;
          v138 = v137 + v163 + dword_19306C;
          --v139;
          if ( *(char *)(v138 + 103) >= 8 )
          {
            v140 = dword_197F98;
            v141 = *(char *)(v138 + 103);
            *(_BYTE *)(v138 + 103) = -1;
            v138 = v216;
            v142 = v141 - 8;
            if ( !*(_BYTE *)(v140 + v216 + 36) )
            {
              v138 = 3753 * v142;
              if ( !*(_BYTE *)(v140 + 3753 * v142 + 36) )
              {
                LOBYTE(v138) = sub_E4A09(v139, v137, v142);
                if ( (_BYTE)v138 )
                  sub_E4AB3(v139, v137, v142);
              }
            }
          }
        }
      }
      nullsub_14(v138);
      for ( jj = 113 * word_19999A + dword_19306C; jj > dword_19306C; jj -= 113 )
        *(_BYTE *)(jj - 61) = 0;
      JUMPOUT(0xD2AA3);
    }
    v99 = 129 * *(int16_t *)(dword_1AA1D4 + 2 * (int16_t)m) + dword_197F9C;
    if ( *(int16_t *)(v99 + 101) >= 72 )
    {
      v96 = 2 * word_19999A + 146 * *(char *)(v99 + 99) + dword_1AA1C8;
      v97 = *(int16_t *)v96;
      if ( v97 != -1 )
        continue;
    }
    else
    {
      v96 = 146 * *(char *)(v99 + 99) + dword_1AA1C8 + 2 * *(int16_t *)(v99 + 101);
      v97 = *(int16_t *)v96;
      if ( v97 != -1 )
        continue;
    }
    *(_WORD *)v96 = m;
  }
}
// D5748: control flows out of bounds to D2AA3
// D4181: variable 'v10' is possibly undefined
// D41D6: variable 'v13' is possibly undefined
// D476C: variable 'v37' is possibly undefined
// D4893: variable 'v45' is possibly undefined
// D4B6F: variable 'v68' is possibly undefined
// D4D8E: variable 'v83' is possibly undefined
// D4D98: variable 'v84' is possibly undefined
// D4E64: variable 'v89' is possibly undefined
// D5500: variable 'v131' is possibly undefined
// D55DD: variable 'v134' is possibly undefined
// D5719: variable 'v138' is possibly undefined
// FE8BD: using guessed type int __fastcall nullsub_14(_DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 183554: using guessed type _UNKNOWN *off_183554;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 1999A2: using guessed type int16_t word_1999A2;
// 1AA1B4: using guessed type int dword_1AA1B4;
// 1AA1B8: using guessed type int dword_1AA1B8;
// 1AA1BC: using guessed type int dword_1AA1BC;
// 1AA1C0: using guessed type int dword_1AA1C0;
// 1AA1C4: using guessed type int dword_1AA1C4;
// 1AA1C8: using guessed type int dword_1AA1C8;
// 1AA1CC: using guessed type int dword_1AA1CC;
// 1AA1D0: using guessed type int dword_1AA1D0;
// 1AA1D4: using guessed type int dword_1AA1D4;
// 1AA1D8: using guessed type int dword_1AA1D8;
// 1AA1DC: using guessed type int dword_1AA1DC;
// 1AA1E0: using guessed type int dword_1AA1E0;
// 1AA1E4: using guessed type int dword_1AA1E4;
// 1AA1E8: using guessed type int dword_1AA1E8;
// 1AA1EC: using guessed type int dword_1AA1EC;
// 1AA1F0: using guessed type int dword_1AA1F0;
// 1AA1F4: using guessed type int dword_1AA1F4;
// 1AA1F8: using guessed type int dword_1AA1F8;
// 1AA1FC: using guessed type int dword_1AA1FC;
// 1AA200: using guessed type int dword_1AA200;
// 1AA204: using guessed type int dword_1AA204;
// 1AA208: using guessed type int dword_1AA208;
// 1AA20C: using guessed type int dword_1AA20C;
// 1AA210: using guessed type int dword_1AA210;
// 1AA214: using guessed type int dword_1AA214;
// 1AA218: using guessed type int16_t word_1AA218;


//----- (000D574D) --------------------------------------------------------
_DWORD *__fastcall sub_D574D(int a1, int a2)
{
  nullsub_14(a1);
  return sub_1113CC(dword_192ED4, a2);
}
// FE8BD: using guessed type int __fastcall nullsub_14(_DWORD);
// 192ED4: using guessed type int dword_192ED4;


//----- (000D5761) --------------------------------------------------------
int __fastcall sub_D5761(uint8_t *a1, uint8_t *a2)
{
  int v2; // ebx
  int v3; // edx

  v2 = dword_192B18 + 361 * *a1;
  v3 = (uint8_t)sub_DF8C1(361 * *a2 + dword_192B18);
  return v3 - (uint8_t)sub_DF8C1(v2);
}
// 192B18: using guessed type int dword_192B18;


//----- (000D5795) --------------------------------------------------------
int sub_D5795()
{
  char *v0; // ebx
  int result; // eax

  word_1AA238 = 0;
  word_1AA23A = 0;
  word_1AA236 = 0;
  memset(dword_1AA22C, 0, 13 * word_199996);
  v0 = (char *)(361 * word_199996 + dword_192B18);
  while ( (unsigned int)v0 > dword_192B18 )
  {
    v0 -= 361;
    if ( *v0 == word_1AA234 && !sub_2341E((int)&v0[-dword_192B18] / 361) && !v0[6] )
    {
      *(_BYTE *)(dword_1AA22C + 13 * word_1AA238) = (int)&v0[-dword_192B18] / 361;
      if ( (uint8_t)sub_DF8C1((int)v0) )
        ++word_1AA23A;
      else
        ++word_1AA236;
      ++word_1AA238;
    }
  }
  qsort(dword_1AA22C, word_1AA238, 13);
  dword_1AA220 = dword_1AA22C;
  result = 13 * word_1AA23A + dword_1AA22C;
  dword_1AA230 = result;
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;
// 1AA220: using guessed type int dword_1AA220;
// 1AA22C: using guessed type int dword_1AA22C;
// 1AA230: using guessed type int dword_1AA230;
// 1AA234: using guessed type int16_t word_1AA234;
// 1AA236: using guessed type int16_t word_1AA236;
// 1AA238: using guessed type int16_t word_1AA238;
// 1AA23A: using guessed type int16_t word_1AA23A;


//----- (000D589B) --------------------------------------------------------
void sub_D589B()
{
  uint8_t *i; // edx

  for ( i = (uint8_t *)(13 * word_1AA238 + dword_1AA22C);
        (unsigned int)i > dword_1AA22C;
        sub_D2754(361 * *i + dword_192B18) )
  {
    i -= 13;
  }
}
// 192B18: using guessed type int dword_192B18;
// 1AA22C: using guessed type int dword_1AA22C;
// 1AA238: using guessed type int16_t word_1AA238;


//----- (000D58D4) --------------------------------------------------------
int16_t __fastcall sub_D58D4( int a1)
{
  int v1; // eax
  uint8_t *v2; // esi
  int v3; // ecx
  int v4; // eax
  int v5; // edx
  uint8_t v6; // dl
  int16_t v7; // bx
  _BYTE v9[25]; // [esp+0h] [ebp-38h] BYREF
  char v10; // [esp+19h] [ebp-1Fh]
  char v11; // [esp+1Dh] [ebp-1Bh]
  char v12; // [esp+1Eh] [ebp-1Ah]
  char v13; // [esp+1Fh] [ebp-19h]
  char v14; // [esp+20h] [ebp-18h]
  char v15; // [esp+21h] [ebp-17h]
  char v16; // [esp+22h] [ebp-16h]
  char v17; // [esp+23h] [ebp-15h]
  char v18; // [esp+24h] [ebp-14h]
  char v19; // [esp+27h] [ebp-11h]
  char v20; // [esp+2Bh] [ebp-Dh]
  char v21; // [esp+31h] [ebp-7h]
  char v22; // [esp+34h] [ebp-4h]

  v22 = a1;
  v1 = 13 * word_1AA238;
  v2 = (uint8_t *)(v1 + dword_1AA22C);
  while ( (unsigned int)v2 > dword_1AA22C )
  {
    v2 -= 13;
    v3 = 361 * *v2 + dword_192B18;
    if ( !v22 )
    {
      v4 = *(int16_t *)(v3 + 277);
      if ( v4 != -1 )
      {
        v1 = v4 != -3 && v4 != -2 && v4 != -10;
        if ( v1 )
          continue;
      }
    }
    v1 = *(int16_t *)(v3 + 277);
    if ( v1 <= -100 )
    {
      v5 = -129 * (v1 + 100);
      LOWORD(v1) = dword_197F9C;
      if ( *(_BYTE *)(v5 + dword_197F9C + 100) == 4 )
        return v1;
    }
    memset(v9, 0, 50);
    v21 = 55;
    if ( *(_BYTE *)(v3 + 10) >= 5u && *(_BYTE *)(dword_1AA21C + 443) == 3 && !*(_BYTE *)(v3 + 349) )
      v19 = *(_BYTE *)(v3 + 10) + 25;
    if ( *(_BYTE *)(v3 + 10) >= 5u && *(_BYTE *)(dword_1AA21C + 414) == 3 && !*(_BYTE *)(v3 + 339) )
      v11 = *(_BYTE *)(v3 + 10) + 20;
    if ( *(_BYTE *)(dword_1AA21C + 457) == 3 && !*(_BYTE *)(v3 + 353) )
      v20 = 20;
    if ( *(_BYTE *)(dword_1AA21C + 366) == 3 && !*(_BYTE *)(v3 + 331) )
      v9[21] = 20;
    if ( *(_BYTE *)(dword_1AA21C + 301) == 3 && !*(_BYTE *)(v3 + 317) )
      v9[7] = 35;
    if ( *(_BYTE *)(dword_1AA21C + 435) == 3 && !*(_BYTE *)(v3 + 346) )
      v18 = 20;
    if ( *(_BYTE *)(dword_1AA21C + 328) == 3 && !*(_BYTE *)(v3 + 322) )
      v9[12] = 10;
    if ( *(_BYTE *)(dword_1AA21C + 433) == 3 && !*(_BYTE *)(v3 + 344) )
      v16 = 7;
    if ( *(_BYTE *)(v3 + 10) >= 5u && *(_BYTE *)(dword_1AA21C + 431) == 3 && !*(_BYTE *)(v3 + 343) )
      v15 = *(_BYTE *)(v3 + 10) + 15;
    if ( *(_BYTE *)(v3 + 10) >= 5u && !*(_BYTE *)(dword_1AA21C + 1437) )
    {
      if ( *(_BYTE *)(dword_1AA21C + 434) == 3 && !*(_BYTE *)(v3 + 345) )
        v17 = 20;
      if ( *(_BYTE *)(dword_1AA21C + 415) == 3 && !*(_BYTE *)(v3 + 340) )
        v12 = 10;
    }
    if ( *(char *)(dword_197F98 + 3753 * ((dword_1AA21C - dword_197F98) / 3753) + 2207) / 2 != 3 )
    {
      if ( (unsigned int)(*(char *)(dword_197F98 + 3753 * ((dword_1AA21C - dword_197F98) / 3753) + 2207) / 2) <= 1 )
      {
        if ( *(_BYTE *)(dword_1AA21C + 382) == 3 && !*(_BYTE *)(v3 + 332) && !*(_BYTE *)(v3 + 312) )
          v9[22] = 37;
        if ( *(_BYTE *)(dword_1AA21C + 293) == 3 && !*(_BYTE *)(v3 + 312) && !*(_BYTE *)(v3 + 332) )
          v9[2] = 10;
      }
      if ( *(_BYTE *)(v3 + 10) >= 3u && *(_BYTE *)(dword_1AA21C + 365) == 3 && !*(_BYTE *)(v3 + 330) )
        v9[20] = *(_BYTE *)(v3 + 10) + 25;
      if ( *(_BYTE *)(v3 + 10) >= 3u && *(_BYTE *)(dword_1AA21C + 420) == 3 && !*(_BYTE *)(v3 + 341) )
        v13 = *(_BYTE *)(v3 + 10) + 10;
    }
    if ( *(_BYTE *)(dword_1AA21C + 340) == 3 && !*(_BYTE *)(v3 + 325) )
      v9[15] = 30;
    if ( *(int16_t *)(v3 + 8) >= 5 && !v2[12] )
    {
      if ( *(_BYTE *)(dword_1AA21C + 329) == 3 && !*(_BYTE *)(v3 + 323) )
        v9[13] = sub_134C92(*(int16_t *)(v3 + 8)) + 8;
      if ( *(_BYTE *)(dword_1AA21C + 298) == 3 && !*(_BYTE *)(v3 + 315) )
        v9[5] = sub_134C92(*(int16_t *)(v3 + 8)) + 8;
      if ( *(_BYTE *)(dword_1AA21C + 421) == 3 && !*(_BYTE *)(v3 + 342) )
        v14 = 10;
    }
    if ( *(_BYTE *)(dword_1AA21C + 410) == 3 && !*(_BYTE *)(v3 + 335) )
    {
      v6 = *(_BYTE *)(17 * *(int16_t *)(v3 + 2) + dword_1930D4 + 6);
      if ( v6 )
      {
        if ( v6 <= 1u )
        {
          if ( !*(_BYTE *)(dword_1AA21C + 2217) )
            goto LABEL_94;
LABEL_89:
          v10 = 10;
          goto LABEL_94;
        }
        if ( v6 == 2 && !*(_BYTE *)(dword_1AA21C + 2218) )
          v10 = 20;
      }
      else if ( !*(_BYTE *)(dword_1AA21C + 2217) )
      {
        goto LABEL_89;
      }
    }
LABEL_94:
    LOWORD(v1) = sub_FE8DA((int)v9, 50);
    v7 = v1;
    if ( (int16_t)v1 < 49 )
    {
      LOWORD(v1) = sub_B20A1((v3 - dword_192B18) / 361);
      *(_WORD *)(v3 + 277) = v7;
    }
  }
  return v1;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 1AA21C: using guessed type int dword_1AA21C;
// 1AA22C: using guessed type int dword_1AA22C;
// 1AA238: using guessed type int16_t word_1AA238;


//----- (000D5CEE) --------------------------------------------------------
void sub_D5CEE()
{
  uint8_t *v0; // ebx
  int v1; // eax
  uint8_t *v2; // edi
  char *v3; // esi
  char v4[94]; // [esp+0h] [ebp-64h] BYREF
  int16_t v5; // [esp+5Eh] [ebp-6h]

  v5 = 0;
  v0 = (uint8_t *)(13 * word_1AA238 + dword_1AA22C);
  while ( (unsigned int)v0 > dword_1AA22C )
  {
    v0 -= 13;
    v1 = *(int16_t *)(dword_192B18 + 361 * *v0 + 277);
    if ( v1 <= -100 )
    {
      v2 = (uint8_t *)(-129 * (v1 + 100) + dword_197F9C);
      if ( !v2[17] )
      {
        if ( v2[16] >= 5u )
        {
          if ( !v5 )
            sub_56460(word_1AA234, v4);
          v3 = v4;
        }
        else
        {
          v3 = (char *)(dword_1AA21C + 806 + 99 * v2[16]);
        }
        qmemcpy(v2, v3, 0x63u);
      }
    }
  }
  JUMPOUT(0xD5CE7);
}
// D5D94: control flows out of bounds to D5CE7
// 192B18: using guessed type int dword_192B18;
// 197F9C: using guessed type int dword_197F9C;
// 1AA21C: using guessed type int dword_1AA21C;
// 1AA22C: using guessed type int dword_1AA22C;
// 1AA234: using guessed type int16_t word_1AA234;
// 1AA238: using guessed type int16_t word_1AA238;


//----- (000D5D99) --------------------------------------------------------
_WORD *__fastcall sub_D5D99(int a1)
{
  _WORD *result; // eax
  int v3; // edx
  int v4; // ebx

  result = (_WORD *)(dword_197F98 + 3753 * a1);
  if ( (int16_t)result[28] < 0 || (int16_t)result[88] < 0 )
  {
    v3 = 3753 * a1;
    v4 = 1 - *(int16_t *)(v3 + dword_197F98 + 56) * (uint8_t)byte_199CB0;
    if ( (int)sub_1247A0(0x32u) > v4 )
    {
      result = (_WORD *)(v3 + dword_197F98);
      if ( !*(_WORD *)(v3 + dword_197F98 + 54) )
      {
        if ( byte_199CB0 )
          result[27] = 5;
      }
    }
    else
    {
      result = (_WORD *)dword_197F98;
      *(_WORD *)(v3 + dword_197F98 + 54) += 5;
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (000D5E19) --------------------------------------------------------
void sub_D5E19()
{
  int16_t *v0; // edx
  unsigned int v1; // edx
  int v2; // eax
  int v3; // ebx
  int v4; // [esp+0h] [ebp-18h]
  int16_t *v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]
  int16_t *v9; // [esp+14h] [ebp-4h]

  v0 = (int16_t *)(3002 * word_1AA234 + dword_1AA1C4);
  v9 = v0;
  v8 = *v0;
  if ( dword_192FD8 > 35035 && *v0 )
  {
    v1 = 2 * (*(_DWORD *)&v0[3 * *v0 - 1] + (uint8_t)byte_D575C[(uint8_t)byte_199CB0]);
    v7 = sub_1247A0(0x384u) <= v1;
    if ( *(int16_t *)(58 * word_1AA234 + dword_1AA204) < 2
      || (int)sub_1247A0(*(int16_t *)(dword_197F98 + 3753 * word_1AA234 + 166)) <= 8 )
    {
      v7 = 0;
    }
    v5 = &v9[3 * v8];
    v4 = (int)&v9[3 * v8 + 1];
    v6 = (int)&v9[3 * v8 + 4];
    while ( v8 && v7 )
    {
      v5 -= 3;
      v2 = dword_197F9C + 129 * v5[1];
      v3 = *(int16_t *)(v2 + 101);
      v4 -= 6;
      v6 -= 6;
      --v8;
      if ( !*(_BYTE *)(10 * v3 + dword_1AA1D8 + 3)
        && (~(1 << word_1AA234) & *(uint8_t *)(dword_19306C + 113 * v3 + 56)) == 0 )
      {
        if ( *(_BYTE *)(v2 + 16) >= 5u )
          sub_56460(word_1AA234, (char *)v2);
        else
          qmemcpy((void *)v2, (void *)(99 * *(uint8_t *)(v2 + 16) + dword_1AA21C + 806), 0x63u);
        --*v9;
        --v7;
        memmove(v4, v6, 6 * (*v9 - v8));
      }
    }
  }
  JUMPOUT(0xD5CE7);
}
// D5E4A: control flows out of bounds to D5CE7
// 1399FF: using guessed type int __fastcall memmove(_DWORD, _DWORD, _DWORD);
// 192FD8: using guessed type int dword_192FD8;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199CB0: using guessed type char byte_199CB0;
// 1AA1C4: using guessed type int dword_1AA1C4;
// 1AA1D8: using guessed type int dword_1AA1D8;
// 1AA204: using guessed type int dword_1AA204;
// 1AA21C: using guessed type int dword_1AA21C;
// 1AA234: using guessed type int16_t word_1AA234;


//----- (000D5FA9) --------------------------------------------------------
void sub_D5FA9()
{
  JUMPOUT(0xD578F);
}
// D5FDC: control flows out of bounds to D578F


//----- (000D5FE1) --------------------------------------------------------
void __fastcall sub_D5FE1(uint8_t *a1)
{
  char *v2; // edi
  char v3; // al
  int16_t v4; // dx
  unsigned int v5; // eax
  int v6; // ebx
  unsigned int v7; // ebx
  unsigned int v8; // ebx
  char v9; // bl
  int v10; // eax
  int v11; // edx
  uint8_t v12; // al
  char *v13; // [esp+0h] [ebp-8h]
  char v14; // [esp+4h] [ebp-4h]

  v2 = (char *)(361 * *a1 + dword_192B18);
  v3 = *(_BYTE *)(dword_197F98 + 3753 * *v2 + 1437);
  a1[3] = 0;
  v14 = v3;
  a1[1] = 0;
  a1[2] = 0;
  v13 = v2 + 12;
  v4 = 0;
  v5 = (unsigned int)&v2[4 * (uint8_t)v2[10] + 12];
  while ( 1 )
  {
    if ( v5 <= (unsigned int)v13 )
    {
      if ( 2 * v4 < (uint8_t)v2[10] )
      {
        v10 = 3753 * *v2 + dword_197F98;
        if ( *(_BYTE *)(v10 + 2225) )
        {
          if ( *(int16_t *)(v10 + 176) >= 0 )
            a1[12] = 1;
        }
      }
      v11 = (uint8_t)v2[10];
      dword_1AA224 = (int)v2;
      qsort(v13, v11, 4);
      a1[4] = a1[3];
      v12 = v2[10];
      a1[5] = v12;
      a1[6] = v12;
      JUMPOUT(0xD5CE7);
    }
    v5 -= 4;
    v6 = *(_DWORD *)v5 & 0xF;
    if ( v6 == 8 || v6 == 9 )
    {
      ++a1[3];
      v7 = *(_DWORD *)v5 << 23 >> 30;
      if ( !v7 )
      {
        ++a1[1];
        goto LABEL_12;
      }
      if ( v7 <= 1 )
      {
        ++a1[2];
        goto LABEL_12;
      }
      if ( v7 != 2 || !v14 )
        goto LABEL_12;
    }
    *(_BYTE *)(v5 + 1) &= ~2u;
LABEL_12:
    v8 = *(_DWORD *)v5 & 0xF;
    if ( v8 < 8 && !*(_BYTE *)(dword_197F98 + 3753 * v8 + 2230) )
    {
      if ( (*(_BYTE *)(v5 + 1) & 4) == 0 || (v9 = v2[303], (uint8_t)v9 >= 2u) && (uint8_t)v9 <= 3u )
        ++v4;
    }
  }
}
// D6120: control flows out of bounds to D5CE7
// 192B18: using guessed type int dword_192B18;
// 197F98: using guessed type int dword_197F98;
// 1AA224: using guessed type int dword_1AA224;


//----- (000D6125) --------------------------------------------------------
int __fastcall sub_D6125(char *a1, int a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax

  sub_DDFD3(a1, a2, 0);
  v4 = v3;
  sub_DDFD3(a1, a2, 1);
  return v4 - v5;
}
// D6139: variable 'v3' is possibly undefined
// D6146: variable 'v5' is possibly undefined


