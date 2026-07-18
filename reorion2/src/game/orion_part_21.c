#include "orion_common.h"

/* Adresni rozsah: 0x13DABB - 0x14814C  (200 funkci) */

//----- (0013DABB) --------------------------------------------------------
int16_t __fastcall sub_13DABB( int a1, unsigned int a2, int a3)
{
  int v3; // eax
  bool v5; // [esp+0h] [ebp-2Ch]
  int v7; // [esp+Ch] [ebp-20h]
  int i; // [esp+14h] [ebp-18h]
  int j; // [esp+14h] [ebp-18h]

  LOWORD(v3) = a3;
  if ( dword_184984 )
  {
    LOWORD(v3) = word_189708;
    if ( *(uint8_t *)(a3 + 8) != word_189708 && (a1 == 1970 || a1 == 1983) )
    {
      if ( a1 == 1983 )
      {
        v3 = *(_DWORD *)a3;
        if ( *(_DWORD *)a3 == dword_18499C )
        {
          for ( i = 0; i < dword_1849B2; ++i )
          {
            if ( *(_BYTE *)(i + a3 + 12) && !byte_1BF590[16 * i + *(uint8_t *)(a3 + 8)] )
              byte_1BF590[16 * i + *(uint8_t *)(a3 + 8)] = 1;
          }
          if ( *(uint8_t *)(a3 + 11) == 255 )
          {
            byte_1C0890[*(uint8_t *)(a3 + 8)] = 1;
          }
          else if ( *(uint8_t *)(a3 + 11) == dword_1849D6 )
          {
            ++dword_1849D6;
            dword_1849C6 = 1;
          }
          v3 = sub_13D97D();
          if ( v3 )
          {
            dword_1849AC = 1;
            LOWORD(v3) = sub_13D75B();
          }
        }
      }
      else if ( !dword_1849BA )
      {
        v3 = *(_DWORD *)a3;
        if ( *(_DWORD *)a3 >= (unsigned int)dword_1C0690[*(uint8_t *)(a3 + 8)] )
        {
          if ( *(_DWORD *)a3 == dword_1C0690[*(uint8_t *)(a3 + 8)] )
          {
            LOWORD(v3) = sub_13D867(*(_BYTE *)(a3 + 8), *(_DWORD *)a3, 1);
          }
          else
          {
            if ( !dword_1849A8 && !dword_1849A4 )
              goto LABEL_36;
            v3 = *(uint8_t *)(a3 + 8);
            if ( v3 != dword_1849A8 )
              return v3;
            if ( (unsigned int)dword_1849A4 < *(_DWORD *)a3 )
            {
LABEL_36:
              sub_13D805();
              dword_1849A8 = *(uint8_t *)(a3 + 8);
              dword_1849A4 = *(_DWORD *)a3;
            }
            v3 = (uint8_t)byte_1C0590[*(uint8_t *)(a3 + 6)];
            if ( v3 != 1 )
            {
              byte_1C0590[*(uint8_t *)(a3 + 6)] = 1;
              ++dword_1849BE;
              if ( *(uint8_t *)(a3 + 11) > dword_1849DA )
                dword_1849DA = *(uint8_t *)(a3 + 11);
              if ( !(dword_1849BE % 5u) )
                sub_13D867(*(_BYTE *)(a3 + 8), *(_DWORD *)a3, 0);
              memcpy(dword_184988 + 338 * *(uint8_t *)(a3 + 6), a3 + 12, a2 - 12);
              v7 = 1;
              for ( j = 0; ; ++j )
              {
                v3 = *(uint8_t *)(a3 + 7);
                if ( v3 <= j )
                  break;
                v5 = v7 && byte_1C0590[j];
                v7 = v5;
              }
              if ( v7 )
              {
                dword_1849BA = 1;
                sub_13D867(*(_BYTE *)(a3 + 8), *(_DWORD *)a3, 1);
                dword_1C0990(
                  *(uint8_t *)(a3 + 8),
                  *(uint16_t *)(a3 + 9),
                  *(uint16_t *)(a3 + 4),
                  dword_184988);
                sub_13D805();
                v3 = *(_DWORD *)a3;
                dword_1C0690[*(uint8_t *)(a3 + 8)] = *(_DWORD *)a3;
                dword_1849BA = 0;
              }
            }
          }
        }
      }
    }
  }
  return v3;
}
// 13F35A: using guessed type int __fastcall memcpy(_DWORD, _DWORD, _DWORD);
// 184984: using guessed type int dword_184984;
// 184988: using guessed type int dword_184988;
// 18499C: using guessed type int dword_18499C;
// 1849A4: using guessed type int dword_1849A4;
// 1849A8: using guessed type int dword_1849A8;
// 1849AC: using guessed type int dword_1849AC;
// 1849B2: using guessed type int dword_1849B2;
// 1849BA: using guessed type int dword_1849BA;
// 1849BE: using guessed type int dword_1849BE;
// 1849C6: using guessed type int dword_1849C6;
// 1849D6: using guessed type int dword_1849D6;
// 1849DA: using guessed type int dword_1849DA;
// 189708: using guessed type int16_t word_189708;
// 1C0690: using guessed type int dword_1C0690[128];
// 1C0990: using guessed type int (__fastcall *dword_1C0990)(_DWORD, _DWORD, _DWORD, _DWORD);
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0013DE7E) --------------------------------------------------------
int __fastcall sub_13DE7E(int result, int a2, int a3)
{
  unsigned int v3; // [esp+Ch] [ebp-10h]
  signed int v4; // [esp+14h] [ebp-8h]

  v4 = (uint16_t)word_184992 / 0x152u + ((uint16_t)word_184992 % 0x152u != 0);
  v3 = 338;
  if ( result < v4 && dword_1849A0 )
  {
    dword_1C0994[0] = dword_18499C;
    LOWORD(dword_1C0994[1]) = word_184992;
    BYTE2(dword_1C0994[1]) = result;
    HIBYTE(dword_1C0994[1]) = (uint16_t)word_184992 / 0x152u + ((uint16_t)word_184992 % 0x152u != 0);
    LOBYTE(dword_1C0994[2]) = word_189708;
    *(_WORD *)((char *)&dword_1C0994[2] + 1) = a3;
    HIBYTE(dword_1C0994[2]) = dword_1849D6;
    if ( v4 - 1 == result )
    {
      v3 = (uint16_t)word_184992 % 0x152u;
      if ( !v3 )
        v3 = 338;
    }
    memcpy(&unk_1C09A0, 338 * result + dword_18498E, v3);
    sub_14E069((int)dword_1C0994, v3 + 12, a2, 1970, 1, 0);
    return j___delay(3);
  }
  return result;
}
// 13F2CC: using guessed type int __fastcall j___delay(_DWORD);
// 13F35A: using guessed type int __fastcall memcpy(_DWORD, _DWORD, _DWORD);
// 18498E: using guessed type int dword_18498E;
// 184992: using guessed type int16_t word_184992;
// 18499C: using guessed type int dword_18499C;
// 1849A0: using guessed type int dword_1849A0;
// 1849D6: using guessed type int dword_1849D6;
// 189708: using guessed type int16_t word_189708;
// 1C0994: using guessed type _DWORD dword_1C0994[3];


//----- (0013DFBF) --------------------------------------------------------
int __fastcall sub_13DFBF( int a1, int a2, unsigned int a3, unsigned int a4)
{
  int v6; // [esp+Ch] [ebp-14h]
  int v7; // [esp+10h] [ebp-10h]

  v7 = 0;
  v6 = dword_1C40EA;
  if ( !dword_184984 || a3 > (uint16_t)word_18498C || dword_1849A0 || a3 > 0x8000u )
    return -204;
  if ( a4 == word_189708 || sub_13D919() == 1 )
  {
    dword_1849AC = 1;
    return 1;
  }
  else
  {
    ++dword_18499C;
    memcpy(dword_1849D2, a2, a3);
    dword_18498E = dword_1849D2;
    word_184992 = a3;
    dword_184994 = a4;
    dword_1849A0 = 1;
    word_1849B0 = a1;
    dword_1849B2 = a3 / 0x152u + (a3 % 0x152u != 0);
    dword_1849C6 = 1;
    if ( a4 == 0x7FFF )
    {
      while ( v6 )
      {
        byte_1C0910[v7++] = *(_BYTE *)v6;
        v6 = *(_DWORD *)(v6 + 30);
      }
      dword_1849DE = v7;
    }
    else if ( a4 == 32766 )
    {
      while ( v6 )
      {
        if ( !strcmp(v6 + 2, &byte_184654) )
          byte_1C0910[v7++] = *(_BYTE *)v6;
        v6 = *(_DWORD *)(v6 + 30);
      }
      dword_1849DE = v7;
    }
    sub_13D6D8();
    return 1;
  }
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 13D6D8: using guessed type int sub_13D6D8(void);
// 13F35A: using guessed type int __fastcall memcpy(_DWORD, _DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 184984: using guessed type int dword_184984;
// 18498C: using guessed type int16_t word_18498C;
// 18498E: using guessed type int dword_18498E;
// 184992: using guessed type int16_t word_184992;
// 184994: using guessed type int dword_184994;
// 18499C: using guessed type int dword_18499C;
// 1849A0: using guessed type int dword_1849A0;
// 1849AC: using guessed type int dword_1849AC;
// 1849B0: using guessed type int16_t word_1849B0;
// 1849B2: using guessed type int dword_1849B2;
// 1849C6: using guessed type int dword_1849C6;
// 1849D2: using guessed type int dword_1849D2;
// 1849DE: using guessed type int dword_1849DE;
// 189708: using guessed type int16_t word_189708;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0013E186) --------------------------------------------------------
int __cdecl sub_13E186(int a1, int a2)
{
  int result; // eax
  char v3[500]; // [esp+0h] [ebp-1F8h] BYREF
  char *v4; // [esp+1F4h] [ebp-4h] BYREF

  v4 = &a2;
  if ( !dword_1849E6 )
        // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    dword_1849E6 = fopen(aLownetLog, aA);
  vsprintf(v3, a1, &v4);
  if ( fprintf(dword_1849E6, "%s", v3) == -1 )
    sub_126487(aLownetLogError, a1);
  fclose(dword_1849E6);
      // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    result = fopen(aLownetLog, aA);
  dword_1849E6 = result;
  return result;
}
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 13C8F0: using guessed type int __fastcall vsprintf(_DWORD, _DWORD, _DWORD);
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1849E6: using guessed type int dword_1849E6;


//----- (0013E47F) --------------------------------------------------------
int __fastcall sub_13E47F(int a1, uint8_t *a2, int a3, int a4)
{
  uint8_t *v4; // eax
  uint8_t *v5; // eax
  uint8_t v6; // al
  int16_t v8; // [esp+10h] [ebp-58h]
  int16_t v9; // [esp+18h] [ebp-50h]
  int v10; // [esp+20h] [ebp-48h]
  int v11; // [esp+24h] [ebp-44h]
  int16_t i; // [esp+28h] [ebp-40h]
  int v13; // [esp+30h] [ebp-38h]
  int16_t v15; // [esp+38h] [ebp-30h]
  int16_t v16; // [esp+3Ch] [ebp-2Ch]
  int v17; // [esp+40h] [ebp-28h]
  int v18; // [esp+44h] [ebp-24h]
  int v19; // [esp+4Ch] [ebp-1Ch]
  int v20; // [esp+50h] [ebp-18h]
  int16_t v21; // [esp+54h] [ebp-14h]
  int16_t v22; // [esp+60h] [ebp-8h]
  int16_t v23; // [esp+64h] [ebp-4h]

  v8 = a1;
  v13 = 0;
  word_1C0E34 = 0;
  v21 = -1;
  v9 = HIWORD(dword_1B3E82);
  LOWORD(a1) = word_1B3EA6;
  v10 = a1;
  LOWORD(a1) = word_1B3EA2;
  v11 = a1;
  while ( *(_BYTE *)(a4 + (int16_t)v13) )
  {
    v16 = 0;
    if ( v21 == -1 )
    {
      v23 = v8;
      v15 = a3 + v8 - 1;
    }
    else
    {
      v23 = v21;
      v15 = a3 + v8 - 1;
      v21 = -1;
    }
    for ( i = 0; i < word_1849EE && !v16; ++i )
    {
      if ( (int16_t)a2 >= word_1C0B04[i] && (int16_t)a2 <= word_1C0B0C[i]
        || (int16_t)a2 + (int16_t)v11 >= *(int *)((char *)&unk_1C0B02 + 2 * i) >> 16
        && (int16_t)a2 + v9 <= *(int *)((char *)&unk_1C0B0A + 2 * i) >> 16 )
      {
        if ( v23 < word_1C0AFC[i] && v15 > word_1C0AF4[i] )
        {
          if ( v23 >= word_1C0AF4[i] )
            v23 = word_1C0AFC[i] + 1;
          else
            v15 = word_1C0AF4[i] - 1;
        }
        if ( v23 >= v15 )
          v16 = 1;
      }
    }
    if ( !v16 )
    {
      LOWORD(v20) = v15 - v23 + 1;
      v17 = -1;
      v22 = -1;
      v18 = v13;
      while ( (int16_t)v20 >= -(int16_t)v10 )
      {
        if ( *(uint8_t *)(a4 + (int16_t)v18) < 0x20u )
        {
          if ( *(_BYTE *)(a4 + (int16_t)v18) == 20
            || *(_BYTE *)(a4 + (int16_t)v18) == 13
            || !*(_BYTE *)(a4 + (int16_t)v18)
            || *(_BYTE *)(a4 + (int16_t)v18) == 25
            || *(_BYTE *)(a4 + (int16_t)v18) == 29 )
          {
            v20 = -v10 - 1;
            v22 = *(uint8_t *)(a4 + (int16_t)v18);
          }
        }
        else
        {
          LOWORD(v20) = v20 - (v10 + (uint8_t)byte_1B3EA8[*(uint8_t *)(a4 + (int16_t)v18)]);
          if ( *(_BYTE *)(a4 + (int16_t)v18) == 32 )
            v17 = v18;
        }
        ++v18;
      }
      if ( !v22 )
        --v18;
      if ( v22 == -1 )
      {
        *((_WORD *)&dword_1C0BDA + ((int)unk_1C0E32 >> 16) + 1) = v23;
        *((_WORD *)&dword_1C0D6A + ((int)unk_1C0E32 >> 16) + 1) = v15;
        *((_WORD *)&dword_1C0B12 + ((int)unk_1C0E32 >> 16) + 1) = (_WORD)a2;
        *((_WORD *)&dword_1C0CA2 + ((int)unk_1C0E32 >> 16) + 1) = v13;
        ++word_1C0E34;
        if ( (int16_t)v17 != -1 )
        {
          *(_BYTE *)(a4 + (int16_t)v17) = 21;
          v13 = v17 + 1;
        }
      }
      else
      {
        *((_WORD *)&dword_1C0BDA + ((int)unk_1C0E32 >> 16) + 1) = v23;
        *((_WORD *)&dword_1C0D6A + ((int)unk_1C0E32 >> 16) + 1) = v15;
        *((_WORD *)&dword_1C0B12 + ((int)unk_1C0E32 >> 16) + 1) = (_WORD)a2;
        *((_WORD *)&dword_1C0CA2 + ((int)unk_1C0E32 >> 16) + 1) = v13;
        ++word_1C0E34;
        if ( v22 == 25 )
        {
          v4 = (uint8_t *)(a4 + (int16_t)v18);
          LOWORD(v4) = *v4;
          v19 = 10 * (_DWORD)(v4 - 48);
          v5 = (uint8_t *)(a4 + (int16_t)v18);
          LOWORD(v5) = *v5;
          a2 = &v5[v19 - 48 - v11];
          v18 += 2;
        }
        if ( v22 == 29 )
        {
          v6 = *(_BYTE *)(a4 + (int16_t)v18);
          a2 -= v11;
          v21 = 11 * (v6 - 48);
          v18 += 2;
        }
        v13 = v18;
      }
    }
    if ( v15 >= v8 + a3 - 1 )
      a2 += v11;
    else
      v21 = v15 + 1;
  }
  return 0;
}
// 1849EE: using guessed type int16_t word_1849EE;
// 1B3E82: using guessed type int dword_1B3E82;
// 1B3EA2: using guessed type int16_t word_1B3EA2;
// 1B3EA6: using guessed type int16_t word_1B3EA6;
// 1C0AF4: using guessed type int16_t word_1C0AF4[4];
// 1C0AFC: using guessed type int16_t word_1C0AFC[3];
// 1C0B04: using guessed type int16_t word_1C0B04[3];
// 1C0B0C: using guessed type int16_t word_1C0B0C[3];
// 1C0B12: using guessed type int dword_1C0B12;
// 1C0BDA: using guessed type int dword_1C0BDA;
// 1C0CA2: using guessed type int dword_1C0CA2;
// 1C0D6A: using guessed type int dword_1C0D6A;
// 1C0E34: using guessed type int16_t word_1C0E34;


//----- (0013EBFE) --------------------------------------------------------
int __fastcall sub_13EBFE(int a1)
{
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = i + a1;
    if ( !*(_BYTE *)(i + a1) )
      break;
    if ( *(_BYTE *)(i + a1) == 21 )
      *(_BYTE *)(i + a1) = 32;
  }
  return result;
}


//----- (0013EE7E) --------------------------------------------------------
int __fastcall sub_13EE7E( int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  int16_t i; // [esp+10h] [ebp-8h]
  int16_t j; // [esp+14h] [ebp-4h]

  result = a5;
  if ( a5 >= 1 )
  {
    sub_124B98();
    sub_124CCE();
    for ( i = 0; i < a5; ++i )
    {
      sub_125CE1();
      for ( j = i + a2; j <= a4; j += a5 )
        sub_138CEE(a1, j, a3, j);
      sub_124ECB();
    }
    return sub_124BCF();
  }
  return result;
}


//----- (0013F1D8) --------------------------------------------------------
void sub_13F1D8()
{
  word_184A34 = __SS__;
}
// 184A34: using guessed type int16_t word_184A34;


//----- (0013F486) --------------------------------------------------------
bool sub_13F486()
{
  bool result; // eax

  if ( !dword_184A54 )
  {
    sub_15421D((unsigned int)sub_13F486, (unsigned int)sub_144305);
    sub_1543A1((unsigned int)&dword_1C0E54, 4);
    sub_1543A1((unsigned int)&dword_1C0E58, 4);
    sub_1543A1((unsigned int)&dword_1C0E50, 4);
    sub_1543A1((unsigned int)&dword_1C0E38, 4);
    sub_1543A1((unsigned int)&dword_1C0E48, 4);
    sub_1543A1((unsigned int)&dword_1C0E44, 4);
    sub_1543A1((unsigned int)&dword_1C0E4C, 4);
    result = sub_1543A1((unsigned int)&dword_1C0E3C, 4);
    dword_184A54 = 1;
  }
  return result;
}
// 184A54: using guessed type int dword_184A54;
// 1C0E38: using guessed type int dword_1C0E38;
// 1C0E3C: using guessed type int dword_1C0E3C;
// 1C0E44: using guessed type int dword_1C0E44;
// 1C0E48: using guessed type int dword_1C0E48;
// 1C0E4C: using guessed type int dword_1C0E4C;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0013F52E) --------------------------------------------------------
int sub_13F52E()
{
  int result; // eax

  if ( (dword_1C0E38 != 99 || dword_1C0E48 != 59 || dword_1C0E44 != 59 || dword_1C0E38 != dword_1C0E4C)
    && ++dword_1C0E4C == 100 )
  {
    result = 0;
    dword_1C0E4C = 0;
    if ( ++dword_1C0E44 == 60 )
    {
      dword_1C0E44 = 0;
      if ( ++dword_1C0E48 == 60 )
      {
        dword_1C0E48 = 0;
        ++dword_1C0E38;
      }
    }
  }
  return result;
}
// 1C0E38: using guessed type int dword_1C0E38;
// 1C0E44: using guessed type int dword_1C0E44;
// 1C0E48: using guessed type int dword_1C0E48;
// 1C0E4C: using guessed type int dword_1C0E4C;


//----- (0013F59A) --------------------------------------------------------
int sub_13F59A()
{
  int v0; // ebp
  int v1; // edi
  int v2; // esi
  unsigned int i; // edx
  unsigned int j; // edx
  int v6; // [esp+0h] [ebp-1Ch]

  sub_154D80();
  v6 = dword_1C0E38;
  v0 = dword_1C0E48;
  v1 = dword_1C0E44;
  v2 = dword_1C0E4C;
  sub_154D8D();
  if ( dword_1C0E40 == 1 )
  {
    fprintf(dword_1C0E50, "[%.02u:%.02u:%.02u.%.02u] ", v6, v0, v1, v2);
  }
  else
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
  }
  for ( j = 1; j < dword_1C0E40; ++j )
    fprintf(dword_1C0E50, &unk_17B145);
  return 1;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E38: using guessed type int dword_1C0E38;
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E44: using guessed type int dword_1C0E44;
// 1C0E48: using guessed type int dword_1C0E48;
// 1C0E4C: using guessed type int dword_1C0E4C;
// 1C0E50: using guessed type int dword_1C0E50;


//----- (0013F640) --------------------------------------------------------
void sub_13F640()
{
  char *v0; // edx
  int v1; // eax
  int v2; // ebx
  int64_t v3; // rax
  char v4; // [esp+0h] [ebp-10h] BYREF

  sub_13F486();
  LOWORD(v0) = 0;
  dword_1C0E54 = 0;
  dword_1C0E58 = 0;
  v1 = getenv(aAilDebug);
  v2 = v1;
  if ( !v1 )
    goto LABEL_2;
  if ( getenv(aAilSysDebug) )
    dword_1C0E58 = 1;
  v0 = aWT;
      // DECOMP_TODO (castecne vyreseno ve vlne 06): chybel mod parametr - v okoli se nenaslo jednoznacne fread/fwrite, takze "aRb" je bezpecny odhad (needela zadnou zapisovou vedlejsi ucinek jako by mohl "wb"), potrebuje overit.
    v1 = fopen(v2, aRb);
  dword_1C0E50 = v1;
  if ( v1 )
  {
    if ( isatty(*(_DWORD *)(v1 + 16), aWT) )
      setbuf(dword_1C0E50, 0);
    v3 = time(&v4);
    LODWORD(v3) = ((int(*)())(void*)localtime)((int)&v4, (time_t *)HIDWORD(v3));
    LODWORD(v3) = ((int(*)())(void*)asctime)(v3, (struct tm *)HIDWORD(v3));
    WORD2(v3) = v3;
    strcpy(byte_1C0E5C, v3);
    byte_1C0E74 = 0;
    fprintf(dword_1C0E50, "-------------------------------------------------------------------------------\n");
    fprintf(dword_1C0E50, "Audio Interface Library application usage script generated by AIL V%s\n", a302);
    fprintf(dword_1C0E50, "Start time: %s\n", byte_1C0E5C);
    LODWORD(v3) = fprintf(
                    dword_1C0E50,
                    "-------------------------------------------------------------------------------\n\n");
    sub_155F76(v3, WORD2(v3));
    dword_1C0E38 = 0;
    dword_1C0E48 = 0;
    dword_1C0E44 = 0;
    dword_1C0E4C = 0;
    dword_1C0E3C = sub_155542((int)sub_13F52E);
    sub_1556D4(dword_1C0E3C, 0x64u);
    sub_1555FC(dword_1C0E3C);
    dword_1C0E54 = 1;
    dword_1C0E40 = 1;
    sub_13F59A();
    dword_1C0E40 = 0;
    fprintf(dword_1C0E50, "AIL_startup()\n");
  }
  else
  {
LABEL_2:
    sub_155F76(v1, (uint16_t)v0);
  }
}
// 13C905: using guessed type int64_t __fastcall time(_DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 155777: using guessed type int __fastcall getenv(_DWORD);
// 156130: using guessed type int __fastcall isatty(_DWORD, _DWORD);
// 156157: using guessed type int __fastcall setbuf(_DWORD, _DWORD);
// 1C0E38: using guessed type int dword_1C0E38;
// 1C0E3C: using guessed type int dword_1C0E3C;
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E44: using guessed type int dword_1C0E44;
// 1C0E48: using guessed type int dword_1C0E48;
// 1C0E4C: using guessed type int dword_1C0E4C;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;
// 1C0E74: using guessed type char byte_1C0E74;


//----- (0013F7BC) --------------------------------------------------------
int sub_13F7BC()
{
  int v0; // edx
  int result; // eax

  v0 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v0 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_shutdown()\n");
  result = sub_15607C();
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) )
  {
    result = sub_155536();
    if ( !result )
      result = fclose(dword_1C0E50);
  }
  --dword_1C0E40;
  return result;
}
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0013F84F) --------------------------------------------------------
void __cdecl sub_13F84F(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_preference(%d,%d)\n", a1, a2);
  sub_155C19(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13FCCA);
  }
  JUMPOUT(0x13FCD2);
}
// 13F944: control flows out of bounds to 13FCCA
// 13F8CD: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0013F953) --------------------------------------------------------
void __usercall sub_13F953(int a1, int a2, int a3)
{
  int v3; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_get_real_vect(0x%X)\n", a3);
  sub_1550B1(a3, v3, a2, a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415CA);
  }
  JUMPOUT(0x13FCD2);
}
// 13FA39: control flows out of bounds to 1415CA
// 13F9C8: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0013FA3E) --------------------------------------------------------
void __cdecl sub_13FA3E(int a1, int a2)
{
  int v2; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_real_vect(0x%X,0x%X)\n", a1, a2);
  sub_1550DD();
  JUMPOUT(0x13FBAC);
}
// 13FAB2: control flows out of bounds to 13FBAC
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0013FAB7) --------------------------------------------------------
void __cdecl sub_13FAB7(int a1, int a2, int a3)
{
  int v3; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_USE16_ISR(%d,0x%X,%u)\n", a1, a2, a3);
  sub_155159(a1, a2, a3);
  JUMPOUT(0x13FB34);
}
// 13FB2F: control flows out of bounds to 13FB34
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0013FB41) --------------------------------------------------------
int __cdecl sub_13FB41(int a1)
{
  int v1; // edx
  int result; // eax

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_restore_USE16_ISR(%d)\n", a1);
  result = sub_15536F(a1);
  --dword_1C0E40;
  return result;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0013FBBA) --------------------------------------------------------
void __cdecl sub_13FBBA(unsigned int a1)
{
  sub_1553B8(a1);
}


//----- (0013FBC8) --------------------------------------------------------
int __cdecl sub_13FBC8(int a1, int a2, _WORD *a3, _WORD *a4)
{
  int v4; // edx
  int v6; // esi
  unsigned int i; // edx
  unsigned int j; // edx

  v4 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v4 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_call_driver(0x%X,0x%X,0x%X,0x%X)\n", a1, a2, a3, a4);
  v6 = sub_15541F(a1, a2, a3, a4);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    fprintf(dword_1C0E50, "Result = %d\n", v6);
  }
  --dword_1C0E40;
  return v6;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0013FCDE) --------------------------------------------------------
void __cdecl sub_13FCDE(int a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_delay(%d)\n", a1);
  sub_1554F9(a1);
  JUMPOUT(0x13FBA9);
}
// 13FD46: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0013FD50) --------------------------------------------------------
int __cdecl sub_13FD50(int a1, char *a2)
{
  int v2; // edx
  int v4; // edi
  unsigned int i; // edx
  unsigned int j; // edx
  unsigned int k; // edx
  unsigned int m; // edx
  unsigned int n; // edx
  unsigned int ii; // edx
  unsigned int jj; // edx
  unsigned int kk; // edx
  unsigned int mm; // edx
  unsigned int nn; // edx
  unsigned int i1; // edx
  unsigned int i2; // edx
  unsigned int i3; // edx
  unsigned int i4; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_API_read_INI(0x%X,%s)\n", a1, a2);
  v4 = sub_155951((void *)a1, (int)a2);
  if ( v4 )
  {
    if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
    {
      for ( i = 0; i < 0xE; ++i )
        fprintf(dword_1C0E50, " ");
      for ( j = 1; j < dword_1C0E40; ++j )
        fprintf(dword_1C0E50, &unk_17B145);
      fprintf(dword_1C0E50, "Driver = %s\n", (char *)(a1 + 128));
      for ( k = 0; k < 0xE; ++k )
        fprintf(dword_1C0E50, " ");
      for ( m = 1; m < dword_1C0E40; ++m )
        fprintf(dword_1C0E50, &unk_17B145);
      fprintf(dword_1C0E50, "Device = %s\n", (char *)a1);
      for ( n = 0; n < 0xE; ++n )
        fprintf(dword_1C0E50, " ");
      for ( ii = 1; ii < dword_1C0E40; ++ii )
        fprintf(dword_1C0E50, &unk_17B145);
      fprintf(dword_1C0E50, "IO     = %X\n", *(int16_t *)(a1 + 256));
      for ( jj = 0; jj < 0xE; ++jj )
        fprintf(dword_1C0E50, " ");
      for ( kk = 1; kk < dword_1C0E40; ++kk )
        fprintf(dword_1C0E50, &unk_17B145);
      fprintf(dword_1C0E50, "IRQ    = %d\n", *(int16_t *)(a1 + 258));
      for ( mm = 0; mm < 0xE; ++mm )
        fprintf(dword_1C0E50, " ");
      for ( nn = 1; nn < dword_1C0E40; ++nn )
        fprintf(dword_1C0E50, &unk_17B145);
      fprintf(dword_1C0E50, "DMA_8  = %d\n", *(int16_t *)(a1 + 260));
      for ( i1 = 0; i1 < 0xE; ++i1 )
        fprintf(dword_1C0E50, " ");
      for ( i2 = 1; i2 < dword_1C0E40; ++i2 )
        fprintf(dword_1C0E50, &unk_17B145);
      fprintf(dword_1C0E50, "DMA_16 = %d\n", *(int16_t *)(a1 + 262));
    }
  }
  else if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i3 = 0; i3 < 0xE; ++i3 )
      fprintf(dword_1C0E50, " ");
    for ( i4 = 1; i4 < dword_1C0E40; ++i4 )
      fprintf(dword_1C0E50, &unk_17B145);
    fprintf(dword_1C0E50, "Result = %u\n", 0);
  }
  --dword_1C0E40;
  return v4;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001400A9) --------------------------------------------------------
void __cdecl sub_1400A9(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_register_timer(0x%X)\n", a1);
  sub_155542(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415CA);
  }
  JUMPOUT(0x13FCD2);
}
// 14018F: control flows out of bounds to 1415CA
// 14011E: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140194) --------------------------------------------------------
void __cdecl sub_140194(int a1, int32_t a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_timer_user(%u,%u)\n", a1, a2);
  sub_155589(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13F93D);
  }
  JUMPOUT(0x13FCD2);
}
// 140282: control flows out of bounds to 13F93D
// 140212: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140287) --------------------------------------------------------
void __cdecl sub_140287(int a1, int a2)
{
  int v2; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_timer_period(%u,%u)\n", a1, a2);
  sub_1556A4(a1, a2);
  JUMPOUT(0x13FAAF);
}
// 1402F8: control flows out of bounds to 13FAAF
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001402FD) --------------------------------------------------------
void __cdecl sub_1402FD(int a1, unsigned int a2)
{
  int v2; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_timer_frequency(%u,%u)\n", a1, a2);
  sub_1556D4(a1, a2);
  JUMPOUT(0x13FAAF);
}
// 14036E: control flows out of bounds to 13FAAF
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001403E9) --------------------------------------------------------
void sub_1403E9()
{
  int v0; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v0 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v0 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_interrupt_divisor()\n");
  sub_155746();
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140F63);
  }
  JUMPOUT(0x13FCD2);
}
// 1404C2: control flows out of bounds to 140F63
// 140451: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001404C7) --------------------------------------------------------
void __cdecl sub_1404C7(int a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_start_timer(%u)\n", a1);
  sub_1555FC(a1);
  JUMPOUT(0x13FBA9);
}
// 14052F: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140596) --------------------------------------------------------
void __cdecl sub_140596(int a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_stop_timer(%u)\n", a1);
  sub_155650(a1);
  JUMPOUT(0x13FBA9);
}
// 1405FE: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140665) --------------------------------------------------------
void __cdecl sub_140665(int a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_release_timer_handle(%u)\n", a1);
  sub_1555B1(a1);
  JUMPOUT(0x13FBA9);
}
// 1406CD: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001406D2) --------------------------------------------------------
void sub_1406D2()
{
  int v0; // edx

  v0 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v0 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_release_all_timers()\n");
  sub_1555D8();
  JUMPOUT(0x13F847);
}
// 14072F: control flows out of bounds to 13F847
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140734) --------------------------------------------------------
void __cdecl sub_140734(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_get_IO_environment(0x%X)\n", a1);
  sub_155F05(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13FA33);
  }
  JUMPOUT(0x13FCD2);
}
// 140814: control flows out of bounds to 13FA33
// 1407A9: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140819) --------------------------------------------------------
void __cdecl sub_140819(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_install_driver(0x%X,%u)\n", a1, a2);
  sub_155C32(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13F93D);
  }
  JUMPOUT(0x13FCD2);
}
// 140907: control flows out of bounds to 13F93D
// 140897: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014090C) --------------------------------------------------------
void __cdecl sub_14090C(unsigned int a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_uninstall_driver(0x%X)\n", a1);
  sub_155E62(a1);
  JUMPOUT(0x13FBA9);
}
// 140974: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140979) --------------------------------------------------------
void sub_140979()
{
  int v0; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v0 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v0 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_install_DIG_INI()\n");
  // DECOMP_TODO (vlna 12): sub_157570 = skutecna instalace DOS zvukoveho
  // driveru dle DIG.INI (real-mode .DIG driver, INT volani) - v portu
  // padala a zadny DOS driver stejne neexistuje. Preskoceno = "zadny
  // zvukovy driver nenalezen"; volajici sub_111F3E (pres v1=0 placeholder)
  // pak bezi TISE a preskoci nacitani SOUND.LBX. Az vznikne port_sound
  // (SDL3), napoji se sem.
  PortDebug_Checkpoint("AIL.install_DIG_INI.skipped", 0);
  // sub_157570();
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140F63);
  }
  JUMPOUT(0x13FCD2);
}
// 140A52: control flows out of bounds to 140F63
// 1409E1: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140A57) --------------------------------------------------------
void __cdecl sub_140A57(char *a1, void *a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_install_DIG_driver_file(%s,0x%X)\n", a1, a2);
  sub_1574B0((int)a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140901);
  }
  JUMPOUT(0x13FCD2);
}
// 140B3F: control flows out of bounds to 140901
// 140AD5: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140BB1) --------------------------------------------------------
void __cdecl sub_140BB1(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_allocate_sample_handle(0x%X)\n", a1);
  sub_157610(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13FA33);
  }
  JUMPOUT(0x13FCD2);
}
// 140C91: control flows out of bounds to 13FA33
// 140C26: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140C96) --------------------------------------------------------
void __cdecl sub_140C96(int a1, int a2, int a3)
{
  int v3; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_allocate_file_sample(0x%X,0x%X,%d)\n", a1, a2, a3);
  sub_1580A3(a1, a2, a3);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140A4C);
  }
  JUMPOUT(0x13FCD2);
}
// 140D8A: control flows out of bounds to 140A4C
// 140D1F: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140D8F) --------------------------------------------------------
void __cdecl sub_140D8F(int a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_release_sample_handle(0x%X)\n", a1);
  sub_157680(a1);
  JUMPOUT(0x13FBA9);
}
// 140DF7: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140DFC) --------------------------------------------------------
void __cdecl sub_140DFC(int *a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_init_sample(0x%X)\n", a1);
  sub_157690(a1);
  JUMPOUT(0x13FBA9);
}
// 140E64: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140E69) --------------------------------------------------------
void __cdecl sub_140E69(_DWORD *a1, int a2, int a3)
{
  int v3; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sample_file(0x%X,0x%X,%d)\n", a1, a2, a3);
  sub_1581CE(a1, a2, a3);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13FCCA);
  }
  JUMPOUT(0x13FCD2);
}
// 140F6A: control flows out of bounds to 13FCCA
// 140EF2: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140F6F) --------------------------------------------------------
_DWORD *__cdecl sub_140F6F(_DWORD *a1, int a2, int a3)
{
  int v3; // edx
  _DWORD *result; // eax

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sample_address(0x%X,0x%X,%u)\n", a1, a2, a3);
  result = sub_157750(a1, a2, a3);
  --dword_1C0E40;
  return result;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00140FF1) --------------------------------------------------------
int *__cdecl sub_140FF1(int a1, int a2, int a3)
{
  int v3; // edx
  int *result; // eax

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sample_type(0x%X,%d,%u)\n", a1, a2, a3);
  result = sub_157780(a1, a2, a3);
  --dword_1C0E40;
  return result;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00141073) --------------------------------------------------------
void __cdecl sub_141073(_DWORD *a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_start_sample(0x%X)\n", a1);
  sub_1578A0(a1);
  JUMPOUT(0x13FBA9);
}
// 1410DB: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001410E0) --------------------------------------------------------
void __cdecl sub_1410E0(int a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_stop_sample(0x%X)\n", a1);
  sub_157920(a1);
  JUMPOUT(0x13FBA9);
}
// 141148: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014114D) --------------------------------------------------------
void __cdecl sub_14114D(int a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_resume_sample(0x%X)\n", a1);
  sub_157940(a1);
  JUMPOUT(0x13FBA9);
}
// 1411B5: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001411BA) --------------------------------------------------------
void __cdecl sub_1411BA(int a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_end_sample(0x%X)\n", a1);
  sub_157960(a1);
  JUMPOUT(0x13FBA9);
}
// 141222: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00141227) --------------------------------------------------------
void __cdecl sub_141227(int a1, int a2)
{
  int v2; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sample_playback_rate(0x%X,%d)\n", a1, a2);
  sub_1577C0(a1, a2);
  JUMPOUT(0x13FAAF);
}
// 141298: control flows out of bounds to 13FAAF
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014129D) --------------------------------------------------------
void __cdecl sub_14129D(int a1, int a2)
{
  int v2; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sample_volume(0x%X,%d)\n", a1, a2);
  sub_1577E0(a1, a2);
  JUMPOUT(0x13FAAF);
}
// 14130E: control flows out of bounds to 13FAAF
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00141313) --------------------------------------------------------
void __cdecl sub_141313(int a1, int a2)
{
  int v2; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sample_pan(0x%X,%d)\n", a1, a2);
  sub_157810(a1, a2);
  JUMPOUT(0x13FAAF);
}
// 141384: control flows out of bounds to 13FAAF
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00141389) --------------------------------------------------------
void __cdecl sub_141389(int a1, int a2)
{
  int v2; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sample_loop_count(0x%X,%d)\n", a1, a2);
  sub_157890(a1, a2);
  JUMPOUT(0x13FAAF);
}
// 1413FA: control flows out of bounds to 13FAAF
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001413FF) --------------------------------------------------------
void __cdecl sub_1413FF(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sample_status(0x%X)\n", a1);
  sub_157740(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140189);
  }
  JUMPOUT(0x13FCD2);
}
// 1414DF: control flows out of bounds to 140189
// 141474: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001414E4) --------------------------------------------------------
void __cdecl sub_1414E4(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sample_playback_rate(0x%X)\n", a1);
  sub_1577B0(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13FCCA);
  }
  JUMPOUT(0x13FCD2);
}
// 1415D0: control flows out of bounds to 13FCCA
// 141559: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001415D5) --------------------------------------------------------
void __cdecl sub_1415D5(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sample_volume(0x%X)\n", a1);
  sub_1577D0(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415C4);
  }
  JUMPOUT(0x13FCD2);
}
// 1416B5: control flows out of bounds to 1415C4
// 14164A: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001416BA) --------------------------------------------------------
void __cdecl sub_1416BA(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sample_pan(0x%X)\n", a1);
  sub_157800(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415C4);
  }
  JUMPOUT(0x13FCD2);
}
// 14179A: control flows out of bounds to 1415C4
// 14172F: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014179F) --------------------------------------------------------
void __cdecl sub_14179F(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sample_loop_count(0x%X)\n", a1);
  sub_157870(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415C4);
  }
  JUMPOUT(0x13FCD2);
}
// 14187F: control flows out of bounds to 1415C4
// 141814: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00141884) --------------------------------------------------------
void __cdecl sub_141884(int a1, int a2, void *a3)
{
  int v3; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_install_DIG_driver_image(0x%X,%u,0x%X)\n", a1, a2, a3);
  sub_157530(a1, a2, a3);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140A4C);
  }
  JUMPOUT(0x13FCD2);
}
// 141978: control flows out of bounds to 140A4C
// 14190D: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014197D) --------------------------------------------------------
void __cdecl sub_14197D(_DWORD *a1, int a2, int a3)
{
  int v3; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
  {
    v3 = dword_1C0E50;
    fprintf(dword_1C0E50, "AIL_minimum_sample_buffer_size(0x%X,%d,%d)\n", a1, a2, a3);
  }
  sub_157A60(v3, a1, a2, a3);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140F5D);
  }
  JUMPOUT(0x13FCD2);
}
// 141A71: control flows out of bounds to 140F5D
// 141A06: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00141A76) --------------------------------------------------------
void __cdecl sub_141A76(_DWORD *a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sample_buffer_ready(0x%X)\n", a1);
  sub_157B90(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415C4);
  }
  JUMPOUT(0x13FCD2);
}
// 141B56: control flows out of bounds to 1415C4
// 141AEB: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00141B5B) --------------------------------------------------------
void __cdecl sub_141B5B(int *a1, int a2, int a3, int a4)
{
  int v4; // edx

  v4 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v4 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_load_sample_buffer(0x%X,%u,0x%X,%u)\n", a1, a2, a3, a4);
  sub_157B00(a1, a2, a3, a4);
  JUMPOUT(0x13FB37);
}
// 141BE5: control flows out of bounds to 13FB37
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00141C60) --------------------------------------------------------
void __cdecl sub_141C60(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sample_position(0x%X)\n", a1);
  sub_157830(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140189);
  }
  JUMPOUT(0x13FCD2);
}
// 141D40: control flows out of bounds to 140189
// 141CD5: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00141D45) --------------------------------------------------------
void __cdecl sub_141D45(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_register_SOB_callback(0x%X,0x%X)\n", a1, a2);
  sub_1579B0(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140901);
  }
  JUMPOUT(0x13FCD2);
}
// 141E2D: control flows out of bounds to 140901
// 141DC3: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00141E32) --------------------------------------------------------
void __cdecl sub_141E32(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_register_EOB_callback(0x%X,0x%X)\n", a1, a2);
  sub_1579D0(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140901);
  }
  JUMPOUT(0x13FCD2);
}
// 141F1A: control flows out of bounds to 140901
// 141EB0: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00141F1F) --------------------------------------------------------
void __cdecl sub_141F1F(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_register_EOS_callback(0x%X,0x%X)\n", a1, a2);
  sub_1579F0(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140901);
  }
  JUMPOUT(0x13FCD2);
}
// 142007: control flows out of bounds to 140901
// 141F9D: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014200C) --------------------------------------------------------
void __cdecl sub_14200C(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_register_EOF_callback(0x%X,0x%X)\n", a1, a2);
  sub_1582A6(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140901);
  }
  JUMPOUT(0x13FCD2);
}
// 1420F4: control flows out of bounds to 140901
// 14208A: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001420F9) --------------------------------------------------------
int __cdecl sub_1420F9(int a1, int a2, int a3)
{
  int v3; // edx
  int result; // eax

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sample_user_data(0x%X,%u,%d)\n", a1, a2, a3);
  result = sub_157A10(a1, a2, a3);
  --dword_1C0E40;
  return result;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014217B) --------------------------------------------------------
void __cdecl sub_14217B(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sample_user_data(0x%X,%u)\n", a1, a2);
  sub_157A30(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13F937);
  }
  JUMPOUT(0x13FCD2);
}
// 142263: control flows out of bounds to 13F937
// 1421F9: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142268) --------------------------------------------------------
void __cdecl sub_142268(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_active_sample_count(0x%X)\n", a1);
  sub_1575E0(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415C4);
  }
  JUMPOUT(0x13FCD2);
}
// 142348: control flows out of bounds to 1415C4
// 1422DD: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014234D) --------------------------------------------------------
void sub_14234D()
{
  int v0; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v0 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v0 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_install_MDI_INI()\n");
  sub_15A400();
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140A4C);
  }
  JUMPOUT(0x13FCD2);
}
// 142420: control flows out of bounds to 140A4C
// 1423B5: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142425) --------------------------------------------------------
void __cdecl sub_142425(char *a1, void *a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_install_MDI_driver_file(%s,0x%X)\n", a1, a2);
  sub_15A340((int)a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140901);
  }
  JUMPOUT(0x13FCD2);
}
// 14250D: control flows out of bounds to 140901
// 1424A3: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014257F) --------------------------------------------------------
void __cdecl sub_14257F(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_allocate_sequence_handle(0x%X)\n", a1);
  sub_15A4F0(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13FA33);
  }
  JUMPOUT(0x13FCD2);
}
// 14265F: control flows out of bounds to 13FA33
// 1425F4: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001426D1) --------------------------------------------------------
void __cdecl sub_1426D1(int **a1, int a2, int a3)
{
  int v3; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_init_sequence(0x%X,0x%X,%d)\n", a1, a2, a3);
  sub_15A590(a1, a2, a3);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140F5D);
  }
  JUMPOUT(0x13FCD2);
}
// 1427C5: control flows out of bounds to 140F5D
// 14275A: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001427CA) --------------------------------------------------------
void __cdecl sub_1427CA(_DWORD *a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_start_sequence(0x%X)\n", a1);
  sub_15A940(a1);
  JUMPOUT(0x13FBA9);
}
// 142832: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142837) --------------------------------------------------------
void __cdecl sub_142837(_DWORD *a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_stop_sequence(0x%X)\n", a1);
  sub_15A980(a1);
  JUMPOUT(0x13FBA9);
}
// 14289F: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001428A4) --------------------------------------------------------
void __cdecl sub_1428A4(_DWORD *a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_resume_sequence(0x%X)\n", a1);
  sub_15AA50(a1);
  JUMPOUT(0x13FBA9);
}
// 14290C: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142911) --------------------------------------------------------
void __cdecl sub_142911(_DWORD *a1)
{
  int v1; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_end_sequence(0x%X)\n", a1);
  sub_15AAE0(a1);
  JUMPOUT(0x13FBA9);
}
// 142979: control flows out of bounds to 13FBA9
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014297E) --------------------------------------------------------
int __cdecl sub_14297E(_DWORD *a1, int a2, int a3)
{
  int v3; // edx
  int result; // eax

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sequence_tempo(0x%X,%d,%d)\n", a1, a2, a3);
  result = sub_15AB20(a1, a2, a3);
  --dword_1C0E40;
  return result;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142A00) --------------------------------------------------------
int __cdecl sub_142A00(_DWORD *a1, int a2, int a3)
{
  int v3; // edx
  int result; // eax

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sequence_volume(0x%X,%d,%d)\n", a1, a2, a3);
  result = sub_15AB90(a1, a2, a3);
  --dword_1C0E40;
  return result;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142A82) --------------------------------------------------------
void __cdecl sub_142A82(int a1, int a2)
{
  int v2; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sequence_loop_count(0x%X,%d)\n", a1, a2);
  sub_15AB10(a1, a2);
  JUMPOUT(0x13FAAF);
}
// 142AF3: control flows out of bounds to 13FAAF
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142AF8) --------------------------------------------------------
void __cdecl sub_142AF8(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sequence_status(0x%X)\n", a1);
  sub_15AC10(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140189);
  }
  JUMPOUT(0x13FCD2);
}
// 142BD8: control flows out of bounds to 140189
// 142B6D: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142BDD) --------------------------------------------------------
void __cdecl sub_142BDD(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sequence_tempo(0x%X)\n", a1);
  sub_15AC40(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415C4);
  }
  JUMPOUT(0x13FCD2);
}
// 142CBD: control flows out of bounds to 1415C4
// 142C52: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142CC2) --------------------------------------------------------
void __cdecl sub_142CC2(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sequence_volume(0x%X)\n", a1);
  sub_15AC50(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415C4);
  }
  JUMPOUT(0x13FCD2);
}
// 142DA2: control flows out of bounds to 1415C4
// 142D37: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142DA7) --------------------------------------------------------
void __cdecl sub_142DA7(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sequence_loop_count(0x%X)\n", a1);
  sub_15AC20(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415C4);
  }
  JUMPOUT(0x13FCD2);
}
// 142E87: control flows out of bounds to 1415C4
// 142E1C: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142E8C) --------------------------------------------------------
void __cdecl sub_142E8C(int a1, int a2, void *a3)
{
  int v3; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_install_MDI_driver_image(0x%X,%u,0x%X)\n", a1, a2, a3);
  sub_15A3C0(a1, a2, a3);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140A4C);
  }
  JUMPOUT(0x13FCD2);
}
// 142F80: control flows out of bounds to 140A4C
// 142F15: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00142FF2) --------------------------------------------------------
void __cdecl sub_142FF2(int *a1, int a2, int a3)
{
  int v3; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_timbre_status(0x%X,%d,%d)\n", a1, a2, a3);
  sub_15AC60(a1, a2, a3);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140F5D);
  }
  JUMPOUT(0x13FCD2);
}
// 1430E6: control flows out of bounds to 140F5D
// 14307B: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001430EB) --------------------------------------------------------
void __cdecl sub_1430EB(int *a1, int a2, int a3)
{
  int v3; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_install_timbre(0x%X,%d,%d)\n", a1, a2, a3);
  sub_15ACA0(a1, a2, a3);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140F5D);
  }
  JUMPOUT(0x13FCD2);
}
// 1431DF: control flows out of bounds to 140F5D
// 143174: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001431E4) --------------------------------------------------------
int __cdecl sub_1431E4(int *a1, int a2, int a3)
{
  int v3; // edx
  int result; // eax

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_protect_timbre(0x%X,%d,%d)\n", a1, a2, a3);
  result = sub_15ADA0(a1, a2, a3);
  --dword_1C0E40;
  return result;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00143266) --------------------------------------------------------
int __cdecl sub_143266(int *a1, int a2, int a3)
{
  int v3; // edx
  int result; // eax

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_unprotect_timbre(0x%X,%d,%d)\n", a1, a2, a3);
  result = sub_15ADE0(a1, a2, a3);
  --dword_1C0E40;
  return result;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001432E8) --------------------------------------------------------
void __cdecl sub_1432E8(int a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_active_sequence_count(0x%X)\n", a1);
  sub_15AE20(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415C4);
  }
  JUMPOUT(0x13FCD2);
}
// 1433C8: control flows out of bounds to 1415C4
// 14335D: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001433CD) --------------------------------------------------------
void __cdecl sub_1433CD(int a1, int a2, unsigned int a3)
{
  int v3; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_controller_value(0x%X,%d,%d)\n", a1, a2, a3);
  sub_15AE50(a1, a2, a3);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140F5D);
  }
  JUMPOUT(0x13FCD2);
}
// 1434C1: control flows out of bounds to 140F5D
// 143456: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001434C6) --------------------------------------------------------
void __cdecl sub_1434C6(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_channel_notes(0x%X,%d)\n", a1, a2);
  sub_15AE80(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13F937);
  }
  JUMPOUT(0x13FCD2);
}
// 1435AE: control flows out of bounds to 13F937
// 143544: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001435B3) --------------------------------------------------------
void __cdecl sub_1435B3(_DWORD *a1, _DWORD *a2, int *a3)
{
  int v3; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sequence_position(0x%X,0x%X,0x%X)\n", a1, a2, a3);
  sub_15AEC0(a1, a2, a3);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    fprintf(dword_1C0E50, "Result = %d:%d\n", *a3 + 1, *a2 + 1);
    JUMPOUT(0x141BE2);
  }
  JUMPOUT(0x13FB37);
}
// 1436B6: control flows out of bounds to 141BE2
// 143632: control flows out of bounds to 13FB37
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001436BB) --------------------------------------------------------
void __cdecl sub_1436BB(_DWORD *a1, int a2)
{
  int v2; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_branch_index(0x%X,%u)\n", a1, a2);
  sub_15AF30(a1, a2);
  JUMPOUT(0x13FAAF);
}
// 14372C: control flows out of bounds to 13FAAF
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00143731) --------------------------------------------------------
void __cdecl sub_143731(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_register_prefix_callback(0x%X,0x%X)\n", a1, a2);
  sub_15AFC0(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140901);
  }
  JUMPOUT(0x13FCD2);
}
// 143819: control flows out of bounds to 140901
// 1437AF: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014381E) --------------------------------------------------------
void __cdecl sub_14381E(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_register_trigger_callback(0x%X,0x%X)\n", a1, a2);
  sub_15AFE0(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140901);
  }
  JUMPOUT(0x13FCD2);
}
// 143906: control flows out of bounds to 140901
// 14389C: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (0014390B) --------------------------------------------------------
void __cdecl sub_14390B(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_register_sequence_callback(0x%X,0x%X)\n", a1, a2);
  sub_15B000(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140901);
  }
  JUMPOUT(0x13FCD2);
}
// 1439F3: control flows out of bounds to 140901
// 143989: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (001439F8) --------------------------------------------------------
void __cdecl sub_1439F8(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_register_event_callback(0x%X,0x%X)\n", a1, a2);
  sub_15B020(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140901);
  }
  JUMPOUT(0x13FCD2);
}
// 143AE0: control flows out of bounds to 140901
// 143A76: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00143AE5) --------------------------------------------------------
void __cdecl sub_143AE5(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_register_timbre_callback(0x%X,0x%X)\n", a1, a2);
  sub_15B040(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x140901);
  }
  JUMPOUT(0x13FCD2);
}
// 143BCD: control flows out of bounds to 140901
// 143B63: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00143BD2) --------------------------------------------------------
int __cdecl sub_143BD2(int a1, int a2, int a3)
{
  int v3; // edx
  int result; // eax

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_set_sequence_user_data(0x%X,%u,%d)\n", a1, a2, a3);
  result = sub_15B060(a1, a2, a3);
  --dword_1C0E40;
  return result;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00143C54) --------------------------------------------------------
void __cdecl sub_143C54(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_sequence_user_data(0x%X,%u)\n", a1, a2);
  sub_15B080(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13F937);
  }
  JUMPOUT(0x13FCD2);
}
// 143D3C: control flows out of bounds to 13F937
// 143CD2: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00143DB7) --------------------------------------------------------
void __cdecl sub_143DB7(_DWORD *a1)
{
  int v1; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v1 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v1 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_lock_channel(0x%X)\n", a1);
  sub_15B0B0(a1);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x1415C4);
  }
  JUMPOUT(0x13FCD2);
}
// 143E97: control flows out of bounds to 1415C4
// 143E2C: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00143E9C) --------------------------------------------------------
void __cdecl sub_143E9C(_DWORD *a1, int a2)
{
  int v2; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_release_channel(0x%X,%d)\n", a1, a2);
  sub_15B250(a1, a2);
  JUMPOUT(0x13FAAF);
}
// 143F0D: control flows out of bounds to 13FAAF
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00143F12) --------------------------------------------------------
_DWORD *__cdecl sub_143F12(_DWORD *a1, int a2, int a3)
{
  int v3; // edx
  _DWORD *result; // eax

  v3 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v3 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_map_sequence_channel(0x%X,%d,%d)\n", a1, a2, a3);
  result = sub_15B380(a1, a2, a3);
  --dword_1C0E40;
  return result;
}
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00143F94) --------------------------------------------------------
void __cdecl sub_143F94(int a1, int a2)
{
  int v2; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v2 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v2 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_true_sequence_channel(0x%X,%d)\n", a1, a2);
  sub_15B3C0(a1, a2);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13F937);
  }
  JUMPOUT(0x13FCD2);
}
// 14407C: control flows out of bounds to 13F937
// 144012: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00144081) --------------------------------------------------------
void __cdecl sub_144081(int a1, int a2, int a3, unsigned int a4, int a5)
{
  int v5; // edx

  v5 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v5 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_send_channel_voice_message(0x%X,0x%X,0x%X,0x%X,0x%X)\n", a1, a2, a3, a4, a5);
  sub_15B3E0(a1, a2, a3, a4, a5);
  JUMPOUT(0x13FB37);
}
// 144115: control flows out of bounds to 13FB37
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00144190) --------------------------------------------------------
void __cdecl sub_144190(int a1, int a2, int a3, int a4)
{
  int v4; // edx
  unsigned int i; // edx
  unsigned int j; // edx

  v4 = ++dword_1C0E40;
  if ( dword_1C0E54 && (v4 == 1 || dword_1C0E58) && !sub_155536() && sub_13F59A() )
    fprintf(dword_1C0E50, "AIL_create_wave_synthesizer(0x%X,0x%X,0x%X,%d)\n", a1, a2, a3, a4);
  sub_15BFAD(a1, a2, a3, a4);
  if ( dword_1C0E54 && (dword_1C0E40 == 1 || dword_1C0E58) && !sub_155536() )
  {
    for ( i = 0; i < 0xE; ++i )
      fprintf(dword_1C0E50, " ");
    for ( j = 1; j < dword_1C0E40; ++j )
      fprintf(dword_1C0E50, &unk_17B145);
    JUMPOUT(0x13FCC3);
  }
  JUMPOUT(0x13FCD2);
}
// 144293: control flows out of bounds to 13FCC3
// 144223: control flows out of bounds to 13FCD2
// 153DFA: using guessed type _DWORD fprintf(_DWORD, _DWORD, ...);
// 1C0E40: using guessed type int dword_1C0E40;
// 1C0E50: using guessed type int dword_1C0E50;
// 1C0E54: using guessed type int dword_1C0E54;
// 1C0E58: using guessed type int dword_1C0E58;


//----- (00144305) --------------------------------------------------------
bool sub_144305()
{
  bool result; // eax

  if ( dword_184A54 )
  {
    result = sub_1542DF((unsigned int)sub_13F486, (unsigned int)sub_144305);
    dword_184A54 = 0;
  }
  return result;
}
// 13F486: using guessed type int sub_13F486();
// 184A54: using guessed type int dword_184A54;


//----- (00144348) --------------------------------------------------------
_DWORD *__fastcall sub_144348(int a1, int a2)
{
  _DWORD *result; // eax
  int v3; // [esp+0h] [ebp-3Ch]
  int v4; // [esp+4h] [ebp-38h]
  int v5; // [esp+8h] [ebp-34h]
  int v6; // [esp+Ch] [ebp-30h]
  int v7; // [esp+10h] [ebp-2Ch]
  int v8; // [esp+14h] [ebp-28h]
  int v9; // [esp+18h] [ebp-24h]
  int v10; // [esp+1Ch] [ebp-20h]
  int v11; // [esp+20h] [ebp-1Ch]
  int k; // [esp+24h] [ebp-18h]
  int v13; // [esp+2Ch] [ebp-10h]
  int j; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  int v16; // [esp+38h] [ebp-4h]

  dword_1BB900 = (int)&unk_1C0E7C;
  sub_14475C();
  if ( dword_1BBA52 >> 16 >= 5 )
  {
    result = PoolAlloc_110B89(20000, a2);
    dword_1B3E74 = (int)result;
    word_1B43A8[0] = 19;
    word_1B43B8[0] = 0;
    word_1B43C8[0] = 0;
    for ( i = 0; i < 255; ++i )
    {
      byte_1B43D8[i] = 8;
      result = (_DWORD *)i;
    }
    v11 = 0;
    for ( j = 0; j < 256; ++j )
    {
      dword_1B49D8[j] = v11;
      for ( k = 0; k < 19; ++k )
      {
        v13 = dword_184B00[16 * j + dword_184A5C[k]];
        for ( i = 0; i < 8; ++i )
          *(&v3 + i) = 0;
        if ( (v13 & 0x10000000) != 0 )
          v3 = 1;
        if ( (v13 & 0x1000000) != 0 )
          v4 = 1;
        if ( ((unsigned int)&loc_100000 & v13) != 0 )
          v5 = 1;
        if ( ((unsigned int)sub_10000 & v13) != 0 )
          v6 = 1;
        if ( (v13 & 0x1000) != 0 )
          v7 = 1;
        if ( (v13 & 0x100) != 0 )
          v8 = 1;
        if ( (v13 & 0x10) != 0 )
          v9 = 1;
        if ( (v13 & 1) != 0 )
          v10 = 1;
        v16 = 0;
        for ( i = 0; i < 8; ++i )
        {
          if ( *(&v3 + i) )
          {
            if ( v16 > 0 )
            {
              *(_BYTE *)(v11 + dword_1B3E74) = v16 + 0x80;
              ++v11;
            }
            *(_BYTE *)(v11 + dword_1B3E74) = 1;
            ++v11;
            v16 = 0;
          }
          else
          {
            ++v16;
          }
        }
        *(_BYTE *)(v11 + dword_1B3E74) = 0x80;
        ++v11;
      }
      if ( (v11 & 3) != 0 )
        ++v11;
      if ( (v11 & 3) != 0 )
        ++v11;
      if ( (v11 & 3) != 0 )
        ++v11;
      result = (_DWORD *)j;
    }
  }
  else
  {
    result = PoolAlloc_110B89(20000, a2);
    dword_1B3E74 = (int)result;
    word_1B43A8[0] = 8;
    word_1B43B8[0] = 0;
    word_1B43C8[0] = 0;
    for ( i = 0; i < 255; ++i )
    {
      byte_1B43D8[i] = 4;
      result = (_DWORD *)i;
    }
    v11 = 0;
    for ( j = 0; j < 256; ++j )
    {
      dword_1B49D8[j] = v11;
      for ( k = 0; k < 8; ++k )
      {
        v13 = dword_184B00[16 * j + dword_184AA8[k]];
        for ( i = 0; i < 8; ++i )
          *(&v3 + i) = 0;
        if ( (v13 & 0x1000000) != 0 )
          v3 = 1;
        if ( ((unsigned int)sub_10000 & v13) != 0 )
          v4 = 1;
        if ( (v13 & 0x100) != 0 )
          v5 = 1;
        if ( (v13 & 1) != 0 )
          v6 = 1;
        v16 = 0;
        for ( i = 0; i < 4; ++i )
        {
          if ( *(&v3 + i) )
          {
            if ( v16 > 0 )
            {
              *(_BYTE *)(v11 + dword_1B3E74) = v16 + 0x80;
              ++v11;
            }
            *(_BYTE *)(v11 + dword_1B3E74) = 1;
            ++v11;
            v16 = 0;
          }
          else
          {
            ++v16;
          }
        }
        *(_BYTE *)(v11 + dword_1B3E74) = 0x80;
        ++v11;
      }
      if ( (v11 & 3) != 0 )
        ++v11;
      if ( (v11 & 3) != 0 )
        ++v11;
      if ( (v11 & 3) != 0 )
        ++v11;
      result = (_DWORD *)j;
    }
  }
  return result;
}
// 10000: using guessed type void __noreturn sub_10000();
// 184A5C: using guessed type int dword_184A5C[19];
// 184AA8: using guessed type int dword_184AA8[19];
// 184B00: using guessed type int dword_184B00[4096];
// 1B3E74: using guessed type int dword_1B3E74;
// 1B43A8: using guessed type int16_t word_1B43A8[8];
// 1B43B8: using guessed type int16_t word_1B43B8[];
// 1B43C8: using guessed type int16_t word_1B43C8[8];
// 1B49D8: using guessed type int dword_1B49D8[406];
// 1BB900: using guessed type int dword_1BB900;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (0014475C) --------------------------------------------------------
int16_t sub_14475C()
{
  int i; // [esp+0h] [ebp-10h]
  int k; // [esp+0h] [ebp-10h]
  int j; // [esp+4h] [ebp-Ch]
  int m; // [esp+4h] [ebp-Ch]
  char v5; // [esp+8h] [ebp-8h]
  char v6; // [esp+Ch] [ebp-4h]

  v5 = dword_184A58;
  v6 = dword_184A58;
  for ( i = 0; i < 16; ++i )
  {
    for ( j = 0; j < 3; ++j )
    {
      byte_1BB359[4 * i + j] = byte_188D40[3 * i + j];
      byte_1BB719[4 * i + j] = byte_188D40[3 * i + j];
    }
  }
  for ( k = 0; k < 24; ++k )
  {
    for ( m = 0; m < 24; ++m )
    {
      if ( (uint8_t)byte_188B00[24 * k + m] == 255 )
      {
        *(_BYTE *)(24 * k + m + dword_1BB900) = 0;
      }
      else if ( byte_188B00[24 * k + m] )
      {
        if ( byte_188B00[24 * k + m] == 2 )
          *(_BYTE *)(24 * k + m + dword_1BB900) = v6;
        else
          *(_BYTE *)(24 * k + m + dword_1BB900) = v5;
      }
    }
  }
  return sub_123E6C((int)&unk_184AF4, 1);
}
// 184A58: using guessed type int dword_184A58;
// 1BB900: using guessed type int dword_1BB900;


//----- (001449CC) --------------------------------------------------------
int64_t __fastcall sub_1449CC(int64_t a1, int a2, int a3)
{
  int64_t v3; // rdi
  int v4; // eax
  int v5; // edx
  _BOOL1 v6; // sf

  v3 = a1;
  v4 = 0;
  do
  {
    v5 = v3;
    LOBYTE(v4) = *(_BYTE *)HIDWORD(v3);
    ++HIDWORD(v3);
    v6 = v4 - 128 < 0;
    if ( v4 != 128 )
    {
      do
      {
        while ( !v6 )
        {
          LOWORD(v4) = v4 & 0x7F;
          LODWORD(v3) = v4 + v3;
          LOBYTE(v4) = *(_BYTE *)HIDWORD(v3);
          ++HIDWORD(v3);
          v6 = (char)(v4 + 0x80) < 0;
          if ( (_BYTE)v4 == 0x80 )
            goto LABEL_7;
        }
        *(_BYTE *)v3 = *(_BYTE *)(v4 + a2 - 1);
        LODWORD(v3) = v3 + 1;
        LOBYTE(v4) = *(_BYTE *)HIDWORD(v3);
        ++HIDWORD(v3);
        v6 = (char)(v4 + 0x80) < 0;
      }
      while ( (_BYTE)v4 != 0x80 );
    }
LABEL_7:
    LODWORD(v3) = *(int *)((char *)&dword_184532 + 2) + v5;
    --a3;
  }
  while ( a3 );
  return a1;
}
// 1449CC: could not find valid save-restore pair for edi
// 1449CC: could not find valid save-restore pair for esi
// 184532: using guessed type int dword_184532;


//----- (00144A06) --------------------------------------------------------
int64_t __fastcall sub_144A06(int64_t a1, int a2, int a3)
{
  int64_t v3; // rdi
  int v4; // eax
  int v5; // edx
  _BOOL1 v6; // sf

  v3 = a1;
  v4 = 0;
  do
  {
    v5 = v3;
    LOBYTE(v4) = *(_BYTE *)HIDWORD(v3);
    ++HIDWORD(v3);
    v6 = v4 - 128 < 0;
    if ( v4 != 128 )
    {
      do
      {
        while ( !v6 )
        {
          LOWORD(v4) = v4 & 0x7F;
          LODWORD(v3) = v4 + v3;
          LOBYTE(v4) = *(_BYTE *)HIDWORD(v3);
          ++HIDWORD(v3);
          v6 = (char)(v4 + 0x80) < 0;
          if ( (_BYTE)v4 == 0x80 )
            goto LABEL_9;
        }
        if ( (_BYTE)v4 )
          *(_BYTE *)v3 = *(_BYTE *)(v4 + a2 - 1);
        LODWORD(v3) = v3 + 1;
        LOBYTE(v4) = *(_BYTE *)HIDWORD(v3);
        ++HIDWORD(v3);
        v6 = (char)(v4 + 0x80) < 0;
      }
      while ( (_BYTE)v4 != 0x80 );
    }
LABEL_9:
    LODWORD(v3) = *(int *)((char *)&dword_184532 + 2) + v5;
    --a3;
  }
  while ( a3 );
  return a1;
}
// 144A06: could not find valid save-restore pair for edi
// 144A06: could not find valid save-restore pair for esi
// 184532: using guessed type int dword_184532;


//----- (00144A46) --------------------------------------------------------
void sub_144A46()
{
  _disable();
}


//----- (00144A48) --------------------------------------------------------
void sub_144A48()
{
  _enable();
}


//----- (00144A91) --------------------------------------------------------
void sub_144A91()
{
  int64_t v0; // rt2
  int v1; // ebx
  int v2; // eax
  _DWORD *v3; // edi
  char *v4; // esi
  _DWORD *v5; // edi
  _DWORD *v6; // esi
  char *v7; // esi
  int v8; // edx
  int v9; // eax
  char *v10; // esi

  LOWORD(dword_1BBA3E) = 0;
  dword_1BB8AC = 0;
  byte_188D94 = 0;
  dword_188D8C = 0;
  dword_188D90 = 0;
  LOWORD(dword_1BBA42) = dword_1BBA38;
  HIWORD(dword_1BBA3E) = HIWORD(dword_1BBA34);
  byte_188D95 = 26;
  byte_188D96 = 24;
  if ( (uint16_t)(HIWORD(dword_1BBA34) + 24) >= 0x1E0u )
    byte_188D96 = -32 - BYTE2(dword_1BBA3E);
  dword_188D7A = (uint16_t)(5 * HIWORD(dword_1BBA64));
  dword_188D7E = (uint16_t)dword_1BBA42 + 640 * HIWORD(dword_1BBA3E);
  v0 = (unsigned int)dword_188D7E % (int64_t)(int)sub_10000;
  word_188D82 = (unsigned int)dword_188D7E / (int64_t)(int)sub_10000;
  word_188D82 += dword_188D7A;
  word_188D78 = v0 & 1;
  dword_188D84 = v0 - (v0 & 1);
  v1 = v0 - (v0 & 1) + 15386;
  if ( v1 >= (int)sub_10000 )
  {
    byte_188D94 = 1;
    dword_188D8C = 24 - (unsigned int)(v1 - (_DWORD)sub_10000) / 640LL;
    LOWORD(dword_1BBA3E) = 24 - (unsigned int)(v1 - (_DWORD)sub_10000) / 640LL;
    v1 = 640;
    v2 = dword_188D84 + 640 * dword_188D8C;
    dword_188D90 = 0;
    if ( v2 < 0xFFFF )
    {
      v1 = (int)sub_10000 - v2;
      dword_188D90 = (int)sub_10000 - v2;
      if ( (void (__noreturn *)())((char *)sub_10000 - v2) == (void (__noreturn *)())26 )
      {
        dword_188D90 = 0;
        ++dword_188D8C;
      }
    }
  }
  dword_1BB8AC = v1;
  sub_138C58();
  v3 = (_DWORD *)dword_1BB8B0;
  v4 = (char *)&loc_9FFFD + dword_188D84 + 3;
  dword_188D97 = 0;
  dword_188D9B = 0;
  if ( byte_188D95 == 26 )
  {
    while ( dword_188D9B < (uint8_t)byte_188D96 )
    {
      if ( byte_188D94 == 1 && (dword_188D97 = 0, dword_188D9B == dword_188D8C) )
      {
        do
        {
          if ( dword_188D97 == dword_188D90 )
          {
            ++word_188D82;
            sub_138C58();
            v7 = (char *)&loc_9FFFD + 3;
            HIWORD(v8) = 0;
            v9 = (uint16_t)word_188D82 - dword_188D7A;
            switch ( v9 )
            {
              case 1:
                LOWORD(v8) = dword_1BBA42;
                if ( dword_188D97 + v8 + 1 >= 257 )
                {
                  LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                  v10 = &v7[dword_188D97 - 257];
                }
                else
                {
                  v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 383) + 3;
                }
                break;
              case 2:
                LOWORD(v8) = dword_1BBA42;
                if ( dword_188D97 + v8 + 1 >= 513 )
                {
                  LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                  v10 = &v7[dword_188D97 - 513];
                }
                else
                {
                  v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 127) + 3;
                }
                break;
              case 3:
                LOWORD(v8) = dword_1BBA42;
                if ( dword_188D97 + v8 + 1 >= 129 )
                {
                  LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                  v10 = &v7[dword_188D97 - 129];
                }
                else
                {
                  v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 511) + 3;
                }
                break;
              default:
                LOWORD(v8) = dword_1BBA42;
                if ( dword_188D97 + v8 + 1 >= 385 )
                {
                  LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                  v10 = &v7[dword_188D97 - 385];
                }
                else
                {
                  v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 255) + 3;
                }
                break;
            }
            v4 = v10 + 1;
            if ( word_188D78 == 1 )
              --v4;
          }
          *(_BYTE *)v3 = *v4++;
          v3 = (_DWORD *)((char *)v3 + 1);
          ++dword_188D97;
        }
        while ( dword_188D97 <= 25 );
        if ( dword_188D97 == dword_188D90 )
        {
          ++word_188D82;
          sub_138C58();
          v4 = (char *)&loc_9FFFD + 3;
        }
        ++dword_188D9B;
        v4 += 614;
      }
      else
      {
        *v3 = *(_DWORD *)v4;
        v6 = v4 + 4;
        v5 = v3 + 1;
        *v5 = *v6++;
        *++v5 = *v6++;
        *++v5 = *v6++;
        *++v5 = *v6++;
        *++v5 = *v6++;
        *(_WORD *)++v5 = *(_WORD *)v6;
        v3 = (_DWORD *)((char *)v5 + 2);
        v4 = (char *)(v6 + 154);
        ++dword_188D9B;
      }
    }
  }
}
// 144A91: could not find valid save-restore pair for edi
// 144A91: could not find valid save-restore pair for esi
// 10000: using guessed type void __noreturn sub_10000();
// 188D78: using guessed type int16_t word_188D78;
// 188D7A: using guessed type int dword_188D7A;
// 188D7E: using guessed type int dword_188D7E;
// 188D82: using guessed type int16_t word_188D82;
// 188D84: using guessed type int dword_188D84;
// 188D8C: using guessed type int dword_188D8C;
// 188D90: using guessed type int dword_188D90;
// 188D94: using guessed type char byte_188D94;
// 188D95: using guessed type char byte_188D95;
// 188D96: using guessed type char byte_188D96;
// 188D97: using guessed type int dword_188D97;
// 188D9B: using guessed type int dword_188D9B;
// 1BB8AC: using guessed type int dword_1BB8AC;
// 1BB8B0: using guessed type int dword_1BB8B0;
// 1BBA34: using guessed type int dword_1BBA34;
// 1BBA38: using guessed type int dword_1BBA38;
// 1BBA3E: using guessed type int dword_1BBA3E;
// 1BBA42: using guessed type int dword_1BBA42;
// 1BBA64: using guessed type int dword_1BBA64;


//----- (00144EAC) --------------------------------------------------------
void sub_144EAC()
{
  int64_t v0; // rt2
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  char *v4; // edi
  _DWORD *v5; // edi
  _DWORD *v6; // esi
  char *v7; // edi
  int v8; // edx
  int v9; // eax
  char *v10; // edi

  LOWORD(dword_1BBA3E) = 0;
  dword_1BB8AC = 0;
  byte_188D94 = 0;
  dword_188D8C = 0;
  dword_188D90 = 0;
  byte_188D95 = 26;
  byte_188D96 = 24;
  if ( (uint16_t)(HIWORD(dword_1BBA3E) + 24) >= 0x1E0u )
    byte_188D96 = -32 - BYTE2(dword_1BBA3E);
  dword_188D7A = (uint16_t)(5 * HIWORD(dword_1BBA64));
  dword_188D7E = (uint16_t)dword_1BBA42 + WORD2(qword_184530) * HIWORD(dword_1BBA3E);
  v0 = (unsigned int)dword_188D7E % (int64_t)(int)sub_10000;
  word_188D82 = (unsigned int)dword_188D7E / (int64_t)(int)sub_10000;
  word_188D82 += dword_188D7A;
  word_188D78 = v0 & 1;
  dword_188D84 = v0 - (v0 & 1);
  v1 = v0 - (v0 & 1) + 15386;
  if ( v1 >= (int)sub_10000 )
  {
    byte_188D94 = 1;
    dword_188D8C = 24 - (unsigned int)(v1 - (_DWORD)sub_10000) / 640LL;
    LOWORD(dword_1BBA3E) = 24 - (unsigned int)(v1 - (_DWORD)sub_10000) / 640LL;
    v2 = dword_188D84 + 640 * dword_188D8C;
    dword_188D90 = 0;
    if ( v2 < 0xFFFF )
    {
      dword_188D90 = (int)sub_10000 - v2;
      if ( (void (__noreturn *)())((char *)sub_10000 - v2) == (void (__noreturn *)())26 )
      {
        dword_188D90 = 0;
        ++dword_188D8C;
      }
    }
  }
  sub_138C34();
  v3 = (char *)dword_1BB8B0;
  v4 = (char *)&loc_9FFFD + dword_188D84 + 3;
  dword_188D97 = 0;
  dword_188D9B = 0;
  if ( byte_188D95 == 26 )
  {
    while ( dword_188D9B < (uint8_t)byte_188D96 )
    {
      if ( byte_188D94 == 1 && (dword_188D97 = 0, dword_188D9B == dword_188D8C) )
      {
        do
        {
          if ( dword_188D97 == dword_188D90 )
          {
            ++word_188D82;
            sub_138C34();
            v7 = (char *)&loc_9FFFD + 3;
            HIWORD(v8) = 0;
            v9 = (uint16_t)word_188D82 - dword_188D7A;
            switch ( v9 )
            {
              case 1:
                LOWORD(v8) = dword_1BBA42;
                if ( dword_188D97 + v8 + 1 >= 257 )
                {
                  LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                  v10 = &v7[dword_188D97 - 257];
                }
                else
                {
                  v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 383) + 3;
                }
                break;
              case 2:
                LOWORD(v8) = dword_1BBA42;
                if ( dword_188D97 + v8 + 1 >= 513 )
                {
                  LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                  v10 = &v7[dword_188D97 - 513];
                }
                else
                {
                  v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 127) + 3;
                }
                break;
              case 3:
                LOWORD(v8) = dword_1BBA42;
                if ( dword_188D97 + v8 + 1 >= 129 )
                {
                  LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                  v10 = &v7[dword_188D97 - 129];
                }
                else
                {
                  v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 511) + 3;
                }
                break;
              default:
                LOWORD(v8) = dword_1BBA42;
                if ( dword_188D97 + v8 + 1 >= 385 )
                {
                  LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                  v10 = &v7[dword_188D97 - 385];
                }
                else
                {
                  v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 255) + 3;
                }
                break;
            }
            v4 = v10 + 1;
            if ( word_188D78 == 1 )
              --v4;
          }
          *v4++ = *v3++;
          ++dword_188D97;
        }
        while ( dword_188D97 <= 25 );
        if ( dword_188D97 == dword_188D90 )
        {
          ++word_188D82;
          sub_138C34();
          v4 = (char *)&loc_9FFFD + 3;
        }
        ++dword_188D9B;
        v4 += 614;
      }
      else
      {
        *(_DWORD *)v4 = *(_DWORD *)v3;
        v6 = v3 + 4;
        v5 = v4 + 4;
        *v5 = *v6++;
        *++v5 = *v6++;
        *++v5 = *v6++;
        *++v5 = *v6++;
        *++v5 = *v6++;
        *(_WORD *)++v5 = *(_WORD *)v6;
        v3 = (char *)v6 + 2;
        v4 = (char *)(v5 + 154);
        ++dword_188D9B;
      }
    }
  }
}
// 144EAC: could not find valid save-restore pair for edi
// 144EAC: could not find valid save-restore pair for esi
// 10000: using guessed type void __noreturn sub_10000();
// 184530: using guessed type int64_t qword_184530;
// 188D78: using guessed type int16_t word_188D78;
// 188D7A: using guessed type int dword_188D7A;
// 188D7E: using guessed type int dword_188D7E;
// 188D82: using guessed type int16_t word_188D82;
// 188D84: using guessed type int dword_188D84;
// 188D8C: using guessed type int dword_188D8C;
// 188D90: using guessed type int dword_188D90;
// 188D94: using guessed type char byte_188D94;
// 188D95: using guessed type char byte_188D95;
// 188D96: using guessed type char byte_188D96;
// 188D97: using guessed type int dword_188D97;
// 188D9B: using guessed type int dword_188D9B;
// 1BB8AC: using guessed type int dword_1BB8AC;
// 1BB8B0: using guessed type int dword_1BB8B0;
// 1BBA3E: using guessed type int dword_1BBA3E;
// 1BBA42: using guessed type int dword_1BBA42;
// 1BBA64: using guessed type int dword_1BBA64;


//----- (0014529D) --------------------------------------------------------
void sub_14529D()
{
  int64_t v0; // rt2
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  _BYTE *v4; // edi
  char v5; // al
  char v6; // al
  char *v7; // edi
  int v8; // edx
  int v9; // eax
  char *v10; // edi

  byte_188D94 = 0;
  dword_188D8C = 0;
  dword_188D90 = 0;
  byte_188D95 = 24;
  if ( (uint16_t)(dword_1BBA42 + 24) >= 0x280u )
    byte_188D95 = 0x80 - dword_1BBA42;
  byte_188D96 = 24;
  if ( (uint16_t)(HIWORD(dword_1BBA3E) + 24) >= 0x1E0u )
    byte_188D96 = -32 - BYTE2(dword_1BBA3E);
  dword_188D7A = (uint16_t)(5 * HIWORD(dword_1BBA64));
  dword_188D7E = (uint16_t)dword_1BBA42 + 640 * HIWORD(dword_1BBA3E);
  v0 = (unsigned int)dword_188D7E % (int64_t)(int)sub_10000;
  word_188D82 = (unsigned int)dword_188D7E / (int64_t)(int)sub_10000;
  word_188D82 += dword_188D7A;
  word_188D78 = v0 & 1;
  dword_188D84 = v0 - (v0 & 1);
  v1 = v0 - (v0 & 1) + 15386;
  if ( v1 >= (int)sub_10000 )
  {
    byte_188D94 = 1;
    dword_188D8C = 24 - (unsigned int)(v1 - (_DWORD)sub_10000) / 640LL;
    LOWORD(dword_1BBA3E) = 24 - (unsigned int)(v1 - (_DWORD)sub_10000) / 640LL;
    v2 = dword_188D84 + 640 * dword_188D8C;
    dword_188D90 = 0;
    if ( v2 < 0xFFFF )
    {
      dword_188D90 = (int)sub_10000 - v2;
      if ( (void (__noreturn *)())((char *)sub_10000 - v2) == (void (__noreturn *)())26 )
      {
        dword_188D90 = 0;
        ++dword_188D8C;
      }
    }
  }
  sub_138C34();
  v3 = (char *)dword_1BBA18;
  v4 = (char *)&loc_9FFFD + dword_188D84 + 3;
  dword_188D97 = 0;
  dword_188D9B = 0;
  while ( 1 )
  {
    dword_188D97 = 0;
    if ( dword_188D9B >= (uint8_t)byte_188D96 )
      break;
    if ( byte_188D94 == 1 && dword_188D9B == dword_188D8C )
    {
      while ( 1 )
      {
        if ( dword_188D97 == dword_188D90 )
        {
          ++word_188D82;
          sub_138C34();
          v7 = (char *)&loc_9FFFD + 3;
          HIWORD(v8) = 0;
          v9 = (uint16_t)word_188D82 - dword_188D7A;
          switch ( v9 )
          {
            case 1:
              LOWORD(v8) = dword_1BBA42;
              if ( dword_188D97 + v8 + 1 >= 257 )
              {
                LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                v10 = &v7[dword_188D97 - 257];
              }
              else
              {
                v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 383) + 3;
              }
              break;
            case 2:
              LOWORD(v8) = dword_1BBA42;
              if ( dword_188D97 + v8 + 1 >= 513 )
              {
                LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                v10 = &v7[dword_188D97 - 513];
              }
              else
              {
                v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 127) + 3;
              }
              break;
            case 3:
              LOWORD(v8) = dword_1BBA42;
              if ( dword_188D97 + v8 + 1 >= 129 )
              {
                LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                v10 = &v7[dword_188D97 - 129];
              }
              else
              {
                v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 511) + 3;
              }
              break;
            default:
              LOWORD(v8) = dword_1BBA42;
              if ( dword_188D97 + v8 + 1 >= 385 )
              {
                LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
                v10 = &v7[dword_188D97 - 385];
              }
              else
              {
                v10 = (char *)&loc_9FFFD + (uint16_t)(dword_1BBA42 + 255) + 3;
              }
              break;
          }
          v4 = v10 + 1;
          if ( word_188D78 == 1 )
            --v4;
        }
        if ( dword_188D97 >= (uint8_t)byte_188D95 )
          break;
        v6 = *v3++;
        if ( v6 )
          *v4 = v6;
        ++v4;
        if ( ++dword_188D97 > (uint8_t)(byte_188D95 - 1) )
        {
          if ( dword_188D97 == dword_188D90 )
          {
            ++word_188D82;
            sub_138C34();
            v4 = (char *)&loc_9FFFD + 3;
          }
          break;
        }
      }
      ++dword_188D9B;
      v4 = &v4[-(uint8_t)byte_188D95 + 640];
      if ( byte_188D95 != 24 )
        v3 += 24 - (uint8_t)byte_188D95;
    }
    else
    {
      while ( dword_188D97 < (uint8_t)byte_188D95 )
      {
        ++dword_188D97;
        v5 = *v3++;
        if ( v5 )
          *v4 = v5;
        ++v4;
      }
      v4 = &v4[-(uint8_t)byte_188D95 + 640];
      ++dword_188D9B;
      if ( byte_188D95 != 24 )
        v3 += 24 - (uint8_t)byte_188D95;
    }
  }
}
// 14529D: could not find valid save-restore pair for edi
// 14529D: could not find valid save-restore pair for esi
// 10000: using guessed type void __noreturn sub_10000();
// 188D78: using guessed type int16_t word_188D78;
// 188D7A: using guessed type int dword_188D7A;
// 188D7E: using guessed type int dword_188D7E;
// 188D82: using guessed type int16_t word_188D82;
// 188D84: using guessed type int dword_188D84;
// 188D8C: using guessed type int dword_188D8C;
// 188D90: using guessed type int dword_188D90;
// 188D94: using guessed type char byte_188D94;
// 188D95: using guessed type char byte_188D95;
// 188D96: using guessed type char byte_188D96;
// 188D97: using guessed type int dword_188D97;
// 188D9B: using guessed type int dword_188D9B;
// 1BBA18: using guessed type int dword_1BBA18;
// 1BBA3E: using guessed type int dword_1BBA3E;
// 1BBA42: using guessed type int dword_1BBA42;
// 1BBA64: using guessed type int dword_1BBA64;


//----- (00145719) --------------------------------------------------------
void sub_145719()
{
  _DWORD *v0; // edi
  _DWORD *v1; // esi
  _DWORD *v2; // edi
  _DWORD *v3; // esi

  LOWORD(dword_1BBA3E) = 0;
  dword_1BB8AC = 0;
  LOWORD(dword_1BBA42) = dword_1BBA38;
  HIWORD(dword_1BBA3E) = HIWORD(dword_1BBA34);
  byte_188D95 = 26;
  byte_188D96 = 24;
  if ( (uint16_t)(HIWORD(dword_1BBA34) + 24) >= 0x1E0u )
    byte_188D96 = -32 - BYTE2(dword_1BBA3E);
  dword_188D7E = (uint16_t)dword_1BBA42 + 640 * HIWORD(dword_1BBA3E);
  word_188D78 = dword_188D7E & 1;
  dword_188D84 = dword_188D7E - (dword_188D7E & 1);
  v0 = (_DWORD *)dword_1BB8B0;
  v1 = (_DWORD *)(dword_188D84 + dword_1BB90C);
  dword_188D97 = 0;
  for ( dword_188D9B = 0; dword_188D9B < (uint8_t)byte_188D96; ++dword_188D9B )
  {
    *v0 = *v1;
    v3 = v1 + 1;
    v2 = v0 + 1;
    *v2 = *v3++;
    *++v2 = *v3++;
    *++v2 = *v3++;
    *++v2 = *v3++;
    *++v2 = *v3++;
    *(_WORD *)++v2 = *(_WORD *)v3;
    v0 = (_DWORD *)((char *)v2 + 2);
    v1 = v3 + 154;
  }
}
// 145719: could not find valid save-restore pair for edi
// 145719: could not find valid save-restore pair for esi
// 188D78: using guessed type int16_t word_188D78;
// 188D7E: using guessed type int dword_188D7E;
// 188D84: using guessed type int dword_188D84;
// 188D95: using guessed type char byte_188D95;
// 188D96: using guessed type char byte_188D96;
// 188D97: using guessed type int dword_188D97;
// 188D9B: using guessed type int dword_188D9B;
// 1BB8AC: using guessed type int dword_1BB8AC;
// 1BB8B0: using guessed type int dword_1BB8B0;
// 1BB90C: using guessed type int dword_1BB90C;
// 1BBA34: using guessed type int dword_1BBA34;
// 1BBA38: using guessed type int dword_1BBA38;
// 1BBA3E: using guessed type int dword_1BBA3E;
// 1BBA42: using guessed type int dword_1BBA42;


//----- (00145850) --------------------------------------------------------
void sub_145850()
{
  _DWORD *v0; // esi
  _DWORD *v1; // edi
  _DWORD *v2; // edi
  _DWORD *v3; // esi

  LOWORD(dword_1BBA3E) = 0;
  dword_1BB8AC = 0;
  byte_188D95 = 26;
  byte_188D96 = 24;
  if ( (uint16_t)(HIWORD(dword_1BBA3E) + 24) >= 0x1E0u )
    byte_188D96 = -32 - BYTE2(dword_1BBA3E);
  dword_188D7E = (uint16_t)dword_1BBA42 + 640 * HIWORD(dword_1BBA3E);
  word_188D78 = dword_188D7E & 1;
  dword_188D84 = dword_188D7E - (dword_188D7E & 1);
  v0 = (_DWORD *)dword_1BB8B0;
  v1 = (_DWORD *)(dword_188D84 + dword_1BB90C);
  dword_188D97 = 0;
  for ( dword_188D9B = 0; dword_188D9B < (uint8_t)byte_188D96; ++dword_188D9B )
  {
    *v1 = *v0;
    v3 = v0 + 1;
    v2 = v1 + 1;
    *v2 = *v3++;
    *++v2 = *v3++;
    *++v2 = *v3++;
    *++v2 = *v3++;
    *++v2 = *v3++;
    *(_WORD *)++v2 = *(_WORD *)v3;
    v0 = (_DWORD *)((char *)v3 + 2);
    v1 = v2 + 154;
  }
}
// 145850: could not find valid save-restore pair for edi
// 145850: could not find valid save-restore pair for esi
// 188D78: using guessed type int16_t word_188D78;
// 188D7E: using guessed type int dword_188D7E;
// 188D84: using guessed type int dword_188D84;
// 188D95: using guessed type char byte_188D95;
// 188D96: using guessed type char byte_188D96;
// 188D97: using guessed type int dword_188D97;
// 188D9B: using guessed type int dword_188D9B;
// 1BB8AC: using guessed type int dword_1BB8AC;
// 1BB8B0: using guessed type int dword_1BB8B0;
// 1BB90C: using guessed type int dword_1BB90C;
// 1BBA3E: using guessed type int dword_1BBA3E;
// 1BBA42: using guessed type int dword_1BBA42;


//----- (0014595F) --------------------------------------------------------
void sub_14595F()
{
  char *v0; // esi
  _BYTE *v1; // edi
  char v2; // al

  LOWORD(dword_1BBA3E) = 0;
  dword_1BB8AC = 0;
  byte_188D95 = 24;
  if ( (uint16_t)(dword_1BBA42 + 24) >= 0x280u )
    byte_188D95 = 0x80 - dword_1BBA42;
  byte_188D96 = 24;
  if ( (uint16_t)(HIWORD(dword_1BBA3E) + 24) >= 0x1E0u )
    byte_188D96 = -32 - BYTE2(dword_1BBA3E);
  dword_188D7E = (uint16_t)dword_1BBA42 + 640 * HIWORD(dword_1BBA3E);
  word_188D78 = dword_188D7E & 1;
  dword_188D84 = dword_188D7E - (dword_188D7E & 1);
  v0 = (char *)dword_1BBA18;
  v1 = (_BYTE *)(dword_188D84 + dword_1BB90C);
  dword_188D97 = 0;
  dword_188D9B = 0;
  while ( 1 )
  {
    dword_188D97 = 0;
    if ( dword_188D9B >= (uint8_t)byte_188D96 )
      break;
    while ( dword_188D97 < (uint8_t)byte_188D95 )
    {
      ++dword_188D97;
      v2 = *v0++;
      if ( v2 )
        *v1 = v2;
      ++v1;
    }
    v1 = &v1[-(uint8_t)byte_188D95 + 640];
    ++dword_188D9B;
    if ( byte_188D95 != 24 )
      v0 += 24 - (uint8_t)byte_188D95;
  }
}
// 14595F: could not find valid save-restore pair for edi
// 14595F: could not find valid save-restore pair for esi
// 188D78: using guessed type int16_t word_188D78;
// 188D7E: using guessed type int dword_188D7E;
// 188D84: using guessed type int dword_188D84;
// 188D95: using guessed type char byte_188D95;
// 188D96: using guessed type char byte_188D96;
// 188D97: using guessed type int dword_188D97;
// 188D9B: using guessed type int dword_188D9B;
// 1BB8AC: using guessed type int dword_1BB8AC;
// 1BB90C: using guessed type int dword_1BB90C;
// 1BBA18: using guessed type int dword_1BBA18;
// 1BBA3E: using guessed type int dword_1BBA3E;
// 1BBA42: using guessed type int dword_1BBA42;


//----- (00145ADA) --------------------------------------------------------
void sub_145ADA()
{
  ;
}


//----- (00145AF9) --------------------------------------------------------
void sub_145AF9()
{
  ;
}


//----- (00145B18) --------------------------------------------------------
void sub_145B18()
{
  ;
}


//----- (00145B37) --------------------------------------------------------
void sub_145B37()
{
  ;
}


//----- (00145B56) --------------------------------------------------------
void sub_145B56()
{
  ;
}


//----- (00145B75) --------------------------------------------------------
void sub_145B75()
{
  ;
}


//----- (00145B94) --------------------------------------------------------
void sub_145B94()
{
  ;
}


//----- (00145BB3) --------------------------------------------------------
void sub_145BB3()
{
  ;
}


//----- (00145BD2) --------------------------------------------------------
void sub_145BD2()
{
  ;
}


//----- (00145BF1) --------------------------------------------------------
void sub_145BF1()
{
  ;
}


//----- (00145C10) --------------------------------------------------------
void sub_145C10()
{
  ;
}


//----- (00145C2F) --------------------------------------------------------
void sub_145C2F()
{
  ;
}


//----- (00145C4E) --------------------------------------------------------
void sub_145C4E()
{
  ;
}


//----- (00145C6D) --------------------------------------------------------
void sub_145C6D()
{
  ;
}


//----- (00145C8C) --------------------------------------------------------
void sub_145C8C()
{
  ;
}


//----- (00145CAB) --------------------------------------------------------
void sub_145CAB()
{
  ;
}


//----- (00145CCA) --------------------------------------------------------
void sub_145CCA()
{
  ;
}


//----- (00145CF1) --------------------------------------------------------
void sub_145CF1()
{
  ;
}


//----- (00145D18) --------------------------------------------------------
void sub_145D18()
{
  ;
}


//----- (00145D3F) --------------------------------------------------------
void sub_145D3F()
{
  ;
}


//----- (00145D66) --------------------------------------------------------
void sub_145D66()
{
  ;
}


//----- (00145D85) --------------------------------------------------------
void sub_145D85()
{
  ;
}


//----- (00145DA4) --------------------------------------------------------
void sub_145DA4()
{
  ;
}


//----- (00145DC3) --------------------------------------------------------
void sub_145DC3()
{
  ;
}


//----- (00145DE2) --------------------------------------------------------
void sub_145DE2()
{
  ;
}


//----- (00145E01) --------------------------------------------------------
void sub_145E01()
{
  ;
}


//----- (00145E20) --------------------------------------------------------
void sub_145E20()
{
  ;
}


//----- (00145E3F) --------------------------------------------------------
void sub_145E3F()
{
  ;
}


//----- (00145E5E) --------------------------------------------------------
void sub_145E5E()
{
  ;
}


//----- (00145E7D) --------------------------------------------------------
void sub_145E7D()
{
  ;
}


//----- (00145E9C) --------------------------------------------------------
void sub_145E9C()
{
  ;
}


//----- (00145EBB) --------------------------------------------------------
void sub_145EBB()
{
  ;
}


//----- (00145EDA) --------------------------------------------------------
void sub_145EDA()
{
  ;
}


//----- (00145EF9) --------------------------------------------------------
void sub_145EF9()
{
  ;
}


//----- (00145F18) --------------------------------------------------------
void sub_145F18()
{
  ;
}


//----- (00145F37) --------------------------------------------------------
void sub_145F37()
{
  ;
}


//----- (00145F56) --------------------------------------------------------
void sub_145F56()
{
  ;
}


//----- (00145F75) --------------------------------------------------------
void sub_145F75()
{
  ;
}


//----- (00145F94) --------------------------------------------------------
void sub_145F94()
{
  ;
}


//----- (00145FB3) --------------------------------------------------------
void sub_145FB3()
{
  ;
}


//----- (00145FD2) --------------------------------------------------------
bool sub_145FD2()
{
  char v1[28]; // [esp+0h] [ebp-40h] BYREF
  int v2; // [esp+1Ch] [ebp-24h]
  int16_t v3; // [esp+22h] [ebp-1Eh]
  int v4; // [esp+38h] [ebp-8h]

  sub_127678((char *)&dword_1BB8E0, 0x1Cu, 0);
  sub_127678((char *)word_1BBA1C, 0xCu, 0);
  v4 = dword_1B06FC;
  sub_127678((char *)dword_1B06FC, 0x102u, 0);
  sub_127678(v1, 0x32u, 0);
  v2 = 20224;
  v3 = dword_1B06F8;
  *(_DWORD *)v1 = 0;
  LOWORD(dword_1BB8E0) = 768;
  LOWORD(dword_1BB8E4) = 16;
  LOWORD(dword_1BB8E8) = 0;
  word_1BBA1C[0] = __SS__;
  dword_1BB8F4 = (int)v1;
  int386x(49, &dword_1BB8E0);
  return (_BYTE)v2 == 79;
}
// 144A4A: using guessed type int __fastcall int386x(_DWORD, _DWORD);
// 1B06F8: using guessed type int dword_1B06F8;
// 1B06FC: using guessed type int dword_1B06FC;
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8F4: using guessed type int dword_1BB8F4;
// 1BBA1C: using guessed type int16_t word_1BBA1C[6];


//----- (001460C1) --------------------------------------------------------
int sub_1460C1()
{
  char v1[28]; // [esp+0h] [ebp-40h] BYREF
  int v2; // [esp+1Ch] [ebp-24h]
  int16_t v3; // [esp+22h] [ebp-1Eh]
  int v4; // [esp+38h] [ebp-8h]

  sub_127678((char *)&dword_1BB8E0, 0x1Cu, 0);
  sub_127678((char *)word_1BBA1C, 0xCu, 0);
  v4 = dword_1B06FC;
  sub_127678((char *)dword_1B06FC, 0x102u, 0);
  sub_127678(v1, 0x32u, 0);
  v2 = 20224;
  v3 = dword_1B06F8;
  *(_DWORD *)v1 = 0;
  LOWORD(dword_1BB8E0) = 768;
  LOWORD(dword_1BB8E4) = 16;
  LOWORD(dword_1BB8E8) = 0;
  word_1BBA1C[0] = __SS__;
  dword_1BB8F4 = (int)v1;
  int386x(49, &dword_1BB8E0);
  LOWORD(dword_1BB8E0) = 20231;
  LOWORD(dword_1BB8E4) = 0;
  LOWORD(dword_1BB8E8) = 0;
  LOWORD(dword_1BB8EC) = 0;
  int386(16, &dword_1BB8E0, &dword_1BB8E0);
  if ( (_BYTE)v2 == 79 )
    return *(int *)(v4 + 16) >> 16 << 6;
  else
    return 512;
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 144A4A: using guessed type int __fastcall int386x(_DWORD, _DWORD);
// 1B06F8: using guessed type int dword_1B06F8;
// 1B06FC: using guessed type int dword_1B06FC;
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8EC: using guessed type int dword_1BB8EC;
// 1BB8F4: using guessed type int dword_1BB8F4;
// 1BBA1C: using guessed type int16_t word_1BBA1C[6];


//----- (001461F0) --------------------------------------------------------
int sub_1461F0()
{
  char v1[20]; // [esp+0h] [ebp-40h] BYREF
  int v2; // [esp+14h] [ebp-2Ch]
  int v3; // [esp+18h] [ebp-28h]
  int v4; // [esp+1Ch] [ebp-24h]
  int16_t v5; // [esp+22h] [ebp-1Eh]
  int v6; // [esp+38h] [ebp-8h]

  sub_127678((char *)&dword_1BB8E0, 0x1Cu, 0);
  sub_127678((char *)word_1BBA1C, 0xCu, 0);
  v6 = dword_1B06FC;
  sub_127678((char *)dword_1B06FC, 0x100u, 0);
  sub_127678(v1, 0x32u, 0);
  v4 = 20225;
  v3 = 257;
  v5 = dword_1B06F8;
  v2 = 0;
  LOWORD(dword_1BB8E0) = 768;
  LOWORD(dword_1BB8E4) = 16;
  LOWORD(dword_1BB8E8) = 0;
  word_1BBA1C[0] = __SS__;
  dword_1BB8F4 = (int)v1;
  int386x(49, &dword_1BB8E0);
  if ( (*(_BYTE *)(v6 + 2) & 5) == 5 )
    word_1BBA5E = 0;
  if ( (*(_BYTE *)(v6 + 2) & 3) == 3 )
    word_1BBA58 = 0;
  if ( (*(_BYTE *)(v6 + 3) & 5) == 5 )
    word_1BBA5E = 1;
  if ( (*(_BYTE *)(v6 + 3) & 3) == 3 )
    word_1BBA58 = 1;
  return *(uint16_t *)(v6 + 4);
}
// 144A4A: using guessed type int __fastcall int386x(_DWORD, _DWORD);
// 1B06F8: using guessed type int dword_1B06F8;
// 1B06FC: using guessed type int dword_1B06FC;
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;
// 1BB8E8: using guessed type int dword_1BB8E8;
// 1BB8F4: using guessed type int dword_1BB8F4;
// 1BBA1C: using guessed type int16_t word_1BBA1C[6];
// 1BBA58: using guessed type int16_t word_1BBA58;
// 1BBA5E: using guessed type int16_t word_1BBA5E;


//----- (00146348) --------------------------------------------------------
int sub_146348()
{
  sub_127678((char *)&dword_1BB8E0, 0x1Cu, 0);
  sub_127678(byte_1BB8C4, 0x1Cu, 0);
  LOWORD(dword_1BB8E0) = 20226;
  dword_1BB8E4 = 257;
  return int386(16, &dword_1BB8E0, byte_1BB8C4);
}
// 13F253: using guessed type int __fastcall int386(_DWORD, _DWORD, _DWORD);
// 1BB8E0: using guessed type int dword_1BB8E0;
// 1BB8E4: using guessed type int dword_1BB8E4;


//----- (0014736A) --------------------------------------------------------
int sub_14736A()
{
  return dword_184A00;
}
// 184A00: using guessed type int dword_184A00;


//----- (0014759C) --------------------------------------------------------
char __fastcall sub_14759C( int result, char *a2, unsigned int a3, int a4)
{
  unsigned int v6; // edx

  v6 = *(int *)((char *)&dword_184532 + 2) - a3;
  do
  {
    memset(a2, result, a3);
    a2 += v6 + a3;
    --a4;
  }
  while ( a4 );
  return result;
}
// 184532: using guessed type int dword_184532;


//----- (001475BB) --------------------------------------------------------
int __fastcall sub_1475BB(int a1, char *a2, int a3, int a4)
{
  int16_t v4; // si
  int result; // eax
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int v10; // ebx

  BYTE1(a1) = a1;
  v4 = a1;
  result = a1 << 16;
  LOWORD(result) = v4;
  v8 = 4 * a3;
  v9 = *(int *)((char *)&dword_184532 + 2) - v8;
  v10 = v8 >> 2;
  do
  {
    memset32(a2, result, v10);
    a2 += 4 * v10 + v9;
    --a4;
  }
  while ( a4 );
  return result;
}
// 184532: using guessed type int dword_184532;


//----- (001475EB) --------------------------------------------------------
char __fastcall sub_1475EB( int a1, char *a2, unsigned int a3, int a4)
{
  unsigned int v6; // edx
  char v7; // t0

  v6 = *(int *)((char *)&dword_184532 + 2) - a3;
  do
  {
    memset(a2, a1, a3);
    a2 += v6 + a3;
    v7 = HIBYTE(a1);
    HIBYTE(a1) = a1;
    LOBYTE(a1) = v7;
    --a4;
  }
  while ( a4 );
  return a1;
}
// 184532: using guessed type int dword_184532;


//----- (0014760C) --------------------------------------------------------
int __fastcall sub_14760C(int a1, char *a2, int a3, int a4)
{
  int16_t v4; // si
  int32_t v5; // eax
  int32_t v6; // eax
  int16_t v7; // si
  int result; // eax
  unsigned int v11; // ebx
  unsigned int v12; // edx
  unsigned int v13; // ebx

  dword_188FC4 = a1;
  BYTE1(a1) = a1;
  v4 = a1;
  v5 = a1 << 16;
  LOWORD(v5) = v4;
  v6 = _InterlockedExchange(&dword_188FC4, v5);
  LOBYTE(v6) = BYTE1(v6);
  v7 = v6;
  v6 <<= 16;
  LOWORD(v6) = v7;
  result = _InterlockedExchange(&dword_188FC4, v6);
  v11 = 4 * a3;
  v12 = *(int *)((char *)&dword_184532 + 2) - v11;
  v13 = v11 >> 2;
  do
  {
    memset32(a2, result, v13);
    a2 += 4 * v13 + v12;
    result = _InterlockedExchange(&dword_188FC4, result);
    --a4;
  }
  while ( a4 );
  return result;
}
// 184532: using guessed type int dword_184532;
// 188FC4: using guessed type int dword_188FC4;


//----- (0014765E) --------------------------------------------------------
int __fastcall sub_14765E(int result, char *a2, unsigned int a3, int a4)
{
  unsigned int v6; // edx
  char *v7; // edi
  int v8; // esi
  char *v9; // edi
  int v10; // esi

  v6 = *(int *)((char *)&dword_184532 + 2) - a3;
  do
  {
    memset(a2, result, a3);
    v7 = &a2[a3 + v6];
    result = __ROR4__(result, 8);
    v8 = a4 - 1;
    if ( !v8 )
      break;
    memset(v7, result, a3);
    v9 = &v7[a3 + v6];
    result = __ROR4__(result, 8);
    v10 = v8 - 1;
    if ( !v10 )
      break;
    memset(v9, result, a3);
    a2 = &v9[a3 + v6];
    result = __ROR4__(result, 16);
    a4 = v10 - 1;
  }
  while ( a4 );
  return result;
}
// 184532: using guessed type int dword_184532;


//----- (00147698) --------------------------------------------------------
int __fastcall sub_147698(int result, char *a2, int a3, int a4)
{
  int v5; // esi
  unsigned int v6; // ebx
  unsigned int v7; // edx
  unsigned int v8; // ebx
  char *v9; // edi
  int v10; // esi
  int v11; // eax
  char *v12; // edi
  int v13; // esi
  int v14; // eax

  dword_188FC4 = result;
  v5 = a4;
  v6 = 4 * a3;
  v7 = *(int *)((char *)&dword_184532 + 2) - v6;
  v8 = v6 >> 2;
  do
  {
    result = (uint8_t)result;
    BYTE1(result) = result;
    LOWORD(a4) = result;
    memset32(a2, (a4 << 16) | result, v8);
    v9 = &a2[4 * v8 + v7];
    dword_188FC4 = __ROR4__(dword_188FC4, 8);
    result = dword_188FC4;
    v10 = v5 - 1;
    if ( !v10 )
      break;
    v11 = (uint8_t)dword_188FC4;
    BYTE1(v11) = dword_188FC4;
    memset32(v9, (v11 << 16) | v11, v8);
    v12 = &v9[4 * v8 + v7];
    dword_188FC4 = __ROR4__(dword_188FC4, 8);
    result = dword_188FC4;
    v13 = v10 - 1;
    if ( !v13 )
      break;
    v14 = (uint8_t)dword_188FC4;
    BYTE1(v14) = dword_188FC4;
    memset32(v12, (v14 << 16) | v14, v8);
    HIWORD(a4) = 0;
    a2 = &v12[4 * v8 + v7];
    dword_188FC4 = __ROR4__(dword_188FC4, 16);
    result = dword_188FC4;
    v5 = v13 - 1;
  }
  while ( v5 );
  return result;
}
// 184532: using guessed type int dword_184532;
// 188FC4: using guessed type int dword_188FC4;


//----- (00147723) --------------------------------------------------------
char __fastcall sub_147723(int a1, _BYTE *a2, int a3, int a4)
{
  _BYTE *v4; // edi
  _BYTE *v5; // esi
  int v6; // edx
  int v8; // eax
  int v9; // ecx

  v4 = a2;
  v5 = a2;
  dword_188FBC = a4;
  v6 = *(int *)((char *)&dword_184532 + 2) - a3;
  dword_188FC0 = a3;
  v8 = 0;
  do
  {
    v9 = dword_188FC0;
    do
    {
      LOBYTE(v8) = *v5++;
      LOBYTE(v8) = *(_BYTE *)(a1 + v8);
      *v4++ = v8;
      --v9;
    }
    while ( v9 );
    v4 += v6;
    v5 += v6;
    --dword_188FBC;
  }
  while ( dword_188FBC );
  return v8;
}
// 184532: using guessed type int dword_184532;
// 188FBC: using guessed type int dword_188FBC;
// 188FC0: using guessed type int dword_188FC0;


//----- (00147760) --------------------------------------------------------
char __fastcall sub_147760(int a1, _BYTE *a2, int a3, int a4)
{
  _BYTE *v4; // edi
  _BYTE *v5; // esi
  unsigned int v6; // ebx
  unsigned int v7; // edx
  int v9; // eax
  int v10; // ecx
  _BYTE *v11; // esi
  _BYTE *v12; // edi

  v4 = a2;
  v5 = a2;
  dword_188FBC = a4;
  v6 = 4 * a3;
  v7 = *(int *)((char *)&dword_184532 + 2) - v6;
  dword_188FC0 = v6 >> 2;
  v9 = 0;
  do
  {
    v10 = dword_188FC0;
    do
    {
      LOBYTE(v9) = *v5;
      v11 = v5 + 1;
      *v4 = *(_BYTE *)(a1 + v9);
      v12 = v4 + 1;
      LOBYTE(v9) = *v11++;
      *v12++ = *(_BYTE *)(a1 + v9);
      LOBYTE(v9) = *v11++;
      *v12++ = *(_BYTE *)(a1 + v9);
      LOBYTE(v9) = *v11;
      v5 = v11 + 1;
      LOBYTE(v9) = *(_BYTE *)(a1 + v9);
      *v12 = v9;
      v4 = v12 + 1;
      --v10;
    }
    while ( v10 );
    v4 += v7;
    v5 += v7;
    --dword_188FBC;
  }
  while ( dword_188FBC );
  return v9;
}
// 184532: using guessed type int dword_184532;
// 188FBC: using guessed type int dword_188FBC;
// 188FC0: using guessed type int dword_188FC0;


//----- (001477B4) --------------------------------------------------------
char *__fastcall sub_1477B4(char *result, int a2, int a3)
{
  unsigned int v3; // ebx

  v3 = -a3;
  qmemcpy(result, &result[v3], a2 - v3);
  memset(&result[a2 - v3], 0, v3);
  return result;
}
// 1477B4: could not find valid save-restore pair for ebx
// 1477B4: could not find valid save-restore pair for edi
// 1477B4: could not find valid save-restore pair for esi


//----- (001477CF) --------------------------------------------------------
int __fastcall sub_1477CF(int result, int a2, int a3)
{
  _BYTE *v3; // edi
  _BYTE *v4; // esi
  int i; // ecx
  int j; // ecx

  v3 = (_BYTE *)(a2 + result - 1);
  v4 = &v3[-a3];
  for ( i = a2 - a3; i; --i )
    *v3-- = *v4--;
  for ( j = a3; j; --j )
    *v3-- = 0;
  return result;
}
// 1477CF: could not find valid save-restore pair for edi
// 1477CF: could not find valid save-restore pair for esi


//----- (001477ED) --------------------------------------------------------
int __userpurge sub_1477ED(_BYTE *a1, int a2, int a3, int a4)
{
  int v4; // ebx
  _BYTE *v5; // edi
  _BYTE *v6; // esi
  int result; // edx
  int v8; // ecx
  int v9; // ecx

  v4 = -a3;
  v5 = a1;
  v6 = a1;
  result = a2 - 1;
  v8 = a4 - v4;
  do
  {
    *v5 = *v6;
    v6 += result + 1;
    v5 += result + 1;
    --v8;
  }
  while ( v8 );
  v9 = v4;
  do
  {
    *v5 = 0;
    v5 += result + 1;
    --v9;
  }
  while ( v9 );
  return result;
}
// 1477ED: could not find valid save-restore pair for ebx
// 1477ED: could not find valid save-restore pair for edi
// 1477ED: could not find valid save-restore pair for esi


//----- (00147826) --------------------------------------------------------
int64_t __fastcall sub_147826(int64_t a1, int a2, int a3)
{
  uint16_t v3; // kr00_2
  _BYTE *v4; // edi
  _BYTE *v5; // esi
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v10; // [esp-2Ch] [ebp-2Ch]
  int64_t v11; // [esp-20h] [ebp-20h]

  v11 = a1;
  v10 = HIDWORD(a1);
  HIDWORD(a1) = WORD2(a1);
  v3 = a3 * WORD2(a1);
  WORD2(a1) = ((uint16_t)a3 * (unsigned int)WORD2(a1)) >> 16;
  v4 = (_BYTE *)((HIDWORD(a1) << 16) + v3 - v10 + a1);
  v5 = &v4[-(uint16_t)(v10 * a2) + -65536 * (((uint16_t)v10 * (unsigned int)(uint16_t)a2) >> 16)];
  v6 = a3 - a2;
  v7 = v10 - 1;
  do
  {
    *v4 = *v5;
    v4 -= v10;
    v5 -= v10;
    --v6;
  }
  while ( v6 );
  v8 = a2;
  do
  {
    *v4 = 0;
    v4 = &v4[-v7 + 1];
    v5 -= v7;
    --v8;
  }
  while ( v8 );
  return v11;
}
// 147826: could not find valid save-restore pair for edi
// 147826: could not find valid save-restore pair for esi


//----- (0014787E) --------------------------------------------------------
_BYTE *__fastcall sub_14787E(_BYTE *a1, unsigned int a2, int a3)
{
  _BYTE *v3; // esi
  _BYTE *v4; // edi
  unsigned int v5; // ecx
  char v6; // ah
  _BYTE *v8; // [esp-30h] [ebp-30h]
  _BYTE *v9; // [esp-2Ch] [ebp-2Ch]

  v3 = a1;
  v4 = &a1[a2 - 1];
  do
  {
    v5 = a2 >> 1;
    v9 = v4;
    v8 = v3;
    do
    {
      v6 = *v4;
      *v4 = *v3++;
      *(v3 - 1) = v6;
      --v4;
      --v5;
    }
    while ( v5 );
    v4 = &v9[a2];
    v3 = &v8[a2];
    --a3;
  }
  while ( a3 );
  return a1;
}
// 14787E: could not find valid save-restore pair for edi
// 14787E: could not find valid save-restore pair for esi


//----- (001478A6) --------------------------------------------------------
_BYTE *__fastcall sub_1478A6(_BYTE *result, int a2, int a3, int a4)
{
  _BYTE *v4; // esi
  _BYTE *v5; // edi
  int v6; // ecx

  v4 = result;
  v5 = (_BYTE *)(a2 + a4 - 1);
  do
  {
    v6 = a2;
    do
    {
      *v5-- = *v4++;
      --v6;
    }
    while ( v6 );
    v5 += a2 + a2;
    --a3;
  }
  while ( a3 );
  return result;
}
// 1478A6: could not find valid save-restore pair for edi
// 1478A6: could not find valid save-restore pair for esi


//----- (001478C3) --------------------------------------------------------
_BYTE *__fastcall sub_1478C3(_BYTE *a1, int a2, unsigned int a3)
{
  _BYTE *v3; // esi
  _BYTE *v4; // edi
  unsigned int v5; // ebx
  int v6; // ecx
  char v7; // ah
  _BYTE *v9; // [esp-30h] [ebp-30h]
  _BYTE *v10; // [esp-2Ch] [ebp-2Ch]

  v3 = a1;
  v4 = &a1[a2 * a3 - a2];
  v5 = a3 >> 1;
  do
  {
    v10 = v4;
    v9 = v3;
    v6 = a2;
    do
    {
      v7 = *v4;
      *v4++ = *v3++;
      *(v3 - 1) = v7;
      --v6;
    }
    while ( v6 );
    v3 = &v9[a2];
    v4 = &v10[-a2];
    --v5;
  }
  while ( v5 );
  return a1;
}
// 1478C3: could not find valid save-restore pair for ebx
// 1478C3: could not find valid save-restore pair for edi
// 1478C3: could not find valid save-restore pair for esi


//----- (001478EF) --------------------------------------------------------
int __fastcall sub_1478EF(int result, unsigned int a2, int a3, char *a4)
{
  char *v4; // esi
  char *v6; // edi
  char *v7; // esi
  unsigned int v8; // ecx

  v4 = (char *)(a2 * a3 - a2 + result);
  do
  {
    qmemcpy(a4, v4, 4 * (a2 >> 2));
    v7 = &v4[4 * (a2 >> 2)];
    v6 = &a4[4 * (a2 >> 2)];
    v8 = a2 & 3;
    qmemcpy(v6, v7, v8);
    a4 = &v6[v8];
    v4 = &v7[v8 - a2 - a2];
    --a3;
  }
  while ( a3 );
  return result;
}
// 1478EF: could not find valid save-restore pair for ebx
// 1478EF: could not find valid save-restore pair for edi
// 1478EF: could not find valid save-restore pair for esi


//----- (0014791B) --------------------------------------------------------
char *__fastcall sub_14791B(char *result, unsigned int a2, int a3, char *a4)
{
  char *v5; // esi

  v5 = result;
  do
  {
    qmemcpy(a4, v5, a2);
    a4 += a2;
    v5 += *(int *)((char *)&dword_184532 + 2);
    --a3;
  }
  while ( a3 );
  return result;
}
// 14791B: could not find valid save-restore pair for edi
// 14791B: could not find valid save-restore pair for esi
// 184532: using guessed type int dword_184532;


//----- (00147935) --------------------------------------------------------
unsigned int __fastcall sub_147935(int a1, int a2, int a3, int a4, int a5, unsigned int a6, int a7, int a8)
{
  int v9; // edx
  int v10; // eax
  _BYTE *v11; // esi
  _BYTE *v12; // edi
  unsigned int v13; // edx
  int v14; // ecx
  unsigned int v15; // ebx
  unsigned int result; // eax
  int v17; // ecx
  _BYTE *v18; // [esp-4h] [ebp-Ch]

  dword_188FE0 = a2;
  dword_188FE4 = a3;
  LOWORD(a2) = (a6 * (unsigned int)(uint16_t)a5) >> 16;
  v9 = a2 << 16;
  v10 = v9 + (uint16_t)(a6 * a5) - 1;
  v11 = (_BYTE *)(v10 + a1);
  word_188FC8 = 0x6400u / (uint16_t)dword_188FE0;
  LOWORD(v10) = 0x6400u / (uint16_t)a3;
  dword_188FD8 = v10;
  LOWORD(v9) = ((uint16_t)a8 * (unsigned int)(uint16_t)a7) >> 16;
  v12 = (_BYTE *)((v9 << 16) + (uint16_t)(a8 * a7) - 1 + a4);
  word_188FCE = a7;
  dword_188FD4 = 0;
  v13 = 0x6400u / (uint16_t)dword_188FE0;
  do
  {
    v18 = v11;
    v14 = a7;
    v15 = 0;
    do
    {
      *v12-- = *v11;
      v15 += v13;
      result = v15 >> 8;
      v11 -= v15 >> 8;
      v15 = (uint8_t)v15;
      --v14;
    }
    while ( v14 );
    v11 = v18;
    v17 = dword_188FD8 + dword_188FD4;
    if ( (uint16_t)(dword_188FD8 + dword_188FD4) >> 8 )
    {
      v11 = &v18[-a5];
      BYTE1(v17) = 0;
    }
    dword_188FD4 = v17;
    --a8;
  }
  while ( a8 );
  return result;
}
// 188FC8: using guessed type int16_t word_188FC8;
// 188FCE: using guessed type int16_t word_188FCE;
// 188FD4: using guessed type int dword_188FD4;
// 188FD8: using guessed type int dword_188FD8;
// 188FE0: using guessed type int dword_188FE0;
// 188FE4: using guessed type int dword_188FE4;


//----- (00147A12) --------------------------------------------------------
int16_t __fastcall sub_147A12(int a1, int a2, int a3, _BYTE *a4, int a5, int a6, int a7, int a8)
{
  _BYTE *v8; // esi
  unsigned int v10; // edx
  int v11; // ecx
  unsigned int v12; // ebx
  int v13; // ecx
  int v14; // eax
  _BYTE *v16; // [esp-4h] [ebp-Ch]

  v8 = (_BYTE *)a1;
  dword_188FE0 = a2;
  dword_188FE4 = a3;
  word_188FC8 = 0x6400u / (uint16_t)a2;
  LOWORD(a1) = 0x6400u / (uint16_t)a3;
  dword_188FD8 = a1;
  word_188FCE = a7;
  dword_188FD4 = 0;
  v10 = 0x6400u / (uint16_t)a2;
  do
  {
    v16 = v8;
    v11 = a7;
    v12 = 0;
    do
    {
      *a4++ = *v8;
      v12 += v10;
      v8 += v12 >> 8;
      v12 = (uint8_t)v12;
      --v11;
    }
    while ( v11 );
    v13 = dword_188FD8 + dword_188FD4;
    HIWORD(v14) = HIWORD(a5);
    LOWORD(v14) = (uint8_t)((uint16_t)(dword_188FD8 + dword_188FD4) >> 8) * (uint8_t)a5;
    v8 = &v16[v14];
    BYTE1(v13) = 0;
    dword_188FD4 = v13;
    --a8;
  }
  while ( a8 );
  return v14;
}
// 188FC8: using guessed type int16_t word_188FC8;
// 188FCE: using guessed type int16_t word_188FCE;
// 188FD4: using guessed type int dword_188FD4;
// 188FD8: using guessed type int dword_188FD8;
// 188FE0: using guessed type int dword_188FE0;
// 188FE4: using guessed type int dword_188FE4;


//----- (00147ABC) --------------------------------------------------------
int __usercall sub_147ABC(int *a1, int a2, int *a3, unsigned int a4, unsigned int a5)
{
  int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // ecx
  int v10; // ebx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int result; // eax
  _BOOL1 v19; // tt
  _BOOL1 v20; // zf

  dword_188FDC = a2;
  v7 = ((uint16_t)sub_1247A0(0x3E8u) - 1) & 0xFFFE;
  dword_188FF0 = v7;
  LOWORD(a2) = ((uint16_t)a4 * (unsigned int)a5) >> 16;
  LOWORD(v7) = a4 * a5;
  v8 = (a2 << 16) + v7;
  v9 = v8 >> 2;
  if ( (v8 & 3) != 0 )
    ++v9;
  dword_188FE8 = a4 >> 2;
  dword_188FEC = a4 >> 2;
  v10 = dword_188FF0 & 0xFE;
  do
  {
    v11 = *a1++;
    v12 = *(int *)((char *)&dword_189024 + v10);
    v10 = (uint8_t)(v10 + 4);
    if ( (uint8_t)v12 < (uint8_t)dword_188FDC )
      LOBYTE(v11) = 0;
    v13 = __ROR4__(v11, 8);
    v14 = __ROR4__(v12, 8);
    if ( (uint8_t)v14 < (uint8_t)dword_188FDC )
      LOBYTE(v13) = 0;
    v15 = __ROR4__(v13, 8);
    v16 = __ROR4__(v14, 8);
    if ( (uint8_t)v16 < (uint8_t)dword_188FDC )
      LOBYTE(v15) = 0;
    v17 = __ROR4__(v15, 8);
    if ( (uint8_t)__ROR4__(v16, 8) < (uint8_t)dword_188FDC )
      LOBYTE(v17) = 0;
    v19 = __CFSHR__(v17, 8);
    result = __ROR4__(v17, 8);
    *a3++ = result;
    v20 = dword_188FEC-- == 1;
    if ( v19 || v20 )
    {
      dword_188FEC = dword_188FE8;
      result = v9 * v9;
      v10 = ((_BYTE)v9 * (_BYTE)v9 + (_BYTE)v10) & 0xFE;
    }
    --v9;
  }
  while ( v9 );
  return result;
}
// 188FDC: using guessed type int dword_188FDC;
// 188FE8: using guessed type int dword_188FE8;
// 188FEC: using guessed type int dword_188FEC;
// 188FF0: using guessed type int dword_188FF0;
// 189024: using guessed type int dword_189024;


//----- (00147B89) --------------------------------------------------------
char __usercall sub_147B89(char *a1, int a2, _BYTE *a3, int a4)
{
  char *v4; // esi
  _BYTE *v5; // edi
  int v6; // ecx
  int v7; // edx
  char v8; // ah
  int16_t v9; // bx
  char v10; // al
  _BYTE *v11; // edi
  char *v12; // esi
  int v13; // ecx
  char v14; // ah
  int16_t v15; // bx
  char result; // al
  _BYTE *v17; // esi

  v4 = a1;
  v5 = a3;
  dword_188FF4 = a2;
  dword_188FF8 = a4 * a4;
  dword_188FFC = 0;
  v6 = a4 * a4;
  v7 = a4;
  v8 = dword_188FF4;
  v9 = 0;
  do
  {
    v10 = *v4++;
    if ( !v10 || v10 == v8 )
    {
      if ( (_BYTE)v9 )
        *v5 = v8;
      v9 = 256;
    }
    else
    {
      if ( HIBYTE(v9) )
        *(v5 - 1) = v8;
      v9 = 1;
    }
    ++v5;
    if ( !--v7 )
    {
      v7 = a4;
      v9 = 0;
    }
    --v6;
  }
  while ( v6 );
  v11 = a3;
  v12 = a1;
  dword_188FF8 = a4 * a4;
  dword_189000 = (int)&a1[a4 * a4];
  v13 = a4 * a4;
  v14 = dword_188FF4;
  v15 = 0;
  do
  {
    result = *v12;
    v17 = v12 + 1;
    if ( !result || result == v14 )
    {
      if ( (_BYTE)v15 )
        *v11 = v14;
      v15 = 256;
    }
    else
    {
      if ( HIBYTE(v15) )
        v11[-a4] = v14;
      v15 = 1;
    }
    v12 = &v17[a4 - 1];
    v11 += a4;
    if ( (int)&v12[-dword_189000] >= 0 )
    {
      v12 = &v12[-dword_188FF8 + 1];
      v11 = &v11[-dword_188FF8 + 1];
      v15 = 0;
    }
    --v13;
  }
  while ( v13 );
  return result;
}
// 188FF4: using guessed type int dword_188FF4;
// 188FF8: using guessed type int dword_188FF8;
// 188FFC: using guessed type int dword_188FFC;
// 189000: using guessed type int dword_189000;


//----- (00147C6A) --------------------------------------------------------
uint8_t __usercall sub_147C6A(uint8_t *a1, int a2, _BYTE *a3, int a4)
{
  uint8_t *v4; // esi
  _BYTE *v5; // edi
  int v6; // ecx
  int v7; // edx
  char v8; // ah
  int16_t v9; // bx
  uint8_t v10; // al
  _BYTE *v11; // edi
  uint8_t *v12; // esi
  int v13; // ecx
  char v14; // ah
  int16_t v15; // bx
  uint8_t result; // al
  _BYTE *v17; // esi

  v4 = a1;
  v5 = a3;
  dword_188FF4 = a2;
  dword_188FF8 = a4 * a4;
  dword_188FFC = 0;
  v6 = a4 * a4;
  v7 = a4;
  v8 = dword_188FF4;
  v9 = 0;
  do
  {
    v10 = *v4++;
    if ( !v10 || v10 == v8 || v10 >= 0xF0u )
    {
      if ( (_BYTE)v9 )
        *v5 = v8;
      v9 = 256;
    }
    else
    {
      if ( HIBYTE(v9) )
        *(v5 - 1) = v8;
      v9 = 1;
    }
    ++v5;
    if ( !--v7 )
    {
      v7 = a4;
      v9 = 0;
    }
    --v6;
  }
  while ( v6 );
  v11 = a3;
  v12 = a1;
  dword_188FF8 = a4 * a4;
  dword_189000 = (int)&a1[a4 * a4];
  v13 = a4 * a4;
  v14 = dword_188FF4;
  v15 = 0;
  do
  {
    result = *v12;
    v17 = v12 + 1;
    if ( !result || result == v14 || result >= 0xF0u )
    {
      if ( (_BYTE)v15 )
        *v11 = v14;
      v15 = 256;
    }
    else
    {
      if ( HIBYTE(v15) )
        v11[-a4] = v14;
      v15 = 1;
    }
    v12 = &v17[a4 - 1];
    v11 += a4;
    if ( (int)&v12[-dword_189000] >= 0 )
    {
      v12 = &v12[-dword_188FF8 + 1];
      v11 = &v11[-dword_188FF8 + 1];
      v15 = 0;
    }
    --v13;
  }
  while ( v13 );
  return result;
}
// 188FF4: using guessed type int dword_188FF4;
// 188FF8: using guessed type int dword_188FF8;
// 188FFC: using guessed type int dword_188FFC;
// 189000: using guessed type int dword_189000;


//----- (00147D53) --------------------------------------------------------
char __fastcall sub_147D53(char *a1, int a2, int a3, _BYTE *a4, int a5, int a6, int a7)
{
  int v9; // ebx
  char v10; // ah
  int v11; // ecx
  unsigned int v12; // edx
  char result; // al

  dword_188FF4 = a2;
  dword_189004 = a3;
  dword_188FF8 = a6 * a5;
  v9 = dword_189004;
  v10 = a2;
  v11 = a6 * a5;
  v12 = a7 & 0xFFFF0707;
  do
  {
    result = *a1++;
    if ( result == v10 )
    {
      result = BYTE1(v12);
      BYTE1(v12) = 0;
      *a4 = *(_BYTE *)(v9 + v12);
      BYTE1(v12) = result;
    }
    ++a4;
    LOBYTE(v12) = BYTE1(v12) + v12;
    ++BYTE1(v12);
    LOWORD(v12) = v12 & 0x707;
    --v11;
  }
  while ( v11 );
  return result;
}
// 188FF4: using guessed type int dword_188FF4;
// 188FF8: using guessed type int dword_188FF8;
// 189004: using guessed type int dword_189004;


//----- (00147DB0) --------------------------------------------------------
int __usercall sub_147DB0(_BYTE *a1, int a2, int a3, int a4)
{
  int result; // eax
  int v6; // edx
  _BYTE *v7; // edi
  int v8; // ecx

  result = a3 * a4;
  dword_188FF8 = a3 * a4;
  v6 = a4;
  v7 = (_BYTE *)(a3 + a2 - 1);
  do
  {
    v8 = a3;
    do
    {
      *v7 = *a1++;
      v7 += a3;
      --v8;
    }
    while ( v8 );
    v7 = &v7[-dword_188FF8 - 1];
    --v6;
  }
  while ( v6 );
  return result;
}
// 188FF8: using guessed type int dword_188FF8;


//----- (00147DE7) --------------------------------------------------------
int __usercall sub_147DE7(_BYTE *a1, int a2, int a3, int a4)
{
  int result; // eax
  _BYTE *v6; // edi
  int v7; // edx
  int v8; // ecx

  result = a3 * a4;
  dword_188FF8 = a3 * a4;
  v6 = (_BYTE *)(a3 * a4 + a2 - a3);
  v7 = a4;
  do
  {
    v8 = a3;
    do
    {
      *v6 = *a1++;
      v6 -= a3;
      --v8;
    }
    while ( v8 );
    v6 += dword_188FF8 + 1;
    --v7;
  }
  while ( v7 );
  return result;
}
// 188FF8: using guessed type int dword_188FF8;


//----- (00147E23) --------------------------------------------------------
char __usercall sub_147E23(char *a1, int a2, _BYTE *a3, int a4, int a5)
{
  int v7; // ecx
  int v9; // edx
  char result; // al

  dword_189004 = a2;
  dword_188FF8 = a4 * a5;
  v7 = a4 * a5;
  v9 = 0;
  do
  {
    result = *a1++;
    if ( result )
    {
      LOBYTE(v9) = result;
      result = *(_BYTE *)(a2 + v9);
    }
    *a3++ = result;
    --v7;
  }
  while ( v7 );
  return result;
}
// 188FF8: using guessed type int dword_188FF8;
// 189004: using guessed type int dword_189004;


//----- (00147E61) --------------------------------------------------------
char __fastcall sub_147E61(char *a1, int a2, int a3, int a4, int a5)
{
  char *v5; // esi
  char *v6; // edi
  int v8; // edx
  int v9; // ecx
  char v10; // al
  char result; // al

  v5 = a1;
  v6 = a1;
  dword_188FD8 = a3;
  dword_189004 = a2;
  dword_189008 = a4;
  v8 = 0;
  do
  {
    v9 = dword_189008;
    do
    {
      v10 = *v5++;
      LOBYTE(v8) = v10;
      result = *(_BYTE *)(a2 + v8);
      *v6++ = result;
      --v9;
    }
    while ( v9 );
    --a5;
  }
  while ( a5 );
  return result;
}
// 188FD8: using guessed type int dword_188FD8;
// 189004: using guessed type int dword_189004;
// 189008: using guessed type int dword_189008;


//----- (00147E9F) --------------------------------------------------------
int64_t __fastcall sub_147E9F(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v8; // ecx
  _BYTE *v9; // esi
  _BYTE *v10; // edi
  int v11; // ebx
  int64_t result; // rax

  dword_188FDC = a3;
  dword_18900C = a2;
  dword_188FF0 = (uint8_t)(sub_1247A0(0x3E8u) - 1);
  v8 = a6 * a5 - dword_18900C - dword_18900C - 2;
  v9 = (_BYTE *)(dword_18900C + a1 + 1);
  v10 = (_BYTE *)(dword_18900C + a4 + 1);
  v11 = dword_188FF0;
  WORD1(result) = HIWORD(dword_188FDC);
  BYTE1(result) = dword_188FDC;
  HIDWORD(result) = 0;
  do
  {
    LOBYTE(result) = *v9++;
    BYTE4(result) = *((_BYTE *)&dword_189024 + v11);
    if ( BYTE4(result) < BYTE1(result) )
    {
      HIDWORD(result) &= dword_18900C;
      ++BYTE4(result);
      if ( dword_189010 )
        HIDWORD(result) = -HIDWORD(result);
      *v10 = v9[HIDWORD(result) - 1];
      v10[HIDWORD(result)] = result;
      dword_189010 = ~dword_189010;
    }
    HIDWORD(result) = 0;
    v11 = (uint8_t)(v11 + 1);
    ++v10;
    --v8;
  }
  while ( v8 );
  return result;
}
// 188FDC: using guessed type int dword_188FDC;
// 188FF0: using guessed type int dword_188FF0;
// 18900C: using guessed type int dword_18900C;
// 189010: using guessed type int dword_189010;
// 189024: using guessed type int dword_189024;


//----- (00147F3E) --------------------------------------------------------
char __fastcall sub_147F3E(char *a1, int a2, int a3, _BYTE *a4, int a5, int a6)
{
  int v9; // edx
  int v10; // ecx
  char result; // al

  dword_189014 = a2;
  dword_189018 = a3;
  v9 = dword_189018;
  do
  {
    v10 = a5;
    do
    {
      result = *a1++;
      if ( result )
      {
        result = 0;
        *a4 = 0;
      }
      ++a4;
      --v10;
    }
    while ( v10 );
    a1 += a2;
    a4 += v9;
    --a6;
  }
  while ( a6 );
  return result;
}
// 189014: using guessed type int dword_189014;
// 189018: using guessed type int dword_189018;


//----- (00147F7B) --------------------------------------------------------
char __fastcall sub_147F7B(char *a1, int a2, int a3, _BYTE *a4, int a5, int a6)
{
  int v9; // edx
  int v10; // ecx
  char result; // al

  dword_189014 = a2;
  dword_189018 = a3;
  v9 = dword_189018;
  do
  {
    v10 = a5;
    do
    {
      result = *a1++;
      if ( result )
      {
        if ( *a4 )
        {
          result = *(_BYTE *)(dword_1845E8 + (uint8_t)*a4 + ((uint8_t)(result - dword_1BC358) << 8));
          *a4 = result;
        }
      }
      ++a4;
      --v10;
    }
    while ( v10 );
    a1 += a2;
    a4 += v9;
    --a6;
  }
  while ( a6 );
  return result;
}
// 1845E8: using guessed type int dword_1845E8;
// 189014: using guessed type int dword_189014;
// 189018: using guessed type int dword_189018;
// 1BC358: using guessed type int dword_1BC358;


//----- (00147FDF) --------------------------------------------------------
char __fastcall sub_147FDF(char *a1, int a2, int a3, _BYTE *a4, int a5, int a6)
{
  int v9; // edx
  int v10; // ecx
  char result; // al

  dword_189014 = a2;
  dword_189018 = a3;
  v9 = dword_189018;
  do
  {
    v10 = a5;
    do
    {
      result = *a1++;
      if ( !result )
      {
        result = 0;
        *a4 = 0;
      }
      ++a4;
      --v10;
    }
    while ( v10 );
    a1 += a2;
    a4 += v9;
    --a6;
  }
  while ( a6 );
  return result;
}
// 189014: using guessed type int dword_189014;
// 189018: using guessed type int dword_189018;


//----- (0014801C) --------------------------------------------------------
int __usercall sub_14801C(int *a1, int a2, int a3, int a4, int a5)
{
  int *v5; // esi
  int *v6; // edi
  unsigned int v7; // ecx
  uint8_t v8; // bl
  uint8_t v9; // dl
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int result; // eax

  v5 = a1;
  v6 = a1;
  dword_18901C = a2;
  dword_189020 = a3;
  v7 = (unsigned int)(a5 * a4) >> 2;
  v8 = a2;
  v9 = dword_189020;
  do
  {
    v10 = *v5++;
    if ( (uint8_t)v10 >= v8 && (uint8_t)v10 <= v9 )
      LOBYTE(v10) = 0;
    v11 = __ROR4__(v10, 8);
    if ( (uint8_t)v11 >= v8 && (uint8_t)v11 <= v9 )
      LOBYTE(v11) = 0;
    v12 = __ROR4__(v11, 8);
    if ( (uint8_t)v12 >= v8 && (uint8_t)v12 <= v9 )
      LOBYTE(v12) = 0;
    v13 = __ROR4__(v12, 8);
    if ( (uint8_t)v13 >= v8 && (uint8_t)v13 <= v9 )
      LOBYTE(v13) = 0;
    result = __ROR4__(v13, 8);
    *v6++ = result;
    --v7;
  }
  while ( v7 );
  return result;
}
// 18901C: using guessed type int dword_18901C;
// 189020: using guessed type int dword_189020;


//----- (00148086) --------------------------------------------------------
void __fastcall sub_148086(unsigned int a1, unsigned int a2, _BYTE *a3, int a4, int a5, int a6, _BYTE *a7, int a8)
{
  _BYTE *v10; // esi

  for ( ; a4; --a4 )
  {
    LOBYTE(a1) = *a3;
    v10 = a3 + 1;
    if ( (_BYTE)a1 )
      *a7 = a1;
    ++a7;
    a2 += a5;
    a1 += a6;
    a3 = &v10[HIWORD(a2) - 1];
    a2 = (uint16_t)a2;
    while ( a1 >= (unsigned int)sub_10000 )
    {
      a3 += a8;
      a1 -= (unsigned int)sub_10000;
    }
  }
}
// 10000: using guessed type void __noreturn sub_10000();


//----- (001480C8) --------------------------------------------------------
void __fastcall sub_1480C8(unsigned int a1, unsigned int a2, _BYTE *a3, int a4, int a5, int a6, _BYTE *a7, int a8)
{
  _BYTE *v10; // esi

  for ( ; a4; --a4 )
  {
    LOBYTE(a1) = *a3;
    v10 = a3 + 1;
    if ( (_BYTE)a1 )
      *a7 = a1;
    ++a7;
    a2 += a5;
    a1 += a6;
    a3 = &v10[-HIWORD(a2) - 1];
    a2 = (uint16_t)a2;
    while ( a1 >= (unsigned int)sub_10000 )
    {
      a3 += a8;
      a1 -= (unsigned int)sub_10000;
    }
  }
}
// 10000: using guessed type void __noreturn sub_10000();


//----- (0014810A) --------------------------------------------------------
void __fastcall sub_14810A(unsigned int a1, unsigned int a2, _BYTE *a3, int a4, int a5, int a6, _BYTE *a7, int a8)
{
  _BYTE *v10; // esi

  for ( ; a4; --a4 )
  {
    LOBYTE(a1) = *a3;
    v10 = a3 + 1;
    if ( (_BYTE)a1 )
      *a7 = a1;
    ++a7;
    a2 += a5;
    a1 += a6;
    a3 = &v10[HIWORD(a2) - 1];
    a2 = (uint16_t)a2;
    while ( a1 >= (unsigned int)sub_10000 )
    {
      a3 -= a8;
      a1 -= (unsigned int)sub_10000;
    }
  }
}
// 10000: using guessed type void __noreturn sub_10000();


//----- (0014814C) --------------------------------------------------------
void __fastcall sub_14814C(unsigned int a1, unsigned int a2, _BYTE *a3, int a4, int a5, int a6, _BYTE *a7, int a8)
{
  _BYTE *v10; // esi

  for ( ; a4; --a4 )
  {
    LOBYTE(a1) = *a3;
    v10 = a3 + 1;
    if ( (_BYTE)a1 )
      *a7 = a1;
    ++a7;
    a2 += a5;
    a1 += a6;
    a3 = &v10[-HIWORD(a2) - 1];
    a2 = (uint16_t)a2;
    while ( a1 >= (unsigned int)sub_10000 )
    {
      a3 -= a8;
      a1 -= (unsigned int)sub_10000;
    }
  }
}
// 10000: using guessed type void __noreturn sub_10000();


